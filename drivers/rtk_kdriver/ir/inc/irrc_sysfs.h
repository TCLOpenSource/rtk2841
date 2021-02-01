#ifndef __IRRC_SYSFS_H
#define  __IRRC_SYSFS_H

#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/kfifo.h>
#include <mach/io.h>
#include "ir_debug.h"
#include "irrc_common.h"
#include "irrc_reg.h"

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
#include "ir_input.h"
#endif

extern struct IRDA_PROTOCOL irda_proto_list[IRDA_PROTO_LIST_SIZE];
extern struct kfifo ir_fifo;
extern unsigned int ir_repeat_interval; 
extern int ir_is_upload_more_key;
extern eirda_report_mode ir_report_mode;
extern sirda_report_mode ir_report_mode_list[IRDA_REPORT_MODE_MAX];

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
int ir_mute_flag = 0;
extern unsigned int repeat_event;
extern unsigned int rawkey_event;
extern int is_customized_input_report_key;
extern int is_customized_input_report_end;
#endif

extern spinlock_t ir_lock;
static char protocol_attr_name[32] = {0};

#define ir_attr(_name) \
static struct kobj_attribute _name##_attr = {   \
        .attr   = {                             \
                .name = __stringify(_name),     \
                .mode = 0644,                   \
        },                                      \
        .show   = _name##_show,                 \
        .store  = _name##_store,                \
}

#define IR_BITS_MASK(msb, lsb)         ((0xFFFFFFFF >> (32-((msb) - (lsb) + 1))) << (lsb))

#endif
