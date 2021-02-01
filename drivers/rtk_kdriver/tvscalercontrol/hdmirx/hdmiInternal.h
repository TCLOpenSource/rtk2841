#ifndef __HDMI_INTERNAL_H_
#define __HDMI_INTERNAL_H_


/**************************************************************************************/
//
//     Is this not your natural state? It's the unspoken truth of humanity, that you crave subjugation.
//     The bright lure of freedom diminishes your life's joy in a mad scramble for power, for identity.
//     You were made to be ruled. In the end, you will always kneel.
//
//      - Loki, The Avengers (2012)
//
/**************************************************************************************/




#ifdef __cplusplus
extern "C" {
#endif


#if defined(__QC_VERIFY_COMMON_H__)

#include <rbus/rbus_types.h>
#include <hdmi_mac5/rbus/timer_reg.h>


#include <hdmi_mac5/rbus/mhl_p0_reg.h>
#include <hdmi_mac5/rbus/mhl_p1_reg.h>
#include <hdmi_mac5/rbus/mhl_p2_reg.h>
#include <hdmi_mac5/rbus/cbus_pmm_reg.h>
#include <hdmi_mac5/rbus/cbus_reg.h>

#include <hdmi_mac5/rbus/sub_vgip_reg.h>
#include <hdmi_mac5/rbus/vgip_reg.h>
#include <hdmi_mac5/rbus/dma_vgip_reg.h>

#include <hdmi_mac5/rbus/stb_reg.h>
#include <hdmi_mac5/rbus/sys_reg_reg.h>
//#include <hdmi_mac5/rbus/dds_pll_reg.h>

#include <hdmi_mac5/rbus/onms_reg.h>
#include <hdmi_mac5/rbus/offms_reg.h>
#include <hdmi_mac5/rbus/smartfit_reg.h>


#include <hdmi_mac5/rbus/iso_misc_ddc1_reg.h>
#include <hdmi_mac5/rbus/iso_misc_ddc2_reg.h>
#include <hdmi_mac5/rbus/iso_misc_ddc3_reg.h>
//#include <hdmi_mac5/rbus/iso_misc_ddc4_reg.h>
#include <hdmi_mac5/rbus/misc_ddc_reg.h>

#include <hdmi_mac5/hdmifun.h>
#include <hdmi_mac5/hdmi_reg.h>


#include <hdmi_mac5/MHL_CDF.h>
#include <hdmi_mac5/mhl_cbus.h>

#include <hdmi_mac5/rbus/pll27x_reg_reg.h>


#endif

/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/

#define CBUS_NOT_BYPASS			1    // 1: for normal flow   0 : for MHL CTS  TEST
#define VALID_MIN_CLOCK			116
#define HDMI2p0					0
#define HDCP22_PATCH_DEFAULT_EN		0
#define MEAS_RETRY_LIMIT			6
#define MHL_DATA_TIMEOUT			12
#define HDMI_MEASURE_BY_SMART_FIT		1
#define BITERR_PATCH				1
#define CK_MD_AUTO				0
#define AUDIO_HBR_DETECT			1

#define HDR10_MD_INFO_CHECK			1
#define HDMI_MEASURE_I3DDMA_SMART_FIT	1

#define BIST_PLUG_CABLE				0
#define BIST_DFE_SCAN				0

//USER:LewisLee DATE:2016/08/20
//just for short time 1080P 100Hz, 120Hz test
//It need webos modify FW
#define HDMI_120HZ_SHORT_TIME_PATCH		0 // 1

#if defined(CONFIG_HDMI_DRV_CONTROL_AVMUTE)
//USER:LewisLee DATE:2015/11/09
//Some Tx device, change timing have transient garbage
//clock chnage later than data change
//So need enable AV mute to fix it
//PS. It should be turn on 0xb8028300[15] is more better
#define HDMI_VIDEO_WD_ENABLE		1 // Video WatchDog function enable

//USER:willychou DATE:2017/08/23
//Sink CTS -avmute need display timing info
#define AVMUTE_HDMI_REDETECT  1
#endif
//USER:LewisLee Date:2016/09/30
//to fix colorimetry NG case
#define HDMI_AVI_INFO_COLORIMETRY_ENABLE				1
#define HDMI_AVI_INFO_COLORIMETRY_DEBOUNCE_CNT		25

//USER:LewisLee Date:2016/10/08
//Fix Tx send stable clock at first, and check HDCP later
#define HDMI_CHECK_HDCP_ENABLE				1
#define HDMI_HDCP_DEBOUNCE_CNT				25

//USER:LewisLee DATE:2016/10/25
//modify clk_debounce_count threshold value
//to prevent HDCP handshake too fast
//set phy disable HDCP 1.4 will let picture unstable
#define HDMI_PHY_CLOCK_DYNAMIC_CNT_ENABLE	1

#define DISP_DEB_CNT_APPLETV				2

#define TMDS_ERR_DET_SHORT_PERIOD		1

//WOSQRTK-10354, PC40000
//Video card : AMD radeon R9 390 / Intel HD 4600
//OC D5 8GB Tri-X NITRO - SAPPHIRE
#define DISP_DEB_CNT_PC40000				2

//USER:LewisLee DATE:2016/12/07
//to prevent audio thread create / destroy too many times
//if HDMI disconnect, and measure error
//It maybe call thread stop twice
#define AUDIO_THREAD_MODIFY				1

//USER:LewisLee DATE:2016/12/22
//WOSQRTK-10319, [STB-14] KT UHD STB (IC1000)
//STB DC off/on, will send AV mute after display, let it flicker
#define HDMI_TOGGLE_HPD_Z0_ENABLE		1
#define HDMI_START_TOGGLE_HPD_Z0_MS		5000
#define HDMI_TOGGLE_HPD_Z0_MS			400 // some times NG at 100 ~ 200, 500 ms is good
#define HDMI_DC_ON_DELAY_MS				5000 //OK, 3000ms NG

//USER:LewisLee DATE:2016/12/22
//WOSQRTK-10334, [STB-20] IC1100 - KT olleh GiGA UHD tv STB
//STR TV and STB DC off/on together, It will keep to send AVMute, can not display
#define HDMI_STR_TOGGLE_HPD_ENABLE		1
#define HDMI_STR_TOGGLE_HPD_MS			400

//speed up DC off/on by CEC enable/disable
#define HDMI_STR_HPD_SPEED_UP_ENABLE			0


//USER:LewisLee DATE:2016/12/26
//for Tx output stable clock => unstbale => stable
//let output flicker issue
#define HDMI_DISPLAY_DELAY_ENABLE		1

#define HDMI_DISPLAY_DELAY_LHB_755_MS		600
#define HDMI_DISPLAY_DELAY_LHB_755_MS_2		200

#define HDMI_DISPLAY_DELAY_ROKU_ULTRA_4640R_MS		1500 // large 1500ms OK

//USER:LewisLee DATE:2017/01/04
//for Roku Ultra 4640R, if TV DC off/on, some times it will HDCP 2.2 handshake error
//and can not output
//If DC off/on, some times it will output HDCP 1.4
#define HDCP_STATUS_CHECK_ENABLE		1
#define HDCP_STATUS_CHECK_TOGGLE_MS	10000

#define HDCP_STATUS_CHECK_ROKU_ULTRA_4640R_HPD_MS	600

#define HPD_DEFAULT_LOW_MS	100
#define HPD_ROKU_ULTRA_4640R_LOW_MS 1000




#define DEBUG_REG_ADDR			0xb800d108
#define DEBUG_31_BYPASS_CBUS		_BIT31
#define DEBUG_30_FORCE_MHL_PP		_BIT30
#define DEBUG_29_BYPASS_PHY_ISR	_BIT29
#define DEBUG_28_BYPASS_DETECT	_BIT28
#define DEBUG_27_BYPASS_CHECK		_BIT27
#define DEBUG_26_FORCE_6G		_BIT26

#define DEBUG_25_BITERR_DET		_BIT25


#define DEBUG_23_FORCE_NO_INFOPKT	_BIT23
#define DEBUG_22_FORCE_NO_DRMPKT	_BIT22

#define DEBUG_23_QC_PORT3		_BIT23
#define DEBUG_22_QC_PORT2		_BIT22
#define DEBUG_21_QC_PORT1		_BIT21
#define DEBUG_20_QC_PORT0		_BIT20
#define DEBUG_19_DUMP_REG		_BIT19
#define DEBUG_17_PRINT_AVI		_BIT17

#define DBG_FW_ADDR			0xb800d508
#define DBG_00_MHL3_16BIT		_BIT0
#define DBG_01_MHL3_ON			_BIT1	//default=6G
#define DBG_02_MHL3_3G			_BIT2
#define DBG_03_MHL3_1p5G		_BIT3

#define DBG_30_DFE_SCAN_TEST		_BIT30
#define DBG_31_PLUG_CABLE_TEST	_BIT31

#define HDMI_ABS(x, y)	 	((x > y) ? (x-y) : (y-x))
#define HDMI_CONST		const



extern const char* _hdmi_video_fsm_str(unsigned int fsm);
extern const char* _hdmi_audio_fsm_str(unsigned int fsm);
extern const char* _hdmi_color_space_str(unsigned char color_space);
extern const char* _hdmi_color_depth_str(unsigned char depth);

#if 1
#define SET_H_VIDEO_FSM(port, fsm)	(hdmi_rx[port].video_fsm = fsm)
#define SET_H_AUDIO_FSM(port, fsm)	(hdmi_rx[port].audio_fsm = fsm)
#else
#define SET_H_VIDEO_FSM(port, fsm)	do { if (hdmi_rx[port].video_fsm!=fsm) { pr_warn("[HDMI][FSM] VIDEO_FSM=%d(%s) -> %d(%s)\n", hdmi_rx[port].video_fsm, _hdmi_video_fsm_str(hdmi_rx[port].video_fsm), fsm, _hdmi_video_fsm_str(fsm)); hdmi_rx[port].video_fsm = fsm;  }  }while(0)
#define SET_H_AUDIO_FSM(port, fsm)	do { if (hdmi_rx[port].audio_fsm!=fsm) { pr_warn("[HDMI][FSM] AUDIO_FSM=%d(%s) -> %d(%s)\n", hdmi_rx[port].audio_fsm, _hdmi_audio_fsm_str(hdmi_rx[port].audio_fsm), fsm, _hdmi_audio_fsm_str(fsm)); hdmi_rx[port].audio_fsm = fsm;  }  }while(0)
#endif

#define SET_H_INTERLACE(port, interlace)	(hdmi_rx[port].timing_t.is_interlace = interlace)
#define SET_H_MODE(port, m)		(hdmi_rx[port].timing_t.mode = m)
#define SET_H_COLOR_DEPTH(port, color)	(hdmi_rx[port].timing_t.colordepth= color)
#define SET_H_COLOR_SPACE(port, color)	(hdmi_rx[port].timing_t.colorspace = color)
#define SET_H_PIXEL_REPEAT(port, pr)	(hdmi_rx[port].timing_t.pixel_repeat = pr)
#define SET_H_VIDEO_FORMAT(port, fmt)	(hdmi_rx[port].timing_t.hvf = fmt)
#define SET_H_3DFORMAT(port, fmt) 	(hdmi_rx[port].timing_t.h3dformat = fmt)

#define SET_MHL_ON(port, on)		(hdmi_rx[port].timing_t.is_mhl = on)
#define SET_MHL_PP_MODE(port, is_pp)	(hdmi_rx[port].timing_t.is_mhl_pp = is_pp)
#define SET_MHL_VER3(port, is_ver3)	(hdmi_rx[port].timing_t.is_mhl3 = is_ver3)

#define SET_AUDIO_TYPE(port, type)	(hdmi_rx[port].audio_type = type)



#define GET_H_VIDEO_FSM(port)		(hdmi_rx[port].video_fsm)
#define GET_H_AUDIO_FSM(port)		(hdmi_rx[port].audio_fsm)

#define GET_H_INTERLACE(port)		(hdmi_rx[port].timing_t.is_interlace)
#define GET_H_MODE(port)		(hdmi_rx[port].timing_t.mode)
#define GET_H_COLOR_DEPTH(port)	(hdmi_rx[port].timing_t.colordepth)
#define GET_H_COLOR_SPACE(port)	(hdmi_rx[port].timing_t.colorspace)
#define GET_H_PIXEL_REPEAT(port)	(hdmi_rx[port].timing_t.pixel_repeat)
#define GET_H_VIDEO_FORMAT(port) 	(hdmi_rx[port].timing_t.hvf)
#define GET_H_3DFORMAT(port) 		(hdmi_rx[port].timing_t.h3dformat)

#define GET_MHL_ON(port)		(hdmi_rx[port].timing_t.is_mhl)
#define GET_MHL_PP_MODE(port)		(hdmi_rx[port].timing_t.is_mhl_pp)
#define GET_MHL_VER3(port)		(hdmi_rx[port].timing_t.is_mhl3)

#define GET_AUDIO_TYPE(port)		(hdmi_rx[port].audio_type)


#define GET_VGIP_CHNx_CTRL_ADDR()		(vgip_ch ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg)
#define GET_VGIP_CHNx_STATUS_ADDR()		(vgip_ch ? SUB_VGIP_VGIP_CHN2_STATUS_reg : VGIP_VGIP_CHN1_STATUS_reg)
#define GET_VGIP_CHNx_V_CAP_ADDR()  		(vgip_ch ? SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg : VGIP_VGIP_CHN1_ACT_VSTA_Length_reg)
#define GET_VGIP_CHNx_H_CAP_ADDR()  		(vgip_ch ? SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg : VGIP_VGIP_CHN1_ACT_HSTA_Width_reg)
#define GET_VGIP_CHNx_DELAY_ADDR()  		(vgip_ch ? SUB_VGIP_VGIP_CHN2_DELAY_reg : VGIP_VGIP_CHN1_DELAY_reg)



#define GET_SFT_AUTO_FIELD_VADDR()				(SMARTFIT_AUTO_FIELD_reg)
#define GET_SFT_AUTO_H_BOUNDARY_VADDR()			(SMARTFIT_AUTO_H_BOUNDARY_reg)
#define GET_SFT_AUTO_V_BOUNDARY_VADDR()			(SMARTFIT_AUTO_V_BOUNDARY_reg)
#define GET_SFT_AUTO_ADJ_VADDR()					(SMARTFIT_AUTO_ADJ_reg)
#define GET_SFT_AUTO_RESULT_VSTA_END_VADDR() 	(SMARTFIT_AUTO_RESULT_VSTA_END_reg)
#define GET_SFT_AUTO_RESULT_HSTA_END_VADDR() 	(SMARTFIT_AUTO_RESULT_HSTA_END_reg)





#if MHL_SUPPORT
//--------------------------------------------------
// Definitions of MHL Status
//--------------------------------------------------
#define _MHL_STATE_INITIAL                                   0
#define _MHL_STATE_WAKE_UP_DONE                      1
#define _MHL_STATE_DISCOVERY_DONE                   2
#define _MHL_STATE_HPD_DONE                              3
#define _MHL_STATE_PATH_EN_DONE                       4
#define _MHL_STATE_DEV_CAP_RDY                         5

#define GET_MHL_PROCESS_STATE()                      (MHL_CTRL.MHL_CBUS_CMD_ST)
#define SET_MHL_PROCESS_STATE(x)                     (MHL_CTRL.MHL_CBUS_CMD_ST = (x))

#define GET_MHL_READY_TO_TRANSMIT()                 ((MHL_CTRL.Info & _BIT0) >> 0)
#define SET_MHL_READY_TO_TRANSMIT(x)               (MHL_CTRL.Info =((MHL_CTRL.Info & (~_BIT0))  | (((unsigned int) x & _BIT0) << 0)))

#define GET_MHL_RECONNECT_OK()                         ((MHL_CTRL.Info & _BIT1) >> 1)
#define SET_MHL_RECONNECT_OK(x)                       (MHL_CTRL.Info =((MHL_CTRL.Info & (~_BIT1))  | (((unsigned int) x & _BIT0) << 1)))

#define GET_MHL_READY_TO_RESEND()                 ((MHL_CTRL.Info & _BIT2) >> 2)
#define SET_MHL_READY_TO_RESEND(x)               (MHL_CTRL.Info =((MHL_CTRL.Info & (~_BIT2))  | (((unsigned int) x & _BIT0) << 2)))


#define GET_ISMHL()                                             ((MHL_CTRL.Info & _BIT3) >> 3)
#define SET_ISMHL(x)                                          (MHL_CTRL.Info =((MHL_CTRL.Info & (~_BIT3))  | (((unsigned int) x & _BIT0) << 3)))

#define GET_SETTINGMHL()                                             ((MHL_CTRL.Info & _BIT4) >> 4)
#define SET_SETTINGMHL(x)                                          (MHL_CTRL.Info =((MHL_CTRL.Info & (~_BIT4))  | (((unsigned int) x & _BIT0) << 4)))

#define GET_MHL_TIMER1_SEC()                 (MHL_CTRL.MHL_TIMER1 )
#define SET_MHL_TIMER1_SEC(x)               (MHL_CTRL.MHL_TIMER1 =(x))

#define GET_MHL_TIMER2_SEC()                 (MHL_CTRL.MHL_TIMER2 )
#define SET_MHL_TIMER2_SEC(x)               (MHL_CTRL.MHL_TIMER2 =(x))

#define GET_MHL_TIMER3_SEC()                 (MHL_CTRL.MHL_TIMER3 )
#define SET_MHL_TIMER3_SEC(x)               (MHL_CTRL.MHL_TIMER3 =(x))
#endif










/**********************************************************************************************
*
*	Enumerations or Structures
*
**********************************************************************************************/

// -------------------------------------  hdmiPhy ----------------------------------------------//


typedef struct {
	unsigned short b;
	unsigned short b_pre;
	unsigned short b_count;
	unsigned short b_debouce_count;
	unsigned short b_mhl_debounce;
	unsigned char b_change;
	unsigned char avi_info_in;
	unsigned short avi_info_miss_cnt;
	unsigned short LG_patch_timer;
	unsigned short timer;
	short    hotplug_timer;
	unsigned short hotplug_delay_count;
} HDMIRX_IOCTL_STRUCT_T;


typedef struct {
	u_int16_t b_upper;
	u_int16_t b_lower;

	u_int16_t M_code;
	u_int16_t N_code;
	u_int8_t pscaler;
	u_int8_t SEL_D4;
	u_int8_t CMU_KVCO;

	u_int8_t EN_CAP;
	u_int8_t CK_CS;
	u_int8_t CK_Icp;
	u_int8_t Icp_DUL;
	u_int8_t CK_RS;

	u_int8_t CK_LDOD;
	u_int8_t PI_DIV;
	u_int8_t DEMUX;
	u_int8_t RATE_SEL;
	u_int8_t PIX2_SEL;

	u_int8_t PI_ISEL;
	u_int8_t PI_CSEL;
	u_int8_t CDR_bias;
	u_int8_t CDR_KP;
	u_int8_t CDR_KP2;

	u_int8_t CDR_KI;
	u_int8_t CDR_KD;
	u_int8_t EQ_gain;
	u_int8_t EQ_bias;
	u_int8_t EQ_adj;

	u_int8_t PR;
	u_int8_t vsel_ldo;
	u_int8_t CMU_SEL_CP;
	u_int8_t PI_CURRENT;
	char *band_name;
} HDMI_PHY_PARAM_T;

#if 0
typedef struct {
	unsigned char vth;
	unsigned char tap0;
	unsigned char tap1;
	unsigned char tap1min;
	unsigned char le;
	char tap2;
	char tap2min;
	char tap2max;

} DFE_INIT_T;
#endif

typedef struct {
	unsigned int b_upper;
	unsigned int b_lower;
	unsigned int lock_up_limit; /*FLD upper bound*/
	unsigned int lock_dn_limit; /*FLD lower bound*/
	unsigned char cdr_bw_icp;
	unsigned char lfrs_sel;
	unsigned char vcogain;
	unsigned char hr_pd;
	unsigned char rate_sel;
} HDMI_ACDR_T;




#if 1//#if HDCP_STATUS_CHECK_ENABLE
/*
0x001: unauthenticated
0x002: compute km
0x004: compute L'
0x008: compute ks
0x010: authenticated
0x020: wait for downstream
0x040: assemble receiver ID list
0x080: verify receiver ID list acknowledgement
0x100: content stream management
0x200: content stream management from wait for downstream which has not been done
0x400: content stream management from assemble receiver ID list which has not been done
0x800: content stream management from verify receiver ID list acknowledgement which has not been done
*/

typedef enum {
	HDMI_HDCP_2P2_UNAUTH = 0x001,
	HDMI_HDCP_2P2_COMPUTE_KM = 0x002,
	HDMI_HDCP_2P2_COMPUTE_LP = 0x004,
	HDMI_HDCP_2P2_COMPUTE_KS = 0x008,
	HDMI_HDCP_2P2_AUTHENTICATED = 0x010,
	HDMI_HDCP_2P2_WAIT_FOR_DOWNSTREAM = 0x020,
	HDMI_HDCP_2P2_ASSEMBLE_RX_ID_LIST = 0x040,
	HDMI_HDCP_2P2_VERIFY_RX_ID_LIST_ACK = 0x080,
	HDMI_HDCP_2P2_CONTENT_STREAM_MANAGEMENT = 0x100,
	HDMI_HDCP_2P2_CONTENT_STREAM_MANAGEMENT_2 = 0x200,
	HDMI_HDCP_2P2_CONTENT_STREAM_MANAGEMENT_3 = 0x400,
	HDMI_HDCP_2P2_CONTENT_STREAM_MANAGEMENT_4 = 0x800,
	HDMI_HDCP_2P2_CONTENT_UNKNOW,
}  HDMI_HDCP_2P2_STATUS_T;

typedef enum {
	HDMI_HDCP_TOGGLE_NONE = 0,
	HDMI_HDCP_TOGGLE_INIT,
	HDMI_HDCP_TOGGLE_ENABLE,
	HDMI_HDCP_TOGGLE_EXIT,
	HDMI_HDCP_TOGGLE_UNKNOW,
}  HDMI_HDCP_TOGGLE_STATUS_T;
#endif //#if HDCP_STATUS_CHECK_ENABLE


// -------------------------------------  MHL ----------------------------------------------//

#if MHL_SUPPORT
typedef struct {
	unsigned int Info;   //[0] : cbus transmit ready or not
		//[1] : reconnect  or not
		//[2] : 1 sec rotine command  ,write ready command per 1 sec
		//[3] : MHL or not
	u_int16_t MHL_TIMER1;  // For release  SET_MHL_READY_TO_TRANSMIT
	u_int16_t MHL_TIMER2;  // For  RECONNECT_1K
	u_int16_t MHL_TIMER3;  // For CONNECT_DCAP_RDY command  1 sec send 1 times
	u_int8_t   MHL_CBUS_CMD_ST;
	u_int8_t   bBuf[16];

} MHL_PARAM_T;

typedef enum
{
	_MHL_WRITE_BURST_WITH_REQ,
	_MHL_WRITE_BURST_WITHOUT_REQ,
}EnumMHLWriteBurstMode;


typedef enum {

	MHL_CLK_TYPE_packedpixel_mode =2,
	MHL_CLK_TYPE_24_bit_mode,

} MHL_CLK_TYPE_T;

#endif









// -------------------------------------  HdmiHdmi ----------------------------------------------//

typedef enum {

	HDMIRX_DETECT_FAIL = 0,
	HDMIRX_DETECT_SUCCESS,
	HDMIRX_DETECT_AVMUTE,
	HDMIRX_CHECK_MODE,
	HDMIRX_RELEASED,

} HDMIRX_APSTATUS_T;

typedef struct {
	unsigned char SM;
	unsigned char SN;
	unsigned char RatioM;
	unsigned char RatioN;
} VIDEO_DPLL_RATIO_T;



typedef struct {
	unsigned char dpll_M;
	unsigned char dpll_N;
	unsigned char dpll_IP;
	unsigned char dpll_RS;
}VIDEO_DPLL_FIX_T;



typedef struct {
	unsigned char min_M;
	unsigned char max_M;
	unsigned char dpll_IP;
	unsigned char dpll_RS;

} VIDEO_DPLL_RANGE_T;

typedef enum {
	HDMI_AUDIO_N_CTS_TREND_BOUND = 0,
	HDMI_AUDIO_TREND_BOUND,
	HDMI_AUDIO_N_CTS,
} HDMI_AUDIO_TRACK_MODE;

typedef enum {
	HDMI_SMT_PATH_MAIN_VGIP = 0,
	HDMI_SMT_PATH_SUB_VGIP,
	HDMI_SMT_PATH_DMA_VGIP,
	HDMI_SMT_PATH_UNKNOW,
} HDMI_SMT_PATH;

#if 0

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
#endif





typedef struct {

	unsigned int v_total;
	unsigned int h_total;
	unsigned int v_act_len;
	unsigned int h_act_len;
	unsigned int v_act_sta;
	unsigned int h_act_sta;
	unsigned int v_freq;
	unsigned int h_freq;
	unsigned int polarity;
	unsigned int mode_id;
	unsigned int modetable_index;
	unsigned char is_interlace;
	unsigned int IVSyncPulseCount;	//Input VSYNC High Period Measurement Result

	HDMI_DVI_MODE_T 	mode;
	HDMI_COLOR_DEPTH_T colordepth;
	HDMI_COLOR_SPACE_T colorspace;
	HDMI_COLORIMETRY_T  colorimetry;
	unsigned char pixel_repeat;

	HDMI_HVF_E hvf;
	HDMI_3D_T h3dformat;

	unsigned int tmds_clk_b;

	unsigned char tmds_clk_stable_cnt;

	unsigned char is_mhl;
	unsigned char is_mhl_pp;
	unsigned char is_mhl3;

} HDMI_TIMING_T;

enum hdmi_rx_port_idx_e
{
       HDMI_RX_PORT_IDX_0 = 0,
       HDMI_RX_PORT_IDX_1,
       HDMI_RX_PORT_IDX_2,
       HDMI_RX_PORT_MAX_NUM,
       HDMI_RX_PORT_NOTUSED= HDMI_RX_PORT_MAX_NUM
};

typedef enum {
	MAIN_FSM_HDMI_WAIT_SYNC,
	MAIN_FSM_HDMI_SETUP_VEDIO_PLL,
	MAIN_FSM_HDMI_MEASURE,
	MAIN_FSM_HDMI_MEASURE_ACTIVE_SPACE,
	MAIN_FSM_HDMI_WAIT_READY,
	MAIN_FSM_HDMI_DISPLAY_ON,
	MAIN_FSM_HDMI_VIDEO_READY
} HDMI_MAIN_FSM_T;


typedef enum {
	AUDIO_FSM_AUDIO_START = 0,
	AUDIO_FSM_FREQ_DETECT,
	AUDIO_FSM_AUDIO_WAIT_TO_START,
	AUDIO_FSM_AUDIO_START_OUT,
	AUDIO_FSM_AUDIO_WAIT_PLL_READY,
	AUDIO_FSM_AUDIO_CHECK
} HDMI_AUDIO_FSM_T;


typedef enum {

	AUDIO_FORMAT_LPCM = 0,
	AUDIO_FORMAT_NONLPCM

} HDMI_AUDIO_FORMAT_T;

typedef enum {
	HDMI_MS_ONESHOT = 0,
	HDMI_MS_CONTINUOUS,
	HDMI_MS_DIRECT
} HDMI_MS_T;

typedef enum _HDMI_HDCP_{
	NO_HDCP = 0,
	HDCP14,
	HDCP22
}HDMI_HDCP_E;

#if 1//#if HDMI_TOGGLE_HPD_Z0_ENABLE
typedef enum _HDMI_DC_ON_STATE_{
	HDMI_DC_ON_NONE = 0,
	HDMI_DC_ON_ENABLE_DELAY,
	HDMI_DC_ON_START_TIME,
	HDMI_DC_ON_FINISH,
	HDMI_DC_ON_UNKNOW
}HDMI_DC_ON_STATE_E;
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

#if 1//#if HDMI_STR_TOGGLE_HPD_ENABLE
typedef enum _HDMI_STR_HPD_TOGGLE_STATE_{
	HDMI_STR_HPD_TOGGLE_NONE = 0,
	HDMI_STR_HPD_TOGGLE_ENTER,
	HDMI_STR_HPD_TOGGLE_READY,
	HDMI_STR_HPD_TOGGLE_UNKNOW,
}HDMI_STR_HPD_TOGGLE_STATE_E;
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE

#if 1//#if HDMI_DISPLAY_DELAY_ENABLE
typedef enum _HDMI_DISPLAY_DELAY_STATE_{
	HDMI_DISPLAY_DELAY_NONE = 0,
	HDMI_DISPLAY_DELAY_INIT,
	HDMI_DISPLAY_DELAY_START,
	HDMI_DISPLAY_DELAY_FINISH,
}HDMI_DISPLAY_DELAY_STATE_STATE_E;
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

#if 1//#if HDMI_DISPLAY_DELAY_ENABLE
typedef enum _HDMI_SPECIFIC_DEVICE_{
	HDMI_SPECIFIC_DEVICE_NONE = 0,
	HDMI_SPECIFIC_DEVICE_SK_STB,
	HDMI_SPECIFIC_DEVICE_KT_STB_IC1000,
	HDMI_SPECIFIC_DEVICE_KT_STB_IC1100,
	HDMI_SPECIFIC_DEVICE_LHB_755, // [HOME-05] LHB755 - LG
	HDMI_SPECIFIC_DEVICE_ROKU_ULTRA_4640R,
}HDMI_SPECIFIC_DEVICE_E;
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

typedef struct {
	unsigned long ACR_freq;			// Audio Frequency from ACR
	unsigned long AudioInfo_freq;		// Audio Frequency from Audio Info Frame
	unsigned long SPDIF_freq;			// Audio Frequency from SPDIF Channel Status Info
	unsigned int ACR_N;
} HDMI_AUDIO_FREQ_T;

typedef struct {
	unsigned int   freq;
	unsigned char coeff;
	unsigned char rate;
} HDMI_AUDIO_PLL_COEFF_T;






typedef struct {

	unsigned char N;
	unsigned char M;
	unsigned char O;
	unsigned char S;
	unsigned char S1;
	unsigned int D_HighByte;
	unsigned int D_LowByte;
	const char *sample_rate;

} HDMI_AUDIO_PLL_PARAM_T;

typedef struct {
	unsigned char coding_type; // 0=pcm; 1=nonpcm
	unsigned char sr_mismatch_cnt;
	unsigned char track_mode_tgl;
} HDMI_AUDIO_ST;


typedef struct {

	HDMI_PHY_PARAM_T phy_param_t;

	HDMI_TIMING_T timing_t;
	HDMI_AUDIO_ST audio_t;

	HDMI_AVI_T avi_t;
	HDMI_VSI_T vsi_t;
	HDMI_SPD_T spd_t;
	HDMI_AUDIO_T audiopkt_t;
	HDMI_DRM_T drm_t;
	unsigned char no_avi_cnt;
	unsigned char no_vsi_cnt;
	unsigned char no_spd_cnt;
	unsigned char no_audiopkt_cnt;
	unsigned char no_drm_cnt;


	HDMI_MAIN_FSM_T video_fsm;
	HDMI_AUDIO_FSM_T audio_fsm;


#if HDMI2p0
	unsigned char scramble_flag;
	unsigned char clock40x_flag;
	unsigned char hdmi2p0_tmds_toggle_flag;
#endif

	unsigned char tx_aksv[5];
	HDMI_HDCP_E hdcp_authing;	// 0=no hdcp; 1=hdcp1.4; 2=hdcp2.2
#if HDCP2_2 && HDCP22_PATCH_DEFAULT_EN
	unsigned char hdcp_init_period;	// Timeout to reset to turn on (hdcp1.4/2.2), while no sync
#endif

	unsigned char cable_conn;	// 5V or not
	unsigned char vs_cnt;

	unsigned char meas_retry_cnt;

} HDMI_PORT_INFO_T;



typedef struct {
	unsigned char spd_vn_name[8];
	unsigned char psd_pd_desc[16];
} HDMI_POOR_DEV_T;



typedef struct{
	unsigned int h_act;
	unsigned int v_act;
	unsigned int h_tol;
	unsigned int v_tol;
}HDMI_TIMING_TABLE_T;




typedef enum {
	ACKG = 0,
	SPD_INFO,
	DRM_INFO,
	FVS,
	GM,
	VS_INFO,
	MPEG_INFO,
	ISRC2,
	ISRC1,
	ACP,
	AUDIO_INFO,
	AVI_INFO,
	ALL_PKT
} HDMI_PACKET_CONTENT_CLR;


/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
extern const VIDEO_DPLL_RATIO_T dpll_ratio[];
#if MHL_SUPPORT
extern MHL_PARAM_T MHL_CTRL;
#endif
extern const HDMI_ACTIVE_SPACE_TABLE_T hdmi_active_space_table[];










/**********************************************************************************************
*
*	External Funtion Declarations
*
**********************************************************************************************/
#include <rtk_gpio.h>

// -------------------------------------  MHL ----------------------------------------------//
#if MHL_SUPPORT
extern u_int8_t MHLNormalPreDetect(void);
extern void mhl_fill_burst_chksum(unsigned char *buf);
extern u_int8_t MHLMscSendWriteBurst( u_int8_t ucOffset, u_int8_t ucDataLength, u_int8_t *pucData, EnumMHLWriteBurstMode enumMode);
extern unsigned char MHL_GetScratchpad(unsigned char len, unsigned char *scr);
extern unsigned char mhl_get_msc_write_burst(void);
extern void mhl_write_burst_handler(void);
extern unsigned char mhl_get_bist_trigger(void);
extern unsigned char mhl_get_bist_request_stat(void);
extern unsigned char mhl_get_bist_ready(void);
extern unsigned char mhl_get_bist_stop(void);
extern unsigned char MHLMscCheckDeviceINT(void);
extern void  MHLMscRAPHandler(void);
extern u_int8_t MHLMscRAPGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscRAPKGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscRCPGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscRCPKGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscRCPEGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscUCPGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscUCPKGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscUCPEGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscMSGEGetCommand(u_int8_t *pucKeyCode);
extern u_int8_t MHLMscRBPGetCommand(u_int8_t *pucKeyCode);
extern void MHLMscRBPHandler(void);
extern void CBUS_TIMER_Handle_ISR(void);
extern void UserMHLMscCHECK_MODE(void);
extern HDMI_bool Cbus_SEND_UCP_SUB_Command(unsigned char bKeyCode);
extern void CBUSSwitch( u_int8_t benable);
extern void mhl_release(void);
extern void MHL_Z100k_Switch(u_int8_t port, u_int8_t benable);
extern void mhl_clk_switch(u_int8_t bchannel, u_int8_t benable);
extern void MHLSwitch(u_int8_t bchannel, u_int8_t benable);
extern void mhl3_set_24_16bit(void);
extern void mhl_disconnect(void);
extern void MHLCBUS_ISR(void);
extern void CBUS_InitialPHYSettings(void);
extern void MHLInitialMACSettings(void);
extern void MHLTmdsInitial(void);
extern void CBUSLINKClk(u_int8_t  bmode);

extern void MHL_setPPMode(unsigned char pp);
extern unsigned char MHL_IsPPMode(void);
extern unsigned char Cbus_SEND_RCP_SUB_Command(unsigned char  bKeyCode);
extern void Cbus_GET_RCPK_SUB_Command(void);
extern void SimpleMHLTMDSPhy(u_int32_t bvalue, char force);
extern unsigned char drvif_MHL_DetectMode(void);
extern u_int8_t  READ_RCP_FIFO(void);
extern void MHL_CheckPPMode(void);
extern void lib_mhl_mac_init(unsigned char nport);
extern unsigned char lib_mhl_port_is_ppmode(unsigned char nport);
extern unsigned char lib_mhl_port_is_turn_on(unsigned char nport);
extern unsigned char lib_mhl_port_is_mhl3(unsigned char nport);
extern void lib_mhl3_set_24_16bit(unsigned char nport, unsigned char bpp_16);
extern unsigned char mhl_is_ver3x(void);
extern u_int8_t MHLMscFIFOSendCommand( u_int8_t enumMSCCommand, u_int8_t enumMSCOffset, u_int8_t enumMSCValue, u_int8_t ucDataLength, u_int8_t *pucData);
extern u_int8_t MHLMscSendCommand( u_int8_t enumMSCCommand, u_int8_t enumMSCOffset, u_int8_t enumMSCValue);

#endif


// -------------------------------------  hdmiHdmi ----------------------------------------------//
extern void newbase_hdmi_init(void);
extern void newbase_hdmi_uninit(void);
extern void newbase_hdmi_init_source(unsigned char port);
extern void newbase_hdmi_release_source(unsigned char port);
extern void newbase_hdmi_disconnect_source(unsigned char port);

void newbase_hdmi_port_select(unsigned char port);

extern void newbase_hdmi_port_var_init_all(void);
extern void newbase_hdmi_port_var_init(unsigned char port);

extern unsigned char newbase_hdmi_detect_mode(unsigned char port);
extern unsigned char newbase_hdmi_check_condition_change(unsigned char port);
extern unsigned char newbase_hdmi_wait_sync(unsigned char port);
extern unsigned char newbase_hdmi_setup_video_pll(unsigned char port);
extern unsigned char newbase_hdmi_measure(unsigned char port);
extern unsigned char newbase_hdmi_display_on(unsigned char port);
extern unsigned char newbase_hdmi_video_ready(unsigned char port);
extern unsigned char newbase_hdmi_check_mode(void);



extern void newbase_hdmi_reset_video_state(unsigned char port);
extern unsigned char newbase_hdmi_get_video_state(unsigned char port);
extern void newbase_hdmi_reset_meas_counter(unsigned char port);

extern void newbase_hdmi_check_crc_0(unsigned char nport);


extern void newbase_hdcp_init_timer(unsigned char port);
extern void newbase_hdcp_handler(unsigned char port);
extern unsigned char newbase_hdcp_get_auth_mode(unsigned char port);

extern void newbase_hdmi2p0_check_tmds_config(unsigned char port);
extern unsigned char newbase_hdmi2p0_get_scramble_flag(unsigned char port);
extern unsigned char newbase_hdmi2p0_get_clock40x_flag(unsigned char port);
extern void newbase_hdmi2p0_detect_config(unsigned char port);
extern void newbase_hdmi2p0_reset_scdc_toggle(unsigned char port);
extern void newbase_hdmi2p0_inc_scdc_toggle(unsigned char port);




extern void newbase_hdmi_set_current_display_port(unsigned char port);
extern unsigned char newbase_hdmi_get_current_display_port(void);

extern unsigned char newbase_hdmi_get_timing(unsigned char port, HDMI_TIMING_T *ptiming);
extern unsigned char newbase_hdmi_get_hvstart(unsigned char port, HDMI_TIMING_T *ptiming, unsigned char vsc_ch);
extern unsigned char newbase_hdmi_get_interlace_conti_mode(unsigned char nport);
extern unsigned char newbase_hdmi_get_is_interlace(unsigned char port);
extern unsigned char newbase_hdmi_get_hdmi_mode_reg(unsigned char port);
extern unsigned char newbase_hdmi_get_hdmi_mode(unsigned char port);
extern unsigned char newbase_hdmi_get_colordepth(unsigned char port);
extern unsigned char newbase_hdmi_get_colorspace_reg(unsigned char port);
extern unsigned char newbase_hdmi_get_colorspace(unsigned char port);
extern unsigned char newbase_hdmi_get_video_format_reg(unsigned char port);
extern unsigned char newbase_hdmi_get_video_format(unsigned char port);
extern unsigned char newbase_hdmi_get_3d_structure_reg(unsigned char port);
extern unsigned char newbase_hdmi_get_3d_structure(unsigned char port);
extern unsigned char newbase_hdmi_get_colorimetry(unsigned char port);
extern unsigned char newbase_hdmi_get_color_range(unsigned char port);
extern unsigned char newbase_hdmi_get_audio_coding_type(unsigned char *code_type);
extern unsigned int newbase_hdmi_get_tmds_clockx10(unsigned char port);



extern void newbase_hdmi_set_is_mhl(unsigned char port, unsigned char is_mhl);
extern unsigned char newbase_hdmi_get_is_mhl(unsigned char port);
extern void newbase_hdmi_set_is_mhl_ppmode(unsigned char port, unsigned char is_mhl_pp);
extern unsigned char newbase_hdmi_get_is_mhl_ppmode(unsigned char port);
extern void newbase_hdmi_set_is_mhl3(unsigned char port, unsigned char is_mhl3);
extern unsigned char newbase_hdmi_get_is_mhl3(unsigned char port);


extern void newbase_hdmi_audio_var_init(unsigned char port);
extern unsigned char newbase_hdmi_audio_is_pll_ready(unsigned char nport);
extern unsigned char newbase_hdmi_audio_set_pll(unsigned char nport, unsigned int freq, unsigned char ucACR_N,HDMI_AUDIO_TRACK_MODE track_mode);
extern void newbase_hdmi_audio_get_freq(unsigned char nport, HDMI_AUDIO_FREQ_T *freq, HDMI_AUDIO_TRACK_MODE *track_mode);
extern unsigned char newbase_hdmi_audio_detect(void);
extern void newbase_hdmi_audio_close(unsigned char port);
extern void newbase_hdmi_audio_reset_status(void);
extern unsigned char newbase_hdmi_audio_get_current_status(void);
extern unsigned char newbase_hdmi_audio_wait_acr(unsigned char port);
extern unsigned char newbase_hdmi_audio_wait_sample(unsigned char port);
extern unsigned char newbase_hdmi_audio_wait_2_samples(unsigned char port);



// Configurations
extern void newbase_hdmi_save_pcbinfo(unsigned char port, const HDMI_CHANNEL_T_PCB_INFO *pcb);

// HDP & 5V DET related
extern unsigned char newbase_hdmi_get_5v_state(unsigned char port);
extern void newbase_hdmi_set_hpd(unsigned char nport, unsigned char high, unsigned char controllable);
extern void newbase_hdmi_hpd_delay_work_init(void);
extern void newbase_hdmi_check_connection_state(unsigned char port);


// EDID related
extern void newbase_hdmi_edid_enable(unsigned char port, unsigned char enable);
extern void newbase_hdmi_read_edid(unsigned char port, unsigned char *edid, unsigned int len);
extern void newbase_hdmi_write_edid(unsigned char port, unsigned char *edid, unsigned int len);
extern void newbase_hdmi_save_edid(unsigned char port, const unsigned char *edid, const unsigned int len);
extern int  newbase_hdmi_edid_initialized(unsigned char port);

extern void newbase_hdmi_load_edid(unsigned char channel_index, unsigned char *EDID, int len);
extern void newbase_hdmi_mhl_write_edid(unsigned char *edid, unsigned int len);
extern void newbase_hdmi_mhl_edid_enable(unsigned char enable);
extern void newbase_hdmi_control_pull_up_1k(void);
extern void newbase_hdmi_save_mhl_edid(const unsigned char *edid, const unsigned int len);
extern void newbase_hdmi_save_hdcp(const HDCP_KEY_T *key);

// HDCP related
extern void newbase_hdmi_read_aksv(unsigned char port, unsigned char *pAKSV);
extern void newbase_hdmi_read_hdcp14_key(unsigned char *bksv, unsigned char *hdcp_key);
extern void newbase_hdmi_write_hdcp14_key(unsigned char *bksv, unsigned char *hdcp_key);

// Info frame related
extern void newbase_hdmi_reset_all_infoframe(unsigned char port);
extern void newbase_hdmi_update_infoframe(unsigned char nport);
extern unsigned char newbase_hdmi_get_hdmi_mode_infoframe(unsigned char port);
extern unsigned char newbase_hdmi_get_vs_infoframe(unsigned char port, HDMI_VSI_T *p_vsi_t);
extern unsigned char newbase_hdmi_get_avi_infoframe(unsigned char port, HDMI_AVI_T *p_avt_t);
extern unsigned char newbase_hdmi_get_spd_infoframe(unsigned char port, HDMI_SPD_T *p_spd_t);
extern unsigned char newbase_hdmi_get_audio_infoframe(unsigned char port, HDMI_AUDIO_T *p_audio_t);
extern unsigned char newbase_hdmi_get_drm_infoframe(unsigned char port, HDMI_DRM_T *p_drm_t);

extern unsigned char newbase_hdmi_check_stable_before_display(void);
extern unsigned char newbase_hdmi_watchdog_apply(unsigned char Enable, unsigned char Condition);

extern void newbase_hdmi_set_info(unsigned char port);

#if HDCP2_2 // HDCP2_2
extern void  newbase_msg_hander(unsigned char port);
//extern void newbase_hdmi_hdcp2_clear_status(unsigned char port);
#endif

unsigned char newbase_hdmi_is_dispsrc(unsigned char disp);
unsigned char newbase_hdmi_get_avmute(unsigned char port);

//Minchay@20160607-a-s add hdr10 and dolby version hdr
extern void newbase_hdmi_dv_hdr_enable(unsigned char detectEn);
extern void newbase_hdmi_hdr10_enable(unsigned char detectEn);
extern unsigned char newbase_hdmi_dv_hdr_md_info_check(void);
extern unsigned char newbase_hdmi_hdr10_md_info_check(void);
extern void newbase_hdmi_hdr_disable(void);
//Minchay@20160607-a-e add hdr10 and dolby version hdr


void newbase_hdmi_save_customer_hdcp1p4(unsigned char* hdcp_1p4, unsigned int len );
void newbase_hdmi_save_customer_hdcp2p2(unsigned char* hdcp_2p2, unsigned int len );
extern unsigned char newbase_hdmi_get_customer_hdcp1p4(void);
extern unsigned char newbase_hdmi_get_customer_hdcp2p2(void);
extern unsigned char* newbase_hdmi_get_customer_hdcp2p2_table(void);
extern void newbase_hdmi_clear_table(void);


extern void lib_hdmi_crt_on(void);
extern void lib_hdmi_power(unsigned char port, unsigned char enable);
extern void lib_hdmi_tmds_init(unsigned char port);
extern void lib_hdmi_mac_init(unsigned char port);

extern void lib_hdmi_hdcp_init(unsigned char nport);
extern void lib_hdmi_write_hdcpkey(unsigned char nport, unsigned char *bksv, unsigned char *hdcp_key);
extern void lib_hdmi_read_hdcpkey(unsigned char nport, unsigned char *bksv, unsigned char *hdcp_key);
extern void lib_hdmi_hdcp14_enable(unsigned char port, unsigned char on);
extern unsigned char lib_hdmi_hdcp14_is_onoff(unsigned char nport);
#if HDMI_STR_HPD_SPEED_UP_ENABLE
extern unsigned char lib_hdmi_cec_is_enabled(void);
#endif

extern unsigned char lib_hdcp14_check_aksv_reg(unsigned char port);
extern void lib_hdcp14_clear_aksv_reg(unsigned char port);
extern unsigned char lib_hdcp14_check_bksv_reg(unsigned char nport);
extern void lib_hdcp14_clear_bksv_reg(unsigned char nport);
extern void lib_hdmi_hdcp_port_write_conti(unsigned char port, unsigned char addr, const unsigned char* value, unsigned char num);
extern void lib_hdmi_hdcp_port_write(unsigned char port, unsigned char addr ,unsigned char value);
extern unsigned char lib_hdmi_hdcp_port_read(unsigned char port, unsigned char addr);

#if HDCP2_2 // HDCP2_2
extern void lib_hdmi_hdcp22_enable(unsigned char port, unsigned char enable);
extern unsigned char lib_hdmi_hdcp22_is_onoff(unsigned char nport);
extern unsigned char lib_hdmi_hdcp22_get_auth_done(unsigned char nport);
extern void lib_hdmi_hdcp22_init(unsigned char port);
#endif


extern void lib_hdmi_ddc_sel(unsigned char nport, unsigned char ddc_ch);
extern void lib_hdmi_mac_select_port(unsigned char port);
extern void lib_hdmi_meas_select_port(unsigned char nport);
extern unsigned char lib_hdmi_is_rgb_status_ready(unsigned char nport);
extern void lib_hdmi_clear_rgb_status(unsigned char nport);
extern unsigned char lib_hdmi_vsync_checked(unsigned char nport);
extern unsigned char lib_hdmi_get_color_depth(unsigned char port);
extern void lib_hdmi_clear_interlace_reg(unsigned char port);
extern unsigned char lib_hdmi_get_is_interlace(unsigned char port, HDMI_MS_T one_shot_mode);
extern void lib_hdmi_set_repeat_manual(unsigned char port, unsigned char rep_value);
extern void lib_hdmi_set_repeat_auto(unsigned char port);
extern unsigned char lib_hdmi_get_pixelrepeat(unsigned char port);
extern void lib_hdmi_set_colorspace_manual(unsigned char port, unsigned char color_space);
extern void lib_hdmi_set_colorspace_auto(unsigned char port);
extern unsigned char lib_hdmi_get_colorspace(unsigned char port);

extern unsigned char lib_hdmi_is_hdmi_mode(unsigned char port);
extern unsigned char lib_hdmi_get_video_format(unsigned char port);
extern unsigned char lib_hdmi_get_3d_structure(unsigned char nport);
extern unsigned char lib_hdmi_get_3d_extdata(unsigned char port);
extern unsigned char lib_hdmi_get_vsi_vic(unsigned char port);

extern unsigned char lib_hdmi_set_video_pll(unsigned char nport, unsigned int b_clk, unsigned char cd, unsigned char is_interlace, unsigned char is_420, unsigned char is_mhl);
extern void lib_hdmi_video_output(unsigned char port, unsigned char on);
extern unsigned char lib_hdmi_is_video_output(unsigned char nport);

extern void lib_hdmi_clear_avmute(unsigned char port);
extern unsigned char lib_hdmi_get_avmute(unsigned char port);
extern unsigned char lib_hdmi_get_bch_1bit_error(unsigned char port);
extern unsigned char lib_hdmi_get_bch_2bit_error(unsigned char port);
extern void lib_hdmi_bch_error_clr(unsigned char nport);
extern void lib_hdmi_wdm_enable(unsigned char nport, unsigned char enable);
extern unsigned char lib_hdmi_is_wdm_enable(unsigned char nport);
extern void lib_hdmi_auto_avmute_enable(unsigned char nport, unsigned char enable);
extern unsigned char lib_hdmi_is_auto_avmute_enable(unsigned char nport);
extern void lib_hdmi_tmds_out_ctrl(unsigned char nport, unsigned char bypass, unsigned int r, unsigned int g, unsigned int b);
extern void lib_hdmi_mac_afifo_enable(unsigned char nport);
extern void lib_hdmi_420_en(unsigned char nport, unsigned char en);
extern void lib_hdmi_crc_check(unsigned char nport);
extern unsigned int lib_hdmi_read_crc(unsigned char nport);
extern void lib_hdmi_dbg_reg_dump(unsigned char nport);

extern unsigned char lib_hdmi_get_mhl_5v(void);
extern void lib_hdmi_control_pull_up_1k(unsigned char up1k);



extern void lib_hdmi_scdc_write(unsigned char nport, unsigned char addr,unsigned char value);
extern unsigned char lib_hdmi2p0_get_tmds_config(unsigned char port);
extern void lib_hdmi2p0_reset_scdc(unsigned char port);
extern void lib_hdmi2p0_scdc_update_flag(unsigned char port);
extern void lib_hdmi2p0_scramble_enable(unsigned char port, unsigned char on_off);
extern void lib_hdmi_read_packet_sram(unsigned char nport, unsigned int start_addr, unsigned char len, unsigned char *pbuf);
extern unsigned char lib_hdmi_is_fvs_received(unsigned char nport);
extern void lib_hdmi_clear_fvs_received_status(unsigned char nport);
extern unsigned char lib_hdmi_is_vs_received(unsigned char nport);
extern void lib_hdmi_clear_vs_received_status(unsigned char nport);
extern unsigned char lib_hdmi_is_avi_received(unsigned char nport);
extern void lib_hdmi_clear_avi_received_status(unsigned char nport);
extern unsigned char lib_hdmi_is_spd_received(unsigned char nport);
extern void lib_hdmi_clear_spd_received_status(unsigned char nport);
extern unsigned char lib_hdmi_is_audiopkt_received(unsigned char nport);
extern void lib_hdmi_clear_audiopkt_received_status(unsigned char nport);
extern unsigned char lib_hdmi_is_drm_received(unsigned char nport);
extern void lib_hdmi_clear_drm_received_status(unsigned char nport);
extern void lib_hdmi_set_rsv_packet_type(unsigned char nport, unsigned char index, unsigned char pkt_type);
extern unsigned char lib_hdmi_is_rsv_packet0_received(unsigned char nport);
extern void lib_hdmi_clear_rsv_packet0_status(unsigned char nport);
extern unsigned char lib_hdmi_is_rsv_packet1_received(unsigned char nport);
extern void lib_hdmi_clear_rsv_packet1_status(unsigned char nport);
extern unsigned char lib_hdmi_is_rsv_packet2_received(unsigned char nport);
extern void lib_hdmi_clear_rsv_packet2_status(unsigned char nport);
extern unsigned char lib_hdmi_is_rsv_packet3_received(unsigned char nport);
extern void lib_hdmi_clear_rsv_packet3_status(unsigned char nport);

#if HDMI_TOGGLE_HPD_Z0_ENABLE
extern void lib_hdmi_set_toggle_hpd_z0_flag(unsigned char nport, unsigned char uc_flag);
extern unsigned char lib_hdmi_get_toggle_hpd_z0_flag(unsigned char nport);
extern unsigned char lib_hdmi_toggle_hpd_z0_check(unsigned char nport, unsigned char ucInit);
extern void lib_hdmi_set_dc_on_delay_state(unsigned char nport, HDMI_DC_ON_STATE_E state);
extern HDMI_DC_ON_STATE_E lib_hdmi_get_dc_on_delay_state(unsigned char nport);
extern unsigned char lib_hdmi_dc_on_delay_check(unsigned char nport, unsigned char ucInit);
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

#if HDMI_STR_TOGGLE_HPD_ENABLE
void lib_hdmi_set_str_toggle_hpd_state(unsigned char nport, HDMI_STR_HPD_TOGGLE_STATE_E state);
HDMI_STR_HPD_TOGGLE_STATE_E lib_hdmi_get_str_toggle_hpd_state(unsigned char nport);
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE

#if HDMI_DISPLAY_DELAY_ENABLE
extern void lib_hdmi_set_delay_display_enable(unsigned char nport, unsigned char ucEnable);
extern unsigned char lib_hdmi_get_delay_display_enable(unsigned char nport);
extern void lib_hdmi_set_delay_display_state(unsigned char nport, HDMI_DISPLAY_DELAY_STATE_STATE_E state);
extern HDMI_DISPLAY_DELAY_STATE_STATE_E lib_hdmi_get_delay_display_state(unsigned char nport);
extern unsigned char lib_hdmi_delay_check_before_display(unsigned char nport, unsigned char ucInit);
extern unsigned int lib_hdmi_get_delay_display_time(unsigned char nport);
extern unsigned char lib_hdmi_delay_display_action(unsigned char port);
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

void lib_hdmi_set_specific_device(unsigned char nport, HDMI_SPECIFIC_DEVICE_E device);
HDMI_SPECIFIC_DEVICE_E lib_hdmi_get_specific_device(unsigned char nport);

extern void lib_hdmi_misc_variable_initial(unsigned char port);

#if HDCP_STATUS_CHECK_ENABLE
extern void lib_hdmi_set_hdcp_check_toggle_state(unsigned char nport, HDMI_HDCP_TOGGLE_STATUS_T status);
extern HDMI_HDCP_TOGGLE_STATUS_T lib_hdmi_get_hdcp_check_toggle_state(unsigned char nport);
extern unsigned char lib_hdmi_hdcp_status_check(unsigned char nport, unsigned char IsInit);
extern unsigned char lib_hdmi_hdcp_toggle_action(unsigned char nport);
#endif //#if HDCP_STATUS_CHECK_ENABLE

extern void lib_hdmi_audio_pv_wd_enable(unsigned char nport, unsigned char on_off);
extern void lib_hdmi_video_pv_wd_enable(unsigned char nport, unsigned char on_off);
extern void lib_hdmi_pv_irq_enable(unsigned char nport, unsigned char on_off);
extern void lib_hdmi_packet_contnet_clear(unsigned nport, unsigned char pkt_type);


//dolby detect
extern void lib_hdmi_enable_hdr_dolby_meta_info_check(unsigned char on_off);
extern void lib_hdmi_enable_hdr_dolby_md_detect(unsigned char on_off);


extern unsigned char lib_hdmi_hdr_dolby_detect_res_change(void);
extern unsigned char lib_hdmi_hdr_dolby_res_det(void);
extern unsigned char lib_hdmi_hdr_dolby_frame_crc_det(void);



// ---------------- audio -------------------------------------------//
extern void lib_hdmi_audio_init(unsigned char port);
extern unsigned char lib_hdmi_audio_is_nonpcm(unsigned char port);
extern void lib_hdmi_audio_pop_n_cts(unsigned char port);
extern unsigned char lib_hdmi_audio_pop_n_cts_done(unsigned char port);
extern unsigned int lib_hdmi_audio_get_n(unsigned char port);
extern unsigned int lib_hdmi_audio_get_cts(unsigned char port);
extern void lib_hdmi_audio_clear_fs(unsigned char port);
extern unsigned char lib_hdmi_audio_fs_from_cs(unsigned char port);
extern unsigned char lib_hdmi_audio_get_freq_from_cs(unsigned char port);
extern void lib_hdmi_audio_cts_bound(unsigned char nport, unsigned int clk);
extern void lib_hdmi_audio_n_bound(unsigned char nport, unsigned int freq);
extern unsigned char lib_hdmi_audio_is_pll_unlock(unsigned char port);
extern void lib_hdmi_audio_wclr_pll_unlock(unsigned char port);
extern unsigned char lib_hdmi_audio_is_fifo_overflow(unsigned char port);
extern void lib_hdmi_audio_wclr_fifo_overflow(unsigned char port);
extern unsigned char lib_hdmi_audio_is_fifo_underflow(unsigned char port);
extern void lib_hdmi_audio_wclr_fifo_underflow(unsigned char port);
extern void lib_hdmi_audio_clear_phase_error(unsigned char port);
extern void lib_hdmi_audio_generate(unsigned char port);
extern unsigned char lib_hdmi_audio_is_output(unsigned char port);
extern void lib_hdmi_audio_output(unsigned char port, unsigned char on);
extern void lib_hdmi_audio_set_hbr_manual_mode(unsigned char nport, unsigned char manu, unsigned char mode_fw);
extern void lib_hdmi_audio_clear_hdr_status(unsigned char nport);
extern unsigned char lib_hdmi_audio_get_hbr_mode(unsigned char nport);
extern unsigned char lib_hdmi_audio_get_channel_status15_0(unsigned char nport, unsigned int bitmask, unsigned int bitshift);
extern unsigned char lib_hdmi_audio_get_channel_status39_16(unsigned char nport, unsigned int bitmask, unsigned int bitshift);







// -------------------------------------  hdmiPhy ----------------------------------------------//

extern void newbase_rxphy_isr_set(unsigned char port, unsigned char en);
extern void newbase_rxphy_init_struct(unsigned char port);
extern int newbase_rxphy_isr(void);


extern void newbase_rxphy_force_clear_clk_st(unsigned char port);
extern unsigned int newbase_rxphy_get_clk(unsigned char port);
extern unsigned char newbase_rxphy_is_clk_stable(unsigned char port);
extern unsigned char newbase_rxphy_get_setphy_done(unsigned char port);
extern void newbase_rxphy_reset_setphy_proc(unsigned char port);
extern void newbase_hdmi_dfe_recovery_6g_long_cable(unsigned char port);
extern void newbase_hdmi_dfe_recovery_midband_long_cable(unsigned char port);
extern void newbase_hdmi_dfe_recovery_mi_speed(unsigned char port);
extern void newbase_hdmi_set_phy(unsigned char port, unsigned int b);
extern unsigned char newbase_hdmi_dfe_record(unsigned char nport, unsigned int clk);
extern unsigned char newbase_hdmi_dfe_close(unsigned char nport, unsigned int clk, unsigned char phy_state);
extern void newbase_hdmi_dfe_hi_speed(unsigned char nport, unsigned int b_clk);
extern void newbase_hdmi_dfe_6g_long_cable_patch(unsigned char nport);
extern void newbase_hdmi_dfe_mi_speed(unsigned char nport, unsigned int b_clk);
extern void newbasse_hdmi_dfe_mid_adapthve(unsigned char nport, unsigned int b_clk);
#ifdef TMDS_ERR_DET_SHORT_PERIOD
extern void newbase_hdmi_open_err_detect(unsigned char port);
extern unsigned char newbase_hdmi_err_detect_stop(unsigned char port);
#endif

extern unsigned char newbase_hdmi_char_err_detection(unsigned char port);
extern unsigned char newbase_hdmi_bit_err_detection(unsigned char port);
extern unsigned char newbase_hdmi_is_long_cable(unsigned char port);
extern void newbase_hdmi_dump_dfe_para(unsigned char nport);



extern void lib_hdmi_trigger_measurement(unsigned char port);
extern void lib_hdmi_trigger_measure_start(unsigned char port);
extern void lib_hdmi_trigger_measure_stop(unsigned char port);
extern unsigned char lib_hdmi_is_clk_ready(unsigned char port);
extern unsigned int lib_hdmi_get_clock(unsigned char port);
#if CK_MD_AUTO
extern void lib_hdmi_ck_md_reset(unsigned char port);
extern void lib_hdmi_ck_md_set(unsigned char port);
extern void lib_hdmi_ck_md_auto(unsigned char port, unsigned char auto_mode);
#endif
extern void lib_hdmi_phy_init(void);
extern void lib_hdmi_z0_set(unsigned char port, unsigned char lane, unsigned char enable);
extern void lib_hdmi_mhl_z300_sel(unsigned char port, unsigned char is_mhl, unsigned char is_mhl3);
extern void lib_hdmi_ck_md_ref_sel(unsigned char port, unsigned char is_mhl3);

extern void lib_hdmi_mac_release(unsigned char nport);

extern void lib_hdmi_char_err_rst(unsigned char nport, unsigned char rst);


#define LN_CK 0x08
#define LN_B   0x04
#define LN_G   0x02
#define LN_R   0x01
#define LN_ALL (LN_CK|LN_B|LN_G|LN_R)










// -------------------------------------  hdmiMs ----------------------------------------------//

extern void set_no_polarity_inverse(unsigned char TorF);//allow vgip to set h v polarity inverse or not
extern unsigned char newbase_hdmims_measure_video(HDMI_TIMING_T *tm);


extern unsigned char lib_hdmims_measure(HDMI_TIMING_T *tm);
extern unsigned char lib_hdmims_get_hvstart(HDMI_TIMING_T *tm, unsigned char vsc_ch);








// -------------------------------------  mhl_detect ----------------------------------------------//
extern unsigned char newbase_mhl_cts_mode(void);
extern unsigned char newbase_mhl_detect_mode(unsigned char port);


extern void lib_mhl3_set_detectmode(unsigned char nport, unsigned char mhl3);


// -------------------------------------  mhl3 ----------------------------------------------//
extern void mhl3_disable_dphy(void);


// -------------------------------------  hdmi_ddc ----------------------------------------------//
extern void lib_hdmiddc_crt_on(void);
extern void lib_hdmiddc_sync_reset(unsigned char port);
extern unsigned char lib_hdmiddc_write(unsigned char port, unsigned char* EDID, unsigned int len);
extern unsigned char lib_hdmiddc_read(unsigned char port, unsigned char *edid_tbl, unsigned int len);
extern void lib_hdmiddc_enable(unsigned char port, unsigned char enable);
extern void lib_hdmiddc_set_sda_delay(unsigned char port, unsigned char delay_sel);
extern void lib_hdmiddc_set_write_debounce(unsigned char port, unsigned char debounce);
extern unsigned char lib_hdmiddc_mhl_write(unsigned char* EDID, unsigned int len);
extern void lib_hdmiddc_mhl_enable(unsigned char enable);
extern void lib_hdmiddc_sda2gpio(unsigned char port);
extern void lib_hdmiddc_gpio2sda(unsigned char port);
extern void lib_hdmiddc_sda_dir_out(unsigned char port, unsigned char dir_o);




#ifdef __cplusplus
}
#endif

#endif

