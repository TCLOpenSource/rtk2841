#ifndef __IRRC_RAW_H
#define  __IRRC_RAW_H

#include <linux/kfifo.h>
#include <rbus/misc_off_irda_reg.h>
#include "ir_debug.h"
#include "irrc_reg.h"

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
#include "ir_input.h"
#endif

#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE) || defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) || defined(CONFIG_RTK_KDRV_TV035_IR)
extern struct delayed_work ir_work;
extern struct kfifo ir_fifo_raw;
static int raw_bit_anchor;
static unsigned long raw_bit_sample;
static int symbol = 0;
extern int first_fifo;
struct irrplen {
        u32 bit_num;
        u32 burst_len;
        u32 silence_len;
        u32 mod_len;
        u32 zero_len;
        u32 one_len;
        u32 stop_len;
        u32 fifo_len;
};
extern struct irrplen ir_len[2];
#define LEN_RANGE(cur_len, def_len)                     (cur_len >= (def_len-2) && cur_len <= (def_len+2))
#define LEAD_RANGE(high_len, low_len, idx)              (LEN_RANGE(high_len, ir_len[idx].burst_len) && LEN_RANGE(low_len, ir_len[idx].silence_len))
#define BIT_RANGE(low_len, zero_len, one_len)   (low_len >= (zero_len-2) && low_len <= (one_len+2))

#endif

extern wait_queue_head_t ir_read_wait;
extern struct kfifo ir_fifo;
extern unsigned int lastRecvMs;
extern uint32_t lastSrValue;
extern unsigned int ir_repeat_interval;

#if defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) || defined(CONFIG_RTK_KDRV_TV035_IR)
static u32 shuttle_keycode = 0;
static u32 shuttle_received = 0;
#endif

int raw_nec_decoder(int *dataRepeat);
uint32_t raw_tsb_decoder(int *dataRepeat);
uint32_t raw_rc6_decoder(int *dataRepeat);
#ifdef CONFIG_RTK_KDRV_TV002_IR_RAW_MODE
int raw_sony_decoder(int *dataRepeat);
#endif

#ifdef CONFIG_RTK_KDRV_TV005_MOUSE
void ir_dsr_nec_decode(void);
#endif
#ifdef CONFIG_RTK_KDRV_TV030_MOUSE
void ir_dsr_rca_decode(void);
#endif
#ifdef CONFIG_RTK_KDRV_YK_54LU_SHUTTLE
void ir_dsr_sky_decode(void);
#endif
#ifdef CONFIG_RTK_KDRV_TV035_IR
void ir_dsr_konka_decode(void);
#endif

void IR_raw_fifo_decode(u32 isr_fifo, u32 fifo_depth);

#endif
