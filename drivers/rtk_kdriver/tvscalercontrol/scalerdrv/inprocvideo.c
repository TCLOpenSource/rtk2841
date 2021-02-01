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

//#include <stdio.h>

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/semaphore.h>

#include <rtd_types.h>
//#include "rtd_regs.h"
//#include "rtd_macro.h"
//#include <rbus/rbusVDTopReg.h>
#include <rbus/vdtop_reg.h>//sunray
//#include <rbus/rbusVDPQReg.h>
#include <rbus/vdpq_reg.h>//sunray
#include <rbus/vgip_reg.h>
//#include <tvscalercontrol/scalerCommon.h>
#include <scalercommon/scalerCommon.h>
#include "tvscalercontrol/io/ioregdrv.h"
//#include "libs/utils/rtSystem.h"
#include "tvscalercontrol/scaler/scaleratv.h"
#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/scalerdrv/mode.h"
#include "tvscalercontrol/scalerdrv/inprocvideo.h"
#include "tvscalercontrol/scalerdrv/syncproc.h"
#include "tvscalercontrol/vdc/video.h"
#include "tvscalercontrol/scaler_vfedev.h"
#include "tvscalercontrol/avd/avdctrl.h"
#include "tvscalercontrol/scaler/scalerlib.h"
#ifdef CONFIG_ENABLE_SPEED_UP_CH_SWITCH
#include "tvscalercontrol/scaler/modeState.h" //for _MODE_SUCCESS
#endif //#ifdef CONFIG_ENABLE_SPEED_UP_CH_SWITCH
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#include "tvscalercontrol/scaler/scalervideo.h"
#endif //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

#include <mach/rtk_log.h>
#define TAG_NAME_AVD "AVD"  //sunray add for log 2016-06-06

#define ScalerTimer_DelayXms(mSec)		msleep(mSec)

#define Rt_Delay(mSec)					msleep(mSec)

#define Rt_Sleep(mSec)					msleep(mSec)

/*
#include "scaler/inprocvideo.h"
#include "scaler/mode.h"
#include "scaler_display.h"
#include "scaler/syncproc.h"
#include "scaler/scalerdef.h"
#include "scaler.h"
#include "dragon.h"
#include "video/dragon_video.h"
*/


#define VDC_MEASURE_NTSC_VFREQ_MAX			620
#define VDC_MEASURE_NTSC_VFREQ_MIN			580
#define VDC_MEASURE_PAL_VFREQ_MAX			520
#define VDC_MEASURE_PAL_VFREQ_MIN			480
#define VDC_RE_MEASURE_COUNTER			20


//#define AVD_CKill_table

#define AV_OFFSET_LEN	2
#define SV_OFFSET_LEN	2

#ifdef CONFIG_CUSTOMER_TV030
#define AV_OFFSETX_NTSC        		(44)
#define AV_OFFSETY_NTSC        		(0)
#define AV_OFFSETX_PAL_M       		(44)
#define AV_OFFSETY_PAL_M       		(0)
#define AV_OFFSETX_NTSC_50     		(44)
#define AV_OFFSETY_NTSC_50     		(4)
#define AV_OFFSETX_PAL_N       		(44)
#define AV_OFFSETY_PAL_N       		(4)
#define AV_OFFSETX_NTSC_443    		(44)
#define AV_OFFSETY_NTSC_443    		(0)
#define AV_OFFSETX_PAL_60      		(44)
#define AV_OFFSETY_PAL_60      		(0)
#define AV_OFFSETX_PAL_I       		(44)
#define AV_OFFSETY_PAL_I       		(4)
#define AV_OFFSETX_SECAM       		(28)
#define AV_OFFSETY_SECAM       		(4)
#else
#define AV_OFFSETX_NTSC        		(52)
#define AV_OFFSETY_NTSC        		(1)
#define AV_OFFSETX_PAL_M       		(52)
#define AV_OFFSETY_PAL_M       		(1)
#define AV_OFFSETX_NTSC_50     		(52)
#define AV_OFFSETY_NTSC_50     		(5)
#define AV_OFFSETX_PAL_N       		(52)
#define AV_OFFSETY_PAL_N       		(5)
#define AV_OFFSETX_NTSC_443    		(52)
#define AV_OFFSETY_NTSC_443    		(1)
#define AV_OFFSETX_PAL_60      		(52)
#define AV_OFFSETY_PAL_60      		(1)
#define AV_OFFSETX_PAL_I       		(52)
#define AV_OFFSETY_PAL_I       		(5)
#define AV_OFFSETX_SECAM       		(37)
#define AV_OFFSETY_SECAM       		(6)
#endif

#ifdef CONFIG_CUSTOMER_TV030
#define AV_CKILL_OFFSETX_NTSC      	(44)
#define AV_CKILL_OFFSETY_NTSC      	(1)
#define AV_CKILL_OFFSETX_PAL_M     	(52)
#define AV_CKILL_OFFSETY_PAL_M     	(1)
#define AV_CKILL_OFFSETX_NTSC_50   	(52)
#define AV_CKILL_OFFSETY_NTSC_50   	(5)
#define AV_CKILL_OFFSETX_PAL_N     	(52)
#define AV_CKILL_OFFSETY_PAL_N     	(5)
#define AV_CKILL_OFFSETX_NTSC_443  	(44)
#define AV_CKILL_OFFSETY_NTSC_443  	(1)
#define AV_CKILL_OFFSETX_PAL_60    	(52)
#define AV_CKILL_OFFSETY_PAL_60    	(1)
#define AV_CKILL_OFFSETX_PAL_I     	(52)
#define AV_CKILL_OFFSETY_PAL_I     	(5)//30(force align)
#define AV_CKILL_OFFSETX_SECAM     	(37)
#define AV_CKILL_OFFSETY_SECAM     	(6)//31(force align)
#else
#define AV_CKILL_OFFSETX_NTSC      	(52)
#define AV_CKILL_OFFSETY_NTSC      	(1)
#define AV_CKILL_OFFSETX_PAL_M     	(52)
#define AV_CKILL_OFFSETY_PAL_M     	(1)
#define AV_CKILL_OFFSETX_NTSC_50   	(52)
#define AV_CKILL_OFFSETY_NTSC_50   	(5)
#define AV_CKILL_OFFSETX_PAL_N     	(52)
#define AV_CKILL_OFFSETY_PAL_N     	(5)
#define AV_CKILL_OFFSETX_NTSC_443  	(52)
#define AV_CKILL_OFFSETY_NTSC_443  	(1)
#define AV_CKILL_OFFSETX_PAL_60    	(52)
#define AV_CKILL_OFFSETY_PAL_60    	(1)
#define AV_CKILL_OFFSETX_PAL_I     	(52)
#define AV_CKILL_OFFSETY_PAL_I     	(5)//30(force align)
#define AV_CKILL_OFFSETX_SECAM     	(37)
#define AV_CKILL_OFFSETY_SECAM     	(6)//31(force align)
#endif

#define SV_OFFSETX_NTSC        		(0)
#define SV_OFFSETY_NTSC        		(0)
#define SV_OFFSETX_PAL_M       		(0)
#define SV_OFFSETY_PAL_M       		(0)
#define SV_OFFSETX_NTSC_50     		(0)
#define SV_OFFSETY_NTSC_50     		(0)
#define SV_OFFSETX_PAL_N       		(0)
#define SV_OFFSETY_PAL_N       		(0)
#define SV_OFFSETX_NTSC_443    		(0)
#define SV_OFFSETY_NTSC_443    		(0)
#define SV_OFFSETX_PAL_60      		(0)
#define SV_OFFSETY_PAL_60      		(0)
#define SV_OFFSETX_PAL_I       		(0)
#define SV_OFFSETY_PAL_I       		(0)
#define SV_OFFSETX_SECAM       		(0)
#define SV_OFFSETY_SECAM       		(0)

#ifdef CONFIG_CUSTOMER_TV030
#define ATV_OFFSETX_NTSC        	(31)	//20180531--3d
#define ATV_OFFSETY_NTSC        	(0)//20180531--3d
#define ATV_OFFSETX_PAL_M       	(30)	//20180531--3d
#define ATV_OFFSETY_PAL_M       	(0)	//20180531--3d
#define ATV_OFFSETX_NTSC_50     	(0)
#define ATV_OFFSETY_NTSC_50     	(0)
#define ATV_OFFSETX_PAL_N       	(39)//20180531--3D
#define ATV_OFFSETY_PAL_N       	(3)//20180531--3D
#define ATV_OFFSETX_NTSC_443    	(5)//20180531--
#define ATV_OFFSETY_NTSC_443    	(-1)//20180531--
#define ATV_OFFSETX_PAL_60      	(-15)
#define ATV_OFFSETY_PAL_60      	(0)
#define ATV_OFFSETX_PAL_I       	(15)//20180531--3D
#define ATV_OFFSETY_PAL_I       	(4)
#define ATV_OFFSETX_SECAM       	(-15)//mei you
#define ATV_OFFSETY_SECAM       	(4)
#else
#define ATV_OFFSETX_NTSC        	(33)	//TV_Colombia:6
#define ATV_OFFSETY_NTSC        	(1)
#define ATV_OFFSETX_PAL_M       	(24)	//TV_Colombia:-1
#define ATV_OFFSETY_PAL_M       	(1)	//TV_Colombia:1
#define ATV_OFFSETX_NTSC_50     	(0)
#define ATV_OFFSETY_NTSC_50     	(0)
#define ATV_OFFSETX_PAL_N       	(38)//TV_Colombia:6
#define ATV_OFFSETY_PAL_N       	(4)
#define ATV_OFFSETX_NTSC_443    	(0)
#define ATV_OFFSETY_NTSC_443    	(1)
#define ATV_OFFSETX_PAL_60      	(-15)
#define ATV_OFFSETY_PAL_60      	(0)
#define ATV_OFFSETX_PAL_I       	(14)
#define ATV_OFFSETY_PAL_I       	(5)
#define ATV_OFFSETX_SECAM       	(-41)
#define ATV_OFFSETY_SECAM       	(5)
#endif

#ifdef AVD_CKill_table
#define ATV_CKILL_OFFSETX_NTSC      (-2)// TV_Colombia:-2
#define ATV_CKILL_OFFSETY_NTSC      (1)// TV_Colombia:1
#define ATV_CKILL_OFFSETX_PAL_M     (-9)// TV_Colombia:-9
#define ATV_CKILL_OFFSETY_PAL_M     (7)// TV_Colombia:7
#define ATV_CKILL_OFFSETX_NTSC_50   (0)
#define ATV_CKILL_OFFSETY_NTSC_50   (0)
#define ATV_CKILL_OFFSETX_PAL_N     (10)
#define ATV_CKILL_OFFSETY_PAL_N     (5)	// TV_Colombia:5
#define ATV_CKILL_OFFSETX_NTSC_443  (6)
#define ATV_CKILL_OFFSETY_NTSC_443  (0)
#define ATV_CKILL_OFFSETX_PAL_60    (-15)
#define ATV_CKILL_OFFSETY_PAL_60    (0)
#define ATV_CKILL_OFFSETX_PAL_I     (-5)
#define ATV_CKILL_OFFSETY_PAL_I     (5)
#define ATV_CKILL_OFFSETX_SECAM     (-43)
#define ATV_CKILL_OFFSETY_SECAM     (6)
#endif

#define EXTD_ATV_OFFSETX_NTSC        	(5)
#define EXTD_ATV_OFFSETY_NTSC        	(-1)
#define EXTD_ATV_OFFSETX_PAL_M       	(6)
#define EXTD_ATV_OFFSETY_PAL_M       	(5)
#define EXTD_ATV_OFFSETX_NTSC_50     	(0)
#define EXTD_ATV_OFFSETY_NTSC_50     	(0)
#define EXTD_ATV_OFFSETX_PAL_N       	(13)
#define EXTD_ATV_OFFSETY_PAL_N       	(5)
#define EXTD_ATV_OFFSETX_NTSC_443    	(-19)
#define EXTD_ATV_OFFSETY_NTSC_443    	(-1)
#define EXTD_ATV_OFFSETX_PAL_60      	(-15)
#define EXTD_ATV_OFFSETY_PAL_60      	(0)
#define EXTD_ATV_OFFSETX_PAL_I       	(-7)//TV_DVBT:-2
#define EXTD_ATV_OFFSETY_PAL_I       	(5)
#define EXTD_ATV_OFFSETX_SECAM       	(-4)
#define EXTD_ATV_OFFSETY_SECAM       	(6)

#ifdef AVD_CKill_table
#define EXTD_ATV_CKILL_OFFSETX_NTSC        	(5)
#define EXTD_ATV_CKILL_OFFSETY_NTSC        	(-1)
#define EXTD_ATV_CKILL_OFFSETX_PAL_M       	(6)
#define EXTD_ATV_CKILL_OFFSETY_PAL_M       	(5)
#define EXTD_ATV_CKILL_OFFSETX_NTSC_50     	(0)
#define EXTD_ATV_CKILL_OFFSETY_NTSC_50     	(0)
#define EXTD_ATV_CKILL_OFFSETX_PAL_N       	(-8)
#define EXTD_ATV_CKILL_OFFSETY_PAL_N       	(5)
#define EXTD_ATV_CKILL_OFFSETX_NTSC_443    	(-19)
#define EXTD_ATV_CKILL_OFFSETY_NTSC_443    	(-1)
#define EXTD_ATV_CKILL_OFFSETX_PAL_60      	(-15)
#define EXTD_ATV_CKILL_OFFSETY_PAL_60      	(0)
#define EXTD_ATV_CKILL_OFFSETX_PAL_I       	(-5)
#define EXTD_ATV_CKILL_OFFSETY_PAL_I       	(5)
#define EXTD_ATV_CKILL_OFFSETX_SECAM       	(-5)
#define EXTD_ATV_CKILL_OFFSETY_SECAM       	(6)
#endif

static INT8 g_av_offset_array[][2] = {
	{ AV_OFFSETX_NTSC, 		AV_OFFSETY_NTSC},
	{ AV_OFFSETX_PAL_M, 	AV_OFFSETY_PAL_M},
	{ AV_OFFSETX_NTSC_50, 	AV_OFFSETY_NTSC_50},
	{ AV_OFFSETX_PAL_N,		AV_OFFSETY_PAL_N},
	{ AV_OFFSETX_NTSC_443, 	AV_OFFSETY_NTSC_443},
	{ AV_OFFSETX_PAL_60, 	AV_OFFSETY_PAL_60},
	{ AV_OFFSETX_PAL_I, 	AV_OFFSETY_PAL_I},
	{ AV_OFFSETX_SECAM, 	AV_OFFSETY_SECAM}
};

static INT8 g_av_ckill_offset_array[][2] = {
	{ AV_CKILL_OFFSETX_NTSC, 		AV_CKILL_OFFSETY_NTSC},
	{ AV_CKILL_OFFSETX_PAL_M, 		AV_CKILL_OFFSETY_PAL_M},
	{ AV_CKILL_OFFSETX_NTSC_50, 	AV_CKILL_OFFSETY_NTSC_50},
	{ AV_CKILL_OFFSETX_PAL_N,		AV_CKILL_OFFSETY_PAL_N},
	{ AV_CKILL_OFFSETX_NTSC_443, 	AV_CKILL_OFFSETY_NTSC_443},
	{ AV_CKILL_OFFSETX_PAL_60, 		AV_CKILL_OFFSETY_PAL_60},
	{ AV_CKILL_OFFSETX_PAL_I, 		AV_CKILL_OFFSETY_PAL_I},
	{ AV_CKILL_OFFSETX_SECAM, 		AV_CKILL_OFFSETY_SECAM}
};

static INT8 g_sv_offset_array[][2] = {
	{ SV_OFFSETX_NTSC, 		SV_OFFSETY_NTSC},
	{ SV_OFFSETX_PAL_M, 	SV_OFFSETY_PAL_M},
	{ SV_OFFSETX_NTSC_50, 	SV_OFFSETY_NTSC_50},
	{ SV_OFFSETX_PAL_N,		SV_OFFSETY_PAL_N},
	{ SV_OFFSETX_NTSC_443, 	SV_OFFSETY_NTSC_443},
	{ SV_OFFSETX_PAL_60, 	SV_OFFSETY_PAL_60},
	{ SV_OFFSETX_PAL_I, 	SV_OFFSETY_PAL_I},
	{ SV_OFFSETX_SECAM, 	SV_OFFSETY_SECAM}
};

static INT8 g_atv_offset_array[][2] = {
	{ ATV_OFFSETX_NTSC, 	ATV_OFFSETY_NTSC},
	{ ATV_OFFSETX_PAL_M, 	ATV_OFFSETY_PAL_M},
	{ ATV_OFFSETX_NTSC_50, 	ATV_OFFSETY_NTSC_50},
	{ ATV_OFFSETX_PAL_N,	ATV_OFFSETY_PAL_N},
	{ ATV_OFFSETX_NTSC_443,	ATV_OFFSETY_NTSC_443},
	{ ATV_OFFSETX_PAL_60, 	ATV_OFFSETY_PAL_60},
	{ ATV_OFFSETX_PAL_I, 	ATV_OFFSETY_PAL_I},
	{ ATV_OFFSETX_SECAM, 	ATV_OFFSETY_SECAM}
};

#ifdef AVD_CKill_table
static INT8 g_atv_ckill_offset_array[][2] = {
	{ ATV_CKILL_OFFSETX_NTSC, 		ATV_CKILL_OFFSETY_NTSC},
	{ ATV_CKILL_OFFSETX_PAL_M, 		ATV_CKILL_OFFSETY_PAL_M},
	{ ATV_CKILL_OFFSETX_NTSC_50, 	ATV_CKILL_OFFSETY_NTSC_50},
	{ ATV_CKILL_OFFSETX_PAL_N,		ATV_CKILL_OFFSETY_PAL_N},
	{ ATV_CKILL_OFFSETX_NTSC_443,	ATV_CKILL_OFFSETY_NTSC_443},
	{ ATV_CKILL_OFFSETX_PAL_60, 	ATV_CKILL_OFFSETY_PAL_60},
	{ ATV_CKILL_OFFSETX_PAL_I, 		ATV_CKILL_OFFSETY_PAL_I},
	{ ATV_CKILL_OFFSETX_SECAM, 		ATV_CKILL_OFFSETY_SECAM}
};
#endif

static INT8 g_extd_atv_offset_array[][2] = {
	{ EXTD_ATV_OFFSETX_NTSC, 		EXTD_ATV_OFFSETY_NTSC},
	{ EXTD_ATV_OFFSETX_PAL_M, 		EXTD_ATV_OFFSETY_PAL_M},
	{ EXTD_ATV_OFFSETX_NTSC_50, 	EXTD_ATV_OFFSETY_NTSC_50},
	{ EXTD_ATV_OFFSETX_PAL_N,		EXTD_ATV_OFFSETY_PAL_N},
	{ EXTD_ATV_OFFSETX_NTSC_443,	EXTD_ATV_OFFSETY_NTSC_443},
	{ EXTD_ATV_OFFSETX_PAL_60, 		EXTD_ATV_OFFSETY_PAL_60},
	{ EXTD_ATV_OFFSETX_PAL_I, 		EXTD_ATV_OFFSETY_PAL_I},
	{ EXTD_ATV_OFFSETX_SECAM, 		EXTD_ATV_OFFSETY_SECAM}
};

#ifdef AVD_CKill_table
static INT8 g_extd_atv_ckill_offset_array[][2] = {
	{ EXTD_ATV_CKILL_OFFSETX_NTSC, 		EXTD_ATV_CKILL_OFFSETY_NTSC},
	{ EXTD_ATV_CKILL_OFFSETX_PAL_M, 	EXTD_ATV_CKILL_OFFSETY_PAL_M},
	{ EXTD_ATV_CKILL_OFFSETX_NTSC_50, 	EXTD_ATV_CKILL_OFFSETY_NTSC_50},
	{ EXTD_ATV_CKILL_OFFSETX_PAL_N,		EXTD_ATV_CKILL_OFFSETY_PAL_N},
	{ EXTD_ATV_CKILL_OFFSETX_NTSC_443,	EXTD_ATV_CKILL_OFFSETY_NTSC_443},
	{ EXTD_ATV_CKILL_OFFSETX_PAL_60, 	EXTD_ATV_CKILL_OFFSETY_PAL_60},
	{ EXTD_ATV_CKILL_OFFSETX_PAL_I, 	EXTD_ATV_CKILL_OFFSETY_PAL_I},
	{ EXTD_ATV_CKILL_OFFSETX_SECAM, 	EXTD_ATV_CKILL_OFFSETY_SECAM}
};
#endif

//For CVBS
static UINT16 g_tAV_PRESET_TABLE[][9] =
{
	// VIDEO-60(NTSC)
	{
		858,				//IH_TOTAL
		208,				//IH_ACT_STA
		720,				//IH_ACT_WID
		15,					//IV_ACT_STA
		240,				//IV_ACT_LEN
		_DISPLAY_RATIO_95,	//H_Ratio percent
		_DISPLAY_RATIO_98,	//V_Ratio percent
		36,					//H_Ratio value
		5					//V_Ratio value
	},
	// VIDEO-50(PAL& SECAM)
	{
		864,				//IH_TOTAL
		208,				//IH_ACT_STA
		720,				//IH_ACT_WID
		15,					//IV_ACT_STA
		288,				//IV_ACT_LEN
		_DISPLAY_RATIO_92,	//H_Ratio percent
		_DISPLAY_RATIO_98,	//V_Ratio percent
		45,					//H_Ratio value
		8					//V_Ratio value
	},
};

//For S-Video
static UINT16 g_tVIDEO8_PRESET_TABLE[][9] =
{
	// VIDEO-60(NTSC)
	{
		858,				//IH_TOTAL
		131,				//IH_ACT_STA
		720,				//IH_ACT_WID
		15,					//IV_ACT_STA
		240,				//IV_ACT_LEN
		_DISPLAY_RATIO_95,	//H_Ratio percent
		_DISPLAY_RATIO_98,	//V_Ratio percent
		36,					//H_Ratio value
		5					//V_Ratio value
	},
	// VIDEO-50(PAL& SECAM)
	{
		864,				//IH_TOTAL
		138,				//IH_ACT_STA
		720,				//IH_ACT_WID
		13,					//IV_ACT_STA
		288,				//IV_ACT_LEN
		_DISPLAY_RATIO_92,	//H_Ratio percent
		_DISPLAY_RATIO_98,	//V_Ratio percent
		45,					//H_Ratio value
		8					//V_Ratio value
	},
};





extern struct semaphore* get_offline_semaphore(void);
static unsigned short *tAV_PRESET_TABLE = &g_tAV_PRESET_TABLE[0][0];
static unsigned short *tVIDEO8_PRESET_TABLE = &g_tVIDEO8_PRESET_TABLE[0][0];
static char *av_offset_array = &g_av_offset_array[0][0];
static char *av_ckill_offset_array = &g_av_ckill_offset_array[0][0];
static char *sv_offset_array = &g_sv_offset_array[0][0];
static char *atv_offset_array = &g_atv_offset_array[0][0];
static char *extd_atv_offset_array = &g_extd_atv_offset_array[0][0];
#ifdef AVD_CKill_table
static char *atv_ckill_offset_array = &g_atv_ckill_offset_array[0][0];
static char *extd_atv_ckill_offset_array = &g_extd_atv_ckill_offset_array[0][0];
#endif

//static bool change_color_std_only = false;







static unsigned char g_ucVideoMode;


void drvif_inprocvideo_SetVideoMode(unsigned char a_ucVideoMode)
{
	g_ucVideoMode = a_ucVideoMode;
}




/**
 * This API is used to init scaler setting for vdc related signal
 *
 * @param [input] :
 * @param [output] :
 * @return None
 *
 */
void drvif_inprocvideo_init(void)
{
	//Set V10Bit swap control normal
	//frank@0520 remove redundant code
	//IoReg_SetBits(VGIP_V10_CTRL_VADDR, _BIT4);
	//no signal counter down initial value
//jj	IoReg_Write32(VDC_NO_SIGNAL_DEC_VADDR, 0x03);//frank@0908 speed up no-signal status
	drvif_module_vdc_set_noSignalCounter_Value(0x03);	//jj@20130820 [2:0]=0x03,speed up no-signal status
}


#if 0
void drvif_inprocvideo_config_capture(unsigned char display, unsigned char modecnt)
{
	//0: ntsc. 1: palm. 2: ntsc50. 3: paln. 4: ntsc443. 5: pal60. 6: pali. 7: secam.
	unsigned char vd_mode = 0;

	modecnt -= _MODE_480I;
#if 1
	if (Scaler_InputSrcGetMainChType() == _SRC_TV)
	{
		/*
		//if (fw_tv_getvideomode()==ZAUTO)
		if (g_ucVideoMode==ZAUTO)
		{
			//vd_mode = fwif_tv_ConvertToRegColorStandard();
		}
		else
		{
			//vd_mode = fw_tv_getvideomode()  & 0x0f;
			vd_mode = g_ucVideoMode  & 0x0f;
		}
		*/


		vd_mode = g_ucVideoMode  & 0x0f;
	}
	else
		vd_mode = drvif_module_vdc_ReadMode(VDC_DETECT);
#else
	vd_mode = drvif_module_vdc_ReadMode(VDC_DETECT);
#endif
	if(modecnt == 0) {	//_MODE_480I
		if((vd_mode != VDC_MODE_NTSC)&&(vd_mode != VDC_MODE_PALM)&&(vd_mode != VDC_MODE_NTSC443)&&(vd_mode != VDC_MODE_PAL60))
			vd_mode = VDC_MODE_NTSC;
	}
	else {
		if((vd_mode != VDC_MODE_NTSC50)&&(vd_mode != VDC_MODE_PALN)&&(vd_mode != VDC_MODE_PALI)&&(vd_mode != VDC_MODE_SECAM))
			vd_mode = VDC_MODE_PALI;
	}

	//<Stanley K81014> For Overscan function.
	if(Scaler_InputSrcGetMainChType() == _SRC_CVBS || Scaler_InputSrcGetMainChType() == _SRC_TV) {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"DEBUG: modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, *(av_offset_array+vd_mode*AV_OFFSET_LEN), *(av_offset_array+vd_mode*AV_OFFSET_LEN+1));

//orginal jeffrey
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN,*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE,(unsigned short)((int)((*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)(*(av_offset_array+vd_mode*AV_OFFSET_LEN))));
//		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE,(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2+av_offset_array[vd_mode][0]);

		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE,*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+2));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA_PRE,(unsigned short)((int)(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)(*(av_offset_array+vd_mode*AV_OFFSET_LEN+1))));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE,*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+4));
	}
	else {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"DEBUG: modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, *(sv_offset_array+vd_mode*AV_OFFSET_LEN), *(sv_offset_array+vd_mode*AV_OFFSET_LEN+1));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN,*(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE,(unsigned short)((int)((*(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)(*(sv_offset_array+vd_mode*AV_OFFSET_LEN))));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE,*(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+2));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA_PRE,(unsigned short)((int)(*(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)(*(sv_offset_array+vd_mode*AV_OFFSET_LEN+1))));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE,*(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+4));
	}

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
	if(VD_27M_OFF != fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)display))
	{
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN, Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)<<1);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE)<<1);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)<<1);
	}
#endif //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

#if 0
	//patch zoom in 100 % and occur dirth line
	if(_ENABLE == Scaler_Get_Zoom_In_Out_Enable())
	{
		if(Scaler_InputSrcGetMainChType() == _SRC_CVBS)
		{
			//		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"zoom in overscan tv & av source  PRE_V_LEN -8 , PRE_V_STA + 4\n");
			//		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE,Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE) - 8 );
			//		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA_PRE,Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_STA_PRE) + 4 );
		}
		else if (Scaler_InputSrcGetMainChType() == _SRC_TV)
		{
			//	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"zoom in overscan tv & av source  PRE_V_LEN -12 , PRE_V_STA + 6\n");
			//	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE,Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_LEN_PRE) - 6 );
			//	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA_PRE,Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_IPV_ACT_STA_PRE) + 4 );
		}
	}
#endif

}

#endif

void drvif_inprocvideo_config_capture(unsigned char a_ucSrc, unsigned char display, unsigned char modecnt, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo,unsigned char vd_mode, unsigned char supportColor)
{
	//0: ntsc. 1: palm. 2: ntsc50. 3: paln. 4: ntsc443. 5: pal60. 6: pali. 7: secam.
//	unsigned char vd_mode = 0;

	bool ckill_on = false;
	modecnt -= _MODE_480I;

	bool ck_1 = !drvif_module_vdc_GetChromaLockStatus();
	bool ck_2 = drvif_module_vdc_CKill_status();
	int vgip_offset_h = 0, vgip_offset_v = 0;
	// ckill offsets will be applied only for av source 20151218
	if((drvif_module_vdc_ReadMode(VDC_SET) != drvif_module_vdc_ReadMode(VDC_DETECT)) ||
		ck_1 || ck_2)
	{
		if (supportColor != 0) {
			ckill_on = true;
			//vd_mode = drvif_module_vdc_ReadMode(VDC_DETECT);
		}
	}
	//dump_stack();
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"%s line:%d ckill_on:%d ck_1:%d ck_2:%d burst:%d modecnt:%d vd:%d set:%d det:%d supportColor:0x%x\n", __func__, __LINE__, ckill_on, ck_1, ck_2, vdc_BurstLockStatus, modecnt, vd_mode, drvif_module_vdc_ReadMode(VDC_SET), drvif_module_vdc_ReadMode(VDC_DETECT), supportColor);

	if(modecnt == 2) { // apply new vd_mode as modecnt = _MODE_480I + 2
		if(vd_mode == VDC_MODE_NTSC || vd_mode == VDC_MODE_PALM || vd_mode == VDC_MODE_NTSC443 || vd_mode == VDC_MODE_PAL60)
			modecnt = 0;
		else
			modecnt = 1;
	}

	if(modecnt == 1 && vd_mode >= VDC_MODE_AUTO)
		vd_mode = VDC_MODE_PALI;
	else if (vd_mode >= VDC_MODE_AUTO)
		vd_mode = VDC_MODE_NTSC;

#if 0
	else if(modecnt == 0) {	//_MODE_480I
		if((vd_mode != VDC_MODE_NTSC)&&(vd_mode != VDC_MODE_PALM)&&(vd_mode != VDC_MODE_NTSC443)&&(vd_mode != VDC_MODE_PAL60))
			vd_mode = VDC_MODE_NTSC;
	}
	else {
		if((vd_mode != VDC_MODE_NTSC50)&&(vd_mode != VDC_MODE_PALN)&&(vd_mode != VDC_MODE_PALI)&&(vd_mode != VDC_MODE_SECAM))
			vd_mode = VDC_MODE_PALI;
	}
#endif

	//<Stanley K81014> For Overscan function.
	if(a_ucSrc == _SRC_CVBS || a_ucSrc == _SRC_TV) {
		if (a_ucSrc == _SRC_CVBS) {
			if(ckill_on) {
				vgip_offset_h = *(av_ckill_offset_array + vd_mode*AV_OFFSET_LEN);
				vgip_offset_v = *(av_ckill_offset_array + vd_mode*AV_OFFSET_LEN + 1);
				rtd_printk(KERN_INFO, TAG_NAME_AVD,"DEBUG AV ckill : modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, vgip_offset_h, vgip_offset_v);
				a_ptDispInfo->IPH_ACT_STA_PRE = (unsigned short)((int)((*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)vgip_offset_h);
				a_ptDispInfo->IPV_ACT_STA_PRE = (unsigned short)((int)(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)vgip_offset_v);
			}
			else
			{
				vgip_offset_h = *(av_offset_array + vd_mode*AV_OFFSET_LEN);
				vgip_offset_v = *(av_offset_array + vd_mode*AV_OFFSET_LEN + 1);
				if (supportColor == TV_AllMode && vd_mode == VDC_MODE_NTSC443)
					vgip_offset_v--;
				rtd_printk(KERN_INFO, TAG_NAME_AVD,"DEBUG AV: modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, vgip_offset_h, vgip_offset_v);
				a_ptDispInfo->IPH_ACT_STA_PRE = (unsigned short)((int)((*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)vgip_offset_h);
				a_ptDispInfo->IPV_ACT_STA_PRE = (unsigned short)((int)(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)vgip_offset_v);
			}
		}
		else {
			if (AVD_EXTERNAL_DEMOD == Scaler_AVD_GetDemodType()) {
#ifdef AVD_CKill_table
				if(ckill_on) {
					vgip_offset_h = *(extd_atv_ckill_offset_array + vd_mode*AV_OFFSET_LEN);
					vgip_offset_v = *(extd_atv_ckill_offset_array + vd_mode*AV_OFFSET_LEN + 1);
					rtd_printk(KERN_INFO, TAG_NAME_AVD,"DEBUG EXT ATV ckill : modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, vgip_offset_h, vgip_offset_v);
					a_ptDispInfo->IPH_ACT_STA_PRE = (unsigned short)((int)((*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)vgip_offset_h);
					a_ptDispInfo->IPV_ACT_STA_PRE = (unsigned short)((int)(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)vgip_offset_v);
				} else
#endif
				{
					vgip_offset_h = *(extd_atv_offset_array + vd_mode*AV_OFFSET_LEN);
					vgip_offset_v = *(extd_atv_offset_array + vd_mode*AV_OFFSET_LEN + 1);
					rtd_printk(KERN_INFO, TAG_NAME_AVD,"DEBUG EXT ATV: modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, vgip_offset_h, vgip_offset_v);
					a_ptDispInfo->IPH_ACT_STA_PRE = (unsigned short)((int)((*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)vgip_offset_h);
					a_ptDispInfo->IPV_ACT_STA_PRE = (unsigned short)((int)(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)vgip_offset_v);
				}
			} else {
#ifdef AVD_CKill_table
				if(ckill_on) {
					vgip_offset_h = *(atv_ckill_offset_array + vd_mode*AV_OFFSET_LEN);
					vgip_offset_v = *(atv_ckill_offset_array + vd_mode*AV_OFFSET_LEN + 1);
					rtd_printk(KERN_INFO, TAG_NAME_AVD,"DEBUG ATV ckill : modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, vgip_offset_h, vgip_offset_v);
					a_ptDispInfo->IPH_ACT_STA_PRE = (unsigned short)((int)((*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)vgip_offset_h);
					a_ptDispInfo->IPV_ACT_STA_PRE = (unsigned short)((int)(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)vgip_offset_v);
				} else
#endif
				{
					vgip_offset_h = *(atv_offset_array + vd_mode*AV_OFFSET_LEN);
					vgip_offset_v = *(atv_offset_array + vd_mode*AV_OFFSET_LEN + 1);
					rtd_printk(KERN_INFO, TAG_NAME_AVD,"DEBUG ATV: modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, vgip_offset_h, vgip_offset_v);
					a_ptDispInfo->IPH_ACT_STA_PRE = (unsigned short)((int)((*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)vgip_offset_h);
					a_ptDispInfo->IPV_ACT_STA_PRE = (unsigned short)((int)(*(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)vgip_offset_v);
				}
			}
		}

//orginal jeffrey
		a_ptDispInfo->IHTotal = *(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX);
		a_ptDispInfo->IPH_ACT_WID_PRE = *(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+2);
		a_ptDispInfo->IPV_ACT_LEN_PRE = *(tAV_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+4);
	}
	else {
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"DEBUG: modecnt %d, vd_mode %d, offset_h %d, offset_v %d\n", modecnt, vd_mode, *(sv_offset_array+vd_mode*AV_OFFSET_LEN), *(sv_offset_array+vd_mode*AV_OFFSET_LEN+1));
		a_ptDispInfo->IHTotal = *(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX);
		a_ptDispInfo->IPH_ACT_STA_PRE = (unsigned short)((int)((*(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+1)/2)*2)+(int)(*(sv_offset_array+vd_mode*AV_OFFSET_LEN)));
		a_ptDispInfo->IPH_ACT_WID_PRE = *(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+2);
		a_ptDispInfo->IPV_ACT_STA_PRE = (unsigned short)((int)(*(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+3))+(int)(*(sv_offset_array+vd_mode*AV_OFFSET_LEN+1)));
		a_ptDispInfo->IPV_ACT_LEN_PRE = *(tVIDEO8_PRESET_TABLE+modecnt*AV_PRESET_TABLE_COL_MAX+4);
	}
	//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_inprocvideo_config_capture, IPH_ACT_STA_PRE=%d\n", a_ptDispInfo->IPH_ACT_STA_PRE);

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
	//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"Scaler_Get_VDC_27MHz_Mode_Enable=%d, a_ucSrc=%d\n", Scaler_Get_VDC_27MHz_Mode_Enable(), a_ucSrc);
	//if(VD_27M_OFF != fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)display))
	if (TRUE == Scaler_Get_VDC_27MHz_Mode_Enable() && (a_ucSrc == _SRC_CVBS || a_ucSrc == _SRC_TV))
	{
		a_ptDispInfo->IHTotal = (a_ptDispInfo->IHTotal) << 1;
		a_ptDispInfo->IPH_ACT_STA_PRE = (a_ptDispInfo->IPH_ACT_STA_PRE) << 1;
		a_ptDispInfo->IPH_ACT_WID_PRE = (a_ptDispInfo->IPH_ACT_WID_PRE) << 1;
		//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"27M, a_ptDispInfo->IPH_ACT_STA_PRE = (a_ptDispInfo->IPH_ACT_STA_PRE) << 1\n");

		/*
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN, Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)<<1);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE)<<1);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)<<1);
		*/
	}
#endif //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
}



/**
* This API is used to setup scaler related setting for video8(including capture window, ip, clock,
 * display timing etc.)
 *
 * @param [input] :
 * @param [output] :
 * @return The result it setup.
 * @retval _SUCCESS If setup ok.
 * @retval _FAIL If setup fail.
 *
 */
#if 0
unsigned char drvif_inprocvideo_setup(void)
{
	unsigned short display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	unsigned short type = Scaler_InputSrcGetMainChType();


	// FixMe, 20140928
	//drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT);


	// FixMe, 20140928
	//drvif_inprocvideo_offline_measure_check((SCALER_DISP_CHANNEL)display);


	Scaler_DispSetInputInfo(SLR_INPUT_V_LEN,Scaler_ModeGetModeInfo(SLR_MODE_IVLEN));	// hsliao 20090519, pass IVTotal to calculate dclk
	Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ,Scaler_ModeGetModeInfo(SLR_MODE_IHFREQ));
	Scaler_DispSetInputInfo(SLR_INPUT_V_FREQ,Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ));

	//forster modified 061228
	drvif_inprocvideo_config_capture(display, Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));

	//enable interlace flag
	Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_INTERLACE, TRUE);
	Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_422, FALSE);

	// FixMe, 20140928
	/*
	if (Scaler_Get_Vflip_Enable())
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_VFLIP3, TRUE);
	*/

	return TRUE;
}
#endif


unsigned char drvif_inprocvideo_setup(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo)
{
	unsigned char ucRet = TRUE;
#if 0
	unsigned char ucVideoMode = drvif_module_vdc_IdentifyColorStandard(a_ucSrc);//drvif_module_vdc_ReadMode(VDC_DETECT);
	unsigned short VHalfTotal;


	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_inprocvideo_setup\n");

	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"ucVideoMode=%x\n", ucVideoMode);

	ucVideoMode = ucVideoMode | 0x10;
//	vdc_mode_detect = ucVideoMode & 0xf;

	if( (ucVideoMode == ZNTSC) ||
			(ucVideoMode == ZNTSC_443)||
			(ucVideoMode ==  ZPAL_60) ||
			(ucVideoMode  ==  ZPAL_M))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "480i\n");
		// 480i NTSC
		a_ptDispInfo->ucMode_Curr = _MODE_480I;
	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "576i\n");
		// 576i PAL
		a_ptDispInfo->ucMode_Curr = _MODE_576I;
	}

	down(get_offline_semaphore());
	if(drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT, a_ptDispInfo, a_ptTimingInfo) == _MODE_SUCCESS)
	{
		up(get_offline_semaphore());
		a_ptDispInfo->Polarity = a_ptTimingInfo->Polarity;

		a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount;

		a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal;
		a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal;
		a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq;
		a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq;


		a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount;
		drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf));


		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);

		drvif_module_vdc_GetVHalfTotalLen(&VHalfTotal);
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC CHalfTotal=%d\n", VHalfTotal);

		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_mode_offlinemeasure success\n");

		ucRet = TRUE;

	}
	else
	{
		up(get_offline_semaphore());
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_mode_offlinemeasure fail\n");
		ucRet = FALSE;
	}
#endif
	return ucRet;
}

unsigned char drvif_inprocvideo_setup_NoSignal(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo, unsigned char a_ucColorStd)
{
	//unsigned char ucVideoMode = drvif_module_vdc_IdentifyColorStandard(a_ucSrc);//drvif_module_vdc_ReadMode(VDC_DETECT);
	unsigned char ucVideoMode = a_ucColorStd;
	//unsigned short VHalfTotal;

	unsigned char ucRet = TRUE;
	unsigned short usVFreq = 0;
	unsigned int i = 0;

	rtd_printk(KERN_INFO, TAG_NAME_AVD,"drvif_inprocvideo_setup_NoSignal\n");

	rtd_printk(KERN_INFO, TAG_NAME_AVD,"ucVideoMode=%x\n", ucVideoMode);

	ucVideoMode = ucVideoMode | 0x10;
//	vdc_mode_detect = ucVideoMode & 0xf;

	if( (ucVideoMode == ZNTSC) ||
			(ucVideoMode == ZNTSC_443)||
			(ucVideoMode ==  ZPAL_60) ||
			(ucVideoMode  ==  ZPAL_M))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "480i\n");
		// 480i NTSC
		a_ptDispInfo->ucMode_Curr = _MODE_480I;
	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "576i\n");
		// 576i PAL
		a_ptDispInfo->ucMode_Curr = _MODE_576I;
	}

	down(get_offline_semaphore());

	if(drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT, a_ptDispInfo, a_ptTimingInfo) == _MODE_SUCCESS)
	{
		usVFreq = a_ptTimingInfo->IVFreq;
		ucRet = TRUE;
	}
	else
	{
		ucRet = FALSE;
	}

	up(get_offline_semaphore());


	rtd_printk(KERN_INFO, TAG_NAME_AVD,"usVFreq=%d\n", usVFreq);

	// Check 20 times
	for (i = 0; i < VDC_RE_MEASURE_COUNTER; i++)
	{
		// Signal is locked, don't check offlinemeasure
		if (1 == drvif_module_vdc_GetLockStatus())
			break;

		if  (_MODE_480I == a_ptDispInfo->ucMode_Curr)
		{
			// vFreq : 580~620
			if (usVFreq < VDC_MEASURE_NTSC_VFREQ_MAX && usVFreq > VDC_MEASURE_NTSC_VFREQ_MIN)
			{
				break;
			}
			else
			{
				down(get_offline_semaphore());
				if(drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT, a_ptDispInfo, a_ptTimingInfo) == _MODE_SUCCESS)
				{
					usVFreq = a_ptTimingInfo->IVFreq;

					ucRet = TRUE;

					rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"480i check count=%d, usVFreq=%d\n", i, usVFreq);
				}
				else
				{
					ucRet = FALSE;

					rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"480i  drvif_mode_offlinemeasure fail\n");
				}

				up(get_offline_semaphore());
			}
		}
		// 576i
		else
		{
			// vFreq : 480~520
			if (usVFreq < VDC_MEASURE_PAL_VFREQ_MAX &&  usVFreq > VDC_MEASURE_PAL_VFREQ_MIN)
			{
				break;
			}
			else
			{
				down(get_offline_semaphore());
				if(drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT, a_ptDispInfo, a_ptTimingInfo) == _MODE_SUCCESS)
				{
					usVFreq = a_ptTimingInfo->IVFreq;

					ucRet = TRUE;

					rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"576i check count=%d, usVFreq=%d\n", i, usVFreq);
				}
				else
				{
					ucRet = FALSE;

					rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"576i drvif_mode_offlinemeasure fail\n");
				}

				up(get_offline_semaphore());
			}
		}

		msleep(50);
	}

	if (TRUE == ucRet)
	{
		a_ptDispInfo->Polarity = a_ptTimingInfo->Polarity;
		a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount;
		a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal;
		a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal;
		a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq;
		a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq;
		a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount;

		drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf), 0);

		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);
	}
	else
	{
		if (_MODE_480I == a_ptDispInfo->ucMode_Curr)
		{
			//ucVideoMode = ZNTSC;
			a_ptDispInfo->Polarity = a_ptTimingInfo->Polarity = 0;
			a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount = 262;
			a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal = 262;
			a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal = 858;
			a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq = 157;
			a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq = 600;
			a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount = 127;
			drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf), 0);

			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);
		}
		else
		{
			//ucVideoMode = ZPAL_I;
			a_ptTimingInfo->Polarity = 0;
			a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount = 302;
			a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal = 302;
			a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal = 864;
			a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq = 156;
			a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq = 500;
			a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount = 127;
			drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf), 0);

			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);
		}
	}

	//no-signal case, v_total is smaller than v_active, refine v_total. @Crixus 20161209
	if(a_ptDispInfo->IVTotal < a_ptDispInfo->IPV_ACT_LEN_PRE){
		a_ptTimingInfo->IVTotal = a_ptDispInfo->IPV_ACT_LEN_PRE + a_ptDispInfo->IPV_ACT_STA_PRE*2;
		a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal;
	}

#if 0
	if(drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT, a_ptDispInfo, a_ptTimingInfo) == _MODE_SUCCESS)
	{
		up(get_offline_semaphore());
		a_ptDispInfo->Polarity = a_ptTimingInfo->Polarity;

		a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount;

		a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal;
		a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal;
		a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq;
		a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq;


		a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount;
		drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf), 0);


		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);

		//drvif_module_vdc_GetVHalfTotalLen(&VHalfTotal);
		//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC CHalfTotal=%d\n", VHalfTotal);

		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_mode_offlinemeasure success\n");

		ucRet = TRUE;

	}
	else
	{
		up(get_offline_semaphore());
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_mode_offlinemeasure fail\n");
		ucRet = FALSE;
	}
#endif
	return ucRet;
}


//
unsigned char drvif_inprocvideo_regTable(INPROCVIDE_TABLE_INFO info , unsigned short *ptr)
{
	if(!ptr)
		return FALSE;

	switch(info) {
	case INPROCVIDE_TABLE_AV:
		tAV_PRESET_TABLE = ptr;
		break;
	case INPROCVIDE_TABLE_VIDEO8:
		tVIDEO8_PRESET_TABLE = ptr;
		break;
	case INPROCVIDE_TABLE_AV_OFFSET:
		av_offset_array = (char *)ptr;
		break;
	case INPROCVIDE_TABLE_SV_OFFSET:
		sv_offset_array =(char *) ptr;
		break;
	default:
		break;
	}

	return TRUE;
}

//Mantis bug number = [common] 0020956
//How : [RTKQC][SYS]Switch channel from no signal to the signal, the screen is little possibility to split and freeze in NTSC
//Why : When change channel, the freq not stable, let we measure error data
//What : We need to check the current input is correct or not, if the result is not reasonable, we will re-measure input signal

//Mantis bug number = [common] 0020924
//How : [PU200][Freeze][Heat run test]ATV CH UP (weak signal)
//Why : When change channel, the freq not stable, let we measure error data
//What : We need to check the current input is correct or not, if the result is not reasonable, we will re-measure input signal

//USER:LewisLee, DATE:2012/07/12
//To prevent ATV off line measure result error
//the value need double check Get_DISP_HORIZONTAL_TOTAL() change DH total value range
#if 0
#define VDC_MEASURE_NTSC_VFREQ_MIN		580
#define VDC_MEASURE_PAL_VFREQ_MAX		520
#define VDC_RE_MEASURE_COUNTER			20
#endif
void drvif_inprocvideo_offline_measure_check(SCALER_DISP_CHANNEL Display)
{

	UINT16	CureentMode = _MODE_576I;
	UINT8	VdcMode = VDC_MODE_AUTO;
	UINT32	counter = 0;


	if(_SRC_TV != Scaler_InputSrcGetMainChType()  && _SRC_CVBS != Scaler_InputSrcGetMainChType() )
	{
		return;
	}


	CureentMode = Scaler_DispGetInputInfoByDisp(Display, SLR_INPUT_MODE_CURR);

	counter = 0;
	while (_FALSE == drvif_video_status_reg(VDC_hv_lock))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_inprocvideo_offline_measure_check, HV no Lock\n");

		Rt_Sleep(10);
		counter++;
		if (counter >20)
		{
			if(_MODE_480I == CureentMode)
			{
				Scaler_ModeSetModeInfo(SLR_MODE_IVFREQ, 600);
				rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC offline measure %d times error, force Vfreq as 60Hz\n", VDC_RE_MEASURE_COUNTER);
			}
			else
			{
				Scaler_ModeSetModeInfo(SLR_MODE_IVFREQ, 500);
				rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC offline measure %d times error, force Vfreq as 50Hz\n", VDC_RE_MEASURE_COUNTER);
			}

			return;

		}

	}


	//if(ZAUTO == fw_tv_getvideomode() || _SRC_CVBS == Scaler_InputSrcGetMainChType() )
	if(ZAUTO == g_ucVideoMode || _SRC_CVBS == Scaler_InputSrcGetMainChType() )
	{
		VdcMode = drvif_module_vdc_ReadMode(VDC_DETECT);
	}
	else// if(ZAUTO != fw_tv_getvideomode())
	{
		VdcMode = drvif_module_vdc_ReadMode(VDC_SET);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"CureentMode=%d, VdcMode=%d, SLR_MODE_IVFREQ=%d\n", CureentMode, VdcMode, Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ));

	switch(VdcMode)
	{
	case VDC_MODE_NTSC:
	case VDC_MODE_NTSC443:
	case VDC_MODE_PAL60:
	case VDC_MODE_PALM:
		if(_MODE_480I == CureentMode)
		{
			if(Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ) < VDC_MEASURE_NTSC_VFREQ_MIN)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC Error Case1 : SLR_MODE_IVFREQ : %x, too small!\n", Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ));
			}
			else
			{
				return;
			}
		}
		else// if(_MODE_576I == CureentMode)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC Error Case2 : CureentMode : %x, VdcMode : %x, is differ\n", CureentMode, VdcMode);
			return;
		}
		break;

	case VDC_MODE_NTSC50:
	case VDC_MODE_PALN:
	case VDC_MODE_PALI:
	case VDC_MODE_SECAM:
	default:
		if(_MODE_480I == CureentMode)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC Error Case3 : CureentMode : %x, VdcMode : %x, is differ\n", CureentMode, VdcMode);
			return;
		}
		else// if(_MODE_576I == CureentMode)
		{
			if(Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ) > VDC_MEASURE_PAL_VFREQ_MAX)
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC Error Case4 : SLR_MODE_IVFREQ : %x, too large!\n", Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ));
			}
			else
			{
				return;
			}
		}
		break;
	}

	//to Prevent VDC Free run, double Protect
	drvif_module_vdc_FreeRun(VDC_FREERUN_DISABLE);

	counter = VDC_RE_MEASURE_COUNTER;

	while(counter--)
	{
		Rt_Sleep(100);

		// FixMe, 20140928
		/*
		if(_MODE_SUCCESS != drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT))
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC offline measure error : %x!", counter);
			continue;
		}
		*/

		if(_MODE_480I == CureentMode)
		{
			if(Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ) >= VDC_MEASURE_NTSC_VFREQ_MIN)
				break;
		}
		else// if(_MODE_576I == CureentMode)
		{
			if(Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ) <= VDC_MEASURE_PAL_VFREQ_MAX)
				break;
		}
	}



	if(0 == counter)
	{
		if(_MODE_480I == CureentMode)
		{

			if (_SRC_CVBS == Scaler_InputSrcGetMainChType())
			{
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_POLARITY, _SYNC_HP_VP);
				Scaler_ModeSetModeInfo(SLR_MODE_IHCOUNT,1717);
				Scaler_ModeSetModeInfo(SLR_MODE_IVCOUNT,262);


				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_INPUT_H_COUNT,Scaler_ModeGetModeInfo(SLR_MODE_IHCOUNT));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_INPUT_V_COUNT,Scaler_ModeGetModeInfo(SLR_MODE_IVCOUNT));

				Scaler_ModeSetModeInfo(SLR_MODE_IHSYNCPULSECOUNT,128);
				Scaler_ModeSetModeInfo(SLR_MODE_IVLEN,Scaler_ModeGetModeInfo(SLR_MODE_IVCOUNT));
				Scaler_ModeSetModeInfo(SLR_MODE_IHFREQ,157);

			}
			Scaler_ModeSetModeInfo(SLR_MODE_IVFREQ,600);

			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC offline measure %d times error, force Vfreq as 60Hz\n", VDC_RE_MEASURE_COUNTER);

		}
		else// if(_MODE_576I == CureentMode)
		{
			if (_SRC_CVBS == Scaler_InputSrcGetMainChType())
			{
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_POLARITY, _SYNC_HP_VP);
				Scaler_ModeSetModeInfo(SLR_MODE_IHCOUNT,1730);
				Scaler_ModeSetModeInfo(SLR_MODE_IVCOUNT,312);


				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_INPUT_H_COUNT,Scaler_ModeGetModeInfo(SLR_MODE_IHCOUNT));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_INPUT_V_COUNT,Scaler_ModeGetModeInfo(SLR_MODE_IVCOUNT));

				Scaler_ModeSetModeInfo(SLR_MODE_IHSYNCPULSECOUNT,127);
				Scaler_ModeSetModeInfo(SLR_MODE_IVLEN,Scaler_ModeGetModeInfo(SLR_MODE_IVCOUNT));
				Scaler_ModeSetModeInfo(SLR_MODE_IHFREQ,156);
			}
			Scaler_ModeSetModeInfo(SLR_MODE_IVFREQ,500);

			rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC offline measure %d times error, force Vfreq as 50Hz\n", VDC_RE_MEASURE_COUNTER);
		}
	}

}

unsigned char drvif_inprocvideo_setup_ex(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo, unsigned char ucVideoMode)
{
	unsigned char ucRet = TRUE;
#if 0
	unsigned short VHalfTotal;


	rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_inprocvideo_setup, ucVideoMode=%x\n", ucVideoMode);

	//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"ucVideoMode=%x\n", ucVideoMode);

	ucVideoMode = ucVideoMode | 0x10;
//	 vdc_mode_detect = ucVideoMode & 0xf;

	if( (ucVideoMode == ZNTSC) ||
			(ucVideoMode == ZNTSC_443)||
			(ucVideoMode ==  ZPAL_60) ||
			(ucVideoMode  ==  ZPAL_M))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "480i\n");
		// 480i NTSC
		a_ptDispInfo->ucMode_Curr = _MODE_480I;
	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD, "576i\n");
		// 576i PAL
		a_ptDispInfo->ucMode_Curr = _MODE_576I;
	}

	down(get_offline_semaphore());
	if(drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT, a_ptDispInfo, a_ptTimingInfo) == _MODE_SUCCESS)
	{
		up(get_offline_semaphore());
		a_ptDispInfo->Polarity = a_ptTimingInfo->Polarity;

		a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount;

		a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal;
		a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal;
		a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq;
		a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq;

		if (_MODE_480I == a_ptDispInfo->ucMode_Curr)
			a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq = 600;
		else
			a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq = 500;


		a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount;
		drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf));


		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
		Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);

		drvif_module_vdc_GetVHalfTotalLen(&VHalfTotal);
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"VDC CHalfTotal=%d\n", VHalfTotal);

		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_mode_offlinemeasure success\n");

		ucRet = TRUE;

	}
	else
	{
		up(get_offline_semaphore());
		rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_mode_offlinemeasure fail\n");
		ucRet = FALSE;
	}
#endif
	return ucRet;
}


unsigned char drvif_inprocvideo_setup_NotMeasure(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo, unsigned char ucModeCur, unsigned char supportColor)
{
	unsigned short VHalfTotal;
	unsigned char ucRet = TRUE;
	//unsigned char ucVideoMode = ZNTSC;
	unsigned char ucVideoMode = ucModeCur;
	rtd_printk(KERN_INFO, TAG_NAME_AVD,"%s line:%d ucVideoMode=%x\n", __func__, __LINE__, ucVideoMode);
	//rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"ucVideoMode=%x\n", ucVideoMode);
 #if 1
	ucVideoMode = ucVideoMode | 0x10;
	//vdc_mode_detect = ucVideoMode & 0xf;

	if( (ucVideoMode == ZNTSC) ||
			(ucVideoMode == ZNTSC_443)||
			(ucVideoMode ==  ZPAL_60) ||
			(ucVideoMode	==	ZPAL_M))
	{
		rtd_printk(KERN_INFO, TAG_NAME_AVD, "[%s(line:%d)]480i\n", __FUNCTION__, __LINE__);
		// 480i NTSC
		a_ptDispInfo->ucMode_Curr = _MODE_480I;
	}
	else
	{
		rtd_printk(KERN_INFO, TAG_NAME_AVD, "[%s(line:%d)]576i\n", __FUNCTION__, __LINE__);
		// 576i PAL
		a_ptDispInfo->ucMode_Curr = _MODE_576I;
	}
#endif

	//a_ptDispInfo->ucMode_Curr = ucModeCur;
	down(get_offline_semaphore());
	// if(drvif_mode_offlinemeasure(_OFFLINE_MS_SRC_VDC, ANALOG_MODE_MEASUREMENT, a_ptDispInfo, a_ptTimingInfo) == _MODE_SUCCESS)
	{
		up(get_offline_semaphore());

		if (_MODE_480I == a_ptDispInfo->ucMode_Curr)
		{
			//ucVideoMode = ZNTSC;
			a_ptDispInfo->Polarity = a_ptTimingInfo->Polarity = 0;
			a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount = 262;
			a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal = 262;
			a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal = 858;
			a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq = 157;
			a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq = 600;
			a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount = 127;
			drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf), supportColor);

			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);

			drvif_module_vdc_GetVHalfTotalLen(&VHalfTotal);
			rtd_printk(KERN_INFO, TAG_NAME_AVD,"VDC CHalfTotal=%d\n", VHalfTotal);

		}
		else
		{
		   	//ucVideoMode = ZPAL_I;
			a_ptTimingInfo->Polarity = 0;
			a_ptTimingInfo->IVTotal = a_ptTimingInfo->IVCount = 302;
			a_ptDispInfo->IVTotal = a_ptTimingInfo->IVTotal = 302;
			a_ptDispInfo->IHTotal = a_ptTimingInfo->IHTotal = 864;
			a_ptDispInfo->IHFreq = a_ptTimingInfo->IHFreq = 156;
			a_ptDispInfo->IVFreq = a_ptTimingInfo->IVFreq = 500;
			a_ptDispInfo->IHSyncPulseCount = a_ptTimingInfo->IHSyncPulseCount = 127;
			drvif_inprocvideo_config_capture(a_ucSrc, a_ptDispInfo->channel, a_ptDispInfo->ucMode_Curr , a_ptDispInfo, a_ptTimingInfo,(ucVideoMode&0xf), supportColor);

			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_INTERLACE,TRUE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_422,FALSE);
			Scaler_SetDispStatusFromSource(a_ptDispInfo, SLR_DISP_10BIT,TRUE);

			drvif_module_vdc_GetVHalfTotalLen(&VHalfTotal);
			rtd_printk(KERN_INFO, TAG_NAME_AVD,"VDC CHalfTotal=%d\n", VHalfTotal);
		}

		rtd_printk(KERN_INFO, TAG_NAME_AVD,"drvif_mode_offlinemeasure success\n");

		ucRet = TRUE;
	}

	/*
	 else
	 {
	  up(get_offline_semaphore());
	  rtd_printk(KERN_DEBUG, TAG_NAME_AVD,"drvif_mode_offlinemeasure fail\n");
	  ucRet = FALSE;
	 }
	 */

	return ucRet;
}






/**
*
* @}
*/
