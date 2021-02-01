#ifndef __MODE_STATE_H__
#define __MODE_STATE_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <scalercommon/scalerCommon.h>
//#include <VideoRPC_System.h>


//#include <rtd_types.h>
// oliver-, move to scalerCommon.h
/*
enum _MODE_STATE
{
	_MODE_STATE_NONE = 0,						// none state
	_MODE_STATE_SEARCH,						// detect mode
	_MODE_STATE_ACTIVE,						// ative mode to show
	_MODE_STATE_FREEZE,						// freeze
	_MODE_STATE_TV_SCAN,						// tv scan channel
	_MODE_STATE_SHOWSNOW,					// Show snow in TV
};
*/

// enum _MODE_RESULT
// {
// 	_MODE_NOSIGNAL	= 0xFF,
// 	_MODE_NOSUPPORT	= 0xFE,
// 	_MODE_NOCABLE		= 0xFD,
// 	_MODE_SUCCESS		= 0xFC,
// 	_MODE_DETECT		= 0xFB,
// 	_MDOE_UNDKOWN	= 0xFA,
// };

extern unsigned char	ModeStateAutoColorRunning;
extern unsigned char	ModeStateGetAWBTargetDiffRunning;
extern int ModeStateAutoColorYpbprAdj;
extern int ModeStateAutoColorADCBalance;
#ifdef BUILD_TV005_1_ATV_PATCH_LIB_FROM_MP_BRANCH_SVN_434497_437131
extern UINT8 SelfAWB_VGA_is_done;
extern UINT8 SelfAWB_YPP_is_done;
#endif

typedef enum _MODE_MESSAGE {
	_UI2FL_MAIN_INIT_SRC_EVENT=1,									// 0x01:for source change state
	// don't change _FL2FL_MAIN_STATE_PERIODIC_EVENT positon, it must be  _UI2FL_MAIN_INIT_SRC_EVENT + 1
	// because we use  _UI2FL_MAIN_INIT_SRC_EVENT + 1 in fw_modestate_process()
	_FL2FL_MAIN_STATE_PERIODIC_EVENT,							//  for search state
	_MODE_MSG_MAIN_SET_VGIP_AFTER_FOUND_MODE_SIGNAL,
	_FL2FL_MAIN_SET_FRAMESYNC_SIGNAL,
	_FL2FL_MAIN_SET_DISPLAY_ON,
	_MODE_MSG_MAIN_UNKNOWN,

	_UI2FL_SUB_INIT_SRC_EVENT,					//  for source change state
	// don't change _FL2FL_SUB_STATE_PERIODIC_EVENT positon, it must be  _UI2FL_MAIN_INIT_SRC_EVENT + 1
	// because we use  _UI2FL_SUB_INIT_SRC_EVENT + 1 in fw_modestate_process()
	_FL2FL_SUB_STATE_PERIODIC_EVENT,							//  for search state
	_MODE_MSG_SUB_SET_VGIP_AFTER_FOUND_MODE_SIGNAL,
	_MODE_MSG_SUB_SETUP_AFTER_FOUND_MODE_SIGNAL,
	_MODE_MSG_SUB_SETUP_BEFORE_SHOW_SIGNAL,
	_FL2FL_SUB_SET_DISPLAY_ON,
	_MODE_MSG_SUB_UNKNOWN,

	_UI2FL_MAIN_DISPLAYRATIO_CHANGE,					// 0x1d change pip type
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	_UI2FL_PIP_TYPE_CHANGE_EVENT,								// 0x1e change pip type
#endif
	_UI2FL_SWAP_SOURCE_EVENT,									// 0x1f
	_UI2FL_TV_AUTOSCAN_START,
	_UI2FL_TV_AUTOSCAN_CANCEL,
	_UI2FL_TV_MENUALSCAN_START,
	_UI2FL_TV_MENUALSCAN_CANCEL,
	_UI2FL_FLOW_GO,
	_UI2FL_ADC_AUTOADJUST_START,
	_UI2FL_ADC_AUTOCOLOR_START,
	_UI2FL_CLOSE_SOURCE_MEM_IP,
	_MODE_MSG_TV_BROWSE_EVENT,								// 0x20
	_MODE_MSG_ENABLE_BLOCKING,								// 0x21
	_MODE_MSG_DISABLE_BLOCKING,
#ifdef CONFIG_SCALER_HDMI_CEC_ENABLE
	_UI2FL_CEC_DEVICELISTUPDATE_START,
#endif

	_UI2FL_3D_FORCE_2D_MODE_EVENT,                                                //0x1c
	_UI2FL_3D_INPUT_AUTO_FROM_INFO_FRAME_FLAG_CHANGE,
	_UI2FL_3D_INPUT_SIDE_BY_SIDE_HALF_FLAG_CHANGE,
	_UI2FL_3D_INPUT_FRAME_PACKING_FLAG_CHANGE,
	_UI2FL_3D_INPUT_TOP_AND_BOTTOM_FLAG_CHANGE,
	// --- new 3D format ---
	_UI2FL_3D_INPUT_LINE_BY_LINE_FLAG_CHANGE,
	_UI2FL_3D_INPUT_VERTICAL_STRIPE_FLAG_CHANGE,
	_UI2FL_3D_INPUT_CHECKER_BOARD_FLAG_CHANGE,
	_UI2FL_3D_INPUT_REALID_FLAG_CHANGE,
	_UI2FL_3D_INPUT_SENSIO_FLAG_CHANGE,
	_UI2FL_3D_INPUT_2D_CVT_3D,
	// -------------------
	_UI2FL_3D_INPUT_AUTO_FROM_INFO_FRAME_CVT_2D,
	_UI2FL_3D_INPUT_SIDE_BY_SIDE_HALF_CVT_2D,
	_UI2FL_3D_INPUT_FRAME_PACKING_CVT_2D,
	_UI2FL_3D_INPUT_TOP_AND_BOTTOM_CVT_2D,
	// --- new 3D format ---
	_UI2FL_3D_INPUT_LINE_BY_LINE_CVT_2D,
	_UI2FL_3D_INPUT_VERTICAL_STRIPE_CVT_2D,
	_UI2FL_3D_INPUT_CHECKER_BOARD_CVT_2D,
	_UI2FL_3D_INPUT_REALID_CVT_2D,
	_UI2FL_3D_INPUT_SENSIO_CVT_2D,
	// -------------------
	_UI2FL_3D_FORCE_LR_CHANGE,
	_UI2FL_3D_FORCE_LR_CHANGE_CVT_2D,
	_UI2FL_ADC_SELFAWB_START,//leochen
	_UI2FL_ADC_SELFAWB_GET_TARGET_DIFF,//leochen
#if defined(IS_MACARTHUR3)
	_UI2FL_MAIN_DISPLAY_CAPTURE_CHANGE, //randy
#endif

#if 0 // forGumpDemo
	_UI2FL_3D_FOR_GUMP_DEMO,
#endif

}MODE_MESSAGE;

typedef enum _MODESTATE_TABLE_TYPE{
	MODESTATE_TABLE_VGA_MODE,
	MODESTATE_TABLE_VGA_OFFSET,
	MODESTATE_TABLE_YPBPR_OFFSET,
	MODESTATE_TABLE_SCREEN_MODE_INFO,
//	MODESTATE_TABLE_SRC_PROC,
	MODESTATE_TABLE_SRC_INFO,
	MODESTATE_TABLE_AUTO_SRC_INFO,
//	MODESTATE_TABLE_COLOR_DATA, // marked by hsliao 20090316
       MODESTATE_VGA_DOS_TIMING,
       MODESTATE_AP_CHANGE_SOURCE,
} MODESTATE_TABLE_TYPE;

#if 0
/**
 * This API is used to init some variables  input signal
 *
 * @param [input] :
 * @param [output] :
 * @return _MODE_RESULT_NOSIGNAL,_MODE_RESULT_NOSUPPORT,_MODE_RESULT_NOCABLE...
 *
 */
void fw_modestate_init(void);
#endif

/**
 * This API is used to process mode state message
 *
 * @param [input] :  <msg>		{ Accept message from message queues }
 * @param [output] :
 * @return None
 *
 */
void fw_modestate_process(unsigned int msg);

/**
 * This API will check is the display is on the avtive state.
 *
 * @param [input] :  <display>		{ The display you want to query }
 * @param [output] :
 * @return false: if display on search state or none state
 *             true: if display not on search state or none state
 *
 */
unsigned char fw_modestate_check_display_status(unsigned char display);
unsigned char modestate_I3DDMA_check_idma_mode_enable(unsigned char cur3dType);
int modestate_get_first_voIndex(void);

unsigned char modestate_decide_double_dvs_enable(void);
unsigned char modestate_set_hdi_window_proc(void);
unsigned char modestate_set_zoom_proc(float hratio, float vratio);

#ifdef CONFIG_DUAL_CHANNEL
/**
 * fwif_modestate_set_sub_window
 * This API is used to set the size and position in display window for sub-display
 *
 * @param void
 * @return void
 *
 */
void fwif_modestate_set_sub_window(void);
#endif

unsigned char modestate_regTable(MODESTATE_TABLE_TYPE index, void *ptr);

/**
\brief Check if latest display ready
\param a_ulVersion[In], display version number
\return None
\bug None
\see None
*/
unsigned char fw_modestate_IsATVLatestDisplayReady(UINT32 a_ulVersion);
//unsigned char fw_modestate_IsVOLatestDisplayReady(UINT32 a_ulVersion);
void modestate_set_hflip(void);

//oliver+
unsigned int fw_modestate_GetAtvVersion(void);

unsigned char GET_ZOOM_MODE(void);
unsigned char modestate_decide_double_dvs_enable(void);


// [2D3D] 2D convert 3D mode change speed up control
typedef enum _SLR_2DCVT3D_MODE_CHANGE_STATE{
	_2DCVT3D_STATE_NONE 		= 0,
	_2DCVT3D_STATE_ENABLE 	= 1,
	_2DCVT3D_STATE_DISABLE 	= 2,
}SLR_2DCVT3D_MODE_CHANGE_STATE;


// [IDMA] IDMA mode change speed up control
typedef enum _SLR_IDMA_MODE_CHANGE_STATE{
	IDMA_STATE_NONE 		= 0,
	IDMA_STATE_ENABLE 	= 1,
	IDMA_STATE_DISABLE 	= 2,
}SLR_IDMA_MODE_CHANGE_STATE;


#define SLR_VGIP_HS_INV_START_BIT	2
#define SLR_VGIP_HS_VS_INV_MASK	(0x3 << SLR_VGIP_HS_INV_START_BIT)

// [FIX-ME] Reduce bandwidth by disable RTNR for MacArthur
#define REDUCE_NR_BANDWIDTH_LIMIT_HOR_THRESHOLD 	1440

//frank@0309 change width limit to solve mantis#40114 from 1440 to 960
#define REDUCE_DI_BANDWIDTH_LIMIT_THRESHOLD 	960//1440
#define REDUCE_DI_MEMORY_LIMIT_THRESHOLD 		720

#define VODMACLK_REDUCE_PANEL_LENGTH_THRESHOLD 		800 //for 1366X768 panel

#define REDUCE_DI_BW_VFREQ_THRESHOLD			900 // 90Hz

void modestate_set_Stop_Peak_Flag(UINT8 ucFalg);//leochen
void modestate_set_SelfAWB_Flag(UINT8 ucFalg); //leochen
UINT8 modestate_get_SelfAWB_Flag(void);//planck
UINT8 modestate_get_current_autoAdjust_count(void); // [vga adjust] linmc@20120625, resolve auto adjust osd display repeatly when the current input is not the full screen (pc power on timing)
void modestate_set_manualReduceDIBW(void* callbackfunc); // [XF112HAICNRTK1-88] linmc@20120712, reduce di bandwidth to resolve flicker picture screen happened
void modeste_reset_3D_mode(void);//init 3Dmode

void modestate_I3DDMA_enable(unsigned char mode);
void modestate_I3DDMA_set_IsCaptureReady(unsigned char mode);
unsigned char modestate_I3DDMA_get_IsCaptureReady(void);
unsigned char modestate_I3DDMA_get_In3dMode(void);
unsigned char modestate_I3DDMA_get_2dSrcType(void);
unsigned char modestate_get_vo3d_in_framePacking_FRC_mode(void);
unsigned char modestate_get_pr3d_in_fp_3d_mode(void);
SLR_IDMA_MODE_CHANGE_STATE modestate_I3DDMA_get_idma_modeChange_status(void);
int modestate_get_first_srcType_Index(unsigned char type);
VO_3D_MODE_TYPE modestate_get_vo3d_detect_result(void);

void modestate_release_src_for_MaincvtSub(void);
int modestate_get_first_voIndex(void);

void modestate_fine_tune_src_tv_at_framesync_mode(void);
void modestate_release_subsrc_for_MaintSubOnPR(void);
void Change_sub_ShowOn_PRPanel(unsigned char subindex);
UINT8 hdmi_FT_get_tvbox_test_mode(void);
void modestate_set_hdmi_FT_by_detect_gpio(void);


#ifdef __cplusplus
}
#endif

#endif // __MODE_STATE_H__


