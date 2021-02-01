#ifndef _GDMA_DRIVER_H_
#define _GDMA_DRIVER_H_

#include <rbus/gdma_reg.h>
#include <rbus/osdovl_reg.h>
#include <rbus/osd_sr_reg.h>


#include "rtk_gdma_export.h"
#include "rtk_osd_sr_driver.h"

#define GDMA_IRQ IRQ_DDOMAIN


#define USR_WORKQUEUE_UPDATE_BUFFER

/*2017/3/17, copy ppoverlay_osd1_3d_offset_RBUS to here
  and rename to  ppoverlay_3D_OFFSET.

  Why? cuz' we don't need member name has osd number, such as left_osd1_offset, left_osd2_offset...
  ESPECIALLY in this case...only name is different.
 */
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_offset:11;
        RBus_UInt32  left_dir:1;
        RBus_UInt32  right_offset:11;
        RBus_UInt32  right_dir:1;
        RBus_UInt32  res1:8;
    };
}ppoverlay_3D_OFFSET;

/*
*	Test code for GDMA & OSD COMP
*/
/*#define _TEST_CODE_GDMA_*/
/*#define _TEST_CODE_OSDCOMP_		4*/


#include "rtk_gdma_export.h"

#if defined(_TEST_CODE_GDMA_) || defined(_TEST_CODE_OSDCOMP_)
/*#define OSD_SR_DEBUG*/
/*#define GDMA_DEBUG_HWC*/
/*#define GDMA_DEBUG*/
#endif

#ifdef GDMA_DEBUG_HWC
#define GD_PRINT_2(s, args...) pr_debug(s, ## args)
#else
#define GD_PRINT_2(s, args...)
#endif

/*#ifndef CONFIG_ANDROID*/
#if 1	/* enable vsync wait mechanism */
#define TRIPLE_BUFFER_SEMAPHORE
#endif
/*#define GDMA_REPEAT_LOG*/

#ifdef GDMA_DEBUG
#define DBG_PRINT(s, args...) pr_debug(s, ## args)
#else
#define DBG_PRINT(s, args...)
#endif

#ifdef OSD_SR_DEBUG
#define DBG_SR_PRINT(s, args...) pr_debug(s, ## args)
#else
#define DBG_SR_PRINT(s, args...)
#endif

#define GD_ERR(fmt, args...) printk(KERN_ERR"[GDMA] ERR:" fmt, __FUNCTION__, __LINE__, ## args);



#ifndef GDMA_MAJOR
#define GDMA_MAJOR 0   /* dynamic major by default */
#endif

#ifndef GDMA_NR_DEVS
#define GDMA_NR_DEVS 1
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef ABS
#define ABS(x)   ((x) >= 0 ? (x) : -(x))
#endif

/* online/offline switch indicator */
typedef enum {
    ONLINE_STATE = 0,
    OFFLINE_STATE = 1,
    ON_2_OFFLINE_SWITCH = 2,
    OFF_2_ONLINE_SWITCH = 3,
} GDMA_ONOFF_SWITCH;


/* total line buffer size */
#define GDMA_TOTAL_LB_SIZE	14

#define GDMA_MAX_PIC_Q_SIZE        32 /* 8 */

#define Warning(format, ...)      \
{\
  static unsigned int  LastPrintPTS;			\
  static unsigned int  WarningCount;			\
  unsigned int	     CurrentPTS = (rtd_inl(MIS_SCPU_CLK90K_LO_reg));	\
  if (CurrentPTS - LastPrintPTS > 90090)	{ \
    printk("[%d]:", WarningCount+1);	\
    printk(format, ##__VA_ARGS__);	\
    LastPrintPTS = CurrentPTS;	\
    WarningCount = 0;		\
  }	\
  else	\
    WarningCount++;	\
}


/* data structure for GDMA */
#define GDMA_MAX_NUM_OSD_WIN 2
#define GDMA_MAX_NUM_CLUT    4

typedef struct {
    unsigned short reserved:6;
    unsigned short hwTurnOff:1;
    unsigned short dispOn:1; /* display Graphic at a time is turned-on */
    unsigned short en:1;
    unsigned short index:1;
    unsigned short newUpdate:1;
    unsigned short wn:5;
} GDMA_CONTROL;


typedef struct {
    unsigned char  en;
    VO_RECTANGLE   srcWin;
    VO_RECTANGLE   dispWin;
} GDMA_CANVAS;


typedef struct {
    unsigned int reserved:6;
    unsigned int id:8;
    unsigned int previd:8;
    unsigned int nextid:8;
    unsigned int drawn:1;
    unsigned int occupied:1;
} GDMA_WIN_CTRL;


typedef struct _GDMA_WIN_NEXT_ADDR {
    unsigned int addr:31;
    unsigned int last:1;
} GDMA_WIN_NEXT_ADDR;

typedef struct _GDMA_WIN_XY {
    unsigned int x:16;
    unsigned int y:16;
} GDMA_WIN_XY;


typedef struct _GDMA_WIN_WH {
    unsigned int width:16;
    unsigned int height:16;
} GDMA_WIN_WH;


typedef struct {
    unsigned int type:5;
    unsigned int reserved2:1;
    unsigned int IMGcompress:1;
    unsigned int compress:1;
    unsigned int keepPreCLUT:1;
    unsigned int littleEndian:1;
    unsigned int clut_fmt:1;
    unsigned int reserved1:5;
    unsigned int alpha:8;
    unsigned int objType:1;
    unsigned int reserved0:1;
    unsigned int alphaEn:1;
    unsigned int alphaType:1;
    unsigned int rgbOrder:3;
    unsigned int extendMode:1;
} GDMA_WIN_ATTR;


typedef struct _GDMA_WIN_KEY {
    unsigned int key:24;
    unsigned int keyEn:1;
    unsigned int reserved:7;
} GDMA_WIN_KEY;


typedef struct _GDMA_WIN_INIT {
    unsigned int objXoffset:16;
    unsigned int objYoffset:16;
} GDMA_WIN_INIT;

typedef struct _FBDC_PREBLEND_ATTR {
    unsigned int alpha_2nd:8;
    unsigned int alpha_1st:8;
    unsigned int pre_blend_c2_sel:2;
    unsigned int pre_blend_c1_sel:2;
    unsigned int pre_blend_c0_sel:2;
    unsigned int plane_alpha_c2:1;
    unsigned int plane_alpha_c1:1;
    unsigned int plane_alpha_c0:1;
    unsigned int const_a_3rd:1;
    unsigned int const_a_2nd:1;
    unsigned int const_a_1st:1;
    unsigned int fbdc_3rd_en:1;
    unsigned int fbdc_2nd_en:1;
    unsigned int fbdc_1st_en:1;
    unsigned int pre_blend_en:1;
} FBDC_PREBLEND_ATTR;

typedef struct _FBDC_FORMAT {
    unsigned int fbdc_fmt_3rd:7;
    unsigned int cdc_cor_3rd:1;
    unsigned int fbdc_fmt_2nd:7;
    unsigned int cdc_cor_2nd:1;
    unsigned int fbdc_fmt_1st:7;
    unsigned int cdc_cor_1st:1;
    unsigned int alpha_3rd:8;
} FBDC_FORMAT;

typedef struct _FBDC_ALPHA_ARGB {
    unsigned int reserved3:8;
    unsigned int argb_order_3rd:5;
    unsigned int alpha_type_3rd:1;
    unsigned int ext_3rd:1;
    unsigned int reserved2:1;
    unsigned int argb_order_2nd:5;
    unsigned int alpha_type_2nd:1;
    unsigned int ext_2nd:1;
    unsigned int reserved1:1;
    unsigned int argb_order_1st:5;
    unsigned int alpha_type_1st:1;
    unsigned int ext_1st:1;
    unsigned int reserved0:1;
} FBDC_ALPHA_ARGB;

typedef struct _FBDC_BLEND_FACTOR {
    unsigned int k4_blend:6;
    unsigned int reserved3:2;
    unsigned int k3_blend:6;
    unsigned int reserved2:2;
    unsigned int k2_blend:6;
    unsigned int reserved1:2;
    unsigned int k1_blend:6;
    unsigned int reserved0:2;
} FBDC_BLEND_FACTOR;


typedef struct _FBDC_TOTAL_TILE {
    unsigned int x_total_tile:16;
    unsigned int y_total_tile:16;
} FBDC_TOTAL_TILE;

typedef struct _FBDC_PIC_PIXEL_XY {
    unsigned int x_pic_pixel:16;
    unsigned int y_pic_pixel:16;
} FBDC_PIC_PIXEL_XY;

typedef struct _FBDC_START_XY {
    unsigned int x_sta:16;
    unsigned int y_sta:16;
} FBDC_START_XY;

typedef struct _FBDC_PLANEALPHA {
    unsigned int     plane_alpha_b:8;
    unsigned int     plane_alpha_g:8;
    unsigned int     plane_alpha_r:8;
    unsigned int     plane_alpha_a:8;
} FBDC_PLANEALPHA;



typedef struct {
    GDMA_WIN_NEXT_ADDR nxtAddr;
    /* Window Region */
    GDMA_WIN_XY       winXY;
    GDMA_WIN_WH       winWH;
    /* Window Attribute */
    GDMA_WIN_ATTR     attr;
    unsigned int      CLUT_addr;
    GDMA_WIN_KEY      colorKey;
    union {
		unsigned int      top_addr;    /* top or progressive OSD start address (sequential) or index (block mode) */
		unsigned int      fbdc1_addr;
    };
    union {
		unsigned int      bot_addr;    /* bottom OSD start address (sequential) or index (block mode) */
		unsigned int      fbdc2_addr;
    };
    union {
		unsigned int      pitch;
		unsigned int      fbdc3_addr;
    };
    GDMA_WIN_INIT     objOffset;
    FBDC_PREBLEND_ATTR      fbdc_attr;
    FBDC_FORMAT             fbdc_format;
    FBDC_ALPHA_ARGB         fbdc_alpha_argb;
    FBDC_BLEND_FACTOR       fbdc_blend1st;
    FBDC_BLEND_FACTOR       fbdc_blend2nd;
    FBDC_TOTAL_TILE         fbdc1_totaltile;
    FBDC_PIC_PIXEL_XY       fbdc1_xy_pixel;
    FBDC_START_XY           fbdc1_xy_sta;
    FBDC_START_XY           fbdc1_preblend_xy_sta;
    FBDC_PLANEALPHA         fbdc_plane_alpha_c0;
    FBDC_TOTAL_TILE         fbdc2_totaltile;
    FBDC_PIC_PIXEL_XY       fbdc2_xy_pixel;
    FBDC_START_XY           fbdc2_xy_sta;
    FBDC_START_XY           fbdc2_preblend_xy_sta;
    FBDC_PLANEALPHA         fbdc_plane_alpha_c1;
    FBDC_TOTAL_TILE         fbdc3_totaltile;
    FBDC_PIC_PIXEL_XY       fbdc3_xy_pixel;
    FBDC_START_XY           fbdc3_xy_sta;
    FBDC_START_XY           fbdc3_preblend_xy_sta;
    FBDC_PLANEALPHA         fbdc_plane_alpha_c2;	/* 30 words for osd win info. */
    unsigned int reserved[2];

    /*  below size should be multiple of 16 s.t every element of GDMA_WIN array can be located at 16 byte-aligned address */
    GDMA_WIN_CTRL     ctrl __attribute__((aligned(16)));
    unsigned int      srcImg[2];
    unsigned short    srcPitch[2];
    unsigned short    dst_x;
    unsigned short    dst_y;
    unsigned int      dst_width;
    unsigned int      dst_height;
    bool used;
} GDMA_WIN;


typedef struct {
    unsigned char     OSD_topid ;
    unsigned char     numOSDwins;
    GDMA_CONTROL      OSD_ctrl;
    GDMA_CANVAS       OSD_canvas;
    GDMA_WIN          OSDwin[GDMA_MAX_NUM_OSD_WIN] __attribute__((aligned(16)));
    GDMA_WIN          OSDwinBuf[2][GDMA_MAX_NUM_OSD_WIN] __attribute__((aligned(16)));
} GDMA_PLANE;

typedef struct {
    unsigned char reserved:7;
    unsigned char obsolete:1;
} GDMA_PIC_STATUS;


typedef struct {
    /*  in GDMA */
	line_buffer_end_RBUS lb_end_reg;
	osd1_ctrl_RBUS osd_ctrl_reg;
	osd1_RBUS osd_reg;
	osd1_wi_RBUS osd_wi_reg;
	osd1_wi_3d_RBUS osd_wi_3d_reg;
	osd1_size_RBUS osd_size_reg;
	osd1_clear1_RBUS osd_clear1_reg;
	osd1_clear2_RBUS osd_clear2_reg;

	/*  in osd_sr */
	osd_sr_1_scaleup_ctrl0_RBUS osd_sr_scaleup_ctrl0_reg;
	osd_sr_1_scaleup_ctrl1_RBUS osd_sr_scaleup_ctrl1_reg;
	osd_sr_1_h_location_ctrl_RBUS osd_sr_h_location_ctrl_reg;
	osd_sr_1_v_location_ctrl_RBUS osd_sr_v_location_ctrl_reg;
	osd_sr_1_ctrl_RBUS osd_sr_ctrl_reg;
	osd_sr_1_filter_ctrl0_RBUS osd_sr_filter_ctrl_reg;
	osd_sr_1_gainy_ctrl0_RBUS osd_sr_gainy_ctrl0_reg;
	osd_sr_1_gainmap_ctrl0_RBUS osd_sr_gainmap_ctrl_reg;
	osd_sr_osd_bypass_3_location_ctrl_RBUS osd_bypass_location_ctrl_reg;

	/*  in Mixer */
	osdovl_mixer_layer_sel_RBUS mixer_layer_sel_reg;
	osdovl_mixer_c0_plane_alpha1_RBUS mixer_c0_plane_alpha1_reg;
	osdovl_mixer_c0_plane_alpha2_RBUS mixer_c0_plane_alpha2_reg;
	osdovl_mixer_c1_plane_alpha1_RBUS mixer_c1_plane_alpha1_reg;
	osdovl_mixer_c1_plane_alpha2_RBUS mixer_c1_plane_alpha2_reg;
	osdovl_mixer_c2_plane_alpha1_RBUS mixer_c2_plane_alpha1_reg;
	osdovl_mixer_c2_plane_alpha2_RBUS mixer_c2_plane_alpha2_reg;
	osdovl_mixer_c3_plane_alpha1_RBUS mixer_c3_plane_alpha1_reg;
	osdovl_mixer_c3_plane_alpha2_RBUS mixer_c3_plane_alpha2_reg;
} GDMA_REG_CONTENT;


typedef struct {
    GDMA_PIC_STATUS      status;
    unsigned short       repeatCnt;
    unsigned int         context;
    SEG_NUMBER seg_num;
    COMP_BUFF_IDX current_comp_idx;
    GDMA_WIN             OSDwin    __attribute__((aligned(16)));
    GDMA_WIN             OSDwin3D  __attribute__((aligned(16)));
    GDMA_DISPLAY_PLANE plane;
    osd_planealpha_ar plane_ar;     /*  fbdc only 8 bits, mixer has 9 bits */
    osd_planealpha_gb plane_gb;     /*  fbdc only 8 bits, mixer has 9 bits */
    osd_clear_x clear_x;
    osd_clear_y clear_y;
	int cookie;
    GDMA_PIC_MATCH_SYNCSTAMP syncInfo;
    int show;					/* 1: show this plane. 0:hide */
    GDMA_REG_CONTENT reg_content;   /*  pre-calculate by workqueue and store */
    E_BLEND_ORDER onlineOrder;          /*  for final display use */
	int isFromOffline;					/* image data from offline */
	int scale_factor;	/* layer scale factor based on panel size & fb size */

    int workqueueDone;     /*  1: register value was ready 0: Not ready */
    int workqueueIdx;
} GDMA_PIC_DATA;

typedef struct {
    unsigned int reserved:14;
    unsigned int zeroBuffer:1;
    unsigned int displayEachPic:1;
    unsigned int OSD1onTop:1;
    unsigned int enable3D:1;
    unsigned int forceUpdate:1;
    unsigned int updateOSD1Offset:1;
    unsigned int updateOSD2Offset:1;
    unsigned int updateOSD3Offset:1;
    unsigned int updateOSD4Offset:1;
    unsigned int updateOSD5Offset:1;
    unsigned int enableOSD1Offset:1;
    unsigned int enableOSD2Offset:1;
    unsigned int enableOSD3Offset:1;
    unsigned int enableOSD4Offset:1;
    unsigned int enableOSD5Offset:1;
    unsigned int enableVFlip:1;
    unsigned int enable3D_PR_SGMode:1; /*  0: Enable 3D SG function; 1: Enable 3D PR function */
    unsigned int enableNonBlocking:1;

    unsigned int sync[GDMA_PLANE_MAXNUM];
    unsigned int osdfirstEn[GDMA_PLANE_MAXNUM];
    unsigned int osdEn[GDMA_PLANE_MAXNUM];
} GDMA_STATUS;



typedef struct {
    struct semaphore sem;          /* mutual exclusion semaphore     */
    struct semaphore updateSem[GDMA_PLANE_MAXNUM];
    struct semaphore sem_receive;          /* mutual exclusion semaphore     */
	struct semaphore sem_gfxreceive;      /* mutual exclusion semaphore     */
#ifdef USR_WORKQUEUE_UPDATE_BUFFER
	struct semaphore sem_work;
	struct semaphore sem_work_down_timeout;
#endif
    struct cdev      cdev;         /* Char device structure          */
	struct device *dev;

    GDMA_PLANE       osdPlane[GDMA_PLANE_MAXNUM];  /* OSD1, OSD2, OSD3, OSD4, OSD5 */
    unsigned int     OSD_CLUT[GDMA_MAX_NUM_CLUT][256] __attribute__((aligned(8)));
    unsigned int     OSD_CLUT_LEN[GDMA_MAX_NUM_CLUT];

    char             pendingRPC[GDMA_PLANE_MAXNUM];
    unsigned char iCONFIG_PANEL_TYPE;	/*  (0:LVDS 2k1k only), (1: VBY_ONE 4k2K), (2: LVDS 4k2k+2k1k (NEED define CUSTOM INDEX)) */
    unsigned char iCONFIG_PANEL_CUSTOM_INDEX;	/*  (0:LVDS 2k1k only), (1: VBY_ONE 4k2K), (2: LVDS 4k2k+2k1k (NEED define CUSTOM INDEX)) */
    int             f_inputsrc_4k2k;
    bool             f_3d_ui;/* 4k1k china start panel use */

    bool             f_box_mode;
    bool             f_palette_update;
    int              box_src_height;
    int              box_dst_height;


    /* for registers */
    osd1_RBUS GDMA_osd;
    osd1_ctrl_RBUS GDMA_osd_ctrl;
    unsigned int GDMA_hcoeff[8];

    ppoverlay_3D_OFFSET osd3Doffset[MAX_OSD_NUM];  /* OSD1, OSD2, OSD3, OSD4, OSD5 */

    /* for 3D Graphic */
    GDMA_DISPLAY_PLANE plane;
    GDMA_STATUS     ctrl;
    unsigned char   picQrd[GDMA_PLANE_MAXNUM];
    unsigned char   picQwr[GDMA_PLANE_MAXNUM];
    unsigned char   curPic[GDMA_PLANE_MAXNUM];
    unsigned char   picCount[GDMA_PLANE_MAXNUM];
    VO_RECTANGLE    dispWin[GDMA_PLANE_MAXNUM];
    GDMA_PIC_DATA   pic[GDMA_PLANE_MAXNUM][GDMA_MAX_PIC_Q_SIZE];

    OSD_SR_CH_SEL osd_sr_ch;

    /*modify for vsync between hwc and gdma*/
    unsigned int vsync_enable;
    struct semaphore vsync_sem;
    void (*GDMA_CallBack) (void *handler, bool isRightEye);
    void (*GDMA_CookieCallBack) (void *handler, int cookie);
} gdma_dev;


struct gdma_receive_work {
    struct work_struct GdmaReceiveWork;

    GDMA_DISPLAY_PLANE disPlane;
    unsigned char   picQwr;     /*  pointer to the new picture in the picQueue */
    int used;
#ifdef USR_WORKQUEUE_UPDATE_BUFFER
    PICTURE_LAYERS_OBJECT *data;
#endif
};


/*
*   define function proto-type
*/
ssize_t GDMA_read   (struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
ssize_t GDMA_write  (struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);
loff_t  GDMA_llseek (struct file *filp, loff_t off, int whence);
/* int     GDMA_ioctl  (struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg); */
int     GDMA_ioctl  (struct file *filp, unsigned int cmd, unsigned long arg);
int     GDMA_open   (struct inode *inode, struct file *filp);
int     GDMA_release(struct inode *inode, struct file *filp);
int     GDMA_Update (gdma_dev *gdma, int inISR);
int     GDMA_Flush (gdma_dev *gdma);
void GDMA_QueueFlush(void);


int GDMA_DrawGraphicWindow (VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *cmd);
int GDMA_CreateGraphicWindow (VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *cmd);
int GDMA_DeleteGraphicWindow (unsigned char winID, VO_GRAPHIC_PLANE plane, unsigned char go);

int GDMA_GetOSDPalette (unsigned int index, unsigned int *palette, unsigned int *len);
int GDMA_SetOSDPalette (unsigned int index, unsigned int *palette, unsigned int len);

void GDMA_PreUpdate(struct work_struct *psWork);
void GDMA_CopyLayerInfo(GDMA_PICTURE_OBJECT *dest, GDMA_LAYER_OBJECT *src);

void GDMA_OSDSplitSet(CONFIG_OSDSPLIT_STRUCT *data);
void GDMA_OSDSmoothToggle(void);

int drv_PreScale(uint8_t enable, VO_RECTANGLE srcWin, VO_RECTANGLE dispWin, GDMA_DISPLAY_PLANE plane, struct gdma_receive_work *ptr_work);

int GDMA_Sync_Enable(void);
int GDMA_Sync_Disable(void);

void GDMA_Clk_Select(int src_type, bool enable);
void GDMA_LineBufferCal(void);
void GDMA_ENTER_CRITICAL (void);
void GDMA_EXIT_CRITICAL (void);
void GDMA_OnlineWritebackDisplay(void);
GDMA_ONOFF_SWITCH GDMA_SwitchOnlineOffline(int hasCompress, int osd1offline);


#endif  /*  end of _GDMA_DRIVER_H_ */
