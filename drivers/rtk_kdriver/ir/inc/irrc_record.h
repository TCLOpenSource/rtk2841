#ifndef __IRRC_RECORD_H__
#define __IRRC_RECORD_H__

#define PLL_RBUS_FRQ 27000000 /*27MHZ*/
#define RECORD_RAW_MODE_FREQ 20000 /*2MHZ*/
#define RECORD_PER_BIT_TIME 50 /*50us*/

#define RECORD_RAW_FIFO_LEN 4096
#define RECORDER_DECODED_FIFO_LEN 1024
#define CONTINOUS_HIGH_LEVE_COUNT_THRESOLD 64 /*about 100ms*/
#define MAX_KEY_INTERVAL_COUNTS 1800

extern int IR_record_key_init(void);
extern void IR_record_key_fini(void);
extern void IR_raw_record_decode(void);
#endif
