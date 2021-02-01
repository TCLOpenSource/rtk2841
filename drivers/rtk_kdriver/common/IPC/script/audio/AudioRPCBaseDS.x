
.insert <rpc_common.h>


enum AUDIO_DEC_TYPE{
	AUDIO_UNKNOWN_TYPE = 0,
	AUDIO_MPEG_DECODER_TYPE = 1,
	AUDIO_AC3_DECODER_TYPE = 2,
	AUDIO_LPCM_DECODER_TYPE = 3,
	AUDIO_DTS_DECODER_TYPE = 4,
	AUDIO_WMA_DECODER_TYPE = 5,
	AUDIO_AAC_DECODER_TYPE = 6,
	AUDIO_VORBIS_DECODER_TYPE = 7,
	AUDIO_DV_DECODER_TYPE = 8,
	AUDIO_MLP_DECODER_TYPE = 9,
	AUDIO_DDP_DECODER_TYPE = 10,
	AUDIO_DTS_HD_DECODER_TYPE = 11,
	AUDIO_WMA_PRO_DECODER_TYPE = 12,
	AUDIO_MP4AAC_DECODER_TYPE = 13,
	AUDIO_MP3_PRO_DECODER_TYPE = 14,
	AUDIO_MP4HEAAC_DECODER_TYPE = 15,
	AUDIO_RAW_AAC_DECODER_TYPE = 16,
	AUDIO_RA1_DECODER_TYPE = 17,
	AUDIO_RA2_DECODER_TYPE = 18,
	AUDIO_ATRAC3_DECODER_TYPE = 19,
	AUDIO_COOK_DECODER_TYPE = 20,
	AUDIO_LSD_DECODER_TYPE = 21,
	AUDIO_ADPCM_DECODER_TYPE = 22,
	AUDIO_FLAC_DECODER_TYPE = 23,
	AUDIO_ULAW_DECODER_TYPE = 24,
	AUDIO_ALAW_DECODER_TYPE = 25,
	AUDIO_ALAC_DECODER_TYPE = 26,
	AUDIO_DTS_HIGH_RESOLUTION_DECODER_TYPE = 27,
	AUDIO_DTS_LBR_DECODER_TYPE = 28,
	AUDIO_DTS_MASTER_AUDIO_DECODER_TYPE = 29,
	AUDIO_AMRNB_DECODER_TYPE = 30,
	AUDIO_MIDI_DECODER_TYPE = 31,
	AUDIO_APE_DECODER_TYPE = 32,
	AUDIO_AVS_DECODER_TYPE = 33,
	AUDIO_NELLYMOSER_DECODER_TYPE = 34,
	AUDIO_WMA_LOSSLESS_DECODER_TYPE = 35,
	AUDIO_UNCERTAIN_DECODER_TYPE = 36,
	AUDIO_UNCERTAIN_HDMV_DECODER_TYPE = 37,     /* send which type msg back to system */
	AUDIO_ILBC_DECODER_TYPE = 38,
	AUDIO_SILK_DECODER_TYPE = 39,
	AUDIO_AMRWB_DECODER_TYPE = 40,
	AUDIO_G729_DECODER_TYPE = 41,
	AUDIO_DRA_DECODER_TYPE = 42,
	AUDIO_OPUS_DECODER_TYPE = 43,
	AUDIO_AMRWB_PLUS_DECODER_TYPE = 44,
	AUDIO_AC4_DECODER_TYPE = 45,
	AUDIO_MPEGH_DECODER_TYPE = 46
};

enum AUDIO_CHANNEL_OUT_INDEX{
    AUDIO_NULL_CHANNEL_INDEX = 0,

	AUDIO_LEFT_FRONT_INDEX = 1,            /* L                                        */
	AUDIO_RIGHT_FRONT_INDEX = 2,           /* R                                        */
	AUDIO_CENTER_FRONT_INDEX = 5,          /* C                                        */
	AUDIO_LFE_INDEX = 6,                   /* LFE                                      */
	AUDIO_LEFT_SURROUND_REAR_INDEX = 3,    /* Ls or Lsr                                */
	AUDIO_RIGHT_SURROUND_REAR_INDEX = 4,   /* Rs or Rsr                                */
	AUDIO_LEFT_OUTSIDE_FRONT_INDEX = 7,    /* ENUM_AUDIO_LEFT_SURROUND_SIDE_INDEX,  Lss*/
	AUDIO_RIGHT_OUTSIDE_FRONT_INDEX = 8,   /* ENUM_AUDIO_RIGHT_SURROUND_SIDE_INDEX, Rss*/
	AUDIO_SPDIF_LEFT_CHANNEL_INDEX = 9,
	AUDIO_SPDIF_RIGHT_CHANNEL_INDEX = 10,

	AUDIO_SURROUND_INDEX = 11,
	AUDIO_CENTER_SURROUND_REAR_INDEX = 12,
	AUDIO_OverHead_INDEX = 13,

	AUDIO_LEFT_SURROUND_INDEX = 14,
	AUDIO_RIGHT_SURROUND_INDEX = 15,
	AUDIO_LEFT_FRONT_HIGH_INDEX = 16,
	AUDIO_RIGHT_FRONT_HIGH_INDEX = 17,
	AUDIO_LEFT_INNER_FRONT_INDEX = 18,
	AUDIO_RIGHT_INNER_FRONT_INDEX = 19,
	AUDIO_LEFT_REAR_INDEX = 20,
	AUDIO_RIGHT_REAR_INDEX = 21,
	AUDIO_LEFT_SURROUND_DIRECT_INDEX = 22,
	AUDIO_RIGHT_SURROUND_DIRECT_INDEX = 23,
	AUDIO_CENTER_FRONT_HIGH_INDEX = 24,
	AUDIO_LFE2_INDEX = 25,

	AUDIO_SPDIF_NON_PCM_TYPE = 256,
	AUDIO_ENABLE_DOWNMIX = 257
};


enum AUDIO_MODULE_TYPE {
/*	AUDIO_MPEG_DECODER = 0, */
/*	AUDIO_AC3_DECODER = 1, */
/*	AUDIO_LPCM_DECODER = 2, */
/*	AUDIO_DTS_DVD_DECODER = 3, */	/*modify AUDIO_DTS_DECODER -> AUDIO_DTS_DVD_DECODER*/
/*	AUDIO_WMA_DECODER = 4, */
/*	AUDIO_AAC_DECODER = 5, */
/*	AUDIO_OGG_DECODER = 6, */
	AUDIO_OUT = 7,
	AUDIO_IN = 8,
	AUDIO_ENCODER = 9,
	AUDIO_MPEG_ENCODER = 10,
/*	AUDIO_FILE_OUT = 11, */
/*	AUDIO_ALSA_OUT = 12, */
/*	AUDIO_DV_DECODER = 13, */
	AUDIO_PSEUDO_OUT = 14,
	AUDIO_PP_OUT = 15,
	AUDIO_DECODER = 16,
	AUDIO_UNKNOWN = 17,
/*	AUDIO_DTS_CD_DECODER = 18, */  	/*added*/
	AUDIO_LPCM_ENCODER = 19,         /*added*/
/*	AUDIO_WAVE_DECODER = 20, */
	AUDIO_AAC_ENCODER = 21,
	AUDIO_MP3_ENCODER = 22,
	AUDIO_RV_PARSER = 23,
	AUDIO_AC3_ENCODER = 24,
	AUDIO_VIENNA_OUT = 25,
	AUDIO_DTS_ENCODER = 26,
	AUDIO_VP6_PARSER = 27,
	AUDIO_IN_DEVICE = 28,
    	AUDIO_ILBC_ENCODER = 29,
	AUDIO_KARAOKE_MIXER = 30, /* only for Karaoke Mixer used*/
	AUDIO_VP8_PARSER = 31,
	AUDIO_SILK_ENCODER = 32,
	AUDIO_G729_ENCODER = 33,
	AUDIO_PCMU_ENCODER = 34,
	AUDIO_PCMA_ENCODER = 35,
	AUDIO_VPMEM_CONV = 36
};

enum AUDIO_IO_PIN {
	BASE_BS_IN = 0,
	EXT_BS_IN = 1,
	PCM_IN_RTK = 2,
	BASE_BS_OUT = 3,
	EXT_BS_OUT = 4,
	PCM_OUT_RTK = 5,
	SPDIF_IN = 6,
	SPDIF_OUT = 7,
	NON_PCM_OUT = 8,
	INBAND_QUEUE = 9,
	MESSAGE_QUEUE = 10,
	MIC_IN = 11,
	SOUND_EVENT_IN = 12,
	PCM_OUT1 = 13,
	PCM_OUT2 = 14,
	FLASH_AUDIO_PIN_1 = 15,
	FLASH_AUDIO_PIN_2 = 16,
	FLASH_AUDIO_PIN_3 = 17,
	FLASH_AUDIO_PIN_4 = 18,
	FLASH_AUDIO_PIN_5 = 19,
	FLASH_AUDIO_PIN_6 = 20,
	FLASH_AUDIO_PIN_7 = 21,
	FLASH_AUDIO_PIN_8 = 22,
	PCM_OUT3 = 23,
	DWNSTRM_INBAND_QUEUE = 200 /*vienna use*/
};

enum ENUM_AUDIO_BILINGUAL_TYPE
{
	ENUM_AUDIO_STEREO,
	ENUM_AUDIO_MAIN_BILINGUAL,
	ENUM_AUDIO_SUB_BILINGUAL
};

enum ENUM_AUDIO_NIGHTMODE_CFG
{
    ENUM_AUDIO_NIGHTMODE_OFF,
    ENUM_AUDIO_NIGHTMODE_ON
};

struct AUDIO_RPC_NIGHTMODE {
	long instanceID;
	long cfg;
};

struct AUDIO_RPC_PP_AGC {
	long instanceID;
	long enable;
    long gain_max;
    long gain_min;
    long gain_prev;
    long gain_rise;
    long gain_drop;
    long gain_abrupt_drop;
    long judge_sample;
};

enum ENUM_AUDIO_AGC_TYPE
{
    ENUM_AUDIO_AGC_TYPE_BYPASS=0,
    ENUM_AUDIO_AGC_TYPE_MANUAL=1,
    ENUM_AUDIO_AGC_TYPE_DEFAULT=2
};


enum ENUM_AUDIO_DAC_SWITCH_CFG
{
    ENUM_AUDIO_DAC_SWITCH_OFF,
    ENUM_AUDIO_DAC_SWITCH_ON
};

enum ENUM_AUDIO_TRUEHD_LOSSLESSMODE_CFG
{
    ENUM_AUDIO_TRUEHD_LOSSLESSMODE_OFF,
    ENUM_AUDIO_TRUEHD_LOSSLESSMODE_ON
};

struct AUDIO_RPC_TRUEHD_LOSSLESSMODE {
	long cfg;
};

enum ENUM_AUDIO_DELAY_DAC_SWITCH_CFG
{
    ENUM_AUDIO_DELAY_DAC_SWITCH_OFF,
    ENUM_AUDIO_DELAY_DAC_SWITCH_ON
};

/* TV version */
enum ENUM_AUDIO_IPT_SRC
{
	AUDIO_IPT_SRC_ATV          = 0x0,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_BBADC        = 0x1,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_SPDIF        = 0x2,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_BIT_3        = 0x3,	/* undefined input soucre                      */
	AUDIO_IPT_SRC_I2S_PRI_CH12 = 0x4,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_I2S_PRI_CH34 = 0x5,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_I2S_PRI_CH56 = 0x6,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_I2S_PRI_CH78 = 0x7,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_I2S_SEC_CH12 = 0x8,	/* real input, mapping to register bit-setting */
	AUDIO_IPT_SRC_ATV_NICAM    = 0x9,
	AUDIO_IPT_SRC_ATV_HDEV     = 0xa,
	AUDIO_IPT_SRC_DTV          = 0x10,	/* pseudo input, only affect clk setting       */
	AUDIO_IPT_SRC_FILE         = 0x20,	/* pseudo input, only affect clk setting       */
	AUDIO_IPT_SRC_UNKNOWN      = 0xFF
};

/* TV version */
enum ENUM_AUDIO_BBADC_SRC
{
	/* identical to the order in (AUDIO_IO_ANALOG_FRONTEND_MUTE_VADDR) register's field */
	/* bit-mapping setting                                                              */
	AUDIO_BBADC_SRC_MUTE_ALL = 0x7F,
	AUDIO_BBADC_SRC_AIN1     = 0x01,
	AUDIO_BBADC_SRC_AIN2     = 0x02,
	AUDIO_BBADC_SRC_AIN3     = 0x04,
	AUDIO_BBADC_SRC_AIO1     = 0x08,
	AUDIO_BBADC_SRC_UNKNOWN  = 0x41
};

/* TV version */
enum ENUM_AUDIO_SPDIFI_SRC
{
	AUDIO_SPDIFI_SRC_IN,
	AUDIO_SPDIFI_SRC_HDMI,
	AUDIO_SPDIFI_SRC_LOOPBACK,
	AUDIO_SPDIFI_SRC_DISABLE
};

/* TV version */
enum ENUM_AUDIO_I2SI_SRC
{
	AUDIO_I2SI_SRC_IN,
	AUDIO_I2SI_SRC_HDMI,
	AUDIO_I2SI_SRC_LOOPBACK,
	AUDIO_I2SI_SRC_DISABLE
};

/* TV version */
enum ENUM_AUDIO_I2SI_ID
{
	AUDIO_I2SI_ID_PRIMARY,
	AUDIO_I2SI_ID_SECOND
};

/* TV version */
enum ENUM_AUDIO_I2SI_MODE
{
	AUDIO_I2SI_MODE_SLAVE,
	AUDIO_I2SI_MODE_MASTER,
	AUDIO_I2SI_MODE_NOCARE
};

/* TV version */
enum ENUM_AUDIO_I2SI_SYNC
{
	AUDIO_I2SI_SYNC_NORMAL,
	AUDIO_I2SI_SYNC_LEFT,
	AUDIO_I2SI_SYNC_RIGHT
};

/* TV version */
enum ENUM_AUDIO_BBADC_CLK
{
	/* identical to the order in register's field */
	AUDIO_BBADC_CLK_24M,
	AUDIO_BBADC_CLK_49M,
	AUDIO_BBADC_CLK_98M
};

/* TV version */
struct AUDIO_IPT_SRC
{
	int	focus[4];		/* ENUM_AUDIO_IPT_SRC */
	int	mux_in;			/* ENUM_AUDIO_BBADC_SRC/ENUM_AUDIO_SPDIFI_SRC/ENUM_AUDIO_I2SI_SRC */
};

struct AUDIO_RPC_DEC_BITSTREAM_BUFFER
{
  long    bsBase;
  long    bsSize;
} ;


struct	AUDIO_RPC_FORMAT_INFO {
	u_char result;		/* 1 = OK, 0 = FAIL*/
	enum AUDIO_DEC_TYPE Type;	/*enum AUDIO_DEC_TYPE in IPC\include\AudioInbandAPI.h */
	long	VariableBitRateFlag;	/* 1 = Variable bit rate, 0 = constant bit rate */
	long	BitRate;
	u_char copyright;

	long rsv_data[4];
};


struct AUDIO_PCM_FORMAT {
	int chnum;
	int samplebit;
	int samplerate;
	u_int dynamicRange;
	u_char emphasis;
	u_char mute;
};

struct AUDIO_EXT_BS {
	int		exist;
};

struct AUDIO_DEC_CFG {
    long scalehi;
    long scalelo;
    long scalehi_2ch;
    long scalelo_2ch;
	u_short mode;
	u_short LFEMode;
	u_short dualmono;
	u_short comprMode;
	u_short comprMode_2ch;
	u_short stereoMode;
	u_short sub_dec_mode;
	u_short substream_id;
	u_short dialnorm;
	u_short prog_ref_level;
};

enum ENCODE_MODE
{
 	DUALCHANNEL_1_AND_1 = 0,
 	MONO = 1,
    STEREO = 2,
    JOINT_STERO = 3
};

struct AUDIO_ENC_CFG {
	int inputmode;
	int outputmode;
	int DRC1;
	int DRC2;
	int datarate;
	int samprate;
	int LorR;
};


struct AUDIO_RPC_INSTANCE {
	long instanceID;
	long type;
};

struct AUDIO_RPC_HASH {
	long rand_value;
};
struct AUDIO_FRAME_BOUNDARY {
	long frameBeginPtr;
	long writeBeginPtr;
	u_long writeSize;
};

struct AUDIO_RPC_SEND_LONG {
	long instanceID;
	long data;
};

struct AUDIO_RPC_SENDPIN_LONG {
	long instanceID;
	long pinID;
	long data;
};

struct AUDIO_RPC_SEEK {
	long instanceID;
	long speed;
	long skip;
};

struct AUDIO_RPC_PRIVATEINFO {
	long instanceID;
	long pData;
	long length;
};

struct AUDIO_RPC_RINGBUFFER {
	long instanceID;
	long in_beginPAddrList[8];
	long in_listSize;
	long in_bufSize;
	long in_pinID;
	long extin_beginPAddrList[8];
	long extin_listSize;
	long extin_bufSize;
	long extin_pinID;
	long out_beginPAddrList[8];
	long out_listSize;
	long out_bufSize;
	long out_pinID;
};

struct AUDIO_RPC_IOBUFFER {
    long instanceID;
    long in_ptrList[8];
    long in_bufSize;
    long in_listSize;
    long out_ptrList[8];
    long out_bufSize;
    long out_listSize;
};

struct AUDIO_RPC_BUFFER {
    long instanceID;
    long ptrList[8];
    long bufSize;
    long listSize;
};

enum ENUM_SYSTEM_PROCESS_TYPE{
    ENUM_ARM_SRC = 0,
    ENUM_ARM_DUMP = 1,
    ENUM_ARM_AC3_DEC = 2,
    ENUM_ARM_AC4_DEC = 3,
    ENUM_ARM_MPEGH_DEC = 4,
    ENUM_ARM_DDP_ENC = 5
};
struct SYSTEM_PROCESS_INFO {
    ENUM_SYSTEM_PROCESS_TYPE type;
    long instanceID;
    long data[16];
};

struct SYSTEM_PROCESS_RES {
    long instanceID;
    long data;
    long packetBufHeader[2];
};

struct AUDIO_RPC_WRITEPACK {
	long instanceID;
	long pinID;
	long writePtr[8];
	int listSize;
	int writeSize;
};

struct AUDIO_RPC_READPACK {
	long instanceID;
	long pinID;
	long readPtr[8];
	int listSize;
	int readSize;
};

struct AUDIO_RPC_SENDIO {
	long instanceID;
	int pinID;
};

struct AUDIO_RPC_SWITCHAGENT {
	long instanceID1;
	long instanceID2;
	AUDIO_PCM_FORMAT pcmFormat;
};

struct AUDIO_RPC_PCMFORMAT {
	long instanceID;
	long pinID;
	AUDIO_PCM_FORMAT pcmFormat;
};

struct AUDIO_RPC_FRAME_BOUNDARY {
	long instanceID;
	AUDIO_FRAME_BOUNDARY frameBoundary;
};

struct AUDIO_RPC_DECCFG {
	long instanceID;
	AUDIO_DEC_CFG cfg;
};

struct AUDIO_RPC_EXTBS_EXIST {
	long instanceID;
	int extbsExist;
};

struct AUDIO_RPC_CONNECTION {
	long srcInstanceID;
	long srcPinID;
	long desInstanceID;
	long desPinID;
	long mediaType;
};

struct AUDIO_RPC_REFCLOCK
{
	long	       		instanceID;
	long	       		pRefClockID;
	long	        	pRefClock;
};


struct AUDIO_RPC_PTS_INFO {
	long		instanceID;
	long		pinID;
	int64_t		pts;
	long    	pWritePointer;
	long		length;
};


struct AUDIO_RPC_RINGBUFFER_HEADER
{
  long	       		instanceID;
  long	       		pinID;
  long	        	pRingBufferHeaderList[8];
  long	        	readIdx;
  long				listSize;
};



struct AUDIO_RPC_FOCUS
{
  long	       		instanceID;
  long	       		focusID;
};


struct AUDIO_RPC_SUBCHANNEL
{
  long	       		instanceID;
  long	       		SubChannelPinID;
};

/* TV version */
enum ENUM_AUDIO_CHANNEL_IDX {
	AUDIO_CH_IDX_0 = 0x01,
	AUDIO_CH_IDX_1 = 0x02,
	AUDIO_CH_IDX_2 = 0x04,
	AUDIO_CH_IDX_3 = 0x08,
	AUDIO_CH_IDX_4 = 0x10,
	AUDIO_CH_IDX_5 = 0x20,
	AUDIO_CH_IDX_6 = 0x40,
	AUDIO_CH_IDX_7 = 0x80
};

struct AUDIO_RPC_AO_FOCUS
{
  long	       		instanceID;
  long	       		focusID;
  long              PTS_length;
};

enum ENUM_AUDIO_CHANNEL_IN {
	IN_NULL_CHANNEL = 0,
	ADC0_LEFT_CHANNEL_EN = 1,
	ADC0_RIGHT_CHANNEL_EN = 2,
	ADC1_LEFT_CHANNEL_EN = 4,
	ADC1_Right_CHANNEL_EN = 8,
	SPDIF_LEFT_CHANNEL_EN = 16,
	SPDIF_RIGHT_CHANNEL_EN = 32,
        ADC2_LEFT_CHANNEL_EN = 64,
        ADC2_RIGHT_CHANNEL_EN = 128
} ;

enum ENUM_AUDIO_CHANNEL_OUT
{
	OUT_NULL_CHANNEL = 0,
	LEFT_CENTER_FRONT_CHANNEL_EN = 1,
	RIGHT_CENTER_FRONT_CHANNEL_EN = 2,
	CENTER_FRONT_CHANNEL_EN = 4,
	LFE_CHANNEL_EN = 8,
	LEFT_SURROUND_CHANNEL_EN = 16,
	RIGHT_SURROUND_CHANNEL_EN = 32,
	LEFT_OUTSIDE_FRONT_CHANNEL_EN = 64,
	RIGHT_OUTSIDE_FRONT_CHANNEL_EN = 128,
	NON_PCM_OUT_EN = 256,
	ENABLE_DOWNMIX = 257,
	NON_PCM_OUT_EN_AUTO = 258,
	NON_PCM_OUT_EN_AUTO_AAC = 259,
	NON_PCM_OUT_EN_AUTO_DDP = 260,
	NON_PCM_OUT_EN_AUTO_DDP_AAC = 261,
	NON_PCM_OUT_EN_HALF_AUTO = 262,
	NON_PCM_OUT_EN_HALF_AUTO_AAC = 263,
	NON_PCM_OUT_EN_HALF_AUTO_DDP = 264,
	NON_PCM_OUT_EN_HALF_AUTO_DDP_AAC = 265
} ;

struct AUDIO_GENERAL_CONFIG {
	char	interface_en;
	char	channel_in;
	char	count_down_rec_en;
	int	count_down_rec_cyc;
} ;

struct AUDIO_SAMPLE_INFO {
	int	sampling_rate;
	int	PCM_bitnum;
} ;

/* TV version */
struct AUDIO_BBADC_CONFIG {
	AUDIO_GENERAL_CONFIG	audioGeneralConfig;
	AUDIO_SAMPLE_INFO		sampleInfo;
	int						clk_sel;
	int						src_sel;
} ;

/* TV version */
struct AUDIO_I2SI_CONFIG {
	AUDIO_GENERAL_CONFIG	audioGeneralConfig;
	char					id;
	char					src_sel;
	char					sync_type;
	char					mode_sel;
} ;

/* TV version */
struct AUDIO_SPDIFI_CONFIG {
	AUDIO_GENERAL_CONFIG	audioGeneralConfig;
	char					src_sel;
	char					req_after_lock;
} ;

/* TV version */
struct AUDIO_RPC_IPT_SRC{
	long instanceID;
	int focus_in[4];	/* SetPathSrc */
	int mux_in;			/* SetSPDIFIpt/SetI2SIpt/SetBBADCSrc(opt. plus SetMonoIn) */
};

/* TV version */
struct AUDIO_RPC_SET_ATV_CLOCK{
	long instanceID;
	int atv_type;	/* ATV type*/
};

/* TV version */
struct AUDIO_RPC_INOUT_CH_SELECT{
	long instanceID;
	int valid_setting;
	int ch_select_pb;
  int ch_select_ts;
};

/* TV version */
struct AUDIO_RPC_SET_FS_CLOCKSRC{
	long instanceID;
	char   set_fs;
	int	set_clock_src;
	int	set_i2s_mode;
};

/* TV version */
struct AUDIO_RPC_SET_PATH_DATA_OUT{
	long   instanceID;
	int    data_out_path_pb;
	int    data_out_path_ts;
};

struct AUDIO_RPC_AI_SET_OUT_FMT
{
	long	instanceID;
	int		out_fmt_pb;
	int		out_fmt_ts;
};

/* TV version */
struct AUDIO_RPC_SET_INTERLEAVE_OUT{
	long   instanceID;
	int    enable_interleave_out_pb;
	int    enable_interleave_out_ts;
};

struct AUDIO_RPC_SET_SIF_ADC_INIT{
	long   instanceID;
	int    sif_adc_init_enable;
};

struct AUDIO_SPDIF_ERROR {
	unsigned char err_threshold;
	long 	errorReportEnable;
} ;

struct AUDIO_ADC_CONFIG {
	AUDIO_GENERAL_CONFIG audioGeneralConfig;
	AUDIO_SAMPLE_INFO sampleInfo;
} ;

struct AUDIO_SPDIF_CONFIG {
	AUDIO_GENERAL_CONFIG audioGeneralConfig;
	AUDIO_SPDIF_ERROR audioSPDIFError;
} ;

struct AUDIO_IN_SOURCE{
	long instanceID;
	char focus_in;
};

struct AUDIO_IN_DATA_MEASURE{
	long instanceID;
};
struct AUDIO_IN_MUTE_INFO{
	long instanceID;
	char mute_en;
};

struct AUDIO_OUT_COPY_SOURCE{
	long instanceID;
	int			src_channel;
};

struct AUDIO_OUT_SPDIF_SOURCE{
	long instanceID;
	int			l_channel;
	int			r_channel;
};

struct AUDIO_KARAOKE_CONTROL_INFO{
	long instanceID;
	char speaker_mode;	/* speaker_mode[0] : speaker 2/0 1 vocal */
				/* speaker_mode[1] : speaker 2/0 2 vocal */
				/* speaker_mode[2] : speaker 3/0 1 vocal */
				/* speaker_mode[3] : speaker 3/0 2 vocal */
 	char vocal_mode;	/* vocal_mode[0] : V1, V2         	 (only vocal)       */
				/* vocal_mode[1] : MIC_V1, V2		 (with vocal :man)  */
				/* vocal_mode[2] : V1, MIC_V2		 (with vocal :woman)*/
				/* vocal_mode[3] : MIC_V1, MIC_V2	 (only mic)	    */

};

struct LINK_BUFFER{
   unsigned long magicNumber; /* 0x8088CAFE,  this is the magic sync word, just to verify the buffer */
   unsigned long Reserved;
   unsigned long Next;  /* The physical address of next linked buffer. If Next==0, means end of the buffer list */
   unsigned long Size;  /* size of the following data payload, count as bytes. The Size does not include this header part. */
   unsigned char  Data[1];   /* The data payload. Use [1] as declaration only, the real size is defined in the ﾡﾧSizeﾡﾨ field above. */
};

struct AUDIO_SOUND_EVENT{
    long instanceID;
	AUDIO_PCM_FORMAT pcmFormat;
    long endianType;		/* AUDIO_ENDIANTYPE */
    long pBitstreamRB;      /* physical address of bitstream buffer  as of LinkBuffer structure*/
    long iteration;                 /* iterations the sample should be played for */
};

struct AUDIO_HDMI_SET{
    unsigned int HDMI_Frequency;
};

struct AUDIO_HDMI_MUTE_INFO{
	long instanceID;
	char hdmi_mute;		/* 1:mute ;0:un-mute */
};

struct AUDIO_OUT_MUTE_INFO{
	long instanceID;
	char mute_flag;		/* 1:mute ;0:un-mute */
};

/* TV version */
struct AUDIO_RPC_BBADC_CONFIG{
	long instanceID;
	AUDIO_BBADC_CONFIG config;
};

/* TV version */
struct AUDIO_RPC_I2SI_CONFIG{
	long instanceID;
	AUDIO_I2SI_CONFIG config;
};

struct AUDIO_CONFIG_ADC{
	long instanceID;
	AUDIO_ADC_CONFIG adcConfig;
};

struct AUDIO_CONFIG_AFC{
	char afc_flag;
};

struct AUDIO_DROP_SAMPLE{
	long instanceID;
	long drop_pts;
};

struct AUDIO_P_W_NOISE_CFG{
	long instanceID;
	char pink_white_noise_en;/*0:disable ; 1: pink noise ; 2: white noise*/
	char pink_white_noise_out_channel[6];
};

enum ENUM_AUDIO_SPECTRUM_BANDNUM
{
    ENUM_AUDIO_SPECTRUM_16BAND=0,
    ENUM_AUDIO_SPECTRUM_32BAND=1,
    ENUM_AUDIO_SPECTRUM_64BAND=2,
    ENUM_AUDIO_SPECTRUM_ALLBAND=3
};

struct AUDIO_SPECTRUM_CFG
{
	long enable;	                /*0:disable ; 1:enable*/
	long bandnum;                   /* enum ENUM_AUDIO_SPECTRUM_BANDNUM */
	long data_addr;                 /* physical addr */
	long upper_bandlimit_addr;      /* physical addr */
};

struct AUDIO_VOLUME_CONTROL{
	long instanceID;
	char level;
};

/* TV version */
struct AUDIO_RPC_SPDIFI_CONFIG{
	long instanceID;
	AUDIO_SPDIFI_CONFIG config;
};

struct AUDIO_CONFIG_SPDIF{
	long instanceID;
	AUDIO_SPDIF_CONFIG spdifConfig;
};

struct AUDIO_CONFIG_SPDIF_ERR{
	long instanceID;
	AUDIO_SPDIF_ERROR audioSPDIFError;
};

struct	AUDIO_BACKDOOR_AI_INIT
{
	long	instanceID;
	long	PTSStamp1;
	long	PTSStamp2;
};

struct AUDIO_OUT_GENERAL_CONFIG
{
	char	interface_en;
	char	channel_out;
	char	count_down_play_en;
	int	count_down_play_cyc;
} ;

struct AUDIO_OUT_CS_INFO
{
	char	non_pcm_valid;
	char	non_pcm_format;
	int	audio_format;
	char	spdif_consumer_use;
	char	copy_right;
	char	pre_emphasis;
	char	stereo_channel;
} ;

struct AUDIO_DAC_CONFIG
{
	AUDIO_OUT_GENERAL_CONFIG audioGeneralConfig;
	AUDIO_SAMPLE_INFO sampleInfo;
} ;

struct AUDIO_OUT_SPDIF_CONFIG
{
	AUDIO_OUT_GENERAL_CONFIG audioGeneralConfig;
	AUDIO_SAMPLE_INFO sampleInfo;
	AUDIO_OUT_CS_INFO out_cs_info;
} ;

struct AUDIO_CONFIG_DAC_I2S{
	long instanceID;
	AUDIO_DAC_CONFIG dacConfig;
};

struct AUDIO_CONFIG_DAC_SPDIF{
	long instanceID;
	AUDIO_OUT_SPDIF_CONFIG spdifConfig;
};


struct	AUDIO_RPC_SPDIF_CHANNEL_STATUS
{
	long 	instanceID;
	long	ChannelStatus[6];		/* 192 / 32 = 6 */
};


/*
	Basicly, this is a feedback of the command issued by system side first.
*/
enum  ENUM_DVD_AUDIO_ENCODER_OUTPUT_INFO_TYPE{
	AUDIOENCODER_AudioGEN,
	AUDIOENCODER_AudioFrameInfo,
	AUDIOENCODER_TotalInfo,
 	AUDIOENCODER_AudioEOSInfo,
        AUDIOENCODER_InputEOSInfo
};

struct	AUDIO_RPC_ENC_ELEM_GENERAL_INFO
{
	enum ENUM_DVD_AUDIO_ENCODER_OUTPUT_INFO_TYPE infoType;
	enum AUDIO_MODULE_TYPE audioEncoderType;
	long	bitRate;
	long	samplingRate;
	enum ENCODE_MODE mode;			/* the default value is the AC Mode */
};


struct	AUDIO_RPC_ENC_ELEM_FRAME_INFO
{
	enum ENUM_DVD_AUDIO_ENCODER_OUTPUT_INFO_TYPE infoType;
        u_int   frameNumber;
	unsigned long	PTSH;			/* The PTS at the begin of the frame */
	unsigned long	PTSL;
/*	long	wptr;*/
	long	frameSize;		/* since it could be VBR, so the frame size should be given explicitly. */
	long	NumberOfFrame;	/* 1 is suggested, otherwise, system need to interpolated PTS later. */
};

enum  ENUM_AUDIO_AIN_INFO_TYPE{
	AUDIO_AIN_PB_PtsInfo,
	AUDIO_AIN_TS_PtsInfo
};

struct	AUDIO_RPC_AIN_ELEM_FRAME_INFO
{
	enum ENUM_AUDIO_AIN_INFO_TYPE infoType;
	unsigned long	PTSH;			/* The PTS at ptr position */
	unsigned long	PTSL;
	long ptr;
	long leng;
};

struct	AUDIO_RPC_DEC_GENERAL_INFO
{
	long	instanceID;
	long	samplingRate;
	long	bitRate;
	long	bitWidth;
};

struct	AUDIO_RPC_DEC_FRAME_INFO
{
	long	instanceID;
	long	frameSize;		/* since it could be VBR, so the frame size should be given explicitly. */
	long	NumberOfFrame;	/* 1 is suggested, otherwise, system need to interpolated PTS later. */
	char	EOS;			/* End of stream encountered */
};

struct	AUDIO_RPC_ERROR
{
	long	instanceID;
	long	audioError;
};

struct	AUDIO_RPC_MASTERSHIP
{
	long	instanceID;
	char	MasterShip;		/* 1 = master, 0 = slave */
};

/* Only for simulation */
struct AUDIO_RPC_ENC_SOURCEFILE
{
    long      instanceID;
    char      fileName[20];
    long      length;
};


/*conrad*/

enum AUDIO_PP_FUNCTION
{
	ENUM_AUDIO_PP_MASTER		=0, /* when this is turned off (=0), all post-procesing functions off. */
	ENUM_AUDIO_DEEMPHASIZE		=1,
	ENUM_AUDIO_PINKNOISE		=2,
	ENUM_AUDIO_DD_VIRTUAL_SURROUND	=3,
	ENUM_AUDIO_DD_VIRTUAL_SPEAKER	=4,
	ENUM_AUDIO_DD_EX		=5,
	ENUM_AUDIO_REVERB		=6,
	ENUM_AUDIO_EQUALIZER		=7,
	ENUM_AUDIO_PROLOGIC2		=8,
	ENUM_AUDIO_SRS		=9,
	ENUM_AUDIO_BASS_MANAGER		=10,
	ENUM_AUDIO_DTS_NEO		=11,
	ENUM_AUDIO_DOWN_MIX		=12,
	ENUM_AUDIO_MIXER		=13,
	ENUM_AUDIO_SRC		=14,
	ENUM_AUDIO_KEY_SHIFT		=15,
	ENUM_AUDIO_VOCAL_REMOVER	=16
};

struct	AUDIO_PP_FUNCTION_MODE
{
	char		AUDIO_PP_FUNCTION_ENA;			/* 0 : turn off, else : turn on */
	char		AUDIO_DEEMPHASIZE_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_PINKNOISE_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_DD_VIRTUAL_SURROUND_ENA;		/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_DD_VIRTUAL_SPEAKER_ENA;		/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_DD_EX_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_EQUALIZER_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_PROLOGIC2_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_SRS_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_BASS_MANAGER_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_DTS_NEO_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_DOWN_MIX_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_SRC_ENA;			/* -1 : don't change, 0 : turn off, 1 : turn on 	*/
	char		AUDIO_VOCAL_REMOVER_ENA[4];		/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_REVERB_ENA[4];			/* -1 : don't change, 0 : turn off, 1 : turn on */
	char		AUDIO_KEY_SHIFT_ENA[4];			/* -1 : don't change, 0 : turn off, 1 : turn on */
};

struct	AUDIO_PP_CONFIG
{
	long		instanceID;
	AUDIO_PP_FUNCTION_MODE	app_config;
};

struct	AUDIO_PROLOGIC2_MODE
{
	char   abaldisable_config_flag;		/* flag =1, then config this parameter enable,Auto-Balance [1:0] = [disable,enable] */
	char   chanconfig_config_flag;		/* flag =1, then config this parameter enable,Output Channel Select [7:0] = [3/2,2/2,Rsd,Rsd,3/0,Rsd,Rsd,Rsd] */
	char   dimset_config_flag;		/* flag =1, then config this parameter enable,Dimension Control [7:0] = [Rsd,3(center),2,1,0,-1,-2,-3(surround)] */
	char   surfiltenable_config_flag;	/* flag =1, then config this parameter enable,Surround Shelf-Filter [1:0] = [enable,disable] */
	char   modeselect_config_flag;		/* flag =1, then config this parameter enable,Decoder Mode Select [4:0] = [Mat.,Mov.,Mus.,Vir.,PL_Emu] */
	char   panoramaenable_config_flag;	/* flag =1, then config this parameter enable,Panorama [1:0] = [enable,disable] */
	char   fix_pcmscalefac_config_flag;	/* flag =1, then config this parameter enable,PCM scale factor(1,-1) ,defualt is 1.0 */
	char   rsinvenable_config_flag;		/* flag =1, then config this parameter enable,Right Surround polarity inversion [1:0] = [enable,disable] */
	char   samprateid_config_flag;		/* flag =1, then config this parameter enable,PCM sample rate [2:0] = [32kHz,44.1kHz,48kHz] */
	char   cwidthset_config_flag;		/* flag =1, then config this parameter enable,Center Width Setting [7:0] = [90(phantom center),69,2,62,54,36,28,20,8,0] */

	long   abaldisable;			/* Auto-Balance [1:0] = [disable,enable] */
	long   chanconfig;			/* Output Channel Select [7:0] = [3/2,2/2,Rsd,Rsd,3/0,Rsd,Rsd,Rsd] */
	long   dimset;			/* Dimension Control [7:0] = [Rsd,3(center),2,1,0,-1,-2,-3(surround)] */
	long   surfiltenable;			/* Surround Shelf-Filter [1:0] = [enable,disable] */
	long   modeselect;			/* Decoder Mode Select [4:0] = [Mat.,Mov.,Mus.,Vir.,PL_Emu] */
	long   panoramaenable;			/* Panorama [1:0] = [enable,disable] */
	long   fix_pcmscalefac;			/* PCM scale factor(1,-1) ,defualt is 1.0  */
	long   rsinvenable;			/* Right Surround polarity inversion [1:0] = [enable,disable] */
	long   samprateid;			/* PCM sample rate [2:0] = [32kHz,44.1kHz,48kHz] */
	long   cwidthset;			/* Center Width Setting [7:0] = [90(phantom center),69,2,62,54,36,28,20,8,0] */
};

enum ENUM_PROLOGIC2_ENA
{
    ENUM_PROLOGIC2_OFF,
    ENUM_PROLOGIC2_ON
};


enum ENUM_AI_PATH
{
    ENUM_AI_PB_PATH = 0,
    ENUM_AI_TS_PATH = 1
};

struct	AUDIO_PROLOGIC2_CONFIG
{
	long		instanceID;
	unsigned char	ena;
	AUDIO_PROLOGIC2_MODE	app_pl2_config;
};

enum ENUM_SRC_MODE
{
    ENUM_SRC_POOR=0,
    ENUM_SRC_GOOD=1
};

struct	AUDIO_SRC_CONFIG
{
	long		instanceID;
	long   		mode;		/* mode =0 then less computation, mode =1 then better quality */
};

struct	AUDIO_RPC_MIXER_MODE
{
	long		simpleMix;		/* if simpleMix = 1, it is supposed to mix the inputs for a long time. */
					/* when simpleMix = 1, the exclusiveMode is ignored */
	long		exclusiveMode;	/* the last 4 bits (LSB) represents the 4 input pins, 1 = enable, 0 = disbale */
	/* SRC will be called automatically when the inputRate is different from outputRate. */
};

struct	AUDIO_MIXER_CONFIG
{
	long		instanceID;
	AUDIO_RPC_MIXER_MODE	app_mixer_config;
};

struct AUDIO_PTS_MIXER {
	long	pinID;
	int64_t	mixer_in_change_PTS;
	long	mixer_in_ena;
	long	mixer_gain[8];
};
typedef struct AUDIO_PTS_MIXER AUDIO_PTS_MIXER;

struct AUDIO_RPC_PTS_MIXER_CONFIG {
	long	instanceID;
	AUDIO_PTS_MIXER config;
};
typedef struct AUDIO_RPC_PTS_MIXER_CONFIG AUDIO_RPC_PTS_MIXER_CONFIG;


enum ENUM_EQUALIZER_GAIN
{
    ENUM_EQUALIZER_GAIN_N12DB=-12,
    ENUM_EQUALIZER_GAIN_N11DB=-11,
    ENUM_EQUALIZER_GAIN_N10DB=-10,
    ENUM_EQUALIZER_GAIN_N9DB=-9,
    ENUM_EQUALIZER_GAIN_N8DB=-8,
    ENUM_EQUALIZER_GAIN_N7DB=-7,
    ENUM_EQUALIZER_GAIN_N6DB=-6,
    ENUM_EQUALIZER_GAIN_N5DB=-5,
    ENUM_EQUALIZER_GAIN_N4DB=-4,
    ENUM_EQUALIZER_GAIN_N3DB=-3,
    ENUM_EQUALIZER_GAIN_N2DB=-2,
    ENUM_EQUALIZER_GAIN_N1DB=-1,
    ENUM_EQUALIZER_GAIN_0DB=0,
    ENUM_EQUALIZER_GAIN_1DB=1,
    ENUM_EQUALIZER_GAIN_2DB=2,
    ENUM_EQUALIZER_GAIN_3DB=3,
    ENUM_EQUALIZER_GAIN_4DB=4,
    ENUM_EQUALIZER_GAIN_5DB=5,
    ENUM_EQUALIZER_GAIN_6DB=6,
    ENUM_EQUALIZER_GAIN_7DB=7,
    ENUM_EQUALIZER_GAIN_8DB=8,
    ENUM_EQUALIZER_GAIN_9DB=9,
    ENUM_EQUALIZER_GAIN_10DB=10,
    ENUM_EQUALIZER_GAIN_11DB=11,
    ENUM_EQUALIZER_GAIN_12DB=12
};

enum ENUM_EQUALIZER_MODE
{
    ENUM_EQUALIZER_RESERVED=0,
    ENUM_EQUALIZER_MODE_POP=1,
    ENUM_EQUALIZER_MODE_LIVE=2,
    ENUM_EQUALIZER_MODE_CLUB=3,
    ENUM_EQUALIZER_MODE_ROCK=4,
    ENUM_EQUALIZER_MODE_BASS=5,
    ENUM_EQUALIZER_MODE_TREBLE=6,
    ENUM_EQUALIZER_MODE_VOCAL=7,
    ENUM_EQUALIZER_MODE_POWERFUL=8,
    ENUM_EQUALIZER_MODE_DANCE=9,
    ENUM_EQUALIZER_MODE_SOFT=10,
    ENUM_EQUALIZER_MODE_PARTY=11,
    ENUM_EQUALIZER_MODE_CLASSICAL=12
};

struct	AUDIO_RPC_EQUALIZER_MODE
{
	long		mode;		/* 0:customer designed, 1:club mode, 2:dance mode, 3:live mode, 4:pop mode, 5:rock mode,   6:loudness(powerful) */
	long		gain[10];		/* for customer designed, gain of each band */
};

enum ENUM_EQUALIZER_ENA
{
    ENUM_EQUALIZER_OFF,
    ENUM_EQUALIZER_ON
};

enum ENUM_GBL_VAR_EQUALIZER_ID
{
    ENUM_EQUALIZER_PP = 0,
    ENUM_EQUALIZER_MIC = 1,
    ENUM_EQUALIZER_AUX = 2
};

struct	AUDIO_EQUALIZER_CONFIG
{
	long			instanceID;
	int			gbl_var_eq_ID;
	unsigned char		ena;
	AUDIO_RPC_EQUALIZER_MODE	app_eq_config;
};

enum ENUM_BASS_MANAGEMENT_CUTOFFFREQ
{
    ENUM_BASS_MANAGEMENT_80_HZ=0,
    ENUM_BASS_MANAGEMENT_100_HZ=1,
    ENUM_BASS_MANAGEMENT_120_HZ=2
};

enum ENUM_BASS_MANAGEMENT_MODE
{
    ENUM_BASS_MANAGEMENT_MODE_0=0,
    ENUM_BASS_MANAGEMENT_MODE_1=1,
    ENUM_BASS_MANAGEMENT_MODE_2=2,
    ENUM_BASS_MANAGEMENT_MODE_3=3,
    ENUM_BASS_MANAGEMENT_SIMPLIFIED=4,
    ENUM_BASS_MANAGEMENT_CAR=5,
    ENUM_BASS_MANAGEMENT_DIGITAL_0=6,
    ENUM_BASS_MANAGEMENT_DIGITAL_1=7
};

enum ENUM_BASS_MANAGEMENT_SUBWOOFER_ENA
{
    ENUM_BASS_MANAGEMENT_SUBWOOFER_OFF,
    ENUM_BASS_MANAGEMENT_SUBWOOFER_ON
};

struct	AUDIO_RPC_BASS_MANAGEMENT_MODE
{
	long		cutoffFreq;		/* 80/100/120 Hz */
	long		config_mode;	/* mode : 0~7 */
	long		subwoofer_ena;	/* 0:disable, 1:enable; for configuration 2 ,3, simplified */
};

enum ENUM_BASS_MANAGEMENT_ENA
{
    ENUM_BASS_MANAGEMENT_OFF,
    ENUM_BASS_MANAGEMENT_ON
};

struct	AUDIO_BASS_MANAGEMENT_CONFIG
{
	long			instanceID;
	unsigned char		ena;
	AUDIO_RPC_BASS_MANAGEMENT_MODE	app_bassmng_config;
};

struct	AUDIO_RPC_DVS_MODE
{
	long		wide_mode;	/* 0:reference mode, 1:wide mode */
};

enum ENUM_DVS_ENA
{
    ENUM_DVS_OFF,
    ENUM_DVS_ON
};

struct	AUDIO_DVS_CONFIG
{
	long			instanceID;
	unsigned char		ena;
	AUDIO_RPC_DVS_MODE	app_dvs_config;
};

enum ENUM_KEY_SHIFT_ENA
{
    ENUM_KEY_SHIFT_OFF,
    ENUM_KEY_SHIFT_ON
};

enum ENUM_KEY_SHIFT_STONE
{
    ENUM_KEY_SHIFT_STONE_N24=-24,
    ENUM_KEY_SHIFT_STONE_N23=-23,
    ENUM_KEY_SHIFT_STONE_N22=-22,
    ENUM_KEY_SHIFT_STONE_N21=-21,
    ENUM_KEY_SHIFT_STONE_N20=-20,
    ENUM_KEY_SHIFT_STONE_N19=-19,
    ENUM_KEY_SHIFT_STONE_N18=-18,
    ENUM_KEY_SHIFT_STONE_N17=-17,
    ENUM_KEY_SHIFT_STONE_N16=-16,
    ENUM_KEY_SHIFT_STONE_N15=-15,
    ENUM_KEY_SHIFT_STONE_N14=-14,
    ENUM_KEY_SHIFT_STONE_N13=-13,
    ENUM_KEY_SHIFT_STONE_N12=-12,
    ENUM_KEY_SHIFT_STONE_N11=-11,
    ENUM_KEY_SHIFT_STONE_N10=-10,
    ENUM_KEY_SHIFT_STONE_N9=-9,
    ENUM_KEY_SHIFT_STONE_N8=-8,
    ENUM_KEY_SHIFT_STONE_N7=-7,
    ENUM_KEY_SHIFT_STONE_N6=-6,
    ENUM_KEY_SHIFT_STONE_N5=-5,
    ENUM_KEY_SHIFT_STONE_N4=-4,
    ENUM_KEY_SHIFT_STONE_N3=-3,
    ENUM_KEY_SHIFT_STONE_N2=-2,
    ENUM_KEY_SHIFT_STONE_N1=-1,
    ENUM_KEY_SHIFT_STONE_0=0,
    ENUM_KEY_SHIFT_STONE_1=1,
    ENUM_KEY_SHIFT_STONE_2=2,
    ENUM_KEY_SHIFT_STONE_3=3,
    ENUM_KEY_SHIFT_STONE_4=4,
    ENUM_KEY_SHIFT_STONE_5=5,
    ENUM_KEY_SHIFT_STONE_6=6,
    ENUM_KEY_SHIFT_STONE_7=7,
    ENUM_KEY_SHIFT_STONE_8=8,
    ENUM_KEY_SHIFT_STONE_9=9,
    ENUM_KEY_SHIFT_STONE_10=10,
    ENUM_KEY_SHIFT_STONE_11=11,
    ENUM_KEY_SHIFT_STONE_12=12,
    ENUM_KEY_SHIFT_STONE_13=13,
    ENUM_KEY_SHIFT_STONE_14=14,
    ENUM_KEY_SHIFT_STONE_15=15,
    ENUM_KEY_SHIFT_STONE_16=16,
    ENUM_KEY_SHIFT_STONE_17=17,
    ENUM_KEY_SHIFT_STONE_18=18,
    ENUM_KEY_SHIFT_STONE_19=19,
    ENUM_KEY_SHIFT_STONE_20=20,
    ENUM_KEY_SHIFT_STONE_21=21,
    ENUM_KEY_SHIFT_STONE_22=22,
    ENUM_KEY_SHIFT_STONE_23=23,
    ENUM_KEY_SHIFT_STONE_24=24
};

struct	AUDIO_KEY_SHIFT_CONFIG
{
	long		instanceID;
	unsigned char	ena;
	long		pinID;
	long		semitone;
};

enum ENUM_REVERB_ENA
{
    ENUM_REVERB_OFF,
    ENUM_REVERB_ON
};

enum ENUM_REVERB_MODE
{
    ENUM_Cathedral_1=0,
    ENUM_Cathedral_2=1,
    ENUM_Hall=2,
    ENUM_Room=3,
    ENUM_Basement=4
};

struct	AUDIO_REVERB_CONFIG
{
	long		instanceID;
	unsigned char	ena;
	long		pinID;
	long		reverb_mode;	/* 0:Cathedral1, 1:Cathedral2, 2:Hall, 3:Room, 4:Basement*/
};

enum ENUM_VOCAL_REMOVER_ENA
{
    ENUM_VOCAL_REMOVER_OFF,
    ENUM_VOCAL_REMOVER_ON
};

enum ENUM_VOCAL_REMOVER_MODE
{
    ENUM_VOCAL_REMOVER_ADVANCED,
    ENUM_VOCAL_REMOVER_CLASSICAL
};

struct	AUDIO_VOCAL_REMOVER_CONFIG
{
	long		instanceID;
	unsigned char	ena;
	long		vr_mode;
	long		pinID;
};

struct AUDIO_RPC_DEC_INIT
{
	long 	  temp;
};

struct AUDIO_RPC_ENC_INIT
{
	long	  instanceID;
	long 	  temp;
};


struct AUDIO_RPC_ENC_SET_BITRATE
{
	long	  instanceID;
	long 	  bitrate;
};


struct AUDIO_RPC_ENC_COMMAND
{
	long	  instanceID;
	AUDIO_ENC_CFG 	  enc_config;
};


struct	AUDIO_RPC_DEBUG_MEMORY
{
	int	AudioFWVersionNumber;
	char	audioVersionNumber[12];
	int64_t		AudioDemuxPTS;
	int64_t		AudioOutPTS;
	int64_t		DecoderPTS;
	int64_t		FreeRun;
	int	contextSwitchTimes;
	int	taskNumber;
	int	ISRNumber;
	int	DSRNumber;
	int	EPC;
	int	exceptionCause;
	int	RPC_Status;
	int	Reserve[8];
};

struct AUDIO_RPC_ENC_INFO
{
	long	  instanceID;
	long 	  encode_type;
};

struct AUDIO_RPC_ENC_DV_MIXER
{
	long 	  temp;
};


struct AUDIO_RPC_AO_INIT
{
	long 	  temp;
};

struct AUDIO_RPC_AO_SET_EQUALIZER
{
	long 	  temp;
};

struct AUDIO_AO_RPC_CONFIG_DELAY_CONTROL
{
	long 	  temp;
};

struct AUDIO_RPC_AO_CONFIG_KARAOKE
{
	long 	  temp;
};

struct AUDIO_RPC_AO_MIXER
{
	long 	  temp;
};

struct AUDIO_RPC_PP_CFG
{
	long 	  temp;
};


struct AUDIO_RPC_PP_MUTE
{
	long 	  temp;
};

struct AUDIO_RPC_AO_DAC
{
	long 	  temp;
};

struct AUDIO_RPC_PP_PROLOGIC
{
	long 	  temp;
};

enum AUDIO_AGC_MODE
{
	ENUM_AUDIO_AGC_OFF,
	ENUM_AUDIO_AGC_NIGHT_MODE,
	ENUM_AUDIO_AGC_COMFORT_LISTEN_MODE,
	ENUM_AUDIO_AGC_ADVANCE_MODE
};


enum AUDIO_KARAOKE_MODE
{
    KARAOKE_NO_VOCALS=0,
    KARAOKE_VOCAL1=1,
    KARAOKE_VOCAL2=2,
    KARAOKE_BOTH_VOCALS=3
};

enum AUDIO_EASE_TYPE
{
    AUDIO_EASE_TYPE_LINEAR,
    AUDIO_EASE_TYPE_INQUAD,
    AUDIO_EASE_TYPE_OUTQUAD,
    AUDIO_EASE_TYPE_INOUTQUAD,
    AUDIO_EASE_TYPE_INCUBIC,
    AUDIO_EASE_TYPE_OUTCUBIC,
    AUDIO_EASE_TYPE_INOUTCUBIC,
    AUDIO_EASE_TYPE_INQUARTIC,
    AUDIO_EASE_TYPE_OUTQUARTIC,
    AUDIO_EASE_TYPE_INOUTQUARTIC,
    AUDIO_EASE_TYPE_INQUINTIC,
    AUDIO_EASE_TYPE_OUTQUINTIC,
    AUDIO_EASE_TYPE_INOUTQUINTIC,
    AUDIO_EASE_TYPE_INSIN,
    AUDIO_EASE_TYPE_OUTSIN,
    AUDIO_EASE_TYPE_INOUTSIN,
    AUDIO_EASE_TYPE_INEXP,
    AUDIO_EASE_TYPE_OUTEXP,
    AUDIO_EASE_TYPE_INOUTEXP,
    AUDIO_EASE_TYPE_INCIRCULAR,
    AUDIO_EASE_TYPE_OUTCIRCULAR,
    AUDIO_EASE_TYPE_INOUTCIRCULAR,
    AUDIO_EASE_TYPE_UNKNOWN
};

/*
	Audio config uses the msg ID and following 4 words to pass the info to audio side. These
    are used config the general global variable for the audio side.
*/
enum AUDIO_CONFIG_CMD_MSG
{
	AUDIO_CONFIG_CMD_SPEAKER=0,		/* [0] Speaker mode, 		[1,2,3] Reserved */
	AUDIO_CONFIG_CMD_AGC=1,			/* [0] AGC mode (AUDIO_AGC_MODE),  	[1,2,3] Reserved */
	AUDIO_CONFIG_CMD_SPDIF=2,		/* [0] L-channel, [1] R-channel, 	[2,3] Reserved */
	AUDIO_CONFIG_CMD_VOLUME=3,		/* [0] Volume value,		[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_MUTE=4,		/* [0] Mute enable,       	[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_AO_MIC=5,		/* [0] Enable,       		[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_AO_AUX=6,		/* [0] Enable,		[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_AO_ECHO_REVERB=7,		/* [0] Enable, [1] mode		[2,3] Reserved*/
	AUDIO_CONFIG_CMD_AO_MIC1_VOLUME=8,		/* [0] Volume value		[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_AO_MIC2_VOLUME=9,		/* [0] Volume value		[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_AO_DEC_VOLUME=10,		/* [0] Volume value		[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_AO_AUX_VOLUME=11,		/* [0] Volume value		[1,2,3] Reserved*/
	AUDIO_CONFIG_CMD_DAC_SWITCH=12,
	/* Dolby Decoder Config */
	AUDIO_CONFIG_CMD_DD_DUALMONO=13,
	AUDIO_CONFIG_CMD_DD_SCALE=14,
	AUDIO_CONFIG_CMD_DD_DOWNMIXMODE=15,
	AUDIO_CONFIG_CMD_DD_COMP=16,
	AUDIO_CONFIG_CMD_DD_LFE=17,
	AUDIO_CONFIG_CMD_DD_STEREOMIX=18,
	/* Dolby Decoder Config end*/
	/* Digital Out Config */
	AUDIO_CONFIG_CMD_DIGITAL_OUT=19,
	AUDIO_CONFIG_CMD_EXCLUSIVE=20,
	AUDIO_CONFIG_CMD_AC3_SPDIF_RAW=21,
	AUDIO_CONFIG_CMD_AC3_HDMI_RAW=22,
	AUDIO_CONFIG_CMD_DTS_SPDIF_RAW=23,
	AUDIO_CONFIG_CMD_DTS_HDMI_RAW=24,
	AUDIO_CONFIG_CMD_MPG_SPDIF_RAW=25,
	AUDIO_CONFIG_CMD_MPG_HDMI_RAW=26,
	AUDIO_CONFIG_CMD_AAC_SPDIF_RAW=27,
	AUDIO_CONFIG_CMD_AAC_HDMI_RAW=28,
	AUDIO_CONFIG_CMD_MLP_HDMI_RAW=29,
	AUDIO_CONFIG_CMD_DDP_HDMI_RAW=30,

	AUDIO_CONFIG_CMD_HDMI_CHANNEL_OUT=31,	/* [0] HDMI 2-channel, [1] HDMI multi channel */
	AUDIO_CONFIG_CMD_FORCE_CHANNEL_CODEC=32,	/* [bit 0] DTS force channel */
	AUDIO_CONFIG_CMD_MLP_SPDIF_RAW = 33,
	AUDIO_CONFIG_CMD_DDP_SPDIF_RAW = 34,

	AUDIO_CONFIG_CMD_MAX_OUTPUT_SAMPLERATE = 35,

	AUDIO_CONFIG_CMD_USB_DEVICE_SUPPORT_SAMPLERATE = 36,  /* value[0]: off(0)/on(1), value[1]: info size, value[2] info addr, ptr[0:size-1]: samplerate info*/

	AUDIO_CONFIG_CMD_KARAOKE_MODE = 37, /* value[0]: see enum AUDIO_KARAOKE_MODE */

	AUDIO_CONFIG_CMD_BRAZIL_LATM_AAC = 38,

	AUDIO_CONFIG_CMD_DRC_PERCENT = 39,

    AUDIO_CONFIG_CMD_LICENSE_MODE = 40,

    AUDIO_CONFIG_CMD_AUDIO_TYPE_PRIORITY = 41,

    AUDIO_CONFIG_CMD_SPDIF_OUTPUT_SWITCH = 42,

    AUDIO_CONFIG_CMD_CUSTOMIZE_REQUEST = 43,

    AUDIO_CONFIG_CMD_DEC_PLAYBACK_RATE = 44,     /* max_rate,min_rate */

    AUDIO_CONFIG_CMD_SAMPLERATE_TOLERANCE = 45,  /* see enum AUDIO_SAMPLERATE_TOLERANCE */

    AUDIO_CONFIG_CMD_KARAOKE_GENDER_CHANGE = 46,

    AUDIO_CONFIG_CMD_SET_DEC_DELAY_RP = 47,

    AUDIO_CONFIG_CMD_AO_OUTPUT_CONFIG = 48,

    AUDIO_CONFIG_CMD_SET_AI_VOLUME = 49,

    AUDIO_CONFIG_CMD_AO_DEC_MUTE=50,

    AUDIO_CONFIG_TFAGC_DEBUG_PRINT = 51,

    AUDIO_CONFIG_ASF_DEBUG_PRINT = 52,

    AUDIO_CONFIG_CMD_AO_OUTPUT_VOLUME = 53,

    AUDIO_CONFIG_CMD_KARAOKE_MODE_FORTV_PROJECT=54,

    AUDIO_CONFIG_CMD_AVOUT_FROM_HW = 56,/* [0] = on/off
                                         * [1] = src(AIO_PATH_SRC)
                                         * [2] = sub_src(AIO_BBADC_SRC)
                                         */
    AUDIO_CONFIG_CMD_CONFIG_AIO_AIO1 = 57,
    AUDIO_CONFIG_CMD_CONFIG_AIO_AIO2 = 58,
    AUDIO_CONFIG_CMD_CONFIG_AIO_HEADPHONE = 59,
    AUDIO_CONFIG_CMD_AO_DEC_MULTI_CH_VOLUME = 60, /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_DEC_MULTI_CH_MUTE = 61,  /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_SET_SPDIF_CS_INFO= 62,
    AUDIO_CONFIG_CMD_HDMI_ARC = 63,
    AUDIO_CONFIG_CMD_AO_DEC_MULTI_CH_PB_VOLUME = 64, /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_DEC_MULTI_CH_PB_MUTE = 65,  /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_DEC_MULTI_CH_TS_VOLUME = 66, /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_DEC_MULTI_CH_TS_MUTE = 67,  /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_FLASH_PB_VOLUME = 68, /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_FLASH_PB_MUTE = 69,  /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_FLASH_TS_VOLUME = 70, /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AO_FLASH_TS_MUTE = 71,  /*L, R, Ls, Rs, C, LFE, Lss, Rss */
    AUDIO_CONFIG_CMD_AI_CEI_ENABLE = 72,
    AUDIO_CONFIG_CMD_AI_CEI_SETMODE = 73,  /* not used any more, keep this becuase of ordering*/

    AUDIO_CONFIG_CMD_AD_DESCRIPTOR = 74,
    AUDIO_CONFIG_CMD_DEFAULT_DIALNORM = 75,
    AUDIO_CONFIG_CMD_AI_CEI_SET_PARAMETER = 76,
    AUDIO_CONFIG_CMD_AI_CEI_GET_PARAMETER = 77,
    AUDIO_CONFIG_CMD_AI_TRANSFER_MATRIX = 78,
    AUDIO_CONFIG_CMD_AO_LGSE_MUX = 79,

    AUDIO_CONFIG_CMD_SET_VOLUME = 100,
    AUDIO_CONFIG_CMD_SET_MUTE = 101,
    AUDIO_CONFIG_CMD_SET_DELAY = 102,
    AUDIO_CONFIG_CMD_SET_SCART_ON = 103,
    AUDIO_CONFIG_CMD_SET_NO_DELAY_PARAM = 104,
    AUDIO_CONFIG_CMD_SET_SPDIF_CS_ALL = 105,
    AUDIO_CONFIG_CMD_ARC = 106,
    AUDIO_CONFIG_CMD_NTFY_HAL_HDMI_FMT = 107,
    AUDIO_CONFIG_CMD_AANDROID_DOLBY_DYN_RANGE = 108,
    AUDIO_CONFIG_CMD_AANDROID_HEAAC_DYN_RANGE = 109,
    AUDIO_CONFIG_CMD_AANDROID_MPEG_AUD_LEVEL = 110,
    AUDIO_CONFIG_CMD_AANDROID_HEAAC_AUD_LEVEL = 111,
    AUDIO_CONFIG_CMD_SET_PCM_INFO = 112,
    AUDIO_CONFIG_CMD_GET_TASK_STARTED = 113,
    AUDIO_CONFIG_CMD_DBX_DEBUG = 114,
    AUDIO_CONFIG_CMD_DBX_CONFIG = 115,
    AUDIO_CONFIG_CMD_DBX_TAB_CONFIG = 116,
    AUDIO_CONFIG_CMD_SET_GAP_PTS = 117,
    AUDIO_CONFIG_CMD_AO_ENCODER_ENABLE = 118,
    AUDIO_CONFIG_CMD_DTS_DEC_PARAM = 119
};

enum AUDIO_DTS_DEC_PARAM_TYPE{
    AUDIO_DTS_DEC_DRC,
    AUDIO_DTS_DEC_LFEMIX
};

enum AUDIO_DBX_DEBUG_CMD{
	AUDIO_DBX_DEBUG_CMD_RP = 0,
	AUDIO_DBX_DEBUG_CMD_RC,
	AUDIO_DBX_DEBUG_CMD_WP,
	AUDIO_DBX_DEBUG_CMD_WC,
	AUDIO_DBX_DEBUG_CMD_EP,
	AUDIO_DBX_DEBUG_CMD_DP,
	AUDIO_DBX_DEBUG_CMD_SETMODE,
	AUDIO_DBX_DEBUG_CMD_GS,
	AUDIO_DBX_DEBUG_CMD_GV
};

enum AUDIO_DBXTV_PARAM_TYPE{
    AUDIO_DBX_PARAM_TYPE_ONOFF,
    AUDIO_DBX_PARAM_TYPE_TOTAL_SONICS,
    AUDIO_DBX_PARAM_TYPE_TOTAL_SURROUND,
    AUDIO_DBX_PARAM_TYPE_TOTAL_VOLUME
};

enum AUDIO_DBXTV_TABLE{
    AUDIO_DBXTV_TABLE_TOTSON_PARAM,
    AUDIO_DBXTV_TABLE_TOTSON_COEFF,
    AUDIO_DBXTV_TABLE_TOTVOL_PARAM,
    AUDIO_DBXTV_TABLE_TOTVOL_COEFF,
    AUDIO_DBXTV_TABLE_TOTSUR_PARAM,
    AUDIO_DBXTV_TABLE_TOTSUR_COEFF,
    AUDIO_DBXTV_TABLE_CNT
};

enum AUDIO_DBXTV_TotSonMode{
    AUDIO_DBXTV_TOTSON_ON   = 0,
    AUDIO_DBXTV_TOTSON_B,  /*Non-functional placeholder*/
    AUDIO_DBXTV_TOTSON_C,  /*Non-functional placeholder*/
    AUDIO_DBXTV_TOTSON_D,  /*Non-functional placeholder*/
    AUDIO_DBXTV_TOTSON_E,  /*Non-functional placeholder*/
    AUDIO_DBXTV_TOTSON_F,  /*Non-functional placeholder*/
    AUDIO_DBXTV_TOTSON_NUMBER_OF_CONFIGS,
    AUDIO_DBXTV_TOTSON_OFF = AUDIO_DBXTV_TOTSON_NUMBER_OF_CONFIGS
};

enum AUDIO_DBXTV_TotVolMode{
    AUDIO_DBXTV_TOTVOL_NORMAL   = 0,
    AUDIO_DBXTV_TOTVOL_NIGHT,
    AUDIO_DBXTV_TOTVOL_NUMBER_OF_CONFIGS,
    AUDIO_DBXTV_TOTVOL_OFF = AUDIO_DBXTV_TOTVOL_NUMBER_OF_CONFIGS
};

enum AUDIO_DBXTV_TotSurMode{
    AUDIO_DBXTV_TOTSUR_ON   = 0,
    AUDIO_DBXTV_TOTSUR_NUMBER_OF_CONFIGS,
    AUDIO_DBXTV_TOTSUR_OFF = AUDIO_DBXTV_TOTSUR_NUMBER_OF_CONFIGS
};

enum AUDIO_DBXTV_SAMPLE_RATE{
    AUDIO_DBXTV_SAMPLE_RATE_48000,
    AUDIO_DBXTV_SAMPLE_RATE_44100,
    AUDIO_DBXTV_SAMPLE_RATE_32000,
    AUDIO_DBXTV_SAMPLE_RATE_CNT
};

struct AUDIO_DBXTV_TABLE_INFO {
    u_char dbxTotSonConfigsNum;
    u_char dbxTotVolConfigsNum;
    u_char dbxTotSurConfigsNum;
    u_int tblAddr[AUDIO_DBXTV_TABLE_CNT];
};

enum AUDIO_CONFIG_LGSE
{
    ENUM_LGSE_NONE = 0,
    ENUM_LGSE_PASS = 1,
    ENUM_LGSE_MAX  = 2
};

enum AUDIO_CONFIG_DEVICE
{
    ENUM_DEVICE_NONE        = 0,
    ENUM_DEVICE_ENCODER     = 1,
    ENUM_DEVICE_DECODER     = 2,
    ENUM_DEVICE_SPDIF       = 3,
    ENUM_DEVICE_SPEAKER     = 4,
    ENUM_DEVICE_HEADPHONE   = 5,
    ENUM_DEVICE_SCART       = 6,
    ENUM_DEVICE_PCM_CAPTURE = 7,
    ENUM_DEVICE_PP_MIXER    = 8,
    ENUM_DEVICE_FLASH_PIN   = 9,
    ENUM_DEVICE_SPDIF_ES    = 10,
    ENUM_DEVICE_DECODER0    = 11,
    ENUM_DEVICE_DECODER1    = 12,
    ENUM_DEVICE_DEC_PB = 13,
    ENUM_DEVICE_DEC_TS = 14,
    ENUM_DEVICE_FLASH_PB = 15,
    ENUM_DEVICE_FLASH_TS = 16,
    ENUM_DEVICE_PCM_CAPTURE_PIN1 = 17,
    ENUM_DEVICE_PCM_CAPTURE_PIN2 = 18,
    ENUM_DEVICE_PCM_CAPTURE_PIN3 = 19,
    ENUM_DEVICE_MAX = 20
};

enum AUDIO_CONFIG_AIO
{
    ENUM_AUDIO_CONFIG_AIO_VARIABLE_VOLUME = 0,
    ENUM_AUDIO_CONFIG_AIO_FIXED_VOLUME = 1,
    ENUM_AUDIO_CONFIG_AIO_MUTE = 2
};

enum AUDIO_CUSTOMIZE_REQUEST
{
    ENUM_MELE_SPDIF_FUNCTION = 0x39D
};

struct AUDIO_CONFIG_COMMAND
{
	AUDIO_CONFIG_CMD_MSG	msgID;		/* The message ID corresponding to the command */
	unsigned int	value[15];		/* The setting values, follows the values specified above. */
};

enum AUDISTRY_FEATURE_CMD_MSG
{
	ENUM_AUDISTRY_BUNDLE = 0,
	ENUM_AUDISTRY_TWOUP = 1,
	ENUM_AUDISTRY_STEREOWRAPPER = 2,
	ENUM_AUDISTRY_HEADSPACE = 3,
	ENUM_AUDISTRY_LATENIGHT = 4,
	ENUM_AUDISTRY_VOLUME = 5,
	ENUM_AUDISTRY_RUMBLER = 6
};

enum AUDISTRY_TWOUP_PARAMETER
{
	ENUM_TWOUP_ENABLE = 0,
	ENUM_TWOUP_DETECTOR = 1
};

enum AUDISTRY_HEADSPACE_PARAMETER
{
	ENUM_HEADSPACE_ENABLE = 0,
	ENUM_HEADSPACE_MODE = 1
};

enum AUDISTRY_STEREOWRAPPER_PARAMETER
{
	ENUM_STEREOWRAPPER_ENABLE = 0,
	ENUM_STEREOWRAPPER_WIDTH = 1
};

enum AUDISTRY_LATENIGHT_PARAMETER
{
	ENUM_LATENIGHT_ENABLE = 0,
	ENUM_LATENIGHT_LEVEL = 1,
	ENUM_LATENIGHT_DEPTH = 2
};

enum AUDISTRY_VOLUME_PARAMETER
{
	ENUM_VOLUME_ENABLE = 0,
	ENUM_VOLUME_GAIN = 1
};

enum AUDISTRY_RUMBLER_PARAMETER
{
	ENUM_RUMBLER_ENABLE = 0,
	ENUM_RUMBLER_CUTOFF = 1,
	ENUM_RUMBLER_BOOST = 2,
	ENUM_RUMBLER_LEVEL = 3
};

struct AUDISTRY_CONFIG_COMMAND
{
	AUDISTRY_FEATURE_CMD_MSG	feature;			/* The setting feature, follows the values specified above. */
	unsigned int 	parameter;						/* The setting parameter, follows the values specified above. */
	int				value;
};

enum AUDIO_AO_MIC_CONFIG
{
	ENUM_AUDIO_AO_MIC_OFF=0,
	ENUM_AUDIO_AO_MIC1_ON=1,
	ENUM_AUDIO_AO_MIC2_ON=2,
	ENUM_AUDIO_AO_MIC1_MIC2_ON=3
};

enum AUDIO_AO_AUX_CONFIG
{
	ENUM_AUDIO_AO_AUX_OFF=0,
	ENUM_AUDIO_AO_AUX_ON=1
};

enum AUDIO_AO_ECHO_REVERB_CONFIG
{
	ENUM_AUDIO_AO_ECHO_REVERB_OFF=0,
	ENUM_AUDIO_AO_ECHO_ON=1,
	ENUM_AUDIO_AO_REVERB_ON=2,
	ENUM_AUDIO_AO_ECHO_ON_REVERB_ON=3
};

struct	AUDIO_RPC_ECHO_MODE
{
	long		mode;		/* 0:customer designed, 1:club mode, 2:dance mode, 3:live mode, 4:pop mode, 5:rock mode,   6:loudness(powerful) */
	long		delay;		/* enum AUDIO_AO_ECHO_DELAY_MODE */
	long		fdbk_gain;
};

enum AUDIO_AO_ECHO_DELAY_MODE
{
	ENUM_AUDIO_AO_ECHO_0MS=0,
	ENUM_AUDIO_AO_ECHO_10MS=2,
	ENUM_AUDIO_AO_ECHO_20MS=4,
	ENUM_AUDIO_AO_ECHO_30MS=6,
	ENUM_AUDIO_AO_ECHO_40MS=8,
	ENUM_AUDIO_AO_ECHO_50MS=9,
	ENUM_AUDIO_AO_ECHO_60MS=11,
	ENUM_AUDIO_AO_ECHO_70MS=13,
	ENUM_AUDIO_AO_ECHO_80MS=15,
	ENUM_AUDIO_AO_ECHO_90MS=17,
	ENUM_AUDIO_AO_ECHO_100MS=19,
	ENUM_AUDIO_AO_ECHO_110MS=21,
	ENUM_AUDIO_AO_ECHO_120MS=23,
	ENUM_AUDIO_AO_ECHO_130MS=24,
	ENUM_AUDIO_AO_ECHO_140MS=26,
	ENUM_AUDIO_AO_ECHO_150MS=28,
	ENUM_AUDIO_AO_ECHO_160MS=30,
	ENUM_AUDIO_AO_ECHO_170MS=32,
	ENUM_AUDIO_AO_ECHO_180MS=34,
	ENUM_AUDIO_AO_ECHO_190MS=36,
	ENUM_AUDIO_AO_ECHO_200MS=38,
	ENUM_AUDIO_AO_ECHO_215MS=41,
	ENUM_AUDIO_AO_ECHO_230MS=43,
	ENUM_AUDIO_AO_ECHO_240MS=45,
	ENUM_AUDIO_AO_ECHO_250MS=47,
	ENUM_AUDIO_AO_ECHO_260MS=49,
	ENUM_AUDIO_AO_ECHO_270MS=51,
	ENUM_AUDIO_AO_ECHO_285MS=54,
	ENUM_AUDIO_AO_ECHO_300MS=56,
	ENUM_AUDIO_AO_ECHO_310MS=58,
	ENUM_AUDIO_AO_ECHO_320MS=60,
	ENUM_AUDIO_AO_ECHO_330MS=62
};

enum AUDIO_HDMI_CODING_TYPE
{
	AUDIO_HDMI_CODING_TYPE_REFER=0,			/* Refer to Steam Header */
	AUDIO_HDMI_CODING_TYPE_PCM=1,			/* IEC60958 PCM */
	AUDIO_HDMI_CODING_TYPE_AC_3=2,			/* AC-3 */
	AUDIO_HDMI_CODING_TYPE_MPEG1=3,			/* MPEG1 (Layers 1 & 2) */
	AUDIO_HDMI_CODING_TYPE_MP3=4,			/* MP3 (MPEG1 Layer 3) */
	AUDIO_HDMI_CODING_TYPE_MPEG2=5,			/* MPEG2 (multichannel) */
	AUDIO_HDMI_CODING_TYPE_AAC=6,			/* AAC */
	AUDIO_HDMI_CODING_TYPE_DTS=7,			/* DTS */
	AUDIO_HDMI_CODING_TYPE_ATRAC=8,			/* ATRAC */

	AUDIO_HDMI_CODING_TYPE_ONE_BIT_AUDIO=9,	/* ONE BIT AUDIO */
	AUDIO_HDMI_CODING_TYPE_DDP=10,			/* DDP */

	AUDIO_HDMI_CODING_TYPE_DTSHD=11,		/* DTSHD */
	AUDIO_HDMI_CODING_TYPE_MLP=12			/* MLP */
};

enum AUDIO_HDMI_CHANNEL_COUNT
{
	AUDIO_HDMI_CHANNEL_COUNT_REFER=0,		/* Refer to Steam Header */
	AUDIO_HDMI_CHANNEL_COUNT_2=1,			/* 2 ch */
	AUDIO_HDMI_CHANNEL_COUNT_3=2,			/* 3 ch */
	AUDIO_HDMI_CHANNEL_COUNT_4=3,			/* 4 ch */
	AUDIO_HDMI_CHANNEL_COUNT_5=4,			/* 5 ch */
	AUDIO_HDMI_CHANNEL_COUNT_6=5,			/* 6 ch */
	AUDIO_HDMI_CHANNEL_COUNT_7=6,			/* 7 ch */
	AUDIO_HDMI_CHANNEL_COUNT_8=7			/* 8 ch */
};

enum AUDIO_HDMI_SAMPLING_FREQ
{
	AUDIO_HDMI_SAMPLING_FREQ_REFER=0,		/* Refer to Steam Header */
	AUDIO_HDMI_SAMPLING_FREQ_32K=1,			/* 32kHZ */
	AUDIO_HDMI_SAMPLING_FREQ_44K1=2,		/* 44.1kHZ (CD) */
	AUDIO_HDMI_SAMPLING_FREQ_48K=3,			/* 48kHZ */
	AUDIO_HDMI_SAMPLING_FREQ_88K2=4,		/* 88.2kHZ */
	AUDIO_HDMI_SAMPLING_FREQ_96K=5,			/* 96kHZ */
	AUDIO_HDMI_SAMPLING_FREQ_176K4=6,		/* 176.4kHZ */
	AUDIO_HDMI_SAMPLING_FREQ_192K=7			/* 192kHZ */

};

enum AUDIO_HDMI_SAMPLE_SIZE
{
	AUDIO_HDMI_SAMPLE_SIZE_REFER=0,			/* Refer to Steam Header */
	AUDIO_HDMI_SAMPLE_SIZE_16BIT=1,			/* 16 bit */
	AUDIO_HDMI_SAMPLE_SIZE_20BIT=2,			/* 20 bit */
	AUDIO_HDMI_SAMPLE_SIZE_24BIT=3			/* 24 bit */
};

/* only useful on multi-channel LPCM */

struct AUDIO_HDMI_SETTING_INFO
{
	AUDIO_HDMI_CODING_TYPE		coding_type;
	AUDIO_HDMI_CHANNEL_COUNT	channel_count;
	AUDIO_HDMI_SAMPLING_FREQ	sample_freq;
	AUDIO_HDMI_SAMPLE_SIZE		sample_size;
	unsigned int			max_bit_rate_divided_by_8KHz;	/* unit : 8 kHZ */

	/* only useful on multi-channel LPCM
	 * multi-channel lpcm speaker placement
	 * 1 = allocated, 0 = none
	 *
	 * BYTE 0 : bit 0 = FL/FR
	 *          bit 1 = LFE
	 *          bit 2 = FC
	 *          bit 3 = RL/RR
	 *          bit 4 = RC
	 *          bit 5 = FLC/FRC
	 *          bit 6 = RLC/RRC
	 *          bit 7 = reserved
	 * BYTE 1 : reserved
	 * BYTE 2 : reserved
	 */
	unsigned char			lpcm_speaker_allocation[3];

	/* multi-channel lpcm level shift value
	 * for 0 - 15 dB only
	 */
	unsigned int			lpcm_level_shift_value;	/* unit : dB (0 - 15) */

	/* mute setting*/
	unsigned char			mute;			/* 1: mute */
};

enum ENUM_AUDIO_HDMI_EDID_ENABLE {
	ENUM_AUDIO_EDID_DISABLE = 0,
	ENUM_AUDIO_EDID_ENABLE = 1,
	ENUM_AUDIO_EDID_START = 2,
	ENUM_AUDIO_EDID_END = 3
};

struct AUDIO_HDMI_OUT_EDID_DATA
{
	long HDMI_output_enable;
	long EDID_DATA_addr;
};

struct AUDIO_HDMI_OUT_EDID_DATA2
{
	long Version;
	long HDMI_output_enable;
	long EDID_DATA_addr;
};

struct AUDIO_HDMI_OUT_VSDB_DATA {
 	long HDMI_VSDB_delay;
};

enum HDMI_VIDEO_TYPE
{
	ENUM_HDMI_VIDEO_TYPE_SD = 0,
	ENUM_HDMI_VIDEO_TYPE_HD = 1
};

struct HDMI_INFO
{
	long video_type;
};


enum AUDIO_MIC_DELAY_SLOT
{
    ENUM_MIC_DELAY_SLOT_LEVEL_0 = 0,
    ENUM_MIC_DELAY_SLOT_LEVEL_1 = 2,
    ENUM_MIC_DELAY_SLOT_LEVEL_2 = 4,
    ENUM_MIC_DELAY_SLOT_LEVEL_3 = 6,
    ENUM_MIC_DELAY_SLOT_LEVEL_4 = 8,
    ENUM_MIC_DELAY_SLOT_LEVEL_5 = 10,
    ENUM_MIC_DELAY_SLOT_LEVEL_6 = 12,
    ENUM_MIC_DELAY_SLOT_LEVEL_7 = 14,
    ENUM_MIC_DELAY_SLOT_LEVEL_8 = 16,
    ENUM_MIC_DELAY_SLOT_LEVEL_9 = 18,
    ENUM_MIC_DELAY_SLOT_LEVEL_10 = 20,
    ENUM_MIC_DELAY_SLOT_LEVEL_11 = 22,
    ENUM_MIC_DELAY_SLOT_LEVEL_12 = 24,
    ENUM_MIC_DELAY_SLOT_LEVEL_13 = 26,
    ENUM_MIC_DELAY_SLOT_LEVEL_14 = 28,
    ENUM_MIC_DELAY_SLOT_LEVEL_15 = 30,
    ENUM_MIC_DELAY_SLOT_LEVEL_16 = 32,
    ENUM_MIC_DELAY_SLOT_LEVEL_17 = 34,
    ENUM_MIC_DELAY_SLOT_LEVEL_18 = 36,
    ENUM_MIC_DELAY_SLOT_LEVEL_19 = 38,
    ENUM_MIC_DELAY_SLOT_LEVEL_20 = 40
};

enum AUDIO_VOLUME_LEVEL
{
	ENUM_AUDIO_VOLUME_LEVEL_0_DB    =0,
	ENUM_AUDIO_VOLUME_LEVEL_N1_DB   =1,
	ENUM_AUDIO_VOLUME_LEVEL_N2_DB   =2,
	ENUM_AUDIO_VOLUME_LEVEL_N3_DB   =3,
	ENUM_AUDIO_VOLUME_LEVEL_N4_DB   =4,
	ENUM_AUDIO_VOLUME_LEVEL_N5_DB   =5,
	ENUM_AUDIO_VOLUME_LEVEL_N6_DB   =6,
	ENUM_AUDIO_VOLUME_LEVEL_N7_DB   =7,
	ENUM_AUDIO_VOLUME_LEVEL_N8_DB   =8,
	ENUM_AUDIO_VOLUME_LEVEL_N9_DB   =9,
	ENUM_AUDIO_VOLUME_LEVEL_N10_DB  =10,
	ENUM_AUDIO_VOLUME_LEVEL_N11_DB  =11,
	ENUM_AUDIO_VOLUME_LEVEL_N12_DB  =12,
	ENUM_AUDIO_VOLUME_LEVEL_N13_DB  =13,
	ENUM_AUDIO_VOLUME_LEVEL_N14_DB  =14,
	ENUM_AUDIO_VOLUME_LEVEL_N15_DB  =15,
	ENUM_AUDIO_VOLUME_LEVEL_N16_DB  =16,
	ENUM_AUDIO_VOLUME_LEVEL_N17_DB  =17,
	ENUM_AUDIO_VOLUME_LEVEL_N18_DB  =18,
	ENUM_AUDIO_VOLUME_LEVEL_N19_DB  =19,
	ENUM_AUDIO_VOLUME_LEVEL_N20_DB  =20,
	ENUM_AUDIO_VOLUME_LEVEL_N21_DB  =21,
	ENUM_AUDIO_VOLUME_LEVEL_N22_DB  =22,
	ENUM_AUDIO_VOLUME_LEVEL_N23_DB  =23,
	ENUM_AUDIO_VOLUME_LEVEL_N24_DB  =24,
	ENUM_AUDIO_VOLUME_LEVEL_N25_DB  =25,
	ENUM_AUDIO_VOLUME_LEVEL_N26_DB  =26,
	ENUM_AUDIO_VOLUME_LEVEL_N30_DB  =27,
	ENUM_AUDIO_VOLUME_LEVEL_N36_DB  =28,
	ENUM_AUDIO_VOLUME_LEVEL_N44_DB  =29,
	ENUM_AUDIO_VOLUME_LEVEL_N52_DB  =30,
	ENUM_AUDIO_VOLUME_LEVEL_MUTE    =31
};

enum AUDIO_DVOL_LEVEL
{
 ENUM_AUDIO_DVOL_MUTE = 100,
 ENUM_AUDIO_DVOL_KMINUS72p0DB = 101,
 ENUM_AUDIO_DVOL_KMINUS71p75DB = 102,
 ENUM_AUDIO_DVOL_KMINUS71p50DB = 103,
 ENUM_AUDIO_DVOL_KMINUS71p25DB = 104,
 ENUM_AUDIO_DVOL_KMINUS71p0DB = 105,
 ENUM_AUDIO_DVOL_KMINUS70p75DB = 106,
 ENUM_AUDIO_DVOL_KMINUS70p50DB = 107,
 ENUM_AUDIO_DVOL_KMINUS70p25DB = 108,
 ENUM_AUDIO_DVOL_KMINUS70p0DB = 109,
 ENUM_AUDIO_DVOL_KMINUS69p75DB = 110,
 ENUM_AUDIO_DVOL_KMINUS69p50DB = 111,
 ENUM_AUDIO_DVOL_KMINUS69p25DB = 112,
 ENUM_AUDIO_DVOL_KMINUS69p0DB = 113,
 ENUM_AUDIO_DVOL_KMINUS68p75DB = 114,
 ENUM_AUDIO_DVOL_KMINUS68p50DB = 115,
 ENUM_AUDIO_DVOL_KMINUS68p25DB = 116,
 ENUM_AUDIO_DVOL_KMINUS68p0DB = 117,
 ENUM_AUDIO_DVOL_KMINUS67p75DB = 118,
 ENUM_AUDIO_DVOL_KMINUS67p50DB = 119,
 ENUM_AUDIO_DVOL_KMINUS67p25DB = 120,
 ENUM_AUDIO_DVOL_KMINUS67p0DB = 121,
 ENUM_AUDIO_DVOL_KMINUS66p75DB = 122,
 ENUM_AUDIO_DVOL_KMINUS66p50DB = 123,
 ENUM_AUDIO_DVOL_KMINUS66p25DB = 124,
 ENUM_AUDIO_DVOL_KMINUS66p0DB = 125,
 ENUM_AUDIO_DVOL_KMINUS65p75DB = 126,
 ENUM_AUDIO_DVOL_KMINUS65p50DB = 127,
 ENUM_AUDIO_DVOL_KMINUS65p25DB = 128,
 ENUM_AUDIO_DVOL_KMINUS65p0DB = 129,
 ENUM_AUDIO_DVOL_KMINUS64p75DB = 130,
 ENUM_AUDIO_DVOL_KMINUS64p50DB = 131,
 ENUM_AUDIO_DVOL_KMINUS64p25DB = 132,
 ENUM_AUDIO_DVOL_KMINUS64p0DB = 133,
 ENUM_AUDIO_DVOL_KMINUS63p75DB = 134,
 ENUM_AUDIO_DVOL_KMINUS63p50DB = 135,
 ENUM_AUDIO_DVOL_KMINUS63p25DB = 136,
 ENUM_AUDIO_DVOL_KMINUS63p0DB = 137,
 ENUM_AUDIO_DVOL_KMINUS62p75DB = 138,
 ENUM_AUDIO_DVOL_KMINUS62p50DB = 139,
 ENUM_AUDIO_DVOL_KMINUS62p25DB = 140,
 ENUM_AUDIO_DVOL_KMINUS62p0DB = 141,
 ENUM_AUDIO_DVOL_KMINUS61p75DB = 142,
 ENUM_AUDIO_DVOL_KMINUS61p50DB = 143,
 ENUM_AUDIO_DVOL_KMINUS61p25DB = 144,
 ENUM_AUDIO_DVOL_KMINUS61p0DB = 145,
 ENUM_AUDIO_DVOL_KMINUS60p75DB = 146,
 ENUM_AUDIO_DVOL_KMINUS60p50DB = 147,
 ENUM_AUDIO_DVOL_KMINUS60p25DB = 148,
 ENUM_AUDIO_DVOL_KMINUS60p0DB = 149,
 ENUM_AUDIO_DVOL_KMINUS59p75DB = 150,
 ENUM_AUDIO_DVOL_KMINUS59p50DB = 151,
 ENUM_AUDIO_DVOL_KMINUS59p25DB = 152,
 ENUM_AUDIO_DVOL_KMINUS59p0DB = 153,
 ENUM_AUDIO_DVOL_KMINUS58p75DB = 154,
 ENUM_AUDIO_DVOL_KMINUS58p50DB = 155,
 ENUM_AUDIO_DVOL_KMINUS58p25DB = 156,
 ENUM_AUDIO_DVOL_KMINUS58p0DB = 157,
 ENUM_AUDIO_DVOL_KMINUS57p75DB = 158,
 ENUM_AUDIO_DVOL_KMINUS57p50DB = 159,
 ENUM_AUDIO_DVOL_KMINUS57p25DB = 160,
 ENUM_AUDIO_DVOL_KMINUS57p0DB = 161,
 ENUM_AUDIO_DVOL_KMINUS56p75DB = 162,
 ENUM_AUDIO_DVOL_KMINUS56p50DB = 163,
 ENUM_AUDIO_DVOL_KMINUS56p25DB = 164,
 ENUM_AUDIO_DVOL_KMINUS56p0DB = 165,
 ENUM_AUDIO_DVOL_KMINUS55p75DB = 166,
 ENUM_AUDIO_DVOL_KMINUS55p50DB = 167,
 ENUM_AUDIO_DVOL_KMINUS55p25DB = 168,
 ENUM_AUDIO_DVOL_KMINUS55p0DB = 169,
 ENUM_AUDIO_DVOL_KMINUS54p75DB = 170,
 ENUM_AUDIO_DVOL_KMINUS54p50DB = 171,
 ENUM_AUDIO_DVOL_KMINUS54p25DB = 172,
 ENUM_AUDIO_DVOL_KMINUS54p0DB = 173,
 ENUM_AUDIO_DVOL_KMINUS53p75DB = 174,
 ENUM_AUDIO_DVOL_KMINUS53p50DB = 175,
 ENUM_AUDIO_DVOL_KMINUS53p25DB = 176,
 ENUM_AUDIO_DVOL_KMINUS53p0DB = 177,
 ENUM_AUDIO_DVOL_KMINUS52p75DB = 178,
 ENUM_AUDIO_DVOL_KMINUS52p50DB = 179,
 ENUM_AUDIO_DVOL_KMINUS52p25DB = 180,
 ENUM_AUDIO_DVOL_KMINUS52p0DB = 181,
 ENUM_AUDIO_DVOL_KMINUS51p75DB = 182,
 ENUM_AUDIO_DVOL_KMINUS51p50DB = 183,
 ENUM_AUDIO_DVOL_KMINUS51p25DB = 184,
 ENUM_AUDIO_DVOL_KMINUS51p0DB = 185,
 ENUM_AUDIO_DVOL_KMINUS50p75DB = 186,
 ENUM_AUDIO_DVOL_KMINUS50p50DB = 187,
 ENUM_AUDIO_DVOL_KMINUS50p25DB = 188,
 ENUM_AUDIO_DVOL_KMINUS50p0DB = 189,
 ENUM_AUDIO_DVOL_KMINUS49p75DB = 190,
 ENUM_AUDIO_DVOL_KMINUS49p50DB = 191,
 ENUM_AUDIO_DVOL_KMINUS49p25DB = 192,
 ENUM_AUDIO_DVOL_KMINUS49p0DB = 193,
 ENUM_AUDIO_DVOL_KMINUS48p75DB = 194,
 ENUM_AUDIO_DVOL_KMINUS48p50DB = 195,
 ENUM_AUDIO_DVOL_KMINUS48p25DB = 196,
 ENUM_AUDIO_DVOL_KMINUS48p0DB = 197,
 ENUM_AUDIO_DVOL_KMINUS47p75DB = 198,
 ENUM_AUDIO_DVOL_KMINUS47p50DB = 199,
 ENUM_AUDIO_DVOL_KMINUS47p25DB = 200,
 ENUM_AUDIO_DVOL_KMINUS47p0DB = 201,
 ENUM_AUDIO_DVOL_KMINUS46p75DB = 202,
 ENUM_AUDIO_DVOL_KMINUS46p50DB = 203,
 ENUM_AUDIO_DVOL_KMINUS46p25DB = 204,
 ENUM_AUDIO_DVOL_KMINUS46p0DB = 205,
 ENUM_AUDIO_DVOL_KMINUS45p75DB = 206,
 ENUM_AUDIO_DVOL_KMINUS45p50DB = 207,
 ENUM_AUDIO_DVOL_KMINUS45p25DB = 208,
 ENUM_AUDIO_DVOL_KMINUS45p0DB = 209,
 ENUM_AUDIO_DVOL_KMINUS44p75DB = 210,
 ENUM_AUDIO_DVOL_KMINUS44p50DB = 211,
 ENUM_AUDIO_DVOL_KMINUS44p25DB = 212,
 ENUM_AUDIO_DVOL_KMINUS44p0DB = 213,
 ENUM_AUDIO_DVOL_KMINUS43p75DB = 214,
 ENUM_AUDIO_DVOL_KMINUS43p50DB = 215,
 ENUM_AUDIO_DVOL_KMINUS43p25DB = 216,
 ENUM_AUDIO_DVOL_KMINUS43p0DB = 217,
 ENUM_AUDIO_DVOL_KMINUS42p75DB = 218,
 ENUM_AUDIO_DVOL_KMINUS42p50DB = 219,
 ENUM_AUDIO_DVOL_KMINUS42p25DB = 220,
 ENUM_AUDIO_DVOL_KMINUS42p0DB = 221,
 ENUM_AUDIO_DVOL_KMINUS41p75DB = 222,
 ENUM_AUDIO_DVOL_KMINUS41p50DB = 223,
 ENUM_AUDIO_DVOL_KMINUS41p25DB = 224,
 ENUM_AUDIO_DVOL_KMINUS41p0DB = 225,
 ENUM_AUDIO_DVOL_KMINUS40p75DB = 226,
 ENUM_AUDIO_DVOL_KMINUS40p50DB = 227,
 ENUM_AUDIO_DVOL_KMINUS40p25DB = 228,
 ENUM_AUDIO_DVOL_KMINUS40p0DB = 229,
 ENUM_AUDIO_DVOL_KMINUS39p75DB = 230,
 ENUM_AUDIO_DVOL_KMINUS39p50DB = 231,
 ENUM_AUDIO_DVOL_KMINUS39p25DB = 232,
 ENUM_AUDIO_DVOL_KMINUS39p0DB = 233,
 ENUM_AUDIO_DVOL_KMINUS38p75DB = 234,
 ENUM_AUDIO_DVOL_KMINUS38p50DB = 235,
 ENUM_AUDIO_DVOL_KMINUS38p25DB = 236,
 ENUM_AUDIO_DVOL_KMINUS38p0DB = 237,
 ENUM_AUDIO_DVOL_KMINUS37p75DB = 238,
 ENUM_AUDIO_DVOL_KMINUS37p50DB = 239,
 ENUM_AUDIO_DVOL_KMINUS37p25DB = 240,
 ENUM_AUDIO_DVOL_KMINUS37p0DB = 241,
 ENUM_AUDIO_DVOL_KMINUS36p75DB = 242,
 ENUM_AUDIO_DVOL_KMINUS36p50DB = 243,
 ENUM_AUDIO_DVOL_KMINUS36p25DB = 244,
 ENUM_AUDIO_DVOL_KMINUS36p0DB = 245,
 ENUM_AUDIO_DVOL_KMINUS35p75DB = 246,
 ENUM_AUDIO_DVOL_KMINUS35p50DB = 247,
 ENUM_AUDIO_DVOL_KMINUS35p25DB = 248,
 ENUM_AUDIO_DVOL_KMINUS35p0DB = 249,
 ENUM_AUDIO_DVOL_KMINUS34p75DB = 250,
 ENUM_AUDIO_DVOL_KMINUS34p50DB = 251,
 ENUM_AUDIO_DVOL_KMINUS34p25DB = 252,
 ENUM_AUDIO_DVOL_KMINUS34p0DB = 253,
 ENUM_AUDIO_DVOL_KMINUS33p75DB = 254,
 ENUM_AUDIO_DVOL_KMINUS33p50DB = 255,
 ENUM_AUDIO_DVOL_KMINUS33p25DB = 256,
 ENUM_AUDIO_DVOL_KMINUS33p0DB = 257,
 ENUM_AUDIO_DVOL_KMINUS32p75DB = 258,
 ENUM_AUDIO_DVOL_KMINUS32p50DB = 259,
 ENUM_AUDIO_DVOL_KMINUS32p25DB = 260,
 ENUM_AUDIO_DVOL_KMINUS32p0DB = 261,
 ENUM_AUDIO_DVOL_KMINUS31p75DB = 262,
 ENUM_AUDIO_DVOL_KMINUS31p50DB = 263,
 ENUM_AUDIO_DVOL_KMINUS31p25DB = 264,
 ENUM_AUDIO_DVOL_KMINUS31p0DB = 265,
 ENUM_AUDIO_DVOL_KMINUS30p75DB = 266,
 ENUM_AUDIO_DVOL_KMINUS30p50DB = 267,
 ENUM_AUDIO_DVOL_KMINUS30p25DB = 268,
 ENUM_AUDIO_DVOL_KMINUS30p0DB = 269,
 ENUM_AUDIO_DVOL_KMINUS29p75DB = 270,
 ENUM_AUDIO_DVOL_KMINUS29p50DB = 271,
 ENUM_AUDIO_DVOL_KMINUS29p25DB = 272,
 ENUM_AUDIO_DVOL_KMINUS29p0DB = 273,
 ENUM_AUDIO_DVOL_KMINUS28p75DB = 274,
 ENUM_AUDIO_DVOL_KMINUS28p50DB = 275,
 ENUM_AUDIO_DVOL_KMINUS28p25DB = 276,
 ENUM_AUDIO_DVOL_KMINUS28p0DB = 277,
 ENUM_AUDIO_DVOL_KMINUS27p75DB = 278,
 ENUM_AUDIO_DVOL_KMINUS27p50DB = 279,
 ENUM_AUDIO_DVOL_KMINUS27p25DB = 280,
 ENUM_AUDIO_DVOL_KMINUS27p0DB = 281,
 ENUM_AUDIO_DVOL_KMINUS26p75DB = 282,
 ENUM_AUDIO_DVOL_KMINUS26p50DB = 283,
 ENUM_AUDIO_DVOL_KMINUS26p25DB = 284,
 ENUM_AUDIO_DVOL_KMINUS26p0DB = 285,
 ENUM_AUDIO_DVOL_KMINUS25p75DB = 286,
 ENUM_AUDIO_DVOL_KMINUS25p50DB = 287,
 ENUM_AUDIO_DVOL_KMINUS25p25DB = 288,
 ENUM_AUDIO_DVOL_KMINUS25p0DB = 289,
 ENUM_AUDIO_DVOL_KMINUS24p75DB = 290,
 ENUM_AUDIO_DVOL_KMINUS24p50DB = 291,
 ENUM_AUDIO_DVOL_KMINUS24p25DB = 292,
 ENUM_AUDIO_DVOL_KMINUS24p0DB = 293,
 ENUM_AUDIO_DVOL_KMINUS23p75DB = 294,
 ENUM_AUDIO_DVOL_KMINUS23p50DB = 295,
 ENUM_AUDIO_DVOL_KMINUS23p25DB = 296,
 ENUM_AUDIO_DVOL_KMINUS23p0DB = 297,
 ENUM_AUDIO_DVOL_KMINUS22p75DB = 298,
 ENUM_AUDIO_DVOL_KMINUS22p50DB = 299,
 ENUM_AUDIO_DVOL_KMINUS22p25DB = 300,
 ENUM_AUDIO_DVOL_KMINUS22p0DB = 301,
 ENUM_AUDIO_DVOL_KMINUS21p75DB = 302,
 ENUM_AUDIO_DVOL_KMINUS21p50DB = 303,
 ENUM_AUDIO_DVOL_KMINUS21p25DB = 304,
 ENUM_AUDIO_DVOL_KMINUS21p0DB = 305,
 ENUM_AUDIO_DVOL_KMINUS20p75DB = 306,
 ENUM_AUDIO_DVOL_KMINUS20p50DB = 307,
 ENUM_AUDIO_DVOL_KMINUS20p25DB = 308,
 ENUM_AUDIO_DVOL_KMINUS20p0DB = 309,
 ENUM_AUDIO_DVOL_KMINUS19p75DB = 310,
 ENUM_AUDIO_DVOL_KMINUS19p50DB = 311,
 ENUM_AUDIO_DVOL_KMINUS19p25DB = 312,
 ENUM_AUDIO_DVOL_KMINUS19p0DB = 313,
 ENUM_AUDIO_DVOL_KMINUS18p75DB = 314,
 ENUM_AUDIO_DVOL_KMINUS18p50DB = 315,
 ENUM_AUDIO_DVOL_KMINUS18p25DB = 316,
 ENUM_AUDIO_DVOL_KMINUS18p0DB = 317,
 ENUM_AUDIO_DVOL_KMINUS17p75DB = 318,
 ENUM_AUDIO_DVOL_KMINUS17p50DB = 319,
 ENUM_AUDIO_DVOL_KMINUS17p25DB = 320,
 ENUM_AUDIO_DVOL_KMINUS17p0DB = 321,
 ENUM_AUDIO_DVOL_KMINUS16p75DB = 322,
 ENUM_AUDIO_DVOL_KMINUS16p50DB = 323,
 ENUM_AUDIO_DVOL_KMINUS16p25DB = 324,
 ENUM_AUDIO_DVOL_KMINUS16p0DB = 325,
 ENUM_AUDIO_DVOL_KMINUS15p75DB = 326,
 ENUM_AUDIO_DVOL_KMINUS15p50DB = 327,
 ENUM_AUDIO_DVOL_KMINUS15p25DB = 328,
 ENUM_AUDIO_DVOL_KMINUS15p0DB = 329,
 ENUM_AUDIO_DVOL_KMINUS14p75DB = 330,
 ENUM_AUDIO_DVOL_KMINUS14p50DB = 331,
 ENUM_AUDIO_DVOL_KMINUS14p25DB = 332,
 ENUM_AUDIO_DVOL_KMINUS14p0DB = 333,
 ENUM_AUDIO_DVOL_KMINUS13p75DB = 334,
 ENUM_AUDIO_DVOL_KMINUS13p50DB = 335,
 ENUM_AUDIO_DVOL_KMINUS13p25DB = 336,
 ENUM_AUDIO_DVOL_KMINUS13p0DB = 337,
 ENUM_AUDIO_DVOL_KMINUS12p75DB = 338,
 ENUM_AUDIO_DVOL_KMINUS12p50DB = 339,
 ENUM_AUDIO_DVOL_KMINUS12p25DB = 340,
 ENUM_AUDIO_DVOL_KMINUS12p0DB = 341,
 ENUM_AUDIO_DVOL_KMINUS11p75DB = 342,
 ENUM_AUDIO_DVOL_KMINUS11p50DB = 343,
 ENUM_AUDIO_DVOL_KMINUS11p25DB = 344,
 ENUM_AUDIO_DVOL_KMINUS11p0DB = 345,
 ENUM_AUDIO_DVOL_KMINUS10p75DB = 346,
 ENUM_AUDIO_DVOL_KMINUS10p50DB = 347,
 ENUM_AUDIO_DVOL_KMINUS10p25DB = 348,
 ENUM_AUDIO_DVOL_KMINUS10p0DB = 349,
 ENUM_AUDIO_DVOL_KMINUS9p75DB = 350,
 ENUM_AUDIO_DVOL_KMINUS9p50DB = 351,
 ENUM_AUDIO_DVOL_KMINUS9p25DB = 352,
 ENUM_AUDIO_DVOL_KMINUS9p0DB = 353,
 ENUM_AUDIO_DVOL_KMINUS8p75DB = 354,
 ENUM_AUDIO_DVOL_KMINUS8p50DB = 355,
 ENUM_AUDIO_DVOL_KMINUS8p25DB = 356,
 ENUM_AUDIO_DVOL_KMINUS8p0DB = 357,
 ENUM_AUDIO_DVOL_KMINUS7p75DB = 358,
 ENUM_AUDIO_DVOL_KMINUS7p50DB = 359,
 ENUM_AUDIO_DVOL_KMINUS7p25DB = 360,
 ENUM_AUDIO_DVOL_KMINUS7p0DB = 361,
 ENUM_AUDIO_DVOL_KMINUS6p75DB = 362,
 ENUM_AUDIO_DVOL_KMINUS6p50DB = 363,
 ENUM_AUDIO_DVOL_KMINUS6p25DB = 364,
 ENUM_AUDIO_DVOL_KMINUS6p0DB = 365,
 ENUM_AUDIO_DVOL_KMINUS5p75DB = 366,
 ENUM_AUDIO_DVOL_KMINUS5p50DB = 367,
 ENUM_AUDIO_DVOL_KMINUS5p25DB = 368,
 ENUM_AUDIO_DVOL_KMINUS5p0DB = 369,
 ENUM_AUDIO_DVOL_KMINUS4p75DB = 370,
 ENUM_AUDIO_DVOL_KMINUS4p50DB = 371,
 ENUM_AUDIO_DVOL_KMINUS4p25DB = 372,
 ENUM_AUDIO_DVOL_KMINUS4p0DB = 373,
 ENUM_AUDIO_DVOL_KMINUS3p75DB = 374,
 ENUM_AUDIO_DVOL_KMINUS3p50DB = 375,
 ENUM_AUDIO_DVOL_KMINUS3p25DB = 376,
 ENUM_AUDIO_DVOL_KMINUS3p0DB = 377,
 ENUM_AUDIO_DVOL_KMINUS2p75DB = 378,
 ENUM_AUDIO_DVOL_KMINUS2p50DB = 379,
 ENUM_AUDIO_DVOL_KMINUS2p25DB = 380,
 ENUM_AUDIO_DVOL_KMINUS2p0DB = 381,
 ENUM_AUDIO_DVOL_KMINUS1p75DB = 382,
 ENUM_AUDIO_DVOL_KMINUS1p50DB = 383,
 ENUM_AUDIO_DVOL_KMINUS1p25DB = 384,
 ENUM_AUDIO_DVOL_KMINUS1p0DB = 385,
 ENUM_AUDIO_DVOL_KMINUS0p75DB = 386,
 ENUM_AUDIO_DVOL_KMINUS0p50DB = 387,
 ENUM_AUDIO_DVOL_KMINUS0p25DB = 388,
 ENUM_AUDIO_DVOL_K0p0DB = 389,
 ENUM_AUDIO_DVOL_K0p25DB = 390,
 ENUM_AUDIO_DVOL_K0p50DB = 391,
 ENUM_AUDIO_DVOL_K0p75DB = 392,
 ENUM_AUDIO_DVOL_K1p0DB = 393,
 ENUM_AUDIO_DVOL_K1p25DB = 394,
 ENUM_AUDIO_DVOL_K1p50DB = 395,
 ENUM_AUDIO_DVOL_K1p75DB = 396,
 ENUM_AUDIO_DVOL_K2p0DB = 397,
 ENUM_AUDIO_DVOL_K2p25DB = 398,
 ENUM_AUDIO_DVOL_K2p50DB = 399,
 ENUM_AUDIO_DVOL_K2p75DB = 400,
 ENUM_AUDIO_DVOL_K3p0DB = 401,
 ENUM_AUDIO_DVOL_K3p25DB = 402,
 ENUM_AUDIO_DVOL_K3p50DB = 403,
 ENUM_AUDIO_DVOL_K3p75DB = 404,
 ENUM_AUDIO_DVOL_K4p0DB = 405,
 ENUM_AUDIO_DVOL_K4p25DB = 406,
 ENUM_AUDIO_DVOL_K4p50DB = 407,
 ENUM_AUDIO_DVOL_K4p75DB = 408,
 ENUM_AUDIO_DVOL_K5p0DB = 409,
 ENUM_AUDIO_DVOL_K5p25DB = 410,
 ENUM_AUDIO_DVOL_K5p50DB = 411,
 ENUM_AUDIO_DVOL_K5p75DB = 412,
 ENUM_AUDIO_DVOL_K6p0DB = 413,
 ENUM_AUDIO_DVOL_K6p25DB = 414,
 ENUM_AUDIO_DVOL_K6p50DB = 415,
 ENUM_AUDIO_DVOL_K6p75DB = 416,
 ENUM_AUDIO_DVOL_K7p0DB = 417,
 ENUM_AUDIO_DVOL_K7p25DB = 418,
 ENUM_AUDIO_DVOL_K7p50DB = 419,
 ENUM_AUDIO_DVOL_K7p75DB = 420,
 ENUM_AUDIO_DVOL_K8p0DB = 421,
 ENUM_AUDIO_DVOL_K8p25DB = 422,
 ENUM_AUDIO_DVOL_K8p50DB = 423,
 ENUM_AUDIO_DVOL_K8p75DB = 424,
 ENUM_AUDIO_DVOL_K9p0DB = 425,
 ENUM_AUDIO_DVOL_K9p25DB = 426,
 ENUM_AUDIO_DVOL_K9p50DB = 427,
 ENUM_AUDIO_DVOL_K9p75DB = 428,
 ENUM_AUDIO_DVOL_K10p0DB = 429,
 ENUM_AUDIO_DVOL_K10p25DB = 430,
 ENUM_AUDIO_DVOL_K10p50DB = 431,
 ENUM_AUDIO_DVOL_K10p75DB = 432,
 ENUM_AUDIO_DVOL_K11p0DB = 433,
 ENUM_AUDIO_DVOL_K11p25DB = 434,
 ENUM_AUDIO_DVOL_K11p50DB = 435,
 ENUM_AUDIO_DVOL_K11p75DB = 436,
 ENUM_AUDIO_DVOL_K12p0DB = 437,
 ENUM_AUDIO_DVOL_K12p25DB = 438,
 ENUM_AUDIO_DVOL_K12p50DB = 439,
 ENUM_AUDIO_DVOL_K12p75DB = 440,
 ENUM_AUDIO_DVOL_K13p0DB = 441,
 ENUM_AUDIO_DVOL_K13p25DB = 442,
 ENUM_AUDIO_DVOL_K13p50DB = 443,
 ENUM_AUDIO_DVOL_K13p75DB = 444,
 ENUM_AUDIO_DVOL_K14p0DB = 445,
 ENUM_AUDIO_DVOL_K14p25DB = 446,
 ENUM_AUDIO_DVOL_K14p50DB = 447,
 ENUM_AUDIO_DVOL_K14p75DB = 448,
 ENUM_AUDIO_DVOL_K15p0DB = 449,
 ENUM_AUDIO_DVOL_K15p25DB = 450,
 ENUM_AUDIO_DVOL_K15p50DB = 451,
 ENUM_AUDIO_DVOL_K15p75DB = 452,
 ENUM_AUDIO_DVOL_K16p0DB = 453,
 ENUM_AUDIO_DVOL_K16p25DB = 454,
 ENUM_AUDIO_DVOL_K16p50DB = 455,
 ENUM_AUDIO_DVOL_K16p75DB = 456,
 ENUM_AUDIO_DVOL_K17p0DB = 457,
 ENUM_AUDIO_DVOL_K17p25DB = 458,
 ENUM_AUDIO_DVOL_K17p50DB = 459,
 ENUM_AUDIO_DVOL_K17p75DB = 460,
 ENUM_AUDIO_DVOL_K18p0DB = 461,
 ENUM_AUDIO_DVOL_K18p25DB = 462,
 ENUM_AUDIO_DVOL_K18p50DB = 463,
 ENUM_AUDIO_DVOL_K18p75DB = 464,
 ENUM_AUDIO_DVOL_K19p0DB = 465,
 ENUM_AUDIO_DVOL_K19p25DB = 466,
 ENUM_AUDIO_DVOL_K19p50DB = 467,
 ENUM_AUDIO_DVOL_K19p75DB = 468,
 ENUM_AUDIO_DVOL_K20p0DB = 469,
 ENUM_AUDIO_DVOL_K20p25DB = 470,
 ENUM_AUDIO_DVOL_K20p50DB = 471,
 ENUM_AUDIO_DVOL_K20p75DB = 472,
 ENUM_AUDIO_DVOL_K21p0DB = 473,
 ENUM_AUDIO_DVOL_K21p25DB = 474,
 ENUM_AUDIO_DVOL_K21p50DB = 475,
 ENUM_AUDIO_DVOL_K21p75DB = 476,
 ENUM_AUDIO_DVOL_K22p0DB = 477,
 ENUM_AUDIO_DVOL_K22p25DB = 478,
 ENUM_AUDIO_DVOL_K22p50DB = 479,
 ENUM_AUDIO_DVOL_K22p75DB = 480,
 ENUM_AUDIO_DVOL_K23p0DB = 481,
 ENUM_AUDIO_DVOL_K23p25DB = 482,
 ENUM_AUDIO_DVOL_K23p50DB = 483,
 ENUM_AUDIO_DVOL_K23p75DB = 484,
 ENUM_AUDIO_DVOL_K24p0DB = 485,
 ENUM_AUDIO_DVOL_K24p25DB = 486,
 ENUM_AUDIO_DVOL_K24p50DB = 487,
 ENUM_AUDIO_DVOL_K24p75DB = 488,
 ENUM_AUDIO_DVOL_K25p0DB = 489,
 ENUM_AUDIO_DVOL_K25p25DB = 490,
 ENUM_AUDIO_DVOL_K25p50DB = 491,
 ENUM_AUDIO_DVOL_K25p75DB = 492,
 ENUM_AUDIO_DVOL_K26p0DB = 493,
 ENUM_AUDIO_DVOL_K26p25DB = 494,
 ENUM_AUDIO_DVOL_K26p50DB = 495,
 ENUM_AUDIO_DVOL_K26p75DB = 496,
 ENUM_AUDIO_DVOL_K27p0DB = 497,
 ENUM_AUDIO_DVOL_K27p25DB = 498,
 ENUM_AUDIO_DVOL_K27p50DB = 499,
 ENUM_AUDIO_DVOL_K27p75DB = 500,
 ENUM_AUDIO_DVOL_K28p0DB = 501,
 ENUM_AUDIO_DVOL_K28p25DB = 502,
 ENUM_AUDIO_DVOL_K28p50DB = 503,
 ENUM_AUDIO_DVOL_K28p75DB = 504,
 ENUM_AUDIO_DVOL_K29p0DB = 505,
 ENUM_AUDIO_DVOL_K29p25DB = 506,
 ENUM_AUDIO_DVOL_K29p50DB = 507,
 ENUM_AUDIO_DVOL_K29p75DB = 508,
 ENUM_AUDIO_DVOL_K30p0DB = 509
};

enum AUDIO_LICENSE_CONTROL_MASK
{
	BONDING_OPTION_PA = 0,						/* 0x0 */
	BONDING_OPTION_DA = 15						/* 0xF */
};

struct AUDIO_RPC_DEC_FORMAT_INFO {
       enum AUDIO_DEC_TYPE type;
       u_short nChannels;
       u_short wBitsPerSample;
       long nSamplesPerSec;
       long nAvgBytesPerSec;   /* -1 for VBR ? */
       long reserved[4];      /* reserved[0] for mpeg  (layer<<8)&0xFF00) | (mpegN)&0xFF */
                              /* reserved[0] for ac3   (acmod<<8)&0xFF00) | (lfeon)&0xFF */
};

struct AUDIO_RPC_AIN_FORMAT_INFO {
       enum AUDIO_DEC_TYPE type;
       long reserved[4];
};


struct AUDIO_LICENSE_STATUS_CONFIG {
	long	HighWord;
	long	LowWord;
};

enum AudioCodecControlBit
{
	AUDIO_UNKNOWN_BIT = 0,
	AUDIO_MPEG_DECODER_BIT = 1,
	AUDIO_AC3_DECODER_BIT = 2,
	AUDIO_LPCM_DECODER_BIT = 3,
	AUDIO_DTS_DECODER_BIT = 4,
	AUDIO_WMA_DECODER_BIT = 5,
	AUDIO_AAC_DECODER_BIT = 6,
	AUDIO_VORBIS_DECODER_BIT = 7,
	AUDIO_DV_DECODER_BIT = 8,
	AUDIO_MLP_DECODER_BIT = 9,
	AUDIO_DDP_DECODER_BIT = 10,
	AUDIO_DTS_HD_DECODER_BIT = 11,
	AUDIO_WMA_PRO_DECODER_BIT = 12,
	AUDIO_MP4AAC_DECODER_BIT = 13,
	AUDIO_MP3_PRO_DECODER_BIT = 14,
	AUDIO_MP4HEAAC_DECODER_BIT = 15,
	AUDIO_RAW_AAC_DECODER_BIT = 16,
	AUDIO_RA1_DECODER_BIT = 17,
	AUDIO_RA2_DECODER_BIT = 18,
	AUDIO_ATRAC3_DECODER_BIT = 19,
	AUDIO_COOK_DECODER_BIT = 20,
	AUDIO_LSD_DECODER_BIT = 21,
	AUDIO_ADPCM_DECODER_BIT = 22,
	AUDIO_FLAC_DECODER_BIT = 23,
	AUDIO_ULAW_DECODER_BIT = 24,
	AUDIO_ALAW_DECODER_BIT = 25,
	AUDIO_ALAC_DECODER_BIT = 26,
	AUDIO_DTS_HIGH_RESOLUTION_DECODER_BIT = 27,
	AUDIO_DTS_LBR_DECODER_BIT = 28,
	AUDIO_DTS_MASTER_AUDIO_DECODER_BIT = 29,
	AUDIO_AMR_DECODER_BIT = 30,
	AUDIO_MIDI_DECODER_BIT = 31,
	AUDIO_APE_DECODER_BIT = 32,
	AUDIO_AVS_DECODER_BIT = 33,
	AUDIO_NELLYMOSER_DECODER_BIT = 34,
	AUDIO_WMA_LOSSLESS_DECODER_BIT = 35,
	AUDIO_ILBC_DECODER_BIT = 38,
	AUDIO_SILK_DECODER_BIT = 39,
	AUDIO_AMRWB_DECODER_BIT = 40,
	AUDIO_G729_DECODER_BIT = 41,
	AUDIO_AC3_MULTI_CH_ENCODER_BIT = 56,
	AUDIO_DTS_MULTI_CH_ENCODER_BIT = 57,
	AUDIO_ADPCM_ENCODER_BIT = 58,
	AUDIO_LPCM_ENCODER_BIT = 59,
	AUDIO_AAC_ENCODER_BIT = 60,
	AUDIO_MP2_ENCODER_BIT = 61,
	AUDIO_MP3_ENCODER_BIT = 62,
	AUDIO_AC3_ENCODER_BIT = 63
};


enum AUDIO_ENUM_PRIVAETINFO_TO_SYS
{
    ENUM_PRIVATEINFO_AUDIO_HDMV_UNCERTAIN_TYPE,
    ENUM_PRIVATEINFO_AUDIO_PCM_FORMAT_TYPE,    /* privateInfo[0]=chnum ; privateInfo[1]=samplerate */
    ENUM_PRIVATEINFO_AUDIO_OPEN_FILE,          /* privateInfo[0]=id or filename, privateInfo[1] = checkaddr */
    ENUM_PRIVATEINFO_AUDIO_CLOSE_FILE,         /* privateInfo[0]=id or filename, privateInfo[1] = checkaddr */
    ENUM_PRIVATEINFO_AUDIO_WRITE_FILE,         /* privateInfo[0]=id or filename,  privateInfo[1] = addr, privateInfo[2] = size, privateInfo[3] = checkaddr */
    ENUM_PRIVATEINFO_AUDIO_DECODRER_MASSAGE,   /* privateInfo[0]=msgID (DECODER_MESSAGE_CODE) */
    ENUM_PRIVATEINFO_AUDIO_PROCESS_SRC
};

struct	AUDIO_RPC_PRIVATEINFO_TO_SYS
{
	long	instanceID;
	enum    AUDIO_ENUM_PRIVAETINFO_TO_SYS type;
	long	privateInfo[16];
};

enum AUDIO_ENUM_PRIVAETINFO
{
    ENUM_PRIVATEINFO_AUDIO_FORMAT_PARSER_CAPABILITY, /* input: noneed instanceID privateInfo[0]=AUDIO_DEC_TYPE  output: privateInfo[0]=0 for fail, 1 for ok */
    ENUM_PRIVATEINFO_AUDIO_DECODER_CAPABILITY,       /* no input, output: privateInfo[0] = low 32  privateInfo[1] = high 32  of AudioCodecControlBit */
    ENUM_PRIVATEINFO_AUDIO_CONFIG_CMD_BS_INFO,
    ENUM_PRIVATEINFO_AUDIO_CHECK_LPCM_ENDIANESS,      /* input: noneed instanceID privateInfo[0]=buf privateInfo[1]=size privateInfo[2]:chnum privateInfo[3]:bitwidth output: privateInfo[0]= LPCM_ENDIANESS */
    ENUM_PRIVATEINFO_AUDIO_CONFIG_CMD_AO_DELAY_INFO,
    /*{privateInfo[0] =LEFT_delay_en,
        privateInfo[1] =LEFT_delay_ms,
        privateInfo[2] =CNTR_delay_en,
        privateInfo[3] =CNTR_delay_ms,
        privateInfo[4] =RGHT_delay_en,
        privateInfo[5] =RGHT_delay_ms,
        privateInfo[6] =LSUR_delay_en,
        privateInfo[7] =LSUR_delay_ms,
        privateInfo[8] =RSUR_delay_en,
        privateInfo[9] =RSUR_delay_ms,
        privateInfo[10] =LFE_delay_en,
        privateInfo[11] =LFE_delay_ms} */
    ENUM_PRIVATEINFO_AUDIO_AO_CHANNEL_VOLUME_LEVEL,   /* input: noneed instanceID ,
                                                        privateInfo[0]= Left Front              channel volume level
                                                        privateInfo[1]= Right Front             channel volume level
                                                        privateInfo[2]= Left Surround Rear      channel volume level
                                                        privateInfo[3]= Right Surround Rear     channel volume level
                                                        privateInfo[4]= Center Front            channel volume level
                                                        privateInfo[5]= LFE                     channel volume level
                                                        privateInfo[6]= Left Outside Front      channel volume level
                                                        privateInfo[7]= Right Outside Front     channel volume level */
    ENUM_PRIVATEINFO_AUDIO_GET_FLASH_PIN,       /* request flash pin ID */
    ENUM_PRIVATEINFO_AUDIO_RELEASE_FLASH_PIN,    /* release flash pinID */
    ENUM_PRIVATEINFO_AUDIO_GET_MUTE_N_VOLUME,     /*  privateInfo[0] = mute flag ,privateInfo[1] = volume level */
    ENUM_PRIVATEINFO_AUDIO_AO_MONITOR_FULLNESS,   /* privateInfo[0]= 0 disable or 1 enable ao to monitor queue fullness and do add drop sample */
    ENUM_PRIVATEINFO_AUDIO_CONTROL_FLASH_VOLUME,    /* control the volume of flash pin */
    ENUM_PRIVATEINFO_AUDIO_CONTROL_DAC_SWITCH,	/* decide whether DAC switch */
    ENUM_PRIVATEINFO_AUDIO_CONTROL_AO_GIVE_UP_SET_CLOCK,	/* AO give up to set clock*/
     /*  privateInfo[0] =isAinInput,  0 or 1
        privateInfo[1] =AnalogInputClockSrc , 0 is 64_512 , 1 is spdif, 2 is pll_audio
        privateInfo[2] =pre512fs_sampleRate , 32000, 44100, 48000
     */

    ENUM_PRIVATEINFO_AUDIO_DEC_DELAY_RP,		/* 1:enable, 0:disable */
    ENUM_PRIVATEINFO_AUDIO_AI_SET_OUT_FMT,		/* privateInfo[0] =out_fmt_pb, privateInfo[1] =out_fmt_ts*/
    ENUM_PRIVATEINFO_AUDIO_AI_SWITCH_FOCUS,
    ENUM_PRIVATEINFO_AUDIO_SUPPORT_SAMPLERATE,
    ENUM_PRIVATEINFO_AUDIO_GET_AVAILABLE_AO_OUTPUT_PIN, /* privateInfo[0] is pcm_out or pcm_out1 or pcm_out2 ... */
    ENUM_PRIVATEINFO_AUDIO_GET_PCM_IN_PIN,               /* request pcm-in pin ID */
    ENUM_PRIVATEINFO_AUDIO_RELEASE_PCM_IN_PIN,            /* release pcm-in pin ID */
    ENUM_PRIVATEINFO_AUDIO_FIRMWARE_CAPABILITY,
    ENUM_PRIVATEINFO_AUDIO_SRC_PROCESS_DONE,
    ENUM_PRIVATEINFO_AUDIO_DEC_SRC_ENABLE,
    ENUM_PRIVATEINFO_AUDIO_QUERY_FLASH_PIN,
    ENUM_PRIVATEINFO_AUDIO_SET_FLASH_PIN,
    ENUM_PRIVATEINFO_AUDIO_SET_SYSTEM_PROCESS_PID,
    ENUM_PRIVATEINFO_AUDIO_CONFIG_VIRTUALX_PARAM,
    ENUM_PRIVATEINFO_AUDIO_GET_CURR_AO_VOLUME              /*get current volume ID*/
};

enum AUDIO_ENUM_AUDIO_FIRMWARE_CAPABILITY_BIT
{
	ENUM_FWCAP_SUPPORT_GLOBAL_AI = 32,
	ENUM_FWCAP_SUPPORT_MULTIPLE_REMOTE = 64
};

struct	AUDIO_RPC_PRIVATEINFO_PARAMETERS
{
	long	instanceID;
	enum    AUDIO_ENUM_PRIVAETINFO type;
	long	privateInfo[16];
};

struct	AUDIO_RPC_PRIVATEINFO_RETURNVAL
{
	long	instanceID;
	long	privateInfo[16];
};

enum AUDIO_ENUM_MAX_OUTPUT_SAMPLERATE
{
	ENUM_MAX_OUTPUT_SAMPLERATE_UNLIMITED = 0,
	ENUM_MAX_OUTPUT_SAMPLERATE_48000 = 1,
	ENUM_MAX_OUTPUT_SAMPLERATE_96000 = 2,
	ENUM_MAX_OUTPUT_SAMPLERATE_192000 = 3
};

struct AUDIO_PASSTHROUGH_INFO
{
	unsigned long audioPassThroughType;
    unsigned short audioPassThroughFlag;
};

enum AUDIO_SAMPLERATE
{
    AUDIO_SAMPLERATE_32000  = 0x1,
    AUDIO_SAMPLERATE_44100  = 0x2,
    AUDIO_SAMPLERATE_48000  = 0x4,
    AUDIO_SAMPLERATE_88200  = 0x8,
    AUDIO_SAMPLERATE_96000  = 0x10,
    AUDIO_SAMPLERATE_176400 = 0x20,
    AUDIO_SAMPLERATE_192000 = 0x40,
    AUDIO_SAMPLERATE_22050  = 0x80,
    AUDIO_SAMPLERATE_24000  = 0x100,
    AUDIO_SAMPLERATE_64000  = 0x200,
    AUDIO_SAMPLERATE_16000  = 0x400,
    AUDIO_SAMPLERATE_8000   = 0x800,
    AUDIO_SAMPLERATE_11025  = 0x1000,
    AUDIO_SAMPLERATE_12000  = 0x2000
};

enum USB_AUDIO_IN_CMD
{
    ENUM_USB_AUDIO_IN_CMD_DISCONNECT = 0,
    ENUM_USB_AUDIO_IN_CMD_CONNECT = 1,
    ENUM_USB_AUDIO_IN_CMD_STOP = 2,
    ENUM_USB_AUDIO_IN_CMD_START = 3,
    ENUM_USB_AUDIO_IN_CMD_GETINFO = 4,
    ENUM_USB_AUDIO_IN_CMD_SETINFO = 5,
    ENUM_USB_AUDIO_IN_CMD_MUTE = 6,
    ENUM_USB_AUDIO_IN_CMD_UNMUTE = 7,
    ENUM_USB_AUDIO_IN_CMD_MAX = 8
};

enum USB_AUDIO_IN_FORMAT
{
    ENUM_USB_AUDIO_IN_FORMAT_SIGNED_8BITS    = 0x1,
    ENUM_USB_AUDIO_IN_FORMAT_SIGNED_16BITS   = 0x2,
    ENUM_USB_AUDIO_IN_FORMAT_SIGNED_24BITS   = 0x4,
    ENUM_USB_AUDIO_IN_FORMAT_SIGNED_32BITS   = 0x8,
    ENUM_USB_AUDIO_IN_FORMAT_UNSIGNED_8BITS  = 0x10,
    ENUM_USB_AUDIO_IN_FORMAT_UNSIGNED_16BITS = 0x20,
    ENUM_USB_AUDIO_IN_FORMAT_UNSIGNED_24BITS = 0x40,
    ENUM_USB_AUDIO_IN_FORMAT_UNSIGNED_32BITS = 0x80
};

struct USB_AUDIO_IN_INFO
{
    unsigned long command;
    unsigned long usb_ai_ringbuf_addr;  /* addr of ring buffer struct AUDIO_RINGBUF_PTR */
    unsigned long usb_ai_samplerate;    /* bit 0~13: 32/44.1/48/88.2/96/176.4/192/22.05/24/64/16/8/11.025/12 kHz */
    unsigned long usb_ai_format;        /* ref to USB_AUDIO_IN_SAMPLE_FORMAT, always big-endian */
    unsigned long usb_ai_max_chnum;     /* up to 2-ch currently */
};

enum USB_AUDIO_IN_TYPE
{
    ENUM_USB_AUDIO_IN_TYPE_VIDEO_CONFERENCE = 0,
    ENUM_USB_AUDIO_IN_TYPE_KARAOKE          = 1
};

struct AUDIO_AI_DEVICE_USB_INFO
{
    long instanceID;
    unsigned long     type;             /* enum USB_AUDIO_IN_TYPE */
    USB_AUDIO_IN_INFO info;
};


struct AUDIO_DUMMY_DATA
{
	long parameter[8];
};

enum LPCM_ENDIANESS
{
    LPCM_ENDIANESS_UNKNOWN,
    LPCM_ENDIANESS_LITTLE,
    LPCM_ENDIANESS_BIG
};

struct AUDIO_RPC_TSXT
{
	long instanceID;
	unsigned char		       pp_Tsxt_Enable;

	unsigned char		       ModeType;
	unsigned char			TruBassGain;
	unsigned char  	       TruBassSize;
	unsigned char			FocusGain;
	unsigned char			InputGain;

	/* bypass mode -6 db */
	unsigned char			IsTSXTEnable;
	unsigned char			IsHeadphoneMode;
	unsigned char			IsTruBassEnable;
	unsigned char			IsFocusEnable;

	unsigned char DefinitionGain;
	unsigned char IsDefEnable;
};

struct AUDIO_RPC_TSHD_INFO {
	short							Enable;
	short							InGain;
	short							OutGain;
	short 						BypassGain;
	short							InMode;
	short							OutMode;
	short				      SurEnabled;
	short							SurLevel;
	short							SubWooferCxOverFc;
	short							FrontTBEn;
	short							FrontTBLevel;
	short							FrontTBSplitAnalysisEn;
	short							FrontTBCompLevel;
	short							FrontTBSpkSize;
	short							FrontTBMode;
	short							SubTBEn;
	short							SubTBLevel;
	short							SubTBSplitAnalysisEn;
	short							SubTBCompLevel;
	short							SubTBSpkSize;
	short							FrontDefEn;
	short							FrontDefLevel;
	short							CenterDefEn;
	short							CenterDefLevel;
	short							DiaClarityEn;
	short							DiaClarityLevel;
	short							WowhdSrs3dMode;
	short							WowhdSpaceLevel;
	short							WowhdCenterLevel;
	short							WowhdFocusEn;
	short							WowhdFocusLevel;
	short							WowhdLimiterEn;
	short							WowhdHighBitEn;
	short							WowhdLimiterMinimalGain;
};

struct AUDIO_RPC_TSHD
{
	long instanceID;
	short Enable;
	short Test_case_Enable; /* enabled: use for test case; disabled: use for general case.*/
	short Type;             /* type 0: input L/R, type 1: input SL/SR , type 2: input C/Sub*/
  AUDIO_RPC_TSHD_INFO TSHD_info;
};


struct AUDIO_RPC_LGSE_RETURNVAL
{
	long ret;       /* S_OK or not */
	long value[16];
};

struct AUDIO_RPC_LGSE_GETDATA
{
	/* now, only support fn010,fn014 out */
  long instanceID;
	long function_list;
	long rw;
	long size;
};

struct AUDIO_RPC_LGSE_SETMODE
{
	long instanceID;
	short dataOption;
	long flag;       /* flag = 0 : bypass ,flag > 0 : enabled*/
};

struct AUDIO_RPC_LGSE00861
{
	unsigned int _LGSE01668;
	unsigned int _LGSE01669;
	unsigned int _LGSE02409;
	unsigned int _LGSE01665;
	unsigned int _LGSE01673;
	unsigned int _LGSE01667;
	unsigned int _LGSE01658;
	unsigned int _LGSE01662;
	unsigned int _LGSE01661;
	unsigned int _LGSE01670;
};

struct AUDIO_RPC_LGSE00876
{
	unsigned int _LGSE00585;
	unsigned int _LGSE00584;
	unsigned int _LGSE00586;
};

struct AUDIO_RPC_LGSE_SETMAIN
{
	long instanceID;
	short dataOption;
	/*option = 0 ,_LGSE00861 for init*/
	AUDIO_RPC_LGSE00861	dataInit;
	/*option = 1 ,_LGSE00876 for var*/
	AUDIO_RPC_LGSE00876 dataVar;
};

struct AUDIO_RPC_LGSE00855
{
	int _LGSE00742;
	int _LGSE00744;
	int _LGSE00743;
	int _LGSE00745;
	int _LGSE00746;
	int _LGSE00755;
	int _LGSE00738;
	int _LGSE00756;
	int _LGSE00757;
	int _LGSE00748;
	int _LGSE00741;
	int _LGSE00747;
	int _LGSE00740;
	int _LGSE00739;
	int _LGSE00753;
	/*int _LGSE00759[7][20];*/
	int _LGSE00759[140];
	/*int _LGSE00758[7][20];*/
	int _LGSE00758[140];
};

struct AUDIO_RPC_LGSE00870
{
	int _LGSE00754;
};

struct AUDIO_RPC_LGSE_SETFN000
{
	long  instanceID;
	short dataOption;
	/*option = 0 ,_LGSE00855 for init*/
	long rpc_LGSE00855_set_address;
	/*option = 1 ,_LGSE00870 for var*/
	AUDIO_RPC_LGSE00870 dataVar;
};

struct AUDIO_RPC_LGSE00854
{
	int _LGSE00784;
	int _LGSE00823[20];
};

struct AUDIO_RPC_LGSE00869
{
	int _LGSE00794;
	int _LGSE00795;
	int _LGSE00582;
	int _LGSE00610;
	int _LGSE00580;
	int _LGSE00067;
	int _LGSE00068;
	int _LGSE00075;
	int _LGSE00716;
	int _LGSE00348;
	int _LGSE00076;
	int _LGSE00717;
	int _LGSE00349;
	int _LGSE00077;
	int _LGSE00718;
	int _LGSE00191;
	int _LGSE00192;
	int _LGSE00190;
	int _LGSE00189;
	int _LGSE00687;
	int _LGSE00690;
	int _LGSE00689;
	int _LGSE00688;
	int _LGSE00692;
	int _LGSE00691;
	int _LGSE00538;
	int _LGSE00534;
	int _LGSE00537;
	int _LGSE00536;
	int _LGSE00542[101];
};

struct AUDIO_RPC_LGSE_SETFN001
{
	long instanceID;
	short dataOption;
	/*option = 0 ,_LGSE00854 for init*/
	AUDIO_RPC_LGSE00854 dataInit;
	/*option = 1 ,_LGSE00869 for var*/
	long rpc_LGSE00869_set_address;
};

struct AUDIO_RPC_LGSE00857
{
	int _LGSE00762[2];
	int	_LGSE00343;
	int	_LGSE00693;
	int	_LGSE00545;
	int	_LGSE00543;
	int	_LGSE00539;
	int	_LGSE00544;
	int	_LGSE00540;
	int	_LGSE00541;
};

struct AUDIO_RPC_LGSE00872
{
	int _LGSE00132;
	int VALUE;
};

struct AUDIO_RPC_LGSE_SETFN009
{
    long instanceID;
    short dataOption;
    /*option = 0 ,_LGSE00857 for init*/
    AUDIO_RPC_LGSE00857 dataInit;
    /*option = 1 ,_LGSE00872 for var*/
    AUDIO_RPC_LGSE00872 dataVar;
};

struct AUDIO_RPC_LGSE00859
{
	int _Left[5];
	int _Right[5];
};

struct AUDIO_RPC_LGSE00874
{
	int _LGSE00588;
};

struct AUDIO_RPC_LGSE_SETFN010
{
	long instanceID;
	short dataOption;
	/*option = 0 ,_LGSE00859 for init*/
	AUDIO_RPC_LGSE00859 dataInit;
	/*option = 1 ,_LGSE00874 for var*/
	AUDIO_RPC_LGSE00874 dataVar;
};

struct AUDIO_RPC_LGSE_SETFN004
{
    long instanceID;
    short dataOption;
    /*option = 0 ,data for init*/
    /*option = 1 ,data[25] for var*/
    int	data[25];
};

struct AUDIO_RPC_LGSE_SETFN005
{
    long instanceID;
    short dataOption;
    /*option = 0 ,data for init*/
    /*option = 1 ,data[15] for var*/
    int	data[15];
};

struct AUDIO_RPC_LGSE00858
{
    int _LGSE00319;
    int _LGSE00330;
    int _LGSE00331;
    int _LGSE00327;
    int _LGSE00303;
    int _LGSE00332;
    int _LGSE00304;
    int _LGSE00333;
    int _LGSE00326;
    int _LGSE00341;
    int _LGSE00342;
    int _LGSE00324;
    int _LGSE00305;
    int _LGSE00334;
    int _LGSE00306;
    int _LGSE00335;
    int _LGSE00320[20];
    int _LGSE00322[4];
    int _LGSE00329[5];
    int _LGSE00338[20];
    int _LGSE00337;
    int _LGSE00328[4];
    int _LGSE00321[20];
    int _LGSE00317[2];
    int _LGSE00318[3];
    int _LGSE00315[2];
    int _LGSE00316[3];
    int _LGSE00313[2];
    int _LGSE00314[3];
    int _LGSE00309;
    int _LGSE00323;
    int _LGSE00336;
};

struct AUDIO_RPC_LGSE00873
{
    int _LGSE00843;
    int _LGSE00340;
    int _LGSE00841;
    int _LGSE00308;
    int _LGSE00842;
    int _LGSE00312;
    int _LGSE00311;
    int _LGSE00307;
    int _LGSE00325;
    int _LGSE00339;
    int _LGSE00310;
};

struct AUDIO_RPC_LGSE_SETFN008
{
    long instanceID;
    short dataOption;
	/*option = 0 ,_LGSE00858 for init*/
    long rpc_LGSE00858_set_address;
	/*option = 1 ,_LGSE00873 for var*/
    AUDIO_RPC_LGSE00873 dataVar;
};

struct AUDIO_RPC_LGSE00853
{
   int _LGSE00013;
   int _LGSE00003;
   int _LGSE00006;
   int _LGSE00005[3];
   int _LGSE00015;
   /*DSPfix _LGSE00016[35][3];*/
   int _LGSE00016[105];
   /*DSPfix _LGSE00009[8][3]*;*/
   int _LGSE00009[24];
};

struct AUDIO_RPC_LGSE00868
{
	 int _LGSE00008;
};

struct AUDIO_RPC_LGSE_SETFN014
{
    long instanceID;
    short dataOption;
	/*option = 0 ,_LGSE00853 for init*/
    long rpc_LGSE00853_set_address;
	/*option = 1 ,_LGSE00868 for var*/
    AUDIO_RPC_LGSE00868 dataVar;
};

struct AUDIO_RPC_LGSE00879
{
  /*DSPfix _LGSE00804[4][20];*/
  int _LGSE00804[80];
  /*DSPfix _LGSE00803[4][20];*/
  int _LGSE00803[80];
  int _LGSE00667;
  int _LGSE00666;
};

struct AUDIO_RPC_LGSE_SETFN017
{
    long instanceID;
    short dataOption;
	/*option = 0 ,null for init*/

	/*option = 1 ,_LGSE00879 for var*/
    long rpc_LGSE00879_set_address;
};

struct AUDIO_RPC_LGSE00856
{
		int _LGSE00799[20];
		int _LGSE00074[5];
		int RELEASE[5];
		int _LGSE00827[5];
		int _LGSE00828[5];
		int _LGSE00831[5];
		int _LGSE00837[5];
		int _LGSE00838[5];
		int _LGSE00839[5];
		int _LGSE00710[5];
		int _LGSE00711[5];
		int _LGSE00712[5];
		int _LGSE02471;
		int _LGSE00764;
		int _LGSE00763;
		int _LGSE00079[5];
		int _LGSE00720[5];
		int _LGSE00078[5];
		int _LGSE00719[5];
};

struct AUDIO_RPC_LGSE00871
{
		int _LGSE00018;
		int _LGSE02468;
		int _LGSE02469;
		int _LGSE00298;
};

struct AUDIO_RPC_LGSE_SETFN019
{
	long instanceID;
	short dataOption;
	/*option = 0 ,_LGSE00856 for init*/
	long rpc_LGSE00856_set_address;
	/*option = 1 ,_LGSE00871 for var*/
	AUDIO_RPC_LGSE00871 dataVar;
};

struct AUDIO_RPC_LGSE00863
{
   unsigned int _LGSE00285;
   int _LGSE00071;
   int _LGSE00086;
   unsigned int _LGSE00284;
   int _LGSE00070;
   int _LGSE00085;
};

struct AUDIO_RPC_LGSE00878
{
   /*int _LGSE00789[4][20][3];*/
   int _LGSE00789[240];
   /*int _LGSE00788[4][20][3];*/
   int _LGSE00788[240];
};

struct AUDIO_RPC_LGSE_SETFN022
{
	long instanceID;
	short dataOption;
	/*option = 0 ,_LGSE00863 for init*/
	AUDIO_RPC_LGSE00863 dataInit;
	/*option = 1 ,_LGSE00878 for var*/
	long rpc_LGSE00878_set_address;
};

struct AUDIO_RPC_LGSE00862
{
  int _LGSE02719[2];
  int _LGSE02761[20];
  int _LGSE02810[20];
};

struct AUDIO_RPC_LGSE00877
{
  int _LGSE02720[20];
};

struct AUDIO_RPC_LGSE_SETFN018
{
	long instanceID;
	short dataOption;
	/*option = 0 ,_LGSE00862 for init*/
	long rpc_LGSE00862_set_address;
	/*option = 1 ,_LGSE00877 for var*/
	AUDIO_RPC_LGSE00877 dataVar;
};

struct AUDIO_RPC_LGSE02624
{
  long _LGSE02582;
  long _LGSE02590;
  long _LGSE02591[2];
  long _LGSE02592[3];
  long _LGSE02605[2];
  long _LGSE02606[3];
};

struct AUDIO_RPC_LGSE_SETFN024
{
  long instanceID;
  short dataOption;
  /*option = 0 ,_LGSE00862 for init*/
  AUDIO_RPC_LGSE02624 dataInit;
  /*option = 1 ,data for var*/
};

struct AUDIO_RPC_LGSE_DATA026
{
  int data[200];
};

struct AUDIO_RPC_LGSE_SETFN026
{
    long instanceID;
    short dataOption;
    /*option = 0 ,data for init*/
    /*option = 1 ,data[200] for var*/
    long rpc_data026_set_address;
};

struct AUDIO_RPC_LGSE_DATA027
{
  int data[100];
};

struct AUDIO_RPC_LGSE_SETFN027
{
    long instanceID;
    short dataOption;
    /*option = 0 ,data for init*/
    /*option = 1 ,data[100] for var*/
    long rpc_data027_set_address;
};

struct AUDIO_RPC_LGSE02871
{
    int _LGSE02797;
    int _LGSE02798;
};

struct AUDIO_RPC_LGSE_SETFN028
{
    long instanceID;
    short dataOption;
    /*option = 0 ,data for init*/
    /*option = 1 ,_LGSE02871 for var*/
    AUDIO_RPC_LGSE02871 dataVar;
};

struct AUDIO_RPC_LGSE02869
{
    int _LGSE00799[20];
    int _LGSE00074[5];
    int RELEASE[5];
    int _LGSE00827[5];
    int _LGSE00828[5];
    int _LGSE00831[5];
    int _LGSE02856[5];
    int _LGSE00837[5];
    int _LGSE00838[5];
    int _LGSE00839[5];
    int _LGSE02861[5];
    int _LGSE00710[5];
    int _LGSE00711[5];
    int _LGSE00712[5];
    int _LGSE02791[5];
    int _LGSE02471;
    int _LGSE00764;
    int _LGSE00763;
    int _LGSE00079[5];
    int _LGSE00720[5];
    int _LGSE00078[5];
    int _LGSE00719[5];
    int _LGSE00018;
    int _LGSE02723[20];
    int _LGSE02795;
    int _LGSE02717[20];
    int _LGSE02718[20];
    int _LGSE02729;
    int _LGSE02730;
    int _LGSE02767[23];
};

struct AUDIO_RPC_LGSE_SETFN029
{
    long instanceID;
    short dataOption;
    /*option = 0 ,data for init*/
    /*option = 1 ,_LGSE02869 for var*/
    long rpc_LGSE02869_set_address;
};

struct AUDIO_RPC_TRUVOL_MODE {
	int mode;         /* 0 for light mode, 1 for normal mode, 2 for heavy mode  */
    int enable;       /* 1 for TRUE, 0 for FALSE  */
    int InputGain;    /* 0.0-32.0 for inputGain range, default is 1.0  */
    int OutputGain;   /* 0.0-32.0 for outputGain range, default is 0.5  */
};

enum AUDIO_FREQ_EQ_MODE {
	FREQ_EQ_HW_MODE = 0,
	FREQ_EQ_SW_MODE = 1
};

struct AUDIO_RPC_FREQ_EQ {
    int mode;
	int	bw[15]; /* 15 is for max band number */
	int fc[15];
	int gain[15];
	int type[15];
	int valid_mask;
};

struct AUDIO_RPC_TRUVOLUME {
	long instanceID;
	u_char pp_TruVol_Enable;
    AUDIO_RPC_TRUVOL_MODE pp_TruVol_Info;
};

enum AUDIO_SAMPLERATE_TOLERANCE
{
    AUDIO_SAMPLERATE_TOLERANCE_NONE,
    AUDIO_SAMPLERATE_TOLERANCE_MAXIMUM,     /* 50, means 50/1000, 5% */
    AUDIO_SAMPLERATE_TOLERANCE_CUSTOM      /* 1~50, means 1/1000~50/1000, 0.1~5%  */
};

struct AUDIO_BASSBACK_TV_MODE
{
    /*BassBack*/
    int  Enable_Sys;        /* Input*/
    int  StopBandFreq_Sys;  /* InputStopband */
    int  HarmonicGain;      /* Input*/
    int  vb_enable;

    /* Bass*/
    int  Sys_EnhanceFreq;   /* Input*/
    int  Tru_StopbandFreq;  /* Input*/
    int  Set_BassGain;        /*  0 ~  10 dB*/

};

struct AUDIO_BASSBACK_PCBU_MODE
{
	int  Enable_Sys;        /* Input*/
	int  StopBandFreq_Sys;  /* InputStopband */
	int  HarmonicGain;      /* Input*/
	int  SubHarmonicGain;   /* Input*/
	int  TreHarmonicGain;   /* Input*/
	int  vb_enable;

	/*Bass*/
	int  Sys_EnhanceFreq;   /* Input*/
	int  Tru_StopbandFreq;  /* Input*/
	int  Set_BassGain;      /*  0 ~  10 dB*/

	/*High-Pass-Filter*/
	int Enable_HPF;        /* Input*/
	int  StopBandFreq_HPF;  /* Input*/

        /*PeakFilter */
	int  Enable_PF;         /* ON/OFF of peakfilter */
	int  Gain_PF; /* Gain(dB)*100-3000 ~ 1000*/
	int  CenterFreq_PF; /* 100~10000 */
	int  BandWidth_PF;  /* 10~3000 */
};

struct AUDIO_RPC_PCBU_BASSBACK
{
	long instanceID;
	unsigned char		       pp_bassback_Enable;
	AUDIO_BASSBACK_PCBU_MODE    pp_bassback_mode;
};


struct AUDIO_RPC_TV_BASSBACK
{
	long instanceID;
	unsigned char		          pp_bassback_Enable;
	AUDIO_BASSBACK_TV_MODE    pp_bassback_mode;
};

struct AUDIO_RPC_TV_BASSBACK_CHANGE_BASS_GAIN
{
	long instanceID;
	unsigned char		          pp_bassback_bassgain;

};

enum AUDIO_AO_CHANNEL_OUT_SWAP
{
    AUDIO_AO_CHANNEL_OUT_STEREO  = 0x0,
	AUDIO_AO_CHANNEL_OUT_L_TO_R  = 0x1,
	AUDIO_AO_CHANNEL_OUT_R_TO_L  = 0x2,
	AUDIO_AO_CHANNEL_OUT_LR_SWAP = 0x3,
	AUDIO_AO_CHANNEL_OUT_LR_MIXED = 0x4
};

struct AUDIO_RPC_AO_CHANNEL_OPT_SWAP
{
	long instanceID;
	unsigned int	channelSwapIndex;
};

enum AUDIO_CHANNEL_OUT_MODE
{
/*avoid redefine compiling error with Android native code*/
        AUDIO_CHANNEL_OUT_STEREO_RTK   = 0x0,
        AUDIO_CHANNEL_OUT_L_TO_R_RTK   = 0x1,
        AUDIO_CHANNEL_OUT_R_TO_L_RTK   = 0x2,
        AUDIO_CHANNEL_OUT_LR_SWAP_RTK  = 0x3,
        AUDIO_CHANNEL_OUT_LR_MIXED_RTK = 0x4
};

struct AUDIO_RPC_CHANNEL_OUT_MODE
{
	long instanceID;
	AUDIO_CHANNEL_OUT_MODE mode;
};

struct AUDIO_RPC_GET_PTS_INFO
{
	long instanceID;
	AUDIO_RPC_PTS_INFO pts_info;
};

enum AUDIO_SPDIFO_SOURCE
{
	SPDIFO_SRC_FIFO = 0x0,
	SPDIFO_SRC_IN = 0x1,
	SPDIFO_SRC_HDMI = 0x2,
	SPDIFO_SRC_DISABLE = 0x3
};

struct AUDIO_RPC_SPDIFO_SOURCE
{
	long instanceID;
	AUDIO_SPDIFO_SOURCE source;
};

struct AUDIO_RPC_PP_ASF_ON_OFF
{
	long instanceID;
	unsigned int	on_off_flag;
};

struct AUDIO_RPC_PP_ASF_BALANCE
{
	long instanceID;
	int	asf_balance;
};


struct AUDIO_RPC_PP_ASF_MASTER_VOLUME
{
	long instanceID;
	unsigned int	asf_volume;
};

struct AUDIO_SPDIF_CS
{
    long module_type;  /* AI or AO*/
    char professional;
    char data_type;
    char copyright;
    char pre_emphasis;
    char mode;
    char category_code;
    char source_number;
    char channel_number;
    char sampling_freq;
    char clock_accuracy;
    char word_length;
    char original_sampling_freq;
    char cgms_a;
};

struct AUDIO_RPC_RESAMPLE_INFO
{
    int Taps;
    int SrcSamples;
    int DstSamples;
    int Coefs;
};


/* Kernel */
struct AUDIO_RPC_TO_KERNEL_PARAMETER
{
   unsigned int command;
   unsigned int param1;
   unsigned int param2;
};

/* decoder seeking capability */
struct AUDIO_RPC_DEC_SEEKING_CAP
{
  long                        MaxSpeed;
  long                        MaxReverseSpeed;
  long                        MinSkip;
  long                        MaxSkip;
  long                        MinReverseSkip;
  long                        MaxReverseSkip;
} ;

struct AUDIO_RPC_GET_DEC_SEEK_CAP {
	long instanceID;
	AUDIO_DEC_TYPE dec_type;
};

