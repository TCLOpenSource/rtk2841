#ifndef _IFD_magellan_H_
#define _IFD_magellan_H_

//********************************************************************
// PACIFIC_PRIME CONFIG
//********************************************************************
#define CONFIG_Pacific_prime //No define in Sys. now

#ifdef __cplusplus
extern "C" {
#endif

//#include "to_conf.h"
//********************************************************************
//Include file
//********************************************************************
#if 0
#include <rbus/scaler/rbusVDTopReg.h>
#include <rbus/scaler/rbusVDPQReg.h>
#include <rbus/scaler/rbusAudio_IOReg.h>

//#include <rbusIFDReg.h>
#include <rbus/scaler/rbusVDIFDinReg.h>
#include <rbus/scaler/rbusIFD_108Reg.h>
#include <rbus/scaler/rbusIFD_49Reg.h>
#include <rbus/scaler/rbusIFD_27Reg.h>
//#include <rbusIFD_AnalogReg.h>

#include <rbus/scaler/rbusTV_SB1_ANAReg.h>
//#include <rbus_ifdemod_27mreg.h>
//#include <rbus_ifdemod_49mreg.h>
//#include <rbus_ifdemod_108mreg.h>
#endif
//#include <rbus/crt_reg.h>
#include <rbus/sys_reg_reg.h>//sunray
//#include <rbus/scaler/rbusPinmuxReg.h> // For Factory Mode
//#include <rbus/scaler/rbusHDMIReg.h> // For Factory Mode
#include <rbus/adc_reg.h> // For Factory Mode
#include <rbus/dds_pll_reg.h> // For Factory Mode

#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalertimer.h>
#include <tvscalercontrol/frontend/tuner_atv.h>
#include <tvscalercontrol/frontend/tuner_atv_base.h>

//#include <Platform_Lib/TSDControl/audio_atv.h>
#include <tvscalercontrol/vdc/video_factory.h>
#include <tvscalercontrol/vdc/video.h>

//#include <tvscalercontrol/scaler/scalerLib.h>
//#include <Platform_Lib/TSDControl/audio_atv.h>

/*
#include <unistd.h>			// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/

#ifdef CONFIG_USE_TV_FRONTEND_CTRL
       #include "../tvscalercontrol/frontend/tuner/tuner_tv_frontend_control.h"
#endif
#ifdef CONFIG_TUNER_RF_TYPE
	#include "../tvscalercontrol/frontend/tuner/tuner_rf.h"
#elif defined(CONFIG_TUNER_LOWIF_TYPE)
       #ifdef CONFIG_TUNER_NXP_TDA18273
       #include "../tvscalercontrol/frontend/tuner/tuner_nxp_tda18273.h"
	#elif CONFIG_TUNER_NXP_TDA18274
       #include "../tvscalercontrol/frontend/tuner/tuner_nxp_tda18274.h"
	#elif CONFIG_TUNER_NXP_TDA18275
       #include "../tvscalercontrol/frontend/tuner/tuner_nxp_tda18275.h"
	#elif CONFIG_TUNER_NXP_TDA18275A
       #include "../tvscalercontrol/frontend/tuner/tuner_nxp_tda18275a.h"
       #elif defined(CONFIG_TUNER_RAFAEL_R830)
       #include "../tvscalercontrol/frontend/tuner/tuner_rafael_r830.h"
       #elif defined(CONFIG_TUNER_RAFAEL_R828)
       #include "../tvscalercontrol/frontend/tuner/tuner_rafael_r828.h"
       #elif defined(CONFIG_TUNER_RAFAEL_R840)
       #include "../tvscalercontrol/frontend/tuner/tuner_rafael_r840.h"
	 #elif defined(CONFIG_TUNER_MAXIM_MAX3543)
       #include "../tvscalercontrol/frontend/tuner/tuner_maxim_max3543.h"
       #elif defined(CONFIG_TUNER_ENRT_EN4020)
       #include "../tvscalercontrol/frontend/tuner/tuner_entr_en4020.h"
       #elif defined(CONFIG_TUNER_FRESCO_FM2150)
       #include "../tvscalercontrol/frontend/tuner/tuner_fresco_fm2150.h"
	 #elif defined(CONFIG_TUNER_SILICONLABS_SI2151)
       #include "../tvscalercontrol/frontend/tuner/tuner_siliconlabs_si2151.h"
	  #elif defined(CONFIG_TUNER_SILICONLABS_SI2156)
       #include "../tvscalercontrol/frontend/tuner/tuner_siliconlabs_si2156.h"
	#elif defined(CONFIG_TUNER_SILICONLABS_SI2157)
       #include "../tvscalercontrol/frontend/tuner/tuner_siliconlabs_si2157.h"
	#elif defined(CONFIG_TUNER_SILICONLABS_SI2158)
       #include "../tvscalercontrol/frontend/tuner/tuner_siliconlabs_si2158.h"
	#elif defined(CONFIG_TUNER_SILICONLABS_SI2156_ATV_DTV)
       #include "../tvscalercontrol/frontend/tuner/tuner_siliconlabs_si2156_atv_dtv.h"
	#elif defined(CONFIG_TUNER_MAXLINEAR_MXL601)
       #include "../tvscalercontrol/frontend/tuner/tuner_maxlinear_mxl601.h"
	#elif defined(CONFIG_TUNER_MAXLINEAR_MXL661)
       #include "../tvscalercontrol/frontend/tuner/tuner_maxlinear_mxl661.h"
	#elif defined(CONFIG_TUNER_FITICOMM_FC0014)
       #include "../tvscalercontrol/frontend/tuner/tuner_fiticomm_fc0014.h"
	#elif defined(CONFIG_TUNER_SONY_SUTRE221ZN)
       #include "../tvscalercontrol/frontend/tuner/tuner_sony_sutre221zn.h"
	#elif defined(CONFIG_TUNER_SONY_SUTRE231)
       #include "../tvscalercontrol/frontend/tuner/tuner_sony_sutre231.h"
 	 #elif defined(CONFIG_TUNER_SONY_SUTRA231TN)
       #include "../tvscalercontrol/frontend/tuner/tuner_sony_sutra231tn.h"
	#elif defined(CONFIG_TUNER_SONY_SUTRE232TN)
       #include "../tvscalercontrol/frontend/tuner/tuner_sony_sutre232tn.h"
	#elif defined(CONFIG_TUNER_SONY_SUTRC234)
       #include "../tvscalercontrol/frontend/tuner/tuner_sony_sutrc234.h"
	#endif
#endif


//********************************************************************
//System Function Define
//********************************************************************
#if 0
#ifndef UINT8
typedef  unsigned char UINT8;
#endif
#ifndef UINT16
typedef  unsigned short UINT16;
#endif
#ifndef UINT32
typedef  unsigned int UINT32;
#endif
#ifndef UINT64
typedef unsigned long long      	UINT64;
#endif
#endif

#ifndef CONFIG_Tuner_Max_NUMBER
#ifdef AFEIF_RTKATV_TUNER_MAX
#define CONFIG_Tuner_Max_NUMBER AFEIF_RTKATV_TUNER_MAX
#else
#define CONFIG_Tuner_Max_NUMBER 1
#endif
#endif

#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)

#ifndef CONFIG_Tuner_Max_NUMBER
#define CONFIG_Tuner_Max_NUMBER 1
#endif
#ifndef _Tuner_MAX_NO
#define _Tuner_MAX_NO CONFIG_Tuner_Max_NUMBER
#endif
#define IFD_CODE
#define IFD_XDATA
#define _TRUE 1
#define _FALSE 0
#define _SUCCESS 1
#define I2C_MASTER0		0
#define I2C_MASTER1		1
#define I2C_MASTER I2C_MASTER1
#define ROS_ENTER_CRITICAL()
#define ROS_EXIT_CRITICAL()
#define ScalerTimer_DelayXms(ms) Rt_Sleep(ms)
//********************************************************************
//CONFIG definition
//********************************************************************
#undef CONFIG_ATV_IFD_VERIFY
//********************************************************************
//Debug Msg definition
//********************************************************************
typedef enum {
	IFD_MSG_NONE=_ZERO,
	IFD_MSG_TUNER=_BIT0,
	IFD_MSG_SCANCH=_BIT1,
	IFD_MSG_SETCH=_BIT2,
	IFD_MSG_AUTO=_BIT3,
	IFD_MSG_AFC=_BIT4,
	IFD_MSG_ADAPTIVE_TARGET=_BIT5,
	IFD_MSG_CR_STATE=_BIT6,
	IFD_MSG_STRONG_SIGNAL=_BIT7,
	IFD_MSG_DUMP_REG=_BIT8,
	IFD_MSG_AGC_VAR=_BIT9,
	IFD_MSG_INIT=_BIT10,
	IFD_MSG_OTHERS=_BIT11,
	IFD_MSG_INFO=_BIT15,
	IFD_MSG_ALL_MSG=0xFFFF,
}IFD_MSG_LEVEL;

extern IFD_MSG_LEVEL  g_ifd_msg_level;

#define IFD_CALLER(ifd_level)  \
{                                                                                      \
    if((g_ifd_msg_level&ifd_level)!=0)                            \
    {                                                                                  \
    	 asm("or $5,$31,$0");                                                 \
    	 printk( "$$$$$$IFD API called at %x --- ");                 \
    }                                                                                  \
}
#define IFD_DEBUG_MSG(ifd_level,string,args...) \
{									\
	if(ifd_level==IFD_MSG_INFO)	\
	{								\
			printk("\n[IFD_DEBUG][INFO]");				\
			printk(string, ##args);				\
	}\
	if(((g_ifd_msg_level&ifd_level)!=0)) {	\
		if(ifd_level==IFD_MSG_TUNER)	\
		{								\
			printk("\n[IFD_DEBUG][TUNER]");				\
		}								\
		if(ifd_level==IFD_MSG_SCANCH)	\
		{								\
			printk("\n[IFD_DEBUG][SCAN_CH]");				\
		}								\
		if(ifd_level==IFD_MSG_SETCH)	\
		{								\
			printk("\n[IFD_DEBUG][SET_CH]");				\
		}								\
		if(ifd_level==IFD_MSG_AUTO)	\
		{								\
			printk("\n[IFD_DEBUG][SET_CH]");				\
		}								\
		if(ifd_level==IFD_MSG_AFC)	\
		{								\
			printk("\n[IFD_DEBUG][AFC]");				\
		}								\
		if(ifd_level==IFD_MSG_ADAPTIVE_TARGET)	\
		{								\
			printk("\n[IFD_DEBUG][ADAPTIVE_TARGET]");				\
		}								\
		if(ifd_level==IFD_MSG_CR_STATE)	\
		{								\
			printk("\n[IFD_DEBUG][CR_STATE]");				\
		}								\
		if(ifd_level==IFD_MSG_STRONG_SIGNAL)	\
		{								\
			printk("\n[IFD_DEBUG][STRONG_SIGNAL]");				\
		}								\
		if(ifd_level==IFD_MSG_DUMP_REG)	\
		{								\
			printk("\n[IFD_DEBUG][DUMP_REG]");				\
		}								\
		if(ifd_level==IFD_MSG_AGC_VAR)	\
		{								\
			printk("\n[IFD_DEBUG][AGC_VAR]");				\
		}								\
		if(ifd_level==IFD_MSG_INIT)	\
		{								\
			printk("\n[IFD_DEBUG][INIT]");				\
		}								\
		if(ifd_level==IFD_MSG_OTHERS)	\
		{								\
			printk("\n[IFD_DEBUG][OTHERS]");				\
		}								\
		printk(string, ##args);				\
	}\
}

//********************************************************************
//Version ID definition
//********************************************************************
#define GET_IFD_VERSION() (rtd_inl(0xb8060000)&0xffff)
typedef enum _IFD_CHIP_VERSION {
	IFD_CHIP_VERSION_VER_A=0x0,
	IFD_CHIP_VERSION_VER_B,
	IFD_CHIP_VERSION_VER_C,
} IFD_CHIP_VERSION;



//********************************************************************
//Timer Event definition
//********************************************************************
#define next_time_dont_check_variance g_next_time_dont_check_variance
#define ifd_log_reg_active drv_ifd_periodic_log_reg
#define ifd_log_reg_cancel SLRTIMER_IFD_LOGGER
#define IFD_ScalerTimer_CancelTimerEvent(event) ScalerTimer_CancelTimerEvent(event)
#define IFD_ReactiveTimerEvent(flag, ms, event) ScalerTimer_ReactiveTimerEvent(flag, ms, (SLRTIMER_CALLBACK)event)
//********************************************************************
//Other definition
//********************************************************************
extern UINT16  group_delay_table1[];
extern UINT16  group_delay_table2[];
extern UINT16  group_delay_table3[];
extern UINT16  group_delay_table4[];
extern UINT16  group_delay_table5[];

typedef enum _IFD_DEBUG_MODE_CLK_CONFIG {
	CLK54=0,
	CLK49,
	CLK108,
} IFD_DEBUG_MODE_CLK_CONFIG;

typedef enum _IFD_DEBUG_MODE_CONFIG { //Please sync with ifd_factorymode.cpp
	ADC_OUT=0,
	FIFO_OUT,
	DGAIN_OUT,
	DEMOD_OUT,
	CVBS_OUT,
	AGC_RF,
	AGC_IF,
	AGC_LOOP1_LPF_OUT,
	AGC_LOOP1_MAX_OUT,
	AGC_LOOP1_DGAIN,
	AGC_LOOP1_DIFF_ERR,
	AGC_LOOP1_ERR0,
	AGC_LOOP1_PEAK_ERR,
	AGC_LOOP1_PEAK,
	AGC_LOOP1_LPF_OUT_DGAINED,
	AGC_LOOP2_DGAIN,
	AGC_LOOP2_DIFF_ERR,
	AGC_LOOP2_PEAK_ERR,
	AGC_LOOP2_PEAK,
	CR_COS,
	CR_LPF_OUT,
	CR_PHASE_ERROR,
	CR_IN,
	SIF_OUT,
	IFD_RESERVE_1,
	IFD_RESERVE_2,
	IFD_DMA_ALL,
} IFD_DEBUG_MODE_CONFIG;
/*=============================================================*/
/**
 * drvif_ifd_dma_data
 *
 *
 * @param <debug_mode>
 * @return { void }
 */
void drvif_ifd_dma_data(IFD_DEBUG_MODE_CONFIG debug_mode);


//=================================================================
//IFD local driver
//=================================================================
#include <tvscalercontrol/frontend/ifd_rtd296x_analog.h>
#include <tvscalercontrol/frontend/ifd_rtd296x_cr.h>
#include <tvscalercontrol/frontend/ifd_rtd296x_agc.h>
#include <tvscalercontrol/frontend/ifd_rtd296x_audio.h>
#include <tvscalercontrol/frontend/ifd_rtd296x_video.h>
#include <tvscalercontrol/vdac/vdac.h>
#ifdef CONFIG_ATV_IFD_VERIFY
#include <tvscalercontrol/frontend/ifd_rtd296x_verify.h>
#endif

void drv_ifd_tuner_data_init(void);
void drv_ifd_tuner_BuildTuner(void);
void drv_ifd_user_data_init(void);
void drv_ifd_active_tuner_assign(UINT8 tunerID);
void drv_ifd_tuner_select(UINT8 tunerNo);
void drv_ifd_dma_data_sel_en(bool dma_data_sel_en);
void drv_ifd_debug_mode(IFD_DEBUG_MODE_CLK_CONFIG clk,UINT8 debug_mode);
UINT8 drv_ifd_tuner_table_search(UINT8 tunerID);


#ifdef __cplusplus
}
#endif

#endif // _IFD_PACIFICP_H_







