#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <linux/compat.h>
#include <linux/sysfs.h>
#include <linux/kthread.h>
#include <linux/err.h>
#include <linux/kfifo.h>
#include <rtk_kdriver/rtk_gpio.h>
#include "irrc_modulate.h"

#define     MAX_KEY_SEQ_ARR_NUM         128
#define     OTP_BIT_MASK(i)                 (0xFFFFFFFF >> (32-(i)))
#define     WRITE_REG(reg_addr,para)            rtd_outl(reg_addr,para)
#define     READ_REG(reg_addr)              rtd_inl(reg_addr)
#define     RTK_GPIO_SET_DIR(pin, value)        rtk_gpio_set_dir(pin, value)
#define     RTK_GPIO_INPUT(pin)             rtk_gpio_input(pin)
#define     RTK_GPIO_OUTPUT(pin, value)     rtk_gpio_output(pin, value)
#define     RTK_GPIO_SET_DEBOUNCE(pin, value)   rtk_gpio_set_debounce(pin, value)
#define     RTK_GPIO_SET_IRQ_POLARITY(pin, value)   rtk_gpio_set_irq_polarity(pin, value)
#define     RTK_GPIO_SET_IRQ_ENABLE(pin, value)     rtk_gpio_set_irq_enable(pin, value)
#define     RTK_GPIO_REQUEST_IRQ(pin, isr, name, dev_id)    rtk_gpio_request_irq(pin, isr, name, dev_id)
#define     RTK_GPIO_FREE_IRQ(pin, dev_id)  rtk_gpio_free_irq(pin, dev_id)
#define     RTK_GPIO_CLEAR_ISR(pin)     rtk_gpio_clear_isr(pin)
#define     GET_RTK_GPIO_ID(group, num)     rtk_gpio_id(group, num);

#define     KEY_DELAY(x)                        {if((x) / 1000)  mdelay((x)/1000); udelay((x)%1000);}

static RTK_GPIO_ID g_irrc_mod_pin;
static RTK_GPIO_ID g_irrc_record_pin;
#ifdef IRRC_RECORD_BY_POLLING
struct completion g_irrc_record_thread_exited;
static int g_irrc_record_thread_exited_flag = 0;
static struct task_struct * g_irrc_record_tast_struct = NULL;
#endif
static IRRC_MOD_KEY_RECORDER g_irrc_key_recorder;

static struct irrc_mod_key_sequence* alloc_key_sequence(int key_part_len)
{
    struct irrc_mod_key_sequence  *pkey_seq = NULL;
    if(key_part_len <= 0)
        return NULL;
    pkey_seq = (struct irrc_mod_key_sequence  *)
               kmalloc(sizeof(struct irrc_mod_key_sequence), GFP_KERNEL);
    if(!pkey_seq)
        return NULL;
    memset(pkey_seq, 0, sizeof(struct irrc_mod_key_sequence));

    pkey_seq->key_part_array = (struct irrc_mod_key_part *)kmalloc
                               (sizeof(struct irrc_mod_key_part) * key_part_len, GFP_KERNEL);
    if(!pkey_seq->key_part_array) {
        kfree(pkey_seq);
        return NULL;
    }
    pkey_seq->key_part_len = key_part_len;
    memset(pkey_seq->key_part_array, 0, sizeof(struct irrc_mod_key_part) * key_part_len);
    return pkey_seq;
}

static void free_key_sequence(struct irrc_mod_key_sequence*pkey_seq)
{
    if(pkey_seq) {
        if(pkey_seq->key_part_array) {
            kfree(pkey_seq->key_part_array);
            pkey_seq->key_part_array = NULL;
        }
        kfree(pkey_seq);
        pkey_seq = NULL;
    }
}

static void irrc_mod_set_gpio_pinmux(unsigned long pinmux_reg_addr, unsigned long msb, unsigned long lsb, unsigned long val)
{
    unsigned long mask = OTP_BIT_MASK(msb - lsb + 1);
    mask <<= lsb;
    mask = (~mask);
    val &= OTP_BIT_MASK(msb - lsb + 1);
    val <<= lsb;
    IRRC_MOD_DBG("irrc_mod_set_gpio_pinmux:mask == %08x, val == %08x\n", mask, val);
    WRITE_REG(pinmux_reg_addr, (READ_REG(pinmux_reg_addr) & mask) | val);
}

static int irrc_mod_set_gpio_pin_info(IRRC_GPIO_FUNC_TYPE func_type, unsigned char pin_type, unsigned int pin_num)
{
    if(func_type >= 2 || pin_type >= 2)
        return -1;
    IRRC_MOD_DBG("irrc_mod_set_gpio_pin_info:func_type == %u, pin_type == %u, pin_num == %u\n", func_type, pin_type, pin_num);
    if(func_type == IRRC_MOD) {
        g_irrc_mod_pin =  GET_RTK_GPIO_ID(pin_type, pin_num);
        RTK_GPIO_SET_DIR(g_irrc_mod_pin, 1);
        RTK_GPIO_OUTPUT(g_irrc_mod_pin, 1);
    } else {
        g_irrc_record_pin =  GET_RTK_GPIO_ID(pin_type, pin_num);
        RTK_GPIO_SET_DIR(g_irrc_record_pin, 0);
    }
    return 0;
}

static struct irrc_mod_key_sequence* irrc_mod_get_key_sequence
(char *seq_info, unsigned int seq_info_len, unsigned int key_part_len)
{
    char *pTmp = NULL;
    struct irrc_mod_key_sequence  *pkey_seq = NULL;
    unsigned int fact_len = 0;
    if(seq_info == NULL || seq_info_len <= 0 || key_part_len <= 0)
        return NULL;

    pkey_seq = alloc_key_sequence(key_part_len);
    if(!pkey_seq)
        return NULL;
    while(NULL != ( pTmp = strsep(&seq_info, ":"))) {
        if( fact_len < key_part_len) {
            unsigned int times, first_level, first_level_interval, second_level, second_level_interval;
            if(5 == sscanf(pTmp, "%u,%u,%u,%u,%u", &times, &first_level, &first_level_interval,
                           &second_level, &second_level_interval)) {
                pkey_seq->key_part_array[fact_len].times = times;
                pkey_seq->key_part_array[fact_len].first_level = first_level;
                pkey_seq->key_part_array[fact_len].first_level_interval = first_level_interval;
                pkey_seq->key_part_array[fact_len].second_level = second_level;
                pkey_seq->key_part_array[fact_len].second_level_interval = second_level_interval;

                IRRC_MOD_DBG("irrc_mod_parse_key_sequence:Seq[%d]:times == %u, first_level = %u, first_level_interval == %u, second_level==%u, second_level_interval==%u\n",
                             fact_len, pkey_seq->key_part_array[fact_len].times, pkey_seq->key_part_array[fact_len].first_level, pkey_seq->key_part_array[fact_len].first_level_interval,
                             pkey_seq->key_part_array[fact_len].second_level, pkey_seq->key_part_array[fact_len].second_level_interval);
                fact_len++;

            } else {
                goto PARSE_FAILED;
            }
        } else {
            goto PARSE_FAILED;
        }
    }
    return pkey_seq;

PARSE_FAILED:
    free_key_sequence(pkey_seq);
    return NULL;

}

static int irrc_mod_generate_key_sequece(struct irrc_mod_key_sequence* pkey_sequence, unsigned int times, unsigned int interval)
{
    int i = 0;
    if(!pkey_sequence || !pkey_sequence->key_part_array || times == 0)
        return -1;
    while(times-- > 0) {
        if(interval)
            msleep(interval);
        else
            msleep(1000);
        preempt_disable();
        for(i = 0; i < pkey_sequence->key_part_len; i++) {
            int j = 0;
            for(j = 0; j < pkey_sequence->key_part_array[i].times; j++) {
                RTK_GPIO_OUTPUT(g_irrc_mod_pin, pkey_sequence->key_part_array[i].first_level);
                if(pkey_sequence->key_part_array[i].first_level_interval)
                    KEY_DELAY(pkey_sequence->key_part_array[i].first_level_interval);
                RTK_GPIO_OUTPUT(g_irrc_mod_pin, pkey_sequence->key_part_array[i].second_level);
                if(pkey_sequence->key_part_array[i].second_level_interval)
                    KEY_DELAY(pkey_sequence->key_part_array[i].second_level_interval);
            }
        }
        preempt_enable();
    }
    return 0;
}
static inline int64_t IRRC_MOD_CLOCK_GetCount(void)
{
    unsigned int ptrlo = READ_REG(TIMER_SCPU_CLK90K_LO_reg) ;
    unsigned int ptrhi = READ_REG(TIMER_SCPU_CLK90K_HI_reg) ;
    int64_t ret = ptrlo | (((int64_t)ptrhi) << 32) ;
    return ret ;
}
#ifdef IRRC_RECORD_BY_POLLING
static int irrc_mod_record_poll_gpio(void *arg)
{
    int last_gpio_val = 1;
    int now_gpio_val = 1;
    int64_t prev_90k_timer_counter = 0;
    int64_t now_90k_timer_counter = 0;
    int64_t time_us;
    unsigned int element;

    preempt_disable();
    prev_90k_timer_counter = IRRC_MOD_CLOCK_GetCount();
    last_gpio_val = RTK_GPIO_INPUT(g_irrc_record_pin);

    while (!g_irrc_record_thread_exited_flag) {
        now_gpio_val = RTK_GPIO_INPUT(g_irrc_record_pin);
        if(now_gpio_val != last_gpio_val) {
            now_90k_timer_counter = IRRC_MOD_CLOCK_GetCount();
            time_us = now_90k_timer_counter - prev_90k_timer_counter;
            element = 0;
            if(time_us < 0 || time_us >= 90000)
                time_us = 90000;
            element = element | (last_gpio_val << 31) | time_us;

            if (kfifo_in_locked(&g_irrc_key_recorder.irrc_record_fifo, &element, 4,
                                &g_irrc_key_recorder.irrc_record_lock) < 4) {
                rtd_printk(KERN_DEBUG, TAG_NAME, "[IRRC_MOD] : fifo over flow... flush data...:%d\n", kfifo_len(&g_irrc_key_recorder.irrc_record_fifo));
                kfifo_reset(&g_irrc_key_recorder.irrc_record_fifo);
            }
            spin_lock(&g_irrc_key_recorder.irrc_record_lock);
            //rtd_printk(KERN_DEBUG, TAG_NAME, "ELEMENT:%d,%d\n", last_gpio_val, time_us);
            spin_unlock(&g_irrc_key_recorder.irrc_record_lock);


            last_gpio_val = now_gpio_val;
            prev_90k_timer_counter = now_90k_timer_counter;
        }
        udelay(100);
    }

    preempt_enable();
    complete_and_exit(&g_irrc_record_thread_exited, 1);
}
#else
static void irrc_mod_rec_gpio_int_isr(RTK_GPIO_ID gid, unsigned char assert,
                                      void *dev_id)
{
    static int last_gpio_val = 1;
    static int now_gpio_val = 1;
    static int64_t prev_90k_timer_counter = 0;
    static int64_t now_90k_timer_counter = 0;
    unsigned int element;
    int64_t time_us;
    now_gpio_val = RTK_GPIO_INPUT(g_irrc_record_pin);
    if(now_gpio_val != last_gpio_val) {
        now_90k_timer_counter = IRRC_MOD_CLOCK_GetCount();
        time_us = now_90k_timer_counter - prev_90k_timer_counter;
        element = 0;
        if(time_us < 0 || time_us >= 90000)
            time_us = 90000;
        element = element | ((last_gpio_val << 31) | time_us);
        //rtd_printk(KERN_DEBUG, TAG_NAME, "kernel:%d, %d, %08x\n", last_gpio_val, time_us, element);

        if (kfifo_in_locked(&g_irrc_key_recorder.irrc_record_fifo, &element, 4,
                            &g_irrc_key_recorder.irrc_record_lock) < 4) {
            rtd_printk(KERN_DEBUG, TAG_NAME, "[IRRC_MOD] : fifo over flow... flush data...:%d\n", kfifo_len(&g_irrc_key_recorder.irrc_record_fifo));
            kfifo_reset(&g_irrc_key_recorder.irrc_record_fifo);
        }
        last_gpio_val = now_gpio_val;
        prev_90k_timer_counter = now_90k_timer_counter;
    }

}
#endif
static int irrc_mod_start_record(void)
{
    int err;
    if(!atomic_dec_and_test(&g_irrc_key_recorder.recorder_mutex)) {
        err = -1;
        goto FAIL_IN_RECORD_PROCESS;
    }

    if (kfifo_alloc(&g_irrc_key_recorder.irrc_record_fifo, PAGE_SIZE, GFP_KERNEL) < 0) {
        rtd_printk(KERN_DEBUG, TAG_NAME, "[IRRC_MODE]:alloc rx fifo mem failed\n");
        err = -ENOMEM;
        goto FAIL_ALLOC_FIFO_MEM;
    }
    kfifo_reset(&g_irrc_key_recorder.irrc_record_fifo);
    spin_lock_init(&g_irrc_key_recorder.irrc_record_lock);
    init_waitqueue_head(&g_irrc_key_recorder.irrc_record_wq);

    WRITE_REG(TIMER_CLK90K_CTRL_reg, READ_REG(TIMER_CLK90K_CTRL_reg) | TIMER_CLK90K_CTRL_en(1));

#ifdef IRRC_RECORD_BY_POLLING
    g_irrc_record_thread_exited_flag = 0;
    init_completion(&g_irrc_record_thread_exited);
    g_irrc_record_tast_struct = kthread_create(irrc_mod_record_poll_gpio, NULL, "IRRC_RECORD");
    if(IS_ERR(g_irrc_record_tast_struct)) {
        rtd_printk(KERN_DEBUG, TAG_NAME, "[IRRC_MOD]:ceate record thread error\n");
        err = -EFAULT;
        goto FAIL_CREATE_KERNEL_THREAD;
    }
    wake_up_process(g_irrc_record_tast_struct);
#else
    RTK_GPIO_SET_DIR(g_irrc_record_pin, 0);
    RTK_GPIO_SET_DEBOUNCE(g_irrc_record_pin, RTK_GPIO_DEBOUNCE_100us);  /* 100 us*/
    RTK_GPIO_SET_IRQ_POLARITY(g_irrc_record_pin, 0);
    RTK_GPIO_REQUEST_IRQ(g_irrc_record_pin, irrc_mod_rec_gpio_int_isr,
                         "IRRC_RECORD_INT", irrc_mod_rec_gpio_int_isr);
    RTK_GPIO_SET_IRQ_ENABLE(g_irrc_record_pin, 1);
#endif

    return 0;
#ifdef IRRC_RECORD_BY_POLLING
FAIL_CREATE_KERNEL_THREAD:
    kfifo_free(&g_irrc_key_recorder.irrc_record_fifo);
    g_irrc_record_tast_struct = NULL;
#endif
FAIL_ALLOC_FIFO_MEM:
FAIL_IN_RECORD_PROCESS:
    atomic_inc(&g_irrc_key_recorder.recorder_mutex);
    return err;

}

static int irrc_mod_stop_record(void)
{
#ifdef IRRC_RECORD_BY_POLLING
    if(g_irrc_record_tast_struct) {
        g_irrc_record_thread_exited_flag = 1;
        wait_for_completion(&g_irrc_record_thread_exited);
        wake_up(&g_irrc_key_recorder.irrc_record_wq);
        kfifo_free(&g_irrc_key_recorder.irrc_record_fifo);
        g_irrc_record_tast_struct = NULL;
    }
#else
    RTK_GPIO_SET_IRQ_ENABLE(g_irrc_record_pin, 0);
    RTK_GPIO_CLEAR_ISR(g_irrc_record_pin);
    RTK_GPIO_FREE_IRQ(g_irrc_record_pin, irrc_mod_rec_gpio_int_isr);
    wake_up(&g_irrc_key_recorder.irrc_record_wq);
    kfifo_free(&g_irrc_key_recorder.irrc_record_fifo);
#endif
    atomic_inc(&g_irrc_key_recorder.recorder_mutex);

    return 0;

}



static int irrc_mod_dev_open(struct inode *inode, struct file *file)

{

    return 0;

}



static int irrc_mod_dev_release(struct inode *inode, struct file *file)

{

    return 0;

}



static ssize_t irrc_mod_dev_read(struct file *file,

                                 char __user *buff, size_t size, loff_t *ofst)

{

    unsigned char *tmp_buf;

    int len = 0;

    wait_event_interruptible_timeout(g_irrc_key_recorder.irrc_record_wq,

                                     kfifo_len(&g_irrc_key_recorder.irrc_record_fifo) > 0,

                                     msecs_to_jiffies(100));



    len = kfifo_len(&g_irrc_key_recorder.irrc_record_fifo);

    len = (len > size) ? size : len;



    if(len) {

        tmp_buf = kmalloc(len, GFP_KERNEL);

        if(tmp_buf) {

            len = kfifo_out_locked(&g_irrc_key_recorder.irrc_record_fifo, tmp_buf, len,

                                   &g_irrc_key_recorder.irrc_record_lock);

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



static ssize_t irrc_mod_dev_write(struct file *file,

                                  const char __user *buff, size_t size, loff_t *ofst)

{

    return 0;

}



static long irrc_mod_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)



{

    int ret = -EFAULT;

    switch(cmd) {

        case IRRC_MOD_SET_GPIO_PIN_MUX: {

            struct irrc_mod_gpio_pinmux_setting gpio_pinmux_setting;

            if (arg == 0 || copy_from_user(&gpio_pinmux_setting, (void *)arg, sizeof(struct irrc_mod_gpio_pinmux_setting)))

                return -EFAULT;

            irrc_mod_set_gpio_pinmux(gpio_pinmux_setting.pinmux_reg_addr, gpio_pinmux_setting.msb, gpio_pinmux_setting.lsb, gpio_pinmux_setting.val);

            return 0;

        }

        case IRRC_MOD_SET_GPIO_PIN_INFO: {

            struct irrc_mod_gpio_pin_info gpio_pin_info;

            if (arg == 0 || copy_from_user(&gpio_pin_info, (void *)arg, sizeof(struct irrc_mod_gpio_pin_info)))

                return -EFAULT;

            return irrc_mod_set_gpio_pin_info(gpio_pin_info.func_type, gpio_pin_info.pin_type, gpio_pin_info.pin_num);

        }

        case IRRC_MOD_SET_GEN_KEY_SEQUENCE: {

            char *key_seqs_str = NULL;

            struct  irrc_mod_key_sequence_info key_seq_info;

            struct irrc_mod_key_sequence *pkey_seq = NULL;

            if (arg == 0 || copy_from_user(&key_seq_info, (void *)arg, sizeof(struct  irrc_mod_key_sequence_info)))

                return -EFAULT;



            if(key_seq_info.info_len > 0)

                key_seqs_str = (char *)kmalloc(key_seq_info.info_len + 1, GFP_KERNEL);

            if(!key_seqs_str)

                return -ENOMEM;



            memset(key_seqs_str, 0, key_seq_info.info_len + 1);

            if (copy_from_user(key_seqs_str, key_seq_info.info_string, key_seq_info.info_len)) {

                kfree(key_seqs_str);

                return -EFAULT;

            }

            pkey_seq = irrc_mod_get_key_sequence(key_seqs_str, key_seq_info.info_len, key_seq_info.key_part_len);

            if(pkey_seq)

                ret = irrc_mod_generate_key_sequece(pkey_seq, key_seq_info.times, key_seq_info.interval);

            else

                ret = -ENOMEM;

            free_key_sequence(pkey_seq);

            kfree(key_seqs_str);

            key_seqs_str = NULL;

            return ret;

        }

        case IRRC_MOD_START_RECORD: {

            return irrc_mod_start_record();

        }

        case IRRC_MOD_STOP_RECORD: {

            return irrc_mod_stop_record();

        }



        default: {



            break;



        }







    }



    return ret;



}



#ifdef CONFIG_COMPAT



static long irrc_mod_dev_compat_ioctl(struct file *file, unsigned int cmd, unsigned long arg)



{



    int ret = -EFAULT;











    switch(cmd) {



        case COMPAT_IRRC_MOD_SET_GPIO_PIN_MUX: {



            struct compat_irrc_mod_gpio_pinmux_setting gpio_pinmux_setting;



            if (arg == 0 || copy_from_user(&gpio_pinmux_setting, compat_ptr(arg), sizeof(struct compat_irrc_mod_gpio_pinmux_setting)))



                return -EFAULT;



            irrc_mod_set_gpio_pinmux(gpio_pinmux_setting.pinmux_reg_addr, gpio_pinmux_setting.msb, gpio_pinmux_setting.lsb, gpio_pinmux_setting.val);



            return 0;



        }



        case IRRC_MOD_SET_GPIO_PIN_INFO: {



            struct irrc_mod_gpio_pin_info gpio_pin_info;



            if (arg == 0 || copy_from_user(&gpio_pin_info, (void *)arg, sizeof(struct irrc_mod_gpio_pin_info)))



                return -EFAULT;



            return irrc_mod_set_gpio_pin_info(gpio_pin_info.func_type, gpio_pin_info.pin_type, gpio_pin_info.pin_num);



        }



        case COMPAT_IRRC_MOD_SET_GEN_KEY_SEQUENCE: {



            char *key_seqs_str = NULL;



            struct  compat_irrc_mod_key_sequence_info key_seq_info;



            struct irrc_mod_key_sequence *pkey_seq = NULL;



            if (arg == 0 || copy_from_user(&key_seq_info, compat_ptr(arg), sizeof(struct  compat_irrc_mod_key_sequence_info)))



                return -EFAULT;



            if(key_seq_info.info_len > 0)



                key_seqs_str = (char *)kmalloc(key_seq_info.info_len + 1, GFP_KERNEL);



            if(!key_seqs_str)



                return -ENOMEM;



            memset(key_seqs_str, 0, key_seq_info.info_len + 1);



            if (copy_from_user(key_seqs_str, compat_ptr(key_seq_info.info_string), key_seq_info.info_len)) {
                kfree(key_seqs_str);
                return -EFAULT;
            }

            pkey_seq = irrc_mod_get_key_sequence(key_seqs_str, key_seq_info.info_len, key_seq_info.key_part_len);
            if(pkey_seq)
                ret = irrc_mod_generate_key_sequece(pkey_seq, key_seq_info.times, key_seq_info.interval);
            else
                ret = -ENOMEM;
            free_key_sequence(pkey_seq);
            kfree(key_seqs_str);
            key_seqs_str = NULL;
            return ret;
        }
        case IRRC_MOD_START_RECORD: {
            return irrc_mod_start_record();
        }
        case IRRC_MOD_STOP_RECORD: {
            return irrc_mod_stop_record();
        }
        default: {
            break;
        }
    }
    return ret;
}
#endif

static struct file_operations irrc_mod_dev_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = irrc_mod_dev_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl = irrc_mod_dev_compat_ioctl,
#endif
    .open = irrc_mod_dev_open,
    .read = irrc_mod_dev_read,
    .write = irrc_mod_dev_write,
    .release = irrc_mod_dev_release,
};

static struct miscdevice rtk_irrc_mod_miscdev = {
    MISC_DYNAMIC_MINOR,
    "irrc_mod",
    &irrc_mod_dev_fops,
};

int __init irrc_mod_module_init(void)

{
    int ret = 0;
    if (misc_register(&rtk_irrc_mod_miscdev)) {
        rtd_printk(KERN_ERR, TAG_NAME,  "[IRRC_MOD]register irrc mod misc dev file failed\n");
        ret = -ENODEV;
        goto FAIL_REGISTER_MISC_DEV;
    }
    atomic_set(&g_irrc_key_recorder.recorder_mutex, 1);
    return 0;
FAIL_REGISTER_MISC_DEV:
    return ret;
}

void __exit irrc_mod_module_exit(void)
{
    misc_deregister(&rtk_irrc_mod_miscdev);
}
module_init(irrc_mod_module_init);
module_exit(irrc_mod_module_exit);

