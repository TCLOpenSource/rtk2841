#ifndef __RTICE_CMD_H__
#define __RTICE_CMD_H__

#include <linux/list.h>
typedef struct  {
	struct list_head list;
	unsigned char *head;
	unsigned char *data;
	unsigned char *tail;
	unsigned char *end;
	unsigned long len;
} __attribute__ ((aligned(8))) rtice_cmd;
rtice_cmd * alloc_rtice_cmd(unsigned int len);
void free_rtice_cmd(rtice_cmd * cmd);
void rtice_cmd_reserve(rtice_cmd * cmd, unsigned int len);
unsigned char *rtice_cmd_put(rtice_cmd * cmd, unsigned int len);
void rtice_cmd_trim(rtice_cmd * cmd, unsigned int len);
void rtice_cmd_purge(rtice_cmd * cmd);
void rtice_cmd_dump_data(rtice_cmd * cmd);

#ifdef RTICE_CMD_DBG_ENABLE
#define rtice_cmd_dbg(fmt, args...) \
			printk(KERN_INFO "[RTICE][CMD] DBG, " fmt, ## args)
#else	/*  */
#define rtice_cmd_dbg(fmt, args...)
#endif	/*  */

#define rtice_cmd_warning(fmt, args...)  \
			printk(KERN_WARNING "[RTICE][CMD] WARNING," fmt,##args)

#endif	/*  */
