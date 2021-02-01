.insert <RPCBaseDS.h>
.insert <VideoRPCBaseDS.h>

/*---------------------------------------------------------------------------*/
/*    APIs on VP Agent Side                          */
/*                                                                           */
/*---------------------------------------------------------------------------*/

struct VIDEO_RPC_SUBPIC_INFO
{
    enum ENUM_VIDEO_SUBPIC_INFO_TYPE  infoType;
    u_char    pixel_depth ;
    u_char    st_mode ;
    u_char    last_in_page ;
    u_char    buf_idx ;

    u_short   start_x ;
    u_short   start_y ;
    u_short   width ;
    u_short   height ;
    u_short   pitch ;
    u_int     pixel_addr ;
    u_int     pixel_addr_end ;
    u_int     CLUT[256] ;

    u_short   video_width ; /* fullWidth and fullHeight for BD subtitle */
    u_short   video_height ;
    uint64_t  sPTS ;
    uint64_t  ePTS ;

    u_short   dst_x ;
    u_short   dst_y ;
    u_short   dst_width ;
    u_short   dst_height ;

    u_char    valid ;
};


struct VIDEO_RPC_ENC_ELEM_GEN_INFO
{
    enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE  infoType;
    u_char    videoInputSource;
    u_char    encoderType;
    u_char    TVSystemFormat;
    u_char    videoRCMode;
    int       horizontalResolusion;
    u_int     video_STD_buffer_size;
    u_int     init_STD_buffer_fullness;
    u_int     videoBitRate;
    u_char    gop_M;
    u_char    gop_N;
    u_char    numOfGOPsPerVOBU;
};


struct VIDEO_RPC_ENC_ELEM_FRAME_INFO
{
    enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE  infoType;
    u_int     pictureNumber;
    u_char    pictureType;
    u_char    topFieldFirst;
    u_char    numOfField;
    u_char    newScene;
    u_int     PTShigh;
    u_int     PTSlow;
    u_int     DTShigh;
    u_int     DTSlow;
    u_int     VBIData;
    u_int     VBVfullness;
    u_char    resumedVideoFrame;
    u_char    newVOBUStart;
    u_char    KeyFrame;
    u_char    AGCDetection;
    u_int     CCData;
    u_int     CCStatus;
    int       frameSize;
};




struct VIDEO_RPC_ENDOFSTREAM
{
    long      SP_instanceID;
};


struct VIDEO_RPC_DEC_JPEG_INFO
{
    long instanceID;
    long destWidth;
    long destHeight;
    long eventID;
    long reserved2;
    long reserved3;
};


struct VIDEO_RPC_DEC_JPEG_CTRL
{
    long decodedWidth;
    long decodedHeight;

    long bitstreamEnd;
    long cancel;
    long status;                /* please reference enum IMG_STATUS */

    long orgJpegWidth;
    long orgJpegHeight;
    long croppedJpegX;
    long croppedJpegY;
    long croppedJpegWidth;
    long croppedJpegHeight;

    enum VIDEO_JPEG_ROTATION orientation;
    long percentage;  /* 0~256 */
    long reserved3;           /* bit0 is 1 represent thumbnail picture if decode mode is thumbnail first, bit1 is 1 represent pic is 3D picture */

    long JPEG_CTRL;
    long BITMAP_CTRL;
    long TIFF_CTRL;
    long GIF_CTRL;
    long PNG_CTRL;
    long Format1_CTRL;
    long Format2_CTRL;
    long Format3_CTRL;
    long bitstreamStart;      /* system will set bitstreamStart for video firwmare to update read pointer if bistream has streamed */
    long outInstanceID;       /* send picture to VideoOut directly if decode mode is thumbnail first and outInstanceID is nonzero */
    enum VIDEO_IMG_TYPE imgType ;   /* image format */
    long pScratchBase ;     /* address of scratch memroy for decoder */
    long scratchSize ;      /* size    of scratch memroy (default is 2MBs) */
    long WEBP_CTRL;
    long PSEUDOIMG_CTRL;
};


struct VIDEO_RPC_ENC_VBID_WSS_INFO
{
    enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE  infoType;
    enum ENUM_TVD_VIDEO_FORMAT video_format;
    u_int flg_no_signal;
    u_int copy_protected;
    enum VO_VBI_ASPECT_RATIO vbi_aspect_ratio;
};


struct VIDEO_RPC_ENC_PAUSE_INFO
{
    enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE  infoType;
    u_int   pausedPTSHigh;
    u_int   pausedPTSLow;
    u_int   pausedDTSHigh;
    u_int   pausedDTSLow;
    u_int   resumedPTSHigh;
    u_int   resumedPTSLow;
    u_int   resumedDTSHigh;
    u_int   resumedDTSLow;
    u_char  pictureType;
};

struct VIDEO_RPC_ENC_AUTOPAUSE_INFO
{
    enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE  infoType;
    u_char  isFinish;
};

struct VIDEO_RPC_DEC_ERROR_INFO
{
   long instanceID ;
   long errCode ;
} ;

struct VIDEO_RPC_ENC_AUTOPAUSE
{
   long instanceID;
   u_char isFinish;
};

struct VIDEO_DEC_FRM_MSG
{
	ENUM_VIDEO_MSG_INFO_TYPE msgType   ;
	unsigned int             frame_type;	
	unsigned int             PTSL      ;
	unsigned int             PTSH      ;
	unsigned int             reserved1 ;
	unsigned int             reserved2 ;
	unsigned int             reserved3 ;
	unsigned int             reserved4 ;
	unsigned int             reserved5 ;
	unsigned int             reserved6 ;
	unsigned int             reserved7 ;
	unsigned int             reserved8 ;
	unsigned int             reserved9 ;
	unsigned int             reserved10 ;
	unsigned int             reserved11 ;
	unsigned int             reserved12 ;
	unsigned int             reserved13 ;
	unsigned int             reserved14 ;
	unsigned int             reserved15 ;
	unsigned int             reserved16 ;
	unsigned int             reserved17 ;
	unsigned int             reserved18 ;
	unsigned int             reserved19 ;
};

struct VIDEO_DEC_PIC_MSG
{
	ENUM_VIDEO_MSG_INFO_TYPE msgType   ;
	unsigned int             frame_rate;
	unsigned int             bit_rate  ;
	unsigned int             resol     ;  /* hor_size      << 16 | ver_size        */
  unsigned int             disp_resol;  /* disp_hor_size << 16 | disp_ver_size   */
  unsigned int             actXY     ;  /* activeX       << 16 | activeY         */
  unsigned int             actWH     ;  /* activeW       << 16 | activeH         */
  unsigned int             sarWH     ;  /* sar_width     << 16 | sar_height      */
                           
	unsigned int             prog_info ;  /* prog_seq      << 16 | prog_frame      */
  unsigned int             ratio_info;  /* aspect_ratio  << 16 | aspect_ratio_idc*/
  unsigned int             afd_3d    ;  /* afd           << 16 | info_3D         */
  unsigned int             PTSL ;
  unsigned int             PTSH ;
  unsigned int             color_transf;
  unsigned int             coeffs_overscan;
  unsigned int             dispXY0;
  unsigned int             dispXY1;
  unsigned int             dispXY2;
  unsigned int             whitePointXY;
  unsigned int             maxL;
  unsigned int             minL;
  unsigned int             videoFullRangeFlag;
  unsigned int             reserved1 ;
};

/* oliver+ */
struct VIDEO_RPC_SCALER_MESSAGE
{
	unsigned int								msgType;			/* msgType is dispatched by system controller */
	unsigned int								msgSubType;		/* msgSubType is dispatched by others include emergency thread */
	unsigned int								msgIntData;		/* Integer data part */
	unsigned int								msgBodyByteSize;	/* record the data size in followed data pointer */
	unsigned int								msgDataPtrAddr;		/* The variable length data */
	unsigned int								isValidate;		/* Record the status of message. */
	unsigned int                isSmoothtoggle;
};

struct VIDEO_RPC_DEC_MESSAGE
{
   long instanceID;
   long message;
} ;

struct VIDEO_RPC_VOUT_MESSAGE
{
   long instanceID        ;
   long message           ;
   unsigned int  PTShigh  ;
   unsigned int  PTSlow   ;
   unsigned int  reserved1;
   unsigned int  reserved2;
   unsigned int  reserved3;
   unsigned int  reserved4;
} ;

struct VIDEO_RPC_DEC_FRAME_INFO
{
  long       instanceID ;
  u_int      PTSH ;
  u_int      PTSL ;
  u_char     frame_type;

} ;

struct VIDEO_RPC_DEC_PIC_INFO
{
  long       instanceID ;
  u_short    frame_rate;
	u_short    aspect_ratio;
	u_short    hor_size;
	u_short    ver_size;
	u_int      bit_rate;
	u_char     afd;
	u_char     prog_seq; 
	u_char     prog_frame;
	u_short    activeX;
	u_short    activeY;
	u_short    activeW;
	u_short    activeH;
	u_short    disp_hor_size;
	u_short    disp_ver_size;
	u_char     aspect_ratio_idc;
	u_int      sar_width;
	u_int      sar_height;
	u_char     info_3D;

} ;

struct VIDEO_RPC_DEC_MEDIA_INFO
{
    long instanceID;
    u_int width;
    u_int height;
    u_int frame_rate;
    u_int aspect_ratio_n;
    u_int aspect_ratio_d;
    u_int level;
    u_int profile;
    u_int type_3D;
    u_int par_width;
    u_int par_height;
    u_int type_LR;
    u_int type_Scan;
    u_int afd;
} ;

struct VIDEO_RPC_TO_KERNEL_PARAMETER
{
   unsigned int command;
   unsigned int param1;
   unsigned int param2;
};

program VIDEO_AGENT {
  version VERSION {
  HRESULT   VIDEO_RPC_ENC_ToSystem_EndOfStream(long)=1;
  HRESULT   VIDEO_RPC_ToSystem_EndOfStream(VIDEO_RPC_ENDOFSTREAM)=2;
  HRESULT   VIDEO_RPC_ToSystem_Deliver_GenInfo(long)=3;
  HRESULT   VIDEO_RPC_ToSystem_Deliver_FrameInfo(long)=4;
  HRESULT   VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg(VIDEO_RPC_DEC_JPEG_INFO)=5;
  HRESULT   VIDEO_RPC_ToSystem_Deliver_WSSInfo(long)=6;
  HRESULT   VIDEO_RPC_ToSystem_Deliver_PauseInfo(long)=7;
  HRESULT   VIDEO_RPC_DEC_ToSystem_FatalError(VIDEO_RPC_DEC_ERROR_INFO)=8;
  HRESULT   VIDEO_RPC_ToSystem_ScaleModeSCART(long)=9;
  HRESULT   VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo(VIDEO_RPC_ENC_AUTOPAUSE)=10;
  HRESULT   VIDEO_RPC_ToSystem_VideoHaltDone(long)=11;
  /* Oliver+ Send message via RPC */
  HRESULT   VIDEO_RPC_ToSystem_SendScalerMsg(VIDEO_RPC_SCALER_MESSAGE)=12;
  HRESULT   VIDEO_RPC_ToSystem_DecoderMessage(VIDEO_RPC_DEC_MESSAGE)=15;
  HRESULT   VIDEO_RPC_ToSystem_VoutMessage(VIDEO_RPC_VOUT_MESSAGE)=17;
  HRESULT   VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo(VIDEO_RPC_DEC_FRAME_INFO)=18;
  HRESULT   VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo(VIDEO_RPC_DEC_PIC_INFO)=19;
  HRESULT   VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo(VIDEO_RPC_DEC_MEDIA_INFO)=20;
  HRESULT   VIDEO_RPC_ToSystem_KernelRPC(VIDEO_RPC_TO_KERNEL_PARAMETER)=30;
  }=0;
}=300;




struct VIDEO_RPC_TRANSITION_EFFECT_CTRL
{
    long cancel;
    long percentage;  /* 0~256 */
    VO_RECTANGLE winStart_A; /* for VIDEO_TRANSITION_CROSSFADE_KENBURNS effect */
                             /* Start zoom window for A to be displayed on whole display window. */
                             /* If All arguments are 0xffff, use previous end zoom window as start zoom window. */
    VO_RECTANGLE winEnd_A;
    VO_RECTANGLE winStart_B;
    VO_RECTANGLE winEnd_B;
    long         timeForKenBurns ; /* micro-second unit, time for B's Kenburns */
};

