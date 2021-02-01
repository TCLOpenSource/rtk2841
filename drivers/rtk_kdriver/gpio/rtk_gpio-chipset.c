#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/io.h>
#include <linux/ioctl.h>
#include <linux/slab.h>
#include <linux/jiffies.h>
#include <linux/device.h>
#include <linux/string.h>
#include <linux/seq_file.h>
#include <linux/gpio.h>
#include <linux/gpio/driver.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-chipset.h>
#include "../../gpio/gpiolib.h"



/*================================================================
 *
 *================================================================*/

static int  gpio_ops_request(struct gpio_chip* chip, unsigned offset);
static void gpio_ops_free(struct gpio_chip* chip, unsigned offset);
static int  gpio_ops_get(struct gpio_chip* chip, unsigned offset);
static void gpio_ops_set(struct gpio_chip* chip, unsigned offset, int value);
static int  gpio_ops_get_direction(struct gpio_chip* chip, unsigned offset);
static int  gpio_ops_set_direction_input(struct gpio_chip* chip, unsigned offset);
static int  gpio_ops_set_direction_output(struct gpio_chip* chip, unsigned offset, int value);
static int  gpio_ops_set_debounce(struct gpio_chip *chip, unsigned offset, unsigned debounce);
static void gpio_ops_dbg_show(struct seq_file *s, struct gpio_chip *chip);

static struct gpio_chip g_rtk_gpio_chipsets[] =
{
    {
        .label            = "misc_gpio",
        .request          = gpio_ops_request,
        .free             = gpio_ops_free,
        .get_direction    = gpio_ops_get_direction,
        .direction_input  = gpio_ops_set_direction_input,
        .direction_output = gpio_ops_set_direction_output,
        .get              = gpio_ops_get,
        .set              = gpio_ops_set,
        .dbg_show         = gpio_ops_dbg_show,
        .base             = MIS_GPIO_OFST,
        .ngpio            = MIS_GPIO_CNT,
        .can_sleep        = false,
    },
    {
        .label            = "misc_gpi",
        .request          = gpio_ops_request,
        .free             = gpio_ops_free,
        .get_direction    = gpio_ops_get_direction,
        .direction_input  = gpio_ops_set_direction_input,
        .direction_output = gpio_ops_set_direction_output,
        .get              = gpio_ops_get,
        .set              = gpio_ops_set,
        .dbg_show         = gpio_ops_dbg_show,
        .base             = MIS_GPI_OFST,
        .ngpio            = GPI_MIS_CNT,
        .can_sleep        = false,
    },
    {
        .label            = "misc_gpo",
        .request          = gpio_ops_request,
        .free             = gpio_ops_free,
        .get_direction    = gpio_ops_get_direction,
        .direction_input  = gpio_ops_set_direction_input,
        .direction_output = gpio_ops_set_direction_output,
        .get              = gpio_ops_get,
        .set              = gpio_ops_set,
        .dbg_show         = gpio_ops_dbg_show,
        .base             = MIS_GPO_OFST,
        .ngpio            = GPO_MIS_CNT,
        .can_sleep        = false,
    },
    {
        .label            = "iso_gpio",
        .request          = gpio_ops_request,
        .free             = gpio_ops_free,
        .get_direction    = gpio_ops_get_direction,
        .direction_input  = gpio_ops_set_direction_input,
        .direction_output = gpio_ops_set_direction_output,
        .get              = gpio_ops_get,
        .set              = gpio_ops_set,
        .dbg_show         = gpio_ops_dbg_show,
        .base             = ISO_GPIO_OFST,
        .ngpio            = ISO_GPIO_CNT,
        .can_sleep        = false,
    },
    {
        .label            = "iso_gpi",
        .request          = gpio_ops_request,
        .free             = gpio_ops_free,
        .get_direction    = gpio_ops_get_direction,
        .direction_input  = gpio_ops_set_direction_input,
        .direction_output = gpio_ops_set_direction_output,
        .get              = gpio_ops_get,
        .set              = gpio_ops_set,
        .dbg_show         = gpio_ops_dbg_show,
        .base             = ISO_GPI_OFST,
        .ngpio            = GPI_ISO_CNT,
        .can_sleep        = false,
    },
    {
        .label            = "iso_gpo",
        .request          = gpio_ops_request,
        .free             = gpio_ops_free,
        .get_direction    = gpio_ops_get_direction,
        .direction_input  = gpio_ops_set_direction_input,
        .direction_output = gpio_ops_set_direction_output,
        .get              = gpio_ops_get,
        .set              = gpio_ops_set,
        .dbg_show         = gpio_ops_dbg_show,
        .base             = ISO_GPO_OFST,
        .ngpio            = GPO_ISO_CNT,
        .can_sleep        = false,
    },
};

 #define RTK_GPIO_CHIPSET_CNT     (sizeof(g_rtk_gpio_chipsets)/sizeof(struct gpio_chip))




//----------------------------------------------------------------------
//
//----------------------------------------------------------------------


/*------------------------------------------------------
 * Func : rtk_gpio_id_to_number
 *
 * Desc : convert gpio to global gpio number
 *        where gpio number was used for gpio chipset
 *        driver to identify which GPIO number to be used.
 *
 * Para  : gid : GPIO index
 *         gpio_num : GPIO number output
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
int rtk_gpio_id_to_number(
    RTK_GPIO_ID             gid,
    unsigned int*           gpio_num
    )
{
    RTK_GPIO_GROUP group = gpio_group(gid);

    switch(group) {
    case MIS_GPIO: *gpio_num = MIS_GPIO_OFST; break;
    case MIS_GPI:  *gpio_num = MIS_GPI_OFST;  break;
    case MIS_GPO:  *gpio_num = MIS_GPO_OFST;  break;
    case ISO_GPIO: *gpio_num = ISO_GPIO_OFST; break;
    case ISO_GPI:  *gpio_num = ISO_GPI_OFST;  break;
    case ISO_GPO:  *gpio_num = ISO_GPO_OFST;  break;
    default:
        return -1;
    }

    *gpio_num += gpio_idx(gid);
    return 0;
}



/*------------------------------------------------------
 * Func : _get_gpio_chipset
 *
 * Desc : get GPIO ID
 *
 * Para  : gpio_chip :
 *         offset  : hardware pin number
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static struct gpio_chip* _get_gpio_chipset(RTK_GPIO_ID gid)
{
    RTK_GPIO_GROUP group;
    unsigned int   gpio_base;
    int i;

    switch(group) {
    case MIS_GPIO: gpio_base = MIS_GPIO_OFST; break;
    case MIS_GPI:  gpio_base = MIS_GPI_OFST;  break;
    case MIS_GPO:  gpio_base = MIS_GPO_OFST;  break;
    case ISO_GPIO: gpio_base = ISO_GPIO_OFST; break;
    case ISO_GPI:  gpio_base = ISO_GPI_OFST;  break;
    case ISO_GPO:  gpio_base = ISO_GPO_OFST;  break;
    default:
        return -1;
    }

    for (i=0; i<RTK_GPIO_CHIPSET_CNT; i++)
    {
        if (g_rtk_gpio_chipsets[i].base == gpio_base)
            return &g_rtk_gpio_chipsets[i];
    }

    return NULL;
}


/*------------------------------------------------------
 * Func : _get_gpio_id
 *
 * Desc : get GPIO ID
 *
 * Para  : gpio_chip :
 *         offset  : hardware pin number
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static int _get_gpio_id(
    struct gpio_chip*       chip,
    unsigned                offset,
    RTK_GPIO_ID*            p_gid
    )
{
    RTK_GPIO_GROUP group;

    if (offset >= chip->ngpio)
        return -1;

    switch(chip->base) {
    case MIS_GPIO_OFST: group = MIS_GPIO; break;
    case MIS_GPI_OFST:  group = MIS_GPI;  break;
    case MIS_GPO_OFST:  group = MIS_GPO;  break;
    case ISO_GPIO_OFST: group = ISO_GPIO; break;
    case ISO_GPI_OFST:  group = ISO_GPI;  break;
    case ISO_GPO_OFST:  group = ISO_GPO;  break;
    default:
        return -1;
    }

    *p_gid = rtk_gpio_id(group, offset);

    RTK_GPIO_CHIP_DBG("_get_gpio_id(chip->base=%d, offset=%d) rtk_gpio_id=%x\n",
            chip->base, offset, *p_gid);

    return 0;
}



/*------------------------------------------------------
 * Func : gpio_ops_request
 *
 * Desc : optional hook for chip-specific activation,
 *        such as enabling module power and clock;
 *        may sleep
 *
 * Para  : gpio_chip :
 *         offset  : hardware pin number
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static int gpio_ops_request(struct gpio_chip* chip, unsigned offset)
{
    RTK_GPIO_ID gid;

    RTK_GPIO_CHIP_DBG("gpio_ops_request : id = %d\n", offset);

    if (_get_gpio_id(chip, offset, &gid)<0)
        return -1;

    // TODO:
    return 0;
}



/*------------------------------------------------------
 * Func : gpio_ops_free
 *
 * Desc : optional hook for chip-specific deactivation
 *
 * Para : gpio_chip :
 *         offset  : hardware pin number
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static void gpio_ops_free(struct gpio_chip* chip, unsigned offset)
{
    RTK_GPIO_CHIP_DBG("gpio_ops_request : id = %d\n", offset);
    // TODO:
}



/*------------------------------------------------------
 * Func : gpio_ops_get_direction
 *
 * Desc : returns direction for signal "offset"
 *
 * Para : gpio_chip :
 *         offset  : hardware pin number
 *
 * Retn  : 0 : out, 1 = in
 *------------------------------------------------------*/
static int gpio_ops_get_direction(struct gpio_chip* chip, unsigned offset)
{
    RTK_GPIO_ID gid;
    int dir;

    RTK_GPIO_CHIP_DBG("gpio_ops_request : id = %d\n", offset);

    if (_get_gpio_id(chip, offset, &gid)<0)
        return -1;

    dir = rtk_gpio_get_dir(gid);

    if (dir <0)
        return -1;

    return (dir==0) ? 1 : 0;
}



/*------------------------------------------------------
 * Func  : gpio_ops_set_direction_input
 *
 * Desc  : configures signal "offset" as input, or returns error
 *
 * Para  : gpio_chip :
 *         offset  : hardware pin number
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static int gpio_ops_set_direction_input(struct gpio_chip* chip, unsigned offset)
{
    RTK_GPIO_ID gid;

    RTK_GPIO_CHIP_DBG("gpio_ops_set_direction_input : id = %d\n", offset);

    if (_get_gpio_id(chip, offset, &gid)<0)
        return -1;

    return rtk_gpio_set_dir(gid, 0);
}



/*------------------------------------------------------
 * Func  : gpio_ops_set_direction_output
 *
 * Desc  : configures signal "offset" as output with the
 *         same value, or returns error
 *
 * Para  : gpio_chip :
 *         offset  : hardware pin number
 *         value   : value to output
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static int gpio_ops_set_direction_output(
    struct gpio_chip*           chip,
    unsigned                    offset,
    int                         value
    )
{
    RTK_GPIO_ID gid;

    RTK_GPIO_CHIP_DBG("gpio_ops_set_direction_output : id = %d, value=%d\n", offset, value);

    if (_get_gpio_id(chip, offset, &gid)<0)
        return -1;

    rtk_gpio_output(gid, (value) ? 1 : 0);

    return rtk_gpio_set_dir(gid, 1);
}



/*------------------------------------------------------
 * Func  : gpio_ops_get
 *
 * Desc  : returns value for signal "offset";
 *         for output signals this returns either the
 *         value actually sensed, or zero
 *
 * Para  : gpio_chip :
 *         offset  : hardware pin number
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static int gpio_ops_get(struct gpio_chip* chip, unsigned offset)
{
    RTK_GPIO_ID gid;
    RTK_GPIO_CHIP_DBG("gpio_ops_get : id = %d\n", offset);

    if (_get_gpio_id(chip, offset, &gid)<0)
        return -1;

    return rtk_gpio_input(gid);
}



/*------------------------------------------------------
 * Func  : gpio_ops_set
 *
 * Desc  : set a gpio output value
 *
 * Para  : gpio_chip :
 *         offset  : hardware pin number
 *         value   : output value
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
static void gpio_ops_set(
    struct gpio_chip *      chip,
    unsigned                offset,
    int                     value
    )
{
    RTK_GPIO_ID gid;
    RTK_GPIO_CHIP_DBG("gpio_ops_set : id = %d, value = %d\n", offset, value);

    if (_get_gpio_id(chip, offset, &gid)<0)
        return ;

    rtk_gpio_output(gid, (value) ? 1 : 0);
}



/*------------------------------------------------------
 * Func  : gpio_ops_set_debounce
 *
 * Desc  : set a gpio debounce value
 *
 * Para  : gpio_chip :
 *         offset    : hardware pin number
 *         debounce  : debounce value
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
int gpio_ops_set_debounce(struct gpio_chip *chip, unsigned offset, unsigned debounce)
{
    RTK_GPIO_ID gid;

    RTK_GPIO_CHIP_DBG("gpio_ops_set_debounce : id = %d, value = %d\n", offset, debounce);

    if (_get_gpio_id(chip, offset, &gid)<0)
        return -1;

    return 0;
}



/*------------------------------------------------------
 * Func  : gpio_ops_dbg_show
 *
 * Desc  : dump debug information of GPIO controller
 *
 * Para  : s     : file to write
 *         chip  : gpio chipset
 *
 * Retn  : 0 : success, others failed
 *------------------------------------------------------*/
void gpio_ops_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
    unsigned i;
    unsigned gpio = chip->base;
    struct  gpio_desc *gdesc = &chip->desc[0];
    int is_out;
    int is_irq;

    seq_printf(s, "----------------------------------------------------------------------------\n");
    seq_printf(s, " ID | Name           | Label                             | Dir | Val | IRQ |\n");
    seq_printf(s, "----+----------------+-----------------------------------+-----+-----+-----+\n");

    for (i = 0; i < chip->ngpio; i++, gpio++, gdesc++)
    {
        if (!test_bit(FLAG_REQUESTED, &gdesc->flags))
        {
            if (gdesc->label) {
                seq_printf(s, "%-3d, Name:%s-%-3d Label:%-20.20s\n",
                    gpio, chip->label, i, gdesc->label);
            }
            continue;
        }

        gpiod_get_direction(gdesc);
        is_out = test_bit(FLAG_IS_OUT, &gdesc->flags);
        is_irq = test_bit(FLAG_USED_AS_IRQ, &gdesc->flags);

        seq_printf(s, "%3d | %10s-%-3d | %-32s  |  %s  |  %s  |  %s  |\n",
                    gpio,
                    chip->label,
                    i,
                    gdesc->label,
                    is_out ? "O" : "I",
                    chip->get ? (chip->get(chip, i) ? "H" : "L") : "?",
                    is_irq ? "O" : "X");
    }
}



/*---------------------------------------------------
 * Func : rtk_gpio_register_gpio_chipset
 *
 * Desc : register rtk gpio chipsets to Linux GPIO subsystem
 *
 * Para : na
 *
 * Retn : na
 *---------------------------------------------------*/
int __init rtk_gpio_register_gpio_chipset(void)
{
    int i;

    for (i=0; i<RTK_GPIO_CHIPSET_CNT; i++)
        gpiochip_add(&g_rtk_gpio_chipsets[i]);

    return 0;
}



/*---------------------------------------------------
 * Func : rtk_gpio_unregister_gpio_chipset
 *
 * Desc : unregister rtk gpio chipsets to Linux GPIO subsystem
 *
 * Para : na
 *
 * Retn : na
 *---------------------------------------------------*/
void __exit rtk_gpio_unregister_gpio_chipset(void)
{
    int i;

    for (i=0; i<RTK_GPIO_CHIPSET_CNT; i++)
        gpiochip_remove(&g_rtk_gpio_chipsets[i]);
}
