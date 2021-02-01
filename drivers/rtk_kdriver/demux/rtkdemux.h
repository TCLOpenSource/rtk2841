/******************************************************************************
 *
 *   Realtek Demux driver
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author lciou@realtek.com
 *
 *****************************************************************************/


#ifndef _DEMUX_DRIVER_H_
#define _DEMUX_DRIVER_H_


#include <generated/autoconf.h>
#include <linux/cdev.h>
#include <linux/semaphore.h>
#include "rtkdemux_common.h"
#include "rtkdemux_export.h"
#include "rtkdemux_pcrsync.h"
#include "rtkdemux_pcrtracking.h"
#include "rtkdemux_refclk.h"
#include <tp/tp_drv_api.h>

/*#define DEMUX_BRINGUP_DEBUG*/

//#define DEMUX_AUDIO_USE_GLOBAL_BUFFER

#define RTKDEMUX_MAJOR  0

/* #define  DEMUX_DEBUG */
#ifdef DEMUX_DEBUG
#define DBG_PRINT(s, args...) dmx_info(s, ## args)
#else
#define DBG_PRINT(s, args...)
#endif

#define DBG_Warning(format, ...)      \
{\
	static unsigned int  LastPrintPTS=0;			\
	static unsigned int  WarningCount=0;			\
	unsigned int	     CurrentPTS = CLOCK_GetPTS();	\
	if (CurrentPTS - LastPrintPTS > 90090)	{\
		dmx_warn("WARNING[%d]:", WarningCount+1);	\
		dmx_warn(format, ##__VA_ARGS__);	\
		LastPrintPTS = CurrentPTS;	\
		WarningCount = 0;		\
	} else	\
	WarningCount++;	\
}

#define DBG_WarningSec(_sec, format, ...)      \
{\
	static unsigned int  LastPrintPTS=0;			\
	static unsigned int  WarningCount=0;			\
	unsigned int	     CurrentPTS = CLOCK_GetPTS();	\
	if (CurrentPTS - LastPrintPTS > 90090 * _sec) {	\
		dmx_warn("WARNING[%d]:", WarningCount+1);	\
		dmx_warn(format, ##__VA_ARGS__);	\
		LastPrintPTS = CurrentPTS;	\
		WarningCount = 0;		\
	} else	\
	WarningCount++;	\
}


#define DEFAULT_FILE_HANDLE (0xAB)
#define MAX_VDEC_NUM 2
#define MAX_ADEC_NUM 2


#define DEMUX_TP_NUM                         3
#define DEMUX_VD_NUM                         2
#define DEMUX_AD_NUM                         2
#define DEMUX_REFCLK_BUFF_SIZE          (sizeof(REFCLOCK))

#define DEMUX_TP_BUFF_SIZE         (16*1024*1024)
#define DEMUX_VD_BS_SIZE             (8*1024*1024)
#define DEMUX_VD_IB_SIZE             (256*1024)
#define DEMUX_AD_BS_SIZE             (256*1024)
#define DEMUX_AD_IB_SIZE             (256*1024)
#define MTP_AVSYNC_MODE             NAV_AVSYNC_AUDIO_MASTER_AUTO //NAV_AVSYNC_AUDIO_MASTER_AF

#define DONTFIXBUG13648
//============================================

#define DEMUX_PESDATA_PREFIX_PESLENGTH 2
#define DEMUX_PESDATA_PREFIX_LENGTH (DEMUX_PESDATA_PREFIX_PESLENGTH)


//============================================

typedef enum {
	DEMUX_STATE_STOP = 0,
	DEMUX_STATE_PAUSE,
	DEMUX_STATE_RUNNING,

} DEMUX_STATE_T;

typedef struct {
	dma_addr_t     phyAddr ;
	unsigned char *virAddr ;
	unsigned char *cachedaddr ;     /* cached addresss for release*/
	unsigned char *nonCachedaddr ;
	unsigned int   size ;
	unsigned int   allocSize ;
	unsigned char  isCache ;
	unsigned char  fromPoll ;
} DEMUX_BUF_T ;

typedef struct {
	RINGBUFFER_HEADER *pRBH ;
	unsigned long *pWrPtr ;
	unsigned long *pRdPtr ;
	unsigned long *pRdPtrDump ;   /* for DUMP */
	unsigned char *pBufferLower ; /*  lower bound of buffer (physical)*/
	unsigned char *pBufferUpper ; /*  upper bound of buffer (physical)*/
	long           phyAddrOffset; /*  physical address - non cached address (or cached address for bitstream ringbuffer)*/
} DEMUX_BUF_PIN_T ;

typedef enum {
	DEMUX_STREAM_TYPE_BS = 0,
	DEMUX_STREAM_TYPE_IB,
	DEMUX_STREAM_TYPE_NUM,

} DEMUX_STREAM_TYPE_T;

typedef enum{
	BUF_STAT_DONE = 0,
	BUF_STAT_NEW,
	BUF_STAT_FREE,
	BUF_STAT_ONLINE,
	BUF_STAT_OFFLINE,
	BUF_STAT_REUSED,
	BUF_STAT_REUSED_II,
}DEMUX_BUF_STAT_T;

#ifdef DEMUX_AUDIO_USE_GLOBAL_BUFFER
typedef struct{
	DEMUX_BUF_T 		bsBuffer;
	DEMUX_BUF_T 		bsBufferH;
	DEMUX_BUF_T 		ibBuffer;
	DEMUX_BUF_T 		ibBufferH;

	DEMUX_BUF_STAT_T 	status;
	enum OUTPUT_PIN_ENUM		ownerPin;
	unsigned char 		ownerChannel;
	unsigned char 		bufferIndex;
}DEMUX_PIN_BUFFER_T;
#endif

typedef struct {
	DEMUX_BUF_PIN_T bufInfo[DEMUX_STREAM_TYPE_NUM] ;
#ifdef DEMUX_AUDIO_USE_GLOBAL_BUFFER
	DEMUX_PIN_BUFFER_T *pBuffer;
	DEMUX_PIN_BUFFER_T *pBuffer_reserved;
#endif
} DEMUX_OUT_T ;

typedef struct {
	int  pid;
	bool bNewTarget;
	int  IsScramble;        /* -1 means scramble control info is not ready.
				 * 0 means packets are not scramble
				 * 1 means packets are scramble */
	int  format ;           /* audio need to set format before demux*/
} DEMUX_TARGET_T ;
typedef struct {
	int  pid;
	bool bNewTarget;
	int  IsScramble;        /* -1 means scramble control info is not ready.
				 * 0 means packets are not scramble
				 * 1 means packets are scramble */
	bool bCheckContiCounter ;
	int  contiCounter ;

} DEMUX_PES_TARGET_T ;

typedef struct {
	short             pid ;
	unsigned char     enDescramble ;
	int               cwIndex ;
	DEMUX_PID_TYPE_T  pidType ;
	DEMUX_PES_DEST_T  pesDest ;
	int               refCnt ;
} DEMUX_PID_LIST_T ;

typedef struct {
	bool  bCheck ;
	short pid ;
	DEMUX_PID_TYPE_T  pidType ;
	long long timeStamp;

} DEMUX_SCRAMBLE_CHECK_LIST_T ;

typedef struct {
	unsigned char     used ;
	short pid ;
	DEMUX_PID_TYPE_T  pidType ;
	int cwIndex ;

} DEMUX_PES_PID_LIST_T ;

typedef struct {
	unsigned char  occupied ;
	unsigned char *virAddr ;
	unsigned int   phyAddr ;
	unsigned char *curWr ;    /* current write pointer */
	unsigned int   unitSize ; /* PES_packet_length */
	unsigned int   size ;     /* accumulated size */
	DEMUX_BUF_T    rbHeader ; /* ringbuffer header */
	unsigned long *pWrPtr ;   /* pointer to ringbuffer wrPtr */
	unsigned long *pRdPtr ;   /* pointer to ringbuffer rdPtr */
	unsigned char *pBufferLower ; /*  lower bound of buffer (physical)*/
	unsigned char *pBufferUpper ; /*  upper bound of buffer (physical)*/
	long           phyAddrOffset; /*  physical address - non cached address (or cached address for bitstream ringbuffer)*/

#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
	DEMUX_BUF_T  pesFilterBuffer;
	enum {
		BUFFER_OFFLINE,
		BUFFER_ONLINE,
		BUFFER_NEW,
		BUFFER_FREE
	}  bufferStatus;
#endif//DEMUX_PES_BUFFER_DYNAMIC_ALLOC

} DEMUX_PES_MAP_T ;

typedef struct {
	unsigned char  used ;
	unsigned char  checksum ;
	unsigned short firstBufIndex ; /* pointer to first index of section buffer from DEMUX_SEC_MAP_T allocated for this section */
	unsigned short lastBufIndex ;  /* pointer to last index of section buffer from DEMUX_SEC_MAP_T allocated for this section */
	unsigned short count ; /* how many units(32K) are used */
	void          *handle ;

	DEMUX_BUF_T    rbHeader ; /* ringbuffer header */
	unsigned long *pWrPtr ;   /* pointer to ringbuffer wrPtr */
	unsigned long *pRdPtr ;   /* pointer to ringbuffer rdPtr */
	unsigned char *pBufferLower ; /*  lower bound of buffer (physical)*/
	unsigned char *pBufferUpper ; /*  upper bound of buffer (physical)*/
	long           phyAddrOffset; /*  physical address - non cached address (or cached address for bitstream ringbuffer)*/

	TPK_SEC_FILTER_PARAM_T param ;

	/* for debug */
	unsigned char ch ;

} DEMUX_SEC_LIST_T ;

typedef struct {
	unsigned char  occupied ;
	short bufIndex ;
	short nextBufIndex ;
	unsigned char *virAddr ;
	void          *pContext ;      /* ((tp_id << 8) | secfIndex) to release buffer*/

} DEMUX_SEC_MAP_T ;

typedef struct {
	unsigned char   used ;          /* gotten by API*/
	/*  unsigned char enable ;        // enable descrambler for this PID*/
	unsigned short  pid ;
	DEMUX_CHANNEL_T ch ;
	TPK_DESCRAMBLE_ALGORITHM_T desc;

	unsigned char IV_odd[TPK_MAX_IV_LENGTH] ;
	unsigned char IV_even[TPK_MAX_IV_LENGTH] ;

} DEMUX_CW_INDEX_INFO_T ;


typedef struct {
	struct file *filp[DEMUX_NUM_OF_TARGETS][2] ; /* [pinIndex][isIB]*/
	void (*OnFlush)(void *pCh) ;
	void (*Write)(void *pCh, NAVBUF *pBuf) ;
	void (*WritePrivateInfo)(void *pCh, NAVBUF *pBuf) ;

} DEMUX_DUMP_ES ;

typedef struct {
	unsigned char AD_fade_byte;
	unsigned char AD_pan_byte;
	char AD_gain_byte_center;
	char AD_gain_byte_front;
	char AD_gain_byte_surround;
} AUDIO_AD_INFO;

typedef struct {
	enum {
		PININFO_DONE,
		PININFO_NEW,
		PININFO_FREE
	} pinInfoStatus;
	int bufIndex;
} DEMUX_TEMP_PIN_INFO;

typedef struct {
	int chIndex;
} DEMUX_PIN_MAP_T;

typedef struct {
	unsigned char       isInit ;
	unsigned char       startStreaming ;
	unsigned char       bStartRec ;
	
	unsigned char       bIsSDT;
	unsigned char       bPcrTrackEnable ;
	int                 CIKeySel ;         /* automatic to get/release an index while CI Channel enabled/disabled*/
	struct task_struct *thread_task ;

	/* Don't use pCh->mutex in the scope of demux_device->mutex. Mutex order deadlock may happen. */
	struct mutex        mutex ;

	DEMUX_STATE_T       state ;
#ifndef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
	DEMUX_BUF_T         pesFilterBuffer ;
#endif
	DEMUX_BUF_T         refClockBuffer ;
	DEMUX_BUF_T         tpBuffer ;
	DEMUX_BUF_T         tpBufferH ;
	DEMUX_BUF_T         mtpBuffer;
	DEMUX_BUF_T         tpInfoBufferH;
	DEMUX_BUF_T         tpInfoBuffer;

#ifndef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
	DEMUX_BUF_STAT_T 	vBufStatus[MAX_VDEC_NUM];
	DEMUX_BUF_T         bsVideoBuf[MAX_VDEC_NUM] ;  /* BS ringbuffer of video*/
	DEMUX_BUF_T         bsVideoBufH[MAX_VDEC_NUM] ; /* BS RINGBUFFER_HEADER of video*/
	DEMUX_BUF_T         ibVideoBuf[MAX_VDEC_NUM] ;  /* IB ringbuffer of video*/
	DEMUX_BUF_T         ibVideoBufH[MAX_VDEC_NUM] ; /* IB RINGBUFFER_HEADER of video*/
#endif
#ifndef DEMUX_AUDIO_USE_GLOBAL_BUFFER
	DEMUX_BUF_T         bsAudioBuf[MAX_ADEC_NUM] ;  /* BS ringbuffer of audio*/
	DEMUX_BUF_T         bsAudioBufH[MAX_ADEC_NUM] ; /* BS RINGBUFFER_HEADER of audio*/
	DEMUX_BUF_T         ibAudioBuf[MAX_ADEC_NUM] ;  /* IB ringbuffer of audio*/
	DEMUX_BUF_T         ibAudioBufH[MAX_ADEC_NUM] ; /* IB RINGBUFFER_HEADER of audio*/
#endif
#if defined(DEMUX_VIDEO_USE_PINGPONG_BUFFERS)
	DEMUX_TEMP_PIN_INFO  tmpPinInfo[NUMBER_OF_PINS] ;
#endif
	DEMUX_OUT_T         pinInfo[NUMBER_OF_PINS] ;

	uint64_t            latestDDRCopyHandle ;
	unsigned char       bFlushBeforeDelivery ;
	unsigned char       bUseDDRCopy ;
	unsigned char       tunerHandle ;
	unsigned char      *pTPRelase ;
	unsigned int        TPReleaseSize ;
	unsigned long       dataThreshold;
	unsigned long       videoFreeRunThreshold;
	long                phyAddrOffset ;


	AV_SYNC_MODE        avSyncMode;

	bool                bCheckAFState;
	int64_t             timeToUpdteAF;
	AUDIO_DEC_TYPE      audioType;
	int                 pvrSpeed;

	DECODE_MODE         videoDecodeMode[MAX_VDEC_NUM] ;

	DEMUX_AUDIO_DEC_T   audioFormat ;
	long                audioPrivateInfo[8];
	DEMUX_AUDIO_DEC_T   audioFormat2 ;
	long                audioPrivateInfo2[8];
	unsigned int        status ;
	unsigned int        events ;
	bool                bUpdateDemuxTarget ;
	NAVDEMUXIN          demuxIn ;
	NAVDEMUXOUT         demuxOut ;
	NAVDEMUXIN          demuxInReserved ;
	NAVDEMUXOUT         demuxOutReserved ;

	unsigned int        tsPacketSize;

	int PCRPID ;
	/* nav buffer for demux-out*/
	NAVBUF navBuffers[NUM_OF_NAV_BUFFERS];

	/* demux target table (one unsigned char for each possible value of the 13 bits PID)*/
	unsigned char demuxTargetTable[1 << 13];

	unsigned char demuxTargetTableCB[1 << 13];
	/* demux target info*/
	struct {
		int pinIndex;
		int events;
		int contiCounter;
		bool bKeepPES;
		bool bCheckContiCounter;
		bool bResyncStartUnit;
		bool bSyncPTSEnable;
		bool bResyncPTS;    /*for bug 13648*/
		int64_t pts;
		unsigned char pesHeaderBuf[PES_HEADER_BUF_SIZE];
		unsigned int bufferedBytes;
		unsigned int remainingHeaderBytes;
		unsigned int demuxedCount;

	} demuxTargetInfo[DEMUX_NUM_OF_TARGETS];

	DEMUX_TARGET_T activeTarget[DEMUX_NUM_OF_TARGETS];

	/* PID filter list (Active)*/
	TPK_PID_FILTER_PARAM_T pidActiveList[MAX_PID_FILTER_NUMBER];
	unsigned int           pidActiveCount ;

	/* PID filter list*/
	DEMUX_PID_LIST_T pidFilterList[MAX_PID_FILTER_NUMBER];
	unsigned int     pidFilterCount ;

	/* PID list for scramble checking*/
	DEMUX_SCRAMBLE_CHECK_LIST_T scrambleList[MAX_PID_FILTER_NUMBER] ;
	unsigned int     checkScrambleCount ;
	unsigned char    chkScrambleTable[1 << 13]; /* bit 0: bCheckIsScrambed, bit 1: bIsScrambled*/

	/* the buffer map for PES filter*/
	DEMUX_PES_MAP_T    pesMap[MAX_PID_FILTER_CB_NUM] ;

	DEMUX_PES_PID_LIST_T  pidFilterListCB[MAX_PID_FILTER_CB_NUM] ;
	DEMUX_PES_TARGET_T    activePESTarget[MAX_PID_FILTER_CB_NUM] ;

	int lumpsumLoopCount ;
	int lumpsumErrCount ;
	const char *lumpsumMsg[256] ;

	/* to adjust sleep time while buffer is empty*/
	unsigned int bitRate ;
	unsigned int bytes ;       /* read bytes*/
	int64_t lastStampedPTS ;

	DEMUX_PCRSYNC_T pcrProcesser;

	/* Section Filter*/
	struct mutex section_mutex;
	DEMUX_SEC_LIST_T secListCB[MAX_SECTION_FILTER_NUM] ;	/* allocate section index */

	/* buffering */
	long avSyncStartupFullness;
	long avSyncStartupPTS;
	bool bPendingOnFullness;
	bool bPendingOnPTSCheck;
	PCRTRK_MANAGER_T *pPcrRecoveryManager;

	AUDIO_AD_INFO adInfo;
	//int audioFullnessLowCount;
	//int audioFullnessLowCheckNum;
	int64_t PCRSyncStatusCheckTick;
	int64_t PCRSyncStatusCheckBaseTick;

	/* Special Handling */
	int64_t ringFullCheckTimer[NUMBER_OF_PINS];
	bool bDropflag[NUMBER_OF_PINS];

	/* Check AD channel target*/
	int AdChannelTarget;

	/*  tp source*/
	TPK_TP_SOURCE_T tp_src;

	/* For check demux info when timeout */
	int64_t preVideoSystemPTS;
	int64_t preAudioSystemPTS;
	int64_t preRCD;
	unsigned char   preMasterState;

	int64_t startCheckAudioStable;
} demux_channel ;

typedef struct {
	struct semaphore sem ;          /* mutual exclusion semaphore     */
	struct cdev      cdev ;         /* Char device structure          */

	/* Don't use pCh->mutex in the scope of demux_device->mutex. Mutex order deadlock may happen. */
	struct mutex     mutex ;      /* make secFilterBuffer, secMap, secBufCnt and cwInfo thread-safe*/

	struct file     *fpInit ;       /* which fp to init sdec module can un-init sdec while init-process is killed*/
	unsigned char	 isInit;		/* Is init members in DEMUX_InitModule */
	unsigned char    filter_flag ;  /* set to 1 if received section/pes packet*/
	unsigned char    disableCache ; /* for DEBUG*/
	unsigned char    chNum ;        /* total channels*/
	unsigned char    useSDT ;
	unsigned char    numberOfVD ;
	unsigned char    numberOfAD ;
	unsigned int     sizeOfVideoBS ;
	unsigned int     sizeOfAudioBS ;
	unsigned int     sizeOfVideoIB ;
	unsigned int     sizeOfAudioIB ;
	demux_channel   *pChArray ;     /* pointer to channel structure*/
	PCRTRK_MANAGER_T pcrTrkManager[DEMUX_PCRTRACKING_MANAGER_NUM];
	DEMUX_BUF_T      secFilterBuffer ;                   /* used by each channel*/
	DEMUX_SEC_MAP_T  secMap[SEC_FILTER_BUFFER_UNIT_CNT] ;     /* the buffer map used by which section filter */
	unsigned char    secBufCnt ;

	DEMUX_BUF_T      bufPoll ;                   /* buffer only be released in exit module and init module, init module will release orignal buffer before re-allocating new buffer*/
	unsigned int     usedPollSize ;
	unsigned int    totalDroppingPin;

	TPK_HARDWARE_INFO_T   tpInfo ;
	DEMUX_CW_INDEX_INFO_T cwInfo[MAX_DESCRAMBLER_INDEX_NUM] ;

#ifdef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
	unsigned char       bVideoBufUsed[MAX_VDEC_NUM];
	DEMUX_BUF_T         bsVideoBuf[MAX_VDEC_NUM] ;  /* BS ringbuffer of video*/
	DEMUX_BUF_T         bsVideoBufH[MAX_VDEC_NUM] ; /* BS RINGBUFFER_HEADER of video*/
	DEMUX_BUF_T         ibVideoBuf[MAX_VDEC_NUM] ;  /* IB ringbuffer of video*/
	DEMUX_BUF_T         ibVideoBufH[MAX_VDEC_NUM] ; /* IB RINGBUFFER_HEADER of video*/
#endif
#if defined(DEMUX_AUDIO_USE_GLOBAL_BUFFER)
	DEMUX_PIN_BUFFER_T	audioBuffer[MAX_ADEC_NUM];
#endif
	DEMUX_PIN_MAP_T pinMap[NUMBER_OF_PINS];
} demux_dev ;

typedef struct {
	unsigned int uSysPllDispaSD1;
	unsigned int uSysPllDispbSD1;
	unsigned int uSysPllDispaSD2;
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	unsigned int uSysPllDispbSD2;
#endif
	unsigned int uScpuClkLoReg;
	unsigned int uScpuClkHiReg;

} demux_snapshot;


extern demux_dev *demux_device ;

long DEMUX_ioctl          (struct file *filp, unsigned int cmd, unsigned long arg) ;
int DEMUX_open            (struct inode *inode, struct file *filp) ;
int DEMUX_release         (struct inode *inode, struct file *filp) ;

void DEMUX_PcrTrkRegRestore	  (void);
void DEMUX_wakeUpPoll     (void) ;
//int DEMUX_AllocBuffer     (DEMUX_BUF_T *pBuf, int size, int isCache, int useZone) ;
//int DEMUX_AllocFromPoll   (DEMUX_BUF_T *pBuf, int size, DEMUX_BUF_T *pSrcBuf, int isCache) ;
int DEMUX_checkFilterCount(demux_channel *channel);
//int DEMUX_FreeBuffer      (DEMUX_BUF_T *pBuf) ;
int GetTargetIdxFromType  (DEMUX_PID_TYPE_T pidType, DEMUX_PES_DEST_T  pesDest) ;
int  DEMUX_GetSecIndex    (demux_channel *channel);
void DEMUX_FreeSecIndex   (demux_channel *channel, unsigned char index);
void DEMUX_flushMemory    (unsigned char *pSrc, unsigned char *pSrcPhy, int bytes) ;

unsigned int DEMUX_RegRead32 (unsigned int addr) ;
void DEMUX_RegWrite32        (unsigned int addr, unsigned int value) ;

int64_t DEMUX_getPTS(void) ;
unsigned long      DEMUX_reverseInteger    (unsigned long value) ;  /* endian covert*/
unsigned long long DEMUX_reverseLongInteger(unsigned long long value) ;

void DUMP_StartDumpStream(demux_channel *pCh) ;
void DUMP_StopDumpStream (demux_channel *pCh) ;

int  DEMUX_ThreadProcEntry(void *pParam) ;
int  DEMUX_ResyncTSStream(const unsigned char *pData, unsigned int bytes);
int  DEMUX_GetSecRingBuffer (void *pContext, size_t count);
void DEMUX_FreeSecRingBuffer(void *pContext, size_t count);

/* IOCTL*/
//int DEMUX_InitModule            (DEMUX_INIT_T *pInfo) ;
int IOCTL_InitModule            (void);
int IOCTL_UnInitModule          (void);
int IOCTL_STDResetInfoPoll      (void);
int IOCTL_GetBufferInfo         (DEMUX_BUF_INFO_T *pInfo) ;
int IOCTL_GetSTC                (DEMUX_STC_T *pInfo) ;
int IOCTL_StartSCrambleCheck    (DEMUX_SCRAMBLE_T *pInfo) ;
int IOCTL_StopSCrambleCheck     (DEMUX_SCRAMBLE_T *pInfo) ;
int IOCTL_CheckSCrambledStatus  (DEMUX_SCRAMBLE_T *pInfo) ;
int IOCTL_SetPID                (DEMUX_SET_PID_T *pInfo) ;
int IOCTL_GetPID                (DEMUX_GET_PID_T *pInfo) ;
int IOCTL_AddSectionFilter      (DEMUX_ADD_SEC_FILTER_T *pInfo) ;
int IOCTL_CancelSectionFilter   (DEMUX_CANCEL_SEC_FILTER_T *pInfo) ;
int IOCTL_AddPESFilter          (DEMUX_ADD_PES_FILTER_T *pInfo) ;
int IOCTL_CancelPESFilter       (DEMUX_CANCEL_PES_FILTER_T *pInfo) ;
//int IOCTL_GetFilterResult       (DEMUX_GET_FILTER_RESULT_T *pInfo) ;
int IOCTL_FreeFilterBuffer      (DEMUX_FREE_FILTER_BUFFER_T *pInfo) ;
int IOCTL_StartPCRRecovery      (DEMUX_CHANNEL_T *pInfo) ;
int IOCTL_StopPCRRecovery       (DEMUX_CHANNEL_T *pInfo) ;
int IOCTL_ResetFilters          (DEMUX_RESET_FILTERS_T *pInfo) ;
int IOCTL_InitDescrambler       (DEMUX_INIT_DESCRAMBLER_T *pInfo) ;
int IOCTL_SetDescramblerMode    (DEMUX_DESCRAMBLER_MODE_T *pInfo) ;
int IOCTL_GetCWInfo             (DEMUX_DESCRAMBLER_CWINFO_T *pInfo);
int IOCTL_SetCW                 (DEMUX_SET_CW_T *pInfo) ;
int IOCTL_GetDescramblerIndex     (DEMUX_GET_DESC_INDEX_T *pInfo) ;
int IOCTL_MTPFlush              (DEMUX_MTP_FLUSH_T *pInfo) ;
int IOCTL_MTPGetBuffer          (DEMUX_PVR_BUF_INFO_T *pInfo) ;
int IOCTL_MTPWriteBuffer        (DEMUX_MTP_WRITE_T *pInfo) ;
int IOCTL_MTPGetWriteStatus     (DEMUX_MTP_WRITE_STATUS_T *pInfo) ;
int IOCTL_SetTimeStampPadding   (DEMUX_TIMESTAMP_SETTING_T *pInfo) ;
int IOCTL_SetTPParam            (DEMUX_TP_PARAM_T *pInfo) ;
int IOCTL_GetTPParam            (DEMUX_TP_PARAM_T *pInfo) ;
int IOCTL_SetTPSource           (DEMUX_TP_SOURCE_T *pInfo) ;
int IOCTL_GetTPSource           (DEMUX_TP_SOURCE_T *pInfo) ;
int IOCTL_SetPrivateInfo        (DEMUX_PRIVATE_INFO_T *pInfo) ;
int IOCTL_SetTPStreamControl    (DEMUX_TP_STREAM_CONTROL_T *pInfo) ;
int IOCTL_SetRecStatus          (DEMUX_REC_STATUS_T *pInfo) ;
int IOCTL_GetBufferInfoEX       (DEMUX_BUF_INFO_EX_T *pInfo) ;
int IOCTL_SetPidDescrambler     (DEMUX_ENABLE_DESCRAMBLER_T *pInfo) ;
int IOCTL_IsPidActive           (DEMUX_IS_PID_ACTIVE_T *pInfo) ;
int IOCTL_SetMtpStreaming       (DEMUX_MTP_STREAMING_STATUS_T *pInfo);
int IOCTL_ClearDescrambler      (DEMUX_CLEAR_DESCRAMBLER_T *pInfo) ;
int IOCTL_EnableDescrambler     (DEMUX_SWITCH_DESCRAMBLER_T *pInfo) ;
int IOCTL_SetCIChannel          (DEMUX_SET_CI_CHANNEL_T *pInfo) ;

int IOCTL_GetHardwareInfo       (DEMUX_GET_TP_HARDWARE_INFO_T *pInfo) ;
int IOCTL_DebugInfo             (DEMUX_DEBUG_INFO_T *pInfo) ;
int IOCTL_SetPidActive          (DEMUX_SET_MULTI_PID_T *pInfo) ;
int IOCTL_SetPIDs               (DEMUX_SET_MULTI_PID_T *pInfo) ;
int IOCTL_RemovePIDs            (DEMUX_REMOVE_PID_T    *pInfo) ;
int IOCTL_SetInputSourcePol	   (DEMUX_TP_INPUT_POL_T *pInfo);
int IOCTL_SetTPOutDataSource    (DEMUX_SET_TP_OUT_SOURCE_T *pInfo) ;
int IOCTL_SetTPOutStreamControl (DEMUX_SET_TP_OUT_STREAM_CONTROL_T *pInfo) ;
int IOCTL_SetTPOutClockSpeed(DEMUX_SET_TP_OUT_CLOCK_SPEED_T *pInfo);
int IOCTL_FreeAllPIDFilterIndex (DEMUX_FREE_DESCRAMBLE_INDEX_T *pInfo);
int IOCTL_ChangeAvSyncMode      (DEMUX_SET_SPEED_T *pInfo);
int IOCTL_GetTPStatus           (DEMUX_TP_STATUS_T *pStatus) ;
int DEMUX_CheckFullness         (demux_channel *pCh, enum OUTPUT_PIN_ENUM pin, DEMUX_BUF_PIN_T *pPinInfo);
int IOCTL_SetTPInputConfig	(DEMUX_TP_SOURCE_CONFIG_T *pInfo);
int IOCTL_GetFilterList(DEMUX_GET_FILTERS_T * pFilterList);
int IOCTL_GetTPPacketStatus(DEMUX_TP_PACKETSTATUS_T* pTpPs);
bool IOCTL_CheckRingBufferData(void);
void DEMUX_UpdateAFMode(demux_channel *pCh);
void DEMUX_ResetAVSync(demux_channel *pCh, AV_SYNC_MODE avSyncMode);
int IOCTL_FreeMTPBuf(DEMUX_CHANNEL_T *pInfo);
REFCLOCK* DEMUX_GetReferenceClock(demux_channel *channel);
bool DEMUX_HasReferenceClock(demux_channel *channel);
int DEMUX_CheckPTSChange(demux_channel *pCh);
void IOCTL_SetPinInfo(DEMUX_BUF_PIN_T *pPinInfo, RINGBUFFER_HEADER *pRBH, DEMUX_BUF_T *pBuf);
int IOCTL_ReleaseBuffer(DEMUX_BUF_INFO_T *pInfo);
int IOCTL_SetTPPatternSearchPID(DEMUX_TP_PATTERN_SEARCH_T *pInfo);
int IOCTL_GetTPInfoBuffer(DEMUX_PVR_BUF_INFO_T *pInfo);
//void IOCTL_ResetRBHeader(DEMUX_BUF_T *pBufH, DEMUX_BUF_T *pBuf, RINGBUFFER_TYPE type, unsigned char reverse);

/* End of _DEMUX_DRIVER_H_  */
#endif
