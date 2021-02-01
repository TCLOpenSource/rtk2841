#ifndef __SCALER_STATE_H__
#define __SCALER_STATE_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>

/*===================================  Types ================================*/
#if 0 // marked by hsliao 20090205
enum SYSTEMESSAGE {
	_SYSTEM_NO_MSG = 0,
	_SYSTEM_POWERSWITCH_MSG = 1,	// Power switch
	_SYSTEM_ENTER_DEBUG_MODE_MSG,	// Enter debug mode
	_SYSTEM_EXIT_DEBUG_MODE_MSG,	// Exit debug mode
	_SYSTEM_TEST_MSG,					// test message
	_SYSTEM_TEST_MSG1,				// test message1
#ifdef CONFIG_CUSTOMER_VERIFY
	_SYSTEM_CHECK_VIP_CHECK1,
	_SYSTEM_CHECK_VIP_CHECK2,
#endif
	_SYSTEM_UNKNOWN_MSG			// Unknown state
};
#endif

typedef enum _SLR_UI_MESSAGE{
	_FL2UI_TASK_READY, //frank@0513 when flow task wake up,flow send the msg to ui task
	_FL2UI_TASK_ACK_GO, //frank@0513 when flow task receive flow go msg,flow send the msg to ui task
	_FL2UI_AUTO_ADJUST_BEGIN, //frank@0513 when flow task receive flow  auto adjust start msg,flow send the msg to ui task
	_FL2UI_AUTO_ADJUST_END, //0x0130//frank@0513 when flow task receive flow auto adjust end msg,flow send the msg to ui task
	_FL2UI_AUTO_ADJUST_END_OK,
	_FL2UI_AUTO_ADJUST_END_FAIL,
	_UI2UI_FAKE_EVENT, // for ui to active itself
	_FL2UI_MAIN_NO_SIGNAL,			//0x0113
	_FL2UI_MAIN_NO_CABLE,			//0x0114
	_FL2UI_MAIN_NO_SUPPORT,		//0x0115
	_FL2UI_1S_TIMER_EVENT,		//0x0115
	_FL2UI_VCHIP_BLOCK,			// hsliao 20080908, when vchip block
	_FL2UI_VCHIP_UNBLOCK, 		// hsliao 20080908, when vchip unblock
	_FL2UI_RELOAD_CC_FONT,		// hsliao 20081015. When CC change to unmute, we need to reload CC font.
	_FL2UI_ENABLE_CC_OSD,			// hsliao 20081015. When CC change to unmute, we need to enable CC's OSD_V.

	_SIGNAL_MAIN_DETECT_OK_MESSAGE, //frank@0428 after color handler must store some color control parameter
	_SIGNAL_SUB_DETECT_OK_MESSAGE, //frank@0428 after color handler must store some color control parameter
	_MAIN_DISPLAY_MESSAGE,					//0x0104
	_SUB_DISPLAY_MESSAGE,					//0x0104
	_MAIN_DISPLAY_NOSIGNAL_MESSAGE,   //TLM
	_FL2UI_AUTO_AUTOCOLOR_END,
	_FL2UI_AUTO_AUTOCOLOR_FAIL,
	_FL2UI_AUTO_AUTOCOLOR_SUCCESS,
	_MAIN_SEARCH_MODE_MESSAGE,	//Gilbert ==> Mode Searching Message
	_FL2UI_MAGICPIC_OFF_MESSAGE, // signal is not stable we call ap to close magicpic
#if defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH) || defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH_DETECT_BY_PIN)
//#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
	_FL2UI_YPBPR_AV_SAME_PATH_CHANGE_SRC,
//#endif //#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
#endif //#if defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH) || defined(CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH_DETECT_BY_PIN)
	_FL2UI_FORCE_3D_DISABLE,
	_FL2UI_DISABLE_OSD,
        _FL2UI_AWB_MESSAGE,
#ifdef CONFIG_TTX_TOSHIBA_PATCH
	_FL2UI_TTX_SAVE_LIST, //save ListMode RGBY Pages Data
#endif //CONFIG_TTX_TOSHIBA_PATCH
#if (defined BUILD_TV013_1_ATV)||(defined BUILD_TV013_1_ISDB)
	_FL2UI_SLR_RATIO_16_9_SETED,
	_FL2UI_EG_PIC_REFRESH,  //jacklong2012/08/14
#endif
//#if defined(TV032_1)||defined (TV014_1)||(defined TV014_2)//Added by Kangwei 2012-07-18-11:5
//	_FL2UI_AWB_MESSAGE_START,
//#endif
#ifdef CONFIG_SOURCE_AUTO_SWITCH
	_FL2UI_SOURCE_AUTO_SWITCH_MESSAGE,
	//_FL2UI_SOURCE_AUTO_SWITCH_AV_MESSAGE,
	//_FL2UI_SOURCE_AUTO_SWITCH_YPBPR_MESSAGE,
	//_FL2UI_SOURCE_AUTO_SWITCH_HDMI1_MESSAGE,
	//_FL2UI_SOURCE_AUTO_SWITCH_HDMI2_MESSAGE,
#endif

	// EATON+
	_FL2UI_SCART_RATIO_16_9_DETECTED,
	_FL2UI_SCART_RATIO_4_3_DETECTED,

}SLR_UI_MESSAGE;


//oliver+2010/1/5
typedef struct _ATV_VERSION_CTRL
{
	unsigned int					ulVersion;		// your message.
	unsigned char					ucSrcType;			// type of message.
} ATV_VERSION_CTRL;
//oliver+2010/1/5
#define ATV_VER_CTRL_STRUCT_SIZE     5


#define SLR_TASK_SLEEP_INTERVAL_DEFAULT 	10//1000 // default scaler task sleep interval time: 500ms
#define SLR_TASK_SLEEP_INTERVAL_NORMAL 		10 // after UI is ready.use this setting
#define SLR_TASK_SLEEP_INTERVAL_NOSIGNAL 	100 // after signal is no sinal state.use this setting



/*================================== Variables ==============================*/

/*================================ Definitions ==============================*/

/*================================== Function ===============================*/

void flow_message_push(unsigned int message);
unsigned int flow_message_pop(void);
void flow_message_clearallType(unsigned int message);
void flow_message_clearall(void);
unsigned char flow_message_checkQueue(unsigned int message);
void Scaler_SendMessageToUI(SLR_UI_MESSAGE message);
void Scaler_ClearMessageFromUI(SLR_UI_MESSAGE message);
unsigned char scaler_AutoColorRunning(void);
void scaler_SetModeStateAutoColorRunning(unsigned char flag);
void scaler_SetModeStateGetAWBTargetDiffRunning(unsigned char flag);

//void fw_firmware_task(void);
void * fw_firmware_task(void * pParam);
unsigned char fw_firmware_createTask(void);
unsigned char fw_firmware_deinit_task(void);

//void state_initial_proc(void); // useless in LV
void fw_flow_message_init(void);
void fw_flow_message_deinit(void);

//void Scaler_SetDebugMode(unsigned char statue);
#ifdef BUILD_TV013_1
void Scaler_SetDebugMode(unsigned char statue);
#endif
void fw_flow_SetSleepInterval(unsigned int interval);
void state_update_disp_info(void);
void state_update_disp3d_info(void);

unsigned char fw_flow_GetATVDispReadyFlag(void);
void fw_flow_SetATVDispReadyFlag(unsigned char a_bFlag);

//unsigned int fw_flow_GetUnhandleMsgFlag();

unsigned char fw_flow_GetAPDispReadyFlag(void);
void fw_flow_SetAPDispReadyFlag(unsigned char a_bFlag);
unsigned char fw_flow_GetCUSTOMModeflowFlag(void);
void fw_flow_SetCUSTOMModeflowFlag(unsigned char a_bFlag);
StructRect fw_flow_GetCUSTOMModeDisplayWindow(void);
void fw_flow_SetCUSTOMModeDisplayWindow(StructRect m_dispwin);

unsigned char fw_flow_Get3DModeReadyFlag(void);
void fw_flow_Set3DModeReadyFlag(unsigned char flag);

#if (defined TV003_ADTV)
void scaler_RegisterAudoEffectCallbackFunc(void (*fp)(void));
#endif

#ifdef __cplusplus
}
#endif

#endif // __SCALER_STATE_H__


