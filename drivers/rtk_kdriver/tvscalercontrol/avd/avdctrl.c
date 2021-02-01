#define __AVD__
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/delay.h>
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
//#include <mach/RPCDriver.h>
#include <rtk_kdriver/RPCDriver.h>//sunray_liao add
#include <mach/io.h>
#include <linux/pageremap.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/string.h>/*memset*/
#include <linux/freezer.h>
#include <linux/timer.h>
#include <tvscalercontrol/scaler_vfedev.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/scalerdrv/inprocvideo.h>
#include <tvscalercontrol/pcbsource/pcbSource.h>
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scalerdrv/syncproc.h>
#include <rbus/adc_reg.h>
#include <mach/pcbMgr.h>//sunray
#include <tvscalercontrol/vdc/yc_separation_vpq.h>
#include <tvscalercontrol/vdc/video_factory.h>
#include <tvscalercontrol/vdc/video_input.h>
#include <tvscalercontrol/adcsource/adcctrl.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#include <tvscalercontrol/scaler/scalervideo.h>
#endif
#include <tvscalercontrol/scaler_vscdev.h>
#include <tvscalercontrol/scaler_vpqdev.h>

#include <tvscalercontrol/tve/tve.h>
#include <tvscalercontrol/vdac/vdac.h>

#include <tvscalercontrol/scalerdrv/power.h>
#include <rbus/vdpq_reg.h>//sunray
#include <rbus/sys_reg_reg.h>//sunray
#include <rbus/pll27x_reg_reg.h>
#include <rtk_kdriver/rtk_crt.h>//sunray
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/avd/avdctrl_vd.h>
#include <tvscalercontrol/avd/avdctrl.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <rbus/tv_sb1_ana_reg.h>//add for audio
#include <rbus/audio_reg.h>//add for audio

#define TAG_NAME_AVD "AVD"  //sunray add for log 2016-06-06
/**********************************************/
//#define VSTATE_STABLE 3
#define Interlaced 0
#define Progressive 1
//#define ATV_VSTATE_STABLE 3
//#define ATV_DETECT_STAGE_INIT 0
//#define ATV_DETECT_STAGE_HVLOCK 1
//#define ATV_DETECT_STAGE_VSTATE_READY 2
//#define ATV_DETECT_STAGE_FINAL 0xff

//==jj refine===============================
unsigned char g_ucAtvDetectStage = DETECT_STAGE_INIT;
unsigned char g_ucDetectStage = DETECT_STAGE_INIT;

unsigned char g_ucVDMode = _MODE_UNKNOWN;
unsigned char g_ucVDPreMode = _MODE_UNKNOWN;
unsigned char g_ucModeCurr = _MODE_UNKNOWN;
VFE_AVD_SCART_FB_STATUS_T g_ucScartMode = _MODE_UNKNOWN;
unsigned char g_ucSrcType = _SRC_TV;
VFE_AVD_DEMOD_TYPE g_tAVDDemodType = AVD_EXTERNAL_DEMOD;
VFE_AVD_COLOR_SYSTEM_T g_tSupportedColorSys = -1;
VDC_POWER_SETTING g_vdc_power_setting = VDC_Power_off;

unsigned int g_ulVDCPhyAddr = 0;
#ifdef CONFIG_ARM64
unsigned long g_ulVDCPhyAddr_cache = 0;
unsigned long *g_ulVDCPhyAddr_nonCache = 0;
#else
unsigned int g_ulVDCPhyAddr_cache = 0;
unsigned int *g_ulVDCPhyAddr_nonCache = 0;
#endif
unsigned char g_ucMode_Curr = _MODE_480I;


extern void Scaler_AVD_Set_VDC_Power_Setting(VDC_POWER_SETTING pow, unsigned char source);
extern VDC_POWER_SETTING Scaler_AVD_Get_VDC_Power(void);
StructDisplayInfo *Get_AVD_ScalerDispinfo(void);

//==jj refine===============================

//#define V_lock_num 6
#define _MODE_MIXED 0xff
#define _MODE_UNKNOWN 0xff

//unsigned char g_ucAtvVideoMode = KADP_COLOR_SYSTEM_PAL_G;
//unsigned char g_ucAtvVDMode = 0xff;
static unsigned char v_lock_count;
static StructDisplayInfo g_tAVDScalerDispInfo;
static ModeInformationType g_tAVDScalerTimingInfo;
static VFE_AVD_TIMING_INFO_T g_tAVDLGETimingInfo = {0};
static VFE_AVD_AVDECODER_VIDEO_MODE_T g_tLGEVideoMode = VIDEO_AVDEC_MODE_UNKNOWN;
static VFE_AVD_CC_TTX_STATUS_T g_tCCTTXStatus = VFE_AVD_NOTHING_IS_SUPPORTED;

static unsigned char g_ucSyncDetForTuning = TRUE;
bool g_bChangeSystem = true;
bool g_bStartChangeSystem = true;

bool g_bMainRunSearchState;
bool g_bSubRunSearchState;

#ifdef CONFIG_CUSTOMER_TV010
static unsigned short *tAV_PRESET_TABLE = NULL;
static UINT8 ucFieldChanged_Case0_Counter = 0;
static UINT8 ucFieldChanged_Case1_Counter = 0;
static UINT8 ucFieldChanged_Case2_Counter = 0;
static unsigned char bFieldChangedFlag = FALSE;
static bool g_bFVBiasRunScaler;
#endif

static bool g_AutoTuneMode;

unsigned int g_ulInitStageCount;
//extern unsigned char vdc_mode_detect;
unsigned char g_ucStopVDTimer = TRUE;
unsigned char g_ucTimerEnable = FALSE;
unsigned int g_ucTimerCount = 0x00000000;
extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr;


unsigned char avd_good_timing_ready = FALSE;
unsigned char atv_channel_change = FALSE;
unsigned char atv_channel_change_start = FALSE;
unsigned char vdc_resetTV_Count = 0;


#ifdef AVD_27M_CONTROL_BY_AP
static bool g_AP27MEnable = false;
#endif

/********************************************************************************/
void ClearAVDLGETimingInfo(void);
static VFE_AVD_AVDECODER_VIDEO_MODE_T ChangeAVDColorSysToVideoMode(VFE_AVD_COLOR_SYSTEM_T m_changeAVDColorsys);
static char CheckSupportedColorSys(VFE_AVD_AVDECODER_VIDEO_MODE_T a_tColorSystem);
static VFE_AVD_AVDECODER_VIDEO_MODE_T TransColorSysRTK2LGE(unsigned char a_ucVDMode);
static unsigned char GetLGESupportedMode(void);
static int getSCART_pin8(void);
//static void Scaler_AVD_Set_Scart_Mode(void);
//void fw_video_SetModeInfo(unsigned char CurrentSrc);
//static void AVD_check_av_color_std(unsigned char bInCheckMode);
/********************************************************************************/
//extern void Scaler_VBI_connect(unsigned char source, unsigned char mode,unsigned char vdc_mode);
extern void Scaler_VBI_disconnect(void);
//extern void wss_data_handle(void);
extern void drv_ifd_analog_preset(void);
extern void drv_ifd_adc_clock_init_162M(void);
void Scaler_AVD_ClearTimingInfo(void);
char Scaler_AVD_Timer_Init(void);
void Scaler_AVD_Timer_Delete(void);
void SendAVDSourceInfo(unsigned char a_ucSrcType, unsigned char a_ucDemodType);
void IFD_SIF_ADC_Pll_Initial(void);//add for audio requirements
void IFD_SIF_ADC_Initial_Flow(void);//add for audio requirements
//void Check_PLL27X_Settings(void);
void Scaler_AVD_Set_VDC_Power(VDC_POWER_SETTING pow, unsigned char source);
VDC_POWER_SETTING Scaler_AVD_Get_VDC_Power(void);





#ifdef AVD_27M_CONTROL_BY_AP
void Scaler_AVD_SetAP27MEnable(unsigned char a_ucFlag)
{
	g_AP27MEnable = a_ucFlag;
}

void Scaler_AVD_GetAP27MEnable(void)
{
	return g_AP27MEnable;
}
#endif /* AVD_27M_CONTROL_BY_AP */

StructDisplayInfo *Get_AVD_ScalerDispinfo(void)
{
	if (FALSE == module_vdc_check_vd_clock()) {
		VDC_DEBUG_MSG(VDC_MSG_ERROR, "module_vdc_check_vd_clock fail!\n");
		drvif_module_vdc_ClockOn();
	}

	Scaler_AVD_Set_VDC_Power_Setting(VDC_Power_on, get_AVD_Input_Source());
	return &g_tAVDScalerDispInfo;
}

ModeInformationType *Get_AVD_ScalerTiminginfo(void)
{
	return &g_tAVDScalerTimingInfo;
}

VFE_AVD_TIMING_INFO_T *Get_AVD_LGETiminginfo(void)
{
	return &g_tAVDLGETimingInfo;
}

void Scaler_AVD_SetSyncDetectForTuning(unsigned char a_ucFlag)
{
	g_ucSyncDetForTuning = a_ucFlag;
}

unsigned char Scaler_AVD_DoesSyncExist(void)
{
	unsigned char ucSyncExist = false;
	ucSyncExist= drvif_module_vdc_CheckHVisLocked();
	VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "ucSyncExist=%x\n", ucSyncExist);
	return ucSyncExist;
}

int Scaler_AVD_Init(VFE_AVD_CC_TTX_STATUS_T a_tCCTTXStatus)
{
	int ulRet = 0;
	g_tCCTTXStatus = a_tCCTTXStatus;
	ClearAVDLGETimingInfo();
	memset(&g_tAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(&g_tAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	return ulRet;
}

char Scaler_AVD_Uninit(void)
{
	char cRet = 0;
	ClearAVDLGETimingInfo();
	memset(&g_tAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(&g_tAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	return cRet;
}

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
void Scaler_AVD_EnableVD27MMode(VD_27M_OVERSAMPLING_MODE mode)
{
#ifdef AVD_27M_CONTROL_BY_AP
	rtd_printk(KERN_EMERG,TAG_NAME_AVD,"Scaler_AVD_EnableVD27MMode() mode=%d\n",mode);
#endif
	if (VD_27M_OFF != mode)
	{
		Scaler_Set_VDC_27MHz_Mode_Enable(TRUE);
		fw_video_set_27mhz_mode(mode);
		drvif_module_vdc_set_27M_mode(TRUE);
	}
	else
	{
		Scaler_Set_VDC_27MHz_Mode_Enable(FALSE);
		fw_video_set_27mhz_mode(VD_27M_OFF);
		drvif_module_vdc_set_27M_mode(FALSE);
	}
}
#endif /* CONFIG_ENABLE_VD_27MHZ_MODE */

char Scaler_AVD_Open(void)
{
	char cRet = 0;
	unsigned int ulPhyAddr;

	rtd_printk(KERN_EMERG,TAG_NAME_AVD,"Scaler_AVD_Open()\n");

	//g_ulVDCPhyAddr = 0;

/*
	#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
		Scaler_Set_VDC_27MHz_Mode_Enable(TRUE);
		fw_video_set_27mhz_mode(VD_27M_HSD960_DI5A);
	#endif
*/
	//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "0   Scaler_AVD_Open 0xb8000104=%x\n", rtd_inl(0xb8000104));

	Check_PLL27X_Settings();

	/*CVBS*/
	down(get_avd_power_semaphore());
	drvif_module_vdc_ClockOn();
	drvif_vdac_tvdac_power_on(OFF);
	drvif_module_tve_clock_enable(TVE_CLOCK_DISABLE);
//	drvif_module_vdc_PowerCtrl(ON, _SRC_CVBS);

	up(get_avd_power_semaphore());
	if (g_ulVDCPhyAddr == 0)
	{
#ifdef CONFIG_ARM64
		g_ulVDCPhyAddr_cache = (unsigned long)dvr_malloc_uncached_specific(_SDRAM_3D_COM_USE, GFP_DCU2_FIRST, (void **)&g_ulVDCPhyAddr_nonCache);
#else
		g_ulVDCPhyAddr_cache = (unsigned int)dvr_malloc_uncached_specific(_SDRAM_3D_COM_USE, GFP_DCU2_FIRST, (void **)&g_ulVDCPhyAddr_nonCache);
#endif
		g_ulVDCPhyAddr = (unsigned int)dvr_to_phys((void*)g_ulVDCPhyAddr_cache);
	}
	if(g_ulVDCPhyAddr == 0) {
		rtd_printk(KERN_ERR, TAG_NAME_AVD,"[ERROR]Allocate DCU2 size=%x fail\n",_SDRAM_3D_COM_USE);
		return FALSE;
	}

	ulPhyAddr = g_ulVDCPhyAddr + _SDRAM_3D_COM_OFFSET;

	rtd_printk(KERN_INFO, TAG_NAME_AVD,"VDC get addr = %x, _SDRAM_3D_COM_USE = %x, _SDRAM_3D_COM_OFFSET = %x\n", ulPhyAddr, _SDRAM_3D_COM_USE, _SDRAM_3D_COM_OFFSET);
	drvif_module_vdc_Initial(ulPhyAddr);
	drvif_inprocvideo_init();
	drvif_module_vpq_DmaAccessCtrl(ON);
	//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "1   Scaler_AVD_Open 0xb8000104=%x\n", rtd_inl(0xb8000104));
	return cRet;
}

char Scaler_AVD_Close(void)
{
	char cRet = 0;
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "Scaler_AVD_Close\n");

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
	Scaler_AVD_EnableVD27MMode(VD_27M_OFF);
#endif
#if 0
	//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "Need to wait detect timing done\n");
	while(g_ucAVDInDetectTiming)
	{
		mdelay(100);
		rtd_printk(KERN_EMERG, TAG_NAME_AVD, "Wait AVD detect timing done. g_ucAVDInDetectTiming=%d \n", g_ucAVDInDetectTiming);
	}
#endif

	ClearAVDLGETimingInfo();
	Scaler_AVD_ClearTimingInfo();
	drvif_module_vpq_DmaAccessCtrl(OFF);
	down(get_avd_power_semaphore());
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"Turn off VDC power\n");
	drvif_module_vdc_PowerCtrl(OFF, _SRC_TV);
	Scaler_AVD_Set_VDC_Power_Setting(VDC_Power_off, _SRC_TV);
	up(get_avd_power_semaphore());


	/*Use pli memory allocation @Crixus 20150801*/
	/*
	if (g_ulVDCPhyAddr != 0)
		pli_free((void *)g_ulVDCPhyAddr);

	g_ulVDCPhyAddr = 0;
	*/

	memset(&g_tAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(&g_tAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	return cRet;
}

char Scaler_AVD_AV_Connect(unsigned short srcinput)
{
	char cRet = 0;
	unsigned char ucSize = 0, i = 0;
	StructSourceInput *srcinput_pt = PcbSource_GetTable();
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"Scaler_AVD_AV_CONNECT()\n");

	g_ulInitStageCount = 0;

	drvif_module_vdc_SECAM_ColorReduction(_DISABLE);/*patch for HW issue 20160105,CSFC*/

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#ifdef AVD_27M_CONTROL_BY_AP
	if(g_AP27MEnable==VD_27M_HSD960_DI5A){
		Scaler_AVD_EnableVD27MMode(VD_27M_HSD960_DI5A);
	}else if(g_AP27MEnable==VD_27M_HSD1440_DI3A){
		Scaler_AVD_EnableVD27MMode(VD_27M_HSD1440_DI3A);
	}else{
		Scaler_AVD_EnableVD27MMode(VD_27M_OFF);
	}
#else
	//Scaler_AVD_EnableVD27MMode(VD_27M_HSD960_DI5A);
	Scaler_AVD_EnableVD27MMode(VD_27M_OFF);
#endif /* AVD_27M_CONTROL_BY_AP */
#endif /* CONFIG_ENABLE_VD_27MHZ_MODE */

	down(get_avd_power_semaphore());
	drvif_module_vdc_PowerCtrl(ON, _SRC_CVBS);
	Scaler_AVD_Set_VDC_Power_Setting(VDC_Power_saving, _SRC_CVBS);
	up(get_avd_power_semaphore());
	mdelay(2);

	g_ucSrcType = _SRC_CVBS;
	ucSize = PcbSource_GetTableSize();
	for (i = 0 ; i < ucSize ; i++) {
		if (srcinput_pt->src_index == srcinput)
			break;
		srcinput_pt++;
	}
	if (i == ucSize) {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Can't find srcinput in pcbsource=%x\n", srcinput);
		return -1;
	}
	g_tAVDScalerDispInfo.input_src = i;
	g_tAVDScalerDispInfo.data_array_index = i;
	g_tAVDScalerDispInfo.osd_input_src = i;

	drvif_module_vdc_SelectInput(_SRC_CVBS, (VDC_INITIAL_OPTIONS *)srcinput_pt->InitOptions);
//	drvif_module_vdc_set_burst_gate_position(VDC_MODE_AUTO);/*add by lichun zhao 20120105*/
	drvif_module_vdc_set_vsync_freerun_enable(_DISABLE);

	cRet = Scaler_AVD_Timer_Init();

	return cRet;
}

char Scaler_AVD_AV_Disconnect(void)
{
	char cRet = 0;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"Scaler_AVD_AV_Disconnet()\n");

	// Delete timer
	Scaler_AVD_Timer_Delete();

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
	Scaler_AVD_EnableVD27MMode(VD_27M_OFF);
#endif

	drvif_module_vdc_ResetLockStatus();
	Scaler_VBI_disconnect();
	ClearAVDLGETimingInfo();
	Scaler_AVD_ClearTimingInfo();
	memset(&g_tAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(&g_tAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	return cRet;
}

char Scaler_AVD_SetLGEColorSystem(VFE_AVD_COLOR_SYSTEM_T a_tColorSystem)
{
	char ret = 0;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_INFO, TAG_NAME_AVD, "a_tColorSystem=%x\n", a_tColorSystem);
	g_tSupportedColorSys = a_tColorSystem;
	return ret;
}

static char CheckSupportedColorSys(VFE_AVD_AVDECODER_VIDEO_MODE_T a_tColorSystem)
{
	VFE_AVD_COLOR_SYSTEM_T tColorSys = BIT0_VFE_AVD << a_tColorSystem;

	//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "kernel Scaler_CheckSupportedColorSys() g_tSupportedColorSys=%x, a_tColorSystem=%x\n", g_tSupportedColorSys, a_tColorSystem);

	if ((g_tSupportedColorSys & tColorSys) == 0) {
		//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Color sys not support, tColorSys=%x\n", tColorSys);
		//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "Color sys not support, tColorSys=%x\n", tColorSys);
		return -1;
	} else {
		//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Color sys support, tColorSys=%x\n", tColorSys);
		//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "Color sys support, tColorSys=%x\n", tColorSys);
		return 0;
	}
}

char Scaler_AVD_ATV_Connect(unsigned short srcinput)
{
	char cRet = 0;
	unsigned char ucSize = 0, i = 0;
	StructSourceInput *srcinput_pt = PcbSource_GetTable();
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"Scaler_AVD_ATV_CONNECT()\n");

	g_ucVDPreMode = _MODE_UNKNOWN;

	drvif_module_vdc_SECAM_ColorReduction(_DISABLE);/*patch for HW issue 20160105,CSFC*/
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
	//Scaler_AVD_EnableVD27MMode(VD_27M_HSD960_DI5A);
	Scaler_AVD_EnableVD27MMode(VD_27M_OFF);
#endif

	g_ulInitStageCount = 0;

	//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "0   Scaler_AVD_ATV_Connect 0xb8000104=%x\n", rtd_inl(0xb8000104));
	if (AVD_EXTERNAL_DEMOD == g_tAVDDemodType) {
		srcinput=_AV_INPUT2;
		//IFD_SIF_ADC_Pll_Initial();//add for audio requirements
	}

	g_ucSrcType = _SRC_TV;
	drvif_module_vdc_set_noSignalCounter_Value(0x03);
	ucSize = PcbSource_GetTableSize();
	for (i = 0 ; i < ucSize ; i++) {
		if (srcinput_pt->src_index == srcinput)
			break;
		srcinput_pt++;
	}
	if (i == ucSize) {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Can't find srcinput in pcbsource=%x\n", srcinput);
		return -1;
	}
	if (AVD_INTERNAL_DEMOD == g_tAVDDemodType) {
		down(get_avd_power_semaphore());
		drvif_module_vdc_PowerCtrl(ON, _SRC_TV);
		Scaler_AVD_Set_VDC_Power_Setting(VDC_Power_saving, _SRC_TV);
		up(get_avd_power_semaphore());
		mdelay(2);
		drvif_module_vdc_SelectInput(_SRC_TV, (VDC_INITIAL_OPTIONS *)srcinput_pt->InitOptions);
	} else if (AVD_EXTERNAL_DEMOD == g_tAVDDemodType) {
		down(get_avd_power_semaphore());
		drvif_module_vdc_PowerCtrl(ON, _SRC_CVBS);
		Scaler_AVD_Set_VDC_Power_Setting(VDC_Power_saving, _SRC_CVBS);
		drvif_module_vdc_set_external_ch_change_flag(FALSE);//For k6418
		//add for audio requirements
		if (_SRC_TV == g_ucSrcType) {
			IFD_SIF_ADC_Initial_Flow();
		}
		up(get_avd_power_semaphore());
		mdelay(2);
		//drvif_module_vdc_SelectInput(_SRC_CVBS, (VDC_INITIAL_OPTIONS *)srcinput_pt->InitOptions);
		drvif_module_vdc_for_demod_external(_SRC_CVBS, (VDC_INITIAL_OPTIONS *)srcinput_pt->InitOptions);
	}
	g_tAVDScalerDispInfo.input_src = i;
	g_tAVDScalerDispInfo.data_array_index = i;
	g_tAVDScalerDispInfo.osd_input_src = i;
//	drvif_module_vdc_set_burst_gate_position(VDC_MODE_AUTO);
	drvif_module_vdc_set_vsync_freerun_enable(_DISABLE);
	v_lock_count = 0;

	cRet = Scaler_AVD_Timer_Init();
	return cRet;
}

char Scaler_AVD_ATV_Disconnect(void)
{
	char cRet = 0;
	rtd_printk(KERN_INFO, TAG_NAME_AVD, "Scaler_AVD_ATV_Disconnect\n");

	g_ucVDPreMode = _MODE_UNKNOWN;

	// clear the auto scan flag
	drvif_module_vdc_set_scan_flag(FALSE);
	drvif_module_vdc_set_int_auto_scan_flag(FALSE);
	drvif_module_vdc_set_external_auto_scan_flag(FALSE);

	// Delete timer
	Scaler_AVD_Timer_Delete();
	drvif_module_vdc_ResetLockStatus();
	drv_module_vdc_SetInterrupt(VDC_Mode_irq_disable);
	drvif_module_vdc_FreeRun(VDC_FREERUN_DISABLE);
	Scaler_VBI_disconnect();
	ClearAVDLGETimingInfo();
	Scaler_AVD_ClearTimingInfo();
	memset(&g_tAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(&g_tAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	return cRet;
}

VFE_AVD_TIMING_INFO_T *Scaler_AVD_GetLGETimingInfo(unsigned char *a_ucRet)
{
	*a_ucRet = 0;
//	VFE_AVD_TIMING_INFO_T *ptLGETimingInfo;

	SetAVDLGETimingInfo();

#if 0
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.h=%d\n", ptLGETimingInfo->active.h);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.w=%d\n", ptLGETimingInfo->active.w);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.x=%d\n", ptLGETimingInfo->active.x);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.y=%d\n", ptLGETimingInfo->active.y);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "format=%d\n", ptLGETimingInfo->format);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "hFreq=%d\n", ptLGETimingInfo->hFreq);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vFreq=%d\n", ptLGETimingInfo->vFreq);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "hTotal=%d\n", ptLGETimingInfo->hTotal);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vTotal=%d\n", ptLGETimingInfo->vTotal);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "hPorch=%d\n", ptLGETimingInfo->hPorch);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vPorch=%d\n", ptLGETimingInfo->vPorch);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "scanType=%d\n", ptLGETimingInfo->scanType);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vdLock=%d\n", ptLGETimingInfo->vdLock);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "HLock=%d\n", ptLGETimingInfo->HLock);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "VLock=%d\n", ptLGETimingInfo->VLock);
#endif

	//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "g_tAVDLGETimingInfo.standard=%x, hTotal=%x, format=%x\n", g_tAVDLGETimingInfo.standard, g_tAVDLGETimingInfo.hTotal, g_tAVDLGETimingInfo.format);
	//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "s=%x, ht=%x, h=%x, w=%x\n", g_tAVDLGETimingInfo.standard, g_tAVDLGETimingInfo.hTotal, g_tAVDLGETimingInfo.active.h, g_tAVDLGETimingInfo.active.w);
	return &g_tAVDLGETimingInfo;
}

void SetAVDLGETimingInfo(void)
{
	bool Support480I = false, Support576I = false;
	unsigned char ucModeCur = 0;
	StructDisplayInfo *ptAVDScalerDispInfo;
	//ModeInformationType *ptAVDScalerTimingInfo;
	VFE_AVD_TIMING_INFO_T *ptLGETimingInfo;

	unsigned char uc625_flag = 0xff;

	ptAVDScalerDispInfo = Get_AVD_ScalerDispinfo();;
	//ptAVDScalerTimingInfo = Get_AVD_ScalerTiminginfo();
	ptLGETimingInfo = Get_AVD_LGETiminginfo();
	ucModeCur = ptAVDScalerDispInfo->ucMode_Curr;
	if ((g_tSupportedColorSys & COLOR_SYSTEM_NTSC_M) == COLOR_SYSTEM_NTSC_M
		|| (g_tSupportedColorSys & COLOR_SYSTEM_NTSC_443) == COLOR_SYSTEM_NTSC_443
		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_60) == COLOR_SYSTEM_PAL_60
		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_M) == COLOR_SYSTEM_PAL_M)
	{
		Support480I = true;
	}
	if ((g_tSupportedColorSys & COLOR_SYSTEM_PAL_G) == COLOR_SYSTEM_PAL_G
		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_NC_358)	== COLOR_SYSTEM_PAL_NC_358
		|| (g_tSupportedColorSys & COLOR_SYSTEM_SECAM) == COLOR_SYSTEM_SECAM
//		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_60) == COLOR_SYSTEM_PAL_60
		|| g_tSupportedColorSys == -1) {
		Support576I = true;
	}
	/*No signal*/
	if (DETECT_STAGE_FINAL != g_ucDetectStage) {
		ClearAVDLGETimingInfo();
		// When no siganl, only ATV needs to set active.h, active.w vFreq
		// In other VD sources, all timing info is zero

		if ( _SRC_TV == g_ucSrcType)
		{
			//rtd_printk(KERN_INFO, TAG_NAME_AVD,"no siganl\n");
			//rtd_printk(KERN_INFO, TAG_NAME_AVD,"DETECT_STAGE_FINAL != g_ucDetectStage(%d), can't do SetAVDLGETimingInfo()\n", g_ucDetectStage);
			if (Support480I == true && Support576I == true && g_tSupportedColorSys != -1) {
				VFE_AVD_COLOR_SYSTEM_T LastVideoMode = -1;
				LastVideoMode = BIT0_VFE_AVD << g_tLGEVideoMode;
				if ((LastVideoMode & COLOR_SYSTEM_NTSC_M) == COLOR_SYSTEM_NTSC_M
					|| (LastVideoMode & COLOR_SYSTEM_NTSC_443) == COLOR_SYSTEM_NTSC_443
					|| (LastVideoMode & COLOR_SYSTEM_PAL_60) == COLOR_SYSTEM_PAL_60
					|| (LastVideoMode & COLOR_SYSTEM_PAL_M) == COLOR_SYSTEM_PAL_M)
				{
					Support480I = true;
					Support576I = false;
				}
				else if ((LastVideoMode & COLOR_SYSTEM_PAL_G) == COLOR_SYSTEM_PAL_G
					|| (LastVideoMode & COLOR_SYSTEM_PAL_NC_358) == COLOR_SYSTEM_PAL_NC_358
//					|| (LastVideoMode & COLOR_SYSTEM_PAL_60) == COLOR_SYSTEM_PAL_60
					|| (LastVideoMode & 	COLOR_SYSTEM_SECAM) == COLOR_SYSTEM_SECAM)
				{
					Support480I = false;
					Support576I = true;
				}
			}
			if (Support480I == true && Support576I == false) {
				ptLGETimingInfo->active.h = 480;
				ptLGETimingInfo->active.w = 704;
				ptLGETimingInfo->vFreq = 599;
			} else if (Support576I == true && Support480I == false) {
				ptLGETimingInfo->active.h = 576;
				ptLGETimingInfo->active.w = 704;
				ptLGETimingInfo->vFreq = 500;
			} else if (Support576I == true && Support480I == true) 	{
				ptLGETimingInfo->active.h = 480;
				ptLGETimingInfo->active.w = 704;
				ptLGETimingInfo->vFreq = 599;
			} else {
				ptLGETimingInfo->active.h = 480;
				ptLGETimingInfo->active.w = 704;
				ptLGETimingInfo->vFreq = 599;
			}


			// External demod auto scan (For China model)
			// External demod
			if (0 == drvif_module_vdc_read_Clamping_path())
			{
				// Auto scan
				if (drvif_module_vdc_read_external_autoscan_flag())
				{
					uc625_flag = drvif_video_get_625_flag();

					VD_recheck_625flag_loop(&uc625_flag);

					if (uc625_flag != 0xff)
					{
						if (0 == uc625_flag)
						{
							ptLGETimingInfo->active.h = 480;
							ptLGETimingInfo->active.w = 704;
							ptLGETimingInfo->vFreq = 599;

							//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "autoscan 525 line, std=%x\n", ptLGETimingInfo->standard);
						}
						else
						{
							ptLGETimingInfo->active.h = 576;
							ptLGETimingInfo->active.w = 704;
							ptLGETimingInfo->vFreq = 500;

							//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "autoscan 625 line, std=%x\n", ptLGETimingInfo->standard);
						}
					}
				}
				else
				{
					//rtd_printk(KERN_EMERG, TAG_NAME_AVD, "Not in autoscan\n");
				}
			}
		}
		return;
	}
	/*Neet to translate color std from Realtek to LGE	*/
	g_tLGEVideoMode = TransColorSysRTK2LGE(g_ucVDMode);
	/*Input color std is supported by this TV.*/
	// Only ATV need to do CheckSupportedColorSys
	if ( _SRC_TV != g_ucSrcType || 0 == CheckSupportedColorSys(g_tLGEVideoMode)) {

		//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Not ATV source, don't do CheckSupportedColorSys()\n");
		/*480i*/
		if (_MODE_480I == ucModeCur) {
			g_ucModeCurr = _MODE_480I;
			if (Support480I == false && Support576I == true) {
				ptLGETimingInfo->active.h = 576;
				ptLGETimingInfo->active.w = 704;
				ptLGETimingInfo->vFreq = 500;
			}
			else {
				ptLGETimingInfo->active.h = 480;
				ptLGETimingInfo->active.w = 704;
				if (g_ucSrcType == _SRC_TV) {
					ptLGETimingInfo->vFreq = 599;
				}
				else {
					ptLGETimingInfo->vFreq = 600;
				}
			}
		} else if (_MODE_576I == ucModeCur) {
			/*576i*/
			g_ucModeCurr = _MODE_576I;
			if (Support480I == true && Support576I == false) {
				ptLGETimingInfo->active.h = 480;
				ptLGETimingInfo->active.w = 704;
				if (g_ucSrcType == _SRC_TV) {
					ptLGETimingInfo->vFreq = 599;
				}
				else {
					ptLGETimingInfo->vFreq = 600;
				}
			}
			else {
				ptLGETimingInfo->active.h = 576;
				ptLGETimingInfo->active.w = 704;
				ptLGETimingInfo->vFreq = 500;
			}
		} else {
			ptLGETimingInfo->active.h = 576;
			ptLGETimingInfo->active.w = 704;
			g_ucModeCurr = _MODE_576I;
			ptLGETimingInfo->vFreq = 500;
		}

		if (drvif_module_vdc_Get625flag() == 0){
			ptLGETimingInfo->active.h = 480;
			ptLGETimingInfo->active.w = 704;
			ptLGETimingInfo->vFreq = 599;
		}else{
			ptLGETimingInfo->active.h = 576;
			ptLGETimingInfo->active.w = 704;
			ptLGETimingInfo->vFreq = 500;
		}

		
		ptLGETimingInfo->active.x = ptAVDScalerDispInfo->IPH_ACT_STA_PRE;
		ptLGETimingInfo->active.y = ptAVDScalerDispInfo->IPV_ACT_LEN_PRE;
		/*this is not used in HAL function*/
		ptLGETimingInfo->format = 0;
		ptLGETimingInfo->hFreq = (ptAVDScalerDispInfo->IHFreq) * 100;
		ptLGETimingInfo->hTotal = ptAVDScalerDispInfo->IHTotal;
		ptLGETimingInfo->vTotal = ptAVDScalerDispInfo->IVTotal;
		ptLGETimingInfo->hPorch = ptAVDScalerDispInfo->IPH_ACT_STA_PRE;
		ptLGETimingInfo->vPorch = ptAVDScalerDispInfo->IPV_ACT_LEN_PRE;
		ptLGETimingInfo->scanType = Interlaced;/* 0 : Interlaced, 1 : Progressive*/
		ptLGETimingInfo->vdLock = TRUE;
		ptLGETimingInfo->HLock = TRUE;
		ptLGETimingInfo->VLock = TRUE;
		ptLGETimingInfo->standard = g_tLGEVideoMode;
	} /* end of if (0 == CheckSupportedColorSys(g_tLGEVideoMode))*/
	/*Input color std is "NOT" supported by this TV.*/
	else {
		ClearAVDLGETimingInfo();
		ptLGETimingInfo->standard = ChangeAVDColorSysToVideoMode(g_tSupportedColorSys);
	}
#if 0
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.h=%d\n", ptLGETimingInfo->active.h);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.w=%d\n", ptLGETimingInfo->active.w);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.x=%d\n", ptLGETimingInfo->active.x);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "active.y=%d\n", ptLGETimingInfo->active.y);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "format=%d\n", ptLGETimingInfo->format);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "hFreq=%d\n", ptLGETimingInfo->hFreq);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vFreq=%d\n", ptLGETimingInfo->vFreq);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "hTotal=%d\n", ptLGETimingInfo->hTotal);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vTotal=%d\n", ptLGETimingInfo->vTotal);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "hPorch=%d\n", ptLGETimingInfo->hPorch);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vPorch=%d\n", ptLGETimingInfo->vPorch);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "scanType=%d\n", ptLGETimingInfo->scanType);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "vdLock=%d\n", ptLGETimingInfo->vdLock);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "HLock=%d\n", ptLGETimingInfo->HLock);
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "VLock=%d\n", ptLGETimingInfo->VLock);
#endif
}

static unsigned char GetLGESupportedMode(void)
{
	unsigned char ucMode = 0;
	if ((g_tSupportedColorSys & COLOR_SYSTEM_NTSC_M) == COLOR_SYSTEM_NTSC_M
		|| (g_tSupportedColorSys & COLOR_SYSTEM_NTSC_443) == COLOR_SYSTEM_NTSC_443
		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_60) == COLOR_SYSTEM_PAL_60
		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_M) == COLOR_SYSTEM_PAL_M)
	{
		ucMode = _MODE_480I;
	}
	if ((g_tSupportedColorSys & COLOR_SYSTEM_PAL_G) == COLOR_SYSTEM_PAL_G
		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_NC_358) 	== COLOR_SYSTEM_PAL_NC_358
		|| (g_tSupportedColorSys & 	COLOR_SYSTEM_SECAM) == COLOR_SYSTEM_SECAM
//		|| (g_tSupportedColorSys & COLOR_SYSTEM_PAL_60) == COLOR_SYSTEM_PAL_60
		|| g_tSupportedColorSys == -1)
	{
		if (_MODE_480I == ucMode) {
			/*Mixed mode*/
			ucMode = _MODE_MIXED;
		} else {
			ucMode = _MODE_576I;
		}
	}
	return ucMode;
}

void ClearAVDLGETimingInfo(void)
{
	VFE_AVD_TIMING_INFO_T *ptLGETimingInfo = Get_AVD_LGETiminginfo();
	unsigned char ucModeSupported = 0;
	/*rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"ClearAVDLGETimingInfo\n");*/
	/*rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, 	__LINE__);*/
	memset(ptLGETimingInfo, 0, sizeof(VFE_AVD_TIMING_INFO_T));

	// Non-ATV source don't need to check supported color std
	if ( _SRC_TV != g_ucSrcType)
		return;

	ucModeSupported = GetLGESupportedMode();
	/*Mixed Mode*/
	if (_MODE_MIXED == ucModeSupported) {
		/*Use previous mode*/
		if (_MODE_UNKNOWN != g_ucModeCurr) {
			ucModeSupported = g_ucModeCurr;
		} else {
			ucModeSupported = _MODE_480I;
		}
	}
	/*480i*/
	if (_MODE_480I == ucModeSupported) {
		ptLGETimingInfo->active.h = 480;
		ptLGETimingInfo->active.w = 704;
		ptLGETimingInfo->vFreq = 599;
		//} else if (_MODE_576I == ucModeSupported) {
	} else {
		/*576i*/
		ptLGETimingInfo->active.h = 576;
		ptLGETimingInfo->active.w = 704;
		ptLGETimingInfo->vFreq = 500;
	}
	ptLGETimingInfo->standard = VIDEO_AVDEC_MODE_UNKNOWN;
	//g_ucVDMode = _MODE_UNKNOWN;
}
static VFE_AVD_AVDECODER_VIDEO_MODE_T ChangeAVDColorSysToVideoMode(VFE_AVD_COLOR_SYSTEM_T m_changeAVDColorsys)
{
	switch(m_changeAVDColorsys){
		
		case COLOR_SYSTEM_NTSC_M :
			return VIDEO_AVDEC_MODE_NTSC;
			
		case COLOR_SYSTEM_PAL_G :
			return VIDEO_AVDEC_MODE_PAL;
				
		case COLOR_SYSTEM_PAL_NC_358 :
			return VIDEO_AVDEC_MODE_PAL_NC_358;
				
		case COLOR_SYSTEM_PAL_M :
			return VIDEO_AVDEC_MODE_PAL_M;
				
		case COLOR_SYSTEM_SECAM :
			return VIDEO_AVDEC_MODE_SECAM;
				
		case COLOR_SYSTEM_NTSC_443 :
			return VIDEO_AVDEC_MODE_NTSC_443;
				
		case COLOR_SYSTEM_PAL_60 :
			return VIDEO_AVDEC_MODE_PAL_60;

		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Color std error, m_changeAVDColorsys=%x\n", m_changeAVDColorsys);
			return VIDEO_AVDEC_MODE_UNKNOWN;
	}


}
static VFE_AVD_AVDECODER_VIDEO_MODE_T TransColorSysRTK2LGE(unsigned char a_ucVDMode)
{
	//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"TransColorSysRTK2LGE a_ucVDMode=%x\n", a_ucVDMode);
	if (0xff != a_ucVDMode) {
		switch (a_ucVDMode) {
		/*480i*/
		case VDC_MODE_NTSC:
			return VIDEO_AVDEC_MODE_NTSC;
		case VDC_MODE_NTSC443:
			return VIDEO_AVDEC_MODE_NTSC_443;
		case VDC_MODE_PAL60:
			return VIDEO_AVDEC_MODE_PAL_60;
		case VDC_MODE_PALM:
			return VIDEO_AVDEC_MODE_PAL_M;
		/*576i*/
		case VDC_MODE_NTSC50:
			/*FixMe*/
			return VIDEO_AVDEC_MODE_PAL;
		case VDC_MODE_PALN:
			return VIDEO_AVDEC_MODE_PAL_NC_358;
		case VDC_MODE_PALI:
			return VIDEO_AVDEC_MODE_PAL;
		case VDC_MODE_SECAM:
			return VIDEO_AVDEC_MODE_SECAM;
		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Color std error, a_ucVDMode=%x\n", a_ucVDMode);
		}
	}
	return VIDEO_AVDEC_MODE_UNKNOWN;
}

char Scaler_AVD_GetLGEColorSystem(VFE_AVD_AVDECODER_VIDEO_MODE_T *a_ptColorSystem)
{
	char ret = 0;
	StructDisplayInfo *p_tAVDDispInfo = Get_AVD_ScalerDispinfo();
	unsigned char SupportSystem = 0;
	SupportSystem = GetLGESupportedMode();
	if (DETECT_STAGE_FINAL != g_ucDetectStage) {
		*a_ptColorSystem = VIDEO_AVDEC_MODE_UNKNOWN;
	} else {
		VFE_AVD_AVDECODER_VIDEO_MODE_T CurrentVideoMode = TransColorSysRTK2LGE(g_ucVDMode);
		/*Input color std is supported by this TV.*/
		if (_SRC_TV != g_ucSrcType || 0 == CheckSupportedColorSys(CurrentVideoMode)) {
			*a_ptColorSystem = CurrentVideoMode;
		}
		/*Input color std is "NOT" supported by this TV.*/
		else {
			if (_MODE_480I == p_tAVDDispInfo->ucMode_Curr) {
#if 0 /* Modify based on the Question_detail.xlsx*/
				*a_ptColorSystem =  VIDEO_AVDEC_MODE_UNKNOWN_525;
#else
				if (SupportSystem == _MODE_576I) {
					*a_ptColorSystem = VIDEO_AVDEC_MODE_PAL;
				}
				else {
					*a_ptColorSystem = VIDEO_AVDEC_MODE_NTSC;
				}
#endif
			} else if (_MODE_576I == p_tAVDDispInfo->ucMode_Curr) {
#if 0 /* Modify based on the Question_detail.xlsx*/
				*a_ptColorSystem = VIDEO_AVDEC_MODE_UNKNOWN_625;
#else
				if (SupportSystem == _MODE_480I) {
					*a_ptColorSystem = VIDEO_AVDEC_MODE_NTSC;
				}
				else {
					*a_ptColorSystem = VIDEO_AVDEC_MODE_PAL;
				}
#endif
			} else {
				*a_ptColorSystem = VIDEO_AVDEC_MODE_UNKNOWN;
			}
		}
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_GetColorSystem(),  a_ptColorSystem=%x, ucMode_Curr=%x\n", *a_ptColorSystem, p_tAVDDispInfo->ucMode_Curr);
	return ret;
}

#if 0
static void AVD_check_av_color_std(unsigned char bInCheckMode)
{
	unsigned char mode = drvif_module_vdc_ReadMode(VDC_SET);
	unsigned char getmode;
	mode = mode | 0x10;

	if (bInCheckMode && mode != ZAUTO) {
		if ((drv_module_vdc_GetVdcCurrMode() == VDC_MODE_PALI) && (mode == ZPAL_I))
			return;
		if ((drv_module_vdc_GetVdcCurrMode() == VDC_MODE_NTSC) && (mode == ZNTSC))
			return;
	}
	switch (mode) {
	case ZAUTO:
		if ((drvif_module_vdc_ReadAutomode()) == 0) {
			UINT8 i = 0;
			drvif_module_vdc_SetMode(VDC_MODE_AUTO);
			for (i = 0 ; i < 50 ; i++) {
				if (drvif_module_vdc_CheckHVisLocked()) {
					rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"[%x]vd lock:%x\n", i, (drvif_video_status_reg(VDC_STATUS_REG1)));
					break;
				}
				msleep(10);
			}
		}
		break;
	case ZNTSC:
		getmode = drv_module_vdc_GetVdcCurrMode();
		if (getmode == ZNTSC_443)
			drvif_module_vdc_SetMode(VDC_MODE_NTSC443);
		else
			drvif_module_vdc_SetMode(VDC_MODE_NTSC);
		break;
	case ZPAL_I:
		drvif_module_vdc_SetMode(VDC_MODE_PALI);
		break;
	case ZNTSC_50:
		drvif_module_vdc_SetMode(VDC_MODE_NTSC50);
		break;
	case ZNTSC_443:
		drvif_module_vdc_SetMode(VDC_MODE_NTSC443);
		break;
	case ZPAL_M:
		drvif_module_vdc_SetMode(VDC_MODE_PALM);
		break;
	case ZPAL_N:
		drvif_module_vdc_SetMode(VDC_MODE_PALN);
		break;
	case ZPAL_60:
		drvif_module_vdc_SetMode(VDC_MODE_PAL60);
		break;
	case ZSECAM:
	case ZSECAML:
	case ZSECAMLA:
		drvif_module_vdc_SetMode(VDC_MODE_SECAM);
		break;
	default:
		break;
	}
}
#endif

void AVD_OnlineMeasureError_Handler(int srcType)
{
	StructDisplayInfo *ptAVDScalerDispInfo = Get_AVD_ScalerDispinfo();
	ModeInformationType *ptAVDScalerTimingInfo = Get_AVD_ScalerTiminginfo();
	/*For ATV, only go to init state of Scaler_AVD_DetectTiming().*/
	if (_SRC_TV == g_ucSrcType) {
		//g_ucDetectStage = DETECT_STAGE_INIT;
#if 0
		if (AVD_EXTERNAL_DEMOD == g_tAVDDemodType) {
			//drvif_module_vdc_SoftReset();
		}
#endif
		return;
	}
	memset(ptAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(ptAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	g_ucDetectStage = DETECT_STAGE_INIT;
	switch (srcType) {
	case _AV_INPUT1:
	case _AV_INPUT2:
	case _AV_INPUT3:
		break;
	case _TV_INPUT1:
	case _TV_INPUT2:
	case _TV_INPUT3:
		break;
	case _SCART_INPUT1:
	case _SCART_INPUT2:
	case _SCART_INPUT3:
		break;
	default:
		break;
	}
}

void Scaler_AVD_ClearTimingInfo(void)
{
	VDC_DEBUG_MSG(VDC_MSG_TVCHCH, "Scaler_AVD_ClearTimingInfo\n");
	StructDisplayInfo *ptAVDScalerDispInfo = Get_AVD_ScalerDispinfo();
	ModeInformationType *ptAVDScalerTimingInfo = Get_AVD_ScalerTiminginfo();
	memset(ptAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(ptAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	g_ucDetectStage = DETECT_STAGE_INIT;
}

char Scaler_AVD_SetDemodType(VFE_AVD_DEMOD_TYPE a_tDemodType)
{
	char  cRet = 0;
	if (a_tDemodType == AVD_INTERNAL_DEMOD || a_tDemodType == AVD_EXTERNAL_DEMOD) {
		g_tAVDDemodType = a_tDemodType;
		cRet = 0;
	} else {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_SetDemodType fail, a_tDemodType=%d\n", a_tDemodType);
		cRet = -1;
	}
	return cRet;
}
VFE_AVD_DEMOD_TYPE Scaler_AVD_GetDemodType(void)
{
	return g_tAVDDemodType;
}

/*Scart CVBS*/
char Scaler_AVD_Scart_Connect(unsigned short srcinput)
{
	char cRet = 0;
	unsigned char ucSize = 0, i = 0;
	StructSourceInput *srcinput_pt = PcbSource_GetTable();
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_SCART_CONNECT()\n");

	down(get_avd_power_semaphore());
	drvif_module_vdc_PowerCtrl(ON, _SRC_SCART);
	Scaler_AVD_Set_VDC_Power_Setting(VDC_Power_saving, _SRC_SCART);
	up(get_avd_power_semaphore());
	/*It means scart cvbs*/
	g_ucSrcType = _SRC_SCART;
	ucSize = PcbSource_GetTableSize();
	for (i = 0 ; i < ucSize ; i++) {
		if (srcinput_pt->src_index == srcinput)
			break;
		srcinput_pt++;
	}
	if (i == ucSize) {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Can't find srcinput in pcbsource=%x\n", srcinput);
		return -1;
	}
	g_tAVDScalerDispInfo.input_src = i;
	g_tAVDScalerDispInfo.data_array_index = i;
	g_tAVDScalerDispInfo.osd_input_src = i;
	g_ucScartMode = _MODE_UNKNOWN;
	drvif_module_vdc_SelectInput(_SRC_SCART, (VDC_INITIAL_OPTIONS *)srcinput_pt->InitOptions);
	drvif_module_vdc_set_vsync_freerun_enable(_DISABLE);
	return cRet;
}

char Scaler_AVD_ScartRGB_Connect(unsigned short srcinput)
{
	char cRet = 0;
	unsigned char ucSize = 0, i = 0;
	StructSourceInput *srcinput_pt = PcbSource_GetTable();
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_SCART_CONNECT()\n");
	down(get_avd_power_semaphore());
	drvif_module_vdc_PowerCtrl(ON, _SRC_SCART_RGB);
	Scaler_AVD_Set_VDC_Power_Setting(VDC_Power_saving, _SRC_SCART_RGB);
	up(get_avd_power_semaphore());

	g_ucSrcType = _SRC_SCART_RGB;
	ucSize = PcbSource_GetTableSize();
	for (i = 0 ; i < ucSize ; i++) {
		if (srcinput_pt->src_index == srcinput)
			break;
		srcinput_pt++;
	}
	if (i == ucSize) {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Can't find srcinput in pcbsource=%x\n", srcinput);
		return -1;
	}
	g_tAVDScalerDispInfo.input_src = i;
	g_tAVDScalerDispInfo.data_array_index = i;
	g_tAVDScalerDispInfo.osd_input_src = i;
	g_ucScartMode = _MODE_UNKNOWN;
	drvif_module_vdc_SelectInput(_SRC_SCART_RGB, (VDC_INITIAL_OPTIONS *)srcinput_pt->InitOptions);
	drvif_module_vdc_set_vsync_freerun_enable(_DISABLE);
	return cRet;
}

char Scaler_AVD_Scart_Disconnect(void)
{
	char cRet = 0;
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_Scart_Disconnect()\n");
	drvif_module_vdc_ResetLockStatus();
	Scaler_VBI_disconnect();
	ClearAVDLGETimingInfo();
	Scaler_AVD_ClearTimingInfo();
	memset(&g_tAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(&g_tAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	return cRet;
}

char Scaler_AVD_GetScartFastBlankingStatus(VFE_AVD_SCART_FB_STATUS_T *pStatus)
{
	int ret = 0;
	adc_scart_ctrl1_RBUS scart_ctrl1_reg;//sunray modify
	ADC_Power_Control(ON);
	scart_ctrl1_reg.regValue = IoReg_Read32(ADC_SCART_CTRL1_reg);
	scart_ctrl1_reg.vdadc_sct_ctrl = 0x47;
	IoReg_Write32(ADC_SCART_CTRL1_reg, scart_ctrl1_reg.regValue);
	msleep(30);
	if (drvif_module_vdc_read_FSW_value() >= cSCART_FSW_Level) {
		g_ucScartMode = VIDEO_DDI_FB_STATUS_RGB;
	} else {
		g_ucScartMode = VIDEO_DDI_FB_STATUS_CVBS;
	}
	*pStatus = g_ucScartMode;
	ADC_Power_Control(OFF);
	return ret;
}

char Scaler_AVD_GetScartID(VFE_AVD_SCART_AR_T *pScartAr)
{
	int ret = 0;
	SCART_PIN8_LEVEL Scart;
	Scart = getSCART_pin8();
	if (Scart == SCART_PIN8_LEVEL_16_9)
		*pScartAr = VFE_AVD_SCART_AR_16_9;
	else if (Scart == SCART_PIN8_LEVEL_4_3)
		*pScartAr = VFE_AVD_SCART_AR_4_3;
	else
		*pScartAr = VFE_AVD_SCART_AR_INVALID;
	return ret;
}

int lsadc_init(int index, int voltage_mode)
{
// FixMe

#if 0
	/*st_lsadc_ctrl_RBUS st_lsadc_ctrl_reg;*/
	/*st_lsadc_analog_ctrl_RBUS 	st_lsadc_analog_ctrl_reg;*/
	st_pad0_RBUS st_pad0_reg;
	if (index >= 8)
		return -1;
	st_pad0_reg.regValue = 0;
	st_pad0_reg.pad0_active = 1;
	st_pad0_reg.pad0_sw = index;
	if (voltage_mode)
		st_pad0_reg.pad0_ctrl = 0;
	else
		st_pad0_reg.pad0_ctrl = 1;
	rtd_outl(ST_PAD0_VADDR + index * 4, st_pad0_reg.regValue);
#endif
	return 0;
}

int lsdac_get(int index)
{
// FixMe

#if 0
	st_lsadc_ctrl_RBUS st_lsadc_ctrl_reg;
	st_pad0_RBUS st_pad0_reg;
	if (index >= 8)
		return -1;
	st_lsadc_ctrl_reg.regValue = rtd_inl(ST_LSADC_CTRL_VADDR);
	if (st_lsadc_ctrl_reg.enable == 0) {
		st_lsadc_ctrl_reg.enable = 1;
		rtd_outl(ST_LSADC_CTRL_VADDR, st_lsadc_ctrl_reg.regValue);
	}
	st_pad0_reg.regValue = rtd_inl(ST_PAD0_VADDR + index * 4);
	return st_pad0_reg.adc_val0;
#endif

// FixMe
	return 0;
}

int getSCART_pin8(void)
{
	char *pin_name[3] = {"PIN_SCART_LEVEL_NONE", "PIN_SCART_LEVEL_16_9", "PIN_SCART_LEVEL_4_3"};
	unsigned long long value;
	int idx, upper, lower;
	int adc_val = 0, i = 0;
	static bool is_lsadc_init;
	for (i = 0 ; i < 3 ; i++) {
		if ((pcb_mgr_get_enum_info_byname(pin_name[i], &value) == 0) && (GET_PIN_TYPE(value) == PCB_PIN_TYPE_LSADC)) {
			if (!is_lsadc_init) {
				lsadc_init(value, 1);
				msleep(10);
				is_lsadc_init = true;
			}
			idx  = GET_PIN_INDEX(value);
			upper = GET_LSADC_HITVALUE(value) + GET_LSADC_TOLERANCE(value);
			lower = GET_LSADC_HITVALUE(value) - GET_LSADC_TOLERANCE(value);
			adc_val = lsdac_get(idx);
			if ((adc_val >= lower) && (adc_val <= upper)) {
				return i;
			}
		}
	}
	return 0;
}

/*static unsigned char fw_video_detectmode_avd(unsigned char CurrentSrc)*/
/* porting from fw_video_detectmode()*/
void fw_video_SetModeInfo(unsigned char CurrentSrc)
{
	if (CurrentSrc == _SRC_TV || CurrentSrc == _SRC_CVBS) {
		if (drv_module_vdc_GetFrameRate()) {
			drv_module_vdc_SetVarFieldVTotal(263);
			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"[VDC] 480i \n");
		} else {
			drv_module_vdc_SetVarFieldVTotal(313);
			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"[VDC] 576i \n");
		}
#if 0	/* jj modify 20150814, tv reset move to channel change */
		if (CurrentSrc == _SRC_TV)
			drvif_module_vdc_tv_Reset();
		else
			drvif_module_vdc_ResetReg();
#endif

		if (CurrentSrc == _SRC_CVBS) {
			drvif_module_vdc_ResetReg();
			module_vdc_set_Clamp_position(drvif_module_vdc_ReadMode(VDC_SET));
		}
	}
}


//For K4L
bool Scaler_AVD_SetChannelChange(void)
{
	int ret = 0;
	StructDisplayInfo *ptAVDScalerDispInfo  = Get_AVD_ScalerDispinfo();
	ModeInformationType *ptAVDScalerTimingInfo = Get_AVD_ScalerTiminginfo();

	rtd_printk(KERN_EMERG, TAG_NAME_AVD,"Scaler_AVD_SetChannelChange\n");
	memset(ptAVDScalerDispInfo, 0, sizeof(StructDisplayInfo));
	memset(ptAVDScalerTimingInfo, 0, sizeof(ModeInformationType));
	atv_channel_change = TRUE;
	atv_channel_change_start=TRUE;
	if (AVD_EXTERNAL_DEMOD == g_tAVDDemodType) {
		drvif_module_vdc_set_external_ch_change_flag(TRUE);
	}else{
		drvif_module_vdc_set_ch_change_flag(TRUE);
	}
	return ret;
}

bool Scaler_AVD_GetIsChannelChange(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_GetIsChannelChange\n");
	return atv_channel_change_start;
}


// Channel change at this time
void Scaler_AVD_SetChangeSystem(bool Change)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_SetChangeSystem\n");
	if(_SRC_CVBS == g_ucSrcType) {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"[AVD] Not TV Source!! \n");
		return;
	}

	g_bStartChangeSystem = Change;
	if (true == Change) {
		Scaler_AVD_ClearTimingInfo();
	}
	g_ucDetectStage = DETECT_STAGE_INIT;
	ClearAVDLGETimingInfo();
}

bool Scaler_AVD_GetChangeSystem(void)
{
	return  g_bChangeSystem;
}

bool Scaler_AVD_GetRunSearchState(unsigned char a_ucChannel)
{
	if (SLR_MAIN_DISPLAY  == a_ucChannel)
		return g_bMainRunSearchState;
	else
		return g_bSubRunSearchState;
}

void Scaler_AVD_SetRunSearchState(unsigned char a_ucChannel, bool a_bFlag)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_SetRunSearchState=%x, a_ucChannel=%x\n", a_bFlag, a_ucChannel);


	if (SLR_MAIN_DISPLAY  == a_ucChannel)
		g_bMainRunSearchState = a_bFlag;
	else
		g_bSubRunSearchState = a_bFlag;

}

unsigned char Scaler_AVD_GetAvdSource(void)
{
	return g_ucSrcType;
}

#if 0
bool Scaler_AVD_GetDetectTimingAgain(unsigned char a_ucChannel)
{
	return g_bAVDDetectTimingAgain;
}
void Scaler_AVD_SetDetectTimingAgain(unsigned char a_ucChannel, bool a_bFlag)
{
	g_bAVDDetectTimingAgain = a_bFlag;
}
#endif

void Scaler_AVD_SetAutoTuneMode(bool AutoTuneMode)
{
	g_AutoTuneMode = AutoTuneMode;
}

bool Scaler_AVD_GetAutoTuneMode(void)
{
	return g_AutoTuneMode;
}

unsigned char Scaler_AVD_GetDetectStage(void)
{
	return g_ucDetectStage;
}

void Scaler_AVD_SetDetectStage(unsigned char stage)
{
	g_ucDetectStage = stage;
}

unsigned char Scaler_AVD_GetVDPreMode(void)
{
	return g_ucVDPreMode;
}

/* True: Timing change
   False: Timing is the same */
//unsigned char Scaler_AVD_CheckATVTimingChange(void)
unsigned char Scaler_AVD_CheckATVTimingChange(unsigned char a_ucChannel)
{
	// ATV change channel with different color std
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_AVD_GetRunSearchState=%x, channel=%x, src=%x\n", Scaler_AVD_GetRunSearchState(a_ucChannel), a_ucChannel, Scaler_AVD_GetAvdSource());
	if (Scaler_AVD_GetAvdSource() == _SRC_TV && Scaler_AVD_GetRunSearchState(a_ucChannel))
	{
		Scaler_AVD_SetRunSearchState(a_ucChannel, false);
		return true;
	}

	return false;
}

char Scaler_AVD_IsSupportedColorSys(void)
{
	return CheckSupportedColorSys(TransColorSysRTK2LGE(g_ucVDMode));
}

void Scaler_AVD_ResetTVCount(void)
{
	vdc_resetTV_Count = 0;
}

//add for audio requirements
void  IFD_SIF_ADC_Pll_Initial(void)
{
//K3L
/*
	rtd_printk(KERN_EMERG, TAG_NAME_AVD, "\n[SIF_ADC]IFD_SIF_ADC_Pll_Initial\n");
	//PLDIF
	//rtd_maskl(0xb80004c8, 0xfffffff8, 0x0);
	//rtd_maskl(0xb80004c8, 0xfffffff8, 0x6);
	//rtd_maskl(0xb80004c8, 0xfffffff8, 0x7);
	//rtd_maskl(0xb80004c8, 0x7fffffff, 0x80000000);

	//PLL27X
	//rtd_maskl(0xb80004d4, 0xfff8ffff, 0x00070000);
	//rtd_maskl(0xb80004d8, 0xffffffe8, 0x17);
	//rtd_maskl(0xb80004dc, 0xfDfffefe, 0x02000100);
	//PLL27X_IFADC
	rtd_maskl(0xb8000500, 0xfffffeef, 0x00000110);
	rtd_maskl(0xb8000508, 0xfffffff8, 0x7);

	//rtd_maskl(0xb80004dc, 0XFDF3FEFF, 0x020C0100);//Enable Output
*/
}

void  IFD_SIF_ADC_Initial_Flow(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "\n[SIF_ADC]IFD_SIF_ADC_Initial_Flow\n");
	tv_sb1_ana_ifadc_ctrl1_RBUS ifadc_ctrl1;
	tv_sb1_ana_ifadc_ctrl2_RBUS ifadc_ctrl2;

	tv_sb1_ana_iqadc_ctrl0_RBUS iqadc_ctrl0;
	tv_sb1_ana_iqadc_ctrl2_RBUS iqadc_ctrl2;
	tv_sb1_ana_iqadc_ctrl3_RBUS iqadc_ctrl3;
	tv_sb1_ana_iqadc_ctrl4_RBUS iqadc_ctrl4;
	tv_sb1_ana_iqadc_ctrl5_RBUS iqadc_ctrl5;
	tv_sb1_ana_iqadc_ctrl7_RBUS iqadc_ctrl7;

	ifadc_ctrl1.regValue = IoReg_Read32(TV_SB1_ANA_IFADC_CTRL1_reg);
	ifadc_ctrl2.regValue = IoReg_Read32(TV_SB1_ANA_IFADC_CTRL2_reg);

	iqadc_ctrl0.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL0_reg);
	iqadc_ctrl2.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL2_reg);
	iqadc_ctrl3.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL3_reg);
	iqadc_ctrl4.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL4_reg);
	iqadc_ctrl5.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL5_reg);
	iqadc_ctrl7.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL7_reg);

	//IFADC+IFPGA power on
	ifadc_ctrl1.reg_pow_mbias = 1; //[16]REG_POW_MBIAS
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33100 %x\n",ifadc_ctrl1.regValue);
	IoReg_Write32(TV_SB1_ANA_IFADC_CTRL1_reg, ifadc_ctrl1.regValue);

	ifadc_ctrl2.reg_adc2x_difpow = 1; //[24]REG_ADC2X_DIFPOW
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33104 %x\n",ifadc_ctrl2.regValue);
	IoReg_Write32(TV_SB1_ANA_IFADC_CTRL2_reg, ifadc_ctrl2.regValue);

	//IQADC+IQPGA power on
	iqadc_ctrl7.reg_qadc_meta_pow = 1; //[12]REG_QADC_META_POW, [8]REG_IADC_META_POW
	iqadc_ctrl7.reg_iadc_meta_pow = 1;
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33134 %x\n",iqadc_ctrl7.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL7_reg, iqadc_ctrl7.regValue);

	iqadc_ctrl3.reg_pow_q_pga = 1; //[12]REG_POW_Q_PGA, [8]REG_POW_I_PGA, [4]REG_POW_Q_ADC, [0]REG_POW_I_ADC
	iqadc_ctrl3.reg_pow_q_adc = 1;
	iqadc_ctrl3.reg_pow_i_pga = 1;
	iqadc_ctrl3.reg_pow_i_adc = 1;
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33124 %x\n",iqadc_ctrl3.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL3_reg, iqadc_ctrl3.regValue);

	//Fix IFPGA 2dB
	iqadc_ctrl2.reg_adc2x_fixgain= 0; //[6:4]REG_ADC2X_FIXGAIN, Fix IFPGA 2dB, [0]REG_IF_FIX_EN
	iqadc_ctrl2.reg_if_fix_en= 1;
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33120 %x\n",iqadc_ctrl2.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL2_reg, iqadc_ctrl2.regValue);

	iqadc_ctrl5.reg_ipga_d = 2; //[3:0]REG_IPGA_D, IPGA gain adjust 0x2: 2dB
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 3312c %x\n",iqadc_ctrl5.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL5_reg, iqadc_ctrl5.regValue);

	// SIF Audio related setting

	iqadc_ctrl0.reg_ckout_sel_q = 0; //REG_CKOUT_SEL_Q--> 0:Q_CKOUT
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33118 %x\n",iqadc_ctrl0.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL0_reg, iqadc_ctrl0.regValue);

	iqadc_ctrl4.reg_qpga_input_sel = 0x4; //REG_QPGA_INPUT_SEL  100: SIF input
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33128 %x\n",iqadc_ctrl4.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL4_reg, iqadc_ctrl4.regValue);

	iqadc_ctrl7.reg_qadc_vref_sel = 0; //1.23V
	iqadc_ctrl7.reg_iadc_vref_sel = 0; //1.23V
	iqadc_ctrl7.reg_qadc_ldo_sel = 0; //0.95V
	iqadc_ctrl7.reg_iadc_ldo_sel = 0; //0.95V
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33134 %x\n",iqadc_ctrl7.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL7_reg, iqadc_ctrl7.regValue);

	iqadc_ctrl2.reg_iqcmp_isel = 0x4; //50uA(default)
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 33120 %x\n",iqadc_ctrl2.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL2_reg, iqadc_ctrl2.regValue);

	iqadc_ctrl5.reg_q_ckin_sel = 0x2; //REG_Q_CKIN_SEL 10: CK_24M From Digital
	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"SIF ADC 3312c %x\n",iqadc_ctrl5.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL5_reg, iqadc_ctrl5.regValue);

//K3L
#if 0
	audio_global_ctrl_1_RBUS  global_ctrl_1;

	//SIF audio clk
    global_ctrl_1.regValue = IoReg_Read32(AUDIO_global_ctrl_1_reg);
	global_ctrl_1.sif_adc_clk_en = 1;
    IoReg_Write32(AUDIO_global_ctrl_1_reg, global_ctrl_1.regValue);

	tv_sb1_ana_ifadc_ctrl1_RBUS ifadc_ctrl1;
	tv_sb1_ana_iqadc_ctrl0_RBUS iqadc_ctrl0;
	tv_sb1_ana_iqadc_ctrl3_RBUS iqadc_ctrl3;
	tv_sb1_ana_iqadc_ctrl4_RBUS iqadc_ctrl4;
	tv_sb1_ana_iqadc_ctrl5_RBUS iqadc_ctrl5;
	tv_sb1_ana_iqadc_ctrl6_RBUS iqadc_ctrl6;

	ifadc_ctrl1.regValue = IoReg_Read32(TV_SB1_ANA_IFADC_CTRL1_reg);
	iqadc_ctrl0.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL0_reg);
	iqadc_ctrl3.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL3_reg);
	iqadc_ctrl4.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL4_reg);
	iqadc_ctrl5.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL5_reg);
	iqadc_ctrl6.regValue = IoReg_Read32(TV_SB1_ANA_IQADC_CTRL6_reg);

	ifadc_ctrl1.reg_pow_mbias = 1;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"SIF ADC 33100 %x\n",ifadc_ctrl1.regValue);
	IoReg_Write32(TV_SB1_ANA_IFADC_CTRL1_reg, ifadc_ctrl1.regValue);

	iqadc_ctrl0.reg_q_ckout_edge = 0;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"SIF ADC 33118 %x\n",iqadc_ctrl0.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL0_reg, iqadc_ctrl0.regValue);

	iqadc_ctrl3.reg_pow_q_adc = 1;
	iqadc_ctrl3.reg_pow_q_pga = 1;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"SIF ADC 33124 %x\n",iqadc_ctrl3.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL3_reg, iqadc_ctrl3.regValue);

	iqadc_ctrl4.reg_qpga_input_sel = 2; //Select SIF_in pad
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"SIF ADC 33128 %x\n",iqadc_ctrl4.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL4_reg, iqadc_ctrl4.regValue);

	iqadc_ctrl5.reg_q_ckin_sel = 2; //CK_24M From Digital
	iqadc_ctrl5.reg_qpga_d = 0;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"SIF ADC 3312c %x\n",iqadc_ctrl5.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL5_reg, iqadc_ctrl5.regValue);

	iqadc_ctrl6.reg_qadc_delay_en = 0;
	iqadc_ctrl6.reg_qadc_ckout_div = 0;
	iqadc_ctrl6.reg_qadc_bypass_pga= 0;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"SIF ADC 33130 %x\n",iqadc_ctrl6.regValue);
	IoReg_Write32(TV_SB1_ANA_IQADC_CTRL6_reg, iqadc_ctrl6.regValue);
#endif
}
//add for audio requirements end 2016-07-12

void Check_PLL27X_Settings(void)
{
	pll27x_reg_sys_pll_27x3_RBUS sys_pll_27x3_reg;	/* 0_04d8 */
	pll27x_reg_sys_pll_27x4_RBUS sys_pll_27x4_reg;	/* 0_04dc */

	sys_pll_27x3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_27X3_reg);
	sys_pll_27x4_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_27X4_reg);


	if (sys_pll_27x3_reg.pll27x_pow != 1)
		sys_pll_27x3_reg.pll27x_pow = 1;

	if (sys_pll_27x3_reg.pll27x_rstb != 1)
		sys_pll_27x3_reg.pll27x_rstb = 1;

	if (sys_pll_27x3_reg.pll27x_vcorstb != 1)
		sys_pll_27x3_reg.pll27x_vcorstb = 1;

	if (sys_pll_27x3_reg.pll27x_ps_en != 1)
		sys_pll_27x3_reg.pll27x_ps_en = 1;

	if (sys_pll_27x4_reg.pll_l2h_cml_pow != 1)
		sys_pll_27x4_reg.pll_l2h_cml_pow = 1;

	if (sys_pll_27x4_reg.pll27x_yppadc_cko_en != 1)
		sys_pll_27x4_reg.pll27x_yppadc_cko_en = 1;

	if (sys_pll_27x4_reg.pll27x_yppadc_cko_sel != 3)
		sys_pll_27x4_reg.pll27x_yppadc_cko_sel = 3;

	IoReg_Write32(PLL27X_REG_SYS_PLL_27X3_reg, sys_pll_27x3_reg.regValue);
	IoReg_Write32(PLL27X_REG_SYS_PLL_27X4_reg, sys_pll_27x4_reg.regValue);
}

unsigned char AVD_vpq_mem_ctrl(unsigned char bEnable)
{
	// bEnable = 1, allocate memory and enable VDPQ memory access
	// bEnable = 0, disable VDPQ memory access and free memory (delay 1/60 sec)

	if (FALSE == module_vdc_check_pll27x_setting()  || FALSE == module_vdc_check_vd_clock())
	{
		rtd_printk(KERN_ERR, TAG_NAME_AVD, "[ERROR] VDC Clock is off\n");
		return FALSE;
	}

	if(bEnable == _ENABLE)
	{
		AVD_Memory_Allocate();
	}
	else
	{

		// Bound end address to start address for protection
		vdpq_mem0_addr_ini_RBUS mem0_addr_ini_reg;
		vdpq_mem1_addr_ini_RBUS mem1_addr_ini_reg;
		vdpq_mem2_addr_ini_RBUS mem2_addr_ini_reg;
		vdpq_mem3_addr_ini_RBUS mem3_addr_ini_reg;
		vdpq_mem0_addr_end_RBUS mem0_addr_end_reg;
		vdpq_mem1_addr_end_RBUS mem1_addr_end_reg;
		vdpq_mem2_addr_end_RBUS mem2_addr_end_reg;
		vdpq_mem3_addr_end_RBUS mem3_addr_end_reg;
		
		// Disble VDPQ memory access
		drvif_module_vpq_DmaAccessCtrl(OFF);
		
		mem0_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_INI_reg);
		mem1_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM1_ADDR_INI_reg);
		mem2_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM2_ADDR_INI_reg);
		mem3_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_INI_reg);
		mem0_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_END_reg);
		mem1_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM1_ADDR_END_reg);
		mem2_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM2_ADDR_END_reg);
		mem3_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_END_reg);

		mem0_addr_end_reg.regValue = mem0_addr_ini_reg.regValue;
		mem1_addr_end_reg.regValue = mem1_addr_ini_reg.regValue;
		mem2_addr_end_reg.regValue = mem2_addr_ini_reg.regValue;
		mem3_addr_end_reg.regValue = mem3_addr_ini_reg.regValue;

		vdcf_outl(VDPQ_MEM0_ADDR_END_reg, mem0_addr_end_reg.regValue);
		vdcf_outl(VDPQ_MEM1_ADDR_END_reg, mem1_addr_end_reg.regValue);
		vdcf_outl(VDPQ_MEM2_ADDR_END_reg, mem2_addr_end_reg.regValue);
		vdcf_outl(VDPQ_MEM3_ADDR_END_reg, mem3_addr_end_reg.regValue);

		AVD_Memory_Free();
	}

	if(bEnable == _ENABLE && g_ulVDCPhyAddr != 0)
		return TRUE;
	else if(bEnable == _DISABLE && g_ulVDCPhyAddr == 0)
		return TRUE;
	else
		return FALSE;

}

unsigned int AVD_vpq_mem_isAllocated(void)
{
	return g_ulVDCPhyAddr;
}
