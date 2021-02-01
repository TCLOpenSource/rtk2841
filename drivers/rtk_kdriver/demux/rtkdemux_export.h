/******************************************************************************
*
*   Realtek Demux driver
*
*   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
*
*   @author lciou@realtek.com
*
*****************************************************************************/

#ifndef _DEMUX_EXPORT_H_
#define _DEMUX_EXPORT_H_
#include <linux/types.h>
#include <linux/ioctl.h>

#include <tp/tp_drv_global.h>

#ifndef UINT8
typedef    unsigned char            __UINT8;
#define UINT8 __UINT8
#endif

#ifndef UINT08
typedef    unsigned char            __UINT08;
#define UINT08 __UINT08
#endif

#ifndef SINT8
typedef    signed char                __SINT8;
#define SINT8 __SINT8
#endif

#ifndef SINT08
typedef    signed char                __SINT08;
#define SINT08 __SINT08
#endif

#ifndef CHAR
typedef    char                    __CHAR;
#define CHAR __CHAR
#endif

#ifndef UINT16
typedef    unsigned short            __UINT16;
#define UINT16 __UINT16
#endif

#ifndef SINT16
typedef    signed short            __SINT16;
#define SINT16 __SINT16
#endif

#ifndef UINT32
typedef    unsigned int            __UINT32;
#define UINT32 __UINT32
#endif

#ifndef SINT32
typedef signed int                __SINT32;
#define SINT32 __SINT32
#endif

#ifndef ULONG
typedef unsigned long            __ULONG;
#define ULONG __ULONG
#endif

#ifndef SLONG
typedef signed long                __SLONG;
#define SLONG __SLONG
#endif

#ifndef UINT64
typedef    unsigned long long        __UINT64;
#define UINT64 __UINT64
#endif

#ifndef SINT64
typedef    signed long long        __SINT64;
#define SINT64 __SINT64
#endif

#ifndef BOOLEAN
#ifndef _EMUL_WIN
typedef	unsigned int			__BOOLEAN;
#define BOOLEAN __BOOLEAN
#else
typedef	unsigned char		__BOOLEAN;
#define BOOLEAN __BOOLEAN
#endif
#endif

#define DEMUX_MAX_NUM_TO_SET        16
#define DEMUX_MAX_NUM_FILTER_TO_GET 60

#define DEMUX_PES_BUFFER_DYNAMIC_ALLOC
typedef enum {
    DEMUX_AUDIO_UNKNOWN_TYPE                        = 0,
    DEMUX_AUDIO_MPEG_DECODER_TYPE                   = 1,
    DEMUX_AUDIO_AC3_DECODER_TYPE                    = 2,
    DEMUX_AUDIO_LPCM_DECODER_TYPE                   = 3,
    DEMUX_AUDIO_DTS_DECODER_TYPE                    = 4,
    DEMUX_AUDIO_WMA_DECODER_TYPE                    = 5,
    DEMUX_AUDIO_AAC_DECODER_TYPE                    = 6,
    DEMUX_AUDIO_VORBIS_DECODER_TYPE                 = 7,
    DEMUX_AUDIO_DV_DECODER_TYPE                     = 8,
    DEMUX_AUDIO_MLP_DECODER_TYPE                    = 9,
    DEMUX_AUDIO_DDP_DECODER_TYPE                    = 10,
    DEMUX_AUDIO_DTS_HD_DECODER_TYPE                 = 11,
    DEMUX_AUDIO_WMA_PRO_DECODER_TYPE                = 12,
    DEMUX_AUDIO_MP4AAC_DECODER_TYPE                 = 13,
    DEMUX_AUDIO_MP3_PRO_DECODER_TYPE                = 14,
    DEMUX_AUDIO_MP4HEAAC_DECODER_TYPE               = 15,
    DEMUX_AUDIO_RAW_AAC_DECODER_TYPE                = 16,
    DEMUX_AUDIO_RA1_DECODER_TYPE                    = 17,
    DEMUX_AUDIO_RA2_DECODER_TYPE                    = 18,
    DEMUX_AUDIO_ATRAC3_DECODER_TYPE                 = 19,
    DEMUX_AUDIO_COOK_DECODER_TYPE                   = 20,
    DEMUX_AUDIO_LSD_DECODER_TYPE                    = 21,
    DEMUX_AUDIO_ADPCM_DECODER_TYPE                  = 22,
    DEMUX_AUDIO_FLAC_DECODER_TYPE                   = 23,
    DEMUX_AUDIO_ULAW_DECODER_TYPE                   = 24,
    DEMUX_AUDIO_ALAW_DECODER_TYPE                   = 25,
    DEMUX_AUDIO_ALAC_DECODER_TYPE                   = 26,
    DEMUX_AUDIO_DTS_HIGH_RESOLUTION_DECODER_TYPE    = 27,
    DEMUX_AUDIO_DTS_LBR_DECODER_TYPE                = 28,
    DEMUX_AUDIO_DTS_MASTER_DEMUX_AUDIO_DECODER_TYPE = 29,
    DEMUX_AUDIO_AMRNB_DECODER_TYPE                  = 30,
    DEMUX_AUDIO_MIDI_DECODER_TYPE                   = 31,
    DEMUX_AUDIO_APE_DECODER_TYPE                    = 32,
    DEMUX_AUDIO_AVS_DECODER_TYPE                    = 33,
    DEMUX_AUDIO_NELLYMOSER_DECODER_TYPE             = 34,
    DEMUX_AUDIO_WMA_LOSSLESS_DECODER_TYPE           = 35,
    DEMUX_AUDIO_UNCERTAIN_DECODER_TYPE              = 36,
    DEMUX_AUDIO_UNCERTAIN_HDMV_DECODER_TYPE         = 37,
    DEMUX_AUDIO_ILBC_DECODER_TYPE                   = 38,
    DEMUX_AUDIO_SILK_DECODER_TYPE                   = 39,
    DEMUX_AUDIO_AMRWB_DECODER_TYPE                  = 40,
    DEMUX_AUDIO_G729_DECODER_TYPE                   = 41,
    DEMUX_AUDIO_DRA_DECODER_TYPE                    = 42,
    DEMUX_AUDIO_OPUS_DECODER_TYPE                   = 43,

} DEMUX_AUDIO_DEC_T ;

typedef enum {
	DEMUX_PRIVATEINFO_NONE = 0,
	DEMUX_PRIVATEINFO_NOTIFY_FLUSHED = 1,      /* demux will send new segment and decode command to inband queue after audio/video decoder is flushed */
	DEMUX_PRIVATEINFO_AUDIO_FORMAT = 2,        /* new format, first long data is AUDIO_DEC_TYPE, the others are privateInfo[0~7]*/
	DEMUX_PRIVATEINFO_VIDEO_DECODE_MODE = 3,   /* video decoder mode : DECODE_MODE*/
	DEMUX_PRIVATEINFO_VIDEO_FREERUN_THRESHOLD = 4,   /* Video FreeRun Threshold */
	DEMUX_PRIVATEINFO_PCR_TRACK = 5,                 /* Pcr Track enable/disable */
	DEMUX_PRIVATEINFO_AUDIO_PAUSE = 6,
	DEMUX_PRIVATEINFO_APVR_PLAYBACK_START = 7,  /* To nitify APVR playback start */
} DEMUX_PRIVATEINFO_T ;

typedef struct {
  UINT8  useSDT ;
  UINT8  numberOfTP ;
  UINT8  numberOfVD ;
  UINT8  numberOfAD ;
  UINT32 sizeOfRefClock ;
  UINT32 sizeOfTP ;
  UINT32 sizeOfVideoBS ;
  UINT32 sizeOfVideoIB ;
  UINT32 sizeOfAudioBS ;
  UINT32 sizeOfAudioIB ;

} DEMUX_INIT_T ;

typedef enum {
  DEMUX_CH_A = 0,
  DEMUX_CH_B,
  DEMUX_CH_C,
  DEMUX_CH_D,
  DEMUX_CH_NUM

} DEMUX_CHANNEL_T ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;
  UINT32 stc_hi ;
  UINT32 stc_lo ;

} DEMUX_STC_T ;

typedef enum {
  DEMUX_PID_VIDEO = 0,
  DEMUX_PID_AUDIO ,
  DEMUX_PID_AUDIO_DESCRIPTION = DEMUX_PID_AUDIO,
  DEMUX_PID_PCR ,
  DEMUX_PID_TELETEXT ,
  DEMUX_PID_SUBTITLE ,
  DEMUX_PID_DCC = DEMUX_PID_SUBTITLE ,
  DEMUX_PID_PSI,
  DEMUX_PID_GP ,
  DEMUX_PID_TYPE_NUM

} DEMUX_PID_TYPE_T ;
#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
typedef enum{
  DEMUX_PESBUFFER_OP_PENDING_FOR_INIT = 0,
  DEMUX_PESBUFFER_OP_INITIALIZED,
}DEMUX_PESBUFFER_OP_STATUS;
#endif
typedef struct {
  DEMUX_CHANNEL_T  ch ;
  DEMUX_PID_TYPE_T pidType ;
  UINT16           pid ;

} DEMUX_SCRAMBLE_T ;

typedef enum {
  DEMUX_DEST_NONE = 0,
  DEMUX_DEST_ADEC0 ,
  DEMUX_DEST_ADEC1,
  DEMUX_DEST_VDEC0,
  DEMUX_DEST_VDEC1,
  DEMUX_DEST_STC0,
  DEMUX_DEST_STC1,
  DEMUX_DEST_BUFFER,
  DEMUX_DEST_RECORD_A,
  DEMUX_DEST_RECORD_B,
  DEMUX_DEST_TSO,
  DEMUX_DEST_NUM

} DEMUX_PES_DEST_T ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;
  UINT16           pid ;
  DEMUX_PID_TYPE_T pidType ;
  DEMUX_PES_DEST_T dest ;

} DEMUX_SET_PID_T ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;
  DEMUX_PID_TYPE_T pidType ;
  DEMUX_PES_DEST_T dest ;

} DEMUX_GET_PID_T ;

typedef struct {

  TPK_DESCRAMBLE_ALGORITHM_T algo;

} DEMUX_GET_DESC_INDEX_T ;

typedef struct {
  DEMUX_CHANNEL_T          ch ;   /* IN */
  TPK_SEC_FILTER_PARAM_T   param ;/* IN */
  UINT32                   size ; /* IN, buffer size for this section filter */

  UINT32 baseAddr ;          /* OUT, the base address of BitStream RBH */
  UINT32 baseAllocSize ;     /* OUT, allocated size from base address */
  UINT32 headerPhyAddr ;     /* OUT, the address of BitStream RBH */
  SINT32 headerSize;         /* OUT */
  SINT32 allocSize;          /* OUT, allocated size for this section filter */

} DEMUX_ADD_SEC_FILTER_T ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;
  UINT8            secfIndex ;

} DEMUX_CANCEL_SEC_FILTER_T ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;      /* IN */
  DEMUX_PID_TYPE_T pidType ; /* IN */
  UINT16           pid ;     /* IN */
  UINT32           size ;    /* IN, buffer size for this pes filter */

  UINT32 baseAddr ;          /* OUT, the base address of BitStream RBH */
  UINT32 baseAllocSize ;     /* OUT, allocated size from base address */
  UINT32 headerPhyAddr ;     /* OUT, the address of BitStream RBH */
  SINT32 headerSize;         /* OUT */
  SINT32 allocSize;          /* OUT, allocated size for this pes filter */

} DEMUX_ADD_PES_FILTER_T ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;
  UINT8            pesfIndex ;

} DEMUX_CANCEL_PES_FILTER_T ;

typedef enum {
  DEMUX_BUFFER_TYPE_SECTION = 0,
  DEMUX_BUFFER_TYPE_PES,
  DEMUX_BUFFER_TYPE_REFCLOCK,
  DEMUX_BUFFER_TYPE_BUFFERHEADERPOOL,

} DEMUX_BUFFER_TYPE_T ;


typedef struct {
  DEMUX_CHANNEL_T     ch ;
  UINT16              pid ;
  UINT8               isPES ;
  UINT8               index ;       /*secfIndex or pesfIndex*/
  UINT32              phyAddr ;
  UINT32              size ;

} DEMUX_FREE_FILTER_BUFFER_T ;

typedef enum {
  DEMUX_CLEAN_ALL = 0,
  DEMUX_CLEAN_AV,
  DEMUX_CLEAN_VIDEO,
  DEMUX_CLEAN_AUDIO,
  DEMUX_CLEAN_PCR,
  DEMUX_CLEAN_WO_AV,
  DEMUX_CLEAN_SECTION,
  DEMUX_CLEAN_PES,
  DEMUX_CLEAN_RECORD_A,
  DEMUX_CLEAN_RECORD_B,
  DEMUX_CLEAN_PVR,

} DEMUX_CLEANING_SCOPE_T ;

typedef struct {
  DEMUX_CHANNEL_T        ch ;
  DEMUX_CLEANING_SCOPE_T scope ;

} DEMUX_RESET_FILTERS_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    DEMUX_PES_DEST_T dest ;
    UINT32 bsPhyAddr ;                /* the address of BitStream RBH*/
    UINT32 ibPhyAddr ;                /* the address of InBand    RBH*/
    UINT32 refClockPhyAddr ;
    SINT32 bsHeaderSize;
    SINT32 ibHeaderSize;
    SINT32 refClockHeaderSize;

} DEMUX_BUF_INFO_T ;

typedef struct {
    DEMUX_CHANNEL_T     ch ;
    DEMUX_BUFFER_TYPE_T bufferType ;
    UINT32              phyAddr ;           /* base phyAddr and size for mmap to set once*/
    UINT32              size ;

} DEMUX_BUF_INFO_EX_T ;

typedef struct {
  DEMUX_CHANNEL_T            ch ;
  TPK_DESCRAMBLE_ALGORITHM_T alg ;

} DEMUX_INIT_DESCRAMBLER_T ;

typedef struct {
  DEMUX_CHANNEL_T       ch ;
  TPK_DESCRAMBLE_MODE_T mode ;

} DEMUX_DESCRAMBLER_MODE_T ;

typedef enum {
    DEMUX_SET_CW_ONLY_IV,
    DEMUX_SET_CW_ONLY_KEY,
    DEMUX_SET_CW_ALL,

} DEMUX_SET_CW_E ;

typedef struct {
  DEMUX_CHANNEL_T       ch ;
  DEMUX_SET_CW_E        keyType ;
  UINT32                KeySel ;    /* set pid_filter_idx*/
  UINT8                 key_id ;    /* please refer to TP's definition*/
  UINT8                 Key[TPK_MAX_KEY_LENGTH] ;
  UINT8                 IV[TPK_MAX_IV_LENGTH] ;

} DEMUX_SET_CW_T ;

typedef enum {
    DEMUX_MTP_SYNC_TO_BASE,
    DEMUX_MTP_SYNC_TO_RP,
    DEMUX_MTP_SYNC_TO_WP
} DEMUX_MTP_FLUSH_MODE_E;

typedef struct {
    DEMUX_CHANNEL_T ch;
    DEMUX_MTP_FLUSH_MODE_E mode;
} DEMUX_MTP_FLUSH_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    ULONG bufPhyAddr;
    SINT32 bufSize;
} DEMUX_PVR_BUF_INFO_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    ULONG writeAddr; /*physical address*/
    SINT32 writeSize;
} DEMUX_MTP_WRITE_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    ULONG writeAddr; /*physical address*/
    SINT32 contiguousWritableSize;
    SINT32 writableSize;
} DEMUX_MTP_WRITE_STATUS_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    UINT8 bEnable;
} DEMUX_TIMESTAMP_SETTING_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    TPK_TP_TS_PARAM_T tpParam;
} DEMUX_TP_PARAM_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    TPK_TP_SOURCE_T tpSrc;
    TPK_CAS_TYPE_T casType;
} DEMUX_TP_SOURCE_T;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    DEMUX_PES_DEST_T dest ;
    ULONG            data[10] ;

} DEMUX_PRIVATE_INFO_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    TPK_TP_STREAM_CTRL_T ctrl ;

} DEMUX_TP_STREAM_CONTROL_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    unsigned char    bStartRec; /* 1 : start record, 0 : stop record*/
} DEMUX_REC_STATUS_T;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    UINT8            bEnable ;
    UINT16           pid ;
    DEMUX_PID_TYPE_T pidType ;
    UINT32           KeySel ;    /* pid_filter_idx*/

} DEMUX_ENABLE_DESCRAMBLER_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    UINT16           pid ;
    DEMUX_PID_TYPE_T pidType ;
    UINT32           KeySel ;    /* pid_filter_idx*/

} DEMUX_CLEAR_DESCRAMBLER_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    UINT8            bEnable ;
    UINT16           pid ;
    UINT32           KeySel ;    /* pid_filter_idx*/

} DEMUX_SWITCH_DESCRAMBLER_T ;

typedef struct {
    UINT32          KeySel ;    /* pid_filter_idx*/
    unsigned char   used ;          /* gotten by API*/
    unsigned short  pid ;
    DEMUX_CHANNEL_T ch ;

} DEMUX_DESCRAMBLER_CWINFO_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    DEMUX_PID_TYPE_T pidType ;
    UINT16           pid ;

} DEMUX_IS_PID_ACTIVE_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    unsigned char bStartStreaming;
} DEMUX_MTP_STREAMING_STATUS_T;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    unsigned char    bCI;

} DEMUX_SET_CI_CHANNEL_T ;

typedef struct {
    DEMUX_CHANNEL_T  ch ;
    DEMUX_PES_DEST_T dest ;
    unsigned char    bEnable ;
    UINT32 bsPhyAddr ;                /* the address of BitStream RBH*/
    SINT32 bsHeaderSize;

} DEMUX_SET_DUMP_ES_T ;

typedef struct {
  TPK_HARDWARE_INFO_T tpInfo ;

} DEMUX_GET_TP_HARDWARE_INFO_T ;

typedef enum {
    DEMUX_DEBUG_PRINT_PID_LIST,
    DEMUX_DEBUG_PRINT_PID_FOR_PES,

} DEMUX_DEBUG_INFO_E ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;
  DEMUX_DEBUG_INFO_E eType ;

} DEMUX_DEBUG_INFO_T ;

typedef struct {
  DEMUX_CHANNEL_T ch ;
  unsigned char   count ;
  DEMUX_SET_PID_T pidlist[DEMUX_MAX_NUM_TO_SET] ; /* don't care ch in DEMUX_SET_PID_T*/

} DEMUX_SET_MULTI_PID_T ;

typedef struct {
  DEMUX_CHANNEL_T ch ;
  unsigned char   count ;
  UINT16          pid[DEMUX_MAX_NUM_TO_SET] ;

} DEMUX_REMOVE_PID_T ;

typedef struct {
  TPK_TPI_PIN_T tpi;
  TPK_TP_INPUT_PARAM_T pol ;
} DEMUX_TP_INPUT_POL_T ;

typedef struct {
  UINT8             tpout_id ;
  TPK_TPOUT_SOURCE_T tpout_src;
  TPK_TPOUT_REMUX_PARAM_T *remux_param;
} DEMUX_SET_TP_OUT_SOURCE_T ;

typedef struct {
  UINT8             tpout_id ;
  TPK_TPOUT_STREAM_CTRL_T ctrl ;

} DEMUX_SET_TP_OUT_STREAM_CONTROL_T ;

typedef struct {
    UINT8           tpout_id ;
    UINT32          pre_div ;
    UINT32          post_div ;

} DEMUX_SET_TP_OUT_CLOCK_SPEED_T ;

typedef struct {
  DEMUX_CHANNEL_T  ch ;
  UINT32 reserved ;

} DEMUX_FREE_DESCRAMBLE_INDEX_T ;

typedef struct {
  DEMUX_CHANNEL_T ch;
  int             speed;
} DEMUX_SET_SPEED_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    TPK_TP_STATUS_T tpStatus;
} DEMUX_TP_STATUS_T;

typedef struct {
  DEMUX_CHANNEL_T 	ch;
  TPK_INPUT_PORT_T 	portType;
  TPK_INPUT_TYPE_T 	inputType;
  TPK_CAS_TYPE_T	casType;
} DEMUX_TP_SOURCE_CONFIG_T;



typedef struct{
	UINT16 pid;
	UINT8 pidClass;//0:pid, 1: pes, 2:section
	UINT32 innerIndex;
	DEMUX_PID_TYPE_T type;
	DEMUX_PES_DEST_T dest;
	UINT8 tid;
	UINT32 gpb_size;
	int cwIndex;
	BOOL enDescramble;
}DEMU_FILTER_T;

typedef struct {
	DEMUX_CHANNEL_T ch;
	UINT32 size;
	DEMU_FILTER_T filterList[DEMUX_MAX_NUM_FILTER_TO_GET];
}DEMUX_GET_FILTERS_T;


typedef struct{
	DEMUX_CHANNEL_T ch;
	UINT32 rev;
	UINT32 err;
	UINT32 drop;
}DEMUX_TP_PACKETSTATUS_T;

typedef struct{
	DEMUX_CHANNEL_T ch;
	UINT8 enable;
	UINT8 * file;
	UINT32 fsize;
}DEMUX_TP_DUMPTSDATA_T;

typedef struct {
    DEMUX_CHANNEL_T ch;
    UINT16          pid ;
} DEMUX_TP_PATTERN_SEARCH_T;

#define DEMUX_IOC_MAGIC  'z'

#define DEMUX_IOC_INIT                      (_IOWR(DEMUX_IOC_MAGIC, 0, DEMUX_INIT_T*))
#define DEMUX_IOC_UNINIT                    (_IOR (DEMUX_IOC_MAGIC, 1, int))
#define DEMUX_IOC_GET_BUF_INFO              (_IOWR(DEMUX_IOC_MAGIC, 2, DEMUX_BUF_INFO_T*))             /* for connect*/
#define DEMUX_IOC_GET_STC                   (_IOWR(DEMUX_IOC_MAGIC, 3, DEMUX_STC_T*))
#define DEMUX_IOC_START_SCRAMBLE_CHECK      (_IOR (DEMUX_IOC_MAGIC, 4, DEMUX_SCRAMBLE_T*))
#define DEMUX_IOC_STOP_SCRAMBLE_CHECK       (_IOR (DEMUX_IOC_MAGIC, 5, DEMUX_SCRAMBLE_T*))
#define DEMUX_IOC_CHECK_SCRAMBLED_STATUS    (_IOR (DEMUX_IOC_MAGIC, 6, DEMUX_SCRAMBLE_T*))              /* return isScrambled*/
#define DEMUX_IOC_SET_PID                   (_IOR (DEMUX_IOC_MAGIC, 7, DEMUX_SET_PID_T*))
#define DEMUX_IOC_GET_PID                   (_IOR (DEMUX_IOC_MAGIC, 8, DEMUX_GET_PID_T*))
#define DEMUX_IOC_ADD_SECTION_FILTER        (_IOWR(DEMUX_IOC_MAGIC, 9, DEMUX_ADD_SEC_FILTER_T*))        /* return secfIndex*/
#define DEMUX_IOC_CANCEL_SECTION_FILTER     (_IOR (DEMUX_IOC_MAGIC, 10, DEMUX_CANCEL_SEC_FILTER_T*))
#define DEMUX_IOC_ADD_PES_FILTER            (_IOWR(DEMUX_IOC_MAGIC, 11, DEMUX_ADD_PES_FILTER_T*))        /* return pesfIndex*/
#define DEMUX_IOC_CANCEL_PES_FILTER         (_IOR (DEMUX_IOC_MAGIC, 12, DEMUX_CANCEL_PES_FILTER_T*))
//#define DEMUX_IOC_GET_FILTER_RESULT         (_IOW (DEMUX_IOC_MAGIC, 13, DEMUX_GET_FILTER_RESULT_T*))
#define DEMUX_IOC_FREE_FILTER_BUFFER        (_IOR (DEMUX_IOC_MAGIC, 14, DEMUX_FREE_FILTER_BUFFER_T*))
#define DEMUX_IOC_START_PCR_RECOVERY        (_IOR (DEMUX_IOC_MAGIC, 15, DEMUX_CHANNEL_T*))
#define DEMUX_IOC_STOP_PCR_RECOVERY         (_IOR (DEMUX_IOC_MAGIC, 16, DEMUX_CHANNEL_T*))
#define DEMUX_IOC_RESET_FILTERS             (_IOR (DEMUX_IOC_MAGIC, 17, DEMUX_RESET_FILTERS_T*))
#define DEMUX_IOC_INIT_DESCRAMBLER          (_IOR (DEMUX_IOC_MAGIC, 18, DEMUX_INIT_DESCRAMBLER_T*))
#define DEMUX_IOC_GET_DESCRAMBLER_INDEX      (_IOR (DEMUX_IOC_MAGIC, 19, DEMUX_SET_PID_T*))               /* return index*/
#define DEMUX_IOC_SET_CW                    (_IOR (DEMUX_IOC_MAGIC, 20, DEMUX_SET_CW_T*))
#define DEMUX_IOC_MTP_FLUSH                 (_IOR (DEMUX_IOC_MAGIC, 21, DEMUX_MTP_FLUSH_T*))
#define DEMUX_IOC_MTP_GET_BUF               (_IOWR(DEMUX_IOC_MAGIC, 22, DEMUX_PVR_BUF_INFO_T*))
#define DEMUX_IOC_MTP_WRITE_BUF             (_IOR (DEMUX_IOC_MAGIC, 23, DEMUX_MTP_WRITE_T*))
#define DEMUX_IOC_MTP_GET_WRITE_STATUS      (_IOWR(DEMUX_IOC_MAGIC, 24, DEMUX_MTP_WRITE_STATUS_T*))
#define DEMUX_IOC_SET_TIMESTAMP_PADDING     (_IOR (DEMUX_IOC_MAGIC, 25, DEMUX_TIMESTAMP_SETTING_T*))
#define DEMUX_IOC_SET_TP_PARAM              (_IOR (DEMUX_IOC_MAGIC, 26, DEMUX_TP_PARAM_T*))
#define DEMUX_IOC_GET_TP_PARAM              (_IOWR(DEMUX_IOC_MAGIC, 27, DEMUX_TP_PARAM_T*))
#define DEMUX_IOC_SET_TP_DATA_SOURCE        (_IOR (DEMUX_IOC_MAGIC, 28, DEMUX_TP_SOURCE_T*))
#define DEMUX_IOC_GET_TP_DATA_SOURCE        (_IOWR(DEMUX_IOC_MAGIC, 29, DEMUX_TP_SOURCE_T*))
#define DEMUX_IOC_SET_PRIVATE_INFO          (_IOR (DEMUX_IOC_MAGIC, 30, DEMUX_PRIVATE_INFO_T*))
#define DEMUX_IOC_SET_DESCRAMBLER_MODE      (_IOR (DEMUX_IOC_MAGIC, 31, DEMUX_DESCRAMBLER_MODE_T*))
#define DEMUX_IOC_TP_STREAM_CONTROL         (_IOR (DEMUX_IOC_MAGIC, 32, DEMUX_TP_STREAM_CONTROL_T*))
#define DEMUX_IOC_SET_RECORD_STATUS         (_IOR (DEMUX_IOC_MAGIC, 33, DEMUX_REC_STATUS_T*))
#define DEMUX_IOC_GET_BUF_INFO_EX           (_IOWR(DEMUX_IOC_MAGIC, 34, DEMUX_BUF_INFO_EX_T*))              /* for Section/PES filter*/
#define DEMUX_IOC_SET_PID_DESCRAMBLER        (_IOR (DEMUX_IOC_MAGIC, 35, DEMUX_ENABLE_DESCRAMBLER_T*))
#define DEMUX_IOC_IS_PID_ACTIVE             (_IOR (DEMUX_IOC_MAGIC, 36, DEMUX_IS_PID_ACTIVE_T*))
#define DEMUX_IOC_SET_MTP_STREAMING_STATUS  (_IOR (DEMUX_IOC_MAGIC, 37, DEMUX_MTP_STREAMING_STATUS_T*))
#define DEMUX_IOC_CLEAR_DESCRAMBLER         (_IOR (DEMUX_IOC_MAGIC, 38, DEMUX_CLEAR_DESCRAMBLER_T*))
#define DEMUX_IOC_ENABLE_DESCRAMBLER        (_IOR (DEMUX_IOC_MAGIC, 39, DEMUX_SWITCH_DESCRAMBLER_T*))
#define DEMUX_IOC_SET_CI_CHANNEL            (_IOR (DEMUX_IOC_MAGIC, 40, DEMUX_SET_CI_CHANNEL_T*))

#define DEMUX_IOC_GET_TP_HARDWARE_INFO      (_IOW (DEMUX_IOC_MAGIC, 42, DEMUX_GET_TP_HARDWARE_INFO_T*))
#define DEMUX_IOC_DEBUG_INFO                (_IOR (DEMUX_IOC_MAGIC, 43, DEMUX_DEBUG_INFO_T*))
#define DEMUX_IOC_SET_PID_ACTIVE            (_IOR (DEMUX_IOC_MAGIC, 44, DEMUX_SET_MULTI_PID_T*))
#define DEMUX_IOC_SET_PID_MULTI             (_IOR (DEMUX_IOC_MAGIC, 45, DEMUX_SET_MULTI_PID_T*))
#define DEMUX_IOC_REMOVE_PID_MULTI          (_IOR (DEMUX_IOC_MAGIC, 46, DEMUX_REMOVE_PID_T*))
//#define DEMUX_IOC_SET_TS_PORT_ID            (_IOR (DEMUX_IOC_MAGIC, 47, DEMUX_SET_TS_PORT_ID_T*))    /* set to TP for 294x+*/
//#define DEMUX_IOC_SET_TS_MUX_IN             (_IOR (DEMUX_IOC_MAGIC, 48, DEMUX_SET_TS_MUX_IN_T*))     /* set to TP for 294x+*/
#define DEMUX_IOC_SET_TP_INPUT_POL          (_IOR (DEMUX_IOC_MAGIC, 49, DEMUX_TP_INPUT_POL_T*))      /* set to TP for 284x+*/
#define DEMUX_IOC_SET_TP_OUT_DATA_SOURCE    (_IOR (DEMUX_IOC_MAGIC, 50, DEMUX_SET_TP_OUT_SOURCE_T*))        /* set to TP for 284x+*/
#define DEMUX_IOC_SET_TP_OUT_STREAM_CONTROL    (_IOR (DEMUX_IOC_MAGIC, 51, DEMUX_SET_TP_OUT_STREAM_CONTROL_T*))   /* set to TP for 294x+*/
#define DEMUX_IOC_FREE_DESCRAMBLE_INDEX    (_IOR (DEMUX_IOC_MAGIC, 52, DEMUX_FREE_DESCRAMBLE_INDEX_T*))
#define DEMUX_IOC_SET_SPEED                (_IOR (DEMUX_IOC_MAGIC, 53, DEMUX_SET_SPEED_T*))
#define DEMUX_IOC_GET_TP_STATUS              (_IOWR(DEMUX_IOC_MAGIC, 54, DEMUX_TP_STATUS_T*))
#define DEMUX_IOC_SET_TP_INPUT_CONFIG      (_IOWR (DEMUX_IOC_MAGIC, 55, DEMUX_TP_SOURCE_CONFIG_T*))
#define DEMUX_IOC_GET_FILTERLIST	(_IOWR(DEMUX_IOC_MAGIC, 56, DEMUX_GET_FILTERS_T*))
#define DEMUX_IOC_GET_TP_PACKETSTATUS 	(_IOWR(DEMUX_IOC_MAGIC, 57, DEMUX_TP_PACKETSTATUS_T*))

#define DEMUX_IOC_GET_DESCRAMBLER_CWINFO (_IOWR(DEMUX_IOC_MAGIC, 59, DEMUX_DESCRAMBLER_CWINFO_T*))
#define DEMUX_IOC_FREE_MTP                  (_IOR (DEMUX_IOC_MAGIC, 60, DEMUX_CHANNEL_T*))
#define DEMUX_IOC_RELEASE_BUF               (_IOR (DEMUX_IOC_MAGIC, 61, DEMUX_BUF_INFO_T*))
#define DEMUX_IOC_SET_PATTERN_SEARCH_PID    (_IOR (DEMUX_IOC_MAGIC, 62, DEMUX_TP_PATTERN_SEARCH_T*))
#define DEMUX_IOC_GET_INFO_BUF              (_IOWR(DEMUX_IOC_MAGIC, 63, DEMUX_PVR_BUF_INFO_T*))
#define DEMUX_IOC_HALLOG                  (_IOW (DEMUX_IOC_MAGIC, 64, int))
#define DEMUX_IOC_SET_TP_OUT_CLOCK_SPEED    (_IOR (DEMUX_IOC_MAGIC,65, DEMUX_SET_TP_OUT_CLOCK_SPEED_T*))

#define DEMUX_IOC_MAXNR           66

#endif
