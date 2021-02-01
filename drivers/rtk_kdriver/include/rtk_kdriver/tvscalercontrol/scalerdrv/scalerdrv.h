/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler clock related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	clock
 */

/**
 * @addtogroup clock
 * @{
 */

#ifndef _SCALER_H_
#define _SCALER_H_

#ifdef __cplusplus
extern "C" {
#endif


//#include <Platform_Lib/Utils/RtSystem.h>
//#include <rbusVgip2Reg.h>
#include <scalercommon/scalerDrvCommon.h> /* SCALERIOC_GETVOINFO */
#include <scalercommon/scalerCommon.h>    /* StructDisplayInfo */


#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#include <tvscalercontrol/scaler/scalervideo.h>
#endif

/*============================ Module dependency  ===========================*/
//#include <auto_conf.h>
//#include <rtd_types.h>
//#include <rbusScaledownReg.h>
//#include <rbusPpOverlayReg.h>//peggy mark first
/*===================================  Types ================================*/
/*================================== Variables ==============================*/
#define CONFIG_YPBPR_AUTO_COLOR_TYPE2	1
#define CONFIG_VGA_SUPPORT_ABL	1
#ifdef ENABLE_VGA_POSITION_SAVE
#define CONFIG_VGA_POSITION_SAVE	1
#endif
//#define AUTO_SOY_ADAPTIVE_FLOW 1
#define CONFIG_ADC_DMA 1
#define DUMP_VSYNC 1
#define CONFIG_3D_ASPECT_RATIO 1
#define  CONFIG_3D_ASPECT_RATIO_FRAMESEQ 1
#define  CONFIG_3D_OVERSCAN_FRAMESEQ 1
//#define CONFIG_3D_OVERSCAN_ENABLE 1
#define CONFIG_DCLK_CHECK 0
#define CONFIG_APLL_PROTECT 1
#ifndef CONFIG_HW_SUPPORT_MEMC
#define CONFIG_MEMC_BYPASS 1
#define CONFIG_FRAMERATE_DEBUG_IN_VGIPISR 1
#endif

#define CONFIG_HDR10_ENABLE
#define ENABLE_3_BUFFER_DELAY_MODE 1
#define CONFIG_ENABLE_FRC_TO_FRAMESYNC_BY_HW 1
#define CONFIG_MDOMAIN_RESERVED_MEMORY 1
#define CONFIG_ORBIT_PIXEL_SHIFT_ALGO 1
//#define CONFIG_SCALER_BRING_UP 1
#ifndef CONFIG_SCALER_BRING_UP
#define CONFIG_FORCE_RUN_I3DDMA   //not vo source force go i3ddma flow
#endif

#define	CONFIG_SDNR_CROP		1
#ifdef CONFIG_SDNR_CROP
#define	CONFIG_VGIP_DIGITAL_MODE //enable digital mode
#endif
//#define CONFIG_I2RND_ENABLE //enable i2rnd function
//#define CONFIG_PST_ENABLE //enable pst function
#define CONFIG_I2RND_B05_ENABLE //enable i2rnd_b05 function
#define CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
//#define CONFIG_DUMP_REGISTER

#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
#define CONFIG_ALL_SOURCE_DATA_FS
#endif

#define CONFIG_SMOOTH_TOOGLE_AT_VO_FREEZE 1
//#define USE_FORCEBG_TASK//If define, use forcebg task flow
// for VB1 to HDMI adaptor
//#define ENABLE_VBY1_TO_HDMI_4K2K_DATA_FS
/*================================ Definitions ==============================*/
//#define CONFIG_HDR_SDR_SEAMLESS//If define to support HDR to SDR SEAMLESS

//#define Scaler_ClearLineBufferStatus() IoReg_ClearBits(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR, _BIT0 | _BIT1 | _BIT2)
//#define FORCE_BYPASS_DI_RTNR//If define will force bypass DI and RTNR. Only use for interlace timing
#define _OSD_DATA_IN_INTERNAL	0
#define _OSD_DATA_IN_FLASH		1
#define _OSD_DATA_IN_CODE		2

#define _EVENT_UNDERFLOW 		0x20
#define _EVENT_OVERFLOW  		0x40s

#define _I_DOMAIN				0x00//forster modified 041004
#define _D_DOMAIN				0x01

//#define _H_POSITION_MOVE_TOLERANCE      0x50 // +- 80 pixels
#define _H_POSITION_MOVE_TOLERANCE      0xa0 // +- 160 pixels
#define _V_POSITION_MOVE_TOLERANCE      0x32 // 50 lines

//for hdmi smooth toggle portch adjustment fo 70Hz
#define _PROTECT_VDELAY_70Hz 8

/*
-6 : RGB2YUV
-32 : M-cap
-2 : tolerance
*/
#define VGIP_H_PORCH_RGB2YUV 6
#define VGIP_H_PORCH_MCAP 32
#define VGIP_H_PORCH_TOLERANCE 2
#define VGIP_H_PORCH_MARGIN (VGIP_H_PORCH_RGB2YUV + VGIP_H_PORCH_MCAP + VGIP_H_PORCH_TOLERANCE) // h-porch num = h-total - pic width - porch margin (from DIC's comment)

//VGA position adjust
#define MIN_H_BACK_PORCH 3 //minimal porch number
#define FIX_VGIP_V_START 5//fix vgip v start using delay to adjust position
#define FIX_VGIP_H_DELAY 50//fix vgip h delay using delay to adjust position


//	#define _EVENT_IVS1  			 0x01
#define WaitFor_IVS1()			fwif_scaler_wait_for_event(VGIP_VGIP_CHN1_STATUS_reg, _BIT26)

//	#define _EVENT_IEN_START1		 0x02
#define WaitFor_IEN_START1()	fwif_scaler_wait_for_event(VGIP_VGIP_CHN1_STATUS_reg, _BIT24)

//#define _EVENT_IEN_STOP1 		 0x04
#define WaitFor_IEN_STOP1()		fwif_scaler_wait_for_event(VGIP_VGIP_CHN1_STATUS_reg, _BIT25)

//#define _EVENT_IVS2 		 	0x08
#define WaitFor_IVS2()			fwif_scaler_wait_for_event(SUB_VGIP_VGIP_CHN2_STATUS_reg, _BIT26)

//#define _EVENT_IEN_START2 		 0x10
#define WaitFor_IEN_START2()	fwif_scaler_wait_for_event(SUB_VGIP_VGIP_CHN2_STATUS_reg, _BIT24)

//#define _EVENT_IEN_STOP2 		 0x20
#define WaitFor_IEN_STOP2()		fwif_scaler_wait_for_event(SUB_VGIP_VGIP_CHN2_STATUS_reg, _BIT25)

//#define _EVENT_DVS   				0x10
//#define WaitFor_DVS()			// fwif_scaler_wait_for_event(()

//#define _EVENT_DEN_START 			0x20
//#define WaitFor_DEN_START()		// fwif_scaler_wait_for_event(()
#define WaitFor_DEN_START()		fwif_scaler_wait_for_event(PPOVERLAY_DTG_pending_status_reg, _BIT1)	//hsliao 20090518

//#define _EVENT_DEN_STOP  			0x40
//#define WaitFor_DEN_STOP()		fwif_scaler_wait_for_event(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT10)	//jerry1207a
								//WaitFor_EN_STOP_MAIN()

// #define WaitFor_OEN_START_MAIN  	0x40
#define WaitFor_EN_START_MAIN() fwif_scaler_wait_for_event(PPOVERLAY_DTG_pending_status_reg, _BIT1)

// #define _EVENT_OEN_STOP_MAIN 		0x08
#define WaitFor_EN_STOP_MAIN()	fwif_scaler_wait_for_event(PPOVERLAY_DTG_pending_status_reg, _BIT0)

// #define _EVENT_OEN_START_SUB 		0x01
#define WaitFor_EN_START_SUB()	fwif_scaler_wait_for_event(PPOVERLAY_DTG_pending_status_reg, _BIT3)

//#define _EVENT_OEN_STOP_SUB  		0x02
#define WaitFor_EN_STOP_SUB()	fwif_scaler_wait_for_event(PPOVERLAY_DTG_pending_status_reg, _BIT2)

#define ZOOM_WaitFor_IEN_STOP1()		fwif_scaler_wait_for_event1(VGIP_VGIP_CHN1_STATUS_reg, _BIT25)

#define WaitFor_IVS1_Done()		fwif_scaler_wait_for_event_done(VGIP_VGIP_CHN1_STATUS_reg, _BIT26)

#define WaitFor_IVS2_Done()			fwif_scaler_wait_for_event_done(SUB_VGIP_VGIP_CHN2_STATUS_reg, _BIT26)

#define WaitFor_EN_STOP_MAIN_Done()	fwif_scaler_wait_for_event_done(PPOVERLAY_DTG_pending_status_reg, _BIT0)

#define WaitFor_DEN_STOP_Done()		fwif_scaler_wait_for_event_done(PPOVERLAY_DTG_pending_status_reg, _BIT0)

#if defined (SELFAWB)
#define CONFIG_SELF_AWB_ENABLE  //leochen add
#endif

//#define THERMAL_PHASE_COMPENSATION
//#define THERMAL_PHASE_COMPENSATION_THRESHOLD	5
typedef struct _StructSrcRect{
	unsigned short srcx;     		//x
	unsigned short srcy;     		//y
	unsigned short src_wid;    	//width
	unsigned short src_height;	//height
}StructSrcRect;

typedef struct _StructRect{
	int x;     		//x
	int y;     		//y
	int width;    	//width
	int height;	//height
}StructRect;

typedef struct _StructDstRect{
	unsigned short dst_wid;    	//width
	unsigned short dst_height;	//height
}StructDstRect;

typedef struct _StructJPEGDisplayInfo{
	unsigned short	IVTotal;		///! input vertical total
	unsigned short	IHFreq;			///! input horizontal frequency
	unsigned int	MemAddr;		///! display memory address
	unsigned short	MemWid;		///! display memory width
	unsigned short	MemLen;		///! display memory length
	unsigned short	DispHSta;		///! display window horizental start
	unsigned short	DispVSta;		///! display window vertical start
	unsigned short	DispWid;			///! display widnow width
	unsigned short	DispLen;			///! display window length
}StructJPEGDisplayInfo;

typedef enum{
	SLR_2DCVT3D_MODE_DISABLE = 0,
	SLR_2DCVT3D_MODE_SG,
	SLR_2DCVT3D_FRAME_RATE_DOUBLE_MODE_PR,
} SLR_2DCVT3D_MODE;


typedef enum{
	SLR_IDMA_MODE_DISABLE = 0,
	SLR_IDMA_MODE_3D 		= 1,
	SLR_IDMA_MODE_3Dto2D = 2
} SLR_IDMA_MODE;


typedef enum{
	SLR_SIZE_TYPE_WID = 0,
	SLR_SIZE_TYPE_LEN,
} SLR_SIZE_TYPE;

#define CONTENT_MAX  20
typedef struct VSC_DRIVER_STRING{
	char timing_index_str[CONTENT_MAX];
	char rtnr_mode_str[CONTENT_MAX];
	char od_en_str[CONTENT_MAX];
	char dexc_en_str[CONTENT_MAX];
	char free_run_str[CONTENT_MAX];
	char ve_comp_str[CONTENT_MAX];
	char dipqc_bit_str[CONTENT_MAX];
	char ma_snr_str[CONTENT_MAX];
}VSC_DRIVER_STRING;

typedef struct VSC_DRIVER_RESOURCE{
	unsigned int magic_num;
	bool valid;
	VSC_DRIVER_STRING vsc_driver_string[TIMING_INVAILD];
}VSC_DRIVER_RESOURCE ;

/*================================== Function ===============================*/
/*============================================================================*/

void Set_3d_type(unsigned char type);
unsigned char Get_3d_type(void);

/**
 * drvif_scaler_ddomain_switch_irq
 * switch (enable/disable) D-Domain IRQ
 *
 * @param <enable>	{ enable or disable D-Domain IRQ }
 * @return 			{ void }
 *
 */
void drvif_scaler_ddomain_switch_irq(unsigned char enable);

void drvif_scaler_ddomain_DTG_line_compare_irq(unsigned char enable, unsigned char vlc_mode, unsigned int vlc_src_sel, unsigned int dtg_vln);

/*============================================================================*/
/**
 * drvif_scaler_poweron_init
 * Initial settings for scaler from power saving mode or power-off mode.
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void drvif_scaler_poweron_init(void);


/**
 * fwif_scaler_wait_for_event
 * Wait for evnet specifed status
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
//unsigned char fwif_scaler_wait_for_event(unsigned char domain, unsigned char event);
unsigned char fwif_scaler_wait_for_event(unsigned int addr, unsigned int event);
unsigned char fwif_scaler_wait_for_event1(unsigned int addr, unsigned int event);
unsigned char fwif_scaler_wait_for_event_done(unsigned int addr,
					unsigned int event);

/*============================================================================*/
/**
 * Reset the scaler.
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
//void Scaler_EnableDisplayOutput(void);

/*============================================================================*/
/**
 * drvif_scaler_disable_display_output
 * Reset the scaler.
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void drvif_scaler_disable_display_output(void);

/*============================================================================*/
/**
 * Reset the scaler.
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
//void Scaler_WriteInitialTable(void);

/*============================================================================*/
/**
 * Reset the scaler.
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void fw_scaler_set_vgip_capture(unsigned char display);
void scaler_set_vgip_capture_shift(unsigned char display, char shiftx, char shifty);
/*============================================================================*/
/**
 * ScalerSetScaleUpInSize
 * Enable/disable vertical or horizontal scaling up,
 * including main and sub display. It is to set scale control register.
 * @param <info> {info structure}
 * @nWid
 * @nLen
 * @return { none }
 *
 */
void Scaler_SetScaleUpInputSize(unsigned int nWid, unsigned int nLen);
void Scaler_IrqInitial(void);
void	DeintelacerControl(void);
void drv_scaler_adjust_ihs_delay(unsigned char display, unsigned short usIHSDelay);
void fw_scaler_update_mode_para(void);
void fw_scaler_enable_fs_wdg(unsigned char display, unsigned char enable);
void fw_scaler_enable_measure_wdg(unsigned char channel, unsigned char enable);
void fw_scaler_adc_nolock_wdg_ctrl(unsigned char display, unsigned char enable);
unsigned char  fwif_scaler_decide_display_cut4line(unsigned char disp);

unsigned char drvif_scaler_decide_idmaVgip_syncTo_mainVgip(void);

//void Scaler_OnMeasureIRQEnable(unsigned char channel, unsigned char bEnable);
//void drvif_scaler_vgip_irq_init(void);	// hsliao 20081231, move to linux driver
//void Scaler_OnMeasure1IRQInit(void);
//void Scaler_OnMeasure2IRQInit(void);
void fw_scaler_double_buffer_maskl(unsigned char display,unsigned int addr,  unsigned int andmask, unsigned int ormask);
void fw_scaler_double_buffer_outl(unsigned char display,unsigned int addr,  unsigned int val);
void fw_scaler_dtg_double_buffer_enable(unsigned char bEnable);
void fw_scaler_dtg_double_buffer_apply(void);

enum{
	VGIP_SRC_TMDS = 0,	//HDMI
	VGIP_SRC_ADC,		//ADC/YPbPr/Pattern Gen
	VGIP_SRC_ATV,		//From Dragon
	VGIP_SRC_DISPD,	// DispD for Sub/DMA VGIP only
	VGIP_SRC_VODMA1,	//SENSIO/VODMA1 for Main VGIP, VODMA2 for Sub-VGIP, VODMA for DMA VGIP
	VGIP_SRC_VODMA2
};

enum{
	VGIP_MODE_ANALOG = 0,
	VGIP_MODE_DIGITAL
};

enum{
	SUB_VGIP_SRC_MAINUZD = 0,
	SUB_VGIP_SRC_AVD,
};

void fw_scaler_set_vgip(unsigned char channel, unsigned char src, unsigned char mode);

enum{
	DISPLAY_MODE_FRC = 0,
	DISPLAY_MODE_FRAME_SYNC,
	DISPLAY_MODE_NEW_FLL_MODE
};

typedef struct _RPC_SHARE_MEM_INFO {
	unsigned int			ulOffset;			//Memory offset
	unsigned int			ulSize;				//Memory size
} RPC_SHARE_MEM_INFO;

typedef unsigned short (*GET_INPUT_WID_F)(unsigned short);

unsigned char drvif_scaler_get_display_mode(void);
void drvif_scaler_set_display_mode(unsigned char timing_mode);
void drvif_scaler_set_display_modeByDisp(unsigned char timing_mode,unsigned char _channel);
void drvif_scaler_set_Disp_line_4x(unsigned char ucEnable);
void drvif_scaler_set_display_mode_frc2fsync_by_hw(unsigned char ucReset);
void drvif_scaler_set_display_mode_frc2fsync_check_lock(void);
void drvif_scaler_set_display_mode_frc2fsync_by_hw_wait_lock(void);
void drvif_scaler_set_display_mode_frc2fsync_by_hw_speedup(void);
void drvif_scaler_set_display_mode_to_framesync_by_hw(void);
//void fwif_osd_load_bitmap(unsigned char *array, unsigned int addr, int len, unsigned char ucFrom);
//void fwif_osd_load_bitmap_256_palette(unsigned char *array, unsigned char ucFrom);
void drvif_scaler_check_vgip_data_dclk(unsigned char channel);
void fw_scaler_set_sample(unsigned char channel, unsigned char enable);
void fw_scaler_set_vgip_3d_mode(unsigned char channel, unsigned char enable);
void fw_scaler_set_Main2_vgip_3d_mode(unsigned char enable);
unsigned char fw_scaler_get_M_capture_LR_ctrl_by_HW(void);
void fw_scaler_set_vgip_frame_packing_3d_mode(unsigned char enable);
//void Scaler_VStartIRQInit(void);
void drvif_scaler_vactive_sta_irq(unsigned char enable, unsigned char channel);
void drvif_scaler_vactive_end_irq(unsigned char enable, unsigned char channel);
void fw_scaler_cal_scale_down_size(void);
unsigned short apsys_get_input_width(unsigned short ori_width);

//unsigned char drvif_scaler_get_AutoMaEnableStatus(void);
void drvif_scaler_WriteTable(unsigned int* array);
unsigned char drvif_scaler_regGetInputWidCallBck(GET_INPUT_WID_F function);
unsigned char  fwif_scaler_decide_display_cut4line(unsigned char disp);
void fw_scaler_enable_measure_subwdg_magicpic(void);
void fw_scaler_disable_measure_subwdg_magicpic(void);
void scaler_OSD_md_domain_update(unsigned int addr);

unsigned char drvif_scaler3d_decide_3d_PR_enter_3DDMA(void);
unsigned char drvif_scaler3d_decide_2d_cvt_3d_PR_enter_3DDMA(void);
unsigned char drvif_scaler3d_decide_HDMI_framePacking_interlaced_status(void);
//unsigned char drvif_scaler3d_decide_HDMI_framePacking_auto_status(void);
unsigned char drvif_scaler3d_decide_HDMI_framePacking_auto_status(SCALER_DISP_CHANNEL channel);
unsigned char drvif_scaler3d_decide_3d_PR_enable_IDMA(void);
unsigned char drvif_scaler3d_decide_3d_SG_Disable_IDMA(unsigned char uc3dType);
unsigned char drvif_scaler3d_decide_3d_SG_Disable_IDMA_suport_FP_interlace(void);
unsigned char drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain(void);
unsigned char drvif_scaler3d_decide_vo_3d_output_frame_seq(void);
unsigned char drvif_scaler3d_decide_dispM_3d_output_frame_seq(void);
unsigned char drvif_scaler3d_decide_PR_output_120Hz(void);
unsigned char drvif_scaelr3d_decide_1080i_TB_enter_2ddi(void);
unsigned char drvif_scaelr3d_decide_is_3D_display_mode(void);
unsigned char drvif_scaelr3d_decide_is_3Dto2D_display_mode(void);

SLR_IDMA_MODE drvif_scaler3d_get_IDMA3dMode(void);
unsigned char drvif_scaler3d_decide_3d_SG_data_FRC(void);


unsigned char drvif_scaler3d_decide_iv2dv_delay_line(void);
//SLR_2DCVT3D_MODE drvif_scaler3d_decide_2d_cvt_3d_mode(void);
unsigned char drvif_scaler3d_decide_isPR3dMode(void);
unsigned char drvif_scaler3d_decide_IsFRCMode(void);

int drvif_scaler3d_init_vo_3d_mode(unsigned char uc3dMode);
void drvif_scaler3d_set_voDropLine_for_4k2k_3d(unsigned char enable);
unsigned int drvif_scaler3d_get_vo_3dDropLineMode(void);
int drvif_scaler3d_set_panel_info(void);
void drvif_scaler_voFrameRateControl_init(void);
void drvif_scaler_voFrameRateControl_force(unsigned char iEnable,unsigned int theframerate);


unsigned char drvif_scaler4k2k_get_forceDisplayOutput_60Hz(void);
int drvif_scaler_voFrameRateControl_set_bwSavingMode(DISP_MODE flag_3d, unsigned char bwSavingEnable);
int drvif_scaler_voForceFrameRateControl_by_TvBox(unsigned int forceFrameRate, unsigned char bEnable);
#ifdef CONFIG_4K2K_VIDEO_EMEMC
void drvif_scalerEMEMC(bool iEnable);
#endif
int drvif_scaler3d_voFrameRateControl_set_forceMaxFrameRate(DISP_MODE flag_3d, unsigned char flag_forceEnable, unsigned char boolUpdate);
void drivf_scaler_reset_freerun(void);
void drivf_scaler_reset_freerun_60Hz(void);

// 3D PR Video PQ Improvement
unsigned char drvif_scaler3d_decide_3d_PR_PQ_improve(void);
void fw_scaler_set_3D_depth(void);
unsigned int get_scaler_memory_map_addr(void);
void WaitFor_3DTG_Period(unsigned int StartOffset, unsigned int EndOffset);
void WaitFor_DEN_STOP(void);
void WaitFor_DEN_STOP_Period(unsigned int PorchStartOffset, unsigned int PorchEndOffset);
void WaitFor_DEN_STOP_Period2(unsigned int PorchStartOffset, unsigned int PorchEndOffset);
//unsigned char Rt_Sleep(unsigned int  milliSec);
unsigned int Scaler_InitRPCShareMem(void);
void Scaler_FreeRPCShareMem(void);
long Scaler_SendRPC(unsigned int a_ulCmd, unsigned long a_ulValue, unsigned char a_ucValueOnly);

unsigned int Scaler_GetShareMemVirAddr(unsigned int a_ulCmd);

unsigned int Scaler_ChangeUINT32Endian(unsigned int a_ulLittleIndian);
unsigned short Scaler_ChangeUINT16Endian(unsigned short a_usLittleEndian);

unsigned char modestate_decide_double_dvs_enable(void);
unsigned char modestate_check_input_special_framerate(void);
unsigned char modestate_get_pr3d_in_fp_3d_mode(void);
unsigned char modestate_I3DDMA_check_idma_mode_enable(unsigned char cur3dType);
unsigned char modestate_get_vo3d_in_framePacking_FRC_mode(void);

//unsigned char Scaler_Get3DMode(void);
unsigned char Scaler_Get3DMode(SCALER_DISP_CHANNEL display);
//void Scaler_Set3DMode_Attr(unsigned char message);
//void Scaler_Set3DMode_Attr(SCALER_DISP_CHANNEL display, unsigned char message);
//unsigned char Scaler_Set3DMode(unsigned char message, bool muteAudio);
//unsigned char Scaler_Set3DMode(SCALER_DISP_CHANNEL display, unsigned char message, bool muteAudio);
unsigned char Scaler_Set3DLRSwap(unsigned char message);
unsigned char modestate_I3DDMA_get_In3dMode(void);
unsigned char Scaler_Get3D_IsFramePacking(void);
int Scaler_Set3D_VoAutoDetect_Enable(unsigned char enable);
unsigned char Scaler_Get3D_VoAutoDetectMode(void);
//void check_vo3d_detect_result(void);
void check_vo3d_detect_result(SCALER_DISP_CHANNEL display);
VO_3D_MODE_TYPE modestate_get_vo3d_detect_result(void);
//void modestate_HDMI_3D_format_auto_detection(void);
void modestate_HDMI_3D_format_auto_detection(SCALER_DISP_CHANNEL channel);
long Scaler_Kernel_SendRPC_to_Video(unsigned int rpc_cmd, unsigned int param_1);

void modestate_decide3D_for_vdc(void);
//#define CONFIG_ENABLE_FRC_TO_FRAMESYNC_BY_HW 1
void Scaler_Set_FRC_Open_Fix_Lastline_2(unsigned char ucEnable);
unsigned char Scaler_Get_FRC_Open_Fix_Lastline_2(void);
unsigned char Scaler_EnterFRC_LastLine_Condition(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_FreeRun_To_FrameSync_By_HW_Enable(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_LineBufferMode_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_FreeRun_To_FrameSync_By_HW_LineBufferMode_Enable(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_LineBufferMode_SpeedUp_TimeOut(unsigned int Value);
unsigned int Scaler_Get_FreeRun_To_FrameSync_By_HW_LineBufferMode_SpeedUp_TimeOut(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp(unsigned char ucEnable);
unsigned char Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_TimeOut(unsigned int Value);
unsigned int Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_TimeOut(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_Porch(unsigned char Value);
unsigned char Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_Porch(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_Delay(unsigned int delay);
unsigned int Scaler_Get_FreeRun_To_FrameSync_By_HW_Delay(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_FastMode(unsigned int Value);
unsigned int Scaler_Get_FreeRun_To_FrameSync_By_HW_FastMode(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL2(unsigned char ucEnable);
unsigned int Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL2(void);
void Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL3(unsigned char ucEnable);
unsigned int Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL3(void);
void state_update_disp3d_info(void);

unsigned char get_3D_mode_enable(void);
void set_3D_mode_enable(unsigned char enable);
unsigned char get_3D_overscan_enable(void);
void set_3D_overscan_enable(unsigned char enable);
unsigned int get_3D_overscan_input_hsta(void);
void set_3D_overscan_input_hsta(unsigned int hsta);
unsigned int get_3D_overscan_input_vsta(void);
void set_3D_overscan_input_vsta(unsigned int vsta);
unsigned int get_3D_overscan_input_wid(void);
void set_3D_overscan_input_wid(unsigned int wid);
unsigned int get_3D_overscan_input_len(void);
void set_3D_overscan_input_len(unsigned int len);
unsigned int get_3D_overscan_output_hsta(void);
void set_3D_overscan_output_hsta(unsigned int hsta);
unsigned int get_3D_overscan_output_vsta(void);
void set_3D_overscan_output_vsta(unsigned int vsta);
unsigned int get_3D_overscan_output_wid(void);
void set_3D_overscan_output_wid(unsigned int wid);
unsigned int get_3D_overscan_output_len(void);
void set_3D_overscan_output_len(unsigned int len);
unsigned int get_field_alternative_3d_mode_enable(void);
void set_field_alternative_3d_mode_enable(unsigned int enable);
unsigned int get_line_alternative_3d_mode_enable(void);
void set_line_alternative_3d_mode_enable(unsigned int enable);
void check_3D_overscan_size_error(void);
void modestate_decide_pixel_mode(void);
void modestate_decide_fractional_framesync(void);
void modestate_decide_fractional_framesyncByDisp(unsigned char _channel);
void modestate_set_display_timing_gen(void);
void modestate_set_display_timing_genByDisp(unsigned char _channel);
void modestate_set_display_timing_gen_clock_div(void);
void modestate_set_display_timing_gen_clock_divByDisp(unsigned char _channel);
void modestate_set_fractional_framesync(void);
void modestate_set_fractional_framesyncByDisp(unsigned char _channel);
void modestate_set_memc_pixel_mode(void);
void modestate_decide_dtg_m_mode(void);
void modestate_decide_dtg_m_modeByDisp(unsigned char _channel);
void modestate_disp_flow_double_buf_enable(unsigned char enable);
void modestate_disp_flow_double_buf_apply(void);
void force_enable_datapath_clock(void);//force enable Xcdi_clock 0xb8022284 bit3
void ResetShareMem(void);
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
typedef enum _MAINSUB_ROTATE_STATUS{
	MAIN_ROTATE_NON_ACTIVE = 0,	/*no opration*/
	MAIN_ROTATE_INIT_UZD = 1,	//UZD : 1920x1080=>1080x1080
	MAIN_ROTATE_INIT_VI = 2,	/*RPC to video fw to initial VI*/
	MAIN_ROTATE_UPDATE_BLOCK_READ = 3,	/*re init main source vodma */
	MAIN_ROTATE_DISPLAY_ON = 4,
}MAINSUB_ROTATE_STATUS;

void scaler_Rotate_VI_init_send_rpc(void);
void set_rotate_mode(DIRECT_VO_FRAME_ORIENTATION value);
DIRECT_VO_FRAME_ORIENTATION get_rotate_mode(void);
void Set_rotate_function(unsigned char enable);
unsigned char Get_rotate_function(void);
void set_ori_rotate_mode(DIRECT_VO_FRAME_ORIENTATION value);
DIRECT_VO_FRAME_ORIENTATION get_ori_rotate_mode(void);
void set_rotate_curState(MAINSUB_ROTATE_STATUS value);
MAINSUB_ROTATE_STATUS get_rotate_curState(void);
void VI_close(void);
void Scaler_HDMI_Rotate(char rotateon, ROTATE_MODE_LIST mode, unsigned char srcIdx);
#endif

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
void Scaler_Set_VDC_27MHz_Mode_Enable(unsigned char ucEnable);
unsigned char Scaler_Get_VDC_27MHz_Mode_Enable(void);
VD_27M_OVERSAMPLING_MODE Scaler_Enter_VDC_27MHz_Mode_Condition(SCALER_DISP_CHANNEL Display);
void Scaler_Set_VDC_27MHz_Mode_SD_Width(unsigned int ScalingDown_Width);
unsigned int Scaler_Get_VDC_27MHz_Mode_SD_Width(void);
#endif

void set_HDMI_HDR_mode(HDR_MODE mode);
HDR_MODE get_HDMI_HDR_mode(void);
HDR_MODE get_OTT_HDR_mode(void);
void set_OTT_HDR_mode(HDR_MODE mode);


void scaler_dolby_hdmi_smooth_toggle(unsigned char isSDRtoEDR);
void drvif_Dolby_HDR_disable_DM_LUT(void);

#ifdef CONFIG_FORCE_RUN_I3DDMA
void set_force_i3ddma_enable(unsigned char enable);
unsigned char get_force_i3ddma_enable(unsigned char display);
#endif
int drvif_i3ddma_triplebuf_flag(void);
void drvif_scaler_i3ddma_vodma_fifo_setting(unsigned char enable);
char drivf_Sub_I2rnd_SetupVODMA(void);
void WaitFor_DEN_STOP_UZUDTG(void);
void WaitFor_Frame_timer(void);
unsigned char drvif_scaler_get_abnormal_dvs_long_flag(void);
void drvif_scaler_wclr_abnormal_dvs_long_short(void);
void drvif_scaler_enable_abnormal_dvs_protect(unsigned char bEnable);
void drvif_scaler_check_abnormal_dvs_flag(void);
void drvif_scaler_check_main_onlinemeasure_flag(void);
unsigned int drvif_memory_get_data_littlealign(unsigned int Value, unsigned int unit);
void set_ori_HDMI_HDR_mode(HDR_MODE mode);//Set hdmi hdr mode at scaler beginning
HDR_MODE get_ori_HDMI_HDR_mode(void);//Get record hdmi hdr mode
void is_DTV_flag_set(unsigned char enable);
unsigned char is_DTV_flag_get(void);
void drvif_scaler_sub_mdomain_switch_irq(unsigned char enable);
void drvif_scaler_i3ddma_vodma_fifo_input_fast(unsigned char display, unsigned int input_frame_rate);

void copy_current_driver_pattern(VSC_DRIVER_PATTERN driver_pattern);
void copy_current_driver_table(VSC_DRIVER_PATTERN *driver_table);
INPUT_TIMING_INDEX get_current_pattern_index(void);
unsigned int get_current_driver_pattern(DRIVER_LIST_INFO info);
void print_current_driver_pattern(void);
void driver_config_data_to_video(void);
int parse_xml_driver_string(VSC_DRIVER_STRING *driver_str);
int copy_driver_table_from_bootload(void);

#ifdef __cplusplus
}
#endif

#endif // #ifndef _SCALER_H_
/*======================== End of File =======================================*/
/**
*
* @}
*/

