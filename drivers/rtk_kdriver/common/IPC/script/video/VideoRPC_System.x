.insert <RPCBaseDS.h>
.insert <VideoRPCBaseDS.h>



/**
 * \brief By this struct video cpu will init the video parameters
 */
struct VIDEO_INIT_DATA
{
	enum TVE_BOARD_TYPE boardType ;
};


/**
 * \brief Video firmware configuration parameters
 */
struct VIDEO_CONFIG_DATA
{
	enum VIDEO_BUFFER_TYPE  videoBufferType ;
} ;


/**
 * \brief By this struct video cpu create specified video filter.
 *
 * The filters on the SP side will base on the VP filter's instance ID to
 * dispatch the message correctly.
 */
struct VIDEO_RPC_INSTANCE
{
    enum VIDEO_VF_TYPE  type ;     /* The module type, such as VIDEO_DECODER, */
                                   /* SPU_DECODER, VIDEO_IN, VIDEO_OUT */
};


/**
 * \brief This is for debug use. It contains information to initialize a pseudo vin
 *
 */
struct VIDEO_RPC_PVIN_INIT {
	long            instanceID;
	enum PVIN_MODE  mode;
	char            path[64];
  int             max_pic_count;
  int             period;
  int             width;
  int             height;
};


/**
 * \brief This is for debug use. It contains information to schedule sending eos of pseudo vin
 *
 */
struct VIDEO_RPC_PVIN_SCHEDULE_EOS {
	long            instanceID;
  int             frame_number_after;
};


/**
 * \brief This is for debug use. It setups the filename for MUX bitstream.
 *
 */
struct VIDEO_RPC_MUX_SET_FILE {
	long  instanceID;
  char  fname[64];
};

/**
 * \brief This is for debug use. It contains the initialization information for pvout
 *
 */
struct VIDEO_RPC_PVOUT_INIT {
	long  instanceID;
  long  frame_width;
  long  frame_height;
  long  max_pic_count;
};

/**
 * \brief VIDEO_RPC_SetRefClock() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_DEC_SetRefClock().
 */

struct VIDEO_RPC_SET_REFCLOCK
{
  long instanceID ;
  long pRefClock ; /* pointer to reference clock structure */
};


/**
 * \brief Used by VIDEO_RPC_ToAgent_RequestBuffer() to specify the size
 *        of the buffer to be requested from the VBM.
 */
struct VIDEO_RPC_REQUEST_BUFFER
{
	long width ;
	long height ;
};


struct VIDEO_RPC_LOW_DELAY
{
	enum VIDEO_LOW_DELAY mode ;
  long instanceID ;
};

/**
 * \brief VIDEO_RPC_SetScale() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_SetScale().
 */
struct VIDEO_RPC_SET_SCALE {
	unsigned int Divx_Certify; /* enable Scaling flow*/
	unsigned int targetWidth;
	unsigned int targetHeight;
} ;

/**
 * \brief VIDEO_RPC_COMP_CTRL for compress option control
 */
struct VIDEO_RPC_COMP_CTRL
{
  unsigned char isComp2k;
} ;

/**
 * \defgroup video_dec_data Video_Dec_Data_Type
 *
 *
 * @{
 */


/**
 * \brief VIDEO_RPC_DEC_SetSpeed() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_DEC_SetSpeed().
 */
struct VIDEO_RPC_DEC_SET_SPEED
{
	long instanceID ;
	long displaySpeed ;
	long decodeSkip ;
};



/**
 * \brief VIDEO_RPC_DEC_SetErrorConcealmentLevel() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_DEC_SetErrorConcealmentLevel().
 */
struct VIDEO_RPC_DEC_SET_ERR_CONCEALMENT_LEVEL
{
	long instanceID ;
	long errConcealmentLevel ;
};



/**
 * \brief A init function of video decoder filter.
 */
struct VIDEO_RPC_DEC_INIT
{
	long		                        instanceID ;
	VIDEO_STREAM_TYPE		            type ;
	struct	VIDEO_RPC_DEC_SET_SPEED set_speed ;
} ;

/**
 * \bref VIDEO_RPC_DEC_SetDeblock for deblocking control
  */
struct VIDEO_RPC_DEC_SET_DEBLOCK
{
	long    instanceID;
	u_char  enable;
} ;




/**
 * \brief VIDEO_RPC_DEC_BITSTREAM_BUFFER for bitstream validation
   */
struct VIDEO_RPC_DEC_BITSTREAM_BUFFER
{
	enum VIDEO_VF_TYPE  type  ;
	long                bsBase;
	long                bsSize;
} ;


/**
 * \brief VIDEO_RPC_DEC_BV_RESULT for result of bitstream validation
 */
struct VIDEO_RPC_DEC_BV_RESULT
{
	long    bitRate;
	long    type;
};


/**
 * \brief VIDEO_RPC_DEC_PV_RESULT for result of frame resolution parse
 */
struct VIDEO_RPC_DEC_PV_RESULT
{
	unsigned int width;
	unsigned int height;
};

/**
 * \brief VIDEO_RPC_DEC_SEQ_INFO to return video sequence information to system
 *
 *  Note: 1. If any information is unavailable or invalid, its corresponding
 *           variable in the structure will be set to -1.
 *
 *        2. All variables are LSB aligned, i.e., if the syntax element it
 *           represents has less than 32 bits to occupy the entire 'long' word,
 *           the MSBs are set to zero.
 */
struct VIDEO_RPC_DEC_SEQ_INFO
{
  long  hor_size ;      /* decoded picture horizontal size */
  long  ver_size ;      /* decoded picture vertical   size */
  long  aspect_ratio ;  /* 'aspect_ratio_information' as defined in ISO/IEC 13818-2 sec. 6.3.3 (Table 6-3) */
                        /* 0: forbidden, 1: square sample, 2: 3/4, 3: 9/16, 4: 1/2.21, 5~15: reserved      */
  long  frame_rate ;    /* 'frame_rate_code'          as defined in ISO/IEC 13818-2 sec. 6.3.3 (Table 6-4) */
  long  bit_rate ;      /* video elementary stream bit rate in units of 400 bits/second */
  long  vbv_buf_size ;  /* VBV buffer size as defined in ISO/IEC 13818-2 sec. 6.3.3 and Annex C */
  long  profile_level ; /* MPEG-2 profile and level identification as defined in ISO/IEC 13818-2 sec. 8 */
  long  chroma_format ; /* MPEG-2 chroma format                    as defined in ISO/IEC 13818-2 sec. 6.3.5 (Table 6-5) */
                        /* 0: reserved, 1: 420, 2: 422, 3: 444                                                          */
  long  video_format ;  /* MPEG-2 video format                     as defined in ISO/IEC 13818-2 sec. 6.3.6 (Table 6-6) */
                        /* 0: component, 1: PAL, 2: NTSC, 3: SECAM, 4: MAC, 5: unspecified video format, 6~7: reserved  */
  long  disp_hor_size ; /* MPEG-2 display horizontal size          as defined in ISO/IEC 13818-2 sec. 6.3.6 */
  long  disp_ver_size ; /* MPEG-2 display vertical   size          as defined in ISO/IEC 13818-2 sec. 6.3.6 */
  long  isProg ;        /* progressive frame, 0:interlace  1:progressive  -1:unknown                        */
  long  isMVC ;         /* 0:non-MVC   1:MVC          -1:unknown                                            */
  long  is4k2k_MVC;     /* 0:non-4k2kMVC 1:4k2kMVC    -1:unknown                                            */
  long  isREALD;        /* 0:non-realD 1:QUINCUNX 2:SIMPLE_HORZONTAL_SQUEEZE -1:unknown                     */
  long  prog_sequence ; /* MPEG-2 progressive_sequence as defined in ISO/IEC 13818-2 sec. 6.3.5             */
  long  pic_type ;      /* 1: I, 2: P, 3: B                                                                 */
  long  temp_ref ;      /* MPEG-2 temporal_reference as defined in ISO/IEC 13818-2 sec. 6.3.10              */
  long  pic_struct ;    /* 0: top field, 1: bottom field, 2: frame picture                                  */
  long  top_ff ;        /* MPEG-2 top_field_first as defined in ISO/IEC 13818-2 sec. 6.3.11                 */
  long  rept_ff ;       /* MPEG-2 repeat_first_field as defined in ISO/IEC 13818-2 sec. 6.3.11              */
  unsigned char   video_full_range_flag;
  unsigned char   transfer_characteristics;   /* information for xvYCC/HDR content */
  unsigned char   matrix_coefficiets;   /* information for HDR content */
  unsigned char   colour_primaries;   /* information for HDR content */
  unsigned short display_primaries_x[3];
  unsigned short display_primaries_y[3];
  unsigned short white_point_x;
  unsigned short white_point_y;
  unsigned int min_display_mastering_luminance;
  unsigned int max_display_mastering_luminance;
  unsigned int MaxSpeed;
  unsigned char hdr_type; /* HDR type - 0:NONE_HDR, 1:HDR_10, 2:HLG, 3:PRIME, 4:DOLBY */
} ;


/**
 * \brief VIDEO_RPC_DEC_MPEG_SEQ_HDR to return MPEG sequence header to system
 *
 *
 *        1. All variables are LSB aligned, i.e., if the syntax element it
 *           represents has less than 32 bits to occupy the entire 'long' word,
 *           the MSBs are set to zero.
 */
struct VIDEO_RPC_DEC_MPEG_SEQ_HDR
{
    long  instanceID ;
  u_long  C_prog_seq ;      /* progressive_sequence flag, see ISO/IEC 13818-2 sec. 6.3.5 */
  u_long  C_aspect_ratio ;  /* aspect ratio information,  see ISO/IEC 13818-2 sec. 6.3.3 */
  u_long  C_intra_QM ;      /* index to the sequence intra quantiser matrix circular buffer.
                               If set to UNKNOWN_INDEX_C (defined in MPEG_Decode_def.h), then use
                               default matrix for intra blocks defined in ISO/IEC 13818-2 sec. 6.3.11 */
  u_long  C_non_intra_QM ;  /* index to the sequence non-intra quantiser matrix circular buffer.
                               If set to UNKNOWN_INDEX_C (defined in MPEG_Decode_def.h), then use
                               default matrix for non-intra blocks defined in ISO/IEC 13818-2 sec. 6.3.11 */
  u_long  H_hor_size ;      /* width  of the displayable part of the decoded luma frame */
  u_long  H_ver_size ;      /* height of the displayable part of the decoded luma frame */
  u_long  H_disp_hor_size ; /* width  of the actual display. see ISO/IEC 13818-2 sec. 6.3.6 */
  u_long  H_disp_ver_size ; /* height of the actual display. see ISO/IEC 13818-2 sec. 6.3.6 */
  u_long  H_frame_rate ;
  u_long  L_frame_PTSinc;   /* PTS increament of two successive frames, derived from frame_rate_code, frame_rate_extension_n and frame_rate_extension_d */
  u_long  L_bit_rate ;      /* coded bit rate in units of 400 bits/second */
  u_long  C_Mpeg1 ;         /* 1 if it is an MPEG-1 Sequence, i.e., no Sequence Extension following the Sequence Header
                               0 if it is an MPEG-2 Sequence */
  u_long  active_format ;   /* ETSI TS 101 154 V1.91(2009-09) B.3.4 Table B.5 -- Active Format */
  u_long  L_Num_Pics ;      /* number of pictures in the sequence */

  /*MPEG4*/
  u_short H_vop_time_increment_resolution;
  u_short H_size_vop_time_increment;
  u_char  C_complexity_estimation_disable;
  u_char  C_resync_marker_disable;
  u_char  C_quant_type;
  u_char  C_quarter_sample;
  char    C_intra_QM_MPEG4;
  char    C_non_intra_QM_MPEG4;
  u_long  L_define_vop_comp_est_hdr;

  /*HEVC*/
  u_long  saveBuf;

} ;


struct VIDEO_MEM_CHUNK
{
  long address ;   /* base address of a contiguous memory chunk */
  long size ;      /* size of the memory chunk */
} ;


struct VIDEO_RPC_VIDEO_FREE_MEMORY
{
  long  numMemChunks ; /* number of free memory chunks:                                                   */
                       /*                                                                                 */
                       /* -1: error occured when video firmware tried to recall allocated memory,         */
                       /*     a necessary step before video firmware is able to re-group and free up      */
                       /*    (part of) them to form the free memory chunk(s) to be returned to System.    */
                       /*                                                                                 */
                       /*  0: video firmware successfully recalled all allocated memory, but is unable    */
                       /*     to free up any of them for System, resuling zero free memory chunks         */
                       /*                                                                                 */
                       /*  1-8: valid values                                                              */
                       /*                                                                                 */
                       /*  9 and above: reserved and should not be used at the current version of         */
                       /*               video firmware                                                    */
                       /*                                                                                 */
                       /*  when 'numMemChunks' is not in the range of 1-8, the contents in the following  */
                       /*  'memChunk' struct array are all invalid.                                       */

  struct VIDEO_MEM_CHUNK memChunk[8] ;
} ;


struct VIDEO_RPC_CONFIG_CHUNK
{
  long configMode ;
  long numofChunk ;
} ;

struct VIDEO_RPC_DEC_CC_BYPASS_MODE
{
  long instanceID;
  enum VIDEO_DECODER_CC_BYPASS_MODE  cc_mode;
} ;


struct VIDEO_RPC_DEC_SET_DNR
{
  long instanceID;
  enum VIDEO_DNR_MODE  dnr_mode;
} ;

struct VIDEO_RPC_DEC_SET_REF_SYNC_LIMIT
{
  long instanceID ;
  long refSyncLimit ;
} ;


/**
 * \brief input of VIDEO_RPC_DEC_ToAgent_Capability(), use enum VideoCodecControlBit
 */
struct VIDEO_RPC_DEC_CAPABILITY
{
	long	HighWord;
	long	LowWord;
};


/**
 * \brief input of VIDEO_RPC_DEC_ToAgent_ParseFrameBoundary()
 */
struct VIDEO_RPC_DEC_PARSE_FRAME_BOUNDARY
{
  long instanceID;
};


/**
 * \brief VIDEO_RPC_DEC_DRIP_INFO for drip decoding
 */
struct VIDEO_RPC_DEC_DRIP_INFO
{
  long pDripData;
  long dripSize;
  long dripType;       /* 0: VDEC_DRIP_I_FRAME, 1: VDEC_DRIP_NORMAL */
  enum VIDEO_STREAM_TYPE codecType;
  long targetFormat;   /* 0: none, 1: ARGB8888, 2: BGR888, 3: JPEG */
  long targetWidth;
  long targetHeight;
  long targetBufSize;
  long pTargetAddr;
  long timeOut;        /* millisecond */
} ;


/**
 * \brief VIDEO_RPC_DEC_DRIP_RESULT for result of drip decoding
 */
struct VIDEO_RPC_DEC_DRIP_RESULT
{
  HRESULT hr;
  int     length;
};


/**
 * \brief A set decode mode.
 */
struct VIDEO_RPC_DEC_SET_DECODEMODE
{
	long		                        instanceID ;
	int             		            mode       ;
} ;


/**
 * \brief VIDEO_RPC_DEC_MEASURE_DECODE_TIME for measurement of decoding time per frame
 */
struct VIDEO_RPC_DEC_MEASURE_DECODE_TIME
{
	long   instanceID ;
	u_char enable ;
} ;

/**
 * \brief VIDEO_RPC_DEC_CMPRS_CTRL for control compression
 */
struct VIDEO_RPC_DEC_CMPRS_CTRL
{
	long               instanceID ;
	u_char             mode       ; /* 0:loseless , 1: lossy  */
	enum CMPRS_RATIO   ratio      ; 
	u_char             enable     ; /* 0: compression off, 1: compression on  */
} ;

/**
 * \brief VIDEO_RPC_THUMBNAIL_SetVscalerOutputFormat() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_THUMBNAIL_SetVscalerOutputFormat().
 */
struct VIDEO_RPC_THUMBNAIL_SET_VSCALER_OUTFORMAT {
    long instanceID;
	unsigned int ThumbAckAddr ;
    VIDEO_COLOR_FMT colorFormat ;
    unsigned int pTargetLuma ;       /* Linear address of Luma buffer */
    unsigned int pTargetChroma ;     /* Linear address of Chroma buffer */
    unsigned int pitch ;
    unsigned int targetRectX ;
    unsigned int targetRectY ;
    unsigned int targetRectWidth ;
    unsigned int targetRectHeight ;
    unsigned int alpha ;             /* if RGB8888 mode, alpha is for RGBA or ARGB */
    unsigned int fillColor;
} ;


/**
 * \brief VIDEO_RPC_THUMBNAIL_SetThreshold() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_THUMBNAIL_SetThreshold().
 */
struct VIDEO_RPC_THUMBNAIL_SET_THRESHOLD {
	long instanceID;
	long threshold;
} ;

/**
 * \brief VIDEO_RPC_FLASH_SetOutput() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_FLASH_SetOutput().
 */
struct VIDEO_RPC_FLASH_SET_OUTPUT {
	long instanceID;
	long address;
} ;

/**
 * \brief VIDEO_RPC_THUMBNAIL_SetStartPictureNumber() use this struct as parameter.
 *
 *  Please look the description of VIDEO_RPC_THUMBNAIL_SetStartPictureNumber().
 */
struct VIDEO_RPC_THUMBNAIL_SET_STARTPIC {
	long instanceID;
	long startPicNum;
	long endPicNum;
} ;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 **/
struct HAL_VO_P_RECT_T
{
	unsigned int    x;  /* x coordinate of its top-left point */
	unsigned int    y;  /* y coordinate of its top-left point */
	unsigned int    w;  /* width of it */
	unsigned int    h;  /* height of it */
};

/**
 * @brief This structure describes a image information to VO.
 **/
struct HAL_VO_P_IMAGE_T
{
	unsigned int       buf;           /* buffer pointer of decoded raw data */
	unsigned int       ofs_y;         /* offset of Y component */
	unsigned int       ofs_uv;        /* offset of UV components */
	unsigned int        len_buf;        /* buffer length of decoded raw data */
	unsigned int        stride;         /* stride size of decoded raw data */
	HAL_VO_P_RECT_T       rect;           /* image data rectangular */
  HAL_VO_P_PIXEL_FORMAT     pixel_format;
};

/**
 * @brief This struct describes a value set for the configuration type.
 **/
struct HAL_VO_P_CFG_VALUE_T
{
    unsigned int alpha; /* alpha blending factor (0~255) */
    HAL_VO_P_RECT_T rect; /* rectangular information for the video source */
    HAL_VO_P_PIXEL_FORMAT pixel_format;   /* pixel format of image */
};

/**
 * @brief This structure describes a video output (VO) configuration set.
 **/
struct HAL_VO_P_CFG_T
{
	enum HAL_VO_P_CFG_TYPE     type;   /* configuration type to set VO */
	HAL_VO_P_CFG_VALUE_T  value;  /* configuration value */
};

/**
 * @brief This structure describes a video output (VO) capability of device.
 **/
struct HAL_VO_P_DEVICE_CAPABILITY_T
{
    HAL_VO_P_SUPPORT_PANEL_TYPE_T support_panel_type;     /* supported panel type */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_T support_pixel_format; /* supported pixel format */
    unsigned char is_seperated_vo_port;                 /* whether to be seperated vo port */
    unsigned char is_changeable_cs_dynamically;			/* whether to be able to change color space dynamically */
    unsigned int vo_port_nb;                            /* the number of vo ports */
    unsigned int framebuffer_length;                    /* the length of framebuffer */
    HAL_VO_P_RECT_T framebuffer_rect;                     /* the rect of framebuffer */
};

/**
 * @brief This structure describes a framebuffer for the video output (VO).
 **/
struct HAL_VO_P_FB_FRAMEBUFFER_T
{
    unsigned char buf;			/* buffer pointer of the framebuffer */
    unsigned int buf_length;		/* the length of buffer */
    unsigned int stride;		/* stride size of the framebuffer */
    HAL_VO_P_RECT_T resolution;		/* resolution of the framebuffer */
    HAL_VO_P_PIXEL_FORMAT pixel_format;	/* pixel format of the framebuffer */
};

/**
 * @brief This structure describes a framebuffer property for the video output (VO).
 **/
struct HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_T
{
    HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_FLAGS_T flags;	/* framebuffer property flags */
	HAL_VO_P_PIXEL_FORMAT pixel_format;				/* pixel format of the framebuffer */
	unsigned int alpha;								/* value for the alpha blending */
	HAL_VO_P_RECT_T input;							/* input rect of source */
	HAL_VO_P_RECT_T output;							/* output rect of source */
};
/** @} */


struct VIDEO_RPC_CAP_START_CAPTURE
{
    long        instanceID;
    long        startMode;
    long        cap_width;
    long        cap_height;
};

struct VIDEO_RPC_CAP_STOP_CAPTURE
{
    long        instanceID;
};

struct VIDEO_RPC_CAP_CAPTURE_ONE_FRAME
{
    long        instanceID;
    long        frame_type;
    long        frame_width;
    long        frame_height;
    long	frame_x_offset;
    long	frame_y_offset;
    long        frame_crop_width;
    long        frame_crop_height;
};

struct VIDEO_RPC_CAP_SET_FRAME_RATE {
	long instanceID;
	long frame_rate;
};


/****************************************
 * \defgroup Video_Encoder_Data_Type structures for the Video Encoder APIs.
 *
 * @{
 ****************************************/


struct VIDEO_RPC_ENC_INIT
{
    long                      instanceID ;
    long                  type;         /* Filter type in init state, such as MPEG1_ENCODER... */
    enum VIDEO_FORMAT     videoFormat;  /* NTSC or PAL */
    /*                    - the values are defined below.
                                  0	= NTSC
                                  1	= PAL                               */
    enum VIDEO_SOURCE     videoSource;  /* TVD or DIN */
    /*                    - the values are defined below.
                                  0	= TVD
                                  1	= DIN
                                  2 = RAWIN                             */
    enum YUV_FMT              yuvFormat  ;
    u_char                    mixerWinID ;

};

struct VIDEO_RPC_ENC_VIDEOSOURCE
{
    long                  instanceID;
    enum VIDEO_SOURCE     videoSource;  /* TVD or DIN */
    /*                    - the values are defined below.
                                  0	= TVD
                                  1	= DIN                               */
};

struct VIDEO_RPC_ENC_SOURCEFILE
{
    long      instanceID;
    char      fileName[20];
    long      length;
};

struct VIDEO_RPC_ENC_SET_RESOLUTION
{
    long                       instanceID;
    long      hres;
    /*        - horizontal resolution, out of the values 720, 704, 360, and 352.
    		In the future, 128 to 720 multiple of 16
    		vertical resolution is determined by VIDEO_FORMAT 480 for NTSC, 576 for PAL
    */
    int       SIF;
    /*
    	      -if SIF is 1, hres is ingored and is fixed to 352, vres is 240 for NTSC and 288 for PAL 	*/
};

struct VIDEO_RPC_ENC_SET_BITRATE
{
    long                            instanceID     ;
    enum  VIDEO_RATE_CONTROL_MODE   rateControlMode;
                                                       /* - the method of rate control. The values are defined:
                                                          0	= CBR	Constant bit-rate
					  	VBV_delay will be filled in, zero stuffing turned on
					  	peakBitRate is ignored. bitFufferSize will be VBVSize, initBufferFufferFullness
					  	will be initVBVFullness
                                          1	= VBR	Variable bit-rate
					  	VBV_delay will be 0xFFFF, initVBVFullness=VBVSIZE=MAXVBVSIZE
					  2	= CVBR contant VBR
					  	VBV_delay will be 0xFFFF, zero stuffing turned on
						time is ignored, initVBVFullness=VBVSIZE=MAXVBVSIZE
						*/
    long	peakBitRate;
    /*          - the maximum bit-rate in unit of bits/s.     */
    long        aveBitRate;
    /*          - the average bit-rate in unit of bits/s.     */
    long        bitBufferSize;
    /*          - For VBR, the size of bit-rate variation. For CBR, it is vbv size. */
    long        initBufferFullness;
    /*          - For VBR the initial buffer fullness.  For CBR, it is initial vbv fullness */
    long	time;
    /*		- in seconds. At the end of this time, bitrate will be controled within bitFufferSize	*/
    /* Note: Minimum I picture size is 2kBytes to help the mux operation */
};


struct VIDEO_RPC_ENC_SET_GOPSTRUCTURE
{
    long        instanceID;
    long        M         ;
    /*          - the distance in unit of frames between two anchor frames.
                  The number of B pictures will be M - 1 between two I/P pictures.    */
    long        N;
    /*          - the minimum number of fields in one GOP is 2N. For 3:2 case, the number of
    		pictures could be less than N, otherwise it is always N
		Note: With fixed M, the total fields per GOP could be 2N+8.
		in the future with 3:2, we may change the last B frame to P frame to
		ensure the total number of fields is 2N or 2N+1. */
};


struct VIDEO_RPC_ENC_SET_NEWGOPONSC
{
    long        instanceID;
    long        newGOPOnSceneChange;
    /*          - if the value is true, the encoder will
                  start a new GOP whenever it detects scene changes.    */
};

struct VIDEO_RPC_ENC_SET_INV32DETECT
{
    long        instanceID;
    long        inverseTelecineDetection;
    /*          - if the value is true, the encoder will turn on the 3:2 pull-down
                  detection, and applies the proper operations if it detects. */
};

struct VIDEO_RPC_ENC_SET_TF{
    long        instanceID;
    long        mode;    /* off, MATF or MCTF */
    /*          - the mode for temporal filtering. The values and meanings are described below.
        0 =	Off,    No temporal filtering.
        1	= MATF,   Motion adaptive temporal filtering.
        2 = MCTF,   Motion compensated temporal filtering.
        3	= AMCTF,  Adaptive motion compensated temporal filtering.       */
    long        strength;
    /*          - the strength of temporal filtering. The valid ranges are from 0 to 15, inclusive.            */
};

struct VIDEO_RPC_ENC_SET_NR{
    long        instanceID;
    long        Hstrength;
    /*          - the strength of horizontal NR. The valid ranges are from 0 to 15, inclusive. 0 to turn off.   */
    long        Vstrength;
    /*          - the strength of vertical NR. The valid ranges are from 0 to 15, inclusive. 0 to turn off.     */
};

struct VIDEO_RPC_ENC_SET_ENCFORMAT
{
    long                      instanceID;
    enum VIDEO_STREAM_TYPE    streamType;        /* MPEG1 or MPEG2 or MPEG4 */
    /*                        - the encoded bitstream format. The values are defined in the below table.
                                        0 = MPEG-2 (ISO/IEC 13818-2)
                                        1 = MPEG-1 (ISO/IEC 11172-2)
                                        2 = MPEG-4 Part II (ISO/IEC 14496-2)
                                        3 = Divx3
                                        4 = DV                                 */
};

struct VIDEO_RPC_ENC_CONFIG_CCDATA
{
    long        instanceID;
    long        option;
    long        CCDataSize;
    u_char      CCDAta[128];
};

struct VIDEO_RPC_ENC_SET_CLOSEDGOPFREQ
{
    long        instanceID;
    long        closedGOPFreq;
    /*          - if the number of open GOPs that is beyond the last closed GOP exceeds
                      this number, inclusively, the next GOP will be a closed GOP.          */

};

struct VIDEO_RPC_ENC_START_ENC
{
    long        instanceID;
  long        startMode; /* 0: wait for input; 1: start immediately */
};

struct VIDEO_RPC_ENC_PAUSE_ENC
{
    long        instanceID  ;
    long        pausedAtVOBU;
    /*          - if the value is true, the encoder will pause at the next VOBU start
    		otherwise, it will pause immediately */
};

struct VIDEO_RPC_ENC_STOP_ENC
{
    long        instanceID;
};

struct VIDEO_RPC_ENC_CONFIG_VOBU
{
    long        instanceID;
    long        minGOPs;
    /*          - minimum number of GOPs per VOBU. VOBU should be between 0.4 to 1.2 seconds and at least this number
    		of GOPs inclusive
    */
};

struct VIDEO_RPC_ENC_MPEG_I_ENC
{
    long        pIFrameStream;
    long        pTargetLuma;
    long        pTargetChroma;
    long        width;
    long        height;
    long        maxSize;
};

struct VIDEO_RPC_ENC_SET_VBID_WSS_FREQ
{
    long       instanceID;
    long       numOfField;
};

struct VIDEO_RPC_ENC_SET_VBV
{
    long        instanceID;
	long       vbv_buf_size ;      /* VBV buffer size     */
	long       vbv_buf_fullness ;  /* VBV buffer fullness */
};

struct VIDEO_RPC_ENC_SET_NONREALTIME
{
    long       instanceID;
	u_char     bNonRealTime ;      /* Non real time     */
};

struct VIDEO_RPC_ENC_SET_NEW_RESOLUTION
{
    long                       instanceID;
    long                       in_width  ;
    long                       in_height ;
    long                       out_width ;
    long                       out_height;
};

struct VIDEO_RPC_ENC_SET_FRAME_RATE
{
    long        instanceID;
    long        frame_rate;
};

struct VIDEO_RPC_ENC_SEND_TVD_INFO
{
    long                  instanceID;
    enum VIDEO_FORMAT     videoFormat;
    long                  Macrovision;
    /*
    000 = No copy protection
    001 = AGC process present (Macrovision Type 1 present)
    010 = Colorstripe process Type 2 present
    011 = AGC process and colorstripe process Type 2 present
    100 = Reserved
    101 = Reserved
    110 = Colorstripe process Type 3 present
    111 = AGC process and color stripe process Type 3 present
    */
    long                  reserved0;
    long                  reserved1;
};

struct VIDEO_RPC_ENC_REQ_KEY_FRAME
{
    long        instanceID;
};

struct VIDEO_RPC_ENC_SET_PROFILE
{
    long        instanceID;
		enum  VIDEO_ENC_PROFILE   profile;
};

/****************************************
 * \defgroup Video_Out_Data_Type structures for the Video Output APIs.
 *
 * @{
 ****************************************/

struct VIDEO_RPC_VOUT_SET_VIDEO_STANDARD
{
  enum VO_STANDARD       standard ;
  u_char                 enProg ;
  u_char                 enDIF ;
  u_char                 enCompRGB ;
  enum VO_PEDESTAL_TYPE  pedType ;
} ;

struct VIDEO_RPC_VOUT_CONFIG_VIDEO_STANDARD
{
  enum VO_STANDARD       standard ;
  u_char                 enProg ;
  u_char                 enDIF ;
  u_char                 enCompRGB ;
  enum VO_PEDESTAL_TYPE  pedType ;
  unsigned int           dataInt0  ;
  unsigned int           dataInt1  ;
  u_char                 hdmiState ;
} ;

struct VIDEO_RPC_VOUT_SET_HDMI
{
  enum VO_HDMI_MODE              hdmiMode ;
  enum VO_HDMI_AUDIO_SAMPLE_FREQ audioSampleFreq ;
  u_char                         audioChannelCount ;
} ;

struct VIDEO_RPC_VOUT_CONFIG_HDMI
{
  enum VO_HDMI_MODE              hdmiMode ;
  enum VO_HDMI_AUDIO_SAMPLE_FREQ audioSampleFreq ;
  enum VO_HDMI_COLOR_FMT         colorFmt ;
  u_char                         audioChannelCount ;
} ;

struct VIDEO_RPC_VOUT_CONFIG_HDMI_INFO_FRAME
{
  enum VO_HDMI_MODE              hdmiMode ;
  enum VO_HDMI_AUDIO_SAMPLE_FREQ audioSampleFreq ;
  u_char                         audioChannelCount ;
  u_char                         dataByte1 ;
  u_char                         dataByte2 ;
  u_char                         dataByte3 ;
  u_char                         dataByte4 ;
  u_char                         dataByte5 ;
  unsigned int                   dataInt0  ;
  long                           reserved1 ;
  long                           reserved2 ;
  long                           reserved3 ;
  long                           reserved4 ;
} ;

struct VIDEO_RPC_VOUT_SET_BKGRND
{
  struct VO_COLOR  bgColor ;
  u_char           bgEnable ;
} ;


struct VIDEO_RPC_VOUT_SET_MIXER_ORDER
{
   u_char                      pic ;
   u_char                      dd ;
   u_char                      v1 ;
   u_char                      sub1 ;
   u_char                      v2 ;
   u_char                      osd1 ;
   u_char                      osd2 ;
   u_char                      csr ;
   u_char                      reserved1 ;
   u_char                      reserved2 ;
   u_char                      reserved3 ;
   u_char                      reserved4 ;
   u_char                      reserved5 ;
} ;



struct VIDEO_RPC_VOUT_SET_CC
{
  u_char enCC_odd ;
  u_char enCC_even ;
} ;



struct VIDEO_RPC_VOUT_SET_APS
{
  u_char           enExt ;
  enum VO_VBI_APS  APS ;
} ;



struct VIDEO_RPC_VOUT_SET_COPY_MODE
{
  u_char                 enExt ;
  enum VO_VBI_COPY_MODE  copyMode ;
} ;



struct VIDEO_RPC_VOUT_SET_AR
{
  u_char                    enExt ;
  enum VO_VBI_ASPECT_RATIO  aspectRatio ;
} ;


struct VIDEO_RPC_VOUT_CONFIG_DISP_WIN
{
  enum   VO_VIDEO_PLANE  videoPlane ;
  struct VO_RECTANGLE    videoWin ;
  struct VO_RECTANGLE    borderWin ;
  struct VO_COLOR        borderColor ;
  u_char                 enBorder ;
} ;


struct VIDEO_RPC_VOUT_SET_RESCALE_MODE
{
  enum   VO_VIDEO_PLANE   videoPlane ;
  enum   VO_RESCALE_MODE  rescaleMode ;
  struct VO_RECTANGLE     rescaleWindow ;
  u_char                  delayExec ;
} ;


struct VIDEO_RPC_VOUT_SET_DEINT_MODE
{
  enum VO_VIDEO_PLANE  videoPlane ;
  enum VO_DEINT_MODE   deintMode ;
} ;


struct VIDEO_RPC_VOUT_ZOOM
{
  enum   VO_VIDEO_PLANE  videoPlane ;
  struct VO_RECTANGLE    zoomWin ;
} ;


struct VIDEO_RPC_VOUT_PAN_ZOOM
{
  enum   VO_VIDEO_PLANE  videoPlane ;
  struct VO_RECTANGLE    zoomWinStart ;
  struct VO_RECTANGLE    zoomWinEnd ;
  u_short                time;
} ;

struct VIDEO_RPC_VOUT_TRANSPARENCY
{
  enum   VO_VIDEO_PLANE  videoPlane ;
  u_short                alphaStart ;
  u_short                alphaEnd ;
  u_short                time;
} ;

struct VIDEO_RPC_VOUT_CONFIG_OSD
{
  enum VO_OSD_LPF_TYPE  lpfType ;
  short                 RGB2YUVcoeff[12] ;
} ;


struct VIDEO_RPC_VOUT_CONFIG_OSD_PALETTE
{
  u_char                      paletteIndex ;
  long                        pPalette ;
} ;


struct VIDEO_RPC_VOUT_CREATE_OSD_WIN
{
  struct VO_RECTANGLE         winPos ;
  enum   VO_OSD_COLOR_FORMAT  colorFmt ;
  int                         colorKey ;
  u_char                      alpha ;
} ;


struct VIDEO_RPC_VOUT_SET_OSD_WIN_PALETTE
{
  u_char                      winID ;
  u_char                      paletteIndex ;
} ;


struct VIDEO_RPC_VOUT_MODIFY_OSD_WIN
{
  u_char                      winID ;
  u_char                      reqMask ;
  struct VO_RECTANGLE         winPos ;
  enum   VO_OSD_COLOR_FORMAT  colorFmt ;
  int                         colorKey ;
  u_char                      alpha ;
  u_short                     startX ;
  u_short                     startY ;
  u_short                     imgPitch ;
  long                        pImage ;
  u_char                      go ;
} ;


struct VIDEO_RPC_VOUT_DRAW_OSD_WIN
{
  u_short  winID ;
  u_short  startX ;
  u_short  startY ;
  u_short  imgPitch ;
  long     pImage ;
  u_char   go ;
} ;


struct VIDEO_RPC_VOUT_HIDE_OSD_WIN
{
  u_short  winID ;
  u_char   go ;
} ;


struct VIDEO_RPC_VOUT_DELETE_OSD_WIN
{
  u_short  winID ;
  u_char   go ;
} ;


struct VIDEO_RPC_VOUT_CONFIG_OSD_CANVAS
{
  struct VO_RECTANGLE         srcWin ;
  struct VO_RECTANGLE         dispWin ;
  u_char                      go ;
} ;


struct VIDEO_RPC_VOUT_CONFIG_CURSOR
{
  char                 alpha ;
  char                 colorKey ;
  struct VO_COLOR      colorMap[4] ;
  enum VO_OSD_LPF_TYPE lpfType ;
  long                 pCursorImg ;
} ;


struct VIDEO_RPC_VOUT_CONFIG_MARS_CURSOR
{
  u_short                  width ;
  u_short                  height ;
  enum VO_OSD_COLOR_FORMAT colorFmt ;
  u_char                   paletteIndex ;
  long                     pCursorImg ;
} ;


struct VIDEO_RPC_VOUT_DRAW_CURSOR
{
  u_short x ;
  u_short y ;
} ;


struct VIDEO_RPC_VOUT_CONFIG_COLOR_MATRIX
{
  short                 ColorMatrixCoeff[12] ;
} ;


struct VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS
{
  enum VO_GRAPHIC_PLANE       plane ;
  struct VO_RECTANGLE         srcWin ;
  struct VO_RECTANGLE         dispWin ;
  u_char                      go ;
} ;


struct VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN
{
  enum VO_GRAPHIC_PLANE       plane ;
  struct VO_RECTANGLE         winPos ;
  enum VO_OSD_COLOR_FORMAT    colorFmt ;
  enum VO_OSD_RGB_ORDER       rgbOrder ;
  int                         colorKey ;
  u_char                      alpha ;
  u_char                      reserved ;
} ;


struct VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN
{
  enum VO_GRAPHIC_PLANE        plane ;
  u_char                       winID ;
  u_char                       reqMask ;
  struct VO_RECTANGLE          winPos ;
  enum VO_OSD_COLOR_FORMAT     colorFmt ;
  enum VO_OSD_RGB_ORDER        rgbOrder ;
  int                          colorKey ;
  u_char                       alpha ;
  enum VO_GRAPHIC_STORAGE_MODE storageMode ;
  u_char                       paletteIndex ;
  u_char                       compressed ;
  u_char                       interlace_Frame ;
  u_char                       bottomField ;
  u_short                      startX[4] ;
  u_short                      startY[4] ;
  u_short                      imgPitch[4] ;
  long                         pImage[4] ;
  u_char                       reserved ;
  u_char                       go ;
} ;


struct VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN
{
  enum VO_GRAPHIC_PLANE        plane ;
  u_short                      winID ;
  enum VO_GRAPHIC_STORAGE_MODE storageMode ;
  u_char                       paletteIndex ;
  u_char                       compressed ;
  u_char                       interlace_Frame ;
  u_char                       bottomField ;
  u_short                      startX[4] ;
  u_short                      startY[4] ;
  u_short                      imgPitch[4] ;
  long                         pImage[4] ;
  u_char                       reserved ;
  u_char                       go ;
} ;


struct VIDEO_RPC_VOUT_HIDE_GRAPHIC_WIN
{
  enum VO_GRAPHIC_PLANE       plane ;
  u_short                     winID ;
  u_char                      go ;
} ;


struct VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN
{
  enum VO_GRAPHIC_PLANE       plane ;
  u_short                     winID ;
  u_char                      go ;
} ;


struct VIDEO_RPC_VOUT_DISPLAY_GRAPHIC_WIN
{
  long                         x ;
  long                         y ;
  long                         width ;
  long                         height ;
  enum VO_OSD_COLOR_FORMAT     colorFmt ;
  enum VO_OSD_RGB_ORDER        rgbOrder ;
  long                         colorKey ;
  long                         alpha ;
  enum VO_GRAPHIC_STORAGE_MODE storageMode ;
  long                         paletteIndex ;
  long                         compressed ;
  long                         interlace_Frame ;
  long                         bottomField ;
  long                         startX[4] ;
  long                         startY[4] ;
  long                         imgPitch[4] ;
  long                         pImage[4] ;
  long                         reserved0 ;
  long                         reserved1 ;
} ;


struct VIDEO_RPC_VOUT_DISPLAY_GRAPHIC
{
  enum VO_GRAPHIC_PLANE       plane ;
  u_char                      osdNum ;
  long                        pGraphic ;
} ;


struct VIDEO_RPC_VOUT_HACK_GRAPHICCANVAS
{
  enum VO_GRAPHIC_PLANE       plane ;
  enum VO_HACK_CANVAS_MODE    mode ;
} ;


struct VIDEO_RPC_VOUT_VIDEO_CAPTURE
{
  enum   VO_OSD_COLOR_FORMAT  colorFmt ;
  long                        pImage ;
  u_short                     imgPitch ;
  u_short                     startX ;
  u_short                     startY ;
  u_short                     width ;
  u_short                     height ;

} ;



/** @} */

struct VIDEO_RPC_VO_FILTER_DISPLAY
{
	long                 instanceID ;
  enum VO_VIDEO_PLANE  videoPlane ;
  u_char               zeroBuffer ;
  u_char               realTimeSrc ;
} ;


struct VIDEO_RPC_VO_FILTER_HIDE
{
	long                 instanceID ;
  enum VO_VIDEO_PLANE  videoPlane ;
} ;


struct VIDEO_RPC_VO_FILTER_DISP_BD_COLOR
{
	long                 instanceID ;
  enum VO_VIDEO_PLANE  videoPlane ;
} ;


struct VIDEO_RPC_VO_FILTER_SET_SPEED
{
	long  instanceID ;
  long  speed ;
} ;


struct VIDEO_RPC_VO_FILTER_SHOW_STILL_PIC
{
	long  instanceID ;
	long  lumaAddr ;
	long  lumaPitch ;
	long  chromaAddr ;
	long  chromaPitch ;
  long  width ;
  long  height ;
} ;


struct VIDEO_RPC_VO_FILTER_FILL_VIDEO_BORDER
{
  long  instanceID ;
  long  border ;
  long  num_pixels ;

  struct VO_COLOR  fillColor ;
} ;


struct VIDEO_RPC_VO_FILTER_SET_FAST_DISPLAY
{
  long instanceID ;
  u_char enFastDisplay ;
  u_char count ;
} ;

struct VIDEO_RPC_VO_FILTER_CAPTURE
{
	long                        instanceID ;
  enum   VO_OSD_COLOR_FORMAT  colorFmt ;
  long                        pImage ;
  u_short                     imgPitch ;
  u_short                     startX ;
  u_short                     startY ;
  u_short                     width ;
  u_short                     height ;

  long                        pStretchBuf ;
  long                        stretchBufSize ;

  long                        pImage_C ;
  u_short                     imgPitch_C ;

} ;


struct VIDEO_RPC_VO_FILTER_ENABLE_3D_MODE_DETECT
{
  long                        instanceID ;
  u_char                      enable ;
  enum YUV_FMT                yuvFormat ;
  u_short                     fullWidth ;
  u_short                     fullHeight ;
} ;


struct VIDEO_RPC_VO_FILTER_CLEAR_VIDEO
{
  long                        instanceID ;
  struct VO_COLOR  			  fillColor ;
} ;


struct VIDEO_RPC_VO_FILTER_Config_SyncAV
{
  long instanceID ;
  u_char enable ;
} ;


struct VIDEO_RPC_VO_FILTER_Config_VoFreeze
{
  long instanceID ;
  u_char enable ;
} ;


struct VIDEO_RPC_VO_FILTER_Config_DisplayDelay
{
  long instanceID ;
  long delay ;
} ;


struct VIDEO_RPC_VO_FILTER_ConnectVDec
{
  long instanceID ;
  u_char nPort ;
} ;


struct VIDEO_RPC_VO_FILTER_Config_Mastership
{
  long instanceID ;
  u_char useSTC ;
  u_char lipsyncMaster ;
  u_char audioChannel ;
} ;


struct VIDEO_RPC_VO_FILTER_Config_Dual3D
{
  long instanceID ;
  u_char enable ;
} ;


struct VIDEO_RPC_VO_FILTER_SET_APP_TYPE
{
  long                      instanceID ;
  enum VO_APP_TYPE          appType ;
} ;
struct VIDEO_RPC_SUBPIC_DEC_ENABLE_SUBPIC
{
	long    instanceID ;
  u_char  alwaysOnTop ;
} ;

struct VIDEO_RPC_SUBPIC_DEC_CONFIGURE
{
  long    instanceID ;
  u_short fullWidth ;
  u_short fullHeight ;
  enum SP_STREAM_TYPE streamType ;
} ;

struct VIDEO_RPC_SUBPIC_DEC_PAGE{
    long                instanceID ;
    unsigned short      page_id_composition;
    unsigned short      page_id_ancillary;
} ;


struct VIDEO_RPC_DIRECT_VO_OPEN
{
    long	instanceID;
    unsigned int version_num;
};

struct VIDEO_RPC_DIRECT_VO_RUN
{
    long	instanceID;
    long 	shmPhyAddr;
    long 	versionNum;
    long	video_port;
    long	dolbyVision;
    long	dolbyVisionProfile;
};


struct VIDEO_RPC_DIRECT_VO_STOP
{
    long	instanceID;
    long 	shmPhyAddr;
};

struct VIDEO_RPC_DIRECT_VO_FLUSH
{
    long	instanceID;
    long	video_port;
};


 struct DOLBY_VISION_CAPTURE_BUFFER_T{
	unsigned long uncacheAddr;
	unsigned long cacheAddr;
	unsigned long phyaddr;
	unsigned int size;
};

 struct DOLBY_VISION_CAPTURE_INFO{
    DOLBY_VISION_CAPTURE_BUFFER_T bufAddr_md[2];		/* IDMA meta data capture buffer */
    DOLBY_VISION_CAPTURE_BUFFER_T bufAddr_video[2];	/* IDMA video capture buffer */
    DOLBY_VISION_CAPTURE_BUFFER_T bufAddr_graph[2];	/* IDMA graphic capture buffer */
 };


struct VIDEO_RPC_DOLBY_VISION_HDMI_SET_DETECT_ENABLE
{
    long	instanceID;
    long	detect_en;
    long	display_en;
    DOLBY_VISION_CAPTURE_INFO capInfo;	/* IDMA capture buffer info */
};


struct VIDEO_RPC_DOLBY_VISION_HDMI_GET_DETECT_INFO
{
    long	instanceID;
    long	detect_ret;
};


struct VIDEO_RPC_DOLBY_VISION_HDMI_SET_DISPLAY_ENABLE
{
    long	instanceID;
    long	display_en;
};



/*******************************************
 * structures for the Video input(TVD)APIs *
 ******************************************/
struct VIDEO_RPC_TVD_CONFIG
{
	enum ENUM_TVD_VIDEO_FORMAT		video_fmt;
	enum ENUM_TVD_INPUT_FORMAT		input_fmt;
	enum ENUM_TVD_YC_SEP_MODE		ycsep_mode;
	u_char default_ycsep; /*use default value for YC separation*/
	u_char mv_workaround_en; /*Enable the work-around for MacroVision, which would enable Auto_positioning*/
};

struct VIDEO_RPC_TVD_VIDEO_FORMAT
{
  enum ENUM_TVD_VIDEO_FORMAT format;
};

struct VIDEO_RPC_TVD_INPUT_FORMAT
{
  enum ENUM_TVD_INPUT_FORMAT format;
};

struct VIDEO_RPC_TVD_YC_SEP_MODE
{
  enum ENUM_TVD_YC_SEP_MODE mode;
};

struct VIDEO_RPC_TVD_VBI_CTRL
{
  u_char VBI_slicer_en;
};

struct VIDEO_RPC_TVD_ADJ_CONTRAST
{
	u_char value;
};

struct VIDEO_RPC_TVD_ADJ_BRIGHTNESS
{
	u_char value;
};

struct VIDEO_RPC_TVD_ADJ_SATURATION
{
	u_char value;
};

struct VIDEO_RPC_TVD_ADJ_HUE
{
	u_char value;
};

struct VIDEO_RPC_TVD_BLUE_MODE
{
	u_char mode;
};

struct VIDEO_RPC_VIN_ADJ_SCALE_COEF
{
	u_short y_32th_coef;
	u_short c_16th_coef;
};

struct CHANNEL_RES {
	HRESULT hr;
	enum ENUM_TVD_VIDEO_FORMAT fmt;
};

struct VIDEO_RPC_JPEG_DEC
{
  long colorFormat;				  /* 0: YUV, 1: RGB8888, 2: RGB565, 3: RGB332 */
                            /* please use enum IMG_TARGET_FORMAT
                               and set bit N to 1 represent
                               bit17: panscan
                               bit20: stretch and transfer picture to Y and UV sequential buffer (only for SATURN and later chip)
                               bit21: disable blending white color for color format with alpha
                               bit24: saveToLargeBuf
                               bit25: useLargeBuf
                               bit26: scratch buffer provided by system and decode small picture
                               bit28: JPS file    (only for SATURN and later chip)
                               bit29: SE_BitBlit with fb_premultiply
                            */
  long pBitstreamRB;				/* Linear address of bitstream ring buffer. */
  long pTargetLuma;					/* Linear address of Luman buffer. */
  long pTargetChroma;				/* Linear address of Chroma buffer. */
  long pitch;

  long targetRectX;
  long targetRectY;
  long targetRectWidth; 		/* width of the target rectangle to store the decoded picture */
  long targetRectHeight;		/* height of the target rectangle to store the decoded picture */
  long centerToTargetRect;      /* if 1, decode to center of the target rectangle.
                                   if 0, decode to upper-left most position of the target rectangle.
                                   if 2: scale to display window regardless of source AR
                                   (please use enum IMG_TARGET_POSITION) */

  /* JPEG decoder will fit either the width or heigh to this rectangle based on the source width or height
     ratio to display the full picture.
  */
  enum VIDEO_JPEG_ROTATION rotation;
  /*                    - the values are defined below.
			0	= 0
			1	= 90
			2	= 180
			3	= 270
  */
  long srcRectAlignmentRatioX;   /* The alignment ratio is expressed as a 1.8 fixed-point number.
                                    For example,
                                        If 256, the maximal legal value, the extracted area is aligned to right-most position.
                                        If 0, the minimal legal value, the extracted area is aligned to left-most position.
                                    In general, if n, the extracted area is aligned to (n/256) of the horizontal position,
                                        relative to the X=0 line. */
  long srcRectAlignmentRatioY;   /* The alignment ratio is expressed as a 1.8 fixed-point number.
                                    For example,
                                        If 256, the maximal legal value, the extracted area is aligned to lower-most position.
                                        If 0, the minimal legal value, the extracted area is aligned to upper-most position.
                                    In general, if n, the extracted area is aligned to (n/256) of the vertical position,
                                        relative to the Y=0 line. */
  long srcRectZoomFactor;        /* The zoom factor is expressed as a 1.8 fixed-point number.
                                    For example,
                                        If 256, the full-sized jpeg file will be decoded. (MAXIMUM)
                                        If 1, the extracted area is (1/256)*(1/256) of the original one. (MINIMUM)
                                    In general, if n, the extracted area is (n/256)*(n/256) of the original one. */

  long initOption;			     /* if -1, initialize only.
                                    if 0, decode, and, if needed, initialize.
                                    if 1, destroy only. */

  long pSharedJpegDecCtrl;


  long useWholePictureOnly;      /* If 0, FIRMWARE can optionally choose either the whole picture or the embedded thumbnail picture to decode.
                                    If 1, FIRMWARE will decode the whole picture, not concerning about the embedded thumbnail.
                                    If 2, FIRMWARE will decode the embedded thumbnail only
                                   (please use enum IMG_SOURCE_PICTURE_SELECT) */

  long ScaleUpToRect;	/* if image is smaller than Target Rect
                         0: keep actual size, but can't apply to ZOOM
                         1: scale-up to Rect
                         2: turn on acutal zoom */

  long FillBlackInRect;	/* fill black if image is smaller than Target Rect */
  long SmoothLevel;	/* 0~9 to smooth more or not */

  enum VIDEO_JPEG_MIRROR mirror ; /* don't support YUV */

  long pTargetLuma_right ;    /* set right eye bufferID to -1 if VO isn't 3D display  */
  long pTargetChroma_right ;

  /* use below parameters to stretch picture and transfer to sequential Y and UV if bit 20 of colorFormat is 1 */
  long pLumaSeq ;             /* sequential buffer address for Y */
  long pChromaSeq ;           /* sequential buffer address for UV */
  u_short pitchYSeq ;         /* pitch  of Y buffer (Must be mutiple of 16) */
  u_short pitchCSeq ;         /* pitch  of UV buffer (Must be mutiple of 16) */
  u_short widthSeq ;          /* width of sequential picture (Must be mutiple of 16) */
  u_short heightSeq ;         /* height of sequential picture */

  long cropRectX;
  long cropRectY;
  long cropRectWidth;
  long cropRectHeight;
  long cropBuffer;
  long reserved ;

};

struct VIDEO_RPC_JPEG_DEC_BATCH
{
  long number;          /* how many JPEG are decoded */
  long structure_addr;  /* shared memory of data structure struct VIDEO_RPC_JPEG_DEC */
};

struct VIDEO_RPC_TRANSITION_EFFECT
{
	long instantID;
	long YBufID_A;
	long YBufID_B;
	long CBufID_A;
	long CBufID_B;
	long width;
	long height;
	long type;			/* transition type in VIDEO_TRANSITION_TYPE */
	long frame_num;		/* how many frames for this transition */
	long PTS_inc;		/* PTS between each frames */
	long start_x;       /* for TRANSITION_MOVE effect */
	long start_y;
	long start_width;
	long start_height;
	long end_x;
	long end_y;
	long end_width;
	long end_height;

	long pSharedTransEffCtrl;


	long YBufID_A_right ;   /* set right eye bufferID to -1 if VO isn't 3D display or source is 3D picture */
	long YBufID_B_right ;
	long CBufID_A_right ;
	long CBufID_B_right ;

};

struct VIDEO_RPC_MIXER_FILTER_CONFIGURE
{
  long                         instanceID ;
  u_short                      width ;
  u_short                      height ;
  u_char                       EnablebgPicture ;
  struct VO_COLOR              bgColor ;

  enum VO_OSD_COLOR_FORMAT     colorFmt ;
  enum VO_GRAPHIC_STORAGE_MODE storageMode ;
  struct VO_RECTANGLE          SrcWin ;
  struct VO_RECTANGLE          dispWin ;
  u_short                      startX  [2] ;
  u_short                      startY  [2] ;
  u_short                      imgPitch[2] ;
  long                         pImage  [2] ;

} ;

struct VIDEO_RPC_MIXER_FILTER_CONFIGURE_WIN
{
  long                  instanceID ;
  long                  count ;
  struct MIXER_WIN      win[8] ;

} ;

struct VIDEO_RPC_MIXER_FILTER_SET_MASTER_WIN
{
  long                 instanceID ;
  unsigned char        winID ;
} ;

struct VIDEO_RPC_MIXER_PLAY_ONE_MOTION_JPEG_FRAME
{
  u_char                        mixerWinID ;
  enum VIDEO_STREAM_TYPE        stream_type;
  enum YUV_FMT                  yuv_fmt    ;
  long                          base       ;
  long                          size       ;
  long                          width      ;
  long                          height     ;

} ;

struct VIDEO_RPC_MIXER_FILTER_CAPTURE
{
	long                        instanceID       ;
  enum   VO_OSD_COLOR_FORMAT  colorFmt         ;
  long                        pImage        [2];
  u_short                     imgPitch      [2];
  u_short                     startX        [2];
  u_short                     startY        [2];
  u_short                     width         [2];
  u_short                     height        [2];

  long                        pStretchBuf   [2];
  long                        stretchBufSize[2];

  long                        pImage_C      [2];
  u_short                     imgPitch_C    [2];

} ;


struct VIDEO_RPC_YUYV_TO_RGB
{
  long                     yuyv_addr     ;
  long                     rgb_addr      ;
  long                     width         ;
  long                     height        ;
  long                     imgPitch      ;

  enum YUV_FMT             yuv_fmt       ;
  enum IMG_TARGET_FORMAT   rgb_fmt       ;
} ;


/**
 * \brief This struct defines the structure of the memory space set by the system
 *        for the video firmware to report its status to the system and for other
 *        video firmware internal debug purposes.
 */
struct VIDEO_RPC_DEBUG_MEMORY
{
	long videoFirmwareVersion ;
} ;


/* oliver+ */
struct SCALER_RPC_STRUCT
{
  unsigned long                  ulCmd;       /* RPC command */
  unsigned long                  ulArgAddr;   /* Share memory physical address */
  unsigned long                  ulArgSize;   /* Share memory size */
} ;


struct SCALER_RPC_SHARE_MEM
{
  unsigned long                  ulAddr[50];       /* struct memory addr in share memory */
} ;


struct VIDEO_RPC_VOUT_VODMA_ENABLE
{
  enum VO_VIDEO_PLANE 	videoPlane;
  u_char  				enable;
} ;


struct VIDEO_RPC_VOUT_FRAMERATE_CONTROL_STRUCT
{
  u_char		opCode;						/* frame rate control RPC OP code */
  u_char		curDispMode;						/* current 2D/3D mode status for frame rate control */
  u_char		enableForceFrameRate[2] ;		/* enable force framerate, regardless of double dvs and boundary check */
  unsigned int	ForceFrameRate[2] ;			/* force display framerate = ForceFrameRate (in 0.001 Hz) */

  u_char		enableDoubleDvs[2] ;			/* enable double dvs, multiply framerate for panel spec */
  unsigned int	DoubleDvsThreshold[2] ;		/* multiply framerate if framerate <= DoubleDvsThreshold (in 0.001 Hz) */

  u_char		enableHighBound[2] ;			/* enable high-bound check */
  unsigned int	HighBound[2] ;					/* set framerate = HighAdjust if framerate > HighBound (in 0.001 Hz) */
  unsigned int	HighAdjust[2] ;

  u_char		enableLowBound[2] ;			/* enable low-bound check */
  unsigned int	LowBound[2] ;					/* set framerate = LowAdjust if framerate < LowBound (in 0.001 Hz) */
  unsigned int	LowAdjust[2] ;
} ;


struct VIDEO_RPC_VO_FILTER_SET_SOURCE_TYPE
{
  long						instanceID ;
  enum VO_SOURCE_TYPE		sourceType ;
} ;


struct VIDEO_RPC_VOUT_DECIMATE_STRUCT
{
	enum VO_VIDEO_PLANE		videoPlane ;		/* video plane */
	u_char					HorDecimate;		/* horizontal decimate ratio*/
	u_char					VerDecimate;		/* vertical decimate ratio*/
} ;


struct VIDEO_RPC_VOUT_SET_SCALER_AR_MODE
{
	enum VO_VIDEO_PLANE		videoPlane ;		/* video plane */
	enum VO_SCALER_AR_MODE	ScalerARMode ;		/* aspect raio mode*/
} ;


struct VIDEO_RPC_VOUT_CONFIG_SCALER_AR_CUSTOMER_MODE
{
	enum VO_VIDEO_PLANE		videoPlane ;	/* video plane */
	u_short  				customerX;				/* crop customerX percent from left, in 0.01%. set 1250 means 12.5% */
	u_short  				customerY;				/* crop customerY percent from top, in 0.01%. set 1250 means 12.5% */
	u_short  				customerW;				/* take customerW percent as width, in 0.01%. set 7500 means 75% */
	u_short  				customerH;				/* take customerH percent as height, in 0.01%. set 7500 means 75% */
} ;


struct VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE
{
  enum VO_VIDEO_PLANE 	videoPlane;
  u_char  				enable;
} ;


struct VIDEO_RPC_VOUT_VODMA_ZOOM_RATE
{
  enum VO_VIDEO_PLANE 	videoPlane;				/* video plane */
  u_char  				zoomRate;				/* 0~100:overscan, 100~200:zoom */
} ;


struct VIDEO_RPC_VOUT_VODMA_POS_FIUNTUNE
{
  enum VO_VIDEO_PLANE 	videoPlane;
  int  				shift_h;
  int  				shift_v;
  int  				shift_w;
  int  				shift_l;
} ;


struct VIDEO_RPC_VOUT_FORCEBG_CTRL
{
  u_char 				ForceBGType;			/* combination of VO_FORCEBG_TYPE */
  u_char  				enable;
} ;


struct VIDEO_RPC_VOUT_CONFIG_SCALEUP
{
  long            instanceID;
  u_char  			enable;		/* enable vodma scale up function*/
  unsigned int		tgtw;		/* target output width */
  unsigned int		tgth;		/* target output height */
} ;


struct VIDEO_RPC_VOUT_VODMA_CONFIG_VSGEN_IV_SRC
{
	enum VO_VIDEO_PLANE		videoPlane ;		/* video plane */
	enum VSGEN_IV_SRC		ivSrc ;				/* iv src sel */
} ;


struct VIDEO_RPC_VOUT_VSCINPUTTYPE
{
    u_char      vsc_source;
    u_char      vsc_port;
} ;


struct VIDEO_RPC_VOUT_CURRENT_BLK_TO_SEQ
{
	enum VO_VIDEO_PLANE		videoPlane ;		/* video plane */
	long					destAddrY;			/* the destination physical address for luma*/
	long					destAddrC;			/* the destination physical address for chroma*/
} ;


struct VIDEO_RPC_VOUT_SET_3D_MODE
{
  enum VO_VIDEO_PLANE	videoPlane ;		/* video plane */
  VO_3D_MODE_TYPE		mode_3d;
  u_short           LeftDirect ;
  u_short           LeftOffset ;
  u_short           RightDirect ;
  u_short           RightOffset ;

  unsigned int      dataInt0  ;
  unsigned int      dataInt1  ;
  unsigned int      dataInt2  ;
  unsigned int      dataInt3  ;
} ;


struct VIDEO_RPC_VOUT_SET_3D_OUTPUT_MODE
{
  enum VO_VIDEO_PLANE	videoPlane ;		/* video plane */
  VO_3D_MODE_TYPE		mode_3d;			/* 3d mode */
  VO_3D_OUTPUT_MODE		output_mode;		/* output mode, 0: orignal as 2d, 1: LR sequence */
} ;


struct VIDEO_RPC_VOUT_FORCE2D_MODE
{
  enum VO_VIDEO_PLANE	videoPlane ;		/* video plane */
  VO_FORCE2D_MODE		force2d_mode;
} ;


struct VO_2D3D_CONFIG
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	framerate;	/* 0.1 Hz */
	unsigned int	progressive;
	enum VO_CHROMA_FMT	chroma_fmt;
	unsigned int	data_bit_width;
	unsigned int	double_buf[3];
};


struct VIDEO_RPC_VOUT_CONFIG_HDMI_3D
{
  enum VO_VIDEO_PLANE 	videoPlane;
  unsigned int			width ;
  unsigned int			height ;
  unsigned int			progressive ;
  unsigned int			framerate ;
  enum VO_CHROMA_FMT	chroma_fmt ;
  unsigned int			data_bit_width ;
  unsigned int			hw_auto_mode ;
  unsigned int			l1_st_adr ;
  unsigned int			l2_st_adr ;
  unsigned int			r1_st_adr ;
  unsigned int			r2_st_adr ;
  unsigned int			quincunx_en ;
  unsigned int			quincunx_mode_fw ;
  unsigned int			sensio3D_en ;
  unsigned int			sg3d_dataFrc ;
  u_int 				i2rnd_sub_src;
  u_int 				i2rnd_display_table;
  unsigned int htotal;
	unsigned int vtotal;
  unsigned int              l3_st_adr;
  unsigned int              r3_st_adr;
  unsigned int			framerate_ori;
  long					reserved4 ;
} ;


struct VIDEO_RPC_VOUT_FORCE_HDMI_2D
{
  enum VO_VIDEO_PLANE 	videoPlane;
  u_char  				force2d;
  u_char  				l_flag;
} ;


struct VO_CAPTURE_CONFIG
{
	enum VO_VIDEO_PLANE 	videoPlane;
	unsigned int			width;
	unsigned int			height;
	unsigned int			framerate;	/* 0.1 Hz */
	unsigned int			progressive;
	enum VO_CHROMA_FMT		chroma_fmt;
	unsigned int			data_bit_width;
	unsigned int			double_buf[3];
};


struct VIDEO_RPC_VOUT_SET_OSD_4K2K_MODE
{
  OSD_4K2K_MODE_TYPE		osd_mode ;
  VO_4K2K_MODE_TYPE			vo_mode ;
  struct VO_RECTANGLE		srcWin ;
  struct VO_RECTANGLE		dispWin ;
} ;


struct VIDEO_RPC_VOUT_4K2K_SEQUENCE_CONTORL
{
  u_char		enable ;	/* enable 4k2k sequence control */
  u_char		sequence ;	/* assigned sequence number */
} ;


struct VIDEO_RPC_VOUT_CONFIG_3D_STRUCT
{
  enum VO_GRAPHIC_PLANE  plane ;            /* -1 represent to apply to all plane */
  u_char                 enable3D ;
  enum PANEL_3D_TYPE     panel_type ;            /* panel type 0:PR 1:SG */
} ;


struct VIDEO_RPC_VOUT_CONFIG_3D_OFFSET_STRUCT
{
  enum VO_GRAPHIC_PLANE  plane ;            /* -1 represent to apply to all plane */
  u_char                 closeToViewer ;   /* 0: close to viewer, 1: away from viewer */
  u_char                 offset ;           /* pixel number to offset */
} ;


/** The interface between the HWC and VO */
struct VIDEO_RPC_DIRECT_VO_FRAME_INFO {
    /** video information */
    uint32_t uVideoId; /* OMX buffer_id */
    int32_t nVideoLeft;
    int32_t nVideoTop;
    int32_t nVideoWidth;
    int32_t nVideoHeight;
    int32_t nVideoPitch;
    enum DIRECT_VO_FRAME_FORMAT eVideoFormat; /* current is DIRECT_VO_FRAME_FORMAT_YCBCR_422_I */
    enum DIRECT_VO_FRAME_LAYOUT eVideoLayout; /* current is DIRECT_VO_FRAME_MODE_SEQUENCE */
    enum DIRECT_VO_FRAME_SCAN_MODE eVideoScanMode;
    enum DIRECT_VO_FRAME_3D_TYPE eVideo3DType;
    int32_t nVideoFrameRate;
    uint32_t uVideoPhyAddr; /* physical address */
    uint32_t uVideoBufferSize;

    /** screen information */
    int32_t nScreenLeft;
    int32_t nScreenTop;
    int32_t nScreenWidth;
    int32_t nScreenHeight;
    int32_t nScreenRotation; /* ignore at this time */

    /** dolby vision information */
    uint32_t uVideoBLAddr;
    uint32_t uVideoELAddr;
    uint32_t uVideoMDAddr;

    /** presentation timestamp */
    int64_t llPts;

    /** synchronization */
    uint64_t ullVideoPts;
    enum DIRECT_VO_FRAME_FLAG eVideoFlag;

    /** reserved */
    uint32_t uReserved[3];
};


/** The shared memory definition */
struct VIDEO_RPC_DIRECT_VO_SHM {
    uint32_t picQWr;
    uint32_t picQRd;
    uint32_t picQDrop;
    uint32_t picQDropThresh;
    int64_t nReferencePts;
    DIRECT_VO_FRAME_CLOCK_TYPE eClockType;
    int32_t nPlayRate;
    uint32_t uProcessId;
    int32_t nAudioPort;
    int64_t llAudioRcd;
    uint32_t uSvpVersion;
    uint32_t uReserved[3];
    struct VIDEO_RPC_DIRECT_VO_FRAME_INFO frames[DIRECT_VO_FRAME_QUEUE_SIZE];
};


struct VIDEO_RPC_RESOURCE_INFO
{
    enum VIDEO_RESOURCE_CTRL_TYPE ctrl_type;
    enum VIDEO_RESOURCE_CORE_TYPE core_type;
    int32_t video_port;
    int32_t max_width;
    int32_t max_height;
    long instanceID;
    int32_t width;
    int32_t height;
    int32_t framerate;
};


struct VIDEO_RPC_K2V_PARAM {
	long reserve0 ;
	long reserve1 ;
	long reserve2 ;
	long reserve3 ;
};

struct VIDEO_RPC_VO_PHOTO_OPEN_T{
	unsigned int        ch;
	unsigned int        def;
	unsigned int        buf_addr;
	unsigned int        buf_size;	
};

struct VIDEO_RPC_VO_PHOTO_CONFIG_T{
	unsigned int        ch;
	HAL_VO_P_CFG_T        cfg;
};

struct VIDEO_RPC_VO_DISPLAYPICTURE_T{
	unsigned int        ch;
	HAL_VO_P_IMAGE_T      image;
};

struct VIDEO_RPC_VO_GETDEVICECAPABILITY_T {
	HAL_VO_P_DEVICE_CAPABILITY_T capability;
};

/**
 * This script describes VIDEO_SYSTEM APIs which system software could invoke/(be invoked) by RPC mechanism.
 * There are several groups of APIs in the VIDEO_SYSTEM APIs.
 * One group is APIs that are common to all video filters,
 * Others are specific APIs for dedicated video filters, such as DEC, VO, SPU_DEC, and etc.
 */

#define VIDEO_RPC_COMMON_FUNC_BASE               0
#define VIDEO_RPC_VDEC_FUNC_BASE              1000
#define VIDEO_RPC_VENC_FUNC_BASE              2000
#define VIDEO_RPC_VOUT_FUNC_BASE              3000
#define VIDEO_RPC_VIN_FUNC_BASE               4000
#define VIDEO_RPC_SPDEC_FUNC_BASE             5000
#define VIDEO_RPC_JPEGDEC_FUNC_BASE           6000
#define VIDEO_RPC_PSEUDO_FILTER_FUNC_BASE     7000
#define VIDEO_RPC_MIXER_FUNC_BASE             8000
#define VIDEO_RPC_VCAP_FUNC_BASE	      9000
#define VIDEO_RPC_DIRECT_VO_FUNC_BASE	10000
#define VIDEO_RPC_DOLBY_VISION_FUNC_BASE	11000
#define VIDEO_RPC_VO_PHOTO_FUNC_BASE		12000

program VIDEO_SYSTEM {
  version VERSION {

/**
 *  \defgroup common The common APIs
 *  Common APIs which all video filter should support to.
 *
 *  \author right
 *  @{
 */





/**
 *  \fn   RPCRES_LONG  VIDEO_RPC_ToAgent_Create (VIDEO_RPC_INSTANCE)
 *
 *  \brief To create a video filter in video cpu side.
 *	This function creates a video filter in video cpu side. And it will
 *	return the struct RPCRES_LONG which contains a pointer to the created
 *  filter to system software. The System software will specify the filter
 *  type which it requires such as video encoder, video decoder, video in, etc.
 *
 *	\return RPCRES_LONG
 *
 *  \param VIDEO_RPC_INSTANCE
 *
 */
  RPCRES_LONG VIDEO_RPC_ToAgent_Create(VIDEO_RPC_INSTANCE x) = VIDEO_RPC_COMMON_FUNC_BASE + 10 ;


/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_Connect (RPC_CONNECTION)
 *
 *  \brief To connect two filters.
 *  This function connects two filters, for example a video decoder filter
 *  and a video out filter to accomplish a playback or recoding flow.
 *
 *  \return
 *
 *  \param
 */
  HRESULT     VIDEO_RPC_ToAgent_Connect(RPC_CONNECTION x) = VIDEO_RPC_COMMON_FUNC_BASE + 20 ;




/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_InitRingBuffer (RPC_RINGBUFFER)
 *
 *  \brief To Init Ring Buffer.
 *  This function initialize the ring buffer setting.
 *  System software invoke this function to inform video filter the setting of
 *  an available ring buffer.
 *
 *  \return
 *
 *  \param
 */
  HRESULT     VIDEO_RPC_ToAgent_InitRingBuffer(RPC_RINGBUFFER x) = VIDEO_RPC_COMMON_FUNC_BASE + 30 ;





/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_Run (long)
 *
 *  \brief To Command video filter run.
 *  This function commands video filter run. For a video decoder filter,
 *  run means to decode the bitstream and produce pictures.
 *
 *  \return
 *
 *  \param
 *
 */
  HRESULT     VIDEO_RPC_ToAgent_Run(long x) = VIDEO_RPC_COMMON_FUNC_BASE + 40 ;




/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_Pause (long)
 *
 *  \brief To pause a video filter.
 *  This function commands video filter enter pause status. For a video
 *  decoder filter, there is no difference between run status and pause status.
 *
 *  \return
 *
 *  \param  The pointer to video filter.
 */
  HRESULT     VIDEO_RPC_ToAgent_Pause(long x) = VIDEO_RPC_COMMON_FUNC_BASE + 50 ;





/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_Stop (long)
 *
 *  \brief To stop a video filter
 *  This function stops the operation of a video filter.
 *
 *  \return
 *
 *  \param
 */
  HRESULT     VIDEO_RPC_ToAgent_Stop(long x) = VIDEO_RPC_COMMON_FUNC_BASE + 60 ;





/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_Destroy (long)
 *
 *  \brief To destroy a video filter.
 *  This function force to kill all tasks of the video filter.
 *  It also should return all requested memory in all components in the filter.
 *
 *  \return
 *
 *  \param
 */
  HRESULT VIDEO_RPC_ToAgent_Destroy(long x) = VIDEO_RPC_COMMON_FUNC_BASE + 70 ;





/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_Flush (long)
 *
 *  \brief To flush the stalling data in queues of components in a video filter.
 *  This function inform each component to flush stalling data and eventually
 *  clean up all the queuing data in pins.
 *
 *  \return
 *
 *  \param
 */
  HRESULT VIDEO_RPC_ToAgent_Flush(long x) = VIDEO_RPC_COMMON_FUNC_BASE + 80 ;





/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_SetRefClock (VIDEO_RPC_SET_REFCLOCK)
 *
 *  \brief Inform agent where to find reference clock.
 */
  HRESULT VIDEO_RPC_ToAgent_SetRefClock(VIDEO_RPC_SET_REFCLOCK x) = VIDEO_RPC_COMMON_FUNC_BASE + 90 ;




/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_VideoCreate (VIDEO_INIT_DATA)
 *
 *  \brief Inform agent to initialize video CPU
 */
  HRESULT VIDEO_RPC_ToAgent_VideoCreate(VIDEO_INIT_DATA x) = VIDEO_RPC_COMMON_FUNC_BASE + 100 ;




/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_VideoConfigure (VIDEO_CONFIG_DATA)
 *
 *  \brief To globally configure the video firmware
 */
  HRESULT VIDEO_RPC_ToAgent_VideoConfig(VIDEO_CONFIG_DATA x) = VIDEO_RPC_COMMON_FUNC_BASE + 105 ;




/**
 *  \fn  VIDEO_CONFIG_DATA  VIDEO_RPC_ToAgent_GetVideoConfigure (long configType)
 *
 *  \brief To get the configure of video firmware
 */
  VIDEO_CONFIG_DATA  VIDEO_RPC_ToAgent_GetVideoConfigure(long configType) = VIDEO_RPC_COMMON_FUNC_BASE + 106 ;




/**
 *  \fn  VIDEO_RPC_VIDEO_FREE_MEMORY   VIDEO_RPC_ToAgent_VideoMemoryConfig (long configMode)
 *
 *  \brief  To let System software borrow/return contiguous memory chunks from/to video firmware,
 *          or to define any other types of video firmware memory configuration System may need
 *          in the future.
 *
 *  \return  a VIDEO_RPC_VIDEO_FREE_MEMORY struct
 *
 *  \param   configMode:
 *
 *             0: Power-on default mode:
 *                   Video firmware can access all memory allocated under the default power-on configuration.
 *                   This mode can also be used when System wants to return all borrowed memory back to video.
 *
 *             1: Memory reduction mode 1:
 *                   Video firmware will only keep the minimum amount of memory necessary for decoding all
 *                   formats except H.264, and return all unused memory to System in the form of one or
 *                   more memory chunks.
 *
 *             Other values: Memory configuration modes reserved for future use
 *
 */
  VIDEO_RPC_VIDEO_FREE_MEMORY   VIDEO_RPC_ToAgent_VideoMemoryConfig(long configMode) = VIDEO_RPC_COMMON_FUNC_BASE + 108 ;





/**
 *  \fn  HRESULT VIDEO_RPC_ToAgent_VideoChunkConfig (VIDEO_RPC_CONFIG_CHUNK)
 *
 *  \brief  To let System software config Video Memory Chunk
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 *  \param   configMode:
 *             0: video will allocate Video buffer from system
 *             1: video will free video buffer to system
 *
 *  \param   numofChunk:
 *             number of chunks to allocate/free video buffer,
 *             each Chunk is 16 MBs, Max of numofChunk is 3
 *
 */
  HRESULT VIDEO_RPC_ToAgent_VideoChunkConfig(VIDEO_RPC_CONFIG_CHUNK *) = VIDEO_RPC_COMMON_FUNC_BASE + 109 ;


/**
 *  \fn  HRESULT  VIDEO_RPC_ToAgent_VideoDestroy (VIDEO_INIT_DATA)
 *
 *  \brief Inform agent where to destroy video application
 */
  HRESULT VIDEO_RPC_ToAgent_VideoDestroy(VIDEO_INIT_DATA x) = VIDEO_RPC_COMMON_FUNC_BASE + 110 ;




/**
 * \fn  RPCRES_LONG  VIDEO_RPC_ToAgent_RequestBuffer (VIDEO_RPC_REQUEST_BUFFER)
 *
 * \brief Request a video buffer from the buffer pools managed by the Vide Buffer Manager (VBM)
 *
 * \return a RPCRES_LONG struct in which:
 *    If the VBM successfully allocates the requested buffer, the 'result' field
 *    will be set to 'S_OK' and the 'data' field will be set to the non-negative ID
 *    that identifies the buffer by any video components that use it subsequently.
 *
 *    If the VBM fails to allocate the requested buffer, the 'result' field
 *    will be set to 'E_FAIL' and the 'data' field will be set to a negative
 *    value indicating the cause of the failure as defined in the file 'VBM_def.h'.
 *
 * \param  width:
 *    Width of the requested buffer in pixel unit.
 *
 * \param  height:
 *    Height of the requested buffer in pixel unit.
 */
  RPCRES_LONG VIDEO_RPC_ToAgent_RequestBuffer(VIDEO_RPC_REQUEST_BUFFER x) = VIDEO_RPC_COMMON_FUNC_BASE + 120 ;




/**
 * \fn  HRESULT  VIDEO_RPC_ToAgent_ReleaseBuffer (long)
 *
 * \brief Release a video buffer to the buffer pools managed by the Vide Buffer Manager (VBM)
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param  bufferID:
 *    ID of the buffer to be released.
 */
  HRESULT VIDEO_RPC_ToAgent_ReleaseBuffer(long bufferID) = VIDEO_RPC_COMMON_FUNC_BASE + 130 ;



/**
 * \fn  HRESULT  VIDEO_RPC_ToAgent_ConfigLowDelay (long)
 *
 * \brief To config low-delay mode for Decoder and Video-Out,
 *        and we will enable DPB bypass if any low-delay mode is turned-on
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param  mode:
 *    mode to turn-on/off low_delay for Decoder and Video-Out
 *
 */
  HRESULT VIDEO_RPC_ToAgent_ConfigLowDelay(VIDEO_RPC_LOW_DELAY x) = VIDEO_RPC_COMMON_FUNC_BASE + 133 ;

/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_CmprsCtrl (VIDEO_RPC_DEC_CMPRS_CTRL)
 * \brief This function is used to control compression mode
 *
 * \return
 * \param  A VIDEO_RPC_DEC_CMPRS_CTRL struct.
 */
  HRESULT  VIDEO_RPC_DEC_ToAgent_CmprsCtrl (VIDEO_RPC_DEC_CMPRS_CTRL x) = VIDEO_RPC_VDEC_FUNC_BASE + 135 ;

/**
 * \fn  HRESULT  VIDEO_RPC_ToAgent_SetDebugMemory (long)
 *
 * \brief Set the address of the debug memory holding the structure 'VIDEO_RPC_DEBUG_MEMORY'
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param  debugMemAddr:
 *    The physical DRAM address of the debug memory.
 */
  HRESULT VIDEO_RPC_ToAgent_SetDebugMemory (long debugMemAddr) = VIDEO_RPC_COMMON_FUNC_BASE + 140 ;





/**
 ************************************************************************
 * \fn  HRESULT  VIDEO_RPC_ToAgent_VideoHalt (void)
 * \brief
 *    This function is used to suspend video CPU
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param reserved for future use
 *
 ************************************************************************
 */
  HRESULT VIDEO_RPC_ToAgent_VideoHalt (long reserved) = VIDEO_RPC_COMMON_FUNC_BASE + 150;

/**
 ************************************************************************
 * \fn  HRESULT  VIDEO_RPC_ToAgent_YUYV2RGB (VIDEO_RPC_YUYV_TO_RGB)
 * \brief
 *    This function is used to convert YUYV(seq) to RGB(seq)
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param reserved for future use
 *
 ************************************************************************
 */
  HRESULT VIDEO_RPC_ToAgent_YUYV2RGB (VIDEO_RPC_YUYV_TO_RGB x) = VIDEO_RPC_COMMON_FUNC_BASE + 160;

/**
 * \fn  HRESULT  VIDEO_RPC_ToAgent_SetScale (VIDEO_RPC_SET_SCALE)
 *
 *\brief This function is used to set target frame size and enable scaling flow for dynamic resolution stream.
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param  A VIDEO_RPC_SET_SCALE struct.
 *
 */
  HRESULT VIDEO_RPC_ToAgent_SetScale (VIDEO_RPC_SET_SCALE x) = VIDEO_RPC_COMMON_FUNC_BASE + 170 ;


/** oliver+
 ************************************************************************
 * \fn  HRESULT  VIDEO_RPC_ScalerDrv (void)
 * \brief
 *    This function is used to replace IOCtl in scalerDrv.c
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param RPC Struct for scaler driver
 *
 ************************************************************************
 */
  HRESULT VIDEO_RPC_ToAgent_ScalerDrv (SCALER_RPC_STRUCT x) = VIDEO_RPC_COMMON_FUNC_BASE + 500;


/** oliver+
 ************************************************************************
 * \fn  HRESULT  VIDEO_RPC_ScalerDrv (void)
 * \brief
 *    This function is used to replace IOCtl in scalerDrv.c
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param RPC Struct for scaler driver
 *
 ************************************************************************
 */
  HRESULT VIDEO_RPC_ToAgent_SetShareMemAddr (SCALER_RPC_SHARE_MEM x) = VIDEO_RPC_COMMON_FUNC_BASE + 510;


/**
 ************************************************************************
 * \fn  HRESULT  VIDEO_RPC_SetResourceInfo (void)
 * \brief
 *    This function is used to set resource-info
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param VIDEO_RPC_RESOURCE_INFO
 *
 ************************************************************************
 */
  HRESULT VIDEO_RPC_ToAgent_SetResourceInfo (VIDEO_RPC_RESOURCE_INFO x) = VIDEO_RPC_COMMON_FUNC_BASE + 600;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_CompCtrl (VIDEO_RPC_COMP_CTRL)
 * \brief This function is used to control compress option
 *
 * \return
 * \param  A VIDEO_RPC_COMP_CTRL struct.
 */
  HRESULT  VIDEO_RPC_ToAgent_CompCtrl (VIDEO_RPC_COMP_CTRL x) = VIDEO_RPC_COMMON_FUNC_BASE + 700 ;


/** @} */

/**
 *  \defgroup video_decoder The Video Decoder RPC call.
 *
 *  @{
 */





/**
 * \fn HRESULT  VIDEO_RPC_DEC_ToAgent_SetSpeed (VIDEO_RPC_DEC_SET_SPEED)
 *
 * \brief This function is used to specify the decoding direction and the picture skipping rate
 *       (a.k.a., the decode sampling rate).
 *
 * \return
 *
 * \param  displaySpeed:
 *    As the decoder is not the presentation unit that controls the ultimate video playback
 *    speed (VideoOut is), this parameter does nothing but to specify the direction of
 *    decoding, i.e., if it is a positive number, the decoder performs forward decoding;
 *    if it is a negative number, the decoder performs backward decoding. The absolute value
 *    of this parameter is irrelevant.
 *
 * \param  decodeSkip:
 *    A 24.8 fixed-point value to specify the rate in unit of picture count at which
 *    the decoder decodes and sends the decoded picture to its downstream components.
 *    E.g.: when decodeSkip = 0x100, the decoder decodes/sends every picture in the bitstream
 *          when decodeSkip = 0x200, the decoder decodes/sends every other (skip 1) picture in the bitstream.
 *          when decodeSkip = 0x180, the decoder decodes/sends two pictures for every 3 pictures in the bitstream.
 *
 *    The sign of 'decodeSkip' must be the same as that of 'displaySpeed'.
 *    Any value between -0x100 and 0x100 for 'decodeSkip' (i.e., sampling rate less than 1)
 *    has no significance and will be rounded to 0x100 or -0x100 depending on its sign.
*/
  HRESULT VIDEO_RPC_DEC_ToAgent_SetSpeed(VIDEO_RPC_DEC_SET_SPEED x) = VIDEO_RPC_VDEC_FUNC_BASE + 10 ;





/**
 * \fn HRESULT  VIDEO_RPC_DEC_ToAgent_SetErrorConcealmentLevel (VIDEO_RPC_DEC_SET_ERR_CONCEALMENT_LEVEL)
 *
 * \brief  This function is used to specify the Level of Error Concealment, a threshold that contorls
 *         the Video Decoder whether to send an erroneous picture to its downstream Filter or not.
 *
 *
 * \return This function always returns S_OK.
 *
 *
 * \param  errConcealmentLevel:
 *
 *    This parameter is set prior to decoding as a quality measurement that defines the tolerance for
 *    visual artifacts in exchange for a smoother presentation. When too many errors are detected in one
 *    picture that exceed the tolerance level, the picture will be dropped. A higher errConcealmentLevel
 *    leads to more dropped pictures. It is an unsigned integer that:
 *
 *    (1) when set to 0, means that the Video Decoder will NOT do any concealment on erroneous pictures.
 *        All decoded pictures will be sent to the downstream Filter regardless of decoding errors.
 *        This will result in the best temporal smoothness and least lost video information.
 *        But it will also have some spatially corrupted pictures shown on the final video presentation.
 *        This setting is desireable when constant screen update is preferred over jittery but clean video.
 *
 *    (2) when set to a value between 1-256, specifies a threshold that the Video Decoder will use
 *        to decide if it shall output an erroneous picture or not. It represents a percentage
 *        of the error-free area in a decoded picture, with 256 being 100% and 1 being (100/256)% or 0.391%.
 *        When the percentage of the error-free area is below the threshold, the entire picture will
 *        be dropped. Otherwise, the Video Decoder will do a macroblock-based error recovery through which
 *        the macroblocks in the erroneous area will be reconstructed from the reference picture(s) either
 *        by direct copy or by motion-compensated reconstruction depending on the availability of
 *        macroblock-level information and performance constraints. The picture after error recovery will
 *        then be sent to the downstream Filter.
 *
*/
  HRESULT VIDEO_RPC_DEC_ToAgent_SetErrorConcealmentLevel(VIDEO_RPC_DEC_SET_ERR_CONCEALMENT_LEVEL x) = VIDEO_RPC_VDEC_FUNC_BASE + 15 ;








/**
 * \fn	HRESULT  VIDEO_RPC_DEC_ToAgent_Init (VIDEO_RPC_DEC_INIT)
 * \brief This function initiates the decoder.
 *
 * \return
 * \param  A VIDEO_RPC_DEC_INIT struct.
 */
  HRESULT VIDEO_RPC_DEC_ToAgent_Init (VIDEO_RPC_DEC_INIT x) = VIDEO_RPC_VDEC_FUNC_BASE + 20 ;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_SetDeblock (VIDEO_RPC_DEC_SET_DEBLOCK)
 * \brief This function is used to enable/disable the deblocking processing on the decoded pictures.
 *
 * \return
 * \param  A VIDEO_RPC_DEC_SET_DEBLOCK struct.
 */
  HRESULT VIDEO_RPC_DEC_ToAgent_SetDeblock (VIDEO_RPC_DEC_SET_DEBLOCK x) = VIDEO_RPC_VDEC_FUNC_BASE + 30 ;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_GetVideoSequenceInfo (long)
 * \brief This function is used to return detailed video sequence information to system.
 *
 * \return
 * \param  A VIDEO_RPC_DEC_SEQ_INFO struct.
 */
  VIDEO_RPC_DEC_SEQ_INFO  VIDEO_RPC_DEC_ToAgent_GetVideoSequenceInfo (long instanceID) = VIDEO_RPC_VDEC_FUNC_BASE + 35 ;



/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_BitstreamValidation (VIDEO_RPC_DEC_BITSTREAM_BUFFER)
 * \brief This function is used to validate the video elementary stream
 *        (i.e., to find out if the given bitstream is a valid and decodable MPEG bitstream).
 *
 * \return
 * \param  A VIDEO_RPC_DEC_BV_RESULT struct.
 */
  VIDEO_RPC_DEC_BV_RESULT  VIDEO_RPC_DEC_ToAgent_BitstreamValidation (VIDEO_RPC_DEC_BITSTREAM_BUFFER x) = VIDEO_RPC_VDEC_FUNC_BASE + 40 ;



/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_Capability (long mask)
 * \brief Turn on decoder by a mask
 * \return
 * \param  see "enum VIDEO_VF_TYPE" to know which bit is for which decoder
 *         ex. use ~(1<<VF_TYPE_VIDEO_REAL_DECODER) to disable RealVideo decoder and enable all others
 */
  HRESULT  VIDEO_RPC_DEC_ToAgent_Capability (VIDEO_RPC_DEC_CAPABILITY mask) = VIDEO_RPC_VDEC_FUNC_BASE + 45 ;



/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_DecodeCCBypass (VIDEO_RPC_DEC_CC_BYPASS_MODE)
 * \brief This function is used to set the CC bypass mode
 *
 * \return
 * \param  A VIDEO_RPC_DEC_CC_BYPASS_MODE struct.
 */
  HRESULT VIDEO_RPC_DEC_ToAgent_SetDecoderCCBypass (VIDEO_RPC_DEC_CC_BYPASS_MODE x) = VIDEO_RPC_VDEC_FUNC_BASE + 50 ;



/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_SetDNR (VIDEO_RPC_DEC_SET_DNR)
 * \brief This function is used to set the DNR (Digital Noise Reduction) mode
 *
 * \return
 *
 * \param  dnr_mode:
 *
 *    The DNR mode can be set to one of the following:
 *
 *    VIDEO_DNR_OFF:  to turn off the DNR.
 *
 *    VIDEO_DNR_AUTO: to let vidoe firmware perform DNR automatically based on.
 *                    on the video source properties and system resources
 *
 *    VIDEO_DNR_DEMO: to demonstrate the playback video quality improvement by the DNR:
 *                    identical video contents will be displayed side by side on the
 *                    two halves of the screen, with the left half showing video after
 *                    the DNR processing and the right half showing the original video.
 *
 */
  HRESULT VIDEO_RPC_DEC_ToAgent_SetDNR (VIDEO_RPC_DEC_SET_DNR x) = VIDEO_RPC_VDEC_FUNC_BASE + 60 ;




/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_SetRefSyncLimit (VIDEO_RPC_DEC_SET_REF_SYNC_LIMIT)
 * \brief This function is used to set "RefSyncLimit"
 *
 * \return This function always returns S_OK
 *
 * \param  refSyncLimit:
 *    To cap the maximal number of discarded P/B frames before the first I frame is decoded/displayed.
 * If after RefSyncLimit frames there has still not been an I frame, all frames that follow will be decoded/displayed normally.
 *
 */
  HRESULT VIDEO_RPC_DEC_ToAgent_SetRefSyncLimit (VIDEO_RPC_DEC_SET_REF_SYNC_LIMIT x) = VIDEO_RPC_VDEC_FUNC_BASE + 65 ;




/**
 * \fn  HRESULT  VIDEO_RPC_THUMBNAIL_ToAgent_SetVscalerOutputFormat (VIDEO_RPC_THUMBNAIL_SET_VSCALER_OUTFORMAT)
 * \brief This function is used to set output format for the vscaler in thumbnail filter.
 *
 * \return
 * \param  A VIDEO_RPC_THUMBNAIL_SET_VSCALER_OUTFORMAT struct.
 */
  HRESULT VIDEO_RPC_THUMBNAIL_ToAgent_SetVscalerOutputFormat (VIDEO_RPC_THUMBNAIL_SET_VSCALER_OUTFORMAT x) = VIDEO_RPC_VDEC_FUNC_BASE + 70 ;



/**
 * \fn  HRESULT  VIDEO_RPC_THUMBNAIL_ToAgent_SetThreshold (VIDEO_RPC_THUMBNAIL_SET_THRESHOLD)
 * \brief This function is used to set the threshold for the thumbnail filter.
 *
 * \return
 * \param  A VIDEO_RPC_THUMBNAIL_SET_THRESHOLD struct.
 */
  HRESULT VIDEO_RPC_THUMBNAIL_ToAgent_SetThreshold (VIDEO_RPC_THUMBNAIL_SET_THRESHOLD x) = VIDEO_RPC_VDEC_FUNC_BASE + 80 ;

/**
 * \fn  HRESULT  VIDEO_RPC_FLASH_ToAgent_SetOutput (VIDEO_RPC_FLASH_SET_OUTPUT)
 * \brief This function is used to set the output address for flash decode
 *
 * \return
 * \param  A VIDEO_RPC_FLASH_SET_OUTPUT struct.
 */
  HRESULT VIDEO_RPC_FLASH_ToAgent_SetOutput (VIDEO_RPC_FLASH_SET_OUTPUT x) = VIDEO_RPC_VDEC_FUNC_BASE + 85 ;



/**
 * \fn  HRESULT  VIDEO_RPC_THUMBNAIL_ToAgent_SetStartPictureNumber (VIDEO_RPC_THUMBNAIL_SET_STARTPIC)
 * \brief This function is used to set which picture to start for the thumbnail filter.
 *
 * \return
 * \param  A VIDEO_RPC_THUMBNAIL_SET_STARTPIC struct.
 */
  HRESULT VIDEO_RPC_THUMBNAIL_ToAgent_SetStartPictureNumber (VIDEO_RPC_THUMBNAIL_SET_STARTPIC x) = VIDEO_RPC_VDEC_FUNC_BASE + 90 ;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_GetMPEGSequenceHdr (long)
 * \brief This function is used to return MPEG sequence header to system.
 *
 * \return
 * \param  A VIDEO_RPC_DEC_MPEG_SEQ_HDR struct.
 */
  VIDEO_RPC_DEC_MPEG_SEQ_HDR  VIDEO_RPC_DEC_ToAgent_GetMPEGSequenceHdr (long instanceID) = VIDEO_RPC_VDEC_FUNC_BASE + 95 ;

/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_SetMPEGSequenceHdr (long)
 * \brief This function is used to set MPEG sequence header to video.
 *
 * \return
 * \param  A VIDEO_RPC_DEC_MPEG_SEQ_HDR struct.
 */
  HRESULT  VIDEO_RPC_DEC_ToAgent_SetMPEGSequenceHdr (VIDEO_RPC_DEC_MPEG_SEQ_HDR x) = VIDEO_RPC_VDEC_FUNC_BASE + 100 ;

/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_GetMPEGSequenceHdr_New (long)
 * \brief This function is used to get and return MPEG sequence header to system.
 *
 * \return
 * \param  A VIDEO_RPC_DEC_MPEG_SEQ_HDR struct.
 */
  HRESULT  VIDEO_RPC_DEC_ToAgent_GetMPEGSequenceHdr_New (VIDEO_RPC_DEC_MPEG_SEQ_HDR x) = VIDEO_RPC_VDEC_FUNC_BASE + 105 ;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_ParseFrameBoundary (VIDEO_RPC_DEC_PARSE_FRAME_BOUNDARY)
 * \brief This function is used to parse I/P frame from an elementary stream and return frame type and offset to system .
 *
 * \return Packet offset from Inband command.
 * \param  A VIDEO_RPC_DEC_PARSE_FRAME_BOUNDARY struct.
 */
  HRESULT  VIDEO_RPC_DEC_ToAgent_ParseFrameBoundary (VIDEO_RPC_DEC_PARSE_FRAME_BOUNDARY x) = VIDEO_RPC_VDEC_FUNC_BASE + 110 ;


/**
 * \fn  VIDEO_RPC_DEC_DRIP_RESULT  VIDEO_RPC_DEC_ToAgent_SetDripDec (VIDEO_RPC_DEC_DRIP_INFO)
 * \brief This function is used to start or save the drip decoding.
 *
 * \return  A VIDEO_RPC_DEC_DRIP_RESULT struct.
 * \param  A VIDEO_RPC_DEC_DRIP_INFO struct.
 */
  VIDEO_RPC_DEC_DRIP_RESULT  VIDEO_RPC_DEC_ToAgent_SetDripDec (VIDEO_RPC_DEC_DRIP_INFO x) = VIDEO_RPC_VDEC_FUNC_BASE + 115 ;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_ParseResolution (VIDEO_RPC_DEC_BITSTREAM_BUFFER)
 * \brief This function is used to parse frame resolution from the video elementary stream
 *
 * \return A VIDEO_RPC_DEC_PV_RESULT struct
 * \param  A VIDEO_RPC_DEC_BITSTREAM_BUFFER struct.
 */
  VIDEO_RPC_DEC_PV_RESULT  VIDEO_RPC_DEC_ToAgent_ParseResolution (VIDEO_RPC_DEC_BITSTREAM_BUFFER x) = VIDEO_RPC_VDEC_FUNC_BASE + 120 ;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_SetDecodeMode (VIDEO_RPC_DEC_SET_DECODEMODE)
 * \brief This function is used to set decode mode
 *
 * \return
 * \param  A VIDEO_RPC_DEC_SET_DECODEMODE struct.
 */
  HRESULT  VIDEO_RPC_DEC_ToAgent_SetDecodeMode (VIDEO_RPC_DEC_SET_DECODEMODE x) = VIDEO_RPC_VDEC_FUNC_BASE + 125 ;


/**
 * \fn  HRESULT  VIDEO_RPC_DEC_ToAgent_MeasureDecodeTime (VIDEO_RPC_DEC_MEASURE_DECODE_TIME)
 * \brief This function is used to measure decoding time per frame
 *
 * \return
 * \param  A VIDEO_RPC_DEC_MEASURE_DECODE_TIME struct.
 */
  HRESULT  VIDEO_RPC_DEC_ToAgent_MeasureDecodeTime (VIDEO_RPC_DEC_MEASURE_DECODE_TIME x) = VIDEO_RPC_VDEC_FUNC_BASE + 130 ;


/** @} */


/**
 *  \defgroup Video Capturer APIs
 *  APIs for Video Capturer functionalities .
 *
 */
/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_CAP_ToAgent_StartCapture(VIDEO_RPC_CAP_START_CAPTURE x);

  Function:
    Start Capturing.
    The capturing starts after the command issued.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_CAP_ToAgent_StartCapture(VIDEO_RPC_CAP_START_CAPTURE x) = VIDEO_RPC_VCAP_FUNC_BASE + 10 ;


/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_CAP_ToAgent_StopCapture(VIDEO_RPC_CAP_STOP_CAPTURE x);

  Function:
    Stop Capturing.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_CAP_ToAgent_StopCapture(VIDEO_RPC_CAP_STOP_CAPTURE x) = VIDEO_RPC_VCAP_FUNC_BASE + 20 ;


/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_CAP_ToAgent_CaptureOneFrame(VIDEO_RPC_CAP_STOP_CAPTURE x);

  Function:
    Stop Capturing.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_CAP_ToAgent_CaptureOneFrame(VIDEO_RPC_CAP_CAPTURE_ONE_FRAME x) = VIDEO_RPC_VCAP_FUNC_BASE + 30 ;



/**
 *  \defgroup Video Capturer APIs
 *  APIs for Video Capturer functionalities .
 *
 */
/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_CAP_ToAgent_SetCaptureMode(VIDEO_RPC_CAP_START_CAPTURE x);

  Function:
    Start Capturing.
    The capturing starts after the command issued.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_CAP_ToAgent_SetCaptureMode(VIDEO_RPC_CAP_START_CAPTURE x) = VIDEO_RPC_VCAP_FUNC_BASE + 40 ;

/**
 *  \defgroup Video Capturer APIs
 *  APIs for Video Capturer functionalities .
 *
 */
/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_CAP_ToAgent_SetFrameRate(VIDEO_RPC_CAP_SET_FRAME_RATE x);

  Function:
    Set Capture Frame Rate.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_CAP_ToAgent_SetFrameRate(VIDEO_RPC_CAP_SET_FRAME_RATE x) = VIDEO_RPC_VCAP_FUNC_BASE + 50 ;



/** @} */

/**
 *  \defgroup Video Encoder APIs
 *  APIs for Video Encoder functionalities .
 *
 */

/*!
 ************************************************************************
 * \brief
 *    This function is used to initialize encoder
 *
 * \return
 * \param steamType : Darwin only H.264
 * \param input source :
 *    raw data in or generic data in
 * \param yuvFormat
 *    only used in raw data in
 * \param mixerWinID
 ************************************************************************
 */
HRESULT VIDEO_RPC_ENC_ToAgent_Init (VIDEO_RPC_ENC_INIT x)  = VIDEO_RPC_VENC_FUNC_BASE + 10 ;

/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetVideoSource(VIDEO_RPC_ENC_VIDEOSOURCE x);

  Function:
    This function sets video source to either DIN or VIN.
    ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetVideoSource(VIDEO_RPC_ENC_VIDEOSOURCE x) = VIDEO_RPC_VENC_FUNC_BASE + 15 ;

/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetSourceFile(VIDEO_RPC_ENC_SOURCEFILE x);

  Function:
    For simulation purposes only
    ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetSourceFile(VIDEO_RPC_ENC_SOURCEFILE x) = VIDEO_RPC_VENC_FUNC_BASE + 20 ;  /* Simulation Purpose Only */




/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetResolution(VIDEO_RPC_ENC_SET_RESOLUTION x);

  Function:
      Set Picture Resolution.
      The horizontal and vertical resolutions are assigned. Currently the following combination
    is supported: horizontally 352, 360, 704 and 720, with vertically 240, 288, 480, and 576.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetResolution(VIDEO_RPC_ENC_SET_RESOLUTION x) = VIDEO_RPC_VENC_FUNC_BASE + 30 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to set output resolution and input resolution (only used in raw data in)
 *
 * \return
 *
 * \param input  width height :
 * \param output width height :
 ************************************************************************
 */
HRESULT VIDEO_RPC_ENC_ToAgent_SetNewResolution (VIDEO_RPC_ENC_SET_NEW_RESOLUTION x)  = VIDEO_RPC_VENC_FUNC_BASE + 35 ;



/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetBitRate(VIDEO_RPC_ENC_SET_BITRATE x);

  Function:
      Set the rate-control related parameters.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetBitRate(VIDEO_RPC_ENC_SET_BITRATE x) = VIDEO_RPC_VENC_FUNC_BASE + 40 ;




/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetGOPStructure(VIDEO_RPC_ENC_SET_GOPSTRUCTURE x);

  Function:
    It configures the GOP structure that the encoder generates.
    The constant M and N controls the GOP structure, as described below.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetGOPStructure(VIDEO_RPC_ENC_SET_GOPSTRUCTURE x) = VIDEO_RPC_VENC_FUNC_BASE + 50 ;


/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetNewGOPOnSceneChange(VIDEO_RPC_ENC_SET_NEWGOPONSC x);

  Function:
    Set On/Off for Restart a New GOP on Scene Changes
    This turns on or off the start of new GOP when the scene change is detected.
  The default value is off.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetNewGOPOnSceneChange(VIDEO_RPC_ENC_SET_NEWGOPONSC x) = VIDEO_RPC_VENC_FUNC_BASE + 70 ;




/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetInverseTelecineDetection(VIDEO_RPC_ENC_SET_INV32DETECT x);

  Function:
    Set On/Off for Inverse Telecine Detection
    Set the encoder to apply inverse telecine detection. If it detects, the encoder will apply
  frame mode vertical noise reduction over the luma frame.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetInverseTelecineDetection(VIDEO_RPC_ENC_SET_INV32DETECT x) = VIDEO_RPC_VENC_FUNC_BASE + 80 ;





/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetTF(VIDEO_RPC_ENC_SET_TF x);

  Function:
    Set Up Temporal Filter
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetTF(VIDEO_RPC_ENC_SET_TF x) = VIDEO_RPC_VENC_FUNC_BASE + 90 ;




/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetNR(VIDEO_RPC_ENC_SET_NR x);

  Function:
    Set Up Spacitial Noise Reduction Filter
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetNR(VIDEO_RPC_ENC_SET_NR x) = VIDEO_RPC_VENC_FUNC_BASE + 100 ;





/*  ------------------------------------------------------------------------------------
  Signature:
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetEncodeFormat(VIDEO_RPC_ENC_SET_ENCFORMAT x) = 22;

  Function:
    Set Encoder Format to MPEG1 or MPEG2
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetEncodeFormat(VIDEO_RPC_ENC_SET_ENCFORMAT x) = VIDEO_RPC_VENC_FUNC_BASE + 110 ;






/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_ConfigureCCData(VIDEO_RPC_ENC_CONFIG_CCDATA x);

  Function:
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_ConfigureCCData(VIDEO_RPC_ENC_CONFIG_CCDATA x) = VIDEO_RPC_VENC_FUNC_BASE + 120 ;






/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_SetClosedGOPFrequency(VIDEO_RPC_ENC_SET_CLOSEDGOPFREQ x);

  Function:
    Set the Frequency for Closed GOP
    This command sets the number of frames that the encoder will start a closed GOP for.
  Generally, the encoder will start a closed GOP in three cases: the first GOP of the
  sequence, the first GOP after resume, and the detected scene change if the option turns
  on. If this command is called, one closed GOP will be started for every indicated number
  of GOPs.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_SetClosedGOPFrequency(VIDEO_RPC_ENC_SET_CLOSEDGOPFREQ x) = VIDEO_RPC_VENC_FUNC_BASE + 130 ;





/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_StartRecord(VIDEO_RPC_ENC_START_ENC x);

  Function:
    Start Recording
    The recording starts after the command issued.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_StartRecord(VIDEO_RPC_ENC_START_ENC x) = VIDEO_RPC_VENC_FUNC_BASE + 140 ;




/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_PauseRecord(VIDEO_RPC_ENC_PAUSE_ENC x);

  Function:
    Pause Recording.
    It pauses the recording. Two different types are supported: pause immediately
  and pause at GOP. In the former
    For now, it always pause at VOBU boundary.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_PauseRecord(VIDEO_RPC_ENC_PAUSE_ENC x) = VIDEO_RPC_VENC_FUNC_BASE + 150 ;




/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_StopRecord(VIDEO_RPC_ENC_STOP_ENC x);

  Function:
    Stop Recording.
    The encoding stops at the  end of current VOBU after the command issued.
    Note: if encoder sees an EOS, it should repeat this frame until end of VOBU.
      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_StopRecord(VIDEO_RPC_ENC_STOP_ENC x) = VIDEO_RPC_VENC_FUNC_BASE + 160 ;





/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT     VIDEO_RPC_ENC_ToAgent_ConfigVOBU(VIDEO_RPC_ENC_CONFIG_VOBU x);

  Function:
    Sets the minimum GOP number per VOBU. VOBU will be at least this number of GOPs and
    0.4 to 1.2 seconds.

      ------------------------------------------------------------------------------------ */
  HRESULT     VIDEO_RPC_ENC_ToAgent_ConfigVOBU(VIDEO_RPC_ENC_CONFIG_VOBU x) = VIDEO_RPC_VENC_FUNC_BASE + 170 ;


/*  ------------------------------------------------------------------------------------
  Signature:
    RPCRES_LONG  VIDEO_RPC_ENC_ToAgent_MPEGIFrameEncode(VIDEO_RPC_ENC_MPEG_I_ENC x);

  Function:
    Mpeg I frame encoder
  --------------------------------------------------------------------------------------*/
  RPCRES_LONG  VIDEO_RPC_ENC_ToAgent_MPEGIFrameEncode(VIDEO_RPC_ENC_MPEG_I_ENC x) = VIDEO_RPC_VENC_FUNC_BASE + 180;

/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT VIDEO_RPC_ENC_ToAgent_SetVbidWssFreq
  Function:
    Set the VBID_WSS info frequency.
  --------------------------------------------------------------------------------------*/

  HRESULT VIDEO_RPC_ENC_ToAgent_SetVbidWssFreq(VIDEO_RPC_ENC_SET_VBID_WSS_FREQ x) = VIDEO_RPC_VENC_FUNC_BASE + 190;

 /*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT VIDEO_RPC_ENC_ToAgent_IsRunnable
  Function:
    Query if Encoder is runnable now. (for avoiding recording at HD buffer case)
  Return:
    S_OK means is runnable now, otherwise not.
  --------------------------------------------------------------------------------------*/
  HRESULT VIDEO_RPC_ENC_ToAgent_IsRunnable(long instanceID) = VIDEO_RPC_VENC_FUNC_BASE + 200;

 /*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT VIDEO_RPC_ENC_ToAgent_SetVBV
  Function:
    Set VBV_Buf_Size and VBV_Buf_Fullness
  --------------------------------------------------------------------------------------*/
  HRESULT VIDEO_RPC_ENC_ToAgent_SetVBV(VIDEO_RPC_ENC_SET_VBV x) = VIDEO_RPC_VENC_FUNC_BASE + 210;

/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT VIDEO_RPC_ENC_ToAgent_SetNonRealTime
  Function:
    Set Video Encoder NonRealTime/RealTime
  --------------------------------------------------------------------------------------*/
  HRESULT VIDEO_RPC_ENC_ToAgent_SetNonRealTime(VIDEO_RPC_ENC_SET_NONREALTIME x) = VIDEO_RPC_VENC_FUNC_BASE + 220;

/*  ------------------------------------------------------------------------------------
  Signature:
    HRESULT VIDEO_RPC_ENC_ToAgent_SendTVDInfo
  Function:
    send TVD info
  --------------------------------------------------------------------------------------*/
  HRESULT VIDEO_RPC_ENC_ToAgent_SendTVDInfo(VIDEO_RPC_ENC_SEND_TVD_INFO x) = VIDEO_RPC_VENC_FUNC_BASE + 230;


/*!
 ************************************************************************
 * \brief
 *    This function is used to set frame rate
 *
 * \return
 * \param fr
 ************************************************************************
 */
HRESULT VIDEO_RPC_ENC_ToAgent_SetFrameRate (VIDEO_RPC_ENC_SET_FRAME_RATE x)  = VIDEO_RPC_VENC_FUNC_BASE + 240 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to request Key frame
 *
 * \return
 ************************************************************************
 */
HRESULT VIDEO_RPC_ENC_ToAgent_ReqKeyFrame (VIDEO_RPC_ENC_REQ_KEY_FRAME x)  = VIDEO_RPC_VENC_FUNC_BASE + 250 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set encoding profile
 *
 * \return
 * \param fr
 ************************************************************************
 */
HRESULT VIDEO_RPC_ENC_ToAgent_SetProfile (VIDEO_RPC_ENC_SET_PROFILE x)  = VIDEO_RPC_VENC_FUNC_BASE + 260 ;



/**
 *  \defgroup Video Output APIs
 *  APIs for generic and filter-specific Video Output functionalities .
 *
 *  \author Shiyan Pan
 *  @{
 */

/*********************/
/* Video Output APIs */
/*********************/

/* General description */

/*
The Video Output APIs as will be described below are composed of two portions.
One is the global VO functions that are not associated with any specific
video source for presentation. Functions in this portion shall have the prefix
'VIDEO_RPC_VOUT_' and they mainly address the needs of the application to control
and configure the global Video Output hardware resources on Venus. Therefore,
application developers must be fully aware of the special features and
limitations of Venus hardware in order to use them properly in the application
programming. The other portion of the APIs are Video Output filter functions
corresponding to the 'VideoOut Filter' class defined by the system software which
are usually linked to a specific video source for presentation (e.g., the MPEG
Video Decoder, DV Decoder, JPEG Picture Decoder, Video Capture, and etc).
The system software may create multiple instances of the 'VideoOut Filter',
each one of which has an independent context and operates independently to each
other, although they may share the same Video Output hardware as defined by the
global VO functions. These functions will bare the prefix 'VIDEO_RPC_VO_FILTER_'.

Each Video Output Filter shall have at least two input pins, one is bound to
a video source and receives 2-D picture(s) for display (thus called the 'video
pin'), The other is bound to a DVD Sub-picture decoder and receives information
from properly decoded DVD sub-picture unit (SPU) headers (thus called the
'sub-picture pin'). The Video Output Filter is responsible for synchronizing
sub-picture and video by matching the PTS stamped in the video frames and the
PTS range information extracted from the SPU headers by the sub-picture decoder.
If a PTS match is found, pointers to the compressed sub-picture pixel data
(PXD) and to the sub-picture pixel control data (PXCD) will be attached to the
corresponding video frame as part of the the frame properties, which will be
interpreted and programmed into proper VO hardware registers together with those
for the video frame regardless if the frame is dropped or repeated due to A/V
sync or video frame rate conversion. In the event there is no DVD sub-picture
associated with the video source, the sub-picture pin shall be bound to a 'NULL'
filter indicating there is no sub-picture source.

Each Video Output Filter can also have an optional output pin for video data
write-back. When this pin is connected to a filter (by calling the filter common
API function VIDEO_RPC_ToAgent_Connect()) and the Video Output Filter is being
displayed on VO's V1 plane, then the video data will be written back to SDRAM
buffers and be passed to the downstream filter connected to this pin. When this
pin is not connected (by default), the SDRAM write-back feature of the VO's
V1 plane is disabled. This pin is usally connected to an Video Encoder in video
transcoding applications.
*/

/*************************************
 * GENERAL VO/TVE CONFIGURATION APIs *
 *************************************/

/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the video output standard.
 *    It sets up appropriate registers in the TVE, as well as VO
 *    parameters associated with the format in the digital domain such as
 *    the size of the mixer window and the display frame rate.
 *
 * \return
 *
 * \param standard:
 *    The analog television standards like NTSC, PAL, VGA or HDTV.
 *    See descriptions in VO_STANDARD for details.
 *
 * \param enProg:
 *    If true, the TVE receives the P-data from VOut, processes it in its
 *    progressive and component encoders, and outputs the progessive
 *    analog video signal in the component path. To set the 480P and 576P
 *    standards, enProg must be true and the 'standard' argument must be
 *    set to one of the NTSC and PAL standards, respectively. Interlaced
 *    video corresponding to the 480P and 576P standards will always be
 *    available in the composite and S-video output channels. If the
 *    'stardard' argument is set to one of the 720P, 1080P or (S)VGA
 *    stardards, enProg is ignored (and defaults to true).
 *
 * \param enDIF:
 *    If true, the TVE's Digital Interface will be enabled where the SAV,
 *    EAV and additional sync information will be output in the format
 *    defined in BT.656 or BT.1120. Default is false.
 *
 * \param enCompRGB:
 *    If true, the TVE's component output channel will be in RGB format.
 *    If false (default), the TVE's component output channel will be in
 *    YPbPr format.
 *
 * \param pedType:
 *    The pedestal type for the NTSC-M standard. This argument is ignored
 *    when the standard  is not NTSC-M.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetVideoStandard (VIDEO_RPC_VOUT_SET_VIDEO_STANDARD x) = VIDEO_RPC_VOUT_FUNC_BASE + 10 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to turn on/off HDMI or DVI
 *
 * \return
 *
 * \param hdmiMode:
 *    turn on/off HDMI or DVI
 * \param audioSampleFreq
 *    audio sampling frequency rate
 * \param audioChannelCount:
 *    audio channel count, e.g.: 2 ==> 2CH,...etc
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetHDMI (VIDEO_RPC_VOUT_SET_HDMI x)  = VIDEO_RPC_VOUT_FUNC_BASE + 11 ;


/*!
 ************************************************************************
 * \brief
 *    This function is used to turn on/off HDMI or DVI
 *
 * \return
 *
 * \param hdmiMode:
 *    turn on/off HDMI or DVI
 * \param colorFmt:
 *    0->RGB444 , 1->YCbCr422 , 2->YCbCr444
 * \param audioSampleFreq
 *    audio sampling frequency rate
 * \param audioChannelCount:
 *    audio channel count, e.g.: 2 ==> 2CH,...etc
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigHDMI (VIDEO_RPC_VOUT_CONFIG_HDMI x)  = VIDEO_RPC_VOUT_FUNC_BASE + 12 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to turn on/off HDMI or DVI
 *    and change HDMI setting
 *    Please refer Table 8-2 of HDMI spec ver 1.3 for detail of dataByte1 ~ 5
 * \return
 *
 * \param hdmiMode:
 *    turn on/off HDMI or DVI
 * \param audioSampleFreq
 *    audio sampling frequency rate
 * \param audioChannelCount:
 *    audio channel count, e.g.: 2 ==> 2CH,...etc
 * \param dataByte1:
 *    Rsdv      [bit7  ]
 *    Y1Y0      [bit6~5] : color fmt ## 0->RGB444 , 1->YCbCr422 , 2->YCbCr444
 *    A0        [bit4  ] : active info present. indicates whether field R3~R0 is valid
 *    B1B0      [bit3~2] : bar info  ## 0->not valid , 1->vert , 2->horiz , 3-> vert and horiz
 *    S1S0      [bit1~0] : scan info ## 0->no data , 1-> overscan , 2->underscan
 * \param dataByte2:
 *    C1C0      [bit7~6] : colorimetry      ## 0->no data, 1->ITU601 , 2->ITU709, 3->Extened colorimetry
 *    M1M0      [bit5~4] : picture AR       ## 0->no data, 1->4:3 , 2->16:9
 *    R3~R0     [bit3~0] : active format AR ##
 *                             8 -> same as picture AR,
 *                             9 -> 4:3(center),
 *                            10 -> 16:9(center),
 *                            11 -> 14:9(center),
 *                         other -> per DVB AFD active_format field in ETSI
 * \param dataByte3:
 *    ITC       [bit7  ] : IT content              ## 0->no data, 1->IT content
 *    EC2~EC0   [bit6~4] : Extended Colorimetry    ## 0->xvYCC601, 1->xvYCC709
 *    Q1Q0      [bit3~2] : Quantization range      ## 0->depends on vid fmt, 1->limited range, 2->full range,
 *    SC1SC0    [bit1~0] : non-uniform pic scaling ## 0->no known, 1->scaled horiz, 2->scaled vert, 3->scaled horiz and vert
 * \param dataByte4:
 *    Rsdv      [bit7  ]
 *    VIC6~VIC0 [bit6~0] : video fmt ID code ## refer spec for detail{ decided by firmware. }
 * \param dataByte5:
 *    Rsdv      [bit7~4]
 *    PR3~PR0   [bit3~0] : pixel repetition factor ## refer spec for detail{ decided by firmware. }
 * \param dataInt0:
 *    Rsdv      [bit31~7]
 *    xvMetaData[bit 6  ] : 0->disable, 1->enable
 *    deepDepth [bit 5~2] : if deepColor is disabled, then this bits are ignored. ## 4->24bits, 5->30bits, 6->36bits
 *    deepColor [bit1   ] : 0->disable, 1->enable
 *    disAudio  [bit0   ] : disable audio setting ## 0->enable , 1->disable
 * \param reserved1~4:
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigHdmiInfoFrame (VIDEO_RPC_VOUT_CONFIG_HDMI_INFO_FRAME x)  = VIDEO_RPC_VOUT_FUNC_BASE + 13 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the video output standard.
 *    It sets up appropriate registers in the TVE, as well as VO
 *    parameters associated with the format in the digital domain such as
 *    the size of the mixer window and the display frame rate.
 *
 * \return
 *
 * \param standard:
 *    The analog television standards like NTSC, PAL, VGA or HDTV.
 *    See descriptions in VO_STANDARD for details.
 *
 * \param enProg:
 *    If true, the TVE receives the P-data from VOut, processes it in its
 *    progressive and component encoders, and outputs the progessive
 *    analog video signal in the component path. To set the 480P and 576P
 *    standards, enProg must be true and the 'standard' argument must be
 *    set to one of the NTSC and PAL standards, respectively. Interlaced
 *    video corresponding to the 480P and 576P standards will always be
 *    available in the composite and S-video output channels. If the
 *    'stardard' argument is set to one of the 720P, 1080P or (S)VGA
 *    stardards, enProg is ignored (and defaults to true).
 *
 * \param enDIF:
 *    If true, the TVE's Digital Interface will be enabled where the SAV,
 *    EAV and additional sync information will be output in the format
 *    defined in BT.656 or BT.1120. Default is false.
 *
 * \param enCompRGB:
 *    If true, the TVE's component output channel will be in RGB format.
 *    If false (default), the TVE's component output channel will be in
 *    YPbPr format.
 *
 * \param pedType:
 *    The pedestal type for the NTSC-M standard. This argument is ignored
 *    when the standard  is not NTSC-M.
 *
 * \param dataInt0:
 *    Rsvd      [bit31~3]
 *
 *    TVE_DAC_mode [bit 4-3] : output mode of TVE DAC. >>>
 *
 *                          ##(#->DAC#123,DAC#456) (0->CVBS,YPbPr), (1->CVBS,CVBS), (2->YPbPr,YPbPr), (3->YPbPr,CVBS)
 *
 *    NTSC_sel  [bit2 ~1] : NTSC source select >>>
 *                          If the 'standard' argument is set as SD mode [480I/P,576I/P]
 *                          or partial HD mode [ 720P25,720P50,1080I50,1080P25,1080P50]
 *                          this bits are ignored.
 *                          ## 0->NTSC_M , 1->Reserved , 2->NTSC_J , 3->Reserved
 *    comp_sel  [bit0   ] : component output source select >>>
 *                          If the 'standard' argument is set to one of the NTSC or PAL
 *                          and 'enProg' argument is set to false, this bit is ignored.
 *                          ## 0->from P channel , 1->from I channel
 * \param dataInt1:
 *    Rsvd
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigVideoStandard (VIDEO_RPC_VOUT_CONFIG_VIDEO_STANDARD x) = VIDEO_RPC_VOUT_FUNC_BASE + 14 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the presentation devide (TV) type
 *
 * \return
 *
 * \param tvType:
 *    The TV type.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetTVtype (VO_TV_TYPE x) = VIDEO_RPC_VOUT_FUNC_BASE + 20 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to configure the background of the
 *    presentation device.
 *
 * \return
 *
 * \param  bgColor:
 *    The background color.
 *
 * \param  bgEnable:
 *    If true, background is the bottom layer of the image (i.e., it will
 *    be blended with video, sub-picture and other VO planes. Otherwise
 *    the background color is filled into any area of the presentation
 *    device that is not covered by any one of the VO planes (a.k.a the
 *    'fill mode').
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetBackground (VIDEO_RPC_VOUT_SET_BKGRND x) = VIDEO_RPC_VOUT_FUNC_BASE + 30 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to configure the blending order of Mixer
 *    and TOP layer is largest number
 * \return
 *
 * \param  pic:
 *    the order of background picture plane,  default value is 0
 *
 * \param  dd:
 *    the order of direct display plane,      (don't support)
 *
 * \param  v1:
 *    the order of video1 plane,              default value is 1
 *
 * \param  sub1:
 *    the order of SUB1 plane,                default value is 3
 *
 * \param  v2:
 *    the order of video2 plane,              default value is 2
 *
 * \param  osd1:
 *    the order of OSD1 plane,                default value is 4
 *
 * \param  osd2:
 *    the order of OSD2 plane,                default value is 5
 *
 * \param  csr:
 *    the order of video1 plane,              default value is 6
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetMixerOrder (VIDEO_RPC_VOUT_SET_MIXER_ORDER x) = VIDEO_RPC_VOUT_FUNC_BASE + 31 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to get the blending order of Mixer
 *    and TOP layer is largest number
 * \return
 *    VIDEO_RPC_VOUT_SET_MIXER_ORDER
 ************************************************************************
 */
VIDEO_RPC_VOUT_SET_MIXER_ORDER VIDEO_RPC_VOUT_ToAgent_GetMixerOrder () = VIDEO_RPC_VOUT_FUNC_BASE + 32 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to turn on/off the Line 21 data (Closed
 *    Caption) in a 525/60 system. This function does nothing if the
 *    video display mode is not one that corresponds to a 525/60 system.
 *
 * \return
 *
 * \param  enCC_odd:
 *    If true, when the video output mode is 480i the Line21 data at Odd
 *    field will be enabled. If false, the Line21 data will be disabled.
 *
 * \param  enCC_even:
 *    If true, the Line21 data at even field will be enabled. If false,
 *    the Line21 data at even field will be turned off.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetClosedCaption (VIDEO_RPC_VOUT_SET_CC x) = VIDEO_RPC_VOUT_FUNC_BASE + 40 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the APS bits (bits 8-9) in WORD 2
 *    of Line 20 data in a 525/60 system to trigger the Macrovision copy
 *    protection signals added to the analog NTSC video signal. The
 *    details of Line 20 data are defined in CEI/IEC 61880.
 *    This function does nothing when the video standard is not set to
 *    one that corresponds to a 525-line display system.
 *
 * \return
 *
 * \param  enExt:
 *    If true, enable the external APS settings specified below to over-
 *    write the in-band APS configurations from the internal video flow
 *    until the next VIDEO_RPC_VOUT_ToAgent_SetAPS() is called in which
 *    this parameter is set to false, in which case the Video Output
 *    firmware will switch back to using the in-band APS configurations.
 *
 * \param  APS:
 *    One of the four APS types as defined in VO_VBI_APS. If the 'enExt'
 *    parameter is set to false, this parameter is ignored.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetAPS (VIDEO_RPC_VOUT_SET_APS x) = VIDEO_RPC_VOUT_FUNC_BASE + 50 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the copy protection mode which
 *    corresponds to the CGMS-A bits of WORD2 of the Line 20 data in a
 *    525/60 system or the copyright protection bits 12 and 13 of the
 *    group 4 of the Line 23 data in a 626/50 system.
 *
 * \return
 *
 * \param  enExt:
 *    If true, enable the external copy protection settings specified
 *    below to over-write the in-band copy protection configurations
 *    from the internal video flow until the next
 *    VIDEO_RPC_VOUT_ToAgent_SetCopyMode() is called in which this
 *    parameter is set to false, in which case the Video Output firmware
 *    will switch back to using the in-band copy protection
 *    configurations.
 *
 * \param  copyMode:
 *    To specify the condition under which copying of the video signal
 *    is permitted or inhibited.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetCopyMode (VIDEO_RPC_VOUT_SET_COPY_MODE x) = VIDEO_RPC_VOUT_FUNC_BASE + 60 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the aspect ratio settings to be
 *    inserted into the bits 0-1 of in WORD 0 of the Line 20 data in a
 *    525/60 system, or into the bits 0-3 in Group A data of Line 23 in a
 *    625/50 system.
 *
 * \return
 *
 * \param  enExt:
 *    If true, enable the external aspect ratio settings specified below
 *    to over-write the in-band aspect ratio configurations from the
 *    internal video flow until the next
 *    VIDEO_RPC_VOUT_ToAgent_SetAspectRatio() is called in which this
 *    parameter is set to false, in which case the Video Output firmware
 *    will switch back to using the in-band aspect ratio configurations.
 *
 * \param  aspectRatio:
 *    To specify the aspectRatio setting in WSS.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetAspectRatio (VIDEO_RPC_VOUT_SET_AR x) = VIDEO_RPC_VOUT_FUNC_BASE + 70 ;




/*****************************************
 * GLOBAL VIDEO PLANE CONFIGURATION APIs *
 *****************************************/

/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the size, position, and border
 *    configuration of the display window for one of the two video planes
 *    (V1 and V2) available in Venus-1's the VO hardware.
 *
 * \return
 *
 * \param  videoPlane:
 *    Video plane selection, V1 or V2.
 *
 * \param  videoWin:
 *    The position and size of the video window of the selected video
 *    plane. The (x,y) coordinates of the upper left corner of the video
 *    window should be relative to border window. The video window should
 *    be inside the border window.
 *
 * \param  borderWin:
 *    The position and size of the border window of the selected video
 *    plane. The (x,y) coordinates of the upper left corner of the border
 *    window should be relative to the upper left corner of the video
 *    output device The size of the border window should not exceed the
 *    boundary of the video output device (i.e., VO hardware's mixer
 *    window), which is determined by the video standard set in
 *    SetVideoStandard().
 *
 * \param  borderColor:
 *    border color of the video plane
 *
 * \param  enBorder:
 *    If true, the border color defined by the above parameter will be
 *    filled in the area from (outside of) the video window boundary to
 *    (inside of) the border window, a.k.a. the border area (if there is
 *    any). If false, the border area will not be filled with the border
 *    color but is left with whatever has already been appended into
 *    the VO's mixer window. Turning off the border can be used, for
 *    example, to erase the upper and lower matting area when a letter-
 *    boxed video is being displayed on a 4:3 PIP display window.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigureDisplayWindow (VIDEO_RPC_VOUT_CONFIG_DISP_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 80 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the alpha value used in appending
 *    the video in V2 plane into the mixer window, possibly on the V1
 *    plane or the background.
 *
 * \return
 *
 * \param  alpha:
 *    The alpha value used in the blending, valid in [0, 15].
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetV2alpha (u_char x) = VIDEO_RPC_VOUT_FUNC_BASE + 90 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the rescaling mode of a video
 *    plane.
 *
 * \return
 *
 * \param  videoPlane:
 *    Video plane selection, V1 or V2.
 *
 * \param  rescaleMode:
 *    The rescaling mode for the above specified video plane.
 *
 * \param  rescaleWindow:
 *    If the 'rescaleMode' is VO_RESCALE_MODE_USER_DEFINE, rescaleWindow
 *    defines the size and position of the rescale window inside the video
 *    display window (defined by the 'videoWin' paramenter when calling
 *    ConfigureDisplayWindow() ) of the video plane. The (x,y) coordinates
 *    of the upper left corner of the rescale window are relative to video
 *    display window, and it must be inside the video display window.
 *    If 'rescaleMode' is set to any one of the 'KEEP_AR' modes, then
 *    'rescaleWindow' is ignored.
 *
 * \param  delayExec:
 *    if true, the execution of this function is delayed to the next
 *    synchronization picture (e.g., the first picture VideoOut receives
 *    after an EOS). If false, then the function is executed immediately
 *    upon receival, and the change on the rescaling mode is immediately
 *    applied to the current picture being displayed.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetRescaleMode (VIDEO_RPC_VOUT_SET_RESCALE_MODE x) = VIDEO_RPC_VOUT_FUNC_BASE + 100 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to specify the de-interlacing mode of a video
 *    plane.
 *
 * \return
 *
 * \param  videoPlane:
 *    Video plane selection, V1 or V2.
 *
 * \param  deintMode:
 *    The de-interlacing mode for the above specified video plane.
 *    For the V2 plane, deintMode can NOT be set to VO_DEINT_MODE_BOB,
 *    VO_DEINT_MODE_MADI, VO_DEINT_MODE_MADI_SNGLDIR,
 *    or VO_DEINT_MODE_MCOMP.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetDeintMode (VIDEO_RPC_VOUT_SET_DEINT_MODE x) = VIDEO_RPC_VOUT_FUNC_BASE + 110 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to specify a window inside the video display
 *    window of the V1 or V2 plane to zoom in. After this function is
 *    called, the video content inside the specified zoom window will be
 *    magnified to occupy the entire display window of the video plane
 *    (zoom-in). Video contents outside the zoom window and the border
 *    portion inside the zoom window will not be presented on the selected
 *    video plane. If the zoom window is not entirely inside the selected
 *    video plane, or the video plane containing the zoom window is not
 *    being used by any Video Output Filter, this function will return
 *    failure. Multiple zoom-in on the same video plane can be achieved
 *    by calling this function multiple times up to 8. The video firmware
 *    will memorize the zooming paramenter given by each call in the
 *    zoom-in sequence to determine the ultimate zoom-in window on the
 *    video source. System software can also call this same function to
 *    'zoom-out' by walking backward step by step through the inverse
 *    order of the zoom-in sequence, or go back to the 'un-zoomed' status
 *    directly.
 *
 * \return
 *     0: success
 *    -1: invalid zoom window: zoom window is not entirely inside the
 *        video display window of the selected video plane.
 *    -2: unused video plane: the selected video plane to zoom in is not
 *        being used by any Video Output Filter.
 *    -3: too many zoom-in request: there has been 8 zoom-in
 *        Video Output Filter.
 *
 * \param  videoPlane:
 *    Video plane to zoom in, V1 or V2.
 *
 * \param  zoomWin:
 *    The position and size of the window to zoom in. If 'zoomWin.width'
 *    is zero while 'zoomWin.height' is non-zero, then 'zoom-out' one
 *    step, i.e., the zoom condition goes back to the same status as of
 *    before the last 'zoom-in' call. If 'zoom.with' and 'zoom.height'
 *    are both zero, then 'zoom-out' directly to the un-zoomed status.
 *    If All arguments are 0xffff, stop zooming and
 *    use current zooming window as end zoom window.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Zoom (VIDEO_RPC_VOUT_ZOOM x) = VIDEO_RPC_VOUT_FUNC_BASE + 120 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to specify two windows relative to the video
 *    display window of the V1 or V2 plane, start & end zoom window,
 *    to pan & zoom from start zoom window to end zoom window
 *    to achieve ken burns effect. This function is equivalent to 2
 *    contiguous zoom function calls with additional time interval
 *    parameter, first call gives start zoom window and second gives
 *    end zoom window.
 * \return
 *     0: success
 *    -1: invalid zoom window: zoom window is not entirely inside the
 *        video display window of the selected video plane.
 *    -2: unused video plane: the selected video plane to zoom in is not
 *        being used by any Video Output Filter.
 *    -3: too many zoom-in request: there has been 8 zoom-in
 *        Video Output Filter.
 *
 * \param  videoPlane:
 *    Video plane to pan & zoom, V1 or V2.
 *
 * \param  zoomWinStart:
 *    Start zoom window to be displayed on whole display window.
 *    If All arguments are 0xffff, use previous end zoom vindow
 *    as start zoom window.
 *
 * \param  zoomWinEnd:
 *    End zoom window to be displayed on whole display window.
 *    If All arguments are 0xffff, stop panning & zooming and
 *    use current zooming window as end zoom window.
 *
 * \param  time:
 *    time interval to pan & zoom from start zoom window to end zoom
 *    window in micro-second unit.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Pan_Zoom (VIDEO_RPC_VOUT_PAN_ZOOM x) = VIDEO_RPC_VOUT_FUNC_BASE + 121 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to specify two alpha values
 *    of the V1 or V2 plane, start & end alpha value,
 *    to set the transparency from start alpha to end alpha.
 *    The alpha value of 0 implies full transparency and 256 implies no transparency.
 * \return
 *     0: success
 *
 * \param  videoPlane:
 *    V1 or V2.
 *
 * \param  alphaStart:
 *    If argument is larger than 256, use previous end alpha value
 *    as start alpha value.
 *
 * \param  alphaEnd:
 *    If argument is larger than 256, stop blending and
 *    use current alpha value as end alpha value.
 *
 * \param  time:
 *    time interval to blend from start alpha value to end alpha
 *    value in micro-second unit.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetTransparency (VIDEO_RPC_VOUT_TRANSPARENCY x) = VIDEO_RPC_VOUT_FUNC_BASE + 122 ;



/*****************************************
 *           GLOBAL OSD APIs             *
 *****************************************/

/*!
 ************************************************************************
 * \brief
 *    This function is used to set up VO hardware's global OSD parameters.
 *
 * \return
 *
 * \param  lpfType:
 *    OSD chroma and alpha low pass filter (444->422) selection, default
 *    is 'VO_OSD_LPF_TYPE_DROP'.
 *
 * \param  RGB2YUVcoeff:
 *    RGB to YUV transformation matrix coefficients (all in s9 format,
 *    defaults to standard conversion coefficients):
 *    words 0-8:  RGB to YUV transform matrix multiplication coefficients
 *    word    9:  RGB to YUV transform matrix addition coefficients for V
 *    word   10:  RGB to YUV transform matrix addition coefficients for U
 *    word   11:  RGB to YUV transform matrix addition coefficients for Y
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigureOSD (VIDEO_RPC_VOUT_CONFIG_OSD x) = VIDEO_RPC_VOUT_FUNC_BASE + 130 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to set up OSD palette for index mode.
 *
 * \return
 *
 * \param  paletteIndex:
 *    assign an index to this palette, valid in [0, 3]
 *
 * \param  pPalette:
 *    Pointer to palette data. the format is :
 *    address          Byte3 | Byte2 | Byte1 | Byte0
 *    pPalette + 0x0     A       Cr      Cb      Y
 *    pPalette + 0x4     A       Cr      Cb      Y
 *    pPalette + 0x8     A       Cr      Cb      Y
 *     ...
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigureOSDPalette (VIDEO_RPC_VOUT_CONFIG_OSD_PALETTE x) = VIDEO_RPC_VOUT_FUNC_BASE + 131 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to create an OSD window. Due to VO hardware
 *    limitations, if four OSD windows have already been created and have
 *    not been deleted before this function is called, or the position of
 *    the OSD window to be created is horizontally overlapping another OSD
 *    window(s) created earlier, this function will return failure with
 *    an error code identifying the reason of the failure.
 *
 * \return
 *    If the OSD window is successfully created, return the ID of the just
 *    created OSD window (a positive integer). Otherwise, return the
 *    following error code:
 *
 *    -1: There are already 4(four) OSD windows created.
 *    -2: The position of the OSD window to be created is horizontally
 *        overlapping one or more of the previously created OSD window(s).
 *
 * \param  winPos:
 *    The position and size of the OSD window on the VO hardware's mixer
 *    coordinate.
 *
 * \param  colorFmt:
 *    Color format of the OSD window.
 *
 * \param  colorKey:
 *    Color key value of the OSD window in RGB888 format. If the
 *    'colorFmt' parameter is VO_OSD_COLOR_FORMAT_RGB332 or
 *    VO_OSD_COLOR_FORMAT_RGB565, only the lower corresponding bits of
 *    RGB888 format will be used in defining the color key in these two
 *    formats. -1 if no color key.
 *
 * \param  alpha:
 *    Constant alpha value of the OSD window, valid in [0, 255].
 *    -1 if no alpha blending.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_CreateOSDwindow (VIDEO_RPC_VOUT_CREATE_OSD_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 140 ;




/*!
 ************************************************************************
 * \brief
 *    assign an palette index to an OSD window for index mode
 *
 * \return
 *
 * \param  winID:
 *    The ID of the OSD window to set.
 *
 * \param  paletteIndex:
 *    assign an palette index to this window if colorFmt is index mode, valid in [0, 3].
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetOSDwindowPalette (VIDEO_RPC_VOUT_SET_OSD_WIN_PALETTE x) = VIDEO_RPC_VOUT_FUNC_BASE + 141 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to modify the configuration of an OSD window
 *    created earlier.
 *
 * \return
 *     0: modification(s) successfully completed.
 *    -1: invalid OSD window ID.
 *    -2: the OSD window position is to be modified but the new position
 *        specified is horizontally overlapping one or more of other
 *        existing OSD window(s).
 *
 * \param  winID:
 *    The ID of the OSD window to modify.
 *
 * \param  reqMask:
 *    The mask word to specify which configuration(s) is(are) to be
 *    modified. It is composed by 'or'-ing one or more of the following
 *    mask words each representing one of the configuration item that
 *    can be modified:
 *
 *       VO_OSD_WIN_POSITION == 0x01: to modify 'winPos'
 *       VO_OSD_WIN_COLORFMT == 0x02: to modify 'colorFmt'
 *       VO_OSD_WIN_COLORKEY == 0x04: to modify 'colorKey'
 *       VO_OSD_WIN_ALPHA    == 0x08: to modify 'alpha'
 *       VO_OSD_WIN_SRC_LOCATION == 0x10: to modify 'source location'
 *
 *    If the any one of the bits in the 'reqMask' word is 0, then its
 *    corresponding configuration items defined in the arguments below
 *    will be ignored by this function
 *
 * \param  winPos:
 *    The position and size of the OSD window on the VO hardware's mixer
 *    coordinate.
 *
 * \param  colorFmt:
 *    Color format of the OSD window.
 *
 * \param  colorKey:
 *    Color key value of the OSD window in RGB888 format. If the
 *    'colorFmt' parameter is VO_OSD_COLOR_FORMAT_RGB332 or
 *    VO_OSD_COLOR_FORMAT_RGB565, only the lower corresponding bits of
 *    RGB888 format will be used in defining the color key in these two
 *    formats. -1 if no color key.
 *
 * \param  alpha:
 *    Constant alpha value of the OSD window, valid in [0, 255].
 *    -1 if no alpha blending.
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be 4-page aligned.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ModifyOSDwindow (VIDEO_RPC_VOUT_MODIFY_OSD_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 150 ;





/*!
 ************************************************************************
 * \brief
 *    This function is used to modify the configuration of an OSD window
 *    created earlier.
 *
 * \return
 *     0: modification(s) successfully completed.
 *    -1: invalid OSD window ID.
 *    -2: the OSD window position is to be modified but the new position
 *        specified is horizontally overlapping one or more of other
 *        existing OSD window(s).
 *
 * \param  winID:
 *    The ID of the OSD window to modify.
 *
 * \param  reqMask:
 *    The mask word to specify which configuration(s) is(are) to be
 *    modified. It is composed by 'or'-ing one or more of the following
 *    mask words each representing one of the configuration item that
 *    can be modified:
 *
 *       VO_OSD_WIN_POSITION == 0x01: to modify 'winPos'
 *       VO_OSD_WIN_COLORFMT == 0x02: to modify 'colorFmt'
 *       VO_OSD_WIN_COLORKEY == 0x04: to modify 'colorKey'
 *       VO_OSD_WIN_ALPHA    == 0x08: to modify 'alpha'
 *       VO_OSD_WIN_SRC_LOCATION == 0x10: to modify 'source location'
 *
 *    If the any one of the bits in the 'reqMask' word is 0, then its
 *    corresponding configuration items defined in the arguments below
 *    will be ignored by this function
 *
 * \param  winPos:
 *    The position and size of the OSD window on the VO hardware's mixer
 *    coordinate.
 *
 * \param  colorFmt:
 *    Color format of the OSD window.
 *
 * \param  colorKey:
 *    Color key value of the OSD window in RGB888 format. If the
 *    'colorFmt' parameter is VO_OSD_COLOR_FORMAT_RGB332 or
 *    VO_OSD_COLOR_FORMAT_RGB565, only the lower corresponding bits of
 *    RGB888 format will be used in defining the color key in these two
 *    formats. -1 if no color key.
 *
 * \param  alpha:
 *    Constant alpha value of the OSD window, valid in [0, 255].
 *    -1 if no alpha blending.
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be 4-page aligned.
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ModifyOSDwindowOnGo (VIDEO_RPC_VOUT_MODIFY_OSD_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 151 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to delete an OSD window previously created.
 *    After this function is called the OSD window specified is
 *    permanently removed from the VO firmware's internal registry, the
 *    windows' ID becomes invalid and therefore the window is no longer
 *    available to draw any image upon.
 *
 * \return
 *     0: requested OSD window successfully deleted.
 *    -1: invalid OSD window ID.
 *
 * \param  winID:
 *    The ID of the OSD window to delete.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DeleteOSDwindow (u_char winID) = VIDEO_RPC_VOUT_FUNC_BASE + 160 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to delete an OSD window previously created.
 *    After this function is called the OSD window specified is
 *    permanently removed from the VO firmware's internal registry, the
 *    windows' ID becomes invalid and therefore the window is no longer
 *    available to draw any image upon.
 *
 * \return
 *     0: requested OSD window successfully deleted.
 *    -1: invalid OSD window ID.
 *
 * \param  winID:
 *    The ID of the OSD window to delete.
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DeleteOSDwindowOnGo (VIDEO_RPC_VOUT_DELETE_OSD_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 161 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to draw an image or a portion of an image on
 *    a given OSD window.
 *
 * \return
 *     0: image successsfully drawn on the requested OSD window.
 *    -1: invalid OSD window ID.
 *
 * \param  winID:
 *    The ID of the OSD window to draw upon.
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be 4-page aligned.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DrawOSDwindow (VIDEO_RPC_VOUT_DRAW_OSD_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 170 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to draw an image or a portion of an image on
 *    a given OSD window.
 *
 * \return
 *     0: image successsfully drawn on the requested OSD window.
 *    -1: invalid OSD window ID.
 *
 * \param  winID:
 *    The ID of the OSD window to draw upon.
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be 4-page aligned.
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DrawOSDwindowOnGo (VIDEO_RPC_VOUT_DRAW_OSD_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 171 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to hide the content from being displayed in
 *    an OSD window. After this function is called the content in the OSD
 *    window specified will disappear. However the OSD window still
 *    exists for furture drawing until deleted.
 *
 * \return
 *     0: requested OSD window successfully hidden.
 *    -1: invalid OSD window ID.
 *
 * \param  winID:
 *    The ID of the OSD window to hide.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_HideOSDwindow (u_char winID) = VIDEO_RPC_VOUT_FUNC_BASE + 180 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to hide the content from being displayed in
 *    an OSD window. After this function is called the content in the OSD
 *    window specified will disappear. However the OSD window still
 *    exists for furture drawing until deleted.
 *
 * \return
 *     0: requested OSD window successfully hidden.
 *    -1: invalid OSD window ID.
 *
 * \param  winID:
 *    The ID of the OSD window to hide.
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_HideOSDwindowOnGo (VIDEO_RPC_VOUT_HIDE_OSD_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 181 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to set up source OSD window in Canvas and
 *    display window in Mixer for scaling purpose
 * \return
 *
 * \param  srcWin:
 *    source window in Canvas
 * \param  dispWin:
 *    display window in Mixer
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigOSDCanvas (VIDEO_RPC_VOUT_CONFIG_OSD_CANVAS x) = VIDEO_RPC_VOUT_FUNC_BASE + 182 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to set up source OSD/SUB1/SUB2 window in Canvas and
 *    display window in Mixer for scaling purpose
 * \return
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param  srcWin:
 *    source window in Canvas
 *
 * \param  dispWin:
 *    display window in Mixer
 *
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigureGraphicCanvas (VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS x) = VIDEO_RPC_VOUT_FUNC_BASE + 183 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to create an OSD window. Due to VO hardware
 *    limitations, if four OSD windows have already been created and have
 *    not been deleted before this function is called, or the position of
 *    the OSD window to be created is horizontally overlapping another OSD
 *    window(s) created earlier, this function will return failure with
 *    an error code identifying the reason of the failure.
 *
 * \return
 *    If the OSD window is successfully created, return the ID of the just
 *    created OSD window (a positive integer). Otherwise, return the
 *    following error code:
 *
 *    -1: There are already 4(four) OSD windows created.
 *    -2: The position of the OSD window to be created is horizontally
 *        overlapping one or more of the previously created OSD window(s).
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param  winPos:
 *    The position and size of the OSD window on the VO hardware's mixer
 *    coordinate.
 *
 * \param  colorFmt:
 *    Color format of the OSD window.
 *
 * \param  rgbOrder:
 *    the RGB Order for RGB color format
 *
 * \param  colorKey:
 *    Color key value of the OSD window in RGB888 format. If the
 *    'colorFmt' parameter is VO_OSD_COLOR_FORMAT_RGB332 or
 *    VO_OSD_COLOR_FORMAT_RGB565, only the lower corresponding bits of
 *    RGB888 format will be used in defining the color key in these two
 *    formats. -1 if no color key.
 *
 * \param  alpha:
 *    Constant alpha value of the OSD window, valid in [0, 255].
 *    -1 if no alpha blending.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_CreateGraphicWindow (VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 184 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to hide the content from being displayed in
 *    an OSD window. After this function is called the content in the OSD
 *    window specified will disappear. However the OSD window still
 *    exists for furture drawing until deleted.
 *
 * \return
 *     0: requested OSD window successfully hidden.
 *    -1: invalid OSD window ID.
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param  winID:
 *    The ID of the OSD window to hide.
 *
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_HideGraphicWindow (VIDEO_RPC_VOUT_HIDE_GRAPHIC_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 185 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to modify the configuration of an OSD window
 *    created earlier.
 *
 * \return
 *     0: modification(s) successfully completed.
 *    -1: invalid OSD window ID.
 *    -2: the OSD window position is to be modified but the new position
 *        specified is horizontally overlapping one or more of other
 *        existing OSD window(s).
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param  winID:
 *    The ID of the OSD window to modify.
 *
 * \param  reqMask:
 *    The mask word to specify which configuration(s) is(are) to be
 *    modified. It is composed by 'or'-ing one or more of the following
 *    mask words each representing one of the configuration item that
 *    can be modified:
 *
 *       VO_OSD_WIN_POSITION == 0x01: to modify 'winPos'
 *       VO_OSD_WIN_COLORFMT == 0x02: to modify 'colorFmt' and 'rgbOrder'
 *       VO_OSD_WIN_COLORKEY == 0x04: to modify 'colorKey'
 *       VO_OSD_WIN_ALPHA    == 0x08: to modify 'alpha'
 *       VO_OSD_WIN_SRC_LOCATION == 0x10: to modify 'source location'
 *       VO_OSD_WIN_STORAGE_TYPE == 0x20: to modify 'storageMode',
 *                                      'compressed', 'paletteIndex',
 *                                      'interlace_Frame' and 'bottomField'
 *
 *    If the any one of the bits in the 'reqMask' word is 0, then its
 *    corresponding configuration items defined in the arguments below
 *    will be ignored by this function
 *
 * \param  winPos:
 *    The position and size of the OSD window on the VO hardware's mixer
 *    coordinate.
 *
 * \param  colorFmt:
 *    Color format of the OSD window.
 *
 * \param  rgbOrder:
 *    the RGB Order for RGB color format
 *
 * \param  colorKey:
 *    Color key value of the OSD window in RGB888 format. If the
 *    'colorFmt' parameter is VO_OSD_COLOR_FORMAT_RGB332 or
 *    VO_OSD_COLOR_FORMAT_RGB565, only the lower corresponding bits of
 *    RGB888 format will be used in defining the color key in these two
 *    formats. -1 if no color key.
 *
 * \param  alpha:
 *    Constant alpha value of the OSD window, valid in [0, 255].
 *    -1 if no alpha blending.
 *
 * \param  storageMode:
 *    sequential mode or block mode
 *
 * \param  paletteIndex:
 *    assign an palette index to this window if colorFmt is index mode, valid in [0, 3].
 *
 * \param compressed:
 *    1: Felics compressed bitstream
 *
 * \param interlace_frame:
 * 1: interlace frame
 *
 * \param bottomField:
 * 1: select bottom field if it is interlace frame
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be 4-page aligned.
 *
 * startX[i], startY[i], imgPitch[i], pImage[i]
 * i = 0: Top or Progressive OSD start address.
 *        Felics compressed bitstream sequential address 0
          For Video Format, it is Luma address
 * i = 1: Bottom OSD start address.
          Felics compressed bitstream sequential address 1
          For Video Format, it is Chroma address
 * i = 2: Felics compressed bitstream sequential address 2
 * i = 3: Felics compressed bitstream sequential address 3
 *
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ModifyGraphicWindow (VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 186 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to delete an OSD window previously created.
 *    After this function is called the OSD window specified is
 *    permanently removed from the VO firmware's internal registry, the
 *    windows' ID becomes invalid and therefore the window is no longer
 *    available to draw any image upon.
 *
 * \return
 *     0: requested OSD window successfully deleted.
 *    -1: invalid OSD window ID.
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param  winID:
 *    The ID of the OSD window to delete.
 *
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DeleteGraphicWindow (VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 187 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to draw an image or a portion of an image on
 *    a given OSD window.
 *
 * \return
 *     0: image successsfully drawn on the requested OSD window.
 *    -1: invalid OSD window ID.
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param  winID:
 *    The ID of the OSD window to draw upon.
 *
 * \param  storageMode:
 *    sequential mode or block mode
 *
 * \param  paletteIndex:
 *    assign an palette index to this window if colorFmt is index mode, valid in [0, 3].
 *
 * \param compressed:
 *    1: Felics compressed bitstream
 *
 * \param interlace_frame:
 * 1: interlace frame
 *
 * \param bottomField:
 * 1: select bottom field if it is interlace frame
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be 4-page aligned.
 *
 * startX[i], startY[i], imgPitch[i], pImage[i]
 * i = 0: Top or Progressive OSD start address.
 *        Felics compressed bitstream sequential address 0
          For Video Format, it is Luma address
 * i = 1: Bottom OSD start address.
          Felics compressed bitstream sequential address 1
          For Video Format, it is Chroma address
 * i = 2: Felics compressed bitstream sequential address 2
 * i = 3: Felics compressed bitstream sequential address 3
 *
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DrawGraphicWindow (VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN x) = VIDEO_RPC_VOUT_FUNC_BASE + 188 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to draw/disable all OSD windows from Mixer
 *
 * \return
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param  osdNum:
 *    Number of OSD window to display
 *    0: disable OSD
 *
 * \param  pGraphic:
 *    Pointer to the graphic structure (VIDEO_RPC_VOUT_DISPLAY_GRAPHIC_WIN)
 *
 * \param  x, y, width, height:
 *    The position and size of the OSD window on the canvas coordinate.
 *
 * \param  colorFmt:
 *    Color format of the OSD window.
 *
 * \param  rgbOrder:
 *    the RGB Order for RGB color format
 *
 * \param  colorKey:
 *    Color key value of the OSD window in RGB888 format. If the
 *    'colorFmt' parameter is VO_OSD_COLOR_FORMAT_RGB332 or
 *    VO_OSD_COLOR_FORMAT_RGB565, only the lower corresponding bits of
 *    RGB888 format will be used in defining the color key in these two
 *    formats. -1 if no color key.
 *
 * \param  alpha:
 *    Constant alpha value of the OSD window, valid in [0, 255].
 *    -1 if no alpha blending.
 *
 * \param  storageMode:
 *    sequential mode or block mode
 *
 * \param  paletteIndex:
 *    assign an palette index to this window if colorFmt is index mode, valid in [0, 3].
 *
 * \param compressed:
 * 1: Felics compressed bitstream
 *
 * \param interlace_frame:
 * 1: interlace frame
 *
 * \param bottomField:
 * 1: select bottom field if it is interlace frame
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be 4-page aligned.
 *
 * \param go:
 *    0: caching OSD's setting in structure
 *    1: restore OSD's setting into hardware registers
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DisplayGraphic (VIDEO_RPC_VOUT_DISPLAY_GRAPHIC x) = VIDEO_RPC_VOUT_FUNC_BASE + 189 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config canvas.dispWin is defined through ConfigureGraphicCanvas or video hack to fit MainAct or Den
 *
 * \return
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 *
 * \param mode:
 *    0: canvas.dispWin defined through ConfigureGraphicCanvas
 *    1: canvas.dispWin fit MainAct
 *    2: canvas.dispWin fit Den
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_HackGraphicCanvas (VIDEO_RPC_VOUT_HACK_GRAPHICCANVAS x) = VIDEO_RPC_VOUT_FUNC_BASE + 191 ;




/*****************************************
 *          GLOBAL CURSOR APIs           *
 *****************************************/

/*!
 ************************************************************************
 * \brief
 *    This function is used to configure the VO hardware's cursor plane.
 *
 * \return
 *
 * \param  alpha:
 *    Constant alpha value of the cursor, valid in [0, 15].
 *    -1 if no alpha blending.
 *
 * \param  colorKey:
 *    Color key index, valid in [0, 3], -1 if no color key.
 *
 * \param  colorMap:
 *    The four colors in the cursor color look-up table.
 *
 * \param  lpfType:
 *    Cursor chroma low pass filter (444->422) selection. Default value
 *    is VO_OSD_LPF_TYPE_DROP.
 *
 * \param  pCursorImg:
 *    The address of the 32x32x2-bit (265 bytes) bitmap of the cursor
 *    image. Address must align to 8-byte boundary.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigureCursor (VIDEO_RPC_VOUT_CONFIG_CURSOR x) = VIDEO_RPC_VOUT_FUNC_BASE + 190 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to configure the Mars VO hardware's cursor plane.
 *
 * \return
 *
 * \param  width:
 *    width of this crusor, less than 512
 *
 * \param  height:
 *    height of this crusor, less than 512
 *
 * \param  colorFmt:
 *    Color format of this cursor, valid in 2-bit, 4-bit and 8-bit index formats.
 *
 * \param  paletteIndex:
 *    assign an palette index to this cursor, valid in [0, 3].
 *
 * \param  pCursorImg:
 *    The address of the 32x32x2-bit (265 bytes) bitmap of the cursor
 *    image. Address must align to 8-byte boundary.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigureMarsCursor (VIDEO_RPC_VOUT_CONFIG_MARS_CURSOR x) = VIDEO_RPC_VOUT_FUNC_BASE + 192 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to draw the cursor at the specified position
 *    according to the cursor configuration set in ConfigureCursor().
 *    The cursor will be drawn at the same position on all following
 *    video frames until the next DrawCursor() is called or the function
 *    EraseCursor() is called.
 *
 * \return
 *
 * \param  x:
 *    The x coordinate of the upper-left corner point of the cursor on
 *    VO hardware's mixer coordinate.
 *
 * \param  y:
 *    The y coordinate of the upper-left corner point of the cursor on
 *    VO hardware's mixer coordinate.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_DrawCursor (VIDEO_RPC_VOUT_DRAW_CURSOR x) = VIDEO_RPC_VOUT_FUNC_BASE + 200 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to erase the cursor previously drawn on the
 *    display window. After this function is called, the cursor will
 *    disappear from the video display.
 *
 * \return
 *
 * \param
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_HideCursor() = VIDEO_RPC_VOUT_FUNC_BASE + 210 ;



/****************************************************
 *  GLOBAL PEAKING/CORING and COLOR ADJUSTMENT APIs *
 ****************************************************/

/*!
 ************************************************************************
 * \brief
 *    This function is used to set the filtering strength of the
 *    peaking/coring filter.
 *
 * \return
 *
 * \param strength:
 *   The strength of the peaking/coring filter, valid in [0, 64] with
 *   0 being the weakest (no filtering) and 64 being the strongest.
 *   Default value is 0.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetPeakingStrength (u_char strength) = VIDEO_RPC_VOUT_FUNC_BASE + 220 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to adjust the brightness of the digital
 *    video output signal (after the VO mixer and before TVE).
 *
 * \return
 *
 * \param  brightness:
 *    The brightness of the output signal, valid in [0, 64] with 0 being
 *    the darkest and 64 being the brightest. Default value is 32.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetBrightness (u_char brightness) = VIDEO_RPC_VOUT_FUNC_BASE + 230 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to adjust the hue of the digital
 *    video output signal (after the VO mixer and before TVE).
 *
 * \return
 *
 * \param  hue:
 *    The hue of the output signal, valid in [0, 64] with 0 being
 *    the weakest and 64 being the strongest. Default value is 32.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetHue (u_char hue) = VIDEO_RPC_VOUT_FUNC_BASE + 240 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to adjust the saturation of the digital
 *    video output signal (after the VO mixer and before TVE).
 *
 * \return
 *
 * \param  saturation:
 *    The saturation of the output signal, valid in [0, 64] with 0 being
 *    the weakest and 64 being the strongest. Default value is 32.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetSaturation (u_char saturation) = VIDEO_RPC_VOUT_FUNC_BASE + 250 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to adjust the contrast of the digital
 *    video output signal (after the VO mixer and before TVE).
 *
 * \return
 *
 * \param  contrast:
 *    The contrast of the output signal, valid in [0, 64] with 0 being
 *    the weakest and 64 being the strongest. Default value is 32.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetContrast (u_char contrast) = VIDEO_RPC_VOUT_FUNC_BASE + 255 ;


/*!
 ************************************************************************
 * \brief
 *    This function is used to adjust VO hardware's Color Adjustment transformation matrix.
 *         Y'        m00 m10 m20       Y        a0
 *       [ Cb' ] = [ m01 m11 m21 ] * [ Cb ] + [ a1 ]
 *         Cr'       m02 m12 m22       Cr       a2
 *
 * \return
 *
 * \param  ColorMatrixCoeff:
 *    Color Adjustment transformation matrix coefficients
 *    words 0-8:  m00,m10,m20,m01,m11,m21,m02,m12,m22 (all in s1.10 format)
 *    word    9:  a0, Color Adjustment transformation matrix addition coefficients for Y (s8 format)
 *    word   10:  a1, Color Adjustment transformation matrix addition coefficients for U (s8 format)
 *    word   11:  a2, Color Adjustment transformation matrix addition coefficients for V (s8 format)
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigColorMatrix (VIDEO_RPC_VOUT_CONFIG_COLOR_MATRIX x) = VIDEO_RPC_VOUT_FUNC_BASE + 256 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to capture the video displaying on TV.
 *
 * \return
 *
 * \param  colorFmt:
 *    color format after transferring (ONLY for RGB format)
 * \param  pImage:
 *    destination address
 * \param  imgPitch:
 *    the pitch of the destination
 * \param  startX:
 *    starting x on the destination coordinate to place image
 * \param  startY:
 *    starting y on the destination coordinate to palce image
 * \param  width:
 *    image width after transferring  (width currently be smaller than 352)
 * \param  height:
 *    image height after transferring (height currently be smaller than 288)
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_VideoCapture (VIDEO_RPC_VOUT_VIDEO_CAPTURE x) = VIDEO_RPC_VOUT_FUNC_BASE + 257 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set Y offset of subtitle relative to
 *    original y position
 *
 * \return
 *
 * \param  x:
 *    The Y offset value
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetSubtitleYoffset (short x) = VIDEO_RPC_VOUT_FUNC_BASE + 258 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to switch the domination for subtitle plane from system to video
 *    e.g.: the position of BD Menu controlled by system originally
 *
 * \return
 *
 * \param  enable:
 *    0: controlled by system, 1: by video
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SwitchSPDomination (short enable) = VIDEO_RPC_VOUT_FUNC_BASE + 259 ;



/*****************************************************
 *  BEHAVIOUR OF VIDEO OUTPUT FILTER ON COMMON APIs  *
 *****************************************************/

/*
 VIDEO_RPC_ToAgent_Create():
 ===========================
   Default behaviour.


 VIDEO_RPC_ToAgent_Connect():
 ============================
   The Video Output Filter can be connected to up to three source and
   destination filters: a video source filter, a sub-picture decoder
   source filter (optional, and if not connected the Video Output
   Filter's sub-picture overlay feature is automatically disabled),
   and a data write-back filter (optional, and if connected, the Video
   Output Filter must be displayed on the V1 plane, or there will be no
   data written back to SDRAM buffers and passed to the downstream filter
   although connected. If not connected the SDRAM write-back feature of
   the Video Output Filter is automatically disabled).


 VIDEO_RPC_ToAgent_InitRingBuffer():
 ===================================
   This is not supported by the the Video Output Filter and will return
   failure when called.


 VIDEO_RPC_ToAgent_Run():
 ========================
   If called when the Video Output Filter is in the 'idle (stop)' state
   it will start reading the input data from the connected video source and
   start the presentation according to the current configuration of the video
   source. If called when the Video Output Filter is in the 'pause' state,
   the Video Output Filter will resume reading its input data for seamless
   continuous presentation from the last paused frame.


 VIDEO_RPC_ToAgent_Pause():
 ==========================
   If called when the Video Output Filter is in the 'run' state, it will
   temporarily pause the continuous presentation of the connected video source
   by freezing the display on the last display frame, and it will also stop
   consuming its input data. If called when the Video Output Filter is in the
   'idle (stop)' state, the Video Output Filter will wait for the first frame
   data to reach its input pipeline and when it does, display and freeze on
   the first frame (a.k.a. pause-trigger) until the next VIDEO_RPC_ToAgent_Run()
   is called on which the Video Output Filter will resume seamless continuous
   presentation from the next input frame.


 VIDEO_RPC_ToAgent_Stop():
 =========================
   When called, the Video Output Filter will stop reading its input data
   from the connected video source and flush the Filter's input pipeline by
   releasing all picture buffers in it except the last frame which will still
   be displayed indefinitely until further actions are instructed by the
   system software.


 VIDEO_RPC_ToAgent_Destroy():
 ============================
   Default behaviour. When the source of this Video Output Filter is being
   displayed on the V1 or V2 plane, it is recommended that the system software
   select other Video Output Filter to use the display plane by calling the
   function 'VIDEO_RPC_VO_FILTER_ToAgent_SelectDisplayPlane()' before this
   Video Output Filter is destroyed. If not, when this Video Output Filter
   is destroyed, the video plane it was previously selected to will display
   the border color.



 VIDEO_RPC_ToAgent_Flush():
 ==========================
   Default behaviour but keep the buffer for the last picture being displayed
   if the filter has been selected to be displayed on the V1 or the V2 plane.


 VIDEO_RPC_ToAgent_SetRefClock():
 ================================
   Default behaviour to initialize a Video Output Filter. This is
   a hand-shake operation completed during the Video Output Filter
   initalization to set up some share-memory type structures that will
   be monitored/updated by both the system and video SW sides.

   Input is a poiner to the share-memory structure that includes the
   channel specific reference clock shared with system and audio (which
   defines AV mastership and local clock PTS for A/V sync and video
   speed control), the PTS to notify system SW the latest video frame
   being displayed, the 'context' information genereated by streaming
   source (e.g., DEMUX) to be fed back to the system SW as notification,
   and etc.


/*************************************
 * GENERAL VO/TVE CONFIGURATION APIs *
 *************************************/


/**************************************
 *  VIDEO OUTPUT FILTER SPECIAL APIs  *
 **************************************/

/*!
 ************************************************************************
 * \brief
 *    This function is used to display video on one of the VO hardware's
 *    video planes V1 or V2, when the 'videoPlane' parameter is set to
 *    VO_VIDEO_PLANE_V1V1 or VO_VIDEO_PLANE_V2, respectively. If the V1
 *    or the V2 plane has already been selected to display video from
 *    another Vide Output Filter, calling this function will result in
 *    the previous selection being overwritten by the latest one which
 *    takes effect immediately after this function is called.
 *
 *    By setting the 'videoPlane' parameter to VO_VIDEO_PLANE_NONE, this
 *    function can be also used to hide the video of the Video Output
 *    Filter. Please note that even when the video is 'hidden', the
 *    Video Output Filter still consumes its input video samples as it
 *    would normally do unless the 'zeroBuffer' parmater is set to true.
 *
 * \return
 *
 * \param  videoPlane:
 *    Video plane selection: V1 or V2 to display video, NONE to hide
 *
 * \param  zeroBuffer:
 *    When 'videoPlane' is set to VO_VIDEO_PLANE_NONE (i.e., video
 *    is running in 'background') and 'zeroBuffer' is true, then the
 *    Video Output Filter will discard its input video samples as soon
 *    as they are received in the input pin, and therefore hold zero
 *    buffer. This is usually needed in real-time video flows bound at
 *    the rate of video producer (such as the encoding flow) rather
 *    than that of the video consumer (such as the playback flow).
 *
 *    This parameter is ignored when 'videoPlane' is set to a value
 *    other than VO_VIDEO_PLANE_NONE.
 *
 * \param realTimeSrc:
 *    Real Time Source. when 'realTimeSrc' is true, then the
 *    Video Output Filter will keep 3 fields before displaying
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_Display (VIDEO_RPC_VO_FILTER_DISPLAY x) = VIDEO_RPC_VOUT_FUNC_BASE + 260 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to capture the video displaying on video plane
 *    that contains border. But, we will capture source picture
 *    if it don't belong to any video plane.
 *
 * \return
 *
 * \param  colorFmt:
 *    color format after format conversion (ONLY big/little endian for RGB565,RGBA8888,ARGB8888)
 * \param  pImage:
 *    destination address
 * \param  imgPitch:
 *    the pitch of the destination
 * \param  startX:
 *    starting x on the destination coordinate to place image
 * \param  startY:
 *    starting y on the destination coordinate to palce image
 * \param  width:
 *    image width after format conversion
 * \param  height:
 *    image height after format conversion
 * \param  pStretchBuf:
 *    buffer for stretch before format conversion
 * \param  stretchBufSize:
 *    size of stretch buffer
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_Capture (VIDEO_RPC_VO_FILTER_CAPTURE x) = VIDEO_RPC_VOUT_FUNC_BASE + 270 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to set the video presentation speed
 *    regardless of whether this Video Output Filter is currently
 *    selected to be displayed on one of the two video planes in the VO
 *    hardware.
 *
 * \return
 *
 * \param  speed:
 *    The presentation speed of this Video Output Filter:
 *     b0-b7:  fractional part of the speed
 *     b8-b31: integer    part of the speed, two's complement if negative
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_SetSpeed (VIDEO_RPC_VO_FILTER_SET_SPEED x) = VIDEO_RPC_VOUT_FUNC_BASE + 290 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to step the video presentation one further
 *    frame. After this function is called the Video Output Filter will
 *    display the next video frame following the frame on which the
 *    Video Output Filter is being paused. This function can only be
 *    called when the Video Output Filter is in the 'Pause' state.
 *
 * \return
 *
 * \param
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_Step (long instanceID) = VIDEO_RPC_VOUT_FUNC_BASE + 300 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to display a still picture on the video plane
 *    to which the Video Output Filter is attached. This function can
 *    be called only when the Video Output Filter is not being used for
 *    video presentation, i.e., it has to be in the 'stopped' state.
 *
 * \return
 *
 * \param  lumaAddr:
 *    Physical address of luma buffer in block storage mode.
 *    Must be 4-page aligned.
 *
 * \param  lumaPitch:
 *    Pitch of luma buffer in luma pixel unit. Must be multiple of 256.
 *
 * \param  chromaAddr:
 *    Physical address of chroma data in block storage mode.
 *    Must be 4-page aligned. Chroma must be in 4:2:0 format.
 *
 * \param  chromaPitch:
 *    Pitch of chroma buffer in luma pixel unit. Must be multiple of 256.
 *
 * \param  width:
 *    Picture width in luma pixel unit.
 *
 * \param  height:
 *    Picture height in luma pixel unit.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ShowStillPicture (VIDEO_RPC_VO_FILTER_SHOW_STILL_PIC x) = VIDEO_RPC_VOUT_FUNC_BASE + 310 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to fill the video border(s) with a fixed
 *    color, usually to hide video artifacts that can't be otherwise
 *    removed in video processings prior to display.
 *
 *    This function can be called multiple times to specify each
 *    border if more than one of the four video borders need to be
 *    filled at the same time.
 *
 * \return
 *
 * \param  border:
 *    Selects one of the four video borders to fill:
 *      0: disable filling on all four borders
 *      1: fill top    border
 *      2: fill bottom border
 *      3: fill left   border
 *      4: fill right  border
 *
 * \param  num_pixels:
 *    The thickness of the filled border area in pixel units.
 *
 * \param  fillColor:
 *    The color used to fill the border specified by 'border'.
 *    Different color can be used on different borders.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_FillVideoBorder (VIDEO_RPC_VO_FILTER_FILL_VIDEO_BORDER x) = VIDEO_RPC_VOUT_FUNC_BASE + 320 ;





/*!
 ************************************************************************
 * \brief
 *    This function is used to display picture in constant time,
 *    that is, VO display don't care PTS from picture object.
 *    This function only uses in video master mode.
 *
 * \return
 *
 * \param  enFastDisplay:
 *      0: disable fast display
 *      1:  enable fast display
 *
 * \param  count:
 *    the number of field times for every picture to display
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_SetFastDisplay (VIDEO_RPC_VO_FILTER_SET_FAST_DISPLAY x) = VIDEO_RPC_VOUT_FUNC_BASE + 330 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to enable video 3D mode detection.
 *    If enabled, specified vout filter will analyse received video sequence
 *    to decide if it's a side-by-side, top-and-bottom, or pure 2D video
 *    and inform VODMA and scaler to display in proper 2D or 3D mode.
 *
 * \return
 *
 * \param  enable:
 *     0->disble, 1->enable 3D mode detection
 *
 * \param  yuvFormat:
 *     source format, currently should be FMT_YUV420 or FMT_M_DOMAIN
 *
 * \param  fullWidth, FullHeight:
 *     original resolution of source video if source format is FMT_M_DOMAIN, ignored otherwise
 *
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_Enable3DModeDetect (VIDEO_RPC_VO_FILTER_ENABLE_3D_MODE_DETECT x) = VIDEO_RPC_VOUT_FUNC_BASE + 335 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to clear video, ie, memset video buffer as black
 *
 * \return
 *
 * \param
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ClearVideo (VIDEO_RPC_VO_FILTER_CLEAR_VIDEO x) = VIDEO_RPC_VOUT_FUNC_BASE + 340 ;



/**
 *  \fn  HRESULT  VIDEO_RPC_VO_FILTER_ToAgent_FlushVideoOut (long)
 *
 *  \brief
 *  This function copy current picture to last chunk of VBM to avoid blacking out the display due to re-configure VBM
 *
 *  \return
 *
 *  \param  instanceID
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_FlushVideoOut(long instanceID) = VIDEO_RPC_VOUT_FUNC_BASE + 350 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config vo freerun or sync to master
 * \return
 *
 * \param  enable:
 *    0: freerun, 1: sync to master
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ConfigSyncAV (VIDEO_RPC_VO_FILTER_Config_SyncAV x) = VIDEO_RPC_VOUT_FUNC_BASE + 360 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config freeze or melt(un-freeze) the video (video freeze on the screen, but decoding continues at the background)
 * \return
 *
 * \param  enable:
 *    0: melt, 1: freeze
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ConfigVoFreeze (VIDEO_RPC_VO_FILTER_Config_VoFreeze x) = VIDEO_RPC_VOUT_FUNC_BASE + 370 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config display delay between pts and stc (in miliseconds)
 * \return
 *
 * \param  delay:
 *    delay in miliseconds
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ConfigDisplayDelay (VIDEO_RPC_VO_FILTER_Config_DisplayDelay x) = VIDEO_RPC_VOUT_FUNC_BASE + 380 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to connect vo instance and vdec port
 * \return
 *
 * \param  instanceID
 * \param  nPort:
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ConnectVDec (VIDEO_RPC_VO_FILTER_ConnectVDec x) = VIDEO_RPC_VOUT_FUNC_BASE + 390 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config mastership
 * \return
 *
 * \param  useSTC:
 *    0: not use STC as lipsync clock source, 1: use STC as lipsync clock source (system master)
 * \param  lipsyncMaster:
 *    set lipsync master mode for NOT_USE_STC. (0:FIRSTCOMES, 1:ADEC_MASTER, 2:VDEC_MASTER)
 * \param  audioChannel:
 *    audio channel to keep sync with
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ConfigMastership (VIDEO_RPC_VO_FILTER_Config_Mastership x) = VIDEO_RPC_VOUT_FUNC_BASE + 395 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config Dual 3D mode on/off
 * \return
 *
 * \param  enable:
 *    0: on, 1: off
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_ConfigDual3D (VIDEO_RPC_VO_FILTER_Config_Dual3D x) = VIDEO_RPC_VOUT_FUNC_BASE + 400 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set video source type,
 *
 * \return
 *
 * \param  VIDEO_SOURCE_TYPE:
 *      0: Playback
 *      1: DTV
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_SetSourceType (VIDEO_RPC_VO_FILTER_SET_SOURCE_TYPE x) = VIDEO_RPC_VOUT_FUNC_BASE + 520 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to enable/disable VODMA clock for bandwidth saving
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  enable:
 *	  0->disable, 1->enable
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_VodmaEnable (VIDEO_RPC_VOUT_VODMA_ENABLE x)  = VIDEO_RPC_VOUT_FUNC_BASE + 500 ;


/*!
 ************************************************************************
 * \brief
 *    This function is used to calibrate vodma display framerate
 *
 * \return
 *
 * \param  enableForceFrameRate:
 *	  0->disable, 1->enable force framerate, regardless of double dvs and boundary check
 *
 * \param  ForceFrameRate:
 *	  force display framerate = ForceFrameRate (in 0.001 Hz).
 *
 * \param  enableDoubleDvs:
 *	  0->disable, 1->enable double dvs, multiply framerate for panel spec
 *
 * \param  DoubleDvsThreshold:
 *	  multiply framerate if framerate <= DoubleDvsThreshold (in 0.001 Hz).
 *
 * \param  enableHighBound:
 *	  0->disable, 1->enable high-bound check
 *
 * \param  HighBound:
 *	  set framerate = HighAdjust if framerate > HighBound (in 0.001 Hz).
 *
 * \param  HighAdjust:
 *	  adjust value for high-bound check
 *
 * \param  enableLowBound:
 *	  0->disable, 1->enable low-bound check
 *
 * \param  LowBound:
 *	  set framerate = LowAdjust if framerate < LowBound (in 0.001 Hz).
 *
 * \param  LowAdjust:
 *	  adjust value for low-bound check
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_VodmaFrameRateControl (VIDEO_RPC_VOUT_FRAMERATE_CONTROL_STRUCT x)  = VIDEO_RPC_VOUT_FUNC_BASE + 510 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to decimate video output size
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 *
 * \param  HorDecimate:
 *	  horizontal decimate ratio
 *
 * \param  VerDecimate:
 *	  vertical decimate ratio
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_VideoDecimate (VIDEO_RPC_VOUT_DECIMATE_STRUCT x)  = VIDEO_RPC_VOUT_FUNC_BASE + 530 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set aspect ratio which needs VO's help
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  ScalerARMode:
 *
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_SetScalerARMode (VIDEO_RPC_VOUT_SET_SCALER_AR_MODE x) = VIDEO_RPC_VOUT_FUNC_BASE + 540 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set aspect ratio which needs VO's help
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  customerX:
 *    crop customerX percent from left, in 0.01%. set 1250 means 12.5%
 * \param  customerY:
 *    crop customerY percent from top, in 0.01%. set 1250 means 12.5%
 * \param  customerW:
 *    crop customerW take customerW percent as width, in 0.01%. set 7500 means 75%
 * \param  customerH:
 *    crop customerH take customerH percent as height, in 0.01%. set 7500 means 75%
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigScalerARCustomerMode (VIDEO_RPC_VOUT_CONFIG_SCALER_AR_CUSTOMER_MODE x) = VIDEO_RPC_VOUT_FUNC_BASE + 545 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set vodma vflip
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  enable:
 *	  0->normal, 1->enable vflip
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigVodmaVFlip (VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE x) = VIDEO_RPC_VOUT_FUNC_BASE + 550 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set vodma zoom function
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  zoomRate:
 *	  0~100->overscan, 100~200->zoom
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigVodmaZoom (VIDEO_RPC_VOUT_VODMA_ZOOM_RATE x) = VIDEO_RPC_VOUT_FUNC_BASE + 560 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set vodma shift window to finetune after calculate zoom and aspect ratio
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  shift_h:
 *	  x = x + shift_h
 * \param  shift_v:
 *	  y = y + shift_y
 * \param  shift_w:
 *	  width = width + shift_w
 * \param  shift_l:
 *	  height = height + shift_l
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigVodmaPosFinetune (VIDEO_RPC_VOUT_VODMA_POS_FIUNTUNE x) = VIDEO_RPC_VOUT_FUNC_BASE + 570 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config vo do forceBG or not, could combined all type at once through "OR" operate
 *
 * \return
 *
 * \param  ForceBGType:
 *    VO_FORCEBG_TYPE_HIDECHANNEL(1) -> when hide channel,
 *    VO_FORCEBG_TYPE_SETVOINFO(2) -> when vodma set voinfo
 *    VO_FORCEBG_TYPE_DTVSPATUPDATE(4) -> when spatial update in DTV source
 *    VO_FORCEBG_TYPE_DTVRESETCLKGEN(8) -> when reset vodma clkgen in DTV source
 *    VO_FORCEBG_TYPE_FLUSHVIDEOOUT(16)-> when decoder flush video out
 * \param  enable:
 *	  0->disable, 1->enable.
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigVoForceBG (VIDEO_RPC_VOUT_FORCEBG_CTRL x) = VIDEO_RPC_VOUT_FUNC_BASE + 580 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config vodma scale up function
 *
 * \return
 *
 * \param  enable:
 *    0->disable, 1->enable.
 * \param  tgtw:
 *	  target output width
 * \param  tgth:
 *	  target output height
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigVoScaleUp (VIDEO_RPC_VOUT_CONFIG_SCALEUP x) = VIDEO_RPC_VOUT_FUNC_BASE + 600 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to set iv_src of vodma vsync gen
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  iv_src:
 *      0: VS generated by the counter
 *      1: Main IVS
 *      2: Main DVS
 *      3: HDMI 3D DMA VS
 *      4: manual vs
 *      5: hdmitx_vsync_pulse
 *      6: tve_vsync_pulse_p
 *      7: tve_vsync_pulse_i
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_FILTER_ToAgent_VODMA_ConfigVsyncGenIvSrc (VIDEO_RPC_VOUT_VODMA_CONFIG_VSGEN_IV_SRC x) = VIDEO_RPC_VOUT_FUNC_BASE + 650 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to set vsc source and port to vodma
 *
 * \return
 *
 * \param  vsc_source:
 *    0->VO_VSC_SRC_VDEC, 1->VO_VSC_SRC_JPEG.
 * \param  vsc_port:
 *    vsc connect port
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_VSCINPUTTYPE_TO_VODMA (VIDEO_RPC_VOUT_VSCINPUTTYPE x) = VIDEO_RPC_VOUT_FUNC_BASE + 666 ;




/**
 * \fn  HRESULT  VIDEO_RPC_ToAgent_SetScalerVBICCBuf (long)
 *
 * \brief Set the address of the Scaler_VBI_CC_Buf
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param vbiccbufAddr:
 *    The physical DRAM address of the Scaler_VBI_CC_Buf.
 */
  HRESULT VIDEO_RPC_ToAgent_SetScalerVBICCBuf (long vbiccbufAddr) = VIDEO_RPC_VOUT_FUNC_BASE + 680;



/*!
 ************************************************************************
 * \brief
 *    This function is used to transform current display picture form block index to sequential address
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 *
 * \param  destAddrY:
 *	  the physical destination address for luma
 *
 * \param  destAddrC:
 *	  the physical destination address for chroma
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_CurrentBlockToSequential (VIDEO_RPC_VOUT_CURRENT_BLK_TO_SEQ x)  = VIDEO_RPC_VOUT_FUNC_BASE + 690 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to specify 3D format
 *
 * \return
 *
 * \param  mode_3d:
 *	  0->2d mode, 1->side-by-side(half), 2->top-and-bottom, 3->frame packing
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Set_3D_Mode (VIDEO_RPC_VOUT_SET_3D_MODE x)  = VIDEO_RPC_VOUT_FUNC_BASE + 700 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to configure vodma 3d output format
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 *
 * \param  mode_3d:
 *    0->2d mode, 1->side-by-side(half), 2->top-and-bottom, 3->frame packing
 *
 * \param  output_mode:
 *	  0->output as 2d, 1->output LR frame sequence
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Set_3D_Output_Mode (VIDEO_RPC_VOUT_SET_3D_OUTPUT_MODE x)  = VIDEO_RPC_VOUT_FUNC_BASE + 705 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to force 2d
 *
 * \return
 *
 * \param  force2d_mode:
 *	  0->disable(3d), 1->force left, 2->force right
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Force2D (VIDEO_RPC_VOUT_FORCE2D_MODE x)  = VIDEO_RPC_VOUT_FUNC_BASE + 710 ;



/** frank
 ************************************************************************
 * \fn  HRESULT  VIDEO_RPC_ToAgent_Set2Dcvt3DVOConfig (void)
 * \brief
 *    This function is used to config VO parameter when 2D cvt 3D flow
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param the config parameter data set by scaler sub source
 *
 ************************************************************************
 */
  HRESULT VIDEO_RPC_ToAgent_Set2Dcvt3DVOConfig(VO_2D3D_CONFIG x) = VIDEO_RPC_VOUT_FUNC_BASE + 720;



/*!
 ************************************************************************
 * \brief
 *    This function is used to turn on HDMI 3D VO path
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  width:
 *	  video active wdith
 * \param  height:
 *	  video active height
 * \param  progressive:
 *	  0: interlace
 *	  1: progressive video
 * \param  framerate:
 *	  framerate in 0.001Hz. Ex: 29.97 FPS, fraamerate = 29970
 * \param chroma_fmt:
 *    0->YUV420 ,
 *	  1->YUV422 ,
 *	  2->YUV444 ,
 *	  3->ARGB8888 ,
 *	  4->RGB888 ,
 *	  5->RGB565 ,
 *	  6->YUV411
 * \param data_bit_width:
 *    8 or 10 bits
 * \param hw_auto_mode:
 *    0: fw_mode, dma seq address is auto load form ST_ADR Register
 *	  1: hw_auto_mode, HW auto mode, use 4 start memory(L1_ST_ADR, R1_ST_ADR, L2_ST_ADR, R2_ST_ADR)
 * \param l1_st_adr:
 *    start address of l1
 * \param r1_st_adr:
 *    start address of r1
 * \param l2_st_adr:
 *    start address of l2
 * \param r2_st_adr:
 *    start address of r2
 * \param quincunx_en:
 *    quincunx_en
 * \param quincunx_mode_fw:
 *    quincunx_mode
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigHDMI_3D (VIDEO_RPC_VOUT_CONFIG_HDMI_3D x)  = VIDEO_RPC_VOUT_FUNC_BASE + 730 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to force 3D to 2D for HDMI 3D VO path
 *
 * \return
 *
 * \param  videoPlane:
 *    0->V1, 1->V2.
 * \param  force2d:
 *	  0->3d mode, 1->force 3D to 2D.
 * \param  l_flag:
 *	  0->right, 1->left.
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Force_HDMI_2D (VIDEO_RPC_VOUT_FORCE_HDMI_2D x)  = VIDEO_RPC_VOUT_FUNC_BASE + 740 ;



/** jiunyu
 ************************************************************************
 * \fn  HRESULT  VIDEO_RPC_ToAgent_SetVOCaptureConfig (void)
 * \brief
 *    This function is used to config VO parameter when VO capture flow
 *
 * \return 'S_OK' if success and 'E_FAIL' otherwise
 *
 * \param the config parameter data set by scaler main source
 *
 ************************************************************************
 */
  HRESULT VIDEO_RPC_ToAgent_SetVOCaptureConfig(VO_CAPTURE_CONFIG x) = VIDEO_RPC_VOUT_FUNC_BASE + 750;



/*!
 ************************************************************************
 * \brief
 *    This function is used to specify OSD 4K2K format
 *
 * \return
 *
 * \param  vo_mode:
 *	  0: native mode,
 *	  1: photo mode, 2Kx1K x4 sequential output (Top-Left, Top-Right, Bottom-Left, Bottom-Right)
 *	  2: video mode, PCtool-converted MVC-like 4Kx1K video file
 * \param  osd_mode:
 *	  0: native mode,
 *	  1: corner mode, show 2k osd in specific area in 4k panel(Top-Left, Top-Right, Bottom-Left, Bottom-Right)
 *	  2: scaleup mode, 2k osd scale up to 4k
 * \param  srcWin:
 *    source window in Canvas
 * \param  dispWin:
 *    display window in Mixer
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Set_OSD_4K2K_Mode (VIDEO_RPC_VOUT_SET_OSD_4K2K_MODE x)  = VIDEO_RPC_VOUT_FUNC_BASE + 800 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to assign 4K2K sequence
 *
 * \return
 *
 * \param  enable:
 *     enable sequence control or not,
 *     0->sequence switch automatically, 1->specify a sequence number
 * \param  sequence:
 *     assigned sequence number
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_4K2K_Sequence_Control (VIDEO_RPC_VOUT_4K2K_SEQUENCE_CONTORL x)  = VIDEO_RPC_VOUT_FUNC_BASE + 810 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set gdma in 3d mode
 * \return
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 * \param  enable3D:
 *    enable 3d mode
 * \param  panel_type:
 *    0: PR, 1:SG
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigGDMA3D (VIDEO_RPC_VOUT_CONFIG_3D_STRUCT x) = VIDEO_RPC_VOUT_FUNC_BASE + 900 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set gdma in 3d mode
 * \return
 *
 * \param  plane:
 *    which plane  (OSD/SUB1/SUB2)
 * \param  closeToViewer:
 *    0: close to viewer, 1: away from viewer
 * \param  offset:
 *    pixel number to offset
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigGDMA3DOffset (VIDEO_RPC_VOUT_CONFIG_3D_OFFSET_STRUCT x) = VIDEO_RPC_VOUT_FUNC_BASE + 910 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to config gdma vflip
 * \return
 *
 * \param  enable:
 *    0: disable, 1: enable v-flip
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_ConfigGDMAVFlip (u_char enable) = VIDEO_RPC_VOUT_FUNC_BASE + 920 ;





/*!
 ************************************************************************
 * \brief
 *    This function is used to force VO chroma output 422 format
 * \return
 *
 * \param  enable:
 *    0: disable, 1: enable force VO output 422
 ************************************************************************
 */
HRESULT VIDEO_RPC_VOUT_ToAgent_Force_VO_Chroma_422 (u_char enable) = VIDEO_RPC_VOUT_FUNC_BASE + 930 ;


/*!
 ************************************************************************
 * \brief
 *    This function is used to set app type,
 *
 * \return
 *
 * \param  VIDEO_APP_TYPE:
 *      0: None
 *      1: Netflix
 *      2: Youtube
 ************************************************************************
*/
HRESULT VIDEO_RPC_VO_FILTER_ToAgent_SetAppType (VIDEO_RPC_VO_FILTER_SET_APP_TYPE x) = VIDEO_RPC_VOUT_FUNC_BASE + 940 ;




/**
 *  \defgroup    Sub-picture Decoder APIs
 *  APIs for Sub-picture Decoder functionalities .
 *
 *  \author Shiyan Pan
 *  @{
 */


/****************************
 * SUB-PICTURE DECODER APIs *
 ****************************/

/* Despite the fact that the sub-picture RLE decoding, color-map lookup
   and blending to video are all done in the VideoOut hardware, the system
   software team still prefers to reserve a 'Sub-picture Decoder'.
   For this reason the video firmware will have to implement a fake
   sub-picture decoder having a different filter handler than the Video
   Output Filter to make it 'look like' there is an separate sub-picture
   decoder filter just to make the system-video software architecture
   consistant, while in fact the 'sub-picture decoder' filter on the video
   firmware side is nothing but an empty shell whose only duty is to direct
   the API calls and other in-band commands to the Video Output Filther
   it is 'connected' to. Therefore, in the following descriptions of the
   'sub-picture decoder' filter, although the prefix of the functions are
   changed to 'SUBPIC_DEC', in the description we still use
   'Video Output Filter' to address the real functionality that will be
   carried out by the VideoOut firmware.
*/

/*!
 ************************************************************************
 * \brief
 *    This function is used to enable sub-picture overlay on video being
 *    presented on the V1 or V2 plane. This function must be called to
 *    enable the sub-picture overlay every time the Video Output Filter
 *    is selected to be displayed on the V1 or V2 plane (by calling the
 *    VO_FILTER_SelectDisplayPlane() function). Because the VO hardware
 *    has only one sub-picture plane that can be overlaid on either V1 or
 *    V2 but not both, calling this function will disable any other Video
 *    Output Filter whose sub-picture overlay was enabled earlier. If the
 *    Video Output Filter is not being displayed on either the V1 plane
 *    or the V2 plane, calling this function will not result in anything
 *    and the function will return failure.
 *
 * \return
 *     0: success
 *    -1: the Video Output Filter bound to this Sub-picture Decoder
 *        Filter is not being displayed on either the V1 plane or the
 *        V2 plane.
 *
 * \param  alwaysOnTop:
 *    If true, the sub-picture will always be overlaid on top of all
 *    video display (i.e., the sub-picture will be blended into the mixer
 *    window after both the V1 and the V2 video planes have been blended
 *    into the mixer window). If false, then in the case where the
 *    sub-picture is being overlaid on the V1 plane with some portion
 *    overlapping the V2 plane, then the overlapping portion of the sub-
 *    picture will be invisible (i.e., obscured by the video content of
 *    the V2 plane in the overlapping area).
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_SUBPIC_DEC_ToAgent_EnableSubPicture (VIDEO_RPC_SUBPIC_DEC_ENABLE_SUBPIC x) = VIDEO_RPC_SPDEC_FUNC_BASE + 10 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to show the sub-picture overlay of the
 *    Video Output Filter
 * \return
 *
 * \param
 ************************************************************************
 */
HRESULT VIDEO_RPC_SUBPIC_DEC_ToAgent_ShowSubPicture (long instanceID) = VIDEO_RPC_SPDEC_FUNC_BASE + 20 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to hide the sub-picture overlay of the
 *    Video Output Filter
 * \return
 *
 * \param
 ************************************************************************
 */
HRESULT VIDEO_RPC_SUBPIC_DEC_ToAgent_HideSubPicture (long instanceID) = VIDEO_RPC_SPDEC_FUNC_BASE + 30 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to configurate sub-picture stream type and set
 *    the full window resolution on the original sub-picture coordinates
 * \return
 *
 * \param fullWidth:
 *    Width  of sub-picture full screen.
 *
 * \param fullHeight:
 *    Height of sub-picture full screen.
 *
 * \param streamType:
 *    Type of sub-picture stream.
 ************************************************************************
 */
HRESULT VIDEO_RPC_SUBPIC_DEC_ToAgent_Configure (VIDEO_RPC_SUBPIC_DEC_CONFIGURE x) = VIDEO_RPC_SPDEC_FUNC_BASE + 40 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to tell the decoder which pages to decode
 * \return
 *
 * \param page_id_composition
 *    composition page id
 *
 * \param page_id_ancillary
 *    ancillary page id
 ************************************************************************
 */
HRESULT VIDEO_RPC_SUBPIC_DEC_ToAgent_Page (VIDEO_RPC_SUBPIC_DEC_PAGE x) = VIDEO_RPC_SPDEC_FUNC_BASE + 50 ;

/**
 *  \defgroup Video Input(TVD) APIs
 *  APIs for the generic and filter-specific Video Input and TVD functionalities .
 *
 *  \author Ge Gao
 *  @{
 */


/*************************/
/* Video Input(TVD) APIs */
/*************************/

/* General description */

/*
The Video Input API is actually only applied to TV decoder. It applies directly
to internal TV decoder. To insure a safe and reliable setting of TVD, all the
TVD registers settings are first stored somewhere(in DMEM). When Vsync comes,
Vsync ISR will fetch these settings and do the actual filling. All other
commands that control Video Input will be issued by  Encoder filter. They
are not exposed to system.
*/

/*************************************
 * GENERAL VI/TVD CONFIGURATION APIs *
 *************************************/
/*!
 ************************************************************************
 * \brief
 *    This function is used to select TV decoder input source type.
 *    It selects among Composite, S-Video, Component source and
 *    SCART format.
 *
 * \return
 *
 * \param video_fmt:
 *    Video format can be NTSC, NTSC_443, PAL_I, PAL_M, PAL_CN, or SECAM.
 *		System should be aware of which video format is being reveived,
 *		and let the TVD know the current settings.
 *
 * \param input_fmt:
 *    Input format can be Composite, S-Video, Component, or SCART.
 *		System should translate consumer's request into corresponding
 *		API and let the TVD know the current settings.
 *
 * \param ycsep_mode:
 *    Input format can be Composite, S-Video, Component, or SCART.
 *		System should translate consumer's request into corresponding
 *
 * \param default_ycsep:
 *    If system prefer using default value for YC separation.
 *		A 1-bit value to enable/disable default.
 *    If enable default, the YC separation mode will be set based on
 *    the current video format.(default=TRUE)
 *
 * \param mv_workaround_en:
 *    A 1-bit value to enable/disable the work-around for MacroVision,
 *    which would enable/disable Auto-positioning.(default=FALSE)
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_TVD_ToAgent_TVD_Configure (VIDEO_RPC_TVD_CONFIG x) = VIDEO_RPC_VIN_FUNC_BASE + 10 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to select TV decoder input source type.
 *    It selects among Composite, S-Video, Component source and
 *    SCART format.
 *
 * \return
 *
 *
 * \param format:
 *    Input format can be Composite, S-Video, Component, or SCART.
 *		System should translate consumer's request into corresponding
 *		API and let the TVD know the current settings.
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_TVD_ToAgent_Select_INFMT (VIDEO_RPC_TVD_INPUT_FORMAT x) = VIDEO_RPC_VIN_FUNC_BASE + 20 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to set Y/C separation mode.
 *
 * \return
 *
 *
 * \param mode:
 *    TVD supports 3 kinds of mode for Y/C separation.
 *		Three of modes are "1D/2D adaptive", "3D adaptive", and "3D fixed".
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_TVD_ToAgent_YC_Separation (VIDEO_RPC_TVD_YC_SEP_MODE x) = VIDEO_RPC_VIN_FUNC_BASE + 30 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to enable/disable VBI slicing.
 *
 * \return
 *
 *
 * \param VBI_slicer_en:
 *    A 1-bit value to enable/disable VBI slicing.
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_TVD_ToAgent_VBI_Ctrl (VIDEO_RPC_TVD_VBI_CTRL x) = VIDEO_RPC_VIN_FUNC_BASE + 40 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to set TV decoder output feature.
 *    TV decoder might do some post-processing to the signal it received.
 *
 * \return
 *
 *
 * \param value:
 *    This is a 8-bit value. It controls adjustable gain to the
 *    luma output path.(default:0x80)
 */
HRESULT VIDEO_RPC_TVD_ToAgent_Adjust_Contrast(VIDEO_RPC_TVD_ADJ_CONTRAST x)  = VIDEO_RPC_VIN_FUNC_BASE + 50 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to set TV decoder output feature.
 *    TV decoder might do some post-processing to the signal it received.
 *
 * \return
 *
 *
 * \param value:
 *    This is a 8-bit value. These bits control the adjustable
 *		brightness level to the luma output path.
 *		This value is offset by ¡V128, i.e., a value of 128
 *		implies a brightness of level 0, and a value of 0 implies
 *		a brightness level of ¡V128.(default:0x80)
 */
HRESULT VIDEO_RPC_TVD_ToAgent_Adjust_Brightness(VIDEO_RPC_TVD_ADJ_BRIGHTNESS x) = VIDEO_RPC_VIN_FUNC_BASE + 60 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to set TV decoder output feature.
 *    TV decoder might do some post-processing to the signal it received.
 *
 * \return
 *
 *
 * \param value:
 *    This is a 8-bit value. It adjusts color saturation.(default:0x80)
 */
HRESULT VIDEO_RPC_TVD_ToAgent_Adjust_Saturation(VIDEO_RPC_TVD_ADJ_SATURATION x) = VIDEO_RPC_VIN_FUNC_BASE + 70 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to set TV decoder output feature.
 *    TV decoder might do some post-processing to the signal it received.
 *
 * \return
 *
 *
 * \param value:
 *    This is a 8-bit value. It adjusts Hue.(default:0x00)
 *    This 2's complement number adjusts the hue phase offset.
 */
HRESULT VIDEO_RPC_TVD_ToAgent_Adjust_Hue(VIDEO_RPC_TVD_ADJ_HUE x) = VIDEO_RPC_VIN_FUNC_BASE + 80 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to set TV decoder output feature.
 *    TV decoder might do some post-processing to the signal it received.
 *
 * \return
 *
 * \param mode:
 *    This is a 2-bit value. It controls the blue-screen mode.
 *		0x00:Disable; 0x01: Enabled: 0x02: Auto.(default:0x02)
 */
HRESULT VIDEO_RPC_TVD_ToAgent_Blue_Screen_Ctrl(VIDEO_RPC_TVD_BLUE_MODE x) = VIDEO_RPC_VIN_FUNC_BASE + 90 ;

/*!
 ************************************************************************
 * \brief
 *		If System has set TVD to Auto detect which video format is being reveived,
 *		then this fuction could be called to Query which video format is detected.
 *
 * \return
 *
 *
 * \param video_fmt:
 *    Video format can be NTSC, NTSC_443, PAL_I, PAL_M, PAL_CN, or SECAM.
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_TVD_ToAgent_Query_VIDEO_FORMAT (VIDEO_RPC_TVD_VIDEO_FORMAT x) = VIDEO_RPC_VIN_FUNC_BASE + 100 ;


/*!
 **************************************************************************
 * \brief
 *    This API is used for setting the coefficients of VIN Scaling.
 * \return
 *
 * \param y_32th_coef:
 *    A 16-bit unsigned value, specify the 32th coefficient for luma.
 *    0x1000 means 1 times.
 * \param c_16th_coef:
 *    A 16-bit unsigned value, specify the 16th coefficient for chroma.
 *    0x1000 means 1 times.
 **************************************************************************
 */
HRESULT VIDEO_RPC_VIN_ToAgent_Adjust_Scale_Coef(VIDEO_RPC_VIN_ADJ_SCALE_COEF x) = VIDEO_RPC_VIN_FUNC_BASE + 110 ;


/*!
 ************************************************************************
 * \brief
 *  This API is used to notify Vin the channel is going to be changed.
 *
 *
 * \return
 *
 *
 ************************************************************************
 */
CHANNEL_RES VIDEO_RPC_TVD_ToAgent_ChangeChannel_Start(long x) = VIDEO_RPC_VIN_FUNC_BASE + 120 ;


/**********************************************************************/
/**
 *  \defgroup JPEG Decoder Untility APIs
 *  APIs for the generic and filter-specific JPEG Decoder untilities .
 *
 *  \author
 *  @{
 */

/*!
 ************************************************************************
 * \brief
 *    This function is used to decode, scale and rotal a JPEG picture
 *
 * \return
 *
 * \param
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_JPEG_ToAgent_DEC (VIDEO_RPC_JPEG_DEC x) = VIDEO_RPC_JPEGDEC_FUNC_BASE + 10 ;
HRESULT VIDEO_RPC_JPEG_ToAgent_DEC_BATCH (VIDEO_RPC_JPEG_DEC_BATCH x) = VIDEO_RPC_JPEGDEC_FUNC_BASE + 11 ;

/*!
 ************************************************************************
 * \brief
 *    This function is used to transition effect
 *
 * \return
 *
 * \param
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_TRANSITION_ToAgent_Start (VIDEO_RPC_TRANSITION_EFFECT x) = VIDEO_RPC_JPEGDEC_FUNC_BASE + 20 ;

/**
 *  \defgroup Pseudo Filter APIs
 *  For debug use, providing pseudo filters such as pseudo-vin/out/mux.
 *
 *  \author
 *  @{
 */

/*!
 ************************************************************************
 * \brief
 *    This function is used to configure size and background color/picture
 *    for mixer filter
 *
 * \return
 *
 * \param  width:
 *    The width of mixer
 *
 * \param  height:
 *    The height of mixer
 *
 * \param  EnablebgPicture:
 *    use bgColor and skip bgPicture's parameters if it is 0
 *
 * \param  bgColor:
 *    The color used to fill the background
 *
 * \param  colorFmt:
 *    Color format of the background (support RGB or YUV)
 *
 * \param  storageMode:
 *    sequential mode or block mode
 *
 * \param  colorFmt:
 *    Color format of the background
 *
 * \param  srcWin:
 *    source window of background picture
 *
 * \param  dispWin:
 *    display window of background picture on Mixer
 *
 * \param  startX:
 *    The starting x on the source image coordinate
 *    Must be multiple of 8 for block mode and even for sequential mode.
 *
 * \param  startY:
 *    The starting y on the source image coordinate.
 *
 * \param  imgPitch:
 *    The pitch of the 2-D image (must be multiple of 256 for block mode and 16 for sequential mode) and greater
 *    than or equal to startX + OSD window width.
 *
 * \param  pImage:
 *    Pointer to the 2-D image data. Must be page aligned for block mode and 16 byte aligned for sequential mode.
 *
 * startX[i], startY[i], imgPitch[i], pImage[i]
 * i = 0: source image.
          For Video Format, it is Luma
 * i = 1: For Video Format, it is Chroma
 ************************************************************************
 */
HRESULT VIDEO_RPC_MIXER_FILTER_ToAgent_Configure (VIDEO_RPC_MIXER_FILTER_CONFIGURE x) = VIDEO_RPC_MIXER_FUNC_BASE + 10 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to configure window on mixer
 *
 * \return
 *
 * \param  count:
 *    window counts to be configured
 *
 * \param  winID:
 *    window ID (pin ID) to be configured on mixer, valid in [0, 7]
 *    winID is pinID bound to Mixer component
 *
 * \param  order:
 *    order on Mixer, valid in [0, 7]
 *    -1 if we will hide this window
 *
 * \param  alpha:
 *    Constant alpha value of the window (ONLY for Jupiter), valid in [0, 255]
 *
 * \param  dispWin:
 *    display window on Mixer
 *
 * \param  clipSrcWin:
 *    clip source video, if width is 0 then we will clip full source video
 *
 ************************************************************************
 */

HRESULT VIDEO_RPC_MIXER_FILTER_ToAgent_ConfigureWindow (VIDEO_RPC_MIXER_FILTER_CONFIGURE_WIN x) = VIDEO_RPC_MIXER_FUNC_BASE + 20 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to set master window ID
 *
 * \return
 *
 * \param  winID:
 *    window ID (pin ID) to be set as master on mixer, valid in [0, 7]
 *    winID is pinID bound to Mixer component
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_MIXER_FILTER_ToAgent_SetMasterWindow (VIDEO_RPC_MIXER_FILTER_SET_MASTER_WIN x)  = VIDEO_RPC_MIXER_FUNC_BASE + 30 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to decode one motion jpeg frame and send to Mixer with mixerWinID to display
 *
 * \return
 *
 * \param  mixerWinID:
 *    winID on Mixer to display
 *    We will call a gobal function to send this frame to Mixer based on mixerWinID
 *    mixerWinID is pinID bound to Mixer component
 *
 * \param  base:
 *    The base address of bitstream
 *
 * \param  size:
 *    The size of bitstream
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_MIXER_ToAgent_PlayOneMotionJpegFrame (VIDEO_RPC_MIXER_PLAY_ONE_MOTION_JPEG_FRAME x) = VIDEO_RPC_MIXER_FUNC_BASE + 40 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to capture Mixer`s picture
 *
 * \return
 *
* \param  colorFmt:
 *    color format after format conversion (ONLY big/little endian for RGB565,RGBA8888,ARGB8888)
 * \param  pImage:
 *    destination address
 * \param  imgPitch:
 *    the pitch of the destination
 * \param  startX:
 *    starting x on the destination coordinate to place image
 * \param  startY:
 *    starting y on the destination coordinate to palce image
 * \param  width:
 *    image width after format conversion
 * \param  height:
 *    image height after format conversion
 * \param  pStretchBuf:
 *    buffer for stretch before format conversion
 * \param  stretchBufSize:
 *    size of stretch buffer
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_MIXER_FILTER_ToAgent_Capture (VIDEO_RPC_MIXER_FILTER_CAPTURE x)  = VIDEO_RPC_MIXER_FUNC_BASE + 50 ;




/**
 *  \defgroup Direct VO APIs
 *  VODMA read the specified video frame buffer then output to the scaler IMD domain.
 *
 *  \author yc_hsiung
 *  @{
 */

/*!
 ************************************************************************
 * \brief
 *    This function is used to open Direct VO function
 *
 * \return
 *
 * \param  version_num:
 *    check if the System/Video SW/FW version compatible
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_DIRECT_VO_ToAgent_open (VIDEO_RPC_DIRECT_VO_OPEN x) = VIDEO_RPC_DIRECT_VO_FUNC_BASE + 10 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to start the Direct VO function
 *
 * \return
 *
 * \param  shmPhyAddr:
 *    assign the share memory physical address for Direct VO function control
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_DIRECT_VO_ToAgent_run (VIDEO_RPC_DIRECT_VO_RUN x) = VIDEO_RPC_DIRECT_VO_FUNC_BASE + 20 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to stop the Direct VO function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_DIRECT_VO_ToAgent_stop (VIDEO_RPC_DIRECT_VO_STOP x) = VIDEO_RPC_DIRECT_VO_FUNC_BASE + 30 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to stop the Direct VO function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_DIRECT_VO_ToAgent_flush (VIDEO_RPC_DIRECT_VO_FLUSH x) = VIDEO_RPC_DIRECT_VO_FUNC_BASE + 40 ;



/**
 *  \defgroup Dolby Vision APIs
 *  Dolby Vision HDMI/Normal mode control
 *
 *  \author yc_hsiung
 *  @{
 */

/*!
 ************************************************************************
 * \brief
 *    This function is used to control Dolby Vision HDMI detect enable/disable
 *
 * \return
 *
 * \param  detect_en:
 *    disable/enable Dolby Vision HDMI source detect
 * \param  display_en:
 *    disable/enable auto video display control
 * \param  bufAddr_md[]:
 *    metadata capture buffer start address
 * \param  bufAddr_video[]:
 *    video capture buffer start address
 * \param  bufAddr_graph[]:
 *    graphic capture buffer start address
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_DOLBY_VISION_HDMI_Set_Detect_Enable (VIDEO_RPC_DOLBY_VISION_HDMI_SET_DETECT_ENABLE x) = VIDEO_RPC_DOLBY_VISION_FUNC_BASE + 10 ;



/*!
 ************************************************************************
 * \brief
 *    This function is used to get the Dolby Vision HDMI source detect result
 *
 * \return detect_ret
 *	report if current HDMI source is Dolby Vision content
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_DOLBY_VISION_HDMI_Get_Detect_Info (VIDEO_RPC_DOLBY_VISION_HDMI_GET_DETECT_INFO x) = VIDEO_RPC_DOLBY_VISION_FUNC_BASE + 20 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to enable/disable video through Dolby Vision control path
 *
 * \return
 *
 * \param  display_en:
 *    enable/disable play HDMI video through Dolby Vision HDR control path
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_DOLBY_VISION_HDMI_Set_Display_Enable (VIDEO_RPC_DOLBY_VISION_HDMI_SET_DISPLAY_ENABLE x) = VIDEO_RPC_DOLBY_VISION_FUNC_BASE + 30 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to get parameter from KCPU to VCPU
 *
 * \return
 *
 * \param  reserve0:
 *    no use
 * \param  reserve1:
 *    no use
 * \param  reserve2:
 *    no use
 * \param  reserve3:
 *    no use
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_ToAgent_K2VParameter (VIDEO_RPC_K2V_PARAM x) = VIDEO_RPC_DOLBY_VISION_FUNC_BASE + 40 ;


/*!
 ************************************************************************
 * \brief
 *    This function is used to vo photo open function
 *
 * \return
 *
 ************************************************************************
 */
VIDEO_RPC_DEC_PV_RESULT VIDEO_RPC_VO_PHOTO_ToAgent_Open (VIDEO_RPC_VO_PHOTO_OPEN_T x) = VIDEO_RPC_VO_PHOTO_FUNC_BASE + 10 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to vo photo Config function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_PHOTO_ToAgent_Config (VIDEO_RPC_VO_PHOTO_CONFIG_T x) = VIDEO_RPC_VO_PHOTO_FUNC_BASE + 20 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to vo photo DisplayPicture function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_PHOTO_ToAgent_DisplayPicture (VIDEO_RPC_VO_DISPLAYPICTURE_T x) = VIDEO_RPC_VO_PHOTO_FUNC_BASE + 30 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to vo photo RedrawPicture function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_PHOTO_ToAgent_RedrawPicture (unsigned int ch) = VIDEO_RPC_VO_PHOTO_FUNC_BASE + 40 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to vo photo Close function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_PHOTO_ToAgent_Close (unsigned int ch) = VIDEO_RPC_VO_PHOTO_FUNC_BASE + 50 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to vo photo Connect function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_PHOTO_ToAgent_Connect () = VIDEO_RPC_VO_PHOTO_FUNC_BASE + 60 ;




/*!
 ************************************************************************
 * \brief
 *    This function is used to vo photo GetDeviceCapability function
 *
 * \return
 *
 ************************************************************************
 */
HRESULT VIDEO_RPC_VO_PHOTO_ToAgent_GetDeviceCapability (VIDEO_RPC_VO_GETDEVICECAPABILITY_T x) = VIDEO_RPC_VO_PHOTO_FUNC_BASE + 70 ;



  } = 0;
} = 100;
