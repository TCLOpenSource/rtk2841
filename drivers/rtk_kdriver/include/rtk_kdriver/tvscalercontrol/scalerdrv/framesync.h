/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for mode declarations.
 *
 * @author 	$Author: $
 * @date 	$Date: $
 * @version $Revision:  $
 * @ingroup
 */

/**
 * @addtogroup
 * @{
 */

#ifndef _FRAMESYNC_H
#define _FRAMESYNC_H

//#include "rtd_types.h"

//--------------------------------------------------
// Adjust DV total state machine.
//--------------------------------------------------
// [Code Sync][LewisLee][0990823][1]
typedef enum {
	FRAMESYNC_ADJUST_DVTOTAL_NONE = 0x00,
	FRAMESYNC_ADJUST_DVTOTAL_INITIAL,
	FRAMESYNC_ADJUST_DVTOTAL_ADJUST,
	FRAMESYNC_ADJUST_DVTOTAL_FINISH
} FRAMESYNC_ADJUST_DVTOTAL_STATE;

typedef enum {
	FLL_DYMANIC_ADJUST_DHTOTAL_NONE = 0x00,
	FLL_DYMANIC_ADJUST_DHTOTAL_TO_MAX,
	FLL_DYMANIC_ADJUST_DHTOTAL_TO_MIN,
} FLL_ADJUST_DVTOTAL_STATE;

typedef enum {
	FRAMESYNC_DYMANIC_ADJUST_DHTOTAL_NONE = 0x00,
	FRAMESYNC_DYMANIC_ADJUST_DHTOTAL_TO_MAX,
	FRAMESYNC_DYMANIC_ADJUST_DHTOTAL_TO_MIN,
} FRAMESYNC_DYMANIC_ADJUST_DVTOTAL_STATE;

//--------------------------------------------------
// Offset_Step is the DCLK frequency step for searching frame-sync.
//--------------------------------------------------
#define _OFFSET_STEP    24
#define _SEARCH_TIME    24

#define XTAL_FREQ 27000000
#define IVS_DVS_THRESHOLD 0x100
#define IVS_XTAL_CNT  1
#define IVS_XTAL_CNT2 2
#define DVS_XTAL_CNT  3

//--------------------------------------------------
// Global Variables
//--------------------------------------------------


//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void drvif_framesync_reset_dv_total_flg(unsigned char flg);
void drvif_framesync_reset_dv_total(void);


unsigned char drvif_framesync_detect(void);
unsigned char drvif_framesync_do(void);
void framesync_set_enterlastline_at_frc_mode_flg(unsigned char flg);
unsigned char framesync_get_enterlastline_at_frc_mode_flg(void);
//unsigned char drvif_frc_fixlastline_frc_measure(void);
unsigned char drvif_framesync_offlinemeasureendevent(void); //forster modified 071224
void drvif_framesync_gatting(unsigned char enable);
unsigned char drvif_decide_VO_SD_video_frameSync_enable(void);
unsigned char drvif_framesync_gatting_do(void);
#ifdef CONFIG_FS_HS_BIAS
unsigned char drvif_framesync_hs_bias(void);
void drvif_framesync_hs_bias_release(void);
#endif //#ifdef CONFIG_FS_HS_BIAS

void drvif_framesync_5_4(void);
void drvif_framesync_5_4_release(void);

void framesync_syncDoubleDVSReset(void);
void framesync_syncDoubleDVS_Frc_Tracking_Framesync(unsigned char display, unsigned char ucEnable);
void framesync_syncDoubleDVS(unsigned char display);
void framesync_DoubleDvs_Wait_FS_Lock(unsigned char display);
unsigned char framesync_sync_fixlastline_mode(void);
unsigned char framesync_lastlinefinetune_at_frc_mode(void);
void framesync_set_enterlastline_at_frc_mode_flg(unsigned char flg);
unsigned char framesync_get_enterlastline_at_frc_mode_flg(void);
FRAMESYNC_ADJUST_DVTOTAL_STATE framesync_lastlinefine_dvtotal_adjust(void);
unsigned int framesync_lastlinefinetune_at_frc_mode_get_dhtotal_value(void);
void framesync_lastlinefinetune_at_frc_mode_modify_dhtotal_value(unsigned char reset);
void framesync_lastlinefinetune_at_frc_mode_dymanic_adjust_dhtotal(FLL_ADJUST_DVTOTAL_STATE state);
void framesync_set_lastlinefinetune_at_frc_mode_fixDclk_Flag(unsigned char ucEnable);
unsigned char framesync_get_lastlinefinetune_at_frc_mode_fixDclk_Flag(void);
void drvif_framesync_2Dcvt3D_reset_dv_total(void);
unsigned int hardware_measure_dvtotal(void);
unsigned int framesync_get_dvtotal_min(void);
unsigned int framesync_dynamic_adjust_dvtotal_den_relation(unsigned int CurDVtotal);
unsigned char framesync_adjust_dvtotal_at_framesync_mode(SCALER_DISP_CHANNEL display);
void framesync_mode_dymanic_adjust_dhtotal(FRAMESYNC_DYMANIC_ADJUST_DVTOTAL_STATE state);
unsigned char framesync_adjust_dvtotal_before_display_at_framesync_mode(SCALER_DISP_CHANNEL display);
unsigned char framesync_new_fixlastline_set_locked_threashold(unsigned short threshold_val);
unsigned char framesync_new_fixlastline_check_locked_status(void);
unsigned char framesync_new_fixlastline_threashold_check_enable(unsigned char bEnable);
unsigned char framesync_new_fixlastline_flow_do(void);
unsigned char framesync_new_fixlastline_fine_tune(void);
unsigned char framesync_lastlinefinetune_at_new_mode(void);

void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(unsigned char ucEnable);
void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper(unsigned int ucValue);
void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower(unsigned int ucValue);
void Scaler_Set_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag(UINT8 ucEnable);
void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Typical(UINT32 ucValue);
void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Upper(UINT32 ucValue);
void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Lower(UINT32 ucValue);
void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Typical(UINT32 ucValue);
void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Upper(UINT32 ucValue);
void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Lower(UINT32 ucValue);
void framesync_wait_vdc_stable(void);
UINT32 framesync_new_fixlastline_get_stable_xtal_cnt(UINT8 type);

#endif /* _FRAMESYNC_H */
//----------------------------------------------------------------------------------------------------

/**
 *
 * @}
 */

