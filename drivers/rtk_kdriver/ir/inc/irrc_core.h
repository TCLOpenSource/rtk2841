#ifndef __IRRC_H
#define  __IRRC_H

#include <linux/interrupt.h>
#include <rtk_kdriver/rtk_crt.h>
#include <mach/irqs.h>
#include "ir_debug.h"
#include "irrc_reg.h"
#include "irrc_common.h"

#ifdef CONFIG_RTK_KDRV_RAW_MODE
#include "irrc_raw.h"
#endif

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
#include "ir_input.h"
#endif

#if defined(CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND)
#include <rtk_kdriver/rtk_gpio.h>
#endif

#ifdef CONFIG_RTK_KDRV_RECORD_KEY
#include <linux/miscdevice.h>
#endif

#ifdef CONFIG_RTK_KDRV_MK5_2
#include "irrc_tv001.h"
#endif

#ifdef CONFIG_RTK_KDRV_TV002_IR_RAW_MODE
#include "irrc_tv002.h"
#endif

#ifdef CONFIG_RTK_KDRV_TV005_IR
#include "irrc_tv005.h"
#endif

#ifdef CONFIG_RTK_KDRV_YK_54LU
#include "irrc_tv010.h"
#endif

#ifdef CONFIG_RTK_KDRV_HAIER_IR
#include "irrc_tv013.h"
#endif

#ifdef CONFIG_RTK_KDRV_TV015_IR
#include "irrc_tv015.h"
#endif

#ifdef CONFIG_RTK_KDRV_TV030_IR
#include "irrc_tv030.h"
#endif

#ifdef CONFIG_RTK_KDRV_TV035_IR
#include "irrc_tv035.h"
#endif

#define IR_IOC_MAGIC                    'r'
#define IR_IOC_SET_IRIOTCDP             _IOW(IR_IOC_MAGIC, 1, int)
#define IR_IOC_FLUSH_IRRP               _IOW(IR_IOC_MAGIC, 2, int)
#define IR_IOC_SET_PROTOCOL             _IOW(IR_IOC_MAGIC, 3, int)
#define IR_IOC_SET_DEBOUNCE             _IOW(IR_IOC_MAGIC, 4, int)
#define IR_IOC_SET_IRPSR                _IOW(IR_IOC_MAGIC, 5, int)
#define IR_IOC_SET_IRPER                _IOW(IR_IOC_MAGIC, 6, int)
#define IR_IOC_SET_IRSF                 _IOW(IR_IOC_MAGIC, 7, int)
#define IR_IOC_SET_IRCR                 _IOW(IR_IOC_MAGIC, 8, int)
#define IR_IOC_SET_DRIVER_MODE          _IOW(IR_IOC_MAGIC, 9, int)
#define IR_IOC_SET_FIRST_REPEAT_DELAY   _IOW(IR_IOC_MAGIC, 10, int)
#define IR_IOC_SET_IR_TO_MOUSE          _IOW(IR_IOC_MAGIC, 11, int)
#define IR_IOC_GET_PROTOCOL             _IOR(IR_IOC_MAGIC, 12, int)
#define IR_IOC_SET_MAIN0_PROTOCOL       _IOW(IR_IOC_MAGIC, 13, int)
#define IR_IOC_GET_MAIN0_PROTOCOL       _IOW(IR_IOC_MAGIC, 14, int)

#define IR_IOC_MAXNR                    12

#define FIFO_DEPTH                      16              /* driver queue depth */

#ifndef IR_PROTOCOL
#define IR_PROTOCOL                     NEC
#endif

#define REPEAT_INTERVAL                 100
#define REPEAT_MAX_INTERVAL             300

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)   gic_irq_find_mapping(hwirq)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)   (hwirq)
#endif

extern int ir_core_pm_suspend(struct platform_device * dev,
                                pm_message_t state);
extern int ir_core_pm_resume(struct platform_device * dev);
extern int ir_core_open(struct inode * inode, struct file * filp);
extern ssize_t ir_core_read(struct file * filp, char __user * buf,
                                size_t count, loff_t *f_pos);
extern unsigned int ir_core_poll(struct file * filp, poll_table * wait);
extern long ir_core_ioctl(struct file * file,
                                unsigned int cmd, unsigned long arg);
extern const char* ir_core_get_cur_remote_control_name(void);
extern void ir_decode_key_on_off(bool on);

extern int __init ir_core_init(void);
extern void __exit ir_core_uninit(void);

#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
void voice_dev_init(void);
static void voice_dev_int_isr(RTK_GPIO_ID gid,
                                unsigned char assert, void *dev);
void voice_dev_uninit(void);
#endif
#endif

