/******************************************************************************
 *
 *   Realtek Demux debug
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author evenkeel@realtek.com
 *
 *****************************************************************************/
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include "rtkdemux.h"
#include "rtkdemux_common.h"
#include "rtkdemux_export.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_refclk.h"
#include <linux/file.h>
#include <linux/string.h>
#include <tp/tp_reg_ctrl.h>

extern const char *rtkdemux_outputNames[NUMBER_OF_PINS];

#define DMX_DBG_LOG(fmt, ...) pr_emerg(fmt, ##__VA_ARGS__)

#define RTKDEMUX_PROC_DIR                        "rtkdemux"
#define RTKDEMUX_PROC_ENTRY                      "dbg"
#define RTKDEMUX_MAX_CMD_LENGTH 256
#define RTKDEMUX_MAX_DUMP_PES_FILE_NAME_LEN 1024

enum {
	DEMUX_DBG_CMD_LOG_LEVEL = 0,
	DEMUX_DBG_CMD_SET_AUDIO_BUFFER_SIZE = 1,
	DEMUX_DBG_CMD_SET_VIDEO_BUFFER_SIZE = 2,
	DEMUX_DBG_CMD_SET_PCR_OFFSET = 3,
	DEMUX_DBG_CMD_DONT_DELIVER_AUDIO = 4,
	DEMUX_DBG_CMD_DONT_DELIVER_VIDEO = 5,
	DEMUX_DBG_CMD_DTV_FORCE_MASTERSHIP = 6,
	DEMUX_DBG_CMD_PRINT_IO = 7,
	DEMUX_DBG_CMD_SHOW_BUFFER_INFO = 8,
	DEMUX_DBG_CMD_DUMP_TS = 9,
	DEMUX_DBG_CMD_DUMP_BITSTREAM = 10,
	DEMUX_DBG_CMD_DUMP_AVSYNC_INFO = 11,
	DEMUX_DBG_CMD_DUMP_PTS = 12,
	DEMUX_DBG_CMD_SET_PID = 13,
	DEMUX_DBG_CMD_PRINT_DEMUX_TARGET = 14,
	DEMUX_DBG_CMD_PRINT_FILTER_LIST = 15,
	DEMUX_DBG_CMD_PRINT_SECTION_FILTER_LIST = 16,
	DEMUX_DBG_CMD_PRINT_PTS = 17,
	DEMUX_DBG_CMD_PRINT_CLOCK = 18,
	DEMUX_DBG_CMD_PCR_TRACK = 19,
	DEMUX_DBG_CMD_DUMP_PES = 20,
	DEMUX_DBG_CMD_NUMBER
} DEMUX_DBG_CMD_INDEX_T;

static const char *rtkdemux_cmd_str[] = {
	"level=",			/* DEMUX_DBG_CMD_LOG_LEVEL */
	"audiosize=",		/* DEMUX_DBG_CMD_SET_AUDIO_BUFFER_SIZE */
	"videosize=",		/* DEMUX_DBG_CMD_SET_VIDEO_BUFFER_SIZE */
	"pcroffset=",		/* DEMUX_DBG_CMD_SET_PCR_OFFSET */
	"nodemuxaudio=",    /* DEMUX_DBG_CMD_DONT_DELIVER_AUDIO */
	"nodemuxvideo=",    /* DEMUX_DBG_CMD_DONT_DELIVER_VIDEO */
	"mastership=",		/* DEMUX_DBG_CMD_DTV_FORCE_MASTERSHIP */
	"printio=",			/* DEMUX_DBG_CMD_PRINT_IO */
	"buffer_info",		/* DEMUX_DBG_CMD_SHOW_BUFFER_INFO */
	"dumpts=",			/* DEMUX_DBG_CMD_DUMP_TS */		/* dump_ts=1,0,/tmp/dump.ts */
	"dumpes=",			/* DEMUX_DBG_CMD_DUMP_BITSTREAM */  /* dump_es=1,0,audio,/tmp/dump.ac3 */
	"dumpavsyncinfo=",  /* DEMUX_DBG_CMD_DUMP_AVSYNC_INFO */
	"dumppts=",			/* DEMUX_DBG_CMD_DUMP_PTS */
	"setpid=",          /* DEMUX_DBG_CMD_SET_PID */
	"demux_target", 	/* DEMUX_DBG_CMD_PRINT_DEMUX_TARGET */
	"filter_list",		/* DEMUX_DBG_CMD_PRINT_FILTER_LIST */
	"section_filter",	/* DEMUX_DBG_CMD_PRINT_SECTION_FILTER_LIST */
	"printpts=",		/* DEMUX_DBG_CMD_PRINT_PTS */
	"printclock=",		/* DEMUX_DBG_CMD_PRINT_CLOCK */
	"pcrtrack=",		/* DEMUX_DBG_CMD_PCR_TRACK */
	"dumppes=",			/* DEMUX_DBG_CMD_DUMP_PES */
};

unsigned long rtkdemux_dbg_log_mask;
unsigned long rtkdemux_dbg_audio_buffer_size;
unsigned long rtkdemux_dbg_video_buffer_size;
unsigned char rtkdemux_dbg_nodemux_audio_en;
unsigned char rtkdemux_dbg_nodemux_video_en;
unsigned char rtkdemux_dbg_printio_en;
unsigned char rtkdemux_dbg_printclock_en;

/*****************************************************************************/

/* Print IO */
unsigned long rtkdemux_dbg_printio_read_count[DEMUX_CH_NUM];
unsigned long rtkdemux_dbg_printio_deliver_count[DEMUX_CH_NUM][NUMBER_OF_PINS];

int rtkdemux_dbg_get_ch_idx(demux_channel *ch_pointer)
{
	int ch_idx;
	if (!demux_device)
		return -1;


	for (ch_idx = 0; ch_idx < DEMUX_CH_NUM; ch_idx++)
		if (ch_pointer == &demux_device->pChArray[ch_idx])
			break;
	if (ch_idx == DEMUX_CH_NUM)
		return -1;
	return ch_idx;
}

void rtkdemux_dbg_printio_read_size_calc(void *ch_pointer, unsigned long read_size)
{
	demux_channel *ch = (demux_channel *)ch_pointer;
	int ch_idx = rtkdemux_dbg_get_ch_idx(ch);
	if (ch_idx >= 0)
		rtkdemux_dbg_printio_read_count[ch_idx] += read_size;
}

void rtkdemux_dbg_printio_deliver_size_calc(void *ch_pointer, int pin_idx, unsigned long deliver_size)
{
	demux_channel *ch = (demux_channel *)ch_pointer;
	int ch_idx = rtkdemux_dbg_get_ch_idx(ch);
	if (ch_idx >= 0 && pin_idx >= 0 && pin_idx < NUMBER_OF_PINS)
		rtkdemux_dbg_printio_deliver_count[ch_idx][pin_idx] += deliver_size;
}

void rtkdemux_dbg_printio_print(void *ch_pointer)
{
	static int64_t clock[DEMUX_CH_NUM] = {0};
	demux_channel *ch = (demux_channel *)ch_pointer;
	int ch_idx = rtkdemux_dbg_get_ch_idx(ch);

	if(ch_idx < 0)
		return;
	if (ch->startStreaming && CLOCK_GetPTS()-clock[ch_idx] > DEMUX_CLOCKS_PER_SEC) {
		int i;
		unsigned long * const deliver_counters =
			rtkdemux_dbg_printio_deliver_count[ch_idx];

		DMX_DBG_LOG(
			DGB_COLOR_GREEN"CH[%d]: READ:%lu"
			", VIDEO:%lu, AUDIO:%lu, VIDEO2:%lu, AUDIO2:%lu, SUBTITLE:%lu \n"DGB_COLOR_NONE,
			ch_idx,
			rtkdemux_dbg_printio_read_count[ch_idx],
			deliver_counters[VIDEO_PIN],
			deliver_counters[AUDIO_PIN],
			deliver_counters[VIDEO2_PIN],
			deliver_counters[AUDIO2_PIN],
			deliver_counters[SUBTITLE_PIN]
		);

		rtkdemux_dbg_printio_read_count[ch_idx] = 0;

		for (i = 0; i < NUMBER_OF_PINS; i++)
			deliver_counters[i] = 0;

		clock[ch_idx] = CLOCK_GetPTS();
	}
}

extern u32 DEMUX_reverseInteger(u32 value);
static inline unsigned rtkdemux_dbg_get_free_size(
	const unsigned long *wp,
	const unsigned long *rp,
	unsigned lower,
	unsigned upper,
	bool is_reverse)
{
	unsigned long phyWp, phyRp;

	if (wp == NULL || rp == NULL)
		return 0;

	if (is_reverse) {
		phyWp = DEMUX_reverseInteger(*(UINT32 *)wp);
		phyRp = DEMUX_reverseInteger(*(UINT32 *)rp);
	} else {
		phyWp = *(UINT32 *)wp;
		phyRp = *(UINT32 *)rp;
	}

	if (phyRp > phyWp)
		return (UINT32)(phyRp - phyWp);
	else
		return  (UINT32)((upper - lower) - (phyWp - phyRp));
}

static void rtkdemux_dbg_show_buffer_info(void)
{
	unsigned int sec_used_size = 0;
	unsigned int sec_used_num = 0;
	unsigned int total_allocated = 0;
	int i = 0;
	int j = 0;

	DMX_DBG_LOG(DGB_COLOR_GREEN"=========================================================================================="DGB_COLOR_NONE_N);

	/* demux_device buffer */
	DMX_DBG_LOG(DGB_COLOR_GREEN"Pool: %uB allocated, %uB size, %uB used, %uB free"DGB_COLOR_NONE_N,
		demux_device->bufPoll.allocSize, demux_device->bufPoll.size, demux_device->usedPollSize, demux_device->bufPoll.size - demux_device->usedPollSize);
	total_allocated += demux_device->bufPoll.allocSize;

	sec_used_size = 0;
	sec_used_num = 0;
/*
	for (i = 0 ; i < SEC_FILTER_BUFFER_NUM ; i++) {
		if (demux_device->secMap[i].occupied) {
			sec_used_size += SEC_FILTER_BUFFER_EACH_SIZE;
			sec_used_num++;
		}
	}
	DMX_DBG_LOG(DGB_COLOR_GREEN"Section: %uB allocated, %uB size, %uB(%u/%d) used, %uB free\n"DGB_COLOR_NONE,
		demux_device->secFilterBuffer.allocSize,
		demux_device->secFilterBuffer.size,
		sec_used_size,
		sec_used_num,
		SEC_FILTER_BUFFER_NUM,
		demux_device->secFilterBuffer.size - sec_used_size);
*/
	for (i = 0; i < SEC_FILTER_BUFFER_UNIT_CNT; i++) {
		if (demux_device->secMap[i].occupied) {
			sec_used_num++;
			sec_used_size += SEC_FILTER_BUFFER_UNIT_SIZE;
		}
	}
	DMX_DBG_LOG(DGB_COLOR_GREEN"Section: %uB allocated, %uB size, %uB(%u/%d) used, %uB free"DGB_COLOR_NONE_N,
		demux_device->secFilterBuffer.allocSize,
		demux_device->secFilterBuffer.size,
		sec_used_size,
		sec_used_num,
		SEC_FILTER_BUFFER_UNIT_CNT,
		demux_device->secFilterBuffer.size - sec_used_size);

	total_allocated += demux_device->secFilterBuffer.allocSize;

	/* demux_channel buffer */
	for (i = 0; i < demux_device->chNum; i++) {
		demux_channel *pCh = &demux_device->pChArray[i];
		DMX_DBG_LOG("\n");
		DMX_DBG_LOG(DGB_COLOR_GREEN"CH%d:"DGB_COLOR_NONE_N, i);

		/* demux_device->isInit is to confirm that all demux_channel have been initialized. */
		if (demux_device->isInit && pCh->isInit) {
			DEMUX_BUF_PIN_T *pin_info;
			int pin;
			unsigned int pes_used_size;
			unsigned int pes_used_num;
			unsigned long write_pointer;
			unsigned long read_pointer;
			unsigned free_size;
			unsigned tp_buffer_size;
			/* tp */
			TP_BUFFER_PARAM_T tp_ring_buffer = {0};
			_tp_lock();
			if (i == 0)
				Tp_Get_Buffer(TP0_BUFFER_MASS_DATA, &tp_ring_buffer);
			else if (i == 1)
				Tp_Get_Buffer(TP1_BUFFER_MASS_DATA, &tp_ring_buffer);
			else
				Tp_Get_Buffer(TP2_BUFFER_MASS_DATA, &tp_ring_buffer);
			_tp_unlock();

			write_pointer = tp_ring_buffer.WP;
			read_pointer  = tp_ring_buffer.RP;
			free_size = rtkdemux_dbg_get_free_size(
				(const unsigned long *)&write_pointer,
				(const unsigned long *)&read_pointer,
				tp_ring_buffer.Base,
				tp_ring_buffer.Limit,
				false // pointer valuess are not reversed
			);

			tp_buffer_size = tp_ring_buffer.Limit - tp_ring_buffer.Base;
			DMX_DBG_LOG(DGB_COLOR_GREEN"    TP: %uB allocated, %uB size, %uB used, %uB free"DGB_COLOR_NONE_N,
				pCh->tpBuffer.allocSize, tp_buffer_size, tp_buffer_size - free_size, free_size);
			total_allocated += pCh->tpBuffer.allocSize;

			/* pes */
			pes_used_size = 0;
			pes_used_num = 0;


			for (j = 0; j < MAX_PID_FILTER_CB_NUM; j++) {
				DEMUX_PES_MAP_T   *pPes = &pCh->pesMap[j];
				DMX_DBG_LOG(DGB_COLOR_GREEN"   PES %d:  %uB allocated, %uB size, status: %d "DGB_COLOR_NONE_N,
					j, pPes->pesFilterBuffer.allocSize, pPes->pesFilterBuffer.size, pPes->bufferStatus );
			}	

			pin_info = NULL;
			pin = 0;
			/* video */
			for (j = 0 ; j < demux_device->numberOfVD ; j++) {
				unsigned free_size;
				pin = (j ? VIDEO2_PIN : VIDEO_PIN);
				/* bitstream buffer */
				pin_info = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
				if (pin_info->pRBH == 0)
					continue;

				free_size = rtkdemux_dbg_get_free_size(
					(const unsigned long *)pin_info->pWrPtr,
					(const unsigned long *)pin_info->pRdPtr,
					(uintptr_t)pin_info->pBufferLower,
					(uintptr_t)pin_info->pBufferUpper,
					true // pass reversed pointer values
				);
				DMX_DBG_LOG(DGB_COLOR_GREEN"    Video%d BS: %uB allocated, %uB size, %uB used, %uB free"DGB_COLOR_NONE_N,
					j, pCh->bsDecBuf[j].allocSize, pCh->bsDecBuf[j].size, pCh->bsDecBuf[j].size - free_size, free_size);
				total_allocated += pCh->bsDecBuf[j].allocSize;


				/* inband buffer */
				pin_info = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
				free_size = rtkdemux_dbg_get_free_size(
					(const unsigned long *)pin_info->pWrPtr,
					(const unsigned long *)pin_info->pRdPtr,
					(uintptr_t)pin_info->pBufferLower,
					(uintptr_t)pin_info->pBufferUpper,
					true // pass reversed pointer values
				);
				DMX_DBG_LOG(DGB_COLOR_GREEN"    Video%d IB: %uB allocated, %uB size, %uB used, %uB free"DGB_COLOR_NONE_N,
					j, pCh->ibDecBuf[j].allocSize, pCh->ibDecBuf[j].size, pCh->ibDecBuf[j].size - free_size, free_size);
				total_allocated += pCh->ibDecBuf[j].allocSize;

			}

			/* audio */
			for (j = 0 ; j < demux_device->numberOfAD ; j++) {
				unsigned free_size;
				pin = (j ? AUDIO2_PIN : AUDIO_PIN);
				/* bitstream buffer */
				pin_info = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
				if (pin_info->pRBH == 0)
					continue;

				free_size = rtkdemux_dbg_get_free_size(
					(const unsigned long *)pin_info->pWrPtr,
					(const unsigned long *)pin_info->pRdPtr,
					(uintptr_t)pin_info->pBufferLower,
					(uintptr_t)pin_info->pBufferUpper,
					true // pass reversed pointer values
				);

				DMX_DBG_LOG(DGB_COLOR_GREEN"    Audio%d BS: %uB allocated, %uB size, %uB used, %uB free"DGB_COLOR_NONE_N,
					j, pCh->bsDecBuf[j].allocSize, pCh->bsDecBuf[j].size, pCh->bsDecBuf[j].size - free_size, free_size);
				total_allocated += pCh->bsDecBuf[j].allocSize;

				/* inband buffer */
				pin_info = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
				free_size = rtkdemux_dbg_get_free_size(
					(const unsigned long *)pin_info->pWrPtr,
					(const unsigned long *)pin_info->pRdPtr,
					(uintptr_t)pin_info->pBufferLower,
					(uintptr_t)pin_info->pBufferUpper,
					true // pass reversed pointer values
				);

				DMX_DBG_LOG(DGB_COLOR_GREEN"    Audio%d IB: %uB allocated, %uB size, %uB used, %uB free"DGB_COLOR_NONE_N,
					j, pCh->ibDecBuf[j].allocSize, pCh->ibDecBuf[j].size, pCh->ibDecBuf[j].size - free_size, free_size);
				total_allocated += pCh->ibDecBuf[j].allocSize;

			}


		} else {
			DMX_DBG_LOG(DGB_COLOR_RED"    channel%d has not initialized."DGB_COLOR_NONE, i);
		}
	}

	DMX_DBG_LOG("\n");
	DMX_DBG_LOG(DGB_COLOR_GREEN"Summary: %uB allocated"DGB_COLOR_NONE_N, total_allocated);
	DMX_DBG_LOG(DGB_COLOR_GREEN"=========================================================================================="DGB_COLOR_NONE_N);
}

static char *rtkdemux_get_pidtype_string(int pid_type)
{
	/* use static to let return value be valid */
	/* AndroidTV_Klocwork_0144664 : sync enum DEMUX_PID_TYPE_T from rtkdemux_export.h */
	static char *pid_type_string[] =
	{
		"DEMUX_PID_VIDEO",
		"DEMUX_PID_AUDIO",
		"DEMUX_PID_PCR",
		"DEMUX_PID_TELETEXT",
		"DEMUX_PID_SUBTITLE",
		"DEMUX_PID_ISDB_CC",
		"DEMUX_PID_ISDB_CC_SUPERIMPOSE",
		"DEMUX_PID_DCC",
		"DEMUX_PID_PSI",
		"DEMUX_PID_GP"
	};

	static char nullstr = '\0';

	if (pid_type >= 0 && pid_type < DEMUX_PID_TYPE_NUM)
		return pid_type_string[pid_type];
	else
		return &nullstr;
}

static char *rtkdemux_get_pesdest_string(int pid_dest)
{
	/* use static to let return value be valid */
	static char *pid_dest_string[] =
	{
		"DEMUX_DEST_NONE",
		"DEMUX_DEST_ADEC0",
		"DEMUX_DEST_ADEC1",
		"DEMUX_DEST_VDEC0",
		"DEMUX_DEST_VDEC1",
		"DEMUX_DEST_STC0",
		"DEMUX_DEST_STC1",
		"DEMUX_DEST_BUFFER",
		"DEMUX_DEST_RECORD_A",
		"DEMUX_DEST_RECORD_B",
		"DEMUX_DEST_TSO",
		"DEMUX_DEST_PSI",
		"DEMUX_DEST_SUBTITLE",
		"DEMUX_DEST_TELETEXT",
		"DEMUX_DEST_ISDB_CC",
		"DEMUX_DEST_ISDB_CC_SUPERIMPOSE"
	};

	static char nullstr = '\0';

	if (pid_dest >= 0 && pid_dest < DEMUX_DEST_NUM)
		return pid_dest_string[pid_dest];
	else
		return &nullstr;
}

void rtkdemux_print_demux_target(void)
{
	int i, j;
	if (demux_device) {
		DMX_DBG_LOG(DGB_COLOR_GREEN"==========================================================================================\n"DGB_COLOR_NONE);
		for (i = 0 ; i < demux_device->chNum ; i++) {
			demux_channel *pCh = &demux_device->pChArray[i];
			if (pCh) {
				if (!pCh->isInit) {
					DMX_DBG_LOG(DGB_COLOR_GREEN"CH%d: isInit=%d\n"DGB_COLOR_NONE, i, pCh->isInit);
					continue;
				}
				DMX_DBG_LOG(DGB_COLOR_GREEN"CH%d: streaming=%d\n"DGB_COLOR_NONE, i, pCh->startStreaming);
				mutex_lock(&pCh->mutex);
				for (j = 0 ; j < pCh->pidFilterCount ; j++) {

					int target = pCh->demuxTargetTable[pCh->pidFilterList[j].pid];

					if (target >= 0 && target < DEMUX_NUM_OF_TARGETS)
						DMX_DBG_LOG(DGB_COLOR_GREEN"(%d/%d): pid=%d(0x%x),type=%s(%d),dest=%s(%d),target_pin=%s\n"DGB_COLOR_NONE,
							j+1,
							pCh->pidFilterCount,
							pCh->pidFilterList[j].pid, pCh->pidFilterList[j].pid,
							rtkdemux_get_pidtype_string(pCh->pidFilterList[j].pidType), pCh->pidFilterList[j].pidType,
							rtkdemux_get_pesdest_string(pCh->pidFilterList[j].pesDest), pCh->pidFilterList[j].pesDest,
							rtkdemux_outputNames[pCh->demuxTargetInfo[pCh->demuxTargetTable[pCh->pidFilterList[j].pid]].pinIndex]);
					else
						DMX_DBG_LOG(DGB_COLOR_GREEN"(%d/%d): pid=%d(0x%x),type=%s(%d),dest=%s(%d),target_pin=NOT_DEMUX\n"DGB_COLOR_NONE,
							j+1,
							pCh->pidFilterCount,
							pCh->pidFilterList[j].pid, pCh->pidFilterList[j].pid,
							rtkdemux_get_pidtype_string(pCh->pidFilterList[j].pidType), pCh->pidFilterList[j].pidType,
							rtkdemux_get_pesdest_string(pCh->pidFilterList[j].pesDest), pCh->pidFilterList[j].pesDest);

				}
				mutex_unlock(&pCh->mutex);
			}
		}
		DMX_DBG_LOG(DGB_COLOR_GREEN"==========================================================================================\n"DGB_COLOR_NONE);
	}
}

void rtkdemux_print_filter_list(void)
{
	int i, j;
	if (demux_device) {
		DMX_DBG_LOG(DGB_COLOR_GREEN"==========================================================================================\n"DGB_COLOR_NONE);
		for (i = 0 ; i < demux_device->chNum ; i++) {
			demux_channel *pCh = &demux_device->pChArray[i];
			if (pCh) {
				if (!pCh->isInit) {
					DMX_DBG_LOG(DGB_COLOR_GREEN"CH%d: isInit=%d\n"DGB_COLOR_NONE, i, pCh->isInit);
					continue;
				}
				DMX_DBG_LOG(DGB_COLOR_GREEN"CH%d: streaming=%d\n"DGB_COLOR_NONE, i, pCh->startStreaming);
				mutex_lock(&pCh->mutex);
				for (j = 0 ; j < pCh->pidFilterCount ; j++) {
					DMX_DBG_LOG(DGB_COLOR_GREEN"    PID_FILTER(%d/%d): pid=%d(0x%x),type=%s(%d),dest=%s(%d),en_descramble=%d,cw_index=%d\n"DGB_COLOR_NONE,
						j+1,
						pCh->pidFilterCount,
						pCh->pidFilterList[j].pid, pCh->pidFilterList[j].pid,
						rtkdemux_get_pidtype_string(pCh->pidFilterList[j].pidType), pCh->pidFilterList[j].pidType,
						rtkdemux_get_pesdest_string(pCh->pidFilterList[j].pesDest), pCh->pidFilterList[j].pesDest,
						pCh->pidFilterList[j].enDescramble,
						pCh->pidFilterList[j].cwIndex);
				}
				for (j = 0 ; j < MAX_PID_FILTER_CB_NUM ; j++) {
					if (pCh->pidFilterListCB[j].used) {
						DMX_DBG_LOG(DGB_COLOR_GREEN"    PES_FILTER: index=%d,pid=%d(0x%x),type=%s(%d),cw_index=%d\n"DGB_COLOR_NONE,
							j,
							pCh->pidFilterListCB[j].pid, pCh->pidFilterListCB[j].pid,
							rtkdemux_get_pidtype_string(pCh->pidFilterListCB[j].pidType), pCh->pidFilterListCB[j].pidType,
							pCh->pidFilterListCB[j].cwIndex);
					}
				}
				for (j = 0; j < pCh->checkScrambleCount; j++) {
					const DEMUX_SCRAMBLE_CHECK_LIST_T* const entry = &pCh->scrambleList[j];
					if (pCh->scrambleList[j].bCheck) {
						DMX_DBG_LOG(
							DGB_COLOR_GREEN"    CHECK_SCRAMBLE_FILTER: index=%d,pid=%d(0x%x),type=%s(%d)\n"DGB_COLOR_NONE,
							j,
							entry->pid,
							entry->pid,
							rtkdemux_get_pidtype_string(entry->pidType),
							(int)entry->pidType
						);
					}
				}
				mutex_unlock(&pCh->mutex);
			}
		}
		DMX_DBG_LOG(DGB_COLOR_GREEN"==========================================================================================\n"DGB_COLOR_NONE);
	}
}

void rtkdemux_print_section_filter_list(void)
{
	int i, j;
	if (demux_device) {
		DMX_DBG_LOG(DGB_COLOR_GREEN"==========================================================================================\n"DGB_COLOR_NONE);
		DMX_DBG_LOG(DGB_COLOR_GREEN"<Filter List>\n"DGB_COLOR_NONE);

		for (i = 0 ; i < demux_device->chNum ; i++) {
			demux_channel *pCh = &demux_device->pChArray[i];
			if (pCh) {
				if (!pCh->isInit) {
					DMX_DBG_LOG(DGB_COLOR_GREEN"CH%d: isInit=%d\n"DGB_COLOR_NONE, i, pCh->isInit);
					continue;
				}
				DMX_DBG_LOG(DGB_COLOR_GREEN"CH%d: streaming=%d\n"DGB_COLOR_NONE, i, pCh->startStreaming);
				mutex_lock(&pCh->mutex);
				for (j = 0 ; j < MAX_SECTION_FILTER_NUM ; j++) {

					if (pCh->secListCB[j].ch != i || pCh->secListCB[j].used != 1)
						continue;

					DMX_DBG_LOG(DGB_COLOR_GREEN"    SEC_FILTER: index=%d,pid=%d(0x%x),crc_en=%d,one_shoot=%d,toggle_mode_en=%d\n"DGB_COLOR_NONE,
							j,
							pCh->secListCB[j].param.PID, pCh->secListCB[j].param.PID,
							pCh->secListCB[j].param.crc_en,
							pCh->secListCB[j].param.one_shoot,
							pCh->secListCB[j].param.toggle_mode_en);
					DMX_DBG_LOG(DGB_COLOR_GREEN"    SEC_FILTER: pRd=0x%x,pWr=0x%x,pBase=0x%lx,pLimit=0x%lx\n"DGB_COLOR_NONE,
							*pCh->secListCB[j].pRdPtr,
							*pCh->secListCB[j].pWrPtr,
							 (unsigned long)(uintptr_t)pCh->secListCB[j].pBufferLower,
							 (unsigned long)(uintptr_t)pCh->secListCB[j].pBufferUpper);
				}
				mutex_unlock(&pCh->mutex);
			}
		}
/*
		DMX_DBG_LOG("\n\033[1;32m<Section Map>\n"DGB_COLOR_NONE);
		mutex_lock(&demux_device->mutex);
		for (i = 0 ; i < SEC_FILTER_BUFFER_NUM ; i++) {
			if (!demux_device->secMap[i].occupied)
				continue;

			DMX_DBG_LOG(DGB_COLOR_GREEN"    SEC_MAP: index=%d,ch=%d,filter_idx=%d,virAddr=%p,phyAddr=%p,size=%u\n"DGB_COLOR_NONE,
						i,
						((int)demux_device->secMap[i].pContext) >> 8,
						((int)demux_device->secMap[i].pContext) & 0xff,
						demux_device->secMap[i].virAddr,
						demux_device->secMap[i].phyAddr,
						demux_device->secMap[i].size);
		}
		mutex_unlock(&demux_device->mutex);
*/
		DMX_DBG_LOG(DGB_COLOR_GREEN"==========================================================================================\n"DGB_COLOR_NONE);
	}

}

/* DEMUX_DBG_CMD_PRINT_CLOCK */
void rtkdemux_print_clock(void *ch_pointer)
{
	const static int64_t carry = 10000;
	static int64_t clock[DEMUX_CH_NUM] = {0};
	static int64_t prev_pcra[DEMUX_CH_NUM] = {0};
	static int64_t prev_misc[DEMUX_CH_NUM] = {0};
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	static int64_t prev_pcrb[DEMUX_CH_NUM] = {0};
	int64_t pcrb;
#endif
	int64_t pcra,misc;
	long clk_src;
	demux_channel *ch = (demux_channel *)ch_pointer;
	int ch_idx = rtkdemux_dbg_get_ch_idx(ch);

	if (ch_idx < 0)
		return;
	if (!ch->startStreaming || ch->bIsSDT)
		return;

	clk_src = REFCLK_GetClockMode(DEMUX_GetReferenceClock(ch));


	misc=CLOCK_GetPTS();
	switch (clk_src) {
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	case 2:
		pcrb=CLOCK_GetTPPTS(2);
		break;
#endif
	case 1:
	default:
		pcra=CLOCK_GetTPPTS(1);
		break;
	}

	switch (clk_src) {
	case 0: /* MISC_90KHz */
		if (misc-clock[ch_idx] > 3*DEMUX_CLOCKS_PER_SEC) {
			DMX_DBG_LOG(
				DGB_COLOR_GREEN"rtkdemux_debug:%d CH%d:(MISC)"
				" clk_src=%ld,MISC=%lld\n"DGB_COLOR_NONE,
				__LINE__, ch_idx, clk_src, misc
			);
			clock[ch_idx] = CLOCK_GetPTS();
		}
		break;
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	case 2:
		if (pcrb != prev_pcrb[ch_idx]) {
			if (misc-clock[ch_idx] > 3*DEMUX_CLOCKS_PER_SEC) {
				int64_t pcrb_diff = div_s64(carry*(pcrb-prev_pcrb[ch_idx]),misc-prev_misc[ch_idx]);
				DMX_DBG_LOG(
					DGB_COLOR_GREEN"rtkdemux_debug:%d CH%d:(PCRB) clk_src=%ld,MISC=%lld,"
					"PCRB=%lld, PCRB_DIFF=%lld/%lld\n"DGB_COLOR_NONE,
					__LINE__, ch_idx, clk_src, misc,
					pcrb, pcrb_diff, carry
				);
				clock[ch_idx] = CLOCK_GetPTS();
			}
			prev_pcrb[ch_idx] = pcrb;
		}
		break;
#endif
	case 1:
	default:
		if (pcra != prev_pcra[ch_idx]) {
			if (misc-clock[ch_idx] > 3*DEMUX_CLOCKS_PER_SEC) {
				int64_t pcra_diff = div_s64(carry*(pcra-prev_pcra[ch_idx]),misc-prev_misc[ch_idx]);
				DMX_DBG_LOG(
					DGB_COLOR_GREEN"rtkdemux_debug:%d CH%d:(PCRA) clk_src=%ld,MISC=%lld,"
					"PCRA=%lld, PCRA_DIFF=%lld/%lld\n"DGB_COLOR_NONE,
					__LINE__, ch_idx, clk_src, misc,
					pcra, pcra_diff, carry
				);
				clock[ch_idx] = CLOCK_GetPTS();
			}
			prev_pcra[ch_idx] = pcra;
		}
		break;
	}

	if (misc != prev_misc[ch_idx])
		prev_misc[ch_idx] = misc;

}

/* from rtkdemux_dump.c */
extern void DUMP_CreateFile(const char *filename, struct file **handle);
extern void DUMP_CloseFile(struct file *handle);
extern int DUMP_WriteFile(struct file *handle, char *buffer, unsigned int size, loff_t *pOffset);

/* dump ts */
struct {
	unsigned char enable;
	unsigned char flush_en;
	unsigned char do_flush;
	struct file *fp;
	loff_t pos;
	unsigned char filename[1024];
} rtkdemux_dump_ts[DEMUX_CH_NUM];

static void rtkdemux_dbg_dump_ts_stop(int tp_index)
{
	if (rtkdemux_dump_ts[tp_index].enable) {
		rtkdemux_dump_ts[tp_index].enable = false;
		if (rtkdemux_dump_ts[tp_index].fp != NULL && !IS_ERR(rtkdemux_dump_ts[tp_index].fp))
			DUMP_CloseFile(rtkdemux_dump_ts[tp_index].fp);
	}
	memset(&rtkdemux_dump_ts[tp_index], 0, sizeof(rtkdemux_dump_ts[tp_index]));
}
static void rtkdemux_dbg_dump_ts_start(int tp_index, const char* filename)
{
	DUMP_CreateFile(filename, &rtkdemux_dump_ts[tp_index].fp);
	if (rtkdemux_dump_ts[tp_index].fp == NULL || IS_ERR(rtkdemux_dump_ts[tp_index].fp)) {
		DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump ts start FAILED...\n"DGB_COLOR_NONE, __LINE__);
		rtkdemux_dump_ts[tp_index].fp = NULL;
		return;
	}

	rtkdemux_dump_ts[tp_index].enable = true;
}
void rtkdemux_dbg_dump_ts_flush_enable(int tp_index)
{
	if (!rtkdemux_dump_ts[tp_index].flush_en)
		return;

	rtkdemux_dump_ts[tp_index].do_flush = 1;
}
void rtkdemux_dbg_dump_ts(int tp_index, char *buffer, unsigned int size)
{
	static int64_t notify_clock[DEMUX_CH_NUM] = {0};
	if (rtkdemux_dump_ts[tp_index].enable) {
		int64_t clock ;
		if (rtkdemux_dump_ts[tp_index].flush_en && rtkdemux_dump_ts[tp_index].do_flush)
		{
			rtkdemux_dump_ts[tp_index].enable = false;
			if (rtkdemux_dump_ts[tp_index].fp != NULL && !IS_ERR(rtkdemux_dump_ts[tp_index].fp))
			DUMP_CloseFile(rtkdemux_dump_ts[tp_index].fp);
			rtkdemux_dump_ts[tp_index].fp = NULL;
			rtkdemux_dump_ts[tp_index].pos = 0;
			rtkdemux_dbg_dump_ts_start(tp_index, rtkdemux_dump_ts[tp_index].filename);
			rtkdemux_dump_ts[tp_index].do_flush = 0;
		}
		DUMP_WriteFile(rtkdemux_dump_ts[tp_index].fp, buffer, size, &rtkdemux_dump_ts[tp_index].pos);

		clock = CLOCK_GetPTS();
		if (clock-notify_clock[tp_index] > 5*DEMUX_CLOCKS_PER_SEC) {

			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump TP%d Processing...\n"DGB_COLOR_NONE, tp_index);
			notify_clock[tp_index] = clock;
		}
	}
}

/* dump es */
struct {
	unsigned char enable;
	unsigned char flush_en;
	struct file *fp;
	loff_t pos;
	unsigned char filename[1024];
} rtkdemux_dump_es[DEMUX_CH_NUM][NUMBER_OF_PINS];


static const char *rtkdemux_dbg_pin_name[NUMBER_OF_PINS] = { "VIDEO0", "AUDIO0", "VIDEO1", "AUDIO1" };
static void rtkdemux_dbg_dump_bitstream_stop(int tp_index, int pin_index)
{
	if (rtkdemux_dump_es[tp_index][pin_index].enable) {
		rtkdemux_dump_es[tp_index][pin_index].enable = false;
		if (rtkdemux_dump_es[tp_index][pin_index].fp != NULL && !IS_ERR(rtkdemux_dump_es[tp_index][pin_index].fp))
			DUMP_CloseFile(rtkdemux_dump_es[tp_index][pin_index].fp);
	}
	memset(&rtkdemux_dump_es[tp_index][pin_index], 0, sizeof(rtkdemux_dump_es[tp_index][pin_index]));
}
static void rtkdemux_dbg_dump_bitstream_start(int tp_index, int pin_index, const char* filename)
{
	DUMP_CreateFile(filename, &(rtkdemux_dump_es[tp_index][pin_index].fp));
	if (rtkdemux_dump_es[tp_index][pin_index].fp == NULL || IS_ERR(rtkdemux_dump_es[tp_index][pin_index].fp)) {
		DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump bitstream start FAILED...\n"DGB_COLOR_NONE, __LINE__);
		rtkdemux_dump_es[tp_index][pin_index].fp = NULL;
		return;
	}

	rtkdemux_dump_es[tp_index][pin_index].enable = true;
}
void rtkdemux_dbg_dump_bitstream_flush(int tp_index, int pin_index)
{
	if(rtkdemux_dump_es[tp_index][pin_index].flush_en == 0 || rtkdemux_dump_es[tp_index][pin_index].filename[0] == '\0')
		return;

	if (rtkdemux_dump_es[tp_index][pin_index].enable) {
		rtkdemux_dump_es[tp_index][pin_index].enable = false;
		if (rtkdemux_dump_es[tp_index][pin_index].fp != NULL && !IS_ERR(rtkdemux_dump_es[tp_index][pin_index].fp))
			DUMP_CloseFile(rtkdemux_dump_es[tp_index][pin_index].fp);
	}
	rtkdemux_dump_es[tp_index][pin_index].fp = NULL;
	rtkdemux_dump_es[tp_index][pin_index].pos = 0;
	rtkdemux_dbg_dump_bitstream_start(tp_index, pin_index, rtkdemux_dump_es[tp_index][pin_index].filename);

}
void rtkdemux_dbg_dump_bitstream(int tp_index, int pin_index, char *buffer, unsigned int size)
{
	static int64_t notify_clock[DEMUX_CH_NUM][NUMBER_OF_PINS] = {{0}};
	if (rtkdemux_dump_es[tp_index][pin_index].enable) {
		int64_t clock;
		DUMP_WriteFile(rtkdemux_dump_es[tp_index][pin_index].fp, buffer, size, &rtkdemux_dump_es[tp_index][pin_index].pos);

		clock = CLOCK_GetPTS();
		if (clock-notify_clock[tp_index][pin_index] > 5*DEMUX_CLOCKS_PER_SEC) {

			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump TP%d(%s) Processing...\n"DGB_COLOR_NONE, tp_index, rtkdemux_dbg_pin_name[pin_index]);
			notify_clock[tp_index][pin_index] = clock;
		}
	}
}

/* dump pes */
struct {
	unsigned char enable;
	unsigned char flush_en;
	struct file *fp01;
	loff_t pos01;
	unsigned char filename01[RTKDEMUX_MAX_DUMP_PES_FILE_NAME_LEN];
	unsigned int pid01;
	struct file *fp02;
	loff_t pos02;
	unsigned char filename02[RTKDEMUX_MAX_DUMP_PES_FILE_NAME_LEN];
	unsigned int pid02;
} rtkdemux_dump_pes[DEMUX_CH_NUM];


static void rtkdemux_dbg_dump_pes_stop(int tp_index)
{
	if (rtkdemux_dump_pes[tp_index].enable) {
		rtkdemux_dump_pes[tp_index].enable = false;

		if (rtkdemux_dump_pes[tp_index].fp01 != NULL && !IS_ERR(rtkdemux_dump_pes[tp_index].fp01)) {
			DUMP_CloseFile(rtkdemux_dump_pes[tp_index].fp01);
		}
		if (rtkdemux_dump_pes[tp_index].fp02 != NULL && !IS_ERR(rtkdemux_dump_pes[tp_index].fp02)) {
			DUMP_CloseFile(rtkdemux_dump_pes[tp_index].fp02);
		}
	}
	memset(&rtkdemux_dump_pes[tp_index], 0, sizeof(rtkdemux_dump_pes[tp_index]));
}
static void rtkdemux_dbg_dump_pes_start(int tp_index, const char *filename)
{
	int filelength = 0;

	if(filename)
	{
		sprintf(rtkdemux_dump_pes[tp_index].filename01, "%s_01",filename);
		filelength = strlen(rtkdemux_dump_pes[tp_index].filename01);
		rtkdemux_dump_pes[tp_index].filename01[filelength] = '\0';

		sprintf(rtkdemux_dump_pes[tp_index].filename02, "%s_02",filename);
		filelength = strlen(rtkdemux_dump_pes[tp_index].filename02);
		rtkdemux_dump_pes[tp_index].filename02[filelength] = '\0';

	}
	DUMP_CreateFile(rtkdemux_dump_pes[tp_index].filename01, &(rtkdemux_dump_pes[tp_index].fp01));
	if (rtkdemux_dump_pes[tp_index].fp01 == NULL || IS_ERR(rtkdemux_dump_pes[tp_index].fp01)) {
		DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump pes start FAILED...\n"DGB_COLOR_NONE, __LINE__);
		rtkdemux_dump_pes[tp_index].fp01 = NULL;
		return;
	}
	DUMP_CreateFile(rtkdemux_dump_pes[tp_index].filename02, &(rtkdemux_dump_pes[tp_index].fp02));
	if (rtkdemux_dump_pes[tp_index].fp02 == NULL || IS_ERR(rtkdemux_dump_pes[tp_index].fp02)) {
		DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump pes start FAILED...\n"DGB_COLOR_NONE, __LINE__);
		rtkdemux_dump_pes[tp_index].fp02 = NULL;
		DUMP_CloseFile(rtkdemux_dump_pes[tp_index].fp01);
		return;
	}
	rtkdemux_dump_pes[tp_index].enable = true;
}
void rtkdemux_dbg_dump_pes_flush(int tp_index)
{
	if (rtkdemux_dump_pes[tp_index].flush_en == 0 ||
		(rtkdemux_dump_pes[tp_index].filename01[0] == '\0' &&
		rtkdemux_dump_pes[tp_index].filename02[0] == '\0'))
		return;

	if (rtkdemux_dump_pes[tp_index].enable) {
		rtkdemux_dump_pes[tp_index].enable = false;

		if (rtkdemux_dump_pes[tp_index].fp01 != NULL && !IS_ERR(rtkdemux_dump_pes[tp_index].fp01)) {
			DUMP_CloseFile(rtkdemux_dump_pes[tp_index].fp01);
		}
		if (rtkdemux_dump_pes[tp_index].fp02 != NULL && !IS_ERR(rtkdemux_dump_pes[tp_index].fp02)) {
			DUMP_CloseFile(rtkdemux_dump_pes[tp_index].fp02);
		}
	}
	rtkdemux_dump_pes[tp_index].fp01 = NULL;
	rtkdemux_dump_pes[tp_index].fp02 = NULL;
	rtkdemux_dump_pes[tp_index].pos01 = 0;
	rtkdemux_dump_pes[tp_index].pos02 = 0;
	rtkdemux_dbg_dump_pes_start(tp_index, NULL);

}
void rtkdemux_dbg_dump_pes(int tp_index, char *buffer, unsigned int size, unsigned int dumppid)
{
	static int64_t notify_clock[DEMUX_CH_NUM] = {0};

	if (rtkdemux_dump_pes[tp_index].pid01 == 0)
		rtkdemux_dump_pes[tp_index].pid01 = dumppid;
	else if (rtkdemux_dump_pes[tp_index].pid02 == 0)
		rtkdemux_dump_pes[tp_index].pid02 = dumppid;

	if (rtkdemux_dump_pes[tp_index].enable) {
		int64_t clock;

		if (rtkdemux_dump_pes[tp_index].pid01 == dumppid) {
			DUMP_WriteFile(rtkdemux_dump_pes[tp_index].fp01, buffer, size, &rtkdemux_dump_pes[tp_index].pos01);
			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump pid:0x%x(%d) to %s...\n"DGB_COLOR_NONE, dumppid, dumppid, rtkdemux_dump_pes[tp_index].filename01);
		} else if (rtkdemux_dump_pes[tp_index].pid02 == dumppid) {
			DUMP_WriteFile(rtkdemux_dump_pes[tp_index].fp02, buffer, size, &rtkdemux_dump_pes[tp_index].pos02);
			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump pid:0x%x(%d) to %s...\n"DGB_COLOR_NONE, dumppid, dumppid, rtkdemux_dump_pes[tp_index].filename02);
		} else {
			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump pid:0x%x(%d) not exist...\n"DGB_COLOR_NONE, dumppid, dumppid);
		}

		clock = CLOCK_GetPTS();
		if (clock-notify_clock[tp_index] > 5*DEMUX_CLOCKS_PER_SEC) {

			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump TP%d Processing...\n"DGB_COLOR_NONE, tp_index);
			notify_clock[tp_index] = clock;
		}
	}
}

/* dump avsync info */
#define RTKDEMUX_DBG_DUMP_AVSYNC_INFO_FILENAME_MAX_LENGTH 64
struct {
	unsigned char enable;
	struct file *fp;
	loff_t pos;
	unsigned char filename[RTKDEMUX_DBG_DUMP_AVSYNC_INFO_FILENAME_MAX_LENGTH];
} rtkdemux_dump_avsync_info[DEMUX_CH_NUM];

static void rtkdemux_dbg_dump_avsync_info_stop(int tp_index)
{
	if (rtkdemux_dump_avsync_info[tp_index].enable) {
		rtkdemux_dump_avsync_info[tp_index].enable = false;
		if (rtkdemux_dump_avsync_info[tp_index].fp != NULL && !IS_ERR(rtkdemux_dump_avsync_info[tp_index].fp))
			DUMP_CloseFile(rtkdemux_dump_avsync_info[tp_index].fp);
	}
	memset(&rtkdemux_dump_avsync_info[tp_index], 0, sizeof(rtkdemux_dump_avsync_info[tp_index]));
}
static void rtkdemux_dbg_dump_avsync_info_start(int tp_index, const char* filename)
{
	char buffer[128];
	size_t null_terminated_index;
	rtkdemux_dbg_dump_avsync_info_stop(tp_index);
	DUMP_CreateFile(filename, &rtkdemux_dump_avsync_info[tp_index].fp);
	if (rtkdemux_dump_avsync_info[tp_index].fp == NULL || IS_ERR(rtkdemux_dump_avsync_info[tp_index].fp)) {
		DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump avsync info start FAILED...\n"DGB_COLOR_NONE, __LINE__);
		rtkdemux_dump_avsync_info[tp_index].fp = NULL;
		return;
	}

	null_terminated_index = strnlen(filename, RTKDEMUX_DBG_DUMP_AVSYNC_INFO_FILENAME_MAX_LENGTH-1);
	strncpy(rtkdemux_dump_avsync_info[tp_index].filename, filename, RTKDEMUX_DBG_DUMP_AVSYNC_INFO_FILENAME_MAX_LENGTH-1);
	rtkdemux_dump_avsync_info[tp_index].filename[null_terminated_index] = '\0';

	/* first line */
	snprintf(buffer, 128, "PCR,STC,RCD,AudioDemuxPTS,SubAudioDemuxPTS,VideoDemuxPTS,AudioSystemPTS,VideoSystemPTS,PcrOffset,MasterPTS,SystemPTS\n");
	DUMP_WriteFile(rtkdemux_dump_avsync_info[tp_index].fp, buffer, strlen(buffer), &rtkdemux_dump_avsync_info[tp_index].pos);

	rtkdemux_dump_avsync_info[tp_index].enable = true;
}
void rtkdemux_dbg_dump_avsync_info_reset(int tp_index)
{
	if (rtkdemux_dump_avsync_info[tp_index].enable)
		rtkdemux_dbg_dump_avsync_info_start(tp_index, rtkdemux_dump_avsync_info[tp_index].filename);
}
void rtkdemux_dbg_dump_avsync_info(int tp_index, RTKDEMUX_AVSYNC_INFO_T *info)
{
	static int64_t notify_clock[DEMUX_CH_NUM] = {0};
	if (rtkdemux_dump_avsync_info[tp_index].enable) {
		char buffer[256];
		int64_t clock;
		memset(buffer, 0, sizeof(buffer));
		snprintf(buffer, 256, "%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
			info->Pcr, info->Stc, info->Rcd, info->AudioDemuxPts, info->SubAudioDemuxPts, info->VideoDemuxPts,
			info->AudioSystemPts, info->VideoSystemPts, info->PcrOffset, info->MasterPTS, info->SystemPts);
		DUMP_WriteFile(rtkdemux_dump_avsync_info[tp_index].fp, buffer, strlen(buffer), &rtkdemux_dump_avsync_info[tp_index].pos);

		clock = CLOCK_GetPTS();
		if (clock-notify_clock[tp_index] > 5*DEMUX_CLOCKS_PER_SEC) {

			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump TP%d AvsyncInfo...\n"DGB_COLOR_NONE, tp_index);
			notify_clock[tp_index] = clock;
		}
	}
}
bool rtkdemux_dbg_dump_avsync_info_is_enabled(int tp_index)
{
	return rtkdemux_dump_avsync_info[tp_index].enable;
}

/* dump pts */
struct {
	unsigned char enable;
	struct file *fp;
	loff_t pos;
	int64_t pts[NUMBER_OF_PINS];
} rtkdemux_dump_pts[DEMUX_CH_NUM];

static void rtkdemux_dbg_dump_pts_stop(int tp_index)
{
	if (rtkdemux_dump_pts[tp_index].enable) {
		rtkdemux_dump_pts[tp_index].enable = false;
		if (rtkdemux_dump_pts[tp_index].fp != NULL && !IS_ERR(rtkdemux_dump_pts[tp_index].fp))
			DUMP_CloseFile(rtkdemux_dump_pts[tp_index].fp);
	}
	memset(&rtkdemux_dump_pts[tp_index], 0, sizeof(rtkdemux_dump_pts[tp_index]));
}
static void rtkdemux_dbg_dump_pts_start(int tp_index, const char* filename)
{
	char buffer[64];
	DUMP_CreateFile(filename, &rtkdemux_dump_pts[tp_index].fp);
	if (rtkdemux_dump_pts[tp_index].fp == NULL || IS_ERR(rtkdemux_dump_pts[tp_index].fp)) {
		DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump pts start FAILED...\n"DGB_COLOR_NONE, __LINE__);
		rtkdemux_dump_pts[tp_index].fp = NULL;
		return;
	}

	/* first line */
	snprintf(buffer, 64, "VideoPTS,AudioPTS,Video1PTS,Audio1PTS\n");
	DUMP_WriteFile(rtkdemux_dump_pts[tp_index].fp, buffer, strlen(buffer), &rtkdemux_dump_pts[tp_index].pos);

	rtkdemux_dump_pts[tp_index].enable = true;
}
void rtkdemux_dbg_dump_pts(int tp_index, int pin_index, int64_t pts)
{
	static int64_t notify_clock[DEMUX_CH_NUM] = {0};

	rtkdemux_dump_pts[tp_index].pts[pin_index] = pts;

	if (rtkdemux_dump_pts[tp_index].enable) {
		int64_t clock;
		char buffer[128];
		memset(buffer, 0, sizeof(buffer));
		snprintf(buffer, 128, "%lld,%lld,%lld,%lld\n",
			rtkdemux_dump_pts[tp_index].pts[VIDEO_PIN],
			rtkdemux_dump_pts[tp_index].pts[AUDIO_PIN],
			rtkdemux_dump_pts[tp_index].pts[VIDEO2_PIN],
			rtkdemux_dump_pts[tp_index].pts[AUDIO2_PIN]);
		DUMP_WriteFile(rtkdemux_dump_pts[tp_index].fp, buffer, strlen(buffer), &rtkdemux_dump_pts[tp_index].pos);

		clock = CLOCK_GetPTS();
		if (clock-notify_clock[tp_index] > 5*DEMUX_CLOCKS_PER_SEC) {

			DMX_DBG_LOG(DGB_COLOR_CYAN"Dump TP%d PTS...\n"DGB_COLOR_NONE, tp_index);
			notify_clock[tp_index] = clock;
		}
	}
}

/* set pcr offset */
static bool rtkdemux_dbg_set_pcroffset(INT64 pcroffset)
{
	if (demux_device) {
		int i;
		for (i = 0 ; i < demux_device->chNum ; i++)
			if (&demux_device->pChArray[i]) {
				demux_device->pChArray[i].pcrProcesser.pcrOffset = pcroffset;
				demux_device->pChArray[i].pcrProcesser.pcrDefaultOffset = pcroffset;
			}

		if (i != demux_device->chNum)
			return true;
	}

	return false;
}

/* force mastership */
AV_SYNC_MODE rtkdemux_dbg_force_mastership[DEMUX_CH_NUM];
static const char *rtkdemux_dbg_mastership_name[MASTERSHIP_NUM ] = { "PCR_MASTER", "AUDIO_MASTER", "VIDEO_ONLY", "FREE_RUN", "AUDIO_ONLY", "AUDIO_MASTER_AF" };
void rtkdemux_dbg_force_mastership_check(int tp_index, REFCLOCK* refClock, AV_SYNC_MODE *avSyncMode)
{
	if (rtkdemux_dbg_force_mastership[tp_index] >= 0 &&
		rtkdemux_dbg_force_mastership[tp_index] < MASTERSHIP_NUM) {
		static int64_t notify_clock[DEMUX_CH_NUM] = {0};
		int64_t clock = CLOCK_GetPTS();

		if (*avSyncMode != rtkdemux_dbg_force_mastership[tp_index]) {
			REFCLK_SetMasterShip(refClock, rtkdemux_dbg_force_mastership[tp_index]);
			*avSyncMode = rtkdemux_dbg_force_mastership[tp_index];
		}


		if (clock-notify_clock[tp_index] > 5*DEMUX_CLOCKS_PER_SEC) {

			DMX_DBG_LOG(DGB_COLOR_CYAN"ForceMastership: TP%d is now on %s\n"DGB_COLOR_NONE, tp_index, rtkdemux_dbg_mastership_name[rtkdemux_dbg_force_mastership[tp_index]]);
			notify_clock[tp_index] = clock;
		}
	}
}

/* print pts */
struct {
	unsigned char enable;
	struct file *fp;
	loff_t pos;
} rtkdemux_print_pts[DEMUX_CH_NUM];

static void rtkdemux_dbg_print_pts_stop(int tp_index)
{
	if (rtkdemux_print_pts[tp_index].enable) {
		rtkdemux_print_pts[tp_index].enable = false;
		if (rtkdemux_print_pts[tp_index].fp != NULL && !IS_ERR(rtkdemux_print_pts[tp_index].fp))
			DUMP_CloseFile(rtkdemux_print_pts[tp_index].fp);
	}
	memset(&rtkdemux_print_pts[tp_index], 0, sizeof(rtkdemux_print_pts[tp_index]));
}
static void rtkdemux_dbg_print_pts_start(int tp_index, const char* filename)
{
	DUMP_CreateFile(filename, &rtkdemux_print_pts[tp_index].fp);
	if (rtkdemux_print_pts[tp_index].fp == NULL || IS_ERR(rtkdemux_print_pts[tp_index].fp)) {
		DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d print pts start FAILED...\n"DGB_COLOR_NONE, __LINE__);
		rtkdemux_print_pts[tp_index].fp = NULL;
		return;
	}

	rtkdemux_print_pts[tp_index].enable = true;
}
void rtkdemux_dbg_print_pts(int tp_index, int pin_index, int64_t pts, unsigned char* WP)
{
	static char* pinName[] = {"VIDEO","AUDIO","VIDEO1","AUDIO1"};


	if (rtkdemux_print_pts[tp_index].enable) {

		char buffer[128];
		memset(buffer, 0, sizeof(buffer));
		snprintf(
			buffer, 128,
			"[Ch%d][%s] PTS = 0x%llx, WP = 0x%lx\n",
			tp_index, pinName[pin_index], pts, (unsigned long)(uintptr_t)WP
		);

		DUMP_WriteFile(rtkdemux_print_pts[tp_index].fp, buffer, strlen(buffer), &rtkdemux_print_pts[tp_index].pos);

	}
}
/*****************************************************************************/
/* Parse the value right after the character '=' */
static inline bool rtkdemux_dbg_parse_value(char *cmd_pointer, long long *parsed_data)
{
	if (kstrtoll(cmd_pointer, 0, parsed_data) == 0) {
		DMX_DBG_LOG("rtkdemux_debug:%d parsed_data=%lld\n",
			__LINE__, *parsed_data);
		return true;
	} else {
		DMX_DBG_LOG("rtkdemux_debug:%d parsing data failed. pCmd=%s\n",
			__LINE__, cmd_pointer);
		return false;
	}
}

static inline void rtkdemux_dbg_EXECUTE(const int cmd_index, char **cmd_pointer)
{
	static const char *delim = ", ";

	long long parsed_data = 0;

	int dump_en = -1, flush_en = 0 , pcrtack_en = -1;
	int tp_index = -1, pin_index = -1;

	char *token = NULL;
	int i = 0, j = 0;

	switch (cmd_index) {
	case DEMUX_DBG_CMD_LOG_LEVEL:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		rtkdemux_dbg_log_mask = (unsigned long)parsed_data;
		DMX_DBG_LOG("rtkdemux_dbg_log_level=0x%8lx\n",
			rtkdemux_dbg_log_mask);
		break;
	case DEMUX_DBG_CMD_SET_AUDIO_BUFFER_SIZE:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		rtkdemux_dbg_audio_buffer_size = (unsigned long)parsed_data;
		DMX_DBG_LOG("rtkdemux_dbg_audio_buffer_size=%lu\n",
			rtkdemux_dbg_audio_buffer_size);
		break;
	case DEMUX_DBG_CMD_SET_VIDEO_BUFFER_SIZE:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		rtkdemux_dbg_video_buffer_size = (unsigned long)parsed_data;
		DMX_DBG_LOG("rtkdemux_dbg_video_buffer_size=%lu\n",
			rtkdemux_dbg_video_buffer_size);
		break;
	case DEMUX_DBG_CMD_SET_PCR_OFFSET:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		if (rtkdemux_dbg_set_pcroffset(parsed_data))
			DMX_DBG_LOG("rtkdemux_dbg_set_pcroffset=%lld\n", parsed_data);
		break;
	case DEMUX_DBG_CMD_DONT_DELIVER_AUDIO:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		rtkdemux_dbg_nodemux_audio_en = (unsigned char)parsed_data;
		DMX_DBG_LOG("rtkdemux_dbg_nodemux_audio_en=%d\n",
			rtkdemux_dbg_nodemux_audio_en);
		break;
	case DEMUX_DBG_CMD_DONT_DELIVER_VIDEO:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		rtkdemux_dbg_nodemux_video_en = (unsigned char)parsed_data;
		DMX_DBG_LOG("rtkdemux_dbg_nodemux_video_en=%d\n",
			rtkdemux_dbg_nodemux_video_en);
		break;
	case DEMUX_DBG_CMD_DTV_FORCE_MASTERSHIP:
		{
			if (*cmd_pointer == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d force mastership command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}
			token = strsep(cmd_pointer, delim);
			if (token == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the mastership string.\n"DGB_COLOR_NONE, __LINE__);
				break;
			} else {
				int i = 0;
				int mastership;

				for (i = 0 ; i < MASTERSHIP_NUM ; i++) {
					if (rtkdemux_dbg_mastership_name[i] != NULL && strncasecmp(rtkdemux_dbg_mastership_name[i], token, strlen(rtkdemux_dbg_mastership_name[i])) == 0) {
						rtkdemux_dbg_force_mastership[tp_index] = i;
						break;
					}
				}

				if (i == MASTERSHIP_NUM) {
					if (strncmp("0", token, 1) == 0) {
						rtkdemux_dbg_force_mastership[tp_index] = -1;
						DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d force mastership stop: tp=%d\n"DGB_COLOR_NONE, __LINE__, tp_index);
						break;
					} else {
						DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse mastership.\n"DGB_COLOR_NONE, __LINE__);
						break;
					}
				}

				mastership = rtkdemux_dbg_force_mastership[tp_index];
				if( mastership < MASTERSHIP_NUM )
					DMX_DBG_LOG(
						DGB_COLOR_GREEN"rtkdemux_debug:%d force mastership: tp=%d, mastership=%s\n"DGB_COLOR_NONE,
					__LINE__, tp_index, rtkdemux_dbg_mastership_name[mastership]
				);
			}

			break;
		}
	case DEMUX_DBG_CMD_PRINT_IO:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		rtkdemux_dbg_printio_en = (unsigned char)parsed_data;
		DMX_DBG_LOG("rtkdemux_dbg_printio_en=%d\n",
			rtkdemux_dbg_printio_en);
		if (rtkdemux_dbg_printio_en == 0) {
			for (i = 0; i < DEMUX_CH_NUM; i++)
				rtkdemux_dbg_printio_read_count[i] = 0;
			for (i = 0; i < DEMUX_CH_NUM; i++)
				for (j = 0; j < NUMBER_OF_PINS; j++)
					rtkdemux_dbg_printio_deliver_count[i][j] = 0;
		}
		break;
	case DEMUX_DBG_CMD_SHOW_BUFFER_INFO:
		rtkdemux_dbg_show_buffer_info();
		break;
	case DEMUX_DBG_CMD_PRINT_DEMUX_TARGET:
		rtkdemux_print_demux_target();
		break;
	case DEMUX_DBG_CMD_PRINT_FILTER_LIST:
		rtkdemux_print_filter_list();
		break;
	case DEMUX_DBG_CMD_PRINT_SECTION_FILTER_LIST:
		rtkdemux_print_section_filter_list();
		break;
	case DEMUX_DBG_CMD_PRINT_CLOCK:
		rtkdemux_dbg_parse_value(*cmd_pointer, &parsed_data);
		rtkdemux_dbg_printclock_en = (unsigned char)parsed_data;
		DMX_DBG_LOG("rtkdemux_dbg_printclock_en=%d\n",
			rtkdemux_dbg_printclock_en);
		break;
	case DEMUX_DBG_CMD_DUMP_TS:
		{
			if (*cmd_pointer == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump ts command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &dump_en) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the dump ts enable flag.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}
			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			if (dump_en == 1) {
				char *pFileName = strsep(cmd_pointer, delim);
				int filelength = 0;
				if (pFileName == NULL) {
					DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse filename.\n"DGB_COLOR_NONE, __LINE__);
					break;
				}

				rtkdemux_dbg_dump_ts_stop(tp_index);
				rtkdemux_dbg_dump_ts_start(tp_index, pFileName);
				token = strsep(cmd_pointer, delim);
				if (token == NULL || kstrtoint(token, 0, &flush_en) != 0) rtkdemux_dump_ts[tp_index].flush_en = 0;
				else               rtkdemux_dump_ts[tp_index].flush_en = flush_en;

				filelength = strlen(pFileName);
				if((filelength+1) <= sizeof(rtkdemux_dump_ts[tp_index].filename))
				{
					strncpy(rtkdemux_dump_ts[tp_index].filename, pFileName, filelength);
					rtkdemux_dump_ts[tp_index].filename[filelength] = '\0';
				}
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d start to dump ts: dump_ts_en=%d, tp=%d, path=%s, flush = %d\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index, pFileName, rtkdemux_dump_ts[tp_index].flush_en);
			} else {
				rtkdemux_dbg_dump_ts_stop(tp_index);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d stop to dump ts: dump_ts_en=%d, tp=%d\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index);
			}

			break;
		}
	case DEMUX_DBG_CMD_DUMP_BITSTREAM:
		{
			if (*cmd_pointer == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump bitstream command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &dump_en) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the dump bitstream enable flag.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}
			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}
			token = strsep(cmd_pointer, delim);
			if (token == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse pin index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			} else {
				int i = 0;
				for (i = 0 ; i < NUMBER_OF_PINS ; i++) {
					if (rtkdemux_dbg_pin_name[i] != NULL && strncasecmp(rtkdemux_dbg_pin_name[i], token, strlen(rtkdemux_dbg_pin_name[i])) == 0) {
						pin_index = i;
						break;
					}
				}

				if (i == NUMBER_OF_PINS) {
					DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse pin index.\n"DGB_COLOR_NONE, __LINE__);
					break;
				}
			}

			if (dump_en == 1) {
				char *pFileName = strsep(cmd_pointer, delim);
				int filelength = 0;
				if (pFileName == NULL) {
					DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse filename.\n"DGB_COLOR_NONE, __LINE__);
					break;
				}

				rtkdemux_dbg_dump_bitstream_stop(tp_index, pin_index);
				rtkdemux_dbg_dump_bitstream_start(tp_index, pin_index, pFileName);
				token = strsep(cmd_pointer, delim);
				if (token == NULL || kstrtoint(token, 0, &flush_en) != 0) rtkdemux_dump_es[tp_index][pin_index].flush_en = 0;
				else               rtkdemux_dump_es[tp_index][pin_index].flush_en = flush_en;

				filelength = strlen(pFileName);
				//rtkdemux_dbg_dump_bitstream_filename[tp_index][pin_index] = dvr_malloc(filelength+1);
				if((filelength+1) <= sizeof(rtkdemux_dump_es[tp_index][pin_index].filename))
				{
					strncpy(rtkdemux_dump_es[tp_index][pin_index].filename, pFileName, filelength);
					rtkdemux_dump_es[tp_index][pin_index].filename[filelength] = '\0';
				}
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d start to dump bitstream: dump_ts_en=%d, tp=%d, pin=%s, path=%s, flush=%d\n"DGB_COLOR_NONE,
					__LINE__, dump_en, tp_index, rtkdemux_dbg_pin_name[pin_index], pFileName, rtkdemux_dump_es[tp_index][pin_index].flush_en);
			} else if (dump_en == 0) {
				rtkdemux_dbg_dump_bitstream_stop(tp_index, pin_index);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d stop to dump bitstream: dump_ts_en=%d, tp=%d, pin=%s\n"DGB_COLOR_NONE,
					__LINE__, dump_en, tp_index, rtkdemux_dbg_pin_name[pin_index]);
			}

			break;
		}
	case DEMUX_DBG_CMD_DUMP_AVSYNC_INFO:
		{
			if (*cmd_pointer == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump avsync info command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &dump_en) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the dump avsync info enable flag.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}
			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			if (dump_en == 1) {
				token = strsep(cmd_pointer, delim);
				if (token == NULL) {
					DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse filename.\n"DGB_COLOR_NONE, __LINE__);
					break;
				}

				rtkdemux_dbg_dump_avsync_info_start(tp_index, token);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d start to dump avsync info: dump_ts_en=%d, tp=%d, path=%s\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index, token);
			} else {
				rtkdemux_dbg_dump_avsync_info_stop(tp_index);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d stop to dump avsync info: dump_ts_en=%d, tp=%d\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index);
			}

			break;
		}
	case DEMUX_DBG_CMD_DUMP_PTS:
		{
			if (*cmd_pointer == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump pts command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &dump_en) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the dump pts enable flag.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			if (dump_en == 1) {
				token = strsep(cmd_pointer, delim);
				if (token == NULL) {
					DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse filename.\n"DGB_COLOR_NONE, __LINE__);
					break;
				}

				rtkdemux_dbg_dump_pts_stop(tp_index);
				rtkdemux_dbg_dump_pts_start(tp_index, token);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d start to dump pts: dump_ts_en=%d, tp=%d, path=%s\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index, token);
			} else {
				rtkdemux_dbg_dump_pts_stop(tp_index);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d stop to dump pts: dump_ts_en=%d, tp=%d\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index);
			}

			break;
		}
	case DEMUX_DBG_CMD_SET_PID:
		{
			int pid, type, dest;
			DEMUX_SET_PID_T set_pid;
			if (*cmd_pointer == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d setpid command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &pid) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse pid.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &type) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse pid type.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &dest) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse pes dest.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			if (demux_device && demux_device->pChArray) {
				demux_channel *pCh = &demux_device->pChArray[tp_index];

				if (pCh->startStreaming) {
					DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d set pid: ch=%d, pid=%d, type=%d, dest=%d\n"DGB_COLOR_NONE,  __LINE__, tp_index, pid, type, dest);
					set_pid.ch  = tp_index;
					set_pid.pid = pid;
					set_pid.pidType = type;
					set_pid.dest = dest;
					IOCTL_SetPID(&set_pid);
				}
			}

			break;
		}
	case DEMUX_DBG_CMD_PRINT_PTS:
	{
		if (*cmd_pointer == NULL) {
			DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d print pts command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
			break;
		}

		token = strsep(cmd_pointer, delim);
		if (token == NULL || kstrtoint(token, 0, &dump_en) != 0) {
			DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the print pts enable flag.\n"DGB_COLOR_NONE, __LINE__);
			break;
		}

		token = strsep(cmd_pointer, delim);
		if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
			DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
			break;
		}

		if (dump_en == 1) {
			token = strsep(cmd_pointer, delim);
			if (token == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse filename.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			rtkdemux_dbg_print_pts_stop(tp_index);
			rtkdemux_dbg_print_pts_start(tp_index, token);
			DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d start to print pts: dump_ts_en=%d, tp=%d, path=%s\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index, token);
		} else {
			rtkdemux_dbg_print_pts_stop(tp_index);
			DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d stop to print pts: dump_ts_en=%d, tp=%d\n"DGB_COLOR_NONE, __LINE__, dump_en, tp_index);
		}
		break;
	}
	case DEMUX_DBG_CMD_PCR_TRACK:
	{
		DEMUX_CHANNEL_T ch;
		demux_channel *pCh = NULL;
		if (*cmd_pointer == NULL) {
			DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d pcr track command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
			break;
		}

		token = strsep(cmd_pointer, delim);
		if (token == NULL || kstrtoint(token, 0, &pcrtack_en) != 0) {
			DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the pcr track enable flag.\n"DGB_COLOR_NONE, __LINE__);
			break;
		}

		token = strsep(cmd_pointer, delim);
		if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
			DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
			break;
		}

		/* demux_channel *pCh; */
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
		ch = (tp_index == 0) ? DEMUX_CH_A : DEMUX_CH_B;
#else
		ch = DEMUX_CH_A;
#endif


		if (demux_device && demux_device->pChArray)
			pCh = &demux_device->pChArray[ch];

		/* AndroidTV_Klocwork_0144665 - pCh might be used uninitialized in this function */
		if (pCh != NULL) {
			if (pcrtack_en == 1) {
				pCh->bPcrTrackEnable = 1;
				IOCTL_StartPCRRecovery(&ch);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d Start PCR_Tracking, tp=%d.\n"DGB_COLOR_NONE, __LINE__ , tp_index);
			} else {
				pCh->bPcrTrackEnable = 0;
				IOCTL_StopPCRRecovery(&ch);
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d Stop PCR_Tracking, tp=%d\n"DGB_COLOR_NONE, __LINE__, tp_index);
			}
		}
		break;
	}
	case DEMUX_DBG_CMD_DUMP_PES:
		{
			if (*cmd_pointer == NULL) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d dump pes command is incorrect.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &dump_en) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse the dump pes enable flag.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}
			token = strsep(cmd_pointer, delim);
			if (token == NULL || kstrtoint(token, 0, &tp_index) != 0) {
				DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse tp index.\n"DGB_COLOR_NONE, __LINE__);
				break;
			}

			if (dump_en == 1) {
				char *pFileName = strsep(cmd_pointer, delim);
				if (pFileName == NULL) {
					DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed to parse filename.\n"DGB_COLOR_NONE, __LINE__);
					break;
				}
				if((strlen(pFileName) + 4) > RTKDEMUX_MAX_DUMP_PES_FILE_NAME_LEN){
					DMX_DBG_LOG(DGB_COLOR_RED"rtkdemux_debug:%d failed for filename length.\n"DGB_COLOR_NONE, __LINE__);
					break;
				}
				rtkdemux_dbg_dump_pes_stop(tp_index);
				rtkdemux_dbg_dump_pes_start(tp_index, pFileName);
				token = strsep(cmd_pointer, delim);
				if (token == NULL || kstrtoint(token, 0, &flush_en) != 0) rtkdemux_dump_pes[tp_index].flush_en = 0;
				else			   rtkdemux_dump_pes[tp_index].flush_en = flush_en;

				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d start to dump pes: dump_pes_en=%d, tp=%d, path=%s & %s, flush=%d\n"DGB_COLOR_NONE,
					__LINE__, dump_en, tp_index, rtkdemux_dump_pes[tp_index].filename01, rtkdemux_dump_pes[tp_index].filename02, rtkdemux_dump_pes[tp_index].flush_en);
			} else if (dump_en == 0) {
				rtkdemux_dbg_dump_pes_stop(tp_index);
				DMX_DBG_LOG(DGB_COLOR_GREEN"rtkdemux_debug:%d stop to dump pes: dump_pes_en=%d, tp=%d \n"DGB_COLOR_NONE,
					__LINE__, dump_en, tp_index);
			}
			break;
		}
	default:
		DMX_DBG_LOG("rtkdemux_debug:%d unknown command.\n", __LINE__);
	}
}

static int rtkdemux_proc_write(
	struct file *file,
	const char __user *buf,
	size_t count,
	loff_t *ppos)
{
	int cmd_index;
	char *cmd_pointer = NULL;
	char str[RTKDEMUX_MAX_CMD_LENGTH] = {0};
	if (buf == NULL) {
		DMX_DBG_LOG("rtkdemux_debug:%d buf=%p\n", __LINE__, buf);
		return -EFAULT;
	}
	if (count > RTKDEMUX_MAX_CMD_LENGTH - 1)
		count = RTKDEMUX_MAX_CMD_LENGTH - 1;
	if (copy_from_user(str, buf, RTKDEMUX_MAX_CMD_LENGTH - 1)) {
		DMX_DBG_LOG("rtkdemux_debug:%d copy_from_user failed! (buf=%p, count=%u)\n",
			__LINE__, buf, count);
		return -EFAULT;
	}

	if (count > 0)
		str[count-1] = '\0';
	DMX_DBG_LOG("rtkdemux_debug:%d >>%s\n", __LINE__, str);


	for (cmd_index = 0; cmd_index < DEMUX_DBG_CMD_NUMBER; cmd_index++) {
		if (strncmp(str,
				rtkdemux_cmd_str[cmd_index],
				strlen(rtkdemux_cmd_str[cmd_index])) == 0)
			break;
	}


	if (cmd_index < DEMUX_DBG_CMD_NUMBER) {
		cmd_pointer = &str[strlen(rtkdemux_cmd_str[cmd_index])];
	}

	/* The extern definition is at rtkdemux_common.h */
	if (console_printk[0] == 0)
		console_printk[0] = 1;
	rtkdemux_dbg_EXECUTE(cmd_index, &cmd_pointer);

	return count;
}


static int rtkdemux_proc_read(
	struct file *file,
	char __user *buf,
	size_t count,
	loff_t *ppos)
{
	char *str = "Rtkdemux kernel driver debug message\n";
	int len = strlen(str);
	if (copy_to_user(buf, str, len)) {
		DMX_DBG_LOG("rtkdemux_debug:%d Copy proc data to user space failed\n",
			__LINE__);
		return 0;
	}

	if (*ppos == 0)
		*ppos += len;
	else
		len = 0;
	return len;
}

/*****************************************************************************/

static const struct file_operations rtkdemux_proc_fops = {
	.owner = THIS_MODULE,
	.write = rtkdemux_proc_write,
	.read = rtkdemux_proc_read,
};

struct proc_dir_entry *rtkdemux_proc_dir;
struct proc_dir_entry *rtkdemux_proc_entry;

bool demux_init_debug_proc(void)
{
	int i;

	if (rtkdemux_proc_dir == NULL && rtkdemux_proc_entry == NULL) {
		rtkdemux_proc_dir = proc_mkdir(RTKDEMUX_PROC_DIR , NULL);

		if (rtkdemux_proc_dir != NULL) {
			rtkdemux_proc_entry =
				proc_create(RTKDEMUX_PROC_ENTRY, 0666,
					rtkdemux_proc_dir, &rtkdemux_proc_fops);

			if (rtkdemux_proc_entry == NULL) {
				proc_remove(rtkdemux_proc_dir);
				rtkdemux_proc_dir = NULL;
				DMX_DBG_LOG("failed to get proc entry for %s/%s\n",
					RTKDEMUX_PROC_DIR, RTKDEMUX_PROC_ENTRY);
				return false;
			}
		} else {
			DMX_DBG_LOG("create rtkdemux dir proc entry (%s) failed\n",
				RTKDEMUX_PROC_DIR);
			return false;
		}
	}

	/* init rtkdemux_dbg_force_mastership to -1 */
	for (i = 0 ; i < DEMUX_CH_NUM ; i++)
		rtkdemux_dbg_force_mastership[i] = -1;

	return true;
}

void demux_uninit_debug_proc(void)
{
	if (rtkdemux_proc_entry) {
		proc_remove(rtkdemux_proc_entry);
		rtkdemux_proc_entry = NULL;
	}

	if (rtkdemux_proc_dir) {
		proc_remove(rtkdemux_proc_dir);
		rtkdemux_proc_dir = NULL;
	}
}
