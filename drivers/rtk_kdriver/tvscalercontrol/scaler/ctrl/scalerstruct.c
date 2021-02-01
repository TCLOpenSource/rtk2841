/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * The file is a declaration and definition header file
 *
 * @author 	$Author:  $
 * @date 	$Date:  $
 * @version 	$Revision:  $
 * @ingroup
 */

 /**
 * @addtogroup
 * @{
 */
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>


//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>

//#include <rtd_types.h>
//#include <Platform_Lib/Board/pcbSource.h>
//#include <tvscalercontrol/scaler/scalerType.h>

#include <tvscalercontrol/scaler/scalerstruct.h>
//#include <kernel/scaler/scalerDrv.h>	// kernel space scalerDrv
//#include <kernel/scaler/scalerVideo.h> // kernel space scalerVideo
#include <tvscalercontrol/scalerdrv/scalerdrv.h>	// user space scalerDrv
#include <tvscalercontrol/scalerdrv/scalerip.h>
#include <tvscalercontrol/scaler/source.h>
//#include <tvscalercontrol/scaler/modeState.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
//#include <kernel/scaler/scalerIRQ.h>	// for interrupt testing
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>

#include "tvscalercontrol/i3ddma/i3ddma.h"
#include "tvscalercontrol/i3ddma/i3ddma_drv.h"

#include <scalercommon/scalerDrvCommon.h>
//#include <tvscalercontrol/scaler/scalerLib.h>
//#include "tvscalercontrol/scaler/state.h"
#include "tvscalercontrol/vdc/video.h"

#include "tvscalercontrol/io/ioregdrv.h"
//#include <Application/AppClass/SetupClass.h>


// information of mode
static ModeInformationType stModeInfo;
static ModeInformationType stHdmiModeInfo;

// information of input source
static StructSourceInput *	src_info = NULL;
static StructSourceInput *		auto_av_sv_src_info = NULL;
static unsigned char				slrSourceMax = 0;
//static unsigned char					slrSourceInit = FALSE;

// information of display channel
StructDisplayInfo 			disp_info[MAX_DISP_CHANNEL_NUM];
StructDisplayInfo* 			info = NULL;	// Erin 100310
static unsigned char		custom_osd4k2k = 0;
static StructSrcRect		custom_dispwin = {0, 0, 0, 0};
static unsigned char		bNewInputRegionFlag[MAX_DISP_CHANNEL_NUM];
static StructSrcRect		adaptivestream_inputwin = {0, 0, 0, 0};
static unsigned char 				InputSource[MAX_DISP_CHANNEL_NUM];
static unsigned int 			VoVersion = 0;
//static unsigned int 			mvRdyVersion;
static unsigned int 			g_ulVoRdyVersion;
static StructSrcRect		custom_source_dispwin = {0, 0, 0, 0};
static unsigned char		output_2k1k_timing = 1;


//StructDisplay3DInfo		disp3d_info;
StructDisplay3DInfo		disp3d_info[MAX_DISP_CHANNEL_NUM];
//DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr;	// debug scaler flag tracker

DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr=
{
	//vsc
	FALSE,	//	unsigned char VSC_Device_Init_Done;
	0,	//	unsigned short main_inputregion_x_pre;
	0,	//	unsigned short main_inputregion_w_pre;
	0,	//	unsigned short main_inputregion_x_ori_pre;
	0,	//	unsigned short main_inputregion_w_ori_pre;
	0,	//	unsigned char main_check_pre_flag;
	FALSE,	//	unsigned char OuputDisplayMode;
	FALSE,	//	unsigned char OutputVencMode;
	FALSE,	//	unsigned char OutputMemoryMode;
	FALSE,	//	unsigned char OutputAveMode;
	FALSE,	//	unsigned char RGB444Mode;
	FALSE,	//	unsigned char RGB444Mode_change;
	FALSE,	//	unsigned char DI_low_delay_flag;
	_UNKNOWN_INPUT,	//	unsigned int main_opensourceID;
	FALSE,	//	unsigned char main_VO_smoothtoggle_need_presetting;
	FALSE,	//	unsigned char VscMuteStatus;
	FALSE,	//	unsigned char Main_AutoRunScaler;
	FALSE,	//	char Main_Run_Scaler_flag;
	FALSE,	//	char Main_Output_Set_flag;
	FALSE,	//	char Main_force_frc_flag;
	FALSE,	//	char Main_force_frc_fs_flag;
	FALSE,	//	char Main_Scaler_Stop_flag;
	FALSE,	//	char Main_Output_Set_flag_Special_Case;
	FALSE,	//	char Main_Request_ForceBG_ctrl;
	FALSE,	//	char Main_Reset_Mode_flag;
	FALSE,	//	unsigned char Main_during_scalerflow_flag;
	0,	//	unsigned char main_winfreeze;
	0,	//unsigned char mainVscFreezeFlag;
	0,	//unsigned char subVscFreezeFlag;
	FALSE,	//	char memc_realcinema_run_flag;
	0xF0,	//	unsigned char separator_vsc;

	//smooth toggle
	FALSE,	//	unsigned char check_only_xy_shift_same_region;
	FALSE,	//	char Main_smooth_toggle_set_flag;
	FALSE,	//	char Main_SetOutput_request_muteoff_smooth_toggle_set_flag;
	0,	//	unsigned char JPEG_Scaler_SM;
	0,	//	unsigned char adaptive_stream;
	ADAPTIVE_STREAM_INIT,	//	unsigned char adaptive_stream_pre;
	0xF1,	//	unsigned char separator_smoothtoggle;

	//adc
	0xF2,	//	unsigned char separator_adc;

	//avd
	0xff,	//	unsigned char g_ucCheckAVDandWebOSInfoCount;
	0,	//	unsigned char g_ucVSCCheckATVChanelChange;
	0,	//	unsigned char g_ucVSCATVChanelChangeStart;
	0,	//	unsigned char g_ucVSCATVSetWinBlankCount;
	0,	//	unsigned char g_ucVDCDetectStage;
	FALSE,	//	char Main_ATV_Go_Smooth_Toggle_flag;
	FALSE,	//	char Main_ATV_PassThrought_output_flag;
	0,	//	unsigned short Main_ATV_InputRegion_x_pre;
	0,	//	unsigned short Main_ATV_InputRegion_y_pre;
	0,	//	unsigned short Main_ATV_InputRegion_w_pre;
	0,	//	unsigned short Main_ATV_InputRegion_h_pre;
	0,	//	unsigned short Main_ATV_OutputRegion_x_pre;
	0,	//	unsigned short Main_ATV_OutputRegion_y_pre;
	0,	//	unsigned short Main_ATV_OutputRegion_w_pre;
	0,	//	unsigned short Main_ATV_OutputRegion_h_pre;
	FALSE,	//	char run_iv2dv_slow_tuning_flag;
	0xF3,	//	unsigned char separator_avd;

	//hdmi
	FALSE,	//	unsigned char line_cnt_no_run_hdmi_check;
	0xF4,	//	unsigned char separator_hdmi;

	//HDR
	0,	//	unsigned char hdmi_dolby_vision_flag;
	0xF5,	//	unsigned char separator_hdr;

	//Sub path
	_UNKNOWN_INPUT,	//	unsigned int sub_opensourceID;
	FALSE,	//	unsigned char LivezoomvoinfocheckFlag;
	FALSE,	//	unsigned char LivezoomMainRerunFlag;
	FALSE,	//	unsigned char LivezoomSubRerunFlag;
	FALSE,	//	LivezoomMainRerunEndneedOpenforcebgFlag;
	FALSE,	//	LivezoomSubRerunEndneedOpenforcebgFlag
	FALSE,	//	unsigned char magnifier_mainscaler_run_livezoom;
	FALSE,	//	unsigned char DataFramesynclivezoom;
	FALSE,	//	unsigned char LivezoomOffKeepMainForceBG;
	FALSE,	//	unsigned char multiview_sub_interlace_flag;
	FALSE,	//	unsigned char Sub_OuputDisplayMode;
	FALSE,	//	unsigned char Sub_OutputVencMode;
	FALSE,	//	unsigned char Sub_OutputMemoryMode;
	FALSE,	//	unsigned char Sub_OutputAveMode;
	FALSE,	//	char Sub_Run_Scaler_flag;
	FALSE,	//	char Sub_Output_Set_flag;
	FALSE,	//	char Sub_Scaler_Stop_flag;
	FALSE,	//	unsigned char Sub_AutoRunScaler;
	FALSE,	//	char Sub_ATV_Go_Smooth_Toggle_flag;
	FALSE,	//	char Sub_Request_ForceBG_ctrl;
	FALSE,	//	char Sub_Reset_Mode_flag;
	0,	//	unsigned short Sub_ATV_InputRegion_x_pre;
	0,	//	unsigned short Sub_ATV_InputRegion_y_pre;
	0,	//	unsigned short Sub_ATV_InputRegion_w_pre;
	0,	//	unsigned short Sub_ATV_InputRegion_h_pre;
	0,	//	unsigned short Sub_ATV_OutputRegion_x_pre;
	0,	//	unsigned short Sub_ATV_OutputRegion_y_pre;
	0,	//	unsigned short Sub_ATV_OutputRegion_w_pre;
	0,	//	unsigned short Sub_ATV_OutputRegion_h_pre;
	0,	//	unsigned int  sub_zoom_disp_hpos;
	0,	//	unsigned int  sub_zoom_disp_vpos;
	0,	//	unsigned int  sub_zoom_disp_hsize;
	0,	//	unsigned int  sub_zoom_disp_vsize;
	FALSE,	//	unsigned char sub_wind0000;
	0xF6,	//	unsigned char separator_sub;

	//vpq
	0,	//	unsigned char vpq_ld_first_boot;
	0xF7,	//	unsigned char separator_vpq;
	//game mode
	0,	//unsigned char game_mode_dynamic_flag;
	FALSE,	//	char Main_run_smooth_toggle_from_mute_off;
	0,   //unsigned char dvo_dual_decoder_flag;
	0, //unsigned char dvo_dual_decoder_run;
}
; // debug scaler flag tracker

// information of TV mode
//static SLR_TV_CHANNEL_INFO 	tvInfo = {SLR_ATV_MODE, SLR_ATV_VIDEO_NTSC};//frank@0406 change SLR_TV_MODE_NONE to SLR_ATV_MODE ti test ATV SOURCE
//static bool tvExitScanflag =true;
static bool doingAutoPosition = FALSE; // add by qiao 20120716
// information of PIP
StructPipDataType gPipData =
{
	0,	// disable
	0,	// none
	0,	// top-left
//	50,	// SubRgbContrast		// marked by hsliao 20090306
//	50,	// SubRgbBrightness	// marked by hsliao 20090306
	0,	// PipBlending
	0,
	0,
};



#if 0
static RATIO_TYPE_STATE ratiotype_state=RT_STATE_INIT;
static SLR_RATIO_TYPE ratio_type_pre=SLR_RATIO_AUTO;
#endif

static StructSubInfo 				SubInfo;
static SLR_RATIO_TYPE 				currZoomMode = SLR_RATIO_CUSTOM;
static SLR_RATIO_TYPE 				pre_currZoomMode = SLR_RATIO_CUSTOM;

#if defined (TV003_ADTV)
static bool 				m_isUserSetRatio=false;
#endif

// from scaler
static unsigned char 				ucIVS2DVSDelay = 0;
static unsigned char 				IVS2DVSDelay_VGA = 0;

static unsigned char 				ucIHSDelay = 0;
static unsigned char 				ucIPH_Max_Margin =0;
static unsigned char 				ucIPH_Min_Margin =0;
static unsigned char 				ucIPV_Max_Margin =0;
static unsigned char 				ucIPV_Min_Margin =0;

#ifdef CONFIG_ENABLE_3D_SETTING
static unsigned char 				b3DEnablable = OFF;
#endif
//static unsigned char adaptive_3d_en = OFF;

//for HDMI
static unsigned short 				HDMIDiditalMeasureIVH;

static unsigned short 				m_TvBlueScreen = FALSE;

//static int 				m_ScalerDrvDevice = -1;

static SLR_VOINFO 			vo_info[2];			// VO info from kernel space
static SLR_VOINFO 			pre_vo_info[2];

//static unsigned char 				gTvScanMode = FALSE; // TV scan or not

//static unsigned char 				m_ChangeChannelEnable = FALSE;	//TREUE: system is changing channel

static UINT8	m_AtvDuringChangeChannel_Flag	=	_FALSE;	//TREUE: ATV is changing channel

static unsigned char 				vo_timing_equal = FALSE;	//TREUE: system is changing channel
static unsigned char				m_isPrevCheckFail = FALSE;

unsigned char				tripled_info = 0;

unsigned char		dclk_under_flow_2dcvt3d;
unsigned char		dclk_divider = 1;

static unsigned char LivezoomOrMagnifierPIPON = FALSE;

void Set_LivezoomOrMagnifierPIPON(unsigned char value)
{
	LivezoomOrMagnifierPIPON = value;
}

unsigned char Get_LivezoomOrMagnifierPIPON(void)
{
	return LivezoomOrMagnifierPIPON;
}


static LIVE_ZOOM_TYPE_T Live_zoom_mode = LIVE_ZOOM_OFF;

void Set_Live_zoom_mode(LIVE_ZOOM_TYPE_T type)
{
	Live_zoom_mode = type;
}

LIVE_ZOOM_TYPE_T Get_Live_zoom_mode(void)
{
	return Live_zoom_mode;
}

static unsigned char LivezoomOffMainForceBG = FALSE;

void Set_LivezoomOffMainForceBG(unsigned char value)
{
	LivezoomOffMainForceBG = value;
}

unsigned char Get_LivezoomOffMainForceBG(void)
{
	return LivezoomOffMainForceBG;
}

// new display ready version control
typedef struct _DISP_INDEX{
	unsigned char	validFlag;
	unsigned int	playIndex;
} DISP_INDEX;

//static DISP_INDEX gDispIndex={0, 0};

static SLR_RATIO_TYPE m_3dRatio = SLR_RATIO_AUTO;

//----------------------------------------------------------
//		main function
//----------------------------------------------------------
/**
 * Scaler_update_src_type
 * update src_info to kernel space
 *
 * @param {void}
 * @return {void}
 */
void Scaler_update_src_type(void)
{
	unsigned short *pkg = NULL;
	unsigned int i =0, ulPkgCount = 0;
	int ret;

	pkg = (unsigned short *)kmalloc(sizeof(unsigned short)*((unsigned int)slrSourceMax+1),GFP_KERNEL);
	//frank@1017 add below condition to solve scan tool warning
	if(pkg){
	pkg[0] = (unsigned short)slrSourceMax;
	for (i=0; i<slrSourceMax; ++i) {
		pkg[i+1] = src_info[i].src_type;
	}

	ulPkgCount = (unsigned int)slrSourceMax+1;

	for (i = 0; i < ulPkgCount; i++)
	{
		pkg[i] = fwif_color_ChangeOneUINT16Endian(pkg[i], 0);
		//printk("pkg[%d]=0x%x\n", i, pkg[i]);
	}

	// copy to RPC share memory
	memcpy((unsigned short*)Scaler_GetShareMemVirAddr(SCALERIOC_SETSRCINFO), pkg, sizeof(unsigned short)*((unsigned int)slrSourceMax+1));

	if ((ret = Scaler_SendRPC(SCALERIOC_SETSRCINFO,0,0)) <0)
	{
		pr_debug("ret = %d, set src_type to driver fail !!!\n", ret);
	}

	kfree(pkg);
   }

}

/**
 * Scaler_StructInit
 * register src_info to scaler library
 *
 * @param {sourceInfo : source list}
 * @param {maxSource : max number of source list }
 * @param {mainInputSource: index of main source}
 * @param {subInputSource: index of sub source}
 * @return {TRUE/FALSE }
 */
unsigned char Scaler_StructInit(StructSourceInput* sourceInfo, unsigned char maxSource, unsigned char mainInputSource, unsigned char subInputSource)
{
	const unsigned char upper_bound = (SRC_NUM_UPPER < 0xFF ) ? SRC_NUM_UPPER : 0xFF;

	//checking input parameters
	if (!sourceInfo)
		return FALSE;

	if ( maxSource > upper_bound ) {
		return FALSE;
	}

	//main process
	src_info = sourceInfo;
	slrSourceMax = maxSource;

	Scaler_update_src_type();

	//slrSourceInit = TRUE;

	info = &disp_info[SLR_MAIN_DISPLAY];/*need remove after bring up*/
	disp_info[SLR_MAIN_DISPLAY].display = SLR_MAIN_DISPLAY;
	disp_info[SLR_MAIN_DISPLAY].input_src = mainInputSource;
	disp_info[SLR_MAIN_DISPLAY].state = _MODE_STATE_SEARCH;;
	disp_info[SLR_MAIN_DISPLAY].channel = _CHANNEL1;
	disp_info[SLR_MAIN_DISPLAY].disp_status = 0;
	disp_info[SLR_MAIN_DISPLAY].data_array_index = src_info[mainInputSource].osdarray_index;

#ifdef CONFIG_DUAL_CHANNEL
	gPipData.enable = 1;// reset pip mode
	gPipData.type = 3;// reset pip mode
	gPipData.pipPosition = 3;
	SubInfo.MpEnable = 0;
	disp_info[SLR_SUB_DISPLAY].display = SLR_SUB_DISPLAY;
	disp_info[SLR_SUB_DISPLAY].input_src = subInputSource;
	disp_info[SLR_SUB_DISPLAY].state = _MODE_STATE_NONE;
	disp_info[SLR_SUB_DISPLAY].channel = _CHANNEL2;
	disp_info[SLR_SUB_DISPLAY].FrameSyncFlag = FALSE;
	disp_info[SLR_SUB_DISPLAY].disp_status = 0;
	disp_info[SLR_SUB_DISPLAY].nShowMpType = SUBTYPE_NONE;
	disp_info[SLR_SUB_DISPLAY].data_array_index = src_info[subInputSource].osdarray_index;
#endif

	//if (Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE())
	{
		disp3d_info[SLR_MAIN_DISPLAY].bIs3dFmt = 0;
		disp3d_info[SLR_MAIN_DISPLAY].uc3dType = SLR_3D_2D_ONLY;
		disp3d_info[SLR_MAIN_DISPLAY].bEnableDoubleDVS = 0;
		disp3d_info[SLR_MAIN_DISPLAY].uc3dFlow = 0;
		disp3d_info[SLR_MAIN_DISPLAY].display_size = 0;
		disp3d_info[SLR_MAIN_DISPLAY].main_addr = 0;
		disp3d_info[SLR_MAIN_DISPLAY].main_sec_addr = 0;
		disp3d_info[SLR_MAIN_DISPLAY].main_third_addr = 0;
		disp3d_info[SLR_MAIN_DISPLAY].sub_addr = 0;
		disp3d_info[SLR_MAIN_DISPLAY].sub_sec_addr = 0;
		disp3d_info[SLR_MAIN_DISPLAY].ucLRsequence = 0;
		disp3d_info[SLR_MAIN_DISPLAY].bIs2Dcvt3D = 0;
		disp3d_info[SLR_MAIN_DISPLAY].c3dDepth = 0;
		disp3d_info[SLR_MAIN_DISPLAY].ui3dBlkStep = 0;

#ifdef CONFIG_DUAL_CHANNEL
		disp3d_info[SLR_SUB_DISPLAY].bIs3dFmt = 0;
		disp3d_info[SLR_SUB_DISPLAY].uc3dType = SLR_3D_2D_ONLY;
		disp3d_info[SLR_SUB_DISPLAY].bEnableDoubleDVS = 0;
		disp3d_info[SLR_SUB_DISPLAY].uc3dFlow = 0;
		disp3d_info[SLR_SUB_DISPLAY].display_size = 0;
		disp3d_info[SLR_SUB_DISPLAY].main_addr = 0;
		disp3d_info[SLR_SUB_DISPLAY].main_sec_addr = 0;
		disp3d_info[SLR_SUB_DISPLAY].main_third_addr = 0;
		disp3d_info[SLR_SUB_DISPLAY].sub_addr = 0;
		disp3d_info[SLR_SUB_DISPLAY].sub_sec_addr = 0;
		disp3d_info[SLR_SUB_DISPLAY].ucLRsequence = 0;
		disp3d_info[SLR_SUB_DISPLAY].bIs2Dcvt3D = 0;
		disp3d_info[SLR_SUB_DISPLAY].c3dDepth = 0;
		disp3d_info[SLR_SUB_DISPLAY].ui3dBlkStep = 0;
#endif //#ifdef CONFIG_DUAL_CHANNEL
	}


	InputSource[SLR_MAIN_DISPLAY]=mainInputSource;
#ifdef CONFIG_DUAL_CHANNEL
	InputSource[SLR_SUB_DISPLAY]=subInputSource;
#endif

	return TRUE;
}

void Scaler_StructUninit(void)
{
	/*info = NULL;*/
	memset(disp_info, 0, MAX_DISP_CHANNEL_NUM*sizeof(StructDisplayInfo));
//	memset(&disp3d_info, 0, sizeof(StructDisplay3DInfo));
	memset(&disp3d_info, 0, MAX_DISP_CHANNEL_NUM*sizeof(StructDisplay3DInfo));
}

void Scaler_SET_VSCDispinfo_WithVFEDispinfo(unsigned char display, StructDisplayInfo* VFEDispInfo)
{
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_ADC_CLOCK, VFEDispInfo->INPUT_ADC_CLOCK);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN_PRE, VFEDispInfo->IPV_ACT_LEN_PRE);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA_PRE, VFEDispInfo->IPV_ACT_STA_PRE);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_WID_PRE, VFEDispInfo->IPH_ACT_WID_PRE);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_STA_PRE, VFEDispInfo->IPH_ACT_STA_PRE);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_HSYNC, VFEDispInfo->Hsync);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_VSYNC, VFEDispInfo->Vsync);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MODE_CURR, VFEDispInfo->ucMode_Curr);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MODE_TABLE_INDEX, VFEDispInfo->ucMode_Table_Index);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_AFD, VFEDispInfo->afd);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_POLARITY, VFEDispInfo->Polarity);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_H_FREQ, VFEDispInfo->IHFreq);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_FREQ, VFEDispInfo->IVFreq);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_H_LEN, VFEDispInfo->IHTotal);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_LEN, VFEDispInfo->IVTotal);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_H_COUNT, VFEDispInfo->IHCount_PRE);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_COUNT, VFEDispInfo->IVCount_PRE);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IHSYNCPULSECOUNT, VFEDispInfo->IHSyncPulseCount);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_COLOR_SPACE, VFEDispInfo->color_space);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_COLOR_DEPTH, VFEDispInfo->color_depth);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_COLOR_IMETRY, VFEDispInfo->color_imetry);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IVSYNCPULSECOUNT, VFEDispInfo->IVSyncPulseCount);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_SYNC_HIGH_PERIOD, VFEDispInfo->IVPolarityIndicator);

	Scaler_DispSetStatus(display, SLR_DISP_422,((VFEDispInfo->disp_status&_BIT1)>>1));
	Scaler_DispSetStatus(display, SLR_DISP_INTERLACE,((VFEDispInfo->disp_status&_BIT8)>>8));
	//Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE,FALSE);
#if 0//frank@20141103 mark below code to reduce time
	printk("VSC timing info from VFE:SLR_INPUT_ADC_CLOCK:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_ADC_CLOCK));
	printk("VSC timing info from VFE:SLR_INPUT_IPV_ACT_LEN_PRE:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN_PRE));
	printk("VSC timing info from VFE:SLR_INPUT_IPV_ACT_STA_PRE:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA_PRE));
	printk("VSC timing info from VFE:SLR_INPUT_IPH_ACT_WID_PRE:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_WID_PRE));
	printk("VSC timing info from VFE:SLR_INPUT_IPH_ACT_STA_PRE:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_STA_PRE));
	printk("VSC timing info from VFE:SLR_INPUT_HSYNC:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_HSYNC));
	printk("VSC timing info from VFE:SLR_INPUT_VSYNC:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_VSYNC));
	printk("VSC timing info from VFE:SLR_INPUT_MODE_CURR:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MODE_CURR));
	printk("VSC timing info from VFE:SLR_INPUT_MODE_TABLE_INDEX:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MODE_TABLE_INDEX));
	printk("VSC timing info from VFE:SLR_INPUT_AFD:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_AFD));
	printk("VSC timing info from VFE:SLR_INPUT_POLARITY:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_POLARITY));
	printk("VSC timing info from VFE:SLR_INPUT_H_FREQ:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_H_FREQ));
	printk("VSC timing info from VFE:SLR_INPUT_V_FREQ:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ));
	printk("VSC timing info from VFE:SLR_INPUT_H_LEN:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_H_LEN));
	printk("VSC timing info from VFE:SLR_INPUT_V_LEN:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_LEN));
	printk("VSC timing info from VFE:SLR_INPUT_H_COUNT:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_H_COUNT));
	printk("VSC timing info from VFE:SLR_INPUT_V_COUNT:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_COUNT));
	printk("VSC timing info from VFE:SLR_INPUT_IHSYNCPULSECOUNT:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IHSYNCPULSECOUNT));
	printk("VSC timing info from VFE:SLR_INPUT_COLOR_SPACE:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_COLOR_SPACE));
	printk("VSC timing info from VFE:SLR_INPUT_COLOR_DEPTH:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_COLOR_DEPTH));
	printk("VSC timing info from VFE:SLR_INPUT_COLOR_IMETRY:%d\n",Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_COLOR_IMETRY));
	printk("VSC timing info from VFE:SLR_DISP_422:%d\n",Scaler_DispGetStatus(display, SLR_DISP_422));
	printk("VSC timing info from VFE:SLR_DISP_INTERLACE:%d\n",Scaler_DispGetStatus(display, SLR_DISP_INTERLACE));
#endif

}

unsigned char vsc_timinginfo_check(void)
{
	if(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)==0)
	{
		return FALSE;
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)==0)
	{
		return FALSE;
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_H_FREQ) ==0)
	{
		return FALSE;
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) ==0)
	{
		return FALSE;
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) ==0)
	{
		return FALSE;
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_V_LEN) ==0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
/**
	 get current mode status of current dispaly channel
*/

unsigned int Scaler_ModeGetModeInfo(SLR_MODE_INFO infoList)
{
	switch (infoList)
	{
		case SLR_MODE_MODECURR:
			return stModeInfo.ModeCurr;
		case SLR_MODE_POLARITY:
			return stModeInfo.Polarity;
		case SLR_MODE_IHFREQ:
			return stModeInfo.IHFreq;
		case SLR_MODE_IVFREQ:
			return stModeInfo.IVFreq;
		case SLR_MODE_IHLEN:
			return stModeInfo.IHTotal;
		case SLR_MODE_IVLEN:
			return stModeInfo.IVTotal;
		case SLR_MODE_IHWID:
			return stModeInfo.IHWidth;
		case SLR_MODE_IVHEIGHT:
			return stModeInfo.IVHeight;
		case SLR_MODE_IHSTARTPOS:
			return stModeInfo.IHStartPos;
		case SLR_MODE_IVSTARTPOS:
			return stModeInfo.IVStartPos;
		case SLR_MODE_IHCOUNT:
			return stModeInfo.IHCount;
		case SLR_MODE_IVCOUNT:
			return stModeInfo.IVCount;
		case SLR_MODE_IHSYNCPULSECOUNT:
			return stModeInfo.IHSyncPulseCount;
		default:
			return 0;
	}
}

/**
	 set current mode status of current dispaly channel
*/

void Scaler_ModeSetModeInfo(SLR_MODE_INFO infoList, unsigned int data)
{
	switch (infoList)
	{
		case SLR_MODE_MODECURR:
			stModeInfo.ModeCurr = (unsigned char)data;
			break;
		case SLR_MODE_POLARITY:
			stModeInfo.Polarity = (unsigned char)data;
			break;
		case SLR_MODE_IHFREQ:
			stModeInfo.IHFreq = (unsigned short)data;
			break;
		case SLR_MODE_IVFREQ:
			stModeInfo.IVFreq = (unsigned short)data;
			break;
		case SLR_MODE_IHLEN:
			stModeInfo.IHTotal = (unsigned short)data;
			break;
		case SLR_MODE_IVLEN:
			stModeInfo.IVTotal = (unsigned short)data;
			break;
		case SLR_MODE_IHWID:
			stModeInfo.IHWidth = (unsigned short)data;
			break;
		case SLR_MODE_IVHEIGHT:
			stModeInfo.IVHeight = (unsigned short)data;
			break;
		case SLR_MODE_IHSTARTPOS:
			stModeInfo.IHStartPos = (unsigned short)data;
			break;
		case SLR_MODE_IVSTARTPOS:
			stModeInfo.IVStartPos = (unsigned short)data;
			break;
		case SLR_MODE_IHCOUNT:
			stModeInfo.IHCount = (unsigned short)data;
			break;
		case SLR_MODE_IVCOUNT:
			stModeInfo.IVCount = (unsigned short)data;
			break;
		case SLR_MODE_IHSYNCPULSECOUNT:
			stModeInfo.IHSyncPulseCount = (unsigned short)data;
			break;
		default:
			break;
	}

	return;
}

/**
	 get current hdmi mode status of current dispaly channel
*/

unsigned int Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_INFO infoList)
{
	switch (infoList)
	{
		case SLR_MODE_MODECURR:
			return stHdmiModeInfo.ModeCurr;
		case SLR_MODE_POLARITY:
			return stHdmiModeInfo.Polarity;
		case SLR_MODE_IHFREQ:
			return stHdmiModeInfo.IHFreq;
		case SLR_MODE_IVFREQ:
			return stHdmiModeInfo.IVFreq;
		case SLR_MODE_IHLEN:
			return stHdmiModeInfo.IHTotal;
		case SLR_MODE_IVLEN:
			return stHdmiModeInfo.IVTotal;
		case SLR_MODE_IHWID:
			return stHdmiModeInfo.IHWidth;
		case SLR_MODE_IVHEIGHT:
			return stHdmiModeInfo.IVHeight;
		case SLR_MODE_IHSTARTPOS:
			return stHdmiModeInfo.IHStartPos;
		case SLR_MODE_IVSTARTPOS:
			return stHdmiModeInfo.IVStartPos;
		case SLR_MODE_IHCOUNT:
			return stHdmiModeInfo.IHCount;
		case SLR_MODE_IVCOUNT:
			return stHdmiModeInfo.IVCount;
		case SLR_MODE_IHSYNCPULSECOUNT:
			return stHdmiModeInfo.IHSyncPulseCount;
		default:
			return 0;
	}
}

/**
	 set current hdmi mode status of current dispaly channel
*/

void Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_INFO infoList, unsigned int data)
{
	switch (infoList)
	{
		case SLR_MODE_MODECURR:
			stHdmiModeInfo.ModeCurr = (unsigned char)data;
			break;
		case SLR_MODE_POLARITY:
			stHdmiModeInfo.Polarity = (unsigned char)data;
			break;
		case SLR_MODE_IHFREQ:
			stHdmiModeInfo.IHFreq = (unsigned short)data;
			break;
		case SLR_MODE_IVFREQ:
			stHdmiModeInfo.IVFreq = (unsigned short)data;
			break;
		case SLR_MODE_IHLEN:
			stHdmiModeInfo.IHTotal = (unsigned short)data;
			break;
		case SLR_MODE_IVLEN:
			stHdmiModeInfo.IVTotal = (unsigned short)data;
			break;
		case SLR_MODE_IHWID:
			stHdmiModeInfo.IHWidth = (unsigned short)data;
			break;
		case SLR_MODE_IVHEIGHT:
			stHdmiModeInfo.IVHeight = (unsigned short)data;
			break;
		case SLR_MODE_IHSTARTPOS:
			stHdmiModeInfo.IHStartPos = (unsigned short)data;
			break;
		case SLR_MODE_IVSTARTPOS:
			stHdmiModeInfo.IVStartPos = (unsigned short)data;
			break;
		case SLR_MODE_IHCOUNT:
			stHdmiModeInfo.IHCount = (unsigned short)data;
			break;
		case SLR_MODE_IVCOUNT:
			stHdmiModeInfo.IVCount = (unsigned short)data;
			break;
		case SLR_MODE_IHSYNCPULSECOUNT:
			stHdmiModeInfo.IHSyncPulseCount = (unsigned short)data;
			break;
		default:
			break;
	}

	return;
}

/**
	 set current mode status of current dispaly channel
*/

unsigned char Scaler_DispInfoSetModeCurr(unsigned int modeCurr)
{
	info->ucMode_Curr = modeCurr;
	return TRUE;
}

#if 0
/**
	 set TV information
*/
unsigned char Scaler_TVSetChannelInfo(SLR_TV_CHANNEL_INFO *chInfo)
{
	int ret;

	memcpy((void *)&tvInfo, (void *)chInfo, sizeof(SLR_TV_CHANNEL_INFO));

	if (chInfo->mode == SLR_SCAN_MODE)
		gTvScanMode = TRUE;
	else
		gTvScanMode = FALSE;

	// copy to RPC share memory
	memcpy((unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_SETTVSCANMODE), &gTvScanMode, sizeof(unsigned char));
	if ((ret = Scaler_SendRPC(SCALERIOC_SETTVSCANMODE,0,1)) <0)
	{
		printk("ret=%d, set TV_scan_mode flag to driver fail !!!\n", ret);
		return FALSE;
	}

	return TRUE;
}

unsigned char Scaler_TVSetScanMode(unsigned char a_ucScanMode)
{
	int ret;
	int i = 0;


	drv_module_vdc_SetAutoScanFlag(a_ucScanMode);
	Scaler_SetAutoScanFlag(a_ucScanMode);

	//USER:LewisLee DATE:2012/07/04
	//when TV auto scan, set as FRC
	//to prevent OSD jitter
	if(_TRUE == a_ucScanMode)
	{
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
	}

	// copy to RPC share memory
	memcpy((unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_SETTVSCANMODE), &a_ucScanMode, sizeof(unsigned char));
	if ((ret = Scaler_SendRPC(SCALERIOC_SETTVSCANMODE)) <0)
	{
		printk("ret=%d, set TV_scan_mode flag to driver fail !!!\n", ret);
		return FALSE;
	}



	if (TRUE == a_ucScanMode)
	{
		printk("ATV auto scan start\n");

		// Check 3D->2D finish
		while(FALSE == Scaler_Get3D2DFinishFlag())
		//while (_2DCVT3D_STATE_NONE != modestate_get_2Dcvt3D_changeState())
		{
			//printk("[%d]3D->2D finish flag =%x\n", i, Scaler_Get3D2DFinishFlag());
			Rt_Sleep(100);

			i++;

			if (i > 20)
				break;
		}
		Scaler_Set3D2DFinishFlag(TRUE);
		printk("3D->2D finish count=%x\n", i);
	}
	else
		printk("ATV auto scan End\n");

	return TRUE;
}

/**
 * Scaler_TVGetScanMode
 * get rhe status of TV scan
 *
 * @param { void }
 * @return { TV Scan or not }
 *
 */
unsigned char Scaler_TVGetScanMode(void)
{
	return gTvScanMode;
}
//direct set Flag avoid state receive data too late
void Scaler_TVSetExitScan(bool m_exit)
{
	 tvExitScanflag = m_exit;
	 printk("\033[1;31m ##### %s%d %s:tvExitScanflag:%d\033[m\n",__FILE__, __LINE__,__FUNCTION__,tvExitScanflag );
}
bool Scaler_TVGetExitScan(void)
{
	 return tvExitScanflag;
}
SLR_TV_MODE Scaler_TVGetMode(void)
{
	return tvInfo.mode;
}

SLR_ATV_VIDEO_STD Scaler_TVGetAtvVideoStd(void)
{
	return tvInfo.atvVideoStd;
}
#endif

/**
	initialize src_info
*/
void Scaler_InputSrcInit(StructSourceInput* ptr)
{
	src_info = ptr;
}

/**
	 Get src_info status
*/
StructSourceInput* Scaler_Get_InputSrcInit(void)
{
	return src_info;
}

/**
	initialize auto_av_sv_src_info
*/
void Scaler_AutoAVInputSrcInit(StructSourceInput* ptr)
{
	auto_av_sv_src_info = ptr;
}

/**
	get pointer of input source
*/
StructSourceInput* Scaler_InputSrc(unsigned char idx)
{
	return &src_info[idx];
}

unsigned short Scaler_InputSrcIndex(unsigned char idx)
{
	return src_info[idx].src_index;
}

ENUM_TVD_INPUT_FORMAT Scaler_InputSrcFormat(unsigned char idx)
{
	return src_info[idx].input_fmt;
}

ENUM_TVD_INPUT_FORMAT Scaler_InputSrcGetMainFormat(void)
{
	return src_info[info->input_src].input_fmt;
}

/**
	get pointer of input source
*/
StructSourceInput* Scaler_AutoAVInputSrc(unsigned char idx)
{
	return &auto_av_sv_src_info[idx];
}

/**
	get source raw type by source index
*/
unsigned short Scaler_InputSrcGetRawType(unsigned char idx)
{
	return src_info[idx].src_type;
}

/**
	get source type by source index
*/
unsigned char Scaler_InputSrcGetIdxType(unsigned char idx)
{
	return GET_SOURCE_TYPE(src_info[idx].src_type);
}

/**
	get source from by source index
*/
unsigned char Scaler_InputSrcGetIdxFrom(unsigned char idx)
{
	return GET_SOURCE_FROM(src_info[idx].src_type);
}


/**
	 get source format of dispaly channel
*/

ENUM_TVD_INPUT_FORMAT Scaler_InputSrcGetFormat(SCALER_DISP_CHANNEL channel)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	return src_info[disp_info[channel].input_src].input_fmt;
}


/**
	 get source type of dispaly channel
*/

unsigned char Scaler_InputSrcGetType(SCALER_DISP_CHANNEL channel)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	return GET_SOURCE_TYPE(src_info[disp_info[channel].input_src].src_type);
}

/**
	 get source type of dispaly channel
*/

unsigned char Scaler_InputSrcGetFrom(SCALER_DISP_CHANNEL channel)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	return GET_SOURCE_FROM(src_info[disp_info[channel].input_src].src_type);
}

/**
	get source from of main dispaly channel
*/
unsigned char Scaler_InputSrcGetMainChFrom(void)
{
	return GET_SOURCE_FROM(src_info[info->input_src].src_type);
}

/**
	 get source type of main dispaly channel
*/
unsigned char Scaler_InputSrcGetMainChType(void)
{
	return GET_SOURCE_TYPE(src_info[info->input_src].src_type);
}

/**
	 get input source format of main dispaly channel
*/
unsigned char Scaler_InputSrcGetMainChFormat(void)
{
	return src_info[info->input_src].input_fmt;
}

StructDisplayInfo* Scaler_DispGetInfoPtr(void)
{
	return info;
}

/* MOD_BY_QIAO 20120716: Don't Use ENABLE_ADJUST_POSITION_DEPEND_ON_OSD_VALUE When Doing Auto */
void Scaler_DispSetAutoPosition(bool flag)
{
	doingAutoPosition = flag;
}

bool Scaler_DispGetAutoPosition(void)
{
	return doingAutoPosition;
}
/* MOD_END */

unsigned short Scaler_DispGetInputInfo(SLR_INPUT_INFO infoList)
{
	return Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)info->display,infoList);
}

void Scaler_DispSetInputInfo(SLR_INPUT_INFO infoList, unsigned short value)
{
	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)info->display,infoList,value);
}

void Scaler_DispSetInputInfoByDisp(SCALER_DISP_CHANNEL channel, SLR_INPUT_INFO infoList, unsigned short value)
{
	switch (infoList)
	{
		case SLR_INPUT_H_FREQ:
			disp_info[channel].IHFreq = value;
			break;
		case SLR_INPUT_V_FREQ:
			disp_info[channel].IVFreq = value;
			break;
		case SLR_INPUT_H_LEN:
			disp_info[channel].IHTotal = value;
			break;
		case SLR_INPUT_V_LEN:
			disp_info[channel].IVTotal = value;
			break;
		case SLR_INPUT_H_COUNT:
			disp_info[channel].IHCount_PRE = value;
			break;
		case SLR_INPUT_V_COUNT:
			disp_info[channel].IVCount_PRE = value;
			break;
		case SLR_INPUT_IPH_ACT_STA:
			disp_info[channel].IPH_ACT_STA = value;
			break;
		case SLR_INPUT_IPV_ACT_STA:
			disp_info[channel].IPV_ACT_STA = value;
			break;
		case SLR_INPUT_IPH_ACT_WID:
			disp_info[channel].IPH_ACT_WID = value;
			break;
		case SLR_INPUT_IPV_ACT_LEN:
			disp_info[channel].IPV_ACT_LEN = value;
			break;
		case SLR_INPUT_ADC_CLOCK:
			disp_info[channel].INPUT_ADC_CLOCK = value;
			break;
		case SLR_INPUT_CHANNEL:
			disp_info[channel].channel = value;
			break;
		case SLR_INPUT_DATA_ARRAY_IDX:
			disp_info[channel].data_array_index = value;
			break;
		case SLR_INPUT_MODE_TABLE_INDEX:
			disp_info[channel].ucMode_Table_Index = value;
			break;
		case SLR_INPUT_MODE_CURR:
			disp_info[channel].ucMode_Curr = value;
			break;
		case SLR_INPUT_ASPECT_RATIO:
			disp_info[channel].IAspectRatio = value;
			break;
		case SLR_INPUT_AFD:
			disp_info[channel].afd = (SLR_AFD_TYPE)value;
			break;
		case SLR_INPUT_MEM_ACT_HSTA:
			disp_info[channel].MEM_ACT_HSTA = value;
			break;
		case SLR_INPUT_MEM_ACT_VSTA:
			disp_info[channel].MEM_ACT_VSTA = value;
			break;
		case SLR_INPUT_MEM_ACT_LEN:
			disp_info[channel].MEM_ACT_LEN = value;
			break;
		case SLR_INPUT_MEM_ACT_WID:
			disp_info[channel].MEM_ACT_WID = value;
			break;
		case SLR_INPUT_DISPLAY:
			disp_info[channel].display = value;
			break;
		case SLR_INPUT_FAILURECOUNT:
			disp_info[channel].FailureCount = value;
			break;
		case SLR_INPUT_FAILURECOUNT_NOSUPPORT:
			disp_info[channel].FailureCountNoSupport = value;
			break;
		case SLR_INPUT_FRAMESYNC:
			disp_info[channel].FrameSyncFlag = value;
			break;
		case SLR_INPUT_CAP_LEN:
			disp_info[channel].CapLen = value;
			break;
		case SLR_INPUT_CAP_WID:
			disp_info[channel].CapWid = value;
			break;
		case SLR_INPUT_DISP_LEN:
			disp_info[channel].DispLen = value;
			break;
		case SLR_INPUT_DISP_WID:
			disp_info[channel].DispWid = value;
			break;
		case SLR_INPUT_DISP_LEN_PRE:
			disp_info[channel].DispLen_PRE = value;
			break;
		case SLR_INPUT_DISP_WID_PRE:
			disp_info[channel].DispWid_PRE = value;
			break;
		case SLR_INPUT_POLARITY:
			disp_info[channel].Polarity = value;
			break;
		case SLR_INPUT_IPV_SMARTFIT_START:
			disp_info[channel].IPV_SMARTFIT_START = value;
			break;
		case SLR_INPUT_IPH_SMARTFIT_START:
			disp_info[channel].IPH_SMARTFIT_START = value;
			break;
		case SLR_INPUT_IPV_ACT_LEN_PRE:
			disp_info[channel].IPV_ACT_LEN_PRE = value;
			break;
		case SLR_INPUT_IPV_ACT_STA_PRE:
			disp_info[channel].IPV_ACT_STA_PRE = value;
			break;
		case SLR_INPUT_IPH_ACT_WID_PRE:
			disp_info[channel].IPH_ACT_WID_PRE = value;
			break;
		case SLR_INPUT_IPH_ACT_STA_PRE:
			disp_info[channel].IPH_ACT_STA_PRE = value;
			break;
		case SLR_INPUT_IHSYNCPULSECOUNT:
			disp_info[channel].IHSyncPulseCount = value;
			break;
		case SLR_INPUT_HSYNC:
			disp_info[channel].Hsync = value;
			break;
		case SLR_INPUT_VSYNC:
			disp_info[channel].Vsync = value;
			break;
		case SLR_INPUT_STATE:
			disp_info[channel].state = value;
			break;
		case SLR_INPUT_NSHOWMPTYPE:
			disp_info[channel].nShowMpType = value;
			break;
		case SLR_INPUT_INPUT_SRC:
			disp_info[channel].input_src = (unsigned char)value;
			break;
		case SLR_INPUT_OSD_INPUT_SRC:
			disp_info[channel].osd_input_src = (unsigned char)value;
			break;
		case SLR_INPUT_IPV_DLY_PRE:
			disp_info[channel].IPV_DLY_PRE = value;
			break;
		case SLR_INPUT_BGCOLOR_R:
			disp_info[channel].bg_color_r = value;
			break;
		case SLR_INPUT_BGCOLOR_G:
			disp_info[channel].bg_color_g = value;
			break;
		case SLR_INPUT_BGCOLOR_B:
			disp_info[channel].bg_color_b = value;
			break;
		case SLR_INPUT_DISP_STATUS:
			disp_info[channel].disp_status = value;
			break;
		case SLR_INPUT_WSS:
			disp_info[channel].wss = (SLR_WSS_TYPE)value;
			break;
		case SLR_INPUT_COLOR_SPACE:
			disp_info[channel].color_space= value;
			break;
		case SLR_INPUT_COLOR_DEPTH:
			disp_info[channel].color_depth= value;
			break;
		case SLR_INPUT_COLOR_IMETRY:
			disp_info[channel].color_imetry= value;
			break;
		case SLR_INPUT_THROUGH_I3DDMA:
			disp_info[channel].through_i3ddma= value;
			break;
		case SLR_INPUT_SR_MODE:
			disp_info[channel].SR_MODE= value;
			break;
		case SLR_INPUT_PIXEL_MODE:
			disp_info[channel].PIXEL_MODE= value;
			break;
		case SLR_INPUT_DFRC_ENABLE:
			disp_info[channel].DFRC_ENABLE= value;
			break;
		case SLR_INPUT_DI_WID:
			disp_info[channel].DiWid= value;
			break;
		case SLR_INPUT_DI_LEN:
			disp_info[channel].DiLen= value;
			break;			
		case SLR_INPUT_VO_SOURCE_TYPE:
			disp_info[channel].vo_type= value;
			break;
		case SLR_INPUT_FRAC_FS_REMOVE_RATIO:
			disp_info[channel].frac_fs_remove_ratio = value;
			break;
		case SLR_INPUT_FRAC_FS_MULTIPLE_RATIO:
			disp_info[channel].frac_fs_multiple_ratio = value;
			break;
		case SLR_INPUT_DTG_MASTER_V_FREQ:
			disp_info[channel].dtg_m_v_freq = value;
			break;
#ifdef CONFIG_SDNR_CROP
		case SLR_INPUT_SDNRH_ACT_STA_PRE:
			disp_info[channel].SDNRH_ACT_STA_PRE= value;
			break;
		case SLR_INPUT_SDNRV_ACT_STA_PRE:
			disp_info[channel].SDNRV_ACT_STA_PRE= value;
			break;
		case SLR_INPUT_SDNRH_ACT_WID_PRE:
			disp_info[channel].SDNRH_ACT_WID_PRE= value;
			break;
		case SLR_INPUT_SDNRV_ACT_LEN_PRE:
			disp_info[channel].SDNRV_ACT_LEN_PRE= value;
			break;
		case SLR_INPUT_SDNRH_ACT_STA:
			disp_info[channel].SDNRH_ACT_STA= value;
			break;
		case SLR_INPUT_SDNRV_ACT_STA:
			disp_info[channel].SDNRV_ACT_STA= value;
			break;
		case SLR_INPUT_SDNRH_ACT_WID:
			disp_info[channel].SDNRH_ACT_WID= value;
			break;
		case SLR_INPUT_SDNRV_ACT_LEN:
			disp_info[channel].SDNRV_ACT_LEN= value;
			break;
#endif
		case SLR_INPUT_IVSYNCPULSECOUNT:
			disp_info[channel].IVSyncPulseCount= value;
			break;
		case SLR_INPUT_V_SYNC_HIGH_PERIOD:
			disp_info[channel].IVPolarityIndicator= value;
			break;
		default:
			pr_debug("[disp_info] Don't know how to set disp_info!!!\n");
			break;
	}

	return;
}

unsigned short Scaler_DispGetInputInfoByDisp(unsigned char channel, SLR_INPUT_INFO infoList)
{
	// frank@1017 mark below code to solve scan tool warning
	//if ((channel < SLR_MAIN_DISPLAY) || (channel > SLR_SUB_DISPLAY)) {
	if ( channel > SLR_SUB_DISPLAY) {
		pr_debug("[disp_info] Invalid channel\n");
		return 0;
	}
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif

	switch (infoList)
	{
		case SLR_INPUT_H_FREQ:
			return disp_info[channel].IHFreq;
		case SLR_INPUT_V_FREQ:
			return disp_info[channel].IVFreq;
		case SLR_INPUT_H_LEN:
			return disp_info[channel].IHTotal;
		case SLR_INPUT_V_LEN:
			return disp_info[channel].IVTotal;
		case SLR_INPUT_H_COUNT:
			return disp_info[channel].IHCount_PRE;
		case SLR_INPUT_V_COUNT:
			return disp_info[channel].IVCount_PRE;
		case SLR_INPUT_IPH_ACT_STA:
			return disp_info[channel].IPH_ACT_STA;
		case SLR_INPUT_IPV_ACT_STA:
			return disp_info[channel].IPV_ACT_STA;
		case SLR_INPUT_IPH_ACT_WID:
			return disp_info[channel].IPH_ACT_WID;
		case SLR_INPUT_IPV_ACT_LEN:
			return disp_info[channel].IPV_ACT_LEN;
		case SLR_INPUT_ADC_CLOCK:
			return disp_info[channel].INPUT_ADC_CLOCK;
		case SLR_INPUT_CHANNEL:
			return disp_info[channel].channel;
		case SLR_INPUT_DATA_ARRAY_IDX:
			return disp_info[channel].data_array_index;
		case SLR_INPUT_MODE_CURR:
			return disp_info[channel].ucMode_Curr;
		case SLR_INPUT_MODE_TABLE_INDEX:
			return  disp_info[channel].ucMode_Table_Index;
		case SLR_INPUT_ASPECT_RATIO:
			return disp_info[channel].IAspectRatio;
		case SLR_INPUT_AFD:
			return disp_info[channel].afd;
		case SLR_INPUT_MEM_ACT_HSTA:
			return disp_info[channel].MEM_ACT_HSTA;
		case SLR_INPUT_MEM_ACT_VSTA:
			return disp_info[channel].MEM_ACT_VSTA;
		case SLR_INPUT_MEM_ACT_LEN:
			return disp_info[channel].MEM_ACT_LEN;
		case SLR_INPUT_MEM_ACT_WID:
			return disp_info[channel].MEM_ACT_WID;
		case SLR_INPUT_DISPLAY:
			return disp_info[channel].display;
		case SLR_INPUT_FAILURECOUNT:
			return disp_info[channel].FailureCount;
		case SLR_INPUT_FAILURECOUNT_NOSUPPORT:
			return disp_info[channel].FailureCountNoSupport;
		case SLR_INPUT_FRAMESYNC:
			return disp_info[channel].FrameSyncFlag;
		case SLR_INPUT_CAP_LEN:
			return disp_info[channel].CapLen;
		case SLR_INPUT_CAP_WID:
			return disp_info[channel].CapWid;
		case SLR_INPUT_DISP_LEN:
			return disp_info[channel].DispLen;
		case SLR_INPUT_DISP_WID:
			return disp_info[channel].DispWid;
		case SLR_INPUT_DISP_LEN_PRE:
			return disp_info[channel].DispLen_PRE;
		case SLR_INPUT_DISP_WID_PRE:
			return disp_info[channel].DispWid_PRE;
		case SLR_INPUT_POLARITY:
			return disp_info[channel].Polarity;
		case SLR_INPUT_IPV_SMARTFIT_START:
			return disp_info[channel].IPV_SMARTFIT_START;
		case SLR_INPUT_IPH_SMARTFIT_START:
			return disp_info[channel].IPH_SMARTFIT_START;
		case SLR_INPUT_IPV_ACT_LEN_PRE:
			return disp_info[channel].IPV_ACT_LEN_PRE;
		case SLR_INPUT_IPV_ACT_STA_PRE:
			return disp_info[channel].IPV_ACT_STA_PRE;
		case SLR_INPUT_IPH_ACT_WID_PRE:
			return disp_info[channel].IPH_ACT_WID_PRE;
		case SLR_INPUT_IPH_ACT_STA_PRE:
			return disp_info[channel].IPH_ACT_STA_PRE;
		case SLR_INPUT_IHSYNCPULSECOUNT:
			return disp_info[channel].IHSyncPulseCount;
		case SLR_INPUT_HSYNC:
			return disp_info[channel].Hsync;
		case SLR_INPUT_VSYNC:
			return disp_info[channel].Vsync;
		case SLR_INPUT_STATE:
			return disp_info[channel].state;
		case SLR_INPUT_NSHOWMPTYPE:
			return disp_info[channel].nShowMpType;
		case SLR_INPUT_INPUT_SRC:
			return disp_info[channel].input_src;
		case SLR_INPUT_OSD_INPUT_SRC:
			return disp_info[channel].osd_input_src;
		case SLR_INPUT_IPV_DLY_PRE:
			return disp_info[channel].IPV_DLY_PRE;
		case SLR_INPUT_BGCOLOR_R:
			return disp_info[channel].bg_color_r;
		case SLR_INPUT_BGCOLOR_G:
			return disp_info[channel].bg_color_g;
		case SLR_INPUT_BGCOLOR_B:
			return disp_info[channel].bg_color_b;
		case SLR_INPUT_DISP_STATUS:
			return disp_info[channel].disp_status;
		case SLR_INPUT_WSS:
			return disp_info[channel].wss;
		case SLR_INPUT_COLOR_SPACE:
			return disp_info[channel].color_space;
		case SLR_INPUT_COLOR_DEPTH:
			return disp_info[channel].color_depth;
		case SLR_INPUT_COLOR_IMETRY:
			return disp_info[channel].color_imetry;
		case SLR_INPUT_THROUGH_I3DDMA:
			return disp_info[channel].through_i3ddma;
		case SLR_INPUT_SR_MODE:
			return disp_info[channel].SR_MODE;
		case SLR_INPUT_PIXEL_MODE:
			return disp_info[channel].PIXEL_MODE;
		case SLR_INPUT_DFRC_ENABLE:
			return disp_info[channel].DFRC_ENABLE;
		case SLR_INPUT_DI_WID:
			return disp_info[channel].DiWid;
		case SLR_INPUT_DI_LEN:
			return disp_info[channel].DiLen;			
		case SLR_INPUT_VO_SOURCE_TYPE:
			return disp_info[channel].vo_type;
		case SLR_INPUT_FRAC_FS_REMOVE_RATIO:
			return disp_info[channel].frac_fs_remove_ratio;
		case SLR_INPUT_FRAC_FS_MULTIPLE_RATIO:
			return disp_info[channel].frac_fs_multiple_ratio;
		case SLR_INPUT_DTG_MASTER_V_FREQ:
			return disp_info[channel].dtg_m_v_freq;
#ifdef CONFIG_SDNR_CROP
		case SLR_INPUT_SDNRH_ACT_STA_PRE:
			return disp_info[channel].SDNRH_ACT_STA_PRE;
		case SLR_INPUT_SDNRV_ACT_STA_PRE:
			return disp_info[channel].SDNRV_ACT_STA_PRE;
		case SLR_INPUT_SDNRH_ACT_WID_PRE:
			return disp_info[channel].SDNRH_ACT_WID_PRE;
		case SLR_INPUT_SDNRV_ACT_LEN_PRE:
			return disp_info[channel].SDNRV_ACT_LEN_PRE;
		case SLR_INPUT_SDNRH_ACT_STA:
			return disp_info[channel].SDNRH_ACT_STA;
		case SLR_INPUT_SDNRV_ACT_STA:
			return disp_info[channel].SDNRV_ACT_STA;
		case SLR_INPUT_SDNRH_ACT_WID:
			return disp_info[channel].SDNRH_ACT_WID;
		case SLR_INPUT_SDNRV_ACT_LEN:
			return disp_info[channel].SDNRV_ACT_LEN;
#endif
		case SLR_INPUT_IVSYNCPULSECOUNT:
			return disp_info[channel].IVSyncPulseCount;
		case SLR_INPUT_V_SYNC_HIGH_PERIOD:
			return disp_info[channel].IVPolarityIndicator;
		default:
			pr_debug("[disp_info] Don't know how to get disp_info!!!\n");
			return 0;
	}
}


void Scaler_Disp3dSetInfo(SCALER_DISP_CHANNEL channel, SLR_DISP_3D_INFO infoList, unsigned int value)
{
#ifdef CONFIG_DUAL_CHANNEL
	if ( channel > SLR_SUB_DISPLAY)
	{
		pr_debug("[disp_info] Invalid channel\n");
		return;
	}
#else //#ifdef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif //#ifdef CONFIG_DUAL_CHANNEL

	switch (infoList)
	{
		case SLR_DISP_3D_IS3DFMT:
			disp3d_info[channel].bIs3dFmt = value;
			break;
		case SLR_DISP_3D_3DTYPE:
			disp3d_info[channel].uc3dType = value;
			break;
		case SLR_DISP_3D_ENABLE_DOUBLE_DVS:
			disp3d_info[channel].bEnableDoubleDVS = value;
			break;
		case SLR_DISP_3D_3DFLOW:
			disp3d_info[channel].uc3dFlow = value;
			break;
		case SLR_DISP_3D_DISPLAY_SIZE:
			disp3d_info[channel].display_size = value;
			break;
		case SLR_DISP_3D_MAIN_ADDR:
			disp3d_info[channel].main_addr = value;
			break;
		case SLR_DISP_3D_MAIN_SEC_ADDR:
			disp3d_info[channel].main_sec_addr = value;
			break;
		case SLR_DISP_3D_MAIN_THIRD_ADDR:
			disp3d_info[channel].main_third_addr = value;
			break;
		case SLR_DISP_3D_SUB_ADDR:
			disp3d_info[channel].sub_addr = value;
			break;
		case SLR_DISP_3D_SUB_SEC_ADDR:
			disp3d_info[channel].sub_sec_addr = value;
			break;
		case SLR_DISP_3D_SUB_THIRD_ADDR:
			disp3d_info[channel].sub_third_addr = value;
			break;
		case SLR_DISP_3D_LR_SEQUENCE:
			disp3d_info[channel].ucLRsequence = value;
			break;
		case SLR_DISP_3D_IS_2D_CVT_3D:
			disp3d_info[channel].bIs2Dcvt3D = value;
			break;
		case SLR_DISP_3D_3DDEPTH:
			disp3d_info[channel].c3dDepth = value;
			break;
		case SLR_DISP_3D_2DCVT3DDEPTH:
			disp3d_info[channel].c2Dcvt3dDepth = value;
			break;
		case SLR_DISP_3D_BLKSTEP:
			disp3d_info[channel].ui3dBlkStep = value;
			break;
		case SLR_DISP_3D_H_RATIO:
			disp3d_info[channel].HRatio3d = value;
			break;
		case SLR_DISP_3D_V_RATIO:
			disp3d_info[channel].VRatio3d = value;
			break;
		case SLR_DISP_3D_MEM_WID_PRE:
			disp3d_info[channel].mem_wid_pre = value;
			break;
		case SLR_DISP_3D_MEM_LEN_PRE:
			disp3d_info[channel].mem_len_pre = value;
			break;
		default:
			pr_debug("[disp3d_info] Don't know how to set disp3d_info!!!\n");
			break;
	}

	return;
}

unsigned int Scaler_Disp3dGetInfo(SCALER_DISP_CHANNEL channel, SLR_DISP_3D_INFO infoList)
{
#ifdef CONFIG_DUAL_CHANNEL
	if ( channel > SLR_SUB_DISPLAY)
	{
		pr_debug("[disp_info] Invalid channel\n");
		return 0;
	}
#else //#ifdef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif //#ifdef CONFIG_DUAL_CHANNEL

	switch (infoList)
	{
		case SLR_DISP_3D_IS3DFMT:
			return disp3d_info[channel].bIs3dFmt;
		case SLR_DISP_3D_3DTYPE:
			return disp3d_info[channel].uc3dType;
		case SLR_DISP_3D_ENABLE_DOUBLE_DVS:
			return disp3d_info[channel].bEnableDoubleDVS;
		case SLR_DISP_3D_3DFLOW:
			return disp3d_info[channel].uc3dFlow;
		case SLR_DISP_3D_DISPLAY_SIZE:
			return disp3d_info[channel].display_size;
		case SLR_DISP_3D_MAIN_ADDR:
			return disp3d_info[channel].main_addr;
		case SLR_DISP_3D_MAIN_SEC_ADDR:
			return disp3d_info[channel].main_sec_addr;
		case SLR_DISP_3D_MAIN_THIRD_ADDR:
			return disp3d_info[channel].main_third_addr;
		case SLR_DISP_3D_SUB_ADDR:
			return disp3d_info[channel].sub_addr;
		case SLR_DISP_3D_SUB_SEC_ADDR:
			return disp3d_info[channel].sub_sec_addr;
		case SLR_DISP_3D_SUB_THIRD_ADDR:
			return disp3d_info[channel].sub_third_addr;
		case SLR_DISP_3D_LR_SEQUENCE:
			return disp3d_info[channel].ucLRsequence;
		case SLR_DISP_3D_IS_2D_CVT_3D:
			return disp3d_info[channel].bIs2Dcvt3D;
		case SLR_DISP_3D_3DDEPTH:
			return disp3d_info[channel].c3dDepth;
		case SLR_DISP_3D_2DCVT3DDEPTH:
			return disp3d_info[channel].c2Dcvt3dDepth;
		case SLR_DISP_3D_BLKSTEP:
			return disp3d_info[channel].ui3dBlkStep;
		case SLR_DISP_3D_H_RATIO:
			return disp3d_info[channel].HRatio3d;
		case SLR_DISP_3D_V_RATIO:
			return disp3d_info[channel].VRatio3d;
		case SLR_DISP_3D_MEM_WID_PRE:
			return disp3d_info[channel].mem_wid_pre;
		case SLR_DISP_3D_MEM_LEN_PRE:
			return disp3d_info[channel].mem_len_pre;
		default:
			pr_debug("[disp3d_info] Don't know how to get disp3d_info!!!\n");
			return 0;
	}
}

unsigned char Scaler_PipGetInfo(SLR_PIP_INFO infoList)
{
	switch (infoList)
	{
		case SLR_PIP_ENABLE:
			return gPipData.enable;
		case SLR_PIP_POSITION:
			return gPipData.pipPosition;
		case SLR_PIP_TYPE:
			return gPipData.type;
		case SLR_PIP_BLENDING:
			return gPipData.PipBlending;
		case SLR_PIP_SWAP:
			return gPipData.PipSwapStatus;
		case SLR_PIP_RUN:
			return gPipData.PipRunStatus;
		default:
			return 0;
	}
}

void Scaler_PipSetInfo(SLR_PIP_INFO infoList,unsigned char value)
{
	switch (infoList)
	{
		case SLR_PIP_ENABLE:
			gPipData.enable = value;
			break;
		case SLR_PIP_POSITION:
			gPipData.pipPosition = value;
			break;
		case SLR_PIP_TYPE:
			gPipData.type = value;
			break;
		case SLR_PIP_BLENDING:
			gPipData.PipBlending = value;
			break;
		case SLR_PIP_SWAP:
			gPipData.PipSwapStatus = value;
			break;
		case SLR_PIP_RUN:
			gPipData.PipRunStatus = value;
			break;
		default:
			break;
	}
	return;
}

unsigned short Scaler_PipGetSubInfo(SLR_PIP_SUB_INFO infoList)
{
	switch (infoList)
	{
		case SLR_PIP_SUB_MPENABLE:
			return SubInfo.MpEnable;
		case SLR_PIP_SUB_SUBHVCNT:
			return SubInfo.SubHVCnt;
		case SLR_PIP_SUB_MPHIIDX:
			return SubInfo.MpHiIdx;
		case SLR_PIP_SUB_MPENIDX:
			return SubInfo.MpEnIdx;
		case SLR_PIP_SUB_MPCNT:
			return SubInfo.MpCnt;
		case SLR_PIP_SUB_MPDISPLINESTEP:
			return SubInfo.MpDispLineStep;
		case SLR_PIP_SUB_MPDISPBLOCKSTEP:
			return SubInfo.MpDispBlockStep;
		default:
			return 0;
	}
}

void Scaler_PipSetSubInfo(SLR_PIP_SUB_INFO infoList, unsigned short value)
{
	switch (infoList)
	{
		case SLR_PIP_SUB_MPENABLE:
			SubInfo.MpEnable = value;
			break;
		case SLR_PIP_SUB_SUBHVCNT:
			SubInfo.SubHVCnt = value;
			break;
		case SLR_PIP_SUB_MPHIIDX:
			SubInfo.MpHiIdx = value;
			break;
		case SLR_PIP_SUB_MPENIDX:
			SubInfo.MpEnIdx = value;
			break;
		case SLR_PIP_SUB_MPCNT:
			SubInfo.MpCnt = value;
			break;
		case SLR_PIP_SUB_MPDISPLINESTEP:
			SubInfo.MpDispLineStep = value;
			break;
		case SLR_PIP_SUB_MPDISPBLOCKSTEP:
			SubInfo.MpDispBlockStep = value;
			break;

		default:
			break;
	}

}

unsigned short Scaler_DispGetStatus(SCALER_DISP_CHANNEL channel, SLR_DISP_STATUS index)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	if (index == SLR_DISP_FSYNC_VUZD) {
		return ((disp_info[channel].disp_status & index) >> 4);
	}

	if (index == SLR_DISP_COMP) {
		if ((!(disp_info[channel].disp_status & SLR_DISP_THRIP)) && (disp_info[channel].disp_status & SLR_DISP_INTERLACE) && Get_Live_zoom_mode() == LIVE_ZOOM_OFF)
			return TRUE;
		else
			return FALSE;
	}

	if (disp_info[channel].disp_status & index)
		return TRUE;
	else
		return FALSE;
}

void Scaler_DispSetStatus(SCALER_DISP_CHANNEL channel, SLR_DISP_STATUS index, unsigned short status)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	if (index == SLR_DISP_FSYNC_VUZD) {
		disp_info[channel].disp_status = (disp_info[channel].disp_status & ~(SLR_DISP_FSYNC_VUZD)) | (status<<4);
		return;
	}

	if (status == TRUE)
		disp_info[channel].disp_status |= index;
	else if ( status == FALSE )
		disp_info[channel].disp_status &= ~index;

	return;
}


unsigned short Scaler_GetDispStatusFromSource(StructDisplayInfo* p_dispinfo,  SLR_DISP_STATUS index)
{//This is for get status form each source dispinfo table

	if (index == SLR_DISP_FSYNC_VUZD) {
		return ((p_dispinfo->disp_status & index) >> 4);
	}

	if (index == SLR_DISP_COMP) {
		if ((!(p_dispinfo->disp_status & SLR_DISP_THRIP)) && (p_dispinfo->disp_status & SLR_DISP_INTERLACE))
			return TRUE;
		else
			return FALSE;
	}

	if (p_dispinfo->disp_status & index)
		return TRUE;
	else
		return FALSE;
}

void Scaler_SetDispStatusFromSource(StructDisplayInfo* p_dispinfo, SLR_DISP_STATUS index, unsigned short status)
{//This is for set status form each source dispinfo table

	if (index == SLR_DISP_FSYNC_VUZD) {
		p_dispinfo->disp_status = (p_dispinfo->disp_status & ~(SLR_DISP_FSYNC_VUZD)) | (status<<4);
		return;
	}

	if (status == TRUE)
		p_dispinfo->disp_status |= index;
	else if ( status == FALSE )
		p_dispinfo->disp_status &= ~index;

	return;
}

unsigned short Scaler_DispGetScaleStatus(SCALER_DISP_CHANNEL channel, SLR_SCALE_STATUS index)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	if (disp_info[channel].ScaleOption & index)
		return TRUE;
	else
		return FALSE;
}

void Scaler_DispSetScaleStatus(SCALER_DISP_CHANNEL channel, SLR_SCALE_STATUS index, unsigned char status)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	if (status)
		disp_info[channel].ScaleOption |= index;
	else
		disp_info[channel].ScaleOption &= (~index);

	return;
}

void Scaler_VGASetClockStatus(SCALER_DISP_CHANNEL channel, unsigned char status)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	disp_info[channel].vga_clock_setting = status;

	return;
}

unsigned char Scaler_VGAGetClockStatus(SCALER_DISP_CHANNEL channel)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	return disp_info[channel].vga_clock_setting;
}

#if 0
SLR_RATIO_TYPE Scaler_GetPreRatio_smoothtoggle(void)
{
	return ratio_type_pre;
}
void Scaler_SetPreRatio_smoothtoggle(SLR_RATIO_TYPE ratio)
{
	ratio_type_pre=ratio;
}
RATIO_TYPE_STATE Scaler_Getratiostate_smoothtoggle(void)
{
	return ratiotype_state;
}
void Scaler_Setratiostate_smoothtoggle(RATIO_TYPE_STATE state)
{
	ratiotype_state=state;
}
#endif
void Scaler_DispSetRatioMode(SLR_RATIO_TYPE ratio)
{
#if 0
	if(Get_vo_smoothtoggle_changeratio_flag()||Get_vo_smoothtoggle_timingchange_flag())
	{
		Scaler_SetPreRatio_smoothtoggle(currZoomMode);
		Scaler_Setratiostate_smoothtoggle(RT_STATE_CHANGE);
	}
#endif
	//printk("Set Ratio=%d\n", ratio);
	pre_currZoomMode = currZoomMode;
	currZoomMode = ratio;
	return;
}

#if defined (TV003_ADTV)
bool Scaler_GetIsUserSetRatio(void)
{
	return m_isUserSetRatio;
}
void  Scaler_SetIsUserSetRatio(bool isUser)
{
	m_isUserSetRatio = isUser;
}
#endif

SLR_RATIO_TYPE Scaler_DispGetRatioMode(void)
{

  // 4k2k photo mode ratio type only support 16:9
  #if defined (ENABLE_QUADFHD)
        if((Scaler_InputSrcGetMainChType() == _SRC_VO) && Scaler_VOFromJPEG(Scaler_Get_CurVoInfo_plane())){
            //printk("%s line:%d 4k2k photo mode need to return 16:9 ratio\n", __FILE__, __LINE__);
            return SLR_RATIO_16_9;
        }
    #ifdef ENABLE_HDMI_DMA_FOR_4K2K
        if(Scaler_GetHdmiDmaCapture_Enable() && (Scaler_GetHdmiDmaCapture_Status() >= HDMI_DMA_4K2K_STATE_DMA_ENABLE)){
            //printk("%s line:%d Hdmi 4k2k need to return 16:9 ratio\n", __FILE__, __LINE__);
            return SLR_RATIO_16_9;
        }
    #endif
  #endif

	if((Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))==SLR_3DMODE_2D_CVT_3D)  && (currZoomMode == SLR_RATIO_POINTTOPOINT))
		return (SLR_RATIO_TYPE)currZoomMode;


	//printk("Mode=%d, Ratio 3D/Cur[%d/%d]\n", Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)), m_3dRatio, currZoomMode);
	if (m_3dRatio == SLR_RATIO_AUTO) // don't care if 3d mode
		return (SLR_RATIO_TYPE)currZoomMode;


	if ((Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))==SLR_3DMODE_2D) || ((Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) >= SLR_3DMODE_3D_AUTO_CVT_2D) && (Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) <= SLR_3DMODE_3D_SENSIO_CVT_2D))) {
		return (SLR_RATIO_TYPE)currZoomMode;
	} else {
		return (SLR_RATIO_TYPE) m_3dRatio; //SLR_RATIO_16_9;
	}

}

SLR_RATIO_TYPE Scaler_DispGetPreRatioMode(void)
{
	return pre_currZoomMode;
}

SLR_RATIO_TYPE Scaler_DispGetRatioMode2(void) // added by hsliao 20090318, ratio mode is original or auto decided
{
	SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode();


	if (ratio_type == SLR_RATIO_BBY_AUTO) {
		if (Get_DISPLAY_RATIO_4X3() == 1) { // 4:3 panel
			ratio_type = SLR_RATIO_BBY_NORMAL; // use NORMAL zoom mode
		} else { // 16:9 panel
#ifdef CONFIG_DTV_AFD_CONTROL
			if(Scaler_InputSrcGetMainChType()==_SRC_VO||Scaler_InputSrcGetMainChType()==_SRC_CVBS)
				return SLR_RATIO_BBY_AUTO;
#endif
			if (Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO)) { // 4:3 content
				ratio_type = SLR_RATIO_BBY_NORMAL; // use NORMAL zoom mode
			} else { // 16:9 content
				ratio_type = SLR_RATIO_BBY_WIDE_1; // use WIDE1 zoom mode
			}
		}
	}


	return ratio_type;
}

unsigned char Scaler_DispCheckRatio(SLR_RATIO_TYPE ratio)
{
	if (currZoomMode == ratio)
		return TRUE;
	else
		return FALSE;
}
void Scaler_AdaptiveStream_NewInputRegionFlagSet(unsigned char display,unsigned char bEnable)
{
	bNewInputRegionFlag[display] = bEnable;
}
unsigned char Scaler_AdaptiveStream_NewInputRegionFlagGet(unsigned char display)
{
	return bNewInputRegionFlag[display];
}

void Scaler_AdaptiveStream_InputWindowSet(StructSrcRect m_inputwin)
{
	adaptivestream_inputwin = m_inputwin;
	return;
}

StructSrcRect Scaler_AdaptiveStream_InputWindowGet(void)
{
	if((adaptivestream_inputwin.src_height == 0) ||(adaptivestream_inputwin.src_wid == 0)){
		//adaptivestream_inputwin.src_height =  Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_LEN_PRE);
		//adaptivestream_inputwin.src_wid =  Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_WID_PRE);
		adaptivestream_inputwin = Scaler_DispWindowGet();//don't overscan
	}
	return (StructSrcRect)adaptivestream_inputwin;
}

void Scaler_OSD4k2kSet(unsigned char m_osd4k2k)
{
	custom_osd4k2k = m_osd4k2k;
	return;
}



void Scaler_DispWindowSet(StructSrcRect m_dispwin)
{
	//printk("@@@@@@@@@@@@@@@@@@[%s]m_dispwin.wid:%x, m_dispwin.height:%x\n", __FUNCTION__, m_dispwin.src_wid, m_dispwin.src_height);
	if (Get_PANEL_VFLIP_ENABLE()){
		if (Get_DISP_ACT_END_VPOS()>=(m_dispwin.srcy+m_dispwin.src_height))
			m_dispwin.srcy=Get_DISP_ACT_END_VPOS()-(m_dispwin.srcy+m_dispwin.src_height);
		else
			m_dispwin.srcy=0;
	}

	if((Get_DISP_ACT_END_HPOS() - Get_DISP_ACT_STA_HPOS()) == 3840){//4k2k panel
		if((m_dispwin.src_wid%4)>0){
			m_dispwin.src_wid = (m_dispwin.src_wid&(~3))+4;
		}
	}else{
		if(custom_osd4k2k){
			m_dispwin.srcx /=2;
			m_dispwin.srcy /=2;
			m_dispwin.src_wid /=2;
			m_dispwin.src_height /=2;
		}
		if((m_dispwin.src_wid%2)>0){
			m_dispwin.src_wid = (m_dispwin.src_wid & (~1))+2;
		}
	}

	custom_dispwin= m_dispwin;


#if 0//#ifdef CONFIG_MEMC_BYPASS

	if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE)==0) // 60hz panel do nothing
	{
		//custom_dispwin.src_wid = _DISP_WID/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
	}
	else
		custom_dispwin.src_wid = _DISP_WID/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
#endif

	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES()){
		output_2k1k_timing = Get_DISPLAY_2k1k_output_mode_status();
	}

	//printk("@@@@@@@@@@@@@@@@@@[%s]src_wid:%x, src_height:%x\n", __FUNCTION__, custom_dispwin.src_wid, custom_dispwin.src_height);
	return;
}

StructSrcRect Scaler_DispWindowGet(void)
{
	//frank@0429 avoid display window not be set
	if((custom_dispwin.src_height == 0) ||(custom_dispwin.src_wid == 0)){
#if 0//#ifdef CONFIG_MEMC_BYPASS
		custom_dispwin.src_wid = _DISP_WID/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
#else
		custom_dispwin.src_height = _DISP_LEN;
		custom_dispwin.src_wid = _DISP_WID;
#endif
	}

	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES()){
		pr_debug("output_2k1k_timing:%d, Get_DISPLAY_2k1k_output_mode_status() : %d \n", output_2k1k_timing, Get_DISPLAY_2k1k_output_mode_status());
		if(output_2k1k_timing != Get_DISPLAY_2k1k_output_mode_status()){
			if(Get_DISPLAY_2k1k_output_mode_status() == 0){
				pr_debug("Scaler_DispWindowGet: By2\n");
				custom_dispwin.srcx *= 2;
				custom_dispwin.srcy *= 2;
				custom_dispwin.src_height*= 2;
				custom_dispwin.src_wid*= 2;
				output_2k1k_timing = 0;
			}else{
				pr_debug("Scaler_DispWindowGet : Divide 2\n");
				custom_dispwin.srcx /= 2;
				custom_dispwin.srcy /= 2;
				custom_dispwin.src_height/= 2;
				custom_dispwin.src_wid/= 2;
				output_2k1k_timing = 1;
			}
		}
	}

	return (StructSrcRect)custom_dispwin;
}

void Scaler_DispWindowSet_source(StructSrcRect m_dispwin)
{
	//printk("@@@@@@@@@@@@@@@@@@[%s]m_dispwin.wid:%x, m_dispwin.height:%x\n", __FUNCTION__, m_dispwin.src_wid, m_dispwin.src_height);

	if (Get_PANEL_VFLIP_ENABLE()){
		if (Get_DISP_ACT_END_VPOS()>=(m_dispwin.srcy+m_dispwin.src_height))
			m_dispwin.srcy=Get_DISP_ACT_END_VPOS()-(m_dispwin.srcy+m_dispwin.src_height);
		else
			m_dispwin.srcy=0;
	}

	if((Get_DISP_ACT_END_HPOS() - Get_DISP_ACT_STA_HPOS()) == 3840){//4k2k panel
		//frank@05292013 align to 4,because source will scale up to m_dispwin.src_wid/2
		if((m_dispwin.src_wid%4)>0){
			m_dispwin.src_wid = (m_dispwin.src_wid&(~3))+4;
		}
	}else{
		if(custom_osd4k2k){
			m_dispwin.srcx /=2;
			m_dispwin.srcy /=2;
			m_dispwin.src_wid /=2;
			m_dispwin.src_height /=2;
		}
		if((m_dispwin.src_wid%2)>0){
			m_dispwin.src_wid = (m_dispwin.src_wid & (~1))+2;
		}
	}

	custom_source_dispwin= m_dispwin;


	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES()){
		output_2k1k_timing = Get_DISPLAY_2k1k_output_mode_status();
	}

	//printk("@@@@@@@@@@@@@@@[%s]src_wid:%x, src_height:%x\n", __FUNCTION__, custom_dispwin.src_wid, custom_dispwin.src_height);
	return;
}

StructSrcRect Scaler_DispWindowGet_source(void)
{
	//frank@0429 avoid display window not be set
	if((custom_source_dispwin.src_height == 0) ||(custom_source_dispwin.src_wid == 0)){
		custom_source_dispwin.src_height = _DISP_LEN;
		custom_source_dispwin.src_wid = _DISP_WID;
	}

	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES()){
		if(output_2k1k_timing != Get_DISPLAY_2k1k_output_mode_status()){
			if(Get_DISPLAY_2k1k_output_mode_status() == 0){
				pr_debug("Scaler_DispWindowGet: By2\n");
				custom_dispwin.srcx *= 2;
				custom_dispwin.srcy *= 2;
				custom_dispwin.src_height*= 2;
				custom_dispwin.src_wid*= 2;
				output_2k1k_timing = 1;
			}else{
				pr_debug("Scaler_DispWindowGet : Divide 2\n");
				custom_dispwin.srcx /= 2;
				custom_dispwin.srcy /= 2;
				custom_dispwin.src_height/= 2;
				custom_dispwin.src_wid/= 2;
				output_2k1k_timing = 0;
			}

		}
	}

	return (StructSrcRect)custom_source_dispwin;

}

unsigned char Scaler_DispGetIvs2DvsDelay(void)
{
	return ucIVS2DVSDelay;
}

void Scaler_DispSetIvs2DvsDelay(unsigned char value)
{
	ucIVS2DVSDelay = value;
	return;
}

unsigned char Scaler_DispGetIhsDelay(void)
{
	return ucIHSDelay;
}

void Scaler_DispSetIhsDelay(unsigned char value)
{
	ucIHSDelay = value;
	return;
}


unsigned char Scaler_DispGetVgaIVS2DVSDelay(void)
{
	return IVS2DVSDelay_VGA;
}

void Scaler_DispSetVgaIVS2DVSDelay(unsigned char value)
{
	IVS2DVSDelay_VGA = value;
	return;
}


unsigned char Scaler_DispGetIpMargin(SLR_IPMARGIN_TYPE type)
{
	switch (type)
	{
		case SLR_IPMARGIN_H_MAX:
			return ucIPH_Max_Margin;
		case SLR_IPMARGIN_H_MIN:
			return ucIPH_Min_Margin;
		case SLR_IPMARGIN_V_MAX:
			return ucIPV_Max_Margin;
		case SLR_IPMARGIN_V_MIN:
			return ucIPV_Min_Margin;
		default:
			return 0;
	}
}

void Scaler_DispSetIpMargin(SLR_IPMARGIN_TYPE type, unsigned char value)
{
	switch (type)
	{
		case SLR_IPMARGIN_H_MAX:
			ucIPH_Max_Margin = value;
			break;
		case SLR_IPMARGIN_H_MIN:
			ucIPH_Min_Margin = value;
			break;
		case SLR_IPMARGIN_V_MAX:
			ucIPV_Max_Margin = value;
			break;
		case SLR_IPMARGIN_V_MIN:
			ucIPV_Min_Margin = value;
			break;
		default:
			break;
	}

	return;
}

#ifdef CONFIG_ENABLE_3D_SETTING
/**
   get status of b3DEnablable

   @param <enableTvScan>   { ENABLE/DISABLE }
   @return                  { true/false }
    add by josh@2008/10/21
*/
unsigned char Scaler_Get3DEnable(void)
{
	return b3DEnablable;
}

/**
   Set status of b3DEnablable

   @param <enableTvScan>   { ENABLE/DISABLE }
   @return                  { true/false }
    add by josh@2008/10/21
*/
unsigned char Scaler_Set3DEnable(unsigned char enable)
{
	int ret;
	b3DEnablable = enable;


	// copy to RPC share memory
	//if (Scaler_IsUnitTest()== FALSE)
	memcpy((unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_SETADAPTIVE3D), &b3DEnablable, sizeof(unsigned char));

	if ((ret = Scaler_SendRPC(SCALERIOC_SETADAPTIVE3D, 0, 0)) <0)
	{
		pr_debug("ret=%d, set b3DEnablable flag to driver fail !!!\n", ret);
		return FALSE;
	}

	///}


	return TRUE;
}
#endif

void Scaler_SetHDMIDiditalMeasureIVH(unsigned short value)
{
	HDMIDiditalMeasureIVH = value;
}

/**
   Set status of adaptive_3d_en

   @param <enableTvScan>   { ENABLE/DISABLE }
   @return                  { true/false }
    add by josh@2008/10/21
*/
unsigned short Scaler_GeHDMIDiditalMeasureIVH(void)
{
	return HDMIDiditalMeasureIVH;
}

unsigned char Scaler_GetTvBlueScreen(void)
{
	return m_TvBlueScreen;
}

void Scaler_SetTvBlueScreen(unsigned char status)
{
	m_TvBlueScreen = status;
}

void Scaler_SetCurrentDispInfo(SCALER_DISP_CHANNEL channel)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	info = & disp_info[channel];
}

void Scaler_SetUserInputSrc(SCALER_DISP_CHANNEL channel,unsigned char index)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	InputSource[channel] = index;
}

unsigned char Scaler_GetUserInputSrc(SCALER_DISP_CHANNEL channel)
{
// frank@1017 add below code to solve scan tool warning
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	return InputSource[channel];
}

void Scaler_SetVoVersion(unsigned int version)
{
	VoVersion++;
}

unsigned int Scaler_GetVoVersion(void)
{
	// new display ready version control
	return VoVersion;
}

#if 0
// new MV ready version control
void Scaler_SetMvRdyVersion(unsigned int version)
{
	mvRdyVersion = version;
}

unsigned int Scaler_GetMvRdyVersion(void)
{
	return mvRdyVersion;
}
#endif
// new VO ready version control
void Scaler_SetVoRdyVersion(void)
{
	g_ulVoRdyVersion = Scaler_GetVoVersion();

	//printk("Scaler_SetVoRdyVersion  g_ulVoRdyVersion=%d\n", g_ulVoRdyVersion);
}

void Scaler_SetVoRdyVersionManual(UINT32 a_ulVersion)
{
	g_ulVoRdyVersion = a_ulVersion;
}


unsigned int Scaler_GetVoRdyVersion(void)
{
	return g_ulVoRdyVersion;

	//printk("Scaler_GetVoRdyVersion  g_ulVoRdyVersion=%d\n", g_ulVoRdyVersion);
}

unsigned int Scaler_SendDisplayReadyIrc(VO_VIDEO_PLANE plane)
{
	int ret = 0;
	unsigned char ack = 0;

/*fix me@frankcheng	int ret, ack;

	if ((ret = ioctl(Scaler_GetDev(), SCALERIOC_SEND_DISP_READY_IRC, &ack)) < 0) {
		printk("ret=%d, set Display Ready IRC to ROS fail !!!\n", ret);
		return FALSE;
	}*/


	// copy to RPC share memory
	memcpy((unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_SEND_DISP_READY_IRC), &ack, sizeof(unsigned char));
	if ((ret = Scaler_SendRPC(SCALERIOC_SEND_DISP_READY_IRC,plane,1)) <0)
	{
		pr_debug("ret=%d, set Display Ready IRC to ROS fail !!!\n", ret);
		return FALSE;
	}

	return TRUE;
}

unsigned char Scaler_GetSourceListLen(void)
{
	return slrSourceMax;
}

static VO_VIDEO_PLANE curVoPlane=VO_VIDEO_PLANE_V1;
void Scaler_Set_CurVoInfo_plane(VO_VIDEO_PLANE plane)
{
	if(curVoPlane != plane)
		pr_debug("%s=%d\n", __FUNCTION__, plane);

	curVoPlane = plane;
	return;
}

unsigned char Scaler_Get_CurVoInfo_plane(void)
{
#if 0
	return curVoPlane;
#else
	unsigned char port = Get_DisplayMode_Port(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));

    return port;
#endif
}

VO_VIDEO_PLANE Scaler_Get_CurVoInfo_VoVideoPlane(unsigned char display)
{
	unsigned char port = Get_DisplayMode_Port(display);

    return vo_info[port].plane;
}

SLR_VOINFO* Scaler_VOInfoPointer(unsigned char port)
{
	return &vo_info[port];
}


SLR_VOINFO *Scaler_PreVOInfoPointer(unsigned char plane)
{
	return &pre_vo_info[plane];
}


void Scaler_SetVOFromJPG(unsigned char plane)//For jpeg flow : im config usage
{
	vo_info[plane].source = 1;	// 0) DTV, 1) JPEG, 2)GAME
}

unsigned char Scaler_VOFrom(unsigned char plane)
{
	return vo_info[plane].source;	// 0) DTV, 1) JPEG, 2)GAME
}

unsigned char Scaler_VOFromVDEC(unsigned char plane)
{
	return vo_info[plane].vdec_source;
}

unsigned char Scaler_VOFromJPEG(unsigned char plane)
{
	return vo_info[plane].isJPEG;	// 0) DTV, 1) JPEG
}

void Scaler_UpdateVOInfo(unsigned char plane)
{
    memcpy(&vo_info[plane], (unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_GETVOINFO), sizeof(SLR_VOINFO));
}

void Scaler_ClearVOInfo(unsigned char port)
{    
    memset(&vo_info[port],0,sizeof(SLR_VOINFO));
}

// new display ready version control
#ifdef ENABLE_DISPLAY_READY_VERSION_CONTROL
#warning "ENABLE_DISPLAY_READY_VERSION_CONTROL"
  unsigned char Scaler_GetCurPlayVideoIndexValidation(void)
  {
  	return gDispIndex.validFlag;
  }

  unsigned int Scaler_GetCurPlayVideoIndex(void)
  {
  	if(gDispIndex.validFlag)
  		return gDispIndex.playIndex;
	else
		return 0;
  }

#else
  unsigned char Scaler_GetCurPlayVideoIndexValidation(void)
 {
 	return TRUE;
 }
  unsigned int Scaler_GetCurPlayVideoIndex(void)
  {
  	return 0;
  }
#endif

#ifdef ENABLE_VO_READY_VERSION_CHECK // new MV ready version control
#warning "ENABLE_VO_READY_VERSION_CHECK IS ENABLED"
  unsigned char Scaler_CheckLatestNewVoInfo(unsigned int ver_vo)
  {
	SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());

	// display version check only for DTV/FP mode, not for JPEG
	if(pVOInfo->source != 0)
		return TRUE;

	if((ver_vo != 0) && (ver_vo == Scaler_GetCurPlayVideoIndex()))
		return TRUE;
	else
		return FALSE;
  }
#else
  unsigned char Scaler_CheckLatestNewVoInfo(unsigned int ver_vo)
  {
  	if (ver_vo == Scaler_GetVoVersion())
  	return TRUE;
	else
	{
		return FALSE;
	}
  }
#endif

  unsigned char Scaler_IsLatestDisplayReady(unsigned int data)
  {
	if(Scaler_CheckLatestNewVoInfo(data))
  		return TRUE;
	else
		return FALSE;
  }

#if 0 //FixedME clamp Mac3
void Scaler_SetChangeChannelMode(unsigned char mode)
{
//	unsigned char sourceType;

	// new display ready version control
	// [DTV/FP] display ready version control for VO source DTV/FP mode only
	SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());

	gDispIndex.validFlag = mode;
	if(mode == TRUE){
		gDispIndex.playIndex++;
		if(gDispIndex.playIndex == 0)
			gDispIndex.playIndex = 1;
	}
	printk("[SLR][%d]Valid/Idx[%d/%d]\n", (int)pVOInfo->source, mode, gDispIndex.playIndex);

	m_ChangeChannelEnable = mode;
}

unsigned char Scaler_GetChangeChannelMode(void)
{
	return m_ChangeChannelEnable;
}
#endif

//USER:LewisLee DATE:2012/06/12
void Scaler_SetATVChangeChannelFlag(UINT8 ucFlag)
{
	m_AtvDuringChangeChannel_Flag = ucFlag;
}

UINT8 Scaler_GetATVChangeChannelFlag(void)
{
	return m_AtvDuringChangeChannel_Flag;
}


void Scaler_SetPreATVCheckFailFlag(unsigned char flag)
{
	m_isPrevCheckFail = flag;
}

unsigned char Scaler_GetPreATVCheckFailFlag(void)
{
	return m_isPrevCheckFail;
}

void Scaler_Set_Vo_Timing_Equal(unsigned char option)
{
	vo_timing_equal = option;
}


unsigned char Scaler_GET_Vo_Timing_Equal(void)
{
	return vo_timing_equal;
}

unsigned char Scaler_DO_VO_timing_Equal(VO_VIDEO_PLANE plane)
{
	int ret = 0;
	unsigned int i = 0, ulVOInfoItemCount = 0;
	unsigned int *pulTemp;
	unsigned int voPlane=0;

	// force to re-start mode detect flow in jpeg source or when 2D3D conversion mode is enabled
	// let 2d3dcvt do equal timing decesion by jiunyu 20110725
	/*
	if((Scaler_VOFrom(Scaler_Get_CurVoInfo_plane())==1)|| (Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE() && scaler_2Dcvt3D_get_curMode())){
		vo_timing_equal = FALSE;
		return vo_timing_equal;
	}
	*/
	SLR_VOINFO *pPreVoInfo = Scaler_PreVOInfoPointer(plane);
	SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(plane);
	pulTemp = (unsigned int *)pVOInfo;


#if 0  //fixme
	voPlane = ((Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == TRUE) && (plane == VO_VIDEO_PLANE_V1)? Scaler_Get_3D_VoPlane(): Scaler_Get_2D_VoPlane());
#else
	voPlane =plane;
#endif
	if ((ret = Scaler_SendRPC(SCALERIOC_GETVOINFO, voPlane, 1)) < 0)
	{
		pr_debug("ret=%d, get SCALERIOC_GETVOINFOl from driver fail@%s !!!\n", ret, __FUNCTION__);
	}
	// copy from RPC share memory
	memcpy(pVOInfo, (unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_GETVOINFO), sizeof(SLR_VOINFO));

	ulVOInfoItemCount = sizeof(SLR_VOINFO) /  sizeof(UINT32);
	// change endian
	for (i = 0; i < ulVOInfoItemCount; i++)
		pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);

	if (memcmp(pPreVoInfo, pVOInfo, sizeof(SLR_VOINFO)- (sizeof(SLR_AFD_TYPE) + (sizeof(unsigned int)*4))) == 0) //don't compare voinfo AFD, PixelAR and launcher
	{
		vo_timing_equal = TRUE;
	}else if(Scaler_DispGetRatioMode2() == SLR_RATIO_BBY_AUTO){
		if((memcmp(pPreVoInfo, pVOInfo,((unsigned int)&(pVOInfo->afd)-(unsigned int)&(pVOInfo->mode))) == 0) && (!Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))) //only compare input timing not afd/hv ratio
		{
			if(((pVOInfo->pixelAR_hor != pPreVoInfo->pixelAR_hor) ||(pVOInfo->pixelAR_ver != pPreVoInfo->pixelAR_ver))&&(pVOInfo->afd == pPreVoInfo->afd)){
				scalerdisplay_vo_ratio_change(plane);
				memcpy(pPreVoInfo, pVOInfo, sizeof(SLR_VOINFO));
				vo_timing_equal = TRUE;
			}else{
				vo_timing_equal = FALSE;
			}
		}
	else
		{
		vo_timing_equal = FALSE;
		}
	}

	return vo_timing_equal;
}


unsigned char Scaler_GetRoiInfo(SCALER_DISP_CHANNEL channel, int* resolution, int* videoWidth, int* videoHeight, unsigned char* isInterlace, int* freq)
{
	int mode, srcType, srcFrom, res=0, width=0, height=0, isI=0, hz=0, ivFreq=0;
	int tempHz = 0;

	switch (Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_STATE)) {
		case _MODE_STATE_SEARCH:
		case _MODE_STATE_NONE:
			pr_debug("Scaler_GetRoiInfo %d\n", Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_STATE));
			return FALSE;
	}

#ifdef ENABLE_DRIVER_I3DDMA

// FixMe, 20140928
#if 1
	if(drvif_scaler3d_get_IDMA3dMode() != SLR_IDMA_MODE_DISABLE){
		I3DDMA_TIMING_T *i3ddma_timing = (I3DDMA_TIMING_T*)drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_TIMING);

		srcType = drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_SRC_TYPE);
		srcFrom = drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_SRC_FROM);
		mode = drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_MODE_CURR);
		if(i3ddma_timing){
			isI = !i3ddma_timing->progressive;
			width = i3ddma_timing->h_act_len;
			height = i3ddma_timing->v_act_len;
			ivFreq = i3ddma_timing->v_freq;
			// monitor always show 72.8xx as 72Hz
			tempHz = (i3ddma_timing->v_freq + 5) / 10;
		}
	}else
#endif


#endif
	{
		srcType = Scaler_InputSrcGetType(channel);
		srcFrom = Scaler_InputSrcGetFrom(channel);
		isI = Scaler_DispGetStatus(channel, SLR_DISP_INTERLACE);
		width = disp_info[channel].IPH_ACT_WID_PRE;
		height = disp_info[channel].IPV_ACT_LEN_PRE;
		ivFreq = disp_info[channel].IVFreq;
		// monitor always show 72.8xx as 72Hz
		tempHz = (ivFreq + 5) / 10;

		mode = (int)Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_MODE_CURR);
	}

	// FixMe, 20140928
	pr_debug("Scaler_GetRoiInfo I3D[%d], mode/wid/len/vFreq=%d/%d/%d/%d\n", drvif_scaler3d_get_IDMA3dMode(), mode, width, height, ivFreq);

	#if defined(TV032_1) || defined (TV014_1) || (defined TV014_2)//Added by Kangwei 2012-07-28-20:50
	if (ABS(ivFreq, 728) < 8) {
			if(tempHz>72)
			tempHz--;
	}
	#else
	if (ABS(ivFreq, 728) <= 3) {
			tempHz--;
	}
	#endif
	switch (srcType) {
		case _SRC_HDMI:
			if (drvif_IsHDMI()) {
				pr_debug("Scaler_GetRoiInfo IsHDMI = 1\n");

				switch (mode) {
					case _MODE_480I:
                #if (defined BUILD_TV015_1_ATV)||(defined BUILD_TV020_1_ATV)||(defined BUILD_TV011_1_ATV)
                    case _MODE_480I_DH:
                #endif
						res = 480;
						break;
					case _MODE_576I:
                #if (defined BUILD_TV015_1_ATV)||(defined BUILD_TV020_1_ATV) ||(defined BUILD_TV011_1_ATV)
                    case _MODE_576I_DH:
                #endif
						res = 576;
						break;
					case _MODE_480P:
						res = 480;
						break;
					case _MODE_576P:
						res = 576;
						break;
					case _MODE_720P50:
						res = 720;
						hz = 50;
						break;
					case _MODE_720P60:
						res = 720;
						hz = 60;
						break;
#if (defined BUILD_TV005_1_ISDB)
					case _MODE_720P24:
						res = 720;
						hz = 24;
						break;
					case _MODE_720P30:
						res = 720;
						hz = 30;
						break;
#endif
					case _MODE_1080I25:
						res = 1080;
						hz = 50;
						break;
					case _MODE_1080I30:
						res = 1080;
						hz = 60;
						break;
					case _MODE_1080P50:
						res = 1080;
						hz = 50;
						break;
					case _MODE_1080P60:
						res = 1080;
						hz = 60;
						break;
					case _MODE_1080P23:
					case _MODE_1080P24:
						res = 1080;
						hz = 24;
						break;
					case _MODE_1080P25:
						res = 1080;
						hz = 25;
						break;
					case _MODE_1080P29:
					case _MODE_1080P30:
						res = 1080;
						hz = 30;
						break;
					case _MODE_1080PM50:
						res = 1080;
						hz = 50;
						break;
					case _MODE_1080PM60:
						res = 1080;
						hz = 60;
						break;
					default:
						break;
				}
				if (res != 0)
					break;
			}
			else
				pr_debug("Scaler_GetRoiInfo IsHDMI = 0, current DVI mode\n");

				if((ivFreq<=610)&&(ivFreq>=590))
					hz=60;
				else
					hz = tempHz;

				if (isI)
					height = height * 2;
			break;

		case _SRC_VGA:
			hz = tempHz;

			//special timing
			switch(mode){
				case _MODE_VGA_480I:
				case _MODE_VGA_576I:
				case _MODE_VGA_1080I25:
				case _MODE_VGA_1080I30:
					height *=2;
					break;
				default:
					break;
			}

			break;

		case _SRC_YPBPR:
			switch (mode) {
				case _MODE_480I:
					res = 480;
					break;
				case _MODE_576I:
					res = 576;
					break;
				case _MODE_480P:
					res = 480;
					break;
				case _MODE_576P:
					res = 576;
					break;
				case _MODE_720P50:
					res = 720;
					hz = 50;
					break;
				case _MODE_720P60:
					res = 720;
					hz = 60;
					break;
				case _MODE_1080I25:
					res = 1080;
					hz = 50;
					break;
				case _MODE_1080I30:
					res = 1080;
					hz = 60;
					break;
				case _MODE_1080P50:
					res = 1080;
					hz = 50;
					break;
				case _MODE_1080P60:
					res = 1080;
					hz = 60;
					break;
				case _MODE_1080P23:
				case _MODE_1080P24:
					res = 1080;
					hz = 24;
					break;
				case _MODE_1080P25:
					res = 1080;
					hz = 25;
					break;
				case _MODE_1080P29:
				case _MODE_1080P30:
					res = 1080;
					hz = 30;
					break;
				case _MODE_1080PM50:
					res = 1080;
					hz = 50;
					break;
				case _MODE_1080PM60:
					res = 1080;
					hz = 60;
					break;
				default:
					break;
			}
			if (res != 0)
				break;

				//avoid unknown mode
				hz = tempHz;
				if (isI)
					height = height * 2;
			break;

		case _SRC_TV:
		case _SRC_CVBS:
		case _SRC_SV:
		case _SRC_SCART:
		case _SRC_SCART_RGB:
			if (srcFrom != _SRC_FROM_VDC)
				break;

			if (mode == _MODE_480I) {
				res = 480;
				isI = TRUE;
			}
			else if (mode == _MODE_576I) {
				res = 576;
				isI = TRUE;
			}
			else {
				res = 480;
				isI = TRUE;
			}
			break;

		default:
			break;
	}

	pr_debug("Scaler_GetRoiInfo hz = %d\n", hz);

	if (resolution != NULL)
		*resolution = res;
	if (videoWidth != NULL)
		*videoWidth = width;
	if (videoHeight != NULL)
		*videoHeight = height;
	if (isInterlace != NULL)
		*isInterlace = isI;
	if (freq != NULL)
		*freq = hz;

	return TRUE;
}


#if defined (TV003_ADTV)
bool Scaler_GetIsHD(void) //peterpan1017,20130228: Get timing is SD ro HD
{
	int resolution = 0;
	return FALSE; // temp all timing save to same memory
	if (Scaler_GetRoiInfo(SLR_MAIN_DISPLAY, &resolution, NULL, NULL, NULL, NULL))
	{
		if(resolution>=720) return TRUE;
		else return FALSE;
	}
	return FALSE;
}

bool Scaler_GetTimingIsHD(void) //peterpan1017,20130301: Get timing is SD ro HD
{

	switch(Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR))
	{
		case _MODE_720x480_60HZ:
		case _MODE_640x480_50HZ:
		case _MODE_640x480_60HZ:
		case _MODE_640x480_67HZ:
		case _MODE_640x480_70HZ:
		case _MODE_640x480_72HZ:
		case _MODE_640x480_75HZ:
		case _MODE_480I:
		case _MODE_480P:
		case _MODE_576I:
		case _MODE_576P:
		//case _MODE_1440_576P:
		//case _MODE_1440_480P:
			//printk("\033[1;31m ##### %s%d %s\033[m\n",__FILE__, __LINE__,__FUNCTION__ );
			return FALSE;
		case _MODE_720P50:
		case _MODE_720P60:
		case _MODE_1080I25:
		case _MODE_1080I30:
		case _MODE_1080P50:
		case _MODE_1080P60:
		case _MODE_1080P23:
		case _MODE_1080P24:
		case _MODE_1080P25:
		case _MODE_1080P29:
		case _MODE_1080P30:
		case _MODE_1080PM50:
		case _MODE_1080PM60:
			//printk("\033[1;34m ##### %s%d %s\033[m\n",__FILE__, __LINE__,__FUNCTION__ );
			return TRUE;
		default:
			pr_debug("\033[1;31m [not Modestate Timing] %s%d %s\033[m\n",__FILE__, __LINE__,__FUNCTION__ );
			if(Scaler_InputSrcGetMainChType()==_SRC_VO){
				SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
				if(pVOInfo->v_length>=720)return TRUE;
			}else{
				if(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)>=720)return TRUE;
			}
			return FALSE;
	}
	return FALSE;

}
#endif

unsigned char Scaler_CheckDviMode(void)
{
	if (drvif_IsHDMI() == MODE_HDMI)
		return FALSE;
	else
		return TRUE;
}


unsigned int Scaler_GetRPCSrcInfoSize(void)
{//fixme
	return 	(sizeof(unsigned short)*((unsigned int)slrSourceMax+1));
}


void Scaler_Set3DRatioMode(SLR_RATIO_TYPE ratio3d)
{
	m_3dRatio = ratio3d;
}


#ifdef ENABLE_MHEG5
static SLR_IFRAME_MODE __IframeMode=SLR_IFRAME_NONE;
static SLR_MHEG5_SCENE_ASPECT_RATIO __mheg5SceneAspectRatio=SLR_MHEG5_SCENE_ASPECT_NONE;
static SLR_MHEG5_ALIGNMENT __mheg5Alignment=SLR_MHEG5_ALIGNMENT_NONE;
static StructOverscanInfo __overscanInfo={0,0,0,0};
void Scaler_SetIframeMode(SLR_IFRAME_MODE mode)
{
	SLR_IFRAME_MODE preIframeMode=__IframeMode;
	if(__IframeMode != mode)
	{
		__IframeMode = mode;
		if(preIframeMode != SLR_IFRAME_NONE )
		{
			//Scaler_SetLastDtvChChangeIgnoreFlag(TRUE);
		}
	}
}
SLR_IFRAME_MODE Scaler_GetIframeMode(void)
{
    return __IframeMode;
}

void Scaler_GetAfdAndRatio(VO_VIDEO_PLANE plane, SLR_AFD_TYPE* afd, SLR_SOURCERATIO_TYPE* ratio)
{
    *afd=vo_info[plane].afd;
    *ratio=(SLR_SOURCERATIO_TYPE)vo_info[plane].i_ratio;
}
void Scaler_SetMheg5SceneAspectRatio(SLR_MHEG5_SCENE_ASPECT_RATIO ratio)
{
    unsigned short dispLen, dispWid;

	if(__mheg5SceneAspectRatio!=ratio)
	{
		__mheg5SceneAspectRatio=ratio;
		//Scaler_SetLastDtvChChangeIgnoreFlag(TRUE);
		dispLen =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN);
		dispWid =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID);
        if ((dispWid*3) <= (4*dispLen))
        {
            // 4:3 display must set to 16x9
            if (ratio == SLR_MHEG5_SCENE_ASPECT_16X9)
            {
                Scaler_ChangeRatio(Scaler_DispGetRatioMode());
            }
        }
        else
        {
            // 16:9 display must set to 4x3
            if (ratio == SLR_MHEG5_SCENE_ASPECT_4X3)
            {
                Scaler_ChangeRatio(Scaler_DispGetRatioMode());
            }
        }
	}


}
SLR_MHEG5_SCENE_ASPECT_RATIO Scaler_GetMheg5SceneAspectRatio(void)
{
	return __mheg5SceneAspectRatio;
}

void Scaler_SetMheg5Alignment(SLR_MHEG5_ALIGNMENT alignment)
{
	if(__mheg5Alignment != alignment)
	{
		__mheg5Alignment = alignment;
	    if (Scaler_DispGetRatioMode() == SLR_RATIO_BBY_AUTO && Scaler_GetMheg5SceneAspectRatio() != SLR_MHEG5_SCENE_ASPECT_NONE)
	    {
		    Scaler_ChangeRatio(Scaler_DispGetRatioMode());
		}
	}
}
SLR_MHEG5_ALIGNMENT Scaler_GetMheg5Alignment(void)
{
    return __mheg5Alignment;
}

void Scaler_SetCurrentOverscanInfo(StructOverscanInfo* info)
{
	__overscanInfo=*info;
}
void Scaler_GetCurrentOverscanInfo(StructOverscanInfo* info)
{
	*info=__overscanInfo;
}


#endif

#if 0
typedef struct
{
    int tv_mode;
    int tv_sys;
    int tv_std;
}VoutModeInfo;
static const  VoutModeInfo g_VoutModeTable[] =
{
     {_MODE_480I,      VIDEO_NTSC,        VIDEO_INTERLACED  },
     {_MODE_576I,      VIDEO_PAL,         VIDEO_INTERLACED  },
     {_MODE_480P,      VIDEO_NTSC,        VIDEO_PROGRESSIVE },
     {_MODE_576P,      VIDEO_PAL,         VIDEO_PROGRESSIVE },
     {_MODE_720P50,    VIDEO_HD720_50HZ,  VIDEO_PROGRESSIVE },
     {_MODE_720P60,    VIDEO_HD720_60HZ,  VIDEO_PROGRESSIVE },
     {_MODE_1080I25,   VIDEO_HD1080_50HZ, VIDEO_INTERLACED  },
     {_MODE_1080I30,   VIDEO_HD1080_60HZ, VIDEO_INTERLACED  },
     {_MODE_1080P50,   VIDEO_HD1080_50HZ, VIDEO_PROGRESSIVE },
     {_MODE_1080P60,   VIDEO_HD1080_60HZ, VIDEO_PROGRESSIVE },
     {_MODE_4k2kI30,   VIDEO_HD3840x2160, VIDEO_INTERLACED  },
     {_MODE_4k2kP30,   VIDEO_HD3840x2160, VIDEO_PROGRESSIVE },
};
static int g_nVoutModeNum = (int)(sizeof(g_VoutModeTable)/sizeof(g_VoutModeTable[0]));

unsigned char Scaler_IsTVBOX(void)
{
#ifdef RUN_ON_TVBOX
    return TRUE;
#else
    return FALSE;
#endif
}

unsigned char Scaler_DispGetCVBSOutputType(void)
{
    unsigned char mode = _MODE_480I;
    unsigned char tv_mode = _MODE_480I;
    VIDEO_SYSTEM_INFO video_system_info = SetupClass::GetInstance()->GetVideoSystem();

    for(int ii=0; ii<g_nVoutModeNum; ii++)
    {
        if(video_system_info.video_system == g_VoutModeTable[ii].tv_sys &&
           video_system_info.video_standard == g_VoutModeTable[ii].tv_std)
        {
            mode = g_VoutModeTable[ii].tv_mode;
            break;
        }
    }

    switch(mode)
    {
    case _MODE_480I:
    case _MODE_480P:
    case _MODE_720P60:
    case _MODE_1080I30:
    case _MODE_1080P60:
    case _MODE_4k2kI30:
    case _MODE_4k2kP30:
    default:
        tv_mode = _MODE_480I;
        break;

    case _MODE_576I:
    case _MODE_576P:
    case _MODE_720P50:
    case _MODE_1080I25:
    case _MODE_1080P50:
        tv_mode = _MODE_576I;
        break;
    }

    return tv_mode;
}

unsigned char Scaler_DispGetYPPOutputType(void)
{
    unsigned char tv_mode = _MODE_480I;
    VIDEO_SYSTEM_INFO video_system_info = SetupClass::GetInstance()->GetVideoSystem();

    for(int ii=0; ii<g_nVoutModeNum; ii++)
    {
        if(video_system_info.video_system == g_VoutModeTable[ii].tv_sys &&
           video_system_info.video_standard == g_VoutModeTable[ii].tv_std)
        {
            tv_mode = g_VoutModeTable[ii].tv_mode;
            break;
        }
    }

    return tv_mode;
}

unsigned char Scaler_DispGetHDMIOutputType(void)
{
    unsigned char tv_mode = _MODE_480I;
    VIDEO_SYSTEM_INFO video_system_info = SetupClass::GetInstance()->GetVideoSystem();

    for(int ii=0; ii<g_nVoutModeNum; ii++)
    {
        if(video_system_info.video_system == g_VoutModeTable[ii].tv_sys &&
           video_system_info.video_standard == g_VoutModeTable[ii].tv_std)
        {
            tv_mode = g_VoutModeTable[ii].tv_mode;
            break;
        }
    }

    return tv_mode;
}
#endif

