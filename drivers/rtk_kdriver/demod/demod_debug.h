#ifndef _DEMOD_DEBUG_H_
#define _DEMOD_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <mach/rtk_log.h>

#define DEMOD_PROC_DIR                        "rtkdemod"
#define DEMOD_PROC_ENTRY                      "dbg"

typedef enum
{
	DEMOD_PROC_SETLOGONOFF,
	DEMOD_PROC_GETLOCK,
	DEMOD_PROC_GETCROFFSET,
	DEMOD_PROC_COUNT,                   /* max number */
}DEMOD_PROC_CMD;


typedef struct _RTK_DEMOD_DEBUG_CMD {
	const char *demod_cmd_str;
	DEMOD_PROC_CMD proc_cmd;
} SRTK_DEMOD_DEBUG_CMD, *PS_RTK_DEMOD_DEBUG_CMD;


int demod_proc_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos);
int demod_proc_read(struct file *file, char __user *buf, size_t count, loff_t *ppos);

#include "demod_debug.h"
#if 1
extern unsigned char demod_log_onoff;

#if 1
#define rtd_printk_demod(fmt, args...)  \
{ \
	if (demod_log_onoff) \
	{ \
		rtd_printk( fmt, ##args); \
	} \
}
#define rtd_printk_demod_force(fmt, args...)  \
{ \
		rtd_printk( fmt, ##args); \
}

#else
#define rtd_printk_demod(fmt, args...)  rtd_printk(fmt, ##args)
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
