#ifndef __IRRC_COMMON_H
#define  __IRRC_COMMON_H

#define MAX_HW_RTK_KDRV_PROTOCOLS_NUM   2
#define IRDA_PROTO_LIST_SIZE        20

enum {
    SINGLE_WORD_IF = 0, // send IRRP only
    DOUBLE_WORD_IF = 1, // send IRRP with IRSR together
};

// IR protocol support enum
enum {
    NEC = 1,
    RC5 = 2,
    SHARP = 3,
    SONY = 4,
    C03 = 5,
    RC6 = 6,
    RAW_NEC = 7,
    RCA = 8,
    PANASONIC = 9,
    KONKA = 10, //wangzhh add ,this value must same with the AP layer 20120927
    RAW_RC6 = 11,
    TSB = 12,
    RAW_TSB = 13,
    RAW_RCA = 14,
    RAW_C03 = 15,
    RAW_KONKA = 16,
    RAW_SONY = 17,
    AEHA = 18,
    TCL_NEC = 19,
#ifdef CONFIG_RTK_KDRV_RECORD_KEY
    RAW_RECORDER = 0xff,
#endif
};

enum {
	OFF = 0,
	ON = 1,
};

typedef enum _E_IRDA_REPORT_MODE {
    IRDA_REPORT_MODE_NORMAL = 0,
    IRDA_REPORT_MODE_TCL,
    IRDA_REPORT_MODE_MAX,
} eirda_report_mode;

typedef enum _E_IRDA_KEYMAP_TYPE{
    IRDA_KEYMAP_TYPE_NONE = 0,
    IRDA_KEYMAP_TYPE_NEC,
    IRDA_KEYMAP_TYPE_TV002,
    IRDA_KEYMAP_TYPE_TV030,
    IRDA_KEYMAP_TYPE_TV030_NEC,
    IRDA_KEYMAP_TYPE_TV036_10D,
    IRDA_KEYMAP_TYPE_MAX,
} eirda_keymap_type;

enum decode_mode{
    RAW_MODE = 0,
    HW_MODE = 1,
};

enum hw_decode{
    MAIN0 = 0,
    MAIN1 = 1,
};


extern int ir_support_protocols[MAX_HW_RTK_KDRV_PROTOCOLS_NUM];
extern int ir_protocol;
extern eirda_keymap_type ir_keymap_type;

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
extern unsigned int ir_to_mouse;
extern unsigned int ir_poll_interval;
extern unsigned int ir_poll_enable;
#endif

struct IRDA_PROTOCOL {
    unsigned int  proto_id;
    unsigned int  proto_standby_id;
    unsigned char proto_name[16];
    unsigned char remote_control_name[16];
};

int IR_Init(int main1_protcol, int main0_protocol, bool int_on);

void ir_set_rx_detect_on_off(uint32_t on);

typedef struct _S_IRDA_REPORT_MODE {
    eirda_report_mode mode;
    char name[32];
} sirda_report_mode;
#endif
