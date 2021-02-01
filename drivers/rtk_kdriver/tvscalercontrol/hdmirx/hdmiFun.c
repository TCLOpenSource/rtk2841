/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmiFun.c
 *
 * author: 	The Hulk, David Banner
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"




/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/
#ifndef _ENABLE
#define _ENABLE			1
#endif

#ifndef _DISABLE
#define _DISABLE			0
#endif



/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/





/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/

#ifdef CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
bool isHdr10CheckedChanged=FALSE;
#endif

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
bool isDlobyCheckedChanged=FALSE;
//timeval myTimeFoundCRC;
#endif




/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/





/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/


HDMI_COLOR_SPACE_T drvif_Hdmi_GetColorSpace(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return (HDMI_COLOR_SPACE_T)newbase_hdmi_get_colorspace(port);
}

HDMI_COLORIMETRY_T drvif_Hdmi_GetColorimetry(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return (HDMI_COLORIMETRY_T)newbase_hdmi_get_colorimetry(port);
}

HDMI_COLOR_DEPTH_T drvif_Hdmi_GetColorDepth(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return (HDMI_COLOR_DEPTH_T)newbase_hdmi_get_colordepth(port);
}

unsigned char drvif_Hdmi_HdcpEnabled(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return (newbase_hdcp_get_auth_mode(port) != 0);

}

HDMI_bool drvif_Hdmi_GetInterlace(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_is_interlace(port);
}

HDMI_DVI_MODE_T drvif_IsHDMI(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return (HDMI_DVI_MODE_T)newbase_hdmi_get_hdmi_mode(port);
}

HDMI_RGB_YUV_RANGE_MODE_T drvif_IsRGB_YUV_RANGE(void)
{
//return
//	MODE_RAG_DEFAULT = 0x0
//	MODE_RAG_LIMIT = 1
//	MODE_RAG_FULL = 2

	unsigned char port = newbase_hdmi_get_current_display_port();
	return (HDMI_RGB_YUV_RANGE_MODE_T)newbase_hdmi_get_color_range(port);
}

HDMI_3D_T drvif_HDMI_GetReal3DFomat(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return (HDMI_3D_T)newbase_hdmi_get_3d_structure(port);
}

char drvif_Hdmi_IsAudioLock(void)
{
	return (newbase_hdmi_audio_get_current_status() != AUDIO_FSM_AUDIO_START);
}



unsigned char drvif_Hdmi_CheckStable_BeforeDisplay(void)
{
	return newbase_hdmi_check_stable_before_display();
}

unsigned char drvif_Hdmi_WatchDog_Apply(unsigned char Enable, unsigned char Condition)
{
	return newbase_hdmi_watchdog_apply(Enable, Condition);
}


HDMI_bool drvif_hdmi_is_drm_info_ready(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	HDMI_DRM_T drm_info;

	if ( newbase_hdmi_get_drm_infoframe(port, &drm_info)) {
		if (drm_info.len == 0 && drm_info.ver == 0) {
			return FALSE;
		}

		if (drm_info.eEOTFtype == 0) {
			return FALSE; // no EOTF
		}
	#ifndef CONFIG_CUSTOMER_TV030 //TCL PS4 HDR  does not have  display_primaries_x0/display_primaries_x1/display_primaries_x2
		if (drm_info.display_primaries_x0==0 &&
			drm_info.display_primaries_x1==0 && drm_info.display_primaries_x2==0) {
			return FALSE;
		}
	#endif
	} else {
		return FALSE;
	}

	return TRUE;
}




unsigned char drvif_Hdmi_GetConsumerUse(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status15_0(port, _BIT0, 0);
}

unsigned char drvif_Hdmi_GetAudioSampleWord(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status15_0(port, _BIT1, 1);
}

unsigned char drvif_Hdmi_GetCopyright(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status15_0(port, _BIT2, 2);
}

unsigned char drvif_Hdmi_GetFormatInfo(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status15_0(port, _BIT5|_BIT4|_BIT3, 3);
}

unsigned char drvif_Hdmi_GetChannelStatusMode(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status15_0(port, _BIT7|_BIT6, 6);
}

unsigned char drvif_Hdmi_GetCategoryCode(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status15_0(port, 0xFF00, 8);
}

unsigned char drvif_Hdmi_GetSourceNumber(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status39_16(port, _BIT3|_BIT2|_BIT1|_BIT0, 0);
}

unsigned char drvif_Hdmi_GetChannelNumber(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status39_16(port, _BIT7|_BIT6|_BIT5|_BIT4, 4);
}

unsigned char drvif_Hdmi_GetSamplingFrequency(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status39_16(port, _BIT11|_BIT10|_BIT9|_BIT8, 8);
}

unsigned char drvif_Hdmi_GetClockAccuracy(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status39_16(port, _BIT13|_BIT12, 12);
}

unsigned char drvif_Hdmi_GetWordLength(void) // return 16~24
{
	const unsigned char word_len[2][8]={{0, 16, 18, 0, 19, 20, 17}, {0, 20, 22, 0, 23, 24, 21}};
	unsigned char port = newbase_hdmi_get_current_display_port();
	unsigned char chstatus = lib_hdmi_audio_get_channel_status39_16(port, _BIT19|_BIT18|_BIT17|_BIT16, 16);

	return word_len[(chstatus & 0x01)][chstatus>>1];
}

unsigned char drvif_Hdmi_GetOriginalFrequency(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return lib_hdmi_audio_get_channel_status39_16(port, _BIT23|_BIT22|_BIT21|_BIT20, 20);
}


/**
 * Get Vendor Specific Infoframe
 * Please refer to CEA-861
 */
unsigned char drvif_Hdmi_GetVsInfoFrame(HDMI_VSI_T *pVsInfo) //pVsInfo size = 28+3 bytes, the length is reffered to LG implement guide
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_vs_infoframe(port, pVsInfo);
}

/**
 * Get AVI Infoframe
 * Please refer to CEA-861
 */
unsigned char drvif_Hdmi_GetAviInfoFrame(HDMI_AVI_T *pAviInfo) //pAviInfo size = 16 bytes
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_avi_infoframe(port, pAviInfo);
}

/**
 * Get SPD Infoframe
 * Please refer to CEA-861
 */
unsigned char drvif_Hdmi_GetSpdInfoFrame(HDMI_SPD_T *pSpdInfo) //pSpdInfo size = 28 bytes
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_spd_infoframe(port, pSpdInfo);
}

/**
 * Get Audio Infoframe
 * Please refer to CEA-861
 */
unsigned char drvif_Hdmi_GetAudioInfoFrame(HDMI_AUDIO_T *pAudioInfo) //pAudioInfo size = 13 bytes
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_audio_infoframe(port, pAudioInfo);
}

/**
 * Get DRM Infoframe
 * Please refer to CEA-861
 */
unsigned char drvif_Hdmi_GetDrmInfoFrame(HDMI_DRM_T *pDrmInfo) //pSpdInfo size = 29 bytes
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_drm_infoframe(port, pDrmInfo);
}



unsigned char drvif_hdmi_is_current_port_mhl(void)
{
#if MHL_SUPPORT
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_is_mhl(port);
#else
	return 0;
#endif
}

unsigned char drvif_hdmi_is_current_port_mhl3(void)
{
#if MHL_SUPPORT
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_get_is_mhl3(port);
#else
	return 0;
#endif
}




void drvif_hdmi_save_pcbinfo(unsigned char port, const HDMI_CHANNEL_T_PCB_INFO *pcb)
{
	newbase_hdmi_save_pcbinfo(port, pcb);
}

void drvif_hdmi_save_mhl_edid(const unsigned char *edid, const unsigned int len)
{
	newbase_hdmi_save_mhl_edid(edid, len);
}

void drvif_hdmi_save_hdcp(const HDCP_KEY_T *key)
{
	newbase_hdmi_save_hdcp(key);
}

unsigned char drvif_hdmi_check_mode(void)
{
	return newbase_hdmi_check_mode();
}



void drvif_hdmi_set_no_polarity_inverse(unsigned char TF)
{
	set_no_polarity_inverse(TF);
}


unsigned char drvif_hdmi_get_customer_hdcp1p4(void)
{
	return newbase_hdmi_get_customer_hdcp1p4();
}



/*==================== TVServer Used ===================*/
#if defined(PROJECT_TVSERVER)

unsigned char drvif_hdmi_is_drm_info_eEOTFtype(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	HDMI_DRM_T drm_info;

	if ( newbase_hdmi_get_drm_infoframe(port, &drm_info)) {
		if (drm_info.len == 0 && drm_info.ver == 0)
			return FALSE;
		else
			return drm_info.eEOTFtype;
	}
	else
		return FALSE;
}


#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
unsigned char newbase_hdmi_dv_hdr_md_info_check(void)
{
	if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() != SLR_DV_HDMI_DETECT_OFF){ // check HDMI CRC result when DolbyVision check enabled
		unsigned char bChanged=0;
		unsigned char result = Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result();
		unsigned char port = newbase_hdmi_get_current_display_port();
		//printf("[Benson](2)[%s][%d] result= %d \n", __FUNCTION__, __LINE__, result);

		if(result && (Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_ON))
		{
			if(lib_hdmi_get_avmute(port) != 0)
			{
				return TRUE;
			}
			else
			{
				lib_hdmi_auto_avmute_enable(port, 0);
				msleep(10);
				lib_hdmi_auto_avmute_enable(port, 1);

				lib_hdmi_video_output(port, 1);
			}

			HDMI_PRINTF("[%s][%d] set SLR_DV_HDMI_DETECT_FOUND_CRC \n", __FUNCTION__, __LINE__);
			Scaler_HDR_DolbyVision_Hdmi_Set_Detect_Status(SLR_DV_HDMI_DETECT_FOUND_CRC);
			bChanged = TRUE;
			isDlobyCheckedChanged = TRUE;
			Scaler_ForceBg((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_FORCE_BG_SYSTEM, TRUE);
		}

		if(bChanged){
			HDMI_PRINTF("[DolbyVision] check=%d\n", result);
			return FALSE;
		}
	}

	return TRUE;
}

#endif




// RemoteAPI/TvDisplaySetupApi.cpp used
HDMI_bool  drvif_Cbus_SEND_RCP_SUB_Command(MHL_RCP_CMD_T bRCPCode)
{
#if MHL_SUPPORT
	if (GET_ISMHL()&&(newbase_hdmi_get_current_display_port() ==MHL_CHANNEL))
	{
		return  (HDMI_bool)Cbus_SEND_RCP_SUB_Command(bRCPCode);
	}
	else
	{
		return  MHL_RCP_NOT_MHL ;  //fail ,  not MHL channel
	}
#endif
}

// RemoteAPI/TvDisplaySetupApi.cpp used
HDMI_bool  drvif_CurrentIsMHL(void)
{
#if MHL_SUPPORT
	if (GET_ISMHL()&&(newbase_hdmi_get_current_display_port() ==MHL_CHANNEL))
		return true;
	else
		return false;
#endif
}


void drvif_hdmi_save_pcbinfo(unsigned char port, const HDMI_CHANNEL_T_PCB_INFO *pcb)
{
	newbase_hdmi_save_pcbinfo(port, pcb);
}


// RemoteAPI/EngineerFactoryApi.cpp used
char get_drvif_HDMI_Force3DTo2D(bool ismode)
{
	// not implemented
    return 0;
}

// RemoteAPI/EngineerFactoryApi.cpp used
char get_drvif_HDMI_Force2DToFake3D(bool ismode)
{
	// not implemented
    return 0;
}

// RemoteAPI/EngineerFactoryApi.cpp used
char drvif_Hdmi_3DDMA_Progressive_freeze(char  enable)
{
	// not implemented
	return TRUE;
}

// RemoteAPI/EngineerFactoryApi.cpp used
char drvif_HDMI_3D_FeatureEnable(char enable) {
	// not implement
	return FALSE;
}

// RemoteAPI/EngineerFactoryApi.cpp used
char drvif_HDMI_Force3DTo2D(char enable, char LR) {
	// not implement
	return FALSE;

}

// RemoteAPI/EngineerFactoryApi.cpp used
char drvif_HDMI_Force2DToFake3D(char enable, HDMI_3D_T mode) {
	// not implement
	return FALSE;

}

// RemoteAPI/EngineerFactoryApi.cpp used
char drvif_HDMI_ColorBar(char enable) {
	// not implement
	return TRUE;
}

// scalerLib.cpp used
HDMI_bool drvif_Hdmi_regTable(HDMI_TABLE_TYPE index, void *ptr)
{

	if ( !ptr )
		return FALSE;

	HDMI_PRINTF("drvif_Hdmi_regTable %d %x\n", index, (unsigned int) ptr);
	switch ( index )
	{

		case HDMI_HDCP_KEY_TABLE:
		    newbase_hdmi_save_hdcp((HDCP_KEY_T*) ptr);
			break;

		case HDMI_CHANNEL0:

			break;
		case HDMI_CHANNEL1:

			break;
		case HDMI_CHANNEL2:

			break;

		case HDMI_CHANNEL3:

			break;
		#if MHL_SUPPORT
             case CBUS_TABLE:   //cloud add for magellan CBUS table
		     //cbus = (CBUS_CHANNEL_T*) ptr;

		      break;
	      #endif

		default:

			return FALSE;
	}
	return TRUE;
}

// scalerDrv.cpp used  (for cut 4 line)
int drvif_HDMI_GetScreenMode(void)
{
	return HDMI_OSD_MODE_AUTO;

}

// scalerDrv.cpp used (for cut 4 line)
HDMI_bool drvif_HDMI_IsVideoTiming(void)
{
    /* MOD_BY_QIAO 20120620: TPV Remove 640*480@60 Form Video Timing */
	if (Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) ==_SRC_HDMI &&
       (((Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR)>=_MODE_480I)&&(Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR)<=_MODE_VIDEO_TIMING_END)) ||
        ((Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR)>=_MODE_720x480_60HZ)&&(Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR)<=_MODE_640x480_75HZ) &&
         (Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR)!=_MODE_640x480_60HZ))))
		return TRUE;
	else
		return FALSE;
    /* MOD_END */
}

// modestate.cpp used
unsigned char drvif_HDMI_CheckConditionChange(void)
{
	unsigned char nport = newbase_hdmi_get_current_display_port();
	if(FALSE == newbase_hdmi_check_condition_change(nport))
		return _FALSE;

	return _TRUE;
}

// sig_hdmi.cpp used
char drvif_Hdmi_Is_3DDMA_Enable(void) {
	/*
	if (hdmi.path_policy == HDMI_PATH_POLICY_3D_NODMA || hdmi.path_policy == HDMI_PATH_POLICY_2D_ONLY) return FALSE;
	if (hdmi.gen_timing.hdmi_3dformat < HDMI3D_2D_ONLY) return TRUE;
	*/
	return FALSE;
}

// hdmiFun.c (InProcHDMI_Setup) used
void drvif_Hdmi_Audio_Check()
{
	unsigned char port = newbase_hdmi_get_current_display_port();

	if(lib_hdmi_is_hdmi_mode(port) == MODE_HDMI) {
		if (newbase_hdmi_audio_get_current_status() != AUDIO_FSM_AUDIO_CHECK) {//done AUDIO_FSM_AUDIO_START_OUT
			if (newbase_hdmi_audio_get_current_status() == AUDIO_FSM_AUDIO_START){
				//HDMI_LOG("Do Hdmi Audio Tracking again 01\n");
				newbase_hdmi_audio_detect();//AUDIO_FSM_FREQ_DETECT
				newbase_hdmi_audio_detect();//AUDIO_FSM_AUDIO_START_OUT
			} else if ((newbase_hdmi_audio_get_current_status() == AUDIO_FSM_AUDIO_WAIT_PLL_READY)||(newbase_hdmi_audio_get_current_status() == AUDIO_FSM_AUDIO_START_OUT)) {//done AUDIO_FSM_FREQ_DETECT
				//HDMI_LOG("Do Hdmi Audio Tracking again 02\n");
				newbase_hdmi_audio_detect();//AUDIO_FSM_AUDIO_START_OUT
			}
		}
	}
}

// sig_hdmi.cpp used
HDMI_bool InProcHDMI_Setup(void)
{
	//HDMI_LOG("%s \n", "InProcHDMI_Setup");
	//if (hdmi_in(HDMI_HDMI_SR_VADDR) & _BIT6) { // AVMute Set
	//	return FALSE;
	//}
	unsigned char nport = newbase_hdmi_get_current_display_port();

	//drvif_mode_enableonlinemeasure();

	//20110930 kist add
	if(lib_hdmi_is_hdmi_mode(nport) == MODE_HDMI) {
		newbase_hdmi_audio_detect();
		drvif_Hdmi_Audio_Check();
		//hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~(_BIT7),(_BIT7));		// Enable AVMute  	WDG
		//Hdmi_AudioModeDetect();//for AUDIO_FSM_AUDIO_WAIT_PLL_READY if normally
		//Hdmi_AudioModeDetect();//for AUDIO_FSM_AUDIO_START_OUT if normally
	}
	return TRUE;
}

void drvif_Hdmi_Init(void){

	unsigned char i =0;

	lib_hdmi_reg_init(); //to prevent load HDCP reg NG

	newbase_hdmi_init();

	newbase_hdmi_hdr10_enable(_ENABLE);

	for(i = 0; i < HDMI_RX_PORT_MAX_NUM; i++) {
		newbase_hdmi_init_source(i);
	}

}

void drvif_Hdmi_UnInit(void){
       newbase_hdmi_uninit();
}


void drvif_Hdmi_InitSrc(unsigned char channel){

	newbase_hdmi_set_current_display_port(channel);

}

HDMI_bool drvif_Hdmi_DetectMode(void){
	unsigned char port = newbase_hdmi_get_current_display_port();
	return newbase_hdmi_detect_mode(port);
}

HDMI_bool drvif_Hdmi_CheckMode(void){
	return newbase_hdmi_check_mode();
}

void drvif_Hdmi_Release(void){
	unsigned char port = newbase_hdmi_get_current_display_port();
	newbase_hdmi_disconnect_source(port);

}


HDMI_bool DV_drvif_Hdmi_CheckMode(void)
{
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if(isDlobyCheckedChanged){  //someone else called drvif_Hdmi_CheckMode() and returned false before, DV's should return false, too
		HDMI_PRINTF("[DolbyVision][HDMI][%s][%d] Forece return FALSE !\n", __FUNCTION__, __LINE__);
		isDlobyCheckedChanged = FALSE;
		return FALSE;
	}
	isDlobyCheckedChanged = FALSE;
#endif

#ifdef CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
	if(isHdr10CheckedChanged){  //someone else called drvif_Hdmi_CheckMode() and returned false before, DV's should return false, too
		HDMI_PRINTF("[HDR10][HDMI][%s][%d] Forece return FALSE !\n", __FUNCTION__, __LINE__);
		isHdr10CheckedChanged = FALSE;
		return FALSE;
	}
	isHdr10CheckedChanged = FALSE;
#endif

	return drvif_Hdmi_CheckMode();
}

void drvif_Hdmi_set_scaler_info(void)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	newbase_hdmi_set_info(port);
}

#endif
/*=================================================*/
