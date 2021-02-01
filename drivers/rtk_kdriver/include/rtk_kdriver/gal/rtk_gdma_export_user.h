#ifndef _GDMA_EXPORT_USER_H_
#define _GDMA_EXPORT_USER_H_

#define BLOCKING_COOKIE 1
#define NONBLOCKING_COOKIE 2


typedef struct {
	unsigned short index;
	unsigned short d0;
	unsigned short d1;
} GDMA_GAMMA_TABLE;

typedef struct {
	unsigned short gamma_num; //1 or 2
	unsigned short op;       //1:w or 2:r
	unsigned short channel;  //0:R or 1:G or 2:B or 3:all
	unsigned short gamma_size; //<=128
	GDMA_GAMMA_TABLE gamma_data[128];
} GDMA_GAMMA_OP;

/* data structure for RPC call */
#define GDMA_IOC_MAGIC  'z'

#define GDMA_CONFIGURE_GRPAHIC_CANVAS  _IOR(GDMA_IOC_MAGIC, 0, int)
#define GDMA_CREATE_GRPAHIC_WINDOW     _IOR(GDMA_IOC_MAGIC, 1, int)
#define GDMA_DRAW_GRPAHIC_WINDOW       _IOR(GDMA_IOC_MAGIC, 2, int)
#define GDMA_MODIFY_GRPAHIC_WINDOW     _IOR(GDMA_IOC_MAGIC, 3, int)
#define GDMA_HIDE_GRPAHIC_WINDOW       _IOR(GDMA_IOC_MAGIC, 4, int)
#define GDMA_DELETE_GRPAHIC_WINDOW     _IOR(GDMA_IOC_MAGIC, 5, int)
#define GDMA_CONFIGURE_OSD_PALETTE     _IOR(GDMA_IOC_MAGIC, 6, int)
#define GDMA_DISPLAY_GRPAHIC           _IOR(GDMA_IOC_MAGIC, 7, int)
#define GDMA_QUERY_STATUS              _IOR(GDMA_IOC_MAGIC, 8, int)

#define GDMA_PLANE_CONFIG_DISPLAY_WIN  _IOR(GDMA_IOC_MAGIC, 9, int)
#define GDMA_PLANE_DISPLAY             _IOR(GDMA_IOC_MAGIC, 10, int)
#define GDMA_OSD1_ON_TOP               _IOR(GDMA_IOC_MAGIC, 11, int)
#define GDMA_CONFIG_3D                 _IOR(GDMA_IOC_MAGIC, 12, int)
#define GDMA_DEBUG_CONTROL             _IOWR(GDMA_IOC_MAGIC, 13, int)
#define GDMA_CONFIG_3D_OFFSET          _IOR(GDMA_IOC_MAGIC, 14, int)
#define GDMA_CONFIG_BLENDING           _IOR(GDMA_IOC_MAGIC, 15, int)
#define GDMA_CONFIG_VFLIP              _IOR(GDMA_IOC_MAGIC, 16, int)
#define GDMA_CONFIG_INPUTSRC_4K2K               _IOR(GDMA_IOC_MAGIC, 17, int)
#define GDMA_CONFIG_OSD_ENABLE             _IOR(GDMA_IOC_MAGIC, 18, int)
#define GDMA_CONFIG_ANDROID_LAYERS             _IOR(GDMA_IOC_MAGIC, 19, int)
#define GDMA_CONFIG_OSD1_ENABLE             _IOR(GDMA_IOC_MAGIC, 20, int)
#define GDMA_CONFIG_OSD2_ENABLE             _IOR(GDMA_IOC_MAGIC, 21, int)
#define GDMA_READ_PANEL_SETTING             _IOR(GDMA_IOC_MAGIC, 22, int)
#define GDMA_CONFIG_EMEMC               _IOR(GDMA_IOC_MAGIC, 23, int)
#define GDMA_READ_Millet3_INPUTSRC_4K2K _IOR(GDMA_IOC_MAGIC, 24, int)
#define GDMA_CONFIG_OSD4_ENABLE _IOR(GDMA_IOC_MAGIC, 25, int)
#define GDMA_CONFIG_3D_UI _IOR(GDMA_IOC_MAGIC, 26, int)
#define GDMA_CONFIG_2K1K_IN_4K2K _IOR(GDMA_IOC_MAGIC, 27, int)
#define GDMA_READ_Millet3 _IOR(GDMA_IOC_MAGIC, 28, int)
#define GDMA_READ_PANEL_RES _IOR(GDMA_IOC_MAGIC, 29, int)
#define GDMA_LOCK_VSYNC_SEM _IOR(GDMA_IOC_MAGIC, 30, int)
#define GDMA_CONFIG_BOX_SRC_SIZE _IOR(GDMA_IOC_MAGIC, 31, int)
#define GDMA_CONFIG_BOX_DST_SIZE _IOR(GDMA_IOC_MAGIC, 32, int)
#define GDMA_CONFIG_NONBLOCKING        _IOR(GDMA_IOC_MAGIC, 33, int)
#define GDMA_CONFIG_OSDCOMP_WRITEBACK_OFFLINE        _IOR(GDMA_IOC_MAGIC, 34, int)
#define GDMA_CONFIG_OSDCOMP_WRITEBACK_ONLINE        _IOR(GDMA_IOC_MAGIC, 35, int)
#define GDMA_CONFIG_QUEUEFLUSH        _IOR(GDMA_IOC_MAGIC, 36, int)
#define GDMA_CONFIG_OSDSPLIT            _IOR(GDMA_IOC_MAGIC, 37, int)
#define GDMA_CONFIG_OSD_SMOOTH_TOGGLE        _IOR(GDMA_IOC_MAGIC, 38, int)
#define GDMA_CONFIG_OSD_SHIFT			_IOR(GDMA_IOC_MAGIC, 39, int)
#define GDMA_CONFIG_OSD1_MIXER_ENABLE  _IOR(GDMA_IOC_MAGIC, 40, int)
#define GDMA_CONFIG_OSD3_MIXER_ENABLE  _IOR(GDMA_IOC_MAGIC, 41, int)
#define GDMA_CONFIG_OSD1OSD3_MIXER_ORDER  _IOR(GDMA_IOC_MAGIC, 42, int)
#define GDMA_CONFIG_OSD_DUMP			_IOR(GDMA_IOC_MAGIC, 43, int)
#define GDMA_GET_OSD_STATUS			_IOW(GDMA_IOC_MAGIC, 44, int)
#define GDMA_DROP_OSD_UPDATE			_IOR(GDMA_IOC_MAGIC, 45, int)
#define GDMA_OSD_PATTERN			_IOR(GDMA_IOC_MAGIC, 46, int)

#define GDMA_CONFIG_OSD_GAMMA_POSITION			_IOR(GDMA_IOC_MAGIC, 51, int)
#define GDMA_CONFIG_OSD_GAMMA_COLOR_MAPPING			_IOR(GDMA_IOC_MAGIC, 52, int)
#define GDMA_CONFIG_OSD_GAMMA_OP			_IOR(GDMA_IOC_MAGIC, 53, GDMA_GAMMA_OP)

#define GDMA_IOC_MAXNR                 54

#define GDMA_FBDC_LAYER_NUM       3
#define GDMA_LAYER_NUM             6


typedef enum {
	INBAND_CMD_GRAPHIC_2D_MODE = 0,
	INBAND_CMD_GRAPHIC_SIDE_BY_SIDE = 1,
	INBAND_CMD_GRAPHIC_TOP_AND_BOTTOM = 2,
} INBAND_CMD_GRAPHIC_3D_MODE;

/*
typedef union {
    uint32_t value;
    struct{
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
    };
}osdcomp_plane;
*/

typedef union {
    uint32_t value;
    struct{
		uint32_t  plane_alpha_r:9;
		uint32_t  res1:7;
		uint32_t  plane_alpha_a:9;
		uint32_t  res2:7;
    };
} osd_planealpha_ar;

typedef union {
    uint32_t value;
    struct{
		uint32_t  plane_alpha_b:9;
		uint32_t  res1:7;
		uint32_t  plane_alpha_g:9;
		uint32_t  res2:7;
    };
} osd_planealpha_gb;

typedef union {
    uint32_t value;
    struct{
		unsigned int     x_end:13;
		unsigned int     reserved_1:3;
		unsigned int     x_sta:13;
		unsigned int     reserved_0:3;
    };
} osd_clear_x;

typedef union {
    uint32_t value;
    struct{
		unsigned int     y_end:13;
		unsigned int     reserved_1:3;
		unsigned int     y_sta:13;
		unsigned int     reserved_0:3;
    };
} osd_clear_y;


typedef enum {
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
	VO_OSD_COLOR_FORMAT_YCBYCR88,   /* M-cap 422 */
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
	VO_OSD_COLOR_FORMAT_YCBYCR88_LITTLE   = 42,
	VO_OSD_COLOR_FORMAT_YCBCRA4444_LITTLE = 43,
	VO_OSD_COLOR_FORMAT_YCBCRA8888_LITTLE = 44,
	VO_OSD_COLOR_FORMAT_RGBA5551_LITTLE   = 45,
	VO_OSD_COLOR_FORMAT_RGBA4444_LITTLE   = 46,
	VO_OSD_COLOR_FORMAT_RGBA8888_LITTLE   = 47,
	VO_OSD_COLOR_FORMAT_RGB556_LITTLE     = 52,
	VO_OSD_COLOR_FORMAT_RGB655_LITTLE     = 53,
	VO_OSD_COLOR_FORMAT_RGB888_LITTLE     = 54
} VO_OSD_COLOR_FORMAT;

typedef enum {
	FBDC_COLOR_FORMAT_U8 = 0x0,
	FBDC_COLOR_FORMAT_S8 = 0x1,
	FBDC_COLOR_FORMAT_A4R4G4B4 = 0x2,
	FBDC_COLOR_FORMAT_A8R3G3B2 = 0x3,
	FBDC_COLOR_FORMAT_A1R5G5B5 = 0x4,
	FBDC_COLOR_FORMAT_R5G6B5 = 0x5,
	FBDC_COLOR_FORMAT_R5SG5SB6 = 0x6,
	FBDC_COLOR_FORMAT_U8U8 = 0x7,
	FBDC_COLOR_FORMAT_S8S8 = 0x8,
	FBDC_COLOR_FORMAT_U16 = 0x9,
	FBDC_COLOR_FORMAT_S16 = 0xa,
	FBDC_COLOR_FORMAT_F16 = 0xb,
	FBDC_COLOR_FORMAT_U8U8U8U8 = 0xc,
	FBDC_COLOR_FORMAT_S8S8S8S8 = 0xd,
	FBDC_COLOR_FORMAT_A2R10B10G10 = 0xe,
	FBDC_COLOR_FORMAT_U16U16 = 0xf,
	FBDC_COLOR_FORMAT_S16S16 = 0x10,
	FBDC_COLOR_FORMAT_F16F16 = 0x11,
	FBDC_COLOR_FORMAT_F32 = 0x12,
	FBDC_COLOR_FORMAT_F32_SIGNMASK = 0x13,
	FBDC_COLOR_FORMAT_X8U8S8S8 = 0x14,
	FBDC_COLOR_FORMAT_X8U24 = 0x15,
	FBDC_COLOR_FORMAT_U8U24 = 0x16,
	FBDC_COLOR_FORMAT_U8X24 = 0x17,
	FBDC_COLOR_FORMAT_U32 = 0x18,
	FBDC_COLOR_FORMAT_S32 = 0x19,
	FBDC_COLOR_FORMAT_SE9995 = 0x1a,
	FBDC_COLOR_FORMAT_F11F11F10 = 0x1b,
	FBDC_COLOR_FORMAT_F16F16F16F16 = 0x1c,
	FBDC_COLOR_FORMAT_U16U16U16U16 = 0x1d,
	FBDC_COLOR_FORMAT_S16S16S16S16 = 0x1e,
	FBDC_COLOR_FORMAT_F16F16F16 = 0x1f,
	FBDC_COLOR_FORMAT_U16U16U16 = 0x20,
	FBDC_COLOR_FORMAT_S16S16S16 = 0x21,
	FBDC_COLOR_FORMAT_F32F32 = 0x22,
	FBDC_COLOR_FORMAT_U32U32 = 0x23,
	FBDC_COLOR_FORMAT_S32S32 = 0x24,
	FBDC_COLOR_FORMAT_X24U8F32 = 0x25,
	FBDC_COLOR_FORMAT_X24X8F32 = 0x26,
	FBDC_COLOR_FORMAT_X24G8X32 = 0x27,
	FBDC_COLOR_FORMAT_YUV420_2PLANE = 0x36,
	FBDC_COLOR_FORMAT_YVU420_2PLANE = 0x37,
	FBDC_COLOR_FORMAT_YUV420_3PLANE = 0x38,
	FBDC_COLOR_FORMAT_YVU420_3PLANE = 0x39,
	FBDC_COLOR_FORMAT_U8U8U8 = 0x3a,
	FBDC_COLOR_FORMAT_S8S8S8 = 0x3b,
	FBDC_COLOR_FORMAT_A2F10F10F10 = 0x3c,
	FBDC_COLOR_FORMAT_F32F32F32F32 = 0x3d,
	FBDC_COLOR_FORMAT_U32U32U32U32 = 0x3e,
	FBDC_COLOR_FORMAT_S32S32S32S32 = 0x3f,
	FBDC_COLOR_FORMAT_F32F32F32 = 0x40,
	FBDC_COLOR_FORMAT_U32U32U32 = 0x41,
	FBDC_COLOR_FORMAT_S32S32S32 = 0x42,
	FBDC_COLOR_FORMAT_A2_XRBIAS_U10U10U10 = 0x43,
	FBDC_COLOR_FORMAT_O8 = 0x51,
	FBDC_COLOR_FORMAT_O8O8 = 0x52,
	FBDC_COLOR_FORMAT_R5G5B5A1 = 0x53,
	FBDC_COLOR_FORMAT_B6G5SR5S = 0x54,
	FBDC_COLOR_FORMAT_R10B10G10A2 = 0x55,
	FBDC_COLOR_FORMAT_X8S8S8U8 = 0x56,
	FBDC_COLOR_FORMAT_U24U8 = 0x57,
	FBDC_COLOR_FORMAT_F10F11F11 = 0x58,
	FBDC_COLOR_FORMAT_VYUY = 0x59,
	FBDC_COLOR_FORMAT_UYVY = 0x5a,
	FBDC_COLOR_FORMAT_YVYU = 0x5b,
	FBDC_COLOR_FORMAT_YUYV = 0x5c,
	FBDC_COLOR_FORMAT_F10F10F10A2 = 0x5d,
} FBDC_COLOR_FORMAT;

typedef enum {
	VO_GRAPHIC_OSD1 = 1,
	VO_GRAPHIC_OSD2 = 2,
	VO_GRAPHIC_OSD3 = 3,
	VO_GRAPHIC_OSD4 = 4,
	VO_GRAPHIC_OSD5 = 5,
	VO_GRAPHIC_INVALID = 6,
} VO_GRAPHIC_PLANE;

typedef enum {
    ARGB8888,
    RBG888,
    RTKCOMPRESS,
} WB_TYPE;

typedef enum {
    SRC_NORMAL,
    SRC_FBDC,
    SRC_MOUSE_NORMAL,
    SRC_MOUSE_FBDC,
} SOURCE_TYPE;


typedef struct {
    /* for online write-back */
    unsigned int wbAddr;
    WB_TYPE wbType;
} ONLINE_WRRITEBACK_STRUCT;


typedef struct {
    SOURCE_TYPE src_type;
    VO_OSD_COLOR_FORMAT format;
    FBDC_COLOR_FORMAT fbdc_format;
    unsigned int context;
    unsigned int key_en;
    int colorkey;          /* -1: disable colorkey */
    int alpha;             /*  0: disable constant alpha */
    unsigned int x ;/* src */
    unsigned int y ;/* src */
    unsigned int width ;/* src */
    unsigned int height ;/* src */
    unsigned int address;   /* for normal source */
    unsigned int pitch;
    int dst_x;/* dst depends on source UI */
    int dst_y;/* dst depends on source UI */
    int dst_width;/* dst */
    int dst_height;/* dst */
    INBAND_CMD_GRAPHIC_3D_MODE picLayout;
    int handle;
    osd_planealpha_ar plane_ar;     /* fbdc only 8 bits, mixer has 9 bits */
    osd_planealpha_gb plane_gb;     /* fbdc only 8 bits, mixer has 9 bits */
    osd_clear_x clear_x;
    osd_clear_y clear_y;
    int show;					/* 1: show this plane. 0:hide */
    u64 syncstamp;
	unsigned int compressed;	/*  indicate this layer needs to do compression for OSD compress */
    unsigned int decompress;	/*  for decompress picture */
	int scale_factor;	/* layer scale factor based on panel size & fb size */
    u_char paletteIndex;
} GDMA_LAYER_OBJECT;



typedef struct {
    int layer_num;
    GDMA_LAYER_OBJECT layer[GDMA_LAYER_NUM];
	int cookie;

    /* for offline write-back */
    WB_TYPE wbType;
	unsigned char comp_done;		/*  indicate the OSD compress done 1: done 0: wait or on-going */
	unsigned int wb_img_addr;		/*  physical address for OSD compress output address 0: not write-back, otherwise do write-back function */
} GRAPHIC_LAYERS_OBJECT;

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;
    unsigned int phyaddr;
    unsigned int pitch;
    unsigned int fmt;
    char fname[128];
} OSD_DUMP_STRUCT;

typedef struct {
    unsigned int en;
    unsigned int osdn;
    unsigned int color;
} OSD_PATTERN;


int GDMA_ReceiveGraphicLayers(GRAPHIC_LAYERS_OBJECT *data);
#endif/* _GDMA_EXPORT_USER_H_ */
