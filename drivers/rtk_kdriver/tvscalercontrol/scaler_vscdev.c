//Kernel Header file
#include <linux/interrupt.h>
#include <linux/sched.h>
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
#include <rtk_kdriver/RPCDriver.h>
#include <linux/pageremap.h>
#include <linux/kthread.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/string.h>/*memset*/
#include <linux/wait.h>//For wake_up and wait
#include <linux/spinlock_types.h>/*For spinlock*/
#include <rbus/dma_vgip_reg.h>
#include <rtk_dc_mt.h>
#include <scalercommon/scalerDrvCommon.h>

#ifdef CONFIG_RTK_KDRV_PWM
#include <rtk_kdriver/rtk_pwm.h>
#endif
#ifdef CONFIG_RTK_KDRV_QOS_CONTROL
#include <rtk_kdriver/rtk_qos_export.h>
#endif

// FixMe
//#include "../rtk_gdma_export.h"
//#include "../rtk_osdcomp_driver.h"


#include <rtk_kdriver/gal/rtk_gdma_export_user.h>
#include <tvscalercontrol/scaler/scalerlib.h>

//#include <tvscalercontrol/i3ddma/i3ddma.h>
//#include <tvscalercontrol/i3ddma/i3ddma_drv.h>


#include <rbus/sub_vgip_reg.h>
#include <rbus/onms_reg.h>
#include <rbus/timer_reg.h>
#include <rbus/hsd_dither_reg.h>
#include <rbus/osdovl_reg.h>
#include <rbus/h3ddma_reg.h>
#include <rbus/rgb2yuv_reg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/abl_reg.h>
#include <rbus/iedge_smooth_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/dolby_v_top_reg.h>
#include <rbus/dm_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/sub_vgip_reg.h>
#include <rbus/rgb2yuv_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/onms_reg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/scaleup_reg.h>
#include <rbus/scaledown_reg.h>
#include <rbus/dolby_v_top_reg.h>
#include <rbus/dm_reg.h>
#include <rbus/misc_reg.h>
//#include <rbus/rbus_DesignSpec_MISC_GPIOReg.h>
#include <rbus/tvsb2_reg.h>
#include <rbus/vdtop_reg.h>

#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/scalerdrv/overscanTable.h>

#include <tvscalercontrol/pcbsource/pcbSource.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/syncproc.h>
#include <tvscalercontrol/scalerdrv/auto.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/scalerip.h>
#include <tvscalercontrol/scalerdrv/framesync.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/adcsource/ypbpr.h>
#include <tvscalercontrol/adcsource/vga.h>
#include <tvscalercontrol/adcsource/adcctrl.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <rtk_kdriver/tvscalercontrol/hdmirx/hdmi_vfe.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/scalerdrv/adjust.h>
#include <tvscalercontrol/scalerdrv/scaler_2dcvt3d_ctrl.h>
#include <tvscalercontrol/vo/rtk_vo.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle_lib.h>
#include <tvscalercontrol/scalerdrv/pipmp.h>
#include <tvscalercontrol/scalerdrv/power.h>
#include <tvscalercontrol/scalerdrv/inprocvideo.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <tvscalercontrol/scalerdrv/scaler_pst.h>
#include <rpc/VideoRPC_System.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>

#include <tvscalercontrol/i3ddma/i3ddma.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>

#include "scaler_vfedev.h"
#include "scaler_vscdev.h"
#include "scaler_vbedev.h"
#include "scaler_vtdev.h"
#include <tvscalercontrol/avd/avdctrl.h>
#include <rbus/vgip_reg.h>
#include "scaler_vpqmemcdev.h"
#include <linux/freezer.h>
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#include <tvscalercontrol/scaler/scalervideo.h>
#include "scaler_vfedev.h"
static UINT8 read_buffer_first_flag = 0;
static UINT8 sub_read_buffer_first_flag = 0;
#endif

#if 1//(defined(CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT)||defined(CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT))
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#endif

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
#include <dolby_IDK_1_4_3/dolbyvisionEDR_export.h>
#include "../dolbyvision_edr/dolby_flowCtrl.h"
#endif

#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/vdc/yc_separation_vpq.h>
#include <rbus/abl_reg.h>
#include <scalercommon/vipRPCCommon.h>	/* in common*/

#include <mach/rtk_log.h>
#define TAG_NAME_VSC "VSC"

//#include <rtk_kdriver/rtk_platform.h>

//#define BRING_UP_AUTO_FLOW/*This is for bring up. auto vsc set input and output region*/
//#define _PRINT_VSC_COST_TIME_AFTER_MUTE_OFF
static struct semaphore VSC_Semaphore;
static struct semaphore MagMsg_Semaphore;
static struct semaphore Magnifier_Semaphore;
static struct semaphore DM_HDR_Semaphore;
static struct semaphore Force_Run_Idma_Semaphore;
static struct semaphore Low_Delay_Semaphore;
static struct semaphore Double_buffer_Semaphore;
static struct semaphore GameMode_Check_Semaphore;
#ifdef CONFIG_HDR_SDR_SEAMLESS
void dynamic_change_hdr_setting(unsigned char hdr_enable);
static struct semaphore HDR_Setting_Semaphore;//this is for HDR V top setting Semaphore
struct semaphore *get_hdr_setting_semaphore(void);//ger HDR_Setting_Semaphore
#endif

#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
static struct semaphore Orbit_algo_Semaphore;
#endif
#ifdef _PRINT_VSC_COST_TIME_AFTER_MUTE_OFF
static unsigned int cost_time;
#endif
static struct semaphore Adaptive_Streaming_Semaphore;/*For adaptive streaming info Semaphore*/
static struct semaphore SetMainOutPutRegion_Semaphore;/*For main set output region Semaphore*/
static struct semaphore Main_ResetMode_Semaphore;/*For main reset mode Semaphore*/

#ifdef CONFIG_DUAL_CHANNEL
static struct semaphore SetSubOutPutRegion_Semaphore;/*For sub set output region Semaphore*/
static struct semaphore Sub_ResetMode_Semaphore;/*For sub reset mode Semaphore*/

#endif
extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr; // debug scaler flag tracker
extern unsigned int rotatedisconnecten;

extern unsigned char vga_good_timing_ready;
static unsigned int check_atv_stable_count =0;

int sub_window_type = 0;
int subWin_LGowner = 0;
int ATV_forcei3ddma = 0;

#ifdef CONFIG_HW_SUPPORT_MEMC
//These are for mute on to wait memc already blck video
#define MAX_MEMC_DELAY_BUFFER 45//4.4 frame buffer
unsigned char sync_memc_ready = FALSE;//if TRUE. when mute on to wait memc buffer
void wait_memc_ready(void);
#endif

int main_InputRegion_0000 = 0;



static unsigned char vsc_debug_mode = FALSE;// This is for VSC flow debug
//static unsigned char VSC_Device_Init_Done = FALSE;
//static unsigned char LivezoomMainRerunFlag = FALSE;
//unsigned char DataFramesynclivezoom = FALSE;
//static unsigned char check_only_xy_shift_same_region = FALSE;
//static unsigned char LivezoomOffKeepMainForceBG = FALSE;
//static unsigned char multiview_sub_interlace_flag = 0;//add HDMI sub channel field control @Crixus 20151203

//static unsigned short main_inputregion_x_pre = 0;
//static unsigned short main_inputregion_w_pre = 0;
//static unsigned short main_inputregion_x_ori_pre = 0;
//static unsigned short main_inputregion_w_ori_pre = 0;
//static unsigned char main_check_pre_flag = 0;

//static unsigned char DI_low_delay_flag = FALSE;

//static unsigned char g_ucCheckAVDandWebOSInfoCount = 0xff;

//unsigned char g_ucVSCCheckATVChanelChange;
//unsigned char g_ucVSCATVChanelChangeStart;
//unsigned char g_ucVSCATVSetWinBlankCount;
//unsigned char g_ucVDCDetectStage;

//#define CONFIG_FIXED_VD_27MHZ_960_TO_UZU 1
//#define CONFIG_MDOMAIN_COMPRESSION_ENBLE 1

#define VSC_PROFILE 0
#define LiveZoom_PROFILE 0
#define _RGB2YUV_m11				0x00
#define _RGB2YUV_m12				0x01
#define _RGB2YUV_m13				0x02
#define _RGB2YUV_m21				0x03
#define _RGB2YUV_m22				0x04
#define _RGB2YUV_m23				0x05
#define _RGB2YUV_m31				0x06
#define _RGB2YUV_m32				0x07
#define _RGB2YUV_m33				0x08
#define _RGB2YUV_Yo_even			0x09
#define _RGB2YUV_Yo_odd			0x0a
#define _RGB2YUV_Y_gain				0x0b
#define _RGB2YUV_sel_RGB			0x0c
#define _RGB2YUV_set_Yin_offset		0x0d
#define _RGB2YUV_set_UV_out_offset	0x0e
#define _RGB2YUV_sel_UV_off			0x0f
#define _RGB2YUV_Matrix_bypass		0x10
#define _RGB2YUV_Enable_Y_gain		0x11

#define REDUCE_DI_BANDWIDTH_LIMIT_THRESHOLD 	1920//960//1440


#define CHECK_AVD_WEBOS_INFO_TIMEOUT (30)


//#define  _Mantis_74135
//#define  _Mantis_80057
//#define  _Mantis_72744
#define CONFIG_COMPRESSION_MODE_TEST

int drivf_I3DDMA_3D_config(void);
#ifdef CONFIG_FORCE_RUN_I3DDMA
unsigned char drivf_i3ddma_config(unsigned char display, unsigned char src);
#endif
void drvif_I3DDMA_Init(void);
void I3DDMA_Parse_HDMI3D_pattern(void);
static void set_default_mcap_format(unsigned char display, VSC_INPUT_TYPE_T inputSrctype);//M Cap 444 or 422
//unsigned char Scaler_Set3DMode(unsigned char message, bool muteAudio);
unsigned char wait_atv_stable_for_bg(unsigned char display);

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
unsigned char rtk_hal_vsc_SetHdrDolbyVisionIdmaEnable(unsigned char bEnable);
#endif

#ifdef CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
unsigned char rtk_hal_vsc_SetHdr10IdmaEnable(unsigned char bEnable);
#endif

#define VDC_DETECT_STAGE_FINAL 0xff
static void apvr_request_run_main_path(void);//This api is for apvr need to run main path again
int sub_shape_type = VSC_MGF_TYPE_CIRCLE;
static int sub_mode_type = VSC_SUB_MODE_PIP;//PIP: Live zoom, magnifire //PBP: Multiview
unsigned char Scaler_CalWindowZoominForAVD(SCALER_DISP_CHANNEL display,VIDEO_RECT_T *inregion, VIDEO_RECT_T *outregion);
unsigned char Scaler_DispWindowZoominForAVD(SCALER_DISP_CHANNEL display, VIDEO_RECT_T inputwin, VIDEO_RECT_T outputwin, unsigned char changetomain);
extern unsigned char check_ott_dolby_update_run(void);
extern void Set_Reply_Zero_Timing_Flag(unsigned char src, unsigned char flag);
extern void modestate_set_display_timing(unsigned char dclk_is_max);
extern unsigned char modestate_decide_display_timing(void);
extern void memc_setting_displayDtiming_framerate(void);
extern unsigned char LiveZoom_MEMCClose_Flag;
extern struct semaphore* get_livezoom_memcclose_Semaphore(void);
extern void Scaler_AVD_EnableVD27MMode(VD_27M_OVERSAMPLING_MODE mode);
extern void zoom_clear_input_output_region_record(unsigned char display);
unsigned char scaler_atv_force_run_idma(void);
extern unsigned char modestate_decide_display_timing(void);
extern unsigned char get_vo_frameratechange_enable(unsigned char display);

static dev_t vsc_devno = 0;//vsc device number
static struct cdev vsc_cdev;
//Eric@0809
unsigned char VSC_OUTPUT_VENC_MODE_FLAG = FALSE;
unsigned short virtual_x=0,virtual_y=0,virtual_w=0,virtual_h=0;
unsigned short true_wide=0,true_high=0;

//Game mode cmd checking flow @Cixus 20161204
unsigned int game_mode_cmd_check = 0;

unsigned int mdomain_input_fast_flag = 0;

//unsigned int main_opensourceID = _UNKNOWN_INPUT;
//#ifdef CONFIG_DUAL_CHANNEL
//unsigned int sub_opensourceID = _UNKNOWN_INPUT;
//#endif
//static unsigned char main_VO_smoothtoggle_need_presetting = FALSE;

DECLARE_WAIT_QUEUE_HEAD(FORCEBG_WAIT_QUEUE);

//Below is used to check run scaler source already change or not
static struct semaphore vsc_src_verify_num_ctrl_sem;
static unsigned char source_connect_verify_num[MAX_DISP_CHANNEL_NUM] =
{//record vsc connect number. verify used. confirm vsc source connect numebt
	0,
#ifdef CONFIG_DUAL_CHANNEL
	0
#endif
};

static unsigned char cur_vsc_src_num = 0;//currently run scaler vsc source num

unsigned char get_source_connect_verify_num(unsigned char display)
{
#ifndef CONFIG_DUAL_CHANNEL
	if(display != SLR_MAIN_DISPLAY)
	{
		pr_err("\r\n get_source_connect_verify_num display(%d) error", display);
		return 0;
	}
#else
	if((display != SLR_MAIN_DISPLAY) && (display != SLR_SUB_DISPLAY))
	{
		pr_err("\r\n get_source_connect_verify_num display(%d) error", display);
		return 0;
	}
#endif
		return source_connect_verify_num[display];
}

void increase_source_connect_verify_num(unsigned char display)
{
	#define max_source_verify_num 200
#ifndef CONFIG_DUAL_CHANNEL
	if(display != SLR_MAIN_DISPLAY)
	{
		pr_err("\r\n increase_source_connect_verify_num display(%d) error", display);
		return;
	}
#else
	if((display != SLR_MAIN_DISPLAY) && (display != SLR_SUB_DISPLAY))
	{
		pr_err("\r\n increase_source_connect_verify_num display(%d) error", display);
		return;
	}
#endif
	down(&vsc_src_verify_num_ctrl_sem);
	if(source_connect_verify_num[display] == max_source_verify_num)
		source_connect_verify_num[display] = 0;
	else
		source_connect_verify_num[display] =  source_connect_verify_num[display] + 1;
	up(&vsc_src_verify_num_ctrl_sem);
}

void set_current_scaler_source_num(unsigned char display)
{//set cur_vsc_src_num form get_source_connect_verify_num
#ifndef CONFIG_DUAL_CHANNEL
	if(display != SLR_MAIN_DISPLAY)
	{
		pr_err("\r\n set_cur_sclaer_source_num display(%d) error", display);
		return;
	}
#else
	if((display != SLR_MAIN_DISPLAY) && (display != SLR_SUB_DISPLAY))
	{
		pr_err("\r\n set_cur_sclaer_source_num display(%d) error", display);
		return;
	}
#endif
	down(&vsc_src_verify_num_ctrl_sem);
	cur_vsc_src_num = source_connect_verify_num[display];
	up(&vsc_src_verify_num_ctrl_sem);

}

unsigned char compare_rerify_vsc_source_num_result(unsigned char display)
{//return TRUE: source not change.  return false: source change
#ifndef CONFIG_DUAL_CHANNEL
	if(display != SLR_MAIN_DISPLAY)
	{
		pr_err("\r\n rerify_vsc_source_num_result display(%d) error", display);
		return TRUE;
	}
#else
	if((display != SLR_MAIN_DISPLAY) && (display != SLR_SUB_DISPLAY))
	{
		pr_err("\r\n set_cur_sclaer_source_num display(%d) error", display);
		return TRUE;
	}
#endif
	down(&vsc_src_verify_num_ctrl_sem);
	if(cur_vsc_src_num == source_connect_verify_num[display])
	{
		up(&vsc_src_verify_num_ctrl_sem);
		return TRUE;
	}
	else
	{
		up(&vsc_src_verify_num_ctrl_sem);
		return FALSE;
	}

}
//Above is used to check run scaler source already change or not



static SCALER_ADAPTIVE_STREAM_INFO adaptive_streaming_info[2] = //This data is for scaler flow
{//This data is for adaptive streaming width and hight from application. 3 is total port number
	{-1, 0, 0, FALSE},
	{-1, 0, 0, FALSE},
};

unsigned char rtk_hal_vsc_GetOutputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * poutregion);

static StructSrcRect main_dispwin;//Temp record main output info
static StructSrcRect main_input_size;
static StructSrcRect main_dispwin_pre = {0, 0, 0, 0};//Record previous main output info
static StructSrcRect main_input_size_pre = {0, 0, 0, 0};//Record previous main output info
static StructSrcRect main_dispwin_for_only_xy = {0, 0, 0, 0};//Record previous main output info for apply_only_xy_shift

static VSC_INPUT_SRC_INFO_T DisplayModeInputInfo = {VSC_INPUTSRC_MAXN,0,0};
static VSC_INPUT_SRC_INFO_T VencModeInputInfo = {VSC_INPUTSRC_MAXN,0,0};
static VSC_INPUT_SRC_INFO_T MemoryModeInputInfo = {VSC_INPUTSRC_MAXN,0,0};
static VSC_INPUT_SRC_INFO_T AveModeInputInfo = {VSC_INPUTSRC_MAXN,0,0};

static DIRECT_VO_FRAME_ORIENTATION rotate_mode = DIRECT_VO_FRAME_ORIENTATION_DEFAULT; //this is the current rotate mode from webos
static DIRECT_VO_FRAME_ORIENTATION rotate_mode_pre = DIRECT_VO_FRAME_ORIENTATION_DEFAULT; //this is the last rotate mode from webos

//static unsigned char OuputDisplayMode = FALSE;
//static unsigned char OutputVencMode = FALSE;
//static unsigned char OutputMemoryMode = FALSE;
//static unsigned char OutputAveMode = FALSE;
//static unsigned char RGB444Mode = TRUE;
//static unsigned char VscMuteStatus = FALSE;
extern UINT8 TV006_WB_Pattern_En;
unsigned char OutpuLocalDimmingPatMode = FALSE;

//static unsigned char Main_AutoRunScaler = FALSE;//Mean when running scaler and set output again. let it auto run scaler. For ATV
//static char Main_Run_Scaler_flag = FALSE;//Mean that Scaler task to run main scaler
//static char Main_Output_Set_flag = FALSE;//Mean that set main setoutput region
//static char Main_force_frc_flag = FALSE;
//static char Main_force_frc_fs_flag = FALSE;
//static char Main_Scaler_Stop_flag = FALSE;//Mean that don't let task run main scaler. Because disconnet
//static char Main_ATV_Go_Smooth_Toggle_flag = FALSE;//Mean ATV current no mute, so can run smooth toggle
//static char Main_smooth_toggle_set_flag = FALSE;//Mean that Scaler task to run smooth toggle
//static char Main_ATV_PassThrought_output_flag = FALSE;//Mean ATV pass throught set output region. Let set winblank off work directly
//static char Main_Output_Set_flag_Special_Case = FALSE; //for Special case: set mute off=>set ARC need run scaler case.
//static char Main_SetOutput_request_muteoff_smooth_toggle_set_flag = FALSE;//Mean that wait mute off to set Main_smooth_toggle_set_flag
//static char Main_Request_ForceBG_ctrl = FALSE;//Mean webos call set main winblank on/off
#ifdef USE_FORCEBG_TASK
static DEFINE_SPINLOCK(Main_Request_ForceBG_ctrl_Spinlock);/*Spin lock no context switch. This is for Main_Request_ForceBG_ctrl*/
#endif
//static char Main_Reset_Mode_flag = FALSE;//Run Mode Reset mode
//static unsigned char Main_Reset_Mode_flag = FALSE;//Record during runing scaler. Can not mute off
#ifdef CONFIG_DUAL_CHANNEL
static StructSrcRect sub_dispwin;//Temp record sub output info
static StructSrcRect sub_input_size;
static StructSrcRect sub_dispwin_pre = {0, 0, 0, 0};//Record previour main output info
static StructSrcRect sub_input_size_pre = {0, 0, 0, 0};//Record previour main output info
static VSC_INPUT_SRC_INFO_T Sub_DisplayModeInputInfo = { VSC_INPUTSRC_MAXN, 0, 0 };
static VSC_INPUT_SRC_INFO_T Sub_VencModeInputInfo = { VSC_INPUTSRC_MAXN, 0, 0 };
static VSC_INPUT_SRC_INFO_T Sub_MemoryModeInputInfo = { VSC_INPUTSRC_MAXN, 0, 0 };
static VSC_INPUT_SRC_INFO_T Sub_AveModeInputInfo = { VSC_INPUTSRC_MAXN, 0, 0 };

//static unsigned char Sub_OuputDisplayMode = FALSE;
//static unsigned char Sub_OutputVencMode = FALSE;
//static unsigned char Sub_OutputMemoryMode = FALSE;
//static unsigned char Sub_OutputAveMode = FALSE;
//static char Sub_Run_Scaler_flag = FALSE;//Mean that Scaler task to run Sub scaler
//static char Sub_Output_Set_flag = FALSE;//Mean that set sub setoutput region
//static char Sub_Scaler_Stop_flag = FALSE;//Mean that don't let task run sub scaler. Because disconnet
//static unsigned char Sub_AutoRunScaler = FALSE;//Mean when running scaler and set output again. let it auto run scaler. For ATV
//static char Sub_ATV_Go_Smooth_Toggle_flag = FALSE;//Mean ATV current no mute, so can run smooth toggle
//static char Sub_Request_ForceBG_ctrl = FALSE;//Mean webos call set sub winblank on/off
#ifdef USE_FORCEBG_TASK
static DEFINE_SPINLOCK(Sub_Request_ForceBG_ctrl_Spinlock);/*Spin lock no context switch. This is for Sub_Request_ForceBG_ctrl*/
#endif
//static char Sub_Reset_Mode_flag = FALSE;//Run SUB Reset mode

#endif

extern unsigned short Main_InputRegion_x;
extern unsigned short Main_InputRegion_y;
extern unsigned short Main_InputRegion_w;
extern unsigned short Main_InputRegion_h;
#ifdef CONFIG_DUAL_CHANNEL
extern unsigned short Sub_InputRegion_x;
extern unsigned short Sub_InputRegion_y;
extern unsigned short Sub_InputRegion_w;
extern unsigned short Sub_InputRegion_h;
#endif




//unsigned short Main_ATV_InputRegion_x_pre;
//unsigned short Main_ATV_InputRegion_y_pre;
//unsigned short Main_ATV_InputRegion_w_pre;
//unsigned short Main_ATV_InputRegion_h_pre;
#ifdef CONFIG_DUAL_CHANNEL
//unsigned short Sub_ATV_InputRegion_x_pre;
//unsigned short Sub_ATV_InputRegion_y_pre;
//unsigned short Sub_ATV_InputRegion_w_pre;
//unsigned short Sub_ATV_InputRegion_h_pre;
#endif


//unsigned short Main_ATV_OutputRegion_x_pre;
//unsigned short Main_ATV_OutputRegion_y_pre;
//unsigned short Main_ATV_OutputRegion_w_pre;
//unsigned short Main_ATV_OutputRegion_h_pre;
#ifdef CONFIG_DUAL_CHANNEL
//unsigned short Sub_ATV_OutputRegion_x_pre;
//unsigned short Sub_ATV_OutputRegion_y_pre;
//unsigned short Sub_ATV_OutputRegion_w_pre;
//unsigned short Sub_ATV_OutputRegion_h_pre;
#endif

//unsigned char main_winfreeze;


//unsigned char JPEG_Scaler_SM;
extern void ADC_set_detect_flag(unsigned char enable);
extern void VDC_set_detect_flag(unsigned char enable);
extern unsigned char VDC_get_detect_flag(void);
extern void HDMI_set_detect_flag(unsigned char enable);
extern struct semaphore* get_adc_adjustsemaphore(void);
extern struct semaphore *get_adc_detectsemaphore(void);
extern struct semaphore *get_vdc_detectsemaphore(void);
extern struct semaphore *get_hdmi_detectsemaphore(void);
extern struct semaphore *get_setsource_semaphore(void);
extern struct semaphore* get_scaler_fll_running_semaphore(void);
extern StructDisplayInfo * Get_ADC_Dispinfo(void);
extern StructDisplayInfo * Get_AVD_ScalerDispinfo(void);
extern ModeInformationType *Get_AVD_ScalerTiminginfo(void);
extern StructDisplayInfo * Get_VO_Dispinfo(unsigned char);
extern unsigned char get_vfod_enablestatus(void);
extern struct semaphore* get_vo_infosemaphore(void);
extern unsigned char get_vo_change_flag(unsigned char);
extern void set_vo_change_flag(unsigned char, unsigned char);
extern unsigned char ADC_Check_VSC_VFE_ConnectSrc_Match(unsigned int vsc_src);
unsigned char init_source_proc(unsigned char display, VSC_INPUT_TYPE_T sourcetype, unsigned char sourceport);
void set_vsc_SetCircle_OutputRegion(VIDEO_RECT_T outregion, unsigned short W, unsigned short H, UINT32 num);

//unsigned int  sub_zoom_disp_hpos = 0;//For Scaler use
//unsigned int  sub_zoom_disp_vpos = 0;//For Scaler use
//unsigned int  sub_zoom_disp_hsize = 0;//For Scaler use
//unsigned int  sub_zoom_disp_vsize = 0;//For Scaler use
//static unsigned char sub_wind0000 = FALSE;
//static unsigned char main_wind0000 = FALSE;

//static unsigned char adaptive_stream;
//static unsigned char adaptive_stream_pre = ADAPTIVE_STREAM_INIT;
//static unsigned char line_cnt_no_run_hdmi_check = 0;

//unsigned char hdmi_dolby_vision_flag = FALSE; //for dm function to adjust hdmi dolby vision detect result

struct semaphore Memc_Realcinema_Semaphore;/*For adaptive streaming info Semaphore*/
//char memc_realcinema_run_flag = FALSE;//Run memc mode
extern void memc_realcinema_framerate(void);

struct semaphore Iv2dv_Slow_Tuning_Semaphore;
//char run_iv2dv_slow_tuning_flag = FALSE;//Run iv2dv slow tuning flag
extern void drv_run_GameMode_iv2dv_slow_tuning(void);
static UINT8 enable_VSC_GameMode = _DISABLE;

struct semaphore VPQ_ld_running_Semaphore;/*For adaptive streaming info Semaphore*/

struct semaphore VPQ_DeXC_MEM_Semaphore;/*For Dexc MEM*/

//I2RND semaphore
struct semaphore I2RND_Semaphore;
static unsigned char i2rnd_test_done = 0;

//static unsigned char vpq_ld_first_boot = FALSE; //dc off/on condition, set at resume
extern unsigned char vpq_ld_running_flag;
extern unsigned char vpq_led_LDEnable;
extern unsigned int ld_time_tick;
extern void drvif_HAL_VPQ_LED_LDEnable(unsigned char bCtrl);
extern unsigned char  fwif_color_get_black_detection_info_tv006(VIP_BlackDetectionInfo* BlackDetectionInfo);

#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
struct timer_list OrbitTimerList;
void Scaler_Orbit_Timer_Init(void);
void OrbitTimer(void);
void Scaler_Orbit_Timer_Delete(void);
static unsigned char g_ucTimerInitCount = 0;
#endif

// For Dolby letter box DTG change
extern spinlock_t* dolby_letter_box_spinlock(void);
extern unsigned int dolby_proverlay_background_h_start_end;//For letter box use.Record h start and end
extern unsigned int dolby_proverlay_background_v_start_end;//For letter box use. Record V start and end
extern unsigned char letter_box_black_flag;//For letter box use. Need force BG black
extern unsigned char request_letter_dtg_change;//For letter box use. Requesttsk to run
//
#ifdef CONFIG_I2RND_ENABLE
unsigned char vsc_i2rnd_sub_stage = I2RND_STAGE_DISABLE;
unsigned char vsc_i2rnd_sub_output_mode = 0;
unsigned char vsc_i2rnd_sub_input_type = 0;
unsigned char vsc_i2rnd_sub_input_port = 0;
static unsigned char vsc_i2rnd_initial_done = _DISABLE;
unsigned char vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_DISABLE; //for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823

#endif

struct semaphore* get_gamemode_check_semaphore(void)
{
	return &GameMode_Check_Semaphore;
}
//k4lp new hal api - mute off callback. When mute off to callback api
unsigned char main_muteoff_cb_trigger = FALSE;
unsigned char sub_muteoff_cb_trigger = FALSE;
struct semaphore muteoff_cb_sem;

StructSrcRect get_main_dispwin(void)
{
	return main_dispwin;
}

StructSrcRect get_main_input_size(void)
{
	return main_input_size;
}

void set_shiftxy_main_inputpre(StructSrcRect input_size )
{
	main_input_size_pre=input_size;
}

void set_shiftxy_main_dispwinpre(StructSrcRect out_size )
{
	main_dispwin_for_only_xy=out_size;
}

static DECLARE_WAIT_QUEUE_HEAD(MUTEOFF_CB_WAIT_QUEUE);

void wakeup_mute_off_callback(unsigned char display)
{//this is wake up to call webos callback function to notice mute off
	if(display == SLR_MAIN_DISPLAY)
	{
		down(&muteoff_cb_sem);
		main_muteoff_cb_trigger = TRUE;
		up(&muteoff_cb_sem);
	}
	else
	{
		down(&muteoff_cb_sem);
		sub_muteoff_cb_trigger = TRUE;
		up(&muteoff_cb_sem);
	}
	wake_up(&MUTEOFF_CB_WAIT_QUEUE);
}

#ifdef CONFIG_FORCE_RUN_I3DDMA
unsigned char force_i3ddma_enable = false;

void set_force_i3ddma_enable(UINT8 enable)
{
	force_i3ddma_enable = enable;
}

UINT8 get_force_i3ddma_enable(unsigned char display)
{
	if(display == SLR_MAIN_DISPLAY)
		return force_i3ddma_enable;
	else
		return 0;
}
#endif

VSC_SUB_MODE_T get_sub_mode(void)
{
//Get sub current mode
//PIP: Live zoom, magnifire
//PBP: Multiview
//default mode is pip
	return (VSC_SUB_MODE_T)sub_mode_type;
}

#ifdef CONFIG_HW_SUPPORT_MEMC
void wait_memc_ready(void)
{
	unsigned int sleep_time = 0;
	unsigned int output_framerate = 0;

	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ) &&  Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAC_FS_REMOVE_RATIO)
		&& Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAC_FS_MULTIPLE_RATIO))
		output_framerate = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ) * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAC_FS_MULTIPLE_RATIO) / (10 * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAC_FS_REMOVE_RATIO));
	else
		output_framerate = 60;


	sleep_time = MAX_MEMC_DELAY_BUFFER * 100 / output_framerate;
	msleep(sleep_time);
	printk(KERN_NOTICE "\r\n#### func:%s wait_time:%d framerate:(%d %d %d)####\r\n",__FUNCTION__, sleep_time, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ),  Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAC_FS_REMOVE_RATIO), Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAC_FS_MULTIPLE_RATIO));
}
#endif


VSC_SUB_SHAPE_T get_shape_mode(void)
{

	return (VSC_SUB_SHAPE_T)sub_shape_type;
}


void set_vsc_debug_mode(unsigned char TorF)
{
	vsc_debug_mode = TorF;
}

void reset_adaptive_streaming_info(unsigned char display)
{
	int i;
	down(&Adaptive_Streaming_Semaphore);
	for(i = 0; i < 2; i++)//port number is 0, 1
	{
		if(adaptive_streaming_info[i].display == display)
			break;
	}
	if(i == 2)
	{
		up(&Adaptive_Streaming_Semaphore);
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"####Reset info fail. No connect channel[%d] for adaptive stream####\r\n", display);
		return;
	}

	adaptive_streaming_info[i].display = -1;
	adaptive_streaming_info[i].width = 0;
	adaptive_streaming_info[i].height = 0;
	adaptive_streaming_info[i].update_flag = FALSE;
	up(&Adaptive_Streaming_Semaphore);

}


void get_adaptive_streaming_info_from_app(unsigned char display, unsigned short *p_width, unsigned short *p_height)
{

	int i;
	for(i = 0; i < 2; i++)//port number is 0, 1
	{
		if(adaptive_streaming_info[i].display == display)
			break;
	}
	if(i == 2)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"\r\n####Get info fail. No connect channel[%d] for adaptive stream####\r\n", display);
		*p_width = 0;
		*p_height = 0;
		return;
	}
	*p_width = adaptive_streaming_info[i].width;
	*p_height = adaptive_streaming_info[i].height;

}

StructSrcRect Scaler_SubDispWindowGet(void)
{
	StructSrcRect subWindow;
	subWindow.srcx = DbgSclrFlgTkr.sub_zoom_disp_hpos;
	subWindow.srcy = DbgSclrFlgTkr.sub_zoom_disp_vpos;
	subWindow.src_wid = DbgSclrFlgTkr.sub_zoom_disp_hsize;
	subWindow.src_height = DbgSclrFlgTkr.sub_zoom_disp_vsize;
	return subWindow;
}

void Scaler_SubDispWindowSet(StructSrcRect subWindow)
{
	DbgSclrFlgTkr.sub_zoom_disp_hpos = subWindow.srcx;
	DbgSclrFlgTkr.sub_zoom_disp_vpos = subWindow.srcy;
	DbgSclrFlgTkr.sub_zoom_disp_hsize = subWindow.src_wid;
	DbgSclrFlgTkr.sub_zoom_disp_vsize = subWindow.src_height;
}

unsigned char get_sub_OutputVencMode(void)
{
	return DbgSclrFlgTkr.Sub_OutputVencMode;
}

unsigned char get_main_OutputVencMode(void)
{
	return DbgSclrFlgTkr.OutputVencMode;
}

void set_atv_go_smooth_toggle_flag(unsigned char display, unsigned char flag)
{
	if (display == SLR_MAIN_DISPLAY)
		DbgSclrFlgTkr.Main_ATV_Go_Smooth_Toggle_flag = flag;
#ifdef CONFIG_DUAL_CHANNEL
	else
		DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag = flag;
#endif
}

unsigned char rtk_rerun_scaler(SCALER_DISP_CHANNEL channel);

VSC_INPUT_TYPE_T Get_DisplayMode_Src(unsigned char display)
{
#ifdef CONFIG_DUAL_CHANNEL
	if (display == SLR_MAIN_DISPLAY) {
		if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return DisplayModeInputInfo.type;
		else if (VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return VencModeInputInfo.type;
		else if (MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return  MemoryModeInputInfo.type;
		else if (AveModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return AveModeInputInfo.type;
		else
			return DisplayModeInputInfo.type;
	} else {
		if(Sub_DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return Sub_DisplayModeInputInfo.type;
		else if (Sub_VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return Sub_VencModeInputInfo.type;
		else if (Sub_MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return  Sub_MemoryModeInputInfo.type;
		else if (Sub_AveModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return Sub_AveModeInputInfo.type;
		else
			return Sub_DisplayModeInputInfo.type;
}
#else
	if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
		return DisplayModeInputInfo.type;
	else if (VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		return VencModeInputInfo.type;
	else if (MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		return  MemoryModeInputInfo.type;
	else if (AveModeInputInfo.type != VSC_INPUTSRC_MAXN)
		return AveModeInputInfo.type;
	else
	return DisplayModeInputInfo.type;
#endif
}

unsigned char Get_DisplayMode_Port(unsigned char display)
{
#ifdef CONFIG_DUAL_CHANNEL
	if (display == SLR_MAIN_DISPLAY) {
		if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN) {
#ifdef CONFIG_FORCE_RUN_I3DDMA
			if((DisplayModeInputInfo.type != VSC_INPUTSRC_VDEC) && (DisplayModeInputInfo.type != VSC_INPUTSRC_JPEG))
			{
				return 0;//Vo port is always 0 for all source go i3ddma
			}
#else
			if(DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI)
			{
				if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_THROUGH_I3DDMA))
				{
					return 0;//Vo port is always 0 for hdmi hdr case
				}
			}
#endif
			return DisplayModeInputInfo.resourceIndex;
		}
		else if (VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return VencModeInputInfo.resourceIndex;
		else if (MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return  MemoryModeInputInfo.resourceIndex;
		else if (AveModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return AveModeInputInfo.resourceIndex;
		else
			return DisplayModeInputInfo.resourceIndex;
	} else {
		if(Sub_DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return Sub_DisplayModeInputInfo.resourceIndex;
		else if (Sub_VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return Sub_VencModeInputInfo.resourceIndex;
		else if (Sub_MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return  Sub_MemoryModeInputInfo.resourceIndex;
		else if (Sub_AveModeInputInfo.type != VSC_INPUTSRC_MAXN)
			return Sub_AveModeInputInfo.resourceIndex;
		else
			return Sub_DisplayModeInputInfo.resourceIndex;
}
#else
	if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN) {
#ifdef CONFIG_FORCE_RUN_I3DDMA
		if((DisplayModeInputInfo.type != VSC_INPUTSRC_VDEC) && (DisplayModeInputInfo.type != VSC_INPUTSRC_JPEG))
		{
			return 0;//Vo port is always 0 for all source go i3ddma
		}
#else
		if(DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI)
		{
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_THROUGH_I3DDMA))
			{
				return 0;//Vo port is always 0 for hdmi hdr case
			}
		}
#endif
		return DisplayModeInputInfo.resourceIndex;
	}
	else if (VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		return VencModeInputInfo.resourceIndex;
	else if (MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		return  MemoryModeInputInfo.resourceIndex;
	else if (AveModeInputInfo.type != VSC_INPUTSRC_MAXN)
		return AveModeInputInfo.resourceIndex;
	else
		return DisplayModeInputInfo.resourceIndex;
#endif
}

unsigned char get_output_set_flag(unsigned char display)
{
#ifdef CONFIG_DUAL_CHANNEL
	return ((display == SLR_MAIN_DISPLAY) ? DbgSclrFlgTkr.Main_Output_Set_flag : DbgSclrFlgTkr.Sub_Output_Set_flag);
#else
	return DbgSclrFlgTkr.Main_Output_Set_flag;
#endif
}

unsigned char get_scaler_stop_flag(unsigned char display)
{
#ifdef CONFIG_DUAL_CHANNEL
	return ((display == SLR_MAIN_DISPLAY) ? DbgSclrFlgTkr.Main_Scaler_Stop_flag : DbgSclrFlgTkr.Sub_Scaler_Stop_flag);
#else
	return DbgSclrFlgTkr.Main_Scaler_Stop_flag;
#endif
}

unsigned char check_input_and_output_the_same(unsigned char display)
{//True: The same. False: The different
	unsigned char result = TRUE;
	if(display == SLR_MAIN_DISPLAY) {
		if((main_input_size_pre.srcx != main_input_size.srcx) || (main_input_size_pre.srcy != main_input_size.srcy) ||
			(main_input_size_pre.src_height != main_input_size.src_height) || (main_input_size_pre.src_wid != main_input_size.src_wid)) {
			result = FALSE;
			main_input_size_pre.srcx = main_input_size.srcx;
			main_input_size_pre.srcy = main_input_size.srcy;
			main_input_size_pre.src_height = main_input_size.src_height;
			main_input_size_pre.src_wid = main_input_size.src_wid;
		}
		if((main_dispwin_pre.srcx != main_dispwin.srcx) || (main_dispwin_pre.srcy != main_dispwin.srcy) ||
			(main_dispwin_pre.src_height != main_dispwin.src_height) || (main_dispwin_pre.src_wid != main_dispwin.src_wid)) {
			result = FALSE;
			main_dispwin_pre.srcx = main_dispwin.srcx;
			main_dispwin_pre.srcy = main_dispwin.srcy;
			main_dispwin_pre.src_height = main_dispwin.src_height;
			main_dispwin_pre.src_wid = main_dispwin.src_wid;
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	else
	{
		if((sub_input_size_pre.srcx != sub_input_size.srcx) || (sub_input_size_pre.srcy != sub_input_size.srcy) ||
			(sub_input_size_pre.src_height != sub_input_size.src_height) || (sub_input_size_pre.src_wid != sub_input_size.src_wid)) {
			result = FALSE;
			sub_input_size_pre.srcx = sub_input_size.srcx;
			sub_input_size_pre.srcy = sub_input_size.srcy;
			sub_input_size_pre.src_height = sub_input_size.src_height;
			sub_input_size_pre.src_wid = sub_input_size.src_wid;
		}
		if((sub_dispwin_pre.srcx != sub_dispwin.srcx) || (sub_dispwin_pre.srcy != sub_dispwin.srcy) ||
			(sub_dispwin_pre.src_height != sub_dispwin.src_height) || (sub_dispwin_pre.src_wid != sub_dispwin.src_wid)) {
			result = FALSE;
			sub_dispwin_pre.srcx = sub_dispwin.srcx;
			sub_dispwin_pre.srcy = sub_dispwin.srcy;
			sub_dispwin_pre.src_height = sub_dispwin.src_height;
			sub_dispwin_pre.src_wid = sub_dispwin.src_wid;
		}
	}
#else
	result = FALSE;
#endif
	return result;
}

void reset_any_srcrect(StructSrcRect *p_srcrect)
{
	if(p_srcrect) {
		p_srcrect->srcx = 0;
		p_srcrect->srcy = 0;
		p_srcrect->src_height = 0;
		p_srcrect->src_wid = 0;
	}
}

void set_source_info_forPQ(unsigned char display)
{
	VSC_OUTPUT_MODE_T outputMode;
	VSC_INPUT_TYPE_T inputType = VSC_INPUTSRC_MAXN;
	unsigned char inputPort = 0;

	if (display == SLR_MAIN_DISPLAY) {
		if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_DISPLAY_MODE;
			inputType = DisplayModeInputInfo.type;
			inputPort = DisplayModeInputInfo.resourceIndex;
		}
		else if(VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_VENC_MODE;
			inputType = VencModeInputInfo.type;
			inputPort = VencModeInputInfo.resourceIndex;
		}
		else if(MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_MEMORY_MODE;
			inputType = MemoryModeInputInfo.type;
			inputPort = MemoryModeInputInfo.resourceIndex;
		}
		else
		{
			return;
		}
		//Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);//No need
		if (DbgSclrFlgTkr.main_opensourceID == _UNKNOWN_INPUT) {
			if (init_source_proc(SLR_MAIN_DISPLAY, inputType, inputPort) == FALSE) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"\r\n######init_source_proc fail fail#####\r\n");
				DbgSclrFlgTkr.main_opensourceID = _UNKNOWN_INPUT;
				return;
			}
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if (display == SLR_SUB_DISPLAY){
		if(Sub_DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_DISPLAY_MODE;
			inputType = Sub_DisplayModeInputInfo.type;
			inputPort = Sub_DisplayModeInputInfo.resourceIndex;
		}
		else if(Sub_VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_VENC_MODE;
			inputType = Sub_VencModeInputInfo.type;
			inputPort = Sub_VencModeInputInfo.resourceIndex;
		}
		else if(Sub_MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_MEMORY_MODE;
			inputType = Sub_MemoryModeInputInfo.type;
			inputPort = Sub_MemoryModeInputInfo.resourceIndex;
		}
		else
		{
			return;
		}

		//Scaler_SetCurrentDispInfo(SLR_SUB_DISPLAY);//No need
		if (DbgSclrFlgTkr.sub_opensourceID == _UNKNOWN_INPUT) {
			if (init_source_proc(SLR_SUB_DISPLAY, inputType, inputPort) == FALSE) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"\r\n######init_source_proc fail fail#####\r\n");
				DbgSclrFlgTkr.sub_opensourceID = _UNKNOWN_INPUT;
				return;
			}
		}
	}
#endif
}


unsigned judge_scaler_break_case(unsigned char display)
{//Return True: break. False:No break
	unsigned char src;
	VSC_INPUT_TYPE_T webos_src;
	webos_src = Get_DisplayMode_Src(display);
	src = Scaler_InputSrcGetType(display);
	if (get_scaler_stop_flag(display)) {
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####channel:%d vsc already disconnect !!!####\r\n", display);
		return TRUE;
	}
	else if(!compare_rerify_vsc_source_num_result(display))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "### judge_scaler_break_case source(%d) already change###\r\n", display);
		return TRUE;
	}
#ifdef CONFIG_FORCE_RUN_I3DDMA
	else if((display == SLR_MAIN_DISPLAY) &&
		((webos_src == VSC_INPUTSRC_ADC) ||(webos_src == VSC_INPUTSRC_AVD) || (webos_src == VSC_INPUTSRC_HDMI))
	)
	{
		if((webos_src == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
		{
			return FALSE;//ATV don't check dma online status
		}
		else if(drvif_mode_check_dma_onlinemeasure_status() == FALSE) {
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####dma online error status:%08x!!!####\r\n", IoReg_Read32(ONMS_onms3_status_reg));
			return TRUE;
		}
		else if(webos_src == VSC_INPUTSRC_HDMI)
    	{
    		if(get_ori_HDMI_HDR_mode() != get_HDMI_HDR_mode()){
                rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"\r\nHDMI HDR (%d %d) not match so break !!!####\r\n", get_ori_HDMI_HDR_mode(), get_HDMI_HDR_mode());
			    return TRUE;
            }
        }
	}
#endif
	else if(src == _SRC_VO) {
		if(get_vo_change_flag(Get_DisplayMode_Port(display))) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d vo already update !!!####\r\n", display);
			return TRUE;
		}
#ifndef CONFIG_FORCE_RUN_I3DDMA
		if((display == SLR_MAIN_DISPLAY) && (webos_src == VSC_INPUTSRC_HDMI))
    	{
    		if(get_ori_HDMI_HDR_mode() != get_HDMI_HDR_mode()){
                rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"\r\nHDMI HDR (%d %d) not match so break !!!####\r\n", get_ori_HDMI_HDR_mode(), get_HDMI_HDR_mode());
			    return TRUE;
            }
        }
#endif
	} else {
		if(drvif_mode_check_onlinemeasure_status(display) == FALSE) {
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####channel:%d online error status:%08x!!!####\r\n", display, IoReg_Read32(ONMS_onms1_status_reg));
			return TRUE;
		}
#ifndef CONFIG_FORCE_RUN_I3DDMA
		if((display == SLR_MAIN_DISPLAY) && (webos_src == VSC_INPUTSRC_HDMI))
    	{
    		if(get_ori_HDMI_HDR_mode() != get_HDMI_HDR_mode()){
                rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"\r\nHDMI HDR (%d %d) not match so break !!!####\r\n", get_ori_HDMI_HDR_mode(), get_HDMI_HDR_mode());
			    return TRUE;
            }
        }
#endif
	}
	return FALSE;
}

void Scaler_Dolby_HDR_reset(void){
	//Reset DM control
	drvif_Dolby_HDR_disable_DM_LUT();//disable DM LUT @Crixus 20160313
}
void reset_hdr_mode(void)
{//Disable v top setting
	dolby_v_top_top_ctl_RBUS top_ctl_reg;
	dolby_v_top_top_d_buf_RBUS dolby_v_top_top_d_buf_Reg;
	top_ctl_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg);
	dolby_v_top_top_d_buf_Reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_D_BUF_reg);
	dolby_v_top_top_d_buf_Reg.dolby_v_read_sel = 1;
	top_ctl_reg.dolby_mode = 0;
	IoReg_Write32(DOLBY_V_TOP_TOP_D_BUF_reg, dolby_v_top_top_d_buf_Reg.regValue);

	IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);//Disable dolby mode
	IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT1);//Enable doublue buffer
#ifdef CONFIG_RTK_KDRV_QOS_CONTROL
	rtk_qos_set_mode(RTK_QOS_NORMAL_MODE);
#endif

}

void decide_hdr_mode(void)
{//Decide HDR setting
	unsigned char directvo_hdr10_flag = FALSE;
	dolby_v_top_top_ctl_RBUS top_ctl_reg;
	top_ctl_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg);
	//_system_setting_info *VIP_system_info_structure_table;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;

#ifdef CONFIG_RTK_KDRV_QOS_CONTROL
    // [WOSQRTK-10007][BW] improve HDMI 4k2kp60 bandwidth
    if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
        && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE) >= 3800)
        && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ) > 480)
        && ((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_SPACE) == I3DDMA_COLOR_YUV444)
            || (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_SPACE) == I3DDMA_COLOR_RGB)))
    {
        rtk_qos_set_mode(RTK_QOS_HDMI_4K_MODE);
    }else{
        rtk_qos_set_mode(RTK_QOS_DECODER_MODE);
    }
#endif

	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
	{
		if((get_HDMI_HDR_mode() == HDR_DOLBY_HDMI) || (get_HDMI_HDR_mode() == HDR_HDR10_HDMI))
		{//HDMI dolby or HDR10 mdoe
			top_ctl_reg.dolby_mode = 1;
			top_ctl_reg.hdmi_in_mux = 1;
			top_ctl_reg.dolby_ratio = 0;
			if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI)
			{
				top_ctl_reg.en_422to444_1 = 1;
			} else if (get_HDMI_HDR_mode() == HDR_HDR10_HDMI) {
				top_ctl_reg.en_422to444_1 = 0;/*for HDR10*/
			}

			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue); //HDMI dolby mode or HDR10 mode
			IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT1);//Enable doublue buffer
		}
		if (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)
		{
			if(!Scaler_color_Get_HDR_AutoRun())
				fwif_color_set_HDR_TV006();
			set_HDR10_DM_setting();
			Scaler_Dolby_HDR_reset();//disable B02 LUT
#if 0
#ifdef CONFIG_HDR_SDR_SEAMLESS
			fwif_color_SetDataFormatHandler_tv006();
			Scaler_hdr_setting_SEAMLESS(TRUE);
#endif
		}else{
#ifdef CONFIG_HDR_SDR_SEAMLESS
			fwif_color_SetDataFormatHandler_tv006();
			Scaler_hdr_setting_SEAMLESS(FALSE);
#endif
#endif
		}
		if (get_HDMI_HDR_mode() == HDR_DOLBY_HDMI)
		{//K3LG-1046 noise screen
			dm_dm_b05_lut_ctrl2_RBUS dm_dm_b05_lut_ctrl2_Reg;
			dm_dm_b05_lut_ctrl2_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL2_reg);
			dm_dm_b05_lut_ctrl2_Reg.dm_b05_dimension = 0;//reset to 0(table 17*17*17*3);
			IoReg_Write32(DM_DM_B05_LUT_CTRL2_reg, dm_dm_b05_lut_ctrl2_Reg.regValue);

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
			//for set dolby hdmi from  vo drvif_hdr_idma_enable
		    HDR_IDMA_HANDLER hdrIdma_hdl;
			vgip_vgip_chn1_act_hsta_width_RBUS vgip_chn1_act_hsta_width_reg;
			vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_length_reg;

			vgip_chn1_act_hsta_width_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
			vgip_chn1_act_vsta_length_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);

			// [FIX-ME] MUST CHANGE TO HDMI CONFIG PICTURE WIDTH/HEIGHT TO AVOID WRONG IDMA SETTING
			hdrIdma_hdl.inSize.nWidth = hdrIdma_hdl.capSize.nWidth = vgip_chn1_act_hsta_width_reg.ch1_ih_act_wid;
			hdrIdma_hdl.inSize.nLength = hdrIdma_hdl.capSize.nLength = vgip_chn1_act_vsta_length_reg.ch1_iv_act_len;

			pr_debug("[HDR.V] IDMA Setup...\n");
			pr_debug("[HDR] In/Out[(%d,%d)->(%d,%d)] in decide_hdr_mode\n",
			hdrIdma_hdl.inSize.nWidth, hdrIdma_hdl.inSize.nLength, hdrIdma_hdl.capSize.nWidth, hdrIdma_hdl.capSize.nLength);

			//drvif_hdr_idma_vgip_config();
			#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT  //DolbyHDR_fix_me!!
			drvif_hdr_idma_color_colorspacergb2yuvtransfer();
			drvif_hdr_idma_ultrazoom_config_scaling_down(&hdrIdma_hdl.inSize, &hdrIdma_hdl.capSize, 0);
			#endif
#endif
		}
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
		VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
		if(VIP_RPC_system_info_structure_table)
			directvo_hdr10_flag = VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] ? TRUE : FALSE;

		if(directvo_hdr10_flag)
		{//Playback HDR10 mode
			if(drvif_HDR_get_VO_Decompress_Status())
			{//Playback HDR10 mode and compress mode
				top_ctl_reg.dolby_mode = 3;
				top_ctl_reg.hdmi_in_mux = 0;
				top_ctl_reg.dolby_ratio = 0;
				IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue); //Playback dolbymode and compress
				IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT1);//Enable doublue buffer
			}
			else
			{//Playback HDR10 mode and no compress mode
				top_ctl_reg.dolby_mode = 1;
				top_ctl_reg.hdmi_in_mux = 1;
				top_ctl_reg.dolby_ratio = 0;
				IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue); //Playback dolbymode and no compress
				IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT1);//Enable doublue buffer
			}

			top_ctl_reg.en_422to444_1 = 0;/*for HDR10*/
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue);

			if(!Scaler_color_Get_HDR_AutoRun())
				fwif_color_set_HDR_TV006();
			set_HDR10_DM_setting();
			Scaler_Dolby_HDR_reset();//disable B02 LUT

		}
		else if(get_OTT_HDR_mode() == HDR_DOLBY_COMPOSER)
		{//dolby OTT mode

			//reset color space for dolby OTT in case webos not set	//WOSQRTK-7184
			vgip_vgip_chn1_misc_RBUS vgip_chn1_misc_reg;
			vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);
			vgip_chn1_misc_reg.ch1_v1_v3_swap = 0;
			vgip_chn1_misc_reg.ch1_v2_v3_swap = 0;
			vgip_chn1_misc_reg.ch1_v1_v2_swap = 0;
			IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);

			top_ctl_reg.dolby_mode = 2;
			top_ctl_reg.dolby_ratio = 1;
			top_ctl_reg.hdmi_in_mux = 0;
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue); //Playback dolbymode and compress
			IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT1);//Enable doublue buffer

	        //K3LG-1046 noise screen
		    dm_dm_b05_lut_ctrl2_RBUS dm_dm_b05_lut_ctrl2_Reg;
			dm_dm_b05_lut_ctrl2_Reg.regValue = rtd_inl(DM_DM_B05_LUT_CTRL2_reg);
            dm_dm_b05_lut_ctrl2_Reg.dm_b05_dimension = 0;//reset to 0(table 17*17*17*3);
            IoReg_Write32(DM_DM_B05_LUT_CTRL2_reg, dm_dm_b05_lut_ctrl2_Reg.regValue);
		} else//sdr case		
		{//for hbbtv patch
			top_ctl_reg.en_422to444_1 = 1;//sdr set 422 to 44
			IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue); //VDEC SDR setting
			IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT1);// doublue buffer apply
		}

	}
	rtd_printk(KERN_INFO, TAG_NAME_VSC, "decide_hdr_mode, display_src=%d, hdmi_hdr=%d, directvo_hdr10_flag=%d, compress_status=%d, OTT_HDR=%d, auto_run=%d\n",
		Get_DisplayMode_Src(SLR_MAIN_DISPLAY), get_HDMI_HDR_mode(), directvo_hdr10_flag, drvif_HDR_get_VO_Decompress_Status(), get_OTT_HDR_mode(), Scaler_color_Get_HDR_AutoRun());
}

#ifdef CONFIG_HDR_SDR_SEAMLESS
void dynamic_change_hdr_setting(unsigned char hdr_enable)
{
	down(&HDR_Setting_Semaphore);
	IoReg_ClearBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT0);		//disable double buffer

	dolby_v_top_top_ctl_RBUS top_ctl_reg;
	top_ctl_reg.regValue = IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg);
	if(hdr_enable)
	{
		top_ctl_reg.en_422to444_1 = 0;//hdr don't enable 422 to 444
	}
	else
	{
		top_ctl_reg.en_422to444_1 = 1;
	}
	IoReg_Write32(DOLBY_V_TOP_TOP_CTL_reg, top_ctl_reg.regValue); //Set vtop setting
	IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT1);//Enable doublue buffer

	Scaler_hdr_setting_SEAMLESS(hdr_enable);

	IoReg_SetBits(DOLBY_V_TOP_TOP_D_BUF_reg, _BIT0);			//enable double buffer
	up(&HDR_Setting_Semaphore);
}

struct semaphore *get_hdr_setting_semaphore(void)
{
	return &HDR_Setting_Semaphore;
}

#endif

static void apvr_request_run_main_path(void)
{//This api is for apvr need to run main path again

	//reset i2rnd and pst write point when rerun scaler flow @Crixus 20180819
#ifdef CONFIG_I2RND_ENABLE
	//enable I2rnd
	if (Scaler_I2rnd_get_enable()) {
		Scaler_i2rnd_write_default_cmd_num();
		Scaler_I2rnd_set_read_cmd_num(0);
	}
#endif
#ifdef CONFIG_PST_ENABLE
	//enable pst
	if (Scaler_main_md_pst_get_enable()) {
		Scaler_pst_main_md_write_default_cmd_num();
		Scaler_pst_main_md_set_read_cmd_num(0);
	}
#endif

	if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE)
	{
		down(get_forcebg_semaphore());
		scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
		up(get_forcebg_semaphore());
	}
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);//Let main path to search state. In order to request VO
	down(&SetMainOutPutRegion_Semaphore);
	DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;//Let main path run scaler again
	up(&SetMainOutPutRegion_Semaphore);
}

unsigned char get_vsc_mutestatus(void)
{
	return DbgSclrFlgTkr.VscMuteStatus;
}

void Scaler_SET_VSCDispinfo_WithVFEHMDI(unsigned char display, vfe_hdmi_timing_info_t vfehdmitiminginfo)
{
	//Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_ADC_CLOCK, VFEDispInfo->INPUT_ADC_CLOCK);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN_PRE, vfehdmitiminginfo.active.h);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA_PRE, vfehdmitiminginfo.active.y+vfehdmitiminginfo.y_offset);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_WID_PRE, vfehdmitiminginfo.active.w);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_STA_PRE, vfehdmitiminginfo.active.x+vfehdmitiminginfo.x_offset);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_HSYNC, vfehdmitiminginfo.hsync);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_VSYNC, vfehdmitiminginfo.vsync);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MODE_CURR, vfehdmitiminginfo.mode_id);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MODE_TABLE_INDEX, vfehdmitiminginfo.mode_table_index);

	//Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_AFD, VFEDispInfo->afd);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_POLARITY, vfehdmitiminginfo.polarity);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_H_FREQ, vfehdmitiminginfo.h_freq);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_FREQ, vfehdmitiminginfo.v_freq);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_H_LEN, vfehdmitiminginfo.h_total);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_LEN, vfehdmitiminginfo.v_total);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_H_COUNT, vfehdmitiminginfo.h_total);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_COUNT, vfehdmitiminginfo.v_total);
	//Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IHSYNCPULSECOUNT, VFEDispInfo->IHSyncPulseCount);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_COLOR_SPACE, vfehdmitiminginfo.color_space);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_COLOR_DEPTH, vfehdmitiminginfo.color_depth);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_COLOR_IMETRY, vfehdmitiminginfo.color_imetry);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_IVSYNCPULSECOUNT, vfehdmitiminginfo.IVSyncPulseCount);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_V_SYNC_HIGH_PERIOD, vfehdmitiminginfo.polarity);

	Scaler_DispSetStatus(display, SLR_DISP_422, (vfehdmitiminginfo.color_space==VFE_HDMI_COLOR_YUV422) ? 1 : 0);
	Scaler_DispSetStatus(display, SLR_DISP_INTERLACE,  (!vfehdmitiminginfo.scan_type));
	//Scaler_DispSetStatus(display, SLR_DISP_INTERLACE,FALSE);

#if 0//frank@20141103 mark below code to reduce time
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_ADC_CLOCK:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_ADC_CLOCK));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPV_ACT_LEN_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPV_ACT_STA_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPH_ACT_WID_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPH_ACT_STA_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_HSYNC:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_HSYNC));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_VSYNC:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_VSYNC));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_MODE_CURR:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_MODE_TABLE_INDEX:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_TABLE_INDEX));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_AFD:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_AFD));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_POLARITY:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_POLARITY));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_FREQ:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_H_FREQ));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_FREQ:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_LEN:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_H_LEN));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_LEN:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_V_LEN));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_COUNT:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_H_COUNT));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_COUNT:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_V_COUNT));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IHSYNCPULSECOUNT:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IHSYNCPULSECOUNT));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_SPACE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_COLOR_SPACE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_DEPTH:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_COLOR_DEPTH));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_IMETRY:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_COLOR_IMETRY));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_DISP_422:%d\n", Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_422));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_DISP_INTERLACE:%d\n", Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE));
#endif
}

void Scaler_SET_VSCSubDispinfo_Withmain(void)
{
	//Scaler_DispSetInputInfo(SLR_INPUT_ADC_CLOCK, VFEDispInfo->INPUT_ADC_CLOCK);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE));
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE));
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE));

	Scaler_DispSetInputInfo(SLR_INPUT_HSYNC, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_HSYNC));
	Scaler_DispSetInputInfo(SLR_INPUT_VSYNC, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_VSYNC));

	Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_CURR));
	Scaler_DispSetInputInfo(SLR_INPUT_MODE_TABLE_INDEX, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_TABLE_INDEX));

	//Scaler_DispSetInputInfo(SLR_INPUT_AFD, VFEDispInfo->afd);

	Scaler_DispSetInputInfo(SLR_INPUT_POLARITY, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_POLARITY));
	Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_FREQ));
	Scaler_DispSetInputInfo(SLR_INPUT_V_FREQ, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ));
	Scaler_DispSetInputInfo(SLR_INPUT_H_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_LEN));
	Scaler_DispSetInputInfo(SLR_INPUT_V_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_LEN));
	Scaler_DispSetInputInfo(SLR_INPUT_H_COUNT, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_COUNT));
	Scaler_DispSetInputInfo(SLR_INPUT_V_COUNT, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_COUNT));
	//Scaler_DispSetInputInfo(SLR_INPUT_IHSYNCPULSECOUNT, VFEDispInfo->IHSyncPulseCount);

	Scaler_DispSetInputInfo(SLR_INPUT_COLOR_SPACE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_SPACE));
	Scaler_DispSetInputInfo(SLR_INPUT_COLOR_DEPTH, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_DEPTH));
	Scaler_DispSetInputInfo(SLR_INPUT_COLOR_IMETRY, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_IMETRY));

	Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_422, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422));
	Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE));
	//Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE,FALSE);

#if 0//frank@20141103 mark below code to reduce time
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_ADC_CLOCK:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_ADC_CLOCK));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPV_ACT_LEN_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPV_ACT_STA_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPH_ACT_WID_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPH_ACT_STA_PRE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_HSYNC:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_HSYNC));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_VSYNC:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_VSYNC));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_MODE_CURR:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_MODE_TABLE_INDEX:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_TABLE_INDEX));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_AFD:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_AFD));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_POLARITY:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_POLARITY));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_FREQ:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_H_FREQ));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_FREQ:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_LEN:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_H_LEN));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_LEN:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_V_LEN));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_COUNT:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_H_COUNT));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_COUNT:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_V_COUNT));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IHSYNCPULSECOUNT:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_IHSYNCPULSECOUNT));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_SPACE:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_COLOR_SPACE));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_DEPTH:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_COLOR_DEPTH));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_IMETRY:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_COLOR_IMETRY));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_DISP_422:%d\n", Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_422));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC timing info from VFE:SLR_DISP_INTERLACE:%d\n", Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE));
#endif
}

void Scaler_SET_VSCDispinfo_WithVFEHMDIHDR( vfe_hdmi_timing_info_t vfehdmitiminginfo)
{
	//Scaler_DispSetInputInfo(SLR_INPUT_ADC_CLOCK, VFEDispInfo->INPUT_ADC_CLOCK);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE, vfehdmitiminginfo.active.h);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE, vfehdmitiminginfo.active.y+vfehdmitiminginfo.y_offset);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE, vfehdmitiminginfo.active.w);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE, vfehdmitiminginfo.active.x+vfehdmitiminginfo.x_offset);

	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_HSYNC, vfehdmitiminginfo.hsync);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_VSYNC, vfehdmitiminginfo.vsync);

	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_CURR, vfehdmitiminginfo.mode_id);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_TABLE_INDEX, vfehdmitiminginfo.mode_table_index);

	//Scaler_DispSetInputInfo(SLR_INPUT_AFD, VFEDispInfo->afd);

	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_POLARITY, vfehdmitiminginfo.polarity);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_FREQ, vfehdmitiminginfo.h_freq);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ, vfehdmitiminginfo.v_freq);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_LEN, vfehdmitiminginfo.h_total);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_LEN, vfehdmitiminginfo.v_total);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_COUNT, vfehdmitiminginfo.h_total);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_COUNT, vfehdmitiminginfo.v_total);
	//Scaler_DispSetInputInfo(SLR_INPUT_IHSYNCPULSECOUNT, VFEDispInfo->IHSyncPulseCount);

	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_SPACE, vfehdmitiminginfo.color_space);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_DEPTH, vfehdmitiminginfo.color_depth);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_IMETRY, vfehdmitiminginfo.color_imetry);

	Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422, (vfehdmitiminginfo.color_space == VFE_HDMI_COLOR_YUV422) ? 1 : 0);
	Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE,  (!vfehdmitiminginfo.scan_type));
	//Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE,FALSE);

#if 0//frank@20141103 mark below code to reduce time
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_ADC_CLOCK:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_ADC_CLOCK));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPV_ACT_LEN_PRE:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPV_ACT_STA_PRE:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPH_ACT_WID_PRE:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IPH_ACT_STA_PRE:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_HSYNC:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_HSYNC));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_VSYNC:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_VSYNC));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_MODE_CURR:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_CURR));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_MODE_TABLE_INDEX:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_TABLE_INDEX));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_AFD:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_AFD));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_POLARITY:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_POLARITY));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_FREQ:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_FREQ));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_FREQ:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_LEN:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_LEN));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_LEN:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_LEN));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_H_COUNT:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_COUNT));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_V_COUNT:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_COUNT));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_IHSYNCPULSECOUNT:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IHSYNCPULSECOUNT));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_SPACE:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_SPACE));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_DEPTH:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_DEPTH));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_INPUT_COLOR_IMETRY:%d\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_COLOR_IMETRY));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_DISP_422:%d\n", Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422));
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "VSC timing info from VFE:SLR_DISP_INTERLACE:%d\n", Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE));
#endif
}

unsigned char VSC_Check_Signal_Lock(unsigned char display)
{
	VSC_INPUT_TYPE_T src_type;
	unsigned char port;
#ifndef CONFIG_DUAL_CHANNEL
	display = SLR_MAIN_DISPLAY;
	if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN) {
		src_type = DisplayModeInputInfo.type;
		port = DisplayModeInputInfo.resourceIndex;
	} else if (VencModeInputInfo.type != VSC_INPUTSRC_MAXN) {
		src_type = VencModeInputInfo.type;
		port = VencModeInputInfo.resourceIndex;
	} else if (MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN) {
		src_type =  MemoryModeInputInfo.type;
		port = MemoryModeInputInfo.resourceIndex;
	} else if (AveModeInputInfo.type != VSC_INPUTSRC_MAXN) {
		src_type = AveModeInputInfo.type;
		port = AveModeInputInfo.resourceIndex;
	} else {
		src_type = DisplayModeInputInfo.type;
		port = DisplayModeInputInfo.resourceIndex;
	}
#else
	if (display == SLR_MAIN_DISPLAY)
	{
		if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type = DisplayModeInputInfo.type;
			port = DisplayModeInputInfo.resourceIndex;
		} else if (VencModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type = VencModeInputInfo.type;
			port = VencModeInputInfo.resourceIndex;
		} else if (MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type =	MemoryModeInputInfo.type;
			port = MemoryModeInputInfo.resourceIndex;
		} else if (AveModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type = AveModeInputInfo.type;
			port = AveModeInputInfo.resourceIndex;
		} else {
			src_type = DisplayModeInputInfo.type;
			port = DisplayModeInputInfo.resourceIndex;
		}
	}
	else
	{
		if(Sub_DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type = Sub_DisplayModeInputInfo.type;
			port = Sub_DisplayModeInputInfo.resourceIndex;
		} else if (Sub_VencModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type = Sub_VencModeInputInfo.type;
			port = Sub_VencModeInputInfo.resourceIndex;
		} else if (Sub_MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type =  Sub_MemoryModeInputInfo.type;
			port = Sub_MemoryModeInputInfo.resourceIndex;
		} else if (Sub_AveModeInputInfo.type != VSC_INPUTSRC_MAXN) {
			src_type = Sub_AveModeInputInfo.type;
			port = Sub_AveModeInputInfo.resourceIndex;
		} else {
			src_type = Sub_DisplayModeInputInfo.type;
			port = Sub_DisplayModeInputInfo.resourceIndex;
		}
	}
#endif

	switch(src_type)
	{
		case VSC_INPUTSRC_ADC:
		case VSC_INPUTSRC_AVD:
		case VSC_INPUTSRC_HDMI:
			 if((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && drvif_mode_check_onlinemeasure_status(display))
			 	return TRUE;
			 else
			 	return FALSE;

		case VSC_INPUTSRC_VDEC:
		case VSC_INPUTSRC_JPEG:
			if(get_vo_change_flag(port) == FALSE && Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}

		default:
			return FALSE;

	}
}
unsigned char Scaler_get_data_framesync(unsigned char display)
{
	unsigned int len_temp=Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE);
	VSC_INPUT_TYPE_T srctype;
	SLR_VOINFO *pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
	if((pVOInfo == NULL) ||(pVOInfo->src_v_len ==0))
	{
		pr_emerg("Scaler_get_data_framesync get vo timinginfo error\n");
		
	} else {
		len_temp = pVOInfo->src_v_len;
	}
	if (display == SLR_MAIN_DISPLAY) {
		if (TRUE == Get_rotate_function()) {
			return false;
		}
		if (get_current_driver_pattern(DRIVER_FREERUN_PATTERN) == 1) {
			if (Scaler_DispGetStatus(display,SLR_DISP_INTERLACE)) {
				len_temp = len_temp *2;
			}
			if (Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI ||
		    		Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI) {
				return FALSE;
			}

			srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);
			if((srctype == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV)){
				pr_notice("==== ATV GO data frc ====\n");
				return FALSE;
			}
			if (vsc_get_adaptivestream_flag()) {
				if (Scaler_DispWindowGet().src_height < (_DISP_LEN-5)) {
					return FALSE;
				} else
				{
					return TRUE;
				}
			} else {
				if (Scaler_DispWindowGet().src_height <  _DISP_LEN && Scaler_DispWindowGet().src_height <  len_temp) {
					return FALSE;
				} else
				{
					return TRUE;
				}
			}
		} else {
			return FALSE;
		}
	} else {
		return FALSE;
	}
}
unsigned char get_displayinfo_proc(unsigned char display, VSC_INPUT_TYPE_T inputSrctype)//This is for driver base implement open source
{
	unsigned int *p_sourceID = NULL;
	SLR_VOINFO* pVOInfo;

	if(display == SLR_SUB_DISPLAY) {
		p_sourceID = &DbgSclrFlgTkr.sub_opensourceID;
	} else {
		p_sourceID = &DbgSclrFlgTkr.main_opensourceID;
	}
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if(
		(inputSrctype != VSC_INPUTSRC_VDEC) && (inputSrctype != VSC_INPUTSRC_JPEG) && (display == SLR_MAIN_DISPLAY) &&
		((get_line_alternative_3d_mode_enable() == TRUE)
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			|| (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)
		#endif
			|| get_force_i3ddma_enable(SLR_MAIN_DISPLAY)) /*&& inputSrctype == VSC_INPUTSRC_HDMI*/
#ifdef CONFIG_I2RND_ENABLE
			|| ((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))
#endif
	)
	{

//		fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),VGIP_SRC_VODMA1, VGIP_MODE_ANALOG);
		fw_scaler_set_vgip(display, VGIP_SRC_VODMA1, VGIP_MODE_ANALOG);

		if(get_force_i3ddma_enable(display) &&
			((inputSrctype != VSC_INPUTSRC_HDMI) || (get_HDMI_HDR_mode() == HDR_MODE_DISABLE))
		)
		{
			//drvif_mode_enable_dma_onlinemeasure();
		}
	}
	else if(inputSrctype == VSC_INPUTSRC_ADC)//ypp,VGA
#else
	if(inputSrctype == VSC_INPUTSRC_ADC)//ypp,VGA
#endif
	{
		if(ADC_Check_VSC_VFE_ConnectSrc_Match(*p_sourceID) == FALSE)
		{
			return FALSE;
		}
		down(get_adc_detectsemaphore());
		Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_ADC_Dispinfo());//now for test, only for ypp timing info
		if(vsc_timinginfo_check() == FALSE)
		{
			up(get_adc_detectsemaphore());
			return FALSE;
		}
		if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > 2000)//mean 4095 no support
		{
			up(get_adc_detectsemaphore());
			rtd_printk(KERN_ERR, TAG_NAME_VSC," get_displayinfo_proc adc vsc_timinginfo_check no support error\n");
			return FALSE;
		}
		ADC_set_detect_flag(FALSE);
		up(get_adc_detectsemaphore());
		 if(get_ADC_Input_Source() == _SRC_SCART_RGB)// Scart RGB
		{
//			fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), VGIP_SRC_ATV, VGIP_MODE_ANALOG);
			fw_scaler_set_vgip(display, VGIP_SRC_ATV, VGIP_MODE_ANALOG);
		}
		// YPP and VGA
		else
		{
//			fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), VGIP_SRC_ADC, VGIP_MODE_ANALOG);
			fw_scaler_set_vgip(display, VGIP_SRC_ADC, VGIP_MODE_ANALOG);
//			fw_scaler_set_sample(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), _ENABLE);
			fw_scaler_set_sample(display, _ENABLE);
		}

		ADC_VSC_Setting(get_ADC_Input_Source());
		fw_scaler_adc_nolock_wdg_ctrl(display, FALSE);//Disable adc_nolock_wdg
		drvif_mode_enableonlinemeasure(display);//Enable online measure
	}
	else if(inputSrctype == VSC_INPUTSRC_AVD)
	{
		down(get_vdc_detectsemaphore());
		Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_AVD_ScalerDispinfo());
		if(vsc_timinginfo_check() == FALSE)
		{
			up(get_vdc_detectsemaphore());
			return FALSE;
		}
		//VDC_set_detect_flag(FALSE);//Will temp add. Need to check.
		up(get_vdc_detectsemaphore());
//		fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), VGIP_SRC_ATV, VGIP_MODE_ANALOG);
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY))
		{
			if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM)
			{
				drvif_color_ultrazoom_config_livezoompathselect(TRUE);
				fw_scaler_set_vgip(display, SUB_VGIP_SRC_MAINUZD, VGIP_MODE_ANALOG);
			}
			else
			{
				drvif_color_ultrazoom_config_livezoompathselect(FALSE);
				fw_scaler_set_vgip(display, SUB_VGIP_SRC_AVD, VGIP_MODE_ANALOG);
			}
			drvif_mode_disableonlinemeasure(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
		}else{
				if(display == SLR_SUB_DISPLAY)
				{
					fw_scaler_set_vgip(display, SUB_VGIP_SRC_AVD, VGIP_MODE_ANALOG);
				}
				else
				{
					fw_scaler_set_vgip(display, VGIP_SRC_ATV, VGIP_MODE_ANALOG);
				}
		}
		drvif_mode_enableonlinemeasure(display);//Enable online measure
	}
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	else if(((get_line_alternative_3d_mode_enable() == TRUE) || (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)) && inputSrctype == VSC_INPUTSRC_HDMI)
	{

		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY)) {
			/*qiangzhou:hdmi hdr source should support livezoom , sub should run ormal*/
			drvif_mode_disableonlinemeasure(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
		} else {
			//USER:Lewislee DATE:2015/09/29
			//PIP no 3D
			if(SLR_SUB_DISPLAY == display)
			{
				return FALSE;
			}
			else if(get_line_alternative_3d_mode_enable() == TRUE)
			{
				if((TRUE == DbgSclrFlgTkr.Sub_OuputDisplayMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputVencMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputMemoryMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputAveMode))
					return FALSE;
			}
		}

//		fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),VGIP_SRC_VODMA1, VGIP_MODE_ANALOG);
		fw_scaler_set_vgip(display, VGIP_SRC_VODMA1, VGIP_MODE_ANALOG);
	}
#endif
	else if(inputSrctype == VSC_INPUTSRC_HDMI)
	{
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY))
		{
			//tmp code
			Scaler_SET_VSCSubDispinfo_Withmain();
//			fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), VGIP_SRC_TMDS, VGIP_MODE_ANALOG);
			if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM)
				fw_scaler_set_vgip(display, SUB_VGIP_SRC_MAINUZD, VGIP_MODE_ANALOG);
			else
				fw_scaler_set_vgip(display, VGIP_SRC_TMDS, VGIP_MODE_ANALOG);

			drvif_mode_disableonlinemeasure(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
		} else {
			vfe_hdmi_timing_info_t vfehdmitiminginfo;
			down(get_hdmi_detectsemaphore());
			if(0 != vfe_hdmi_drv_get_display_timing_info(&vfehdmitiminginfo, display))
			{
				up(get_hdmi_detectsemaphore());
				return FALSE;
			}
			Scaler_SET_VSCDispinfo_WithVFEHMDI(display, vfehdmitiminginfo);

			if(get_field_alternative_3d_mode_enable() == TRUE)
			{
				//USER:Lewislee DATE:2015/09/29
				//PIP no 3D
				if(SLR_SUB_DISPLAY == display)
				{
					up(get_hdmi_detectsemaphore());
					return FALSE;
				}
				else// if(SLR_MAIN_DISPLAY == display)
				{
					if((TRUE == DbgSclrFlgTkr.Sub_OuputDisplayMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputVencMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputMemoryMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputAveMode))
					{
						up(get_hdmi_detectsemaphore());
						return FALSE;
					}
				}

//				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE, TRUE);
				Scaler_DispSetStatus(display, SLR_DISP_INTERLACE, TRUE);
			}
			if(vsc_timinginfo_check() == FALSE)
			{
				up(get_hdmi_detectsemaphore());
				return FALSE;
			}

#if 0
			HDMI_set_detect_flag(FALSE);
#endif
			up(get_hdmi_detectsemaphore());
			if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && drvif_scaler3d_decide_HDMI_framePacking_auto_status(display))
			{
				modestate_HDMI_3D_format_auto_detection(display);

				//USER:Lewislee DATE:2015/09/29
				//PIP no 3D
				if(SLR_SUB_DISPLAY == display)
				{
					if(SLR_3DMODE_3D_AUTO == Scaler_Get3DMode(SLR_SUB_DISPLAY))
					{
						if(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) >= HDMI3D_2D_ONLY)
						{
							//bypass
						}
						else
						{
//							up(get_hdmi_detectsemaphore());
							return FALSE;
						}
					}
				}
				else// if(SLR_MAIN_DISPLAY == display)
				{
					if((TRUE == DbgSclrFlgTkr.Sub_OuputDisplayMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputVencMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputMemoryMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputAveMode))
					{
						if(SLR_3DMODE_3D_AUTO == Scaler_Get3DMode(SLR_MAIN_DISPLAY))
						{
							if(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) >= HDMI3D_2D_ONLY)
							{
								//bypass
							}
							else
							{
//								up(get_hdmi_detectsemaphore());
								return FALSE;
							}
						}
					}
				}
			}
			fw_scaler_set_vgip(display, VGIP_SRC_TMDS, VGIP_MODE_ANALOG);
			drvif_mode_enableonlinemeasure(display);//Enable online measure
		}
	}
	else if((inputSrctype == VSC_INPUTSRC_VDEC) || (inputSrctype == VSC_INPUTSRC_JPEG)) {
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY)&& (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM))
			fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SUB_VGIP_SRC_MAINUZD, VGIP_MODE_ANALOG);
		else if (Scaler_Get_CurVoInfo_VoVideoPlane(display) == VO_VIDEO_PLANE_V2)
			fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),VGIP_SRC_VODMA2, VGIP_MODE_ANALOG);
		else
			fw_scaler_set_vgip(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),VGIP_SRC_VODMA1, VGIP_MODE_ANALOG);
	} else {
		return FALSE;
	}
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if(((inputSrctype == VSC_INPUTSRC_VDEC)||(inputSrctype == VSC_INPUTSRC_JPEG) ||(get_line_alternative_3d_mode_enable() == TRUE)
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		|| (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)
		#endif
		|| get_force_i3ddma_enable(display))&&(SLR_MAIN_DISPLAY == display)
#ifdef CONFIG_I2RND_ENABLE
		||((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))
#endif
		)
#else
	if(((inputSrctype == VSC_INPUTSRC_VDEC)||(inputSrctype == VSC_INPUTSRC_JPEG) ||(get_line_alternative_3d_mode_enable() == TRUE)
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		|| (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)
		#endif
		)&&(SLR_MAIN_DISPLAY == display))
#endif
	{
		unsigned char smooth_toggle_mode=SLR_DISPLAY_DEFAULT;
		unsigned char plane=0;
#ifdef CONFIG_ALL_SOURCE_DATA_FS // [MAC5P-2291] force all source M-domain in data FS path
		if (Scaler_get_data_framesync(display)) {
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, TRUE);
		} else {
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
		}
		smooth_toggle_mode=SLR_DISPLAY_DATA_FRAME_SYNC;
		rtd_printk(KERN_EMERG, TAG_NAME_VSC, "data FS/FRC@%d\n", Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC));
#endif
#if 0
		if (vsc_get_adaptivestream_flag()) {
		#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
			if(vbe_disp_get_adaptivestream_fs_mode()){
			#if 0
				//Add VO low delay mode run fs @Crixus 20160407
				unsigned int v_len_low_delay;
				if (Scaler_DispGetStatus(display, SLR_DISP_INTERLACE)) { // interlace
					v_len_low_delay = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)<<1;
				} else {
					v_len_low_delay = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
				}
				pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
				if((pVOInfo->lowdelay == _ENABLE)
					&& (Main_InputRegion_w == Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE))
					&& (Main_InputRegion_h == Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE))){
					//Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, TRUE);
					Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
					//smooth_toggle_mode = SLR_DISPLAY_DATA_FRC_FS_4K2K;
					smooth_toggle_mode = SLR_DISPLAY_DATA_FRC;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo][low delay]data FS@%d\n", __LINE__);
				}else{
					if((Scaler_DispWindowGet().src_height <= _DISP_LEN) && ((_DISP_LEN - Scaler_DispWindowGet().src_height )<= 240)  && (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) >= 3000) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 310)) {
					//Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, TRUE);
					Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);

				} else {
					Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				}
				smooth_toggle_mode=SLR_DISPLAY_DATA_FRC_FS_4K2K; //let adaptive stream always use the same data mode

				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "_rk %s %d [vo]adaptive always data FRC_FS4K2K\n",__FUNCTION__,__LINE__);
				}
			#else
				Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				smooth_toggle_mode = SLR_DISPLAY_DATA_FRC;
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "[vo][smoothtoggle] adaptive stream go all FRC\n");
			#endif
			}else{
				Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				smooth_toggle_mode=SLR_DISPLAY_DATA_FRC;
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "[vo][smoothtoggle] go all FRC\n");
			}
		#else
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
			smooth_toggle_mode=SLR_DISPLAY_DATA_FRC;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo][smoothtoggle] adaptive go all FRC\n");
		#endif
		} else if(Disp_Get_isForceFreeRun()||	//free run timing
			((get_vo_3d_mode() >= VO_3D_SIDE_BY_SIDE_HALF) && (get_vo_3d_mode() <= VO_3D_LINE_BY_LINE))) //3d source
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo] go force free run or 3d mode,data frc\n");
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
			smooth_toggle_mode=SLR_DISPLAY_DATA_FRC;
		} else if ((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) >= 3000) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 310)) {
			unsigned int v_len;
			if (Scaler_DispGetStatus(display, SLR_DISP_INTERLACE)) { // interlace
				v_len=Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)<<1;
			} else {
				v_len=Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
			}
			if (DbgSclrFlgTkr.Main_force_frc_flag && (display == SLR_MAIN_DISPLAY)) {
				down(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_force_frc_flag = FALSE;
				up(&SetMainOutPutRegion_Semaphore);
				Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				smooth_toggle_mode=SLR_DISPLAY_DATA_FRC;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo]force data FRC@%d\n", __LINE__);
			} else if ((Main_InputRegion_w<Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) )||(Main_InputRegion_h<v_len)) {
				Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				smooth_toggle_mode=SLR_DISPLAY_DATA_FRC;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo]force data FRC@%d\n", __LINE__);
			}
			else if ((Scaler_DispWindowGet().src_height == _DISP_LEN)) {
				//Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, TRUE);
				Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				//smooth_toggle_mode=SLR_DISPLAY_DATA_FRC_FS_4K2K;
				smooth_toggle_mode=SLR_DISPLAY_DATA_FRC;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo]data FS@%d\n", __LINE__);
			} else {
				Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				smooth_toggle_mode=SLR_DISPLAY_DATA_FRC_FS_4K2K;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo]FORCE FRC\n");
			}
		} else {
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
			smooth_toggle_mode=SLR_DISPLAY_DATA_FRC_FS_4K2K;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo][smoothtoggle] FORCE FRC\n");
		}
#endif
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB)) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[live zoom on/off] Force Data Frc !\n");
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
			smooth_toggle_mode=SLR_DISPLAY_DATA_FRC;
		} else if ((Get_LivezoomOffMainForceBG() == TRUE)&& (DbgSclrFlgTkr.DataFramesynclivezoom == TRUE)) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[live zoom off] Force Data Fs !\n");
			//Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, TRUE);
			//smooth_toggle_mode = SLR_DISPLAY_DATA_FRC_FS_4K2K;
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
			smooth_toggle_mode = SLR_DISPLAY_DATA_FRC;
		} else if ((Get_LivezoomOffMainForceBG() == TRUE)&& (DbgSclrFlgTkr.DataFramesynclivezoom == FALSE)) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[live zoom off] Force Data Frc !\n");
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
			smooth_toggle_mode = SLR_DISPLAY_DATA_FRC;
		}
		plane = get_vo_plane_flag(display);
		if (inputSrctype == VSC_INPUTSRC_VDEC) {
			if (get_vo_open_smooth_toggle_enable(display) && (!Get_vo_smoothtoggle_timingchange_flag(display))
				/*pause-open livezoom could not close di,so livezoom case not run here*/
				&&(Get_Live_zoom_mode() == LIVE_ZOOM_OFF)
				&&(Get_LivezoomOffMainForceBG() == FALSE)
				&&((get_rotate_mode()==get_ori_rotate_mode())|| (get_ori_rotate_mode()==DIRECT_VO_FRAME_ORIENTATION_DEFAULT))
				/*&& (display == SLR_MAIN_DISPLAY)*/) {
					Set_direct_vo_smoothtoggle_enable(1, smooth_toggle_mode, display,plane); //open smooth toggle go data frc
			} else if (Get_vo_smoothtoggle_timingchange_flag(display)) {
					set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_INIT, display,plane);
				vo_force_data_mode_set_enable(smooth_toggle_mode, display);
			} else if(vsc_get_adaptivestream_flag()){
				 	Set_direct_vo_smoothtoggle_enable(1, smooth_toggle_mode, display,plane); //open smooth toggle go data frc
			} else 	if(inputSrctype == VSC_INPUTSRC_VDEC) {//DTV
#ifndef CONFIG_ALL_SOURCE_DATA_FS
				Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo]DTV always Go FRC%d\n", __LINE__);
#endif
			}
		}

	#if 1
		if(get_3D_mode_enable() == TRUE)
		{
			if(get_vo_3d_mode() == VO_3D_SIDE_BY_SIDE_HALF )
			{
				Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE, SLR_3D_SIDE_BY_SIDE_HALF);
				Scaler_Set3DMode_Attr((SCALER_DISP_CHANNEL)display, SLR_3DMODE_3D_SBS);
			}
			else if(get_vo_3d_mode() == VO_3D_TOP_AND_BOTTOM)
			{
				Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE, SLR_3D_TOP_AND_BOTTOM);
				Scaler_Set3DMode_Attr((SCALER_DISP_CHANNEL)display, SLR_3DMODE_3D_TB);
			}
			else if(get_vo_3d_mode() == VO_3D_FRAME_PACKING)
			{
				Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE, SLR_3D_FRAME_PACKING);
				Scaler_Set3DMode_Attr((SCALER_DISP_CHANNEL)display, SLR_3DMODE_3D_FP);
			}
		}
		else
		{
			Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE,SLR_3D_2D_ONLY);
			Scaler_Set3DMode_Attr((SCALER_DISP_CHANNEL)display, SLR_3DMODE_2D);
		}
	#endif

#ifdef CONFIG_MEMC_BYPASS
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "############# [ben dbg][SLR_INPUT_PIXEL_MODE] [%d]\n", Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE));

		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[CONFIG_MEMC_BYPASS][2 pixel] go data FRC@%d\n", __LINE__);

		}
#endif

	}
	else
	{
		Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC, FALSE);
	}



#ifdef CONFIG_FORCE_RUN_I3DDMA
	if((inputSrctype == VSC_INPUTSRC_VDEC) || (inputSrctype == VSC_INPUTSRC_JPEG) || (get_line_alternative_3d_mode_enable() == TRUE)
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		|| (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)
		#endif
		|| get_force_i3ddma_enable(display)
#ifdef CONFIG_I2RND_ENABLE
		|| ((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))
#endif
		)
#else
	if((inputSrctype == VSC_INPUTSRC_VDEC) || (inputSrctype == VSC_INPUTSRC_JPEG) || (get_line_alternative_3d_mode_enable() == TRUE)
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		|| (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)
		#endif
		)
#endif
	{
		Scaler_DispSetStatus(display, SLR_DISP_VFLIP3, FALSE);

	}
	else
	{
		if (Get_PANEL_VFLIP_ENABLE())
			Scaler_DispSetStatus(display, SLR_DISP_VFLIP3, TRUE);
		else
			Scaler_DispSetStatus(display, SLR_DISP_VFLIP3, FALSE);
	}

	set_default_mcap_format(display, inputSrctype);//Set default m cap 422 or 444

	if ((get_sub_OutputVencMode() && (display == SLR_SUB_DISPLAY)) || (get_main_OutputVencMode() && (display == SLR_MAIN_DISPLAY)) || (Get_Live_zoom_mode() == LIVE_ZOOM_SUB)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n######DbgSclrFlgTkr.OutputVencMode force to 422capture######\r\n");
		Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
		if((Get_Live_zoom_mode() == LIVE_ZOOM_SUB)&&(display == SLR_MAIN_DISPLAY)){
			if (DbgSclrFlgTkr.RGB444Mode == TRUE)
				set_LiveZoomPcmodeDiableRTNR(TRUE);
			else
				set_LiveZoomPcmodeDiableRTNR(FALSE);
		}
	} else if((DbgSclrFlgTkr.RGB444Mode == TRUE) && ((inputSrctype == VSC_INPUTSRC_ADC) || (inputSrctype == VSC_INPUTSRC_HDMI) || (inputSrctype == VSC_INPUTSRC_JPEG))) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n######DbgSclrFlgTkr.RGB444Mode is true force to 444capture######\r\n");
		if(display == SLR_SUB_DISPLAY)
			Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);//sub only run 422 format
		else
			/*qiangzhou:mac5p need go 422 for m domain 12bit compress*/
			Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
	}

	if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n######framesync is true force to 444capture######\r\n");
		Scaler_DispSetStatus(display, SLR_DISP_422CAP, FALSE);
	} else if(get_3D_overscan_enable()) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n######get_3D_overscan_enable is true force to 444capture######\r\n");
		Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
	}
#ifdef FORCE_BYPASS_DI_RTNR
//Debug use. Interlace timing don't go rtnr and DI
	if(display == SLR_MAIN_DISPLAY)
		Scaler_DispSetStatus(display, SLR_DISP_INTERLACE, FALSE);//force to set no interlace
#endif

	extern UINT8 TV006_WB_Pattern_En;
	if (TV006_WB_Pattern_En == 0)
		IoReg_ClearBits(SCALEUP_D_UZU_Globle_Ctrl_reg, _BIT0|_BIT1);//clear uzu pattern gen
	// FixMe
	//Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_10BIT,FALSE);//let all source go 10bit mode
	if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB)&& (display == SLR_MAIN_DISPLAY)) {
		Scaler_DispSetStatus(display, SLR_DISP_10BIT, FALSE);
	}else if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (get_vo_vp9_flag(Get_DisplayMode_Port(display)))) {
		Scaler_DispSetStatus(display, SLR_DISP_10BIT, FALSE);//VP9 case use 8 bits setting @ Crixus 20160407
#ifdef CONFIG_I2RND_ENABLE
	}else if((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){
		Scaler_DispSetStatus(display, SLR_DISP_10BIT, FALSE);
#endif
	} else if (display == SLR_MAIN_DISPLAY) {
		Scaler_DispSetStatus(display, SLR_DISP_10BIT, TRUE);//let all source go 10bit mode
	} else if(display == SLR_SUB_DISPLAY) {
		Scaler_DispSetStatus(display, SLR_DISP_10BIT, FALSE);
	}
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		if (TRUE == Get_rotate_function())
			Scaler_DispSetStatus(display, SLR_DISP_10BIT, FALSE);
#endif

#ifdef CONFIG_COMPRESSION_MODE_TEST
	//self-dianosis need disable compression, rzhen@2016-09-01
	if ((SLR_MAIN_DISPLAY == display) //&& (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)==FALSE)
		&& (Get_Live_zoom_mode() == LIVE_ZOOM_OFF )/*livezoom magnifier close compress mode*/
//#ifdef CONFIG_I2RND_ENABLE
	//	&& (Scaler_I2rnd_get_enable() == _DISABLE)
//#endif
		&&(drv_memory_get_game_mode() == _DISABLE)
		&&(Get_Factory_SelfDiagnosis_Mode() == FALSE)
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		&&(FALSE == Get_rotate_function())
#endif
		)
	{
		//Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);//compress force 422. need to check
		dvrif_memory_compression_set_enable(SLR_MAIN_DISPLAY, TRUE);

		//if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_422CAP))
			//dvrif_memory_set_compression_bits(COMPRESSION_12_BITS);
		//else
		if((Scaler_DispGetStatus(display, SLR_DISP_422CAP) == FALSE) && (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)==FALSE))
			dvrif_memory_set_compression_bits(COMPRESSION_10_BITS); //444 go 24 bit
		else
			dvrif_memory_set_compression_bits(COMPRESSION_10_BITS);//422 go 12 bits

		//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"[crixus]M-domain Compression Enable!!\n");
	}
	else
	{
		if(display == SLR_MAIN_DISPLAY) {
#ifdef CONFIG_I2RND_ENABLE
			if (Scaler_I2rnd_get_enable()) {
				if (Scaler_I2rnd_get_display() ==I2RND_SUB_S1_TABLE) {
					dvrif_memory_compression_set_enable(SLR_SUB_DISPLAY, FALSE);
				} else {
					dvrif_memory_compression_set_enable(SLR_MAIN_DISPLAY, FALSE);
				}
			} else
#endif
			{
				dvrif_memory_compression_set_enable(SLR_MAIN_DISPLAY, FALSE);
			}

		}
		else
			dvrif_memory_compression_set_enable(SLR_SUB_DISPLAY, FALSE);
		//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"[crixus]M-domain Compression Disable!!\n");
	}
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "###Finally fsync:%d 422:%d comp(%d %d) disp(%d)###\r\n", Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC), Scaler_DispGetStatus(display, SLR_DISP_422CAP), dvrif_memory_compression_get_enable(display), dvrif_memory_get_compression_bits(), display);

	drvif_memory_compression_rpc();
#endif
	return TRUE;
}

void close_livezoom_doublebuffer(void)
{
	mdomain_disp_ddr_mainsubctrl_RBUS mdomain_disp_ddr_mainsubctrl_Reg;
	ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_Reg;
	scaleup_dm_uzu_db_ctrl_RBUS scaleup_dm_uzu_db_ctrl_Reg;
	scaleup_ds_uzu_db_ctrl_RBUS scaleup_ds_uzu_db_ctrl_Reg;
	unsigned long flags;//for spin_lock_irqsave

	//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT17);
	mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
	mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_enable = 0;
	mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_enable = 0;
	IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Enable dtg double buffer register
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_en = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	//IoReg_SetBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
	scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
	scaleup_ds_uzu_db_ctrl_Reg.db_en = 0;
	IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);

	//IoReg_SetBits(SCALEUP_DM_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
	scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg);
	scaleup_dm_uzu_db_ctrl_Reg.db_en = 0;
	IoReg_Write32(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);

}

unsigned char init_source_proc(unsigned char display, VSC_INPUT_TYPE_T sourcetype, unsigned char sourceport)
{
	unsigned short vfesource;
	unsigned int *p_sourceID = NULL;

	int i= 0, size;
	//unsigned int srcid = MainOpenSourceID;
	StructSourceInput *srcinput_pt = NULL;
	//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "%s.%d\n", __FUNCTION__, __LINE__);


	if(get_zoom_reset_double_state(display) == _ENABLE){
		set_zoom_reset_double_state(_DISABLE,display);
 	}

#ifdef CONFIG_DUAL_CHANNEL
		if (display == SLR_MAIN_DISPLAY) {
			p_sourceID = &DbgSclrFlgTkr.main_opensourceID;
		} else {
			p_sourceID = &DbgSclrFlgTkr.sub_opensourceID;
		}
#else
		if (display == SLR_MAIN_DISPLAY) {
			p_sourceID = &DbgSclrFlgTkr.main_opensourceID;
		} else {
			return FALSE;
		}

#endif

	switch(sourcetype)
	{
		case VSC_INPUTSRC_AVD:
		{
			down(get_setsource_semaphore());
			vfesource = get_AVD_Input_Source();
			up(get_setsource_semaphore());
			switch (vfesource) {
			case _SRC_TV://atv
			{
				if(sourceport == 0) {
					*p_sourceID = _TV_INPUT1;
				} else if (sourceport == 1) {
					*p_sourceID = _TV_INPUT2;
				} else if (sourceport == 2) {
					*p_sourceID = _TV_INPUT3;
				} else {
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc AVD ATV port = %d is invalid!!!!!!!!!!!!!!!1\n", sourceport);
					return FALSE;
				}
				if (display == SLR_MAIN_DISPLAY) {
					DbgSclrFlgTkr.Main_AutoRunScaler = TRUE;
				}
#ifdef CONFIG_DUAL_CHANNEL
				else {
					DbgSclrFlgTkr.Sub_AutoRunScaler = TRUE;
				}
#endif
				break;
			}
			case _SRC_CVBS://cvbs
			{
				if(sourceport == 0) {
					*p_sourceID = _AV_INPUT1;
				} else if (sourceport == 1) {
					*p_sourceID = _AV_INPUT2;
				} else if (sourceport == 2) {
					*p_sourceID = _AV_INPUT3;
				} else {
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc AVD CVBS port = %d is invalid!!!!!!!!!!!!!!!1\n", sourceport);
					return FALSE;
				}

				break;
			}
			case _SRC_SCART://SCART
			{
				if(sourceport == 0) {
					*p_sourceID = _SCART_INPUT1;
				} else if (sourceport == 1) {
					*p_sourceID = _SCART_INPUT2;
				} else if (sourceport == 2) {
					*p_sourceID = _SCART_INPUT3;
				} else {
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc AVD SCART RGB port = %d is invalid!!!!!!!!!!!!!!!1\n", sourceport);
					return FALSE;
				}
				break;
			}

			default:
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc AVD VFE not connect!!!!!!!!!!!!!!!1\n");
				return FALSE;
			}
			break;
		}
		case VSC_INPUTSRC_ADC:
		{
			down(get_setsource_semaphore());
			vfesource = get_ADC_Input_Source();
			up(get_setsource_semaphore());
			switch (vfesource) {
			case _SRC_YPBPR://ypp
			{
				if (sourceport == 0) {
					*p_sourceID = _YPBPR_INPUT1;
				} else if (sourceport == 1) {
					*p_sourceID = _YPBPR_INPUT2;
				} else if (sourceport == 2) {
					*p_sourceID = _YPBPR_INPUT3;
				} else {
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc ADC YPP port = %d is invalid!!!!!!!!!!!!!!!1\n", sourceport);
					return FALSE;
				}

				break;
			}
			case _SRC_VGA://VGA
			{
				if (sourceport == 0) {
					*p_sourceID = _VGA_INPUT1;
				} else if(sourceport == 1) {
					*p_sourceID = _VGA_INPUT2;
				} else if(sourceport == 2) {
					*p_sourceID = _VGA_INPUT3;
				} else {
					rtd_printk(KERN_INFO, TAG_NAME_VSC, "init_source_proc ADC VGA port = %d is invalid!!!!!!!!!!!!!!!1\n", sourceport);
					return FALSE;
				}
				break;
			}
			case _SRC_SCART_RGB://SCARTRGB
			{
				if (sourceport == 0) {
					*p_sourceID = _SCART_RGB_INPUT1;
				} else if(sourceport == 1) {
					*p_sourceID = _SCART_RGB_INPUT2;
				} else if(sourceport == 2) {
					*p_sourceID = _SCART_RGB_INPUT3;
				} else {
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc ADC SCART_RGB port = %d is invalid!!!!!!!!!!!!!!!1\n", sourceport);
					return FALSE;
				}
				break;
			}
			default:
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc ADC VFE not connect!!!!!!!!!!!!!!!1\n");
				return FALSE;
			}
			break;
		}
		case VSC_INPUTSRC_HDMI:
		{
			down(get_setsource_semaphore());
			vfesource = get_HDMI_Input_Source();
			up(get_setsource_semaphore());
			switch (vfesource) {
			case _SRC_HDMI://hdmi
				if (sourceport == 0) {
					*p_sourceID = _HDMI_INPUT1;
				} else if(sourceport == 1) {
					*p_sourceID = _HDMI_INPUT2;
				} else if(sourceport == 2) {
					*p_sourceID = _HDMI_INPUT3;
				} else if(sourceport == 3) {
					*p_sourceID = _HDMI_INPUT4;
				} else {
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc HDMI port%d is invalid!!!!!!!!!!!!!!!1\n", sourceport);
					return FALSE;
				}
				break;
			default:
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "init_source_proc HDMI source VFE not connect!!!!!!!!!!!!!!!1\n");
				return FALSE;
			}

			break;
		}

		case VSC_INPUTSRC_VDEC:
		{
            *p_sourceID = _VO_INPUT1;
			break;
		}
		case VSC_INPUTSRC_JPEG:
		{
            *p_sourceID = _VO_INPUT1;
			break;
		}
		default:
		{
			return FALSE;
			break ;
		}
	}
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if((display == SLR_MAIN_DISPLAY)/* && (sourcetype != VSC_INPUTSRC_AVD || vfesource != _SRC_TV)*/)
#else
	if(get_line_alternative_3d_mode_enable() == TRUE
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		|| Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED
		#endif
		)
#endif
	{
		  *p_sourceID = _VO_INPUT1;
	}

	size = PcbSource_GetTableSize();
	srcinput_pt = Scaler_InputSrc(0);

	for(i = 0; i < size; i++)
	{
		if(srcinput_pt->src_index == *p_sourceID) break;
		srcinput_pt++;
	}
	if(i == size)
	{
		rtd_printk(KERN_ERR, TAG_NAME_VSC, "\r\n###### source not found#######\r\n");
		return FALSE;
	}
	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_INPUT_SRC, i);
	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX, i);//For m_screenModeCurrInfo table
	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_OSD_INPUT_SRC, i);
	Scaler_SetUserInputSrc((SCALER_DISP_CHANNEL)display, i);
	return TRUE;

}

static void set_default_mcap_format(unsigned char display, VSC_INPUT_TYPE_T inputSrctype)
{//Set M Cap 444 or 422
#ifndef CONFIG_DUAL_CHANNEL
	display = SLR_MAIN_DISPLAY;
#endif
	switch(inputSrctype) {
	case VSC_INPUTSRC_ADC:
	Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
	break;

	case VSC_INPUTSRC_HDMI:
	Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
	break;

	case VSC_INPUTSRC_AVD:
	Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
	break;

	case VSC_INPUTSRC_VDEC:
	case VSC_INPUTSRC_JPEG:
	Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
	break;

	default:
	Scaler_DispSetStatus(display, SLR_DISP_422CAP, TRUE);
	break;
	}
}

static unsigned char modestate_set_vgip(StructDisplayInfo* info)
{

	unsigned char result = TRUE;
    //extern unsigned int vpq_project_id;
#if 0
	// restore original signa's info
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_WriteByte0(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? SUB_VGIP_VGIP_CHN2_DELAY_reg : VGIP_VGIP_CHN1_DELAY_reg, Scaler_DispGetInputInfo(SLR_INPUT_IPV_DLY_PRE));
#else
	IoReg_WriteByte0(/*Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? SUB_VGIP_VGIP_CHN2_DELAY_reg : */VGIP_VGIP_CHN1_DELAY_reg, Scaler_DispGetInputInfo(SLR_INPUT_IPV_DLY_PRE));
#endif
#endif

#ifdef CONFIG_ENABLE_3D_SETTING
	modestate_decide3D_for_vdc();
#endif

	//If source is FR, handle display ratio at movie or caption
	if(!fw_scaler_cal_vgip_capture(info->display))
		return FALSE;
#if 0
    if (0){//(vpq_project_id == 0x00010000) {
        stDISPLAY_OVERSCAN_DATA scan_data={0};
        stVGIP_ADJUSTMENT_INFO adj_data={0};
        scan_data.HStart = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA);
        scan_data.HWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
        scan_data.VStart = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);
        scan_data.VHeight = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
        Mode_scaler_overscan(&scan_data,0);
        Mode_scaler_VGIP_Adjustment(&adj_data,0);

        Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA,scan_data.HStart+adj_data.h_start);
        Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID,scan_data.HWidth+adj_data.h_width);
        Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,scan_data.VStart+adj_data.v_start);
        Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,scan_data.VHeight+adj_data.v_length);
    }
#endif
	if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (info->display== SLR_SUB_DISPLAY)) {
		if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM) {
			/*mac5p need use sub vgip */
	//		fw_scaler_cal_scale_down_size();

			/*livezoom sub path, ,main uzd to sub vgip*/
	//		drvif_color_ultrazoom_config_livezoompathselect(TRUE);
			// Set in the scale up&down
	//		drvif_color_ultrazoom_config_scaling_down(Scaler_DispCheckRatio(SLR_RATIO_PANORAMA));

			/*update vgip para to main uzd output size*/
	//		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, 0);
	//		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID));
	//		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, 0);
	//		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN));
		} else {
			//tmp code
			return result;
		}
	}

	if(DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == TRUE || (Get_LivezoomOffMainForceBG() == TRUE && Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) <= 3000)) {
		/*no need run vgip to di for livezoom main*/
		return result;
	}
	/* setup capture window */
	fw_scaler_set_vgip_capture(info->display);

	if (info->display== SLR_SUB_DISPLAY) {
		sub_vgip_sub_vgip_444to422_ctrl_RBUS sub_vgip_444to422_ctrl;
		sub_vgip_444to422_ctrl.regValue = IoReg_Read32(SUB_VGIP_SUB_VGIP_444to422_CTRL_reg);
		sub_vgip_444to422_ctrl.sort_fmt = !(Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP));
		IoReg_Write32(SUB_VGIP_SUB_VGIP_444to422_CTRL_reg, sub_vgip_444to422_ctrl.regValue);
	}

	// Attention: This bit may be set as enable again in memory_3ddma_control()
	fw_scaler_set_vgip_3d_mode(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), _DISABLE);

#if 1
	//USER:Lewis DTAE:2015/09/29
	//PIP no 3D
	if(SLR_MAIN_DISPLAY == info->display)
	{
		if((TRUE == DbgSclrFlgTkr.Sub_OuputDisplayMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputVencMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputMemoryMode) || (TRUE == DbgSclrFlgTkr.Sub_OutputAveMode))
		{
			fw_scaler_set_vgip_frame_packing_3d_mode(_FALSE);
		}
		else// if(((FALSE == DbgSclrFlgTkr.Sub_OuputDisplayMode) && (FALSE == DbgSclrFlgTkr.Sub_OutputVencMode) && (FALSE == DbgSclrFlgTkr.Sub_OutputMemoryMode) && (FALSE == DbgSclrFlgTkr.Sub_OutputAveMode)))
		{
			if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
				if(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING)
					fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
				else
					fw_scaler_set_vgip_frame_packing_3d_mode(_FALSE);
			}
#ifdef ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE // [SG] HDMI FP video in M-domain frame sequence 3D output mode
			else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == FALSE)
				&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING) && (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
				fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
#endif // [SG] MVC 3D data FRC path (M-domain data FRC sequence 3D output)
			else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && modestate_get_vo3d_in_framePacking_FRC_mode())
				fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
			else
				fw_scaler_set_vgip_frame_packing_3d_mode(_FALSE);
		}
	}
	else// if(SLR_SUB_DISPLAY == info->display)
	{
		fw_scaler_set_vgip_frame_packing_3d_mode(_FALSE);
	}
#else //#if 1
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
		if(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING)
			fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
		else
			fw_scaler_set_vgip_frame_packing_3d_mode(_FALSE);
		}
#ifdef ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE // [SG] HDMI FP video in M-domain frame sequence 3D output mode
	else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == FALSE)
		&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING) && (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
		fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
#endif // [SG] MVC 3D data FRC path (M-domain data FRC sequence 3D output)
	else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && modestate_get_vo3d_in_framePacking_FRC_mode())
		fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
	else
		fw_scaler_set_vgip_frame_packing_3d_mode(_FALSE);
#endif //#if 1

	return result;
}

static void modestate_check_prtnr(void)
{
	di_im_di_rtnr_new_control_RBUS rtnr_new_Ctrl;
	rtnr_new_Ctrl.regValue = IoReg_Read32(DI_IM_DI_RTNR_NEW_CONTROL_reg);
	if(Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)>1920){
		rtnr_new_Ctrl.prtnr_4k2k = 0x1;		//4K2K support
	}else{
		rtnr_new_Ctrl.prtnr_4k2k = 0x0;
	}
	IoReg_Write32(DI_IM_DI_RTNR_NEW_CONTROL_reg, rtnr_new_Ctrl.regValue);
}

static void modestate_decide_rtnr(void)
{
	SLR_VOINFO* pVOInfo;

	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY) {
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_RTNR, FALSE);
		return;
	}

#if 0// [S4AP-358]-- [FIX-ME] S4AP H-scaling down need before DI/RTNR
	if (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > REDUCE_DI_WIDTH_LIMIT_THRESHOLD) {
		//case and Livezoom. We disable RTNR
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "[4k2k] RTNR OFF in S4AP 4k2k \n");
		return;
	}
#endif

#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
	//Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
	//return;
#endif

#ifdef FORCE_BYPASS_DI_RTNR
//Debug use. Interlace timing don't go rtnr and DI
	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)
	{
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);//don't go rtnr
		return;
	}
#endif

	/* in Main channel, RTNR is controlled by AP , AP controlled table priority is higher than others*/
	if ((Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) && (get_current_driver_pattern(DRIVER_RTNR_PATTERN) == DI_RTNR_OFF)) {
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		rtd_printk(KERN_INFO, TAG_NAME_VSC, "Decide RTNR, RTNR OFF by AP table\n");
	} else {
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
		rtd_printk(KERN_INFO, TAG_NAME_VSC, "Decide RTNR, RTNR ON by AP table\n");
	}
	if((Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) && 
		DbgSclrFlgTkr.RGB444Mode &&(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI))
    {
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		rtd_printk(KERN_INFO, TAG_NAME_VSC, "RTNR off by rgb444mode\n");
	}
	return;

	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)
	{//temp flow for livezoom
		if(Get_Live_zoom_mode()== LIVE_ZOOM_SUB)
		{//4
			if (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > 3000) {
				//case and Livezoom. We disable RTNR
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "[4k2k] RTNR OFF in 4k2k Livezoom case\n");
				return;
			}
			if (get_LiveZoomPcmodeDiableRTNR()){
				//case and Livezoom and pc mode. We disable RTNR
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "[4k2k] RTNR OFF in 4k2k Livezoom case\n");
				return;
			}

		}

		//RGB444 & 4k2k disable RTNR @Crixus 20160902
		if((Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422CAP) == FALSE) &&
            ((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI) || (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_JPEG)))
        {
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
			//printk(KERN_EMERG"[crixus]RGB444 disable RTNR\n");
			return;
		}
	}
	//20151124 roger, sub don't open RTNR
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) {
	       modestate_check_prtnr();
	}

	pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());

	// frank@0207 disable DI/RTNR to reduce bandwidth usage
	if (Scaler_InputSrcGetMainChType() == _SRC_VO)
	{
//		if((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 1080))		//4k2k
//			Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
//		else
		#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
		if(vbe_disp_get_adaptivestream_fs_mode()==1){
			if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>3000) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>495)){
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
			}else{
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
			}
			return;
			#if 0
			if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>3000)
			{
				if ((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)==1 || Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)<500) ||vsc_get_adaptivestream_flag()) 	//	FRAMESYNC mode
					Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
				else
					Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
				return;
			}
			else
			{
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);//Vo always enable RTNR
				return;
			}
			#endif
		} else if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>1920)
		#else
		if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>1920)
		#endif
		{
#if 0
			if ((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)==1 || Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)<500) ||vsc_get_adaptivestream_flag())		//  FRAMESYNC mode
			{
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
			}else{
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
			}
#endif
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
			return;
		}
		else
		{
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);//Vo always enable RTNR
			return;
		}
	}

	// force enable DI/NR when need enable HSD & VSD in the same time
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
		if((Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) < Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID))
			&& (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF))
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[3D] Force Enable RTNR in SBS 3D, Width In/Out[%d/%d]\n", Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
			return;
		}
	}

#ifdef ENABLE_DRIVER_I3DDMA
	if(Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == TRUE){
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		return;
	}
#endif

	// [SG] disable RTNR in 4k2k 3D mode
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == FALSE)
		&& (Scaler_InputSrcGetMainChType() == _SRC_VO) && (Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) != SLR_3DMODE_2D)
		&& (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) >= 3840))
	{
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[RTNR] disable in 4k2k 3D mode\n");
		return;
	}

	//Elsie 20130314, force it to enter RTNR if source is CVBS.
	if(Scaler_InputSrcGetMainChType() == _SRC_CVBS)
	{
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR,TRUE);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[CVBS] RTNR ON\n");
		return;
	}
#ifdef CONFIG_RTNR_4K2K
	// [#0048022] 4k1k/4k2k video ratio mode 4:3 will cause RTNR fail
	if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 2048)
			&& (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >= 1080)){	// 4k1k/4k2k
		drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
		//frank@20130604 add below patch code for mantis#40619 solve DI readstart bits not enough problem
		if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)-Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID)) < 960)
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, TRUE);
		else
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		return;
	}
#endif

	// disable DI/RTNR in VO source HD video 3D mode due to no enough memory space
	if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (drvif_scaelr3d_decide_is_3D_display_mode() == TRUE)
		&& (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > 720))
	{
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		return;
	} // Disable RTNR in MVC 3D
	else if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (pVOInfo->mode_3d == VO_3D_FRAME_PACKING) && (!pVOInfo->force2d))
	{
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[VO][3D] NR OFF\n");
		return;
	}


	// JPEG doesn't enter RTNR
	if ((Scaler_InputSrcGetMainChType()==_SRC_VO) && (Scaler_VOFromJPEG(Scaler_Get_CurVoInfo_plane()) == 1)) {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_RTNR, FALSE);
		return;
	}

	#if 0	//20150817 roger mark, merlin do not have double DVS condition
	if (/*Scaler_PipGetInfo(SLR_PIP_ENABLE) && */modestate_decide_double_dvs_enable()) { //avoid memory allocate is not enough
		// Only main display can enter GIBI and RTNR should be closed
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		return;
	}
	#endif
#ifdef CONFIG_DUAL_CHANNEL
	// Sub doesn't enter RTNR.
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY) {
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_RTNR, FALSE);
		return;
	}
#endif

	// [#0048022] 4k1k/4k2k video ratio mode 4:3 will cause RTNR fail

	if((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 2160)|| (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 4096)){//3   		//input frame paking case avoid scaler memory not enough
		//rika20151120 updated
		//let w=4096 goes rtnr, too
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, FALSE);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[4k2k] RTNR OFF in 4k2k\n");
		return;
	}

	if (Scaler_InputSrcGetMainChType() != _SRC_VGA) {
		if ( ((Scaler_InputSrcGetMainChFrom()==_SRC_FROM_TMDS) && (!drvif_IsHDMI())) ||
			((Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE) == 0) && (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422CAP) == FALSE) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)) ) // DVI don't enter RTNR
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_RTNR, FALSE);
		else
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_RTNR, TRUE);
	} else { // VGA don't enter RTNR
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_RTNR, FALSE);
	}
	//vflip rtnr check again
#ifdef CONFIG_DUAL_CHANNEL
	// if main needs RTNR but sub allocates DI, we have to release sub.
	if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR)) {
			if (Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_THRIP) || Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_RTNR)) {
				/*Scaler_ForceBg(SLR_SUB_DISPLAY, SLR_FORCE_BG_SYSTEM, TRUE);*/
				fw_scalerip_disable_ip(SLR_SUB_DISPLAY);
				//frank@0528 Sove QCBUG10151 push below to set sub channel i,m,d domain to avoid sub set display but DI disable by main channel
				//flow_message_push(_MODE_MSG_SUB_SET_VGIP_AFTER_FOUND_MODE_SIGNAL);
				//flow_message_clearallType(_MODE_MSG_SUB_SETUP_BEFORE_SHOW_SIGNAL);
				//mark by frank@0528 flow_message_push(_MODE_MSG_SUB_SETUP_AFTER_FOUND_MODE_SIGNAL);
				Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_THRIP, FALSE);
				Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_RTNR, FALSE);
			}
	}
#endif
}

static void modestate_decide_DI(void)
{
	//unsigned char source = fwif_vip_source_check(3, 0);
	UINT32 picWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	//unsigned char display_mode = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	UINT32 timingMode;
	// Elsie 20131106: playback always does not use RTNR 10-bit mode.
	// 20131210 sync from Mac2
	unsigned int modeByAP_table;
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY)
	{
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, FALSE);
		/*warning: sub could not set main di 10bit or 8bit flag*/
		//fw_scalerip_set_DI_chroma_10bits(FALSE);
#ifdef CONFIG_I2RND_ENABLE
	}else if((Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, FALSE);
		fw_scalerip_set_DI_chroma_10bits(TRUE);
		printk(KERN_EMERG"[%s]I2rnd go 8bits!!!!!!\n", __FUNCTION__);
#endif
	} else if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)  == SLR_MAIN_DISPLAY)) {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, FALSE);
		fw_scalerip_set_DI_chroma_10bits(TRUE);
	} else if (vsc_get_adaptivestream_flag() && (Scaler_InputSrcGetMainChType() == _SRC_VO) ){
		//if <1080, di10bit , >1080 di 8bit
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, TRUE);

		if(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) > 1080){
			fw_scalerip_set_DI_chroma_10bits(TRUE);
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "_rk adaptive >2k1k force 8bit\n");

		}
		else{
			fw_scalerip_set_DI_chroma_10bits(TRUE);
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "_rk adaptive 2k1k force 10bit\n");
		}
	} else if (Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && get_3D_overscan_enable() &&
		((Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF) || (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM) || (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING))) {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, FALSE);
		fw_scalerip_set_DI_chroma_10bits(FALSE);
	}
	else if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC) && (Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane()) == SOURCE_VIDEO)
		&& (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > 3000) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) >= 480)
		&& (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE) && (Get_DISPLAY_PANEL_OLED_TYPE() == TRUE))
	{ // [OLED panel] data FRC force in 8bit capture mode
		Scaler_DispSetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) , SLR_DISP_10BIT, FALSE);
	} else if ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) > 1080) && (Scaler_InputSrcGetMainChType() == _SRC_VO)) {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, TRUE);
		fw_scalerip_set_DI_chroma_10bits(TRUE);
	} else {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, TRUE);
		fw_scalerip_set_DI_chroma_10bits(TRUE);
	}

	//VP9 case use 8 bits setting @Crixus 20160407	2192
	if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (get_vo_vp9_flag(Get_DisplayMode_Port(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))))) {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT, FALSE);
		fw_scalerip_set_DI_chroma_10bits(FALSE);
	}



	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[VSC] src/vdec/wid/freq, fs/10/olde=%d/%d/%d/%d, %d/%d/%d\n",
		Get_DisplayMode_Src(SLR_MAIN_DISPLAY), Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane()),
		Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE), Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ), Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC),
		Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT), Get_DISPLAY_PANEL_OLED_TYPE());


#if 1//def REDUCE_DIBW_ENABLE
//	UINT32 picWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);

	// [XF112HAICNRTK1-88] linmc@20120712, reduce di bandwidth to resolve flicker picture screen happened
	//if (setManualReduceDIBW != NULL)
	//	setManualReduceDIBW();
	//else
	{
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
		//USER:LewisLee DATE:2012/12/20
		//fix VDC 27MHz mode, picture abnormal
		if(VD_27M_OFF != fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
		{
			picWidth = picWidth>>1;
		}
#endif //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

		// for playback source memory/bandwidth issue (24bit DI only for SD video--480i/576i)
		timingMode =  Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);

		//Elsie 20131210: Enable BTR mode when source is 1080i. 20140211: Always disable BTR when source is playback.
		if((Scaler_InputSrcGetMainChType() != _SRC_VO) && (timingMode == _MODE_1080I25 || timingMode==_MODE_1080I30))
		{
			drv_memory_set_ip_Btr_mode(_ENABLE);
			drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
		}
		else if (picWidth > REDUCE_DI_BANDWIDTH_LIMIT_THRESHOLD)
		{
			drv_memory_set_ip_Btr_mode(_DISABLE);
			if(Scaler_InputSrcGetMainChType() == _SRC_VO){
				if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 2048)&& (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >= 1080)){		// 4k2k
					drv_memory_set_ip_DMA420_mode(SLR_DMA_400_mode);
				} else {
					drv_memory_set_ip_DMA420_mode(SLR_DMA_420_mode);
				}
			}
	                //frank@0904 add below code to avoid DI memory trash
			else if(Get_PANEL_VFLIP_ENABLE()){
				drv_memory_set_ip_DMA420_mode(SLR_DMA_420_mode);
			}
			else if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 2048)
			&& (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >= 1080)){
				drv_memory_set_ip_DMA420_mode(SLR_DMA_420_mode);				/*WOSQRTK-2096*/
			}
			else
			{
				drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
			}
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DI] DI BTR/420[%d/%d], width=%d!\n", drv_memory_get_ip_Btr_mode(), drv_memory_get_ip_DMA420_mode(), picWidth);
		}
		else{
		#if 0
			if(Scaler_InputSrcGetMainChType() == _SRC_VO) {
				drv_memory_set_ip_Btr_mode(_DISABLE);
				drv_memory_set_ip_DMA420_mode(SLR_DMA_420_mode);
			} else {
		#endif
				drv_memory_set_ip_Btr_mode(_ENABLE);
				drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
		//	}
		}
	}
#else

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
	//USER:LewisLee DATE:2012/12/20
	//fix VDC 27MHz mode, picture abnormal
	if(VD_27M_OFF != fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
	{
		picWidth = picWidth>>1;
	}
#endif //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE


	if (picWidth > REDUCE_DI_BANDWIDTH_LIMIT_THRESHOLD){
		if((Scaler_InputSrcGetMainChType() == _SRC_HDMI)&&((_MODE_1080I25 == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_CURR))||(_MODE_1080I30 == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_CURR))) )
		{
			drv_memory_set_ip_Btr_mode(_ENABLE);//for 1080i video book Di 1 #chapter_10
			drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
		}
		else
		{
			drv_memory_set_ip_Btr_mode(_DISABLE);
			drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
  #if 0 // [IDMA] IDMA 3D reduce bandwidth issue (Sensio 3D mode)
			if((Scaler_InputSrcGetMainChType() == _SRC_VO) && modestate_I3DDMA_get_In3dMode() && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) >= REDUCE_DI_BW_VFREQ_THRESHOLD))
				drv_memory_set_ip_DMA420_mode(SLR_DMA_420_mode);
			else
				drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);

			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[DBG] V_Freq=%d\n", Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));
  #endif
		}
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DI] DI BTR/420[%d/%d], width=%d!!\n", drv_memory_get_ip_Btr_mode(), drv_memory_get_ip_DMA420_mode(), picWidth);
	}
	else{
		drv_memory_set_ip_Btr_mode(_ENABLE);
		drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
	}
#endif

#ifdef CONFIG_DUAL_CHANNEL
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY) {
#if 0//frank@1008 simple the PIP flow
		// main need DI, just return
		if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_THRIP) ||		// use DI's IP
			Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE) ||	// interlace source
			Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_RTNR))	{		// RTNR (because RTNR and DI uses the same IP)
				Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_THRIP,FALSE);
				return;
		}

		// main don't need DI, if sub need, sub get it!
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP, TRUE);
		return;
#else
		//add HDMI sub channel field control @Crixus 20151203
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
			DbgSclrFlgTkr.multiview_sub_interlace_flag = TRUE;
		else
			DbgSclrFlgTkr.multiview_sub_interlace_flag = FALSE;

		//sub always don't go DI
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_THRIP, FALSE);
		return;
#endif
	}
#endif

	// now handle main display
	//if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE)) {
	if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
#ifdef CONFIG_DUAL_CHANNEL
		if (Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_THRIP) || Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_RTNR)) {
			/*Scaler_ForceBg(SLR_SUB_DISPLAY, SLR_FORCE_BG_SYSTEM, TRUE);*/
			fw_scalerip_disable_ip(SLR_SUB_DISPLAY);
			//frank@0528 Sove QCBUG10151 push below to set sub channel i,m,d domain to avoid sub set display but DI disable by main channel
			/*flow_message_push(_MODE_MSG_SUB_SET_VGIP_AFTER_FOUND_MODE_SIGNAL);
			flow_message_clearallType(_MODE_MSG_SUB_SETUP_BEFORE_SHOW_SIGNAL);*/
			//mark by frank@0528 flow_message_push(_MODE_MSG_SUB_SETUP_AFTER_FOUND_MODE_SIGNAL);
			Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_THRIP, FALSE);
			Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_RTNR, FALSE);
		}
#endif
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP, TRUE);
	}
	else
	{
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP, FALSE);
	}

	/* in Main channel, DI is controlled by AP , AP controlled table priority is higher than others*/
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) {
		modeByAP_table = get_current_driver_pattern(DRIVER_RTNR_PATTERN);
		if (modeByAP_table == DI_RTNR_422) {
			drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
		} else if (modeByAP_table == DI_RTNR_420) {
			drv_memory_set_ip_DMA420_mode(SLR_DMA_420_mode);
		} else if (modeByAP_table == DI_RTNR_400) {
			if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) == 0)
				drv_memory_set_ip_DMA420_mode(SLR_DMA_400_mode);
			else
				drv_memory_set_ip_DMA420_mode(SLR_DMA_422_mode);
		} else {
			rtd_printk(KERN_EMERG, TAG_NAME_VSC, "Decide DI by AP, get table parameter error, table value = %d\n", modeByAP_table);
		}
		rtd_printk(KERN_INFO, TAG_NAME_VSC, "Decide DI, AP Val=%d, isInterlace=%d,\n", modeByAP_table, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE));
	}

}

static void modestate_decide_nr_path(void)
{
	/* select bypass, NR or VUZD */
	if(Scaler_DispGetScaleStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_SCALE_V_DOWN)){  // go vuzd path
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_FSYNC_VUZD, VUZD_BUFFER_VUZD_MODE);
	}else{
		if (Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))   //sub channal no NR path
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_FSYNC_VUZD, VUZD_BUFFER_BYPASS_MODE);
		else
		{
			if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {//WOSQRTK-6131 Patch
				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_FSYNC_VUZD, VUZD_BUFFER_FRAMESYNC_MODE);
			} else {
				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_FSYNC_VUZD, VUZD_BUFFER_BYPASS_MODE);
			}
		}
	}
}

static void modestate_setup_vgip_even_odd_toggle(void)
{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	unsigned short channel = Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL);
#endif

	//CSW+ 0970710 Sub Channel(480i or 576i or 1080i50 or 1080i60) interlace mode by video compensation
	if(Scaler_InputSrcGetMainChType() == _SRC_YPBPR || Scaler_InputSrcGetMainChType() == _SRC_VGA) {
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY){				//ch2
			if(!Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_THRIP))	//video comp
				IoReg_Mask32(channel ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg, ~_BIT18, 0x00);			//odd signal inverted disable
			else										//di or progressive
				IoReg_Mask32(channel ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg, ~_BIT18, _BIT18);			//odd signal inverted enable
		}
#endif
	}
	else if((Scaler_InputSrcGetMainChType() == _SRC_TV) || (Scaler_InputSrcGetMainChType() == _SRC_CVBS) || (Scaler_InputSrcGetMainChType() == _SRC_SV)){
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY){				//ch2
			if(!Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_THRIP))	//video comp
			{
				if ((Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_AVD) && (!get_sub_OutputVencMode()))
				{
					// AVD display in sub channel.
					IoReg_Mask32(channel ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg, ~_BIT18, 0x0);			//odd signal inverted disable
				}
				else
				{
					// APVR recording by sub channel
					IoReg_Mask32(channel ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg, ~_BIT18, _BIT18);			//odd signal inverted enable
				}
			}
			else
			{
				//di or progressive
				IoReg_Mask32(channel ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg, ~_BIT18, 0x00);			//odd signal inverted disable
			}
		}
#endif
	}
	else if(Scaler_InputSrcGetMainChType() == _SRC_HDMI){
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)
		{
			IoReg_Mask32(VGIP_VGIP_CHN1_CTRL_reg, ~(_BIT16|_BIT18), (_BIT16|_BIT18));
		}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		//add HDMI sub channel field control @Crixus 20151203
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY){				//ch2
			if(!DbgSclrFlgTkr.multiview_sub_interlace_flag){//(!Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_INTERLACE)){//!Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_THRIP)){	//video comp
				IoReg_Mask32(channel ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg, ~_BIT18, 0x00);			//odd signal inverted disable
			}
			else{										//di or progressive
				IoReg_Mask32(channel ? SUB_VGIP_VGIP_CHN2_CTRL_reg : VGIP_VGIP_CHN1_CTRL_reg, ~_BIT18, _BIT18); 		//odd signal inverted enable
			}
		}
#endif
	}
}


static void modestate_EnableVGIPInt(unsigned char a_bEnable)
{
	// I-domain VGIP Int Ctl
	vgip_int_ctl_RBUS tVGIPIntCtl;

	// Read init value
	tVGIPIntCtl.regValue = IoReg_Read32(VGIP_INT_CTL_reg);

	if (TRUE == a_bEnable)
	{
		// Enable VGIP Interrupt
		tVGIPIntCtl.vgip_int_ie = 1;
	}
	else
	{
		// Disable VGIP interrupt
		tVGIPIntCtl.vgip_int_ie = 0;
	}

	// Update value
	IoReg_Write32(VGIP_INT_CTL_reg, tVGIPIntCtl.regValue);


}

#ifdef CONFIG_SDNR_CROP
extern unsigned int getFactorUZD(unsigned int inVal, bool bFlag, unsigned char uDisplay);

static void modestate_decide_SDNR(unsigned char channel)
{
	VIDEO_RECT_T  outregion;
	outregion.x = Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_STA);
	outregion.y = Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_STA);
	outregion.w = Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID);
	outregion.h = Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN);

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"outregion.x=%d\n", outregion.x);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"outregion.y=%d\n", outregion.y);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"outregion.w=%d\n", outregion.w);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"outregion.h=%d\n", outregion.h);

#if 0
	printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	printk(KERN_EMERG "outregion.x=%d\n", outregion.x);
	printk(KERN_EMERG "outregion.y=%d\n", outregion.y);
	printk(KERN_EMERG "outregion.w=%d\n", outregion.w);
	printk(KERN_EMERG "outregion.h=%d\n", outregion.h);
#endif

	if (channel == SLR_MAIN_DISPLAY)
	{
		scaledown_ich1_sdnr_cutout_range_hor_RBUS ich1_sdnr_cutout_range_hor_reg;
		scaledown_ich1_sdnr_cutout_range_ver0_RBUS ich1_sdnr_cutout_range_ver0_reg;
		scaledown_ich1_sdnr_cutout_range_ver1_RBUS ich1_sdnr_cutout_range_ver1_reg;

		ich1_sdnr_cutout_range_hor_reg.regValue = IoReg_Read32(SCALEDOWN_ich1_sdnr_cutout_range_hor_reg);
		ich1_sdnr_cutout_range_hor_reg.hor_front= outregion.x;
		ich1_sdnr_cutout_range_hor_reg.hor_back= outregion.x+outregion.w+1; // chip setting need to +1
		IoReg_Write32(SCALEDOWN_ich1_sdnr_cutout_range_hor_reg, ich1_sdnr_cutout_range_hor_reg.regValue);

		ich1_sdnr_cutout_range_ver0_reg.regValue = IoReg_Read32(SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg);
		ich1_sdnr_cutout_range_ver0_reg.ver_front= outregion.y;
		ich1_sdnr_cutout_range_ver0_reg.ver_back= outregion.y+outregion.h+1;	// chip setting need to +1
		IoReg_Write32(SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg, ich1_sdnr_cutout_range_ver0_reg.regValue);

		ich1_sdnr_cutout_range_ver1_reg.regValue = IoReg_Read32(SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg);
		ich1_sdnr_cutout_range_ver1_reg.ver_mid_top=0;	// inregion.y;
		ich1_sdnr_cutout_range_ver1_reg.ver_mid_bot=0;	// inregion.y;
		IoReg_Write32(SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg, ich1_sdnr_cutout_range_ver1_reg.regValue);

//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_hor_front = %d \n", outregion.x);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_front = %d \n", outregion.y);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_mid_top = %d \n", outregion.y);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_mid_bot = %d \n", outregion.y);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_hor_back = %d \n", outregion.x+outregion.w);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_back = %d \n", outregion.y+outregion.h);

		scaledown_ich1_uzd_ctrl0_RBUS 	ich1_uzd_Ctrl0_REG;
		ich1_uzd_Ctrl0_REG.regValue = IoReg_Read32(SCALEDOWN_ICH1_UZD_Ctrl0_reg);
		ich1_uzd_Ctrl0_REG.cutout_en = 1;
		IoReg_Write32(SCALEDOWN_ICH1_UZD_Ctrl0_reg, ich1_uzd_Ctrl0_REG.regValue);
	}
	else
	{
	#if 0//mac5p no sub sdnr
		scaledown_ich2_sdnr_cutout_range_hor_RBUS ich2_sdnr_cutout_range_hor_reg;
		scaledown_ich2_sdnr_cutout_range_ver0_RBUS ich2_sdnr_cutout_range_ver0_reg;
		scaledown_ich2_sdnr_cutout_range_ver1_RBUS ich2_sdnr_cutout_range_ver1_reg;

		ich2_sdnr_cutout_range_hor_reg.regValue = IoReg_Read32(SCALEDOWN_ich2_sdnr_cutout_range_hor_reg);
		ich2_sdnr_cutout_range_hor_reg.hor_front= outregion.x;
		ich2_sdnr_cutout_range_hor_reg.hor_back= outregion.x+outregion.w+1; // chip setting need to +1
		IoReg_Write32(SCALEDOWN_ich2_sdnr_cutout_range_hor_reg, ich2_sdnr_cutout_range_hor_reg.regValue);

		ich2_sdnr_cutout_range_ver0_reg.regValue = IoReg_Read32(SCALEDOWN_ich2_sdnr_cutout_range_ver0_reg);
		ich2_sdnr_cutout_range_ver0_reg.ver_front= outregion.y;
		ich2_sdnr_cutout_range_ver0_reg.ver_back= outregion.y+outregion.h+1;	// chip setting need to +1
		IoReg_Write32(SCALEDOWN_ich2_sdnr_cutout_range_ver0_reg, ich2_sdnr_cutout_range_ver0_reg.regValue);

		ich2_sdnr_cutout_range_ver1_reg.regValue = IoReg_Read32(SCALEDOWN_ich2_sdnr_cutout_range_ver1_reg);
		ich2_sdnr_cutout_range_ver1_reg.ver_mid_top=0;	// inregion.y;
		ich2_sdnr_cutout_range_ver1_reg.ver_mid_bot=0;	// inregion.y;
		IoReg_Write32(SCALEDOWN_ich2_sdnr_cutout_range_ver1_reg, ich2_sdnr_cutout_range_ver1_reg.regValue);

//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_hor_front = %d \n", outregion.x);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_front = %d \n", outregion.y);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_mid_top = %d \n", outregion.y);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_mid_bot = %d \n", outregion.y);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_hor_back = %d \n", outregion.x+outregion.w);
//		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "******************reg_ver_back = %d \n", outregion.y+outregion.h);

		scaledown_ich2_uzd_ctrl0_RBUS ich2_uzd_ctrl0_reg;
		ich2_uzd_ctrl0_reg.regValue = IoReg_Read32(SCALEDOWN_ICH2_UZD_Ctrl0_reg);
		ich2_uzd_ctrl0_reg.cutout_en = 1;
		IoReg_Write32(SCALEDOWN_ICH2_UZD_Ctrl0_reg, ich2_uzd_ctrl0_reg.regValue);
	#endif
	}
}

#endif

static void modestate_setup_idomain(StructDisplayInfo* info)
{
	modestate_decide_pixel_mode();

	modestate_decide_dtg_m_mode();

	modestate_decide_fractional_framesync();

	// Calculate main or sub display width and display height and set it to info
	// remember main's display width/height may change later if display ratio is
	// pointer to pointer
	fw_scalerdisplay_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));

//	decide which channel to use DI
	modestate_decide_DI();

#ifdef CONFIG_SDNR_CROP
	/* Decide RTNR flag */
	modestate_decide_rtnr();

	//for HSD enable
	Scaler_AdjustPathAndInfo();/*Will add. decide Uzd path*/

	// Calculate Overscan
	fw_scaler_cal_sdnr_capture(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
#endif

	// Calculate the output size of scale down
	fw_scaler_cal_scale_down_size();

#ifdef CONFIG_SDNR_CROP
	// Move Position for get RTNR flag
#else
	/* Decide RTNR flag */
	modestate_decide_rtnr();
#endif

	/*Decide NR buffer mode,move from fw_scaler_cal_scale_down_size to support new NR path limit*/
	modestate_decide_nr_path();

	// Set in the scale up&down
	if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) && (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM)) {
		/*livezoom main path, jump main uzd*/
		drvif_color_ultrazoom_config_livezoompathselect(TRUE);
	} else if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY) && (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM)){
		sub_VGIP_sample_needDItiming(TRUE);
		drvif_color_ultrazoom_config_scaling_down(Scaler_DispCheckRatio(SLR_RATIO_PANORAMA));
	} else {
		drvif_color_ultrazoom_config_livezoompathselect(FALSE);
		// Set in the scale up&down
		drvif_color_ultrazoom_config_scaling_down(Scaler_DispCheckRatio(SLR_RATIO_PANORAMA));
	}

	//DI game mode checking & setting in scaler flow @Crixus 20161217
	if(fw_scalerip_get_di_gamemode() == _ENABLE){
		fw_scalerip_set_di_gamemode_setting(_ENABLE);
		//printk(KERN_EMERG"[Game Mode]Enter DI game mode\n");
	}
	else{
		fw_scalerip_set_di_gamemode_setting(_DISABLE);
		//printk(KERN_EMERG"[Game Mode]Exit DI game mode\n");
	}

	if(DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == TRUE || (Get_LivezoomOffMainForceBG() == TRUE && Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) <= 3000)
		||((get_rotate_mode()!=get_ori_rotate_mode()) && get_ori_rotate_mode()!= DIRECT_VO_FRAME_ORIENTATION_DEFAULT)) {
		pr_emerg("[rotate] no run vgip&di\n");
		/*no need run vgip to di for livezoom main*/
	} else  {
		// Disable VGIP Interrupt and let DI can be enabled.
		if(get_sub_OutputVencMode() == TRUE)
			IoReg_ClearBits(VGIP_VGIP_CHN1_CTRL_reg, _BIT24|_BIT25);
		else
			modestate_EnableVGIPInt(FALSE);

		//DI control setting
		down(get_DI_semaphore());
		fw_scalerip_set_di();
		up(get_DI_semaphore());
		// Enable VGIP Interrupt
		if(get_sub_OutputVencMode() == TRUE)
			IoReg_SetBits(VGIP_VGIP_CHN1_CTRL_reg, _BIT24|_BIT25);
		else
			modestate_EnableVGIPInt(TRUE);
	}
#ifdef CONFIG_SDNR_CROP
	modestate_decide_SDNR(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
#endif


#ifdef CONFIG_VGA_AUTO_MA_ENABLE
	// enable AutoMA in VGA source

	if ( Scaler_InputSrcGetType(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == _SRC_VGA ) {
		drvif_scaler_vactive_end_irq(_ENABLE, info->display); // enable automa ISR
		drvif_scaler_vactive_sta_irq(_ENABLE, info->display); // enable automa ISR
	}
#endif
#if 0/*Framesync also need to enable VGIP ISR*/
    if((_FALSE == Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) /*&& (_ENABLE == drvif_memory_sw_buffer_swap_Enable((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))*/)
#endif
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
		drvif_scaler_vactive_end_irq(_ENABLE, SLR_MAIN_DISPLAY);
		drvif_scaler_vactive_sta_irq(_ENABLE, SLR_MAIN_DISPLAY);
	} else {
#ifdef  CONFIG_I2RND_ENABLE
#else
		drvif_scaler_vactive_end_irq(_ENABLE, SLR_SUB_DISPLAY);
		drvif_scaler_vactive_sta_irq(_ENABLE, SLR_SUB_DISPLAY);
#endif
	}

#if 1
	if(get_3D_mode_enable() == TRUE && get_vo_3d_mode() == VO_3D_FRAME_PACKING && Scaler_InputSrcGetType(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == _SRC_VO)
	{
		drvif_scaler_vactive_end_irq(_DISABLE, SLR_MAIN_DISPLAY);
		drvif_scaler_vactive_sta_irq(_DISABLE, SLR_MAIN_DISPLAY);
	}
#endif

	#ifndef CONFIG_FORCE_RUN_I3DDMA	//not define
	//CSW+ 0970710 Sub Channel(480i or 576i or 1080i50 or 1080i60) interlace mode by video compensation
	modestate_setup_vgip_even_odd_toggle();
	#endif

#if 0
/*
	In mac5
	 When 3 line mode : input width <= 4096
	 When 5 line mode : input width <= 4096
	 When 11line mode : input width <= 2048
	 not a reasonable setting = 0 on mac5p, so remove it.
*/
	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)
	{
		//Q-7467 capture nosie frame because the line mode correction in D domain <- too late.
		//		 So move it up to here, I domain.
		//edgesmooth
		iedge_smooth_edgesmooth_ex_ctrl_RBUS edgesmooth_ex_ctrl_reg;
		edgesmooth_ex_ctrl_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg);
		edgesmooth_ex_ctrl_reg.lbuf_linemode = 0; //3 line
		IoReg_Write32(IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg, edgesmooth_ex_ctrl_reg.regValue);

		//edsm db
		iedge_smooth_edsm_db_ctrl_RBUS edsm_db_ctrl_reg;
		edsm_db_ctrl_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_EDSM_DB_CTRL_reg);
		edsm_db_ctrl_reg.edsm_db_apply = 1;
		IoReg_Write32(IEDGE_SMOOTH_EDSM_DB_CTRL_reg, edsm_db_ctrl_reg.regValue);
	}
#endif
}

static void modestate_set_imd_domain(StructDisplayInfo* info)
{
	//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n Setup State: display:%d\n", Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));

	modestate_setup_idomain(info);

	force_enable_datapath_clock();//Force enable Xcdi_clock 0xb8022284 bit3
#ifdef CONFIG_DUAL_CHANNEL
	//when change PIP type to speed up sub channel setting
	/*modestate_set_sub_domain(msg);*/
#endif

}

static unsigned char modestate_set_framesync(StructDisplayInfo* info)
{
//	unsigned char result=0;

#ifdef CONFIG_DCLK_CHECK
	if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
	{
		if (Scaler_OpenVOGating())
		{
		//if((GET_HDMI_3DTYPE() == HDMI3D_FRAMESEQUENCE) &&  Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
		//&& (((Scaler_InputSrcGetMainChType() == _SRC_VO) && (scaler_2Dcvt3D_get_vgip2CurState() == VGIP2_2X_CLK_NON_ACTIVE)) || (scaler_2Dcvt3D_get_vgip2CurState() == VGIP2_2X_CLK_VO_GO)))

			check_dclk2_is_underflow();
		}
		else
		{
			check_dclk_is_underflow();
		}

	}
#endif



	//frank@1011 FRC with frame sync timing so must do calculation IVS2DVS
	fw_scalerdisplay_handler(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));

	// Set in the scale up&down
	drvif_color_ultrazoom_config_scaling_up(Scaler_DispCheckRatio(SLR_RATIO_PANORAMA));

	if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
	//	if(Scaler_InputSrcGetMainChType() != _SRC_VO){

		// Enter FrameSync Setup
		if(Scaler_InputSrcGetMainChType() == _SRC_VGA) {	// weihao 960308
			fw_scaler_update_mode_para(); //update mode parameters after adjust IVS2DVSDelay
		}


		// set display FIFO for Frame sync
		drvif_memory_set_fs_display_fifo();

		//data fs need to disable compression clock @Crixus 20171227
		dvrif_memory_comp_setting(FALSE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID), Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN), dvrif_memory_get_compression_bits());


#ifdef CONFIG_FORCE_RUN_I3DDMA
		if(drv_memory_get_game_mode()){
			if(drvif_i3ddma_triplebuf_flag())
				drv_I3ddmaVodma_SingleBuffer_GameMode(_DISABLE);
			else
				drv_I3ddmaVodma_SingleBuffer_GameMode(_ENABLE);
			}
		else{

			drv_I3ddmaVodma_SingleBuffer_GameMode(_DISABLE);
		}

		/*qiangzhou:all i3ddma source go vodma timing sync i3ddma,all i3ddma source should setting iv2pv delay*/
		if(((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC)
			|| (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
			||((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD)	&& (get_AVD_Input_Source() != _SRC_TV)))
#ifdef CONFIG_ALL_SOURCE_DATA_FS
			//don't care 3 buffer case
			/*&&(!drvif_i3ddma_triplebuf_flag())*/
			&&(!(Get_PANEL_VFLIP_ENABLE()&&Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE) == 1))){
#else
			&&(!drvif_i3ddma_triplebuf_flag())){
#endif
			drv_I3ddmaVodma_GameMode_iv2pv_delay(TRUE);
		} else {
			drv_I3ddmaVodma_GameMode_iv2pv_delay(FALSE);
		}
#endif

#if 0

		if(Scaler_OpenVOGating()){
/*
			if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() ==1){
				//move framesync_gating to disp on
			}else if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K){
				scaler_dtg_reconfig();
				drvif_framesync_gatting_do();
			}
			else
*/
			{
				scaler_dtg_reconfig();
				drvif_framesync_gatting_do();
				/*WaitFor_EN_STOP_MAIN_Done();*/
				//WaitFor_EN_STOP_MAIN_Done();//Will mark no need
				//WaitFor_EN_STOP_MAIN_Done();//Will mark no need
				drvif_framesync_gatting(_DISABLE);
				drvif_framesync_gatting(_ENABLE);
				/*WaitFor_EN_STOP_MAIN_Done();*/
				//WaitFor_EN_STOP_MAIN_Done();//Will mark no need
				//WaitFor_EN_STOP_MAIN_Done();//Will mark no need
			}
		}else{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, KERN_INFO "\r\n[%s][line:%d] Error! Data FS without open gating!!\r\n", __FUNCTION__, __LINE__);
#if 0
				drvif_scaler_set_display_mode_frc2fsync_by_hw(_TRUE);
				result = drvif_framesync_do();

			if(Scaler_InputSrcGetMainChType()==_SRC_VO && (result != 0)){
				drvif_framesync_gatting_do();
				drvif_framesync_gatting(_DISABLE);
				drvif_framesync_gatting(_ENABLE);
				result = 0;
			}else if(Scaler_InputSrcGetMainChType()==_SRC_VO){//frank@0920 open VO gating function to solve mantis#5011
				drvif_framesync_gatting(_DISABLE);
				drvif_framesync_gatting(_ENABLE);
			}

			if (result != 0) {// frame sync fail
#if 0
				drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
				if(Scaler_DispGetInputInfo(SLR_INPUT_FAILURECOUNT) > 0) {
					//drvif_mode_resetmode();
					//Scaler_ForceBg((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_FORCE_BG_SYSTEM, TRUE);
					drvif_mode_disablechannelproc(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
					drvif_mode_disablevgip(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
					#if 0
					if(Scaler_InputSrcGetMainChType()==_SRC_VO) { // hsliao 20090311, VO source requests VO info again
						CVoRequestVoInfo(Scaler_Get_CurVoInfo_plane());
					}
					#endif
					Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_SEARCH); // hsliao 20090311, from active state or search state to search state

#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
					if(_FALSE == modestate_send_ypbpr_and_av_same_path_init_msg())
						flow_message_push(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? _FL2FL_SUB_STATE_PERIODIC_EVENT : _FL2FL_MAIN_STATE_PERIODIC_EVENT);
#else //#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
					flow_message_push(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? _FL2FL_SUB_STATE_PERIODIC_EVENT : _FL2FL_MAIN_STATE_PERIODIC_EVENT);
#endif //#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH

					Scaler_DispSetInputInfo(SLR_INPUT_FAILURECOUNT,0);
				} else {
					flow_message_push(_FL2FL_MAIN_SET_FRAMESYNC_SIGNAL);
					Scaler_DispSetInputInfo(SLR_INPUT_FAILURECOUNT,Scaler_DispGetInputInfo(SLR_INPUT_FAILURECOUNT)+1);
				}
#endif
				// while frame sync fail, must return fail
				// then try again, if frame sync still fail, goto search-state to re-detect signal.
				return FALSE;
			}else{
#ifdef CONFIG_FS_HS_BIAS
				if(drvif_framesync_hs_bias() == FALSE)
					return FALSE;
#endif
				// for gatting debug
				/*if(Scaler_InputSrcGetMainChType()==_SRC_VO){
					drvif_framesync_gatting(_ENABLE);
				}*/

			//	fw_dvi_framesync_setting();

			}
#endif
		}
#endif
#if 0
		if((GET_HDMI_3DTYPE() == HDMI3D_FRAMESEQUENCE) &&  Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
		&& (((Scaler_InputSrcGetMainChType() == _SRC_VO) && (scaler_2Dcvt3D_get_vgip2CurState() == VGIP2_2X_CLK_NON_ACTIVE)) || (scaler_2Dcvt3D_get_vgip2CurState() == VGIP2_2X_CLK_VO_GO)))
		{
			memory_3ddma_control();
			drvif_3ddma_DVTotal_Set(2);
		}
#endif

		//Scaler_DispSetInputInfo(SLR_INPUT_FAILURECOUNT,0);
		if(Get_DISPLAY_PANEL_TYPE() != P_VBY1_4K2K){
			if(!(Scaler_InputSrcGetMainChType() == _SRC_TV && Scaler_GetTvBlueScreen() == FALSE))	// weihao 960308
				fw_scaler_enable_fs_wdg(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), TRUE);
			else
				fw_scaler_enable_fs_wdg(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);
		}
	} else {
#if 0 //frank@0903 mark redundent code
		if(Scaler_InputSrcGetMainChType() == _SRC_VGA) {	// weihao 960308
			fw_scaler_update_mode_para(); //update mode status after set capture window
		}
#endif
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (info->display== SLR_SUB_DISPLAY)&&(Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER)) {
			/*magnifier use main domain capture */
		} else {
			//Set M-domain setting
			dvrif_memory_handler();
		}
#if 0
		//USER:LewisLee DATE:2012/06/21
		//for SW buffer swap, need some IVS2DVS delay
		//to prevent DVS swap buffer too close IVS
		if(SLR_MAIN_DISPLAY == Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))
		{
			if(TRUE == framesync_get_enterlastline_at_frc_mode_flg())
			{
				//it have set ivs2dvs Value
			}
			else// if(FALSE == framesync_get_enterlastline_at_frc_mode_flg())
			{
				//frank@0617 mark below code to speed up,below code will setting by memory_set_input_format
#if 0

				drvif_set_frc_ivs2dvsdelay_line(_FRC_MODE_IVS2DVS_LINE_1, _FRC_MODE_IVS2DVS_LINE_2, 0);
				drvif_set_frc_ivs2dvsdelay_pixel(_FRC_MODE_IVS2DVS_PIXEL_1, _FRC_MODE_IVS2DVS_PIXEL_2, 0);
#endif
			}
		}
//#else //#if 1
		if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)
			drvif_clear_ivs2dvsdelay();

		modestate_set_FRC_fix_last_line();
#endif //#if 1
	}

//USER : LewusLee DATE:2012/11/30
//move position
#if 0
//USER : LewusLee DATE:2012/08/30
//for novatek Tcon IC, too easy to enter burn in mode
//sw we need to set FRC -> Framesync moer smooth
	framesync_adjust_dvtotal_at_framesync_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
#endif

 	return TRUE;

}

void state_update_disp_info(void)	// updated by hsliao 20090515
{
	SCALER_DISPINFO_PKG info_pkg;
	unsigned char i;
	int ret;
	unsigned long ulIPKGItemCount = 0;
	unsigned long *pulTemp;
	for ( i=0 ; i<MAX_DISP_CHANNEL_NUM ; ++i )
	{
		info_pkg.disp_info[i].input_src = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_INPUT_SRC);
		info_pkg.disp_info[i].state = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_STATE);
		info_pkg.disp_info[i].disp_status = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_DISP_STATUS);
		info_pkg.disp_info[i].display = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_DISPLAY);
		info_pkg.disp_info[i].MEM_ACT_WID = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_MEM_ACT_WID);
		info_pkg.disp_info[i].MEM_ACT_LEN = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_MEM_ACT_LEN);
		info_pkg.disp_info[i].MEM_ACT_HSTA = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_MEM_ACT_HSTA);
		info_pkg.disp_info[i].MEM_ACT_VSTA = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_MEM_ACT_VSTA);
		info_pkg.disp_info[i].ucMode_Curr = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_MODE_CURR);
		info_pkg.disp_info[i].DispWid = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_DISP_WID);
		info_pkg.disp_info[i].DispLen = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_DISP_LEN);
		info_pkg.disp_info[i].IVFreq = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_V_FREQ);
		info_pkg.disp_info[i].CapWid = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_CAP_WID);
		info_pkg.disp_info[i].CapLen = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_CAP_LEN);
		info_pkg.disp_info[i].IphActWid_Pre = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPH_ACT_WID_PRE);
		info_pkg.disp_info[i].IpvActLen_Pre = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPV_ACT_LEN_PRE);


		info_pkg.disp_info[i].IpvActSTA_H = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPH_ACT_STA);
		info_pkg.disp_info[i].IpvActSTA_V = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPV_ACT_STA);
		info_pkg.disp_info[i].IphActWid_H = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPH_ACT_WID);
		info_pkg.disp_info[i].IpvActLen_V = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPV_ACT_LEN);
		info_pkg.disp_info[i].Iph_STA_Pre = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPH_ACT_STA_PRE);
		info_pkg.disp_info[i].Ipv_STA_Pre = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)i, SLR_INPUT_IPV_ACT_STA_PRE);
		info_pkg.disp_info[i].scaler_source_type = Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)i);
		switch(Get_DisplayMode_Src(i))
		{//get adn set ui real src input
			case VSC_INPUTSRC_AVD:
				info_pkg.disp_info[i].ui_select_src = get_AVD_Input_Source();
			break;

			case VSC_INPUTSRC_ADC:
				info_pkg.disp_info[i].ui_select_src = get_ADC_Input_Source();
			break;

			case VSC_INPUTSRC_HDMI:
				info_pkg.disp_info[i].ui_select_src = _SRC_HDMI;
			break;

			case VSC_INPUTSRC_VDEC:
			case VSC_INPUTSRC_JPEG:
				info_pkg.disp_info[i].ui_select_src = _SRC_VO;
			break;

			default:
				info_pkg.disp_info[i].ui_select_src = _SRC_MAX;
			break;
		}
	}

	pulTemp = (unsigned long *)(&info_pkg);

	ulIPKGItemCount = sizeof(SCALER_DISPINFO_PKG) / sizeof(unsigned long);

	// change endian
	for (i = 0; i < ulIPKGItemCount; i++)
		pulTemp[i] = htonl(pulTemp[i]);

	//frank@0801 compare Disp_info is the same of video firmware,when the result is the same then return to speed up the code
	if (memcmp((unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_SETDISPINFO), pulTemp, sizeof(SCALER_DISPINFO_PKG)) == 0) //compare equal or not
		return;
	// copy from RPC share memory
	memcpy((unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_SETDISPINFO), pulTemp, sizeof(SCALER_DISPINFO_PKG));

	if ((ret = Scaler_SendRPC(SCALERIOC_SETDISPINFO,0,0)) < 0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "ret = %d, set disp_info to driver fail !!!\n", ret );
		return;
	}

}

extern void i2rnd_debug(void);
extern void drv_memory_display_set_input_fast(void);

unsigned char Setup_IMD(StructDisplayInfo* info)
{
#ifndef CONFIG_SDNR_CROP
	scaledown_ich1_uzd_RBUS 	ich1_uzd_Ctrl0_REG;
	ich1_uzd_Ctrl0_REG.regValue = IoReg_Read32(SCALEDOWN_ICH1_UZD_CTRL0_VADDR);
	ich1_uzd_Ctrl0_REG.cutout_en = 0;
	IoReg_Write32(SCALEDOWN_ICH1_UZD_CTRL0_VADDR, ich1_uzd_Ctrl0_REG.regValue);
#endif
	unsigned char srcType_2d;
	unsigned char phase_result = 0;
	unsigned char display;
	int count;
	mdomain_cap_cap_ddr_fifostatus_RBUS cap_ddr_fifostatus_reg;
	unsigned char game_mode_wait_frame = 0;
	unsigned int plane=0;
	VSC_INPUT_TYPE_T webos_src;
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		ROTATE_MODE_LIST rotatemode;
		if (TRUE == Get_rotate_function())
		{
			rotatemode = (ROTATE_MODE_LIST)get_rotate_mode();
			pr_emerg("rotatemode=%d\n",rotatemode);
			Scaler_HDMI_Rotate(TRUE, rotatemode, 0);
		}
#endif
	display = info->display;
	Scaler_DispSetInputInfo(SLR_INPUT_FAILURECOUNT, 0);
#if(VSC_PROFILE == 1)
	unsigned int before_time = 0;
	unsigned int after_time = 0;
	before_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
#endif
	//srcproc_pt = &src_proc[srcinput_pt->srcObj_index];
#if 0
	if (Scaler_DispGetRatioMode() == SLR_RATIO_CUSTOM)
	{
		Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC,FALSE);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[Setup_IMD][SLR_RATIO_CUSTOM]FORCE FRC\n");
	}
#endif
	set_di_wait_frame_num(0);//reset DI wait number
#ifdef ENABLE_AV1_AUTOSWITCH2SV1
		StructSourceInput *srcinput_pt = Scaler_InputSrc(Scaler_DispGetInputInfo(SLR_INPUT_INPUT_SRC));
		srcinput_pt->srcAutoSwitchAVSV_DB = 10;
#endif

		//Scaler_Set_Dynamic_Display_HV_total_Value((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));

#ifdef ENABLE_DRIVER_I3DDMA
		// [I3DDMA] VO source I3DDMA enable/disable control
		modestate_I3DDMA_update_VO_3D_enable();
		srcType_2d = modestate_I3DDMA_get_In3dMode() ? drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_SRC_TYPE):
#else
		srcType_2d = Scaler_InputSrcGetType(display);
#endif
		webos_src = Get_DisplayMode_Src(display);
		if(vsc_debug_mode)
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####func:%s start line:%d####\r\n", __FUNCTION__, __LINE__);

		if(judge_scaler_break_case(display)) {
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####channel:%d scaler need to break 1!!!####\r\n", display);
			return FALSE;
		}
		if(DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == TRUE || (Get_LivezoomOffMainForceBG() == TRUE && Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) <= 3000)) {
			/*no need run vgip to di for livezoom main*/
		} else {
			if(display == SLR_MAIN_DISPLAY)
			{
#ifdef CONFIG_HDR_SDR_SEAMLESS
				if(!DbgSclrFlgTkr.game_mode_dynamic_flag)//no game mode flow
				{
					reset_hdr_mode();//disable dolby mode
				}
#else
				reset_hdr_mode();//disable dolby mode
				#ifdef CONFIG_CUSTOMER_TV030
				//printk("yuan,checkB Scaler_color_Get_HDR_AutoRun()=%d\n",Scaler_color_Get_HDR_AutoRun());
				if(Scaler_color_Get_HDR_AutoRun())
					Scaler_color_HDRIP_AutoRun_sRGB();
				#else
				if(Scaler_color_Get_HDR_AutoRun())
					Scaler_color_HDRIP_AutoRun();
				#endif
				decide_hdr_mode();//decide which hdr mode
#endif
			}

		#ifdef ADC_UP_DOWN_CLAMP
			if(webos_src == VSC_INPUTSRC_ADC){
				SyncProc_Check_UpDn_Stable(display);
			}
		#endif

			if((webos_src == VSC_INPUTSRC_ADC) && (get_ADC_Input_Source() == _SRC_YPBPR) && (auto_phase_flow_bypass() == FALSE)){// Start YPbPr auto phase
				//rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "%s(line: %d)####display=%d(0:main, 1:sub)####\r\n", __func__, __LINE__, display);
			#if 1 //enable auto phase flow, rzhen@2016-08-15
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "start drvif_ypbpr_auto_phasedo_start\n");
				phase_result = drvif_ypbpr_auto_phasedo_start(SLR_MAIN_DISPLAY);
				//rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "drvif_ypbpr_auto_phasedo_start  result = %x\n", phase_result);
				if(phase_result != ERROR_SUCCEED){//Phase start setting fail
					rtd_printk(KERN_INFO, TAG_NAME_VSC, "###########drvif_ypbpr_auto_phasedo_start fail#############\r\n");
					return FALSE;
				}else{
					rtd_printk(KERN_INFO, TAG_NAME_VSC, "###########drvif_ypbpr_auto_phasedo_start success#############\r\n");
				}
			#else
				SyncProc_SetMinDiff(display);
			#endif
				drvif_scaler_check_vgip_data_dclk(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));
			} else {
				{
					fw_scaler_set_sample(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), _ENABLE);
					drvif_scaler_check_vgip_data_dclk(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));
				}

				if((webos_src == VSC_INPUTSRC_ADC) && (get_ADC_Input_Source() == _SRC_YPBPR))
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####YPP no need to run autophase again####\r\n");
			}

			if ( ( Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == _SRC_TV ||
			      Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == _SRC_CVBS ||
			      Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == _SRC_SV ) &&
				( Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_422) == TRUE ) )
			{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
				IoReg_Mask32(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? SUB_VGIP_VGIP_CHN2_MISC_reg : VGIP_VGIP_CHN1_MISC_reg, ~_BIT0, _BIT0);
#else
				IoReg_Mask32(/*Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)?SUB_VGIP_VGIP_CHN2_MISC_reg:*/VGIP_VGIP_CHN1_MISC_reg, ~_BIT0, _BIT0);
#endif
			}
			else
			{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
				IoReg_Mask32(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? SUB_VGIP_VGIP_CHN2_MISC_reg : VGIP_VGIP_CHN1_MISC_reg, ~_BIT0, _ZERO);
#else
				IoReg_Mask32(/*Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)?SUB_VGIP_VGIP_CHN2_MISC_reg:*/VGIP_VGIP_CHN1_MISC_reg, ~_BIT0, _ZERO);
#endif
			}

			Scaler_SetDataFormatHandler();

			// we have to remember the original iv2dvs delay and other parameters
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_DLY_PRE,Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? IoReg_ReadByte0(SUB_VGIP_VGIP_CHN2_DELAY_reg) : IoReg_ReadByte0(VGIP_VGIP_CHN1_DELAY_reg));
#else
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_DLY_PRE,/*Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? IoReg_ReadByte0(SUB_VGIP_VGIP_CHN2_DELAY_reg) : */IoReg_ReadByte0(VGIP_VGIP_CHN1_DELAY_reg));
#endif
#if(VSC_PROFILE == 1)
			after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Setup_IMD initial time=%d ms", (after_time-before_time));
			before_time = after_time;
#endif
		}
		if(!modestate_set_vgip(info)){//set VGIP fail for vo source return detect state
			//flow_message_push(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) ? _FL2FL_SUB_STATE_PERIODIC_EVENT: _FL2FL_MAIN_STATE_PERIODIC_EVENT);
			return FALSE;
		}
#if(VSC_PROFILE == 1)
		after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Setup_IMD set VGIP time=%d ms", (after_time-before_time));
		before_time = after_time;
#endif

		modestate_set_imd_domain(info);
#if(VSC_PROFILE == 1)
		after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Setup_IMD set imd time=%d ms", (after_time-before_time));
		before_time = after_time;
#endif

		//modestate_arbitration_setup();

		//printk(KERN_EMERG"Get_display_forcebg_mask(SLR_MAIN_DISPLAY,SLR_FORCE_BG_TYPE_GameMode) = %d\n", Get_display_forcebg_mask(SLR_MAIN_DISPLAY,SLR_FORCE_BG_TYPE_GameMode));


#ifdef CONFIG_WSS_ENABLE
		check_wss(_TRUE,0); // move here by linmc, need to wait wss stable
#endif
		//IoReg_SetBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? SYNCPROCESSOR_SP_MS2STUS_VADDR : */ONMS_onms1_status_reg, (_BIT14|_BIT15|_BIT8|_BIT9));//clear online ms error flag
		if(judge_scaler_break_case(display)) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d scaler need to break 2!!!####\r\n", display);
			return FALSE;
		}
		if (((display == SLR_MAIN_DISPLAY) && get_main_OutputVencMode()) || ((display == SLR_SUB_DISPLAY) && get_sub_OutputVencMode())) {
#ifdef CONFIG_I2RND_ENABLE
 			if((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){//capture progressive video data
 				printk(KERN_EMERG"[frank] apvr step3!\n");
				Scaler_i2rnd_send_apvr_info();
				mdomain_handler_i2rnd_mcap_apvr();

				vsc_i2rnd_sub_stage = I2RND_STAGE_MAIN_I2RND_DONE;
				drvif_scaler_vactive_end_irq(_ENABLE, SLR_SUB_DISPLAY);
				drvif_scaler_vactive_sta_irq(_ENABLE, SLR_SUB_DISPLAY);
				VencModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
				DbgSclrFlgTkr.OutputVencMode = FALSE;
				Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
				i2rnd_send_table_idx(I2RND_MAIN_S0_TABLE);
				printk(KERN_EMERG"[frank] apvr step4!\n");
				//go to timing frame sync mode -s- Eric@0809
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "[OUTPUT_VENC_MODE] go to data frc & timing framesync!\n");
				VSC_OUTPUT_VENC_MODE_FLAG = FALSE;
				modestate_set_fll_running_flag(_DISABLE);
				fwif_color_safe_od_enable(0);
				drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
				fwif_color_safe_od_enable(1);
				//go to timing frame sync mode -e-
				Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_ACTIVE);
				//scaler_update_struct_info(SLR_SUB_DISPLAY);
				scaler_update_struct_info(SLR_MAIN_DISPLAY);
				return TRUE;
			}else if((display == SLR_SUB_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DETECT_SOURCE)){//sub path capture
				printk(KERN_EMERG"[frank] apvr step1!\n");
				mdomain_handler_onlycap_i2run();
			}
			else
#endif
				mdomain_handler_onlycap();

#if 0
#ifdef CONFIG_I2RND_ENABLE
		}else if((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){
			mdomain_handler_i2rnd_mcap_sdisp();
			i2rnd_group3_s1_to_s0_register_sync();
			vsc_i2rnd_sub_stage = I2RND_STAGE_MAIN_I2RND_DONE;
			return TRUE;
#endif
#endif
		} else {

			if (!modestate_set_framesync(info))  // if fs fail, keep in fs state
			{
				return FALSE;
			}
		}
		//run scaler IM-domain flow to sync timing info after running smooth toggle@Crixus 20160919
		if((DbgSclrFlgTkr.game_mode_dynamic_flag == TRUE)&&(display == SLR_MAIN_DISPLAY))
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[GameMode][break for not setting d domain timing]Main re run scaler flow!!\n");
			//When enter or exit game mode, need to wait buffer write done @Crixus 20161005
			if(drv_memory_get_game_mode() == _ENABLE)
				game_mode_wait_frame = 1;//triple-buffer => single buffer, need to wait least 1 frame done.
			else
				game_mode_wait_frame = 3;//single-buffer => triple buffer, need to wait least 3 frame done.


			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC)){
				//data fsync no need to wait
			}else{
				//Update the M-domain last done @Crixus 20161013
				drv_memory_wait_cap_last_write_done(SLR_MAIN_DISPLAY, game_mode_wait_frame);
			}
			state_update_disp_info();//send scaler info to smoothtoggle ,for issue KTASKWBS-6453
			return TRUE;
		}

#ifdef CONFIG_I2RND_ENABLE
		//enable I2rnd
		if (Scaler_I2rnd_get_enable()) {
			Scaler_i2rnd_set_write_point();
			Scaler_i2rnd_buffer_copy();
			//only main scaler do i2rnd handler @Crixus 20160817
			if(display == SLR_MAIN_DISPLAY)
				Scaler_I2rnd_handler();
			scaler_save_main_info();
		}
#endif

#ifdef CONFIG_I2RND_B05_ENABLE
		//enable I2rnd_b05
         if (Scaler_I2rnd_b05_get_enable()) {
		 //	 Scaler_i2rnd_b05_buffer_copy();
             Scaler_I2rnd_b05_handler();
         }


#endif
#ifdef CONFIG_PST_ENABLE
		//enable pst
		if (Scaler_main_md_pst_get_enable()) {
			Scaler_pst_set_write_point(_MAIN_MD);
			Scaler_pst_buffer_copy(_MAIN_MD);
			drvif_scaler_pst_top_ctrl(1,_MAIN_MD);
		}
#endif
#if(VSC_PROFILE == 1)
		after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Setup_IMD set Mdomain time=%d ms",(after_time-before_time));
		before_time = after_time;
#endif

#if(VSC_PROFILE == 1)
		after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Setup_IMD online measure enable time=%d ms", (after_time-before_time));
		before_time = after_time;
#endif
		if (((display == SLR_MAIN_DISPLAY) && get_main_OutputVencMode())
			|| ((display == SLR_SUB_DISPLAY) && get_sub_OutputVencMode())
			|| (DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == TRUE)) {
			/*not open disp*/
			//in VENC mode, apvr need to enable d-domain den start irq @Crixus 20161014
			drvif_scaler_ddomain_switch_irq(_ENABLE);
			if ((display == SLR_SUB_DISPLAY) && get_sub_OutputVencMode())
				drvif_scaler_sub_mdomain_switch_irq(_ENABLE);
		} else {

			Scaler_disp_setting(display);
		}

#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
	//rtd_setbits(TVSB2_TV_SB2_DCU1_ARB_CR1_reg,_BIT2|_BIT3);
	//if(DisplayModeInputInfo.type == KADP_VSC_INPUTSRC_VDEC || VencModeInputInfo.type ==KADP_VSC_INPUTSRC_VDEC || MemoryModeInputInfo.type ==KADP_VSC_INPUTSRC_VDEC)
			//if((rotatemode == ROTATE_MODE_90) || (rotatemode == ROTATE_MODE_180) || (rotatemode == ROTATE_MODE_270))
			if (TRUE == Get_rotate_function())
				scaler_Rotate_VI_init_send_rpc();
#endif

		if(judge_scaler_break_case(display)) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d scaler need to break 3!!!####\r\n", display);
			return FALSE;
		}

#if(VSC_PROFILE == 1)
		after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Setup_IMD set display time=%d ms",(after_time-before_time));
		before_time = after_time;
#endif
	//Scaler_DispSetInputInfo(SLR_INPUT_FAILURECOUNT, 0);

#ifndef CONFIG_MEMC_BYPASS
	if((Get_MEMC_Enable_Dynamic() == 1)
		&& (DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == FALSE)
		&& (!((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY)))){
		//run MEMC setting
		Scaler_MEMC_Handler();
	}
#endif
	if(display == SLR_MAIN_DISPLAY)
	{
		check_di_buffer_mode();//Check DI buffer mode right or not. If wrong, recover it.
		/* use DI_i2r_db_reg_ctl_reg_sm_size_change_hw_detect_en_mask
		if(((IoReg_Read32(DI_IM_DI_CONTROL_reg)&DI_IM_DI_CONTROL_ip_enable_mask)!=0) && ((IoReg_Read32(DI_i2r_db_reg_ctl_reg)&DI_i2r_db_reg_ctl_reg_sm_size_change_sw_detect_en_mask)==0)){
			IoReg_SetBits(DI_i2r_db_reg_ctl_reg, DI_i2r_db_reg_ctl_reg_sm_size_change_sw_detect_en_mask);//set _BIT1
		}else{
			IoReg_ClearBits(DI_i2r_db_reg_ctl_reg, DI_i2r_db_reg_ctl_reg_sm_size_change_sw_detect_en_mask);//clear _BIT1
		}
		*/
	}
	if(Scaler_InputSrcGetType(display) == _SRC_VO)
	{
		MODE_CLEAR_ONMS_FLAG();
		if(!Get_vo_smoothtoggle_timingchange_flag(display))  //vo smooth toggle don't need onlinemeasure
		{
			if((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY)){
				/*qiangzhou added livezoom and magnifier case sub forbidden open wtd and interrupt and onlinemeasure*/
				drvif_mode_disableonlinemeasure(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
				drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), FALSE, FALSE);
			} else {
				if((webos_src == VSC_INPUTSRC_VDEC) || (webos_src == VSC_INPUTSRC_JPEG)){
					//Real Vo case
					drvif_mode_enableonlinemeasure(display);//Enable online measure
					drvif_mode_onlinemeasure_setting(display, _SRC_VO, TRUE, FALSE);
				}
			}

		}

		if (get_scaler_stop_flag(display)) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d vsc already disconnet !!!####\r\n", display);
			return FALSE;
		} else if(get_vo_change_flag(Get_DisplayMode_Port(display))){
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d vo change!!!####\r\n", display);
			return FALSE;
		}
#ifdef CONFIG_HDR_SDR_SEAMLESS
		down(&HDR_Setting_Semaphore);
		if(Scaler_color_Get_HDR_AutoRun())
			Scaler_color_HDRIP_AutoRun();
		decide_hdr_mode();//decide which hdr mode
		Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_ACTIVE);//For Video FW PQ
		up(&HDR_Setting_Semaphore);
#else
		Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_ACTIVE);//For Video FW PQ
#endif
		Scaler_Check_VIP_src_resync_flag();//fix picmode can't get hdr src info
		state_update_disp_info();//Update the active state
		if((Get_vo_smoothtoggle_timingchange_flag(display)) && (get_vo_smoothtoggle_state(display) == SLR_SMOOTH_TOGGLE_INIT) && (Scaler_DispGetInputInfo(SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
		{
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
			send_memory_mapping_for_adaptive_streaming();
#endif
			plane = get_vo_plane_flag(display);
			set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_ACTIVE, display, plane);
			smooth_toggle_state_info_rpc(display);
			if(get_zoom_vgip_adjust_enable())
			{
				stVGIP_ADJUSTMENT_INFO adjust_data=get_zoom_vgip_adjust_data(display);
				StructSrcRect disp_wid=Scaler_DispWindowGet();
				vo_zoom_go_smooth_toggle_set(_ENABLE, display);//display or channel
				zoom_smooth_toggle_state_info_rpc(display,
					adjust_data.h_start, adjust_data.v_start, adjust_data.h_width, adjust_data.v_length,
					disp_wid.srcx, disp_wid.srcy, disp_wid.src_wid, disp_wid.src_height
				);
			}
		#if 0
			if(!(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_THRIP)))
			{
				drvif_color_ma_init();
			}
		#endif
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "enter SLR_SMOOTH_TOGGLE_ACTIVE state\n");
		}
	}
	else
	{
		if(judge_scaler_break_case(display) == FALSE)
		{
			if (get_scaler_stop_flag(display)) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d vsc already disconnet !!!####\r\n", display);
				return FALSE;
			}

			if(Scaler_InputSrcGetType(display) == _SRC_TV) {
				if (display == SLR_MAIN_DISPLAY) {
					down(&SetMainOutPutRegion_Semaphore);
					if(DbgSclrFlgTkr.Main_Output_Set_flag == TRUE) {
						up(&SetMainOutPutRegion_Semaphore);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Main Output change can not active!!!####\r\n");
						return FALSE;
					}
					up(&SetMainOutPutRegion_Semaphore);
				} else {
					down(&SetSubOutPutRegion_Semaphore);
					if(DbgSclrFlgTkr.Sub_Output_Set_flag == TRUE) {
						up(&SetSubOutPutRegion_Semaphore);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Sub Output change can not active!!!####\r\n");
						return FALSE;
					}
					up(&SetSubOutPutRegion_Semaphore);
				}
			}
			Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_ACTIVE);//For Video FW PQ
			state_update_disp_info();//Update the active state
		}
		else
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "####Online measure status error!!!####\r\n");
			return FALSE;
		}
	}

	//rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "%s(line: %d)####display=%d(0:main, 1:sub)####\r\n", __func__, __LINE__, display);
	if((webos_src == VSC_INPUTSRC_ADC) && (get_ADC_Input_Source() == _SRC_YPBPR) && (auto_phase_flow_bypass() == FALSE)){

		//rtd_printk(KERN_INFO, TAG_NAME_VSC, "YPbPr auto phase---wait\n");
		drvif_ypbpr_auto_phasedo_WaitFinish(SLR_MAIN_DISPLAY);
		rtd_printk(KERN_INFO, TAG_NAME_VSC, "YPbPr auto phase---done\n");
		SyncProc_SetMinDiff(display);

		if(judge_scaler_break_case(display)) {
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "####after auto phase need to break!!!####\r\n");
			return FALSE;
		}
	}

#ifndef ADC_UP_DOWN_CLAMP
	if(webos_src == VSC_INPUTSRC_ADC)
	{
		 abl_abl_status_RBUS abl_status_reg;
		 abl_abl_mgn_b_RBUS abl_mgn_b_reg;
		 abl_abl_mgn_rg_RBUS abl_mgn_rg_reg;
		 count = 50;
		 while(count > 0)	/* wait abl status ready */
		 {
			abl_status_reg.regValue = IoReg_Read32(ABL_ABL_STATUS_reg);
			if(abl_status_reg.abl_red_equal & abl_status_reg.abl_grn_equal & abl_status_reg.abl_blu_equal)
			{
				if(judge_scaler_break_case(display))
					return FALSE;
				abl_mgn_rg_reg.regValue = IoReg_Read32(ABL_ABL_MGN_RG_reg);
				abl_mgn_rg_reg.abl_l_mgn_red = YPBPR_ABL_UV_LARGE_MARGIN;
				IoReg_Write32(ABL_ABL_MGN_RG_reg, abl_mgn_rg_reg.regValue);

				abl_mgn_b_reg.regValue = IoReg_Read32(ABL_ABL_MGN_B_reg);
				abl_mgn_b_reg.abl_l_mgn_blu = YPBPR_ABL_UV_LARGE_MARGIN;
				IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);
				break;
			}
			else
			{
				count--;
				if((count%10) == 0) {
					if(judge_scaler_break_case(display))
						return FALSE;
				}
				if(count == 0)
				{
					abl_mgn_rg_reg.regValue = IoReg_Read32(ABL_ABL_MGN_RG_reg);
					abl_mgn_rg_reg.abl_l_mgn_red = YPBPR_ABL_UV_LARGE_MARGIN;
					IoReg_Write32(ABL_ABL_MGN_RG_reg, abl_mgn_rg_reg.regValue);

					abl_mgn_b_reg.regValue = IoReg_Read32(ABL_ABL_MGN_B_reg);
					abl_mgn_b_reg.abl_l_mgn_blu = YPBPR_ABL_UV_LARGE_MARGIN;
					IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);

					rtd_printk(KERN_INFO, TAG_NAME_VSC, "ABLStatus_Reg Count Time out!\n");
				}
				msleep(5);
			}
		 }
		//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "%s(%d)-%s:  ABLStatus_Reg Count Time =%d !\n", __FILE__,__LINE__,__FUNCTION__, count);
	}
#endif

	if(webos_src == VSC_INPUTSRC_HDMI)
	{
		if(_FALSE == drvif_Hdmi_CheckStable_BeforeDisplay())
			return FALSE;
	}

	if (display == SLR_MAIN_DISPLAY){
		//add main double buffer apply @Crixus 20160126
		imd_smooth_main_double_buffer_all_apply();
		if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE){
			//Update the M-domain last done @Crixus 20161013
			if ((TRUE == Get_rotate_function()) && (get_rotate_mode()!=DIRECT_VO_FRAME_ORIENTATION_DEFAULT))
				drv_memory_wait_mdom_vi_last_write_done(SLR_MAIN_DISPLAY, 3);//triple buf for rotate
			else
				drv_memory_wait_cap_last_write_done(SLR_MAIN_DISPLAY, 1);

			//if input fast case, it need to wait capture done, then set FRC style.
			if(mdomain_input_fast_flag){
				drv_memory_display_set_input_fast();
				mdomain_input_fast_flag = 0;
			}
		}
	} else {
		//add sub double buffer apply @Crixus 20160126
		imd_smooth_sub_double_buffer_all_apply();
		if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE){
			//Update the M-domain last done @Crixus 20161013
			if (!get_sub_OutputVencMode()) {//sub m domain iterrupt open so don't need wait lastwrite @qing_liu --s4ap
				drv_memory_wait_cap_last_write_done(SLR_SUB_DISPLAY, 1);
			}
		}
	}

	if(judge_scaler_break_case(display)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d scaler need to break 4!!!####\r\n", display);
		return FALSE;
	}
	wait_DI_ready();//wait DI ready

	if(judge_scaler_break_case(display)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####channel:%d scaler need to break 5!!!####\r\n", display);
		return FALSE;
	}
	return TRUE;
}

void Scaler_SetFreeze(unsigned char channel, unsigned char mode)
{
	if (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)channel, SLR_INPUT_FRAMESYNC))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "drvif_color_di_freeze\n");
		drvif_color_di_freeze(mode);
	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "drvif_scalerdisplay_set_freeze\n");
		drvif_scalerdisplay_set_freeze(channel, mode);
	}
}

extern void magnifier_color_ultrazoom_config_scaling_up(unsigned char display);
//extern void imd_smooth_enable_sub_double_buffer(unsigned char bEnable);

unsigned char Scaler_DispWindowZoomin(SCALER_DISP_CHANNEL display, VIDEO_RECT_T inputwin, VIDEO_RECT_T outputwin, unsigned short W, unsigned short H, unsigned char changetomain)
{
	unsigned short usAfterDILen = 0;
	unsigned short usAfterDIWid = 0;
	unsigned short mDomainCapLen = 0;
	unsigned short mDomainCapWid = 0;

	mdomain_disp_ddr_mainsubctrl_RBUS mdomain_disp_ddr_mainsubctrl_Reg;
	ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_Reg;
	scaleup_dm_uzu_db_ctrl_RBUS scaleup_dm_uzu_db_ctrl_Reg;
	scaleup_ds_uzu_db_ctrl_RBUS scaleup_ds_uzu_db_ctrl_Reg;

	if (((outputwin.x + outputwin.w) > _DISP_WID) || ((outputwin.y + outputwin.h) > _DISP_LEN)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Zoom in fail, for out size out of panel range\n");
		return FALSE;
	}

	if (display == SLR_SUB_DISPLAY)
	{
		sub_dispwin.srcx = outputwin.x;
		sub_dispwin.srcy = outputwin.y;
		sub_dispwin.src_height = outputwin.h;
		sub_dispwin.src_wid = outputwin.w;
		Scaler_SubDispWindowSet(sub_dispwin);
	} else {
		main_dispwin.srcx = outputwin.x;
		main_dispwin.srcy = outputwin.y;
		main_dispwin.src_height = outputwin.h;
		main_dispwin.src_wid = outputwin.w;

		Scaler_DispWindowSet(main_dispwin);
	}

	/*livezoom & magnifier DI Len Wid is the same*/
	if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
		usAfterDILen =	(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN) << 1);
	} else {
		usAfterDILen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN);
	}
	usAfterDIWid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID);

	if ((display == SLR_SUB_DISPLAY) && (changetomain == TRUE))
	{
		mDomainCapLen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN);
		mDomainCapWid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID);
	} else {
		mDomainCapLen = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_CAP_LEN);
		mDomainCapWid = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_CAP_WID);
	}

	/*if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, mDomainCapLen * inputwin.h / usAfterDILen);
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, mDomainCapLen * (inputwin.y) / usAfterDILen);
	} else */{
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, mDomainCapLen * inputwin.h / usAfterDILen);
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, mDomainCapLen * (inputwin.y) / usAfterDILen);
	}

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, mDomainCapWid * inputwin.w / usAfterDIWid);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, mDomainCapWid * inputwin.x/ usAfterDIWid);


	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, drvif_memory_get_data_littlealign(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID), 4));
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, drvif_memory_get_data_littlealign(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA), 4));

	if ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA)  + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID)) > mDomainCapWid) {
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) - 4));
	}


	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_WID, outputwin.w);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_LEN, outputwin.h);

	if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) < Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID)){
		Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, TRUE);
	}else{
		Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, FALSE);
	}

	if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) < Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN))
		Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, TRUE);
	else
		Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, FALSE);

	if (display == SLR_SUB_DISPLAY) {
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT17);
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_enable = 1;
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_db_rd_sel = 0;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Enable dtg double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 1;
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_read_sel = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//WOSQRTK-8859:dtgm2uzu_delay set to non-zero, dbuf_vs_sel need to select the value after delay time.
		ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl_reg;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
		double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 1;
		double_buffer_ctrl_reg.uzudtg_dbuf_vsync_sel = 3;//using uzudtg vsync
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);

		//IoReg_SetBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
		scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_ds_uzu_db_ctrl_Reg.db_en = 1;
		scaleup_ds_uzu_db_ctrl_Reg.db_read_level = 1;
		IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);
	} else {
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT1);
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_enable = 1;
		mdomain_disp_ddr_mainsubctrl_Reg.disp1_db_rd_sel = 0;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT1);//Enable dtg double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_read_sel = 1;
		ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_en = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl_reg;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
		double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 1;
		double_buffer_ctrl_reg.uzudtg_dbuf_vsync_sel = 3;//using uzudtg vsync
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);

		//IoReg_SetBits(SCALEUP_DM_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
		scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg);
		scaleup_dm_uzu_db_ctrl_Reg.db_read_level = 1;
		scaleup_dm_uzu_db_ctrl_Reg.db_en = 1;
		IoReg_Write32(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);

	}
	//imd_smooth_enable_sub_double_buffer(TRUE);

	/*IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT17);//Enable double buffer register*/
	/*WaitFor_DEN_START();*/
	/*WaitFor_DEN_STOP_Done_SUB();*/
	/*sub m domain display*/
	if (display == SLR_SUB_DISPLAY) {
		memory_set_sub_displaywindow_change(changetomain);
	} else {
		memory_set_main_displaywindow_change();
	}
	/*sub uzu*/
	magnifier_color_ultrazoom_config_scaling_up(display);

	if (display == SLR_SUB_DISPLAY) {
		PipmpSetSubDisplayWindow(
			outputwin.x, outputwin.x + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID),
			outputwin.y, outputwin.y + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN),
			0);

		PipmpSetSubActiveWindow(
			0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID),
			0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN));

	} else {
		ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
		ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

		// Main Active H pos
		main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
		main_active_h_start_end_reg.mh_act_sta = outputwin.x & 0x0fff;
		main_active_h_start_end_reg.mh_act_end = (outputwin.x + outputwin.w) & 0x0fff;
		IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);

		// Main Active V pos
		main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
		main_active_v_start_end_reg.mv_act_sta = outputwin.y & 0x0fff;
		main_active_v_start_end_reg.mv_act_end = (outputwin.y + outputwin.h) & 0x0fff;
		IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);

	}

	if (display == SLR_SUB_DISPLAY)
	{
		if (subWin_LGowner)
			set_vsc_SetCircle_OutputRegion(outputwin, W, H, sub_shape_type);
		else
			set_vsc_SetCircle_OutputRegion(outputwin, W, H, sub_window_type);
	}

	if (display == SLR_SUB_DISPLAY) {

		unsigned int uzulinecntA =0;
		unsigned int uzulinecntB =0;

		unsigned int timeoutcount = 0x3ffff;
		ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
		ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_Reg;

		dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);

		do {
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntA = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntB = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			if((uzulinecntA == uzulinecntB)&&((uzulinecntA < (dv_den_start_end_reg.dv_den_end-100)) && (uzulinecntA > (dv_den_start_end_reg.dv_den_sta+100))))
			{
				ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n *****   uzulinecntA =%d, dv_den_end =%d, dsubreg_dbuf_en =%d  ", uzulinecntA, dv_den_start_end_reg.dv_den_end, ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en);

				mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
				mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_apply = 1;
				IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

				ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_set = 1;
				IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

				scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
				scaleup_ds_uzu_db_ctrl_Reg.db_apply = 1;
				IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);

				new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
				uzulinecntB = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;

				ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n *****   uzulinecntB =%d, dv_den_end =%d, dsubreg_dbuf_en =%d  ", uzulinecntA, dv_den_start_end_reg.dv_den_end, ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en);

				break;
			}
			timeoutcount--;
		} while(timeoutcount);

		if(timeoutcount == 0)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n *****   uzulinecntC =%d, dv_den_end =%d ", uzulinecntB, dv_den_start_end_reg.dv_den_end);

			mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
			mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_apply = 1;
			IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

			ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_set = 1;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

			scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
			scaleup_ds_uzu_db_ctrl_Reg.db_apply = 1;
			IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);
		}

#if 0
		tmp = 0;
		while((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT4) || (IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg)&_BIT16) || (IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg)&_BIT0)){
			msleep(1);
			if(++tmp>30)
				break;
		}

		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_enable = 0;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Disable double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_ClearBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Disable uzu double buffer register
		scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_ds_uzu_db_ctrl_Reg.db_en = 0;
		IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);
#endif
	} else {


		unsigned int uzulinecntA =0;
		unsigned int uzulinecntB =0;

		unsigned int timeoutcount = 0x3ffff;
		ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
		ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_Reg;

		dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);

		do {
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntA = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntB = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			if((uzulinecntA == uzulinecntB)&&((uzulinecntA < (dv_den_start_end_reg.dv_den_end-100)) && (uzulinecntA > (dv_den_start_end_reg.dv_den_sta+100))))
			{
				//load M domain double buffer
				mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
				mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_apply = 1;
				IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

				//load D domaindouble buffer register
				ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_set = 1;
				IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

				//load uzu double buffer
				scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg);
				scaleup_dm_uzu_db_ctrl_Reg.db_apply = 1;
				IoReg_Write32(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);
				break;
			}
			timeoutcount--;
		} while(timeoutcount);

		if(timeoutcount == 0)
		{
			//load M domain double buffer
			mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
			mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_apply = 1;
			IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

			//load D domaindouble buffer register
			ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_set = 1;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

			//load uzu double buffer
			scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg);
			scaleup_dm_uzu_db_ctrl_Reg.db_apply = 1;
			IoReg_Write32(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);
		}

#if 0
		tmp = 0;
		while((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0) || (IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg)&_BIT0) || (IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg)&_BIT0)){
			msleep(1);
			if(++tmp>30)
				break;
		}

		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_enable = 0;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);//Disable double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_ClearBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Disable uzu double buffer register
		scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg);
		scaleup_dm_uzu_db_ctrl_Reg.db_en = 0;
		IoReg_Write32(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);
#endif
	}
	return TRUE;
}

unsigned short Scaler_CalAVD27MWidth(SCALER_DISP_CHANNEL display,unsigned short a_usInput)
{
	unsigned short usRet = a_usInput;

	//printk("file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	//rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"outregion.w=%d,display=%d,  outputRegion, orginal x=%d, y=%d, w=%d, h=%d\n", outregion->w,display,Main_InputRegion_x, Main_InputRegion_y, Main_InputRegion_w, Main_InputRegion_h);

	//if (outregion->w >= AVD_DI_5A_WIDTH )
	if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(display))
	{
		if (display == SLR_MAIN_DISPLAY)
		{
			usRet = a_usInput * AVD_DI_5A_WIDTH/AVD_27M_VGIP_WIDTH * 2;
		}
#ifdef CONFIG_DUAL_CHANNEL
		else
		{

		// Sub can use DI
		//#ifdef CONFIG_I2RND_ENABLE
			//usRet = a_usInput * AVD_DI_5A_WIDTH/AVD_27M_VGIP_WIDTH * 2;
		//#else
			// By pass DI
			usRet = a_usInput * 2;
		//#endif
		}
#endif
	}
	else if(VD_27M_HSD1440_DI3A== fw_video_get_27mhz_mode(display))
	{
		usRet = a_usInput * 2;
	}

	return usRet;

}


unsigned char Scaler_CalWindowZoominForAVD(SCALER_DISP_CHANNEL display,VIDEO_RECT_T *inregion, VIDEO_RECT_T *outregion)
{
	VIDEO_RECT_T tmpinregion;

#if 1
	if (display == SLR_MAIN_DISPLAY)
	{
		tmpinregion.x = Main_InputRegion_x;
		tmpinregion.y = Main_InputRegion_y;
		tmpinregion.w = Main_InputRegion_w;
		tmpinregion.h = Main_InputRegion_h;

		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Main path inputRegion, orginal x=%d, y=%d, w=%d, h=%d\n", Main_InputRegion_x, Main_InputRegion_y, Main_InputRegion_w, Main_InputRegion_h);
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if (display == SLR_SUB_DISPLAY)
	{
		tmpinregion.x = Sub_InputRegion_x;
		tmpinregion.y = Sub_InputRegion_y / 2;  // ByPass DI
		tmpinregion.w = Sub_InputRegion_w;
		tmpinregion.h = Sub_InputRegion_h / 2;  // ByPass ID

		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Sub path inputRegion, orginal x=%d, y=%d, w=%d, h=%d\n", Main_InputRegion_x, Main_InputRegion_y, Main_InputRegion_w, Main_InputRegion_h);
	}
#endif

#endif


	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"outregion.w=%d,display=%d,  outputRegion, orginal x=%d, y=%d, w=%d, h=%d\n", outregion->w,display,Main_InputRegion_x, Main_InputRegion_y, Main_InputRegion_w, Main_InputRegion_h);

	if (outregion->w >= AVD_DI_5A_WIDTH )
	{
		if (display == SLR_MAIN_DISPLAY)
		{
			inregion->x = tmpinregion.x*2*AVD_DI_5A_WIDTH/AVD_27M_VGIP_WIDTH ;
			inregion->y = tmpinregion.y;
			inregion->w = tmpinregion.w*2*AVD_DI_5A_WIDTH/AVD_27M_VGIP_WIDTH ;
			inregion->h = tmpinregion.h;

			#ifdef CONFIG_FIXED_VD_27MHZ_960_TO_UZU
				inregion->x = 0;
				inregion->w = 960;
			#endif
		}
#ifdef CONFIG_DUAL_CHANNEL
		else
		{
			inregion->x = tmpinregion.x*2;
			inregion->y = tmpinregion.y;
			inregion->w = tmpinregion.w*2;
			inregion->h = tmpinregion.h;
		}
#endif
	}
	else
	{
		if (outregion->w > tmpinregion.w)
		{
			inregion->x = tmpinregion.x;
			inregion->y = tmpinregion.y;
			inregion->w = tmpinregion.w;
			inregion->h = tmpinregion.h;
		}
		else
		{
			inregion->x = (tmpinregion.x *2*outregion->w)/AVD_27M_VGIP_WIDTH;
			inregion->y = tmpinregion.y;
			inregion->w = (tmpinregion.w *2*outregion->w)/AVD_27M_VGIP_WIDTH;
			inregion->h = tmpinregion.h;

			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"inregion.w=%d, outregion.w=%d\n", inregion->w, outregion->w);
		}
	}

	#if 1
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_run_scaler 1 inregion x=%d, y=%d, w=%d, h=%d\n", inregion->x, inregion->y, inregion->w, inregion->h);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_run_scaler 1 outregion x=%d, y=%d, w=%d, h=%d\n", outregion->x, outregion->y, outregion->w, outregion->h);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"**** Scaler_DispWindowZoominForAVD()\n");
	#endif

	#if 0
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "display=%d\n", display);
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "rtk_run_scaler 1 inregion x=%d, y=%d, w=%d, h=%d\n", inregion->x, inregion->y, inregion->w, inregion->h);
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "rtk_run_scaler 1 outregion x=%d, y=%d, w=%d, h=%d\n", outregion->x, outregion->y, outregion->w, outregion->h);
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "**** Scaler_DispWindowZoominForAVD()\n");
	#endif

	return TRUE;
}

extern void avdmdsmooth_color_ultrazoom_config_scaling_up(unsigned char display);
unsigned char Scaler_DispWindowZoominForAVD(SCALER_DISP_CHANNEL display, VIDEO_RECT_T inputwin, VIDEO_RECT_T outputwin, unsigned char changetomain)
{
	unsigned short usAfterDILen = 0;
	unsigned short usAfterDIWid = 0;
	unsigned short mDomainCapLen = 0;
	unsigned short mDomainCapWid = 0;
	unsigned short x_offset = 0;
	unsigned short w_offset = 0;
	unsigned int ulMemActLen;
	unsigned int ulMemActSta;

	mdomain_disp_ddr_mainsubctrl_RBUS mdomain_disp_ddr_mainsubctrl_Reg;
	ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_Reg;
	scaleup_dm_uzu_db_ctrl_RBUS scaleup_dm_uzu_db_ctrl_Reg;
	scaleup_ds_uzu_db_ctrl_RBUS scaleup_ds_uzu_db_ctrl_Reg;


	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	if (((outputwin.x + outputwin.w) > _DISP_WID) || ((outputwin.y + outputwin.h) > _DISP_LEN)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Zoom in fail, for out size out of panel range\n");
		return FALSE;
	}

	if (display == SLR_SUB_DISPLAY) {
		sub_dispwin.srcx = outputwin.x;
		sub_dispwin.srcy = outputwin.y;
		sub_dispwin.src_height = outputwin.h;
		sub_dispwin.src_wid = outputwin.w;
		Scaler_SubDispWindowSet(sub_dispwin);
	} else {
		main_dispwin.srcx = outputwin.x;
		main_dispwin.srcy = outputwin.y;
		main_dispwin.src_height = outputwin.h;
		main_dispwin.src_wid = outputwin.w;

		Scaler_DispWindowSet(main_dispwin);
	}

	if (display == SLR_MAIN_DISPLAY)
	{
		/*livezoom & magnifier DI Len Wid is the same*/
		if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
			usAfterDILen =	(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN) << 1);
		} else {
			//usAfterDILen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN);
			usAfterDILen = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN);
		}

		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"main path usAfterDILen=%d\n", usAfterDILen);
	}
	else
	{
		usAfterDILen = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN);

		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"sub path usAfterDILen=%d\n", usAfterDILen);
	}

	if ((display == SLR_SUB_DISPLAY) && (changetomain == TRUE))
	{
		mDomainCapLen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN);
		mDomainCapWid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID);
	} else {
		mDomainCapLen = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_CAP_LEN);
		mDomainCapWid = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_CAP_WID);
	}

	usAfterDIWid = mDomainCapWid;

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"mDomainCapLen=%d, mDomainCapWid=%d\n", mDomainCapLen, mDomainCapWid);

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"inputwin.y=%d,  SLR_INPUT_IPV_ACT_STA=%d, SLR_INPUT_IPV_ACT_STA_PRE=%d, usAfterDILen=%d\n", inputwin.y, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA), Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA_PRE), usAfterDILen);

#if 1
		if (inputwin.w > mDomainCapWid)
		{
			if (SLR_MAIN_DISPLAY == display)
			{
				inputwin.x = inputwin.x * mDomainCapWid / AVD_DI_5A_WIDTH ;
				inputwin.w = inputwin.w * mDomainCapWid / AVD_DI_5A_WIDTH ;
			}
			else
			{
				inputwin.x = inputwin.x * mDomainCapWid / AVD_27M_VGIP_WIDTH ;;
				inputwin.w = inputwin.w * mDomainCapWid / AVD_27M_VGIP_WIDTH ;

			}

		}
		else if (mDomainCapWid > AVD_NORMAL_WIDTH && mDomainCapWid < AVD_DI_5A_WIDTH)
		{
			inputwin.x = inputwin.x * mDomainCapWid / AVD_NORMAL_WIDTH;
			inputwin.w = inputwin.w * mDomainCapWid / AVD_NORMAL_WIDTH;
		}

		/*
		if (inputwin.h >= mDomainCapLen)
		{
			inputwin.h = mDomainCapLen;
			inputwin.y = 0;
		}
		*/
#endif

	ulMemActLen =  inputwin.h * mDomainCapLen / usAfterDILen;
	ulMemActSta = inputwin.y * mDomainCapLen / usAfterDILen;

	//printk("ulMemActLen = %d\n", ulMemActLen);

	if (ulMemActLen > mDomainCapLen)
	{
		ulMemActLen = mDomainCapLen;
		ulMemActSta = 0;
	}
	//printk("2 ulMemActLen = %d\n", ulMemActLen);


	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, ulMemActLen);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, ulMemActSta);


#if 0
	if (display == SLR_MAIN_DISPLAY)
	{
		if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, mDomainCapLen * inputwin.h / usAfterDILen);
			//Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, mDomainCapLen * (inputwin.y - 2*(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA) - Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE))) / usAfterDILen);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, inputwin.y * inputwin.h / usAfterDILen);
		} else {
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, mDomainCapLen * inputwin.h / usAfterDILen);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, mDomainCapLen * (inputwin.y - (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA) - Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE))) / usAfterDILen);
		}
	}
	else
	{
#if 0
		if (inputwin.w > mDomainCapWid)
		{
			if (SLR_MAIN_DISPLAY == display)
			{
				inputwin.x = 0;
				inputwin.w = inputwin.w * mDomainCapWid / AVD_DI_5A_WIDTH ;
			}
			else
			{
				inputwin.x = 0;
				inputwin.w = inputwin.w * mDomainCapWid / AVD_27M_VGIP_WIDTH ;

			}

		}

		if (inputwin.h >= mDomainCapLen)
		{
			inputwin.h = mDomainCapLen;
			inputwin.y = 0;
		}
#endif
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, mDomainCapLen * inputwin.h / usAfterDILen);
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, inputwin.y * inputwin.h / usAfterDILen);
	}

#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"SLR_INPUT_MEM_ACT_LEN=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"SLR_INPUT_MEM_ACT_VSTA=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA));

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"mDomainCapWid = %d,inputwin.w=%d,usAfterDIWid=%d\n",mDomainCapWid,inputwin.w,usAfterDIWid);

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, mDomainCapWid * inputwin.w / usAfterDIWid);
	//Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, mDomainCapWid * (inputwin.x - (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA) - Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE))) / usAfterDIWid);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, inputwin.x);

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"SLR_INPUT_MEM_ACT_WID=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"SLR_INPUT_MEM_ACT_HSTA=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA));

	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, drvif_memory_get_data_align(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID), 2));
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, drvif_memory_get_data_align(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA), 2));

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"align 2 SLR_INPUT_MEM_ACT_WID=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"align 2 SLR_INPUT_MEM_ACT_HSTA=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA));

	if ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA)  + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID)) > mDomainCapWid) {
		Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) - 4));
	}

	DbgSclrFlgTkr.main_inputregion_x_ori_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA);
	DbgSclrFlgTkr.main_inputregion_w_ori_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID);

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"DbgSclrFlgTkr.main_inputregion_x_ori_pre=%d\n", DbgSclrFlgTkr.main_inputregion_x_ori_pre);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"DbgSclrFlgTkr.main_inputregion_w_ori_pre=%d\n", DbgSclrFlgTkr.main_inputregion_w_ori_pre);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"DbgSclrFlgTkr.main_inputregion_x_pre=%d\n", DbgSclrFlgTkr.main_inputregion_x_pre);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"DbgSclrFlgTkr.main_inputregion_w_pre=%d\n", DbgSclrFlgTkr.main_inputregion_w_pre);

	if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) < DbgSclrFlgTkr.main_inputregion_w_pre)
		w_offset = DbgSclrFlgTkr.main_inputregion_w_pre - Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID);
	else
		w_offset = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) - DbgSclrFlgTkr.main_inputregion_w_pre;

	//add AVD offset modification flow for ISF @Crixus 20151220
	if(w_offset <= 4){//in the ISF control, there is only 2 pixels shift
		if(DbgSclrFlgTkr.main_inputregion_w_pre == 0){
			DbgSclrFlgTkr.main_inputregion_x_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA);
			DbgSclrFlgTkr.main_inputregion_w_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID);
		}
		else{
			if((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA) > DbgSclrFlgTkr.main_inputregion_x_pre) && (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) < DbgSclrFlgTkr.main_inputregion_w_pre)){
				x_offset = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA) - DbgSclrFlgTkr.main_inputregion_x_pre;
				w_offset = DbgSclrFlgTkr.main_inputregion_w_pre - Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID);
				if(w_offset > x_offset){
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) + (w_offset - x_offset));
					DbgSclrFlgTkr.main_check_pre_flag = 1;
				}
				else if(w_offset < x_offset){
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) - (x_offset-w_offset));
					DbgSclrFlgTkr.main_check_pre_flag = 1;
				}
			}
			else if((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA) < DbgSclrFlgTkr.main_inputregion_x_pre) && (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) > DbgSclrFlgTkr.main_inputregion_w_pre)){
				x_offset = DbgSclrFlgTkr.main_inputregion_x_pre - Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA);
				w_offset = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) - DbgSclrFlgTkr.main_inputregion_w_pre;
				if(w_offset > x_offset){
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) - (w_offset - x_offset));
					DbgSclrFlgTkr.main_check_pre_flag = 1;
				}
				else if(w_offset < x_offset){
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) + (x_offset-w_offset));
					DbgSclrFlgTkr.main_check_pre_flag = 1;
				}

			}
			else{
				if((DbgSclrFlgTkr.main_check_pre_flag == 1) && (DbgSclrFlgTkr.main_inputregion_x_ori_pre == Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA)) && (DbgSclrFlgTkr.main_inputregion_w_ori_pre == Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID))){
					//Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, DbgSclrFlgTkr.main_inputregion_x_pre);
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, DbgSclrFlgTkr.main_inputregion_w_pre);
					DbgSclrFlgTkr.main_check_pre_flag = 0;
				}
			}
				DbgSclrFlgTkr.main_inputregion_x_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA);
				DbgSclrFlgTkr.main_inputregion_w_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID);
		}
	}
	else{
		DbgSclrFlgTkr.main_check_pre_flag = 0;
		DbgSclrFlgTkr.main_inputregion_x_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA);
		DbgSclrFlgTkr.main_inputregion_w_pre = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"final SLR_INPUT_MEM_ACT_WID=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"final SLR_INPUT_MEM_ACT_HSTA=%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA));


	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_WID, outputwin.w);
	Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_LEN, outputwin.h);

	if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) < Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID)){
		Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, TRUE);
	}else{
		Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, FALSE);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"SLR_SCALE_H_UP=%d\n", Scaler_DispGetScaleStatus(display, SLR_SCALE_H_UP));


	if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) < Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN))
		Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, TRUE);
	else
		Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, FALSE);

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"SLR_SCALE_V_UP=%d\n", Scaler_DispGetScaleStatus(display, SLR_SCALE_V_UP));

	if (display == SLR_SUB_DISPLAY) {
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT17);
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_enable = 1;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Enable dtg double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_SetBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
		scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_ds_uzu_db_ctrl_Reg.db_en = 1;
		IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);
	} else {
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT1);
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_enable = 1;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT1);//Enable dtg double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_en = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_SetBits(SCALEUP_DM_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
		scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg);
		scaleup_dm_uzu_db_ctrl_Reg.db_en = 1;
		IoReg_Write32(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);

	}
	//imd_smooth_enable_sub_double_buffer(TRUE);

	/*IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT17);//Enable double buffer register*/
	/*WaitFor_DEN_START();*/
	/*WaitFor_DEN_STOP_Done_SUB();*/
	/*sub m domain display*/
	if (display == SLR_SUB_DISPLAY) {
		memory_set_sub_displaywindow_change(changetomain);
	} else {
		memory_set_main_displaywindow_change();
	}
	/*sub uzu*/
	avdmdsmooth_color_ultrazoom_config_scaling_up(display);

	if (display == SLR_SUB_DISPLAY) {
		PipmpSetSubDisplayWindow(
			outputwin.x, outputwin.x + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID) - 1,
			outputwin.y, outputwin.y + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN) - 1,
			0);

		PipmpSetSubActiveWindow(
			0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID)  - 1,
			0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN) - 1);

	} else {
		ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
		ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

		// Main Active H pos
		main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
		main_active_h_start_end_reg.mh_act_sta = outputwin.x & 0x0fff;
		main_active_h_start_end_reg.mh_act_end = (outputwin.x + outputwin.w) & 0x0fff;
		IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);

		// Main Active V pos
		main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
		main_active_v_start_end_reg.mv_act_sta = outputwin.y & 0x0fff;
		main_active_v_start_end_reg.mv_act_end = (outputwin.y + outputwin.h) & 0x0fff;
		IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);

	}

	if (display == SLR_SUB_DISPLAY) {
		unsigned int uzulinecntA =0;
		unsigned int uzulinecntB =0;

		unsigned int timeoutcount = 0x3ffff;
		ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
		ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_Reg;
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);//load M domain double buffer
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_apply = 1;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);
#if 0
		IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT4);//load D domaindouble buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_set = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);
#endif
		//IoReg_SetBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT0);//load uzu double buffer
		scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_ds_uzu_db_ctrl_Reg.db_apply = 1;
		IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);

		dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);

		do {
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntA = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntB = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			if((uzulinecntA == uzulinecntB)&&((uzulinecntA < (dv_den_start_end_reg.dv_den_sta)) || (uzulinecntA > (dv_den_start_end_reg.dv_den_end)))) {
				//IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Disable double buffer register
				ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 0;
				IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);
				break;
			}
			timeoutcount--;
		} while(timeoutcount);

		if(timeoutcount == 0){
			//IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Disable double buffer register
			ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 0;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[SUB DEN]timeout error!!!\n");
		}
#if 0
		tmp = 0;
		while((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT4) || (IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg)&_BIT16) || (IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg)&_BIT0)){
			msleep(1);
			if(++tmp>30)
				break;
		}

		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_enable = 0;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Disable double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_ClearBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Disable uzu double buffer register
		scaleup_ds_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_ds_uzu_db_ctrl_Reg.db_en = 0;
		IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);
#endif
	} else {
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);//load M domain double buffer
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_apply = 1;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT4);//load D domaindouble buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_set = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_SetBits(SCALEUP_DM_UZU_DB_CTRL_reg, _BIT0);//load uzu double buffer
		scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg);
		scaleup_dm_uzu_db_ctrl_Reg.db_apply = 1;
		IoReg_Write32(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);
#if 0
		tmp = 0;
		while((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0) || (IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg)&_BIT0) || (IoReg_Read32(SCALEUP_DM_UZU_DB_CTRL_reg)&_BIT0)){
			msleep(1);
			if(++tmp>30)
				break;
		}

		mdomain_disp_ddr_mainsubctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp1_double_enable = 0;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);//Disable double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_ClearBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Disable uzu double buffer register
		scaleup_dm_uzu_db_ctrl_Reg.regValue = IoReg_Read32(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_dm_uzu_db_ctrl_Reg.db_en = 0;
		IoReg_Write32(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_Reg.regValue);
#endif
	}

	return TRUE;
}


void Scaler_SetDisplaySingleBufferMode(SCALER_DISP_CHANNEL channel, unsigned char mode)
{
	if (channel == SLR_MAIN_DISPLAY) {
		mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
		if (mode) {
			ddr_mainctrl_reg.main_v_flip_3buf_en = 0;
			ddr_mainctrl_reg.main_double_en = 0;
			ddr_mainctrl_reg.main_single_buffer_select = 2;
		} else {
			ddr_mainctrl_reg.main_v_flip_3buf_en = 1;
			ddr_mainctrl_reg.main_double_en = 1;
		}
		IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);
	} else if (channel == SLR_SUB_DISPLAY) {
		mdomain_disp_ddr_subctrl_RBUS ddr_subctrl_reg;
		ddr_subctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_SubCtrl_reg);
		if (mode) {
			ddr_subctrl_reg.sub_v_flip_3buf_en = 0;
			ddr_subctrl_reg.sub_double_en = 0;
			ddr_subctrl_reg.sub_single_buffer_select = 2;
		} else {
			ddr_subctrl_reg.sub_v_flip_3buf_en = 1;
			ddr_subctrl_reg.sub_double_en = 1;
		}
		IoReg_Write32(MDOMAIN_DISP_DDR_SubCtrl_reg, ddr_subctrl_reg.regValue);
	}
	drvif_memory_set_dbuffer_write();
}

static unsigned char Hdmi_GameMode = FALSE;

unsigned char Get_HDMI_SingleBuffer_GameMode(void)
{
	//only support 50hz/60hz hdmi timing go data frc
	//if(((Scaler_InputSrcGetMainChType() == _SRC_HDMI) || (Scaler_InputSrcGetMainChType() == _SRC_DVI)) && (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE))
	if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE)
	{
		/*magellan and sirius ic m cap and m disp not the same, but merlin the same*/
		if(((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 490) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 510)) || ((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 590) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 610)))
		{
			return Hdmi_GameMode;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

extern unsigned int Get_fine_tune_dclk_forGameMode(void);
#define IV2DVLINE_GAPSPACE 2
void FineTune_iv2dvline_GameMode(void)
{

	unsigned int htotal = Get_DISP_HORIZONTAL_TOTAL();
	unsigned int vtotal = Get_DISP_VERTICAL_TOTAL();
	unsigned int Dclock = Get_fine_tune_dclk_forGameMode();
	unsigned int dispDFRate =  (10*Dclock/(htotal*vtotal));
	unsigned int iputFRate = Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ);

	unsigned int dispLen = Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);
	unsigned int inputSta = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);
	unsigned int inputLen = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);

	mdomain_disp_ddr_mainprevstart_RBUS ddr_mainprevstart_Reg;
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;
	unsigned int preread = 0;
	unsigned int dv_sta = 0;
	unsigned int mv_sta = 0;
	int iv2dvlinesta = 0;
	unsigned int iv2dvlinefreq = 0;

	if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
		inputLen = inputLen*2;

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[Game_mode]input frame rate = %d;output frame rate = %d\n",(unsigned int)iputFRate, (unsigned int)dispDFRate);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[Game_mode]inputSta = %d;inputLen = %d;dispLen = %d\n",(unsigned int)inputSta, (unsigned int)inputLen, (unsigned int)dispLen);


	ddr_mainprevstart_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainPreVStart_reg);
	preread = ddr_mainprevstart_Reg.main_pre_rd_v_start;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[Game_mode]preread = %d\n",preread);


	dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
	dv_sta = dv_den_start_end_reg.dv_den_sta;


	main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
	mv_sta = main_active_v_start_end_reg.mv_act_sta;

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[Game_mode]dv_sta = %d;mv_sta = %d\n",dv_sta,mv_sta);

	iv2dvlinesta = (inputSta*(dispLen*dispDFRate)/(inputLen*iputFRate)) + IV2DVLINE_GAPSPACE + preread - (dv_sta+mv_sta);

	if(iv2dvlinesta < 0)
		iv2dvlinesta = 0;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[Game_mode]iv2dvline for reason sta diff = %d\n", iv2dvlinesta);

	if(iputFRate<dispDFRate)
		iv2dvlinefreq = (inputLen - inputLen*iputFRate/dispDFRate);

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[Game_mode]iv2dvline for reason freq diff = %d\n", iv2dvlinefreq);
	drvif_set_frc_ivs2dvsdelay_line((iv2dvlinesta+iv2dvlinefreq),(iv2dvlinesta+iv2dvlinefreq), 0);
}


static unsigned char vscFilmMode = FALSE;

unsigned char Get_vscFilmMode(void)
{
	return vscFilmMode;
}

void filmmode_videofw_config(unsigned int filmmode, unsigned int buf4addr)//filmmode:0 disable filmmode;filmmode:0 enable filmmode
{
	FILM_MODE_IOCTL_PARAM param = {filmmode, buf4addr};
	unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	int ret;

	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VIDEO_FILMMODE_ENABLE);
	ulCount = sizeof(FILM_MODE_IOCTL_PARAM) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulTemp, &param, sizeof(FILM_MODE_IOCTL_PARAM));

	for (i = 0; i < ulCount; i++)
		pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_VIDEO_FILMMODE_ENABLE, 0, 0)))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"ret=%d, Deinit SCALERIOC_VIDEO_FILMMODE_ENABLE fail !!!\n", ret);
	}
}

extern unsigned int FilmModeCachaddr;
extern unsigned int FilmModePhyadddr;

unsigned char rtk_vsc_setFilmMode(bool value)
{
//remove by ben, due to mag2 remove fs_5_4 hw
#ifdef CONFIG_5_4_FS
#if 0
	vscFilmMode = value;
	if(value == TRUE)
	{
		HAL_VBE_DISP_SetFrameRate(TRUE,48);
	}
	else
	{
		HAL_VBE_DISP_SetFrameRate(FALSE,60);
		dvr_free((void *)FilmModeCachaddr);
		FilmModeCachaddr = NULL;
		FilmModePhyadddr = NULL;
		filmmode_videofw_config(FALSE,NULL);
	}
//#else
	if(value==TRUE)
	{
		ppoverlay_dh_total_last_line_length_RBUS ppoverlay_dh_total_last_line_length_Reg;
		ppoverlay_dh_total_last_line_length_Reg.regValue=IoReg_Read32(PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_VADDR);

		ppoverlay_dv_total_RBUS ppoverlay_dv_total_Reg;
		ppoverlay_dv_total_Reg.regValue = IoReg_Read32(PPOVERLAY_DV_TOTAL_VADDR);

		ppoverlay_fs54_dh_RBUS ppoverlay_fs54_dh_Reg;
		ppoverlay_fs54_dh_Reg.fs54_dh_total = ppoverlay_dh_total_last_line_length_Reg.dh_total;
		ppoverlay_fs54_dh_Reg.fs54_dh_last_line = ppoverlay_dh_total_last_line_length_Reg.dh_total_last_line;
		IoReg_Write32(PPOVERLAY_FS54_DH_VADDR, ppoverlay_fs54_dh_Reg.regValue);

		ppoverlay_fs54_dv_RBUS ppoverlay_fs54_dv_Reg;
		ppoverlay_fs54_dv_Reg.fs54_dv_total = ppoverlay_dv_total_Reg.dv_total*5/4;
		IoReg_Write32(PPOVERLAY_FS54_DV_VADDR,ppoverlay_fs54_dv_Reg.regValue);

		fs54_ctrl_RBUS ppoverlay_fs54_ctrl_Reg;
		ppoverlay_fs54_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_FS54_CTRL_VADDR);
		ppoverlay_fs54_ctrl_Reg.fs54_dclk_en = 0;
		ppoverlay_fs54_ctrl_Reg.fs54_dclk_slow_modify_en = 0;
		ppoverlay_fs54_ctrl_Reg.fs54_pseudo_fsync_en = 0;
		ppoverlay_fs54_ctrl_Reg.fs54_timing_en = 1;
		ppoverlay_fs54_ctrl_Reg.fs54_vs_align = 3;
		ppoverlay_fs54_ctrl_Reg.fs54_force = 1;
		ppoverlay_fs54_ctrl_Reg.fs54_main_sub_sel = 0;
		ppoverlay_fs54_ctrl_Reg.fs54_frc_fastslow = 1;
		ppoverlay_fs54_ctrl_Reg.fs54_db_load = 1;
		ppoverlay_fs54_ctrl_Reg.fs54_en = 1;
		if((IoReg_Read32(PPOVERLAY_DOUBLE_BUFFER_CTRL_VADDR)&_BIT2)>>2)
		{
			IoReg_ClearBits(PPOVERLAY_DOUBLE_BUFFER_CTRL_VADDR, _BIT2);
			IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR,ppoverlay_fs54_ctrl_Reg.regValue);
			IoReg_SetBits(PPOVERLAY_DOUBLE_BUFFER_CTRL_VADDR, _BIT2);
		}
		else
		{
			IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR,ppoverlay_fs54_ctrl_Reg.regValue);
		}
	}
	else
	{
		fs54_ctrl_RBUS ppoverlay_fs54_ctrl_Reg;
		ppoverlay_fs54_ctrl_Reg.regValue = 0;
		IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR,ppoverlay_fs54_ctrl_Reg.regValue);
	}
#else
	if(value == TRUE)
		drvif_framesync_5_4();
	else
		drvif_framesync_5_4_release();
#endif
#endif
	return TRUE;

}

static unsigned char VscInitdone_Flag = FALSE;
static unsigned char VscOpendone_Flag = FALSE;
#ifdef CONFIG_DUAL_CHANNEL
static unsigned char Sub_VscOpendone_Flag = FALSE;
#endif

unsigned char rtk_hal_vsc_initialize(void)
{
	static unsigned char init_done = FALSE; //for paramter initital
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	if(!init_done)
	{
		Scaler_StructInit(PcbSource_GetTable(), PcbSource_GetTableSize(), PcbSource_GetTableSize()-3 /*OSD*/, 4 /*ypp*/);
#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
		Scaler_Orbit_Timer_Init();
#endif
		init_done = TRUE;
	}
	if(VscInitdone_Flag == FALSE)
 	{
		VscInitdone_Flag = TRUE;
		return TRUE;
	}
	else
	{
		  rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC init have done, not need init again\n");
		  return TRUE;
	}
}

unsigned char rtk_hal_vsc_uninitialize(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
#ifdef CONFIG_DUAL_CHANNEL
	if ((VscOpendone_Flag == TRUE) || (Sub_VscOpendone_Flag == TRUE)) {
#else
	if (VscOpendone_Flag == TRUE) {
#endif
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC main and sub not all closed,so can not uninitialize!\n");
		return TRUE;
	} else {
		if (VscInitdone_Flag == TRUE) {
#if 0//no need to do anything
			Scaler_StructUninit();
#endif
			VscInitdone_Flag = FALSE;
			return TRUE;
		} else {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC not init\n");
			return TRUE;
		}
	}
}

unsigned char rtk_hal_vsc_open(VIDEO_WID_T wid)
{
#ifdef CONFIG_DUAL_CHANNEL
	if ((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not right\n");
		return FALSE;
	}
#else
	if (wid !=VIDEO_WID_0) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not right\n");
		return FALSE;
	}
#endif

	if (VscInitdone_Flag == FALSE) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC is not init, can not be opened\n");
		return TRUE;
	} else {
		if (wid ==VIDEO_WID_0) {
			if(VscOpendone_Flag == FALSE)	{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
				VscOpendone_Flag = TRUE;
				return TRUE;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Main vsc open have done, not need open again\n");
				return TRUE;
			}
		}
#ifdef CONFIG_DUAL_CHANNEL
		if (wid ==VIDEO_WID_1) {
			if(Sub_VscOpendone_Flag == FALSE)	{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
				Sub_VscOpendone_Flag = TRUE;
				return TRUE;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Sub vsc open have done,not need open again\n");
				return TRUE;
			}
		}
#endif
	}
	return TRUE;
}

unsigned char rtk_hal_vsc_close(VIDEO_WID_T wid)
{
#ifdef CONFIG_DUAL_CHANNEL
	if ((wid < VIDEO_WID_MIN) || (wid > VIDEO_WID_MAX)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if (wid != VIDEO_WID_0) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	if (wid ==VIDEO_WID_0) {
		if (DbgSclrFlgTkr.OuputDisplayMode || DbgSclrFlgTkr.OutputVencMode || DbgSclrFlgTkr.OutputMemoryMode ||
		    DbgSclrFlgTkr.OutputAveMode) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Main vsc have source not disconnect, so can not close!\n");
			return TRUE;
		} else {
			if(VscOpendone_Flag == TRUE) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
				//drvif_mode_resetmode(SLR_MAIN_DISPLAY);
				down(&Main_ResetMode_Semaphore);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s request reset mode####\r\n", __FUNCTION__);
				DbgSclrFlgTkr.Main_Reset_Mode_flag = TRUE;
				up(&Main_ResetMode_Semaphore);
				VscOpendone_Flag = FALSE;
				return TRUE;
		 	} else {
		 		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Main vsc not opened\n");
				return TRUE;
			}
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	if (wid ==VIDEO_WID_1) {
		if (DbgSclrFlgTkr.Sub_OuputDisplayMode || DbgSclrFlgTkr.Sub_OutputVencMode || DbgSclrFlgTkr.Sub_OutputMemoryMode ||
		    DbgSclrFlgTkr.Sub_OutputAveMode) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Sub vsc have source not disconnect, so can not close!\n");
			return TRUE;
		} else {
			if(Sub_VscOpendone_Flag == TRUE) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
				//drvif_mode_resetmode(SLR_SUB_DISPLAY);
				down(&Sub_ResetMode_Semaphore);
				DbgSclrFlgTkr.Sub_Reset_Mode_flag = TRUE;
				up(&Sub_ResetMode_Semaphore);
				Sub_VscOpendone_Flag = FALSE;
				return TRUE;
		 	} else {
		 		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Sub vsc not opened\n");
				return TRUE;
			}
		}
	}
#endif
	return TRUE;
}

long Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_TYPE_T type, unsigned char wid_port)
{
	long ret = 0;
#ifdef CONFIG_RTK_KDRV_RPC
	unsigned char type_local;
	unsigned char port_local;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[]###############%s\n", __FUNCTION__);

	if (type == VO_VSC_SRC_VDEC) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
		type_local = 0;
	} else if(type == VO_VSC_SRC_JPEG){
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
		type_local = 1;
	} else {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
		type_local = 2;
	}
	if (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC &&
		Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_VDEC &&
		Get_DisplayMode_Port(SLR_MAIN_DISPLAY) != Get_DisplayMode_Port(SLR_SUB_DISPLAY)) {
		type_local = 0x10 | type_local;
	}

	port_local = wid_port;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n\n[pool test][sendVo]wid:%d,port:%d,plane:%d\n",(wid_port&0xf0)>>4,wid_port&0xf,get_vo_plane_flag((wid_port&0xf0)>>4));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo]%s type %d, port %d, m[%d/%d] s[%d/%d]\n", __FUNCTION__, type_local, port_local, Get_DisplayMode_Src(SLR_MAIN_DISPLAY), Get_DisplayMode_Port(SLR_MAIN_DISPLAY), Get_DisplayMode_Src(SLR_SUB_DISPLAY), Get_DisplayMode_Port(SLR_SUB_DISPLAY));

	//set_vo_nosignal_flag((port_local & 0xf), 1);

	if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_VSCDISCONNECT_TO_VODMA, type_local, port_local, &ret))
		rtd_printk(KERN_ERR, TAG_NAME_VSC, "RPC fail!!\n");
#endif

	return ret;
}

long Scaler_Send_VoType_VOMDA(VO_VSC_SRC_TYPE_T type, unsigned char wid_port)
{
	long ret = 0;
#ifdef CONFIG_RTK_KDRV_RPC
	unsigned char type_local;
	unsigned char port_local;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[]###############%s\n", __FUNCTION__);

	if (type == VO_VSC_SRC_VDEC) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
		type_local = 0;
	} else if(type == VO_VSC_SRC_JPEG){
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
		type_local = 1;
	} else {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
		type_local = 2;
	}
	if (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC &&
		Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_VDEC &&
		Get_DisplayMode_Port(SLR_MAIN_DISPLAY) != Get_DisplayMode_Port(SLR_SUB_DISPLAY)) {
		type_local = 0x10 | type_local;
	}

	port_local = wid_port;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n\n[pool test][sendVo]wid:%d,port:%d,plane:%d\n",(wid_port&0xf0)>>4,wid_port&0xf,get_vo_plane_flag((wid_port&0xf0)>>4));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[vo]%s type %d, port %d, m[%d/%d] s[%d/%d]\n", __FUNCTION__, type_local, port_local, Get_DisplayMode_Src(SLR_MAIN_DISPLAY), Get_DisplayMode_Port(SLR_MAIN_DISPLAY), Get_DisplayMode_Src(SLR_SUB_DISPLAY), Get_DisplayMode_Port(SLR_SUB_DISPLAY));

	set_vo_nosignal_flag((port_local & 0xf), 1);

	if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_VSCINPUTTYPE_TO_VODMA, type_local, port_local, &ret))
		rtd_printk(KERN_ERR, TAG_NAME_VSC, "RPC fail!!\n");
#endif

	return ret;
}

unsigned char vsc_force_disconnect(VIDEO_WID_T wid, VSC_INPUT_SRC_INFO_T inputSrcInfo, VSC_OUTPUT_MODE_T outputMode)
{//This API is patch for CI test not work. force disconnect current outputMode.
	unsigned int *p_sourceID = NULL;
	StructSrcRect SrcRect = {0, 0, 0, 0};
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	} else if (wid == VIDEO_WID_0) {
		p_sourceID = &DbgSclrFlgTkr.main_opensourceID;
	} else {
		p_sourceID = &DbgSclrFlgTkr.sub_opensourceID;
	}
#else
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	} else {
		p_sourceID = &DbgSclrFlgTkr.main_opensourceID;
	}
#endif


	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, KERN_WARNING "\r\n####function:%s wid:%d outputMode:%d####\r\n", __FUNCTION__, wid, outputMode);
	unsigned char plane=0;
	if (wid == VIDEO_WID_0) {
		set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
		switch(outputMode)
		{
			case VSC_OUTPUT_DISPLAY_MODE:
			{
				set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, TRUE);//Enable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
				if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){//AP not mute on yet
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
					up(get_forcebg_semaphore());
				}
				down(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_Scaler_Stop_flag = TRUE;
				DbgSclrFlgTkr.Main_force_frc_flag = FALSE;
				DbgSclrFlgTkr.Main_force_frc_fs_flag = FALSE;
				DbgSclrFlgTkr.smoothtoggle_start_flag = FALSE;
				//frank@0204 K-task6477 reset below flag to avoid smooth toggle RPC --
				DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag = FALSE;
				DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off = FALSE;
				DbgSclrFlgTkr.Main_smooth_toggle_set_flag = FALSE;
				DbgSclrFlgTkr.rotate_run_scaler_flag = FALSE;
				DbgSclrFlgTkr.rotate_muteoff_request_flag = FALSE;
				is_DTV_flag_set(_DISABLE);
				zoom_clear_input_output_region_record(wid);
				Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);
				up(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.RGB444Mode_change = 0;
				DbgSclrFlgTkr.RGB444Mode = 0;
				DbgSclrFlgTkr.main_winfreeze=0;
				drvif_mode_disableonlinemeasure(_CHANNEL1);//Diable online measure
				drvif_mode_onlinemeasure_setting(_CHANNEL1, Scaler_InputSrcGetType(SLR_MAIN_DISPLAY), FALSE, FALSE);
				DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset DbgSclrFlgTkr.Main_during_scalerflow_flag.
				drivf_scaler_reset_freerun();
				//set detect timng flag true:
				if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
				{
					/*//no need because AVD don't stop detect task
					down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
					up(get_vdc_detectsemaphore());
					*/
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
				{
					down(get_hdmi_detectsemaphore());
					if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
					up(get_hdmi_detectsemaphore());
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
				{
					down(get_adc_detectsemaphore());
					fw_scaler_adc_nolock_wdg_ctrl(SLR_MAIN_DISPLAY, FALSE);// Disable adc_nolock_wdg
					if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
						YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
						ADC_set_detect_flag(TRUE);
					}
					up(get_adc_detectsemaphore());
					set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
				} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
					down(get_vo_infosemaphore());
					DbgSclrFlgTkr.OuputDisplayMode = FALSE; // Preset for vo
					plane=get_vo_plane_flag(SLR_MAIN_DISPLAY);
					DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};// Preset for vo
					set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
					set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
					set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
					up(get_vo_infosemaphore());
				//	vo_overscan_disable(inputSrcInfo.type);
					reset_adaptive_streaming_info(SLR_MAIN_DISPLAY);//reset adaptive stream info
					if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
						Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
					else
						Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
				}
				smooth_toggle_disconnect(SLR_MAIN_DISPLAY,plane);
				Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();

				DbgSclrFlgTkr.OuputDisplayMode = FALSE;
				DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
				*p_sourceID = _UNKNOWN_INPUT;
				//close display panel

				DbgSclrFlgTkr.Main_AutoRunScaler = FALSE;
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_pre);
				reset_any_srcrect(&main_dispwin_for_only_xy);
				up(&SetMainOutPutRegion_Semaphore);
				if (Get_LivezoomOffMainForceBG() == TRUE) {
					Set_LivezoomOffMainForceBG(FALSE);
				}
				DbgSclrFlgTkr.DataFramesynclivezoom = FALSE;
				break;
			}
			case VSC_OUTPUT_VENC_MODE:
			{
				drvif_mode_disableonlinemeasure(_CHANNEL1);//Diable online measure
				drvif_mode_onlinemeasure_setting(_CHANNEL1, Scaler_InputSrcGetType(SLR_MAIN_DISPLAY), FALSE, FALSE);
				//set detect timng flag true:
				if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
				{
					/*//no need because AVD don't stop detect task
					down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
					up(get_vdc_detectsemaphore());
					*/
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
				{
					down(get_hdmi_detectsemaphore());
					if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
					up(get_hdmi_detectsemaphore());
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
				{
					down(get_adc_detectsemaphore());
					fw_scaler_adc_nolock_wdg_ctrl(SLR_MAIN_DISPLAY, FALSE);// Disable adc_nolock_wdg
					if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
						YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
						ADC_set_detect_flag(TRUE);
					}
					up(get_adc_detectsemaphore());
					set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
					plane=get_vo_plane_flag(SLR_MAIN_DISPLAY);
				}
				smooth_toggle_disconnect(SLR_MAIN_DISPLAY,plane);
				Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();

				DbgSclrFlgTkr.OutputVencMode = FALSE;
				VencModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
				*p_sourceID = _UNKNOWN_INPUT;

				break;
			}
			case VSC_OUTPUT_MEMORY_MODE://Current same with VSC_OUTPUT_DISPLAY_MODE
			{
				set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, TRUE);//Enable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
				if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){//AP not mute on yet
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
					up(get_forcebg_semaphore());
				}
				down(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_Scaler_Stop_flag = TRUE;
				DbgSclrFlgTkr.Main_force_frc_flag = FALSE;
				DbgSclrFlgTkr.Main_force_frc_fs_flag = FALSE;
				DbgSclrFlgTkr.smoothtoggle_start_flag = FALSE;
				//frank@0204 K-task6477 reset below flag to avoid smooth toggle RPC --
				DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag = FALSE;
				DbgSclrFlgTkr.Main_smooth_toggle_set_flag = FALSE;
				DbgSclrFlgTkr.rotate_run_scaler_flag = FALSE;
				DbgSclrFlgTkr.rotate_muteoff_request_flag = FALSE;
				is_DTV_flag_set(_DISABLE);
				zoom_clear_input_output_region_record(wid);
				Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);
				up(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.RGB444Mode_change = 0;
				DbgSclrFlgTkr.RGB444Mode = 0;
				DbgSclrFlgTkr.main_winfreeze=0;
				drvif_mode_disableonlinemeasure(_CHANNEL1);//Diable online measure
				drvif_mode_onlinemeasure_setting(_CHANNEL1, Scaler_InputSrcGetType(SLR_MAIN_DISPLAY), FALSE, FALSE);
				DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset DbgSclrFlgTkr.Main_during_scalerflow_flag.
				//set detect timng flag true:
				if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
				{
					/*//no need because AVD don't stop detect task
					down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
					up(get_vdc_detectsemaphore());
					*/
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
				{
					down(get_hdmi_detectsemaphore());
					if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
					up(get_hdmi_detectsemaphore());
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
				{
					down(get_adc_detectsemaphore());
					fw_scaler_adc_nolock_wdg_ctrl(SLR_MAIN_DISPLAY, FALSE);// Disable adc_nolock_wdg
					if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
						YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
						ADC_set_detect_flag(TRUE);
					}
					up(get_adc_detectsemaphore());
					set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
				} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
					down(get_vo_infosemaphore());
					DbgSclrFlgTkr.OutputMemoryMode = FALSE;
					plane=get_vo_plane_flag(SLR_MAIN_DISPLAY);
					MemoryModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
					set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
					set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
					set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
					up(get_vo_infosemaphore());
				//	vo_overscan_disable(inputSrcInfo.type);
					reset_adaptive_streaming_info(SLR_MAIN_DISPLAY);//reset adaptive stream info
					if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
						Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
					else
						Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
				}
				smooth_toggle_disconnect(SLR_MAIN_DISPLAY,plane);
				Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();

				DbgSclrFlgTkr.OutputMemoryMode = FALSE;
				MemoryModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
				*p_sourceID = _UNKNOWN_INPUT;

				DbgSclrFlgTkr.Main_AutoRunScaler = FALSE;
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_pre);
				reset_any_srcrect(&main_dispwin_for_only_xy);
				up(&SetMainOutPutRegion_Semaphore);
				if (Get_LivezoomOffMainForceBG() == TRUE) {
					Set_LivezoomOffMainForceBG(FALSE);
				}
				DbgSclrFlgTkr.DataFramesynclivezoom = FALSE;
				break;
			}
			case VSC_OUTPUT_AVE_MODE:
			{
				HAL_VBE_AVE_Disconnect();
				DbgSclrFlgTkr.OutputAveMode = FALSE;
				AveModeInputInfo =  (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
				break;
			}
			default:
				break;
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	if (wid == VIDEO_WID_1) {
		set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
		switch(outputMode)
		{
			case VSC_OUTPUT_DISPLAY_MODE:
			{
				set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, TRUE);//Enable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
				down(get_forcebg_semaphore());
				scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);//Auto mue before disconnect
				drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
				up(get_forcebg_semaphore());
				down(&SetSubOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Sub_Scaler_Stop_flag = TRUE;
				zoom_clear_input_output_region_record(wid);
				Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);
				up(&SetSubOutPutRegion_Semaphore);
				if (((inputSrcInfo.type == VSC_INPUTSRC_AVD) ||(inputSrcInfo.type == VSC_INPUTSRC_HDMI) ||(inputSrcInfo.type == VSC_INPUTSRC_VDEC)) && (Get_Live_zoom_mode() == LIVE_ZOOM_SUB )) {
					Set_Live_zoom_mode(LIVE_ZOOM_OFF);
					//DataFramesynclivezoom = FALSE;
					DbgSclrFlgTkr.LivezoomMainRerunFlag = FALSE;
					DbgSclrFlgTkr.LivezoomSubRerunFlag = FALSE;
					DbgSclrFlgTkr.LivezoomvoinfocheckFlag = FALSE;
					DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
					Set_LivezoomOffMainForceBG(TRUE);
				} else {
					drvif_mode_disableonlinemeasure(_CHANNEL2);//Diable online measure
					drvif_mode_onlinemeasure_setting(_CHANNEL2, Scaler_InputSrcGetType(SLR_SUB_DISPLAY), FALSE, FALSE);
					//set detect timng flag true:
					if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
					{
						/*//no need because AVD don't stop detect task
						down(get_vdc_detectsemaphore());
						if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
						up(get_vdc_detectsemaphore());
						*/
					}
					else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
					{
						down(get_hdmi_detectsemaphore());
						if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
						up(get_hdmi_detectsemaphore());
					}
					else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
					{
						down(get_adc_detectsemaphore());
						fw_scaler_adc_nolock_wdg_ctrl(SLR_SUB_DISPLAY, FALSE);// Disable adc_nolock_wdg
						if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
							YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
							ADC_set_detect_flag(TRUE);
						}
						up(get_adc_detectsemaphore());
						set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
					} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
						down(get_vo_infosemaphore());
						DbgSclrFlgTkr.Sub_OuputDisplayMode = FALSE; // Preset for vo
						plane=get_vo_plane_flag(SLR_SUB_DISPLAY);
						Sub_DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};// Preset for vo
						set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
						set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
						set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
						up(get_vo_infosemaphore());
					//	vo_overscan_disable(inputSrcInfo.type);
						reset_adaptive_streaming_info(SLR_SUB_DISPLAY);//reset adaptive stream info
						if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
							Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
						else
							Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
					}
				}
				smooth_toggle_disconnect(SLR_SUB_DISPLAY,plane);
				Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();

				DbgSclrFlgTkr.Sub_OuputDisplayMode = FALSE;
				DbgSclrFlgTkr.sub_wind0000 = FALSE;
				//add semaphore for sub disp @Crixus 20150901

				Scaler_SubDispWindowSet(SrcRect);
				Sub_DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
				*p_sourceID = _UNKNOWN_INPUT;

				close_livezoom_doublebuffer();
				//close display panel

				DbgSclrFlgTkr.Sub_AutoRunScaler = FALSE;
				down(&SetSubOutPutRegion_Semaphore);
				reset_any_srcrect(&sub_dispwin_pre);
				up(&SetSubOutPutRegion_Semaphore);
				break;
			}
			case VSC_OUTPUT_VENC_MODE:
			{
				drvif_mode_disableonlinemeasure(_CHANNEL2);//Diable online measure
				drvif_mode_onlinemeasure_setting(_CHANNEL2, Scaler_InputSrcGetType(SLR_SUB_DISPLAY), FALSE, FALSE);
				//set detect timng flag true:
				if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
				{
					/*//no need because AVD don't stop detect task
					down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
					up(get_vdc_detectsemaphore());
					*/
#ifdef CONFIG_I2RND_ENABLE
					printk(KERN_EMERG"[vsc_disconnect]display:%d,port:%d\n",wid,inputSrcInfo.resourceIndex);
					printk(KERN_EMERG"rtk_hal_vsc_Disconnect para,inputSrcInfo:%d;%d;%d,outputMode:%d\n",inputSrcInfo.type, inputSrcInfo.attr, inputSrcInfo.resourceIndex, outputMode);

					if(i2rnd_test_done == 1){
						i2rnd_test_done = 0;
						rtk_hal_vsc_i2rnd_enable(_DISABLE);
						//frank@I2run disable main VENC flag
						VencModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
						DbgSclrFlgTkr.OutputVencMode = FALSE;
						vsc_i2rnd_sub_stage = I2RND_STAGE_DISABLE;
						printk(KERN_EMERG"[%s][frank]I2RND close\n", __FUNCTION__);
					}
#endif
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
				{
					down(get_hdmi_detectsemaphore());
					if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
					up(get_hdmi_detectsemaphore());
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
				{
					down(get_adc_detectsemaphore());
					fw_scaler_adc_nolock_wdg_ctrl(SLR_SUB_DISPLAY, FALSE);// Disable adc_nolock_wdg
					if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
						YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
						ADC_set_detect_flag(TRUE);
					}
					up(get_adc_detectsemaphore());
					set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
				}
				else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
					plane=get_vo_plane_flag(SLR_SUB_DISPLAY);
				}
				smooth_toggle_disconnect(SLR_SUB_DISPLAY,plane);
				Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();
				DbgSclrFlgTkr.Sub_OutputVencMode = FALSE;
				Sub_VencModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
				*p_sourceID = _UNKNOWN_INPUT;

				break;
			}
			case VSC_OUTPUT_MEMORY_MODE:
			{
				down(&SetSubOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Sub_Scaler_Stop_flag = TRUE;
				up(&SetSubOutPutRegion_Semaphore);

				if (((inputSrcInfo.type == VSC_INPUTSRC_AVD) ||(inputSrcInfo.type == VSC_INPUTSRC_HDMI) ||(inputSrcInfo.type == VSC_INPUTSRC_VDEC)) && (Get_Live_zoom_mode() == LIVE_ZOOM_SUB )) {
					Set_Live_zoom_mode(LIVE_ZOOM_OFF);
					//DataFramesynclivezoom = FALSE;
					DbgSclrFlgTkr.LivezoomMainRerunFlag = FALSE;
					DbgSclrFlgTkr.LivezoomSubRerunFlag = FALSE;
					DbgSclrFlgTkr.LivezoomvoinfocheckFlag = FALSE;
					DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
					Set_LivezoomOffMainForceBG(TRUE);
				} else {
					drvif_mode_disableonlinemeasure(_CHANNEL2);//Diable online measure
					drvif_mode_onlinemeasure_setting(_CHANNEL2,Scaler_InputSrcGetType(SLR_SUB_DISPLAY), FALSE, FALSE);
					//set detect timng flag true:
					if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
					{
						/*//no need because AVD don't stop detect task
						down(get_vdc_detectsemaphore());
						if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
						up(get_vdc_detectsemaphore());
						*/
					}
					else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
					{
						down(get_hdmi_detectsemaphore());
						if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
						up(get_hdmi_detectsemaphore());
					}
					else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
					{
						down(get_adc_detectsemaphore());
						fw_scaler_adc_nolock_wdg_ctrl(SLR_SUB_DISPLAY, FALSE);// Disable adc_nolock_wdg
						if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
							YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
							ADC_set_detect_flag(TRUE);
						}
						up(get_adc_detectsemaphore());
						set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
					} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
						down(get_vo_infosemaphore());
						DbgSclrFlgTkr.Sub_OutputMemoryMode = FALSE; // Preset for vo
						plane=get_vo_plane_flag(SLR_SUB_DISPLAY);
						Sub_MemoryModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};// Preset for vo
						set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
						set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
						set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
						up(get_vo_infosemaphore());
					//	vo_overscan_disable(inputSrcInfo.type);
						reset_adaptive_streaming_info(SLR_SUB_DISPLAY);//reset adaptive stream info
						if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
							Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
						else
							Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
					}
				}
				smooth_toggle_disconnect(SLR_SUB_DISPLAY,plane);
				Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();

				DbgSclrFlgTkr.sub_wind0000 = FALSE;
				DbgSclrFlgTkr.Sub_OutputMemoryMode = FALSE;

				Scaler_SubDispWindowSet(SrcRect);
				Sub_MemoryModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
				*p_sourceID = _UNKNOWN_INPUT;
				close_livezoom_doublebuffer();
				DbgSclrFlgTkr.Sub_AutoRunScaler = FALSE;
				down(&SetSubOutPutRegion_Semaphore);
				reset_any_srcrect(&sub_dispwin_pre);
				up(&SetSubOutPutRegion_Semaphore);
				break;
			}
			case VSC_OUTPUT_AVE_MODE:
			{

				HAL_VBE_AVE_Disconnect();
				DbgSclrFlgTkr.Sub_OutputAveMode = FALSE;
				Sub_AveModeInputInfo =	(VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};

				break;
			}
			default:
				break;
		}
	}
#endif
	return TRUE;
}


unsigned char rtk_hal_vsc_Connect(VIDEO_WID_T wid, VSC_INPUT_SRC_INFO_T inputSrcInfo, VSC_OUTPUT_MODE_T outputMode)
{
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif
	rtd_printk(KERN_INFO, TAG_NAME_VSC, "[vsc_connect]display:%d,port:%d\n",wid,inputSrcInfo.resourceIndex);
	rtd_printk(KERN_INFO, TAG_NAME_VSC, "rtk_hal_vsc_Connect para,inputSrcInfo:%d;%d;%d,outputMode:%d\n",inputSrcInfo.type, inputSrcInfo.attr, inputSrcInfo.resourceIndex, outputMode);
#ifdef CONFIG_I2RND_ENABLE
	//for VDEC source in multiview, first send table idx RPC to video fw @Crixus 20160808
	if((Scaler_I2rnd_get_enable() == _ENABLE) && (inputSrcInfo.type == VSC_INPUTSRC_VDEC)){
		if(wid ==VIDEO_WID_0){
			//reset i2rnd and pst write point when rerun scaler flow @Crixus 20180819
#ifdef CONFIG_I2RND_ENABLE
			//enable I2rnd
			if (Scaler_I2rnd_get_enable()) {
				Scaler_i2rnd_write_default_cmd_num();
				Scaler_I2rnd_set_read_cmd_num(0);
			}
#endif
#ifdef CONFIG_PST_ENABLE
			//enable pst
			if (Scaler_main_md_pst_get_enable()) {
				Scaler_pst_main_md_write_default_cmd_num();
				Scaler_pst_main_md_set_read_cmd_num(0);
			}
#endif


			Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
			i2rnd_send_table_idx(I2RND_MAIN_S0_TABLE);
			printk(KERN_EMERG"[I2RND]DTV case, send I2RND_MAIN_S0_TABLE RPC\n");
		}
#if 0
		else if(wid ==VIDEO_WID_1){
			Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);
			i2rnd_send_table_idx(I2RND_SUB_S1_TABLE);
			printk(KERN_EMERG"[I2RND]DTV case, send I2RND_SUB_S1_TABLE RPC\n");
		}
#endif
	}
#endif

#if 0//def CONFIG_I2RND_ENABLE
	printk(KERN_EMERG"[vsc_connect]display:%d,port:%d\n",wid,inputSrcInfo.resourceIndex);
	printk(KERN_EMERG"rtk_hal_vsc_Connect para,inputSrcInfo:%d;%d;%d,outputMode:%d\n",inputSrcInfo.type, inputSrcInfo.attr, inputSrcInfo.resourceIndex, outputMode);
#if 0//test FIXME
	if((i2rnd_test_done == 0) && (inputSrcInfo.type == VSC_INPUTSRC_ADC)){
		i2rnd_test_done = 1;
		rtk_hal_vsc_i2rnd_enable(_ENABLE);
		printk(KERN_EMERG"[%s][crixus]I2RND initial done\n", __FUNCTION__);
	}
#endif
#endif
	if (wid ==VIDEO_WID_0) {
		if (VscOpendone_Flag == FALSE) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Main vsc not open,so can not connect!\n");
			return TRUE;
		}
		increase_source_connect_verify_num(SLR_MAIN_DISPLAY);//increase the main source num
		switch(outputMode)
		{
			case VSC_OUTPUT_DISPLAY_MODE:
			{
				if(DbgSclrFlgTkr.OuputDisplayMode == TRUE)
				{
					if(rtk_hal_vsc_Getdualdecoder_run() && (inputSrcInfo.type == VSC_INPUTSRC_VDEC)) {
						Scaler_Send_VoType_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
						rtd_printk(KERN_INFO, TAG_NAME_VSC, "dual decoder case,connect just change port return\n");
						DisplayModeInputInfo = inputSrcInfo;
						return TRUE;
					}
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OuputDisplayMode is on, please disconnect output display mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.OutputVencMode == TRUE)
				{
					if((VencModeInputInfo.type == inputSrcInfo.type) && (VencModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						DbgSclrFlgTkr.OuputDisplayMode = TRUE;
						DisplayModeInputInfo = inputSrcInfo;
						//open display panel
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because venc mode is on, and display mode input is not the same with venc mode\n");
						return TRUE;
					}

				}
				else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE)
				{
					if((MemoryModeInputInfo.type == inputSrcInfo.type) && (MemoryModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						DbgSclrFlgTkr.OuputDisplayMode = TRUE;
						DisplayModeInputInfo = inputSrcInfo;
						//open display panel
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because memory mode is on, and display mode input is not the same with memory mode\n");
						return TRUE;
					}

				}
				else if(DbgSclrFlgTkr.OutputAveMode == TRUE)
				{
					if((AveModeInputInfo.type == inputSrcInfo.type) && (AveModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						DbgSclrFlgTkr.OuputDisplayMode = TRUE;
						DisplayModeInputInfo = inputSrcInfo;
						//open display panel
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because ave mode is on, and display mode input is not the same with ave mode\n");
						return TRUE;
					}

				}
				else
				{
					DisplayModeInputInfo = inputSrcInfo;
					DbgSclrFlgTkr.OuputDisplayMode = TRUE;
					if (inputSrcInfo.type == VSC_INPUTSRC_VDEC) {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
						Scaler_Send_VoType_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
						if((inputSrcInfo.resourceIndex == 1) || (inputSrcInfo.resourceIndex == 0)) {
							down(&Adaptive_Streaming_Semaphore);
							adaptive_streaming_info[inputSrcInfo.resourceIndex].display = SLR_MAIN_DISPLAY; //Link port and display channel info with  adaptive_streaming_info
							up(&Adaptive_Streaming_Semaphore);
						}
					}
					else if (inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
						Scaler_Send_VoType_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
					}

					if(VSC_INPUTSRC_HDMI != inputSrcInfo.type)
					{
						if(SRC_CONNECT_DONE == get_HDMI_Global_Status())
							drvif_Hdmi_WatchDog_Apply(_DISABLE, HDMI_WD_VSC_COND);
					}
				}

				break;
			}
			case VSC_OUTPUT_VENC_MODE:
			{
				if(DbgSclrFlgTkr.OutputVencMode==TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "please disconnect output venc mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputMemoryMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.OutputAveMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputAveMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE)
					{
						if((DisplayModeInputInfo.type == inputSrcInfo.type) && (DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
						{
							DbgSclrFlgTkr.OutputVencMode = TRUE;
							VencModeInputInfo = inputSrcInfo;
						}
						else
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because display mode is on, and venc mode input is not the same with display mode\n");
							return TRUE;
						}
					}
					else
					{
						VencModeInputInfo = inputSrcInfo;
						DbgSclrFlgTkr.OutputVencMode = TRUE;
					}
				}

				break;
			}
			case VSC_OUTPUT_MEMORY_MODE:
			{
				if(DbgSclrFlgTkr.OutputMemoryMode==TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "please disconnect output memory mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.OutputVencMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputVencMode is on, please disconnect output Venc mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.OutputAveMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputAveMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE)
					{
						if((DisplayModeInputInfo.type == inputSrcInfo.type) && (DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
						{
							DbgSclrFlgTkr.OutputMemoryMode = TRUE;
							MemoryModeInputInfo = inputSrcInfo;
						}
						else
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because display mode is on, and memory mode input is not the same with display mode\n");
							return TRUE;
						}
					}
					else
					{
						MemoryModeInputInfo = inputSrcInfo;
						DbgSclrFlgTkr.OutputMemoryMode = TRUE;
						if (inputSrcInfo.type == VSC_INPUTSRC_VDEC) {
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
							Scaler_Send_VoType_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
							if((inputSrcInfo.resourceIndex == 1) || (inputSrcInfo.resourceIndex == 0))
							{
								down(&Adaptive_Streaming_Semaphore);
								adaptive_streaming_info[inputSrcInfo.resourceIndex].display = SLR_MAIN_DISPLAY; //Link port and display channel info with  adaptive_streaming_info
								up(&Adaptive_Streaming_Semaphore);
							}
						} else if (inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
							Scaler_Send_VoType_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
						}
					}
				}
				break;
			}
			case VSC_OUTPUT_AVE_MODE:
			{
				if(DbgSclrFlgTkr.OutputAveMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputAveMode is on, please disconnect output ave mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputMemoryMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.OutputVencMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputVencMode is on, please disconnect output Venc mode first\n");
					return TRUE;
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE)
					{
						if((DisplayModeInputInfo.type == inputSrcInfo.type) && (DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
						{
							DbgSclrFlgTkr.OutputAveMode = TRUE;
							AveModeInputInfo = inputSrcInfo;
						}
						else
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because display mode is on, and AVE mode input is not the same with display mode\n");
							return TRUE;
						}
					}
					else
					{
						DbgSclrFlgTkr.OutputAveMode = TRUE;
						AveModeInputInfo = inputSrcInfo;
					}
				}
				break;
			}
			default:
				break;
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	if (wid ==VIDEO_WID_1) {
		if (Sub_VscOpendone_Flag == FALSE) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Sub vsc not open,so can not connect!\n");
			return TRUE;
		}
		increase_source_connect_verify_num(SLR_SUB_DISPLAY);//increase the sub source num
		switch(outputMode)
		{
			case VSC_OUTPUT_DISPLAY_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OuputDisplayMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_OuputDisplayMode is on, please disconnect output display mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.Sub_OutputVencMode == TRUE)
				{
					if((Sub_VencModeInputInfo.type == inputSrcInfo.type) && (Sub_VencModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						DbgSclrFlgTkr.Sub_OuputDisplayMode = TRUE;
						Sub_DisplayModeInputInfo = inputSrcInfo;
						//open display panel
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because venc mode is on, and display mode input is not the same with venc mode\n");
						return TRUE;
					}

				}
				else if(DbgSclrFlgTkr.Sub_OutputMemoryMode == TRUE)
				{
					if((Sub_MemoryModeInputInfo.type == inputSrcInfo.type) && (Sub_MemoryModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						DbgSclrFlgTkr.Sub_OuputDisplayMode = TRUE;
						Sub_DisplayModeInputInfo = inputSrcInfo;
						//open display panel
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because memory mode is on, and display mode input is not the same with memory mode\n");
						return TRUE;
					}

				}
				else if(DbgSclrFlgTkr.Sub_OutputAveMode == TRUE)
				{
					if((Sub_AveModeInputInfo.type == inputSrcInfo.type) && (Sub_AveModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						DbgSclrFlgTkr.Sub_OuputDisplayMode = TRUE;
						Sub_DisplayModeInputInfo = inputSrcInfo;
						//open display panel
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because ave mode is on, and display mode input is not the same with ave mode\n");
						return TRUE;
					}

				}
				else
				{
					Sub_DisplayModeInputInfo = inputSrcInfo;
					DbgSclrFlgTkr.Sub_OuputDisplayMode = TRUE;


					if (((inputSrcInfo.type == VSC_INPUTSRC_AVD)||/*(inputSrcInfo.type == VSC_INPUTSRC_ADC) ||*/(inputSrcInfo.type == VSC_INPUTSRC_HDMI) || (inputSrcInfo.type == VSC_INPUTSRC_VDEC))
						&& (Sub_DisplayModeInputInfo.type == DisplayModeInputInfo.type)
						&& (Sub_DisplayModeInputInfo.resourceIndex == DisplayModeInputInfo.resourceIndex)
						&& (DbgSclrFlgTkr.Sub_OuputDisplayMode == DbgSclrFlgTkr.OuputDisplayMode)) {/*DTV and HDMI*/
						Set_Live_zoom_mode(LIVE_ZOOM_SUB);
#if 1/*disable livezoom framsync flow*/
						DbgSclrFlgTkr.DataFramesynclivezoom = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC);
#else
						DataFramesynclivezoom = FALSE;
#endif
					} else {
						Set_Live_zoom_mode(LIVE_ZOOM_OFF);
						DbgSclrFlgTkr.DataFramesynclivezoom = FALSE;
						DbgSclrFlgTkr.LivezoomMainRerunFlag = FALSE;
						DbgSclrFlgTkr.LivezoomSubRerunFlag = FALSE;
						DbgSclrFlgTkr.LivezoomvoinfocheckFlag = FALSE;
						DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
						Set_LivezoomOffMainForceBG(FALSE);
						if (inputSrcInfo.type == VSC_INPUTSRC_VDEC) {
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);

							Scaler_Send_VoType_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
							if((inputSrcInfo.resourceIndex == 1) || (inputSrcInfo.resourceIndex == 0)) {
								down(&Adaptive_Streaming_Semaphore);
								adaptive_streaming_info[inputSrcInfo.resourceIndex].display = SLR_SUB_DISPLAY; //Link port and display channel info with  adaptive_streaming_info
								up(&Adaptive_Streaming_Semaphore);
							}
						}
						else if (inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
							Scaler_Send_VoType_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
						}
					}

				}

				break;
			}
			case VSC_OUTPUT_VENC_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OutputVencMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "please disconnect output venc mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.Sub_OutputMemoryMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_OutputMemoryMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.Sub_OutputAveMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_OutputAveMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else
				{
					if(DbgSclrFlgTkr.Sub_OuputDisplayMode == TRUE)
					{
						if((Sub_DisplayModeInputInfo.type == inputSrcInfo.type) && (Sub_DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
						{
							DbgSclrFlgTkr.Sub_OutputVencMode = TRUE;
							Sub_VencModeInputInfo = inputSrcInfo;
#ifdef CONFIG_I2RND_ENABLE
							printk(KERN_EMERG"[vsc_connect]display:%d,port:%d\n",wid,inputSrcInfo.resourceIndex);
							printk(KERN_EMERG"rtk_hal_vsc_Connect para,inputSrcInfo:%d;%d;%d,outputMode:%d\n",inputSrcInfo.type, inputSrcInfo.attr, inputSrcInfo.resourceIndex, outputMode);

							if((i2rnd_test_done == 0) && (inputSrcInfo.type == VSC_INPUTSRC_AVD)){
								i2rnd_test_done = 1;
								rtk_hal_vsc_i2rnd_enable(_ENABLE);
								Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
								VSC_OUTPUT_VENC_MODE_FLAG = TRUE;
								//apvr trigger scaler flow in tsk @Crixus 20160824
								if((vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_DISABLE) || (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_RERUN_MAIN_DONE))
									vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_TRIGGER_RUN_MAIN;
								printk(KERN_EMERG"[%s][crixus]I2RND initial done\n", __FUNCTION__);
							}
#endif
						}
						else
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because display mode is on, and venc mode input is not the same with display mode\n");
							return TRUE;
						}
					}
					else
					{
						Sub_VencModeInputInfo = inputSrcInfo;
						DbgSclrFlgTkr.Sub_OutputVencMode = TRUE;
#ifdef CONFIG_I2RND_ENABLE
						printk(KERN_EMERG"[vsc_connect]display:%d,port:%d\n",wid,inputSrcInfo.resourceIndex);
						printk(KERN_EMERG"rtk_hal_vsc_Connect para,inputSrcInfo:%d;%d;%d,outputMode:%d\n",inputSrcInfo.type, inputSrcInfo.attr, inputSrcInfo.resourceIndex, outputMode);

						if((i2rnd_test_done == 0) && (inputSrcInfo.type == VSC_INPUTSRC_AVD)){
							i2rnd_test_done = 1;
							rtk_hal_vsc_i2rnd_enable(_ENABLE);
							Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
							VSC_OUTPUT_VENC_MODE_FLAG = TRUE;

							//apvr trigger scaler flow in tsk @Crixus 20160824
							if((vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_DISABLE) || (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_RERUN_MAIN_DONE))
								vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_TRIGGER_RUN_MAIN;
							printk(KERN_EMERG"[%s][crixus]I2RND initial done\n", __FUNCTION__);
						}
#endif
					}
				}

				break;
			}
			case VSC_OUTPUT_MEMORY_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OutputMemoryMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "please disconnect output memory mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.Sub_OutputVencMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputVencMode is on, please disconnect output Venc mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.Sub_OutputAveMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.OutputAveMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else
				{
					if(DbgSclrFlgTkr.Sub_OuputDisplayMode == TRUE)
					{
						if((Sub_DisplayModeInputInfo.type == inputSrcInfo.type) && (Sub_DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
						{
							DbgSclrFlgTkr.Sub_OutputMemoryMode = TRUE;
							Sub_MemoryModeInputInfo = inputSrcInfo;
						}
						else
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because display mode is on, and memory mode input is not the same with display mode\n");
							return TRUE;
						}
					}
					else
					{

						Sub_MemoryModeInputInfo = inputSrcInfo;
						DbgSclrFlgTkr.Sub_OutputMemoryMode = TRUE;
						if (((inputSrcInfo.type == VSC_INPUTSRC_AVD) ||(inputSrcInfo.type == VSC_INPUTSRC_HDMI) || (inputSrcInfo.type == VSC_INPUTSRC_VDEC))
							&& (Sub_DisplayModeInputInfo.type == DisplayModeInputInfo.type)
							&& (Sub_DisplayModeInputInfo.resourceIndex == DisplayModeInputInfo.resourceIndex)
							&& (DbgSclrFlgTkr.Sub_OuputDisplayMode == DbgSclrFlgTkr.OuputDisplayMode))
						{/*DTV and HDMI*/
							Set_Live_zoom_mode(LIVE_ZOOM_SUB);
#if 1/*disable livezoom framsync flow*/
							DbgSclrFlgTkr.DataFramesynclivezoom = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC);
#else
							DataFramesynclivezoom = FALSE;
#endif
							} else {
								Set_Live_zoom_mode(LIVE_ZOOM_OFF);
								DbgSclrFlgTkr.DataFramesynclivezoom = FALSE;
								DbgSclrFlgTkr.LivezoomMainRerunFlag = FALSE;
								DbgSclrFlgTkr.LivezoomSubRerunFlag = FALSE;
								DbgSclrFlgTkr.LivezoomvoinfocheckFlag = FALSE;
								DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
								Set_LivezoomOffMainForceBG(FALSE);
								if (inputSrcInfo.type == VSC_INPUTSRC_VDEC) {
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);

									Scaler_Send_VoType_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
									if((inputSrcInfo.resourceIndex == 1) || (inputSrcInfo.resourceIndex == 0)) {
										down(&Adaptive_Streaming_Semaphore);
										adaptive_streaming_info[inputSrcInfo.resourceIndex].display = SLR_SUB_DISPLAY; //Link port and display channel info with  adaptive_streaming_info
										up(&Adaptive_Streaming_Semaphore);
									}
								}
								else if (inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s line:%d ########\r\n", __FUNCTION__, __LINE__);
									Scaler_Send_VoType_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
								}
							}
					}
				}
				break;
			}
			case VSC_OUTPUT_AVE_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OutputAveMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_OutputAveMode is on, please disconnect output ave mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.Sub_OutputMemoryMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_OutputMemoryMode is on, please disconnect output memory mode first\n");
					return TRUE;
				}
				else if(DbgSclrFlgTkr.Sub_OutputVencMode == TRUE)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_OutputVencMode is on, please disconnect output Venc mode first\n");
					return TRUE;
				}
				else
				{
					if(DbgSclrFlgTkr.Sub_OuputDisplayMode == TRUE)
					{
						if((Sub_DisplayModeInputInfo.type == inputSrcInfo.type) && (Sub_DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
						{
							DbgSclrFlgTkr.Sub_OutputAveMode = TRUE;
							Sub_AveModeInputInfo = inputSrcInfo;
						}
						else
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "because display mode is on, and AVE mode input is not the same with display mode\n");
							return TRUE;
						}
					}
					else
					{
						DbgSclrFlgTkr.Sub_OutputAveMode = TRUE;
						Sub_AveModeInputInfo = inputSrcInfo;
					}
				}
				break;
			}
			default:
				break;
		}
	}
#endif
	return TRUE;
}

void rtk_i3ddma_disable(void)
{
#ifdef CONFIG_FORCE_RUN_I3DDMA
down(&Force_Run_Idma_Semaphore);
	if(get_force_i3ddma_enable(SLR_MAIN_DISPLAY)) {
		Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_HDMI, 0xfa);
		set_force_i3ddma_enable(false);
		I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);
		msleep(40/*100*/); // wait DMA write done
		// [IDMA] allocate/release IDMA memory dynamic
		if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == TRUE)
			I3DDMA_DolbyVision_HDMI_DeInit();
	}
up(&Force_Run_Idma_Semaphore);
#endif
}

struct semaphore* get_double_buffer_semaphore(void)
{
	return &Double_buffer_Semaphore;
}
extern void vo_free_photo_buffer(unsigned int ch);
unsigned char rtk_hal_vsc_Disconnect(VIDEO_WID_T wid, VSC_INPUT_SRC_INFO_T inputSrcInfo, VSC_OUTPUT_MODE_T outputMode)
{
	unsigned int *p_sourceID = NULL;
	StructSrcRect SrcRect = {0, 0, 0, 0};

#ifdef CONFIG_I2RND_B05_ENABLE
     if(inputSrcInfo.type == VSC_INPUTSRC_VDEC) {
           //  printk("!!!!!!!!!!!!!!!!!!!!!!!!!!!b05_vsc_Disconnect!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
             rtk_hal_vsc_i2rnd_b05_enable(_DISABLE);
     }
#endif

#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	} else if (wid == VIDEO_WID_0) {
		p_sourceID = &DbgSclrFlgTkr.main_opensourceID;
	} else {
		p_sourceID = &DbgSclrFlgTkr.sub_opensourceID;
	}
#else
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	} else {
		p_sourceID = &DbgSclrFlgTkr.main_opensourceID;
	}
#endif

	rtd_printk(KERN_INFO, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_INFO, TAG_NAME_VSC, "rtk_hal_vsc_Disonnect para,inputSrcInfo:%d;%d;%d,outputMode:%d\n",inputSrcInfo.type, inputSrcInfo.attr, inputSrcInfo.resourceIndex, outputMode);
	unsigned char plane=0;
	if (wid ==VIDEO_WID_0) {
		set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
		switch(outputMode)
		{
			case VSC_OUTPUT_DISPLAY_MODE:
			{
				if(DbgSclrFlgTkr.OuputDisplayMode == TRUE)
				{
					if((DisplayModeInputInfo.type == inputSrcInfo.type) && (DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						if (rtk_hal_vsc_Getdualdecoder_run() && (inputSrcInfo.type == VSC_INPUTSRC_VDEC)) {
							Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
							rtd_printk(KERN_INFO, TAG_NAME_VSC, "dual decoder case,disconnect not change,return\n");
						        down(get_vo_infosemaphore());
							set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
							up(get_vo_infosemaphore());
                                                	return TRUE;
						}
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, TRUE);//Enable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
						if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){//AP not mute on yet
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
							up(get_forcebg_semaphore());
						}
						down(&SetMainOutPutRegion_Semaphore);
						DbgSclrFlgTkr.Main_Scaler_Stop_flag = TRUE;
						DbgSclrFlgTkr.Main_force_frc_flag = FALSE;
						DbgSclrFlgTkr.Main_force_frc_fs_flag = FALSE;
						DbgSclrFlgTkr.smoothtoggle_start_flag = FALSE;
						//frank@0204 K-task6477 reset below flag to avoid smooth toggle RPC --
						DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag = FALSE;
						DbgSclrFlgTkr.Main_smooth_toggle_set_flag = FALSE;
						DbgSclrFlgTkr.rotate_run_scaler_flag = FALSE;
						DbgSclrFlgTkr.rotate_muteoff_request_flag = FALSE;
						rotate_mode = DIRECT_VO_FRAME_ORIENTATION_DEFAULT;
						rotate_mode_pre = DIRECT_VO_FRAME_ORIENTATION_DEFAULT;
						set_rotate_mode(DIRECT_VO_FRAME_ORIENTATION_DEFAULT);
						set_ori_rotate_mode(DIRECT_VO_FRAME_ORIENTATION_DEFAULT);
						is_DTV_flag_set(_DISABLE);
						zoom_clear_input_output_region_record(wid);
						Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);
						up(&SetMainOutPutRegion_Semaphore);
						DbgSclrFlgTkr.RGB444Mode_change = 0;
						DbgSclrFlgTkr.RGB444Mode = 0;
						DbgSclrFlgTkr.main_winfreeze=0;
						if (inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
							vo_free_photo_buffer(0);
						}
						drivf_scaler_reset_freerun();

						if((DbgSclrFlgTkr.OutputVencMode == FALSE) && (DbgSclrFlgTkr.OutputMemoryMode == FALSE) && (DbgSclrFlgTkr.OutputAveMode == FALSE))
						{
							drvif_mode_disableonlinemeasure(_CHANNEL1);//Diable online measure
							drvif_mode_onlinemeasure_setting(_CHANNEL1, Scaler_InputSrcGetType(SLR_MAIN_DISPLAY), FALSE, FALSE);
							//set detect timng flag true:
							if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
							{
								/*//no need because AVD don't stop detect task
								down(get_vdc_detectsemaphore());
								if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
								up(get_vdc_detectsemaphore());
								*/
                                rtk_i3ddma_disable();

							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
							{
								down(get_hdmi_detectsemaphore());
								if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
								up(get_hdmi_detectsemaphore());
                                rtk_i3ddma_disable();

								drvif_Hdmi_WatchDog_Apply(_DISABLE, HDMI_WD_VSC_COND);
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
							{
								down(get_adc_detectsemaphore());
								fw_scaler_adc_nolock_wdg_ctrl(SLR_MAIN_DISPLAY, FALSE);// Disable adc_nolock_wdg
								if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
									YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
									ADC_set_detect_flag(TRUE);
								}
								up(get_adc_detectsemaphore());
								rtk_i3ddma_disable();
								set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
							} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
								down(get_vo_infosemaphore());
								DbgSclrFlgTkr.OuputDisplayMode = FALSE;
								plane=get_vo_plane_flag(SLR_MAIN_DISPLAY);
								DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
								set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
								set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
								set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
								up(get_vo_infosemaphore());
							//	vo_overscan_disable(inputSrcInfo.type);
								reset_adaptive_streaming_info(SLR_MAIN_DISPLAY);//reset adaptive stream info
								if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
								{
									Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
								}
								else
									Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
							}
							Scaler_ClearVOInfo(Get_DisplayMode_Port(wid));
							smooth_toggle_disconnect(SLR_MAIN_DISPLAY,plane);
							Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							state_update_disp_info();

#ifdef Mer2_MEMORY_ALLOC
							drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(0, 0, 0, 1);
							drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(1, 0, 0, 1);
#endif

						}

						//USER:Lewislee DATE:2015/10/2
						//when PIP off, need reset setting
						Scaler_Disp3dSetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE, SLR_3D_2D_ONLY);
						Scaler_Set3DMode_Attr(SLR_MAIN_DISPLAY, SLR_3DMODE_2D);

						DbgSclrFlgTkr.OuputDisplayMode = FALSE;
						DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
						*p_sourceID = _UNKNOWN_INPUT;
						//close display panel
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;display mode not open\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OutputVencMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_VENC_MODE);
					} else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_MEMORY_MODE);
					} else if(DbgSclrFlgTkr.OutputAveMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_AVE_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, " error display mode not open\n");
						return TRUE;
					}
				}
				DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset DbgSclrFlgTkr.Main_during_scalerflow_flag.
				DbgSclrFlgTkr.Main_AutoRunScaler = FALSE;
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_pre);
				reset_any_srcrect(&main_dispwin_for_only_xy);
				up(&SetMainOutPutRegion_Semaphore);
				if((Get_Live_zoom_mode()!=LIVE_ZOOM_OFF) &&(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_STATE) ==  _MODE_STATE_ACTIVE))
				{// when MAIN disconnected, mute the video for SUB of livezoom or magnifier. Q-3072
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);//_DISABLE);//pool test
					drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
					up(get_forcebg_semaphore());
				}
				if (Get_LivezoomOffMainForceBG() == TRUE) {
					Set_LivezoomOffMainForceBG(FALSE);
				}
				DbgSclrFlgTkr.DataFramesynclivezoom = FALSE;

				if(read_buffer_first_flag == 1){
					read_buffer_first_flag = 0;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[self-dianosis]27M reset !!\n");
				}
				break;
			}
			case VSC_OUTPUT_VENC_MODE:
			{
				if(DbgSclrFlgTkr.OutputVencMode == TRUE)
				{
					if((VencModeInputInfo.type == inputSrcInfo.type) && (VencModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						if(DbgSclrFlgTkr.OuputDisplayMode == FALSE)
						{
							drvif_mode_disableonlinemeasure(_CHANNEL1);//Diable online measure
							drvif_mode_onlinemeasure_setting(_CHANNEL1, Scaler_InputSrcGetType(SLR_MAIN_DISPLAY), FALSE, FALSE);
							//set detect timng flag true:
							if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
							{
								/*//no need because AVD don't stop detect task
								down(get_vdc_detectsemaphore());
								if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
								up(get_vdc_detectsemaphore());
								*/
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
							{
								down(get_hdmi_detectsemaphore());
								if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
								up(get_hdmi_detectsemaphore());
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
							{
								down(get_adc_detectsemaphore());
								fw_scaler_adc_nolock_wdg_ctrl(SLR_MAIN_DISPLAY, FALSE);// Disable adc_nolock_wdg
								if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
									YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
									ADC_set_detect_flag(TRUE);
								}
								up(get_adc_detectsemaphore());
								set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
								plane=get_vo_plane_flag(SLR_MAIN_DISPLAY);
							}
							smooth_toggle_disconnect(SLR_MAIN_DISPLAY,plane);
							Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							state_update_disp_info();
						}
						DbgSclrFlgTkr.OutputVencMode = FALSE;
						VencModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
						*p_sourceID = _UNKNOWN_INPUT;
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;venc mode close fail\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_DISPLAY_MODE);
					} else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_MEMORY_MODE);
					} else if(DbgSclrFlgTkr.OutputAveMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_AVE_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, " error venc mode not open\n");
						return TRUE;
					}
				}

				break;
			}
			case VSC_OUTPUT_MEMORY_MODE://Current same with VSC_OUTPUT_DISPLAY_MODE
			{
				if(DbgSclrFlgTkr.OutputMemoryMode == TRUE)
				{
					if((MemoryModeInputInfo.type == inputSrcInfo.type) && (MemoryModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, TRUE);//Enable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
						if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){//AP not mute on yet
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
							up(get_forcebg_semaphore());
						}
						down(&SetMainOutPutRegion_Semaphore);
						DbgSclrFlgTkr.Main_Scaler_Stop_flag = TRUE;
						DbgSclrFlgTkr.Main_force_frc_flag = FALSE;
						DbgSclrFlgTkr.Main_force_frc_fs_flag = FALSE;
						DbgSclrFlgTkr.smoothtoggle_start_flag = FALSE;
						//frank@0204 K-task6477 reset below flag to avoid smooth toggle RPC --
						DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag = FALSE;
						DbgSclrFlgTkr.Main_smooth_toggle_set_flag = FALSE;
						DbgSclrFlgTkr.rotate_run_scaler_flag = FALSE;
						DbgSclrFlgTkr.rotate_muteoff_request_flag = FALSE;
						is_DTV_flag_set(_DISABLE);
						zoom_clear_input_output_region_record(wid);
						Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);
						up(&SetMainOutPutRegion_Semaphore);
						DbgSclrFlgTkr.RGB444Mode_change = 0;
						DbgSclrFlgTkr.RGB444Mode = 0;
						DbgSclrFlgTkr.main_winfreeze=0;
						if(DbgSclrFlgTkr.OuputDisplayMode==FALSE)
						{
							drvif_mode_disableonlinemeasure(_CHANNEL1);//Diable online measure
							drvif_mode_onlinemeasure_setting(_CHANNEL1, Scaler_InputSrcGetType(SLR_MAIN_DISPLAY), FALSE, FALSE);
							//set detect timng flag true:
							if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
							{
								/*//no need because AVD don't stop detect task
								down(get_vdc_detectsemaphore());
								if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
								up(get_vdc_detectsemaphore());
								*/
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
							{
								down(get_hdmi_detectsemaphore());
								if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
								up(get_hdmi_detectsemaphore());
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
							{
								down(get_adc_detectsemaphore());
								fw_scaler_adc_nolock_wdg_ctrl(SLR_MAIN_DISPLAY, FALSE);// Disable adc_nolock_wdg
								if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
									YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
									ADC_set_detect_flag(TRUE);
								}
								up(get_adc_detectsemaphore());
								set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
							} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
								down(get_vo_infosemaphore());
								DbgSclrFlgTkr.OutputMemoryMode = FALSE;
								plane=get_vo_plane_flag(SLR_MAIN_DISPLAY);
								MemoryModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
								set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
								set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
								set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
								up(get_vo_infosemaphore());
							//	vo_overscan_disable(inputSrcInfo.type);
								reset_adaptive_streaming_info(SLR_MAIN_DISPLAY);//reset adaptive stream info
								if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
									Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
								else
									Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
							}
							Scaler_ClearVOInfo(Get_DisplayMode_Port(wid));
							smooth_toggle_disconnect(SLR_MAIN_DISPLAY,plane);
							Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							state_update_disp_info();
						}
						DbgSclrFlgTkr.OutputMemoryMode = FALSE;
						MemoryModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
						*p_sourceID = _UNKNOWN_INPUT;
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;memory mode close fail\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_DISPLAY_MODE);
					} else if(DbgSclrFlgTkr.OutputVencMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_VENC_MODE);
					} else if(DbgSclrFlgTkr.OutputAveMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_AVE_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, " error memory mode not open\n");
						return TRUE;
					}
				}
				DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset DbgSclrFlgTkr.Main_during_scalerflow_flag.
				DbgSclrFlgTkr.Main_AutoRunScaler = FALSE;
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_pre);
				reset_any_srcrect(&main_dispwin_for_only_xy);
				up(&SetMainOutPutRegion_Semaphore);
				if((Get_Live_zoom_mode()!=LIVE_ZOOM_OFF) &&(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_STATE) ==  _MODE_STATE_ACTIVE))
				{// when MAIN disconnected, mute the video for SUB of livezoom or magnifier. Q-3072
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);//_DISABLE);//pool test
					drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
					up(get_forcebg_semaphore());
				}
				if (Get_LivezoomOffMainForceBG() == TRUE) {
					Set_LivezoomOffMainForceBG(FALSE);
				}
				DbgSclrFlgTkr.DataFramesynclivezoom = FALSE;
				break;
			}
			case VSC_OUTPUT_AVE_MODE:
			{
				if(DbgSclrFlgTkr.OutputAveMode == TRUE)
				{
					if((AveModeInputInfo.type == inputSrcInfo.type) && (AveModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						HAL_VBE_AVE_Disconnect();
						DbgSclrFlgTkr.OutputAveMode = FALSE;
						AveModeInputInfo =  (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;ave mode not open\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_DISPLAY_MODE);
					} else if(DbgSclrFlgTkr.OutputVencMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_VENC_MODE);
					} else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_MEMORY_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, " error ave mode not open\n");
						return TRUE;
					}
				}
				break;
			}
			default:
				break;
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	if (wid ==VIDEO_WID_1) {
		set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
		switch(outputMode)
		{
			case VSC_OUTPUT_DISPLAY_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OuputDisplayMode == TRUE)
				{
					if((Sub_DisplayModeInputInfo.type == inputSrcInfo.type) && (Sub_DisplayModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, TRUE);//Enable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);//Auto mue before disconnect
						drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
						up(get_forcebg_semaphore());
						if((DbgSclrFlgTkr.Sub_OutputVencMode == FALSE) && (DbgSclrFlgTkr.Sub_OutputMemoryMode == FALSE) && (DbgSclrFlgTkr.Sub_OutputAveMode == FALSE))
						{
							down(&SetSubOutPutRegion_Semaphore);
							DbgSclrFlgTkr.Sub_Scaler_Stop_flag = TRUE;
							zoom_clear_input_output_region_record(wid);
							Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);
							up(&SetSubOutPutRegion_Semaphore);

							if (((inputSrcInfo.type == VSC_INPUTSRC_AVD) ||(inputSrcInfo.type == VSC_INPUTSRC_HDMI) ||(inputSrcInfo.type == VSC_INPUTSRC_VDEC)) && (Get_Live_zoom_mode() == LIVE_ZOOM_SUB )) {
								Set_Live_zoom_mode(LIVE_ZOOM_OFF);
								//DataFramesynclivezoom = FALSE;
								DbgSclrFlgTkr.LivezoomMainRerunFlag = FALSE;
								DbgSclrFlgTkr.LivezoomSubRerunFlag = FALSE;
								DbgSclrFlgTkr.LivezoomvoinfocheckFlag = FALSE;
								DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
								Set_LivezoomOffMainForceBG(TRUE);
								drvif_memory_compression_rpc();
							} else {
								drvif_mode_disableonlinemeasure(_CHANNEL2);//Diable online measure
								drvif_mode_onlinemeasure_setting(_CHANNEL2, Scaler_InputSrcGetType(SLR_SUB_DISPLAY), FALSE, FALSE);
								//set detect timng flag true:
								if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
								{
									/*//no need because AVD don't stop detect task
									down(get_vdc_detectsemaphore());
									if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
									up(get_vdc_detectsemaphore());
									*/
								}
								else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
								{
									down(get_hdmi_detectsemaphore());
									if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
									up(get_hdmi_detectsemaphore());
								}
								else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
								{
									down(get_adc_detectsemaphore());
									fw_scaler_adc_nolock_wdg_ctrl(SLR_SUB_DISPLAY, FALSE);// Disable adc_nolock_wdg
									if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
										YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
										ADC_set_detect_flag(TRUE);
									}
									up(get_adc_detectsemaphore());
									set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
								} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
									down(get_vo_infosemaphore());
									DbgSclrFlgTkr.Sub_OuputDisplayMode = FALSE;
									plane=get_vo_plane_flag(SLR_SUB_DISPLAY);
									Sub_DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
									set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
									set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
									if(Get_Live_zoom_mode()==LIVE_ZOOM_OFF)
									{
										set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
									}
									else
									{
										//live zoom ON dont set force-chagne flag, cuz...
										// SUB disconnect -> set force change = 1 -> unpause -> Vo ready sent -> Vo Ready set info_change = 1
										// -> checksignal set MAIN state = search -> NG //WOSQRTK-2160
									}
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
									up(get_vo_infosemaphore());
								//	vo_overscan_disable(inputSrcInfo.type);
									reset_adaptive_streaming_info(SLR_SUB_DISPLAY);//reset adaptive stream info
									if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
										Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
									else
										Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
								}
								Scaler_ClearVOInfo(Get_DisplayMode_Port(wid));
							}

							smooth_toggle_disconnect(SLR_SUB_DISPLAY,plane);
							Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							state_update_disp_info();
						}
						DbgSclrFlgTkr.Sub_OuputDisplayMode = FALSE;
						DbgSclrFlgTkr.sub_wind0000 = FALSE;

						Scaler_SubDispWindowSet(SrcRect);

						Sub_DisplayModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
						*p_sourceID = _UNKNOWN_INPUT;
						close_livezoom_doublebuffer();
						//close display panel

						//USER:Lewislee DATE:2015/10/2
						//when PIP off, need reset setting
						Scaler_Disp3dSetInfo(SLR_SUB_DISPLAY, SLR_DISP_3D_3DTYPE, SLR_3D_2D_ONLY);
						Scaler_Set3DMode_Attr(SLR_SUB_DISPLAY, SLR_3DMODE_2D);
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;display mode not open\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OutputVencMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_VENC_MODE);
					} else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_MEMORY_MODE);
					} else if(DbgSclrFlgTkr.OutputAveMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_AVE_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, " error display mode not open\n");
						return TRUE;
					}
				}
				DbgSclrFlgTkr.Sub_AutoRunScaler = FALSE;
				/*qiangzhou:should clear setting for mutilvew(sub nosignal) and livezoom switch case */
				if (DbgSclrFlgTkr.Sub_Output_Set_flag == TRUE) {
					DbgSclrFlgTkr.Sub_Output_Set_flag = FALSE;
				}
				down(&SetSubOutPutRegion_Semaphore);
				reset_any_srcrect(&sub_dispwin_pre);
				up(&SetSubOutPutRegion_Semaphore);

				if(sub_read_buffer_first_flag == 1){
					Scaler_AVD_EnableVD27MMode(VD_27M_HSD960_DI5A);
					Scaler_AVD_SetDetectStage(0);//DETECT_STAGE_INIT
					sub_read_buffer_first_flag = 0;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[self-dianosis]27M reset !!\n");
				}
				break;
			}
			case VSC_OUTPUT_VENC_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OutputVencMode == TRUE)
				{
					if((Sub_VencModeInputInfo.type == inputSrcInfo.type) && (Sub_VencModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						if(DbgSclrFlgTkr.Sub_OuputDisplayMode == FALSE)
						{
							drvif_mode_disableonlinemeasure(_CHANNEL2);//Diable online measure
							drvif_mode_onlinemeasure_setting(_CHANNEL2, Scaler_InputSrcGetType(SLR_SUB_DISPLAY), FALSE, FALSE);
							//set detect timng flag true:
							if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
							{
							/*//no need because AVD don't stop detect task
								down(get_vdc_detectsemaphore());
								if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
								up(get_vdc_detectsemaphore());
							*/
#ifdef CONFIG_I2RND_ENABLE
							printk(KERN_EMERG"[vsc_disconnect]display:%d,port:%d\n",wid,inputSrcInfo.resourceIndex);
							printk(KERN_EMERG"rtk_hal_vsc_Disconnect para,inputSrcInfo:%d;%d;%d,outputMode:%d\n",inputSrcInfo.type, inputSrcInfo.attr, inputSrcInfo.resourceIndex, outputMode);

							if(i2rnd_test_done == 1){
								i2rnd_test_done = 0;
								i2rnd_send_table_idx(I2RND_TABLE_OFF);
								rtk_hal_vsc_i2rnd_enable(_DISABLE);
								//frank@I2run disable main VENC flag
								VencModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
								DbgSclrFlgTkr.OutputVencMode = FALSE;
								vsc_i2rnd_sub_stage = I2RND_STAGE_DISABLE;
								vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_DISABLE;
								apvr_request_run_main_path();
								printk(KERN_EMERG"[%s][frank]I2RND close\n", __FUNCTION__);
							}
#endif
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
							{
								down(get_hdmi_detectsemaphore());
								if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
								up(get_hdmi_detectsemaphore());
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
							{
								down(get_adc_detectsemaphore());
								fw_scaler_adc_nolock_wdg_ctrl(SLR_SUB_DISPLAY, FALSE);// Disable adc_nolock_wdg
								if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
									YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
									ADC_set_detect_flag(TRUE);
								}
								up(get_adc_detectsemaphore());
								set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
							}
							else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
								plane=get_vo_plane_flag(SLR_SUB_DISPLAY);
							}
							smooth_toggle_disconnect(SLR_SUB_DISPLAY,plane);
							Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							state_update_disp_info();
						}

						DbgSclrFlgTkr.Sub_OutputVencMode = FALSE;
						Sub_VencModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
						*p_sourceID = _UNKNOWN_INPUT;
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;venc mode close fail\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_DISPLAY_MODE);
					} else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_MEMORY_MODE);
					} else if(DbgSclrFlgTkr.OutputAveMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_AVE_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, " error venc mode not open\n");
						return TRUE;
					}
				}
				break;
			}
			case VSC_OUTPUT_MEMORY_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OutputMemoryMode == TRUE)
				{
					if((Sub_MemoryModeInputInfo.type == inputSrcInfo.type) && (Sub_MemoryModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						if(DbgSclrFlgTkr.Sub_OuputDisplayMode == FALSE)
						{
							down(&SetSubOutPutRegion_Semaphore);
							DbgSclrFlgTkr.Sub_Scaler_Stop_flag = TRUE;
							zoom_clear_input_output_region_record(wid);
							Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);
							up(&SetSubOutPutRegion_Semaphore);

							if (((inputSrcInfo.type == VSC_INPUTSRC_AVD) ||(inputSrcInfo.type == VSC_INPUTSRC_HDMI) ||(inputSrcInfo.type == VSC_INPUTSRC_VDEC)) && (Get_Live_zoom_mode() == LIVE_ZOOM_SUB )) {
								Set_Live_zoom_mode(LIVE_ZOOM_OFF);
								//DataFramesynclivezoom = FALSE;
								DbgSclrFlgTkr.LivezoomMainRerunFlag = FALSE;
								DbgSclrFlgTkr.LivezoomSubRerunFlag = FALSE;
								DbgSclrFlgTkr.LivezoomvoinfocheckFlag = FALSE;
								DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
								Set_LivezoomOffMainForceBG(TRUE);
								drvif_memory_compression_rpc();
							} else {
								drvif_mode_disableonlinemeasure(_CHANNEL2);//Diable online measure
								drvif_mode_onlinemeasure_setting(_CHANNEL2,Scaler_InputSrcGetType(SLR_SUB_DISPLAY), FALSE, FALSE);
								//set detect timng flag true:
								if(inputSrcInfo.type == VSC_INPUTSRC_AVD)
								{
									/*//no need because AVD don't stop detect task
									down(get_vdc_detectsemaphore());
									if(get_AVD_Global_Status() == SRC_CONNECT_DONE) VDC_set_detect_flag(TRUE);
									up(get_vdc_detectsemaphore());
									*/
								}
								else if(inputSrcInfo.type == VSC_INPUTSRC_HDMI)
								{
									down(get_hdmi_detectsemaphore());
									if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
									up(get_hdmi_detectsemaphore());
								}
								else if(inputSrcInfo.type == VSC_INPUTSRC_ADC)
								{
									down(get_adc_detectsemaphore());
									fw_scaler_adc_nolock_wdg_ctrl(SLR_SUB_DISPLAY, FALSE);// Disable adc_nolock_wdg
									if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
										YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
										ADC_set_detect_flag(TRUE);
									}
									up(get_adc_detectsemaphore());
									set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag
								} else if(inputSrcInfo.type == VSC_INPUTSRC_VDEC || inputSrcInfo.type == VSC_INPUTSRC_JPEG) {
									down(get_vo_infosemaphore());
									DbgSclrFlgTkr.Sub_OutputMemoryMode = FALSE;
									plane=get_vo_plane_flag(SLR_SUB_DISPLAY);
									Sub_MemoryModeInputInfo =(VSC_INPUT_SRC_INFO_T) {VSC_INPUTSRC_MAXN, 0, 0};
									set_vo_change_flag(inputSrcInfo.resourceIndex, FALSE);//Reset Vo change flag
									set_force_change_vo_flag(inputSrcInfo.resourceIndex, TRUE);
									set_daptive_stream_vo_update_flag(inputSrcInfo.resourceIndex, FALSE);
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Set force_change_vo_flag TRUE and reset vo change flag####\r\n");
									up(get_vo_infosemaphore());
								//	vo_overscan_disable(inputSrcInfo.type);
									reset_adaptive_streaming_info(SLR_SUB_DISPLAY);//reset adaptive stream info
									if (inputSrcInfo.type == VSC_INPUTSRC_VDEC)
										Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_VDEC, (wid<<4) + inputSrcInfo.resourceIndex);
									else
										Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_JPEG, (wid<<4) + inputSrcInfo.resourceIndex);
								}
								Scaler_ClearVOInfo(Get_DisplayMode_Port(wid));
							}
							smooth_toggle_disconnect(SLR_SUB_DISPLAY,plane);
							Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							state_update_disp_info();
						}

						DbgSclrFlgTkr.sub_wind0000 = FALSE;
						Scaler_SubDispWindowSet(SrcRect);

						DbgSclrFlgTkr.Sub_OutputMemoryMode = FALSE;
						Sub_MemoryModeInputInfo = (VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
						*p_sourceID = _UNKNOWN_INPUT;

						close_livezoom_doublebuffer();
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;memory mode close fail\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_DISPLAY_MODE);
					} else if(DbgSclrFlgTkr.OutputVencMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_VENC_MODE);
					} else if(DbgSclrFlgTkr.OutputAveMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_AVE_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "error memory mode not open\n");
						return TRUE;
					}
				}
				DbgSclrFlgTkr.Sub_AutoRunScaler = FALSE;
				down(&SetSubOutPutRegion_Semaphore);
				reset_any_srcrect(&sub_dispwin_pre);
				up(&SetSubOutPutRegion_Semaphore);
				break;
			}
			case VSC_OUTPUT_AVE_MODE:
			{
				if(DbgSclrFlgTkr.Sub_OutputAveMode == TRUE)
				{
					if((Sub_AveModeInputInfo.type == inputSrcInfo.type) && (Sub_AveModeInputInfo.resourceIndex == inputSrcInfo.resourceIndex))
					{
						HAL_VBE_AVE_Disconnect();
						DbgSclrFlgTkr.Sub_OutputAveMode = FALSE;
						Sub_AveModeInputInfo =	(VSC_INPUT_SRC_INFO_T){VSC_INPUTSRC_MAXN, 0, 0};
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "inputSrcInfo not match;ave mode not open\n");
						return TRUE;
					}
				}
				else
				{
					if(DbgSclrFlgTkr.OuputDisplayMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_DISPLAY_MODE);
					} else if(DbgSclrFlgTkr.OutputVencMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_VENC_MODE);
					} else if(DbgSclrFlgTkr.OutputMemoryMode == TRUE) {
						vsc_force_disconnect(wid, inputSrcInfo, VSC_OUTPUT_MEMORY_MODE);
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "error ave mode not open\n");
						return TRUE;
					}
				}
				break;
			}
			default:
				break;
		}
	}
#endif
	return TRUE;
}

unsigned char check_zoom_smooth_toggle_proc(void)
{//added by rika 20140904
	//int failflag=ZOOM_STATE_OK;
	//unsigned char resetflag=_DISABLE;
	return ZOOM_STATE_OK;//temp return by will.
#if 0
	if(zoom_smooth_toggle_get_finish() == ZOOM_STATE_NONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "_rk %s none\n",__FUNCTION__);
		///Scaler_DispSetInputInfo(SLR_INPUT_STATE,_MODE_STATE_ACTIVE);//For check timing
	}
	else if(zoom_smooth_toggle_get_finish() == ZOOM_STATE_WAIT_APPLY_OK){
		//zoom_smooth_toggle_set_finish(ZOOM_STATE_DONOW);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "_rk wait ok here\n-----\n");
		resetflag=_ENABLE;//reset size anyway  rika 20141112
		failflag=zoom_imd_smooth_toggle_proc(_ENABLE, _ENABLE, Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));//need review rika 20141224

		if(failflag==ZOOM_STATE_OK){
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "_rk %s wait ok done. send active2 \n", __FUNCTION__);
			///Scaler_DispSetInputInfo(SLR_INPUT_STATE,_MODE_STATE_ACTIVE);//For check timing

		}
		//else fail
		// do not set active
	}
	return failflag;
#endif
}


#define AVD_480i_MAX_LENGTH 504   // WebOS adjust v_size max size (2*v_start + v_length)
unsigned char CheckAVDandWebOSInfo(unsigned char display)
{
	unsigned char ucRet = TRUE;

	// The current signal color std is supported, check the M-domain size and InputRegion
	if( (Scaler_AVD_GetDetectStage() == VDC_DETECT_STAGE_FINAL)
		&& (get_AVD_Input_Source() == _SRC_TV)
		&& (0 == Scaler_AVD_IsSupportedColorSys()))  // 0: supported, -1: non-supported
	{
		unsigned short usAfterDILen = 0;
		unsigned short usInputRegion_h = 0, usInputRegion_y = 0;
		SLR_VOINFO *pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"DbgSclrFlgTkr.Main_Output_Set_flag=%x, DbgSclrFlgTkr.Main_Scaler_Stop_flag=%x, DbgSclrFlgTkr.Main_Run_Scaler_flag=%x\n", DbgSclrFlgTkr.Main_Output_Set_flag, DbgSclrFlgTkr.Main_Scaler_Stop_flag, DbgSclrFlgTkr.Main_Run_Scaler_flag);

#ifdef CONFIG_ALL_SOURCE_DATA_FS
		if ((Scaler_InputSrcGetType(display) == _SRC_VO) && (pVOInfo != NULL)) {
			if (display == SLR_MAIN_DISPLAY && Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
				usAfterDILen =	(pVOInfo->src_v_len << 1);
			} else {
				usAfterDILen = pVOInfo->src_v_len;
			}
		} else
#endif
		{
			if (display == SLR_MAIN_DISPLAY && Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
				usAfterDILen =	(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN) << 1);
			} else {
				usAfterDILen = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN);
			}
		}
		if(display == SLR_MAIN_DISPLAY)
		{
			usInputRegion_h = Main_InputRegion_h;
			usInputRegion_y = Main_InputRegion_y;
		}
		else
		{
			usInputRegion_h = Sub_InputRegion_h / 2;  // 480=>240, 576=>288 (InputRegion_h is full size)
			usInputRegion_y = Sub_InputRegion_y / 2;
		}
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"usInputRegion=%d,  usAfterDILen=%d\n", usInputRegion_h , usAfterDILen);
		if ((usInputRegion_h > usAfterDILen)
			|| ((usInputRegion_y*2 + usInputRegion_h) <= AVD_480i_MAX_LENGTH && usAfterDILen > 500)  //Throw DI (Current signal is 576i, but inputRegion is 480i)
			|| ((usInputRegion_y*2 + usInputRegion_h) <= (AVD_480i_MAX_LENGTH/2) && usAfterDILen > 250) ) // ByPass DI
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC," m-domain size wrong, return false\n");

			ucRet = FALSE;
		}
	}

	return ucRet;
}

void wait_DI_auto_freeze(void)
{
	if(((rtd_inl(VODMA_VODMA_V1_DCFG_reg) &VODMA_VODMA_V1_DCFG_vodma_go_mask)==0)
			&&((rtd_inl(VODMA_VODMA_V1INT_reg) &VODMA_VODMA_V1INT_vgip_en_mask) == 0))
		{

			int timeout = 50;
			while(((rtd_inl(DI_IM_DI_DEBUG_MODE_reg)&_BIT8)>>8==0)&&timeout--){
				pr_emerg("wait DI freeze\n");
				mdelay(1);
			}
			if(timeout == 0)
				pr_emerg("wait_DI_auto_freeze timeout\n");

		}
}

void reset_rotate_mode(void)
{
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		if (TRUE == Get_rotate_function())
		{
			extern unsigned int rotatedisconnecten;
			extern void scaler_mdom_stop(void);
			rotatedisconnecten = 1;
			scaler_Rotate_VI_init_send_rpc();
			rotatedisconnecten = 0;
			if(get_rotate_mode()!=get_ori_rotate_mode())
				wait_DI_auto_freeze();
			scaler_mdom_stop();
			Set_rotate_function(FALSE);

		}

#endif
}


unsigned char rtk_run_scaler(unsigned char display, VSC_INPUT_TYPE_T inputType, VSC_OUTPUT_MODE_T outputMode)
{
	StructDisplayInfo  *p_timing = NULL;
	StructSrcRect winSrcRect = {0, 0, 0, 0};
#ifdef CONFIG_RTK_KDRV_PWM
	extern void HAL_VBE_DISP_GetOutputFrameRate(UINT8* pframeRates);
	UINT8 frameRates;
#endif
	unsigned char wait_to_after_avsync_do = 0;
	unsigned char new_voinfo_flag = 0;// to check vo overscan or not
	unsigned char port = Get_DisplayMode_Port(SLR_MAIN_DISPLAY);
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if((inputType == VSC_INPUTSRC_HDMI) || (inputType == VSC_INPUTSRC_ADC) || (inputType == VSC_INPUTSRC_AVD)) {
		port = 0;
	}
#endif
	if(vsc_debug_mode)
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s start line:%d####\r\n", __FUNCTION__, __LINE__);

	switch(outputMode)
	{
		case VSC_OUTPUT_DISPLAY_MODE:
		case VSC_OUTPUT_MEMORY_MODE:
		{
#if(VSC_PROFILE == 1)
			unsigned int before_time = 0;
			unsigned int after_time = 0;
			before_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
#endif
#ifdef CONFIG_FORCE_RUN_I3DDMA
			if ((DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == FALSE)
				&&((get_force_i3ddma_enable(display) == false) /*|| (DbgSclrFlgTkr.RGB444Mode_change && (inputType == VSC_INPUTSRC_HDMI) && (DbgSclrFlgTkr.game_mode_dynamic_flag == 0))*/)
				&&(Get_Live_zoom_mode() == LIVE_ZOOM_OFF)
				&&(!(Get_LivezoomOffMainForceBG() == TRUE && Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) <= 3000))
				&&((get_rotate_mode()==get_ori_rotate_mode())|| (get_ori_rotate_mode()==DIRECT_VO_FRAME_ORIENTATION_DEFAULT)))
#else
			if ((DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == FALSE)
				&&(Get_Live_zoom_mode() == LIVE_ZOOM_OFF)
				&&(!(Get_LivezoomOffMainForceBG() == TRUE && Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) <= 3000))
				&&((get_rotate_mode()==get_ori_rotate_mode())|| (get_ori_rotate_mode()==DIRECT_VO_FRAME_ORIENTATION_DEFAULT))
#endif

			{
				drvif_mode_resetmode(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
			} else {
				 if(DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom == TRUE || (Get_LivezoomOffMainForceBG() == TRUE && Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) <= 3000)) {
					/*livezoom no need do reset_rotate_mode*/
				} else if((get_rotate_mode()!=get_ori_rotate_mode()) && (get_ori_rotate_mode()!=DIRECT_VO_FRAME_ORIENTATION_DEFAULT)) {
					reset_rotate_mode();
				}
				if (display == SLR_MAIN_DISPLAY) {
					//disable data path s1 clock for snr hw bug
				       vgip_data_path_select_RBUS data_path_select_reg;
				       data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
				       data_path_select_reg.s1_clk_en = 0;
				       IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
				}
			}
			if (DbgSclrFlgTkr.RGB444Mode_change) {
				DbgSclrFlgTkr.RGB444Mode_change = 0;
			}
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
			down(&SetMainOutPutRegion_Semaphore);
			if((display == SLR_MAIN_DISPLAY)
				&&(get_rotate_mode() >=DIRECT_VO_FRAME_ORIENTATION_ROTATE_90)
				&&(get_rotate_mode() <=DIRECT_VO_FRAME_ORIENTATION_FLIP_ROTATE_270))
			{
				Set_rotate_function(TRUE);
			} else {
				Set_rotate_function(FALSE);
			}
			//set_ori_rotate_mode(get_rotate_mode());
			up(&SetMainOutPutRegion_Semaphore);
#endif
			if(get_displayinfo_proc(display, inputType) == FALSE)
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "######get_displayinfo_proc fail fail fail!!!#######\n");
				if (display == SLR_MAIN_DISPLAY) {
					down(&SetMainOutPutRegion_Semaphore);
					reset_any_srcrect(&main_dispwin_pre);
					up(&SetMainOutPutRegion_Semaphore);
				} else {
					down(&SetSubOutPutRegion_Semaphore);
					reset_any_srcrect(&sub_dispwin_pre);
					up(&SetSubOutPutRegion_Semaphore);
				}
				if(inputType == VSC_INPUTSRC_ADC)
				{//Need to rerun scaler
					down(get_adc_detectsemaphore());
					vga_good_timing_ready = FALSE;
					p_timing = Get_ADC_Dispinfo();
					p_timing->IPH_ACT_WID_PRE = 0;
					p_timing->IPV_ACT_LEN_PRE = 0;
					p_timing->IVFreq = 0;
					p_timing->IHFreq = 0;
					p_timing->IHTotal = 0;
					p_timing->IVTotal = 0;
					p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
					if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
						ADC_OnlineMeasureError_Handler(get_ADC_Input_Source());
						Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_ADC, TRUE);/*Let Webos get zero timing*/
						//YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
						ADC_set_detect_flag(TRUE);
					}
					up(get_adc_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_HDMI)
				{//Need to rerun scaler
					vfe_hdmi_drv_handle_on_line_measure_error(0);
					vfe_hdmi_drv_adapter();
					down(get_hdmi_detectsemaphore());
					if (get_HDMI_Global_Status() == SRC_CONNECT_DONE) {
						Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_HDMI, TRUE);/*Let Webos get zero timing*/
						HDMI_set_detect_flag(TRUE);
					}
					up(get_hdmi_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_AVD)
				{//Need to rerun scaler
					/*//no need because AVD don't stop detect task
					down(get_vdc_detectsemaphore());
					if (get_AVD_Global_Status() == SRC_CONNECT_DONE) {
						VDC_set_detect_flag(TRUE);
					}
					up(get_vdc_detectsemaphore());
					*/
					Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_AVD, TRUE);/*Let Webos get zero timing*/
				}
				if (display == SLR_MAIN_DISPLAY) {
					drivf_scaler_reset_freerun();
					if(DbgSclrFlgTkr.Main_AutoRunScaler) {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######Need to run scale again#######\n");
						DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
					}
				} else {
					if(DbgSclrFlgTkr.Sub_AutoRunScaler) {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######Need to run scale again#######\n");
						DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
					}
				}
				return FALSE;
			}
			else
			{
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "######get_displayinfo_proc success!!!#######\n");
			}
			if(Setup_IMD(Scaler_DispGetInfoPtr()) == FALSE)
			{
				Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();//Update the search state
				if (display == SLR_MAIN_DISPLAY) {
					down(&SetMainOutPutRegion_Semaphore);
					reset_any_srcrect(&main_dispwin_pre);
					up(&SetMainOutPutRegion_Semaphore);
				} else {
					down(&SetSubOutPutRegion_Semaphore);
					reset_any_srcrect(&sub_dispwin_pre);
					up(&SetSubOutPutRegion_Semaphore);
				}
				if(inputType == VSC_INPUTSRC_ADC)
				{
					if (display == SLR_MAIN_DISPLAY) {
						Reset_YPP_Auto_Phase_SmartFit_Setting();//Reset auto phase related setting
					}
					down(get_adc_detectsemaphore());
					vga_good_timing_ready = FALSE;
					p_timing = Get_ADC_Dispinfo();
					p_timing->IPH_ACT_WID_PRE = 0;
					p_timing->IPV_ACT_LEN_PRE = 0;
					p_timing->IVFreq = 0;
					p_timing->IHFreq = 0;
					p_timing->IHTotal = 0;
					p_timing->IVTotal = 0;
					p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
					if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
						ADC_OnlineMeasureError_Handler(get_ADC_Input_Source());
						Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_ADC, TRUE);/*Let Webos get zero timing*/
						//YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
						ADC_set_detect_flag(TRUE);
					}
					up(get_adc_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_HDMI)
				{
				
					vfe_hdmi_drv_handle_on_line_measure_error(0);
					vfe_hdmi_drv_adapter();
					down(get_hdmi_detectsemaphore());
					if (get_HDMI_Global_Status() == SRC_CONNECT_DONE) {
						Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_HDMI, TRUE);/*Let Webos get zero timing*/
						HDMI_set_detect_flag(TRUE);
					}
					up(get_hdmi_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_AVD)
				{
					/*//no need because AVD don't stop detect task
					down(get_vdc_detectsemaphore());
					if (get_AVD_Global_Status() == SRC_CONNECT_DONE) {

						VDC_set_detect_flag(TRUE);
					}
					up(get_vdc_detectsemaphore());
					*/
					Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_AVD, TRUE);/*Let Webos get zero timing*/
				} else if(inputType == VSC_INPUTSRC_JPEG || inputType == VSC_INPUTSRC_VDEC){
					 //[WOSQRTK-7490]update to add Dolby OTT condition @Crixus 20160414
					if((get_vo_open_smooth_toggle_enable(display) || DbgSclrFlgTkr.adaptive_stream || (get_OTT_HDR_mode() == HDR_DOLBY_COMPOSER)) && (display == SLR_MAIN_DISPLAY)) {//direct vo and VO change
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "######run scale again vo change for direct vo#######\n");
						DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
					}
					if (display == SLR_MAIN_DISPLAY)
						DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset DbgSclrFlgTkr.Main_during_scalerflow_flag
				}
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "######Channel:%d src:%d Setup_IMD fail!!!#######\n", display, inputType);
				if (display == SLR_MAIN_DISPLAY) {
					drivf_scaler_reset_freerun();
					if(DbgSclrFlgTkr.Main_AutoRunScaler) {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######Need to run scale again#######\n");
						DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
					}
				} else {
					if(DbgSclrFlgTkr.Sub_AutoRunScaler) {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######Need to run scale again#######\n");
						DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
					}
				}
				return FALSE;
			}
			else
			{
				if(display == SLR_MAIN_DISPLAY)
				{
					/*K3LG-1445:sync crixus,willlin,qiangzhou,when gamemode re run scaler,no need change SLR_FORCE_BG_TYPE_SIG_UNSTABLE*/
					if((DbgSclrFlgTkr.game_mode_dynamic_flag == FALSE))
					{
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, FALSE);//disable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_GameMode, FALSE);//WOSQRTK-10467 , clear game mode mask when change to non-game mode status before disable force_bg
					}
				}
				else
				{
					set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, FALSE);//disable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
				}

				if(display == SLR_MAIN_DISPLAY){
					Share_Memory_Set_Scaler_Run_Flag(0);
					if(inputType == VSC_INPUTSRC_AVD){
						//printk(KERN_EMERG"[%s][%d]\n", __FUNCTION__, __LINE__);
						zoom_clear_input_output_region_record(display);
					}
				}

				if(vsc_debug_mode)
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "######Channel:%d src:%d Setup_IMD success!!!#######\n", display, inputType);
				imd_smooth_toggle_check_pre_double_buffer(display);

				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######Channel:%d src:%d Setup_IMD success!!!#######\n", display, inputType);
				//Need to check MEMC output BG again for first booting
				if(Scaler_MEMC_Get_First_Run_FBG_enable() || Scaler_MEMC_Get_instanboot_resume_Done() || Scaler_MEMC_Get_snashop_resume_Done()){
					Scaler_MEMC_Set_CheckMEMC_Outbg(TRUE);
				}
				//state_update_disp_info();//Update the active state
				if (display == SLR_MAIN_DISPLAY) {
					down(&SetMainOutPutRegion_Semaphore);
					reset_any_srcrect(&main_dispwin_pre);
					up(&SetMainOutPutRegion_Semaphore);
				} else {
					down(&SetSubOutPutRegion_Semaphore);
					reset_any_srcrect(&sub_dispwin_pre);
					up(&SetSubOutPutRegion_Semaphore);
				}
				if (Scaler_InputSrcGetType(display) != _SRC_VO)
				{
					if((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY)){
						/*qiangzhou added livezoom and magnifier case sub forbidden open wtd and interrupt and onlinemeasure*/
						drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), FALSE, FALSE);
					} else {
						if (Scaler_InputSrcGetType(display) == _SRC_TV)//ATV no need online interrupt
							drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), TRUE, FALSE);
						else
							drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), TRUE, TRUE);
					}

					if (Scaler_InputSrcGetType(display) == _SRC_YPBPR || Scaler_InputSrcGetType(display) == _SRC_VGA) {
						if(YPbPr_Small_Signal_precheck() == FALSE)
							fw_scaler_adc_nolock_wdg_ctrl(display, TRUE);
					}
				}
				else
				{
#ifdef CONFIG_FORCE_RUN_I3DDMA
					if(display == SLR_MAIN_DISPLAY)
					{
						if(inputType == VSC_INPUTSRC_ADC)
							drvif_mode_dma_onlinemeasure_setting( TRUE, TRUE);//ADC CASE
						else if((inputType == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() != _SRC_TV))
							drvif_mode_dma_onlinemeasure_setting( TRUE, TRUE);//AV CASE
						else if(inputType == VSC_INPUTSRC_HDMI)
							drvif_mode_dma_onlinemeasure_setting( TRUE, TRUE);//HDMI CASE
					}
#endif
					enable_vodma_empty_gate(Scaler_Get_CurVoInfo_VoVideoPlane(display));//Enable vo gating
					//Scaler_SendDisplayReadyIrc(Scaler_Get_CurVoInfo_VoVideoPlane(display));/*Send display ready to video FW*/
				}

				if(inputType == VSC_INPUTSRC_AVD) //Let AVD detect enable
				{
					/*//no need because AVD don't stop detect task
					//down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
						VDC_set_detect_flag(TRUE);
					//up(get_vdc_detectsemaphore());
					*/
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtk_run_scaler Scaler_AVD_SetRunSearchState(false)\n");
					Scaler_AVD_SetRunSearchState(display, false);
				}
#ifdef CONFIG_RTK_KDRV_PWM
				if (display == SLR_MAIN_DISPLAY) {
					/*
					frameRates = Scaler_DispGetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ);
					//rtk_pwm_set_freq(0, frameRates, 2);
					rtk_pwm_set_scaler_source(frameRates, 2);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "########Set PWM framerate:%d##########\r\n", frameRates);
					*/
					vbe_disp_pwm_frequency_update(TRUE);
				}
#endif
				if(display == SLR_MAIN_DISPLAY) {
					if((DbgSclrFlgTkr.Main_Output_Set_flag ||(DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag)) && (DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
					{
						if (Scaler_InputSrcGetType(display) == _SRC_VO && DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting)	{
							//This is for smooth togggle presetting
							//state_update_disp_info();//Update the active state
							DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = FALSE;
							if (!Get_vo_smoothtoggle_timingchange_flag(display)) {
							#ifdef CONFIG_I2RND_ENABLE
								if (!((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_I2RND_DONE)))
							#endif
								{
									//pr_emerg("send smoothtoggle info to video line=%d\n",__LINE__);
									if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
										vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC, display);
									} else {
										vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC, display);
									}
									Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
									vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
									send_memory_mapping_for_adaptive_streaming();
#endif
									Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
									panel_parameter_send_info();
								}
							}
						}

						if((inputType == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
						{
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####atv new input ouput break function=%s, line=%d!!!####\r\n", __FUNCTION__, __LINE__);
							return FALSE;
						}

						down(&SetMainOutPutRegion_Semaphore);
						if(!compare_rerify_vsc_source_num_result(display))
						{
							up(&SetMainOutPutRegion_Semaphore);
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "### rtk_run_scaler main source already change line:%d###\r\n", __LINE__);
							return FALSE;
						}
						Scaler_DispWindowSet(main_dispwin);
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####scaler to run smooth toggle 1!!!####\r\n");

						if(inputType == VSC_INPUTSRC_AVD)
						{
							new_voinfo_flag = 1;
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

	#ifdef CONFIG_SDNR_CROP
						//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));
						zoom_imd_smooth_toggle_config(VIDEO_WID_0,Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY, main_input_size.srcx), main_input_size.srcy, Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY, main_input_size.src_wid),  main_input_size.src_height, ZOOM_CROP);
						zoom_imd_smooth_toggle_config(VIDEO_WID_0, main_dispwin.srcx, main_dispwin.srcy, main_dispwin.src_wid, main_dispwin.src_height, ZOOM_DISP);
						//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));


	#else //end of CONFIG_SDNR_CROP
							#if 0
							if(main_dispwin.src_wid < 960)
							{//WOSQRTK-6104 patch
								up(&SetMainOutPutRegion_Semaphore);
								Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
								state_update_disp_info();
								return FALSE;
							}
							#endif
							if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(SLR_MAIN_DISPLAY))
							{
								VIDEO_RECT_T inregion_avd;
								VIDEO_RECT_T outregion_avd;
								rtk_hal_vsc_GetOutputRegion(display, &outregion_avd);
								Scaler_CalWindowZoominForAVD(SLR_MAIN_DISPLAY, &inregion_avd, &outregion_avd);

								rtd_printk(KERN_INFO, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
								Scaler_DispWindowZoominForAVD(SLR_MAIN_DISPLAY, inregion_avd, outregion_avd, FALSE);
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
								//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
							}
							else
							{
								winSrcRect = Scaler_DispWindowGet();
								zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
							}

	#endif //end of CONFIG_SDNR_CROP...else...

#else
							zoom_imd_smooth_toggle_config(VIDEO_WID_0, main_dispwin.srcx, main_dispwin.srcy, main_dispwin.src_wid, main_dispwin.src_height, ZOOM_DISP);
#endif
						} else {
							if(Scaler_data_frc_fs_change_adjust_after_scaler(SLR_MAIN_DISPLAY,main_dispwin.src_height)) {
								if (inputType != VSC_INPUTSRC_VDEC) {
								#ifdef CONFIG_ALL_SOURCE_DATA_FS
									if ((drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC) && (Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC) == FALSE)
										&& (1==Scaler_get_data_framesync(display))){ //data frc change to data fs,display timing need change
										modestate_set_fll_running_flag(_DISABLE);
										drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
										Scaler_DispSetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC,TRUE);
										rtd_printk(KERN_INFO, TAG_NAME_VSC, "timing change to framesync -1-1-1 \n");
									}
								#endif
									zoom_imd_smooth_toggle_config(VIDEO_WID_0, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height, ZOOM_CROP);
									zoom_imd_smooth_toggle_config(VIDEO_WID_0, main_dispwin.srcx, main_dispwin.srcy, main_dispwin.src_wid, main_dispwin.src_height, ZOOM_DISP);
									new_voinfo_flag = 1;
								} else {
									wait_to_after_avsync_do = 1;
								}
							} else {
								up(&SetMainOutPutRegion_Semaphore);
								return FALSE;
							}
						}
						DbgSclrFlgTkr.Main_Output_Set_flag = FALSE;
						up(&SetMainOutPutRegion_Semaphore);
					}
					if((DbgSclrFlgTkr.Main_Run_Scaler_flag || DbgSclrFlgTkr.Main_smooth_toggle_set_flag || DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off)&& (DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
						if(Scaler_InputSrcGetType(display) == _SRC_VO ){
							if(get_vo_change_flag(Get_DisplayMode_Port(SLR_MAIN_DISPLAY)) == FALSE) {
								if (DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting) {
									//This is for smooth togggle presetting
									//state_update_disp_info();//Update the active state
									DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = FALSE;
									if (!Get_vo_smoothtoggle_timingchange_flag(display)) {
							#ifdef CONFIG_I2RND_ENABLE
									if (!((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_I2RND_DONE)))
							#endif
									{
										//pr_emerg("send smoothtoggle info to video line=%d\n",__LINE__);
										if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
											vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC, display);
										} else {
											vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC, display);
										}
										Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
										vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
										send_memory_mapping_for_adaptive_streaming();
#endif

										Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
										panel_parameter_send_info();
									}
									}
								}
							} else {
								Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
								state_update_disp_info();
								DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset DbgSclrFlgTkr.Main_during_scalerflow_flag
								return FALSE;
							}

						}

						if((inputType == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
						{
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####atv new input ouput break function=%s, line=%d!!!####\r\n", __FUNCTION__, __LINE__);
							return FALSE;
						}

						down(&SetMainOutPutRegion_Semaphore);
						if(!compare_rerify_vsc_source_num_result(display))
						{
							up(&SetMainOutPutRegion_Semaphore);
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "### rtk_run_scaler main source already change line:%d###\r\n", __LINE__);
							return FALSE;
						}
#if 0//def CONFIG_ENABLE_VD_27MHZ_MODE
						if(inputType == VSC_INPUTSRC_AVD) {
							if(main_dispwin.src_wid < 960)
							{
								//WOSQRTK-6104 patch
								up(&SetMainOutPutRegion_Semaphore);
								Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
								state_update_disp_info();
								return FALSE;
							}
						}
#endif
						Scaler_DispWindowSet(main_dispwin);
						DbgSclrFlgTkr.Main_Run_Scaler_flag = FALSE;


						if(inputType == VSC_INPUTSRC_AVD)
						{
							new_voinfo_flag = 1;
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

		#ifdef CONFIG_SDNR_CROP

							//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
							//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));
							winSrcRect = Scaler_DispWindowGet();
							zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY,Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY, main_input_size.srcx), main_input_size.srcy, Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY, main_input_size.src_wid),  main_input_size.src_height, ZOOM_CROP);
							zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
							//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
							//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));

		#else

							if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(SLR_MAIN_DISPLAY))
							{
								VIDEO_RECT_T inregion_avd;
								VIDEO_RECT_T outregion_avd;
								rtk_hal_vsc_GetOutputRegion(display, &outregion_avd);
								Scaler_CalWindowZoominForAVD(SLR_MAIN_DISPLAY, &inregion_avd, &outregion_avd);

								rtd_printk(KERN_INFO, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
								Scaler_DispWindowZoominForAVD(SLR_MAIN_DISPLAY, inregion_avd, outregion_avd, FALSE);
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
								//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
							}
							else
							{
								winSrcRect = Scaler_DispWindowGet();
								zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
							}
		#endif
#else
							winSrcRect = Scaler_DispWindowGet();
							zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
#endif
						} else {
							if (inputType != VSC_INPUTSRC_VDEC) {
								Check_smooth_toggle_update_flag(display);
								winSrcRect = Scaler_DispWindowGet();
								
					#ifdef CONFIG_ALL_SOURCE_DATA_FS
							if ((drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC) && (Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC) == FALSE)
								&& (1==Scaler_get_data_framesync(display))){ //data frc change to data fs,display timing need change
								modestate_set_fll_running_flag(_DISABLE);
								drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
								Scaler_DispSetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC,TRUE);
								rtd_printk(KERN_INFO, TAG_NAME_VSC, "timing change to framesync 000 \n");
							}
					#endif
								zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height, ZOOM_CROP);
								zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
								new_voinfo_flag = 1;
							} else {
								wait_to_after_avsync_do = 1;
							}
						}
						up(&SetMainOutPutRegion_Semaphore);
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####scaler to run smooth toggle 2!!!####\r\n");
					}else if (DbgSclrFlgTkr.rotate_run_scaler_flag && (DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)){
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "request just run rotate-scaler\n");
						return FALSE;
					}

					if(!vsc_get_adaptivestream_flag() && (inputType == VSC_INPUTSRC_VDEC) && (is_DTV_flag_get())
						&& (display == SLR_MAIN_DISPLAY)
						&& (!(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE) > 2000) || (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE) == 720))// 4k2k or 720p don't have ip change
						&& ((IoReg_Read32(VODMA_VODMA_V1_DCFG_reg) &VODMA_VODMA_V1_DCFG_vodma_go_mask) &&(IoReg_Read32(VODMA_VODMA_V1INT_reg) &VODMA_VODMA_V1INT_vgip_en_mask))// when vo FREEZE ,don't go this flow
						&& (!(IoReg_Read32(DI_IM_DI_DEBUG_MODE_reg) & DI_IM_DI_DEBUG_MODE_auto_freeze_mask))){// if di freeze ,can't run this flow ,cause this flow need apply di double buffer
						//	pr_emerg("run smooth toggle for DTV I/P exchange after scaler\n");
						//	run_smoothtoggle_for_ip_change(display);
					}
				}
#if 0//for sub smooth toggle test
				else
				{
					down(&SetSubOutPutRegion_Semaphore);
					//if(DbgSclrFlgTkr.Sub_Output_Set_flag == TRUE)
					{
						//Scaler_DispWindowSet(main_dispwin);
						Scaler_SubDispWindowSet(sub_dispwin);
						printk("\r\n####scaler to run sub smooth toggle!!!####\r\n");

						if (Scaler_InputSrcGetType(display) == _SRC_VO)	{
							if (!Get_vo_smoothtoggle_timingchange_flag(display)) {
									if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
										vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC,display);
									} else {
										vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC,display);
									}
									Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
									printk("######[pool test]send memory info to video#######\n");
									vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
									Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
									printk("######[pool test] send panel info to video#######\n");
									panel_parameter_send_info();
							}
						}
						//zoom_imd_smooth_toggle_config(VIDEO_WID_1, sub_dispwin.srcx, sub_dispwin.srcy, sub_dispwin.src_wid, sub_dispwin.src_height, ZOOM_DISP);
						DbgSclrFlgTkr.Sub_Output_Set_flag = FALSE;
					}
					up(&SetSubOutPutRegion_Semaphore);
				}
#endif
			}

#if(VSC_PROFILE == 1)
			after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\nVSC VSC_CONNECT time=%d ms\n",(after_time-before_time));
#endif

			if((inputType == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV) && (display == SLR_MAIN_DISPLAY))
			{//current smooth toggle is at video fw, so need alwasy to call smooth_toggle_preset_info
				if (DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting){
				//This is for smooth togggle presetting
					DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = FALSE;
					if (!Get_vo_smoothtoggle_timingchange_flag(display)) {
							#ifdef CONFIG_I2RND_ENABLE
							if (!((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_I2RND_DONE)))
							#endif
							{
								//pr_emerg("send smoothtoggle info to video line=%d\n",__LINE__);
								if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
									vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC, display);
								} else {
									vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC, display);
								}
								Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
								vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
						#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
								send_memory_mapping_for_adaptive_streaming();
						#endif
								Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
								panel_parameter_send_info();
							}
					}
				}
			}
			if (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
				//Avoid online interrupt occur
//				if(Scaler_InputSrcGetType(display) == _SRC_TV) {
				//if((Scaler_InputSrcGetType(display) == _SRC_TV)||(Scaler_InputSrcGetType(display) == _SRC_CVBS)) {

				if(inputType == VSC_INPUTSRC_AVD)
				{

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE


#ifdef CONFIG_SDNR_CROP

#else
					//if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
					if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(display))
					{
						VIDEO_RECT_T inregion_avd;
						VIDEO_RECT_T outregion_avd;
						rtk_hal_vsc_GetOutputRegion(display, &outregion_avd);
						Scaler_CalWindowZoominForAVD(display, &inregion_avd, &outregion_avd);

						rtd_printk(KERN_INFO, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						Scaler_DispWindowZoominForAVD(display, inregion_avd, outregion_avd,FALSE);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
						//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
					}
#endif

#endif


					if (FALSE == CheckAVDandWebOSInfo(display))
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "CheckAVDandWebOSInfo() fail\n");

						if (0xff == DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount)
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Set DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0\n");
							DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0;
						}

						DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount++;

						if(display == SLR_MAIN_DISPLAY)	{
							if(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE && DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount < CHECK_AVD_WEBOS_INFO_TIMEOUT){
								DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
								return FALSE;
							}
							else
							{
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount timeout\n");
								DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0xff;
							}
						} else {
							if(DbgSclrFlgTkr.Sub_Scaler_Stop_flag == FALSE && DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount < CHECK_AVD_WEBOS_INFO_TIMEOUT){
									DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;// Set output again, switch channel
									return FALSE;
							}
							else
							{
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount timeout\n");
								DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0xff;
							}
						}
					}
					else
					{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "CheckAVDandWebOSInfo ok, DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount=%d\n", DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount);
						DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0xff;
					}


					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Cur VD stage=%x, SetWinBlank VD stage=%x\n", Scaler_AVD_GetDetectStage(), DbgSclrFlgTkr.g_ucVDCDetectStage);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount=%d\n", DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount);

					//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "Cur VD stage=%x, SetWinBlank VD stage=%x\n", Scaler_AVD_GetDetectStage(), DbgSclrFlgTkr.g_ucVDCDetectStage);
					//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount=%d\n", DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount);

					// The timing info is changed from SetOutputRegion to SetWinBlank, therefore avoid to clear ForceBg
					if ((Scaler_AVD_GetDetectStage() == VDC_DETECT_STAGE_FINAL)
						&& (DbgSclrFlgTkr.g_ucVDCDetectStage != VDC_DETECT_STAGE_FINAL)
						&& (get_AVD_Input_Source() == _SRC_TV)
						&& DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount  == 1)
					{
						rtd_printk(KERN_INFO, TAG_NAME_VSC, "In ATV, The timing info is changed between SetWinBlank and Scaler unmute video, therefore avoid to clear ForceBg\n");

						if(display == SLR_MAIN_DISPLAY){
							if(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)
								DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
							return FALSE;
						} else {
							if(DbgSclrFlgTkr.Sub_Scaler_Stop_flag == FALSE)
								DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;// Set output again, switch channel
							return FALSE;
						}
					}

					if(wait_atv_stable_for_bg(display) == FALSE)
					{
						if((get_AVD_Input_Source() != _SRC_TV) || (display == SLR_SUB_DISPLAY)) {//For KTASKWBS-5200
							Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							state_update_disp_info();
						}
						if(display == SLR_MAIN_DISPLAY)	{
							if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Main_Output_Set_flag) {
								DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
								return FALSE;
							}
							if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)
								&&(get_AVD_Input_Source() == _SRC_TV)
								&&((vdc_LockStatus == 0)||(drvif_module_vdc_OutputStable()==FALSE)||(Scaler_AVD_GetDetectStage() != VDC_DETECT_STAGE_FINAL))
								&&(0 == drvif_video_status_reg(VDC_no_signal))){
								rtd_printk(KERN_INFO, TAG_NAME_VSC,"######[%s(line:%d)]fast zapping, flicker garbage.#####\n",__FUNCTION__, __LINE__);
								DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
								return FALSE;
							}
						} else {
							if((DbgSclrFlgTkr.Sub_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Sub_Output_Set_flag) {
								DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
								return FALSE;
							}
						}
					}

					if ((get_AVD_Input_Source() == _SRC_TV)
						&&(Scaler_AVD_GetVDPreMode() == _MODE_UNKNOWN)
						&&(1 == vdc_LockStatus)
						&&(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)){
						rtd_printk(KERN_INFO, TAG_NAME_VSC,"######[%s(line:%d)]fast zapping, flicker garbage.#####\n",__FUNCTION__, __LINE__);
						DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE; // Set output again, switch channel
						return FALSE;
					}
				}
				else if(inputType == VSC_INPUTSRC_VDEC)
				{
					int vo_timeout = 30;
					if(display == SLR_MAIN_DISPLAY) {
						while((get_vo_avsync_flag(port) == FALSE) && vo_timeout)
						{
							vo_timeout -- ;
							if(DbgSclrFlgTkr.Main_Scaler_Stop_flag || DbgSclrFlgTkr.Main_Run_Scaler_flag)
								break;
							if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
								break;
							msleep(1);

						}

						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n### main vo wait sync timeout:%d####\r\n", vo_timeout);
						if (wait_to_after_avsync_do) {
							wait_to_after_avsync_do = 0;
							down(&SetMainOutPutRegion_Semaphore);
							Scaler_DispWindowSet(main_dispwin);
							if(DbgSclrFlgTkr.Main_smooth_toggle_set_flag)
							{
									DbgSclrFlgTkr.Main_smooth_toggle_set_flag=FALSE;
									rtd_printk(KERN_INFO, TAG_NAME_VSC, "clear Main_smooth_toggle_set_flag\n");
							}
							if(DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off) {
								DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off=FALSE;
									rtd_printk(KERN_INFO, TAG_NAME_VSC, "clear Main_run_smooth_toggle_from_mute_off\n");
							}
							up(&SetMainOutPutRegion_Semaphore);
							winSrcRect = Scaler_DispWindowGet();
							Check_smooth_toggle_update_flag(display);
						#ifdef CONFIG_ALL_SOURCE_DATA_FS
							if ((drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC) && (Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC) == FALSE)
								&& (1==Scaler_get_data_framesync(display))){ //data frc change to data fs,display timing need change
								modestate_set_fll_running_flag(_DISABLE);
								drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
								Scaler_DispSetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC,TRUE);
								rtd_printk(KERN_INFO, TAG_NAME_VSC, "timing change to framesync 111 \n");
							}
							down(&SetMainOutPutRegion_Semaphore);
							unsigned int input_len_tmp = main_input_size.src_height;
							up(&SetMainOutPutRegion_Semaphore);

							down(get_vo_infosemaphore());
							unsigned int vo_len_tmp =  Scaler_VOInfoPointer(port)->v_length;
							up(get_vo_infosemaphore());
							if (Scaler_DispGetStatus(display,SLR_DISP_INTERLACE)) {
								vo_len_tmp = vo_len_tmp * 2;
							}
							
							if(Scaler_AdaptiveStream_NewInputRegionFlagGet(display)){
								/*apative input case ，need convert  input_len_tmp*/
								input_len_tmp = ((Scaler_VOInfoPointer(port)->progressive ? Scaler_VOInfoPointer(port)->src_v_len : 2*Scaler_VOInfoPointer(port)->src_v_len) *main_input_size.src_height * 100/_DISP_LEN + 50)/100;

							}

							if (input_len_tmp !=vo_len_tmp)
								zoom_clear_input_output_region_record(display); //clear size to run vo smooth toggle

						#endif
							zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height, ZOOM_CROP);
							zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
							Check_smooth_toggle_update_flag(display);
							new_voinfo_flag = 1;
						}
						if((DbgSclrFlgTkr.Main_smooth_toggle_set_flag) || (DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off))
						{
							new_voinfo_flag = 1;
							down(&SetMainOutPutRegion_Semaphore);
							Scaler_DispWindowSet(main_dispwin);
							DbgSclrFlgTkr.Main_smooth_toggle_set_flag=FALSE;
							DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off = FALSE;
							up(&SetMainOutPutRegion_Semaphore);
							winSrcRect = Scaler_DispWindowGet();
						#ifdef CONFIG_ALL_SOURCE_DATA_FS
							if ((drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC) && (Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC) == FALSE)
								&& (1==Scaler_get_data_framesync(display))){ //data frc change to data fs,display timing need change
								modestate_set_fll_running_flag(_DISABLE);
								drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
								Scaler_DispSetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC,TRUE);
								rtd_printk(KERN_INFO, TAG_NAME_VSC, "timing change to framesync 222 \n");
							}
							down(&SetMainOutPutRegion_Semaphore);
							unsigned int input_len_tmp = main_input_size.src_height;
							up(&SetMainOutPutRegion_Semaphore);

							down(get_vo_infosemaphore());
							unsigned int vo_len_tmp =  Scaler_VOInfoPointer(port)->v_length;
							up(get_vo_infosemaphore());
							if (Scaler_DispGetStatus(display,SLR_DISP_INTERLACE)) {
								vo_len_tmp = vo_len_tmp * 2;
							}
							
							if(Scaler_AdaptiveStream_NewInputRegionFlagGet(display)){
								/*apative input case ，need convert  input_len_tmp*/
								input_len_tmp = ((Scaler_VOInfoPointer(port)->progressive ? Scaler_VOInfoPointer(port)->src_v_len : 2*Scaler_VOInfoPointer(port)->src_v_len) *main_input_size.src_height * 100/_DISP_LEN + 50)/100;
							}

							if (input_len_tmp !=vo_len_tmp)
								zoom_clear_input_output_region_record(display);//clear size to run vo smooth toggle
						#endif
							if (!Get_vo_smoothtoggle_timingchange_flag(display)){
								if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
									vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC, display);
								} else {
									vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC, display);
								}
								Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
								vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
							#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
								send_memory_mapping_for_adaptive_streaming();
							#endif
								Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
								panel_parameter_send_info();
				 			}
							Check_smooth_toggle_update_flag(display);
							zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height, ZOOM_CROP);
							zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####scaler to run smooth toggle 3!!!####\r\n");
							Check_smooth_toggle_update_flag(display);
						}
						if(drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) == 0x0){
							printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN));
						 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC));
						 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD));
						 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1Addr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg));
						 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_2ndAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg));
						 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_3rdAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg));
						 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr1_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg));
						 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr2_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg));
						}
					}
#ifdef CONFIG_DUAL_CHANNEL
					else
					{
						while((get_vo_avsync_flag(port) == FALSE) && vo_timeout)
						{
							vo_timeout -- ;
							if(DbgSclrFlgTkr.Sub_Scaler_Stop_flag || DbgSclrFlgTkr.Sub_Run_Scaler_flag)
								break;
							if(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
								break;
							msleep(1);

						}

						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n### sub vo wait sync timeout:%d####\r\n", vo_timeout);
					}
#endif
				}
				else if(inputType == VSC_INPUTSRC_HDMI)
				{
					drvif_Hdmi_WatchDog_Apply(_ENABLE, HDMI_WD_VSC_COND);
				}
		#ifdef CONFIG_ALL_SOURCE_DATA_FS
				if((new_voinfo_flag == 0) && (display == SLR_MAIN_DISPLAY) && Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC) && (!DbgSclrFlgTkr.Main_smooth_toggle_set_flag) && (!DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag)) {
					down(&SetMainOutPutRegion_Semaphore);
					unsigned int input_wid_tmp = main_input_size.src_wid;
					unsigned int input_len_tmp = main_input_size.src_height;
					unsigned int input_x_tmp = main_input_size.srcx;
					Scaler_DispWindowSet(main_dispwin);
					up(&SetMainOutPutRegion_Semaphore);

					down(get_vo_infosemaphore());
					unsigned int vo_len_tmp =  Scaler_VOInfoPointer(port)->v_length;
					up(get_vo_infosemaphore());
					if (Scaler_DispGetStatus(display,SLR_DISP_INTERLACE)) {
						vo_len_tmp = vo_len_tmp * 2;
					}
					if (inputType== VSC_INPUTSRC_AVD) {
						input_wid_tmp = Scaler_CalAVD27MWidth(display,input_wid_tmp);
						input_x_tmp = Scaler_CalAVD27MWidth(display,input_x_tmp);
					}
					
					if(Scaler_AdaptiveStream_NewInputRegionFlagGet(display)){
						/*apative input case ，need convert  input_len_tmp*/
						input_len_tmp = ((Scaler_VOInfoPointer(port)->progressive ? Scaler_VOInfoPointer(port)->src_v_len : 2*Scaler_VOInfoPointer(port)->src_v_len) *main_input_size.src_height * 100/_DISP_LEN + 50)/100;
					}
					
					if (input_len_tmp !=vo_len_tmp) {
						rtd_printk(KERN_EMERG, TAG_NAME_VSC, "\r\n### before open bg, smoothtoggle will let vo do overscan####\r\n");
						Check_smooth_toggle_update_flag(display);
					 	if (!Get_vo_smoothtoggle_timingchange_flag(display)){
							if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
								vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC, display);
							} else {
								vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC, display);
							}
							Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
							vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
							send_memory_mapping_for_adaptive_streaming();
#endif
							Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
							panel_parameter_send_info();
				 		}

						winSrcRect = Scaler_DispWindowGet();
						zoom_clear_input_output_region_record(display);
						zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, input_x_tmp, main_input_size.srcy, input_wid_tmp, main_input_size.src_height, ZOOM_CROP);
						zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
						Check_smooth_toggle_update_flag(display);
					}
				}
		#endif
				if(display == SLR_SUB_DISPLAY){
				       if((DbgSclrFlgTkr.Sub_Output_Set_flag || DbgSclrFlgTkr.Sub_Run_Scaler_flag) && (DbgSclrFlgTkr.Sub_Scaler_Stop_flag == FALSE)){
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####(%d) got new output. need to run scaler again ####\n", __LINE__);
						Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
						state_update_disp_info();
						down(&SetSubOutPutRegion_Semaphore);
						DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
				        reset_any_srcrect(&sub_dispwin_pre);
				        up(&SetSubOutPutRegion_Semaphore);
						return FALSE;
					}
				}

				if((VSC_INPUTSRC_AVD == inputType) && (_SRC_TV == get_AVD_Input_Source()))
				{
					if(fwif_color_GetAutoMAFlag() == 0){
						fwif_color_SetAutoMAFlag(1);
					}

					// Ready to clear forceBG, finish channel change
					DbgSclrFlgTkr.g_ucVSCATVChanelChangeStart = FALSE;
					DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount = 0;
					//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Ready to Clear forceBG, set DbgSclrFlgTkr.g_ucVSCATVChanelChangeStart=0\n");
				}


#ifdef CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] src/st/ret=%d/%d/%d\n", Scaler_InputSrcGetType(display), Scaler_HDR10_Hdmi_Get_Detect_Status(), drvif_hdmi_is_drm_info_ready());
#endif
#if 0//def CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] src/st/ret=%d/%d/%d\n", Scaler_InputSrcGetType(display), Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status(), Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result());
				if((Scaler_InputSrcGetType(display) == _SRC_HDMI)
					&& (Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() != SLR_DV_HDMI_DETECT_OFF)
					&& Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result())
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] Skip disable BG...\n");
				}else if((Scaler_InputSrcGetType(display) == _SRC_VO)
					&& (Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_FOUND_CRC))
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] disable BG later...\n");
				}else
#endif
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
				if((Scaler_InputSrcGetType(display) == _SRC_HDMI)
					&& (Scaler_HDR10_Hdmi_Get_Detect_Status() != SLR_HDR10_HDMI_DETECT_OFF)
					&& drvif_hdmi_is_drm_info_ready())
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] Skip disable BG...\n");
				}else if((Scaler_InputSrcGetType(display) == _SRC_VO)
					&& (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_FOUND_MD))
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] disable BG later...\n");
				}else
#endif
				if(vsc_debug_mode)
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####start to disable display:%d force bg after scaler####\r\n", display);
				if (get_HDMI_HDR_mode() == HDR_DOLBY_HDMI && (inputType == VSC_INPUTSRC_HDMI)
					&& (display == SLR_MAIN_DISPLAY)) {
#ifdef CONFIG_RTK_KDRV_DV
					extern volatile unsigned int g_picModeUpdateFlag;
					unsigned char cnt = 50;
					while (g_picModeUpdateFlag && !DbgSclrFlgTkr.Main_Scaler_Stop_flag) {
						if (cnt == 0)
							break;
						cnt--;
						msleep(1);
					}
#endif
				}

				//Race condition isse for HDR HDMI aspect ratio faster changing @Crixus 20160412
				if((get_HDMI_HDR_mode() == HDR_HDR10_HDMI) && (inputType == VSC_INPUTSRC_HDMI)
					&& (DbgSclrFlgTkr.Main_Run_Scaler_flag == TRUE) && (DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)){
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "WebOS will run scaler again, do not disable FBG[%s]:%d\n", __FUNCTION__, __LINE__);
				}
				else{
					if(display == SLR_MAIN_DISPLAY) {
						DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset DbgSclrFlgTkr.Main_during_scalerflow_flag. Means webos can mute off directly
					}
#ifdef CONFIG_I2RND_ENABLE
					//if i2rnd and multivie case, do not disable fbg in sub scaler. @Crixus 20160728
					if((display == SLR_SUB_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DETECT_SOURCE)){
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);
						up(get_forcebg_semaphore());
						printk(KERN_EMERG"[I2RND]Do not disable fbg in sub scaler.\n");
					}else{
#endif
	                    if((display == SLR_MAIN_DISPLAY) && (inputType == VSC_INPUTSRC_HDMI))
						{
							if(get_ori_HDMI_HDR_mode() != get_HDMI_HDR_mode()) {
								state_update_disp_info();//current should be search state
								pr_notice("\r\n####hdmi hdr case change (%d->%d) before mute off!!!####\r\n",get_ori_HDMI_HDR_mode(), get_HDMI_HDR_mode());
								return TRUE;
							}
						}
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(display, FALSE);
						up(get_forcebg_semaphore());

#ifdef CONFIG_I2RND_ENABLE

					}
#endif
					Scaler_MEMC_fbg_control();

#if 1 //for first-timing adjust
					if((inputType == VSC_INPUTSRC_ADC) && (get_ADC_Input_Source() == _SRC_VGA) && (display == SLR_MAIN_DISPLAY)){

						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "#####[%s(%d)]check_vga_auto_calib_status=%d #####\n", __func__, __LINE__, check_vga_auto_calib_status());
						if(!check_vga_auto_calib_status())
						{
							down(get_adc_adjustsemaphore());
							Scaler_AdjustPCAuto(display);
							up(get_adc_adjustsemaphore());
						}
					}
#endif



				}

					if(drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) == 0x0){
						printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN));
					 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC));
					 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD));
					 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1Addr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg));
					 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_2ndAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg));
					 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_3rdAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg));
					 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr1_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg));
					 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr2_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg));
					}

				if(!drv_memory_get_game_mode_dynamic_flag())	//WOSQRTK-10203 already done in Scaler_disp_setting if game mode (patch for QA stage)
					Scaler_MEMC_SetInOutFrameRate();


#ifdef _PRINT_VSC_COST_TIME_AFTER_MUTE_OFF
				cost_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90 - cost_time;
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "\r\n####vsc cost time:%d ms after mute off####\r\n", cost_time);
#endif
				//state_update_disp_info();//Update the active state
				if(Scaler_InputSrcGetType(display) == _SRC_VO) {
					Scaler_SendDisplayReadyIrc(Scaler_Get_CurVoInfo_VoVideoPlane(display));/*Send display ready to video FW*/
				}
			}

			if (Scaler_InputSrcGetType(display) == _SRC_VO && DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting && (display == SLR_MAIN_DISPLAY)){
			//This is for smooth togggle presetting
				DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = FALSE;
				if (!Get_vo_smoothtoggle_timingchange_flag(display)) {
				#ifdef CONFIG_I2RND_ENABLE
					if (!((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_I2RND_DONE)))
				#endif
					{
					//pr_emerg("send smoothtoggle info to video line=%d\n",__LINE__);
					if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
						vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC,display);
					} else {
						vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC,display);
					}
					Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
					vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
					send_memory_mapping_for_adaptive_streaming();
#endif
					Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
					panel_parameter_send_info();
					}
				}
			}
			else if(Scaler_InputSrcGetType(display) == _SRC_VO && (display == SLR_SUB_DISPLAY))
			{
				if (!Get_vo_smoothtoggle_timingchange_flag(display)) {
					if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) {
						vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRAME_SYNC,display);
					} else {
						vo_force_data_mode_set_enable(SLR_DISPLAY_DATA_FRC,display);
					}
					Set_vo_smoothtoggle_changeratio_flag2(_ENABLE, display);
					vo_smoothtoggle_memory_alloc(display);//DTV need to allocate memory
					Set_vo_smoothtoggle_changeratio_flag2(_DISABLE, display);
					panel_parameter_send_info();
				}
			}

/////////////////////////////////////////
			break;
		}
		case VSC_OUTPUT_VENC_MODE:
		{

			if(Scaler_DispGetInputInfo(SLR_INPUT_FAILURECOUNT) == 0)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Go VencMode Src:%d!!!#####\r\n", VencModeInputInfo.type);
				Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n######set search state#####\r\n");
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######get_displayinfo_proc success!!!#######\n");
			}

#ifdef CONFIG_I2RND_ENABLE
 			if((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){//capture progressive video data

			}
			else{
				drvif_mode_resetmode(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
			}
#else
			drvif_mode_resetmode(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
#endif


			if(get_displayinfo_proc(display, inputType)== FALSE)
			{
				//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######get_displayinfo_proc fail fail fail!!!#######\n");
				return FALSE;
			}

			if(Setup_IMD(Scaler_DispGetInfoPtr())==FALSE)
			{
				if(inputType == VSC_INPUTSRC_ADC)
				{
					down(get_adc_detectsemaphore());
					vga_good_timing_ready = FALSE;
					p_timing = Get_ADC_Dispinfo();
					p_timing->IPH_ACT_WID_PRE = 0;
					p_timing->IPV_ACT_LEN_PRE = 0;
					p_timing->IVFreq = 0;
					p_timing->IHFreq = 0;
					p_timing->IHTotal = 0;
					p_timing->IVTotal = 0;
					p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
					if(get_ADC_Global_Status() == SRC_CONNECT_DONE) ADC_set_detect_flag(TRUE);
					up(get_adc_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_HDMI)
				{
					down(get_hdmi_detectsemaphore());
					if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
					up(get_hdmi_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_AVD)
				{
					/*//no need because AVD don't stop detect task
					//down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
						VDC_set_detect_flag(TRUE);
					//up(get_vdc_detectsemaphore());
					*/
				}
				printk(KERN_EMERG "######VSC_OUTPUT_VENC_MODE Setup_IMD fail fail!!!#######\n");
				return FALSE;
			}
			else
			{
#ifdef CONFIG_I2RND_ENABLE
				if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_I2RND_DONE)){
					printk(KERN_EMERG"apvr flow finish, so didnot re-run sub path\n");
					break;
				}
#endif
				printk(KERN_EMERG"######VSC_OUTPUT_VENC_MODE Channel:%d src:%d Setup_IMD success!!!#######\n", display, inputType);
				imd_smooth_toggle_check_pre_double_buffer(display);
				//state_update_disp_info();//Update the active state

				if(inputType == VSC_INPUTSRC_AVD) //Let AVD detect enable
				{
					/*//no need because AVD don't stop detect task
					//down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
						VDC_set_detect_flag(TRUE);
					//up(get_vdc_detectsemaphore());
					*/
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtk_run_scaler Scaler_AVD_SetRunSearchState(false)\n");
					Scaler_AVD_SetRunSearchState(display, false);
#ifdef CONFIG_I2RND_ENABLE
					//I2rnd sub=>vo RPC
					if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DETECT_SOURCE)){
						vsc_i2rnd_sub_stage = I2RND_STAGE_SUB_VO_RPC;
						printk(KERN_EMERG"[frank]APVR step 2@@@@@@@@I2RND_STAGE_SUB_VO_RPC\n");
						Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);
						i2rnd_send_table_idx(I2RND_SUB_S1_TABLE);
						drvif_scaler_i2rnd_vodma_setting(SLR_SUB_DISPLAY, inputType);
						drivf_Sub_I2rnd_SetupVODMA();
						//i2rnd_debug();
						printk(KERN_EMERG"[frank]@@@@@@@@@@@@I2RND_STAGE_SUB_VO_RPC OK!!!!!\n");
					}
#endif
				}

				if (Scaler_InputSrcGetType(display) != _SRC_VO)
				{
					if((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY)){
						/*qiangzhou added livezoom and magnifier case sub forbidden open wtd and interrupt and onlinemeasure*/
						drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), FALSE, FALSE);
					} else {
						if (Scaler_InputSrcGetType(display) == _SRC_TV)//ATV no need online interrupt
							drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), TRUE, FALSE);
						else
							drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), TRUE, TRUE);
					}
				}
			}
			break;
		}

#if 0 // Let VSC_OUTPUT_MEMORY_MODE be the same flow with VSC_OUTPUT_DISPLAY_MODE
		case VSC_OUTPUT_MEMORY_MODE:
		{

			if(Scaler_DispGetInputInfo(SLR_INPUT_FAILURECOUNT) == 0)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Go MemoryMode Src:%d!!!#####\r\n", MemoryModeInputInfo.type);
				Scaler_DispSetInputInfo(SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				state_update_disp_info();
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n######set search state#####\r\n");
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######get_displayinfo_proc success!!!#######\n");
			}

			drvif_mode_resetmode(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));


			if(get_displayinfo_proc(display, inputType) == FALSE)
			{
				//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######get_displayinfo_proc fail fail fail!!!#######\n");
				return FALSE;
			}

			if(Setup_IMD(Scaler_DispGetInfoPtr())==FALSE)
			{
				if(inputType == VSC_INPUTSRC_ADC)
				{
					down(get_adc_detectsemaphore());
					p_timing = Get_ADC_Dispinfo();
					p_timing->IPH_ACT_WID_PRE = 0;
					p_timing->IPV_ACT_LEN_PRE = 0;
					p_timing->IVFreq = 0;
					p_timing->IHFreq = 0;
					p_timing->IHTotal = 0;
					p_timing->IVTotal = 0;
					p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
					if(get_ADC_Global_Status() == SRC_CONNECT_DONE) ADC_set_detect_flag(TRUE);
					up(get_adc_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_HDMI)
				{
					down(get_hdmi_detectsemaphore());
					if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
					up(get_hdmi_detectsemaphore());
				}
				else if(inputType == VSC_INPUTSRC_AVD)
				{
					//down(get_vdc_detectsemaphore());
					if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
						VDC_set_detect_flag(TRUE);
					//up(get_vdc_detectsemaphore());
				}
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "######Setup_IMD fail fail fail!!!#######\n");
				return FALSE;
			}
			else
			{
				state_update_disp_info();//Update the active state
				if (Scaler_InputSrcGetType(display) != _SRC_VO)
				{
					if (Scaler_InputSrcGetType(display) == _SRC_TV)//ATV no need online interrupt
						drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), TRUE, FALSE);
					else
						drvif_mode_onlinemeasure_setting(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Scaler_InputSrcGetMainChType(), TRUE, TRUE);
				}
			}

			if (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
				//Avoid online interrupt occur
				down(get_forcebg_semaphore());
				scalerdisplay_force_bg_enable(display, FALSE);
				up(get_forcebg_semaphore());
			}
			break;
		}
#endif
		default:

			break;
	}

	return TRUE;
}

unsigned char rtk_check_signal(unsigned char display)
{/*This is for source check signal stable or not. Must be _MODE_STATE_ACTIVE*/
	unsigned char result;
	VSC_OUTPUT_MODE_T outputMode;
	VSC_INPUT_TYPE_T inputType = VSC_INPUTSRC_MAXN;
	unsigned char inputPort = 0;
	unsigned int inputVfreq = 0;
	unsigned int input_isInterlace = 0;
/*
	unsigned char frame_idicator=0;
	unsigned char b_run_frame_check=0;
	ppoverlay_dtg_frame_cnt1_RBUS dtg_frame_cnt1_reg;
	ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_reg;
	vgip_vgip_chn1_lc_RBUS vgip_chn1_lc_reg;
	unsigned int count2 = 0x3fffff;
	unsigned int ch1_line_cnt_lower = 0;
	unsigned int ch1_line_cnt_upper = 0;

	//check fix last line lock status @Crixus 20151219
	ppoverlay_fix_last_line_mode_lock_status_RBUS fix_last_line_mode_lock_status_reg;
//	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	extern unsigned char modestate_decide_display_timing(void);
	static UINT8 checkStableCnt=0;
*/
	unsigned char plane = 0;//get_vo_plane_flag(display);

#ifdef _VBY1_TO_HDMI_DIRTY_FIX
	static unsigned char bfirst_boot = 1;
#endif


	if (display == SLR_MAIN_DISPLAY) {
		if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_DISPLAY_MODE;
			inputType = DisplayModeInputInfo.type;
			inputPort = DisplayModeInputInfo.resourceIndex;
		}
		else if(VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_VENC_MODE;
			inputType = VencModeInputInfo.type;
			inputPort = VencModeInputInfo.resourceIndex;
		}
		else if(MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_MEMORY_MODE;
			inputType = MemoryModeInputInfo.type;
			inputPort = MemoryModeInputInfo.resourceIndex;
		}
		else
		{
			return false;
		}

#ifdef _VBY1_TO_HDMI_DIRTY_FIX
		if(bfirst_boot == 1){
			scaler_dtg_reconfig(); //vtotal set 0x8ca during boot up, recover to 0x8c9
			bfirst_boot	= 0;
		}
#endif
		//Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);//Remove by Will
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if (display == SLR_SUB_DISPLAY){
		if(Sub_DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_DISPLAY_MODE;
			inputType = Sub_DisplayModeInputInfo.type;
			inputPort = Sub_DisplayModeInputInfo.resourceIndex;
		}
		else if(Sub_VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_VENC_MODE;
			inputType = Sub_VencModeInputInfo.type;
			inputPort = Sub_VencModeInputInfo.resourceIndex;
		}
		else if(Sub_MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_MEMORY_MODE;
			inputType = Sub_MemoryModeInputInfo.type;
			inputPort = Sub_MemoryModeInputInfo.resourceIndex;
		}
		else
		{
			return false;
		}
		//Scaler_SetCurrentDispInfo(SLR_SUB_DISPLAY);//Remove by Will
	}
#endif

#ifdef CONFIG_I2RND_ENABLE
if((VSC_OUTPUT_VENC_MODE_FLAG == TRUE) && (Scaler_I2rnd_get_enable())){
	//Eric@0809
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "[OUTPUT_VENC_MODE] timing framesync!\n");
	modestate_set_fll_running_flag(_DISABLE);
	if(modestate_decide_display_timing() != DISPLAY_MODE_FRAME_SYNC){
		if(drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC){
			fwif_color_safe_od_enable(0);
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
			fwif_color_safe_od_enable(1);
		}
	}
	VSC_OUTPUT_VENC_MODE_FLAG = FALSE;
}
#endif

#if 0
	down(get_scaler_fll_running_semaphore());
	if((display == SLR_MAIN_DISPLAY) &&
		(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)){
		if(modestate_get_fll_running_flag()){
			if(checkStableCnt> 2){
				if((modestate_decide_display_timing() == DISPLAY_MODE_NEW_FLL_MODE) &&
					(drvif_scaler_get_display_mode() != DISPLAY_MODE_NEW_FLL_MODE)){
					down(&VSC_Semaphore);
					Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
					//add check frame cnt and add 1 frame delay @Crixus 20151221
					if((inputType == VSC_INPUTSRC_HDMI) && (DbgSclrFlgTkr.line_cnt_no_run_hdmi_check == 0)){
						//if HDMI source, not to run check mode until sync OK @Crixus 20151229
						DbgSclrFlgTkr.line_cnt_no_run_hdmi_check = 1;
					}
					if(Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_MULTIPLE_RATIO) > 1){
						b_run_frame_check = 1;
						frame_idicator = Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_MULTIPLE_RATIO)-1;
						switch (Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR)) {
							case _MODE_480I:
								ch1_line_cnt_lower = MODE_480I_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_480I_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_480P:
								ch1_line_cnt_lower = MODE_480P_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_480P_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_576I:
								ch1_line_cnt_lower = MODE_576I_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_576I_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_576P:
								ch1_line_cnt_lower = MODE_576P_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_576P_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_720P50:
								ch1_line_cnt_lower = MODE_720P50_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_720P50_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_720P60:
								ch1_line_cnt_lower = MODE_720P60_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_720P60_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_1080I25:// Mode 100: YPbPr 1920x1080ix50HZ (802R)
								ch1_line_cnt_lower = MODE_1080I50_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_1080I50_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_1080I30:// Mode 101: YPbPr 1920x1080ix60HZ (802R)
								ch1_line_cnt_lower = MODE_1080I60_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_1080I60_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_1080P50:
								ch1_line_cnt_lower = MODE_1080P50_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_1080P50_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_1080P60:
								ch1_line_cnt_lower = MODE_1080P60_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_1080P60_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_1080P23:
							case _MODE_1080P24:
							case _MODE_1080P25:
								ch1_line_cnt_lower = MODE_1080P24_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_1080P24_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_1080P29:
							case _MODE_1080P30:
								//[KTASK-3997]Modify 1080p30Hz line count setting for 60Hz panel @Crixus 20160527
								if((Get_DISPLAY_REFRESH_RATE() == 60) && (Get_DISPLAY_PANEL_CUSTOM_INDEX() == VBY_ONE_PANEL_LG_4K2K_600M_1S_8L)){
									ch1_line_cnt_lower = MODE_1080P30_FRAME_DELAY_LOWER_BOUNDARY_60HZ_PANEL;
									ch1_line_cnt_upper = MODE_1080P30_FRAME_DELAY_UPPER_BOUNDARY_60HZ_PANEL;
								}
								else{
									ch1_line_cnt_lower = MODE_1080P30_FRAME_DELAY_LOWER_BOUNDARY;
									ch1_line_cnt_upper = MODE_1080P30_FRAME_DELAY_UPPER_BOUNDARY;
								}
								break;
							case _MODE_4k2kP24:
								ch1_line_cnt_lower = MODE_4K2K24_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_4K2K24_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_4k2kP25:
								ch1_line_cnt_lower = MODE_4K2K24_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_4K2K24_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_4k2kP30:
								ch1_line_cnt_lower = MODE_4K2K30_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_4K2K30_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_4k2kP50:
								ch1_line_cnt_lower = MODE_4K2K50_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_4K2K50_FRAME_DELAY_UPPER_BOUNDARY;
								break;
							case _MODE_4k2kP60:
								ch1_line_cnt_lower = MODE_4K2K60_FRAME_DELAY_LOWER_BOUNDARY;
								ch1_line_cnt_upper = MODE_4K2K60_FRAME_DELAY_UPPER_BOUNDARY;
								break;

							default:
								ch1_line_cnt_lower = 0;
								ch1_line_cnt_upper = (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_LEN) * 1 / 4);
							break;
						}
						//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"\n SLR_INPUT_MODE_CURR = %d\n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
						//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"\n ch1_line_cnt_lower = %d, ch1_line_cnt_upper = %d\n", ch1_line_cnt_lower, ch1_line_cnt_upper);
					}
					if(b_run_frame_check == 1){
						dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
						if(dtg_frame_cnt1_reg.uzudtg_input_frame_cnt == (frame_idicator-1)){
							dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
							//make sure that we can have a full porch apply timing change settings
							while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt != frame_idicator)&& --count2){
								dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
							}
							vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
							if((vgip_chn1_lc_reg.ch1_line_cnt >= ch1_line_cnt_lower) && (vgip_chn1_lc_reg.ch1_line_cnt <= ch1_line_cnt_upper)){
								//change to FLL
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "### set fll new mode 1.###\n");
								framesync_lastlinefinetune_at_new_mode();
								modestate_set_display_timing(0);
								modestate_set_fll_running_flag(FALSE);
								checkStableCnt=0;
								if(inputType == VSC_INPUTSRC_HDMI){
									DbgSclrFlgTkr.line_cnt_no_run_hdmi_check = 0;
								}
								//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"\n vgip_chn1_lc_reg.ch1_line_cnt = %d\n", vgip_chn1_lc_reg.ch1_line_cnt);
							}
							if(count2 == 0)
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "count timeout !!!\n");
						}
					}
					else{
						new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
						if(new_meas1_linecnt_real_reg.memcdtg_line_cnt_rt < 200){
							//change to FLL
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "### set fll new mode 2.###\n");
							framesync_lastlinefinetune_at_new_mode();
							modestate_set_display_timing(0);
							modestate_set_fll_running_flag(FALSE);
							checkStableCnt=0;
						}
					}
					up(&VSC_Semaphore);
				}
			}else{
				checkStableCnt++;
			}
		}else{

			if(vbe_disp_get_adaptivestream_fs_mode() == 1){
				drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
			}
			if(Get_DISPLAY_PANEL_OLED_TYPE()==TRUE){
				if((drv_memory_get_game_mode_dynamic() == _ENABLE)&&(drv_memory_get_game_mode() == TRUE)){
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
				}
			}
			checkStableCnt = 0;
			//if source is table, change to false
			if(DbgSclrFlgTkr.line_cnt_no_run_hdmi_check == 1){
				DbgSclrFlgTkr.line_cnt_no_run_hdmi_check = 0;
			}
		}


		fix_last_line_mode_lock_status_reg.regValue = IoReg_Read32(PPOVERLAY_fix_last_line_mode_lock_status_reg);
		fix_last_line_mode_lock_status_reg.lock_th = 0x800;
		IoReg_Write32(PPOVERLAY_fix_last_line_mode_lock_status_reg, fix_last_line_mode_lock_status_reg.regValue);
#if 0//mark redundaent code
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		if((display_timing_ctrl1_reg.disp_fix_last_line == 2) && (fix_last_line_mode_lock_status_reg.t_s != 0)){
			//double buffer D0
			ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			double_buffer_ctrl_reg.dreg_dbuf_en = 0;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);

			display_timing_ctrl1_reg.disp_fix_last_line = 0;
			IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

			//double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			//double_buffer_ctrl_reg.dreg_dbuf_set = 1;
			//IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);

			//display_timing_ctrl1_reg.disp_fix_last_line = 2;
			//IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "FLL re-sync!!\n");
			modestate_set_fll_running_flag(TRUE);

			//double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			//double_buffer_ctrl_reg.dreg_dbuf_set = 1;
			//IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		}
#endif
	}else{
		checkStableCnt = 0;
	}
	up(get_scaler_fll_running_semaphore());
#endif

	//check abnormal dvs flag
	drvif_scaler_check_abnormal_dvs_flag();
	//check onlinemeasure flag
	if(Scaler_InputSrcGetMainChType() == _SRC_VO){
		drvif_scaler_check_main_onlinemeasure_flag();
	}

	if (inputType == VSC_INPUTSRC_JPEG || inputType == VSC_INPUTSRC_VDEC) {
		if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)//If get_vo_change_flag() == TRUE, VO info change
		{
#if defined(CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT)
			static unsigned int hdrCrcErrCnt = 0;
#endif
			plane = get_vo_plane_flag(display);//Avoid to print port error
			down(get_vo_infosemaphore());
			if(get_vo_change_flag(inputPort) == TRUE)
			{
				up(get_vo_infosemaphore());
				if (Get_vo_smoothtoggle_timingchange_flag(display)) {
	               if(get_vo_run_smooth_toggle_enable(display)) {
#if 0
	                   if (get_vo_imd_disable(display)) {
	                       set_vo_change_flag(inputPort, FALSE);
	                       set_vo_imd_disable(_DISABLE,display);
						   inputVfreq = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ);
   	                       rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n +++ adaptive stream before vfreq:%d\n", inputVfreq);
						   Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_VO_Dispinfo(inputPort));
   	                       rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n +++ adaptive stream after vfreq:%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ));
						   if(inputVfreq!=Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ)){
							   scaler_disp_smooth_variable_setting();
						   }
	                       rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n smooth toggle timing change don't need to go scaler\n");
	                       return TRUE;
	                   }
#endif
	               } else {
                       if (get_vo_smoothtoggle_state(display) == SLR_SMOOTH_TOGGLE_ACTIVE) {
                           vo_force_data_mode_set_enable(vo_force_data_mode_get_enable(display), display);
                           set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_INIT, display,plane);
                           smooth_toggle_state_info_rpc(display);
                           rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "set_vo_smoothtoggle_state=SLR_SMOOTH_TOGGLE_INIT\n");
                       }
	               }
				}
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####check_signal vo change active to search####\r\n");

				if(display == SLR_MAIN_DISPLAY) {
					down(&SetMainOutPutRegion_Semaphore);
					reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
					up(&SetMainOutPutRegion_Semaphore);
				} else {
					down(&SetSubOutPutRegion_Semaphore);
					reset_any_srcrect(&sub_dispwin_pre); //Need to Reste previous output value. For run scaler flow
					up(&SetSubOutPutRegion_Semaphore);
				}
				Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);    //WOSQRTK-3464
				state_update_disp_info();

				return TRUE;
			} else {
				up(get_vo_infosemaphore());
			}

#if 0//def CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			if((Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == TRUE)&& (Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() >= SLR_DV_HDMI_DETECT_FOUND_CRC))
			{ // [TODO] change to HDMI source in Dolby Vision source
				if(!Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result() && (++hdrCrcErrCnt > DV_CRC_ERR_THRESH)){
					// force bg when seitch to HDMI source
					set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, _ENABLE);
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, _ENABLE);
					up(get_forcebg_semaphore());

					// disable DM
					DV_Stop();

					Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_DISABLE);
					rtk_hal_vsc_SetHdrDolbyVisionIdmaEnable(FALSE);
					Scaler_HDR_DolbyVision_Hdmi_Set_Detect_Status(SLR_DV_HDMI_DETECT_ON);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] change to HDMI mode...\n");
					return false;
				}else if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_FOUND_CRC){
					if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result()){
						//Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_ENABLE);
						Scaler_HDR_DolbyVision_Hdmi_Set_Detect_Status(SLR_DV_HDMI_DOLBY_MODE_ENABLED);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] Enable Dolby mode...\n");

						// disable force bg
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, _DISABLE);
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, _DISABLE);
						up(get_forcebg_semaphore());
					}else{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] CRC err\n");
					}
				}

				if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result())
					hdrCrcErrCnt = 0;
			}
#endif
#if 0//def CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
			if((Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == TRUE)&& (Scaler_HDR10_Hdmi_Get_Detect_Status() >= SLR_HDR10_HDMI_DETECT_FOUND_MD))
			{ // [TODO] change to HDMI source in Dolby Vision source
				unsigned char hdr10_ready = drvif_hdmi_is_drm_info_ready();

				if(!hdr10_ready /*&& (++hdrCrcErrCnt > DV_CRC_ERR_THRESH)*/){
					// force bg when seitch to HDMI source
					//set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, _ENABLE);
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, _ENABLE);
					up(get_forcebg_semaphore());

					// disable DM

					rtk_hal_vsc_SetHdr10IdmaEnable(FALSE);
					Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] change to HDMI mode...\n");
					return false;
				}else if(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_FOUND_MD){
					if(hdr10_ready){
						//Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_ENABLE);
						Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_HDR_MODE_ENABLED);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] Enable HDR10 Video mode...\n");

						// disable force bg
						//set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, _DISABLE);
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, _DISABLE);
						up(get_forcebg_semaphore());
					}else{
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] CRC err\n");
					}
				}

				if(hdr10_ready)
					hdrCrcErrCnt = 0;
			}
#endif
			/*livezoom openning and closing stop framsync check, or will have noise for scaler run another times*/
			if((Get_LivezoomOffMainForceBG() == TRUE) || (Get_Live_zoom_mode()!=LIVE_ZOOM_OFF) || (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_FRAMESYNC) == FALSE) || (drvif_framesync_detect()))//If Framesync case, we just check drvif_framesync_detect
			{
				down(get_vo_infosemaphore());
				if (get_vo_run_smooth_toggle_enable(display) && get_vo_imd_disable(display)) {
					set_vo_imd_disable(_DISABLE,display);
					inputVfreq = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ);
					input_isInterlace = Scaler_DispGetStatus(display,SLR_DISP_INTERLACE);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n +++ adaptive stream before vfreq:%d\n", inputVfreq);
					Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_VO_Dispinfo(inputPort));
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n +++ adaptive stream after vfreq:%d\n", Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ));
					up(get_vo_infosemaphore());
					//add frame rate changing smooth toggle flow @Crixus 20151215
					if((get_vo_frameratechange_enable(display)==1)&& (inputVfreq!=Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ)) && (vsc_get_adaptivestream_flag()==0)){
						//before set DTG frame rate, it has to wait for smooth toggle done. @Crixus 20151215
						down(&SetMainOutPutRegion_Semaphore);
						Check_smooth_toggle_update_flag(display);
						scaler_disp_smooth_variable_settingByDisp(0);
						up(&SetMainOutPutRegion_Semaphore);
					}
					drvif_scaler_wclr_abnormal_dvs_long_short();
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\n timing:go smooth toggle\n");
				}
				else{
					up(get_vo_infosemaphore());
				}

				if(Get_vo_smoothtoggle_timingchange_flag(display))  //direct vo smooth toggle
				{
					if(get_vo_run_smooth_toggle_enable(display))  //direct_vo :curr display size changed  go smooth toggle
					{
					}
					else
					{
						if (get_reset_smooth_toggle_state(display)) {
							vo_force_data_mode_set_enable(vo_force_data_mode_get_enable(display), display);
							smooth_toggle_state_info_rpc(display);
							set_reset_smooth_toggle_state(_DISABLE,display);
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "set_vo_smoothtoggle_state=SLR_SMOOTH_TOGGLE_ACTIVE\n");
						}
					}
				}
				return TRUE;
			}
			else
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####VO frame sync error!!!######\r\n");
				down(get_forcebg_semaphore());
				scalerdisplay_force_bg_enable(display, TRUE);/*Auto BG. Add by Will*/
				up(get_forcebg_semaphore());

				down(get_vo_infosemaphore());
				if(get_vo_change_flag(inputPort) == TRUE)
				{
					up(get_vo_infosemaphore());
					if(display == SLR_MAIN_DISPLAY) {
						down(&SetMainOutPutRegion_Semaphore);
						reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
						up(&SetMainOutPutRegion_Semaphore);
					} else {
						down(&SetSubOutPutRegion_Semaphore);
						reset_any_srcrect(&sub_dispwin_pre); //Need to Reste previous output value. For run scaler flow
						up(&SetSubOutPutRegion_Semaphore);
					}
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
					state_update_disp_info();
					return TRUE;
				}
				Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_VO_Dispinfo(inputPort));
				if (get_vo_run_smooth_toggle_enable(display) && get_vo_imd_disable(display)) {
					set_vo_imd_disable(_DISABLE,display);
				}
				up(get_vo_infosemaphore());
				if(Get_vo_smoothtoggle_timingchange_flag(display))  //framesync fail need vo smooth toggle reset to init
				{
					set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_INIT, display,plane);
					smooth_toggle_state_info_rpc(display);
				} else {
					if(inputType == VSC_INPUTSRC_VDEC)
					{
						Check_smooth_toggle_update_flag(display);
					}
				}

				//rerun scaler,update input output
				if(display == SLR_MAIN_DISPLAY) 
				{
					down(&SetMainOutPutRegion_Semaphore);
					set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
					Scaler_DispWindowSet(main_dispwin);
					up(&SetMainOutPutRegion_Semaphore);
				}
			}
		}
		else//if(Scaler_DispGetInputInfo(SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
		{
					return TRUE;
		}
	} else {
		if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
			return TRUE;/* State is not _MODE_STATE_ACTIVE. No need to check signal*/

		//if HDMI source, not to run check mode until sync OK @Crixus 20151229
		//USER:LewisLee DATE:2016/02/21
		//for zhaodong_yin suggest
		//to fix HDR mode, Scaler_InputSrcGetType() will change to _SRC_VO
		//it need change to Get_DisplayMode_Src()
//		if((Scaler_InputSrcGetType(display) == _SRC_HDMI) && (DbgSclrFlgTkr.line_cnt_no_run_hdmi_check == 0)) {
		if((Get_DisplayMode_Src(display) == VSC_INPUTSRC_HDMI) && (DbgSclrFlgTkr.line_cnt_no_run_hdmi_check == 0)) {

			if(drvif_hdmi_check_mode() == FALSE)
			{
				set_display_forcebg_mask(display, SLR_FORCE_BG_TYPE_SIG_UNSTABLE, TRUE);//Enable SLR_FORCE_BG_TYPE_SIG_UNSTABLE mask
				down(get_forcebg_semaphore());
				scalerdisplay_force_bg_enable(display, TRUE);/*Auto BG*/
				up(get_forcebg_semaphore());
				if (Get_Live_zoom_mode() == LIVE_ZOOM_SUB ) {
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);/*Auto BG*/
					up(get_forcebg_semaphore());
				}
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n drvif_Hdmi_CheckMode ERROR\n");

#if 0//def CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
				// [DolbyVision] change to Dolby Vision mode
				if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_FOUND_CRC)
				{
					if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result()){
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] change to IDMA mode...\n");
						rtk_hal_vsc_SetHdrDolbyVisionIdmaEnable(TRUE);
						Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_ENABLE);
						return false;
					}
				}
#endif
#if 0//def CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
				// [HDR10] change to IDMA mode
				if(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_FOUND_MD)
				{
					if(drvif_hdmi_is_drm_info_ready()){
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] change to IDMA mode...\n");
						rtk_hal_vsc_SetHdr10IdmaEnable(TRUE);
						return false;
					}
				}
#endif

  				drvif_mode_disableonlinemeasure(display);//Disable online measure
				drvif_mode_onlinemeasure_setting(display, _SRC_HDMI, FALSE, FALSE);//Disable online measure watchdog and interrupt
				if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_SEARCH) {
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n HDMI Interrupt already happen\n");
					vfe_hdmi_drv_adapter();
					return TRUE;
				}
				Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				if (display == SLR_MAIN_DISPLAY) {
					drivf_scaler_reset_freerun();
				}
 				vfe_hdmi_drv_handle_on_line_measure_error(0);
 				vfe_hdmi_drv_adapter();
				down(get_hdmi_detectsemaphore());
				if (get_HDMI_Global_Status() == SRC_CONNECT_DONE) {
					Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_HDMI, TRUE);
					HDMI_set_detect_flag(TRUE);
				}
				up(get_hdmi_detectsemaphore());

				return false;
			}
#if 0//def CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			else if((Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_ON)
				&& (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
			{
				if((Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result() == FALSE)
					&& (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) & _BIT1))
				{
					// disable force bg since no Dolby Vision detected
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] Disable BG...\n");
					set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, _DISABLE);
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, _DISABLE);
					up(get_forcebg_semaphore());
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[DolbyVision] Disable BG Done!!\n");
				}
			}
#endif
#if 0//def CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT

			else if((Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_ON)
				&& (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
			{
				down(get_forcebg_semaphore());
				if((drvif_hdmi_is_drm_info_ready() == FALSE)
					&& (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) & _BIT1))
				{
					// disable force bg since no HDR10 detected
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] Disable BG...\n");
					//set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, _DISABLE);
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, _DISABLE);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[HDR10] Disable BG Done!!\n");
				}
				up(get_forcebg_semaphore());
			}
#endif
		}
#if 0//No need currently
		else if (Scaler_InputSrcGetType(display) == _SRC_YPBPR) {
			if (YPbPr_Small_Signal_Check()) {
				if (YPbPr_Check_DDS_Status() == FALSE) {
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(display, TRUE);/*Auto BG*/
					up(get_forcebg_semaphore());
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n drvif_YPP_CheckMode ERROR\n");
					drvif_mode_disableonlinemeasure(display);//Disable online measure
					drvif_mode_onlinemeasure_setting(display, _SRC_YPBPR, FALSE, FALSE);//Disable online measure watchdog and interrupt
					fw_scaler_adc_nolock_wdg_ctrl(display, FALSE);// Disable adc_nolock_wdg
					if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_SEARCH) {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n YPP Interrupt already happen\n");
						return TRUE;
					}
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
					if (display == SLR_MAIN_DISPLAY) {
						drivf_scaler_reset_freerun();
					}
					down(get_adc_detectsemaphore());
					if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
						Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_ADC, TRUE);/*Let Webos get zero timing*/
						YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
						ADC_set_detect_flag(TRUE);
					}
					up(get_adc_detectsemaphore());

				}
			}
		}
#endif
		return TRUE; /* Not VO source no need to auto run scaler*/
	}
	down(&VSC_Semaphore);
	Scaler_SetCurrentDispInfo(display);
	result = rtk_run_scaler(display, inputType, outputMode); /*This is for VO frame sync error*/
	Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
	up(&VSC_Semaphore);
	return result;

}

static int GamemodeSaveI3ddmaGetcurMode;

int Get_GamemodeSaveI3ddmaGetcurMode(void)
{
	return GamemodeSaveI3ddmaGetcurMode;
}

void Set_GamemodeSaveI3ddmaGetcurMode(int value)
{
	GamemodeSaveI3ddmaGetcurMode = value;
}

unsigned char rtk_output_connect(unsigned char display)
{
	VSC_OUTPUT_MODE_T outputMode = VSC_OUTPUT_MAXN;
	VSC_INPUT_TYPE_T inputType = VSC_INPUTSRC_MAXN;
	unsigned char inputPort = 0;

	if(get_scaler_stop_flag(display) == TRUE)
		  return FALSE;

	if(vsc_debug_mode)
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s start line:%d####\r\n", __FUNCTION__, __LINE__);

	//printk(KERN_EMERG"[crixus]@@@@@[%s][%d]\n", __FUNCTION__, __LINE__);
#ifdef CONFIG_I2RND_ENABLE
	if((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC) &&(vsc_i2rnd_sub_output_mode ==VSC_OUTPUT_VENC_MODE)){
				//save sub info
		VencModeInputInfo.type = vsc_i2rnd_sub_input_type;
		VencModeInputInfo.resourceIndex = vsc_i2rnd_sub_input_port;
	}

#endif
	if (display == SLR_MAIN_DISPLAY) {
		if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_DISPLAY_MODE;
			inputType = DisplayModeInputInfo.type;
			inputPort = DisplayModeInputInfo.resourceIndex;
		}
		else if(VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_VENC_MODE;
			inputType = VencModeInputInfo.type;
			inputPort = VencModeInputInfo.resourceIndex;
		}
		else if(MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_MEMORY_MODE;
			inputType = MemoryModeInputInfo.type;
			inputPort = MemoryModeInputInfo.resourceIndex;
		}
		else
		{
			return false;
		}

		Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);

#ifdef CONFIG_I2RND_ENABLE
	if((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC) &&(vsc_i2rnd_sub_output_mode ==VSC_OUTPUT_VENC_MODE)){
			outputMode = VSC_OUTPUT_VENC_MODE;
			inputType = VencModeInputInfo.type;
			inputPort = VencModeInputInfo.resourceIndex;
			DbgSclrFlgTkr.OutputVencMode = TRUE;
	}
	else{
#endif
		if (DbgSclrFlgTkr.main_opensourceID == _UNKNOWN_INPUT) {
			if (init_source_proc(SLR_MAIN_DISPLAY, inputType, inputPort) == FALSE) {
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n######init_source_proc fail fail#####\r\n");
				DbgSclrFlgTkr.main_opensourceID = _UNKNOWN_INPUT;
				return false;
			}
		}
#ifdef CONFIG_I2RND_ENABLE
		}
#endif
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if (display == SLR_SUB_DISPLAY){
		if(Sub_DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_DISPLAY_MODE;
			inputType = Sub_DisplayModeInputInfo.type;
			inputPort = Sub_DisplayModeInputInfo.resourceIndex;
		}
		else if(Sub_VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_VENC_MODE;
			inputType = Sub_VencModeInputInfo.type;
			inputPort = Sub_VencModeInputInfo.resourceIndex;
		}
		else if(Sub_MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
		{
			outputMode = VSC_OUTPUT_MEMORY_MODE;
			inputType = Sub_MemoryModeInputInfo.type;
			inputPort = Sub_MemoryModeInputInfo.resourceIndex;
		}
		else
		{
			return false;
		}

		Scaler_SetCurrentDispInfo(SLR_SUB_DISPLAY);
		if (DbgSclrFlgTkr.sub_opensourceID == _UNKNOWN_INPUT) {
			if (init_source_proc(SLR_SUB_DISPLAY, inputType, inputPort) == FALSE) {
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n######init_source_proc fail fail#####\r\n");
				DbgSclrFlgTkr.sub_opensourceID = _UNKNOWN_INPUT;
				return false;
			}
		}
	}
#endif
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if(inputType == VSC_INPUTSRC_JPEG || inputType == VSC_INPUTSRC_VDEC || get_line_alternative_3d_mode_enable() == TRUE
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		|| Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED
		#endif
		|| (get_force_i3ddma_enable(display) == true)
#ifdef CONFIG_I2RND_ENABLE
		|| ((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))//VO source
#endif
		)
#else
	if(inputType == VSC_INPUTSRC_JPEG || inputType == VSC_INPUTSRC_VDEC || get_line_alternative_3d_mode_enable() == TRUE
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		|| Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED
		#endif
		)//VO source
#endif
	{
		down(get_vo_infosemaphore());
#ifdef CONFIG_FORCE_RUN_I3DDMA
		if(get_line_alternative_3d_mode_enable() == TRUE
			#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			|| Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED
			#endif
			|| get_force_i3ddma_enable(display) == true
#ifdef CONFIG_I2RND_ENABLE
			|| ((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))
#endif
			)
#else
		if(get_line_alternative_3d_mode_enable() == TRUE
			#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			|| Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED
			#endif
			)
#endif
		{
			inputPort = 0; //hdmi hdr always set vo port0:
		}
		set_vo_change_flag(inputPort, FALSE);
	#if 0
		if(get_vo_3d_mode() == VO_3D_SIDE_BY_SIDE_HALF || get_vo_3d_mode() == VO_3D_TOP_AND_BOTTOM || get_vo_3d_mode() == VO_3D_FRAME_PACKING)
		{
			drvif_scalerdisplay_force_bg((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), 1);//enable force BG for vo 3d auto detect
		}
	#endif
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (display == SLR_SUB_DISPLAY)) {
			//tmp code
			Scaler_SET_VSCSubDispinfo_Withmain();
		} else {
			Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_VO_Dispinfo(inputPort));
		}
		up(get_vo_infosemaphore());

		if (vsc_timinginfo_check() == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME_VSC, "\n####VO info is zero####\n");
			if (display == SLR_MAIN_DISPLAY) {
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_pre);
				up(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_during_scalerflow_flag = FALSE;//WOSQRTK-7524 patch. Reset Main_during_scalerflag
			} else {
				down(&SetSubOutPutRegion_Semaphore);
				reset_any_srcrect(&sub_dispwin_pre);
				up(&SetSubOutPutRegion_Semaphore);
			}
			return FALSE;
		}
		if(inputType == VSC_INPUTSRC_VDEC)
		{
			Check_smooth_toggle_update_flag(display);
		}

		if((inputType == VSC_INPUTSRC_VDEC) && DbgSclrFlgTkr.adaptive_stream && (display == SLR_MAIN_DISPLAY)) {
			cal_adaptive_streaming_input(SLR_MAIN_DISPLAY);//cal input parameter for adaptive stream //Will 20151127
		}
	}
	else
	{

	}
#ifdef CONFIG_I2RND_ENABLE
	//i2rnd sub=>vodma checking @Crixus 2160721
	if((display == SLR_SUB_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DISABLE)){
		vsc_i2rnd_sub_stage = I2RND_STAGE_DETECT_SOURCE;
		//save sub info
		vsc_i2rnd_sub_output_mode= outputMode;
		vsc_i2rnd_sub_input_type = inputType;
		vsc_i2rnd_sub_input_port = Sub_MemoryModeInputInfo.resourceIndex;
		printk(KERN_EMERG"[I2RND]@@@@@@@@@@@@I2RND_STAGE_DETECT_SOURCE\n");
	}

	if((Scaler_I2rnd_get_enable() == _ENABLE) && (inputType == VSC_INPUTSRC_VDEC)){
		if(display == SLR_MAIN_DISPLAY)
			drvif_scaler_i2rnd_vodma_setting(SLR_MAIN_DISPLAY, inputType);
		else if(display == SLR_SUB_DISPLAY)
			drvif_scaler_i2rnd_vodma_setting(SLR_SUB_DISPLAY, inputType);
	}

	printk(KERN_EMERG"[frank]rtk_output_connect %d,%d,%d\n",display,inputType,outputMode);
#endif

#ifdef CONFIG_I2RND_B05_ENABLE
	if((Scaler_I2rnd_b05_get_enable() == _ENABLE) && (inputType == VSC_INPUTSRC_VDEC)){
		if(display == SLR_MAIN_DISPLAY)
			drvif_scaler_i2rnd_b05_vodma_setting(SLR_MAIN_DISPLAY);
	}
#endif

	return (rtk_run_scaler(display, inputType, outputMode));
}

void scaler_i2rnd_run_main(void){
	//printk(KERN_EMERG"[crixus]@@@@@[%s][%d]\n", __FUNCTION__, __LINE__);
	rtk_output_connect(SLR_MAIN_DISPLAY); // different format to go normal scaler
#ifdef CONFIG_I2RND_ENABLE
	i2rnd_send_table_idx(I2RND_TABLE_OFF);
#endif
}

extern unsigned char g_ucCurColorStd;
extern unsigned char Scaler_AVD_GetDetectStage(void);
extern unsigned char g_ucColorOK;
unsigned char wait_atv_stable_for_bg(unsigned char display)
{
	UINT8 ucVdReady = 0;
	unsigned short Timeout = 0;
	unsigned char *p_stop_flag = &DbgSclrFlgTkr.Main_Scaler_Stop_flag;
	unsigned char *p_output_set_flag = &DbgSclrFlgTkr.Main_Output_Set_flag;
	unsigned char *p_run_scaler_flag = &DbgSclrFlgTkr.Main_Run_Scaler_flag;
	if(display == SLR_MAIN_DISPLAY) {
		p_stop_flag = &DbgSclrFlgTkr.Main_Scaler_Stop_flag;
		p_output_set_flag = &DbgSclrFlgTkr.Main_Output_Set_flag;
		p_run_scaler_flag = &DbgSclrFlgTkr.Main_Run_Scaler_flag;
	}
#ifdef CONFIG_DUAL_CHANNEL
	else
	{
		p_stop_flag = &DbgSclrFlgTkr.Sub_Scaler_Stop_flag;
		p_output_set_flag = &DbgSclrFlgTkr.Sub_Output_Set_flag;
		p_run_scaler_flag = &DbgSclrFlgTkr.Sub_Run_Scaler_flag;
	}
#endif
	//rtd_printk(KERN_INFO, TAG_NAME_VSC, "p_stop_flag=%d, p_output_set_flag=%d, p_run_scaler_flag=%d [%s(line:%d)]\n",p_stop_flag, p_output_set_flag, p_run_scaler_flag, __FUNCTION__, __LINE__);
	down(get_avd_power_semaphore());
	if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
	{
		ucVdReady = drvif_module_vdc_OutputStable();
	}
	up(get_avd_power_semaphore());

	if (vdc_LockStatus)
	{
		extern UINT8 dma_3d_ON_count;
		dma_3d_ON_count = 0;	//init
		while (ucVdReady == FALSE)
		{
			VDC_DEBUG_MSG(VDC_MSG_TVCHCH_DETAIL, "[1]V_state timeout = %d\n",Timeout);
			msleep(10);
			if(*p_stop_flag || *p_output_set_flag || *p_run_scaler_flag)
				return FALSE;
			Timeout++;
			if (Timeout >= 100) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[VSC]V_state timeout\n");
				drvif_module_vdc_set_vstate_new2to3_en(_ENABLE);		/* vstate != 3, set */
				VDC_DEBUG_MSG(VDC_MSG_TVCHCH_DETAIL, "[VSC]V_state timeout\n");
				return FALSE;
				//break;
			}

			down(get_avd_power_semaphore());
			if(get_AVD_Global_Status() == SRC_CONNECT_DONE){
				ucVdReady = drvif_module_vdc_OutputStable();
			}
			up(get_avd_power_semaphore());
		}
	}else{
		if(0 == drvif_video_status_reg(VDC_no_signal))
			return FALSE;
	}

	rtd_printk(KERN_INFO, TAG_NAME_VSC, "vdc_LockStatus=%x, ucVdReady=%x, count=%d [%s(line:%d)]\n",vdc_LockStatus, ucVdReady, Timeout, __FUNCTION__, __LINE__);
	VDC_DEBUG_MSG(VDC_MSG_TVCHCH, "vdc_LockStatus=%x, ucVdReady=%x, count=%d wait_atv_stable_for_bg\n",vdc_LockStatus, ucVdReady, Timeout);

	drvif_module_vdc_new_vdetect_Enable(New_vedetect);
	drvif_module_vdc_set_vstate_speedup(vstate_count_default);
	if(*p_stop_flag || *p_output_set_flag || *p_run_scaler_flag)
		return FALSE;
	else
		return TRUE;
}


unsigned char check_atv_stable_for_bg(unsigned char display)
{
	UINT8 ucVdReady = 0;
	unsigned short Timeout = check_atv_stable_count;

	down(get_avd_power_semaphore());
	if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
	{
		ucVdReady = drvif_module_vdc_OutputStable();
	}
	up(get_avd_power_semaphore());
	//rtd_printk(KERN_INFO, TAG_NAME_VSC, "vdc_LockStatus=%x, ucVdReady=%x, count=%d [%s(line:%d)]\n",vdc_LockStatus, ucVdReady, Timeout, __FUNCTION__, __LINE__);

	if (vdc_LockStatus)
	{
		extern UINT8 dma_3d_ON_count;
		dma_3d_ON_count = 0;	//init
		if (ucVdReady == FALSE)
		{

			Timeout++;
			if (Timeout >= 20) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[VSC]V_state timeout\n");
				drvif_module_vdc_set_vstate_new2to3_en(_ENABLE);		/* vstate != 3, set */
				VDC_DEBUG_MSG(VDC_MSG_TVCHCH_DETAIL, "[VSC]V_state timeout\n");
				return FALSE;
			}
			check_atv_stable_count = Timeout;
			drvif_module_vdc_new_vdetect_Enable(New_vedetect);
			drvif_module_vdc_set_vstate_speedup(vstate_count_default);
			return FALSE;

		}else{

			return TRUE;
		}
	}else{
		if(0 == drvif_video_status_reg(VDC_no_signal))
			return FALSE;
	}

}


//Calc the count of SetWinBlank=0 durning ATV Channel change
void	CalcWinBlankCountForATVChanlChg(unsigned char channel, bool bonoff)
{
	//rtd_printk(KERN_INFO, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	// VSC is connectd to AVD
	if (!bonoff && (VSC_INPUTSRC_AVD == Get_DisplayMode_Src(channel))
		&& (get_AVD_Input_Source() == _SRC_TV))
	{
		if (TRUE == DbgSclrFlgTkr.g_ucVSCCheckATVChanelChange)
		{
			DbgSclrFlgTkr.g_ucVDCDetectStage = Scaler_AVD_GetDetectStage();

			DbgSclrFlgTkr.g_ucVSCCheckATVChanelChange = FALSE;
			DbgSclrFlgTkr.g_ucVSCATVChanelChangeStart = TRUE;

			rtd_printk(KERN_INFO, TAG_NAME_VSC, "reset DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount=0\n");
		}


		if (TRUE == DbgSclrFlgTkr.g_ucVSCATVChanelChangeStart)
		{
			DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount++;
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount=%d\n", DbgSclrFlgTkr.g_ucVSCATVSetWinBlankCount);
		}
	}
}


unsigned char rtk_hal_vsc_SetWinBlank(VIDEO_WID_T wid, bool bonoff, VIDEO_DDI_WIN_COLOR_T color)
{
	SCALER_DISP_CHANNEL channel;

	rtd_printk(KERN_INFO, TAG_NAME_VSC, "rtk_hal_vsc_SetWinBlank wid:%d enable=%d\n", wid, bonoff);

#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN) || (wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_INFO, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid != VIDEO_WID_0)
	{
		rtd_printk(KERN_INFO, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	if((color > VIDEO_DDI_WIN_COLOR_RGB_API) || (color < VIDEO_DDI_WIN_COLOR_BLACK))
		return FALSE;

	if (wid == VIDEO_WID_0) {
		channel = SLR_MAIN_DISPLAY;
	} else if (wid == VIDEO_WID_1) {
		channel = SLR_SUB_DISPLAY;
	}

	if(OutpuLocalDimmingPatMode == TRUE){
        if(bonoff)
            set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, TRUE);
        else
            set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
		return TRUE;
	}

	//Calc the count of SetWinBlank=0 durning ATV Channel change
	CalcWinBlankCountForATVChanlChg(channel, bonoff);
	if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD)&&(get_AVD_Input_Source() == _SRC_TV)){//For KTASKWBS-5200
		check_atv_stable_count =0;
		if (!bonoff && drvif_module_vdc_read_external_ch_change_flag()){
			set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
			rtd_printk(KERN_INFO, TAG_NAME_VSC,"######[%s(line:%d)]external_ch_change_flag =1 don't run rtk_hal_vsc_SetWinBlank\n",__FUNCTION__, __LINE__);
			return TRUE;
		}

		if (!bonoff&&(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)
			&&(Scaler_AVD_GetVDPreMode() == _MODE_UNKNOWN)
			&&(0 == drvif_video_status_reg(VDC_no_signal))){
			set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
			rtd_printk(KERN_INFO, TAG_NAME_VSC,"######[%s(line:%d)]fast zapping, flicker garbage.#####\n",__FUNCTION__, __LINE__);
			if(DbgSclrFlgTkr.Main_Output_Set_flag) {
				DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
				DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
            		}
			return TRUE;
		}
	}
	if (bonoff) {
		if(channel == SLR_MAIN_DISPLAY) {
			DbgSclrFlgTkr.Main_ATV_Go_Smooth_Toggle_flag = FALSE;//ATV can not run smooth toggle
#ifdef CONFIG_DUAL_CHANNEL
		} else {
			DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag = FALSE;//ATV can not run smooth toggle
		}
#endif
		//frank@03102016 DOLBYCERT-144 store mode change playback file osd flash issue ++
		if ((channel == SLR_MAIN_DISPLAY) && Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_FRAMESYNC) &&(get_HDMI_HDR_mode() !=HDR_DOLBY_HDMI) && (get_HDMI_HDR_mode() !=HDR_HDR10_HDMI) &&(!vbe_disp_get_adaptivestream_fs_mode())){
			#ifndef CONFIG_FORCE_RUN_I3DDMA //not define
			drivf_scaler_reset_freerun();
			#endif
		}
		//if((Get_DISPLAY_PANEL_OLED_TYPE()==1)&& vsc_get_adaptivestream_flag() && (channel == SLR_MAIN_DISPLAY)){
		if(vsc_get_adaptivestream_flag() && (channel == SLR_MAIN_DISPLAY)&&(Check_AP_Set_Enable_ForceBG(channel) == FALSE)){
			Check_smooth_toggle_update_flag(SLR_MAIN_DISPLAY);
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "######### [%s]line:%d, enable wdg\n", __FUNCTION__, __LINE__);
			drvif_mode_enableonlinemeasure(channel);//Enable online measure
			drvif_mode_onlinemeasure_setting(channel, _SRC_VO, TRUE, FALSE);
		}
		//frank@03102016 DOLBYCERT-144 store mode change playback file osd flash issue --


		if(color == VIDEO_DDI_WIN_COLOR_BLACK)
		{
			drvif_scalerdisplay_set_bg_color(channel, _DISPLAY_BG, 0x0000, 0x0000, 0x0000);
		}
		else if(color == VIDEO_DDI_WIN_COLOR_BLUE)
		{
			drvif_scalerdisplay_set_bg_color(channel, _DISPLAY_BG, 0x0000, 0x0000, 0x3FFF);
		}
		else if(color == VIDEO_DDI_WIN_COLOR_GRAY)
		{
			drvif_scalerdisplay_set_bg_color(channel, _DISPLAY_BG, 0x2fff, 0x2fff, 0x2fff);
		}
		else if(color == VIDEO_DDI_WIN_COLOR_RGB_API)
		{
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "\r\n rtk_hal_vsc_SetWinBlank display:%d follow RGB color API\n", channel);
		}


		set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, TRUE);

		if((channel == SLR_MAIN_DISPLAY) && TV006_WB_Pattern_En)	//WOSQRTK-7731
		{
			return TRUE;
		}

	} else {
		if(channel == SLR_MAIN_DISPLAY) {
			down(&SetMainOutPutRegion_Semaphore);
			if(DbgSclrFlgTkr.Main_Output_Set_flag) {
				DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
				DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
#ifdef _PRINT_VSC_COST_TIME_AFTER_MUTE_OFF
				cost_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
#endif
				if(vsc_debug_mode)
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request main scaler####\r\n", __FUNCTION__);

				set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
				up(&SetMainOutPutRegion_Semaphore);
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s request main scaler##########\r\n", __FUNCTION__);
				return TRUE;
			} else if(DbgSclrFlgTkr.rotate_muteoff_request_flag) {

				set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
				DbgSclrFlgTkr.rotate_run_scaler_flag = TRUE;
				up(&SetMainOutPutRegion_Semaphore);
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s request main rotate##########\r\n", __FUNCTION__);
				return TRUE;
			} else if(DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag) {
				if(vsc_debug_mode)
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request main smooth toggle####\r\n", __FUNCTION__);

				set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
				DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off = TRUE;
				up(&SetMainOutPutRegion_Semaphore);
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s request main smooth toggle##########\r\n", __FUNCTION__);
				return TRUE;
			} else if(DbgSclrFlgTkr.Main_smooth_toggle_set_flag || DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off){//Rika
				set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
				up(&SetMainOutPutRegion_Semaphore);
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s smoothtoggle now##########\r\n", __FUNCTION__);
				return TRUE;
			}
			up(&SetMainOutPutRegion_Semaphore);
			if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) || (Get_LivezoomOffMainForceBG() == TRUE)) {
				set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
			} else {
				if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
				{
					if(DbgSclrFlgTkr.Main_ATV_PassThrought_output_flag == TRUE){
						set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
						if(vsc_debug_mode)
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s atv case####\r\n", __FUNCTION__);

						rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s atv case##########\r\n", __FUNCTION__);
						return TRUE;
					}
				}
				if(Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE) {
					set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
					if(vsc_debug_mode)
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s Main currently is not active can not disable BG####\r\n", __FUNCTION__);

					rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s Main currently is not active can not disable BG##########\r\n", __FUNCTION__);
					return TRUE;
				}
				else if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) ==  VSC_INPUTSRC_VDEC) && DbgSclrFlgTkr.Main_during_scalerflow_flag)
				{
					set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####func:%s Main during scaler flow so can not disable BG####\r\n", __FUNCTION__);
					return TRUE;
				}
			}
		} else {
			down(&SetSubOutPutRegion_Semaphore);
			if(DbgSclrFlgTkr.Sub_Output_Set_flag) {
				DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
				DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;
				if(vsc_debug_mode)
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request sub scaler#####\r\n", __FUNCTION__);
				set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
				up(&SetSubOutPutRegion_Semaphore);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n########func:%s request sub scaler##########\r\n", __FUNCTION__);
				return TRUE;
			}
			up(&SetSubOutPutRegion_Semaphore);
			if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) || (Get_LivezoomOffMainForceBG() == TRUE)) {
				set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
			} else {
				if((Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
				{
					set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
					if(vsc_debug_mode)
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s atv case#####\r\n", __FUNCTION__);

					rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s atv case##########\r\n", __FUNCTION__);
					return TRUE;
				}
				if(Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE) {
					set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
					if(vsc_debug_mode)
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s Sub currently is not active can not disable BG#####\r\n", __FUNCTION__);

					rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s Sub currently is not active can not disable BG##########\r\n", __FUNCTION__);
				}
			}
		}
		set_display_forcebg_mask(channel, SLR_FORCE_BG_TYPE_VSC, FALSE);
	}

	if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) || (Get_LivezoomOffMainForceBG() == TRUE)) {
		/*livezoom and magnifier open forcebg no need check status*/
	} else {
		if((Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE) && !bonoff) {
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "########func:%s line:%d signal not stable can not disable BG##########\r\n", __FUNCTION__, __LINE__);
			return TRUE;
		}
	}
#ifdef USE_FORCEBG_TASK
	if(channel == SLR_MAIN_DISPLAY) {
		spin_lock(&Main_Request_ForceBG_ctrl_Spinlock);
		DbgSclrFlgTkr.Main_Request_ForceBG_ctrl = TRUE;
		spin_unlock(&Main_Request_ForceBG_ctrl_Spinlock);
	} else {
		spin_lock(&Sub_Request_ForceBG_ctrl_Spinlock);
		DbgSclrFlgTkr.Sub_Request_ForceBG_ctrl = TRUE;
		spin_unlock(&Sub_Request_ForceBG_ctrl_Spinlock);
	}
	wake_up(&FORCEBG_WAIT_QUEUE);
#else
	if(channel == SLR_MAIN_DISPLAY)
	{
		if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY))
		{
			down(get_forcebg_semaphore());
			scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
			up(get_forcebg_semaphore());

			//if(Get_DISPLAY_PANEL_BOW_RGBW() == TRUE){
				//drivf_scaler_reset_freerun();
			//}
#ifdef CONFIG_HW_SUPPORT_MEMC
				//These are for mute on to wait memc already blck video
			if(sync_memc_ready && bonoff)//if TRUE. when mute on to wait memc buffer
			{
				wait_memc_ready();//wait memc buffer
			}
#endif
		}
		else
		{
			down(get_forcebg_semaphore());
			scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
			up(get_forcebg_semaphore());
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	else
	{
		down(get_forcebg_semaphore());
		if(Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY))
		{
			scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);
		}
		else
		{
			scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
		}
		up(get_forcebg_semaphore());
	}
#endif
#endif
#if 1
//	if (bonoff)
	if (bonoff && (Get_DisplayMode_Src(channel) == VSC_INPUTSRC_AVD) && (!get_sub_OutputVencMode()))
	{
		if (get_AVD_Input_Source() == _SRC_TV)
		{
#if 1  //ch_change_flag, 20151221
			Scaler_AVD_ResetTVCount();
#else
			if (drvif_module_vdc_read_Clamping_path() == 0)
			{
				vdc_exTV_chch = TRUE;
				vdc_resetTV_Count = 0x0;
				drvif_module_vdc_set_ch_change_flag(1);
			}/* mark internal ch change
			else {
				vdc_inTV_chch = TRUE;
				vdc_resetTV_Count = 0x0;
			}*/
#endif
		} else if (get_AVD_Input_Source() == _SRC_CVBS)
			vdc_AV_modech = TRUE;
	}
	else
	{
#if 0  //ch_change_flag, 20151221
		vdc_inTV_chch = FALSE;
		vdc_exTV_chch = FALSE;
#endif
		Scaler_AVD_ResetTVCount();
	}
#endif
	return TRUE;
}


unsigned char rtk_hal_vsc_GetInputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * pinregion)
{
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	if(wid ==VIDEO_WID_0) {
		if ((DbgSclrFlgTkr.OutputVencMode || DbgSclrFlgTkr.OutputMemoryMode || DbgSclrFlgTkr.OutputAveMode || DbgSclrFlgTkr.OuputDisplayMode)) {
			pinregion->x = main_input_size.srcx;
			pinregion->w = main_input_size.src_wid;
			pinregion->y = main_input_size.srcy;
			pinregion->h = main_input_size.src_height;
#ifdef CONFIG_SDNR_CROP
#ifdef CONFIG_I2RND_ENABLE
			if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){
				pinregion->x = sub_input_size.srcx;
				pinregion->w = sub_input_size.src_wid;
				pinregion->y = sub_input_size.srcy;
				pinregion->h = sub_input_size.src_height;
			}
#endif
#endif
		} else {
			pinregion->x = 0;
			pinregion->y = 0;
			pinregion->w = 0;
			pinregion->h = 0;
		}
	} else if (wid ==VIDEO_WID_1) {
		if ((DbgSclrFlgTkr.Sub_OutputVencMode || DbgSclrFlgTkr.Sub_OutputMemoryMode || DbgSclrFlgTkr.Sub_OutputAveMode || DbgSclrFlgTkr.Sub_OuputDisplayMode)) {
			pinregion->x = sub_input_size.srcx;
			pinregion->w = sub_input_size.src_wid;
			pinregion->y = sub_input_size.srcy;
			pinregion->h = sub_input_size.src_height;
		} else {
			pinregion->x = 0;
			pinregion->y = 0;
			pinregion->w = 0;
			pinregion->h = 0;
		}

	}
	return TRUE;
}

#if(LiveZoom_PROFILE == 1)
unsigned int magnifierbefore_time = 0;
unsigned int magnifierafter_time = 0;
#endif

unsigned char check_only_xy_shift_case(unsigned char display, StructSrcRect *input, StructSrcRect *output);
void apply_only_xy_shift(unsigned char display, StructSrcRect input, StructSrcRect output);
#ifdef CONFIG_FORCE_RUN_I3DDMA
unsigned char scaler_force_run_idma(unsigned char display, VSC_INPUT_TYPE_T inputSrctype);
#endif

unsigned char rtk_hal_vsc_SetInputRegion_ForAdaptive(VIDEO_WID_T wid, VIDEO_RECT_T  inregion)
{
	VSC_INPUT_TYPE_T srctype;


	if(wid == VIDEO_WID_0)
		srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);
	else
		srctype = Get_DisplayMode_Src(SLR_SUB_DISPLAY);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if((srctype == VSC_INPUTSRC_HDMI)&&(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)&&(wid == VIDEO_WID_0))
	{
		unsigned int input_w;

		input_w = Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHWID);
		//input_w = Scaler_HDR10_Hdmi_Get_Input_ACT_WID_info();
		if(input_w > 3840){
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n input_w=%d \n",input_w);
			inregion.x = 3840*inregion.x/input_w;
			inregion.w = 3840*inregion.w/input_w;
		}
	}
#endif

	if(inregion.w%2)
		inregion.w -=1;

#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif
	down(&Magnifier_Semaphore);

	rtd_printk(KERN_INFO, TAG_NAME_VSC, "rtk_hal_vsc_SetInputRegion_ForAdaptive x=%d, y=%d, w=%d, h=%d\n", inregion.x, inregion.y, inregion.w, inregion.h);
	if ((inregion.w < 1) || (inregion.h < 1)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s wid:%d input paramter is 0#####\r\n",__FUNCTION__, wid);
		if ((wid == VIDEO_WID_0) && (Get_LivezoomOffMainForceBG() == TRUE)) {
			DbgSclrFlgTkr.LivezoomOffKeepMainForceBG = TRUE;
		}
		up(&Magnifier_Semaphore);
		return TRUE;
	}
	if(_DISP_WID && _DISP_LEN){
		if(inregion.w + inregion.x > _DISP_WID){
			inregion.x = 0;
			inregion.w = _DISP_WID;
			rtd_printk(KERN_EMERG, TAG_NAME_VSC, "rtk_hal_vsc_SetInputRegion_ForAdaptive wrong wid\n");
		}
		if(inregion.h + inregion.y > _DISP_LEN){
			inregion.y = 0;
			inregion.h = _DISP_LEN;
			rtd_printk(KERN_EMERG, TAG_NAME_VSC, "rtk_hal_vsc_SetInputRegion_ForAdaptive wrong len\n");
		}
	}

	if(wid == VIDEO_WID_0) {
		down(&SetMainOutPutRegion_Semaphore);
		srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);

		main_input_size.srcx = inregion.x;
		main_input_size.srcy = inregion.y;
		main_input_size.src_wid = inregion.w;
		main_input_size.src_height = inregion.h;

		Scaler_AdaptiveStream_InputWindowSet(main_input_size);//for the first time, adpative stream timing change smooth toggle overscan size
		Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_ENABLE);//add this to identify InputRegion and InputRegion_forAdaptive

		if ((srctype == VSC_INPUTSRC_AVD))
		{
			set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
		}
		else
		{
			//zoom_imd_smooth_toggle_config(wid, inregion.x, inregion.y, inregion.w, inregion.h, ZOOM_CROP);
			if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && (srctype == VSC_INPUTSRC_JPEG))
			{
				if(check_only_xy_shift_case(SLR_MAIN_DISPLAY, &main_input_size_pre, &main_dispwin_for_only_xy))
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "apply_only_xy_shift...\n");
					apply_only_xy_shift(SLR_MAIN_DISPLAY, main_input_size, main_dispwin_for_only_xy);
				}
				else {
					if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){
						if(vsc_debug_mode)
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request run smooth toggle flow####\r\n", __FUNCTION__);

						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s line:%d request run smooth toggle flow####\r\n", __FUNCTION__, __LINE__);
						DbgSclrFlgTkr.Main_smooth_toggle_set_flag = TRUE;
					} else {
						if(vsc_debug_mode)
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request mute off to run smooth toggle####\r\n", __FUNCTION__);

						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s line:%d request mute off to run smooth toggle####\r\n", __FUNCTION__, __LINE__);
						DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag = TRUE;
					}
				}
			}
		}
		up(&SetMainOutPutRegion_Semaphore);
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if(wid == VIDEO_WID_1) {
		down(&SetSubOutPutRegion_Semaphore);

		sub_input_size.srcx = inregion.x;
		sub_input_size.srcy = inregion.y;
		sub_input_size.src_wid = inregion.w;
		sub_input_size.src_height = inregion.h;

		#if 0// for sub smooth toggle test
		zoom_imd_smooth_toggle_config(wid, inregion.x, inregion.y, inregion.w, inregion.h, ZOOM_CROP);
		#endif
		up(&SetSubOutPutRegion_Semaphore);
	}
#endif

	up(&Magnifier_Semaphore);

	return TRUE;
}

unsigned char rtk_hal_vsc_GetInputRegion_ForAdaptive(VIDEO_WID_T wid, VIDEO_RECT_T * poutregion)
{
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN) || (wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	if(wid ==VIDEO_WID_0) {
		if ((DbgSclrFlgTkr.OutputVencMode || DbgSclrFlgTkr.OutputMemoryMode || DbgSclrFlgTkr.OutputAveMode || DbgSclrFlgTkr.OuputDisplayMode)) {
			poutregion->x = main_dispwin.srcx;
			poutregion->y = main_dispwin.srcy;
			poutregion->w = main_dispwin.src_wid;
			poutregion->h = main_dispwin.src_height;
		} else {
			poutregion->x = 0;
			poutregion->y = 0;
			poutregion->w = 0;
			poutregion->h = 0;
		}
	} else if (wid ==VIDEO_WID_1) {
		if ((DbgSclrFlgTkr.Sub_OutputVencMode || DbgSclrFlgTkr.Sub_OutputMemoryMode || DbgSclrFlgTkr.Sub_OutputAveMode || DbgSclrFlgTkr.Sub_OuputDisplayMode)) {
			poutregion->x = sub_dispwin.srcx;
			poutregion->y = sub_dispwin.srcy;
			poutregion->w = sub_dispwin.src_wid;
			poutregion->h = sub_dispwin.src_height;
		} else {
			poutregion->x = 0;
			poutregion->y = 0;
			poutregion->w = 0;
			poutregion->h = 0;
		}

	}

	return TRUE;

}
unsigned char rtk_hal_vsc_SetInputRegion(VIDEO_WID_T wid, VIDEO_RECT_T  inregion)
{
	VSC_INPUT_TYPE_T srctype;

#if(LiveZoom_PROFILE == 1)
	magnifierafter_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\nVSC SetOutputRegion  end to next SetInputRegion star time=%d ms\n",(magnifierafter_time -magnifierbefore_time));
	magnifierbefore_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
#endif

    if(wid == VIDEO_WID_0)
		srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);
	else
		srctype = Get_DisplayMode_Src(SLR_SUB_DISPLAY);

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if((srctype == VSC_INPUTSRC_HDMI)&&(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)&&(wid == VIDEO_WID_0))
	{
		unsigned int input_w;

		input_w = Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHWID);
		//input_w = Scaler_HDR10_Hdmi_Get_Input_ACT_WID_info();
		if(input_w > 3840){
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n input_w=%d \n",input_w);
			inregion.x = 3840*inregion.x/input_w;
			inregion.w = 3840*inregion.w/input_w;
		}
	}
#endif

#ifdef FORCE_BYPASS_DI_RTNR
//Debug use. Interlace timing don't go rtnr and DI
	if(wid == VIDEO_WID_0)
	{
		inregion.h = inregion.h/2;
		inregion.y = inregion.y/2;
	}
#endif

	if(inregion.w%2)
		inregion.w -=1;

#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	down(&Magnifier_Semaphore);

	if (srctype == VSC_INPUTSRC_AVD)
	{
#if 0 //ch_change_flag, 20151221
		vdc_inTV_chch = FALSE;
		vdc_exTV_chch = FALSE;
#endif
		if((get_AVD_Input_Source() == _SRC_TV) && (drvif_module_vdc_read_external_ch_change_flag())){//For KTASKWBS-5200
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"external_ch_change_flag =1 don't clear exTV flag and count\n");
			up(&Magnifier_Semaphore);
			return TRUE;
		}else{
			//vdc_resetTV_Count = 0x0;
			//rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"clear exTV flag and count\n");
		}
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "#####[%s(%d)] x=%d, y=%d, w=%d, h=%d\n", __FUNCTION__, __LINE__, inregion.x, inregion.y, inregion.w, inregion.h);

	if ((inregion.w < 1) || (inregion.h < 1)) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s wid:%d input paramter is 0#####\r\n",__FUNCTION__, wid);
		if ((wid == VIDEO_WID_0) && (Get_LivezoomOffMainForceBG() == TRUE)) {
			DbgSclrFlgTkr.LivezoomOffKeepMainForceBG = TRUE;
		}
		if (wid == VIDEO_WID_0)
			main_InputRegion_0000 = 1;
		up(&Magnifier_Semaphore);
		return TRUE;
	}
	else
	{
		if (wid == VIDEO_WID_0)
			main_InputRegion_0000 = 0;
	}
	
	if(inregion.x >4096) {
		 inregion.x=0;
	}
	if(inregion.w >4096) {
		 inregion.w=0;
	}
	if(inregion.h >4096) {
		 inregion.h=0;
	}
	if(inregion.y >4096) {
		 inregion.y=0;
	}

	if(wid == VIDEO_WID_0) {
		down(&SetMainOutPutRegion_Semaphore);
		srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);

		main_input_size.srcx = inregion.x;
		main_input_size.srcy = inregion.y;
		main_input_size.src_wid = inregion.w;
		main_input_size.src_height = inregion.h;

		Scaler_AdaptiveStream_InputWindowSet(main_input_size);
		Scaler_AdaptiveStream_NewInputRegionFlagSet(wid,_DISABLE);

		if ((srctype == VSC_INPUTSRC_AVD))
		{
			set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);

			inregion.x = Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY,inregion.x);
			inregion.w = Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY,inregion.w);

			zoom_imd_smooth_toggle_config(wid, inregion.x, inregion.y, inregion.w, inregion.h, ZOOM_CROP);

		}
		else
		{
			//zoom_imd_smooth_toggle_config(wid, inregion.x, inregion.y, inregion.w, inregion.h, ZOOM_CROP);
			if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && (srctype == VSC_INPUTSRC_JPEG))
			{
				if(check_only_xy_shift_case(SLR_MAIN_DISPLAY, &main_input_size_pre, &main_dispwin_for_only_xy))
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "apply_only_xy_shift...\n");
					apply_only_xy_shift(SLR_MAIN_DISPLAY, main_input_size, main_dispwin_for_only_xy);
				}
				else {
					if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){
						if(vsc_debug_mode)
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request run smooth toggle flow####\r\n", __FUNCTION__);

						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s line:%d request run smooth toggle flow####\r\n", __FUNCTION__, __LINE__);
						DbgSclrFlgTkr.Main_smooth_toggle_set_flag = TRUE;
					} else {
						if(vsc_debug_mode)
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request mute off to run smooth toggle####\r\n", __FUNCTION__);

						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s line:%d request mute off to run smooth toggle####\r\n", __FUNCTION__, __LINE__);
						DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag = TRUE;
					}
				}
			}
		}
		up(&SetMainOutPutRegion_Semaphore);
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if(wid == VIDEO_WID_1) {
		down(&SetSubOutPutRegion_Semaphore);

		sub_input_size.srcx = inregion.x;
		sub_input_size.srcy = inregion.y;
		sub_input_size.src_wid = inregion.w;
		sub_input_size.src_height = inregion.h;

		#if 0// for sub smooth toggle test
		zoom_imd_smooth_toggle_config(wid, inregion.x, inregion.y, inregion.w, inregion.h, ZOOM_CROP);
		#endif
		up(&SetSubOutPutRegion_Semaphore);
	}
#endif

	up(&Magnifier_Semaphore);

#if(LiveZoom_PROFILE == 1)
	magnifierafter_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\nVSC rtk_hal_vsc_SetInputRegion time=%d ms\n",(magnifierafter_time -magnifierbefore_time));
#endif

	return TRUE;
}

unsigned char rtk_hal_vsc_GetOutputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * poutregion)
{
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN) || (wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	if(wid ==VIDEO_WID_0) {
		if ((DbgSclrFlgTkr.OutputVencMode || DbgSclrFlgTkr.OutputMemoryMode || DbgSclrFlgTkr.OutputAveMode || DbgSclrFlgTkr.OuputDisplayMode)) {
			poutregion->x = main_dispwin.srcx;
			poutregion->y = main_dispwin.srcy;
			poutregion->w = main_dispwin.src_wid;
			poutregion->h = main_dispwin.src_height;
#ifdef CONFIG_SDNR_CROP
#ifdef CONFIG_I2RND_ENABLE
			if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){
				poutregion->x = sub_dispwin.srcx;
				poutregion->y = sub_dispwin.srcy;
				poutregion->w = sub_dispwin.src_wid;
				poutregion->h = sub_dispwin.src_height;
			}
#endif
#endif
		} else {
			poutregion->x = 0;
			poutregion->y = 0;
			poutregion->w = 0;
			poutregion->h = 0;
		}
	} else if (wid ==VIDEO_WID_1) {
		if ((DbgSclrFlgTkr.Sub_OutputVencMode || DbgSclrFlgTkr.Sub_OutputMemoryMode || DbgSclrFlgTkr.Sub_OutputAveMode || DbgSclrFlgTkr.Sub_OuputDisplayMode)) {
			poutregion->x = sub_dispwin.srcx;
			poutregion->y = sub_dispwin.srcy;
			poutregion->w = sub_dispwin.src_wid;
			poutregion->h = sub_dispwin.src_height;
		} else {
			poutregion->x = 0;
			poutregion->y = 0;
			poutregion->w = 0;
			poutregion->h = 0;
		}

	}

	return TRUE;

}
unsigned char vo_overscan_disable(VSC_INPUT_TYPE_T srctype)
{
	VIDEO_RPC_VO_OVERSCAN_INFO overscan_info;
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	int ret = 0;
	if (srctype!=VSC_INPUTSRC_VDEC) {
		return 0;
	}
	if ((get_zoom_smoothtoggle_vo_hwid(SLR_MAIN_DISPLAY)!=Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE)) &&
		(get_zoom_smoothtoggle_vo_vlen(SLR_MAIN_DISPLAY)!=Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE))) {
			overscan_info.input_y=Main_InputRegion_y;
			overscan_info.input_h=Main_InputRegion_h;
			overscan_info.input_w=Main_InputRegion_w;
			overscan_info.input_x=Main_InputRegion_x;
			overscan_info.plane=Scaler_Get_CurVoInfo_VoVideoPlane(SLR_MAIN_DISPLAY);
			overscan_info.vo_source=Scaler_DispGetInputInfoByDisp(Get_DisplayMode_Port(SLR_MAIN_DISPLAY), SLR_INPUT_VO_SOURCE_TYPE);
			overscan_info.vo_overscan_enable=0;
			pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SEND_VO_OVERSCAN_INFO);
			ulCount = sizeof(VIDEO_RPC_VO_OVERSCAN_INFO) / sizeof(unsigned int);

			// copy to RPC share memory
			memcpy(pulDataTemp, &overscan_info, sizeof(VIDEO_RPC_VO_OVERSCAN_INFO));

			for (i = 0; i < ulCount; i++)
				pulDataTemp[i] = Scaler_ChangeUINT32Endian(pulDataTemp[i]);

			if (0 != (ret = Scaler_SendRPC(SCALERIOC_SEND_VO_OVERSCAN_INFO,0,0)))//add 0,0 to fix compile error
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "ret=%d, send VO's overscan info to driver fail !!!\n", ret);
			}
			return 1;
	}
	return 0;
}
unsigned char vo_overscan_adjust(VSC_INPUT_TYPE_T srctype)
{
	unsigned int v_len,interlace;
	VIDEO_RPC_VO_OVERSCAN_INFO overscan_info;
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	unsigned char ch = Scaler_Get_CurVoInfo_plane();
	int ret = 0;
	if (srctype!=VSC_INPUTSRC_VDEC) {
		return 0;
	}
	if ((Scaler_DispWindowGet().src_height == _DISP_LEN)&&(Get_VO_Dispinfo(ch)->IPH_ACT_WID_PRE >= 3000)&&(Get_VO_Dispinfo(ch)->IVFreq>310)) {
		if ((Get_VO_Dispinfo(ch)->disp_status&_BIT8)>>8) { // interlace
			v_len=(Get_VO_Dispinfo(ch)->IPV_ACT_LEN_PRE<<1);
			interlace=1;
		} else {
			v_len=Get_VO_Dispinfo(ch)->IPV_ACT_LEN_PRE;
			interlace=0;
		}
		if ((Main_InputRegion_h<v_len)||(Main_InputRegion_y>0)) {
			set_vo_change_flag(ch, FALSE);
			if (interlace) {
				overscan_info.input_y=Main_InputRegion_y/2;
			} else {
				overscan_info.input_y=Main_InputRegion_y;
			}
			if (Main_InputRegion_h>v_len) {
				overscan_info.input_h=v_len;
			} else {
				overscan_info.input_h=Main_InputRegion_h;
			}
			if (Main_InputRegion_w>Get_VO_Dispinfo(ch)->IPH_ACT_WID_PRE) {
				overscan_info.input_w=Get_VO_Dispinfo(ch)->IPH_ACT_WID_PRE;
			} else {
				overscan_info.input_w=Main_InputRegion_w;
			}
			overscan_info.input_x=Main_InputRegion_x;
			overscan_info.plane=Scaler_Get_CurVoInfo_VoVideoPlane(SLR_MAIN_DISPLAY);
			overscan_info.vo_source=Scaler_DispGetInputInfoByDisp(Get_DisplayMode_Port(SLR_MAIN_DISPLAY), SLR_INPUT_VO_SOURCE_TYPE);
			overscan_info.vo_overscan_enable=1;
			pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SEND_VO_OVERSCAN_INFO);
			ulCount = sizeof(VIDEO_RPC_VO_OVERSCAN_INFO) / sizeof(unsigned int);

			// copy to RPC share memory
			memcpy(pulDataTemp, &overscan_info, sizeof(VIDEO_RPC_VO_OVERSCAN_INFO));

			for (i = 0; i < ulCount; i++)
				pulDataTemp[i] = Scaler_ChangeUINT32Endian(pulDataTemp[i]);

			if (0 != (ret = Scaler_SendRPC(SCALERIOC_SEND_VO_OVERSCAN_INFO,0,0)))//add 0,0 to fix compile error
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "ret=%d, send VO's overscan info to driver fail !!!\n", ret);
			}
			return 1;
		}
	}
	return 0;
}

static VSC_SUB_PURPOSE_T VSC_SUB_PURPOSE = VSC_SUB_PURPOSE_NONE;

void Set_Magnifier_LiveZoom_Mode(VSC_SUB_PURPOSE_T value)
{
	VSC_SUB_PURPOSE = value;
}

VSC_SUB_PURPOSE_T Get_Magnifier_LiveZoom_Mode(void)
{

#if 0
	unsigned int source_width;
	unsigned int source_lenth;
	VIDEO_RECT_T inregion;
	rtk_hal_vsc_GetInputRegion(VIDEO_WID_1, &inregion);

	if (Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_INTERLACE))
		source_lenth = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)*2;
	else
		source_lenth = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE);

	source_width = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);

	source_width = source_width*9/10;/*after 90% just scan size*/
	source_lenth = source_lenth*9/10;/*after 90% just scan size*/

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "after 90% just scan size:source_width=%d;source_lenth=%d!!!\n", source_width,source_lenth);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "webos input_width=%d;input_lenth=%d!!!\n", inregion.w, inregion.h);

	if ((inregion.w>=source_width)&&( inregion.h>=source_lenth))
		return PIP_LIVEZOOM;
	else
		return PIP_MAGNIFIER;
#else

	return VSC_SUB_PURPOSE;
#endif
}

unsigned char get_livezoomode_forvideofw(void)
{
	if(Get_Live_zoom_mode()==LIVE_ZOOM_OFF)
		return FALSE;
	else
		return TRUE;
}

unsigned char magnifier_voinfo_wait(unsigned char channel)
{
	/*wait new vo ready info*/
	if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH)
	{
		VSC_INPUT_TYPE_T srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);
		if (srctype == VSC_INPUTSRC_VDEC) {
			unsigned int timeout;

			if(DbgSclrFlgTkr.LivezoomvoinfocheckFlag == FALSE) {
				timeout = 200;
				DbgSclrFlgTkr.LivezoomvoinfocheckFlag = TRUE;
			} else {
				timeout = 20;
			}
			unsigned char port = Get_DisplayMode_Port(SLR_MAIN_DISPLAY);
			while (timeout) {
				#if 0
				if(DbgSclrFlgTkr.Main_Scaler_Stop_flag) {
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####VO already disconnet#####\r\n");
					break;
				}
				#endif
				if(get_vo_change_flag(port)) {
					break;
				}
				msleep(10);
				timeout--;
			}
			if (timeout ==0) {
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "[magnifier]#####happen####timeout = %d##########Function:%s;;Line:%d\n",timeout,__FUNCTION__,__LINE__);
				return FALSE;
			}
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "[magnifier]#########timeout = %d##########Function:%s;;Line:%d\n",timeout,__FUNCTION__,__LINE__);
                	unsigned char inputPort = 0;
                	if(DisplayModeInputInfo.type != VSC_INPUTSRC_MAXN)
                	{
                		inputPort = DisplayModeInputInfo.resourceIndex;
                	}
                	else if(VencModeInputInfo.type != VSC_INPUTSRC_MAXN)
                	{
                		inputPort = VencModeInputInfo.resourceIndex;
                	}
                	else if(MemoryModeInputInfo.type != VSC_INPUTSRC_MAXN)
                	{
                		inputPort = MemoryModeInputInfo.resourceIndex;
                	}
                        Scaler_SET_VSCDispinfo_WithVFEDispinfo(SLR_MAIN_DISPLAY, Get_VO_Dispinfo(inputPort));
		}
	}
	return TRUE;
}

unsigned char magnifier_mainscaler_run(unsigned char channel, VSC_INPUT_TYPE_T srctype, VIDEO_RECT_T outregion)
{
	int timeout = 50;
	/*re run main scaler start*/
	StructSrcRect magnifiermaininputsize;
	rtk_hal_vsc_GetInputRegion(VIDEO_WID_0, &magnifiermaininputsize);
	main_input_size.srcx = 0;//no overscan
	main_input_size.srcy = 0;//no overscan
	main_input_size.src_wid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);//no overscan
	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE))//interlace timing
		main_input_size.src_height = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) << 1;//no overscan
	else
		main_input_size.src_height = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE);//no overscan
#if 0
	printk("\n *********************magnifier_mainscaler_run    channel = %d !", channel);
	printk("\n *********************magnifier_mainscaler_run    SLR_DISP_INTERLACE = %d !", Scaler_DispGetStatus(channel, SLR_DISP_INTERLACE));
	printk("\n *********************magnifier_mainscaler_run    SLR_INPUT_IPH_ACT_STA = %d !", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA));
	printk("\n *********************magnifier_mainscaler_run    SLR_INPUT_IPV_ACT_STA = %d !", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA));
	printk("\n *********************magnifier_mainscaler_run    SLR_INPUT_IPH_ACT_WID = %d !", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
	printk("\n *********************magnifier_mainscaler_run    SLR_INPUT_IPV_ACT_LEN = %d !", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN));
	printk("\n *********************magnifier_mainscaler_run    main_input_size.srcx = %d !", main_input_size.srcx);
	printk("\n *********************magnifier_mainscaler_run    main_input_size.srcy = %d !", main_input_size.srcy);
	printk("\n *********************magnifier_mainscaler_run    main_input_size.src_height = %d !", main_input_size.src_height);
	printk("\n *********************magnifier_mainscaler_run    main_input_size.src_wid = %d !", main_input_size.src_wid);
#endif
	set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, TRUE);
	down(get_forcebg_semaphore());
	scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
	up(get_forcebg_semaphore());

	if(SLR_MAIN_DISPLAY == channel)
		Share_Memory_Set_Scaler_Run_Flag(1);
	//Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH); //Remove by Will
	down(&SetMainOutPutRegion_Semaphore);
	#if 0
	if(align8byte == TRUE) {
		Main_InputRegion_x = drvif_memory_get_data_align(Main_InputRegion_x, 0x04);
		Main_InputRegion_w = drvif_memory_get_data_align(Main_InputRegion_w, 0x04);
		if ((Main_InputRegion_x  + Main_InputRegion_w) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE)) {
			Main_InputRegion_w = Main_InputRegion_w -4;
		}
	}
	#endif
	if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
		main_dispwin.srcx = 0;
		main_dispwin.srcy = 0;
		main_dispwin.src_height = _DISP_LEN;
		main_dispwin.src_wid = _DISP_WID;
	} else {
		main_dispwin.srcx = outregion.x;
		main_dispwin.srcy = outregion.y;
		main_dispwin.src_height = outregion.h;
		main_dispwin.src_wid = outregion.w;
	}

	Scaler_DispWindowSet(main_dispwin);

	up(&SetMainOutPutRegion_Semaphore);
#if 0/*disable vo overscan for need magnifier and livezoom all input size*/
	/*if (DataFramesynclivezoom == TRUE) */{
		if (vo_overscan_disable(srctype)) {
			msleep(20);
			timeout = 50;
			while (timeout--) {
				if(get_vo_change_flag(Get_DisplayMode_Port(SLR_MAIN_DISPLAY))) {
					break;
				}
				msleep(10);
			}
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s disable VO overscan case. timeout:%d#####\r\n", __FUNCTION__, timeout);
		}
	}
#endif

	//[WOSQRTK-9641] When change to ATV, main path will force i3ddma scaler flow
	if ((srctype == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV)
		&&((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH)
	#ifdef CONFIG_FORCE_RUN_I3DDMA
		||(get_force_i3ddma_enable(SLR_MAIN_DISPLAY) == 0)
	#endif
		)){
		unsigned char port;
		down(&Force_Run_Idma_Semaphore);
	#ifdef CONFIG_FORCE_RUN_I3DDMA
		set_force_i3ddma_enable(TRUE);		// clear i3ddma flag
	#endif
		ATV_forcei3ddma = 1;	//	ATV will force i3ddma scaler flow
	#ifdef CONFIG_FORCE_RUN_I3DDMA
		unsigned char check_Flag = scaler_atv_force_run_idma();
	#else
		unsigned char check_Flag = 0;
	#endif
		ATV_forcei3ddma = 0;

		if(check_Flag) {
			up(&Force_Run_Idma_Semaphore);

#ifdef CONFIG_I2RND_ENABLE
          //for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823
          if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_TRIGGER_RUN_MAIN)){
           vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_I3DDMA_RPC;
           //printk(KERN_EMERG"[%s][%d]vsc_i2rnd_main_rerun_stage = %d!!!!\n",__FUNCTION, LINE__, vsc_i2rnd_atv_main_rerun_stage);
          }
#endif
          rtd_printk(KERN_EMERG, TAG_NAME_VSC, "\r\n####Go ATV VO case. timeout:%d#####\r\n", timeout);

         } else {
          if(!DbgSclrFlgTkr.Main_Scaler_Stop_flag) {
           	Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_HDMI, 0xfa);	// desconnect vo
          }
          up(&Force_Run_Idma_Semaphore);
         }

        }

	down(&VSC_Semaphore);
	DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;

	if (Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VO) {
		DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;
	}

#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE //update rotate info
	set_ori_rotate_mode(get_rotate_mode());
	set_rotate_mode(rotate_mode);
#endif

	rtk_output_connect(SLR_MAIN_DISPLAY);
	if (LiveZoom_MEMCClose_Flag == TRUE) {
		down(get_livezoom_memcclose_Semaphore());
		LiveZoom_MEMCClose_Flag = FALSE;
		up(get_livezoom_memcclose_Semaphore());
		memc_setting_displayDtiming_framerate();
	}
	main_input_size.srcx = magnifiermaininputsize.srcx;
	main_input_size.srcy = magnifiermaininputsize.srcy;
	main_input_size.src_wid = magnifiermaininputsize.src_wid;
	main_input_size.src_height = magnifiermaininputsize.src_height;

	up(&VSC_Semaphore);
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
	return TRUE;
}

extern void send_vo_freeze_shiftxy_share_memory(void);
unsigned char check_only_xy_shift_case(unsigned char display, StructSrcRect *input, StructSrcRect *output)
{
	VSC_INPUT_TYPE_T srctype;

         if(input->src_wid != main_input_size.src_wid || input->src_height != main_input_size.src_height
         || output->srcx != main_dispwin.srcx || output->srcy != main_dispwin.srcy
         || output->src_wid != main_dispwin.src_wid || output->src_height != main_dispwin.src_height)
         {
                   input->srcx = main_input_size.srcx;
                   input->srcy = main_input_size.srcy;
                   input->src_wid = main_input_size.src_wid;
                   input->src_height = main_input_size.src_height;
                   output->srcx = main_dispwin.srcx;
                   output->srcy = main_dispwin.srcy;
                   output->src_wid = main_dispwin.src_wid;
                   output->src_height = main_dispwin.src_height;
                   DbgSclrFlgTkr.check_only_xy_shift_same_region = FALSE;
                   return FALSE;
         }
         else
         {
                   // all region are the same, just run apply_only_xy_shift, but do nothing
                   if(input->srcx == main_input_size.srcx && input->srcy == main_input_size.srcy)
                   {
                            DbgSclrFlgTkr.check_only_xy_shift_same_region = TRUE;
                            return TRUE;
                   }

                   input->srcx = main_input_size.srcx;
                   input->srcy = main_input_size.srcy;
                   input->src_wid = main_input_size.src_wid;
                   input->src_height = main_input_size.src_height;
                   output->srcx = main_dispwin.srcx;
                   output->srcy = main_dispwin.srcy;
                   output->src_wid = main_dispwin.src_wid;
                   output->src_height = main_dispwin.src_height;
                   DbgSclrFlgTkr.check_only_xy_shift_same_region = FALSE;
                   srctype = Get_DisplayMode_Src(display);
                   if(srctype == VSC_INPUTSRC_VDEC)	{
					   if ((!DbgSclrFlgTkr.Main_smooth_toggle_set_flag) && (!DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off)) {// && (!DbgSclrFlgTkr.smoothtoggle_start_flag)) {
							if (!DbgSclrFlgTkr.smoothtoggle_start_flag) {
								 send_vo_freeze_shiftxy_share_memory();
		                           			 return TRUE;
							} else {
								//wait
								unsigned int timeout = 15;

								while((DbgSclrFlgTkr.Main_smooth_toggle_set_flag || DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off || DbgSclrFlgTkr.smoothtoggle_start_flag) && timeout)
								{
									timeout--;
									msleep(10);
								}

								if(!timeout){
									rtd_printk(KERN_INFO, TAG_NAME_VSC, "shiftxf wait smoothtoogh timeout !\n");
									return FALSE;
								}else{
									send_vo_freeze_shiftxy_share_memory();
									return TRUE;
								}
							}
						} else {
							return FALSE;
						}
				 } else {
					return FALSE;
				 }
         }
}


void apply_only_xy_shift(unsigned char display, StructSrcRect input, StructSrcRect output)
{
	int timeout = 30;
	unsigned char src = Scaler_InputSrcGetType(display);
	VSC_INPUT_TYPE_T srctype = Get_DisplayMode_Src(display);


	// all region are the same, just run apply_only_xy_shift, but do nothing
	if(DbgSclrFlgTkr.check_only_xy_shift_same_region == TRUE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "apply_only_xy_shift do nothing\n");
		return;
	}

#if defined(CONFIG_SMOOTH_TOOGLE_AT_VO_FREEZE)
	//send_vo_freeze_shiftxy_share_memory();
#endif

#ifndef CONFIG_SDNR_CROP// for VGIP overscan
	unsigned int hstart = 0;
	unsigned int vstart = 0;
	vgip_vgip_chn1_ctrl_RBUS vgip_chn1_ctrl_reg;
	vgip_vgip_chn1_act_hsta_width_RBUS vgip_chn1_act_hsta_width_reg;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_length_reg;
	vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	while(vgip_chn1_act_hsta_width_reg.ch1_db_rdy && vgip_chn1_act_hsta_width_reg.ch1_db_en)
	{
		timeout --;
		mdelay(1); /*wait 1ms 30 counts for vsync */
		if(!timeout) break;
		vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	}

	if (Scaler_DispGetStatus(display, SLR_DISP_INTERLACE)) {
		hstart = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_STA_PRE) + input.srcx;
		vstart = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA_PRE) + input.srcy/2;
	} else {
		hstart = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_STA_PRE) + input.srcx;
		vstart = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA_PRE) + input.srcy;
	}

	if ((src == _SRC_HDMI) || (src == _SRC_VO)) {
		//if color space is 422 format, it should be even number. @ Crixus
		if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_COLOR_SPACE) == COLOR_YUV422){
			if((hstart%2) != (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_IPH_ACT_STA_PRE)%2))
				hstart = hstart - 1;//This means that shift value need even
		}
	}
	vgip_chn1_ctrl_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_CTRL_reg);
	vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	vgip_chn1_act_hsta_width_reg.ch1_db_en = 1;
	vgip_chn1_act_hsta_width_reg.ch1_db_rdy = 0;
	IoReg_Write32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg,vgip_chn1_act_hsta_width_reg.regValue);

	vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	if(vgip_chn1_ctrl_reg.ch1_digital_mode)
		vgip_chn1_act_hsta_width_reg.ch1_ih_act_sta = hstart - Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_STA_PRE);
	else
		vgip_chn1_act_hsta_width_reg.ch1_ih_act_sta = hstart;
	IoReg_Write32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg, vgip_chn1_act_hsta_width_reg.regValue);
	vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
	if(vgip_chn1_ctrl_reg.ch1_digital_mode)
		vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta = vstart - Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_STA_PRE);
	else
		vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta = vstart;
	IoReg_Write32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg, vgip_chn1_act_vsta_length_reg.regValue);


	vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	vgip_chn1_act_hsta_width_reg.ch1_db_rdy = 1;
	IoReg_Write32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg,vgip_chn1_act_hsta_width_reg.regValue);
#else
//for SDNR overscan
	scaledown_ich1_uzd_db_ctrl_RBUS ich1_uzd_db_ctrl_reg;
	scaledown_ich1_sdnr_cutout_range_hor_RBUS ich1_sdnr_cutout_range_hor_reg;
	scaledown_ich1_sdnr_cutout_range_ver0_RBUS ich1_sdnr_cutout_range_ver0_reg;
	scaledown_ich1_sdnr_cutout_range_ver1_RBUS ich1_sdnr_cutout_range_ver1_reg;
	StructSrcRect SDNR_size = input;
	int mid = 0;
#if 0
	printk("========input size============\n");
	printk("x:%d,y:%d,wid:%d,len:%d\n",input.srcx,input.srcy,input.src_wid,input.src_height);
	printk("========output size============\n");
	printk("x:%d,y:%d,wid:%d,len:%d\n",output.srcx,output.srcy,output.src_wid,output.src_height);
	printk("===============================\n");
#endif
	SDNR_size = drvif_cal_SDNR_size(display,input,output);
#if 0
	printk("############SDNR size#############\n");
	printk("x:%d,y:%d,wid:%d,len:%d\n",SDNR_size.srcx,SDNR_size.srcy,SDNR_size.src_wid,SDNR_size.src_height);
	printk("################################\n");
#endif
#ifdef CONFIG_I2RND_ENABLE
	if (!Scaler_I2rnd_get_enable())
#endif
	{
		ich1_uzd_db_ctrl_reg.regValue =IoReg_Read32(SCALEDOWN_ICH1_UZD_DB_CTRL_reg);
		while(ich1_uzd_db_ctrl_reg.h_db_en && ich1_uzd_db_ctrl_reg.v_db_en && ich1_uzd_db_ctrl_reg.v_db_apply)
		{
			timeout --;
			mdelay(1); /*wait 1ms 30 counts for vsync */
			if(!timeout) break;
			ich1_uzd_db_ctrl_reg.regValue = IoReg_Read32(SCALEDOWN_ICH1_UZD_DB_CTRL_reg);
		}
		if(timeout == 0) printk("uzd aplly time out !!! :%d\n",timeout);
		//uzu double buffer enbale
		ich1_uzd_db_ctrl_reg.regValue =IoReg_Read32(SCALEDOWN_ICH1_UZD_DB_CTRL_reg);
		ich1_uzd_db_ctrl_reg.h_db_en=1;
		ich1_uzd_db_ctrl_reg.h_db_apply=0;
		ich1_uzd_db_ctrl_reg.v_db_en=1;
		ich1_uzd_db_ctrl_reg.v_db_apply=0;
		IoReg_Write32(SCALEDOWN_ICH1_UZD_DB_CTRL_reg,ich1_uzd_db_ctrl_reg.regValue);
	}
	ich1_sdnr_cutout_range_hor_reg.regValue = IoReg_Read32(SCALEDOWN_ich1_sdnr_cutout_range_hor_reg);
	ich1_sdnr_cutout_range_hor_reg.hor_front = SDNR_size.srcx;
	ich1_sdnr_cutout_range_hor_reg.hor_back = SDNR_size.src_wid + SDNR_size.srcx + 1; // chip setting need to +1
	IoReg_Write32(SCALEDOWN_ich1_sdnr_cutout_range_hor_reg, ich1_sdnr_cutout_range_hor_reg.regValue);

	ich1_sdnr_cutout_range_ver0_reg.regValue = IoReg_Read32(SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg);
	ich1_sdnr_cutout_range_ver0_reg.ver_front = SDNR_size.srcy;
	ich1_sdnr_cutout_range_ver0_reg.ver_back = SDNR_size.src_height + SDNR_size.srcy + 1;// chip setting need to +1
	IoReg_Write32(SCALEDOWN_ich1_sdnr_cutout_range_ver0_reg, ich1_sdnr_cutout_range_ver0_reg.regValue);

	mid = ich1_sdnr_cutout_range_ver0_reg.ver_back;
	ich1_sdnr_cutout_range_ver1_reg.regValue = IoReg_Read32(SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg);
	ich1_sdnr_cutout_range_ver1_reg.ver_mid_top = mid;
	ich1_sdnr_cutout_range_ver1_reg.ver_mid_bot = mid - 1;
	IoReg_Write32(SCALEDOWN_ich1_sdnr_cutout_range_ver1_reg, ich1_sdnr_cutout_range_ver1_reg.regValue);

	scaledown_ich1_uzd_ctrl0_RBUS 	ich1_uzd_Ctrl0_REG;
	ich1_uzd_Ctrl0_REG.regValue = IoReg_Read32(SCALEDOWN_ICH1_UZD_Ctrl0_reg);
	ich1_uzd_Ctrl0_REG.cutout_en = 1;
	IoReg_Write32(SCALEDOWN_ICH1_UZD_Ctrl0_reg, ich1_uzd_Ctrl0_REG.regValue);
#ifdef CONFIG_I2RND_ENABLE
	if (!Scaler_I2rnd_get_enable())
#endif
	{
		//uzu double buffer apply
		ich1_uzd_db_ctrl_reg.regValue =IoReg_Read32(SCALEDOWN_ICH1_UZD_DB_CTRL_reg);
		ich1_uzd_db_ctrl_reg.h_db_apply=1;
		ich1_uzd_db_ctrl_reg.v_db_apply=1;
		IoReg_Write32(SCALEDOWN_ICH1_UZD_DB_CTRL_reg,ich1_uzd_db_ctrl_reg.regValue);
	}
#endif

	//KTASKWBS-5348  move update info after execution
	if(srctype == VSC_INPUTSRC_VDEC)
		zoom_record_input_output_pre_size(display,main_input_size,main_dispwin);


}

void Scaler_data_frc_fs_change_adjust_outputregion(unsigned char display,unsigned short disp_height)
{
	return; //k3l always go data frc
#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if(!vbe_disp_get_adaptivestream_fs_mode())
#endif
	{
		if (!vsc_get_adaptivestream_flag()) {
			if(Get_vo_smoothtoggle_timingchange_flag(display) ||(get_HDMI_HDR_mode() ==HDR_DOLBY_HDMI) || (get_HDMI_HDR_mode() ==HDR_HDR10_HDMI)) {
					if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_FRAMESYNC)) {
						if ((drvif_HDR_get_VO_Decompress_Status()==TRUE) || (get_vo_vp9_flag(Get_DisplayMode_Port(display)))) {
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(display, TRUE);
							up(get_forcebg_semaphore());
							Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							down(&SetMainOutPutRegion_Semaphore);
							DbgSclrFlgTkr.Main_force_frc_flag = TRUE;
							reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
							up(&SetMainOutPutRegion_Semaphore);
						} else {
							if(Get_display_forcebg_mask(display,SLR_FORCE_BG_TYPE_VSC)) {
								if ((disp_height!=_DISP_LEN) ||(main_input_size.src_wid!=Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPH_ACT_WID_PRE))||(main_input_size.src_height!=Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE))) {
									DbgSclrFlgTkr.Main_force_frc_fs_flag = TRUE;
									Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
									down(&SetMainOutPutRegion_Semaphore);
									reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
									up(&SetMainOutPutRegion_Semaphore);
								}
							}
						}
					} else {
						if(Get_display_forcebg_mask(display,SLR_FORCE_BG_TYPE_VSC)) {
							if (drvif_HDR_get_VO_Decompress_Status()==FALSE) {
								if ((Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPH_ACT_WID_PRE)>=3000)&&(Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_V_FREQ)>310))
								{
									if((disp_height==_DISP_LEN)&&(main_input_size.src_wid==Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPH_ACT_WID_PRE))&&(main_input_size.src_height==Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE))) {
										DbgSclrFlgTkr.Main_force_frc_fs_flag = TRUE;
										Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
										down(&SetMainOutPutRegion_Semaphore);
										reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
										up(&SetMainOutPutRegion_Semaphore);
									}
								}
							}
						}
					}
				//}
			} else {//DTV flow
				if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_FRAMESYNC)) {
					if (drvif_HDR_get_VO_Decompress_Status()==TRUE) {
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(display, TRUE);
						up(get_forcebg_semaphore());
						Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
						down(&SetMainOutPutRegion_Semaphore);
						DbgSclrFlgTkr.Main_force_frc_flag = TRUE;
						reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
						up(&SetMainOutPutRegion_Semaphore);
					} else {
						if (Get_display_forcebg_mask(display,SLR_FORCE_BG_TYPE_VSC)) {
							if ((disp_height!=_DISP_LEN) ||(main_input_size.src_wid!=Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPH_ACT_WID_PRE))||(main_input_size.src_height!=Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE))) {
								Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
								down(&SetMainOutPutRegion_Semaphore);
								DbgSclrFlgTkr.Main_force_frc_flag = TRUE;
								reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
								up(&SetMainOutPutRegion_Semaphore);
							}
						}
					}
				}
			}
		}
	}
}
unsigned char Scaler_data_frc_fs_change_adjust_after_scaler(unsigned char display,unsigned short disp_height)
{
	return TRUE; //k3l always go data frc
	if (Scaler_InputSrcGetType(display) == _SRC_VO) {
#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if(!vbe_disp_get_adaptivestream_fs_mode())
#endif
	{
		if(!vsc_get_adaptivestream_flag() && (Get_vo_smoothtoggle_timingchange_flag(display) || (get_HDMI_HDR_mode() ==HDR_DOLBY_HDMI) || (get_HDMI_HDR_mode() ==HDR_HDR10_HDMI))) {
			if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_FRAMESYNC)) {
				if (drvif_HDR_get_VO_Decompress_Status()==TRUE) {
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(display, TRUE);
					up(get_forcebg_semaphore());
					if(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) {
						DbgSclrFlgTkr.Main_force_frc_flag = TRUE;
					}
					Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
					reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
					return FALSE;
				} else {
					if ((disp_height!=_DISP_LEN) ||(main_input_size.src_wid!=Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPH_ACT_WID_PRE))||(main_input_size.src_height!=Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE))) {
						DbgSclrFlgTkr.Main_force_frc_fs_flag = TRUE;
						Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
						reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
						return FALSE;
					}
				}
			} else {
				if (drvif_HDR_get_VO_Decompress_Status()==FALSE) {
					if ((Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPH_ACT_WID_PRE)>=3000)&&(Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_V_FREQ)>310))
					{
						if((disp_height==_DISP_LEN)&&(main_input_size.src_wid==Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPH_ACT_WID_PRE))&&(main_input_size.src_height==Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE))) {
							DbgSclrFlgTkr.Main_force_frc_fs_flag = TRUE;
							Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
							return FALSE;
						}
					}
				}
			}
		}
	}
	}
	return TRUE;
}

extern unsigned char drvif_module_vdc_Read_Vstate(void);
extern void drvif_module_vdc_CheckInputStatus(unsigned char ucInputSrc, unsigned char ucCheckStart);
extern unsigned char drvif_HDR_get_VO_Decompress_Status(void);

unsigned char  CompareATVOutputRegion(unsigned char a_ucChannel, VIDEO_RECT_T *a_ptOutputregion)
{
	if (SLR_MAIN_DISPLAY == a_ucChannel)
	{

		if (DbgSclrFlgTkr.Main_ATV_OutputRegion_x_pre == a_ptOutputregion->x
			&& DbgSclrFlgTkr.Main_ATV_OutputRegion_y_pre == a_ptOutputregion->y
			&& DbgSclrFlgTkr.Main_ATV_OutputRegion_w_pre == a_ptOutputregion->w
			&& DbgSclrFlgTkr.Main_ATV_OutputRegion_h_pre == a_ptOutputregion->h
		)
		{
			return TRUE;
		}
	}
	else
	{
		if (DbgSclrFlgTkr.Sub_ATV_OutputRegion_x_pre == a_ptOutputregion->x
			&& DbgSclrFlgTkr.Sub_ATV_OutputRegion_y_pre == a_ptOutputregion->y
			&& DbgSclrFlgTkr.Sub_ATV_OutputRegion_w_pre == a_ptOutputregion->w
			&& DbgSclrFlgTkr.Sub_ATV_OutputRegion_h_pre == a_ptOutputregion->h
		)
		{
			return TRUE;
		}
	}

	return FALSE;
}


unsigned char  CompareATVInputOutputRegion(unsigned char a_ucChannel, VIDEO_RECT_T *a_ptOutputregion, VIDEO_RECT_T *a_ptInputRegion)
{
	if (SLR_MAIN_DISPLAY == a_ucChannel)
	{
		if (DbgSclrFlgTkr.Main_ATV_OutputRegion_x_pre == a_ptOutputregion->x
			&& DbgSclrFlgTkr.Main_ATV_OutputRegion_y_pre == a_ptOutputregion->y
			&& DbgSclrFlgTkr.Main_ATV_OutputRegion_w_pre == a_ptOutputregion->w
			&& DbgSclrFlgTkr.Main_ATV_OutputRegion_h_pre == a_ptOutputregion->h
			&& DbgSclrFlgTkr.Main_ATV_InputRegion_x_pre == a_ptInputRegion->x
			&& DbgSclrFlgTkr.Main_ATV_InputRegion_y_pre == a_ptInputRegion->y
			&& DbgSclrFlgTkr.Main_ATV_InputRegion_w_pre == a_ptInputRegion->w
			&& DbgSclrFlgTkr.Main_ATV_InputRegion_h_pre == a_ptInputRegion->h
		)
		{
			return TRUE;
		}
	}
	else
	{
		if (DbgSclrFlgTkr.Sub_ATV_OutputRegion_x_pre == a_ptOutputregion->x
			&& DbgSclrFlgTkr.Sub_ATV_OutputRegion_y_pre == a_ptOutputregion->y
			&& DbgSclrFlgTkr.Sub_ATV_OutputRegion_w_pre == a_ptOutputregion->w
			&& DbgSclrFlgTkr.Sub_ATV_OutputRegion_h_pre == a_ptOutputregion->h
			&& DbgSclrFlgTkr.Sub_ATV_InputRegion_x_pre == a_ptInputRegion->x
			&& DbgSclrFlgTkr.Sub_ATV_InputRegion_y_pre == a_ptInputRegion->y
			&& DbgSclrFlgTkr.Sub_ATV_InputRegion_w_pre == a_ptInputRegion->w
			&& DbgSclrFlgTkr.Sub_ATV_InputRegion_h_pre == a_ptInputRegion->h
		)
		{
			return TRUE;
		}
	}

	return FALSE;
}

unsigned char uc4_get_main_dispwin_value(unsigned short *x, unsigned short *y, unsigned short *w, unsigned short *h)	//WOSQRTK-7731
{
	if((x !=NULL)&&(y !=NULL)&&(w !=NULL)&&(h !=NULL))
	{
		*x = main_dispwin.srcx;
		*y = main_dispwin.srcy;
		*w = main_dispwin.src_wid;
		*h = main_dispwin.src_height;
	}
	else
		return 1;
	return 0;
}

void set_vsc_SetCircle_OutputRegion(VIDEO_RECT_T outregion, unsigned short W, unsigned short H, UINT32 num)
{
#if 0//MAc5p no these setting of sub shape

	//pr_debug("rtk_hal_vsc_SetOutputRegion  x=%d, y=%d, w=%d, h=%d \n", outregion.x, outregion.y, outregion.w, outregion.h);

	//pr_debug("\n ********************* Sub_circle_center_h = %d ", outregion.x+(outregion.w/2));
	//pr_debug("\n ********************* Sub_circle_center_v = %d ", outregion.y+(outregion.h/2));
	//pr_debug("\n ********************* Sub_act_rad_a = %d ", (outregion.w/2 * outregion.w/2));
	//pr_debug("\n ********************* Sub_act_rad_b = %d ", (outregion.h/2 * outregion.h/2));

	SUB_Active_Red_A_RBUS           SUB_Active_Red_A_reg;
	SUB_Active_Red_B_RBUS           SUB_Active_Red_B_reg;
	SUB_Circle_center_RBUS		SUB_Circle_center_reg;
	int	Circle_x=0, Circle_y=0, Circle_w=0, Circle_h=0;

	if (num>= 2)
		return;

	unsigned short temp_w=0, temp_h=0;
	unsigned short true_w=0, true_h=0;

	if (outregion.w%2==0)
		temp_w = (outregion.w-1)/2;
	else
		temp_w = (outregion.w)/2;
	true_w = temp_w;

	if (outregion.h%2==0)
		temp_h = (outregion.h-1)/2;
	else
		temp_h = (outregion.h)/2;
	true_h = temp_h;

	if (num == 1)
	{
		if (W%2==0)
			temp_w = (W-1);
		else
			temp_w = (W);

		if (H%2==0)
			temp_h = (H-1);
		else
			temp_h = (H);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 0.SLR_INPUT_DISP_WID=%d ", Scaler_DispGetInputInfoByDisp(1, SLR_INPUT_DISP_WID));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 0.SLR_INPUT_DISP_LEN=%d ", Scaler_DispGetInputInfoByDisp(1, SLR_INPUT_DISP_LEN));
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 1.set_vsc_OutputRegion  x=%d, y=%d, w=%d, h=%d ", outregion.x, outregion.y, outregion.w, outregion.h);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 2.virtual_w=%d, virtual_h=%d ", W, H);

	if ((outregion.x== 0) && (outregion.y== 0) && (outregion.w >= W) && (outregion.h >= H))
	{
		Circle_x = (int)(outregion.x + outregion.w - W);
		Circle_y = (int)(outregion.y + outregion.h - H);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 3.set_vsc_SetCircleRegion  x=%d, y=%d, w=%d, h=%d ", Circle_x, Circle_y, Circle_w, Circle_h);
	}
	else if ((outregion.x== 0) && (outregion.w >= W) && (outregion.h/2 <=  H))
	{
		Circle_x = (int)(outregion.x + outregion.w - W);
		Circle_y = (int)(outregion.y + H);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 4.set_vsc_SetCircleRegion  x=%d, y=%d, w=%d, h=%d ", Circle_x, Circle_y, Circle_w, Circle_h);
	}
	else if ( (outregion.y== 0) && (outregion.w >= W) && (outregion.h >= H))
	{
		Circle_x = (int)(outregion.x + W);
		Circle_y = (int)(outregion.y + outregion.h - H);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 5.set_vsc_SetCircleRegion  x=%d, y=%d, w=%d, h=%d ", Circle_x, Circle_y, Circle_w, Circle_h);
	}
	else if ( (outregion.y + outregion.h == 2160) && (outregion.h/2 < H))
	{
		Circle_x = (int)(outregion.x + W);
		Circle_y = (int)(outregion.y + H);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 6.set_vsc_SetCircleRegion  x=%d, y=%d, w=%d, h=%d ", Circle_x, Circle_y, Circle_w, Circle_h);
	}
	else if ( (outregion.x + outregion.w == 3840) && (outregion.w/2 < W))
	{
		Circle_x = (int)(outregion.x + W);
		Circle_y = (int)(outregion.y + H);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 7.set_vsc_SetCircleRegion  x=%d, y=%d, w=%d, h=%d ", Circle_x, Circle_y, Circle_w, Circle_h);
	}
	else
	{
		Circle_x = (int)(outregion.x + true_w);
		Circle_y = (int)(outregion.y + true_h);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n ***** 8.set_vsc_SetCircleRegion  x=%d, y=%d, w=%d, h=%d ", Circle_x, Circle_y, Circle_w, Circle_h);
	}

	SUB_Active_Red_A_reg.regValue     = IoReg_Read32(SUB_ACTIVE_RAD_A_reg);
	SUB_Active_Red_A_reg.sub_act_rad_a= (temp_w*temp_w);
	IoReg_Write32(SUB_ACTIVE_RAD_A_reg, SUB_Active_Red_A_reg.regValue);

	SUB_Active_Red_B_reg.regValue     = IoReg_Read32(SUB_ACTIVE_RAD_B_reg);
	SUB_Active_Red_B_reg.sub_act_rad_b= (temp_h * temp_h);
	IoReg_Write32(SUB_ACTIVE_RAD_B_reg, SUB_Active_Red_B_reg.regValue);

	SUB_Active_Red_A_reg.regValue     = IoReg_Read32(SUB_BACKGROUND_RAD_A_reg);
	SUB_Active_Red_A_reg.sub_act_rad_a= (temp_w*temp_w);
	IoReg_Write32(SUB_BACKGROUND_RAD_A_reg, SUB_Active_Red_A_reg.regValue);

	SUB_Active_Red_B_reg.regValue     = IoReg_Read32(SUB_BACKGROUND_RAD_B_reg);
	SUB_Active_Red_B_reg.sub_act_rad_b= (temp_h * temp_h);
	IoReg_Write32(SUB_BACKGROUND_RAD_B_reg, SUB_Active_Red_B_reg.regValue);

	SUB_Active_Red_A_reg.regValue     = IoReg_Read32(SUB_DEN_RAD_A_reg);
	SUB_Active_Red_A_reg.sub_act_rad_a= (temp_w*temp_w);
	IoReg_Write32(SUB_DEN_RAD_A_reg, SUB_Active_Red_A_reg.regValue);

	SUB_Active_Red_B_reg.regValue     = IoReg_Read32(SUB_DEN_RAD_B_reg);
	SUB_Active_Red_B_reg.sub_act_rad_b= (temp_h * temp_h);
	IoReg_Write32(SUB_DEN_RAD_B_reg, SUB_Active_Red_B_reg.regValue);

	if (num == 1)
	{
		SUB_Circle_center_reg.regValue     = IoReg_Read32(SUB_CIRCLE_CENTER_reg);
		SUB_Circle_center_reg.sub_circle_center_h= (Circle_x)*2;
		SUB_Circle_center_reg.sub_circle_center_v= (Circle_y)*2;
		SUB_Circle_center_reg.sub_window_form_sel= num;
		IoReg_Write32(SUB_CIRCLE_CENTER_reg, SUB_Circle_center_reg.regValue);
	}
	else
	{
	SUB_Circle_center_reg.regValue     = IoReg_Read32(SUB_CIRCLE_CENTER_reg);
	SUB_Circle_center_reg.sub_circle_center_h= (outregion.x+temp_w)*2;
	SUB_Circle_center_reg.sub_circle_center_v= (outregion.y+temp_h)*2;
	SUB_Circle_center_reg.sub_window_form_sel= num;
	IoReg_Write32(SUB_CIRCLE_CENTER_reg, SUB_Circle_center_reg.regValue);
	}
#endif
}

void set_vsc_SetMagnifire_shape(UINT32 num)
{
#if 0//MAc5p no these setting of sub shape

	SUB_Circle_center_RBUS		SUB_Circle_center_reg_shape;
	SUB_Circle_center_reg_shape.regValue     = IoReg_Read32(SUB_CIRCLE_CENTER_reg);

	if(num==1)
		SUB_Circle_center_reg_shape.sub_window_form_sel= 1;//Circle
	//else if(num==2) //no need in arrow
  	//	SUB_Circle_center_reg.sub_window_form_sel= 2; //arrow
	else
  		SUB_Circle_center_reg_shape.sub_window_form_sel= 0; //rectangle

  	IoReg_Write32(SUB_CIRCLE_CENTER_reg, SUB_Circle_center_reg_shape.regValue);
#endif
}


unsigned char rtk_hal_vsc_SetOutputRegion(VIDEO_WID_T wid, VIDEO_RECT_T outregion, unsigned short Wide, unsigned short High)
{
	StructSrcRect m_dispwin ; //temp add by will
	VSC_INPUT_TYPE_T srctype;
	unsigned char channel;
	VIDEO_RECT_T inregion;
	unsigned char port_num = 0;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
	unsigned char plane=0;
	static unsigned char OutpuLocalDimmingPatMode_pre = FALSE;
	unsigned long flags;//for spin_lock_irqsave
	//unsigned char avd_small_output_flag = FALSE;

	VIDEO_RECT_T tInputRegion;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
#if(LiveZoom_PROFILE == 1)
	magnifierbefore_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
#endif

	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "#####[%s(%d)] x=%d, y=%d, w=%d, h=%d\n", __FUNCTION__, __LINE__, outregion.x, outregion.y, outregion.w, outregion.h);
	//frank@0323 add TV006_WB_Pattern_En to support output region function

#ifdef CONFIG_MEMC_BYPASS
	outregion.x = outregion.x/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
	outregion.w = outregion.w/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
	rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "after memc_bypass rtk_hal_vsc_SetOutputRegion  x=%d, y=%d, w=%d, h=%d \n", outregion.x, outregion.y, outregion.w, outregion.h);
#endif



	if((OutpuLocalDimmingPatMode == TRUE) || (TV006_WB_Pattern_En)){

		osdovl_mixer_ctrl2_RBUS mixer_ctrl2_reg;
		ppoverlay_main_background_h_start_end_RBUS main_background_h_start_end_reg;
		ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
		ppoverlay_main_background_v_start_end_RBUS main_background_v_start_end_reg;
		ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;
		unsigned int timeout=0x3fffff;
		ppoverlay_main_background_color1_RBUS	main_background_color1_reg;
		ppoverlay_main_background_color2_RBUS main_background_color2_reg;
		ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
		//ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
		//ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl2_reg;
		ppoverlay_dispd_smooth_toggle1_RBUS	 dispd_smooth_toggle1_reg;
		if(!TV006_WB_Pattern_En) {
		if((outregion.x ==0)&&(outregion.y == 0)&&(outregion.w == 3840)&&(outregion.h== 2160))
			return TRUE;
		}
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "+++OutpuLocalDimmingPatMode");

		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

		//set free run timing
		//drivf_scaler_reset_freerun_60Hz();
		//fw_scaler_dtg_double_buffer_enable(TRUE);
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		if(!TV006_WB_Pattern_En){
		// turn off osd mixer
		mixer_ctrl2_reg.regValue = IoReg_Read32(OSDOVL_Mixer_CTRL2_reg);
		mixer_ctrl2_reg.mixer_en = 0;
		IoReg_Write32(OSDOVL_Mixer_CTRL2_reg, mixer_ctrl2_reg.regValue);
		IoReg_Write32(OSDOVL_OSD_Db_Ctrl_reg, 0);
		}

		main_background_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_H_Start_End_reg);
		main_background_h_start_end_reg.mh_bg_sta = outregion.x;
		main_background_h_start_end_reg.mh_bg_end = outregion.x+outregion.w;
		IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, main_background_h_start_end_reg.regValue);

		main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
		main_active_h_start_end_reg.mh_act_sta= outregion.x;
		main_active_h_start_end_reg.mh_act_end = outregion.x+outregion.w;
		IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);

		main_background_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);
		main_background_v_start_end_reg.mv_bg_sta = outregion.y;
		main_background_v_start_end_reg.mv_bg_end = outregion.y+outregion.h;
		IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);

		main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
		main_active_v_start_end_reg.mv_act_sta = outregion.y;
		main_active_v_start_end_reg.mv_act_end = outregion.y+outregion.h;
		IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);
		if(!TV006_WB_Pattern_En){
			main_background_color1_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color1_reg);
			main_background_color2_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color2_reg);
			main_background_color1_reg.m_bg_b = 0x3fff;
			main_background_color1_reg.m_bg_g = 0x3fff;
			main_background_color2_reg.m_bg_r = 0x3fff;
			IoReg_Write32(PPOVERLAY_Main_Background_Color1_reg, main_background_color1_reg.regValue);
			IoReg_Write32(PPOVERLAY_Main_Background_Color2_reg, main_background_color2_reg.regValue);
			down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
			main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
			main_display_control_rsv_reg.m_force_bg = 1;
			IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
			spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
			up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		}
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		do{
			dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
		}while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply==1) && (--timeout));

		if(timeout==0){
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "[%s]WARNING! wait double buf timeout!\n", __FUNCTION__);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		}else{
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		}

		if(OutpuLocalDimmingPatMode) {
		OutpuLocalDimmingPatMode_pre = TRUE;
		return TRUE;
		}

	}else{

		if(OutpuLocalDimmingPatMode_pre == TRUE){
			ppoverlay_main_background_h_start_end_RBUS main_background_h_start_end_reg;
			ppoverlay_main_background_v_start_end_RBUS main_background_v_start_end_reg;
			ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
			ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;
			ppoverlay_dispd_smooth_toggle1_RBUS	 dispd_smooth_toggle1_reg;
			unsigned int timeout=0x3fffff;

			ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

			down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			double_buffer_ctrl_reg.dmainreg_dbuf_en = 1;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
			spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
			up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			main_background_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_H_Start_End_reg);
			main_background_h_start_end_reg.mh_bg_sta = Get_DISP_ACT_STA_HPOS();
			main_background_h_start_end_reg.mh_bg_end = Get_DISP_ACT_END_HPOS();
			IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, main_background_h_start_end_reg.regValue);
			main_background_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);
			main_background_v_start_end_reg.mv_bg_sta = Get_DISP_ACT_STA_VPOS();
			main_background_v_start_end_reg.mv_bg_end = Get_DISP_ACT_END_VPOS();
			IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);
			main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
			main_active_h_start_end_reg.mh_act_sta= outregion.x;
			main_active_h_start_end_reg.mh_act_end = outregion.x+outregion.w;
			IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);
			main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
			main_active_v_start_end_reg.mv_act_sta = outregion.y;
			main_active_v_start_end_reg.mv_act_end = outregion.y+outregion.h;
			IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			do{
				dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
			}while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply==1) && (--timeout));

			if(timeout==0){
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "[%s]WARNING! wait double buf timeout!\n", __FUNCTION__);
				dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
				IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
				dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
				dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
				IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
				dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
				IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			}else{
				dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
				dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
				IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
			}
			OutpuLocalDimmingPatMode_pre = FALSE;
		}
		else
		OutpuLocalDimmingPatMode_pre = FALSE;

	}



#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif
	if (wid ==VIDEO_WID_0) {
		channel = SLR_MAIN_DISPLAY;
	} else if (wid ==VIDEO_WID_1) {
		channel = SLR_SUB_DISPLAY;
	}
	srctype = Get_DisplayMode_Src(channel);

	//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtk_hal_vsc_SetOutputRegion wid=%x  channel=%x\n", wid, channel);

	if(wid == VIDEO_WID_0) {
		down(&Magnifier_Semaphore);
		if (DbgSclrFlgTkr.LivezoomOffKeepMainForceBG == TRUE) {
			DbgSclrFlgTkr.LivezoomOffKeepMainForceBG = FALSE;
			up(&Magnifier_Semaphore);
			return TRUE;
		}
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB ) && DbgSclrFlgTkr.OuputDisplayMode && DbgSclrFlgTkr.Sub_OuputDisplayMode
			/*&& (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)*/) {
				if (DbgSclrFlgTkr.LivezoomMainRerunFlag == FALSE) {
					if (main_InputRegion_0000 == 1){
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"main inputregion is 0,0,0,0 \n");
						up(&Magnifier_Semaphore);
						return TRUE;
					}
					DbgSclrFlgTkr.Main_smooth_toggle_set_flag = false;
					DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off = FALSE;
					DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag =false;
					DbgSclrFlgTkr.Main_Output_Set_flag = false;
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][started]Main re run scaler flow self firstly when open pip!!\n");

					//clear_imd_smooth_toggle_clk_time2switch_en(SLR_MAIN_DISPLAY);
					//imd_smooth_enable_main_double_buffer(FALSE);
					//imd_smooth_enable_sub_double_buffer(FALSE);
					set_zoom_reset_double_state(_DISABLE,SLR_MAIN_DISPLAY);
					set_zoom_reset_double_state(_DISABLE,SLR_SUB_DISPLAY);

					if (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
					{
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom = true\n");
						DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom = true;
					} else {
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom = false\n");
						DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom = false;
					}

					if (magnifier_voinfo_wait(SLR_MAIN_DISPLAY) == FALSE){
						DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom = false;
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"main wait vo info time out happen in main self\n");
						up(&Magnifier_Semaphore);
						return TRUE;
					}
					magnifier_mainscaler_run(wid, srctype,(VIDEO_RECT_T){0,0,_DISP_WID,_DISP_LEN});

					DbgSclrFlgTkr.magnifier_mainscaler_run_livezoom = false;
					#if 0
					if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE)==_MODE_STATE_ACTIVE))//recheck, timing may under changing
					{
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
					}
					#endif
					DbgSclrFlgTkr.LivezoomMainRerunFlag = TRUE;
					DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = TRUE;

					if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER) {
						/*magnifier main overscan*/
						VIDEO_RECT_T magnifiermaininregion;
						VIDEO_RECT_T magnifiermainoutregion;
						rtk_hal_vsc_GetInputRegion(VIDEO_WID_0, &magnifiermaininregion);
						rtk_hal_vsc_GetOutputRegion(VIDEO_WID_0, &magnifiermainoutregion);
						Scaler_DispWindowZoomin(SLR_MAIN_DISPLAY, magnifiermaininregion, magnifiermainoutregion,0,0,FALSE);
					}
					msleep(200);
					if (DbgSclrFlgTkr.mainVscFreezeFlag) {
						Scaler_SetFreeze(SLR_MAIN_DISPLAY, DbgSclrFlgTkr.mainVscFreezeFlag);
					}
					if (DbgSclrFlgTkr.subVscFreezeFlag) {
						Scaler_SetFreeze(SLR_SUB_DISPLAY, DbgSclrFlgTkr.subVscFreezeFlag);
					}

					if(DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag&&DbgSclrFlgTkr.LivezoomSubRerunFlag)
					{
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
						DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag = FALSE;
					}

					if(DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag&&DbgSclrFlgTkr.LivezoomSubRerunFlag)
					{
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
						DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier]LivezoomMainRerunEndneedOpenforcebg at main!!\n");
					}
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][ended]Main re run scaler flow self firstly when open pip!!\n");
				} else {
					if(DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag&&DbgSclrFlgTkr.LivezoomSubRerunFlag)
					{
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
						DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag = FALSE;
					}

					if(DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag&&DbgSclrFlgTkr.LivezoomSubRerunFlag)
					{
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
						DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier]LivezoomMainRerunEndneedOpenforcebg at main!!\n");
					}

					/*live zoom md smootoggle flow*/
					set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
					if (((Main_InputRegion_w + Main_InputRegion_x) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE))
						|| ((Main_InputRegion_h + Main_InputRegion_y) > (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)))) {
						Main_InputRegion_x = 0;
						Main_InputRegion_y = 0;
						Main_InputRegion_w = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
						Main_InputRegion_h = (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));
					}
#if 0
					inregion.x = drvif_memory_get_data_align(Main_InputRegion_x, 4);
					inregion.y = Main_InputRegion_y;
					inregion.w = drvif_memory_get_data_align(Main_InputRegion_w, 4);
					inregion.h = Main_InputRegion_h;
					if ((inregion.x  + inregion.w) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE)) {
						inregion.w = inregion.w -4;
					}
#else
					inregion.x = Main_InputRegion_x;
					inregion.y = Main_InputRegion_y;
					inregion.w = Main_InputRegion_w;
					inregion.h = Main_InputRegion_h;
#endif
#if 0
					if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER) {
#endif
						VSC_MAGNIGIER_PARA_T magmsg;

						magmsg.magnifierWid = wid;
						magmsg.magnifierinregion = inregion;
						magmsg.magnifieroutregion = outregion;
						magmsg.W = 0;
						magmsg.H = 0;

	//					sub_window_type = 0;
	//					set_vsc_SetCircle_OutputRegion(outregion, 0);
						magnifier_message_push(magmsg);
						//Scaler_DispWindowZoomin(SLR_MAIN_DISPLAY, inregion, outregion,FALSE);
#if 0
					} else {
						/*livezoom main window change go photo smoothtoggle*/
						down(&VSC_Semaphore);
						zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, inregion.x, inregion.y, inregion.w, inregion.h, ZOOM_CROP);
						zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, outregion.x, outregion.y, outregion.w, outregion.h, ZOOM_DISP);
						up(&VSC_Semaphore);
					}
#endif
				}
				up(&Magnifier_Semaphore);
		} else {
			up(&Magnifier_Semaphore);


#if 1//def CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
			if ((outregion.w < 1) || (outregion.h < 1)) {
				down(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_Output_Set_flag = FALSE;
				main_dispwin.srcx = outregion.x;
				main_dispwin.srcy = outregion.y;
				main_dispwin.src_height = outregion.h;
				main_dispwin.src_wid = outregion.w;
				check_input_and_output_the_same(SLR_MAIN_DISPLAY);
				up(&SetMainOutPutRegion_Semaphore);
				pr_emerg("outputregion is zero, return\n");
				return TRUE;
			}
#endif

			if((srctype == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
			{//For ATV case
				unsigned ucVDTimingChange;
				if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
					m_dispwin.srcx = 0;
					m_dispwin.srcy = 0;
					m_dispwin.src_height = _DISP_LEN;
					m_dispwin.src_wid = _DISP_WID;
				}else {
					m_dispwin.srcx = outregion.x;
					m_dispwin.srcy = outregion.y;
					m_dispwin.src_height = outregion.h;
					m_dispwin.src_wid = outregion.w;
				}
//				if(DbgSclrFlgTkr.Main_ATV_Go_Smooth_Toggle_flag){//This means that currently force bg is disabled, so directly run scaler flow
				ucVDTimingChange = Scaler_AVD_GetRunSearchState(SLR_MAIN_DISPLAY); // it will not clear ATV run search state flag
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
				#if 0
				//WOSQRTK-6104 patch
				if((outregion.w < 960) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
					if(CompareATVOutputRegion(SLR_MAIN_DISPLAY, &outregion))
					{
						//go throgh to smooth toggle.	//WOSQRTK-6617
					}
					else {
						if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE)
						{

							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####avd output smaller than 960 auto mute on####\r\n");
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
							up(get_forcebg_semaphore());
						}
						avd_small_output_flag = TRUE;
					}
				}
				#endif
					if (Get_LivezoomOffMainForceBG() == TRUE){
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][started][ATV]Main re run scaler flow when pip close!!\n");
						down(&VSC_Semaphore);
						set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, TRUE);
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
						up(get_forcebg_semaphore());
						if(SLR_MAIN_DISPLAY == wid)
							Share_Memory_Set_Scaler_Run_Flag(1);

						Scaler_DispWindowSet(m_dispwin);
						Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
						//zoom_imd_smooth_toggle_config(wid, outregion.x, outregion.y, outregion.w, outregion.h, ZOOM_DISP);
#if 0//if should run back data framesync,should let vo do smoothtoggle
						if ((drvif_HDR_get_VO_Decompress_Status()==FALSE)&&(DbgSclrFlgTkr.DataFramesynclivezoom == TRUE)) {
							int timeout = 50;
							if (vo_overscan_adjust(srctype)) {
								msleep(20);
								timeout = 50;
								while (timeout--) {
									if(get_vo_change_flag(Get_DisplayMode_Port(SLR_MAIN_DISPLAY))) {
										break;
									}
									msleep(10);
								}
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s disable VO overscan case. timeout:%d#####\r\n", __FUNCTION__, timeout);
							}
						}
#endif
						DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
#if 1
						if (Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VO) {
							DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;
						}
#endif
						rtk_output_connect(SLR_MAIN_DISPLAY);
						up(&VSC_Semaphore);//Rika

						msleep(50);
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "open bg for live zoom off....\n");
						Set_LivezoomOffMainForceBG(FALSE);
						zoom_clear_input_output_region_record(SLR_MAIN_DISPLAY);
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][ended][ATV]Main re run scaler flow when pip close!!\n");
						return TRUE;

					}


				//if(DbgSclrFlgTkr.Main_ATV_Go_Smooth_Toggle_flag && !ucVDTimingChange && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && !avd_small_output_flag)
				if(DbgSclrFlgTkr.Main_ATV_Go_Smooth_Toggle_flag && !ucVDTimingChange && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
#else
				if(DbgSclrFlgTkr.Main_ATV_Go_Smooth_Toggle_flag && !ucVDTimingChange && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
#endif
				{//This means that currently force bg is disabled and color std is not changed, so run smooth toggle flow //For Sub black video issue patch will 20151211
					set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "2 rtk_hal_vsc_SetOutputRegion  x=%d, y=%d, w=%d, h=%d \n", outregion.x, outregion.y, outregion.w, outregion.h);
					main_dispwin.srcx = m_dispwin.srcx;
					main_dispwin.srcy = m_dispwin.srcy;
					main_dispwin.src_height = m_dispwin.src_height;
					main_dispwin.src_wid = m_dispwin.src_wid;

					//back up output region	//WOSQRTK-6617
					DbgSclrFlgTkr.Main_ATV_OutputRegion_x_pre = outregion.x;
					DbgSclrFlgTkr.Main_ATV_OutputRegion_y_pre = outregion.y;
					DbgSclrFlgTkr.Main_ATV_OutputRegion_w_pre = outregion.w;
					DbgSclrFlgTkr.Main_ATV_OutputRegion_h_pre = outregion.h;

					down(&VSC_Semaphore);
					Scaler_DispWindowSet(m_dispwin);
					rtd_printk(KERN_INFO, TAG_NAME_VSC, "\r\n####func:%s atv smooth toggle#####\r\n", __FUNCTION__);
					Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

	#ifdef CONFIG_SDNR_CROP

					//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
					//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));

					zoom_imd_smooth_toggle_config(wid, outregion.x, outregion.y, outregion.w, outregion.h, ZOOM_DISP);
					//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
					//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));
	#else

					if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(SLR_MAIN_DISPLAY))
					{
						VIDEO_RECT_T inregion_avd;
						VIDEO_RECT_T outregion_avd;
						rtk_hal_vsc_GetOutputRegion(SLR_MAIN_DISPLAY, &outregion_avd);
						Scaler_CalWindowZoominForAVD(SLR_MAIN_DISPLAY, &inregion_avd, &outregion_avd);

						rtd_printk(KERN_INFO, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						Scaler_DispWindowZoominForAVD(SLR_MAIN_DISPLAY, inregion_avd, outregion_avd,FALSE);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
						//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
					}
					else
					{
						zoom_imd_smooth_toggle_config(wid, outregion.x, outregion.y, outregion.w, outregion.h, ZOOM_DISP);
					}

	#endif //end of 	#ifdef CONFIG_SDNR_CROP...else...

#else
					zoom_imd_smooth_toggle_config(wid, outregion.x, outregion.y, outregion.w, outregion.h, ZOOM_DISP);
#endif
					up(&VSC_Semaphore);
				} else {//This means that currently force bg is enabled. Need to check run smooth toggle or scaler
					down(&SetMainOutPutRegion_Semaphore);

					if(DbgSclrFlgTkr.Main_ATV_Go_Smooth_Toggle_flag && ucVDTimingChange)//This means that currently force bg is disabled and color std is changed, so directly run scaler flow
					{
						DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;//Special case:mute off=>set ARC have to run
						DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
						Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s [special case]request atv run main scaler flow atv#####\r\n", __FUNCTION__);
					}
					else{
						if((Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE)) {

							DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;//This is special case for VIP test
							DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;//Let scaler can be run
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####no mute on, so request run main scaler flow for atv directly####\r\n");

						} else {
							if(vsc_debug_mode)
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request atv run main scaler flow atv####\r\n", __FUNCTION__);
							DbgSclrFlgTkr.Main_Output_Set_flag = TRUE;//Set output flag for setwinblank to request scaler
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s request atv run main scaler flow atv#####\r\n", __FUNCTION__);
						}
					}
					reset_any_srcrect(&main_dispwin_for_only_xy);
					DbgSclrFlgTkr.Main_ATV_PassThrought_output_flag = TRUE;//in ATV set this flag to check ATV will run scaler flow.
					main_dispwin.srcx = m_dispwin.srcx;
					main_dispwin.srcy = m_dispwin.srcy;
					main_dispwin.src_height = m_dispwin.src_height;
					main_dispwin.src_wid = m_dispwin.src_wid;

					//back up output region	//WOSQRTK-6617
					DbgSclrFlgTkr.Main_ATV_OutputRegion_x_pre = outregion.x;
					DbgSclrFlgTkr.Main_ATV_OutputRegion_y_pre = outregion.y;
					DbgSclrFlgTkr.Main_ATV_OutputRegion_w_pre = outregion.w;
					DbgSclrFlgTkr.Main_ATV_OutputRegion_h_pre = outregion.h;

					if (DbgSclrFlgTkr.main_opensourceID == _UNKNOWN_INPUT) {
						set_source_info_forPQ(SLR_MAIN_DISPLAY);//Set source info for PQ request befor scaler
					}
					up(&SetMainOutPutRegion_Semaphore);
				}
				return TRUE;
			}
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			{
				if (srctype == VSC_INPUTSRC_VDEC || srctype == VSC_INPUTSRC_JPEG)
				{
					port_num = Get_DisplayMode_Port(SLR_MAIN_DISPLAY);
					if((srctype == VSC_INPUTSRC_VDEC) && (get_vo_open_smooth_toggle_enable(SLR_MAIN_DISPLAY)) && (DbgSclrFlgTkr.adaptive_stream == FALSE))
					{
						if((port_num == 0) || (port_num == 1))
						{
							if(adaptive_streaming_info[port_num].update_flag)
							{
								if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE)
								{//WOSQRTK-4065 Patch. Need to force bg. Because webos stop VO but don't call forcebg
									rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s stop VO case auto mute on####\r\n", __FUNCTION__);
									down(get_forcebg_semaphore());
									scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
									up(get_forcebg_semaphore());
								}
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s active to search for gst####\r\n", __FUNCTION__);
								Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							}
						}
					}

					if(((port_num == 0) || (port_num == 1)) && (srctype == VSC_INPUTSRC_VDEC))
					{
						if(adaptive_streaming_info[port_num].update_flag)
						{
							down(&Adaptive_Streaming_Semaphore);
							adaptive_streaming_info[port_num].update_flag = FALSE;
							up(&Adaptive_Streaming_Semaphore);
						}
					}

					if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
					{
						down(get_vo_infosemaphore());
						if(get_vo_change_flag(port_num))
						{
							up(get_vo_infosemaphore());
							if (Get_vo_smoothtoggle_timingchange_flag(SLR_MAIN_DISPLAY)) {
								if(get_vo_run_smooth_toggle_enable(SLR_MAIN_DISPLAY)) {
								} else {
									if (get_vo_smoothtoggle_state(SLR_MAIN_DISPLAY) == SLR_SMOOTH_TOGGLE_ACTIVE) {
										plane = get_vo_plane_flag(SLR_MAIN_DISPLAY);
										vo_force_data_mode_set_enable(vo_force_data_mode_get_enable(SLR_MAIN_DISPLAY), SLR_MAIN_DISPLAY);
										set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_INIT, SLR_MAIN_DISPLAY,plane);
										smooth_toggle_state_info_rpc(SLR_MAIN_DISPLAY);
										rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "set_vo_smoothtoggle_state=SLR_SMOOTH_TOGGLE_INIT\n");
									}
									if(SLR_MAIN_DISPLAY == wid)
										Share_Memory_Set_Scaler_Run_Flag(1);
									rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####Voinfo is change. Active to search 1####\r\n");
									Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
								}
							} else {
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####Voinfo is change. Active to search 2####\r\n");
								Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
							}
						} else {
							up(get_vo_infosemaphore());
						}

					}
					if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH) {
						down(&SetMainOutPutRegion_Semaphore);
						reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
						up(&SetMainOutPutRegion_Semaphore);
					}
				}
			}
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE && get_3D_mode_enable())
			{
				Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
				up(&SetMainOutPutRegion_Semaphore);
			}

			if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
				m_dispwin.srcx = 0;
				m_dispwin.srcy = 0;
				m_dispwin.src_height = _DISP_LEN;
				m_dispwin.src_wid = _DISP_WID;
			}else {
				m_dispwin.srcx = outregion.x;
				m_dispwin.srcy = outregion.y;
				m_dispwin.src_height = outregion.h;
				m_dispwin.src_wid = outregion.w;
			}
			if (((srctype == VSC_INPUTSRC_VDEC) ||(((srctype == VSC_INPUTSRC_HDMI)&& (get_HDMI_HDR_mode() ==HDR_DOLBY_HDMI)) || (get_HDMI_HDR_mode() ==HDR_HDR10_HDMI))) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
				Scaler_data_frc_fs_change_adjust_outputregion(SLR_MAIN_DISPLAY,m_dispwin.src_height);
			}

			if ((srctype == VSC_INPUTSRC_JPEG) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
				ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
				ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;
				main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);/* Main Active H pos*/
				main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);

				if((m_dispwin.src_wid != (main_active_h_start_end_reg.mh_act_end - main_active_h_start_end_reg.mh_act_sta))||
				(m_dispwin.src_height != (main_active_v_start_end_reg.mv_act_end - main_active_v_start_end_reg.mv_act_sta))) {
					Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
					down(&SetMainOutPutRegion_Semaphore);
					reset_any_srcrect(&main_dispwin_pre); //Need to Reste previous output value. For run scaler flow
					up(&SetMainOutPutRegion_Semaphore);
				}
			}
#if 0//def CONFIG_ENABLE_VD_27MHZ_MODE
			//WOSQRTK-6104 patch
			if((srctype == VSC_INPUTSRC_AVD) && (outregion.w < 960) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
				if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE)
				{
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####avd output smaller than 960 auto mute on####\r\n");
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
					up(get_forcebg_semaphore());
				}
				avd_small_output_flag = TRUE;
			}
			if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && (DbgSclrFlgTkr.OuputDisplayMode || DbgSclrFlgTkr.OutputMemoryMode) && !avd_small_output_flag) {
#else
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
			if ((get_rotate_mode()!=rotate_mode) &&((get_rotate_mode()!=DIRECT_VO_FRAME_ORIENTATION_DEFAULT) ||(rotate_mode!=0)) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
			{
				pr_emerg("[Qing]output rotate run=%d,%d\n",get_rotate_mode(),rotate_mode);
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_for_only_xy);
				main_dispwin.srcx = m_dispwin.srcx;
				main_dispwin.srcy = m_dispwin.srcy;
				main_dispwin.src_wid = m_dispwin.src_wid;
				main_dispwin.src_height = m_dispwin.src_height;
				if (rotate_mode == DIRECT_VO_FRAME_ORIENTATION_ROTATE_0) {
					DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;
				}
				if (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE) {
					ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
					DbgSclrFlgTkr.rotate_run_scaler_flag = TRUE;
					DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
					up(&SetMainOutPutRegion_Semaphore);
					rtd_printk(KERN_EMERG, TAG_NAME_VSC,"[Rotate]active case run rotate scaler\n");
					main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
					if (!main_display_control_rsv_reg.m_force_bg) {
						rtd_printk(KERN_EMERG, TAG_NAME_VSC,"[Rotate]force to forcbg \n");
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
						up(get_forcebg_semaphore());
					}
				} else {
					DbgSclrFlgTkr.rotate_muteoff_request_flag = TRUE;
					//DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
					up(&SetMainOutPutRegion_Semaphore);
					rtd_printk(KERN_EMERG, TAG_NAME_VSC,"[Rotate] active case mute off go rotate\n");
				}
			}else
#endif

			if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && (DbgSclrFlgTkr.OuputDisplayMode || DbgSclrFlgTkr.OutputMemoryMode)
				&& (!(DbgSclrFlgTkr.RGB444Mode_change && (srctype == VSC_INPUTSRC_HDMI)))) {
#endif
				if ((outregion.w == 0) || (outregion.h == 0)) {
					/*if main output region all are zero, do nothing @Crixus 20160118*/
					/*
					down(get_forcebg_semaphore());
					drvif_scalerdisplay_enable_display(SLR_MAIN_DISPLAY, _DISABLE);
					up(get_forcebg_semaphore());
					main_wind0000 = TRUE;
					*/
				} else {
					down(&SetMainOutPutRegion_Semaphore);

					main_dispwin.srcx = m_dispwin.srcx;
					main_dispwin.srcy = m_dispwin.srcy;
					main_dispwin.src_wid = m_dispwin.src_wid;
					main_dispwin.src_height = m_dispwin.src_height;
					if (Get_LivezoomOffMainForceBG() == TRUE){
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][started]Main re run scaler flow when pip close!!\n");
						up(&SetMainOutPutRegion_Semaphore);
						down(&VSC_Semaphore);
						set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, TRUE);
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
						up(get_forcebg_semaphore());
						if(SLR_MAIN_DISPLAY == wid)
							Share_Memory_Set_Scaler_Run_Flag(1);

						Scaler_DispWindowSet(m_dispwin);
						Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
						//zoom_imd_smooth_toggle_config(wid, outregion.x, outregion.y, outregion.w, outregion.h, ZOOM_DISP);
#if 0//if should run back data framesync,should let vo do smoothtoggle
						if ((drvif_HDR_get_VO_Decompress_Status()==FALSE)&&(DbgSclrFlgTkr.DataFramesynclivezoom == TRUE)) {
							int timeout = 50;
							if (vo_overscan_adjust(srctype)) {
								msleep(20);
								timeout = 50;
								while (timeout--) {
									if(get_vo_change_flag(Get_DisplayMode_Port(SLR_MAIN_DISPLAY))) {
										break;
									}
									msleep(10);
								}
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s disable VO overscan case. timeout:%d#####\r\n", __FUNCTION__, timeout);
							}
						}
#endif
						DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
						if (Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VO) {
							DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;
						}
						rtk_output_connect(SLR_MAIN_DISPLAY);
						up(&VSC_Semaphore);//Rika

						msleep(50);
						set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
						zoom_clear_input_output_region_record(SLR_MAIN_DISPLAY);
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "open bg for live zoom off....\n");
						up(get_forcebg_semaphore());
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][ended]Main re run scaler flow when pip close!!\n");
					}
#if 0//def CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
					else if (Get_rotate_function() && (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == TRUE)) {
						DbgSclrFlgTkr.Main_Output_Set_flag = TRUE;//Set output flag for setwinblank to request scaler
						Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE,_MODE_STATE_SEARCH);
						up(&SetMainOutPutRegion_Semaphore);
						}
#endif
					else if((srctype != VSC_INPUTSRC_AVD) && (check_only_xy_shift_case(SLR_MAIN_DISPLAY, &main_input_size_pre, &main_dispwin_for_only_xy))//need to updatemain_input_size_pre and main_dispwin_for_only_xy always
							&& (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE)){
						up(&SetMainOutPutRegion_Semaphore);
					#ifdef CONFIG_ALL_SOURCE_DATA_FS
						if ((srctype == VSC_INPUTSRC_VDEC) &&  Scaler_get_data_framesync(SLR_MAIN_DISPLAY)) {
							// all region are the same, just run apply_only_xy_shift, but do nothing
							if(DbgSclrFlgTkr.check_only_xy_shift_same_region == TRUE){
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "%s -- apply_only_xy_shift do nothing\n", __FUNCTION__);
							} else {
								down(&VSC_Semaphore);
								zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height, ZOOM_CROP);
								zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, main_dispwin.srcx, main_dispwin.srcy, main_dispwin.src_wid, main_dispwin.src_height, ZOOM_DISP);
								up(&VSC_Semaphore);
							}
						} else
					#endif
						{
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "apply_only_xy_shift...\n");
							apply_only_xy_shift(SLR_MAIN_DISPLAY, main_input_size, main_dispwin_for_only_xy);
						}
					} else {
						if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){
							if(vsc_debug_mode)
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request run smooth toggle flow####\r\n", __FUNCTION__);

							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s line:%d request run smooth toggle flow####\r\n", __FUNCTION__, __LINE__);
							DbgSclrFlgTkr.Main_smooth_toggle_set_flag = TRUE;
						} else {
							if(vsc_debug_mode)
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request mute off to run smooth toggle####\r\n", __FUNCTION__);

							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s line:%d request mute off to run smooth toggle####\r\n", __FUNCTION__, __LINE__);
							DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag = TRUE;
						}
						up(&SetMainOutPutRegion_Semaphore);

					}
					/*if main output region all are zero, do nothing @Crixus 20160118*/
					/*
					if(main_wind0000 == TRUE) {
						down(get_forcebg_semaphore());
						drvif_scalerdisplay_enable_display(SLR_MAIN_DISPLAY, _ENABLE);
						up(get_forcebg_semaphore());
						main_wind0000 = FALSE;
					}
					*/
				}
			}
			else if (DbgSclrFlgTkr.OutputVencMode || DbgSclrFlgTkr.OutputMemoryMode || DbgSclrFlgTkr.OutputAveMode || DbgSclrFlgTkr.OuputDisplayMode) {
				if (srctype == VSC_INPUTSRC_VDEC)
				{
					port_num = Get_DisplayMode_Port(SLR_MAIN_DISPLAY);
					if((port_num == 0) || (port_num == 1))
					{
						if(adaptive_streaming_info[port_num].update_flag)
						{
							down(&Adaptive_Streaming_Semaphore);
							adaptive_streaming_info[port_num].update_flag = FALSE;
							up(&Adaptive_Streaming_Semaphore);
						}
					}
				}
				down(&SetMainOutPutRegion_Semaphore);
				reset_any_srcrect(&main_dispwin_for_only_xy);
				main_dispwin.srcx = m_dispwin.srcx;
				main_dispwin.srcy = m_dispwin.srcy;
				main_dispwin.src_height = m_dispwin.src_height;
				main_dispwin.src_wid = m_dispwin.src_wid;
				if(check_input_and_output_the_same(SLR_MAIN_DISPLAY) == FALSE) {
					if(SLR_MAIN_DISPLAY == wid)
						Share_Memory_Set_Scaler_Run_Flag(1);
					DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;
					if(/*Main_Output_Set_flag_Special_Case == TRUE*/0){//No need
						DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;//Special case:mute off=>set ARC have to run scaler
						DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;//Let scaler can be run
						if(vsc_debug_mode)
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s [special case]request run main scaler flow####\r\n", __FUNCTION__);

						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s src:%d [special case]request run main scaler flow#####\r\n", __FUNCTION__, srctype);
					} else {
						if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE)==_MODE_STATE_ACTIVE)
							&&DbgSclrFlgTkr.RGB444Mode_change && (srctype==VSC_INPUTSRC_HDMI))
						{
							Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
						}
						if((Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE)) {
							DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;//This is special case for VIP test
							DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;//Let scaler can be run
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####no mute on, so request run main scaler flow directly####\r\n");
						} else {
							DbgSclrFlgTkr.Main_Output_Set_flag = TRUE;//Set output flag for setwinblank to request scaler
							if(vsc_debug_mode)
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####go func:%s request run main scaler flow####\r\n", __FUNCTION__);

							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s src:%d request run main scaler flow#####\r\n", __FUNCTION__, srctype);
						}
					}
					if (DbgSclrFlgTkr.main_opensourceID == _UNKNOWN_INPUT) {
						set_source_info_forPQ(SLR_MAIN_DISPLAY);//Set source info for PQ request befor scaler
					}

				} else {
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####func:%s src:%d main the input and output is the same#####\r\n", __FUNCTION__, srctype);
				}
				if(srctype == VSC_INPUTSRC_JPEG) {
					DbgSclrFlgTkr.JPEG_Scaler_SM = 1;
				} else {
					DbgSclrFlgTkr.JPEG_Scaler_SM = 0;
				}
				up(&SetMainOutPutRegion_Semaphore);

			}
			if (Get_LivezoomOffMainForceBG() == TRUE) {
				Set_LivezoomOffMainForceBG(FALSE);
			}

		}
	}
	else if (wid == VIDEO_WID_1)
	{
#ifdef CONFIG_DUAL_CHANNEL
		down(&Magnifier_Semaphore);
		if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB ) && (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && DbgSclrFlgTkr.Sub_OuputDisplayMode) {
			if(DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag && DbgSclrFlgTkr.LivezoomMainRerunFlag)
			{
				down(get_forcebg_semaphore());
				scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
				up(get_forcebg_semaphore());
				DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier]LivezoomMainRerunEndneedOpenforcebg at sub!!\n");
			}

			//magnifier md smootoggle flow
			if ((outregion.w == 0) || (outregion.h == 0))
			{
				sub_dispwin.srcx = 0;
				sub_dispwin.srcy = 0;
				sub_dispwin.src_height = 0;
				sub_dispwin.src_wid = 0;
				Scaler_SubDispWindowSet(sub_dispwin);
				down(get_forcebg_semaphore());
				drvif_scalerdisplay_subdisplay_hidenfunc(_ENABLE);
				up(get_forcebg_semaphore());
				DbgSclrFlgTkr.sub_wind0000 = TRUE;

			} else {
				if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
					outregion.x = 0;
					outregion.y = 0;
					outregion.h = _DISP_LEN;
					outregion.w = _DISP_WID;
				}

				set_input_for_vgip(SLR_SUB_DISPLAY, sub_input_size.srcx, sub_input_size.srcy, sub_input_size.src_wid, sub_input_size.src_height);
				if (((Sub_InputRegion_w + Sub_InputRegion_x) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE))
					|| ((Sub_InputRegion_h + Sub_InputRegion_y) > (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)))) {
					Sub_InputRegion_x = 0;
					Sub_InputRegion_y = 0;
					Sub_InputRegion_w = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
					Sub_InputRegion_h = (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));
				}

#if 0
				inregion.x = drvif_memory_get_data_align(Sub_InputRegion_x, 4);
				inregion.y = Sub_InputRegion_y;
				inregion.w = drvif_memory_get_data_align(Sub_InputRegion_w, 4);
				inregion.h = Sub_InputRegion_h;
				if ((inregion.x  + inregion.w) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE)) {
					inregion.w = inregion.w -4;
				}
#else
				inregion.x = Sub_InputRegion_x;
				inregion.y = Sub_InputRegion_y;
				inregion.w = Sub_InputRegion_w;
				inregion.h = Sub_InputRegion_h;
#endif
				if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM)
				{/*livezoom*/
					//set_vsc_SetMagnifire_shape(0);
					sub_window_type = 0;
					Scaler_DispWindowZoomin(SLR_SUB_DISPLAY, inregion, outregion,0,0, FALSE);
				}
				else
				{/*magnifier*/

					VSC_MAGNIGIER_PARA_T magmsg;
					if (inregion.w > outregion.w)
						inregion.w = outregion.w;
					if (inregion.h > outregion.h)
						inregion.h = outregion.h;

					//set_vsc_SetMagnifire_shape(1);
					magmsg.magnifierWid = wid;
					magmsg.magnifierinregion = inregion;
					magmsg.magnifieroutregion = outregion;
					magmsg.W = Wide;
					magmsg.H = High;

//					set_vsc_SetCircle_OutputRegion(outregion, 1);
					sub_window_type = 1;
					magnifier_message_push(magmsg);
					/*Scaler_DispWindowZoomin(SLR_SUB_DISPLAY, inregion, outregion,TRUE);*/
				}

				if(DbgSclrFlgTkr.sub_wind0000 == TRUE) {
					down(get_forcebg_semaphore());
					drvif_scalerdisplay_subdisplay_hidenfunc( _DISABLE);
					up(get_forcebg_semaphore());
					DbgSclrFlgTkr.sub_wind0000 = FALSE;
				}
			}
			up(&Magnifier_Semaphore);
		} else if (DbgSclrFlgTkr.Sub_OuputDisplayMode && (Get_Live_zoom_mode() == LIVE_ZOOM_SUB )
			/*&& (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)*/) {
			if ((outregion.w == 0) || (outregion.h == 0)) {
				sub_dispwin.srcx = 0;
				sub_dispwin.srcy = 0;
				sub_dispwin.src_height = 0;
				sub_dispwin.src_wid = 0;
				Scaler_SubDispWindowSet(sub_dispwin);
				if (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
					down(get_forcebg_semaphore());
					drvif_scalerdisplay_subdisplay_hidenfunc( _ENABLE);
					up(get_forcebg_semaphore());
					DbgSclrFlgTkr.sub_wind0000 = TRUE;
				} else {
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
					up(get_forcebg_semaphore());
				}
			} else {
				if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
					outregion.x = 0;
					outregion.y = 0;
					outregion.h = _DISP_LEN;
					outregion.w = _DISP_WID;
				}
				sub_dispwin.srcx = outregion.x;
				sub_dispwin.srcy = outregion.y;
				sub_dispwin.src_height = outregion.h;
				sub_dispwin.src_wid = outregion.w;
				Scaler_SubDispWindowSet(sub_dispwin);

				/*let main go 8 bit and 422 cap, main and sub should keep the same format for switch buffer*/
				//clear_imd_smooth_toggle_clk_time2switch_en(SLR_MAIN_DISPLAY);
				//imd_smooth_enable_main_double_buffer(FALSE);
				//imd_smooth_enable_sub_double_buffer(FALSE);
				set_zoom_reset_double_state(_DISABLE,SLR_MAIN_DISPLAY);
				set_zoom_reset_double_state(_DISABLE,SLR_SUB_DISPLAY);
				set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, TRUE);

				if (DbgSclrFlgTkr.Main_Output_Set_flag == TRUE) {
						DbgSclrFlgTkr.Main_Output_Set_flag = FALSE;
						if (DbgSclrFlgTkr.LivezoomMainRerunFlag == FALSE) {
							DbgSclrFlgTkr.Main_smooth_toggle_set_flag = false;
							DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off = false;
							DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag =false;
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][started]11Main re run scaler flow by sub firstly when open pip!!\n");
							/*re run main scaler start*/
							if (magnifier_voinfo_wait(SLR_SUB_DISPLAY) == FALSE){
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"main wait vo info time out happen11\n");
								set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
								up(&Magnifier_Semaphore);
								return FALSE;
							}
							magnifier_mainscaler_run(wid, srctype, (VIDEO_RECT_T){0,0,_DISP_WID,_DISP_LEN});

							rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][ended]11Main re run scaler flow by sub firstly when open pip!!\n");
							DbgSclrFlgTkr.LivezoomMainRerunFlag = TRUE;
							DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = TRUE;
						}

						if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER) {
							/*magnifier main overscan*/
							VIDEO_RECT_T magnifiermaininregion;
							VIDEO_RECT_T magnifiermainoutregion;
							rtk_hal_vsc_GetInputRegion(VIDEO_WID_0, &magnifiermaininregion);
							rtk_hal_vsc_GetOutputRegion(VIDEO_WID_0, &magnifiermainoutregion);
							Scaler_DispWindowZoomin(SLR_MAIN_DISPLAY, magnifiermaininregion, magnifiermainoutregion,0,0,FALSE);
						}
#if 0
						if(DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag)
						{
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
							up(get_forcebg_semaphore());
							DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier]11LivezoomMainRerunEndneedOpenforcebg at sub!!\n");
						}
#endif
                               } else if (((Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM)&&(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH))
					||((Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER))){
					if (DbgSclrFlgTkr.LivezoomMainRerunFlag == FALSE) {
						DbgSclrFlgTkr.Main_smooth_toggle_set_flag = false;
						DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off = false;
						DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag =false;
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][started]22Main re run scaler flow by sub firstly when open pip!!\n");
						/*re run main scaler start*/
						if (magnifier_voinfo_wait(SLR_SUB_DISPLAY) == FALSE) {
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"main wait vo info time out happen22\n");
							set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
							up(&Magnifier_Semaphore);
							return FALSE;
						}

						magnifier_mainscaler_run(wid, srctype, (VIDEO_RECT_T){0,0,_DISP_WID,_DISP_LEN});
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][ended]22Main re run scaler flow by sub firstly when open pip!!\n");
						DbgSclrFlgTkr.LivezoomMainRerunFlag = TRUE;
						DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = TRUE;
#if 0
						if(DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag)
						{
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
							up(get_forcebg_semaphore());
							DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier]22LivezoomMainRerunEndneedOpenforcebg at sub!!\n");
						}
#endif
					}
				} else {
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
					up(get_forcebg_semaphore());
					DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = TRUE;
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier]main forcebg for main and sub mute at the same time\n");
				}

				set_input_for_vgip(SLR_SUB_DISPLAY, sub_input_size.srcx, sub_input_size.srcy, sub_input_size.src_wid, sub_input_size.src_height);
				if (((Sub_InputRegion_w + Sub_InputRegion_x) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE))
					|| ((Sub_InputRegion_h + Sub_InputRegion_y) > (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)))) {
					Sub_InputRegion_x = 0;
					Sub_InputRegion_y = 0;
					Sub_InputRegion_w = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
					Sub_InputRegion_h = (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));
				}
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][started]sub run scaler flow by self when open pip!!\n");
				down(get_forcebg_semaphore());
				scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);
				up(get_forcebg_semaphore());

				if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_LIVE_ZOOM) {
					/*livezoom, sub disp sub*/
					sub_window_type = 0;
				}
				down(&VSC_Semaphore);
				DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;
				rtk_output_connect(SLR_SUB_DISPLAY);
				up(&VSC_Semaphore);
				DbgSclrFlgTkr.LivezoomSubRerunFlag = TRUE;
				DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag = TRUE;

				if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER) {
					/*magnifier, sub disp change to main buffer*/
					VIDEO_RECT_T magnifiermaininregion;
					VIDEO_RECT_T magnifiermainoutregion;
					rtk_hal_vsc_GetInputRegion(VIDEO_WID_0, &magnifiermaininregion);
					rtk_hal_vsc_GetOutputRegion(VIDEO_WID_0, &magnifiermainoutregion);
					Scaler_DispWindowZoomin(SLR_MAIN_DISPLAY, magnifiermaininregion, magnifiermainoutregion,0,0,FALSE);

					inregion.x = Sub_InputRegion_x;
					inregion.y = Sub_InputRegion_y;
					inregion.w =Sub_InputRegion_w;
					inregion.h = Sub_InputRegion_h;

					//set_vsc_SetMagnifire_shape(1);
					if (inregion.w > outregion.w)
						inregion.w = outregion.w;
					if (inregion.h > outregion.h)
						inregion.h = outregion.h;
					sub_window_type = 1;
					Scaler_DispWindowZoomin(SLR_SUB_DISPLAY, inregion, outregion,Wide,High,TRUE);
				}

				set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);

				if (Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER) {
					if (DbgSclrFlgTkr.mainVscFreezeFlag) {
						Scaler_SetFreeze(SLR_MAIN_DISPLAY, DbgSclrFlgTkr.mainVscFreezeFlag);
					}
					if (DbgSclrFlgTkr.subVscFreezeFlag) {
						Scaler_SetFreeze(SLR_SUB_DISPLAY, DbgSclrFlgTkr.subVscFreezeFlag);
					}

					if (DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag)
					{
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
						DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag = FALSE;
					}

					if(DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag)
					{
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
						DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[magnifier]LivezoomMainRerunEndneedOpenforcebg at sub!!\n");
					}
				} else {
					/*for livezoom:main setting window before sub window setting case*/
					if (DbgSclrFlgTkr.LivezoomMainRerunFlag) {
						if (DbgSclrFlgTkr.mainVscFreezeFlag) {
							Scaler_SetFreeze(SLR_MAIN_DISPLAY, DbgSclrFlgTkr.mainVscFreezeFlag);
						}
						if (DbgSclrFlgTkr.subVscFreezeFlag) {
							Scaler_SetFreeze(SLR_SUB_DISPLAY, DbgSclrFlgTkr.subVscFreezeFlag);
						}
						if (DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag)
						{
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
							up(get_forcebg_semaphore());
							DbgSclrFlgTkr.LivezoomSubRerunEndneedOpenforcebgFlag = FALSE;
						}

						if(DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag)
						{
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
							up(get_forcebg_semaphore());
							DbgSclrFlgTkr.LivezoomMainRerunEndneedOpenforcebgFlag = FALSE;
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom]LivezoomMainRerunEndneedOpenforcebg at sub!!\n");
						}
					}
				}

				if(DbgSclrFlgTkr.sub_wind0000 == TRUE) {
					down(get_forcebg_semaphore());
					drvif_scalerdisplay_subdisplay_hidenfunc( _DISABLE);
					up(get_forcebg_semaphore());
					DbgSclrFlgTkr.sub_wind0000 = FALSE;
				}

				set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[livezoom/magnifier][ended]sub run scaler flow by self when open pip!!\n");
#if 0/*qiangzhou marked, becasue webos will set winblank off*/
				if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE)==_MODE_STATE_ACTIVE) && (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE)==_MODE_STATE_ACTIVE))//recheck, timing may under changing
				{
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
					up(get_forcebg_semaphore());
				}
#endif
			}
			up(&Magnifier_Semaphore);
		} else if ((DbgSclrFlgTkr.Sub_OuputDisplayMode || DbgSclrFlgTkr.Sub_OutputVencMode || DbgSclrFlgTkr.Sub_OutputMemoryMode || DbgSclrFlgTkr.Sub_OutputAveMode) && (Get_Live_zoom_mode() == LIVE_ZOOM_OFF)) {
			up(&Magnifier_Semaphore);

			if((srctype == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
			{
				if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
					m_dispwin.srcx = 0;
					m_dispwin.srcy = 0;
					m_dispwin.src_height = _DISP_LEN;
					m_dispwin.src_wid = _DISP_WID;
				}else {
					m_dispwin.srcx = outregion.x;
					m_dispwin.srcy = outregion.y;
					m_dispwin.src_height = outregion.h;
					m_dispwin.src_wid = outregion.w;
				}


				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "SetOutputRegion DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag=%x\n", DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "SetOutputRegion scaler state=%x\n", Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE));
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "SetOutputRegion Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY)=%x\n", Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY));

				//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "SetOutputRegion DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag=%x\n", DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag);
				//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "SetOutputRegion scaler state=%x\n", Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE));
				//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "SetOutputRegion Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY)=%x\n", Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY));

				rtk_hal_vsc_GetInputRegion(1, &tInputRegion);

				//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "SetOutputRegion rtk_hal_vsc_GetInputRegion InputRegion_x=%d, y=%d, w=%d, h=%d\n", tInputRegion.x, tInputRegion.y, tInputRegion.w, tInputRegion.h);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "SetOutputRegion rtk_hal_vsc_GetInputRegion InputRegion_x=%d, y=%d, w=%d, h=%d\n", tInputRegion.x, tInputRegion.y, tInputRegion.w, tInputRegion.h);


				if (DbgSclrFlgTkr.Sub_OutputVencMode) {
					down(&SetSubOutPutRegion_Semaphore);
					sub_dispwin.srcx = outregion.x;
					sub_dispwin.srcy = outregion.y;
					sub_dispwin.src_height = outregion.h;
					sub_dispwin.src_wid = outregion.w;
					set_input_for_vgip(SLR_SUB_DISPLAY, sub_input_size.srcx, sub_input_size.srcy, sub_input_size.src_wid, sub_input_size.src_height);
					Scaler_SubDispWindowSet(sub_dispwin);
					DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;
					DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
					up(&SetSubOutPutRegion_Semaphore);
					return TRUE;
				} else if(DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag && (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {//For Sub black video issue patch will 20151211


					if (CompareATVInputOutputRegion(SLR_SUB_DISPLAY, &outregion, &tInputRegion))
					{
						//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "0  ATV sub path, no forcebg, intput and output region are the same\n");
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "0  ATV sub path, no forcebg, intput and output region are the same\n");
						return TRUE;
					}

					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);/*Auto BG. Add by Will*/
					up(get_forcebg_semaphore());
					down(&SetSubOutPutRegion_Semaphore);
					sub_dispwin.srcx = outregion.x;
					sub_dispwin.srcy = outregion.y;
					sub_dispwin.src_height = outregion.h;
					sub_dispwin.src_wid = outregion.w;
					//Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
					DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;//For Sub black video issue patch will 20151211
					DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
					if(vsc_debug_mode)
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n#####go func:%s sub smooth toggle temp flow####\r\n", __FUNCTION__);

					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s sub smooth toggle temp flow#####\r\n", __FUNCTION__);
					up(&SetSubOutPutRegion_Semaphore);
					return TRUE;
				}
				else if(Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY) == FALSE && (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
				{
					if (CompareATVInputOutputRegion(SLR_SUB_DISPLAY, &outregion, &tInputRegion))
					{
						//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "1  ATV sub path, no forcebg, intput and output region are the same\n");
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "1  ATV sub path, no forcebg, intput and output region are the same\n");
						DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;
						DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
						return TRUE;
					}
				}
				down(&SetSubOutPutRegion_Semaphore);
				sub_dispwin.srcx = outregion.x;
				sub_dispwin.srcy = outregion.y;
				sub_dispwin.src_height = outregion.h;
				sub_dispwin.src_wid = outregion.w;


				if((Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY) == FALSE)) {
					DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;//This is special case for VIP test
					DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;//Let scaler can be run
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####no mute on, so request run sub scaler flow for atv directly####\r\n");
				} else {
					DbgSclrFlgTkr.Sub_Output_Set_flag = TRUE;//Set output flag for setwinblank to request scaler
					if(vsc_debug_mode)
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n#####go func:%s request atv run sub scaler flow atv####\r\n", __FUNCTION__);

					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s request atv run sub scaler flow atv#####\r\n", __FUNCTION__);
				}
				if (DbgSclrFlgTkr.sub_opensourceID == _UNKNOWN_INPUT) {
					set_source_info_forPQ(SLR_SUB_DISPLAY);//Set source info for PQ request befor scaler
				}
				up(&SetSubOutPutRegion_Semaphore);
				return TRUE;
			}
#if 1//test sub timing change smooth toggle flow
			if(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			{
				if (srctype == VSC_INPUTSRC_VDEC || srctype == VSC_INPUTSRC_JPEG)
				{
					down(get_vo_infosemaphore());
					if(get_vo_change_flag(Get_DisplayMode_Port(SLR_SUB_DISPLAY)))
					{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####Voinfo is change. Active to search 3####\r\n");
							Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
					}
					up(get_vo_infosemaphore());
					if(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH) {
						down(&SetSubOutPutRegion_Semaphore);
						reset_any_srcrect(&sub_dispwin_pre); //Need to Reste previous output value. For run scaler flow
						up(&SetSubOutPutRegion_Semaphore);
					}
				}
			}
#endif
			if ((outregion.w == 0) || (outregion.h == 0)) {
				sub_dispwin.srcx = 0;
				sub_dispwin.srcy = 0;
				sub_dispwin.src_height = 0;
				sub_dispwin.src_wid = 0;
				Scaler_SubDispWindowSet(sub_dispwin);
				if (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
					down(get_forcebg_semaphore());
					drvif_scalerdisplay_subdisplay_hidenfunc( _ENABLE);
					up(get_forcebg_semaphore());
					DbgSclrFlgTkr.sub_wind0000 = TRUE;
				}
			} else {
				if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
					outregion.x = 0;
					outregion.y = 0;
					outregion.h = _DISP_LEN;
					outregion.w = _DISP_WID;
				}
				if (DbgSclrFlgTkr.Sub_OutputVencMode) {
					down(&VSC_Semaphore);
					sub_dispwin.srcx = outregion.x;
					sub_dispwin.srcy = outregion.y;
					sub_dispwin.src_height = outregion.h;
					sub_dispwin.src_wid = outregion.w;
					set_input_for_vgip(SLR_SUB_DISPLAY, sub_input_size.srcx, sub_input_size.srcy, sub_input_size.src_wid, sub_input_size.src_height);
					Scaler_SubDispWindowSet(sub_dispwin);
					DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;
					rtk_output_connect(SLR_SUB_DISPLAY);
					up(&VSC_Semaphore);

				} else if (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
					//Need smooth toggle flow. Not yet
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);/*Auto BG. Add by Will*/
					up(get_forcebg_semaphore());
					down(&SetSubOutPutRegion_Semaphore);
					sub_dispwin.srcx = outregion.x;
					sub_dispwin.srcy = outregion.y;
					sub_dispwin.src_height = outregion.h;
					sub_dispwin.src_wid = outregion.w;
					Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
					DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;
#if 0// for sub smooth toggle test
{

		down(&VSC_Semaphore);
		Scaler_SetCurrentDispInfo(SLR_SUB_DISPLAY);

		sub_dispwin.srcx = m_dispwin.srcx;
		sub_dispwin.srcy = m_dispwin.srcy;
		sub_dispwin.src_wid = m_dispwin.src_wid;
		sub_dispwin.src_height = m_dispwin.src_height;

		set_input_for_vgip(SLR_SUB_DISPLAY, sub_input_size.srcx, sub_input_size.srcy, sub_input_size.src_wid, sub_input_size.src_height);
		Scaler_SubDispWindowSet(sub_dispwin);
		zoom_imd_smooth_toggle_config(wid, outregion.x, outregion.y, outregion.w, outregion.h, ZOOM_DISP);

		DbgSclrFlgTkr.Main_smooth_toggle_set_flag=FALSE;
		DbgSclrFlgTkr.Sub_Scaler_Stop_flag = TRUE;
		DbgSclrFlgTkr.Sub_Run_Scaler_flag = FALSE;
		up(&VSC_Semaphore);
}
#endif
					if(vsc_debug_mode)
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n#####go func:%s sub smooth toggle temp flow####\r\n", __FUNCTION__);

					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s sub smooth toggle temp flow#####\r\n", __FUNCTION__);
					up(&SetSubOutPutRegion_Semaphore);
				} else {
					down(&SetSubOutPutRegion_Semaphore);
					sub_dispwin.srcx = outregion.x;
					sub_dispwin.srcy = outregion.y;
					sub_dispwin.src_height = outregion.h;
					sub_dispwin.src_wid = outregion.w;
					if(check_input_and_output_the_same(SLR_SUB_DISPLAY) == FALSE){//Check input and output parameter is the same or not
						if((Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY) == FALSE)) {
							DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;//This is special case for VIP test
							DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;//Let scaler can be run
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####no mute on, so request run sub scaler flow directly####\r\n");
						} else {
							DbgSclrFlgTkr.Sub_Output_Set_flag = TRUE;//Set output flag for setwinblank to request scaler
							if(vsc_debug_mode)
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n#####go func:%s src:%d request run sub scaler flow####\r\n", __FUNCTION__, srctype);

							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s src:%d request run sub scaler flow#####\r\n", __FUNCTION__, srctype);
						}
						if (DbgSclrFlgTkr.sub_opensourceID == _UNKNOWN_INPUT) {
							set_source_info_forPQ(SLR_SUB_DISPLAY);//Set source info for PQ request befor scaler
						}
					} else {
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####func:%s src:%d sub the input and output is the same#####\r\n", __FUNCTION__, srctype);
					}
					up(&SetSubOutPutRegion_Semaphore);
				}
				if(DbgSclrFlgTkr.sub_wind0000 == TRUE) {
					down(get_forcebg_semaphore());
					drvif_scalerdisplay_subdisplay_hidenfunc( _DISABLE);
					up(get_forcebg_semaphore());
					DbgSclrFlgTkr.sub_wind0000 = FALSE;
				}
			}
		} else {
			up(&Magnifier_Semaphore);/*added by qiangzhou, can not remove*/
		}

#endif
	}
#if(LiveZoom_PROFILE == 1)
	magnifierafter_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\nVSC rtk_hal_vsc_SetOutputRegion time=%d ms\n",(magnifierafter_time-magnifierbefore_time));
	magnifierbefore_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
#endif
	return TRUE;
}
unsigned char rtk_hal_vsc_SetWinFreeze(VIDEO_WID_T wid, bool bonoff)
{
	SCALER_DISP_CHANNEL channel;
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid != VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	down(&Magnifier_Semaphore);
	down(&VSC_Semaphore);
	if (wid == VIDEO_WID_0) {
		channel = SLR_MAIN_DISPLAY;
		DbgSclrFlgTkr.mainVscFreezeFlag = bonoff;
	} else if (wid == VIDEO_WID_1) {
		channel = SLR_SUB_DISPLAY;
		DbgSclrFlgTkr.subVscFreezeFlag = bonoff;
	}


	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);

	if ((channel == SLR_MAIN_DISPLAY) && (Get_DisplayMode_Src(channel) == VSC_INPUTSRC_AVD) && (Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)) {
		DbgSclrFlgTkr.main_winfreeze=bonoff;
	} else {
		Scaler_SetFreeze(channel, bonoff);
	}
	up(&VSC_Semaphore);
	up(&Magnifier_Semaphore);

	return TRUE;
}


static unsigned char ForceSmoothtoggleGo = FALSE;

unsigned char get_ForceSmoothtoggleGo(void)
{
	return ForceSmoothtoggleGo;
}

void SelfDiagnosis_mainscaler_run(SCALER_DISP_CHANNEL channel, VIDEO_RECT_T inregion, VIDEO_RECT_T outregion)
{
	if (channel == SLR_MAIN_DISPLAY) {
		/*re run main scaler start*/
		main_input_size.srcx = inregion.x;
		main_input_size.srcy = inregion.y;
		main_input_size.src_wid = inregion.w;
		main_input_size.src_height = inregion.h;
		set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);

		down(get_forcebg_semaphore());
		scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
		up(get_forcebg_semaphore());
		//Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH); //Remove by Will
		down(&SetMainOutPutRegion_Semaphore);
		if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
			main_dispwin.srcx = 0;
			main_dispwin.srcy = 0;
			main_dispwin.src_height = _DISP_LEN;
			main_dispwin.src_wid = _DISP_WID;
		} else {
			main_dispwin.srcx = outregion.x;
			main_dispwin.srcy = outregion.y;
			main_dispwin.src_height = outregion.h;
			main_dispwin.src_wid = outregion.w;
		}
		Scaler_DispWindowSet(main_dispwin);
		up(&SetMainOutPutRegion_Semaphore);

		down(&VSC_Semaphore);
		DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
		if (Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VO) {
			DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;
		}
		rtk_output_connect(SLR_MAIN_DISPLAY);
		up(&VSC_Semaphore);

		down(get_forcebg_semaphore());
		scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
		up(get_forcebg_semaphore());
	} else if (channel == SLR_SUB_DISPLAY) {
		/*re run sub scaler start*/
		sub_input_size.srcx = inregion.x;
		sub_input_size.srcy = inregion.y;
		sub_input_size.src_wid = inregion.w;
		sub_input_size.src_height = inregion.h;
		set_input_for_vgip(SLR_SUB_DISPLAY, sub_input_size.srcx, sub_input_size.srcy, sub_input_size.src_wid, sub_input_size.src_height);

		down(get_forcebg_semaphore());
		scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);
		up(get_forcebg_semaphore());
		//Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH); //Remove by Will
		down(&SetSubOutPutRegion_Semaphore);
		if ((outregion.w + outregion.x > _DISP_WID) || (outregion.h + outregion.y > _DISP_LEN)) {
			sub_dispwin.srcx = 0;
			sub_dispwin.srcy = 0;
			sub_dispwin.src_height = _DISP_LEN;
			sub_dispwin.src_wid = _DISP_WID;
		} else {
			sub_dispwin.srcx = outregion.x;
			sub_dispwin.srcy = outregion.y;
			sub_dispwin.src_height = outregion.h;
			sub_dispwin.src_wid = outregion.w;
		}
		Scaler_SubDispWindowSet(sub_dispwin);
		up(&SetSubOutPutRegion_Semaphore);

		down(&VSC_Semaphore);
		DbgSclrFlgTkr.Sub_Scaler_Stop_flag = FALSE;
		rtk_output_connect(SLR_SUB_DISPLAY);
		up(&VSC_Semaphore);

		down(get_forcebg_semaphore());
		scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
		up(get_forcebg_semaphore());
	}
}



unsigned static char Factory_SelfDiagnosis_Mode = FALSE;

unsigned char Get_Factory_SelfDiagnosis_Mode(void)
{
	return Factory_SelfDiagnosis_Mode;
}

unsigned char change_vscinput_with_vfetiming(SCALER_DISP_CHANNEL channel)
{
	VIDEO_RECT_T  inregion;
	VIDEO_RECT_T outregion;

	if(Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
		if(channel == SLR_MAIN_DISPLAY) {
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
			//self-dianosis AV source have to do no overscan @Crixus 20151201
			if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD){
				//self-dianosis AV source, rzhen@2016-09-01
				if(read_buffer_first_flag) return TRUE;
				read_buffer_first_flag = 1;

				inregion.x = 0;
				inregion.y = 0;
				inregion.w = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
				inregion.h = (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));

				main_input_size.srcx = inregion.x;
				main_input_size.srcy = inregion.y;
				main_input_size.src_wid = inregion.w;
				main_input_size.src_height = inregion.h;
				set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);

				outregion.x = 0;
				outregion.y = 0;
				outregion.w = _DISP_WID;
				outregion.h = _DISP_LEN;

				main_dispwin.srcx = outregion.x;
				main_dispwin.srcy = outregion.y;
				main_dispwin.src_height = outregion.h;
				main_dispwin.src_wid = outregion.w;
				Scaler_DispWindowSet(main_dispwin);

				if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE){
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
					up(get_forcebg_semaphore());
				}

				Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);//Let main path to search state. In order to request VO
				down(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;//Let main path run scaler again
				up(&SetMainOutPutRegion_Semaphore);
				msleep(1000);
			}
			else
#endif
			{
				StructSrcRect maindispwind;

				inregion.x = 0;
				inregion.y = 0;
				inregion.w = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
				inregion.h = (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));

				outregion.x = 0;
				outregion.y = 0;
				outregion.w = _DISP_WID;
				outregion.h = _DISP_LEN;
				maindispwind = Scaler_DispWindowGet();
				if((inregion.x != Main_InputRegion_x)
					||(inregion.y != Main_InputRegion_y)
					||(inregion.w != Main_InputRegion_w)
					||(inregion.h != Main_InputRegion_h)
					||(maindispwind.srcx != outregion.x)
					||(maindispwind.srcy != outregion.y)
					||(maindispwind.src_wid != outregion.w)
					||(maindispwind.src_height != outregion.h)
					) {
					SelfDiagnosis_mainscaler_run(SLR_MAIN_DISPLAY, inregion, outregion);
				}
			}
		} else if (channel == SLR_SUB_DISPLAY){
#if 0//def CONFIG_ENABLE_VD_27MHZ_MODE
			//self-dianosis AV source have to do no overscan @Crixus 20151201
			if(Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_AVD){
				if(read_buffer_first_flag == 0){
					read_buffer_first_flag = 1;
					Scaler_AVD_EnableVD27MMode(VD_27M_OFF);
					msleep(1000);
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "[self-dianosis]read buffrt 27M on !!\n");
				}
			} else
#endif
			{
				StructSrcRect subdispwind;
				inregion.x = 0;
				inregion.y = 0;
				inregion.w = Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
				inregion.h = (Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_INTERLACE) ? 2*Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE) : Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));

				outregion.x = 0;
				outregion.y = 0;
				outregion.w = _DISP_WID;
				outregion.h = _DISP_LEN;
				subdispwind = Scaler_SubDispWindowGet();
				if((inregion.x != Main_InputRegion_x)
					||(inregion.y != Main_InputRegion_y)
					||(inregion.w != Main_InputRegion_w)
					||(inregion.h != Main_InputRegion_h)
					||(subdispwind.srcx != outregion.x)
					||(subdispwind.srcy != outregion.y)
					||(subdispwind.src_wid != outregion.w)
					||(subdispwind.src_height != outregion.h)
					) {
					SelfDiagnosis_mainscaler_run(SLR_SUB_DISPLAY, inregion, outregion);
				}
			}
		}
		return TRUE;
	} else {
		return FALSE;
	}
}

unsigned char rtk_hal_vsc_FreezeVideoFrameBuffer(VIDEO_WID_T wid, bool bonoff)
{
	SCALER_DISP_CHANNEL channel;
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN) || (wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	if (wid ==VIDEO_WID_0) {
		channel = SLR_MAIN_DISPLAY;
	} else if (wid ==VIDEO_WID_1) {
		channel = SLR_SUB_DISPLAY;
	}

	if(change_vscinput_with_vfetiming(channel) == FALSE)/*for self diagnosis vfe vsc no overscan*/
		return FALSE;

	drvif_scalerdisplay_set_freeze(channel, bonoff);
	Scaler_SetDisplaySingleBufferMode(channel, bonoff);
	return TRUE;
}

unsigned char rtk_hal_vsc_ReadVideoFrameBuffer(VIDEO_WID_T wid, VIDEO_RECT_T * pin,VIDEO_DDI_PIXEL_STANDARD_COLOR_T * pRead, VIDEO_DDI_COLOR_STANDARD_T *pColor_standard, VIDEO_DDI_PIXEL_COLOR_FORMAT_T * pPixelColorFormat)
{
	unsigned int linesize;
	unsigned char * capturebufferaddr;
	unsigned int capturebuffersize;
	unsigned int capturebufferphyaddr;

	SCALER_DISP_CHANNEL channel;
	VIDEO_DDI_PIXEL_STANDARD_COLOR_T * readaddr = pRead;
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	if (wid ==VIDEO_WID_0) {
		channel = SLR_MAIN_DISPLAY;
	} else if (wid ==VIDEO_WID_1) {
		channel = SLR_SUB_DISPLAY;
	}

	if(change_vscinput_with_vfetiming(channel) == FALSE)/*for self diagnosis vfe vsc no overscan*/
		return FALSE;

	if (pRead == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "pRead == NULL not ok\n");
		return FALSE;
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "x=%d;;y=%d;;w=%d;;h=%d\n", pin->x, pin->y, pin->w,pin->h);
	if(((pin->x+pin->w)>Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_CAP_WID)) || ((pin->y+pin->h)>Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_CAP_LEN)))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wrong ReadVideoFrameBuffer size!!!!!!!\n");
		return FALSE;
	}

	linesize = memory_get_capture_size(channel, MEMCAPTYPE_LINE);
	linesize = SHL(linesize, 3); //unit conversion. 64bits to 8bits

	if (channel == SLR_MAIN_DISPLAY) {
		capturebufferaddr = (unsigned char *)drvif_memory_get_mainblock_viraddr();
		capturebuffersize = drvif_memory_get_block_size(MEMIDX_MAIN);
		capturebufferphyaddr = drvif_memory_get_block_addr(MEMIDX_MAIN);
	} else if (channel == SLR_SUB_DISPLAY) {
		capturebufferaddr = (unsigned char *)drvif_memory_get_subblock_viraddr();
		capturebuffersize = drvif_memory_get_block_size(MEMIDX_SUB);
		capturebufferphyaddr = drvif_memory_get_block_addr(MEMIDX_SUB);
	}

	//dmac_inv_range(capturebufferaddr, capturebufferaddr + capturebuffersize);
	//outer_inv_range(capturebufferphyaddr, capturebufferphyaddr + capturebuffersize);

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "linesize==%d\n",linesize);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "capturebufferaddr==%x\n",drvif_memory_get_mainblock_viraddr());
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "m domain pixel:%x;%x;%x;%x\n",capturebufferaddr[0],capturebufferaddr[1],capturebufferaddr[2],capturebufferaddr[3]);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "m domain pixel:%x;%x;%x;%x\n",capturebufferaddr[4],capturebufferaddr[5],capturebufferaddr[6],capturebufferaddr[7]);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "m domain pixel:%x;%x;%x;%x\n",capturebufferaddr[8],capturebufferaddr[9],capturebufferaddr[10],capturebufferaddr[11]);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "m domain pixel:%x;%x;%x;%x\n",capturebufferaddr[12],capturebufferaddr[13],capturebufferaddr[14],capturebufferaddr[15]);
	if(Scaler_DispGetStatus(channel, SLR_DISP_10BIT))
	{
		* pPixelColorFormat = VIDEO_DDI_PIXEL_10BIT;
		* pColor_standard = VIDEO_DDI_COLOR_STANDARD_YUV;
		if(Scaler_DispGetStatus(channel, SLR_DISP_422CAP))//10bit 422 format
		{
			unsigned int*  linebuffer=NULL;
			unsigned int* srclineptr;
			unsigned int tempvalue;
			unsigned int arraynum = ((pin->x+pin->w)%2)?(pin->x+pin->w+1):(pin->x+pin->w);
			VIDEO_DDI_PIXEL_STANDARD_COLOR_T *linepixel = NULL;
			unsigned int remainbit;
			unsigned int highvalue,lowvalue;
			unsigned int value4byte;
			unsigned int colorindex;
			unsigned int i;
			unsigned int j ;
			unsigned int p;
#if 0
			linebuffer = (unsigned int*)dvr_malloc(linesize);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
#else
			linebuffer = (unsigned int*)dvr_malloc_specific(linesize, GFP_DCU1_FIRST);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc_specific(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T), GFP_DCU1_FIRST);
#endif
			if(linebuffer == NULL)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtk_hal_vsc_ReadVideoFrameBuffer:allocate memoty fail!!!!!\n");
				return FALSE;
			}
			for(p=0;p<pin->h;p++)
			{
				srclineptr = (unsigned int*)(capturebufferaddr+(pin->y+p)*linesize);
				//Do Swap start
				for(i=0; i<(linesize>>2);i++)
				{
					linebuffer[i] =( (srclineptr[i]&0x000000ff)<<24 )|( (srclineptr[i]&0x0000ff00)<<8 )| ( (srclineptr[i]&0x00ff0000)>>8 )|( (srclineptr[i]&0xff000000)>>24 );
				}
				for(i=0; i<(linesize>>2);i+=2)
				{
					tempvalue  = linebuffer[i];
					linebuffer[i] = linebuffer[i+1];
					linebuffer[i+1] = tempvalue;
				}
				//Do Swap end

				remainbit = 0;
				value4byte =0;
				i=0;
				j =0;
				colorindex = 0;
				for(i=0;i<arraynum;)
				{
					if(remainbit<10)
					{
						lowvalue = value4byte;
						value4byte = linebuffer[j++];
						highvalue = (value4byte&(0x000003ff>>remainbit))<<remainbit;
						highvalue = highvalue|lowvalue;
						value4byte = value4byte >> (10-remainbit);
						remainbit = 32-(10-remainbit);
					}
					else
					{
						highvalue = value4byte&0x000003ff;
						value4byte = value4byte>>10;
						remainbit = remainbit - 10;
					}
					switch(colorindex)
					{
						case 0:
							linepixel[i].pixelStandardCb = highvalue;
							linepixel[i+1].pixelStandardCb = highvalue;
							colorindex = 1;
							break;
						case 1:
							linepixel[i].pixelStandardY = highvalue;
							colorindex = 2;
							break;
						case 2:
							linepixel[i].pixelStandardCr= highvalue;
							linepixel[i+1].pixelStandardCr = highvalue;
							colorindex = 3;
							break;
						case 3:
							linepixel[i+1].pixelStandardY = highvalue;
							colorindex = 0;
							i = i+2;
							break;
					}
				}
				memcpy((unsigned char *)(readaddr+p*pin->w), (unsigned char *)(linepixel+pin->x), (pin->w)*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
			}
			dvr_free((void *)linebuffer);
			dvr_free((void *)linepixel);
		}
		else//10bit 444 format
		{
			unsigned int *linebuffer=NULL;
			unsigned int *srclineptr;
			unsigned int tempvalue;
			unsigned int arraynum = pin->x+pin->w;
			VIDEO_DDI_PIXEL_STANDARD_COLOR_T *linepixel = NULL;
			unsigned int remainbit;
			unsigned int highvalue,lowvalue;
			unsigned int value4byte;
			unsigned int colorindex;
			unsigned int i;
			unsigned int j ;
			unsigned int p;
#if 0
			linebuffer = (unsigned int*)dvr_malloc(linesize);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
#else
			linebuffer = (unsigned int*)dvr_malloc_specific(linesize, GFP_DCU1_FIRST);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc_specific(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T), GFP_DCU1_FIRST);
#endif
			if(linebuffer == NULL)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtk_hal_vsc_ReadVideoFrameBuffer:allocate memoty fail!!!!!\n");
				return FALSE;
			}
			for(p=0;p<pin->h;p++)
			{
				srclineptr = (unsigned int*)(capturebufferaddr+(pin->y+p)*linesize);
				//Do Swap start
				for(i=0; i<(linesize>>2);i++)
				{
					linebuffer[i] =( (srclineptr[i]&0x000000ff)<<24 )|( (srclineptr[i]&0x0000ff00)<<8 )| ( (srclineptr[i]&0x00ff0000)>>8 )|( (srclineptr[i]&0xff000000)>>24 );
				}
	    			for(i=0; i<(linesize>>2);i+=2)
				{
					tempvalue  = linebuffer[i];
					linebuffer[i] = linebuffer[i+1];
					linebuffer[i+1] = tempvalue;
				}
				//Do Swap end

				remainbit = 0;
				value4byte =0;
				i=0;
				j =0;
				colorindex = 0;
				for(i=0;i<(pin->x+pin->w);)
				{
					if(remainbit<10)
			       		 {
			           		lowvalue = value4byte;
			        		value4byte = linebuffer[j++];
						highvalue = (value4byte&(0x000003ff>>remainbit))<<remainbit;
					    	highvalue = highvalue|lowvalue;
						value4byte = value4byte >> (10-remainbit);
						remainbit = 32-(10-remainbit);
			        	}
					else
					{
						highvalue = value4byte&0x000003ff;
						value4byte = value4byte>>10;
						remainbit = remainbit - 10;
					}
					switch(colorindex)
					{
						case 0:
							linepixel[i].pixelStandardCr = highvalue;
							colorindex = 1;
							break;
						case 1:
							linepixel[i].pixelStandardCb = highvalue;
							colorindex = 2;
							break;
						case 2:
							linepixel[i].pixelStandardY= highvalue;
							colorindex = 0;
							i++;
							break;
					}
				}
				memcpy((unsigned char *)(readaddr+p*pin->w), (unsigned char *)(linepixel+pin->x), (pin->w)*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
			}
			dvr_free((void *)linebuffer);
			dvr_free((void *)linepixel);
		}
		return TRUE;
	}
	else
	{
		unsigned int i,k;
		* pPixelColorFormat = VIDEO_DDI_PIXEL_8BIT;
		* pColor_standard = VIDEO_DDI_COLOR_STANDARD_YUV;
		if(Scaler_DispGetStatus(channel, SLR_DISP_422CAP))//8bit 422 format
		{
			for(i=pin->y;i<(pin->y + pin->h);i++)
			{
				for(k=pin->x;k<(pin->x + pin->w);k++)
				{
					readaddr->pixelStandardY = capturebufferaddr[i*linesize+2*k];
					readaddr->pixelStandardCb = capturebufferaddr[i*linesize+2*(k/2)*2+1];
					readaddr->pixelStandardCr = capturebufferaddr[i*linesize+2*(k/2)*2+3];
					readaddr ++;
				}
			}
		}
		else//8bit 444 fromat
		{
			for(i=pin->y;i<(pin->y + pin->h);i++)
			{
				for(k=pin->x;k<(pin->x + pin->w);k++)
				{
					readaddr->pixelStandardY= capturebufferaddr[i*linesize+3*k+2];
					readaddr->pixelStandardCb= capturebufferaddr[i*linesize+3*k+1];
					readaddr->pixelStandardCr= capturebufferaddr[i*linesize+3*k];
					readaddr++;
				}
			}
		}
		return TRUE;
	}
}

unsigned char rtk_hal_vsc_WriteVideoFrameBuffer(VIDEO_WID_T wid, VIDEO_RECT_T * pin,VIDEO_DDI_PIXEL_STANDARD_COLOR_T * pWrite)
{
	unsigned int linesize;
	unsigned char * capturebufferaddr;
	unsigned int capturebuffersize;
	unsigned int capturebufferphyaddr;

	SCALER_DISP_CHANNEL channel;
	VIDEO_DDI_PIXEL_STANDARD_COLOR_T * writeaddr = pWrite;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "pWrite = %x\n",(unsigned int)pWrite);
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wid id is not ok\n");
		return FALSE;
	}
#endif

	if (wid ==VIDEO_WID_0) {
		channel = SLR_MAIN_DISPLAY;
	} else if (wid ==VIDEO_WID_1) {
		channel = SLR_SUB_DISPLAY;
	}

	if(change_vscinput_with_vfetiming(channel) == FALSE)/*for self diagnosis vfe vsc no overscan*/
		return FALSE;

	if(pWrite == NULL)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "pWrite == NULL not ok\n");
		return FALSE;
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "x=%d;;y=%d;;w=%d;;h=%d\n", pin->x, pin->y, pin->w, pin->h);

	if(((pin->x+pin->w)>Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_CAP_WID))||((pin->y+pin->h)>Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_CAP_LEN)))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "wrong WriteVideoFrameBuffer size!!!!!!!\n");
		return FALSE;
	}

	linesize = memory_get_capture_size(channel, MEMCAPTYPE_LINE);
	linesize = SHL(linesize, 3); //unit conversion. 64bits to 8bits
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "linesize = %d\n",linesize);

	if (channel == SLR_MAIN_DISPLAY) {
		capturebufferaddr = (unsigned char *)drvif_memory_get_mainblock_viraddr();
		capturebuffersize = drvif_memory_get_block_size(MEMIDX_MAIN);
		capturebufferphyaddr = drvif_memory_get_block_addr(MEMIDX_MAIN);
	} else if (channel == SLR_SUB_DISPLAY) {
		capturebufferaddr = (unsigned char *)drvif_memory_get_subblock_viraddr();
		capturebuffersize = drvif_memory_get_block_size(MEMIDX_SUB);
		capturebufferphyaddr = drvif_memory_get_block_addr(MEMIDX_SUB);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "capturebufferaddr = %x\n",(unsigned int)capturebufferaddr);

	if(Scaler_DispGetStatus(channel, SLR_DISP_10BIT))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "SLR_DISP_422CAP = %x\n",(Scaler_DispGetStatus(channel, SLR_DISP_422CAP)));
		if(Scaler_DispGetStatus(channel, SLR_DISP_422CAP))//422 10bit fomat
		{
			unsigned int arraynum = Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_CAP_WID);
			unsigned int*  linebuffer=NULL;
			unsigned int* srclineptr;
			unsigned int tempvalue;
			VIDEO_DDI_PIXEL_STANDARD_COLOR_T *linepixel=NULL;
			unsigned int remainbit;
			unsigned int highvalue,lowvalue;
			unsigned int value4byte;
			unsigned int colorindex;
			unsigned int i;
			unsigned int j ;
			unsigned int p;

			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "arraynum = %d\n",arraynum);
#if 0
			linebuffer = (unsigned int*)dvr_malloc(linesize);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
#else
			linebuffer = (unsigned int*)dvr_malloc_specific(linesize, GFP_DCU1_FIRST);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc_specific(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T), GFP_DCU1_FIRST);
#endif

			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "linebuffer = %x\n",(unsigned int)linebuffer);
			if(linebuffer == NULL)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtk_hal_vsc_ReadVideoFrameBuffer:allocate memoty fail!!!!!\n");
				return FALSE;
			}
			for(p=0;p<pin->h;p++)
			{
				srclineptr = (unsigned int*)(capturebufferaddr+(pin->y+p)*linesize);
				//Do Swap start
				for(i=0; i<(linesize>>2);i++)
				{
					linebuffer[i] =( (srclineptr[i]&0x000000ff)<<24 )|( (srclineptr[i]&0x0000ff00)<<8 )| ( (srclineptr[i]&0x00ff0000)>>8 )|( (srclineptr[i]&0xff000000)>>24 );
				}
				for(i=0; i<(linesize>>2);i+=2)
				{
					tempvalue  = linebuffer[i];
					linebuffer[i] = linebuffer[i+1];
					linebuffer[i+1] = tempvalue;
				}
				//Do Swap end

				remainbit = 0;
				value4byte =0;
				i=0;
				j =0;
				colorindex = 0;
				for(i=0;i<arraynum;)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "arraynum = %d\n",arraynum);
					if(remainbit<10)
					{
						lowvalue = value4byte;
						value4byte = linebuffer[j++];
						highvalue = (value4byte&(0x000003ff>>remainbit))<<remainbit;
						highvalue = highvalue|lowvalue;
						value4byte = value4byte >> (10-remainbit);
						remainbit = 32-(10-remainbit);
					}
					else
					{
						highvalue = value4byte&0x000003ff;
						value4byte = value4byte>>10;
						remainbit = remainbit - 10;
					}
					switch(colorindex)
					{
						case 0:
							linepixel[i].pixelStandardCb = highvalue;
							linepixel[i+1].pixelStandardCb = highvalue;
							colorindex = 1;
							break;
						case 1:
							linepixel[i].pixelStandardY = highvalue;
							colorindex = 2;
							break;
						case 2:
							linepixel[i].pixelStandardCr= highvalue;
							linepixel[i+1].pixelStandardCr = highvalue;
							colorindex = 3;
							break;
						case 3:
							linepixel[i+1].pixelStandardY = highvalue;
							colorindex = 0;
							i = i+2;
							break;
					}
				}
				//write user's pixel to linepixel array
				memcpy((unsigned char *)(linepixel+pin->x),(unsigned char *)(writeaddr+p*pin->w), (pin->w)*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
				//clear linebuffer
				memset((unsigned char *)linebuffer, 0,linesize);
				//linepixel is the new pixel line should be written in memory. so next do
				remainbit = 32;
				value4byte =0;
				i=0;
				j =0;
				colorindex = 0;
				for(i=0;i<arraynum;)
				{
					switch(colorindex)
					{
						case 0:
							value4byte = linepixel[i].pixelStandardCb;
							colorindex = 1;
							break;
						case 1:
							value4byte = linepixel[i].pixelStandardY;
							colorindex = 2;
							break;
						case 2:
							value4byte = linepixel[i].pixelStandardCr;
							colorindex = 3;
							break;
						case 3:
							value4byte = linepixel[i+1].pixelStandardY;
							colorindex = 0;
							i = i+2;
							break;
					}

					if(remainbit<10)
			       		 {
						lowvalue = value4byte&(0x000003ff>>(10-remainbit));
						highvalue = (value4byte&0x000003ff)>>remainbit;
						linebuffer[j] = linebuffer[j] |(lowvalue<<(32-remainbit));
						j++;
						linebuffer[j] = linebuffer[j] |highvalue;
						remainbit = 32-(10-remainbit);
			        	}
					else
					{
						linebuffer[j] =  linebuffer[j] |(value4byte&0x000003ff)<<(32-remainbit);
						remainbit = remainbit - 10;
					}
				}
				//Do Swap start
				for(i=0; i<(linesize>>2);i++)
				{
					srclineptr[i] =( (linebuffer[i]&0x000000ff)<<24 )|( (linebuffer[i]&0x0000ff00)<<8 )| ( (linebuffer[i]&0x00ff0000)>>8 )|( (linebuffer[i]&0xff000000)>>24 );
				}
	    			for(i=0; i<(linesize>>2);i+=2)
				{
					tempvalue  = srclineptr[i];
					srclineptr[i] = srclineptr[i+1];
					srclineptr[i+1] = tempvalue;
				}
				//Do Swap end
			}
			dvr_free((void *)linebuffer);
			dvr_free((void *)linepixel);
		}
		else//444 10bit format
		{
			unsigned int arraynum = Scaler_DispGetInputInfoByDisp(channel, SLR_INPUT_CAP_WID);
			unsigned int*  linebuffer=NULL;
			unsigned int* srclineptr;
			unsigned int tempvalue;
			VIDEO_DDI_PIXEL_STANDARD_COLOR_T *linepixel = NULL;
			unsigned int remainbit;
			unsigned int highvalue,lowvalue;
			unsigned int value4byte;
			unsigned int colorindex;
			unsigned int i;
			unsigned int j ;
			unsigned int p;

#if 0
			linebuffer = (unsigned int*)dvr_malloc(linesize);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
#else
			linebuffer = (unsigned int*)dvr_malloc_specific(linesize, GFP_DCU1_FIRST);
			linepixel = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc_specific(arraynum*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T), GFP_DCU1_FIRST);
#endif
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "arraynum = %d\n",arraynum);
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "linebuffer = %x\n",(unsigned int)linebuffer);

			if(linebuffer == NULL)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtk_hal_vsc_WriteVideoFrameBuffer:allocate memoty fail!!!!!\n");
				return FALSE;
			}
			for(p=0;p<pin->h;p++)
			{
				srclineptr = (unsigned int*)(capturebufferaddr+(pin->y+p)*linesize);
				//Do Swap start
				for(i=0; i<(linesize>>2);i++)
				{
					linebuffer[i] =( (srclineptr[i]&0x000000ff)<<24 )|( (srclineptr[i]&0x0000ff00)<<8 )| ( (srclineptr[i]&0x00ff0000)>>8 )|( (srclineptr[i]&0xff000000)>>24 );
				}
	    			for(i=0; i<(linesize>>2);i+=2)
				{
					tempvalue  = linebuffer[i];
					linebuffer[i] = linebuffer[i+1];
					linebuffer[i+1] = tempvalue;
				}
				//Do Swap end
				remainbit = 0;
				value4byte =0;
				i=0;
				j =0;
				colorindex = 0;
				for(i=0;i<arraynum;)
				{
					if(remainbit<10)
			       		 {
			           		lowvalue = value4byte;
			        		value4byte = linebuffer[j++];
						highvalue = (value4byte&(0x000003ff>>remainbit))<<remainbit;
					    	highvalue = highvalue|lowvalue;
						value4byte = value4byte >> (10-remainbit);
						remainbit = 32-(10-remainbit);
			        	}
					else
					{
						highvalue = value4byte&0x000003ff;
						value4byte = value4byte>>10;
						remainbit = remainbit - 10;
					}
					switch(colorindex)
					{
						case 0:
							linepixel[i].pixelStandardCr = highvalue;
							colorindex = 1;
							break;
						case 1:
							linepixel[i].pixelStandardCb = highvalue;
							colorindex = 2;
							break;
						case 2:
							linepixel[i].pixelStandardY= highvalue;
							colorindex = 0;
							i++;
							break;
					}
				}

				//write user's pixel to linepixel array
				memcpy((unsigned char *)(linepixel+pin->x),(unsigned char *)(writeaddr+p*pin->w), (pin->w)*sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T));
				//clear linebuffer
				memset((unsigned char *)linebuffer, 0,linesize);
				//linepixel is the new pixel line should be written in memory. so next do
				remainbit = 32;
				value4byte =0;
				i=0;
				j =0;
				colorindex = 0;
				for(i=0;i<arraynum;)
				{
					switch(colorindex)
					{
						case 0:
							value4byte = linepixel[i].pixelStandardCr;
							colorindex = 1;
							break;
						case 1:
							value4byte = linepixel[i].pixelStandardCb;
							colorindex = 2;
							break;
						case 2:
							value4byte = linepixel[i].pixelStandardY;
							colorindex = 0;
							i++;
							break;
					}

					if(remainbit<10)
			       		 {
						lowvalue = value4byte&(0x000003ff>>(10-remainbit));
						highvalue = (value4byte&0x000003ff)>>remainbit;
						linebuffer[j] = linebuffer[j] |(lowvalue<<(32-remainbit));
						j++;
						linebuffer[j] = linebuffer[j] |highvalue;
						remainbit = 32-(10-remainbit);
			        	}
					else
					{
						linebuffer[j] =  linebuffer[j] |(value4byte&0x000003ff)<<(32-remainbit);
						remainbit = remainbit - 10;
					}
				}
				//Do Swap start
				for(i=0; i<(linesize>>2);i++)
				{
					srclineptr[i] =( (linebuffer[i]&0x000000ff)<<24 )|( (linebuffer[i]&0x0000ff00)<<8 )| ( (linebuffer[i]&0x00ff0000)>>8 )|( (linebuffer[i]&0xff000000)>>24 );
				}
	    			for(i=0; i<(linesize>>2);i+=2)
				{
					tempvalue  = srclineptr[i];
					srclineptr[i] = srclineptr[i+1];
					srclineptr[i+1] = tempvalue;
				}
				//Do Swap end
			}

			dvr_free((void *)linebuffer);
			dvr_free((void *)linepixel);
		}
	}
	else
	{
		unsigned int i,k;
		if(Scaler_DispGetStatus(channel, SLR_DISP_422CAP))//422 8bit fomat
		{
			for(i=pin->y;i<(pin->y + pin->h);i++)
			{
				for(k=pin->x;k<(pin->x + pin->w);k++)
				{
					capturebufferaddr[i*linesize+2*k] = writeaddr->pixelStandardY;
					capturebufferaddr[i*linesize+2*(k/2)*2+1] = writeaddr->pixelStandardCb;
					capturebufferaddr[i*linesize+2*(k/2)*2+3] = writeaddr->pixelStandardCr;
					writeaddr ++;
				}
			}
		}
		else//444 8bit format
		{
			for(i=pin->y;i<(pin->y + pin->h);i++)
			{
				for(k=pin->x;k<(pin->x + pin->w);k++)
				{
					capturebufferaddr[i*linesize+3*k+2] = writeaddr->pixelStandardY;
					capturebufferaddr[i*linesize+3*k+1] = writeaddr->pixelStandardCb;
					capturebufferaddr[i*linesize+3*k] = writeaddr->pixelStandardCr;
					writeaddr++;
				}
			}
		}
	}
	dmac_flush_range(capturebufferaddr, capturebufferaddr + capturebuffersize);
	outer_flush_range(capturebufferphyaddr, capturebufferphyaddr + capturebuffersize);
	return TRUE;
}

#if 0//now have VT,no use vsc capture,but these code must keep:qiang_zhou
extern void set_vt_function(unsigned char value);
extern struct semaphore VT_Semaphore;
extern I3DDMA_3DDMA_CTRL_T i3ddmaCtrl_VT;
#endif
unsigned char rtk_hal_vsc_CaptureVideoFrame(VIDEO_DDI_CAPTURE_PLACE_T place, VIDEO_DDI_CAPTURE_INFO_T * pCaptureInfo)
{
#if 0//now have VT,no use vsc capture,but these code must keep:qiang_zhou
	IDMA_DISPD_CAPTURE_INFO capinfo;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	down(&VT_Semaphore);
	if(get_vfod_enablestatus()==FALSE)
	{
		capinfo.enable = 1; //iMode;
		if(place==VIDEO_DDI_SCALER_OUTPUT)
			capinfo.capSrc =  CAP_SRC_UZU;  // 0: UZU, 1: Subtitle, 2: OSD, 3: dither output
		else if(place==VIDEO_DDI_DISPLAY_OUTPUT)
			capinfo.capSrc =  CAP_SRC_SUBTITLE;
		capinfo.capMode = CAP_MODE_SEQ;
		capinfo.capFmt = CAP_422;//CAP_422;
		capinfo.capWid = 960; //iWid;
		capinfo.capLen = 540;
		set_vt_function(TRUE);
		if (I3DDMA_3DDMAInit_VT() == FALSE) {
			up(&VT_Semaphore);
			return FALSE;
		}
		drvif_DC2H_dispD_CaptureConfig(capinfo);
		set_cur_vfod_capinfo(capinfo);
		set_vfod_enablestatus(TRUE);
		if(place==VIDEO_DDI_SCALER_OUTPUT)
			set_vfod_applypqstatus(FALSE);
		else if(place==VIDEO_DDI_DISPLAY_OUTPUT)
			set_vfod_applypqstatus(TRUE);

		msleep(200);
		capinfo = get_cur_vfod_capinfo();

		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "pCaptureInfo addr =%x\n",(unsigned int)pCaptureInfo);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "pCaptureInfo->pData addr = %x\n",(unsigned int)pCaptureInfo->pData);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "pCaptureInfo->pCbCr addr = %x\n",(unsigned int)pCaptureInfo->pCbCr);

		pCaptureInfo->width = capinfo.capWid;
		pCaptureInfo->height = capinfo.capLen;
		pCaptureInfo->pixelFormat = VIDEO_DDI_PIXEL_FORMAT_RGB8;
		*(pCaptureInfo->pScanTypeCapImg) = 1;//p

		if((pCaptureInfo->pData == NULL)/*||(pCaptureInfo->pCbCr == NULL)*/)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "pCaptureInfo->pData  == NULL or pCaptureInfo->pCbCr == NULL not ok\n");
			up(&VT_Semaphore);
			return FALSE;
		}

		memcpy((unsigned char*)pCaptureInfo->pData, (unsigned char*)(i3ddmaCtrl_VT.cap_buffer[0].cache), 3* capinfo.capWid*capinfo.capLen);
		capinfo.enable = 0;
		drvif_DC2H_dispD_CaptureConfig(capinfo);
		I3DDMA_3DDMADeInit_VT();
		set_vfod_enablestatus(FALSE);
		set_vfod_applypqstatus(FALSE);
		set_vt_function(FALSE);
		up(&VT_Semaphore);
		return TRUE;

	} else {
		up(&VT_Semaphore);
		return FALSE;
	}
#else
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "have VT, V2G and VSCcapture not use,keep empty!!\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;
#endif
}


unsigned char rtk_rerun_scaler(SCALER_DISP_CHANNEL channel)
{
	return TRUE;//No work
}

unsigned char rtk_hal_vsc_SetRGB444Mode(bool bonoff)
{
	rtd_printk(KERN_INFO, TAG_NAME_VSC,"file=%s, function=%s, line=%d,%d\n", __FILE__, __FUNCTION__, __LINE__,bonoff);
	if (DbgSclrFlgTkr.RGB444Mode != bonoff) {
		DbgSclrFlgTkr.RGB444Mode_change = 1;
	} else {
		DbgSclrFlgTkr.RGB444Mode_change = 0;
	}
	DbgSclrFlgTkr.RGB444Mode = bonoff;
	return TRUE;
}

bool rtk_hal_vsc_GetRGB444Mode(void)
{
	return DbgSclrFlgTkr.RGB444Mode;
}

unsigned char LiveZoomPcmodeDiableRTNR;

void set_LiveZoomPcmodeDiableRTNR(unsigned char value)
{
	LiveZoomPcmodeDiableRTNR = value;
}

unsigned char get_LiveZoomPcmodeDiableRTNR(void)
{
	return LiveZoomPcmodeDiableRTNR;
}

unsigned char rtk_hal_vsc_Set3DForScaler(TRIDTV_SCALER_CTRL_T * p3DCfgInfo)
{
	unsigned char curmode;
	unsigned char support3Dinput[INPUT_TYPE_MAX]= {
		SLR_3DMODE_2D, SLR_3DMODE_3D_TB, SLR_3DMODE_3D_SBS, SLR_3DMODE_2D,
		SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_3D_FP,
		SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_3D_SBS, SLR_3DMODE_3D_FP,
		SLR_3DMODE_2D_CVT_3D};

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"vsc_3d:%d=%d=%d=%d\n",p3DCfgInfo->mode, p3DCfgInfo->in_fmt, p3DCfgInfo->out_fmt, p3DCfgInfo->lr);
	if(p3DCfgInfo == NULL)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"scaler vsc Set3DForScaler paramter NULL!!!\n");
		return FALSE;
	}
	if(p3DCfgInfo->mode > TRIDTV_3DMODE_MAX || p3DCfgInfo->mode  < TRIDTV_3DMODE_OFF
		||p3DCfgInfo->in_fmt > INPUT_TYPE_MAX || p3DCfgInfo->in_fmt < INPUT_TYPE_3DOFF
		||p3DCfgInfo->out_fmt > SC_OUT_MAX || p3DCfgInfo->out_fmt < SC_OUT_SINGLE_2D
		||p3DCfgInfo->lr > INPUT_LR_MAX || p3DCfgInfo->lr  < INPUT_LR_SEQ)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"scaler vsc Set3DForScaler paramter error!!!\n");
		return FALSE;
	}

	set_field_alternative_3d_mode_enable(FALSE);
#if 1
	if(get_line_alternative_3d_mode_enable() == TRUE)
	{
		Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, false);
		set_line_alternative_3d_mode_enable(FALSE);
		DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
	}
#endif
	if(p3DCfgInfo->mode == TRIDTV_3DMODE_OFF  || p3DCfgInfo->mode == TRIDTV_3DMODE_3DTO2D)
	{

		if(get_3D_mode_enable() == TRUE)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"scaler vsc Set3DForScaler OFF!change to 2D!\n");
			set_3D_mode_enable(FALSE);
			set_3D_overscan_enable(FALSE);
			Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
			down(&VSC_Semaphore);
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
  				rtk_output_connect(SLR_MAIN_DISPLAY);
   			up(&VSC_Semaphore);
		}
		return TRUE;
	}
	else if(p3DCfgInfo->mode == TRIDTV_3DMODE_MAX || p3DCfgInfo->in_fmt == INPUT_TYPE_MAX  ||p3DCfgInfo->out_fmt == SC_OUT_MAX ||p3DCfgInfo->lr == INPUT_LR_MAX)
	{

		if(get_3D_mode_enable() == TRUE)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"scaler vsc Set3DForScaler MAXNUM!change to 2D!\n");
			set_3D_mode_enable(FALSE);
			set_3D_overscan_enable(FALSE);
			Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
			down(&VSC_Semaphore);
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
  				rtk_output_connect(SLR_MAIN_DISPLAY);
   			up(&VSC_Semaphore);
		}
		return TRUE;
	}


	/*force set the out_fmt SC_OUT_SINGLE_FS*/
	if(p3DCfgInfo->out_fmt != SC_OUT_SINGLE_FS)
		p3DCfgInfo->out_fmt = SC_OUT_SINGLE_FS;

	if(p3DCfgInfo->out_fmt != SC_OUT_SINGLE_FS)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"scaler vsc Set3DForScaler out format no support!change to 2D!\n");
		if(get_3D_mode_enable() == TRUE)
		{
			set_3D_mode_enable(FALSE);
			set_3D_overscan_enable(FALSE);
			Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
			down(&VSC_Semaphore);
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
  				rtk_output_connect(SLR_MAIN_DISPLAY);
   			up(&VSC_Semaphore);
		}
		return TRUE;
	}

	if(p3DCfgInfo->in_fmt == INPUT_TYPE_DUALSTREAM)
	{
		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);
		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP, TRUE);
		down(&VSC_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			rtk_output_connect(SLR_MAIN_DISPLAY);
		up(&VSC_Semaphore);

		return TRUE;
	}

	if(p3DCfgInfo->in_fmt == INPUT_TYPE_LINE_ALTERNATIVE/*&& DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI*/)
	{
		vfe_hdmi_timing_info_t vfehdmitiminginfo;
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"input is line alternative\n");
		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_LBL, TRUE);

		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);

		 //DisplayModeInputInfo.type = VSC_INPUTSRC_VDEC;

		if(0!=vfe_hdmi_drv_get_display_timing_info(&vfehdmitiminginfo, SLR_MAIN_DISPLAY))
			return FALSE;
		Scaler_SET_VSCDispinfo_WithVFEHMDI(SLR_MAIN_DISPLAY, vfehdmitiminginfo);
		drvif_I3DDMA_Init();
		HDMI_set_detect_flag(FALSE);
		Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, true);
		set_line_alternative_3d_mode_enable(TRUE);
		drivf_I3DDMA_3D_config();

		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP, TRUE);
		Scaler_Disp3dSetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE,SLR_3D_FRAME_PACKING);
		Scaler_Set3DMode_Attr(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP);
		set_vo_3d_mode(VO_2D_MODE);

		DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
		down(&VSC_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
  			rtk_output_connect(SLR_MAIN_DISPLAY);
   		up(&VSC_Semaphore);

		return TRUE;


	}
	else if(p3DCfgInfo->in_fmt == INPUT_TYPE_FIELD_ALTERNATIVE/*&& DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI*/)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"input is feild alternative\n");
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE,true);
		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);
		set_field_alternative_3d_mode_enable(TRUE);
		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP, TRUE);
		down(&VSC_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			rtk_output_connect(SLR_MAIN_DISPLAY);
		up(&VSC_Semaphore);

		 return TRUE;

	}
	if(p3DCfgInfo->mode == TRIDTV_3DMODE_ON ||p3DCfgInfo->mode == TRIDTV_3DMODE_2DTO3D)
	{
		curmode = p3DCfgInfo->in_fmt;
		curmode = support3Dinput[(curmode < INPUT_TYPE_MAX? curmode: INPUT_TYPE_3DOFF)];

		if(curmode == SLR_3DMODE_2D)
		{
			if(get_3D_mode_enable() == TRUE)
			{
				set_3D_mode_enable(FALSE);
				set_3D_overscan_enable(FALSE);
				Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
				down(&VSC_Semaphore);
				if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
  					rtk_output_connect(SLR_MAIN_DISPLAY);
   				up(&VSC_Semaphore);
				return TRUE;
			}
			else
			{
				return TRUE;
			}
		}

		Scaler_Set3DMode(SLR_MAIN_DISPLAY, curmode, TRUE);
		 if (Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE() && p3DCfgInfo->in_fmt == INPUT_TYPE_2DTO3D)
		{
			// [2D3D] default mode init
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"2d concvt 3d init\n");
			scaler_2Dcvt3D_init();
		}
		 if( drvif_scaler3d_decide_HDMI_framePacking_interlaced_status() && p3DCfgInfo->in_fmt == INPUT_TYPE_FRAMEPAC)
		 {
		 	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Interlace Fp 3D, change progress to interlace!\n");
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE,true);
		 }

		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);
		down(&VSC_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
  			rtk_output_connect(SLR_MAIN_DISPLAY);
   		up(&VSC_Semaphore);
		//Scaler_Set3DLRSwap(p3DCfgInfo->lr);
	}

	return TRUE;
}

unsigned char rtk_hal_vsc_Get3DAutoDetectmode(VIDEO_WID_T wid, VIDEO_DDI_3D_FORMAT_TYPE_T * pvideo3DType)
{
	unsigned char  curmode;

#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#endif

	if(pvideo3DType == NULL)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"scaler vsc Get3DAutoDetectmode paramter is error!\n");
		return FALSE;
	}

	if (Scaler_InputSrcGetMainChType() == _SRC_VO)
	{
		if(get_vo_3d_mode() == VO_3D_SIDE_BY_SIDE_HALF)
			*pvideo3DType = VIDEO_DDI_3D_FORMAT_SIDEBYSIDE_HALF;
		else if(get_vo_3d_mode() == VO_3D_TOP_AND_BOTTOM)
			*pvideo3DType = VIDEO_DDI_3D_FORMAT_TOP_BOTTOM;
		else
			*pvideo3DType = VIDEO_DDI_3D_FORMAT_2D;
		return TRUE;
	}

	Scaler_Set3D_VoAutoDetect_Enable(true);

#ifdef CONFIG_DUAL_CHANNEL
	if(VIDEO_WID_1 == wid)
		check_vo3d_detect_result(SLR_SUB_DISPLAY);
	else// if(VIDEO_WID_0 == wid)
		check_vo3d_detect_result(SLR_MAIN_DISPLAY);
#else //#ifdef CONFIG_DUAL_CHANNEL
	check_vo3d_detect_result(SLR_MAIN_DISPLAY);
#endif //#ifdef CONFIG_DUAL_CHANNEL

	curmode = modestate_get_vo3d_detect_result();
	switch(curmode)
	{
		case VO_2D_MODE:
			*pvideo3DType = VIDEO_DDI_3D_FORMAT_2D;
			break;
		case VO_3D_SIDE_BY_SIDE_HALF:
			*pvideo3DType = VIDEO_DDI_3D_FORMAT_SIDEBYSIDE_HALF;
			break;
		case VO_3D_TOP_AND_BOTTOM:
			*pvideo3DType = VIDEO_DDI_3D_FORMAT_TOP_BOTTOM;
			break;
		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Can't detect 3D auto mode!\n");
			break;
	}


	return TRUE;
}

unsigned char rtk_hal_vsc_Set3Dpatternmode(VIDEO_WID_T wid, VIDEO_DDI_3D_PATTERN_TYPE_T video3DType)
{
	unsigned char curmode;
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#endif

	switch(video3DType)
	{
		case VIDEO_DDI_3D_PATTERN_TOP_BOTTOM:
			curmode = SLR_3DMODE_3D_TB;
			break;
		case VIDEO_DDI_3D_PATTERN_SIDEBYSIDE_HALF:
			curmode = SLR_3DMODE_3D_SBS;
			break;
		case VIDEO_DDI_3D_PATTERN_LINE_INTERLEAVE_HALF:
			curmode = SLR_3DMODE_3D_LBL;
			break;
		case VIDEO_DDI_3D_PATTERN_FRAME_PACKING:
			curmode = SLR_3DMODE_3D_FP;
			break;
		default:
			curmode = SLR_3DMODE_2D;
			break;
	}

	Scaler_Set3DMode(SLR_MAIN_DISPLAY, curmode, TRUE);
	rtk_rerun_scaler(SLR_MAIN_DISPLAY);
	return TRUE;
}

unsigned char rtk_hal_vsc_SetVENEMode(unsigned short framerate, unsigned short scantype)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"VENEMode hal venc support framerate setting,but no scantype setting!!\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;
}

unsigned char 	rtk_hal_vsc_OpenV2G(VIDEO_WID_T wid )
{
#if 0//now have VT,no use V2G,but these code must keep:qiang_zhou
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	IDMA_DISPD_CAPTURE_INFO capinfo;
	if(get_vfod_enablestatus()==FALSE)
	{
		capinfo.enable = 1; //iMode;
		capinfo.capSrc =  CAP_SRC_UZU;
		capinfo.capMode = CAP_MODE_BLOCK;
		capinfo.capFmt = CAP_422;//CAP_422;
		capinfo.capWid = 1920; //iWid;
		capinfo.capLen = 1080;
		drvif_I3DDMA_dispD_to_IdmaVI_idmaConfig(capinfo);
		set_cur_vfod_capinfo(capinfo);
		set_vfod_enablestatus(TRUE);
		set_vfod_applypqstatus(TRUE);
	}
	else
	{
		HAL_VT_RECT_T outregion = {0,0,1920,1080};
		HAL_VT_SetVideoFrameOutputDeviceOutputRegion(HAL_VT_VIDEO_WINDOW_0, HAL_VT_DISPLAY_OUTPUT,&outregion);
	}
	msleep(2000);//for start 100frame not go block cvt sequence

	return TRUE;
#else
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"V2G not use,keep empty!!\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;
#endif
}
unsigned char 	rtk_hal_vsc_CloseV2G(VIDEO_WID_T wid )
{
#if 0//now have VT,no use V2G,but these code must keep:qiang_zhou
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#endif
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	if(get_vfod_enablestatus()==TRUE)
	{
		if(FALSE==HAL_VT_Finalize())
			return FALSE;
	}
	return TRUE;
#else
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"V2G not use,keep empty!!\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;
#endif
}

unsigned char 	rtk_hal_vsc_GetV2GFramebuffer(VIDEO_WID_T wid , VIDEO_DDI_CAPTURE_INFO_T* pCaptureInfo)
{
#if 0//now have VT,no use V2G,but these code must keep:qiang_zhou

#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	IDMA_DISPD_CAPTURE_INFO capinfo;

	if(get_vfod_enablestatus()==TRUE)
	{
		capinfo = get_cur_vfod_capinfo();

		pCaptureInfo->width = capinfo.capWid;
		pCaptureInfo->height = capinfo.capLen;
		pCaptureInfo->pixelFormat = VIDEO_DDI_PIXEL_FORMAT_YCBCR422_8;
		*(pCaptureInfo->pScanTypeCapImg) = 1;//p

		if((pCaptureInfo->pData == NULL)||(pCaptureInfo->pCbCr == NULL))
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"pCaptureInfo->pData  == NULL or pCaptureInfo->pCbCr == NULL not ok\n");
			return FALSE;
		}

		memcpy(pCaptureInfo->pData, (unsigned char*)(i3ddmaCtrl_VT.cap_buffer[0].cache+VT_I3DDMA_BUFFER_UNITSIZE*6), capinfo.capWid*capinfo.capLen);
		memcpy(pCaptureInfo->pCbCr, (unsigned char*)(i3ddmaCtrl_VT.cap_buffer[0].cache+VT_I3DDMA_BUFFER_UNITSIZE*6+capinfo.capWid*capinfo.capLen), capinfo.capWid*capinfo.capLen);
		return TRUE;
	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"VT,V2G not enabled!!!\n");
		return FALSE;
	}
#else
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"have VT, V2G not use,keep empty!!\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;
#endif
}

unsigned char	rtk_hal_vsc_SetUDInput(VIDEO_UD_MODE_T videoUDMode)
{
#if 0//these code must keep:qiang_zhou
	//only support 2k1k:UD_MODE_FHD
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	if(videoUDMode==UD_MODE_FHD)
	{
		if(get_vfod_enablestatus()==FALSE)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"VT,V2G not enabled!!!\n");
			return FALSE;
		}
		else
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"now input is already UD_MODE_FHD, no need change!!\n ");
			return TRUE;
		}
	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"UD_MODE_UD UD_MODE_UD_HALF  is not support \n");
		return FALSE;
	}
#else
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"UD not use,keep empty!!\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;
#endif
}

unsigned char 	rtk_hal_vsc_SetUDOutput(VIDEO_DDI_DIS_FMT_T disFmt)
{
#if 0//these code must keep:qiang_zhou
	//only support 2k1k:UD_MODE_FHD
	if(disFmt.isUD==TRUE)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"only 2k1k support\n");
		return FALSE;
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	IDMA_DISPD_CAPTURE_INFO capinfo;
	capinfo = get_cur_vfod_capinfo();
	if((get_vfod_enablestatus()==TRUE)&&(capinfo.capWid==disFmt.h_total)&&(capinfo.capLen==disFmt.v_total))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"all settingf is the same now.no need go\n");
		return TRUE;
	}
	else
	{
		capinfo.enable = 1; //iMode;
		capinfo.capSrc =  CAP_SRC_SUBTITLE;
		capinfo.capMode = CAP_MODE_BLOCK;
		capinfo.capFmt = CAP_422;//CAP_422;
		capinfo.capWid = disFmt.h_total; //iWid;
		capinfo.capLen = disFmt.v_total;
		drvif_I3DDMA_dispD_to_IdmaVI_idmaConfig(capinfo);
		set_cur_vfod_capinfo(capinfo);
		set_vfod_enablestatus(TRUE);
		set_vfod_applypqstatus(TRUE);
		return TRUE;
	}
#else
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"UD not use,keep empty!!\n");
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
		return TRUE;
#endif

}


unsigned char	rtk_hal_vsc_GetVideoDelayedTime (VIDEO_WID_T wid , unsigned short *pDelayedTime)
{
#ifdef CONFIG_DUAL_CHANNEL
	if((wid < VIDEO_WID_MIN)||(wid > VIDEO_WID_MAX))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#else
	if(wid !=VIDEO_WID_0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"wid id is not ok\n");
		return FALSE;
	}
#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	*pDelayedTime = 10000/Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ);
	return TRUE;
}


unsigned char 	rtk_hal_vsc_SetTileMode(BOOLEAN bOnOff)
{
	//pip not support
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"pip pop mode not support!!\n");
	return TRUE;
}

unsigned char 	rtk_hal_vsc_SetTileMaxRowVal(unsigned char uMaxRow, unsigned char uMaxCol)
{
	//pip not support
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"pip pop mode not support!!\n");
	return TRUE;
}

unsigned char 	rtk_hal_vsc_SetTileID(unsigned char uTileID)
{
	//pip not support
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"pip pop mode not support!!\n");
	return TRUE;
}

unsigned char rtk_hal_vsc_SetAdaptiveStream(unsigned char bOnOff)
{
	int ret = -1;
	//this is vo smoothtoggle operation:when change timing,with qing_liu code
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d,bOnOff=%d,DbgSclrFlgTkr.adaptive_stream_pre=%d\n", __FILE__, __FUNCTION__, __LINE__, bOnOff,DbgSclrFlgTkr.adaptive_stream_pre);
	if(DbgSclrFlgTkr.adaptive_stream_pre != bOnOff) {
		DbgSclrFlgTkr.adaptive_stream = bOnOff;
		DbgSclrFlgTkr.adaptive_stream_pre = bOnOff;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_ADAPTIVE_STREAM_FLAG, bOnOff, 1))){
			rtd_printk(KERN_ERR, TAG_NAME_VSC,"ret=%d, SCALERIOC_ADAPTIVE_STREAM_FLAG RPC fail !!!\n", ret);
		}
	}

	return TRUE;

}
unsigned char vsc_get_adaptivestream_flag(void)
{
	return DbgSclrFlgTkr.adaptive_stream;
}

#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
unsigned char vsc_decide_timingframesync(unsigned char display)
{
	if(display==SLR_MAIN_DISPLAY){
		if (Scaler_InputSrcGetType(display) == _SRC_VO){

			if (vsc_get_adaptivestream_flag()&& vbe_disp_get_adaptivestream_fs_mode())
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}

		else {
			return FALSE;
		}
	}
	else if (display==SLR_SUB_DISPLAY){
			return FALSE;
	}

	return FALSE;


}
#endif

void Scaler_DualChannelRpc(unsigned char flag)
{
	long ret = 0;
	unsigned char *pulTemp = NULL;

	pulTemp = (unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_DUAL_CHANNEL_FLAG);

	// copy to RPC share memory
	//memcpy(pulTemp, &DbgSclrFlgTkr.dvo_dual_decoder_flag, sizeof(unsigned char));

	//pulTemp[0] = htonl(pulTemp[0]);
	if (pulTemp) {
		*pulTemp = flag;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_DUAL_CHANNEL_FLAG,0,0)))
		{
			pr_debug( "ret=%d, set dual channel fail !!!\n", ret );
			return;

		}
	}
}

unsigned char 	rtk_hal_vsc_SetSOCOutputFMT(VIDEO_UD_MODE_T videoUDMode)
{
	//this is vo smoothtoggle operation:when change timing,with qing_liu code
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;

}

unsigned char 	rtk_hal_vsc_SetFRCType(unsigned char frcType)
{
	//this is vo smoothtoggle operation:when change timing,with qing_liu code
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;

}

unsigned char 	rtk_hal_vsc_GetFRCType(unsigned char frcType)
{
	//this is vo smoothtoggle operation:when change timing,with qing_liu code
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;

}

void rtk_hal_vsc_Setdualdecoder(unsigned char enable)
{
	rtd_printk(KERN_INFO, TAG_NAME_VSC,"file=%s, function=%s, enable=%d\n", __FILE__, __FUNCTION__, enable);
	
	DbgSclrFlgTkr.dvo_dual_decoder_flag = enable;
	if ( 0== enable) {
		rtk_hal_vsc_Setdualdecoder_run(0);
		Scaler_DualChannelRpc(0);
	} else {
		if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
			rtk_hal_vsc_Setdualdecoder_run(1);
			Scaler_DualChannelRpc(1);
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "dual decoder start to run 1\n");
		}
	}
}

unsigned char rtk_hal_vsc_Getdualdecoder(void)
{
	return DbgSclrFlgTkr.dvo_dual_decoder_flag;

}
void  rtk_hal_vsc_Setdualdecoder_run(unsigned char flag)
{
	DbgSclrFlgTkr.dvo_dual_decoder_run = flag;
}
unsigned char rtk_hal_vsc_Getdualdecoder_run(void)
{
	return DbgSclrFlgTkr.dvo_dual_decoder_run;
}
unsigned char	rtk_hal_vsc_GetMVOPStatus(VIDEO_WID_T wId, BOOLEAN *bMVOPEnable)
{
	//this is vo smoothtoggle operation:when change timing,with qing_liu code
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	return TRUE;

}
/*api which have protect by forcebg_semaphore*/
void set_ATV_passthrought_output_flag(unsigned char display, unsigned char flag)
{
	if(display == SLR_MAIN_DISPLAY)
		DbgSclrFlgTkr.Main_ATV_PassThrought_output_flag = flag;
}

unsigned int osdsample_addr = 0;

unsigned char rtk_hal_vsc_showosdsample(unsigned char bonoff)
{

	GRAPHIC_LAYERS_OBJECT grahpic_obj;
	GDMA_LAYER_OBJECT *picObj;

	memset(&grahpic_obj, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
	picObj = &grahpic_obj.layer[0];
	grahpic_obj.layer_num = 1;

	picObj->src_type = SRC_NORMAL;
	picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	/*picObj->plane = VO_GRAPHIC_OSD1;*/
	picObj->colorkey = -1;
	picObj->alpha = 0;
	picObj->x = 0;
	picObj->y = 0;
	picObj->width = 260;				// image width
	picObj->height = 200;				// image height
	picObj->pitch = picObj->width*4;

	if(bonoff == TRUE)
	{
		osdsample_addr = (unsigned int)dvr_malloc(1024*1024*3);
	}

	//picObj->address = (unsigned int)virt_to_phys((void*)osdsample_addr);	// set image address
	picObj->address = (unsigned int)dvr_to_phys((void*)osdsample_addr);	// set image address
	picObj->dst_x = 0;
	picObj->dst_y = 0;
	picObj->dst_width = 260;	 // image width
	picObj->dst_height = 200; // image height
	picObj->plane_ar.value = 0xffffffff;
	picObj->plane_gb.value = 0xffffffff;
	picObj->clear_x.value = 0;
	picObj->clear_y.value = 0;
	picObj->syncstamp = 0;
	picObj->show = bonoff;	  // always show the picture by normal update pic flow
	picObj->compressed = 0;
	/*picObj->layer_used = 1;*/
	/*osd_comp_receive_picture(&com_picObj);*/
#ifdef CONFIG_RTK_KDRV_GDMA
	GDMA_ReceiveGraphicLayers(&grahpic_obj);
#endif

	if(bonoff == FALSE)
	{
		dvr_free((void *)osdsample_addr);
		osdsample_addr = 0;
	}
	return 0;
}

// Dolby Vision IDMA enable control
unsigned char rtk_hal_vsc_SetHdrDolbyVisionIdmaEnable(unsigned char bEnable)
{
	vfe_hdmi_timing_info_t vfehdmitiminginfo;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[DolbyVision] %s.%d\n", __FUNCTION__, __LINE__);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"en=%d, type/idma=%d/%d\n", bEnable, DisplayModeInputInfo.type, Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA));
	if(bEnable){
		if(DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI)
		{
			DisplayModeInputInfo.type = VSC_INPUTSRC_VDEC;
			if(0!=vfe_hdmi_drv_get_display_timing_info(&vfehdmitiminginfo, SLR_MAIN_DISPLAY))
				return FALSE;
			Scaler_SET_VSCDispinfo_WithVFEHMDI(SLR_MAIN_DISPLAY, vfehdmitiminginfo);

			set_HDMI_HDR_mode(HDR_DOLBY_HDMI);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			DV_HDMI_Init();
#endif
			drvif_I3DDMA_Init();
			Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, true);
			drivf_I3DDMA_3D_config();
			DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_OFF)
#endif
			down(&VSC_Semaphore);
	  		rtk_output_connect(SLR_MAIN_DISPLAY);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_OFF)
#endif
	   		up(&VSC_Semaphore);

			return TRUE;
		}else{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[WARN][DolbyVision][%d] Not in HDMI source\n", DisplayModeInputInfo.type);
		}
	}
	else if(DisplayModeInputInfo.type == VSC_INPUTSRC_VDEC){
		if(Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == true)
		{
			if(IoReg_Read32(H3DDMA_I3DDMA_enable_reg) & _BIT0){
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[DolbyVision] Disable IDMA HW\n");
				I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);
				msleep(40/*100*/); // wait DMA write done

				// [IDMA] allocate/release IDMA memory dynamic
				if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == TRUE)
					I3DDMA_DolbyVision_HDMI_DeInit();
			}

			Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, false);
			DisplayModeInputInfo.type = VSC_INPUTSRC_HDMI;
			DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
		}
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_OFF)
#endif
		down(&VSC_Semaphore);
		rtk_output_connect(SLR_MAIN_DISPLAY);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status() == SLR_DV_HDMI_DETECT_OFF)
#endif
		up(&VSC_Semaphore);
	}

	if(!bEnable)
		set_HDMI_HDR_mode(HDR_MODE_DISABLE);
	return 0;
}



#ifdef CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
// HDR10 IDMA enable control
unsigned char rtk_hal_vsc_SetHdr10IdmaEnable(unsigned char bEnable)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[HDR10] %s.%d\n", __FUNCTION__, __LINE__);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"en=%d, type/idma=%d/%d\n", bEnable, DisplayModeInputInfo.type, Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA));
	if(bEnable){
		if(DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI)
		{
			 DisplayModeInputInfo.type = VSC_INPUTSRC_VDEC;
			 DisplayModeInputInfo.resourceIndex = 0;
			 vfe_hdmi_timing_info_t vfehdmitiminginfo;
			if(0!=vfe_hdmi_drv_get_display_timing_info(&vfehdmitiminginfo, SLR_MAIN_DISPLAY))
				return FALSE;
			Scaler_SET_VSCDispinfo_WithVFEHMDI(SLR_MAIN_DISPLAY, vfehdmitiminginfo);

			set_HDMI_HDR_mode(HDR_HDR10_HDMI);
			drvif_I3DDMA_Init();
			Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, true);
			drivf_I3DDMA_3D_config();
			DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;

			if(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_OFF)
			down(&VSC_Semaphore);
	  		rtk_output_connect(SLR_MAIN_DISPLAY);
			if(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_OFF)
	   		up(&VSC_Semaphore);

			return TRUE;
		}else{
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[WARN][HDR10][%d] Not in HDMI source\n", DisplayModeInputInfo.type);
		}
	}
	else if(DisplayModeInputInfo.type = VSC_INPUTSRC_VDEC){
		if(Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == true)
		{
			if(IoReg_Read32(H3DDMA_I3DDMA_enable_reg) & _BIT0){
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[HDR10] Disable IDMA HW\n");
				I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);
				msleep(40/*100*/); // wait DMA write done

				// [IDMA] allocate/release IDMA memory dynamic
				if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == TRUE)
					drvif_I3DDMA_DeInit();
			}

			Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, false);
			DisplayModeInputInfo.type = VSC_INPUTSRC_HDMI;
			DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
		}
		if(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_OFF)
		down(&VSC_Semaphore);
  		rtk_output_connect(SLR_MAIN_DISPLAY);
		if(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_OFF)
   		up(&VSC_Semaphore);
	}

	if(!bEnable)
		set_HDMI_HDR_mode(HDR_MODE_DISABLE);
	return 0;
}
#endif


unsigned char rtk_hal_vsc_SetZorder(VSC_SET_ZORDER_T zOrderMain,VSC_SET_ZORDER_T zOrderSub)//(unsigned char uZorder,unsigned char uAlpha)
{
	zOrderMain.uAlpha = zOrderMain.uAlpha%16;
	zOrderSub.uAlpha = zOrderSub.uAlpha%16;

	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
	{
		int ret;
		drvif_color_setpiprgbcontrastbrightness(zOrderMain.uAlpha);
		if (0 != (ret =Scaler_SendRPC(SCALERIOC_SENDZORDER, (zOrderMain.uZorder<<8) + zOrderSub.uZorder, RPC_SEND_VALUE_ONLY))) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"ret=%d, rtk_hal_vsc_SetZorder SCALERIOC_SENDZORDER fail !!!\n", ret);
			return FALSE;
		}
	}
	return TRUE;
}

unsigned char rtk_hal_vsc_makeColoredVideo(VSC_VIDEO_COLOR_TYPE_T videoColor)
{
	osdovl_mixer_ctrl2_RBUS mixer_ctrl2_reg;
	ppoverlay_main_background_color1_RBUS main_background_color1_reg;
	ppoverlay_main_background_color2_RBUS main_background_color2_reg;
	ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
	ppoverlay_dispd_smooth_toggle1_RBUS	 dispd_smooth_toggle1_reg;
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl_reg;
	static unsigned char m_memc_bg_en = 0;

	static VIDEO_RECT_T originalSize={0,0,0,0};
	unsigned int timeout=0x3fffff;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_makeColoredVideo (%d) \n", videoColor);

	if(videoColor == VSC_VIDEO_COLOR_WHITE){
		if((originalSize.x==0)&&(originalSize.y==0)&&(originalSize.w==0)&&(originalSize.h==0)){
			rtk_hal_vsc_GetOutputRegion(VIDEO_WID_0, &originalSize);
			rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"originalSize (%d.%d.%d.%d) \n", originalSize.x, originalSize.y, originalSize.w, originalSize.h);
		}
		OutpuLocalDimmingPatMode = TRUE;
		//set free run timing
		drivf_scaler_reset_freerun_60Hz();
		// turn off osd mixer
		mixer_ctrl2_reg.regValue = IoReg_Read32(OSDOVL_Mixer_CTRL2_reg);
		mixer_ctrl2_reg.mixer_en = 0;
		IoReg_Write32(OSDOVL_Mixer_CTRL2_reg, mixer_ctrl2_reg.regValue);
		IoReg_Write32(OSDOVL_OSD_Db_Ctrl_reg, 0);

		//frank@0220 check memc bg status and clear memc bg
		memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
		m_memc_bg_en = memc_mux_ctrl_reg.memc_out_bg_en;
		if(m_memc_bg_en){
			//enable UZU DTG double buffer.
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
			double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 1;
			double_buffer_ctrl_reg.uzudtg_dbuf_vsync_sel = 3;//using uzudtg vsync
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
			memc_mux_ctrl_reg.memc_out_bg_en = 0;
			IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
			//set apply
			double_buffer_ctrl_reg.uzudtgreg_dbuf_set = 1;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
		}

		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

		main_background_color1_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color1_reg);
		main_background_color2_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color2_reg);
		main_background_color1_reg.m_bg_b = 0x3fff;
		main_background_color1_reg.m_bg_g = 0x3fff;
		main_background_color2_reg.m_bg_r = 0x3fff;
		IoReg_Write32(PPOVERLAY_Main_Background_Color1_reg, main_background_color1_reg.regValue);
		IoReg_Write32(PPOVERLAY_Main_Background_Color2_reg, main_background_color2_reg.regValue);
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		main_display_control_rsv_reg.m_force_bg = 1;
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		do{
			dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
		}while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply==1) && (--timeout));

		if(timeout==0){
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "[%s]WARNING! wait double buf timeout!\n", __FUNCTION__);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		}else{
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		}
/*
		int x=0;
		VIDEO_RECT_T output_region;

		while(1){
			output_region.x= x;
			output_region.y = 0;
			output_region.w = 150;
			output_region.h = 2160;

			rtk_hal_vsc_SetOutputRegion(0, output_region);

			if(x<=3690){
				x+=20;
			}else
				x=0;
		}
*/
	}else{
		mixer_ctrl2_reg.regValue = IoReg_Read32(OSDOVL_Mixer_CTRL2_reg);
		mixer_ctrl2_reg.mixer_en = 1;
		IoReg_Write32(OSDOVL_Mixer_CTRL2_reg, mixer_ctrl2_reg.regValue);
		IoReg_Write32(OSDOVL_OSD_Db_Ctrl_reg, 0);

		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		main_background_color1_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color1_reg);
		main_background_color2_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color2_reg);
		main_background_color1_reg.m_bg_b = 0;
		main_background_color1_reg.m_bg_g = 0;
		main_background_color2_reg.m_bg_r = 0;
		IoReg_Write32(PPOVERLAY_Main_Background_Color1_reg, main_background_color1_reg.regValue);
		IoReg_Write32(PPOVERLAY_Main_Background_Color2_reg, main_background_color2_reg.regValue);


		//frank@0220 revert memc bg
		if(m_memc_bg_en){
			//disable UZU DTG double buffer.
			double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
			double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 0;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
			memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
			memc_mux_ctrl_reg.memc_out_bg_en = m_memc_bg_en;
			m_memc_bg_en = 0;
			IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
		}
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		do{
			dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
		}while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply==1) && (--timeout));

		if(timeout==0){
			rtd_printk(KERN_INFO, TAG_NAME_VSC, "[%s]WARNING! wait double buf timeout!\n", __FUNCTION__);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		}else{
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		}
		rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"recovery originalSize (%d.%d.%d.%d) \n", originalSize.x, originalSize.y, originalSize.w, originalSize.h);
		OutpuLocalDimmingPatMode = FALSE;

		if((originalSize.x==0)&&(originalSize.y==0)&&(originalSize.w==0)&&(originalSize.h==0)){
			//do nothing
		}else{
			rtk_hal_vsc_SetOutputRegion(VIDEO_WID_0, originalSize, 0, 0);
		}
		memset((void*)&originalSize, 0, sizeof(VIDEO_RECT_T));
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		scaler_disp_smooth_variable_settingByDisp(0);

        //frank@01062016 add below flow to avoid demo mode exit will have garbage
        if(!Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY)){
            down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
            if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
            {
                scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);/*disable forcebg*/
            }
            up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
        }
	}
	return 1;
}

unsigned char rtk_hal_vsc_dm_open(void)
{
	down(&DM_HDR_Semaphore);
	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_open, It is OTT, so return true!");
		up(&DM_HDR_Semaphore);
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_open, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result())
	{
		DbgSclrFlgTkr.hdmi_dolby_vision_flag = TRUE;
	}
	else
#endif
	{
		/*HDR10 flow*/
		DbgSclrFlgTkr.hdmi_dolby_vision_flag = FALSE;//in HDR10 HDMI, disable Dolby version flag @Crixus 20160313
	}
	Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_HDR_OPEN);

	up(&DM_HDR_Semaphore);
	return TRUE;
}


unsigned char rtk_hal_vsc_dm_close(void)
{
	down(&DM_HDR_Semaphore);
	rtd_maskl(H3DDMA_I3DDMA_MDP_CR_reg,~(_BIT3|_BIT4), 0);
	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_close, It is OTT, so return true!");
		up(&DM_HDR_Semaphore);
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_close, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
	DbgSclrFlgTkr.hdmi_dolby_vision_flag = FALSE;
	up(&DM_HDR_Semaphore);
	return TRUE;
}

void Share_Memory_Set_DM_Connect_Flag(unsigned char enable)
{
	unsigned int *dm_connect_flag = NULL;
	unsigned int *pulTemp = NULL;
	unsigned int i = 0, ulItemCount = 0;

	dm_connect_flag = (unsigned int *)Scaler_GetShareMemVirAddr(SCALERIOC_DM_CONNECT_FLAG);
	*dm_connect_flag = enable;

	ulItemCount = sizeof(unsigned int) /  sizeof(UINT32);
	pulTemp = dm_connect_flag;
	for (i = 0; i < ulItemCount; i++)
		pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);
}

unsigned char rtk_hal_vsc_dm_connect(void)
{
	rtd_printk(KERN_INFO, TAG_NAME_VSC,"rtk_hal_vsc_dm_connect\n");
	down(&DM_HDR_Semaphore);
	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		Check_DV_Mode();//Check dolby mode again. Dolby 64 patch
#endif
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_connect, It is OTT, so so return true!");
		Share_Memory_Set_DM_Connect_Flag(true);
		up(&DM_HDR_Semaphore);

#ifdef CONFIG_HDR_SDR_SEAMLESS
        if(get_OTT_HDR_mode() != HDR_DOLBY_COMPOSER)
        {
            set_OTT_HDR_mode(HDR_HDR10_VDEC);
    		down(&HDR_Setting_Semaphore);
    		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
    		{
    			spin_lock_irq(get_vdec_seamless_change_spinlock());//lock i3ddma change spinlock
    			set_vdec_seamless_change_flag(TRUE);
    			spin_unlock_irq(get_vdec_seamless_change_spinlock());//unlock i3ddma change  spinlock
    		}
    		up(&HDR_Setting_Semaphore);
        }
#endif
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_connect, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}

	if(Scaler_HDR10_Hdmi_Get_Detect_Status() != SLR_HDR10_HDMI_HDR_OPEN)
	{
		rtd_printk(KERN_INFO, TAG_NAME_VSC,"hdmi hdr10 is not open\n");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}

		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_HDR_MODE_ENABLED);
			
#ifdef CONFIG_DUAL_CHANNEL
	if ((Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_HDMI) && (Get_Live_zoom_mode()==LIVE_ZOOM_OFF))
	{
		/*qiangzhou:livezoom case ,hdr will ng for here,so livezoom case not enter this code*/
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"sub hdmi hdr, so no enable hdr\n");
		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
#endif

	/*hdmi dolby detect ok, set dolby_vision_flag=true*/
	if(DbgSclrFlgTkr.hdmi_dolby_vision_flag)
	{
		set_HDMI_HDR_mode(HDR_DOLBY_HDMI);
		rtd_printk(KERN_INFO, TAG_NAME_VSC,"enable hdr dolby hdmi\n");
	}
	else{
		/*HDR10 flow*/
		set_HDMI_HDR_mode(HDR_HDR10_HDMI);
		rtd_printk(KERN_INFO, TAG_NAME_VSC,"enable hdr10 hdmi\n");
	}


	if(!DbgSclrFlgTkr.hdmi_dolby_vision_flag)//HDMI HDR10 case. Wait OTT dolby run. should no wait
	{
		unsigned char timeout = 10;
#ifdef CONFIG_RTK_KDRV_DV
		while(check_ott_dolby_update_run() && timeout)
		{
			msleep(1);
			timeout --;
		}
#endif
	}

#ifdef CONFIG_HDR_SDR_SEAMLESS
	if(get_HDMI_HDR_mode() == HDR_HDR10_HDMI)
	{
//		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
//			dynamic_change_hdr_setting(TRUE);
	}
	else
	{
		if(DbgSclrFlgTkr.hdmi_dolby_vision_flag){
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			DV_HDMI_Init();
#endif
		}
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
	}
#else
	Scaler_Send_VoType_VOMDA(VO_VSC_SRC_HDMI,255);
	if(DbgSclrFlgTkr.hdmi_dolby_vision_flag) {
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		DV_HDMI_Init();
#endif
	}
	//Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_THROUGH_I3DDMA, true);
	DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
#endif
	up(&DM_HDR_Semaphore);
	return TRUE;
}


unsigned char rtk_hal_vsc_dm_disconnect(void)
{
	rtd_printk(KERN_INFO, TAG_NAME_VSC,"rtk_hal_vsc_dm_disconnect\n");
	down(&DM_HDR_Semaphore);
	//reset Dolby HDR
	if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC) || get_HDMI_HDR_mode() == HDR_DOLBY_HDMI){
		//Scaler_Dolby_HDR_reset(); //Mark by will. Move to scaler
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_disconnect, reset Dolby HDR\n");
	}

	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_disconnect, It is OTT, so return true!");
		Share_Memory_Set_DM_Connect_Flag(false);
		up(&DM_HDR_Semaphore);
#ifdef CONFIG_HDR_SDR_SEAMLESS
        if(get_OTT_HDR_mode() == HDR_HDR10_VDEC)
        {
            set_OTT_HDR_mode(HDR_MODE_DISABLE);
    		down(&HDR_Setting_Semaphore);
    		if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
				&& !Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY))
    		{
    			spin_lock_irq(get_vdec_seamless_change_spinlock());//lock vdec semaless change spinlock
    			set_vdec_seamless_change_flag(TRUE);
    			spin_unlock_irq(get_vdec_seamless_change_spinlock());//unlock vdec semaless  change  spinlock
    		}
    		up(&HDR_Setting_Semaphore);
        }
#endif
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_dm_disconnect, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
	//if(Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == true)
	if(DbgSclrFlgTkr.hdmi_dolby_vision_flag)
	{
		//DV_Stop(void)
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_DISABLE);
#endif
	}

#ifdef CONFIG_HDR_SDR_SEAMLESS
	if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI)
	{
		if(Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_HDMI)
			Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
		if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
		//willychou add WOSQRTK-8674/WOSQRTK-9024,HDMI clock change -> _MODE_STATE_SEARCH -> stop rtk_check_signal and HDMI_set_detect_flag(TRUE)
		//-> no signal happen -> util HDMI_set_detect_flag(TRUE) again
		down(get_hdmi_detectsemaphore());
		if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
		up(get_hdmi_detectsemaphore());
	}

//#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
//#endif
	if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI)
	{
		set_HDMI_HDR_mode(HDR_MODE_DISABLE);
	}
	else
	{
		set_HDMI_HDR_mode(HDR_MODE_DISABLE);
//		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
//			dynamic_change_hdr_setting(FALSE);
	}


#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	Scaler_HDR_DolbyVision_Hdmi_SetDetectEnable(_ENABLE, _DISABLE);
#endif


#else
	if(Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_HDMI)
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);

	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);

	//willychou add WOSQRTK-8674/WOSQRTK-9024,HDMI clock change -> _MODE_STATE_SEARCH -> stop rtk_check_signal and HDMI_set_detect_flag(TRUE)
	//-> no signal happen -> util HDMI_set_detect_flag(TRUE) again
	down(get_hdmi_detectsemaphore());
	if(get_HDMI_Global_Status() == SRC_CONNECT_DONE) HDMI_set_detect_flag(TRUE);
	up(get_hdmi_detectsemaphore());

//#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
//#endif

	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_THROUGH_I3DDMA, false);
	DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
	set_HDMI_HDR_mode(HDR_MODE_DISABLE);
	Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_HDMI, 255);

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	Scaler_HDR_DolbyVision_Hdmi_SetDetectEnable(_ENABLE, _DISABLE);
#endif
#endif
	up(&DM_HDR_Semaphore);
	return TRUE;
}

void scaler_dolby_hdmi_smooth_toggle(UINT8 isSDRtoEDR)/*1==SDR->EDR   0==EDR->SDR*/
{
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if(isSDRtoEDR)
	{
		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_HDR_MODE_ENABLED);
	}
	else
	{
		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
	}
#endif

	DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
	DbgSclrFlgTkr.Main_Run_Scaler_flag =TRUE;
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
}

extern void I3DDMA_Set_Metadata_Vgip(void);
void scaler_dolby_enable_idmacap2_metadata(unsigned char enable)
{
	if(enable)
	{

		if(I3DDMA_DolbyVision_MetaData_Init() == 1)
		{
			rtd_printk(KERN_EMERG, TAG_NAME_VSC,"idma metadata alloc memory fail\n");
			return;
		}
		I3DDMA_DolbyVision_buf_setting();
		I3DDMA_Set_Metadata_Vgip();
	}
	else
	{
		I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);
		I3DDMA_DolbyVision_MetaData_DeInit();
	}
}

#ifdef CONFIG_FORCE_RUN_I3DDMA
unsigned char scaler_force_run_idma(unsigned char display, VSC_INPUT_TYPE_T inputSrctype)
{
	if(DbgSclrFlgTkr.Main_Scaler_Stop_flag)
		return FALSE;

	set_force_change_vo_flag(0, TRUE);//force update vo info
	if(Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_HDR_MODE_ENABLED)
		Scaler_Send_VoType_VOMDA(VO_VSC_SRC_HDMI,  255);
	else
		Scaler_Send_VoType_VOMDA(VO_VSC_SRC_HDMI,  0xfa);
	down(&VSC_Semaphore);
	drvif_mode_resetmode(display);
	drvif_I3DDMA_Init();

	if((inputSrctype == VSC_INPUTSRC_VDEC) || (inputSrctype == VSC_INPUTSRC_JPEG))
	{
		rtd_printk(KERN_EMERG, TAG_NAME_VSC,"vo source,return\n");
		up(&VSC_Semaphore);
		return TRUE;
	}
	else if(inputSrctype == VSC_INPUTSRC_ADC)//ypp,VGA
	{
		down(get_adc_detectsemaphore());
		Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_ADC_Dispinfo());//now for test, only for ypp timing info
		if(vsc_timinginfo_check() == FALSE)
		{
			up(get_adc_detectsemaphore());
			up(&VSC_Semaphore);
			rtd_printk(KERN_ERR, TAG_NAME_VSC,"adc vsc_timinginfo_check error\n");
			return FALSE;
		}
		if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > 2000)//mean 4095 no support
		{
			up(get_adc_detectsemaphore());
			up(&VSC_Semaphore);
			rtd_printk(KERN_ERR, TAG_NAME_VSC,"scaler_force_run_idma adc vsc_timinginfo_check no support error\n");
			return FALSE;
		}
		ADC_set_detect_flag(FALSE);
		up(get_adc_detectsemaphore());

		// Scart RGB
		if(get_ADC_Input_Source() == _SRC_SCART_RGB)
		{
			if(!drivf_i3ddma_config(display, VGIP_SRC_ATV))
			{
				up(&VSC_Semaphore);
				rtd_printk(KERN_EMERG, TAG_NAME_VSC,"adc drivf_i3ddma_config error\n");
				return FALSE;
			}
		}
		// YPP and VGA
		else
		{
			if(!drivf_i3ddma_config(display, VGIP_SRC_ADC))
			{
				up(&VSC_Semaphore);
				rtd_printk(KERN_EMERG, TAG_NAME_VSC,"adc drivf_i3ddma_config error\n");
				return FALSE;
			}
			fw_scaler_set_sample(display, _ENABLE);
		}

		ADC_VSC_Setting(get_ADC_Input_Source());
		fw_scaler_adc_nolock_wdg_ctrl(display, FALSE);//Disable adc_nolock_wdg
		drvif_mode_enable_dma_onlinemeasure();//Enable dma online measure
	}
	else if(inputSrctype == VSC_INPUTSRC_AVD)
	{
		down(get_vdc_detectsemaphore());
		Scaler_SET_VSCDispinfo_WithVFEDispinfo(display, Get_AVD_ScalerDispinfo());
		if(vsc_timinginfo_check() == FALSE)
		{
			up(get_vdc_detectsemaphore());
			up(&VSC_Semaphore);
			rtd_printk(KERN_EMERG, TAG_NAME_VSC,"avd vsc_timinginfo_check error\n");
			return FALSE;
		}
		up(get_vdc_detectsemaphore());
		if(!drivf_i3ddma_config(display, VGIP_SRC_ATV))
		{
			up(&VSC_Semaphore);
			rtd_printk(KERN_EMERG, TAG_NAME_VSC,"avd drivf_i3ddma_config error\n");
			return FALSE;
		}
		drvif_mode_enable_dma_onlinemeasure();//Enable dma online measure
	}
	else if(inputSrctype == VSC_INPUTSRC_HDMI)
	{

		vfe_hdmi_timing_info_t vfehdmitiminginfo;
		down(get_hdmi_detectsemaphore());
		if(0 != vfe_hdmi_drv_get_display_timing_info(&vfehdmitiminginfo, display))
		{
			up(get_hdmi_detectsemaphore());
			up(&VSC_Semaphore);
			rtd_printk(KERN_EMERG, TAG_NAME_VSC,"vfe_hdmi_drv_get_display_timing_info error\n");
			return FALSE;
		}
		Scaler_SET_VSCDispinfo_WithVFEHMDI(display, vfehdmitiminginfo);
		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		Scaler_HDR10_Hdmi_Set_Input_ACT_WID_info(vfehdmitiminginfo.active.w);
		#endif

		if(vsc_timinginfo_check() == FALSE)
		{
			up(get_hdmi_detectsemaphore());
			up(&VSC_Semaphore);
			rtd_printk(KERN_EMERG, TAG_NAME_VSC,"hdmi vsc_timinginfo_check error\n");
			return FALSE;
		}

		HDMI_set_detect_flag(FALSE);
		up(get_hdmi_detectsemaphore());

		if(!drivf_i3ddma_config(display, VGIP_SRC_TMDS))
		{
			up(&VSC_Semaphore);
			rtd_printk(KERN_EMERG, TAG_NAME_VSC,"hdmi drivf_i3ddma_config error\n");
			return FALSE;
		}

		#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		if(DbgSclrFlgTkr.hdmi_dolby_vision_flag)
		{
			Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_ENABLE);
		}
		#endif

		drvif_mode_enable_dma_onlinemeasure();//Enable dma online measure
	}
	up(&VSC_Semaphore);
	return TRUE;
}

unsigned char scaler_atv_force_run_idma(void)
{
	if (ATV_forcei3ddma == 1)
		;	//	ATV will force i3ddma scaler flow
	else if(DbgSclrFlgTkr.Main_Output_Set_flag || DbgSclrFlgTkr.Main_Scaler_Stop_flag || DbgSclrFlgTkr.Main_Run_Scaler_flag)
		return FALSE;
	set_force_change_vo_flag(0, TRUE);//force update vo info
	Scaler_Send_VoType_VOMDA(VO_VSC_SRC_HDMI,  0xfa);
	down(&VSC_Semaphore);
	drvif_mode_resetmode(SLR_MAIN_DISPLAY);
	drvif_I3DDMA_Init();

	down(get_vdc_detectsemaphore());
	Scaler_SET_VSCDispinfo_WithVFEDispinfo(SLR_MAIN_DISPLAY, Get_AVD_ScalerDispinfo());
	if(vsc_timinginfo_check() == FALSE)
	{
		up(get_vdc_detectsemaphore());
		up(&VSC_Semaphore);
		pr_emerg("avd vsc_timinginfo_check error\n");
		return FALSE;
	}
	up(get_vdc_detectsemaphore());
	if(!drivf_i3ddma_config(SLR_MAIN_DISPLAY, VGIP_SRC_ATV))
	{
		up(&VSC_Semaphore);
		rtd_printk(KERN_EMERG, TAG_NAME_VSC,"atv drivf_i3ddma_config error\n");
		return FALSE;
	}
	drvif_mode_enable_dma_onlinemeasure();//Enable online measure

	up(&VSC_Semaphore);

	return TRUE;
}
#endif

extern unsigned char rtk_hal_vsc_hdr_disconnect(void);
unsigned char rtk_hal_vsc_hdr_open(void)
{
	rtd_printk(KERN_EMERG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_open\n");

	down(&DM_HDR_Semaphore);
	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_open, It is OTT, so return true!");
		up(&DM_HDR_Semaphore);
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_open, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	/*hdmi dolby detect ok, set dolby_vision_flag=true*/
	if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result())
	{
		DbgSclrFlgTkr.hdmi_dolby_vision_flag = TRUE;
	}
	else{
		/*HDR10 flow*/
		DbgSclrFlgTkr.hdmi_dolby_vision_flag = FALSE;//in HDR10 HDMI, disable Dolby version flag @Crixus 20160313
	}
	Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_HDR_OPEN);
#endif
	up(&DM_HDR_Semaphore);
	return TRUE;
}


unsigned char rtk_hal_vsc_hdr_close(void)
{
	down(&DM_HDR_Semaphore);
	rtd_maskl(H3DDMA_I3DDMA_MDP_CR_reg,~(_BIT3|_BIT4), 0);
	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_close, It is OTT, so return true!");
		up(&DM_HDR_Semaphore);
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_close, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if(Scaler_HDR10_Hdmi_Get_Detect_Status() != SLR_HDR10_HDMI_HDR_OPEN)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"hdmi hdr10 is connected, run disconnect\n");
		up(&DM_HDR_Semaphore);
		rtk_hal_vsc_dm_disconnect();
		down(&DM_HDR_Semaphore);
		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
		up(&DM_HDR_Semaphore);
		return FALSE;
	}

	Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
#endif
	DbgSclrFlgTkr.hdmi_dolby_vision_flag = FALSE;
	up(&DM_HDR_Semaphore);
	return TRUE;
}


unsigned char rtk_hal_vsc_hdr_connect(VSC_HDR_TYPE_T hdr_type)
{
	vfe_hdmi_timing_info_t vfehdmitiminginfo;
	down(&DM_HDR_Semaphore);
	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		Check_DV_Mode();//Check dolby mode again. Dolby 64 patch
#endif
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_connect, It is OTT, so so return true!");
		up(&DM_HDR_Semaphore);
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_connect, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if(Scaler_HDR10_Hdmi_Get_Detect_Status() != SLR_HDR10_HDMI_HDR_OPEN)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"hdmi hdr10 is not open\n");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_HDR_MODE_ENABLED);

	if ((Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_HDMI) && (Get_Live_zoom_mode()==LIVE_ZOOM_OFF))
	{
		/*qiangzhou:livezoom case ,hdr will ng for here,so livezoom case not enter this code*/
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"sub hdmi hdr, so no enable hdr\n");
		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
#endif
	msleep(10); //wait vsc_tsk run reset mode over
	down(&VSC_Semaphore);//protect race condition for smartfit
	down(get_hdmi_detectsemaphore());
	drvif_hdmi_set_no_polarity_inverse(TRUE);//no allow vgip to set h v polarity inverse before measure
	if(0!=vfe_hdmi_drv_get_display_timing_info(&vfehdmitiminginfo, SLR_MAIN_DISPLAY))
	{
		drvif_hdmi_set_no_polarity_inverse(FALSE);
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"hdmi hdr10  vfe_hdmi_drv_get_display_timing_info error!\n");

		/*dm_connect get hdmi timing info error, rerun dm flow*/
		vfe_hdmi_drv_handle_on_line_measure_error(0);
		vfe_hdmi_drv_adapter();
		if (get_HDMI_Global_Status() == SRC_CONNECT_DONE) {
			Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_HDMI, TRUE);/*Let Webos get zero timing*/
			HDMI_set_detect_flag(TRUE);
		}

		up(get_hdmi_detectsemaphore());
		up(&VSC_Semaphore);
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
	drvif_hdmi_set_no_polarity_inverse(FALSE);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	Scaler_HDR10_Hdmi_Set_Input_ACT_WID_info(vfehdmitiminginfo.active.w);
#endif

	Scaler_SET_VSCDispinfo_WithVFEHMDIHDR(vfehdmitiminginfo);
	up(get_hdmi_detectsemaphore());
	if(DbgSclrFlgTkr.hdmi_dolby_vision_flag) {//Move to set hdr mode first. Let OTT update know hdmi mode
		set_HDMI_HDR_mode(HDR_DOLBY_HDMI);
	} else{
		set_HDMI_HDR_mode(HDR_HDR10_HDMI);
	}

	Scaler_Send_VoType_VOMDA(VO_VSC_SRC_HDMI,  255);
	if(DbgSclrFlgTkr.hdmi_dolby_vision_flag) {
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		DV_HDMI_Init();
#endif
	}

	drvif_I3DDMA_Init();

	if(!DbgSclrFlgTkr.hdmi_dolby_vision_flag)//HDMI HDR10 case. Wait OTT dolby run. should no wait
	{
		unsigned char timeout = 10;
#ifdef CONFIG_RTK_KDRV_DV
		while(check_ott_dolby_update_run() && timeout)
		{
			msleep(1);
			timeout --;
		}
#endif
	}
#if 1
	if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == TRUE) {
		if(I3DDMA_DolbyVision_HDMI_Init() == 1)
		{
			rtd_printk(KERN_EMERG, TAG_NAME_VSC,"i3ddma dolby/hdr10 not alloc memory, no run hdr!!!\n");
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
#endif
					up(&VSC_Semaphore);
			up(&DM_HDR_Semaphore);
			return FALSE;
		}
	}
#endif
	Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_THROUGH_I3DDMA, true);
	drivf_I3DDMA_3D_config();
	up(&VSC_Semaphore);
	DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;

	//DbgSclrFlgTkr.Main_Scaler_Stop_flag = FALSE;
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	if(DbgSclrFlgTkr.hdmi_dolby_vision_flag)
		Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_ENABLE);
#endif

	up(&DM_HDR_Semaphore);
	return TRUE;
}


unsigned char rtk_hal_vsc_hdr_disconnect(void)
{
	down(&DM_HDR_Semaphore);
	//reset Dolby HDR
	if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC) || get_HDMI_HDR_mode() == HDR_DOLBY_HDMI){
		//Scaler_Dolby_HDR_reset(); //Mark by will. Move to scaler
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_disconnect, reset Dolby HDR\n");
	}


	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_disconnect, It is OTT, so return true!");
		up(&DM_HDR_Semaphore);
		return TRUE;
	}
	else if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"rtk_hal_vsc_hdr_disconnect, It is not hdmi source, so can not call dm funciton!");
		up(&DM_HDR_Semaphore);
		return FALSE;
	}
	//if(Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == true)
	if(DbgSclrFlgTkr.hdmi_dolby_vision_flag)
	{
		//DV_Stop(void)
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
		Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(_DISABLE);
#endif
	}
	if(Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_HDMI)
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);

	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"[HDR10] Disable IDMA HW\n");
	I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);

	msleep(40/*100*/); // wait DMA write done

#if 1
	// [IDMA] allocate/release IDMA memory dynamic
	if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == TRUE)
		I3DDMA_DolbyVision_HDMI_DeInit();
#endif

	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_THROUGH_I3DDMA, false);
	DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
	set_HDMI_HDR_mode(HDR_MODE_DISABLE);
	Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_HDMI, 255);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	Scaler_HDR_DolbyVision_Hdmi_SetDetectEnable(_ENABLE, _DISABLE);
#endif
	up(&DM_HDR_Semaphore);
	return TRUE;
}
#ifdef CONFIG_I2RND_ENABLE
unsigned char rtk_hal_vsc_i2rnd_enable(unsigned char enable){
	if(enable == _ENABLE){
		if(vsc_i2rnd_initial_done == _DISABLE){
			drvif_scaler_i2rnd_initial();
			Scaler_I2rnd_set_enable(_ENABLE);
			i2rnd_default_register_setting();
		#ifdef CONFIG_PST_ENABLE
			drvif_scaler_pst_initial(_MAIN_MD);
			Scaler_main_md_pst_set_enable(_ENABLE);
		#endif
		}
		else{
			Scaler_I2rnd_set_enable(_ENABLE);
			i2rnd_default_register_setting();
		#ifdef CONFIG_PST_ENABLE
			Scaler_main_md_pst_set_enable(_ENABLE);
		#endif
		}
		vsc_i2rnd_initial_done = _ENABLE;
	}
	else{
		drvif_scaler_i2rnd_uninitial();
		Scaler_I2rnd_set_enable(_DISABLE);//uninitial i2rnd  to disable I2rnd flag @Crixus 20160801
		//vsc_i2rnd_initial_done = _DISABLE;
	#ifdef CONFIG_PST_ENABLE
		drvif_scaler_pst_uninitial(_MAIN_MD);
	#endif
	}
}
#endif


#ifdef CONFIG_I2RND_B05_ENABLE
unsigned char rtk_hal_vsc_i2rnd_b05_enable(unsigned char enable)
{
	if(enable == _ENABLE) {
	//               printk("in_b05_initial\n");
		drvif_scaler_i2rnd_b05_initial();
		Scaler_I2rnd_b05_set_enable(_ENABLE);
	//                drvif_scaler_i2rnd_b05_vodma_setting(SLR_MAIN_DISPLAY);
	} else {
		drvif_scaler_i2rnd_b05_uninitial();
		Scaler_I2rnd_b05_set_enable(_DISABLE);//uninitial i2rnd_b05  to disable I2rnd flag
		//printk("in_b05_uninitial\n");
	}
	return TRUE;
}
#endif

unsigned char rtk_hal_vsc_SetDelayBuffer(VIDEO_WID_T wId, UINT8 buffer){
	if(wId == VIDEO_WID_0){
		if(buffer > 0){
			drv_memory_Set_multibuffer_flag(_ENABLE);
			//drv_memory_Set_multibuffer_number(buffer+3);//buffer means that it need n more frame delay. Total buffer is n+3.
			drv_memory_Set_multibuffer_number(4);
		}
		else{
			drv_memory_Set_multibuffer_flag(_DISABLE);
			drv_memory_Set_multibuffer_number(0);
		}
	}

	return TRUE;
}
SMOOTH_TOGGLE_INFO temp_info_main;
void scaler_save_main_info(void)
{
	temp_info_main.IMD_SMOOTH_H_ACT_WID_PRE= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_WID_PRE);
	temp_info_main.IMD_SMOOTH_H_ACT_STA_PRE= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_STA_PRE);
	temp_info_main.IMD_SMOOTH_V_ACT_LEN_PRE= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_LEN_PRE);
	temp_info_main.IMD_SMOOTH_V_ACT_STA_PRE= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_STA_PRE);
	temp_info_main.IMD_SMOOTH_H_ACT_WID = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_WID);
	temp_info_main.IMD_SMOOTH_H_ACT_STA= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_STA);
	temp_info_main.IMD_SMOOTH_V_ACT_LEN= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_LEN);
	temp_info_main.IMD_SMOOTH_V_ACT_STA= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_STA);
	temp_info_main.IMD_SMOOTH_FRAMESYNC = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC);
	temp_info_main.IMD_SMOOTH_DI_WID= Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DI_WID);

#ifdef CONFIG_SDNR_CROP
	temp_info_main.IMD_SMOOTH_SDNRH_ACT_STA_PRE = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_STA_PRE);
	temp_info_main.IMD_SMOOTH_SDNRV_ACT_STA_PRE = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_STA_PRE);
	temp_info_main.IMD_SMOOTH_SDNRH_ACT_WID_PRE = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_WID_PRE);
	temp_info_main.IMD_SMOOTH_SDNRV_ACT_LEN_PRE = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN_PRE);
	temp_info_main.IMD_SMOOTH_SDNRH_ACT_STA = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_STA);
	temp_info_main.IMD_SMOOTH_SDNRV_ACT_STA = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_STA);
	temp_info_main.IMD_SMOOTH_SDNRH_ACT_WID = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_WID);
	temp_info_main.IMD_SMOOTH_SDNRV_ACT_LEN = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN);
#endif
	temp_info_main.IMD_SMOOTH_CapWid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CAP_WID);
	temp_info_main.IMD_SMOOTH_CapLen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CAP_LEN);
	temp_info_main.IMD_SMOOTH_MEM_ACT_HSTA = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_HSTA);
	temp_info_main.IMD_SMOOTH_MEM_ACT_VSTA = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_VSTA);
	temp_info_main.IMD_SMOOTH_MEM_ACT_LEN = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
	temp_info_main.IMD_SMOOTH_MEM_ACT_WID = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_WID);
	temp_info_main.IMD_SMOOTH_DispLen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN);
	temp_info_main.IMD_SMOOTH_DispWid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID);
	temp_info_main.IMD_SMOOTH_DISP_RTNR =Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR);
	temp_info_main.IMD_SMOOTH_DISP_10BIT = Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_10BIT);
	temp_info_main.IMD_SMOOTH_DISP_THRIP = Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP);
	temp_info_main.IMD_SMOOTH_DISP_MA3A = Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_MA3A);
	temp_info_main.IMD_SMOOTH_DISP_422CAP= Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422CAP);
	temp_info_main.IMD_SMOOTH_DISP_422= Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422);
}
void scaler_update_struct_info(unsigned char display)
{
	if (display == SLR_MAIN_DISPLAY) {
		pr_emerg("update main scaler struct info\n");
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_WID_PRE, temp_info_main.IMD_SMOOTH_H_ACT_WID_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_STA_PRE, temp_info_main.IMD_SMOOTH_H_ACT_STA_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_LEN_PRE, temp_info_main.IMD_SMOOTH_V_ACT_LEN_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_STA_PRE, temp_info_main.IMD_SMOOTH_V_ACT_STA_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_WID, temp_info_main.IMD_SMOOTH_H_ACT_WID);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_STA, temp_info_main.IMD_SMOOTH_H_ACT_STA);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_LEN, temp_info_main.IMD_SMOOTH_V_ACT_LEN);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_STA, temp_info_main.IMD_SMOOTH_V_ACT_STA);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC, temp_info_main.IMD_SMOOTH_FRAMESYNC);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DI_WID, temp_info_main.IMD_SMOOTH_DI_WID);

#ifdef CONFIG_SDNR_CROP
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_STA_PRE, temp_info_main.IMD_SMOOTH_SDNRH_ACT_STA_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_STA_PRE, temp_info_main.IMD_SMOOTH_SDNRV_ACT_STA_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_WID_PRE, temp_info_main.IMD_SMOOTH_SDNRH_ACT_WID_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN_PRE, temp_info_main.IMD_SMOOTH_SDNRV_ACT_LEN_PRE);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_STA, temp_info_main.IMD_SMOOTH_SDNRH_ACT_STA);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_STA, temp_info_main.IMD_SMOOTH_SDNRV_ACT_STA);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_WID, temp_info_main.IMD_SMOOTH_SDNRH_ACT_WID);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN, temp_info_main.IMD_SMOOTH_SDNRV_ACT_LEN);
#endif
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CAP_WID, temp_info_main.IMD_SMOOTH_CapWid);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CAP_LEN, temp_info_main.IMD_SMOOTH_CapLen);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_HSTA, temp_info_main.IMD_SMOOTH_MEM_ACT_HSTA);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_VSTA, temp_info_main.IMD_SMOOTH_MEM_ACT_VSTA);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN, temp_info_main.IMD_SMOOTH_MEM_ACT_LEN );
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_WID, temp_info_main.IMD_SMOOTH_MEM_ACT_WID);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN, temp_info_main.IMD_SMOOTH_DispLen);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID, temp_info_main.IMD_SMOOTH_DispWid);
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR, temp_info_main.IMD_SMOOTH_DISP_RTNR);
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_10BIT, temp_info_main.IMD_SMOOTH_DISP_10BIT);
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP, temp_info_main.IMD_SMOOTH_DISP_THRIP);
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_MA3A, temp_info_main.IMD_SMOOTH_DISP_MA3A);
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422CAP, temp_info_main.IMD_SMOOTH_DISP_422CAP);
		Scaler_DispSetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422, temp_info_main.IMD_SMOOTH_DISP_422);
	} else {
		pr_emerg("update sub scaler struct info\n");
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPH_ACT_WID_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_WID_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPH_ACT_STA_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPV_ACT_LEN_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_LEN_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPV_ACT_STA_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPH_ACT_WID,  Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_WID));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPH_ACT_STA));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_LEN));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_IPV_ACT_STA));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_FRAMESYNC, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DI_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DI_WID));

#ifdef CONFIG_SDNR_CROP
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRH_ACT_STA_PRE,  Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRV_ACT_STA_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRH_ACT_WID_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_WID_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN_PRE));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRH_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_STA));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRV_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_STA));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRH_ACT_WID));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_SDNRV_ACT_LEN));
#endif
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_CAP_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CAP_WID));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_CAP_LEN,  Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CAP_LEN));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_MEM_ACT_HSTA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_HSTA));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_MEM_ACT_VSTA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_VSTA));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_MEM_ACT_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_MEM_ACT_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_WID));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN));
		Scaler_DispSetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID));
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_RTNR, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_RTNR));
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_10BIT));
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_THRIP, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP));
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_MA3A, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_MA3A));
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422CAP));
		Scaler_DispSetStatus(SLR_SUB_DISPLAY, SLR_DISP_422, Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422));
	}
}

unsigned int VSC_PM_REGISTER_DATA[][2]
=
{
	//VGIP
	{SUB_VGIP_VGIP_CHN2_DELAY_reg, 0},
	{SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg, 0},
	{SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg, 0},
	{SUB_VGIP_VGIP_CHN2_CTRL_reg, 0},

	{VGIP_VGIP_CHN1_MISC_reg, 0},
	{VGIP_Data_Path_Select_reg, 0},
	{VGIP_VGIP_CHN1_DELAY_reg, 0},
	{VGIP_VGIP_CHN1_ACT_HSTA_Width_reg, 0},
	{VGIP_VGIP_CHN1_ACT_VSTA_Length_reg, 0},
	{VGIP_FRAMEPACKING_INTERLACE_CTRL1_reg, 0},
	{VGIP_FRAMEPACKING_INTERLACE_CTRL2_reg, 0},
	{VGIP_FRAMEPACKING_INTERLACE_CTRL3_reg, 0},
	{VGIP_FRAMEPACKING_INTERLACE_CTRL4_reg, 0},
	{VGIP_FRAMEPACKING_CTRL1_reg, 0},
	{VGIP_FRAMEPACKING_CTRL2_reg, 0},
	{VGIP_VGIP_CHN1_CTRL_reg, 0},
	{VGIP_INT_CTL_reg, 0},

	//RGB2YUV
	{RGB2YUV_Tab1_M11_M12_reg, 0},
	{RGB2YUV_Tab1_M13_M21_reg, 0},
	{RGB2YUV_Tab1_M22_M23_reg, 0},
	{RGB2YUV_Tab1_M31_M32_reg, 0},
	{RGB2YUV_Tab1_M33_YGain_reg,0},
	{RGB2YUV_Tab1_Yo_reg, 0},
	{RGB2YUV_ICH1_422to444_CTRL_reg, 0},
	{RGB2YUV_ICH1_RGB2YUV_CTRL_reg, 0},

	{RGB2YUV_Tab2_M11_M12_reg, 0},
	{RGB2YUV_Tab2_M13_M21_reg, 0},
	{RGB2YUV_Tab2_M22_M23_reg, 0},
	{RGB2YUV_Tab2_M31_M32_reg, 0},
	{RGB2YUV_Tab2_M33_Y_Gain_reg, 0},
	{RGB2YUV_Tab2_Yo_reg, 0},
#if 0//mac5p no these setting	of sub
	{RGB2YUV_ICH2_422to444_CTRL_reg, 0},
	{RGB2YUV_ICH2_RGB2YUV_CTRL_reg, 0},
#endif
	//UZD
	{SCALEDOWN_ICH1_sdnr_444to422_CTRL_reg, 0},
	{SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg, 0},
	{SCALEDOWN_ICH1_UZD_FIR_Coef_Tab1_C0_reg, 0},
	{SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C0_reg, 0},
	{SCALEDOWN_ICH1_hsd_3d_boundary_reg, 0},
	{SCALEDOWN_ICH1_UZD_Scale_Hor_Factor_reg, 0},
	{SCALEDOWN_ICH1_UZD_Scale_Ver_Factor_reg, 0},
	{SCALEDOWN_ICH1_UZD_Initial_Value_reg, 0},
	{SCALEDOWN_ICH1_UZD_Hor_Segment_reg, 0},
	{SCALEDOWN_ICH1_UZD_Hor_Delta1_reg, 0},
	{SCALEDOWN_ICH1_UZD_Ctrl0_reg, 0},
	{SCALEDOWN_ICH1_UZD_Ctrl1_reg, 0},

	{HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg, 0},
	{HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg, 0},
	{HSD_DITHER_DI_HSD_Initial_Value_reg, 0},
	{HSD_DITHER_DI_HSD_Hor_Delta1_reg, 0},
	{HSD_DITHER_DI_HSD_Hor_Segment_reg, 0},
	{HSD_DITHER_DI_HSD_Ctrl0_reg, 0},
#if 0//mac5p no these setting	of sub
	{SCALEDOWN_ICH2_UZD_H_Output_Size_reg, 0},
	{SCALEDOWN_ICH2_UZD_Scale_Hor_Factor_reg, 0},
	{SCALEDOWN_ICH2_UZD_Scale_Ver_Factor_reg, 0},
	{SCALEDOWN_ICH2_UZD_Initial_Value_reg, 0},
	{SCALEDOWN_ICH2_UZD_Ctrl0_reg, 0},
	{SCALEDOWN_ICH2_UZD_Ctrl1_reg, 0},
#endif
	//DI
	//{EXSRAM_CTRL_reg, 0},
	{DI_Color_Recovery_Option_reg, 0},
	{DI_DI_DMA_Multi_Req_Num_reg, 0},
	{DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, 0},
	{DI_db_reg_ctl_reg, 0},
	{DI_IM_DI_DMA_reg, 0},
	{DI_DDR_RDATDMA_WTLENNUM_reg, 0},
	{DI_DDR_RINFDMA_WTLENNUM_reg, 0},
	{DI_DDR_WDATDMA_WTLENNUM_reg, 0},
	{DI_DDR_DATDMA_RM_reg, 0},
	{DI_DDR_WINFDMA_WTLENNUM_reg, 0},
	{DI_DDR_INFDMA_RM_reg, 0},
	{DI_DI_DATMemoryStartAdd1_reg, 0},
	{DI_DI_DATMemoryStartAdd2_reg, 0},
	{DI_DI_DATMemoryStartAdd3_reg, 0},
	{DI_DI_DATMemoryStartAdd4_reg, 0},
	{DI_DI_INFMemoryStartAdd1_reg, 0},
	{DI_DI_INFMemoryStartAdd2_reg, 0},
	{DI_DI_DATMemoryStartAdd1_3D_reg, 0},
	{DI_DI_DATMemoryStartAdd2_3D_reg, 0},
	{DI_DI_DATMemoryStartAdd3_3D_reg, 0},
	{DI_DI_DATMemoryStartAdd4_3D_reg, 0},
	{DI_DI_INFMemoryStartAdd1_3D_reg, 0},
	{DI_DI_INFMemoryStartAdd2_3D_reg, 0},
	{DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, 0},
	{DI_IM_DI_BTR_CONTROL_reg, 0},
	{DI_IM_DI_MPEG_SEQUENCE_APP_reg, 0},
	{DI_IM_DI_FRAMESOBEL_STATISTIC_reg, 0},
	{DI_IM_DI_CONTROL_reg, 0},
	//MTG:
	{PPOVERLAY_MAIN_DEN_H_Start_End_reg, 0},
	{PPOVERLAY_MAIN_DEN_V_Start_End_reg, 0},
	{PPOVERLAY_MAIN_Background_H_Start_End_reg, 0},
	{PPOVERLAY_MAIN_Background_V_Start_End_reg, 0},
	{PPOVERLAY_Main_Background_Color1_reg, 0},
	{PPOVERLAY_Main_Background_Color2_reg, 0},
	#if 0//mac5p no these setting	of sub
	{PPOVERLAY_Main_Border_Highlight_Border_Color1_reg, 0},
	#endif
	{PPOVERLAY_Main_Border_Highlight_Border_Color2_reg, 0},
	{PPOVERLAY_Main_Border_Highlight_Border_Color3_reg, 0},
	{PPOVERLAY_MAIN_Active_H_Start_End_reg, 0},
	{PPOVERLAY_MAIN_Active_V_Start_End_reg, 0},

	{PPOVERLAY_SUB_DEN_H_Start_Width_reg, 0},
	{PPOVERLAY_SUB_DEN_V_Start_Length_reg, 0},
	{PPOVERLAY_SUB_Background_H_Start_End_reg, 0},
	{PPOVERLAY_SUB_Background_V_Start_End_reg, 0},
	#if 0//mac5p no these setting	of sub
	{PPOVERLAY_SUB_Background_Color1_reg, 0},
	{PPOVERLAY_SUB_Background_Color2_reg, 0},
	{PPOVERLAY_SUB_Border_Highlight_Border_Color1_reg, 0},
	{PPOVERLAY_SUB_Border_Highlight_Border_Color2_reg, 0},
	{PPOVERLAY_SUB_Border_Highlight_Border_Color3_reg, 0},
	#endif
	{PPOVERLAY_SUB_Active_H_Start_End_reg, 0},
	{PPOVERLAY_SUB_Active_V_Start_End_reg, 0},

	//UZU
	{SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg, 0},
	{SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_reg, 0},
	{SCALEUP_DM_UZUMAIN_Adapt8tap_reg, 0},
	{SCALEUP_DM_UZU_8tap_dering_reg, 0},
	{SCALEUP_DM_UZU_V6CTRL_reg, 0},
	{SCALEUP_DM_UZU_AdaptV6CTRL_reg, 0},
	{SCALEUP_DM_UZU_Scale_Hor_Factor_reg, 0},
	{SCALEUP_DM_UZU_Scale_Ver_Factor_reg, 0},
	{SCALEUP_DM_UZU_Hor_Delta1_reg, 0},
	{SCALEUP_DM_UZU_Hor_Delta2_reg, 0},
	{SCALEUP_DM_UZU_Hor_Segment1_reg, 0},
	{SCALEUP_DM_UZU_Hor_Segment2_reg, 0},
	{SCALEUP_DM_UZU_Hor_Segment3_reg, 0},
	{SCALEUP_DM_UZU_Initial_Value_reg, 0},
	{SCALEUP_DM_UZU_Input_Size_reg, 0},
	{SCALEUP_D_UZU_Globle_Ctrl_reg, 0},
	{SCALEUP_DM_UZU_Ctrl_reg, 0},

	{SCALEUP_DS_UZU_Scale_Ver_Factor_reg, 0},
	{SCALEUP_DS_UZU_Scale_Hor_Factor_reg, 0},
	{SCALEUP_DS_UZU_Initial_Value_reg, 0},
	{SCALEUP_DS_UZU_Input_Size_reg, 0},
	{SCALEUP_DS_UZU_Ctrl_reg, 0},
	//Data FRC:m cap
	{MDOMAIN_CAP_Main_SDNR_cxxto64_reg, 0},
	{MDOMAIN_CAP_DDR_In1WTLVL_Num_reg, 0},
	{MDOMAIN_CAP_DDR_In1WrLen_Rem_reg, 0},
	{MDOMAIN_CAP_DDR_In1Addr_reg, 0},
	{MDOMAIN_CAP_DDR_In1LineStep_reg, 0},
	{MDOMAIN_CAP_DDR_In1BlkStep_reg, 0},
	{MDOMAIN_CAP_DDR_In1_2ndAddr_reg, 0},
	{MDOMAIN_CAP_DDR_In1_3rdAddr_reg, 0},
	{MDOMAIN_CAP_DDR_In1LineNum_reg, 0},
	{MDOMAIN_CAP_DDR_In1Ctrl_reg, 0},
	{MDOMAIN_CAP_CapMain_BoundaryAddr1_reg, 0},
	{MDOMAIN_CAP_CapMain_BoundaryAddr2_reg, 0},
	{MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg, 0},
	{MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg, 0},
	{MDOMAIN_CAP_Capture_byte_swap_reg, 0},
	{MDOMAIN_CAP_Cap_In1_enable_reg, 0},

	{MDOMAIN_CAP_Sub_SDNR_cxxto64_reg, 0},
	{MDOMAIN_CAP_DDR_In2WTLVL_reg, 0},
	{MDOMAIN_CAP_DDR_In2WrLen_Rem_reg, 0},
	{MDOMAIN_CAP_DDR_In2Addr_reg, 0},
	{MDOMAIN_CAP_DDR_In2LineStep_reg, 0},
	{MDOMAIN_CAP_DDR_In2BlkStep_reg, 0},
	{MDOMAIN_CAP_DDR_In2_2ndAddr_reg, 0},
	{MDOMAIN_CAP_DDR_In2LineNum_reg, 0},
	{MDOMAIN_CAP_DDR_In2Ctrl_reg, 0},
	{MDOMAIN_CAP_CapSub_BoundaryAddr1_reg, 0},
	{MDOMAIN_CAP_CapSub_BoundaryAddr2_reg, 0},
	{MDOMAIN_CAP_Cap_In2_enable_reg, 0},
	//m disp
	{MDOMAIN_DISP_DDR_MainPreVStart_reg, 0},
	{MDOMAIN_DISP_DDR_MainNumWTL_reg, 0},
	{MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, 0},
	{MDOMAIN_DISP_DDR_MainAddr_reg, 0},
	{MDOMAIN_DISP_DDR_MainAddrDropBits_reg, 0},
	{MDOMAIN_DISP_DDR_MainLineStep_reg, 0},
	{MDOMAIN_DISP_DDR_MainBlkStep_reg, 0},
	{MDOMAIN_DISP_DDR_MainLineNum_reg, 0},
	{MDOMAIN_DISP_DDR_MainCtrl_reg, 0},
	{MDOMAIN_DISP_DDR_Main2ndAddr_reg, 0},
	{MDOMAIN_DISP_DDR_Main3rdAddr_reg, 0},
	{MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, 0},
	{MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, 0},
	{MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, 0},
	{MDOMAIN_DISP_Display_byte_channel_swap_reg, 0},
	{MDOMAIN_DISP_Disp_main_enable_reg, 0},

	{MDOMAIN_DISP_DDR_SubPreVStart_reg, 0},
	{MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0},
	{MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0},
	{MDOMAIN_DISP_DDR_SubAddr_reg, 0},
	{MDOMAIN_DISP_DDR_SubAddrDropBits_reg, 0},
	{MDOMAIN_DISP_DDR_SubLineStep_reg, 0},
	{MDOMAIN_DISP_DDR_SubBlkStep_reg, 0},
	{MDOMAIN_DISP_DDR_SubLineNum_reg, 0},
	{MDOMAIN_DISP_DDR_SubCtrl_reg, 0},
	{MDOMAIN_DISP_DDR_Sub2ndAddr_reg, 0},
	{MDOMAIN_DISP_Disp_sub_enable_reg, 0},

};


#ifdef CONFIG_PM
static int vsc_suspend (struct device *p_dev)
{
#if 0//No need vsc suspend
	int i,size;

	/*rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"func=%s line=%d \n", __FUNCTION__, __LINE__);*/

	size = (sizeof(VSC_PM_REGISTER_DATA)/4)/2;
	for(i = 0; i < size; i++)
	{
		VSC_PM_REGISTER_DATA[i][1] = rtd_inl(VSC_PM_REGISTER_DATA[i][0]);
		/*rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"func=%s line=%d VSC_PM_REGISTER_DATA[i][0]=%x\n", __FUNCTION__, __LINE__, VSC_PM_REGISTER_DATA[i][0]);*/
		/*rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"func=%s line=%d VSC_PM_REGISTER_DATA[i][1]=%x\n", __FUNCTION__, __LINE__, VSC_PM_REGISTER_DATA[i][1]);*/
	}
#endif
	return 0;
}

static int vsc_resume (struct device *p_dev)
{
#if 0//No need vsc resume
	int i, size;
	size = (sizeof(VSC_PM_REGISTER_DATA)/4)/2;
	for(i = 0; i < size; i++)
	{
		IoReg_Write32(VSC_PM_REGISTER_DATA[i][0],VSC_PM_REGISTER_DATA[i][1]);
		/*rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"func=%s line=%d VSC_PM_REGISTER_DATA[i][0]=%x\n", __FUNCTION__, __LINE__, VSC_PM_REGISTER_DATA[i][0]);*/
		/*rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"func=%s line=%d VSC_PM_REGISTER_DATA[i][1]=%x\n", __FUNCTION__, __LINE__, VSC_PM_REGISTER_DATA[i][1]);*/
	}
#endif
	vsc_debug_mode = FALSE;//disable VSC debug mode
	reset_any_srcrect(&main_dispwin_for_only_xy);
	reset_any_srcrect(&main_dispwin_pre);
#ifdef CONFIG_DUAL_CHANNEL
	reset_any_srcrect(&sub_dispwin_pre);
#endif
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_GameMode, FALSE);
#ifdef CONFIG_DUAL_CHANNEL
	set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
	set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_GameMode, FALSE);
#endif
	DbgSclrFlgTkr.adaptive_stream_pre = ADAPTIVE_STREAM_INIT;
	vpq_ld_running_flag = FALSE;
	DbgSclrFlgTkr.vpq_ld_first_boot = TRUE;
	sub_mode_type = VSC_SUB_MODE_PIP;//reset sub mode.
#if 1//enable M-domain clock for str resume @Crixus 20180117
	IoReg_Write32(0xb8000118, _BIT24 | _BIT25 | _BIT0);
 	IoReg_Write32(0xb8000108, _BIT24 | _BIT25 | _BIT0);
#endif
	return 0;
}

static int vsc_resume_std (struct device *p_dev)
{
#if 0//No need vsc resume
	int i, size;
	size = (sizeof(VSC_PM_REGISTER_DATA)/4)/2;
	for(i = 0; i < size; i++)
	{
		IoReg_Write32(VSC_PM_REGISTER_DATA[i][0],VSC_PM_REGISTER_DATA[i][1]);
		/*rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"func=%s line=%d VSC_PM_REGISTER_DATA[i][0]=%x\n", __FUNCTION__, __LINE__, VSC_PM_REGISTER_DATA[i][0]);*/
		/*rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"func=%s line=%d VSC_PM_REGISTER_DATA[i][1]=%x\n", __FUNCTION__, __LINE__, VSC_PM_REGISTER_DATA[i][1]);*/
	}
#endif
	ResetShareMem();//reset share memory to 0
	vsc_debug_mode = FALSE;//disable VSC debug mode
	Set_send_panel_para_flag(TRUE);//Need to send panel parameter
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_GameMode, FALSE);
#ifdef CONFIG_DUAL_CHANNEL
	set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_LIVEZOOM, FALSE);
	set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_GameMode, FALSE);
#endif
	DbgSclrFlgTkr.adaptive_stream_pre = ADAPTIVE_STREAM_INIT;
	vpq_ld_running_flag = FALSE;
	DbgSclrFlgTkr.vpq_ld_first_boot = TRUE;
	sub_mode_type = VSC_SUB_MODE_PIP;//reset sub mode.
#if 1//enable M-domain clock for std resume @Crixus 20180117
	IoReg_Write32(0xb8000118, _BIT24 | _BIT25 | _BIT0);
 	IoReg_Write32(0xb8000108, _BIT24 | _BIT25 | _BIT0);
#endif
	return 0;
}
#endif

int vsc_open(struct inode *inode, struct file *filp) {
	return 0;
}

ssize_t  vsc_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
	return 0;

}

ssize_t vsc_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

int vsc_release(struct inode *inode, struct file *filep)
{
	return 0;
}

unsigned char vsc_set_vd_ptg(unsigned char bOnOff)
{
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "function=%s, line=%d\n", __FUNCTION__, __LINE__);

	if(bOnOff == _ENABLE) {
		//Set VD PatternGen
		IoReg_SetBits(VDTOP_PATTERN_CONTROL_reg,_BIT0);
		IoReg_Write32(VDTOP_AD_SW_CTRL0_reg, 0x0);
		//Set VGIP PatternGen
		IoReg_SetBits(SUB_VGIP_VGIP_CHN2_CTRL_reg,_BIT27);
	}
	else {
		//Clear VD PatternGen
		IoReg_ClearBits(VDTOP_PATTERN_CONTROL_reg,_BIT0);
		IoReg_Write32(VDTOP_AD_SW_CTRL0_reg, 0xc9);
		//Clear VGIP PatternGen
		IoReg_ClearBits(SUB_VGIP_VGIP_CHN2_CTRL_reg,_BIT27);
	}
	return TRUE;
}

unsigned char vsc_get_uzu_crc(VIDEO_WID_T wid, unsigned int *CRC_Value)
{
	rtd_printk(KERN_EMERG, TAG_NAME_VSC, "function=%s, line=%d\n", __FUNCTION__, __LINE__);
	unsigned int iResult;

	//Set M-Domain CRC Bits
	if(wid == VIDEO_WID_0) {
		IoReg_SetBits(SCALEUP_DM_MEM_CRC_CTRL_reg,_BIT1|_BIT0);
	}
	else if(wid == VIDEO_WID_1) {
		IoReg_SetBits(SCALEUP_DS_MEM_CRC_CTRL_reg,_BIT1|_BIT0);
	}
	msleep(1000);
	//Get M-Domain CRC Result
	if(wid == VIDEO_WID_0) {
		iResult = IoReg_Read32(SCALEUP_DM_MEM_CRC_Result_reg);
	}
	else if(wid == VIDEO_WID_1) {
		iResult = IoReg_Read32(SCALEUP_DS_MEM_CRC_Result_reg);
	}
	*CRC_Value = iResult;

	return TRUE;
}

unsigned char i3dma_uzd_flag=1;
void set_i3dma_uzd(unsigned char i3dma_uzd)
{
	i3dma_uzd_flag=i3dma_uzd;
}
unsigned char get_i3dma_uzd(void)
{
	return i3dma_uzd_flag;
}
unsigned char vsc_set_uzd_path(unsigned char i3dma_uzd)
{
	//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "function=%s, line=%d\n", __FUNCTION__, __LINE__);

	set_i3dma_uzd(i3dma_uzd);

	return TRUE;
}

extern void scalerVIP_Set_BlackDetection_EN(unsigned char bEnable);
long vsc_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{
	extern VFE_AVD_TIMING_INFO_T *Get_AVD_LGETiminginfo(void);
	unsigned int before_time = 0;
	unsigned int after_time = 0;
	VFE_AVD_TIMING_INFO_T *ptLGETimingInfo = NULL;
	StructDisplayInfo * p_adc_dispinfo = NULL;
	//HDMI_TIMING_T hdmi_timing_info = {0, COLOR_RGB, HDMI_COLORIMETRY_NOSPECIFIED, 0 ,HDMI3D_2D_ONLY, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	vfe_hdmi_timing_info_t hdmi_timing_info;

	int retval = 0;
	//rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC: vsc_ioctl, %x;;agr:%x\n", cmd, *((unsigned int *)arg));

	if (_IOC_TYPE(cmd) != VSC_IOC_MAGIC || _IOC_NR(cmd) > VSC_IOC_MAXNR) return -ENOTTY ;

	switch (cmd)
	{
		case VSC_IOC_INITIALIZE:
		{
			before_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
			if(rtk_hal_vsc_initialize()==FALSE)
				retval =  -1;
			after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC intial time=%d ms", (after_time-before_time));
			break;
		}
		case VSC_IOC_UNINITIALIZE:
		{
			if(rtk_hal_vsc_uninitialize()==FALSE)
				return -1;
			break;
		}
		case VSC_IOC_OPEN:
		{
			VIDEO_WID_T widid;
			before_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
			if(copy_from_user((void *)&widid, (const void __user *)arg, sizeof(VIDEO_WID_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_OPEN copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_open(widid) == FALSE)
					retval =  -1;
				after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC open time=%d ms", (after_time-before_time));
			}
			break;
		}
		case VSC_IOC_CLOSE:
		{
			VIDEO_WID_T widid;
			if(copy_from_user((void *)&widid, (const void __user *)arg, sizeof(VIDEO_WID_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_CLOSE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_close(widid)==FALSE)
					retval =  -1;
			}
			break;

		}
		case VSC_IOC_CONNECT:
		{
			VSC_CONNECT_PARA_T connectPara;
			before_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
			if(copy_from_user((void *)&connectPara, (const void __user *)arg, sizeof(VSC_CONNECT_PARA_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_CONNECT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				down(&Magnifier_Semaphore);/*added by qiangzhou, can not remove*/
				if(rtk_hal_vsc_Connect(connectPara.connectwid, connectPara.vsc_input, connectPara.outputmode)==FALSE)
				{
					retval =  -1;
				}
				up(&Magnifier_Semaphore);
				after_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "VSC connect time=%d ms",(after_time-before_time));

			}
			break;
		}
		case VSC_IOC_DISCONNECT:
		{
			VSC_CONNECT_PARA_T disconnectPara;
			if(copy_from_user((void *)&disconnectPara, (const void __user *)arg, sizeof(VSC_CONNECT_PARA_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_DISCONNECT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				down(&Magnifier_Semaphore);/*added by qiangzhou, can not remove*/
				if(rtk_hal_vsc_Disconnect(disconnectPara.connectwid, disconnectPara.vsc_input, disconnectPara.outputmode)==FALSE)
				{
					retval =  -1;
				}
				up(&Magnifier_Semaphore);
			}
			break;
		}
		case VSC_IOC_SET_WINBLANK:
		{
			VSC_WINBLANK_PARA_T winblankpara;
			if(copy_from_user((void *)&winblankpara, (const void __user *)arg, sizeof(VSC_WINBLANK_PARA_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_WINBLANK copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "winblankpara.winblankwid=%d,winblankpara.winblankbonoff=%d,winblankpara.winblankcolor=%d\n", winblankpara.winblankwid, winblankpara.winblankbonoff, winblankpara.winblankcolor);
				if(rtk_hal_vsc_SetWinBlank(winblankpara.winblankwid, winblankpara.winblankbonoff, winblankpara.winblankcolor) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_ADAPTIVE_INPUTREGION:
		{
			VSC_GET_FRAME_REGION_T  pframeregion;
			VIDEO_DDI_RECT_T inregion = {0, 0, 0 , 0};
			if(copy_from_user((void *)&pframeregion, (const void __user *)arg, sizeof(VSC_GET_FRAME_REGION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_ADAPTIVE_INPUTREGION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_GetInputRegion_ForAdaptive(pframeregion.setframewid, &inregion) == FALSE) {
					retval =  -1;
				}
				else
				{
					if (copy_to_user((int __user *)pframeregion.pinregion , &inregion, sizeof(VIDEO_DDI_RECT_T)) )
					{
	                			rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_GET_INPUTREGION copy_to_user error \n");
						retval = EFAULT;
	            			}
				}

			}
			break;
		}
		case VSC_IOC_SET_ADAPTIVE_INPUTREGION:
		{
			VSC_SET_FRAME_REGION_T frameregion;
			if(copy_from_user((void *)&frameregion, (const void __user *)arg, sizeof(VSC_SET_FRAME_REGION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_ADAPTIVE_INPUTREGION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetInputRegion_ForAdaptive(frameregion.setframewid, frameregion.inregion) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_INPUTREGION:
		{
			VSC_GET_FRAME_REGION_T  pframeregion;
			VIDEO_DDI_RECT_T inregion = {0, 0, 0 , 0};
			if(copy_from_user((void *)&pframeregion, (const void __user *)arg, sizeof(VSC_GET_FRAME_REGION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_INPUTREGION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_GetInputRegion(pframeregion.setframewid, &inregion) == FALSE) {
					retval =  -1;
				}
				else
				{
					if (copy_to_user((int __user *)pframeregion.pinregion , &inregion, sizeof(VIDEO_DDI_RECT_T)) )
					{
	                	rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_GET_INPUTREGION copy_to_user error \n");
						retval = EFAULT;
	            	}
				}

			}
			break;
		}
		case VSC_IOC_SET_INPUTREGION:
		{
			VSC_SET_FRAME_REGION_T frameregion;
			if(copy_from_user((void *)&frameregion, (const void __user *)arg, sizeof(VSC_SET_FRAME_REGION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_INPUTREGION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetInputRegion(frameregion.setframewid, frameregion.inregion) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_OUTPUTREGION:
		{
			VSC_GET_FRAME_REGION_T  pframeregion;
			VIDEO_DDI_RECT_T outregion = {0, 0, 0 , 0};
			if(copy_from_user((void *)&pframeregion, (const void __user *)arg, sizeof(VSC_GET_FRAME_REGION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_OUTPUTREGION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_GetOutputRegion(pframeregion.setframewid, &outregion) == FALSE) {
					retval =  -1;
				}
				else
				{
					if (copy_to_user((int __user *)pframeregion.pinregion , &outregion, sizeof(VIDEO_DDI_RECT_T)) )
					{
	                	rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_GET_OUTPUTREGION copy_to_user error \n");
						retval = EFAULT;
	            	}
				}
			}
			break;
		}
		case VSC_IOC_SET_OUTPUTREGION:
		{
			VSC_SET_FRAME_REGION_T frameregion;
			if(copy_from_user((void *)&frameregion, (const void __user *)arg, sizeof(VSC_SET_FRAME_REGION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_OUTPUTREGION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				virtual_w = true_wide;
				virtual_h = true_high;

				if(rtk_hal_vsc_SetOutputRegion(frameregion.setframewid, frameregion.inregion, virtual_w, virtual_h)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_WINFREEZE:
		{
			VSC_FREEZE_ACTION_T freezeact;
			if(copy_from_user((void *)&freezeact, (const void __user *)arg, sizeof(VSC_FREEZE_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_WINFREEZE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "freezeact.freezewid=%d,freezeact.freezeonoff=%d\n", freezeact.freezewid, freezeact.freezeonoff);
				if(rtk_hal_vsc_SetWinFreeze(freezeact.freezewid, freezeact.freezeonoff)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_FREEZE_VIDEOFRAMEBUFFER:
		{
			VSC_FREEZE_ACTION_T freezeact;
			if(copy_from_user((void *)&freezeact, (const void __user *)arg, sizeof(VSC_FREEZE_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_FREEZE_VIDEOFRAMEBUFFER copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				Factory_SelfDiagnosis_Mode = TRUE;
				if(rtk_hal_vsc_FreezeVideoFrameBuffer(freezeact.freezewid, freezeact.freezeonoff)==FALSE)
					retval =  -1;
				Factory_SelfDiagnosis_Mode = FALSE;
			}
			break;
		}
		case VSC_IOC_READ_VIDEOFRAMEBUFFER:
		{
			VSC_READ_BUFFER_ACTION_T readaction;
			if(copy_from_user((void *)&readaction, (const void __user *)arg, sizeof(VSC_READ_BUFFER_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_READ_VIDEOFRAMEBUFFER copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				Factory_SelfDiagnosis_Mode = TRUE;

				VIDEO_RECT_T kernelInregion;

				if(copy_from_user((void *)&kernelInregion, (const void __user *)readaction.pinregion, sizeof(VIDEO_DDI_RECT_T)))
				{
					retval = -EFAULT;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_READ_VIDEOFRAMEBUFFER kernelInregion copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				VIDEO_DDI_PIXEL_STANDARD_COLOR_T *kernelPRead;
				kernelPRead = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc_specific(kernelInregion.w * kernelInregion.h * sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T), GFP_DCU1_FIRST);

				VIDEO_DDI_COLOR_STANDARD_T Color_standard = VIDEO_DDI_COLOR_STANDARD_YUV;
				VIDEO_DDI_PIXEL_COLOR_FORMAT_T PixelColorFormat = VIDEO_DDI_PIXEL_8BIT;
				if(rtk_hal_vsc_ReadVideoFrameBuffer(readaction.bufferwid, &kernelInregion, kernelPRead, &Color_standard, &PixelColorFormat) == FALSE)
					retval =  -1;

				if(copy_to_user((void __user *)readaction.pcolor_standard, (void *)&Color_standard, sizeof(VIDEO_DDI_COLOR_STANDARD_T)))
				{
					retval = -EFAULT;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_READ_VIDEOFRAMEBUFFER pcolor_standard copy_to_user failed!!!!!!!!!!!!!!!\n");
				}

				if(copy_to_user((void __user *)readaction.ppixelcolorformat, (void *)&PixelColorFormat, sizeof(VIDEO_DDI_PIXEL_COLOR_FORMAT_T)))
				{
					retval = -EFAULT;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_READ_VIDEOFRAMEBUFFER ppixelcolorformat copy_to_user failed!!!!!!!!!!!!!!!\n");
				}

				if(copy_to_user((void __user *)readaction.pRead, (void *)kernelPRead, kernelInregion.w * kernelInregion.h * sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T)))
				{
					retval = -EFAULT;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_READ_VIDEOFRAMEBUFFER pRead copy_to_user failed!!!!!!!!!!!!!!!\n");
				}
				dvr_free((void *)kernelPRead);
				Factory_SelfDiagnosis_Mode = FALSE;
			}
			break;
		}
		case VSC_IOC_WRITE_VIDEOFRAMEBUFFER:
		{
			VSC_WRITE_BUFFER_ACTION_T writeaction;
			if(copy_from_user((void *)&writeaction, (const void __user *)arg, sizeof(VSC_WRITE_BUFFER_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_WRITE_VIDEOFRAMEBUFFER copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				Factory_SelfDiagnosis_Mode = TRUE;
				VIDEO_RECT_T kernelInregion;
				if(copy_from_user((void *)&kernelInregion, (const void __user *)writeaction.pinregion, sizeof(VIDEO_DDI_RECT_T)))
				{
					retval = -EFAULT;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_WRITE_VIDEOFRAMEBUFFER kernelInregion copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				VIDEO_DDI_PIXEL_STANDARD_COLOR_T *kernelPWrite;
				kernelPWrite = (VIDEO_DDI_PIXEL_STANDARD_COLOR_T *)dvr_malloc_specific(kernelInregion.w * kernelInregion.h * sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T), GFP_DCU1_FIRST);

				if(copy_from_user((void *)&kernelPWrite, (const void __user *)writeaction.pWrite, kernelInregion.w * kernelInregion.h * sizeof(VIDEO_DDI_PIXEL_STANDARD_COLOR_T)))
				{
					retval = -EFAULT;
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_WRITE_VIDEOFRAMEBUFFER kernelPWrite copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				if(rtk_hal_vsc_WriteVideoFrameBuffer(writeaction.bufferwid, &kernelInregion, kernelPWrite) == FALSE)
					retval =  -1;

				dvr_free((void *)kernelPWrite);
				Factory_SelfDiagnosis_Mode = FALSE;
			}

			break;
		}
		case VSC_IOC_CAPTURE_VIDEOFRAME:
		{
			VSC_CAPTURE_FRAME_ACTION_T capaction;
			if(copy_from_user((void *)&capaction, (const void __user *)arg, sizeof(VSC_CAPTURE_FRAME_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_CAPTURE_VIDEOFRAME copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
#if 0//now have VT,no use vsc capture,but these code must keep:qiang_zhou
				if(rtk_hal_vsc_CaptureVideoFrame(capaction.place, capaction.pcaptureinfo) == FALSE)
					retval =  -1;
#endif
			}
			break;
		}
		case VSC_IOC_SET_RGB444MODE:
		{
			bool boffon;
			if(copy_from_user((void *)&boffon, (const void __user *)arg, sizeof(bool)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_RGB444MODE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetRGB444Mode(boffon)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_3DFORSCALER:
		{

			TRIDTV_SCALER_CTRL_T p3dcfginfo;
			if(copy_from_user((void *)&p3dcfginfo, (const void __user *)arg, sizeof(TRIDTV_SCALER_CTRL_T )))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_3DFORSCALER copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_Set3DForScaler(&p3dcfginfo) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_3DAUTODETECTMODE:
		{
			VSC_3DAUTODET_ACTION_T autodet;
			VIDEO_DDI_3D_FORMAT_TYPE_T threedtype = VIDEO_DDI_3D_FORMAT_MAX;
			if(copy_from_user((void *)&autodet, (const void __user *)arg, sizeof(VSC_3DAUTODET_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_3DAUTODETECTMODE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_Get3DAutoDetectmode(autodet.wid, &threedtype) == FALSE)
				{
					retval =  -1;
				}
				if (copy_to_user((int __user *)autodet.pvideo3dtype, &threedtype, sizeof(VIDEO_DDI_3D_FORMAT_TYPE_T)) )
				{
                	rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_GET_3DAUTODETECTMODE copy_to_user error \n");
					retval = EFAULT;
            	}
			}
			break;
		}
		case VSC_IOC_SET_3DPATTERNMODE:
		{
			VSC_3DPATTERNMODE_ACTION_T patternaction;
			if(copy_from_user((void *)&patternaction, (const void __user *)arg, sizeof(VSC_3DPATTERNMODE_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_3DPATTERNMODE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_Set3Dpatternmode(patternaction.wid, patternaction.video3dtype) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_VENCMODE:
		{
			VSC_SET_VENCMODE_ACTION_T venc;
			if(copy_from_user((void *)&venc, (const void __user *)arg, sizeof(VSC_SET_VENCMODE_ACTION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_VENCMODE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetVENEMode(venc.framerate,venc.scantype)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_OPENV2G:
		{
			VIDEO_WID_T widid;
			if(copy_from_user((void *)&widid, (const void __user *)arg, sizeof(VIDEO_WID_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_OPENV2G copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_OpenV2G(widid)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_CLOSEV2G:
		{
			VIDEO_WID_T widid;
			if(copy_from_user((void *)&widid, (const void __user *)arg, sizeof(VIDEO_WID_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_CLOSEV2G copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_CloseV2G(widid)==FALSE)
					retval =  -1;
			}

			break;
		}
		case VSC_IOC_GET_V2GFRAMEBUFFER:
		{
			VSC_GET_V2GFRAMEBUFFER_T v2gbf;
			if(copy_from_user((void *)&v2gbf, (const void __user *)arg, sizeof(VSC_GET_V2GFRAMEBUFFER_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_V2GFRAMEBUFFER copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
#if 0//now have VT,no use V2G,but these code must keep:qiang_zhou
				if(rtk_hal_vsc_GetV2GFramebuffer(v2gbf.wid,v2gbf.pCaptureInfo) == FALSE)
					retval =  -1;
#endif
			}
			break;
		}
		case VSC_IOC_SET_UDINPUT:
		{
			VIDEO_UD_MODE_T udmode;
			if(copy_from_user((void *)&udmode, (const void __user *)arg, sizeof(udmode)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_UDINPUT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetUDInput(udmode)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_UDOUTPUT:
		{
			VIDEO_DDI_DIS_FMT_T disfmt;
			if(copy_from_user((void *)&disfmt, (const void __user *)arg, sizeof(VIDEO_DDI_DIS_FMT_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_UDOUTPUT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetUDOutput(disfmt)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_VIDEODELAYEDTIME:
		{
			VSC_GET_VIDEODELAYEDTIME_T vddelaytime;
			unsigned short delaytime = 0;
			if(copy_from_user((void *)&vddelaytime, (const void __user *)arg, sizeof(VSC_GET_VIDEODELAYEDTIME_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_VIDEODELAYEDTIME copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_GetVideoDelayedTime(vddelaytime.wid, &delaytime) == FALSE)
				{
					retval =  -1;
				}
				else
				{
					if (copy_to_user((int __user *)vddelaytime.pDelayedTime , &delaytime, sizeof(unsigned short)) )
					{
	                	rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_GET_VIDEODELAYEDTIME copy_to_user error \n");
						retval = EFAULT;
	            	}
				}
			}
			break;
		}
		case VSC_IOC_SET_TITLEMODE:
		{
			bool bonoff;
			if(copy_from_user((void *)&bonoff, (const void __user *)arg, sizeof(bool)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_TITLEMODE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetTileMode(bonoff)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_TILEMAXROWVAL:
		{
			VSC_SET_TILEMAXROWVAL_T titlerowval;
			if(copy_from_user((void *)&titlerowval, (const void __user *)arg, sizeof(VSC_SET_TILEMAXROWVAL_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_TILEMAXROWVAL copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetTileMaxRowVal(titlerowval.uMaxRow,titlerowval.uMaxCol)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_TILEID:
		{
			unsigned char titleid;
			if(copy_from_user((void *)&titleid, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_TILEID copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetTileID(titleid)==FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_ADAPTIVESTREAM:
		{
			bool bonoff;
			if(copy_from_user((void *)&bonoff, (const void __user *)arg, sizeof(bool)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_ADAPTIVESTREAM copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetAdaptiveStream(bonoff) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_SOCOUTPUTFMT:
		{
			VIDEO_UD_MODE_T socoutputfmt;
			if(copy_from_user((void *)&socoutputfmt, (const void __user *)arg, sizeof(VIDEO_UD_MODE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_SOCOUTPUTFMT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetSOCOutputFMT(socoutputfmt) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_FRCTYPE:
		{
			unsigned char  frctype;
			if(copy_from_user((void *)&frctype, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_FRCTYPE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetFRCType(frctype) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_FRCTYPE:
		{
			unsigned char frctypeget;
			if(copy_from_user((void *)&frctypeget, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_FRCTYPE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_GetFRCType(frctypeget) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_GETMVOPSTATUS:
		{
			VSC_GET_GETMVOPSTATUS_T mvopstatus;
			BOOLEAN MVOPEnable = FALSE;
			if(copy_from_user((void *)&mvopstatus, (const void __user *)arg, sizeof(VSC_GET_GETMVOPSTATUS_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_GETMVOPSTATUS copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_GetMVOPStatus(mvopstatus.wid, &MVOPEnable) == FALSE)//Current not use
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SET_VENCI3DDMA:
		{
			IDMA_DISPD_CAPTURE_INFO capInfo;
			if(copy_from_user((void *)&capInfo, (const void __user *)arg, sizeof(IDMA_DISPD_CAPTURE_INFO)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_VENCI3DDMA copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				drvif_I3DDMA_dispD_to_IdmaVI_idmaConfig(capInfo);
			}
			break;
		}
		case VSC_IOC_STOPVO:
		{
			/*
			down(get_vo_infosemaphore());
			set_vo_change_flag(TRUE);
   			memset(Get_VO_Dispinfo(), 0, sizeof(StructDisplayInfo));
			up(get_vo_infosemaphore());
			*/
			break;
		}
		case VSC_IOC_GETINPUTINFO:
		{
			VSC_GET_INPUT_INFO info;
			SCALER_INPUT_INFO input_info = {0, 0, 0, 0, 0, 0};
			if(copy_from_user((void *)&info, (const void __user *)arg, sizeof(VSC_GET_INPUT_INFO )))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GETINPUTINFO copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			if (info.wid == VIDEO_WID_0) {
				state_update_disp3d_info();
				I3DDMA_Parse_HDMI3D_pattern();
				switch(Get_DisplayMode_Src(SLR_MAIN_DISPLAY))
				{
					case VSC_INPUTSRC_ADC:
						down(get_adc_detectsemaphore());
						p_adc_dispinfo = Get_ADC_Dispinfo();
						input_info.inputWid = p_adc_dispinfo->IPH_ACT_WID_PRE;
						input_info.inputLen = p_adc_dispinfo->IPV_ACT_LEN_PRE;
		           		input_info.capWid = p_adc_dispinfo->IPH_ACT_WID_PRE;
		           		input_info.capLen = p_adc_dispinfo->IPV_ACT_LEN_PRE;
						input_info.inputFramerate = p_adc_dispinfo->IVFreq;
						input_info.interlace = (p_adc_dispinfo->disp_status&_BIT8)>>8;
						up(get_adc_detectsemaphore());
						break;

					case VSC_INPUTSRC_HDMI:
/*
						newbase_hdmi_get_timing(newbase_hdmi_get_current_display_port(), &hdmi_timing_info);
						input_info.inputWid = hdmi_timing_info.h_act_len;
						input_info.inputLen = hdmi_timing_info.v_act_len;
		           		input_info.capWid = hdmi_timing_info.h_act_len;
		           		input_info.capLen = hdmi_timing_info.v_act_len;
						input_info.inputFramerate = hdmi_timing_info.v_freq;
*/
						vfe_hdmi_drv_get_port_timing_info(&hdmi_timing_info);
						input_info.inputWid = hdmi_timing_info.active.w;
						input_info.inputLen = hdmi_timing_info.active.h;
				           	input_info.capWid = hdmi_timing_info.active.w;
				           	input_info.capLen = hdmi_timing_info.active.h;
						input_info.inputFramerate = hdmi_timing_info.v_freq;
						input_info.interlace = !hdmi_timing_info.scan_type;
						break;

					case VSC_INPUTSRC_AVD:
						ptLGETimingInfo = Get_AVD_LGETiminginfo();
						input_info.inputWid = ptLGETimingInfo->active.w;
						input_info.inputLen = ptLGETimingInfo->active.h/2;
						input_info.capWid = ptLGETimingInfo->active.w;
						input_info.capLen = ptLGETimingInfo->active.h/2;
						input_info.inputFramerate = ptLGETimingInfo->vFreq;
						input_info.interlace = !ptLGETimingInfo->scanType;
						break;

					default:
						input_info.inputWid = 0;
						input_info.inputLen = 0;
		           		input_info.capWid = 0;
		           		input_info.capLen = 0;
						input_info.inputFramerate = 0;
						input_info.interlace = 0;
						break;
				}
				if (copy_to_user((int __user *)info.inputInfo, &input_info, sizeof(SCALER_INPUT_INFO)) )
				{
	                rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_GETINPUTINFO main copy_to_user error \n");
					retval = EFAULT;
	            }
			} else {
				if(DbgSclrFlgTkr.Sub_OutputVencMode && (Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_AVD)) {
					ptLGETimingInfo = Get_AVD_LGETiminginfo();
					input_info.inputWid = ptLGETimingInfo->active.w;
					input_info.inputLen = ptLGETimingInfo->active.h/2;
					input_info.capWid = sub_dispwin.src_wid;
					input_info.capLen = sub_dispwin.src_height;
					input_info.inputFramerate = ptLGETimingInfo->vFreq;
					input_info.interlace = !ptLGETimingInfo->scanType;
				} else {
					input_info.inputWid = 0;
					input_info.inputLen = 0;
					input_info.capWid = 0;
					input_info.capLen = 0;
					input_info.inputFramerate = 0;
					input_info.interlace = 0;
				}
				if (copy_to_user((int __user *)info.inputInfo, &input_info, sizeof(SCALER_INPUT_INFO)) )
				{
	                rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_GETINPUTINFO sub copy_to_user error \n");
					retval = EFAULT;
	            }
			}
			break;
		}
		case VSC_IOC_SHOWOSDSAMPLE:
		{
			unsigned char bonoff;
			if(copy_from_user((void *)&bonoff, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SHOWOSDSAMPLE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_showosdsample(bonoff) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GETPANELSIZE:
		{
			VSC_PANEL_SIZE_T  panel_size;
			panel_size.display_wid = _DISP_WID;
			panel_size.display_len = _DISP_LEN;
			if(copy_to_user((void __user *)arg, (void *)&panel_size, sizeof(VSC_PANEL_SIZE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GETPANELSIZE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			break;
		}
		case VSC_IOC_SET_DOLBYVISION_IDMA_ENABLE:
		{
			unsigned char bEnable;
			if(copy_from_user((void *)&bEnable, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_DOLBYVISION_IDMA_ENABLE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetHdrDolbyVisionIdmaEnable(bEnable) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_SETZORDER:
		{
			VSC_SET_ZORDER_T zorderNO[2];
			if(copy_from_user((void *)zorderNO, (const void __user *)arg, 2*sizeof(VSC_SET_ZORDER_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_OUTPUTREGION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_SetZorder(zorderNO[0],zorderNO[1]) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_MAKECOLOREDVIDEO:
		{
			VSC_VIDEO_COLOR_TYPE_T colorType;

			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Scaler vsc disp: Get VSC_IOC_MAKECOLOREDVIDEO!!!!!!!\n");

			if(copy_from_user((void *) &colorType, (const void __user *)arg, sizeof(VSC_VIDEO_COLOR_TYPE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_MAKECOLOREDVIDEO copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_makeColoredVideo(colorType) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_DM_OPEN:
		{
			if(rtk_hal_vsc_dm_open()==FALSE)
				return -1;
			break;
		}
		case VSC_IOC_DM_CLOSE:
		{
			if(rtk_hal_vsc_dm_close()==FALSE)
				return -1;
			break;
		}
		case VSC_IOC_DM_CONNECT:
		{
			if(rtk_hal_vsc_dm_connect()==FALSE)
				return -1;
			break;
		}
		case VSC_IOC_DM_DISCONNECT:
		{
			if(rtk_hal_vsc_dm_disconnect()==FALSE)
				return -1;
			break;
		}
		case VSC_IOC_ISDOLBYHDR:
		{

			unsigned char isdolbyHdr = 0;
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
			if(Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result())
				isdolbyHdr = 1;
			else
				isdolbyHdr = 0;
#endif

			if(copy_to_user((void __user *)arg, (void *)&isdolbyHdr, sizeof(unsigned char)))
        		{
           			retval = -EFAULT;
            			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler hdcp2 ioctl code=VSC_IOC_ISDOLBYHDR copy_to_user failed!!!!!!!!!!!!!!!\n");
            			break;
        		}

			break;
		}

		case VSC_IOC_UPDATE_ADAPTIVE_STREAMING_INFO:
		{
			VSC_ADAPTIVE_STREAM_INFO_FROM_APP temp_adaptive_stream_info;
			if(copy_from_user((void *)&temp_adaptive_stream_info, (const void __user *)arg, sizeof(VSC_ADAPTIVE_STREAM_INFO_FROM_APP)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_ERR, TAG_NAME_VSC, "scaler vsc ioctl VSC_IOC_UPDATE_ADAPTIVE_STREAMING_INFO copy_from_user failed!!!!!!!!!!!!!!!\n");
				return retval;
			}
			if((temp_adaptive_stream_info.port == 0) || (temp_adaptive_stream_info.port == 1))
			{
				down(&Adaptive_Streaming_Semaphore);
				adaptive_streaming_info[temp_adaptive_stream_info.port].width = temp_adaptive_stream_info.width;
				adaptive_streaming_info[temp_adaptive_stream_info.port].height = temp_adaptive_stream_info.height;
				adaptive_streaming_info[temp_adaptive_stream_info.port].update_flag = TRUE;
				up(&Adaptive_Streaming_Semaphore);
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####Get adaptive stream info port:%d w:%d h:%d####\r\n", temp_adaptive_stream_info.port, temp_adaptive_stream_info.width, temp_adaptive_stream_info.height);
			}
			else
			{
				rtd_printk(KERN_ERR, TAG_NAME_VSC, "scaler vsc ioctl VSC_IOC_UPDATE_ADAPTIVE_STREAMING_INFO failed port:%d!!!!!\n", temp_adaptive_stream_info.port);
			}

			break;
		}

		case VSC_IOC_NOTICE_GST_VO_UPDATE:
		{
			VSC_NOTICE_GST_VO_UPDATE_INFO temp_vsc_notice_gst_vo_update;
			unsigned char update_flag = TRUE;
			if(copy_from_user((void *)&temp_vsc_notice_gst_vo_update, (const void __user *)arg, sizeof(VSC_NOTICE_GST_VO_UPDATE_INFO)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_ERR, TAG_NAME_VSC, "scaler vsc ioctl VSC_IOC_NOTICE_GST_VO_UPDATE copy_from_user failed!!!!!!!!!!!!!!!\n");
				return retval;
			}
			if((temp_vsc_notice_gst_vo_update.port == 0) || (temp_vsc_notice_gst_vo_update.port == 1))
			{
				if(get_daptive_stream_vo_update_flag(temp_vsc_notice_gst_vo_update.port))
				{
					set_daptive_stream_vo_update_flag(temp_vsc_notice_gst_vo_update.port, FALSE);
					update_flag = TRUE;
					if (copy_to_user((int __user *)temp_vsc_notice_gst_vo_update.update_flag, &update_flag, sizeof(unsigned char)) )
					{
		                rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_NOTICE_GST_VO_UPDATE copy_to_user error 1 \n");
						retval = EFAULT;
		            }
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####VSC_IOC_NOTICE_GST_VO_UPDATE port:%d vo already update####\r\n", temp_vsc_notice_gst_vo_update.port);
				}
				else
				{
					update_flag = FALSE;
					if (copy_to_user((int __user *)temp_vsc_notice_gst_vo_update.update_flag, &update_flag, sizeof(unsigned char)) )
					{
		                rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_NOTICE_GST_VO_UPDATE copy_to_user error 2\n");
						retval = EFAULT;
		            }
				}
				/*
				if (copy_to_user((int __user *)arg, &temp_vsc_notice_gst_vo_update, sizeof(VSC_NOTICE_GST_VO_UPDATE_INFO)) )
				{
                	rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_NOTICE_GST_VO_UPDATE copy_to_user error\n");
					retval = EFAULT;
            	}
            	*/
			}
			else
			{
				rtd_printk(KERN_ERR, TAG_NAME_VSC, "scaler vsc ioctl VSC_IOC_NOTICE_GST_VO_UPDATE failed port:%d!!!!!\n", temp_vsc_notice_gst_vo_update.port);
			}
			break;
		}

		case VSC_IOC_APP_CONTRO_FORCEBG:
		{//This case is for camera currently
			VSC_APP_CONTROL_FORCEBG_TYPE forcetype;
			if(copy_from_user((void *)&forcetype, (const void __user *)arg, sizeof(VSC_APP_CONTROL_FORCEBG_TYPE)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_ERR, TAG_NAME_VSC, "scaler vsc ioctl VSC_IOC_APP_CONTRO_FORCEBG copy_from_user failed!!!!!!!!!!!!!!!\n");
				return retval;
			}
			if((forcetype.port == 0) || (forcetype.port == 1))
			{
				if(adaptive_streaming_info[forcetype.port].display == SLR_MAIN_DISPLAY)
				{
					if((Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE) && (forcetype.enable))
					{
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####VSC_IOC_APP_CONTRO_FORCEBG main mute######\r\n");
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);/*Auto BG. Add by Will*/
						up(get_forcebg_semaphore());
					}
				}
				else if(adaptive_streaming_info[forcetype.port].display == SLR_SUB_DISPLAY)
				{
					if((Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY) == FALSE) && (forcetype.enable))
					{
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####VSC_IOC_APP_CONTRO_FORCEBG sub mute######\r\n");
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);/*Auto BG. Add by Will*/
						up(get_forcebg_semaphore());
					}
				}
				else
				{
					rtd_printk(KERN_ERR, TAG_NAME_VSC, "scaler vsc ioctl VSC_IOC_APP_CONTRO_FORCEBG no display connet!!!!!\n");
				}
			}
			else
			{
				rtd_printk(KERN_ERR, TAG_NAME_VSC, "scaler vsc ioctl VSC_IOC_APP_CONTRO_FORCEBG failed port:%d!!!!!\n", forcetype.port);
			}
			break;
		}

		case VSC_IOC_HDR_OPEN:
		{
			if(rtk_hal_vsc_hdr_open()==FALSE)
				return -1;
			break;
		}
		case VSC_IOC_HDR_CLOSE:
		{
			if(rtk_hal_vsc_hdr_close()==FALSE)
				return -1;
			break;
		}
		case VSC_IOC_HDR_CONNECT:
		{
			VSC_HDR_TYPE_T hdrtype;
			if(copy_from_user((void *)&hdrtype, (const void __user *)arg, sizeof(VSC_HDR_TYPE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_HDR_CONNECT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_vsc_hdr_connect(hdrtype) == FALSE)
					return -1;
			}
			break;
		}
		case VSC_IOC_HDR_DISCONNECT:
		{
			if(rtk_hal_vsc_hdr_disconnect()==FALSE)
				return -1;
			break;
		}

		case VSC_IOC_SET_SubWinShape:
		{
			//Evance->VSC_SUB_SHAPE_INFO_T
			VSC_SUB_SHAPE_INFO_T shape_info;
			VIDEO_RECT_T  shape_region;
			int shape_type;
			if(copy_from_user((void *)&shape_info, (const void __user *)arg, sizeof(VSC_SUB_SHAPE_INFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_SUB_SHAPE_INFO_T copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				{
					//virtual_x =shape_info.rect.x;
					//virtual_y =shape_info.rect.y;
					true_wide =shape_info.rect.w;
					true_high=shape_info.rect.h;
				if (shape_info.shapeinfo == 0)
					sub_shape_type = VSC_MGF_TYPE_RECTANGLE;
				else if (shape_info.shapeinfo == 1)
					sub_shape_type = VSC_MGF_TYPE_CIRCLE;
				else
					sub_shape_type = VSC_MGF_TYPE_CIRCLE;
				subWin_LGowner =1;
#if 0
				printk("\n ***************************virtual_x = %d", virtual_x);
				printk("\n ***************************virtual_y = %d", virtual_y);
				printk("\n ***************************virtual_w = %d", virtual_w);
				printk("\n ***************************virtual_h = %d", virtual_h);
				printk("\n ***************************sub_shape_type = %d", sub_shape_type);
#endif
			}
			}

			break;
		}

		case  VSC_IOC_SET_SetSubWinMode:
		{
			int mode_type = 0;


			if(copy_from_user((void *)&mode_type, (const void __user *)arg, sizeof(VSC_SUB_MODE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_SetSubWinMode copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				printk(KERN_EMERG"[%s][crixus]@@VSC_IOC_SET_SetSubWinMode, mode_type = %d\n", __FUNCTION__, (unsigned int)mode_type);
				sub_mode_type = mode_type;//get sub mode
#ifdef CONFIG_I2RND_ENABLE
				if((i2rnd_test_done == 0) && (sub_mode_type == VSC_SUB_MODE_PBP)){
					i2rnd_test_done = 1;
					rtk_hal_vsc_i2rnd_enable(_ENABLE);
					printk(KERN_EMERG"[%s][crixus]I2RND initial done\n", __FUNCTION__);
				}else if((i2rnd_test_done == 1) && (sub_mode_type == VSC_SUB_MODE_PIP)){
					i2rnd_test_done = 0;
					rtk_hal_vsc_i2rnd_enable(_DISABLE);
					printk(KERN_EMERG"[%s][crixus]I2RND Uninitial done\n", __FUNCTION__);
				}
#endif
				if (sub_mode_type == VSC_SUB_MODE_PIP) {
					if (Get_Live_zoom_mode() == LIVE_ZOOM_SUB )
						Set_LivezoomOrMagnifierPIPON(TRUE);
					else
						Set_LivezoomOrMagnifierPIPON(FALSE);
				}
			}
			break;
		}

		case  VSC_IOC_SET_SetSubWinPurpose:
		{
			VSC_SUB_PURPOSE_T purpose_type;


			if(copy_from_user((void *)&purpose_type, (const void __user *)arg, sizeof(VSC_SUB_PURPOSE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_SetSubWinPurpose copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				Set_Magnifier_LiveZoom_Mode(purpose_type);
				printk(KERN_EMERG"[qiangzhou]@@VSC_IOC_SET_SetSubWinPurpose, purpose_type = %d\n", (unsigned int)purpose_type);

			}
			break;
		}
		case  VSC_IOC_SET_SetDelayBuffer:
		{
			VSC_SET_DELAY_BUFFER_TYPE delay_buffer_type;


			if(copy_from_user((void *)&delay_buffer_type, (const void __user *)arg, sizeof(VSC_SET_DELAY_BUFFER_TYPE)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_SET_DELAY_BUFFER_TYPE copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtk_hal_vsc_SetDelayBuffer(delay_buffer_type.window, delay_buffer_type.buffer);
				printk(KERN_DEBUG,"VSC_SET_DELAY_BUFFER_TYPE, delay_buffer_type.window = %d\n", (unsigned int)delay_buffer_type.window);
				printk(KERN_DEBUG,"VSC_SET_DELAY_BUFFER_TYPE, delay_buffer_type.buffer = %d\n", (unsigned int)delay_buffer_type.buffer);

			}
			break;
		}

		case VSC_IOC_GET_BLACDETECTION_INFO_T:
		{
			//static unsigned int cnt;
			//printk("Enter VSC_IOC_GET_BLACDETECTION_INFO_T\n");
			VSC_GET_BLACDETECTION_INFO_T BLACKDETECTION_INFO;
			VIP_BlackDetectionInfo vip_info;

			BLACKDETECTION_INFO.ready_flag = fwif_color_get_black_detection_info_tv006(&vip_info);

			memcpy(&(BLACKDETECTION_INFO.window.original), &(vip_info.OriRegion), sizeof(VIDEO_RECT_T));
			memcpy(&(BLACKDETECTION_INFO.window.active), &(vip_info.ActRegion), sizeof(VIDEO_RECT_T));
			BLACKDETECTION_INFO.connectwid = Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL);

			if (copy_to_user((void __user *)arg, (void *)&BLACKDETECTION_INFO, sizeof(VSC_GET_BLACDETECTION_INFO_T))) {
				retval = -EFAULT;
				pr_err( "kernel VSC_IOC_GET_BLACDETECTION_INFO_T fail\n");
			}
			#if 0
			if (cnt % 600 == 0)
				printk("BLACKDETECTION_INFO.window = %d, %d %d %d, %d %d %d %d\n", BLACKDETECTION_INFO.window.original.x,BLACKDETECTION_INFO.window.original.y,BLACKDETECTION_INFO.window.original.w,BLACKDETECTION_INFO.window.original.h,BLACKDETECTION_INFO.window.active.x,BLACKDETECTION_INFO.window.active.y,BLACKDETECTION_INFO.window.active.w,BLACKDETECTION_INFO.window.active.h);
			cnt ++;
			#endif
			break;

		}
		case VSC_IOC_SET_BLACDETECTION_EN:
		{
			unsigned char bEnable;
			if(copy_from_user((void *)&bEnable, (const void __user *)arg, sizeof(unsigned char))) {
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_BLACDETECTION_EN copy_from_user failed!!!!!!!!!!!!!!!\n");
			} else {
				scalerVIP_Set_BlackDetection_EN(bEnable);
			}
			break;

		}
		case VSC_IOC_RotateVideo:
		{
			VSC_ROTATE_T rotate_type;
			if(copy_from_user((void *)&rotate_type, (const void __user *)arg, sizeof(VSC_ROTATE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_RotateVideo copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{

#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
				 if (Get_PANEL_VFLIP_ENABLE()) {
                                       if (rotate_type == VSC_ROTATE_90) {
                                               rotate_type = VSC_ROTATE_270;
                                      } else if (rotate_type == VSC_ROTATE_270) {
                                               rotate_type = VSC_ROTATE_90;
                                       }
                               }
				down(&SetMainOutPutRegion_Semaphore);
				rotate_mode_pre = rotate_mode;
				rotate_mode = rotate_type;
				up(&SetMainOutPutRegion_Semaphore);
#endif
			}
			break;
		}

		case VSC_IOC_Set_VD_PTG:
		{
			unsigned char bOnOff = 0;
			if(copy_from_user((void *)&bOnOff, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_Set_VD_PTG copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else{
				if(vsc_set_vd_ptg(bOnOff) == FALSE)
					retval =  -1;
			}
			break;
		}
		case VSC_IOC_GET_UZD_CRC:
		{
			VSC_UZD_CRC pUZD_CRC;
			unsigned int iCRC_Value = 0;
			if(copy_from_user((void *)&pUZD_CRC, (const void __user *)arg, sizeof(VSC_UZD_CRC)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_UZD_CRC copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else{
				if(vsc_get_uzu_crc(pUZD_CRC.wid,&iCRC_Value) == FALSE)
					retval =  -1;
				else{
					pUZD_CRC.CRC_Value = iCRC_Value;
					if(copy_to_user((void __user *)arg, &pUZD_CRC, sizeof(VSC_UZD_CRC)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_EMERG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_GET_UZD_CRC copy_to_user failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VSC_IOC_SET_UZD_PATH:
		{
			unsigned char i3dma_uzd = 0;
			if(copy_from_user((void *)&i3dma_uzd, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_UZD_PATH copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else{
				if(vsc_set_uzd_path(i3dma_uzd) == FALSE)
					retval =  -1;
			}
			break;
		}

		case VSC_IOC_WAIT_MUTEOFF_QUEUE:
		{
			unsigned char winid = 0;
			wait_event_freezable(MUTEOFF_CB_WAIT_QUEUE, sub_muteoff_cb_trigger || main_muteoff_cb_trigger);
			if(main_muteoff_cb_trigger)
			{
				down(&muteoff_cb_sem);
				main_muteoff_cb_trigger = FALSE;
				up(&muteoff_cb_sem);
				winid |= WIN_MAIN_ONLY;//main path mute off
			}
			if(sub_muteoff_cb_trigger)
			{
				down(&muteoff_cb_sem);
				sub_muteoff_cb_trigger = FALSE;
				up(&muteoff_cb_sem);
				winid |= WIN_SUB_ONLY;//sub path mute off
			}
			if(arg)
			{
				if(copy_to_user((void __user *)arg, (void *)&winid, sizeof(unsigned char)))
				{
					rtd_printk(KERN_ERR, TAG_NAME_VSC,  "[ERR] VSC_IOC_WAIT_MUTEOFF_QUEUE copy_to_user error \n");
					retval = EFAULT;
				}
			}
			break;
		}

		case VSC_IOC_SET_WINBLANK_SYNC_MEMC:
		{//this is for mute on to sync memc ready
			VSC_WINBLANK_PARA_T winblankpara;
			if(copy_from_user((void *)&winblankpara, (const void __user *)arg, sizeof(VSC_WINBLANK_PARA_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_WINBLANK_SYNC_MEMC copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "winblankpara.winblankwid=%d,winblankpara.winblankbonoff=%d,winblankpara.winblankcolor=%d\n", winblankpara.winblankwid, winblankpara.winblankbonoff, winblankpara.winblankcolor);

#ifdef CONFIG_HW_SUPPORT_MEMC
				//These are for mute on to wait memc already blck video
				sync_memc_ready = TRUE;//if TRUE. when mute on to wait memc buffer
#endif

				if(rtk_hal_vsc_SetWinBlank(winblankpara.winblankwid, winblankpara.winblankbonoff, winblankpara.winblankcolor) == FALSE)
					retval =  -1;
#ifdef CONFIG_HW_SUPPORT_MEMC
				//These are for mute on to wait memc already blck video
				sync_memc_ready = FALSE;//if TRUE. when mute on to wait memc buffer
#endif
			}
			break;
		}
		case VSC_IOC_SET_DUALDECODER:
		{
			unsigned char dual_decoder_flag = 0;
			if(copy_from_user((void *)&dual_decoder_flag, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_EMERG, TAG_NAME_VSC, "scaler vsc ioctl code=VSC_IOC_SET_DUALDECODER copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else{
				rtk_hal_vsc_Setdualdecoder(dual_decoder_flag);
			}
			break;
		}
		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Scaler vsc disp: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
			break ;
		}
	return retval;


}


#define CONFIG_MAGNIFIER_MESSAGE_QUEUE_SIZE 	6 // Define the size of message queue

static VSC_MAGNIGIER_PARA_T MAGNIFIER_MESSAGEQUEUES_BUF[CONFIG_MAGNIFIER_MESSAGE_QUEUE_SIZE]; // message queue
static unsigned char  InMagnifierQueue, OutMagnifierQueue; // in/out index of message queue


void magnifier_message_push(VSC_MAGNIGIER_PARA_T message)
{
	down(&MagMsg_Semaphore);
	MAGNIFIER_MESSAGEQUEUES_BUF[InMagnifierQueue] = message;
	InMagnifierQueue = (InMagnifierQueue + 1) % CONFIG_MAGNIFIER_MESSAGE_QUEUE_SIZE;
	//frank@0506 add avoid message queue full and can not be pop
	if(InMagnifierQueue == OutMagnifierQueue){//Queue is full
		if(InMagnifierQueue == 0)
			InMagnifierQueue = CONFIG_MAGNIFIER_MESSAGE_QUEUE_SIZE-1;
		else
			InMagnifierQueue = InMagnifierQueue-1;
	}
	up(&MagMsg_Semaphore);
}

VSC_MAGNIGIER_PARA_T ManifierNULLmsg = {VIDEO_WID_MAXN, {0,0,0,0}, {0,0,0,0}};

VSC_MAGNIGIER_PARA_T magnifier_message_pop(void)
{
	VSC_MAGNIGIER_PARA_T msg;
	down(&MagMsg_Semaphore);
	if(OutMagnifierQueue == InMagnifierQueue) {
		up(&MagMsg_Semaphore);
		return ManifierNULLmsg;
	}
	msg = MAGNIFIER_MESSAGEQUEUES_BUF[OutMagnifierQueue];
	MAGNIFIER_MESSAGEQUEUES_BUF[OutMagnifierQueue] = ManifierNULLmsg;
	OutMagnifierQueue = (OutMagnifierQueue + 1) % CONFIG_MAGNIFIER_MESSAGE_QUEUE_SIZE;
	up(&MagMsg_Semaphore);

	return msg;
}


static bool magnifier_tsk_running_flag = FALSE;//Record vsc_connet_apply_tsk status. True: Task is running
static struct task_struct *p_magnifier_tsk = NULL;


static int vsc_magnifier_tsk(void *p)//This task run rtk_check_signal to check signal stable or not
{
    rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "vsc_magnifier_tsk()\n");
	current->flags &= ~PF_NOFREEZE;
    while (1)
    {
    		if(Get_Live_zoom_mode() == LIVE_ZOOM_OFF) {
			msleep(20);
    		} else {
			VSC_MAGNIGIER_PARA_T msg;
			msg = magnifier_message_pop();
			if(msg.magnifierWid != VIDEO_WID_MAXN) {
				if(msg.magnifierWid == VIDEO_WID_0)
					Scaler_DispWindowZoomin(SLR_MAIN_DISPLAY, msg.magnifierinregion, msg.magnifieroutregion,0,0,FALSE);
				else if(msg.magnifierWid == VIDEO_WID_1)
					Scaler_DispWindowZoomin(SLR_SUB_DISPLAY, msg.magnifierinregion, msg.magnifieroutregion,msg.W,msg.H,TRUE);
			} else {
				msleep(5);
			}
    		}
		if (freezing(current))
        	{
			try_to_freeze();
        	}

		if (kthread_should_stop()) {
         	break;
      	}
    }
    rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####vsc_magnifier_tsk: exit...####\n");
    do_exit(0);
    return 0;
}

static void create_magnifier_tsk(void)
{
	int i;
	int err;
	for(i=0; i<CONFIG_MAGNIFIER_MESSAGE_QUEUE_SIZE; i++)
		MAGNIFIER_MESSAGEQUEUES_BUF[i] = ManifierNULLmsg;

	if (magnifier_tsk_running_flag == FALSE) {
		p_magnifier_tsk = kthread_create(vsc_magnifier_tsk, NULL, "magnifier_tsk");

	    if (p_magnifier_tsk) {
			wake_up_process(p_magnifier_tsk);
			magnifier_tsk_running_flag = TRUE;
	    } else {
	    	err = PTR_ERR(p_magnifier_tsk);
	    	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Unable to start p_magnifier_tsk (err_id = %d)./n", err);
	    }
	}
}

static void delete_magnifier_tsk(void)
{
	int ret;
	if (magnifier_tsk_running_flag) {
 		ret = kthread_stop(p_magnifier_tsk);
 		if (!ret) {
 			p_magnifier_tsk = NULL;
 			magnifier_tsk_running_flag = FALSE;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "p_magnifier_tsk thread stopped\n");
 		}
	}
}
extern void i2rnd_debug(void);
static bool vsc_tsk_running_flag = FALSE;//Record vsc_scaler_tsk status. True: Task is running
static struct task_struct *p_vsc_tsk = NULL;

static int vsc_scaler_tsk(void *p)//This task run scaler or check signal stable or not
{
	unsigned char input_src_type;
	unsigned char input_src_form;
	StructSrcRect winSrcRect;
	VSC_INPUT_TYPE_T srctype;
    struct cpumask vsc_cpumask;
	int timeout;
	unsigned char port;
	static int print_count = 200;
	static int ld_debug_cnt=0;
	current->flags &= ~PF_NOFREEZE;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "vsc_scaler_tsk()\n");
    cpumask_clear(&vsc_cpumask);
    cpumask_set_cpu(0, &vsc_cpumask); // run task in core 0
    cpumask_set_cpu(2, &vsc_cpumask); // run task in core 2
    cpumask_set_cpu(3, &vsc_cpumask); // run task in core 3
    sched_setaffinity(0, &vsc_cpumask);

    while (1)
    {
		msleep(10);
		if(OutpuLocalDimmingPatMode == TRUE){
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "#Enter LocalDimming debug mode#\n");
			continue;
		}

		if(TV006_WB_Pattern_En == TRUE){
			if(DbgSclrFlgTkr.Main_Reset_Mode_flag)	//WOSQRTK-7881 should go reset after close in WB background
			{
				down(&Main_ResetMode_Semaphore);
				DbgSclrFlgTkr.Main_Reset_Mode_flag = FALSE;
				up(&Main_ResetMode_Semaphore);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n#####func:%s DO Main reset mode during WB#####\r\n", __FUNCTION__);
				down(&VSC_Semaphore);
				drvif_mode_resetmode(SLR_MAIN_DISPLAY);//Reset Mode for Main
				up(&VSC_Semaphore);
			}
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "#Enter WB Pattern debug mode#\n");	//WOSQRTK-7731
			continue;
		}

		if(vpq_ld_running_flag == TRUE){
#ifdef CONFIG_RTK_KDRV_PWM
			if((DbgSclrFlgTkr.vpq_ld_first_boot==FALSE)||(((IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)-ld_time_tick)/90) > 1100)){

				if((DbgSclrFlgTkr.vpq_ld_first_boot==TRUE)){ // protect first enter after resume 1.1sec, otherwise no need to check time
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "[%s] ld tick time = %d (cnt:%d)\n", __FUNCTION__, (IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)-ld_time_tick)/90,
						ld_debug_cnt);
				}
				DbgSclrFlgTkr.vpq_ld_first_boot = FALSE;
				down(&VPQ_ld_running_Semaphore);
				drvif_HAL_VPQ_LED_LDEnable(vpq_led_LDEnable);
				vpq_ld_running_flag = FALSE;
				up(&VPQ_ld_running_Semaphore);
				ld_debug_cnt = 0;
			}else{
				ld_debug_cnt++;
			}
#endif
		}
		#if 1
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE){
			int smooth_toggle_ret = 0;
			zoom_update_scaler_info_from_vo_smooth_toggle(SLR_MAIN_DISPLAY);//update vo smooth toggle info
			if (rtk_hal_vsc_Getdualdecoder() && (0== rtk_hal_vsc_Getdualdecoder_run())) {
				rtk_hal_vsc_Setdualdecoder_run(1);
				Scaler_DualChannelRpc(1);
				rtd_printk(KERN_INFO, TAG_NAME_VSC, "dual decoder start to run\n");
			}
			if(DbgSclrFlgTkr.Main_smooth_toggle_set_flag || DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off) {
				unsigned char Main_smoothtoggle_forcebg_flag=0;
				unsigned char Main_smoothtoggle_from_mute_off = FALSE;//if TRUE, means mute off trigger smooth toggle
				srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);
				down(&SetMainOutPutRegion_Semaphore);
				if(DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off || DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off)
					Main_smoothtoggle_from_mute_off = TRUE;//if TRUE, means mute off trigger smooth toggle
				DbgSclrFlgTkr.smoothtoggle_start_flag = TRUE;
				DbgSclrFlgTkr.Main_smooth_toggle_set_flag = false;
				DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off = false;
				if (DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag) {
					Main_smoothtoggle_forcebg_flag=TRUE;
					DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag =false;
				}
				Scaler_DispWindowSet(main_dispwin);
				if(srctype != VSC_INPUTSRC_AVD) {
					zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height, ZOOM_CROP);
				}
				up(&SetMainOutPutRegion_Semaphore);
				if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY)) {
					ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
					main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
					timeout = 30;
					while(!main_display_control_rsv_reg.m_force_bg && timeout) {
						timeout -- ;
						msleep(10);
						main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
					}
					pr_info("before smoothtoggle,need wait forcebg ok timeout=%d\n",timeout);
				}

				#ifdef CONFIG_ALL_SOURCE_DATA_FS
				if ((drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC) == FALSE)
					&& (1==Scaler_get_data_framesync(SLR_MAIN_DISPLAY))){ //data frc change to data fs,display timing need change
					down(get_scaler_fll_running_semaphore());
					modestate_set_fll_running_flag(_DISABLE);
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
					Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC,TRUE);
					up(get_scaler_fll_running_semaphore());
					rtd_printk(KERN_INFO, TAG_NAME_VSC, "vsc_scaler_tsk timing change to framesync\n");
				}
				#endif

				if(srctype == VSC_INPUTSRC_AVD)
				{
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

		#ifdef CONFIG_SDNR_CROP
					//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
					//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));
					down(&VSC_Semaphore);
					Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
					winSrcRect = Scaler_DispWindowGet();
					zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY,Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY, main_input_size.srcx), main_input_size.srcy, Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY, main_input_size.src_wid),  main_input_size.src_height, ZOOM_CROP);
					smooth_toggle_ret = zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
					up(&VSC_Semaphore);
					//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
					//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));
		#else

					if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(SLR_MAIN_DISPLAY))
					{
						VIDEO_RECT_T inregion_avd;
						VIDEO_RECT_T outregion_avd;
						rtk_hal_vsc_GetOutputRegion(SLR_MAIN_DISPLAY, &outregion_avd);
						Scaler_CalWindowZoominForAVD(SLR_MAIN_DISPLAY, &inregion_avd, &outregion_avd);

						rtd_printk(KERN_INFO, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						Scaler_DispWindowZoominForAVD(SLR_MAIN_DISPLAY, inregion_avd, outregion_avd,FALSE);
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
						//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
					}
					else
					{
						down(&VSC_Semaphore);
						Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
						winSrcRect = Scaler_DispWindowGet();
						smooth_toggle_ret = zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
						up(&VSC_Semaphore);
					}
	#endif
#endif

				}
				else
				{
					down(&VSC_Semaphore);
					Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
					winSrcRect = Scaler_DispWindowGet();
					smooth_toggle_ret = zoom_imd_smooth_toggle_config(SLR_MAIN_DISPLAY, winSrcRect.srcx, winSrcRect.srcy, winSrcRect.src_wid, winSrcRect.src_height, ZOOM_DISP);
					up(&VSC_Semaphore);
				}

				if((DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off == FALSE) && (DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag == FALSE)){
					rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n#####open forcebg after smoothtoggle\r\n");
					if((Main_smoothtoggle_forcebg_flag==TRUE)/*&&(srctype == VSC_INPUTSRC_VDEC)*/&&(!Get_display_forcebg_mask(SLR_MAIN_DISPLAY,SLR_FORCE_BG_TYPE_VSC)))
					{
						Check_smooth_toggle_update_flag(SLR_MAIN_DISPLAY);
						if (srctype == VSC_INPUTSRC_ADC) {//componet 5A wait at least two frame in case of shaking
							int timingMode = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MODE_CURR);
							if((Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE)) && (Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_YPBPR)&&((timingMode == _MODE_480I)||(timingMode == _MODE_576I)))
							{
								unsigned int waitsec = 3*10000/(int)Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ);
								msleep(waitsec);
							}
						}
					}

					if(srctype == VSC_INPUTSRC_VDEC)
					{
						port = Get_DisplayMode_Port(SLR_MAIN_DISPLAY);
						timeout = 30;
						while((get_vo_avsync_flag(port) == FALSE) && timeout && Main_smoothtoggle_from_mute_off)
						{
							timeout -- ;
							if(DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off || DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag || DbgSclrFlgTkr.Main_Scaler_Stop_flag)
								break;
							if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
								break;
							msleep(1);
						}
						
						if(Main_smoothtoggle_from_mute_off)
						{
							Check_smooth_toggle_update_flag(SLR_MAIN_DISPLAY);
						}

						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n### smooth toggle vo wait sync timeout:%d####\r\n", timeout);

						//Set FLL flag when DTV channel changing
						if(vbe_disp_get_adaptivestream_fs_mode() == 1){
							//drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
							modestate_set_fll_running_flag(_DISABLE);
							//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"@@@@@@@@@@@FLL disable for adaptive stream\n");
						}else{

						if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI)
							modestate_set_fll_running_flag(_DISABLE);
						else {
							if (Main_smoothtoggle_forcebg_flag && DbgSclrFlgTkr.check_only_xy_shift_same_region) {//only the same timing DTV exchange need reset_freerun
								#ifdef CONFIG_I2RND_ENABLE
								if(Scaler_I2rnd_get_enable() == _DISABLE)
								#endif
								//for enter fixlastline condition, reset timing to freerun
								if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC)==FALSE){
									drivf_scaler_reset_freerun();
									modestate_set_fll_running_flag(_ENABLE);
								}
							}
						}
							//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"@@@@@@@@@@@FLL enable for DTV changing channel\n");
						}
					}
					DbgSclrFlgTkr.smoothtoggle_start_flag = FALSE;
					if((DbgSclrFlgTkr.Main_run_smooth_toggle_from_mute_off == FALSE) && (DbgSclrFlgTkr.Main_SetOutput_request_muteoff_smooth_toggle_set_flag == FALSE) &&
						(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
						if (!Get_display_forcebg_mask(SLR_MAIN_DISPLAY,SLR_FORCE_BG_TYPE_VSC)) {
							down(get_forcebg_semaphore());
							scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
							up(get_forcebg_semaphore());
						}
					}
				}
			} else {
				if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC)&& (Get_DisplayMode_Src(SLR_MAIN_DISPLAY)==VSC_INPUTSRC_VDEC)) {
					onms_onms1_ctrl_RBUS onms_onms1_ctrl_reg;
					onms_onms1_ctrl_reg.regValue =  IoReg_Read32(ONMS_onms1_ctrl_reg);
					if(!onms_onms1_ctrl_reg.on1_start_ms) {
						Check_smooth_toggle_update_flag(SLR_MAIN_DISPLAY);
						drvif_mode_enableonlinemeasure(SLR_MAIN_DISPLAY);
						drvif_mode_onlinemeasure_setting(SLR_MAIN_DISPLAY, _SRC_VO, TRUE, FALSE);
					}
				}
			}

			/*livezoom and magnifier not support single buffer mode*/
			//game mode dynamic checking
			if((Get_Live_zoom_mode()==LIVE_ZOOM_OFF)&&(drv_memory_get_game_mode_dynamic() != drv_memory_get_game_mode_flag())){

				if(drv_memory_get_game_mode_dynamic() == _ENABLE){
					/*drv_memory_SingleBuffer_GameMode_Dynamic(_ENABLE);*/
					drv_memory_set_game_mode(_ENABLE);
					/*drv_memory_SingleBuffer_GameMode_Dynamic(_ENABLE);	*/
				} else {
					//drivf_scaler_reset_freerun();
					/*drv_memory_SingleBuffer_GameMode_Dynamic(_DISABLE);*/
					drv_memory_set_game_mode(_DISABLE);
					/*drv_memory_SingleBuffer_GameMode_Dynamic(_DISABLE);*/
				}

				srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);

				if (((srctype == VSC_INPUTSRC_ADC)
					|| (srctype == VSC_INPUTSRC_HDMI)
					||((srctype == VSC_INPUTSRC_AVD)  && (get_AVD_Input_Source() != _SRC_TV))))
				{/*qiangzhou:only need run av hdmi ypp, DTV ATV Playback,CP no need run these*/
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[GameMode][started]Main re run scaler flow!!\n");
					//set the game mode dynamic flag.
					down(&GameMode_Check_Semaphore);
					DbgSclrFlgTkr.game_mode_dynamic_flag = TRUE;
					up(&GameMode_Check_Semaphore);

					set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_GameMode, TRUE);
					down(get_forcebg_semaphore());
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
					up(get_forcebg_semaphore());
#ifdef CONFIG_ALL_SOURCE_DATA_FS
					//if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC)){
						//drivf_scaler_reset_freerun();
					//}
#endif
					fw_scalerip_set_di_gamemode_setting(fw_scalerip_get_di_gamemode());


					//run scaler IM-domain flow to sync timing info after running smooth toggle@Crixus 20160919
					//clear_imd_smooth_toggle_clk_time2switch_en(SLR_MAIN_DISPLAY);
					//down(get_double_buffer_semaphore());
					//imd_smooth_enable_main_double_buffer(FALSE);
					//up(get_double_buffer_semaphore());
					//set_zoom_reset_double_state(_DISABLE,SLR_MAIN_DISPLAY);

					//down(&SetMainOutPutRegion_Semaphore);
					//set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
					//Scaler_DispWindowSet(main_dispwin);
					//up(&SetMainOutPutRegion_Semaphore);
					if(srctype == VSC_INPUTSRC_ADC)
						set_auto_phase_flow_bypass_flag(TRUE);//No need to run auto phase flow again
					//down(&VSC_Semaphore);
					//DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;// protected by semaphore, in case  scaler tsk cleared it
					//rtk_output_connect(SLR_MAIN_DISPLAY);/*qiangzhou added for m domain compress mode close and open*/
					//up(&VSC_Semaphore);
					if(srctype == VSC_INPUTSRC_ADC)
						set_auto_phase_flow_bypass_flag(FALSE);//Rest the auto phase bypass flag

					//if(vbe_disp_get_dynamic_memc_bypass_flag() == TRUE){
						//vbe_disp_game_mode_memc_bypass(drv_memory_get_game_mode_dynamic_flag());
					//}

					if(vbe_disp_get_dynamic_memc_bypass_flag() == TRUE){
						if(drv_memory_get_game_mode_dynamic_flag()==TRUE){
							if(fw_get_vsc_GameMode() == FALSE){
								vbe_disp_game_mode_memc_bypass(1);
								fw_set_vsc_GameMode(1);
							}
						}else{
							if(fw_get_vsc_GameMode() == TRUE){
								vbe_disp_game_mode_memc_bypass(0);
								fw_set_vsc_GameMode(0);
							}
						}
					}

					if(drv_memory_get_game_mode() == _ENABLE){
						//Add VSC semaphore to protect vtotal modification @Crixus 20161219
						down(&VSC_Semaphore);
						//I3DDMA 1-buffer
						if(drvif_i3ddma_triplebuf_flag())
							drv_I3ddmaVodma_SingleBuffer_GameMode(_DISABLE);
						else
							drv_I3ddmaVodma_SingleBuffer_GameMode(_ENABLE);
						//drv_memory_SingleBuffer_GameMode_Dynamic(_ENABLE);
						up(&VSC_Semaphore);
						//printk(KERN_EMERG"[crixus]Enter game mode!!!\n");
					} else {
						//I3DDMA 3 buffer
						drv_I3ddmaVodma_SingleBuffer_GameMode(_DISABLE);
						//drv_memory_SingleBuffer_GameMode_Dynamic(_DISABLE);
						//printk(KERN_EMERG"[crixus]Exit game mode!!!\n");
					}

					//Disable the game mode dynamic flag.
					down(&GameMode_Check_Semaphore);
					DbgSclrFlgTkr.game_mode_dynamic_flag = FALSE;
					up(&GameMode_Check_Semaphore);
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"[GameMode][ended]Main re run scaler flow!!\n");
				}

			}else{
				if(vbe_disp_get_dynamic_memc_bypass_flag() == TRUE){
					if(drv_memory_get_game_mode_dynamic_flag()==TRUE){
						if(fw_get_vsc_GameMode() == FALSE){
							vbe_disp_game_mode_memc_bypass(1);
							fw_set_vsc_GameMode(1);
						}
					}else{
						if(fw_get_vsc_GameMode() == TRUE){
							vbe_disp_game_mode_memc_bypass(0);
							fw_set_vsc_GameMode(0);
						}
					}
				}
			}
		}else{
			if(DbgSclrFlgTkr.Main_smooth_toggle_set_flag) {
				down(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_smooth_toggle_set_flag=FALSE;
				up(&SetMainOutPutRegion_Semaphore);
			}
		}



		#endif
		if(vsc_debug_mode)
		{
			print_count --;
			if(print_count == 0) {
				print_count = 200;
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####vsc_scaler_tsk still alive#####\r\n");
			}
		}

		if(DbgSclrFlgTkr.run_iv2dv_slow_tuning_flag)
		{
			if(drv_memory_get_game_mode_iv2dv_slow_enable() == TRUE){
				rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n#drv_run_GameMode_iv2dv_slow_tuning#\r\n");
				down(&Iv2dv_Slow_Tuning_Semaphore);
				drv_run_GameMode_iv2dv_slow_tuning();
				up(&Iv2dv_Slow_Tuning_Semaphore);
			}
		}

		if(DbgSclrFlgTkr.Main_Reset_Mode_flag)
		{
			down(&Main_ResetMode_Semaphore);
#if 0//def CONFIG_I2RND_ENABLE
			if(Scaler_I2rnd_get_enable() == _ENABLE){
				Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
				printk(KERN_EMERG"[%s]I2RND_MAIN_S0_TABLE in main reset mode!!!!\n",__FUNCTION__);
			}
#endif
			DbgSclrFlgTkr.Main_Reset_Mode_flag = FALSE;
			up(&Main_ResetMode_Semaphore);
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n#####func:%s DO Main reset mode#####\r\n", __FUNCTION__);
			down(&VSC_Semaphore);
			drvif_mode_resetmode(SLR_MAIN_DISPLAY);//Reset Mode for Main
			vbe_disp_game_mode_memc_bypass(0);
			fw_set_vsc_GameMode(0);
			up(&VSC_Semaphore);
		}
#ifdef CONFIG_RTK_KDRV_DV
		if(request_letter_dtg_change && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && ((rtd_inl(VGIP_Smooth_tog_ctrl_reg)&_BIT0)==0))
		{
			ppoverlay_main_background_h_start_end_RBUS main_background_h_start_end_reg;
			ppoverlay_main_background_v_start_end_RBUS main_background_v_start_end_reg;
			unsigned char dolby_dtg_black_flag;
			unsigned long flags;//for spin_lock_irqsave
			spin_lock_irq(dolby_letter_box_spinlock());
			main_background_h_start_end_reg.regValue = dolby_proverlay_background_h_start_end;
			main_background_v_start_end_reg.regValue = dolby_proverlay_background_v_start_end;
			dolby_dtg_black_flag = letter_box_black_flag;
			request_letter_dtg_change = FALSE;
			spin_unlock_irq(dolby_letter_box_spinlock());
			IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, main_background_h_start_end_reg.regValue);
			IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);
			down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			if(dolby_dtg_black_flag)
				IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT2);
			else
				IoReg_ClearBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT2);
			spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
			IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);//Aplly double buffer
			spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
			up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		}
#endif

		if((DbgSclrFlgTkr.memc_realcinema_run_flag)&&((rtd_inl(VGIP_Smooth_tog_ctrl_reg)&_BIT0)==0)) //wait smooth toggle finish
		{
			down(&Memc_Realcinema_Semaphore);
			DbgSclrFlgTkr.memc_realcinema_run_flag=FALSE;
			up(&Memc_Realcinema_Semaphore);


			down(&VSC_Semaphore);
			memc_realcinema_framerate();
			up(&VSC_Semaphore);
		}

#ifdef CONFIG_I2RND_ENABLE
		//trigger I2rnd sub => vo => main flow
		if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_TRIGGER_RUN_MAIN)){
				vsc_i2rnd_sub_stage = I2RND_STAGE_MAIN_GET_RPC;
				printk(KERN_EMERG"[I2RND]@@@@@@@@@@@@I2RND_STAGE_MAIN_GET_RPC\n");
				//run main patch
				down(&VSC_Semaphore);
				scaler_i2rnd_run_main();
				//Disable sub fbg after sub=>vo=>mcap2 done @Crixus 20160728
				down(get_forcebg_semaphore());
				scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
				up(get_forcebg_semaphore());
				printk(KERN_EMERG"[I2RND]Disable fbg after sub => vo => main mcap2 done.\n");
				//Change stage to default stage
#if 0//frank test
				if(vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_I2RND_DONE){
					vsc_i2rnd_sub_stage = I2RND_STAGE_DISABLE;
				}
#endif
				up(&VSC_Semaphore);
		}

		//move APVR run scaler to tsk @Crixus 20160824
		if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_TRIGGER_RUN_MAIN)){
			vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_TRIGGER_RUN_MAIN;
			apvr_request_run_main_path();
		}
#endif

		if (LiveZoom_MEMCClose_Flag == TRUE) {
			down(&VSC_Semaphore);
			if (LiveZoom_MEMCClose_Flag == TRUE) {
				down(get_livezoom_memcclose_Semaphore());
				LiveZoom_MEMCClose_Flag = FALSE;
				up(get_livezoom_memcclose_Semaphore());
				memc_setting_displayDtiming_framerate();
			}
			up(&VSC_Semaphore);
		}

		if (DbgSclrFlgTkr.rotate_run_scaler_flag || DbgSclrFlgTkr.Main_Run_Scaler_flag && (DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && (DbgSclrFlgTkr.Main_Reset_Mode_flag == FALSE)//wait vsc close reset mode ready
#ifdef CONFIG_I2RND_ENABLE
			&& ((vsc_i2rnd_sub_stage == I2RND_STAGE_DISABLE) ||(vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_I2RND_DONE))
#endif
			) {
			set_current_scaler_source_num(SLR_MAIN_DISPLAY);//record current vsc source num
			srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);
			down(&SetMainOutPutRegion_Semaphore);
			DbgSclrFlgTkr.Main_Run_Scaler_flag = FALSE;
			DbgSclrFlgTkr.Main_Output_Set_flag = FALSE;
			DbgSclrFlgTkr.main_VO_smoothtoggle_need_presetting = TRUE;
			DbgSclrFlgTkr.rotate_run_scaler_flag = FALSE;
			DbgSclrFlgTkr.rotate_muteoff_request_flag = FALSE;
			set_input_for_vgip(SLR_MAIN_DISPLAY, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
			Scaler_DispWindowSet(main_dispwin);
			//Fixed ATV all direction zoom non-working issue. @Crixus 20160829
			if(srctype != VSC_INPUTSRC_AVD){
				//printk(KERN_EMERG"[%s][%d]\n", __FUNCTION__, __LINE__);
				zoom_record_input_output_pre_size(SLR_MAIN_DISPLAY,main_input_size,main_dispwin);
			}
			set_ori_rotate_mode(get_rotate_mode());
			set_rotate_mode(rotate_mode);
			up(&SetMainOutPutRegion_Semaphore);

			port = Get_DisplayMode_Port(SLR_MAIN_DISPLAY);
#ifdef CONFIG_I2RND_ENABLE
			if(Scaler_I2rnd_get_enable() == _ENABLE){
				Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
				printk(KERN_EMERG"[%s]I2RND_MAIN_S0_TABLE!!!!\n",__FUNCTION__);
			}
#endif
			switch(srctype)
			{
				case VSC_INPUTSRC_AVD:
					if(get_AVD_Input_Source() != _SRC_TV)
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Main path VSC_Src:VSC_INPUTSRC_AVD(AV)#####\r\n");
				break;

				case VSC_INPUTSRC_ADC:
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Main path VSC_Src:VSC_INPUTSRC_ADC#####\r\n");
				break;

				case VSC_INPUTSRC_HDMI:
					set_ori_HDMI_HDR_mode(get_HDMI_HDR_mode());//recode current hdr mode
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Main path VSC_Src:VSC_INPUTSRC_HDMI#####\r\n");
				break;

				case VSC_INPUTSRC_VDEC:
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Main path VSC_Src:VSC_INPUTSRC_VDEC#####\r\n");
				break;

				case VSC_INPUTSRC_JPEG:
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Main path VSC_Src:VSC_INPUTSRC_JPEG#####\r\n");
				break;

				default:
					break;
			}
			//game mode search status checking:ex:change input source
			if(drv_memory_get_game_mode_dynamic() != drv_memory_get_game_mode_flag()){
				if(drv_memory_get_game_mode_dynamic() == _ENABLE){
					drv_memory_set_game_mode(_ENABLE);
				} else {
					drv_memory_set_game_mode(_DISABLE);
				}
			}
#ifdef CONFIG_FORCE_RUN_I3DDMA
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH)
			{
				//rtd_printk(KERN_EMERG, TAG_NAME_VSC,"######fw_set_vsc_GameMode(0) Line=%d #######\n", __LINE__);
				fw_set_vsc_GameMode(0);
				/*main path always run i3ddma->vodma->scaler*/
				if(((srctype == VSC_INPUTSRC_HDMI) /*&& (get_HDMI_HDR_mode() == HDR_MODE_DISABLE)*/)
				|| (srctype == VSC_INPUTSRC_ADC) || ((srctype == VSC_INPUTSRC_AVD)  && (get_AVD_Input_Source() != _SRC_TV)))
				{
				    down(&Force_Run_Idma_Semaphore);
					set_force_i3ddma_enable(TRUE);
					if(scaler_force_run_idma(SLR_MAIN_DISPLAY, srctype) == FALSE)
					{
						set_force_i3ddma_enable(false);
						Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_HDMI, 0xfa);
						up(&Force_Run_Idma_Semaphore);
						pr_err("######scaler_force_run_idma fail fail fail!!!#######\n");
						down(&SetMainOutPutRegion_Semaphore);
						reset_any_srcrect(&main_dispwin_pre);
						up(&SetMainOutPutRegion_Semaphore);
						if(srctype  == VSC_INPUTSRC_ADC)
						{//Need to rerun scaler
							StructDisplayInfo  *p_timing = NULL;
							down(get_adc_detectsemaphore());
							vga_good_timing_ready = FALSE;
							p_timing = Get_ADC_Dispinfo();
							if(p_timing!=NULL)
							{
								p_timing->IPH_ACT_WID_PRE = 0;
								p_timing->IPV_ACT_LEN_PRE = 0;
								p_timing->IVFreq = 0;
								p_timing->IHFreq = 0;
								p_timing->IHTotal = 0;
								p_timing->IVTotal = 0;
								p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
							}
							if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
								ADC_OnlineMeasureError_Handler(get_ADC_Input_Source());
								Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_ADC, TRUE);/*Let Webos get zero timing*/
								//YPbPr_Power_ADCRGB(FALSE);//Turn off RGB for saving power on detecting.  brandon add
								ADC_set_detect_flag(TRUE);
							}
							up(get_adc_detectsemaphore());
						}
						else if(srctype  == VSC_INPUTSRC_HDMI)
						{//Need to rerun scaler
							vfe_hdmi_drv_handle_on_line_measure_error(0);
							vfe_hdmi_drv_adapter();
							down(get_hdmi_detectsemaphore());
							if (get_HDMI_Global_Status() == SRC_CONNECT_DONE) {
								Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_HDMI, TRUE);/*Let Webos get zero timing*/
								HDMI_set_detect_flag(TRUE);
							}
							up(get_hdmi_detectsemaphore());
						}
						else if(srctype  == VSC_INPUTSRC_AVD)
						{//Need to rerun scaler
							/*//no need because AVD don't stop detect task
							down(get_vdc_detectsemaphore());
							if (get_AVD_Global_Status() == SRC_CONNECT_DONE) {
								VDC_set_detect_flag(TRUE);
							}
							up(get_vdc_detectsemaphore());
							*/
							Set_Reply_Zero_Timing_Flag(VSC_INPUTSRC_AVD, TRUE);/*Let Webos get zero timing*/
						}
						I3DDMA_Setup3DDMA(&i3ddmaCtrl, I3DDMA_3D_OPMODE_DISABLE);
						continue;
					}
					else
					{
						/*stored for iv2pv delay(i3ddma and vodma) setting at gamemode*/
						//printk("[qiangzhou22]SLR_INPUT_MODE_CURR = %d\n",Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
						Set_GamemodeSaveI3ddmaGetcurMode(Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
					    up(&Force_Run_Idma_Semaphore);
						pr_notice("\r\n########func:%s force i3ddma_success (modeidx: %d)##########\r\n", __FUNCTION__, Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
						port = 0;
					}
				}
				else
				{
					if(srctype != VSC_INPUTSRC_AVD)	//for vdec, jpeg case
						set_force_i3ddma_enable(false);
				}
			}
#endif

#ifdef CONFIG_FORCE_RUN_I3DDMA
			if(((srctype == VSC_INPUTSRC_VDEC || srctype == VSC_INPUTSRC_JPEG) && ((DbgSclrFlgTkr.Main_force_frc_flag == FALSE)&&(DbgSclrFlgTkr.Main_force_frc_fs_flag==FALSE)))
				|| (((srctype == VSC_INPUTSRC_ADC) || ((srctype == VSC_INPUTSRC_HDMI) && (DbgSclrFlgTkr.RGB444Mode_change == 0)) || (srctype == VSC_INPUTSRC_AVD && (get_AVD_Input_Source() != _SRC_TV))) && get_force_i3ddma_enable(SLR_MAIN_DISPLAY))
				)
#else
			if ((srctype == VSC_INPUTSRC_VDEC || srctype == VSC_INPUTSRC_JPEG) && ((DbgSclrFlgTkr.Main_force_frc_flag == FALSE)&&(DbgSclrFlgTkr.Main_force_frc_fs_flag==FALSE)))
#endif
			{
				if(DbgSclrFlgTkr.adaptive_stream)
					timeout = 300;
				else
					timeout = 200;
				while (timeout--) {
					if(DbgSclrFlgTkr.Main_Scaler_Stop_flag) {
						rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "\r\n####VO already disconnet#####\r\n");
						break;
					}
					if(get_vo_change_flag(port)) {
						break;
					}
					msleep(10);
				}
#ifdef CONFIG_I2RND_ENABLE
				//for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823
				if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_TRIGGER_RUN_MAIN)){
					vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_I3DDMA_RPC;
					//printk(KERN_EMERG"[%s][%d]vsc_i2rnd_main_rerun_stage = %d!!!!\n",__FUNCTION__, __LINE__, vsc_i2rnd_atv_main_rerun_stage);
				}
#endif
				if((srctype == VSC_INPUTSRC_VDEC) || (srctype == VSC_INPUTSRC_JPEG))
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Go VO case. timeout:%d , port:%d#####\r\n", timeout,port);
				else if(timeout <= 0)
					rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Go i3ddma case. timeout err#####\r\n");

				if((srctype == VSC_INPUTSRC_VDEC) && !DbgSclrFlgTkr.Main_Scaler_Stop_flag)
				{
					DbgSclrFlgTkr.Main_during_scalerflow_flag = TRUE;//WOSQRTK-7524 patch. Avoid webos call mute off during scaler flow
				}
			}
			if(DbgSclrFlgTkr.Main_force_frc_fs_flag) {
				down(&SetMainOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Main_force_frc_fs_flag=FALSE;
				up(&SetMainOutPutRegion_Semaphore);
			}

//			if((srctype == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
			if(srctype == VSC_INPUTSRC_AVD)
			{
				// If signal is locked, needs to wait VDC_DETECT_STAGE_FINAL
				if((Scaler_AVD_GetDetectStage() == VDC_DETECT_STAGE_FINAL) || (drvif_video_status_reg(VDC_no_signal)==1)) // Need wait detect ready. (0 == vdc_LockStatus) means snow screen
				{
					if(!DbgSclrFlgTkr.Main_Output_Set_flag && !DbgSclrFlgTkr.Main_Scaler_Stop_flag && !DbgSclrFlgTkr.Main_Run_Scaler_flag) {
						if(get_AVD_Input_Source() == _SRC_TV)
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Main path VSC_Src:VSC_INPUTSRC_AVD(ATV)#####\r\n");
						if (0 == drvif_video_status_reg(VDC_no_signal))
						{
#if 0 //def CONFIG_ENABLE_VD_27MHZ_MODE
							if(Scaler_AVD_CheckATVTimingChange(SLR_MAIN_DISPLAY) || ((main_dispwin.src_wid < 960)&&(get_AVD_Input_Source() != _SRC_TV))) {//WOSQRTK-6104 patch
#else
							if(Scaler_AVD_CheckATVTimingChange(SLR_MAIN_DISPLAY)) {
#endif
								Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
								if(get_AVD_Input_Source() == _SRC_TV)
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "#######Switch ATV different format##########\r\n");
							} else {
								if(get_AVD_Input_Source() == _SRC_TV)
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "#######Switch ATV same format##########\r\n");
								modestate_set_fll_running_flag(_ENABLE);
							}
						}
						else
						{
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "vsc_scaler_tsk  ATV no-signal\n");
						}

						if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH) {
							if(!DbgSclrFlgTkr.Main_Output_Set_flag && !DbgSclrFlgTkr.Main_Scaler_Stop_flag && !DbgSclrFlgTkr.Main_Run_Scaler_flag) {
#ifdef CONFIG_FORCE_RUN_I3DDMA
								if(get_AVD_Input_Source() == _SRC_TV)
								{
								    down(&Force_Run_Idma_Semaphore);
									set_force_i3ddma_enable(TRUE);
									if(scaler_atv_force_run_idma()) {
										up(&Force_Run_Idma_Semaphore);
										port = 0;
										timeout = 200;
										while (timeout--) {
											if(DbgSclrFlgTkr.Main_Scaler_Stop_flag || DbgSclrFlgTkr.Main_Output_Set_flag || DbgSclrFlgTkr.Main_Run_Scaler_flag) {
												rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####VO already disconnet#####\r\n");
												break;
											}
											if(get_vo_change_flag(port)) {
												break;
											}
											msleep(1);
										}
#ifdef CONFIG_I2RND_ENABLE
										//for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823
										if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_TRIGGER_RUN_MAIN)){
											vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_I3DDMA_RPC;
											//printk(KERN_EMERG"[%s][%d]vsc_i2rnd_main_rerun_stage = %d!!!!\n",__FUNCTION__, __LINE__, vsc_i2rnd_atv_main_rerun_stage);
										}
#endif
										if(timeout <= 0)
											rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "####Go ATV VO case. timeout err#####\r\n");

									} else {
										if(!DbgSclrFlgTkr.Main_Scaler_Stop_flag) {	//if not disconnected
											set_force_i3ddma_enable(FALSE);
											Scaler_Send_VoDisconnect_VOMDA(VO_VSC_SRC_HDMI, 0xfa);
										}
										up(&Force_Run_Idma_Semaphore);
									}
									//if(DbgSclrFlgTkr.Main_Scaler_Stop_flag)
										//set_force_i3ddma_enable(FALSE);
								}
								if(!DbgSclrFlgTkr.Main_Output_Set_flag && !DbgSclrFlgTkr.Main_Scaler_Stop_flag && !DbgSclrFlgTkr.Main_Run_Scaler_flag && get_force_i3ddma_enable(SLR_MAIN_DISPLAY)) {
									down(&VSC_Semaphore);
									pr_debug("\r\n####atv run scaler flow#####\r\n");

									rtk_output_connect(SLR_MAIN_DISPLAY); // different format to go normal scaler
#ifdef CONFIG_I2RND_ENABLE
									//for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823
									if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_I3DDMA_RPC)){
										vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_RERUN_MAIN_DONE;
										//printk(KERN_EMERG"[%s][%d]vsc_i2rnd_main_rerun_stage = %d!!!!\n",__FUNCTION__, __LINE__, vsc_i2rnd_atv_main_rerun_stage);
									}

									//send RPC let video fw do not write to memory after i2rnd donw @Crixus 20160808
									i2rnd_send_table_idx(I2RND_TABLE_OFF);
#endif
									up(&VSC_Semaphore);
								}
								else if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Main_Output_Set_flag) {
									DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
								}
#else
								down(&VSC_Semaphore);
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "####atv run scaler flow#####\r\n");
#ifdef CONFIG_I2RND_ENABLE
									//send RPC let video fw do not write to memory after i2rnd donw @Crixus 20160808
									i2rnd_send_table_idx(I2RND_TABLE_OFF);
#endif
								rtk_output_connect(SLR_MAIN_DISPLAY); // different format to go normal scaler
								up(&VSC_Semaphore);
#endif//#ifdef CONFIG_FORCE_RUN_I3DDMA
							} else if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Main_Output_Set_flag) {
								DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
							}
						} else {
							int smooth_toggle_ret = 0;
							if(!DbgSclrFlgTkr.Main_Output_Set_flag && !DbgSclrFlgTkr.Main_Scaler_Stop_flag && !DbgSclrFlgTkr.Main_Run_Scaler_flag){
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "####atv run smooth toggle flow#####\r\n");
								down(&VSC_Semaphore);
								Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
								//before ATV smooth toggle flow, sync start address. @Crixus 20161019
								send_memory_mapping_for_adaptive_streaming();
								panel_parameter_send_info();//before vo smooth toggle , send panel info
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

		#ifdef CONFIG_SDNR_CROP
						//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));
						smooth_toggle_ret = zoom_imd_smooth_toggle_config(VIDEO_WID_0, main_dispwin.srcx, main_dispwin.srcy,
							main_dispwin.src_wid, main_dispwin.src_height, ZOOM_DISP);
						//printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
						//printk(KERN_EMERG "0xB80252d0=%x\n", rtd_inl(0xB80252d0));
		#else

								if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(SLR_MAIN_DISPLAY))
								{
									VIDEO_RECT_T inregion_avd;
									VIDEO_RECT_T outregion_avd;
									rtk_hal_vsc_GetOutputRegion(SLR_MAIN_DISPLAY, &outregion_avd);
									Scaler_CalWindowZoominForAVD(SLR_MAIN_DISPLAY, &inregion_avd, &outregion_avd);

									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
									Scaler_DispWindowZoominForAVD(SLR_MAIN_DISPLAY, inregion_avd, outregion_avd,FALSE);
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
									//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "&&&& Scaler_DispWindowZoominForAVD()\n");
								}
								else
								{
									zoom_imd_smooth_toggle_config(VIDEO_WID_0, main_dispwin.srcx, main_dispwin.srcy,
										main_dispwin.src_wid, main_dispwin.src_height, ZOOM_DISP);

								}
		#endif
#else
								zoom_imd_smooth_toggle_config(VIDEO_WID_0, main_dispwin.srcx, main_dispwin.srcy,
									main_dispwin.src_wid, main_dispwin.src_height, ZOOM_DISP);
#endif
								up(&VSC_Semaphore);

							} else if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Main_Output_Set_flag) {
								DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
							}

							if (FALSE == CheckAVDandWebOSInfo(SLR_MAIN_DISPLAY))
							{
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "CheckAVDandWebOSInfo() fail\n");

								if (0xff == DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount)
								{
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Set DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0\n");
									DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0;
								}

								DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount++;

								if(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE && DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount < CHECK_AVD_WEBOS_INFO_TIMEOUT){
									DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
								}
								else
								{
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount timeout\n");
									DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0xff;
								}
							}
							else
							{
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "CheckAVDandWebOSInfo ok, DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount=%d\n", DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount);
								DbgSclrFlgTkr.g_ucCheckAVDandWebOSInfoCount = 0xff;
							}


							if(!DbgSclrFlgTkr.Main_Scaler_Stop_flag && !DbgSclrFlgTkr.Main_Output_Set_flag && !DbgSclrFlgTkr.Main_Run_Scaler_flag)
							{
								if(wait_atv_stable_for_bg(SLR_MAIN_DISPLAY) == FALSE)
								{
									if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Main_Output_Set_flag) {
										DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE; // Set output again, switch channel
									}

									if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)
										&&(get_AVD_Input_Source() == _SRC_TV)
										&&((vdc_LockStatus == 0)||(drvif_module_vdc_OutputStable()==FALSE)||(Scaler_AVD_GetDetectStage() != VDC_DETECT_STAGE_FINAL))
										&&(0 == drvif_video_status_reg(VDC_no_signal))){
										//rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"######[%s(line:%d)]fast zapping, flicker garbage.#####\n",__FUNCTION__, __LINE__);
										DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;
									}
								} else {
									if(!DbgSclrFlgTkr.Main_Scaler_Stop_flag) {
										Check_smooth_toggle_update_flag(SLR_MAIN_DISPLAY);

										if ((get_AVD_Input_Source() == _SRC_TV)
											&&(DbgSclrFlgTkr.g_ucVSCCheckATVChanelChange == TRUE)
											&&(Scaler_AVD_GetVDPreMode() != _MODE_UNKNOWN)
											&&(1 == vdc_LockStatus)
											&&(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)){
											//rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"######[%s(line:%d)]fast zapping, flicker garbage.#####\n",__FUNCTION__, __LINE__);
											DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE; // Set output again, switch channel
										}else{
											if(smooth_toggle_ret == ZOOM_STATE_SAMEREGION){
												msleep(100);
												rtd_printk(KERN_EMERG,TAG_NAME_VSC,"ATV auto format,same region sleep 100ms\n");
											}
											down(get_forcebg_semaphore());
											scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
											up(get_forcebg_semaphore());
										}
									}

#ifdef _PRINT_VSC_COST_TIME_AFTER_MUTE_OFF
									cost_time = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg)/90 - cost_time;
									rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####vsc cost time:%d ms after mute off atv smooth toggle####\r\n", cost_time);
#endif
								}
							} else if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Main_Output_Set_flag) {
								DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
							}
						}
					} else {
						if((DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Main_Output_Set_flag)
							DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
					}
				} else {
					if(vsc_debug_mode)
						rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n#####main ATV not ready####\r\n");

					if(DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE)
						DbgSclrFlgTkr.Main_Run_Scaler_flag = TRUE;// Set output again, switch channel
				}

			} else {
				if(!DbgSclrFlgTkr.Main_Scaler_Stop_flag) {
					down(&VSC_Semaphore);
					rtk_output_connect(SLR_MAIN_DISPLAY);
#ifdef CONFIG_I2RND_ENABLE
					//for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823
					if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_I3DDMA_RPC)){
						vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_RERUN_MAIN_DONE;
						//printk(KERN_EMERG"[%s][%d]vsc_i2rnd_main_rerun_stage = %d!!!!\n",__FUNCTION__, __LINE__, vsc_i2rnd_atv_main_rerun_stage);
					}

					//send RPC let video fw do not write to memory after i2rnd donw @Crixus 20160808
					i2rnd_send_table_idx(I2RND_TABLE_OFF);
#endif
					up(&VSC_Semaphore);
				}
			}
			if (DbgSclrFlgTkr.main_winfreeze) {
				Scaler_SetFreeze(SLR_MAIN_DISPLAY, DbgSclrFlgTkr.main_winfreeze);
			}
			DbgSclrFlgTkr.main_winfreeze=0;
		} else if ((DbgSclrFlgTkr.OuputDisplayMode == TRUE)  && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
#ifndef BRING_UP_AUTO_FLOW
			//down(&VSC_Semaphore);//Remove by Will
			rtk_check_signal(SLR_MAIN_DISPLAY);
			//up(&VSC_Semaphore);//Remove by Will
#endif
		}
		if (freezing(current))
        {
			fw_scalerip_disable_onlyip(SLR_MAIN_DISPLAY);
#ifdef CONFIG_DUAL_CHANNEL
			fw_scalerip_disable_onlyip(SLR_SUB_DISPLAY);
#endif
			try_to_freeze();
        }

#ifdef CONFIG_DUAL_CHANNEL
		if(DbgSclrFlgTkr.Sub_Reset_Mode_flag)
		{
			down(&Sub_ResetMode_Semaphore);
			DbgSclrFlgTkr.Sub_Reset_Mode_flag = FALSE;
			up(&Sub_ResetMode_Semaphore);
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n#####func:%s DO Sub reset mode#####\r\n", __FUNCTION__);
			down(&VSC_Semaphore);
			drvif_mode_resetmode(SLR_SUB_DISPLAY);//Reset Mode for sub
			up(&VSC_Semaphore);
		}

		if(Get_DisplayMode_Src(SLR_SUB_DISPLAY) != VSC_INPUTSRC_MAXN)
		{
			msleep(10);
			if (DbgSclrFlgTkr.Sub_Run_Scaler_flag && (DbgSclrFlgTkr.Sub_Scaler_Stop_flag == FALSE) && (DbgSclrFlgTkr.Sub_Reset_Mode_flag == FALSE)//wait vsc close reset mode ready
#ifdef CONFIG_I2RND_ENABLE
				&& (vsc_i2rnd_sub_stage == I2RND_STAGE_DISABLE)
				//for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823
				&& ((Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_AVD)/* && (get_AVD_Input_Source() == _SRC_TV)*/ && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_RERUN_MAIN_DONE))
#endif
				) {

				VIDEO_RECT_T tOutRegion, tInputRegion;
				set_current_scaler_source_num(SLR_SUB_DISPLAY);//record current vsc source num
				down(&SetSubOutPutRegion_Semaphore);
				DbgSclrFlgTkr.Sub_Run_Scaler_flag = FALSE;
				DbgSclrFlgTkr.Sub_Output_Set_flag = FALSE;

#if 0
#ifdef CONFIG_I2RND_ENABLE
				if(Scaler_I2rnd_get_enable() == _ENABLE){
					Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);
					printk(KERN_EMERG"[%s]I2RND_SUB_S1_TABLE!!!!\n",__FUNCTION__);
				}
#endif
#endif

				set_input_for_vgip(SLR_SUB_DISPLAY, sub_input_size.srcx, sub_input_size.srcy, sub_input_size.src_wid, sub_input_size.src_height);
				Scaler_SubDispWindowSet(sub_dispwin);

				rtk_hal_vsc_GetInputRegion(SLR_SUB_DISPLAY, &tInputRegion);
				rtk_hal_vsc_GetOutputRegion(SLR_SUB_DISPLAY, &tOutRegion);

				up(&SetSubOutPutRegion_Semaphore);
				srctype = Get_DisplayMode_Src(SLR_SUB_DISPLAY);
				rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "####Sub path VSC_Src:%d#####\r\n", srctype);

				if((srctype == VSC_INPUTSRC_AVD) && (get_AVD_Input_Source() == _SRC_TV))
				{
					if((Scaler_AVD_GetDetectStage() == VDC_DETECT_STAGE_FINAL) || (0 == vdc_LockStatus))
					{//If APVR, need to wait main ready
						if(!DbgSclrFlgTkr.Sub_Output_Set_flag && !DbgSclrFlgTkr.Sub_Scaler_Stop_flag && !DbgSclrFlgTkr.Sub_Run_Scaler_flag) {

							#if 0
							rtd_printk(KERN_EMERG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
							rtd_printk(KERN_EMERG, TAG_NAME_VSC, "rtk_hal_vsc_GetInputRegion InputRegion_x=%d, y=%d, w=%d, h=%d\n", tInputRegion.x, tInputRegion.y, tInputRegion.w, tInputRegion.h);
							rtd_printk(KERN_EMERG, TAG_NAME_VSC, "rtk_hal_vsc_GetOutputRegion OutputRegion_x=%d, y=%d, w=%d, h=%d\n", tOutRegion.x, tOutRegion.y, tOutRegion.w, tOutRegion.h);

							rtd_printk(KERN_EMERG, TAG_NAME_VSC, "Pre InputRegion_x=%d, y=%d, w=%d, h=%d\n", DbgSclrFlgTkr.Sub_ATV_InputRegion_x_pre, DbgSclrFlgTkr.Sub_ATV_InputRegion_y_pre, DbgSclrFlgTkr.Sub_ATV_InputRegion_w_pre, DbgSclrFlgTkr.Sub_ATV_InputRegion_h_pre);
							rtd_printk(KERN_EMERG, TAG_NAME_VSC, "Pre OutputRegion_x=%d, y=%d, w=%d, h=%d\n", DbgSclrFlgTkr.Sub_ATV_OutputRegion_x_pre, DbgSclrFlgTkr.Sub_ATV_OutputRegion_y_pre, DbgSclrFlgTkr.Sub_ATV_OutputRegion_w_pre, DbgSclrFlgTkr.Sub_ATV_OutputRegion_h_pre);

							rtd_printk(KERN_EMERG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag=%x\n", DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag);
							rtd_printk(KERN_EMERG, TAG_NAME_VSC, "CompareATVInputOutputRegion()=%x\n", CompareATVInputOutputRegion(SLR_SUB_DISPLAY, &tOutRegion, &tInputRegion));
							#endif

							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag=%x\n", DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag);
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "CompareATVInputOutputRegion()=%x\n", CompareATVInputOutputRegion(SLR_SUB_DISPLAY, &tOutRegion, &tInputRegion));


							if (DbgSclrFlgTkr.Sub_ATV_Go_Smooth_Toggle_flag && CompareATVInputOutputRegion(SLR_SUB_DISPLAY, &tOutRegion, &tInputRegion))
							{
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "vsc_scaler_task ATV sub path don't run scaler flow\n");
								//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "vsc_scaler_task ATV sub path don't run scaler flow\n");
							}
							else
							{
								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Set ATV output/input pre\n");
								//rtd_printk(KERN_EMERG, TAG_NAME_VSC, "Set ATV output/input pre\n");

								DbgSclrFlgTkr.Sub_ATV_OutputRegion_x_pre = tOutRegion.x;
								DbgSclrFlgTkr.Sub_ATV_OutputRegion_y_pre = tOutRegion.y;
								DbgSclrFlgTkr.Sub_ATV_OutputRegion_w_pre = tOutRegion.w;
								DbgSclrFlgTkr.Sub_ATV_OutputRegion_h_pre = tOutRegion.h;

								DbgSclrFlgTkr.Sub_ATV_InputRegion_x_pre = tInputRegion.x;
								DbgSclrFlgTkr.Sub_ATV_InputRegion_y_pre = tInputRegion.y;
								DbgSclrFlgTkr.Sub_ATV_InputRegion_w_pre = tInputRegion.w;
								DbgSclrFlgTkr.Sub_ATV_InputRegion_h_pre = tInputRegion.h;


								rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####atv run sub scaler flow#####\r\n");
								down(&VSC_Semaphore);
								rtk_output_connect(SLR_SUB_DISPLAY); // different format to go normal scaler
								Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
								up(&VSC_Semaphore);
#ifdef CONFIG_I2RND_ENABLE
								//for APVR and ATV channel changing stage, avoid the race condition issue. @Crixus 20160823
								if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_atv_main_rerun_stage == I2RND_ATV_STAGE_RERUN_MAIN_DONE)){
									vsc_i2rnd_atv_main_rerun_stage = I2RND_ATV_STAGE_DISABLE;
								}
#endif
							}
						} else if((DbgSclrFlgTkr.Sub_Scaler_Stop_flag == FALSE) && DbgSclrFlgTkr.Sub_Output_Set_flag) {
							DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;// Set output again, switch channel
						}
					} else {
						if(vsc_debug_mode)
							rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####sub ATV not ready#####\r\n");

						if(DbgSclrFlgTkr.Sub_Scaler_Stop_flag == FALSE)
							DbgSclrFlgTkr.Sub_Run_Scaler_flag = TRUE;// Set output again, switch channel
					}
				} else {
					if(!DbgSclrFlgTkr.Sub_Scaler_Stop_flag) {
						down(&VSC_Semaphore);
						rtk_output_connect(SLR_SUB_DISPLAY);
						Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
						up(&VSC_Semaphore);
#if 0
#ifdef CONFIG_I2RND_ENABLE
						//I2rnd sub=>vo RPC
						if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DETECT_SOURCE)){
							vsc_i2rnd_sub_stage = I2RND_STAGE_SUB_VO_RPC;
							printk(KERN_EMERG"[I2RND]@@@@@@@@@@@@I2RND_STAGE_SUB_VO_RPC\n");
							Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);
							i2rnd_send_table_idx(I2RND_SUB_S1_TABLE);
							drvif_scaler_i2rnd_vodma_setting(SLR_SUB_DISPLAY, srctype);
							drivf_Sub_I2rnd_SetupVODMA();
							//i2rnd_debug();
							printk(KERN_EMERG"[I2RND]@@@@@@@@@@@@I2RND_STAGE_SUB_VO_RPC OK!!!!!\n");
						}
#endif
#endif
					}
				}
			} else if ((DbgSclrFlgTkr.Sub_OuputDisplayMode == TRUE) && (Get_Live_zoom_mode() == LIVE_ZOOM_OFF )
				&& (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
#ifndef BRING_UP_AUTO_FLOW

				//down(&VSC_Semaphore);//Remove by Will
				rtk_check_signal(SLR_SUB_DISPLAY);
				//up(&VSC_Semaphore);//Remove by Will
#endif
			}
		}
		if (freezing(current))
       	{
			fw_scalerip_disable_onlyip(SLR_MAIN_DISPLAY);
			fw_scalerip_disable_onlyip(SLR_SUB_DISPLAY);
			try_to_freeze();
        }
#endif
		if (kthread_should_stop()) {
         	break;
      	}
#ifdef MEMC_DYNAMIC_ONOFF
		Scaler_MEMC_Dynamic_OnOff();
#endif

    }
    rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####vsc_scaler_tsk: exit...####\n");
    do_exit(0);
    return 0;
}

static void create_vsc_tsk(void)
{
	int err;
	if (vsc_tsk_running_flag == FALSE) {
		p_vsc_tsk = kthread_create(vsc_scaler_tsk, NULL, "vsc_tsk");

	    if (p_vsc_tsk) {
			wake_up_process(p_vsc_tsk);
			vsc_tsk_running_flag = TRUE;
	    } else {
	    	err = PTR_ERR(p_vsc_tsk);
	    	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Unable to start create_vsc_tsk (err_id = %d)./n", err);
	    }
	}
}

static void delete_vsc_tsk(void)
{
	int ret;
	if (vsc_tsk_running_flag) {
 		ret = kthread_stop(p_vsc_tsk);
 		if (!ret) {
 			p_vsc_tsk = NULL;
 			vsc_tsk_running_flag = FALSE;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "vsc_scaler_tsk thread stopped\n");
 		}
	}
}

#ifdef USE_FORCEBG_TASK
static bool forcebg_tsk_running_flag = FALSE;//Record forcebg_scaler_tsk status. True: Task is running
static struct task_struct *p_forcebg_tsk = NULL;


static int video_forcebg_tsk(void *p)
{
    struct cpumask vsc_cpumask;
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,  "video_forcebg_tsk()\n");
    cpumask_clear(&vsc_cpumask);
    cpumask_set_cpu(0, &vsc_cpumask); // run task in core 0
    cpumask_set_cpu(2, &vsc_cpumask); // run task in core 2
    cpumask_set_cpu(3, &vsc_cpumask); // run task in core 3
    sched_setaffinity(0, &vsc_cpumask);
	current->flags &= ~PF_NOFREEZE;
	while (1)
	{
#ifdef CONFIG_DUAL_CHANNEL
		wait_event_timeout(FORCEBG_WAIT_QUEUE, DbgSclrFlgTkr.Main_Request_ForceBG_ctrl || DbgSclrFlgTkr.Sub_Request_ForceBG_ctrl, 10);//Timeout is 100ms
#else
		wait_event_timeout(FORCEBG_WAIT_QUEUE, DbgSclrFlgTkr.Main_Request_ForceBG_ctrl, 10);//Timeout is 100ms
#endif

#ifdef CONFIG_DUAL_CHANNEL
		if(DbgSclrFlgTkr.Main_Request_ForceBG_ctrl || DbgSclrFlgTkr.Sub_Request_ForceBG_ctrl)
#else
		if(DbgSclrFlgTkr.Main_Request_ForceBG_ctrl)
#endif
		{
			if(DbgSclrFlgTkr.Main_Request_ForceBG_ctrl) {
				spin_lock(&Main_Request_ForceBG_ctrl_Spinlock);
				DbgSclrFlgTkr.Main_Request_ForceBG_ctrl = FALSE;
				spin_unlock(&Main_Request_ForceBG_ctrl_Spinlock);
				down(get_forcebg_semaphore());
				if(Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY))
				{
#if 0/*qiangzhou marked, becasue webos will set winblank on when open livezoom*/
					if (Get_Live_zoom_mode() == LIVE_ZOOM_SUB ) {
						scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);/*Auto BG*/
					}
#endif
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, TRUE);
				}
				else
				{
					scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
				}
				up(get_forcebg_semaphore());
			}
#ifdef CONFIG_DUAL_CHANNEL
			if(DbgSclrFlgTkr.Sub_Request_ForceBG_ctrl) {
				spin_lock(&Sub_Request_ForceBG_ctrl_Spinlock);
				DbgSclrFlgTkr.Sub_Request_ForceBG_ctrl = FALSE;
				spin_unlock(&Sub_Request_ForceBG_ctrl_Spinlock);
				down(get_forcebg_semaphore());
				if(Check_AP_Set_Enable_ForceBG(SLR_SUB_DISPLAY))
				{
					scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, TRUE);
				}
				else
				{
					scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
				}
				up(get_forcebg_semaphore());
			}

#endif
		}
		if (freezing(current))
		{
			try_to_freeze();
		}
		if (kthread_should_stop()) {
			break;
		}
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,  "\r\n####video_forcebg_tsk: exit...####\n");
	do_exit(0);
	return 0;
}



static void create_forcebg_tsk(void)
{
	int err;
	if (forcebg_tsk_running_flag == FALSE) {
		p_forcebg_tsk = kthread_create(video_forcebg_tsk, NULL, "forcebg_tsk");

	    if (p_forcebg_tsk) {
			wake_up_process(p_forcebg_tsk);
			forcebg_tsk_running_flag = TRUE;
	    } else {
	    	err = PTR_ERR(p_forcebg_tsk);
	    	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Unable to start video_forcebg_tsk (err_id = %d)./n", err);
	    }
	}
}

static void delete_forcebg_tsk(void)
{
	int ret;
	if (forcebg_tsk_running_flag) {
 		ret = kthread_stop(p_forcebg_tsk);
 		if (!ret) {
 			p_forcebg_tsk = NULL;
 			forcebg_tsk_running_flag = FALSE;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "video_forcebg_tsk thread stopped\n");
 		}
	}
}
#endif

#define FLL_UZUDTG_VSYNC_LINE_DELAY 63
#define FLL_UZUDTG_WAIT_LINE_RANGE 20
#define FLL_LOWER_DOUNDARY_PERCENT 22//lower boundary is total line * 2.2%
#define FLL_UPPER_DOUNDARY_PERCENT 44 //upper boundary is total line * 4.4%

static bool fix_lastline_tsk_running_flag = FALSE;//Record fixlastline_scaler_tsk status. True: Task is running
static struct task_struct *p_fix_lastline_tsk = NULL;
extern void drvif_scaler_set_frc2fsync_vtotal_protect_on_without_den_shift(void);
extern void drvif_scaler_set_fixlastline_vtotal_speedup_protect_on(void);
extern void drvif_scaler_set_frc2fsync_vtotal_protect_off(void);
extern void drvif_scaler_set_frc2fsync_recovery_vtotal(unsigned int u32_vtotal);

unsigned char vsc_decide_fixlastline_speedup_enable(void)
{
	unsigned char b_enable = 1;

	if(drvif_scaler_get_display_mode() == DISPLAY_MODE_FRAME_SYNC){
		b_enable = 0;
	}
	//if(Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_REMOVE_RATIO) != 1){
	//	b_enable = 0;
	//}
	return b_enable;
}

static int fixlast_line_tsk(void *p)
{
    struct cpumask vsc_cpumask;
	static UINT8 checkStableCnt=0;
	unsigned int count2 = 0x3fffff;
	unsigned int ch1_line_cnt_lower = 0;
	unsigned int ch1_line_cnt_upper = 0;
	ppoverlay_dtg_frame_cnt1_RBUS dtg_frame_cnt1_reg;
	ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_reg;
	vgip_vgip_chn1_lc_RBUS vgip_chn1_lc_reg;
	unsigned int vtotal = 0;
	unsigned int uzudtg_line_lower = FLL_UZUDTG_VSYNC_LINE_DELAY;
	unsigned int uzudtg_line_upper = FLL_UZUDTG_VSYNC_LINE_DELAY + FLL_UZUDTG_WAIT_LINE_RANGE;

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "fixlast_line_tsk()\n");
/*
    cpumask_clear(&vsc_cpumask);
    cpumask_set_cpu(0, &vsc_cpumask); // run task in core 0
    cpumask_set_cpu(2, &vsc_cpumask); // run task in core 2
    cpumask_set_cpu(3, &vsc_cpumask); // run task in core 3
    sched_setaffinity(0, &vsc_cpumask);
*/
	current->flags &= ~PF_NOFREEZE;
	while (1)
	{
#if 1
		down(get_scaler_fll_running_semaphore());

		if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)&&(get_scaler_stop_flag(SLR_MAIN_DISPLAY)==FALSE)){
			if(modestate_get_fll_running_flag()){
				if(checkStableCnt> 2){
					if((modestate_decide_display_timing() == DISPLAY_MODE_NEW_FLL_MODE) &&
						(drvif_scaler_get_display_mode() != DISPLAY_MODE_NEW_FLL_MODE)){
						down(&VSC_Semaphore);
						Scaler_SetCurrentDispInfo(SLR_MAIN_DISPLAY);
						vtotal = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_LEN);
						ch1_line_cnt_lower = vtotal - (vtotal * FLL_LOWER_DOUNDARY_PERCENT / 1000);//lower boundary is total line * 2.2%
						ch1_line_cnt_upper = (vtotal * FLL_UPPER_DOUNDARY_PERCENT / 1000);//upper boundary is total line's 4.4%
						//printk(KERN_EMERG"\n ch1_line_cnt_lower = %d, ch1_line_cnt_upper = %d\n", ch1_line_cnt_lower, ch1_line_cnt_upper);

						if((DisplayModeInputInfo.type == VSC_INPUTSRC_VDEC)||(DisplayModeInputInfo.type == VSC_INPUTSRC_JPEG)){
							//change to FLL
							rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "### set fll new mode 1.###\n");
							framesync_lastlinefinetune_at_new_mode();
							modestate_set_display_timing(0);
							modestate_set_fll_running_flag(FALSE);
							checkStableCnt=0;
						}
						else
						{
							count2 = 0x3fffff;
							/*speedup*/
							if(vsc_decide_fixlastline_speedup_enable() == TRUE){
								ppoverlay_dv_total_RBUS dv_total_reg;
								fwif_color_safe_od_enable(0);
								dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
								drvif_scaler_set_frc2fsync_recovery_vtotal(dv_total_reg.dv_total+1);
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"fll set recovery vtotal = %x", dv_total_reg.dv_total+1);
								drvif_scaler_set_fixlastline_vtotal_speedup_protect_on();
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"func=%s, line=%d\n", __FUNCTION__, __LINE__);
							}
							while(count2){
								new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
								vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
								/*wait uzu dtg Vsync and wait the vgip line cnt*/
								if(((new_meas1_linecnt_real_reg.uzudtg_line_cnt_rt >= uzudtg_line_lower) && (new_meas1_linecnt_real_reg.uzudtg_line_cnt_rt < uzudtg_line_upper))
								&& ((vgip_chn1_lc_reg.ch1_line_cnt >= ch1_line_cnt_lower) || (vgip_chn1_lc_reg.ch1_line_cnt <= ch1_line_cnt_upper))){
									/*recover*/
									if(vsc_decide_fixlastline_speedup_enable() == TRUE){
										drvif_scaler_set_frc2fsync_vtotal_protect_off();
										fwif_color_safe_od_enable(1);
									}
									framesync_lastlinefinetune_at_new_mode();
									modestate_set_display_timing(0);
									modestate_set_fll_running_flag(FALSE);
									checkStableCnt=0;
									//change to FLL
									rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "### set fll new mode 1.###\n");

									//printk(KERN_EMERG"\n new_meas1_linecnt_real_reg.uzudtg_line_cnt_rt = %d\n", new_meas1_linecnt_real_reg.uzudtg_line_cnt_rt);
									//printk(KERN_EMERG"\n vgip_chn1_lc_reg.ch1_line_cnt = %d\n", vgip_chn1_lc_reg.ch1_line_cnt);
									break;
								}

								//check game mode status to aviod mute on time too long @Crixus 20161219
								if(drv_memory_get_game_mode() == _ENABLE){
									rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "[FLL]game mode enable break\n");
									//recovery
									if(vsc_decide_fixlastline_speedup_enable() == TRUE){
										drvif_scaler_set_frc2fsync_vtotal_protect_off();
										fwif_color_safe_od_enable(1);
									}
									modestate_set_fll_running_flag(FALSE);
									break;
								}

								// DC off avoids this thread to lock vsc semaphore
								if(get_scaler_stop_flag(SLR_MAIN_DISPLAY) == TRUE){
									rtd_printk(KERN_NOTICE, TAG_NAME_VSC,"FUNC:%s, break due to scaler stop\n", __FUNCTION__);
									if(vsc_decide_fixlastline_speedup_enable() == TRUE){
										drvif_scaler_set_frc2fsync_vtotal_protect_off();
										fwif_color_safe_od_enable(1);
									}
									modestate_set_fll_running_flag(FALSE);
									break;
								}
								count2--;
							}
							//printk(KERN_EMERG"count2 = %d\n", count2);

							if(count2 == 0){
								rtd_printk(KERN_NOTICE, TAG_NAME_VSC, "count timeout !!!\n");
								//printk(KERN_EMERG"count timeout !!!\n");
								if(vsc_decide_fixlastline_speedup_enable() == TRUE){
									drvif_scaler_set_frc2fsync_vtotal_protect_off();
									fwif_color_safe_od_enable(1);
								}
							}
						}
						up(&VSC_Semaphore);
					}
				}
				else{
					checkStableCnt++;
				}
			}else{
				down(&VSC_Semaphore);
				if(vbe_disp_get_adaptivestream_fs_mode() == 1){
					if ((drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC) &&
						(Get_DISPLAY_PANEL_TYPE() != P_LVDS_TO_HDMI)) {
						pr_emerg("[fll]drvif_scaler_get_display_mode=%d\n", drvif_scaler_get_display_mode());
						fwif_color_safe_od_enable(0);
						drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
						fwif_color_safe_od_enable(1);
					}
				}
				if(Get_DISPLAY_PANEL_OLED_TYPE()==TRUE){
					if((drv_memory_get_game_mode_dynamic() == _ENABLE)&&(drv_memory_get_game_mode() == TRUE)){
						if(drvif_scaler_get_display_mode() != DISPLAY_MODE_FRAME_SYNC){
							fwif_color_safe_od_enable(0);
							drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
							fwif_color_safe_od_enable(1);
						}
					}
				}
				up(&VSC_Semaphore);
				checkStableCnt = 0;
			}
		}else{
			checkStableCnt = 0;
		}
		up(get_scaler_fll_running_semaphore());
#endif

		if (freezing(current))
		{
			try_to_freeze();
		}
		if (kthread_should_stop()) {
			break;
		}
		msleep(10);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,  "\r\n####fixlast_line_tsk: exit...####\n");
	do_exit(0);
	return 0;
}

static void create_fixlast_line_tsk(void)
{
	int err;
	if (fix_lastline_tsk_running_flag == FALSE) {
		p_fix_lastline_tsk = kthread_create(fixlast_line_tsk, NULL, "fix_lastline_tsk");

	    if (p_fix_lastline_tsk) {
			wake_up_process(p_fix_lastline_tsk);
			fix_lastline_tsk_running_flag = TRUE;
	    } else {
	    	err = PTR_ERR(p_fix_lastline_tsk);
	    	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Unable to start fixlast_line_tsk (err_id = %d)./n", err);
	    }
	}
}

static void delete_fix_lastline_tsk(void)
{
	int ret;
	if (fix_lastline_tsk_running_flag) {
 		ret = kthread_stop(p_fix_lastline_tsk);
 		if (!ret) {
 			p_fix_lastline_tsk = NULL;
 			fix_lastline_tsk_running_flag = FALSE;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "fixlast_line_tsk thread stopped\n");
 		}
	}
}


static bool game_mode_unmute_tsk_running_flag = FALSE;
static struct task_struct *p_game_mode_unmute_tsk = NULL;

static int game_mode_unmute_tsk(void *p)
{
	struct cpumask vsc_cpumask;
	static UINT8 checkStableCnt = 0;
	static UINT32 game_mode_cmd_pre = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "game_mode_unmute_tsk()\n");
/*
    cpumask_clear(&vsc_cpumask);
    cpumask_set_cpu(0, &vsc_cpumask); // run task in core 0
    cpumask_set_cpu(2, &vsc_cpumask); // run task in core 2
    cpumask_set_cpu(3, &vsc_cpumask); // run task in core 3
    sched_setaffinity(0, &vsc_cpumask);
*/
	current->flags &= ~PF_NOFREEZE;
	while (1)
	{
		//Game mode cmd checking flow @Cixus 20161204
		if ((Get_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_GameMode) == TRUE)
			&& (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)) {
			down(&GameMode_Check_Semaphore);
			if(checkStableCnt < 30){
				if(game_mode_cmd_pre != game_mode_cmd_check){
					checkStableCnt = 0;
					game_mode_cmd_pre = game_mode_cmd_check;
					//printk(KERN_EMERG"[crixus]game mode cmd again!! reset!! game_mode_cmd_pre = %d\n", game_mode_cmd_pre);
				}
				else{
					checkStableCnt++;
				}
				//printk(KERN_EMERG"[crixus]checkStableCnt = %d\n", checkStableCnt);
			}
			else{

				if((DbgSclrFlgTkr.game_mode_dynamic_flag == FALSE) && (game_mode_cmd_pre == game_mode_cmd_check)){
					game_mode_cmd_check = 0;
					game_mode_cmd_pre = 0;
					checkStableCnt = 0;
					set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_GameMode, FALSE);
					/*K3LG-1445:sync crixus,willlin,qiangzhou,when gamemode re run scaler,open forcebg need check scaler status active*/
					if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
						down(get_forcebg_semaphore());
						scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, FALSE);
						up(get_forcebg_semaphore());
					}
					//printk(KERN_EMERG"[crixus]game mode unmute!!\n");
				}
				else{
					if(game_mode_cmd_pre != game_mode_cmd_check){
						checkStableCnt = 0;
						//printk(KERN_EMERG"[crixus]2. game mode cmd again!! reset!! game_mode_cmd_pre = %d\n", game_mode_cmd_pre);
					}
					//printk(KERN_EMERG"[crixus]wait game mode scaler done!!\n");
				}

			}
			up(&GameMode_Check_Semaphore);
		}

		if (freezing(current))
		{
			try_to_freeze();
		}
		if (kthread_should_stop()) {
			break;
		}
		msleep(10);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,  "\r\n####game_mode_unmute_tsk: exit...####\n");
	do_exit(0);
	return 0;
}

static void create_game_mode_unmute_tsk(void)
{
	int err;
	if (game_mode_unmute_tsk_running_flag == FALSE) {
		p_game_mode_unmute_tsk = kthread_create(game_mode_unmute_tsk, NULL, "game_mode_unmute_tsk");

	    if (p_game_mode_unmute_tsk) {
			wake_up_process(p_game_mode_unmute_tsk);
			game_mode_unmute_tsk_running_flag = TRUE;
	    } else {
	    	err = PTR_ERR(p_game_mode_unmute_tsk);
	    	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Unable to start game_mode_unmute_tsk (err_id = %d)./n", err);
	    }
	}
}

static void delete_game_mode_unmute_tsk(void)
{
	int ret;
	if (game_mode_unmute_tsk_running_flag) {
 		ret = kthread_stop(p_game_mode_unmute_tsk);
 		if (!ret) {
 			p_game_mode_unmute_tsk = NULL;
 			game_mode_unmute_tsk_running_flag = FALSE;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "game_mode_unmute_tsk thread stopped\n");
 		}
	}
}


#ifdef BRING_UP_AUTO_FLOW/*This is only for bring up use demoap*/
static bool bring_up_vsc_running_flag = FALSE;
static struct task_struct *p_bring_up_vsc_tsk = NULL;

unsigned char rtk_bring_up_connect(void)
{/*This is for source check signal stable or not. Must be _MODE_STATE_ACTIVE*/
	VIDEO_RECT_T  inregion = {0, 0, 0, 0};
	VIDEO_RECT_T outregion = {0, 0, 0, 0};
	static int flag = 0;
	if(flag == 0)
	{
#ifdef CONFIG_DUAL_CHANNEL
		flag = 1;
#endif
		if(DisplayModeInputInfo.type == VSC_INPUTSRC_MAXN)
		{
			return false;
		}
		if(DisplayModeInputInfo.type == VSC_INPUTSRC_VDEC || DisplayModeInputInfo.type == VSC_INPUTSRC_JPEG)
		{
			down(get_vo_infosemaphore());
			if(get_vo_change_flag(DisplayModeInputInfo.resourceIndex))
			{
				Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE,  _MODE_STATE_SEARCH);
			}
			else
			{
				up(get_vo_infosemaphore());
				return false;
			}
			up(get_vo_infosemaphore());
		}

		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_SEARCH)
		{
			return false;
		}
		inregion.h = 4096;/*default*/
		inregion.w = 4096;/*default*/
		outregion.w = _DISP_WID;
		outregion.h = _DISP_LEN;
		rtk_hal_vsc_SetInputRegion(VIDEO_WID_0, inregion);
		return(rtk_hal_vsc_SetOutputRegion(VIDEO_WID_0, outregion, 0, 0));
	}
#ifdef CONFIG_DUAL_CHANNEL
	else
	{
		flag = 0;
		if(Sub_DisplayModeInputInfo.type == VSC_INPUTSRC_MAXN)
		{
			return false;
		}
		if(Sub_DisplayModeInputInfo.type == VSC_INPUTSRC_VDEC || Sub_DisplayModeInputInfo.type == VSC_INPUTSRC_JPEG)
		{
			return false;
		}

		if(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_SEARCH)
		{
			return false;
		}
		inregion.h = 4096;/*default*/
		inregion.w = 4096;/*default*/
		outregion.w = _DISP_WID/6;
		outregion.h = _DISP_LEN/6;
		rtk_hal_vsc_SetInputRegion(VIDEO_WID_1, inregion);
		return(rtk_hal_vsc_SetOutputRegion(VIDEO_WID_1, outregion, 0, 0));
	}
#endif
}

static int bring_up_vsc_tsk(void *p)
{/* only for bring up test */
    rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "bring_up_vsc_tsk()\n");
	current->flags &= ~PF_NOFREEZE;
    while (1)
    {
    	msleep(100);
		if (DbgSclrFlgTkr.OuputDisplayMode == TRUE)
			rtk_bring_up_connect();

		if (freezing(current))
        {
			try_to_freeze();
        }
		if (kthread_should_stop()) {
         	break;
      	}
    }

    rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####bring_up_vsc_tsk: exit...####\n");
    do_exit(0);
    return 0;
}

static void create_bring_up_vsc_tsk(void)
{
	int err;
	if (bring_up_vsc_running_flag == FALSE) {
		p_bring_up_vsc_tsk = kthread_create(bring_up_vsc_tsk, NULL, "bring_up_vsc_tsk");

	    if (p_bring_up_vsc_tsk) {
			wake_up_process(p_bring_up_vsc_tsk);
			bring_up_vsc_running_flag = TRUE;
	    } else {
	    	err = PTR_ERR(p_bring_up_vsc_tsk);
	    	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Unable to start bring_up_vsc_tsk (err_id = %d)./n", err);
	    }
	}
}

static void delete_bring_up_vsc_tsk(void)
{
	int ret;
	if (bring_up_vsc_running_flag) {
 		ret = kthread_stop(p_bring_up_vsc_tsk);
 		if (!ret) {
 			p_bring_up_vsc_tsk = NULL;
 			bring_up_vsc_running_flag = FALSE;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "bring_up_vsc_tsk thread stopped\n");
 		}
	}
}
#endif


struct file_operations vsc_fops= {
	.owner =    THIS_MODULE,
	.open  =    vsc_open,
	.release =  vsc_release,
	.read  =    vsc_read,
	.write = 	vsc_write,
	.unlocked_ioctl =    vsc_ioctl,
};

#ifdef CONFIG_DUMP_REGISTER
static bool dump_register_vsc_running_flag = FALSE;
static struct task_struct *p_dump_register_vsc_tsk = NULL;
extern void register_dump_test(void);
extern void register_dump_data_to_file(void);
static void dump_register_vsc_tsk(void *p)
{
    rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "dump_register_vsc_tsk()\n");
	current->flags &= ~PF_NOFREEZE;
    while (1)
    {
		msleep(200);
	//pr_emerg("dump_register_vsc_tsk\n");
#ifdef CONFIG_DUMP_REGISTER
		register_dump_test();
		register_dump_data_to_file();
		//pr_emerg("test_vsc_tsk********\n");
		//pr_emerg("test_vsc_tsk********\n");
#endif

		if (freezing(current))
        {
			try_to_freeze();
        }
		if (kthread_should_stop()) {
			break;
		}
	}

    rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\r\n####dump_register_vsc_tsk: exit...####\n");
    do_exit(0);
    return 0;
}
static void create_dump_register_vsc_tsk(void)
{
	int err;
	if (dump_register_vsc_running_flag == FALSE) {
		p_dump_register_vsc_tsk = kthread_create(dump_register_vsc_tsk, NULL, "dump_register_vsc_tsk");

	    if (p_dump_register_vsc_tsk) {
			wake_up_process(p_dump_register_vsc_tsk);
			dump_register_vsc_running_flag = TRUE;
	    } else {
			err = PTR_ERR(p_dump_register_vsc_tsk);
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "Unable to start dump_register_vsc_tsk (err_id = %d)./n", err);
	    }
	}
}
static void delete_dump_register_vsc_tsk(void)
{
	int ret;
	if (dump_register_vsc_running_flag) {
		ret = kthread_stop(p_dump_register_vsc_tsk);
		if (!ret) {
			p_dump_register_vsc_tsk = NULL;
			dump_register_vsc_running_flag = FALSE;
			rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "dump_register_vsc_tsk thread stopped\n");
		}
	}
}
#endif

int vsc_major   = VSC_MAJOR;
int vsc_minor   = 0 ;
int vsc_nr_devs = VSC_NR_DEVS;

module_param(vsc_major, int, S_IRUGO);
module_param(vsc_minor, int, S_IRUGO);
module_param(vsc_nr_devs, int, S_IRUGO);


static struct class *vsc_class = NULL;
static struct platform_device *vsc_platform_devs = NULL;

#ifdef CONFIG_PM
static const struct dev_pm_ops vsc_pm_ops =
{
	.suspend    = vsc_suspend,
	.resume     = vsc_resume,
#ifdef CONFIG_HIBERNATION
	.freeze 	= vsc_suspend,
	.thaw		= vsc_resume_std,
	.poweroff	= vsc_suspend,
	.restore	= vsc_resume_std,
#endif

};
#endif

static struct platform_driver vsc_device_driver = {
    .driver = {
        .name       = VSC_DEVICE_NAME,
        .bus        = &platform_bus_type,
#ifdef CONFIG_PM
	.pm 		= &vsc_pm_ops,
#endif

    },
} ;


static char *vsc_devnode(struct device *dev, mode_t *mode)
{
	*mode = 0666;
	return NULL;
}


static void sb2_di_debug_info(void)
{
	dcmt_trap_info trap_info;
	//check trash module
	if(!isDcmtTrap("TVSB2_DIW"))  //"SB3_MD_SCPU"?trap ip,ip?????rtk_dc_mt.c??module_info[]
	{
		printk(KERN_ERR "not TVSB2_DIW module!\n");
		return;
	}

	get_dcmt_trap_info(&trap_info);  //get dcmt trap information (include trash_addr,module_id,rw_type)
	printk(KERN_ERR "TVSB2_DIW module trashed somewhere!\n");
	printk(KERN_ERR "0xb8024000=%x\n", IoReg_Read32(0xb8024000));
	printk(KERN_ERR "0xb8024538=%x\n", IoReg_Read32(0xb8024538));
	unsigned int i = 0;
	for (i = 0xb8024400; i <=0xb8024440; i=i+4)
	{
		printk(KERN_ERR "%x=%x\n", i, IoReg_Read32(i));
	}
	return;
}



static void sb2_m_cap_debug_info(void)
{
	dcmt_trap_info trap_info;
	//check trash module
	if(!isDcmtTrap("TVSB2_M_CAP"))  //"SB3_MD_SCPU"?trap ip,ip?????rtk_dc_mt.c??module_info[]
	{
		printk(KERN_ERR "not TVSB2_M_CAP module!\n");
		return;
	}

	get_dcmt_trap_info(&trap_info);  //get dcmt trap information (include trash_addr,module_id,rw_type)
	printk(KERN_ERR "TVSB2_M_CAP module trashed somewhere!\n");

	unsigned int i = 0;
	//m-cap address and control
	for (i = 0xb8027200; i <=0xb8027228; i=i+4)
	{
		printk(KERN_ERR "%x=%x\n", i, IoReg_Read32(i));
	}

	// Double buffer
	printk(KERN_ERR "Double buffer 0xb802726c=%x\n", IoReg_Read32(0xb802726c));

	// Boundary down limit
	printk(KERN_ERR "Boundary down limit 0xb8027278=%x\n", IoReg_Read32(0xb8027278));
	// Boundary up limit
	printk(KERN_ERR "Boundary up limit 0xb802727c=%x\n", IoReg_Read32(0xb802727c));

	// Boundary status
	printk(KERN_ERR "Boundary status 0xb8027280=%x\n", IoReg_Read32(0xb8027280));

	return;
}

/******************DCMT declare callback func******************/
DCMT_DEBUG_INFO_DECLARE(sb2_di_mdscpu, sb2_di_debug_info);

/******************DCMT declare callback func******************/
DCMT_DEBUG_INFO_DECLARE(sb2_m_cap_mdscpu, sb2_m_cap_debug_info);


int vsc_init_module(void)
{
	int result;
  	int devno;
	dev_t dev = 0;


	/******************DCMT register callback func in init flow******************/
	DCMT_DEBUG_INFO_REGISTER(sb2_di_mdscpu, sb2_di_debug_info);
	printk(KERN_DEBUG, TAG_NAME_VSC, "DCMT_DEBUG_INFO_REGISTER(sb2_di_mdscpu,sb2_di_debug_info)\n");


	/******************DCMT register callback func in init flow******************/
	DCMT_DEBUG_INFO_REGISTER(sb2_m_cap_mdscpu, sb2_m_cap_debug_info);
	printk(KERN_DEBUG, TAG_NAME_VSC, "DCMT_DEBUG_INFO_REGISTER(sb2_m_cap_mdscpu, sb2_m_cap_debug_info)\n");


	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "\n\n\n\n *****************  vsc init module  *********************\n\n\n\n");
	if (vsc_major) {
		dev = MKDEV(vsc_major, vsc_minor);
		result = register_chrdev_region(dev, vsc_nr_devs, VSC_DEVICE_NAME);
	} else {
		result = alloc_chrdev_region(&dev, vsc_minor, vsc_nr_devs,VSC_DEVICE_NAME);
		vsc_major = MAJOR(dev);
	}
	if (result < 0) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, KERN_WARNING "vsc: can't get major %d\n", vsc_major);
		return result;
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "vsc init module major number = %d\n", vsc_major);

	vsc_class = class_create(THIS_MODULE,VSC_DEVICE_NAME);

	if (IS_ERR(vsc_class))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scalevsc: can not create class...\n");
		result = PTR_ERR(vsc_class);
		goto fail_class_create;
	}

	vsc_class->devnode = vsc_devnode;

	vsc_platform_devs = platform_device_register_simple(VSC_DEVICE_NAME, -1, NULL, 0);

	if((result = platform_driver_register(&vsc_device_driver)) != 0){
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scalevsc: can not register platform driver...\n");
		result = -ENOMEM;
		goto fail_platform_driver_register;
	}

    devno = MKDEV(vsc_major, vsc_minor);
    cdev_init(&vsc_cdev, &vsc_fops);
    vsc_cdev.owner = THIS_MODULE;
   	vsc_cdev.ops = &vsc_fops;
	result = cdev_add (&vsc_cdev, devno, 1);
	if (result<0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "scalevsc: can not add character device...\n");
		goto fail_cdev_init;
	}

    device_create(vsc_class, NULL, MKDEV(vsc_major, 0), NULL, VSC_DEVICE_NAME);
   	sema_init(&VSC_Semaphore, 1);
	sema_init(&MagMsg_Semaphore, 1);
	sema_init(&Magnifier_Semaphore, 1);
	sema_init(&SetMainOutPutRegion_Semaphore, 1);
	sema_init(&Main_ResetMode_Semaphore, 1);
	sema_init(&Adaptive_Streaming_Semaphore, 1);
	sema_init(&DM_HDR_Semaphore, 1);
	sema_init(&Force_Run_Idma_Semaphore, 1);
	sema_init(&Low_Delay_Semaphore, 1);
	sema_init(&Memc_Realcinema_Semaphore, 1);
	sema_init(&Iv2dv_Slow_Tuning_Semaphore, 1);
	sema_init(&VPQ_ld_running_Semaphore, 1);
	sema_init(&VPQ_DeXC_MEM_Semaphore, 1);
	sema_init(&Double_buffer_Semaphore, 1);
	sema_init(&GameMode_Check_Semaphore, 1);
	sema_init(&muteoff_cb_sem, 1);
#ifdef CONFIG_HDR_SDR_SEAMLESS
	sema_init(&HDR_Setting_Semaphore, 1);
#endif
#ifdef CONFIG_DUAL_CHANNEL
	sema_init(&SetSubOutPutRegion_Semaphore, 1);
	sema_init(&Sub_ResetMode_Semaphore, 1);
#endif
#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
	sema_init(&Orbit_algo_Semaphore, 1);
#endif
	sema_init	(&I2RND_Semaphore, 1);
	forcebg_semaphore_init();//Init force semaphore
	DI_semaphore_init();//Init force semaphore
	sema_init(&vsc_src_verify_num_ctrl_sem, 1);//initial the Semaphore for vsc source verify
	DbgSclrFlgTkr.VSC_Device_Init_Done = TRUE;

	//init_i3ddmavi_rpc();
	PcbSource_Init();
	drvif_memory_init();
	create_vsc_tsk();/*Create VSC task*/
	create_magnifier_tsk();
	/*Panel_LVDS_To_Hdmi_Converter_Parameter();*/
#ifdef BRING_UP_AUTO_FLOW
	create_bring_up_vsc_tsk();/*Create bring up vsc tsk*/
#endif
#ifdef USE_FORCEBG_TASK
	create_forcebg_tsk();//Create forcebg task
#endif
	create_fixlast_line_tsk(); //Create fix last line tsk
#ifdef CONFIG_DUMP_REGISTER
	create_dump_register_vsc_tsk();
#endif
	create_game_mode_unmute_tsk(); //Create game mode unmute tsk
#if 1//FIXME @Crixus for K3L bringup
	IoReg_Write32(0xb8000118, _BIT24 | _BIT25 | _BIT0);
 	IoReg_Write32(0xb8000108, _BIT24 | _BIT25 | _BIT0);
#endif


    	return 0;	//success

fail_cdev_init:
	platform_driver_unregister(&vsc_device_driver);
fail_platform_driver_register:
	platform_device_unregister(vsc_platform_devs);
	vsc_platform_devs = NULL;
	class_destroy(vsc_class);
fail_class_create:
	vsc_class = NULL;
	unregister_chrdev_region(vsc_devno, 1);
	return result;
}



void __exit vsc_cleanup_module(void)
{
	dev_t devno = MKDEV(vsc_major, vsc_minor);
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC, "rtice clean module vsc_major = %d\n", vsc_major);
	delete_vsc_tsk();/*Delete VSC task*/
#ifdef USE_FORCEBG_TASK
	delete_forcebg_tsk();
#endif
	delete_fix_lastline_tsk();
	delete_game_mode_unmute_tsk();

	delete_magnifier_tsk();
#ifdef BRING_UP_AUTO_FLOW
	delete_bring_up_vsc_tsk();/*Delete bring up vsc tsk*/
#endif
#ifdef CONFIG_DUMP_REGISTER
		delete_dump_register_vsc_tsk();
#endif
  	device_destroy(vsc_class, MKDEV(vsc_major, 0));
  	class_destroy(vsc_class);
	vsc_class = NULL;
	cdev_del(&vsc_cdev);
   	/* device driver removal */
	if(vsc_platform_devs) {
		platform_device_unregister(vsc_platform_devs);
		vsc_platform_devs = NULL;
	}
  	platform_driver_unregister(&vsc_device_driver);
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, vsc_nr_devs);
	DbgSclrFlgTkr.VSC_Device_Init_Done = FALSE;
	drvif_memory_release();
}
struct semaphore* get_vsc_semaphore(void)
{
	return &VSC_Semaphore;
}

unsigned char Get_AVD_display(unsigned char display)
{

	if (Get_DisplayMode_Src(display) == VSC_INPUTSRC_AVD)
		return TRUE;
	else
		return FALSE;
}


unsigned char VSC_Check_AVD_Connected(void)
{
	if (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD
	  ||Get_DisplayMode_Src(SLR_SUB_DISPLAY) == VSC_INPUTSRC_AVD)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void fw_scalerip_set_di_gamemode_flag(unsigned char bflag)
{
	if(DbgSclrFlgTkr.DI_low_delay_flag != bflag) {

		down(&Low_Delay_Semaphore);
		DbgSclrFlgTkr.DI_low_delay_flag = bflag;
		up(&Low_Delay_Semaphore);

	}
}


unsigned char fw_scalerip_get_di_gamemode_flag(void)
{
	return DbgSclrFlgTkr.DI_low_delay_flag;
}

void fw_set_vsc_GameMode(unsigned char b_vscGameMode_OnOff)
{
	enable_VSC_GameMode = b_vscGameMode_OnOff;
}

unsigned char fw_get_vsc_GameMode(void)
{
	return enable_VSC_GameMode;
}

#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO

#define ORBIT_TIME 180
static unsigned char orbit_shift_index=0;
static unsigned char start_orbit_algo=FALSE;

/*api which have protect by forcebg_semaphore*/
void Scaler_start_orbit_algo(unsigned char b_enable)
{

	if((b_enable != start_orbit_algo)&&(b_enable)){
		Scaler_reset_orbit();
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"start_orbit_algo(%d)\n", b_enable);
	start_orbit_algo = b_enable;
}

unsigned char Scaler_get_orbit_algo_status(void)
{
	if(vbe_disp_get_orbit()== TRUE)
		return start_orbit_algo;
	else
		return FALSE;
}
/*api which have protect by forcebg_semaphore*/
void Scaler_reset_orbit(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Scaler_reset_orbit\n");

	down(&Orbit_algo_Semaphore);
	orbit_shift_index = 0;
	vbe_disp_orbit_position_update(0xff); // force update

	if (!OrbitTimerList.function)
		Scaler_Orbit_Timer_Init();

	mod_timer(&OrbitTimerList, jiffies + ORBIT_TIME*HZ);
	up(&Orbit_algo_Semaphore);
}


void OrbitTimer()
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"OrbitTimer\n");

	//down(&Orbit_algo_Semaphore);
	if(Scaler_get_orbit_algo_status() == TRUE){
		if(orbit_shift_index < 43){
			orbit_shift_index++;
		}else{
			orbit_shift_index=0;
		}
	}else{
		orbit_shift_index=0;
	}
	vbe_disp_orbit_position_update(orbit_shift_index);
	mod_timer(&OrbitTimerList, jiffies + ORBIT_TIME*HZ);
	//up(&Orbit_algo_Semaphore);
	//OrbitTimerList.expires = jiffies + HZ;
	//add_timer(&OrbitTimerList);
}

void Scaler_Orbit_Timer_Init(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Scaler_Orbit_Timer_Init\n");

	g_ucTimerInitCount++;

	if (timer_pending(&OrbitTimerList))
	{
		rtd_printk(KERN_EMERG, TAG_NAME_VSC,"Error! Scaler_Orbit_Timer_Init more than twice. g_ucTimerInitCount=%d\n", g_ucTimerInitCount);
		dump_stack();

		return;
	}

	BUG_ON(timer_pending(&OrbitTimerList));

	/* timer init*/
	init_timer(&OrbitTimerList);
	OrbitTimerList.data = ((unsigned long) 0);
	OrbitTimerList.function = (void *)OrbitTimer;
	OrbitTimerList.expires = jiffies + ORBIT_TIME*HZ;
	/*add timer*/
	add_timer(&OrbitTimerList);
}

void Scaler_Orbit_Timer_Delete(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VSC,"Scaler_Orbit_Timer_Delete\n");
	/* delete timer */
	del_timer_sync(&OrbitTimerList);
}
#endif

module_init(vsc_init_module) ;
module_exit(vsc_cleanup_module) ;
