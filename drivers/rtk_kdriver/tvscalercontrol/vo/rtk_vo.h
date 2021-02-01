#ifndef _VO_H_
#define _VO_H_

#include "base_types.h"
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/vodma_reg.h>
#include <rbus/vodma2_reg.h>
#include <rbus/sensio_reg.h>
#include <rbus/dc_sys_reg.h>
//#include <rbus/dc2_sys_reg.h>
#include <rbus/osdovl_reg.h>
#include <rbus/ppoverlay_reg.h>

#include <scalercommon/scalerDrvCommon.h> /* SCALERIOC_GETVOINFO */
#include <scalercommon/scalerCommon.h>    /* StructDisplayInfo */

#define __DOLBY_VTOP_422TO444__

/**
 * @brief This enumeration describes the VO API return types.
 **/
typedef enum {
	HAL_VO_STATE_OK = 0,        /* from OK */
	HAL_VO_STATE_ERROR,         /* from ERROR */
	HAL_VO_STATE_INVALID_PARAM, /* from PARAMETER ERROR */
	HAL_VO_STATE_NOT_AVAILABLE, /* from NOT ENOUGH RESOURCE */
	HAL_VO_STATE_NOT_CALLABLE,  /* from NOT SUPPORTED */
	HAL_VO_STATE_ERR_LENGTH,    /* from NOT PERMITTED */
	HAL_VO_STATE_TIMEOUT,       /* from TIMEOUT */
	HAL_VO_STATE_OBJ_DELETED,   /* from OBJECT DELETED */
} HAL_VO_STATE_T;

/**
 * @brief This enumeration describes the supported pixel formats.
 **/
typedef enum {
    HAL_VO_PIXEL_FORMAT_NONE = 0,   /* none of these */
    HAL_VO_PIXEL_FORMAT_PALETTE,    /* palette color type */
    HAL_VO_PIXEL_FORMAT_GRAYSCALE,  /* 8bit gray scale */
    HAL_VO_PIXEL_FORMAT_RGB,    /* 24bit RGB */
    HAL_VO_PIXEL_FORMAT_BGR,    /* 24bit RGB */
    HAL_VO_PIXEL_FORMAT_ARGB,   /* 32bit ARGB */
    HAL_VO_PIXEL_FORMAT_ABGR,   /* 32bit ABGR */
    HAL_VO_PIXEL_FORMAT_YUV444P,  /* planar format with each U/V values plane (YYYY UUUU VVVV) */
    HAL_VO_PIXEL_FORMAT_YUV444I,  /* planar format with interleaved U/V values (YYYY UVUVUVUV) */
    HAL_VO_PIXEL_FORMAT_YUV422P,  /* semi-planar format with each U/V values plane (2x1 subsampling ; YYYY UU VV) */
    HAL_VO_PIXEL_FORMAT_YUV422I,  /* semi-planar format with interleaved U/V values (2x1 subsampling ; YYYY UVUV) */
    HAL_VO_PIXEL_FORMAT_YUV422YUYV, /* interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) for MStar Chip Vender */
    HAL_VO_PIXEL_FORMAT_YUV420P,  /* semi-planar format with each U/V values plane (2x2 subsampling ; YYYYYYYY UU VV) */
    HAL_VO_PIXEL_FORMAT_YUV420I,  /* semi-planar format with interleaved U/V values (2x2 subsampling ; YYYYYYYY UVUV) */
    HAL_VO_PIXEL_FORMAT_YUV400,   /* 8bit Y plane without U/V values */
    HAL_VO_PIXEL_FORMAT_YUV224P,  /* semi-planar format with each U/V values plane, 1 Ysamples has 2 U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_PIXEL_FORMAT_YUV224I,  /* semi-planar format with interleaved U/V values (Y0Y1 U0V0U0V0U1V1U1V1) */
    HAL_VO_PIXEL_FORMAT_YUV444SP,  /* sequential packed with non-planar (YUVYUVYUV...) */
    HAL_VO_PIXEL_FORMAT_ALPHAGRAYSCALE,    /* gray scale with alpha */
    HAL_VO_PIXEL_FORMAT_MAX,    /* maximum number of HAL_VO_PIXEL_FORMAT */
} HAL_VO_PIXEL_FORMAT;

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
typedef enum {
    HAL_VO_PANEL_TYPE_NONE = 0, /* none of these */
    HAL_VO_PANEL_TYPE_FHD,  /* full HD panel (1920x1080) */
    HAL_VO_PANEL_TYPE_UHD,  /* ultra HD panel (3840x2160) */
    HAL_VO_PANEL_TYPE_HD1024X768,   /* HD panel (1024x768) */
    HAL_VO_PANEL_TYPE_HD1280X720,   /* HD panel (1280x720) */
    HAL_VO_PANEL_TYPE_HD1366X768,   /* HD panel (1366x768) */
    HAL_VO_PANEL_TYPE_MAX,  /* maximum number of HAL_VO_PANEL_TYPE */
} HAL_VO_PANEL_TYPE;

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
typedef enum {
    HAL_VO_CFG_TYPE_NONE = 0,   /* none of these */
    HAL_VO_CFG_TYPE_ALPHA_BLEND,    /* set alpha blend */
    HAL_VO_CFG_TYPE_PIXEL_FORMAT,   /* set pixel format of video source */
    HAL_VO_CFG_TYPE_INPUT_RECT, /* set video input source */
    HAL_VO_CFG_TYPE_OUTPUT_RECT,    /* set video output source */
    HAL_VO_CFG_TYPE_MAX,    /* maximum number of HAL_VO_CONFIG_TYPE */
} HAL_VO_CFG_TYPE;

/**
 * @brief This enumeration describes supported pixel format for a video output (VO).
 **/
typedef enum {
    HAL_VO_SUPPORT_PIXEL_FORMAT_NONE = 0x00000000, /* none of these */
    HAL_VO_SUPPORT_PIXEL_FORMAT_PALETTE = 0x00000001,    /* palette color type */
    HAL_VO_SUPPORT_PIXEL_FORMAT_GRAYSCALE = 0x00000002,    /* 8bit gray scale */
    HAL_VO_SUPPORT_PIXEL_FORMAT_RGB = 0x00000004,  /* 24bit RGB */
    HAL_VO_SUPPORT_PIXEL_FORMAT_BGR = 0x00000008,  /* 24bit BGR */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ARGB = 0x00000010, /* 32bit ARGB */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ABGR = 0x00000020, /* 32bit ABGR */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444P = 0x00000040,  /* planar format with each U/V values plane (YYYY UUUU VVVV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444I = 0x00000080,  /* planar format with interleaved U/V values (YYYY UVUVUVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422P = 0x00000100,  /* semi-planar format with each U/V values plane (2x1 subsampling ; YYYY UU VV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422I = 0x00000200,  /* semi-planar format with interleaved U/V values (2x1 subsampling ; YYYY UVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422YUYV = 0x00000400,   /* interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) for MStar Chip Vender */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV420P = 0x00000800,  /* semi-planar format with each U/V values plane (2x2 subsampling ; YYYYYYYY UU VV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV420I = 0x00001000,  /* semi-planar format with interleaved U/V values (2x2 subsampling ; YYYYYYYY UVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV400 = 0x00002000,   /* 8bit Y plane without U/V values */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV224P = 0x00004000,  /* semi-planar format with each U/V values plane, 1 Ysamples has 2 U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV224I = 0x00008000,  /* semi-planar format with interleaved U/V values (Y0Y1 U0V0U0V0U1V1U1V1) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444SP = 0x00010000,  /* sequential packed with non-planar (YUVYUVYUV...) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ALPHAGRAYSCALE = 0x00020000,    /* gray scale with alpha */
} HAL_VO_SUPPORT_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes supported panel type for a video output (VO).
 **/
typedef enum {
    HAL_VO_SUPPORT_PANEL_TYPE_NONE = 0x00000000,
    HAL_VO_SUPPORT_PANEL_TYPE_HD1024X768 = 0x00000001,  /* HD panel (1024x768) */
    HAL_VO_SUPPORT_PANEL_TYPE_HD1280X720 = 0x00000002,  /* HD panel (1280x720) */
    HAL_VO_SUPPORT_PANEL_TYPE_HD1366X768 = 0x00000004,  /* HD panel (1366x768) */
    HAL_VO_SUPPORT_PANEL_TYPE_FHD = 0x00000008,         /* full HD panel (1920x1080) */
    HAL_VO_SUPPORT_PANEL_TYPE_UHD = 0x00000010,         /* ultra HD panel (3840x2160) */
} HAL_VO_SUPPORT_PANEL_TYPE_T;

/**
 * @brief This enumeration describes a framebuffer property flags for the video output (VO).
 **/
typedef enum {
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_NONE = 0x00000000,
	HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_COLORSPACE = 0x00000001,
	HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_ALPHABLENDING = 0x00000002,
	HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_INPUTRECT = 0x00000004,
	HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_OUTPUTRECT = 0x00000008,
} HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 **/
typedef struct {
	unsigned int    x;  /* x coordinate of its top-left point */
	unsigned int    y;  /* y coordinate of its top-left point */
	unsigned int    w;  /* width of it */
	unsigned int    h;  /* height of it */
} HAL_VO_RECT_T;

/**
 * @brief This structure describes a image information to VO.
 **/
typedef struct {
	unsigned char       *buf;           /* buffer pointer of decoded raw data */
	unsigned char       *ofs_y;         /* offset of Y component */
	unsigned char       *ofs_uv;        /* offset of UV components */
	unsigned int        len_buf;        /* buffer length of decoded raw data */
	unsigned int        stride;         /* stride size of decoded raw data */
	HAL_VO_RECT_T       rect;           /* image data rectangular */
	HAL_VO_PIXEL_FORMAT pixel_format;   /* pixel format of image */
} HAL_VO_IMAGE_T;

/**
 * @brief This struct describes a value set for the configuration type.
 **/
typedef union {
    unsigned int alpha; /* alpha blending factor (0~255) */
    HAL_VO_RECT_T rect; /* rectangular information for the video source */
    HAL_VO_PIXEL_FORMAT pixel_format;   /* pixel format of image */
} HAL_VO_CFG_VALUE_T;

/**
 * @brief This structure describes a video output (VO) configuration set.
 **/
typedef struct {
	HAL_VO_CFG_TYPE     type;   /* configuration type to set VO */
	HAL_VO_CFG_VALUE_T  value;  /* configuration value */
} HAL_VO_CFG_T;

/**
 * @brief This structure describes a video output (VO) capability of device.
 **/
typedef struct {
    HAL_VO_SUPPORT_PANEL_TYPE_T support_panel_type;     /* supported panel type */
    HAL_VO_SUPPORT_PIXEL_FORMAT_T support_pixel_format; /* supported pixel format */
    unsigned char is_seperated_vo_port;                 /* whether to be seperated vo port */
    unsigned char is_changeable_cs_dynamically;			/* whether to be able to change color space dynamically */
    unsigned int vo_port_nb;                            /* the number of vo ports */
    unsigned int framebuffer_length;                    /* the length of framebuffer */
    HAL_VO_RECT_T framebuffer_rect;                     /* the rect of framebuffer */
} HAL_VO_DEVICE_CAPABILITY_T;

/**
 * @brief This structure describes a framebuffer for the video output (VO).
 **/
typedef struct {
    unsigned char* buf;			/* buffer pointer of the framebuffer */
    unsigned int buf_length;		/* the length of buffer */
    unsigned int stride;		/* stride size of the framebuffer */
    HAL_VO_RECT_T resolution;		/* resolution of the framebuffer */
    HAL_VO_PIXEL_FORMAT pixel_format;	/* pixel format of the framebuffer */
} HAL_VO_FB_FRAMEBUFFER_T;

/**
 * @brief This structure describes a framebuffer property for the video output (VO).
 **/
typedef struct {
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_T flags;	/* framebuffer property flags */
	HAL_VO_PIXEL_FORMAT pixel_format;				/* pixel format of the framebuffer */
	unsigned int alpha;								/* value for the alpha blending */
	HAL_VO_RECT_T input;							/* input rect of source */
	HAL_VO_RECT_T output;							/* output rect of source */
} HAL_VO_FB_FRAMEBUFFER_PROPERTY_T;

//==============================================================================
typedef enum {
	HAL_VO_DISPLAY_MODE_FHD,
	HAL_VO_DISPLAY_MODE_UHD,
	HAL_VO_DISPLAY_MODE_UHD_SINGLE,
} HAL_VO_DISPLAY_MODE;

typedef struct {
	unsigned int        ch;
	HAL_VO_PANEL_TYPE   def;
	unsigned int        buf_addr[2];
	unsigned int        buf_size;
} VO_OPEN_CMD_T;

typedef struct {
	unsigned int        ch;
	HAL_VO_CFG_T        cfg;
} VO_CONFIG_CMD_T;

typedef struct {
	unsigned int        ch;
	HAL_VO_IMAGE_T      image;
} VO_DISPLAY_CMD_T;

HAL_VO_STATE_T VO_Open(VO_OPEN_CMD_T *);
HAL_VO_STATE_T VO_Config(unsigned int, HAL_VO_CFG_T);
HAL_VO_STATE_T VO_DisplayPicture(unsigned int, HAL_VO_IMAGE_T, bool);
HAL_VO_STATE_T VO_RedrawPicture(unsigned int);
HAL_VO_STATE_T VO_Close(unsigned int);
bool Mixer_Alpha(unsigned char alpha);

#define VO_IOC_MAGIC            'v'
#define VO_IOC_OPEN             _IOW(VO_IOC_MAGIC, 0, int)
#define VO_IOC_CONFIG           _IOW(VO_IOC_MAGIC, 1, int)
#define VO_IOC_DISPLAYPICTTURE  _IOW(VO_IOC_MAGIC, 2, int)
#define VO_IOC_REDRAWPICTURE    _IOW(VO_IOC_MAGIC, 3, int)
#define VO_IOC_CLOSE            _IOW(VO_IOC_MAGIC, 4, int)
#define VO_IOC_MAXNR            4

#define S_OK		0x10000000
#define S_FAIL		0x10000001

#define VODMA_DEV_NUM 2
#define VODMA_BUF_NUM 3 /* two for double buffer, one for transition*/
#define VODMA_HALBUF_NUM 2
#define MIN_VO_WIDTH    64
#define MIN_VO_HEIGHT   0
#define MAX_VO_WIDTH    8192
#define MAX_VO_HEIGHT   4096

#define MAX_SE_ALPHA_WIDTH      4096

#define PANEL_FHD_WIDTH    1920
#define PANEL_FHD_HEIGHT   1080
#define PANEL_UHD_WIDTH    3840
#define PANEL_UHD_HEIGHT   2160

typedef enum {
	VO_STATE_INIT = 0x00,
	VO_STATE_OPEN,
	VO_STATE_DISPLAY
} VO_STATE_T;

typedef struct {
	unsigned int    HTotal;     /* h_threshold */
	unsigned int    VTotal;     /* v_threshold */
	unsigned int    HWidth;     /* h_active */
	unsigned int    VHeight;    /* v_active */
	unsigned int    HStartPos;  /* h_active_start */
	unsigned int    VStartPos;  /* v_active_start */
	unsigned int    isProg;     /* progressive or interlace */
	unsigned int    SampleRate; /* sample rate in 100Hz */
	unsigned int    FrameRate;  /* Frame Rate, //vfreq unit 0.001Hz */
} VO_TIMING;

typedef struct {
	VO_TIMING                   timemode;
	SLR_VOINFO                  VOInfo;
	unsigned int                vsyncgen_pixel_freq;
	VODMA_DDOMAIN_CHROMA_FMT    Ddomain_Chroma_fmt;
} VO_VPLANE_ATTR;

typedef struct {
	bool				f_update;
	vodma_vodma_v1_v_flip_RBUS      DMA_v1_seq_v_flip;
	vodma_vodma_v1_seq_RBUS         DMA_v1_staddr;
} UPDATE_SEQ_CTRL;

typedef struct {
	VO_STATE_T      vo_state[VODMA_DEV_NUM];

	unsigned long   phy_addr[VODMA_DEV_NUM][VODMA_BUF_NUM];
	unsigned int    buffer_size[VODMA_DEV_NUM][VODMA_BUF_NUM];
	unsigned char   buf_idx[VODMA_DEV_NUM];
	unsigned long   phy_addr_y[VODMA_DEV_NUM][VODMA_BUF_NUM];
	unsigned long   phy_addr_c[VODMA_DEV_NUM][VODMA_BUF_NUM];
	unsigned char   borrow_from_vbm[VODMA_DEV_NUM][VODMA_BUF_NUM];
	unsigned int    borrow_size[VODMA_DEV_NUM][VODMA_BUF_NUM];
	unsigned long   hal_phy_addr[VODMA_DEV_NUM][VODMA_HALBUF_NUM];
	unsigned int    hal_buf_size[VODMA_DEV_NUM][VODMA_HALBUF_NUM];

	HAL_VO_PANEL_TYPE panel_type[VODMA_DEV_NUM];
	unsigned char   alpha_blend[VODMA_DEV_NUM];
	HAL_VO_IMAGE_T  image[VODMA_DEV_NUM];

	VO_VPLANE_ATTR  videoPlane[VODMA_DEV_NUM];  /* video plane attributes */
	HAL_VO_RECT_T   displayWin[VODMA_DEV_NUM];
	unsigned char   nosignal[VODMA_DEV_NUM];
	unsigned char   avsync[VODMA_DEV_NUM];
	UPDATE_SEQ_CTRL	updare_seq_ctrl[VODMA_DEV_NUM];
} VO_DATA;

typedef enum {
	VODMA_COLOR_RGB    = 0x00,
	VODMA_COLOR_YUV422,
	VODMA_COLOR_YUV444,
	VODMA_COLOR_YUV411,
	VODMA_COLOR_UNKNOW
} VODMA_COLOR_SPACE_T;

#define VP_DC_IDX_VOUT_V1_Y_CURR	116
#define VP_DC_IDX_VOUT_V1_C_CURR	117
#define VP_DC_IDX_VOUT_V1_Y_CURR2	118
#define VP_DC_IDX_VOUT_V1_C_CURR2	119
#define VP_DC_IDX_VOUT_V2_Y_CURR	120
#define VP_DC_IDX_VOUT_V2_C_CURR	121
#define VP_DC_IDX_VOUT_V2_Y_CURR2	122
#define VP_DC_IDX_VOUT_V2_C_CURR2	123
#define VP_DC_IDX_VOUT_TMP_Y_CURR	124
#define VP_DC_IDX_VOUT_TMP_C_CURR	125

/* //reserve for dcu1 access in IB mode */
#define VP_DC1_IDX_VOUT_V1_Y_CURR	0
#define VP_DC1_IDX_VOUT_V1_C_CURR	1
#define VP_DC1_IDX_VOUT_V1_Y_CURR2	2
#define VP_DC1_IDX_VOUT_V1_C_CURR2	3
#define VP_DC1_IDX_VOUT_V2_Y_CURR	4
#define VP_DC1_IDX_VOUT_V2_C_CURR	5
#define VP_DC1_IDX_VOUT_V2_Y_CURR2	6
#define VP_DC1_IDX_VOUT_V2_C_CURR2	7
#define VP_DC1_IDX_VOUT_TMP_Y_CURR	8
#define VP_DC1_IDX_VOUT_TMP_C_CURR	9

int vodma_init_pll(void);
int vodma_reset(void);
int vodma_disable(void);
int vodma_waitApply(void);
int vodma_SeqWidthAlign(int, HAL_VO_PIXEL_FORMAT);
#ifdef __DOLBY_VTOP_422TO444__
void vodma_set_dolby_vtop_422to444(bool);
#endif
int vodma_set_dma(unsigned int, VO_TIMING *);
int vodma_set_timinggen(VO_TIMING *);
int vodma_set_vsyncgen(unsigned int, VO_TIMING *);
int vodma_set_sensio(void);
int vomda_set_voinfo(unsigned int, VO_TIMING *, unsigned char);

unsigned int rpcVoReady(unsigned long, unsigned long);
unsigned int rpcVoNoSignal(unsigned long, unsigned long);
unsigned int rpcVoAVSync(unsigned long, unsigned long);
unsigned int rpcVoHdrFrameInfo(unsigned long, unsigned long);
unsigned char get_vo_nosignal_flag(unsigned int);
void set_vo_nosignal_flag(unsigned int, unsigned char);
unsigned char get_vo_avsync_flag(unsigned int);
void set_vo_avsync_flag(unsigned int, unsigned char);

StructDisplayInfo *Get_VO_Dispinfo(unsigned char);
void Config_VO_Dispinfo(SLR_VOINFO *);
unsigned char get_vo_mode_sequential(void);
void set_vo_mode_sequential(unsigned char enable);
unsigned char get_vo_run_smooth_toggle_enable(unsigned char display);
void set_vo_run_smooth_toggle_enable(unsigned char enable, unsigned char display);
unsigned char get_vo_open_smooth_toggle_enable(unsigned char display);
void set_vo_open_smooth_toggle_enable(unsigned char enable, unsigned char display);
#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
void set_vo_smooth_toggle_fsmode(unsigned char fsmode, unsigned char display);
unsigned char get_vo_smooth_toggle_fsmode(unsigned char display);
#endif
VO_3D_MODE_TYPE get_vo_3d_mode(void);
void set_vo_3d_mode(VO_3D_MODE_TYPE mode);
unsigned char get_vo_imd_disable(unsigned char display);
void set_vo_imd_disable(unsigned char enable, unsigned char display);
unsigned char get_reset_smooth_toggle_state(unsigned char display);
void set_reset_smooth_toggle_state(unsigned char enable, unsigned char display);

extern unsigned char rtk_display_connect(void);
void set_force_change_vo_flag(unsigned char, unsigned char flag);
HAL_VO_STATE_T vo_SetInputRegion(unsigned int, unsigned char, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned char get_vo_plane_flag(unsigned char display);
void enable_vodma_empty_gate(unsigned char plane);
unsigned char VO_get_disp_from_port(unsigned char port);
void VO_set_disp_to_port(unsigned char port, unsigned char display);
unsigned char get_daptive_stream_vo_update_flag(unsigned char ch); /* //This is for adaptive stream wait vo update */
void set_daptive_stream_vo_update_flag(unsigned char ch, unsigned char flag); /* //This is for adaptive stream wait vo update */
void set_vo_vp9_flag(unsigned char ch, unsigned char enable);
unsigned char get_vo_vp9_flag(unsigned char ch);
#if 0
void set_rotate_mode(DIRECT_VO_FRAME_ORIENTATION value);
DIRECT_VO_FRAME_ORIENTATION get_rotate_mode(void);
extern void Set_rotate_function(unsigned char enable);
#endif
unsigned char get_voinfo_flag(void);
void set_voinfo_flag(unsigned char flag);
#ifdef CONFIG_HDR_SDR_SEAMLESS
spinlock_t* get_vdec_seamless_change_spinlock(void);
void set_vdec_seamless_change_flag(unsigned char TorF);
unsigned char get_vdec_seamless_change_flag(void);
unsigned char get_vo_frameratechange_enable(unsigned char display);
void set_vo_frameratechange_enable(unsigned char enable, unsigned char display);
#endif
#endif
