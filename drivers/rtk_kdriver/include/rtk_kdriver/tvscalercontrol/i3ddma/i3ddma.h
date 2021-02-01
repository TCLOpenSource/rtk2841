#ifndef __I3DDMA_H_
#define __I3DDMA_H__

#ifdef __cplusplus
extern "C" {
#endif
//#include <rbus/rbusTypes.h>
//#include <rtd_types.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
//#include <OSAL/PLI.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <rbus/h3ddma_reg.h>
#include <rbus/vgip_reg.h>


#define I3DDMA_PRINTF printf

#define I3DDMA_HAVE_HDMI_DMA        			1
#define I3DDMA_HAVE_HDMI_DITHER_12X10		1
#define I3DDMA_HAVE_HDMI_3D_TG				1


#ifndef rtd_maskl
#define rtd_maskl(x, y, z)	IoReg_Mask32(x, y, z)
#endif

#ifndef rtd_outl
//#define rtd_outl(x, y)		IoReg_Write32(x, y)
#endif

#ifndef rtd_inl
#define rtd_inl(x)			IoReg_Read32(x)
#endif

#define _SYNC_HN_VN	_BIT0
#define _SYNC_HP_VN		_BIT1
#define _SYNC_HN_VP		_BIT2
#define _SYNC_HP_VP		_BIT3

//#include <tvscalercontrol/hdmiRx/hdmiFun.h>
//#include <rbusHDMIReg.h>
//#include <rbusDDCReg.h>

//#include <tvscalercontrol/scaler/scalerStruct.h>
//#include <hdmiPlatform.h>

typedef enum {
	I3DDMA_FRAME_PACKING = 0,
	I3DDMA_FIELD_ALTERNATIVE = 1,
	I3DDMA_LINE_ALTERNATIVE = 2,
	I3DDMA_SIDE_BY_SIDE_FULL = 3,
	I3DDMA_L_DEPTH = 4,
	I3DDMA_L_DEPTH_GPX = 5,
	I3DDMA_TOP_AND_BOTTOM =6,
	I3DDMA_FRAMESEQUENCE=7,
	I3DDMA_SIDE_BY_SIDE_HALF = 8,
	// --- new 3D format ---
	I3DDMA_VERTICAL_STRIPE,
	I3DDMA_CHECKER_BOARD,
	I3DDMA_REALID,
	I3DDMA_SENSIO,
	// -------------------
	I3DDMA_RSV1,
	I3DDMA_2D_ONLY,
	I3DDMA_UNKOWN = 0xFFFFFFFF
} I3DDMA_3D_T;

typedef enum {
	I3DDMA_3D_CHESS_FMT_0 = 0,
	I3DDMA_3D_CHESS_FMT_1
}I3DDMA_3D_CHESS_FMT_T;

typedef enum {
	I3DDMA_3D_OPMODE_DISABLE = 0,
	I3DDMA_3D_OPMODE_HW,
	I3DDMA_3D_OPMODE_HW_2DONLY_L,
	I3DDMA_3D_OPMODE_HW_2DONLY_R,
	I3DDMA_3D_OPMODE_SW,
	I3DDMA_3D_OPMODE_HW_NODMA
} I3DDMA_3D_OPMODE_T;

typedef struct {
	unsigned char *uncache;
	void *cache;
	unsigned long phyaddr;
	unsigned int size;
	unsigned int getsize;
} I3DDMA_CAPTURE_BUFFER_T;

typedef enum {

	I3DDMA_COLOR_DEPTH_8B =0,
	I3DDMA_COLOR_DEPTH_10B,
	I3DDMA_COLOR_DEPTH_12B,
	I3DDMA_COLOR_DEPTH_16B,

} I3DDMA_COLOR_DEPTH_T;

typedef enum {
	I3DDMA_COLOR_RGB 	= 0x00,
	I3DDMA_COLOR_YUV422,
	I3DDMA_COLOR_YUV444,
	I3DDMA_COLOR_YUV411,
	I3DDMA_COLOR_UNKNOW
} I3DDMA_COLOR_SPACE_T;

typedef enum {
	I3DDMA_COLORIMETRY_NOSPECIFIED = 0,
	I3DDMA_COLORIMETRY_601,
	I3DDMA_COLORIMETRY_709,
	I3DDMA_COLORIMETRY_XYYCC601,
	I3DDMA_COLORIMETRY_XYYCC709,
	I3DDMA_COLORIMETRY_SYCC601,
	I3DDMA_COLORIMETRY_ADOBE_YCC601,
	I3DDMA_COLORIMETRY_ADOBE_RGB,
} I3DDMA_COLORIMETRY_T;

typedef enum {
	I3DDMA_ERR_NO = 0,
	I3DDMA_EER_GENERIC,
	I3DDMA_ERR_ONMS_ONESHOT,
	I3DDMA_ERR_ONMS_CONTINUOUS_INIT,
	I3DDMA_ERR_ONMS_CONTINUOUS_CHECK,
	I3DDMA_ERR_ONMS_WRONG_TIMING,
	I3DDMA_ERR_ONMS_WRONG_PARAM,
	I3DDMA_ERR_3D_WRONG_OPMODE,
	I3DDMA_ERR_3D_NO_MEM,
	I3DDMA_ERR_4XXTO4XX_WRONG_PARAM,
	I3DDMA_EER_MEASURE_ACTIVESPACE_FAIL,
	I3DDMA_EER_VODMA_NOT_READY,
} I3DDMA_ERR_T;

typedef struct {

    I3DDMA_COLOR_DEPTH_T depth;
    I3DDMA_COLOR_SPACE_T color;

    I3DDMA_COLORIMETRY_T  colorimetry;
    char progressive;          // 0 --> interlaced ; 1 --> progressive
    I3DDMA_3D_T i3ddma_3dformat;
	VO_FORCE2D_MODE i3ddma_force2d; // 0: disable, 1: L-frame, 2: R-frame

    unsigned int v_total;
    unsigned int h_total;
    unsigned int v_act_len;
    unsigned int h_act_len;
    unsigned int v_act_sta;
    unsigned int h_act_sta;
    //unsigned int h_sync_high;
    unsigned int v_freq;
    unsigned int h_freq;
    unsigned int polarity;
    //unsigned int mode_id;

    // only for fram packing
    unsigned int v_active_space1;
    unsigned int v_active_space2;

    // quincunx
//    unsigned quincunx_en;
//    unsigned quincunx_mode;

}I3DDMA_TIMING_T;




// share with VO DMA
typedef struct {

    int 	   i3ddma_3d_capability;
    int      fast_boot_source;
    int 	   force_all_3d_disable;
    int 	   force_2dto3d_enable;
    I3DDMA_3D_T force_2dto3d_mode;
    int 	   force_3dto2d_enable;
    int 	  force_3dto2d_lr_sel;
    int      enable_3ddma;
    int 	   resume;

	I3DDMA_3D_OPMODE_T   hw_i3ddma_dma;
	int      hw_dither12x10_enable;
	int      hw_dither10x8_enable;
	int      hw_4xxto4xx_enable;
	int      hw_rgbtoyuv_enable;

	I3DDMA_COLOR_DEPTH_T targetDepth;
	I3DDMA_COLOR_SPACE_T targetColor;

	int      hw_hsd_enable;
	unsigned int input_src_idx;
	unsigned int input_src_type;
	unsigned int input_src_from;
	unsigned int input_src_mode;
	unsigned int input_h_Count;
	unsigned int input_h_size;
	unsigned int output_h_size;

	I3DDMA_TIMING_T *ptx_timing;
	I3DDMA_TIMING_T *pgen_timing;


    // for 3d
    unsigned int frame_rate_x2;
    unsigned int enable_4xxto4xx;
    unsigned int pixel_bits;





     int down_sample_number;

	int enable; 					// 3d global enable
	// video ring buffer
	unsigned int cap_rp;			// W: Video R:System
	unsigned int cap_wp;			// W: System R:Video
	int cap_size;
	I3DDMA_CAPTURE_BUFFER_T cap_buffer_pool;
	I3DDMA_CAPTURE_BUFFER_T cap_buffer[8];
	// freeze
	unsigned int vodma_freeze;	// W: System R:Video
	unsigned int hdmi_freeze;
	unsigned int force_2d;			// 0: 3d  1:L only 2:R only
	// pull down 22
	unsigned int pulldown22;
	I3DDMA_COLOR_SPACE_T  cap_color_fmt;
	int cap_pixel_bits;
	I3DDMA_COLOR_DEPTH_T cap_colordepth;
	I3DDMA_COLOR_SPACE_T cap_colorspace;
	I3DDMA_TIMING_T vodma_timing;
	I3DDMA_3D_OPMODE_T opmode;
	I3DDMA_CAPTURE_BUFFER_T cap_total_buffer;
} I3DDMA_3DDMA_CTRL_T;


char I3DDMA_SetupVODMA(I3DDMA_TIMING_T *timing);
char I3DDMA_Setup3DDMA(I3DDMA_3DDMA_CTRL_T* ctrl, I3DDMA_3D_OPMODE_T opmode);
char I3DDMA_ForceVODMA2D(UINT8 enable, UINT8 LR);
unsigned char I3DDMA_Get3DAllocReleaseMemoryDynamic(void);
char I3DDMA_ResetVODMA4K2K(void);
char drvif_I3DDMA_3D_FeatureEnable(char enable);
unsigned char I3DDMA_Get_FP1080i_status(void);

unsigned char I3DDMA_check_idma_shareMemWithVideoFW(void);

extern unsigned char I3DDMA_3DDMAInit(void);
extern void I3DDMA_3DDMADeInit(void);
unsigned char I3DDMA_DolbyVision_HDMI_Init(void);

void I3DDMA_DolbyVision_HDMI_DeInit(void);
unsigned char I3DDMA_DolbyVision_MetaData_Init(void);
unsigned char I3DDMA_DolbyVision_MetaData_DeInit(void);
void I3DDMA_DolbyVision_buf_setting(void);
//unsigned long I3DDMA_GetMemChunkAddr(void);
unsigned long I3DDMA_GetMemChunkAddr(unsigned int size);

extern void I3DDMA_Get3DGenTiming(I3DDMA_TIMING_T *tx_timing, I3DDMA_TIMING_T *gen_timing);
extern void I3DDMA_BandWidth_Control(I3DDMA_TIMING_T* tx_timing, I3DDMA_TIMING_T*gen_timing);
extern char I3DDMA_Dithering12to10(I3DDMA_COLOR_DEPTH_T source, I3DDMA_COLOR_DEPTH_T target);
extern char I3DDMA_4xxto4xx_Downsample(I3DDMA_COLOR_SPACE_T source, I3DDMA_COLOR_SPACE_T target);
extern void I3DDMA_ultrazoom_config_h_scaling_down(unsigned int in_h_Size, unsigned int out_h_Size, unsigned char panorama);
extern  void I3DDMA_ColorSpacergb2yuvtransfer(unsigned char nSrcType, unsigned char nSD_HD, unsigned char VO_Jpeg_Back_YUV);
extern  unsigned char I3DDMA_disp2tve_CapBufInit(void);
extern void I3DDMA_disp2tve_CapBufDeInit(void) ;
extern I3DDMA_3DDMA_CTRL_T i3ddmaCtrl;

extern I3DDMA_CAPTURE_BUFFER_T idma_cap_buf[3];
void drv_I3ddmaVodma_GameMode_iv2pv_delay(unsigned char enable);
void drv_I3ddmaVodma_SingleBuffer_GameMode(unsigned char enable);
#ifdef __cplusplus
}
#endif


#endif
