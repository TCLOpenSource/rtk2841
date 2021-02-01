/******************************************************************************
 *
 *   Realtek GPIO debug
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author evenkeel@realtek.com
 *
 *****************************************************************************/
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/pageremap.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <base_types.h>

#include <rtk_gpio.h>
#include <rtk_gpio-debug.h>

unsigned long gpio_dbg_log_level_mask = GPIO_LOG_LEVEL_ERR | GPIO_LOG_LEVEL_WARNING | GPIO_LOG_LEVEL_DEBUG;
unsigned long gpio_dbg_log_block_mask = GPIO_LOG_BLOCK_ALWAYS;

#define rtk_gpio_PROC_DIR                        "rtk_gpio"
#define rtk_gpio_PROC_ENTRY                      "dbg"
#define rtk_gpio_MAX_CMD_LENGTH 256

static const char* cmd_str[GPIO_PROC_COUNT] = {
    GPIO_PROC_PARAM_PRESET_ALLOFF,
    GPIO_PROC_PARAM_PRESET_BASIC,
    GPIO_PROC_PARAM_PRESET_NIGHTRUN,
    GPIO_PROC_PARAM_LOG_ONOFF,
    GPIO_PROC_PARAM_INFO_LOG_EN,
    GPIO_PROC_PARAM_WARNING_LOG_EN,
    GPIO_PROC_PARAM_TRACE_LOG_EN,
    GPIO_PROC_PARAM_IOCTL_LOG_EN,
};

unsigned char gpio_log_onoff = 0;

static int rtk_gpio_proc_write(
    struct file *file,
    const char __user *buf,
    size_t count,
    loff_t *ppos){

    UINT8 i ;
    UINT8 str[128 + 1];
    INT32 input_data;
    UINT8 *cmd = str;
    /* check parameter */
    if(buf == NULL) {
        RTK_GPIO_ERROR("buf=%p\n", buf);
        return -EFAULT;
    }

    if (count > 128) { /* procfs write and read has PAGE_SIZE limit */
        RTK_GPIO_WARNING("command too long, set length to 128 Byte\n");
        count = 128;
    }

    if (copy_from_user(str, buf, count)) {
        RTK_GPIO_ERROR("copy_from_user failed! (buf=%p, count=%u)\n", buf, count);
        return -EFAULT;
    }

    str[count] = '\0';
#if 1
    RTK_GPIO_DBG_SIMPLE("proc data: %s\n", str);
#endif

    /* get command string */
    for( i = 0; i < GPIO_PROC_COUNT; i++) {
        if (strncmp(str, cmd_str[i], strlen(cmd_str[i])) == 0) {
                RTK_GPIO_DBG_SIMPLE("GPIO debug command: %s\n", cmd_str[i]);
                break;
        }
    }

    /* command out of range check */
    if ( i >= GPIO_PROC_COUNT ) {
        RTK_GPIO_ERROR("Cannot find your command: \"%s\"\n", str);
        return -EINVAL;

    } else {
        /* get parameter */
        cmd += strlen(cmd_str[i]);
        if (sscanf(cmd, "%d", &input_data) < 1) {
                RTK_GPIO_DBG_SIMPLE("sscanf get more data failed (%s) - there is no more parameter.\n", cmd);
                //return -EFAULT;
        } else {
                RTK_GPIO_DBG_SIMPLE("input data=%d\n", input_data);
        }
    }

    switch(i) {
        case GPIO_PROC_PRESET_ALLOFF: {
            gpio_log_onoff = 0;

            CLEAR_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_INFO);
            CLEAR_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_WARNING);
            CLEAR_LOG_BLOCK_MASK(GPIO_LOG_BLOCK_FUNCTIN_CALLER);
            RTK_GPIO_DBG_SIMPLE("Turn Off all GPIO logs\n");

            break;
        }
        case GPIO_PROC_PRESET_BASIC: {
            gpio_log_onoff = 1;

            CLEAR_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_INFO);
            SET_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_WARNING);

            CLEAR_LOG_BLOCK_MASK(GPIO_LOG_BLOCK_FUNCTIN_CALLER);

            RTK_GPIO_DBG_SIMPLE("Enable GPIO Preset Basic log\n");

            break;
        }
        case GPIO_PROC_PRESET_NIGHTRUN: {
            gpio_log_onoff = 1;

            CLEAR_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_INFO);
            SET_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_WARNING);

            CLEAR_LOG_BLOCK_MASK(GPIO_LOG_BLOCK_FUNCTIN_CALLER);

            RTK_GPIO_DBG_SIMPLE("Enable GPIO Preset Night Run log\n");

            break;
        }
        case GPIO_PROC_LOG_ONOFF: {
            gpio_log_onoff = (UINT32)input_data;

            if ( input_data == 1 ) {
                    RTK_GPIO_DBG_SIMPLE("Enable GPIO log\n");
            } else {
                    RTK_GPIO_DBG_SIMPLE("Disable GPIO log\n");
            }

                break;
        }
        case GPIO_PROC_INFO_LOG_EN: {
            if(input_data == 1) {
                    SET_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_INFO);
            } else {
                    CLEAR_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_INFO);
            }

            if ( input_data == 1 ) {
                    RTK_GPIO_DBG_SIMPLE("Enable GPIO info log\n");
            } else {
                    RTK_GPIO_DBG_SIMPLE("Disable GPIO info log\n");
            }

            break;
        }
        case GPIO_PROC_WARNING_LOG_EN: {
            if(input_data == 1) {
                    SET_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_WARNING);
            } else {
                    CLEAR_LOG_LEVEL_MASK(GPIO_LOG_LEVEL_WARNING);
            }

            if ( input_data == 1 )
                    RTK_GPIO_DBG_SIMPLE("Enable GPIO warning log\n");
            else
                    RTK_GPIO_DBG_SIMPLE("Disable GPIO warning log\n");

            break;
        }
        case GPIO_PROC_TRACE_LOG_EN: {
            if(input_data == 1) {
                    SET_LOG_BLOCK_MASK(GPIO_LOG_BLOCK_FUNCTIN_CALLER);
            } else {
                    CLEAR_LOG_BLOCK_MASK(GPIO_LOG_BLOCK_FUNCTIN_CALLER);
            }

            if ( input_data == 1 )
                    RTK_GPIO_DBG_SIMPLE("Enable GPIO function trace log\n");
            else
                    RTK_GPIO_DBG_SIMPLE("Disable GPIO function trace log\n");

            break;
        }
        case GPIO_PROC_IOCTL_LOG_EN: {
            if(input_data == 1) {
                    SET_LOG_BLOCK_MASK(GPIO_LOG_BLOCK_IOCTL);
            } else {
                    CLEAR_LOG_BLOCK_MASK(GPIO_LOG_BLOCK_IOCTL);
            }

            if ( input_data == 1 )
                    RTK_GPIO_DBG_SIMPLE("Enable GPIO function ioctl log\n");
            else
                    RTK_GPIO_DBG_SIMPLE("Disable GPIO function ioctl log\n");

            break;
        }

        default:
            break;
        }
    return count;
}

/*TODO: fix it in the future*/
static int rtk_gpio_proc_read(
    struct file *file,
    char __user *buf,
    size_t count,
    loff_t *ppos)
{
    char *str = "rtk_gpio kernel driver debug message\n";
    int len = strlen(str);
    if (copy_to_user(buf, str, len)) {
        RTK_GPIO_DBG_SIMPLE("rtk_gpio_debug:%d Copy proc data to user space failed\n",
            __LINE__);
        return 0;
    }

    if (*ppos == 0)
        *ppos += len;
    else
        len = 0;
    return len;
}


/*****************************************************************************/

static const struct file_operations rtk_gpio_proc_fops = {
    .owner = THIS_MODULE,
    .write = rtk_gpio_proc_write,
    .read = rtk_gpio_proc_read,
};

struct proc_dir_entry *rtk_gpio_proc_dir;
struct proc_dir_entry *rtk_gpio_proc_entry;

bool rtk_gpio_init_debug_proc(void)
{
    if (rtk_gpio_proc_dir == NULL && rtk_gpio_proc_entry == NULL) {
        rtk_gpio_proc_dir = proc_mkdir(rtk_gpio_PROC_DIR , NULL);

        if (rtk_gpio_proc_dir != NULL) {
            rtk_gpio_proc_entry =
                proc_create(rtk_gpio_PROC_ENTRY, 0666,
                    rtk_gpio_proc_dir, &rtk_gpio_proc_fops);

            if (rtk_gpio_proc_entry == NULL) {
                proc_remove(rtk_gpio_proc_dir);
                rtk_gpio_proc_dir = NULL;
                RTK_GPIO_DBG_SIMPLE("failed to get proc entry for %s/%s\n",
                    rtk_gpio_PROC_DIR, rtk_gpio_PROC_ENTRY);
                return false;
            }

        } else {
            RTK_GPIO_DBG_SIMPLE("create rtk_gpio dir proc entry (%s) failed\n",
                rtk_gpio_PROC_DIR);
            return false;
        }
    }

    return true;
}

void rtk_gpio_uninit_debug_proc(void)
{
    if (rtk_gpio_proc_entry) {
        proc_remove(rtk_gpio_proc_entry);
        rtk_gpio_proc_entry = NULL;
    }

    if (rtk_gpio_proc_dir) {
        proc_remove(rtk_gpio_proc_dir);
        rtk_gpio_proc_dir = NULL;
    }
}
