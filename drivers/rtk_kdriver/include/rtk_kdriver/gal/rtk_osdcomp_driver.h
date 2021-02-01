#ifndef _OSD_COMP_DRIVER_H
#define _OSD_COMP_DRIVER_H
#include "rtk_gdma_driver.h"

#define DEFAULT_COMPRESS_RATIO 40

/* source 2k1k */
/*#define DEFAULT_SEG_SIZE ((TWOK_W*ONEK_H)*4*DEFAULT_COMPRESS_RATIO/100)*/
/* source 4k2k */
#define DEFAULT_SEG_SIZE ((FOURK_W*TWOK_H)*4*DEFAULT_COMPRESS_RATIO/100)

/* Can't_USE_SEM+ */
#define COMP_SEM_COUNT MAX_COMP_BUFF
/*#define COMP_MAX_WORK 3*/
/* Can't_USE_SEM- */
#define COMP_MAX_WAIT_TIME 20

typedef enum _COMP_BUF_STATUS {
    BUF_FULL = -1,
    BUF_EMPTY = 0,
    BUF_USED,
    BUF_COMPRESSING,
    BUF_READY2DISPLAY,
    BUF_DISPLAYING,
} COMP_BUF_STATUS;

typedef enum _COMP_MOD_STATUS {
    COM_MOD_INIT = 0,
    COM_MOD_START = 1,
    COM_MOD_END = 2
} COMP_MOD_STATUS;

typedef struct {
    unsigned int type:5;
    unsigned int reserved2:2;
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
} COMP_WIN_ATTR;

typedef struct {
    unsigned int alloc_virt_addr;
    unsigned int alloc_phy_16byte_addr;/* alignment for compress use */
} SEG_ADDR_INFO;



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
    FBDC_PLANEALPHA         fbdc_plane_alpha_c2;
    unsigned int reserved[2];


    bool used;
    int dst_x;/* dst */
    int dst_y;/* dst */
    int dst_width;/* dst */
    int dst_height;/* dst */
    osd_planealpha_ar plane_ar;     /*  fbdc only 8 bits, mixer has 9 bits */
    osd_planealpha_gb plane_gb;     /*  fbdc only 8 bits, mixer has 9 bits */
    osd_clear_x clear_x;
    osd_clear_y clear_y;
    E_BLEND_ORDER offlineOrder;   /*  for offline blend use */
} OSD_WIN __attribute__((aligned(16)));


typedef struct {
    OSD_WIN OSD1_WIN;	/* offline OSD win info. */
    OSD_WIN OSD2_WIN;	/* offline OSD win info. */
    OSD_WIN OSD3_WIN;	/* offline OSD win info. */
    OSD_WIN OSD4_WIN;	/* offline OSD win info. */
    OSD_WIN OSD5_WIN;	/* offline OSD win info. */

    COMP_BUF_STATUS buf_status;
    SEG_ADDR_INFO seg_addr[MAX_SEG_NUM];
    unsigned int context;
    WB_TYPE wbType;
    VO_GRAPHIC_PLANE plane;              /*  final display plane */
    INBAND_CMD_GRAPHIC_3D_MODE picLayout;
    GDMA_PIC_MATCH_SYNCSTAMP syncInfo;
    int show;					/* 1: show this plane. 0:hide */
	int scale_factor;	/* layer scale factor based on panel size & fb size */

    unsigned char *comp_done;		/* pointer to comp_done variable from GRAPHIC_LAYERS_OBJECT */
} COMP_WIN __attribute__((aligned(16)));



typedef struct {
    int comp_sem;/* Can't_USE_SEM */
    int comp_process;
    int start_compress;
    struct semaphore compress_sem;          /* compress sem for compress done */
    struct semaphore softabort_sem;          /* compress sem for softabort call */
    struct semaphore dequeue_sem;          /* compress sem for online write-back */
	struct semaphore pli_sem;          	/* compress sem for buffer creation */
    /*COMP_BUFF_IDX current_comp_idx; //for compress use */
    unsigned int compress_ratio; /* default :50 */
    unsigned int seg_size;
    COMP_WIN    comp_win[MAX_COMP_BUFF];
    /* COMP_WIN    comp_3dwin[MAX_COMP_BUFF]; */
} COMP_CONTROL;

struct cmp_receive_work {
    struct work_struct CmpReceiveWork;
    COMP_BUFF_IDX current_comp_idx;/* for compress use */
    COMP_WIN    comp_win;
    int used;
};



/* int osd_comp_init_module(void); */
void osd_comp_init_module(void);
void osd_comp_cleanup_module(void);
int osd_comp_work_queue_init(void);
int osd_comp_work_queue(void);

int osd_comp_receive_enqueue(PICTURE_LAYERS_OBJECT *data);
void osd_comp_receive_dequeue(struct work_struct *psWork);
int osd_comp_send_gdma(struct cmp_receive_work *ptr_work);

int osd_comp_pre_receive_picture(PICTURE_LAYERS_OBJECT *data);
int osd_comp_receive_picture(PICTURE_LAYERS_OBJECT *data);
int osd_comp_graphic_layers_wb_offline(GRAPHIC_LAYERS_OBJECT *data);
int osd_comp_graphic_layers_wb_online(ONLINE_WRRITEBACK_STRUCT *wb, int protectFlag);
int osd_comp_process(struct cmp_receive_work *ptr_work);
int osd_comp_handler(int compress_done, int compress_int);
void osd_decomp_handler(GDMA_PIC_DATA *curPic);
void osd_comp_softwareAbort(void);


#endif/* _OSD_COMP_DRIVER_H */

