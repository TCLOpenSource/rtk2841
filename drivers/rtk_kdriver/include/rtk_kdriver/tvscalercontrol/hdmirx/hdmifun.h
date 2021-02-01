#ifndef _HDMI_FUN_H
#define _HDMI_FUN_H




/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/
// --------------------------------------------------------------------------------
//	By project's requirement
// --------------------------------------------------------------------------------
#define HDMI_PHY_TOTAL_NUM		3
#define HDCP2_2				1
#define MHL_SUPPORT			1
#define INIT_HPD_OFF			1	/* set hotplug as low in hdmi_init, super_switch case should set 1 */
#define INITSRC_HPD_ON			0	/* set hotplug as high in init_source, LG webos case should set 0 */


//#define USE_DEFAULT_HDMI_EDID		1
#define USE_DEFAULT_MHL_EDID		1
#ifdef CONFIG_CUSTOMER_TV030
#define USE_DEFAULT_HDCP14		0
#else
#define USE_DEFAULT_HDCP14		1
#endif
#define HDMI_WD_VIDEO_COND		_BIT0
#define HDMI_WD_AUDIO_COND		_BIT1
#define HDMI_WD_VSC_COND			_BIT2
#define HDMI_WD_ALL_COND			(HDMI_WD_VIDEO_COND | HDMI_WD_AUDIO_COND | HDMI_WD_VSC_COND)



// --------------------------------------------------------------------------------
//	PCB Related
// --------------------------------------------------------------------------------

#ifndef __QC_VERIFY_COMMON_H__

#define PHY_Z0					0x10		// by PCB
#define HDMI_INTERNAL_1K			1
#define DETECT_HDMI_5V_IN(port)			get_hdmirx_5v(port)
#define MHL_CIRCUIT 				get_is_support_mhl_circuit()
#define MHL_CHANNEL				get_hdmi_rx_mhl_channel()	//CUSTOM_MHL_PORT
#define DETECT_MHL2_IN				get_mhl_signal()
#define PINMUX_SEL_HDMI_OUT()			{} //(set_hdmi_mhl_sel(1))
#define PINMUX_SEL_MHL_OUT()			{} //(set_hdmi_mhl_sel(0))
#define SET_HDMIRX_HPD(port, high_low)		set_hdmirx_hotplug(port, high_low)

#else

#define PHY_Z0					0x10		// by PCB
#define HDMI_INTERNAL_1K			1
#define DETECT_HDMI_5V_IN(port)			1
#define MHL_CIRCUIT				1
#define MHL_CHANNEL				0
#define MHL2_IN_PIN()				{ rtd_maskl(0xB8061100, ~_BIT26, 0); }
#define DETECT_MHL2_IN				(rtd_inl(0xb8061110)&_BIT26)
#define PINMUX_SEL_HDMI_OUT()			{}
#define PINMUX_SEL_MHL_OUT()			{}

#if MHL_CIRCUIT
#define HDMI_HOTPLUG0(x)	{ if (x) { \
					rtd_maskl(CBUS_PMM_CBUS_PHY_3_reg, ~(CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel_mask), CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel_mask); \
					rtd_maskl(CBUS_PMM_CBUS_PHY_3_reg, ~(CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask), 0);  \
				   } else { \
				   	rtd_maskl(CBUS_PMM_CBUS_PHY_3_reg, ~(CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel_mask), 0); \
				   	rtd_maskl(CBUS_PMM_CBUS_PHY_3_reg,~(CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask|CBUS_PMM_CBUS_PHY_3_cbus_i_rx_mask),(CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask)); } \
				}
#else
#define HDMI_HOTPLUG0(x)	{ rtd_maskl(0xB8061100, ~_BIT26, _BIT26); \
                                                                        rtd_maskl(0xB8061108, ~_BIT26, (1-x)<<26); }
#endif

#define HDMI_HOTPLUG1(x)	{ rtd_maskl(0xB8061100, ~_BIT28, _BIT28); \
                                                                        rtd_maskl(0xB8061108, ~_BIT28, (1-x)<<28); }
#define HDMI_HOTPLUG2(x)	{ rtd_maskl(0xB8061104, ~_BIT12, _BIT12); \
                                                                        rtd_maskl(0xB806110c, ~_BIT12, (1-x)<<12); }
#define HDMI_HOTPLUG3(x)	{} //{ rtd_maskl(0xB8061100, ~_BIT6, _BIT6);     rtd_maskl(0xB8061108, ~_BIT6, (1-x)<<6); }

#define SET_HDMIRX_HPD(port, high)	{ if (port == 0)  {HDMI_HOTPLUG0(high);} \
						else if (port == 1) {HDMI_HOTPLUG1(high);} \
						else if (port == 2) {HDMI_HOTPLUG2(high);} \
						else if (port == 3) {HDMI_HOTPLUG3(high);} }


#endif



/**********************************************************************************************
*
*	Enumerations or Structures
*
**********************************************************************************************/
typedef enum {
	HVF_NO,
	HVF_EXT,
	HVF_3D,
	HVF_RESERVED
}HDMI_HVF_E;

typedef enum {

	HDMI3D_FRAME_PACKING = 0,
	HDMI3D_FIELD_ALTERNATIVE = 1,
	HDMI3D_LINE_ALTERNATIVE = 2,
	HDMI3D_SIDE_BY_SIDE_FULL = 3,
	HDMI3D_L_DEPTH = 4,
	HDMI3D_L_DEPTH_GPX = 5,
	HDMI3D_TOP_AND_BOTTOM =6,
	HDMI3D_FRAMESEQUENCE=7,
	HDMI3D_SIDE_BY_SIDE_HALF = 8,
	// --- new 3D format ---
	HDMI3D_LINE_BY_LINE = 9,
	HDMI3D_VERTICAL_STRIPE = 10,
	HDMI3D_CHECKER_BOARD = 11,
	HDMI3D_REALID = 12,
	HDMI3D_SENSIO = 13,
	// -------------------
	HDMI3D_RSV1,
	HDMI3D_2D_ONLY,
	HDMI3D_UNKOWN = 0xFFFFFFFF
} HDMI_3D_T;

#if 0
typedef enum {

	HDMI_PTG_MODE_BACKGROUD_ONLY,
	HDMI_PTG_MODE_H_COLOR_BAR,
	HDMI_PTG_MODE_V_COLOR_BAR,
	HDMI_PTG_MODE_H_GREDIENT,
	HDMI_PTG_MODE_V_GREDIENT,
	HDMI_PTG_MODE_HV_GREDIENT,
	HDMI_PTG_MODE_BITMAP,
	HDMI_PTG_CROSS_COLOR_SEQ0,
	HDMI_PTG_CROSS_COLOR_SEQ1,
	HDMI_PTG_CROSS_COLOR_SEQ2,
	HDMI_PTG_CROSS_COLOR_SEQ3,

} HDMI_PTG_MODE_T;
#endif
typedef enum _HDMI_TABLE_TYPE{
              HDMI_CHANNEL0 ,
	HDMI_CHANNEL1,
	HDMI_CHANNEL2,
	HDMI_CHANNEL3,
	HDMI_CHANNEL,
	HDMI_HDCP_KEY_TABLE,
	CBUS_TABLE,
}HDMI_TABLE_TYPE;

//typedef void (*HDMI_MUX_ADVANCED_FUNCTION)(unsigned char index, unsigned int Value_1, unsigned int Value_2, unsigned int Value_3);


typedef  unsigned char HDMI_bool;

typedef enum {
	MODE_DVI	= 0x0,
	MODE_HDMI  ,
	MODE_UNKNOW
} HDMI_DVI_MODE_T;

typedef enum {
	MODE_RAG_DEFAULT	= 0x0,
	MODE_RAG_LIMIT  ,
	MODE_RAG_FULL  ,
	MODE_RAG_UNKNOW
} HDMI_RGB_YUV_RANGE_MODE_T;

typedef enum {
	COLOR_RGB 	= 0x00,
	COLOR_YUV422,
	COLOR_YUV444,
	COLOR_YUV420,
	COLOR_UNKNOW
} HDMI_COLOR_SPACE_T;

typedef enum {

	HDMI_COLOR_DEPTH_8B =0,
	HDMI_COLOR_DEPTH_10B,
	HDMI_COLOR_DEPTH_12B,
	HDMI_COLOR_DEPTH_16B,

} HDMI_COLOR_DEPTH_T;


typedef enum _HDMI_OSD_MODE{
	HDMI_OSD_MODE_AUTO= 0,
	HDMI_OSD_MODE_HDMI,
	HDMI_OSD_MODE_DVI,
	HDMI_OSD_MODE_NO_SETTING
} HDMI_OSD_MODE;


typedef enum {
	HDMI_PHY_PORT0 = 0,
	HDMI_PHY_PORT1,
	HDMI_PHY_PORT2,
	HDMI_PHY_PORT_NOTUSED = HDMI_PHY_TOTAL_NUM
} HDMI_PHY_PORT_T;


typedef enum {
	HDMI_EDID_ONCHIP = 0,
	HDMI_EDID_EEPROM,
	HDMI_EDID_I2CMUX,
	HDMI_EDID_DISABLE
} HDMI_EDID_TYPE_T;



typedef enum {
	DDC0 = 0,
	DDC1,
	DDC2,
	DDC3,
	DDC_NOTUSED
} DDC_NUMBER_T;



#include <rtk_gpio.h>

typedef struct {

	unsigned char	phy_port;
	unsigned char	ddc_selected;
	unsigned char	edid_table[256];

	unsigned char	edid_type;
	unsigned char	edid_initialized;

	RTK_GPIO_ID     hpd;        // GPIO for HPD
	RTK_GPIO_ID     det_5v;     // GPIO for 5V det
    
} HDMI_CHANNEL_T;

typedef struct {

	unsigned char	phy_port;
	unsigned char	ddc_selected;
	unsigned char	edid_type;	
	unsigned char	arc_support;	
	RTK_GPIO_ID     hpd;        // GPIO for HPD
	RTK_GPIO_ID     det_5v;     // GPIO for 5V det
} HDMI_CHANNEL_T_PCB_INFO;

typedef struct {
	unsigned char BKsv[5];
	unsigned char Key[320];
} HDCP_KEY_T;

#if (defined ENABLE_HDCPKEY_ENDIAN_SWAP)
typedef struct {
	unsigned char BKsv[5];
	unsigned char Key[328];
} HDCP_KEY_T1;
#endif

typedef enum {
	HDMI_COLORIMETRY_NOSPECIFIED = 0,
	HDMI_COLORIMETRY_601,
	HDMI_COLORIMETRY_709,
	HDMI_COLORIMETRY_XYYCC601,
	HDMI_COLORIMETRY_XYYCC709,
	HDMI_COLORIMETRY_SYCC601,
	HDMI_COLORIMETRY_ADOBE_YCC601,
	HDMI_COLORIMETRY_ADOBE_RGB,
} HDMI_COLORIMETRY_T;



typedef enum {
	MHL_RCP_SELECT = 0x00,
	MHL_RCP_UP = 0x01,
	MHL_RCP_DOWN = 0x02,
	MHL_RCP_LEFT = 0x03,
	MHL_RCP_RIGHT = 0x04,
	MHL_RCP_ROOT_MENU = 0X09,
	MHL_RCP_SETUP_MENU = 0X0A,
	MHL_RCP_CONTENTS_MENU = 0x0B,
	MHL_RCP_EXIT = 0x0D,
	MHL_RCP_NUM0 = 0x20,
	MHL_RCP_NUM1 = 0x21,
	MHL_RCP_NUM2 = 0x22,
	MHL_RCP_NUM3 = 0x23,
	MHL_RCP_NUM4 = 0x24,
	MHL_RCP_NUM5 = 0x25,
	MHL_RCP_NUM6 = 0x26,
	MHL_RCP_NUM7 = 0x27,
	MHL_RCP_NUM8 = 0x28,
	MHL_RCP_NUM9 = 0x29,
	MHL_RCP_DOT = 0x2A,
	MHL_RCP_ENTER = 0x2B,
	MHL_RCP_CH_ADD = 0x30,
	MHL_RCP_CH_SUB = 0x31,
	MHL_RCP_CH_PRE = 0x32,
	MHL_RCP_AUDIO = 0x33,
	MHL_RCP_DISPLAY = 0x35,

	MHL_RCP_VOLUME_UP = 0x41,
	MHL_RCP_VOLUME_DOWN = 0x42,
	MHL_RCP_MUTE = 0x43,
	MHL_RCP_PLAY = 0x44,
	MHL_RCP_STOP = 0x45,
	MHL_RCP_PAUSE = 0x46,
	MHL_RCP_REWIND = 0x48,
	MHL_RCP_FAST_FORWARD = 0x49,
	MHL_RCP_FORWARD = 0x4B,
	MHL_RCP_BACKWARD = 0x4C,

	MHL_RCP_MUTE_FUNCTION = 0x65,
	MHL_RCP_RESTORE_VOLUME_FUNCTION = 0x66,

	MHL_RCP_RED = 0x72,
	MHL_RCP_BLUE = 0x71,
	MHL_RCP_GREEN = 0x73,
	MHL_RCP_YELLOW = 0x74,
} MHL_RCP_CMD_T;


typedef enum {
	MHL_RCP_STATUS_OK = 0x00,
	MHL_RCP_FAIL=0x01,
	MHL_RCP_NOT_MHL=0x02,

} MHL_RCP_STATUS_T;


typedef struct  {
	char *name;
	int progressive;
	unsigned int h_act_len;
	unsigned int v_act_len;
	unsigned int lr_v_act_len;
	unsigned int v_active_space1;
	unsigned int v_active_space2;
}HDMI_ACTIVE_SPACE_TABLE_T;



typedef struct
{
    unsigned char   VSIF_TypeCode;
    unsigned char   VSIF_Version;
    unsigned char   Length;
    unsigned char   Reg_ID[3];
    unsigned char   Payload[25];
}HDMI_VSI_T;

typedef struct
{
    unsigned char type_code;
    unsigned char ver;
    unsigned char len;
    unsigned int    S:2;
    unsigned int    B:2;
    unsigned int    A:1;
    unsigned int    Y:3;
    unsigned int    R:4;
    unsigned int    M:2;
    unsigned int    C:2;
    unsigned int    SC:2;
    unsigned int    Q:2;
    unsigned int    EC:3;
    unsigned int    ITC:1;
    unsigned int    VIC:8;
    unsigned int    PR:4;
    unsigned int    CN:2;
    unsigned int    YQ:2;
    unsigned char   ETB07_00;
    unsigned char   ETB15_08;
    unsigned char   SBB07_00;
    unsigned char   SBB15_08;
    unsigned char   ELB07_00;
    unsigned char   ELB15_08;
    unsigned char   SRB07_00;
    unsigned char   SRB15_08;
}HDMI_AVI_T;

typedef struct
{
    unsigned char   type_code;
    unsigned char   ver;
    unsigned char   len;
    unsigned char   VendorName[8];
    unsigned char   ProductDesc[16];
    unsigned char   SourceInfo;
}HDMI_SPD_T;

typedef struct
{
    unsigned char type_code;
    unsigned char ver;
    unsigned char len;
    unsigned int    CC:3;
    unsigned int    F13:1;
    unsigned int    CT:4;
    unsigned int    SS:2;
    unsigned int    SF:3;
    unsigned int    F27_25:3;
    unsigned int    CXT:5;
    unsigned int    F37_35:3;
    unsigned int    CA:8;
    unsigned int    LFEPBL:2;
    unsigned int    F52:1;
    unsigned int    LSV:4;
    unsigned int    DM_INH:1;
    unsigned char   F67_60;
    unsigned char   F77_70;
    unsigned char   F87_80;
    unsigned char   F97_90;
    unsigned char   F107_100;
}HDMI_AUDIO_T;

typedef struct
{
        unsigned char type_code;
        unsigned char ver;
        unsigned char len;
        unsigned char  eEOTFtype;
        unsigned char  eMeta_Desc;
        unsigned short display_primaries_x0;
        unsigned short display_primaries_y0;
        unsigned short display_primaries_x1;
        unsigned short display_primaries_y1;
        unsigned short display_primaries_x2;
        unsigned short display_primaries_y2;
        unsigned short white_point_x;
        unsigned short white_point_y;
        unsigned short max_display_mastering_luminance;
        unsigned short min_display_mastering_luminance;
        unsigned short maximum_content_light_level;
        unsigned short maximum_frame_average_light_level;
		unsigned char  reserved;
}__attribute__((packed)) HDMI_DRM_T;



/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
// Should Not declare variables here






/**********************************************************************************************
*
*	External Funtion Declarations
*
**********************************************************************************************/

extern HDMI_COLOR_SPACE_T drvif_Hdmi_GetColorSpace(void);
extern HDMI_COLORIMETRY_T drvif_Hdmi_GetColorimetry(void);
extern HDMI_COLOR_DEPTH_T drvif_Hdmi_GetColorDepth(void);
extern HDMI_bool drvif_Hdmi_HdcpEnabled(void);
extern HDMI_bool  drvif_Hdmi_GetInterlace(void);
extern HDMI_DVI_MODE_T drvif_IsHDMI(void);
extern HDMI_RGB_YUV_RANGE_MODE_T drvif_IsRGB_YUV_RANGE(void); //cloud add
extern HDMI_3D_T drvif_HDMI_GetReal3DFomat(void);
extern char drvif_Hdmi_IsAudioLock(void);
unsigned char drvif_Hdmi_CheckStable_BeforeDisplay(void);

extern unsigned char drvif_Hdmi_WatchDog_Apply(unsigned char Enable, unsigned char Condition);

extern HDMI_bool drvif_hdmi_is_drm_info_ready(void);
extern unsigned char drvif_hdmi_is_drm_info_eEOTFtype(void);




/*60958*/
extern unsigned char drvif_Hdmi_GetConsumerUse(void); /* [0] */
extern unsigned char drvif_Hdmi_GetAudioSampleWord(void);  /* [1] */
extern unsigned char drvif_Hdmi_GetCopyright(void); /* [2] */
extern unsigned char drvif_Hdmi_GetFormatInfo(void); /* [5:3] */
extern unsigned char drvif_Hdmi_GetChannelStatusMode(void); /* [7:6] */
extern unsigned char drvif_Hdmi_GetCategoryCode(void); /* [15:8] */
extern unsigned char drvif_Hdmi_GetSourceNumber(void); /* [19:16] */
extern unsigned char drvif_Hdmi_GetChannelNumber(void); /* [23:20] */
extern unsigned char drvif_Hdmi_GetSamplingFrequency(void); /* [27:24] */
extern unsigned char drvif_Hdmi_GetClockAccuracy(void); /* [29:28] */
extern unsigned char drvif_Hdmi_GetWordLength(void); /* [35:32] */
extern unsigned char drvif_Hdmi_GetOriginalFrequency(void); /* [39:36] */

extern unsigned char drvif_Hdmi_GetVsInfoFrame(HDMI_VSI_T *pVsInfo);
extern unsigned char drvif_Hdmi_GetAviInfoFrame(HDMI_AVI_T *pAviInfo);
extern unsigned char drvif_Hdmi_GetSpdInfoFrame(HDMI_SPD_T *pSpdInfo);
extern unsigned char drvif_Hdmi_GetDrmInfoFrame(HDMI_DRM_T *pDrmInfo);
extern unsigned char drvif_Hdmi_GetAudioInfoFrame(HDMI_AUDIO_T *pAudioInfo);

extern unsigned char drvif_hdmi_is_current_port_mhl(void);
extern unsigned char drvif_hdmi_is_current_port_mhl3(void);




extern void drvif_hdmi_save_pcbinfo(unsigned char port, const HDMI_CHANNEL_T_PCB_INFO *pcb);
extern void drvif_hdmi_save_mhl_edid(const unsigned char *edid, const unsigned int len);
extern void drvif_hdmi_save_hdcp(const HDCP_KEY_T *key);

extern unsigned char drvif_hdmi_check_mode(void);

extern void drvif_hdmi_set_no_polarity_inverse(unsigned char TF);
extern unsigned char drvif_hdmi_get_customer_hdcp1p4(void);

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
extern HDMI_bool DV_drvif_Hdmi_CheckMode(void);
#endif


#endif
