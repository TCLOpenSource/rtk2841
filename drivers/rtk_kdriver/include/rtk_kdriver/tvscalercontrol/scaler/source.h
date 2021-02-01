#ifndef  __SCALER_SOURCE_H__
#define  __SCALER_SOURCE_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/scaler/scalerstruct.h>




/*==================== Definitions ================ */



enum _INPUT_SRC_STRING_MAP
{
	_TV_INPUT1 = _SRC_TV | (0x01<<8),
	_TV_INPUT2 = _SRC_TV | (0x02<<8),
	_TV_INPUT3 = _SRC_TV | (0x03<<8),
//	_DTV_INPUT1 = _SRC_DTV | (0x01<<8),
//	_DTV_INPUT2 = _SRC_DTV | (0x02<<8),
//	_DTV_INPUT3 = _SRC_DTV | (0x03<<8),
	_AV_INPUT1 = _SRC_CVBS | (0x01<<8),
	_AV_INPUT2 = _SRC_CVBS | (0x02<<8),
	_AV_INPUT3 = _SRC_CVBS | (0x03<<8),
	_AV_INPUT4 = _SRC_CVBS | (0x04<<8),
	_AV_INPUT5 = _SRC_CVBS | (0x05<<8),
	_AV_INPUT6 = _SRC_CVBS | (0x06<<8),
	_SV_INPUT1 = _SRC_SV | (0x01<<8),
	_SV_INPUT2 = _SRC_SV | (0x02<<8),
	_SV_INPUT3 = _SRC_SV | (0x03<<8),
	_SV_INPUT4 = _SRC_SV | (0x04<<8),
	_SV_INPUT5 = _SRC_SV | (0x05<<8),
	_SV_INPUT6 = _SRC_SV | (0x06<<8),
	_YPBPR_INPUT1 = _SRC_YPBPR | (0x01<<8),
	_YPBPR_INPUT2 = _SRC_YPBPR | (0x02<<8),
	_YPBPR_INPUT3 = _SRC_YPBPR | (0x03<<8),
	_YPBPR_INPUT4 = _SRC_YPBPR | (0x04<<8),
	_YPBPR_INPUT5 = _SRC_YPBPR | (0x05<<8),
	_YPBPR_INPUT6 = _SRC_YPBPR | (0x06<<8),
	_VGA_INPUT1 = _SRC_VGA | (0x01<<8),
	_VGA_INPUT2 = _SRC_VGA | (0x02<<8),
	_VGA_INPUT3 = _SRC_VGA | (0x03<<8),
	_VGA_INPUT4 = _SRC_VGA | (0x04<<8),
	_VGA_INPUT5 = _SRC_VGA | (0x05<<8),
	_VGA_INPUT6 = _SRC_VGA | (0x06<<8),
	_HDMI_INPUT1 = _SRC_HDMI | (0x01<<8),
	_HDMI_INPUT2 = _SRC_HDMI | (0x02<<8),
	_HDMI_INPUT3 = _SRC_HDMI | (0x03<<8),
	_HDMI_INPUT4 = _SRC_HDMI | (0x04<<8),
	_HDMI_INPUT5 = _SRC_HDMI | (0x05<<8),
	_HDMI_INPUT6 = _SRC_HDMI | (0x06<<8),
	_DISPLAYPORT_INPUT1 = _SRC_DISPLAYPORT | (0x01<<8),
	_DISPLAYPORT_INPUT2 = _SRC_DISPLAYPORT | (0x02<<8),
	_DISPLAYPORT_INPUT3 = _SRC_DISPLAYPORT | (0x03<<8),
	_DISPLAYPORT_INPUT4 = _SRC_DISPLAYPORT | (0x04<<8),
	_DISPLAYPORT_INPUT5 = _SRC_DISPLAYPORT | (0x05<<8),
	_DISPLAYPORT_INPUT6 = _SRC_DISPLAYPORT | (0x06<<8),
	_DVI_INPUT1 = _SRC_DVI | (0x01<<8),
	_DVI_INPUT2 = _SRC_DVI | (0x02<<8),
	_DVI_INPUT3 = _SRC_DVI | (0x03<<8),
	_DVI_INPUT4 = _SRC_DVI | (0x04<<8),
	_PVR_INPUT1 = _SRC_PVR | (0x01<<8),
	_PVR_INPUT2 = _SRC_PVR | (0x02<<8),
	_USB_INPUT1 = _SRC_USB | (0x01<<8),
	_USB_INPUT2 = _SRC_USB | (0x02<<8),
	_USB_INPUT3 = _SRC_USB | (0x03<<8),
	_USB_INPUT4 = _SRC_USB | (0x04<<8),
	_WIFI_INPUT1 = _SRC_WIFI | (0x01<<8),
	_WIFI_INPUT2 = _SRC_WIFI | (0x02<<8),
	_WIFI_INPUT3 = _SRC_WIFI | (0x03<<8),
	_WIFI_INPUT4 = _SRC_WIFI | (0x04<<8),
	_COMP_INPUT1 = _SRC_COMPONENT | (0x01<<8),
	_COMP_INPUT2 = _SRC_COMPONENT | (0x02<<8),
	_COMP_INPUT3 = _SRC_COMPONENT | (0x03<<8),
	_COMP_INPUT4 = _SRC_COMPONENT | (0x04<<8),
	_COMP_INPUT5 = _SRC_COMPONENT | (0x05<<8),
	_COMP_INPUT6 = _SRC_COMPONENT | (0x06<<8),
	_SCART_INPUT1 = _SRC_SCART | (0x01<<8),
	_SCART_INPUT2 = _SRC_SCART | (0x02<<8),
	_SCART_INPUT3 = _SRC_SCART | (0x03<<8),
	_SCART_INPUT4 = _SRC_SCART | (0x04<<8),
	_SCART_INPUT5 = _SRC_SCART | (0x05<<8),
	_SCART_INPUT6 = _SRC_SCART | (0x06<<8),
	_SCART_RGB_INPUT1 = _SRC_SCART_RGB | (0x01<<8),
	_SCART_RGB_INPUT2 = _SRC_SCART_RGB | (0x02<<8),
	_SCART_RGB_INPUT3 = _SRC_SCART_RGB | (0x03<<8),
	_SCART_RGB_INPUT4 = _SRC_SCART_RGB | (0x04<<8),
	_SCART_RGB_INPUT5 = _SRC_SCART_RGB | (0x05<<8),
	_SCART_RGB_INPUT6 = _SRC_SCART_RGB | (0x06<<8),
	_VO_INPUT1 = _SRC_VO | (0x01<<8),
	_VO_INPUT2 = _SRC_VO | (0x02<<8),
	_VO_INPUT3 = _SRC_VO | (0x03<<8),
	_OSD_INPUT1 = _SRC_OSD | (0x01<<8),
	_UNKNOWN_INPUT = _SRC_MAX | (0x01<<8),
};

#define SRC_NUM_UPPER		(_SRC_MAX*6)

/*====================== Types ================== */
#define SET_SOURCE(From,VdcSrc)		((((VdcSrc & 0xff)<<8)|(From & 0xff)))
#define GET_SOURCE_FROM(src_type)			((src_type & 0xff))


typedef struct _StructSrcProcObject {
	void	(*InitSrc)(StructSourceInput *srcinput_pt);	// Init current input source setting
	unsigned char	(*DetectMode)(StructSourceInput *srcinput_pt);			// detect mode function pointer
	unsigned char	(*CheckMode)(StructSourceInput *srcinput_pt); // check mode function pointer
	void	(*InProcSetup)(void);
	void	(*InProcRelease)(StructSourceInput *srcinput_pt);	// Init current input source setting to VDC
}StructSrcProcObject;

//ADC SIGNAL POSITIVE PATH
//Swap  ADC R,G,B  for VGIP__RGB
//VD_ADC same as ADC
typedef enum {
    ADC_SWAP_RGB = 0,//000
	ADC_SWAP_GRB,//001
	ADC_SWAP_BGR,//010
	ADC_SWAP_RBG,//011
	ADC_SWAP_BRG,//100
	ADC_SWAP_GBR = 6,//110
} ADC_PATH_SWAP;

#if 0
typedef enum {
//ADC_SOY_MUX_CMP4_7 for bit28-bit31
	ADC_SOY_MUX_CMP4_7_VIN0P = 0x00,
	ADC_SOY_MUX_CMP4_7_VIN1P,//0001
	ADC_SOY_MUX_CMP4_7_VIN2P,//0010
	ADC_SOY_MUX_CMP4_7_VIN3P,//0011
	ADC_SOY_MUX_CMP4_7_VIN4P,//0100
	ADC_SOY_MUX_CMP4_7_VIN5P,//0101
	ADC_SOY_MUX_CMP4_7_VIN6P,//0110
	ADC_SOY_MUX_CMP4_7_VIN7P,//0111
	ADC_SOY_MUX_CMP4_7_VIN8PP,//1000
	ADC_SOY_MUX_CMP4_7_VSOG_CAL,//1001
	ADC_SOY_MUX_CMP4_7_GND1,//1010
	ADC_SOY_MUX_CMP4_7_GND2,//1011
	ADC_SOY_MUX_CMP4_7_GND3,//1100
	ADC_SOY_MUX_CMP4_7_GND4,//1101
	ADC_SOY_MUX_CMP4_7_GND5,//1110
	ADC_SOY_MUX_CMP4_7_GND6,//1111
//ADC_SOY_MUX for bit24-bit27
	ADC_SOY_MUX_VIN0P = 0x00,
	ADC_SOY_MUX_VIN1P,//0001
	ADC_SOY_MUX_VIN2P,//0010
	ADC_SOY_MUX_VIN3P,//0011
	ADC_SOY_MUX_VIN4P,//0100
	ADC_SOY_MUX_VIN5P,//0101
	ADC_SOY_MUX_VIN6P,//0110
	ADC_SOY_MUX_VIN7P,//0111
	ADC_SOY_MUX_VIN8PP,//1000
	ADC_SOY_MUX_VSOG_CAL,//1001
	ADC_SOY_MUX_VIN9P,//1010
	ADC_SOY_MUX_VIN10P,//1011
	ADC_SOY_MUX_VIN11PP,//1100
	ADC_SOY_MUX_GND1,//1101
	ADC_SOY_MUX_GND2,//1110
	ADC_SOY_MUX_GND3,//1111

} ADC_SOY_PATH;
#else
typedef enum {
//ADC_SOY_MUX_CMP4_7 for bit28-bit31
	ADC_SOY_MUX_CMP4_7_VIN1P = 0x00,
	ADC_SOY_MUX_CMP4_7_VIN4P,//0001
	ADC_SOY_MUX_CMP4_7_VIN7P,//0010
	ADC_SOY_MUX_CMP4_7_VSOG_CAL,//0011
//ADC_SOY_MUX for bit24-bit27
	ADC_SOY_MUX_VIN1P = 0x00,
	ADC_SOY_MUX_VIN4P,//0001
	ADC_SOY_MUX_VIN7P,//0010
	ADC_SOY_MUX_VIN10P,//0011
	ADC_SOY_MUX_VIN13P,//0100
	ADC_SOY_MUX_GND1,//0101
	ADC_SOY_MUX_GND2,//0110
	ADC_SOY_MUX_GND3,//0111
} ADC_SOY_PATH;
#endif

typedef enum {
	ADC_DATA_INPUT0 = 0,
	ADC_DATA_INPUT1,
	ADC_DATA_INPUT2,
} ADC_DATA_PATH;

typedef struct {
	ADC_DATA_PATH DATA_INPUT;
	ADC_SOY_PATH SOY_INPUT;
	ADC_PATH_SWAP SWAP_PATH;
}  VGA_ADC_DATA_PATH;

typedef struct {
	ADC_DATA_PATH DATA_INPUT;
	ADC_SOY_PATH SOY_INPUT;
	ADC_PATH_SWAP SWAP_PATH;
}  YPBPR_ADC_DATA_PATH;

typedef struct {
	void*		path;
	//unsigned int*		InitTable;
} ADC_INITIAL_OPTIONS;

//VDC SIGNAL POSITIVE PATH
typedef enum {
	VIDEO_INPUT0 = 0,
	VIDEO_INPUT1,
	VIDEO_INPUT2,
	VIDEO_INPUT3,
	VIDEO_INPUT4,
	VIDEO_INPUT5,
	VIDEO_INPUT6,
	VIDEO_INPUT7,
	VIDEO_INPUT8,
	VIDEO_INPUT9,
	VIDEO_INPUT10,
	VIDEO_INPUT11,
	VIDEO_INPUT12,
	VIDEO_INPUT13,
	VIDEO_INPUT14,
	TV_INPUT,
} VIDEO_PATH;

typedef enum {
	VIDEO_GNDA0 = 0x30,
	VIDEO_GNDA1 = 0x31,
	VIDEO_GNDA2 = 0x32,
	VIDEO_BN = 0x00,
	VIDEO_Y0N = 0x21,
	VIDEO_Y1N = 0x22,
//	VIDEO_RN = 0x20,		// no support
//	VIDEO_GN = 0x10,		// no support
}VIDEO_GND_PATH;

typedef enum {
   VIDEO_SV_NORMAL,
   VIDEO_SV_SWAP,
}VIDEO_SV_FUNC;

typedef struct {
	VIDEO_PATH VideoIn;
	VIDEO_GND_PATH GroundIn;
}  AV_VDC_PATH;

typedef struct {
	VIDEO_PATH Y_VideoIn;
	VIDEO_GND_PATH Y_GroundIn;
	VIDEO_PATH C_VideoIn;
	VIDEO_GND_PATH C_GroundIn;
	VIDEO_SV_FUNC SV_Type;
}  SV_VDC_PATH;

typedef AV_VDC_PATH TV_VDC_PATH;

#if 1//def CONFIG_SCART_ENABLE
typedef struct {
	VIDEO_PATH Y_VideoIn;
	VIDEO_PATH R_VideoIn;
	VIDEO_PATH G_VideoIn;
	VIDEO_PATH B_VideoIn;
	VIDEO_GND_PATH GroundIn;
}  SCART_VDC_PATH;
#endif //#ifdef CONFIG_SCART_ENABLE

typedef struct {
	void*		path;
//	unsigned char*		InitTable;		it's not used after columbus era.josh@20090407
} VDC_INITIAL_OPTIONS;

void CAVSVInitial(StructSourceInput *srcinput_pt);
unsigned char CAVSVDetectMode(StructSourceInput *srcinput_pt);
unsigned char CAVSVCheckMode(StructSourceInput *srcinput_pt);
void CAVSVInProcSetup(void);
void CAVSVRelease(StructSourceInput *srcinput_pt);

void CHDMIInitial(StructSourceInput *srcinput_pt);
unsigned char CHDMIDetectMode(StructSourceInput *srcinput_pt);
unsigned char CHDMICheckMode(StructSourceInput *srcinput_pt);
void CHDMIInProcSetup(void);
void CHDMIRelease(StructSourceInput *srcinput_pt);

void CVGAInitial(StructSourceInput *srcinput_pt);
unsigned char CVGADetectMode(StructSourceInput *srcinput_pt);
unsigned char CVGACheckMode(StructSourceInput *srcinput_pt);
void CVGAInProcSetup(void);
void CVGARelease(StructSourceInput *srcinput_pt);

void CTv_clear_vdc_counter(void);
void CTVInitial(StructSourceInput *srcinput_pt);
unsigned char CTVDetectMode(StructSourceInput *srcinput_pt);
unsigned char CTVCheckMode(StructSourceInput *srcinput_pt);
void CTVInProcSetup(void);
void CTVRelease(StructSourceInput *srcinput_pt);
/**
\brief Get CTV initial flag
\param None
\return Init or not
*/
unsigned char CTVGetInitFlag(void);

/**
\brief Set "Change color standard" flag.
\param None
\return None
*/
void CTVSetChangeColorStdFlag(void);

unsigned char CTVGetVideoResolutin(void);


#if 1//def CONFIG_FV_CHECK
unsigned char CTVCheckFVBias(void);
#endif
void CTvReSetVGIP(unsigned char display);
typedef enum _TV_TABLE_TYPE{
	TV_TABLE_AV,
	TV_TABLE_PRESET,
}TV_TABLE_TYPE;
unsigned char CTVRegTable(TV_TABLE_TYPE type,void *ptr);

void CVideo8Initial(StructSourceInput *srcinput_pt);
unsigned char CVideo8DetectMode(StructSourceInput *srcinput_pt);
unsigned char CVideo8CheckMode(StructSourceInput *srcinput_pt);
void CVideo8InProcSetup(void);
void CVideo8Release(StructSourceInput *srcinput_pt);
unsigned char CVideo8CheckFVBias(void);

void CYPbPrInitial(StructSourceInput *srcinput_pt);
unsigned char CYPbPrDetectMode(StructSourceInput *srcinput_pt);
unsigned char CYPbPrCheckMode(StructSourceInput *srcinput_pt);
void CYPbPrInProcSetup(void);
void CYPbPrRelease(StructSourceInput *srcinput_pt);

void CVoInitial(StructSourceInput *srcinput_pt);
unsigned char CVoDetectMode(StructSourceInput *srcinput_pt);
unsigned char CVoCheckMode(StructSourceInput *srcinput_pt);
void CVoInProcSetup(void);
void CVoRelease(StructSourceInput *srcinput_pt);
void CVoRequestVoInfo(VO_VIDEO_PLANE plane);
void CVoSetFetestFlag(unsigned char flag);
void CVoUnstable(void);
void CVoSetCloseVODisplayFlag(unsigned char flag);

#if 1 //#ifdef CONFIG_NL_VO_INFO // Notify vo_info to scaler via netlink. USER: hsliao DATE: 2010/4/20
void CVoRun(void);
void CVoStop(void);
unsigned char CVoGetVoStopFlag(void);
void CVoNewVoInfo(void);
void CVoGetVoInfo(void);
unsigned char CVoGetNewVoInfoFlag(void);
void CVoSetWaitVoInfoFlag(unsigned char a_bFlag);
unsigned char CVoGetWaitVoInfoFlag(void);
#if defined(IS_MACARTHUR3)
unsigned char CVoGetInitFlag();
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif // __SCALER_SOURCE_H__


