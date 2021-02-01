#ifndef __IR_INPUT_H
#define __IR_INPUT_H

#include <linux/input.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/delay.h>
#include "ir_debug.h"


#define LIBRA_MS_CUSTOMER_CODE      0x08F7
#define JAECS_T118_CUSTOMER_CODE    0xFC03
#define RTK_MK3_CUSTOMER_CODE       0xB649
#define YK_70LB_CUSTOMER_CODE       0x0E
#define RTK_MK4_CUSTOMER_CODE       0x6B86
#define RTK_MK5_CUSTOMER_CODE       0x7F80
#define NETG_MS_CUSTOMER_CODE       0x18
#define YK_54LU_CUSTOMER_CODE       0xf1f1
#define YK_76J_CUSTOMER_CODE        0xf1f1
#define KONKA_CUSTOMER_CODE     0x0200 //wangzhh add for konka 20130407
#define RTK_MK5_2_CUSTOMER_CODE     0xfb04
#define RTK_ANDROID_OTT_CUSTOMER_CODE   0xfd02
#define TV005_CUSTOMER_CODE1        0xBF40
#define TV005_CUSTOMER_CODE2        0xBE40
#define TV005_CUSTOMER_CODE3        0xBC40
#define YK_54LU_SHUTTLE_CUSTOMER_CODE   0x0002
#define YK_76J_SHUTTLE_CUSTOMER_CODE    0x0002
#define TV015_IR_AOC_CUSTOMER_CODE  0xbd00
#define TV015_IR_FAC_CUSTOMER_CODE  0x0820
#define TV015_IR_FAC_TEST_CODE1     0x926d0820
#define TV015_IR_FAC_TEST_CODE2     0x6d92f7df
#define TV015_IR_RC6_CUSTOMER_CODE  0x00
#define TV036_KTSG45_COUSTOM_CODE      0x7D02
#define TV036_10D_CUSTOMER_CODE        0x7F00

enum {
    KEYCODE_INTERCEPT_DISABLE_IRDA_DECODE = 0x00000001,
};
#define MAX_KEYCODE_ARRY_NUM 16
#define MAX_IR_DISABLE_KEY_TIME  (10 * HZ)
typedef struct {
    u32 keycode_num;
    /*keycode: keycode_array[i][0]; flags: keycode: keycode_array[i][1]*/
    u32 keycode_array[MAX_KEYCODE_ARRY_NUM][2];
    u8 keycode_array_not_empty;
    rwlock_t lock;
    struct work_struct work;
    struct timer_list timer;    
} IR_Keycode_List;


struct venus_ir_data {
    unsigned int irq;
    struct input_dev *input_dev;
    struct input_dev *mouse_dev;
    u32 scancode;
    u32 keycode;
    u32 prev_keycode;
    u32 dataRepeat;
};

#if defined(CONFIG_RTK_KDRV_TV002_IR)
struct sony_key {
    u32 custcode;
    u32 datacode;
    u32 keycode;
};

struct sony_key_table {
    struct sony_key *keys;
    int size;
};
#endif

struct venus_key {
    u32 scancode;
    u32 keycode;
};

struct venus_key_table {
    struct venus_key *keys;
    int size;
};

#if defined(CONFIG_RTK_KDRV_TV005_MOUSE) || defined(CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE)
int venus_ir_mouse_init(void);
void venus_ir_mouse_cleanup(void);
void venus_ir_mouse_report_event(uint32_t value);
void venus_ir_mouse_report_end(uint32_t value);
#endif
int venus_ir_input_init(void);
void venus_ir_input_cleanup(void);
int venus_ir_input_set_input_dev_name(const char *name);
void venus_ir_input_report_key(uint32_t repkey);
unsigned long _IR_Input_GetSystemTime(void);

void schedule_venus_ir_keyup_handler(void);
void venus_ir_input_report_end(unsigned long _data);
u32 venus_ir_scancode_to_keycode(uint32_t value);
u32 venus_ir_keycode_to_scancode(uint32_t value);
void venus_ir_keylist_to_scanlist(uint32_t *keylist, uint32_t *scanlist, uint32_t keycnt);
int venus_ir_is_simulated_key(u32 key);
void venus_ir_gen_keyupdown_event(uint32_t keycode);

int ir_add_keycode_to_list(IR_Keycode_List *p_keycode_list, u32 keycode, u32 flags);
int ir_remove_keycode_from_list(IR_Keycode_List *p_keycode_list, u32 keycode);
int ir_query_keycode_from_list(IR_Keycode_List *p_keycode_list, u32 keycode, u32 *flags) ;
void ir_send_intercept_key_event(struct input_dev *input_dev, u32 keycode);

#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
u32 voice_dev_cmd_to_keycode(uint32_t value);
void voice_dev_input_report_key(uint32_t value);
#endif
#endif


