#ifndef __IRRC_MODULATE_H_
#define __IRRC_MODULATE_H_
#include <linux/kfifo.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#include <rbus/timer_reg.h>
#include <mach/rtk_log.h>
#define TAG_NAME            "IRMD"
#define IRRC_MOD_SET_GPIO_PIN_MUX           0x1001
#define IRRC_MOD_SET_GPIO_PIN_INFO          0x1002
#define IRRC_MOD_SET_GEN_KEY_SEQUENCE       0x1003
#define IRRC_MOD_START_RECORD               0x1004
#define IRRC_MOD_STOP_RECORD                    0x1005
typedef enum {
    IRRC_MOD,
    IRRC_RECORD,
} IRRC_GPIO_FUNC_TYPE;

typedef struct irrc_mod_key_recorder {
    struct kfifo irrc_record_fifo;
    wait_queue_head_t   irrc_record_wq;
    spinlock_t irrc_record_lock;
    atomic_t recorder_mutex;
} IRRC_MOD_KEY_RECORDER;



struct irrc_mod_key_part {
    unsigned int  first_level_interval;
    unsigned int  second_level_interval;
    unsigned char first_level;
    unsigned char second_level;
    unsigned char times;
};
struct irrc_mod_key_sequence {
    unsigned int key_part_len;
    struct irrc_mod_key_part *key_part_array;
};
struct irrc_mod_gpio_pinmux_setting {
    unsigned long pinmux_reg_addr;
    unsigned long val;
    unsigned char msb;
    unsigned char lsb;
};
struct irrc_mod_gpio_pin_info {
    unsigned int pin_num;
    unsigned char pin_type; /*MISC GPIO/ISO GPIO*/
    unsigned char func_type;/*use for record or modulate*/
};

struct  irrc_mod_key_sequence_info {
    unsigned int key_part_len;
    unsigned int info_len;
    char *info_string;
    unsigned int  times;
    unsigned int interval;
};


#ifdef CONFIG_COMPAT
#define COMPAT_IRRC_MOD_SET_GPIO_PIN_MUX            0x1001
#define COMPAT_IRRC_MOD_SET_GEN_KEY_SEQUENCE        0x1003

struct compat_irrc_mod_gpio_pinmux_setting {
    unsigned int pinmux_reg_addr;
    unsigned int val;
    unsigned char msb;
    unsigned char lsb;
};

struct  compat_irrc_mod_key_sequence_info {
    unsigned int key_part_len;
    unsigned int info_len;
    unsigned int info_string;
    unsigned int  times;
    unsigned int interval;
};
#endif


//#define IRRC_MOD_DBG_EN
#ifdef IRRC_MOD_DBG_EN
#define IRRC_MOD_DBG(fmt, args...)      printk( KERN_DEBUG "[IRRC_MOD] DBG, " fmt, ##args)
#else
#define IRRC_MOD_DBG(fmt, args...)
#endif
#define IRRC_MOD_WARNING(fmt, args...)  printk(KERN_WARNING "[IRRC_MOD]WARNING," fmt, ##args)
#endif
