#ifndef __INPUT_EVENT_INTERCEPT_H__
#define __INPUT_EVENT_INTERCEPT_H__


#include <linux/init.h>
#include <linux/types.h>
#include <linux/idr.h>
#include <linux/input/mt.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/random.h>
#include <linux/major.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/seq_file.h>
#include <linux/poll.h>
#include <linux/device.h>
#include <linux/mutex.h>
#include <linux/input.h>
#include <linux/spinlock.h>



#define MAX_INTERCEPT_EVENT_ARRY_NUM 128

#define INPUT_GET_DEV_IDX(p)     (((unsigned long)(p)) & 0xFFFFFFFF)

typedef enum {
    INPUT_INTERCEPT_EVENT_MATCH_TYPE = (1 << 0),
    INPUT_INTERCEPT_EVENT_MATCH_CODE = (1 << 1),
    INPUT_INTERCEPT_EVENT_MATCH_VALUE = (1 << 2),
    INPUT_INTERCEPT_EVENT_KEYDOWN_SEND_UEVENT = (1 << 16),
    INPUT_INTERCEPT_EVENT_KEYUP_SEND_UEVENT = (1 << 17),
}INPUT_INTERCEPT_EVENT_FLAG;

typedef struct  _input_intercept_event{
    u32 type;
    u32 code;
    u32 value;
    u32 flags;
    struct list_head node;
}input_intercept_event;


typedef struct  _input_intercept_uevent{
    u32 type;
    u32 code;
    u32 value;
    u32 flags;
    struct input_dev *input_dev;
}input_intercept_uevent;


typedef struct {
    struct list_head event_list;
    rwlock_t events_lock;
   
    u32 uevents_num;
    input_intercept_uevent uevents_array[MAX_INTERCEPT_EVENT_ARRY_NUM];
    spinlock_t uevents_lock;
    
    struct work_struct work;
} INPUT_EVENT_INTERCEPT_LIST;



int input_init_intercept_event_list(struct class *p_class, INPUT_EVENT_INTERCEPT_LIST *p_events_list);

int input_free_intercept_event_list(struct class *p_class, INPUT_EVENT_INTERCEPT_LIST *p_events_list);

int input_query_intercept_event(INPUT_EVENT_INTERCEPT_LIST *p_events_list,
                                    u32 type, u32 code, u32 value, u32 *flags) ;

int input_remove_intercept_event(INPUT_EVENT_INTERCEPT_LIST *p_events_list, 
                                                u32 type, u32 code, u32 value, u32 flags);

int input_add_intercept_event(INPUT_EVENT_INTERCEPT_LIST *p_events_list, 
                                                u32 type, u32 code, u32 value, u32 flags);

int input_send_intercept_uevent(INPUT_EVENT_INTERCEPT_LIST *p_events_list, 
                                                            struct input_dev *dev,
                                                            u32 type, u32 code, u32 value);

#endif
