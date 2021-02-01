/*Kernel Header file*/
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
#include <linux/init.h>
#include <linux/spinlock_types.h>/*For spinlock*/
#include <linux/suspend.h>

/*RBUS Header file*/
#include <scalercommon/scalerCommon.h>
#include <scalercommon/scalerDrvCommon.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/memc_mux_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/ppoverlay_reg.h>
#ifdef CONFIG_HW_SUPPORT_MEMC
#include <rbus/memc_dbus_wrap_reg.h>
#endif
#include <rbus/di_reg.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <rbus/sys_reg_reg.h>


/*TVScaler Header file*/
#include "scaler_vpqmemcdev.h"
#include "scaler_vscdev.h"
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/vip/memc_mux.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/panel/panelapi.h>
#include "scaler_vbedev.h"
#include <scalercommon/vipRPCCommon.h>

#include <mach/rtk_log.h>
#define TAG_NAME "MEMC"

//#define RUN_MERLIN_MEMC_ENABLE
#define MEMC_DEBUG

#ifdef MEMC_DEBUG
#define MEMC_DBG_PRINT(s, args...) rtd_printk(KERN_DEBUG, TAG_NAME, s, ## args)
#else
#define MEMC_DBG_PRINT(s, args...)
#endif

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
#include "memc_isr/scalerMEMC.h"
#endif

#if 0
#define bisr_rstn_addr_kme 	(0xb8000f00)
#define IP_rstn_bits_kme 	(_BIT10)
#define bisr_remap_addr_kme	(0xb8000f10)
#define IP_remap_bits_kme 	(_BIT10)
#define bisr_done_addr_kme 	(0xb8000f20)
#define IP_done_bits_kme 	(_BIT10)
#define bisr_repair_addr_kme (0xb809d0e4)
#define IP_repair_check_bits_kme (_BIT26)
#define bisr_fail_addr_kme 	(0xb809d0e4)
#define IP_fail_bits_kme 	(_BIT24)

#define bisr_rstn_addr_kmc 	(0xb8000f00)
#define IP_rstn_bits_kmc 	(_BIT8|_BIT7|_BIT4|_BIT3|_BIT2|_BIT1)
#define bisr_remap_addr_kmc	(0xb8000f10)
#define IP_remap_bits_kmc 	(_BIT8|_BIT7|_BIT4|_BIT3|_BIT2|_BIT1)
#define bisr_done_addr_kmc 	(0xb8000f20)
#define IP_done_bits_kmc 	(_BIT8|_BIT7|_BIT4|_BIT3|_BIT2|_BIT1)
#define bisr_repair_addr_kmc (0xb8099098)
#define IP_repair_check_bits_kmc (_BIT8|_BIT7|_BIT6|_BIT5|_BIT4|_BIT3|_BIT2|_BIT1|_BIT0)
#define bisr_fail_addr_kmc 	(0xb809909c)
#define IP_fail_bits_kmc 	(_BIT7|_BIT6|_BIT3|_BIT2|_BIT1|_BIT0)
#endif
static struct cdev vpq_memc_cdev;

int vpq_memc_major   = 0;
int vpq_memc_minor   = 0 ;
int vpq_memc_nr_devs = 1;

static struct semaphore vpq_memc_Semaphore;
static struct semaphore livezoom_memcclose_Semaphore;
extern struct semaphore Memc_Realcinema_Semaphore;
extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr;//extern char memc_realcinema_run_flag;//Run memc mode

module_param(vpq_memc_major, int, S_IRUGO);
module_param(vpq_memc_minor, int, S_IRUGO);
module_param(vpq_memc_nr_devs, int, S_IRUGO);
static struct class *vpq_memc_class;
static UINT8 MEMC_First_Run_Done=0;//using for booting to avoid second initial
static UINT8 MEMC_First_Run_FBG_enable=0;//using for booting fbg checking
static UINT8 MEMC_instanboot_resume_Done=0;
static UINT8 MEMC_snashop_resume_Done=0;
static unsigned int gphy_addr_kme, gphy_addr_kmc00, gphy_addr_kmc01;
static VPQ_MEMC_TYPE_T MEMC_motion_type = VPQ_MEMC_TYPE_OFF;
static char AVD_Unstable_Check_MEMC_OutBG_flag = FALSE;
extern unsigned char fwif_color_get_cinema_mode_en(void);

/*******************************************************************************
****************************VPQ MEMC DRIVER************************************
*******************************************************************************/
//#ifdef CONFIG_ENABLE_MEMC
void HAL_VPQ_MEMC_Initialize(void){
	if(MEMC_First_Run_Done == 0){
		MEMC_First_Run_Done = 1;
		MEMC_First_Run_FBG_enable = _ENABLE;
		Scaler_MEMC_output_force_bg_enable(TRUE);
		Scaler_MEMC_initial_Case();
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]HAL_VPQ_MEMC_Initialize Done!!\n");
	}
}

void HAL_VPQ_MEMC_Uninitialize(void){

}

void memc_setting_displayDtiming_framerate(void)
{
	unsigned int vfreq_ori = 0;
	vfreq_ori = Scaler_DispGetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ);
	modestate_decide_dtg_m_mode();
	if(vfreq_ori != Scaler_DispGetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ))
		scaler_disp_smooth_variable_settingByDisp(0);
}

/**
 *@brief memc_realcinema_framerate Set framerate while turnning on/off real-cinema
 *@return VOID
**/
void memc_realcinema_framerate(void)
{
	/*scaler timing setting is finish?*/
	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_STATE) != _MODE_STATE_ACTIVE)
		return;

	/*input frame rate must be 24hz or output is 48hz*/
	if(((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ) > 235) && \
			(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ) < 245)) || \
			Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DTG_MASTER_V_FREQ) == 48) {
		unsigned int vfreq_ori = 0;
		vfreq_ori = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DTG_MASTER_V_FREQ);
		modestate_decide_dtg_m_modeByDisp((unsigned char)SLR_MAIN_DISPLAY);
		if(vfreq_ori != Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DTG_MASTER_V_FREQ))
			scaler_disp_smooth_variable_settingByDisp((unsigned char)SLR_MAIN_DISPLAY);
	}
}

unsigned char LiveZoom_MEMCClose_Flag = FALSE;

struct semaphore* get_livezoom_memcclose_Semaphore(void)
{
	return &livezoom_memcclose_Semaphore;
}

long HAL_VPQ_MEMC_SetMotionComp(UINT8 blurLevel, UINT8 judderLevel, VPQ_MEMC_TYPE_T motion){
	VPQ_MEMC_SETMOTIONCOMP_T *set_motion_comp_info;
	unsigned int ulCount = 0;
	int ret = 0;
	unsigned int semaphoreCnt = 0;

	//Elsie 20151120, add semaphore
	while((IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg)&_BIT30) && semaphoreCnt < 100000) {
		semaphoreCnt++;
	}
	if(semaphoreCnt >= 100000) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]HAL_VPQ_MEMC_SetMotionComp timed out!\n");
		return -1;
	}
	IoReg_SetBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg, _BIT30);

	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]HAL_VPQ_MEMC_SetMotionComp\n");
	rtd_printk(KERN_DEBUG, TAG_NAME, "blurLevel = %d\n judderLevel = %d\n motion = %d\n",blurLevel, judderLevel, motion);

	set_motion_comp_info = (VPQ_MEMC_SETMOTIONCOMP_T *)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_SETMOTIONCOMP);
	ulCount = sizeof(VPQ_MEMC_SETMOTIONCOMP_T) / sizeof(unsigned int);

	set_motion_comp_info->blurLevel = blurLevel;
	set_motion_comp_info->judderLevel = judderLevel;
	set_motion_comp_info->motion = motion;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//change endian
	set_motion_comp_info->blurLevel = htonl(set_motion_comp_info->blurLevel);
	set_motion_comp_info->judderLevel = htonl(set_motion_comp_info->judderLevel);
	set_motion_comp_info->motion = htonl(set_motion_comp_info->motion);
#else
#ifndef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	//change endian
	set_motion_comp_info->blurLevel = htonl(set_motion_comp_info->blurLevel);
	set_motion_comp_info->judderLevel = htonl(set_motion_comp_info->judderLevel);
	set_motion_comp_info->motion = htonl(set_motion_comp_info->motion);
#endif
#endif

	down(&Memc_Realcinema_Semaphore);
	//save current MEMC motion type+	Scaler_MEMC_SetMotionType(motion);
	Scaler_MEMC_SetMotionType(motion);
	//set frame rate
	if ((Get_Live_zoom_mode()!=LIVE_ZOOM_OFF)||(Get_LivezoomOffMainForceBG() == TRUE)) {
		/*qiangzhou:livezomm no need setting dtg three times*/
		//down(get_livezoom_memcclose_Semaphore());
		//LiveZoom_MEMCClose_Flag = TRUE;
		//up(get_livezoom_memcclose_Semaphore());
	} else {
		DbgSclrFlgTkr.memc_realcinema_run_flag = TRUE;//Run memc mode
		//memc_realcinema_framerate();
	}
	up(&Memc_Realcinema_Semaphore);
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETMOTIONCOMP,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETMOTIONCOMP RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT

#ifndef CONFIG_MEMC_TASK_QUEUE
	if(!Scaler_MEMC_GetMEMC_Enable())
		return 0;
	#ifndef CONFIG_MEMC_DEFAULT_REPEAT_MODE
	Scaler_MEMC_SetMotionComp(set_motion_comp_info->blurLevel, set_motion_comp_info->judderLevel, set_motion_comp_info->motion);
#else
		Scaler_MEMC_SetMotionComp(0,0,0);
	#endif
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETMOTIONCOMP;
		memcpy(&task.data,set_motion_comp_info,sizeof(SCALER_MEMC_TASK_T));
		#ifdef CONFIG_MEMC_DEFAULT_REPEAT_MODE
		task.data.memc_set_motion_comp.motion = 0;
		#endif
		Scaler_MEMC_PushTask(&task);
#endif

#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETMOTIONCOMP,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETMOTIONCOMP RPC fail !!!\n", ret);
	}
#endif
#endif

	IoReg_ClearBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);

	return ret;
}
/* not use in WebOS
void HAL_VPQ_MEMC_SetBlurLevel(UINT8 blurLevel){
	int ret;

	MEMC_DBG_PRINT("blurLevel = %d\n",blurLevel);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETBLURLEVEL, blurLevel, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETBLURLEVEL RPC fail !!!\n", ret);
	}
}

void HAL_VPQ_MEMC_SetJudderLevel(UINT8 judderLevel){
	int ret;

	MEMC_DBG_PRINT("judderLevel = %d\n",judderLevel);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETJUDDERLEVEL, judderLevel, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETJUDDERLEVEL RPC fail !!!\n", ret);
	}
}
*/
long HAL_VPQ_MEMC_MotionCompOnOff(BOOLEAN bOnOff){
	int ret = 0;
	unsigned int semaphoreCnt = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]HAL_VPQ_MEMC_SetMotionComp, bOnOff = %d\n", bOnOff);

	while((IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg)&_BIT30) && semaphoreCnt < 100000) {
		semaphoreCnt++;
	}
	if(semaphoreCnt >= 100000) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]HAL_VPQ_MEMC_SetMotionComp timed out!\n");
		return -1;
	}
	IoReg_SetBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_MOTIONCOMPONOFF, bOnOff, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_MOTIONCOMPONOFF RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_MotionCompOnOff(bOnOff);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_MOTIONCOMPONOFF;
		task.data.value = bOnOff;
		Scaler_MEMC_PushTask(&task);
	#endif

#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_MOTIONCOMPONOFF, bOnOff, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_MOTIONCOMPONOFF RPC fail !!!\n", ret);
	}
#endif
#endif
	IoReg_ClearBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
	return ret;
}

long HAL_VPQ_MEMC_LowDelayMode(UINT8 type){
	int ret = 0;
	unsigned int semaphoreCnt = 0;

	while((IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg)&_BIT30) && semaphoreCnt < 100000) {
		semaphoreCnt++;
	}
	if(semaphoreCnt >= 100000) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]HAL_VPQ_MEMC_LowDelayMode timed out!\n");
		return -1;
	}
	IoReg_SetBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_LOWDELAYMODE, type, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_LOWDELAYMODE RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_LowDelayMode(type);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_LOWDELAYMODE;
		task.data.value = type;
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_LOWDELAYMODE, type, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_LOWDELAYMODE RPC fail !!!\n", ret);
	}
#endif
#endif
	IoReg_ClearBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
	return ret;
}
long HAL_VPQ_MEMC_SetRGBYUVMode(UINT8 mode){
	int ret = 0;

	//if(mode == 0)
	//	mode = VPQ_MEMC_RGB_IN_VIDEO_OUT;
	//else
	//	mode = VPQ_MEMC_YUV_IN_VIDEO_OUT;
	unsigned int semaphoreCnt = 0;

	while((IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg)&_BIT30) && semaphoreCnt < 100000) {
		semaphoreCnt++;
	}
	if(semaphoreCnt >= 100000) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]HAL_VPQ_MEMC_SetRGBYUVMode timed out!\n");
		return -1;
	}
	IoReg_SetBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETRGBYUVMode, mode, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETRGBYUVMode RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetRGBYUVMode(mode);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETRGBYUVMode;
		task.data.value = mode;
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETRGBYUVMode, mode, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETRGBYUVMode RPC fail !!!\n", ret);
	}
#endif
#endif
	IoReg_ClearBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
	return ret;
}
void HAL_VPQ_MEMC_GetFrameDelay (UINT16 *pFrameDelay){
	/*
	int ret;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_GETFRAMEDELAY, 1, 1))){
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]ret=%d, SCALERIOC_MEMC_GETFRAMEDELAY RPC fail !!!\n", ret);
	}
	*/
}


void HAL_VPQ_MEMC_SetVideoBlock(VPQ_MEMC_MUTE_TYPE_T type, BOOLEAN bOnOff) {
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, bOnOff);
	down(get_forcebg_semaphore());
	scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, bOnOff);
	up(get_forcebg_semaphore());
}

/* not use in WebOS
void HAL_VPQ_MEMC_SetTrueMotionDemo(BOOLEAN bOnOff){
	int ret;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETTRUEMOTIONDEMO, bOnOff, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETTRUEMOTIONDEMO RPC fail !!!\n", ret);
	}
}
void HAL_VPQ_MEMC_GetFirmwareVersion(UINT16 *pVersion){

	int ret;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETBLURLEVEL, blurLevel, 1))){
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]ret=%d, SCALERIOC_MEMC_SETBLURLEVEL RPC fail !!!\n", ret);
	}

}
*/
void HAL_VPQ_MEMC_SetBypassRegion(BOOLEAN bOnOff, VPQ_MEMC_BYPASS_REGION_T region, UINT32 x, UINT32 y, UINT32 w, UINT32 h){
	VPQ_MEMC_SETBYPASSREGION_T*set_bypass_region_info;
	unsigned int ulCount = 0;
	int ret;

	MEMC_DBG_PRINT("region = %d\n",region);
	MEMC_DBG_PRINT("rect.x = %d, rect.y = %d, rect.w = %d, rect.h = %d\n",x, y, w, h);

	MEMC_DBG_PRINT("bOnOff = %d\n",bOnOff);

	set_bypass_region_info = (VPQ_MEMC_SETBYPASSREGION_T *)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_SETBYPASSREGION);
	ulCount = sizeof(VPQ_MEMC_SETBYPASSREGION_T) / sizeof(unsigned int);

	set_bypass_region_info->bOnOff = bOnOff;
	set_bypass_region_info->region = region;
	set_bypass_region_info->x = x;
	set_bypass_region_info->y = y;
	set_bypass_region_info->w = w;
	set_bypass_region_info->h = h;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//change endian
	set_bypass_region_info->bOnOff = htonl(set_bypass_region_info->bOnOff);
	set_bypass_region_info->region = htonl(set_bypass_region_info->region);
	set_bypass_region_info->x = htonl(set_bypass_region_info->x);
	set_bypass_region_info->y = htonl(set_bypass_region_info->y);
	set_bypass_region_info->w = htonl(set_bypass_region_info->w);
	set_bypass_region_info->h = htonl(set_bypass_region_info->h);


	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETBYPASSREGION,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETBYPASSREGION RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetBypassRegion(set_bypass_region_info->bOnOff, set_bypass_region_info->region, set_bypass_region_info->x, set_bypass_region_info->y, set_bypass_region_info->w, set_bypass_region_info->h);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETBYPASSREGION;
		memcpy(&task.data,set_bypass_region_info,sizeof(SCALER_MEMC_SETBYPASSREGION_T));
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	//change endian
	set_bypass_region_info->bOnOff = htonl(set_bypass_region_info->bOnOff);
	set_bypass_region_info->region = htonl(set_bypass_region_info->region);
	set_bypass_region_info->x = htonl(set_bypass_region_info->x);
	set_bypass_region_info->y = htonl(set_bypass_region_info->y);
	set_bypass_region_info->w = htonl(set_bypass_region_info->w);
	set_bypass_region_info->h = htonl(set_bypass_region_info->h);


	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETBYPASSREGION,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETBYPASSREGION RPC fail !!!\n", ret);
	}
#endif
#endif
}
/* not use in WebOS
void HAL_VPQ_MEMC_SetReverseControl(UINT8 u8Mode){
	int ret;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETREVERSECONTROL, u8Mode, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETREVERSECONTROL RPC fail !!!\n", ret);
	}
}
void HAL_VPQ_MEMC_Freeze(UINT8 type){
	int ret;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_FREEZE, type, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_FREEZE RPC fail !!!\n", ret);
	}
}
void HAL_VPQ_MEMC_SetDemoBar(BOOLEAN bOnOff, UINT8 r, UINT8 g, UINT8 b){
	VPQ_MEMC_SETDEMOBAR_T*set_demo_bar_info;
	unsigned int ulCount = 0;
	int ret;

	set_demo_bar_info = (VPQ_MEMC_SETDEMOBAR_T *)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_SETDEMOBAR);
	ulCount = sizeof(VPQ_MEMC_SETDEMOBAR_T) / sizeof(unsigned int);

	set_demo_bar_info->bOnOff = bOnOff;
	set_demo_bar_info->r = r;
	set_demo_bar_info->g = g;
	set_demo_bar_info->b = b;

	//change endian
	set_demo_bar_info->bOnOff = htonl(set_demo_bar_info->bOnOff);
	set_demo_bar_info->r = htonl(set_demo_bar_info->r);
	set_demo_bar_info->g = htonl(set_demo_bar_info->g);
	set_demo_bar_info->b = htonl(set_demo_bar_info->b);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETDEMOBAR,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETDEMOBAR RPC fail !!!\n", ret);
	}
}
void HAL_VPQ_MEMC_DEBUG(void){

}
*/
void Scaler_MEMC_SetInOutUseCase(VPQ_MEMC_INPUT_RESOLUTION input_re, VPQ_MEMC_OUTPUT_RESOLUTION output_re, VPQ_MEMC_INPUT_FORMAT input_for, VPQ_MEMC_OUTPUT_FORMAT output_for){
	SCALER_MEMC_SETINOUTUSECASE_T* set_inout_usecase_info;
	unsigned int ulCount = 0;
	int ret;

	set_inout_usecase_info = (SCALER_MEMC_SETINOUTUSECASE_T*)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_SETINOUTUSECASE);
	ulCount = sizeof(SCALER_MEMC_SETINOUTUSECASE_T) / sizeof(unsigned int);

	set_inout_usecase_info->input_re = input_re;
	set_inout_usecase_info->output_re = output_re;
	set_inout_usecase_info->input_for = input_for;
	set_inout_usecase_info->output_for = output_for;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//change endian
	set_inout_usecase_info->input_re = htonl(set_inout_usecase_info->input_re);
	set_inout_usecase_info->output_re = htonl(set_inout_usecase_info->output_re);
	set_inout_usecase_info->input_for = htonl(set_inout_usecase_info->input_for);
	set_inout_usecase_info->output_for = htonl(set_inout_usecase_info->output_for);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINOUTUSECASE,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINOUTUSECASE RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetInOutputUseCase(set_inout_usecase_info->input_re, set_inout_usecase_info->output_re, set_inout_usecase_info->input_for, set_inout_usecase_info->output_for);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETINOUTUSECASE;
		memcpy(&task.data,set_inout_usecase_info,sizeof(SCALER_MEMC_SETINOUTUSECASE_T));
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	//change endian
	set_inout_usecase_info->input_re = htonl(set_inout_usecase_info->input_re);
	set_inout_usecase_info->output_re = htonl(set_inout_usecase_info->output_re);
	set_inout_usecase_info->input_for = htonl(set_inout_usecase_info->input_for);
	set_inout_usecase_info->output_for = htonl(set_inout_usecase_info->output_for);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINOUTUSECASE,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINOUTUSECASE RPC fail !!!\n", ret);
	}
#endif
#endif
}

void Scaler_MEMC_SetInOutputFormat(VPQ_MEMC_INPUT_FORMAT input_for, VPQ_MEMC_OUTPUT_FORMAT output_for){
	SCALER_MEMC_SETINOUTPUTFORMAT_T* set_inputput_format_info;
	unsigned int ulCount = 0;
	int ret;

	set_inputput_format_info = (SCALER_MEMC_SETINOUTPUTFORMAT_T*)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_SETINPUTOUTPUTFORMAT);
	ulCount = sizeof(SCALER_MEMC_SETINOUTPUTFORMAT_T) / sizeof(unsigned int);

	set_inputput_format_info->input_for = input_for;
	set_inputput_format_info->output_for = output_for;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//change endian
	set_inputput_format_info->input_for = htonl(set_inputput_format_info->input_for);
	set_inputput_format_info->output_for = htonl(set_inputput_format_info->output_for);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINPUTOUTPUTFORMAT,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINPUTOUTPUTFORMAT RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetInputOutputFormat(set_inputput_format_info->input_for, set_inputput_format_info->output_for);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETINPUTOUTPUTFORMAT;
		memcpy(&task.data,set_inputput_format_info,sizeof(SCALER_MEMC_SETINOUTPUTFORMAT_T));
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	//change endian
	set_inputput_format_info->input_for = htonl(set_inputput_format_info->input_for);
	set_inputput_format_info->output_for = htonl(set_inputput_format_info->output_for);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINPUTOUTPUTFORMAT,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINPUTOUTPUTFORMAT RPC fail !!!\n", ret);
	}
#endif
#endif
}

void Scaler_MEMC_SetInOutputResolution(VPQ_MEMC_INPUT_RESOLUTION input_re, VPQ_MEMC_OUTPUT_RESOLUTION output_re){
	SCALER_MEMC_SETINOUTPUTRESOLUTION_T* set_inoutput_resolution_info;
	unsigned int ulCount = 0;
	int ret;

	set_inoutput_resolution_info = (SCALER_MEMC_SETINOUTPUTRESOLUTION_T*)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_SETINPUTOUTPUTRESOLUTION);
	ulCount = sizeof(SCALER_MEMC_SETINOUTPUTRESOLUTION_T) / sizeof(unsigned int);

	set_inoutput_resolution_info->input_re = input_re;
	set_inoutput_resolution_info->output_re = output_re;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//change endian
	set_inoutput_resolution_info->input_re = htonl(set_inoutput_resolution_info->input_re);
	set_inoutput_resolution_info->output_re = htonl(set_inoutput_resolution_info->output_re);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINPUTOUTPUTRESOLUTION,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINPUTOUTPUTRESOLUTION RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetInputOutputResolution(set_inoutput_resolution_info->input_re, set_inoutput_resolution_info->output_re);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETINPUTOUTPUTRESOLUTION;
		memcpy(&task.data,set_inoutput_resolution_info,sizeof(SCALER_MEMC_SETINOUTPUTRESOLUTION_T));
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	//change endian
	set_inoutput_resolution_info->input_re = htonl(set_inoutput_resolution_info->input_re);
	set_inoutput_resolution_info->output_re = htonl(set_inoutput_resolution_info->output_re);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINPUTOUTPUTRESOLUTION,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINPUTOUTPUTRESOLUTION RPC fail !!!\n", ret);
	}
#endif
#endif
}
#if 1
void Scaler_MEMC_SetInOutputFrameRate(VPQ_MEMC_INPUT_FRAMERATE input_frame, VPQ_MEMC_OUTPUT_FRAMERATE output_frame){
	SCALER_MEMC_INOUTFRAMERATE_T* set_inoutput_framerate_info;
	unsigned int ulCount = 0;
	int ret;

	set_inoutput_framerate_info = (SCALER_MEMC_INOUTFRAMERATE_T*)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_SETINOUTPUTFRAMERATE);
	ulCount = sizeof(SCALER_MEMC_INOUTFRAMERATE_T) / sizeof(unsigned int);

	set_inoutput_framerate_info->input_frame_rate= input_frame;
	set_inoutput_framerate_info->output_frame_rate= output_frame;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//change endian
	set_inoutput_framerate_info->input_frame_rate = htonl(set_inoutput_framerate_info->input_frame_rate);
	set_inoutput_framerate_info->output_frame_rate = htonl(set_inoutput_framerate_info->output_frame_rate);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINOUTPUTFRAMERATE,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINOUTPUTFRAMERATE RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetInputFrameRate(set_inoutput_framerate_info->input_frame_rate);
	Scaler_MEMC_SetOutputFrameRate(set_inoutput_framerate_info->output_frame_rate);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETINOUTPUTFRAMERATE;
		memcpy(&task.data,set_inoutput_framerate_info,sizeof(SCALER_MEMC_INOUTFRAMERATE_T));
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	//change endian
	set_inoutput_framerate_info->input_frame_rate = htonl(set_inoutput_framerate_info->input_frame_rate);
	set_inoutput_framerate_info->output_frame_rate = htonl(set_inoutput_framerate_info->output_frame_rate);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINOUTPUTFRAMERATE,0,0))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINOUTPUTFRAMERATE RPC fail !!!\n", ret);
	}
#endif
#endif
}
#else
void Scaler_MEMC_SetInputFrameRate(VPQ_MEMC_INPUT_FRAMERATE input_frame){
	int ret;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETINPUTFRAMERATE, input_frame, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETINPUTFRAMERATE RPC fail !!!\n", ret);
	}
}

void Scaler_MEMC_SetOutputFrameRate(VPQ_MEMC_OUTPUT_FRAMERATE output_frame){
	int ret;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETOUTPUTFRAMERATE, output_frame, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETOUTPUTFRAMERATE RPC fail !!!\n", ret);
	}
}
#endif

long Scaler_MEMC_SetFrameRepeatEnable(BOOL bEnable){
	int ret = 0;
	unsigned int semaphoreCnt = 0;

	while((IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg)&_BIT30) && semaphoreCnt < 100000) {
		semaphoreCnt++;
	}
	if(semaphoreCnt >= 100000) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]Scaler_MEMC_SetFrameRepeatEnable timed out!\n");
		return -1;
	}
	IoReg_SetBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETMEMCFRAMEREPEATENABLE, bEnable, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETMEMCFRAMEREPEATENABLE RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetMEMCFrameRepeatEnable(bEnable);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETMEMCFRAMEREPEATENABLE;
		task.data.value = bEnable;
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETMEMCFRAMEREPEATENABLE, bEnable, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETMEMCFRAMEREPEATENABLE RPC fail !!!\n", ret);
	}
#endif
#endif
	IoReg_ClearBits(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg,_BIT30);
	return ret;
}

void Scaler_MEMC_SetInOutMode(VPQ_MEMC_INOUT_MODE emom){
	int ret;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETMEMCINOUTMODE, emom, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETMEMCINOUTMODE RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	ISR_Scaler_MEMC_SetInOutMode(emom);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETMEMCINOUTMODE;
		task.data.value = emom;
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETMEMCINOUTMODE, emom, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_SETMEMCINOUTMODE RPC fail !!!\n", ret);
	}
#endif
#endif
}

void Scaler_MEMC_Instanboot_InitPhaseTable(BOOL bEnable){
	int ret;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_INSTANBOOT_INITPHASETABLE, bEnable, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_INSTANBOOT_INITPHASETABLE RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	Scaler_MEMC_SetInstantBootInitPhaseTable();
#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_INSTANBOOT_INITPHASETABLE, bEnable, 1))){
		MEMC_DBG_PRINT("[MEMC]ret=%d, SCALERIOC_MEMC_INSTANBOOT_INITPHASETABLE RPC fail !!!\n", ret);
	}
#endif
#endif
}


void Scaler_MEMC_SetInOutFrameRate(void){
	UINT8 memc_input_frame_rate;
	UINT8 memc_output_frame_rate;

	if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 235) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 245))	//24Hz
	{
		memc_input_frame_rate = VPQ_INPUT_24HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //24Hz => 120Hz
		}
		else{
			if((Scaler_MEMC_GetMotionType() == VPQ_MEMC_TYPE_OFF) && (fwif_color_get_cinema_mode_en() == 1)){
				memc_output_frame_rate = VPQ_OUTPUT_48HZ; //24Hz => 48Hz	//tru-motion off + real cinema
			}else{
				if(vbe_disp_get_adaptivestream_fs_mode() == 1)
					memc_output_frame_rate = VPQ_OUTPUT_48HZ;
				else
					memc_output_frame_rate = VPQ_OUTPUT_60HZ; //24Hz => 60Hz
			}
		}
	}
	else if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 245) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 255))	//25Hz
	{
		memc_input_frame_rate = VPQ_INPUT_25HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_100HZ; //25Hz => 100Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_50HZ; //25Hz => 50Hz
		}
	}
	else if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 295) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 305))	//30Hz
	{
		memc_input_frame_rate = VPQ_INPUT_30HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //30Hz => 120Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_60HZ; //30Hz => 60Hz
		}
	}
	else if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 495) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 505))	//50Hz
	{
		memc_input_frame_rate = VPQ_INPUT_50HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_100HZ; //50Hz => 100Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_50HZ; //50Hz => 50Hz
		}
	}
	else if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 595) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 605))	//60hz
	{
		memc_input_frame_rate = VPQ_INPUT_60HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //60Hz => 120Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_60HZ; //60Hz => 60Hz
		}
	}
	else{ // others
		memc_input_frame_rate = VPQ_INPUT_60HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //60Hz => 120Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_60HZ; //60Hz => 60Hz
		}
	}

	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]UZU DTG input frame_rate = %d\n",memc_input_frame_rate);
	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]MEMC DTG output frame_rate = %d\n",memc_output_frame_rate);

	//set MEMC in/out frame rate
	//Scaler_MEMC_SetInputFrameRate(memc_input_frame_rate);
	//Scaler_MEMC_SetOutputFrameRate(memc_output_frame_rate);
	Scaler_MEMC_SetInOutputFrameRate(memc_input_frame_rate, memc_output_frame_rate);
}

void Scaler_MEMC_SetInOutFrameRateByDisp(unsigned char _channel)
{
	SCALER_DISP_CHANNEL channel = (SCALER_DISP_CHANNEL)_channel;
	UINT8 memc_input_frame_rate;
	UINT8 memc_output_frame_rate;

	if((Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) > 235) && (Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) < 245))	//24Hz
	{
		memc_input_frame_rate = VPQ_INPUT_24HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //24Hz => 120Hz
		}
		else{
			if((Scaler_MEMC_GetMotionType() == VPQ_MEMC_TYPE_OFF) && (fwif_color_get_cinema_mode_en() == 1)){
				memc_output_frame_rate = VPQ_OUTPUT_48HZ; //24Hz => 48Hz	//tru-motion off + real cinema
			}else{
				if(vbe_disp_get_adaptivestream_fs_mode() == 1)
					memc_output_frame_rate = VPQ_OUTPUT_48HZ;
				else
					memc_output_frame_rate = VPQ_OUTPUT_60HZ; //24Hz => 60Hz
			}
		}
	}
	else if((Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) > 245) && (Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) < 255))	//25Hz
	{
		memc_input_frame_rate = VPQ_INPUT_25HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_100HZ; //25Hz => 100Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_50HZ; //25Hz => 50Hz
		}
	}
	else if((Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) > 295) && (Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) < 305))	//30Hz
	{
		memc_input_frame_rate = VPQ_INPUT_30HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //30Hz => 120Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_60HZ; //30Hz => 60Hz
		}
	}
	else if((Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) > 495) && (Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) < 505))	//50Hz
	{
		memc_input_frame_rate = VPQ_INPUT_50HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_100HZ; //50Hz => 100Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_50HZ; //50Hz => 50Hz
		}
	}
	else if((Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) > 595) && (Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_V_FREQ) < 605))	//60hz
	{
		memc_input_frame_rate = VPQ_INPUT_60HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //60Hz => 120Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_60HZ; //60Hz => 60Hz
		}
	}
	else{ // others
		memc_input_frame_rate = VPQ_INPUT_60HZ;
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			memc_output_frame_rate = VPQ_OUTPUT_120HZ; //60Hz => 120Hz
		}
		else{
			memc_output_frame_rate = VPQ_OUTPUT_60HZ; //60Hz => 60Hz
		}
	}

	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]UZU DTG input frame_rate = %d\n",memc_input_frame_rate);
	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]MEMC DTG output frame_rate = %d\n",memc_output_frame_rate);

	//set MEMC in/out frame rate
	//Scaler_MEMC_SetInputFrameRate(memc_input_frame_rate);
	//Scaler_MEMC_SetOutputFrameRate(memc_output_frame_rate);
	Scaler_MEMC_SetInOutputFrameRate(memc_input_frame_rate, memc_output_frame_rate);
}

void Scaler_MEMC_CLK(void){
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;

	//MEMC lantency temp setting
	//rtd_outl(MEMC_LATENCY01_ADDR, 0x00000000);
	//rtd_outl(MEMC_LATENCY02_ADDR, 0x00000000);

	//MEMC in/out clock enable
	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	sys_dispclksel_reg.clken_disp_memc_in= 1;
	sys_dispclksel_reg.clken_disp_memc_out= 1;
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);
}

void Scaler_MEMC_ForceBg(UINT8 bEnable)
{
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl_reg;

	memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	memc_mux_ctrl_reg.memc_out_bg_en = bEnable;
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);

	//set apply
	double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl_reg.uzudtgreg_dbuf_set = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
	double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
}


void Scaler_MEMC_Mux(void){
	//MEMC mux
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl_reg;

	double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);

	//MEMC mux enable
	#ifdef CONFIG_HW_SUPPORT_MEMC
	drvif_memc_mux_en(TRUE);
	#endif

	//DTG MEMC MUX control
	if(vbe_disp_get_dynamic_memc_bypass_flag() == FALSE){
		//if not dynamic swith memc mux, control in scaler memc driver, or control by VBE. @Crixus 20161108
		memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
		if(vbe_disp_decide_memc_mux_bypass()==TRUE)
			memc_mux_ctrl_reg.memc_outmux_sel = 0;
		else
			memc_mux_ctrl_reg.memc_outmux_sel = 1;
		//memc_mux_ctrl_reg.memcdtg_golden_vs = 0;//disable memc golden vsync
		IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
	}
	//set apply
	double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl_reg.uzudtgreg_dbuf_set = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
#if 0
	if(vbe_disp_decide_memc_mux_bypass()==TRUE){
		//disable memc clk
		Scaler_MEMC_Bypass_CLK_OnOff(0);
		if(Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane()) == SOURCE_VIDEO){//DTV case
			pr_notice("DTV 4K, bypass PQ Lv2\n");
			Scaler_color_Set_PQ_ByPass_Lv(2);
		}else if(Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane()) == SOURCE_DIRECTVO){
			pr_notice("Playback 4K, bypass PQ Lv3\n");
			Scaler_color_Set_PQ_ByPass_Lv(3);
		}
	}else{
		Scaler_MEMC_Bypass_CLK_OnOff(1);
	}
#else
	if(vbe_disp_decide_PQ_power_saveing() == TRUE){
		if(Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane()) == SOURCE_VIDEO){//DTV case
			pr_notice("DTV 4K, bypass PQ Lv2\n");
			Scaler_color_Set_PQ_ByPass_Lv(3);
		}else if(Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane()) == SOURCE_DIRECTVO){
			pr_notice("Playback 4K, bypass PQ Lv3\n");
			Scaler_color_Set_PQ_ByPass_Lv(3);
		}
	}

#endif
}

//Reset flow : CLKEN = "0" 'RSTN = "0" 'RSTN = "1" ' CLKEN = "1"
void Scaler_MEMC_Bypass_CLK_OnOff(unsigned char clk_OnOff)
{
#if 0
	sys_reg_sys_srst3_RBUS sys_reg_sys_srst3_reg;
	sys_reg_sys_clken3_RBUS sys_reg_sys_clken3_reg;

	//sys_reg_sys_srst3_reg.regValue = IoReg_Read32(SYS_REG_SYS_SRST3_reg);
	//sys_reg_sys_clken3_reg.regValue = IoReg_Read32(SYS_REG_SYS_CLKEN3_reg);
	sys_reg_sys_srst3_reg.regValue = 0;
	sys_reg_sys_clken3_reg.regValue = 0;

	if(clk_OnOff == 0){
		pr_emerg("MEMC CLK OFF\n");
		// clear memc_in interrupt
		IoReg_ClearBits(0xb8099018, _BIT25);
		// clear memc_out interrupt
		IoReg_ClearBits(0xb809d008, _BIT6);
		sys_reg_sys_clken3_reg.clken_memc = 1;
		sys_reg_sys_clken3_reg.clken_memc_me = 1;
		sys_reg_sys_clken3_reg.write_data = 0;
		IoReg_Write32(SYS_REG_SYS_CLKEN3_reg, sys_reg_sys_clken3_reg.regValue);
		sys_reg_sys_srst3_reg.rstn_memc = 1;
		sys_reg_sys_srst3_reg.rstn_memc_me = 1;
		sys_reg_sys_srst3_reg.write_data = 0;
		IoReg_Write32(SYS_REG_SYS_SRST3_reg, sys_reg_sys_srst3_reg.regValue);
	}else{
		pr_emerg("MEMC CLK ON\n");
		sys_reg_sys_srst3_reg.rstn_memc = 1;
		sys_reg_sys_srst3_reg.rstn_memc_me = 1;
		sys_reg_sys_srst3_reg.write_data = 1;
		IoReg_Write32(SYS_REG_SYS_SRST3_reg, sys_reg_sys_srst3_reg.regValue);
		sys_reg_sys_clken3_reg.clken_memc = 1;
		sys_reg_sys_clken3_reg.clken_memc_me = 1;
		sys_reg_sys_clken3_reg.write_data = 1;
		IoReg_Write32(SYS_REG_SYS_CLKEN3_reg, sys_reg_sys_clken3_reg.regValue);
		// enable memc_in interrupt
		IoReg_SetBits(0xb8099018, _BIT25);
		// enable memc_out interrupt
		IoReg_SetBits(0xb809d008, _BIT6);
	}
#endif
}

void Scaler_MEMC_Mux_off(void){
	//MEMC mux
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;

	//MEMC mux enable
	#ifdef CONFIG_HW_SUPPORT_MEMC
	drvif_memc_mux_en(FALSE);
	#endif

	//DTG MEMC MUX control
	memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	memc_mux_ctrl_reg.memc_outmux_sel = 0;
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
}

void Scaler_MEMC_Bypass_On(unsigned char b_isBypass){
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	unsigned int count = 100;

#ifdef CONFIG_MEMC_BYPASS
	return;
#endif

	ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;
	ppoverlay_double_buffer_ctrl2_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);

	rtd_printk(KERN_EMERG, "VPQ","Scaler_MEMC_Bypass_On (%d)\n", b_isBypass);
	memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	if(b_isBypass)
		memc_mux_ctrl_reg.memc_outmux_sel = 0;
	else
		memc_mux_ctrl_reg.memc_outmux_sel = 1;
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
	//set apply
	ppoverlay_double_buffer_ctrl2_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_set = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);

	while((ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_set)&& --count){
		ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		msleep(10);
	}
}

unsigned char Scaler_MEMC_get_Bypass_Status(void)
{
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	if(memc_mux_ctrl_reg.memc_outmux_sel)
		return FALSE;
	else
		return TRUE;
}


void Scaler_MEMC_allocate_memory(void){
	//unsigned int vir_addr;/*, phy_addr_kme, phy_addr_kmc00, phy_addr_kmc01;*/
#if 1

	unsigned int memc_size = 0;
	unsigned int memc_addr = 0;
	memc_size = carvedout_buf_query(CARVEDOUT_SCALER_MEMC, &memc_addr);
        if (memc_addr == 0 || memc_size == 0) {
                rtd_printk(KERN_EMERG, TAG_NAME,"[%s %d] ERR : %x %x\n", __func__, __LINE__, memc_addr, memc_size);
                return;
        }


	gphy_addr_kme = memc_addr;
	gphy_addr_kmc00 = gphy_addr_kme + KME_TOTAL_SIZE;
	gphy_addr_kmc01 = gphy_addr_kmc00 + MEMC_KMC_00_START_TOTAL_SIZE;
	rtd_printk(KERN_EMERG, TAG_NAME, "KMC00 start address = %x\n", gphy_addr_kmc00);
	rtd_printk(KERN_EMERG, TAG_NAME, "KMC01 start address = %x\n", gphy_addr_kmc01);

	if(KME_TOTAL_SIZE > memc_size){
		rtd_printk(KERN_EMERG, TAG_NAME, "[KME_TOTAL_SIZE] setting error");
		return;
	}


#ifdef CONFIG_HW_SUPPORT_MEMC
	//ME memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Me_downlimit_addr_reg, gphy_addr_kme);
	IoReg_Write32(MEMC_DBUS_WRAP_Me_uplimit_addr_reg, (gphy_addr_kme + KME_TOTAL_SIZE));
	//MC memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_downlimit_addr_reg, gphy_addr_kmc00);
	//IoReg_Write32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg, (gphy_addr_kmc00 + KMC_TOTAL_SIZE));
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg, (gphy_addr_kme + memc_size));
#endif
#else
	unsigned char	*m_pCacheStartAddr_kme = NULL;
	unsigned int 	m_allocate_memory_kme = 0;
	unsigned char	*m_pCacheStartAddr_kmc00 = NULL;
	unsigned int 	m_allocate_memory_kmc00 = 0;

	rtd_printk(KERN_ERR, TAG_NAME, "+++Scaler_MEMC_allocate_memory+++\n");

	m_pCacheStartAddr_kme = (unsigned char *)dvr_malloc_specific(KME_TOTAL_SIZE, GFP_DCU2_FIRST);
	if(m_pCacheStartAddr_kme == NULL){
	rtd_printk(KERN_ERR, TAG_NAME, "[ERROR]Allocate DCU2 size=%x fail\n",KME_TOTAL_SIZE);
	BUG();//add kernel crash function when cma not enough
	return FALSE;
	}
	m_allocate_memory_kme = (unsigned int)dvr_to_phys((void*)m_pCacheStartAddr_kme);

	m_pCacheStartAddr_kmc00 = (unsigned char *)dvr_malloc_specific(KMC_TOTAL_SIZE, GFP_DCU2_FIRST);
	if(m_pCacheStartAddr_kmc00 == NULL){
	rtd_printk(KERN_ERR, TAG_NAME, "[ERROR]Allocate DCU2 size=%x fail\n",KMC_TOTAL_SIZE);
	BUG();//add kernel crash function when cma not enough
	return FALSE;
	}
	m_allocate_memory_kmc00 = (unsigned int)dvr_to_phys((void*)m_pCacheStartAddr_kmc00);

	gphy_addr_kme = m_allocate_memory_kme;
	gphy_addr_kmc00 = m_allocate_memory_kmc00;
	gphy_addr_kmc01 = gphy_addr_kmc00 + MEMC_KMC_00_START_TOTAL_SIZE;

	//ME memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Me_downlimit_addr_reg, gphy_addr_kme);
	IoReg_Write32(MEMC_DBUS_WRAP_Me_uplimit_addr_reg, (gphy_addr_kme + KME_TOTAL_SIZE));
	//MC memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_downlimit_addr_reg, gphy_addr_kmc00);
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg, (gphy_addr_kmc00 + KMC_TOTAL_SIZE));

	rtd_printk(KERN_NOTICE, TAG_NAME,  "KME_TOTAL_SIZE=%x\n", KME_TOTAL_SIZE);
	rtd_printk(KERN_NOTICE, TAG_NAME,  "KMC_TOTAL_SIZE=%x\n", KMC_TOTAL_SIZE);
	rtd_printk(KERN_NOTICE, TAG_NAME,  "MEMC_KMC_00_START_TOTAL_SIZE=%x\n", MEMC_KMC_00_START_TOTAL_SIZE);
	rtd_printk(KERN_NOTICE, TAG_NAME,  "MEMC_KMC_01_START_TOTAL_SIZE=%x\n", MEMC_KMC_01_START_TOTAL_SIZE);

	rtd_printk(KERN_NOTICE, TAG_NAME,  "gphy_addr_kme=%x\n", gphy_addr_kme);
	rtd_printk(KERN_NOTICE, TAG_NAME,  "gphy_addr_kmc00=%x\n", gphy_addr_kmc00);
	rtd_printk(KERN_NOTICE, TAG_NAME,  "gphy_addr_kmc01=%x\n", gphy_addr_kmc01);
#endif

}

void Scaler_MEMC_initial_Case(void){
	// MEMC 4k60 in, 4k60 out
	int ret;
	SCALER_MEMC_DMASTARTADDRESS_T* memc_dma_address_info;
	unsigned int ulCount = 0;
	VPQ_MEMC_INPUT_FORMAT input_format;
	VPQ_MEMC_OUTPUT_FORMAT output_format;
	ppoverlay_memcdtg_dv_den_start_end_RBUS memcdtg_dv_den_start_end_reg;

	memcdtg_dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg);
#ifdef CONFIG_MEMC_BYPASS
	//memcdtg_dv_den_start_end_reg.memcdtg_dv_den_sta = Get_DISP_DEN_STA_VPOS();
	//memcdtg_dv_den_start_end_reg.memcdtg_dv_den_end = Get_DISP_DEN_END_VPOS();
	return;
#else // memcdtg start position should sync to MEMC HW
	memcdtg_dv_den_start_end_reg.memcdtg_dv_den_sta = 45;
	memcdtg_dv_den_start_end_reg.memcdtg_dv_den_end = 2205;
#endif
	IoReg_Write32(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg, memcdtg_dv_den_start_end_reg.regValue);

	fw_scaler_dtg_double_buffer_apply();

	//MEMC CLK Init
	Scaler_MEMC_CLK();
	memc_dma_address_info = (SCALER_MEMC_DMASTARTADDRESS_T*)Scaler_GetShareMemVirAddr(SCALERIOC_MEMC_INITIALIZATION);
	ulCount = sizeof(SCALER_MEMC_DMASTARTADDRESS_T) / sizeof(unsigned int);

	memc_dma_address_info->ME_start_addr= gphy_addr_kme;
	memc_dma_address_info->MC00_start_addr = gphy_addr_kmc00;
	memc_dma_address_info->MC01_start_addr = gphy_addr_kmc01;
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	//change endian
	memc_dma_address_info->ME_start_addr = htonl(memc_dma_address_info->ME_start_addr);
	memc_dma_address_info->MC00_start_addr = htonl(memc_dma_address_info->MC00_start_addr);
	memc_dma_address_info->MC01_start_addr = htonl(memc_dma_address_info->MC01_start_addr);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_INITIALIZATION, 0, 0))){
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]ret=%d, SCALERIOC_MEMC_INITIALIZATION RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	Scaler_MEMC_Initialize(memc_dma_address_info->ME_start_addr, memc_dma_address_info->MC00_start_addr, memc_dma_address_info->MC01_start_addr);
#else
	//change endian
	memc_dma_address_info->ME_start_addr = htonl(memc_dma_address_info->ME_start_addr);
	memc_dma_address_info->MC00_start_addr = htonl(memc_dma_address_info->MC00_start_addr);
	memc_dma_address_info->MC01_start_addr = htonl(memc_dma_address_info->MC01_start_addr);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_INITIALIZATION, 0, 0))){
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]ret=%d, SCALERIOC_MEMC_INITIALIZATION RPC fail !!!\n", ret);
	}
#endif
#endif
	input_format = VPQ_INPUT_2D;
	output_format = VPQ_OUTPUT_2D;
	//set MEMC in,out use case
	Scaler_MEMC_SetInOutUseCase(VPQ_INPUT_3840X2160, VPQ_OUTPUT_3840X2160, input_format, output_format);
	//set MEMC in/out frame rate
	Scaler_MEMC_SetInOutFrameRate();
}

unsigned char Get_MEMC_Enable_Dynamic(void);

/*api which have protect by forcebg_semaphore*/
void Scaler_MEMC_fbg_control(void){
	if(MEMC_First_Run_FBG_enable == _ENABLE){
		msleep(50);
		Scaler_MEMC_output_force_bg_enable(FALSE);
		MEMC_First_Run_FBG_enable = _DISABLE;
		pr_notice("[MEMC]MEMC_First_Run_FBG_enable disable FBG!!\n");
	}
	if(MEMC_instanboot_resume_Done == 1){
		msleep(50);
		Scaler_MEMC_output_force_bg_enable(FALSE);
		MEMC_instanboot_resume_Done = 0;
		pr_notice("[MEMC]MEMC_instanboot_resume_Done disable FBG!!\n");
	}
	if(MEMC_snashop_resume_Done == 1){
		Scaler_MEMC_output_force_bg_enable(FALSE);
		MEMC_snashop_resume_Done = 0;
		pr_notice("[MEMC]MEMC_snashop_resume_Done disable FBG!!\n");
	}
//set MEMC in, out frame rate
	//Scaler_MEMC_SetInOutFrameRate();//Can not send RPC here
	pr_notice("[MEMC]MEMC_instanboot_resume_Done = %d\n", MEMC_instanboot_resume_Done);
}

void Scaler_MEMC_Handler(){
	VPQ_MEMC_INPUT_FORMAT input_format;
	VPQ_MEMC_OUTPUT_FORMAT output_format;

	if(MEMC_First_Run_Done == 0){
		//memc initial RPC
		MEMC_First_Run_Done = 1;
		MEMC_First_Run_FBG_enable = _ENABLE;
		Scaler_MEMC_output_force_bg_enable(TRUE);
		Scaler_MEMC_initial_Case();
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]initial in handler!!\n");
	}
#if 0
	// 2D, 3D switch
	if((get_3D_mode_enable() == true) && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == true)){
		//K2L on support PR 3D
		input_format = VPQ_INPUT_3D_LBL;
		output_format = VPQ_OUTPUT_3D_PR;
	}
	else{
		input_format = VPQ_INPUT_2D;
		output_format = VPQ_OUTPUT_2D;
	}

#else
	input_format = VPQ_INPUT_2D;
	output_format = VPQ_OUTPUT_2D;
#endif

	if(MEMC_instanboot_resume_Done == 1){
		Scaler_MEMC_SetInOutUseCase(VPQ_INPUT_3840X2160, VPQ_OUTPUT_3840X2160, VPQ_INPUT_3D_LBL, VPQ_OUTPUT_3D_PR);
		//msleep(100);//Remove by Will for performance
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]reset usecase (instanboot)!!\n");
	}
	//MEMC mux
	Scaler_MEMC_Mux();
	//set MEMC in,out use case
	Scaler_MEMC_SetInOutUseCase(VPQ_INPUT_3840X2160, VPQ_OUTPUT_3840X2160, input_format, output_format);

	//Instanboot to initial phase table
	if(MEMC_instanboot_resume_Done == 1){
		Scaler_MEMC_Instanboot_InitPhaseTable(1);
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]initial phase table (instanboot)!!\n");
	}
	//set MEMC in, out frame rate
	//Scaler_MEMC_SetInOutFrameRate();//Move after disable force bg

	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]Scaler_MEMC_Handler Done!!\n");
}
#ifdef MEMC_DYNAMIC_ONOFF
void Scaler_ME_OnOff(UINT8 enable)
{
	unsigned int enable_bit;
	if(enable == TRUE)
		enable_bit = 0x00100000;
	else
		enable_bit = 0x0;



	IoReg_Mask32(me_00_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_01_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_02_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_03_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_04_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_05_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_06_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_07_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_08_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_09_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_10_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_11_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_12_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_13_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_14_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(me_15_read_enable_ADDR, 0xffefffff, enable_bit);
}

void Scaler_MC_OnOff(UINT8 enable){
	unsigned int enable_bit;
	if(enable == TRUE)
		enable_bit = 0x00100000;
	else
		enable_bit = 0x0;

	IoReg_Mask32(mc_00_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_00_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_01_write_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_02_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_03_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_04_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_05_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_06_read_enable_ADDR, 0xffefffff, enable_bit);
	IoReg_Mask32(mc_07_read_enable_ADDR, 0xffefffff, enable_bit);
}

static UINT8 no_signal_MEMC_outputbg_check = 0;
void Scaler_MEMC_Booting_NoSignal_Check_OutputBG(UINT8 enable){
	//check MEMC out bg when not run scaler
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS memc_double_buffer_ctrl_reg;
	memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);

	//add checking no signal status @Crixus 20160112
	if(Scaler_MEMC_Get_First_Run_FBG_enable() || Scaler_MEMC_Get_instanboot_resume_Done() || Scaler_MEMC_Get_snashop_resume_Done()){
		if((enable == 0) && (memc_mux_ctrl_reg.memc_out_bg_en == 1)){
			memc_mux_ctrl_reg.memc_out_bg_en = 0;
			no_signal_MEMC_outputbg_check = 1;
			Scaler_MEMC_Handler();
//			memc_mux_ctrl_reg.memcdtg_golden_vs = 0; // Mac5p fix me
			pr_notice("\r\n####[MEMC]No signal and disable MEMC out bg\n");
		}
		else{
			if(no_signal_MEMC_outputbg_check == 1){
				if((enable == 1) && (memc_mux_ctrl_reg.memc_out_bg_en == 0)){
					memc_mux_ctrl_reg.memc_out_bg_en = 1;
//					memc_mux_ctrl_reg.memcdtg_golden_vs = 1; // Mac5p fix me
					no_signal_MEMC_outputbg_check = 0;
					pr_notice("\r\n####[MEMC]No signal and enable MEMC out bg\n");
				}
			}
		}
		IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);

		//set apply
		memc_double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
		memc_double_buffer_ctrl_reg.uzudtgreg_dbuf_set = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, memc_double_buffer_ctrl_reg.regValue);
	}
}


static UINT8 MEMC_Dynamic_OnOff = 1;//default MEMC enable
extern VSC_INPUT_TYPE_T Get_DisplayMode_Src(unsigned char display);
extern unsigned char rtk_run_scaler(unsigned char display, VSC_INPUT_TYPE_T inputType, VSC_OUTPUT_MODE_T outputMode);
void Scaler_MEMC_Dynamic_OnOff(){
	//MDOMAIN_CAP_Smooth_tog_ctrl_0_reg[1] => dummy bit to control dynamic MEMC on/off.

	//MEMC change to disable
	if((IoReg_Read32(MDOMAIN_CAP_Smooth_tog_ctrl_0_reg) & _BIT1) && (MEMC_Dynamic_OnOff == 1)){
		rtk_run_scaler(SLR_MAIN_DISPLAY, Get_DisplayMode_Src(SLR_MAIN_DISPLAY), VSC_OUTPUT_DISPLAY_MODE);
		Scaler_ME_OnOff(FALSE);
		Scaler_MC_OnOff(FALSE);
		Scaler_MEMC_Mux_off();
		MEMC_Dynamic_OnOff = 0;
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]Dynamic off!!!!\n");
	}
	//MEMC change to enable
	else if(!(IoReg_Read32(MDOMAIN_CAP_Smooth_tog_ctrl_0_reg) & _BIT1) && (MEMC_Dynamic_OnOff == 0)){
		rtk_run_scaler(SLR_MAIN_DISPLAY, Get_DisplayMode_Src(SLR_MAIN_DISPLAY), VSC_OUTPUT_DISPLAY_MODE);
		Scaler_ME_OnOff(TRUE);
		Scaler_MC_OnOff(TRUE);
		MEMC_Dynamic_OnOff = 1;
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]Dynamic on!!!!\n");
	}
}

UINT8 Scaler_MEMC_GetDynamicOnOff(void){
	return MEMC_Dynamic_OnOff;
}
#endif
/*api which have protect by forcebg_semaphore*/
void Scaler_MEMC_output_force_bg_enable(UINT8 enable){
	//MEMC enable, using MEMC out fbg
	ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl_reg;
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	UINT8 timeout = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME, "%s,MEMC out FBG = %d\n", __FUNCTION__, enable);
	//enable UZU DTG double buffer.
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 1;
	double_buffer_ctrl_reg.uzudtg_dbuf_vsync_sel = 3;//using uzudtg vsync
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
	//enable MEMC output fbg
	memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	memc_mux_ctrl_reg.memc_out_bg_en = enable;
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
	//set apply
	double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl_reg.uzudtgreg_dbuf_set = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
	double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);

	while(double_buffer_ctrl_reg.uzudtgreg_dbuf_set) {
		timeout++;
		msleep(10);
		double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
		if(timeout >= 5)
		break;
	}
	//disable UZU DTG double buffer.
	double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);
}

void Scaler_MEMC_set_output_bg_color(UINT16 color_r, UINT16 color_g, UINT16 color_b){
	ppoverlay_memc_mux_out1_color_value_gb_RBUS memc_mux_out1_color_value_gb_reg;
	ppoverlay_memc_mux_out1_color_value_r_RBUS memc_mux_out1_color_value_r_reg;

	memc_mux_out1_color_value_gb_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_GB_reg);
	memc_mux_out1_color_value_r_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_R_reg);

	memc_mux_out1_color_value_gb_reg.out_y_g_value = color_g;
	memc_mux_out1_color_value_gb_reg.out_cb_b_value = color_b;
	memc_mux_out1_color_value_r_reg.out_cr_r_value = color_r;

	IoReg_Write32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_GB_reg, memc_mux_out1_color_value_gb_reg.regValue);
	IoReg_Write32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_R_reg, memc_mux_out1_color_value_r_reg.regValue);
}

void Scaler_MEMC_SetMotionType(VPQ_MEMC_TYPE_T motion)
{
	MEMC_motion_type = motion;
}
VPQ_MEMC_TYPE_T Scaler_MEMC_GetMotionType(void)
{
	return MEMC_motion_type;
}
void Scaler_MEMC_Set_CheckMEMC_Outbg(unsigned char mode)
{
	AVD_Unstable_Check_MEMC_OutBG_flag = mode;
}
unsigned char Scaler_MEMC_Get_CheckMEMC_Outbg(void)
{
	return AVD_Unstable_Check_MEMC_OutBG_flag;
}
unsigned char Scaler_MEMC_Get_First_Run_FBG_enable(void)
{
	return MEMC_First_Run_FBG_enable;
}
unsigned char Scaler_MEMC_Get_instanboot_resume_Done(void)
{
	return MEMC_instanboot_resume_Done;
}
unsigned char Scaler_MEMC_Get_snashop_resume_Done(void)
{
	return MEMC_snashop_resume_Done;
}




int Scaler_MEMC_set_cinema_mode_en(unsigned char bEn)
{
	int ret = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]fwif_color_set_cinema_mode_en, bEn = %d\n", bEn);
#ifdef CONFIG_RTK_KDEV_DEBUG_ISR
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETCINEMAMODE, bEn, 1))){
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]ret=%d, SCALERIOC_MEMC_SETCINEMAMODE RPC fail !!!\n", ret);
	}
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	#ifndef CONFIG_MEMC_TASK_QUEUE
		if(!Scaler_MEMC_GetMEMC_Enable())
			return 0;
	Scaler_MEMC_SetCinemaMode(bEn);
#else
		SCALER_MEMC_TASK_T task;

		task.type = SCALERIOC_MEMC_SETCINEMAMODE;
		task.data.value = bEn;
		Scaler_MEMC_PushTask(&task);
	#endif
#else
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_MEMC_SETCINEMAMODE, bEn, 1))){
		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]ret=%d, SCALERIOC_MEMC_SETCINEMAMODE RPC fail !!!\n", ret);
	}
#endif
#endif
	return ret;
}

BOOL ScalerMEMC_EnablePowerSave(void)
{

	_clues* SmartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	_RPC_clues* RPC_SmartPic_clue = (_RPC_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_SMARTPIC_CLUS);

	if(SmartPic_clue == NULL || RPC_SmartPic_clue == NULL)
		return 1;

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	if(RPC_SmartPic_clue->prePowerSaveStatus == PS_OFF)
	{
		if(Scaler_MEMC_SetPowerSaveOn())
			return 1;

		if(Scaler_MEMC_GetMEMC_Mode() != MEMC_OFF)
		{
			Scaler_MEMC_SetMEMCFrameRepeatEnable(1);
		}

		RPC_SmartPic_clue->prePowerSaveStatus = PS_ON;
	}

	return 0;
#else
	if(RPC_SmartPic_clue->prePowerSaveStatus == PS_OFF)
	{
		//sendRPC TBD..
	}
#endif

}

BOOL ScalerMEMC_DisablePowerSave(void)
{

	_clues* SmartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	_RPC_clues* RPC_SmartPic_clue = (_RPC_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_SMARTPIC_CLUS);

	if(SmartPic_clue == NULL || RPC_SmartPic_clue==NULL)
		return 1;

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	if(RPC_SmartPic_clue->prePowerSaveStatus == PS_ON)
	{
		if(Scaler_MEMC_SetPowerSaveOff())
			return 1;

		if(Scaler_MEMC_GetMEMC_Mode() != MEMC_OFF)
		{
			Scaler_MEMC_SetMEMCFrameRepeatEnable(0);
		}

		RPC_SmartPic_clue->prePowerSaveStatus = PS_OFF;
	}

	return 0;
#else
	if(RPC_SmartPic_clue->prePowerSaveStatus == PS_ON)
	{
		//sendRPC TBD..
	}
#endif

}
/*******************************************************************************
****************************VPQ MEMC DEVICE************************************
*******************************************************************************/
#ifdef CONFIG_PM
static int vpq_memc_suspend (struct device *p_dev)
{
	return 0;
}

static int vpq_memc_resume (struct device *p_dev)
{

	return 0;
}

VPQ_MEMC_SUSPEND_RESUME_T vpq_memc_suspend_resume;
void vpq_memc_disp_suspend_snashop(void){

#ifdef CONFIG_HW_SUPPORT_MEMC

	//MEMC mux
	vpq_memc_suspend_resume.MEMC_MUX_MEMC_MUX_FUNC_CTRL_SUSPEND = IoReg_Read32(MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg);
	//FBG
	vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	//clock
	vpq_memc_suspend_resume.SYS_REG_SYS_DISPCLKSEL_SUSPEND = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	vpq_memc_suspend_resume.MEMC_LATENCY01 = IoReg_Read32(MEMC_LATENCY01_ADDR);
	vpq_memc_suspend_resume.MEMC_LATENCY02 = IoReg_Read32(MEMC_LATENCY02_ADDR);

	//ME memory boundary
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_DOWNLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Me_downlimit_addr_reg);
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_UPLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Me_uplimit_addr_reg);
	//MC memory boundary
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_DOWNLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Mc_downlimit_addr_reg);
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_UPLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg);
#endif
}

void vpq_memc_disp_resume_snashop(void){
#ifdef CONFIG_HW_SUPPORT_MEMC

	ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl2_reg;
	int timeout = 0xff;

	//MEMC mux
	IoReg_Write32(MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg, vpq_memc_suspend_resume.MEMC_MUX_MEMC_MUX_FUNC_CTRL_SUSPEND);
	//FBG
	double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 1;
	double_buffer_ctrl2_reg.uzudtg_dbuf_vsync_sel = 3;
	//enable double buffer
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl2_reg.regValue);

	vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND = vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND | 0x00001000;
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND);

	double_buffer_ctrl2_reg.uzudtgreg_dbuf_set = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl2_reg.regValue);
	//wait double buffer done
	double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	while(double_buffer_ctrl2_reg.uzudtgreg_dbuf_set && timeout--){
		double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
		mdelay(1);
	}
	//disable double buffer
	double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl2_reg.regValue);

	//clock
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, vpq_memc_suspend_resume.SYS_REG_SYS_DISPCLKSEL_SUSPEND);
	IoReg_Write32(MEMC_LATENCY01_ADDR, vpq_memc_suspend_resume.MEMC_LATENCY01);
	IoReg_Write32(MEMC_LATENCY02_ADDR, vpq_memc_suspend_resume.MEMC_LATENCY02);

	//ME memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Me_downlimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_DOWNLIMIT);
	IoReg_Write32(MEMC_DBUS_WRAP_Me_uplimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_UPLIMIT);
	//MC memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_downlimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_DOWNLIMIT);
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_UPLIMIT);

	MEMC_snashop_resume_Done = 1;
	rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]Snashop Resume done !!!\n");
#endif

}

void vpq_memc_disp_suspend_instanboot(void){


	#ifdef CONFIG_HW_SUPPORT_MEMC
	// disable interrupt
	UINT32 u32_interrupt_reg = 0;
	//reg_kmc_int_en
	u32_interrupt_reg = IoReg_Read32(KMC_TOP__KMC_IN_INT_CTRL_ADDR);
	u32_interrupt_reg &= 0xf0ffffff;
	IoReg_Write32(KMC_TOP__KMC_IN_INT_CTRL_ADDR, u32_interrupt_reg);

	//reg_post_int_en
	u32_interrupt_reg = IoReg_Read32(KPOST_TOP__POST_INT_CTRL_ADDR);
	u32_interrupt_reg &= 0xfffffe1f;
	IoReg_Write32(KPOST_TOP__POST_INT_CTRL_ADDR, u32_interrupt_reg);

	//KMC_TOP
	vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_TOTAL = IoReg_Read32(KMC_TOP__TOP_PATT_TOTAL_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_ACT = IoReg_Read32(KMC_TOP__TOP_PATT_ACT_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_WIDTH_BPORCH = IoReg_Read32(KMC_TOP__TOP_PATT_WIDTH_BPORCH_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_CTRL = IoReg_Read32(KMC_TOP__TOP_PATT_CTRL_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_RGB0 = IoReg_Read32(KMC_TOP__TOP_PATT_RGB0_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_RGB1 = IoReg_Read32(KMC_TOP__TOP_PATT_RGB1_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_IN_INT_CTRL = IoReg_Read32(KMC_TOP__KMC_IN_INT_CTRL_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_METER_DETIAL_CORING0 = IoReg_Read32(KMC_TOP__KMC_METER_DETIAL_CORING0_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_VH_DETAIL_MODE = IoReg_Read32(KMC_TOP__KMC_VH_DETAIL_MODE_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_VH_DETAIL_TH = IoReg_Read32(KMC_TOP__KMC_VH_DETAIL_TH_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_METER_DETIAL_CORING1 = IoReg_Read32(KMC_TOP__KMC_METER_DETIAL_CORING1_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_METER_DETIAL_CORING2 = IoReg_Read32(KMC_TOP__KMC_METER_DETIAL_CORING2_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_ACTIVE_NUM = IoReg_Read32(KMC_TOP__KNR_ACTIVE_NUM_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_BPORCH_NUM = IoReg_Read32(KMC_TOP__KNR_BPORCH_NUM_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_IPMC0 = IoReg_Read32(KMC_TOP__KMC_IPMC0_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_IPMC1 = IoReg_Read32(KMC_TOP__KMC_IPMC1_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF0 = IoReg_Read32(KMC_TOP__KNR_CSC_COEF0_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF1 = IoReg_Read32(KMC_TOP__KNR_CSC_COEF1_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF2 = IoReg_Read32(KMC_TOP__KNR_CSC_COEF2_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF3 = IoReg_Read32(KMC_TOP__KNR_CSC_COEF3_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF4 = IoReg_Read32(KMC_TOP__KNR_CSC_COEF4_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF5 = IoReg_Read32(KMC_TOP__KNR_CSC_COEF5_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_0 = IoReg_Read32(KMC_TOP__KMC_DRF_BIST_IN_0_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_1 = IoReg_Read32(KMC_TOP__KMC_DRF_BIST_IN_1_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_2 = IoReg_Read32(KMC_TOP__KMC_DRF_BIST_IN_2_ADDR);
	vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_3 = IoReg_Read32(KMC_TOP__KMC_DRF_BIST_IN_3_ADDR);
	//IPPRE
	vpq_memc_suspend_resume.IPPRE__INPUT_CURSOR = IoReg_Read32(IPPRE__INPUT_CURSOR_ADDR);
	vpq_memc_suspend_resume.IPPRE__INPUT_CURSOR_UV = IoReg_Read32(IPPRE__INPUT_CURSOR_UV_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_RETIMING = IoReg_Read32(IPPRE__IPPRE_RETIMING_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOGO_BLEND = IoReg_Read32(IPPRE__LOGO_BLEND_ADDR);
	vpq_memc_suspend_resume.IPPRE__PATT_HV_ACTIVE = IoReg_Read32(IPPRE__PATT_HV_ACTIVE_ADDR);
	vpq_memc_suspend_resume.IPPRE__PATT_HV_TOTAL = IoReg_Read32(IPPRE__PATT_HV_TOTAL_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_444TO422_COEF0 = IoReg_Read32(IPPRE__IPPRE_444TO422_COEF0_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_444TO422_COEF1 = IoReg_Read32(IPPRE__IPPRE_444TO422_COEF1_ADDR);
	vpq_memc_suspend_resume.IPPRE__PATT_MODE_CTRL = IoReg_Read32(IPPRE__PATT_MODE_CTRL_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_SEQUENCY = IoReg_Read32(IPPRE__LOOP_PATT_SEQUENCY_ADDR);
	vpq_memc_suspend_resume.IPPRE__PATT_PARA_0 = IoReg_Read32(IPPRE__PATT_PARA_0_ADDR);
	vpq_memc_suspend_resume.IPPRE__PATT_PARA_1 = IoReg_Read32(IPPRE__PATT_PARA_1_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA0 = IoReg_Read32(IPPRE__LOOP_PATT_PARA0_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA1 = IoReg_Read32(IPPRE__LOOP_PATT_PARA1_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA2 = IoReg_Read32(IPPRE__LOOP_PATT_PARA2_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA3 = IoReg_Read32(IPPRE__LOOP_PATT_PARA3_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA4 = IoReg_Read32(IPPRE__LOOP_PATT_PARA4_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA5 = IoReg_Read32(IPPRE__LOOP_PATT_PARA5_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA6 = IoReg_Read32(IPPRE__LOOP_PATT_PARA6_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA7 = IoReg_Read32(IPPRE__LOOP_PATT_PARA7_ADDR);
	vpq_memc_suspend_resume.IPPRE__LOOP_SCROLL_CTRL = IoReg_Read32(IPPRE__LOOP_SCROLL_CTRL_ADDR);
	vpq_memc_suspend_resume.IPPRE__SCROLL_BAR_HV = IoReg_Read32(IPPRE__SCROLL_BAR_HV_ADDR);
	vpq_memc_suspend_resume.IPPRE__SCROLL_BAR_COLOR = IoReg_Read32(IPPRE__SCROLL_BAR_COLOR_ADDR);
	vpq_memc_suspend_resume.IPPRE__SPEED_HV_1 = IoReg_Read32(IPPRE__SPEED_HV_1_ADDR);
	vpq_memc_suspend_resume.IPPRE__CIRCLE_CADENCE = IoReg_Read32(IPPRE__CIRCLE_CADENCE_ADDR);
	vpq_memc_suspend_resume.IPPRE__CIRCLE_CENTER = IoReg_Read32(IPPRE__CIRCLE_CENTER_ADDR);
	vpq_memc_suspend_resume.IPPRE__RANDOM_SEED = IoReg_Read32(IPPRE__RANDOM_SEED_ADDR);
	vpq_memc_suspend_resume.IPPRE__RANDOM_CTRL = IoReg_Read32(IPPRE__RANDOM_CTRL_ADDR);
	vpq_memc_suspend_resume.IPPRE__CADENCE_FRM = IoReg_Read32(IPPRE__CADENCE_FRM_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF0_H = IoReg_Read32(IPPRE__CSC_COEF0_H_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF1_H = IoReg_Read32(IPPRE__CSC_COEF1_H_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF2_H = IoReg_Read32(IPPRE__CSC_COEF2_H_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF3_H = IoReg_Read32(IPPRE__CSC_COEF3_H_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF4_H = IoReg_Read32(IPPRE__CSC_COEF4_H_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF5_H = IoReg_Read32(IPPRE__CSC_COEF5_H_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF0_L = IoReg_Read32(IPPRE__CSC_COEF0_L_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF1_L = IoReg_Read32(IPPRE__CSC_COEF1_L_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF2_L = IoReg_Read32(IPPRE__CSC_COEF2_L_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF3_L = IoReg_Read32(IPPRE__CSC_COEF3_L_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF4_L = IoReg_Read32(IPPRE__CSC_COEF4_L_ADDR);
	vpq_memc_suspend_resume.IPPRE__CSC_COEF5_L = IoReg_Read32(IPPRE__CSC_COEF5_L_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G4 = IoReg_Read32(IPPRE__IPPRE_MUTE_G4_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN0 = IoReg_Read32(IPPRE__HPATTERN0_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN1 = IoReg_Read32(IPPRE__HPATTERN1_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN2 = IoReg_Read32(IPPRE__HPATTERN2_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN3 = IoReg_Read32(IPPRE__HPATTERN3_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN4 = IoReg_Read32(IPPRE__HPATTERN4_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN5 = IoReg_Read32(IPPRE__HPATTERN5_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN6 = IoReg_Read32(IPPRE__HPATTERN6_ADDR);
	vpq_memc_suspend_resume.IPPRE__HPATTERN7 = IoReg_Read32(IPPRE__HPATTERN7_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G0 = IoReg_Read32(IPPRE__IPPRE_MUTE_G0_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G1 = IoReg_Read32(IPPRE__IPPRE_MUTE_G1_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G2 = IoReg_Read32(IPPRE__IPPRE_MUTE_G2_ADDR);
	vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G3 = IoReg_Read32(IPPRE__IPPRE_MUTE_G3_ADDR);
	//KMC_CPR_TOP0
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL0_REG = IoReg_Read32(KMC_CPR_TOP0__CPR_CTRL0_REG_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL1_REG = IoReg_Read32(KMC_CPR_TOP0__CPR_CTRL1_REG_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL2_REG = IoReg_Read32(KMC_CPR_TOP0__CPR_CTRL2_REG_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL3_REG = IoReg_Read32(KMC_CPR_TOP0__CPR_CTRL3_REG_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL4_REG = IoReg_Read32(KMC_CPR_TOP0__CPR_CTRL4_REG_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_PACKET = IoReg_Read32(KMC_CPR_TOP0__BUDGET_PACKET_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_INIT_START = IoReg_Read32(KMC_CPR_TOP0__BUDGET_INIT_START_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_INIT_END = IoReg_Read32(KMC_CPR_TOP0__BUDGET_INIT_END_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG0 = IoReg_Read32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG1 = IoReg_Read32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG2 = IoReg_Read32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG3 = IoReg_Read32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG3_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP3 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP3_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP4 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP4_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP5 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP5_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP6 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP6_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP7 = IoReg_Read32(KMC_CPR_TOP0__CURVE_QBPP7_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC0_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC0_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC1_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC1_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC2_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC2_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC3_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC3_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC4_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC4_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC5_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC5_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC6_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC6_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC7_VAR0 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC7_VAR0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC0_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC0_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC1_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC1_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC2_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC2_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC3_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC3_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC4_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC4_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC5_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC5_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC6_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC6_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC7_VAR1 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC7_VAR1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC0_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC0_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC1_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC1_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC2_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC2_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC3_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC3_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC4_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC4_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC5_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC5_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC6_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC6_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC7_VAR2 = IoReg_Read32(KMC_CPR_TOP0__CURVE_TRUNC7_VAR2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CORE_DELAY_CTRL_I = IoReg_Read32(KMC_CPR_TOP0__CORE_DELAY_CTRL_I_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CORE_DELAY_CTRL_P = IoReg_Read32(KMC_CPR_TOP0__CORE_DELAY_CTRL_P_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CORE_DELAY_CTRL_NR = IoReg_Read32(KMC_CPR_TOP0__CORE_DELAY_CTRL_NR_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_EROSION_RATIO = IoReg_Read32(KMC_CPR_TOP0__CPR_EROSION_RATIO_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_MOTION_DIFF_THD = IoReg_Read32(KMC_CPR_TOP0__CPR_MOTION_DIFF_THD_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_VARIANCE_CHECK_THD = IoReg_Read32(KMC_CPR_TOP0__CPR_LF_VARIANCE_CHECK_THD_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_VARIANCE_CHECK_THD = IoReg_Read32(KMC_CPR_TOP0__CPR_HF_VARIANCE_CHECK_THD_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL0 = IoReg_Read32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL1 = IoReg_Read32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL2 = IoReg_Read32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL3 = IoReg_Read32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL3_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL0 = IoReg_Read32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL1 = IoReg_Read32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL2 = IoReg_Read32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL2_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL3 = IoReg_Read32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL3_ADDR);
	//KMC_CPR_TOP1
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_CTRL0 = IoReg_Read32(KMC_CPR_TOP1__PATT_CTRL0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_I_POSITION0 = IoReg_Read32(KMC_CPR_TOP1__PATT_LF_I_POSITION0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_I_POSITION1 = IoReg_Read32(KMC_CPR_TOP1__PATT_LF_I_POSITION1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_I_POSITION0 = IoReg_Read32(KMC_CPR_TOP1__PATT_HF_I_POSITION0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_I_POSITION1 = IoReg_Read32(KMC_CPR_TOP1__PATT_HF_I_POSITION1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING0 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING1 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING0 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING1 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_P_POSITION0 = IoReg_Read32(KMC_CPR_TOP1__PATT_LF_P_POSITION0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_P_POSITION1 = IoReg_Read32(KMC_CPR_TOP1__PATT_LF_P_POSITION1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_P_POSITION0 = IoReg_Read32(KMC_CPR_TOP1__PATT_HF_P_POSITION0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_P_POSITION1 = IoReg_Read32(KMC_CPR_TOP1__PATT_HF_P_POSITION1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING0 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING1 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING0 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING1 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_NR_POSITION0 = IoReg_Read32(KMC_CPR_TOP1__PATT_LF_NR_POSITION0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_NR_POSITION1 = IoReg_Read32(KMC_CPR_TOP1__PATT_LF_NR_POSITION1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_NR_POSITION0 = IoReg_Read32(KMC_CPR_TOP1__PATT_HF_NR_POSITION0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_NR_POSITION1 = IoReg_Read32(KMC_CPR_TOP1__PATT_HF_NR_POSITION1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING0 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING1 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING0 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING0_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING1 = IoReg_Read32(KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING1_ADDR);
	vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_DEBUG_CFG0 = IoReg_Read32(KMC_CPR_TOP1__CPR_DEBUG_CFG0_ADDR);
	//KMC_DM_TOP
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS0 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS1 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS2 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS3 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS4 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS5 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS0 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS1 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS2 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS3 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS4 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS5 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_LR_OFFSET_ADDR = IoReg_Read32(KMC_DM_TOP__KMC_00_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_LINE_OFFSET_ADDR = IoReg_Read32(KMC_DM_TOP__KMC_00_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_00_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_00_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS0 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS1 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS2 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS3 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS4 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS5 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS0 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS1 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS2 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS3 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS4 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS5 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_LR_OFFSET_ADDR = IoReg_Read32(KMC_DM_TOP__KMC_01_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_LINE_OFFSET_ADDR = IoReg_Read32(KMC_DM_TOP__KMC_01_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_01_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_01_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_02_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_02_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_02_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_02_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_03_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_03_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_03_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_03_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_04_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_04_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_04_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_04_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_05_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_05_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_05_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_05_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_06_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_06_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_06_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_06_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_07_AGENT = IoReg_Read32(KMC_DM_TOP__KMC_07_AGENT_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_07_THRESHOLD = IoReg_Read32(KMC_DM_TOP__KMC_07_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_VTOTAL_AND_TIMER = IoReg_Read32(KMC_DM_TOP__KMC_VTOTAL_AND_TIMER_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_HOLD_TIME_G0 = IoReg_Read32(KMC_DM_TOP__KMC_HOLD_TIME_G0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_HOLD_TIME_G1 = IoReg_Read32(KMC_DM_TOP__KMC_HOLD_TIME_G1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_SOURCE_MODE = IoReg_Read32(KMC_DM_TOP__KMC_SOURCE_MODE_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G0 = IoReg_Read32(KMC_DM_TOP__KMC_DEBUG_HEAD_G0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G1 = IoReg_Read32(KMC_DM_TOP__KMC_DEBUG_HEAD_G1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G2 = IoReg_Read32(KMC_DM_TOP__KMC_DEBUG_HEAD_G2_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G3 = IoReg_Read32(KMC_DM_TOP__KMC_DEBUG_HEAD_G3_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS6 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS6_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS6 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS6_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS7 = IoReg_Read32(KMC_DM_TOP__KMC_00_START_ADDRESS7_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS7 = IoReg_Read32(KMC_DM_TOP__KMC_00_END_ADDRESS7_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS6 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS6_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS6 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS6_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS7 = IoReg_Read32(KMC_DM_TOP__KMC_01_START_ADDRESS7_ADDR);
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS7 = IoReg_Read32(KMC_DM_TOP__KMC_01_END_ADDRESS7_ADDR);
	//MC
	vpq_memc_suspend_resume.MC__MISC = IoReg_Read32(MC__MISC_ADDR);
	vpq_memc_suspend_resume.MC__PXL_RESOLUTION = IoReg_Read32(MC__PXL_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.MC__BLK_SIZE = IoReg_Read32(MC__BLK_SIZE_ADDR);
	vpq_memc_suspend_resume.MC__BLK_RESOLUTION = IoReg_Read32(MC__BLK_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.MC__DE_FLICKER = IoReg_Read32(MC__DE_FLICKER_ADDR);
	vpq_memc_suspend_resume.MC__VER_LF_SR = IoReg_Read32(MC__VER_LF_SR_ADDR);
	vpq_memc_suspend_resume.MC__VER_HF_SR = IoReg_Read32(MC__VER_HF_SR_ADDR);
	vpq_memc_suspend_resume.MC__HOR_SR = IoReg_Read32(MC__HOR_SR_ADDR);
	vpq_memc_suspend_resume.MC__VER_RIM0 = IoReg_Read32(MC__VER_RIM0_ADDR);
	vpq_memc_suspend_resume.MC__HOR_RIM0 = IoReg_Read32(MC__HOR_RIM0_ADDR);
	vpq_memc_suspend_resume.MC__VER_RIM1 = IoReg_Read32(MC__VER_RIM1_ADDR);
	vpq_memc_suspend_resume.MC__HOR_RIM1 = IoReg_Read32(MC__HOR_RIM1_ADDR);
	vpq_memc_suspend_resume.MC__DW_CONTROL = IoReg_Read32(MC__DW_CONTROL_ADDR);
	vpq_memc_suspend_resume.MC__DW_V0 = IoReg_Read32(MC__DW_V0_ADDR);
	vpq_memc_suspend_resume.MC__DW_H0 = IoReg_Read32(MC__DW_H0_ADDR);
	vpq_memc_suspend_resume.MC__DW_V1 = IoReg_Read32(MC__DW_V1_ADDR);
	vpq_memc_suspend_resume.MC__DW_H1 = IoReg_Read32(MC__DW_H1_ADDR);
	vpq_memc_suspend_resume.MC__DW_V2 = IoReg_Read32(MC__DW_V2_ADDR);
	vpq_memc_suspend_resume.MC__DW_H2 = IoReg_Read32(MC__DW_H2_ADDR);
	vpq_memc_suspend_resume.MC__DW_V3 = IoReg_Read32(MC__DW_V3_ADDR);
	vpq_memc_suspend_resume.MC__DW_H3 = IoReg_Read32(MC__DW_H3_ADDR);
	vpq_memc_suspend_resume.MC__DW_V4 = IoReg_Read32(MC__DW_V4_ADDR);
	vpq_memc_suspend_resume.MC__DW_H4 = IoReg_Read32(MC__DW_H4_ADDR);
	vpq_memc_suspend_resume.MC__DW_V5 = IoReg_Read32(MC__DW_V5_ADDR);
	vpq_memc_suspend_resume.MC__DW_H5 = IoReg_Read32(MC__DW_H5_ADDR);
	vpq_memc_suspend_resume.MC__DW_V6 = IoReg_Read32(MC__DW_V6_ADDR);
	vpq_memc_suspend_resume.MC__DW_H6 = IoReg_Read32(MC__DW_H6_ADDR);
	vpq_memc_suspend_resume.MC__DW_V7 = IoReg_Read32(MC__DW_V7_ADDR);
	vpq_memc_suspend_resume.MC__DW_H7 = IoReg_Read32(MC__DW_H7_ADDR);
	vpq_memc_suspend_resume.MC__PT_PROC = IoReg_Read32(MC__PT_PROC_ADDR);
	vpq_memc_suspend_resume.MC__OCCL_PROC = IoReg_Read32(MC__OCCL_PROC_ADDR);
	vpq_memc_suspend_resume.MC__OBMC = IoReg_Read32(MC__OBMC_ADDR);
	vpq_memc_suspend_resume.MC__BLEND = IoReg_Read32(MC__BLEND_ADDR);
	vpq_memc_suspend_resume.MC__BLD_MV_DIFF_CURVE = IoReg_Read32(MC__BLD_MV_DIFF_CURVE_ADDR);
	vpq_memc_suspend_resume.MC__MC_SOBJ0 = IoReg_Read32(MC__MC_SOBJ0_ADDR);
	vpq_memc_suspend_resume.MC__MC_SOBJ1 = IoReg_Read32(MC__MC_SOBJ1_ADDR);
	vpq_memc_suspend_resume.MC__CURSOR0_POSI = IoReg_Read32(MC__CURSOR0_POSI_ADDR);
	vpq_memc_suspend_resume.MC__CURSOR0_COLOR = IoReg_Read32(MC__CURSOR0_COLOR_ADDR);
	vpq_memc_suspend_resume.MC__CURSOR1_POSI = IoReg_Read32(MC__CURSOR1_POSI_ADDR);
	vpq_memc_suspend_resume.MC__CURSOR1_COLOR = IoReg_Read32(MC__CURSOR1_COLOR_ADDR);
	vpq_memc_suspend_resume.MC__GRID = IoReg_Read32(MC__GRID_ADDR);
	vpq_memc_suspend_resume.MC__MC_FORCE_PHASE = IoReg_Read32(MC__MC_FORCE_PHASE_ADDR);
	vpq_memc_suspend_resume.MC__FORCE_MV = IoReg_Read32(MC__FORCE_MV_ADDR);
	vpq_memc_suspend_resume.MC__MC_FALSE_COLOR = IoReg_Read32(MC__MC_FALSE_COLOR_ADDR);
	vpq_memc_suspend_resume.MC__INTERNAL_DEBUG = IoReg_Read32(MC__INTERNAL_DEBUG_ADDR);
	//MC2
	vpq_memc_suspend_resume.MC2__OBMC_COEF0 = IoReg_Read32(MC2__OBMC_COEF0_ADDR);
	vpq_memc_suspend_resume.MC2__OBMC_COEF1 = IoReg_Read32(MC2__OBMC_COEF1_ADDR);
	vpq_memc_suspend_resume.MC2__OBMC_COEF2 = IoReg_Read32(MC2__OBMC_COEF2_ADDR);
	vpq_memc_suspend_resume.MC2__OBMC_COEF3 = IoReg_Read32(MC2__OBMC_COEF3_ADDR);
	vpq_memc_suspend_resume.MC2__OBMC_COEF4 = IoReg_Read32(MC2__OBMC_COEF4_ADDR);
	vpq_memc_suspend_resume.MC2__OBMC_COEF5 = IoReg_Read32(MC2__OBMC_COEF5_ADDR);
	vpq_memc_suspend_resume.MC2__OBMC_COEF6 = IoReg_Read32(MC2__OBMC_COEF6_ADDR);
	vpq_memc_suspend_resume.MC2__OBMC_COEF7 = IoReg_Read32(MC2__OBMC_COEF7_ADDR);
	vpq_memc_suspend_resume.MC2__MC_LOGO_CTRL = IoReg_Read32(MC2__MC_LOGO_CTRL_ADDR);
	vpq_memc_suspend_resume.MC2__MC_LOGO_BLK_NUM = IoReg_Read32(MC2__MC_LOGO_BLK_NUM_ADDR);
	vpq_memc_suspend_resume.MC2__MC_LOGO_PXL_NUM = IoReg_Read32(MC2__MC_LOGO_PXL_NUM_ADDR);
	vpq_memc_suspend_resume.MC2__MC_LOGO_LPF_COEF = IoReg_Read32(MC2__MC_LOGO_LPF_COEF_ADDR);
	vpq_memc_suspend_resume.MC2__MC_LOGO_ALPHA = IoReg_Read32(MC2__MC_LOGO_ALPHA_ADDR);
	vpq_memc_suspend_resume.MC2__MC_VAR_LPF0 = IoReg_Read32(MC2__MC_VAR_LPF0_ADDR);
	vpq_memc_suspend_resume.MC2__MC_VAR_LPF1 = IoReg_Read32(MC2__MC_VAR_LPF1_ADDR);
	vpq_memc_suspend_resume.MC2__MC_VAR_LPF2 = IoReg_Read32(MC2__MC_VAR_LPF2_ADDR);
	vpq_memc_suspend_resume.MC2__MC_VAR_LPF3 = IoReg_Read32(MC2__MC_VAR_LPF3_ADDR);
	vpq_memc_suspend_resume.MC2__MC_OCCL_DIA_V = IoReg_Read32(MC2__MC_OCCL_DIA_V_ADDR);
	vpq_memc_suspend_resume.MC2__MC_OCCL_DIA_C = IoReg_Read32(MC2__MC_OCCL_DIA_C_ADDR);
	vpq_memc_suspend_resume.MC2__MC_OCCL_DIA_H = IoReg_Read32(MC2__MC_OCCL_DIA_H_ADDR);
	vpq_memc_suspend_resume.MC2__MC_VAR17_LPF0 = IoReg_Read32(MC2__MC_VAR17_LPF0_ADDR);
	vpq_memc_suspend_resume.MC2__MC_VAR17_LPF1 = IoReg_Read32(MC2__MC_VAR17_LPF1_ADDR);
	vpq_memc_suspend_resume.MC2__MC_VAR17_LPF2 = IoReg_Read32(MC2__MC_VAR17_LPF2_ADDR);
	//LBMC
	vpq_memc_suspend_resume.LBMC__LBMC_SR0 = IoReg_Read32(LBMC__LBMC_SR0_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_SR1 = IoReg_Read32(LBMC__LBMC_SR1_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_SR2 = IoReg_Read32(LBMC__LBMC_SR2_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_SR3 = IoReg_Read32(LBMC__LBMC_SR3_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_SR4 = IoReg_Read32(LBMC__LBMC_SR4_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_SR5 = IoReg_Read32(LBMC__LBMC_SR5_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_DUMMY18 = IoReg_Read32(LBMC__LBMC_DUMMY18_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_DUMMY1C = IoReg_Read32(LBMC__LBMC_DUMMY1C_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_RESOLUTION = IoReg_Read32(LBMC__LBMC_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_MODE = IoReg_Read32(LBMC__LBMC_MODE_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_BLANKING_CTRL = IoReg_Read32(LBMC__LBMC_BLANKING_CTRL_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART0_N = IoReg_Read32(LBMC__LBMC_I_IDX_PART0_N_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART1_N = IoReg_Read32(LBMC__LBMC_I_IDX_PART1_N_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART2_N = IoReg_Read32(LBMC__LBMC_I_IDX_PART2_N_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART0_N = IoReg_Read32(LBMC__LBMC_P_IDX_PART0_N_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART1_N = IoReg_Read32(LBMC__LBMC_P_IDX_PART1_N_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART2_N = IoReg_Read32(LBMC__LBMC_P_IDX_PART2_N_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_HF_IDX_NUM_N = IoReg_Read32(LBMC__LBMC_HF_IDX_NUM_N_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART0_S = IoReg_Read32(LBMC__LBMC_I_IDX_PART0_S_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART1_S = IoReg_Read32(LBMC__LBMC_I_IDX_PART1_S_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART2_S = IoReg_Read32(LBMC__LBMC_I_IDX_PART2_S_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART0_S = IoReg_Read32(LBMC__LBMC_P_IDX_PART0_S_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART1_S = IoReg_Read32(LBMC__LBMC_P_IDX_PART1_S_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART2_S = IoReg_Read32(LBMC__LBMC_P_IDX_PART2_S_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_HF_IDX_NUM_S = IoReg_Read32(LBMC__LBMC_HF_IDX_NUM_S_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_FETCH_POINT_LF = IoReg_Read32(LBMC__LBMC_FETCH_POINT_LF_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_FETCH_POINT_HF = IoReg_Read32(LBMC__LBMC_FETCH_POINT_HF_ADDR);
	vpq_memc_suspend_resume.LBMC__LBMC_INFO_GET_NUM = IoReg_Read32(LBMC__LBMC_INFO_GET_NUM_ADDR);
	//BBD
	vpq_memc_suspend_resume.BBD__BBD_INPUT_THRESHOLD_CTRL = IoReg_Read32(BBD__BBD_INPUT_THRESHOLD_CTRL_ADDR);
	vpq_memc_suspend_resume.BBD__BBD_INPUT_H_THRESHOLD_CTRL = IoReg_Read32(BBD__BBD_INPUT_H_THRESHOLD_CTRL_ADDR);
	vpq_memc_suspend_resume.BBD__BBD_INPUT_V_THRESHOLD_CTRL = IoReg_Read32(BBD__BBD_INPUT_V_THRESHOLD_CTRL_ADDR);
	vpq_memc_suspend_resume.BBD__BBD_WINDOW_START_POINT = IoReg_Read32(BBD__BBD_WINDOW_START_POINT_ADDR);
	vpq_memc_suspend_resume.BBD__BBD_WINDOW_END_POINT = IoReg_Read32(BBD__BBD_WINDOW_END_POINT_ADDR);
	//KMC_METER_TOP
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_YUV_X_POS = IoReg_Read32(KMC_METER_TOP__KMC_METER_YUV_X_POS_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_YUV_Y_POS = IoReg_Read32(KMC_METER_TOP__KMC_METER_YUV_Y_POS_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_X_POS = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_X_POS_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_Y_POS = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_Y_POS_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FACTOR = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FACTOR_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0001 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_0001_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0203 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_0203_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0405 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_0405_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0607 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_0607_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0809 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_0809_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0A0B = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_0A0B_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0C10 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_0C10_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1112 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_1112_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1314 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_1314_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1516 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_1516_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1718 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_1718_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_191A = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_191A_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1B1C = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_FILTER_1B1C_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_DR = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_DR_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_THR0 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_THR0_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_THR1 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_THR1_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_THR2 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_THR2_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_SLP_01 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_SLP_01_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_DR_THR = IoReg_Read32(KMC_METER_TOP__KMC_METER_DETAIL_DR_THR_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_THR0 = IoReg_Read32(KMC_METER_TOP__KMC_METER_DETAIL_THR0_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_THR1 = IoReg_Read32(KMC_METER_TOP__KMC_METER_DETAIL_THR1_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_THR2 = IoReg_Read32(KMC_METER_TOP__KMC_METER_DETAIL_THR2_ADDR);
	vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_CORING1 = IoReg_Read32(KMC_METER_TOP__KMC_METER_BW_CORING1_ADDR);
	//KMC_DM_METER_TOP
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_REG0 = IoReg_Read32(KMC_DM_METER_TOP__KMC_METER_REG0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_NUM = IoReg_Read32(KMC_DM_METER_TOP__KMC_METER_NUM_ADDR);
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_H_NUM0 = IoReg_Read32(KMC_DM_METER_TOP__KMC_METER_H_NUM0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_H_NUM1 = IoReg_Read32(KMC_DM_METER_TOP__KMC_METER_H_NUM1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TH0 = IoReg_Read32(KMC_DM_METER_TOP__METER_TH0_ADDR);
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TH1 = IoReg_Read32(KMC_DM_METER_TOP__METER_TH1_ADDR);
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TH3 = IoReg_Read32(KMC_DM_METER_TOP__METER_TH3_ADDR);
	vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TIMER0 = IoReg_Read32(KMC_DM_METER_TOP__METER_TIMER0_ADDR);
	//KME_TOP
	vpq_memc_suspend_resume.KME_TOP__KME_ME_ABL_SETTING0 = IoReg_Read32(KME_TOP__KME_ME_ABL_SETTING0_ADDR);
	vpq_memc_suspend_resume.KME_TOP__ME_ME_ABL_SETTING1 = IoReg_Read32(KME_TOP__ME_ME_ABL_SETTING1_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_0 = IoReg_Read32(KME_TOP__KME_DRF_BIST_IN_0_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_1 = IoReg_Read32(KME_TOP__KME_DRF_BIST_IN_1_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_2 = IoReg_Read32(KME_TOP__KME_DRF_BIST_IN_2_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_3 = IoReg_Read32(KME_TOP__KME_DRF_BIST_IN_3_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_4 = IoReg_Read32(KME_TOP__KME_DRF_BIST_IN_4_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_5 = IoReg_Read32(KME_TOP__KME_DRF_BIST_IN_5_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_6 = IoReg_Read32(KME_TOP__KME_DRF_BIST_IN_6_ADDR);
	vpq_memc_suspend_resume.KME_TOP__KME_DEHALO_DEBUG_0 = IoReg_Read32(KME_TOP__KME_DEHALO_DEBUG_0_ADDR);
	vpq_memc_suspend_resume.KME_TOP__DUMMY0 = IoReg_Read32(KME_TOP__DUMMY0_ADDR);
	vpq_memc_suspend_resume.KME_TOP__DUMMY1 = IoReg_Read32(KME_TOP__DUMMY1_ADDR);
	vpq_memc_suspend_resume.KME_TOP__DUMMY2 = IoReg_Read32(KME_TOP__DUMMY2_ADDR);
	vpq_memc_suspend_resume.KME_TOP__DUMMY3 = IoReg_Read32(KME_TOP__DUMMY3_ADDR);
	//KME_VBUF_TOP
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_ACTIVE = IoReg_Read32(KME_VBUF_TOP__VBUF_ACTIVE_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__IP_SEED_INIT = IoReg_Read32(KME_VBUF_TOP__IP_SEED_INIT_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__PI_SEED_INIT = IoReg_Read32(KME_VBUF_TOP__PI_SEED_INIT_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__LFSR_IP_1ST_MASK = IoReg_Read32(KME_VBUF_TOP__LFSR_IP_1ST_MASK_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__ENABLE_1ST = IoReg_Read32(KME_VBUF_TOP__ENABLE_1ST_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__ENABLE_2ND = IoReg_Read32(KME_VBUF_TOP__ENABLE_2ND_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_1 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_1ST_1_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_2 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_1ST_2_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_3 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_1ST_3_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_4 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_1ST_4_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_5 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_1ST_5_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_1 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_2ND_1_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_2 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_2ND_2_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_3 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_2ND_3_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_4 = IoReg_Read32(KME_VBUF_TOP__CANDIDATE_2ND_4_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__MV_XY_RANGE = IoReg_Read32(KME_VBUF_TOP__MV_XY_RANGE_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__MV_BLK_TOP_BOT_RIM = IoReg_Read32(KME_VBUF_TOP__MV_BLK_TOP_BOT_RIM_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__PIX_TOP_BOT_RIM = IoReg_Read32(KME_VBUF_TOP__PIX_TOP_BOT_RIM_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__PIX_LEFT_RIGHT_RIM = IoReg_Read32(KME_VBUF_TOP__PIX_LEFT_RIGHT_RIM_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__RIM_ENABLE = IoReg_Read32(KME_VBUF_TOP__RIM_ENABLE_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_GMV_SEL = IoReg_Read32(KME_VBUF_TOP__VBUF_GMV_SEL_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_LOGO = IoReg_Read32(KME_VBUF_TOP__VBUF_LOGO_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_REQ_INTERVAL = IoReg_Read32(KME_VBUF_TOP__VBUF_REQ_INTERVAL_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__LFSR_PI_1ST_MASK = IoReg_Read32(KME_VBUF_TOP__LFSR_PI_1ST_MASK_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__SINGLE_MODE_DEBUG = IoReg_Read32(KME_VBUF_TOP__SINGLE_MODE_DEBUG_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__MULTIMIN_DEBUG_IP = IoReg_Read32(KME_VBUF_TOP__MULTIMIN_DEBUG_IP_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__MULTIMIN_DEBUG_PI = IoReg_Read32(KME_VBUF_TOP__MULTIMIN_DEBUG_PI_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__MULTIMIN_DEBUG_BLK_IDX = IoReg_Read32(KME_VBUF_TOP__MULTIMIN_DEBUG_BLK_IDX_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_PPI_DM_DEBUG = IoReg_Read32(KME_VBUF_TOP__VBUF_PPI_DM_DEBUG_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_DM_MONITOR_CNT = IoReg_Read32(KME_VBUF_TOP__VBUF_DM_MONITOR_CNT_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_DUMMY_0 = IoReg_Read32(KME_VBUF_TOP__VBUF_DUMMY_0_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__SC_LFSR_IP_1ST_MASK = IoReg_Read32(KME_VBUF_TOP__SC_LFSR_IP_1ST_MASK_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__SC_LFSR_PI_1ST_MASK = IoReg_Read32(KME_VBUF_TOP__SC_LFSR_PI_1ST_MASK_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__MEANDER_RIM = IoReg_Read32(KME_VBUF_TOP__MEANDER_RIM_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_LOGO_DEBUG = IoReg_Read32(KME_VBUF_TOP__VBUF_LOGO_DEBUG_ADDR);
	vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_DEBUG_IDX = IoReg_Read32(KME_VBUF_TOP__VBUF_DEBUG_IDX_ADDR);
	//KME_ME1_TOP2
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_00 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_01 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_02 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_03 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_04 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_05 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_06 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_07 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_08 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_09 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_10 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_11 = IoReg_Read32(KME_ME1_TOP2__GMV_CTRL_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__SW_GMV_CTRL_00 = IoReg_Read32(KME_ME1_TOP2__SW_GMV_CTRL_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__SW_GMV_CTRL_01 = IoReg_Read32(KME_ME1_TOP2__SW_GMV_CTRL_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP2__SW_RMV_CTRL_00 = IoReg_Read32(KME_ME1_TOP2__SW_RMV_CTRL_00_ADDR);
	//KME_ME1_TOP3
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_00 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_01 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_02 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_03 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_04 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_05 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_06 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_07 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_08 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_09 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_10 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_11 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_12 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_12_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_13 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_13_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_14 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_14_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_15 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_15_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_16 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_16_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_17 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_17_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_18 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_18_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_19 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_19_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_20 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_20_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_21 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_21_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_22 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_22_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_23 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_23_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_24 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_24_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_25 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_25_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_26 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_26_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_27 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_27_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_28 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_28_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_29 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_29_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_30 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_30_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_31 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_MV_CTRL_31_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_00 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_01 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_02 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_03 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_04 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_05 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_06 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_07 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_08 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_09 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_10 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_11 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_12 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_12_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_13 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_13_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_14 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_14_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_15 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_15_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_00 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_01 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_02 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_03 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_04 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_05 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_06 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_07 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_08 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_09 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_10 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_11 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_12 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_12_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_13 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_13_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_14 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_14_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_15 = IoReg_Read32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_15_ADDR);
	//KME_ME1_TOP4
	//KME_ME1_TOP5
	//P27
	vpq_memc_suspend_resume.P27__DEHALO_00 = IoReg_Read32(P27__DEHALO_00_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_04 = IoReg_Read32(P27__DEHALO_04_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_08 = IoReg_Read32(P27__DEHALO_08_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_0C = IoReg_Read32(P27__DEHALO_0C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_10 = IoReg_Read32(P27__DEHALO_10_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_14 = IoReg_Read32(P27__DEHALO_14_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_18 = IoReg_Read32(P27__DEHALO_18_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_1C = IoReg_Read32(P27__DEHALO_1C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_20 = IoReg_Read32(P27__DEHALO_20_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_24 = IoReg_Read32(P27__DEHALO_24_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_28 = IoReg_Read32(P27__DEHALO_28_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_2C = IoReg_Read32(P27__DEHALO_2C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_30 = IoReg_Read32(P27__DEHALO_30_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_34 = IoReg_Read32(P27__DEHALO_34_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_38 = IoReg_Read32(P27__DEHALO_38_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_3C = IoReg_Read32(P27__DEHALO_3C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_40 = IoReg_Read32(P27__DEHALO_40_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_44 = IoReg_Read32(P27__DEHALO_44_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_48 = IoReg_Read32(P27__DEHALO_48_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_4C = IoReg_Read32(P27__DEHALO_4C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_50 = IoReg_Read32(P27__DEHALO_50_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_54 = IoReg_Read32(P27__DEHALO_54_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_58 = IoReg_Read32(P27__DEHALO_58_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_5C = IoReg_Read32(P27__DEHALO_5C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_60 = IoReg_Read32(P27__DEHALO_60_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_64 = IoReg_Read32(P27__DEHALO_64_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_68 = IoReg_Read32(P27__DEHALO_68_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_6C = IoReg_Read32(P27__DEHALO_6C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_80 = IoReg_Read32(P27__DEHALO_80_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_84 = IoReg_Read32(P27__DEHALO_84_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_88 = IoReg_Read32(P27__DEHALO_88_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_8C = IoReg_Read32(P27__DEHALO_8C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_90 = IoReg_Read32(P27__DEHALO_90_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_94 = IoReg_Read32(P27__DEHALO_94_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_98 = IoReg_Read32(P27__DEHALO_98_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_9C = IoReg_Read32(P27__DEHALO_9C_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_A0 = IoReg_Read32(P27__DEHALO_A0_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_A4 = IoReg_Read32(P27__DEHALO_A4_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_A8 = IoReg_Read32(P27__DEHALO_A8_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_AC = IoReg_Read32(P27__DEHALO_AC_ADDR);
	vpq_memc_suspend_resume.P27__DEHALO_F0 = IoReg_Read32(P27__DEHALO_F0_ADDR);
	//KME_LBME_TOP
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_X_POS = IoReg_Read32(KME_LBME_TOP__LBME_X_POS_ADDR);
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_Y_POS = IoReg_Read32(KME_LBME_TOP__LBME_Y_POS_ADDR);
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_DEBUG = IoReg_Read32(KME_LBME_TOP__LBME_DEBUG_ADDR);
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_XY_OFFSET = IoReg_Read32(KME_LBME_TOP__LBME_XY_OFFSET_ADDR);
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_DEBUG_XY_POS = IoReg_Read32(KME_LBME_TOP__LBME_DEBUG_XY_POS_ADDR);
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM = IoReg_Read32(KME_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM_ADDR);
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_LINE_LINEBUF_NUM = IoReg_Read32(KME_LBME_TOP__LBME_LINE_LINEBUF_NUM_ADDR);
	vpq_memc_suspend_resume.KME_LBME_TOP__LBME_REGIONAL_APL = IoReg_Read32(KME_LBME_TOP__LBME_REGIONAL_APL_ADDR);
	//KME_LOGO2
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD0 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD0_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD1 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD1_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD2 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD2_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD3 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD3_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD4 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD4_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD5 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD5_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD6 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD6_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD7 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD7_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD8 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD8_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD9 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD9_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD10 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD10_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD11 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD11_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD12 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD12_ADDR);
	vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD13 = IoReg_Read32(KME_LOGO2__KM_LOGO_PXL_RW_FLD13_ADDR);
	//KME_IPME
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN0 = IoReg_Read32(KME_IPME__KME_IPME_SCALER_DOWN0_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN1 = IoReg_Read32(KME_IPME__KME_IPME_SCALER_DOWN1_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN2 = IoReg_Read32(KME_IPME__KME_IPME_SCALER_DOWN2_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN3 = IoReg_Read32(KME_IPME__KME_IPME_SCALER_DOWN3_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR0 = IoReg_Read32(KME_IPME__KME_IPME_IIR0_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR1 = IoReg_Read32(KME_IPME__KME_IPME_IIR1_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR2 = IoReg_Read32(KME_IPME__KME_IPME_IIR2_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR3 = IoReg_Read32(KME_IPME__KME_IPME_IIR3_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR4 = IoReg_Read32(KME_IPME__KME_IPME_IIR4_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN4 = IoReg_Read32(KME_IPME__KME_IPME_SCALER_DOWN4_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET_0 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET_0_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET0 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET0_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET1 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET1_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET2 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET2_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET3 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET3_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET4 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET4_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET5 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET5_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET6 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET6_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET7 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET7_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET8 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET8_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET9 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET9_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET10 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET10_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET11 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET11_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET12 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET12_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET13 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET13_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET14 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET14_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET15 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET15_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET16 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET16_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET17 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET17_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET18 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET18_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET19 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET19_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET20 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET20_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET21 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET21_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET22 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET22_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET23 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET23_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP0 = IoReg_Read32(KME_IPME__KME_IPME_FILTER_ALP0_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP1 = IoReg_Read32(KME_IPME__KME_IPME_FILTER_ALP1_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP2 = IoReg_Read32(KME_IPME__KME_IPME_FILTER_ALP2_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP3 = IoReg_Read32(KME_IPME__KME_IPME_FILTER_ALP3_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET24 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET24_ADDR);
	vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET25 = IoReg_Read32(KME_IPME__KME_IPME_FILM_DET25_ADDR);
	//KME_IPME1
	vpq_memc_suspend_resume.KME_IPME1__KME_IPME_FILM_DET_RW0 = IoReg_Read32(KME_IPME1__KME_IPME_FILM_DET_RW0_ADDR);
	vpq_memc_suspend_resume.KME_IPME1__KME_IPME_CPRS_RW0 = IoReg_Read32(KME_IPME1__KME_IPME_CPRS_RW0_ADDR);
	vpq_memc_suspend_resume.KME_IPME1__KME_IPME_SCALER0 = IoReg_Read32(KME_IPME1__KME_IPME_SCALER0_ADDR);
	//KME_LOGO0
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER0 = IoReg_Read32(KME_LOGO0__KM_LOGO_SCALER0_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER1 = IoReg_Read32(KME_LOGO0__KM_LOGO_SCALER1_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER2 = IoReg_Read32(KME_LOGO0__KM_LOGO_SCALER2_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER3 = IoReg_Read32(KME_LOGO0__KM_LOGO_SCALER3_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_IIR0 = IoReg_Read32(KME_LOGO0__KM_LOGO_IIR0_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK0 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK0_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK1 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK1_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK2 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK2_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK3 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK3_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK4 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK4_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK5 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK5_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK6 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK6_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK7 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK7_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK8 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK8_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK9 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK9_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK10 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK10_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK11 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK11_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK12 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK12_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK13 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK13_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK14 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK14_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK15 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK15_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK16 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK16_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK17 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK17_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK18 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK18_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK19 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK19_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK20 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK20_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK21 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK21_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK22 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK22_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK23 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK23_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK24 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK24_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK25 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK25_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK26 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK26_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK27 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK27_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK28 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK28_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK29 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK29_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK30 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK30_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK31 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK31_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK32 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK32_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK33 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK33_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK34 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK34_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK35 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK35_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK36 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK36_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK37 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK37_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK38 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK38_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK39 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK39_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK40 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK40_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK41 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK41_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK42 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK42_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK43 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK43_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK44 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK44_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK45 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK45_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK46 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK46_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK47 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK47_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK48 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK48_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK49 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK49_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK50 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK50_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK51 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK51_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK52 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK52_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK53 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK53_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK54 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK54_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK55 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK55_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK56 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK56_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK57 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK57_ADDR);
	vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK58 = IoReg_Read32(KME_LOGO0__KM_LOGO_BLK58_ADDR);
	//KME_LOGO1
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK80 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK80_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK81 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK81_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK82 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK82_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK83 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK83_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK84 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK84_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK85 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK85_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK86 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK86_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK87 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK87_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK88 = IoReg_Read32(KME_LOGO1__KM_LOGO_BLK88_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL0 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL0_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL1 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL1_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL2 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL2_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL3 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL3_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL4 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL4_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL5 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL5_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL6 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL6_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL7 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL7_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL8 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL8_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL9 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL9_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL10 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL10_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL11 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL11_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL12 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL12_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL13 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL13_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL14 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL14_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL15 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL15_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL16 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL16_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL17 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL17_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL18 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL18_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL19 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL19_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL_ADD20 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL_ADD20_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL_ADD21 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL_ADD21_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL20 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL20_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL21 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL21_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL22 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL22_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL23 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL23_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL24 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL24_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL25 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL25_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL26 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL26_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL27 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL27_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL28 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL28_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL29 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL29_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL30 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL30_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL31 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL31_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL32 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL32_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL33 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL33_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL34 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL34_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL35 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL35_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL36 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL36_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL37 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL37_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL38 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL38_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL39 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL39_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL40 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL40_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL41 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL41_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL43 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL43_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL44 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL44_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL45 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL45_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL46 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL46_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL47 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL47_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL48 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL48_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL49 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL49_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL50 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL50_ADDR);
	vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL51 = IoReg_Read32(KME_LOGO1__KM_LOGO_PXL51_ADDR);
	//KME_DM_TOP0
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP0__KME_00_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP0__KME_00_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS2 = IoReg_Read32(KME_DM_TOP0__KME_00_START_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS3 = IoReg_Read32(KME_DM_TOP0__KME_00_START_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS4 = IoReg_Read32(KME_DM_TOP0__KME_00_START_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS5 = IoReg_Read32(KME_DM_TOP0__KME_00_START_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP0__KME_00_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP0__KME_00_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS2 = IoReg_Read32(KME_DM_TOP0__KME_00_END_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS3 = IoReg_Read32(KME_DM_TOP0__KME_00_END_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS4 = IoReg_Read32(KME_DM_TOP0__KME_00_END_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS5 = IoReg_Read32(KME_DM_TOP0__KME_00_END_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP0__KME_00_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP0__KME_00_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_AGENT = IoReg_Read32(KME_DM_TOP0__KME_00_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_00_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_01_AGENT = IoReg_Read32(KME_DM_TOP0__KME_01_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_01_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_01_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_02_AGENT = IoReg_Read32(KME_DM_TOP0__KME_02_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_02_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_02_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_03_AGENT = IoReg_Read32(KME_DM_TOP0__KME_03_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_03_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_03_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP0__KME_04_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP0__KME_04_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP0__KME_04_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP0__KME_04_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP0__KME_04_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP0__KME_04_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_AGENT = IoReg_Read32(KME_DM_TOP0__KME_04_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_04_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP0__KME_05_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP0__KME_05_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP0__KME_05_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP0__KME_05_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP0__KME_05_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP0__KME_05_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_AGENT = IoReg_Read32(KME_DM_TOP0__KME_05_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_05_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_06_AGENT = IoReg_Read32(KME_DM_TOP0__KME_06_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_06_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_06_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_07_AGENT = IoReg_Read32(KME_DM_TOP0__KME_07_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_07_THRESHOLD = IoReg_Read32(KME_DM_TOP0__KME_07_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_ME_RESOLUTION = IoReg_Read32(KME_DM_TOP0__KME_ME_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_MV_RESOLUTION = IoReg_Read32(KME_DM_TOP0__KME_MV_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_SOURCE_MODE = IoReg_Read32(KME_DM_TOP0__KME_SOURCE_MODE_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_ME_HNUM = IoReg_Read32(KME_DM_TOP0__KME_ME_HNUM_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_TIMER_ENABLE = IoReg_Read32(KME_DM_TOP0__KME_TIMER_ENABLE_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME0 = IoReg_Read32(KME_DM_TOP0__KME_HOLD_TIME0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME1 = IoReg_Read32(KME_DM_TOP0__KME_HOLD_TIME1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME2 = IoReg_Read32(KME_DM_TOP0__KME_HOLD_TIME2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME3 = IoReg_Read32(KME_DM_TOP0__KME_HOLD_TIME3_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__WAIT_TIME0 = IoReg_Read32(KME_DM_TOP0__WAIT_TIME0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__WAIT_TIME1 = IoReg_Read32(KME_DM_TOP0__WAIT_TIME1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__WAIT_TIME2 = IoReg_Read32(KME_DM_TOP0__WAIT_TIME2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__MV04_START_ADDRESS2 = IoReg_Read32(KME_DM_TOP0__MV04_START_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP0__MV04_END_ADDRESS2 = IoReg_Read32(KME_DM_TOP0__MV04_END_ADDRESS2_ADDR);
	//KME_DM_TOP1
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_08_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_08_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_08_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_08_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP1__KME_08_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_AGENT = IoReg_Read32(KME_DM_TOP1__KME_08_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_08_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_09_AGENT = IoReg_Read32(KME_DM_TOP1__KME_09_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_09_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_09_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_10_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_10_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_10_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_10_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP1__KME_10_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_AGENT = IoReg_Read32(KME_DM_TOP1__KME_10_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_10_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_11_AGENT = IoReg_Read32(KME_DM_TOP1__KME_11_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_11_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_11_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_12_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_12_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_12_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_12_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP1__KME_12_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_AGENT = IoReg_Read32(KME_DM_TOP1__KME_12_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_12_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_13_AGENT = IoReg_Read32(KME_DM_TOP1__KME_13_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_13_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_13_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_14_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_14_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP1__KME_14_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP1__KME_14_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP1__KME_14_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_AGENT = IoReg_Read32(KME_DM_TOP1__KME_14_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_14_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_15_AGENT = IoReg_Read32(KME_DM_TOP1__KME_15_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_15_THRESHOLD = IoReg_Read32(KME_DM_TOP1__KME_15_THRESHOLD_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_IPLOGO_RESOLUTION = IoReg_Read32(KME_DM_TOP1__KME_IPLOGO_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_MLOGO_RESOLUTION = IoReg_Read32(KME_DM_TOP1__KME_MLOGO_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_PLOGO_RESOLUTION = IoReg_Read32(KME_DM_TOP1__KME_PLOGO_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_HLOGO_RESOLUTION = IoReg_Read32(KME_DM_TOP1__KME_HLOGO_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_LOGO_HNUM = IoReg_Read32(KME_DM_TOP1__KME_LOGO_HNUM_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_CLR = IoReg_Read32(KME_DM_TOP1__KME_CLR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__TH0 = IoReg_Read32(KME_DM_TOP1__TH0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__TH1 = IoReg_Read32(KME_DM_TOP1__TH1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__TH2 = IoReg_Read32(KME_DM_TOP1__TH2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__TH3 = IoReg_Read32(KME_DM_TOP1__TH3_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__TH4 = IoReg_Read32(KME_DM_TOP1__TH4_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP1__METER_TIMER1 = IoReg_Read32(KME_DM_TOP1__METER_TIMER1_ADDR);
	//KME_DM_TOP2
	vpq_memc_suspend_resume.KME_DM_TOP2__MV01_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV01_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV01_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV01_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_01_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV_01_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV01_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV01_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV01_AGENT = IoReg_Read32(KME_DM_TOP2__MV01_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV02_START_ADDRESS11 = IoReg_Read32(KME_DM_TOP2__MV02_START_ADDRESS11_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV02_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV02_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_02_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV_02_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV02_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV02_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV02_AGENT = IoReg_Read32(KME_DM_TOP2__MV02_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV03_AGENT = IoReg_Read32(KME_DM_TOP2__MV03_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV04_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV04_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV04_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP2__MV04_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV04_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV04_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV04_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP2__MV04_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_04_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV_04_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV04_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV04_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV04_AGENT = IoReg_Read32(KME_DM_TOP2__MV04_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV05_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV05_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV05_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP2__MV05_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV05_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV05_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV05_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP2__MV05_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_05_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV_05_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV05_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV05_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV05_AGENT = IoReg_Read32(KME_DM_TOP2__MV05_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV06_AGENT = IoReg_Read32(KME_DM_TOP2__MV06_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV07_AGENT = IoReg_Read32(KME_DM_TOP2__MV07_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV08_AGENT = IoReg_Read32(KME_DM_TOP2__MV08_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV09_AGENT = IoReg_Read32(KME_DM_TOP2__MV09_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV10_AGENT = IoReg_Read32(KME_DM_TOP2__MV10_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV11_AGENT = IoReg_Read32(KME_DM_TOP2__MV11_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS1 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS2 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS3 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS4 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS5 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS0 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS1 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS2 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS3 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS3_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS4 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS4_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS5 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS5_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_LINE_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV_12_LINE_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_LR_OFFSET_ADDR = IoReg_Read32(KME_DM_TOP2__MV_12_LR_OFFSET_ADDR_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV12_AGENT = IoReg_Read32(KME_DM_TOP2__MV12_AGENT_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_SOURCE_MODE = IoReg_Read32(KME_DM_TOP2__MV_SOURCE_MODE_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV01_RESOLUTION = IoReg_Read32(KME_DM_TOP2__MV01_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV02_RESOLUTION = IoReg_Read32(KME_DM_TOP2__MV02_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV04_RESOLUTION = IoReg_Read32(KME_DM_TOP2__MV04_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV05_RESOLUTION = IoReg_Read32(KME_DM_TOP2__MV05_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV12_RESOLUTION = IoReg_Read32(KME_DM_TOP2__MV12_RESOLUTION_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_TIME_ENABLE = IoReg_Read32(KME_DM_TOP2__MV_TIME_ENABLE_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_HOLD_TIME0 = IoReg_Read32(KME_DM_TOP2__MV_HOLD_TIME0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_HOLD_TIME1 = IoReg_Read32(KME_DM_TOP2__MV_HOLD_TIME1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_HOLD_TIME2 = IoReg_Read32(KME_DM_TOP2__MV_HOLD_TIME2_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_WAIT_TIME0 = IoReg_Read32(KME_DM_TOP2__MV_WAIT_TIME0_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_WAIT_TIME1 = IoReg_Read32(KME_DM_TOP2__MV_WAIT_TIME1_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS6 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS6_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS7 = IoReg_Read32(KME_DM_TOP2__MV_12_START_ADDRESS7_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS6 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS6_ADDR);
	vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS7 = IoReg_Read32(KME_DM_TOP2__MV_12_END_ADDRESS7_ADDR);
	//KME_ME1_TOP0
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_00 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_01 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_02 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_03 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_04 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_05 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_06 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_07 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_08 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_09 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_10 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_11 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_12 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_12_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_13 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_13_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_14 = IoReg_Read32(KME_ME1_TOP0__ME1_IP_CONFIG_14_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_00 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_01 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_02 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_03 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_04 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_05 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_06 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_07 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_08 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_09 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_10 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_11 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_12 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_12_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_13 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_13_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_14 = IoReg_Read32(KME_ME1_TOP0__ME1_PI_CONFIG_14_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_04 = IoReg_Read32(KME_ME1_TOP0__ME1_COMMON_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_00 = IoReg_Read32(KME_ME1_TOP0__ME1_COMMON_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_01 = IoReg_Read32(KME_ME1_TOP0__ME1_COMMON_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_02 = IoReg_Read32(KME_ME1_TOP0__ME1_COMMON_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_03 = IoReg_Read32(KME_ME1_TOP0__ME1_COMMON_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG00 = IoReg_Read32(KME_ME1_TOP0__ME1_SC_REG00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG01 = IoReg_Read32(KME_ME1_TOP0__ME1_SC_REG01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG02 = IoReg_Read32(KME_ME1_TOP0__ME1_SC_REG02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG03 = IoReg_Read32(KME_ME1_TOP0__ME1_SC_REG03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG04 = IoReg_Read32(KME_ME1_TOP0__ME1_SC_REG04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG05 = IoReg_Read32(KME_ME1_TOP0__ME1_SC_REG05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG00 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG01 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG02 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG03 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG04 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG05 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG06 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG07 = IoReg_Read32(KME_ME1_TOP0__ME1_MEANDER_REG07_ADDR);
	//KME_ME1_TOP1
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_00 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_01 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_02 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_03 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_04 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_05 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_06 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_07 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_08 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_09 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_10 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_11 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_12 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_12_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_13 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_13_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_14 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_14_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_15 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_15_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_16 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_16_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_17 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_17_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_18 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_18_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_19 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_19_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_20 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_20_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_21 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_21_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_22 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_22_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_23 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_23_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_24 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_24_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_25 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_25_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_26 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_26_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_27 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_27_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_28 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_28_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_29 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_29_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_30 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_30_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_31 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_31_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_32 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_32_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_33 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_33_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_34 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_34_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_35 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_35_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_36 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_36_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_37 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_37_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_38 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_38_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_39 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_39_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_40 = IoReg_Read32(KME_ME1_TOP1__ME1_COMMON1_40_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_00 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_01 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_02 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_03 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_04 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_05 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_06 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_07 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_08 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_08_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_09 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_09_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_10 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_10_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_11 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_11_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_12 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_12_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_13 = IoReg_Read32(KME_ME1_TOP1__ME1_SCENE1_13_ADDR);
	//KME_ME2_LBME_TOP
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_X_POS = IoReg_Read32(KME_ME2_LBME_TOP__LBME_X_POS_ADDR);
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_Y_POS = IoReg_Read32(KME_ME2_LBME_TOP__LBME_Y_POS_ADDR);
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_DEBUG = IoReg_Read32(KME_ME2_LBME_TOP__LBME_DEBUG_ADDR);
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_XY_OFFSET = IoReg_Read32(KME_ME2_LBME_TOP__LBME_XY_OFFSET_ADDR);
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_DEBUG_XY_POS = IoReg_Read32(KME_ME2_LBME_TOP__LBME_DEBUG_XY_POS_ADDR);
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM = IoReg_Read32(KME_ME2_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM_ADDR);
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_LINE_LINEBUF_NUM = IoReg_Read32(KME_ME2_LBME_TOP__LBME_LINE_LINEBUF_NUM_ADDR);
	vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_ED_EN = IoReg_Read32(KME_ME2_LBME_TOP__LBME_ED_EN_ADDR);
	//KME_ME2_VBUF_TOP
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG0 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG0_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG1 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG1_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG2 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG2_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG3 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG3_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG4 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG4_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG5 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG5_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG6 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG6_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG7 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG7_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG8 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG8_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG9 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG9_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG10 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG10_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG11 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG11_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG12 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG12_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG13 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG13_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG14 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG14_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG15 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG15_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG16 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG16_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG17 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG17_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG18 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG18_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG19 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG19_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG20 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG20_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG21 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG21_ADDR);
	vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG22 = IoReg_Read32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG22_ADDR);
	//KME_ME2_TOP
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_00 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_00_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_01 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_01_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_02 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_02_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_03 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_03_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_04 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_04_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_05 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_05_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_06 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_06_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_07 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_07_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_08 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_08_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_09 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_09_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_10 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_10_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_11 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_11_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_12 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_12_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_13 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_13_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_14 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_14_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_15 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_15_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_16 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_16_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_17 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_17_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_18 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_18_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_19 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_19_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_20 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_20_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_21 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_21_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_22 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_22_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_23 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_23_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_24 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_24_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_25 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_25_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_26 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_26_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_27 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_27_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_28 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_28_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_34 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_34_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_35 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_35_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_36 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_36_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_37 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_37_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_38 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_38_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_39 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_39_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_40 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_40_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_41 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_41_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_42 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_42_ADDR);
	vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_43 = IoReg_Read32(KME_ME2_TOP__ME2_CONFIG_43_ADDR);
	//KME_ME1_TOP6
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_00 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_00_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_01 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_01_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_02 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_02_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_03 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_03_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_04 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_04_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_05 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_05_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_06 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_06_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_07 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_07_ADDR);
	vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_08 = IoReg_Read32(KME_ME1_TOP6__ME1_STATIS_08_ADDR);
	//KME_ME1_TOP7
	//KME_ME1_TOP8
	//KME_ME1_TOP9
	//KME_DEHALO
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_CTRL = IoReg_Read32(KME_DEHALO__KME_DH_CTRL_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_LOGO0 = IoReg_Read32(KME_DEHALO__KME_DH_LOGO0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RIM0 = IoReg_Read32(KME_DEHALO__KME_DH_RIM0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RIM1 = IoReg_Read32(KME_DEHALO__KME_DH_RIM1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PHASE = IoReg_Read32(KME_DEHALO__KME_DH_PHASE_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_0 = IoReg_Read32(KME_DEHALO__KME_DH_RT1_0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_0 = IoReg_Read32(KME_DEHALO__KME_DH_RT2_0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_1 = IoReg_Read32(KME_DEHALO__KME_DH_RT1_1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_2 = IoReg_Read32(KME_DEHALO__KME_DH_RT1_2_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_1 = IoReg_Read32(KME_DEHALO__KME_DH_RT2_1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_2 = IoReg_Read32(KME_DEHALO__KME_DH_RT2_2_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_CONF_GEN1 = IoReg_Read32(KME_DEHALO__KME_DH_CONF_GEN1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_CONF_PROC2 = IoReg_Read32(KME_DEHALO__KME_DH_CONF_PROC2_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PFV_GEN1 = IoReg_Read32(KME_DEHALO__KME_DH_PFV_GEN1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PFV_CHK1 = IoReg_Read32(KME_DEHALO__KME_DH_PFV_CHK1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_DEBUG_SEL = IoReg_Read32(KME_DEHALO__KME_DH_DEBUG_SEL_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_3 = IoReg_Read32(KME_DEHALO__KME_DH_RT1_3_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_4 = IoReg_Read32(KME_DEHALO__KME_DH_RT1_4_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_3 = IoReg_Read32(KME_DEHALO__KME_DH_RT2_3_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PHASE_OFT0 = IoReg_Read32(KME_DEHALO__KME_DH_PHASE_OFT0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PHASE_OFT1 = IoReg_Read32(KME_DEHALO__KME_DH_PHASE_OFT1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_VBUF_TIMING0 = IoReg_Read32(KME_DEHALO__KME_DH_VBUF_TIMING0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_VBUF_TIMING1 = IoReg_Read32(KME_DEHALO__KME_DH_VBUF_TIMING1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__KME_DH_VBUF_TIMING2 = IoReg_Read32(KME_DEHALO__KME_DH_VBUF_TIMING2_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DEHALO_SHOW = IoReg_Read32(KME_DEHALO__DEHALO_SHOW_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__MV_PAT = IoReg_Read32(KME_DEHALO__MV_PAT_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_DUMMY_CTRL2 = IoReg_Read32(KME_DEHALO__DH_DUMMY_CTRL2_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__MV_PAT_WINDOWH = IoReg_Read32(KME_DEHALO__MV_PAT_WINDOWH_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__MV_PAT_WINDOWV = IoReg_Read32(KME_DEHALO__MV_PAT_WINDOWV_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_HOR0 = IoReg_Read32(KME_DEHALO__DH_LOGO_HOR0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_HOR1 = IoReg_Read32(KME_DEHALO__DH_LOGO_HOR1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_VER0 = IoReg_Read32(KME_DEHALO__DH_LOGO_VER0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_VER1 = IoReg_Read32(KME_DEHALO__DH_LOGO_VER1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_MV_DIFF = IoReg_Read32(KME_DEHALO__DH_LOGO_MV_DIFF_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_SMV0 = IoReg_Read32(KME_DEHALO__DH_LOGO_SMV0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_SMV1 = IoReg_Read32(KME_DEHALO__DH_LOGO_SMV1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_CTRL = IoReg_Read32(KME_DEHALO__DH_LOGO_CTRL_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_REGION0 = IoReg_Read32(KME_DEHALO__DH_REGION0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_REGION1 = IoReg_Read32(KME_DEHALO__DH_REGION1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_REGION2 = IoReg_Read32(KME_DEHALO__DH_REGION2_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_TMV = IoReg_Read32(KME_DEHALO__DH_LOGO_TMV_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_CORNER0 = IoReg_Read32(KME_DEHALO__DH_CORNER0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_CORNER1 = IoReg_Read32(KME_DEHALO__DH_CORNER1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_CORNER2 = IoReg_Read32(KME_DEHALO__DH_CORNER2_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_PHASE_GAIN0 = IoReg_Read32(KME_DEHALO__DH_PHASE_GAIN0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO__DH_PHASE_GAIN1 = IoReg_Read32(KME_DEHALO__DH_PHASE_GAIN1_ADDR);
	//KME_DEHALO2
	vpq_memc_suspend_resume.KME_DEHALO2__DH_DEBUG_PATH_SETTING = IoReg_Read32(KME_DEHALO2__DH_DEBUG_PATH_SETTING_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__DH_RT2_H_V_IDX_OFFSET = IoReg_Read32(KME_DEHALO2__DH_RT2_H_V_IDX_OFFSET_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__DH_CHECK_MODE0 = IoReg_Read32(KME_DEHALO2__DH_CHECK_MODE0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__DH_DEBUG_KKK = IoReg_Read32(KME_DEHALO2__DH_DEBUG_KKK_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__DH_PATT_EN_CTRL = IoReg_Read32(KME_DEHALO2__DH_PATT_EN_CTRL_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__RT1_RIM0 = IoReg_Read32(KME_DEHALO2__RT1_RIM0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__RT1_RIM1 = IoReg_Read32(KME_DEHALO2__RT1_RIM1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__RT2_RIM0 = IoReg_Read32(KME_DEHALO2__RT2_RIM0_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__RT2_RIM1 = IoReg_Read32(KME_DEHALO2__RT2_RIM1_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__DH_PR_MODE_CTRL = IoReg_Read32(KME_DEHALO2__DH_PR_MODE_CTRL_ADDR);
	vpq_memc_suspend_resume.KME_DEHALO2__DH_DUMMY_GEN_CTRL = IoReg_Read32(KME_DEHALO2__DH_DUMMY_GEN_CTRL_ADDR);
	//KPOST_TOP
	vpq_memc_suspend_resume.KPOST_TOP__POST_CURSOR = IoReg_Read32(KPOST_TOP__POST_CURSOR_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_BS_OUT_INT_CTRL = IoReg_Read32(KPOST_TOP__POST_BS_OUT_INT_CTRL_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_INT_CTRL = IoReg_Read32(KPOST_TOP__POST_INT_CTRL_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__BLACK_INSERT = IoReg_Read32(KPOST_TOP__BLACK_INSERT_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_TOTAL = IoReg_Read32(KPOST_TOP__POST_PATT_TOTAL_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_ACT = IoReg_Read32(KPOST_TOP__POST_PATT_ACT_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_WIDTH_BPORCH = IoReg_Read32(KPOST_TOP__POST_PATT_WIDTH_BPORCH_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_CTRL = IoReg_Read32(KPOST_TOP__POST_PATT_CTRL_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_RGB0 = IoReg_Read32(KPOST_TOP__POST_PATT_RGB0_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_RGB1 = IoReg_Read32(KPOST_TOP__POST_PATT_RGB1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__LINE2_TO_4PORT = IoReg_Read32(KPOST_TOP__LINE2_TO_4PORT_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_PSC_CTRL = IoReg_Read32(KPOST_TOP__POST_PSC_CTRL_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_0 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_Y_0_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_1 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_Y_1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_2 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_Y_2_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_3 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_Y_3_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_0 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_C_0_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_1 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_C_1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_2 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_C_2_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_3 = IoReg_Read32(KPOST_TOP__POST_HSC_COEF_C_3_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_BLUE_SCREEN = IoReg_Read32(KPOST_TOP__POST_BLUE_SCREEN_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_DRF_BIST_IN_1 = IoReg_Read32(KPOST_TOP__POST_DRF_BIST_IN_1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_DRF_BIST_IN_2 = IoReg_Read32(KPOST_TOP__POST_DRF_BIST_IN_2_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_DRF_BIST_IN_3 = IoReg_Read32(KPOST_TOP__POST_DRF_BIST_IN_3_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF0 = IoReg_Read32(KPOST_TOP__POST_CSC_COEF0_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF1 = IoReg_Read32(KPOST_TOP__POST_CSC_COEF1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF2 = IoReg_Read32(KPOST_TOP__POST_CSC_COEF2_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF3 = IoReg_Read32(KPOST_TOP__POST_CSC_COEF3_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF4 = IoReg_Read32(KPOST_TOP__POST_CSC_COEF4_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF5 = IoReg_Read32(KPOST_TOP__POST_CSC_COEF5_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_G0G1 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_DATA_G0G1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_G2G3 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_DATA_G2G3_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G0G1 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G0G1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G0 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_PLACE_G0_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G1 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_PLACE_G1_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G2 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_PLACE_G2_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G3 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_PLACE_G3_ADDR);
	vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G2G3 = IoReg_Read32(KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G2G3_ADDR);
	//CRTC1
	vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_TOTAL_HSWIDTH = IoReg_Read32(CRTC1__CRTC1_OUT_TOTAL_HSWIDTH_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_ACT_VSWIDTH = IoReg_Read32(CRTC1__CRTC1_OUT_ACT_VSWIDTH_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_SYNC_BPORCH = IoReg_Read32(CRTC1__CRTC1_OUT_SYNC_BPORCH_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_OSD_ACT = IoReg_Read32(CRTC1__CRTC1_OSD_ACT_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_OSD_SYNC_BPORCH = IoReg_Read32(CRTC1__CRTC1_OSD_SYNC_BPORCH_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_FRC_ACT = IoReg_Read32(CRTC1__CRTC1_FRC_ACT_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_FRC_SYNC_BPORCH = IoReg_Read32(CRTC1__CRTC1_FRC_SYNC_BPORCH_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_IP_ME_VTRIG = IoReg_Read32(CRTC1__CRTC1_IP_ME_VTRIG_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_OSD_FRC_VTRIG = IoReg_Read32(CRTC1__CRTC1_OUT_OSD_FRC_VTRIG_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_ME_DEC_VTRIG = IoReg_Read32(CRTC1__CRTC1_ME_DEC_VTRIG_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_DEHALO_MC_VTRIG = IoReg_Read32(CRTC1__CRTC1_DEHALO_MC_VTRIG_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_INDEX_A = IoReg_Read32(CRTC1__CRTC1_LBMC_INDEX_A_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_INDEX_B = IoReg_Read32(CRTC1__CRTC1_LBMC_INDEX_B_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_INDEX_C = IoReg_Read32(CRTC1__CRTC1_LBMC_INDEX_C_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_INDEX_HDLY = IoReg_Read32(CRTC1__CRTC1_INDEX_HDLY_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_HDLY = IoReg_Read32(CRTC1__CRTC1_HDLY_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_VRANGE0_ROW_TYPE = IoReg_Read32(CRTC1__CRTC1_VRANGE0_ROW_TYPE_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_VRANGE1 = IoReg_Read32(CRTC1__CRTC1_VRANGE1_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LOGO = IoReg_Read32(CRTC1__CRTC1_LOGO_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_SETTING_A = IoReg_Read32(CRTC1__CRTC1_VSPLL_SETTING_A_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_V_MAX_MIN = IoReg_Read32(CRTC1__CRTC1_VSPLL_V_MAX_MIN_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_V_OFFSET = IoReg_Read32(CRTC1__CRTC1_VSPLL_V_OFFSET_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_SETTING_B = IoReg_Read32(CRTC1__CRTC1_VSPLL_SETTING_B_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_SETTING_C = IoReg_Read32(CRTC1__CRTC1_VSPLL_SETTING_C_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_A = IoReg_Read32(CRTC1__CRTC1_LBMC_SEP_INDEX_A_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_B = IoReg_Read32(CRTC1__CRTC1_LBMC_SEP_INDEX_B_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_C = IoReg_Read32(CRTC1__CRTC1_LBMC_SEP_INDEX_C_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_D = IoReg_Read32(CRTC1__CRTC1_LBMC_SEP_INDEX_D_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_ME_ROW_TRG_OFST = IoReg_Read32(CRTC1__CRTC1_ME_ROW_TRG_OFST_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_ME1_TIMING0 = IoReg_Read32(CRTC1__CRTC1_ME1_TIMING0_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_ME1_TIMING1 = IoReg_Read32(CRTC1__CRTC1_ME1_TIMING1_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_LR_CONTROL = IoReg_Read32(CRTC1__CRTC1_LR_CONTROL_ADDR);
	vpq_memc_suspend_resume.CRTC1__CRTC1_DEHALO_FLT_TRIG = IoReg_Read32(CRTC1__CRTC1_DEHALO_FLT_TRIG_ADDR);
	//KPhase
	vpq_memc_suspend_resume.KPHASE__KPHASE_FORCE_G0 = IoReg_Read32(KPHASE__KPHASE_FORCE_G0_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_FORCE_G1 = IoReg_Read32(KPHASE__KPHASE_FORCE_G1_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_MEMC_INDEX = IoReg_Read32(KPHASE__KPHASE_MEMC_INDEX_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_FILM = IoReg_Read32(KPHASE__KPHASE_FILM_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_DEC_INDEX = IoReg_Read32(KPHASE__KPHASE_IN_DEC_INDEX_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G0 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G0_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G1 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G1_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G2 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G2_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G3 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G3_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G4 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G4_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G5 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G5_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G6 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G6_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G7 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G7_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G8 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G8_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G9 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G9_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G10 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G10_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G11 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G11_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G12 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G12_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G13 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G13_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G14 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G14_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G15 = IoReg_Read32(KPHASE__KPHASE_IN_PHASE_G15_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_DEC_MATCHPERIOD = IoReg_Read32(KPHASE__KPHASE_DEC_MATCHPERIOD_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED0 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED0_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED1 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED1_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED2 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED2_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED3 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED3_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED4 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED4_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED5 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED5_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED6 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED6_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED7 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED7_ADDR);
	vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED8 = IoReg_Read32(KPHASE__KPHASE_ME2_FILED8_ADDR);
	//Hardware
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_00 = IoReg_Read32(HARDWARE__HARDWARE_00_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_01 = IoReg_Read32(HARDWARE__HARDWARE_01_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_02 = IoReg_Read32(HARDWARE__HARDWARE_02_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_03 = IoReg_Read32(HARDWARE__HARDWARE_03_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_04 = IoReg_Read32(HARDWARE__HARDWARE_04_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_05 = IoReg_Read32(HARDWARE__HARDWARE_05_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_06 = IoReg_Read32(HARDWARE__HARDWARE_06_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_07 = IoReg_Read32(HARDWARE__HARDWARE_07_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_08 = IoReg_Read32(HARDWARE__HARDWARE_08_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_09 = IoReg_Read32(HARDWARE__HARDWARE_09_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_10 = IoReg_Read32(HARDWARE__HARDWARE_10_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_11 = IoReg_Read32(HARDWARE__HARDWARE_11_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_12 = IoReg_Read32(HARDWARE__HARDWARE_12_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_13 = IoReg_Read32(HARDWARE__HARDWARE_13_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_14 = IoReg_Read32(HARDWARE__HARDWARE_14_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_15 = IoReg_Read32(HARDWARE__HARDWARE_15_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_16 = IoReg_Read32(HARDWARE__HARDWARE_16_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_17 = IoReg_Read32(HARDWARE__HARDWARE_17_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_18 = IoReg_Read32(HARDWARE__HARDWARE_18_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_19 = IoReg_Read32(HARDWARE__HARDWARE_19_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_20 = IoReg_Read32(HARDWARE__HARDWARE_20_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_21 = IoReg_Read32(HARDWARE__HARDWARE_21_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_22 = IoReg_Read32(HARDWARE__HARDWARE_22_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_23 = IoReg_Read32(HARDWARE__HARDWARE_23_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_24 = IoReg_Read32(HARDWARE__HARDWARE_24_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_25 = IoReg_Read32(HARDWARE__HARDWARE_25_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_26 = IoReg_Read32(HARDWARE__HARDWARE_26_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_27 = IoReg_Read32(HARDWARE__HARDWARE_27_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_28 = IoReg_Read32(HARDWARE__HARDWARE_28_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_29 = IoReg_Read32(HARDWARE__HARDWARE_29_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_30 = IoReg_Read32(HARDWARE__HARDWARE_30_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_31 = IoReg_Read32(HARDWARE__HARDWARE_31_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_32 = IoReg_Read32(HARDWARE__HARDWARE_32_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_33 = IoReg_Read32(HARDWARE__HARDWARE_33_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_34 = IoReg_Read32(HARDWARE__HARDWARE_34_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_35 = IoReg_Read32(HARDWARE__HARDWARE_35_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_36 = IoReg_Read32(HARDWARE__HARDWARE_36_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_37 = IoReg_Read32(HARDWARE__HARDWARE_37_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_38 = IoReg_Read32(HARDWARE__HARDWARE_38_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_39 = IoReg_Read32(HARDWARE__HARDWARE_39_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_40 = IoReg_Read32(HARDWARE__HARDWARE_40_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_41 = IoReg_Read32(HARDWARE__HARDWARE_41_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_42 = IoReg_Read32(HARDWARE__HARDWARE_42_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_43 = IoReg_Read32(HARDWARE__HARDWARE_43_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_44 = IoReg_Read32(HARDWARE__HARDWARE_44_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_45 = IoReg_Read32(HARDWARE__HARDWARE_45_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_46 = IoReg_Read32(HARDWARE__HARDWARE_46_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_47 = IoReg_Read32(HARDWARE__HARDWARE_47_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_48 = IoReg_Read32(HARDWARE__HARDWARE_48_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_49 = IoReg_Read32(HARDWARE__HARDWARE_49_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_50 = IoReg_Read32(HARDWARE__HARDWARE_50_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_51 = IoReg_Read32(HARDWARE__HARDWARE_51_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_52 = IoReg_Read32(HARDWARE__HARDWARE_52_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_53 = IoReg_Read32(HARDWARE__HARDWARE_53_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_54 = IoReg_Read32(HARDWARE__HARDWARE_54_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_55 = IoReg_Read32(HARDWARE__HARDWARE_55_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_56 = IoReg_Read32(HARDWARE__HARDWARE_56_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_57 = IoReg_Read32(HARDWARE__HARDWARE_57_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_58 = IoReg_Read32(HARDWARE__HARDWARE_58_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_59 = IoReg_Read32(HARDWARE__HARDWARE_59_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_60 = IoReg_Read32(HARDWARE__HARDWARE_60_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_61 = IoReg_Read32(HARDWARE__HARDWARE_61_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_62 = IoReg_Read32(HARDWARE__HARDWARE_62_ADDR);
	vpq_memc_suspend_resume.HARDWARE__HARDWARE_63 = IoReg_Read32(HARDWARE__HARDWARE_63_ADDR);
	//Software
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_00 = IoReg_Read32(SOFTWARE__SOFTWARE_00_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_01 = IoReg_Read32(SOFTWARE__SOFTWARE_01_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_02 = IoReg_Read32(SOFTWARE__SOFTWARE_02_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_03 = IoReg_Read32(SOFTWARE__SOFTWARE_03_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_04 = IoReg_Read32(SOFTWARE__SOFTWARE_04_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_05 = IoReg_Read32(SOFTWARE__SOFTWARE_05_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_06 = IoReg_Read32(SOFTWARE__SOFTWARE_06_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_07 = IoReg_Read32(SOFTWARE__SOFTWARE_07_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_08 = IoReg_Read32(SOFTWARE__SOFTWARE_08_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_09 = IoReg_Read32(SOFTWARE__SOFTWARE_09_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_10 = IoReg_Read32(SOFTWARE__SOFTWARE_10_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_11 = IoReg_Read32(SOFTWARE__SOFTWARE_11_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_12 = IoReg_Read32(SOFTWARE__SOFTWARE_12_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_13 = IoReg_Read32(SOFTWARE__SOFTWARE_13_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_14 = IoReg_Read32(SOFTWARE__SOFTWARE_14_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_15 = IoReg_Read32(SOFTWARE__SOFTWARE_15_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_16 = IoReg_Read32(SOFTWARE__SOFTWARE_16_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_17 = IoReg_Read32(SOFTWARE__SOFTWARE_17_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_18 = IoReg_Read32(SOFTWARE__SOFTWARE_18_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_19 = IoReg_Read32(SOFTWARE__SOFTWARE_19_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_20 = IoReg_Read32(SOFTWARE__SOFTWARE_20_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_21 = IoReg_Read32(SOFTWARE__SOFTWARE_21_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_22 = IoReg_Read32(SOFTWARE__SOFTWARE_22_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_23 = IoReg_Read32(SOFTWARE__SOFTWARE_23_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_24 = IoReg_Read32(SOFTWARE__SOFTWARE_24_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_25 = IoReg_Read32(SOFTWARE__SOFTWARE_25_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_26 = IoReg_Read32(SOFTWARE__SOFTWARE_26_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_27 = IoReg_Read32(SOFTWARE__SOFTWARE_27_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_28 = IoReg_Read32(SOFTWARE__SOFTWARE_28_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_29 = IoReg_Read32(SOFTWARE__SOFTWARE_29_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_30 = IoReg_Read32(SOFTWARE__SOFTWARE_30_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_31 = IoReg_Read32(SOFTWARE__SOFTWARE_31_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_32 = IoReg_Read32(SOFTWARE__SOFTWARE_32_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_33 = IoReg_Read32(SOFTWARE__SOFTWARE_33_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_34 = IoReg_Read32(SOFTWARE__SOFTWARE_34_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_35 = IoReg_Read32(SOFTWARE__SOFTWARE_35_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_36 = IoReg_Read32(SOFTWARE__SOFTWARE_36_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_37 = IoReg_Read32(SOFTWARE__SOFTWARE_37_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_38 = IoReg_Read32(SOFTWARE__SOFTWARE_38_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_39 = IoReg_Read32(SOFTWARE__SOFTWARE_39_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_40 = IoReg_Read32(SOFTWARE__SOFTWARE_40_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_41 = IoReg_Read32(SOFTWARE__SOFTWARE_41_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_42 = IoReg_Read32(SOFTWARE__SOFTWARE_42_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_43 = IoReg_Read32(SOFTWARE__SOFTWARE_43_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_44 = IoReg_Read32(SOFTWARE__SOFTWARE_44_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_45 = IoReg_Read32(SOFTWARE__SOFTWARE_45_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_46 = IoReg_Read32(SOFTWARE__SOFTWARE_46_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_47 = IoReg_Read32(SOFTWARE__SOFTWARE_47_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_48 = IoReg_Read32(SOFTWARE__SOFTWARE_48_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_49 = IoReg_Read32(SOFTWARE__SOFTWARE_49_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_50 = IoReg_Read32(SOFTWARE__SOFTWARE_50_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_51 = IoReg_Read32(SOFTWARE__SOFTWARE_51_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_52 = IoReg_Read32(SOFTWARE__SOFTWARE_52_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_53 = IoReg_Read32(SOFTWARE__SOFTWARE_53_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_54 = IoReg_Read32(SOFTWARE__SOFTWARE_54_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_55 = IoReg_Read32(SOFTWARE__SOFTWARE_55_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_56 = IoReg_Read32(SOFTWARE__SOFTWARE_56_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_57 = IoReg_Read32(SOFTWARE__SOFTWARE_57_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_58 = IoReg_Read32(SOFTWARE__SOFTWARE_58_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_59 = IoReg_Read32(SOFTWARE__SOFTWARE_59_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_60 = IoReg_Read32(SOFTWARE__SOFTWARE_60_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_61 = IoReg_Read32(SOFTWARE__SOFTWARE_61_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_62 = IoReg_Read32(SOFTWARE__SOFTWARE_62_ADDR);
	vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_63 = IoReg_Read32(SOFTWARE__SOFTWARE_63_ADDR);

	//MEMC mux
	vpq_memc_suspend_resume.MEMC_MUX_MEMC_MUX_FUNC_CTRL_SUSPEND = IoReg_Read32(MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg);
	//FBG
	vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	//clock
	vpq_memc_suspend_resume.SYS_REG_SYS_DISPCLKSEL_SUSPEND = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	vpq_memc_suspend_resume.MEMC_LATENCY01 = IoReg_Read32(MEMC_LATENCY01_ADDR);
	vpq_memc_suspend_resume.MEMC_LATENCY02 = IoReg_Read32(MEMC_LATENCY02_ADDR);
#ifdef CONFIG_HW_SUPPORT_MEMC
	//ME memory boundary
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_DOWNLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Me_downlimit_addr_reg);
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_UPLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Me_uplimit_addr_reg);
	//MC memory boundary
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_DOWNLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Mc_downlimit_addr_reg);
	vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_UPLIMIT = IoReg_Read32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg);
#endif
	//MC DMA disable
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_02_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_02_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_03_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_03_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_04_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_04_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_05_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_05_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_06_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_06_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KMC_DM_TOP__KMC_07_AGENT = vpq_memc_suspend_resume.KMC_DM_TOP__KMC_07_AGENT & 0xffefffff;

	//ME DMA disable
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_01_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_01_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_02_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_02_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_03_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_03_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_06_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_06_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP0__KME_07_AGENT = vpq_memc_suspend_resume.KME_DM_TOP0__KME_07_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_09_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_09_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_11_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_11_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_13_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_13_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_AGENT & 0xffefffff;
	vpq_memc_suspend_resume.KME_DM_TOP1__KME_15_AGENT = vpq_memc_suspend_resume.KME_DM_TOP1__KME_15_AGENT & 0xffefffff;

	#endif
}

void vpq_memc_disp_resume_instanboot(void){
	#ifdef CONFIG_HW_SUPPORT_MEMC
#if 0//BISR, BIST will be checked
		//KME BISR
		unsigned int iMaxCount_kme = 100;
		unsigned rstn_bits_kme = IP_rstn_bits_kme;
		unsigned done_bits_kme = IP_done_bits_kme;
		unsigned remap_bits_kme = IP_remap_bits_kme;
		unsigned repair_check_bits_kme = IP_repair_check_bits_kme;
		unsigned fail_bits_kme = IP_fail_bits_kme;

		rtd_printk(KERN_DEBUG, TAG_NAME, "\n[MEMC] KME: BISR testing ....\n");
		rtd_maskl(SYS_REG_SYS_SRST3_reg, ~(_BIT29), (_BIT29));	//enable RBUS clk of MEMC reset reg
		rtd_maskl(SYS_REG_SYS_CLKEN3_reg, ~(_BIT29), (_BIT29));   //enable RBUS clk of MEMC
		rtd_maskl(SYS_REG_SYS_CLKEN3_reg, ~(_BIT31|_BIT30), 0);   //disable CLKEN_MEMC/CLKEN_MEME_ME
		rtd_maskl(SYS_REG_SYS_SRST3_reg, ~(_BIT31|_BIT30), 0);//reset of memc
		rtd_maskl(SYS_REG_SYS_SRST3_reg, ~(_BIT31|_BIT30), (_BIT31|_BIT30));//release reset of memc
		rtd_maskl(SYS_REG_SYS_CLKEN3_reg, ~(_BIT31|_BIT30), (_BIT31|_BIT30));	  //enable CLKEN_MEMC/CLKEN_MEME_ME
		rtd_maskl(SYS_REG_SYS_DISPCLKSEL_reg, ~(_BIT27|_BIT26), 0);   //dispd-clock div 2

		rtd_setbits(bisr_rstn_addr_kme, rstn_bits_kme);
		udelay(100);
		while((rtd_inl(bisr_done_addr_kme) & done_bits_kme) != done_bits_kme) {
			iMaxCount_kme--;
			udelay(100);
			if( iMaxCount_kme == 0 ) {
				break;
			}
		}
		rtd_setbits(bisr_remap_addr_kme, remap_bits_kme);

		if((rtd_inl(bisr_repair_addr_kme) & repair_check_bits_kme) != 0) {
			rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]KME: Need to repair\n");
		}


		if((rtd_inl(bisr_fail_addr_kme) & fail_bits_kme) != 0) {
			rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]KME: BISR fail!\n");
		}

		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]Finish ME BISR testing %s\n\n", (iMaxCount_kme ? "done" : "fail" ) );

		//KMC BISR
		unsigned int iMaxCount_kmc = 100;
		unsigned rstn_bits_kmc = IP_rstn_bits_kmc;
		unsigned done_bits_kmc = IP_done_bits_kmc;
		unsigned remap_bits_kmc = IP_remap_bits_kmc;
		unsigned repair_check_bits_kmc = IP_repair_check_bits_kmc;
		unsigned fail_bits_kmc = IP_fail_bits_kmc;

		rtd_printk(KERN_DEBUG, TAG_NAME, "\n[MEMC]KMC: BISR testing ....\n");

		rtd_setbits(bisr_rstn_addr_kmc, rstn_bits_kmc);
		udelay(100);
		while((rtd_inl(bisr_done_addr_kmc) & done_bits_kmc) != done_bits_kmc) {
			iMaxCount_kmc--;
			udelay(100);
			if( iMaxCount_kmc == 0 ) {
				break;
			}
		}
		rtd_setbits(bisr_remap_addr_kmc, remap_bits_kmc);

		if((rtd_inl(bisr_repair_addr_kmc) & repair_check_bits_kmc) != 0) {
			rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]KMC: Need to repair\n");
		}


		if((rtd_inl(bisr_fail_addr_kmc) & fail_bits_kmc) != 0) {
			rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]KMC: BISR fail!\n");
		}

		rtd_printk(KERN_DEBUG, TAG_NAME, "[MEMC]Finish MC BISR testing %s\n\n", (iMaxCount_kmc ? "done" : "fail" ) );

	rtd_maskl(SYS_REG_SYS_SRST3_reg, ~(_BIT29), (_BIT29));	//enable RBUS clk of MEMC reset reg
	rtd_maskl(SYS_REG_SYS_CLKEN3_reg, ~(_BIT29), (_BIT29));   //enable RBUS clk of MEMC
	rtd_maskl(SYS_REG_SYS_CLKEN3_reg, ~(_BIT31|_BIT30), 0);   //disable CLKEN_MEMC/CLKEN_MEME_ME
	rtd_maskl(SYS_REG_SYS_SRST3_reg, ~(_BIT31|_BIT30), 0);//reset of memc
	rtd_maskl(SYS_REG_SYS_SRST3_reg, ~(_BIT31|_BIT30), (_BIT31|_BIT30));//release reset of memc
	rtd_maskl(SYS_REG_SYS_CLKEN3_reg, ~(_BIT31|_BIT30), (_BIT31|_BIT30));	  //enable CLKEN_MEMC/CLKEN_MEME_ME
	rtd_maskl(SYS_REG_SYS_DISPCLKSEL_reg, ~(_BIT27|_BIT26), 0);   //dispd-clock div 2
#endif

#if 0
	static unsigned int time_s=0, time_e=0;
	static unsigned int time_check1 = 0;

	time_s = rtd_inl(0xB801B6A8);
#endif
	//KMC_TOP
	IoReg_Write32(KMC_TOP__TOP_PATT_TOTAL_ADDR , vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_TOTAL);
	IoReg_Write32(KMC_TOP__TOP_PATT_ACT_ADDR , vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_ACT);
	IoReg_Write32(KMC_TOP__TOP_PATT_WIDTH_BPORCH_ADDR , vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_WIDTH_BPORCH);
	IoReg_Write32(KMC_TOP__TOP_PATT_CTRL_ADDR , vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_CTRL);
	IoReg_Write32(KMC_TOP__TOP_PATT_RGB0_ADDR , vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_RGB0);
	IoReg_Write32(KMC_TOP__TOP_PATT_RGB1_ADDR , vpq_memc_suspend_resume.KMC_TOP__TOP_PATT_RGB1);
	IoReg_Write32(KMC_TOP__KMC_IN_INT_CTRL_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_IN_INT_CTRL);
	IoReg_Write32(KMC_TOP__KMC_METER_DETIAL_CORING0_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_METER_DETIAL_CORING0);
	IoReg_Write32(KMC_TOP__KMC_VH_DETAIL_MODE_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_VH_DETAIL_MODE);
	IoReg_Write32(KMC_TOP__KMC_VH_DETAIL_TH_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_VH_DETAIL_TH);
	IoReg_Write32(KMC_TOP__KMC_METER_DETIAL_CORING1_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_METER_DETIAL_CORING1);
	IoReg_Write32(KMC_TOP__KMC_METER_DETIAL_CORING2_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_METER_DETIAL_CORING2);
	IoReg_Write32(KMC_TOP__KNR_ACTIVE_NUM_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_ACTIVE_NUM);
	IoReg_Write32(KMC_TOP__KNR_BPORCH_NUM_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_BPORCH_NUM);
	IoReg_Write32(KMC_TOP__KMC_IPMC0_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_IPMC0);
	IoReg_Write32(KMC_TOP__KMC_IPMC1_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_IPMC1);
	IoReg_Write32(KMC_TOP__KNR_CSC_COEF0_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF0);
	IoReg_Write32(KMC_TOP__KNR_CSC_COEF1_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF1);
	IoReg_Write32(KMC_TOP__KNR_CSC_COEF2_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF2);
	IoReg_Write32(KMC_TOP__KNR_CSC_COEF3_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF3);
	IoReg_Write32(KMC_TOP__KNR_CSC_COEF4_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF4);
	IoReg_Write32(KMC_TOP__KNR_CSC_COEF5_ADDR , vpq_memc_suspend_resume.KMC_TOP__KNR_CSC_COEF5);
	IoReg_Write32(KMC_TOP__KMC_DRF_BIST_IN_0_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_0);
	IoReg_Write32(KMC_TOP__KMC_DRF_BIST_IN_1_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_1);
	IoReg_Write32(KMC_TOP__KMC_DRF_BIST_IN_2_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_2);
	IoReg_Write32(KMC_TOP__KMC_DRF_BIST_IN_3_ADDR , vpq_memc_suspend_resume.KMC_TOP__KMC_DRF_BIST_IN_3);
	//IPPRE
	IoReg_Write32(IPPRE__INPUT_CURSOR_ADDR , vpq_memc_suspend_resume.IPPRE__INPUT_CURSOR);
	IoReg_Write32(IPPRE__INPUT_CURSOR_UV_ADDR , vpq_memc_suspend_resume.IPPRE__INPUT_CURSOR_UV);
	IoReg_Write32(IPPRE__IPPRE_RETIMING_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_RETIMING);
	IoReg_Write32(IPPRE__LOGO_BLEND_ADDR , vpq_memc_suspend_resume.IPPRE__LOGO_BLEND);
	IoReg_Write32(IPPRE__PATT_HV_ACTIVE_ADDR , vpq_memc_suspend_resume.IPPRE__PATT_HV_ACTIVE);
	IoReg_Write32(IPPRE__PATT_HV_TOTAL_ADDR , vpq_memc_suspend_resume.IPPRE__PATT_HV_TOTAL);
	IoReg_Write32(IPPRE__IPPRE_444TO422_COEF0_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_444TO422_COEF0);
	IoReg_Write32(IPPRE__IPPRE_444TO422_COEF1_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_444TO422_COEF1);
	IoReg_Write32(IPPRE__PATT_MODE_CTRL_ADDR , vpq_memc_suspend_resume.IPPRE__PATT_MODE_CTRL);
	IoReg_Write32(IPPRE__LOOP_PATT_SEQUENCY_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_SEQUENCY);
	IoReg_Write32(IPPRE__PATT_PARA_0_ADDR , vpq_memc_suspend_resume.IPPRE__PATT_PARA_0);
	IoReg_Write32(IPPRE__PATT_PARA_1_ADDR , vpq_memc_suspend_resume.IPPRE__PATT_PARA_1);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA0_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA0);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA1_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA1);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA2_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA2);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA3_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA3);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA4_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA4);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA5_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA5);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA6_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA6);
	IoReg_Write32(IPPRE__LOOP_PATT_PARA7_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_PATT_PARA7);
	IoReg_Write32(IPPRE__LOOP_SCROLL_CTRL_ADDR , vpq_memc_suspend_resume.IPPRE__LOOP_SCROLL_CTRL);
	IoReg_Write32(IPPRE__SCROLL_BAR_HV_ADDR , vpq_memc_suspend_resume.IPPRE__SCROLL_BAR_HV);
	IoReg_Write32(IPPRE__SCROLL_BAR_COLOR_ADDR , vpq_memc_suspend_resume.IPPRE__SCROLL_BAR_COLOR);
	IoReg_Write32(IPPRE__SPEED_HV_1_ADDR , vpq_memc_suspend_resume.IPPRE__SPEED_HV_1);
	IoReg_Write32(IPPRE__CIRCLE_CADENCE_ADDR , vpq_memc_suspend_resume.IPPRE__CIRCLE_CADENCE);
	IoReg_Write32(IPPRE__CIRCLE_CENTER_ADDR , vpq_memc_suspend_resume.IPPRE__CIRCLE_CENTER);
	IoReg_Write32(IPPRE__RANDOM_SEED_ADDR , vpq_memc_suspend_resume.IPPRE__RANDOM_SEED);
	IoReg_Write32(IPPRE__RANDOM_CTRL_ADDR , vpq_memc_suspend_resume.IPPRE__RANDOM_CTRL);
	IoReg_Write32(IPPRE__CADENCE_FRM_ADDR , vpq_memc_suspend_resume.IPPRE__CADENCE_FRM);
	IoReg_Write32(IPPRE__CSC_COEF0_H_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF0_H);
	IoReg_Write32(IPPRE__CSC_COEF1_H_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF1_H);
	IoReg_Write32(IPPRE__CSC_COEF2_H_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF2_H);
	IoReg_Write32(IPPRE__CSC_COEF3_H_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF3_H);
	IoReg_Write32(IPPRE__CSC_COEF4_H_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF4_H);
	IoReg_Write32(IPPRE__CSC_COEF5_H_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF5_H);
	IoReg_Write32(IPPRE__CSC_COEF0_L_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF0_L);
	IoReg_Write32(IPPRE__CSC_COEF1_L_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF1_L);
	IoReg_Write32(IPPRE__CSC_COEF2_L_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF2_L);
	IoReg_Write32(IPPRE__CSC_COEF3_L_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF3_L);
	IoReg_Write32(IPPRE__CSC_COEF4_L_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF4_L);
	IoReg_Write32(IPPRE__CSC_COEF5_L_ADDR , vpq_memc_suspend_resume.IPPRE__CSC_COEF5_L);
	IoReg_Write32(IPPRE__IPPRE_MUTE_G4_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G4);
	IoReg_Write32(IPPRE__HPATTERN0_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN0);
	IoReg_Write32(IPPRE__HPATTERN1_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN1);
	IoReg_Write32(IPPRE__HPATTERN2_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN2);
	IoReg_Write32(IPPRE__HPATTERN3_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN3);
	IoReg_Write32(IPPRE__HPATTERN4_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN4);
	IoReg_Write32(IPPRE__HPATTERN5_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN5);
	IoReg_Write32(IPPRE__HPATTERN6_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN6);
	IoReg_Write32(IPPRE__HPATTERN7_ADDR , vpq_memc_suspend_resume.IPPRE__HPATTERN7);
	IoReg_Write32(IPPRE__IPPRE_MUTE_G0_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G0);
	IoReg_Write32(IPPRE__IPPRE_MUTE_G1_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G1);
	IoReg_Write32(IPPRE__IPPRE_MUTE_G2_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G2);
	IoReg_Write32(IPPRE__IPPRE_MUTE_G3_ADDR , vpq_memc_suspend_resume.IPPRE__IPPRE_MUTE_G3);
	//KMC_CPR_TOP0
	IoReg_Write32(KMC_CPR_TOP0__CPR_CTRL0_REG_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL0_REG);
	IoReg_Write32(KMC_CPR_TOP0__CPR_CTRL1_REG_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL1_REG);
	IoReg_Write32(KMC_CPR_TOP0__CPR_CTRL2_REG_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL2_REG);
	IoReg_Write32(KMC_CPR_TOP0__CPR_CTRL3_REG_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL3_REG);
	IoReg_Write32(KMC_CPR_TOP0__CPR_CTRL4_REG_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_CTRL4_REG);
	IoReg_Write32(KMC_CPR_TOP0__BUDGET_PACKET_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_PACKET);
	IoReg_Write32(KMC_CPR_TOP0__BUDGET_INIT_START_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_INIT_START);
	IoReg_Write32(KMC_CPR_TOP0__BUDGET_INIT_END_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_INIT_END);
	IoReg_Write32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG0);
	IoReg_Write32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG1);
	IoReg_Write32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG2);
	IoReg_Write32(KMC_CPR_TOP0__BUDGET_CREDITS_CFG3_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__BUDGET_CREDITS_CFG3);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP3_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP3);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP4_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP4);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP5_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP5);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP6_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP6);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_QBPP7_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_QBPP7);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC0_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC0_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC1_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC1_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC2_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC2_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC3_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC3_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC4_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC4_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC5_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC5_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC6_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC6_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC7_VAR0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC7_VAR0);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC0_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC0_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC1_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC1_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC2_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC2_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC3_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC3_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC4_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC4_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC5_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC5_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC6_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC6_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC7_VAR1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC7_VAR1);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC0_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC0_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC1_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC1_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC2_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC2_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC3_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC3_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC4_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC4_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC5_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC5_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC6_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC6_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CURVE_TRUNC7_VAR2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CURVE_TRUNC7_VAR2);
	IoReg_Write32(KMC_CPR_TOP0__CORE_DELAY_CTRL_I_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CORE_DELAY_CTRL_I);
	IoReg_Write32(KMC_CPR_TOP0__CORE_DELAY_CTRL_P_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CORE_DELAY_CTRL_P);
	IoReg_Write32(KMC_CPR_TOP0__CORE_DELAY_CTRL_NR_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CORE_DELAY_CTRL_NR);
	IoReg_Write32(KMC_CPR_TOP0__CPR_EROSION_RATIO_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_EROSION_RATIO);
	IoReg_Write32(KMC_CPR_TOP0__CPR_MOTION_DIFF_THD_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_MOTION_DIFF_THD);
	IoReg_Write32(KMC_CPR_TOP0__CPR_LF_VARIANCE_CHECK_THD_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_VARIANCE_CHECK_THD);
	IoReg_Write32(KMC_CPR_TOP0__CPR_HF_VARIANCE_CHECK_THD_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_VARIANCE_CHECK_THD);
	IoReg_Write32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL0);
	IoReg_Write32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL1);
	IoReg_Write32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL2);
	IoReg_Write32(KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL3_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_LF_DICT_PENALTY_CTRL3);
	IoReg_Write32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL0);
	IoReg_Write32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL1);
	IoReg_Write32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL2_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL2);
	IoReg_Write32(KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL3_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP0__CPR_HF_DICT_PENALTY_CTRL3);
	//KMC_CPR_TOP1
	IoReg_Write32(KMC_CPR_TOP1__PATT_CTRL0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_CTRL0);
	IoReg_Write32(KMC_CPR_TOP1__PATT_LF_I_POSITION0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_I_POSITION0);
	IoReg_Write32(KMC_CPR_TOP1__PATT_LF_I_POSITION1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_I_POSITION1);
	IoReg_Write32(KMC_CPR_TOP1__PATT_HF_I_POSITION0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_I_POSITION0);
	IoReg_Write32(KMC_CPR_TOP1__PATT_HF_I_POSITION1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_I_POSITION1);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING0);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_I_SETTING1);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING0);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_I_SETTING1);
	IoReg_Write32(KMC_CPR_TOP1__PATT_LF_P_POSITION0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_P_POSITION0);
	IoReg_Write32(KMC_CPR_TOP1__PATT_LF_P_POSITION1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_P_POSITION1);
	IoReg_Write32(KMC_CPR_TOP1__PATT_HF_P_POSITION0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_P_POSITION0);
	IoReg_Write32(KMC_CPR_TOP1__PATT_HF_P_POSITION1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_P_POSITION1);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING0);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_P_SETTING1);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING0);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_P_SETTING1);
	IoReg_Write32(KMC_CPR_TOP1__PATT_LF_NR_POSITION0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_NR_POSITION0);
	IoReg_Write32(KMC_CPR_TOP1__PATT_LF_NR_POSITION1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_LF_NR_POSITION1);
	IoReg_Write32(KMC_CPR_TOP1__PATT_HF_NR_POSITION0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_NR_POSITION0);
	IoReg_Write32(KMC_CPR_TOP1__PATT_HF_NR_POSITION1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__PATT_HF_NR_POSITION1);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING0);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_LF_NR_SETTING1);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING0);
	IoReg_Write32(KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING1_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_PATT_HF_NR_SETTING1);
	IoReg_Write32(KMC_CPR_TOP1__CPR_DEBUG_CFG0_ADDR , vpq_memc_suspend_resume.KMC_CPR_TOP1__CPR_DEBUG_CFG0);
	//KMC_DM_TOP
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS0);
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS1);
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS2_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS2);
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS3_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS3);
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS4_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS4);
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS5_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS5);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS0);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS1);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS2_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS2);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS3_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS3);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS4_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS4);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS5_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS5);
	IoReg_Write32(KMC_DM_TOP__KMC_00_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_LR_OFFSET_ADDR);
	IoReg_Write32(KMC_DM_TOP__KMC_00_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_LINE_OFFSET_ADDR);
	IoReg_Write32(KMC_DM_TOP__KMC_00_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_00_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS0);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS1);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS2_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS2);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS3_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS3);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS4_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS4);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS5_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS5);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS0);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS1);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS2_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS2);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS3_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS3);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS4_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS4);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS5_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS5);
	IoReg_Write32(KMC_DM_TOP__KMC_01_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_LR_OFFSET_ADDR);
	IoReg_Write32(KMC_DM_TOP__KMC_01_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_LINE_OFFSET_ADDR);
	IoReg_Write32(KMC_DM_TOP__KMC_01_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_01_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_02_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_02_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_02_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_02_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_03_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_03_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_03_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_03_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_04_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_04_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_04_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_04_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_05_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_05_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_05_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_05_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_06_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_06_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_06_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_06_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_07_AGENT_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_07_AGENT);
	IoReg_Write32(KMC_DM_TOP__KMC_07_THRESHOLD_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_07_THRESHOLD);
	IoReg_Write32(KMC_DM_TOP__KMC_VTOTAL_AND_TIMER_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_VTOTAL_AND_TIMER);
	IoReg_Write32(KMC_DM_TOP__KMC_HOLD_TIME_G0_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_HOLD_TIME_G0);
	IoReg_Write32(KMC_DM_TOP__KMC_HOLD_TIME_G1_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_HOLD_TIME_G1);
	IoReg_Write32(KMC_DM_TOP__KMC_SOURCE_MODE_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_SOURCE_MODE);
	IoReg_Write32(KMC_DM_TOP__KMC_DEBUG_HEAD_G0_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G0);
	IoReg_Write32(KMC_DM_TOP__KMC_DEBUG_HEAD_G1_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G1);
	IoReg_Write32(KMC_DM_TOP__KMC_DEBUG_HEAD_G2_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G2);
	IoReg_Write32(KMC_DM_TOP__KMC_DEBUG_HEAD_G3_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_DEBUG_HEAD_G3);
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS6_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS6);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS6_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS6);
	IoReg_Write32(KMC_DM_TOP__KMC_00_START_ADDRESS7_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_START_ADDRESS7);
	IoReg_Write32(KMC_DM_TOP__KMC_00_END_ADDRESS7_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_00_END_ADDRESS7);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS6_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS6);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS6_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS6);
	IoReg_Write32(KMC_DM_TOP__KMC_01_START_ADDRESS7_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_START_ADDRESS7);
	IoReg_Write32(KMC_DM_TOP__KMC_01_END_ADDRESS7_ADDR , vpq_memc_suspend_resume.KMC_DM_TOP__KMC_01_END_ADDRESS7);
	//MC
	IoReg_Write32(MC__MISC_ADDR , vpq_memc_suspend_resume.MC__MISC);
	IoReg_Write32(MC__PXL_RESOLUTION_ADDR , vpq_memc_suspend_resume.MC__PXL_RESOLUTION);
	IoReg_Write32(MC__BLK_SIZE_ADDR , vpq_memc_suspend_resume.MC__BLK_SIZE);
	IoReg_Write32(MC__BLK_RESOLUTION_ADDR , vpq_memc_suspend_resume.MC__BLK_RESOLUTION);
	IoReg_Write32(MC__DE_FLICKER_ADDR , vpq_memc_suspend_resume.MC__DE_FLICKER);
	IoReg_Write32(MC__VER_LF_SR_ADDR , vpq_memc_suspend_resume.MC__VER_LF_SR);
	IoReg_Write32(MC__VER_HF_SR_ADDR , vpq_memc_suspend_resume.MC__VER_HF_SR);
	IoReg_Write32(MC__HOR_SR_ADDR , vpq_memc_suspend_resume.MC__HOR_SR);
	IoReg_Write32(MC__VER_RIM0_ADDR , vpq_memc_suspend_resume.MC__VER_RIM0);
	IoReg_Write32(MC__HOR_RIM0_ADDR , vpq_memc_suspend_resume.MC__HOR_RIM0);
	IoReg_Write32(MC__VER_RIM1_ADDR , vpq_memc_suspend_resume.MC__VER_RIM1);
	IoReg_Write32(MC__HOR_RIM1_ADDR , vpq_memc_suspend_resume.MC__HOR_RIM1);
	IoReg_Write32(MC__DW_CONTROL_ADDR , vpq_memc_suspend_resume.MC__DW_CONTROL);
	IoReg_Write32(MC__DW_V0_ADDR , vpq_memc_suspend_resume.MC__DW_V0);
	IoReg_Write32(MC__DW_H0_ADDR , vpq_memc_suspend_resume.MC__DW_H0);
	IoReg_Write32(MC__DW_V1_ADDR , vpq_memc_suspend_resume.MC__DW_V1);
	IoReg_Write32(MC__DW_H1_ADDR , vpq_memc_suspend_resume.MC__DW_H1);
	IoReg_Write32(MC__DW_V2_ADDR , vpq_memc_suspend_resume.MC__DW_V2);
	IoReg_Write32(MC__DW_H2_ADDR , vpq_memc_suspend_resume.MC__DW_H2);
	IoReg_Write32(MC__DW_V3_ADDR , vpq_memc_suspend_resume.MC__DW_V3);
	IoReg_Write32(MC__DW_H3_ADDR , vpq_memc_suspend_resume.MC__DW_H3);
	IoReg_Write32(MC__DW_V4_ADDR , vpq_memc_suspend_resume.MC__DW_V4);
	IoReg_Write32(MC__DW_H4_ADDR , vpq_memc_suspend_resume.MC__DW_H4);
	IoReg_Write32(MC__DW_V5_ADDR , vpq_memc_suspend_resume.MC__DW_V5);
	IoReg_Write32(MC__DW_H5_ADDR , vpq_memc_suspend_resume.MC__DW_H5);
	IoReg_Write32(MC__DW_V6_ADDR , vpq_memc_suspend_resume.MC__DW_V6);
	IoReg_Write32(MC__DW_H6_ADDR , vpq_memc_suspend_resume.MC__DW_H6);
	IoReg_Write32(MC__DW_V7_ADDR , vpq_memc_suspend_resume.MC__DW_V7);
	IoReg_Write32(MC__DW_H7_ADDR , vpq_memc_suspend_resume.MC__DW_H7);
	IoReg_Write32(MC__PT_PROC_ADDR , vpq_memc_suspend_resume.MC__PT_PROC);
	IoReg_Write32(MC__OCCL_PROC_ADDR , vpq_memc_suspend_resume.MC__OCCL_PROC);
	IoReg_Write32(MC__OBMC_ADDR , vpq_memc_suspend_resume.MC__OBMC);
	IoReg_Write32(MC__BLEND_ADDR , vpq_memc_suspend_resume.MC__BLEND);
	IoReg_Write32(MC__BLD_MV_DIFF_CURVE_ADDR , vpq_memc_suspend_resume.MC__BLD_MV_DIFF_CURVE);
	IoReg_Write32(MC__MC_SOBJ0_ADDR , vpq_memc_suspend_resume.MC__MC_SOBJ0);
	IoReg_Write32(MC__MC_SOBJ1_ADDR , vpq_memc_suspend_resume.MC__MC_SOBJ1);
	IoReg_Write32(MC__CURSOR0_POSI_ADDR , vpq_memc_suspend_resume.MC__CURSOR0_POSI);
	IoReg_Write32(MC__CURSOR0_COLOR_ADDR , vpq_memc_suspend_resume.MC__CURSOR0_COLOR);
	IoReg_Write32(MC__CURSOR1_POSI_ADDR , vpq_memc_suspend_resume.MC__CURSOR1_POSI);
	IoReg_Write32(MC__CURSOR1_COLOR_ADDR , vpq_memc_suspend_resume.MC__CURSOR1_COLOR);
	IoReg_Write32(MC__GRID_ADDR , vpq_memc_suspend_resume.MC__GRID);
	IoReg_Write32(MC__MC_FORCE_PHASE_ADDR , vpq_memc_suspend_resume.MC__MC_FORCE_PHASE);
	IoReg_Write32(MC__FORCE_MV_ADDR , vpq_memc_suspend_resume.MC__FORCE_MV);
	IoReg_Write32(MC__MC_FALSE_COLOR_ADDR , vpq_memc_suspend_resume.MC__MC_FALSE_COLOR);
	IoReg_Write32(MC__INTERNAL_DEBUG_ADDR , vpq_memc_suspend_resume.MC__INTERNAL_DEBUG);
	//MC2
	IoReg_Write32(MC2__OBMC_COEF0_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF0);
	IoReg_Write32(MC2__OBMC_COEF1_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF1);
	IoReg_Write32(MC2__OBMC_COEF2_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF2);
	IoReg_Write32(MC2__OBMC_COEF3_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF3);
	IoReg_Write32(MC2__OBMC_COEF4_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF4);
	IoReg_Write32(MC2__OBMC_COEF5_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF5);
	IoReg_Write32(MC2__OBMC_COEF6_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF6);
	IoReg_Write32(MC2__OBMC_COEF7_ADDR , vpq_memc_suspend_resume.MC2__OBMC_COEF7);
	IoReg_Write32(MC2__MC_LOGO_CTRL_ADDR , vpq_memc_suspend_resume.MC2__MC_LOGO_CTRL);
	IoReg_Write32(MC2__MC_LOGO_BLK_NUM_ADDR , vpq_memc_suspend_resume.MC2__MC_LOGO_BLK_NUM);
	IoReg_Write32(MC2__MC_LOGO_PXL_NUM_ADDR , vpq_memc_suspend_resume.MC2__MC_LOGO_PXL_NUM);
	IoReg_Write32(MC2__MC_LOGO_LPF_COEF_ADDR , vpq_memc_suspend_resume.MC2__MC_LOGO_LPF_COEF);
	IoReg_Write32(MC2__MC_LOGO_ALPHA_ADDR , vpq_memc_suspend_resume.MC2__MC_LOGO_ALPHA);
	IoReg_Write32(MC2__MC_VAR_LPF0_ADDR , vpq_memc_suspend_resume.MC2__MC_VAR_LPF0);
	IoReg_Write32(MC2__MC_VAR_LPF1_ADDR , vpq_memc_suspend_resume.MC2__MC_VAR_LPF1);
	IoReg_Write32(MC2__MC_VAR_LPF2_ADDR , vpq_memc_suspend_resume.MC2__MC_VAR_LPF2);
	IoReg_Write32(MC2__MC_VAR_LPF3_ADDR , vpq_memc_suspend_resume.MC2__MC_VAR_LPF3);
	IoReg_Write32(MC2__MC_OCCL_DIA_V_ADDR , vpq_memc_suspend_resume.MC2__MC_OCCL_DIA_V);
	IoReg_Write32(MC2__MC_OCCL_DIA_C_ADDR , vpq_memc_suspend_resume.MC2__MC_OCCL_DIA_C);
	IoReg_Write32(MC2__MC_OCCL_DIA_H_ADDR , vpq_memc_suspend_resume.MC2__MC_OCCL_DIA_H);
	IoReg_Write32(MC2__MC_VAR17_LPF0_ADDR , vpq_memc_suspend_resume.MC2__MC_VAR17_LPF0);
	IoReg_Write32(MC2__MC_VAR17_LPF1_ADDR , vpq_memc_suspend_resume.MC2__MC_VAR17_LPF1);
	IoReg_Write32(MC2__MC_VAR17_LPF2_ADDR , vpq_memc_suspend_resume.MC2__MC_VAR17_LPF2);
	//LBMC
	IoReg_Write32(LBMC__LBMC_SR0_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_SR0);
	IoReg_Write32(LBMC__LBMC_SR1_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_SR1);
	IoReg_Write32(LBMC__LBMC_SR2_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_SR2);
	IoReg_Write32(LBMC__LBMC_SR3_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_SR3);
	IoReg_Write32(LBMC__LBMC_SR4_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_SR4);
	IoReg_Write32(LBMC__LBMC_SR5_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_SR5);
	IoReg_Write32(LBMC__LBMC_DUMMY18_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_DUMMY18);
	IoReg_Write32(LBMC__LBMC_DUMMY1C_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_DUMMY1C);
	IoReg_Write32(LBMC__LBMC_RESOLUTION_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_RESOLUTION);
	IoReg_Write32(LBMC__LBMC_MODE_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_MODE);
	IoReg_Write32(LBMC__LBMC_BLANKING_CTRL_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_BLANKING_CTRL);
	IoReg_Write32(LBMC__LBMC_I_IDX_PART0_N_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART0_N);
	IoReg_Write32(LBMC__LBMC_I_IDX_PART1_N_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART1_N);
	IoReg_Write32(LBMC__LBMC_I_IDX_PART2_N_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART2_N);
	IoReg_Write32(LBMC__LBMC_P_IDX_PART0_N_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART0_N);
	IoReg_Write32(LBMC__LBMC_P_IDX_PART1_N_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART1_N);
	IoReg_Write32(LBMC__LBMC_P_IDX_PART2_N_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART2_N);
	IoReg_Write32(LBMC__LBMC_HF_IDX_NUM_N_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_HF_IDX_NUM_N);
	IoReg_Write32(LBMC__LBMC_I_IDX_PART0_S_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART0_S);
	IoReg_Write32(LBMC__LBMC_I_IDX_PART1_S_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART1_S);
	IoReg_Write32(LBMC__LBMC_I_IDX_PART2_S_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_I_IDX_PART2_S);
	IoReg_Write32(LBMC__LBMC_P_IDX_PART0_S_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART0_S);
	IoReg_Write32(LBMC__LBMC_P_IDX_PART1_S_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART1_S);
	IoReg_Write32(LBMC__LBMC_P_IDX_PART2_S_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_P_IDX_PART2_S);
	IoReg_Write32(LBMC__LBMC_HF_IDX_NUM_S_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_HF_IDX_NUM_S);
	IoReg_Write32(LBMC__LBMC_FETCH_POINT_LF_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_FETCH_POINT_LF);
	IoReg_Write32(LBMC__LBMC_FETCH_POINT_HF_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_FETCH_POINT_HF);
	IoReg_Write32(LBMC__LBMC_INFO_GET_NUM_ADDR , vpq_memc_suspend_resume.LBMC__LBMC_INFO_GET_NUM);
	//BBD
	IoReg_Write32(BBD__BBD_INPUT_THRESHOLD_CTRL_ADDR , vpq_memc_suspend_resume.BBD__BBD_INPUT_THRESHOLD_CTRL);
	IoReg_Write32(BBD__BBD_INPUT_H_THRESHOLD_CTRL_ADDR , vpq_memc_suspend_resume.BBD__BBD_INPUT_H_THRESHOLD_CTRL);
	IoReg_Write32(BBD__BBD_INPUT_V_THRESHOLD_CTRL_ADDR , vpq_memc_suspend_resume.BBD__BBD_INPUT_V_THRESHOLD_CTRL);
	IoReg_Write32(BBD__BBD_WINDOW_START_POINT_ADDR , vpq_memc_suspend_resume.BBD__BBD_WINDOW_START_POINT);
	IoReg_Write32(BBD__BBD_WINDOW_END_POINT_ADDR , vpq_memc_suspend_resume.BBD__BBD_WINDOW_END_POINT);
	//KMC_METER_TOP
	IoReg_Write32(KMC_METER_TOP__KMC_METER_YUV_X_POS_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_YUV_X_POS);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_YUV_Y_POS_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_YUV_Y_POS);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_X_POS_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_X_POS);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_Y_POS_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_Y_POS);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FACTOR_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FACTOR);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_0001_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0001);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_0203_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0203);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_0405_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0405);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_0607_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0607);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_0809_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0809);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_0A0B_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0A0B);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_0C10_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_0C10);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_1112_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1112);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_1314_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1314);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_1516_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1516);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_1718_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1718);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_191A_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_191A);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_FILTER_1B1C_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_FILTER_1B1C);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_DR_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_DR);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_THR0_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_THR0);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_THR1_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_THR1);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_THR2_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_THR2);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_SLP_01_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_SLP_01);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_DETAIL_DR_THR_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_DR_THR);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_DETAIL_THR0_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_THR0);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_DETAIL_THR1_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_THR1);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_DETAIL_THR2_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_DETAIL_THR2);
	IoReg_Write32(KMC_METER_TOP__KMC_METER_BW_CORING1_ADDR , vpq_memc_suspend_resume.KMC_METER_TOP__KMC_METER_BW_CORING1);
	//KMC_DM_METER_TOP
	IoReg_Write32(KMC_DM_METER_TOP__KMC_METER_REG0_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_REG0);
	IoReg_Write32(KMC_DM_METER_TOP__KMC_METER_NUM_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_NUM);
	IoReg_Write32(KMC_DM_METER_TOP__KMC_METER_H_NUM0_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_H_NUM0);
	IoReg_Write32(KMC_DM_METER_TOP__KMC_METER_H_NUM1_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__KMC_METER_H_NUM1);
	IoReg_Write32(KMC_DM_METER_TOP__METER_TH0_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TH0);
	IoReg_Write32(KMC_DM_METER_TOP__METER_TH1_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TH1);
	IoReg_Write32(KMC_DM_METER_TOP__METER_TH3_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TH3);
	IoReg_Write32(KMC_DM_METER_TOP__METER_TIMER0_ADDR , vpq_memc_suspend_resume.KMC_DM_METER_TOP__METER_TIMER0);
	//KME_TOP
	IoReg_Write32(KME_TOP__KME_ME_ABL_SETTING0_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_ME_ABL_SETTING0);
	IoReg_Write32(KME_TOP__ME_ME_ABL_SETTING1_ADDR , vpq_memc_suspend_resume.KME_TOP__ME_ME_ABL_SETTING1);
	IoReg_Write32(KME_TOP__KME_DRF_BIST_IN_0_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_0);
	IoReg_Write32(KME_TOP__KME_DRF_BIST_IN_1_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_1);
	IoReg_Write32(KME_TOP__KME_DRF_BIST_IN_2_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_2);
	IoReg_Write32(KME_TOP__KME_DRF_BIST_IN_3_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_3);
	IoReg_Write32(KME_TOP__KME_DRF_BIST_IN_4_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_4);
	IoReg_Write32(KME_TOP__KME_DRF_BIST_IN_5_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_5);
	IoReg_Write32(KME_TOP__KME_DRF_BIST_IN_6_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DRF_BIST_IN_6);
	IoReg_Write32(KME_TOP__KME_DEHALO_DEBUG_0_ADDR , vpq_memc_suspend_resume.KME_TOP__KME_DEHALO_DEBUG_0);
	IoReg_Write32(KME_TOP__DUMMY0_ADDR , vpq_memc_suspend_resume.KME_TOP__DUMMY0);
	IoReg_Write32(KME_TOP__DUMMY1_ADDR , vpq_memc_suspend_resume.KME_TOP__DUMMY1);
	IoReg_Write32(KME_TOP__DUMMY2_ADDR , vpq_memc_suspend_resume.KME_TOP__DUMMY2);
	IoReg_Write32(KME_TOP__DUMMY3_ADDR , vpq_memc_suspend_resume.KME_TOP__DUMMY3);
	//KME_VBUF_TOP
	IoReg_Write32(KME_VBUF_TOP__VBUF_ACTIVE_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_ACTIVE);
	IoReg_Write32(KME_VBUF_TOP__IP_SEED_INIT_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__IP_SEED_INIT);
	IoReg_Write32(KME_VBUF_TOP__PI_SEED_INIT_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__PI_SEED_INIT);
	IoReg_Write32(KME_VBUF_TOP__LFSR_IP_1ST_MASK_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__LFSR_IP_1ST_MASK);
	IoReg_Write32(KME_VBUF_TOP__ENABLE_1ST_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__ENABLE_1ST);
	IoReg_Write32(KME_VBUF_TOP__ENABLE_2ND_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__ENABLE_2ND);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_1ST_1_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_1);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_1ST_2_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_2);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_1ST_3_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_3);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_1ST_4_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_4);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_1ST_5_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_1ST_5);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_2ND_1_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_1);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_2ND_2_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_2);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_2ND_3_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_3);
	IoReg_Write32(KME_VBUF_TOP__CANDIDATE_2ND_4_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__CANDIDATE_2ND_4);
	IoReg_Write32(KME_VBUF_TOP__MV_XY_RANGE_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__MV_XY_RANGE);
	IoReg_Write32(KME_VBUF_TOP__MV_BLK_TOP_BOT_RIM_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__MV_BLK_TOP_BOT_RIM);
	IoReg_Write32(KME_VBUF_TOP__PIX_TOP_BOT_RIM_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__PIX_TOP_BOT_RIM);
	IoReg_Write32(KME_VBUF_TOP__PIX_LEFT_RIGHT_RIM_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__PIX_LEFT_RIGHT_RIM);
	IoReg_Write32(KME_VBUF_TOP__RIM_ENABLE_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__RIM_ENABLE);
	IoReg_Write32(KME_VBUF_TOP__VBUF_GMV_SEL_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_GMV_SEL);
	IoReg_Write32(KME_VBUF_TOP__VBUF_LOGO_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_LOGO);
	IoReg_Write32(KME_VBUF_TOP__VBUF_REQ_INTERVAL_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_REQ_INTERVAL);
	IoReg_Write32(KME_VBUF_TOP__LFSR_PI_1ST_MASK_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__LFSR_PI_1ST_MASK);
	IoReg_Write32(KME_VBUF_TOP__SINGLE_MODE_DEBUG_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__SINGLE_MODE_DEBUG);
	IoReg_Write32(KME_VBUF_TOP__MULTIMIN_DEBUG_IP_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__MULTIMIN_DEBUG_IP);
	IoReg_Write32(KME_VBUF_TOP__MULTIMIN_DEBUG_PI_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__MULTIMIN_DEBUG_PI);
	IoReg_Write32(KME_VBUF_TOP__MULTIMIN_DEBUG_BLK_IDX_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__MULTIMIN_DEBUG_BLK_IDX);
	IoReg_Write32(KME_VBUF_TOP__VBUF_PPI_DM_DEBUG_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_PPI_DM_DEBUG);
	IoReg_Write32(KME_VBUF_TOP__VBUF_DM_MONITOR_CNT_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_DM_MONITOR_CNT);
	IoReg_Write32(KME_VBUF_TOP__VBUF_DUMMY_0_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_DUMMY_0);
	IoReg_Write32(KME_VBUF_TOP__SC_LFSR_IP_1ST_MASK_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__SC_LFSR_IP_1ST_MASK);
	IoReg_Write32(KME_VBUF_TOP__SC_LFSR_PI_1ST_MASK_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__SC_LFSR_PI_1ST_MASK);
	IoReg_Write32(KME_VBUF_TOP__MEANDER_RIM_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__MEANDER_RIM);
	IoReg_Write32(KME_VBUF_TOP__VBUF_LOGO_DEBUG_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_LOGO_DEBUG);
	IoReg_Write32(KME_VBUF_TOP__VBUF_DEBUG_IDX_ADDR , vpq_memc_suspend_resume.KME_VBUF_TOP__VBUF_DEBUG_IDX);
	//KME_ME1_TOP2
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_00);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_01);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_02);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_03);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_04);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_05);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_06);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_07);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_08);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_09);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_10);
	IoReg_Write32(KME_ME1_TOP2__GMV_CTRL_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__GMV_CTRL_11);
	IoReg_Write32(KME_ME1_TOP2__SW_GMV_CTRL_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__SW_GMV_CTRL_00);
	IoReg_Write32(KME_ME1_TOP2__SW_GMV_CTRL_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__SW_GMV_CTRL_01);
	IoReg_Write32(KME_ME1_TOP2__SW_RMV_CTRL_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP2__SW_RMV_CTRL_00);
	//KME_ME1_TOP3
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_00);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_01);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_02);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_03);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_04);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_05);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_06);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_07);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_08);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_09);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_10);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_11);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_12_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_12);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_13_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_13);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_14_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_14);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_15_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_15);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_16_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_16);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_17_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_17);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_18_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_18);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_19_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_19);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_20_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_20);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_21_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_21);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_22_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_22);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_23_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_23);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_24_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_24);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_25_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_25);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_26_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_26);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_27_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_27);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_28_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_28);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_29_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_29);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_30_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_30);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_MV_CTRL_31_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_MV_CTRL_31);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_00);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_01);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_02);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_03);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_04);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_05);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_06);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_07);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_08);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_09);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_10);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_11);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_12_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_12);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_13_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_13);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_14_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_14);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_CNT_CTRL_15_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_CNT_CTRL_15);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_00);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_01);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_02);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_03);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_04);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_05);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_06);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_07);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_08);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_09);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_10);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_11);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_12_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_12);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_13_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_13);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_14_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_14);
	IoReg_Write32(KME_ME1_TOP3__SW_RMV_UCF_CTRL_15_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP3__SW_RMV_UCF_CTRL_15);
	//KME_ME1_TOP4
	//KME_ME1_TOP5
	//P27
	IoReg_Write32(P27__DEHALO_00_ADDR , vpq_memc_suspend_resume.P27__DEHALO_00);
	IoReg_Write32(P27__DEHALO_04_ADDR , vpq_memc_suspend_resume.P27__DEHALO_04);
	IoReg_Write32(P27__DEHALO_08_ADDR , vpq_memc_suspend_resume.P27__DEHALO_08);
	IoReg_Write32(P27__DEHALO_0C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_0C);
	IoReg_Write32(P27__DEHALO_10_ADDR , vpq_memc_suspend_resume.P27__DEHALO_10);
	IoReg_Write32(P27__DEHALO_14_ADDR , vpq_memc_suspend_resume.P27__DEHALO_14);
	IoReg_Write32(P27__DEHALO_18_ADDR , vpq_memc_suspend_resume.P27__DEHALO_18);
	IoReg_Write32(P27__DEHALO_1C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_1C);
	IoReg_Write32(P27__DEHALO_20_ADDR , vpq_memc_suspend_resume.P27__DEHALO_20);
	IoReg_Write32(P27__DEHALO_24_ADDR , vpq_memc_suspend_resume.P27__DEHALO_24);
	IoReg_Write32(P27__DEHALO_28_ADDR , vpq_memc_suspend_resume.P27__DEHALO_28);
	IoReg_Write32(P27__DEHALO_2C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_2C);
	IoReg_Write32(P27__DEHALO_30_ADDR , vpq_memc_suspend_resume.P27__DEHALO_30);
	IoReg_Write32(P27__DEHALO_34_ADDR , vpq_memc_suspend_resume.P27__DEHALO_34);
	IoReg_Write32(P27__DEHALO_38_ADDR , vpq_memc_suspend_resume.P27__DEHALO_38);
	IoReg_Write32(P27__DEHALO_3C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_3C);
	IoReg_Write32(P27__DEHALO_40_ADDR , vpq_memc_suspend_resume.P27__DEHALO_40);
	IoReg_Write32(P27__DEHALO_44_ADDR , vpq_memc_suspend_resume.P27__DEHALO_44);
	IoReg_Write32(P27__DEHALO_48_ADDR , vpq_memc_suspend_resume.P27__DEHALO_48);
	IoReg_Write32(P27__DEHALO_4C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_4C);
	IoReg_Write32(P27__DEHALO_50_ADDR , vpq_memc_suspend_resume.P27__DEHALO_50);
	IoReg_Write32(P27__DEHALO_54_ADDR , vpq_memc_suspend_resume.P27__DEHALO_54);
	IoReg_Write32(P27__DEHALO_58_ADDR , vpq_memc_suspend_resume.P27__DEHALO_58);
	IoReg_Write32(P27__DEHALO_5C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_5C);
	IoReg_Write32(P27__DEHALO_60_ADDR , vpq_memc_suspend_resume.P27__DEHALO_60);
	IoReg_Write32(P27__DEHALO_64_ADDR , vpq_memc_suspend_resume.P27__DEHALO_64);
	IoReg_Write32(P27__DEHALO_68_ADDR , vpq_memc_suspend_resume.P27__DEHALO_68);
	IoReg_Write32(P27__DEHALO_6C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_6C);
	IoReg_Write32(P27__DEHALO_80_ADDR , vpq_memc_suspend_resume.P27__DEHALO_80);
	IoReg_Write32(P27__DEHALO_84_ADDR , vpq_memc_suspend_resume.P27__DEHALO_84);
	IoReg_Write32(P27__DEHALO_88_ADDR , vpq_memc_suspend_resume.P27__DEHALO_88);
	IoReg_Write32(P27__DEHALO_8C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_8C);
	IoReg_Write32(P27__DEHALO_90_ADDR , vpq_memc_suspend_resume.P27__DEHALO_90);
	IoReg_Write32(P27__DEHALO_94_ADDR , vpq_memc_suspend_resume.P27__DEHALO_94);
	IoReg_Write32(P27__DEHALO_98_ADDR , vpq_memc_suspend_resume.P27__DEHALO_98);
	IoReg_Write32(P27__DEHALO_9C_ADDR , vpq_memc_suspend_resume.P27__DEHALO_9C);
	IoReg_Write32(P27__DEHALO_A0_ADDR , vpq_memc_suspend_resume.P27__DEHALO_A0);
	IoReg_Write32(P27__DEHALO_A4_ADDR , vpq_memc_suspend_resume.P27__DEHALO_A4);
	IoReg_Write32(P27__DEHALO_A8_ADDR , vpq_memc_suspend_resume.P27__DEHALO_A8);
	IoReg_Write32(P27__DEHALO_AC_ADDR , vpq_memc_suspend_resume.P27__DEHALO_AC);
	IoReg_Write32(P27__DEHALO_F0_ADDR , vpq_memc_suspend_resume.P27__DEHALO_F0);
	//KME_LBME_TOP
	IoReg_Write32(KME_LBME_TOP__LBME_X_POS_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_X_POS);
	IoReg_Write32(KME_LBME_TOP__LBME_Y_POS_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_Y_POS);
	IoReg_Write32(KME_LBME_TOP__LBME_DEBUG_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_DEBUG);
	IoReg_Write32(KME_LBME_TOP__LBME_XY_OFFSET_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_XY_OFFSET);
	IoReg_Write32(KME_LBME_TOP__LBME_DEBUG_XY_POS_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_DEBUG_XY_POS);
	IoReg_Write32(KME_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM);
	IoReg_Write32(KME_LBME_TOP__LBME_LINE_LINEBUF_NUM_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_LINE_LINEBUF_NUM);
	IoReg_Write32(KME_LBME_TOP__LBME_REGIONAL_APL_ADDR , vpq_memc_suspend_resume.KME_LBME_TOP__LBME_REGIONAL_APL);
	//KME_LOGO2
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD0_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD0);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD1_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD1);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD2_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD2);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD3_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD3);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD4_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD4);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD5_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD5);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD6_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD6);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD7_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD7);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD8_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD8);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD9_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD9);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD10_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD10);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD11_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD11);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD12_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD12);
	IoReg_Write32(KME_LOGO2__KM_LOGO_PXL_RW_FLD13_ADDR , vpq_memc_suspend_resume.KME_LOGO2__KM_LOGO_PXL_RW_FLD13);
	//KME_IPME
	IoReg_Write32(KME_IPME__KME_IPME_SCALER_DOWN0_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN0);
	IoReg_Write32(KME_IPME__KME_IPME_SCALER_DOWN1_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN1);
	IoReg_Write32(KME_IPME__KME_IPME_SCALER_DOWN2_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN2);
	IoReg_Write32(KME_IPME__KME_IPME_SCALER_DOWN3_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN3);
	IoReg_Write32(KME_IPME__KME_IPME_IIR0_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR0);
	IoReg_Write32(KME_IPME__KME_IPME_IIR1_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR1);
	IoReg_Write32(KME_IPME__KME_IPME_IIR2_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR2);
	IoReg_Write32(KME_IPME__KME_IPME_IIR3_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR3);
	IoReg_Write32(KME_IPME__KME_IPME_IIR4_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_IIR4);
	IoReg_Write32(KME_IPME__KME_IPME_SCALER_DOWN4_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_SCALER_DOWN4);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET_0_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET_0);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET0_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET0);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET1_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET1);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET2_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET2);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET3_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET3);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET4_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET4);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET5_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET5);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET6_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET6);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET7_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET7);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET8_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET8);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET9_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET9);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET10_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET10);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET11_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET11);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET12_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET12);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET13_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET13);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET14_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET14);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET15_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET15);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET16_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET16);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET17_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET17);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET18_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET18);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET19_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET19);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET20_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET20);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET21_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET21);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET22_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET22);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET23_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET23);
	IoReg_Write32(KME_IPME__KME_IPME_FILTER_ALP0_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP0);
	IoReg_Write32(KME_IPME__KME_IPME_FILTER_ALP1_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP1);
	IoReg_Write32(KME_IPME__KME_IPME_FILTER_ALP2_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP2);
	IoReg_Write32(KME_IPME__KME_IPME_FILTER_ALP3_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILTER_ALP3);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET24_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET24);
	IoReg_Write32(KME_IPME__KME_IPME_FILM_DET25_ADDR , vpq_memc_suspend_resume.KME_IPME__KME_IPME_FILM_DET25);
	//KME_IPME1
	IoReg_Write32(KME_IPME1__KME_IPME_FILM_DET_RW0_ADDR , vpq_memc_suspend_resume.KME_IPME1__KME_IPME_FILM_DET_RW0);
	IoReg_Write32(KME_IPME1__KME_IPME_CPRS_RW0_ADDR , vpq_memc_suspend_resume.KME_IPME1__KME_IPME_CPRS_RW0);
	IoReg_Write32(KME_IPME1__KME_IPME_SCALER0_ADDR , vpq_memc_suspend_resume.KME_IPME1__KME_IPME_SCALER0);
	//KME_LOGO0
	IoReg_Write32(KME_LOGO0__KM_LOGO_SCALER0_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER0);
	IoReg_Write32(KME_LOGO0__KM_LOGO_SCALER1_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER1);
	IoReg_Write32(KME_LOGO0__KM_LOGO_SCALER2_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER2);
	IoReg_Write32(KME_LOGO0__KM_LOGO_SCALER3_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_SCALER3);
	IoReg_Write32(KME_LOGO0__KM_LOGO_IIR0_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_IIR0);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK0_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK0);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK1_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK1);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK2_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK2);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK3_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK3);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK4_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK4);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK5_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK5);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK6_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK6);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK7_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK7);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK8_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK8);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK9_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK9);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK10_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK10);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK11_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK11);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK12_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK12);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK13_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK13);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK14_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK14);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK15_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK15);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK16_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK16);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK17_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK17);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK18_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK18);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK19_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK19);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK20_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK20);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK21_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK21);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK22_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK22);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK23_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK23);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK24_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK24);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK25_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK25);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK26_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK26);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK27_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK27);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK28_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK28);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK29_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK29);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK30_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK30);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK31_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK31);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK32_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK32);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK33_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK33);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK34_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK34);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK35_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK35);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK36_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK36);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK37_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK37);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK38_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK38);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK39_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK39);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK40_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK40);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK41_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK41);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK42_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK42);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK43_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK43);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK44_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK44);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK45_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK45);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK46_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK46);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK47_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK47);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK48_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK48);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK49_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK49);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK50_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK50);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK51_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK51);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK52_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK52);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK53_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK53);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK54_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK54);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK55_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK55);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK56_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK56);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK57_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK57);
	IoReg_Write32(KME_LOGO0__KM_LOGO_BLK58_ADDR , vpq_memc_suspend_resume.KME_LOGO0__KM_LOGO_BLK58);
	//KME_LOGO1
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK80_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK80);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK81_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK81);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK82_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK82);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK83_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK83);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK84_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK84);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK85_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK85);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK86_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK86);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK87_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK87);
	IoReg_Write32(KME_LOGO1__KM_LOGO_BLK88_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_BLK88);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL0_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL0);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL1_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL1);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL2_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL2);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL3_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL3);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL4_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL4);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL5_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL5);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL6_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL6);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL7_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL7);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL8_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL8);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL9_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL9);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL10_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL10);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL11_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL11);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL12_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL12);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL13_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL13);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL14_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL14);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL15_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL15);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL16_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL16);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL17_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL17);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL18_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL18);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL19_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL19);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL_ADD20_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL_ADD20);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL_ADD21_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL_ADD21);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL20_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL20);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL21_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL21);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL22_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL22);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL23_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL23);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL24_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL24);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL25_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL25);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL26_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL26);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL27_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL27);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL28_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL28);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL29_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL29);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL30_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL30);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL31_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL31);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL32_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL32);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL33_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL33);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL34_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL34);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL35_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL35);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL36_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL36);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL37_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL37);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL38_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL38);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL39_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL39);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL40_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL40);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL41_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL41);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL43_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL43);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL44_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL44);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL45_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL45);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL46_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL46);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL47_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL47);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL48_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL48);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL49_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL49);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL50_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL50);
	IoReg_Write32(KME_LOGO1__KM_LOGO_PXL51_ADDR , vpq_memc_suspend_resume.KME_LOGO1__KM_LOGO_PXL51);
	//KME_DM_TOP0
	IoReg_Write32(KME_DM_TOP0__KME_00_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP0__KME_00_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP0__KME_00_START_ADDRESS2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS2);
	IoReg_Write32(KME_DM_TOP0__KME_00_START_ADDRESS3_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS3);
	IoReg_Write32(KME_DM_TOP0__KME_00_START_ADDRESS4_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS4);
	IoReg_Write32(KME_DM_TOP0__KME_00_START_ADDRESS5_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_START_ADDRESS5);
	IoReg_Write32(KME_DM_TOP0__KME_00_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP0__KME_00_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP0__KME_00_END_ADDRESS2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS2);
	IoReg_Write32(KME_DM_TOP0__KME_00_END_ADDRESS3_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS3);
	IoReg_Write32(KME_DM_TOP0__KME_00_END_ADDRESS4_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS4);
	IoReg_Write32(KME_DM_TOP0__KME_00_END_ADDRESS5_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_END_ADDRESS5);
	IoReg_Write32(KME_DM_TOP0__KME_00_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP0__KME_00_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP0__KME_00_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_00_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_00_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_01_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_01_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_01_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_01_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_02_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_02_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_02_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_02_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_03_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_03_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_03_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_03_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_04_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP0__KME_04_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP0__KME_04_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP0__KME_04_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP0__KME_04_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP0__KME_04_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP0__KME_04_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_04_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_04_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_05_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP0__KME_05_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP0__KME_05_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP0__KME_05_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP0__KME_05_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP0__KME_05_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP0__KME_05_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_05_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_05_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_06_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_06_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_06_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_06_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_07_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_07_AGENT);
	IoReg_Write32(KME_DM_TOP0__KME_07_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_07_THRESHOLD);
	IoReg_Write32(KME_DM_TOP0__KME_ME_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_ME_RESOLUTION);
	IoReg_Write32(KME_DM_TOP0__KME_MV_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_MV_RESOLUTION);
	IoReg_Write32(KME_DM_TOP0__KME_SOURCE_MODE_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_SOURCE_MODE);
	IoReg_Write32(KME_DM_TOP0__KME_ME_HNUM_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_ME_HNUM);
	IoReg_Write32(KME_DM_TOP0__KME_TIMER_ENABLE_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_TIMER_ENABLE);
	IoReg_Write32(KME_DM_TOP0__KME_HOLD_TIME0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME0);
	IoReg_Write32(KME_DM_TOP0__KME_HOLD_TIME1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME1);
	IoReg_Write32(KME_DM_TOP0__KME_HOLD_TIME2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME2);
	IoReg_Write32(KME_DM_TOP0__KME_HOLD_TIME3_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__KME_HOLD_TIME3);
	IoReg_Write32(KME_DM_TOP0__WAIT_TIME0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__WAIT_TIME0);
	IoReg_Write32(KME_DM_TOP0__WAIT_TIME1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__WAIT_TIME1);
	IoReg_Write32(KME_DM_TOP0__WAIT_TIME2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__WAIT_TIME2);
	IoReg_Write32(KME_DM_TOP0__MV04_START_ADDRESS2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__MV04_START_ADDRESS2);
	IoReg_Write32(KME_DM_TOP0__MV04_END_ADDRESS2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP0__MV04_END_ADDRESS2);
	//KME_DM_TOP1
	IoReg_Write32(KME_DM_TOP1__KME_08_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_08_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_08_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_08_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_08_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP1__KME_08_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_08_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_08_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_09_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_09_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_09_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_09_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_10_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_10_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_10_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_10_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_10_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP1__KME_10_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_10_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_10_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_11_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_11_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_11_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_11_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_12_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_12_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_12_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_12_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_12_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP1__KME_12_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_12_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_12_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_13_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_13_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_13_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_13_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_14_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_14_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_14_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP1__KME_14_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP1__KME_14_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP1__KME_14_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_14_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_14_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_15_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_15_AGENT);
	IoReg_Write32(KME_DM_TOP1__KME_15_THRESHOLD_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_15_THRESHOLD);
	IoReg_Write32(KME_DM_TOP1__KME_IPLOGO_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_IPLOGO_RESOLUTION);
	IoReg_Write32(KME_DM_TOP1__KME_MLOGO_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_MLOGO_RESOLUTION);
	IoReg_Write32(KME_DM_TOP1__KME_PLOGO_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_PLOGO_RESOLUTION);
	IoReg_Write32(KME_DM_TOP1__KME_HLOGO_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_HLOGO_RESOLUTION);
	IoReg_Write32(KME_DM_TOP1__KME_LOGO_HNUM_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_LOGO_HNUM);
	IoReg_Write32(KME_DM_TOP1__KME_CLR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__KME_CLR);
	IoReg_Write32(KME_DM_TOP1__TH0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__TH0);
	IoReg_Write32(KME_DM_TOP1__TH1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__TH1);
	IoReg_Write32(KME_DM_TOP1__TH2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__TH2);
	IoReg_Write32(KME_DM_TOP1__TH3_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__TH3);
	IoReg_Write32(KME_DM_TOP1__TH4_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__TH4);
	IoReg_Write32(KME_DM_TOP1__METER_TIMER1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP1__METER_TIMER1);
	//KME_DM_TOP2
	IoReg_Write32(KME_DM_TOP2__MV01_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV01_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV01_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV01_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV_01_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_01_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV01_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV01_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV01_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV01_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV02_START_ADDRESS11_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV02_START_ADDRESS11);
	IoReg_Write32(KME_DM_TOP2__MV02_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV02_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV_02_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_02_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV02_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV02_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV02_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV02_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV03_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV03_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV04_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV04_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV04_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV04_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP2__MV04_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV04_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV04_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV04_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP2__MV_04_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_04_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV04_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV04_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV04_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV04_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV05_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV05_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV05_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV05_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP2__MV05_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV05_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV05_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV05_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP2__MV_05_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_05_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV05_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV05_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV05_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV05_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV06_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV06_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV07_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV07_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV08_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV08_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV09_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV09_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV10_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV10_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV11_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV11_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS1);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS2);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS3_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS3);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS4_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS4);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS5_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS5);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS0);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS1);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS2);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS3_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS3);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS4_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS4);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS5_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS5);
	IoReg_Write32(KME_DM_TOP2__MV_12_LINE_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_LINE_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV_12_LR_OFFSET_ADDR_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_LR_OFFSET_ADDR);
	IoReg_Write32(KME_DM_TOP2__MV12_AGENT_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV12_AGENT);
	IoReg_Write32(KME_DM_TOP2__MV_SOURCE_MODE_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_SOURCE_MODE);
	IoReg_Write32(KME_DM_TOP2__MV01_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV01_RESOLUTION);
	IoReg_Write32(KME_DM_TOP2__MV02_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV02_RESOLUTION);
	IoReg_Write32(KME_DM_TOP2__MV04_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV04_RESOLUTION);
	IoReg_Write32(KME_DM_TOP2__MV05_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV05_RESOLUTION);
	IoReg_Write32(KME_DM_TOP2__MV12_RESOLUTION_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV12_RESOLUTION);
	IoReg_Write32(KME_DM_TOP2__MV_TIME_ENABLE_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_TIME_ENABLE);
	IoReg_Write32(KME_DM_TOP2__MV_HOLD_TIME0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_HOLD_TIME0);
	IoReg_Write32(KME_DM_TOP2__MV_HOLD_TIME1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_HOLD_TIME1);
	IoReg_Write32(KME_DM_TOP2__MV_HOLD_TIME2_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_HOLD_TIME2);
	IoReg_Write32(KME_DM_TOP2__MV_WAIT_TIME0_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_WAIT_TIME0);
	IoReg_Write32(KME_DM_TOP2__MV_WAIT_TIME1_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_WAIT_TIME1);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS6_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS6);
	IoReg_Write32(KME_DM_TOP2__MV_12_START_ADDRESS7_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_START_ADDRESS7);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS6_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS6);
	IoReg_Write32(KME_DM_TOP2__MV_12_END_ADDRESS7_ADDR , vpq_memc_suspend_resume.KME_DM_TOP2__MV_12_END_ADDRESS7);
	//KME_ME1_TOP0
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_00);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_01);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_02);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_03);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_04);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_05);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_06);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_07);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_08);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_09);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_10);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_11);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_12_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_12);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_13_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_13);
	IoReg_Write32(KME_ME1_TOP0__ME1_IP_CONFIG_14_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_IP_CONFIG_14);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_00);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_01);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_02);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_03);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_04);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_05);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_06);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_07);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_08);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_09);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_10);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_11);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_12_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_12);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_13_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_13);
	IoReg_Write32(KME_ME1_TOP0__ME1_PI_CONFIG_14_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_PI_CONFIG_14);
	IoReg_Write32(KME_ME1_TOP0__ME1_COMMON_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_04);
	IoReg_Write32(KME_ME1_TOP0__ME1_COMMON_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_00);
	IoReg_Write32(KME_ME1_TOP0__ME1_COMMON_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_01);
	IoReg_Write32(KME_ME1_TOP0__ME1_COMMON_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_02);
	IoReg_Write32(KME_ME1_TOP0__ME1_COMMON_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_COMMON_03);
	IoReg_Write32(KME_ME1_TOP0__ME1_SC_REG00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG00);
	IoReg_Write32(KME_ME1_TOP0__ME1_SC_REG01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG01);
	IoReg_Write32(KME_ME1_TOP0__ME1_SC_REG02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG02);
	IoReg_Write32(KME_ME1_TOP0__ME1_SC_REG03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG03);
	IoReg_Write32(KME_ME1_TOP0__ME1_SC_REG04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG04);
	IoReg_Write32(KME_ME1_TOP0__ME1_SC_REG05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_SC_REG05);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG00);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG01);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG02);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG03);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG04);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG05);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG06);
	IoReg_Write32(KME_ME1_TOP0__ME1_MEANDER_REG07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP0__ME1_MEANDER_REG07);
	//KME_ME1_TOP1
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_00);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_01);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_02);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_03);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_04);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_05);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_06);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_07);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_08);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_09);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_10);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_11);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_12_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_12);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_13_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_13);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_14_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_14);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_15_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_15);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_16_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_16);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_17_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_17);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_18_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_18);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_19_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_19);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_20_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_20);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_21_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_21);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_22_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_22);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_23_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_23);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_24_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_24);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_25_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_25);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_26_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_26);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_27_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_27);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_28_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_28);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_29_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_29);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_30_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_30);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_31_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_31);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_32_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_32);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_33_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_33);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_34_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_34);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_35_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_35);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_36_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_36);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_37_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_37);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_38_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_38);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_39_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_39);
	IoReg_Write32(KME_ME1_TOP1__ME1_COMMON1_40_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_COMMON1_40);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_00);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_01);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_02);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_03);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_04);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_05);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_06);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_07);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_08);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_09_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_09);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_10_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_10);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_11_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_11);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_12_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_12);
	IoReg_Write32(KME_ME1_TOP1__ME1_SCENE1_13_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP1__ME1_SCENE1_13);
	//KME_ME2_LBME_TOP
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_X_POS_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_X_POS);
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_Y_POS_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_Y_POS);
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_DEBUG_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_DEBUG);
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_XY_OFFSET_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_XY_OFFSET);
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_DEBUG_XY_POS_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_DEBUG_XY_POS);
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_TOTAL_LINE_PIX_NUM);
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_LINE_LINEBUF_NUM_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_LINE_LINEBUF_NUM);
	IoReg_Write32(KME_ME2_LBME_TOP__LBME_ED_EN_ADDR , vpq_memc_suspend_resume.KME_ME2_LBME_TOP__LBME_ED_EN);
	//KME_ME2_VBUF_TOP
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG0_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG0);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG1_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG1);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG2_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG2);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG3_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG3);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG4_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG4);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG5_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG5);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG6_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG6);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG7_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG7);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG8_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG8);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG9_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG9);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG10_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG10);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG11_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG11);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG12_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG12);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG13_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG13);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG14_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG14);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG15_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG15);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG16_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG16);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG17_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG17);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG18_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG18);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG19_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG19);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG20_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG20);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG21_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG21);
	IoReg_Write32(KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG22_ADDR , vpq_memc_suspend_resume.KME_ME2_VBUF_TOP__ME2_VBUF_WR_REG22);
	//KME_ME2_TOP
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_00_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_00);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_01_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_01);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_02_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_02);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_03_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_03);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_04_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_04);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_05_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_05);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_06_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_06);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_07_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_07);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_08_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_08);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_09_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_09);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_10_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_10);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_11_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_11);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_12_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_12);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_13_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_13);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_14_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_14);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_15_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_15);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_16_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_16);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_17_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_17);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_18_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_18);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_19_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_19);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_20_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_20);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_21_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_21);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_22_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_22);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_23_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_23);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_24_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_24);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_25_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_25);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_26_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_26);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_27_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_27);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_28_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_28);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_34_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_34);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_35_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_35);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_36_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_36);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_37_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_37);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_38_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_38);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_39_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_39);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_40_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_40);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_41_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_41);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_42_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_42);
	IoReg_Write32(KME_ME2_TOP__ME2_CONFIG_43_ADDR , vpq_memc_suspend_resume.KME_ME2_TOP__ME2_CONFIG_43);
	//KME_ME1_TOP6
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_00_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_00);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_01_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_01);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_02_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_02);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_03_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_03);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_04_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_04);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_05_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_05);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_06_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_06);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_07_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_07);
	IoReg_Write32(KME_ME1_TOP6__ME1_STATIS_08_ADDR , vpq_memc_suspend_resume.KME_ME1_TOP6__ME1_STATIS_08);
	//KME_ME1_TOP7
	//KME_ME1_TOP8
	//KME_ME1_TOP9
	//KME_DEHALO
	IoReg_Write32(KME_DEHALO__KME_DH_CTRL_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_CTRL);
	IoReg_Write32(KME_DEHALO__KME_DH_LOGO0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_LOGO0);
	IoReg_Write32(KME_DEHALO__KME_DH_RIM0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RIM0);
	IoReg_Write32(KME_DEHALO__KME_DH_RIM1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RIM1);
	IoReg_Write32(KME_DEHALO__KME_DH_PHASE_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PHASE);
	IoReg_Write32(KME_DEHALO__KME_DH_RT1_0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_0);
	IoReg_Write32(KME_DEHALO__KME_DH_RT2_0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_0);
	IoReg_Write32(KME_DEHALO__KME_DH_RT1_1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_1);
	IoReg_Write32(KME_DEHALO__KME_DH_RT1_2_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_2);
	IoReg_Write32(KME_DEHALO__KME_DH_RT2_1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_1);
	IoReg_Write32(KME_DEHALO__KME_DH_RT2_2_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_2);
	IoReg_Write32(KME_DEHALO__KME_DH_CONF_GEN1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_CONF_GEN1);
	IoReg_Write32(KME_DEHALO__KME_DH_CONF_PROC2_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_CONF_PROC2);
	IoReg_Write32(KME_DEHALO__KME_DH_PFV_GEN1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PFV_GEN1);
	IoReg_Write32(KME_DEHALO__KME_DH_PFV_CHK1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PFV_CHK1);
	IoReg_Write32(KME_DEHALO__KME_DH_DEBUG_SEL_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_DEBUG_SEL);
	IoReg_Write32(KME_DEHALO__KME_DH_RT1_3_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_3);
	IoReg_Write32(KME_DEHALO__KME_DH_RT1_4_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT1_4);
	IoReg_Write32(KME_DEHALO__KME_DH_RT2_3_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_RT2_3);
	IoReg_Write32(KME_DEHALO__KME_DH_PHASE_OFT0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PHASE_OFT0);
	IoReg_Write32(KME_DEHALO__KME_DH_PHASE_OFT1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_PHASE_OFT1);
	IoReg_Write32(KME_DEHALO__KME_DH_VBUF_TIMING0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_VBUF_TIMING0);
	IoReg_Write32(KME_DEHALO__KME_DH_VBUF_TIMING1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_VBUF_TIMING1);
	IoReg_Write32(KME_DEHALO__KME_DH_VBUF_TIMING2_ADDR , vpq_memc_suspend_resume.KME_DEHALO__KME_DH_VBUF_TIMING2);
	IoReg_Write32(KME_DEHALO__DEHALO_SHOW_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DEHALO_SHOW);
	IoReg_Write32(KME_DEHALO__MV_PAT_ADDR , vpq_memc_suspend_resume.KME_DEHALO__MV_PAT);
	IoReg_Write32(KME_DEHALO__DH_DUMMY_CTRL2_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_DUMMY_CTRL2);
	IoReg_Write32(KME_DEHALO__MV_PAT_WINDOWH_ADDR , vpq_memc_suspend_resume.KME_DEHALO__MV_PAT_WINDOWH);
	IoReg_Write32(KME_DEHALO__MV_PAT_WINDOWV_ADDR , vpq_memc_suspend_resume.KME_DEHALO__MV_PAT_WINDOWV);
	IoReg_Write32(KME_DEHALO__DH_LOGO_HOR0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_HOR0);
	IoReg_Write32(KME_DEHALO__DH_LOGO_HOR1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_HOR1);
	IoReg_Write32(KME_DEHALO__DH_LOGO_VER0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_VER0);
	IoReg_Write32(KME_DEHALO__DH_LOGO_VER1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_VER1);
	IoReg_Write32(KME_DEHALO__DH_LOGO_MV_DIFF_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_MV_DIFF);
	IoReg_Write32(KME_DEHALO__DH_LOGO_SMV0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_SMV0);
	IoReg_Write32(KME_DEHALO__DH_LOGO_SMV1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_SMV1);
	IoReg_Write32(KME_DEHALO__DH_LOGO_CTRL_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_CTRL);
	IoReg_Write32(KME_DEHALO__DH_REGION0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_REGION0);
	IoReg_Write32(KME_DEHALO__DH_REGION1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_REGION1);
	IoReg_Write32(KME_DEHALO__DH_REGION2_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_REGION2);
	IoReg_Write32(KME_DEHALO__DH_LOGO_TMV_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_LOGO_TMV);
	IoReg_Write32(KME_DEHALO__DH_CORNER0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_CORNER0);
	IoReg_Write32(KME_DEHALO__DH_CORNER1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_CORNER1);
	IoReg_Write32(KME_DEHALO__DH_CORNER2_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_CORNER2);
	IoReg_Write32(KME_DEHALO__DH_PHASE_GAIN0_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_PHASE_GAIN0);
	IoReg_Write32(KME_DEHALO__DH_PHASE_GAIN1_ADDR , vpq_memc_suspend_resume.KME_DEHALO__DH_PHASE_GAIN1);
	//KME_DEHALO2
	IoReg_Write32(KME_DEHALO2__DH_DEBUG_PATH_SETTING_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__DH_DEBUG_PATH_SETTING);
	IoReg_Write32(KME_DEHALO2__DH_RT2_H_V_IDX_OFFSET_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__DH_RT2_H_V_IDX_OFFSET);
	IoReg_Write32(KME_DEHALO2__DH_CHECK_MODE0_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__DH_CHECK_MODE0);
	IoReg_Write32(KME_DEHALO2__DH_DEBUG_KKK_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__DH_DEBUG_KKK);
	IoReg_Write32(KME_DEHALO2__DH_PATT_EN_CTRL_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__DH_PATT_EN_CTRL);
	IoReg_Write32(KME_DEHALO2__RT1_RIM0_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__RT1_RIM0);
	IoReg_Write32(KME_DEHALO2__RT1_RIM1_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__RT1_RIM1);
	IoReg_Write32(KME_DEHALO2__RT2_RIM0_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__RT2_RIM0);
	IoReg_Write32(KME_DEHALO2__RT2_RIM1_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__RT2_RIM1);
	IoReg_Write32(KME_DEHALO2__DH_PR_MODE_CTRL_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__DH_PR_MODE_CTRL);
	IoReg_Write32(KME_DEHALO2__DH_DUMMY_GEN_CTRL_ADDR , vpq_memc_suspend_resume.KME_DEHALO2__DH_DUMMY_GEN_CTRL);
	//KPOST_TOP
	IoReg_Write32(KPOST_TOP__POST_CURSOR_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_CURSOR);
	IoReg_Write32(KPOST_TOP__POST_BS_OUT_INT_CTRL_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_BS_OUT_INT_CTRL);
	IoReg_Write32(KPOST_TOP__POST_INT_CTRL_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_INT_CTRL);
	IoReg_Write32(KPOST_TOP__BLACK_INSERT_ADDR , vpq_memc_suspend_resume.KPOST_TOP__BLACK_INSERT);
	IoReg_Write32(KPOST_TOP__POST_PATT_TOTAL_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_TOTAL);
	IoReg_Write32(KPOST_TOP__POST_PATT_ACT_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_ACT);
	IoReg_Write32(KPOST_TOP__POST_PATT_WIDTH_BPORCH_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_WIDTH_BPORCH);
	IoReg_Write32(KPOST_TOP__POST_PATT_CTRL_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_CTRL);
	IoReg_Write32(KPOST_TOP__POST_PATT_RGB0_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_RGB0);
	IoReg_Write32(KPOST_TOP__POST_PATT_RGB1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_PATT_RGB1);
	IoReg_Write32(KPOST_TOP__LINE2_TO_4PORT_ADDR , vpq_memc_suspend_resume.KPOST_TOP__LINE2_TO_4PORT);
	IoReg_Write32(KPOST_TOP__POST_PSC_CTRL_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_PSC_CTRL);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_Y_0_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_0);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_Y_1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_1);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_Y_2_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_2);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_Y_3_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_Y_3);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_C_0_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_0);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_C_1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_1);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_C_2_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_2);
	IoReg_Write32(KPOST_TOP__POST_HSC_COEF_C_3_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_HSC_COEF_C_3);
	IoReg_Write32(KPOST_TOP__POST_BLUE_SCREEN_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_BLUE_SCREEN);
	IoReg_Write32(KPOST_TOP__POST_DRF_BIST_IN_1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_DRF_BIST_IN_1);
	IoReg_Write32(KPOST_TOP__POST_DRF_BIST_IN_2_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_DRF_BIST_IN_2);
	IoReg_Write32(KPOST_TOP__POST_DRF_BIST_IN_3_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_DRF_BIST_IN_3);
	IoReg_Write32(KPOST_TOP__POST_CSC_COEF0_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF0);
	IoReg_Write32(KPOST_TOP__POST_CSC_COEF1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF1);
	IoReg_Write32(KPOST_TOP__POST_CSC_COEF2_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF2);
	IoReg_Write32(KPOST_TOP__POST_CSC_COEF3_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF3);
	IoReg_Write32(KPOST_TOP__POST_CSC_COEF4_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF4);
	IoReg_Write32(KPOST_TOP__POST_CSC_COEF5_ADDR , vpq_memc_suspend_resume.KPOST_TOP__POST_CSC_COEF5);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_DATA_G0G1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_G0G1);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_DATA_G2G3_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_G2G3);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G0G1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G0G1);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_PLACE_G0_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G0);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_PLACE_G1_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G1);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_PLACE_G2_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G2);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_PLACE_G3_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_PLACE_G3);
	IoReg_Write32(KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G2G3_ADDR , vpq_memc_suspend_resume.KPOST_TOP__SEG_DIPLAY_DATA_COLOR_G2G3);
	//CRTC1
	IoReg_Write32(CRTC1__CRTC1_OUT_TOTAL_HSWIDTH_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_TOTAL_HSWIDTH);
	IoReg_Write32(CRTC1__CRTC1_OUT_ACT_VSWIDTH_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_ACT_VSWIDTH);
	IoReg_Write32(CRTC1__CRTC1_OUT_SYNC_BPORCH_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_SYNC_BPORCH);
	IoReg_Write32(CRTC1__CRTC1_OSD_ACT_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_OSD_ACT);
	IoReg_Write32(CRTC1__CRTC1_OSD_SYNC_BPORCH_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_OSD_SYNC_BPORCH);
	IoReg_Write32(CRTC1__CRTC1_FRC_ACT_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_FRC_ACT);
	IoReg_Write32(CRTC1__CRTC1_FRC_SYNC_BPORCH_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_FRC_SYNC_BPORCH);
	IoReg_Write32(CRTC1__CRTC1_IP_ME_VTRIG_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_IP_ME_VTRIG);
	IoReg_Write32(CRTC1__CRTC1_OUT_OSD_FRC_VTRIG_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_OUT_OSD_FRC_VTRIG);
	IoReg_Write32(CRTC1__CRTC1_ME_DEC_VTRIG_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_ME_DEC_VTRIG);
	IoReg_Write32(CRTC1__CRTC1_DEHALO_MC_VTRIG_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_DEHALO_MC_VTRIG);
	IoReg_Write32(CRTC1__CRTC1_LBMC_INDEX_A_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_INDEX_A);
	IoReg_Write32(CRTC1__CRTC1_LBMC_INDEX_B_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_INDEX_B);
	IoReg_Write32(CRTC1__CRTC1_LBMC_INDEX_C_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_INDEX_C);
	IoReg_Write32(CRTC1__CRTC1_INDEX_HDLY_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_INDEX_HDLY);
	IoReg_Write32(CRTC1__CRTC1_HDLY_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_HDLY);
	IoReg_Write32(CRTC1__CRTC1_VRANGE0_ROW_TYPE_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_VRANGE0_ROW_TYPE);
	IoReg_Write32(CRTC1__CRTC1_VRANGE1_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_VRANGE1);
	IoReg_Write32(CRTC1__CRTC1_LOGO_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LOGO);
	IoReg_Write32(CRTC1__CRTC1_VSPLL_SETTING_A_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_SETTING_A);
	IoReg_Write32(CRTC1__CRTC1_VSPLL_V_MAX_MIN_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_V_MAX_MIN);
	IoReg_Write32(CRTC1__CRTC1_VSPLL_V_OFFSET_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_V_OFFSET);
	IoReg_Write32(CRTC1__CRTC1_VSPLL_SETTING_B_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_SETTING_B);
	IoReg_Write32(CRTC1__CRTC1_VSPLL_SETTING_C_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_VSPLL_SETTING_C);
	IoReg_Write32(CRTC1__CRTC1_LBMC_SEP_INDEX_A_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_A);
	IoReg_Write32(CRTC1__CRTC1_LBMC_SEP_INDEX_B_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_B);
	IoReg_Write32(CRTC1__CRTC1_LBMC_SEP_INDEX_C_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_C);
	IoReg_Write32(CRTC1__CRTC1_LBMC_SEP_INDEX_D_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LBMC_SEP_INDEX_D);
	IoReg_Write32(CRTC1__CRTC1_ME_ROW_TRG_OFST_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_ME_ROW_TRG_OFST);
	IoReg_Write32(CRTC1__CRTC1_ME1_TIMING0_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_ME1_TIMING0);
	IoReg_Write32(CRTC1__CRTC1_ME1_TIMING1_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_ME1_TIMING1);
	IoReg_Write32(CRTC1__CRTC1_LR_CONTROL_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_LR_CONTROL);
	IoReg_Write32(CRTC1__CRTC1_DEHALO_FLT_TRIG_ADDR , vpq_memc_suspend_resume.CRTC1__CRTC1_DEHALO_FLT_TRIG);
	//KPhase
	IoReg_Write32(KPHASE__KPHASE_FORCE_G0_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_FORCE_G0);
	IoReg_Write32(KPHASE__KPHASE_FORCE_G1_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_FORCE_G1);
	IoReg_Write32(KPHASE__KPHASE_MEMC_INDEX_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_MEMC_INDEX);
	IoReg_Write32(KPHASE__KPHASE_FILM_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_FILM);
	IoReg_Write32(KPHASE__KPHASE_IN_DEC_INDEX_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_DEC_INDEX);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G0_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G0);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G1_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G1);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G2_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G2);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G3_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G3);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G4_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G4);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G5_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G5);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G6_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G6);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G7_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G7);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G8_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G8);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G9_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G9);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G10_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G10);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G11_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G11);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G12_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G12);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G13_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G13);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G14_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G14);
	IoReg_Write32(KPHASE__KPHASE_IN_PHASE_G15_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_IN_PHASE_G15);
	IoReg_Write32(KPHASE__KPHASE_DEC_MATCHPERIOD_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_DEC_MATCHPERIOD);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED0_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED0);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED1_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED1);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED2_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED2);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED3_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED3);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED4_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED4);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED5_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED5);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED6_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED6);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED7_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED7);
	IoReg_Write32(KPHASE__KPHASE_ME2_FILED8_ADDR , vpq_memc_suspend_resume.KPHASE__KPHASE_ME2_FILED8);
	//Hardware
	IoReg_Write32(HARDWARE__HARDWARE_00_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_00);
	IoReg_Write32(HARDWARE__HARDWARE_01_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_01);
	IoReg_Write32(HARDWARE__HARDWARE_02_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_02);
	IoReg_Write32(HARDWARE__HARDWARE_03_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_03);
	IoReg_Write32(HARDWARE__HARDWARE_04_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_04);
	IoReg_Write32(HARDWARE__HARDWARE_05_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_05);
	IoReg_Write32(HARDWARE__HARDWARE_06_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_06);
	IoReg_Write32(HARDWARE__HARDWARE_07_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_07);
	IoReg_Write32(HARDWARE__HARDWARE_08_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_08);
	IoReg_Write32(HARDWARE__HARDWARE_09_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_09);
	IoReg_Write32(HARDWARE__HARDWARE_10_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_10);
	IoReg_Write32(HARDWARE__HARDWARE_11_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_11);
	IoReg_Write32(HARDWARE__HARDWARE_12_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_12);
	IoReg_Write32(HARDWARE__HARDWARE_13_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_13);
	IoReg_Write32(HARDWARE__HARDWARE_14_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_14);
	IoReg_Write32(HARDWARE__HARDWARE_15_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_15);
	IoReg_Write32(HARDWARE__HARDWARE_16_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_16);
	IoReg_Write32(HARDWARE__HARDWARE_17_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_17);
	IoReg_Write32(HARDWARE__HARDWARE_18_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_18);
	IoReg_Write32(HARDWARE__HARDWARE_19_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_19);
	IoReg_Write32(HARDWARE__HARDWARE_20_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_20);
	IoReg_Write32(HARDWARE__HARDWARE_21_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_21);
	IoReg_Write32(HARDWARE__HARDWARE_22_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_22);
	IoReg_Write32(HARDWARE__HARDWARE_23_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_23);
	IoReg_Write32(HARDWARE__HARDWARE_24_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_24);
	IoReg_Write32(HARDWARE__HARDWARE_25_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_25);
	IoReg_Write32(HARDWARE__HARDWARE_26_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_26);
	IoReg_Write32(HARDWARE__HARDWARE_27_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_27);
	IoReg_Write32(HARDWARE__HARDWARE_28_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_28);
	IoReg_Write32(HARDWARE__HARDWARE_29_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_29);
	IoReg_Write32(HARDWARE__HARDWARE_30_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_30);
	IoReg_Write32(HARDWARE__HARDWARE_31_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_31);
	IoReg_Write32(HARDWARE__HARDWARE_32_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_32);
	IoReg_Write32(HARDWARE__HARDWARE_33_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_33);
	IoReg_Write32(HARDWARE__HARDWARE_34_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_34);
	IoReg_Write32(HARDWARE__HARDWARE_35_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_35);
	IoReg_Write32(HARDWARE__HARDWARE_36_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_36);
	IoReg_Write32(HARDWARE__HARDWARE_37_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_37);
	IoReg_Write32(HARDWARE__HARDWARE_38_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_38);
	IoReg_Write32(HARDWARE__HARDWARE_39_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_39);
	IoReg_Write32(HARDWARE__HARDWARE_40_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_40);
	IoReg_Write32(HARDWARE__HARDWARE_41_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_41);
	IoReg_Write32(HARDWARE__HARDWARE_42_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_42);
	IoReg_Write32(HARDWARE__HARDWARE_43_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_43);
	IoReg_Write32(HARDWARE__HARDWARE_44_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_44);
	IoReg_Write32(HARDWARE__HARDWARE_45_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_45);
	IoReg_Write32(HARDWARE__HARDWARE_46_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_46);
	IoReg_Write32(HARDWARE__HARDWARE_47_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_47);
	IoReg_Write32(HARDWARE__HARDWARE_48_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_48);
	IoReg_Write32(HARDWARE__HARDWARE_49_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_49);
	IoReg_Write32(HARDWARE__HARDWARE_50_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_50);
	IoReg_Write32(HARDWARE__HARDWARE_51_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_51);
	IoReg_Write32(HARDWARE__HARDWARE_52_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_52);
	IoReg_Write32(HARDWARE__HARDWARE_53_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_53);
	IoReg_Write32(HARDWARE__HARDWARE_54_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_54);
	IoReg_Write32(HARDWARE__HARDWARE_55_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_55);
	IoReg_Write32(HARDWARE__HARDWARE_56_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_56);
	IoReg_Write32(HARDWARE__HARDWARE_57_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_57);
	IoReg_Write32(HARDWARE__HARDWARE_58_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_58);
	IoReg_Write32(HARDWARE__HARDWARE_59_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_59);
	IoReg_Write32(HARDWARE__HARDWARE_60_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_60);
	IoReg_Write32(HARDWARE__HARDWARE_61_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_61);
	IoReg_Write32(HARDWARE__HARDWARE_62_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_62);
	IoReg_Write32(HARDWARE__HARDWARE_63_ADDR , vpq_memc_suspend_resume.HARDWARE__HARDWARE_63);
	//Software
	IoReg_Write32(SOFTWARE__SOFTWARE_00_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_00);
	IoReg_Write32(SOFTWARE__SOFTWARE_01_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_01);
	IoReg_Write32(SOFTWARE__SOFTWARE_02_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_02);
	IoReg_Write32(SOFTWARE__SOFTWARE_03_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_03);
	IoReg_Write32(SOFTWARE__SOFTWARE_04_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_04);
	IoReg_Write32(SOFTWARE__SOFTWARE_05_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_05);
	IoReg_Write32(SOFTWARE__SOFTWARE_06_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_06);
	IoReg_Write32(SOFTWARE__SOFTWARE_07_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_07);
	IoReg_Write32(SOFTWARE__SOFTWARE_08_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_08);
	IoReg_Write32(SOFTWARE__SOFTWARE_09_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_09);
	IoReg_Write32(SOFTWARE__SOFTWARE_10_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_10);
	IoReg_Write32(SOFTWARE__SOFTWARE_11_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_11);
	IoReg_Write32(SOFTWARE__SOFTWARE_12_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_12);
	IoReg_Write32(SOFTWARE__SOFTWARE_13_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_13);
	IoReg_Write32(SOFTWARE__SOFTWARE_14_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_14);
	IoReg_Write32(SOFTWARE__SOFTWARE_15_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_15);
	IoReg_Write32(SOFTWARE__SOFTWARE_16_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_16);
	IoReg_Write32(SOFTWARE__SOFTWARE_17_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_17);
	IoReg_Write32(SOFTWARE__SOFTWARE_18_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_18);
	IoReg_Write32(SOFTWARE__SOFTWARE_19_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_19);
	IoReg_Write32(SOFTWARE__SOFTWARE_20_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_20);
	IoReg_Write32(SOFTWARE__SOFTWARE_21_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_21);
	IoReg_Write32(SOFTWARE__SOFTWARE_22_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_22);
	IoReg_Write32(SOFTWARE__SOFTWARE_23_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_23);
	IoReg_Write32(SOFTWARE__SOFTWARE_24_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_24);
	IoReg_Write32(SOFTWARE__SOFTWARE_25_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_25);
	IoReg_Write32(SOFTWARE__SOFTWARE_26_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_26);
	IoReg_Write32(SOFTWARE__SOFTWARE_27_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_27);
	IoReg_Write32(SOFTWARE__SOFTWARE_28_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_28);
	IoReg_Write32(SOFTWARE__SOFTWARE_29_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_29);
	IoReg_Write32(SOFTWARE__SOFTWARE_30_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_30);
	IoReg_Write32(SOFTWARE__SOFTWARE_31_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_31);
	IoReg_Write32(SOFTWARE__SOFTWARE_32_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_32);
	IoReg_Write32(SOFTWARE__SOFTWARE_33_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_33);
	IoReg_Write32(SOFTWARE__SOFTWARE_34_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_34);
	IoReg_Write32(SOFTWARE__SOFTWARE_35_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_35);
	IoReg_Write32(SOFTWARE__SOFTWARE_36_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_36);
	IoReg_Write32(SOFTWARE__SOFTWARE_37_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_37);
	IoReg_Write32(SOFTWARE__SOFTWARE_38_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_38);
	IoReg_Write32(SOFTWARE__SOFTWARE_39_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_39);
	IoReg_Write32(SOFTWARE__SOFTWARE_40_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_40);
	IoReg_Write32(SOFTWARE__SOFTWARE_41_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_41);
	IoReg_Write32(SOFTWARE__SOFTWARE_42_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_42);
	IoReg_Write32(SOFTWARE__SOFTWARE_43_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_43);
	IoReg_Write32(SOFTWARE__SOFTWARE_44_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_44);
	IoReg_Write32(SOFTWARE__SOFTWARE_45_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_45);
	IoReg_Write32(SOFTWARE__SOFTWARE_46_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_46);
	IoReg_Write32(SOFTWARE__SOFTWARE_47_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_47);
	IoReg_Write32(SOFTWARE__SOFTWARE_48_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_48);
	IoReg_Write32(SOFTWARE__SOFTWARE_49_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_49);
	IoReg_Write32(SOFTWARE__SOFTWARE_50_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_50);
	IoReg_Write32(SOFTWARE__SOFTWARE_51_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_51);
	IoReg_Write32(SOFTWARE__SOFTWARE_52_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_52);
	IoReg_Write32(SOFTWARE__SOFTWARE_53_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_53);
	IoReg_Write32(SOFTWARE__SOFTWARE_54_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_54);
	IoReg_Write32(SOFTWARE__SOFTWARE_55_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_55);
	IoReg_Write32(SOFTWARE__SOFTWARE_56_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_56);
	IoReg_Write32(SOFTWARE__SOFTWARE_57_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_57);
	IoReg_Write32(SOFTWARE__SOFTWARE_58_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_58);
	IoReg_Write32(SOFTWARE__SOFTWARE_59_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_59);
	IoReg_Write32(SOFTWARE__SOFTWARE_60_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_60);
	IoReg_Write32(SOFTWARE__SOFTWARE_61_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_61);
	IoReg_Write32(SOFTWARE__SOFTWARE_62_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_62);
	IoReg_Write32(SOFTWARE__SOFTWARE_63_ADDR , vpq_memc_suspend_resume.SOFTWARE__SOFTWARE_63);

#if 0
	//MEMC mux
	IoReg_Write32(MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg, vpq_memc_suspend_resume.MEMC_MUX_MEMC_MUX_FUNC_CTRL_SUSPEND);
	//FBG
	vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND = vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND | 0x00001000;
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, vpq_memc_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_SUSPEND);
	//clock
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, vpq_memc_suspend_resume.SYS_REG_SYS_DISPCLKSEL_SUSPEND);
	IoReg_Write32(MEMC_LATENCY01_ADDR, vpq_memc_suspend_resume.MEMC_LATENCY01);
	IoReg_Write32(MEMC_LATENCY02_ADDR, vpq_memc_suspend_resume.MEMC_LATENCY02);

	//ME memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Me_downlimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_DOWNLIMIT);
	IoReg_Write32(MEMC_DBUS_WRAP_Me_uplimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_ME_UPLIMIT);
	//MC memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_downlimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_DOWNLIMIT);
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg, vpq_memc_suspend_resume.MEMC_DBUS_WRAP_MC_UPLIMIT);
#else

	//MEMC resume setting
	Scaler_MEMC_Mux();
	Scaler_MEMC_CLK();
	//Scaler_MEMC_output_force_bg_enable(TRUE);
	//disable double buffer
	{
		ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl_reg;
		double_buffer_ctrl_reg.regValue =  IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
		double_buffer_ctrl_reg.uzudtgreg_dbuf_en = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl_reg.regValue);

		//enable MEMC output fbg
		ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
		memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
		memc_mux_ctrl_reg.memc_out_bg_en = TRUE;
		IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
	}

#ifdef CONFIG_HW_SUPPORT_MEMC
	//ME memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Me_downlimit_addr_reg, gphy_addr_kme);
	IoReg_Write32(MEMC_DBUS_WRAP_Me_uplimit_addr_reg, (gphy_addr_kme + KME_TOTAL_SIZE));
	//MC memory boundary
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_downlimit_addr_reg, gphy_addr_kmc00);
	IoReg_Write32(MEMC_DBUS_WRAP_Mc_uplimit_addr_reg, (gphy_addr_kmc00 + KMC_TOTAL_SIZE));
#endif
#endif
	MEMC_instanboot_resume_Done = 1;

	// enable interrupt
	UINT32 u32_interrupt_reg = 0;
	//reg_kmc_int_en
	u32_interrupt_reg = IoReg_Read32(KMC_TOP__KMC_IN_INT_CTRL_ADDR);
	u32_interrupt_reg |= 0x02000000;
	IoReg_Write32(KMC_TOP__KMC_IN_INT_CTRL_ADDR, u32_interrupt_reg);

	//reg_post_int_en
	u32_interrupt_reg = IoReg_Read32(KPOST_TOP__POST_INT_CTRL_ADDR);
	u32_interrupt_reg |= 0x00000040;
	IoReg_Write32(KPOST_TOP__POST_INT_CTRL_ADDR, u32_interrupt_reg);

	pr_notice("[MEMC]Instanboot Resume done !!!\n");
#if 0
	time_check1= time_e- time_s;
	time_e = rtd_inl(0xB801B6A8);
	printk(KERN_EMERG "Time = %d",time_check1);
#endif


	#endif
}
#endif

unsigned char memc_ioctl_cmd_stop[32] = {0};
unsigned char vpq_memc_ioctl_get_stop_run(unsigned int cmd)
{
	return (memc_ioctl_cmd_stop[_IOC_NR(cmd)&0x1f]|memc_ioctl_cmd_stop[0]);
}

unsigned char vpq_memc_ioctl_get_stop_run_by_idx(unsigned char cmd_idx)
{
	return memc_ioctl_cmd_stop[cmd_idx];
}

void vpq_memc_ioctl_set_stop_run_by_idx(unsigned char cmd_idx, unsigned char stop)
{
	memc_ioctl_cmd_stop[cmd_idx] = stop;
}

int vpq_memc_open(struct inode *inode, struct file *filp)
{
	return 0;
}

ssize_t  vpq_memc_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

ssize_t vpq_memc_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

int vpq_memc_release(struct inode *inode, struct file *filep)
{
	return 0;
}

long vpq_memc_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{

	#ifdef CONFIG_HW_SUPPORT_MEMC

	int retval = 0;
	VPQ_MEMC_SETVIDEOBLOCK_T set_video_block_info;
	//rtd_printk(KERN_DEBUG, TAG_NAME, "VPQ MEMC: vpq_memc_ioctl, %x;;agr:%x\n", cmd,*((unsigned int *)arg));
	if (_IOC_TYPE(cmd) != VPQ_IOC_MEMC_MAGIC || _IOC_NR(cmd) > VPQ_MEMC_IOC_MAXNR) return -ENOTTY ;

	if (vpq_memc_ioctl_get_stop_run(cmd))
		return 0;

	switch (cmd)
	{
		case VPQ_IOC_MEMC_INITILIZE:
		{
			rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_INITILIZE\n");
			HAL_VPQ_MEMC_Initialize();

			break;
		}
		case VPQ_IOC_MEMC_UNINITILIZE:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_UNINITILIZE\n");
			HAL_VPQ_MEMC_Uninitialize();

			break;
		}
		case VPQ_IOC_MEMC_SETMOTIONCOMP:
		{
			//printk(KERN_EMERG "##############[MEMC]VPQ_IOC_MEMC_SETMOTIONCOMP\n");
			VPQ_MEMC_SETMOTIONCOMP_T set_motion_comp_info;
			if(copy_from_user((void *)&set_motion_comp_info, (const void __user *)arg, sizeof(VPQ_MEMC_SETMOTIONCOMP_T)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETMOTIONCOMP failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				retval = HAL_VPQ_MEMC_SetMotionComp(set_motion_comp_info.blurLevel, set_motion_comp_info.judderLevel, set_motion_comp_info.motion);
			}

			break;
		}
/*
		case VPQ_IOC_MEMC_SETBLURLEVEL:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_SETBLURLEVEL\n");
			UINT8 blurLevel;
			if(copy_from_user((void *)&blurLevel, (const void __user *)arg, sizeof(UINT8)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETBLURLEVEL failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_SetBlurLevel(blurLevel);
			}

			break;
		}
		case VPQ_IOC_MEMC_SETJUDDERLEVEL:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_SETJUDDERLEVEL\n");
			UINT8 judderLevel;
			if(copy_from_user((void *)&judderLevel, (const void __user *)arg, sizeof(UINT8)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETJUDDERLEVEL failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_SetJudderLevel(judderLevel);
			}

			break;
		}
*/
		case VPQ_IOC_MEMC_MOTIONCOMPONOFF:
		{
			//printk(KERN_EMERG "##############[MEMC]VPQ_IOC_MEMC_MOTIONCOMPONOFF\n");
			BOOLEAN bOnOff;
			if(copy_from_user((void *)&bOnOff, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_MOTIONCOMPONOFF failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				retval = HAL_VPQ_MEMC_MotionCompOnOff(bOnOff);
			}

			break;
		}
		case VPQ_IOC_MEMC_LOWDELAYMODE:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_LOWDELAYMODE\n");
			UINT8 type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(UINT8)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_LOWDELAYMODE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{

				retval = HAL_VPQ_MEMC_LowDelayMode(type);
			}

			break;
		}
		case VPQ_IOC_MEMC_SETRGBYUVMode:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_SETRGBYUVMode\n");
			UINT8 mode;
			if(copy_from_user((void *)&mode, (const void __user *)arg, sizeof(mode)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETRGBYUVMode failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				retval = HAL_VPQ_MEMC_SetRGBYUVMode(mode);
			}

			break;
		}

		case VPQ_IOC_MEMC_GETFRAMEDELAY:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_GETFRAMEDELAY\n");
			UINT16 *pFrameDelay;
			if(copy_from_user((void *)&pFrameDelay, (const void __user *)arg, sizeof(UINT16)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_GETFRAMEDELAY failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_GetFrameDelay(pFrameDelay);
			}

			break;
		}

		case VPQ_IOC_MEMC_SETVIDEOBLOCK:
		{
			rtd_printk(KERN_DEBUG, TAG_NAME, "\r\n###[MEMC]VPQ_IOC_MEMC_SETVIDEOBLOCK####\r\n");

			if(copy_from_user((void *)&set_video_block_info, (const void __user *)arg, sizeof(VPQ_MEMC_SETVIDEOBLOCK_T)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETVIDEOBLOCK failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_SetVideoBlock(set_video_block_info.type, set_video_block_info.bOnOff);
			}

			break;
		}
/*
		case VPQ_IOC_MEMC_SETTRUEMOTIONDEMO:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_SETTRUEMOTIONDEMO\n");
			BOOLEAN bOnOff;
			if(copy_from_user((void *)&bOnOff, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETTRUEMOTIONDEMO failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_SetTrueMotionDemo(bOnOff);
			}

			break;
		}

		case VPQ_IOC_MEMC_GETFIRMWAREVERSION:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_GETFIRMWAREVERSION\n");
			UINT16 *pVersion;
			if(copy_from_user((void *)&pVersion, (const void __user *)arg, sizeof(UINT16)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETBLURLEVEL failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_GetFirmwareVersion(pVersion);
			}

			break;
		}
*/
		case VPQ_IOC_MEMC_SETBYPASSREGION:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_SETBYPASSREGION\n");
			VPQ_MEMC_SETBYPASSREGION_T set_bypass_region_info;
			if(copy_from_user((void *)&set_bypass_region_info, (const void __user *)arg, sizeof(VPQ_MEMC_SETBYPASSREGION_T)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETBYPASSREGION failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_SetBypassRegion(set_bypass_region_info.bOnOff, set_bypass_region_info.region, set_bypass_region_info.x, set_bypass_region_info.y, set_bypass_region_info.w, set_bypass_region_info.h);
			}

			break;
		}
/*
		case VPQ_IOC_MEMC_SETREVERSECONTROL:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_SETREVERSECONTROL\n");
			UINT8 u8Mode;
			if(copy_from_user((void *)&u8Mode, (const void __user *)arg, sizeof(UINT8)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETREVERSECONTROL failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_SetReverseControl(u8Mode);
			}

			break;
		}

		case VPQ_IOC_MEMC_FREEZE:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_FREEZE\n");
			UINT8 type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(UINT8)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_FREEZE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_Freeze(type);
			}

			break;
		}

		case VPQ_IOC_MEMC_SETDEMOBAR:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_SETDEMOBAR\n");
			VPQ_MEMC_SETDEMOBAR_T set_demo_bar_info;
			if(copy_from_user((void *)&set_demo_bar_info, (const void __user *)arg, sizeof(VPQ_MEMC_SETDEMOBAR_T)))
			{
				retval = -EFAULT;
				MEMC_DBG_PRINT("scaler vpq memc ioctl code=VPQ_IOC_MEMC_SETDEMOBAR failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VPQ_MEMC_SetDemoBar(set_demo_bar_info.bOnOff, set_demo_bar_info.r, set_demo_bar_info.g, set_demo_bar_info.b);
			}

			break;
		}

		case VPQ_IOC_MEMC_DEBUG:
		{
			//rtd_printk(KERN_DEBUG, TAG_NAME, "##############[MEMC]VPQ_IOC_MEMC_DEBUG\n");
			HAL_VPQ_MEMC_DEBUG();

			break;
		}
*/
		default:
			rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler vpq memc: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
			break ;
		}

	return retval;
	#endif
}
//#endif

struct file_operations vpq_memc_fops= {
	.owner =    THIS_MODULE,
	.open  =    vpq_memc_open,
	.release =  vpq_memc_release,
	.read  =    vpq_memc_read,
	.write = 	vpq_memc_write,
	.unlocked_ioctl =    vpq_memc_ioctl,
};

#ifdef CONFIG_PM
static const struct dev_pm_ops vpq_memc_pm_ops =
{
	.suspend    = vpq_memc_suspend,
	.resume     = vpq_memc_resume,
};
#endif // CONFIG_PM


static struct platform_device *vpq_memc_platform_devs;

static struct platform_driver vpq_memc_device_driver = {
	.driver =
	{
        .name         = VPQ_MEMC_DEVICE_NAME,
        .bus          = &platform_bus_type,
#ifdef CONFIG_PM
	 .pm         = &vpq_memc_pm_ops,
#endif

	},
};

static char *vpq_memc_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

#ifdef CONFIG_HW_SUPPORT_MEMC
static void memc_isr_disable (void)
{
    // disable interrupt
    UINT32 u32_interrupt_reg = 0;
    //reg_kmc_int_en
    u32_interrupt_reg = IoReg_Read32(0xB8099018); //MC_TOP__REG_KMC_IN_INT_SEL_ADDR
    u32_interrupt_reg &= 0xf0ffffff;
    IoReg_Write32(0xB8099018, u32_interrupt_reg);

    //reg_post_int_en
    u32_interrupt_reg = IoReg_Read32(0xB809D008); //KPOST_TOP__REG_POST_INT_SOURCE_SEL_ADDR
    u32_interrupt_reg &= 0xfffffe1f;
    IoReg_Write32(0xB809D008, u32_interrupt_reg);
}
#endif
static int memc_pm_event (struct notifier_block *this, unsigned long event, void *ptr)
{
        switch (event) {
    case PM_SUSPEND_PREPARE:
        printk("%s %d\n",__func__,__LINE__);
	#ifdef CONFIG_HW_SUPPORT_MEMC
        memc_isr_disable();
	#endif
        break;
        default:
                break;
        }

    return NOTIFY_DONE;
}

static struct notifier_block memc_notifier = {
  .notifier_call = memc_pm_event,
};


int vpq_memc_module_init(void)
{
	int result;
	int vpq_memc_devno;
	dev_t devno = 0;//vbe device number
	//PANEL_CONFIG_PARAMETER *panel_parameter = NULL;

	result = alloc_chrdev_region(&devno, vpq_memc_minor, vpq_memc_nr_devs,VPQ_MEMC_DEVICE_NAME);
	vpq_memc_major = MAJOR(devno);
	if (result < 0) {
		rtd_printk(KERN_WARNING, TAG_NAME, "VPQ_MEMC_DEVICE: can't get major %d\n", vpq_memc_major);
		return result;
	}

	rtd_printk(KERN_DEBUG, TAG_NAME, "VPQ_MEMC_DEVICE init module major number = %d\n", vpq_memc_major);
	vpq_memc_devno = MKDEV(vpq_memc_major, vpq_memc_minor);

	vpq_memc_class = class_create(THIS_MODULE, VPQ_MEMC_DEVICE_NAME);

	if (IS_ERR(vpq_memc_class))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "scalevpqmemc: can not create class...\n");
	    result=PTR_ERR(vpq_memc_class);
		goto fail_class_create;
	}
	vpq_memc_class->devnode = vpq_memc_devnode;
	vpq_memc_platform_devs = platform_device_register_simple(VPQ_MEMC_DEVICE_NAME, -1, NULL, 0);
    if((result=platform_driver_register(&vpq_memc_device_driver)) != 0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vpqmemc: can not register platform driver...\n");
    	goto fail_platform_driver_register;
    }

	cdev_init(&vpq_memc_cdev, &vpq_memc_fops);
	vpq_memc_cdev.owner = THIS_MODULE;
   	vpq_memc_cdev.ops = &vpq_memc_fops;
	result = cdev_add (&vpq_memc_cdev, vpq_memc_devno, 1);
	if (result)
	{
		MEMC_DBG_PRINT("Error %d adding VPQ_MEMC_DEVICE!\n", result);
		goto fail_cdev_init;
	}
	device_create(vpq_memc_class, NULL, MKDEV(vpq_memc_major, 0), NULL,VPQ_MEMC_DEVICE_NAME);
	sema_init(&vpq_memc_Semaphore, 1);
	sema_init(&livezoom_memcclose_Semaphore, 1);
	//panel_parameter =  (PANEL_CONFIG_PARAMETER *)&platform_info.panel_parameter;
	//Panel_InitParameter(panel_parameter);
	//Panel_LVDS_To_Hdmi_Converter_Parameter();

        register_pm_notifier(&memc_notifier);

	return 0;//Success

fail_cdev_init:
	platform_driver_unregister(&vpq_memc_device_driver);
fail_platform_driver_register:
	platform_device_unregister(vpq_memc_platform_devs);
	vpq_memc_platform_devs = NULL;
	class_destroy(vpq_memc_class);
fail_class_create:
	vpq_memc_class = NULL;
	unregister_chrdev_region(vpq_memc_devno, vpq_memc_nr_devs);
	return result;
}

void __exit vpq_memc_module_exit(void)
{
	dev_t devno = MKDEV(vpq_memc_major, vpq_memc_minor);
	MEMC_DBG_PRINT("vbe clean module vpq_memc_major = %d\n", vpq_memc_major);

  	device_destroy(vpq_memc_class, MKDEV(vpq_memc_major, 0));
  	class_destroy(vpq_memc_class);
	vpq_memc_class=NULL;
	cdev_del(&vpq_memc_cdev);

   	/* device driver removal */
	if(vpq_memc_platform_devs)
	{
		platform_device_unregister(vpq_memc_platform_devs);
		vpq_memc_platform_devs=NULL;
	}
  	platform_driver_unregister(&vpq_memc_device_driver);

	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, vpq_memc_nr_devs);
}

module_init(vpq_memc_module_init);
module_exit(vpq_memc_module_exit);
