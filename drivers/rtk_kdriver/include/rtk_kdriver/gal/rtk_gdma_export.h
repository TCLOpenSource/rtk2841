#ifndef _GDMA_EXPORT_H_
#define _GDMA_EXPORT_H_

#include "rtk_gdma_export_user.h"
#include <linux/types.h>


/* #define USING_GDMA_VSYNC */

#define MAX_SEG_NUM 4
#define MAX_OSD_NUM 4 /* note if osd number is 3 , need to set 4*/

#define FOURK_W (3840)
#define TWOK_H (2160)

#define TWOK_W (1920)
#define ONEK_H (1080)


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define GDMA_MODIFY_POSITION      1
#define GDMA_MODIFY_COLORFMT      2
#define GDMA_MODIFY_COLORKEY      4
#define GDMA_MODIFY_ALPHA         8
#define GDMA_MODIFY_SRC_LOCATION 16
#define GDMA_MODIFY_STORAGE_TYPE 32


#define VIDEO_W_640 640
#define VIDEO_W_720 720
#define VIDEO_W_960 960
#define VIDEO_W_1280 1280
#define VIDEO_W_1920 1920
#define VIDEO_W_3840 3840

#define GDMA_SUCCESS  0
#define GDMA_FAIL    -1
#define COMP_BUF_FULL -2
#define COMP_HW_USED -3
#define COMP_PICOBJ_INFO_ERROR -4
#define COMP_ALLOC_NOT_READY  -5
#define COMP_BUF_WORK_FULL -6
#define COMP_INT_NOT_READY -7




typedef enum _SEG_NUMBER {
    INIT_PIXEL_SEG = -1,
    ONE_PIXEL_SEG = 0,
    TWO_PIXEL_SEG,
    FOUR_PIXEL_SEG,
    NOT_DEFIEND_PIXEL_SEG
} SEG_NUMBER;

typedef enum _COMP_BUFF_IDX {
    COMP_IDX_INIT = -1,
    COMP_BUFF0 = 0,
    COMP_BUFF1,
    COMP_BUFF2,
    MAX_COMP_BUFF = 4,  /*  up to 4 buffers */
} COMP_BUFF_IDX;

typedef enum {
    C0  = 0,    /*  bottom layer */
    C1,
    C2,
    C3,
    C4,
    C5,
} E_BLEND_ORDER;

typedef enum {
    GAMMA_LOC_C0  = 0,    /*  bottom layer */
    GAMMA_LOC_C1,
    GAMMA_LOC_C2,
    GAMMA_LOC_C3,
    GAMMA_LOC_B0_C0_C1,
    GAMMA_LOC_B1_C0_C1_C2,
    GAMMA_LOC_B2_C0_C1_C2_C3,
} GAMMA_LOC_POSITION;

typedef enum {
	GDMA_DBG_CMD_SET_H_SHIFT = 0,
	GDMA_DBG_CMD_SET_V_SHIFT = 1,
	GDMA_DBG_CMD_OSD_DUMP = 2,
	GDMA_DBG_CMD_OSD_DUMP_EX = 3,
	GDMA_DBG_CMD_OSD_DROP = 4,
	GDMA_DBG_CMD_OSD_PATTERN = 5,
	GDMA_DBG_CMD_OSD_VFLIP = 6,
	GDMA_DBG_CMD_OSD_CTRL = 7,
	GDMA_DBG_CMD_OSD_SWAP = 8,
	GDMA_DBG_CMD_OSD_CAP2MEM = 9,
	GDMA_DBG_CMD_SHOW_INFO = 10,
	GDMA_DBG_CMD_OSD_GET_INFO = 11,
	GDMA_DBG_CMD_OSD_CTRL_EN = 12,
	GDMA_DBG_CMD_NUMBER
} GDMA_DBG_CMD_INDEX_T;



typedef enum {
    GDMA_SET_DISPLAY_MODE
} GDMA_CMD_TYPE;

typedef enum {
    VO_GRAPHIC_BLOCK,
    VO_GRAPHIC_SEQUENTIAL
} VO_GRAPHIC_STORAGE_MODE;


typedef enum {
    VIDEO_480P = 480, /* 640 * 480*/
    VIDEO_540P = 540, /* 960 * 540*/
    VIDEO_576P = 576, /* 720 * 576*/
    VIDEO_720P = 720, /* 1280 * 720*/
    VIDEO_1080P = 1080, /* 1920 * 1080*/
    VIDEO_2160P = 2160, /* 3840 * 2160*/
    VIDEO_USERDEFINED = 0 /* gdma->dispWin */
} ENUM_VIDEO_SYSTEM;

typedef enum {
    VO_OSD_COLOR_RGB,
    VO_OSD_COLOR_BGR,
    VO_OSD_COLOR_GRB,
    VO_OSD_COLOR_GBR,
    VO_OSD_COLOR_RBG,
    VO_OSD_COLOR_BRG
} VO_OSD_RGB_ORDER;

typedef enum {
    GDMA_PLANE_OSD1 = 1,
    GDMA_PLANE_OSD2 = 2,
    GDMA_PLANE_OSD3 = 3,
    GDMA_PLANE_MAXNUM = 4,
    GDMA_PLANE_NONE
} GDMA_DISPLAY_PLANE;

typedef enum _COMP_LAYER {
    OSD1_1 = 0,
    OSD1_2,
    OSD1_3,
    OSD1_4,
    OSD1_5,
    MAX_COMP_VIRTUAL_LAYERS,
} COMP_LAYER;



typedef struct {
    int displayEachPic;    /* default is 1: display each picture, 0: display latest picture */
} GDMA_DISPLAY_MODE_STRUCT;

typedef struct {
    short x;        /* the x coordinate of the upper-left corner */
    short y;        /* the y coordinate of the upper-left corner */
    u_short width;    /* width  of rectangle */
    u_short height;   /* height of rectangle */
} VO_RECTANGLE;

typedef struct {
    unsigned int cm_x_offset;
    unsigned int cm_y_offset;
    unsigned int cm_z_offset;
    unsigned int cm_k11;
    unsigned int cm_k12;
    unsigned int cm_k13;
    unsigned int cm_k21;
    unsigned int cm_k22;
    unsigned int cm_k23;
    unsigned int cm_k31;
    unsigned int cm_k32;
    unsigned int cm_k33;
    unsigned int cm_r_offset;
    unsigned int cm_g_offset;
    unsigned int cm_b_offset;
} GAMMA_COLOR_MAPPING_DATA;

typedef struct {
    VO_GRAPHIC_PLANE       plane;
    VO_RECTANGLE           srcWin;
    VO_RECTANGLE           dispWin;
    u_char                 go;
} VIDEO_RPC_VOUT_CONFIG_GRAPHIC_CANVAS;



typedef struct {
    VO_GRAPHIC_PLANE            plane;
    VO_RECTANGLE                winPos;
    VO_OSD_COLOR_FORMAT         colorFmt;
    VO_OSD_RGB_ORDER            rgbOrder;
    int                         colorKey;
    u_char                      compressed;  /*  indicate this picture needs to decompress */
    u_char                      alpha;
    u_char                      reserved;
} VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN;


typedef struct {
    VO_GRAPHIC_PLANE             plane;
    u_char                       winID;
    u_char                       reqMask;/* position,format,colorkey,alpha,src location */
    VO_RECTANGLE                 winPos;
    VO_OSD_COLOR_FORMAT          colorFmt;
    VO_OSD_RGB_ORDER             rgbOrder;
    int                          colorKey;
    u_char                       alpha;
    VO_GRAPHIC_STORAGE_MODE      storageMode;/* Block,Sequentail:no need */
    u_char                       paletteIndex;
    u_char                       compressed;  /*  indicate this picture needs to decompress */
    u_char                       interlace_Frame;
    u_char                       bottomField;
    u_short                      startX[4];
    u_short                      startY[4];
    u_short                      imgPitch[4];
    long                         pImage[4];
    u_char                       reserved;
    u_char                       go;
} VIDEO_RPC_VOUT_MODIFY_GRAPHIC_WIN;


typedef struct {
    VO_GRAPHIC_PLANE             plane;
    u_short                      winID;
    VO_GRAPHIC_STORAGE_MODE      storageMode;
    u_char                       paletteIndex;
    u_char                       compressed;  /*  indicate this picture needs to decompress */
    u_char                       interlace_Frame;
    u_char                       bottomField;
    u_short                      startX[4];
    u_short                      startY[4];
    u_short                      imgPitch[4];
    long                         pImage[4];
    u_char                       reserved;
    u_char                       go;
} VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN;


typedef struct {
    VO_GRAPHIC_PLANE            plane;
    u_short                     winID;
    u_char                      go;
} VIDEO_RPC_VOUT_HIDE_GRAPHIC_WIN;


typedef struct {
    VO_GRAPHIC_PLANE            plane;
    u_short                     winID;
    u_char                      go;
} VIDEO_RPC_VOUT_DELETE_GRAPHIC_WIN;

typedef struct {
    u_char                      paletteIndex;
    long                        pPalette;
} VIDEO_RPC_VOUT_CONFIG_OSD_PALETTE;


typedef struct {
    long                         x;
    long                         y;
    long                         width;
    long                         height;
    VO_OSD_COLOR_FORMAT          colorFmt;
    VO_OSD_RGB_ORDER             rgbOrder;
    long                         colorKey;
    long                         alpha;
    VO_GRAPHIC_STORAGE_MODE      storageMode;
    long                         paletteIndex;
    long                         compressed;
    long                         interlace_Frame;
    long                         bottomField;
    long                         startX[4];
    long                         startY[4];
    long                         imgPitch[4];
    long                         pImage[4];
    long                         reserved0;
    long                         reserved1;
} VIDEO_RPC_VOUT_DISPLAY_GRAPHIC_WIN;

typedef struct {
    VO_GRAPHIC_PLANE            plane;
    u_char                      osdNum;
    long                        pGraphic;
} VIDEO_RPC_VOUT_DISPLAY_GRAPHIC;

typedef struct {
    VO_GRAPHIC_PLANE       plane;            /* -1 represent to apply to all plane */
    u_char                 closeToViewer;    /* 0: close to viewer, 1: away from viewer */
    u_char                 offset;           /* pixel number to offset */
} CONFIG_3D_OFFSET_STRUCT;


typedef struct {
    char blendingOSD1En;                 /* -1: don't change, 1: blending, 0: overlay */
    char blendingOSD2En;
    char blendingCursorEn;
} CONFIG_BLENDING_STRUCT;

typedef struct {
    char osdSplitEn;                 /* 1: on, 0: off */
    char osdSplitHeaderEn;         /* 1: on, 0: off */
    int header_h_sta;                 /* header starting position in horizontal dimension */
    int header_v_sta;                 /* line number for header */
    unsigned int emptyPixel;        /* [31:24]:A, [23:16]:R, [15:8]:G, [7:0]:B */
    unsigned int osdSplitHeader[24]; /* 24 pixels header */
	char osdTimingSel;				/* 0: frame_sync, 1: free-run */
} CONFIG_OSDSPLIT_STRUCT;

typedef struct {
	VO_GRAPHIC_PLANE plane;
	char shift_h_enable;			  /* 1: on, 0: off */
	char shift_v_enable;		   	  /* 1: on, 0: off */
	int h_shift_pixel;				  /* position value: shift right, negative: shfit left */
	int v_shift_pixel;				  /* position value: shift down, negative: shfit up */

	int para_h_N;				          /* para N */
	int para_h_K;				          /* para K */
	int para_v_N;				          /* para N */
	int para_v_K;				          /* para K */
	int Canvas_H;				          /* Canvas_H */
	int Canvas_V;				          /* Canvas_V */
} CONFIG_OSDSHIFT_STRUCT;


typedef struct {
    u64 syncstamp;                        /*  syncstamp number */
    uint matchNum;                        /*  how many osd plane has the same syncstamp picture */
    uint matchPlane[GDMA_PLANE_MAXNUM];/*  indicate which osd plane has the same syncstamp picture */
} GDMA_PIC_MATCH_SYNCSTAMP;


typedef struct {
    GDMA_DISPLAY_PLANE plane;
    unsigned char      zeroBuffer;   /* 1: flush all buffer if plane is NONE */
} GDMA_DISPLAY;

typedef struct {
    GDMA_DISPLAY_PLANE plane;
    VO_RECTANGLE       dispWin;
} GDMA_CONFIG_DISP_WIN;

typedef struct {
    SOURCE_TYPE src_type;
    VO_OSD_COLOR_FORMAT format;
    FBDC_COLOR_FORMAT fbdc_format;
    unsigned int context;
    unsigned int key_en;
    int colorkey;          /* -1: disable colorkey */
    int alpha;             /*  0: disable constant alpha */
    unsigned int x;/* src */
    unsigned int y;/* src */
    unsigned int width;/* src */
    unsigned int height;/* src */
    unsigned int address;
    unsigned int pitch;
    unsigned int seg_addr[MAX_SEG_NUM];/* for compress and decompress use */
    INBAND_CMD_GRAPHIC_3D_MODE picLayout;
    unsigned int compressed;	/*  indicate this layer needs to do compression for OSD compress */
    WB_TYPE wbType;
    SEG_NUMBER seg_num;
    COMP_BUFF_IDX current_comp_idx;     /* for compress use */
    VO_GRAPHIC_PLANE comp_plane;        /*  compose plane */
    VO_GRAPHIC_PLANE plane;              /*  final display plane */
    int dst_x;/* dst */
    int dst_y;/* dst */
    int dst_width;/* dst */
    int dst_height;/* dst */
    int layer_used;/* for compress */
    osd_planealpha_ar plane_ar;     /*  fbdc only 8 bits, mixer has 9 bits */
    osd_planealpha_gb plane_gb;     /*  fbdc only 8 bits, mixer has 9 bits */
    osd_clear_x clear_x;
    osd_clear_y clear_y;
    int show;					/* 1: show this plane. 0:hide */
    uint decompress;	/*  for continue compress test, indicate this layer needs to decompress for OSD compression or GDMA */
    unsigned int paletteformat; /* YVUA-->0  BGRA-->1 */
    u_char paletteIndex;
    VO_OSD_RGB_ORDER rgb_order;
    GDMA_PIC_MATCH_SYNCSTAMP syncInfo;
    E_BLEND_ORDER offlineOrder;   /*  for offline blend use */
	int scale_factor;	/* layer scale factor based on panel size & fb size */
	int isFromOffline;					/* image data from offline */
} GDMA_PICTURE_OBJECT;

/*
*	for each OSD HW
*/
typedef struct {
    int fbdc_num;
    int normal_num;
    E_BLEND_ORDER onlineOrder;          /*  for final display use */
    GDMA_PICTURE_OBJECT fbdc[3];        /*  for FBDC */
    GDMA_PICTURE_OBJECT normal[1];      /*  for Mouse or Normal OSD */
} COMPOSE_PICTURE_OBJECT;


typedef struct {
    int layer_num;  /* indicate how many graphic layer (OSD HW) after GDMA driver arranged */
    COMPOSE_PICTURE_OBJECT layer[GDMA_PLANE_MAXNUM];
	int cookie;
} PICTURE_LAYERS_OBJECT;


typedef struct {
	unsigned int type;
	unsigned int osdn;
	unsigned int en;
	unsigned int clr;
	unsigned int c[6];
	OSD_DUMP_STRUCT capinfo;
	OSD_DUMP_STRUCT stchinfo;
} KADP_HAL_GAL_CTRL_T;


/*============= buffer management ===============*/
typedef struct VP_BUFFER {
    char         usage;
    unsigned int addr;
    unsigned int pitch;
} VP_BUFFER;

void        VP_InitPool     (VP_BUFFER *pool, int pool_size, unsigned int *buffer_addr, unsigned int *buffer_pitch);
VP_BUFFER *VP_AllocateMem  (VP_BUFFER *pool, int pool_size);
void        VP_RegisterMem  (VP_BUFFER *buf);
void        VP_ReleaseMem   (VP_BUFFER *buf);

void getDispSize(VO_RECTANGLE *disp_rec);

int GDMA_AddCallBackFunc        (void (*fp)(void *, bool));
int GDMA_AddCookieCallBackFunc        (void (*fp)(void *, int));

int GDMA_Display                (GDMA_DISPLAY *);
int GDMA_OSD1OnTop              (bool);
int GDMA_Config3D               (bool);
int GDMA_ConfigVFlip            (bool);
int GDMA_Config3DOffset         (CONFIG_3D_OFFSET_STRUCT *);
int GDMA_ConfigBlending         (CONFIG_BLENDING_STRUCT *);
int GDMA_ConfigureDisplayWindow (GDMA_CONFIG_DISP_WIN *);
int GDMA_ReceivePicture         (PICTURE_LAYERS_OBJECT *);
int GDMA_ReceiveCmd             (GDMA_CMD_TYPE, void *);
int GDMA_ConfigInputSrc_4k2k (bool);
int GDMA_Config3dUi (bool flag);
int GDMA_ConfigBoxSrcSize (int size);
int GDMA_ConfigBoxDstSize (int size);
int GDMA_ConfigOSDEnable (bool);
int GDMA_ConfigOSDxEnable (GDMA_DISPLAY_PLANE disPlane, bool flag);
int GDMA_ConfigOSDxMixerEnableNoDelay(GDMA_DISPLAY_PLANE disPlane, bool flag);
int GDMA_ConfigOSD1OSD3MixerOrder(bool flag);
void GDMA_ISR_export (void);
bool GDMA_UseMilletDisp(void);
bool GDMA_UseMilletInputSrc4k2k(void);
int GDMA_GetPanelPixelMode(void);
int GDMA_ConfigPRLeftOnly(bool);
int GDMA_Lock_Vsync_Sem(void);
void fwif_color_set_scaleosd_sharpness_driver(unsigned char src_index, unsigned char scale_factor);
int GDMA_ConfigNonBlocking (bool);
int GDMA_Debug(KADP_HAL_GAL_CTRL_T* data);
unsigned int GDMA_gpuWrap_std_suspend(unsigned int phyAddr, unsigned int size);
void GDMA_gpuWrap_std_resume(unsigned int phyAddr, unsigned int virtAddr, unsigned int size);
int GDMA_ConfigGammaPosition(unsigned int data);
int GDMA_ConfigGammaColorMapping(GAMMA_COLOR_MAPPING_DATA *data);
int GDMA_GammaOperation(GDMA_GAMMA_OP* data);
/*===============================================*/
#endif
