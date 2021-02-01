//----------------------------------------------------------------------------------------------------
// ID Code      : FrameSync.c No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <mach/io.h>

//FIXME #include <rbus/rbusScaledownReg.h>
#include <rbus/di_reg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/sub_vgip_reg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/vodma_reg.h>
#include <rbus/vodma2_reg.h>
#include <rbus/patterngen_reg.h>
//#include <rbus/scaler/rbusCRTReg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/offms_reg.h>

#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
//#include <tvscalercontrol/scaler/source.h>
//#include <tvscalercontrol/scaler/scalerlib.h>
//#include <tvscalercontrol/scaler/modeState.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/framesync.h>
#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/scalerdrv/adjust.h>
#include <tvscalercontrol/scalerdrv/syncproc.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/adcsource/vga.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle_lib.h>
#include <tvscalercontrol/vdc/video.h>
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scalerdrv/power.h>
#include <../tvscalercontrol/scaler_vfedev.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <mach/rtk_log.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>

//#include <tvscalercontrol/scalerdrv/mode.h>
//#include <tvscalercontrol/vip/gibi_od.h>

//#include <tvscalercontrol/scaler/scalerAPI.h>

// Double DVS to solve 1080p24 & 1080p30 video flicker
//#include <tvscalercontrol/vip/db_DVS_gamma.h>
//#include <tvscalercontrol/vip/color.h>
//#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/panel/panelapi.h>
typedef double                      FLOAT64;

static unsigned char framesync_enterlastline_at_frc_mode_flg = FALSE;

static unsigned char framesync_change_dv_total_flg = _FALSE;

// VO source SD video frame sync enable control
static unsigned char framesync_vo_sd_fs_enable_flg = _DISABLE; // _ENABLE;

//USER:LewisLee DATE:2010/08/12
//for framesync adjust DV total slowly
static FRAMESYNC_ADJUST_DVTOTAL_STATE Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;
//static unsigned short TargetDVTotal = 0, OriginalDVTotal = 0;
static unsigned char ucframesync_lastlinefinetune_at_frc_mode_fixDclk_Flag = _DISABLE;

//static unsigned int framesync_lastlinefinetune_at_frc_mode_DHtotal = 2200;

#define _MEASURE_2FRAME_AT_ONCE
#define TAG_NAME_VBE "VBE"


#define CONTINUE_MODE	0
#define SINGLE_MODE		1
#define _SELECT_MEASURE_MODE	SINGLE_MODE
#define _DCLK_SPREAD_RANGE (0)

//USER:LewisLee
//to prevent porch too small, let Panel abnormal
#define DV_TOTAL_FRONT_PORCH_OFFSET	3

//USER:LewisLee DATE:2011/02/23
//I have modify new Double DVS algo
//but not test finish
//#define DOUBLE_DVS_ORIGINAL_ALGO	1

#ifdef DOUBLE_DVS_ORIGINAL_ALGO
	//need nothing
#else //#ifdef DOUBLE_DVS_ORIGINAL_ALGO
void drvif_measure_total_pixels(unsigned char ucEnable);
void drvif_measure_dvtotal_last_line_pixels(unsigned char ucEnable);
#endif  //#ifdef DOUBLE_DVS_ORIGINAL_ALGO

static void framesync_set_iv2dv_delay(void);

//0x1802_8034[21:0], total 22 bit
#define TOTAL_PIXEL_CNT_MAX				0x3FFFFF

//0x1802_803C[27:16], total 12 bit
#define TOTAL_LINE_CNT_MAX					0xFFF

//0x1802_803C[11:0], total 12 bit
#define TOTAL_LAST_LINE_PIXEL_CNT_MAX	0xFFF

//USER:LewisLee DATE:2013/08/27
//for some panel, range have 50 / 60 Hz two size
static UINT8 Scaler_FixLastLine_DVTotal_ByVfreq_Limit_Enable_Flag = _ENABLE;
static UINT32 Scaler_FixLastLine_DVTotal_Limit_60Hz_Typical = 0;
static UINT32 Scaler_FixLastLine_DVTotal_Limit_60Hz_Upper = 0;
static UINT32 Scaler_FixLastLine_DVTotal_Limit_60Hz_Lower = 0;
static UINT32 Scaler_FixLastLine_DVTotal_Limit_50Hz_Typical = 0;
static UINT32 Scaler_FixLastLine_DVTotal_Limit_50Hz_Upper = 0;
static UINT32 Scaler_FixLastLine_DVTotal_Limit_50Hz_Lower = 0;

static unsigned char Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Enable_Flag = _DISABLE;
static unsigned int Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Upper = 0;
static unsigned int Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Lower = 0;

void Scaler_Set_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag(UINT8 ucEnable)
{
	//Get Get_DISP_VERTICAL_TOTAL() original value
	Scaler_FixLastLine_DVTotal_ByVfreq_Limit_Enable_Flag = _DISABLE;

	//set DV total limit Upper / Lower, Ap can adjust
	Scaler_FixLastLine_DVTotal_Limit_60Hz_Typical = Get_DISP_VERTICAL_TOTAL();
	Scaler_FixLastLine_DVTotal_Limit_60Hz_Upper = (Get_DISP_VERTICAL_TOTAL()<<2)/3;
	Scaler_FixLastLine_DVTotal_Limit_60Hz_Lower = (Get_DISP_VERTICAL_TOTAL()*3)>>2;

	Scaler_FixLastLine_DVTotal_Limit_50Hz_Typical = Get_DISP_VERTICAL_TOTAL();
	Scaler_FixLastLine_DVTotal_Limit_50Hz_Upper = (Get_DISP_VERTICAL_TOTAL()<<2)/3;
	Scaler_FixLastLine_DVTotal_Limit_50Hz_Lower = (Get_DISP_VERTICAL_TOTAL()*3)>>2;

	if(_DISABLE == ucEnable)
		return;

	Scaler_FixLastLine_DVTotal_ByVfreq_Limit_Enable_Flag = ucEnable;

}

void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Typical(UINT32 ucValue)
{
	Scaler_FixLastLine_DVTotal_Limit_60Hz_Typical = ucValue;
}

UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Typical(void)
{
	if(Scaler_FixLastLine_DVTotal_Limit_60Hz_Typical != 0)
		return Scaler_FixLastLine_DVTotal_Limit_60Hz_Typical;
	else
		return Get_DISP_VERTICAL_TOTAL();
}

void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Upper(UINT32 ucValue)
{
	Scaler_FixLastLine_DVTotal_Limit_60Hz_Upper = ucValue;
}

UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Upper(void)
{
	if(Scaler_FixLastLine_DVTotal_Limit_60Hz_Upper != 0)
		return Scaler_FixLastLine_DVTotal_Limit_60Hz_Upper;
	else
		return Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MAX();
}

void Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Lower(UINT32 ucValue)
{
	Scaler_FixLastLine_DVTotal_Limit_60Hz_Lower = ucValue;
}

UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Lower(void)
{
	if(Scaler_FixLastLine_DVTotal_Limit_60Hz_Lower != 0)
		return Scaler_FixLastLine_DVTotal_Limit_60Hz_Lower;
	else
		return Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MIN();
}

void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Typical(UINT32 ucValue)
{
	Scaler_FixLastLine_DVTotal_Limit_50Hz_Typical = ucValue;
}

UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Typical(void)
{
	if(Scaler_FixLastLine_DVTotal_Limit_50Hz_Typical != 0)
		return Scaler_FixLastLine_DVTotal_Limit_50Hz_Typical;
	else
		return (Get_DISPLAY_CLOCK_TYPICAL() / (Get_DISP_HORIZONTAL_TOTAL()*50));
}

void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Upper(UINT32 ucValue)
{
	Scaler_FixLastLine_DVTotal_Limit_50Hz_Upper = ucValue;
}

UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Upper(void)
{
	if(Scaler_FixLastLine_DVTotal_Limit_50Hz_Upper != 0)
		return Scaler_FixLastLine_DVTotal_Limit_50Hz_Upper;
	else
		return Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MAX();
}

void Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Lower(UINT32 ucValue)
{
	Scaler_FixLastLine_DVTotal_Limit_50Hz_Lower = ucValue;
}

UINT32 Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Lower(void)
{
	if(Scaler_FixLastLine_DVTotal_Limit_50Hz_Lower != 0)
		return Scaler_FixLastLine_DVTotal_Limit_50Hz_Lower;
	else
		return Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MIN();
}

UINT8 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag(void)
{

	// [PR to SG] for PR -> SG 3D TCON, 3D need timing free run@60Hz
	if(Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode())
		return FALSE;

	return Scaler_FixLastLine_DVTotal_ByVfreq_Limit_Enable_Flag;
}
UINT32 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Typical(void)
{
	if(ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),500) < 30) // 47Hz~53Hz input
	{
		return Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Typical();
	}
	else// if(ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),500) >= 30)
	{
		return Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Typical();
	}
}
UINT32 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Upper(void)
{
	if((ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),500) < 30) ||
		(ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),250) < 20)) // 47Hz~53Hz input
	{
		return Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Upper();
	}
	else// if(ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),500) >= 30)
	{
		return Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Upper();
	}
}

UINT32 Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Lower(void)
{
	if((ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),500) < 30) ||
		(ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),250) < 20)) // 47Hz~53Hz input
	{
		return Scaler_Get_FixLastLine_DVTotal_Limit_50Hz_Lower();
	}
	else// if(ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),500) >= 30)
	{
		return Scaler_Get_FixLastLine_DVTotal_Limit_60Hz_Lower();
	}
}
unsigned char Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(void)
{
//#ifdef VBY_ONE_PANEL
	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K)
		return _TRUE;	// Millet3 4k2k timing don't use this flag
//#else
	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() && (Get_DISPLAY_2k1k_output_mode_status() == 0))
		return _FALSE;	// Millet3 4k2k timing don't use this flag
//#endif

	return Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Enable_Flag;
}
void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(unsigned char ucEnable)
{
	Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Enable_Flag = ucEnable;
}

void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper(unsigned int ucValue)
{
	Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Upper = ucValue;
}

unsigned int Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper(void)
{
	if(_ENABLE == Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag()){
		return Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Upper();
	}
	return Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Upper;
}

void Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower(unsigned int ucValue)
{
	Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Lower= ucValue;
}

unsigned int Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower(void)
{
	if(_ENABLE == Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag()){
		return Scaler_Get_FixLastLine_DVTotoal_Limit_ByVfreq_Lower();
	}
	return Scaler_FRC_Open_Fix_Lastline_FixDclk_DVTotal_Limit_Lower;
}

//USER: LewisLee DATE:2010/05/25
//in Fix Last lIne, Double DVS etc, maybe change Dv total
//we need set it to default value at mode reset
void drvif_framesync_reset_dv_total_flg(unsigned char flg)
{
	framesync_change_dv_total_flg = flg;
}


void drvif_framesync_reset_dv_total(void)
{
	ppoverlay_dv_total_RBUS dv_total_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;

#if 0  //mark scalerlib control by qing_liu
	//USER:LewisLee DATE:2010/08/12
	//to prevent panel tolerance too small
	//mediabrowser need set to original setting
	if (_SRC_USB == Scaler_InputSrcGetMainChType())
	{
		//do nothing, it need to reset DV total and last line
	}
	else
	{
		if(_TRUE == Scaler_Get_SetDvtotal_Slowly_flag())
			return;
	}
#endif
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);

	if((Get_DISP_VERTICAL_TOTAL() - 1) != dv_total_reg.dv_total)
	{
		dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total_last_line = (Get_DISP_HSYNC_LASTLINE() - 1) & 0x1fff;
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	}

	framesync_change_dv_total_flg = _FALSE;
}

//User:LewisLee DATE:2012/11/26
//to prevent DV total too small, panel abnormal
unsigned int framesync_get_dvtotal_min(void)
{
//	return (Get_DISP_ACT_END_VPOS() + _FRC_LAST_LINE_DV_TOTAL_FRONT_PORCH_OFFSET);
	return (Get_DISP_DEN_END_VPOS() + DV_TOTAL_FRONT_PORCH_OFFSET);
}

//USER:LewisLee DATE:2012/11/29
//to dynamic adjust Panel Den position
//to prevent over panel spec or framesync error
unsigned int framesync_dynamic_adjust_dvtotal_den_relation(unsigned int CurDVtotal)
{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
	UINT32 ModifyDvtotal = 0, DVtotalMin = 0;
	UINT32 OriginalDenStart = 0, OriginalDenEnd = 0, Porchoffset = 0;
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;

	if(_ENABLE == Scaler_Get_Dynamic_Adjust_Display_DenVPos_Flag())
	{
		DVtotalMin = framesync_get_dvtotal_min();
		ModifyDvtotal = DVtotalMin; //initial value
		Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(0);
		Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(0);

		if(CurDVtotal >= DVtotalMin)
		{
			// it is normal case
			return CurDVtotal;
		}

		OriginalDenStart = Get_DISP_DEN_STA_VPOS();
		OriginalDenEnd = Get_DISP_DEN_END_VPOS();

		if(DVtotalMin >= (OriginalDenEnd - OriginalDenStart
			+ Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min()
			+ Scaler_Get_Dynamic_Adjust_Display_DenVPos_FrontPorch_Min()))
		{
			//porch is enough, just DV start too large, let front porch not enough
			//move up Den position
			Porchoffset = DVtotalMin - CurDVtotal;

			if(OriginalDenStart >= Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min())
			{
				if((OriginalDenStart >= Porchoffset)
					&& ((OriginalDenStart - Porchoffset) >= Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min()))
				{
					//move up Porchoffset
					Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(OriginalDenStart - Porchoffset);
					Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(OriginalDenEnd - Porchoffset);
				}
				else
				{
					//it should not happen in this case, just prevent error
					Porchoffset = OriginalDenStart - Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min();

					Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min());
					Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(OriginalDenEnd - Porchoffset);
				}

				dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
				dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
				dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
				IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);

				ModifyDvtotal = Get_DISP_DEN_END_VPOS() + Scaler_Get_Dynamic_Adjust_Display_DenVPos_FrontPorch_Min();

				if(CurDVtotal >= ModifyDvtotal)
				{
					//Den move to save region, don't need to change DV total
					//return original value
					ModifyDvtotal = CurDVtotal;
				}
			}
			else// if(OriginalDenStart < Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min())
			{
				//it should not happen in this case, just prevent error
				//move Den down
				Porchoffset = Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min() - OriginalDenStart;

				Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min());
				Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(OriginalDenEnd + Porchoffset);

				dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
				dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
				dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
				IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);

				ModifyDvtotal = Get_DISP_DEN_END_VPOS() + Scaler_Get_Dynamic_Adjust_Display_DenVPos_FrontPorch_Min();

				if(CurDVtotal >= ModifyDvtotal)
				{
					//Den move to save region, don't need to change DV total
					//return original value
					ModifyDvtotal = CurDVtotal;
				}
			}

			return ModifyDvtotal;
		}
		else
		{
			//porch is not enough, need to move Den position and DV total
			if(OriginalDenStart >= Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min())
			{
				//move up Den position
				Porchoffset = OriginalDenStart - Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min();
				Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min());
				Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(OriginalDenEnd - Porchoffset);
			}
			else// if(OriginalDenStart < Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min())
			{
				//move down Den position
				Porchoffset = Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min() - OriginalDenStart;
				Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(Scaler_Get_Dynamic_Adjust_Display_DenVPos_BackPorch_Min());
				Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(OriginalDenEnd + Porchoffset);
			}

			dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
			dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
			dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
			IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);

			ModifyDvtotal = Get_DISP_DEN_END_VPOS() + Scaler_Get_Dynamic_Adjust_Display_DenVPos_FrontPorch_Min();

			if(CurDVtotal >= ModifyDvtotal)
			{
				//Den move to save region, don't need to change DV total
				//return original value
				ModifyDvtotal = CurDVtotal;
			}

			return ModifyDvtotal;
		}
	}
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

	return framesync_get_dvtotal_min();
}

#define DYNAMIC_IV2DV_DELAY_RULE 1
#define PIXEL_SHIFT_RESOLUTION 100

extern unsigned char drv_memory_get_game_mode(void);
static void framesync_set_iv2dv_delay(void)
{
	UINT8 ucThrIP_Flag = _FALSE;
	UINT8 chromaErr = FALSE;
	UINT8 b_Is3AMode = FALSE;
	UINT8  measureBased = 1;
	UINT32 ivs_cnt1, ivs_cnt2;
	UINT32 target_ivs_cnt, target_distance;
	UINT32 distance1, distance2;
	UINT32 line_compensation=0, pixel_compensation=0;
	UINT32 xtalCountPerFrame=0;
	UINT32 targetPixel=0;
	UINT32 temp=0;
	UINT32 shift_1st_line=0, shift_2nd_line=0;

	ppoverlay_fs_iv_dv_fine_tuning1_RBUS tuning1_reg;
	ppoverlay_fs_iv_dv_fine_tuning2_RBUS tuning2_reg;
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5_reg;
	di_im_di_active_window_control_RBUS di_active_window_control_reg;


	//set iv2dv delay
	ucThrIP_Flag = Scaler_DispGetStatus((SCALER_DISP_CHANNEL) SLR_MAIN_DISPLAY,SLR_DISP_THRIP);
	//chromaErr = ((IoReg_Read32(DI_IM_DI_FRAMESOBEL_STATISTIC_VADDR) & _BIT31)?1:0);
	chromaErr = Scaler_GetMA_Chroma_Error_En_From_vipTable();
	b_Is3AMode = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)0, SLR_DISP_MA3A);

	//for measure result, sync chroma error setting
	if(chromaErr == 0){
		IoReg_ClearBits(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, _BIT31);
	}else{
		IoReg_SetBits(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, _BIT31);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE," [framesync iv2dv delay mode]  Scaler_GetMA_Chroma_Error_En_From_vipTable = %d\n ", Scaler_GetMA_Chroma_Error_En_From_vipTable());
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE," [framesync iv2dv delay mode]  ucThrIP_Flag:%d,  chromaErr:%d, b_Is3AMode = %d\n ", ucThrIP_Flag, chromaErr, b_Is3AMode);

	tuning2_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
	tuning2_reg.iv2dv_pixel = 20;
	tuning2_reg.iv2dv_pixel2 = 20; // cant' be zero
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, tuning2_reg.regValue);

	if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) || (!drv_memory_get_game_mode()))//fs need set iv2dv to be 1, game mode need set iv2dv delay in drv_GameMode_iv2dv_delay
	{
		fs_iv_dv_fine_tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
		fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = 1;
		fs_iv_dv_fine_tuning5_reg.iv2dv_line = 1;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5_reg.regValue);
	}

	IoReg_Mask32(PPOVERLAY_IVS_cnt_1_reg, ~_BIT27, 0);
/*
	WaitFor_IVS1();
	WaitFor_IVS1();
	WaitFor_IVS1();
	WaitFor_IVS1();
	WaitFor_IVS1();
*/
//	int i=0;
//	for(i=0; i<10; i++){
//		printk(KERN_EMERG "ivs_cnt1=%x, ivs_cnt2=%x\n", IoReg_Read32(PPOVERLAY_IVS_cnt_1_reg), IoReg_Read32(PPOVERLAY_IVS_cnt_2_reg));
//		WaitFor_IVS1();
//	}

	tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);

	if(_TRUE == ucThrIP_Flag)
	{
		/*step1 : measure target distance*/
		//WaitFor_IVS1();
		//msleep(100);
		ivs_cnt1 = IoReg_Read32(PPOVERLAY_IVS_cnt_1_reg) & 0xffffff;
		ivs_cnt2 = IoReg_Read32(PPOVERLAY_IVS_cnt_2_reg) & 0xffffff;
		target_ivs_cnt = (ivs_cnt1+ivs_cnt2)/2;
		if(ivs_cnt1 > target_ivs_cnt){	//compensate odd;
			measureBased = 0;
			distance1 = (ivs_cnt1 - target_ivs_cnt);
			distance2 = (target_ivs_cnt - ivs_cnt2);
		}
		else{ //compensate even;
			measureBased = 1;
			distance1 = (target_ivs_cnt - ivs_cnt1);
			distance2 = (ivs_cnt2 - target_ivs_cnt);
		}
		tuning1_reg.iv2dv_toggle_inv = 0;
		tuning1_reg.iv2dv_toggle_en = _ENABLE;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"ivs_cnt1=%x, ivs_cnt2=%x, target_ivs_cnt=%x, dist1=%x, dist2=%x, measureBased=%x \n",
			ivs_cnt1, ivs_cnt2, target_ivs_cnt, distance1, distance2, measureBased);
		target_distance = distance1;
		xtalCountPerFrame = (270000000 / Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));
		temp = (target_distance*Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)/100*(Scaler_DispGetInputInfo(SLR_INPUT_V_LEN)*2)); //interlace*2
		targetPixel = temp /(xtalCountPerFrame/100);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[iv2dv] Input htotal:%d, Input vtotal=%d\n", Scaler_DispGetInputInfo(SLR_INPUT_H_LEN),
			Scaler_DispGetInputInfo(SLR_INPUT_V_LEN));
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[iv2dv] xtalCountPerFrame:%d, temp=%d, targetPixel:%d\n", xtalCountPerFrame, temp, targetPixel);

		di_active_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);

		/*Because of hsync period gen. by DI_Hsize+Hblk_size, if input h total is larger than it,
		iv2dv rule need to calculate by even & odd field*/
		if((di_active_window_control_reg.hsize+di_active_window_control_reg.hblksize)<
			Scaler_DispGetInputInfo(SLR_INPUT_H_LEN))
		{
			unsigned int i=0;

			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[iv2dv] DI htotal < Input Htotal \n");

			if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>580)&& (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)<620)){
				/*NTSC*/
				shift_1st_line = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*2 -
					(di_active_window_control_reg.hsize+di_active_window_control_reg.hblksize);
				shift_2nd_line =  di_active_window_control_reg.hsize+di_active_window_control_reg.hblksize;
			}else{
				/*PAL*/
				shift_1st_line = di_active_window_control_reg.hsize+di_active_window_control_reg.hblksize;
				shift_2nd_line = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*2 -
					(di_active_window_control_reg.hsize+di_active_window_control_reg.hblksize);
			}

			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[iv2dv] shift_1st_line=%d, shift_2nd_line=%d\n", shift_1st_line, shift_2nd_line);

			for(i=0; i<8; i++){

				if(targetPixel<=Scaler_DispGetInputInfo(SLR_INPUT_H_LEN))
					break;

				if(i%2==0){
					if(targetPixel > shift_1st_line)
						targetPixel-=shift_1st_line;
					else
						break;
				}
				else{
					if(targetPixel > shift_2nd_line)
						targetPixel-=shift_2nd_line;
					else
						break;
				}
				line_compensation++;
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[iv2dv] targetPixel=%d, line_compensation=%d\n", targetPixel, line_compensation);
			}
			pixel_compensation = targetPixel;

		}
		else{
			line_compensation = targetPixel/Scaler_DispGetInputInfo(SLR_INPUT_H_LEN);
			pixel_compensation = targetPixel%Scaler_DispGetInputInfo(SLR_INPUT_H_LEN);
		}
#ifdef CONFIG_ALL_SOURCE_DATA_FS
		if(measureBased){
			fs_iv_dv_fine_tuning5_reg.iv2dv_line = 8;
			fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = 8+line_compensation;
			tuning2_reg.iv2dv_pixel = 20;
			tuning2_reg.iv2dv_pixel2 = 20+pixel_compensation;
		}
		else{
			fs_iv_dv_fine_tuning5_reg.iv2dv_line = 8+line_compensation;
			fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = 8;
			tuning2_reg.iv2dv_pixel = 20+pixel_compensation;
			tuning2_reg.iv2dv_pixel2 = 20;
		}
#else
		if(measureBased){
			fs_iv_dv_fine_tuning5_reg.iv2dv_line = 1;
			fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = 1+line_compensation;
			tuning2_reg.iv2dv_pixel = 20;
			tuning2_reg.iv2dv_pixel2 = 20+pixel_compensation;
		}
		else{
			fs_iv_dv_fine_tuning5_reg.iv2dv_line = 1+line_compensation;
			fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = 1;
			tuning2_reg.iv2dv_pixel = 20+pixel_compensation;
			tuning2_reg.iv2dv_pixel2 = 20;
		}
#endif
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[iv2dv] line_compensation:%d, pixel_compensation=%d\n", line_compensation, pixel_compensation);

		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, tuning2_reg.regValue);
		if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) || (!drv_memory_get_game_mode()))//fs need set iv2dv to be 1, game mode need set iv2dv delay in drv_GameMode_iv2dv_delay
			IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5_reg.regValue);

	}
	else{
		tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		tuning1_reg.iv2dv_toggle_en = _DISABLE;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);
	}

#ifdef CONFIG_I2RND_ENABLE
		ppoverlay_dctl_iv2dv_ihs_ctrl_RBUS ppoverlay_dctl_iv2dv_ihs_ctrl_reg;

		if(Scaler_I2rnd_get_enable()==TRUE){
			ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg);
			ppoverlay_dctl_iv2dv_ihs_ctrl_reg.iv2dv_ih_slf_width = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_LEN);
			ppoverlay_dctl_iv2dv_ihs_ctrl_reg.iv2dv_ih_slf_gen_en = 1;
			IoReg_Write32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg, ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue);
		}else{
			ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg);
			ppoverlay_dctl_iv2dv_ihs_ctrl_reg.iv2dv_ih_slf_gen_en = 0;
			IoReg_Write32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg, ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue);
		}
#endif

}

/**
* drvif_framesync_detect
*  This function will Detect frame sync status
* @param <none>
*@return <result>  	 { TRUE if frame sync is ok, FALSE while PLL mislock
*/
unsigned char drvif_framesync_detect(void)
{
	mdomain_cap_ich12_ibuff_status_RBUS mdomain_cap_ich12_ibuff_status_reg;

#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if(vbe_disp_get_adaptivestream_fs_mode() == 1){
		//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"fsync under smoothtoggle mode, don't check\n");
		return TRUE;//to test rika20151224
	}
#endif
	if (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == TRUE) {
		if ((MDOMAIN_DISP_Disp_main_enable_get_main_disp_en(IoReg_Read32(MDOMAIN_DISP_Disp_main_enable_reg)) == 0)
			&&(MDOMAIN_CAP_Cap_In1_enable_get_in1_cap_enable(IoReg_Read32(MDOMAIN_CAP_Cap_In1_enable_reg)) == 0)) {
		mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);
		if(_CHANNEL1 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))//If Framesync case, we just check the following flow
	{
		if(mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf | mdomain_cap_ich12_ibuff_status_reg.fsync_ovf | mdomain_cap_ich12_ibuff_status_reg.fsync_udf)
		{

			if(fwif_color_get_osd_Outer() ==1) /* it's for playback photo patch . rord.tsao */
			{
				//main_active_h_start_end_RBUS main_active_h_start_end_reg;
				//main_active_v_start_end_RBUS main_active_v_start_end_reg;
				fwif_color_set_osd_Outer(0);
				mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf=1;
				mdomain_cap_ich12_ibuff_status_reg.fsync_ovf=1;
				mdomain_cap_ich12_ibuff_status_reg.fsync_udf=1;
				IoReg_Write32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg,mdomain_cap_ich12_ibuff_status_reg.regValue);
				mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);
				if(mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf | mdomain_cap_ich12_ibuff_status_reg.fsync_ovf | mdomain_cap_ich12_ibuff_status_reg.fsync_udf)
				{
					rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"ch1 Frame Sync check error=%d %d %d\n", mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf, mdomain_cap_ich12_ibuff_status_reg.fsync_ovf, mdomain_cap_ich12_ibuff_status_reg.fsync_udf);
				} else {
					// VO decompress mode don't support empty gate
					if (((rtd_inl(VODMA_DECOMP_CTRL0_reg) & _BIT0) == 0) && ((IoReg_Read32(VODMA_VODMA_CLKGEN_reg)&_BIT3) ==0)){
						IoReg_Mask32(VODMA_VODMA_CLKGEN_reg, ~(_BIT3), _BIT3);
					}
					return TRUE;
				}
			}


			rtd_printk(KERN_ERR, TAG_NAME_VBE,"ch1 Frame Sync check error=%d %d %d\n", mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf, mdomain_cap_ich12_ibuff_status_reg.fsync_ovf, mdomain_cap_ich12_ibuff_status_reg.fsync_udf);
#if 0 //frank@1225 check below code when sirius IC back
			cnt++;
				};
			}
#endif
			// for debug
			while(1){
				msleep(50);

				if(!(IoReg_Read32(0xb8022288)&_BIT17))
					break;
			}

			return FALSE;
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
		else
		{
			if(mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf_sub | mdomain_cap_ich12_ibuff_status_reg.fsync_ovf_sub | mdomain_cap_ich12_ibuff_status_reg.fsync_udf_sub)
			{
				rtd_printk(KERN_ERR, TAG_NAME_VBE,"ch2 Frame Sync check error=%d %d %d\n", mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf_sub, mdomain_cap_ich12_ibuff_status_reg.fsync_ovf_sub, mdomain_cap_ich12_ibuff_status_reg.fsync_udf_sub);
				return FALSE;
			}
		}
#endif
	}

	}


	return TRUE;
 }


// CSW+  0980429
// Double DVS to solve 1080p24 & 1080p30 video flicker
/**
* framesync_syncDoubleDVSReset
*  This function will reset DVS(double display V sync) setting
* @param <pDelta>       { display }
*@return <result>  	 { Return void}
*/
#define _DOUBLE_DVS_RESET_ALL_FLL		1	//LewisLee
void framesync_syncDoubleDVSReset(void)
{
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;

	// 1. disable frame sync last line timing
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	#if 0	//fix me later by ben.
	if((_DISABLE == display_timing_ctrl1_reg.disp_fix_last_line) && (_DISABLE == display_timing_ctrl1_reg.multiple_dvs))
		return;
	#endif

	// 7. disable double DVS
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	//WaitFor_DEN_STOP_Done();//Remove by Will. Ben Check no need.

//	display_timing_ctrl1_reg.multiple_dvs = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

#ifdef _DOUBLE_DVS_RESET_ALL_FLL
	//USER:LewisLee DATE:2012/12/06
	//for novatek Tcon IC, too easy have white noise
	display_timing_ctrl1_reg.disp_frc_on_fsync = _FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	drvif_scaler_set_display_mode_frc2fsync_by_hw(_TRUE);
#else //#ifdef _DOUBLE_DVS_RESET_ALL_FLL
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
#endif //#ifdef _DOUBLE_DVS_RESET_ALL_FLL

	// 8. Disable DMA clock sel frank@04122011 add below for DMACLK
#if 0	//mag2 un-used dclk sel, move to dpll_o
	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1){
		if (GET_PANEL_DCLK_DIV() == 1){
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL);
		}
		else
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
	}
	else
		drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
#endif
	// 8. disable gamma table switch
//	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
//	display_timing_ctrl1_reg.gat_sw_en = _DISABLE;
//	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
}


#define _DCLK_FREQ_SYN_SLT  0x200

//USER:LewisLee DATE:2011/02/23
//modify double DVS algorithm
//when we have turn on fix last line
//we don't need to calculate again

//#define _DOUBLE_DVS_INPUT_VSYNC_LOST_THRESHOLD		3
#define _DOUBLE_DVS_INPUT_VSYNC_LOST_THRESHOLD		6
#define _DOUBLE_DVS_DV_TOTAL_FRONT_PORCH_OFFSET	3//Lewis Modify 10
#define _DOUBLE_DVS_FRC_LAST_LINE_PIXEL_OFFSET		4
#define _DOUBLE_DVS_FRC_RE_MEASURE_TIMES			3

#define DOUBLE_DVS_printk(format, args...) 	pr_debug(format, ##args)
//#define DOUBLE_DVS_printk(format, args...)

//USER:LewisLee DATE:2012/05/17
//Use Fix Last Line for Double DVS, not Adjust Last Line Pixel
void framesync_syncDoubleDVS_FLL(UINT8 display)
{
//	UINT8 iv2dv_line=3;
//	UINT8 iv2dv_16p1=0;
	UINT16 DVTotal, DVTotal1, DHTotal, DHTotal1;
	UINT16 measure_timeout;
	UINT8 InputSyncLoseCount = 0;
//	fs_iv_dv_fine_tuning1_RBUS fs_iv_dv_fine_tuning1_reg;
	//fs_iv_dv_fine_tuning3_RBUS fs_iv_dv_fine_tuning3_reg;
//	fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
//	fs_iv_dv_fine_tuning2_RBUS fs_iv_dv_fine_tuning2_reg;
	ppoverlay_measure_total_pixels_result1_RBUS measure_total_pixels_result1_reg;
	ppoverlay_measure_total_pixels_result2_RBUS measure_total_pixels_result2_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;
	pll27x_reg_sys_dclkss_RBUS sys_dclkss_reg;
	pll27x_reg_dpll_in_fsync_tracking_ctrl_RBUS dpll_in_fsync_tracking_ctrl_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
//poverlay_dclk_sel_RBUS dclk_sel_reg;

	if(SLR_SUB_DISPLAY == display)
		return;

	if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC))
		return;

	//to make sure Dclk is stable
	drv_adjust_spreadspectrumrange(0);

	//USER:LewisLee DATE:2012/07/11
	//to fix measure DV total error
	drvif_scaler_set_display_mode_frc2fsync_by_hw(_TRUE);

	fw_scaler_enable_fs_wdg(display, FALSE);

	fw_scaler_dtg_double_buffer_enable(1);
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _DISABLE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	//display_timing_ctrl1_reg.multiple_dvs = _DISABLE;
	/*WaitFor_DEN_STOP();*/ /*avoid blinking line*/
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	fw_scaler_dtg_double_buffer_apply();

	/*WaitFor_IVS1();*/
	//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);


	framesync_set_iv2dv_delay();

	DOUBLE_DVS_printk("\nDClk = %x\n", IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg));
#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
	framesync_syncDoubleDVS_FLL_Enable_Re_MEASURE:
#endif

	//disable measure
	drvif_measure_total_pixels(_DISABLE);

	msleep(10);

	//enable measure
	drvif_measure_total_pixels(_ENABLE);

	// 3. Get the measure result for last line
	measure_timeout = 0xfff;
	measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

	while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
	{
		if ((_FALSE == WaitFor_IVS1_Done())
			#ifdef CONFIG_DUAL_CHANNEL
			&& (_FALSE == WaitFor_IVS2_Done())
			#endif
			)
			InputSyncLoseCount++;

		if(InputSyncLoseCount >= _DOUBLE_DVS_INPUT_VSYNC_LOST_THRESHOLD)
			goto framesync_syncDoubleDVS_FLL_Enable_Lose_Sync;

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_timeout--;
	}

	if(0 == measure_timeout)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS Last Line Measure timeout\n");
		goto framesync_syncDoubleDVS_FLL_Enable_Lose_Sync;
	}
	else
	{
		DOUBLE_DVS_printk("Double DVS measure_timeout : %x, InputSyncLoseCount : %x\n", measure_timeout, InputSyncLoseCount);

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Get_DISP_HORIZONTAL_TOTAL();
		DOUBLE_DVS_printk( "\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

		measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
		DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Get_DISP_HORIZONTAL_TOTAL();
		DOUBLE_DVS_printk( "\nMeasure second time DV total = %x, last line = %x\n",DVTotal1, DHTotal1);

		DHTotal += DHTotal1;
		DHTotal = DHTotal>>1;
		DOUBLE_DVS_printk("Measure average last line = %x\n",DHTotal);
	}

	if (ABS(Get_DISP_VERTICAL_TOTAL(), DVTotal) > ABS(Get_DISP_VERTICAL_TOTAL(), DVTotal1))
		DVTotal = DVTotal1;

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Scaler_InputSrcGetMainChType()==_SRC_HDMI) && (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING))
	{
		//frame packing mode will double ivs in vgip
	}
	else
    {
			if(0 == (DVTotal % 2))
			{
				DVTotal = DVTotal>>1;
		//		printk("Signal Port DVtotal>>1 !\n");
			}
			else// if(0 != (DVTotal % 2))
			{
				//because measure start by zero, so need add 1 for real value
				DVTotal++;

				DVTotal = DVTotal>>1;
		//		printk("Signal Port DVtotal>>1 !\n");

				//reverse value to start from zero
				DVTotal--;
			}

			if(0 == (DHTotal % 2))
			{
				DHTotal = DHTotal>>1;
		//		printk("Signal Port DVtotal>>1 !\n");
			}
			else// if(0 != (DHTotal % 2))
			{
				//because measure start by zero, so need add 1 for real value
				DHTotal++;

				DHTotal = DHTotal>>1;
		//		printk("Signal Port DVtotal>>1 !\n");

				//reverse value to start from zero
				DHTotal--;
			}
	}
	DOUBLE_DVS_printk("Measure Final line = %x\n", DVTotal);

	if(DVTotal < framesync_get_dvtotal_min())
	{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		DVTotal = (UINT16)framesync_dynamic_adjust_dvtotal_den_relation((UINT32)DVTotal);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		DVTotal = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

		if(DVTotal > Get_DISP_VERTICAL_TOTAL())
			DVTotal = (Get_DISP_VERTICAL_TOTAL() - 1);

		DOUBLE_DVS_printk(" DV total over spec !\n");

#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
		//USER:LewisLee DATE:2012/10/22
		//fix FLL mode, DV total over range, let Vfreq change
		//DV total too small, Set Dh total smaller
		if(_ENABLE == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_Enable_Flag())
		{
			//only execute once
			if(0 == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue())
			{
				ucReMeasureTimes = 0;
				framesync_lastlinefinetune_at_frc_mode_dymanic_adjust_dhtotal(FLL_DYMANIC_ADJUST_DHTOTAL_TO_MIN);
				goto framesync_syncDoubleDVS_FLL_Enable_Re_MEASURE;
			}
		}
#endif //#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
	}
	fw_scaler_dtg_double_buffer_enable(1);

	// 4. Set the DV total
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = DVTotal-1;
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"DVTotal:%x, 8014:%x\n", DVTotal, IoReg_Read32(PPOVERLAY_DV_total_reg));

	// 5. Set F & F - N *dF
	if(DHTotal > _DOUBLE_DVS_FRC_LAST_LINE_PIXEL_OFFSET)
		DHTotal -= _DOUBLE_DVS_FRC_LAST_LINE_PIXEL_OFFSET;
	else
		DHTotal = 1;//avoid 0-1 equal to -1

	/*WaitFor_IVS1();*/
	/*WaitFor_IVS1();*/
	WaitFor_IVS1_Done();

	// enable last line
	dpll_in_fsync_tracking_ctrl_reg.regValue = IoReg_Read32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg);
	dpll_in_fsync_tracking_ctrl_reg.dclk_freq_syn_slt = _DCLK_FREQ_SYN_SLT;
	IoReg_Write32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg, dpll_in_fsync_tracking_ctrl_reg.regValue);


	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	sys_dclkss_reg.dclk_ss_load = 1;
	sys_dclkss_reg.dclk_ss_en = 1;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, sys_dclkss_reg.regValue);


	//USER:LewisLee DATE:2010/07/16
	//for Edward request, let last line pixel is even at picasso platform
	if(DHTotal & _BIT0)
		DHTotal += 1;

	if((Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1)||(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)){
		DHTotal	= (DHTotal | 0x3) +1; //last line total msut 4x

		if(DHTotal <= 0x1d)
			DHTotal = (0x1f + 1);
	}
	// 6. Set display last line
	if(DHTotal > 1)
	{
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
		dh_total_last_line_length_reg.dh_total_last_line = DHTotal - 1;
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	}
	else
	{
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
		dh_total_last_line_length_reg.dh_total_last_line = (DHTotal | _BIT0);
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	}


	// 7. Enable double DVS
	//USER:LewisLee DATE:2012/06/06
	//in new Double DVS rule, if turn on FRC Tracking Framesync
	//will let Double DVS fail, can not create virtual Vsync
#ifdef DOUBLE_DVS_FRC_TRACKING_FRAMESYNC_SOL
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _ENABLE;
	display_timing_ctrl1_reg.disp_fix_last_line = _ENABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _ENABLE;
	display_timing_ctrl1_reg.multiple_dvs = _ENABLE;
#else //#ifdef DOUBLE_DVS_FRC_TRACKING_FRAMESYNC_SOL
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _DISABLE;
	display_timing_ctrl1_reg.disp_fix_last_line = _ENABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _ENABLE;
	//display_timing_ctrl1_reg.multiple_dvs = _ENABLE;
#endif //#ifdef DOUBLE_DVS_FRC_TRACKING_FRAMESYNC_SOL
	/*WaitFor_IVS1();*/
	/*WaitFor_IVS1();*/
	/*WaitFor_DEN_STOP();*/
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	fw_scaler_dtg_double_buffer_apply();
	//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);
	// 8. Enable gamma table switch
	//fs_iv_dv_fine_tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
	//fs_iv_dv_fine_tuning1_reg.gat_sw_en = ENABLE;
	//IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, fs_iv_dv_fine_tuning1_reg.regValue);
	//drvif_db_DVS_setgamma(_MAIN_DISPLAY);

	//disable measure
	drvif_measure_total_pixels(_DISABLE);

	fw_scaler_enable_fs_wdg(display, TRUE);

	framesync_set_enterlastline_at_frc_mode_flg(TRUE);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n framesync_syncDoubleDVS_FLL success\n");
	return;

	framesync_syncDoubleDVS_FLL_Enable_Lose_Sync:
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	//display_timing_ctrl1_reg.multiple_dvs = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL()- 1)& 0x00001fff;
	dh_total_last_line_length_reg.dh_total_last_line = dh_total_last_line_length_reg.dh_total;
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);

	//disable measure
	drvif_measure_total_pixels(_DISABLE);

	fw_scaler_enable_fs_wdg(display , TRUE);

	framesync_set_enterlastline_at_frc_mode_flg(FALSE);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n framesync_syncDoubleDVS_FLL fail\n");
}
//USER:LewisLee DATE:2012/06/06
//it is help Double DVS timing IVS / DVS can sync
void framesync_syncDoubleDVS_Frc_Tracking_Framesync(unsigned char display, unsigned char ucEnable)
{
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;

#ifdef DOUBLE_DVS_FRC_TRACKING_FRAMESYNC_SOL
	return;
#endif //#ifdef DOUBLE_DVS_FRC_TRACKING_FRAMESYNC_SOL

	if(SLR_SUB_DISPLAY == display)
		return;

	if(_DISABLE == modestate_decide_double_dvs_enable())
		return;

	//WaitFor_DEN_STOP_Done();//Remove by Will. Ben Chenck no need
	//WaitFor_DEN_STOP_Done();//Remove by Will. Ben Chenck no need

	if(_ENABLE == ucEnable)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _ENABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}
	else// if(_DISABLE == ucEnable)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _DISABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}
}

#ifdef CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_50HZ
#define _INPUT_VFREQ_CONDITION	24
#define _CONVER_TO_OUTPUT_VFREQ	50
#endif //#ifdef CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_50HZ

#ifdef CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_60HZ
#define _INPUT_VFREQ_CONDITION	24
#define _CONVER_TO_OUTPUT_VFREQ	60
#endif //#ifdef CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_60HZ

#define _INPUT_29HZ_VFREQ_CONDITION_MAX	30
#define _INPUT_29HZ_VFREQ_CONDITION_MIN	28
#define _CONVER_TO_60HZ_OUTPUT_VFREQ	60

//USER:LewisLee DATE:2012/06/25
//customer request, only 1080P25Hz, output Vfreq is 50hz
//other is 60Hz
void framesync_syncDoubleDVS_VfreqConvert(void)
{
#if defined(CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_50HZ) ||defined(CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_60HZ) ||defined(CONFIG_ENABLE_VFREQ_29HZ_CONVER_TO_60HZ)
	dv_total_RBUS dv_total_reg;
	UINT32 IVFreq = 0, DVTotal = 0;

	if(_FALSE == framesync_get_enterlastline_at_frc_mode_flg())
		return;

	IVFreq = Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ);

	if(IVFreq <= (_INPUT_VFREQ_CONDITION*10))
	{
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		DVTotal = dv_total_reg.dv_total + 1;

		DVTotal = DVTotal * (IVFreq<<1) / (_CONVER_TO_OUTPUT_VFREQ*10);

		dv_total_reg.dv_total = DVTotal - 1;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS, Input Vfreq : %x to Output Vfreq : %x\n", IVFreq, (_CONVER_TO_OUTPUT_VFREQ*10));
	}
	else if((IVFreq < (_INPUT_29HZ_VFREQ_CONDITION_MAX*10)) && (IVFreq > (_INPUT_29HZ_VFREQ_CONDITION_MIN*10)))
	{
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		DVTotal = dv_total_reg.dv_total + 1;

		DVTotal = DVTotal * (IVFreq<<1) / (_CONVER_TO_60HZ_OUTPUT_VFREQ*10);

		dv_total_reg.dv_total = DVTotal - 1;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS, Input Vfreq : %x to Output Vfreq : %x\n", IVFreq, (_CONVER_TO_60HZ_OUTPUT_VFREQ*10));
	}
#endif //#if defined(CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_50HZ) ||defined(CONFIG_ENABLE_VFREQ_24HZ_CONVER_TO_60HZ) ||defined(CONFIG_ENABLE_VFREQ_29HZ_CONVER_TO_60HZ)
}

void framesync_syncDoubleDVS(unsigned char display)
{
	framesync_syncDoubleDVS_FLL(display);
	framesync_syncDoubleDVS_VfreqConvert();
}

void framesync_DoubleDvs_Wait_FS_Lock(unsigned char display)
{
#if 0
//#ifdef CONFIG_ENABLE_FRC_TO_FRAMESYNC_BY_HW
	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	UINT32 OriginalMcodeValue = 0;
	UINT32 TimeOutCounterThreshold = 0;
	UINT32 TimeOutCounter = 0;

	TimeOutCounterThreshold = Scaler_Get_DoubleDVS_FreeRun_To_FrameSync_By_HW_WaitLock_TimeOut();

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	while(_FALSE == display_timing_ctrl1_reg.disp_frc_fsync)
	{
		msleep(1);
		TimeOutCounter++;

		if(TimeOutCounter > TimeOutCounterThreshold)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS WL wait timeout......\n");
			break;
		}

		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS WL time count = %d\n",TimeOutCounter);

	if(TimeOutCounter > TimeOutCounterThreshold)
	{
		/*WaitFor_DEN_STOP();*/
		fw_scaler_dtg_double_buffer_enable(1);
		drvif_scaler_set_display_mode_frc2fsync_by_hw(_TRUE);
		fw_scaler_dtg_double_buffer_apply();
		//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS WL LineBufferMode HW set frc2framesync fail, disable it\n");
	}

	return;
#endif //#ifdef CONFIG_ENABLE_FRC_TO_FRAMESYNC_BY_HW
}

// [Code Sync][LewisLee][0990305][1]
void framesync_set_enterlastline_at_frc_mode_flg(unsigned char flg)
{
	framesync_enterlastline_at_frc_mode_flg = flg;
}

unsigned char framesync_get_enterlastline_at_frc_mode_flg(void)
{
	return framesync_enterlastline_at_frc_mode_flg;
}
// [Code Sync][LewisLee][0990305][1][End]

// [Code Sync][LewisLee][0990316][3]
void drvif_measure_total_pixels(unsigned char ucEnable)
{
	ppoverlay_measure_total_pixels_result1_RBUS measure_total_pixels_result1_reg;

	if(_ENABLE == ucEnable)
	{
#ifdef _MEASURE_2FRAME_AT_ONCE
		//Measure two frame at once
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_total_pixels_result1_reg.measure_topixels_mode = _SELECT_MEASURE_MODE;
		measure_total_pixels_result1_reg.measure_topixels_2f = _ENABLE;
		IoReg_Write32(PPOVERLAY_Measure_total_pixels_Result1_reg, measure_total_pixels_result1_reg.regValue);
#else //#ifdef _MEASURE_2FRAME_AT_ONCE
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_total_pixels_result1_reg.measure_topixels_mode = _SELECT_MEASURE_MODE;
		measure_total_pixels_result1_reg.measure_topixels_2f = _DISABLE;
		IoReg_Write32(PPOVERLAY_Measure_total_pixels_Result1_reg, measure_total_pixels_result1_reg.regValue);
#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

		//enable measure
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_total_pixels_result1_reg.measure_topixels_ctr = _ENABLE;
		IoReg_Write32(PPOVERLAY_Measure_total_pixels_Result1_reg, measure_total_pixels_result1_reg.regValue);
	}
	else// if(DISABLE == ucEnable)
	{
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_total_pixels_result1_reg.measure_topixels_ctr = _DISABLE;
		IoReg_Write32(PPOVERLAY_Measure_total_pixels_Result1_reg, measure_total_pixels_result1_reg.regValue);
	}
}
// [Code Sync][LewisLee][0990316][3][End]

void drvif_measure_dvtotal_last_line_pixels(unsigned char ucEnable)
{
	ppoverlay_measure_dvtotal_last_line_pixels_result1_RBUS measure_dvtotal_last_line_pixels_result1_reg;

	if(_ENABLE == ucEnable)
	{
#ifdef _MEASURE_2FRAME_AT_ONCE
		//Measure two frame at once
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_mode	= _SELECT_MEASURE_MODE;
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_2f = _ENABLE;
		IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);
#else //#ifdef _MEASURE_2FRAME_AT_ONCE
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_mode	= _SELECT_MEASURE_MODE;
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_2f = _DISABLE;
		IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);
#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

		//enable measure
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr = _ENABLE;
		IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);
	}
	else// if(DISABLE == ucEnable)
	{
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr = _DISABLE;
		IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);
	}
}

//USER:LewisLee DATE:2010/08/12
//adjust DV total after image show, adjust it slowly
//to fix panel tolerance too samll
#define ADJUST_DVTOTAL_INCREASE	0
#define ADJUST_DVTOTAL_DECREASE	1
FRAMESYNC_ADJUST_DVTOTAL_STATE framesync_lastlinefine_dvtotal_adjust(void)
{
	return FRAMESYNC_ADJUST_DVTOTAL_FINISH;
#if 0
	dv_total_RBUS dv_total_reg;
	static unsigned short Step = 0;
	static unsigned char AdjustDirect = 0;
//mark scalerlib control by qing_liu
//	if(_FALSE == Scaler_Get_SetDVtotal_Later())


	switch(Adjust_Dvtotal_State)
	{
		case FRAMESYNC_ADJUST_DVTOTAL_INITIAL:
			if(OriginalDVTotal > TargetDVTotal)
			{
				Step = OriginalDVTotal - TargetDVTotal;
				AdjustDirect = ADJUST_DVTOTAL_DECREASE;
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_ADJUST;
			}
			else if(TargetDVTotal > OriginalDVTotal)
			{
				Step = TargetDVTotal - OriginalDVTotal;
				AdjustDirect = ADJUST_DVTOTAL_INCREASE;
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_ADJUST;
			}
			else
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;
		break;

		case FRAMESYNC_ADJUST_DVTOTAL_ADJUST:
			if(ADJUST_DVTOTAL_DECREASE == AdjustDirect)
			{
				dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
				dv_total_reg.dv_total -= 1;
				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

				Step--;

				if(0 == Step)
					Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;
			}
			else if(ADJUST_DVTOTAL_INCREASE == AdjustDirect)
			{
				dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
				dv_total_reg.dv_total += 1;
				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

				Step--;

				if(0 == Step)
					Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;
			}
			else
			{
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;
			}
		break;

		case FRAMESYNC_ADJUST_DVTOTAL_NONE:
		case FRAMESYNC_ADJUST_DVTOTAL_FINISH:

		break;
	}

	return Adjust_Dvtotal_State;
#endif
}

/**
* framesync_lastlinefinetune_at_frc_mode
* This function will Finetune last line problem at frc mode
* @param <none>		{ none}
* @return <result>		{ Return _TRUE if there is no timing change}
*/
#define _FRC_LAST_LINE_TIMEOUT_CNT						15
#define _ADJUST_DV_TOTAL_ENABLE							1
//[Code Sync][LewisLee][0990318][1]
#define _FRC_LAST_LINE_PIXEL_OFFSET						4
//[Code Sync][LewisLee][0990318][1]
#define _FRC_LAST_LINE_PIXEL_STEP							1
#define _FRC_LAST_LINE_PIXEL_THRESHOLD					100
#define _FRC_LAST_LINE_DV_TOTAL_FRONT_PORCH_OFFSET		3//LewisLee modify 10//frank@0330 sync with LewisLee 30 is too large
#define _FRC_LAST_LINE_DCLK_AJUST_METHOD2				1
#define _DCLK_OFFSET_DECREASE								0
#define _DCLK_OFFSET_INCREASE								1
// [Code Sync][LewisLee][0990316][1]
#define _INPUT_VSYNC_LOST_THRESHOLD						6

// [Code Sync][LewisLee][0990316][1][End]

#define FRC_FLL_printk(format, args...)
//mark scalerlib control by qing_liu
#if 0
unsigned char framesync_lastlinefinetune_at_frc_mode_algo1(void)
{
	unsigned short DVTotal = 0, DHTotal = 0, DVTotal1 = 0, DHTotal1 = 0;
#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
	unsigned short DHTotal_1st = 0, DclkOffset_step = 0;
	unsigned char JumpFlag = FALSE, AdjustDirect = _DCLK_OFFSET_DECREASE;
#endif //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
	unsigned short DclkOffset, timeout;
	unsigned short measure_timeout = 0, measure_timeout_cnt = 0;
	ppoverlay_fs_iv_dv_fine_tuning1_RBUS tuning1_reg;
	ppoverlay_fs_iv_dv_fine_tuning2_RBUS tuning2_reg;
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS tuning5_reg;
	crt_sys_dclkss_RBUS dclkss_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	ppoverlay_measure_total_pixels_result1_RBUS measure_total_pixels_result1_reg;
	ppoverlay_measure_total_pixels_result2_RBUS measure_total_pixels_result2_reg;
#ifdef _ADJUST_DV_TOTAL_ENABLE
	ppoverlay_dv_total_RBUS dv_total_reg;
#endif //#ifdef _ADJUST_DV_TOTAL_ENABLE
// [Code Sync][LewisLee][0990316][1]
	unsigned char InputSyncLoseCount = 0;
//#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	unsigned char i = 0;
//#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1][End]
	unsigned short Step = 0; //for DV total adjust
	DPLL_ADJUST_MCODE_STATE Mcode_State;

//	framesync_set_enterlastline_at_frc_mode_flg(_FALSE);
	unsigned char display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);

	if ((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) || (SLR_SUB_DISPLAY == display))
		return FALSE;

	if(FALSE == Scaler_EnterFRC_LastLine_Condition())
		return FALSE;

	printk("Enter framesync_lastlinefinetune_at_frc_mode_algo1\n");

	//USER:LewisLee DATE:2012/05/17
	//to prevent Measure Total Pixel Number Overflow
	if(_ENABLE == modestate_decide_double_dvs_enable())
	{
		printk("Double DVS timing, Exit!\n\n");
		return FALSE;
	}

	//to make sure Dclk is stable
	drv_adjust_spreadspectrumrange(0);

	fw_scaler_enable_fs_wdg(display , FALSE);

	//USER:LewisLee Date:2010/08/23
	//we need set correct Dclk for fix last line DV total measure
	if(_TRUE == Scaler_Get_SetDPLL_M_Later())
	{
		i = 0xff;

		do
		{
			WaitFor_DEN_STOP();
			Mcode_State = drvif_clock_dpll_M_adjust();
		}while((DPLL_ADJUST_MCODE_FINISH != Mcode_State)&&(i--));
	}

	tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
	tuning1_reg.iv2dv_toggle_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);

	if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP))
	{
		tuning2_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
		tuning2_reg.iv2dv_pixel = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN);
		tuning2_reg.iv2dv_pixel2 = 0;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, tuning2_reg.regValue);

		tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		//frank@03242011 add below code to set even field iv2dv delay line ++
		tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
		tuning5_reg.iv2dv_line_2 = tuning5_reg.iv2dv_line;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, tuning5_reg.regValue);
		//frank@03242011 add below code to set even field iv2dv delay line --
		tuning1_reg.iv2dv_toggle_en = 1;
		tuning1_reg.iv2dv_toggle_inv = 1;//frank@0403 add this setting for Mac measure correct
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);
	}

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

	msleep(10);

	//enable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_ENABLE);
// [Code Sync][LewisLee][0990316][3][End]

	// Get the measure result for last line
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1]
	if(_MAIN_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if(FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}

	}
	else// if(_SUB_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			//if(FALSE == WaitFor_IVS2())
			//	InputSyncLoseCount++;
		}
	}

	if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
		goto FlxLastLine_Lose_Sync_Algo1;
// [Code Sync][LewisLee][0990316][1][End]
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	measure_timeout = 0xfff;
	measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
	while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
	{
		msleep(40);
		InputSyncLoseCount++;
		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_Algo1;
// [Code Sync][LewisLee][0990316][1][End]

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_timeout--;
	}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

// [Code Sync][LewisLee][0990316][1]
	InputSyncLoseCount = 0;
// [Code Sync][LewisLee][0990316][1][End]

	if(0 == measure_timeout)
	{
		measure_timeout_cnt++;
		FRC_FLL_printk("Last Line Measure timeout : %x\n", measure_timeout_cnt);
	}
	else
	{
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

		DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Get_DISP_HORIZONTAL_TOTAL();
		FRC_FLL_printk( "\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		if (_MAIN_DISPLAY == display)
			WaitFor_IVS1();
		else
			; //WaitFor_IVS2();
		//display ? WaitFor_IVS2() : WaitFor_IVS1();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
		DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Get_DISP_HORIZONTAL_TOTAL();
		FRC_FLL_printk("Measure second time DV total = %x, last line = %x\n", DVTotal1, DHTotal1);

		DHTotal += DHTotal1;
		DHTotal = DHTotal>>1;
		FRC_FLL_printk("Measure average last line = %x\n",DHTotal);

#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

#ifdef _ADJUST_DV_TOTAL_ENABLE
// [Code Sync][LewisLee][0990302][1]
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);

		if(_ENABLE == Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Enable_Flag())
		{
			if(DVTotal > Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Upper())
				DVTotal = Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Upper();
			else if(DVTotal < Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Lower())
				DVTotal = Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Lower();
		}
#if 0  //mark scalerlib control by qing_liu
		if(_TRUE == Scaler_Get_SetDvtotal_Slowly_flag())
		{
			FRC_FLL_printk("dv_total_reg.dv_total = %x\n",dv_total_reg.dv_total);
			OriginalDVTotal = dv_total_reg.dv_total;
			//frank@0330 Sync code
	//			TargetDVTotal = DVTotal - 1;
			TargetDVTotal = DVTotal;
		}
#endif
		//frank@0330 Sync code
//		dv_total_reg.dv_total = DVTotal - 1;
		dv_total_reg.dv_total = DVTotal;

		if(dv_total_reg.dv_total < framesync_get_dvtotal_min())
		{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
			dv_total_reg.dv_total = framesync_dynamic_adjust_dvtotal_den_relation(dv_total_reg.dv_total);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
			dv_total_reg.dv_total = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

			if(dv_total_reg.dv_total > Get_DISP_VERTICAL_TOTAL())
				dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);

			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

			FRC_FLL_printk(" DV total over spec !\n");
		}
		else
		{
		#if 0   //mark scalerlib control by qing_liu
// [Code Sync][LewisLee][0990823][1]
			if(_TRUE == Scaler_Get_SetDVtotal_Later())
			{
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_INITIAL;
			}
			else// if(_FALSE == CustomerSys_Set_DVtotal_Later())
		#endif
			{
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;

			//	if(_FALSE == Scaler_Get_SetDvtotal_Slowly_flag())
				{
//					WaitFor_DEN_STOP();
					IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
				}
			#if 0  //mark scalerlib control by qing_liu
				else
				{
					if(OriginalDVTotal > TargetDVTotal)
					{
						Step = OriginalDVTotal - TargetDVTotal;
						dv_total_reg.dv_total = OriginalDVTotal;
//						WaitFor_DEN_STOP();
//						msleep(20);

						/*while(Step--)
						{
							dv_total_reg.dv_total -= 1;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
							msleep(4); //it can adjust by yourself
						}*/
						while(dv_total_reg.dv_total-TargetDVTotal>10)
						{
							dv_total_reg.dv_total -= 10;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
							msleep(20); //it can adjust by yourself
						}
						if(dv_total_reg.dv_total!=TargetDVTotal)
						{
							dv_total_reg.dv_total = TargetDVTotal;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
						}
					}
					else if(TargetDVTotal > OriginalDVTotal)
					{
						Step = TargetDVTotal - OriginalDVTotal;
						dv_total_reg.dv_total = OriginalDVTotal;

						while(TargetDVTotal-dv_total_reg.dv_total>10)
						{
							dv_total_reg.dv_total += 10;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
							msleep(20); //it can adjust by yourself
						}
						if(dv_total_reg.dv_total!=TargetDVTotal)
						{
							dv_total_reg.dv_total = TargetDVTotal;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
						}
					}
					else
					{
//						WaitFor_DEN_STOP();
						msleep(20);
						IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
					}
				}
			#endif
			}
// [Code Sync][LewisLee][0990823][1][End]
		}
// [Code Sync][LewisLee][0990302][1][End]
#endif //#ifdef _ADJUST_DV_TOTAL_ENABLE

		// Adjust Dclk offset to make last line equal to DH total
		if (DHTotal < _FRC_LAST_LINE_PIXEL_THRESHOLD)
		{
			goto EnableFlxLastLine_At_FRC_Mode_Algo1;
		}
		else if(DHTotal > (Get_DISP_HORIZONTAL_TOTAL() - _FRC_LAST_LINE_PIXEL_THRESHOLD))
		{
			goto EnableFlxLastLine_At_FRC_Mode_Algo1;
		}

#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		DHTotal_1st = DHTotal;
		DclkOffset_step = 0;
		JumpFlag = FALSE;
#endif //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
	}

	// Need to adjust Dclk offset
	FRC_FLL_printk("Need to adjust offset \n");

	//frank@0507 add timeout ask willy
	timeout = _FRC_LAST_LINE_TIMEOUT_CNT;

	while (timeout--)
	{
		//disable measure
// [Code Sync][LewisLee][0990316][3]
		drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		FRC_FLL_printk("Dclk offset data= %x\n", dclkss_reg.dclk_offset_11_0);
		DclkOffset = dclkss_reg.dclk_offset_11_0;//get dclk offset
#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		DHTotal_1st = DHTotal;

		if(0 == DclkOffset_step)
		{
			//first time enter while loop
			if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
				DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
			else
				DclkOffset = 0;
		}
		else if(TRUE == JumpFlag)
		{
			if(_DCLK_OFFSET_DECREASE == AdjustDirect)
			{
				if(DHTotal > (Get_DISP_HORIZONTAL_TOTAL()/2))
				{
					 // remain at same line, keep same action
					if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
						DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
					else
						FRC_FLL_printk("Dclk offset too small@dec\n");
				}
				else // // not jump to next line
				{
					 // jump to next line, do different action
					DclkOffset = DclkOffset + _FRC_LAST_LINE_PIXEL_STEP;
				}
			}
			else// if(_DCLK_OFFSET_INCREASE == AdjustDirect)
			{
				if(DHTotal > (Get_DISP_HORIZONTAL_TOTAL()/2))
				{
					 // jump to front line, do different action
					if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
						DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
					else
						FRC_FLL_printk("Dclk offset too small@inc\n");
				}
				else
				{
					 // remain at same line, keep same action
					DclkOffset = DclkOffset + _FRC_LAST_LINE_PIXEL_STEP;
				}
			}
		}
		else
		{
			//second time enter while loop
			if(_DCLK_OFFSET_DECREASE == AdjustDirect)
			{
				if(DclkOffset >= DclkOffset_step)
					DclkOffset = DclkOffset - DclkOffset_step;
				else if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
					DclkOffset = DclkOffset -_FRC_LAST_LINE_PIXEL_STEP;
				else
					DclkOffset = 0;
			}
			else// if(_DCLK_OFFSET_INCREASE == AdjustDirect)
			{
				DclkOffset = DclkOffset + DclkOffset_step;
			}

			JumpFlag = TRUE;
		}
#else //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
#endif //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2

		if (DclkOffset < 20) // CSW+ 0970327 Add protection for time out
			break;

		FRC_FLL_printk("Dclk offset after adjust = %x\n", DclkOffset);

		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_offset_11_0 = DclkOffset;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

// [Code Sync][LewisLee][0990302][1]
	//	ROS_ENTER_CRITICAL();
//		WaitFor_DEN_STOP(); //<- LewisLee Mask, for speed up fix last line speed
		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_ss_load = 1;
		dclkss_reg.dclk_ss_en = _ENABLE;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);
	//	ROS_EXIT_CRITICAL();
// [Code Sync][LewisLee][0990302][1][End]

		//enable measure
// [Code Sync][LewisLee][0990316][3]
		drvif_measure_total_pixels(_ENABLE);
// [Code Sync][LewisLee][0990316][3][End]

#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1]
		if(_MAIN_DISPLAY == display)
		{
			for(i = 0; i<4; i++)
			{
				if(FALSE == WaitFor_IVS1())
					InputSyncLoseCount++;
			}

		}
		else// if(_SUB_DISPLAY == display)
		{
			for(i = 0; i<4; i++)
			{
				if(FALSE == WaitFor_IVS2())
					InputSyncLoseCount++;
			}
		}

		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_Algo1;
// [Code Sync][LewisLee][0990316][1][End]
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		// Get the measure result for last line
		measure_timeout = 0xfff;
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
		{
			msleep(40);
			InputSyncLoseCount++;
			if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
				goto FlxLastLine_Lose_Sync_Algo1;
// [Code Sync][LewisLee][0990316][1][End]

			measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
			measure_timeout--;
		}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

// [Code Sync][LewisLee][0990316][1]
		InputSyncLoseCount = 0;
// [Code Sync][LewisLee][0990316][1][End]

		if(0 == measure_timeout)
		{
			measure_timeout_cnt++;
			FRC_FLL_printk("Last Line Measure timeout : %x\n", measure_timeout_cnt);
			continue;
		}

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

		DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Get_DISP_HORIZONTAL_TOTAL();
		FRC_FLL_printk("\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		display ? WaitFor_IVS2() : WaitFor_IVS1();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
		DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Get_DISP_HORIZONTAL_TOTAL();
		FRC_FLL_printk("Measure second time DV total = %x, last line = %x\n", DVTotal1, DHTotal1);

		DHTotal += DHTotal1;
		DHTotal = DHTotal >>1;
		FRC_FLL_printk( "Measure average last line = %x\n",DHTotal);
#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

		if ((DHTotal < _FRC_LAST_LINE_PIXEL_THRESHOLD) || (DHTotal > (Get_DISP_HORIZONTAL_TOTAL() - _FRC_LAST_LINE_PIXEL_THRESHOLD)))
		{
			FRC_FLL_printk("adjust offset,  final timeout : %x\n", timeout);

#ifdef _ADJUST_DV_TOTAL_ENABLE
// [Code Sync][LewisLee][0990302][1]
			if(_ENABLE == Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Enable_Flag())
			{
				if(DVTotal > Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Upper())
					DVTotal = Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Upper();
				else if(DVTotal < Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Lower())
					DVTotal = Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Lower();
			}

			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
//			dv_total_reg.dv_total = DVTotal - 1;
			dv_total_reg.dv_total = DVTotal;

			if(dv_total_reg.dv_total < framesync_get_dvtotal_min())
			{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_dynamic_adjust_dvtotal_den_relation(dv_total_reg.dv_total);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

				if(dv_total_reg.dv_total > Get_DISP_VERTICAL_TOTAL())
					dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);

				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

				FRC_FLL_printk(" DV total over spec !\n");
			}
			else
			{
				#if 0  //mark scalerlib control by qing_liu
				if(_TRUE == Scaler_Get_SetDVtotal_Later())
				{
//					TargetDVTotal = DVTotal - 1;
					TargetDVTotal = DVTotal;
				}
				else
				#endif
				{
					IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
				}
			}
// [Code Sync][LewisLee][0990302][1][End]
//			RTD_Log(LOGGER_INFO, "\n PPOVERLAY_DV_total_reg : %x\n", rtdf_inl(PPOVERLAY_DV_total_reg));
#endif //#ifdef _ADJUST_DV_TOTAL_ENABLE

			break;
		}

		if(0 == timeout)
		{
#ifdef _ADJUST_DV_TOTAL_ENABLE
			FRC_FLL_printk( "FRC Measure Last Line Fail\n");
// [Code Sync][LewisLee][0990302][1]
			if(_ENABLE == Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Enable_Flag())
			{
				if(DVTotal > Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Upper())
					DVTotal = Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Upper();
				else if(DVTotal < Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Lower())
					DVTotal = Scaler_Get_EnterFRC_LastLine_DVTotoal_Limit_Lower();
			}

			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
			dv_total_reg.dv_total = DVTotal;

			if(dv_total_reg.dv_total < framesync_get_dvtotal_min())
			{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_dynamic_adjust_dvtotal_den_relation(dv_total_reg.dv_total);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

				if(dv_total_reg.dv_total > Get_DISP_VERTICAL_TOTAL())
					dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);

				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

				FRC_FLL_printk(" DV total over spec !\n");
			}
			else
			{
			#if 0   //mark scalerlib control by qing_liu
				if(_TRUE == Scaler_Get_SetDVtotal_Later())
				{
					TargetDVTotal = DVTotal;
				}
				else
			#endif
				{
					IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
				}
			}
// [Code Sync][LewisLee][0990302][1][End]
#endif //#ifdef _ADJUST_DV_TOTAL_ENABLE
		}
		else
		{
#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
			if(0 == DclkOffset_step)
			{
// [Code Sync][LewisLee][0990603][1]
				//USER:LewisLee DATE:2010/06/03
				//to prevent divide by zero
				if(DHTotal == DHTotal_1st)
				{
					if(DHTotal >= (Get_DISP_HORIZONTAL_TOTAL()/2))
						AdjustDirect = _DCLK_OFFSET_DECREASE;
					else
						AdjustDirect = _DCLK_OFFSET_INCREASE;

					DclkOffset_step = _FRC_LAST_LINE_PIXEL_STEP<<1;
				}
				else
				{
					if(DHTotal >= (Get_DISP_HORIZONTAL_TOTAL()/2))
					{
						AdjustDirect = _DCLK_OFFSET_DECREASE;
						DclkOffset_step = _FRC_LAST_LINE_PIXEL_STEP*(Get_DISP_HORIZONTAL_TOTAL() - DHTotal + _FRC_LAST_LINE_PIXEL_THRESHOLD/2)/ABS(DHTotal, DHTotal_1st);
					}
					else
					{
						AdjustDirect = _DCLK_OFFSET_INCREASE;
						DclkOffset_step = (_FRC_LAST_LINE_PIXEL_STEP*(DHTotal - _FRC_LAST_LINE_PIXEL_THRESHOLD))/ABS(DHTotal, DHTotal_1st);
					}
				}
// [Code Sync][LewisLee][0990603][1][End]
			}
#endif //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		}

	}

	EnableFlxLastLine_At_FRC_Mode_Algo1:

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_freq_syn_slt = 0x2f;
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

//[Code Sync][LewisLee][0990318][1]
	if(DHTotal > (_FRC_LAST_LINE_PIXEL_OFFSET + Scaler_Get_EnterFRC_LastLine_LastLinePixel_Offset()))
		DHTotal -= _FRC_LAST_LINE_PIXEL_OFFSET;
	else
		DHTotal = 1 + Scaler_Get_EnterFRC_LastLine_LastLinePixel_Offset();//avoid 0-1 equal to -1

//#ifdef CONFIG_PICASSO_CONNECT_UART
	//USER:LewisLee DATE:2010/07/16
	//for Edward request, let last line pixel is even at picasso platform
	if(DHTotal & _BIT0)
		DHTotal += 1;
//#endif //#ifdef CONFIG_PICASSO_CONNECT_UART

	// Setting value = ( real value -1) , Min. value 90
	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = DHTotal&(~(_BIT0|_BIT1));
#endif
	dh_total_last_line_length_reg.dh_total_last_line = DHTotal - 1;
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
//[Code Sync][LewisLee][0990318][1][End]

	//step 9, Enable F and F-NdF switch
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_new_en = _DISABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	framesync_set_enterlastline_at_frc_mode_flg(TRUE);

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]
	fw_scaler_enable_fs_wdg(display , TRUE);

	return TRUE;

// [Code Sync][LewisLee][0990316][1]
	FlxLastLine_Lose_Sync_Algo1:
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	framesync_set_enterlastline_at_frc_mode_flg(FALSE);

#ifdef _ADJUST_DV_TOTAL_ENABLE
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
#endif //#ifdef _ADJUST_DV_TOTAL_ENABLE

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]
	fw_scaler_enable_fs_wdg(display , TRUE);

	return FALSE;
// [Code Sync][LewisLee][0990316][1][End]
}

#define _FRC_DV_TOTAL_OFFSET		1
#define _FRC_LASTLINE_N_OFFSET	2
#define _FRC_LASTLINE_N_MAX		64

unsigned char framesync_lastlinefinetune_at_frc_mode_algo2(void)
{
	unsigned short DVTotal = 0, DHTotal = 0, DVTotal1 = 0, DHTotal1 = 0;
	unsigned short DclkOffset = 0;
	unsigned short measure_timeout = 0;
	unsigned int DPLL_Freq = 0, Dclk_std = 0;
	unsigned char N_value = 0;
	crt_sys_pll_disp1_RBUS pll_disp1_reg;
	crt_sys_pll_disp2_RBUS pll_disp2_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	ppoverlay_fs_iv_dv_fine_tuning1_RBUS tuning1_reg;
	ppoverlay_fs_iv_dv_fine_tuning2_RBUS tuning2_reg;
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS tuning5_reg;
	crt_sys_dclkss_RBUS dclkss_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	ppoverlay_measure_total_pixels_result1_RBUS measure_total_pixels_result1_reg;
	ppoverlay_measure_total_pixels_result2_RBUS measure_total_pixels_result2_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;
	unsigned char InputSyncLoseCount = 0;
//#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	unsigned char i = 0;
//#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	DPLL_ADJUST_MCODE_STATE Mcode_State;

//	framesync_set_enterlastline_at_frc_mode_flg(_FALSE);

	unsigned short display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	if ((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) || (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY))
		return FALSE;

	if(FALSE == Scaler_EnterFRC_LastLine_Condition())
		return FALSE;

	printk("Enter framesync_lastlinefinetune_at_frc_mode_algo2\n");

	//USER:LewisLee DATE:2012/05/17
	//to prevent Measure Total Pixel Number Overflow
	if(_ENABLE == modestate_decide_double_dvs_enable())
	{
		printk("Double DVS timing, Exit!\n\n");
		return FALSE;
	}

	//to make sure Dclk is stable
	drv_adjust_spreadspectrumrange(0);

	fw_scaler_enable_fs_wdg(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) , FALSE);

	//USER:LewisLee Date:2010/08/23
	//we need set correct Dclk for fix last line DV total measure
	if(_TRUE == Scaler_Get_SetDPLL_M_Later())
	{
		i = 0xff;

		do
		{
			WaitFor_DEN_STOP( );
			Mcode_State = drvif_clock_dpll_M_adjust();

		}while((DPLL_ADJUST_MCODE_FINISH != Mcode_State)&&(i--));
	}

	tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
	tuning1_reg.iv2dv_toggle_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);

	if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP))
	{
		tuning2_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
		tuning2_reg.iv2dv_pixel = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN);
		tuning2_reg.iv2dv_pixel2 = 0;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, tuning2_reg.regValue);

		tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		//frank@03242011 add below code to set even field iv2dv delay line ++
		tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
		tuning5_reg.iv2dv_line_2 = tuning5_reg.iv2dv_line;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, tuning5_reg.regValue);
		//frank@03242011 add below code to set even field iv2dv delay line --
		tuning1_reg.iv2dv_toggle_en = 1;
		tuning1_reg.iv2dv_toggle_inv = 1;//frank@0403 add this setting for Mac measure correct
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);
	}

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

	//calculate original Dclock
	//DPLL_Freq = Crystal * (M/N) * (1/div) * (1/2)
	pll_disp1_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	pll_disp2_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_VADDR);
	DPLL_Freq = (unsigned int)((unsigned long long)((CONFIG_CPU_XTAL_FREQ)*(pll_disp1_reg.dpll_m + 2)/(pll_disp1_reg.dpll_n + 2))/(2*(1<<pll_disp2_reg.dpll_o)));
	printk("M:%x, div:%x, N:%x, DPLL_Freq:%x\n", (pll_disp1_reg.dpll_m + 2),
		(1<<pll_disp2_reg.dpll_o), (pll_disp1_reg.dpll_n + 2), DPLL_Freq);

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_VADDR);
	DclkOffset = dclkss_reg.dclk_offset_11_0;//get dclk offset
	//Dclk_std = DPLL_Freq*(1 - (Dclk_offset/2^15))
	Dclk_std = DPLL_Freq - (unsigned int)((unsigned long long)(DPLL_Freq*DclkOffset)>>15);
	printk("Dclk offset data:%x, Dclk_std:%x\n", dclkss_reg.dclk_offset_11_0, Dclk_std);

// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_ENABLE);
// [Code Sync][LewisLee][0990316][3][End]

	// Get the measure result for last line
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	if(SLR_MAIN_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if(FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}

	}
	else// if(_SUB_DISPLAY == info->display)
	{
		for(i = 0; i<4; i++)
		{
			//if(FALSE == WaitFor_IVS2())
			//	InputSyncLoseCount++;
		}
	}

	if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
		goto FlxLastLine_Lose_Sync_Algo2;
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	measure_timeout = 0xfff;
	measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
	while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
	{

		if(SLR_MAIN_DISPLAY == display)
		{
			if(FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}

		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_Algo2;

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_timeout--;
	}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

	InputSyncLoseCount = 0;

	if(0 == measure_timeout)
		goto FlxLastLine_Lose_Sync_Algo2;

	measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

	DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Get_DISP_HORIZONTAL_TOTAL();
	DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Get_DISP_HORIZONTAL_TOTAL();
	printk("\nMeasure first time DV total = %x, last line = %x\n", DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	display ? WaitFor_IVS2() : WaitFor_IVS1();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

	measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
	DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Get_DISP_HORIZONTAL_TOTAL();
	DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Get_DISP_HORIZONTAL_TOTAL();
	printk("Measure second time DV total = %x, last line = %x\n", DVTotal1, DHTotal1);

	DHTotal += DHTotal1;
	DHTotal = DHTotal>>1;

	DVTotal += DVTotal1;
	DVTotal = DVTotal>>1;
	printk("Measure DVTotal = %x, average last line = %x\n",DVTotal, DHTotal);
#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

	//set Dclk_slow
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = (DVTotal + _FRC_DV_TOTAL_OFFSET) - 1;
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	// Setting value = ( real value -1) , Min. value 90
	if(DHTotal > _FRC_LAST_LINE_PIXEL_THRESHOLD)
	{
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
		dh_total_last_line_length_reg.dh_total_last_line = _FRC_LAST_LINE_PIXEL_THRESHOLD - 1;
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);

		//Frequency Synthesis Select, F & F-N*dF
		// N_value >= (2^15 - DclkOffset)*(DHTotal + _FRC_LAST_LINE_PIXEL_THRESHOLD - last line pixel)/(DVTotal*DHTotal + last line pixel)
		N_value = (unsigned char)((unsigned long long)(32768 - DclkOffset)*(Get_DISP_HORIZONTAL_TOTAL() + _FRC_LAST_LINE_PIXEL_THRESHOLD - DHTotal)/(DVTotal*Get_DISP_HORIZONTAL_TOTAL() + DHTotal));
		printk("1. N_value = %x\n", N_value);
	}
	else
	{
		//last line pixel need as even
		if(DHTotal & _BIT0)
			DHTotal += 1;

		if(DHTotal > 1)
		{
			dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
			dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = DHTotal&(~(_BIT0|_BIT1));
#endif
			dh_total_last_line_length_reg.dh_total_last_line = DHTotal - 1;
			IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
		}
		else
		{
			dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
			dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = (DHTotal&(~(_BIT0|_BIT1))) - 1 + 4;
#endif
			dh_total_last_line_length_reg.dh_total_last_line = (DHTotal | _BIT0);
			IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
		}

		//Frequency Synthesis Select, F & F-N*dF
		// N_value >= (2^15 - DclkOffset)*(DHTotal + _FRC_LAST_LINE_PIXEL_THRESHOLD - last line pixel)/(DVTotal*DHTotal + last line pixel)
		N_value = (unsigned char)((unsigned long long)(32768 - DclkOffset)*Get_DISP_HORIZONTAL_TOTAL()/(DVTotal*Get_DISP_HORIZONTAL_TOTAL() + DHTotal));
		printk("2. N_value = %x\n", N_value);
	}

	if((N_value + _FRC_LASTLINE_N_OFFSET) < _FRC_LASTLINE_N_MAX)
		N_value = N_value + _FRC_LASTLINE_N_OFFSET;
	else if(0 == N_value)
		N_value++; //it is abnoraml case
	else
		N_value = _FRC_LASTLINE_N_MAX; //it is abnoraml case

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_VADDR);
//	dclkss_reg.dclk_freq_syn_slt = 0x2f;
	dclkss_reg.dclk_freq_syn_slt = N_value - 1;
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP2_VADDR, dclkss_reg.regValue);

	//step 9, Enable F and F-NdF switch
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_VADDR);
	dclkss_reg.dclk_new_en = _DISABLE;
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP2_VADDR, dclkss_reg.regValue);

// [Code Sync][LewisLee][0990705][1]
	//USER:LewisLee DATE:2010/07/05
	//let fix last line and framesync bit set at same time
	//to prevent TV change channel unstable
/*
	if(_ENABLE == display_timing_ctrl1_reg.disp_fsync_en)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_fix_last_line = _ENABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}
	else
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}
*/
// [Code Sync][LewisLee][0990705][1][End]

	framesync_set_enterlastline_at_frc_mode_flg(TRUE);

	//disable measure
	drvif_measure_total_pixels(_DISABLE);

	return TRUE;

	FlxLastLine_Lose_Sync_Algo2:
	printk("Sync Lose at FRC LastLine\n");

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	framesync_set_enterlastline_at_frc_mode_flg(FALSE);

	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	//disable measure
	drvif_measure_total_pixels(_DISABLE);

	return FALSE;
}
#endif
unsigned int framesync_lastlinefinetune_at_frc_mode_get_dhtotal_value(void)
{//mark scalerlib control by qing_liu
//	if(_DISABLE == Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag())
		return Get_DISP_HORIZONTAL_TOTAL();

//	return framesync_lastlinefinetune_at_frc_mode_DHtotal;
}

void framesync_lastlinefinetune_at_frc_mode_modify_dhtotal_value(unsigned char reset)
{//mark scalerlib control by qing_liu
//	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	//UINT32 DH_total_Temp = 0;

	//If not allow adjust DH total, we don't need to do anything
//	if(_DISABLE == Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag())
		return ;//Get_DISP_HORIZONTAL_TOTAL();
#if 0  //mark scalerlib control by qing_liu
	//In reset mode, we need set it to default value
	if(_TRUE == reset)
	{
		// It Will reset At scalerdisplay_set_timing()

		framesync_lastlinefinetune_at_frc_mode_DHtotal = Get_DISP_HORIZONTAL_TOTAL();
		return;
	}

	switch(drvif_get_dclk_margin_check_result())
	{
		case DCLK_OVER_RANGE:
			framesync_lastlinefinetune_at_frc_mode_DHtotal = Get_DISP_DEN_END_HPOS() + Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Over_OffsetValue();

			//to prevent large than original value
			if(framesync_lastlinefinetune_at_frc_mode_DHtotal >= Get_DISP_HORIZONTAL_TOTAL())
			{
				framesync_lastlinefinetune_at_frc_mode_DHtotal = Get_DISP_HORIZONTAL_TOTAL() + Get_DISP_DEN_END_HPOS();
				framesync_lastlinefinetune_at_frc_mode_DHtotal = framesync_lastlinefinetune_at_frc_mode_DHtotal>>1;
			}

			printk("DCLK_OVER_RANGE : %x\n", framesync_lastlinefinetune_at_frc_mode_DHtotal);
		break;

		case DCLK_UNDER_RANGE:
			framesync_lastlinefinetune_at_frc_mode_DHtotal = Get_DISP_HORIZONTAL_TOTAL() + Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Under_OffsetValue();

			printk("DCLK_UNDER_RANGE : %x\n", framesync_lastlinefinetune_at_frc_mode_DHtotal);
		break;

		default:
//		case DCLK_IN_RANGE:
			framesync_lastlinefinetune_at_frc_mode_DHtotal = Get_DISP_HORIZONTAL_TOTAL();

			printk("DCLK_IN_RANGE : %x\n", framesync_lastlinefinetune_at_frc_mode_DHtotal);
		break;

	}

//	return DH_total_Temp;
	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total_last_line_length_reg.dh_total = framesync_lastlinefinetune_at_frc_mode_DHtotal - 1;
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
#endif
}

//USER:LewisLee DATE:2012/10/22
//fix FLL mode, DV total over range, let Vfreq change
void framesync_lastlinefinetune_at_frc_mode_dymanic_adjust_dhtotal(FLL_ADJUST_DVTOTAL_STATE state)
{
#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
	ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;
	UINT32 DhTotalMin = 0;

	switch(state)
	{
		case FLL_DYMANIC_ADJUST_DHTOTAL_TO_MAX:
			Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue(Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MaxValue());
			scalerdisplay_set_dh_total(_TRUE);
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"FLL_DYMANIC_ADJUST_DHTOTAL_TO_MAX : %x\n", Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MaxValue());
		break;
		case FLL_DYMANIC_ADJUST_DHTOTAL_TO_MIN:
			dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);

			if(Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MinValue() >=
				(dh_den_start_end_reg.dh_den_end +Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_FrontPorchOffset()))
			{
				//Safe Region
				DhTotalMin = Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MinValue();
			}
			else
			{
				DhTotalMin = (dh_den_start_end_reg.dh_den_end +Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_FrontPorchOffset());
			}

			Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue(DhTotalMin);

			scalerdisplay_set_dh_total(_TRUE);
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"FLL_DYMANIC_ADJUST_DHTOTAL_TO_MIN : %x, DhTotalMin : %x\n",
				Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_MinValue(), DhTotalMin);
		break;

		case FLL_DYMANIC_ADJUST_DHTOTAL_NONE:
		default:
			Scaler_Set_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue(0);
		break;
	}
#endif //#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
}

//#define XTAL_FREQ 27000000
//#define IVS_DVS_THRESHOLD 0x100
//#define IVS_XTAL_CNT  1
//#define IVS_XTAL_CNT2 2
//#define DVS_XTAL_CNT  3

void framesync_wait_vdc_stable()
{
	UINT8 cnt=0;
	unsigned char timeout = 10;
	unsigned short VHalfTotal = 0;
	unsigned char ucNoSignal = 0, ucVState = 0, ucVHalfTotalRet = 0;
	unsigned char mode= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);

	if((Scaler_InputSrcGetMainChType() == _SRC_TV) || (Scaler_InputSrcGetMainChType() == _SRC_CVBS))
	{
		down(get_avd_power_semaphore());
		if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
		{
			ucNoSignal = drvif_video_status_reg(VDC_no_signal);
			ucVState = drvif_module_vdc_Read_Vstate();
		}
		up(get_avd_power_semaphore());

		//if(drvif_video_status_reg(VDC_no_signal))
		if(ucNoSignal)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VD no signal \n");
			return;
		}

		//while((drvif_module_vdc_Read_Vstate() != 3) && (++cnt <10)){
		while((ucVState != 3) && (++cnt <10)){

			//printk("###### drvif_module_vdc_Read_Vstate:%d , cnt (%d) ######\n", drvif_module_vdc_Read_Vstate(), cnt);


			//  unsigned short VHalfTotal;
	      //          unsigned char mode = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	  		timeout = 10;

			while(--timeout){
		              mode = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);

			down(get_avd_power_semaphore());
			if(get_AVD_Global_Status() == SRC_CONNECT_DONE)
			{
				ucVHalfTotalRet = drvif_module_vdc_GetVHalfTotalLen(&VHalfTotal) ;
				ucVState = drvif_module_vdc_Read_Vstate();
			}
			up(get_avd_power_semaphore());


				//if ( drvif_module_vdc_GetVHalfTotalLen(&VHalfTotal) )
			 if (ucVHalfTotalRet)
		              {
			               if (((mode==_MODE_480I)&&((VHalfTotal==263)||(VHalfTotal==262))) ||
			               ((mode==_MODE_576I)&&((VHalfTotal==313)||(VHalfTotal==312))))
			               {
			                   //表示穩定了
	                 		     //printk("drvif_module_vdc_GetVHalfTotalLen : check ok!\n");
			                  return;
			               }
				}
				msleep(50);
			}

		      if(timeout == 0){
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[framesync_wait_vdc_stable]check error, timeout !\n");
		      }
			msleep(200);
		}
	}

}
unsigned int framesync_generate_ivscnt_for_tv_nosignal(UINT32 xtal_cnt)
{
	UINT32 result = 0;

	if(Scaler_InputSrcGetMainChType() == _SRC_TV){
/*
		if((xtal_cnt > 0x66FF3) && (xtal_cnt < 0x75B5E)){	// 56Hz ~ 64Hz
			printk("## TV source resotre to NTSC format ##\n");
			result = 0x0006DF91;
		}else if ((xtal_cnt > 0x7A120) && (xtal_cnt < 0x8F4CC)){	// 46Hz ~ 54Hz
			printk("## TV source resotre to PAL format ##\n");
			result = 0x83D60;
		}else{
			printk("## TV source resotre to NTSC format ##\n");
			result = 0x0006DF91;
		}
*/
		// due to ivs_cnt of atv no signal is unstable, we use off-line measure result to give a standard ivs_cnt
		// for speed up fix last line algo.
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"## TV No Signal : cnt = %d ##\n", xtal_cnt);

		if(ABS(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_INPUT_V_FREQ),500) < 30)
			result = 0x83D60;	// framerate 50Hz ivs_cnt : 27000000/50 = 0x83D60;
		else
			result = 0x6DF91;	// framerate 60Hz ivs_cnt : 27000000/60 = 0x6DF91;


	}
	return result;
}

#define TIMEOUT_COUNT 10
UINT32 framesync_new_fixlastline_get_stable_xtal_cnt(UINT8 type)
{
	UINT8 cnt = 0;
	UINT8 loop_timeout = TIMEOUT_COUNT;
	UINT32 xtal_cnt = 0;
	static UINT32 xtal_cnt_previous=0;
	UINT32 xtal_cnt_avg = 0;

	//printk("initial 0xb801975c[1:0] : %x \n", (vdcf_inl(0xb801975c)&0x3));
	//printk("\n 0xb8019008:%x  \n", vdcf_inl(0xb8019008));
	IoReg_Mask32(PPOVERLAY_IVS_cnt_1_reg, ~(_BIT27), _BIT27);

	do
	{
		if(type ==IVS_XTAL_CNT)
			 xtal_cnt = (IoReg_Read32(PPOVERLAY_IVS_cnt_1_reg) & 0xffffff);
		else if(type ==IVS_XTAL_CNT2)
			 xtal_cnt = (IoReg_Read32(PPOVERLAY_IVS_cnt_2_reg) & 0xffffff);
		else if(type ==DVS_XTAL_CNT)
			 xtal_cnt = (IoReg_Read32(PPOVERLAY_DVS_cnt_reg) & 0xffffff);

		xtal_cnt_avg += xtal_cnt;

		if(ABS(xtal_cnt_previous, xtal_cnt) < 0x0A){
			cnt++;
		}else{ //unstable
			xtal_cnt_previous = xtal_cnt;
			cnt = 0;
		}

		if(cnt >= 5){
			break;
		}

		//tv no signal, doesn't need measure.
		if((Scaler_InputSrcGetMainChType() == _SRC_TV)&&(drvif_video_status_reg(VDC_no_signal))){
			return framesync_generate_ivscnt_for_tv_nosignal(xtal_cnt);
		}

		// modify as wait ivs start, later
		msleep(20);
		//WaitFor_DEN_STOP_Done();

	}while(--loop_timeout);

	if(loop_timeout == 0){
		xtal_cnt = xtal_cnt_avg / TIMEOUT_COUNT;
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"!!unstable!! Use average xtal_cnt : %x , type (%d)\n", xtal_cnt, type);
	}


	return xtal_cnt;
}

#ifdef NEW_FLL_METHOD
////////////////////////////////////////////////////////////////////////////////////
#define NEW_FLL_printk(format, args...) 	pr_debug(format, ##args)
//#define NEW_FLL_printk(format, args...)

unsigned int framesync_new_fixlastline_check_vtotal_boundary(unsigned int vtotal);

unsigned char framesync_new_fixlastline_set_locked_threashold(unsigned short threshold_val)
{
	ppoverlay_dvs_phase_error_set_RBUS dvs_phase_error_set_reg;

	// set threa
	dvs_phase_error_set_reg.regValue = IoReg_Read32(PPOVERLAY_dvs_phase_error_set_reg);
	dvs_phase_error_set_reg.old_fll_unlocked_th = threshold_val;
	IoReg_Write32(PPOVERLAY_dvs_phase_error_set_reg, dvs_phase_error_set_reg.regValue);

	return 1;
}

unsigned char framesync_new_fixlastline_threashold_check_enable(unsigned char bEnable)
{
	measure_two_dvs_phase_error_result_RBUS measure_two_dvs_phase_error_result_reg;

	measure_two_dvs_phase_error_result_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_two_dvs_phase_error_Result_reg);
	measure_two_dvs_phase_error_result_reg.two_dvs_phase_error_cntr = bEnable;
	IoReg_Write32(PPOVERLAY_Measure_two_dvs_phase_error_Result_reg, measure_two_dvs_phase_error_result_reg.regValue);
	msleep(50);
	IoReg_Write32(PPOVERLAY_DTG_no_ie_pending_status_reg, 0x1);	//wclr pending status

	return 1;
}

unsigned char framesync_new_fixlastline_check_locked_status(void)
{
	UINT8 result = FALSE;

	result = (IoReg_Read32(PPOVERLAY_DTG_no_ie_pending_status_reg) & _BIT0)?FALSE:TRUE ;

	return result;
}

UINT32 framesync_new_fixlastline_finetune_by_vtotal()
{
	unsigned char cnt = 10;
	unsigned int ivs_cnt=0;
	unsigned int dvs_cnt=0;
	unsigned int vtotal_tmp=0;
	ppoverlay_dv_total_RBUS dv_total_reg;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"enter framesync_new_fixlastline_finetune_by_vtotal\n");

	do{
		ivs_cnt = framesync_new_fixlastline_get_stable_xtal_cnt(IVS_XTAL_CNT);
		dvs_cnt = framesync_new_fixlastline_get_stable_xtal_cnt(DVS_XTAL_CNT);
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		vtotal_tmp = dv_total_reg.dv_total;

		cnt--;

		if(modestate_decide_double_dvs_enable() == _ENABLE){
			NEW_FLL_printk("Double DVS enable!! ivs cnt /2 \n");
			ivs_cnt /= 2;
		}

		NEW_FLL_printk("(cnt: %d) ivs_cnt = %x, dvs_cnt = %x, ABS(ivs,dvs) = %x, vtotal = %x \n", cnt, ivs_cnt, dvs_cnt, ABS(ivs_cnt,dvs_cnt), dv_total_reg.regValue);

		if(ABS(ivs_cnt, dvs_cnt) < 0x100){
			if((dvs_cnt > ivs_cnt) || (ABS(ivs_cnt, dvs_cnt) < 0x10)){
				dv_total_reg.dv_total--;	//let ivs_cnt little large than dvs_cnt
				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
			}
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"final vtotal:%x \n", dv_total_reg.dv_total);
			break;
		}else{
			if(dvs_cnt > ivs_cnt)
				dv_total_reg.dv_total--;
			else
				dv_total_reg.dv_total++;
		}

		dv_total_reg.dv_total = framesync_new_fixlastline_check_vtotal_boundary(dv_total_reg.dv_total);
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
		msleep(50);

		if(ABS(ivs_cnt, dvs_cnt) > 0x2000){
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE," !!!!!!! measure error above 0x2000, retry it ...  !!!!!!!!! \n");
			return 0;
		}

	}while((ABS(ivs_cnt, dvs_cnt) >= 0x100) && (cnt != 0));


	if(cnt== 0){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s][line:%d] !!!!!!! measure error !!!!!!!!! \n", __FUNCTION__, __LINE__);
		dv_total_reg.dv_total = vtotal_tmp;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
	}
	else
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s][line:%d] !!!!!!! measure done !!!!!!!!! \n", __FUNCTION__, __LINE__);

	return 1;
}

#define ERR_OVERFLOW 1
#define ERR_UNDERFLOW 2

UINT32 framesync_new_fixlastline_finetune_step_dclk_M_code(UINT8 bIncrease)
{
	unsigned int dclkVal=0;
	unsigned int M_Code=0;
	unsigned int N_Code=0;
	unsigned int dclkOffset=0;
	unsigned int temp=0;

	dclkVal = scalerdisplay_get_dclk()/10000;

	pll_disp1_RBUS pll_disp1_reg;
	pll_disp1_reg.regValue =  IoReg_Read32(SYSTEM_PLL_DISP1_VADDR);
	M_Code = pll_disp1_reg.dpll_m;
	N_Code = pll_disp1_reg.dpll_n;

	dclk_sel_RBUS dclk_sel_reg;
	dclk_sel_reg.regValue = IoReg_Read32(PPOVERLAY_DCLK_SEL_VADDR);

	NEW_FLL_printk("dclkVal:%d, M_Code:%x, N_Code:%x\n", dclkVal, M_Code, N_Code);

	if(bIncrease)
		M_Code++;
	else
		M_Code--;

	temp = ((32768*dclkVal*(N_Code+2)*(dclk_sel_reg.dclk_sel+1)) /(2700*(M_Code+2)));

	NEW_FLL_printk("temp : %x \n", temp);

	dclkOffset = (32768 - temp);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"+++ M_Code : %x, dclkOffset : %x \n", M_Code, dclkOffset);


	pll_disp1_reg.dpll_m = M_Code;
	IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, pll_disp1_reg.regValue);
	drvif_clock_offset(dclkOffset);
	msleep(50);
}

UINT32 framesync_new_fixlastline_finetune_by_dclk_offset()
{
	unsigned char cnt = 10;
	unsigned int ivs_cnt=0;
	unsigned int dvs_cnt=0;
	static unsigned int dvs_cnt_pre=0;
	unsigned int dvs_diff=0;
	unsigned int nFactor=0;
	unsigned int dclkVal=0;
	unsigned int dclkOffset=0;
	unsigned char dclkOffsetStep = 0x8;
	pll27x_reg_sys_dclkss_RBUS dclkss_reg;
	UINT8 bSpeedUp = 1;
	UINT8 bErrorStatus = 0;


	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"enter framesync_new_fixlastline_finetune_by_dclk_offset\n");

	if(Scaler_Get_New_FLL_Alog_With_FixDclk() == TRUE){	//Fix Dclk cant dynamic tuning dclk, so skip step4
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Fix dclk can't tuning dclk, return.\n");
		return 0;
	}

	do{
		ivs_cnt = framesync_new_fixlastline_get_stable_xtal_cnt(IVS_XTAL_CNT);
		dvs_cnt = framesync_new_fixlastline_get_stable_xtal_cnt(DVS_XTAL_CNT);
		dclkVal = scalerdisplay_get_dclk();
		dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
		dclkOffset = dclkss_reg.dclk_offset_11_0;

		cnt--;

		if(modestate_decide_double_dvs_enable() == _ENABLE){
			NEW_FLL_printk("Double DVS enable!! ivs cnt /2 \n");
			ivs_cnt /= 2;
		}

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"(cnt: %d) ivs_cnt = %x, dvs_cnt = %x, ABS(ivs,dvs) = %x, dclkOffset:%x, dclkVal = %d \n", cnt, ivs_cnt, dvs_cnt, ABS(ivs_cnt,dvs_cnt), dclkOffset, dclkVal);

		if(ABS(ivs_cnt, dvs_cnt) < 0x100){
			if((dvs_cnt > ivs_cnt) || (ABS(ivs_cnt, dvs_cnt) < 0x10)){
				dclkOffset -= dclkOffsetStep;	//let ivs_cnt little large than dvs_cnt
				dclkss_reg.dclk_offset_11_0 = dclkOffset;
				dclkss_reg.dclk_ss_load = 1;
				dclkss_reg.dclk_ss_en = _ENABLE;
				IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);
			}
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"final dclkOffset:%x \n", dclkOffset);
			break;
		}else{

			/*=== due to step a dclkoffset, we can get stable dvs cnt difference. ===*/
			/*===  we can use this rule for speed up dclk to acheive real offset  ===*/

			if(ABS(ivs_cnt, dvs_cnt) > 0x200){
				bSpeedUp = 1;
			}
			NEW_FLL_printk("bSpeedUp:%d \n", bSpeedUp);

			if(bSpeedUp == 1){ // for speed up
				if(dvs_cnt_pre != 0){
					dvs_diff = ABS(dvs_cnt_pre, dvs_cnt);
				}
				if(dvs_diff != 0){
					nFactor = (ABS(ivs_cnt, dvs_cnt) / dvs_diff);
				}
				dvs_cnt_pre = dvs_cnt;

				NEW_FLL_printk("nFactor:%d \n", nFactor);

				if(nFactor == 0){
					if(dvs_cnt > ivs_cnt){
						if(dclkOffsetStep > dclkOffset)
							bErrorStatus = ERR_UNDERFLOW;
						else
							dclkOffset -= dclkOffsetStep;
					}
					else{
						if( dclkOffset + dclkOffsetStep > 0xf00)
							bErrorStatus = ERR_OVERFLOW;
						else
							dclkOffset += dclkOffsetStep;
					}
				}else{
					if(dvs_cnt > ivs_cnt){
						if((nFactor*dclkOffsetStep) > dclkOffset)
							bErrorStatus = ERR_UNDERFLOW;
						else
							dclkOffset -= (nFactor*dclkOffsetStep);
					}
					else{
						if( dclkOffset + (nFactor*dclkOffsetStep) > 0xf00)
							bErrorStatus = ERR_OVERFLOW;
						else
							dclkOffset += (nFactor*dclkOffsetStep);
					}
					bSpeedUp = 0;
					dvs_cnt_pre = 0;
				}
			}
			else{
				if(dvs_cnt > ivs_cnt){
					if(dclkOffsetStep > dclkOffset)
						bErrorStatus = ERR_UNDERFLOW;
					else
						dclkOffset -= dclkOffsetStep;
				}
				else{
					if( dclkOffset + dclkOffsetStep > 0xf00)
						bErrorStatus = ERR_OVERFLOW;
					else
						dclkOffset += dclkOffsetStep;
				}
			}
		}

		drvif_clock_offset(dclkOffset);
		msleep(50);

		NEW_FLL_printk("dvs_diff : %d, nFactor : %d, dclkOffset:%x, bErrorStatus:%d \n", dvs_diff, nFactor, dclkOffset, bErrorStatus);

		if(bErrorStatus != 0){
			pll_disp1_RBUS pll_disp1_reg;

			pll_disp1_reg.regValue =  IoReg_Read32(SYSTEM_PLL_DISP1_VADDR);

			if(bErrorStatus == ERR_UNDERFLOW)
				framesync_new_fixlastline_finetune_step_dclk_M_code(1);
			else
				framesync_new_fixlastline_finetune_step_dclk_M_code(0);

			bSpeedUp = 1;
			bErrorStatus = 0;
			nFactor = 0;
			dvs_diff = 0;
			dvs_cnt_pre = 0;
		}

	}while((ABS(ivs_cnt, dvs_cnt) >= 0x100) && (cnt != 0));


	if(cnt== 0)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s][line:%d] !!!!!!! measure error !!!!!!!!! \n", __FUNCTION__, __LINE__);
	else
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s][line:%d] !!!!!!! measure done !!!!!!!!! \n", __FUNCTION__, __LINE__);

	return 1;
}

unsigned char framesync_new_fixlastline_check_vtotal_meet_panelspec(void)
{
//	if(_DISABLE == Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag())
		return TRUE;
#if 0   //mark scalerlib control by qing_liu
	unsigned char result = TRUE;
	UINT32 DVTotal;
	dv_total_RBUS dv_total_reg;
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	DVTotal = dv_total_reg.dv_total+1;

	if(DVTotal > Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper()){
		DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper();
		result = FALSE;
	}
	else if(DVTotal < Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower()){
		DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower();
		result = FALSE;
	}

	if(result == FALSE){
		printk("\n DVTotal, Over Spec, set to panel spec limit !!! \n");
		IoReg_Write32(PPOVERLAY_DV_total_reg, DVTotal-1);

		printk("\n Limit_Upper()=%x",Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper());
		printk("\n Limit_Lower()=%x",Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower());
		printk("\n DVTotal=%x \n",DVTotal);
	}

	return result;
#endif
}


unsigned int framesync_new_fixlastline_check_vtotal_boundary(unsigned int vtotal)
{
//	if(_DISABLE == Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag())
		return vtotal;
#if 0   //mark scalerlib control by qing_liu
	unsigned char result = TRUE;
	UINT32 DVTotal = vtotal;

	if(DVTotal > Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper()){
		DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper();
		result = FALSE;
	}
	else if(DVTotal < Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower()){
		DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower();
		result = FALSE;
	}

	if(result == FALSE){
		printk("\n DVTotal, Over Spec, set to panel spec limit !!! \n");
		printk("\n Limit_Upper()=%x",Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper());
		printk("\n Limit_Lower()=%x",Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower());
		printk("\n DVTotal=%x \n",DVTotal);
	}
	return DVTotal;
#endif
}
unsigned char framesync_new_fixlastline_flow_do(void)
{
	unsigned int ivs_freq=0;
	unsigned int ivs_cnt=0;
	unsigned int calc_vtotal=0;
	UINT8 fll_result = 1;
	UINT8 ivs_stable = 0;
	UINT8 cnt = 2;

	ppoverlay_fs_iv_dv_fine_tuning1_RBUS tuning1_reg;
	ppoverlay_fs_iv_dv_fine_tuning2_RBUS tuning2_reg;
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5_reg;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n ========== new fix last line flow start ========== \n");

	//disable spread spectrum and watch dog
	drv_adjust_spreadspectrumrange(0);
	fw_scaler_enable_fs_wdg(SLR_MAIN_DISPLAY , FALSE);

	//set fix last line check threshold
	if((_DISP_WID> 2300) && (_DISP_LEN> 1200))	//4k2k
		framesync_new_fixlastline_set_locked_threashold(0x200);
	else
		framesync_new_fixlastline_set_locked_threashold(0x100);

	framesync_new_fixlastline_threashold_check_enable(0);

	//set timing free run
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _DISABLE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	display_timing_ctrl1_reg.multiple_dvs = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	framesync_set_iv2dv_delay();
	msleep(50);

	 framesync_wait_vdc_stable();

	//New FLL Flow:
	do{
		//step1 : determine vtotal
		ivs_cnt = ((UINT32) framesync_new_fixlastline_get_stable_xtal_cnt(IVS_XTAL_CNT));
		ivs_freq = (((UINT32) XTAL_FREQ * 100) / ivs_cnt);
		calc_vtotal = (scalerdisplay_get_dclk()  / ((UINT32) ((Get_DISP_HORIZONTAL_TOTAL()/100) * ivs_freq)));
/*	//remove vby1 define due to no sr mode on sirius
#ifdef VBY_ONE_PANEL
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_SR_MODE) != SR_BYPASS){
			if(modestate_decide_double_dvs_enable() == _DISABLE){
				calc_vtotal *= 2;
			}
		}
#else
		if(modestate_decide_double_dvs_enable() == _ENABLE){
			calc_vtotal /= 2;
		}
#endif
*/
		if(modestate_decide_double_dvs_enable() == _ENABLE)
			calc_vtotal /= 2;


		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk : %d, ivs_freq : %d, get vtotal:%x \n", scalerdisplay_get_dclk(), ivs_freq, calc_vtotal);

		dv_total_RBUS dv_total_reg;
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dv_total_reg.dv_total = calc_vtotal-1;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
		msleep(50);	// wait vtotal apply;

		//step2 : finetune vtotal
		fll_result = framesync_new_fixlastline_finetune_by_vtotal();


		if(fll_result == 0){
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[Framesync][NEW_FLL] Step 2 Fail. Remeasure!!\n");
			continue;
		}

		//step3 : check vtotal meet panel spec
		if(framesync_new_fixlastline_check_vtotal_meet_panelspec() == 1){
			// new fll done.
			goto NEW_FLL_FLOW_DONE;
		}

		//step4 : dclk offset finetune
		//IoReg_Write32(0xb8000490, 0x01D01700); //1080p24 underflow boundary test case, M_code ++
		//IoReg_Write32(0xb8000640, 0x00002F05);
		//IoReg_Write32(0xb8000490, 0x02301700); //1080p24 overflow boundary test case, M_code --
		//IoReg_Write32(0xb8000640, 0x0EFF2F05);
		fll_result = framesync_new_fixlastline_finetune_by_dclk_offset();
	}while((fll_result == 0) && cnt--);

	NEW_FLL_FLOW_DONE:

	if(fll_result == 1)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"new fix last line flow done. \n");
	else
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"new fix last line flow fail. \n");

	pll27x_reg_sys_dclkss_RBUS dclkss_reg;
	dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_field_flag_mode_en = 0;
	dclkss_reg.dclk_freq_syn_slt = 0x2f;
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	if(modestate_decide_double_dvs_enable() == _ENABLE){
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.multiple_dvs = 1;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}

	framesync_set_enterlastline_at_frc_mode_flg(TRUE);
	fw_scaler_enable_fs_wdg(SLR_MAIN_DISPLAY , TRUE);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE," ========== new fix last line flow end ========== \n\n");

	return 0;
}


unsigned char framesync_new_fixlastline_fine_tune(void)
{
	UINT8 fll_result = 1;
	UINT8 cnt = 2;


	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n ========== framesync_new_fixlastline_fine_tune start ========== \n");

	//disable spread spectrum and watch dog
	drv_adjust_spreadspectrumrange(0);
	fw_scaler_enable_fs_wdg(SLR_MAIN_DISPLAY , FALSE);

	//set fix last line check threshold
	if((_DISP_WID> 2300) && (_DISP_LEN> 1200))	//4k2k
		framesync_new_fixlastline_set_locked_threashold(0x200);
	else
		framesync_new_fixlastline_set_locked_threashold(0x100);

	framesync_new_fixlastline_threashold_check_enable(0);

	//set timing free run
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _DISABLE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	display_timing_ctrl1_reg.multiple_dvs = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	//set ivs measure parameter
	ivs_cnt_RBUS ivs_cnt_reg;
	ivs_cnt_reg.regValue = 0;
	ivs_cnt_reg.measure_ivs_cnt_src_sel = 1;	//iv2dv done
	IoReg_Write32(PPOVERLAY_IVS_cnt_reg, ivs_cnt_reg.regValue);

	//set iv2dv delay
	framesync_set_iv2dv_delay();

	if(modestate_get_pr3d_in_fp_3d_mode() == 1){	// framepacking
		unsigned int ivs_framreate = scalerdisplay_get_framerate(_TYPE_IVS);
		unsigned int dvs_framreate = (Get_DISPLAY_REFRESH_RATE()*100);

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s] ivs_framreate:%d, dvs_framreate:%d \n", __FUNCTION__, ivs_framreate, dvs_framreate);

		// if ivs larger than dvs 20 Hz, itshould be double framerate case, need remove half ivs
		// ex 1: input src_ivs=60, after vgip ivs=120, dvs=60;
		// need to remove half ivs and do framesync + fix last line
		// ex 2: input src_ivs=24, after vgip ivs=48, dvs=60;
		// go framesync + fix last line to 48Hz

		if((ivs_framreate > dvs_framreate) && ((ivs_framreate - dvs_framreate) > 2000)){
			ivs_cnt_reg.remove_half_ivs = 1;	//remove half ivs
		}
	}
	IoReg_Write32(PPOVERLAY_IVS_cnt_reg, ivs_cnt_reg.regValue);

	do{
		//step1 : finetune vtotal
		fll_result = framesync_new_fixlastline_finetune_by_vtotal();

		if(fll_result == 1){
		   // new fll done.
		   goto NEW_FLL_FLOW_DONE;
		}

	// move vtotal checking into framesync_new_fixlastline_finetune_by_vtotal
#if 0
		//step2 : check vtotal meet panel spec
		if(framesync_new_fixlastline_check_vtotal_meet_panelspec() == 1){
			 if(fll_result == 1){
				// new fll done.
				goto NEW_FLL_FLOW_DONE;
			 }
			 else{
			 	printk("[Framesync][NEW_FLL] Step 2 Fail. Remeasure!!\n");
			 }
		}
#endif

		//step3 : dclk offset finetune
		//IoReg_Write32(0xb8000490, 0x01D01700); //1080p24 underflow boundary test case, M_code ++
		//IoReg_Write32(0xb8000640, 0x00002F05);
		//IoReg_Write32(0xb8000490, 0x02301700); //1080p24 overflow boundary test case, M_code --
		//IoReg_Write32(0xb8000640, 0x0EFF2F05);
		fll_result = framesync_new_fixlastline_finetune_by_dclk_offset();

	}while((fll_result == 0) && cnt--);

	NEW_FLL_FLOW_DONE:

	if(fll_result == 1)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"new fix last line flow done. \n");
	else
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"new fix last line flow fail. \n");

	sys_dclkss_RBUS dclkss_reg;
	dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_field_flag_mode_en = 0;
	dclkss_reg.dclk_freq_syn_slt = 0x2f;
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_fsync_en = 1;
	display_timing_ctrl1_reg.disp_fix_last_line = 1;
	if(modestate_decide_double_dvs_enable() == _ENABLE){
		display_timing_ctrl1_reg.multiple_dvs = 1;
	}
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	framesync_set_enterlastline_at_frc_mode_flg(TRUE);
	fw_scaler_enable_fs_wdg(SLR_MAIN_DISPLAY , TRUE);

	framesync_new_fixlastline_threashold_check_enable(1);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE," ========== framesync_new_fixlastline_fine_tune end ========== \n\n");

	return 0;
}



#endif
///////////////////////////////////////////////////////////////////////////////////
//USER:LewisLee DATE:2011/04/22
//Fix Dclk, only Adjust DV total
//#define _FRC_LAST_LINE_FIX_DCLK_DV_TOTAL_FRONT_PORCH_OFFSET		10
#define _FRC_LAST_LINE_FIX_DCLK_DV_TOTAL_FRONT_PORCH_OFFSET		3 //Lewis modify 2
#define _FRC_LAST_LINE_FIX_DCLK_RE_MEASURE_TIMES					1// 3  //frank@0617 change remeasure times to speed up
#define _FRC_LAST_LINE_FIX_DCLK_EVEN_ODD_LINE_DIFF_THRESHOLD		9//5  //frank@0617 chage Vtotal compare value to speed up

void framesync_set_lastlinefinetune_at_frc_mode_fixDclk_Flag(unsigned char ucEnable)
{
	ucframesync_lastlinefinetune_at_frc_mode_fixDclk_Flag = ucEnable;
}

unsigned char framesync_get_lastlinefinetune_at_frc_mode_fixDclk_Flag(void)
{  //mark scalerlib control by qing_liu
//	if(_DISABLE == Scaler_Get_EnterFRC_LastLine_FixDclk_AdjustDVtotal_Enable_Flag())
//		return _DISABLE;

	return ucframesync_lastlinefinetune_at_frc_mode_fixDclk_Flag;
}

unsigned char framesync_lastlinefinetune_at_frc_mode_fixDclk(void)
{
	unsigned short DVTotal = 0, DHTotal = 0, DVTotal1 = 0, DHTotal1 = 0;
	//unsigned short DclkOffset, timeout;
	unsigned short measure_timeout = 0, measure_timeout_cnt = 0;
//	fs_iv_dv_fine_tuning1_RBUS tuning1_reg;
//	fs_iv_dv_fine_tuning2_RBUS tuning2_reg;
	pll27x_reg_sys_dclkss_RBUS dclkss_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	ppoverlay_measure_total_pixels_result1_RBUS measure_total_pixels_result1_reg;
	ppoverlay_measure_total_pixels_result2_RBUS measure_total_pixels_result2_reg;
//	fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;
	unsigned char InputSyncLoseCount = 0;
//	unsigned char i = 0;
//	unsigned short Step = 0; //for DV total adjust
//	DPLL_ADJUST_MCODE_STATE Mcode_State;
	UINT8 ucReMeasureTimes = 0;
	UINT8 ucThrIP_Flag = _FALSE;
#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
	framepacking_ctrl1_RBUS framepacking_ctrl1_reg;
	UINT8 uc3D_FP_Flag = _FALSE;
#else
	pll27x_reg_dpll_in_fsync_tracking_ctrl_RBUS dpll_in_fsync_tracking_ctrl_reg;
#endif //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION

//	framesync_set_enterlastline_at_frc_mode_flg(_FALSE);
	unsigned char display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);

	if ((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) || (SLR_SUB_DISPLAY == display))
		return FALSE;
//mark scalerlib control by qing_liu
//	if(FALSE == Scaler_EnterFRC_LastLine_Condition())
//		return FALSE;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Enter framesync_lastlinefinetune_at_frc_mode_fixDclk\n");

	//USER:LewisLee DATE:2012/05/17
	//to prevent Measure Total Pixel Number Overflow
	if(_ENABLE == modestate_decide_double_dvs_enable())
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS timing, Exit!\n\n");
		return FALSE;
	}
	else if (((_DISP_WID < 3800) && (_DISP_LEN < 2100)) && Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES())
	{	// millet3 panel 2k1k all use double dvs timing
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS timing, Exit2!\n\n");
		return FALSE;
	}

	//to make sure Dclk is stable
	drv_adjust_spreadspectrumrange(0);

	fw_scaler_enable_fs_wdg(display , FALSE);

#if 0  //mark scalerlib control by qing_liu
	//USER:LewisLee Date:2010/08/23
	//we need set correct Dclk for fix last line DV total measure
	if(_TRUE == Scaler_Get_SetDPLL_M_Later())
	{
		i = 0xff;

		do
		{
			WaitFor_DEN_STOP();
			Mcode_State = drvif_clock_dpll_M_adjust();

#ifdef CONFIG_WATCHDOG_ENABLE
			IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
			IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif //#ifdef CONFIG_WATCHDOG_ENABLE
		}while((DPLL_ADJUST_MCODE_FINISH != Mcode_State)&&(i--));
	}
#endif
#if 0
	tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
	tuning1_reg.iv2dv_toggle_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);

	ucThrIP_Flag = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP);

	if(_TRUE == ucThrIP_Flag)
	{
		tuning2_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
		tuning2_reg.iv2dv_pixel = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN);
		tuning2_reg.iv2dv_pixel2 = 0;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, tuning2_reg.regValue);

		tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		tuning1_reg.iv2dv_toggle_en = _ENABLE;
		tuning1_reg.iv2dv_toggle_inv = 1;//frank@0403 add this setting for Mac measure correct
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);
	}
#else
	ucThrIP_Flag = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP);
	framesync_set_iv2dv_delay();
#endif

#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
	//USER:LewisLee DATE:2012/12/28
	//During measure FLL mode, need to disable Virtual Vsync
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())
	{
		framepacking_ctrl1_reg.regValue = IoReg_Read32(VGIP_FRAMEPACKING_CTRL1_reg);

		if(_ENABLE == framepacking_ctrl1_reg.frame_packing_en)
		{
			uc3D_FP_Flag = _TRUE;
			fw_scaler_set_vgip_frame_packing_3d_mode(_FALSE);
/*
			printk("VGIP_VGIP_CHN1_CTRL_reg : %x\n", IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg));
			printk("VGIP_FRAMEPACKING_CTRL1_reg : %x\n", IoReg_Read32(VGIP_FRAMEPACKING_CTRL1_reg));
			printk("VGIP_FRAMEPACKING_CTRL2_reg : %x\n", IoReg_Read32(VGIP_FRAMEPACKING_CTRL2_reg));
*/
		}
	}
#endif //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION

	FlxLastLine_Re_MEASURE_FixDclk:

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

//frank@0617 mark below code to speed up
//	msleep(10);

	//enable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_ENABLE);
// [Code Sync][LewisLee][0990316][3][End]

	// Get the measure result for last line
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1]
	if(_MAIN_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if (FALSE == WaitFor_IVS1_Done())
				InputSyncLoseCount++;
		}

	}
	else// if(_SUB_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if (FALSE == WaitFor_IVS2_Done())
				InputSyncLoseCount++;
		}
	}

	if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
		goto FlxLastLine_Lose_Sync_FixDclk;
// [Code Sync][LewisLee][0990316][1][End]
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	measure_timeout = 0xfff;
	measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

	while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
	{
#ifdef CONFIG_WATCHDOG_ENABLE
		IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
		IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif //#ifdef CONFIG_WATCHDOG_ENABLE

// [Code Sync][LewisLee][0990316][1]
#if 0
		if(SLR_MAIN_DISPLAY == display)
		{
			if(FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}
		else// if(_SUB_DISPLAY == display)
		{
			if(FALSE == WaitFor_IVS2())
				InputSyncLoseCount++;
		}
#else //#if 0
		//frank@0617 change  below delaycode to speed up
		msleep(1);
		//msleep(40);
		InputSyncLoseCount++;
#endif //#if 0
		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_FixDclk;
// [Code Sync][LewisLee][0990316][1][End]

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_timeout--;
	}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

// [Code Sync][LewisLee][0990316][1]
	InputSyncLoseCount = 0;
// [Code Sync][LewisLee][0990316][1][End]

	if(0 == measure_timeout)
	{
		measure_timeout_cnt++;
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Last Line Measure timeout : %x\n", measure_timeout_cnt);
		goto FlxLastLine_Lose_Sync_FixDclk;
	}
	else
	{
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
		//need check again
#else //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
		if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
			if((Scaler_InputSrcGetMainChType()==_SRC_HDMI) && (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING))
				measure_total_pixels_result1_reg.total_pixels_first_cnt = measure_total_pixels_result1_reg.total_pixels_first_cnt<<1;
		}
#endif //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
		DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Get_DISP_HORIZONTAL_TOTAL();
		FRC_FLL_printk( "\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);


#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		display ? WaitFor_IVS2_Done() : WaitFor_IVS1_Done();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
		//need check again
#else //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
		if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE()	&& Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
			if((Scaler_InputSrcGetMainChType()==_SRC_HDMI) && (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING))
				measure_total_pixels_result2_reg.total_pixels_second_cnt=measure_total_pixels_result2_reg.total_pixels_second_cnt<<1;
		}
#endif //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
		DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Get_DISP_HORIZONTAL_TOTAL();
		DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Get_DISP_HORIZONTAL_TOTAL();
		FRC_FLL_printk("Measure second time DV total = %x, last line = %x\n", DVTotal1, DHTotal1);

		if(_TRUE == ucThrIP_Flag)
		{
			//USER:LewisLee DATE:2012/08/03
			//some times, measure two frame line is different
			//it maybe is error result
			if(ABS(DVTotal, DVTotal1) > _FRC_LAST_LINE_FIX_DCLK_EVEN_ODD_LINE_DIFF_THRESHOLD)
			{
				if(ucReMeasureTimes <= _FRC_LAST_LINE_FIX_DCLK_RE_MEASURE_TIMES)
				{
					ucReMeasureTimes++;
					rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"DI mode FixDclk ReMeasure, DVTotal : %x, DVTotal1 : %x, ucMeasureTimes : %x\n", DVTotal, DVTotal1, ucReMeasureTimes);
					goto FlxLastLine_Re_MEASURE_FixDclk;
				}
			}

		// hack avoid DVTotal over panel spec
		if(DVTotal > DVTotal1)
			DVTotal = DVTotal1;
		}
		else// if(_FALSE == ucThrIP_Flag)
		{
			//USER:LewisLee DATE:2012/06/18
			//some times, measure two frame line is different
			//it maybe is error result
			if(DVTotal != DVTotal1)
			{
				if(ucReMeasureTimes <= _FRC_LAST_LINE_FIX_DCLK_RE_MEASURE_TIMES)
				{
					ucReMeasureTimes++;
					rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"FixDclk ReMeasure, DVTotal : %x, DVTotal1 : %x, ucMeasureTimes : %x\n", DVTotal, DVTotal1, ucReMeasureTimes);
					goto FlxLastLine_Re_MEASURE_FixDclk;
				}
			}
		}

		DHTotal += DHTotal1;
		DHTotal = DHTotal>>1;
		FRC_FLL_printk("Measure average last line = %x\n",DHTotal);

#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

// [Code Sync][LewisLee][0990302][1]
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
#if 1   //mark scalerlib control by qing_liu
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Limit_Enable_Flag()=%x,DVTotal:%x\n",Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(), DVTotal);
		if(_ENABLE == Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag())
		{
#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
			//USER:LewisLee DATE:2012/10/22
			//fix FLL mode, DV total over range, let Vfreq change
			if(DVTotal > Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper())
			{
				DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper();

				//DV total too large, Set Dh total bigger
				if(_ENABLE == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_Enable_Flag())
				{
					//only execute once
					if(0 == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue())
					{
						ucReMeasureTimes = 0;
						framesync_lastlinefinetune_at_frc_mode_dymanic_adjust_dhtotal(FLL_DYMANIC_ADJUST_DHTOTAL_TO_MAX);
						goto FlxLastLine_Re_MEASURE_FixDclk;
					}
				}
			}
			else if(DVTotal < Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower())
			{
				DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower();

				//DV total too small, Set Dh total smaller
				if(_ENABLE == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_Enable_Flag())
				{
					//only execute once
					if(0 == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue())
					{
						ucReMeasureTimes = 0;
						framesync_lastlinefinetune_at_frc_mode_dymanic_adjust_dhtotal(FLL_DYMANIC_ADJUST_DHTOTAL_TO_MIN);
						goto FlxLastLine_Re_MEASURE_FixDclk;
					}
				}
			}
#else //#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
			if(DVTotal > Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper())
				DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper();
			else if(DVTotal < Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower())
				DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower();
#endif //#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL

			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Limit_Upper()=%x",Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper());
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Limit_Lower()=%x",Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower());
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n DVTotal=%x ",DVTotal);
		}
#endif
	#if 0   //mark scalerlib control by qing_liu
		if(_TRUE == Scaler_Get_SetDvtotal_Slowly_flag())
		{
			FRC_FLL_printk("dv_total_reg.dv_total = %x\n",dv_total_reg.dv_total);
			OriginalDVTotal = dv_total_reg.dv_total;
//			TargetDVTotal = DVTotal - 1;
			TargetDVTotal = DVTotal;
		}
	#endif
		dv_total_reg.dv_total = DVTotal - 1;
		//dv_total_reg.dv_total = DVTotal;
		fw_scaler_dtg_double_buffer_enable(1);

		if(dv_total_reg.dv_total < framesync_get_dvtotal_min())
		{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
			dv_total_reg.dv_total = framesync_dynamic_adjust_dvtotal_den_relation(dv_total_reg.dv_total);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
			dv_total_reg.dv_total = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

			if(dv_total_reg.dv_total > Get_DISP_VERTICAL_TOTAL())
				dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);

			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

//			FRC_FLL_printk(" DV total over spec !\n");
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE," DV total over spec :%x\n", (DVTotal - 1));
		}
		else
		{
		#if 0  //mark scalerlib control by qing_liu
// [Code Sync][LewisLee][0990823][1]
			if(_TRUE == Scaler_Get_SetDVtotal_Later())
			{
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_INITIAL;
			}
			else
		#endif
			{
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;

		//		if(_FALSE == Scaler_Get_SetDvtotal_Slowly_flag())
				{
					IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
				}
			#if 0  //mark scalerlib control by qing_liu
				else
				{
					if(OriginalDVTotal > TargetDVTotal)
					{
						Step = OriginalDVTotal - TargetDVTotal;
						dv_total_reg.dv_total = OriginalDVTotal;
						msleep(20);

						while(Step--)
						{
							dv_total_reg.dv_total -= 1;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
							msleep(4);//frank@0430 Change busy delay to save time
						}
					}
					else if(TargetDVTotal > OriginalDVTotal)
					{
						Step = TargetDVTotal - OriginalDVTotal;
						dv_total_reg.dv_total = OriginalDVTotal;
//						WaitFor_DEN_STOP();
						msleep(20);

						while(Step--)
						{
							dv_total_reg.dv_total += 1;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
							msleep(4);//frank@0430 Change busy delay to save time
						}
					}
					else
					{
//						WaitFor_DEN_STOP();
						msleep(20);
						IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
					}
				}
			#endif
			}
// [Code Sync][LewisLee][0990823][1][End]
		}
// [Code Sync][LewisLee][0990302][1][End]
	}

#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
	if(_TRUE == uc3D_FP_Flag)
	{
		dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_freq_syn_slt = 0x3f;
		dclkss_reg.dclk_ss_load = 1;
		dclkss_reg.dclk_ss_en = _ENABLE;
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);
	}
	else// if(_FALSE == uc3D_FP_Flag)
	{
		dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_freq_syn_slt = 0x2f;
		dclkss_reg.dclk_ss_load = 1;
		dclkss_reg.dclk_ss_en = _ENABLE;
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);
	}
#else //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
	dpll_in_fsync_tracking_ctrl_reg.regValue = IoReg_Read32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg);
	dpll_in_fsync_tracking_ctrl_reg.dclk_freq_syn_slt = _DCLK_FREQ_SYN_SLT;
	IoReg_Write32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg, dpll_in_fsync_tracking_ctrl_reg.regValue);
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, dclkss_reg.regValue);
#endif //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION

//[Code Sync][LewisLee][0990318][1]
//	if(DHTotal > (_FRC_LAST_LINE_PIXEL_OFFSET + Scaler_Get_EnterFRC_LastLine_LastLinePixel_Offset()))
	if(DHTotal > (_FRC_LAST_LINE_PIXEL_OFFSET + 0))
		DHTotal -= _FRC_LAST_LINE_PIXEL_OFFSET;
	else
	//	DHTotal = 1 + Scaler_Get_EnterFRC_LastLine_LastLinePixel_Offset();//avoid 0-1 equal to -1
		DHTotal = 1 + 0;

	//to prevent Dh total over range
	if(DHTotal > Get_DISP_HORIZONTAL_TOTAL())
	{
		DHTotal -= Get_DISP_HORIZONTAL_TOTAL();

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"LastLine Pixel > DH_Total\n");

		//Increase 1 line
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dv_total_reg.dv_total += 1;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
	}

	//USER:LewisLee DATE:2010/07/16
	//for Edward request, let last line pixel is even at picasso platform
	if(DHTotal & _BIT0)
		DHTotal += 1;

	// Setting value = ( real value -1) , Min. value 90
	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = DHTotal&(~(_BIT0|_BIT1));
#endif
	if((Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1)||(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)){
		DHTotal	= (DHTotal | 0x3) +1; //last line total msut 4x
	}
	dh_total_last_line_length_reg.dh_total_last_line = DHTotal-1;
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
//[Code Sync][LewisLee][0990318][1][End]

	//step 9, Enable F and F-NdF switch
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	dclkss_reg.dclk_new_en = _DISABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, dclkss_reg.regValue);

	framesync_set_enterlastline_at_frc_mode_flg(TRUE);

	fw_scaler_dtg_double_buffer_apply();
	//frank@0903 reduce timefw_scaler_dtg_double_buffer_enable(0);


	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]
	fw_scaler_enable_fs_wdg(display , TRUE);

#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
	if(_TRUE == uc3D_FP_Flag)
		fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
#endif //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION

	return TRUE;

// [Code Sync][LewisLee][0990316][1]
	FlxLastLine_Lose_Sync_FixDclk:
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"FlxLastLine_Lose_Sync_FixDclk\n");
	framesync_set_enterlastline_at_frc_mode_flg(FALSE);

	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL()- 1)& 0x00001fff;
	dh_total_last_line_length_reg.dh_total_last_line = dh_total_last_line_length_reg.dh_total;
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]
	fw_scaler_enable_fs_wdg(display , TRUE);

#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION
	if(_TRUE == uc3D_FP_Flag)
		fw_scaler_set_vgip_frame_packing_3d_mode(_TRUE);
#endif //#ifdef CONFIG_ENABLE_3D_FRAME_PACKING_ID_DOMAIN_NEW_RELATION

	return FALSE;
// [Code Sync][LewisLee][0990316][1][End]
}

UINT8 framesync_lastlinefinetune_at_frc_mode_fixDclk_withfinetunelastline(void)
{
	return FALSE;
#if 0
	UINT16 DVTotal = 0, DHTotal = 0, DVTotal1 = 0, DHTotal1 = 0;
	UINT16 DHTotal_1st = 0, DclkOffset_step = 0;
	UINT8 JumpFlag = FALSE, AdjustDirect = _DCLK_OFFSET_DECREASE;
	UINT16 DclkOffset, timeout;
	UINT16 measure_timeout = 0, measure_timeout_cnt = 0;
	fs_iv_dv_fine_tuning1_RBUS tuning1_reg;
	fs_iv_dv_fine_tuning2_RBUS tuning2_reg;
	sys_dclkss_RBUS sys_dclkss_reg;
	pll_ssc0_RBUS pll_ssc0_reg;
	dpll_in_fsync_tracking_ctrl_RBUS dpll_in_fsync_tracking_ctrl_reg;
	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	measure_total_pixels_result1_RBUS measure_total_pixels_result1_reg;
	measure_total_pixels_result2_RBUS measure_total_pixels_result2_reg;
	dv_total_RBUS dv_total_reg;
// [Code Sync][LewisLee][0990316][1]
	UINT8 InputSyncLoseCount = 0;
//#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	//UINT8 i = 0;
//#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1][End]
//	UINT16 Step = 0; //for DV total adjust
//	DPLL_ADJUST_MCODE_STATE Mcode_State;
	UINT32 Cur_DH_Total_Value = 0;
//	framesync_set_enterlastline_at_frc_mode_flg(_FALSE);
	UINT8 display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);

	if ((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) || (SLR_SUB_DISPLAY == display))
		return FALSE;

//	if(FALSE == Scaler_EnterFRC_LastLine_Condition())

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Enter framesync_lastlinefinetune_at_frc_mode_fixDclk_withfinetunelastline\n");

	//USER:LewisLee DATE:2012/05/17
	//to prevent Measure Total Pixel Number Overflow
	if(_ENABLE == modestate_decide_double_dvs_enable())
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Double DVS timing, Exit!\n\n");
		return FALSE;
	}

	//to make sure Dclk is stable
	drv_adjust_spreadspectrumrange(0);

	fw_scaler_enable_fs_wdg(display , FALSE);

	Cur_DH_Total_Value = framesync_lastlinefinetune_at_frc_mode_get_dhtotal_value();
#if 0   //mark scalerlib control by qing_liu
	//USER:LewisLee Date:2010/08/23
	//we need set correct Dclk for fix last line DV total measure
	if(_TRUE == Scaler_Get_SetDPLL_M_Later())
	{
		Step = 0x3ff; // DPLLQM[9:0]

		do
		{
			WaitFor_DEN_STOP();
			Mcode_State = drvif_clock_dpll_M_adjust();

#ifdef CONFIG_WATCHDOG_ENABLE
			IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
			IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif //#ifdef CONFIG_WATCHDOG_ENABLE
		}while((DPLL_ADJUST_MCODE_FINISH != Mcode_State)&&(Step--));
	}
#endif
	tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
	tuning1_reg.iv2dv_toggle_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);

	if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP))
	{
		tuning2_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
		tuning2_reg.iv2dv_pixel = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN);
		tuning2_reg.iv2dv_pixel2 = 0;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, tuning2_reg.regValue);

		tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		tuning1_reg.iv2dv_toggle_en = _ENABLE;
		tuning1_reg.iv2dv_toggle_inv = 1;//frank@0403 add this setting for Mac measure correct
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, tuning1_reg.regValue);
	}

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

	msleep(10);

	//enable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_ENABLE);
// [Code Sync][LewisLee][0990316][3][End]

	// Get the measure result for last line
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1]
	if(_MAIN_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if (FALSE == WaitFor_IVS1_Done())
				InputSyncLoseCount++;
		}
	}
	else// if(_SUB_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if (FALSE == WaitFor_IVS2_Done())
				InputSyncLoseCount++;
		}
	}

	if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
		goto FlxLastLine_Lose_Sync_FixDclk_WithFineTuneLastLine;
// [Code Sync][LewisLee][0990316][1][End]
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	measure_timeout = 0xfff;
	measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

	while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
	{
#ifdef CONFIG_WATCHDOG_ENABLE
		IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
		IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif //#ifdef CONFIG_WATCHDOG_ENABLE

// [Code Sync][LewisLee][0990316][1]
#if 0
		if(SLR_MAIN_DISPLAY == display)
		{
			if(FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}
		else// if(_SUB_DISPLAY == display)
		{
			if(FALSE == WaitFor_IVS2())
				InputSyncLoseCount++;
		}
#else //#if 0
		msleep(40);
		InputSyncLoseCount++;
#endif //#if 0
		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_FixDclk_WithFineTuneLastLine;
// [Code Sync][LewisLee][0990316][1][End]

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_timeout--;
	}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

// [Code Sync][LewisLee][0990316][1]
	InputSyncLoseCount = 0;
// [Code Sync][LewisLee][0990316][1][End]

	if(0 == measure_timeout)
	{
		measure_timeout_cnt++;
		FRC_FLL_printk("Last Line Measure timeout : %x\n", measure_timeout_cnt);
	}
	else
	{
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

		DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Cur_DH_Total_Value;
		DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Cur_DH_Total_Value;
		FRC_FLL_printk( "\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		display ? WaitFor_IVS2_Done() : WaitFor_IVS1_Done();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
		DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Cur_DH_Total_Value;
		DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Cur_DH_Total_Value;
		FRC_FLL_printk("Measure second time DV total = %x, last line = %x\n", DVTotal1, DHTotal1);

		DHTotal += DHTotal1;
		DHTotal = DHTotal>>1;
		FRC_FLL_printk("Measure average last line = %x\n",DHTotal);

#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

// [Code Sync][LewisLee][0990302][1]
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	#if 1   //mark scalerlib control by qing_liu
		if(_ENABLE == Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag())
		{
			if(DVTotal > Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper())
				DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper();
			else if(DVTotal < Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower())
				DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower();
		}
 	#endif
	#if 0  //mark scalerlib control by qing_liu
		if(_TRUE == Scaler_Get_SetDvtotal_Slowly_flag())
		{
			FRC_FLL_printk("dv_total_reg.dv_total = %x\n",dv_total_reg.dv_total);
			OriginalDVTotal = dv_total_reg.dv_total;
			TargetDVTotal = DVTotal;
		}
	#endif

		dv_total_reg.dv_total = DVTotal;

		if(dv_total_reg.dv_total < framesync_get_dvtotal_min())
		{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
			dv_total_reg.dv_total = framesync_dynamic_adjust_dvtotal_den_relation(dv_total_reg.dv_total);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
			dv_total_reg.dv_total = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

			if(dv_total_reg.dv_total > Get_DISP_VERTICAL_TOTAL())
				dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);

			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

//			FRC_FLL_printk(" DV total over spec !\n");
//			printk(" DV total over spec :%x\n", (DVTotal - 1));
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE," DV total over spec :%x\n", DVTotal);
		}
		else
		{
// [Code Sync][LewisLee][0990823][1]
		#if 0  //mark scalerlib control by qing_liu
			if(_TRUE == Scaler_Get_SetDVtotal_Later())
			{
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_INITIAL;
			}
			else
		#endif
			{
				Adjust_Dvtotal_State = FRAMESYNC_ADJUST_DVTOTAL_FINISH;

			//	if(_FALSE == Scaler_Get_SetDvtotal_Slowly_flag())
				{
					IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
				}
			#if 0   //mark scalerlib control by qing_liu
				else
				{
					if(OriginalDVTotal > TargetDVTotal)
					{
						Step = OriginalDVTotal - TargetDVTotal;
						dv_total_reg.dv_total = OriginalDVTotal;
						msleep(20);

						while(Step--)
						{
							dv_total_reg.dv_total -= 1;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
							msleep(4);//frank@0430 Change busy delay to save time
						}
					}
					else if(TargetDVTotal > OriginalDVTotal)
					{
						Step = TargetDVTotal - OriginalDVTotal;
						dv_total_reg.dv_total = OriginalDVTotal;
//						WaitFor_DEN_STOP();
						msleep(20);

						while(Step--)
						{
							dv_total_reg.dv_total += 1;
							IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
							msleep(4);//frank@0430 Change busy delay to save time
						}
					}
					else
					{
//						WaitFor_DEN_STOP();
						msleep(20);
						IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
					}
				}
			#endif
			}
// [Code Sync][LewisLee][0990823][1][End]
		}
// [Code Sync][LewisLee][0990302][1][End]

		// Adjust Dclk offset to make last line equal to DH total
		if (DHTotal < _FRC_LAST_LINE_PIXEL_THRESHOLD)
		{
			// enable last line
			goto EnableFlxLastLine_At_FRC_Mode_FixDclk_WithFineTuneLastLine;
		}
		else if(DHTotal > (Cur_DH_Total_Value - _FRC_LAST_LINE_PIXEL_THRESHOLD))
		{
			goto EnableFlxLastLine_At_FRC_Mode_FixDclk_WithFineTuneLastLine;
		}

#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		DHTotal_1st = DHTotal;
		DclkOffset_step = 0;
		JumpFlag = FALSE;
#endif //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
	}

	// Need to adjust Dclk offset
	FRC_FLL_printk("Need to adjust offset \n");

	timeout = _FRC_LAST_LINE_TIMEOUT_CNT;

	while (timeout--)
	{
		//disable measure
// [Code Sync][LewisLee][0990316][3]
		drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

		pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
		DclkOffset = pll_ssc0_reg.fcode_t_ssc;
		FRC_FLL_printk("Dclk offset data= %x\n", pll_ssc0_reg.fcode_t_ssc);
#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		DHTotal_1st = DHTotal;

		if(0 == DclkOffset_step)
		{
			//first time enter while loop
			if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
				DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
			else
				DclkOffset = 0;
		}
		else if(TRUE == JumpFlag)
		{
			if(_DCLK_OFFSET_DECREASE == AdjustDirect)
			{
				if(DHTotal > (Cur_DH_Total_Value/2))
				{
					 // remain at same line, keep same action
					if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
						DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
					else
						FRC_FLL_printk("Dclk offset too small@dec\n");
				}
				else // // not jump to next line
				{
					 // jump to next line, do different action
					DclkOffset = DclkOffset + _FRC_LAST_LINE_PIXEL_STEP;
				}
			}
			else// if(_DCLK_OFFSET_INCREASE == AdjustDirect)
			{
				if(DHTotal > (Cur_DH_Total_Value/2))
				{
					 // jump to front line, do different action
					if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
						DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
					else
						FRC_FLL_printk("Dclk offset too small@inc\n");
				}
				else
				{
					 // remain at same line, keep same action
					DclkOffset = DclkOffset + _FRC_LAST_LINE_PIXEL_STEP;
				}
			}
		}
		else
		{
			//second time enter while loop
			if(_DCLK_OFFSET_DECREASE == AdjustDirect)
			{
				if(DclkOffset >= DclkOffset_step)
					DclkOffset = DclkOffset - DclkOffset_step;
				else if(DclkOffset >= _FRC_LAST_LINE_PIXEL_STEP)
					DclkOffset = DclkOffset -_FRC_LAST_LINE_PIXEL_STEP;
				else
					DclkOffset = 0;
			}
			else// if(_DCLK_OFFSET_INCREASE == AdjustDirect)
			{
				DclkOffset = DclkOffset + DclkOffset_step;
			}

			JumpFlag = TRUE;
		}
#else //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		DclkOffset = DclkOffset - _FRC_LAST_LINE_PIXEL_STEP;
#endif //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2

		if (DclkOffset < 20) // CSW+ 0970327 Add protection for time out
			break;

		FRC_FLL_printk("Dclk offset after adjust = %x\n", DclkOffset);

		pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
		pll_ssc0_reg.fcode_t_ssc= DclkOffset;
		IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

// [Code Sync][LewisLee][0990302][1]
	//	ROS_ENTER_CRITICAL();
//		WaitFor_DEN_STOP(); //<- LewisLee Mask, for speed up fix last line speed
		sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
		sys_dclkss_reg.dclk_ss_load = 1;
		sys_dclkss_reg.dclk_ss_en = _ENABLE;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, sys_dclkss_reg.regValue);
	//	ROS_EXIT_CRITICAL();
// [Code Sync][LewisLee][0990302][1][End]

#ifdef CONFIG_WATCHDOG_ENABLE
		IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
		IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif //#ifdef CONFIG_WATCHDOG_ENABLE

		//enable measure
// [Code Sync][LewisLee][0990316][3]
		drvif_measure_total_pixels(_ENABLE);
// [Code Sync][LewisLee][0990316][3][End]

#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1]
		if(_MAIN_DISPLAY == display)
		{
			for(i = 0; i<4; i++)
			{
				if (FALSE == WaitFor_IVS1_Done())
					InputSyncLoseCount++;
			}

		}
		else// if(_SUB_DISPLAY == display)
		{
			for(i = 0; i<4; i++)
			{
				if (FALSE == WaitFor_IVS2_Done())
					InputSyncLoseCount++;
			}
		}

		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_FixDclk_WithFineTuneLastLine;
// [Code Sync][LewisLee][0990316][1][End]
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		// Get the measure result for last line
		measure_timeout = 0xfff;
		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
		{
	#ifdef CONFIG_WATCHDOG_ENABLE
			IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
			IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
	#endif //#ifdef CONFIG_WATCHDOG_ENABLE

// [Code Sync][LewisLee][0990316][1]
#if 0
			if(SLR_MAIN_DISPLAY == display)
			{
				if(FALSE == WaitFor_IVS1())
					InputSyncLoseCount++;
			}
			else// if(_SUB_DISPLAY == display)
			{
				if(FALSE == WaitFor_IVS2())
					InputSyncLoseCount++;
			}
#else //#if 0
			msleep(40);
			InputSyncLoseCount++;
#endif //#if 0
			if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
				goto FlxLastLine_Lose_Sync_FixDclk_WithFineTuneLastLine;
// [Code Sync][LewisLee][0990316][1][End]

			measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
			measure_timeout--;
		}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

// [Code Sync][LewisLee][0990316][1]
		InputSyncLoseCount = 0;
// [Code Sync][LewisLee][0990316][1][End]

		if(0 == measure_timeout)
		{
			measure_timeout_cnt++;
			FRC_FLL_printk("Last Line Measure timeout : %x\n", measure_timeout_cnt);
			continue;
		}

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

		DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Cur_DH_Total_Value;
		DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Cur_DH_Total_Value;
		FRC_FLL_printk("\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		display ? WaitFor_IVS2_Done() : WaitFor_IVS1_Done();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
		DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Cur_DH_Total_Value;
		DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Cur_DH_Total_Value;
		FRC_FLL_printk("Measure second time DV total = %x, last line = %x\n", DVTotal1, DHTotal1);

		DHTotal += DHTotal1;
		DHTotal = DHTotal >>1;
		FRC_FLL_printk( "Measure average last line = %x\n",DHTotal);
#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

		if ((DHTotal < _FRC_LAST_LINE_PIXEL_THRESHOLD) || (DHTotal > (Cur_DH_Total_Value - _FRC_LAST_LINE_PIXEL_THRESHOLD)))
		{
			FRC_FLL_printk("adjust offset,  final timeout : %x\n", timeout);

// [Code Sync][LewisLee][0990302][1]
#if 1   //mark scalerlib control by qing_liu
			if(_ENABLE == Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag())
			{
				if(DVTotal > Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper())
					DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper();
				else if(DVTotal < Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower())
					DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower();
			}
#endif
			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
//			dv_total_reg.dv_total = DVTotal - 1;
			dv_total_reg.dv_total = DVTotal;

			if(dv_total_reg.dv_total < framesync_get_dvtotal_min())
			{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_dynamic_adjust_dvtotal_den_relation(dv_total_reg.dv_total);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

				if(dv_total_reg.dv_total > Get_DISP_VERTICAL_TOTAL())
					dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);

				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

//				FRC_FLL_printk(" DV total over spec !\n");
//				printk(" DV total over spec :%x\n", (DVTotal - 1));
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE," DV total over spec :%x\n", DVTotal);
			}
			else
			{
			#if 0   //mark scalerlib control by qing_liu
				if(_TRUE == Scaler_Get_SetDVtotal_Later())
				{
//					TargetDVTotal = DVTotal - 1;
					TargetDVTotal = DVTotal;
				}
				else
			#endif
				{
					IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
				}
			}
// [Code Sync][LewisLee][0990302][1][End]
//			RTD_Log(LOGGER_INFO, "\n PPOVERLAY_DV_total_reg : %x\n", rtdf_inl(PPOVERLAY_DV_total_reg));

			break;
		}

		if(0 == timeout)
		{
			FRC_FLL_printk( "FRC Measure Last Line Fail\n");
// [Code Sync][LewisLee][0990302][1]
		#if 0    //mark scalerlib control by qing_liu
			if(_ENABLE == Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag())
			{
				if(DVTotal > Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper())
					DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper();
				else if(DVTotal < Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower())
					DVTotal = Scaler_Get_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower();
			}
		#endif
			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
//			dv_total_reg.dv_total = DVTotal - 1;
			dv_total_reg.dv_total = DVTotal;

			if(dv_total_reg.dv_total < framesync_get_dvtotal_min())
			{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_dynamic_adjust_dvtotal_den_relation(dv_total_reg.dv_total);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
				dv_total_reg.dv_total = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

				if(dv_total_reg.dv_total > Get_DISP_VERTICAL_TOTAL())
					dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);

				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

//				FRC_FLL_printk(" DV total over spec !\n");
//				printk(" DV total over spec :%x\n", (DVTotal - 1));
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE," DV total over spec :%x\n", (DVTotal));
			}
			else
			{
			#if 0   //mark scalerlib control by qing_liu
				if(_TRUE == Scaler_Get_SetDVtotal_Later())
				{
//					TargetDVTotal = DVTotal - 1;
					TargetDVTotal = DVTotal;
				}
				else
			#endif
				{
					IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
				}
			}
// [Code Sync][LewisLee][0990302][1][End]
		}
		else
		{
#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
			if(0 == DclkOffset_step)
			{
// [Code Sync][LewisLee][0990603][1]
				//USER:LewisLee DATE:2010/06/03
				//to prevent divide by zero
				if(DHTotal == DHTotal_1st)
				{
					if(DHTotal >= (Cur_DH_Total_Value/2))
						AdjustDirect = _DCLK_OFFSET_DECREASE;
					else
						AdjustDirect = _DCLK_OFFSET_INCREASE;

					DclkOffset_step = _FRC_LAST_LINE_PIXEL_STEP<<1;
				}
				else
				{
					if(DHTotal >= (Cur_DH_Total_Value/2))
					{
						AdjustDirect = _DCLK_OFFSET_DECREASE;
						DclkOffset_step = _FRC_LAST_LINE_PIXEL_STEP*(Cur_DH_Total_Value - DHTotal + _FRC_LAST_LINE_PIXEL_THRESHOLD/2)/ABS(DHTotal, DHTotal_1st);
					}
					else
					{
						AdjustDirect = _DCLK_OFFSET_INCREASE;
						DclkOffset_step = (_FRC_LAST_LINE_PIXEL_STEP*(DHTotal - _FRC_LAST_LINE_PIXEL_THRESHOLD))/ABS(DHTotal, DHTotal_1st);
					}
				}
// [Code Sync][LewisLee][0990603][1][End]
			}
#endif //#ifdef _FRC_LAST_LINE_DCLK_AJUST_METHOD2
		}

	}

	EnableFlxLastLine_At_FRC_Mode_FixDclk_WithFineTuneLastLine:

	dpll_in_fsync_tracking_ctrl_reg.regValue = IoReg_Read32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg);
	dpll_in_fsync_tracking_ctrl_reg.dclk_freq_syn_slt = _DCLK_FREQ_SYN_SLT;
	IoReg_Write32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_reg, dpll_in_fsync_tracking_ctrl_reg.regValue);

	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	sys_dclkss_reg.dclk_ss_load = 1;
	sys_dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, sys_dclkss_reg.regValue);

//[Code Sync][LewisLee][0990318][1]
//	if(DHTotal > (_FRC_LAST_LINE_PIXEL_OFFSET + Scaler_Get_EnterFRC_LastLine_LastLinePixel_Offset()))
	if(DHTotal > _FRC_LAST_LINE_PIXEL_OFFSET)
		DHTotal -= _FRC_LAST_LINE_PIXEL_OFFSET;
	else
	//	DHTotal = 1 + Scaler_Get_EnterFRC_LastLine_LastLinePixel_Offset();//avoid 0-1 equal to -1
		DHTotal = 1 ;

	//USER:LewisLee DATE:2010/07/16
	//for Edward request, let last line pixel is even at picasso platform
	if(DHTotal & _BIT0)
		DHTotal += 1;

	// Setting value = ( real value -1) , Min. value 90
	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total_last_line_length_reg.dh_total = (Cur_DH_Total_Value - 1);
	dh_total_last_line_length_reg.dh_total_last_line = DHTotal-1;
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
//[Code Sync][LewisLee][0990318][1][End]

	//step 9, Enable F and F-NdF switch
	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	sys_dclkss_reg.dclk_new_en = _DISABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, sys_dclkss_reg.regValue);


	framesync_set_enterlastline_at_frc_mode_flg(TRUE);

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]
	fw_scaler_enable_fs_wdg(display , TRUE);

	return TRUE;

// [Code Sync][LewisLee][0990316][1]
	FlxLastLine_Lose_Sync_FixDclk_WithFineTuneLastLine:
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	framesync_set_enterlastline_at_frc_mode_flg(FALSE);

	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_total_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]
	fw_scaler_enable_fs_wdg(display , TRUE);

	return FALSE;
// [Code Sync][LewisLee][0990316][1][End]
#endif
}

#define _FLL_MODE_VFREQ_CONVERT_VFREQ_MIN		(55*10) // 55Hz
#define _FLL_MODE_VFREQ_CONVERT_VFREQ_MAX		(65*10) // 65Hz
#define _FLL_MODE_VFREQ_CONVERT_TO_60_VFREQ		(60*10) // 60Hz
#define _FLL_MODE_VFREQ_CONVERT_TOLERANCE		(1*10) // 1Hz
UINT8 framesync_lastlinefinetune_at_frc_mode_VfreqConvert(void)
{
#ifdef CONFIG_ENABLE_FLL_MODE_VFREQ_CONVER_TO_60HZ
	//USER:LewisLee DATE:2012/06/20
	//for special request
	//the customer request, converter input freq to 60Hz
	ppoverlay_dv_total_RBUS dv_total_reg;
	UINT32 IVFreq = 0, DVTotal = 0;

	if(_TRUE == framesync_get_enterlastline_at_frc_mode_flg())
	{
		IVFreq = Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ);

		//In safe range, do nothing
		if(ABS(IVFreq, _FLL_MODE_VFREQ_CONVERT_TO_60_VFREQ) <= _FLL_MODE_VFREQ_CONVERT_TOLERANCE)
			return _TRUE;

		//only adjust 55Hz ~ 65Hz
		if((IVFreq <= _FLL_MODE_VFREQ_CONVERT_VFREQ_MAX) || (IVFreq >= _FLL_MODE_VFREQ_CONVERT_VFREQ_MIN))
		{
			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
			DVTotal = dv_total_reg.dv_total + 1;

			DVTotal = DVTotal * IVFreq / _FLL_MODE_VFREQ_CONVERT_TO_60_VFREQ;

			dv_total_reg.dv_total = DVTotal - 1;
			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Fix Dclk, Input Vfreq : %x to Output Vfreq : %x\n", IVFreq, _FLL_MODE_VFREQ_CONVERT_TO_60_VFREQ);
		}
	}
	else// if(_FALSE == framesync_get_enterlastline_at_frc_mode_flg())
	{
		return _FALSE;
	}
#endif //#ifdef CONFIG_ENABLE_FLL_MODE_VFREQ_CONVER_TO_60HZ

	return _TRUE;
}

unsigned char framesync_lastlinefinetune_at_frc_mode(void)
{
// [Code Sync][LewisLee][0990316][2]
	unsigned char result = FALSE;
//	dv_total_RBUS dv_total_reg;
//	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;
//	mdomain_disp_ddr_mainsubctrl_RBUS ddr_mainsubctrl_reg;

#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
	framesync_lastlinefinetune_at_frc_mode_dymanic_adjust_dhtotal(FLL_DYMANIC_ADJUST_DHTOTAL_NONE);
#endif //#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL

	if(_ENABLE == framesync_get_lastlinefinetune_at_frc_mode_fixDclk_Flag())
	{
		result = framesync_lastlinefinetune_at_frc_mode_fixDclk();

		if(_TRUE == result)
			framesync_lastlinefinetune_at_frc_mode_VfreqConvert();

		if(_TRUE == result) //if(_TRUE == framesync_get_enterlastline_at_frc_mode_flg())
		{
			#if 0   //mark scalerlib control by qing_liu
			if(_TRUE == Scaler_Mdomain_Disp_SingleBuffer_Disable_FLL_Condition(SLR_MAIN_DISPLAY))
			{
				framesync_set_enterlastline_at_frc_mode_flg(_FALSE);
				printk("change FLL flag to False 1\n");
			}
			#endif
		}

		return result;
	}
#if 0  //mark scalerlib control by qing_liu
	else if(_ENABLE == Scaler_Get_EnterFRC_LastLine_DclkOverRange_Compensate_Enable_Flag())
	{
		if(DCLK_IN_RANGE == drvif_get_dclk_margin_check_result())
		{
			//Run Normal flow
		}
		else
		{
			result = framesync_lastlinefinetune_at_frc_mode_fixDclk_withfinetunelastline();

			if(_TRUE == result) //if(_TRUE == framesync_get_enterlastline_at_frc_mode_flg())
			{
				if(_TRUE == Scaler_Mdomain_Disp_SingleBuffer_Disable_FLL_Condition(SLR_MAIN_DISPLAY))
	{
					framesync_set_enterlastline_at_frc_mode_flg(_FALSE);
					printk("change FLL flag to False 2\n");
				}
	}

			return result;
		}
	}

	if(TRUE == Scaler_Get_FRC_Open_Fix_Lastline_2_Algo1())
	{
		result = framesync_lastlinefinetune_at_frc_mode_algo1();

		if (Scaler_Get_Vflip_Enable())
		{
			if(TRUE == result)
			{
				//Slower Down D domain Speed
				dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
				dv_total_reg.dv_total += 1;
				IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

				//Modify M domain FRC Style
				ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
				ddr_mainctrl_reg.main_frc_style = Scaler_Get_Vflip_FRC_Style();
				IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);

				ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
				ddr_mainsubctrl_reg.disp1_double_enable = _ENABLE;
				IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, ddr_mainsubctrl_reg.regValue);
			}
			else
			{
				//Set M domain FRC Style to Default Modemake
				ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
				ddr_mainctrl_reg.main_frc_style = Scaler_Get_Default_Vflip_FRC_Style();
				IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);

				ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
				ddr_mainsubctrl_reg.disp1_double_enable = _ENABLE;
				IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, ddr_mainsubctrl_reg.regValue);
			}
		}
	}
	else if(TRUE == Scaler_Get_FRC_Open_Fix_Lastline_2_Algo2())
	{
		result = framesync_lastlinefinetune_at_frc_mode_algo2();
	}

        if(_TRUE == result) //if(_TRUE == framesync_get_enterlastline_at_frc_mode_flg())
	{
		if(_TRUE == Scaler_Mdomain_Disp_SingleBuffer_Disable_FLL_Condition(SLR_MAIN_DISPLAY))
		{
			framesync_set_enterlastline_at_frc_mode_flg(_FALSE);
			printk("change FLL flag to False 3\n");
		}
	}
#endif

	return result;
// [Code Sync][LewisLee][0990316][2][End]
}
#define FLL_NEW_MODE_SYNTHESISN 1
unsigned char framesync_lastlinefinetune_at_new_mode(void)
{
	unsigned char result = TRUE;
	unsigned int multiplier, y, htotal, vtotal;
	ppoverlay_fix_last_line_systhesisn_ratio_RBUS fix_last_line_systhesisn_ratio_reg;
	pll27x_reg_dpll_in_fsync_tracking_ctrl4_RBUS dpll_in_fsync_tracking_ctrl4_reg;
	ppoverlay_fix_last_line_mode_lock_status_RBUS ppoverlay_fix_last_line_mode_lock_status_reg;
//	dpll_in_fsync_tracking_ctrl_RBUS dpll_in_fsync_tracking_ctrl_reg;
	pll27x_reg_sys_pll_disp1_RBUS pll_disp1_reg;
	pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
	pll27x_reg_sys_dclkss_RBUS sys_dclkss_reg;
	ppoverlay_dh_total_last_line_length_RBUS ppoverlay_dh_total_last_line_length_reg;
	ppoverlay_dv_total_RBUS ppoverlay_dv_total_reg;
	unsigned char fll_newmode_synt =0;
	ppoverlay_main_display_control_rsv_RBUS ppoverlay_main_display_control_rsv_reg;

	framesync_set_iv2dv_delay();

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI){
		fll_newmode_synt = 5;
	}else{
		fll_newmode_synt = FLL_NEW_MODE_SYNTHESISN;
	}

	//FLL reset flow for merlin2 @Crixus 20160909
	ppoverlay_fix_last_line_mode_lock_status_reg.regValue = IoReg_Read32(PPOVERLAY_fix_last_line_mode_lock_status_reg);
	//ppoverlay_fix_last_line_mode_lock_status_reg.lock_th = 0xafc;//modify the fll threshold, ((xclk / 12) *n%)<<4
	ppoverlay_fix_last_line_mode_lock_status_reg.lock_th = 0xfff;//modify the fll threshold, ((xclk / 12) *n%)<<4
	ppoverlay_fix_last_line_mode_lock_status_reg.t_s = 1;//reset fll lock status
	IoReg_Write32(PPOVERLAY_fix_last_line_mode_lock_status_reg, ppoverlay_fix_last_line_mode_lock_status_reg.regValue);

	ppoverlay_dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	ppoverlay_dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	htotal = ppoverlay_dh_total_last_line_length_reg.dh_total+1;
	vtotal = ppoverlay_dv_total_reg.dv_total+1;
	fix_last_line_systhesisn_ratio_reg.regValue = IoReg_Read32(PPOVERLAY_fix_last_line_systhesisN_ratio_reg);
	fix_last_line_systhesisn_ratio_reg.max_multiple_synthesisn = 6;
	fix_last_line_systhesisn_ratio_reg.synthesisn = fll_newmode_synt;
	fix_last_line_systhesisn_ratio_reg.synthesisn_ratio =
		(((125*htotal*vtotal)/100)*fll_newmode_synt)/40960;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s]synthesisn_ratio = %x\n", __FUNCTION__, fix_last_line_systhesisn_ratio_reg.synthesisn_ratio);
	IoReg_Write32(PPOVERLAY_fix_last_line_systhesisN_ratio_reg, fix_last_line_systhesisn_ratio_reg.regValue);
	pll_disp1_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
	y = (2048*(pll_disp1_reg.dpll_m+3))+pll_ssc0_reg.fcode_t_ssc;
	multiplier = (y*4096)/4095;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s]multiplier= %x\n", __FUNCTION__, multiplier);
	dpll_in_fsync_tracking_ctrl4_reg.regValue = IoReg_Read32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg);
	dpll_in_fsync_tracking_ctrl4_reg.new_fll_tracking_mul = multiplier;
	IoReg_Write32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL4_reg, dpll_in_fsync_tracking_ctrl4_reg.regValue);
	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	sys_dclkss_reg.dclk_ss_en = 1;
	sys_dclkss_reg.dclk_ss_load= 1;
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	ppoverlay_main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
	ppoverlay_main_display_control_rsv_reg.main_wd_to_free_run=0;
	IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, ppoverlay_main_display_control_rsv_reg.regValue);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	return result;
}
#if 0  //mark scalerlib control by qing_liu
#define _FRAMESYNC_LAST_LINE_PIXEL_STEP				1
#define _FRAMESYNC_LAST_LINE_PIXEL_THRESHOLD		100
unsigned char framesync_synclastlinefinetune_method_0(void)
{
	unsigned short DVTotal,DHTotal,DVTotal1,DHTotal1 ;
	unsigned short DclkOffset, timeout;
	measure_dvtotal_last_line_pixels_result1_RBUS measure_dvtotal_last_line_pixels_result1_reg;
	ppoverlay_measure_dvtotal_last_line_pixels_result2_RBUS measure_dvtotal_last_line_pixels_result2_reg;
	crt_sys_dclkss_RBUS dclkss_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
#if (_SELECT_MEASURE_MODE == SINGLE_MODE)
	unsigned short measure_timeout;
#endif //#if (_SELECT_MEASURE_MODE == SINGLE_MODE)
// [Code Sync][LewisLee][0990316][1]
	unsigned char InputSyncLoseCount = 0;
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	unsigned char i = 0;
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1][End]

	//scaledown_ich1_ibuff_status_RBUS ich1_ibuff_status_reg;
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS tuning5_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;

	unsigned short display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	unsigned char ucIVS2DVSDelay = Scaler_DispGetIvs2DvsDelay();

//mark scalerlib control by qing_liu
//	if(_FALSE == Scaler_Enter_FramesyncOpenFixLastLine_Condition())
		return _TRUE;

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

	msleep(10);

	//enable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_dvtotal_last_line_pixels(_ENABLE);
// [Code Sync][LewisLee][0990316][3][End]

	// Get the measure result for last line
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1]
	if(SLR_MAIN_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if(_FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}
	}
	else// if(SLR_SUB_DISPLAY == info->display)
	{
		for(i = 0; i<4; i++)
		{
			if(_FALSE == WaitFor_IVS2())
				InputSyncLoseCount++;
		}
	}

	if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
		goto FlxLastLine_Lose_Sync_finetune_Method_0;
// [Code Sync][LewisLee][0990316][1][End]
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	measure_timeout = 0xfff;
	measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
	while((_ENABLE == measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr) && measure_timeout)
	{
// [Code Sync][LewisLee][0990316][1]
//		info->display ? WaitFor_IVS2() : WaitFor_IVS1();
		if(SLR_MAIN_DISPLAY == display)
		{
			if(_FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		else// if(SLR_SUB_DISPLAY == info->display)
		{
			if(_FALSE == WaitFor_IVS2())
				InputSyncLoseCount++;
		}
#endif

		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_finetune_Method_0;
// [Code Sync][LewisLee][0990316][1][End]

		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_timeout--;
	}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

// [Code Sync][LewisLee][0990316][1]
	InputSyncLoseCount = 0;
// [Code Sync][LewisLee][0990316][1][End]

	measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
	DVTotal = measure_dvtotal_last_line_pixels_result1_reg.dv_total_value_first;
	DHTotal = measure_dvtotal_last_line_pixels_result1_reg.last_line_value_first;
	printk( "\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE

#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	display ? WaitFor_IVS2() : WaitFor_IVS1();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

	measure_dvtotal_last_line_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result2_reg);
	DHTotal += measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second;
	DHTotal = DHTotal >>1;
	printk("Measure second time DV total = %x\n", measure_dvtotal_last_line_pixels_result2_reg.dv_total_value_second);
	printk("Measure second time last line = %x\n", measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second);
	printk("Measure average last line = %x\n",DHTotal);
#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

	// Adjust Dclk offset to make last line equal to DH total
	if (DHTotal < _FRAMESYNC_LAST_LINE_PIXEL_THRESHOLD)
	{
		// enable last line
		goto EnableFlxLastLine_Method_0;
	}

	// Need to adjust Dclk offset
	printk("Need to adjust offset \n");
	//frank@0507 add timeout ask willy
	timeout = 100;
	while (timeout--){
		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		printk("Dclk offset data= %x\n", dclkss_reg.dclk_offset_11_0);
		DclkOffset = dclkss_reg.dclk_offset_11_0;//get dclk offset
		DclkOffset -= _FRAMESYNC_LAST_LINE_PIXEL_STEP;

		if (DclkOffset < 20) // CSW+ 0970327 Add protection for time out
			break;

		printk("Dclk offset after adjust = %x\n", DclkOffset);

		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_offset_11_0 = DclkOffset;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_ss_load = 1;
		dclkss_reg.dclk_ss_en = _ENABLE;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
// [Code Sync][LewisLee][0990316][1]
		if(SLR_MAIN_DISPLAY == display)
		{
			for(i = 0; i<4; i++)
			{
				if(_FALSE == WaitFor_IVS1())
					InputSyncLoseCount++;
			}

		}
		else// if(SLR_SUB_DISPLAY == info->display)
		{
			for(i = 0; i<4; i++)
			{
				//if(_FALSE == WaitFor_IVS2())
				//	InputSyncLoseCount++;
			}
		}

		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_finetune_Method_0;
// [Code Sync][LewisLee][0990316][1][End]
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		//enable measure
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr = _ENABLE;
		IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);

		measure_timeout = 0xfff;
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		while((_ENABLE == measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr) && measure_timeout)
		{
// [Code Sync][LewisLee][0990316][1]
//			info->display ? WaitFor_IVS2() : WaitFor_IVS1();
			if(SLR_MAIN_DISPLAY == display)
			{
				if(_FALSE == WaitFor_IVS1())
					InputSyncLoseCount++;
			}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
			else// if(SLR_SUB_DISPLAY == display)
			{
				//if(_FALSE == WaitFor_IVS2())
				//	InputSyncLoseCount++;
			}
#endif

			if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
				goto FlxLastLine_Lose_Sync_finetune_Method_0;
// [Code Sync][LewisLee][0990316][1][End]

			measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
			measure_timeout--;
		}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

// [Code Sync][LewisLee][0990316][1]
		InputSyncLoseCount = 0;
// [Code Sync][LewisLee][0990316][1][End]

		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		DVTotal = measure_dvtotal_last_line_pixels_result1_reg.dv_total_value_first;
		DHTotal = measure_dvtotal_last_line_pixels_result1_reg.last_line_value_first;
		printk("\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		//display ? WaitFor_IVS2() : WaitFor_IVS1();
		if (_MAIN_DISPLAY == display)
			WaitFor_IVS1();
		else
			; //WaitFor_IVS2();

#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		measure_dvtotal_last_line_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result2_reg);
		DVTotal1 = measure_dvtotal_last_line_pixels_result2_reg.dv_total_value_second;
		DHTotal1 = measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second;
		printk("Measure second time DV total = %x\n", measure_dvtotal_last_line_pixels_result2_reg.dv_total_value_second);
		printk("Measure second time last line = %x\n", measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second);

		DHTotal += DHTotal1;
		DHTotal = DHTotal>>1;
		printk("Measure average last line = %x\n",DHTotal);

#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

		if (DHTotal< _FRAMESYNC_LAST_LINE_PIXEL_THRESHOLD){
			printk("adjust offset,  final timeout : %x\n", timeout);
			break;
		}
	}

	EnableFlxLastLine_Method_0:
	// enable fix last line
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
//	dv_total_reg.dv_total = DVTotal - 1;
	dv_total_reg.dv_total = DVTotal;
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	printk("Dclk offset data= %x\n", dclkss_reg.dclk_offset_11_0);
	DclkOffset = dclkss_reg.dclk_offset_11_0;//get dclk offset
	DclkOffset += Scalsr_Get_Framesync_FixLastLine_DclkOffset_Step_Method0();
	dclkss_reg.dclk_offset_11_0 = DclkOffset;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);
	printk("Dclk offset after adjust = %x\n", dclkss_reg.dclk_offset_11_0);

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	// Setting value = ( real value -1) , Min. value 90
	if(DHTotal > 1)
	{
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = DHTotal&(~(_BIT0|_BIT1));
#endif
		dh_total_last_line_length_reg.dh_total_last_line = DHTotal - 1;
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	}
	else
	{
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = (DHTotal&(~(_BIT0|_BIT1))) -1 +4;
#endif
		dh_total_last_line_length_reg.dh_total_last_line = (DHTotal | _BIT0);
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	}

	//display ? WaitFor_IVS2() : WaitFor_IVS1();
	//display ? WaitFor_IVS2() : WaitFor_IVS1();
	if (SLR_MAIN_DISPLAY == display)
		WaitFor_IVS1();
	else
		; //WaitFor_IVS2();

	if (SLR_MAIN_DISPLAY == display)
		WaitFor_IVS1();
	else
		; //WaitFor_IVS2();


	//Lewis, 20080923, in full HD panel, the F & F-N*dF can not set too large
	//to prevent framesync error
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_freq_syn_slt = Scaler_Get_Framesync_FixLastLine_N_Value();
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	//step 9, Enable F and F-NdF switch
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_new_en = _DISABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_fix_last_line = _ENABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

// [Code Sync][LewisLee][0990708][1]
	//USER:LewisLee DATE:2010/07/08
	//if we fine tune fix last line, mayte let framesycn un-stable
	//so we can adjust IVS2DVS delay to fine tune it
	if(_CHANNEL1 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
	{
#if 0
		//ich1_ibuff_status_reg.regValue = IoReg_Read32(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR);

		if(_TRUE == ich1_ibuff_status_reg.fsync_ovf) //overflow
		{
			tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);

			if(tuning5_reg.iv2dv_line > 1)
			{
				ucIVS2DVSDelay -= 1;
				tuning5_reg.iv2dv_line -= 1;
				IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, tuning5_reg.regValue);

				//write clear error status
				ich1_ibuff_status_reg.ibuff_ovf = 1;
				ich1_ibuff_status_reg.fsync_ovf = 1;
				ich1_ibuff_status_reg.fsync_udf = 1;
				//IoReg_Write32(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR, ich1_ibuff_status_reg.regValue);
				Scaler_DispSetIvs2DvsDelay(ucIVS2DVSDelay);

				printk("dec IV2DV \n");
			}
		}
		else if(_TRUE == ich1_ibuff_status_reg.fsync_udf) //underflow
		{
			ucIVS2DVSDelay += 1;

			tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
			tuning5_reg.iv2dv_line += 1;
			IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, tuning5_reg.regValue);

			//write clear error status
			ich1_ibuff_status_reg.ibuff_ovf = 1;
			ich1_ibuff_status_reg.fsync_ovf = 1;
			ich1_ibuff_status_reg.fsync_udf = 1;
			//IoReg_Write32(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR, ich1_ibuff_status_reg.regValue);
			Scaler_DispSetIvs2DvsDelay(ucIVS2DVSDelay);

			printk("inc IV2DV \n");
		}
#endif
	}
// [Code Sync][LewisLee][0990708][1][End]

	return _TRUE;

// [Code Sync][LewisLee][0990316][1]
	FlxLastLine_Lose_Sync_finetune_Method_0:
	printk("Sync Lose at framesync_synclastlinefinetune\n");

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	//disable measure
// [Code Sync][LewisLee][0990316][3]
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);
// [Code Sync][LewisLee][0990316][3][End]

	return _FALSE;
// [Code Sync][LewisLee][0990316][1][End]
}

unsigned char framesync_synclastlinefinetune_method_1(void)
{
	unsigned short DVTotal,DHTotal,DVTotal1,DHTotal1 ;
	unsigned short DclkOffset, timeout;
	ppoverlay_measure_dvtotal_last_line_pixels_result1_RBUS measure_dvtotal_last_line_pixels_result1_reg;
	ppoverlay_measure_dvtotal_last_line_pixels_result2_RBUS measure_dvtotal_last_line_pixels_result2_reg;
	crt_sys_dclkss_RBUS dclkss_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
#if (_SELECT_MEASURE_MODE == SINGLE_MODE)
	unsigned short measure_timeout;
#endif //#if (_SELECT_MEASURE_MODE == SINGLE_MODE)
	unsigned char InputSyncLoseCount = 0;
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	unsigned char i = 0;
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	unsigned char AdjustDirect = _DCLK_OFFSET_DECREASE;

	//scaledown_ich1_ibuff_status_RBUS ich1_ibuff_status_reg;
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS tuning5_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;

	unsigned short display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	unsigned char ucIVS2DVSDelay = Scaler_DispGetIvs2DvsDelay();

	if(_FALSE == Scaler_Enter_FramesyncOpenFixLastLine_Condition())
		return _TRUE;

	//disable measure
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);

	msleep(10);

	//enable measure
	drvif_measure_dvtotal_last_line_pixels(_ENABLE);

	// Get the measure result for last line
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	if(SLR_MAIN_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if(_FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else// if(SLR_SUB_DISPLAY == display)
	{
		for(i = 0; i<4; i++)
		{
			if(_FALSE == WaitFor_IVS2())
				InputSyncLoseCount++;
		}
	}
#endif

	if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
		goto FlxLastLine_Lose_Sync_finetune_Method_1;
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	measure_timeout = 0xfff;
	measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
	while((_ENABLE == measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr) && measure_timeout)
	{
		if(SLR_MAIN_DISPLAY ==display)
		{
			if(_FALSE == WaitFor_IVS1())
				InputSyncLoseCount++;
		}

		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_finetune_Method_1;

		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_timeout--;
	}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

	InputSyncLoseCount = 0;

	measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
	DVTotal = measure_dvtotal_last_line_pixels_result1_reg.dv_total_value_first;
	DHTotal = measure_dvtotal_last_line_pixels_result1_reg.last_line_value_first;
	printk("\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE

#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
	display ? WaitFor_IVS2() : WaitFor_IVS1();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

	measure_dvtotal_last_line_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result2_reg);
	DHTotal += measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second;
	DHTotal = DHTotal >>1;
	printk("Measure second time DV total = %x\n", measure_dvtotal_last_line_pixels_result2_reg.dv_total_value_second);
	printk("Measure second time last line = %x\n", measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second);
	printk("Measure average last line = %x\n",DHTotal);
#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

	//Setting value = (real value - 1)
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
//	dv_total_reg.dv_total = DVTotal - 1;
	dv_total_reg.dv_total = DVTotal;
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	// Adjust Dclk offset to make last line equal to DH total
	if (DHTotal < _FRAMESYNC_LAST_LINE_PIXEL_THRESHOLD)
	{
		// enable last line
		goto EnableFlxLastLine_Method_1;
	}

	if(DHTotal > (Get_DISP_HORIZONTAL_TOTAL()/2))
	{
		AdjustDirect = _DCLK_OFFSET_DECREASE;

		// Need to adjust Dclk offset
		printk("Need to adjust offset, dec\n");
	}
	else // not jump to next line
	{
		AdjustDirect = _DCLK_OFFSET_INCREASE;

		// Need to adjust Dclk offset
		printk("Need to adjust offset, inc\n");
	}

	//frank@0507 add timeout ask willy
	timeout = 100;
	while (timeout--){
		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		printk("Dclk offset data= %x\n", dclkss_reg.dclk_offset_11_0);
		DclkOffset = dclkss_reg.dclk_offset_11_0;//get dclk offset

		if(_DCLK_OFFSET_DECREASE == AdjustDirect)
		{
			if(DclkOffset >= _FRAMESYNC_LAST_LINE_PIXEL_STEP)
				DclkOffset = DclkOffset - _FRAMESYNC_LAST_LINE_PIXEL_STEP;
			else
				printk("Dclk offset too small@dec\n");
		}
		else// if(_DCLK_OFFSET_INCREASE == AdjustDirect)
		{
			DclkOffset = DclkOffset + _FRAMESYNC_LAST_LINE_PIXEL_STEP;
		}

		if (DclkOffset < 20) // CSW+ 0970327 Add protection for time out
			break;

		printk("Dclk offset after adjust = %x\n", DclkOffset);

		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_offset_11_0 = DclkOffset;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
		dclkss_reg.dclk_ss_load = 1;
		dclkss_reg.dclk_ss_en = _ENABLE;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		if(SLR_MAIN_DISPLAY == display)
		{
			for(i = 0; i<4; i++)
			{
				if(_FALSE == WaitFor_IVS1())
					InputSyncLoseCount++;
			}
		}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		else// if(SLR_SUB_DISPLAY == display)
		{
			for(i = 0; i<4; i++)
			{
				if(_FALSE == WaitFor_IVS2())
					InputSyncLoseCount++;
			}
		}
#endif

		if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
			goto FlxLastLine_Lose_Sync_finetune_Method_1;
#else //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		//enable measure
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr = _ENABLE;
		IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);

		measure_timeout = 0xfff;
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		while((_ENABLE == measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr) && measure_timeout)
		{
			if(SLR_MAIN_DISPLAY == display)
			{
				if(_FALSE == WaitFor_IVS1())
					InputSyncLoseCount++;
			}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
			else// if(SLR_SUB_DISPLAY == display)
			{
				if(_FALSE == WaitFor_IVS2())
					InputSyncLoseCount++;
			}
#endif

			if(InputSyncLoseCount >= _INPUT_VSYNC_LOST_THRESHOLD)
				goto FlxLastLine_Lose_Sync_finetune_Method_1;

			measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
			measure_timeout--;
		}
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		InputSyncLoseCount = 0;

		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		DVTotal = measure_dvtotal_last_line_pixels_result1_reg.dv_total_value_first;
		DHTotal = measure_dvtotal_last_line_pixels_result1_reg.last_line_value_first;
		printk("\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

#ifdef _MEASURE_2FRAME_AT_ONCE
#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)
		display ? WaitFor_IVS2() : WaitFor_IVS1();
#endif //#if (_SELECT_MEASURE_MODE == CONTINUE_MODE)

		measure_dvtotal_last_line_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result2_reg);
		DVTotal1 = measure_dvtotal_last_line_pixels_result2_reg.dv_total_value_second;
		DHTotal1 = measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second;
		printk("Measure second time DV total = %x, last line = %x\n", DVTotal1, DHTotal1);

		DHTotal += DHTotal1;
		DHTotal = DHTotal>>1;
		printk("Measure average last line = %x\n",DHTotal);

#endif //#ifdef _MEASURE_2FRAME_AT_ONCE

		if (DHTotal < _FRAMESYNC_LAST_LINE_PIXEL_THRESHOLD){
			printk("adjust offset,  final timeout : %x\n", timeout);
			break;
		}
	}

	EnableFlxLastLine_Method_1:
	// enable fix last line
	//Setting value = (real value - 1)
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
//	dv_total_reg.dv_total = DVTotal - 1;
	dv_total_reg.dv_total = DVTotal;
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	//USER:LewisLee DATE:2012/04/25
	//modify rule, it should be cut last line pixel
	//don't change Dclk
	if(DHTotal > _FRC_LAST_LINE_PIXEL_OFFSET)
		DHTotal -= _FRC_LAST_LINE_PIXEL_OFFSET;
	else
		DHTotal = 1;//avoid 0-1 equal to -1

	//USER:LewisLee DATE:2010/07/16
	//for Edward request, let last line pixel is even at picasso platform
	if(DHTotal & _BIT0)
		DHTotal += 1;

	//last line pixel need as even
//	if(DHTotal & _BIT0)
//		DHTotal += 1;

	// Setting value = ( real value -1) , Min. value 90
	if(DHTotal > 1)
	{
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = DHTotal&(~(_BIT0|_BIT1));
#endif
		dh_total_last_line_length_reg.dh_total_last_line = DHTotal-1;
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	}
	else
	{
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
#if defined (ENABLE_QUADFHD)
		DHTotal = (DHTotal&(~(_BIT0|_BIT1))) - 1 + 4;
#endif
		dh_total_last_line_length_reg.dh_total_last_line = (DHTotal | _BIT0);
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	}

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	#ifdef CONFIG_DUAL_CHANNEL
	display ? WaitFor_IVS2() : WaitFor_IVS1();
	display ? WaitFor_IVS2() : WaitFor_IVS1();
	#else
	WaitFor_IVS1();
	WaitFor_IVS1();
	#endif



	// enable last line
	//Lewis, 20080923, in full HD panel, the F & F-N*dF can not set too large
	//to prevent framesync error
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_freq_syn_slt = Scaler_Get_Framesync_FixLastLine_N_Value();
	dclkss_reg.dclk_ss_load = 1;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	//step 9, Enable F and F-NdF switch
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_new_en = _DISABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_fix_last_line = _ENABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	//disable measure
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);

// [Code Sync][LewisLee][0990708][1]
	//USER:LewisLee DATE:2010/07/08
	//if we fine tune fix last line, mayte let framesycn un-stable
	//so we can adjust IVS2DVS delay to fine tune it
	if(_CHANNEL1 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
	{
#if 0
		//ich1_ibuff_status_reg.regValue = IoReg_Read32(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR);

		if(_TRUE == ich1_ibuff_status_reg.fsync_ovf) //overflow
		{
			tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);

			if(tuning5_reg.iv2dv_line > 1)
			{
				ucIVS2DVSDelay -= 1;
				tuning5_reg.iv2dv_line -= 1;
				IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, tuning5_reg.regValue);

				//write clear error status
				ich1_ibuff_status_reg.ibuff_ovf = 1;
				ich1_ibuff_status_reg.fsync_ovf = 1;
				ich1_ibuff_status_reg.fsync_udf = 1;
				//IoReg_Write32(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR, ich1_ibuff_status_reg.regValue);
				Scaler_DispSetIvs2DvsDelay(ucIVS2DVSDelay);

				printk("dec IV2DV \n");
			}
		}
		else if(_TRUE == ich1_ibuff_status_reg.fsync_udf) //underflow
		{
			ucIVS2DVSDelay += 1;

			tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
			tuning5_reg.iv2dv_line += 1;
			IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, tuning5_reg.regValue);

			//write clear error status
			ich1_ibuff_status_reg.ibuff_ovf = 1;
			ich1_ibuff_status_reg.fsync_ovf = 1;
			ich1_ibuff_status_reg.fsync_udf = 1;
			//IoReg_Write32(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR, ich1_ibuff_status_reg.regValue);
			Scaler_DispSetIvs2DvsDelay(ucIVS2DVSDelay);

			printk("inc IV2DV \n");
		}
#endif
	}
// [Code Sync][LewisLee][0990708][1][End]

	return _TRUE;

	FlxLastLine_Lose_Sync_finetune_Method_1:
	printk("Sync Lose at framesync_synclastlinefinetune\n");

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_frc_on_fsync = _FALSE;
	display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

	//disable measure
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);

	return _FALSE;
}
#endif

//USER:LewisLee DATE:2010/09/02
//check framesync fix last line state
unsigned char framesync_sync_fixlastline_mode(void)
{
//mark scalerlib control by qing_liu
//	if(_FALSE == Scaler_Enter_FramesyncOpenFixLastLine_Condition())
		return _FALSE;
#if 0
	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	if(_ENABLE == display_timing_ctrl1_reg.disp_fix_last_line)
		return _TRUE;

	return _FALSE;
#endif
}
#if 0   //mark scalerlib control by qing_liu
/**
* framesync_synclastlinefinetune
*  This function will Finetune last line problem
* @param <pDelta>       { Dclk offset}
*@return <result>  	 { Return TRUE if there is no timing change}
*/
static unsigned char framesync_synclastlinefinetune(unsigned short *pDelta)
{

	if(_TRUE == Scaler_Get_FramesyncOpenFixLastLineMethod0())
		return framesync_synclastlinefinetune_method_0();

	if(_TRUE == Scaler_Get_FramesyncOpenFixLastLineMethod1())
		return framesync_synclastlinefinetune_method_1();

	return _TRUE;
}
#endif
/**
* framesync_testsync
*  This function will Apply Dclk frequency and get the overflow/underflow information
* @param <usOffset>  {Dclk offset}
* @param <retValue>  {under/over flow status}
*@return <result>  	 {Return FALSE if there is no timing change}
*/
static unsigned char framesync_testsync(unsigned short usOffset, unsigned char* retValue)
{
	mdomain_cap_ich12_ibuff_status_RBUS mdomain_cap_ich12_ibuff_status_reg;

	// Apply Dclk frequency setting
	drvif_clock_offset(usOffset);

	//IoReg_SetBits(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR,  _BIT0|_BIT1|_BIT2);//write status

	mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);
	mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf = TRUE;
	mdomain_cap_ich12_ibuff_status_reg.fsync_ovf = TRUE;
	mdomain_cap_ich12_ibuff_status_reg.fsync_udf = TRUE;
	IoReg_Write32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg, mdomain_cap_ich12_ibuff_status_reg.regValue);

	//frank@09032010 wait one input frame
	WaitFor_IVS1_Done();
	WaitFor_IVS1_Done();
	//msleep(40);
 	// Save underflow/overflow information into pData[0]
	//*retValue = IoReg_ReadByte0(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR);
	//*retValue = ((*retValue) & ( _BIT1 | _BIT0)) ;//frank@0625 add BIT2 to check frame sync error

	mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);

	if((TRUE == mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf) || (TRUE == mdomain_cap_ich12_ibuff_status_reg.fsync_ovf))
		*retValue = (*retValue) &  _BIT1;

	if(TRUE == mdomain_cap_ich12_ibuff_status_reg.fsync_udf)
		*retValue = (*retValue) &  _BIT0;

	return FALSE;                                          // Success
 }

/**
* framesync_spreadspectrumfinetune
*  This function will Finetune Dclk offset for spread spectrum
* @param <pDelta>       { Dclk offset}
*@return <result>  	 { Return FALSE if there is no timing change}
*/
#if 0
unsigned char Scaler_GetSpreadSpectrum(unsigned char src_idx)
{
	return fwif_color_get_spread_spectrum(src_idx);
}
#endif
static unsigned char framesync_spreadspectrumfinetune(unsigned short *pDelta)
{
	unsigned char Data = 0;
//fixme:vip
//	drv_adjust_spreadspectrumrange(Scaler_GetSpreadSpectrum(SLR_MAIN_DISPLAY));
	if(framesync_testsync(*pDelta, &Data)) {
		return 0;
	}
	if(Data & 0x03)
		return 2;

	return 0;
 }

int error_flag = 0;

/**
* drvif_framesync_offlinemeasureendevent
*  This function will Measure start/end polling event
* @param <None>
*@return <result>  	 {Return TRUE if measure finished}
*/
unsigned char drvif_framesync_offlinemeasureendevent(void)
{
	offms_sp_ms3stus_RBUS offms_sp_ms3stus_reg;
	offms_sp_ms3ctrl_RBUS offms_sp_ms3ctrl_reg;

	offms_sp_ms3ctrl_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);

	if(_DISABLE == offms_sp_ms3stus_reg.off_ms_now) //measure ack finish
	{
		offms_sp_ms3stus_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Stus_reg);

		if(_OFF_MEAS_TO_SEL == _OFF_MEAS_TO_SEL_76MS)
		{
			if(offms_sp_ms3stus_reg.off_vs_per_to_long)
				goto RESTART_FRAMESYNC_OFFLINE_MEASURE;
			else
				return TRUE;  // off-line measure is ready
		}
		else// if(_OFF_MEAS_TO_SEL == _OFF_MEAS_TO_SEL_38MS)
		{
			if(offms_sp_ms3stus_reg.off_vs_per_to)
				goto RESTART_FRAMESYNC_OFFLINE_MEASURE;
			else
				return TRUE;  // off-line measure is ready
		}
	}

	return FALSE; //measure not finish

	RESTART_FRAMESYNC_OFFLINE_MEASURE:
	//have error status,restart measure
	error_flag++;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"ERROR measure times %d\n",error_flag);
	drv_adjust_syncprocessormeasurestart();
	return FALSE;
}

/**
* framesync_fast_get_sync_point
*  This function will Calculate the suitable framesync point
* @param <None>
*@return <result>  	 {Return Dclk offset}
*/
static unsigned short framesync_fast_get_sync_point(void)
{
//CSW+ 0961214 new code for frame sync by tyan
	unsigned long long offset = 0;
	unsigned long aclkcnt = 0;

	unsigned long long faclkcnt;
	unsigned long long ulFreq;
	unsigned char div = 1, cpc, cnt = 0;
	unsigned short nMCode, nNCode;
	unsigned char timeoutcnt = 50;	// Tracking timeout 60ms
	unsigned int ulResult;
	unsigned long long ulparam1 =0;
	unsigned long ulparam2 =0;

	//msleep(1000);
	//frank@0109 odd field delay even field by 1 progressive line
	/* don't cut lines of di */
	IoReg_ClearBits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT8);

	// Measure input active region by xtal clk & Enable active region measure
	IoReg_Mask32(OFFMS_SP_MS3EnAtvCtrl_reg, ~(_BIT6 | _BIT7), _BIT6);
	//frank@0630 mark IoReg_WriteByte1(SYNCPROCESSOR_SP1_CTRL_VADDR, 1);

	// Enable DPLL Frequence tuning
	IoReg_SetBits(PLL27X_REG_SYS_PLL_DISP2_reg, _BIT20 | _BIT21);
	//Enable DDS Spread Spectrum Output Function
	IoReg_SetBits(PLL27X_REG_SYS_DCLKSS_reg, _BIT0);

	if(Scaler_InputSrcGetMainChType()==_SRC_VO){
		SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
		//if ( Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP) )
		if(TRUE == fwif_scaler_decide_display_cut4line(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))){
			ulparam1 = 27000000*(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
    		ulparam2 = (unsigned long)pVOInfo->pixel_clk;
			//faclkcnt = 27000000*(unsigned long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID))/(unsigned long)pVOInfo->pixel_clk;
			do_div(ulparam1, ulparam2);
			faclkcnt = ulparam1;
			// DI will remove 4 lines per frame ( 2 lines per field ), so we have to -2 more lines in active length.
		}else{
			ulparam1 = 27000000*(unsigned long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
    		ulparam2 = (unsigned long)pVOInfo->pixel_clk;
			//faclkcnt = 27000000*(unsigned long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID))/(unsigned long)pVOInfo->pixel_clk;
			do_div(ulparam1, ulparam2);
			faclkcnt = ulparam1;
		}
		aclkcnt = faclkcnt;
	}

#ifdef CONFIG_INPUT_SOURCE_IPG
	else if(Scaler_InputSrcGetMainChType()==_SRC_IPG){
		//if ( Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP) ){
		if(TRUE == fwif_scaler_decide_display_cut4line(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)){
			faclkcnt = 27000000.0*(FLOAT64)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID))/
				(double)(13487760); //h total * v total * frame rate
			// DI will remove 4 lines per frame ( 2 lines per field ), so we have to -2 more lines in active length.
		}
		else{
				faclkcnt = 27000000.0*(double)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID))/
				(double)(13487760); //h total * v total * frame rate
		}
		aclkcnt = (unsigned long)faclkcnt;
	}
#endif
	else{
	    	// Off-line measure start
		drv_adjust_syncprocessormeasurestart();
		error_flag = 0;
		do {
	   	msleep(20);

	   	if(drvif_framesync_offlinemeasureendevent())
		 		break;
		}while(--timeoutcnt);
		//error happened
		if(timeoutcnt == 0){
			offset = 0xfff;
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "Fast frame sync OffLineMeasure ERROR : off-line measure status polling time-out!!\n");
			IoReg_ClearBits(OFFMS_SP_MS3EnAtvCtrl_reg, _BIT6);
			return offset;
		}

		IoReg_SetBits(OFFMS_SP_MS3Ctrl_reg, _BIT12);  // off-line measure pop-up
		timeoutcnt = 3;
		do {
			msleep(10);
			ulResult = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);
			if(!(ulResult & _BIT12)) // polling start bit
				break;
		} while (--timeoutcnt);
		//error happened
		if (timeoutcnt == 0x00) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"measure aclkcount popup ERROR1\n");
			offset = 0xfff;
			return offset;
		}
		aclkcnt = IoReg_Read32(OFFMS_SP_MS3EnAtvCtrl_reg) & 0x00ffffff;
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n aclkcnt =%x  _DISP_LEN = %x !!\n", (unsigned int)aclkcnt,(unsigned int)_DISP_LEN);//test by tyan

	//printk( "Read DPLL_M=%x, div=%x in FastDo\n", mcode, div);
	if((aclkcnt == 0)||(_DISP_LEN ==0)){
		offset = 0xfff;
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n aclkcnt =%x  _DISP_LEN = %x !!\n", (unsigned int)aclkcnt, (unsigned int)_DISP_LEN);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "Fast frame sync OffLineMeasure ERROR : off-line measure status polling time-out!!\n");
		return offset;
	}

	IoReg_ClearBits(OFFMS_SP_MS3Ctrl_reg, _BIT9|_BIT10);  // clear off-line measureing flag

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n\n  info->IPV_ACT_LEN=%x  info->IPH_ACT_WID = %x !!\n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN),Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "disp_h_total=%d, disp_len=%d, disp_wid=%d\n",Get_DISP_HORIZONTAL_TOTAL(), _DISP_LEN, _DISP_WID);

//	ulFreq = (unsigned int)(((unsigned long long)(Get_DISP_HORIZONTAL_TOTAL()+1)*(_DISP_LEN-1)+_DISP_WID)*27000000/aclkcnt);
	//USER:LewisLee DATE:2010/09/15
	//we should not add 1 for DHtotal
	ulparam1 = ((Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID)*27000000;
    ulparam2 = aclkcnt;
	//ulFreq = (unsigned int)(((unsigned long long)(Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID)*27000000/aclkcnt);
	do_div(ulparam1, ulparam2);
	ulFreq = ulparam1;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n ulFreq (dclk) = %lld Hz, max dclk = %d Hz", ulFreq, Get_DISPLAY_CLOCK_MAX()*1000000 );

	if ( ulFreq > Get_DISPLAY_CLOCK_MAX()*1000000 ) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n !!!!! DClk > Panel Max DClk !!!!!" );
	}

	if (Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() == 0)
	{
		//frank@1231 avoid DCLK set uncorrect value let D-domain fail
		if((ulFreq > (Get_DISPLAY_CLOCK_MAX()*1000000*3/2))||(ulFreq < (Get_DISPLAY_CLOCK_MAX()*1000000*1/2))){
			offset = 0xfff;
			return offset;
		}
	}

	if((ulFreq<=234000000) && (ulFreq>=46800000))
		div=1;
	else if((ulFreq<=117000000) && (ulFreq>=23400000))
		div=2;
	else if((ulFreq<=58000000) && (ulFreq>=11700000))
		div=4;
	else if((ulFreq<=29200000) && (ulFreq>=5850000))
		div=8;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n DIV = %x",div);

	//Ncode/Mcode=2*16*Div*(DHtotal*DVactive-DH_porch)/(15*aclkcnt)
	//USER:LewisLee DATE:2010/09/15
	//we should not add 1 for DHtotal
	ulparam1 = 2*16*div*1000*((Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID);
    ulparam2 = (15*aclkcnt);
//	offset = (unsigned long long)2*16*div*1000*((Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID)/(15*aclkcnt);
	do_div(ulparam1, ulparam2);
	offset = ulparam1;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n nMCode /nNCode= %x", (unsigned int)offset);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n offset = %x",(unsigned int)offset);

	for(cnt=3;cnt<=15;cnt++){
		nNCode=cnt;
		ulparam1 = nNCode*2*offset;
    	ulparam2 = 1000;
		//nMCode=nNCode*2*offset/1000;
		do_div(ulparam1, ulparam2);
		nMCode = ulparam1;
		nMCode = ((nMCode >> 1) + (nMCode & 0x01));
		if ((nMCode<=255)&&(nMCode>=3))
			break;
	}

	cpc = drvif_clock_cal_cpc(nMCode,nNCode);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"div=%d,n=%d,m=%d,aclkcnt=%d\n",div,nNCode,nMCode,(unsigned int)aclkcnt);
	drvif_clock_set_pll(nMCode, nNCode, div, cpc);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "Set Pll Reg = %x\n", IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_reg));
#if 0 //frank@0225 mark below code
	//DPLL WD Status register is Abnormal
	if(IoReg_ReadByte0(SYSTEM_PLL_WDOUT_VADDR)  & _BIT5){
		IoReg_ClearBits(SYSTEM_PLL_DISP2_VADDR, _BIT0);//DPll power down
		msleep(5);//frank@0430 Change busy delay to save time
		IoReg_SetBits(SYSTEM_PLL_DISP2_VADDR, _BIT0);//DPll power on
	}
#endif
	ulparam1 = 32768-(unsigned long long)32768*2*div*nNCode*((Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID);
    ulparam2 = (nMCode*aclkcnt);
	//offset =(unsigned long long)32768-(unsigned long long)32768*2*div*nNCode*((Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID)/(nMCode*aclkcnt);
	do_div(ulparam1, ulparam2);
	offset = ulparam1;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n DClock offset1 = %x\n",(unsigned short) offset);
	drvif_clock_offset((unsigned short) offset);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "offset = %x in FastDo\n", (unsigned short) offset);

	IoReg_ClearBits(OFFMS_SP_MS3EnAtvCtrl_reg, _BIT6);

	return (unsigned short)offset;

}

//lewis 20090812, set syncprocessor off line measure source,
//to prevent PIP mode swap/on/off, the off line measure source switch to other path
void drv_framesync_set_offline_ms_src(void)
{
	offms_sp_ms3ctrl_RBUS offms_sp_ms3ctrl_reg;
	switch(Scaler_InputSrcGetMainChType())
	{
		case _SRC_YPBPR:
//		case _SRC_COMPONENT:
			offms_sp_ms3ctrl_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);
			offms_sp_ms3ctrl_reg.off_meas_source = _OFFLINE_MS_SRC_DEHV1;
			offms_sp_ms3ctrl_reg.off_sycms_mode = ANALOG_MODE_MEASUREMENT;
			IoReg_Write32(OFFMS_SP_MS3Ctrl_reg, offms_sp_ms3ctrl_reg.regValue);
		break;

		case _SRC_VGA:
			if(SEPARATE_MODE == VGA_Detect_SyncTypeMode())
			{
				offms_sp_ms3ctrl_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);
				offms_sp_ms3ctrl_reg.off_meas_source = _OFFLINE_MS_SRC_RAWHV1;
				offms_sp_ms3ctrl_reg.off_sycms_mode = ANALOG_MODE_MEASUREMENT;
				IoReg_Write32(OFFMS_SP_MS3Ctrl_reg, offms_sp_ms3ctrl_reg.regValue);
			}
			else
			{
				offms_sp_ms3ctrl_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);
				offms_sp_ms3ctrl_reg.off_meas_source = _OFFLINE_MS_SRC_DEHV1;
				offms_sp_ms3ctrl_reg.off_sycms_mode = ANALOG_MODE_MEASUREMENT;
				IoReg_Write32(OFFMS_SP_MS3Ctrl_reg, offms_sp_ms3ctrl_reg.regValue);
			}
		break;

		case _SRC_HDMI:
			offms_sp_ms3ctrl_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);
			offms_sp_ms3ctrl_reg.off_meas_source = _OFFLINE_MS_SRC_HDMI;
			offms_sp_ms3ctrl_reg.off_sycms_mode = DIGITAL_MODE_MEASUREMENT;
			IoReg_Write32(OFFMS_SP_MS3Ctrl_reg, offms_sp_ms3ctrl_reg.regValue);
		break;

		case _SRC_TV:
		case _SRC_CVBS:
		case _SRC_SV:
		case _SRC_SCART:
		case _SRC_SCART_RGB:
			offms_sp_ms3ctrl_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);
			offms_sp_ms3ctrl_reg.off_meas_source = _OFFLINE_MS_SRC_VDC;
			offms_sp_ms3ctrl_reg.off_sycms_mode = ANALOG_MODE_MEASUREMENT;
			IoReg_Write32(OFFMS_SP_MS3Ctrl_reg, offms_sp_ms3ctrl_reg.regValue);
		break;

		default:
			//do nothing
		break;
	}
}




//--------------------------------------------------
// Description  : Adjust front porch size to meet frame sync
// Input Value  : None
// Output Value : Return 0 if sucess
//--------------------------------------------------
/**
* drvif_framesync_front_porch_check
*  This function will check and mpdify front porch
* @param <None>
*@return <None>
*/
void drvif_framesync_front_porch_check(void)
{
// [Code Sync][LewisLee][0990712][1]
	//USER:LewisLee DATE:2010/07/12
	//we need let front porch large than 4, or change IVS2DVS delay
	unsigned short _VGIP_V_Porch_temp = 0, porch_offset = 0;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_length_reg;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
//	vgip_chn2_act_vsta_length_RBUS vgip_chn2_act_vsta_length_reg;
#endif
	unsigned short ivst;

	if (_FALSE == Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
		return;

	_VGIP_V_Porch_temp = Scaler_DispGetInputInfo(SLR_INPUT_V_LEN) - Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);

	ivst = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);

	if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP))
		_VGIP_V_Porch_temp = _VGIP_V_Porch_temp<<1;


	if(_VGIP_V_Porch_temp >= _PROGRAM_VDELAY)
	{
		if((_VGIP_V_Porch_temp - ivst) < _PROGRAM_VDELAY)
		{
			porch_offset = _PROGRAM_VDELAY - (_VGIP_V_Porch_temp - ivst);

			if(ivst > porch_offset)
				ivst -= porch_offset;

			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"framesync_update_ivs_position, change Vstart to :%x\n", ivst);

			if(_CHANNEL1 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
			{
				vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
				vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta = ivst;
				IoReg_Write32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg, vgip_chn1_act_vsta_length_reg.regValue);
			}

			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,ivst);

		}
	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"framesync_update_ivs_position, porch <= 5\n");
	}
// [Code Sync][LewisLee][0990712][1][End]
}

unsigned int drvif_framesync_get_vo_clk(void)
{
	pll_reg_sys_pll_vodma1_RBUS pll_vodma1_reg;
	unsigned int vo_clk;
	unsigned char nMCode;
	unsigned char nNCode;
	unsigned char nOCode;

	//read pll_vodma
	 pll_vodma1_reg.regValue= IoReg_Read32(PLL_REG_SYS_PLL_VODMA1_reg); //0xb8000160
	 nMCode = pll_vodma1_reg.pllvodma_m;
	 nNCode = pll_vodma1_reg.pllvodma_n;
	 nOCode = pll_vodma1_reg.pllvodma_o;
	 vo_clk = (27000000*(nMCode+2))/(nNCode+1)/(nOCode+1);
	 rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n\n [%s][%s][%d] vo_clk : %d \n\n", __FILE__, __FUNCTION__, __LINE__, vo_clk);
	 return vo_clk;
}

//#define FIXED_DVST      22
//#define FIXED_IV2DVDLY  5
unsigned char drvif_framesync_gatting_do(void)
{
	//Lewis, move it to VIO_Interface.h
	//#define FIXED_DVST      22
	//#define FIXED_IV2DVDLY  7
	/* fix value for gatting clk */
//	dv_den_start_end_RBUS dvden_1802801c;
//	fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
	mdomain_cap_main_sdnr_cxxto64_RBUS mdomain_cap_main_sdnr_cxxto64_reg;
#ifdef CONFIG_DUAL_CHANNEL
	mdomain_cap_sub_sdnr_cxxto64_RBUS mdomain_cap_sub_sdnr_cxxto64_reg;
#endif

	//fs_iv_dv_fine_tuning3_RBUS fs_iv_dv_fine_tuning3;
//	unsigned int iv2dv_dly;
//	unsigned int line_delay;
//	unsigned int fixed_dvst, iv2dv_dly;
//	unsigned int MLines = 0;
	unsigned int framerate = 60;

	if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) % 10) != 0)
		framerate = (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)+10)/10;
	else
		framerate = (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ))/10;

	/*if(framerate >110)
		framerate = 120;
	else if(framerate >90)
		framerate = 100;*/
	//frank@0327 add below code to solve Data framesync DVS not sync IVS
	display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	display_timing_ctrl2_reg.frc2fsync_en = 0;
	//display_timing_ctrl2_reg.shpnr_line_mode = 2;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);
	//frank@04082013 add below code close DTG pattern generator to solve Data FS fail.
	drvif_scalerdisplay_force_black_bg(0);

	fw_scaler_enable_fs_wdg(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);
	drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);

//	SET_PANEL_DCLK_DIV(1); //mag2 un-used dclk sel, move to dpll_o
	drvif_clock_set_dclk2(Get_DISP_HORIZONTAL_TOTAL() , Get_DISP_VERTICAL_TOTAL(), framerate);
#if 0
	fs_iv_dv_fine_tuning5.regValue  = 0;
	line_delay = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);

	if(line_delay > Get_DISP_DEN_STA_VPOS())
		iv2dv_dly = line_delay-Get_DISP_DEN_STA_VPOS()+3;
	else
		iv2dv_dly = 1;

	/* dtg: alway refer to panel size */
	fs_iv_dv_fine_tuning5.iv2dv_line = iv2dv_dly;
	fs_iv_dv_fine_tuning5.iv2dv_line_2 = iv2dv_dly;
	fw_scaler_enable_fs_wdg(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : MDOMAIN_DISP_DDR_MainCtrl_reg,  _BIT2| _BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0));
	IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg ,  _BIT0);
	while(!(IoReg_Read32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : MDOMAIN_DISP_DDR_MainCtrl_reg)&(_BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0))));
#else
	IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_DDR_MainCtrl_reg,  _BIT2|_BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0));
	// write data & enable double buffer
	IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg ,	_BIT0);
	while(!(IoReg_Read32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SUBSTATUS_VADDR : */MDOMAIN_DDR_MAINSTATUS_VADDR)&(_BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0))));
#endif
	/* fix dvst for gatting clk */
	/* fix iv2dv delay for gatting clk */
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5.regValue);
	//frank@0811 add for gating framesync fail
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, 0);
#endif

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : MDOMAIN_DISP_DDR_MainCtrl_reg,  _BIT2|_BIT1|_BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0));
	IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg,  _BIT0);
	while(!(IoReg_Read32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : MDOMAIN_DISP_DDR_MainCtrl_reg)&(_BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0))));
#else
	IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_DDR_MainCtrl_reg,  _BIT2|_BIT1|_BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0));
	// write data & enable double buffe
	IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg ,	_BIT0);
	while(!(IoReg_Read32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_DDR_MainCtrl_reg)&(_BIT17|(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT)?_BIT16:0))));
#endif

#ifdef CONFIG_DUAL_CHANNEL  /*SDNR output bit and sort format, new add in magellan2 @Crixus 20150330*/
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) { /*main channel*/
		mdomain_cap_main_sdnr_cxxto64_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg);
		mdomain_cap_main_sdnr_cxxto64_reg.out_bit = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT);
		mdomain_cap_main_sdnr_cxxto64_reg.sort_fmt = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP) ? 0 : 1;
		IoReg_Write32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg, mdomain_cap_main_sdnr_cxxto64_reg.regValue);
	} else {
		mdomain_cap_sub_sdnr_cxxto64_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Sub_SDNR_cxxto64_reg);
		mdomain_cap_sub_sdnr_cxxto64_reg.sub_out_bit = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT);
		mdomain_cap_sub_sdnr_cxxto64_reg.sub_sort_fmt = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP) ? 0 : 1;
		IoReg_Write32(MDOMAIN_CAP_Sub_SDNR_cxxto64_reg, mdomain_cap_sub_sdnr_cxxto64_reg.regValue);
	}
#else
	mdomain_cap_main_sdnr_cxxto64_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg);
	mdomain_cap_main_sdnr_cxxto64_reg.out_bit = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT);
	mdomain_cap_main_sdnr_cxxto64_reg.sort_fmt = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP) ? 0 : 1;
	IoReg_Write32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg, mdomain_cap_main_sdnr_cxxto64_reg.regValue);
#endif

	framesync_set_iv2dv_delay();

	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	//frank@1121 mark do by below code rtdf_clearBits(PPOVERLAY_Display_Timing_CTRL1_reg, _BIT29);
	drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
	//frank@1121 mark do by later code fw_scaler_enable_fs_wdg(info->display, FALSE);
	return 0;
}


// VO source interlaced SD video (480i/576i) frame sync timing control
unsigned char drvif_decide_VO_SD_video_frameSync_enable(void)
{
	return framesync_vo_sd_fs_enable_flg;
}

void drvif_framesync_gatting(unsigned char enable)
{
	unsigned int clkgen_reg = 0;//, free_period = 0;
	static unsigned int ori_divider_num = 0;
	static unsigned int ori_ratio_num = 0;
	unsigned int ratio_num = 0;
	unsigned int divider_num = 0;
	//unsigned int source_clk = 0;
	unsigned int voAddr = 0;
	unsigned int vo_clk = 0;
	mdomain_cap_ich12_ibuff_status_RBUS mdomain_cap_ich12_ibuff_status_reg;
	SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
//	pll27x_reg_pll_ssc4_RBUS pll_ssc4_reg;
//	unsigned char sscg_enable = 0;

	if(Scaler_Get_CurVoInfo_VoVideoPlane(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == VO_VIDEO_PLANE_V2)
		voAddr = VODMA2_VODMA2_CLKGEN_reg;
	else
		voAddr = VODMA_VODMA_CLKGEN_reg;
	if(enable){

		if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX){

			//chroma Error
			if(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) < 500)
				IoReg_SetBits(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, _BIT31);
			else
				IoReg_ClearBits(DI_IM_DI_FRAMESOBEL_STATISTIC_reg, _BIT31);

		//	UINT32 regVal = IoReg_Read32(VODMA_VODMA_PVS0_Gen_reg);
			IoReg_ClearBits(VODMA_VODMA_PVS0_Gen_reg, _BIT31);
			msleep(20);
			IoReg_Mask32(VODMA_VODMA_PVS0_Gen_reg, ~(_BIT24|_BIT25|_BIT26), _BIT25);
			msleep(20);
			IoReg_SetBits(VODMA_VODMA_PVS0_Gen_reg, _BIT31);
		}

		if(ori_ratio_num == 0)
		{
			//Open VODMA gating
			clkgen_reg = IoReg_Read32(voAddr);
			ori_divider_num = (clkgen_reg&0x0f800000)>>23;
			ori_ratio_num = (clkgen_reg&0x001f0000)>>16;
			ratio_num = ori_ratio_num;
			{ //1080i/P case
#ifdef CONFIG_ALL_SOURCE_DATA_FS
				//mac5p force vo clk for 2k1k datafs
				divider_num = 1;
				ratio_num = 0;
#else

				// [VO] frame sync timing clock control for VO source (reducing the bandwidth usage)
				if(Scaler_InputSrcGetMainChType() == _SRC_VO){
					// [DI] bandwidth not enough for DI, VO clock need do division
					if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE) == TRUE)
					{
						unsigned int source_clk = 0;
					//	UINT32 picWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);

						source_clk = pVOInfo->pixel_clk/1000000;
						vo_clk = (drvif_framesync_get_vo_clk()/1000000);

						if(vo_clk >= 300){
							ratio_num = 32-((32*source_clk)/150);
							rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"################ source_clk=%d, ratio_num=%d\n", source_clk, ratio_num);
							if(ratio_num > 19){
								divider_num = 1;
								ratio_num = 0;
							}else if((ratio_num <= 19)&&(ratio_num >2)){
								divider_num = 0;
								ratio_num = 5;
							}else{
								divider_num = 0;
								ratio_num = 0;
							}
						}else if((vo_clk >= 250) && (vo_clk < 260)){
							ratio_num = 32-((32*source_clk)/(vo_clk/2));
							rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"################ source_clk=%d, ratio_num=%d\n", source_clk, ratio_num);
							divider_num = 0;
							if(ratio_num >2){
								divider_num = 0;
								ratio_num = 3;
							}else{
								divider_num = 0;
								ratio_num = 0;
							}
						}else if((vo_clk >= 180) && (vo_clk < 200)){
							ratio_num = 32-((32*source_clk)/vo_clk);
							rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"################ source_clk=%d, ratio_num=%d\n", source_clk, ratio_num);
							divider_num = 0;

							if(ratio_num >20){
								divider_num = 0;
								ratio_num = 2;
							}else{
								divider_num = 0;
								ratio_num = 0;
							}
						}else{
							rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###### [WARNING][%s] [line:%d]  No match vo gating clk !########  \n", __FUNCTION__, __LINE__);
						}

					}
					// [RTNR] bandwidth not enough for RTNR, VO clock need do division
					else {
					#define _VZU_GATTING_THRES	100
						unsigned int source_clk = 0;
						UINT32 picWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
					//	UINT32 picLen = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
					//	UINT32 dispLen =Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);

									  source_clk = pVOInfo->pixel_clk/1000000;
						vo_clk = (drvif_framesync_get_vo_clk()/1000000);
						if(vo_clk >= 300){
						ratio_num = 32-((32*source_clk)/300);
						rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"################ source_clk=%d, ratio_num=%d\n", source_clk, ratio_num);
							divider_num = 0;
							if(ratio_num > 27){
								divider_num = 2;
								ratio_num = 0;
							}else if((ratio_num <= 26)&&(ratio_num >17)){
								divider_num = 1;
								ratio_num = 0;
							}else if((ratio_num <= 17)&&(ratio_num >3)){
								divider_num = 0;
								ratio_num = 5;
							}else{
								divider_num = 0;
								ratio_num = 0;
							}
						}else if((vo_clk >= 250) && (vo_clk < 260)){
							ratio_num = 32-((32*source_clk)/vo_clk);
							rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"################ source_clk=%d, ratio_num=%d\n", source_clk, ratio_num);
							divider_num = 0;
							if(ratio_num >3){
								divider_num = 0;
								ratio_num = 3;
							}else{
								divider_num = 0;
								ratio_num = 0;
							}
						}else if((vo_clk >= 180) && (vo_clk < 200)){
							ratio_num = 32-((32*source_clk)/vo_clk);
							rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"################ source_clk=%d, ratio_num=%d\n", source_clk, ratio_num);
							divider_num = 0;

							if(ratio_num >20){
								divider_num = 0;
								ratio_num = 2;
							}else{
								divider_num = 0;
								ratio_num = 0;
							}
						}else{
							rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###### [WARNING][%s] [line:%d]  No match vo gating clk !########  \n", __FUNCTION__, __LINE__);
						}



						if(picWidth >=3000){//	4k2k case
							if(source_clk <280){ // 4k2k 24/25
								ratio_num = 0;
								divider_num = 1;
							}
							else{
								ratio_num = 0;
								divider_num = 0;
							}
						}

						//divider_num = 0;
						rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[vo] ratio_num For RTNR=%d\n", ratio_num);
					}
					if(Get_vo_smoothtoggle_timingchange_flag(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))  {
						ratio_num = 0;
						divider_num = 0;
					}
			#if 0
					if((vo_force_data_mode_get_enable()>=SLR_DISPLAY_DATA_FRAME_SYNC)&&(vo_force_data_mode_get_enable()<=SLR_DISPLAY_DATA_FS_AND_CUSTOM_MODE))
					{
						divider_num = 0;

						if(vo_clk >= 300)
							ratio_num=5;
						else if((vo_clk >= 250) && (vo_clk < 260))
							ratio_num=3;
						else if((vo_clk >= 180) && (vo_clk < 200))
							ratio_num=0;
						// rika 20140519 set vo clock cause mac2 200,sirisu 330
					}
			#endif
					//Fix me later, only for experiment
					ratio_num = 0;
					divider_num = 0;
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"################ div=%d, ratio_num=%d\n", divider_num, ratio_num);
				}else
				/*if(pVOInfo->pixel_clk < 200000000){//200MHZ
					if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE)) {
											source_clk = pVOInfo->pixel_clk/1000000;
						ratio_num = 32-((32*source_clk)/150);
						ratio_num -= 3;
					}else{
						source_clk = pVOInfo->pixel_clk/1000000;
						ratio_num = 32-((32*source_clk)/300);
						ratio_num -= 3;
					}
				}else*/{ //300MHZ case
					ratio_num = 0;
				}
#endif
				clkgen_reg = (clkgen_reg &(~0x0f9f0000))|(divider_num<<23)|(ratio_num<<16);
			}

			/*pll_ssc4_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
			if(pll_ssc4_reg.en_ssc == 1){
				sscg_enable = 1;
				pll_ssc4_reg.en_ssc = 0;
				IoReg_Write32(PLL27X_REG_PLL_SSC4_reg,pll_ssc4_reg.regValue);
				msleep(20);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[vo] gating, disable SSCG. \n");
			}*/
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "### (voAddr %x) => %x ### \n", voAddr, IoReg_Read32(voAddr));

			IoReg_Write32(voAddr, clkgen_reg); //increase clk
			clkgen_reg |= 0x1;
			if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY)
				clkgen_reg |= 0x2;
			//WaitFor_IVS1_Done();//Will mark no need
			//WaitFor_IVS1_Done();//Will mark no need
			/*WaitFor_DEN_STOP();*/
			if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 450) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 550)) {
				//[WOSQRTK-4419] Framesync + 50 framerate, we need to wait increase clk stable
				msleep(30);//50 framerate  wait 1 frame
			}
			WaitFor_IVS1();
			IoReg_Write32(voAddr, clkgen_reg); //gating on
			msleep(50);
			//WaitFor_IVS1_Done();//Will mark no need
			//WaitFor_IVS1_Done();//Will mark no need
			//Write Clear
			mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);
			mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf = TRUE;
			mdomain_cap_ich12_ibuff_status_reg.fsync_ovf = TRUE;
			mdomain_cap_ich12_ibuff_status_reg.fsync_udf = TRUE;
			IoReg_Write32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg, mdomain_cap_ich12_ibuff_status_reg.regValue);
			//IoReg_SetBits(SCALEDOWN_ICH1_IBUFF_STATUS_VADDR,	_BIT0|_BIT1|_BIT2);//write status
			//frank@09032010 wait one input frame
			//WaitFor_IVS1_Done();//Will mark no need
			//WaitFor_IVS1_Done();//Will mark no need
			/*if(sscg_enable == 1){
				pll_ssc4_reg.en_ssc = 1;
				IoReg_Write32(PLL27X_REG_PLL_SSC4_reg,pll_ssc4_reg.regValue);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[vo] gating, enable SSCG. \n");
			}*/

		}
	}else{

		if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX){
			IoReg_ClearBits(PPOVERLAY_Display_Timing_CTRL1_reg, _BIT26);
		}

		clkgen_reg = IoReg_Read32(voAddr);
		#ifdef CONFIG_ALL_SOURCE_DATA_FS
			//mac5p force vo clk for 2k1k datafs
			divider_num = 1;
			ratio_num = 0;
			clkgen_reg = (clkgen_reg &(~0x0f9f0000))|(divider_num<<23)|(ratio_num<<16);
		#endif

			clkgen_reg = clkgen_reg&0xfffffffe;
		IoReg_Write32(voAddr, clkgen_reg); //disable gatting clk
		ori_ratio_num = 0;
	}
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"################ drvif_framesync_gatting (%d, plane %d) => %x\n", enable, Scaler_Get_CurVoInfo_plane(), IoReg_Read32(voAddr));
}



//--------------------------------------------------
// Description  : Adjust Dclk offset to meet frame sync
// Input Value  : None
// Output Value : Return 0 if sucess
//--------------------------------------------------
/**
* drvif_framesync_do
*  This function will djust Dclk offset to meet frame sync
* @param <None>
*@return <unsigned char>  	{Return 0 if sucess}
*/
unsigned char drvif_framesync_do(void)
{

	unsigned short buffer = 0, delta=0;
	unsigned short fine = 0, result = 0;
	unsigned int timeout = 0;
	unsigned char	Data[16] = {0};
	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;
//	ddr_mainstatus_RBUS ddr_mainstatus_reg;
	mdomain_disp_ddr_mainsubctrl_RBUS ddr_mainsubctrl_reg;

	pll27x_reg_sys_dclkss_RBUS dclkss_reg;
//	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	vgip_vgip_chn1_status_RBUS vgip_chn1_status_reg;
	//scaledown_ich1_ibuff_status_RBUS ich1_ibuff_status_reg;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	mdomain_disp_ddr_subctrl_RBUS ddr_subctrl_reg;
//	ddr_substatus_RBUS ddr_substatus_reg;
//	vgip_chn2_status_RBUS vgip_chn2_status_reg;
//	ich2_ibuff_STATUS_RBUS ich2_ibuff_STATUS_reg;
#endif
	unsigned short temp = 0;
	mdomain_cap_ich12_ibuff_status_RBUS mdomain_cap_ich12_ibuff_status_reg;

	fw_scaler_enable_fs_wdg(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);

	if(_CHANNEL1 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
	{
		// Source_Sel[1:0]
		// 00 : use info. from Cap#1.
		// 01 : use info. from Cap#2.
		// 1x : frame sync mode.
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
		ddr_mainctrl_reg.main_source_sel = 3;
		ddr_mainctrl_reg.main_in_format = 1; // 444
		ddr_mainctrl_reg.main_bit_num = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT); // 8bit or 10bit
		IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);

		ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		ddr_mainsubctrl_reg.disp1_double_enable = _ENABLE; // enable double buffer
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, ddr_mainsubctrl_reg.regValue);

		timeout = 0xffff;
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
		while(((1 != ddr_mainctrl_reg.main_in_format) || (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT) != ddr_mainctrl_reg.main_bit_num)) && (timeout))
		{
			ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
			timeout--;
			msleep(10);
		}
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else// if(_CHANNEL2 == info->channel)
	{
		// Source_Sel[1:0]
		// 00 : use info. from Cap#1.
		// 01 : use info. from Cap#2.
		// 1x : frame sync mode.
		ddr_subctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_SubCtrl_reg);
		ddr_subctrl_reg.sub_source_sel = 2;
		ddr_subctrl_reg.sub_in_format = 1; // 444
		ddr_subctrl_reg.sub_bit_num = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT); // 8bit or 10bit
		IoReg_Write32(MDOMAIN_DISP_DDR_SubCtrl_reg, ddr_subctrl_reg.regValue);


		ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		ddr_mainsubctrl_reg.disp2_double_enable = _ENABLE; // enable double buffer
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, ddr_mainsubctrl_reg.regValue);

		timeout = 0xffff;
		ddr_subctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_SubCtrl_reg);
		while(((1 != ddr_subctrl_reg.sub_in_format) || (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT) != ddr_subctrl_reg.sub_bit_num)) && (timeout))
		{
			ddr_subctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_SubCtrl_reg);
			timeout--;
		}
	}
#endif

	if(Scaler_InputSrcGetMainChType()!=_SRC_VO)
		drv_framesync_set_offline_ms_src();

	// Disable spread spectrum
	drv_adjust_spreadspectrumrange(0);

#if 0   //mark scalerlib control by qing_liu
// CSW+ 0961225 Disable Fix last line before open it
	if(_TRUE == Scaler_Get_FramesyncOpenFixLastLine())
	{
		//step 5, Disable F and F-NdF switch
		dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
		dclkss_reg.dclk_new_en = _ENABLE;
		IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, dclkss_reg.regValue);

		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}
#endif
	// // Enable DMA clock sel when disable double dvs frank@04122011 add below for DMACLK
#if 0 // move to dpll_o
	if(!modestate_decide_double_dvs_enable())
	{
		sys_dispclksel_RBUS sys_dispclksel_reg;
		sys_dispclksel_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DISPCLKSEL_reg);
		sys_dispclksel_reg.dispd_video_div= _ENABLE;
		IoReg_Write32(PLL27X_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);
	}
#endif

	{
		// Fast Framesync method
		delta = framesync_fast_get_sync_point();
	       //measure aclkcnt fail
		if(delta == 0xfff)
			return 2;
		drvif_clock_offset(delta);
	}

	drvif_framesync_front_porch_check();

	Scaler_DispSetIvs2DvsDelay(drv_adjust_measureivs2dvsdelay());
	if(Scaler_DispGetIvs2DvsDelay() == 0){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Measure_IVS2DVSDelay FAIL in FrameSync_do\n");
		return 2;
	}

//	framesync_update_ivs_position(Scaler_DispGetIvs2DvsDelay());
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "ret offset =%x fast do\n", delta);

	if(framesync_testsync(delta, &Data[0])) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "FrameSyncTestSync error1:  HS/VS wrong assert(b8052414)");
		return 2;
	}

	if(Data[0] !=0x00){
	//	printk("\n ret=%x after test0 : Frame sync not OK after FrameSyncFastDo!!\n", Data[0]);
	#if 0
		if(Scaler_InputSrcGetMainChFrom()  == _SRC_FROM_TMDS) {
			if (drvif_IsAVMute()) {	// HDMI Avmute
				return 2;
			}
		}
	#endif
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n ret=%x after test0 : Frame sync not OK after FrameSyncFastDo!!\n", Data[0]);
	}else
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n ret=%x after test0 : Frame sync OK after FrameSyncFastDo!!\n", Data[0]);

	if(Data[0] == 0)//frank@0326 framesync OK
	{
		goto _FRAME_SYNC_DO_END; //lewis 20091207, we need apply fix last line function.......
	}

	if(Data[0] == 0) {
		result |= _BIT0;

		if(framesync_testsync(delta + _OFFSET_STEP, &Data[0])) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "FrameSyncTestSync error2:  HS/VS wrong assert(b8052414)");
			return 2;
		}

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n ret=%x after test1 : offset + _OFFSET_STEP!!\n", Data[0]);
		if(Data[0] == 0)   result |= _BIT1;

		if(framesync_testsync(delta - _OFFSET_STEP, &Data[0])){
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "FrameSyncTestSync error3:  HS/VS wrong assert(b8052414)");
			return 2;
		}

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n ret=%x after test2 :  offset  - _OFFSET_STEP!!\n", Data[0]);
		if(Data[0] == 0)   result |= _BIT2;

		if((result & 0x07) != 0x07) {
			if(result == (_BIT0 | _BIT1)) {
				delta += (_OFFSET_STEP / 2);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n FrameSync test3 : FrameSync Success(offset + _OFFSET_STEP)==>offset value=%x\n",delta);
			}
			else if(result == (_BIT0 | _BIT2)) {
				delta -= (_OFFSET_STEP / 2);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n FrameSync test3 : FrameSync Success(offset -_OFFSET_STEP)==>offset value=%x\n",delta);
			}
		}
	}
	drvif_clock_offset(delta);

	buffer = delta;

 	if(result == 0) {   // Fast search fail, do iteration search
 	       rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nFrameSync test4 : Fast Frame sync => do iteration search  !\n");

		// Apply Dclk frequency setting
		//drvif_clock_offset(buffer);

		// Search first satisfied DCLK setting for frame-sync
		result  = 0x00;
		fine    = _SEARCH_TIME;
		do {
			if(framesync_testsync(buffer, &Data[0])){
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "FrameSyncTestSync error4:  HS/VS wrong assert(b8052414)");
				return 2;
			}

			if(Data[0] == 0) break;

			if(Data[0] & 0x02){
				buffer  -= (result & 0x01) ? (_OFFSET_STEP / 2) : _OFFSET_STEP;  // overflow
				//printk( "\n overflow! => offset= %x !!",buffer);
			}
			else{
				buffer  += (result & 0x02) ? (_OFFSET_STEP / 2) : _OFFSET_STEP;  // underflow
				//printk( "\n underflow! => offset= %x !!",buffer);
			}
			result  = Data[0];  // 會儲存上一次是 over or under
		}while(--fine);

		if(fine == 0x00){
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nFrameSync test4 : Iteration search fail! => Frame sync fail !! ");
			return 1;
		}
		else
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nFrameSync test4 : Iteration search success! => search times = %x !!",_SEARCH_TIME - fine);

		// Search most satisfied DCLK setting for frame-sync
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nFrameSync test6 : Search most satisfied DCLK setting for frame-sync ");
		delta = buffer;
		fine  =2; //4;
		do {
			result  = Data[0];
			//unsigned short temp = (result & 0x01) ? delta + (_OFFSET_STEP / 2) : delta - (_OFFSET_STEP / 2);
			temp = (result & 0x01) ? (delta + (unsigned short)_OFFSET_STEP): (delta - (unsigned short)_OFFSET_STEP);

			if(framesync_testsync(temp, &Data[0])){
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nFrameSyncTestSync error6:  HS/VS wrong assert(b8052414)");
				return 2;
			}

			if(Data[0]){
				delta = buffer; // restore the original DClk offset setting
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nrestore the original DClk offset setting");
				break;
			}
			else // CSW+ 0970214 Save safe frame sync offset value
				buffer = temp;
			delta   = temp;
		}while(--fine);


	}
	_FRAME_SYNC_DO_END:
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nFrameSync test7 : FrameSync SpreadSpectrum Finetune ");
	result = framesync_spreadspectrumfinetune(&delta);
	if(result != 0)     return result;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\nFrameSync test8 : FrameSync LastLine Finetune ");
#if 0  //mark scalerlib control by qing_liu
	if(Scaler_Get_FramesyncOpenFixLastLine()){
		if(!framesync_synclastlinefinetune(&delta))
 			return 2;
	}
#endif
	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	dclkss_reg.dclk_ss_load = _ENABLE;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, dclkss_reg.regValue);
	//clear status
	if(_CHANNEL1 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) )
	{
		vgip_chn1_status_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_STATUS_reg);
		vgip_chn1_status_reg.ch1_vs_err = TRUE;
		vgip_chn1_status_reg.ch1_hs_err = TRUE;
		vgip_chn1_status_reg.ch1_field_err = TRUE;
		vgip_chn1_status_reg.ch1_vact_start = 0;
		vgip_chn1_status_reg.ch1_vact_end = 0;
		IoReg_Write32(VGIP_VGIP_CHN1_STATUS_reg, vgip_chn1_status_reg.regValue);

		//Write Clear
		mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);
		mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf = TRUE;
		mdomain_cap_ich12_ibuff_status_reg.fsync_ovf = TRUE;
		mdomain_cap_ich12_ibuff_status_reg.fsync_udf = TRUE;
		IoReg_Write32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg, mdomain_cap_ich12_ibuff_status_reg.regValue);
	}

	return 0;
}


unsigned char drvif_decide_frc_fixlastline_enable(void)
{
	if ((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) || (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY))
		return FALSE;

	//if (modestate_decide_double_dvs_enable())
	//	return FALSE;

	if ( (Scaler_InputSrcGetMainChType() == _SRC_VGA) /*||
		((GET_INPUTSOURCE_FROM() == _SRC_FROM_TMDS) &&(!drvif_Hdmi_FormatDetect())) */
		)
		return FALSE;

	return TRUE;
}

#ifdef CONFIG_FS_HS_BIAS
//--------------------------------------------------
// Description  : When HS Bias, IC will tracking automatically for frame sync
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/**
* drvif_framesync_hs_bias
* limitation: Timing: FS, Data:FS
* This function will enable IC tracking mechanism when HS Bias for FrameSync
* @param <None>
* @return <None>
*/
#define GENERAL_LINE_NUM	8
unsigned char drvif_framesync_hs_bias(void)
{
	float decimal_array[8] = {0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0 , 0};
	float expect_value = 0;
	unsigned char array_index = 0, integer_part = 0, decimal_part = 0, M_code = 0, N_code = 0, K_code = 0, vco_div = 0, result;
	unsigned int ICLK = 0,general_standard_num = 0;
	pll_setM_N_Register_RBUS pll_setM_N_reg;
	pllphase_ctrl_RBUS pllphase_ctrl_reg;
	fsync_general_ctrl1_RBUS fsync_general_ctrl1_reg;
	fsync_general_ctrl2_RBUS fsync_general_ctrl2_reg;
	dpll_in_fsync_tracking_ctrl_RBUS dpll_in_fsync_tracking_ctrl_reg;
	sys_dclkss_RBUS dclkss_reg;
	//scaledown_ich1_ibuff_status_RBUS ich1_ibuff_status_reg;
	mdomain_cap_ich12_ibuff_status_RBUS mdomain_cap_ich12_ibuff_status_reg;

	//only YPbPr / CVBS framesync mode and Go VGIP channel1 can support this function
	if(SLR_MAIN_DISPLAY != Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))
		return TRUE;

	if(!Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
		return;

	if((Scaler_InputSrcGetMainChType() != _SRC_YPBPR) && (Scaler_InputSrcGetMainChType() != _SRC_CVBS))
		return;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Enter HS Bias\n");
	// 1.calculate  general standard num
	if(Scaler_InputSrcGetMainChType() == _SRC_YPBPR){
		pll_setM_N_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SETM_N);
		M_code = pll_setM_N_reg.pll_m;
		N_code = pll_setM_N_reg.pll_n;
		K_code = pll_setM_N_reg.pllsphnext;

		pllphase_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLLPHASE_CTRL_VADDR);
		if(pllphase_ctrl_reg.pll2d2)
		vco_div = 4;
		else
		vco_div = 2;

		// [Code Sync][LewisLee][0990211][1]
				// for K code rule
				// K > 7 ==> M+1
				// K < -8 ==> M-1
				//so we need return K to original value
		if(K_code > 7)
			M_code -= 1;
		// [Code Sync][LewisLee][0990211][1][End]


		ICLK = (27000000*(M_code+3) + 27000000*K_code/16)/((N_code+2)*vco_div);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"==>M:%d N:%d K:%d vco:%d ICLK:%d\n",M_code,N_code,K_code,vco_div,ICLK);
	}
	else{//vdc
		ICLK = 13500000;
	}

	ICLK /= 1000;
	general_standard_num = (GENERAL_LINE_NUM*Scaler_DispGetInputInfo(SLR_INPUT_H_LEN))*27000/ICLK;

	fsync_general_ctrl1_reg.regValue = IoReg_Read32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR);
	fsync_general_ctrl1_reg.fsync_general_standard_num = general_standard_num;
	fsync_general_ctrl1_reg.fsync_general_line_num = GENERAL_LINE_NUM - 1;
	IoReg_Write32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR, fsync_general_ctrl1_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[==>reg:%x]\n",IoReg_Read32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"==>IHtotal:%d\n",Scaler_DispGetInputInfo(SLR_INPUT_H_LEN));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"==> general_standard_num :0x%x\n",general_standard_num);

	// 2.calculate delta ratio
	expect_value = 409600/(general_standard_num*12.5);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"==> ratio:%f\n",expect_value);
	//integer part
	integer_part = (unsigned char)expect_value;
	//decimal part
	expect_value -=  (float)integer_part;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"==> int:%d decimal:%f\n",integer_part,expect_value);
	for(array_index = 0; array_index<6; array_index++){
		if (	(ABS(expect_value, decimal_array[array_index])) <=
			(ABS(expect_value, (decimal_array[array_index+1] + decimal_array[array_index+2])))){
			decimal_part |= 1<<(5 - array_index);
			if(decimal_array[array_index] > expect_value)
				break;
			else
				expect_value -= decimal_array[array_index];
		}
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"==> integer_part0:0x%x decimal:0x%x\n", integer_part, decimal_part);

	fsync_general_ctrl2_reg.regValue = IoReg_Read32(PEAKING_FSYNC_GENERAL_CTRL2_VADDR);
	fsync_general_ctrl2_reg.fsync_general_delta_ratio = (integer_part<<6)|(decimal_part);
	IoReg_Write32(PEAKING_FSYNC_GENERAL_CTRL2_VADDR, fsync_general_ctrl2_reg.regValue);

	// 3.enable function
	fsync_general_ctrl1_reg.regValue = IoReg_Read32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR);
	fsync_general_ctrl1_reg.fsync_general_en = _ENABLE;
	IoReg_Write32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR, fsync_general_ctrl1_reg.regValue);

	dpll_in_fsync_tracking_ctrl_reg.regValue = IoReg_Read32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_VADDR);
	dpll_in_fsync_tracking_ctrl_reg.in_frame_tracking_general_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_VADDR, dpll_in_fsync_tracking_ctrl_reg.regValue);

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_ss_load = 1;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_ss_en = 1;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"==>value:%x reg:%x\n",  (integer_part<<7)|(decimal_part),IoReg_Read32(PEAKING_FSYNC_GENERAL_CTRL2_VADDR));

	msleep(40);
	mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);
	mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf = 1;
	mdomain_cap_ich12_ibuff_status_reg.fsync_ovf = 1;
	mdomain_cap_ich12_ibuff_status_reg.fsync_udf = 1;
	IoReg_Write32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg, mdomain_cap_ich12_ibuff_status_reg.regValue);
	msleep(40);

	mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);

	mdomain_cap_ich12_ibuff_status_reg.regValue = IoReg_Read32(MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg);

	if((TRUE == mdomain_cap_ich12_ibuff_status_reg.ibuff_ovf) || (TRUE == mdomain_cap_ich12_ibuff_status_reg.fsync_ovf))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"drvif_framesync_hs_bias : overflow\n");
		return FALSE;
	}
	else if(TRUE == mdomain_cap_ich12_ibuff_status_reg.fsync_udf)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"drvif_framesync_hs_bias : underflow\n");
		return FALSE;
	}

	return TRUE;
}

void drvif_framesync_hs_bias_release(void)
{
	fsync_general_ctrl1_RBUS fsync_general_ctrl1_reg;
	dpll_in_fsync_tracking_ctrl_RBUS dpll_in_fsync_tracking_ctrl_reg;
	sys_dclkss_RBUS dclkss_reg;


	fsync_general_ctrl1_reg.regValue = IoReg_Read32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR);
	fsync_general_ctrl1_reg.fsync_general_en = _DISABLE;
	IoReg_Write32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR, fsync_general_ctrl1_reg.regValue);

	dpll_in_fsync_tracking_ctrl_reg.regValue = IoReg_Read32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_VADDR);
	dpll_in_fsync_tracking_ctrl_reg.in_frame_tracking_general_en = _DISABLE;
	IoReg_Write32(PLL27X_REG_DPLL_IN_FSYNC_TRACKING_CTRL_VADDR, dpll_in_fsync_tracking_ctrl_reg.regValue);

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	dclkss_reg.dclk_ss_load = 1;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, dclkss_reg.regValue);
}


// [Code Sync][lewislee][0990224][1]
//lewis 20100224, it is short time solution, to prevent Dclk jitter, let panel abnormal
void drvif_framesync_hs_bias_check(void)
{
	fsync_general_ctrl1_RBUS fsync_general_ctrl1_reg;
	SP_MS1Stus_RBUS SP_MS1Stus_reg;
//	SP_MS2Stus_RBUS SP_MS2Stus_reg;

//	if(_MAIN_DISPLAY != info->display)
//		return;

	fsync_general_ctrl1_reg.regValue = IoReg_Read32(PEAKING_FSYNC_GENERAL_CTRL1_VADDR);

	if(_ENABLE == fsync_general_ctrl1_reg.fsync_general_en)
	{
		{
			SP_MS1Stus_reg.regValue = IoReg_Read32(SYNCPROCESSOR_SP_MS1STUS_VADDR);

			if(SP_MS1Stus_reg.on1_vs_per_to || SP_MS1Stus_reg.on1_vs_over_range)
				drvif_framesync_hs_bias_release();
		}

	}
}
// [Code Sync][lewislee][0990224][1][End]

#endif


unsigned int hardware_measure_dvtotal(void)
{

	//unsigned int DVTotal;
	//unsigned short measure_timeout;

	ppoverlay_measure_dvtotal_last_line_pixels_result1_RBUS measure_dvtotal_last_line_pixels_result1_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;

	/*WaitFor_DEN_STOP();*/ /*avoid blinking line*/
	fw_scaler_dtg_double_buffer_enable(1);
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl1_reg.disp_fsync_en = 1;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	fw_scaler_dtg_double_buffer_apply();
	//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);

	measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
	measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr = _DISABLE;
	measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_mode = 0;
	measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_2f = 0;
	IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);

	msleep(50);

	measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
	measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr = _ENABLE;
	IoReg_Write32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg, measure_dvtotal_last_line_pixels_result1_reg.regValue);

	//////////////////////////////////////
	//By Gilbert(2009/5/13)
	//避免發生讀取DVTotal錯誤以此設定錯誤.以產生最後畫面被切割
	//WaitFor_DEN_STOP();
	////////////////////////////////////
	msleep(200);

	if(_CHANNEL1 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
	{
		WaitFor_IVS1_Done();
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);

	}
	#ifdef CONFIG_DUAL_CHANNEL
	else// if(_CHANNEL2 == info->channel)
	{
		WaitFor_IVS2_Done();
		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);

#ifdef CONFIG_WATCHDOG_ENABLE
			IoReg_Write32(TC_WR_TR_VADDR, _BIT0);//tick system WD, to avoid system reset
			IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif //#ifdef CONFIG_WATCHDOG_ENABLE
//		}
	}
	#endif


	return measure_dvtotal_last_line_pixels_result1_reg.dv_total_value_first;

}

#ifdef CONFIG_5_4_FS

//--------------------------------------------------
// Description  : For DVD data 24frame/sec, DVD player will convert 24frame/sec -> 60 frame/sec. (This operation will cause lag)
//			 For Timing: FS, Data:FRC, IC will re-arrange VS => generate VS: 48frame/sec
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/**
* drvif_framesync_5_4
* limitation: Timing: FS, Data:FRC
* This function will solve lag for DVD data is 24frame/sec
* @param <None>
* @return <None>
*/
void drvif_framesync_5_4(void)
{
	unsigned char  div=1;
	unsigned short nMCode,nNCode,usDclkOffset;
	unsigned int temp_val = 0,DHTotal;
	sys_pll_disp1_RBUS reg_disp1;
	sys_pll_disp2_RBUS reg_disp2;
	fs54_ctrl_RBUS ppoverlay_fs54_ctrl_Reg;


	if((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == TRUE)||((IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg)& _BIT26)==0))
		return;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"====  drvif_framesync_5_4 ====\n");
	IoReg_SetBits(PPOVERLAY_Display_Timing_CTRL1_reg, _BIT29);
	temp_val = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	DHTotal = ((temp_val >>16) & 0xffffff)+1;
	IoReg_Mask32(PPOVERLAY_FS54_DH_VADDR, ~0xfff0000, DHTotal<<16);

	//get DCLK setting
	reg_disp1.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	reg_disp2.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_VADDR);
	nMCode = reg_disp1.dpll_m;
	nNCode = reg_disp1.dpll_n;
	div = reg_disp2.dpll_o;

	switch(div){
		default:
		case 0:
			div = 1;
			break;
		case 1:
			div = 2;
			break;
		case 2:
			div = 4;
			break;
		case 3:
			div = 8;
			break;
	}

	temp_val = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	usDclkOffset = (temp_val>>16) & 0xfff;

	//Dclk = 27M *(M+2)/(div*(N+2)*2)*(1- offset/2^15)
    	temp_val = ((CONFIG_CPU_XTAL_FREQ/128 * (nMCode+2)) / (div * (nNCode+2)*2))*128;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk:%d\n",temp_val);
	temp_val = temp_val - (temp_val>>15)*usDclkOffset;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"M:%d N:%d div:%d offset:%d DCLK:%d\n", nMCode, nNCode, div, usDclkOffset, temp_val);

	//DVTotal = Dclk/(DHTotal*48)
	//if(temp_val % (DHTotal*48))
		temp_val = temp_val/(DHTotal*48) + 1;
	//else
	//	temp_val = temp_val/(DHTotal*48);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"DHTotal:%d DVTotal:%d\n", DHTotal, temp_val);
	IoReg_Mask32(PPOVERLAY_FS54_DV_VADDR, ~0xfff, temp_val);
	IoReg_Mask32(PPOVERLAY_FS54_DCLK_M_VADDR, ~0x3ff, nMCode);
	IoReg_Mask32(PPOVERLAY_FS54_DCLK_N_VADDR, ~0xff, nNCode);
#if 0
	IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR, 0x60001110);//enable double buffer => load in setting
	IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR, 0xE0001110);//enable 54FS function
#else
	ppoverlay_fs54_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_FS54_CTRL_VADDR);
	ppoverlay_fs54_ctrl_Reg.fs54_dclk_en = 0;
	ppoverlay_fs54_ctrl_Reg.fs54_dclk_slow_modify_en = 0;
	ppoverlay_fs54_ctrl_Reg.fs54_pseudo_fsync_en = 0;
	ppoverlay_fs54_ctrl_Reg.fs54_timing_en = 1;
	ppoverlay_fs54_ctrl_Reg.fs54_vs_align = 1;
	ppoverlay_fs54_ctrl_Reg.fs54_force = 1;
	ppoverlay_fs54_ctrl_Reg.fs54_main_sub_sel = 0;
	ppoverlay_fs54_ctrl_Reg.fs54_frc_fastslow = 1;
	ppoverlay_fs54_ctrl_Reg.fs54_db_load = 1;
	IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR,ppoverlay_fs54_ctrl_Reg.regValue);

	ppoverlay_fs54_ctrl_Reg.fs54_en = 1;
	IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR,ppoverlay_fs54_ctrl_Reg.regValue);
#endif
}

void drvif_framesync_5_4_release(void)
{
	fs54_ctrl_RBUS ppoverlay_fs54_ctrl_Reg;
	ppoverlay_fs54_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_FS54_CTRL_VADDR);
	ppoverlay_fs54_ctrl_Reg.fs54_en = 0;
	IoReg_Write32(PPOVERLAY_FS54_CTRL_VADDR,ppoverlay_fs54_ctrl_Reg.regValue);
}
#endif

//USER : LewusLee DATE:2012/08/30
//for novatek Tcon IC, too easy to enter burn in mode
//sw we need to set FRC -> Framesync moer smooth

//#define FS_ADJUST_DVTOTAL_printk(format, args...) 	printk(format, ##args)
#define FS_ADJUST_DVTOTAL_printk(format, args...)

#define _FS_ADJUST_DVTOTAL_INPUT_VSYNC_LOST_THRESHOLD		3
#define _FS_ADJUST_DVTOTAL_DV_TOTAL_FRONT_PORCH_OFFSET	3//Lewis Modify 10
#define _FS_ADJUST_DVTOTAL_FRC_LAST_LINE_PIXEL_OFFSET		4
#define _FS_ADJUST_DVTOTAL_FRC_RE_MEASURE_TIMES			3

unsigned char framesync_adjust_dvtotal_at_framesync_mode(SCALER_DISP_CHANNEL display)
{
	return _FALSE;
#if 0
	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	UINT8 ucWatchDogFlag = _FALSE;
	UINT8 ucfrc_on_fsync_flag = _DISABLE;
	UINT16 measure_timeout = 0;
	UINT8 InputSyncLoseCount = 0;
	UINT16 DVTotal, DVTotal1, DHTotal, DHTotal1;
	fs_iv_dv_fine_tuning1_RBUS fs_iv_dv_fine_tuning1_reg;
	measure_dvtotal_last_line_pixels_result1_RBUS measure_dvtotal_last_line_pixels_result1_reg;
	measure_dvtotal_last_line_pixels_result2_RBUS measure_dvtotal_last_line_pixels_result2_reg;
	UINT8 ucReMeasureTimes = 0;
	dv_total_RBUS dv_total_reg;
//	sys_dclkss_RBUS sys_dclkss_reg;
//	dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	sys_pll_disp3_RBUS sys_pll_disp3_reg;
	UINT8 ucDPLL_Phase_Swallow_Circuit_flag = DPLL_PHASE_SWALLOW_CIRCUIT_PATH0;

	if(SLR_SUB_DISPLAY == display)
		return _FALSE;

#ifdef CONFIG_ENABLE_FRAMESYNC_MODE_DYNAMIC_ADJUST_DHTOTAL
	framesync_mode_dymanic_adjust_dhtotal(FRAMESYNC_DYMANIC_ADJUST_DHTOTAL_NONE);
#endif //#ifdef CONFIG_ENABLE_FRAMESYNC_MODE_DYNAMIC_ADJUST_DHTOTAL

//mark scalerlib control by qing_liu
//	if(_DISABLE == Scaler_Get_FS_Mode_Adjust_DVtotal_Flow_Enable())

#if 0   //mark scalerlib control by qing_liu
	if(_TRUE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC))
	{
		if(_ENABLE == Scaler_Enter_FramesyncOpenFixLastLine_Condition())
			return _TRUE;
	}
	else// if(_FALSE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC))
	{
		if(_ENABLE == Scaler_EnterFRC_LastLine_Condition())
			return _FALSE;
#endif
		if(_ENABLE == modestate_decide_double_dvs_enable())
			return _FALSE;
//	}

	if(_TRUE == Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
	{
		fs_iv_dv_fine_tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		fs_iv_dv_fine_tuning1_reg.iv2dv_toggle_en = _ENABLE;
		fs_iv_dv_fine_tuning1_reg.iv2dv_toggle_inv = 1;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, fs_iv_dv_fine_tuning1_reg.regValue);
	}
	else// if(_FALSE == Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
	{
		fs_iv_dv_fine_tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		fs_iv_dv_fine_tuning1_reg.iv2dv_toggle_en = _DISABLE;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, fs_iv_dv_fine_tuning1_reg.regValue);
	}

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	//only suppport famesync mode
	if(_DISABLE == display_timing_ctrl1_reg.disp_fsync_en)
		return _FALSE;

	//not support fix last line mode
	if(_ENABLE == display_timing_ctrl1_reg.disp_fix_last_line)
		return _FALSE;

	//it need framesync lock
	if(_DISABLE == display_timing_ctrl1_reg.disp_frc_fsync)
		return _FALSE;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Enter framesync_adjust_dvtotal_at_framesync_mode !\n");

	if(_TRUE == display_timing_ctrl1_reg.wde_to_free_run)
	{
		fw_scaler_enable_fs_wdg(display, FALSE);
		ucWatchDogFlag = _TRUE;
	}

	if(_ENABLE == display_timing_ctrl1_reg.disp_frc_on_fsync)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _DISABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

		ucfrc_on_fsync_flag = _TRUE;
	}

	//USER:LewisLee DATE:2012/12/13
	//fix measure total pixel measure result error
	sys_pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);

	if(DPLL_PHASE_SWALLOW_CIRCUIT_PATH1 == sys_pll_disp3_reg.dpll_reserve)
	{
		sys_pll_disp3_reg.dpll_reserve = DPLL_PHASE_SWALLOW_CIRCUIT_PATH0;
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP2_reg, sys_pll_disp3_reg.regValue);

		ucDPLL_Phase_Swallow_Circuit_flag = DPLL_PHASE_SWALLOW_CIRCUIT_PATH1;
	}

	framesync_adjust_dvtotal_at_framesync_mode_Enable_Re_MEASURE:

	//disable measure
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);

	msleep(10);

	//enable measure
	drvif_measure_dvtotal_last_line_pixels(_ENABLE);

	// 1. Get the measure result for last line
	measure_timeout = 0xfff;
	measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);

	while((_ENABLE == measure_dvtotal_last_line_pixels_result1_reg.measure_dvllpixels_ctr) && measure_timeout)
	{
		if (_FALSE == WaitFor_IVS1_Done())
			InputSyncLoseCount++;

		if(InputSyncLoseCount >= _FS_ADJUST_DVTOTAL_INPUT_VSYNC_LOST_THRESHOLD)
			goto framesync_adjust_dvtotal_at_framesync_mode_Enable_Lose_Sync;

		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		measure_timeout--;
	}

	if(0 == measure_timeout)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Framesync Last Line Measure timeout\n");
		goto framesync_adjust_dvtotal_at_framesync_mode_Enable_Lose_Sync;
	}
	else
	{
		FS_ADJUST_DVTOTAL_printk("Framesync measure_timeout : %x, InputSyncLoseCount : %x\n", measure_timeout, InputSyncLoseCount);

		measure_dvtotal_last_line_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result1_reg);
		DVTotal = measure_dvtotal_last_line_pixels_result1_reg.dv_total_value_first;
		DHTotal = measure_dvtotal_last_line_pixels_result1_reg.last_line_value_first;
		FS_ADJUST_DVTOTAL_printk( "\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

		measure_dvtotal_last_line_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_dvtotal_last_line_pixels_Result2_reg);
		DVTotal1 = measure_dvtotal_last_line_pixels_result2_reg.dv_total_value_second;
		DHTotal1 = measure_dvtotal_last_line_pixels_result2_reg.last_line_value_second;
		FS_ADJUST_DVTOTAL_printk( "\nMeasure second time DV total = %x, last line = %x\n",DVTotal1, DHTotal1);

		//USER:LewisLee DATE:2012/06/18
		//some times, measure two frame line is different
		//it maybe is error result
		if(DVTotal != DVTotal1)
		{
			if(ucReMeasureTimes < _FS_ADJUST_DVTOTAL_FRC_RE_MEASURE_TIMES)
			{
				ucReMeasureTimes++;
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Framesync ReMeasure, DVTotal : %x, DVTotal1 : %x, ucReMeasureTimes : %x\n", DVTotal, DVTotal1, ucReMeasureTimes);
				goto framesync_adjust_dvtotal_at_framesync_mode_Enable_Re_MEASURE;
			}
		}
	}

	FS_ADJUST_DVTOTAL_printk("Measure Final line = %x, Pixel : %x\n", DVTotal, DHTotal);
#if 0  //mark scalerlib control by qing_liu
	if(_ENABLE == Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Enable_Flag())
	{
#ifdef CONFIG_ENABLE_FRAMESYNC_MODE_DYNAMIC_ADJUST_DHTOTAL
		//USER:LewisLee DATE:2012/10/22
		//fix FLL mode, DV total over range, let Vfreq change
		if(DVTotal > Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper())
		{
			DVTotal = Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper();

			//DV total too large, Set Dh total bigger
			if(_ENABLE == Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_Enable_Flag())
			{
				//only execute once
				if(0 == Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_CurrentValue())
				{
					ucReMeasureTimes = 0;
					framesync_mode_dymanic_adjust_dhtotal(FRAMESYNC_DYMANIC_ADJUST_DHTOTAL_TO_MAX);
					goto framesync_adjust_dvtotal_at_framesync_mode_Enable_Re_MEASURE;
				}
			}
		}
		else if(DVTotal < Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower())
		{
			DVTotal = Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower();

			//DV total too small, Set Dh total smaller
			if(_ENABLE == Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_Enable_Flag())
			{
				//only execute once
				if(0 == Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_CurrentValue())
				{
					ucReMeasureTimes = 0;
					framesync_mode_dymanic_adjust_dhtotal(FRAMESYNC_DYMANIC_ADJUST_DHTOTAL_TO_MIN);
					goto framesync_adjust_dvtotal_at_framesync_mode_Enable_Re_MEASURE;
				}
			}
		}
#else //#ifdef CONFIG_ENABLE_FRAMESYNC_MODE_DYNAMIC_ADJUST_DHTOTAL
		if(DVTotal > Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper())
			DVTotal = Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper();
		else if(DVTotal < Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower())
			DVTotal = Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower();
#endif //#ifdef CONFIG_ENABLE_FRAMESYNC_MODE_DYNAMIC_ADJUST_DHTOTAL

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Limit_Upper()=%x", Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper());
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Limit_Lower()=%x", Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower());
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n DVTotal=%x ",DVTotal);
	}
#endif
	if(DVTotal < framesync_get_dvtotal_min())
	{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		DVTotal = (UINT16)framesync_dynamic_adjust_dvtotal_den_relation((UINT32)DVTotal);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		DVTotal = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

		if(DVTotal > Get_DISP_VERTICAL_TOTAL())
			DVTotal = (Get_DISP_VERTICAL_TOTAL() - 1);

		FS_ADJUST_DVTOTAL_printk(" DV total over spec !\n");
	}

	// 2. Set the DV total
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = DVTotal;
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
/*
	// 3. set N as zero
	sys_dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
	sys_dclkss_reg.dclk_freq_syn_slt = 0x00;
	sys_dclkss_reg.dclk_ss_load = 1;
	sys_dclkss_reg.dclk_ss_en = 1;
	IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, sys_dclkss_reg.regValue);
*/
	//disable measure
	drvif_measure_dvtotal_last_line_pixels(_DISABLE);

	if(_TRUE == ucWatchDogFlag)
		fw_scaler_enable_fs_wdg(display, TRUE);

	if(_ENABLE == ucfrc_on_fsync_flag)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _ENABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}

	//USER:LewisLee DATE:2012/12/13
	//fix measure total pixel measure result error
	if(DPLL_PHASE_SWALLOW_CIRCUIT_PATH1 == ucDPLL_Phase_Swallow_Circuit_flag)
	{
		sys_pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
		sys_pll_disp3_reg.dpll_reserve = DPLL_PHASE_SWALLOW_CIRCUIT_PATH1;
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, sys_pll_disp3_reg.regValue);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n framesync_adjust_dvtotal_at_framesync_mode success\n");

	return _TRUE;

	framesync_adjust_dvtotal_at_framesync_mode_Enable_Lose_Sync:

	if(_ENABLE == ucfrc_on_fsync_flag)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _ENABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}

	//USER:LewisLee DATE:2012/12/13
	//fix measure total pixel measure result error
	if(DPLL_PHASE_SWALLOW_CIRCUIT_PATH1 == ucDPLL_Phase_Swallow_Circuit_flag)
	{
		sys_pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
		sys_pll_disp3_reg.dpll_reserve = DPLL_PHASE_SWALLOW_CIRCUIT_PATH1;
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, sys_pll_disp3_reg.regValue);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n framesync_adjust_dvtotal_at_framesync_mode fail\n");
	return _FALSE;
#endif
}

#define BEFORE_DISPLAY_FS_MODE_LAST_LINE_PIXEL_OFFSET	20

//USER:LewisLee DATE:2012/12/05
//for novatek Tcon IC, too easy have white noise
unsigned char framesync_adjust_dvtotal_before_display_at_framesync_mode(SCALER_DISP_CHANNEL display)
{
	return _FALSE;
#if 0
	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	UINT8 ucWatchDogFlag = _FALSE;
	UINT8 ucfrc_on_fsync_flag = _DISABLE;
	UINT16 measure_timeout = 0;
	UINT8 InputSyncLoseCount = 0;
	UINT16 DVTotal, DVTotal1, DHTotal, DHTotal1;
	fs_iv_dv_fine_tuning1_RBUS fs_iv_dv_fine_tuning1_reg;
	measure_total_pixels_result1_RBUS measure_total_pixels_result1_reg;
	measure_total_pixels_result2_RBUS measure_total_pixels_result2_reg;
	UINT8 ucReMeasureTimes = 0;
	dv_total_RBUS dv_total_reg;
//	sys_dclkss_RBUS sys_dclkss_reg;
	dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	UINT32 Cur_DH_Total_Value = 0;
	sys_pll_disp3_RBUS sys_pll_disp3_reg;
	UINT8 ucDPLL_Phase_Swallow_Circuit_flag = DPLL_PHASE_SWALLOW_CIRCUIT_PATH0;

	if(SLR_SUB_DISPLAY == display)
		return _FALSE;

//mark scalerlib control by qing_liu
//	if(_DISABLE == Scaler_Get_FS_Mode_BeforeDisplay_Adjust_DVtotal_Flow_Enable())


	if(_TRUE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC))
	{
	//	if(_ENABLE == Scaler_Enter_FramesyncOpenFixLastLine_Condition())
	//		return _TRUE;
	}
	else// if(_FALSE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC))
	{
	//	if(_ENABLE == Scaler_EnterFRC_LastLine_Condition())
	//		return _FALSE;

		if(_ENABLE == modestate_decide_double_dvs_enable())
			return _FALSE;
	}

	if(_TRUE == Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
	{
		fs_iv_dv_fine_tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		fs_iv_dv_fine_tuning1_reg.iv2dv_toggle_en = _ENABLE;
		fs_iv_dv_fine_tuning1_reg.iv2dv_toggle_inv = 1;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, fs_iv_dv_fine_tuning1_reg.regValue);
	}
	else// if(_FALSE == Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
	{
		fs_iv_dv_fine_tuning1_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
		fs_iv_dv_fine_tuning1_reg.iv2dv_toggle_en = _DISABLE;
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, fs_iv_dv_fine_tuning1_reg.regValue);
	}

	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	//not support fix last line mode
	if(_ENABLE == display_timing_ctrl1_reg.disp_fix_last_line)
		return _FALSE;

	//to make sure Dclk is stable
	drv_adjust_spreadspectrumrange(0);

	Cur_DH_Total_Value = Get_DISP_HORIZONTAL_TOTAL();

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Enter framesync_adjust_dvtotal_before_display_at_framesync_mode !\n");

	if(_TRUE == display_timing_ctrl1_reg.wde_to_free_run)
	{
		fw_scaler_enable_fs_wdg(display, FALSE);
		ucWatchDogFlag = _TRUE;
	}

	if(_ENABLE == display_timing_ctrl1_reg.disp_frc_on_fsync)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _DISABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

		ucfrc_on_fsync_flag = _TRUE;
	}

	//USER:LewisLee DATE:2012/12/13
	//fix measure total pixel measure result error
	sys_pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);

	if(DPLL_PHASE_SWALLOW_CIRCUIT_PATH1 == sys_pll_disp3_reg.dpll_reserve)
	{
		sys_pll_disp3_reg.dpll_reserve = DPLL_PHASE_SWALLOW_CIRCUIT_PATH0;
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, sys_pll_disp3_reg.regValue);

		ucDPLL_Phase_Swallow_Circuit_flag = DPLL_PHASE_SWALLOW_CIRCUIT_PATH1;
	}

	framesync_adjust_dvtotal_before_display_at_framesync_mode_Enable_Re_MEASURE:

	//disable measure
	drvif_measure_total_pixels(_DISABLE);

	msleep(10);

	//enable measure
	drvif_measure_total_pixels(_ENABLE);

	// 1. Get the measure result for last line
	measure_timeout = 0xfff;
	measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);

	while((_ENABLE == measure_total_pixels_result1_reg.measure_topixels_ctr) && measure_timeout)
	{
#if 1
		if (_FALSE == WaitFor_IVS1_Done())
			InputSyncLoseCount++;
#else //#if 0
		msleep(40);
		InputSyncLoseCount++;
#endif //#if 0

		if(InputSyncLoseCount >= _FS_ADJUST_DVTOTAL_INPUT_VSYNC_LOST_THRESHOLD)
			goto framesync_adjust_dvtotal_before_display_at_framesync_mode_Enable_Lose_Sync;

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		measure_timeout--;
	}

	if(0 == measure_timeout)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Framesync Last Line Measure timeout\n");
		goto framesync_adjust_dvtotal_before_display_at_framesync_mode_Enable_Lose_Sync;
	}
	else
	{
		FS_ADJUST_DVTOTAL_printk("Framesync measure_timeout : %x, InputSyncLoseCount : %x\n", measure_timeout, InputSyncLoseCount);

		measure_total_pixels_result1_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result1_reg);
		DVTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt / Cur_DH_Total_Value;
		DHTotal = measure_total_pixels_result1_reg.total_pixels_first_cnt % Cur_DH_Total_Value;
		FS_ADJUST_DVTOTAL_printk( "\nMeasure first time DV total = %x, last line = %x\n",DVTotal, DHTotal);

		measure_total_pixels_result2_reg.regValue = IoReg_Read32(PPOVERLAY_Measure_total_pixels_Result2_reg);
		DVTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt / Cur_DH_Total_Value;
		DHTotal1 = measure_total_pixels_result2_reg.total_pixels_second_cnt % Cur_DH_Total_Value;
		FS_ADJUST_DVTOTAL_printk( "\nMeasure second time DV total = %x, last line = %x\n",DVTotal1, DHTotal1);

		//USER:LewisLee DATE:2012/06/18
		//some times, measure two frame line is different
		//it maybe is error result
		if(DVTotal != DVTotal1)
		{
			if(ucReMeasureTimes < _FS_ADJUST_DVTOTAL_FRC_RE_MEASURE_TIMES)
			{
				ucReMeasureTimes++;
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Framesync ReMeasure, DVTotal : %x, DVTotal1 : %x, ucReMeasureTimes : %x\n", DVTotal, DVTotal1, ucReMeasureTimes);
				goto framesync_adjust_dvtotal_before_display_at_framesync_mode_Enable_Re_MEASURE;
			}
		}

		DHTotal += DHTotal1;
		DHTotal = DHTotal>>1;
	}

	FS_ADJUST_DVTOTAL_printk("Measure Final line = %x, Pixel : %x\n", DVTotal, DHTotal);
#if 0  //mark scalerlib control by qing_liu
	if(_ENABLE == Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Enable_Flag())
	{
		if(DVTotal > Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper())
			DVTotal = Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper();
		else if(DVTotal < Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower())
			DVTotal = Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower();

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Limit_Upper()=%x", Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Upper());
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Limit_Lower()=%x", Scaler_Get_FS_Mode_Adjust_DVTotoal_Limit_Lower());
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n DVTotal=%x ",DVTotal);
	}
#endif
	if(DVTotal < framesync_get_dvtotal_min())
	{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		DVTotal = (UINT16)framesync_dynamic_adjust_dvtotal_den_relation((UINT32)DVTotal);
#else //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		DVTotal = framesync_get_dvtotal_min();
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS

		if(DVTotal > Get_DISP_VERTICAL_TOTAL())
			DVTotal = (Get_DISP_VERTICAL_TOTAL() - 1);

		FS_ADJUST_DVTOTAL_printk(" DV total over spec !\n");
	}

	// 2. Set the DV total
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total_reg.dv_total = DVTotal;
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

	// 2. Set the Last Line Pixel
	if(DHTotal > BEFORE_DISPLAY_FS_MODE_LAST_LINE_PIXEL_OFFSET)
		DHTotal -= BEFORE_DISPLAY_FS_MODE_LAST_LINE_PIXEL_OFFSET;
	else
		DHTotal = 1;//avoid 0-1 equal to -1

	//to prevent Dh total over range
	if(DHTotal > Get_DISP_HORIZONTAL_TOTAL())
	{
		DHTotal -= Get_DISP_HORIZONTAL_TOTAL();

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"LastLine Pixel > DH_Total\n");

		//Increase 1 line
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dv_total_reg.dv_total += 1;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
	}

	//USER:LewisLee DATE:2010/07/16
	//for Edward request, let last line pixel is even at picasso platform
	if(DHTotal & _BIT0)
		DHTotal += 1;

	// Setting value = ( real value -1) , Min. value 90
	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1);
	dh_total_last_line_length_reg.dh_total_last_line = DHTotal - 1;
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
/*
	// 3. set N as zero
	sys_dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
	sys_dclkss_reg.dclk_freq_syn_slt = 0x00;
	sys_dclkss_reg.dclk_ss_load = 1;
	sys_dclkss_reg.dclk_ss_en = 1;
	IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, sys_dclkss_reg.regValue);
*/
	//disable measure
	drvif_measure_total_pixels(_DISABLE);

	if(_TRUE == ucWatchDogFlag)
		fw_scaler_enable_fs_wdg(display, TRUE);

	if(_ENABLE == ucfrc_on_fsync_flag)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _ENABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}

	//USER:LewisLee DATE:2012/12/13
	//fix measure total pixel measure result error
	if(DPLL_PHASE_SWALLOW_CIRCUIT_PATH1 == ucDPLL_Phase_Swallow_Circuit_flag)
	{
		sys_pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
		sys_pll_disp3_reg.dpll_reserve = DPLL_PHASE_SWALLOW_CIRCUIT_PATH1;
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, sys_pll_disp3_reg.regValue);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n framesync_adjust_dvtotal_before_display_at_framesync_mode success\n");

	return _TRUE;

	framesync_adjust_dvtotal_before_display_at_framesync_mode_Enable_Lose_Sync:

	if(_ENABLE == ucfrc_on_fsync_flag)
	{
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		display_timing_ctrl1_reg.disp_frc_on_fsync = _ENABLE;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
	}

	//USER:LewisLee DATE:2012/12/13
	//fix measure total pixel measure result error
	if(DPLL_PHASE_SWALLOW_CIRCUIT_PATH1 == ucDPLL_Phase_Swallow_Circuit_flag)
	{
		sys_pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
		sys_pll_disp3_reg.dpll_reserve = DPLL_PHASE_SWALLOW_CIRCUIT_PATH1;
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, sys_pll_disp3_reg.regValue);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n framesync_adjust_dvtotal_before_display_at_framesync_mode fail\n");
	return _FALSE;
#endif
}


