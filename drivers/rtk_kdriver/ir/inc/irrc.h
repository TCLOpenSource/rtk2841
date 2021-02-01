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

/* Module Variables */
/*
 * Our parameters which can be set at load time.
 */
#define IR_MAJOR			234
#define IR_DEVICE_NUM			1
#define IR_MINOR_RP			50
#define IR_DEVICE_NAME			"irrp"

#define IR_IOC_MAGIC			'r'
#define IR_IOC_SET_IRIOTCDP		_IOW(IR_IOC_MAGIC, 1, int)
#define IR_IOC_FLUSH_IRRP		_IOW(IR_IOC_MAGIC, 2, int)
#define IR_IOC_SET_PROTOCOL		_IOW(IR_IOC_MAGIC, 3, int)
#define IR_IOC_SET_DEBOUNCE		_IOW(IR_IOC_MAGIC, 4, int)
#define IR_IOC_SET_IRPSR		_IOW(IR_IOC_MAGIC, 5, int)
#define IR_IOC_SET_IRPER		_IOW(IR_IOC_MAGIC, 6, int)
#define IR_IOC_SET_IRSF			_IOW(IR_IOC_MAGIC, 7, int)
#define IR_IOC_SET_IRCR			_IOW(IR_IOC_MAGIC, 8, int)
#define IR_IOC_SET_DRIVER_MODE		_IOW(IR_IOC_MAGIC, 9, int)
#define IR_IOC_SET_FIRST_REPEAT_DELAY	_IOW(IR_IOC_MAGIC, 10, int)
#define IR_IOC_SET_IR_TO_MOUSE		_IOW(IR_IOC_MAGIC, 11, int)
#define IR_IOC_GET_PROTOCOL		_IOR(IR_IOC_MAGIC, 12, int)
#define IR_IOC_SET_MAIN0_PROTOCOL	_IOW(IR_IOC_MAGIC, 13, int)
#define IR_IOC_GET_MAIN0_PROTOCOL	_IOW(IR_IOC_MAGIC, 14, int)

#define IR_IOC_MAXNR			12

#define FIFO_DEPTH      		16              /* driver queue depth */

#ifndef IR_PROTOCOL
#define IR_PROTOCOL			NEC
#endif

#define REPEAT_INTERVAL         	100
#define REPEAT_MAX_INTERVAL             300

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)           gic_irq_find_mapping(hwirq)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)           (hwirq)
#endif
#ifdef CONFIG_QUICK_HIBERNATION
extern int in_suspend;
#endif

/*
*main1decode for ir_support_protocols[0]
*main0decode for ir_support_protocols[1]
*/
int ir_support_protocols[MAX_HW_RTK_KDRV_PROTOCOLS_NUM] = {IR_PROTOCOL, 0};
int ir_protocol = IR_PROTOCOL;
int ir_boot_sel_protocol = 0;
unsigned int ir_repeat_interval = REPEAT_INTERVAL;
static unsigned int debounce = 100;
unsigned int lastRecvMs;
uint32_t lastSrValue = 0;

bool ir_decode_dbg_en = false;

DECLARE_WAIT_QUEUE_HEAD(ir_read_wait);
struct kfifo ir_fifo;

struct kobject *ir_kobj;
extern struct attribute_group ir_attr_group;

static dev_t dev_ir = 0;
static struct cdev *ir_cdev     = NULL;
static struct class *irrp_class;
struct ir_dev *ir_devices;      /* allocated in scull_init_module */
DEFINE_SPINLOCK(ir_lock);


struct IRDA_PROTOCOL irda_proto_list[IRDA_PROTO_LIST_SIZE] = {
        {0, ""},
        {1, "NEC"},
        {2, "RC5"},
        {3, "SHARP"},
        {4, "SONY"},
        {5, "C03"},
        {6, "RC6"},
        {7, "RAW_NEC"},
        {8, "RCA"},
        {9, "PANASONIC"},
        {10, "KONKA"},
        {11, "RAW_RC6"},
        {12, "TSB"},
        {13, "RAW_TSB"},
        {14, "RAW_RCA"},
        {15, "RAW_C03"},
        {16, "RAW_KONKA"},
        {17, "RAW_SONY"},
        {18, "AEHA"},
};

static unsigned int driver_mode = SINGLE_WORD_IF;


#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
void voice_dev_init(void);
static void voice_dev_int_isr(RTK_GPIO_ID gid, unsigned char assert, void *dev);
void voice_dev_uninit(void);
#endif
#endif

