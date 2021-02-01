#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h>       /* DBG_PRINT() */
#include <linux/slab.h>         /* kmalloc() */
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/seq_file.h>
#include <linux/cdev.h>
#include <linux/kfifo.h>
#include <linux/sysfs.h>
#include <linux/poll.h>
#include <linux/wait.h>
#include <linux/jiffies.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/freezer.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
//#include <asm/system.h>               /* cli(), *_flags */
#include <asm/uaccess.h>        /* copy_*_user */
#include <linux/sched.h>
//#include <linux/devfs_fs_kernel.h> /* for devfs */
#include <linux/time.h>
#include <linux/io.h>
#include <mach/io.h>
#include <asm/irq.h>
#include <linux/signal.h>
#include <asm/bitops.h>         /* bit operations */
#include "irrc_core.h"
#include "irrc_record.h"

extern wait_queue_head_t ir_read_wait;
static int raw_recorder_continous_high_levels = 0;
static wait_queue_head_t ir_recorder_wq;
static struct delayed_work ir_record_work;
static struct kfifo record_raw_fifo;
static struct kfifo recorder_decoded_fifo;
static int is_record_function_init = 0;
static uint32_t the_last_level = 1;
static uint32_t the_last_level_count = 1;

static int ir_recorder_dev_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int ir_recorder_dev_release(struct inode *inode, struct file *file)
{
    return 0;
}

static ssize_t ir_recorder_dev_read(struct file *file,
                                    char __user *buff, size_t size, loff_t *ofst)
{
    unsigned char *tmp_buf;
    int len = 0;
    wait_event_interruptible_timeout(ir_recorder_wq,
                                     kfifo_len(&recorder_decoded_fifo) > 0,
                                     msecs_to_jiffies(100));

    len = kfifo_len(&recorder_decoded_fifo);
    len = (len > size) ? size : len;
    if(len) {
        tmp_buf = kmalloc(len, GFP_KERNEL);
        if(tmp_buf) {
            len = kfifo_out(&recorder_decoded_fifo, tmp_buf, len);
            if(len)
                if(copy_to_user(buff, tmp_buf, len))
                    len = 0;
            kfree(tmp_buf);
        } else {
            len = 0;
        }
    }
    return len;
}



static ssize_t ir_recorder_dev_write(struct file *file,
                                     const char __user *buff, size_t size, loff_t *ofst)
{
    return 0;
}

static long ir_recorder_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    return 0;
}

static struct file_operations ir_recorder_dev_fops = {
    .owner = THIS_MODULE,
    .open = ir_recorder_dev_open,
    .read = ir_recorder_dev_read,
    .write = ir_recorder_dev_write,
    .release = ir_recorder_dev_release,
};

static struct miscdevice rtk_irrc_mod_miscdev = {
    MISC_DYNAMIC_MINOR,
    "ir_recorder",
    &ir_recorder_dev_fops,
};

static void ir_record_dsr(struct work_struct *work)
{
    int len = 0;
    int received = 0;
    uint32_t sample = 0;
    while(kfifo_len(&record_raw_fifo) >= 4) {
        int i = 0;
        len = kfifo_out(&record_raw_fifo, (unsigned char *)&sample, sizeof(uint32_t));
        //IR_DBG("len1 == %d\n",kfifo_len(&record_raw_fifo));
        if(len == 4) {
            int current_level = 0;
            while(i < 32) {
                current_level = (sample >> (31 - i)) & 0x1;
                if(current_level == the_last_level) {
                    the_last_level_count++;
                } else {
                    uint32_t value = 0;
                    if(the_last_level_count >= MAX_KEY_INTERVAL_COUNTS)
                        value = ((the_last_level & 0x1) << 31) | (MAX_KEY_INTERVAL_COUNTS * RECORD_PER_BIT_TIME) ;
                    else
                        value = ((the_last_level & 0x1) << 31) | (the_last_level_count * RECORD_PER_BIT_TIME);

                    /*IR_DBG("value=%08x, the_last_level == %d, the_last_level_count == %d\n",
                            value, the_last_level, the_last_level_count * RECORD_PER_BIT_TIME);*/
                    kfifo_in(&recorder_decoded_fifo, (unsigned char *)&value, sizeof(uint32_t));
                    the_last_level = current_level;
                    the_last_level_count = 1;
                    received = 1;
                }
                i++;
            }
        }
        if(received)
            wake_up_interruptible(&ir_read_wait);
    }
}

void IR_raw_record_decode(void)
{
    int i;
    uint32_t regValue;
    for(i = 0; i < 32; i++) {
        regValue = rtd_inl(REG_IR_RAW_FF);
        if(regValue == 0xffffffff)
            raw_recorder_continous_high_levels++;
        else
            raw_recorder_continous_high_levels = 0;
        if(raw_recorder_continous_high_levels >= CONTINOUS_HIGH_LEVE_COUNT_THRESOLD) {//100ms
            rtd_outl(REG_IR_RAW_CTRL, 0x01000020); // stop sampling
            raw_recorder_continous_high_levels = 0;
            break;
        }
        if(kfifo_in(&record_raw_fifo, (unsigned char *)&regValue, sizeof(uint32_t)) < 4) {
            IR_WARNING("fifo overrun\n");
            rtd_outl(REG_IR_RAW_CTRL, 0x01000020); // stop sampling
            break;
        }
    }
    schedule_delayed_work(&ir_record_work, 0);

}


int IR_record_key_init(void)
{
    int ret = 0;
    if(!is_record_function_init) {
        if(kfifo_alloc(&record_raw_fifo, RECORD_RAW_FIFO_LEN * sizeof(uint32_t), GFP_KERNEL)) {
            IR_DBG("[IR_RECORDER]:can't alloc record_raw_fifo\n");
            ret = -ENOMEM;
            goto fail_alloc_raw_kfifo;
        }
        if(kfifo_alloc(&recorder_decoded_fifo, RECORDER_DECODED_FIFO_LEN * sizeof(uint32_t), GFP_KERNEL)) {
            IR_DBG("[IR_RECORDER]:can't alloc recorder_decoded_fifo\n");
            ret = -ENOMEM;
            goto fail_alloc_decoded_kfifo;
        }
        if (misc_register(&rtk_irrc_mod_miscdev)) {
            IR_DBG("[IR_RECORDER]:register /dev/ir_recorder failed\n");
            ret = -ENODEV;
            goto fail_register_ir_recorder_dev_file;
        }
        init_waitqueue_head(&ir_recorder_wq);
        kfifo_reset(&record_raw_fifo);
        kfifo_reset(&recorder_decoded_fifo);
        the_last_level = 1;
        the_last_level_count = 1;
        INIT_DELAYED_WORK(&ir_record_work, ir_record_dsr);
        is_record_function_init = 1;
        return ret;
    fail_register_ir_recorder_dev_file:
        kfifo_free(&recorder_decoded_fifo);
    fail_alloc_decoded_kfifo:
        kfifo_free(&record_raw_fifo);
    fail_alloc_raw_kfifo:
        return ret;
    }
    return ret;
}

void IR_record_key_fini(void)
{
    if(is_record_function_init) {
        wake_up(&ir_recorder_wq);
        misc_deregister(&rtk_irrc_mod_miscdev);
        kfifo_free(&record_raw_fifo);
        kfifo_free(&recorder_decoded_fifo);
        is_record_function_init = 0;
    }
}


