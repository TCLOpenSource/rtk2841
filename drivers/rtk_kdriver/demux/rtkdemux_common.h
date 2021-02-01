#ifndef _DEMUX_DRIVER_COMMON_H_
#define _DEMUX_DRIVER_COMMON_H_

#if 0
#define DEMUX_REC_HACK_TIMESTAMP
#endif
#if 1
#define DEMUX_REC_FROM_TP_BUF       /* record from TP ringbuffer*/
#endif
#define DEMUX_REQ_RB_ON_DEMAND      /* request ringbuffer ONLY while connection has been called*/
#define DEMUX_DISABLE_CACHE_BUFFER  (0)
#define DEMUX_USE_DDR_COPY          (0)         /* MD*/

#define MAX_BYTES_TO_CALC_RATE      (0x200000)    /* 2 MBs: 2*8MBits/sec, so above 2 secs*/

#define MAX_DESCRAMBLER_INDEX_NUM   (32)

#define MAX_SECTION_FILTER_NUM      (64)
#define SEC_FILTER_BUFFER_UNIT_SIZE (32*1024)	/* each is 32K */
#define SEC_FILTER_BUFFER_UNIT_CNT  (128)	/* 128*32K = 4M */
#define SEC_FILTER_BUFFER_SIZE      (SEC_FILTER_BUFFER_UNIT_SIZE*SEC_FILTER_BUFFER_UNIT_CNT) /* all channels use this pool */
#define SEC_FILTER_BUFFER_EACH_SIZE (4096)

/* 256K for both of subtitle and TT ringbuffer */
#define MAX_PID_FILTER_CB_NUM       (2)        /* one is subtitle, another is TT */
#define PES_FILTER_RING_BUFFER_SIZE (0x40000) /* 256K */
#define PES_FILTER_BUFFER_SIZE      (PES_FILTER_RING_BUFFER_SIZE*MAX_PID_FILTER_CB_NUM) /* each channel allocate one buffer */

#define DEFAULT_READ_WRITE_SIZE    (94*1024*2)    /*for devices with sector size 4k(refer to bug 18414), LCM(188, 4096)*/
#define TUNER_RING_BUFFER_SIZE     (DEFAULT_READ_WRITE_SIZE * 15)
#define TUNER_DATA_READ_THRESHOLD  (DEFAULT_READ_WRITE_SIZE)
#define TUNER_DATA_READ_WAIT_TIME  (20)
#define TUNER_RECORD_MAX_IDLE      (10)
#define MAX_TUNER_DATA_READ_WAIT_TIME  (100)

#define LCM_192_4096                  (12288)         /* LCM(192, 4096), LCM is the abbreviation of "Least Common Multiple"*/
#define LCM_188_4096                  (94*1024*2)     /* LCM(188, 4096)*/

#define DTV_LEAST_DELIVER_SIZE        188 /* 752 //least common multiple of 188 and 16*/

#define NAV_SLEEP_TIME_ON_NORMAL_READ 3 /* milliseconds*/
#define NAV_SLEEP_TIME_ON_FAST_READ   1 /* milliseconds*/
#define NAV_SLEEP_TIME_ON_IDLE        100 /* milliseconds*/
#define NAV_MUTEX_TIMEOUT_NS          500000000 /* nanoseconds*/
#define NAV_PAUSE_DELAY_LOOPS         10    /* max number of sleeps (20 ms each) in pause delay loop*/
#define NAV_PAUSE_DELAY_BYTES         10240 /* number of bytes read before ending pause delay loop*/

#define PES_HEADER_BUF_SIZE   14
#define NUM_OF_NAV_BUFFERS    64

#define MAX_PID_FILTER_NUMBER 64

#define SDT_CH_BUFF_SIZE			(512*1024)

#define INPUT_IS_VIDEO_TARGET(_target) ((_target) == INPUT_TARGET_VIDEO || (_target) == INPUT_TARGET_VIDEO_2ND)
#define INPUT_IS_AUDIO_TARGET(_target) ((_target) == INPUT_TARGET_AUDIO || (_target) == INPUT_TARGET_AUDIO_2ND)

#define DEMUX_IS_VIDEO_TARGET(_target) ((_target) == DEMUX_TARGET_VIDEO || (_target) == DEMUX_TARGET_VIDEO_2ND)
#define DEMUX_IS_AUDIO_TARGET(_target) ((_target) == DEMUX_TARGET_AUDIO || (_target) == DEMUX_TARGET_AUDIO_2ND)

/* get the distance between two positions in the bitstream ring bufferrange */
#define BS_DISTANCE(start, end, base, limit) \
((end) + ((end) > (start) ? 0 : limit - base) - (start))

#define BS_DISTANCE2(start, end, buffer_size) \
((end) + ((end) > (start) ? 0 : buffer_size) - (start))

/* check range: start exclusive, end exclusive */
#define So_oE(x, start, end) \
(((end) == (start) &&  ((x) == (start))) \
 || ((end)  > (start) &&  ((x) >  (start) && (x) <  (end)))  \
 || ((end)  < (start) && !((x) <= (start) && (x) >= (end))) \
)

#ifndef MAX
#define MAX(a , b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef ABS
#define ABS(x)   ((x)>=0?(x):-(x))
#endif

      enum OUTPUT_PIN_ENUM {
	VIDEO_PIN = 0,
	AUDIO_PIN,
	VIDEO2_PIN,
	AUDIO2_PIN,
	NUMBER_OF_PINS };

enum {
	DEMUX_TARGET_VIDEO,
	DEMUX_TARGET_AUDIO,    /*active audio*/
	DEMUX_TARGET_VIDEO_2ND,
	DEMUX_TARGET_AUDIO_2ND,
	DEMUX_NUM_OF_TARGETS,
	DEMUX_TARGET_DROP     = 0x1F,
};
enum {
	EVENT_UPDATE_AUDIO_FORMAT      = 1 << 0,
	EVENT_DISCONTINUITY            = 1 << 1,
	EVENT_DROP_PACKET              = 1 << 2,
	EVENT_AUDIO_CHECK_PES_PRIORITY = 1 << 3,
	EVENT_AUDIO_DATA_DISCONTINUITY = 1 << 4,
	EVENT_UPDATE_AD_INFO           = 1 << 6,
};

enum {
	//EVENT_FLUSH_VIDEO                = 1 << 0,
	//EVENT_FLUSH_AUDIO                = 1 << 1,
	//EVENT_FLUSH_VIDEO2               = 1 << 2,
	//EVENT_FLUSH_AUDIO2               = 1 << 3,
	//EVENT_AUDIO_NEW_FORMAT           = 1 << 4,
	//EVENT_AUDIO2_NEW_FORMAT          = 1 << 5,
	EVENT_UPDATE_TS_LIST             = 1 << 6,
	EVENT_UPDATE_PES_LIST            = 1 << 7,
	EVENT_UPDATE_SCRAMBLE_LIST       = 1 << 8,
	//1<<9
	EVENT_VIDEO0_NEW_DECODE_MODE     = 1 << 10,
	EVENT_VIDEO1_NEW_DECODE_MODE     = 1 << 11,
	EVENT_FLUSH_TP                   = 1 << 12,
	EVENT_CHANGE_CLK_SRC             = 1 << 13,
	EVENT_FLUSH_AD_INFO              = 1 << 14,
	EVENT_FLUSH_MTP                  = 1 << 15,
	EVENT_SET_AUDIO_PIN_INFO	     = 1 << 16,
};
enum {
	STATUS_AUDIO_PAUSED              = 1 << 0,
	STATUS_CHECK_PVR_AUDIO_STABLE    = 1 << 1,
	STATUS_TP_RATE_CONTROL_ENABLED   = 1 << 2,
	STATUS_PVR_AUDIO_IS_STABLE       = 1 << 3,
	STATUS_PCRTAK_START              = 1 << 4,
	STATUS_PCRTAK_STOP               = 1 << 5,
	STATUS_APVR_PLAYBACK_START       = 1 << 6,
	STATUS_SET_AUDIO_PIN_INFO        = 1 << 7,
	STATUS_SET_VIDEO_FLUSH			 = 1 << 8,
	STATUS_SET_VIDEO2_FLUSH			 = 1 << 9,
	STATUS_SET_AUDIO_FLUSH			 = 1 << 10,
	STATUS_SET_AUDIO2_FLUSH			 = 1 << 11,
	STATUS_SET_AUDIO_FORMAT			 = 1 << 12,
	STATUS_SET_AUDIO2_FORMAT		 = 1 << 13,

};
enum {
	PID_CHECK_SCRAMBLE               = 1 << 0,
	PID_SCRAMBLE_CHECKED             = 1 << 1,
	PID_IS_SCRAMBLE                  = 1 << 2,

};

#define HAS_FLAG(flag, bit)    ((flag) & (bit))
#define SET_FLAG(flag, bit)    ((flag) |= (bit))
#define RESET_FLAG(flag, bit)  ((flag) &= (~(bit)))

typedef enum _tagRingBufferType {
	RINGBUFFER_STREAM,
	RINGBUFFER_COMMAND,
	RINGBUFFER_MESSAGE,
	RINGBUFFER_VBI,
	RINGBUFFER_PTS,
	RINGBUFFER_DTVCC,
	RINGBUFFER_STREAM1,
	RINGBUFFER_COMMAND1
} RINGBUFFER_TYPE;

typedef enum _tagAVSyncMode {
	AVSYNC_FORCED_SLAVE,
	AVSYNC_FORCED_MASTER,
	AVSYNC_AUTO_SLAVE,
	AVSYNC_AUTO_MASTER,
	AVSYNC_AUTO_MASTER_NO_SKIP,
	AVSYNC_AUTO_MASTER_CONSTANT_DELAY,   /* after getback mastership, it become force master */
	AVSYNC_EXTREME_LOW_DELAY,
	AVSYNC_AUTO_MASTER_NO_SKIP_TIMEOUT, /* hold on mastership if RCD = -1 and TIMEOUT is not expired */
} AVSYNC_MODE;
typedef enum _tagAutoMasterState {
	AUTOMASTER_NOT_MASTER,
	AUTOMASTER_IS_MASTER
} AUTOMASTER_STATE;

struct _tagMastership {
	unsigned char systemMode;  /* enum AVSYNC_MODE */
	unsigned char videoMode;   /* enum AVSYNC_MODE */
	unsigned char audioMode;   /* enum AVSYNC_MODE */
	unsigned char masterState; /* enum AUTOMASTER_STATE */
};
typedef struct _tagMastership MASTERSHIP;

struct _tagRefClock {
	long long      RCD;
	unsigned long  RCD_ext;
	long long      GPTSTimeout;
	long long      videoSystemPTS;
	long long      audioSystemPTS;
	long long      videoRPTS;
	long long      audioRPTS;
	unsigned long  videoContext;
	unsigned long  audioContext;

	MASTERSHIP     mastership;
	unsigned long  videoFreeRunThreshold;
	unsigned long  audioFreeRunThreshold; /* if APTS < LPTS and LPTS - APTS < audioFreeRunThreshold, then drop. Otherwise, output */
	long long      masterGPTS;   /* this is the value of GPTS (hardware PTS) when master set the reference clock*/
	long           audioFullness;   /* This flag will be turned on when AE's output buffer is almost full.*/
	/* VE which is monitoring this flag will issue auto-pause then.*/
	/* (0: still have enough output space for encoding.   1: AE request pause)*/
	long           audioPauseFlag;  /* This flag will be turned on when VE decides to auto-pause.*/
	/* AE which is monitoring this flag will auto-pause itself then.*/
	/* (0: ignore.  1: AE have to pauseEncode immediately)*/

	long           VO_Underflow; /* (0: VO is working properly; otherwise, VO underflow)*/
	long           AO_Underflow; /* (0: AO is working properly; otherwise, AO underflow)*/
	long           videoEndOfSegment; /* set to the flow EOS.eventID by VO after presenting the EOS sample*/
	long           audioEndOfSegment; /* set to the flow EOS.eventID by AO after presenting the EOS sample*/
	long           distanceVo;        /* distance between video and master in ms*/
	unsigned long  decodedQueueDepth; /* Number of decoded pictures which is ready to be displayed.*/
	unsigned long  decodingPicturePTS;/* PTS of currently decoded picture.*/
	long long      RCD_Audio;       /* set by audio*/
	long long      RCD_Video;       /* set by video*/
	unsigned long  clockMode;
	unsigned long  audioFreeRunThresholdToWait;	/* if APTS > LPTS and APTS - LPTS < audioFreeRunThresholdToWait, then wait. Otherwise, output */
};
typedef struct _tagRefClock  REFCLOCK;

typedef struct _tagRingBufferHeader {
	unsigned long magic;   /*Magic number*/
	unsigned long beginAddr;
	unsigned long size;
	unsigned long bufferID;  /* RINGBUFFER_TYPE, choose a type from RINGBUFFER_TYPE*/

	unsigned long  writePtr;
	unsigned long  numOfReadPtr;
	unsigned long  reserve2;  /*Reserve for Red Zone*/
	unsigned long  reserve3;  /*Reserve for Red Zone*/

	unsigned long readPtr[4];

	long          fileOffset ;
	long          requestedFileOffset ;
	long          fileSize ;

	long          bSeekable ;  /* Can't be sought if data is streamed by HTTP */
	/*
FileOffset:
the offset to the streaming file from the beginning of the file.
It is set by system to tell FW that the current streaming is starting from ¡¥FileOffset¡¦ bytes.
For example, the TIFF file display will set fileOffset to 0 at beginning.

RequestedFileOffset:
the offset to be set by video firmware, to request system to seek to other place.
The initial is -1.When it is not equal to -1, that means FW side is requesting a new seek.

FileSize:
file size. At current implementation, only TIFF decode needs the fileSize,
other decoding does not pay attention to this field

the behavior for TIFF seek:
At the initial value, FileOffset = 0, or at any initial offset (for example, resume from bookmark), RequestedFileOffset=-1. FileSize= file size.
1. If FW needs to perform seek operation, FW set RequestedFileOffset to the value it need to seek.
2. Once system see RequestedOffset is not -1, system reset the ring buffer (FW need to make sure it will not use ring buffer after request the seek), set FileOffset to the new location (the value of RequestedFileOffset), then set RequestedOffset  to -1. From now on, system will stream data from byte FileOffset of the file.
3. FW needs to wait until RequestedOffset== -1, then check the value inside FileOffset. If FileOffset is -1, that means read out of bound.
If system already finish the streaming before FW issue a seek, system will still continue polling.
	 */

} RINGBUFFER_HEADER ;

/* Private Info Identifiers ***************************************************/

typedef enum {

	/* to indicate there is no private info  0 */
	PRIVATEINFO_NONE,

	/* sending PTS information (int64_t)  1*/
	PRIVATEINFO_PTS,

	PRIVATEINFO_VIDEO_NEW_SEG,
	PRIVATEINFO_AUDIO_NEW_SEG,

	/* sending payload information (PAYLOADINFO)  2*/
	PRIVATEINFO_PAYLOAD_INFO,

	/* sending demux the video target information (DEMUXTARGET) 3*/
	PRIVATEINFO_DEMUX_VIDEO_TARGET,

	/* sending demux the audio target information (DEMUXTARGET) 4*/
	PRIVATEINFO_DEMUX_AUDIO_TARGET,

	/* sending demux the SPU target information (DEMUXTARGET) 5 */
	PRIVATEINFO_DEMUX_SPU_TARGET,

	/* sending demux the updated STC offset (int64_t) 6*/
	PRIVATEINFO_DEMUX_STC_OFFSET,

	/* sending SPU button information in DVD-Video compatible format (SPUDVDVBUTTON) 7*/
	PRIVATEINFO_SPU_DVDV_BUTTON,

	/* sending SPU palette in DVD-Video compatible format (SPUDVDVPALETTE) 8*/
	PRIVATEINFO_SPU_DVDV_PALETTE,

	/* to turn on/off SPU (int, 1:ON ; 0:OFF) 9*/
	PRIVATEINFO_SPU_ON_OFF,

	/* to set SPU configuration (coding type, screen size) (SPUCONFIG) 10*/
	PRIVATEINFO_SPU_CONFIG,

	/* to flush SPU alone (no argument) 11*/
	PRIVATEINFO_SPU_FLUSH,

	/* sending audio format information (AUDIOFORMAT) 12*/
	PRIVATEINFO_AUDIO_FORMAT,

	/* sending audio context information for AOUT feedback (int) 13*/
	PRIVATEINFO_AUDIO_CONTEXT,

	/* audio decoding command (AUDIODECODECOMMAND) 14*/
	PRIVATEINFO_AUDIO_DECODE_COMMAND,

	/* to flush audio alone (no argument) 15*/
	PRIVATEINFO_AUDIO_FLUSH,

	/* add by stream : to mark the position that data is discontinuity 16*/
	PRIVATEINFO_AUDIO_DATA_DISCONTINUITY,

	/* sending video end-of-sequence (no argument) 17*/
	PRIVATEINFO_VIDEO_END_OF_SEQUENCE,

	/* sending VOBU information from DVD navigation (VIDEODVDVOBUINFO) 18*/
	PRIVATEINFO_VIDEO_DVD_VOBU_INFO,

	/* sending DCI_CCI information from DVD navigation (VIDEODVDDCICCI) 19*/
	PRIVATEINFO_VIDEO_DVD_DCI_CCI,

	/* sending V_ATR information from DVD navigation (unsigned int) 20*/
	PRIVATEINFO_VIDEO_DVD_V_ATR,

	/* sending video presentation mode (NAV_VIDEO_PRES_MODE, normal/wide/letter-box/pan-scan) 21*/
	PRIVATEINFO_VIDEO_PRESENTATION_MODE,

	/* sending video context information for VOUT feedback (int) 22*/
	PRIVATEINFO_VIDEO_CONTEXT,

	/* video decoding command (VIDEODECODECOMMAND) 23*/
	PRIVATEINFO_VIDEO_DECODE_COMMAND,

	/* video decoding command for output to buffer (VIDEODECODETOBUFFER) 24*/
	PRIVATEINFO_VIDEO_DECODE_TO_BUFFER,

	/* sending background color setting for video mixer (VIDEOMIXERBGCOLOR) 25*/
	PRIVATEINFO_VIDEO_MIXER_BG_COLOR,

	/* setting RPTS of video mixer (int64_t) 26*/
	PRIVATEINFO_VIDEO_MIXER_RPTS,

	/* sending blending command for video mixer (VIDEOMIXERBLEND) 27*/
	PRIVATEINFO_VIDEO_MIXER_BLEND,

	/* sending video format information (VIDEOFORMAT) 28*/
	PRIVATEINFO_VIDEO_FORMAT,

	/* sending DV auxilary information (VIDEODVVAUX)  :29*/
	PRIVATEINFO_VIDEO_DV_VAUX,

	/* sending DV auxilary information (VIDEODVVAUX)  :30*/
	PRIVATEINFO_VIDEO_DV_FF,

	/* sending DV auxilary information (VIDEODVVAUX)  :31*/
	PRIVATEINFO_VIDEO_DV_BUSRESET,

	/* sending DV auxilary information (VIDEODVVAUX)  :32*/
	PRIVATEINFO_VIDEO_DV_ENDSEGMENT,

	/* sending to MPEG4 decoder to indicate it's DIVX or not (VIDEODIVX4) 33*/
	PRIVATEINFO_VIDEO_MPEG4_DIVX4,

	/* setting video decoder error concealment level (int, 0~256) 34*/
	PRIVATEINFO_VIDEO_ERROR_CONCEAL_LEVEL,

	/* sending audio OGG_vorbis information (AUDIOVORBISPKTINFO) 35*/
	PRIVATEINFO_AUDIO_OGGVORBIS_COMMAND,

	/* 36*/
	PRIVATEINFO_SPU_PAGE_ID,

	/* sending audio out to drop sample by PTS 37*/
	PRIVATEINFO_AUDIO_DROPSAMPLE_COMMAND,

	/* sending demux the target information for transport stream (DEMUXTARGET_TS) 38*/
	PRIVATEINFO_DEMUX_TRANSPORT_TARGET,

	/* sending demux the transport stream packet size (int) 39*/
	PRIVATEINFO_DEMUX_TRANSPORT_PACKET_SIZE,

	/* to flush teletext alone (no argument) 40*/
	PRIVATEINFO_TELETEXT_FLUSH,

	/* sending video decoder the RM format info (VIDEORMFORMAT) 41*/
	PRIVATEINFO_VIDEO_RM_FORMAT,

	/* sending video decoder the RM frame info (VIDEORMFRAMEINFO) 42*/
	PRIVATEINFO_VIDEO_RM_FRAME_INFO,

	/* sending video decoder the RM segment info (VIDEORMSEGMENT) 43*/
	PRIVATEINFO_VIDEO_RM_SEGMENT_INFO,

	/* sending audio CGMS info (CGMS_INFO, enum) 44*/
	PRIVATEINFO_AUDIO_CGMS,

	/* to indicate the start of the packet (long) 45*/
	PRIVATEINFO_AUDIO_RM_PACKET_START,

	/* send wma DRC settings (WMAPRODRC) 46 */
	PRIVATEINFO_AUDIO_WMAPRO_DRC,

	/* send numbers of row and column of wma down mix martix (WMAPRODOWNMIXMATRIX) 47 */
	PRIVATEINFO_AUDIO_WMAPRO_DOWNMIX_MATRIX,

	/* send video vc1 info (VIDEOVC1SEQINFO) 48 */
	PRIVATEINFO_VIDEO_VC1_INFO,

	/* send DV Display Information 49 */
	PRIVATEINFO_VIDEO_DV_DISPLAY_CONTROL,

	/* send h264 video usability information 50 */
	PRIVATEINFO_VIDEO_USABILITY_INFO,

	/* send mpeg4 video usability information 51 */
	PRIVATEINFO_VIDEO_MPEG4_USABILITY_INFO,

	/* start delivering data after start pts 52 */
	PRIVATEINFO_DEMUX_START_PTS,

	/*deliver both video and audio context 53 */
	PRIVATEINFO_AV_CONTEXT,

	/*deliver New Video Format 54 */
	PRIVATEINFO_NEW_VIDEO_FORMAT,

	/*set offset to physical address 55 (NAVIOBUFMAPINFO)*/
	PRIVATEINFO_OFFSET_TO_PHYSICAL_ADDR,

	/* send video vc1 info with only 32-integered extraData(VIDEOVC1SEQINFO) 56 */
	PRIVATEINFO_VIDEO_VC1_MINI_INFO,

	/* send 3D subtitle offset sequence id to video decoder (unsigned char) 57*/
	PRIVATEINFO_VIDEO_OFFSET_SEQ_ID,

	/* sending audio out to enable/disable dropping sample by fullness 58 (for skype)*/
	PRIVATEINFO_AUDIO_DROPSAMPLE_BYFULLNESS_COMMAND,

	/* send Initial Vector to TS demux for content decryption (unsigned char[16]) 59 */
	PRIVATEINFO_DEMUX_TRANSPORT_IV,

	/* send keys to TS demux for content decryption 60 (NAVDEMUXKEY)*/
	PRIVATEINFO_DEMUX_TRANSPORT_KEYS,

	/*sync from config_19*/
	/* send client resolution 61 (VIDEOFORMAT) */
	PRIVATEINFO_VIDEO_MJPG_RESOLUTION,

	/*clear screen 62 */
	PRIVATEINFO_VIDEO_FJPEG_CLEAR_SCREEN,

	/* send picture info 63 (VIDEOFJPEGPICINFO)*/
	PRIVATEINFO_VIDEO_FJPEG_PICINFO,
	/*sync from config_19 end*/

	/* send audio out to give up set clock (AO_CLOCK_INFO) 64 (for 66call)*/
	PRIVATEINFO_AUDIO_AO_GIVE_UP_SET_CLOCK,

	/* send divxplus certify flag to video to enable TPT track resolution scale 65*/
	PRIVATEINFO_DIVXPLUS_CERTIFY,

	PRIVATEINFO_VIDEO_BUFFER_RESOLUTION,

	/* ask video decoder not to hack rp. 67*/
	PRIVATEINFO_VIDEO_DTV_SOURCE,

	/* notify PP Aout to create ring buffer for the second in pin. 68*/
	PRIVATEINFO_AUDIO_SUPPLEMENTARY_STREAM,

	/* update TS audio target. (TSDEMUXAUDIOTARGETLIST) 69*/
	PRIVATEINFO_DEMUX_TRANSPORT_AUDIO_TARGET,

	/* set key offset in CW 70 (NAVDEMUXCWOFFSET)*/
	PRIVATEINFO_DEMUX_TRANSPORT_KEYS_OFFSET,

	/* set iv offset in CW 71 (NAVDEMUXCWOFFSET)*/
	PRIVATEINFO_DEMUX_TRANSPORT_IV_OFFSET,


	/* ask PP Aout start to do mixing. 72 (DUALAUDIOMIXING) */
	PRIVATEINFO_AUDIO_START_MIXING,

	/* pass ts descramble info to software descrambler 73 (DESCRAMBLE_CONFIG)*/
	PRIVATEINFO_DEMUX_TS_DESCRAMBLE_INFO,

	/* pass a shared memory to audio for the purpose of status polling 74. (NAVAUDIOSHAREMEMORY) */
	PRIVATEINFO_AUDIO_SHARE_MEMORY,

	/* send video M_Domain resolution 75 (VIDEOMDOMAINRESOLUTION)*/
	PRIVATEINFO_VIDEO_M_DOMAIN_RESOLUTION,

	/* enable/disable audio delay rp. 76 (char) */
	PRIVATEINFO_AUDIO_DELAYRP,

	/* notify video in DPB by pass mode 77 */
	PRIVATEINFO_VIDEO_DPBBYPASS_MODE,

	/* notify MHEG5 ICS start 78 */
	PRIVATEINFO_DEMUX_MHEG5_START_ICS,
	/* Use this infoId to deliver skip info */
	PRIVATEINFO_AUDIO_APE_SKIPBITS,
#ifdef SUPPORT_BADMUX_MPEG
	/*tell demux only deliver video es 80*/
	PRIVATEINFO_DEMUX_ONLY_DELIVER_VIDEO,

	/*tell demux only deliver audio es 81*/
	PRIVATEINFO_DEMUX_ONLY_DELIVER_AUDIO,

	/*tell demux  deliver both audio and video es 82*/
	PRIVATEINFO_DEMUX_DELIVER_BOTH,
#endif

	/*reset avsync mode right away 83*/
	PRIVATEINFO_FORCE_RESET_AVSYNC,

	/*deliver audio codec private to decoder 84*/
	PRIVATEINFO_AUDIO_CODEC_PRIVATE,

	/*deliver video codec private to decoder 85*/
	PRIVATEINFO_VIDEO_CODEC_PRIVATE,

	/*deliver audio vorbis codec private 86*/
	PRIVATEINFO_AUDIO_VORBIS_CODEC_PRIVATE,

	/*deliver rm segment end flag for android 87*/
	PRIVATEINFO_VIDEO_RM_SEGMENT_END,

	/* sending audio ad information (AUDIO_AD_INFO) 88*/
	PRIVATEINFO_AUDIO_AD_INFO,

	PRIVATEINFO_VIDEO_NEW_DECODE_MODE,
} PRIVATEINFO_IDENTIFIER;

/* Nav Buffer Type Identifiers ********************************************/

typedef enum {

	/* to indicate there is nothing in Nav Buffer */
	NAVBUF_NONE,

	/* to send data (bit-stream or private-info), use fields under "data" */
	NAVBUF_DATA,

	/* to ask nav thread to wait, use fields under "wait" */
	NAVBUF_WAIT,

	/* to ask nav thread to wait (fullness pending is kept), use fields under "wait" */
	NAVBUF_SHORT_WAIT,

	/* to ask for streaming stop, use fields under "stop" */
	NAVBUF_STOP,

	/* to flush everything buffered downstream, no arguments */
	NAVBUF_FLUSH,

	/* to begin a new bit-stream segment, use fields under "segment" */
	NAVBUF_NEW_SEGMENT,

	/* to end the current bit-stream segment, use fields under "segment" */
	NAVBUF_END_SEGMENT,

	/* to set new media type for demux, use fields under "media" */
	NAVBUF_NEW_MEDIA_TYPE,

	/* to set new av synchronization mode, use fields under "avsync" */
	NAVBUF_NEW_AVSYNC_MODE,

	/* to adjust clock in system-master av sync mode, use fields under "clock" */
	NAVBUF_ADJUST_CLOCK,

	/* to fire event, use fields under "event" */
	NAVBUF_EVENT,

	/* to set new video type to change new video decoder, use fields under "media" */
	NAVBUF_NEW_VIDEO_TYPE,

	NAVBUF_PREFETCH,

	/*to set new av synchronization mode, use fields under "avsync"
	  and field 'reason' is valid. */
	NAVBUF_NEW_AVSYNC_MODE_EXT,

	/* to ask video pin to stop streaming, use fields under "stop" */
	NAVBUF_VIDEO_STOP,

	/* to set phyAddrOffset */
	NAVBUF_DATA_EXT,

	/* check if fullness meets */
	NAVBUF_LONG_WAIT,

} NAV_BUF_ID;

typedef struct _tagNAVBUF {

	/* identify nav buffer type */
	NAV_BUF_ID type;

	union {

		/* if type == NAVBUF_DATA */
		struct {
			unsigned int pinIndex; /* index (0~) of the pin to deliver data */
			/* NOTE: pinIndex is decided by demux */

			unsigned char *payloadData;      /* bit-stream buffer (NULL means no bit-stream) */
			unsigned int   payloadSize;      /* size of payloadData in bytes (0 means no data) */
			int64_t        pts;              /* presentation time (-1 means N/A) */
			unsigned int   dataOffsetForPTS; /* offset of the bit-stream byte associated with pts */
			unsigned char  rtp_header_marker_bit;
			unsigned short rtp_header_seq_number;
			unsigned int   infoId;           /* private-info id (can be PRIVATEINFO_NONE) */
			unsigned char *infoData;         /* private-info data buffer */
			unsigned int   infoSize;         /* private-info data size in bytes */

			unsigned long startAddress; /* start address where the input block was read */
			/* NOTE: for parser application only, use 0xFFFFFFFF otherwise */

			long           phyAddrOffset; /* physical address - (non) cached address */
		} data;

		/* if type == NAVBUF_WAIT */
		struct {
			long waitTime; /* in milliseconds */
		} wait;

		/* if type == NAVBUF_ADJUST_CLOCK */
		struct {
			int __TO_BE_DEFINED__;
		} clock;

		/* if type == NAVBUF_EVENT */
		struct {
			unsigned int   eventId;   /* EVCode */
			unsigned char *eventData; /* event data buffer */
			unsigned int   eventSize; /* event data size in bytes */
		} event;
	};

} NAVBUF;

/* Structure to Update Status of Input Data for Demux Plugin **************/

typedef struct _tagNAVDEMUXIN {
	unsigned char *pBegin;           /* mark begin of input data for demux plugin */
	unsigned char *pEnd;             /* mark end of input data for demux plugin */
	unsigned char *pCurr;            /* point to the first unused input data byte */
	int64_t        pts;              /* presentation time (-1 means N/A) */
	unsigned int   dataOffsetForPTS; /* offset of the bit-stream byte associated with pts */
	unsigned long  startAddress;     /* start address where the input block was read */

	unsigned int    reservedInfoId;  /**/
	unsigned char  *reservedInfoData;/**/
	unsigned int    reservedInfoSize;

	long            phyAddrOffset;
} NAVDEMUXIN;

/* Structure to Receive Output from Demux Plugin **************************/

typedef struct _tagNAVDEMUXOUT {

	NAVBUF       *pNavBuffers;  /* point to the start of NAVBUF array */
	unsigned int numBuffers;   /* number of NAVBUF items in array */

} NAVDEMUXOUT;

/* audio decoding command for one segment (PRIVATEINFO_AUDIO_DECODE_COMMAND) */
typedef struct _tagAUDIODECODECOMMAND {
	unsigned int mode;   /* refer to struct DEC_MODE in AudioInbandAPI.h */
	int64_t relativePTS; /* decode start relative PTS */
	int64_t duration;    /* PTS duration of decoded segment */
} AUDIODECODECOMMAND;

/* video decoding command for one segment (PRIVATEINFO_VIDEO_DECODE_COMMAND) */
typedef struct _tagVIDEODECODECOMMAND {
	unsigned int mode;   /* refer to struct DECODE_MODE in InbandAPI.h */
	int64_t relativePTS; /* decode start relative PTS */
	int64_t duration;    /* PTS duration of decoded segment */
	long skip_GOP;       /* skipped GOP before decode start */
} VIDEODECODECOMMAND;


/** inband cmd type. I use prefix "VIDEO_DEC_" to label the cmd used in video decoder. */
typedef enum {
	INBAND_CMD_TYPE_PTS = 0,
	INBAND_CMD_TYPE_PTS_SKIP,
	INBAND_CMD_TYPE_NEW_SEG,
	INBAND_CMD_TYPE_SEQ_END,
	INBAND_CMD_TYPE_EOS,
	INBAND_CMD_TYPE_CONTEXT,
	INBAND_CMD_TYPE_DECODE,

	/* Video Decoder In-band Command */
	VIDEO_DEC_INBAND_CMD_TYPE_VOBU,
	VIDEO_DEC_INBAND_CMD_TYPE_DVDVR_DCI_CCI,
	VIDEO_DEC_INBAND_CMD_TYPE_DVDV_VATR,

	/* MSG Type for parse mode */
	VIDEO_DEC_INBAND_CMD_TYPE_SEG_INFO,
	VIDEO_DEC_INBAND_CMD_TYPE_PIC_INFO,

	/* Sub-picture Decoder In-band Command */
	VIDEO_SUBP_INBAND_CMD_TYPE_SET_PALETTE,
	VIDEO_SUBP_INBAND_CMD_TYPE_SET_HIGHLIGHT,

	/* Video Mixer In-band Command */
	VIDEO_MIXER_INBAND_CMD_TYPE_SET_BG_COLOR,
	VIDEO_MIXER_INBAND_CMD_TYPE_SET_MIXER_RPTS,
	VIDEO_MIXER_INBAND_CMD_TYPE_BLEND,

	/* Video Scaler In-band Command */
	VIDEO_SCALER_INBAND_CMD_TYPE_OUTPUT_FMT,

	/*DivX3 resolution In-band Command*/
	VIDEO_DIVX3_INBAND_CMD_TYPE_RESOLUTION,

	/*MPEG4 DivX4 detected In-band command*/
	VIDEO_MPEG4_INBAND_CMD_TYPE_DIVX4,
	/* Audio In-band Commands Start Here */

	/* DV In-band Commands */
	VIDEO_DV_INBAND_CMD_TYPE_VAUX,
	VIDEO_DV_INBAND_CMD_TYPE_FF,                /*fast forward*/

	/* Transport Demux In-band command */
	VIDEO_TRANSPORT_DEMUX_INBAND_CMD_TYPE_PID,
	VIDEO_TRANSPORT_DEMUX_INBAND_CMD_TYPE_PTS_OFFSET,
	VIDEO_TRANSPORT_DEMUX_INBAND_CMD_TYPE_PACKET_SIZE,

	/* Real Video In-band command */
	VIDEO_RV_INBAND_CMD_TYPE_FRAME_INFO,
	VIDEO_RV_INBAND_CMD_TYPE_FORMAT_INFO,
	VIDEO_RV_INBAND_CMD_TYPE_SEGMENT_INFO,

	/*VC1 video In-band command*/
	VIDEO_VC1_INBAND_CMD_TYPE_SEQ_INFO,

	/* general video properties */
	VIDEO_INBAND_CMD_TYPE_VIDEO_USABILITY_INFO,
	VIDEO_INBAND_CMD_TYPE_VIDEO_MPEG4_USABILITY_INFO,

	/*MJPEG resolution In-band Command*/
	VIDEO_MJPEG_INBAND_CMD_TYPE_RESOLUTION,

	/* subtitle offset sequence id for 3D video */
	VIDEO_DEC_INBAND_CMD_TYPE_SUBP_OFFSET_SEQUENCE_ID,

	/* Clear back frame to black color and send it to VO */
	VIDEO_FJPEG_INBAND_CMD_TYPE_CLEAR_SCREEN,

	/* each picture info of MJPEG */
	VIDEO_FJPEG_INBAND_CMD_TYPE_PIC_INFO,

	/*FJPEG resolution In-band Command*/
	VIDEO_FJPEG_INBAND_CMD_TYPE_RESOLUTION,

	/*DIVX In-band Command*/
	VIDEO_INBAND_CMD_TYPE_DIVX_CERTIFY,

	/*M_DOMAIN resolution In-band Command*/
	VIDEO_INBAND_CMD_TYPE_M_DOMAIN_RESOLUTION,

	/* DTV source In-band Command */
	VIDEO_INBAND_CMD_TYPE_SOURCE_DTV,

	/* Din source copy mode In-band Command */
	VIDEO_DIN_INBAND_CMD_TYPE_COPY_MODE,

	/* Video Decoder AU In-band command */
	VIDEO_DEC_INBAND_CMD_TYPE_AU,

	/* Video Decoder parse frame In-band command */
	VIDEO_DEC_INBAND_CMD_TYPE_PARSE_FRAME_IN,
	VIDEO_DEC_INBAND_CMD_TYPE_PARSE_FRAME_OUT,

	/* VIDEO_DECODE_MODE */
	VIDEO_DEC_INBAND_CMD_TYPE_NEW_DECODE_MODE,
} INBAND_CMD_TYPE ;

typedef struct {
	INBAND_CMD_TYPE type ;
	unsigned int size ;
} INBAND_CMD_PKT_HEADER ;

typedef enum {
	NORMAL_DECODE = 0,
	I_ONLY_DECODE,
	FASTFR_DECODE,
	RESERVED1,
	TS_NORMAL_DECODE,
	TS_I_ONLY_DECODE,
	TS_FASTFR_DECODE,
	RESERVED2,
	BITSTREAM_PARSING,
	TRANSCODE_PARSING,
	NORMAL_I_ONLY_DECODE
} DECODE_MODE ;

typedef struct {
	INBAND_CMD_PKT_HEADER header ;
	unsigned int RelativePTSH ;
	unsigned int RelativePTSL ;
	unsigned int PTSDurationH ;
	unsigned int PTSDurationL ;
	unsigned int skip_GOP ;
	DECODE_MODE  mode ;

} DECODE ;

typedef struct {
	INBAND_CMD_PKT_HEADER header ;
	unsigned int wPtr ;
} NEW_SEG ;
/**
  \brief
  \param wPtr
  An coresponding address to bit stream buffer.
 */
typedef struct {
	INBAND_CMD_PKT_HEADER header ;
	unsigned int wPtr ;
} SEQ_END ;


#define VRPC_PTS2_FLAG_IDR_FRAME              (0x00010000)
/**
 *  \brief Mark a PTS on an address.
 *  \param:
 */
typedef struct {
	INBAND_CMD_PKT_HEADER header ;
	unsigned int wPtr ;//
	unsigned int PTSH ;//PTS
	unsigned int PTSL ;//PTS
} PTS_INFO ; //This is for DEMUX

/**
  \brief Mark a EOS on an address.
  This is the last inband command of a segment and is mandatary.
  \param wPtr
 */
typedef struct {
	INBAND_CMD_PKT_HEADER header ;
	unsigned int wPtr ;
	unsigned int eventID ;
} EOS ;

typedef struct {
	INBAND_CMD_PKT_HEADER header ;
	unsigned int wPtr ;
} INBAND_SOURCE_DTV ;

typedef enum {
	/* Audio Decoder In-band Command */
	AUDIO_DEC_INBAND_CMD_TYPE_PTS = 0,
	AUDIO_DEC_INBAND_CMD_TYPE_NEW_SEG = 1,    /* let begin_AGC_gain = 1 */
	AUDIO_DEC_INBAMD_CMD_TYPE_NEW_FORMAT = 2,
	AUDIO_DEC_INBAND_CMD_TYPE_EOS = 3,      /* Can not be passed, sent back to system */
	AUDIO_DEC_INBAND_CMD_TYPE_CONTEXT = 4,    /* write debug information, need a RPC_ToSystem command *//* Can not be passed, sent back to system */
	AUDIO_DEC_INBAND_CMD_TYPE_DECODE = 5,    /* Information for each decoder is inclueded */
	AUDIO_DEC_INABND_CMD_TYPE_PTS_SKIP = 6,
	AUDIO_DEC_INBAND_CMD_TYPE_PRIVATE_INFO = 7,
	AUDIO_DEC_INBAND_CMD_TYPE_VORBIS_PACKETINFO = 8,    /* Information about vorbis packets */

	AUDIO_DEC_INBAND_CMD_TYPE_BS_DISCONTINUITY = 9,
	AUDIO_DEC_INBAND_CMD_TYPE_RESYNC = 10,
	AUDIO_DEC_INBAND_CMD_TYPE_CGMS_INFO = 11,
	AUDIO_DEC_INBAND_CMD_TYPE_RALSD_INFO = 12,
	AUDIO_DEC_INBAND_CMD_TYPE_WMAPRO_DRC = 13,
	AUDIO_DEC_INBAND_CMD_TYPE_WMAPRO_DWNMIX_MTRX = 14,

	AUDIO_DEC_INBAND_CMD_TYPE_EMPHASIS = 15,    /* for lpcm emphasis info*/
	AUDIO_DEC_INBAND_CMD_TYPE_SHARED_MEM = 16, /* physical address for decoder agent update infomation to system */
	AUDIO_DEC_INBAND_CMD_TYPE_APE_SKIP_BIT = 17,
	AUDIO_DEC_INBAND_CMD_TYPE_AD_DESCRIPTOR = 18,
	/* Audio AO Mixer In-band Command */
	AUDIO_AO_MIXER_INBAND_CMD_TYPE_SET_MIXER_RPTS = 64,
	AUDIO_AO_MIXER_INBAND_CMD_TYPE_SET_BLEND,

	/* Audio DV Mixer In-band Command */
	AUDIO_DV_MIXER_INBAND_CMD_TYPE_SET_BLEND

} AUDIO_INBAND_CMD_TYPE ;

typedef struct {
	AUDIO_INBAND_CMD_TYPE   type ;
	long            size ;
} AUDIO_INBAND_CMD_PKT_HEADER;


typedef struct
{
  	AUDIO_INBAND_CMD_PKT_HEADER header;
	unsigned long 				wPtr ;
	unsigned long				PTSH;
	unsigned long				PTSL;
	unsigned long 				AD_fade_byte;
	unsigned long				AD_pan_byte;
	long         				gain_byte_center;
	long          				gain_byte_front;
	long         				gain_byte_surround;
} AUDIO_DEC_AD_DESCRIPTOR ;

typedef struct {
	AUDIO_INBAND_CMD_PKT_HEADER header ;
	unsigned long wPtr ;
}   AUDIO_DEC_NEW_SEG ;

enum DEC_MODE {
	AUDIO_DECODE,
	AUDIO_PARSING    /* purpose: (1) check bit stream is valid or not. (2) for SPDIF pass through.*/
};

typedef struct {
	AUDIO_INBAND_CMD_PKT_HEADER header;
	unsigned long         wPtr;
	unsigned long        RelativePTSH;
	unsigned long        RelativePTSL;
	unsigned long        PTSDurationH;
	unsigned long        PTSDurationL;
	enum       DEC_MODE  decodeMode;

}   AUDIO_DEC_DECODE ;

typedef enum {
	AUDIO_UNKNOWN_TYPE                        = 0,
	AUDIO_MPEG_DECODER_TYPE                   = 1,
	AUDIO_AC3_DECODER_TYPE                    = 2,
	AUDIO_LPCM_DECODER_TYPE                   = 3,
	AUDIO_DTS_DECODER_TYPE                    = 4,
	AUDIO_WMA_DECODER_TYPE                    = 5,
	AUDIO_AAC_DECODER_TYPE                    = 6,
	AUDIO_VORBIS_DECODER_TYPE                 = 7,
	AUDIO_DV_DECODER_TYPE                     = 8,
	AUDIO_MLP_DECODER_TYPE                    = 9,
	AUDIO_DDP_DECODER_TYPE                    = 10,
	AUDIO_DTS_HD_DECODER_TYPE                 = 11,
	AUDIO_WMA_PRO_DECODER_TYPE                = 12,
	AUDIO_MP4AAC_DECODER_TYPE                 = 13,
	AUDIO_MP3_PRO_DECODER_TYPE                = 14,
	AUDIO_MP4HEAAC_DECODER_TYPE               = 15,
	AUDIO_RAW_AAC_DECODER_TYPE                = 16,
	AUDIO_RA1_DECODER_TYPE                    = 17,
	AUDIO_RA2_DECODER_TYPE                    = 18,
	AUDIO_ATRAC3_DECODER_TYPE                 = 19,
	AUDIO_COOK_DECODER_TYPE                   = 20,
	AUDIO_LSD_DECODER_TYPE                    = 21,
	AUDIO_ADPCM_DECODER_TYPE                  = 22,
	AUDIO_FLAC_DECODER_TYPE                   = 23,
	AUDIO_ULAW_DECODER_TYPE                   = 24,
	AUDIO_ALAW_DECODER_TYPE                   = 25,
	AUDIO_ALAC_DECODER_TYPE                   = 26,
	AUDIO_DTS_HIGH_RESOLUTION_DECODER_TYPE    = 27,
	AUDIO_DTS_LBR_DECODER_TYPE                = 28,
	AUDIO_DTS_MASTER_DEMUX_AUDIO_DECODER_TYPE = 29,
	AUDIO_AMRNB_DECODER_TYPE                  = 30,
	AUDIO_MIDI_DECODER_TYPE                   = 31,
	AUDIO_APE_DECODER_TYPE                    = 32,
	AUDIO_AVS_DECODER_TYPE                    = 33,
	AUDIO_NELLYMOSER_DECODER_TYPE             = 34,
	AUDIO_WMA_LOSSLESS_DECODER_TYPE           = 35,
	AUDIO_UNCERTAIN_DECODER_TYPE              = 36,
	AUDIO_UNCERTAIN_HDMV_DECODER_TYPE         = 37,
	AUDIO_ILBC_DECODER_TYPE                   = 38,
	AUDIO_SILK_DECODER_TYPE                   = 39,
	AUDIO_AMRWB_DECODER_TYPE                  = 40,
	AUDIO_G729_DECODER_TYPE                   = 41,
	AUDIO_DRA_DECODER_TYPE                    = 42,
	AUDIO_OPUS_DECODER_TYPE                   = 43,

} AUDIO_DEC_TYPE ;

typedef  struct {
	AUDIO_INBAND_CMD_PKT_HEADER header;
	unsigned long         wPtr;
	AUDIO_DEC_TYPE        audioType;        /* AUDIO_DEC_TYPE*/
	long                  privateInfo[8];   /* note: privateinfo[6] is used for choosing decoder sync pts method*/
}  AUDIO_DEC_NEW_FORMAT ;

typedef struct {
	INBAND_CMD_PKT_HEADER header ;
	unsigned int wPtr ;
	DECODE_MODE  mode ;

} VIDEO_DECODE_MODE ;


#endif
