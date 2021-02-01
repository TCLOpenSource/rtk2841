#ifndef __I3DDMA_DRV_H_
#define __I3DDMA_DRV_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rbus/rbusTypes.h>
//#include <rtd_types.h>
//#include <rbus/scaler/rbusHDMIReg.h>
//#include <rbusHDMIReg.h>
//#include <OSAL/PLI.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/scalerlib.h>
#include "tvscalercontrol/tve/tve.h"

#define I3DDMA_PRINTF printf

typedef enum I3DDMA_INFO_LIST{
	I3DDMA_INFO_HW_I3DDMA_DMA=	0x00,
	I3DDMA_INFO_HW_DITHER12X10_ENABLE,
	I3DDMA_INFO_HW_DITHER10x8_ENABLE,
	I3DDMA_INFO_HW_4XXTO4XX_ENABLE,
	I3DDMA_INFO_HW_RGBTOYUV_ENABLE,
	I3DDMA_INFO_TARGET_DEPTH,
	I3DDMA_INFO_TARGET_COLOR,

	I3DDMA_INFO_HW_HSD_ENABLE,
	I3DDMA_INFO_INPUT_H_SIZE,
	I3DDMA_INFO_OUTPUT_H_SIZE,

	I3DDMA_INFO_INPUT_TIMING,
	I3DDMA_INFO_GEN_TIMING,
	I3DDMA_INFO_FRAMERATE_X2,
	I3DDMA_INFO_ENABLE_4XXTO4XX,
	I3DDMA_INFO_PIXEL_BITS,
	I3DDMA_INFO_ENABLE_3DDMA,
	I3DDMA_INFO_INPUT_SRC_IDX,
	I3DDMA_INFO_INPUT_SRC_TYPE,
	I3DDMA_INFO_INPUT_SRC_FROM,
	I3DDMA_INFO_INPUT_MODE_CURR,
	I3DDMA_INFO_INPUT_H_COUNT

}I3DDMA_INFO_LIST;

//#ifdef DTV_SCART_OUT_ENABLE
typedef struct _IDMA_VGIP2_CTRL_INFO {
	//DOUBLE_CLOCK_CTRL_STATE 	curState;
	SRC_TYPE					srcType;
	unsigned char						srcFrom;
	unsigned char						srcIndex;
	SRC_INFO					srcInfo;
	unsigned char						srcChanged;	// Input source is changed before VGIP2 be released
	unsigned char						srcInHand;	// VGIP2 Input source not be released
}IDMA_VGIP2_CTRL_INFO;
//#endif
#ifdef CONFIG_SCALER_BRING_UP
typedef enum
{
	DDOMAIN_FMT_444 = 0,
	DDOMAIN_FMT_422,
} VODMA_DDOMAIN_CHROMA;

typedef enum
{
	DMA_SEQUENTIAL_MODE = 0,
	DMA_BLOCK_MODE,
} VODMA_DMA_MODE;

typedef enum{
	CHROMA_YUV420 = 0,//v note. DON't change default value 420
	CHROMA_YUV422,
	CHROMA_YUV422V,
	CHROMA_YUV444,
	CHROMA_ARGB8888,
	CHROMA_RGB888,
	CHROMA_RGB565,
	CHROMA_GRAY,
	CHROMA_YUV411,
	VODMA_CHROMA_NUM
} VODMA_CHROMA_FORMAT;

typedef enum
{
	IV_SRC_SEL_PIXELCLOCK = 0,
	IV_SRC_SEL_MAINIVS,
	IV_SRC_SEL_MAINDVS,
	IV_SRC_SEL_HDMIDMAVS,
	IV_SRC_SEL_MANUALVS,
	IV_SRC_SEL_HDMITXVS,
	IV_SRC_SEL_SUBIVS,
	IV_SRC_SEL_VODMA1,
} IV_SRC;

typedef enum
{
	VODMA_CLK_SEL_PLLBUS_2 = 0,
	VODMA_CLK_SEL_ADCCLK,
	VODMA_CLK_SEL_HDMICLK,
	VODMA_CLK_SEL_DCLK,
}VODMA_CLK_SRC;

typedef enum
{
	PVS0_FREE_CLK_SEL_PCRACLK = 0,
	PVS0_FREE_CLK_SEL_PIXELCLK,
	PVS0_FREE_CLK_SEL_PCRBCLK,
	PVS0_FREE_CLK_SEL_CRYSTALCLK,
}PVS0_FREE_CLK_SRC;

typedef enum {
	HDMI_AUTO_MODE_DISABLE = 0,
	HDMI_AUTO_MODE_HW_MODE1,	// HW auto mode
	HDMI_AUTO_MODE_HW_MODE2	// Field signal sync from IDMA
}VODMA_HDMI_AUTO_MODE;

typedef enum
{
	VO_COLORSPACE_YUV = 0,
	VO_COLORSPACE_RGB,
} VO_COLORSPACE;

#endif

void drvif_I3DDMA_Init(void);
void drvif_I3DDMA_DeInit(void);
//void drvif_I3DDMA_Set_Path_Policy(I3DDMA_PATH_POLICY_T i3dPathPolicy);
//void drvif_I3DDMA_Set_Input_Timing(I3DDMA_TIMING_T* pInputTiming);

void drvif_I3DDMA_Set_Input_Info_Vaule(I3DDMA_INFO_LIST input_type, unsigned int value);
unsigned int drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_LIST input_type);

char drvif_I3DDMA_3D_FeatureEnable(char enable) ;
void drv_I3DDMA_ApplySetting(void);
void drvif_I3DDMA_dispD_to_IdmaVI_idmaConfig(IDMA_DISPD_CAPTURE_INFO capInfo);
void drvif_I3DDMA_dispDtoI3ddma_TVE(IDMA_DISPD_CAPTURE_INFO outSize);
void drvif_I3DDMA_Enable_Vgip(void);
void drvif_I3DDMA_Disable_Vgip(void);
void drvif_I3DDMA_freeze_enable(unsigned char enable);
void scaler_vodmatoI3ddma_prog(TVE_VIDEO_MODE_SEL tve_mode, UINT8 tve_vflip_en);
unsigned char vo_se_scaling_get_enable(void);
void vo_se_scaling_set_enable(unsigned char enable);
void VO_SE_Scaling(bool enable);
void vo_se_scaling_ctrl(int enable);
unsigned char scaler_get_tve_vflip_enable(void);
void scaler_set_tve_vflip_enable(unsigned char enable);
void disable_I3DDMA_dispDtoSub(void);
unsigned char scaler_dispDtoI3ddma_get_enable(void);
void scaler_dispDtoI3ddma_set_enable(unsigned char enable);
unsigned char scaler_scart_out_isr_get_enable(void);
void scaler_scart_out_isr_set_enable(unsigned char enable);

#ifdef CONFIG_DTV_SCART_OUT_ENABLE_444_FORMAT
long Scaler_VO_Set_VoForce422_enable(unsigned char bEnable);
#endif

#ifdef __cplusplus
}
#endif


#endif
