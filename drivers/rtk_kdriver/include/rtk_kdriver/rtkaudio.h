#ifndef _LINUX_RTKAUDIO_H
#define _LINUX_RTKAUDIO_H

#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/string.h>

#include <rtk_kdriver/rtkaudio_debug.h>

#define RTKAUDIO_MAJOR             0
#define RTKAUDIO_MINOR 0

#define RTKAUDIO_SUSPEND           100
#define RTKAUDIO_RESUME            101
#define RTKAUDIO_RESET_PREPARE     102
#define RTKAUDIO_RESET_DONE        103

#define S_OK	0x10000000

#define REMOTE_MALLOC_DISABLE	0
#define REMOTE_MALLOC_ENABLE	1

#ifdef CONFIG_HIBERNATION
extern int in_suspend;
#endif

#define RTKAUDIO_PROC_DIR   "rtkaudio"
#define RTKAUDIO_PROC_ENTRY "debuginfo"

int register_rtkaudio_notifier(struct notifier_block *nb);
int unregister_rtkaudio_notifier(struct notifier_block *nb);

/* Record memory use*/
struct buffer_info {
	struct list_head buffer_list;

	/* virtual address */
	unsigned long vir_addr;

	/* physical address */
	unsigned long phy_addr;

	/* request size by audio DSP */
	unsigned long request_size;

	/* kernel malloc size */
	unsigned long malloc_size;
	pid_t         task_pid;
};

/* IOCTL return structure */
struct ret_info {
	unsigned long private_info[16];
};

/* IOCTL set/get control structure */
struct cntl_info {
	int resource_type;
	int addr;
	int size;
};

/* GST info */
struct gst_info {
	int gst_open;
	unsigned long long decoded_size;
	unsigned long long undecoded_size;
};

/* Store Open list */
struct rtkaudio_open_list {
	struct list_head open_list;
	pid_t pid;
	struct gst_info info;
};

#define refc_info_size 8
struct refclock_info {
	unsigned long phy_addr;
	int pid;
	int port;
};

/* Store Gst RefClock list */
struct gst_refc_list {
	int size;
	int index;
	struct refclock_info info[refc_info_size];
};

/* Virtual X cmd info */
struct virtualx_cmd_info {
	unsigned int result;
	unsigned int type;
	unsigned int size;
	unsigned int data[60];
};
typedef struct virtualx_cmd_info virtualx_cmd_info;

typedef struct {
	unsigned int  msg_id;
	unsigned int value[15];
} AUDIO_CONFIG_COMMAND_RTKAUDIO;

typedef enum {
	LR_DIGITAL_VOLUME_CONTROL_STATUS = 0,
	CSW_DIGITAL_VOLUME_CONTROL_STATUS = 1,
	LSRS_DIGITAL_VOLUME_CONTROL_STATUS = 2,
	LRRR_DIGITAL_VOLUME_CONTROL_STATUS = 3,
	GST_CLOCK = 4,
	AMIXER_STATUS = 5,
	DEBUG_REGISTER = 6
} AUDIO_REGISTER_TYPE;

typedef struct
{
	AUDIO_REGISTER_TYPE reg_type;
	int reg_value;	/* register value */
	int data;   	/* value for data write */
} AUDIO_REGISTER_ACCESS_T;

#define ENUM_KERNEL_RPC_AUDIO_CONFIG 0x204

/* defined in kernel/printk.c */
extern int console_printk[4];

#define rtkaudio_must_print(fmt, ...)	\
{\
	int prev_printk_level = console_printk[0];\
	if (prev_printk_level == 0)\
		console_printk[0] = 1;\
	pr_emerg(fmt, ##__VA_ARGS__);\
	console_printk[0] = prev_printk_level;\
}

/*
 * Ioctl definitions
 */

/* Use 'a' as magic number */
#define RTKAUDIO_IOC_MAGIC  'a'

/*
 * S means "Set"                : through a ptr,
 * T means "Tell"               : directly with the argument value
 * G means "Get"                : reply by setting through a pointer
 * Q means "Query"              : response is on the return value
 * X means "eXchange"           : G and S atomically
 * H means "sHift"              : T and Q atomically
 */
#define RTKAUDIO_IOC_INIT                   _IO(RTKAUDIO_IOC_MAGIC, 1)
#define RTKAUDIO_IOC_DEINIT                 _IO(RTKAUDIO_IOC_MAGIC, 2)
#define RTKAUDIO_IOC_OPEN                   _IOW(RTKAUDIO_IOC_MAGIC, 3, int)
#define RTKAUDIO_IOC_CLOSE                  _IOW(RTKAUDIO_IOC_MAGIC, 4, int)
#define RTKAUDIO_IOC_CONNECT                _IOW(RTKAUDIO_IOC_MAGIC, 5, int)
#define RTKAUDIO_IOC_SET                    _IOW(RTKAUDIO_IOC_MAGIC, 6, int)
#define RTKAUDIO_IOC_GET                    _IOR(RTKAUDIO_IOC_MAGIC, 7, int)
#define RTKAUDIO_IOC_GET_ALL                _IOR(RTKAUDIO_IOC_MAGIC, 8, int)
#define RTKAUDIO_IOC_FW_REMOTE_MALLOC_SUM   _IOR(RTKAUDIO_IOC_MAGIC, 9, int)
#define RTKAUDIO_IOC_ALLOC                  _IOW(RTKAUDIO_IOC_MAGIC, 10, int)
#define RTKAUDIO_IOC_FREE                   _IOW(RTKAUDIO_IOC_MAGIC, 11, int)
#define RTKAUDIO_IOC_ALLOC_SUM              _IOR(RTKAUDIO_IOC_MAGIC, 12, int)
#define RTKAUDIO_IOC_AUDIO_CONFIG           _IOWR(RTKAUDIO_IOC_MAGIC, 13, int)
#define RTKAUDIO_IOC_READ_REG               _IOR(RTKAUDIO_IOC_MAGIC, 14, int)
#define RTKAUDIO_IOC_WRITE_REG              _IOW(RTKAUDIO_IOC_MAGIC, 15, int)

#endif

