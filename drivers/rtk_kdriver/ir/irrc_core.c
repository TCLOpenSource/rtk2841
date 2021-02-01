//#include <linux/config.h>
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
#include <linux/atomic.h>
#include "irrc_core.h"
#include "irrc_raw.h"
#include "irrc_record.h"

#define IRRC_IRRP_FLUSH() \
    do {                    \
        while(rtd_inl(REG_IR_SR) & 0x1) {   \
        rtd_outl(REG_IR_SR, 0x00000003);    \
        rtd_inl(REG_IR_RP);      \
    }                                       \
    rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | BIT(IRDA_IR_CR_irrp_clr_shift)); \
    }while(0)

 #define IRRC_RAW_FIFO_FLUSH() \
    do {                    \
        unsigned int i = 0;         \
        unsigned int raw_fifo_level = rtd_inl(REG_IR_RAW_CTRL) & 0x7F;   \
        for(i = 0; i < raw_fifo_level; i++)   \
            rtd_inl(REG_IR_RAW_FF);   \
        rtd_outl(REG_IR_RAW_CTRL, 0x01000008);   \
    }while(0)        

struct IRDA_PROTOCOL irda_proto_list[IRDA_PROTO_LIST_SIZE] = {
    {0, 0, "", "IR_none"},
    {1, NEC, "NEC", "IR_nec"},
    {2, RC5, "RC5", "IR_rc5"},
    {3, SHARP, "SHARP", "IR_sharp"},
    {4, SONY, "SONY", "IR_sony"},
    {5, C03, "C03", "IR_c03"},
    {6, RC6, "RC6", "IR_rc6"},
    {7, NEC, "RAW_NEC", "IR_nec"},
    {8, RCA, "RCA", "IR_rca"},
    {9, PANASONIC, "PANASONIC", "IR_panasonic"},
    {10, KONKA, "KONKA", "IR_konka"},
    {11, RC6, "RAW_RC6", "IR_rc6"},
    {12, TSB, "TSB", "IR_toshiba"},
    {13, TSB, "RAW_TSB", "IR_toshiba"},
    {14, RCA, "RAW_RCA", "IR_rca"},
    {15, C03, "RAW_C03", "IR_c03"},
    {16, KONKA, "RAW_KONKA", "IR_konka"},
    {17, SONY, "RAW_SONY", "IR_sony"},
    {18, AEHA, "AEHA", "IR_aeha"},
    {19, NEC, "TCL_NEC", "IR_tclnec"},
};
#ifdef CONFIG_QUICK_HIBERNATION
extern int in_suspend;
#endif
static unsigned int driver_mode = SINGLE_WORD_IF;
/*
*main1decode for ir_support_protocols[0],main0decode for ir_support_protocols[1]
*/
int ir_support_protocols[MAX_HW_RTK_KDRV_PROTOCOLS_NUM] = {IR_PROTOCOL, 0};
int ir_protocol = IR_PROTOCOL;
eirda_keymap_type ir_keymap_type = IRDA_KEYMAP_TYPE_NEC;
int ir_boot_sel_protocol = 0;
unsigned char ir_boot_remoter[32] = {0};

static atomic_t ir_suspended = ATOMIC_INIT(0);
uint32_t ir_disable_irda_decode_key  = 0;

unsigned int ir_repeat_interval = REPEAT_INTERVAL;
unsigned int debounce = 100;
unsigned int lastRecvMs;
uint32_t lastSrValue = 0;
bool ir_decode_dbg_en = false;
DECLARE_WAIT_QUEUE_HEAD(ir_read_wait);
DEFINE_SPINLOCK(ir_lock);

#ifdef CONFIG_DELAY_FIRST_REPEAT
static unsigned int PressRecvMs;
unsigned int firstRepeatInterval = 300; // default disable first repeat delay
static unsigned int firstRepeatTriggered = false;
#endif

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
unsigned int repeat_event = 0;
unsigned int rawkey_event = 0;
#endif

struct kfifo ir_fifo;
#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE) || defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) || defined(CONFIG_RTK_KDRV_TV035_IR)
struct delayed_work ir_work;
struct kfifo ir_fifo_raw;
int first_fifo = 0;
struct irrplen ir_len[2];
#endif

module_param(ir_protocol, int, S_IRUGO);

/* Module Functions */
static int examine_ir_avail(uint32_t *regValue, uint32_t *irrp2Value, int *dataRepeat)
{
    uint8_t data_bits_len = 0;
    uint32_t srValue = rtd_inl(REG_IR_SR);

    *irrp2Value = 0;

    IR_DBG("[%s]REG_IR_SR = [%08X]\n", __func__, srValue);
    if(srValue & BIT(9))
        ir_protocol = ir_support_protocols[0];
    else
        ir_protocol = ir_support_protocols[1];
    IR_DBG("[%s]The ir_protocol is %08x from main%d\n",
           __FUNCTION__, ir_protocol, !!(srValue & BIT(9)));

    if((srValue & 0x10) && ((srValue & BIT(9)) || ir_protocol != RAW_C03)) {
        rtd_outl(REG_IR_SR, 0x00000013);
        return -ERESTARTSYS;
    } else if(srValue & 0x20) {
        rtd_outl(REG_IR_SR, 0x00000023);
        return -ERESTARTSYS;
    } else if(srValue & 0x1) {
        if(srValue & 0x2)
            *dataRepeat = 1;
        else
            *dataRepeat = 0;

        rtd_outl(REG_IR_SR, 0x00000003); /* clear IRDVF */

        if(ir_protocol == AEHA) { /* AEHA has 24/32/48 bits len*/
            data_bits_len = (rtd_inl(REG_IR_CR_RC5_RC6) >> 24) & 0x3F;
            IR_DBG("[%s]AEHA data_bits_len = [%d]\n", __func__, data_bits_len);
            if((data_bits_len != 24) && (data_bits_len != 32)
               && (data_bits_len != 48)) {

                return -ERESTARTSYS;
            }
            if(data_bits_len == 48)
                *irrp2Value = rtd_inl(REG_IR_RP2);
        }

        if(ir_protocol == PANASONIC) {
            *irrp2Value = rtd_inl(REG_IR_RP2); /* read IRRP2 */
        }
        *regValue = rtd_inl(REG_IR_RP); /* read IRRP */

        if(ir_protocol == PANASONIC && (srValue & BIT(9))) {
            *regValue = *regValue | (*irrp2Value >> 16);
            *irrp2Value = (*irrp2Value << 16);
        }
#ifdef CONFIG_RTK_KDRV_TV030_MOUSE
        if(ir_protocol == RAW_RCA && (srValue & BIT(9))) {
            *regValue = ~(*regValue) & 0x00FFFFFF;
        }
#endif
        IR_DBG("[%s]REG_IR_RP = [%08X]\n", __func__, *regValue);
        if(ir_protocol == PANASONIC) {
            IR_DBG("[%s]REG_IR_RP2 = [%08X]\n", __func__, *irrp2Value);
        }
        if((ir_protocol == AEHA) && (data_bits_len == 48)) {
            IR_DBG("[%s]reg_ir_rp2 = [%08X]\n", __func__, *irrp2Value);
        }

        if(ir_protocol == RC6) {
            if((lastSrValue & 0xffff) == (*regValue & 0xffff)) {
                *dataRepeat = 1;
                debounce = 0;
            } else
                *dataRepeat = 0;
            lastSrValue = *regValue;
        } else if(ir_protocol == RCA) {
            if(lastSrValue == *regValue) {
                *dataRepeat = 1;
                debounce = 0; /* for first repeat interval*/
            } else
                *dataRepeat = 0;
            lastSrValue = *regValue;
        } else if((srValue & BIT(9)) == 0 && ir_protocol == RAW_C03 && (*regValue & 0xffff) != 0xf1f1) {
            return -ERESTARTSYS;
        } else if(ir_protocol == SONY) {
            if((lastSrValue & 0xfffff) == (*regValue & 0xfffff)) {
                *dataRepeat = 1;
                debounce = 0;
            } else
                *dataRepeat = 0;
            lastSrValue = *regValue;
        }

        return 0;
    } else
        return -ERESTARTSYS;
}

static int repeat_key_handle(uint32_t regValue, uint32_t irrp2Value, int dataRepeat)
{
    int received = 0;

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    u32 keycode = 0;
    keycode = venus_ir_scancode_to_keycode(regValue);
#endif

    if(dataRepeat == 1 && (jiffies_to_msecs(jiffies) - lastRecvMs) < debounce) {
        IR_DBG(" %dms, ignored..\n", (jiffies_to_msecs(jiffies) - lastRecvMs));
        lastRecvMs = jiffies_to_msecs(jiffies);
    }
#ifdef CONFIG_DELAY_FIRST_REPEAT
    else if(dataRepeat == 1 && firstRepeatInterval > 0 && firstRepeatTriggered == false && (jiffies_to_msecs(jiffies) - PressRecvMs) < firstRepeatInterval) {
        IR_DBG(" %dms, ignored for first repeat interval..\n", (jiffies_to_msecs(jiffies) - PressRecvMs));
        lastRecvMs = jiffies_to_msecs(jiffies);
    }
#endif
    else if(ir_protocol == NEC && dataRepeat == 1 && (jiffies_to_msecs(jiffies) - lastRecvMs) > REPEAT_MAX_INTERVAL) {
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | BIT(IRDA_IR_CR_irrp_clr_shift));
        IR_DBG("Venus IR: Repeat Symbol after %dms, ignored..\n", jiffies_to_msecs(jiffies) - lastRecvMs);
    } else if(ir_protocol == RAW_C03 && dataRepeat == 1 && (jiffies_to_msecs(jiffies) - lastRecvMs) > REPEAT_MAX_INTERVAL) {
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | BIT(IRDA_IR_CR_irrp_clr_shift));
        IR_DBG("Venus IR: Repeat Symbol after %dms, ignored..\n", jiffies_to_msecs(jiffies) - lastRecvMs);
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        schedule_venus_ir_keyup_handler();
#endif
    } else if(ir_protocol == KONKA && dataRepeat == 0 && (jiffies_to_msecs(jiffies) - lastRecvMs) < ir_repeat_interval) {
        IR_DBG(" Repeat Symbol after %dms, ignored..\n", (jiffies_to_msecs(jiffies) - lastRecvMs));
    }

    else if(dataRepeat == 1 && (jiffies_to_msecs(jiffies) - lastRecvMs) < ir_repeat_interval) {
        IR_DBG(" Repeat Symbol after %dms, ignored..\n", (jiffies_to_msecs(jiffies) - lastRecvMs));
    } else {
        IR_DBG(" Non-repeated frame [%dms]\n", (jiffies_to_msecs(jiffies) - lastRecvMs));
        IR_DBG(" IRRP = [%08X].\n", regValue);
        lastRecvMs = jiffies_to_msecs(jiffies);
        if(ir_protocol == RC6) {
            regValue = ~(regValue) & 0x1fffff; // 21 bits
            IR_DBG(" IRRP = [%08X].\n", regValue);
        } else if(ir_protocol == RC5)
            regValue = (regValue & 0xfff);

        if(ir_protocol == PANASONIC && irrp2Value != 0x20020000) {
            IR_DBG(" Maker code = [%08X].\n", irrp2Value);
        } else {

            kfifo_in(&ir_fifo, (unsigned char *)&regValue, sizeof(uint32_t));
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
            venus_ir_input_report_key(dataRepeat);

            if(!ir_poll_enable) {
                venus_ir_input_report_end(0);
            } else {
                schedule_venus_ir_keyup_handler();
            }
#endif
            if(ir_protocol == AEHA) {
                kfifo_in(&ir_fifo, (unsigned char *)&irrp2Value, sizeof(int32_t));
            }

            if(driver_mode == DOUBLE_WORD_IF)
                kfifo_in(&ir_fifo, (unsigned char *)&dataRepeat, sizeof(int32_t));

#ifdef CONFIG_DELAY_FIRST_REPEAT
            if(dataRepeat == 1)
                firstRepeatTriggered = true;
            else {
                PressRecvMs = lastRecvMs;
                firstRepeatTriggered = false;
            }
#endif

            received = 1;
        }
    }

    return received;
}

static void IR_hw_decode_handler(void)
{
    int received = 0;
    int dataRepeat = 0;
    uint32_t regValue;
    uint32_t irrp2Value = 0x0;

    while(examine_ir_avail(&regValue, &irrp2Value, &dataRepeat) == 0) {
        received = repeat_key_handle(regValue, irrp2Value, dataRepeat);
    }

    if(received == 1) {
        wake_up_interruptible(&ir_read_wait);
#if defined(CONFIG_RTK_KDRV_HAIER_IR)
        venus_ir_led_flash_start();
#endif
    }
}

#ifdef CONFIG_RTK_KDRV_RAW_MODE
static irqreturn_t IR_raw_decode_handler(void)
{
    int received = 0;
    int dataRepeat = 0;
    uint32_t regValue;
    uint32_t irrp2Value = 0x0;


    switch(ir_support_protocols[0]) {
    case RAW_NEC:
        ir_protocol = ir_support_protocols[0];
#ifdef CONFIG_RTK_KDRV_TV005_MOUSE
        IR_raw_fifo_decode(16, ir_len[1].fifo_len);
#else
        regValue = raw_nec_decoder(&dataRepeat);
        if(regValue == 0) {
            return IRQ_HANDLED;
        }
        received = repeat_key_handle(regValue, irrp2Value, dataRepeat);
#endif
        break;
    case RAW_RC6:
        regValue = raw_rc6_decoder(&dataRepeat);
        if(regValue == 0x8000) {
            return IRQ_HANDLED;
        }
        received = repeat_key_handle(regValue, irrp2Value, dataRepeat);
        break;
    case RAW_TSB:
        regValue = raw_tsb_decoder(&dataRepeat);
        if(regValue == 0x8000) {
            return IRQ_HANDLED;
        }
        received = repeat_key_handle(regValue, irrp2Value, dataRepeat);
        break;
#ifdef CONFIG_RTK_KDRV_TV002_IR_RAW_MODE
    case RAW_SONY:
        ir_protocol = ir_support_protocols[0];
        regValue = raw_sony_decoder(&dataRepeat);
        if(regValue == 0) {
            return IRQ_HANDLED;
        }
        received = repeat_key_handle(regValue, irrp2Value, dataRepeat);
        break;
#endif
#ifdef CONFIG_RTK_KDRV_YK_54LU_SHUTTLE
    case RAW_C03:
        IR_raw_fifo_decode(16, 64);
        break;
#endif
#ifdef CONFIG_RTK_KDRV_TV035_IR
    case RAW_KONKA:
        IR_raw_fifo_decode(16, ir_len[0].fifo_len);
        break;
#endif
#ifdef  CONFIG_RTK_KDRV_TV030_MOUSE
    case RAW_RCA:
        IR_raw_fifo_decode(16, 128);
        break;
#endif
#ifdef CONFIG_RTK_KDRV_RECORD_KEY
    case RAW_RECORDER:
        IR_raw_record_decode();
        break;
#endif
    default:
        IR_WARNING(" the ir protocol isn't support%d\n", ir_support_protocols[0]);
    }
    if(received == 1) {
        wake_up_interruptible(&ir_read_wait);
#if defined(CONFIG_RTK_KDRV_HAIER_IR)
        venus_ir_led_flash_start();
#endif
    }

    return IRQ_HANDLED;
}
#endif

#ifdef CONFIG_RTK_KDRV_RAW_MODE
static void ir_dsr(struct work_struct * work)
{
    switch(ir_support_protocols[0]) {
    case RAW_NEC:
#ifdef CONFIG_RTK_KDRV_TV005_MOUSE
        ir_dsr_nec_decode();
#endif
        break;
#ifdef CONFIG_RTK_KDRV_YK_54LU_SHUTTLE
    case RAW_C03:
        ir_dsr_sky_decode();
        break;
#endif
#ifdef CONFIG_RTK_KDRV_TV035_IR
    case RAW_KONKA:
        ir_dsr_konka_decode();
        break;
#endif
#ifdef  CONFIG_RTK_KDRV_TV030_MOUSE
    case RAW_RCA:
        ir_dsr_rca_decode();
        break;
#endif
    default:
        IR_WARNING(" the ir protocol[%d] isn't handled\n", ir_support_protocols[0]);
    }
}
#endif

int ir_hw_decode_check_enable(void)
{
    if((rtd_inl(REG_IR_CR) & REG_IR_CR_MAIN0_EN_MASK) || (rtd_inl(REG_IR_CR_RC5_RC6) & REG_IR_CR_MAIN1_EN_MASK)) {
        return 1;
    }

    return 0;
}

int ir_hw_decode_int_status(void)
{
    return rtd_inl(REG_ISR) & BIT(REG_ISR_IR_IN_SHIFT);
}

int ir_raw_decode_int_status(void)
{
    return rtd_inl(REG_OFF_ISR) & BIT(REG_OFF_ISR_IR_IN_SHIFT);
}

static irqreturn_t IR_interrupt_handler(int irq, void *dev_id)
{
    /* HW mode interrupt */
    if(ir_hw_decode_int_status() && ir_hw_decode_check_enable()) {
        IR_DBG("(HW)Interrupt Handler Triggered.\n");
        if(unlikely(ir_disable_irda_decode_key) || unlikely(pm_freezing))
            IRRC_IRRP_FLUSH();
        else
            IR_hw_decode_handler();

        return IRQ_HANDLED;
    }
#ifdef CONFIG_RTK_KDRV_RAW_MODE
    /* RAW mode interrupt */
    else if(ir_raw_decode_int_status()) {
        IR_DBG("(RAW)Interrupt Handler Triggered.\n");
        /* Clear interrupt */
        rtd_setbits(REG_IR_RAW_SR, BIT(REG_IR_RAW_SR_FIFO_VAL_SHIFT) | BIT(REG_IR_RAW_SR_FIFO_OV_SHIFT));

        if(unlikely(ir_disable_irda_decode_key) || unlikely(pm_freezing)) {
            IRRC_RAW_FIFO_FLUSH();
            return IRQ_HANDLED;
        } else {
            return IR_raw_decode_handler();
        }
    }
#endif
    else {
        return IRQ_NONE;
    }
}


int IR_protocol_setting(int main1_protocol, int main0_protocol)
{

    /* Irda Main1 hw setting */
    switch(main1_protocol) {
    case NEC:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x4E13133B);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x014e1327);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0xFFFFFFFF);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0xFFFFFFFF);
        rtd_outl(REG_IR_SF, 0x0000021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00a00090);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00004a41);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        ir_poll_interval = 150;
        ir_repeat_interval = 0;
#endif
        debounce = 0;
        break;
    case PANASONIC:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x24150E32);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x01000010);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0X30201550);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0X000000FF);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00e00900);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00000a61);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case SHARP:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x000c173f);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x01000000);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x00203070);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x00000000);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x007003ff);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x0000081f);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case SONY:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x18181830);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x01000006);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x20202850);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x000000ff);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x005003ff);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00001b19);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        debounce = 0;
        break;
    case C03:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x25103410);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x00252525);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x40306020);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x4040B4ff);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00a003ff);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00004a41);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case TSB:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x4E13133B);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x014e1327);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x80302060);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x802500ff);
        rtd_outl(REG_IR_SF, (rtd_inl(REG_IR_SF) & 0xFFFF0000) | 0x021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00a003ff);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00004a41);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case RC5:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x00242424);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x01000000);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x00303030);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x00000000);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00d00d00);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x0000051b);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case RC6:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x1a100e0e);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x02000008);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x30303030);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x000000ff);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00d00d00);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x0000a7a9);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case KONKA:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x1e143c64);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x0300001a);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x2d1e5a96);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x0000002D);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x0076030c);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00000b21);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case RCA://TCL REMOTE Control
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x25102147);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x01000025);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x3c223C78);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x000000ff);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x006100fa);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00000b31);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
#ifdef CONFIG_RTK_KDRV_TV030_IR
        ir_poll_interval = 90;
        ir_repeat_interval = 0;
	ir_keymap_type = IRDA_KEYMAP_TYPE_TV030;
#endif
        break;
    case AEHA:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x2214143c);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x01221111);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0xFFFFFFFF);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0xFFFF4BFF);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x000003ff);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x804B7F);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        break;
    case TCL_NEC:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x4E13133B);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x014e1327);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0xFFFFFFFF);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0xFFFFFFFF);
        rtd_outl(REG_IR_SF, 0x0000021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00a00090);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00004a41);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        ir_poll_interval = 200;
        ir_repeat_interval = 0;
	ir_keymap_type = IRDA_KEYMAP_TYPE_TV030_NEC;
#endif
        debounce = 0;
        break;
    case RAW_NEC:
        rtd_outl(REG_IR_RAW_SF, 0x1517);       // use 5000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x0a8b);  // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
#ifdef CONFIG_RTK_KDRV_TV005_MOUSE
        ir_len[0].bit_num = 32;
        ir_len[0].burst_len = 40;
        ir_len[0].silence_len = 20;
        ir_len[0].mod_len = 3;
        ir_len[0].zero_len = 3;
        ir_len[0].one_len = 8;
        ir_len[0].stop_len = 190;
        ir_len[0].fifo_len = 128;
        ir_len[1].stop_len = 25;
        ir_len[1].fifo_len = 64;
#endif
        debounce = 0;
        break;
    case RAW_RC6:
    case RAW_TSB: /* for TSB spec, not NEC protocol */
        rtd_outl(REG_IR_RAW_SF, 0xa8b);                 // use 10000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x545);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x03138808);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        debounce = 0;
        break;
#ifdef  CONFIG_RTK_KDRV_TV030_MOUSE
    case RAW_RCA:
        rtd_outl(REG_IR_RAW_SF, 0xa8b);                 // use 10000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x545);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        ir_len[0].bit_num = 24;
        ir_len[0].burst_len = 40;
        ir_len[0].silence_len = 40;
        ir_len[0].mod_len = 5;
        ir_len[0].zero_len = 10;
        ir_len[0].one_len = 20;
        ir_len[0].stop_len = 80;
        ir_len[0].fifo_len = 96;
        ir_len[1].bit_num = 24;
        ir_len[1].burst_len = 18;
        ir_len[1].silence_len = 18;
        ir_len[1].mod_len = 3;
        ir_len[1].zero_len = 6;
        ir_len[1].one_len = 3;
        ir_len[1].stop_len = 33;
        ir_len[1].fifo_len = 32;
        debounce = 0;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_YK_54LU_SHUTTLE
    case RAW_C03:
        rtd_outl(REG_IR_PSR_RC5_RC6, 0x25103410);
        rtd_outl(REG_IR_PER_RC5_RC6, 0x00252525);
        rtd_outl(REG_IR_PSR_UP_RC5_RC6, 0x40306020);
        rtd_outl(REG_IR_PER_UP_RC5_RC6, 0x404000ff);
        rtd_outl(REG_IR_SF, 0xFFFF021B);
        rtd_outl(REG_IR_DPIR_RC5_RC6, 0x00a003ff);
        rtd_outl(REG_IR_CR_RC5_RC6, 0x00004a41);
        rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | (1 << 10));  /*HW decode int en*/
        rtd_outl(REG_IR_RAW_SF, 0x1517);       // use 5000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x0a8b);  // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        ir_len[1].bit_num = 8;
        ir_len[1].burst_len = 12;
        ir_len[1].silence_len = 6;
        ir_len[1].mod_len = 3;
        ir_len[1].zero_len = 3;
        ir_len[1].one_len = 8;
        ir_len[1].stop_len = 10;
        ir_len[1].fifo_len = 16;
        ir_repeat_interval = 200;
        debounce = 0;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_TV035_IR
    case RAW_KONKA:
        rtd_outl(REG_IR_RAW_SF, 0x1517);       // use 5000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x0a8b);  // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        ir_len[0].bit_num = 17;
        ir_len[0].burst_len = 15;
        ir_len[0].silence_len = 15;
        ir_len[0].mod_len = 3;
        ir_len[0].zero_len = 8;
        ir_len[0].one_len = 13;
        ir_len[0].stop_len = 55;
        ir_len[0].fifo_len = 48;
        debounce = 0;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_TV002_IR_RAW_MODE
    case RAW_SONY:
        rtd_outl(REG_IR_RAW_SF, 0xa8b);                 // use 10000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x545);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        ir_poll_interval = 55;
#endif
        ir_repeat_interval = 0;
        debounce = 0;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_RECORD_KEY
    case RAW_RECORDER:
        rtd_outl(REG_IR_RAW_SF, PLL_RBUS_FRQ / RECORD_RAW_MODE_FREQ - 1);               // use 20000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, (PLL_RBUS_FRQ / RECORD_RAW_MODE_FREQ - 1) / 2);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000020);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        break;
#endif
    default:
        IR_WARNING(" the ir protocol[%d] isn't support for main1 initial\n", main1_protocol);
    }

    /* Irda Main0 hw setting */
    switch(main0_protocol) {
    case NEC:
        rtd_outl(REG_IR_PSR, 0x5a13133b);
        rtd_outl(REG_IR_PER, 0x0001162d);
        rtd_outl(REG_IR_SF, 0xff00021b);        // 50KHz
        rtd_outl(REG_IR_DPIR, 0x1f4); // 10ms
        rtd_outl(REG_IR_CR, 0x5df);
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        ir_poll_interval = 130;
        ir_repeat_interval = 0;
#endif
        debounce = 0;
        break;
    case RC5:
        rtd_outl(REG_IR_PSR, 0x00242424);
        rtd_outl(REG_IR_PER, 0x00010000);
        rtd_outl(REG_IR_SF, 0x21b);
        rtd_outl(REG_IR_DPIR, 0x3ff);
        rtd_outl(REG_IR_CR, 0x70c);
        break;
    case SHARP:
        rtd_outl(REG_IR_PSR, 0x000B1750);
        rtd_outl(REG_IR_PER, 0x00010000);
        rtd_outl(REG_IR_SF, 0x0000021B);
        rtd_outl(REG_IR_DPIR, 0x000003FF);
        rtd_outl(REG_IR_CR, 0x0000048E);
        rtd_outl(REG_IR_PSR_UP, 0x0Dfffffff);
        rtd_outl(REG_IR_PER_UP, 0x0000ff28);
        rtd_outl(REG_IR_CR, 0x0000058E);
        break;
    case SONY:
        rtd_outl(REG_IR_CR, 0x80000000);
        rtd_outl(REG_IR_PSR, 0x170F1430);
        rtd_outl(REG_IR_PER, 0x00010004);
        rtd_outl(REG_IR_SF, 0x0000021B);
        rtd_outl(REG_IR_DPIR, 0x000003ff);
        rtd_outl(REG_IR_CR, 0x00000ECB);     // 20 bits
        rtd_outl(REG_IR_SR, 0x0008C000);     // second num 12 bits
        rtd_outl(REG_IR_PSR_UP, 0x5DFFFFFF);
        rtd_outl(REG_IR_PER_UP, 0x0000ff20);
        rtd_outl(REG_IR_CR, 0x00008FCB);
        //rtd_outl(REG_IR_CR, 0x00008DCB);  //data invert
        debounce = 0;
        break;
    case C03:
        rtd_outl(REG_IR_PSR, 0x25151034);
        rtd_outl(REG_IR_PER, 0x00000025);
        rtd_outl(REG_IR_CTRL_RC6, 0x200);
        rtd_outl(REG_IR_SF, 0xff00021b);
        rtd_outl(REG_IR_DPIR, 0x3ff);
        rtd_outl(REG_IR_CR, 0x5ff);
        break;
    case RC6:
        rtd_outl(REG_IR_PSR, 0x1c0e0e0e);
        rtd_outl(REG_IR_PER, 0x00030008);
        rtd_outl(REG_IR_SF, 0x21b);
        rtd_outl(REG_IR_DPIR, 0x3ff);
        rtd_outl(REG_IR_CR, 0x715); // valid bit length is 21
        rtd_outl(REG_IR_CTRL_RC6, 0x123);
        break;
    case RAW_NEC:
        rtd_outl(REG_IR_RAW_SF, 0x1517);       // use 5000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x0a8b);  // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
#ifdef CONFIG_RTK_KDRV_TV005_MOUSE
        ir_len[0].bit_num = 32;
        ir_len[0].burst_len = 40;
        ir_len[0].silence_len = 20;
        ir_len[0].mod_len = 3;
        ir_len[0].zero_len = 3;
        ir_len[0].one_len = 8;
        ir_len[0].stop_len = 190;
        ir_len[0].fifo_len = 128;
        ir_len[1].stop_len = 25;
        ir_len[1].fifo_len = 64;
#endif
        debounce = 0;
        break;
    case KONKA:
        rtd_outl(REG_IR_PSR, 0x1e143c64); //80% spec suggest value
        rtd_outl(REG_IR_PER, 0x0003001a);// 80% spec suggest value
        rtd_outl(REG_IR_SF, 0x21b); // 50KHZ
        rtd_outl(REG_IR_DPIR, 0x30c);   //80% spec suggest value  0x190
        rtd_outl(REG_IR_CR, 0x7cf);  //  bit6 need set 1,  16 bits
        break;
    case RCA://TCL REMOTE Control
        rtd_outl(REG_IR_PSR, 0x2f082a5a);
        rtd_outl(REG_IR_PER, 0x0001002a);
        rtd_outl(REG_IR_SF, 0xff00021b);
        rtd_outl(REG_IR_DPIR, 0x190); // 8ms
        rtd_outl(REG_IR_CR, 0x7d7);
        break;
    case PANASONIC:
        rtd_outl(REG_IR_PSR, 0x24120d30); // modulation length = 360us
        rtd_outl(REG_IR_PER, 0x00010010);
        rtd_outl(REG_IR_SF,     0x6767021b);  // idle time and command time 70ms
        rtd_outl(REG_IR_DPIR, 0xda9);   // 70ms
        rtd_outl(REG_IR_CR, 0x00af05c0);
        break;
    case RAW_RC6:
    case RAW_TSB: /* for TSB spec, not NEC protocol */
        rtd_outl(REG_IR_RAW_SF, 0xa8b);                 // use 10000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x545);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x03138808);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        debounce = 0;
        break;
    case TSB: /* for TSB spec */
        rtd_outl(REG_IR_PSR, 0x1c0f0f0f);
        rtd_outl(REG_IR_PER, 0x0001000f);
        rtd_outl(REG_IR_SF, 0xff00021b);   // 50KHz
        rtd_outl(REG_IR_DPIR, 0x3ff);
        rtd_outl(REG_IR_CR, 0x513);    // 20 bits
        break;
#ifdef  CONFIG_RTK_KDRV_TV030_MOUSE
    case RAW_RCA:
        rtd_outl(REG_IR_RAW_SF, 0xa8b);                 // use 10000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x545);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        ir_len[0].bit_num = 24;
        ir_len[0].burst_len = 40;
        ir_len[0].silence_len = 40;
        ir_len[0].mod_len = 5;
        ir_len[0].zero_len = 10;
        ir_len[0].one_len = 20;
        ir_len[0].stop_len = 80;
        ir_len[0].fifo_len = 96;
        ir_len[1].bit_num = 24;
        ir_len[1].burst_len = 18;
        ir_len[1].silence_len = 18;
        ir_len[1].mod_len = 3;
        ir_len[1].zero_len = 6;
        ir_len[1].one_len = 3;
        ir_len[1].stop_len = 33;
        ir_len[1].fifo_len = 32;
        debounce = 0;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_YK_54LU_SHUTTLE
    case RAW_C03:
        rtd_outl(REG_IR_PSR, 0x25151034);
        rtd_outl(REG_IR_PER, 0x00000025);
        rtd_outl(REG_IR_CTRL_RC6, 0x200);
        rtd_outl(REG_IR_SF, 0xff00021b);
        rtd_outl(REG_IR_DPIR, 0x3ff);
        rtd_outl(REG_IR_CR, 0x5ff);
        rtd_outl(REG_IR_RAW_SF, 0x1517);       // use 5000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x0a8b);  // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        ir_len[1].bit_num = 8;
        ir_len[1].burst_len = 12;
        ir_len[1].silence_len = 6;
        ir_len[1].mod_len = 3;
        ir_len[1].zero_len = 3;
        ir_len[1].one_len = 8;
        ir_len[1].stop_len = 10;
        ir_len[1].fifo_len = 16;
        debounce = 0;
        ir_repeat_interval = 200;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_TV035_IR
    case RAW_KONKA:
        rtd_outl(REG_IR_RAW_SF, 0x1517);       // use 5000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x0a8b);  // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        ir_len[0].bit_num = 17;
        ir_len[0].burst_len = 15;
        ir_len[0].silence_len = 15;
        ir_len[0].mod_len = 3;
        ir_len[0].zero_len = 8;
        ir_len[0].one_len = 13;
        ir_len[0].stop_len = 55;
        ir_len[0].fifo_len = 48;
        debounce = 0;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_TV002_IR_RAW_MODE
    case RAW_SONY:
        rtd_outl(REG_IR_RAW_SF, 0xa8b);                 // use 10000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, 0x545);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000010);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        ir_poll_interval = 55;
#endif
        ir_repeat_interval = 0;
        debounce = 0;
        break;
#endif
#ifdef CONFIG_RTK_KDRV_RECORD_KEY
    case RAW_RECORDER:
        rtd_outl(REG_IR_RAW_SF, PLL_RBUS_FRQ / RECORD_RAW_MODE_FREQ - 1);               // use 20000 Hz sampling rate
        rtd_outl(REG_IR_RAW_DEB, (PLL_RBUS_FRQ / RECORD_RAW_MODE_FREQ - 1) / 2);        // 2x over sampling for debounce
        rtd_outl(REG_IR_RAW_CTRL, 0x00000020);
        rtd_outl(REG_IR_RAW_CR, 0x7000); // enable raw mode
        break;
#endif
    default:
        IR_WARNING(" the ir protocol[%d] isn't support for main0 initial\n", main0_protocol);
    }

    return 0;
}

void ir_set_rx_detect_on_off(uint32_t on)
{
#ifdef CONFIG_IRDA_POWER_SAVING_MODE
    if(on == ON) {
        rtd_setbits(IRDA_HW_MODE_RX_DECTECT_REG, IRDA_HW_MODE_RX_DECTECT_ON);
        rtd_setbits(IRDA_RAW_MODE_RX_DECTECT_REG, IRDA_RAW_MODE_RX_DECTECT_ON);
    } else {
        rtd_clearbits(IRDA_HW_MODE_RX_DECTECT_REG, IRDA_HW_MODE_RX_DECTECT_ON);
        rtd_clearbits(IRDA_RAW_MODE_RX_DECTECT_REG, IRDA_RAW_MODE_RX_DECTECT_ON);
    }
#endif
}

void ir_global_int_on_off(bool hw_mode, bool on)
{
    if(on == ON) {
        if(hw_mode == HW_MODE)
            rtd_outl(INT_CTRL_SCPU_REG, BIT(INT_CTRL_SCPU_MISC_INT_EN_SHIFT) | BIT(INT_CTRL_SCPU_INT_EN_WRITE_DATA));
        else
            rtd_outl(INT_CTRL_SCPU_REG, BIT(INT_CTRL_SCPU_ISO_INT_EN_SHIFT) | BIT(INT_CTRL_SCPU_INT_EN_WRITE_DATA));
    } else {
        if(hw_mode == HW_MODE)
            rtd_outl(INT_CTRL_SCPU_REG, BIT(INT_CTRL_SCPU_MISC_INT_EN_SHIFT));
        else
            rtd_outl(INT_CTRL_SCPU_REG, BIT(INT_CTRL_SCPU_ISO_INT_EN_SHIFT));
    }
}

void ir_local_int_on_off(bool hw_mode, bool on)
{
    ir_set_rx_detect_on_off(OFF);
    if(on == ON) {
        if(hw_mode == HW_MODE)
            rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | BIT(REG_IR_CR_HW_INT_SHIFT)); /*enable HW decode interrupts*/
#ifdef CONFIG_RTK_KDRV_RAW_MODE
        else
            rtd_outl(REG_IR_RAW_CR, rtd_inl(REG_IR_RAW_CR) | BIT(REG_IR_CR_RAW_FIFO_OV_EN_SHIFT) | BIT(REG_IR_CR_RAW_FIFO_VAL_EN_SHIFT)); /*enable raw mode decode interrupts*/
#endif
    } else {
        if(hw_mode == HW_MODE)
            rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) & ~BIT(REG_IR_CR_HW_INT_SHIFT)); /*disable HW decode interrupts*/
#ifdef CONFIG_RTK_KDRV_RAW_MODE
        else
            rtd_outl(REG_IR_RAW_CR, rtd_inl(REG_IR_RAW_CR) & ~(BIT(REG_IR_CR_RAW_FIFO_OV_EN_SHIFT) | BIT(REG_IR_CR_RAW_FIFO_VAL_EN_SHIFT))); /*disable raw mode decode interrupts*/
#endif
    }
}

void ir_all_int_on_off(bool on)
{
    ir_global_int_on_off(HW_MODE, on);
    ir_global_int_on_off(RAW_MODE, on);
    ir_local_int_on_off(HW_MODE, on);
    ir_local_int_on_off(RAW_MODE, on);
}

void ir_hw_decode_on_off(bool main0, bool on)
{
    ir_set_rx_detect_on_off(OFF);
    if(on == ON) {
        if(main0 == MAIN0)
            rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) | REG_IR_CR_MAIN0_EN(ON)); /*enable main0 decode*/
        else
            rtd_outl(REG_IR_CR_RC5_RC6, rtd_inl(REG_IR_CR_RC5_RC6) | REG_IR_CR_MAIN1_EN(ON)); /*enable main1 decode*/
    } else {
        if(main0 == MAIN0)
            rtd_outl(REG_IR_CR, rtd_inl(REG_IR_CR) & ~REG_IR_CR_MAIN0_EN(ON)); /*disable main0 decode*/
        else
            rtd_outl(REG_IR_CR_RC5_RC6, rtd_inl(REG_IR_CR_RC5_RC6) & ~REG_IR_CR_MAIN1_EN(ON)); /*disable main1 decode*/
    }
}

void ir_raw_decode_on_off(bool on)
{
    ir_set_rx_detect_on_off(OFF);

    if(on == ON) {
        rtd_setbits(REG_IR_RAW_CR, BIT(REG_IR_CR_RAW_EN_SHIFT)); /*enable raw mode decode*/
    } else {
        rtd_clearbits(REG_IR_RAW_CR, BIT(REG_IR_CR_RAW_FIFO_OV_EN_SHIFT)); /*disable raw mode decode*/
    }
}

void ir_all_decode_on_off(bool on)
{
    ir_hw_decode_on_off(MAIN0, on);
    ir_hw_decode_on_off(MAIN1, on);
    ir_raw_decode_on_off(on);
}

void ir_decode_key_on_off(bool on) 
{
    ir_disable_irda_decode_key = ((on ==ON) ? 0 : 1);
    if(atomic_read(&ir_suspended) == 0) {
        IRRC_IRRP_FLUSH();
#ifdef CONFIG_RTK_KDRV_RAW_MODE
        IRRC_RAW_FIFO_FLUSH();
#endif
        ir_local_int_on_off(HW_MODE, on);
        ir_local_int_on_off(RAW_MODE, on);
    }
}


const char* ir_core_get_cur_remote_control_name(void)
{
    if(ir_boot_remoter[0] != 0)
        return ir_boot_remoter;
    else if((ir_protocol >= 0) && (ir_protocol < sizeof(irda_proto_list) /sizeof(irda_proto_list[0])))
        return irda_proto_list[ir_protocol].remote_control_name;
    else
        return irda_proto_list[0].remote_control_name;
    
}


/* *** ALL INITIALIZATION HERE *** */
int IR_Init(int main1_protocol, int main0_protocol, bool int_on)
{
    int retval = 0;

    if(main1_protocol > 0) {
        IR_INFO("!! switch ir protocol to %s for main1 !!\n", irda_proto_list[main1_protocol].proto_name);
    }
    if(main0_protocol > 0) {
        IR_INFO("!! switch ir protocol to %s for main0 !!\n", irda_proto_list[main0_protocol].proto_name);
    }

    lastRecvMs = jiffies_to_msecs(jiffies);

    /* Pin Mux */
    rtd_maskl(PINMUX_ST_ST_CFG_1_REG, ~PINMUX_ST_ST_CFG_1_IRRX_MASK, PINMUX_ST_ST_CFG_1_IRRX_DATA);

    /* Clock & Reset */
    CRT_CLK_OnOff(IrDA, CLK_ON, NULL);

    ir_set_rx_detect_on_off(OFF);

    /*Irda register settings*/
    IR_protocol_setting(main1_protocol, main0_protocol);

    if(int_on == ON) {
        /* Enable global interrupt */
        ir_global_int_on_off(HW_MODE, ON);
        ir_global_int_on_off(RAW_MODE, ON);
    } else {
        /* Disable interrupt */
        ir_all_int_on_off(OFF);
    }

    ir_set_rx_detect_on_off(ON);
    return retval;
}

int ir_suspend_protocol(void)
{
    /* Use main1 decode in suspend */
    IR_Init(irda_proto_list[ir_support_protocols[0]].proto_standby_id, 0, OFF);

    /* Disable HW/RAW decode */
    ir_all_decode_on_off(OFF);

    return 0;
}

int ir_core_pm_suspend(struct platform_device * dev, pm_message_t state)
{
    atomic_set(&ir_suspended, 1);

    ir_set_rx_detect_on_off(OFF);
#ifdef CONFIG_QUICK_HIBERNATION
    if(!in_suspend)
        IRRC_IRRP_FLUSH();
#else
    IRRC_IRRP_FLUSH();
#endif

    /* Disable ir interrupt */
    ir_all_int_on_off(OFF);

    return 0;
}

int ir_core_pm_resume(struct platform_device * dev)
{
    // reinitialize ir register
    IR_Init(ir_support_protocols[0], ir_support_protocols[1], ON);

#ifdef CONFIG_QUICK_HIBERNATION
    if (!in_suspend) {
#endif
        /* reinitialize kfifo */
        kfifo_reset(&ir_fifo);
#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE) || defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE)|| defined(CONFIG_RTK_KDRV_TV035_IR)
        kfifo_reset(&ir_fifo_raw);
        first_fifo = 0;
#endif
        ir_set_rx_detect_on_off(OFF);
        IRRC_IRRP_FLUSH();
        ir_set_rx_detect_on_off(ON);
#ifdef CONFIG_QUICK_HIBERNATION
    }
#endif

    atomic_set(&ir_suspended, 0);
    return 0;
}

int ir_core_open(struct inode * inode, struct file * filp)
{
    kfifo_reset(&ir_fifo);
#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE) || defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE)  || defined(CONFIG_RTK_KDRV_TV035_IR)
    kfifo_reset(&ir_fifo_raw);
#endif
    return 0;
}


ssize_t ir_core_read(struct file * filp, char __user * buf, size_t count, loff_t *f_pos)
{
    int uintBuf;
    int i, readCount = count;
    int len = 0;

restart:
    if(wait_event_interruptible(ir_read_wait, kfifo_len(&ir_fifo) > 0) != 0) {
        if(unlikely(current->flags & pm_freezing)) {
            try_to_freeze();
            goto restart;
        } else
            return -ERESTARTSYS;
    }

    spin_lock(&ir_lock);
    if(kfifo_len(&ir_fifo) < count)
        readCount = kfifo_len(&ir_fifo);

    for(i = 0 ; i < readCount ; i += 4) {
        len = kfifo_out(&ir_fifo, &uintBuf, sizeof(uint32_t));
        if(copy_to_user(buf, &uintBuf, 4))
            return -EFAULT;
        buf = buf + 4;
    }
    spin_unlock(&ir_lock);

    return readCount;
}

unsigned int ir_core_poll(struct file * filp, poll_table * wait)
{
    poll_wait(filp, &ir_read_wait, wait);
    if(kfifo_len(&ir_fifo) > 0)
        return POLLIN | POLLRDNORM;
    else
        return 0;
}

long ir_core_ioctl(struct file * file, unsigned int cmd, unsigned long arg)
{
    int retval = 0;
    spin_lock(&ir_lock);
    switch(cmd) {
    case IR_IOC_SET_IRPSR:
        rtd_outl(REG_IR_PSR, arg);
        break;
    case IR_IOC_SET_IRPER:
        rtd_outl(REG_IR_PER, arg);
        break;
    case IR_IOC_SET_IRSF:
        rtd_outl(REG_IR_SF, arg);
        break;
    case IR_IOC_SET_IRCR:
        rtd_outl(REG_IR_CR, arg);
        break;
    case IR_IOC_SET_IRIOTCDP:
        rtd_outl(REG_IR_DPIR, arg);
        break;
    case IR_IOC_SET_PROTOCOL:
    case IR_IOC_SET_MAIN0_PROTOCOL:
        if(cmd == IR_IOC_SET_PROTOCOL) {
            if(ir_boot_sel_protocol > 0)
                break;
            ir_support_protocols[0] = (int)arg;
        } else {
            ir_support_protocols[1] = (int)arg;
        }
    case IR_IOC_FLUSH_IRRP:
        if((retval = IR_Init(ir_support_protocols[0], ir_support_protocols[1], ON)) == 0)
            kfifo_reset(&ir_fifo);
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        ir_boot_remoter[0] = 0;
        venus_ir_input_set_input_dev_name(ir_core_get_cur_remote_control_name());  
#endif       
        break;
    case IR_IOC_SET_DEBOUNCE:
        debounce = (unsigned int)arg;
        break;
    case IR_IOC_SET_FIRST_REPEAT_DELAY:
#ifdef CONFIG_DELAY_FIRST_REPEAT
        firstRepeatInterval = (unsigned int)arg;
#else
        retval = -EPERM;
#endif
        break;
    case IR_IOC_SET_DRIVER_MODE:
        if(((unsigned int)arg) >= 2)
            retval = -EFAULT;
        else {
            kfifo_reset(&ir_fifo);
            driver_mode = (unsigned int)arg;
        }
        break;
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    case IR_IOC_SET_IR_TO_MOUSE:
        if (((unsigned int)arg == 1) || ((unsigned int)arg == 0)) {
            ir_to_mouse = (unsigned int)arg;
            IR_WARNING("Venus IR: simulate IR as mouse %s\n", ir_to_mouse ? "ON" : "OFF");
        } else
            retval = -EINVAL;
        break;
#endif
    case IR_IOC_GET_PROTOCOL:
        if (copy_to_user((void __user *)arg, (void *)&ir_support_protocols[0], sizeof(ir_support_protocols[0]))) {
            retval = -EFAULT;
        }
        break;
    case IR_IOC_GET_MAIN0_PROTOCOL:
        if (copy_to_user((void __user *)arg, (void *)&ir_support_protocols[1], sizeof(ir_support_protocols[1]))) {
            retval = -EFAULT;
        }
        break;
    default:
        retval = -ENOIOCTLCMD;
    }
    spin_unlock(&ir_lock);

    return retval;
}



int __init ir_core_init(void)
{
    int result = 0;

    IR_DBG("%s\n", __func__);

#if defined(CONFIG_RTK_KDRV_HAIER_IR) //hardy20140228
    setup_timer(&led_flash_timer, venus_ir_led_flash_end, 0);
#endif
    if(kfifo_alloc(&ir_fifo, FIFO_DEPTH * sizeof(uint32_t), GFP_KERNEL)) {
        result = -ENOMEM;
        goto fail_alloc_hw_kfifo;
    }

#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE)|| defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) || defined(CONFIG_RTK_KDRV_TV035_IR)
    if(kfifo_alloc(&ir_fifo_raw, FIFO_DEPTH * FIFO_DEPTH * sizeof(uint32_t), GFP_KERNEL)) {
        result = -ENOMEM;
        goto fail_alloc_raw_kfifo;
    }

    INIT_DELAYED_WORK(&ir_work, ir_dsr);
#endif
    if(request_irq(IRQ_GET_KERNEL_IRQ_NUM(IRQ_CEC), IR_interrupt_handler,
                   IRQF_SHARED, "Venus_IR", IR_interrupt_handler)) {
        IR_WARNING("IR: cannot register IRQ %d\n", IRQ_GET_KERNEL_IRQ_NUM(IRQ_CEC));
        result = -EIO;
        goto fail_alloc_irq;
    }

    /* Hardware Registers Initialization */
    IR_Init(ir_support_protocols[0], ir_support_protocols[1], ON);

    return result;       /* succeed ! */

fail_alloc_irq:
#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE)|| defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) || defined(CONFIG_RTK_KDRV_TV035_IR)
    kfifo_free(&ir_fifo_raw);
fail_alloc_raw_kfifo:
#endif
    kfifo_free(&ir_fifo);
fail_alloc_hw_kfifo:
    return result;
}

void __exit ir_core_uninit(void)
{
    /* Reset Hardware Registers */
    CRT_CLK_OnOff(IrDA, CLK_OFF, NULL);

#ifdef CONFIG_RTK_KDRV_RECORD_KEY
    IR_record_key_fini();
#endif
    free_irq(IRQ_GET_KERNEL_IRQ_NUM(IRQ_CEC), IR_interrupt_handler);
    kfifo_free(&ir_fifo);
#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE) || defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE)  || defined(CONFIG_RTK_KDRV_TV035_IR)
    kfifo_free(&ir_fifo_raw);
    cancel_delayed_work_sync(&ir_work);
#endif
}

static int _ir_get_keymap(const char* remoter, eirda_keymap_type* type)
{
    if(NULL == remoter || NULL == type)
    {
        IR_ERR("input invalid paramters\n");
        return -1;
    }

    if(0==strcmp(remoter,"nec"))
        *type = IRDA_KEYMAP_TYPE_NEC;
    else if (0 == strcmp(remoter,"hikeen"))
        *type = IRDA_KEYMAP_TYPE_TV036_10D;
    else if (0 == strcmp(remoter,"sony"))
        *type = IRDA_KEYMAP_TYPE_TV002;
    else if (0 == strcmp(remoter,"rca"))
        *type = IRDA_KEYMAP_TYPE_TV030;
    else if (0 == strcmp(remoter,"tclnec"))
        *type = IRDA_KEYMAP_TYPE_TV030_NEC;
    else
    {
        IR_INFO("use irda keymap %s\n",remoter);
        *type = IRDA_KEYMAP_TYPE_NEC;
    }

    return 0;
}

int ir_proto_init(char *options)
{
    unsigned int boot_sel_proto = 0;
    unsigned char remoter[32] = {0};
    ir_boot_remoter[0] = 0;
    if(options == NULL)
        return 1;
        
    IR_INFO("boot select ir protocol:: %s\n", options);
    if (sscanf(options, "%d-%31s", &boot_sel_proto, remoter) < 1)
        return 1;

    _ir_get_keymap(remoter,&ir_keymap_type);

    IR_INFO("boot select ir protocol:: boot_sel_proto = %d, remoter = %s, keymap=%d\n",
                    boot_sel_proto, remoter,ir_keymap_type);
                    
    if(boot_sel_proto > 0) {
        ir_boot_sel_protocol = boot_sel_proto;
        ir_support_protocols[0] = boot_sel_proto;
        ir_protocol = boot_sel_proto;
        if(remoter[0] != 0  && remoter[0] != ' ')
            snprintf(ir_boot_remoter, 32, "IR_%s", remoter);
    }
    return 1;
}

early_param("irda", ir_proto_init);

