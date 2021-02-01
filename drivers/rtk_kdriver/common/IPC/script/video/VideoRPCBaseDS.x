.insert <rpc_common.h>

/* The common data structure share between System and Video */
struct RPC_RINGBUFFER {
    long        instanceID;
    long        pinID;
    long        readPtrIndex;

    long 	pRINGBUFF_HEADER;
};

enum VIDEO_VF_TYPE
{
    VF_TYPE_VIDEO_MPEG2_DECODER,
    VF_TYPE_VIDEO_MPEG4_DECODER,
    VF_TYPE_VIDEO_DIVX_DECODER,
    VF_TYPE_VIDEO_H263_DECODER,
    VF_TYPE_VIDEO_H264_DECODER,
    VF_TYPE_VIDEO_VC1_DECODER,
    VF_TYPE_VIDEO_REAL_DECODER,
    VF_TYPE_VIDEO_JPEG_DECODER,
    VF_TYPE_VIDEO_MJPEG_DECODER,
    VF_TYPE_SPU_DECODER,
    VF_TYPE_VIDEO_OUT,
    VF_TYPE_TRANSITION,
    VF_TYPE_THUMBNAIL,
    VF_TYPE_VIDEO_VP6_DECODER,
    VF_TYPE_VIDEO_IMAGE_DECODER,
    VF_TYPE_FLASH,
    VF_TYPE_VIDEO_AVS_DECODER,
    VF_TYPE_MIXER,
    VF_TYPE_VIDEO_VP8_DECODER,
    VF_TYPE_VIDEO_WMV7_DECODER,
    VF_TYPE_VIDEO_WMV8_DECODER,
    VF_TYPE_TVD,
    VF_TYPE_VIDEO_ENCODER,
    VF_TYPE_VIDEO_RAW_DECODER,
    VF_TYPE_VIDEO_FJPEG_DECODER,
    VF_TYPE_VIDEO_H264lv51_DECODER,
    VF_TYPE_VIDEO_CAPTURER,
    VF_TYPE_VIDEO_H265_DECODER,
    VF_TYPE_VIDEO_VP9_DECODER,
    VF_TYPE_RAWCONV,
    VF_TYPE_VIDEO_SPLITTER,
    VF_TYPE_VIDEO_AVS2_DECODER
};

enum VIDEO_LOW_DELAY
{
  LOW_DELAY_OFF,                /* turn off low-delay */
  LOW_DELAY_DECODER,            /* turn on for Decoder */
  LOW_DELAY_DISPLAY,            /* turn on for Video-Out */
  LOW_DELAY_DECODER_DISPLAY     /* turn on for both of Decoder and Video-Out */

};

enum VIDEO_IMG_TYPE
{
    IMG_JPEG,        /* ONLY support this type currently */
    IMG_PNG,
    IMG_BMP,
    IMG_GIF,
    IMG_TIFF,
    IMG_WEBP,
    IMG_PSEUDO
};

enum VIDEO_RATE_CONTROL_MODE
{
    VIDEO_RATE_CBR,
    VIDEO_RATE_CBG,   /* CBR/CBG */
    VIDEO_RATE_VBR,
    VIDEO_RATE_CVBR,
    VIDEO_RATE_NVBR
};

enum VIDEO_SOURCE
{
    VIDEO_SOURCE_VIN,
    VIDEO_SOURCE_DIN,
    VIDEO_SOURCE_RAWIN
};

enum VIDEO_JPEG_ROTATION
{
    VIDEO_ROTATE_0,
    VIDEO_ROTATE_90,
    VIDEO_ROTATE_180,
    VIDEO_ROTATE_270
};


enum VIDEO_JPEG_MIRROR
{
    VIDEO_MIRROR_NONE,
    VIDEO_MIRROR_X,
    VIDEO_MIRROR_Y,
    VIDEO_MIRROR_XY
};


enum IMG_TARGET_FORMAT
{
  IMG_YUV,                  /* pTargetLuma is buffer id (32bits) , LSB(16bits) is Y_BufID, MSB(16bits) is C_BufID */
  IMG_ARGB8888,
  IMG_RGB565,
  IMG_RGB332,               /* don't support */
  IMG_HANDLE,               /* don't support */
  IMG_RGBA8888,
  IMG_RGBA8888_LE,          /* little endin for RGBA8888 */
  IMG_ARGB8888_LE,          /* little endin for ARGB8888 */
  IMG_RGB565_LE             /* little endin for RGB565 */
};

enum IMG_TARGET_POSITION
{
    IMG_TARGET_LEFTTOP,
    IMG_TARGET_CENTER,
    IMG_TARGET_FILL
};

enum IMG_SOURCE_PICTURE_SELECT
{
    IMG_PICTURE_OPTIONAL,
    IMG_PICTURE_WHOLE,
    IMG_PICTURE_THUMBNAIL,
    IMG_PICTURE_THUMBNAIL_FIRST
};

enum IMG_STATUS
{
    IMG_STATUS_INIT,
    IMG_STATUS_FINISH,
    IMG_STATUS_FAIL_DECODE,
    IMG_STATUS_UNSUPPORT,
    IMG_STATUS_TIFF_FOR_BATCH,    /* please re-decode tiff file for batch mode */
    IMG_STATUS_ANIMATION_GIF,
    IMG_STATUS_UNSUPPORT_SIZE
};

enum VIDEO_COLOR_FMT
{
    VIDEO_COLOR_YUV,
	VIDEO_COLOR_ARGB8888,
	VIDEO_COLOR_RGB565,
    VIDEO_COLOR_RGB332,
    VIDEO_COLOR_RGBA8888,
    VIDEO_COLOR_HANDLE,
    VIDEO_COLOR_ARGB8888_LE,
    VIDEO_COLOR_JPEG
};

enum VIDEO_TRANSITION_TYPE
{
	VIDEO_TRANSITION_COPY,
	VIDEO_TRANSITION_CROSSFADE,
	VIDEO_TRANSITION_LEFT_TO_RIGHT,
	VIDEO_TRANSITION_TOP_TO_BOTTOM,
	VIDEO_TRANSITION_WATERFALL,
	VIDEO_TRANSITION_SNAKE,
	VIDEO_TRANSITION_RANDOM_BOX,
	VIDEO_TRANSITION_DIAGONAL,
	VIDEO_TRANSITION_FADEIN_FADEOUT,
	VIDEO_TRANSITION_MOVE,
	VIDEO_TRANSITION_CROSSFADE_KENBURNS,
  VIDEO_TRANSITION_WINDOW,
  VIDEO_TRANSITION_EXTEND,
  VIDEO_TRANSITION_EXPAND,
  VIDEO_TRANSITION_STEP_ALPHA,
  VIDEO_TRANSITION_FLYING_RECTANGLE,
  VIDEO_TRANSITION_VENETIAN_BLINDS,
  VIDEO_TRANSITION_BLUR,
  VIDEO_TRANSITION_CIRCLE,
	VIDEO_TRANSITION_RIGHT_TO_LEFT,
	VIDEO_TRANSITION_BOTTOM_TO_TOP,
  VIDEO_TRANSITION_UNKNOWN                  /* as counts of type, please add all your types above this line */

};

enum VIDEO_FORMAT           /* This enumeration is sync-ed with ENUM_TVD_VIDEO_FORMAT */
{
    VIDEO_FORMAT_NTSC,      /* (525 60Hz) NTSC-M (USA) */
    VIDEO_FORMAT_PAL,       /* (625 50Hz) PAL-I, PAL- B, D, G, H, I standards share the same configuration */
    VIDEO_FORMAT_NTSC_443,  /* (525 60Hz) NTSC-4.43 */
    VIDEO_FORMAT_PAL_M,     /* (525 60Hz) PAL-M */
    VIDEO_FORMAT_PAL_CN,    /* (625 50Hz) PAL-CN Combination standard. PAL- N, CN standards share the same configuration */
    VIDEO_FORMAT_SECAM,      /* (625 50Hz) SECAM, not support in Venus-1 */
    VIDEO_FORMAT_480P ,
    VIDEO_FORMAT_576P ,
    VIDEO_FORMAT_720P50 ,
    VIDEO_FORMAT_720P60 ,
    VIDEO_FORMAT_720P25 ,
    VIDEO_FORMAT_720P30 ,
    VIDEO_FORMAT_720I50 ,
    VIDEO_FORMAT_720I60 ,
    VIDEO_FORMAT_1080I50 ,
    VIDEO_FORMAT_1080I60 ,
    VIDEO_FORMAT_1080P50 ,
    VIDEO_FORMAT_1080P60 ,
    VIDEO_FORMAT_NTSC_15P,
    VIDEO_FORMAT_NTSC_10P,
    VIDEO_FORMAT_PAL_15P,
    VIDEO_FORMAT_PAL_10P
};

enum VIDEO_STREAM_TYPE
{
    VIDEO_STREAM_MPEG1,
    VIDEO_STREAM_MPEG2,
    VIDEO_STREAM_MPEG4,
    VIDEO_STREAM_DIVX3,
    VIDEO_STREAM_H263,
    VIDEO_STREAM_H264,
    VIDEO_STREAM_VC1,
    VIDEO_STREAM_REALVIDEO,
    VIDEO_STREAM_MJPEG,
    VIDEO_STREAM_VP6,
    VIDEO_STREAM_AVS,
    VIDEO_STREAM_YUV,
    VIDEO_STREAM_VP8,
    VIDEO_STREAM_WMV7,
    VIDEO_STREAM_WMV8,
    VIDEO_STREAM_RAW,
    VIDEO_STREAM_UNKNOWN,
    VIDEO_STREAM_FJPEG,
    VIDEO_STREAM_H264lv51,
    VIDEO_STREAM_H265,
    VIDEO_STREAM_VP9,
    VIDEO_STREAM_AVS2
};

enum VIDEO_DECODER_CC_BYPASS_MODE
{
    VIDEODECODER_CC_DROP,       /* decoder drops CC packets               */
    VIDEODECODER_CC_BYPASS,     /* decoder bypass CC packets to video-out */
    VIDEODECODER_CC_DECODE,     /* decoder pass CC packets to system side CC-decoder */
    VIDEODECODER_CC_CALLBACK    /* for user data callback */
};

enum CMPRS_RATIO
{
    CMPRS_RATIO_50 = 0,       /* compression ratio 50 */
    CMPRS_RATIO_75 = 1        /* cpmpression ratio 75 */
};

enum ENUM_VIDEO_SUBPIC_INFO_TYPE
{
    VIDEOSUBPIC_IB_INFO_TYPE
} ;

enum ENUM_DVD_VIDEO_ENCODER_OUTPUT_INFO_TYPE
{
    VIDEOENCODER_VideoGEN,
    VIDEOENCODER_VideoFrameInfo,
    VIDEOENCODER_VideoVBID_WSS_Info,
    VIDEOENCODER_VideoEndOfStream_Info,
    VIDEOENCODER_Input_EndOfStream_Info,
    VIDEOENCODER_VideoPauseInfo,
    VIDEOENCODER_AutoPauseInfo,
    VIDEOENCODER_TotalInfo
} ;

/* @FIXME: Define in system/src/Include/Filter/CVideoEncoder.h */
/* not sure if this enum is the same with RATE_CONTROL_MODE     */
enum ENUM_VIDEO_ENCODER_RC_MODE
{
    VIDEOENCODER_CBR,
    VIDEOENCODER_VBR,
    VIDEOENCODER_CVBR,
    VIDEOENCODER_TotalRCMode
};

enum ENUM_VIDEO_MSG_INFO_TYPE
{
    VIDEO_Pic_Info,
    VIDEO_Frm_Info
} ;


/* Video Output Data Types */
enum VO_STANDARD
{
  VO_STANDARD_NTSC_M,     /* NTSC-M (USA) */
  VO_STANDARD_NTSC_J,     /* NTSC-J (Japan) */
  VO_STANDARD_NTSC_443,   /* NTSC-4.43 */

  /* the PAL- B, D, G, H, I standards share the same TVE
     configuration in Venus-1 */
  VO_STANDARD_PAL_B,      /* PAL-B (625 50Hz) */
  VO_STANDARD_PAL_D,      /* PAL-D (625 50Hz) */
  VO_STANDARD_PAL_G,      /* PAL-G (625 50Hz) */
  VO_STANDARD_PAL_H,      /* PAL-H (625 50Hz) */
  VO_STANDARD_PAL_I,      /* PAL-I (625 50Hz) */

  VO_STANDARD_PAL_N,      /* PAL-N (Paraguay & Uruguay) */
  VO_STANDARD_PAL_NC,     /* PAL-NC Combination standard. */
  VO_STANDARD_PAL_M,      /* PAL-M (525 60 Hz) */
  VO_STANDARD_PAL_60,

  VO_STANDARD_SECAM,      /* SECAM, not support in Venus-1 */

  VO_STANDARD_HDTV_720P_60,  /* 720p   60 Hz */
  VO_STANDARD_HDTV_720P_50,  /* 720p   50 Hz */
  VO_STANDARD_HDTV_720P_30,  /* 720p   30 Hz */
  VO_STANDARD_HDTV_720P_25,  /* 720p   25 Hz */
  VO_STANDARD_HDTV_720P_24,  /* 720p   24 Hz */
  VO_STANDARD_HDTV_1080I_60, /* 1080i, 60/59.94 Hz */
  VO_STANDARD_HDTV_1080I_50, /* 1080i, 50 Hz */
  VO_STANDARD_HDTV_1080P_30, /* 1080p, 30 Hz */
  VO_STANDARD_HDTV_1080P_25, /* 1080p, 25 Hz */
  VO_STANDARD_HDTV_1080P_24, /* 1080p, 24 Hz */

  VO_STANDARD_VGA,    /* 640x480 @ 60Hz on VGA monitor, 480P @ 60Hz on TV */
  VO_STANDARD_SVGA,   /* 800x600 @ 50Hz on VGA monitor, 576P @ 50Hz on TV */
  VO_STANDARD_HDTV_1080P_60, /* 1080p, 60 Hz */
  VO_STANDARD_HDTV_1080P_50, /* 1080p, 50 Hz */
  VO_STANDARD_HDTV_1080I_59, /* 1080i, 59.94  Hz     (60000/1001) */
  VO_STANDARD_HDTV_720P_59,  /*  720p, 59.94  Hz     (60000/1001) */
  VO_STANDARD_HDTV_1080P_23,  /* 1080p, 23.976 Hz     (24000/1001) */
  VO_STANDARD_HDTV_1080P_59,   /* 1080p, 59.94  Hz     (60000/1001) */
  VO_STANDARD_HDTV_1080P_60_3D,
  VO_STANDARD_HDTV_1080P_50_3D,
  VO_STANDARD_HDTV_1080P_30_3D,
  VO_STANDARD_HDTV_1080P_24_3D,
   VO_STANDARD_HDTV_720P_60_3D,
   VO_STANDARD_HDTV_720P_50_3D,
   VO_STANDARD_HDTV_720P_30_3D,
   VO_STANDARD_HDTV_720P_24_3D,
   VO_STANDARD_HDTV_720P_59_3D,
  VO_STANDARD_HDTV_1080I_60_3D, /* 3D 1080i, 60 Hz */
  VO_STANDARD_HDTV_1080I_59_3D, /* 3D 1080i, 59.94  Hz     (60000/1001) */
  VO_STANDARD_HDTV_1080I_50_3D, /* 3D 1080i, 50 Hz */
  VO_STANDARD_HDTV_1080P_23_3D, /* 3D 1080P, 23HZ */
  VO_STANDARD_HDTV_4K2K_30,
  VO_STANDARD_HDTV_4K2K_24,

  VO_STANDARD_SDTV_800X600P_75,    /* HDMI support only */
  VO_STANDARD_HDTV_1280X1024P_85, /* HDMI support only */
  VO_STANDARD_HDTV_1600X1200P_85   /* HDMI support only */
} ;


enum VO_PEDESTAL_TYPE
{
  VO_PEDESTAL_TYPE_300_700_ON,
  VO_PEDESTAL_TYPE_300_700_OFF,
  VO_PEDESTAL_TYPE_286_714_ON,
  VO_PEDESTAL_TYPE_286_714_OFF
} ;


enum VO_TV_TYPE
{
  VO_TV_TYPE_4_BY_3,         /* most old-style 4:3 TVs that do not recognize/support the
                                WSS, CGMS and other VBI data */

  VO_TV_TYPE_16_BY_9_FIXED,  /* the 'dumb' 16:9 TVs that do not recognize/support the
                                WSS, CGMS and other VBI data although having a 16:9
                                display pannel. (These are mostly the first generation
                                16:9 TVs on the market that do nothing but horizontally
                                scale-up whatever video content they receive, regardless
                                of the aspect ratio information in the VBI. They can properly
                                display 16:9 anamorphic video but for normal 4:3 video,
                                the pictures will be horizontally expanded to the full 16:9
                                screen resulting a horizontal over scaling */

  VO_TV_TYPE_16_BY_9_AUTO,   /* the true WSS-compliant 16:9 TVs that are able to properly
                                recognize and handle the various control/information signals
                                in the VBI data */

  VO_TV_TYPE_16_BY_10
} ;


enum VO_HDMI_MODE
{
  VO_DVI_ON,
  VO_HDMI_ON,
  VO_MHL_ON,
  VO_HDMI_OFF               /* turn off HDMI/DVI/MHL */

} ;


enum VO_HDMI_AUDIO_SAMPLE_FREQ
{
  VO_HDMI_AUDIO_NULL,
  VO_HDMI_AUDIO_32K,
  VO_HDMI_AUDIO_44_1K,
  VO_HDMI_AUDIO_48K,
  VO_HDMI_AUDIO_88_2K,
  VO_HDMI_AUDIO_96K,
  VO_HDMI_AUDIO_176_4K,
  VO_HDMI_AUDIO_192K

} ;

enum VO_HDMI_COLOR_FMT
{
  VO_HDMI_RGB444,
  VO_HDMI_YCbCr422,
  VO_HDMI_YCbCr444
} ;

/***************************************/
/* NTSC/PAL Aspect Ratio Specification */
/***************************************/
enum VO_VBI_ASPECT_RATIO
{
  VO_VBI_ASPECT_RATIO_RESEVED_0 = 0,

  VO_VBI_ASPECT_RATIO_14_BY_9_LB_CENTER, /* 14:9 letterbox @ center:
                                            PAL  line 23 group A b0-3: 1000, mapping to
                                            NTSC line 20 Word  0 b0-1: 01 */

  VO_VBI_ASPECT_RATIO_14_BY_9_LB_TOP,    /* 14:9 letterbox @ top:
                                            PAL  line 23 group A b0-3: 0100, mapping to
                                            NTSC line 20 Word  0 b0-1: 01 */

  VO_VBI_ASPECT_RATIO_RESEVED_3,

  VO_VBI_ASPECT_RATIO_16_BY_9_LB_TOP,    /* 16:9 letterbox @ top:
                                            PAL  line 23 group A b0-3: 0010, mapping to
                                            NTSC line 20 Word  0 b0-1: 01 */

  VO_VBI_ASPECT_RATIO_RESEVED_5,
  VO_VBI_ASPECT_RATIO_RESEVED_6,

  VO_VBI_ASPECT_RATIO_16_BY_9,            /* 16:9 anamorphic:
                                            PAL  line 23 group A b0-3: 1110, or
                                            NTSC line 20 Word  0 b0-1: 10 */

  VO_VBI_ASPECT_RATIO_4_BY_3,            /* 4:3 normal:
                                            PAL  line 23 group A b0-3: 0001, or
                                            NTSC line 20 Word  0 b0-1: 00 */

  VO_VBI_ASPECT_RATIO_RESEVED_9,
  VO_VBI_ASPECT_RATIO_RESEVED_10,

  VO_VBI_ASPECT_RATIO_16_BY_9_LB_CENTER, /*  16:9 leterbox @ center:
                                             PAL  line 23 group A b0-3: 1101, or
                                             NTSC line 20 Word  0 b0-1: 01 */

  VO_VBI_ASPECT_RATIO_RESEVED_12,

  VO_VBI_ASPECT_RATIO_LT_16_BY_9_LB_CENTER, /* >16:9 leterbox @ center:
                                               PAL  line 23 group A b0-3: 1011, mapping to
                                               NTSC line 20 Word  0 b0-1: 01 */

  VO_VBI_ASPECT_RATIO_14_BY_9           /* 14:9 anamorphic:
                                            PAL  line 23 group A b0-3: 0111, mapping to
                                            NTSC line 20 Word  0 b0-1: 10 */
} ;

/********************************************/
/* NTSC CGMS-A and PAL copyright protection */
/********************************************/

enum VO_VBI_COPY_MODE
{
  VO_VBI_COPY_MODE_COPY_FREE = 0, /* copying is permitted without restriction:
                                     NTSC line 20 Word  2 b6-7: 00, mapping to
                                     PAL  line 23 group D b12-13:  00 */

  VO_VBI_COPY_MODE_RESERVE,       /* condition not to be used
                                     NTSC line 20 Word  2 b6-7: 01, mapping to
                                     PAL line 23 group D b12-13: 01*/

  VO_VBI_COPY_MODE_COPY_ONCE,     /* one generation of copies may be made:
                                     NTSC line 20 Word  2 b6-7: 10, mapping to
                                     PAL  line 23 group D b12-13:  10 */

  VO_VBI_COPY_MODE_COPY_NONE      /* no copy is permitted:
                                     NTSC line 20 Word  2 b6-7: 11, mapping to
                                     PAL  line 23 group D b12-13:  11 */
} ;



/*******************************************/
/* Macrovision Copy Protection (NTSC only) */
/*******************************************/

enum VO_VBI_APS
{
  VO_VBI_APS_OFF = 0, /* PSP off:
                         NTSC line 20 Word  2 b8-9: 00 */

  VO_VBI_APS_TYPE_1,  /* PSP on, split burst off:
                         NTSC line 20 Word  2 b8-9: 01 */

  VO_VBI_APS_TYPE_2,  /* PSP on, 2-line split burst:
                         NTSC line 20 Word  2 b8-9: 10 */

  VO_VBI_APS_TYPE_3   /* PSP on, 4-line split burst on:
                         NTSC line 20 Word  2 b8-9: 11 */
} ;


/*********************************/
/* Open Subtitle Mode (PAL only) */
/*********************************/
enum VO_VBI_SUBTITLE_MODE
{
  VO_VBI_SUBTITLE_MODE_NONE = 0,  /* no open subtitle:
                                     PAL line 23 group C b9-10: 00 */

  VO_VBI_SUBTITLE_MODE_INSIDE,    /* subtitle inside active picture area:
                                     PAL line 23 group C b9-10: 10 */

  VO_VBI_SUBTITLE_MODE_OUTSIDE,   /* subtitle outside active picture area:
                                     PAL line 23 group C b9-10: 01 */

  VO_VBI_SUBTITLE_MODE_RESERVED   /* reserved subtitle mode code:
                                     PAL line 23 group C b9-10: 11 */
} ;


enum VO_VIDEO_PLANE
{
  VO_VIDEO_PLANE_V1 = 0 ,
  VO_VIDEO_PLANE_V2 = 1 ,
  VO_VIDEO_PLANE_V3 = 2 ,
  VO_VIDEO_PLANE_SUB1 = 3 ,
  VO_VIDEO_PLANE_NONE = 255
} ;


enum VO_RESCALE_MODE
{
  VO_RESCALE_MODE_KEEP_AR_AUTO,     /* automatically select the size and position
                                       of the rescale window to best fit the video
                                       display window while keeping the original
                                       aspect ratio */

  VO_RESCALE_MODE_KEEP_AR_LB_CNTR,  /* when source AR is anamorphic, keep original
                                       AR and letter-box at the center */

  VO_RESCALE_MODE_KEEP_AR_LB_TOP,   /* when source AR is anamorphic, keep original
                                       AR and letter-box at the top */

  VO_RESCALE_MODE_KEEP_AR_PS_CNTR,  /* when source AR is anamorphic, keep original
                                       AR and pan/scan from the center of the
                                       video source */

  VO_RESCALE_MODE_KEEP_AR_PS_AUTO,  /* when source AR is anamorphic, keep original
                                       AR and pan/scan using the PS vectors given by
                                       the video source */

  VO_RESCALE_MODE_FULL_SCALE,       /*  rescale to the default display window associated
                                        with a video plane regardless of source AR */

  VO_RESCALE_MODE_USER_DEFINE,       /*  rescale to a display window specified by user */
  /*frankcheng add TV related display ratio type*/
  /* auto*/
  SCALER_SLR_RATIO_AUTO,

 /* for China*/
 SCALER_SLR_RATIO_4_3,
 SCALER_SLR_RATIO_16_9,
 SCALER_SLR_RATIO_14_9,
 SCALER_SLR_RATIO_LETTERBOX,
 SCALER_SLR_RATIO_PANORAMA,
 SCALER_SLR_RATIO_FIT,
 SCALER_SLR_RATIO_POINTTOPOINT,

 /* for best buy */
 SCALER_SLR_RATIO_BBY_AUTO,
 SCALER_SLR_RATIO_BBY_NORMAL,
 SCALER_SLR_RATIO_BBY_ZOOM,
 SCALER_SLR_RATIO_BBY_WIDE_1,
 SCALER_SLR_RATIO_BBY_WIDE_2,
 SCALER_SLR_RATIO_BBY_CINEMA,
 /*for AP set display window */
 SCALER_SLR_RATIO_CUSTOM,
 /*modified for skyworth display ratio request */
 SCALER_SLR_ASPECT_RATIO_PERSON,
 SCALER_SLR_ASPECT_RATIO_CAPTION,
 SCALER_SLR_ASPECT_RATIO_MOVIE,
 SCALER_SLR_ASPECT_RATIO_ZOOM,
 /*modified for skyworth display ratio request*/
 /*add below display ratio mode for tpv project*/
 SCALER_SLR_ASPECT_RATIO_100,
 /*add below display ratio mode to keep soure resolution ratio for skyworth project */
 SCALER_SLR_ASPECT_RATIO_SOURCE,
 /*add below display ratio mode for tpv project */
 SCALER_SLR_RATIO_ZOOM_14_9,
 SCALER_SLR_RATIO_NATIVE,
 SCALER_SLR_RATIO_15_9,
 SCALER_SLR_RATIO_85_48,
 SCALER_SLR_RATIO_5_4,
 SCALER_SLR_RATIO_16_10,
 /* disable */
 SCALER_SLR_RATIO_DISABLE = 0xff
} ;


enum VO_DEINT_MODE
{
  VO_DEINT_MODE_BOB,          /* BOB only, requires the least DRAM bandwith but results
                                 in worse quality in most cases */

  VO_DEINT_MODE_WEAVE,        /* weave (with previous field) only, usually used when
                                 the system software needs to display still pictures
                                 such as logo or JPEG photos */

  VO_DEINT_MODE_MADI,         /* MADI */

  VO_DEINT_MODE_MADI_SNGLDIR, /* MADI single direction, a DRAM bandwith saving version of MADI */

  VO_DEINT_MODE_MCOMP,        /* motion compensated, an option to be implemented in the
                                 future: video software has to generate motion-compensation (MC)
                                 candidiate of the opposite field using ME and VE, and the
                                 MC candidate will be adaptively selected in together with the
                                 weave candidiate (original opposite field) and the BOB candidiate
                                 (generated inside VO hardware) for adaptive deinterlacing */

  VO_DEINT_MODE_FILM,         /* 3:2 or 2:2 film, usually used when the system software knows
                                 sure that the video to be displayed has pure movie content */

  VO_DEINT_MODE_AUTO          /* default option: automatically select the above deint modes
                                 adaptively according to video content */
} ;


enum VO_OSD_LPF_TYPE
{
  VO_OSD_LPF_TYPE_DROP,     /* drop sample (default) */
  VO_OSD_LPF_TYPE_FILTER,   /* 3-tap low pass filter (1/4, 1/2, 1/4) */
  VO_OSD_LPF_TYPE_AVERAGE   /* average the adjacent samples to get 2:1 down sampling */
} ;


enum VO_OSD_COLOR_FORMAT
{
  VO_OSD_COLOR_FORMAT_2BIT,       /*  2-bit index (don't support on Saturn) */
  VO_OSD_COLOR_FORMAT_4BIT,       /*  4-bit index (don't support on Saturn) */
  VO_OSD_COLOR_FORMAT_8BIT,       /*  8-bit index         */
  VO_OSD_COLOR_FORMAT_RGB332,     /*  8-bit RGB    (332)  with constant alpha (don't support on Saturn) */
  VO_OSD_COLOR_FORMAT_RGB565,     /* 16-bit RGB    (565)  with constant alpha */
  VO_OSD_COLOR_FORMAT_ARGB1555,   /* 16-bit ARGB   (1555) */
  VO_OSD_COLOR_FORMAT_ARGB4444,   /* 16-bit ARGB   (4444) */
  VO_OSD_COLOR_FORMAT_ARGB8888,   /* 32-bit ARGB   (8888) */
  VO_OSD_COLOR_FORMAT_Reserved0,
  VO_OSD_COLOR_FORMAT_Reserved1,
  VO_OSD_COLOR_FORMAT_Reserved2,
  VO_OSD_COLOR_FORMAT_YCBCRA4444, /* 16-bit YCBCRA (4444) */
  VO_OSD_COLOR_FORMAT_YCBCRA8888, /* 32-bit YCBCRA (8888) */
  VO_OSD_COLOR_FORMAT_RGBA5551,   /* 16-bit RGBA   (5551) */
  VO_OSD_COLOR_FORMAT_RGBA4444,   /* 16-bit RGBA   (4444) */
  VO_OSD_COLOR_FORMAT_RGBA8888,   /* 32-bit RGBA   (8888) */
  VO_OSD_COLOR_FORMAT_420,        /* Video Format. 420 Y/C separte (don't support on Saturn) */
  VO_OSD_COLOR_FORMAT_422,        /* Video Format. 422 Y/C separte (don't support on Saturn) */
  VO_OSD_COLOR_FORMAT_RGB323,     /*  8-bit RGB    (323)  with constant alpha (don't support on Saturn) */
  VO_OSD_COLOR_FORMAT_RGB233,     /*  8-bit RGB    (233)  with constant alpha (don't support on Saturn) */
  VO_OSD_COLOR_FORMAT_RGB556,     /* 16-bit RGB    (556)  with constant alpha */
  VO_OSD_COLOR_FORMAT_RGB655,     /* 16-bit RGB    (655)  with constant alpha */
  VO_OSD_COLOR_FORMAT_RGB888,     /* 24-bit RGB    (888)  with constant alpha */
  VO_OSD_COLOR_FORMAT_RGB565_LITTLE     = 36,       /* litttle endian below */
  VO_OSD_COLOR_FORMAT_ARGB1555_LITTLE   = 37,
  VO_OSD_COLOR_FORMAT_ARGB4444_LITTLE   = 38,
  VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE   = 39,
  VO_OSD_COLOR_FORMAT_YCBCRA4444_LITTLE = 43,
  VO_OSD_COLOR_FORMAT_YCBCRA8888_LITTLE = 44,
  VO_OSD_COLOR_FORMAT_RGBA5551_LITTLE   = 45,
  VO_OSD_COLOR_FORMAT_RGBA4444_LITTLE   = 46,
  VO_OSD_COLOR_FORMAT_RGBA8888_LITTLE   = 47,
  VO_OSD_COLOR_FORMAT_RGB556_LITTLE     = 52,
  VO_OSD_COLOR_FORMAT_RGB655_LITTLE     = 53,
  VO_OSD_COLOR_FORMAT_RGB888_LITTLE     = 54

} ;

enum VO_OSD_RGB_ORDER
{
  VO_OSD_COLOR_RGB,
  VO_OSD_COLOR_BGR,
  VO_OSD_COLOR_GRB,
  VO_OSD_COLOR_GBR,
  VO_OSD_COLOR_RBG,
  VO_OSD_COLOR_BRG
} ;

enum VO_GRAPHIC_PLANE
{
  VO_GRAPHIC_OSD  = 0,
  VO_GRAPHIC_SUB1 = 1,
  VO_GRAPHIC_SUB2 = 2,
  VO_GRAPHIC_OSD1 = 0,        /* modify naming to substitute for VO_GRAPHIC_OSD  on Saturn and later chip */
  VO_GRAPHIC_OSD2 = 2,        /* modify naming to substitute for VO_GRAPHIC_SUB2 on Saturn and later chip */
  VO_GRAPHIC_NUM = 3
} ;

enum VO_GRAPHIC_STORAGE_MODE
{
  VO_GRAPHIC_BLOCK,
  VO_GRAPHIC_SEQUENTIAL
} ;

enum PVIN_MODE
{
  PVIN_MODE_FIELD,
  PVIN_MODE_FRAME
};

struct VO_COLOR
{
  u_char c1 ;
  u_char c2 ;
  u_char c3 ;
  u_char isRGB ;    /* non-zero if c1, c2 and c3 represent R, G, and B, respectively.
                       Otherwise they correspond to Y, U, and V, respectively. */
} ;


struct VO_RECTANGLE
{
  short x ;        /* the x coordinate of the upper-left corner */
  short y ;        /* the y coordinate of the upper-left corner */
  u_short width ;    /* width  of rectangle */
  u_short height ;   /* height of rectangle */
} ;


struct VO_SUBPIC_COLORMAP
{
  u_char alpha3 ;
  u_char alpha2 ;
  u_char alpha1 ;
  u_char alpha0 ;
  u_char color3 ;
  u_char color2 ;
  u_char color1 ;
  u_char color0 ;
} ;


enum SP_STREAM_TYPE
{
  SP_DVD_TYPE,
  SP_DIVX_TYPE,
  SP_DIVX_MENU_TYPE,
  SP_DVB_SUBTITLE_TYPE,
  SP_DVB_TT_TYPE,
  SP_ATSC_CC_TYPE,
  SP_SRT_TYPE,
  SP_SSA_TYPE,
  SP_DIVX_XSUB_PLUS_TYPE,
  SP_DVD_FOR_DIVX_TYPE,
  SP_BD_SUBTITLE_TYPE
} ;

/* TVD data structures shared by System and Video*/

enum ENUM_TVD_VIDEO_FORMAT
{
  TVD_VIDEO_AUTO_DETECT = 0x00,
  TVD_VIDEO_ZNTSC = 0x01,
  TVD_VIDEO_ZNTSC_443 = 0x02,
  TVD_VIDEO_ZPAL_I = 0x03,
  TVD_VIDEO_ZPAL_M =	0x04,
  TVD_VIDEO_ZPAL_CN = 0x05,
  TVD_VIDEO_ZSECAM	=	0x06,
  TVD_VIDEO_480P ,
  TVD_VIDEO_576P ,
  TVD_VIDEO_720P50 ,
  TVD_VIDEO_720P60 ,
  TVD_VIDEO_1080I50 ,
  TVD_VIDEO_1080I60 ,
  TVD_VIDEO_1080P50 ,
  TVD_VIDEO_1080P60
};

enum ENUM_TVD_INPUT_FORMAT
{
	TVD_INFMT_CVBS0_TUNER,
	TVD_INFMT_CVBS1,
	TVD_INFMT_CVBS2,
	TVD_INFMT_SVIDEO0,
	TVD_INFMT_SVIDEO1,
	TVD_INFMT_YPbPr0,
	TVD_INFMT_YPbPr1,
	TVD_INFMT_SCART,
	TVD_INFMT_YPbPrM,
	TVD_INFMT_SCART_CVBS,
	TVD_INFMT_SCART_RGB,
	TVD_INFMT_YPbPr2,
	TVD_INFMT_YPbPr3,
	TVD_INFMT_HDMI0,
	TVD_INFMT_HDMI1,
	TVD_INFMT_HDMI2,
	TVD_INFMT_HDMI3,
	TVD_INFMT_VGA0,
	TVD_INFMT_VGA1,
	TVD_INFMT_VODMA0,
	TVD_INFMT_VODMA1,
	TVD_INFMT_OSD0
} ;

enum ENUM_TVD_YC_SEP_MODE
{
	TVD_YC_SEP_1D2D_ADAPTIVE = 0,
	TVD_YC_SEP_3D_ADAPTIVE,
	TVD_YC_SEP_3D_FIXED
};

enum ENUM_TVD_VBI_DATA
{
    VBI_DATA_VPS,
    VBI_DATA_CC,
    VBI_DATA_CC_EXT,
    VBI_DATA_TT,
    VBI_DATA_TT_EXT,
    VBI_DATA_WSS,
    VBI_DATA_TIME,
    VBI_DATA_CGMSA,
    VBI_DATA_MACROVISION
};


/* TVE board type */
enum TVE_BOARD_TYPE
{
  TVE_BOARD_CLASSIC_TYPE,
  TVE_BOARD_EXTERNAL_SCART_TYPE,
  TVE_BOARD_AVHDD_TYPE,
  TVE_BOARD_CUSTOM_1_TYPE,
  TVE_BOARD_CUSTOM_2_TYPE,
  TVE_BOARD_CUSTOM_3_TYPE,
  TVE_BOARD_CUSTOM_4_TYPE,
  TVE_BOARD_CUSTOM_5_TYPE,
  TVE_BOARD_CUSTOM_6_TYPE,
  TVE_BOARD_CUSTOM_7_TYPE,
  TVE_BOARD_CUSTOM_8_TYPE,
  TVE_BOARD_CUSTOM_9_TYPE
} ;

/* video buffer type */
enum VIDEO_BUFFER_TYPE
{
  VIDEO_BUFFER_SD,
  VIDEO_BUFFER_HD,
  VIDEO_BUFFER_HD_DIVX,
  VIDEO_BUFFER_RM_CIF,
  VIDEO_BUFFER_USER_DEFINE,
  VIDEO_BUFFER_720P,
  VIDEO_BUFFER_HD_MVC,
  VIDEO_SUBPIC_RENDER_BUFFER_FULL = 16,
  VIDEO_SUBPIC_RENDER_BUFFER_HALF,
  VIDEO_MEMORY_CONFIG_BASE = 32,
  VIDEO_MEMORY_CONFIG_720P = 32,
  VIDEO_MEMORY_CONFIG_720P_WITH_SCALER_BUFFER_3D,
  VIDEO_MEMORY_CONFIG_HD,
  VIDEO_MEMORY_CONFIG_HD_WITH_SCALER_BUFFER_3D,
  VIDEO_MEMORY_CONFIG_HD_3D,
  VIDEO_MEMORY_CONFIG_HD_SMOOTH_TOGGLE_FRC,
  VIDEO_MEMORY_CONFIG_HD_SMOOTH_TOGGLE_FS,
  VIDEO_MEMORY_CONFIG_SCALING_TO_FHD,
  VIDEO_MEMORY_CONFIG_HD_SMOOTH_TOGGLE_FS_NO_MEMORY
} ;

/* DNR mode */
enum VIDEO_DNR_MODE
{
  VIDEO_DNR_OFF,
  VIDEO_DNR_AUTO,
  VIDEO_DNR_DEMO
} ;

enum VIDEO_CODEC_CONTROL_BIT
{
  VIDEO_MPEG2_ENCODER_BIT = 41,
  VIDEO_MPEG4_ENCODER_BIT = 42,
  VIDEO_MPEG2_DECODER_BIT = 43,
  VIDEO_MPEG4_DECODER_BIT = 44,
  VIDEO_DIVX_DECODER_BIT = 45,
  VIDEO_REALVIDEO_DECODER_BIT = 46,
  VIDEO_H263_DECODER_BIT = 47,
  VIDEO_MJPEG_DECODER_BIT = 48,
  VIDEO_H264_DECODER_BIT = 49,
  VIDEO_VC1_DECODER_BIT = 50,
  VIDEO_FJPEG_DECODER_BIT = 51,
  VIDEO_H264lv51_DECODER_BIT = 52

};

enum VIDEO_PHOTO_DEC_JPEG_CTRL
{
	JPEG_ENABLE = 0,
	JPEG_DISABLE = 1,
	JPEG_NO_PROGRESSIVE = 2
};


enum VIDEO_PHOTO_DEC_BITMAP_CTRL
{
	BITMAP_ENABLE = 0,
	BITMAP_DISABLE = 1
};


enum VIDEO_PHOTO_DEC_TIFF_CTRL
{
	TIFF_ENABLE = 0,
	TIFF_DISABLE = 1
};


enum VIDEO_PHOTO_DEC_GIF_CTRL
{
	GIF_ENABLE = 0,
	GIF_DISABLE = 1,
	GIF_NO_ANIMATION = 2
};


enum VIDEO_PHOTO_DEC_PNG_CTRL
{
	PNG_ENABLE = 0,
	PNG_DISABLE = 1
};


enum VIDEO_PHOTO_DEC_WEBP_CTRL
{
	WEBP_ENABLE = 0,
	WEBP_DISABLE = 1
};

enum VIDEO_PHOTO_DEC_PSEUDOIMG_CTRL
{
	PSEUDOIMG_ENABLE = 0,
	PSEUDOIMG_DISABLE = 1
};


struct MIXER_WIN
{
  u_char                 winID ;
  short                  order ;
  short                  alpha ;
  struct VO_RECTANGLE    dispWin ;
  struct VO_RECTANGLE    clipSrcWin ;
} ;

enum YUV_FMT
{
  FMT_YUYV     ,  /* as YUV4:2:2  */
  FMT_UYVY     ,  /* as YUV4:2:2  */
  FMT_YUV420   ,  /* as YUV4:2:0  */
  FMT_YUV422P  ,  /* as YUV4:2:2 and YUV are separated into three sub image  */
  FMT_M_DOMAIN ,
  FMT_YV12     ,   /* as YV12 sequencial mode */
  FMT_NV12     ,   /* as NV12 sequencial mode */
  FMT_BGRA_8888,   /* as BGRA8888 sequencial mode */
  FMT_YUV420P  ,   /* YYYY/UU/VV */
  FMT_REFRECORD,    /* as NV12 block mode */
  FMT_RGBA_8888    /* as RGBA8888 sequencial mode */
};

enum CAP_FRAME_FMT
{
  CAP_FRAME_NONE     ,
  CAP_FRAME_YUV420   ,
  CAP_FRAME_RGBA8888
};

enum CAP_IN_SEL
{
    NO_INPUT,
    MAIN_UZU,
    SUB_MIXER,
    OSD_MIXER1,
    OSD_MIXER2,
	  MAIN_UZU_FOR_DETECT = 8
};

enum VIDEO_ENC_PROFILE
{
    VIDEO_PROFILE_BASELINE,
    VIDEO_PROFILE_MAIN,
    VIDEO_PROFILE_HIGH
};


/* vodma chroma format*/
enum VO_CHROMA_FMT {
	VO_CHROMA_YUV420 = 0,
	VO_CHROMA_YUV422,
	VO_CHROMA_YUV444,
	VO_CHROMA_ARGB8888,
	VO_CHROMA_RGB888,
	VO_CHROMA_RGB565,
	VO_CHROMA_YUV411

};

enum VO_3D_MODE_TYPE {
  VO_2D_MODE = 0,
  VO_3D_SIDE_BY_SIDE_HALF,
  VO_3D_TOP_AND_BOTTOM,
  VO_3D_FRAME_PACKING,
  VO_3D_LINE_BY_LINE,
  VO_3D_VERTICAL_STRIPE,
  VO_3D_CHECKER_BOARD,
  VO_3D_REALID,
  VO_3D_SENSIO,
  VO_3D_AUTO,
  VO_3D_MVC_SBS,
  VO_3D_2DTO3D
};

enum VO_3D_OUTPUT_MODE {
  VO_3D_OUTPUT_ORIGINAL = 0,
  VO_3D_OUTPUT_LR_SEQUENCE
};

enum VO_FORCE2D_MODE {
  VO_FORCE2D_DISABLE = 0,
  VO_FORCE2D_LEFT,
  VO_FORCE2D_RIGHT
};

enum PANEL_3D_TYPE {
  PANEL_TYPE_PR = 0,
  PANEL_TYPE_SG
};

enum VO_SOURCE_TYPE
{
  VO_SOURCE_TYPE_PLAYBACK = 0,
  VO_SOURCE_TYPE_DTV
};

enum VO_FORCEBG_TYPE
{
  VO_FORCEBG_TYPE_HIDECHANNEL = 1,
  VO_FORCEBG_TYPE_SETVOINFO = 2,
  VO_FORCEBG_TYPE_DTVSPATUPDATE = 4,
  VO_FORCEBG_TYPE_DTVRESETCLKGEN = 8,
  VO_FORCEBG_TYPE_FLUSHVIDEOOUT = 16
};

enum VO_SCALER_AR_MODE
{
	VO_SCALER_AR_ORIGINAL = 0,		/* original size */
	VO_SCALER_AR_1080I_BBY_ZOOM,	/* 1080I, BBY NORMAL zoom mode */
	VO_SCALER_AR_1080I_BBY_CINEMA,	/* 1080I, BBY WIDE 2 zoom mode */
	VO_SCALER_AR_AUTO_AFD,			/* follow AFD under auto mode */
	VO_SCALER_AR_PERSON,			/* person mode */
	VO_SCALER_AR_CAPTION,			/* caption mode */
	VO_SCALER_AR_MOVIE,				/* movie mode */
	VO_SCALER_AR_ZOOM,				/* zoom mode */
	VO_SCALER_AR_ZOOM2,				/* zoom2 mode */
	VO_SCALER_AR_ZOOM3,				/* zoom3 mode */
	VO_SCALER_AR_CUSTOMER			/* customer mode */
};

enum VO_4K2K_MODE_TYPE
{
    VO_4K2K_NATIVE_MODE = 0,
    VO_4K2K_PHOTO_MODE,			/* 2Kx1K x4 sequential output (Top-Left, Top-Right, Bottom-Left, Bottom-Right) */
    VO_4K2K_VIDEO_MODE,			/* PCtool-converted MVC-like 4Kx1K video file */
    VO_4K2K_HDMI_MODE			/* 2Kx1K x4 for HDMA DMA*/
};

enum OSD_4K2K_MODE_TYPE
{
    OSD_4K2K_NATIVE_MODE = 0,
    OSD_4K2K_CORNER_MODE,			/* show 2k osd in specific area in 4k panel(Top-Left, Top-Right, Bottom-Left, Bottom-Right) */
    OSD_4K2K_SCALEUP_MODE,			/* 2k osd scale up to 4k */
    OSD_4K2K_QUARTER4K_MODE			/* 4 * 1/4 4k osd*/
} ;

enum VO_HACK_CANVAS_MODE
{
    VO_HACK_CANVAS_MODE_DISABLE = 0,	/* disable hack, canvas.dispWin defined through ConfigureGraphicCanvas by AP */
    VO_HACK_CANVAS_MODE_FIT_MAINACT,	/* canvas.dispWin fit MainAct */
    VO_HACK_CANVAS_MODE_FIT_DEN			/* canvas.dispWin fit Den */
};


enum DIRECT_VO_FRAME_QUEUE_SIZE_VALUE
{
    DIRECT_VO_FRAME_QUEUE_SIZE = 64
};

enum DIRECT_VO_FRAME_FORMAT
{
    DIRECT_VO_FRAME_FORMAT_RGBA_8888       = 0x01,
    DIRECT_VO_FRAME_FORMAT_BGRA_8888       = 0x02,
    DIRECT_VO_FRAME_FORMAT_RGB_888         = 0x03,
    DIRECT_VO_FRAME_FORMAT_YCBCR_444_I     = 0x04,
    DIRECT_VO_FRAME_FORMAT_YCBCR_422_I     = 0x05,
    DIRECT_VO_FRAME_FORMAT_YCBCR_411_I     = 0x06,
    DIRECT_VO_FRAME_FORMAT_YCBCR_420_P     = 0x07
};

enum DIRECT_VO_FRAME_LAYOUT
{
    DIRECT_VO_FRAME_LAYOUT_SEQUENCE        = 0x01,
    DIRECT_VO_FRAME_LAYOUT_BLOCK           = 0x02,
    DIRECT_VO_FRAME_LAYOUT_BLOCK_ZERO_COPY = 0x03
};

enum DIRECT_VO_FRAME_SCAN_MODE
{
    DIRECT_VO_FRAME_SCAN_MODE_INTERLACE    = 0x01,
    DIRECT_VO_FRAME_SCAN_MODE_PROGRESSIVE  = 0x02
};


enum DIRECT_VO_FRAME_CLOCK_TYPE
{
    DIRECT_VO_FRAME_CLOCK_TYPE_FREERUN       = 0x00,
    DIRECT_VO_FRAME_CLOCK_TYPE_PLAYER        = 0x01,
    DIRECT_VO_FRAME_CLOCK_TYPE_AUDIO         = 0x02,
    DIRECT_VO_FRAME_CLOCK_TYPE_VIDEO         = 0x03,
    DIRECT_VO_FRAME_CLOCK_TYPE_LOW_DELAY     = 0x04,
    DIRECT_VO_FRAME_CLOCK_TYPE_LOW_BUFFER    = 0x05,
    DIRECT_VO_FRAME_CLOCK_TYPE_LOW_DELAY_SMOOTH = 0x06,
    DIRECT_VO_FRAME_CLOCK_TYPE_VIDEO_TUNNEL  = 0x07,
    DIRECT_VO_FRAME_CLOCK_TYPE_REFCLOCK      = 0x08
};

enum DIRECT_VO_FRAME_FLAG
{
    DIRECT_VO_FRAME_FLAG_NONE              = 0x00,
    DIRECT_VO_FRAME_FLAG_AFTER_FLUSH       = 0x01,
    DIRECT_VO_FRAME_FLAG_FIRST_FRAME       = 0x02,
    DIRECT_VO_FRAME_FLAG_EOS               = 0x04
};

enum DIRECT_VO_FRAME_3D_TYPE
{
	DIRECT_VO_FRAME_3D_TYPE_2D = 0,
	DIRECT_VO_FRAME_3D_TYPE_SIDEBYSIDE_HALF_LR = 1,
	DIRECT_VO_FRAME_3D_TYPE_SIDEBYSIDE_HALF_RL = 2,
	DIRECT_VO_FRAME_3D_TYPE_TOP_BOTTOM_LR = 3,
	DIRECT_VO_FRAME_3D_TYPE_TOP_BOTTOM_RL = 4,
	DIRECT_VO_FRAME_3D_TYPE_CHECKER_BOARD = 5,
	DIRECT_VO_FRAME_3D_TYPE_FRAME_SEQ = 6,
	DIRECT_VO_FRAME_3D_TYPE_COLUMN_INTERLEAVE = 7,
	DIRECT_VO_FRAME_3D_TYPE_SIDEBYSIDE_FULL_LR = 8,
	DIRECT_VO_FRAME_3D_TYPE_SIDEBYSIDE_FULL_RL = 9,
	DIRECT_VO_FRAME_3D_TYPE_FRAME_PACKING = 10,
	DIRECT_VO_FRAME_3D_TYPE_FIELD_ALTERNATIVE = 11,
	DIRECT_VO_FRAME_3D_TYPE_LINE_ALTERNATIVE = 12,
	DIRECT_VO_FRAME_3D_TYPE_DUALSTREAM = 13,
	DIRECT_VO_FRAME_3D_TYPE_2DTO3D = 14,
	DIRECT_VO_FRAME_3D_TYPE_MAX = 15
};

enum VSGEN_IV_SRC
{
	VSGEN_IV_SRC_SEL_PIXELCLOCK = 0,
	VSGEN_IV_SRC_SEL_MAINIVS,
	VSGEN_IV_SRC_SEL_MAINDVS,
	VSGEN_IV_SRC_SEL_HDMIDMAVS,
	VSGEN_IV_SRC_SEL_MANUALVS,
	VSGEN_IV_SRC_SEL_HDMITXVS,
	VSGEN_IV_SRC_SEL_TVEPVS,
	VSGEN_IV_SRC_SEL_TVEIVS
} ;

enum VIDEO_RESOURCE_CORE_TYPE
{
    VIDEO_RESOURCE_CORE_REALTEK = 0,
    VIDEO_RESOURCE_CORE_GOOGLE,
    VIDEO_RESOURCE_CORE_IP1,
    VIDEO_RESOURCE_CORE_IP2,
    VIDEO_RESOURCE_CORE_DUAL
};

enum VIDEO_RESOURCE_CTRL_TYPE
{
    VIDEO_RESOURCE_CTRL_ADD = 0,
    VIDEO_RESOURCE_CTRL_DEL,
    VIDEO_RESOURCE_CTRL_UPDATE
};

enum VO_VSC_SRC_TYPE {
    VO_VSC_SRC_VDEC = 0,
    VO_VSC_SRC_JPEG,
    VO_VSC_SRC_HDMI
};


/* types for image orientations */
enum DIRECT_VO_FRAME_ORIENTATION{
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_0 = 0x00,
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_90 = 0x01,
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_180 = 0x02,
  DIRECT_VO_FRAME_ORIENTATION_ROTATE_270 = 0x03,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_0 = 0x04,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_90 = 0x05,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_180 = 0x06,
  DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_270 = 0x07
};

enum VO_APP_TYPE
{
  VO_APP_TYPE_NONE = 0,
  VO_APP_TYPE_NETFLIX = 1,
  VO_APP_TYPE_YOUTUBE = 2
};

/**
 * @brief This enumeration describes the VO API return types.
 **/
enum HAL_VO_P_STATE_T{
	HAL_VO_P_STATE_OK = 0,        /* from OK */
	HAL_VO_P_STATE_ERROR,         /* from ERROR */
	HAL_VO_P_STATE_INVALID_PARAM, /* from PARAMETER ERROR */
	HAL_VO_P_STATE_NOT_AVAILABLE, /* from NOT ENOUGH RESOURCE */
	HAL_VO_P_STATE_NOT_CALLABLE,  /* from NOT SUPPORTED */
	HAL_VO_P_STATE_ERR_LENGTH,    /* from NOT PERMITTED */
	HAL_VO_P_STATE_TIMEOUT,       /* from TIMEOUT */
	HAL_VO_P_STATE_OBJ_DELETED   /* from OBJECT DELETED */
};

/**
 * @brief This enumeration describes the supported pixel formats.
 **/
enum HAL_VO_P_PIXEL_FORMAT{
    HAL_VO_P_PIXEL_FORMAT_NONE = 0,   /* none of these */
    HAL_VO_P_PIXEL_FORMAT_PALETTE,    /* palette color type */
    HAL_VO_P_PIXEL_FORMAT_GRAYSCALE,  /* 8bit gray scale */
    HAL_VO_P_PIXEL_FORMAT_RGB,    /* 24bit RGB */
    HAL_VO_P_PIXEL_FORMAT_BGR,    /* 24bit RGB */
    HAL_VO_P_PIXEL_FORMAT_ARGB,   /* 32bit ARGB */
    HAL_VO_P_PIXEL_FORMAT_ABGR,   /* 32bit ABGR */
    HAL_VO_P_PIXEL_FORMAT_YUV444P,  /* planar format with each U/V values plane (YYYY UUUU VVVV) */
    HAL_VO_P_PIXEL_FORMAT_YUV444I,  /* planar format with interleaved U/V values (YYYY UVUVUVUV) */
    HAL_VO_P_PIXEL_FORMAT_YUV422P,  /* semi-planar format with each U/V values plane (2x1 subsampling ; 

YYYY UU VV) */
    HAL_VO_P_PIXEL_FORMAT_YUV422I,  /* semi-planar format with interleaved U/V values (2x1 subsampling ; 

YYYY UVUV) */
    HAL_VO_P_PIXEL_FORMAT_YUV422YUYV, /* interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) for MStar Chip Vender 

*/
    HAL_VO_P_PIXEL_FORMAT_YUV420P,  /* semi-planar format with each U/V values plane (2x2 subsampling ; 

YYYYYYYY UU VV) */
    HAL_VO_P_PIXEL_FORMAT_YUV420I,  /* semi-planar format with interleaved U/V values (2x2 subsampling ; 

YYYYYYYY UVUV) */
    HAL_VO_P_PIXEL_FORMAT_YUV400,   /* 8bit Y plane without U/V values */
    HAL_VO_P_PIXEL_FORMAT_YUV224P,  /* semi-planar format with each U/V values plane, 1 Ysamples has 2 

U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_P_PIXEL_FORMAT_YUV224I,  /* semi-planar format with interleaved U/V values (Y0Y1 

U0V0U0V0U1V1U1V1) */
    HAL_VO_P_PIXEL_FORMAT_YUV444SP,  /* sequential packed with non-planar (YUVYUVYUV...) */
    HAL_VO_P_PIXEL_FORMAT_ALPHAGRAYSCALE,    /* gray scale with alpha */
    HAL_VO_P_PIXEL_FORMAT_MAX    /* maximum number of HAL_VO_P_PIXEL_FORMAT */
};

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
enum HAL_VO_P_PANEL_TYPE{
    HAL_VO_P_PANEL_TYPE_NONE = 0, /* none of these */
    HAL_VO_P_PANEL_TYPE_FHD,  /* full HD panel (1920x1080) */
    HAL_VO_P_PANEL_TYPE_UHD,  /* ultra HD panel (3840x2160) */
    HAL_VO_P_PANEL_TYPE_HD1024X768,   /* HD panel (1024x768) */
    HAL_VO_P_PANEL_TYPE_HD1280X720,   /* HD panel (1280x720) */
    HAL_VO_P_PANEL_TYPE_HD1366X768,   /* HD panel (1366x768) */
    HAL_VO_P_PANEL_TYPE_MAX  /* maximum number of HAL_VO_P_PANEL_TYPE */
};

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
enum HAL_VO_P_CFG_TYPE{
    HAL_VO_P_CFG_TYPE_NONE = 0,   /* none of these */
    HAL_VO_P_CFG_TYPE_ALPHA_BLEND,    /* set alpha blend */
    HAL_VO_P_CFG_TYPE_PIXEL_FORMAT,   /* set pixel format of video source */
    HAL_VO_P_CFG_TYPE_INPUT_RECT, /* set video input source */
    HAL_VO_P_CFG_TYPE_OUTPUT_RECT,    /* set video output source */
    HAL_VO_P_CFG_TYPE_MAX    /* maximum number of HAL_VO_P_CONFIG_TYPE */
};

/**
 * @brief This enumeration describes supported pixel format for a video output (VO).
 **/
enum HAL_VO_P_SUPPORT_PIXEL_FORMAT_T{
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_NONE = 0x00000000, /* none of these */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_PALETTE = 0x00000001,    /* palette color type */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_GRAYSCALE = 0x00000002,    /* 8bit gray scale */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_RGB = 0x00000004,  /* 24bit RGB */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_BGR = 0x00000008,  /* 24bit BGR */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_ARGB = 0x00000010, /* 32bit ARGB */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_ABGR = 0x00000020, /* 32bit ABGR */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV444P = 0x00000040,  /* planar format with each U/V values plane 

(YYYY UUUU VVVV) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV444I = 0x00000080,  /* planar format with interleaved U/V values 

(YYYY UVUVUVUV) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV422P = 0x00000100,  /* semi-planar format with each U/V values plane 

(2x1 subsampling ; YYYY UU VV) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV422I = 0x00000200,  /* semi-planar format with interleaved U/V 

values (2x1 subsampling ; YYYY UVUV) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV422YUYV = 0x00000400,   /* interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) 

for MStar Chip Vender */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV420P = 0x00000800,  /* semi-planar format with each U/V values plane 

(2x2 subsampling ; YYYYYYYY UU VV) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV420I = 0x00001000,  /* semi-planar format with interleaved U/V 

values (2x2 subsampling ; YYYYYYYY UVUV) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV400 = 0x00002000,   /* 8bit Y plane without U/V values */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV224P = 0x00004000,  /* semi-planar format with each U/V values 

plane, 1 Ysamples has 2 U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV224I = 0x00008000,  /* semi-planar format with interleaved U/V 

values (Y0Y1 U0V0U0V0U1V1U1V1) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_YUV444SP = 0x00010000,  /* sequential packed with non-planar 

(YUVYUVYUV...) */
    HAL_VO_P_SUPPORT_PIXEL_FORMAT_ALPHAGRAYSCALE = 0x00020000    /* gray scale with alpha */
};

/**
 * @brief This enumeration describes supported panel type for a video output (VO).
 **/
enum HAL_VO_P_SUPPORT_PANEL_TYPE_T{
    HAL_VO_P_SUPPORT_PANEL_TYPE_NONE = 0x00000000,
    HAL_VO_P_SUPPORT_PANEL_TYPE_HD1024X768 = 0x00000001,  /* HD panel (1024x768) */
    HAL_VO_P_SUPPORT_PANEL_TYPE_HD1280X720 = 0x00000002,  /* HD panel (1280x720) */
    HAL_VO_P_SUPPORT_PANEL_TYPE_HD1366X768 = 0x00000004,  /* HD panel (1366x768) */
    HAL_VO_P_SUPPORT_PANEL_TYPE_FHD = 0x00000008,         /* full HD panel (1920x1080) */
    HAL_VO_P_SUPPORT_PANEL_TYPE_UHD = 0x00000010         /* ultra HD panel (3840x2160) */
};

/**
 * @brief This enumeration describes a framebuffer property flags for the video output (VO).
 **/
enum HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_FLAGS_T{
    HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_FLAGS_NONE = 0x00000000,
	HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_FLAGS_COLORSPACE = 0x00000001,
	HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_FLAGS_ALPHABLENDING = 0x00000002,
	HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_FLAGS_INPUTRECT = 0x00000004,
	HAL_VO_P_FB_FRAMEBUFFER_PROPERTY_FLAGS_OUTPUTRECT = 0x00000008
};

enum HDR_TYPE {
  HDR_NONE = 0,
  HDR_HDR10,
  HDR_HLG,
  HDR_PRIME,
  HDR_DOLBY
};
