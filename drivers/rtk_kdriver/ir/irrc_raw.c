#include <mach/io.h>
#include "irrc_raw.h"

static int get_bit_cnt(int *bit_num, int *sample_cnt, unsigned long *sample, int polar)
{
    int bit_cnt = 0;

    if(polar != 0 && polar != 1)
        return -1;

    while(1) {
        if((*bit_num) == 0) {
            if(rtd_inl(REG_IR_RAW_WL) > 0) {
                (*sample_cnt)++;
                (*sample) = rtd_inl(REG_IR_RAW_FF);
                (*bit_num) = 32;
                continue;
            } else
                break;
        } else {
            if(test_bit((*bit_num) - 1, sample)) {
                if(polar == 1) {
                    (*bit_num)--;
                    bit_cnt++;
                } else
                    break;
            } else {
                if(polar == 0) {
                    (*bit_num)--;
                    bit_cnt++;
                } else
                    break;
            }
        }
    }

    return bit_cnt;
}

#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE) || defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) || defined(CONFIG_RTK_KDRV_TV035_IR)
static int get_fifo_bit_cnt(int *bit_num, int *sample_cnt, unsigned long *sample, int polar)
{
    int bit_cnt = 0;
    int len = 0;

    if(polar != 0 && polar != 1)
        return -1;

    while(1) {
        if((*bit_num) == 0) {
            if(kfifo_len(&ir_fifo_raw) > 0) {
                (*sample_cnt)++;
                len = kfifo_out(&ir_fifo_raw, sample, sizeof(uint32_t));
                (*bit_num) = 32;
                continue;
            } else {
                break;
            }
        } else {
            if(test_bit((*bit_num) - 1, sample)) {
                if(polar == 1) {
                    (*bit_num)--;
                    bit_cnt++;
                } else {
                    break;
                }
            } else {
                if(polar == 0) {
                    (*bit_num)--;
                    bit_cnt++;
                } else {
                    break;
                }
            }
        }
    }

    return bit_cnt;
}
#endif

static inline int get_next_raw_bit(int *bit_num, int *sample_cnt, unsigned long *sample)
{
    if((*bit_num) == 1) {
        if(rtd_inl(REG_IR_RAW_SAMPLE_TIME) > (*sample_cnt)) {
            (*sample_cnt)++;
            (*sample) = rtd_inl(REG_IR_RAW_FF);
            (*bit_num) = 32;

            return test_bit((*bit_num), sample);
        } else
            return -1;
    } else {
        (*bit_num)--;
        return test_bit((*bit_num), sample);
    }
}

// 5000 Hz NEC Protocol Decoder
int raw_nec_decoder(int *dataRepeat)
{
    int i;
    int raw_bit_anchor = 32;
    int raw_bit_sample_cnt = 1;
    unsigned long raw_bit_sample;
    int symbol = 0;
    int length_low, length_high;
    static unsigned long lastSymbol = 0;

    raw_bit_sample = rtd_inl(REG_IR_RAW_FF);

    // [decode] PREMBLE (High for 8ms / Low for 4ms)
    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(length_high >= 40 && length_low <= 12) {
        symbol = lastSymbol;
        goto get_symbol;
    } else if(length_high < 40 || length_low < 20) {
        goto sleep;
    } else

        for(i = 0 ; i < 32 ; i++) {
            int length_high, length_low;

            length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

#ifdef DEV_DEBUG
            //      IR_DBG(" 1 for %d and 0 for %d is detected.\n", length_high, length_low);
#endif

            if(length_high >= 2 && length_low >= 2) {
                if(length_low > 10) { // Repeat
                    *dataRepeat = 1;
                    symbol = lastSymbol;
                    break;
                } else if(length_low >= 7)
                    symbol |= (0x1 << i);
            } else {
                goto sleep;
            }
        }

get_symbol:
#ifdef DEV_DEBUG
    //IR_DBG("Mars IR: [%d = %08X] is detected.\n", symbol, symbol);
#endif
    if(lastSymbol == symbol) {
        *dataRepeat = 1;
    } else {
        *dataRepeat = 0;
        lastSymbol = symbol;
    }

sleep:
    // prepare to stop sampling ..
    rtd_outl(REG_IR_RAW_CTRL, 0x01000010);

    return symbol;
}

uint32_t raw_tsb_decoder(int *dataRepeat)
{
    int i, j;
    int raw_bit_anchor = 32;
    int raw_bit_sample_cnt = 1;
    unsigned long raw_bit_sample;
    int symbol = 0x8000;
    int length_low, length_high;
    int length_get = 0;
    static unsigned long lastSymbol = 0;
    unsigned char check_tsb_tail = 0;

    raw_bit_sample = rtd_inl(REG_IR_RAW_FF);

    // 1 bit == 0.1ms
    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if (!(length_high >= 23 && length_high <= 27 && length_low >= 3 && length_low <= 7)) {
        goto sleep;
    } else {
        int bit_value = 0;
        int delay_ct = 0;
        int length_warn = 0;
        length_high = 0;
        length_low = 0;
        symbol = 0;

        for (i = 0; i < 19; i++) { /* get symbol */
            delay_ct = 0;
            while (rtd_inl(REG_IR_RAW_WL) < 4 && delay_ct <= 12) {  /* Check HW water level(32 word) out of range */
                delay_ct ++;
            }
            if (rtd_inl(REG_IR_RAW_WL) >= 26) { /* Check HW water level(32 word) out of range */
                goto sleep;
            }
            if (length_high == 0 && length_low == 0) {  /* PreGet symbol : notice */
                if (length_get == 1)  {
                    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
                    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
                    bit_value = 1;
                } else {
                    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
                    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
                    bit_value = 0;
                }
            } else {
                if (length_high == 0) {
                    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
                    length_get = 1;
                    bit_value = 1;
                } else if(length_low == 0) {
                    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
                    length_get = 0;
                    bit_value = 0;
                }
            }
            if(length_high <= 3 || length_low <= 3) {
                length_warn++;
            }
            symbol |= (bit_value << i);

            if (length_high >= 8 && length_high <= 11) {
                length_high -= 5;
            } else if (length_high >= 12)
                goto get_symbol;
            else
                length_high = 0;

            if (length_low >= 8 && length_low <= 11) {
                length_low -= 5;
            } else if (length_low >= 12)
                goto get_symbol;
            else
                length_low = 0;
        }
        if(length_warn >= 4) {
            goto sleep;
        }
    }

get_symbol:
    check_tsb_tail = 1;
    for (j = 0; j < 2; j++) {
        raw_bit_sample = rtd_inl(REG_IR_RAW_FF);
        if(raw_bit_sample != 0xFFFFFFFF && raw_bit_sample != 0x0) {
            symbol = 0x8000;
            goto sleep;
        }
    }

    if(i < 18)  // symbol bits >=20
        goto sleep;

    if (symbol == lastSymbol) {
        *dataRepeat = 1;
    } else {
        *dataRepeat = 0;
        lastSymbol = symbol;
    }

    IR_DBG("====>  symbol=%x dataRepeat=%d\n", symbol, *dataRepeat);

sleep:
    if(check_tsb_tail == 0) {
        for (j = 0; j < 2; j++) {
            raw_bit_sample = rtd_inl(REG_IR_RAW_FF);
            if(raw_bit_sample != 0xFFFFFFFF && raw_bit_sample != 0x0) {
                symbol = 0x8000;
                goto sleep1;
            }
        }
    }

sleep1:
    // prepare to stop sampling ..
    rtd_outl(REG_IR_RAW_CTRL, 0x01000008);

    return symbol;
}

// 10000 Hz RC6 Protocol Decoder
uint32_t raw_rc6_decoder(int *dataRepeat)
{
    int i;
    int raw_bit_anchor = 32;
    int raw_bit_sample_cnt = 1;
    unsigned long raw_bit_sample;
    int symbol = 0x8000;
    int length_low, length_high;
    int length_get = 0;
    static unsigned long lastSymbol = 0;

    raw_bit_sample = rtd_inl(REG_IR_RAW_FF);

    // [decode] PREMBLE (High for 2.6ms / Low for 0.8ms)
    // 1 bit == 0.1ms
    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    /* check RC6 LS */
    if (!(length_high >= 26 && length_high <= 29 && length_low >= 8 && length_low <= 10)) {
        goto sleep;
    } else {
        int bit_value = 0;
        int delay_ct = 0;
        int length_warn = 0;
        length_high = 0;
        length_low = 0;
        symbol = 0;

        for (i = 0; i < 21; i++) { /* get symbol */
            delay_ct = 0;
            while (rtd_inl(REG_IR_RAW_WL) < 4 && delay_ct <= 12) {  /* Check HW water level(32 word) out of range */
                delay_ct ++;
            }
            if (rtd_inl(REG_IR_RAW_WL) >= 26) { /* Check HW water level(32 word) out of range */
                goto sleep;
            }
            if (length_high == 0 && length_low == 0) {  /* PreGet symbol : notice */
                if (length_get == 1)  { /* get high then low */
                    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
                    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
                    bit_value = 0;
                } else { /* get low then high */
                    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
                    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
                    bit_value = 1;
                }
            } else {
                if (length_high == 0) {  /* just get low (two high is successive then only get low) */
                    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
                    length_get = 1;
                    bit_value = 0;
                } else if(length_low == 0) { /* just get high (two low is successive then only get high) */
                    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
                    length_get = 0;
                    bit_value = 1;
                }
            }
            if(length_high <= 3 || length_low <= 3) {
                length_warn++;
            }
            /*                                      if(length_high <= 2 || length_low <= 2) { // Check if  length_high or length_low too low(check if sig bit is valid)
                                                                    goto sleep;
                                                    }*/
            if (i == 0) { /* bypass start bit */
                //symbol |= (0x1 << i);
            } else { /* assign symbol bit */
                symbol |= (bit_value << (19 - (i - 1)));
            }

            if (i == 4) { /* handle TR */
                if (length_high >= 11 && length_high <= 16)     {       /* Check if length_high continuous (valid range : 7~16 (100us unit)) */
                    length_high -= 8;
                } else if (length_high >= 17) /* Check if length_low continuous (valid range: 7~16 (100us unit)) */
                    goto get_symbol;
                else
                    length_high = 0;

                if (length_low >= 11 && length_low <= 16) {
                    length_low -= 8;
                } else if (length_low >= 17)
                    goto get_symbol;
                else
                    length_low = 0;
            } else {
                if (length_high >= 7 && length_high <= 16) { /* Check if length_high continuous(valid range : 7~16 (100us unit)) */
                    if (length_high >= 12 && length_low >= 7 )  /* convert length_high is continuous */
                        length_high -= 8;
                    else  /* Normal length_high is not continuous */
                        length_high -= 4;
                    /*bit_value=1;*/
                } else if (length_high >= 17) /*Check if length_low continuous(valid range: 7~16 (100us unit)) */
                    goto get_symbol;
                else
                    length_high = 0;

                if (length_low >= 7 && length_low <= 16) {
                    if(length_low >= 12 && length_high >= 7)
                        length_low -= 8;
                    else
                        length_low -= 4;
                    /*bit_value = 0;*/
                } else if (length_low >= 17)
                    goto get_symbol;
                else
                    length_low = 0;
            }
        }

        if(length_warn >= 4) {
            symbol = 0x8000;
            goto sleep;
        }

        if(i < 20) { // symbol bits >=20
            symbol = 0x8000;
            goto sleep;
        }

        length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
        length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
        if(length_low < 32) {
            symbol = 0x8000;
            goto sleep;
        }
    }

get_symbol:
    if (symbol == lastSymbol) {
        *dataRepeat = 1;
    } else {
        *dataRepeat = 0;
        lastSymbol = symbol;
    }

    IR_DBG("====>  symbol=%x dataRepeat=%d\n", symbol, *dataRepeat);
    if (((symbol & 0x0000ffff) == 0x000c) && (*dataRepeat == 1)) // power key don't response repeat
        goto sleep;

sleep:
    // prepare to stop sampling ..
    rtd_outl(REG_IR_RAW_CTRL, 0x01000008);

    return symbol;
}

#ifdef CONFIG_RTK_KDRV_TV002_IR_RAW_MODE

static unsigned long raw_bit_sample;
static int raw_bit_anchor = 32;
static int first_decode = 1;

int raw_sony_decoder(int *dataRepeat)
{
    int i;
    int raw_bit_sample_cnt = 1;
    int symbol = 0;
    int length_low, length_high;
    static unsigned long lastSymbol = 0;
    static unsigned int lastRecvTime = 0;
    static unsigned int conti_cnt = 0;
    static unsigned int status_low_cnt = 0;

    if(first_decode) {
        raw_bit_anchor = 32;
        raw_bit_sample = rtd_inl(REG_IR_RAW_FF);
    }
    //IR_DBG("raw_bit_sample=0x%08x.\n", raw_bit_sample);

    // [decode] PREMBLE (High for 2.4ms / Low for 0.6ms)
    // Guide Pulse Time spec (1.9ms ~2.7ms) 2.4ms (1.9~2.8)
    // Data Bit OFF Time (0.4~0.65ms)       0.6ms (0.3~0.7)
    // Data Bit ON Time "0" (0.5~0.75ms)    0.6ms (0.4~0.9)
    // Data Bit ON Time "1" (1.15~1.4ms)    1.2ms (1.1~1.6)

    length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    //IR_DBG("Mars IR Leading: 1 for [%d] and 0 for [%d] is detected.\n", length_high, length_low);

    //2.4ms ~ 0.6ms
    if((length_high >= 19) && (length_high <= 28) && (length_low >= 3) && (length_low <= 7)) {
        status_low_cnt = 0;

        for(i = 0 ; i < 20 ; i++) {
            int length_high, length_low;

            length_high = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

#ifdef DEV_DEBUG
            //IR_DBG("Mars IR BBB[%d]: H[%d],L[%d].\n", i, length_high, length_low);
#endif

            if(length_high >= 5) {
                if((length_high >= 11) && (length_high <= 16)) /* high 1.2ms : bit=1 */
                    symbol |= (0x1 << i);
                else if((length_high >= 5) && (length_high < 11)) /* high 0.6ms : bit=0 */
                    symbol &= (~(0x1 << i));
                else {
                    IR_DBG("+++goto sleep in decode error 1\n");
                    goto sleep;
                }
                if ((length_low > 30) && (i >= 11)) {
                    /* noice canceling is 3ms */
                    goto get_symbol;

                }
            } else {
                IR_DBG("+++goto sleep in decode error 2\n");
                goto sleep;
            }

        }
    } else {
        //IR_DBG("length_high = %d, length_low= %d, status_low_cnt %d\n", length_high,
        //                                                                                                                              length_low,
        //                                                                                                                              status_low_cnt);
        if (length_high == 0) {
            status_low_cnt ++;
        } else {
            goto sleep;
        }

        if (status_low_cnt > 2) {
            goto sleep;
        } else {
            return 0;
        }

    }


get_symbol:
    IR_DBG("Mars IR: [%d = 0x%08X] is detected.\n", symbol, symbol);
    if(lastSymbol == symbol) {
#ifndef CONFIG_RTK_KDRV_INPUT_DEVICE
        if ((jiffies_to_msecs(jiffies) - lastRecvTime) > 130) {
            lastSymbol = symbol;
            symbol = 0;
            conti_cnt = 0;
        } else {
            conti_cnt ++;

            if (conti_cnt == 1) {
                *dataRepeat = 0;
            }
            if (conti_cnt == 2) {
                symbol = 0;
            } else {
                *dataRepeat = 1;
            }
            //lastSymbol =0;
        }
#else
        *dataRepeat = 1;
#endif

        //IR_DBG("Valid Mars IR: [%d = 0x%08X] is detected. conti_cnt = [%d] dataRepeat =[%d] key interval = [%d]\n", symbol, symbol,conti_cnt,*dataRepeat, (jiffies_to_msecs(jiffies)- lastRecvTime));


    } else {
        //IR_DBG("New Mars IR: [%d = 0x%08X] is detected. conti_cnt = [%d] dataRepeat =[%d] key interval = [%d]\n", symbol, symbol,conti_cnt,*dataRepeat, (jiffies_to_msecs(jiffies)- lastRecvTime));
        lastSymbol = symbol;
        symbol = 0;
        conti_cnt  = 0;
    }

    lastRecvTime = jiffies_to_msecs(jiffies);

    first_decode = 0;

    if ((i == 11 && (symbol >> 7) == 0x1)
        || ((i == 11) && (symbol >> 7) == 0x08)
        || ((i == 14) && (symbol >> 7) == 0xA4)
        || ((i == 14) && (symbol >> 7) == 0x97)
        || ((i == 14) && (symbol >> 7) == 0x77)
        || ((i == 14) && (symbol >> 7) == 0x1A)
        || ((i == 14) && (symbol >> 7) == 0x04)
        || ((i == 14) && (symbol >> 7) == 0x03)
        || ((i == 14) && (symbol >> 7) == 0xC4)
        || ((i == 14) && (symbol >> 7) == 0x08)
        || ((i == 14) && (symbol >> 7) == 0x7F)
        || ((i == 14) && (symbol >> 7) == 0x80))
        return symbol;
    else
        return 0;
sleep:
    // prepare to stop sampling ..
    rtd_outl(REG_IR_RAW_CTRL, 0x01000010);
    first_decode = 1;


    return (0);
}
#endif

#ifdef CONFIG_RTK_KDRV_TV005_MOUSE
/* Notice that can't enable DEV_DEBUG
 * for pointing device work compatibly with NEC protocol  */
void ir_dsr_nec_decode(void)
{
    int i;
    int received = 0;
    int len = 0;
    int repeat = 0;
    int raw_bit_sample_cnt = 1;
    int length_low, length_high;
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    u32 keycode = 0;
#endif

    /* first fifo */
    if(first_fifo == 0 && kfifo_len(&ir_fifo_raw) % ir_len[1].fifo_len == 0) {
        raw_bit_anchor = 32;
        len = kfifo_out(&ir_fifo_raw, &raw_bit_sample, sizeof(uint32_t));
        first_fifo = 1;
    }

decode:
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(length_high >= ir_len[0].burst_len && length_low <= 12) { /* Repeat key for NEC protocol */
        repeat = 1;
        IR_DBG("Repeat IR [%08X] is detected.\n", symbol);
        goto sleep;
    }

    if(length_high < ir_len[0].burst_len || length_low < ir_len[0].silence_len) {
        while(kfifo_len(&ir_fifo_raw) > 0) {  /* frame space is too long for pointing device */
            length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
            if(length_high < ir_len[0].burst_len || length_low < ir_len[0].silence_len)
                continue;
            else
                break;
        }
        if(kfifo_len(&ir_fifo_raw) == 0 && raw_bit_anchor == 0) {
            goto sleep;
        } else if(kfifo_len(&ir_fifo_raw) == 0 && raw_bit_anchor > 0) {
            return;
        }
    }

    /* decode normally */
    symbol = 0;
    for(i = 0 ; i < ir_len[0].bit_num; i++) {
        length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
        length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

        if(length_high >= (ir_len[0].mod_len - 2) && length_low >= (ir_len[0].zero_len - 1)) {
            if(length_low >= (ir_len[0].one_len - 2))
                symbol |= (0x1 << i);
        } else {
            goto sleep;
        }
    }

    IR_DBG( "[%08X] is detected.\n", symbol);

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    keycode = venus_ir_scancode_to_keycode(symbol);
#endif
    kfifo_in(&ir_fifo, (unsigned char *)&symbol, sizeof(uint32_t));
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    venus_ir_input_report_key(symbol);
    venus_ir_mouse_report_event(symbol);
#endif
    received = 1;

    /* prepare to decode next command */
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(length_high >= (ir_len[0].mod_len - 2) && LEN_RANGE(length_low, ir_len[1].stop_len)) { /* frame space 5ms for pointing device */
        if(kfifo_len(&ir_fifo_raw) >= ir_len[1].fifo_len) {
            raw_bit_sample_cnt = 1;
            goto decode;
        } else {
            return;
        }
    } else {
        IR_DBG( "=====end===high = %d, low = %d, len = %d\n", length_high, length_low, kfifo_len(&ir_fifo_raw));
    }

sleep:
    rtd_outl(REG_IR_RAW_CTRL, 0x01000010); // stop sampling
    kfifo_reset(&ir_fifo_raw);

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    if (keycode != 0) {
        schedule_venus_ir_keyup_handler();
    }
#endif

    if(received) {
        wake_up_interruptible(&ir_read_wait);
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        venus_ir_mouse_report_end(symbol);
#endif
        received = 0;
    }
    return;
}
#endif

#ifdef CONFIG_RTK_KDRV_TV030_MOUSE
void ir_dsr_rca_decode(void)
{
    int i;
    int received = 0;
    int len = 0;
    int raw_bit_sample_cnt = 1;
    int length_low, length_high;
    u32 keycode = 0;

    /* first fifo */
    if(kfifo_len(&ir_fifo_raw) % 128 == 0) {
        raw_bit_anchor = 32;
        len = kfifo_out(&ir_fifo_raw, &raw_bit_sample, sizeof(uint32_t));
    }

decode:
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(!(LEAD_RANGE(length_high, length_low, 1)) && !(LEAD_RANGE(length_high, length_low, 0))) {
        while(kfifo_len(&ir_fifo_raw) > 0) {  /* frame space is too long for pointing device */
            length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
            if(!(LEAD_RANGE(length_high, length_low, 1)) && !(LEAD_RANGE(length_high, length_low, 0)))
                continue;
            else
                break;
        }
        if(kfifo_len(&ir_fifo_raw) == 0) {
            goto sleep;
        }
    }

    /* decode normally */
    symbol = 0;
    if(LEAD_RANGE(length_high, length_low, 1)) {
        for(i = (ir_len[1].bit_num - 1); i >= 0; i--) {
            length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
            if(LEN_RANGE(length_high, ir_len[1].mod_len) && BIT_RANGE(length_low, ir_len[1].one_len, ir_len[1].zero_len)) {
                if(length_low <= (ir_len[1].one_len + 1))
                    symbol |= (0x1 << i);
            } else {
                goto sleep;
            }
        }
    } else if(LEAD_RANGE(length_high, length_low, 0)) {
        for(i = (ir_len[0].bit_num - 1); i >= 0; i--) {
            length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
            if(LEN_RANGE(length_high, ir_len[0].mod_len) && BIT_RANGE(length_low, ir_len[0].zero_len, ir_len[0].one_len)) {
                if(length_low >= (ir_len[0].one_len - 1)) /* bit invert */
                    symbol |= (0x1 << i);
            } else {
                goto sleep;
            }
        }
    } else
        goto sleep;
#ifdef DEV_DEBUG
//      IR_DBG( "[%08X] is detected.\n", symbol);
#endif

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    keycode = venus_ir_scancode_to_keycode(symbol);
#endif

    if((symbol != lastSrValue) || (symbol == lastSrValue && (jiffies_to_msecs(jiffies) - lastRecvMs) > ir_repeat_interval)) {
        IR_DBG( "[%08X] is detected. %dms\n", symbol, (jiffies_to_msecs(jiffies) - lastRecvMs));
        lastRecvMs = jiffies_to_msecs(jiffies);
        kfifo_in(&ir_fifo, (unsigned char *)&symbol, sizeof(uint32_t));
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        venus_ir_input_report_key(symbol);
#endif
        //      venus_ir_mouse_report_event(symbol);
    }
    lastSrValue = symbol;
    received = 1;

    /* prepare to decode next command */
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(LEN_RANGE(length_high, ir_len[0].mod_len) && length_low >= (ir_len[0].stop_len - 22) && length_low <= (ir_len[0].stop_len + 22)) { /* frame space 6-10ms for RCA protocol */
        if(kfifo_len(&ir_fifo_raw) >= ir_len[0].fifo_len) {
            raw_bit_sample_cnt = 1;
            goto decode;
        } else {
            return;
        }
    }
    if(length_high >= (ir_len[1].mod_len - 2) && length_high <= (ir_len[1].mod_len + 1)) {
        if(kfifo_len(&ir_fifo_raw) >= ir_len[1].fifo_len) {
            raw_bit_sample_cnt = 1;
            goto decode;
        } else {
            return;
        }
    } else {
        IR_DBG( "=====end===high = %d, low = %d, len = %d\n", length_high, length_low, kfifo_len(&ir_fifo_raw));
    }

sleep:
    rtd_outl(REG_IR_RAW_CTRL, 0x01000010); // stop sampling
    kfifo_reset(&ir_fifo_raw);

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    if (keycode != 0) {
        schedule_venus_ir_keyup_handler();
    }
#endif

    if(received) {
        wake_up_interruptible(&ir_read_wait);
//              venus_ir_mouse_report_end(symbol);
    }

    return;
}
#endif

#ifdef CONFIG_RTK_KDRV_YK_54LU_SHUTTLE
void ir_dsr_sky_decode(void)
{
    int i;
    int received = 0;
    int len = 0;
    int bit_num = 0;
    int raw_bit_sample_cnt = 1;
    int length_low, length_high;
    u32 keycode = 0;

    /* first fifo */
    if(first_fifo == 0 && kfifo_len(&ir_fifo_raw) % 64 == 0) {
        raw_bit_anchor = 32;
        len = kfifo_out(&ir_fifo_raw, &raw_bit_sample, sizeof(uint32_t));
        first_fifo = 1;
    }

decode:
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(!LEAD_RANGE(length_high, length_low, 1)) {
        while(kfifo_len(&ir_fifo_raw) > 0) {
            length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
            if(!LEAD_RANGE(length_high, length_low, 1))
                continue;
            else
                break;
        }
        if(kfifo_len(&ir_fifo_raw) == 0 && raw_bit_anchor == 0) {
            goto sleep;
        } else if(kfifo_len(&ir_fifo_raw) == 0 && raw_bit_anchor > 0) {
            return;
        }
    }

    /* decode normally */
    symbol = 0;
    if(LEAD_RANGE(length_high, length_low, 1)) {
        bit_num = ir_len[1].bit_num;
    } else
        goto sleep;

    for(i = 0 ; i < bit_num; i++) {
        length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
        length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
        if(LEN_RANGE(length_high, ir_len[1].mod_len) && BIT_RANGE(length_low, ir_len[1].zero_len, ir_len[1].one_len)) {
            if(length_low <= (ir_len[1].zero_len + 2)) /* bit invert */
                symbol |= (0x1 << i);
        } else {
            goto sleep;
        }
    }

//      IR_DBG( "[%08X] is detected.\n", symbol);
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    keycode = venus_ir_scancode_to_keycode(symbol);
    shuttle_keycode = keycode;
#endif
    kfifo_in(&ir_fifo, (unsigned char *)&symbol, sizeof(uint32_t));
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    venus_ir_input_report_key(symbol);
#endif
    received = 1;
    shuttle_received = received;

    /* prepare to decode next command */
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(LEN_RANGE(length_high, ir_len[1].mod_len) && length_low >= ir_len[1].stop_len) { /* min frame space 2ms for shuttle */
        if(kfifo_len(&ir_fifo_raw) >= ir_len[1].fifo_len) {
            raw_bit_sample_cnt = 1;
            goto decode;
        } else {
            return;
        }
    } else {
        IR_DBG( "=====end===high = %d, low = %d, len = %d\n", length_high, length_low, kfifo_len(&ir_fifo_raw));
    }

sleep:
    rtd_outl(REG_IR_RAW_CTRL, 0x01000010); // stop sampling
    kfifo_reset(&ir_fifo_raw);
    first_fifo = 0;

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    if (shuttle_keycode != 0) {
        schedule_venus_ir_keyup_handler();
        shuttle_keycode = 0;
    }
#endif

    if(shuttle_received) {
        wake_up_interruptible(&ir_read_wait);
        shuttle_received = 0;
    }

    return;
}
#endif

#ifdef CONFIG_RTK_KDRV_TV035_IR
void ir_dsr_konka_decode(void)
{
    int i;
    int received = 0;
    int len = 0;
    int bit_num = 0;
    int raw_bit_sample_cnt = 1;
    int length_low, length_high;
    unsigned long stopCnt;
    u32 keycode = 0;

    /* first fifo */
    if(first_fifo == 0 && kfifo_len(&ir_fifo_raw) % 64 == 0) {
        raw_bit_anchor = 32;
        len = kfifo_out(&ir_fifo_raw, &raw_bit_sample, sizeof(uint32_t));
        first_fifo = 1;
    }

decode:
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(!LEAD_RANGE(length_high, length_low, 0)) {
        while(kfifo_len(&ir_fifo_raw) > 0) {
            length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
            length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
            if(!LEAD_RANGE(length_high, length_low, 0))
                continue;
            else
                break;
        }
        if(kfifo_len(&ir_fifo_raw) == 0 && raw_bit_anchor == 0) {
            goto sleep;
        } else if(kfifo_len(&ir_fifo_raw) == 0 && raw_bit_anchor > 0) {
            return ;
        }
    }

    /* decode normally */
    symbol = 0;
    if(LEAD_RANGE(length_high, length_low, 0)) {
        bit_num = ir_len[0].bit_num;
    } else
        goto sleep;

    for(i = 0 ; i < bit_num; i++) {
        length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
        length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);
        if(i < bit_num - 1) {
            if(LEN_RANGE(length_high, ir_len[0].mod_len) && BIT_RANGE(length_low, ir_len[0].zero_len, ir_len[0].one_len)) {
                if(length_low >= (ir_len[0].one_len - 2)) /* bit invert */
                    symbol |= (0x1 << (((bit_num - 1) - 1) - i));
            } else {
                goto sleep;
            }
        } else {
            if(LEN_RANGE(length_high, ir_len[0].mod_len) && LEN_RANGE(length_low, 20))
                continue;
            else
                goto sleep;
        }
    }

    //IR_DBG( "[%08X] is detected.\n", symbol);
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    keycode = venus_ir_scancode_to_keycode(symbol);
    shuttle_keycode = keycode;
#endif

    if((symbol != lastSrValue) || (symbol == lastSrValue && (jiffies_to_msecs(jiffies) - lastRecvMs) > ir_repeat_interval)) {
        IR_DBG( "[%08X] is detected. %dms\n", symbol, (jiffies_to_msecs(jiffies) - lastRecvMs));
        lastRecvMs = jiffies_to_msecs(jiffies);
        kfifo_in(&ir_fifo, (unsigned char *)&symbol, sizeof(uint32_t));
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        venus_ir_input_report_key(symbol);
        if(shuttle_keycode == 495) {
            venus_ir_input_report_end(0);
            shuttle_keycode = 0;
        }
#endif
    }

    lastSrValue = symbol;
    received = 1;
    shuttle_received = received;

    /* prepare to decode next command */
    length_high = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 0);
    length_low = get_fifo_bit_cnt(&raw_bit_anchor, &raw_bit_sample_cnt, &raw_bit_sample, 1);

    if(LEN_RANGE(length_high, ir_len[0].mod_len) && length_low >= 55 && length_low <= 135) { /* 55: min stop_len for 16 bit "1", 135: max stop_len for 16 bit "0" */
        if(kfifo_len(&ir_fifo_raw) >= ir_len[0].fifo_len) {
            raw_bit_sample_cnt = 1;
            goto decode;
        } else {
            return ;
        }
    } else {
        IR_DBG( "=====end===high = %d, low = %d, len = %d\n", length_high, length_low, kfifo_len(&ir_fifo_raw));
    }

sleep:
    rtd_outl(REG_IR_RAW_CTRL, 0x01000010); // stop sampling
    kfifo_reset(&ir_fifo_raw);
    first_fifo = 0;

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    if (shuttle_keycode != 0) {
        venus_ir_input_report_end(0);
        shuttle_keycode = 0;
    }
#endif

    if(shuttle_received) {
        wake_up_interruptible(&ir_read_wait);
        shuttle_received = 0;
    }

    return ;
}
#endif

#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_TV030_MOUSE) || defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) || defined(CONFIG_RTK_KDRV_TV035_IR)
void IR_raw_fifo_decode(u32 isr_fifo, u32 fifo_depth)
{
    int i;
    uint32_t regValue;

    for(i = 0; i < isr_fifo; i++) {
        regValue = rtd_inl(REG_IR_RAW_FF);
        kfifo_in(&ir_fifo_raw, (unsigned char *)&regValue, sizeof(uint32_t));
    }

    /* if the length of fifo is 32 words, ir_dsr will be start to decode */
    if(kfifo_len(&ir_fifo_raw) >= fifo_depth) {
        schedule_delayed_work(&ir_work, 0);
    }

}
#endif

