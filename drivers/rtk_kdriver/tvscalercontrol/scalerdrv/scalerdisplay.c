/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler display related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	display
 */

/**
 * @addtogroup display
 * @{
 */

/*============================ Module dependency  ===========================*/
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
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/spinlock_types.h>/*For spinlock*/
//#include <mach/io.h>

#include <rbus/ppoverlay_reg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/pif_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/di_reg.h>
#include <rbus/scaleup_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
//FIXME #include <rbus/rbusScaledownReg.h>
#include <rbus/pinmux_lvdsphy_reg.h>
#include <rbus/yuv2rgb_reg.h>
#include <rbus/subtovl_reg.h>
#include <rbus/sfg_reg.h>
#include <rbus/tcon_reg.h>

#include <rtk_kdriver/scalercommon/scalerCommon.h>
#include "tvscalercontrol/io/ioregdrv.h"
#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/scalerdrv/scalerdrv.h"
#include "tvscalercontrol/scalerdrv/pipmp.h"
#include "tvscalercontrol/scalerdrv/mode.h"
#include "tvscalercontrol/scalerdrv/scalermemory.h"
#include "tvscalercontrol/scalerdrv/scalerclock.h"
#include "tvscalercontrol/panel/panelapi.h"
#include "tvscalercontrol/hdmirx/hdmifun.h"
#include "tvscalercontrol/scalerdrv/scaler_2dcvt3d_ctrl.h"
#include "tvscalercontrol/scalerdrv/framesync.h"
#include <tvscalercontrol/vip/ultrazoom.h>
#include "tvscalercontrol/scalerdrv/scalerdisplay.h"
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <tvscalercontrol/vdc/video.h>
#include <mach/rtk_log.h>

#ifdef CONFIG_PCBMGR
#include <Platform_Lib/Board/pcbMgr.h>
#include <assert.h>
#endif

#if defined (ENABLE_QUADFHD)
#include <Platform_Lib/QuadFHD/QuadFHD.h>
#endif
#include <rpc/VideoRPC_System.h>
#include <rpc/VideoRPC_System_data.h>
#define UNCAC_BASE		_AC(0xa0000000, UL)
#include <../tvscalercontrol/vo/rtk_vo.h>	//for VODMA_COLOR_YUV444
#include "../tvscalercontrol/scaler_vpqmemcdev.h"
#include <../tvscalercontrol/scaler_vscdev.h>


#include "../tvscalercontrol/scaler_vscdev.h"

// register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

/*================================ Definitions ==============================*/
/*===================================  Types ================================*/
/*================================== Variables ==============================*/
static unsigned short Hstart = 0;//record main Hstart
static unsigned short Vstart = 0;//record main Vstart
void (*pOverscan_func)(stDISPLAY_OVERSCAN_DATA *pt_scan, SLR_RATIO_TYPE ratio_type);
void (*pGet_Src_Overscan_ratio)(UINT8 *h_ratio, UINT8 *v_ratio);
void (*pVGIP_Adjustment_func) (stVGIP_ADJUSTMENT_INFO *pt_data, SLR_RATIO_TYPE ratio_type);
void (*pOverscan3D_func) (UINT16  *h_ratio, UINT16 *v_ratio);
extern void set_ATV_passthrought_output_flag(unsigned char display, unsigned char flag);
#ifdef ENABLE_MHEG5
void (*pMHEG5_Adjustment_func) (stVGIP_ADJUSTMENT_INFO *pt_data)=NULL;
#endif
#define TAG_NAME_VBE "VBE"

static DEFINE_SPINLOCK(Main_DBReg_Spinlock);/*Spin lock no context switch. This is for MAIN double buffer register protection*/
static DEFINE_SPINLOCK(Main_FBReg_Spinlock);/*Spin lock no context switch. This is for MAIN forcebg register protection*/

#ifdef CONFIG_DUAL_CHANNEL
static DEFINE_SPINLOCK(Sub_DBReg_Spinlock);/*Spin lock no context switch. This is for SUB double buffer protection*/
static DEFINE_SPINLOCK(Sub_FBReg_Spinlock);/*Spin lock no context switch. This is for SUB forcebg register protection*/
#endif

static struct semaphore ForceBG_Semaphore;/* This Semaphore is for force bg control*/
static DEFINE_SPINLOCK(ForceBG_Main_Mask_Spinlock);/*Spin lock no context switch. This spinlock is for force bg mask*/
static DEFINE_SPINLOCK(ForceBG_Sub_Mask_Spinlock);/*Spin lock no context switch. This spinlock is for force bg mask*/
extern unsigned char get_sub_OutputVencMode(void);

static struct semaphore DI_Semaphore;/*This semaphore is for DI register setting*/

static unsigned char display_forcebg_mask[MAX_DISP_CHANNEL_NUM][SLR_FORCE_BG_TYPE_MAX] =
{
	{TRUE, FALSE, FALSE, FALSE, FALSE},
#ifdef CONFIG_DUAL_CHANNEL
	{TRUE, FALSE, FALSE, FALSE, FALSE}
#endif

};

#ifdef CONFIG_I2RND_ENABLE
extern unsigned char vsc_i2rnd_sub_stage;
#endif
#define V_HALF_TOTAL_480I 263
#define V_HALF_TOTAL_576I 313

// Be Careful !!
// Display window setting in FreeV[] MUST follow the definition of
// 1. DISP_WID and DISP_LEN
// 2. DH_ACT_STA_POS and DH_ACT_END_POS
// 3. DV_ACT_STA_POS and DV_ACT_END_POS
// 4. Background window must be the same as active window.

/*
unsigned int __initdata tDisplayTiming[] =
{
	1, SYSTEM_LVDS_RSDS_PAD_CTRL1_VADDR, 0,		// Fixed show not good
	11, DDOMAIN_DISPLAY_TIMING_CTRL1_VADDR,
	_BIT25 | _BIT24 | _BIT16 | _BIT10 | (CONFIG_DISPLAY_COLOR_BITS << 22) |  (CONFIG_DISPLAY_PORT << 17)
	| (CONFIG_DISPLAY_PORTAB_SWAP << 8) | (CONFIG_DISPLAY_RED_BLUE_SWAP << 7) |
	(CONFIG_DISPLAY_MSB_LSB_SWAP << 6) | (CONFIG_DISPLAY_OUTPUT_INVERSE << 4),
	0,
	CONFIG_DISP_HSYNC_WIDTH,
	((CONFIG_DISP_HORIZONTAL_TOTAL - 1) << 16) | (CONFIG_DISP_HSYNC_LASTLINE - 1),
	CONFIG_DISP_VSYNC_LENGTH - 1,
	CONFIG_DISP_VERTICAL_TOTAL - 1,
	(CONFIG_DISP_DEN_STA_HPOS << 16) | CONFIG_DISP_DEN_END_HPOS,
	(CONFIG_DISP_DEN_STA_VPOS << 16) | CONFIG_DISP_DEN_END_VPOS,
	0,
	0x00ff0000,
	0,
	1, DDOMAIN_MP_DISP_ENABLE_VADDR, 0,
	_TBL_END
};

unsigned int  __initdata tDisplayMain[] =
{
	1, DDOMAIN_DOUBLE_BUFFER_CTRL_VADDR, 5,
	9, DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR,
	 1,
	 0x0000f000,
	 0x000f0000,

	//Display window H Enable setting // 0x437
	(CONFIG_DISP_ACT_STA_HPOS<< 16) | CONFIG_DISP_ACT_END_HPOS,

	//Display window V Enable setting // 0x43a
	(CONFIG_DISP_ACT_STA_VPOS <<16) | CONFIG_DISP_ACT_END_VPOS,

	//Background window H setting // 0x43d
	(CONFIG_DISP_ACT_STA_HPOS << 16) | CONFIG_DISP_ACT_END_HPOS,

	//Background window V setting // 0x440
	(CONFIG_DISP_ACT_STA_VPOS << 16) | CONFIG_DISP_ACT_END_VPOS,

	//Active window H setting // 0x443
	(CONFIG_DISP_ACT_STA_HPOS << 16) | CONFIG_DISP_ACT_END_HPOS,

	//Active window V setting // 0x446
	(CONFIG_DISP_ACT_STA_VPOS << 16) | CONFIG_DISP_ACT_END_VPOS,

	1, DDOMAIN_DOUBLE_BUFFER_CTRL_VADDR, 1,

	_TBL_END
};
*/
/*================================== Function ===============================*/
/*============================================================================*/
/*============================================================================*/


void drvif_scaler_tvbox_display_init(void)
{
	if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX){
		ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;
		ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;

		dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
		dh_den_start_end_reg.dh_den_sta = Get_DISP_DEN_STA_HPOS() & 0x1fff;
		dh_den_start_end_reg.dh_den_end = Get_DISP_DEN_END_HPOS() & 0x1fff;
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, dh_den_start_end_reg.regValue);

		dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
		dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
		dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
		IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);
	}
}

unsigned char fwif_display_regTable(DISPLAY_REG_TABLE_TYPE index, void *ptr)
{
	if (!ptr
#ifdef ENABLE_MHEG5
        && (DISPLAY_REG_FUNC_MHEG5_ADJUSTMENT != index)
#endif
    )
		return FALSE;

	switch(index)
	{
		case DISPLAY_REG_FUNC_OVERSCAN:
			pOverscan_func = (void (*)(stDISPLAY_OVERSCAN_DATA*, SLR_RATIO_TYPE))ptr;
			break;
		case DISPLAY_REG_FUNC_GET_SRC_OVERSCAN:
			pGet_Src_Overscan_ratio = (void (*)(UINT8 *,UINT8 *))ptr;
			break;
		case DISPLAY_REG_FUNC_VGIP_ADJUSTMENT:
			pVGIP_Adjustment_func =(void (*)(stVGIP_ADJUSTMENT_INFO*, SLR_RATIO_TYPE))ptr;
			break;
		case DISPLAY_REG_FUNC_3DOVERSCAN:
			pOverscan3D_func = (void (*)(UINT16 *,UINT16 *))ptr;
			break;
#ifdef ENABLE_MHEG5
        case DISPLAY_REG_FUNC_MHEG5_ADJUSTMENT:
            pMHEG5_Adjustment_func = (void (*)(stVGIP_ADJUSTMENT_INFO*))ptr;
            break;
#endif
		default:
			break;
	}

	return TRUE;
}

/**
 * scalerdisplay_get_main_pos
 * Retrieve main window position.Mostly, it will be at the top-left corner,
 * except 1C12B sub diaply
 *
 * @return { none }
 *
 */
 void CreateDisplayTimingTable(void)
{
#if 0//This is no used. confirm with BEN
	unsigned int data = 0 ;
	unsigned int usDisplaytiming[18];

	usDisplaytiming[0] = 11;
	usDisplaytiming[1] = PPOVERLAY_Display_Timing_CTRL1_reg;
//#ifdef VBY_ONE_PANEL
//	data = (Get_PANEL_FIX_LAST_LINE_4X_ENABLE() << 28);
//#else
	data = _BIT24 | (Get_PANEL_FIX_LAST_LINE_4X_ENABLE() << 28);
//#endif
	usDisplaytiming[2] = data;
	usDisplaytiming[3] =(0x3<<30);  // set SR bypass
	usDisplaytiming[4] = Get_DISP_HSYNC_WIDTH();
	usDisplaytiming[5] = ((Get_DISP_HORIZONTAL_TOTAL() - 1) << 16) | (Get_DISP_HSYNC_LASTLINE()-1) ;
	usDisplaytiming[6] = Get_DISP_VSYNC_LENGTH();
	usDisplaytiming[7] = (Get_DISP_VERTICAL_TOTAL() - 1) ;
	usDisplaytiming[8] =	(Get_DISP_DEN_STA_HPOS() << 16) | Get_DISP_DEN_END_HPOS();
	usDisplaytiming[9] = (Get_DISP_DEN_STA_VPOS() << 16) | Get_DISP_DEN_END_VPOS();
	usDisplaytiming[10] = 0;
	usDisplaytiming[11] = 0x00000000;//Set Background color is black color
	usDisplaytiming[12] = 4;//Write Display timing generator register immediately
#ifdef CONFIG_DUAL_CHANNEL
	usDisplaytiming[13] = 1;
	usDisplaytiming[14] = PPOVERLAY_MP_Disp_Enable_reg;
	usDisplaytiming[15] = 0;
	usDisplaytiming[16] = _TBL_END;
#else
	usDisplaytiming[17] = _TBL_END;
#endif

	//WaitFor_DEN_STOP();
	fw_scaler_dtg_double_buffer_enable(1);
	drvif_scaler_WriteTable(usDisplaytiming);
	fw_scaler_dtg_double_buffer_apply();
	//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);

	// re-config display mode
//	scaler_PixelWorks_PA168_LVDS_output_control(TRUE);
#endif
}

static void scalerdisplay_get_main_pos(unsigned short *HStartOffset, unsigned short *VStartOffset)
{
	*HStartOffset = 0;	// start from top-left corner
	*VStartOffset = 0;
}

void scalerdisplay_Change_panel_hvtotal(unsigned char enable)
{
#if 1
	//USER:LewisLee DATE:2012/06/24
	//mask un-used code
	//it should apply at scalerdisplay_set_timing()
#else //#if 1
	if(enable){
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, (2650<<16)| (2650 | _BIT0));
		IoReg_Write32(PPOVERLAY_DV_total_reg, 1092);
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, (365<<16)| 2285);
		IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, (6<<16)|1086);
	}else{
//		rtd_outl(PPOVERLAY_DH_Total_Last_Line_Length_reg, ((Get_DISP_HORIZONTAL_TOTAL() - 1)<<16)| (Get_DISP_HSYNC_LASTLINE() - 1));
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, ((Get_DISP_HORIZONTAL_TOTAL() - 1)<<16) | (Get_DISP_HSYNC_LASTLINE() - 1));
		IoReg_Write32(PPOVERLAY_DV_total_reg, (Get_DISP_VERTICAL_TOTAL() - 1));
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, (Get_DISP_DEN_STA_HPOS()<<16)| Get_DISP_DEN_END_HPOS());
		IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, (Get_DISP_DEN_STA_VPOS()<<16)|Get_DISP_DEN_END_VPOS());
	}
#endif //#if 1
}

/*============================================================================*/
/**
 * scalerdisplay_set_main_act_window
 * This function is used to set the position of Main active window,
 * including the start/end position in both horizontal and vertical direction
 *
 * @param <DispHSta> {start position in horizontal direction}
 * @param <DispHEnd> {end position in horizontal direction}
 * @param <DispVSta> {start position in vertical direction}
 * @param <DispVEnd> {end position in vertical direction}
 * @return { none }
 *
 */
#if 1
void scalerdisplay_set_main_act_window(UINT16 DispHSta, UINT16 DispHEnd, UINT16 DispVSta, UINT16 DispVEnd)
{
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

	DispHSta += Get_DISP_ACT_STA_BIOS();
	DispHEnd += Get_DISP_ACT_STA_BIOS();


	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[DISP] set main=H=%x/%x, V=%x/%x\n", DispHSta, DispHEnd, DispVSta, DispVEnd);

	// Main Active H pos
	main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
	main_active_h_start_end_reg.mh_act_sta = (DispHSta & 0x0fff);
	main_active_h_start_end_reg.mh_act_end = (DispHEnd & 0x0fff);
	IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);

	// Main Active V pos
	main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
	main_active_v_start_end_reg.mv_act_sta = DispVSta & 0x0fff;
	main_active_v_start_end_reg.mv_act_end = DispVEnd & 0x0fff;
	IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
}
#else // #if 1
void scalerdisplay_set_main_act_window(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta,unsigned short DispVEnd)
{

	DispHSta += Get_DISP_ACT_STA_BIOS();
	DispHEnd += Get_DISP_ACT_STA_BIOS();
	// Main Active H pos

	IoReg_Mask32(PPOVERLAY_MAIN_Active_H_Start_End_reg, 0xf000f000, ((DispHSta & 0x0fff) << 16) | (DispHEnd & 0x0fff));
	// Main Active V pos
	IoReg_Mask32(PPOVERLAY_MAIN_Active_V_Start_End_reg, 0xf000f000, ((DispVSta & 0x0fff) << 16) | (DispVEnd & 0x0fff));

	drvif_scalerdisplay_set_dbuffer_en(FALSE);
}
#endif // #if 1


/*============================================================================*/
/**
 * scalerdisplay_vo_ratio_change
 * This function is used to change display window and uzu smoothly of VO ratio change,
 *
 * @param <void>
 * @return { none }
 *
 */
void scalerdisplay_vo_ratio_change(VO_VIDEO_PLANE plane)
 {
	unsigned short dispLen = 0;
	unsigned short dispWid = 0;
	unsigned short DispHSta, DispHEnd, DispVSta, DispVEnd;
	SIZE inSize, outSize;
	unsigned short VRatioOffset = 0, HRatioOffset = 0;
	unsigned int panel_ratio = 0;
	unsigned int source_ratio = 0;
	unsigned int input_height;
	SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(plane);
	input_height= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
	dispLen = (unsigned short)_DISP_LEN;	// get original panel length
	dispWid = (unsigned short)_DISP_WID;	// get original panel width

	if(pVOInfo->progressive == 0)
		input_height = input_height*2;
	//frank@0515 add below code to avoid ratio caculate overflow 32bits,1920X1080=2073600,so 2073600X2070 will overflow
    if((pVOInfo->pixelAR_ver>100 && pVOInfo->pixelAR_hor > 100) &&((pVOInfo->pixelAR_ver*input_height)>2000 ||(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor)>2000)){
        pVOInfo->pixelAR_ver /=100;
        pVOInfo->pixelAR_hor /=100;
    }

	panel_ratio = (unsigned int)input_height*pVOInfo->pixelAR_ver*dispWid;
	source_ratio = (unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor*dispLen;
	if(panel_ratio > source_ratio){//Change panel width
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_LEN, dispLen);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_WID, ((dispLen*(unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor)/(input_height*pVOInfo->pixelAR_ver)));
	}else{//Change panel height
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_LEN, ((dispWid*(unsigned int)input_height*pVOInfo->pixelAR_ver)/((unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor)));
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_WID, dispWid);
	}

	if((_DISP_WID == Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID)) && (_DISP_LEN != Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN))){//change height
		VRatioOffset = (_DISP_LEN-Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN))/2;
		HRatioOffset = 0;
	}else if((_DISP_WID != Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID)) && (_DISP_LEN == Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN))){//change width
		HRatioOffset = (_DISP_WID-Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID))/2;
		VRatioOffset = 0;
	}else{//not change width & height
		HRatioOffset = 0;
		VRatioOffset = 0;
	}
	dispWid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_WID);
	dispLen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_LEN);
	inSize.nWidth = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MEM_ACT_WID);;
	inSize.nLength = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MEM_ACT_LEN);
	outSize.nWidth = dispWid;
	outSize.nLength = dispLen;

	// active window
	DispHSta =HRatioOffset + Get_DISP_ACT_STA_HPOS();
	DispHEnd = DispHSta + dispWid;
	DispVSta = VRatioOffset + Get_DISP_ACT_STA_VPOS();
	DispVEnd = DispVSta + dispLen;
	WaitFor_DEN_STOP_Period(2, 10);
	drvif_color_ultrazoom_setscaleup(SLR_MAIN_DISPLAY, &inSize, &outSize, 0);
	scalerdisplay_set_main_act_window(DispHSta, DispHEnd, DispVSta, DispVEnd);
 }

/**
 * CDisplaySetMainCtrl
 * This function is used to control main display
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
static void scalerdisplay_set_main_ctrl(void)
{
	unsigned short VRatioOffset = 0, HRatioOffset = 0;
	unsigned short HStartOffset = 0;
	unsigned short VStartOffset = 0;
#ifdef CONFIG_DUAL_CHANNEL
	unsigned short nVSize = 0, nHSize = 0;
#endif
	SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode2();

	if(get_3D_overscan_enable() == TRUE)
	{
		scalerdisplay_set_main_act_window(	(unsigned short)get_3D_overscan_output_hsta(),
										(unsigned short)get_3D_overscan_output_wid()+ get_3D_overscan_output_hsta() ,
										(unsigned short)get_3D_overscan_output_vsta(),
										(unsigned short)get_3D_overscan_output_len()+ get_3D_overscan_output_vsta() );
		Hstart = get_3D_overscan_output_hsta();
		Vstart = get_3D_overscan_output_vsta();
		return;
	}


#ifdef CONFIG_ENABLE_NORMAL_DISPLAY_RATIO_MODE
	if(_TRUE == Scaler_Get_AspectRatio_Enter_Normal_Mode())
	{
		ratio_type = Scaler_Get_Normal_AspectRatio_RatioType();
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scalerdisplay_set_main_ctrl, Normal Mode : %x\n", ratio_type);
	}
#endif //#ifdef CONFIG_ENABLE_NORMAL_DISPLAY_RATIO_MODE

#ifdef CONFIG_ENABLE_DOT_BY_DOT_DISPLAY_RATIO_MODE
	if(_TRUE == Scaler_Get_AspectRatio_Enter_DotByDot_Mode())
	{
		ratio_type = Scaler_Get_DotByDot_AspectRatio_RatioType();
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scalerdisplay_set_main_ctrl, DotByDot Mode : %x\n", ratio_type);
	}
#endif //#ifdef CONFIG_ENABLE_DOT_BY_DOT_DISPLAY_RATIO_MODE

#ifdef CONFIG_ENABLE_NATIVE_DISPLAY_RATIO_MODE
	if(_TRUE == Scaler_Get_AspectRatio_Enter_Native_Mode())
	{
		ratio_type = Scaler_Get_Native_AspectRatio_RatioType();
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scalerdisplay_set_main_ctrl, Native Mode : %x\n", ratio_type);
	}
#endif //#ifdef CONFIG_ENABLE_NATIVE_DISPLAY_RATIO_MODE

	if ( (ratio_type==SLR_RATIO_POINTTOPOINT)/* && (!Scaler_PipGetInfo(SLR_PIP_ENABLE)) */) {
		if ( _DISP_WID > Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) )
			HRatioOffset = (_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) ) / 2;
		else
			HRatioOffset = 0;

		if ( _DISP_LEN > Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) )
			VRatioOffset = (_DISP_LEN - Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN)) / 2;
		else
			VRatioOffset = 0;
	}
/*
	if (drvif_scaler3d_decide_dispM_3d_output_frame_seq())
	{
		// reset main display window
		scalerdisplay_set_main_display_window(0, _DISP_WID, 0, _DISP_LEN, 0);
	}
*/
	scalerdisplay_set_main_display_window(0, _DISP_WID, 0, _DISP_LEN, 0);
	drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_EB, 0x0C, 0x0D, 0x04); // set external border color
	scalerdisplay_get_main_pos(&HStartOffset, &VStartOffset);	// get main position offset

#ifdef CONFIG_DUAL_CHANNEL
	if ( (Scaler_PipGetInfo(SLR_PIP_TYPE) == SUBTYPE_PIPMLSR_4x3) ||(Scaler_PipGetInfo(SLR_PIP_TYPE) == SUBTYPE_PIPMLSR) ) {
		//VStartOffset =  ??
		if ( Scaler_PipGetInfo(SLR_PIP_TYPE) == SUBTYPE_PIPMLSR_4x3 ) {
			PipMp_GetPipSize(SUBTYPE_PIPMLSR_4x3, &nHSize, &nVSize);
			if ( (unsigned int)(nHSize << 1) < _DISP_WID )
				HStartOffset += ((_DISP_WID - (nHSize << 1)) >> 1);

			VStartOffset += ((_DISP_LEN - nVSize) >> 1);
		}
		else if ( Scaler_PipGetInfo(SLR_PIP_TYPE) == SUBTYPE_PIPMLSR ) {
			PipMp_GetPipSize(SUBTYPE_PIPMLSR, &nHSize, &nVSize);
			if ( (unsigned int)(nHSize << 1) < _DISP_WID )
				HStartOffset += ((_DISP_WID - (nHSize << 1)) >> 1);
		}

		scalerdisplay_set_main_act_window(
			(unsigned short)HStartOffset,
			(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HStartOffset ,
			(unsigned short)VRatioOffset + VStartOffset,
			(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VStartOffset );
		Hstart = HStartOffset;
		Vstart = VRatioOffset + VStartOffset;
		return;
	}
#endif

	#ifdef CONFIG_3D_ASPECT_RATIO

	#endif
#ifdef ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
	if((Get_GOSUBandVODMA()==TRUE)&&((get_rotate_mode()==ROTATE_MODE_90)||(get_rotate_mode()==ROTATE_MODE_270))&&(Scaler_InputSrcGetMainChType() == _SRC_VO))
	{
		HStartOffset = (_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID))>>1;
		VStartOffset = (_DISP_LEN - Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN))>>1;
		scalerdisplay_set_main_act_window(	(unsigned short)HStartOffset,
										(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HStartOffset ,
										(unsigned short)VStartOffset,
										(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VStartOffset );
		Hstart = HStartOffset;
		Vstart = VStartOffset;
		return;
	}
#endif
	//frank@0526 add below code to show jpeg to full panel
	if ((Scaler_InputSrcGetMainChType() == _SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane())==1)){
		VRatioOffset = 0; // offset at vertical direction, zero at this case
		scalerdisplay_set_main_act_window(	(unsigned short)HStartOffset,
										(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HStartOffset ,
										(unsigned short)VRatioOffset + VStartOffset,
										(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
		Hstart = HStartOffset;
		Vstart = VRatioOffset + VStartOffset;
		return;
	}
#if  1
	StructSrcRect m_dispwin = Scaler_DispWindowGet();
	HRatioOffset =  m_dispwin.srcx;
	VRatioOffset = m_dispwin.srcy;
	scalerdisplay_set_main_act_window(
			(unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset,
			(unsigned short)Get_DISP_ACT_STA_HPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HRatioOffset + HStartOffset ,
			(unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset,
			(unsigned short)Get_DISP_ACT_STA_VPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
		///}
		Hstart = (unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset;
		Vstart = (unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset;
	return;
#else
	//frank@0429 add for custom display window
	if((ratio_type == SLR_RATIO_CUSTOM) ||(ratio_type == SLR_ASPECT_RATIO_SOURCE)){
		StructSrcRect m_dispwin = Scaler_DispWindowGet();
		HRatioOffset =  m_dispwin.srcx;
		VRatioOffset = m_dispwin.srcy;
		scalerdisplay_set_main_act_window(
				(unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset,
				(unsigned short)Get_DISP_ACT_STA_HPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HRatioOffset + HStartOffset ,
				(unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset,
				(unsigned short)Get_DISP_ACT_STA_VPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
			///}
			Hstart = (unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset;
			Vstart = (unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset;
		return;
	}
	if(ratio_type == SLR_RATIO_SOURCE_CUSTOM){
			StructSrcRect m_dispwin = Scaler_DispWindowGet_source();
			HRatioOffset =	m_dispwin.srcx;
			VRatioOffset = m_dispwin.srcy;
			scalerdisplay_set_main_act_window(
					(unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset,
					(unsigned short)Get_DISP_ACT_STA_HPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HRatioOffset + HStartOffset ,
					(unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset,
					(unsigned short)Get_DISP_ACT_STA_VPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
				///}
				Hstart = (unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset;
				Vstart = (unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset;
			return;
		}


	if ( Get_DISPLAY_RATIO_4X3() == 1 ) { // 4:3 panel
		///{ hsliao 20090313, for best buy
		if ( (ratio_type==SLR_RATIO_BBY_NORMAL)||(ratio_type==SLR_RATIO_BBY_ZOOM)) {
			// calculate offset
			if ( Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO) ) { // 4:3 content
				HRatioOffset = VRatioOffset = 0;
			} else { // 16:9 content
				if ( ratio_type == SLR_RATIO_BBY_NORMAL ) { // normal
					/*if ( Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) ) { // frame sync
						HRatioOffset = VRatioOffset = 0; // use full screen
					} else {*/ // FRC
						HRatioOffset = 0;
						VRatioOffset = SHR(_DISP_LEN-Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN),1);
					//}
				} else if ( ratio_type == SLR_RATIO_BBY_ZOOM ) { // zoom
					HRatioOffset = VRatioOffset = 0;
				}
			}
			// active window
			scalerdisplay_set_main_act_window(
				HRatioOffset + HStartOffset,
				Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HRatioOffset + HStartOffset,
				VRatioOffset + VStartOffset,
				Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
			Hstart = HRatioOffset + HStartOffset;
			Vstart = VRatioOffset + VStartOffset;
		} else {
		///}
			if (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE) { // FRC
				if ( ratio_type == SLR_RATIO_16_9 ) {  //16 : 9 ratio
					VRatioOffset = (unsigned short)SHR(_DISP_LEN, 3); // offset at vertical direction
					scalerdisplay_set_main_act_window(
						(unsigned short)HStartOffset,
						(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HStartOffset,
						(unsigned short)VRatioOffset + VStartOffset,
						(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
					Hstart = HStartOffset;
					Vstart = VRatioOffset + VStartOffset;
				} else if ( ratio_type == SLR_RATIO_POINTTOPOINT ) {
					scalerdisplay_set_main_act_window(
						(unsigned short) HRatioOffset + HStartOffset ,
						(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HRatioOffset + HStartOffset,
						(unsigned short)VRatioOffset + VStartOffset,
						(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
					Hstart = HRatioOffset + HStartOffset;
					Vstart = VRatioOffset + VStartOffset;
				} else {
					VRatioOffset = 0; // offset at vertical direction, zero at this case
					scalerdisplay_set_main_act_window(
						(unsigned short)HStartOffset,
						(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HStartOffset ,
						(unsigned short)VRatioOffset + VStartOffset,
						(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
					Hstart = HStartOffset;
					Vstart = VRatioOffset + VStartOffset;
				}
			} else { // Frame sync, 4 : 3 ratio
				VRatioOffset = 0; // offset at vertical direction, zero at this case
				scalerdisplay_set_main_act_window(
					(unsigned short)HStartOffset,
					(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HStartOffset ,
					(unsigned short)VRatioOffset + VStartOffset,
					(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
				Hstart = HStartOffset;
				Vstart = VRatioOffset + VStartOffset;
			}
		}
	} else { // 16:9 panel
		///{ hsliao 20090313, ratio offset of best buy
		unsigned short dispWid_16_9 = (unsigned short)((unsigned int)_DISP_LEN*16/9);
		unsigned short dispWid_16_10 = (unsigned short)((unsigned int)_DISP_LEN*16/10);
		if ( ABS(_DISP_WID,dispWid_16_9) < ABS(_DISP_WID,dispWid_16_10) ) { // 16:9 panel
			switch ( ratio_type )
			{
			case SLR_RATIO_BBY_NORMAL:
				HRatioOffset = SHR(_DISP_WID,3);
				VRatioOffset = 0;
				break;
			case SLR_RATIO_POINTTOPOINT:
				//do nothing
				break;
			case SLR_RATIO_ZOOM_14_9:
				HRatioOffset = SHR(_DISP_WID,4);
				VRatioOffset = 0;
				break;
                        case SLR_RATIO_15_9:
				HRatioOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;

			case SLR_RATIO_5_4:
				HRatioOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;

			case SLR_RATIO_85_48:
				//HStartOffset = 3;
				HStartOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;

			case SLR_RATIO_16_10:
				HRatioOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;
			case SLR_RATIO_BBY_WIDE_1:
			case SLR_RATIO_BBY_WIDE_2:
			case SLR_RATIO_BBY_ZOOM:
			case SLR_RATIO_BBY_CINEMA:
			default:
				HRatioOffset = VRatioOffset = 0;
				break;
#ifdef CONFIG_DTV_AFD_CONTROL
			case SLR_RATIO_BBY_AUTO:
				// afd
				if(Scaler_InputSrcGetMainChType()==_SRC_VO){
					switch(Scaler_DispGetInputInfo(SLR_INPUT_AFD)){
						case SLR_AFD_SAME_AS_FRAME:
						default:
							/*if (Scaler_InputSrcGetMainFormat() == TVD_INFMT_VODMA0)
								{ //dtv
								if(Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO)==SLR_SOURCERATIO_4X3)
									{
								HRatioOffset = SHR(_DISP_WID,3);
								VRatioOffset = 0;
							}
								}
							else
							{*/
								if((_DISP_WID == Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID)) && (_DISP_LEN != Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN))){//change height
									VRatioOffset = (_DISP_LEN-Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN))/2;
									HRatioOffset = 0;
								}else if((_DISP_WID != Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID)) && (_DISP_LEN == Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN))){//change width
									HRatioOffset = (_DISP_WID-Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID))/2;
									VRatioOffset = 0;
								}else{//not change width & height
									HRatioOffset = 0;
									VRatioOffset = 0;
								}
							//}
							break;
						case SLR_AFD_4X3:
							HRatioOffset = SHR(_DISP_WID,3);
							VRatioOffset = 0;
							break;
						case SLR_AFD_14X9:
							//if(Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO)==SLR_SOURCERATIO_4X3){
								HRatioOffset = SHR(_DISP_WID,4);
								VRatioOffset = 0;
							//}
							break;
						case SLR_AFD_4X3_SP:
							HRatioOffset = SHR(_DISP_WID,4);
							VRatioOffset = 0;
							break;
						case SLR_AFD_16X9:
						case SLR_AFD_16X9_SP:
						case SLR_AFD_16X9_SP_4X3:
							HRatioOffset = VRatioOffset = 0;
							break;
					}
				}
				break;
#endif

			}
		} else { // 16:10 panel
			switch ( ratio_type )
			{
			case SLR_RATIO_BBY_NORMAL:
				HRatioOffset = SHR(_DISP_WID-Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID),1);
				VRatioOffset = 0;
				break;
			case SLR_RATIO_POINTTOPOINT:
				//do nothing
				break;
			case SLR_RATIO_BBY_WIDE_2:
			/*	if ( Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) ) { // If frame sync, aspect ratio is done in VO.
					HRatioOffset = VRatioOffset = 0;
				} else {*/
					HRatioOffset = 0;
					VRatioOffset = SHR(_DISP_LEN-Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN),1);
				//}
				break;
			case SLR_RATIO_ZOOM_14_9:
				HRatioOffset = SHR(_DISP_WID,4);
				VRatioOffset = 0;
				break;

			case SLR_RATIO_15_9:
				HRatioOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;

			case SLR_RATIO_5_4:
				HRatioOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;

			case SLR_RATIO_85_48:
				//HStartOffset = 3;
				HStartOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;

			case SLR_RATIO_16_10:
				HRatioOffset = 0;
				VRatioOffset = SHR(_DISP_WID - Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), 1);
			break;

			case SLR_RATIO_BBY_WIDE_1:
			case SLR_RATIO_BBY_ZOOM:
			case SLR_RATIO_BBY_CINEMA:
			default:
				HRatioOffset = VRatioOffset = 0;
				break;
			}
		}
		///}
		if ( ratio_type == SLR_RATIO_4_3 ) { // 4 : 3 ratio
			VRatioOffset = (unsigned short)SHR(_DISP_WID , 3); // offset at horizontal direction
			scalerdisplay_set_main_act_window(
				(unsigned short)Get_DISP_ACT_STA_HPOS() + VRatioOffset + HStartOffset,
				(unsigned short)Get_DISP_ACT_STA_HPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + VRatioOffset + HStartOffset ,
				(unsigned short)Get_DISP_ACT_STA_VPOS()  + VStartOffset,
				(unsigned short)Get_DISP_ACT_STA_VPOS()  + Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VStartOffset );
			Hstart = (unsigned short)Get_DISP_ACT_STA_HPOS() + VRatioOffset + HStartOffset;
			Vstart = (unsigned short)Get_DISP_ACT_STA_VPOS()  + VStartOffset;
		} else if (( ratio_type == SLR_RATIO_15_9 ) || ( ratio_type == SLR_RATIO_5_4 ) || ( ratio_type == SLR_RATIO_85_48 ) || ( ratio_type == SLR_RATIO_16_10 )) {
			scalerdisplay_set_main_act_window(
				(unsigned short)Get_DISP_ACT_STA_HPOS() + VRatioOffset + HStartOffset,
				(unsigned short)Get_DISP_ACT_STA_HPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + VRatioOffset + HStartOffset ,
				(unsigned short)Get_DISP_ACT_STA_VPOS()  + VStartOffset,
				(unsigned short)Get_DISP_ACT_STA_VPOS()  + Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VStartOffset );
			Hstart = (unsigned short)Get_DISP_ACT_STA_HPOS() + VRatioOffset + HStartOffset;
			Vstart = (unsigned short)Get_DISP_ACT_STA_VPOS()  + VStartOffset;
		} else if ( ratio_type == SLR_RATIO_POINTTOPOINT ) {
			scalerdisplay_set_main_act_window(
				(unsigned short) HRatioOffset + HStartOffset ,
				(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HRatioOffset + HStartOffset ,
				(unsigned short)VRatioOffset + VStartOffset,
				(unsigned short)Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
			Hstart = HRatioOffset + HStartOffset;
			Vstart = VRatioOffset + VStartOffset;
		} else { // original or BBY
			///{ modified by hsliao 20090313
#ifdef CONFIG_DTV_AFD_CONTROL
		if( !(ratio_type == SLR_RATIO_BBY_AUTO && (Scaler_InputSrcGetMainChType()==_SRC_VO||Scaler_InputSrcGetMainChType()==_SRC_CVBS)) )
#endif
//			if (!((ratio_type>=SLR_RATIO_BBY_NORMAL)&&(ratio_type<=SLR_RATIO_BBY_CINEMA)&&!(ratio_type == SLR_RATIO_ZOOM_14_9))) {

		if(ratio_type != SLR_RATIO_ZOOM_14_9)	//yenwen 20120511
		{

			if (!((ratio_type>=SLR_RATIO_BBY_NORMAL)&&(ratio_type<=SLR_RATIO_BBY_CINEMA)))
			{
			}
		}

#if 0
printk(KERN_INFO "HRatioOffset=%d\n",HRatioOffset);
printk(KERN_INFO "HStartOffset=%d\n",HStartOffset);
printk(KERN_INFO "VRatioOffset=%d\n",VRatioOffset);
printk(KERN_INFO "VStartOffset=%d\n",VStartOffset);
printk(KERN_INFO "Get_DISP_ACT_STA_HPOS=%d\n",Get_DISP_ACT_STA_HPOS());
printk(KERN_INFO "SLR_INPUT_DISP_WID=%d\n",Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID));
printk(KERN_INFO "Get_DISP_ACT_STA_VPOS=%d\n",Get_DISP_ACT_STA_VPOS());
printk(KERN_INFO "SLR_INPUT_DISP_LEN=%d\n",Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN));
#endif //#if 0

			scalerdisplay_set_main_act_window(
				(unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset,
				(unsigned short)Get_DISP_ACT_STA_HPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID) + HRatioOffset + HStartOffset ,
				(unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset,
				(unsigned short)Get_DISP_ACT_STA_VPOS() + Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) + VRatioOffset + VStartOffset );
			///}
			Hstart = (unsigned short)Get_DISP_ACT_STA_HPOS() + HRatioOffset + HStartOffset;
			Vstart = (unsigned short)Get_DISP_ACT_STA_VPOS() + VRatioOffset + VStartOffset;
		}
	}
#endif
}

/*============================================================================*/
/**
 * scalerdisplay_set_main_display_window
 * This function is used to set the position of Main display and background window,
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
//static void __init  scalerdisplay_set_main_display_window(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta, unsigned short DispVEnd, unsigned char Border)
void scalerdisplay_set_main_display_window(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta, unsigned short DispVEnd, unsigned char Border)
{
	scalerdisplay_set_main_display_window_H(DispHSta, DispHEnd, Border);

	scalerdisplay_set_main_display_window_V(DispVSta, DispVEnd, Border);

/*
	DispHSta += Get_DISP_ACT_STA_BIOS();
	DispHEnd += Get_DISP_ACT_STA_BIOS();


	// Main display for H
	IoReg_Mask32(PPOVERLAY_MAIN_DEN_H_Start_End_reg, 0xf000f000, ((DispHSta & 0x0fff)  << 16) | (DispHEnd & 0x0fff));

	// Main display for V
	IoReg_Mask32(PPOVERLAY_MAIN_DEN_V_Start_End_reg, 0xf800f800, ((DispVSta & 0x07ff) << 16) | (DispVEnd & 0x07ff));

	// Main background display for H
	IoReg_Mask32(PPOVERLAY_MAIN_Background_H_Start_End_reg, 0xf000f000, (((DispHSta + Border) & 0x0fff) << 16) | ((DispHEnd - Border) & 0x0fff));

	// Main backupground display for V
	IoReg_Mask32(PPOVERLAY_MAIN_Background_V_Start_End_reg, 0xf800f800, (((DispVSta + Border) & 0x07ff) << 16) | ((DispVEnd - Border) & 0x07ff));


	drvif_scalerdisplay_set_dbuffer_en(FALSE);
*/
}

void scalerdisplay_set_main_display_window_H(unsigned short DispHSta, unsigned short DispHEnd, unsigned char Border)
{
	ppoverlay_main_den_h_start_end_RBUS main_den_h_start_end_reg;
	ppoverlay_main_background_h_start_end_RBUS main_background_h_start_end_reg;
	DispHSta += Get_DISP_ACT_STA_BIOS();
	DispHEnd += Get_DISP_ACT_STA_BIOS();

	main_den_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_DEN_H_Start_End_reg);
	main_background_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_H_Start_End_reg);
#ifdef CONFIG_MEMC_BYPASS
	main_den_h_start_end_reg.mh_den_sta = (DispHSta & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
	main_den_h_start_end_reg.mh_den_end = (DispHEnd & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
	main_background_h_start_end_reg.mh_bg_sta = ((DispHSta + Border) & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
	main_background_h_start_end_reg.mh_bg_end = ((DispHEnd - Border) & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
#else
	if(Get_MEMC_Enable_Dynamic() == 0){
		main_den_h_start_end_reg.mh_den_sta = (DispHSta & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
		main_den_h_start_end_reg.mh_den_end = (DispHEnd & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
		main_background_h_start_end_reg.mh_bg_sta = ((DispHSta + Border) & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
		main_background_h_start_end_reg.mh_bg_end = ((DispHEnd - Border) & 0x0FFF)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
	}else{
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"##### scalerdisplay_set_main_display_window_H : DispHEnd = %x\n", DispHEnd);
	main_den_h_start_end_reg.mh_den_sta = (DispHSta & 0x0FFF);
	main_den_h_start_end_reg.mh_den_end = DispHEnd & 0x0FFF;
	main_background_h_start_end_reg.mh_bg_sta = ((DispHSta + Border) & 0x0FFF);
	main_background_h_start_end_reg.mh_bg_end = ((DispHEnd - Border) & 0x0FFF);
	}
#endif

	fw_scaler_dtg_double_buffer_enable(1);
	IoReg_Write32(PPOVERLAY_MAIN_DEN_H_Start_End_reg, main_den_h_start_end_reg.regValue);
	IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, main_background_h_start_end_reg.regValue);
	fw_scaler_dtg_double_buffer_apply();
	//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);

/*
	// Main display for H
	IoReg_Mask32(PPOVERLAY_MAIN_DEN_H_Start_End_reg, 0xf000f000, ((DispHSta & 0x0fff)  << 16) | (DispHEnd & 0x0fff));

	// Main background display for H
	IoReg_Mask32(PPOVERLAY_MAIN_Background_H_Start_End_reg, 0xf000f000, (((DispHSta + Border) & 0x0fff) << 16) | ((DispHEnd - Border) & 0x0fff));
*/
	// #58980: fix video noise issue when VO 2D video(fps < 30Hz) change to 2Dcvt3D mode
	/*WaitFor_DEN_STOP();
	drvif_scalerdisplay_set_dbuffer_en(FALSE);*/
}

void scalerdisplay_set_main_display_window_V(unsigned short DispVSta, unsigned short DispVEnd, unsigned char Border)
{
	ppoverlay_main_den_v_start_end_RBUS main_den_v_start_end_reg;
	ppoverlay_main_background_v_start_end_RBUS main_background_v_start_end_reg;

	main_den_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_DEN_V_Start_End_reg);
	main_background_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);

	main_den_v_start_end_reg.mv_den_sta = DispVSta & 0x1FFF;
	main_den_v_start_end_reg.mv_den_end = DispVEnd & 0xFfFF;

	main_background_v_start_end_reg.mv_bg_sta = (DispVSta + Border) & 0x1FFF;
	main_background_v_start_end_reg.mv_bg_end = (DispVEnd - Border) & 0x1FFF;

	fw_scaler_dtg_double_buffer_enable(1);
	IoReg_Write32(PPOVERLAY_MAIN_DEN_V_Start_End_reg, main_den_v_start_end_reg.regValue);
	IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);
	fw_scaler_dtg_double_buffer_apply();
	//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);

/*
	// Main display for V
	IoReg_Mask32(PPOVERLAY_MAIN_DEN_V_Start_End_reg, 0xf800f800, ((DispVSta & 0x07ff) << 16) | (DispVEnd & 0x07ff));

	// Main backupground display for V
	IoReg_Mask32(PPOVERLAY_MAIN_Background_V_Start_End_reg, 0xf800f800, (((DispVSta + Border) & 0x07ff) << 16) | ((DispVEnd - Border) & 0x07ff));
*/
	// #58980: fix video noise issue when VO 2D video(fps < 30Hz) change to 2Dcvt3D mode
	/*WaitFor_DEN_STOP();
	drvif_scalerdisplay_set_dbuffer_en(FALSE);*/
}



/*============================================================================*/
/**
 * scalerdisplay_get_main_display_ori_size
 * Retrieve main window size, includes width and length.
 * Mostly, it will be the same as panel size, except 1C12B or 1L7B in sub display.
 *
 * @param <*DispWid> {pointer to DispWid}
 * @param <*DispLen> {pointer to DispLen}
 * @return { none }
 *
 */
static void scalerdisplay_get_main_display_ori_size(void)
{
#if 0  /* 1:if There are two channels*/

	unsigned short  TmpWid = 0;
	unsigned short  TmpLen = 0;

	PipMp_GetPipSize((eSubType)Scaler_PipGetInfo(SLR_PIP_TYPE), &TmpWid, &TmpLen);	// get a small window size
	switch(Scaler_PipGetInfo(SLR_PIP_TYPE)) {
		case SUBTYPE_MP1C12B:
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,(TmpWid << 1));
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,(TmpLen << 1));
			break;
		case SUBTYPE_MP1L7B:
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,(TmpWid * 3));
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,(TmpLen*3));
			break;
		case SUBTYPE_PIPMLSR:
		case SUBTYPE_PIPMLSR_4x3:
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,TmpWid);
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,TmpLen);
			if(TmpWid & _BIT0)
				Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,TmpWid+1);
			break;
		case SUBTYPE_MP4X4:
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,_DISP_WID);
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,TmpLen<<2);
			break;
		default:
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,_DISP_WID);
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,_DISP_LEN);
			break;
	}
#else
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,_DISP_WID);
	Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,_DISP_LEN);
#endif
	}

//USER:LewisLee DATE:2012/11/23
//to prevent front porch too small
void drvif_scalerdisplay_panel_porch_protect(void)
{
#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;

	dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);

	if((dv_den_start_end_reg.dv_den_sta > Get_DISP_DEN_STA_VPOS())
		||(dv_den_start_end_reg.dv_den_end > Get_DISP_DEN_END_VPOS()))
	{
		dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
		dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
		IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Enter Panel Porch Protect!\n");
	}
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT
}

/*============================================================================*/
/**
 * drvif_scalerdisplay_init
 * Init display control module. Collect the register, which should be insert only once.
 *
 * @param  { none }
 * @return { none }
 *
 */
//void __init drvif_scalerdisplay_init(void)

void drvif_scalerdisplay_init(void)
{
//#ifdef ENABLE_MEMC_CONTROL
//	drv_frd_Init();	//sharp_MEMC
//#endif

#ifdef CONFIG_PCBMGR
	unsigned long long panel_en=0, backlight_en=0, value=0;
	if ((pcb_mgr_get_enum_info_byname("PIN_LVDS_ON_OFF", &value) < 0) || (value == 0)) {
		panel_en = 0;
		//assert(0);
	} else {
		panel_en = value;
	}

	if ((pcb_mgr_get_enum_info_byname("PIN_BL_ON_OFF", &value) < 0) || (value == 0)) {
		backlight_en = 0;
		//assert(0);
	} else {
		backlight_en = value;
	}
#endif // #ifdef CONFIG_PCBMGR

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"DispInit, type/idx/3D=%d/%d/%d[PR/SG=%d/%d]\n", Get_DISPLAY_PANEL_TYPE(), Get_DISPLAY_PANEL_CUSTOM_INDEX(),
		Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE(), Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE(), Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE());
#if 0 //frank@1230 mark
#if !defined(ENABLE_AP_INIT_PANEL)
	if (IoReg_Read32(0xb806012c)==0x23796666)
		isWDGmode = TRUE;
#endif
#endif

#if 0  //[mark for base driver by qing_liu]
	if(Get_PANEL_TYPE_IS_USED_TCON_CONTROL() == 1){
		Panel_TconControl_Init();
		Panel_TconControl_Decide_Dynamic_Mode_Table();
	}
#endif


#ifdef OPEN_CELL_PANEL
  #ifndef ENABLE_AP_INIT_PANEL
  #else
	{
	Scaler_ForceBg(SLR_MAIN_DISPLAY, SLR_FORCE_BG_SYSTEM, _ENABLE);
	Panel_Tcon_Init();
	}
  #endif

#else // #ifdef OPEN_CELL_PANEL //LVDS OUTPUT
  #ifndef ENABLE_AP_INIT_PANEL
  #else
	{
  #ifndef VBY_ONE_PANEL //move to bootcode
		//---------- SFG ------------------------------------------------------------------
		sfg_sfg_zz_shift_dbg_ctrl_RBUS sfg_zz_shift_dbg_ctrl_reg;
		sfg_sfg_swap_ctrl0_RBUS sfg_swap_ctrl0_reg;
		sfg_sfg_swap_ctrl1_RBUS sfg_swap_ctrl1_reg;
		sfg_sfg_ctrl_0_RBUS    sfg_ctrl_0_reg;
		sfg_sfg_ctrl_a_RBUS    sfg_ctrl_a_reg;
		sfg_sfg_ctrl_9_RBUS    sfg_ctrl_9_reg;
		sfg_sfg_ctrl_8_RBUS    sfg_ctrl_8_reg;
		sfg_sfg_ctrl_7_RBUS    sfg_ctrl_7_reg;
		sfg_sfg_ctrl_6_RBUS    sfg_ctrl_6_reg;

		sfg_zz_shift_dbg_ctrl_reg.regValue = IoReg_Read32(SFG_SFG_ZZ_shift_dbg_CTRL_reg);
		sfg_zz_shift_dbg_ctrl_reg.dout_mode = Get_DISPLAY_COLOR_BITS();
		sfg_zz_shift_dbg_ctrl_reg.sfg_dout_en  = 1;
		sfg_zz_shift_dbg_ctrl_reg.dvs_inv = 0;
		sfg_zz_shift_dbg_ctrl_reg.dhs_inv = 0;
		sfg_zz_shift_dbg_ctrl_reg.dden_inv = 0;
		sfg_zz_shift_dbg_ctrl_reg.daclk_inv = 1;
		sfg_zz_shift_dbg_ctrl_reg.daclk_en = 1;
		sfg_zz_shift_dbg_ctrl_reg.dout_rb_swap = Get_DISPLAY_RED_BLUE_SWAP();
		sfg_zz_shift_dbg_ctrl_reg.dout_bit_swap =  Get_DISPLAY_MSB_LSB_SWAP();
		sfg_zz_shift_dbg_ctrl_reg.dout_data_inv = Get_DISPLAY_OUTPUT_INVERSE();
		//sfg_zz_shift_dbg_ctrl_reg.dclk_dly_sel = Get_DISPLAY_CLOCK_DELAY();
		IoReg_Write32(SFG_SFG_ZZ_shift_dbg_CTRL_reg, sfg_zz_shift_dbg_ctrl_reg.regValue);

		sfg_swap_ctrl0_reg.regValue = IoReg_Read32(SFG_SFG_SWAP_CTRL0_reg);
		sfg_swap_ctrl0_reg.dclk_mode_switch = Get_DISPLAY_PORT();
		IoReg_Write32(SFG_SFG_SWAP_CTRL0_reg, sfg_swap_ctrl0_reg.regValue);

		if(Get_DISPLAY_PORT_CONFIG1()){
			sfg_swap_ctrl1_reg.regValue = Get_DISPLAY_PORT_CONFIG1();
//			sfg_swap_ctrl2_reg.regValue= Get_DISPLAY_PORT_CONFIG2();

			IoReg_Write32(SFG_SFG_SWAP_CTRL1_reg, sfg_swap_ctrl1_reg.regValue);
//			IoReg_Write32(SFG_SFG_SWAP_CTRL2_VADDR, sfg_swap_ctrl2_reg.regValue);
		}else{
			sfg_swap_ctrl1_reg.regValue = IoReg_Read32(SFG_SFG_SWAP_CTRL1_reg);
			sfg_swap_ctrl1_reg.output_porta = Get_DISPLAY_PORTAB_SWAP()?1:0;
			sfg_swap_ctrl1_reg.output_portb = Get_DISPLAY_PORTAB_SWAP()?0:1;
			//sfg_swap_ctrl1_reg.output_portc = Get_DISPLAY_PORTAB_SWAP()?0:1;
			IoReg_Write32(SFG_SFG_SWAP_CTRL1_reg, sfg_swap_ctrl1_reg.regValue);
//			IoReg_Write32(SFG_SFG_SWAP_CTRL2_VADDR, 0);
		}

		sfg_ctrl_0_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_0_reg);
		if(Get_DISPLAY_PORT() == 2){   // port 4
			sfg_ctrl_0_reg.port_num = 3;
		}else{ //port 1,2
			sfg_ctrl_0_reg.port_num = Get_DISPLAY_PORT();
		}
		sfg_ctrl_0_reg.seg_num = 0;
		IoReg_Write32(SFG_SFG_CTRL_1_reg, 0);
		IoReg_Write32(SFG_SFG_CTRL_2_reg, 0);
		IoReg_Write32(SFG_SFG_CTRL_3_reg, 0);
		IoReg_Write32(SFG_SFG_CTRL_4_reg, 0);

		sfg_ctrl_6_reg.regValue = 0;

		IoReg_Write32(SFG_SFG_CTRL_0_reg, sfg_ctrl_0_reg.regValue);

		sfg_ctrl_a_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_A_reg);
		sfg_ctrl_9_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_9_reg);
		sfg_ctrl_8_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_8_reg);
		sfg_ctrl_7_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_7_reg);
		sfg_ctrl_a_reg.final_line_length = _DISP_WID;
		//sfg_ctrl_a_reg.hsync_threshold = 0;
		sfg_ctrl_9_reg.sfg_dh_den_sta = Get_DISP_DEN_STA_HPOS();
		sfg_ctrl_9_reg.req_start = Get_DISP_DEN_STA_HPOS()-6;
		sfg_ctrl_8_reg.vsync_start = 0;
		sfg_ctrl_8_reg.vsync_end = Get_DISP_VSYNC_LENGTH();
		sfg_ctrl_7_reg.hsync_width = Get_DISP_HSYNC_WIDTH()-1;
		sfg_ctrl_7_reg.hsync_delay = Get_DISP_HORIZONTAL_TOTAL()-13;
		IoReg_Write32(SFG_SFG_CTRL_A_reg, sfg_ctrl_a_reg.regValue);
		IoReg_Write32(SFG_SFG_CTRL_9_reg, sfg_ctrl_9_reg.regValue);
		IoReg_Write32(SFG_SFG_CTRL_8_reg, sfg_ctrl_8_reg.regValue);
		IoReg_Write32(SFG_SFG_CTRL_7_reg, sfg_ctrl_7_reg.regValue);
		IoReg_Write32(SFG_SFG_CTRL_6_reg, sfg_ctrl_6_reg.regValue );//Disable ByPass Mode
		//---------- PIF ------------------------------------------------------------------

		IoReg_Write32(PIF_LVDS_CTRL0_reg, 0);

		if(((Get_DISPLAY_PANEL_TYPE() != P_LVDS_4K_2K_BOOTCODE_2K) &&(Get_DISPLAY_PANEL_TYPE() != P_LVDS_4K_2K_BOOTCODE_4K))
			|| (Get_DISPLAY_PANEL_CUSTOM_INDEX() != P_PA168_AU_55)){
			lvds_ctrl3_RBUS  lvds_ctrl3;

//			if(Get_DISPLAY_PORT() == 2){
				lvds_ctrl3.regValue = IoReg_Read32(PIF_LVDS_CTRL3_reg);
			    lvds_ctrl3.lvds_pn_swap = 0;
				lvds_ctrl3.lvds_map_inv = 1;//frank@0114 sync sirius register script
				lvds_ctrl3.lvds_map = Get_DISPLAY_BITMAPPING_TABLE()?1:0;//-1;

				if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX){
					// don't open by request
				}else{
					lvds_ctrl3.lvds_aport_en = 1;
					lvds_ctrl3.lvds_bport_en = 1;
				}

//				lvds_ctrl3.lvds_cport_en = 1;
//				lvds_ctrl3.lvds_dport_en = 1;

				IoReg_Write32(PIF_LVDS_CTRL3_reg, lvds_ctrl3.regValue);
		//	}

			#if defined(LVDS_PN_SWAP)
				#if LVDS_PN_SWAP
					lvds_ctrl3.lvds_pn_swap = 1;
					IoReg_Write32(PIF_LVDS_CTRL3_reg, lvds_ctrl3.regValue);
				#endif
			#endif
		}

		//---------- LVDS pin share ------------------------------------------------------------------

		IoReg_Write32(0xb80008B8, 0x00000000);	// LVDS A-Port F/G/H Pair PinShare
		IoReg_Write32(0xb80008BC, 0x00000000);	// LVDS A-Port C/D/E Pair PinShare
		IoReg_Write32(0xb80008C0, 0x00000000);	// LVDS A-Port A/B, LVDS B-Port G Pair PinShare
		IoReg_Write32(0xb80008C4, 0x00000000);	// LVDS B-Port D/E/F Pair PinShare
		IoReg_Write32(0xb80008C8, 0x00000000);	// LVDS B-Port A/B/C Pair PinShare

		//---------- LVDS/mini-LVDS/EPI/VBy1 TXPHY ----------------------------------------------------------

		IoReg_Write32(0xb8000C00, 0x03001810);	// PI_A1 = Phase0, PI_A2 = Phase0, CK7X = 1X Current, PI_Clock = 300~600MHz,
		IoReg_Write32(0xb8000C04, 0x03001810);	// PI_B1 = Phase0, PI_B2 = Phase0, CK7X = 1X Current, PI_Clock = 300~600MHz,
		IoReg_Write32(0xb8000C08, 0x03040000);	// PI_AB = Phase0, CK7X = 1X Current, CK5X Duty Adjust Disable, PI_Clock = 300~600MHz,
		IoReg_Write32(0xb8000C0C, 0x04153700);	// Choose legacy charge-pump, DIV248 = 2, VCO = 74.25*7*DIV248 = 1.0395GHz,
							// Small Kvco, CK1X Not Inverse, PLL_VCO = 2V,
							// Icp = 12.5uA, Cp = 9.5pF, Rs = 12Kohm,
							// PI_A Disble, PI_B Disable ==> PI_AB Disble
		IoReg_Write32(0xb8000C10, 0x90040000);	// P0 A-Pair LVDS, Use PI_A1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C14, 0x90040000);	// P0 B-Pair LVDS, Use PI_A1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C18, 0x90040000);	// P0 C-Pair LVDS, Use PI_A1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C1C, 0x91040000);	// P0 D-Pair LVDS, Use PI_A2, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C20, 0x90040000);	// P0 E-Pair LVDS, Use PI_A1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C24, 0x90040000);	// P0 F-Pair LVDS, Use PI_A1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C28, 0x90040000);	// P0 G-Pair LVDS, Use PI_A1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C2C, 0x90040000);	// P0 H-Pair LVDS, Use PI_A1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C30, 0x00000000);	// P0 Not Adjudt CK7X Delay, CK7X Not Inverse, PI Not Lag 0.5UI,
							// P0 Double Driving disable,
		IoReg_Write32(0xb8000C34, 0x90040000);	// P1 A-Pair LVDS, Use PI_B1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C38, 0x90040000);	// P1 B-Pair LVDS, Use PI_B1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C3C, 0x90040000);	// P1 C-Pair LVDS, Use PI_B1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C40, 0x91040000);	// P1 D-Pair LVDS, Use PI_B2, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C44, 0x90040000);	// P1 E-Pair LVDS, Use PI_B1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C48, 0x90040000);	// P1 F-Pair LVDS, Use PI_B1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C4C, 0x90040000);	// P1 G-Pair LVDS, Use PI_B1, SR Disable, internal resistor 100ohm,
		IoReg_Write32(0xb8000C50, 0x00000000);	// P1 Not Adjudt CK7X Delay, CK7X Not Inverse, PI Not Lag 0.5UI,
							// P1 Double Driving disable,
		IoReg_Write32(0xb8000C54, 0x09ECD000);	// ISOURCE = IBHX, Select LVDS/mLVDS/EPI TXPHY,
							// LDO_CML Enable & 2V, LDO_DPLL/LVDSPLL Enable & 1.05V,
							// Swing = 4mA. VCM = 1.25V,
		IoReg_Write32(0xb8000C58, 0x00000000);	// P0 Pre-emphasis disable, internal resistor disable, TTL 2mA,
							// P0 Not Adjudt CK1X Delay, CML 1.2mA (PLL<1.2GHz),
		IoReg_Write32(0xb8000C5C, 0x00000000);	// P0 CMOS Mode, SR 1-buffer delay,
		IoReg_Write32(0xb8000C60, 0x00000000);	// P1 Pre-emphasis disable, internal resistor disable, TTL 2mA,
							// P1 Not Adjudt CK1X Delay, CML 1.2mA (PLL<1.2GHz),
		IoReg_Write32(0xb8000C64, 0x00000000);	// P1 CMOS Mode, SR 1-buffer delay,
		IoReg_Write32(0xb8000C78, 0xFFFF0000);	// Lane Power Enable for non-Vby1-Mode

  #endif // #ifndef VBY_ONE_PANEL //move to bootcode

  #ifdef CONFIG_PCBMGR
		IO_Set(panel_en, 1);
  #else
//		IoReg_Mask32(0xb8061100, 0xff0f0fff,0x00404000);
//		IoReg_Mask32(0xb8061108, 0xffff0fff,0x00004000);
  #endif
	}
#endif

//	Scaler_ForceBg(SLR_MAIN_DISPLAY, SLR_FORCE_BG_SYSTEM, _ENABLE);
  #ifndef VBY_ONE_PANEL
    #ifndef ENABLE_AP_INIT_PANEL
	#else
	{
		CreateDisplayTimingTable();

		//Init Display setting for no signal when boot
		scalerdisplay_set_main_display_window(0, _DISP_WID, 0, _DISP_LEN, 0);
	}
	#endif
  #endif // #ifndef VBY_ONE_PANEL
#endif //#ifdef OPEN_CELL_PANEL

	drvif_scalerdisplay_panel_porch_protect();

	#ifdef FIX_DATA_SHIFT_2BITS //for RSDS Color error to reserve color MSB 2bit HPWang
	fwif_color_setgamma(SLR_MAIN_DISPLAY, 1);
	#endif


#ifndef ENABLE_AP_INIT_PANEL

#else
	{
		//IoReg_Write32(0xb8028100, 0x00008d01);  //enable main display, must remove after bring up 	//this show color ramdom bar
		// PA168 panel init: LVDS input format (0: 10Bit, 1: 8bit, VESA for Darwin)
	#if 0
		if(((Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_2K) || (Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_4K))
			&& (Get_DISPLAY_PANEL_CUSTOM_INDEX() == P_PA168_AU_55))
			scaler_PixelWorks_PA168_set_LvdsInutFmt(Get_DISPLAY_COLOR_BITS()? LVDS_FMT_8BIT_VESA: LVDS_FMT_10BIT_VESA);
	#endif
#ifdef CONFIG_PCBMGR
		IO_Set(backlight_en, 1);
#endif
	}
#endif

	if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX)
	 	drvif_scaler_tvbox_display_init();
#if 0
	if(((Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_2K) ||(Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_4K))
		&& (Get_DISPLAY_PANEL_CUSTOM_INDEX() == P_PA168_AU_55))
		scaler_PixelWorks_PA168_lvdsDisable(_DISABLE); // enable LVDS signal since d-clock is stable

#endif
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Initial Display is completed. \n");
//FIX ME frank@1230 mark strange code
//	IoReg_Write32(0xb806012c, 0xABCD2379);	//let bootcode to know, AP scalerDisplay has inited.

}
#if 0
static void WaitFor_DEN_STOP2(void)
{
	#if 1
	UINT32 timeoutcnt = 0x032500;
	UINT32 real_line = 0;
	UINT32 denEnd = (IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg)&0xfff);
	do {
			real_line = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
			if((real_line > (denEnd+5)) &&(real_line < (denEnd+15)) ) {
				return;
			}
	} while(timeoutcnt-- != 0);

	if(timeoutcnt == 0){
		printk(KERN_INFO "\n ERROR not wait the correct line \n");
		fwif_scaler_wait_for_event(PPOVERLAY_DTG_pending_status_reg, _BIT0);
	}

	#else
	fwif_scaler_wait_for_event(PPOVERLAY_DTG_pending_status_reg, _BIT0);
	#endif
}
#endif
/*============================================================================*/
/**
 * scalerdisplay_set_timing
 * This function is used to set display timing
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
#if 0
static void scalerdisplay_set_timing(void)
{
	//   Last line will be used only in FrameSync mode
	//	if we don't marked these lines, sometimes it will get the
	//   wrong line number & the display of YPbPr in Sub will
	//	become ugly.

	// Set Display Horizontal Sync Width
	IoReg_Mask32(PPOVERLAY_DH_Width_reg, 0xffffff00, (Get_DISP_HSYNC_WIDTH() & 0x000000ff));

	// Set display horizantal total
	IoReg_Mask32(PPOVERLAY_DH_Total_Last_Line_Length_reg, 0xf000f000, (((Get_DISP_HORIZONTAL_TOTAL() - 1) & 0x0fff) << 16) | ((Get_DISP_HSYNC_LASTLINE() - 1) & 0x0fff));

	// Set display V-sync length
	IoReg_Mask32(PPOVERLAY_DV_Length_reg, 0xffffff00, (Get_DISP_VSYNC_LENGTH() & 0x000000ff));

	IoReg_Mask32(PPOVERLAY_DV_total_reg, 0xfffff000, ((Get_DISP_VERTICAL_TOTAL() - 1) & 0x00000fff));
}
#else //#if 0
//USER:LewisLee DATE:2010/08/12
//when we set display ration
//don't change DV total and last lint
void scalerdisplay_set_timing(void)
{
//   Last line will be used only in FrameSync mode
//	if we don't marked these lines, sometimes it will get the
//   wrong line number & the display of YPbPr in Sub will
//	become ugly.
	//This API is not used. confrim with Ben Wang
#if 0
	ppoverlay_dh_width_RBUS dh_width_reg;
	ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	ppoverlay_dv_length_RBUS dv_length_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;
//	dv_den_start_end_RBUS dv_den_start_end_reg;
	unsigned int tmp;
//#ifdef VBY_ONE_PANEL
	//return;
//#endif

	// Set Display Horizontal Sync Width
	dh_width_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Width_reg);
	dh_width_reg.dh_width = Get_DISP_HSYNC_WIDTH()&0xff;
	IoReg_Write32(PPOVERLAY_DH_Width_reg, dh_width_reg.regValue);
	#if 0  //[mark for base driver by qing_liu]
	if(((_TRUE == Scaler_Get_DisplayRatio_Change_Flag()) || (_TRUE == Scaler_Get_3D_Change_Flag())))
	{
//		ROS_ENTER_CRITICAL();
		// Set display horizantal total
//		WaitFor_DEN_STOP();  //if letterbox & framesync mode , dclk > pannel, we must tune DEN_STA_HPOS during the porch
		dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
		dh_den_start_end_reg.dh_den_sta = Get_DISP_DEN_STA_HPOS() & 0x1fff;
		dh_den_start_end_reg.dh_den_end = Get_DISP_DEN_END_HPOS() & 0x1fff;
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, dh_den_start_end_reg.regValue);
//		ROS_EXIT_CRITICAL();
	}
	else //if(_FALSE == displayratio_change)
	#endif
	{
		//frank@0618 enable D domain double buffer register
		IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
//		ROS_ENTER_CRITICAL();
		// Set display horizantal total
//		WaitFor_DEN_STOP();  //if letterbox & framesync mode , dclk > pannel, we must tune DEN_STA_HPOS during the porch
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1) & 0x1fff;
		dh_total_last_line_length_reg.dh_total_last_line = (Get_DISP_HSYNC_LASTLINE() - 1) & 0x1fff;

		//frank@0618 mark below code to speed up and change by d domain double buffer register method
		//WaitFor_DEN_STOP2();

		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);

		dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
#ifdef CONFIG_MEMC_BYPASS
		dh_den_start_end_reg.dh_den_sta = (Get_DISP_DEN_STA_HPOS() & 0x1fff)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
		dh_den_start_end_reg.dh_den_end = (Get_DISP_DEN_END_HPOS() & 0x1fff)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
#else
		if(Get_MEMC_Enable_Dynamic() == 0){
			dh_den_start_end_reg.dh_den_sta = (Get_DISP_DEN_STA_HPOS() & 0x1fff)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
			dh_den_start_end_reg.dh_den_end = (Get_DISP_DEN_END_HPOS() & 0x1fff)/(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) +1);
		}else{
		dh_den_start_end_reg.dh_den_sta = (Get_DISP_DEN_STA_HPOS() & 0x1fff);
		dh_den_start_end_reg.dh_den_end = (Get_DISP_DEN_END_HPOS() & 0x1fff);
		}
#endif
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, dh_den_start_end_reg.regValue);

		// Set display V-sync length
		dv_length_reg.regValue = IoReg_Read32(PPOVERLAY_DV_Length_reg);
		dv_length_reg.dv_length = Get_DISP_VSYNC_LENGTH() & 0xff;
		IoReg_Write32(PPOVERLAY_DV_Length_reg, dv_length_reg.regValue);

		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1) & 0x00001fff;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		if(_ENABLE == Scaler_Get_Dynamic_Adjust_Display_DenVPos_Flag())
		{
			Scaler_Set_Dynamic_Adjust_Display_DenVPos_Start(0);
			Scaler_Set_Dynamic_Adjust_Display_DenVPos_End(0);

			dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
			dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
			dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
			IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);
		}
#endif //#ifdef CONFIG_ENABLE_PANEL_DISPLAY_PORCH_PROTECT_BY_ADJUST_DENVPOS
		//frank@0618 apply D domain double buffer register
		IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);
		tmp = 0;
		while(IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0){
			msleep(2);
			if(++tmp>30)
				break;
		}
		IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
	}
#endif
}
#endif //#if 0

//USER:LewisLee DATE:2012/10/22
//fix FLL mode, DV total over range, let Vfreq change
void scalerdisplay_set_dh_total(UINT8 ucFLL_Mode)
{
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL
	if(_TRUE == ucFLL_Mode)
	{
		if(_ENABLE == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_Enable_Flag())
		{
			if(0 == Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue())
			{
				//do nothing
			}
			else// if(0 != Scaler_Get_EnterFRC_FLL_Dynamic_Adjust_DHTotoal_CurrentValue())
			{
				dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1) & 0x0fff;
				dh_total_last_line_length_reg.dh_total_last_line = (Get_DISP_HSYNC_LASTLINE() - 1) & 0x0fff;
				WaitFor_DEN_STOP2();
				IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
			}
		}

		return;
	}
#endif //#ifdef CONFIG_ENABLE_FLL_DYNAMIC_ADJUST_DHTOTAL

#ifdef CONFIG_ENABLE_FRAMESYNC_MODE_DYNAMIC_ADJUST_DHTOTAL
	if(_FALSE == ucFLL_Mode)
	{
		if(_ENABLE == Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_Enable_Flag())
		{
			if(0 == Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_CurrentValue())
			{
				//do nothing
			}
			else// if(0 != Scaler_Get_FrameSync_Dynamic_Adjust_DHTotoal_CurrentValue())
			{
				dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1) & 0x0fff;
				dh_total_last_line_length_reg.dh_total_last_line = (Get_DISP_HSYNC_LASTLINE() - 1) & 0x0fff;
				WaitFor_DEN_STOP2();
				IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
			}
		}

		return;
	}
#endif //#ifdef CONFIG_ENABLE_FRAMESYNC_MODE_DYNAMIC_ADJUST_DHTOTAL
}

/*============================================================================*/
/**
 * drvif_scalerdisplay_set_bg_color
 * This function is used to set background and border color of both main and sub.
 *
 * @param <display> {main or sub display}
 * @param <type> {offset value of background or external or highlight address}
 * @param <color_red> {red value}
 * @param <color_grn> {green value}
 * @param <color_blu> {blue value}
 * @return { none }
 *
 */

extern unsigned char OutpuLocalDimmingPatMode;
void drvif_scalerdisplay_set_bg_color(unsigned char display, eDISPLAYBORDERTYPE BorderType, unsigned int ColorR, unsigned int ColorG, unsigned int ColorB)
{
	ppoverlay_main_background_color1_RBUS main_background_color1_reg;
	ppoverlay_main_background_color2_RBUS main_background_color2_reg;
	//ppoverlay_main_border_highlight_border_color1_RBUS main_border_highlight_border_color1_reg;
	ppoverlay_main_border_highlight_border_color2_RBUS main_border_highlight_border_color2_reg;
	ppoverlay_main_border_highlight_border_color3_RBUS main_border_highlight_border_color3_reg;

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
/*	//no sub background in mac5
	ppoverlay_sub_background_color1_RBUS sub_background_color1_reg;
	ppoverlay_sub_background_color2_RBUS sub_background_color2_reg;
	ppoverlay_sub_border_highlight_border_color1_RBUS sub_border_highlight_border_color1_reg;
	ppoverlay_sub_border_highlight_border_color2_RBUS sub_border_highlight_border_color2_reg;
	ppoverlay_sub_border_highlight_border_color3_RBUS sub_border_highlight_border_color3_reg;
*/
#endif

#ifdef CONFIG_ENABLE_OSD_SUBTITLE
	//Set Display pattern black color
	rtd_outl(SCALEUP_D_UZU_PATGEN_COLOR0_reg, 0x8080);
	rtd_outl(SCALEUP_D_UZU_PATGEN_COLOR1_reg, 0x8080);
#endif //#ifdef CONFIG_ENABLE_OSD_SUBTITLE

	if(SLR_MAIN_DISPLAY == display)
	{
		if(BorderType == _DISPLAY_BG)
		{
			//type of background color
			main_background_color1_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color1_reg);
			main_background_color2_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Background_Color2_reg);
			if((main_background_color1_reg.m_bg_g == ColorG&0x3fff) && (main_background_color1_reg.m_bg_b == ColorB&0x3fff)
				&& (main_background_color2_reg.m_bg_r == ColorR&0x3fff))
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "#########Main DISPLAY_BG Color is the same\n");
				return;
			}
			main_background_color1_reg.m_bg_g = ColorG&0x3fff;
			main_background_color1_reg.m_bg_b = ColorB&0x3fff;
			main_background_color2_reg.m_bg_r = ColorR&0x3fff;
			IoReg_Write32(PPOVERLAY_Main_Background_Color1_reg, main_background_color1_reg.regValue);
			IoReg_Write32(PPOVERLAY_Main_Background_Color2_reg, main_background_color2_reg.regValue);
#if 0
			// [PA168][TEST] set background color for LVDS output debug
			if(((Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_2K) ||(Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_4K))
				&& (Get_DISPLAY_PANEL_CUSTOM_INDEX() == P_PA168_AU_55))
				IoReg_Mask32(PPOVERLAY_MAIN_BACKGROUND_COLOR_VADDR, ~0x0, 0xf);
#endif
		}
		else if(BorderType == _DISPLAY_EB)
		{
			//type of external border
			main_border_highlight_border_color2_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Border_Highlight_Border_Color2_reg);
			main_border_highlight_border_color3_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Border_Highlight_Border_Color3_reg);
			if((main_border_highlight_border_color2_reg.m_bd_b == ColorB&0x3fff) && (main_border_highlight_border_color3_reg.m_bd_r == ColorR&0x3fff)
				&& (main_border_highlight_border_color3_reg.m_bd_g == ColorG&0x3fff))
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "#########Main DISPLAY_EB Color is the same\n");
				return;
			}
			main_border_highlight_border_color2_reg.m_bd_b = ColorB&0x3fff;
			main_border_highlight_border_color3_reg.m_bd_r = ColorR&0x3fff;
			main_border_highlight_border_color3_reg.m_bd_g = ColorG&0x3fff;
			IoReg_Write32(PPOVERLAY_Main_Border_Highlight_Border_Color2_reg, main_border_highlight_border_color2_reg.regValue);
			IoReg_Write32(PPOVERLAY_Main_Border_Highlight_Border_Color3_reg, main_border_highlight_border_color3_reg.regValue);
		}
		else if(BorderType == _DISPLAY_HB)
		{
			//type of highlight border
			main_border_highlight_border_color2_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Border_Highlight_Border_Color2_reg);
			main_border_highlight_border_color3_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Border_Highlight_Border_Color3_reg);

			if((main_border_highlight_border_color2_reg.m_bd_b == ColorB&0x3fff) && (main_border_highlight_border_color3_reg.m_bd_g == ColorG&0x3fff)
				&& (main_border_highlight_border_color3_reg.m_bd_r == ColorR&0x3fff))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "#########Main DISPLAY_HB Color is the same\n");
				return;
			}

			main_border_highlight_border_color2_reg.m_bd_b = ColorB&0x3fff;
			main_border_highlight_border_color3_reg.m_bd_g = ColorG&0x3fff;
			main_border_highlight_border_color3_reg.m_bd_r = ColorR&0x3fff;
			IoReg_Write32(PPOVERLAY_Main_Border_Highlight_Border_Color2_reg, main_border_highlight_border_color2_reg.regValue);
			IoReg_Write32(PPOVERLAY_Main_Border_Highlight_Border_Color3_reg, main_border_highlight_border_color3_reg.regValue);
		}
		else
			return;
	}
	else// if(SLR_SUB_DISPLAY == display)
	{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
/*	//no sub background in mac5

		if(BorderType == _DISPLAY_BG)
		{
			//type of background color
			sub_background_color1_reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Background_Color1_reg);
			sub_background_color2_reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Background_Color2_reg);
			if((sub_background_color1_reg.s_bg_g == ColorG&0x3fff) && (sub_background_color1_reg.s_bg_b == ColorB&0x3fff)
				&& (sub_background_color2_reg.s_bg_r == ColorR&0x3fff))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "#########Sub DISPLAY_BG Color is the same\n");
				return;
			}
			sub_background_color1_reg.s_bg_g = ColorG&0x3fff;
			sub_background_color1_reg.s_bg_b = ColorB&0x3fff;
			sub_background_color2_reg.s_bg_r = ColorR&0x3fff;
			IoReg_Write32(PPOVERLAY_SUB_Background_Color1_reg, sub_background_color1_reg.regValue);
			IoReg_Write32(PPOVERLAY_SUB_Background_Color2_reg, sub_background_color2_reg.regValue);
		}
		else if(BorderType == _DISPLAY_EB)
		{
			//type of external border
			sub_border_highlight_border_color2_reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Border_Highlight_Border_Color2_reg);
			sub_border_highlight_border_color3_reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Border_Highlight_Border_Color3_reg);
			if((sub_border_highlight_border_color2_reg.s_bd_b == ColorB&0x3fff) && (sub_border_highlight_border_color3_reg.s_bd_r == ColorR&0x3fff)
				&& (sub_border_highlight_border_color3_reg.s_bd_g == ColorG&0x3fff))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "#########Sub DISPLAY_EB Color is the same\n");
				return;
			}

			sub_border_highlight_border_color2_reg.s_bd_b = ColorB&0x3fff;
			sub_border_highlight_border_color3_reg.s_bd_r = ColorR&0x3fff;
			sub_border_highlight_border_color3_reg.s_bd_g = ColorG&0x3fff;
			IoReg_Write32(PPOVERLAY_SUB_Border_Highlight_Border_Color2_reg, sub_border_highlight_border_color2_reg.regValue);
			IoReg_Write32(PPOVERLAY_SUB_Border_Highlight_Border_Color3_reg, sub_border_highlight_border_color3_reg.regValue);
		}
		else if(BorderType == _DISPLAY_HB)
		{
			//type of highlight border
			sub_border_highlight_border_color1_reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Border_Highlight_Border_Color1_reg);
			sub_border_highlight_border_color2_reg.regValue = IoReg_Read32(PPOVERLAY_SUB_Border_Highlight_Border_Color2_reg);
			if((sub_border_highlight_border_color1_reg.s_hbd_g == ColorG&0x3fff) && (sub_border_highlight_border_color1_reg.s_hbd_b == ColorB&0x3fff)
				&& (sub_border_highlight_border_color2_reg.s_hbd_r == ColorR&0x3fff))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "#########Sub DISPLAY_HB Color is the same\n");
				return;
			}

			sub_border_highlight_border_color1_reg.s_hbd_g = ColorG&0x3fff;
			sub_border_highlight_border_color1_reg.s_hbd_b = ColorB&0x3fff;
			sub_border_highlight_border_color2_reg.s_hbd_r = ColorR&0x3fff;
			IoReg_Write32(PPOVERLAY_SUB_Border_Highlight_Border_Color1_reg, sub_border_highlight_border_color1_reg.regValue);
			IoReg_Write32(PPOVERLAY_SUB_Border_Highlight_Border_Color2_reg, sub_border_highlight_border_color2_reg.regValue);
		}
		else
*/
#endif
			return;
	}
}


void drvif_scalerdisplay_set_panel_bg_color(unsigned int ColorR, unsigned int ColorG, unsigned int ColorB)
{//set panel forcebg color
	sfg_sfg_force_bg_at_dif_RBUS sfg_force_bg_at_dif_reg;
	sfg_force_bg_at_dif_reg.regValue = IoReg_Read32(SFG_SFG_FORCE_BG_AT_DIF_reg);
	sfg_force_bg_at_dif_reg.bg_dif_red = ColorR & 0x3ff;
	sfg_force_bg_at_dif_reg.bg_dif_grn = ColorG & 0x3ff;
	sfg_force_bg_at_dif_reg.bg_dif_blu = ColorB & 0x3ff;
	IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, sfg_force_bg_at_dif_reg.regValue);
}

/*============================================================================*/
/**
 * drvif_scalerdisplay_set_freeze
 * This function is used to set background and border color of both main and sub.
 *
 * @param <display> {main or sub display}
 * @param <type> {offset value of background or external or highlight address}
 * @param <color_red> {red value}
 * @param <color_grn> {green value}
 * @param <color_blu> {blue value}
 * @return { none }
 *
 */
void drvif_scalerdisplay_set_freeze(unsigned char display, unsigned char bFreeze)
{
	unsigned char timeout=0;
	mdomain_cap_cap_reg_doublbuffer_RBUS cap_reg_doublbuffer_reg;

	//frank@20100629 add below code to solve mantis27804 DTV SD freeze/unfreeze will have noise image
	if(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_FRAMESYNC) ||( (Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display) == _SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane())==1)) ){//JPEG_mark:need to check
		if(bFreeze)
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		else
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
	}
#ifdef CONFIG_I2RND_ENABLE
	//i2rnd case, do not use double buffer @Crixus 20160819
	if(!Scaler_I2rnd_get_enable()){
#endif
		cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		if (display == SLR_MAIN_DISPLAY) {
			cap_reg_doublbuffer_reg.cap1_db_en = 1;
		} else {
			cap_reg_doublbuffer_reg.cap2_db_en = 1;
		}
		rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);
#ifdef CONFIG_I2RND_ENABLE
	}
#endif

	if(!Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_FRAMESYNC)) {
		if(bFreeze){
#ifdef CONFIG_DUAL_CHANNEL
			IoReg_SetBits(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);
#else
			IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);
#endif

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
			display ? IoReg_BusyCheckRegBit(MDOMAIN_CAP_DDR_In2Status_reg, _BIT5,0x1FFFF) : IoReg_BusyCheckRegBit(MDOMAIN_CAP_DDR_In1Status_reg, _BIT5,0x1FFFF);
#else
			IoReg_BusyCheckRegBit(MDOMAIN_CAP_DDR_In1Status_reg, _BIT5,0x1FFFF);
#endif
		} else {
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
			IoReg_ClearBits(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);
#else
			IoReg_ClearBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);
#endif
		}
	}
#if 0/*for use DI freeze(void drvif_color_di_freeze(unsigned char bFreeze))*/

	else {
 		if(bFreeze) {
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_FREEZE,TRUE);
			// Close WatchDog
			//frank@0810 mask interrupt status bit IoReg_ClearBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT15);
			IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, ((IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) & ~(_BIT15))));
			IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);

//			if((GET_DRAGON_IC_TYPE() ==  _DRAGON_IC_DRAGON_P) && (GET_INTERLACE_MODE(info->display) || GET_RTNR_MODE(info->display)) ) {
			{
				// Enter 2D deinterlace
				// if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP))
				// 	IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_VADDR, ~_BIT19, _BIT19);

	 			// Set Memory format -> 422/8 bits in scale down
				IoReg_ClearBits(SCALEDOWN_ICH1_UZD_CTRL0_VADDR, _BIT9 | _BIT8);
				IoReg_SetBits(SCALEUP_DM_UZU_CTRL_VADDR, _BIT9);

				// Set source select in DDR_main

				IoReg_ClearBits(MDOMAIN_DISP_DDR_MainCtrl_reg, _BIT1| _BIT2);
				//IoReg_Mask32(MDOMAIN_DDR_MAINSTATUS_VADDR, ~(_BIT1 | _BIT0), _BIT2);

				// write data & enable double buffer
				drvif_memory_set_dbuffer_write();

				IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);
				IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);
				IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);

				IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);

				//drvif_scaler_vactive_end_irq(DISABLE, display); // CSW+ 0970710 Close auto MA in freeze mode
			//fixme:vip
			//	Scaler_SetAutoMAFlag(_DISABLE); // CSW+ 0970710 Close auto MA in freeze mode
			}
		}
		else {
			//frank@05242012 add below code avoid freeze/unfreeze will appear noise
			WaitFor_IVS1_Done();
//			if((GET_DRAGON_IC_TYPE() ==  _DRAGON_IC_DRAGON_P) && (GET_INTERLACE_MODE(info->display) || GET_RTNR_MODE(info->display)) ) {
 			{
				// if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP))
				// 	IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_VADDR, ~_BIT19, 0);

				// Set Memory format -> 422/8 bits in scale down
				IoReg_Mask32(SCALEDOWN_ICH1_UZD_CTRL0_VADDR, ~(_BIT8 | _BIT9), _BIT8);
				IoReg_ClearBits(SCALEUP_DM_UZU_CTRL_VADDR, _BIT9);

				IoReg_BusyCheckRegBit(PPOVERLAY_DTG_pending_status_reg, _BIT0,0x1FFFF);

				// Set source select in DDR_main from FrameSync
				IoReg_SetBits(MDOMAIN_DISP_DDR_MainCtrl_reg, _BIT2 | _BIT1);

	//			IoReg_Mask32(MDOMAIN_DDR_MAINSTATUS_VADDR, ~(_BIT1 | _BIT0), _BIT1 | _BIT2);
				// write data & enable double buffer
				// due to mantis bug:10311, we have to write 3 times to enable double buffer register write
				IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg ,  _BIT0);
				IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg ,  _BIT0);
				IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg ,  _BIT0);

				IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);
				IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);
				IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);

				// Open WatchDog
				fw_scaler_enable_fs_wdg(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), TRUE);
				IoReg_ClearBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);
				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_FREEZE,FALSE);

				//drvif_scaler_vactive_end_irq(ENABLE, display); // CSW+ 0970710 Open auto MA in unfreeze mode
			//fixme:vip
			//	Scaler_SetAutoMAFlag(_ENABLE); // CSW+ 0970710 Open auto MA in unfreeze mode
			}
		}
	}
#endif

#ifdef CONFIG_I2RND_ENABLE
	//i2rnd case, do not use double buffer @Crixus 20160819
	if(!Scaler_I2rnd_get_enable()){
#endif
		cap_reg_doublbuffer_reg.regValue =rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		if (display == SLR_MAIN_DISPLAY) {
			cap_reg_doublbuffer_reg.cap1_db_apply = 1;
			IoReg_Write32(MDOMAIN_CAP_cap_reg_doublbuffer_reg, cap_reg_doublbuffer_reg.regValue);
			cap_reg_doublbuffer_reg.regValue = IoReg_Read32(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
			while( cap_reg_doublbuffer_reg.cap1_db_apply) {
				timeout++;
				msleep(10);
				cap_reg_doublbuffer_reg.regValue = IoReg_Read32(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
				if(timeout >= 5)
				break;
			}
		} else {
			cap_reg_doublbuffer_reg.cap2_db_apply = 1;
			IoReg_Write32(MDOMAIN_CAP_cap_reg_doublbuffer_reg, cap_reg_doublbuffer_reg.regValue);
			cap_reg_doublbuffer_reg.regValue = IoReg_Read32(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
			while( cap_reg_doublbuffer_reg.cap2_db_apply) {
				timeout++;
				msleep(10);
				cap_reg_doublbuffer_reg.regValue = IoReg_Read32(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
				if(timeout >= 5)
				break;
			}

		}

		cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		if (display == SLR_MAIN_DISPLAY) {
			cap_reg_doublbuffer_reg.cap1_db_en = 0;
		} else {
			cap_reg_doublbuffer_reg.cap2_db_en = 0;
		}
		rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);
#ifdef CONFIG_I2RND_ENABLE
	}
#endif
}


extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr;
//extern unsigned int  sub_zoom_disp_hsize;
//extern unsigned int  sub_zoom_disp_vsize;

/*============================================================================*/
/**
 * fw_scalerdisplay_get_display_size
 * Set display window size, it must considers aspect ratio and pip.
 * This function will decide the Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN) and info->DisdWid
 *
 * @param { none }
 * @return none
 *
 */
void fw_scalerdisplay_get_display_size(unsigned char display)
{
	//unsigned short dispLen;
	//unsigned short dispWid;
	unsigned int m_disp_wid;
	//SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode2();


	if ( display == SLR_MAIN_DISPLAY ) {
		scalerdisplay_get_main_display_ori_size();	// get main window size
#if TEST_PATTERN_GEN
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,(3840));
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,(2160));
#endif

#if 0
#ifdef CONFIG_MEMC_BYPASS
		dispLen =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN);
		dispWid =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
			dispWid = dispWid/2;
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, dispWid);
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Rtkbypass 2 pixel mode, width /2 : %x\n", dispWid);
		}
#else
		if(Get_MEMC_Enable_Dynamic() == 0){
			dispLen =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN);
			dispWid =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID);
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL){
				dispWid = dispWid/2;
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, dispWid);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Rtkbypass 2 pixel mode, width /2 : %x\n", dispWid);
			}
		}else{
		dispLen =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN);
		dispWid =Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID);
		}
#endif

//		if((Scaler_InputSrcGetMainChType() == _SRC_VO) && ((Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) ==1)
//#ifdef ENABLE_DRIVER_I3DDMA
//			|| ((Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == TRUE) && (Scaler_Get_CurVoInfo_plane() == VO_VIDEO_PLANE_V1) && drvif_scaelr3d_decide_is_3D_display_mode())
//#endif
//		))	// yychao+ : for JPEG source
					//return;//temp mark.

#ifdef CONFIG_ENABLE_NORMAL_DISPLAY_RATIO_MODE
		if(_TRUE == Scaler_Get_AspectRatio_Enter_Normal_Mode())
		{
			ratio_type = Scaler_Get_Normal_AspectRatio_RatioType();
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"fw_scalerdisplay_get_display_size, Normal Mode : %x\n", ratio_type);
		}
#endif //#ifdef CONFIG_ENABLE_NORMAL_DISPLAY_RATIO_MODE

#ifdef CONFIG_ENABLE_DOT_BY_DOT_DISPLAY_RATIO_MODE
		if(_TRUE == Scaler_Get_AspectRatio_Enter_DotByDot_Mode())
		{
			ratio_type = Scaler_Get_DotByDot_AspectRatio_RatioType();
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"fw_scalerdisplay_get_display_size, DotByDot Mode : %x\n", ratio_type);
		}
#endif //#ifdef CONFIG_ENABLE_DOT_BY_DOT_DISPLAY_RATIO_MODE

#ifdef CONFIG_ENABLE_NATIVE_DISPLAY_RATIO_MODE
		if(_TRUE == Scaler_Get_AspectRatio_Enter_Native_Mode())
		{
			ratio_type = Scaler_Get_Native_AspectRatio_RatioType();
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"fw_scalerdisplay_get_display_size, Native Mode : %x\n", ratio_type);
		}
#endif //#ifdef CONFIG_ENABLE_NATIVE_DISPLAY_RATIO_MODE

		if ( Get_DISPLAY_RATIO_4X3() ) { // 4:3 panel
			if ( (ratio_type==SLR_RATIO_16_9) && (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_FRAMESYNC) == FALSE) ) // 4:3 panel but require 16:9 diplay only in FRC
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN, SHR(dispLen * 3, 2)); // 4:3 -> 16:9 length become 3/4
			//else if (IS_RATIO_14_9()) //14 :9 panel but require letter box display
			//	disp_info[display].DispWid = SHR(disp_info[display].DispWid * 14, 4);
		} else { // 16:9 panel
			if ( ratio_type == SLR_RATIO_4_3 ) //16 :9 panel but require 4:3 display
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, SHR(dispWid * 3, 2));
			//else if (IS_RATIO_14_9()) //14 :9 panel but require letter box display
			//	disp_info[display].DispWid = SHR(disp_info[display].DispWid * 14, 4) & ~_BIT0; //CSW+ 0961120 Add ~_BIT0 to set width to be even in 422 mode
		}
#endif
#if 1/*marked nonsense code for k2l*/
		StructSrcRect m_dispwin = Scaler_DispWindowGet();
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN, m_dispwin.src_height);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, m_dispwin.src_wid);
		return;
#else
		//frank@0429 add for custom display window
		if(ratio_type == SLR_RATIO_CUSTOM){
			StructSrcRect m_dispwin = Scaler_DispWindowGet();
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN, m_dispwin.src_height);
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, m_dispwin.src_wid);
			return;
		}else if(ratio_type == SLR_ASPECT_RATIO_SOURCE){
		 	unsigned int Ratio1 = 0, Ratio2 = 0;
			StructSrcRect m_dispwin;
			m_dispwin.srcx = 0;
			m_dispwin.srcy = 0;
			m_dispwin.src_wid = _DISP_WID;
			m_dispwin.src_height = _DISP_LEN;
			Ratio1 = (unsigned int)_DISP_LEN * (unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE);
			if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
			{
				Ratio2 = (unsigned int)_DISP_WID * (unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)*2;
			}
			else
			{
				Ratio2 = (unsigned int)_DISP_WID * (unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE);
			}

			if(Ratio1 > Ratio2){
				if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
				{
					m_dispwin.src_height = (unsigned short)(((unsigned int)_DISP_WID * (unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)*2)/(unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
				}
				else
				{
					m_dispwin.src_height = (unsigned short)(((unsigned int)_DISP_WID * (unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE))/(unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
				}
				m_dispwin.srcy = (_DISP_LEN-m_dispwin.src_height)/2;
             //   if((Scaler_InputSrcGetMainChType() != _SRC_VO)|| ((vo_force_data_mode_get_enable()!=SLR_DISPLAY_DATA_FRAME_SYNC)&&(vo_force_data_mode_get_enable()!=SLR_DISPLAY_DATA_FS_NO_MEMORY)))
					Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC,FALSE);
			}else if(Ratio1 < Ratio2){
				if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
				{
					m_dispwin.src_wid = (unsigned short)(((unsigned int)_DISP_LEN * (unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE))/((unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)*2));
				}
				else
				{
					m_dispwin.src_wid = (unsigned short)(((unsigned int)_DISP_LEN * (unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE))/(unsigned int)Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
				}
				m_dispwin.srcx = (_DISP_WID-m_dispwin.src_wid)/2;
			}
			Scaler_DispWindowSet(m_dispwin);
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN, m_dispwin.src_height);
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, m_dispwin.src_wid);
			return;
		}
		else if(ratio_type == SLR_RATIO_SOURCE_CUSTOM){
			unsigned int Ratio1 = 0, Ratio2 = 0;
			StructSrcRect m_dispwin = Scaler_DispWindowGet();
			StructSrcRect m_disp_src_win;
			unsigned int input_height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

			m_disp_src_win.srcx = m_dispwin.srcx;
			m_disp_src_win.srcy= m_dispwin.srcy;
			m_disp_src_win.src_wid= m_dispwin.src_wid;
			m_disp_src_win.src_height= m_dispwin.src_height;

			if(Scaler_InputSrcGetMainChType()==_SRC_VO)
			{
				SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());

				if(pVOInfo->progressive == 0)
						input_height = input_height*2;
				if(pVOInfo->pixelAR_ver==0)
				{
					pVOInfo->pixelAR_ver=1;
				}
				if(pVOInfo->pixelAR_hor==0)
				{
					pVOInfo->pixelAR_hor=1;
				}
				//frank@0515 add below code to avoid ratio caculate overflow 32bits,1920X1080=2073600,so 2073600X2070 will overflow
			    if((pVOInfo->pixelAR_ver>2000) ||(pVOInfo->pixelAR_hor>2000)){
			        pVOInfo->pixelAR_ver /=100;
			        pVOInfo->pixelAR_hor /=100;
			    }

				Ratio1 =(unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor* (unsigned int)m_dispwin.src_height;
				Ratio2 = (unsigned int)m_dispwin.src_wid* input_height*pVOInfo->pixelAR_ver;

				if(Ratio1 > Ratio2){
					m_disp_src_win.src_height = ((m_dispwin.src_wid*(unsigned int)input_height*pVOInfo->pixelAR_ver)/((unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor));
					m_disp_src_win.srcy = (m_dispwin.src_height-m_disp_src_win.src_height)/2+m_dispwin.srcy;
					Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC,FALSE);
				}else if(Ratio1 < Ratio2){
					m_disp_src_win.src_wid =(((unsigned int)m_dispwin.src_height*(unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor)/(input_height*pVOInfo->pixelAR_ver));
					m_disp_src_win.srcx = (m_dispwin.src_wid-m_disp_src_win.src_wid)/2+m_dispwin.srcx;
				}
			}
			else
			{
				if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
				{
					input_height = input_height*2;
				}
				Ratio1 =(unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*(unsigned int)m_dispwin.src_height;
				Ratio2 = (unsigned int)m_dispwin.src_wid* input_height;

				if(Ratio1 > Ratio2){
					m_disp_src_win.src_height = ((m_dispwin.src_wid*(unsigned int)input_height)/((unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)));
					m_disp_src_win.srcy = (m_dispwin.src_height-m_disp_src_win.src_height)/2+m_dispwin.srcy;
					Scaler_DispSetInputInfo(SLR_INPUT_FRAMESYNC,FALSE);
				}else if(Ratio1 < Ratio2){
					m_disp_src_win.src_wid =(((unsigned int)m_dispwin.src_height*(unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE))/input_height);
					m_disp_src_win.srcx = (m_dispwin.src_wid-m_disp_src_win.src_wid)/2+m_dispwin.srcx;
				}
			}

			//frank@1230 add below code to solve mantis#60205 preview window color not correct problem
			if((m_disp_src_win.src_wid%2)>0){
				m_disp_src_win.src_wid = (m_disp_src_win.src_wid & (~1))+2;
			}

			Scaler_DispWindowSet_source(m_disp_src_win);
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN, m_disp_src_win.src_height);
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, m_disp_src_win.src_wid);
			return;
		}

#ifdef RUN_ON_TVBOX
		if((Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX) && (scalerdisplay_get_display_use_tve_size())){
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"######## TVBOX Set  tveDispWID :%d, tveDispLEN :%d ###########\n", scalerdisplay_get_BoxDispInfo(_BOX_DISP_WID), scalerdisplay_get_BoxDispInfo(_BOX_DISP_LEN));
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_WID,scalerdisplay_get_BoxDispInfo(_BOX_DISP_WID));
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DISP_LEN,scalerdisplay_get_BoxDispInfo(_BOX_DISP_LEN));
			return;
		}
#endif

		dispLen = (unsigned short)_DISP_LEN;	// get original panel length
		dispWid = (unsigned short)_DISP_WID;	// get original panel width

		if ( Get_DISPLAY_RATIO_4X3() ) { // 4:3 panel
			if ( Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_ASPECT_RATIO) ) { // 4:3 content
				// do nothing
			} else { // 16:9 content
				if ( ratio_type == SLR_RATIO_BBY_NORMAL ) { // normal
					/*if ( Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC) ) { // if frame sync, skip aspect ratio
						// do nothing
					} else {*/
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_LEN, SHR(dispLen*3,2)); // 4:3 -> 16:9 length become 3/4
					//}
				} else if ( ratio_type == SLR_RATIO_BBY_ZOOM ) { // zoom
					// do nothing (cut in fw_scaler_cal_vgip_capture())
				}
			}
		} else {
			unsigned short dispWid_16_9 = (unsigned short)((unsigned int)dispLen*16/9);
			unsigned short dispWid_16_10 = (unsigned short)((unsigned int)dispLen*16/10);
			if ( ABS(dispWid,dispWid_16_9) < ABS(dispWid,dispWid_16_10) ) { // 16:9 panel
				switch ( ratio_type )
				{
				case SLR_RATIO_BBY_NORMAL:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, SHR(dispWid*3,2)); // 16:9 -> 4:3 width become 3/4
					break;
				case SLR_RATIO_ZOOM_14_9:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, SHR(dispWid*14,4)&(~_BIT0)); // 16:9 -> 4:3 width become 3/4 //need even to avoid 444->422 data error
					break;
                                case SLR_RATIO_15_9:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*15/9));
				break;

				case SLR_RATIO_5_4:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*5/4));
				break;

				case SLR_RATIO_85_48:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*85/48));
				break;

				case SLR_RATIO_16_10:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*16/10));
				break;
				case SLR_RATIO_BBY_WIDE_1:
				case SLR_RATIO_BBY_WIDE_2:
				case SLR_RATIO_BBY_ZOOM:
				case SLR_RATIO_BBY_CINEMA:
				default:
					// do nothing
					break;
#ifdef CONFIG_DTV_AFD_CONTROL
				case SLR_RATIO_BBY_AUTO:
					if(Scaler_InputSrcGetMainChType()==_SRC_VO){
						switch(Scaler_DispGetInputInfo(SLR_INPUT_AFD)){
							case SLR_AFD_SAME_AS_FRAME:
							default:
									{ //playback
										unsigned int panel_ratio = 0;
										unsigned int source_ratio = 0;
										unsigned int input_height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
										SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
										if(pVOInfo->progressive == 0)
											input_height = input_height*2;
										//frank@0515 add below code to avoid ratio caculate overflow 32bits,1920X1080=2073600,so 2073600X2070 will overflow
										if(pVOInfo->pixelAR_ver>2000 ||pVOInfo->pixelAR_hor>2000){
											pVOInfo->pixelAR_ver /=100;
											pVOInfo->pixelAR_hor /=100;
										}

										panel_ratio = (unsigned int)input_height*pVOInfo->pixelAR_ver*dispWid;
										source_ratio = (unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor*dispLen;
									//frank@0704 mark this condition to do divx verify	if((source_ratio*9/dispLen)<(panel_ratio*16/dispWid)+1)  //input source aspect raito <=16/9
										{
											if(panel_ratio > source_ratio){//Change panel width
												Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, ((dispLen*(unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor)/(input_height*pVOInfo->pixelAR_ver)));
											}else{//Change panel height
												Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_LEN, ((dispWid*(unsigned int)input_height*pVOInfo->pixelAR_ver)/((unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*pVOInfo->pixelAR_hor)));
											}
										}
									}
								break;
							case SLR_AFD_4X3:
								Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, SHR(dispWid*3,2)); //set width as 4:3
								break;
							case SLR_AFD_14X9:
								//if(Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO)==SLR_SOURCERATIO_4X3)
									Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, SHR(dispWid*14,4)); //set width as 14:9
								break;
							case SLR_AFD_4X3_SP:
								Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, SHR(dispWid*14,4)); //set width as 14:9
								break;
							case SLR_AFD_16X9:
							case SLR_AFD_16X9_SP:
							case SLR_AFD_16X9_SP_4X3:
								break;
						}
					}
				#ifdef CONFIG_WSS_ENABLE
					else if(Scaler_InputSrcGetMainChType()==_SRC_CVBS){
						switch(Scaler_DispGetInputInfo(SLR_INPUT_WSS)){
							case SLR_WSS_4X3:
								Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, SHR(dispWid*3,2)); //set width as 4:3
								break;
							case SLR_WSS_BOX_14X9:
							case SLR_WSS_BOX_14X9_TOP:
							case SLR_WSS_14X9_SP:
								Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, SHR(dispWid*14,4)); //set width as 14:9
								break;
							case SLR_WSS_BOX_16X9_TOP:
							case SLR_WSS_16X9:
							case SLR_WSS_BOX_16X9:
							case SLR_WSS_BOX_G16X9:
								break;
								default:
					break;
						}
					}
                                #endif
					break;
#endif //#ifdef CONFIG_DTV_AFD_CONTROL
				}
			} else { // 16:10 panel
				switch ( ratio_type )
				{
				case SLR_RATIO_BBY_NORMAL:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, dispWid*5/6);
					break;
				case SLR_RATIO_BBY_WIDE_2:
					/*if ( Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_FRAMESYNC) ) { // if frame sync, skip aspect ratio
						// do nothing
					} else {*/
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_LEN, dispLen*9/10);
					//}
					break;

				case SLR_RATIO_15_9:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*15/9));
				break;

				case SLR_RATIO_5_4:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*5/4));
				break;

				case SLR_RATIO_85_48:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*85/48));
				break;

				case SLR_RATIO_16_10:
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, (dispLen*16/10));
				break;

				case SLR_RATIO_BBY_WIDE_1:
				case SLR_RATIO_BBY_ZOOM:
				case SLR_RATIO_BBY_CINEMA:
				default:
					// do nothing
					break;
				}
			}
		}
#ifdef ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		//for hdmi rotate display ratio is suitable
		if((Get_GOSUBandVODMA()==TRUE)&&((Get_Rotate_Mode()==ROTATE_MODE_90)||(Get_Rotate_Mode()==ROTATE_MODE_270))&&(Scaler_InputSrcGetMainChType() == _SRC_VO))
		{
			unsigned short rotateDiswidth = (unsigned short)(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN)*Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN)/Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID));
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID, rotateDiswidth);
		}
#endif
#endif
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else {	//Sub PIP
		/*PipMp_GetPipSize((eSubType)Scaler_PipGetInfo(SLR_PIP_TYPE), &dispWid, &dispLen);*/
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN, DbgSclrFlgTkr.sub_zoom_disp_vsize);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, DbgSclrFlgTkr.sub_zoom_disp_hsize);
#if 0
#ifdef CONFIG_PIP_SIZE_NARROW_WITHOUT_BORDER
		if((Scaler_PipGetInfo(SLR_PIP_TYPE) >= SUBTYPE_PIPSMALL) && (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_PIPMLSR_4x3)) {
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN, dispLen - subBorderWidth * 2);
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, dispWid - subBorderWidth * 2);
		}
#endif //#ifdef CONFIG_PIP_SIZE_NARROW_WITHOUT_BORDER
#endif
	}
#endif //#ifdef CONFIG_DUAL_CHANNEL
	//printk(KERN_INFO "display=%x, DispWid=%x, DispLen=%x in SetWindowSize\n",info->display, Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID), Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN));
	//frank@0816 add below code to solve mantis#48375 M domain width can not odd number let format 422 color fail
	m_disp_wid = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DISP_WID);
	if((m_disp_wid%2)>0){
		m_disp_wid = (m_disp_wid & (~1))+2;
	}
	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID, m_disp_wid);
}


/*============================================================================*/
/**
 * fw_scalerdisplay_handler
 * This function is used to handle display (page4), including main & sub
 * It contains several parts:
 * 1. timing control
 * 2. main display
 * 3. sub display
 * 4. scaling
 * 5. OSD overlay
 * 6. CRC
 *
 * @param <info> { display-info struecture }
 * @return none
 *
 */
void fw_scalerdisplay_handler(unsigned char display)
{
//	display ? WaitFor_EN_STOP_SUB() : WaitFor_EN_STOP_MAIN();
	if (display == SLR_MAIN_DISPLAY) {
//#ifdef VBY_ONE_PANEL
	//	fw_scalerdisplay_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
//#endif
		// Display main window control
		if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1)
		{
			//don't do that when milliet3 panel, move to scaler_Millet3_LVDS_output_control
		}
		else
			scalerdisplay_set_main_ctrl();

#if 0	// sirius not support SR mode
//#ifdef VBY_ONE_PANEL

	{
		UINT8 sr_mode;
		unsigned short dispLen;
		unsigned short dispWid;
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
			sr_mode = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_SR_MODE);
			dispLen =Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);
			dispWid =Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID);

			if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() &&
				((Scaler_Disp3dGetInfo(SLR_DISP_3D_3DTYPE)<SLR_3D_SIDE_BY_SIDE_HALF_CVT_2D) || (Scaler_Disp3dGetInfo(SLR_DISP_3D_3DTYPE)==SLR_3D_2D_CVT_3D))){//PR type panel and 3d or 2D cvt 3D  type
					dispWid	/= 2;
					dispLen /= 2;
			}else{
				if(sr_mode == 0){	//Hx2, Vx2
					dispWid	/= 2;
					dispLen /= 2;
				}
				else if(sr_mode == 1) //Vx2
					dispLen /= 2;
				else if(sr_mode == 2) // Hx2
					dispWid	/= 2;
				else	{  // SR_bypass

				}
			}
			Scaler_DispSetInputInfo(SLR_INPUT_DISP_LEN, dispLen);
			Scaler_DispSetInputInfo(SLR_INPUT_DISP_WID, dispWid);
		}
	}
#endif
#if 0 //frank@20150903 mark below timing setting
		// Display timing control
		if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1)
		{
			//don't do that when milliet3 panel, move to scaler_Millet3_LVDS_output_control
		}
		else
			scalerdisplay_set_timing();
#endif

	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else {
		if(((Scaler_PipGetInfo(SLR_PIP_TYPE) >= SUBTYPE_MP2X2) && (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_MP1L7B)) && (Scaler_PipGetSubInfo(SLR_PIP_SUB_MPENABLE))) {

		}
		else{
			PipMp_SetSubInfo(Scaler_PipGetInfo(SLR_PIP_TYPE));		// insert sub infomation
		}

		if (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_PIPMLSR_4x3){	// Sub PIP
			Pipmp_SetPipCtrl();		// Dislay sub window control
		}
		else if (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_MP1L7B) {	// Sub MP
			Pipmp_SetMpCtrl();		// Dislay sub window control
//#ifdef CONFIG_FULL_SCREEN_PIP
		} else {					// This case is only for FULL screen PIP for iDTV solution
			Pipmp_SetPipCtrl();		// Dislay sub window control
//#endif
		}
	}
#endif
}


#if 1//#ifdef CONFIG_ZOOM_IN_OUT_ENABLE
void fw_scaler_zoom_cal_vgip_capture(int ratioH, int ratioV)
{

	unsigned short after_result;
	unsigned int temp;
	stVGIP_ADJUSTMENT_INFO adjustment_data;
//	unsigned char ratio_decrease_flag = 0;
	#if 0
	unsigned char h_ratio,v_ratio;
	#else
	unsigned char h_ratio = 100,v_ratio = 100; //must check overscan after
	#endif


	stDISPLAY_OVERSCAN_DATA scan_data;
	adjustment_data.h_start = 0;
	adjustment_data.h_width= 0;
	adjustment_data.v_start = 0;
	adjustment_data.v_length= 0;

	scan_data.HStart = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
	scan_data.HWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
	scan_data.VStart = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);
	scan_data.VHeight = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[1]%d %d %d %d %d %d\n",scan_data.HStart,scan_data.HWidth,scan_data.VStart,scan_data.VHeight,ratioH,ratioV);


	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_data.HStart);
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, scan_data.HWidth);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_data.VStart);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, scan_data.VHeight);

	Scaler_DispSetInputInfo(SLR_INPUT_MEM_ACT_HSTA,0);
	Scaler_DispSetInputInfo(SLR_INPUT_MEM_ACT_VSTA,0);

	ratioH = ratioH - (100 - h_ratio);
	ratioV = ratioV - (100 - v_ratio); // overscan be 100%

/*
	if (GET_INPUTSOURCE_TYPE() == _SRC_CVBS || GET_INPUTSOURCE_TYPE() == _SRC_SV){
		if(ratioV != _DISPLAY_RATIO_100){
			after_result = disp_info[info->display].IPV_ACT_LEN_PRE - ((disp_info[info->display].IPV_ACT_LEN_PRE/10)*ratioV/10);
			disp_info[info->display].IPV_ACT_STA_PRE+= (after_result/2);
			disp_info[info->display].IPV_ACT_LEN_PRE -= after_result;
		}

		if(ratioH != _DISPLAY_RATIO_100){
			after_result = disp_info[info->display].IPH_ACT_WID_PRE - ((disp_info[info->display].IPH_ACT_WID_PRE/10)*ratioH /10);
			if(after_result%2)
				after_result++;
			disp_info[info->display].IPH_ACT_STA_PRE+= (after_result/2);
			disp_info[info->display].IPH_ACT_WID_PRE -= after_result;
		}

	} else {
		if(GET_INPUTSOURCE_TYPE() == _SRC_VGA)// PC timing don't overscan.
			return;
	*/


			if(ratioV != _DISPLAY_RATIO_100){
				after_result = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)- ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)/10)*ratioV/10);
			temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) + (after_result/2);
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);

			temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) - after_result;
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
			}


			if(ratioH != _DISPLAY_RATIO_100){
				after_result = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) - ((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)/10)*ratioH/10);
			if(after_result%2)
				after_result++;
			temp = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA) + (after_result/2);
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA,temp);
			temp = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) - after_result;
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID,temp);
		}


}

//USER:LewisLee DATE:2011/01/27
//for enable zoom function, we remain need to have different Aspect Ratio

#if 0
// rika20151217
//remove unused parts; coverity 120148, 120147 DEADCODE
void fw_scaler_zoom_cal_vgip_AspectRatio_capture(void)
{
	unsigned short temp;
	stDISPLAY_OVERSCAN_DATA scan_original_data;
	stDISPLAY_OVERSCAN_DATA scan_data;
	stVGIP_ADJUSTMENT_INFO adjustment_data;
	SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode2();
	unsigned char h_start_even_odd_flag=0;
	unsigned char doOverscanFlag = FALSE;
	unsigned short interlaceStatus;
	unsigned short AfterDILen;
	StructSrcRect m_inputwin;

	#if 0
	if(SLR_ASPECT_RATIO_100 == ratio_type)
		return;
	#else //#if 0
	//20110428 modifyed by LewisLee, Resolved bug ID:1916
        if(SLR_ASPECT_RATIO_100 == ratio_type)
	{
		goto fw_scaler_zoom_cal_vgip_AspectRatio_capture_Adjust;
		//		return;
	}
	#endif //#if 0


	scan_data.HStart = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA);
	scan_data.HWidth = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
	scan_data.VStart = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);
	scan_data.VHeight = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[ZOOM]original size %d %d %d %d\n",scan_data.HStart,scan_data.HWidth,scan_data.VStart,scan_data.VHeight);


//	h_start_even_odd_flag = (scan_data.HStart %2)?1:0 ;// 1->odd,0->even
	//printk(KERN_INFO "[ZOOM]@@h_start_even_odd_flag=%x\n",h_start_even_odd_flag);
	//Mode_scaler_overscan(&scan_data, ratio_type);

	scan_original_data.HStart = scan_data.HStart;
	scan_original_data.HWidth = scan_data.HWidth;
	scan_original_data.VStart = scan_data.VStart;
	scan_original_data.VHeight = scan_data.VHeight;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\nratio_type =%x", ratio_type);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\nHStart:%x, HWidth:%x", scan_original_data.HStart, scan_original_data.HWidth);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\nVStart:%x, VHeight:%x\n", scan_original_data.VStart, scan_original_data.VHeight);

//	if(_DISABLE == Scaler_Get_HVSizeAdjustEnable())
		doOverscanFlag = FALSE;
//	else
//		doOverscanFlag = TRUE;

#if 0  //chengying mark
	if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE) && doOverscanFlag){
		temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)-scan_data.VHeight;
		scan_data.VHeight +=	(temp/2);
		scan_data.VStart 	-=	(temp/4);
	}
#endif

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[ZOOM]after overscan %d %d %d %d\n",scan_data.HStart,scan_data.HWidth,scan_data.VStart,scan_data.VHeight);

	// we restore the original input timing first
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_data.HStart);
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, scan_data.HWidth);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_data.VStart);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, scan_data.VHeight);

	Scaler_DispSetInputInfo(SLR_INPUT_MEM_ACT_HSTA,0);
	Scaler_DispSetInputInfo(SLR_INPUT_MEM_ACT_VSTA,0);


	// 14:9
	if ((ratio_type==SLR_RATIO_14_9) && (Scaler_InputSrcGetMainChType() != _SRC_VGA)) {  // vga don't need to do 14:9
		temp = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA) + (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) >> 4))& ~_BIT0;
		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA,temp);
		temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)>>4)*14) & (~_BIT0);
		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID,temp);

	// Point to point
	} else if (ratio_type==SLR_RATIO_POINTTOPOINT) {  // point to point mode, don't do any scaling
		temp = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) & ~_BIT0;
		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID,temp);
		Scaler_DispSetInputInfo(SLR_INPUT_DI_WID,temp);
		Scaler_DispSetInputInfo(SLR_INPUT_CAP_WID,temp);
		Scaler_DispSetInputInfo(SLR_INPUT_DISP_WID,temp);
		Scaler_DispSetInputInfo(SLR_INPUT_MEM_ACT_WID,temp);

		temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) & ~_BIT0;
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
		Scaler_DispSetInputInfo(SLR_INPUT_CAP_LEN,temp);
		Scaler_DispSetInputInfo(SLR_INPUT_DISP_LEN,temp);
		Scaler_DispSetInputInfo(SLR_INPUT_MEM_ACT_LEN,temp);

		// if panel width <= input signal width
		if ((_DISP_WID) <= Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)) {
				temp = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA) +  ((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) - _DISP_WID) >> 1);
				Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA,temp);
				Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID,_DISP_WID);  // may restore while setting scale para
		}

		interlaceStatus = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE);
		AfterDILen = interlaceStatus ? ( Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) << 1) : Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);

		// if panel height <= input signal height
		if ((_DISP_LEN) <= AfterDILen) {
			if (interlaceStatus) {
				temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) - (_DISP_LEN>>1)) >> 1);
				Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
				Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,(_DISP_LEN) >> 1 );
			} else {
				temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) - _DISP_LEN) >> 1);
				Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
				Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,_DISP_LEN );
			}
		}

	// letter bot
	} else if (ratio_type==SLR_RATIO_LETTERBOX ) { //letter box display
		temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >> 3);
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
		temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)>>2)*3) & ~_BIT0 ;
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);

	// others
	}
	/*
	  modified for  display ratio request
	  sync from E60
	  egger20100909 start
	*/

	#ifdef CONFIG_3D_ASPECT_RATIO
	else if(ratio_type==SLR_ASPECT_RATIO_CAPTION )
	{
			if(Scaler_InputSrcGetMainChType() == _SRC_VO && Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
				return;
			}
			temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >> 4);
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
			temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*15)>>4) & ~_BIT0 ;
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
	}
	else if(ratio_type==SLR_ASPECT_RATIO_MOVIE )
	{
			if(Scaler_InputSrcGetMainChType() == _SRC_VO  && Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
				return;
	}
			temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >> 4);
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
			temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)>>3)*7) & ~_BIT0 ;
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
	}
	else if(ratio_type==SLR_ASPECT_RATIO_PERSON )
	{
			if((Scaler_InputSrcGetMainChType() == _SRC_VO) && Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
				return;
			}
			temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >> 5);
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
			temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)>>4)*15) & ~_BIT0 ;
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
        }
#else

	else if(ratio_type==SLR_ASPECT_RATIO_CAPTION )
	{
		if(Scaler_InputSrcGetMainChType() == _SRC_VO){
			return;
		}
		temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >> 4);
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
		temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*15)>>4) & ~_BIT0 ;
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
	}
	else if(ratio_type==SLR_ASPECT_RATIO_MOVIE )
	{
		if((Scaler_InputSrcGetMainChType() == _SRC_VO) && Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
			return;
		}
		temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >> 4);
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
		temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)>>3)*7) & ~_BIT0 ;
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
	}
	else if(ratio_type==SLR_ASPECT_RATIO_PERSON )
	{
		if((Scaler_InputSrcGetMainChType() == _SRC_VO) && Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
			return;
		}
		temp = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA) +  (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) >> 5);
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA,temp);
		temp = ((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)>>4)*15) & ~_BIT0 ;
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,temp);
	}
#endif
	/*
	  modified for  display ratio request
	  sync from E60
	  egger20100909 end
	*/
	//frank@0927 add RATIO_100 mode for tpv project
	else if(ratio_type==SLR_ASPECT_RATIO_100 )
	{
		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
	}
	else {
		if ( Get_DISPLAY_RATIO_4X3() ) { // 4:3 panel
			if ( Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO) ) { // 4:3 content
				// do nothing
			} else { // 16:9 content
				if ( ratio_type == SLR_RATIO_BBY_NORMAL ) { // normal
					// do nothing
				} else if( ratio_type == SLR_RATIO_BBY_ZOOM || ratio_type == SLR_RATIO_ZOOM_14_9){ // zoom
					temp = scan_original_data.HStart + SHR(scan_original_data.HWidth, 3);
					Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, temp);
					temp = SHR((UINT32)(scan_original_data.HWidth)*3, 2);
					Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, temp);
				}
			}
		} else { // 16:9 or 16:10 panel
			unsigned short dispLen = (unsigned short)_DISP_LEN;	// get original panel length
			unsigned short dispWid = (unsigned short)_DISP_WID;	// get original panel width
			unsigned short dispWid_16_9 = (unsigned short)((unsigned int)dispLen*16/9);
			unsigned short dispWid_16_10 = (unsigned short)((unsigned int)dispLen*16/10);
			if ( ABS(dispWid,dispWid_16_9) < ABS(dispWid,dispWid_16_10) ) { // 16:9 panel
				switch ( ratio_type )
				{
				case SLR_RATIO_BBY_NORMAL:
				case SLR_RATIO_BBY_WIDE_1:
				case SLR_RATIO_BBY_WIDE_2:
				default:
					// do nothing
					break;
				case SLR_RATIO_BBY_ZOOM:
					if(Scaler_InputSrcGetMainChType() == _SRC_VO && Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC)){
							Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart);
							Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, scan_original_data.VHeight);
							return;
						}

					temp = scan_original_data.VStart + SHR(scan_original_data.VHeight, 3);
					Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, temp);
					temp = SHR((UINT32)scan_original_data.VHeight*3, 2);
					Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, temp);
					break;


				case SLR_RATIO_ZOOM_14_9://TPV zoom1 spec(Chroma22291 YPP1080p60 V:5.5)
					if(Scaler_InputSrcGetMainChType() == _SRC_VO){
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart);
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, scan_original_data.VHeight);
						return;
					}
					temp = scan_original_data.VStart + (scan_original_data.VHeight/20);
					Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, temp);
					temp = ((UINT32)scan_original_data.VHeight*9)/10;
					Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, temp);
					break;


				case SLR_RATIO_BBY_CINEMA:
					if(Scaler_InputSrcGetMainChType() == _SRC_VO && Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC)){
							Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_original_data.HStart);
							Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, scan_original_data.HWidth);
							Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart);
							Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, scan_original_data.VHeight);
							return;
						}
						temp = (UINT16)((UINT32)scan_original_data.HWidth*320/423)& ~_BIT0;
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_original_data.HStart + SHR((scan_original_data.HWidth - temp),1));
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, temp);
						temp = (UINT16)((UINT32)scan_original_data.VHeight*320/423);
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart + SHR((scan_original_data.VHeight - temp),1));
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, temp);
						break;


				}
			} else { // 16:10 panel
				switch ( ratio_type )
				{
				case SLR_RATIO_BBY_NORMAL:
				case SLR_RATIO_BBY_WIDE_2:
				default:
					// do nothing
					break;
				case SLR_RATIO_BBY_WIDE_1:
					if ( Scaler_DispGetInputInfo(SLR_INPUT_ASPECT_RATIO) ) { // 4:3 content
						// do nothing
					} else { // 16:9 content

						// Based on equation, capture width should be 90% original width.
						// However, best buy says that 95% of the image width is visible.
						temp = (UINT16)((UINT32)scan_original_data.HWidth*19/20)& ~_BIT0; // 95%
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_original_data.HStart + SHR((scan_original_data.HWidth - temp),1));
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, temp);
					}
					break;
				case SLR_RATIO_BBY_ZOOM:
				case SLR_RATIO_ZOOM_14_9:
					if(Scaler_InputSrcGetMainChType() == _SRC_VO){
							Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart);
							Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, scan_original_data.VHeight);
							return;
						}
						temp = (UINT16)((UINT32)scan_original_data.HWidth*9/10)& ~_BIT0;
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_original_data.HStart + SHR((scan_original_data.HWidth - temp),1));
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, temp);
						temp = (UINT16)(SHR((UINT32)scan_original_data.VHeight*3,2));
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart + SHR(scan_original_data.VHeight,3));
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, temp);
						break;
				case SLR_RATIO_BBY_CINEMA:
					if(Scaler_InputSrcGetMainChType() == _SRC_VO && Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC) ){
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_original_data.HStart);
						Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, scan_original_data.HWidth);
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart);
						Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, scan_original_data.VHeight);
						return;
					}
					temp = (UINT16)((UINT32)scan_original_data.HWidth*32/47)& ~_BIT0;
					Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, scan_original_data.HStart + SHR((scan_original_data.HWidth - temp),1));
					Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, temp);
					temp = (UINT16)((UINT32)scan_original_data.VHeight*320/423);
					Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, scan_original_data.VStart + SHR((scan_original_data.VHeight - temp),1));
					Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, temp);
					break;
				}
			}
		}
	}

	fw_scaler_zoom_cal_vgip_AspectRatio_capture_Adjust:

	adjustment_data.h_start=0;
	adjustment_data.h_width=0;
	adjustment_data.v_start=0;
	adjustment_data.v_length=0;
	// [2D3D] don't do overscan adj in 2D 3D conversion mode
	if(doOverscanFlag){
		pVGIP_Adjustment_func(&adjustment_data, ratio_type);
		if(drvif_color_get_scaleup_cuthor4line())
		{
			adjustment_data.h_start += (adjustment_data.h_start-4);
			adjustment_data.h_width += (adjustment_data.h_width+8);
		}
		if(drvif_color_get_scaleup_cutver2line())
		{
			adjustment_data.v_start += (adjustment_data.v_start-2);
			adjustment_data.v_length += (adjustment_data.v_length+4);
		}
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"adust data 0 %d %d %d %d\n",adjustment_data.h_start,adjustment_data.h_width,adjustment_data.v_start,adjustment_data.v_length);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"adust data 1 %d %d %d %d\n",adjustment_data.h_start,adjustment_data.h_width,adjustment_data.v_start,adjustment_data.v_length);

	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA)+adjustment_data.h_start);
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)+adjustment_data.h_width);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA)+adjustment_data.v_start);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)+adjustment_data.v_length);

	//frank@0510 add below code to set HDI input window function ++
	m_inputwin = Scaler_InputWindowGet();

	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE)){
		m_inputwin.srcy /=2;
		m_inputwin.src_height /=2;
	}

	if((m_inputwin.src_wid != 0) && (m_inputwin.src_height != 0)){
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA)+m_inputwin.srcx);
		if((m_inputwin.src_wid+m_inputwin.srcx)>Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)){
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)-m_inputwin.srcx);
		}else{
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, m_inputwin.src_wid);
		}

		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA)+m_inputwin.srcy);
		if((m_inputwin.src_height+m_inputwin.srcy)>Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)){
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-m_inputwin.srcy);
		}else{
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, m_inputwin.src_height);
		}
	}
	//frank@0510 add below code to set HDI input window function --

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n[Zoom]@@@@@h_start=%d",Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n[Zoom]@@@@@h_width=%d",Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n[Zoom]@@@@@v_start=%d",Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n[Zoom]@@@@@v_length=%d\n",Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN));


	// horizontal start point for 3D right frame(l_flag=0)
	if(Scaler_InputSrcGetMainChType()== _SRC_HDMI && drvif_IsHDMI())
	{
					//USER:LewisLee DATE:2011/06/20
		//In zoom mode, we need chech even / odd flag by _PRE
		h_start_even_odd_flag = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE) %2)?1:0 ;// 1->odd,0->even

		if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA)%2) != h_start_even_odd_flag)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"hdmi even odd swap\n");
				Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA)-1);
		}
	}

}
#endif//0
#endif

unsigned short Main_InputRegion_x = 0;
unsigned short Main_InputRegion_y = 0;
unsigned short Main_InputRegion_w = 0;
unsigned short Main_InputRegion_h = 0;
unsigned short Sub_InputRegion_x = 0;
unsigned short Sub_InputRegion_y = 0;
unsigned short Sub_InputRegion_w = 0;
unsigned short Sub_InputRegion_h = 0;



void set_input_for_vgip(unsigned char display, unsigned short input_x, unsigned short input_y, unsigned short input_w, unsigned short input_h)
{
	if (display == SLR_MAIN_DISPLAY) {
		Main_InputRegion_x = input_x;
		Main_InputRegion_y = input_y;
		Main_InputRegion_w = input_w;
		Main_InputRegion_h = input_h;
	}
#ifdef CONFIG_DUAL_CHANNEL
	else {
		Sub_InputRegion_x = input_x;
		Sub_InputRegion_y = input_y;
		Sub_InputRegion_w = input_w;
		Sub_InputRegion_h = input_h;
	}
#endif
}

void get_input_for_vgip(unsigned char display, StructSrcRect *p_input)
{
	if (display == SLR_MAIN_DISPLAY) {
		p_input->srcx = Main_InputRegion_x;
		p_input->srcy = Main_InputRegion_y;
		p_input->src_wid = Main_InputRegion_w;
		p_input->src_height = Main_InputRegion_h;
	}
#ifdef CONFIG_DUAL_CHANNEL
	else {
		p_input->srcx = Sub_InputRegion_x;
		p_input->srcy = Sub_InputRegion_y;
		p_input->src_wid = Sub_InputRegion_w;
		p_input->src_height = Sub_InputRegion_h;
	}
#endif
}

void cal_adaptive_streaming_input(unsigned char display)
{//This api is for cal input parameter. Adaptive streaming case
	extern void get_adaptive_streaming_info_from_app(unsigned char display, unsigned short *p_width, unsigned short *p_height);
	int ap_act_w, ap_act_h, cur_act_w, cur_act_h , cal_act_w, cal_act_h, cal_start_x, cal_start_y;
	if(display == SLR_MAIN_DISPLAY){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n####Adaptive streaming before adjust x:%d y:%d w:%d h:%d####\n", Main_InputRegion_x, Main_InputRegion_y, Main_InputRegion_w, Main_InputRegion_h);
		if((Main_InputRegion_x == 0) && (Main_InputRegion_y == 0))
		{
			Main_InputRegion_w = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_WID_PRE);
			if(Scaler_DispGetStatus(display, SLR_DISP_INTERLACE))
				Main_InputRegion_h = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN_PRE)*2;
			else
				Main_InputRegion_h = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN_PRE);
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"#####Adaptive stream full size case####\n");
		}
		else
		{
			get_adaptive_streaming_info_from_app(display, (unsigned short *)&ap_act_w, (unsigned short *)&ap_act_h);
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"####get_adaptive_streaming_info_from_app ap_act_w:%d ap_act_h:%d####\n", ap_act_w, ap_act_h);
			if((ap_act_w == 0) || (ap_act_h == 0))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"####get_adaptive_streaming_info_from_app error zero data####\n");
				return;
			}
			cur_act_w = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPH_ACT_WID_PRE);//Orignal source size
			if(Scaler_DispGetStatus(display, SLR_DISP_INTERLACE))
				cur_act_h = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN_PRE)*2;//Orignal source size
			else
				cur_act_h = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_IPV_ACT_LEN_PRE);//Orignal source size
			if((ap_act_w != cur_act_w) || (ap_act_h != cur_act_h))
			{
				cal_act_w = cur_act_w * Main_InputRegion_w / ap_act_w;
				if(cal_act_w%2)
					cal_act_w --;
				Main_InputRegion_w = cal_act_w;
				cal_start_x = cur_act_w * Main_InputRegion_x / ap_act_w;
				Main_InputRegion_x = cal_start_x;
				cal_act_h = cur_act_h * Main_InputRegion_h / ap_act_h;
				Main_InputRegion_h = cal_act_h;
				cal_start_y = cur_act_h * Main_InputRegion_y / ap_act_h;
				Main_InputRegion_y = cal_start_y;
			}
			else
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"#####Adaptive stream case no need to adjust input para####\n");
			}
		}
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n####Adaptive streaming after adjust x:%d y:%d w:%d h:%d####\n", Main_InputRegion_x, Main_InputRegion_y, Main_InputRegion_w, Main_InputRegion_h);
	}
}


#ifdef CONFIG_SDNR_CROP

extern unsigned char rtk_hal_vsc_GetInputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * pinregion);
extern unsigned char rtk_hal_vsc_GetOutputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * poutregion);

//bFlag = 0: Width 1:Height
unsigned int getFactorUZD(unsigned int inVal, bool bFlag, unsigned char uDisplay)
{
	unsigned int uRetVal = 1;

#if 1
	uRetVal = inVal*1;
#else
	unsigned int uOutW = 1, uInW=1;
	unsigned int uOutH = 1, uInH=1;

	VIDEO_RECT_T inregion;
	VIDEO_RECT_T outregion;

	if(Scaler_AdaptiveStream_NewInputRegionFlagGet(uDisplay)){
		StructSrcRect newInput = cal_new_input_for_Adaptive(uDisplay);
		inregion.x = newInput.srcx;
		inregion.y = newInput.srcy;
		inregion.h = newInput.src_height;
		inregion.w = newInput.src_wid;
	}else{
		if(uDisplay == SLR_MAIN_DISPLAY)
		{
			inregion.x = Main_InputRegion_x;
			inregion.y = Main_InputRegion_y;
			inregion.w = Main_InputRegion_w;
			inregion.h = Main_InputRegion_h;
		}
		else
		{
#ifdef CONFIG_DUAL_CHANNEL
			inregion.x = Sub_InputRegion_x;
			inregion.y = Sub_InputRegion_y;
			inregion.w = Sub_InputRegion_w;
			inregion.h = Sub_InputRegion_h;
#endif
		}
	}

	if (rtk_hal_vsc_GetOutputRegion(uDisplay, &outregion))
	{
		uOutW = (unsigned int)outregion.w;
		uInW = (unsigned int)inregion.w;
		uOutH = (unsigned int)outregion.h;
		uInH = (unsigned int)inregion.h;


		#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
			if(Get_DisplayMode_Src(uDisplay) == VSC_INPUTSRC_AVD){
				uInW = Scaler_CalAVD27MWidth(uDisplay, uInW);
			}
		#endif
	}
	pr_debug("<=%s=%d=> inVal=%d \n", __FUNCTION__, __LINE__, inVal);

	//When Input size > Source or Output size > Panel, the value need to be changed
	unsigned int uSourceInW=1, uSourceInH=1;
	uSourceInW = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)uDisplay,SLR_INPUT_IPH_ACT_WID_PRE);
	if (Scaler_DispGetStatus(uDisplay, SLR_DISP_INTERLACE))
		uSourceInH = (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)uDisplay,SLR_INPUT_IPV_ACT_LEN_PRE)<<1);
	else
		uSourceInH = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)uDisplay,SLR_INPUT_IPV_ACT_LEN_PRE);

	if (uInW > uSourceInW)	{
		pr_warning("<=%s=%d=> AP_InW=%d Source_InW=%d\n", __FUNCTION__, __LINE__, uInW, uSourceInW);
		uInW = uSourceInW;
	}
	if (uInH > uSourceInH)	{
		pr_warning("<=%s=%d=> AP_InH=%d Source_InH=%d\n", __FUNCTION__, __LINE__, uInH, uSourceInH);
		uInH = uSourceInH;
	}
	if (uOutW > _DISP_WID)	{
		pr_warning("<=%s=%d=> AP_OutW=%d Panel_W=%d\n", __FUNCTION__, __LINE__, uOutW, _DISP_WID);
		uOutW = _DISP_WID;
	}
	if (uOutH > _DISP_LEN)	{
		pr_warning("<=%s=%d=> AP_OutH=%d Panel_H=%d\n", __FUNCTION__, __LINE__, uOutH, _DISP_LEN);
		uOutH = _DISP_LEN;
	}


	if (bFlag == SLR_SIZE_TYPE_WID)	//Width
	{
		if (uOutW < uInW)
			uRetVal = ((inVal * (unsigned int)uOutW * 100 / (unsigned int)uInW) + 55 )/100 ;
		else
			uRetVal = inVal*1;
	}
	else
	{
		if (uOutH < uInH)
			uRetVal = ((inVal * (unsigned int)uOutH * 100 / (unsigned int)uInH) + 55 )/100 ;
		else
			uRetVal = inVal*1;
	}
#endif
	pr_debug("<=%s=%d=> uRetVal=%d \n", __FUNCTION__, __LINE__, uRetVal);
	return uRetVal;
}
#endif
StructSrcRect cal_new_input_for_Adaptive(unsigned char display)
{
	//StructSrcRect m_dispwin = Scaler_DispWindowGet();
	StructSrcRect m_input_size = Scaler_AdaptiveStream_InputWindowGet();

	StructSrcRect NewInput2OldInput = m_input_size;
	//printk("[pool test]input info:x:%d,y:%d,wid:%d,len:%d\n",m_input_size.srcx,m_input_size.srcy,m_input_size.src_wid,m_input_size.src_height);
	unsigned int pre_len = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE) ;
	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE))
		pre_len *= 2;
	//check 4k2k input and output ,overflow
	if(_DISP_WID && _DISP_LEN){
		NewInput2OldInput.srcx = (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE) * m_input_size.srcx *100/_DISP_WID+ 50)/100;
		NewInput2OldInput.srcy = (pre_len * m_input_size.srcy *100/_DISP_LEN + 50)/100;
		NewInput2OldInput.src_wid = (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE) * m_input_size.src_wid*100/_DISP_WID + 50)/100;
		NewInput2OldInput.src_height = (pre_len *m_input_size.src_height * 100/_DISP_LEN + 50)/100;
	}

	if((NewInput2OldInput.srcx + NewInput2OldInput.src_wid) > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)){
		printk("[scaler][WARNING]new adaptive stream, wid is over size\n");
		NewInput2OldInput.src_wid = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE) - NewInput2OldInput.srcx;
	}

	if((NewInput2OldInput.srcy + NewInput2OldInput.src_height) > pre_len){
		printk("[scaler][WARNING]new adaptive stream, len is over size\n");
		NewInput2OldInput.src_height = pre_len - NewInput2OldInput.srcy;
	}
	//printk("[pool test]PRE:wid:%d,len:%d\n",Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE),Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
	//printk("[pool test]ACT:x:%d,y:%d,wid:%d,len:%d\n",NewInput2OldInput.srcx,NewInput2OldInput.srcy,NewInput2OldInput.src_wid,NewInput2OldInput.src_height);

	return NewInput2OldInput;
}



/* =====================================================*/
/* fw_scaler_cal_sdnr_capture
 * This function is used to handle some auto aspect ratio, including movies & subtitle */
/* =====================================================*/
#ifdef CONFIG_SDNR_CROP
unsigned char fw_scaler_cal_sdnr_capture(unsigned char display)
{
	unsigned char src;
	unsigned short Main_InputRegion_w_temp = Main_InputRegion_w;
	unsigned short Main_InputRegion_x_temp = Main_InputRegion_x;
	unsigned short Sub_InputRegion_w_temp = Sub_InputRegion_w;
	unsigned short Sub_InputRegion_x_temp = Sub_InputRegion_x;
	unsigned char colorspace=0;
	unsigned int uDI_WID = 0x00, uDI_LEN = 0x00;

	VIDEO_RECT_T inregion;
	VIDEO_RECT_T outregion;

	if (!rtk_hal_vsc_GetInputRegion(display, &inregion) || !rtk_hal_vsc_GetOutputRegion(display, &outregion))
		pr_err("Input or Output Region is wrong!!!!!!!\n");


	src = Scaler_InputSrcGetMainChType();

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Main_InputRegion_w_temp=%d, Main_InputRegion_x_temp=%d\n", Main_InputRegion_w_temp, Main_InputRegion_x_temp);
	#if 0
	printk(KERN_EMERG "SUB VD 27M mode=%d\n", fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)));
	printk(KERN_EMERG "SUB Display=%d\n", (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
	#endif

	if (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
	{	//
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, 0);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_DI_WID));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DI_LEN));


		StructSrcRect newInput = Scaler_AdaptiveStream_InputWindowGet();;
		if(Scaler_AdaptiveStream_NewInputRegionFlagGet(display)){
			newInput = cal_new_input_for_Adaptive(display);
		}else{
			newInput.srcx = Main_InputRegion_x_temp;
			newInput.srcy = Main_InputRegion_y;
			newInput.src_wid = Main_InputRegion_w_temp;
			newInput.src_height = Main_InputRegion_h;
		}
	
		// Just abbreviate for recognize easy
		uDI_WID = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DI_WID);
			
		// Corrected crop region W&X if HSD enable
		if (Scaler_Get_di_hsd_flag())	{
			if ((VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(display))&&(Get_DisplayMode_Src(display) == VSC_INPUTSRC_AVD)&&
				(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID) == AVD_27M_VGIP_WIDTH))	{
				// AV function had convertered zoom_crop_hpos&zoom_crop_hsize so that no need to calculate
			}
			else	{
				//uRetVal = ((inVal * (unsigned int)uOutW * 100 / (unsigned int)uInW) + 55 )/100 ;				
				newInput.srcx = (newInput.srcx * uDI_WID * 100 /  Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) + 55 ) / 100;
				newInput.src_wid = (newInput.src_wid* uDI_WID * 100 /  Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) + 55 ) / 100; 
			}
		}
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"newInput.srcx=%x, newInput.src_wid=%x\n", newInput.srcx, newInput.src_wid);
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"newInput.srcy=%x, newInput.src_height=%x\n", newInput.srcy, newInput.src_height);


		if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
			#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
				if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(display))
				{
					newInput.srcx = Scaler_CalAVD27MWidth((SCALER_DISP_CHANNEL)display, Main_InputRegion_x_temp);
					newInput.src_wid = Scaler_CalAVD27MWidth((SCALER_DISP_CHANNEL)display, Main_InputRegion_w_temp);
				}
			#endif
	
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, newInput.srcx);
				if (newInput.src_wid > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID))/*Not reasonable input*/
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
				else
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, newInput.src_wid);			
		} else {
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, newInput.srcx);
				if (newInput.src_wid > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID))/*Not reasonable input*/
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
				else
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, newInput.src_wid);
		}
		
	}else {
		if ((SCALER_DISP_CHANNEL)display == SLR_SUB_DISPLAY)
		{
			if (Get_Live_zoom_mode() == LIVE_ZOOM_SUB) {
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DI_WID));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DI_LEN));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, 0);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DI_WID));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_DI_LEN));
			} else {
			#if 1
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, 0);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DI_LEN));
			#else
				if (Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_INTERLACE)) {//sub interlace
				#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
					if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(display))
					{
						Sub_InputRegion_x_temp = Scaler_CalAVD27MWidth((SCALER_DISP_CHANNEL)display, Sub_InputRegion_x_temp);
						Sub_InputRegion_w_temp = Scaler_CalAVD27MWidth((SCALER_DISP_CHANNEL)display, Sub_InputRegion_w_temp);
					}
				#endif
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, Sub_InputRegion_x_temp);

					if ((Sub_InputRegion_w_temp == 0) || (Sub_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))/*Not reasonable input*/
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
					else
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Sub_InputRegion_w_temp);

					//SDNR available WIDTH/HEIGHT value is Enable width/height minuns offset x/y
			//		if (Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID))
			//			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, 0);	// protect

					if ((Sub_InputRegion_h == 0) || (Sub_InputRegion_h > (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1))) /*Not reasonable input*/
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN));
					else if(Scaler_DispGetStatus(display, SLR_DISP_THRIP)) {
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, Sub_InputRegion_y);
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Sub_InputRegion_h);
					} else {
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Sub_InputRegion_h/2);
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, Sub_InputRegion_y/2);
					}
			//		if (Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN))
			//			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);	// protect
				} else {//sub progressive
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, Sub_InputRegion_x_temp);
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, Sub_InputRegion_y);
	  				if(Sub_InputRegion_w_temp == 0 || (Sub_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))
		  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
	  				else
		  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Sub_InputRegion_w_temp);

				//	if (Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID))
				//		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, 0);	// protect

	  				if(Sub_InputRegion_h == 0 || (Sub_InputRegion_h > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)))
		  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DI_LEN));
	  				else
		  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Sub_InputRegion_h);

				//	if (Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN))
				//		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);	// protect
				}
			#endif
			}
		}
		else
		{		// SLR_MAIN_DISPLAY
			StructSrcRect newInput = Scaler_AdaptiveStream_InputWindowGet();;
			if(Scaler_AdaptiveStream_NewInputRegionFlagGet(display)){
				newInput = cal_new_input_for_Adaptive(display);
			}else{
				newInput.srcx = Main_InputRegion_x_temp;
				newInput.srcy = Main_InputRegion_y;
				newInput.src_wid = Main_InputRegion_w_temp;
				newInput.src_height = Main_InputRegion_h;
			}

			// Just abbreviate for recognize easy
			uDI_WID = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DI_WID);
			uDI_LEN = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_DI_LEN);
			
			// Corrected crop region W&X if HSD enable
			if (Scaler_Get_di_hsd_flag())	{
				if ((VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(display))&&(Get_DisplayMode_Src(display) == VSC_INPUTSRC_AVD)&&
					(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID) == AVD_27M_VGIP_WIDTH))	{
					// AV function had convertered zoom_crop_hpos&zoom_crop_hsize so that no need to calculate
				}
				else	{
					//uRetVal = ((inVal * (unsigned int)uOutW * 100 / (unsigned int)uInW) + 55 )/100 ;				
					newInput.srcx = (newInput.srcx * uDI_WID * 100 /  Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) + 55 ) / 100;
					newInput.src_wid = (newInput.src_wid* uDI_WID * 100 /  Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) + 55 ) / 100; 
				}
			}
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"newInput.srcx=%x, newInput.src_wid=%x\n", newInput.srcx, newInput.src_wid);
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"newInput.srcy=%x, newInput.src_height=%x\n", newInput.srcy, newInput.src_height);
			
			if (Get_Live_zoom_mode() == LIVE_ZOOM_SUB) {
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, 0);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DI_LEN));
			} else if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
			#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
				if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode(display))
				{
					newInput.srcx = Scaler_CalAVD27MWidth((SCALER_DISP_CHANNEL)display, Main_InputRegion_x_temp);
					newInput.src_wid = Scaler_CalAVD27MWidth((SCALER_DISP_CHANNEL)display, Main_InputRegion_w_temp);
				}
			#endif

  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, newInput.srcx);
  				if (newInput.src_wid > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID))/*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
  				else
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, newInput.src_wid);

				// No DI	=> corrected crop region H&Y
				if (!Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP)) {
					newInput.srcy = newInput.srcy/2;
					newInput.src_height = newInput.src_height/2; 
				}
				Scaler_DispSetInputInfo(SLR_INPUT_SDNRV_ACT_STA, newInput.srcy);				
  				if (newInput.src_height > (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN))) /*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN));
				else
	  				Scaler_DispSetInputInfo(SLR_INPUT_SDNRV_ACT_LEN, newInput.src_height);				
			} else {
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, newInput.srcx);
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, newInput.srcy);
  				if (newInput.src_wid > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID))/*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
  				else
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, newInput.src_wid);

  				if (newInput.src_height > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN))/*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN));
  				else
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, newInput.src_height);
			}
		}
	}

	colorspace=Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_COLOR_SPACE);
	if ( ((src == _SRC_HDMI) || (src == _SRC_VO)) &&
		 ((colorspace != VODMA_COLOR_YUV444) && (colorspace!= VODMA_COLOR_RGB)) ) {
	  	//This means that shift value need even <= need to do by SDNR side
		if((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA)%2) != (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE)%2))
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA) -1);//This means that shift value need even
	}

#ifdef CONFIG_I2RND_ENABLE
	//i2rnd resync disp info @Crixus 20160719
	if((display == SLR_MAIN_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){

  #ifdef CONFIG_SDNR_CROP
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, 0);
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);
		if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1);
		}else{
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
		}
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
	#endif
		printk(KERN_EMERG"[crixus]Resync disp info\n");
	}
#endif
	//protect data area
	if ((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA)+Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID)) >  Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)) {
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)-Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID));
	}
	if ((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA)+Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN)) >  Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN)) {
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN)-Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN));
	}
#if 1
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"SLR_INPUT_DI_WID=%d\n", Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID));
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"SLR_INPUT_DI_LEN=%d\n", Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN));
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"SLR_INPUT_SDNRH_ACT_STA=%d\n", Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA));
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"SLR_INPUT_SDNRH_ACT_WID=%d\n", Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID));
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"SLR_INPUT_SDNRV_ACT_STA=%d\n", Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA));
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"SLR_INPUT_SDNRV_ACT_LEN=%d\n", Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN));
#endif
	return TRUE;
}
#endif		//CONFIG_SDNR_CROP



/* =====================================================*/
/* fw_scaler_cal_vgip_capture
 * This function is used to handle some auto aspect ratio, including movies & subtitle */
/* =====================================================*/
unsigned char fw_scaler_cal_vgip_capture(unsigned char display)
{
	//unsigned short temp;
	//frank@1018 add below code to solve scan tool warning
	//stDISPLAY_OVERSCAN_DATA scan_data = {0, 0, 0, 0};
	//stVGIP_ADJUSTMENT_INFO adjustment_data;
	//SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode2();
	//unsigned char h_start_even_odd_flag;
	//unsigned char doOverscanFlag = FALSE;
	//UINT16 h_ratio = 0;
	//UINT16 v_ratio = 0;
	//unsigned char result = TRUE;
	//unsigned short interlaceStatus;
	//unsigned short AfterDILen;
	//unsigned char ucInputSrc;
	//StructSrcRect m_inputwin;
	unsigned char src;
	unsigned short Main_InputRegion_w_temp = Main_InputRegion_w;
	unsigned short Main_InputRegion_x_temp = Main_InputRegion_x;
	unsigned short Sub_InputRegion_w_temp = Sub_InputRegion_w;
	unsigned short Sub_InputRegion_x_temp = Sub_InputRegion_x;
	unsigned char colorspace=0;

#ifdef CONFIG_SDNR_CROP

	unsigned short usVal=0;
	VIDEO_RECT_T inregion;
	VIDEO_RECT_T outregion;

	if (!rtk_hal_vsc_GetInputRegion(display, &inregion) || !rtk_hal_vsc_GetOutputRegion(display, &outregion))
		pr_err("Input or Output Region is wrong!!!!!!!\n");
#endif

	src = Scaler_InputSrcGetMainChType();
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE

#ifdef CONFIG_SDNR_CROP

#else
       //if(VD_27M_OFF != fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)))
       if(VD_27M_OFF != fw_video_get_27mhz_mode(display))
      {
		if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) {
			Main_InputRegion_w_temp *= 2;
			Main_InputRegion_x_temp *= 2;
		}
		else {
			Sub_InputRegion_w_temp *= 2;
			Sub_InputRegion_x_temp *= 2;
		}
      }
#endif // end of #ifdef CONFIG_SDNR_CROP..else..

#endif

	#if 1
	printk(KERN_EMERG "file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
	printk(KERN_EMERG "Main_InputRegion_w_temp=%d, Main_InputRegion_x_temp=%d\n", Main_InputRegion_w_temp, Main_InputRegion_x_temp);
	printk(KERN_EMERG "SUB VD 27M mode=%d\n", fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)));
	printk(KERN_EMERG "SUB Display=%d\n", (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
	#endif

	if (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
	{
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA,Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID,Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
	}else {
	if ((SCALER_DISP_CHANNEL)display == SLR_SUB_DISPLAY) {
		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
		Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
		Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));

		// Abnormal Warning
		if (Sub_InputRegion_x_temp == 0)
			rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input Wid is ZERO!!!!!\n", __FUNCTION__, __LINE__);	
		if (Sub_InputRegion_h == 0)
			rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input Height is ZERO!!!!!\n", __FUNCTION__, __LINE__);
		if ((Sub_InputRegion_x_temp + Sub_InputRegion_w_temp) > Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE))	
			rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input W(%x) X(%d)	Source W(%x) !!!!!\n", __FUNCTION__, __LINE__, Sub_InputRegion_x_temp, Sub_InputRegion_w_temp, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE));	
		if (Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_INTERLACE))			{
			if ((Sub_InputRegion_y/2 + Sub_InputRegion_h/2) > Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE))
				rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input H(%x) Y(%x)	Source H(%x) !!!!!\n", __FUNCTION__, __LINE__, Sub_InputRegion_y, Sub_InputRegion_h, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));
		}
		else	{
			if ((Sub_InputRegion_y + Sub_InputRegion_h) > Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE))
				rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input H(%x) Y(%x)	Source H(%x) !!!!!\n", __FUNCTION__, __LINE__, Sub_InputRegion_y, Sub_InputRegion_h, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));			
		}
		
		if (Get_Live_zoom_mode() == LIVE_ZOOM_SUB)
		{
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA,0);
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, 0);
			//because main maybe later than sub,so sub can't get correct main sdnr size,so need set to di output(sdnr not do overscan,m domain do overscan),
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DI_WID));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN,Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DI_LEN));	
		}

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
		//else if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
		else if((VD_27M_OFF== fw_video_get_27mhz_mode(display)) && (get_sub_OutputVencMode()))
		{
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Sub_InputRegion_w_temp);//s4ap need vgip go overscan
		}
#endif
		else
		{
#ifdef CONFIG_SDNR_CROP
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
#endif

			if (Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_INTERLACE)) {
  #ifdef CONFIG_SDNR_CROP
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_WID));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN));
  #else
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE) + Sub_InputRegion_x_temp);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE) + Sub_InputRegion_y/2);
				if((Sub_InputRegion_w_temp == 0) || (Sub_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
				else
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Sub_InputRegion_w_temp);
				if((Sub_InputRegion_h == 0) || (Sub_InputRegion_h > (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1)))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
				else
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Sub_InputRegion_h/2);
  #endif
			} else {
  #ifdef CONFIG_SDNR_CROP
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_WID));
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN));
  #else
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE) + Sub_InputRegion_x_temp);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE) + Sub_InputRegion_y);
				if(Sub_InputRegion_w_temp == 0 || (Sub_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
				else
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Sub_InputRegion_w_temp);
				if(Sub_InputRegion_h == 0 || (Sub_InputRegion_h > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_IPV_ACT_LEN_PRE));
				else
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Sub_InputRegion_h);
  #endif
			}
		}

	} else {
		if (Get_Live_zoom_mode() == LIVE_ZOOM_SUB)
		{
			//printk("file=%s, function=%s, line=%d\n", __FILE__, __FUNCTION__, __LINE__);
#ifdef CONFIG_SDNR_CROP
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));

			//Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE));
			//Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE));
			//Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE));
			//Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE));

			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE), SLR_SIZE_TYPE_WID, display));
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE), SLR_SIZE_TYPE_LEN, display));
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, 0);
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);

			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE));

			if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE))
			{
	  			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1, 1, display));
	  			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1, 1, display));
			}
			else
			{
	  			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE), 1, display));
	  			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE), 1, display));
			}

			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE), 0, display));
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE), 0, display));
#else
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
#endif
		}
//#ifdef CONFIG_SDNR_CROP//sunray add for WOSQRTK-8296 and WOSQRTK-8469
#if 0  //beacause compiler error, fix me later
else if(VD_27M_OFF == fw_video_get_27mhz_mode(display) &&(Get_DisplayMode_Src(display) == VSC_INPUTSRC_AVD) ){

			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));

			if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {

  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE), SLR_SIZE_TYPE_WID, display));
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE), SLR_SIZE_TYPE_LEN, display));
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, getFactorUZD(Main_InputRegion_x_temp, SLR_SIZE_TYPE_WID, display));
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, getFactorUZD(Main_InputRegion_y, SLR_SIZE_TYPE_LEN, display));
  				if ((Main_InputRegion_w_temp == 0) || (Main_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))/*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE), SLR_SIZE_TYPE_WID, display));
  				else
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, getFactorUZD(Main_InputRegion_w_temp, SLR_SIZE_TYPE_WID, display));

				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE), SLR_SIZE_TYPE_WID, display));

				//SDNR available WIDTH/HEIGHT value is Enable width/height minuns offset x/y
				if ((Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID))
					||((Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID_PRE)<=(Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID)+Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_STA)))))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, 0);	// protect

  				if ((Main_InputRegion_h == 0) || (Main_InputRegion_h > (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1))) /*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN)<<1, SLR_SIZE_TYPE_LEN, display));
  				else
	  				Scaler_DispSetInputInfo(SLR_INPUT_SDNRV_ACT_LEN, getFactorUZD(Main_InputRegion_h, 1, display));

				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1, SLR_SIZE_TYPE_LEN, display));

				if ((Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN))
					||((Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN_PRE)<=(Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN)+Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_STA)))))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);	// protect

			} else {

  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE), SLR_SIZE_TYPE_WID, display));
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE), SLR_SIZE_TYPE_LEN, display));
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, getFactorUZD(Main_InputRegion_x_temp, SLR_SIZE_TYPE_WID, display));
  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, getFactorUZD(Main_InputRegion_y, SLR_SIZE_TYPE_LEN, display));
  				if ((Main_InputRegion_w_temp == 0) || (Main_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))/*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE), SLR_SIZE_TYPE_WID, display));
  				else
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID, getFactorUZD(Main_InputRegion_w_temp, SLR_SIZE_TYPE_WID, display));

				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_WID_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE), SLR_SIZE_TYPE_WID, display));

				//SDNR available WIDTH/HEIGHT value is Enable width/height minuns offset x/y
				if ((Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID))
					||((Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID_PRE)<=(Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_WID)+Scaler_DispGetInputInfo(SLR_INPUT_SDNRH_ACT_STA)))))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, 0);	// protect

  				if((Main_InputRegion_h == 0) || (Main_InputRegion_h > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)))/*Not reasonable input*/
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE), SLR_SIZE_TYPE_LEN, display));
  				else
	  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN, getFactorUZD(Main_InputRegion_h, SLR_SIZE_TYPE_LEN, display));

  				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_LEN_PRE, getFactorUZD(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE), SLR_SIZE_TYPE_LEN, display));

				//SDNR available WIDTH/HEIGHT value is Enable width/height minuns offset x/y
				if ((Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_STA) >= Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN))
					||((Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN_PRE)<=(Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_LEN)+Scaler_DispGetInputInfo(SLR_INPUT_SDNRV_ACT_STA)))))
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRV_ACT_STA, 0);	// protect

			}
		}
#endif
		else {

  #ifdef CONFIG_SDNR_CROP
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE));
			Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
  #endif
			StructSrcRect newInput = Scaler_AdaptiveStream_InputWindowGet();;
			if(Scaler_AdaptiveStream_NewInputRegionFlagGet(display)){
				newInput = cal_new_input_for_Adaptive(display);
			}else{
				newInput.srcx = Main_InputRegion_x_temp;
				newInput.srcy = Main_InputRegion_y;
				newInput.src_wid = Main_InputRegion_w_temp;
				newInput.src_height = Main_InputRegion_h;
			}
			if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
				if (!(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))) {
					newInput.src_height /= 2;
					newInput.srcy /= 2;
				}
			}

			// Abnormal Warning
			if (newInput.src_wid == 0)
				rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input Wid is ZERO!!!!!\n", __FUNCTION__, __LINE__);	
			if (newInput.src_height == 0)
				rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input Height is ZERO!!!!!\n", __FUNCTION__, __LINE__);
			if ((newInput.srcx + newInput.src_wid) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE))	
				rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input W(%x) X(%d)  Source W(%x) !!!!!\n", __FUNCTION__, __LINE__, newInput.srcx, newInput.src_wid, Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));	
			if ((newInput.srcy + newInput.src_height) > Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE))
				rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s=%d] Input H(%x) Y(%x)  Source H(%x) !!!!!\n", __FUNCTION__, __LINE__, newInput.srcy, newInput.src_height, Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
			
			if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) {
  #ifdef CONFIG_SDNR_CROP
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID));
				if (Scaler_DispGetStatus(display, SLR_DISP_THRIP)) {
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN)<<1);
				} else {
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN));
				}
  #else
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE) + Main_InputRegion_x_temp);
				Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE) + Main_InputRegion_y/2);
				if ((Main_InputRegion_w_temp == 0) || (Main_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))/*Not reasonable input*/
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
				else
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Main_InputRegion_w_temp);
				if ((Main_InputRegion_h == 0) || (Main_InputRegion_h > (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)<<1)))/*Not reasonable input*/
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
				else
					Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN, Main_InputRegion_h/2);
  #endif
			} else {
  #ifdef CONFIG_SDNR_CROP
  					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_WID, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID));
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DI_LEN, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN));
  #else
  			#ifdef NEW_ADAPTIVE_STREAM_OVERSCAN
  				if(Scaler_InputSrcGetMainChType() == _SRC_VO && vsc_get_adaptivestream_flag() == 1){
					StructSrcRect m_dispwin = Scaler_DispWindowGet();
					StructSrcRect m_input_size = Scaler_AdaptiveStream_InputWindowGet();

					//printk("[pool test]input info:x:%d,y:%d,wid:%d,len:%d\n",m_input_size.srcx,m_input_size.srcy,m_input_size.src_wid,m_input_size.src_height);
					//printk("[pool test]diplay info:x:%d,y:%d,wid:%d,len:%d\n",m_dispwin.srcx,m_dispwin.srcy,m_dispwin.src_wid,m_dispwin.src_height);

					//check 4k2k input and output ,overflow
					if(m_dispwin.src_wid && m_dispwin.src_height){
						int new_overscan_x = (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE) * m_input_size.srcx *100/m_dispwin.src_wid + 50)/100;
						int new_overscan_y = (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE) * m_input_size.srcy *100/m_dispwin.src_height + 50)/100;
						int new_overscan_wid = (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE) * m_input_size.src_wid*100/m_dispwin.src_wid + 50)/100;
						int new_overscan_len = (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE) *m_input_size.src_height * 100/m_dispwin.src_height + 50)/100;
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE) + new_overscan_x);
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE) + new_overscan_y);
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, new_overscan_wid);
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, new_overscan_len);
					}

					unsigned short IPH_ACT_STA = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA);
					unsigned short IPV_ACT_STA = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA);
					unsigned short IPV_ACT_LEN = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_IPV_ACT_LEN);
					unsigned short IPV_ACT_WID = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_IPH_ACT_WID);
					//printk("[pool test]PRE:wid:%d,len:%d\n",Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE),Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
					//printk("[pool test]ACT:x:%d,y:%d,wid:%d,len:%d\n",IPH_ACT_STA,IPV_ACT_STA,IPV_ACT_WID,IPV_ACT_LEN);
				}else
			#endif
				{
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE) + Main_InputRegion_x_temp);
					Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE) + Main_InputRegion_y);
					if ((Main_InputRegion_w_temp == 0) || (Main_InputRegion_w_temp > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE)))/*Not reasonable input*/
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
					else
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Main_InputRegion_w_temp);
					if((Main_InputRegion_h == 0) || (Main_InputRegion_h > Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE)))/*Not reasonable input*/
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
					else
						Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Main_InputRegion_h);
				}
  #endif
			}
		}
	}
	}

	colorspace=Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_COLOR_SPACE);
	if ( ((src == _SRC_HDMI) || (src == _SRC_VO)) &&
		 ((colorspace != VODMA_COLOR_YUV444) && (colorspace!= VODMA_COLOR_RGB)) ) {
  #ifdef CONFIG_SDNR_CROP
  		//if((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA)%2) != (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE)%2))
	  	//	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_SDNRH_ACT_STA) -1);//This means that shift value need even
	  	//This means that shift value need even <= need to do by SDNR side
  #else
		if((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA)%2) != (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE)%2))
			Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA) -1);//This means that shift value need even
  #endif
	}

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() &&
		((Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF)|| (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING) || (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM)))
	{
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA_PRE));
		Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN, Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE));
		Scaler_Disp3dSetInfo(display, SLR_DISP_3D_H_RATIO,100);
		Scaler_Disp3dSetInfo(display, SLR_DISP_3D_V_RATIO,100);
	}

	printk(KERN_EMERG"[crixus]Resync disp info\n");
	return TRUE;
}

/*api which have protect by forcebg_semaphore*/
void drvif_scalerdisplay_enable_display(unsigned char display, unsigned char bEnable)
{
	if(display == SLR_MAIN_DISPLAY) {
		ppoverlay_main_display_control_rsv_RBUS reg_display_control_rsv;
		reg_display_control_rsv.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		reg_display_control_rsv.m_disp_en = bEnable;
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, reg_display_control_rsv.regValue);
		drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
	}
	else {
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		ppoverlay_mp_layout_force_to_background_RBUS reg_layout_force_to_background;
		reg_layout_force_to_background.regValue = IoReg_Read32(PPOVERLAY_MP_Layout_Force_to_Background_reg);
		reg_layout_force_to_background.s_disp_en = bEnable;
		IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, reg_layout_force_to_background.regValue);
		drvif_scalerdisplay_set_dbuffer_en(SLR_SUB_DISPLAY, FALSE);
#endif
	}

	if(bEnable)
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_SHOW,TRUE);
	else
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_SHOW,FALSE);
}


void drvif_scalerdisplay_subdisplay_hidenfunc(unsigned char bEnable)
{
	unsigned char tmp;
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);
	ppoverlay_mp_layout_force_to_background_RBUS reg_layout_force_to_background;
	reg_layout_force_to_background.regValue = IoReg_Read32(PPOVERLAY_MP_Layout_Force_to_Background_reg);
	if (bEnable)
		reg_layout_force_to_background.s_disp_en = 0;
	else
		reg_layout_force_to_background.s_disp_en = 1;
	IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, reg_layout_force_to_background.regValue);
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT4);
	tmp = 0;
	while(IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT4){
		msleep(10);
		if(++tmp>10)
			break;
	}

	IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);
}

/*api which have protect by forcebg_semaphore*/
void drvif_scalerdisplay_set_dbuffer_en(SCALER_DISP_CHANNEL display, int En)
{
	unsigned long flags;//for spin_lock_irqsave
	if (display == SLR_MAIN_DISPLAY) {
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock

		if(En) {
			IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2|_BIT0);
		} else {
			IoReg_Mask32(PPOVERLAY_Double_Buffer_CTRL_reg, ~_BIT2, 0);
		}
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	} else {
		if(En) {
			IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6|_BIT4);
		} else {
			IoReg_Mask32(PPOVERLAY_Double_Buffer_CTRL_reg, ~_BIT6, 0);
		}
	}
}

void drvif_scalerdisplay_force_black_bg(unsigned char Enable)
{
	scaleup_d_uzu_patgen_color0_RBUS scaleup_d_uzu_patgen_color0_reg;
	scaleup_d_uzu_patgen_color1_RBUS scaleup_d_uzu_patgen_color1_reg;
	scaleup_d_uzu_globle_ctrl_RBUS scaleup_d_uzu_globle_ctrl_reg;
	unsigned int value = IoReg_Read32(SCALEUP_D_UZU_Globle_Ctrl_reg);
	if(Enable && !(value&_BIT0)) {
		scaleup_d_uzu_patgen_color0_reg.regValue = 0;
		scaleup_d_uzu_patgen_color0_reg.patgen_c0_cr = 0x80;
		scaleup_d_uzu_patgen_color0_reg.patgen_c0_cb = 0x80;
		IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR0_reg, scaleup_d_uzu_patgen_color0_reg.regValue);

		scaleup_d_uzu_patgen_color1_reg.regValue = 0;
		scaleup_d_uzu_patgen_color1_reg.patgen_c1_cr = 0x80;
		scaleup_d_uzu_patgen_color1_reg.patgen_c1_cb = 0x80;
		IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR1_reg, scaleup_d_uzu_patgen_color1_reg.regValue);

		scaleup_d_uzu_globle_ctrl_reg.regValue = IoReg_Read32(SCALEUP_D_UZU_Globle_Ctrl_reg);
		scaleup_d_uzu_globle_ctrl_reg.patgen_mode = 4;//Pattern 100 bit6
		scaleup_d_uzu_globle_ctrl_reg.patgen_sel = 1;
		IoReg_Write32(SCALEUP_D_UZU_Globle_Ctrl_reg, scaleup_d_uzu_globle_ctrl_reg.regValue);
	} else if(!Enable && (value&_BIT0)) {
		IoReg_BusyCheckRegBit(PPOVERLAY_DTG_pending_status_reg, _BIT0, 0x1FFFF);
		scaleup_d_uzu_globle_ctrl_reg.regValue = IoReg_Read32(SCALEUP_D_UZU_Globle_Ctrl_reg);
		scaleup_d_uzu_globle_ctrl_reg.patgen_mode = 4;//Pattern 100 bit6
		IoReg_Write32(SCALEUP_D_UZU_Globle_Ctrl_reg, scaleup_d_uzu_globle_ctrl_reg.regValue);
	}

}

unsigned char drvif_scalerdisplay_get_force_bg_status()
{
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	if((IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg) & _BIT18) || (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) & (_BIT1))) {
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		return TRUE;
	} else {
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		return FALSE;
	}
}

#if 0
void drvif_scalerdisplay_force_bg(SCALER_DISP_CHANNEL disp, unsigned char Enable)
{

#ifndef CONFIG_ENABLE_OSD_SUBTITLE
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
 	unsigned short  temp;
#endif
#endif
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n###%s disp:%d enable:%d##\r\n",__FUNCTION__, disp, Enable);
	if (Enable){	// enable force-to-background
#ifdef CONFIG_ENABLE_OSD_SUBTITLE
		//Wait Display Data enable end period
		IoReg_BusyCheckRegBit(PPOVERLAY_DTG_pending_status_reg, _BIT0, 0x1FFFF);
		//Set Display pattern black color
		IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR0_reg, 0x8080);
		IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR1_reg, 0x8080);
		if (disp) {// Sub
			IoReg_Mask32(SCALEUP_D_UZU_Globle_Ctrl_reg, 0xffffff8c, _BIT6|_BIT1);
		}else{
			IoReg_Mask32(SCALEUP_D_UZU_Globle_Ctrl_reg, 0xffffff8c, _BIT6|_BIT0);
		}
#else
		drvif_scalerdisplay_set_bg_color(disp, _DISPLAY_BG, Scaler_DispGetInputInfo(SLR_INPUT_BGCOLOR_R),  Scaler_DispGetInputInfo(SLR_INPUT_BGCOLOR_G),  Scaler_DispGetInputInfo(SLR_INPUT_BGCOLOR_B));
		/*WaitFor_DEN_STOP();*/
		fw_scaler_dtg_double_buffer_enable(1);
		if (disp) {// Sub
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
 			temp = IoReg_ReadWord1(PPOVERLAY_MP_Layout_Force_to_Background_reg) | Scaler_PipGetSubInfo(SLR_PIP_SUB_MPHIIDX);
 			IoReg_Mask32(PPOVERLAY_MP_Layout_Force_to_Background_reg, 0x0000ffff, (temp << 16)|_BIT1);
#endif
		} else {  // Main
			//frank@0810 mask interrupt status bit IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1);
			IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) | _BIT1));
 			IoReg_Write32(PPOVERLAY_Display_Background_Color_reg, 0x00);
 			IoReg_Write32(PPOVERLAY_Display_Background_Color_2_reg, 0x00);
			IoReg_Mask32(SUBTOVL_Mixer_CTRL1_reg, ~(_BIT4), _BIT4);
			drvif_scalerdisplay_force_black_bg(Enable);
			//Brian-20120524-Clear dtg bit18 to prevent background force black
			IoReg_Mask32(PPOVERLAY_Display_Timing_CTRL1_reg, ~_BIT18, 0);
		}
		fw_scaler_dtg_double_buffer_apply();
		//frank@0903 reduce time fw_scaler_dtg_double_buffer_enable(0);
		/*drvif_scalerdisplay_set_dbuffer_en(FALSE);*/
#endif

	} else {	// disable force-to-background
#ifdef CONFIG_ENABLE_OSD_SUBTITLE
		//Wait Display Data enable end period
		IoReg_BusyCheckRegBit(PPOVERLAY_DTG_pending_status_reg, _BIT0, 0x1FFFF);
		IoReg_Mask32(SCALEUP_D_UZU_Globle_Ctrl_reg, 0xffffff8c, _BIT6);
#else
		if (disp) {// Sub
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
 			temp = IoReg_ReadWord1(PPOVERLAY_MP_Layout_Force_to_Background_reg)  & (~ Scaler_PipGetSubInfo(SLR_PIP_SUB_MPHIIDX));
			IoReg_Mask32(PPOVERLAY_SUB_Background_Color1_reg, 0xc000c000, 0);	// set G & B as 0
			IoReg_Mask32(PPOVERLAY_SUB_Background_Color2_reg, 0xffffc000, 0);  // set R as 0

 			IoReg_Mask32(PPOVERLAY_MP_Layout_Force_to_Background_reg, 0x0000fffd, (temp << 16));
#endif
		} else {  // Main
			drvif_scalerdisplay_force_black_bg(Enable);
			IoReg_Mask32(SUBTOVL_Mixer_CTRL1_reg, ~(_BIT4), 0);
			IoReg_Mask32(PPOVERLAY_Main_Background_Color1_reg, 0xc000c000, 0);	// set G & B as 0
			IoReg_Mask32(PPOVERLAY_Main_Background_Color2_reg, 0xffffc000, 0);  // set R as 0
 			//frank@0810 mask interrupt status bit IoReg_ClearBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1);
 			IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) & ~(_BIT1)));
			IoReg_Mask32(PPOVERLAY_Display_Timing_CTRL1_reg, ~_BIT18, 0);
	//		Scaler_SetMainBGColor();  // decide  to display or not  for main background color
		}
//		WaitFor_DEN_STOP();
		/*drvif_scalerdisplay_set_dbuffer_en(FALSE);*/
#endif
	}
}
#endif

//This function is used for getting main/sub width, height and position.
void fw_scaler_get_main_and_sub_info(stWINDOW *MainWinInfo, stWINDOW *SubWinInfo)
{
	unsigned short SubWidth = 0, SubLength = 0, SubHpos = 0, SubVpos = 0;

	MainWinInfo->HStart = Hstart;
	MainWinInfo->HWidth = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_WID);
	MainWinInfo->HEnd = Hstart + MainWinInfo->HWidth;
	MainWinInfo->VStart = Vstart;
	MainWinInfo->VLength = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_LEN);
	MainWinInfo->VEnd = Vstart + MainWinInfo->VLength;

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	//get sub window info.
	PipMp_GetPipSize((eSubType)Scaler_PipGetInfo(SLR_PIP_TYPE), &SubWidth, &SubLength);
	PipMp_GetPipPos((ePipPos)Scaler_PipGetInfo(SLR_PIP_POSITION), (eSubType)Scaler_PipGetInfo(SLR_PIP_TYPE), &SubHpos, &SubVpos);
#endif

	SubWinInfo->HStart = SubHpos;
	SubWinInfo->HWidth = SubWidth;
	SubWinInfo->HEnd = SubHpos + SubWidth;
	SubWinInfo->VStart = SubVpos;
	SubWinInfo->VLength = SubLength;
	SubWinInfo->VEnd = SubVpos + SubLength;
}

void drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_SELECT dma_clk_sel, DISP_DCLK_SELECT dclk_sel)
{
#if 0
	sys_dispclksel_RBUS sys_dispclksel_reg;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K){
		return;
	}
	if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX){
		return;
	}

	fw_scaler_dtg_double_buffer_enable(1);
	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	sys_dispclksel_reg.dispd_memc_out_sel = dclk_sel;
	WaitFor_DEN_STOP();
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);
	printf("[SLR] set_dclk_sel=%x\n", sys_dispclksel_reg.regValue);
	fw_scaler_dtg_double_buffer_apply();
	fw_scaler_dtg_double_buffer_enable(0);
#endif
}

#ifdef CONFIG_MINI_LVDS
#define rtd_maskl(x, y, z)	IoReg_Mask32(x, y, z)
#define rtd_outl(x, y)		IoReg_Write32(x, y)

static void scaler_finetune_tcon_alog_do(unsigned int dh_total, unsigned int dv_total, unsigned int dh_start, unsigned int dv_start )
{
#if defined(TV011UI_1) && defined(OPEN_CELL_PANEL)
	//PAD_GPIO_14									 //
	rtd_maskl(PINMUX_GPIO_CFG_3_VADDR,0xffff0fff,0x0000f000); // PAD_GPIO_14	   //0x1800_080C[15:12]
	rtd_maskl(MIS_GP0DIR_reg,0xffffbfff,0x00004000); //IO_Set: 		0x1801BC00[14]
	rtd_maskl(MIS_GP0DATO_reg,0xffffbfff,0x00000000); //GPO_Set:	  0x1801BC14[14]

	//=====================================================================================================

	//---------- PIF ------------------------------------------------------------------
	rtd_outl(PANEL_INTERFACE_LVDS_CTRL4_VADDR, 0x0360040);	 //LVDS 4 port power off (for mini-LVDS)
	rtd_outl(PANEL_INTERFACE_TYPE3_CTRL1_VADDR, 0x02503bf);	 //2-to-4, line buffer size =1920/2-1=959, type 3
	//rtd_outl(PPOVERLAY_Display_Timing_CTRL2_reg, 0x0000437);	 //

	//---------- LVDS pin share ------------------------------------------------------------------

	rtd_outl(PINMUX_LVDS_CFG_0_VADDR, 0x00000000);	 //LVDS pin share
	rtd_outl(PINMUX_LVDS_CFG_1_VADDR, 0x00000000);	 //LVDS pin share
	rtd_outl(PINMUX_LVDS_CFG_2_VADDR, 0x00003000);	 //LVDS pin share
	rtd_outl(PINMUX_LVDS_CFG_3_VADDR, 0x00000000);	 //LVDS pin share
	rtd_outl(PINMUX_LVDS_CFG_4_VADDR, 0x00000000);	 //LVDS pin share
	rtd_outl(PINMUX_LVDS_CFG_5_VADDR, 0x00000000);	 //LVDS pin share
	rtd_outl(PINMUX_LVDS_CFG_6_VADDR, 0x00000000);	 //LVDS pin share
	rtd_outl(PINMUX_LVDS_CFG_7_VADDR, 0x00000000);	 //LVDS pin share

	//---------- mini-LVDS analog ----------------------------------------------------------

	rtd_outl(PINMUX_LVDS_PLL_CTRL_0_VADDR, 0x00300300);	 //A-port B-pair for for bit[23:12], C-port B-pair clock phase for bit[11:0]
	rtd_outl(PINMUX_LVDS_PLL_CTRL_1_VADDR, 0xAF000000);	 //TX PLL feedback x8: 74.25*8=594MHz, mini-LVDS Clock=TX PLL clock/2=297
	rtd_outl(PINMUX_LVDS_PLL_CTRL_2_VADDR, 0x0F2233CF);	 //phase adject enable
	rtd_outl(PINMUX_LVDS_MISC_CTRL_0_VADDR, 0x000000f5);	 // mini-LVDS 8-bit data

	//---------- mini-LVDS setting ----------------------------------------------------------

	rtd_outl(PANEL_INTERFACE_MLVDS_CTRL0_VADDR, 0x00000061);  //mini-LVDS, 8-bit, 2-port 6-pair
	rtd_outl(PANEL_INTERFACE_MLVDS_CTRL1_VADDR, 0xFFAA8080);  //TCON0 Merge Reset pulse

	// ---------Edward modify --------------------------------------
	rtd_outl(PANEL_INTERFACE_MLVDS_CTRL0_VADDR, 0x00000071);	 // LR swap
	rtd_outl(PANEL_INTERFACE_TYPE3_CTRL1_VADDR, 0x002d03bf);	 // H-flip
	rtd_outl(PPOVERLAY_Display_Timing_CTRL2_reg, 0x0000049D);	 // pixel swap

	//=====================================================================================================
	//rtd_outl(PPOVERLAY_Display_Background_Color_reg,0x00FFFFFF);

	// TCON Pin share
	rtd_outl(PINMUX_LVDS_CFG_4_VADDR,0x43000000);
	rtd_outl(PINMUX_LVDS_CFG_6_VADDR,0x00004040);
	rtd_outl(PINMUX_LVDS_CFG_7_VADDR,0x40400000);
	rtd_outl(PINMUX_LVDS_CFG_0_VADDR,0x40000000);

	rtd_outl(PANEL_INTERFACE_TCON_CTRL_VADDR,00000000);  // TCON global disable

	// STV; W21; TCON5;
	rtd_outl(PANEL_INTERFACE_TCON5_HSE_VADDR,0x0386018B);	 // HST = 1077; HEND = 664;
	rtd_outl(PANEL_INTERFACE_TCON5_VSE_VADDR,0x00120014);	 // VST = 10; VEND = 12;
	rtd_outl(PANEL_INTERFACE_TCON5_CTRL_VADDR,0x00000180);	 // Across Line1 Mode;

	// STV1; Y25; TCON14;
	rtd_outl(PANEL_INTERFACE_TCON14_HSE_VADDR,0x052e0380);	 // HST = 1326; HEND = 896;
	rtd_outl(PANEL_INTERFACE_TCON14_VSE_VADDR,0x00140016);	 // VST = 12; VEND = 14;
	rtd_outl(PANEL_INTERFACE_TCON14_CTRL_VADDR,0x00001080);	 // Across Line1 Mode;

	// CPV; M22; TCON13;
	rtd_outl(PANEL_INTERFACE_TCON13_HSE_VADDR,0x087700c0);	 // HST = 44; HEND = 2050;
	rtd_outl(PANEL_INTERFACE_TCON13_VSE_VADDR,0x00000546);	 // VST = 0; VEND = 1350;
	rtd_outl(PANEL_INTERFACE_TCON13_CTRL_VADDR,0x00000080);	 // Normal Mode + Inverse TCON;

	// TP; P25; TCON2;

	rtd_outl(PANEL_INTERFACE_TCON2_HSE_VADDR,0x083e002e);	 // HST = 2; HEND = 1024;
	rtd_outl(PANEL_INTERFACE_TCON2_VSE_VADDR,0x00000546);	 // VST = 18; VEND = 182;
	rtd_outl(PANEL_INTERFACE_TCON2_CTRL_VADDR,0x00000080);	 // Across Line2 Mode;

	// OE; N22; TCON7;
	rtd_outl(PANEL_INTERFACE_TCON7_HSE_VADDR,0x014C0831);	 // HST = 140; HEND = 1960;
	rtd_outl(PANEL_INTERFACE_TCON7_VSE_VADDR,0x00000546);	 // VST = 0; VEND = 1350;
	rtd_outl(PANEL_INTERFACE_TCON7_CTRL_VADDR,0x00000080);	 // Normal Mode;

	// POL; R21; TCON3;
	rtd_outl(PANEL_INTERFACE_TCON3_HSE_VADDR,0x07E007E0);	 // HST = 2016; HEND = 2016;
	rtd_outl(PANEL_INTERFACE_TCON3_VSE_VADDR,0x00090009);	 // VST = 9; VEND = 9;
	rtd_outl(PANEL_INTERFACE_TCON3_CTRL_VADDR,0x00000480);	 // Across Frame Mode
	rtd_outl(PANEL_INTERFACE_TCON3_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR,0x00000000);	 // initial Value = 0
	rtd_outl(PANEL_INTERFACE_TCON3_ACROSS_FRAME_CONTROL_VADDR,0x00000000);	 // 1 Frame Toggle

	// reset pulse; TCON0;
	rtd_outl(PANEL_INTERFACE_TCON0_HSE_VADDR,0x0080008A);	 // HST = 1384; HEND = 2010;
	rtd_outl(PANEL_INTERFACE_TCON0_VSE_VADDR,0x00000546);	 // VST = 0; VEND = 1126;
	rtd_outl(PANEL_INTERFACE_TCON0_CTRL_VADDR,0x00000080);	 // Normal Mode;

	rtd_outl(PANEL_INTERFACE_TCON_CTRL_VADDR,0x00000003);	 // TCON enable

	if(drvif_scaelr3d_decide_is_3D_display_mode() == TRUE){
		// change brightness & contrast
		// disable VGIP interrupt
		//IoReg_Mask32(VGIP_INT_CTL_reg, ~_BIT3, 0);
		// disable YUV2RGB control doubl buffer
		//IoReg_Mask32(YUV2RGB_D_YUV2RGB_CONTROL_VADDR, ~_BIT3, 0);
		//WaitFor_DEN_STOP();

		//IoReg_Write32(YUV2RGB_D_YUV2RGB_TAB1_DATA_0_VADDR, 0x000201A9);
		//IoReg_Write32(YUV2RGB_D_YUV2RGB_TAB1_DATA_2_VADDR, 0x00840420);
		//IoReg_Write32(YUV2RGB_D_YUV2RGB_TAB1_DATA_3_VADDR, 0x00000420);

		// change brightness & contrast
		// disable VGIP interrupt
		//IoReg_Mask32(VGIP_INT_CTL_reg, ~_BIT3, _BIT3);
		// disable YUV2RGB control doubl buffer
		//IoReg_Mask32(YUV2RGB_D_YUV2RGB_CONTROL_VADDR, ~_BIT3, _BIT3);
		WaitFor_DEN_STOP();

		// 3D OD handler
		//===== [wen] begin OD table setting (enter 3D mode) =====
		//================================
		WaitFor_DEN_STOP();
		IoReg_Write32(0xb802C31C, 0x00401FA3);  // Cap setting
		IoReg_Write32(0xb802C33C, 0x1FA32020);  // Disp setting
		IoReg_Write32(0xb802C344, 0x00000000);  // Line step
		IoReg_Write32(0xb802C338, 0x00078040);  // Pixel num
		IoReg_Write32(0xb802C348, 0x00000438);  // Line num

		msleep(50);
		WaitFor_DEN_STOP();
		IoReg_Write32(0xb802C310, 0x00000040);  // Compression 8 bits

		// Cap and Disp en
		IoReg_Write32(0xb802C318, 0x01092020);  // Cap enable
		IoReg_Write32(0xb802C330, 0x00000003);  // Disp enable

		WaitFor_DEN_STOP();
		IoReg_Write32(0xb802C308, 0x20000000);  // OD enable
	//	IoReg_Write32(0xb802C360, 0x00004000);  // OD gain
		//IoReg_Write32(0xb802C108, 0x000000A0);  // gamma table 2 enable
		WaitFor_DEN_STOP();
		//===== [wen] end OD table setting =====

		//reset 3D gamma table
		//Scaler_Set_3D_Gamma_Table();

		// STV1; Y25; TCON14;
		IoReg_Write32(PANEL_INTERFACE_TCON14_HSE_VADDR,0x052e0380);		// HST = 1326; HEND = 896;
		IoReg_Write32(PANEL_INTERFACE_TCON14_VSE_VADDR,0x00140016);		// VST = 12; VEND = 14;
		IoReg_Write32(PANEL_INTERFACE_TCON14_CTRL_VADDR,0x00001000);		// Across Line1 Mode; --> TCON14 disable for 3D mode
		// POL; R21; TCON3;
		IoReg_Write32(PANEL_INTERFACE_TCON3_HSE_VADDR,0x07E007E0);		// HST = 2016; HEND = 2016;
		IoReg_Write32(PANEL_INTERFACE_TCON3_VSE_VADDR,0x00090009);		// VST = 9; VEND = 9;
		IoReg_Write32(PANEL_INTERFACE_TCON3_CTRL_VADDR,0x00000480);		// Across Frame Mode
		IoReg_Write32(PANEL_INTERFACE_TCON3_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR,0x00000000);		// initial Value = 0
		IoReg_Write32(PANEL_INTERFACE_TCON3_ACROSS_FRAME_CONTROL_VADDR,0x00000001);		// 2 Frame Toggle --> for 3D mode
		// TCON Pin share
		IoReg_Write32(PINMUX_LVDS_CFG_2_VADDR,0x00003000);	// Ball W21 is Tcon1 function
		// 3D_LR_Vsync; W21; TCON1;
		IoReg_Write32(PANEL_INTERFACE_TCON1_HSE_VADDR,0x07E007E0);		// HST = 2016; HEND = 2016;
		IoReg_Write32(PANEL_INTERFACE_TCON1_VSE_VADDR,0x00000000);		// VST = 9; VEND = 9;
		IoReg_Write32(PANEL_INTERFACE_TCON1_CTRL_VADDR,0x000004C0);		// Scaning backlight: Across Frame Mode; Tcon enable (3D)
		// GVON--> Glass; P24; TCON10+TCON9;
		// TCON10
		IoReg_Write32(PANEL_INTERFACE_TCON10_HSE_VADDR,0x03500800);		// HST = 848; HEND = 2048;
		IoReg_Write32(PANEL_INTERFACE_TCON10_VSE_VADDR,0x02D80003);		// VST = 728; VEND = 3;
		IoReg_Write32(PANEL_INTERFACE_TCON10_CTRL_VADDR,0x00000381);		// Across Line3 Mode + TCON10 "OR" TCON9; Tcon enable (3D)
		IoReg_Write32(PANEL_INTERFACE_TCON10_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR,0x00030002);
		// TCON9
		IoReg_Write32(PANEL_INTERFACE_TCON9_HSE_VADDR,0x07E007E0);		// HST = 2016; HEND = 2016;
		IoReg_Write32(PANEL_INTERFACE_TCON9_VSE_VADDR,0x00000000);		// VST = 9; VEND = 9;
		//rtd_outl(0xb802D110,0x000004C0);		// Across Frame Mode
		IoReg_Write32(PANEL_INTERFACE_TCON9_ACROSS_LINE_CONTROL3_ACROSS_FRAME_CONTROL_VADDR,0x00000000);		// initial Value = 0
		IoReg_Write32(PANEL_INTERFACE_TCON9_ACROSS_FRAME_CONTROL_VADDR,0x00000000);		// 1 Frame Toggle
		// 2D_3D_Select
		IoReg_Mask32(PINMUX_GPIO_CFG_2_VADDR,0x0FFFFFFF,0XF0000000);
		IoReg_Mask32(MIS_GP0DATO_reg,0xFFFFFEFF,0x00000000);

		// GPIO 79 Interrupt enable --  Enable when in 3D mode
		IoReg_SetBits(MIS_GP2IE_reg, _BIT15); //bit[15]=1, MIS_GPIO_bit79 Assert/Dis-assert Interrupt Enable

	}

#endif

 // // add tcon fine tune api here
}


void  fw_scaler_finetune_tcon(void)
{
	dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	dv_total_RBUS dv_total_reg;
	ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	unsigned int dh_total, dv_total, h_start, v_start;

	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dh_total = dh_total_last_line_length_reg.dh_total;
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dv_total = dv_total_reg.dv_total;
	dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
	h_start = dh_den_start_end_reg.dh_den_sta;
	dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
	v_start = dv_den_start_end_reg.dv_den_sta;

	if(drvif_scaler_get_display_mode() == 1){  //run framesync mode need to recal dvtotal.
		// Since the 3ddma is no be enabled, dv total should not be changed
		if((Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE())
			&& ((Scaler_InputSrcGetMainChType() == _SRC_VO) && drvif_scaelr3d_decide_is_3D_display_mode()
			&& (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC) == TRUE)))
		{
			;// DO NOT NEED DO DV TOTAL MEASURE AGAIN, when VO source display timing in frame sync mode (re-measure will cause OSD flicker issue)
		}else
			dv_total = hardware_measure_dvtotal();
	}

	scaler_finetune_tcon_alog_do(dh_total,dv_total,h_start,v_start);

	}

#endif


unsigned char fw_scaler_check_color_space_in_rgb(void)
{
	unsigned char result;

	result = (Scaler_InputSrcGetMainChType() == _SRC_VGA)
			|| ((Scaler_InputSrcGetMainChType()== _SRC_HDMI) && ((drvif_IsHDMI() == MODE_DVI) || (drvif_Hdmi_GetColorSpace() == COLOR_RGB)));

	return result;
}


// disable vip function in 4k2k video mode
void  fw_scaler_4k2k_color_config(void)
{
#if defined(ENABLE_QUADFHD)
	//if((IoReg_Read32(0xB801bc3c) & _BIT15))
	{

                if(QuadFHD::GetInstance()->GetCurQuadFHDMode() == QUADFHD_VIDEO_MODE || QuadFHD::GetInstance()->GetCurQuadFHDMode() == QUADFHD_PHOTO_MODE){
                    /* Disable the sharpness and nr while in the QuadFHD mode */
		IoReg_Write32(0xb8023600,0x00000200); //I-Dither
		    IoReg_Write32(0xb8023128,0x00000000);//mark for PQ setting for M3 0723 //I-h mpeg nr
		    IoReg_Write32(0xb8024254,0x00000000);//mark for PQ setting for M3 0723//I-v mpeg nr
		    IoReg_Write32(0xb8029404,0x00000000);//mark for PQ setting for M3 0723// disable SPNR
		    IoReg_Write32(0xb802942c,0x00000000);//mark for PQ setting for M3 0723// disable D-v mpeg nr
		    IoReg_Write32(0xb8023170,0x00000000);//mark for PQ setting for M3 0723// disable idlti
		//check 0xb8029004[31:30]=0  //disable adaptive uzu

		    IoReg_Write32(0xb802902c,0x00000000);//mark for PQ setting for M3 0723 // disable supk
		    IoReg_Write32(0xb8029080,0x00000000); //mark for PQ setting for M3 0723// disable unsharp mask

		    //rtd_outl(0xb802a000,0x4000000C); //modify for PQ setting for M3 0723
		    IoReg_Write32(COLOR_D_VC_Global_CTRL_reg,0x0600008C); //disable sharpness,modify for PQ setting for M3 0723
                    IoReg_Write32(0xb802c500,0x00000000); // disable dither

		//IoReg_Write32(0xb802a000,0x40000009);// disable vv color (0717_DarwinPQ_CMI_setting, DCC_on, ICM_on) //IoReg_Write32(0xb802a000,0x00000000); // disable vv color

		//IoReg_Write32(0xb802c000,0x00000010);//mark for PQ setting for M3 0723 // disable srgb
		//IoReg_Write32(0xb802c108,0x00000040);//mark for PQ setting for M3 0723 // enable gamma (0717_DarwinPQ_CMI_setting)  //IoReg_Write32(0xb802c108,0x00000000); // disable gamma

		//IoReg_Write32(0xb802a800,0x40000000);//mark for PQ setting for M3 0723  // con bri
		//IoReg_Write32(0xb802a820,0x00000000);//mark for PQ setting for M3 0723  // con bri

		// RGB color input -- bypass RGB to YUV module
		//IoReg_Write32(0xb8023000,0x00000128);//mark for PQ setting for M3 0723  // rgb2yuv
		if(fw_scaler_check_color_space_in_rgb()){
			// RGB color input -- bypass YUV to RGB module
			//rtd_outl(0xb802a700,00000042); // yuv2rgb
			//printk(KERN_INFO "[4k2k][RGB], src/hdmi/color=%d/%d/%d\n", Scaler_InputSrcGetMainChType(), drvif_IsHDMI(), drvif_Hdmi_GetColorSpace());
		}
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[4k2k] Vip disabled!!\n");


		//add for PQ setting for M3_0723
		//=======================================================
		di_im_di_rtnr_control_RBUS di_im_di_rtnr_control_RBUS_reg;
		di_im_di_rtnr_control_RBUS_reg.regValue = IoReg_Read32(DI_IM_DI_RTNR_CONTROL_reg);
		di_im_di_rtnr_control_RBUS_reg.cp_rtnr_y_enable = 0;
		di_im_di_rtnr_control_RBUS_reg.cp_rtnr_c_enable = 0;
		IoReg_Write32(DI_IM_DI_RTNR_CONTROL_reg, di_im_di_rtnr_control_RBUS_reg.regValue);
		//============================================================

		msleep(100);
	}
	}

	if(modestate_get_isForceEnableRTNR()){
	  	di_im_di_rtnr_control_RBUS di_im_di_rtnr_control_RBUS_reg;

	  	di_im_di_rtnr_control_RBUS_reg.regValue = IoReg_Read32(DI_IM_DI_RTNR_CONTROL_reg);
	  	di_im_di_rtnr_control_RBUS_reg.cp_rtnr_y_enable = 1;
	  	IoReg_Write32(DI_IM_DI_RTNR_CONTROL_reg, di_im_di_rtnr_control_RBUS_reg.regValue);//rtnr

		// disable 444to422 low pass filter to avoid first pixel error (error will be observed in R-frame)
		di_im_di_control_RBUS di_im_di_control_RBUS_reg;
		di_im_di_control_RBUS_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
		di_im_di_control_RBUS_reg.di444to422lowpass = 0;// write_enable[20]

		/* henry @ mac5 161219 DI write enable bit */
		//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_7_mask;
		di_im_di_control_RBUS_reg.write_enable_7 = 1;
		IoReg_Write32(DI_IM_DI_CONTROL_reg, di_im_di_control_RBUS_reg.regValue);

		// [FIX-ME][4k2k] shift for RTNR VO over capture
		vgip_vgip_chn1_act_hsta_width_RBUS vgip_chn1_act_hsta_width_reg;
		vgip_chn1_act_hsta_width_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
		vgip_chn1_act_hsta_width_reg.ch1_ih_act_sta += VO_4K2K_OVER_CAP_PIXEL;
		IoReg_Write32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg, vgip_chn1_act_hsta_width_reg.regValue);
	}

#endif
	return;
}


void drvif_scalerdisplay_set_sharpness_line_mode(void)
{
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;

	display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	//if(_DISP_WID < 1920){
		display_timing_ctrl2_reg.shpnr_line_mode = 0;
	//}else{
		//display_timing_ctrl2_reg.shpnr_line_mode = 4;
	//}
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE," display_timing_ctrl2_reg : %x \n", display_timing_ctrl2_reg.regValue);

	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);
}
/*
#ifdef VBY_ONE_PANEL

void drvif_scalerdisplay_config_vby1_sfg()
{
	UINT8 pixel_mode;

	sfg_sfg_ctrl_7_RBUS    sfg_ctrl_7_reg;
	sfg_sfg_ctrl_9_RBUS    sfg_ctrl_9_reg;

	pixel_mode = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE);

	sfg_ctrl_9_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_9_VADDR);
	sfg_ctrl_7_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_7_VADDR);

	sfg_ctrl_7_reg.hsync_delay = (_DISP_WID/(pixel_mode*2))+24;
	sfg_ctrl_9_reg.sfg_dh_den_sta = (Get_DISP_DEN_STA_HPOS() /(pixel_mode*2));
	sfg_ctrl_9_reg.req_start = (Get_DISP_DEN_STA_HPOS() /(pixel_mode*2))-6;

	IoReg_Write32(SFG_SFG_CTRL_9_VADDR, sfg_ctrl_9_reg.regValue);
	IoReg_Write32(SFG_SFG_CTRL_7_VADDR, sfg_ctrl_7_reg.regValue);
}
void drvif_scalerdisplay_turn_off_vby1_power()
{
	phy0_aphy_03_RBUS phy0_aphy_03_reg;	//0xb802d6d8
	phy1_aphy_03_RBUS phy1_aphy_03_reg;	//0xb802d6f8
	transmit_control_RBUS transmit_control_reg; //0xb802d610

	phy0_aphy_03_reg.regValue = IoReg_Read32(VBY1_PHY0_APHY_03_VADDR);
	phy0_aphy_03_reg.vby1tx_pow_0 = 0;
	phy0_aphy_03_reg.vby1tx_powlv_0= 0;
	phy0_aphy_03_reg.vby1tx_pll_pow_0 = 0;
	phy0_aphy_03_reg.vby1tx_pll_ldo_pow_0 = 0;
	IoReg_Write32(VBY1_PHY0_APHY_03_VADDR, phy0_aphy_03_reg.regValue);

	phy1_aphy_03_reg.regValue = IoReg_Read32(VBY1_PHY1_APHY_03_VADDR);
	phy1_aphy_03_reg.vby1tx_pow_1 = 0;
	phy1_aphy_03_reg.vby1tx_powlv_1 = 0;
	phy1_aphy_03_reg.vby1tx_pll_ldo_pow_1 = 0;
	phy1_aphy_03_reg.vby1tx_pll_pow_1 = 0;
	IoReg_Write32(VBY1_PHY1_APHY_03_VADDR, phy1_aphy_03_reg.regValue);

	transmit_control_reg.regValue = IoReg_Read32(VBY1_TRANSMIT_CONTROL_VADDR);
	transmit_control_reg.reg_en = 0;
	IoReg_Write32(VBY1_TRANSMIT_CONTROL_VADDR, transmit_control_reg.regValue);


}
#endif
*/
#if 0 // move to ap
//#ifdef _LVDS_OUTPUT_TO_MILLET3_PANEL
//static unsigned long long m_TCON_I2C_DEVICE_ADDR = 0x70;	//millet3 slave address
static unsigned long long m_TCON_I2C_DEVICE_ADDR = 0x1C;	//millet3 slave address

static unsigned long long m_TCON_I2C_MASTER = 2;
extern "C"{
	int communicateToWatchDog();
}

void drvif_scalerdisplay_I2CSettingToMillet(MILLET_I2C_INPUT_FORMAT command)
{
    UINT8 dat[9] = {0};
/*
    dat[0] = 0x26;
    dat[1] = 0x38;
    dat[2] = 0x64;
    dat[3] = 0xfd;
    dat[4] = 0x00;
    dat[5] = 0x00;
    dat[6] = 0x00;
    dat[7] = 0x00;

    dat[8] = 0x01;	// 4ch lvds


    if (m_TCON_I2C_DEVICE_ADDR) {
	    if (I2C_Write_EX(m_TCON_I2C_MASTER, m_TCON_I2C_DEVICE_ADDR, sizeof(dat), dat, 0) != S_OK) {
	        printk(KERN_INFO "[I2CSettingToMillet] I2C Write fail 1\n");
	    }
    }

    msleep(500);
*/

	if(Get_DISPLAY_PANEL_CUSTOM_INDEX() ==  VBY_ONE_PANEL_INX8901_4K2K_VBY1){
		UINT8 snedCmd;

		if(command == _INPUT_2K_1K)
			snedCmd = 0x1;
		else
			snedCmd = 0x3;


	    dat[0] = 0x26;
	    dat[1] = 0x38;
	    dat[2] = 0x50;
	    dat[3] = 0x6e;
	    dat[4] = 0x00;	//write
	    dat[5] = 0x00;
	    dat[6] = 0x10;	//video mode
	    dat[7] = 0x00;

	    dat[8] = snedCmd;
	}
	else{
	    dat[0] = 0x26;
	    dat[1] = 0x38;
	    dat[2] = 0x50;
	    dat[3] = 0x6d;
	    dat[4] = 0x00;	//write
	    dat[5] = 0x00;
	    dat[6] = 0x00;
	    dat[7] = 0x00;

	    dat[8] = command;
	}

    if (m_TCON_I2C_DEVICE_ADDR) {
		//if (I2C_Write_EX(m_TCON_I2C_MASTER, m_TCON_I2C_DEVICE_ADDR, sizeof(dat), dat, 0) != S_OK) {
		//    printk(KERN_INFO "[I2CSettingToMillet] I2C Write fail 2\n");
		//}

		for (int i=0; i<10; i++) {
	    if (I2C_Write_EX(m_TCON_I2C_MASTER, m_TCON_I2C_DEVICE_ADDR, sizeof(dat), dat, 0) != S_OK) {
				printk(KERN_INFO "\033[1;33m %s %s %d: I2C_Write_EX NG, try again --%d\033[m\n", __FILE__, __FUNCTION__, __LINE__, i);
				msleep(40);	//re-try no need busy wait 	//important!! one write cycle must delay 5~10ms, must not be removed
				communicateToWatchDog();
				if (i==9) {
					printk(KERN_INFO "\033[1;31m %s %s %d: [I2CSettingToMillet] I2C Write fail 2\033[m\n", __FILE__, __FUNCTION__, __LINE__);
				}
			}
			else {
				//S_OK, leave re-try
				break;
			}
	    }
    }
}



UINT32 drvif_scalerdisplay_MilletI2C_Read(UINT16 addr)
{
    UINT8 dat[6] = {0};
    UINT8 readData[5] = {0};
    UINT32 ret = 0;


    dat[0] = 0x26;
    dat[1] = 0x38;
    dat[2] = 0x06;
    dat[3] = 0x00;
    dat[4] = (addr & 0xff00)>>8;	//addr MSB
    dat[5] = (addr & 0xff); 	//addr LSB


    if (m_TCON_I2C_DEVICE_ADDR) {
	    if (I2C_Read_EX(m_TCON_I2C_MASTER, m_TCON_I2C_DEVICE_ADDR, 6, dat, 5, readData, 0) != S_OK) {
	        printk(KERN_INFO "[I2CSettingToMillet] I2C Read fail\n");
	    }
    }

    ret = (readData[0]<<24 | readData[1]<<16 | readData[2]<<8 | readData[3]);

   if(	readData[4] == (dat[2]^dat[3]^dat[4]^dat[5]^readData[0] ^readData[1] ^readData[2]^readData[3]) )
   	printk(KERN_INFO "Check Sun OK!\n");
   else
   	printk(KERN_INFO "Check Sun Fail!\n");

    printk(KERN_INFO "Addr (%x), readData (%x.%x.%x.%x), ret : (%x) \n", addr, readData[0], readData[1], readData[2], readData[3], ret);

    return ret;
}


UINT32 drvif_scalerdisplay_MilletI2C_Write(UINT16 addr, UINT32 data)
{
    UINT8 dat[10] = {0};
    UINT8 readData[5] = {0};
    UINT32 ret = 0;


    dat[0] = 0x26;
    dat[1] = 0x38;
    dat[2] = 0x07;
    dat[3] = 0x00;
    dat[4] = (addr & 0xff00)>>8;	//addr MSB
    dat[5] = (addr & 0xff); 	//addr LSB
    dat[6] = (data & 0xff000000) >> 24;
    dat[7] = (data & 0x00ff0000) >> 16;
    dat[8] = (data & 0x0000ff00) >> 8;
    dat[9] = (data & 0x000000ff);

    if (m_TCON_I2C_DEVICE_ADDR) {
	    if (I2C_Write_EX(m_TCON_I2C_MASTER, m_TCON_I2C_DEVICE_ADDR, sizeof(dat), dat, 0) != S_OK) {
	        printk(KERN_INFO "[I2CSettingToMillet] I2C Write fail\n");
		 ret = 0;
	    }
    }
    ret = 1;

    return ret;
}
#endif

void scaler_Millet3_LVDS_output_control(unsigned char bootMode)
{//This is no used
#if 0
	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 0)
		return;

	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[Setting Millet3] step1...\n");

	scalerdisplay_set_main_ctrl();
	scalerdisplay_set_main_display_window(0, _DISP_WID, 0, _DISP_LEN, 0);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[Setting Millet3] step2...\n");

	{
		ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
		ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;

		// update DV enable start/end
		dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
		if(ABS(dv_den_start_end_reg.dv_den_end, Get_DISP_DEN_END_VPOS()) > 100){
			dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
			dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
			IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);
		}

		dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
		dh_den_start_end_reg.dh_den_sta = Get_DISP_DEN_STA_HPOS() & 0x1fff;
		dh_den_start_end_reg.dh_den_end = Get_DISP_DEN_END_HPOS() & 0x1fff;
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, dh_den_start_end_reg.regValue);
	}

	drvif_scalerdisplay_set_sharpness_line_mode();
	/*WaitFor_DEN_STOP();*/

	{
		ppoverlay_display_timing_ctrl1_RBUS 	display_timing_ctrl1_reg;
		ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;

		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

		if(display_timing_ctrl1_reg.disp_fsync_en == 0){
			ppoverlay_dv_total_RBUS dv_total_reg;

			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"last line need equal to h_total total \n");
			dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
			dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL()- 1)& 0x00001fff;
			dh_total_last_line_length_reg.dh_total_last_line = dh_total_last_line_length_reg.dh_total;
			IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);

			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
			dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1) & 0x00001fff;
			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
		} // [FIX-ME] VO 3D: data FRC with timing frame sync condition
#ifdef ENABLE_DRIVER_I3DDMA
		else if(drvif_scaelr3d_decide_is_3D_display_mode() && (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE)
			&& (drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_SRC_TYPE) == _SRC_VO) && (Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) != SLR_3DMODE_2D_CVT_3D))
		{
			// Reset DH_Total to avoid 4k2k/2k1k display timing change fail issue
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[3D][VO] reset h_total\n");
			dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
			dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL()- 1)& 0x00001fff;
			dh_total_last_line_length_reg.dh_total_last_line = dh_total_last_line_length_reg.dh_total;
			IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
		}
#endif
		else{
			dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
			if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1){
				dh_total_last_line_length_reg.dh_total_last_line	= (dh_total_last_line_length_reg.dh_total_last_line | 0x3); //last line total msut 4x

				if(dh_total_last_line_length_reg.dh_total_last_line <= 0x1d)
					dh_total_last_line_length_reg.dh_total_last_line = 0x1f;
			}
			IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
		}
   	}

	{
		unsigned int tmp;
		IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);
		tmp = 0;
		while(IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0){
			msleep(2);
			if(++tmp>30)
				break;
		}
		IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[Setting Millet3] step3...\n");
	/*WaitFor_DEN_STOP();*/
	drvif_scalerdisplay_SFG_Setup();
	return;
#endif
}

void scaler_dtg_reconfig(void)
{
#ifndef VBY_ONE_PANEL
	ppoverlay_dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;
#endif
	ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	unsigned int tmp;
	unsigned long flags;//for spin_lock_irqsave
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	//IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[scaler_dtg_reconfig] dtg 0xb802800c ~ 0xb8028018\n");

#if 0	// sirius not support SR mode
//#ifdef VBY_ONE_PANEL
	DISPLAY_SR_MODE sr_mode;

	sr_mode = (DISPLAY_SR_MODE) Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_SR_MODE);

	if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() &&
		((Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)<SLR_3D_SIDE_BY_SIDE_HALF_CVT_2D) || (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)==SLR_3D_2D_CVT_3D))){
		if(sr_mode == SR_H2_V1){	// 4k2k 120Hz
			printk(KERN_INFO "[scaler_dtg_reconfig] Hx2 Vx1 re-config dvtotal\n");

			dv_total_RBUS dv_total_reg;
			IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
			dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() /2) - 1;
			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

			dv_den_start_end_RBUS dv_den_start_end_reg;
			dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
			dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS()/2;
			dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS()/2;
			IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);

			//0xb8028114, 0xb802811c
			main_den_v_start_end_RBUS main_den_v_start_end_reg;
			main_den_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_DEN_V_Start_End_reg);
			main_den_v_start_end_reg.mv_den_sta = 0;
			main_den_v_start_end_reg.mv_den_end = _DISP_LEN/2;
			IoReg_Write32(PPOVERLAY_MAIN_DEN_V_Start_End_reg, main_den_v_start_end_reg.regValue);

			main_background_v_start_end_RBUS main_background_v_start_end_reg;
			main_background_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);
			main_background_v_start_end_reg.mv_bg_sta = 0;
			main_background_v_start_end_reg.mv_bg_end = _DISP_LEN/2;
			IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);

			//0xb8028120, 0xb8028124
			main_active_v_start_end_RBUS main_active_v_start_end_reg;
			main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
			main_active_v_start_end_reg.mv_act_sta = 0;
			main_active_v_start_end_reg.mv_act_end = _DISP_LEN/2;
			IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);

			return;
		}
	}
#endif

	{
#ifndef VBY_ONE_PANEL
		//vtotal set by framesync measure
		//0xb802800c, 0xb8028014, 0xb8028018
		dh_total_last_line_length_reg.regValue = 0;
		dh_total_last_line_length_reg.dh_total = (Get_DISP_HORIZONTAL_TOTAL() - 1) & 0x01fff;
		dh_total_last_line_length_reg.dh_total_last_line = (Get_DISP_HORIZONTAL_TOTAL() - 1) & 0x01fff;
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);

		dv_total_reg.regValue = 0;
		dv_total_reg.dv_total = (Get_DISP_VERTICAL_TOTAL() - 1);
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
#endif
		dh_den_start_end_reg.regValue = 0;
		dh_den_start_end_reg.dh_den_sta = Get_DISP_DEN_STA_HPOS() & 0x1fff;
		dh_den_start_end_reg.dh_den_end = Get_DISP_DEN_END_HPOS() & 0x1fff;
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, dh_den_start_end_reg.regValue);

		dv_den_start_end_reg.regValue = 0;
		if(Scaler_OpenVOGating())
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Get_DISP_DEN_STA_VPOS : %d \n",Get_DISP_DEN_STA_VPOS());
			if((Get_DISP_HORIZONTAL_TOTAL() >2150) && (Get_DISP_HORIZONTAL_TOTAL() <2250)) //FHD panel
			{
				//for data framesync fail issue
				if(Get_DISP_DEN_STA_VPOS() < 0x15){
					unsigned int back_porch_offset = 0x15 - Get_DISP_DEN_STA_VPOS();
					dv_den_start_end_reg.dv_den_sta = 0x15;
					dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS()+ back_porch_offset;
					rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s][%s][%d] back_porch_offset : %d \n", __FILE__, __FUNCTION__, __LINE__, back_porch_offset);
				}
			}else{
				dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
				dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
			}
		}
		else{
			dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
			dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
		}
		IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);

#if 0
		//0xb8028110, 0xb8028118
		main_den_h_start_end_RBUS main_den_h_start_end_reg;
		main_den_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_DEN_H_Start_End_reg);
		main_den_h_start_end_reg.mh_den_sta = 0;
		main_den_h_start_end_reg.mh_den_end = _DISP_WID;
		IoReg_Write32(PPOVERLAY_MAIN_DEN_H_Start_End_reg, main_den_h_start_end_reg.regValue);

		main_background_h_start_end_RBUS main_background_h_start_end_reg;
		main_background_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_H_Start_End_reg);
		main_background_h_start_end_reg.mh_bg_sta = 0;
		main_background_h_start_end_reg.mh_bg_end = _DISP_WID;
		IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, main_background_h_start_end_reg.regValue);


		//0xb8028114, 0xb802811c
		main_den_v_start_end_RBUS main_den_v_start_end_reg;
		main_den_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_DEN_V_Start_End_reg);
		main_den_v_start_end_reg.mv_den_sta = 0;
		main_den_v_start_end_reg.mv_den_end = _DISP_LEN;
		IoReg_Write32(PPOVERLAY_MAIN_DEN_V_Start_End_reg, main_den_v_start_end_reg.regValue);

		main_background_v_start_end_RBUS main_background_v_start_end_reg;
		main_background_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);
		main_background_v_start_end_reg.mv_bg_sta = 0;
		main_background_v_start_end_reg.mv_bg_end = _DISP_LEN;
		IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);


		//0xb8028120, 0xb8028124
		/*main_active_h_start_end_RBUS main_active_h_start_end_reg;
		main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
		main_active_h_start_end_reg.mh_act_sta = 0;
		main_active_h_start_end_reg.mh_act_end = _DISP_WID;
		IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);*/

		main_active_v_start_end_RBUS main_active_v_start_end_reg;
		main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
		main_active_v_start_end_reg.mv_act_sta = 0;
		main_active_v_start_end_reg.mv_act_end = _DISP_LEN;
		IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);
#endif
	}

	//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2|_BIT0);
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	tmp = 0;
	while(IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0){
		msleep(2);
		if(++tmp>30)
			break;
	}
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	return;
}
#ifdef CONFIG_TEST_SCALER_DFRC

void scaler_dtg_reconfig_by_sr_mode(unsigned char srmode)
{//This is no used.
#if 0
	unsigned char h_factor;
	unsigned char v_factor;
	unsigned int tmpData;
	dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	dv_total_RBUS dv_total_reg;
	ppoverlay_dh_den_start_end_RBUS dh_den_start_end_reg;
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	ppoverlay_main_den_h_start_end_RBUS main_den_h_start_end_reg;
	ppoverlay_main_background_h_start_end_RBUS main_background_h_start_end_reg;
	ppoverlay_main_den_v_start_end_RBUS main_den_v_start_end_reg;
	ppoverlay_main_background_v_start_end_RBUS main_background_v_start_end_reg;
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

	if(srmode == SR_H2_V2){
		h_factor = 2;
		v_factor = 2;
	}else if(srmode == SR_H1_V2){
		h_factor = 1;
		v_factor = 2;
	}else if(srmode == SR_H2_V1){
		h_factor = 2;
		v_factor = 1;
	}else{
		h_factor = 1;
		v_factor = 1;
	}

	IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[scaler_dtg_reconfig] dtg 0xb802800c ~ 0xb8028018\n");

	{	//0xb802800c, 0xb8028014, 0xb8028018
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
		tmpData = dh_total_last_line_length_reg.dh_total;
		tmpData = (tmpData+1)/h_factor;
		dh_total_last_line_length_reg.dh_total = (tmpData-1);
		dh_total_last_line_length_reg.dh_total_last_line = dh_total_last_line_length_reg.dh_total;
		IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);

		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dv_total_reg.dv_total /= v_factor;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);

		dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
		dh_den_start_end_reg.dh_den_sta /= h_factor;
		dh_den_start_end_reg.dh_den_end /= h_factor;
		IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, dh_den_start_end_reg.regValue);

		dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
		dv_den_start_end_reg.dv_den_sta /= v_factor;
		dv_den_start_end_reg.dv_den_end /= v_factor;
		IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[scaler_dtg_reconfig] mtg 0xb8028110 ~ 0xb8028124\n");
	{	//0xb8028110, 0xb8028118
		main_den_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_DEN_H_Start_End_reg);
		main_den_h_start_end_reg.mh_den_sta /= h_factor;
		main_den_h_start_end_reg.mh_den_end /= h_factor;
		IoReg_Write32(PPOVERLAY_MAIN_DEN_H_Start_End_reg, main_den_h_start_end_reg.regValue);

		main_background_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_H_Start_End_reg);
		main_background_h_start_end_reg.mh_bg_sta /= h_factor;
		main_background_h_start_end_reg.mh_bg_end /= h_factor;
		IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, main_background_h_start_end_reg.regValue);
	}

	{	//0xb8028114, 0xb802811c
		main_den_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_DEN_V_Start_End_reg);
		main_den_v_start_end_reg.mv_den_sta /= v_factor;
		main_den_v_start_end_reg.mv_den_end /= v_factor;
		IoReg_Write32(PPOVERLAY_MAIN_DEN_V_Start_End_reg, main_den_v_start_end_reg.regValue);

		main_background_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);
		main_background_v_start_end_reg.mv_bg_sta /= v_factor;
		main_background_v_start_end_reg.mv_bg_end /= v_factor;
		IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, main_background_v_start_end_reg.regValue);
	}

	{	//0xb8028120, 0xb8028124
		/*main_active_h_start_end_RBUS main_active_h_start_end_reg;
		main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
		main_active_h_start_end_reg.mh_act_sta /= h_factor;
		main_active_h_start_end_reg.mh_act_end /= h_factor;
		IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, main_active_h_start_end_reg.regValue);*/

		main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);
		main_active_v_start_end_reg.mv_act_sta /= v_factor;
		main_active_v_start_end_reg.mv_act_end /= v_factor;
		IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, main_active_v_start_end_reg.regValue);
	}

	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2|_BIT0);
#endif
	return;
}
//#endif
#endif

#if 0  //mark for driver base by qing_liu
// [PA-168] PixelWorks PA168 4k2k TCON control
void scaler_PixelWorks_PA168_set_LvdsInutFmt(PA168_LVDS_INPUT_FMT lvdsFmt)
{
	UINT8 msg[2];

	msg[0] = PA168_I2C_CMD_LVDS_FMT;
	msg[1] = lvdsFmt;
	I2C_Write_EX(3, PA168_I2C_SLAVE_ID, 2, msg, 0);
	printk(KERN_INFO "[PA168] Set LVDS Fmt=%d\n", lvdsFmt);

	return;
}


void scaler_PixelWorks_PA168_set_MEMC_demoMode(PA168_MEMC_DEMO_MODE mode)
{
	UINT8 msg[2];

	msg[0] = PA168_I2C_CMD_MEMC_DEMO;
	msg[1] = mode;
	I2C_Write_EX(3, PA168_I2C_SLAVE_ID, 2, msg, 0);

	return;
}



void scaler_PixelWorks_PA168_captureDisable(unsigned char mode)
{
	UINT8 msg[2];

	msg[0] = PA168_I2C_CMD_CAPTURE_OFF;
	msg[1] = mode;
	I2C_Write_EX(3, PA168_I2C_SLAVE_ID, 2, msg, 0);
	printk(KERN_INFO "[PA168] Cap OFF=%d\n", mode);
	return;
}


void scaler_PixelWorks_PA168_lvdsDisable(unsigned char mode)
{
	pif_lvds_ctrl3_RBUS  lvds_ctrl3_reg;

	lvds_ctrl3_reg.regValue = IoReg_Read32(PIF_LVDS_CTRL3_reg);

	if(mode){
		// disable PA168 capture before shutdown LVDS signal
		scaler_PixelWorks_PA168_captureDisable(_ENABLE);

		// LVDS disable
		IoReg_Mask32(PIF_LVDS_CTRL3_reg, ~0xf0, 0);
		printk(KERN_INFO "[PA168] Lvds Down\n");
		msleep(50);
	}else{
		// LVDS resume
		if((_DISP_WID <= 1920) || (_DISP_LEN <= 1080)){
			lvds_ctrl3_reg.lvds_aport_en = 0;
			lvds_ctrl3_reg.lvds_bport_en = 0;
		}else{
			lvds_ctrl3_reg.lvds_aport_en = 1;
			lvds_ctrl3_reg.lvds_bport_en = 1;
		}
//		lvds_ctrl3_reg.lvds_cport_en = 1;
//		lvds_ctrl3_reg.lvds_dport_en = 1;
		msleep(50);
		IoReg_Write32(PIF_LVDS_CTRL3_reg, lvds_ctrl3_reg.regValue);
		printk(KERN_INFO "[PA168] Lvds ON\n");

		// enable PA168 capture after resume LVDS signal
		scaler_PixelWorks_PA168_captureDisable(_DISABLE);
	}

	return;
}


void scaler_PixelWorks_PA168_powerReset(unsigned char onOff)
{
	UINT8 msg[2];

	msg[0] = PA168_I2C_CMD_RESET;
	msg[1] = onOff;
	I2C_Write_EX(3, PA168_I2C_SLAVE_ID, 2, msg, 0);

	printk(KERN_INFO "[PA168] Power[%d]\n", onOff);
	return;
}
#endif

// SFG setup
void drvif_scalerdisplay_SFG_Setup(void)
{
#if 0
	sfg_sfg_ctrl_a_RBUS	sfg_ctrl_a_reg;
	sfg_sfg_ctrl_9_RBUS    sfg_ctrl_9_reg;
	sfg_sfg_ctrl_8_RBUS    sfg_ctrl_8_reg;
	sfg_sfg_ctrl_7_RBUS    sfg_ctrl_7_reg;
	sfg_sfg_ctrl_6_RBUS    sfg_ctrl_6_reg;
	sfg_sfg_ctrl_0_RBUS    sfg_ctrl_0_reg;
	sfg_sfg_swap_ctrl0_RBUS sfg_swap_ctrl0_reg;
	sfg_sfg_swap_ctrl1_RBUS sfg_swap_ctrl1_reg;
//	sfg_swap_ctrl2_RBUS sfg_swap_ctrl2_reg;

	sfg_ctrl_a_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_A_reg);
	sfg_ctrl_9_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_9_reg);
	sfg_ctrl_8_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_8_reg);
	sfg_ctrl_7_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_7_reg);
	sfg_ctrl_0_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_0_reg);
	sfg_swap_ctrl0_reg.regValue = IoReg_Read32(SFG_SFG_SWAP_CTRL0_reg);
	sfg_swap_ctrl1_reg.regValue = Get_DISPLAY_PORT_CONFIG1();
//	sfg_swap_ctrl2_reg.regValue= Get_DISPLAY_PORT_CONFIG2();

	sfg_ctrl_a_reg.final_line_length = _DISP_WID;
	sfg_ctrl_a_reg.hsync_threshold = 0;
	sfg_ctrl_9_reg.sfg_dh_den_sta = Get_DISP_DEN_STA_HPOS();
	sfg_ctrl_9_reg.req_start = Get_DISP_DEN_STA_HPOS()-6;
	sfg_ctrl_8_reg.vsync_start = 0;
	sfg_ctrl_8_reg.vsync_end = Get_DISP_VSYNC_LENGTH();
	sfg_ctrl_7_reg.hsync_width = Get_DISP_HSYNC_WIDTH()-1;
	sfg_ctrl_7_reg.hsync_delay = _DISP_WID +24;

	sfg_ctrl_0_reg.port_num = (Get_DISPLAY_PORT() == 2? 3: Get_DISPLAY_PORT());
	sfg_ctrl_0_reg.seg_num = 0;

	// DTG DCLK mode switch & output port index
	sfg_swap_ctrl0_reg.dclk_mode_switch = Get_DISPLAY_PORT();

	IoReg_Write32(SFG_SFG_CTRL_A_reg, sfg_ctrl_a_reg.regValue);
	IoReg_Write32(SFG_SFG_CTRL_9_reg, sfg_ctrl_9_reg.regValue);
	IoReg_Write32(SFG_SFG_CTRL_8_reg, sfg_ctrl_8_reg.regValue);
	IoReg_Write32(SFG_SFG_CTRL_7_reg, sfg_ctrl_7_reg.regValue);
	IoReg_Write32(SFG_SFG_CTRL_0_reg, sfg_ctrl_0_reg.regValue);

	IoReg_Write32(SFG_SFG_SWAP_CTRL0_reg, sfg_swap_ctrl0_reg.regValue);
	IoReg_Write32(SFG_SFG_SWAP_CTRL1_reg, sfg_swap_ctrl1_reg.regValue);
//	IoReg_Write32(SFG_SFG_SWAP_CTRL2_reg, sfg_swap_ctrl2_reg.regValue);
	//printk(KERN_INFO "[SFG] cfg1=%x(%x)\n", IoReg_Read32(SFG_SFG_SWAP_CTRL1_reg), Get_DISPLAY_PORT_CONFIG1());
#else
	int i=0;

	sfg_sfg_swap_ctrl0_RBUS sfg_swap_ctrl0_reg;
	sfg_sfg_swap_ctrl1_RBUS sfg_swap_ctrl1_reg;
	sfg_sfg_ctrl_0_RBUS    sfg_ctrl_0_reg;
	sfg_sfg_ctrl_9_RBUS    sfg_ctrl_9_reg;
	sfg_sfg_ctrl_8_RBUS    sfg_ctrl_8_reg;
	sfg_sfg_ctrl_7_RBUS    sfg_ctrl_7_reg;
	sfg_sfg_ctrl_6_RBUS    sfg_ctrl_6_reg;
	sfg_sfg_ctrl_5_RBUS	   sfg_ctrl_5_reg;
	sfg_sfg_ctrl_1_RBUS    sfg_ctrl_1_reg;
	sfg_sfg_ctrl_a_RBUS    sfg_ctrl_a_reg;
	sfg_sfg_ctrl_b_RBUS	   sfg_ctrl_b_reg;
//	sfg_sfg_ctrl_c_RBUS    sfg_ctrl_c_reg;
	unsigned int m_seg_width = 0;

	sfg_swap_ctrl0_reg.regValue = IoReg_Read32(SFG_SFG_SWAP_CTRL0_reg);
	sfg_swap_ctrl0_reg.dclk_mode_switch = Get_DISPLAY_PORT(); // DTG DCLK mode switch & output port index
	IoReg_Write32(SFG_SFG_SWAP_CTRL0_reg, sfg_swap_ctrl0_reg.regValue);

	sfg_swap_ctrl1_reg.regValue = IoReg_Read32(SFG_SFG_SWAP_CTRL1_reg);
	if(Get_DISPLAY_PORT_CONFIG1()){
		sfg_swap_ctrl1_reg.regValue = Get_DISPLAY_PORT_CONFIG1();
	}else{
		sfg_swap_ctrl1_reg.output_porta = Get_DISPLAY_PORTAB_SWAP()?1:0;
		sfg_swap_ctrl1_reg.output_portb = Get_DISPLAY_PORTAB_SWAP()?0:1;
	}
	IoReg_Write32(SFG_SFG_SWAP_CTRL1_reg, sfg_swap_ctrl1_reg.regValue);

	sfg_ctrl_0_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_0_reg);

	//if(panel->iCONFIG_PANEL_TYPE == P_VBY1_4K2K){
	if(Get_DISPLAY_SFG_SEG_NUM() != 0){

		m_seg_width = (Get_DISP_ACT_END_HPOS()- Get_DISP_ACT_STA_HPOS())/(Get_DISPLAY_SFG_SEG_NUM());

		if(Get_DISPLAY_SFG_SEG_NUM() == 1){
			sfg_ctrl_1_reg.regValue = 0;
		}
		else{
			sfg_ctrl_1_reg.seg0_start = 0;
			sfg_ctrl_1_reg.seg1_start = m_seg_width;
		}
		IoReg_Write32(SFG_SFG_CTRL_1_reg, sfg_ctrl_1_reg.regValue);

		for(i=1; i<(Get_DISPLAY_SFG_SEG_NUM())/2; i++){

			sfg_ctrl_1_reg.seg0_start = sfg_ctrl_1_reg.seg1_start + m_seg_width;
			sfg_ctrl_1_reg.seg1_start = sfg_ctrl_1_reg.seg0_start + m_seg_width;

			IoReg_Write32(SFG_SFG_CTRL_1_reg+4*i, sfg_ctrl_1_reg.regValue);
		}

		for(i=(Get_DISPLAY_SFG_SEG_NUM())/2 ; i<8; i++){
			IoReg_Write32(SFG_SFG_CTRL_1_reg+4*i, 0);
		}

		sfg_ctrl_0_reg.seg_num = Get_DISPLAY_SFG_SEG_NUM()-1;

		if(Get_DISPLAY_SFG_PORT_NUM() != 0)
			sfg_ctrl_0_reg.port_num = Get_DISPLAY_SFG_PORT_NUM()-1;
		else{
			if(Get_DISPLAY_SFG_PORT_NUM() == 2){	// port 4
				sfg_ctrl_0_reg.port_num = 3;
			}else{ //port 1,2
				sfg_ctrl_0_reg.port_num = Get_DISPLAY_SFG_PORT_NUM();
			}
		}

	}
	else{	//traditional lvds panel setting
		if(Get_DISPLAY_PORT() == 2){	// port 4
			sfg_ctrl_0_reg.port_num = 3;
		}else{ //port 1,2
			sfg_ctrl_0_reg.port_num = Get_DISPLAY_PORT();
		}
		sfg_ctrl_0_reg.seg_num = 0;
		IoReg_Write32(SFG_SFG_CTRL_1_reg, 0);
		IoReg_Write32(SFG_SFG_CTRL_2_reg, 0);
		IoReg_Write32(SFG_SFG_CTRL_3_reg, 0);
		IoReg_Write32(SFG_SFG_CTRL_4_reg, 0);
	}

	IoReg_Write32(SFG_SFG_CTRL_0_reg, sfg_ctrl_0_reg.regValue);

	sfg_ctrl_6_reg.regValue = 0;
	sfg_ctrl_6_reg.tg_auto_cfg = 1;
	IoReg_Write32(SFG_SFG_CTRL_6_reg, sfg_ctrl_6_reg.regValue);//Disable ByPass Mode

	sfg_ctrl_7_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_7_reg);
	sfg_ctrl_7_reg.hsync_width = Get_DISP_HSYNC_WIDTH();//HS_Width = 16 dclk = 16*Pixel_Mode*n DH_Width (必為4倍數, n為正整數)
	sfg_ctrl_7_reg.hsync_delay = Get_DISP_HORIZONTAL_TOTAL() -13;
	IoReg_Write32(SFG_SFG_CTRL_7_reg, sfg_ctrl_7_reg.regValue);


	sfg_ctrl_8_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_8_reg);
	sfg_ctrl_8_reg.hs_distance = 0;
	sfg_ctrl_8_reg.vsync_start = 0;
	sfg_ctrl_8_reg.vsync_end = Get_DISP_VSYNC_LENGTH();
	IoReg_Write32(SFG_SFG_CTRL_8_reg, sfg_ctrl_8_reg.regValue);

	sfg_ctrl_9_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_9_reg);
	sfg_ctrl_9_reg.sfg_dh_den_sta = Get_DISP_DEN_STA_HPOS();
	sfg_ctrl_9_reg.req_start = Get_DISP_DEN_STA_HPOS()-6;
	IoReg_Write32(SFG_SFG_CTRL_9_reg, sfg_ctrl_9_reg.regValue);

	sfg_ctrl_5_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_5_reg);
//	sfg_ctrl_5_reg.hs_distance = 0;
	sfg_ctrl_5_reg.seg0_flip= 0;
	IoReg_Write32(SFG_SFG_CTRL_5_reg, sfg_ctrl_5_reg.regValue);

	sfg_ctrl_a_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_A_reg);
	sfg_ctrl_a_reg.final_line_length = (Get_DISP_ACT_END_HPOS()-Get_DISP_ACT_STA_HPOS());
//	sfg_ctrl_a_reg.hsync_threshold = 0;
	IoReg_Write32(SFG_SFG_CTRL_A_reg, sfg_ctrl_a_reg.regValue);

	sfg_ctrl_b_reg.regValue = 0;
	IoReg_Write32(SFG_SFG_CTRL_B_reg, sfg_ctrl_b_reg.regValue);

	IoReg_Write32(SFG_SFG_SWAP_CTRL1_reg, sfg_swap_ctrl1_reg.regValue);

#endif
	return;
}

#if 0
void scaler_PixelWorks_PA168_LVDS_output_control(unsigned char bootMode)
{
	if(((Get_DISPLAY_PANEL_TYPE() != P_LVDS_4K_2K_BOOTCODE_2K) && (Get_DISPLAY_PANEL_TYPE() != P_LVDS_4K_2K_BOOTCODE_4K))
		|| (Get_DISPLAY_PANEL_CUSTOM_INDEX() != P_PA168_AU_55))
		return;

	//type3_ctrl1_RBUS type3_ctrl1_RBUS_reg;
	pif_lvds_ctrl3_RBUS  lvds_ctrl3_reg;
	dclk_sel_RBUS dclk_sel_reg;
	display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
	dv_den_start_end_RBUS dv_den_start_end_reg;
	static unsigned int lastTconMode=1;
	unsigned int curTconMode=0;
	sfg_sfg_swap_ctrl0_RBUS sfg_swap_ctrl0_reg;

	// disable LVDS output before change timing
	IoReg_Mask32(PIF_LVDS_CTRL3_reg, ~0xf0, 0);
	msleep(50);

	printk(KERN_INFO "[PA168] step1[%d]...\n", bootMode);
	// update SFG configurations
	if(!bootMode)
		drvif_scalerdisplay_SFG_Setup();

	lvds_ctrl3_reg.regValue = IoReg_Read32(PIF_LVDS_CTRL3_reg);
	dclk_sel_reg.regValue = IoReg_Read32(PPOVERLAY_DCLK_SEL_VADDR);
	display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);

	// SLR_4K2K_FORCE_DISPLAY_OUTPUT_ON_60HZ enable status
	// - 2D mode			: 50/60Hz
	// - MVC 3D			: [60Hz]
	// - other 3D mode	: 120Hz

	// LVDS 2ch/4ch switch control
	//if(/*((Scaler_InputSrcGetMainChType() == _SRC_VO) && (dclk_sel_reg.dma_clk_sel == 0))||*/ ((Scaler_InputSrcGetMainChType() != _SRC_VO) && (dclk_sel_reg.dclk_sel == 0)))
	if((_DISP_WID > 1920) && (_DISP_LEN > 1080))
	{
		// 300M pixel clock mode
		// PIF type select (1 to 4)
		// LVDS port enable control (A/B/C/D enable)
		lvds_ctrl3_reg.lvds_aport_en = 1;
		lvds_ctrl3_reg.lvds_bport_en = 1;
//		lvds_ctrl3_reg.lvds_cport_en = 1;
//		lvds_ctrl3_reg.lvds_dport_en = 1;

		// Shpnr_line_mode (1: 5 line, H>2K (if and only if UZU's line buffer is free), 2: if UZU line buffer not free)
//		display_timing_ctrl2_reg.shpnr_line_mode = (display_timing_ctrl2_reg.uzu_sram_free? 1: 2);
	}
	else {
		// 150M pixel clock mode
		// PIF type select (1 to 2)
		// LVDS port enable control (B/D enable)
		lvds_ctrl3_reg.lvds_aport_en = 0;
		lvds_ctrl3_reg.lvds_bport_en = 0;
//		lvds_ctrl3_reg.lvds_cport_en = 1;
//		lvds_ctrl3_reg.lvds_dport_en = 1;

		// Shpnr_line_mode (0: 5 line, H<2K)
		display_timing_ctrl2_reg.shpnr_line_mode = 0;
	}

	// Get current LVDS output mode
	sfg_swap_ctrl0_reg.regValue = IoReg_Read32(SFG_SFG_SWAP_CTRL0_reg);
	curTconMode = sfg_swap_ctrl0_reg.dclk_mode_switch;

	printk(KERN_INFO "[PA168] step2...\n");

	if(lastTconMode != curTconMode){
		// update DV enable start/end
		if(ABS(dv_den_start_end_reg.dv_den_end, Get_DISP_DEN_END_VPOS()) > 100){
			dv_den_start_end_RBUS dv_den_start_end_reg;
			dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
			dv_den_start_end_reg.dv_den_sta = Get_DISP_DEN_STA_VPOS();
			dv_den_start_end_reg.dv_den_end = Get_DISP_DEN_END_VPOS();
			IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);
		}
	}

	//if(lastTconMode != curTconMode)
	{
		dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);

		// update display mode setting (4k2k or 2k1k)
		if(dh_total_last_line_length_reg.dh_total != (Get_DISP_HORIZONTAL_TOTAL() -1)){
			printk(KERN_INFO "[PA168] Re-Config Display Mode DHT=%d->%d\n", dh_total_last_line_length_reg.dh_total+1, Get_DISP_HORIZONTAL_TOTAL());
			scalerdisplay_set_timing();
		}

		// [FIX-ME] last line need equal to HD total in 4k2k display mode
		if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 230) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 310) && !drvif_scaelr3d_decide_is_3D_display_mode()){
			if(_DISP_WID > 1920){
				dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
				dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
				dh_total_last_line_length_reg.dh_total_last_line = dh_total_last_line_length_reg.dh_total;
				IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
				//printk(KERN_INFO "[DBG] Force last line=%d\n", dh_total_last_line_length_reg.dh_total);
			}else{
				display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
				display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
				// [FIX-ME] force enable double DVS
				display_timing_ctrl1_reg.disp_fix_last_line = 1;
				display_timing_ctrl1_reg.disp_fsync_en = 1;
				display_timing_ctrl1_reg.double_dvs_en = 1;
				IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

				// Display in 4k2k mode if video frame rate <= 30Hz
				printk(KERN_INFO "[PA168][WARN] SHOULD NOT BE HERE!!\n");
			}
		}

		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);

		if((_DISP_WID <= 1920) && !drvif_scaelr3d_decide_is_3D_display_mode())
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);

		printk(KERN_INFO "[PA168] step3...\n");
		msleep(200);
	}

	WaitFor_DEN_STOP();
	IoReg_Write32(PIF_LVDS_CTRL3_reg, lvds_ctrl3_reg.regValue);
	printk(KERN_INFO "[PA168] CH=%d->%d\n", lastTconMode, curTconMode);
	lastTconMode = curTconMode;

	// resume cature
	scaler_PixelWorks_PA168_captureDisable(_DISABLE);

	return;
}
#endif

unsigned char scalerdisplay_get_2D_MEMC_support(void)
{
	unsigned char result=FALSE;

	if(((Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_2K) || (Get_DISPLAY_PANEL_TYPE() == P_LVDS_4K_2K_BOOTCODE_4K))
		&& (Get_DISPLAY_PANEL_CUSTOM_INDEX() == P_PA168_AU_55))	// 4k2k panel output lvds 2k1k
		result = TRUE;

 	return result;
}

static void scalerdisplay_3D_Tcon_Setting(bool bEnable)
{

	if(bEnable){
		IoReg_Write32(PPOVERLAY_LFLAG_GEN_reg, 0x0000040C);
		IoReg_Write32(TCON_TCON_IP_EN_reg, 0x00000001);
	}
	else{
		IoReg_Write32(PPOVERLAY_LFLAG_GEN_reg, 0x00000000);
		IoReg_Write32(TCON_TCON_IP_EN_reg, 0x00000000);     //star_liu mdoify 20130829
	}


	IoReg_Write32(TCON_TCON6_HSE_reg, 0x04000400);
	IoReg_Write32(TCON_TCON6_VSE_reg, 0x02000200);

#ifdef CONFIG_PANEL_CHINA_STAR_4K2K_VBY1
	   IoReg_Write32(TCON_TCON6_Ctrl_reg, 0x0000e0c0);  // l_inv
#else
	   IoReg_Write32(TCON_TCON6_Ctrl_reg, 0x0000e080);  //l flag delay
#endif


	//move to bootcode
	//IoReg_Mask32(PB_CFG0_reg, 0xff0fffff, (0x3)<<20); // pin mux for TCON LR
}

static void scalerdisplay_3D_Mode_GPIO_Setting(void)
{
#if 0	//Elsie 20131206: FIXME
	//move to bootcode
//	IoReg_Mask32(PINMUX_TUN_I2C_CFG_VADDR, 0xf0ffffff, (0xf)<<28); // pin mux for 2D_3D_SEL
	IoReg_SetBits(GP4DIR_reg, _BIT8); //set gpio as output
#endif
}

void scalerdisplay_set_3D_Support(bool bEnable)
{
	scalerdisplay_3D_Tcon_Setting(bEnable);
	scalerdisplay_3D_Mode_GPIO_Setting();

//	if(bEnable)
//		setGPIO(136, 1);	//Y6-gpio136
//	else
//		setGPIO(136, 0);
#ifdef VBY_ONE_PANEL
	drvif_scalerConfig4K2K3DUI(bEnable);
	scaler_dtg_reconfig();
#endif
}

extern unsigned int scaler_disp_smooth_get_memc_protect_vtotal(void);
extern unsigned char vbe_disp_get_adaptivestream_fs_mode(void);

unsigned int scalerdisplay_get_vtotal_by_vfreq(UINT16 vsyncFreq)
{
	unsigned int vertical_total=0;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"######## vsyncFreq:%d ###############\n",vsyncFreq);

	//fix me
	if(vsyncFreq == 0){
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"######## vsyncFreq:%d, protect to 60Hz ###############\n",vsyncFreq);
		vsyncFreq = 60;
	}

	if(vbe_disp_get_adaptivestream_fs_mode()){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"### scaler_disp_smooth_set_memc_protect_vtotal !!! ###\n");
		vertical_total = scaler_disp_smooth_get_memc_protect_vtotal();
	}

	if ((vertical_total==0) || (Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)) {
		vertical_total = Get_DISPLAY_CLOCK_TYPICAL()/(Get_DISP_HORIZONTAL_TOTAL()
		*vsyncFreq);
	}

	if (Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)
		vertical_total = 1125;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"######## vertical_total:%d ###############\n",
		vertical_total);

	return vertical_total;
}



// Unit: vsync x 100
unsigned int scalerdisplay_get_framerate(DISP_VSYNC_TYPE VsyncType)
{
	UINT32 vsync_cnt, vsyncFreq;
	UINT32 registerAddr = 0;

	WaitFor_DEN_STOP_Done();
	WaitFor_DEN_STOP_Done();

	if(VsyncType == _TYPE_IVS){
		registerAddr = PPOVERLAY_IVS_cnt_1_reg;
		IoReg_SetBits(registerAddr, _BIT27);	//measure result is after iv2dv dealy.
	}
	else if (VsyncType == _TYPE_DVS)
		registerAddr = PPOVERLAY_DVS_cnt_reg;
//	else if (VsyncType ==_TYPE_D3DTG_DVS)
//		registerAddr = PPOVERLAY_D3DTG_DVS_CNT_VADDR;
	else{
	       rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[ScalerDisplay] Get frame rate type error (%d) \n", VsyncType);
		return 0;
	}


       vsync_cnt = IoReg_Read32(registerAddr) & 0x01ffffff;
       vsyncFreq = (UINT32)27000000*100 / vsync_cnt;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[ScalerDisplay] Get Frame rate (type: %d, value : %d) \n", VsyncType, vsyncFreq);
	return vsyncFreq;
}

unsigned int scalerdisplay_get_dclk(void)
{
	//sys_dclkss_RBUS dclkss_reg;
	pll27x_reg_sys_pll_disp1_RBUS pll_disp1_reg;
	pll27x_reg_sys_pll_disp3_RBUS pll_disp3_reg;
	pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
	UINT32 m_code, f_code, n_code;
	UINT32 dpll_clk;

	pll_disp1_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
	pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);

	m_code = pll_disp1_reg.dpll_m;
	n_code = pll_disp1_reg.dpll_n;
	f_code = pll_ssc0_reg.fcode_t_ssc;

	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	dpll_clk = (((m_code+3)*1000000 + (f_code*1000000)/2048)*27) / (n_code+2);

	if(pll_disp3_reg.dpll_o == 1)
		dpll_clk = dpll_clk/2;
	else if(pll_disp3_reg.dpll_o == 2)
		dpll_clk = dpll_clk/4;
	else if(pll_disp3_reg.dpll_o == 3)
		dpll_clk = dpll_clk/8;
#if 0
	if(sys_dispclksel_reg.dispd_memc_out_sel == 1)
		dpll_clk = dpll_clk/2;
	else if(sys_dispclksel_reg.dispd_memc_out_sel == 2)
		dpll_clk = dpll_clk/4;
#endif
	return dpll_clk;

}

#if 0 //temp mark Fixme
void scalerdisplay_set_PWM_Tuning(void)
{
	UINT32 vSyncFreq = 0;

	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	if((display_timing_ctrl1_reg.disp_frc_fsync == 1)&&(display_timing_ctrl1_reg.disp_fsync_en == 1)){	//framesync timing

		vSyncFreq = scalerdisplay_get_framerate(_TYPE_IVS);

		if(display_timing_ctrl1_reg.double_dvs_en == 1){
			vSyncFreq = vSyncFreq*2;
			printk(KERN_INFO "[scalerdisplay_set_PWM_Tuning] Double DVS\n");
		}
		printk(KERN_INFO "[scalerdisplay_set_PWM_Tuning] FrameSync : vSyncFreq (%d)\n", vSyncFreq);
	}
	else{	// free run timing
		dv_total_RBUS dv_total_reg;
		dh_total_last_line_length_RBUS dh_total_last_line_length_reg;

		UINT32 dclkVal = scalerdisplay_get_dclk();

		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);

		vSyncFreq = (((dclkVal/dh_total_last_line_length_reg.dh_total)*100)/(dv_total_reg.dv_total));
		printk(KERN_INFO "[scalerdisplay_set_PWM_Tuning] FRC : vSyncFreq (%d)\n", vSyncFreq);
	}


	printk(KERN_INFO "Get output frame rate : %d \n", vSyncFreq);

	if(vSyncFreq <= 5400)
	{
		printk(KERN_INFO "Set PWM 3X \n");
		IO_Direct_SetPWMFreq1("PIN_BL_ADJ",vSyncFreq*4/100);
	}
	else if(vSyncFreq > 5400)
	{
		printk(KERN_INFO "Set PWM 4X \n");
		IO_Direct_SetPWMFreq1("PIN_BL_ADJ",vSyncFreq*3/100);
	}
}
#endif
#ifdef RUN_ON_TVBOX

#include <rbusDisp2tveReg.h>
#include "tvscalercontrol/scaler/state.h"
#include <tvscalercontrol/vip/sb2_reg.h>

#define TVE_H_POS_STA 0x111
#define TVE_H_POS_END 0x891
#define TVE_V_POS_STA 0x29
#define TVE_V_POS_END 0x461

static unsigned char g_displaySizeUseTVEConfig = FALSE;
static unsigned char g_displayTVEMode = _MODE_1080P60;
static SCALER_TVBOX_DISPINFO g_tvBoxDispInfo = {1920, 1080, TVE_H_POS_STA, TVE_H_POS_END, TVE_V_POS_STA, TVE_V_POS_END, 2200, 1125}; // sync from tve

void scalerdisplay_set_display_use_tve_size(unsigned char flag)
{
	g_displaySizeUseTVEConfig = flag;
}

unsigned char scalerdisplay_get_display_use_tve_size(void)
{
	return g_displaySizeUseTVEConfig;
}

void scalerdisplay_set_display_tve_mode(unsigned char Mode)
{
	g_displayTVEMode = Mode;
}

unsigned char scalerdisplay_get_display_tve_mode(void)
{
	return g_displayTVEMode;
}

unsigned short scalerdisplay_get_BoxDispInfo(TVBOXINFO boxInfo)
{
	unsigned short val;

	switch(boxInfo){

		case _BOX_DISP_WID:
			val = g_tvBoxDispInfo.boxDispWid;
			break;
		case _BOX_DISP_LEN:
			val = g_tvBoxDispInfo.boxDispLen;
			break;
		case _BOX_DISP_HDENSTART:
			val = g_tvBoxDispInfo.boxDispHDenStart;
			break;
		case _BOX_DISP_HDENEND:
			val = g_tvBoxDispInfo.boxDispHDenEnd;
			break;
		case _BOX_DISP_VDENSTART:
			val = g_tvBoxDispInfo.boxDispVDenStart;
			break;
		case _BOX_DISP_VDENEND:
			val = g_tvBoxDispInfo.boxDispVDenEnd;
			break;
		case _BOX_DISP_HTOTAL:
			val = g_tvBoxDispInfo.boxDispHTotal;
			break;
		case _BOX_DISP_VTOTAL:
			val = g_tvBoxDispInfo.boxDispVTotal;
			break;

		default:
			val = 0;
	}

	return val;

}

void scalerdisplay_set_disp2tve_flow(unsigned char mode)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scalerdisplay_set_disp2tve_flow : mode => %d\n", mode);

	/*WaitFor_DEN_STOP();*/
	IoReg_ClearBits(DISP2TVE_DISP2TVE_GLOBAL_VADDR, _BIT31|_BIT15|_BIT14|_BIT13|_BIT12);
	scalerdisplay_set_display_use_tve_size(TRUE);
	scalerdisplay_change_timing_to_disp2tve(mode);
}

void scalerdisplay_change_timing_to_disp2tve(unsigned char mode){
	int ret;
	UINT8 resolution_type = mode; //Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	UINT16 DH_Start=0, DH_End=0, DH_Total, DH_Wid;
	UINT16 DV_Start=0, DV_End=0, DV_Total, DV_Len;
	dh_total_last_line_length_RBUS	dh_total_last_line_length_reg;
	dv_total_RBUS 			    	dv_total_reg;
	ppoverlay_dh_den_start_end_RBUS 		dh_den_start_end_reg;
	ppoverlay_dv_den_start_end_RBUS 		dv_den_start_end_reg;

	/*
	                      Htotal/vtotal         hactive/vactive        pixel clock

	480P:              858*525               720*480                  27M

	576P:               864*625               720*576                  27M

	720P 60Hz:      1650*750             1280*720                74.25M

	720P 50Hz:      1980*750             1280*720                74.25M
	*/

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[crixus_test]scalerdisplay_change_timing_to_disp2tve\n");

	scalerdisplay_set_display_tve_mode(mode);

	switch(resolution_type){

		case _MODE_480I:
		case _MODE_480P:
			DH_Total = 858;
			DV_Total = 525;
			DH_Wid = 720;
			DV_Len = 480;
			DH_Start = 0x82;
			DV_Start = 0x2a;
			break;

		case _MODE_576I:
		case _MODE_576P:
			DH_Total = 864;
			DV_Total = 625;
			DH_Wid = 720;
			DV_Len = 576;
			DH_Start = 0x7c;
			DV_Start = 0x2c;
			break;

		case _MODE_720P50:
			DH_Total = 1980;
			DV_Total = 750;
			DH_Wid = 1280;
			DV_Len = 720;
			DH_Start = 0x171;
			DV_Start = 0x19;
			break;

		case _MODE_720P60:
			DH_Total = 1650;
			DV_Total = 750;
			DH_Wid = 1280;
			DV_Len = 720;
			DH_Start = 0x16B;
			DV_Start = 0x19;
			break;

		case _MODE_1080I25:
		case _MODE_1080P50:
			DH_Total = 2640;
			DV_Total = 1125;
			DH_Wid = 1920;
			DV_Len = 1080;
			DH_Start = 0x135;
			DV_Start = 0x29;
			break;

		case _MODE_1080I30:
		case _MODE_1080P60:
			DH_Total = 2200;
			DV_Total = 1125;
			DH_Wid = 1920;
			DV_Len = 1080;
			DH_Start = 0x111;
			DV_Start = 0x29;
			break;

		case _MODE_4k2kI30:
		case _MODE_4k2kP30://_4k2k
			DH_Total = 4400;
			DV_Total = 2250;
			DH_Wid = 3840;
			DV_Len = 2160;
			DH_Start = 0x128;
			DV_Start = 0x48;
			break;

		case _MODE_800x600_72HZ:
			DH_Total = 1000;
			DV_Total = 675;
			DH_Wid = 800;
			DV_Len = 600;
			DH_Start = 104;
			DV_Start = 71;
			break;

		case _MODE_1600x1200_85HZ:
			DH_Total = 2160;
			DV_Total = 1250;
			DH_Wid = 1600;
			DV_Len = 1200;
			DH_Start = 304;
			DV_Start = 46;
			break;


		default:

			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[Error] Unhandle Mode !!!!\n");
			DH_Total = 2200;
			DV_Total = 1125;
			DH_Wid = 1920;
			DV_Len = 1080;
			DH_Start = 0x111;
			DV_Start = 0x29;


			break;
	}

	if(DH_Start == 0)
		DH_Start = (DH_Total -DH_Wid) / 2;
	if(DV_Start == 0)
		DV_Start = (DV_Total -DV_Len) / 2;

	DH_End	= DH_Start + DH_Wid;
	DV_End	= DV_Start + DV_Len;

	dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	dh_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
	dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);

	dh_total_last_line_length_reg.dh_total = DH_Total-1;
	dh_total_last_line_length_reg.dh_total_last_line = DH_Total-1;
	dv_total_reg.dv_total = DV_Total-1;

	dh_den_start_end_reg.dh_den_sta = DH_Start;
	dh_den_start_end_reg.dh_den_end = DH_End;
	dv_den_start_end_reg.dv_den_sta = DV_Start;
	dv_den_start_end_reg.dv_den_end = DV_End;

	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, dh_total_last_line_length_reg.regValue);
	IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
	IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, dh_den_start_end_reg.regValue);
	IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, dv_den_start_end_reg.regValue);

	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)0,SLR_INPUT_DISP_WID, DH_Wid);
	Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)0,SLR_INPUT_DISP_LEN, DV_Len);

	g_tvBoxDispInfo.boxDispWid = DH_Wid;
	g_tvBoxDispInfo.boxDispLen = DV_Len;
	g_tvBoxDispInfo.boxDispHDenStart =DH_Start;
	g_tvBoxDispInfo.boxDispHDenEnd = DH_End;
	g_tvBoxDispInfo.boxDispVDenStart = DV_Start;
	g_tvBoxDispInfo.boxDispVDenEnd = DV_End;
	g_tvBoxDispInfo.boxDispHTotal = DH_Total;
	g_tvBoxDispInfo.boxDispVTotal = DV_Total;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[crixus_test]DH_TOTAL:%x\n",IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[crixus_test]DV_TOTAL:%x\n",IoReg_Read32(PPOVERLAY_DV_total_reg));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[crixus_test]DH_STA_END:%x\n",IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[crixus_test]DV_STA_END:%x\n",IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg));


	scalerdisplay_set_main_display_window(0, DH_Wid, 0, DV_Len, 0);
	scalerdisplay_set_main_act_window(0, DH_Wid, 0, DV_Len);
	drvif_scalerdisplay_set_sharpness_line_mode();
	drvif_set_dclk_sync_tvbox(resolution_type);


	if((mode == _MODE_1080P50) ||
		    (mode == _MODE_1080I25) ||
  		    (mode == _MODE_720P50) ||
  		    (mode == _MODE_576I) ||
  		    (mode == _MODE_576P) ){
		drvif_scaler_voForceFrameRateControl_by_TvBox(50000, TRUE);
	}else if((mode == _MODE_4k2kI30)||(mode == _MODE_4k2kP30)){
		drvif_scaler_voForceFrameRateControl_by_TvBox(30000, TRUE);
	}
	else{
		drvif_scaler_voForceFrameRateControl_by_TvBox(60000, TRUE);
	}
}
#endif

#if defined BUILD_TV013_1	//zzl 20140226 Add Factory Menu WB Pattern function.
void TPVSetWBGrayPattern(char gray, bool Enable)
{

    rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "function=%s, line=%d, enable=%x\n", __FUNCTION__, __LINE__, Enable);
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	//Wait Display Data enable end period
	//IoReg_BusyCheckRegBit(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT10, 0x1FFFF);
	//Set Display pattern black color
	IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR0_reg, (UINT32)(gray<<16)|0x8080);
	IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR1_reg, (UINT32)(gray<<16)|0x8080);
	if (Enable){
		IoReg_Mask32(SCALEUP_D_UZU_Globle_Ctrl_reg, 0xffffffbe, _BIT6|_BIT0);
		IoReg_Mask32(PPOVERLAY_Main_Display_Control_RSV_reg, 0xfffffffd, 0);
	}else{
		IoReg_Mask32(SCALEUP_D_UZU_Globle_Ctrl_reg, 0xffffffbe, 0);
		IoReg_Mask32(PPOVERLAY_Main_Display_Control_RSV_reg, 0xfffffffd, _BIT1);
	}
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/

}
#endif//shangfu@120607 add End

#ifndef CONFIG_MEMC_BYPASS
void Scaler_MEMC_output_force_bg_enable(UINT8 enable);
#endif

#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
extern void Scaler_start_orbit_algo(unsigned char b_enable);
extern unsigned char vbe_disp_get_orbit(void);
#endif

/*api which have protect by forcebg_semaphore*/
void drvif_scalerdisplay_wait_d0_apply(unsigned char display)
{
	unsigned long flags;//for spin_lock_irqsave
	unsigned int timeoutcount = 0x3ffff;
	if(SLR_MAIN_DISPLAY == display){
		ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
		ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;
		ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
		ppoverlay_double_buffer_ctrl2_reg.uzudtg_dbuf_vsync_sel = 3; //need uzudtg vsync
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_set = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		while((timeoutcount) && (double_buffer_ctrl_reg.dmainreg_dbuf_set)){
			timeoutcount--;
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		}
		if(timeoutcount == 0){
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[FBG MAIN]timeout error!!!\n");
			drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
		}
	}else{//for sub

	}
	return;
}

extern UINT8 TV006_WB_Pattern_En;
/*api which have protect by forcebg_semaphore*/
extern void wakeup_mute_off_callback(unsigned char display);
void scalerdisplay_force_bg_enable(unsigned int channel, unsigned char enable)
{
	unsigned long flags;//for spin_lock_irqsave
	ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
#ifdef CONFIG_DUAL_CHANNEL
	ppoverlay_mp_layout_force_to_background_RBUS mp_layout_force_to_background_reg;
#endif
	extern void set_atv_go_smooth_toggle_flag(unsigned char display, unsigned char flag);

	int i;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
	unsigned char read_level;
	ppoverlay_dtg_lc_RBUS dtg_lc_reg;
	ppoverlay_dtg_pending_status_RBUS dtg_pending_status_reg;

	unsigned int uzulinecntA =0;
	unsigned int uzulinecntB =0;

	unsigned int timeoutcount = 0x3ffff;
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_Reg;
#ifndef CONFIG_DUAL_CHANNEL
	channel = SLR_MAIN_DISPLAY;
#endif
	rtd_printk(KERN_INFO, TAG_NAME_VBE,"%s,Disp[%d]=%d\n", __FUNCTION__, channel, enable);

	if (!enable && (channel == SLR_MAIN_DISPLAY)) {
		set_ATV_passthrought_output_flag(channel, FALSE);//for ATV disable fbg in LD testing case
	}

	if (!enable) {
		for (i = 0; i < SLR_FORCE_BG_TYPE_MAX; i++) {
			if (display_forcebg_mask[channel][i]) {
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n### mask(%d)(%d) is enable, so can not disable bg ###\r\n", channel, i);
				return;
			}
		}
	}

	if((channel == SLR_MAIN_DISPLAY) && TV006_WB_Pattern_En) //WOSQRTK-7731
	{
		pr_notice("%s,Disp[%d]=%d WB=%d\n", __FUNCTION__, channel, enable, TV006_WB_Pattern_En);
		return;
	}



  if(enable) //different algo. enable:new   disable:old
  {

	if(channel == SLR_MAIN_DISPLAY){//main path
		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		if (enable == main_display_control_rsv_reg.m_force_bg) {
			if(enable) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG MAIN]Already forceBG!!!####\r\n");
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG MAIN]Already disable forceBG!!!####\r\n");
			}
			return;
		}
		//enable double buffer
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 1;//enable double buffer
		double_buffer_ctrl_reg.dmainreg_dbuf_set = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		spin_lock_irqsave(get_FBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock forcebg  spinlock
		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		main_display_control_rsv_reg.m_force_bg = enable;

		//check WebOS call mute on
		if (!enable) {
			for (i = 0; i < SLR_FORCE_BG_TYPE_MAX; i++) {
				if (display_forcebg_mask[channel][i]) {
					main_display_control_rsv_reg.m_force_bg = TRUE;
					IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
					spin_unlock_irqrestore(get_FBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock forcebg spinlock
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n### mask(%d)(%d) is enable, so main change to force bg 1###\r\n", channel, i);
					drvif_scalerdisplay_wait_d0_apply(channel);
					return;
				}
			}
		}

		//write force bg
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
		spin_unlock_irqrestore(get_FBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock forcebg spinlock
		//apply double buffer
		drvif_scalerdisplay_wait_d0_apply(channel);

		if (!enable) {
			set_atv_go_smooth_toggle_flag(SLR_MAIN_DISPLAY, TRUE);
			wakeup_mute_off_callback(SLR_MAIN_DISPLAY);
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"####RTK Disable Main ForceBG!!!####\r\n");
#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
			if(vbe_disp_get_orbit()==TRUE){
				Scaler_start_orbit_algo(TRUE);
			}
#endif
		} else {
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"####RTK Enable Main ForceBG(Black screen)!!!####\r\n");
#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
			if(vbe_disp_get_orbit()==TRUE){
				Scaler_start_orbit_algo(FALSE);
			}
#endif
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if(channel == SLR_SUB_DISPLAY){//sub path
/*	fix me later by benwang
		read_level = double_buffer_ctrl_reg.dsubreg_dbuf_read_sel;
		double_buffer_ctrl_reg.dsubreg_dbuf_read_sel = 0;
		mp_layout_force_to_background_reg.regValue = IoReg_Read32(PPOVERLAY_MP_Layout_Force_to_Background_reg);
		if (enable == mp_layout_force_to_background_reg.s_force_bg) {
			if(enable) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG SUB]Already forceBG!!!####\r\n");
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG SUB]Already disable forceBG!!!####\r\n");
			}
			double_buffer_ctrl_reg.dsubreg_dbuf_read_sel = read_level;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
			return;
		}
		double_buffer_ctrl_reg.dsubreg_dbuf_read_sel = read_level;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		mp_layout_force_to_background_reg.s_force_bg = enable;

		//enable line compare function
		dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);



			do {
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntA = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			new_meas1_linecnt_real_Reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntB = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			if((uzulinecntA == uzulinecntB)&&((uzulinecntA < (dv_den_start_end_reg.dv_den_sta)) || (uzulinecntA > (dv_den_start_end_reg.dv_den_end)))) {

					IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, mp_layout_force_to_background_reg.regValue);
					break;
				}
			timeoutcount--;
		} while(timeoutcount);


		if(timeoutcount == 0){
				IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, mp_layout_force_to_background_reg.regValue);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[FBG MAIN]timeout error!!!\n");
			}


		drvif_scalerdisplay_set_dbuffer_en(SLR_SUB_DISPLAY, FALSE);
		if (!enable) {
			set_atv_go_smooth_toggle_flag(SLR_SUB_DISPLAY, TRUE);
wakeup_mute_off_callback(SLR_SUB_DISPLAY);
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n####RTK Disable Sub ForceBG!!!####\r\n");
		} else {
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n####RTK Enable Sub ForceBG(Black screen)!!!####\r\n");
		}

*/
	}
#endif
  }
  else
  {
	if(channel == SLR_MAIN_DISPLAY){//main path
		//enable double buffer
		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		if (enable == main_display_control_rsv_reg.m_force_bg) {
			if(enable) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG MAIN]Already forceBG!!!####\r\n");
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG MAIN]Already disable forceBG!!!####\r\n");
			}
			return;
		}
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		double_buffer_ctrl_reg.dmainreg_dbuf_en = 1;
		double_buffer_ctrl_reg.dmainreg_dbuf_set = 0;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock

		spin_lock_irqsave(get_FBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock forcebg  spinlock
		main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
		main_display_control_rsv_reg.m_force_bg = enable;

		//check WebOS call mute on
		if (!enable) {
			for (i = 0; i < SLR_FORCE_BG_TYPE_MAX; i++) {
				if (display_forcebg_mask[channel][i]) {
					main_display_control_rsv_reg.m_force_bg = TRUE;
					IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
					spin_unlock_irqrestore(get_FBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock forcebg  spinlock
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n### mask(%d)(%d) is enable, so main change to force bg###\r\n", channel, i);
					drvif_scalerdisplay_wait_d0_apply(channel);
					return;
				}
			}
		}
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, main_display_control_rsv_reg.regValue);
		spin_unlock_irqrestore(get_FBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock forcebg  spinlock

		//}

		//apply double buffer
		drvif_scalerdisplay_wait_d0_apply(channel);

		if (!enable) {
			set_atv_go_smooth_toggle_flag(SLR_MAIN_DISPLAY, TRUE);
			wakeup_mute_off_callback(SLR_MAIN_DISPLAY);
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"####RTK Disable Main ForceBG!!!####\r\n");
#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
			if(vbe_disp_get_orbit()==TRUE){
				Scaler_start_orbit_algo(TRUE);
			}
#endif
		} else {
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"####RTK Enable Main ForceBG(Black screen)!!!####\r\n");
#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
			if(vbe_disp_get_orbit()==TRUE){
				Scaler_start_orbit_algo(FALSE);
			}
#endif
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	else if(channel == SLR_SUB_DISPLAY){//sub path
/*	fix me later by benwang
		read_level = double_buffer_ctrl_reg.dsubreg_dbuf_read_sel;
		double_buffer_ctrl_reg.dsubreg_dbuf_read_sel = 0;
		mp_layout_force_to_background_reg.regValue = IoReg_Read32(PPOVERLAY_MP_Layout_Force_to_Background_reg);
		if (enable == mp_layout_force_to_background_reg.s_force_bg) {
			if(enable) {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG SUB]Already forceBG!!!####\r\n");
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n####[FBG SUB]Already disable forceBG!!!####\r\n");
			}
			double_buffer_ctrl_reg.dsubreg_dbuf_read_sel = read_level;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
			return;
		}
		double_buffer_ctrl_reg.dsubreg_dbuf_read_sel = read_level;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		mp_layout_force_to_background_reg.s_force_bg = enable;

		//enable line compare function
		dtg_lc_reg.dtg_vlcen = 0;
		dtg_lc_reg.dtg_vlc_mode = 0;
		dtg_lc_reg.dtg_vlc_src_sel = 1;
		dtg_lc_reg.dtg_vln = dv_den_start_end_reg.dv_den_end;
		IoReg_Write32(PPOVERLAY_DTG_LC_reg, dtg_lc_reg.regValue);
		if(1){//Revert
			do {
				dtg_lc_reg.dtg_vlcen = 1;
				IoReg_Write32(PPOVERLAY_DTG_LC_reg, dtg_lc_reg.regValue);
				if((IoReg_Read32(PPOVERLAY_DTG_pending_status_reg) & _BIT4)) {
					IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, mp_layout_force_to_background_reg.regValue);
					break;
				}
				timeoutcount--;
			} while(timeoutcount);

			if(timeoutcount == 0){
				IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, mp_layout_force_to_background_reg.regValue);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[FBG MAIN]timeout error!!!\n");
			}
		} else {
			IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, mp_layout_force_to_background_reg.regValue);
		}

		drvif_scalerdisplay_set_dbuffer_en(SLR_SUB_DISPLAY, FALSE);
		if (!enable) {
			set_atv_go_smooth_toggle_flag(SLR_SUB_DISPLAY, TRUE);
wakeup_mute_off_callback(SLR_SUB_DISPLAY);
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n####RTK Disable Sub ForceBG!!!####\r\n");
		} else {
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\r\n####RTK Enable Sub ForceBG(Black screen)!!!####\r\n");
		}
*/
	}
#endif
  }	//different algo. enable:new   disable:old

	if (!enable) {
		IoReg_Mask32(PPOVERLAY_Display_Timing_CTRL1_reg, ~_BIT18, 0);
	}


	if(!enable)
	{
		//disable line compare function
		dtg_lc_reg.regValue = 0;
		IoReg_Write32(PPOVERLAY_DTG_LC_reg, dtg_lc_reg.regValue);
		//clear line compare status
		dtg_pending_status_reg.regValue = 0;
		dtg_pending_status_reg.dtg_vlc_status = 1;
		IoReg_Write32(PPOVERLAY_DTG_pending_status_reg, dtg_pending_status_reg.regValue);

		//if(Get_DISPLAY_PANEL_TYPE() == P_EPI_TYPE){
			//drvif_scaler_ddomain_DTG_line_compare_irq(1, 1, 2, 0x8AD);
		//}

        rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[%s][%d]disable FBG!!\n", __FUNCTION__, __LINE__);
	}
    else
        rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[%s][%d]enable FBG!!\n", __FUNCTION__, __LINE__);
	//First booting check MEMC output BG again
	if(Scaler_MEMC_Get_CheckMEMC_Outbg()){
		Scaler_MEMC_fbg_control();
		Scaler_MEMC_Set_CheckMEMC_Outbg(FALSE);
	}
}



void drvif_scalerDTG_set_bg_color(unsigned char ColorR, unsigned char ColorG, unsigned char ColorB,unsigned char enable)
{
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	ppoverlay_display_background_color_RBUS display_background_color_reg;
	ppoverlay_display_background_color_2_RBUS display_background_color_2_reg;

	display_background_color_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Background_Color_reg);
	display_background_color_reg.d_bg_g = ColorG;
	display_background_color_reg.d_bg_b = ColorB;
	IoReg_Write32(PPOVERLAY_Display_Background_Color_reg, display_background_color_reg.regValue);

	display_background_color_2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Background_Color_2_reg);
	display_background_color_2_reg.d_bg_r = ColorR;
	IoReg_Write32(PPOVERLAY_Display_Background_Color_2_reg, display_background_color_2_reg.regValue);

	display_timing_ctrl1_reg.regValue=IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	if(enable)
	{
		display_timing_ctrl1_reg.dout_force_bg = _ENABLE;
	}
	else
	{
		display_timing_ctrl1_reg.dout_force_bg = _DISABLE;
	}
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);
}

unsigned char Scaler_OpenVOGating(void)
{
//	unsigned short dispWid_16_9, dispWid_16_10;
//	SLR_RATIO_TYPE type;
//	SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());

#if 0  //mark by qing_liu
	//frank@0926 let MVC stream 3D force 2D gp FS gating function to solve mantis#5080
	if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (pVOInfo->mode_3d == VO_3D_FRAME_PACKING) && (pVOInfo->force2d) )
		return TRUE;
#endif

	if (/*(!Scaler_PipGetInfo(SLR_PIP_ENABLE)) && // no PIP*/
		(Scaler_InputSrcGetMainChType()==_SRC_VO)  ) // via vo
	{
		//frank@20120524 Change below code to solve DTV weak signal framesync fail issue
		return TRUE;
	}

	return FALSE;
}


void set_display_forcebg_mask(unsigned char display, unsigned char masktype, unsigned char maskvalue)
{
#ifndef CONFIG_DUAL_CHANNEL
	display = SLR_MAIN_DISPLAY;
#endif
	if(display == SLR_MAIN_DISPLAY)
		spin_lock(&ForceBG_Main_Mask_Spinlock);
	else
		spin_lock(&ForceBG_Sub_Mask_Spinlock);
	if (masktype >= SLR_FORCE_BG_TYPE_MAX) {
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n###set_display_forcebg_mask type(%d) error###\r\n", masktype);
		if(display == SLR_MAIN_DISPLAY)
			spin_unlock(&ForceBG_Main_Mask_Spinlock);
		else
			spin_unlock(&ForceBG_Sub_Mask_Spinlock);
		return;
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n###set_display_forcebg_mask (%d %d %d)###\r\n", display, masktype, maskvalue);
	display_forcebg_mask[display][masktype] = maskvalue;
	if(display == SLR_MAIN_DISPLAY)
		spin_unlock(&ForceBG_Main_Mask_Spinlock);
	else
		spin_unlock(&ForceBG_Sub_Mask_Spinlock);
}

unsigned char Get_display_forcebg_mask(unsigned char display, unsigned char masktype)
{
#ifndef CONFIG_DUAL_CHANNEL
	display = SLR_MAIN_DISPLAY;
#endif
	if (masktype >= SLR_FORCE_BG_TYPE_MAX) {
		printk(KERN_ERR "\r\n###set_display_forcebg_mask type(%d) error###\r\n", masktype);
		return FALSE;
	}
	return display_forcebg_mask[display][masktype];
}

unsigned char Check_AP_Set_Enable_ForceBG(unsigned char display)
{//TRUE: Enable force bg. FALSE: Disable force bg
	if((Get_display_forcebg_mask(display, SLR_FORCE_BG_TYPE_VSC) == TRUE) ||
		(Get_display_forcebg_mask(display, SLR_FORCE_BG_TYPE_3D) == TRUE))
		return TRUE;
	else
		return FALSE;
}

void forcebg_semaphore_init(void)
{
	sema_init(&ForceBG_Semaphore, 1);
}

struct semaphore* get_forcebg_semaphore(void)
{
	return &ForceBG_Semaphore;
}

void DI_semaphore_init(void)
{
	sema_init(&DI_Semaphore, 1);
}

struct semaphore* get_DI_semaphore(void)
{
	return &DI_Semaphore;
}

spinlock_t* get_DBreg_spinlock(unsigned char display)
{//Get Main_DBReg_Spinlock or Sub_DBReg_Spinlock
#ifdef CONFIG_DUAL_CHANNEL
	if(display == SLR_MAIN_DISPLAY)
		return &Main_DBReg_Spinlock;
	else
		return &Sub_DBReg_Spinlock;
#else
	return &Main_DBReg_Spinlock;
#endif
}

spinlock_t* get_FBreg_spinlock(unsigned char display)
{//Get Main_DBReg_Spinlock or Sub_DBReg_Spinlock
#ifdef CONFIG_DUAL_CHANNEL
	if(display == SLR_MAIN_DISPLAY)
		return &Main_FBReg_Spinlock;
	else
		return &Sub_FBReg_Spinlock;
#else
	return &Main_FBReg_Spinlock;
#endif
}


void Scaler_ForcePanelBg(unsigned char enable)
{

	sfg_sfg_force_bg_at_dif_RBUS sfg_force_bg_at_dif_reg;
	WaitFor_DEN_STOP();
	sfg_force_bg_at_dif_reg.regValue = IoReg_Read32(SFG_SFG_FORCE_BG_AT_DIF_reg);
	if(enable){
		sfg_force_bg_at_dif_reg.en_force_bg_dif = 1;
	}else{
		sfg_force_bg_at_dif_reg.en_force_bg_dif = 0;
	}
	IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, sfg_force_bg_at_dif_reg.regValue);

}

/*======================== End of File =======================================*/

/**
  * @}
  */

