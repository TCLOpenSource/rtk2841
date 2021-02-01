/******************************************************************************
 *
 *   Realtek Demux driver
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author bonds.lu@realtek.com
 *
 *****************************************************************************/
#include <generated/autoconf.h>
#include <linux/delay.h>
#include <linux/freezer.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/pageremap.h>
#include <linux/sched.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
    #include <linux/suspend.h>
#endif
#include "rtkdemux.h"
#include "rtkdemux_pvr.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_register.h"
#include "rtkdemux_specialhandling.h"
#include "rtkdemux_buf.h"
#include "rtkdemux_MW.h"
#include <rtk_kdriver/RPCDriver.h>

#include <rtk_kdriver/rpc/VideoRPC_System.h>
#include <asm/outercache.h>
#include <rtk_kdriver/rtk_vdec.h>

#ifndef abs64
#define abs64 abs
#endif

#define FLUSH_BEFORE_SYNC_WP
#define TIMEOUT_CHECK_DEMUX_INFO 5

/*extern void rtk_flush_range(unsigned int phys_addr, size_t size) ;*/
/*extern void rtk_inv_range  (unsigned int phys_addr, size_t size) ;*/

extern void rtk_flush_range (const void *, const void *);
extern void rtk_inv_range   (const void *, const void *);

extern unsigned long smd_memcpy(unsigned long addrDst, unsigned long addrSrc, int len) ;
extern bool smd_checkFinish(uint64_t handle);
extern bool smd_waitComplete(uint64_t handle, unsigned long timeout, uint64_t *hwCnt) ;
extern void rtkaudio_send_string(const char* pattern, int length);
void Demux_Flush(demux_channel *pCh, int target);
void ParsePCR(demux_channel *pCh, unsigned char *pTsPacket);
int DEMUX_EVENT_FlushVideo(demux_channel *pCh, DECODE_MODE decMode, int pin);
int DEMUX_EVENT_FlushAudio(demux_channel *pCh, int pin);
int DEMUX_EVENT_AudioNewFormat(demux_channel *pCh, int pin, DEMUX_AUDIO_DEC_T audioFormat, long privateInfo[8]);
void DEMUX_EVENT_FlushTPBuffer(demux_channel *pCh);
void DEMUX_UpdatePinInfo(demux_channel *pCh, char bVideoPin);
void DEMUX_CheckPrintDemuxInfo(demux_channel *pCh);

#define PES_HEADER_MIN_SIZE  (9)
#define PRELOAD_STEP         (4)
#define DMX_WARNING(x__)     do { dmx_warn x__; } while (false)

#define DMX_WARNING_CC(x__)                                                   \
do {                                                                          \
    static int64_t CCFirstPrintPTS__ = 0;                                     \
    static int     CCPrintCount__    = 0;                                     \
    if (CCPrintCount__ < 10) {                                                \
        CCPrintCount__++;                                                     \
        DMX_WARNING(x__);                                                     \
    }                                                                         \
    if (abs64(CLOCK_GetPTS() - CCFirstPrintPTS__) > 3*DEMUX_CLOCKS_PER_SEC) { \
        CCPrintCount__ = 0;                                                   \
        CCFirstPrintPTS__ = CLOCK_GetPTS();                                   \
    }                                                                         \
} while (false)

#define DMX_LUMPSUM_INIT()                            \
do {                                                  \
    pCh->lumpsumLoopCount = pCh->lumpsumErrCount = 0; \
} while (false)

#define DMX_LUMPSUM_ADD(msg__)                       \
do {                                                 \
    if (pCh->lumpsumErrCount >= 256)                 \
        DMX_LUMPSUM_REPORT();                        \
    pCh->lumpsumMsg[pCh->lumpsumErrCount] = (msg__); \
    pCh->lumpsumErrCount++;                          \
} while (false)

#define DMX_LUMPSUM_REPORT()                                                     \
do {                                                                             \
    if (pCh->lumpsumErrCount > 0) {                                              \
        int i, repeat = 1;                                                       \
        dmx_crit(                                                                \
            "*********** Demux Lumpsum Err Report CH%d (%d / %d) ***********\n", \
            pCh->tunerHandle, pCh->lumpsumErrCount, pCh->lumpsumLoopCount        \
        );                                                                       \
        for (i = 0; i < pCh->lumpsumErrCount; i++) {                             \
            if (i < pCh->lumpsumErrCount-1 &&                                    \
                pCh->lumpsumMsg[i] == pCh->lumpsumMsg[i+1]) {                    \
                repeat++;                                                        \
                continue;                                                        \
            }                                                                    \
            dmx_crit("Err: '%s' (%d times)\n", pCh->lumpsumMsg[i], repeat);      \
            repeat = 1;                                                          \
        }                                                                        \
    }                                                                            \
    pCh->lumpsumErrCount = 0;                                                    \
    if (pCh->lumpsumLoopCount < 1024)                                            \
        pCh->lumpsumLoopCount++;                                                 \
} while (false)

#define DMX_MEMCPY(dst__, src__, len__)  memcpy(dst__, src__, len__)
#define DMX_PRELOAD(ptr__, size__)       do { } while (false)

#define IS_OFF_SYNC(p__)         ( (p__)[0] != 0x47      )
#define PID(p__)                 (((((int)(p__)[1]) & 0x1F) << 8) | (p__)[2])
#define IS_TRANSPORT_ERROR(p__)  (((p__)[1] >> 7) & 0x01 )  // transport error
#define IS_START_UNIT(p__)       (((p__)[1] &  0x40) != 0)
#define HAS_PAYLOAD(p__)         (((p__)[3] &  0x10) != 0)
#define HAS_AF(p__)              (((p__)[3] &  0x20) != 0)
#define CONTI_COUNT(p__)         ( (p__)[3] &  0x0F      )
#define AF_LENGTH(p__)           ( (p__)[4]              )
#define IS_DISCONTI(p__)         (((p__)[5] &  0x80) != 0)
#define HAS_PCR(p__)             (((p__)[5] &  0x10) != 0)
#define PCR(p__)                 ((((int64_t)(p__)[6]) << 25) | (((int)(p__)[7]) << 17) | (((int)(p__)[8]) << 9) | (((int)(p__)[9]) << 1) | (((p__)[10]>>7) & 0x1))

#define DMX_DO_ACTION_ONCE_EVERY(duration__, statements__) \
do {                                                       \
    static int64_t last__    = 0;                          \
    const  int64_t current__ = CLOCK_GetPTS();             \
    const  int64_t passed__  = abs64(current__ - last__);  \
    if ((duration__) <= passed__) {                        \
        { statements__ }                                   \
        last__ = current__;                                \
    }                                                      \
} while (false)

#ifdef ENABLE_SCRAMBLE_PES_HEADER
    #define HAS_PACKET_START_CODE(p__)  (((p__)[0] == 0x00 && (p__)[1] == 0x00 && (p__)[2] == 0x01) || ((p__)[0] == 0x00 && (p__)[1] == 0x23 && (p__)[2] == 0x79))
#else
    #define HAS_PACKET_START_CODE(p__)  ( (p__)[0] == 0x00 && (p__)[1] == 0x00 && (p__)[2] == 0x01)
#endif

#define IS_SCRAMBLE(p__)                 (((p__)[6] & 0x30) != 0)
#define HAS_TRANSPORT_PRIVATE_DATA(p__)  (((p__)[5] & 0x02) != 0)
#define IS_RTKPVR(p__)                   ( (p__)[7] == 'R' && (p__)[8] == 'T' && (p__)[9] == 'K' && (p__)[10] == 'P' && (p__)[11] == 'V' && (p__)[12] == 'R' && (p__)[13] == 'S' && (p__)[14] == 'T' && (p__)[15] == 'C')

#define AD_version_text_tag(p__)    ((p__)[ 6])
#define AD_fade_byte(p__)           ((p__)[ 7])
#define AD_pan_byte(p__)            ((p__)[ 8])
#define AD_gain_byte_center(p__)    ((p__)[ 9])
#define AD_gain_byte_front(p__)     ((p__)[10])
#define AD_gain_byte_surround(p__)  ((p__)[11])

const char *rtkdemux_outputNames[NUMBER_OF_PINS] = {
    "VIDEO0",
    "AUDIO0",
    "VIDEO1",
    "AUDIO1",
};

#define RELEASE_TP_BUFFER()                      \
do {                                             \
    if (pCh->pTPRelase && pCh->TPReleaseSize) {  \
        RHAL_TPReleaseData(                      \
            pCh->tunerHandle,                    \
            pCh->pTPRelase + pCh->phyAddrOffset, \
            pCh->TPReleaseSize                   \
        );                                       \
        pCh->pTPRelase = NULL;                   \
        pCh->TPReleaseSize = 0;                  \
    }                                            \
} while (false)

/* Mac3 */
#define MIS_CLK90K_TM_LO_reg    SCPU_CLK90K_LO_reg
#define MIS_CLK90K_TM_HI_reg    SCPU_CLK90K_HI_reg


unsigned long DEMUX_reverseInteger(unsigned long value)
{
	unsigned long b0 =  value & 0x000000ff;
	unsigned long b1 = (value & 0x0000ff00) >> 8;
	unsigned long b2 = (value & 0x00ff0000) >> 16;
	unsigned long b3 = (value & 0xff000000) >> 24;

	return (b0 << 24) | (b1 << 16) | (b2 << 8) | b3 ;
}
unsigned long long DEMUX_reverseLongInteger(unsigned long long value)
{
	unsigned long long ret;
	unsigned char *des, *src;
	src = (unsigned char *)&value;
	des = (unsigned char *)&ret;
	des[0] = src[7];
	des[1] = src[6];
	des[2] = src[5];
	des[3] = src[4];
	des[4] = src[3];
	des[5] = src[2];
	des[6] = src[1];
	des[7] = src[0];
	return ret;
}
void DEMUX_IPCCopyMemory(char *des, char *src, unsigned long len)
{
	unsigned long i ;
	unsigned long *psrc, *pdes ;

	if ((((int)src & 0x3) != 0) || (((int)des & 0x3) != 0) || ((len & 0x3) != 0))
		dmx_err("error in pli_IPCCopyMemory()...\n") ;

	for (i = 0 ; i < len ; i += 4) {
		psrc = (unsigned long *)&src[i];
		pdes = (unsigned long *)&des[i];
		*pdes = DEMUX_reverseInteger(*psrc) ;
		/*        printk("%x, %x...\n", src[i], des[i]);*/
	}
}

inline void DEMUX_flushMemory(unsigned char *pSrc, unsigned char *pSrcPhy, int bytes)
{
	if (demux_device->disableCache)
		return ;

	rtk_flush_range  (pSrc, pSrc + bytes) ;
	outer_flush_range((phys_addr_t)pSrcPhy, (phys_addr_t)pSrcPhy + bytes) ;
}
inline uint64_t DEMUX_ddrCopy(void *dest, void *src, long size)
{
	return smd_memcpy(
		(uintptr_t)dest,
		(uintptr_t)src,
		size
	);
}
inline long DEMUX_checkTaskCompletion(uint64_t serialNumber)
{
	static const unsigned long timeout = 100;

	uint64_t unused;
	while (smd_waitComplete(0, timeout, &unused) == false) {
		dmx_crit("Demux: waitComplete more than %lu ms\n", timeout);
	}

	return 1;
}

inline int DeliverInBandCommand(DEMUX_BUF_PIN_T *pPinInfo, unsigned char *Data, long Size, unsigned long phyWr)
{
	unsigned char *WP;
	WP = (unsigned char *)(phyWr - pPinInfo->phyAddrOffset) ;
	if (phyWr + Size > (unsigned long)pPinInfo->pBufferUpper) { /* wrap-around */
		unsigned int space = (unsigned int)pPinInfo->pBufferUpper - phyWr ;
		DEMUX_IPCCopyMemory (WP, Data, space) ;
		DEMUX_IPCCopyMemory (pPinInfo->pBufferLower - pPinInfo->phyAddrOffset, Data + space, Size - space) ;
	} else {
		DEMUX_IPCCopyMemory (WP, Data, Size) ;
	}

	phyWr += Size ;
	if (phyWr >= (unsigned long)pPinInfo->pBufferUpper)
		phyWr -= (unsigned long)(pPinInfo->pBufferUpper - pPinInfo->pBufferLower) ;
	*pPinInfo->pWrPtr = DEMUX_reverseInteger(phyWr) ;

	return 0 ;
}
/*
*   checkfilterCount
*   return: |8bit|8bit|8bit|8bit|
*           |filter|PES|scramblecheck|section|
*           0   :no filter;
*           -1 : error
*/
int DEMUX_checkFilterCount(demux_channel *channel)
{
    int ret = 0, j = 0;
    int count = 0;
    //filter
    ret = (channel->pidFilterCount& 0xff) <<24;
    //pes
    count  = 0;
    for(j =0;j <MAX_PID_FILTER_CB_NUM ; j++)
    {
        if (channel->pidFilterListCB[j].used)
        {
            count ++;
        }
    }
    ret  = ret |((count &0xff) << 16);
    //scramblelist
    ret  = ret |((channel->checkScrambleCount &0xff) << 8);
    //section
    count  = 0;
    for(j =0;j < MAX_SECTION_FILTER_NUM ; j++)
    {
        if (channel->secListCB[j].used)
        {
            count ++;
        }
    }
    ret  = ret |((count &0xff));
    return ret;
}
int DEMUX_GetSecIndex(demux_channel *channel)
{
    int i;
    mutex_lock(&channel->section_mutex);
    for (i = 0 ; i < MAX_SECTION_FILTER_NUM ; i++) {
        if (!channel->secListCB[i].used) {
            mutex_unlock(&channel->section_mutex);
            return i;
        }
    }

    mutex_unlock(&channel->section_mutex);
    return -1;
}

void DEMUX_FreeSecIndex(demux_channel *channel, unsigned char index)
{
    void *context = (void *)((channel->tunerHandle << 8) | index) ;
    mutex_lock(&channel->section_mutex);
    if (channel->secListCB[index].used) {
        DEMUX_FreeSecRingBuffer(
			context,
			channel->secListCB[index].firstBufIndex
		);

        channel->secListCB[index].used = 0;
    }
    mutex_unlock(&channel->section_mutex);
}

int DEMUX_GetSecRingBuffer(void *pContext, size_t count)
{
	int i;
	size_t acquired;
	int firstIndex, lastIndex, preIndex, curIndex;
    mutex_lock(&demux_device->mutex);

    if ((demux_device->secBufCnt + count) > SEC_FILTER_BUFFER_UNIT_CNT) {
        mutex_unlock(&demux_device->mutex) ;
        dmx_err("[%s %d] section buffer is enough(used %d, new %d)!!\n", __func__, __LINE__, demux_device->secBufCnt, count);
        return -1;
    }

    acquired = 0;

    firstIndex = -1, lastIndex = -1, preIndex = -1, curIndex = -1;
    // total size < 8*32K(8 = count), search from head
    if (count < 8) {
        for (i = 0; i < SEC_FILTER_BUFFER_UNIT_CNT; i++) {
            if (!demux_device->secMap[i].occupied) {

                demux_device->secBufCnt++;
                demux_device->secMap[i].occupied = 1;
                demux_device->secMap[i].pContext = pContext;

                if (firstIndex < 0)
                    firstIndex = i;

                preIndex = curIndex;
                curIndex = i;

                if (preIndex >= 0) {
                    demux_device->secMap[preIndex].nextBufIndex = curIndex;
                }

                acquired++;
                if (acquired == count) {
                    demux_device->secMap[curIndex].nextBufIndex = firstIndex;
                    lastIndex = curIndex;
                    break;
                }
            }
        }
    // search from tail
    } else {
        for (i = SEC_FILTER_BUFFER_UNIT_CNT-1 ; i >= 0 ; i--) {
            if (!demux_device->secMap[i].occupied) {

                demux_device->secBufCnt++;
                demux_device->secMap[i].occupied = 1;
                demux_device->secMap[i].pContext = pContext;

                if (lastIndex < 0)
                    lastIndex = i;

                preIndex = curIndex;
                curIndex = i;

                if (preIndex >= 0) {
                    demux_device->secMap[curIndex].nextBufIndex = preIndex;
                }

                acquired++;
                if (acquired == count) {
                    firstIndex = i;
                    demux_device->secMap[lastIndex].nextBufIndex = firstIndex;
                    break;
                }
            }
        }
    }

    if (acquired == count) {
        mutex_unlock(&demux_device->mutex);
        return (firstIndex << 16) | lastIndex;
    }

    // error occurs
    for (i = 0; i < SEC_FILTER_BUFFER_UNIT_CNT; i++) {
        if (demux_device->secMap[i].occupied && pContext == demux_device->secMap[i].pContext) {
            demux_device->secMap[i].occupied = 0;
            demux_device->secBufCnt--;
        }
    }
    mutex_unlock(&demux_device->mutex);

    dmx_err("[%s %d] something wrong, need debugging!! (requested %zu, gotten %zu)\n", __func__, __LINE__, count, acquired);
    return -1;
}

void DEMUX_FreeSecRingBuffer(void *pContext, size_t count)
{
    size_t released = count;

    mutex_lock(&demux_device->mutex) ;
    for (;;) {
        if (demux_device->secMap[released].occupied &&
            pContext == demux_device->secMap[released].pContext) {

            demux_device->secMap[released].occupied = 0;
            demux_device->secBufCnt--;

            released = demux_device->secMap[released].nextBufIndex;
            if (released == count) {
                mutex_unlock(&demux_device->mutex);
                return;
            }
        } else {
            mutex_unlock(&demux_device->mutex);

            dmx_err("[%s %d] free sec buffer fail!\n", __func__, __LINE__);
            return;
        }
    }

    // should never reach here
    mutex_unlock(&demux_device->mutex);
}

int DEMUX_SendAudioDesc(AUDIO_AD_INFO *pAdInfo)
{
	struct AUDIO_CONFIG_COMMAND {
		long msgID;
		unsigned long value[15];
	};

	DEMUX_BUF_T adBuf;
	unsigned long ret;
	struct AUDIO_CONFIG_COMMAND *pConfig;

	DEMUX_BUF_AllocBuffer(&adBuf, sizeof(struct AUDIO_CONFIG_COMMAND), 0, 1);
	if (adBuf.virAddr == 0)
	{
		dmx_err("[%s %d] out of memory\n", __func__, __LINE__);
		return -1;
	}

	pConfig = (struct AUDIO_CONFIG_COMMAND *)adBuf.virAddr;
	pConfig->msgID = DEMUX_reverseInteger(74); /* AUDIO_CONFIG_CMD_AD_DESCRIPTOR */
	pConfig->value[0] = DEMUX_reverseInteger(pAdInfo->AD_fade_byte);
	pConfig->value[1] = DEMUX_reverseInteger(pAdInfo->AD_pan_byte);
	pConfig->value[2] = DEMUX_reverseInteger(pAdInfo->AD_gain_byte_center);
	pConfig->value[3] = DEMUX_reverseInteger(pAdInfo->AD_gain_byte_front);
	pConfig->value[4] = DEMUX_reverseInteger(pAdInfo->AD_gain_byte_surround);

	dmx_dbg("[%s %d] send_rpc_command start\n", __func__, __LINE__);
	dmx_dbg(
		"[%s %d] msgID = 0x%lx"
		", value[0] = 0x%lx, value[1] = 0x%lx, value[2] = 0x%lx"
		", value[3] = 0x%lx, value[4] = 0x%lx\n",
		__func__, __LINE__, (unsigned long)pConfig->msgID,
		pConfig->value[0], pConfig->value[1], pConfig->value[2],
		pConfig->value[3], pConfig->value[4]
	);
	if (send_rpc_command(RPC_AUDIO, 0x204, adBuf.phyAddr, adBuf.size, &ret) == RPC_FAIL)
		dmx_err("[%s %d] RPC fail\n", __func__, __LINE__);

	dmx_dbg("[%s %d] send_rpc_command end\n", __func__, __LINE__);
	DEMUX_BUF_FreeBuffer(&adBuf);
	return 0;
}
int DeliverPrivateInfo(demux_channel *pCh, DEMUX_BUF_PIN_T *pPinInfo, int infoId, char *pInfo, int length, DEMUX_BUF_PIN_T *pBSPinInfo)
{
	int res = -1 ;
	if (pCh == NULL || pPinInfo== NULL )
	{
		dmx_err("%s, %d, Param Check FAIL \n", __func__, __LINE__);
		return -1;
	}
	while (pCh->state == DEMUX_STATE_RUNNING && pPinInfo->pRBH) {
		long writableSize ;
		unsigned long phyWr, phyRd ;
		phyWr = DEMUX_reverseInteger(*pPinInfo->pWrPtr) ;
		phyRd = DEMUX_reverseInteger(*pPinInfo->pRdPtr) ;
		if (phyWr < (uintptr_t)pPinInfo->pBufferLower
			|| phyWr > (uintptr_t)pPinInfo->pBufferUpper
			|| phyRd < (uintptr_t)pPinInfo->pBufferLower
			|| phyRd > (uintptr_t)pPinInfo->pBufferUpper) {
			dmx_err(
				"func %s, line %d, infoId %d"
				", r 0x%lx, w 0x%lx"
				", l 0x%lx, u 0x%lx\n",
				__func__, __LINE__, infoId,
				phyRd, phyWr,
				(unsigned long)(uintptr_t)pPinInfo->pBufferLower,
				(unsigned long)(uintptr_t)pPinInfo->pBufferUpper
			);
			return -1;
		}

		/*if(infoId == PRIVATEINFO_AUDIO_AD_INFO)
			return DEMUX_SendAudioDesc((AUDIO_AD_INFO *)pInfo);
*/
		writableSize = BS_DISTANCE(phyWr, phyRd, pPinInfo->pBufferLower, pPinInfo->pBufferUpper) - 1 ;
		if (writableSize > length) {
			/*pack info and send to inband buffer*/
			if (infoId == PRIVATEINFO_PTS) {
				PTS_INFO cmd ;
				cmd.header.type = INBAND_CMD_TYPE_PTS ;
				cmd.header.size = sizeof(PTS_INFO) ;
				cmd.wPtr = DEMUX_reverseInteger(*pBSPinInfo->pWrPtr) ;
				cmd.PTSH = (*(int64_t *)pInfo) >> 32 ;
				cmd.PTSL = *(int64_t *)pInfo ;
				return DeliverInBandCommand(pPinInfo, (unsigned char *)&cmd, cmd.header.size, phyWr) ;
			}

			if (infoId == PRIVATEINFO_VIDEO_NEW_SEG) {
				NEW_SEG cmd ;
				cmd.header.type = INBAND_CMD_TYPE_NEW_SEG ;
				cmd.header.size = sizeof(NEW_SEG) ;
				cmd.wPtr = DEMUX_reverseInteger(*pBSPinInfo->pWrPtr) ;
				dmx_crit("[%s %d]CH%d NEW_SEG pointer to BS 0x%x\n", __func__, __LINE__, pCh->tunerHandle, cmd.wPtr);
				return DeliverInBandCommand(pPinInfo, (unsigned char *)&cmd, cmd.header.size, phyWr) ;
			}

			if (infoId == PRIVATEINFO_AUDIO_NEW_SEG) {
				AUDIO_DEC_NEW_SEG cmd ;
				cmd.header.type = AUDIO_DEC_INBAND_CMD_TYPE_NEW_SEG ;
				cmd.header.size = sizeof(AUDIO_DEC_NEW_SEG) ;
				cmd.wPtr = DEMUX_reverseInteger(*pBSPinInfo->pWrPtr) ;
				return DeliverInBandCommand(pPinInfo, (unsigned char *)&cmd, cmd.header.size, phyWr) ;
			}

			if (infoId == PRIVATEINFO_VIDEO_DECODE_COMMAND) {
				DECODE cmd;
				cmd.header.type = INBAND_CMD_TYPE_DECODE ;
				cmd.header.size = sizeof(DECODE) ;
				cmd.RelativePTSH = (((VIDEODECODECOMMAND *)pInfo)->relativePTS) >> 32 ;
				cmd.RelativePTSL = ((VIDEODECODECOMMAND *)pInfo)->relativePTS ;
				cmd.PTSDurationH = (((VIDEODECODECOMMAND *)pInfo)->duration) >> 32 ;
				cmd.PTSDurationL = ((VIDEODECODECOMMAND *)pInfo)->duration ;
				cmd.skip_GOP     = ((VIDEODECODECOMMAND *)pInfo)->skip_GOP ;
				cmd.mode         = (DECODE_MODE)((VIDEODECODECOMMAND *)pInfo)->mode ;
				return DeliverInBandCommand(pPinInfo, (unsigned char *)&cmd, cmd.header.size, phyWr) ;
			}

			if (infoId == PRIVATEINFO_AUDIO_DECODE_COMMAND) {
				AUDIO_DEC_DECODE cmd;
				cmd.header.type = AUDIO_DEC_INBAND_CMD_TYPE_DECODE;
				cmd.header.size = sizeof(AUDIO_DEC_DECODE);
				cmd.RelativePTSH = (((AUDIODECODECOMMAND *)pInfo)->relativePTS) >> 32;
				cmd.RelativePTSL = ((AUDIODECODECOMMAND *)pInfo)->relativePTS;
				cmd.PTSDurationH = (((AUDIODECODECOMMAND *)pInfo)->duration) >> 32;
				cmd.PTSDurationL = ((AUDIODECODECOMMAND *)pInfo)->duration;
				cmd.decodeMode   = ((AUDIODECODECOMMAND *)pInfo)->mode;
				cmd.wPtr = DEMUX_reverseInteger(*pBSPinInfo->pWrPtr) ;
				return DeliverInBandCommand(pPinInfo, (unsigned char *)&cmd, cmd.header.size, phyWr) ;
			}

			if (infoId == PRIVATEINFO_AUDIO_FORMAT) {
				pCh->audioType = ((AUDIO_DEC_NEW_FORMAT *)pInfo)->audioType;
				PCRSYNC_SetAudioType(&pCh->pcrProcesser, pCh->audioType);
				((AUDIO_DEC_NEW_FORMAT *)pInfo)->wPtr = DEMUX_reverseInteger(*pBSPinInfo->pWrPtr) ;
				return DeliverInBandCommand(pPinInfo, pInfo, ((AUDIO_DEC_NEW_FORMAT *)pInfo)->header.size, phyWr) ;
			}

			if (infoId == PRIVATEINFO_VIDEO_NEW_DECODE_MODE) {
				VIDEO_DECODE_MODE cmd;
				cmd.header.type = VIDEO_DEC_INBAND_CMD_TYPE_NEW_DECODE_MODE;
				cmd.header.size = sizeof(VIDEO_DECODE_MODE);
				cmd.wPtr = DEMUX_reverseInteger(*pBSPinInfo->pWrPtr) ;
				cmd.mode = *(DECODE_MODE *)pInfo;
				return DeliverInBandCommand(pPinInfo, (unsigned char *)&cmd, cmd.header.size, phyWr) ;
			}
            if (infoId == PRIVATEINFO_AUDIO_AD_INFO){
                AUDIO_DEC_AD_DESCRIPTOR cmd ;
                memset(&cmd,0, sizeof(AUDIO_DEC_AD_DESCRIPTOR));
                cmd.header.type =  AUDIO_DEC_INBAND_CMD_TYPE_AD_DESCRIPTOR;
                cmd.header.size = sizeof(AUDIO_DEC_AD_DESCRIPTOR) ;
                //bs-ptr
                cmd.wPtr = DEMUX_reverseInteger(*pBSPinInfo->pWrPtr) ;
                //pts
                cmd. PTSH = 0;
                cmd. PTSL = 0;
                //adinfo
                cmd. AD_fade_byte       = (((AUDIO_AD_INFO *)pInfo) -> AD_fade_byte);
                cmd. AD_pan_byte        = (((AUDIO_AD_INFO *)pInfo) -> AD_pan_byte);
                cmd. gain_byte_center   = (((AUDIO_AD_INFO *)pInfo) -> AD_gain_byte_center);
                cmd. gain_byte_front    = (((AUDIO_AD_INFO *)pInfo) -> AD_gain_byte_front);
                cmd. gain_byte_surround = (((AUDIO_AD_INFO *)pInfo) -> AD_gain_byte_surround);
                return DeliverInBandCommand(pPinInfo, (unsigned char *)&cmd, cmd.header.size, phyWr) ;
            }
			break ;
		}

		msleep(100);
		DBG_Warning(DGB_COLOR_RED_WHITE" [%s %d] cmd buffer full. infoId = %d\n"DGB_COLOR_NONE , __FILE__, __LINE__, infoId) ;
	}
	dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d,  ch:%d, DeliverPrivateInfo id:[%d] fail: chStat:%d, pinHead:%p\n", 
		__func__, __LINE__,pCh->tunerHandle, infoId, pCh->state, pPinInfo->pRBH);
	return res ;
}

int GetTargetIdxFromType(DEMUX_PID_TYPE_T pidType, DEMUX_PES_DEST_T  pesDest)
{
	if (pidType == DEMUX_PID_VIDEO) {
		return pesDest == DEMUX_DEST_VDEC0 ? DEMUX_TARGET_VIDEO :
			pesDest == DEMUX_DEST_VDEC1 ? DEMUX_TARGET_VIDEO_2ND : -1 ;
	} else if (pidType == DEMUX_PID_AUDIO) {
		return pesDest == DEMUX_DEST_ADEC0 ? DEMUX_TARGET_AUDIO :
			pesDest == DEMUX_DEST_ADEC1 ? DEMUX_TARGET_AUDIO_2ND : -1 ;
	}
	return -1 ;
}
int DEMUX_DeliverPrivateInfo(demux_channel *pCh, NAVBUF *pBuffer)
{
	/*do nothing ?*/
	return 0 ;
}

int DEMUX_DeliverNavBufCommands(demux_channel *pCh, NAVBUF *pNavBuffer)
{
	switch (pNavBuffer->type) {
	case NAVBUF_NONE:
		break;

	case NAVBUF_WAIT:
		msleep(pNavBuffer->wait.waitTime);
		break;

	case NAVBUF_SHORT_WAIT:
		msleep(pNavBuffer->wait.waitTime);
		break;

	default:
		dmx_err("Unknown bufferType : %d\n", pNavBuffer->type) ;
	}

	return 0 ;
}
void NAV_MEMCPY(demux_channel *pCh, DEMUX_BUF_PIN_T *pPinInfo, unsigned char *dst, unsigned char *src, int bytes, long offsetToPhyAddr)
{
	if (pCh->bFlushBeforeDelivery) {
		DEMUX_flushMemory(src, src+pCh->phyAddrOffset, bytes) ;
	}
	if (pCh->bUseDDRCopy) {
		pCh->latestDDRCopyHandle = DEMUX_ddrCopy(dst+pPinInfo->phyAddrOffset, src+offsetToPhyAddr, bytes) ;
	} else {
		pCh->latestDDRCopyHandle = -1;
		memcpy(dst, src, bytes);
#ifndef FLUSH_BEFORE_SYNC_WP
		DEMUX_flushMemory(dst, dst+pPinInfo->phyAddrOffset, bytes) ;
#endif
	}
	return ;
}
int SyncWritePointers(demux_channel *pCh, unsigned int WP_update_flags, unsigned char *WP[])
{
	unsigned int i ;
	if (pCh->bUseDDRCopy && pCh->latestDDRCopyHandle != (uint64_t)-1) {
		int loop1, loop2 = 0 ;
		/* ------- debug print statistical results ------- */
		static int g_stat[5] = {0, 0, 0, 0, 0};
		static int g_stat_count;
		/* ------------------------------------------------ */

		while (DEMUX_checkTaskCompletion(pCh->latestDDRCopyHandle) == 0) {
			loop2++;
			if (loop2 > 3) { /*osal_Sleep(1);*/
				for (loop1 = 0; loop1 < 100000; loop1++)
					;
			} else if (loop2 > 2) {
				for (loop1 = 0; loop1 < 10000; loop1++)
					;
			} else if (loop2 > 1) {
				for (loop1 = 0; loop1 < 1000;  loop1++)
					;
			} else {
				for (loop1 = 0; loop1 < 100;   loop1++)
					;
			}
		}

		/* ------- debug print statistical results ------- */
		g_stat[(loop2 > 3) ? 4 : loop2]++;
		if (((++g_stat_count)&0xFFF) == 0)
			dmx_notice("DEMUX_DDRCopy_Stat (0/100/1000/10000/slp) : %d/%d/%d/%d/%d\n", g_stat[0], g_stat[1], g_stat[2], g_stat[3], g_stat[4]);
		/* ------------------------------------------------ */
	}

	for (i = 0 ; i < NUMBER_OF_PINS ; i++) {
		/*        DEBUG_SUPPRESS_OUTPUT(WP_update_flags); */
		if ((WP_update_flags & (1<<i)) != 0) {
			DEMUX_BUF_PIN_T *pPinInfo      = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_BS] ;
#ifdef FLUSH_BEFORE_SYNC_WP
			unsigned char   *pWritePointer = (unsigned char *)DEMUX_reverseInteger(*pPinInfo->pWrPtr) ;
			if (!pCh->bUseDDRCopy) {
				if (WP[i] < pWritePointer) {/* wrap-around */
					DEMUX_flushMemory(pWritePointer - pPinInfo->phyAddrOffset, pWritePointer, pPinInfo->pBufferUpper - pWritePointer) ;
					DEMUX_flushMemory(pPinInfo->pBufferLower - pPinInfo->phyAddrOffset, pPinInfo->pBufferLower, WP[i] - pPinInfo->pBufferLower) ;
				} else if (WP[i] > pWritePointer) {
					DEMUX_flushMemory(pWritePointer - pPinInfo->phyAddrOffset, pWritePointer, WP[i] - pWritePointer) ;
				}
			}
#endif
			*pPinInfo->pWrPtr = DEMUX_reverseInteger((unsigned long)WP[i]) ;
		}
	}

	return 0 ;
}
int DEMUX_DeliverData(demux_channel *pCh, NAVDEMUXOUT *pDemuxOut)
{
	static int g_debug_ring_buffer_full_count ;
	static int64_t ring_buffer_debug_time     ;

	unsigned int WP_update_flags = 0 ;
	unsigned int i;
	unsigned int totalPayloadSize[NUMBER_OF_PINS];
	unsigned char *WP[NUMBER_OF_PINS] = {0};
	NAVBUF *pNavBuffer;
	DEMUX_BUF_PIN_T *pPinInfo ;
	DEMUX_BUF_PIN_T *pPinIBInfo ;

	/* pre-calculate total space requirement of audio/video/spic/teletext ring buffers */
	memset(totalPayloadSize, 0, sizeof(totalPayloadSize)) ;

	for (i = 0 ; i < pDemuxOut->numBuffers ; i++) {
		pNavBuffer = &pDemuxOut->pNavBuffers[i] ;
		if (pNavBuffer->type == NAVBUF_DATA || pNavBuffer->type == NAVBUF_DATA_EXT) {
			totalPayloadSize[pNavBuffer->data.pinIndex] += pNavBuffer->data.payloadSize ;
		}
	}

	/*	for (i = 0 ; i < NUMBER_OF_PINS ; i++)
		{
			printk("idx %d, payloadSize = %d\n", i, totalPayloadSize[i]) ;
		}*/

	/* request ring buffer space for audio/video/spic/teletext */

	for (i = 0 ; i < NUMBER_OF_PINS ; i++) {
		if (totalPayloadSize[i] == 0)
			continue ;

		pPinInfo = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_BS] ;
		pPinIBInfo = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_IB] ;

		if (pPinInfo->pRBH != NULL && pPinIBInfo->pRBH != NULL) { /* for connected pin only */
			long writableSize ;
			unsigned long phyWr, phyRd ;
			unsigned char *pRdPtrDump = (unsigned char *)pPinInfo->pRdPtrDump ;
			phyWr = DEMUX_reverseInteger(*pPinInfo->pWrPtr) ;
			phyRd = DEMUX_reverseInteger(*pPinInfo->pRdPtr) ;
			WP[i] = (unsigned char *)phyWr ;
			writableSize = BS_DISTANCE(phyWr, phyRd, pPinInfo->pBufferLower, pPinInfo->pBufferUpper) - 1 ;

			if (pRdPtrDump) {
				writableSize = MIN((BS_DISTANCE(phyWr, *pRdPtrDump, pPinInfo->pBufferLower, pPinInfo->pBufferUpper) - 1), writableSize) ;
			}

			/*                    printk("RTKDemux: ring buffer(%s), WP = %lxh, RP = %lxh, size = %ld, req-size = %d\n",
					      rtkdemux_outputNames[i],
					      phyWr,
					      phyRd,
					      writableSize, totalPayloadSize[i]) ;*/

///////////////////////////////////////////////////////////////////////////////////////////////

            if ((pCh->avSyncMode == NAV_AVSYNC_FREE_RUN || (pCh->avSyncMode==NAV_AVSYNC_PCR_MASTER && pCh->pcrProcesser.bVideoFreerun)) &&
                    ( i ==VIDEO_PIN || i== VIDEO2_PIN) &&
                    (totalPayloadSize[i] > 0)){
                if (writableSize <= (1*1024*1024 +512*1024))   {
                      unsigned char videoport = (i ==VIDEO_PIN ?0 : (i== VIDEO2_PIN ? 1 : 255));
                            long ignore;
                        dmx_mask_print(0x20000,"flush vo -------------->\n");
                        if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_VOCompFlush, videoport, 0, &ignore)) {
                                pr_err("RPC fail!!\n");
                        }
                }
            }

//////////////////////////////////////////////////////////////////////////////////////////////
			if (writableSize < totalPayloadSize[i]) {
				int64_t debug_time = CLOCK_GetPTS();
					pPinIBInfo->pRBH->reserve3 = DEMUX_reverseInteger(1);
					if (pCh->tp_src != MTP){
							CheckStartCondition(pCh, i);
					}
				if (++g_debug_ring_buffer_full_count > 0 && abs64(debug_time-ring_buffer_debug_time) > 3*DEMUX_CLOCKS_PER_SEC) {
					dmx_alert(DGB_COLOR_RED_WHITE" RTKDemux: (CH%d)(%s) ring buffer full (%d times), Drop = %d, WP = %lxh, RP = %lxh, size = %ld, req-size = %d\n"DGB_COLOR_NONE,
							pCh->tunerHandle, rtkdemux_outputNames[i], g_debug_ring_buffer_full_count,
							IsDropping(pCh, i),
							phyWr,
							phyRd,
							writableSize, totalPayloadSize[i]) ;

						if (pCh->tp_src != MTP) {
							dmx_alert("Please check %s decoder or pcr-master logic\n", rtkdemux_outputNames[i]);
							if (i == VIDEO_PIN || i == VIDEO2_PIN){
								rtkvdec_vtm_state();
							}
							else
								rtkaudio_send_string("show_info dec",13);
						}

					g_debug_ring_buffer_full_count = 0 ;
					ring_buffer_debug_time = debug_time ;
				}
				if(!IsDropping(pCh, i)) {
					return -1;
				}
			}
			else {
				pPinIBInfo->pRBH->reserve3 = DEMUX_reverseInteger(0);
				CheckStopCondition(pCh, i, writableSize, pPinInfo->pBufferUpper - pPinInfo->pBufferLower);
			}

			if(!IsDropping(pCh, i)) {
				/*            assert(writableSize >= (long)totalPayloadSize[i]);*/
				DEMUX_CheckFullness(pCh, i, pPinInfo);
			}
		}
	}
	if(!GetTotalDroppingPin())
		g_debug_ring_buffer_full_count = 0 ;

	/* multiple item delivery loop */
#define NAV_SYNC_WRITE_POINTERS()\
	{\
		if (WP_update_flags > 0 && SyncWritePointers(pCh, WP_update_flags, WP) != 0) { \
			pDemuxOut->numBuffers = 0;\
			msleep(NAV_SLEEP_TIME_ON_IDLE);\
			return 0 ;\
		} \
		WP_update_flags = 0;\
	}

	for (i = 0 ; i < pDemuxOut->numBuffers ; i++) {
		pNavBuffer = &pDemuxOut->pNavBuffers[i] ;
		if (pNavBuffer->type != NAVBUF_DATA && pNavBuffer->type != NAVBUF_DATA_EXT) {
			NAV_SYNC_WRITE_POINTERS();
			DEMUX_DeliverNavBufCommands(pCh, pNavBuffer) ;
			continue ;
		}

		pPinInfo   = &pCh->pinInfo[pNavBuffer->data.pinIndex].bufInfo[DEMUX_STREAM_TYPE_BS] ;
		pPinIBInfo = &pCh->pinInfo[pNavBuffer->data.pinIndex].bufInfo[DEMUX_STREAM_TYPE_IB] ;

		if (demux_device->pinMap[pNavBuffer->data.pinIndex].chIndex != pCh->tunerHandle)
			continue;

		if(IsDropping(pCh, pNavBuffer->data.pinIndex)) {
			continue;
		}

		/* Debug functions for don't deliver data to firmwares. */
		if (rtkdemux_dbg_nodemux_audio_en && (pNavBuffer->data.pinIndex == AUDIO_PIN || pNavBuffer->data.pinIndex == AUDIO2_PIN)) {
			rtkdemux_dbg_dump_bitstream(pCh->tunerHandle, pNavBuffer->data.pinIndex, pNavBuffer->data.payloadData, pNavBuffer->data.payloadSize);
			continue;
		}
		if (rtkdemux_dbg_nodemux_video_en && (pNavBuffer->data.pinIndex == VIDEO_PIN || pNavBuffer->data.pinIndex == VIDEO2_PIN)) {
			rtkdemux_dbg_dump_bitstream(pCh->tunerHandle, pNavBuffer->data.pinIndex, pNavBuffer->data.payloadData, pNavBuffer->data.payloadSize);
			continue;
		}

		if (pPinInfo->pRBH == NULL) /* unconnected pin, ignore data */
			continue;

		if (pNavBuffer->data.infoId != PRIVATEINFO_NONE) {
			NAV_SYNC_WRITE_POINTERS();

			if (DeliverPrivateInfo(pCh, pPinIBInfo, pNavBuffer->data.infoId, pNavBuffer->data.infoData, pNavBuffer->data.infoSize, pPinInfo) < 0) {
				/*                assert(demuxIn.reservedInfoId == PRIVATEINFO_NONE); */
				pCh->demuxIn.reservedInfoId = pNavBuffer->data.infoId;
				pCh->demuxIn.reservedInfoSize = pNavBuffer->data.infoSize;
				pCh->demuxIn.reservedInfoData = pNavBuffer->data.infoData;
				return -1 ;
			}
		}

		if (pNavBuffer->data.payloadSize > 0) {
			int offset = 0 ; /*m_offsetToPhyAddr ;
					   if (m_bResetAVSync)
					   ResetAVSync(pNavBuffer);*/

			if (pNavBuffer->data.pts >= 0) {

#define IS_VIDEO_PIN(_pin_) ((_pin_) == VIDEO_PIN || (_pin_) == VIDEO2_PIN)
#define IS_AUDIO_PIN(_pin_) ((_pin_) == AUDIO_PIN || (_pin_) == AUDIO2_PIN)

				if(pCh->AdChannelTarget < 0 || pCh->demuxTargetInfo[pCh->AdChannelTarget].pinIndex != pNavBuffer->data.pinIndex){
					PCRSYNC_UpdateDemuxPTS(&pCh->pcrProcesser, IS_VIDEO_PIN(pNavBuffer->data.pinIndex),pNavBuffer->data.pts);
					if (HAS_FLAG(pCh->status, STATUS_CHECK_PVR_AUDIO_STABLE) && IS_AUDIO_PIN(pNavBuffer->data.pinIndex)) {
						PVR_CheckPvrAudioStable(pCh, pNavBuffer->data.pts);
					}
				}

				DEMUX_CheckPTSChange(pCh);
				PCRSYNC_CheckPTSDataStable(&pCh->pcrProcesser);

				PVR_CheckPTSDiff(pCh);
				rtkdemux_dbg_dump_pts(pCh->tunerHandle, pNavBuffer->data.pinIndex, pNavBuffer->data.pts);
				rtkdemux_dbg_print_pts(
					pCh->tunerHandle,
					pNavBuffer->data.pinIndex,
					pNavBuffer->data.pts,
					(unsigned char*)(uintptr_t)DEMUX_reverseInteger(*pPinInfo->pWrPtr)
				);

				NAV_SYNC_WRITE_POINTERS();

				if (DeliverPrivateInfo(pCh, pPinIBInfo, PRIVATEINFO_PTS, (char *)&pNavBuffer->data.pts, sizeof(int64_t), pPinInfo) < 0) {
					/*                    assert(demuxIn.reservedInfoId == PRIVATEINFO_NONE);*/
					pCh->demuxIn.reservedInfoId = pNavBuffer->data.infoId;
					pCh->demuxIn.reservedInfoSize = pNavBuffer->data.infoSize;
					pCh->demuxIn.reservedInfoData = pNavBuffer->data.infoData;
					return -1 ;
				}
				/*                DEBUG_LOG_PTS;*/
			}

			WP_update_flags |= (1 << pNavBuffer->data.pinIndex) ;

			/*        #ifdef IS_ARCH_ARM_COMMON */
			if (pNavBuffer->type == NAVBUF_DATA_EXT)
				offset = pNavBuffer->data.phyAddrOffset ;
			/*        #endif */
			if (WP[pNavBuffer->data.pinIndex] + pNavBuffer->data.payloadSize > pPinInfo->pBufferUpper) { /* wrap-around */
				unsigned int space = pPinInfo->pBufferUpper - WP[pNavBuffer->data.pinIndex];
				NAV_MEMCPY(pCh, pPinInfo, WP[pNavBuffer->data.pinIndex] - pPinInfo->phyAddrOffset, pNavBuffer->data.payloadData, space, offset);
				NAV_MEMCPY(pCh, pPinInfo, pPinInfo->pBufferLower - pPinInfo->phyAddrOffset, pNavBuffer->data.payloadData + space, pNavBuffer->data.payloadSize - space, offset);
			} else {
				NAV_MEMCPY(pCh, pPinInfo, WP[pNavBuffer->data.pinIndex] - pPinInfo->phyAddrOffset, pNavBuffer->data.payloadData, pNavBuffer->data.payloadSize, offset);
			}

			WP[pNavBuffer->data.pinIndex] += pNavBuffer->data.payloadSize;
			if (WP[pNavBuffer->data.pinIndex] >= pPinInfo->pBufferUpper)
				WP[pNavBuffer->data.pinIndex] -= pPinInfo->pBufferUpper - pPinInfo->pBufferLower;

			if (rtkdemux_dbg_printio_en || rtkdemux_dbg_monitorio_en)
				rtkdemux_dbg_printio_deliver_size_calc(pCh, pNavBuffer->data.pinIndex, pNavBuffer->data.payloadSize);
			rtkdemux_dbg_dump_bitstream(pCh->tunerHandle, pNavBuffer->data.pinIndex, pNavBuffer->data.payloadData, pNavBuffer->data.payloadSize);
		}
	}

	NAV_SYNC_WRITE_POINTERS();
	pDemuxOut->numBuffers = 0 ;

	return 0 ;
}

static int getChannelIndex(const demux_channel *channel)
{
	int idx;
	if (!demux_device->pChArray)
		return -1;

	for (idx = 0; idx < demux_device->chNum; ++idx) {
		if (&demux_device->pChArray[idx] == channel) {
			return idx;
		}
	}

	return -1;
}

static TPK_PID_FILTER_PARAM_T      newPidLists[DEMUX_CH_NUM][MAX_PID_FILTER_NUMBER];
static unsigned short              removePidLists[DEMUX_CH_NUM][MAX_PID_FILTER_NUMBER]  ; /* to move */
static DEMUX_SCRAMBLE_CHECK_LIST_T scrambleLists[DEMUX_CH_NUM][MAX_PID_FILTER_NUMBER] ;
void UpdateDemuxTarget(demux_channel *pCh, NAVBUF *pBuffer)
{
    int i, j, target, count = 0, rm_count = 0 ;
	int channelIdx = -1;
	TPK_PID_FILTER_PARAM_T *  add_pidEntry = NULL;
	unsigned short         *  rm_pid       = NULL;
    if (pCh == NULL){
        dmx_err("%s_%d param invalid !!!!!\n", __func__, __LINE__);
        return;
    }
    channelIdx = getChannelIndex(pCh);
    if ((channelIdx<0) || (channelIdx>=DEMUX_CH_NUM)){
        dmx_err("%s_%d param invalid (%d)\n", __func__, __LINE__, channelIdx);
        return;
    }

    add_pidEntry = newPidLists[channelIdx];
    rm_pid       = removePidLists[channelIdx];

	if (pCh->bUpdateDemuxTarget) {
		int checkTS, checkPES, checkScramble ;
		bool got ;
		memset(pCh->demuxTargetTable, DEMUX_TARGET_DROP, sizeof(pCh->demuxTargetTable)) ;
		checkTS       = HAS_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
		checkPES      = HAS_FLAG(pCh->events, EVENT_UPDATE_PES_LIST);
		checkScramble = HAS_FLAG(pCh->events, EVENT_UPDATE_SCRAMBLE_LIST) ;

		//check all filter :
		//otherwise pes/scramble filter will be miss
		checkTS = checkPES = checkScramble = 1;
		/* pid to be removed */
		/*    printk("pCh->pidActiveCount %d, %d, %d, %d\n", pCh->pidActiveCount, checkTS, checkPES, checkScramble) ; */
		for (i = 0 ; i < pCh->pidActiveCount ; i++) {
			got = false ;
			if (checkTS) {
				/*        printk("pCh->pidFilterCount %d\n", pCh->pidFilterCount) ; */
				for (j = 0 ; j < pCh->pidFilterCount ; j++) {
					/*          printk("PID: %d, %d\n", pCh->pidFilterList[j].pid, pCh->pidActiveList[i].PID) ; */
					if (pCh->pidFilterList[j].pid == pCh->pidActiveList[i].PID) {
						got = true ;
						/*            printk("Got PID line %d, %d\n", __LINE__, j) ;*/
						break ;
					}
				}
			}
			if (!got && checkPES) {
				for (j = 0 ; j < MAX_PID_FILTER_CB_NUM ; j++) {
					if (pCh->pidFilterListCB[j].used && pCh->pidFilterListCB[j].pid == pCh->pidActiveList[i].PID) {
						got = true ;
						/*            printk("Got PID line %d, %d\n", __LINE__, j) ;*/
						break ;
					}
				}
			}
			if (!got && checkScramble) {
				for (j = 0 ; j < pCh->checkScrambleCount ; j++) {
					if (pCh->scrambleList[j].bCheck && pCh->scrambleList[j].pid == pCh->pidActiveList[i].PID) {
						got = true ;
						/*            printk("Got PID line %d, %d\n", __LINE__, j) ;*/
						break ;
					}
				}
			}

			if (!got) {
				rm_pid[rm_count++] = pCh->pidActiveList[i].PID;
				/*        printk("Remove PID line %d, rm_count %d, %d, %d, %d\n", __LINE__, rm_count, got, true, false) ;*/
				if (pCh->pidActiveList[i].DescrambleEn && demux_device->cwInfo[pCh->pidActiveList[i].KeySel].used && demux_device->cwInfo[pCh->pidActiveList[i].KeySel].pid == pCh->pidActiveList[i].PID)
					demux_device->cwInfo[pCh->pidActiveList[i].KeySel].used = 0 ;
			}
		}

		/* pid to be added */
		for (i = 0 ; i < pCh->pidFilterCount ; i++) {
			add_pidEntry[i].valid        = 1 ;
			add_pidEntry[i].DescrambleEn = pCh->pidFilterList[i].enDescramble ;
			add_pidEntry[i].KeySel       = pCh->pidFilterList[i].cwIndex >= 0 ? pCh->pidFilterList[i].cwIndex : 0 ;
			add_pidEntry[i].PID          = pCh->pidFilterList[i].pid ;
		}
		count = pCh->pidFilterCount ;

		if (checkPES) {
			for (i = 0 ; i < MAX_PID_FILTER_CB_NUM ; i++) {
				if (!pCh->pidFilterListCB[i].used)
					continue ;
				for (j = 0 ; j < count ; j++) {
					if (pCh->pidFilterListCB[i].pid == add_pidEntry[j].PID)
						break ;
				}

				if (j == count) { /* add */
					add_pidEntry[count].valid        = 1 ;
					add_pidEntry[count].DescrambleEn = pCh->pidFilterListCB[i].cwIndex >= 0 ; /*? demux_device->cwInfo[pCh->pidFilterListCB[i].cwIndex].enable : 0 ;*/
					add_pidEntry[count].KeySel       = pCh->pidFilterListCB[i].cwIndex >= 0 ? pCh->pidFilterListCB[i].cwIndex : 0 ;
					add_pidEntry[count].PID          = pCh->pidFilterListCB[i].pid ;
					count++ ;
				}
			}
		}
		if (checkScramble) {
			for (i = 0 ; i < pCh->checkScrambleCount ; i++) {
				if (!pCh->scrambleList[i].bCheck)
					continue ;
				for (j = 0 ; j < count ; j++) {
					if (pCh->scrambleList[i].pid == add_pidEntry[j].PID)
						break ;
				}
				if (j == count) { /* add */
					add_pidEntry[count].valid        = 1 ;
					add_pidEntry[count].DescrambleEn = 0 ;
					add_pidEntry[count].KeySel       = 0 ;
					add_pidEntry[count].PID          = pCh->scrambleList[i].pid ;
					count++ ;
				}
			}
		}

		for (i = 0 ; i < pCh->pidFilterCount ; i++) {
			target = GetTargetIdxFromType(pCh->pidFilterList[i].pidType, pCh->pidFilterList[i].pesDest) ;
			if (target >= 0) {
				pCh->demuxTargetTable[pCh->pidFilterList[i].pid] = target ;
			}
		}

		for (i = 0 ; i < DEMUX_NUM_OF_TARGETS ; i++) {
			if (pCh->activeTarget[i].bNewTarget) {
				/* fix bug https://realtektv.realtek.com/view.php?id=103294
				An extra NEW_SEG will cause video decoder read wrong PTS.
				 */
				/*int event = i == DEMUX_TARGET_AUDIO      ? EVENT_FLUSH_AUDIO  :
					i == DEMUX_TARGET_AUDIO_2ND  ? EVENT_FLUSH_AUDIO2 :
					i == DEMUX_TARGET_VIDEO      ? EVENT_FLUSH_VIDEO  : EVENT_FLUSH_VIDEO2 ;

				SET_FLAG(pCh->events, event);*/
				pCh->activeTarget[i].bNewTarget = false ;
			}

		}

		memset(pCh->demuxTargetTableCB, DEMUX_TARGET_DROP, sizeof(pCh->demuxTargetTableCB)) ;
		for (i = 0 ; i < MAX_PID_FILTER_CB_NUM ; i++) {
			if (!pCh->pidFilterListCB[i].used)
				continue ;

			if (pCh->activePESTarget[i].bNewTarget) {
				pCh->activePESTarget[i].pid   = pCh->pidFilterListCB[i].pid ;
				pCh->activePESTarget[i].bNewTarget = false;
			}

			pCh->demuxTargetTableCB[pCh->pidFilterListCB[i].pid] = i ;
		}

		if (rm_count) {
			dmx_notice("%s,(CH%d)UpdateDemuxPID(Remove):\n", __func__, pCh->tunerHandle) ;
			for (i = 0 ; i < rm_count ; i++) {
				dmx_notice("PID = %d\n", rm_pid[i]) ;
			}
		}

		dmx_notice("%s,(CH%d)UpdateDemuxPID(All):\n", __func__, pCh->tunerHandle) ;
		for (i = 0 ; i < count ; i++) {
			dmx_notice("PID = %d, KeySel = %d\n", add_pidEntry[i].PID, add_pidEntry[i].KeySel) ;
		}

		/* Remove Pid List, set Pid List to TP */
		for (i = 0 ; i < rm_count ; i++) {
			RHAL_RemovePIDFilter(pCh->tunerHandle, rm_pid[i], (void *)DEFAULT_FILE_HANDLE) ;
		}

		for (i = 0 ; i < count ; i++) {
			RHAL_AddPIDFilter(pCh->tunerHandle, add_pidEntry[i], (void *)DEFAULT_FILE_HANDLE) ;
		}

		/* Update Active PID list */
		if (count) {
			pCh->pidActiveCount = count ;
			memcpy(pCh->pidActiveList, add_pidEntry, sizeof(TPK_PID_FILTER_PARAM_T)*count) ;
		} else {
			/*RHAL_TPFlushBuffer(pCh->tunerHandle);*/
			pCh->pidActiveCount = count ;
		}

		/* Update check scramble table */
		if (checkScramble) {
			int chkCount = 0 ;
			DEMUX_SCRAMBLE_CHECK_LIST_T * const scrambleList = scrambleLists[channelIdx];
			for (i = 0 ; i < pCh->checkScrambleCount ; i++) {
				if (pCh->scrambleList[i].bCheck) {
					pCh->scrambleList[i].timeStamp = CLOCK_GetPTS();
					scrambleList[chkCount++] = pCh->scrambleList[i] ;
				}
				/* reset chkScrambleTable for this PID if bCheck is set from 1 to 0, or 0 to 1 */
				if ((HAS_FLAG(pCh->chkScrambleTable[pCh->scrambleList[i].pid], PID_CHECK_SCRAMBLE) && !pCh->scrambleList[i].bCheck)
						|| (!HAS_FLAG(pCh->chkScrambleTable[pCh->scrambleList[i].pid], PID_CHECK_SCRAMBLE) &&  pCh->scrambleList[i].bCheck)) {
					pCh->chkScrambleTable[pCh->scrambleList[i].pid] = ((pCh->scrambleList[i].bCheck == true) ? (unsigned char)PID_CHECK_SCRAMBLE : 0) ;
				}
			}
			pCh->checkScrambleCount = chkCount ;
			if (pCh->checkScrambleCount) {
				memcpy(pCh->scrambleList, scrambleList, sizeof (DEMUX_SCRAMBLE_CHECK_LIST_T)*chkCount) ;
			}
		}
/*
		if (HAS_FLAG(pCh->events, EVENT_UPDATE_PCR)) {
			if (0 < pCh->PCRPID && pCh->PCRPID < 0x1FFF) {
                SET_FLAG(pCh->status, STATUS_PCRTAK_START);
			} else {
                Demux_MW_disablePCRTracking(pCh);
			}
            dmx_mask_print(DEMUX_PCRTRACK_DEBUG, "ch:%d, pcr pid:%d \n", pCh->tunerHandle, pCh->PCRPID);
			RESET_FLAG(pCh->events, EVENT_UPDATE_PCR);
		}
*/
		RESET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST | EVENT_UPDATE_PES_LIST | EVENT_UPDATE_SCRAMBLE_LIST);
		pCh->bUpdateDemuxTarget = false ;
	}
}

//event no need  finish handle. befor go process data.
//may be try more than one times.
void handleUnpedingEvents(demux_channel *pCh)
{/*handle mutex  each item self , do not lock whole function*/
	mutex_lock(&pCh->mutex);
	if (HAS_FLAG(pCh->status, STATUS_PCRTAK_STOP)){
		Demux_MW_disablePCRTracking(pCh);
		RESET_FLAG(pCh->status, STATUS_PCRTAK_STOP);
	}
	if (HAS_FLAG(pCh->status, STATUS_PCRTAK_START)){
		if (Demux_MW_enablePCRTracking(pCh)<0){
			dmx_mask_print(DEMUX_PCRTRACK_DEBUG,"\033[1;36m [%s %d] ch:%d, fail to start PcrTracking \033[m\n", __func__ , __LINE__ ,pCh->tunerHandle );
		}
		else{
			RESET_FLAG(pCh->status, STATUS_PCRTAK_START);
			dmx_mask_print(DEMUX_PCRTRACK_DEBUG|DEMUX_NOTICE_PRINT,"%s-%d, ch:%d, start PcrTracking....\n", __func__, __LINE__,pCh->tunerHandle);
		}
	}
	//---video flush--
	if (HAS_FLAG(pCh->status, STATUS_SET_VIDEO_FLUSH)) {
		if (demux_device->pinMap[VIDEO_PIN].chIndex != pCh->tunerHandle){
			dmx_warn("%s,%d, ch:%d,invalid command, channel do not owner pin[%d], giveup videoFlush\n", __func__, __LINE__, pCh->tunerHandle, VIDEO_PIN);
			RESET_FLAG(pCh->status, STATUS_SET_VIDEO_FLUSH);
		}
		else
		{	
			if (DEMUX_EVENT_FlushVideo(pCh, pCh->videoDecodeMode[0], VIDEO_PIN)<0){
				dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d, ch:%d, FlushVideo (%d)FAIL, try latter  \n", __func__,__LINE__, pCh->tunerHandle, VIDEO_PIN);
			}
			else
				RESET_FLAG(pCh->status, STATUS_SET_VIDEO_FLUSH);
		}
	}

	if (HAS_FLAG(pCh->status, STATUS_SET_VIDEO2_FLUSH)) {
		if (demux_device->pinMap[VIDEO2_PIN].chIndex != pCh->tunerHandle){
			dmx_warn("%s,%d, ch:%d,invalid command, channel do not owner pin[%d], giveup videoFlush\n", __func__, __LINE__, pCh->tunerHandle, VIDEO2_PIN);
			RESET_FLAG(pCh->status, STATUS_SET_VIDEO2_FLUSH);
		}
		else
		{
			if (DEMUX_EVENT_FlushVideo(pCh, pCh->videoDecodeMode[1], VIDEO2_PIN)<0){
				dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d, ch:%d, FlushVideo (%d)FAIL, try latter  \n", __func__,__LINE__,pCh->tunerHandle, VIDEO2_PIN);
			}
			else
				RESET_FLAG(pCh->status, STATUS_SET_VIDEO2_FLUSH);
		}
	}
	//------audio flush----
	if (HAS_FLAG(pCh->status, STATUS_SET_AUDIO_FLUSH)) {
		if (demux_device->pinMap[AUDIO_PIN].chIndex != pCh->tunerHandle){
			dmx_warn("%s,%d, ch:%d,invalid command, channel do not owner pin[%d], giveup videoFlush\n", __func__, __LINE__, pCh->tunerHandle, AUDIO_PIN);
			RESET_FLAG(pCh->status, STATUS_SET_AUDIO_FLUSH);
		}
		else
		{
			if (DEMUX_EVENT_FlushAudio(pCh, AUDIO_PIN)<0){
				dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d, ch:%d, FlushVideo (%d)FAIL, try latter  \n", __func__,__LINE__, pCh->tunerHandle, AUDIO_PIN);
			}
			else
				RESET_FLAG(pCh->status, STATUS_SET_AUDIO_FLUSH);
		}
	}

	if (HAS_FLAG(pCh->status, STATUS_SET_AUDIO2_FLUSH)) {
		if (demux_device->pinMap[AUDIO2_PIN].chIndex != pCh->tunerHandle){
			dmx_warn("%s,%d, ch:%d,invalid command, channel do not owner pin[%d], giveup videoFlush\n", __func__, __LINE__, pCh->tunerHandle, AUDIO2_PIN);
			RESET_FLAG(pCh->status, STATUS_SET_AUDIO2_FLUSH);
		}
		else
		{
			if (DEMUX_EVENT_FlushAudio(pCh, AUDIO2_PIN)<0){
				dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d, ch:%d, FlushVideo (%d)FAIL, try latter  \n", __func__,__LINE__,pCh->tunerHandle, AUDIO2_PIN);
			}
			else
				RESET_FLAG(pCh->status, STATUS_SET_AUDIO2_FLUSH);
		}
	}
	//-----audio--new format--
	if (HAS_FLAG(pCh->status, STATUS_SET_AUDIO_FORMAT)) {
		if (demux_device->pinMap[AUDIO_PIN].chIndex != pCh->tunerHandle){
			dmx_warn("%s,%d, ch:%d,invalid command, channel do not owner pin[%d], giveup audioFormat Set\n", __func__, __LINE__, pCh->tunerHandle, AUDIO_PIN);
			RESET_FLAG(pCh->status, STATUS_SET_AUDIO_FORMAT);
		}
		else{
			if (DEMUX_EVENT_AudioNewFormat(pCh, AUDIO_PIN, pCh->audioFormat, pCh->audioPrivateInfo)<0){
				dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d, ch:%d, SetAudioFormat (%d)FAIL, try latter  \n", __func__,__LINE__,pCh->tunerHandle, AUDIO_PIN);
			}
			else
				RESET_FLAG(pCh->status, STATUS_SET_AUDIO_FORMAT);
		}
	}
	if (HAS_FLAG(pCh->status, STATUS_SET_AUDIO2_FORMAT)) {
		if (demux_device->pinMap[AUDIO2_PIN].chIndex != pCh->tunerHandle){
			dmx_warn("%s,%d, ch:%d,invalid command, channel do not owner pin[%d], giveup audioFormat Set\n", __func__, __LINE__, pCh->tunerHandle, AUDIO2_PIN);
			RESET_FLAG(pCh->status, STATUS_SET_AUDIO2_FORMAT);
		}
		else{
			if (DEMUX_EVENT_AudioNewFormat(pCh, AUDIO2_PIN, pCh->audioFormat2, pCh->audioPrivateInfo2)<0){
				dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d, ch:%d, SetAudioFormat (%d)FAIL, try latter  \n", __func__,__LINE__,pCh->tunerHandle, AUDIO2_PIN);
			}
			else
				RESET_FLAG(pCh->status, STATUS_SET_AUDIO2_FORMAT);
		}
	}
#ifdef  DEMUX_AUDIO_USE_GLOBAL_BUFFER
	if (HAS_FLAG(pCh->status, STATUS_SET_AUDIO_PIN_INFO)) {
		if (DEMUX_BUF_UpdateChannelAudioPinStatus(pCh)<0){
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG, "[%s, %d] ch:%d  update pin status fail ,need retry\n", __func__, __LINE__, pCh->tunerHandle);
		}
		else
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG, "[%s, %d] ch:%d finish update pin status \n", __func__, __LINE__, pCh->tunerHandle);
			RESET_FLAG(pCh->status, STATUS_SET_AUDIO_PIN_INFO);
		}
	}
#endif
	mutex_unlock(&pCh->mutex);

}

//event have to finish handle. befor go process data.
void HandleEvents(demux_channel *pCh, NAVBUF *pBuffer)
{
	if (HAS_FLAG(pCh->events, EVENT_VIDEO0_NEW_DECODE_MODE)) {
		DeliverPrivateInfo(pCh, &pCh->pinInfo[VIDEO_PIN].bufInfo[DEMUX_STREAM_TYPE_IB], PRIVATEINFO_VIDEO_NEW_DECODE_MODE, (char *)&pCh->videoDecodeMode[0], sizeof(pCh->videoDecodeMode[0]), &pCh->pinInfo[VIDEO_PIN].bufInfo[DEMUX_STREAM_TYPE_BS]) ;
		RESET_FLAG(pCh->events, EVENT_VIDEO0_NEW_DECODE_MODE);
	}
	if (HAS_FLAG(pCh->events, EVENT_VIDEO1_NEW_DECODE_MODE)) {
		DeliverPrivateInfo(pCh, &pCh->pinInfo[VIDEO2_PIN].bufInfo[DEMUX_STREAM_TYPE_IB], PRIVATEINFO_VIDEO_NEW_DECODE_MODE, (char *)&pCh->videoDecodeMode[1], sizeof(pCh->videoDecodeMode[1]), &pCh->pinInfo[VIDEO2_PIN].bufInfo[DEMUX_STREAM_TYPE_BS]) ;
		RESET_FLAG(pCh->events, EVENT_VIDEO1_NEW_DECODE_MODE);
	}
	if (HAS_FLAG(pCh->events, EVENT_FLUSH_TP)) {
		DEMUX_EVENT_FlushTPBuffer(pCh);
		RESET_FLAG(pCh->events, EVENT_FLUSH_TP);
	}
    if (HAS_FLAG(pCh->events, EVENT_FLUSH_MTP)) {
	UINT8 mtp_id;
        DEMUX_EVENT_FlushTPBuffer(pCh);

        #define DEMUX_GET_MTP_ID(_ch) (((_ch) == DEMUX_CH_A) ? 0 : (((_ch) == DEMUX_CH_B) ? 1 : 2))
        mtp_id = DEMUX_GET_MTP_ID(pCh->tunerHandle);
		dmx_notice("[%s %d] RHAL_MTPStreamControl start\n", __func__, __LINE__);
		RHAL_MTPStreamControl(mtp_id, MTP_STREAM_START);
		dmx_notice("[%s %d] RHAL_MTPStreamControl end\n", __func__, __LINE__);
		#undef DEMUX_GET_MTP_ID
        RESET_FLAG(pCh->events, EVENT_FLUSH_MTP);
	}
    if (HAS_FLAG(pCh->events, EVENT_FLUSH_AD_INFO)) {
        dmx_notice("[%s %d] handle EVENT_FLUSH_AD_INFO\n", __func__, __LINE__);
        pCh->adInfo.AD_fade_byte = 0x0;
        pCh->adInfo.AD_pan_byte = 0x0;
        pCh->adInfo.AD_gain_byte_center = 0x0;
        pCh->adInfo.AD_gain_byte_front = 0x0;
        pCh->adInfo.AD_gain_byte_surround = 0x0;
        pCh->AdChannelTarget = -1;
        DEMUX_SendAudioDesc(&pCh->adInfo);
        RESET_FLAG(pCh->events, EVENT_FLUSH_AD_INFO);
    }
}

static int DEMUX_GetWaitTime(demux_channel *pCh)
{
	/* KTASKWBS-5995 : avoid to wait long time, cause audio cutting */
	#define HIGH_BIT_RATE (1*1024*1024)

	uint64_t ms_time  = TUNER_DATA_READ_WAIT_TIME;
	uint64_t maxTunerReadWaitTime;
	const uint64_t byteRate = (pCh->bitRate >> 3);

	// need to test, waittime between 20ms and 100ms temporarily
	if (byteRate) {
		/* the max wait time is the streaming time for half of TP buffer size/2*/
         if(byteRate >= HIGH_BIT_RATE)
		maxTunerReadWaitTime = TUNER_DATA_READ_WAIT_TIME;
         else
		maxTunerReadWaitTime = MAX_TUNER_DATA_READ_WAIT_TIME;

        const uint64_t max = MIN(
                                 div_u64(
                                     (((uint64_t)pCh->tpBuffer.size >> 1) << 10),
                                     byteRate
                                 ),
                                 maxTunerReadWaitTime
                             );
        const uint64_t min = TUNER_DATA_READ_WAIT_TIME;

        const DEMUX_BUF_PIN_T * const pPinInfo = &pCh->pinInfo[VIDEO_PIN].bufInfo[DEMUX_STREAM_TYPE_BS];
        if (pPinInfo->pRBH != NULL) {
                const uintptr_t phyWr = DEMUX_reverseInteger(*pPinInfo->pWrPtr);
                const uintptr_t phyRd = DEMUX_reverseInteger(*pPinInfo->pRdPtr);

                const size_t buffer_size          = (pPinInfo->pBufferUpper - pPinInfo->pBufferLower);
                const size_t remained_buffer_size = BS_DISTANCE2(phyWr, phyRd, buffer_size);
                const size_t used_buffer_size     = (buffer_size > remained_buffer_size ? buffer_size - remained_buffer_size : 0);

                /* the wait time is the streaming time for half of video buffer fullness/2*/
                ms_time = div_u64(
                               ((((uint64_t)used_buffer_size) >> 1) << 10),
                               byteRate
                          );
                ms_time = MAX(
                              MIN(ms_time, max),
                              min
                          );
            }
        }

	return (int)ms_time;
}
int DEMUX_EVENT_FlushVideo(demux_channel *pCh, DECODE_MODE decMode, int pin)
{
	DEMUX_BUF_PIN_T *pPinInfo, *pPinIBInfo;
	VIDEODECODECOMMAND  cmd ;
	memset(&cmd, 0, sizeof(VIDEODECODECOMMAND)) ;
	cmd.mode = decMode; /*NORMAL_DECODE ;*/
	cmd.relativePTS =  0 ;
	cmd.duration    = -1 ;

	pPinInfo   = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
	pPinIBInfo = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
	if (DeliverPrivateInfo(pCh, pPinIBInfo, PRIVATEINFO_VIDEO_NEW_SEG, NULL, sizeof(NEW_SEG), pPinInfo)<0){
		dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d: ch:%d Deliver PRIVATEINFO_VIDEO_NEW_SEG FAIL \n", __func__, __LINE__,pCh->tunerHandle);
		return -1;
	}
	if (DeliverPrivateInfo(pCh, pPinIBInfo, PRIVATEINFO_VIDEO_DECODE_COMMAND, (char *)&cmd, sizeof(DECODE), pPinInfo)<0){
		dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d: ch:%d Deliver PRIVATEINFO_VIDEO_DECODE_COMMAND FAIL \n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}

	Demux_Flush(pCh, (pin == VIDEO_PIN) ? DEMUX_TARGET_VIDEO : DEMUX_TARGET_VIDEO_2ND);
	REFCLK_Reset(DEMUX_GetReferenceClock(pCh), pCh->avSyncMode, pCh->videoFreeRunThreshold);
	PCRSYNC_Reset(&pCh->pcrProcesser, DEMUX_GetReferenceClock(pCh), pCh->tunerHandle, pCh->pPcrRecoveryManager);
	BufferFullDroppingReset(pCh, 0, 1);
	if (pCh->tp_src != MTP)
		DEMUX_ResetAVSync(pCh, NAV_AVSYNC_PCR_MASTER);
	else if(pCh->avSyncMode == MTP_AVSYNC_MODE && pCh->tp_src == MTP)
	    DEMUX_ResetAVSync(pCh, MTP_AVSYNC_MODE);
	
	rtkdemux_dbg_dump_bitstream_flush(pCh->tunerHandle, pin);
	return 0;
}
int DEMUX_EVENT_FlushAudio(demux_channel *pCh, int pin)
{
	DEMUX_BUF_PIN_T *pPinInfo, *pPinIBInfo;
	AUDIODECODECOMMAND cmd ;
	memset(&cmd, 0, sizeof(AUDIODECODECOMMAND)) ;
	cmd.mode = AUDIO_DECODE ;
	cmd.relativePTS =  0 ;
	cmd.duration    = -1 ;

	Demux_Flush(pCh, (pin == AUDIO_PIN) ? DEMUX_TARGET_AUDIO : DEMUX_TARGET_AUDIO_2ND);
	BufferFullDroppingReset(pCh, pin, 0);

	pPinInfo   = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
	pPinIBInfo = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
	if (DeliverPrivateInfo(pCh, pPinIBInfo, PRIVATEINFO_AUDIO_NEW_SEG       ,         NULL, sizeof(AUDIO_DEC_NEW_SEG), pPinInfo)<0)
	{
		dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d: ch:%d Deliver PRIVATEINFO_AUDIO_NEW_SEG FAIL \n", __func__, __LINE__,pCh->tunerHandle);
		return -1;
	}
	if (DeliverPrivateInfo(pCh, pPinIBInfo, PRIVATEINFO_AUDIO_DECODE_COMMAND, (char *)&cmd, sizeof(AUDIO_DEC_DECODE) , pPinInfo)<0)
	{
		dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d: ch:%d Deliver PRIVATEINFO_AUDIO_DECODE_COMMAND FAIL \n", __func__, __LINE__,pCh->tunerHandle);
		return -1;
	}
	rtkdemux_dbg_dump_bitstream_flush(pCh->tunerHandle, pin);
	return 0;
}
int DEMUX_EVENT_AudioNewFormat(demux_channel *pCh, int pin, DEMUX_AUDIO_DEC_T audioFormat, long privateInfo[8])
{
	int target;
	AUDIO_DEC_NEW_FORMAT cmd ;
	cmd.header.type = AUDIO_DEC_INBAMD_CMD_TYPE_NEW_FORMAT ;
	cmd.header.size = sizeof(AUDIO_DEC_NEW_FORMAT);
	cmd.audioType   = audioFormat ;
	memcpy(cmd.privateInfo, privateInfo, sizeof (cmd.privateInfo)) ;

	target = (pin == AUDIO_PIN) ? DEMUX_TARGET_AUDIO : DEMUX_TARGET_AUDIO_2ND;
	Demux_Flush(pCh, target);
	BufferFullDroppingReset(pCh, pin, 0);
	if (DeliverPrivateInfo(pCh, &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB], PRIVATEINFO_AUDIO_FORMAT, (char *)&cmd, sizeof(AUDIO_DEC_NEW_FORMAT), &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS])<0)
	{
		dmx_mask_print(DEMUX_NOMAL_DEBUG,"%s, %d: ch:%d Deliver PRIVATEINFO_AUDIO_FORMAT FAIL !!!!\n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}
	dmx_notice("%s,%d, ch:%d, pin:%d, audioFormat:%d\n", __func__, __LINE__, pCh->tunerHandle, pin, audioFormat);
	pCh->activeTarget[target].format = audioFormat ;

	/*
	* WOSQRTK-10314
	* If during PVR playback, check audio stable if AduioNewFormat received (ex:switch audio language)
	*/
	if (pCh->tp_src == MTP) {
		REFCLOCK * const pRefClock = DEMUX_GetReferenceClock(pCh);
		int64_t videoSystemPTS = DEMUX_reverseLongInteger(pRefClock->videoSystemPTS);
		if (videoSystemPTS != -1) {
			/* from now on, we want to take only 200 ms to check if audio can be stable or not */
			pCh->startCheckAudioStable = CLOCK_GetPTS();
			/* start to check if it is possible that audio can catch video or not */
			SET_FLAG(pCh->status, STATUS_CHECK_PVR_AUDIO_STABLE);
			/* audio is not master at the beginning of audio language change */
			RESET_FLAG(pCh->status, STATUS_PVR_AUDIO_IS_STABLE);
			dmx_mask_print(DEMUX_AUDIO_STABLE_DEBUG, "[%s %d] Check audio stable start ....\n", __func__, __LINE__);
		}
	}
	return 0;
}
void DEMUX_EVENT_FlushTPBuffer(demux_channel *pCh)
{
	if (pCh->AdChannelTarget != -1){
		SET_FLAG(pCh->events, EVENT_FLUSH_AD_INFO);
	}

	RELEASE_TP_BUFFER();
	RHAL_TPFlushBuffer(pCh->tunerHandle);
}
#if defined(DEMUX_VIDEO_USE_PINGPONG_BUFFERS)
void DEMUX_UpdatePinInfo(demux_channel *pCh, char bVideoPin)
{
	int i;
	DEMUX_BUF_PIN_T *pPinInfo, *pPinIBInfo;
	DEMUX_BUF_T *pBufBS, *pBufIB, *pBufBSH, *pBufIBH;

	for (i = VIDEO_PIN; i < NUMBER_OF_PINS; i++) {
		if ((bVideoPin && (i == AUDIO_PIN || i== AUDIO2_PIN))
		|| (!bVideoPin && (i == VIDEO_PIN || i == VIDEO2_PIN)))
			continue;

		if (pCh->tmpPinInfo[i].pinInfoStatus == PININFO_DONE)
			continue;

		if (pCh->tmpPinInfo[i].pinInfoStatus == PININFO_FREE) {
			memset(&pCh->pinInfo[i], 0, sizeof(DEMUX_OUT_T));
			if (pCh->tmpPinInfo[i].bufIndex >= 0) {
				mutex_lock(&demux_device->mutex) ;
				dmx_crit("[%s %d] CH%d pin %d buffer %d is released\n", __func__, __LINE__, pCh->tunerHandle, i, pCh->tmpPinInfo[i].bufIndex);

				if (i == VIDEO_PIN || i == VIDEO2_PIN) {
				#if defined(DEMUX_VIDEO_USE_PINGPONG_BUFFERS)
					demux_device->bVideoBufUsed[pCh->tmpPinInfo[i].bufIndex] = 0;
				#endif
				}
				pCh->tmpPinInfo[i].bufIndex = -1;
				mutex_unlock(&demux_device->mutex);
			}
			pCh->tmpPinInfo[i].pinInfoStatus = PININFO_DONE;
			continue;
		}
		pCh->tmpPinInfo[i].pinInfoStatus = PININFO_DONE;

		if(i == VIDEO_PIN || i == VIDEO2_PIN) {
		#if defined(DEMUX_VIDEO_USE_PINGPONG_BUFFERS)
			pBufBSH  = &demux_device->bsVideoBufH[pCh->tmpPinInfo[i].bufIndex];
			pBufIBH  = &demux_device->ibVideoBufH[pCh->tmpPinInfo[i].bufIndex];
			pBufBS   = &demux_device->bsVideoBuf[pCh->tmpPinInfo[i].bufIndex];
			pBufIB   = &demux_device->ibVideoBuf[pCh->tmpPinInfo[i].bufIndex];
		#else
			continue;
		#endif
		} else {
			continue;
		}

		pPinInfo   = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_BS];
		pPinIBInfo = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_IB];
		IOCTL_SetPinInfo(pPinIBInfo, (RINGBUFFER_HEADER *)pBufIBH->virAddr, pBufIB);
		IOCTL_SetPinInfo(pPinInfo, (RINGBUFFER_HEADER *)pBufBSH->virAddr, pBufBS);
	}
}
#endif


bool DEMUX_channelStatusCheck(demux_channel *pCh, NAVBUF *pBuffer, bool isProhibited){

	if (pCh== NULL || pBuffer == NULL)
		return false;
	
	if (pCh->bUpdateDemuxTarget) {
		pBuffer->type = NAVBUF_NONE ;

		mutex_lock(&pCh->mutex) ;
		if (pCh->bUpdateDemuxTarget) {
			UpdateDemuxTarget(pCh, pBuffer) ;

		#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
			DEMUX_UpdatePinInfo(pCh, 1);
		#else
			DEMUX_BUF_UpdatePinInfo(pCh, 1);
		#endif
		#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
			DEMUX_PESBuffer_UpdateBuferStatus(pCh);
		#endif
		}

		mutex_unlock(&pCh->mutex) ;
		return true;
	}

	if (pCh->status){
		handleUnpedingEvents(pCh);
	}
	if (isProhibited) {
		pBuffer->type = NAVBUF_WAIT;
		pBuffer->wait.waitTime = 10;
		return true;
	}

	if (pCh->events != 0) {
		pBuffer->type = NAVBUF_NONE ;
		mutex_lock(&pCh->mutex) ;
		HandleEvents(pCh, pBuffer) ;
		mutex_unlock(&pCh->mutex) ;
		return true;
	}

	return false;
}

int DEMUX_ReadData(demux_channel *pCh, NAVBUF *pBuffer)
{
	int ret ;

	RELEASE_TP_BUFFER();
	pBuffer->data.payloadData = 0;
	pBuffer->data.payloadSize = 0;
	/*  printk("func %s, %d\n", __func__, isProhibited) ; */
	ret = RHAL_TPReadData(pCh->tunerHandle, &pBuffer->data.payloadData, (UINT32 *)(&pBuffer->data.payloadSize), pCh->dataThreshold) ;
	if (pBuffer->data.payloadSize) {
		pBuffer->data.payloadData -= pCh->phyAddrOffset ; /* convert to cached address */
		pBuffer->data.payloadSize -= (pBuffer->data.payloadSize % pCh->tsPacketSize);  /* align size to DTV_LEAST_DELIVER_SIZE before demuxing */
		if(pCh->pcrProcesser.pcrExistDetect.checkPacketReady == false)
			pCh->pcrProcesser.pcrExistDetect.checkPacketReady = true;
	}


	if (pCh->tp_src == MTP) { /* don't care buffer full on MTP mode */
		if (ret == TPK_BUFFER_FULL) {
			ret = TPK_SUCCESS ;
			DBG_Warning(DGB_COLOR_RED_WHITE" func %s, buffer full, tp %d, addr %p, phyAddr %p, size %d, ret %d\n"DGB_COLOR_NONE, __func__, pCh->tunerHandle, pBuffer->data.payloadData, pBuffer->data.payloadData + pCh->phyAddrOffset, pBuffer->data.payloadSize, ret) ;
		}
		if (pBuffer->data.payloadSize > pCh->tsPacketSize*1024*2)
			pBuffer->data.payloadSize = pCh->tsPacketSize*1024*2;
	}

	if (ret == TPK_BUFFER_FULL) {
		dmx_warn(DGB_COLOR_RED_WHITE" func %s, buffer full, tp %d, addr %p, phyAddr %p, size %d\n"DGB_COLOR_NONE, __func__, pCh->tunerHandle, pBuffer->data.payloadData, pBuffer->data.payloadData+pCh->phyAddrOffset, pBuffer->data.payloadSize) ;
		pBuffer->type = NAVBUF_SHORT_WAIT;
		pBuffer->wait.waitTime = TUNER_DATA_READ_WAIT_TIME;

		pCh->pTPRelase     = pBuffer->data.payloadData ;
		pCh->TPReleaseSize = pBuffer->data.payloadSize ;
		RELEASE_TP_BUFFER();
		pCh->lastStampedPTS = -1 ;
		return 0 ;
	} else if (ret == TPK_SUCCESS && pBuffer->data.payloadSize >= pCh->tsPacketSize) {
		/*      printk("func %s, line %d, addr %x, phyAddr %x, size %d\n", __func__, __LINE__, pBuffer->data.payloadData, pBuffer->data.payloadData+pCh->phyAddrOffset,pBuffer->data.payloadSize) ; */
		pBuffer->type = NAVBUF_DATA;
		pBuffer->data.startAddress = 0xFFFFFFFF;
		pBuffer->data.infoId = PRIVATEINFO_NONE;
		/*  #ifdef IS_ARCH_ARM_COMMON */
		if (pCh->phyAddrOffset != 0) {
			pBuffer->type =  NAVBUF_DATA_EXT;
			pBuffer->data.phyAddrOffset = pCh->phyAddrOffset;
		}
		/*  #endif */

		pCh->pTPRelase     = pBuffer->data.payloadData ;
		pCh->TPReleaseSize = pBuffer->data.payloadSize ;
		pCh->dataThreshold = TUNER_DATA_READ_THRESHOLD ;

		rtk_inv_range(pCh->pTPRelase, pCh->pTPRelase+pCh->TPReleaseSize) ;

		rtkdemux_dbg_dump_ts(pCh->tunerHandle, pBuffer->data.payloadData, pBuffer->data.payloadSize);


		if (pCh->lastStampedPTS == -1) {
			pCh->lastStampedPTS = CLOCK_GetPTS();
			pCh->bytes           = 0 ;
		}

		pCh->bytes += pBuffer->data.payloadSize ;
		if (pCh->bytes >= MAX_BYTES_TO_CALC_RATE) {
			int64_t curPTS = CLOCK_GetPTS() ;
			if (curPTS > pCh->lastStampedPTS) { /* calculate bitrate */
				pCh->bitRate = div_s64(((int64_t)pCh->bytes << 3) * DEMUX_CLOCKS_PER_SEC, (curPTS - pCh->lastStampedPTS)) ;
			}
			pCh->lastStampedPTS = curPTS ;
			pCh->bytes           = 0 ;
		}

	} else {
		/*
		if (pBuffer->data.payloadSize)
		{
			printk("func %s, buffer size %d < %d\n", __func__, pBuffer->data.payloadSize, DTV_LEAST_DELIVER_SIZE) ;
		}*/
		pBuffer->type = NAVBUF_SHORT_WAIT;
		pBuffer->wait.waitTime = DEMUX_GetWaitTime(pCh) ;
		pCh->dataThreshold = 0; /* next time, no matter how much data in buffer, I will read anyway */
	}

	return 0 ;
}

void CheckScrambling(demux_channel *pCh, unsigned char *pData)
{
	if (IS_START_UNIT(pData) && HAS_PAYLOAD(pData)) {
		// check the value of the transport_scrambling_control field for  TS payload
		int pid = PID(pData) ;
		if (pData[3] & 0xC0) {
			SET_FLAG(pCh->chkScrambleTable[pid], PID_IS_SCRAMBLE);
		} else {
			RESET_FLAG(pCh->chkScrambleTable[pid], PID_IS_SCRAMBLE);
		}

		if (!HAS_FLAG(pCh->chkScrambleTable[pid], PID_SCRAMBLE_CHECKED)) {
			SET_FLAG(pCh->chkScrambleTable[pid], PID_SCRAMBLE_CHECKED);
		}
	}
}

void ParsePCR(demux_channel *pCh, unsigned char *pTsPacket)
{
	int64_t PCRBase, PCR;
	SWDEMUXPCR* pSwPCRInfo = &pCh->pcrProcesser.swPCRInfo;
	int afLen = pTsPacket[4];
	int PCRFlag = (pTsPacket[5] & 0x10);
	if(!PCRFlag || afLen < 7) return;
	PCRBase = (((long long)pTsPacket[6] << 25) | ((long long)pTsPacket[7] << 17) | ((long long)pTsPacket[8] << 9) | ((long long)pTsPacket[9] < 1) | (((long long)pTsPacket[10] & 0x80) >> 7));
	PCR = PCRBase;/*PCRBase * 300 + PCRExt*/;
	pCh->pcrProcesser.pcrExistDetect.newPCR = PCR;
	pSwPCRInfo->aPCR = PCR;
	pSwPCRInfo->vPCR = PCR;
	pSwPCRInfo->aPcrOffset = 0;
	pSwPCRInfo->vPcrOffset = 0;
	//dmx_crit("[%s]PCR = %lld\n", __func__, PCR);
}

bool SendPCR(NAVDEMUXOUT *pDemuxOut, unsigned char *pTsPacket)
{
	int64_t pcr = -1, stc = -1;

	if (AF_LENGTH(pTsPacket) < 25)
		return false;

	if (!IS_RTKPVR(pTsPacket))
		return false;

	pcr = *((int64_t *)(pTsPacket + 16));
	stc = *((int64_t *)(pTsPacket + 24));
	/*
	   int len = pTsPacket[6];
	   if (len > 25)
	   g_streamingRate = *((long*)(pTsPacket + 32));

	   navBuffers[pDemuxOut->numBuffers].type = NAVBUF_ADJUST_CLOCK;
	   navBuffers[pDemuxOut->numBuffers].clock.pcr = pcr;
	   navBuffers[pDemuxOut->numBuffers].clock.stc = stc+pli_getPTS();
	   printf("[%s %d] %s - pcr = %lld, stc_diff = %lld, stc = %lld\n", __FILE__, __LINE__, __func__, pcr, stc, navBuffers[pDemuxOut->numBuffers].clock.stc);

	   pDemuxOut->numBuffers++;*/
	return true;
}


void DEMUX_UpdateADInfo(demux_channel *pCh, int target, unsigned char AD_fade_byte, unsigned char AD_pan_byte, char AD_gain_byte_center, char AD_gain_byte_front, char AD_gain_byte_surround)
{
	if(pCh->adInfo.AD_fade_byte != AD_fade_byte || pCh->adInfo.AD_pan_byte != AD_pan_byte
		|| pCh->adInfo.AD_gain_byte_center != AD_gain_byte_center || pCh->adInfo.AD_gain_byte_front != AD_gain_byte_front
		|| pCh->adInfo.AD_gain_byte_surround != AD_gain_byte_surround) {
		pCh->adInfo.AD_fade_byte = AD_fade_byte;
		pCh->adInfo.AD_pan_byte = AD_pan_byte;
		pCh->adInfo.AD_gain_byte_center = AD_gain_byte_center;
		pCh->adInfo.AD_gain_byte_front = AD_gain_byte_front;
		pCh->adInfo.AD_gain_byte_surround = AD_gain_byte_surround;

		dmx_notice("[ad] %s :AD_fade_byte %d AD_pan_byte %d AD_gain_byte_center %d AD_gain_byte_front %d AD_gain_byte_surround %d\n",
			__FUNCTION__,pCh->adInfo.AD_fade_byte,pCh->adInfo.AD_pan_byte,pCh->adInfo.AD_gain_byte_center,
			pCh->adInfo.AD_gain_byte_front,pCh->adInfo.AD_gain_byte_surround);
		SET_FLAG(pCh->demuxTargetInfo[target].events, EVENT_UPDATE_AD_INFO);
	}
}
void DEMUX_ParseADInfo(demux_channel *pCh, int target, const unsigned char *pCurr, unsigned int headerLen, unsigned int pesHdrOffset)
{
	if (headerLen >= PES_HEADER_MIN_SIZE && (pCurr[7] & 0x40)) /* has DTS */
		pesHdrOffset += 5;      /* DTS data size */

	if (headerLen >= PES_HEADER_MIN_SIZE && (pCurr[7] & 0x20)) /* has ESCR */
		pesHdrOffset += 6;      /* ESCR data size */

	if (headerLen >= PES_HEADER_MIN_SIZE && (pCurr[7] & 0x10)) /* has ES rate */
		pesHdrOffset += 3;      /* ES rate data size */

	if (headerLen >= PES_HEADER_MIN_SIZE && (pCurr[7] & 0x08)) /* has DSM_trick_mode */
		pesHdrOffset += 1;      /* DSM_trick_mode data size */

	if (headerLen >= PES_HEADER_MIN_SIZE && (pCurr[7] & 0x04)) /* has additional_copy_info */
		pesHdrOffset += 1;      /* additional_copy_info data size */

	if (headerLen >= PES_HEADER_MIN_SIZE && (pCurr[7] & 0x02)) /* has PES_CRC */
		pesHdrOffset += 2;      /* PES_CRC data size */

	if (headerLen >= PES_HEADER_MIN_SIZE && (pCurr[7] & 0x01) && (pesHdrOffset < headerLen)) /* has PTS */ {
		const unsigned char *pPesExten = pCurr + pesHdrOffset;
		if ((pPesExten[0] & 0x80) && ((pesHdrOffset + 1 + 16) <= headerLen)) {
			const unsigned char *pAD_descriptor = pPesExten + 1;

			if (((pAD_descriptor[0] & 0x0f) >= 8)  && (pAD_descriptor[1] == 0x44) &&
				(pAD_descriptor[2] == 0x54) && (pAD_descriptor[3] == 0x47) &&
				(pAD_descriptor[4] == 0x41) && (pAD_descriptor[5] == 0x44)) {
			    //printk("AD_fade_byte: 0x%x, AD_pan_byte: 0x%x.\n", AD_fade_byte(pAD_descriptor), AD_pan_byte(pAD_descriptor));
				pCh->AdChannelTarget = target;
				if (AD_version_text_tag(pAD_descriptor) == 0x32) {
                    //printf("AD_gain_byte_center: 0x%x, AD_gain_byte_front: 0x%x , AD_gain_byte_surround: 0x%x.\n", AD_gain_byte_center(pAD_descriptor), AD_gain_byte_front(pAD_descriptor),AD_gain_byte_surround(pAD_descriptor));
					DEMUX_UpdateADInfo(pCh, target,AD_fade_byte(pAD_descriptor),AD_pan_byte(pAD_descriptor),AD_gain_byte_center(pAD_descriptor), AD_gain_byte_front(pAD_descriptor),AD_gain_byte_surround(pAD_descriptor));
				} else {
					DEMUX_UpdateADInfo(pCh, target,AD_fade_byte(pAD_descriptor),AD_pan_byte(pAD_descriptor),0,0,0);
				}
			}
		}
	}
}

void ParsePESHeader(demux_channel *pCh, int target, const unsigned char *pCurr, unsigned int len)
{
	unsigned int headerLen;
	unsigned int pesHdrBufSize = PES_HEADER_BUF_SIZE;

	if (pCh->demuxTargetInfo[target].bufferedBytes + len < pesHdrBufSize) {
		DMX_MEMCPY(pCh->demuxTargetInfo[target].pesHeaderBuf + pCh->demuxTargetInfo[target].bufferedBytes, pCurr, len);

		if (pCh->demuxTargetInfo[target].bufferedBytes + len < PES_HEADER_MIN_SIZE) {
			pCh->demuxTargetInfo[target].remainingHeaderBytes = PES_HEADER_MIN_SIZE - pCh->demuxTargetInfo[target].bufferedBytes;
			pCh->demuxTargetInfo[target].bufferedBytes += len;
		} else {
			headerLen = pCh->demuxTargetInfo[target].pesHeaderBuf[8] + PES_HEADER_MIN_SIZE;

			pCh->demuxTargetInfo[target].remainingHeaderBytes = headerLen - pCh->demuxTargetInfo[target].bufferedBytes;
			pCh->demuxTargetInfo[target].bufferedBytes += len;

			if (headerLen < pesHdrBufSize)
				pCh->demuxTargetInfo[target].bufferedBytes = 0;
		}
	} else {
		unsigned int pesHdrOffset;
		if (pCh->demuxTargetInfo[target].bufferedBytes > 0) {
			DMX_MEMCPY(pCh->demuxTargetInfo[target].pesHeaderBuf + pCh->demuxTargetInfo[target].bufferedBytes, pCurr,
					pesHdrBufSize - pCh->demuxTargetInfo[target].bufferedBytes);

			pCurr = pCh->demuxTargetInfo[target].pesHeaderBuf;
		}

		headerLen = pCurr[8] + PES_HEADER_MIN_SIZE;

		pCh->demuxTargetInfo[target].remainingHeaderBytes = headerLen - pCh->demuxTargetInfo[target].bufferedBytes;
		pCh->demuxTargetInfo[target].bufferedBytes = 0;
		pesHdrOffset = PES_HEADER_MIN_SIZE;

		if (headerLen >= PES_HEADER_BUF_SIZE && (pCurr[7] & 0x80)) { /* has PTS */
			pCh->demuxTargetInfo[target].pts = (((int64_t)pCurr[9]  & 0x0E) << 29) |
				(pCurr[10]         << 22) |
				((pCurr[11] & 0xFE) << 14) |
				(pCurr[12]         <<  7) |
				((pCurr[13] & 0xFE) >>  1);
			pesHdrOffset += 5;	/* PTS data size */

#ifndef DONTFIXBUG13648
			if (pCh->demuxTargetInfo[target].bResyncPTS)
				pCh->demuxTargetInfo[target].bResyncPTS = false;
#endif

			if(DEMUX_IS_AUDIO_TARGET(target) && target != pCh->AdChannelTarget)
			{
				SWDEMUXPCR* pSwPCRInfo = &pCh->pcrProcesser.swPCRInfo;
				if (pSwPCRInfo->aPCR != -1)
				{
					pSwPCRInfo->aPcrOffset = pCh->demuxTargetInfo[target].pts - pSwPCRInfo->aPCR;
					pSwPCRInfo->aPcrRef = pSwPCRInfo->aPCR;
					pSwPCRInfo->aPCR = -1;
					if (pSwPCRInfo->aPrevDemuxPTS != -1)
					{
						pSwPCRInfo->aByteRate = 0; // (pCh->demuxTargetInfo[target].pts > pSwPCRInfo->aPrevDemuxPTS) ? div_s64(pSwPCRInfo->aReadSize * DEMUX_CLOCKS_PER_SEC, pCh->demuxTargetInfo[target].pts - pSwPCRInfo->aPrevDemuxPTS) : 0;
						pSwPCRInfo->aReadSize = 0;
					}
					pSwPCRInfo->aPrevDemuxPTS = pCh->demuxTargetInfo[target].pts;
					//dmx_crit("[%s]aPcrOffset = %lld, aByteRate = %d\n", __func__, pSwPCRInfo->aPcrOffset, pSwPCRInfo->aByteRate);
				}
			}
			else if (DEMUX_IS_VIDEO_TARGET(target) )
			{
				SWDEMUXPCR* pSwPCRInfo = &pCh->pcrProcesser.swPCRInfo;
				if (pSwPCRInfo->vPCR != -1)
				{
					pSwPCRInfo->vPcrOffset = pCh->demuxTargetInfo[target].pts - pSwPCRInfo->vPCR;
					pSwPCRInfo->vPcrRef = pSwPCRInfo->vPCR;
					pSwPCRInfo->vPCR = -1;
					if (pSwPCRInfo->vPrevDemuxPTS != -1)
					{
						pSwPCRInfo->vByteRate = 0; // (pCh->demuxTargetInfo[target].pts > pSwPCRInfo->vPrevDemuxPTS) ? div_s64(pSwPCRInfo->vReadSize * DEMUX_CLOCKS_PER_SEC, pCh->demuxTargetInfo[target].pts - pSwPCRInfo->vPrevDemuxPTS) : 0;
						pSwPCRInfo->vReadSize = 0;
					}
					pSwPCRInfo->vPrevDemuxPTS = pCh->demuxTargetInfo[target].pts;
					//dmx_crit("[%s]vPcrOffset = %lld, vByteRate = %d\n", __func__, pSwPCRInfo->vPcrOffset, pSwPCRInfo->vByteRate);
				}
			}
		}
		DEMUX_ParseADInfo(pCh, target, pCurr, headerLen, pesHdrOffset);
	}
}
bool ParsePacketCB(demux_channel *pCh, int target, unsigned char *pPacketStart,  int phyAddrOffset)
{
	DEMUX_PES_TARGET_T *pTarget = &pCh->activePESTarget[target] ;
	DEMUX_PES_MAP_T *pMap = &pCh->pesMap[target];
	unsigned char *pData = pPacketStart + 4 ;
	int size = 184 ;
    int count ;
	if (HAS_AF(pPacketStart)) {
		int len = AF_LENGTH(pPacketStart) + 1;

		if (len < 184) {
			pData += len;
			size  -= len;
		} else {
			size = 0;
		}

		if (len > 1 && IS_DISCONTI(pPacketStart))
			pTarget->contiCounter = -1 ;
	}

	if (!HAS_PAYLOAD(pPacketStart))
		return true;

	/******************* Check CC start **************************/
	count = CONTI_COUNT(pPacketStart);

	if (pTarget->contiCounter == -1)
		pTarget->contiCounter = count;
	else {
		if (pTarget->contiCounter == count) {/* duplicated packet */
			if (pTarget->bCheckContiCounter || IS_TRANSPORT_ERROR(pPacketStart))
				size = 0;
		} else {
			pTarget->contiCounter = (pTarget->contiCounter + 1) & 0xF;

			if (pTarget->contiCounter != count) { /* continuity_counter is not continuous */
				DMX_WARNING_CC(("ParsePacketCB: [target:%d] detect discontinuous continuity-counter (%d != %d)\n",
							target, pTarget->contiCounter, count));

				DMX_LUMPSUM_ADD("ParsePacketCB: CC discontinuous");
				if (pTarget->bCheckContiCounter || IS_TRANSPORT_ERROR(pPacketStart)) {
					pTarget->contiCounter = -1;
					return true;
				}
				else
				{
					pTarget->contiCounter = -1;
				}
			}
		}
	}
	/******************* Check CC end **************************/

	if (size > 0) {
		unsigned long space, rd, wr;
		unsigned char *pCurWr;
		int isStartUnit = IS_START_UNIT(pPacketStart) ;
		if (!pMap->size && !isStartUnit)
			return false ;
		if (isStartUnit && pMap->size != 0){
			//last data not finish, and jump to new packet.so drop last data start new one
			//WOSQRTK-3068
			pMap->size = 0;
		}
		rd = *pMap->pRdPtr;
		wr = *pMap->pWrPtr;
		pCurWr = (unsigned char *)(wr + pMap->size);
		if (pCurWr >= pMap->pBufferUpper)
			pCurWr -= (pMap->pBufferUpper - pMap->pBufferLower);
		space = BS_DISTANCE(pCurWr, (unsigned char *)rd, pMap->pBufferLower, pMap->pBufferUpper);
		//for first packet ,packet pes size+ pes_length_byte
		if (space <= size +DEMUX_PESDATA_PREFIX_LENGTH) { /* ringbuffer full, re-sync StartUnit */
			dmx_warn("func %s, PES ringbuffer full, skip this unit(space %lu, size %d)!!\n", __func__, space, size) ;
			dmx_warn(
				"func %s, rd 0x%lx, wr 0x%lx, pLower 0x%lx, pUpper 0x%lx\n",
				__func__, rd, wr,
				(unsigned long)(uintptr_t)pMap->pBufferLower,
				(unsigned long)(uintptr_t)pMap->pBufferUpper
			);
			pMap->size = 0;
			return false;
		}

		if (isStartUnit) { /* reset buffer */
			pMap->unitSize =(((pData[4] << 8) | pData[5]) + (DEMUX_PESDATA_PREFIX_LENGTH+6));      /* PES_packet_length */
			/* 	[DEMUX_PESDATA_PREFIX_LENGTHbyte]  |[refer_first_two_byte]
				[pes_packet_lenght]	     |[pesdata]|
					|__________________|
			*/
			//pes prefix length
			*(pCurWr - pMap->phyAddrOffset) = ((pMap->unitSize-DEMUX_PESDATA_PREFIX_LENGTH)>>8) &0xff;
			if (pCurWr+1 >= pMap->pBufferUpper)
			{
				pCurWr =pMap->pBufferLower;
				*(pCurWr - pMap->phyAddrOffset) = (pMap->unitSize-DEMUX_PESDATA_PREFIX_LENGTH) &0xff;
				pCurWr++;
			}
			else{
			 	*(pCurWr - pMap->phyAddrOffset +1)= (pMap->unitSize-DEMUX_PESDATA_PREFIX_LENGTH) &0xff;
				pCurWr+=2;
			}

			if(pCurWr >=pMap->pBufferUpper)
				pCurWr =pMap->pBufferLower;

			pMap->size = DEMUX_PESDATA_PREFIX_LENGTH ;
		}
		if ((pMap->unitSize - pMap->size) < size )
			size = pMap->unitSize - pMap->size;
		pMap->size += size ;
		if (pMap->size > pMap->unitSize) { /* skip this pes */
			dmx_err("func %s, PES size is unmatch (accumulated %d,unit %d)!!\n", __func__, pMap->size, pMap->unitSize) ;
			pMap->size = 0 ;  /* re-sync StartUnit */
			return false ;
		}

		if (pCurWr + size >= pMap->pBufferUpper) {
			space = pMap->pBufferUpper - pCurWr;
			memcpy(pCurWr - pMap->phyAddrOffset, pData, space) ;
			memcpy(pMap->pBufferLower - pMap->phyAddrOffset, pData + space, size - space) ;
		} else {
			memcpy(pCurWr - pMap->phyAddrOffset, pData, size) ;
		}

		if (pMap->size == pMap->unitSize) {
			pCurWr += size;
			if (pCurWr >= pMap->pBufferUpper)
				pCurWr -= (pMap->pBufferUpper - pMap->pBufferLower) ;
			if(wr > (uintptr_t)pCurWr){
				space = (uintptr_t)pMap->pBufferUpper - wr;
				rtkdemux_dbg_dump_pes(pCh->tunerHandle, (char *)(wr - pMap->phyAddrOffset), space, pCh->activePESTarget[target].pid);
				rtkdemux_dbg_dump_pes(pCh->tunerHandle, (char *)(pMap->pBufferLower - pMap->phyAddrOffset), pMap->unitSize - space, pCh->activePESTarget[target].pid);
				DEMUX_flushMemory((unsigned char *)(wr - pMap->phyAddrOffset), (unsigned char *)wr, space);
				DEMUX_flushMemory(pMap->pBufferLower - pMap->phyAddrOffset, pMap->pBufferLower, pMap->unitSize - space);
			} else {
				rtkdemux_dbg_dump_pes(pCh->tunerHandle, (char *)(wr - pMap->phyAddrOffset), pMap->unitSize, pCh->activePESTarget[target].pid);
				DEMUX_flushMemory((unsigned char *)(wr - pMap->phyAddrOffset), (unsigned char *)wr, pMap->unitSize);
			}
			*pMap->pWrPtr = (unsigned long)pCurWr;
			demux_device->filter_flag = 1 ;
			pMap->size = 0;
			DEMUX_wakeUpPoll() ;
		}
	}

	return true ;
}

void DEMUX_PackPrivateInfo(unsigned int infoId, void* infoData, unsigned int infoSize, NAVBUF* pBuffer)
{
	pBuffer->type             = NAVBUF_DATA;
	pBuffer->data.payloadSize = 0;
	pBuffer->data.infoId      = infoId;
	pBuffer->data.infoData    = (unsigned char*)infoData;
	pBuffer->data.infoSize    = infoSize;
}
void DemuxOutPacket(demux_channel *pCh, int target, NAVDEMUXOUT *pDemuxOut, int phyAddrOffset)
{
	SWDEMUXPCR* pSwPCRInfo;

	// fixbug 18043; DONTFIXBUG13912
	if (HAS_FLAG(pCh->demuxTargetInfo[target].events, EVENT_DROP_PACKET)) {
		pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize = 0;
		return;
	}

#ifndef DONTFIXBUG13648
	if ((DEMUX_IS_AUDIO_TARGET(target) || DEMUX_IS_VIDEO_TARGET(target)) && pCh->demuxTargetInfo[target].bResyncPTS)
		pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize = 0;
	else
#endif
	{
		pCh->navBuffers[pDemuxOut->numBuffers].type              = (phyAddrOffset == 0) ? NAVBUF_DATA : NAVBUF_DATA_EXT;
		pCh->navBuffers[pDemuxOut->numBuffers].data.pinIndex     = pCh->demuxTargetInfo[target].pinIndex;
		pCh->navBuffers[pDemuxOut->numBuffers].data.pts          = pCh->demuxTargetInfo[target].pts;
		/*        pCh->navBuffers[pDemuxOut->numBuffers].data.channelIndex = GetChannelIndex(target);*/

		pCh->demuxTargetInfo[target].pts = -1;

		/*#ifdef IS_ARCH_ARM_COMMON */
		if (phyAddrOffset != 0) {
			pCh->navBuffers[pDemuxOut->numBuffers].type =  NAVBUF_DATA_EXT;
			pCh->navBuffers[pDemuxOut->numBuffers].data.phyAddrOffset = phyAddrOffset;
		}
/*    #endif */
		//put in last check
		if (/*target == TARGET_AUDIO_2ND && */HAS_FLAG(pCh->demuxTargetInfo[target].events, EVENT_UPDATE_AD_INFO)
			&& pDemuxOut->numBuffers < (NUM_OF_NAV_BUFFERS-1)) {

			pDemuxOut->numBuffers ++;
			RESET_FLAG(pCh->demuxTargetInfo[target].events, EVENT_UPDATE_AD_INFO);
			dmx_notice("[ad] EVENT_UPDATE_AD_INFO AD_fade_byte = 0x%x\n",pCh->adInfo.AD_fade_byte);
			/*
			printf("[ad] %s EVENT_UPDATE_AD_INFO fade:%d pan:%d center:%d front:%d surround:%d\n",__FUNCTION__,
				pAudioInfo->adInfo.AD_fade_byte,pAudioInfo->adInfo.AD_pan_byte,
				pAudioInfo->adInfo.AD_gain_byte_center,pAudioInfo->adInfo.AD_gain_byte_front,
				pAudioInfo->adInfo.AD_gain_byte_surround);
				*/
			DEMUX_PackPrivateInfo(PRIVATEINFO_AUDIO_AD_INFO, &pCh->adInfo, sizeof(AUDIO_AD_INFO), &pCh->navBuffers[pDemuxOut->numBuffers]);
            pCh->navBuffers[pDemuxOut->numBuffers].data.pinIndex     = pCh->demuxTargetInfo[target].pinIndex;
		}

		pSwPCRInfo = &pCh->pcrProcesser.swPCRInfo;
		if (DEMUX_IS_AUDIO_TARGET(target)) pSwPCRInfo->aReadSize += pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize;
		if (DEMUX_IS_VIDEO_TARGET(target)) pSwPCRInfo->vReadSize += pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize;

		pDemuxOut->numBuffers++;
		pCh->demuxTargetInfo[target].demuxedCount++;
	}
}

bool ParsePacket(demux_channel *pCh, /*in*/ int target, unsigned char *pPacketStart, int phyAddrOffset, /*out*/NAVDEMUXOUT *pDemuxOut)
{
	int count ;
	if (pCh->demuxTargetInfo[target].events != 0) {
		pCh->navBuffers[pDemuxOut->numBuffers].data.pinIndex = pCh->demuxTargetInfo[target].pinIndex;

		if (HAS_FLAG(pCh->demuxTargetInfo[target].events, EVENT_DISCONTINUITY)) {
			RESET_FLAG(pCh->demuxTargetInfo[target].events, EVENT_DISCONTINUITY);

			pCh->demuxTargetInfo[target].contiCounter         = -1;
			pCh->demuxTargetInfo[target].pts                  = -1;
			pCh->demuxTargetInfo[target].bufferedBytes        = 0;
			pCh->demuxTargetInfo[target].remainingHeaderBytes = 0;
			pCh->demuxTargetInfo[target].bResyncStartUnit     = true;
#ifndef DONTFIXBUG13648
			/*if (target == DEMUX_TARGET_AUDIO || target == DEMUX_TARGET_VIDEO)*/
			if (pCh->demuxTargetInfo[target].bSyncPTSEnable) {
				pCh->demuxTargetInfo[target].bResyncPTS = true;
				for (unsigned int i = 0; i < pDemuxOut->numBuffers ; i++) {
					if (pCh->navBuffers[i].data.pinIndex == (unsigned int)pCh->demuxTargetInfo[target].pinIndex) {
						pCh->navBuffers[i].data.payloadSize = 0;
					}
				}
			}
#endif
		}
	}

	pCh->navBuffers[pDemuxOut->numBuffers].data.payloadData = pPacketStart + 4;
	pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize = 184;
	pCh->navBuffers[pDemuxOut->numBuffers].data.infoId = PRIVATEINFO_NONE;
	/*    printk("payloadSize %d\n", pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize) ;*/
	if (HAS_AF(pPacketStart)) {
		int len = AF_LENGTH(pPacketStart) + 1;

		if (len < 184) {
			pCh->navBuffers[pDemuxOut->numBuffers].data.payloadData += len;
			pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize -= len;
		} else {
			pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize = 0;
		}

		if (len > 1 && IS_DISCONTI(pPacketStart))
			pCh->demuxTargetInfo[target].contiCounter = -1;
	}

	if (!HAS_PAYLOAD(pPacketStart))
		return true;

	/******************* Check CC start **************************/
	/*
	//for bug 12007
	//if (demuxTargetInfo[target].bCheckContiCounter) {
	 */
	count = CONTI_COUNT(pPacketStart);

	if (pCh->demuxTargetInfo[target].contiCounter == -1)
		pCh->demuxTargetInfo[target].contiCounter = count;
	else {
		if (pCh->demuxTargetInfo[target].contiCounter == count) { /* duplicated packet*/
			if (pCh->demuxTargetInfo[target].bCheckContiCounter || IS_TRANSPORT_ERROR(pPacketStart))
				pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize = 0;
		} else {
			pCh->demuxTargetInfo[target].contiCounter = (pCh->demuxTargetInfo[target].contiCounter + 1) & 0xF;

			if (pCh->demuxTargetInfo[target].contiCounter != count) { /* continuity_counter is not continuous */
				DMX_WARNING_CC(("ParsePacket: [target:%d] detect discontinuous continuity-counter (%d != %d)\n",
							target,pCh->demuxTargetInfo[target].contiCounter, count));

				DMX_LUMPSUM_ADD("ParsePacket: CC discontinuous");

				if (pCh->demuxTargetInfo[target].bCheckContiCounter || IS_TRANSPORT_ERROR(pPacketStart)) {
					SET_FLAG(pCh->demuxTargetInfo[target].events, EVENT_DISCONTINUITY);
					return true;
				} else {
					pCh->demuxTargetInfo[target].contiCounter = -1;
				}
			}
		}
	}
	/*}*/
	/******************* Check CC end **************************/
	if (pCh->demuxTargetInfo[target].bResyncStartUnit) {
		if (IS_START_UNIT(pPacketStart) || pCh->demuxTargetInfo[target].bKeepPES)
			pCh->demuxTargetInfo[target].bResyncStartUnit = false;
		else
			pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize = 0;
	}

	if ((int)pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize <= 0)
		return true;

	if ((!IS_START_UNIT(pPacketStart) && pCh->demuxTargetInfo[target].remainingHeaderBytes == 0) ||
		pCh->demuxTargetInfo[target].bKeepPES) {
		DemuxOutPacket(pCh, target, pDemuxOut, phyAddrOffset);
	} else {
		const unsigned char * const payload     = pCh->navBuffers[pDemuxOut->numBuffers].data.payloadData;
		const size_t                payloadSize = pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize;
		if (IS_START_UNIT(pPacketStart)) {
			if (HAS_PACKET_START_CODE(payload)) {
				pCh->demuxTargetInfo[target].bufferedBytes = 0;

				ParsePESHeader(pCh, target, payload, payloadSize);
			} else {
				return false;
			}
		} else if (pCh->demuxTargetInfo[target].bufferedBytes > 0) {
			ParsePESHeader(pCh, target, payload, payloadSize);
		}

		if (pCh->demuxTargetInfo[target].remainingHeaderBytes < pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize) {
			pCh->navBuffers[pDemuxOut->numBuffers].data.payloadData += pCh->demuxTargetInfo[target].remainingHeaderBytes;
			pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize -= pCh->demuxTargetInfo[target].remainingHeaderBytes;
			pCh->demuxTargetInfo[target].remainingHeaderBytes = 0;

			DemuxOutPacket(pCh, target, pDemuxOut, phyAddrOffset);
		} else {
			pCh->demuxTargetInfo[target].remainingHeaderBytes -= pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize;
			pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize = 0;
			/*
			//            assert(pCh->demuxTargetInfo[target].remainingHeaderBytes > 0 || pCh->demuxTargetInfo[target].bufferedBytes == 0);

			//        #ifndef DONTFIXBUG21129
			//            CheckEventAudioDatatDiscontinuity(DEMUX_TARGET_AUDIO, pDemuxOut);
			//            #if defined(ENABLE_DTV_DUAL_AUDIO)
			//                CheckEventAudioDatatDiscontinuity(DEMUX_TARGET_AUDIO_2ND, pDemuxOut);
			//            #endif
			//        #endif //DONTFIXBUG21129
			 */
		}
	}
	return true;
}
void Demux_Flush(demux_channel *pCh, int target)
{
    if ((pCh->AdChannelTarget != -1) &&(pCh->AdChannelTarget == target) ){
	pCh->AdChannelTarget = -1;
        SET_FLAG(pCh->events, EVENT_FLUSH_AD_INFO);
    }
	pCh->demuxTargetInfo[target].events = 0;
	pCh->demuxTargetInfo[target].contiCounter         = -1;
	pCh->demuxTargetInfo[target].pts                  = -1;
	pCh->demuxTargetInfo[target].bufferedBytes        = 0;
	pCh->demuxTargetInfo[target].remainingHeaderBytes = 0;
	pCh->demuxTargetInfo[target].bResyncStartUnit     = true;
	pCh->demuxTargetInfo[target].bSyncPTSEnable = false;
	pCh->demuxTargetInfo[target].bResyncPTS = false;
	pCh->demuxTargetInfo[target].bSyncPTSEnable = 0;//DEMUX_IS_AUDIO_TARGET(target) && (pCh->tp_src == MTP);
	pCh->demuxTargetInfo[target].bResyncPTS = pCh->demuxTargetInfo[target].bSyncPTSEnable;
}
int Demux_Parse(demux_channel *pCh, NAVDEMUXIN *pDemuxIn, NAVDEMUXOUT *pDemuxOut)
{
	unsigned char *pNextCachePreloadPos ;
	int i ;
	pDemuxOut->numBuffers = 0;
	pDemuxOut->pNavBuffers = pCh->navBuffers;

	/* at the very beginning of multiplex buffer, preload the 4 bytes long header of the first PRELOAD_STEP TS packets */
	if (pDemuxIn->pCurr == pDemuxIn->pBegin) {
		pNextCachePreloadPos = pDemuxIn->pCurr;

		for (i = 0; i < PRELOAD_STEP; i++) {
			if (pNextCachePreloadPos+4 > pDemuxIn->pEnd)
				break;

			DMX_PRELOAD(pNextCachePreloadPos, 4);
			pNextCachePreloadPos += pCh->tsPacketSize;
		}
		if(pCh->tsPacketSize == 192) {
			pDemuxIn->pCurr += 4;
			pNextCachePreloadPos += 4;
		}
	}

	pNextCachePreloadPos = pDemuxIn->pCurr + PRELOAD_STEP * pCh->tsPacketSize ;

	/* other un-demuxed packets comes, reset demux counter */
	for (i = 0; i < DEMUX_NUM_OF_TARGETS; i++)
		pCh->demuxTargetInfo[i].demuxedCount = 0 ;

	while (pDemuxIn->pCurr+188 <= pDemuxIn->pEnd) {
		int target;
		int targetCB ;

		/* preload the 4 bytes long TS packet header that is PRELOAD_STEP ahead */
		if (pNextCachePreloadPos+4 <= pDemuxIn->pEnd) {
			DMX_PRELOAD(pNextCachePreloadPos, 4);
		}

		if (IS_OFF_SYNC(pDemuxIn->pCurr)) {
			int offset = 0;
			offset = DEMUX_ResyncTSStream(pDemuxIn->pCurr, pDemuxIn->pEnd - pDemuxIn->pCurr);

			if (offset == -1)
				break;

			pDemuxIn->pCurr += offset;
			continue;
		} else {
			int pid  = PID(pDemuxIn->pCurr);
			target   = pCh->demuxTargetTable[pid] ;
			targetCB = pCh->demuxTargetTableCB[pid] ;

			/* printk("pid %d, target %d targetCB %d\n", pid, target, targetCB) ; */
			if ((target == DEMUX_TARGET_AUDIO || target == DEMUX_TARGET_AUDIO_2ND) && !pCh->activeTarget[target].format){
                		DBG_Warning(DGB_COLOR_RED_WHITE "ch:%d, pin:%d, Audio format is not set.\n", pCh->tunerHandle, target);
				target = DEMUX_TARGET_DROP ;
            }

			if (pid == pCh->PCRPID && HAS_AF(pDemuxIn->pCurr))
			{
				ParsePCR(pCh, pDemuxIn->pCurr);
			}

			if (HAS_FLAG(pCh->chkScrambleTable[pid], PID_CHECK_SCRAMBLE))
				CheckScrambling(pCh, pDemuxIn->pCurr);
		}

		if (targetCB < MAX_PID_FILTER_CB_NUM ) {
			mutex_lock(&pCh->mutex);
			if (pCh->activePESTarget[targetCB].pid >= 0)
				ParsePacketCB(pCh, targetCB, pDemuxIn->pCurr, pDemuxIn->phyAddrOffset);
			mutex_unlock(&pCh->mutex);
		}

		if (target < DEMUX_NUM_OF_TARGETS) {
			ParsePacket(pCh, target, pDemuxIn->pCurr, pDemuxIn->phyAddrOffset, pDemuxOut);
			/*            printk("line %d, payloadSize %d, %d, %d\n", __LINE__, pCh->navBuffers[pDemuxOut->numBuffers].data.payloadSize, pCh->navBuffers[pDemuxOut->numBuffers].data.pinIndex, pCh->demuxTargetInfo[target].pinIndex) ; */
			if (pDemuxOut->numBuffers == NUM_OF_NAV_BUFFERS) {
				pDemuxIn->pCurr += pCh->tsPacketSize;
				pNextCachePreloadPos += pCh->tsPacketSize;
				return 0 ;
			}
		}

		pDemuxIn->pCurr += pCh->tsPacketSize;
		pNextCachePreloadPos += pCh->tsPacketSize;
	}

	/*    FeekbackDemuxStatistics(pDemuxOut); */

	pDemuxIn->pCurr = pDemuxIn->pEnd;

	return (pDemuxOut->numBuffers > 0) ? 0 : -1 ;
}

static void DEMUX_EvaluateToReturnPCRMaster(
	demux_channel* channel
);

void DEMUX_Read(demux_channel *pCh)
{
	unsigned int receivedBytes = 0;
	INT32 iRet = 1;

	DEMUX_UpdateAFMode(pCh);

	while (1) {
		NAVDTVPCRINFO pcrinfo;
		int isProhibited = 0 ;
		PCR_EXIST_STATUS status;
		REFCLOCK * const refClock = DEMUX_GetReferenceClock(pCh);
		NAVDEMUXIN *pDemuxIn  = &pCh->demuxIn ;
		NAVDEMUXOUT *pDemuxOut = &pCh->demuxOut ;

		if (pCh->demuxOutReserved.numBuffers > 0) {
			isProhibited = 1 ;
		} else if (pCh->demuxInReserved.pCurr < pCh->demuxInReserved.pEnd) {
			/* process reserved demux-in data when it exists, and there is no reserved data to deliver */
			pDemuxIn  = &pCh->demuxInReserved;
			pDemuxOut = &pCh->demuxOutReserved;
		}

		/* Periodically check forced mastership flag, and print the notified messages. */
		rtkdemux_dbg_force_mastership_check(
			pCh->tunerHandle,
			refClock,
			&pCh->avSyncMode
		);
		/* have to get pcr info from tp */

		if (!pCh->bIsSDT && pCh->startStreaming && pCh->avSyncMode == NAV_AVSYNC_PCR_MASTER)
		{
			memset(&pcrinfo, 0, sizeof(pcrinfo));

			if (pCh->PCRPID > 0)
			{
				iRet = RHAL_GetPCRTrackingStatus(pCh->tunerHandle, &pcrinfo.pcr, &pcrinfo.stc, &pcrinfo.pcrBase, &pcrinfo.stcBase) ;
				if ( iRet == TPK_SUCCESS)
				{
					if (REFCLK_GetRCD(refClock) != -1)
					{
						bool avsyncstatus = PCRSYNC_GetAVSyncStatus(&pCh->pcrProcesser);
						if(avsyncstatus != true)
						{
							PCRTRACK_Smooth(pCh->pPcrRecoveryManager);
							DEMUX_ResetAVSync(pCh, NAV_AVSYNC_AUDIO_MASTER_AF);
						}
					}
				}
				else
				{
					memset(&pcrinfo, 0, sizeof(pcrinfo));

					DMX_DO_ACTION_ONCE_EVERY(DEMUX_CLOCKS_PER_SEC,
						dmx_err(
							"[%s:%d] can not get pcr/stc from TP%d\n",
							__func__, __LINE__, pCh->tunerHandle
						);
					);
				}
			}

			if (pCh->avSyncMode == NAV_AVSYNC_PCR_MASTER)
			{
				DEMUX_PCRSYNC_T * const processor = &pCh->pcrProcesser;
				processor->videoFreeRunThreshold = pCh->videoFreeRunThreshold;
				status = PCRSYNC_CheckPcrExist(&pCh->pcrProcesser);
				if (status != PCR_EXIST_STATUS_ALREADY_GOT) {
					if(status == PCR_EXIST_STATUS_TIMEOUT)
						PCRSYNC_EnterFreeRunMode(&pCh->pcrProcesser);
				}
				else	{
					if( !(TPK_NOT_ENOUGH_RESOURCE == iRet) )
						PCRSYNC_UpdateRCD(processor, pcrinfo);
				}

				if (PCRSYNC_IsUnderFreeRunMode(processor))
					DEMUX_ResetAVSync(pCh, NAV_AVSYNC_FREE_RUN);
			}
		}
		// under other a/v sync modes
		else if (!pCh->bIsSDT && pCh->startStreaming)
		{
			if (0 < pCh->PCRPID)
			{
				DEMUX_EvaluateToReturnPCRMaster(pCh);
			}
		}
		PCRTRACK_UpdatePosition(pCh->pPcrRecoveryManager, &pCh->pcrProcesser, pCh->avSyncMode);

		if (receivedBytes >= 1024*1024) {
			msleep(NAV_SLEEP_TIME_ON_IDLE);
			return;
		}

		if (pDemuxIn->pCurr >= pDemuxIn->pEnd) {
			NAVBUF buf ;
			isProhibited |= !pCh->startStreaming ;
			/*
			//          printk("StartStreaming: %d,%d, %d\n", pCh->tunerHandle, pCh->startStreaming, isProhibited) ;
			//          msleep(50) ;
			 */
			buf.type = NAVBUF_NONE;
			if (DEMUX_channelStatusCheck(pCh, &buf, isProhibited) == false)
				DEMUX_ReadData(pCh, &buf) ;

			if (buf.type == NAVBUF_DATA || buf.type == NAVBUF_DATA_EXT) {
				pDemuxIn->pts              = buf.data.pts;
				pDemuxIn->dataOffsetForPTS = buf.data.dataOffsetForPTS;
				pDemuxIn->startAddress     = buf.data.startAddress;
				pDemuxIn->phyAddrOffset    = (buf.type == NAVBUF_DATA) ? 0 : buf.data.phyAddrOffset;

				/* fill it up with new raw data */
				if (buf.data.payloadSize > 0) {
					receivedBytes  += buf.data.payloadSize;
					pDemuxIn->pCurr = pDemuxIn->pBegin = buf.data.payloadData;
					pDemuxIn->pEnd  = pDemuxIn->pBegin + buf.data.payloadSize;
					if (rtkdemux_dbg_printio_en || rtkdemux_dbg_monitorio_en)
						rtkdemux_dbg_printio_read_size_calc(pCh, buf.data.payloadSize);
				}

				/* handle private info */
				if (!pCh->bIsSDT && buf.data.infoId != PRIVATEINFO_NONE) {
					if (DEMUX_DeliverPrivateInfo(pCh, &buf) < 0) {
						pDemuxIn->reservedInfoId   = buf.data.infoId;
						pDemuxIn->reservedInfoSize = buf.data.infoSize;
						pDemuxIn->reservedInfoData = buf.data.infoData;
						return ;
					}
					continue ;
				}
			} else {
				DEMUX_DeliverNavBufCommands(pCh, &buf) ;
				return ;
			}
		}
		if (Demux_Parse(pCh, pDemuxIn, pDemuxOut) == 0)
			return ;
		pDemuxOut->numBuffers = 0 ;
	}
}
int DEMUX_ThreadProc(demux_channel *pCh)
{
	while (!kthread_should_stop()) {
		NAVDEMUXIN *pDemuxIn;
		set_freezable();

		while (pCh->demuxIn.reservedInfoId != PRIVATEINFO_NONE
				|| pCh->demuxInReserved.reservedInfoId != PRIVATEINFO_NONE) {
			NAVBUF reservedBuf;
			if (pCh->demuxIn.reservedInfoId != PRIVATEINFO_NONE)
				pDemuxIn = &pCh->demuxIn ;
			else if (pCh->demuxInReserved.reservedInfoId != PRIVATEINFO_NONE)
				pDemuxIn = &pCh->demuxInReserved ;

			reservedBuf.type = NAVBUF_DATA;
			reservedBuf.data.payloadSize = 0;
			reservedBuf.data.payloadData = 0;
			reservedBuf.data.infoId   = pDemuxIn->reservedInfoId;
			reservedBuf.data.infoSize = pDemuxIn->reservedInfoSize;
			reservedBuf.data.infoData = pDemuxIn->reservedInfoData;
			if (!pCh->bIsSDT && DEMUX_DeliverPrivateInfo(pCh, &reservedBuf) < 0) {
				msleep(NAV_SLEEP_TIME_ON_IDLE);
				continue ;
			}
			pDemuxIn->reservedInfoId = PRIVATEINFO_NONE;
			pDemuxIn->reservedInfoSize = 0;
			pDemuxIn->reservedInfoData = 0;
		}

		/* try to re-deliver reserved demux-out */
		if (!pCh->bIsSDT && pCh->demuxOutReserved.numBuffers > 0)
			DEMUX_DeliverData(pCh, &pCh->demuxOutReserved);

		DEMUX_Read(pCh)  ;

		/* deliver data from main demux-out */
		if (!pCh->bIsSDT && pCh->demuxOut.numBuffers > 0 && DEMUX_DeliverData(pCh, &pCh->demuxOut) < 0) { /* reserve data if delivery is not successful */
			pCh->demuxInReserved = pCh->demuxIn ;
			pCh->demuxIn.pBegin  = pCh->demuxIn.pEnd = pCh->demuxIn.pCurr = 0 ;
			pCh->demuxIn.reservedInfoId   = PRIVATEINFO_NONE ;
			pCh->demuxIn.reservedInfoSize = 0;
			pCh->demuxIn.reservedInfoData = 0;

			pCh->demuxOutReserved     = pCh->demuxOut ;
			pCh->demuxOut.numBuffers  = 0 ;
		}


		if (pCh->startStreaming && !pCh->bIsSDT && DEMUX_HasReferenceClock(pCh)) {
			DEMUX_CheckPrintDemuxInfo(pCh);
			if (HAS_FLAG(pCh->status, STATUS_CHECK_PVR_AUDIO_STABLE)) {
				/* audio still cannot catch video in 200ms */
				const REFCLOCK * const refClock = DEMUX_GetReferenceClock(pCh);
				if (CLOCK_GetPTS() - pCh->startCheckAudioStable >= 18000
					&& !HAS_FLAG(pCh->status, STATUS_PVR_AUDIO_IS_STABLE)
					&& refClock->mastership.masterState == AUTOMASTER_NOT_MASTER) {
					PVR_EnableTPRateControl(pCh, false);
					RESET_FLAG(pCh->status, STATUS_CHECK_PVR_AUDIO_STABLE);
					dmx_mask_print(DEMUX_AUDIO_STABLE_DEBUG, "[%s %d] disable TP rate control!", __func__, __LINE__);
				}
				/* if audio becomes master, no need to check */
				if (refClock->mastership.masterState == AUTOMASTER_IS_MASTER) {
					dmx_mask_print(DEMUX_AUDIO_STABLE_DEBUG, "[%s %d] audio becomes master!", __func__, __LINE__);
					RESET_FLAG(pCh->status, STATUS_CHECK_PVR_AUDIO_STABLE);
				}
			}
		}
		if (rtkdemux_dbg_printio_en)
			rtkdemux_dbg_printio_print(pCh);
	}
	return 0 ;
}

static void DEMUX_SetThreadSchedulingRealTimePriority(int priority)
{
	struct sched_param param = { .sched_priority = priority };
	sched_setscheduler(current, SCHED_FIFO, &param);
	current->flags &= ~PF_NOFREEZE;
}

int DEMUX_ThreadProcEntry(void *pParam)
{
	struct cpumask demux_cpumask;
	demux_channel * const pCh = (demux_channel *)pParam;

	DEMUX_SetThreadSchedulingRealTimePriority(1);


    cpumask_clear(&demux_cpumask);
    cpumask_set_cpu(2, &demux_cpumask); // run task in core 3
    sched_setaffinity(0, &demux_cpumask);
	DEMUX_ThreadProc(pCh);
	return 0 ;
}

int DEMUX_ResyncTSStream(const unsigned char *pData, unsigned int bytes)
{
#define NUM_SYNC_WORDS_TO_LOCK  10
#define UNSEARCHED_LAST_BYTES   512

	static const int packetSizeTable[] = { 188, 192, 204 };
	unsigned int byteIdx = 0;
	const unsigned char *pLimit = pData + bytes;
	while (byteIdx + UNSEARCHED_LAST_BYTES < bytes) {
		if (pData[byteIdx] == 0x47) {
			unsigned int sizeIdx;
			for (sizeIdx = 0; sizeIdx < sizeof(packetSizeTable)/sizeof(packetSizeTable[0]); sizeIdx++) {
				const unsigned char *pNextSyncWord = pData + byteIdx;
				int i;
				for (i = 1; i < NUM_SYNC_WORDS_TO_LOCK; i++) {
					pNextSyncWord += packetSizeTable[sizeIdx];
					if (pNextSyncWord >= pLimit)
						break;
					if (pNextSyncWord[0] != 0x47)
						break;
				}
				if (i == NUM_SYNC_WORDS_TO_LOCK) {
					return byteIdx;
				}
			}
		}
		byteIdx++;
	}
	return -1;
}

int DEMUX_CheckFullness(demux_channel *pCh, enum OUTPUT_PIN_ENUM pin, DEMUX_BUF_PIN_T *pPinInfo)
{
#define _IS_AUDIO_PIN_(x) (x == AUDIO_PIN || x == AUDIO2_PIN)
#define _IS_VIDEO_PIN_(x) (x == VIDEO_PIN || x == VIDEO2_PIN)

	if (pCh->bPendingOnFullness) {
		PVR_DetectAudioOnlyFile(pCh);
		if ((pCh->avSyncMode == NAV_AVSYNC_AUDIO_ONLY && _IS_AUDIO_PIN_(pin)) ||
			(pCh->avSyncMode != NAV_AVSYNC_PCR_MASTER && pCh->avSyncMode != NAV_AVSYNC_AUDIO_ONLY && (_IS_VIDEO_PIN_(pin) || _IS_AUDIO_PIN_(pin)))) {
			bool bEnough;
			long fullness;
			unsigned long phyWr = DEMUX_reverseInteger(*pPinInfo->pWrPtr) ;
			unsigned long phyRd = DEMUX_reverseInteger(*pPinInfo->pRdPtr) ;

			fullness = (long)(phyWr - phyRd);
			if(fullness < 0)
				fullness += (long)(pPinInfo->pBufferUpper - pPinInfo->pBufferLower);

			bEnough = (fullness >= pCh->avSyncStartupFullness) && ((pCh->avSyncMode == NAV_AVSYNC_AUDIO_ONLY && _IS_AUDIO_PIN_(pin)) || (pCh->avSyncMode != NAV_AVSYNC_AUDIO_ONLY && _IS_VIDEO_PIN_(pin)));
			if (pCh->avSyncStartupFullness > 0 && bEnough) {
				PVR_PvrStartToPlay(pCh);
				dmx_crit("[%s %d] BufferingEnd\n", __func__, __LINE__);
			}

		}
		if (pCh->bPendingOnFullness) {
			if (REFCLK_GetRCD(DEMUX_GetReferenceClock(pCh)) != -1) {
				PVR_PvrStartToPlay(pCh);
				dmx_crit("[%s %d] Buffering Timeout\n", __func__, __LINE__);
			}
		}
	}
	if (REFCLK_GetRCD(DEMUX_GetReferenceClock(pCh)) != -1
	&& !HAS_FLAG(pCh->status, STATUS_TP_RATE_CONTROL_ENABLED)
	&& !HAS_FLAG(pCh->status, STATUS_APVR_PLAYBACK_START)) {
		REFCLOCK * const refClock = DEMUX_GetReferenceClock(pCh);
		int64_t audioSystemPTS = DEMUX_reverseLongInteger(refClock->audioSystemPTS);
		if (refClock->mastership.masterState == AUTOMASTER_IS_MASTER && pCh->pcrProcesser.lastDemuxAudioPTS - audioSystemPTS >= 4500) {
			dmx_mask_print(DEMUX_AUDIO_STABLE_DEBUG,"[%s %d] enable rate control again!\n", __func__, __LINE__);
			PVR_EnableTPRateControl(pCh, true);
		}
	}
	return 1;
}

void DEMUX_UpdateAFMode(demux_channel *pCh)
{
	if(pCh->avSyncMode == NAV_AVSYNC_AUDIO_MASTER_AF && pCh->bCheckAFState == true) {
		REFCLOCK * const pRefClock = DEMUX_GetReferenceClock(pCh);
		DEMUX_PCRSYNC_T *pPcrProcesser = &pCh->pcrProcesser;

		if(REFCLK_GetRCD(pRefClock) != -1) {
			pCh->bCheckAFState = false;
			pRefClock->mastership.videoMode    = (unsigned char)AVSYNC_AUTO_SLAVE;
			pRefClock->mastership.audioMode    = (unsigned char)AVSYNC_AUTO_MASTER_NO_SKIP;
			pRefClock->mastership.masterState  = (unsigned char)AUTOMASTER_IS_MASTER;
			dmx_crit("[%s %d] audio is master\n", __func__, __LINE__);
		} else if (CLOCK_GetPTS() >= pCh->timeToUpdteAF) {
			pCh->bCheckAFState = false;
			pRefClock->mastership.videoMode    = (unsigned char)AVSYNC_AUTO_SLAVE;
			pRefClock->mastership.audioMode    = (unsigned char)AVSYNC_AUTO_MASTER_NO_SKIP;
			if (pPcrProcesser->startAudioPts != -1 && pPcrProcesser->startAudioPts <= pPcrProcesser->startVideoPts)
				pRefClock->mastership.masterState = (unsigned char)AUTOMASTER_IS_MASTER;
			else
				pRefClock->mastership.masterState = (unsigned char)AUTOMASTER_NOT_MASTER;
			dmx_crit("[%s %d] masterState = %d\n", __func__, __LINE__, pRefClock->mastership.masterState );
		}
		pCh->preMasterState = pRefClock->mastership.masterState;
	}
}
void DEMUX_ResetAVSync(demux_channel *pCh, AV_SYNC_MODE avSyncMode)
{
	// NOTICE: caller should lock pCh->mutex first.
	REFCLOCK * const refClock = DEMUX_GetReferenceClock(pCh);
	if (avSyncMode == NAV_AVSYNC_AUDIO_MASTER_AF) {

		if (pCh->tp_src == MTP) {
			pCh->avSyncStartupFullness = 0;
			pCh->bPendingOnFullness = false;
			pCh->avSyncStartupPTS = 500*DEMUX_CLOCKS_PER_MS;
			pCh->bPendingOnPTSCheck = true;

			REFCLK_SetFreeRunThreshold(refClock, FREE_RUN_THRESHOLD_FOR_MTP, FREE_RUN_THRESHOLD_FOR_MTP, AUDIO_FREE_RUN_THRESHOLD_TO_WAIT);
		} else {
			pCh->avSyncStartupFullness = 512 * 1024;
			pCh->bPendingOnFullness = true;
			pCh->avSyncStartupPTS = 0;
			pCh->bPendingOnPTSCheck = false;
		}
		pCh->avSyncMode = NAV_AVSYNC_AUDIO_MASTER_AF;
		pCh->bCheckAFState = true;
		pCh->timeToUpdteAF = CLOCK_GetPTS() + 1500*DEMUX_CLOCKS_PER_MS;

		REFCLK_SetMasterShip(refClock, pCh->avSyncMode);
		REFCLK_SetTimeout(refClock, 3*DEMUX_CLOCKS_PER_SEC);

	} else if (avSyncMode == NAV_AVSYNC_AUDIO_MASTER_AUTO) {

		pCh->avSyncStartupFullness = 0;
		pCh->bPendingOnFullness = false;
		pCh->avSyncStartupPTS = 500*DEMUX_CLOCKS_PER_MS;
		pCh->bPendingOnPTSCheck = true;
		pCh->avSyncMode = NAV_AVSYNC_AUDIO_MASTER_AUTO;

		REFCLK_SetMasterShip(refClock, pCh->avSyncMode);
		REFCLK_SetFreeRunThreshold(refClock, FREE_RUN_THRESHOLD_FOR_MTP, FREE_RUN_THRESHOLD_FOR_MTP, AUDIO_FREE_RUN_THRESHOLD_TO_WAIT);
		if(REFCLK_GetRCD(refClock) == -1)
			REFCLK_SetTimeout(refClock, 3*DEMUX_CLOCKS_PER_SEC);

	} else if (avSyncMode == NAV_AVSYNC_PCR_MASTER) {

		pCh->avSyncStartupFullness = 0;
		pCh->bPendingOnFullness = false;
		pCh->avSyncStartupPTS = 0;
		pCh->bPendingOnPTSCheck = false;
		pCh->avSyncMode = NAV_AVSYNC_PCR_MASTER;

		REFCLK_SetMasterShip(refClock, pCh->avSyncMode);
		REFCLK_SetTimeout(refClock, 3*DEMUX_CLOCKS_PER_SEC);

	} else if (avSyncMode == NAV_AVSYNC_AUDIO_ONLY) {

		pCh->avSyncStartupFullness = 0;
		pCh->bPendingOnFullness = false;
		pCh->avSyncStartupPTS = 0;
		pCh->bPendingOnPTSCheck = false;
		pCh->avSyncMode = NAV_AVSYNC_AUDIO_ONLY;

		REFCLK_SetTimeout(refClock, 0);
		REFCLK_SetMasterShip(refClock, pCh->avSyncMode);
		REFCLK_SetFreeRunThreshold(refClock, FREE_RUN_THRESHOLD_FOR_MTP, FREE_RUN_THRESHOLD_FOR_MTP, AUDIO_FREE_RUN_THRESHOLD_TO_WAIT);

	} else if (avSyncMode == NAV_AVSYNC_VIDEO_ONLY) {

		pCh->avSyncStartupFullness = 0;
		pCh->bPendingOnFullness = false;
		pCh->avSyncStartupPTS = 0;
		pCh->bPendingOnPTSCheck = false;
		pCh->avSyncMode = NAV_AVSYNC_VIDEO_ONLY;

		REFCLK_SetTimeout(refClock, 0);
		REFCLK_SetMasterShip(refClock, pCh->avSyncMode);
	}
    else if (avSyncMode == NAV_AVSYNC_FREE_RUN) {
    pCh->avSyncStartupFullness = 0;
        pCh->bPendingOnFullness = false;
        pCh->avSyncStartupPTS = 0;
        pCh->bPendingOnPTSCheck = false;
        pCh->avSyncMode = NAV_AVSYNC_FREE_RUN;

        REFCLK_SetTimeout(refClock, 0);
        REFCLK_SetMasterShip(refClock, pCh->avSyncMode);
    }
	pCh->preMasterState = refClock->mastership.masterState;
	pCh->preAudioSystemPTS = DEMUX_reverseLongInteger(refClock->audioSystemPTS);
	pCh->preVideoSystemPTS = DEMUX_reverseLongInteger(refClock->videoSystemPTS);
	pCh->preRCD = DEMUX_reverseLongInteger(refClock->RCD);

	dmx_crit("[%s %d] (CH%d) change avsync mode = %d\n", __func__, __LINE__, pCh->tunerHandle, pCh->avSyncMode);
}

REFCLOCK* DEMUX_GetReferenceClock(demux_channel *channel)
{
	return (REFCLOCK *)channel->refClockBuffer.virAddr;
}

bool DEMUX_HasReferenceClock(demux_channel *channel)
{
	return DEMUX_GetReferenceClock(channel) != NULL;
}

static void DEMUX_EvaluateToReturnPCRMaster(
	demux_channel* channel
)
{
	int64_t newPcr, newStc, ignore;

    DEMUX_PCRSYNC_T *  processor = NULL;
    if (channel == NULL)
        return;
    processor = &channel->pcrProcesser;

	if (!PCRSYNC_IsUnderFreeRunMode(processor))
		return;

    if (RHAL_GetPCRTrackingStatus(channel->tunerHandle, &newPcr, &newStc, &ignore, &ignore ) != TPK_SUCCESS)
        return;

    //const REFCLOCK * const refClock =    (REFCLOCK *)channel->refClockBuffer.virAddr;
    if (REFCLK_GetRCD(DEMUX_GetReferenceClock(channel)) == -1)
        return;

    //const bool shouldUpdateProcessorRcd = PCRSYNC_EvaluateRcdStability(processor, newPcr, newStc);

    if (PCRSYNC_EvaluateRcdStability(processor, newPcr, newStc))
    {
        PCRSYNC_UpdateProcessorRcd(processor, newPcr, newStc);
    }

	DMX_DO_ACTION_ONCE_EVERY(DEMUX_CLOCKS_PER_SEC,
		dmx_notice("[%s:%d] RCD stability: stable check = %lld, unstable count = %lld\n",
			__func__, __LINE__, processor->rcdStableCheckCount,	processor->rcdUnstableCount);
	);

	if (PCRSYNC_ShouldReturnToPCRMaster(processor))
	{
		PCRSYNC_ReturnToPCRMaster(processor);
		DEMUX_ResetAVSync(channel, NAV_AVSYNC_PCR_MASTER);
		return;
	}

	if (PCRSYNC_ShouldResetRcdStabilityCheckStatus(processor))
	{
		PCRSYNC_ResetRcdStabilityCheckStatus(processor);
	}
}

int DEMUX_CheckPTSChange(demux_channel *pCh)
{
	if(pCh == NULL)
		return 0;

	if(pCh->pcrProcesser.lastDemuxAudioPTS == -1 || pCh->pcrProcesser.prevAudioDemuxPTS == -1 || (pCh->pcrProcesser.lastDemuxAudioPTS == pCh->pcrProcesser.prevAudioDemuxPTS))
		pCh->pcrProcesser.noAudioPtsCounter++;
	else
		pCh->pcrProcesser.audioPtsCounter++;

	if(pCh->pcrProcesser.lastDemuxVideoPTS == -1 || pCh->pcrProcesser.prevVideoDemuxPTS == -1 || (pCh->pcrProcesser.lastDemuxVideoPTS == pCh->pcrProcesser.prevVideoDemuxPTS))
		pCh->pcrProcesser.noVideoPtsCounter++;
	else
		pCh->pcrProcesser.videoPtsCounter++;

	return 1;
}

void DEMUX_CheckPrintDemuxInfo(demux_channel *pCh)
{
	static int64_t 	last__	 = 0;
	const int64_t current__ = CLOCK_GetPTS();
	const int64_t passed__  = abs64(current__ - last__);
	const REFCLOCK * const refClock = DEMUX_GetReferenceClock(pCh);
	const int64_t curRCD = DEMUX_reverseLongInteger(refClock->RCD);
	const int64_t curVideoSystemPTS = DEMUX_reverseLongInteger(refClock ->videoSystemPTS);
	const int64_t curAudioSystemPTS = DEMUX_reverseLongInteger(refClock ->audioSystemPTS);
	const unsigned char curMasterState = refClock->mastership.masterState;

	if(TIMEOUT_CHECK_DEMUX_INFO * DEMUX_CLOCKS_PER_SEC <= passed__ ) {
		if((pCh->preAudioSystemPTS == curAudioSystemPTS) && (pCh->pcrProcesser.lastDemuxAudioPTS > 0))
			dmx_notice("(CH%d)RTKDEMUX: audio system PTS(%lld) no change during %d sec\n", pCh->tunerHandle, curAudioSystemPTS, TIMEOUT_CHECK_DEMUX_INFO);
		if((pCh->preVideoSystemPTS == curVideoSystemPTS) && (pCh->pcrProcesser.lastDemuxVideoPTS > 0))
			dmx_notice("(CH%d)RTKDEMUX: video system PTS(%lld) no change during %d sec\n", pCh->tunerHandle, curVideoSystemPTS, TIMEOUT_CHECK_DEMUX_INFO);
		if(curRCD == -1 && curRCD == pCh->preRCD)
			dmx_notice("(CH%d)RTKDEMUX: RCD(%lld) no delivered during %d sec\n", pCh->tunerHandle, curRCD, TIMEOUT_CHECK_DEMUX_INFO);

		pCh->preAudioSystemPTS = curAudioSystemPTS;
		pCh->preVideoSystemPTS = curVideoSystemPTS;
		pCh->preRCD = curRCD;
		last__ = current__;
	}

	if (pCh->preMasterState != curMasterState) {
		dmx_notice("(CH%d)RTKDEMUX: mastership mode %d, s %d, v %d, a %d, st %d, PcrCnt %d\n"
			, pCh->tunerHandle
			, pCh->avSyncMode
			, refClock->mastership.systemMode
			, refClock->mastership.videoMode
			, refClock->mastership.audioMode
			, refClock->mastership.masterState
			, pCh->pcrProcesser.pcrExistDetect.detectPcrCnt) ;
		pCh->preMasterState = curMasterState;
	}
}
