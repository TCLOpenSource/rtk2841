#ifndef RTKDEMUX_DEBUG_H
#define RTKDEMUX_DEBUG_H

#include <linux/types.h>
#include <linux/printk.h>
#include <mach/rtk_log.h>
#include "rtkdemux_common.h"
#include "rtkdemux_refclk.h"
#define DEMUX_TAG_NAME "DEMUX"
/* FOR DEBUG*/
#define DGB_COLOR_RED_WHITE      "\033[1;31;47m"
#define DGB_COLOR_RED            "\033[1;31m"
#define DGB_COLOR_GREEN          "\033[1;32m"
#define DGB_COLOR_YELLOW         "\033[1;33m"
#define DGB_COLOR_BLUE           "\033[1;34m"
#define DGB_COLOR_PURPLE         "\033[1;35m"
#define DGB_COLOR_CYAN           "\033[1;36m"
#define DGB_COLOR_NONE           "\033[m"
#define DGB_COLOR_NONE_N         "\033[m \n"

enum {
//	DMX_LOGLEVEL_EMERG = 0,  /* system is unusable */
//	DMX_LOGLEVEL_ALERT,      /* action must be taken immediately */
//	DMX_LOGLEVEL_CRIT,       /* critical conditions */
//	DMX_LOGLEVEL_ERR,        /* error conditions */
//	DMX_LOGLEVEL_WARNING,    /* warning conditions */
//	DMX_LOGLEVEL_NOTICE,     /* normal but significant condition */
	DMX_LOGLEVEL_DEBUG,       /* debug-level messages */
	DMX_LOGLEVEL_INFO       /* informational */
};

#define dmx_emerg(fmt, ...)			{rtd_printk(KERN_EMERG, 	DEMUX_TAG_NAME,	fmt, ##__VA_ARGS__); }
#define dmx_alert(fmt, ...)			{rtd_printk(KERN_ALERT,		DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
#define dmx_crit(fmt, ...)			{rtd_printk(KERN_CRIT,		DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
#define dmx_err(fmt, ...)			{rtd_printk(KERN_ERR,		DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
#define dmx_warn(fmt, ...)			{rtd_printk(KERN_WARNING,	DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
#define dmx_notice(fmt, ...)		{rtd_printk(KERN_NOTICE,	DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
#define dmx_info(fmt, ...)    		{rtd_printk(KERN_INFO,		DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
#define dmx_dbg(fmt, ...)     		{rtd_printk(KERN_DEBUG,		DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }

//#define dmx_info(fmt, ...)     		{if (rtkdemux_dbg_log_mask > DMX_LOGLEVEL_INFO) rtd_printk(KERN_EMERG,DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
//#define dmx_dbg(fmt, ...)     		{if (rtkdemux_dbg_log_mask > DMX_LOGLEVEL_DEBUG) rtd_printk(KERN_EMERG,DEMUX_TAG_NAME, fmt, ##__VA_ARGS__); }
enum DEMUX_LOG_MASK_BIT{
	DEMUX_LOG_MASK_BIT_0 = 1 << 0,
		DEMUX_FUNCTIN_CALLER=DEMUX_LOG_MASK_BIT_0,
	DEMUX_LOG_MASK_BIT_1 = 1 << 1,
		DEMUX_NOMAL_DEBUG 	= DEMUX_LOG_MASK_BIT_1,
	DEMUX_LOG_MASK_BIT_2 = 1 << 2,
		DEMUX_BUFFER_DEBUG	= DEMUX_LOG_MASK_BIT_2,
	DEMUX_LOG_MASK_BIT_3 = 1 << 3,
		DEMUX_NOTICE_PRINT = DEMUX_LOG_MASK_BIT_3,// use this level to print, nomal log and mask log  same time,
	//avsync-----------------------------
	DEMUX_LOG_MASK_BIT_4 = 1 << 4,
		DEMUX_PCRSYC_DEBUG	= DEMUX_LOG_MASK_BIT_4,
	DEMUX_LOG_MASK_BIT_5 = 1<< 5,
		DEMUX_PCRTRACK_DEBUG = DEMUX_LOG_MASK_BIT_5,
	DEMUX_LOG_MASK_BIT_6 = 1<< 6,
		DEMUX_PCRSYC_DEBUG_EX1	= DEMUX_LOG_MASK_BIT_6,
	DEMUX_LOG_MASK_BIT_7 = 1<< 7,
		DEMUX_LR_DEBUG = DEMUX_LOG_MASK_BIT_7,
	//pes/section------------------------------
	DEMUX_LOG_MASK_BIT_8 = 1 << 8,
		DEMUX_PES_DEBUG 	= DEMUX_LOG_MASK_BIT_8,
	DEMUX_LOG_MASK_BIT_9 = 1<< 9,
		DEMUX_SECTION_DEBUG = DEMUX_LOG_MASK_BIT_9,
	DEMUX_LOG_MASK_BIT_10 = 1<< 10,
		DEMUX_FILTER_DEBUG = DEMUX_LOG_MASK_BIT_10,
	DEMUX_LOG_MASK_BIT_11 = 1<< 11,
		DEMUX_PID_DEBUG = DEMUX_LOG_MASK_BIT_11,
	//avsync---------------------------
	DEMUX_LOG_MASK_BIT_12 = 1<< 12,
		DEMUX_AUDIO_STABLE_DEBUG = DEMUX_LOG_MASK_BIT_12,
};
#define dmx_mask_print(BIT,fmt, ...)	{if ((BIT) & rtkdemux_dbg_log_mask) {dmx_emerg(fmt, ##__VA_ARGS__);}else {if ((BIT) & DEMUX_NOTICE_PRINT)		dmx_notice(fmt, ##__VA_ARGS__); }}
#define dmx_function_call() 			{dmx_mask_print(DEMUX_FUNCTIN_CALLER, "func %s, line %d\n", __func__, __LINE__)}

/* defined in kernel/printk.c */
extern int console_printk[4];

#define dmx_must_print(fmt, ...)	\
{\
	int prev_printk_level = console_printk[0];\
	if (prev_printk_level == 0)\
		console_printk[0] = 1;\
	pr_emerg(fmt, ##__VA_ARGS__);\
	console_printk[0] = prev_printk_level;\
}

extern unsigned long rtkdemux_dbg_log_mask;
extern unsigned long rtkdemux_dbg_audio_buffer_size;
extern unsigned long rtkdemux_dbg_video_buffer_size;
extern unsigned char rtkdemux_dbg_nodemux_audio_en;
extern unsigned char rtkdemux_dbg_nodemux_video_en;
extern unsigned char rtkdemux_dbg_printio_en;

/* Print IO */
void rtkdemux_dbg_printio_read_size_calc(
	void *ch_pointer, 			/* demux_channel */
	unsigned long read_size);
void rtkdemux_dbg_printio_deliver_size_calc(
	void *ch_pointer,
	int pin_idx,
	unsigned long deliver_size);
void rtkdemux_dbg_printio_print(void *ch_pointer);

/* Dump AvSync Info */
typedef struct {
	long long Pcr;
	long long Stc;
	long long Rcd;
	long long AudioDemuxPts;
	long long VideoDemuxPts;
	long long SubAudioDemuxPts;
	long long AudioSystemPts;
	long long VideoSystemPts;
	long long PcrOffset;
	long long MasterPTS;
	long long SystemPts;
} RTKDEMUX_AVSYNC_INFO_T;

bool demux_init_debug_proc(void);
void demux_uninit_debug_proc(void);

void rtkdemux_dbg_dump_ts_flush_enable(int tp_index);
void rtkdemux_dbg_dump_ts(int tp_index, char *buffer, unsigned int size);
void rtkdemux_dbg_dump_bitstream(int tp_index, int pin, char *buffer, unsigned int size);
void rtkdemux_dbg_dump_bitstream_flush(int tp_index, int pin_index);
void rtkdemux_dbg_dump_pes(int tp_index, char *buffer, unsigned int size, unsigned int dumppid);
void rtkdemux_dbg_dump_pes_flush(int tp_index);

void rtkdemux_dbg_dump_avsync_info_reset(int tp_index);
void rtkdemux_dbg_dump_avsync_info(int tp_index, RTKDEMUX_AVSYNC_INFO_T *info);
bool rtkdemux_dbg_dump_avsync_info_is_enabled(int tp_index);

void rtkdemux_dbg_dump_pts(int tp_index, int pin_index, int64_t pts);

void rtkdemux_dbg_force_mastership_check(int tp_index, REFCLOCK *refClock, AV_SYNC_MODE *avSyncMode);

void rtkdemux_print_demux_target(void);
void rtkdemux_print_filter_list(void);
void rtkdemux_print_section_filter_list(void);

void rtkdemux_dbg_print_pts(int tp_index, int pin_index, int64_t pts, unsigned char* WP);
#endif /* RTKDEMUX_DEBUG_H */
