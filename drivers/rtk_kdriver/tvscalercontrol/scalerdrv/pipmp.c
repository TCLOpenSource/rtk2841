/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for mode related functions.
 *
 * @author 	$Author: jerrylia $
 * @date 	$Date: 2006-06-09 16:01:50 +0800 (?Ÿæ?äº? 09 ?­æ? 2006) $
 * @version 	$Revision: 2039 $
 * @ingroup 	pip
 */

/**
 * @addtogroup pip
 * @{
 */


#define _PIPMP_C
/*======================== MODULE DEPENDENCY =================================*/


#include <linux/semaphore.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/vgip_reg.h>
//#include <rbus/scaler/rbusVDTopReg.h>
//#include <rbus/scaler/rbusVDPQReg.h>

#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/io/ioregdrv.h>

#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/pipmp.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <../tvscalercontrol/scaler_vfedev.h>


/*======================== PRIVATE CONSTANTS =================================*/

/*======================== PRIVATE MACROS ====================================*/

/*======================== PRIVATE TYPES =====================================*/

/*======================== PRIVATE VARIABLES =================================*/
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
static unsigned short  tPipSize[SUBTYPE_ALL>>1][4] = {
	//    Width   Length	MP_Enable_Flag    memory_cap_width
	{0,0,0,0}  , //Sub Small
	{0,0,0,0}  , //Sub Medium
	{0,0,0,0}  , //Sub Large
	{0,0,0,0}  , //MLSR (Side by Side)

	{0,0,0,0}  , //MLSR (Side by Side (4x3))

	{0,0,0,0}  , 	//MP_2X2
	{0,0,0,0}  , 	//MP_3X3
	{0,0,0,0}  , 	//MP_4X4

	{0,0,0,0}  , 	//MP_1C12B
	{0,0,0,0}  , 	//MP_1L7B
	{0,0,0,0} , 		//Sub Full
	{0,0,0,0}   //CUSTOM
};
static StructSrcRect m_customdispwin = {0, 0, 0, 0};
#endif
/*
static unsigned short  tPipSize[SUBTYPE_ALL>>1][4] = {
	//    Width   Length	MP_Enable_Flag    memory_cap_width
	{((_DISP_WID >> 4) << 4)/4,((_DISP_LEN >> 4) << 4)/4,	0x0001, ((_DISP_WID >> 4) << 4)/4}, //Sub Small
	{((_DISP_WID >> 4) << 4)/3,((_DISP_LEN >> 4) << 4)/3,	0x0001, ((_DISP_WID >> 4) << 4)/3}, //Sub Medium
	{((_DISP_WID >> 4) << 4)/2,((_DISP_LEN >> 4) << 4)/2,	0x0001, ((_DISP_WID >> 4) << 4)/2}, //Sub Large
	{_DISP_WID >> 1,	 _DISP_LEN,	0x0001, _DISP_WID >> 1}, //MLSR (Side by Side)
	{_DISP_WID >> 1, (_DISP_WID >> 3) * 3, 0x0001, _DISP_WID >> 1}, //MLSR (Side by Side (4x3))

	{_DISP_WID/2,	_DISP_LEN/2,	0x0033, 960/2}, 	//MP_2X2
	{_DISP_WID/3,	_DISP_LEN/3,	0x0777, 960/3}, 	//MP_3X3
	{_DISP_WID/4,	_DISP_LEN/4,	0xFFFF, 960/4}, 	//MP_4X4

	{_DISP_WID/4,	_DISP_LEN/4,	0xF99F, 960/4}, 	//MP_1C12B
	{_DISP_WID/4,	_DISP_LEN/4,	0xF888, 960/4}, 	//MP_1L7B
	{_DISP_WID,		_DISP_LEN,	0x0001, 960}  		//Sub Full
};
*/
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
static unsigned char subBorderWidth = 0;
#endif
#define _DISP_WID (Get_DISP_ACT_END_HPOS() - Get_DISP_ACT_STA_HPOS())
#define _DISP_LEN  (Get_DISP_ACT_END_VPOS()  - Get_DISP_ACT_STA_VPOS() )


#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
void Pipmp_SetPipCustomWin(StructSrcRect m_dispwin)
{
	m_customdispwin = m_dispwin;
}

StructSrcRect Pipmp_GetPipCustomWin(void)
{
	return m_customdispwin;
}

static void CreatePipSizeTable(void)
{
//Sub Small
tPipSize[0][0]=((_DISP_WID >> 4) << 4)/4;
tPipSize[0][1]=((_DISP_LEN >> 4) << 4)/4;
tPipSize[0][2]=0x0001;
tPipSize[0][3]=((_DISP_WID >> 4) << 4)/4;

//Sub Medium
tPipSize[1][0]=((_DISP_WID >> 4) << 4)/3;
tPipSize[1][1]=((_DISP_LEN >> 4) << 4)/3;
tPipSize[1][2]=0x0001;
tPipSize[1][3]=((_DISP_WID >> 4) << 4)/3;

////Sub Large
tPipSize[2][0]=((_DISP_WID >> 4) << 4)/2;
tPipSize[2][1]=((_DISP_LEN >> 4) << 4)/2;
tPipSize[2][2]=0x0001;
tPipSize[2][3]=((_DISP_WID >> 4) << 4)/2;

//MLSR (Side by Side)
tPipSize[3][0]=_DISP_WID >> 1;
tPipSize[3][1]= _DISP_LEN;
tPipSize[3][2]=0x0001;
tPipSize[3][3]= _DISP_WID >> 1;

//MLSR (Side by Side (4x3))
tPipSize[4][0]=_DISP_WID >> 1;
tPipSize[4][1]=(_DISP_WID >> 3) * 3;
tPipSize[4][2]=0x0001;
tPipSize[4][3]=_DISP_WID >> 1;

//MP_2X2
tPipSize[5][0]=_DISP_WID/2;
tPipSize[5][1]=_DISP_LEN/2;
tPipSize[5][2]=0x0033;
tPipSize[5][3]=960/2;

//MP_3X3
tPipSize[6][0]=_DISP_WID/3;
tPipSize[6][1]=_DISP_LEN/3;
tPipSize[6][2]=0x0777;
tPipSize[6][3]=960/3;

//MP_4X4
tPipSize[7][0]=_DISP_WID/4;
tPipSize[7][1]=_DISP_LEN/4;
tPipSize[7][2]=0xFFFF;
tPipSize[7][3]=960/4;

//MP_1C12B
tPipSize[8][0]=_DISP_WID/4;
tPipSize[8][1]=_DISP_LEN/4;
tPipSize[8][2]=	0xF99F;
tPipSize[8][3]=960/4;

//MP_1L7B
tPipSize[9][0]=_DISP_WID/4;
tPipSize[9][1]=_DISP_LEN/4;
tPipSize[9][2]=0xF888;
tPipSize[9][3]=960/4;

//Sub Full

tPipSize[10][0]=_DISP_WID;
tPipSize[10][1]=_DISP_LEN;
tPipSize[10][2]=0x0001;
tPipSize[10][3]=960;

if((m_customdispwin.src_wid != 0) && (m_customdispwin.src_height!= 0)){
	tPipSize[11][0]=m_customdispwin.src_wid;
	tPipSize[11][1]=m_customdispwin.src_height;
	tPipSize[11][2]=0x0001;
	tPipSize[11][3]=_DISP_WID >> 1;
}else{
	tPipSize[11][0]=_DISP_WID;
	tPipSize[11][1]=_DISP_LEN;
	tPipSize[11][2]=0x0001;
	tPipSize[11][3]=960;
}


}


extern StructSrcRect Scaler_SubDispWindowGet(void);
extern void set_vsc_SetCircle_OutputRegion(VIDEO_RECT_T outregion, UINT32 num);
extern int sub_window_type;
extern int sub_shape_type;
extern int subWin_LGowner;


/*============================================================================*/
/**
 * Pipmp_SetPipCtrl
 * This function is used to control sub display
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
void Pipmp_SetPipCtrl(void)
{
	unsigned long flags;//for spin_lock_irqsave
	StructSrcRect s_dispwin;
	s_dispwin = Scaler_SubDispWindowGet();
	ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_Reg;

	mdomain_disp_ddr_subprevstart_RBUS mdomain_disp_ddr_subprevstart_Reg;
	mdomain_disp_ddr_subprevstart_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_SubPreVStart_reg);
#if 1 //K3L Q8401 frame tear issue
	if(s_dispwin.srcy <= 100) {
		mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = Get_DISP_DEN_STA_VPOS()-7;
	} else {
		mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = (s_dispwin.srcy+Get_DISP_DEN_STA_VPOS()-4);
	}
#else
	mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = 7;
#endif
	IoReg_Write32(MDOMAIN_DISP_DDR_SubPreVStart_reg, mdomain_disp_ddr_subprevstart_Reg.regValue);

	if (Scaler_PipGetInfo(SLR_PIP_TYPE)!=SUBTYPE_PIPFULL) {
		// It seems only Sub display will call this function,
		// should we really need to check "info->display" variable?!
		drvif_scalerdisplay_set_bg_color(SLR_SUB_DISPLAY, _DISPLAY_EB, 0x0C, 0x0D, 0x04);// set external border color
		//sms 2007-11-01 change red to green
		drvif_scalerdisplay_set_bg_color(SLR_SUB_DISPLAY, _DISPLAY_HB, 0x0F, 0x00, 0x00); // set highlight border color(red)
	} else {
		drvif_scalerdisplay_set_bg_color(SLR_SUB_DISPLAY, _DISPLAY_EB, 0x00, 0x00, 0x00); // set external border color
		drvif_scalerdisplay_set_bg_color(SLR_SUB_DISPLAY, _DISPLAY_HB, 0x00, 0x00, 0x00); // set external border color
	}

	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/

	PipmpSetSubDisplayWindow(
		s_dispwin.srcx, s_dispwin.srcx + Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID) ,
		s_dispwin.srcy, s_dispwin.srcy + Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN) ,
		subBorderWidth);

	//WaitFor_DEN_STOP();
#ifdef CONFIG_PIP_SIZE_NARROW_WITHOUT_BORDER
	//Assume left alignment
	PipmpSetSubActiveWindow(
		subBorderWidth, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID) - subBorderWidth - 1,
		subBorderWidth, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN) - subBorderWidth - 1);
#else
	//Assume left alignment
	//reynold added 071212 for PIP window//sms 2007-11-28
	PipmpSetSubActiveWindow(
		0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID)  - 1,
		0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN) - 1);
#endif

	VIDEO_RECT_T outregion;

	outregion.x = s_dispwin.srcx;
	outregion.y = s_dispwin.srcy;
	outregion.w = s_dispwin.src_wid;
	outregion.h = s_dispwin.src_height;
	
	if (subWin_LGowner)
		set_vsc_SetCircle_OutputRegion(outregion, sub_shape_type);
	else
		set_vsc_SetCircle_OutputRegion(outregion, sub_window_type);

	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	ppoverlay_double_buffer_ctrl_Reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_set = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	// clear MP setting
	/*IoReg_Mask32(PPOVERLAY_MP_Layout_Force_to_Background_reg,~(_BIT4 | _BIT5 |_BIT6 |_BIT7),0);*/
	/*IoReg_Write32(MDOMAIN_DISP_DDR_SubBankLimitEndCol_reg,0x00);*/
	drvif_memory_set_dbuffer_write();
	/*IoReg_WriteWord1(PPOVERLAY_MP_Disp_Enable_reg,Scaler_PipGetSubInfo(SLR_PIP_SUB_MPENIDX));		// Set the first MP*/
	/*IoReg_WriteWord0(PPOVERLAY_MP_Disp_Enable_reg,Scaler_PipGetSubInfo(SLR_PIP_SUB_MPHIIDX));		// Highlight the first MP*/

}

/*============================================================================*/
/**
 * Pipmp_SetMpCtrl
 * This function is used to control sub display
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
void Pipmp_SetMpCtrl(void)
{
	unsigned short  Hpos;
	unsigned short  Vpos;
	unsigned short  nWid;
#if 0//mac5p no these setting of sub mp
	IoReg_WriteWord1(PPOVERLAY_MP_Disp_Enable_reg,Scaler_PipGetSubInfo(SLR_PIP_SUB_MPENIDX));		// Set the first MP
	IoReg_WriteWord0(PPOVERLAY_MP_Disp_Enable_reg,Scaler_PipGetSubInfo(SLR_PIP_SUB_MPHIIDX));
#endif
	// Highlight the first MP
	Hpos = 0;	// get horizontal/vertical position, always at top-left
	Vpos = 0;	// get horizontal/vertical position, always at top-left
	nWid = Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID);
	switch(Scaler_PipGetInfo(SLR_PIP_TYPE)) {
			case SUBTYPE_MP2X2:
				nWid *= 2;
				break;

			case SUBTYPE_MP3X3:
				nWid *= 3;
				break;

			case SUBTYPE_MP4X4:
				nWid *= 4;
				break;

			default:
				nWid = 0;
	}
	if(nWid < _DISP_WID)
		Hpos = (_DISP_WID - nWid) / 2;

	PipmpSetSubDisplayWindow(Hpos, Hpos + Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID), Vpos, Vpos + Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN), subBorderWidth);
	drvif_scalerdisplay_set_bg_color(SLR_SUB_DISPLAY, _DISPLAY_EB, 0x0C, 0x0D, 0x04); // set external border color(yellow)
	drvif_scalerdisplay_set_bg_color(SLR_SUB_DISPLAY, _DISPLAY_HB, 0x0F, 0x00, 0x00); // set highlight border color(red)

	//Assume left alignment
	PipmpSetSubActiveWindow(0 , Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID) ,0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN));	// hill modify 20060207

	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	if(!(Scaler_PipGetSubInfo(SLR_PIP_SUB_MPENABLE)))
		IoReg_WriteWord1(PPOVERLAY_MP_Layout_Force_to_Background_reg,0xffff);

	IoReg_Mask32(PPOVERLAY_MP_Layout_Force_to_Background_reg,~(_BIT4 |_BIT5 | _BIT6 | _BIT7), SHL(Scaler_PipGetSubInfo(SLR_PIP_SUB_SUBHVCNT), 4));
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
}

/*============================================================================*/
/**
 * PipmpSetSubDisplayWindow
 * This function is used to set the position of Sub display and background window,
 * including the start/end position in both horizontal and vertical direction
 * Besides, it also contains the border and background information
 *
 * @param <DispHSta> {start position in horizontal direction}
 * @param <DispHEnd> {end position in horizontal direction}
 * @param <DispVSta> {start position in vertical direction}
 * @param <DispVEnd> {end position in vertical direction}
 * @param <Border> {border size}
 * @return { none }
 *
 */
void PipmpSetSubDisplayWindow(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta,
	unsigned short DispVEnd, unsigned char Border)
{
	ppoverlay_sub_den_h_start_width_RBUS sub_den_h_start_width_Reg;
	ppoverlay_sub_den_v_start_length_RBUS sub_den_v_start_length_Reg;
	ppoverlay_sub_background_h_start_end_RBUS sub_background_h_start_end_Reg;
	ppoverlay_sub_background_v_start_end_RBUS sub_background_v_start_end_Reg;

	sub_den_h_start_width_Reg.regValue = IoReg_Read32(PPOVERLAY_SUB_DEN_H_Start_Width_reg);
	sub_den_v_start_length_Reg.regValue = IoReg_Read32(PPOVERLAY_SUB_DEN_V_Start_Length_reg);
	sub_background_h_start_end_Reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Background_H_Start_End_reg);
	sub_background_v_start_end_Reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Background_V_Start_End_reg);

	sub_den_h_start_width_Reg.sh_den_sta = (DispHSta + Get_DISP_ACT_STA_BIOS());
	sub_den_h_start_width_Reg.sh_den_width = (DispHEnd - DispHSta);

	sub_den_v_start_length_Reg.sv_den_sta = DispVSta;
	sub_den_v_start_length_Reg.sv_den_length = (DispVEnd -DispVSta);

	sub_background_h_start_end_Reg.sh_bg_sta = Border;
	sub_background_h_start_end_Reg.sh_bg_end = (DispHEnd - DispHSta - Border);

	sub_background_v_start_end_Reg.sv_bg_sta = Border;
	sub_background_v_start_end_Reg.sv_bg_end = (DispVEnd - DispVSta - Border);

	IoReg_Write32(PPOVERLAY_SUB_DEN_H_Start_Width_reg, sub_den_h_start_width_Reg.regValue);
	IoReg_Write32(PPOVERLAY_SUB_DEN_V_Start_Length_reg, sub_den_v_start_length_Reg.regValue);

	IoReg_Write32(PPOVERLAY_SUB_Background_H_Start_End_reg, sub_background_h_start_end_Reg.regValue);
	IoReg_Write32(PPOVERLAY_SUB_Background_V_Start_End_reg, sub_background_v_start_end_Reg.regValue);
}


void PipmpSetSubDisplayBorder(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta,
	unsigned short DispVEnd, unsigned char Border,unsigned char BorderType)
{
	unsigned char Top = 0, Bottom = 0, Left = 0, Right = 0, Inaccuracy = 0;

	switch(BorderType){
		case BORDERSTYLE_NONE:
			Inaccuracy = 1;
			break;
		case BORDERSTYLE_TOP: //up
			Top = Border;
			break;
		case BORDERSTYLE_BOTTOM: //down
			Bottom = Border;
			break;
		case BORDERSTYLE_LEFT: //left
			Left = Border;
			break;
		case BORDERSTYLE_RIGHT: //right
			Right = Border;
			break;
		case BORDERSTYLE_ALL: //all
		default:
			Top = Border;
			Bottom = Border;
			Left = Border;
			Right = Border;
			break;
	}

	if(DispHSta == DispHEnd) //avoid flicker
		return;

	//set sub DEN
	IoReg_Write32(PPOVERLAY_SUB_DEN_H_Start_Width_reg,((DispHSta & 0x0fff)<<16) | ((DispHEnd-DispHSta-Inaccuracy) & 0x0fff));
	IoReg_Write32(PPOVERLAY_SUB_DEN_V_Start_Length_reg,((DispVSta & 0x07ff)<<16) | ((DispVEnd-DispVSta) & 0x07ff));
	//set sub BG
	IoReg_Write32(PPOVERLAY_SUB_Background_H_Start_End_reg,((Left & 0x0fff)<<16) | ((DispHEnd - DispHSta - Right) & 0x0fff));
	IoReg_Write32(PPOVERLAY_SUB_Background_V_Start_End_reg,((Top & 0x07ff)<<16) | ((DispVEnd - DispVSta - Bottom) & 0x07ff));
}

/*============================================================================*/
/**
 * PipmpSetSubActiveWindow
 * This function is used to set the position of sub active window,
 * including the start/end position in both horizontal and vertical direction
 *
 * @param <DispHSta> {start position in horizontal direction}
 * @param <DispHEnd> {end position in horizontal direction}
 * @param <DispVSta> {start position in vertical direction}
 * @param <DispVEnd> {end position in vertical direction}
 * @return { none }
 *
 */
void PipmpSetSubActiveWindow(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta, unsigned short DispVEnd)
{
	DispHSta += Get_DISP_ACT_STA_BIOS();
	DispHEnd += Get_DISP_ACT_STA_BIOS();
	ppoverlay_sub_active_h_start_end_RBUS sub_active_h_start_end_Reg;
	ppoverlay_sub_active_v_start_end_RBUS sub_active_v_start_end_Reg;

	sub_active_h_start_end_Reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Active_H_Start_End_reg);
	sub_active_v_start_end_Reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Active_V_Start_End_reg);

	sub_active_h_start_end_Reg.sh_act_sta = DispHSta;
	sub_active_h_start_end_Reg.sh_act_end = DispHEnd;

	sub_active_v_start_end_Reg.sv_act_sta = DispVSta;
	sub_active_v_start_end_Reg.sv_act_end = DispVEnd;

	IoReg_Write32(PPOVERLAY_SUB_Active_H_Start_End_reg, sub_active_h_start_end_Reg.regValue);
	IoReg_Write32(PPOVERLAY_SUB_Active_V_Start_End_reg, sub_active_v_start_end_Reg.regValue);
}


/*============================================================================*/
/**
 * PipMp_GetPipSize
 * Get width or height of PIP/MP
 *
 * @param <Type> {Sub Type, see eSubType for details}
 * @param <Width> {Width}
 * @param <Length> {Length}
 * @return { Width or Height of sub display }
 *
 */
void PipMp_GetPipSize(eSubType Type, unsigned short* Width, unsigned short* Length)
{
	Type = (eSubType)((Type >>1) - 1); // skip the bit 1
	CreatePipSizeTable( );
	*Width = AND(tPipSize[Type][0], 0xFFFE);	// width must be even number
	*Length = AND(tPipSize[Type][1], 0xFFFE);	// length must be even number

	if((Scaler_PipGetInfo(SLR_PIP_TYPE) >= SUBTYPE_MP2X2) && (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_MP1L7B)) {
		*Length = AND(*Length, 0xFFFC);	// Multi-Pic Vertical Line alignment 4
		*Width = AND(*Width, 0xFFF0);	// Dragon Multi-Pic need Horizontal Pixel need alignment 16
	}
	else if((Scaler_PipGetInfo(SLR_PIP_TYPE) == SUBTYPE_PIPMLSR) || (Scaler_PipGetInfo(SLR_PIP_TYPE) == SUBTYPE_PIPMLSR_4x3)) {
		*Width = AND(*Width, 0xFFF8);
	}
}

/*============================================================================*/
/**
 * PipMp_GetPipSize
 * Get width or height of PIP/MP
 *
 * @param <Type> {Sub Type, see eSubType for details}
 * @param <Width> {Width}
 * @param <Length> {Length}
 * @return { Width or Height of sub display }
 *
 */
 /*
unsigned short pipmp_get_mem_cap_width()
{
	eSubType Type;

	Type = (eSubType)((Scaler_PipGetInfo(SLR_PIP_TYPE) >>1) - 1); // skip the bit 1
	CreatePipSizeTable( );
	return AND(tPipSize[Type][3], 0xFFFE);	// must be even number?
}
*/

/*============================================================================*/
/**
 * PipMp_GetMpFlag
 * Get MP enable flag
 *
 * @param <Type> {Sub Type, see eSubType for details}
 * @return { MP enable flag}
 *
 */
unsigned short PipMp_GetMpFlag(eSubType Type)
{
	Type = (eSubType)((Type >>1) - 1); // skip the bit 1
	CreatePipSizeTable( );
	return tPipSize[Type][2];
}

/*============================================================================*/
/**
 * PipMp_GetPipPos
 * This function is used to get position of PIP
 *
 * @param <Pos> {Position of sub display}
 * @param <HStart> {horizontal start position}
 * @param <VStart> {vertical start position}
 * @return { Position of sub display }
 *
 */
void PipMp_GetPipPos(ePipPos Pos, eSubType Type, unsigned short* HStart, unsigned short* VStart)
{
	unsigned short  PipWidth = 0;
	unsigned short  PipLength = 0;

	if (Type == SUBTYPE_PIPMLSR) {
		PipMp_GetPipSize(Type, &PipWidth, &PipLength);
		*HStart = PipWidth;
		*VStart = 0;
		if((unsigned int)(PipWidth << 1) < _DISP_WID) {
			*HStart += ((_DISP_WID - (PipWidth << 1)) >> 1);
		}
	}
	else if (Type == SUBTYPE_PIPMLSR_4x3) {	//MLSR
		// for MLSR, sub display shows at the right half
		PipMp_GetPipSize(Type, &PipWidth, &PipLength);
		*HStart = PipWidth;
		*VStart = (_DISP_LEN - PipLength) >> 1;
		// get PIP size
		if((unsigned int)(PipWidth << 1) < _DISP_WID) {
			*HStart += ((_DISP_WID - (PipWidth << 1)) >> 1);
		}
	}
	else if (Type == SUBTYPE_PIPCUSTOM) {	//CUSTOM PIP type
		*HStart = m_customdispwin.srcx;
		*VStart = m_customdispwin.srcy;
	}
	else if ((Type == SUBTYPE_PIPSMALL) ||
			(Type == SUBTYPE_PIPMEDIUM) ||
			(Type == SUBTYPE_PIPLARGE)) {
		// for PIP small/medium/large, sub display is based on the PIP position
		PipMp_GetPipSize(Type, &PipWidth, &PipLength);	// get PIP size
		switch (Pos) {
			case PIPPOS_TOPLEFT:	// top-left corner
				*HStart = 0;
				*VStart = 0;
				break;
			case PIPPOS_BOTTOMLEFT:	// bottom-left corner
				*HStart = 0;
				*VStart = _DISP_LEN - PipLength;
				break;
			case PIPPOS_CENTER:		// center
				*HStart = (_DISP_WID - PipWidth)/2;
				*VStart = (_DISP_LEN - PipLength)/2;
				break;
			case PIPPOS_TOPRIGHT:	// top-right corner
				*HStart = _DISP_WID - PipWidth + 1;  //align right
				*VStart = 0;
				break;
			case PIPPOS_BOTTOMRIGHT:// bottom-right corner
				//sms 2007-11-12
				#ifdef CONFIG_CUSTOMER_1_sz
				*HStart = _DISP_WID - PipWidth - 3;
				*VStart = _DISP_LEN - PipLength;
				#else
				*HStart = _DISP_WID - PipWidth + 1; // align right
				*VStart = _DISP_LEN - PipLength ;
				#endif
				break;
		}
	}else {
		// for other cases, Sub display starts from top-left corner
		*HStart = 0;
		*VStart = 0;
	}
}
/*============================================================================*/
/**
 * PipMpSetMpEnable
 * Set MP layout enable registers
 *
 * @param <MpEnable> {MP enable flag}
 * @return {none}
 *
 */
void PipMpSetMpEnable(unsigned short MpEnable)
{
#if 0//mac5p no these setting of sub mp
	IoReg_WriteWord1(PPOVERLAY_MP_Disp_Enable_reg,MpEnable);
#endif
}

/*============================================================================*/
/**
 * PipMpSetMpHiEnable
 * Set MP layout enable registers
 *
 * @param <MpEnable> {MP enable flag}
 * @return {none}
 *
 */
void PipMpSetMpHiEnable(unsigned short HiEnable)
{
#if 0//mac5p no these setting of sub mp
	IoReg_WriteWord0(PPOVERLAY_MP_Disp_Enable_reg,HiEnable);
#endif
}

/*============================================================================*/
/**
 * PipMp_SetSubInfo
 * Set sub (PIP/MP) info
 *
 * @param <SubType> {Sub type}
 * @return {none}
 *
 */
void PipMp_SetSubInfo(unsigned char SubType)
{
	Scaler_PipSetSubInfo(SLR_PIP_SUB_MPHIIDX,0x0001);	// initial the first window
	Scaler_PipSetSubInfo(SLR_PIP_SUB_MPENIDX,0x0001);	// initial the first window

	switch(SubType)
	{
		case SUBTYPE_MP2X2:
			Scaler_PipSetSubInfo(SLR_PIP_SUB_SUBHVCNT, 0x05);
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPCNT, 6);
			break;
		case SUBTYPE_MP3X3:
			Scaler_PipSetSubInfo(SLR_PIP_SUB_SUBHVCNT, 0x0A) ;
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPCNT, 11);
			break;
		case SUBTYPE_MP4X4:
		case SUBTYPE_MP1C12B:	//12 sub multi-pictures besieges one main center picture
			Scaler_PipSetSubInfo(SLR_PIP_SUB_SUBHVCNT, 0x0F);
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPCNT, 16);
			break;
		case SUBTYPE_MP1L7B:		//7 multi-pictures besieges one main left-top picture
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPHIIDX,0x0008);	// initial the first window
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPENIDX,0x0008);	// initial the first window
			Scaler_PipSetSubInfo(SLR_PIP_SUB_SUBHVCNT, 0x0F);
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPCNT, 16);
			break;
		default :
			Scaler_PipSetSubInfo(SLR_PIP_SUB_SUBHVCNT, 0x00);
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPCNT, 1);
			break;
	}
}


/*============================================================================*/
/**
 * PipMpSortMp
 * Sort MP enable/highlight sequence
 *
 * @param <MpSeq> {original MP sequence}
 * @return <SortMp> {Re-sort MP sequence}
 * @note
 * 1. MP_1C12B & MP_1L7B need to re-sort sequence
 * 2. It should be inverse of PipMpReSortMp()
 *
 */
unsigned short PipMpSortMp(unsigned short MpSeq)
{
	unsigned short SortMp;
	unsigned char tmp;
	unsigned char i;
	unsigned char  OriArray[16];
	unsigned char  NewArray[16];

	switch (Scaler_PipGetInfo(SLR_PIP_TYPE))
	{
		case SUBTYPE_MP1C12B:
			for (i=0; i<16; i++)
				OriArray[i] = AND(SHR(MpSeq, i), 0x01);	// get each bit

			NewArray[0] = OriArray[0];
			NewArray[1] = OriArray[1];
			NewArray[2] = OriArray[2];
			NewArray[3] = OriArray[3];
			NewArray[4] = OriArray[7];
			NewArray[5] = OriArray[5];
			NewArray[6] = OriArray[6];
			NewArray[7] = OriArray[11];
			NewArray[8] = OriArray[15];
			NewArray[9] = OriArray[9];
			NewArray[10] = OriArray[10];
			NewArray[11] = OriArray[14];
			NewArray[12] = OriArray[13];
			NewArray[13] = OriArray[12];
			NewArray[14] = OriArray[8];
			NewArray[15] = OriArray[4];

			SortMp = 0;
			for (i=0; i<16; i++)
				SortMp += SHL(NewArray[i], i);
			break;
		case SUBTYPE_MP1L7B:
			// reverse the highest 4 bits
			// original sequence 15 14 13 12 11 10 ... 0
			// new sequence      12 13 14 15 11 10 ... 0
			SortMp = 0;
			tmp = SHR(MpSeq, 12);	// get the highest 4 bits
			for (i=0; i<4; i++)
			{
				SortMp = SHL(SortMp, 1);	// shift left reverse
				SortMp += AND(tmp, 1);	// get each bit
				tmp = SHR(tmp, 1);		// shift right to reverse
			}
			SortMp = SHL(SortMp, 12) + AND(MpSeq, 0x0FFF); // append the other 12 bits
			break;
		default:
			SortMp = MpSeq;
			break;
	}
	return SortMp;
}

/*============================================================================*/
/**
 * PipMpReSortMp
 * Re-sort MP enable/highlight sequence
 *
 * @param <SortMp> {original MP sequence}
 * @return <SortMp> {Re-sort MP sequence}
 * @note
 * 1. MP_1C12B & MP_1L7B need to re-sort sequence
 * 2. It should be inverse of PipMpSortMp()
 */
unsigned short PipMpReSortMp(unsigned short MpSeq)
{
	unsigned short SortMp;
	unsigned char tmp;
	unsigned char i;
	unsigned char  OriArray[16];
	unsigned char  NewArray[16];

	switch (Scaler_PipGetInfo(SLR_PIP_TYPE))
	{
		case SUBTYPE_MP1C12B:
			for (i=0; i<16; i++)
				OriArray[i] = AND(SHR(MpSeq, i), 0x01);	// get each bit

			NewArray[0] = OriArray[0];
			NewArray[1] = OriArray[1];
			NewArray[2] = OriArray[2];
			NewArray[3] = OriArray[3];
			NewArray[4] = OriArray[15];
			NewArray[5] = OriArray[5];
			NewArray[6] = OriArray[6];
			NewArray[7] = OriArray[4];
			NewArray[8] = OriArray[14];
			NewArray[9] = OriArray[9];
			NewArray[10] = OriArray[10];
			NewArray[11] = OriArray[7];
			NewArray[12] = OriArray[13];
			NewArray[13] = OriArray[12];
			NewArray[14] = OriArray[11];
			NewArray[15] = OriArray[8];

			SortMp = 0;
			for (i=0; i<16; i++)
				SortMp += SHL(NewArray[i], i);
			break;
		case SUBTYPE_MP1L7B:
			// reverse the highest 4 bits
			// original sequence 15 14 13 12 11 10 ... 0
			// new sequence      12 13 14 15 11 10 ... 0
			SortMp = 0;
			tmp = SHR(MpSeq, 12);	// get the highest 4 bits
			for (i=0; i<4; i++)
			{
				SortMp = SHL(SortMp, 1);	// shift left reverse
				SortMp += AND(tmp, 1);	// get each bit
				tmp = SHR(tmp, 1);		// shift right to reverse
			}
			SortMp = SHL(SortMp, 12) + AND(MpSeq, 0x0FFF); // append the other 12 bits
			break;
		default:
			SortMp = MpSeq;
			break;
	}
	return SortMp;
}

void PipMp_DisableSubChannel(void)
{
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
}

void PipMp_SetSubBorderWidth(unsigned char width)
{
	subBorderWidth = width;
	return;
}

#endif //CONFIG_DUAL_CHANNEL  // There are two channels
/*======================== End of File =======================================*/

/**
 *
 * @}
 */

