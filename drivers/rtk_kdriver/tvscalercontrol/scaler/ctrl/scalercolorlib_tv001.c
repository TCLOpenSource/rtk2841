/*******************************************************************************
* @file    scalerColorLib.cpp
* @brief
* @note    Copyright (c) 2014 RealTek Technology Co., Ltd.
*		   All rights reserved.
*		   No. 2, Innovation Road II,
*		   Hsinchu Science Park,
*		   Hsinchu 300, Taiwan
*
* @log
* Revision 0.1	2014/01/27
* create
*******************************************************************************/
/*******************************************************************************
 * Header include
******************************************************************************/

#include <linux/delay.h>
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/string.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
//#include <mach/RPCDriver.h>
#include <linux/pageremap.h>
#include <mach/system.h>
#include <linux/hrtimer.h>

#include <tvscalercontrol/vip/vip_reg_def.h>
//#include <rbus/rbusHistogramReg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>

//#include <rbus/rbusODReg.h>
//#include <rbus/rbus_DesignSpec_MISC_LSADCReg.h>
//#include <rbus/rbusColorReg.h>
//#include <rbus/rbusCon_briReg.h>
//#include <rbus/rbusYuv2rgbReg.h>
//#include <rbus/rbusScaleupReg.h>
//#include <rbus/rbusColor_dccReg.h>
//#include <rbus/rbusGammaReg.h>
//#include <rbus/rbusInv_gammaReg.h>
#include <rbus/dm_reg.h>
#include <rbus/dolby_v_top_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/vodma_reg.h>
//#include "rbus/rbusHDMIReg.h"
#include <rbus/h3ddma_hsd_reg.h>


#if CONFIG_FIRMWARE_IN_KERNEL
/*#include </merlin_rbus/hdr/dolby_v_top_reg.h>*/ //Need SW sync,  SW Team not sync from TV001
#else
#include <rbus/dolby_v_top_reg.h>
#endif

//#include <rbus/dtg_reg.h>

/*#include <Application/AppClass/SetupClass.h>*/

/*#include "tvscalercontrol/scaler/scalerSuperResolution.h"*/
/*#include <tvscalercontrol/scaler/scalertimer.h>*/
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/scaler/scalercolorlib_tv001.h>
/*#include <tvscalercontrol/scaler/scalerlib.h>*/
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/pipmp.h>
//#include <tvscalercontrol/scalerdrv/scalerdrv.h>

#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>
#include <tvscalercontrol/vip/dcc.h>
#include <tvscalercontrol/vip/intra.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/vip/peaking.h>
#include <tvscalercontrol/vip/nr.h>
#include <tvscalercontrol/vip/xc.h>
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/vip/viptable.h>

#include <tvscalercontrol/hdmirx/hdmifun.h>

#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/panel/panelapi.h>
/*#include <Platform_Lib/Board/pcbMgr.h>*/
/*#include <Platform_Lib/Board/pcb.h>*/
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scaler_vscdev.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>
#include <mach/rtk_log.h>

#include "tvscalercontrol/scaler_vpqmemcdev.h"
#include <tvscalercontrol/vip/localcontrast.h>

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
#include "memc_isr/scalerMEMC.h"
#endif


#define TAG_NAME "VPQ"

/*******************************************************************************
* Macro
******************************************************************************/
#define GET_USER_INPUT_SRC()					(Scaler_GetUserInputSrc(SLR_MAIN_DISPLAY))

#define _SUCCESS		1
#define _FAIL			0
#define _ENABLE 			1
#define _DISABLE			0
#define _TRUE			1
#define _FALSE			0

/*******************************************************************************
* Constant
******************************************************************************/
/*#define example  100000 */ /* 100Khz */

/* Enable or Disable VIP flag*/



/*******************************************************************************
 * Structure
 ******************************************************************************/

/*typedef struct*/
/*{*/
/*} MID_example_Param_t;*/


/*******************************************************************************
* enumeration
******************************************************************************/
/*typedef enum*/
/*{*/
/*    MID_Example_SLEEPING = 0,*/
/*    MID_Example_RUNNING,*/
/*} MID_Example_Status_t;*/

/*******************************************************************************
* Variable
******************************************************************************/
static unsigned char m_nDRLevel;
static unsigned char m_nSRLevel;
static unsigned char m_nCGLevel;
static unsigned char m_nFTLevel;

/*******************************************************************************
* Program
******************************************************************************/
//======================add for TCL Project======================
extern unsigned char bCinemaModeEn;
//******************************************************************************/

static void rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
	unsigned int X,A,result;
	X=(1<<(endBit-startBit+1))-1;
	A=rtd_inl(reg_addr);
	result = (A & (~(X<<startBit))) | (value<<startBit);
	rtd_outl(reg_addr,result);
}

unsigned int Scaler_GetColorTemp_level_type(TV010_COLORTEMP_E * colorTemp)
{
	unsigned char nLevel;
	nLevel=scaler_get_color_temp_level_type(GET_USER_INPUT_SRC());

	if(nLevel == SLR_COLORTEMP_NORMAL )
		*colorTemp=TV010_COLORTEMP_NATURE;
	else if(nLevel == SLR_COLORTEMP_COOL || nLevel == SLR_COLORTEMP_COOLER)
		*colorTemp=TV010_COLORTEMP_COOL;
	else if(nLevel == SLR_COLORTEMP_WARM || nLevel == SLR_COLORTEMP_WARMER)
		*colorTemp=TV010_COLORTEMP_WARM;
	else if(nLevel == SLR_COLORTEMP_USER )
		*colorTemp=TV010_COLORTEMP_USER;
	else
		*colorTemp=TV010_COLORTEMP_NATURE;
	return _SUCCESS;
}
void Scaler_SetColorTemp_level_type(TV010_COLORTEMP_E colorTemp)
{
	if(colorTemp == TV010_COLORTEMP_NATURE )
		Scaler_SetColorTemp(SLR_COLORTEMP_NORMAL);
	else if(colorTemp == TV010_COLORTEMP_COOL )
		Scaler_SetColorTemp(SLR_COLORTEMP_COOL);
	else if(colorTemp == TV010_COLORTEMP_WARM )
		Scaler_SetColorTemp(SLR_COLORTEMP_WARM);
	else if(colorTemp == TV010_COLORTEMP_USER )
		Scaler_SetColorTemp(SLR_COLORTEMP_USER);
	else
		Scaler_SetColorTemp(SLR_COLORTEMP_NORMAL);
}
unsigned int Scaler_GetColorTempData(TV010_COLOR_TEMP_DATA_S *colorTemp)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	colorTemp->redGain = Scaler_get_color_temp_r_type(src_idx);
	colorTemp->greenGain = Scaler_get_color_temp_g_type(src_idx);
	colorTemp->blueGain = Scaler_get_color_temp_b_type(src_idx);
	colorTemp->redOffset = Scaler_get_color_temp_r_offset(src_idx);
	colorTemp->greenOffset = Scaler_get_color_temp_g_offset(src_idx);
	colorTemp->blueOffset = Scaler_get_color_temp_b_offset(src_idx);
	return _SUCCESS;
}
void Scaler_SetColorTempData(TV010_COLOR_TEMP_DATA_S *colorTemp)
{
	printk(KERN_EMERG "Scaler_SetColorTempData Gain(%d, %d, %d)\n",colorTemp->redGain, colorTemp->greenGain, colorTemp->blueGain);
	printk(KERN_EMERG "Scaler_SetColorTempData offset(%d, %d, %d)\n",colorTemp->redOffset, colorTemp->greenOffset,colorTemp->blueOffset);
	fwif_color_setrgbcontrast_By_Table(colorTemp->redGain, colorTemp->greenGain, colorTemp->blueGain, 0);
	fwif_color_setrgbbrightness_By_Table(colorTemp->redOffset, colorTemp->greenOffset,colorTemp->blueOffset);
}
unsigned int Scaler_GetDeRinging_level(TV010_LEVEL_E *drLevel)
{
	*drLevel = m_nDRLevel;
	return _SUCCESS;
}
void Scaler_SetDeRinging_level(TV010_LEVEL_E drLevel)
{
	if(drLevel >4)
		return ;
	m_nDRLevel = drLevel;
	DRV_NR_Item *ptr = NULL;
	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	ptr = &(gVip_Table->Manual_NR_Table[Scaler_GetDNR_table()][m_nDRLevel]);
	drvif_color_DRV_SNR_Mosquito_NR(&(ptr->S_SNR_TABLE.S_SNR_Mosquito_NR));
}
unsigned int Scaler_GetSRLevel(TV010_DEMOLEVEL_E *srLevel)
{
	*srLevel = m_nSRLevel;
	return _SUCCESS;
}

void Scaler_SetSRLevel(TV010_DEMOLEVEL_E srLevel)
{
	if(srLevel >4)
		return ;
	m_nSRLevel = srLevel;
	switch(srLevel){
		case TV010_DEMOLEVEL_OFF:
		case TV010_DEMOLEVEL_ON:
			driver_color_setSR(srLevel);
			break;
		case TV010_DEMOLEVEL_DEMO:
			break;
		default:
			break;
		}
}


unsigned int Scaler_GetColorGainLevel(TV010_LEVEL_E *colorGain)
{
	*colorGain = m_nCGLevel;
	return _SUCCESS;
}

void Scaler_SetColorGainLevel(unsigned int icmIndex)
{
	SLR_VIP_TABLE *gVIP_Table;
	unsigned char *drvSkip_Array;
	_system_setting_info *VIP_system_info_structure_table=NULL;
/*
	if(colorGain >4)
		return ;
	m_nCGLevel = colorGain;
	*/
	gVIP_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if(gVIP_Table ==NULL){
		printk("-1-gVIP_Table ==NULL---error!-\n");
		return;
		}
	drvSkip_Array = &(gVIP_Table->DrvSetting_Skip_Flag[0]);
	if(drvSkip_Array ==NULL){
		printk("-1-drvSkip_Array ==NULL---error!-\n");
		return;
		}

	if(icmIndex>9)
		return;

	printk("---icm---file:%s;line:%d;icmTableIndex:%d;flag:%d---\n",__FUNCTION__,__LINE__,icmIndex,drvSkip_Array[DrvSetting_Skip_Flag_ICM]);
	Scaler_set_ICM_table(icmIndex,  drvSkip_Array[DrvSetting_Skip_Flag_ICM]);
}
unsigned int Scaler_GetFleshToneLevel(TV010_LEVEL_E *fleshtone)
{
	*fleshtone = m_nFTLevel;
	return _SUCCESS;
}

void Scaler_SetFleshToneLevel(TV010_LEVEL_E fleshtone)
{
	SLR_VIP_TABLE *gVIP_Table;
	unsigned char *drvSkip_Array;
	_system_setting_info *VIP_system_info_structure_table=NULL;

/*
	if(fleshtone >4)
		return ;
	m_nFTLevel = fleshtone;
	*/

	gVIP_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if(gVIP_Table ==NULL){
		printk("-2-gVIP_Table ==NULL---error!-\n");
		return;
		}
	drvSkip_Array = &(gVIP_Table->DrvSetting_Skip_Flag[0]);
	if(drvSkip_Array ==NULL){
		printk("-2-drvSkip_Array ==NULL---error!-\n");
		return;
		}

	unsigned char HDR_flag;
	VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if(VIP_system_info_structure_table ==NULL){
		printk("-2-VIP_system_info_structure_table ==NULL---error!-\n");
		return;
		}
	HDR_flag = VIP_system_info_structure_table->HDR_flag;
	//get current picMode

	PICTURE_MODE mode;
	SourceOption sourceOption;
	sourceOption = xGetCurSource();
	mode=GetPictureMode(sourceOption);
	unsigned char icmIndex;

	switch(mode){
		case PICTURE_MODE_USER:
		case PICTURE_MODE_STD:
		case PICTURE_MODE_STANDARD:
			if(HDR_flag>0 && HDR_flag < 10)
			icmIndex = TV010_SDR_ICM_STD;
			else
			icmIndex = TV010_HDR_ICM_STD;
			break;
		case PICTURE_MODE_VIVID:
			if(HDR_flag>0 && HDR_flag < 10)
			icmIndex = TV010_SDR_ICM_VIVID;
			else
			icmIndex = TV010_HDR_ICM_VIVID;
			break;
		case PICTURE_MODE_GENTLE:
			if(HDR_flag>0 && HDR_flag < 10)
			icmIndex = TV010_SDR_ICM_GENTLE;
			else
			icmIndex = TV010_HDR_ICM_GENTLE;
			break;
		default:
			icmIndex = TV010_SDR_ICM_STD;
			break;

		}
		printk("---icm---file:%s;line:%d;---\n",__FUNCTION__,__LINE__);
		fwif_color_icm_set_block_para(fleshtone);
	printk("---icm---file:%s;line:%d;mode:%d---\n",__FUNCTION__,__LINE__,mode);
	Scaler_set_ICM_table(icmIndex,  drvSkip_Array[DrvSetting_Skip_Flag_ICM]);
}

void fwif_color_icm_set_block_para(TV010_LEVEL_E fleshtone)
{
/*
	switch(fleshtone){
		case TV010_LEVEL_OFF:
			{
				icm_block_adj.h_offset = 0;
				icm_block_adj.s_offset = 0;
				icm_block_adj.i_offset = 0;
				icm_block_adj.h_sta = 2;
				icm_block_adj.h_end = 6;
				icm_block_adj.s_sta = 0;
				icm_block_adj.s_end = 11;
				icm_block_adj.i_sta = 0;
				icm_block_adj.i_end = 11;
				break;
			}
		case TV010_LEVEL_LOW:
			{
				icm_block_adj.h_offset = 32;
				icm_block_adj.s_offset = 64;
				icm_block_adj.i_offset = 0;
				icm_block_adj.h_sta = 2;
				icm_block_adj.h_end = 6;
				icm_block_adj.s_sta = 0;
				icm_block_adj.s_end = 11;
				icm_block_adj.i_sta = 0;
				icm_block_adj.i_end = 11;
				break;
			}
		case TV010_LEVEL_MID:
			{
				icm_block_adj.h_offset = 64;
				icm_block_adj.s_offset = 128;
				icm_block_adj.i_offset = 0;
				icm_block_adj.h_sta = 2;
				icm_block_adj.h_end = 6;
				icm_block_adj.s_sta = 0;
				icm_block_adj.s_end = 11;
				icm_block_adj.i_sta = 0;
				icm_block_adj.i_end = 11;
				break;
			}
		case TV010_LEVEL_HIGH:
			{
				icm_block_adj.h_offset = 90;
				icm_block_adj.s_offset = 200;
				icm_block_adj.i_offset = 0;
				icm_block_adj.h_sta = 2;
				icm_block_adj.h_end = 6;
				icm_block_adj.s_sta = 0;
				icm_block_adj.s_end = 11;
				icm_block_adj.i_sta = 0;
				icm_block_adj.i_end = 11;
				break;
			}
		default:
			{
				icm_block_adj.h_offset = 0;
				icm_block_adj.s_offset = 0;
				icm_block_adj.i_offset = 0;
				icm_block_adj.h_sta = 2;
				icm_block_adj.h_end = 6;
				icm_block_adj.s_sta = 0;
				icm_block_adj.s_end = 11;
				icm_block_adj.i_sta = 0;
				icm_block_adj.i_end = 11;
			break;
			}

		}

*/
}


unsigned int Scaler_GetODLevel(unsigned int *level)
{
	*level = drvif_color_get_od_gain();// 0~127
	return _SUCCESS;
}

void Scaler_SetODReadEnable(unsigned char enable)
{
  //  NULL
}
unsigned int Scaler_GetGammaNum(unsigned int *number)
{
	*number = 7;
	return _SUCCESS;
}
void Scaler_SetGamma_byLevel(unsigned char Level)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display,& src_idx);

	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;

	unsigned char level;
	if(Level==3)//level = 3 is center, gamma=0.
		return;

	if(Level==2||Level==4)
		level=1;
	else if(Level==1||Level==5)
		level=3;
	else if(Level==0||Level==6)
		level=5;
	else
		level=0;


	if(Level<3)
		fwif_set_software_gamma(pTable->Gamma, 0, level, level);
	else
		fwif_set_software_gamma(pTable->Gamma, 1023, level, level);

}

void Scaler_Set_Software_Gamma(unsigned char gammaIndex)
{
	if(gammaIndex >6)
		return;
	//software_gamma  level 0~6 , level = 3 is center
	Scaler_SetGamma_byLevel(gammaIndex);
}

void Scaler_SetBlackPatternOutput(unsigned char isBlackPattern)
{
	fwif_color_set_WB_Pattern_IRE(isBlackPattern, 0);
}
void Scaler_SetWhitePatternOutput(unsigned char isWhitePattern)
{
	fwif_color_set_WB_Pattern_IRE(isWhitePattern, 100);
}
unsigned int Scaler_GetPQModule(TV010_PQ_MODULE_E pqModule,unsigned char * onOff)
{
	*onOff = TRUE;
	return _SUCCESS;
}
void Scaler_SetPQModule(TV010_PQ_MODULE_E pqModule,unsigned char onOff)
{
#ifdef ANDTV_MAC5_COMPILE_FIX
	switch(pqModule) {
#ifdef ANDTV_PQ_COMPILE_FIX
		case TV010_PQ_MODULE_FMD:
		drvif_color_set_PQ_Module(PQ_ByPass_Fmd,onOff);
		break;
#endif
		case TV010_PQ_MODULE_NR:
		drvif_color_set_PQ_Module(PQ_ByPass_RTNR_Y,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_SNR_Y,onOff);
		break;

		case TV010_PQ_MODULE_DB:
		drvif_color_set_PQ_Module(PQ_ByPass_MPEG_NR,onOff);
		break;

		case TV010_PQ_MODULE_DR:
		drvif_color_set_PQ_Module(PQ_ByPass_MosquiutoNR,onOff);
		break;

		case TV010_PQ_MODULE_HSHARPNESS:
		drvif_color_set_PQ_Module(PQ_ByPass_SHP_DLTI,onOff);
		break;

		case TV010_PQ_MODULE_SHARPNESS:
		drvif_color_set_PQ_Module(PQ_ByPass_SHP,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_SHP_DLTI,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_MB_Peaking,onOff);
		break;

#ifdef ANDTV_PQ_COMPILE_FIX
		case TV010_PQ_MODULE_CCCL:
		drvif_color_set_PQ_Module(PQ_ByPass_CCCL,onOff);
		break;
		case TV010_PQ_MODULE_COLOR_CORING:
		drvif_color_set_PQ_Module(PQ_ByPass_COLOR_CORING,onOff);
		break;
#endif
		case TV010_PQ_MODULE_BLUE_STRETCH:
		if(onOff){
			IoReg_SetBits(0xB802C130, 0x00000003);//_BIT1
		}
		else{
			IoReg_ClearBits(0xB802C130, 0x00000003);//_BIT1
		}
		break;

		case TV010_PQ_MODULE_GAMMA:
		drvif_color_set_PQ_Module(PQ_ByPass_Gamma,onOff);
		break;
#ifdef ANDTV_PQ_COMPILE_FIX
		case TV010_PQ_MODULE_DBC:
		drvif_color_set_PQ_Module(PQ_ByPass_DBC,onOff);
		break;
#endif
		case TV010_PQ_MODULE_DCI:
		drvif_color_set_PQ_Module(PQ_ByPass_DCC,onOff);
		break;

		case TV010_PQ_MODULE_COLOR:
		drvif_color_set_PQ_Module(PQ_ByPass_ICM,onOff);
		break;

		case TV010_PQ_MODULE_ES:
		//drvif_color_set_PQ_Module(PQ_ByPass_RTNR_Y,onOff);
		break;

		case TV010_PQ_MODULE_SR:
		drvif_color_set_PQ_Module(PQ_ByPass_MB_Peaking,onOff);
		break;

		case TV010_PQ_MODULE_FRC:
		HAL_VPQ_MEMC_MotionCompOnOff(onOff);
		break;

		case TV010_PQ_MODULE_WCG:
		drvif_color_set_PQ_Module(PQ_ByPass_ColorTemp,onOff);
		break;

		case TV010_PQ_MODULE_ALL:
		drvif_color_set_PQ_Module(PQ_ByPass_RTNR_Y,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_SNR_Y,onOff);

		drvif_color_set_PQ_Module(PQ_ByPass_SHP,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_SHP_DLTI,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_MB_Peaking,onOff);

		drvif_color_set_PQ_Module(PQ_ByPass_Gamma,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_DCC,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_ICM,onOff);
		drvif_color_set_PQ_Module(PQ_ByPass_ColorTemp,onOff);
		HAL_VPQ_MEMC_MotionCompOnOff(onOff);
		if(onOff){
			IoReg_SetBits(0xB802C130, 0x00000003);//_BIT1
		}
		else{
			IoReg_ClearBits(0xB802C130, 0x00000003);//_BIT1
		}
		break;
	}
#endif
}
unsigned int Scaler_GetSDR2HDR(unsigned char * onOff)
{
#ifdef ANDTV_PQ_COMPILE_FIX
	_system_setting_info *VIP_system_info_structure_table;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	*onOff = VIP_system_info_structure_table->SDR2HDR_flag;
#endif
	return _SUCCESS;
}
void Scaler_SetSDR2HDR(unsigned char onOff)
{
	//Scaler_LGE_ONEKEY_SDR2HDR_Enable(onOff);
	drvif_color_set_LC_Enable(onOff);
}
unsigned int Scaler_GetHdr10Enable(unsigned char * bEnable)
{
	//_system_setting_info *VIP_system_info_structure_table;
	//VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		printk("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return _FAIL;
	}

	*bEnable = VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En];
	return _SUCCESS;
}
void Scaler_SetHdr10Enable(unsigned char bEnable)
{
	Scaler_LGE_ONEKEY_HDR10_Enable(bEnable);
}


unsigned int Scaler_GetSrcHdrInfo(unsigned int * pGammaType)
{
	*pGammaType = TRUE;
	return _SUCCESS;
}
unsigned int Scaler_GetHdrType(TV010_HDR_TYPE_E * pHdrType)
{
#ifdef ANDTV_PQ_COMPILE_FIX

	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return _FAIL;
	}

	if(VIP_RPC_system_info_structure_table->SDR2HDR_flag)
		*pHdrType = TV010_HDR_TYPE_SDR_TO_HDR;
	else if(VIP_RPC_system_info_structure_table->DolbyHDR_flag)
		*pHdrType = TV010_HDR_TYPE_DOLBY_HDR;
	else if(VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En])
		*pHdrType = TV010_HDR_TYPE_HDR10;
	else
		*pHdrType = TV010_HDR_TYPE_SDR;
#endif
	return _SUCCESS;
}
unsigned int Scaler_GetDOLBYHDREnable(unsigned char * bEnable)
{
	_system_setting_info *VIP_system_info_structure_table;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	*bEnable = VIP_system_info_structure_table->DolbyHDR_flag;
	return _SUCCESS;
}
void Scaler_SetDOLBYHDREnable(unsigned char bEnable)
{
	Scaler_set_HDR10_Enable(bEnable);
}


void Scaler_SetDemoMode(TV010_DEMO_MODE_E demoMode,unsigned char onOff)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL || VIP_system_info_structure_table == NULL){
		printk("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if(!onOff){
#ifdef ANDTV_PQ_COMPILE_FIX
		if(VIP_system_info_structure_table->SDR2HDR_flag)
			Scaler_LGE_ONEKEY_SDR2HDR_Enable(onOff);
		else
#endif
			if(VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En])
				Scaler_LGE_ONEKEY_HDR10_Enable(onOff);

		Scaler_SetMagicPicture(SLR_MAGIC_OFF);
		return;
	}
	switch(demoMode) {
		case TV010_DEMO_DBDR :
		break;
		case TV010_DEMO_NR:
		break;
		case TV010_DEMO_SHARPNESS:
			Scaler_SetMagicPicture(SLR_MAGIC_STILLDEMO_INVERSE);
		break;
		case TV010_DEMO_DCI:
		break;
		case TV010_DEMO_WCG:
			//Scaler_SetMagicPicture(SLR_MAGIC_FULLGAMUT);
		break;
		case TV010_DEMO_MEMC:
			//Scaler_SetMagicPicture(SLR_MAGIC_MEMC_STILLDEMO_INVERSE);
		break;
		case TV010_DEMO_COLOR:
		break;
		case TV010_DEMO_SR:
			Scaler_SetMagicPicture(SLR_MAGIC_STILLDEMO_INVERSE);
		break;
		case TV010_DEMO_ALL:
		break;
		case TV010_DEMO_HDR:
			Scaler_SetMagicPicture(SLR_MAGIC_STILLDEMO_INVERSE);
		break;
		case TV010_DEMO_SDR_TO_HDR:
			Scaler_SetMagicPicture(SLR_MAGIC_STILLDEMO_INVERSE);
			Scaler_LGE_ONEKEY_SDR2HDR_Enable(TRUE);
		break;

	}


}

unsigned int Scaler_GetCurrentPanelSupportLocaldimming(unsigned char *support)
{
	*support = FALSE;
	return _SUCCESS;
}

void Scaler_SetLocalDimmingDemoMode(unsigned char mode)
{
#ifdef ANDTV_MAC5_COMPILE_FIX
	Scaler_SetMagicPicture(SLR_MAGIC_LOCALDIMMING_MARQUEE);
#endif
}

unsigned int Scaler_GetLocalDimmingDemoMode(TV010_LOCALDIMMING_DEMO_MODE_E *demoMode)
{
	*demoMode = TV010_LDM_DEMO_OFF;
	return _SUCCESS;
}

void Scaler_SetLocalDimmingSpiEnable(unsigned char bEnable)
{
	rtd_part_outl(0xb802C900,0,0,bEnable); //Ld_spi enable
}

unsigned int Scaler_GetMemcEnable(unsigned char * bEnable)
{
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT
	unsigned char  nMode;
	nMode = (unsigned char)MEMC_LibGetMEMCMode();
	if(nMode == 3)
		*bEnable = FALSE;
	else
		*bEnable = TRUE;
#else
#ifndef CONFIG_MEMC_BYPASS
	*bEnable = (Scaler_MEMC_GetMotionType() == MEMC_TYPE_OFF)?FALSE:TRUE;
#endif
#endif
	return _SUCCESS;
}
unsigned int Scaler_GetMemcRange(TV010_MEMC_RANGE_S *range)
{
	range->min= 0;
	range->max= 128;
	return _SUCCESS;
}
void Scaler_SetMemcLevel(TV010_LEVEL_E level)
{
	if(level == TV010_LEVEL_OFF)
		HAL_VPQ_MEMC_SetMotionComp(0,0,VPQ_MEMC_TYPE_OFF);
	else if(level == TV010_LEVEL_LOW)
		HAL_VPQ_MEMC_SetMotionComp(16,32,VPQ_MEMC_TYPE_LOW);
	else if(level == TV010_LEVEL_MID)
		HAL_VPQ_MEMC_SetMotionComp(94,94,VPQ_MEMC_TYPE_LOW);
	else if(level == TV010_LEVEL_HIGH)
		HAL_VPQ_MEMC_SetMotionComp(128,128,VPQ_MEMC_TYPE_HIGH);
	else if(level == TV010_LEVEL_AUTO)
		HAL_VPQ_MEMC_SetMotionComp(128,128,VPQ_MEMC_TYPE_HIGH);
	else
		HAL_VPQ_MEMC_SetMotionComp(128,128,VPQ_MEMC_TYPE_HIGH);
}

void fwif_color_gamma_encode_TableSize(RTK_TableSize_Gamma *pData)
{
	unsigned short i;
	unsigned short gamma_temp[4];
	unsigned char g_scaler = 3;		// TCL input gamma is 10-bits and 256-scaler      1024 / 256 = 4
	unsigned char j;
	unsigned char OSD_Color_name,OSD_Color_temp;
	unsigned char gammaindex,Gamma_Mode;
	unsigned short maxvalueR=1024,maxvalueG=1024,maxvalueB=1024;

	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVip_Table == NULL) {
		printk("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}


	OSD_Color_name = scaler_get_color_temp_level_type(GET_UI_SOURCE_FROM_PCB());
	Gamma_Mode =1 ;
	//printk("yuan,OSD_Color_name=%d,Gamma_Mode=%d\n",OSD_Color_name,Gamma_Mode);
	switch (OSD_Color_name) {
	case SLR_COLORTEMP_USER:
	case SLR_COLORTEMP_NORMAL:
			OSD_Color_temp = 2;
			break;
	case SLR_COLORTEMP_WARMER:
	case SLR_COLORTEMP_WARM:
			OSD_Color_temp = 1;
			break;
	case SLR_COLORTEMP_COOL:
	case SLR_COLORTEMP_COOLER:
			OSD_Color_temp = 3;
			break;
	default:
			OSD_Color_temp = 3;
			break;
		/*return;*/
	}

	//printk("OSD_Color_temp= %d\n", OSD_Color_temp);
	if (OSD_Color_temp !=  0) {
		switch (OSD_Color_temp) {
		case 1:
				gammaindex = 0;
				break;
		case 2:
				gammaindex = 1;
				break;
		case 3:
				gammaindex = 4;
				break;

		default:
				gammaindex = 0;
				break;
		}
	}
#if 1
	maxvalueR=pData->pu16Gamma_r[255];
	maxvalueG=pData->pu16Gamma_g[255];
	maxvalueB=pData->pu16Gamma_b[255];
	for(i=255;i>1;i--)
	{
		pData->pu16Gamma_r[i]=pData->pu16Gamma_r[i-1];
		pData->pu16Gamma_g[i]=pData->pu16Gamma_g[i-1];
		pData->pu16Gamma_b[i]=pData->pu16Gamma_b[i-1];
	}
	
	pData->pu16Gamma_r[1]=(pData->pu16Gamma_r[1])*2/3;
	pData->pu16Gamma_g[1]=(pData->pu16Gamma_g[1])*2/3;
	pData->pu16Gamma_b[1]=(pData->pu16Gamma_b[1])*2/3;

	//for(i=0;i<3;i++)
		//printk("[tim_li]after mapping low:i=%d,r=%d,g=%d,b=%d \n",i,pData->pu16Gamma_r[i],pData->pu16Gamma_g[i],pData->pu16Gamma_b[i]);

	//for(i=253;i<256;i++)
		//printk("[tim_li]after mapping high:i=%d,r=%d,g=%d,b=%d \n",i,pData->pu16Gamma_r[i],pData->pu16Gamma_g[i],pData->pu16Gamma_b[i]);

	//printk("[tim_li]after mapping max:r=%d,g=%d,b=%d \n",maxvalueR,maxvalueG,maxvalueB);
#endif
	for(i = 0 ; i < 256 ; i++)
	{
		//printk("-lhh001- TCL_g[%d] = %d    %d    %d\n", i, pData->pu16Gamma_r[i], pData->pu16Gamma_g[i], pData->pu16Gamma_b[i]);
		if(i < 255)
		{
			for(j = 0 ; j < 4 ; j++)
			{
				gamma_temp[j] = (pData->pu16Gamma_r[i] + (pData->pu16Gamma_r[i + 1] - pData->pu16Gamma_r[i]) * j / g_scaler) << 2;
			}
			gVip_Table->tGAMMA[gammaindex].R[i * 2] = ((gamma_temp[0] << 16) | ((gamma_temp[1] - gamma_temp[0]) << 8) | (0x04));			
			gVip_Table->tGAMMA[gammaindex].R[i * 2 + 1] = ((gamma_temp[2] << 16) | ((gamma_temp[3] - gamma_temp[2]) << 8) | (0x04));
			
			for(j = 0 ; j < 4 ; j++)
			{
				gamma_temp[j] = (pData->pu16Gamma_g[i] + (pData->pu16Gamma_g[i + 1] - pData->pu16Gamma_g[i]) * j / g_scaler) << 2;
			}
			gVip_Table->tGAMMA[gammaindex].G[i * 2] = ((gamma_temp[0] << 16) | ((gamma_temp[1] - gamma_temp[0]) << 8) | (0x04));
			gVip_Table->tGAMMA[gammaindex].G[i * 2 + 1] = ((gamma_temp[2] << 16) | ((gamma_temp[3] - gamma_temp[2]) << 8) | (0x04));

			for(j = 0 ; j < 4 ; j++)
			{
				gamma_temp[j] = (pData->pu16Gamma_b[i] + (pData->pu16Gamma_b[i + 1] - pData->pu16Gamma_b[i]) * j / g_scaler) << 2;
			}
			gVip_Table->tGAMMA[gammaindex].B[i * 2] = ((gamma_temp[0] << 16) | ((gamma_temp[1] - gamma_temp[0]) << 8) | (0x04));
			gVip_Table->tGAMMA[gammaindex].B[i * 2 + 1] = ((gamma_temp[2] << 16) | ((gamma_temp[3] - gamma_temp[2]) << 8) | (0x04));
		}
		else
		{
			
			for(j = 0 ; j < 4 ; j++)
			{
				gamma_temp[j] = (pData->pu16Gamma_r[i] + (maxvalueR/*1024*/ - pData->pu16Gamma_r[i]) * j / g_scaler) << 2;
				
			}
			gVip_Table->tGAMMA[gammaindex].R[i * 2] = ((gamma_temp[0] << 16) | ((gamma_temp[1] - gamma_temp[0]) << 8) | (0x04));
			gVip_Table->tGAMMA[gammaindex].R[i * 2 + 1] = ((gamma_temp[2] << 16) | ((gamma_temp[3] - gamma_temp[2]) << 8) | (0x04));

			for(j = 0 ; j < 4 ; j++)
			{
				gamma_temp[j] = (pData->pu16Gamma_g[i] + (maxvalueG - pData->pu16Gamma_g[i]) * j / g_scaler) << 2;
			}
			gVip_Table->tGAMMA[gammaindex].G[i * 2] = ((gamma_temp[0] << 16) | ((gamma_temp[1] - gamma_temp[0]) << 8) | (0x04));
			gVip_Table->tGAMMA[gammaindex].G[i * 2 + 1] = ((gamma_temp[2] << 16) | ((gamma_temp[3] - gamma_temp[2]) << 8) | (0x04));

			for(j = 0 ; j < 4 ; j++)
			{
				gamma_temp[j] = (pData->pu16Gamma_b[i] + (maxvalueB - pData->pu16Gamma_b[i]) * j / g_scaler) << 2;
			}
			gVip_Table->tGAMMA[gammaindex].B[i * 2] = ((gamma_temp[0] << 16) | ((gamma_temp[1] - gamma_temp[0]) << 8) | (0x04));
			gVip_Table->tGAMMA[gammaindex].B[i * 2 + 1] = ((gamma_temp[2] << 16) | ((gamma_temp[3] - gamma_temp[2]) << 8) | (0x04));
		}


	}
	
	//for(i=0 ; i<12 ; i++)
		//printk("-lhh002- VIP_g[%d]: r=%x,g=%x, b=%x \n", i, gVip_Table->tGAMMA[gammaindex].R[i], gVip_Table->tGAMMA[gammaindex].G[i], gVip_Table->tGAMMA[gammaindex].B[i]  );
	//for(i=100 ; i<112 ; i++)
		//printk("-lhh002- VIP_g[%d]: r=%x,g=%x, b=%x \n", i, gVip_Table->tGAMMA[gammaindex].R[i], gVip_Table->tGAMMA[gammaindex].G[i], gVip_Table->tGAMMA[gammaindex].B[i]  );
	//for(i=500 ; i<512 ; i++)
		//printk("-lhh002- VIP_g[%d]: r=%x,g=%x, b=%x \n", i, gVip_Table->tGAMMA[gammaindex].R[i], gVip_Table->tGAMMA[gammaindex].G[i], gVip_Table->tGAMMA[gammaindex].B[i]  );

	
}


unsigned char Scaler_Get_LC_blk_hnum(void)
{

	return fwif_color_get_LC_blk_hnum();

}

unsigned char Scaler_Get_LC_blk_vnum(void)
{

	return fwif_color_get_LC_blk_vnum();

}

unsigned char Scaler_Get_LD_Enable(void)
{

	return fwif_color_get_LD_Enable();

}

UINT8 fwif_color_get_DM2_HDR_histogram_TV030(UINT32* HDR_info)
{
	drvif_DM2_HDR_RGB_max_Get(HDR_info);
	return drvif_DM2_HDR_histogram_Get(HDR_info + 3);
}

UINT8 fwif_color_get_DM_HDR10_enable_TV030(void)
{
	return drvif_DM_HDR10_enable_Get();
}

void Scaler_Set_Partten4AutoGamma(unsigned char  Enable, unsigned short  r_Val,unsigned short  g_Val,unsigned short  b_Val)
{
	drvif_color_set_Partten4AutoGamma( Enable ,r_Val,g_Val,b_Val);
}

void Scaler_Set_Partten4AutoGamma_mute(unsigned char mute_flag, unsigned char display_flag,SCALER_DISPLAY_DATA* sdp_info)
{
	drvif_color_set_Partten4AutoGamma_mute(mute_flag,display_flag,(Drvif_SCALER_DISPLAY_DATA*)sdp_info);
}
void Scaler_Get_ScreenPixel_info(SCREEN_PIXEL_INFO* sp_info)
{
    	printk("scaler_get_screen_pixel_info !!!!h_sta(%d)===h_end(%d)!\n",sp_info->h_sta,sp_info->h_end);
	printk("scaler_get_screen_pixel_info !!!!v_sta(%d)===v_end(%d)!\n",sp_info->v_sta,sp_info->v_end);
	UINT16 i, j, k;
	UINT16 width, hight;
	UINT16 h_read_num, v_read_num;
	UINT32 total_pixel;
	yuv2rgb_accessdata_ctrl_RBUS yuv2rgb_accessdata_ctrl_reg;
	yuv2rgb_accessdata_posctrl_RBUS yuv2rgb_accessdata_posctrl_reg;
	yuv2rgb_readdata_data_y1_RBUS yuv2rgb_readdata_data_y1_reg;
	yuv2rgb_readdata_data_y2_RBUS yuv2rgb_readdata_data_y2_reg;
	yuv2rgb_readdata_data_c1_RBUS yuv2rgb_readdata_data_c1_reg;
	yuv2rgb_readdata_data_c2_RBUS yuv2rgb_readdata_data_c2_reg;
	yuv2rgb_readdata_data_c3_RBUS yuv2rgb_readdata_data_c3_reg;
	yuv2rgb_readdata_data_c4_RBUS yuv2rgb_readdata_data_c4_reg;

	sp_info->r_sum = 0;
	sp_info->g_sum = 0;
	sp_info->b_sum = 0;

	width = sp_info->h_end - sp_info->h_sta + 1;
	hight = sp_info->v_end - sp_info->v_sta + 1;
	total_pixel = width * hight;
    printk("The capture window too large, get screen pixel  total_pixel(%d)!!!\n",total_pixel);
	//if(total_pixel > 200)
	//{
	//	printk("The capture window too large, get screen pixel fail !!!\n");
	//	return;
	//}


	if(width % 2 != 0)
		h_read_num = width / 2 + 1;
	else
		h_read_num = width / 2;
	
	if(hight % 2 != 0)
		v_read_num = hight / 2 + 1;
	else
		v_read_num = hight /2;

	for(j = 0 ; j < v_read_num ; j++)
	{
		for(i = 0 ; i < h_read_num ; i++)
		{
			yuv2rgb_accessdata_posctrl_reg.startx = sp_info->h_sta + i * 2;
			yuv2rgb_accessdata_posctrl_reg.starty = sp_info->v_sta + j * 2;
			IoReg_Write32(YUV2RGB_AccessData_PosCtrl_reg, yuv2rgb_accessdata_posctrl_reg.regValue);
			
			yuv2rgb_accessdata_ctrl_reg.read_en = 1;
			IoReg_Write32(YUV2RGB_AccessData_CTRL_reg, yuv2rgb_accessdata_ctrl_reg.regValue);
			
			msleep(18);
			k = 1000;
			while(k != 0)
			{
				--k;
				yuv2rgb_accessdata_ctrl_reg.regValue = IoReg_Read32(YUV2RGB_AccessData_CTRL_reg);
				if(yuv2rgb_accessdata_ctrl_reg.read_en == 0)
					break;
			}

			//for debug
			if(k == 0)
				printk("\n YUV2RGB Data Access time out.  \n");

			yuv2rgb_readdata_data_y1_reg.regValue = IoReg_Read32(YUV2RGB_ReadData_DATA_Y1_reg);
			yuv2rgb_readdata_data_y2_reg.regValue = IoReg_Read32(YUV2RGB_ReadData_DATA_Y2_reg);
			yuv2rgb_readdata_data_c1_reg.regValue = IoReg_Read32(YUV2RGB_ReadData_DATA_C1_reg);
			yuv2rgb_readdata_data_c2_reg.regValue = IoReg_Read32(YUV2RGB_ReadData_DATA_C2_reg);
			yuv2rgb_readdata_data_c3_reg.regValue = IoReg_Read32(YUV2RGB_ReadData_DATA_C3_reg);
			yuv2rgb_readdata_data_c4_reg.regValue = IoReg_Read32(YUV2RGB_ReadData_DATA_C4_reg);

			sp_info->r_sum += yuv2rgb_readdata_data_y1_reg.y00 >> 6;
			sp_info->g_sum += yuv2rgb_readdata_data_c1_reg.u00 >> 6;
			sp_info->b_sum += yuv2rgb_readdata_data_c1_reg.v00 >> 6;
			if((--total_pixel) == 0)
			{
				//printk("\n--lhh00-- total  R=%x   G=%x   B=%x  \n", sp_info->r_sum, sp_info->g_sum, sp_info->b_sum);
				return;
			}

			sp_info->r_sum += yuv2rgb_readdata_data_y1_reg.y01 >> 6;
			sp_info->g_sum += yuv2rgb_readdata_data_c2_reg.u01 >> 6;
			sp_info->b_sum += yuv2rgb_readdata_data_c2_reg.v01 >> 6;
			if((--total_pixel) == 0)
			{
				//printk("\n--lhh01-- total  R=%x   G=%x   B=%x  \n", sp_info->r_sum, sp_info->g_sum, sp_info->b_sum);
				return;
			}
			
			sp_info->r_sum += yuv2rgb_readdata_data_y2_reg.y10 >> 6;
			sp_info->g_sum += yuv2rgb_readdata_data_c3_reg.u10 >> 6;
			sp_info->b_sum += yuv2rgb_readdata_data_c3_reg.v10 >> 6;
			if((--total_pixel) == 0)
			{
				//printk("\n--lhh10-- total  R=%x   G=%x   B=%x  \n",sp_info->r_sum, sp_info->g_sum, sp_info->b_sum);
				return;
			}

			sp_info->r_sum += yuv2rgb_readdata_data_y2_reg.y11 >> 6;
			sp_info->g_sum += yuv2rgb_readdata_data_c4_reg.u11 >> 6;
			sp_info->b_sum += yuv2rgb_readdata_data_c4_reg.v11 >> 6;
			if((--total_pixel) == 0)
			{
				//printk("\n--lhh11-- total  R=%x   G=%x   B=%x  \n", sp_info->r_sum, sp_info->g_sum, sp_info->b_sum);
				return;
			}
			
		}
	}
	
}

unsigned char hdmi_provider_type_mode=0;

void Scaler_Set_hdmi_provider_type(unsigned char mode)
{
	
	printk("yuan,Scaler_Set_PCmode=%d\n",mode);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		printk("[%s:%d] Warning here!! RPC_system_info=NULL!(%d) \n",__FILE__, __LINE__,VIP_RPC_system_info_structure_table);
		return;
	}

	if(mode==ON){
		fwif_color_PQ_ByPass_Handler(4, 1, VIP_RPC_system_info_structure_table, 0);
		drvif_color_set_LC_Enable(OFF);
	}
	else{
		fwif_color_video_quality_handler();	
		drvif_color_set_LC_Enable(drvif_color_get_LC_Enable());
	}
	hdmi_provider_type_mode=mode;
	
}

void fwif_color_set_cinema_mode_en_TV030(unsigned char bEn)
{
	bCinemaModeEn = bEn;

	return;
}

unsigned char fwif_color_get_cinema_mode_en_TV030(void)
{
	return bCinemaModeEn;
}


void Scaler_GetYuvUV2RGB_Original(YuvUV2RGB_Original* p_demo_yuv2rgb )
{
	//yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS yuv2rgb_tab1_data_clamp_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS yuv2rgb_tab1_data_0_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS yuv2rgb_tab1_data_1_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS yuv2rgb_tab1_data_2_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS yuv2rgb_tab1_data_3_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS yuv2rgb_tab1_data_4_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS yuv2rgb_tab1_data_5_REG;
	yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS yuv2rgb_tab1_data_6_REG;
	//yuv2rgb_d_yuv2rgb_tab1_data_7_RBUS yuv2rgb_tab1_data_7_REG;	

	//yuv2rgb_tab1_data_clamp_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg);
	yuv2rgb_tab1_data_0_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg);
	yuv2rgb_tab1_data_1_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg);
	yuv2rgb_tab1_data_2_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg);
	yuv2rgb_tab1_data_3_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg);
	yuv2rgb_tab1_data_4_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg);
	yuv2rgb_tab1_data_5_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg);
	yuv2rgb_tab1_data_6_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg);
	//yuv2rgb_tab1_data_7_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab1_Data_7_reg);

	p_demo_yuv2rgb->k_11 = yuv2rgb_tab1_data_0_REG.k11;
	p_demo_yuv2rgb->k_12 = yuv2rgb_tab1_data_0_REG.k12;
	p_demo_yuv2rgb->k_13 = yuv2rgb_tab1_data_1_REG.k13;
	p_demo_yuv2rgb->k_22 = yuv2rgb_tab1_data_2_REG.k22;
	p_demo_yuv2rgb->k_23 = yuv2rgb_tab1_data_2_REG.k23;
	p_demo_yuv2rgb->k_32 = yuv2rgb_tab1_data_3_REG.k32;
	p_demo_yuv2rgb->k_33 = yuv2rgb_tab1_data_3_REG.k33;
	p_demo_yuv2rgb->r_offset = yuv2rgb_tab1_data_4_REG.roffset;
	p_demo_yuv2rgb->g_offset = yuv2rgb_tab1_data_5_REG.goffset;
	p_demo_yuv2rgb->b_offset = yuv2rgb_tab1_data_6_REG.boffset;
	//p_demo_yuv2rgb->bt_2020 = yuv2rgb_tab1_data_clamp_REG.bt2020_en;
	//p_demo_yuv2rgb->k_132 = yuv2rgb_tab1_data_7_REG.k132;
	//p_demo_yuv2rgb->k_322 = yuv2rgb_tab1_data_7_REG.k322;
	
}

void Scaler_SetYUV2RGBDemo(unsigned char mode)
{
	#if 0 // removed table 2 in mac5p
	YuvUV2RGB_Original t_demo_yuv2rgb;

	yuv2rgb_d_yuv2rgb_control_RBUS yuv2rgb_control_REG;
	yuv2rgb_d_yuv2rgb_control_1_RBUS yuv2rgb_control_1_reg;
	//yuv2rgb_d_yuv2rgb_tab2_data_clamp_RBUS yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG;
	yuv2rgb_d_yuv2rgb_tab2_data_0_RBUS yuv2rgb_tab2_data_0_REG;
	yuv2rgb_d_yuv2rgb_tab2_data_1_RBUS yuv2rgb_tab2_data_1_REG;
	yuv2rgb_d_yuv2rgb_tab2_data_2_RBUS yuv2rgb_tab2_data_2_REG;
	yuv2rgb_d_yuv2rgb_tab2_data_3_RBUS yuv2rgb_tab2_data_3_REG;
	yuv2rgb_d_yuv2rgb_tab2_data_4_RBUS yuv2rgb_tab2_data_4_REG;
	yuv2rgb_d_yuv2rgb_tab2_data_5_RBUS yuv2rgb_tab2_data_5_REG;
	yuv2rgb_d_yuv2rgb_tab2_data_6_RBUS yuv2rgb_tab2_data_6_REG;
	//yuv2rgb_d_yuv2rgb_tab2_data_7_RBUS yuv2rgb_tab2_data_7_REG;

	yuv2rgb_control_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_reg);
	//yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Tab2_Data_Clamp_reg);
	Scaler_GetYuvUV2RGB_Original(&t_demo_yuv2rgb);

	switch(mode)
	{
		// saturation
		case 1:
			yuv2rgb_tab2_data_0_REG.k11 = t_demo_yuv2rgb.k_11;
			yuv2rgb_tab2_data_0_REG.k12 = t_demo_yuv2rgb.k_12;
			yuv2rgb_tab2_data_1_REG.k13 = t_demo_yuv2rgb.k_13;
			yuv2rgb_tab2_data_2_REG.k22 = t_demo_yuv2rgb.k_22;
			yuv2rgb_tab2_data_2_REG.k23 = t_demo_yuv2rgb.k_23;
			yuv2rgb_tab2_data_3_REG.k32 = t_demo_yuv2rgb.k_32;
			yuv2rgb_tab2_data_3_REG.k33 = t_demo_yuv2rgb.k_33;
			yuv2rgb_tab2_data_4_REG.roffset = t_demo_yuv2rgb.r_offset;
			yuv2rgb_tab2_data_5_REG.goffset = t_demo_yuv2rgb.g_offset;
			yuv2rgb_tab2_data_6_REG.boffset = t_demo_yuv2rgb.b_offset;

			yuv2rgb_tab2_data_1_REG.k13 /= 2;
			yuv2rgb_tab2_data_2_REG.k22 = 0;
			yuv2rgb_tab2_data_2_REG.k23 = 0;
			yuv2rgb_tab2_data_3_REG.k32 /= 2;
			yuv2rgb_control_REG.yuv2rgb_overlay = 1;		//enable overlay
			break;
			

		// error matrix
		case 2:
			yuv2rgb_tab2_data_0_REG.k11 = t_demo_yuv2rgb.k_11;
			yuv2rgb_tab2_data_1_REG.k13 = t_demo_yuv2rgb.k_13;
			yuv2rgb_tab2_data_2_REG.k22 = t_demo_yuv2rgb.k_22;
			yuv2rgb_tab2_data_2_REG.k23 = t_demo_yuv2rgb.k_23;
			yuv2rgb_tab2_data_3_REG.k32 = t_demo_yuv2rgb.k_32;
			yuv2rgb_tab2_data_4_REG.roffset = t_demo_yuv2rgb.r_offset;
			yuv2rgb_tab2_data_5_REG.goffset = t_demo_yuv2rgb.g_offset;
			yuv2rgb_tab2_data_6_REG.boffset = t_demo_yuv2rgb.b_offset;
			//yuv2rgb_tab2_data_7_REG.k132 = t_demo_yuv2rgb.k_132;
			//yuv2rgb_tab2_data_7_REG.k322 = t_demo_yuv2rgb.k_322;
			//yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.bt2020_en = t_demo_yuv2rgb.bt_2020;

			yuv2rgb_tab2_data_0_REG.k12 = 300;
			yuv2rgb_tab2_data_3_REG.k33 = -300;
			yuv2rgb_control_REG.yuv2rgb_overlay = 1;		//enable overlay
			break;

		// limit range output
		case 3:
			//yuv2rgb_tab2_data_7_REG.k132 = t_demo_yuv2rgb.k_132;
			//yuv2rgb_tab2_data_7_REG.k322 = t_demo_yuv2rgb.k_322;
			//yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.bt2020_en = t_demo_yuv2rgb.bt_2020;

		yuv2rgb_tab2_data_0_REG.k11 = 0x100;
			yuv2rgb_tab2_data_0_REG.k12 = 0x000;
			yuv2rgb_tab2_data_1_REG.k13 = 0x18a;
			yuv2rgb_tab2_data_2_REG.k22 = 0x7d1;
			yuv2rgb_tab2_data_2_REG.k23 = 0x78b;
			yuv2rgb_tab2_data_3_REG.k32 = 0x1d1;
			yuv2rgb_tab2_data_3_REG.k33 = 0x000;
			yuv2rgb_tab2_data_4_REG.roffset = 0x000;
			yuv2rgb_tab2_data_5_REG.goffset = 0x000;
			yuv2rgb_tab2_data_6_REG.boffset = 0x000;
			yuv2rgb_control_REG.yuv2rgb_overlay = 1;		//disable overlay
			break;

		// enable bt2020
		case 4:
			yuv2rgb_tab2_data_0_REG.k11 = t_demo_yuv2rgb.k_11;
			yuv2rgb_tab2_data_0_REG.k12 = t_demo_yuv2rgb.k_12;
			yuv2rgb_tab2_data_1_REG.k13 = t_demo_yuv2rgb.k_13;
			yuv2rgb_tab2_data_2_REG.k22 = t_demo_yuv2rgb.k_22;
			yuv2rgb_tab2_data_2_REG.k23 = t_demo_yuv2rgb.k_23;
			yuv2rgb_tab2_data_3_REG.k32 = t_demo_yuv2rgb.k_32;
			yuv2rgb_tab2_data_3_REG.k33 = t_demo_yuv2rgb.k_33;
			yuv2rgb_tab2_data_4_REG.roffset = t_demo_yuv2rgb.r_offset;
			yuv2rgb_tab2_data_5_REG.goffset = t_demo_yuv2rgb.g_offset;
			yuv2rgb_tab2_data_6_REG.boffset = t_demo_yuv2rgb.b_offset;

			//yuv2rgb_tab2_data_7_REG.k132 = 100;
			//yuv2rgb_tab2_data_7_REG.k322 = 100;
			//yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.bt2020_en = 1;	// enable bt2020
			yuv2rgb_control_REG.yuv2rgb_overlay = 1;		//enable overlay
			break;

		// limit range output
		case 5:
			//yuv2rgb_tab2_data_7_REG.k132 = t_demo_yuv2rgb.k_132;
			//yuv2rgb_tab2_data_7_REG.k322 = t_demo_yuv2rgb.k_322;			
			//yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.bt2020_en = t_demo_yuv2rgb.bt_2020;

			yuv2rgb_tab2_data_0_REG.k11 = 0x100;
			yuv2rgb_tab2_data_0_REG.k12 = 0x000;
			yuv2rgb_tab2_data_1_REG.k13 = 0x18a;
			yuv2rgb_tab2_data_2_REG.k22 = 0x7d1;
			yuv2rgb_tab2_data_2_REG.k23 = 0x78b;
			yuv2rgb_tab2_data_3_REG.k32 = 0x1d1;
			yuv2rgb_tab2_data_3_REG.k33 = 0x000;
			yuv2rgb_tab2_data_4_REG.roffset = 0x000;
			yuv2rgb_tab2_data_5_REG.goffset = 0x000;
			yuv2rgb_tab2_data_6_REG.boffset = 0x000;
			yuv2rgb_control_REG.yuv2rgb_overlay = 1;		//enable overlay
			yuv2rgb_control_REG.yuv2rgb_main_tab_sel = 1;
			break;

		// yuv2rgb tab2 all setting as same tab1 and disable overlay
		case 0:
		default:
			yuv2rgb_tab2_data_0_REG.k11 = t_demo_yuv2rgb.k_11;
			yuv2rgb_tab2_data_0_REG.k12 = t_demo_yuv2rgb.k_12;
			yuv2rgb_tab2_data_1_REG.k13 = t_demo_yuv2rgb.k_13;
		yuv2rgb_tab2_data_2_REG.k22 = t_demo_yuv2rgb.k_22;
			yuv2rgb_tab2_data_2_REG.k23 = t_demo_yuv2rgb.k_23;
			yuv2rgb_tab2_data_3_REG.k32 = t_demo_yuv2rgb.k_32;
			yuv2rgb_tab2_data_3_REG.k33 = t_demo_yuv2rgb.k_33;
			yuv2rgb_tab2_data_4_REG.roffset = t_demo_yuv2rgb.r_offset;
			yuv2rgb_tab2_data_5_REG.goffset = t_demo_yuv2rgb.g_offset;
			yuv2rgb_tab2_data_6_REG.boffset = t_demo_yuv2rgb.b_offset;
			//yuv2rgb_tab2_data_7_REG.k132 = t_demo_yuv2rgb.k_132;
			//yuv2rgb_tab2_data_7_REG.k322 = t_demo_yuv2rgb.k_322;
			//yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.bt2020_en = t_demo_yuv2rgb.bt_2020;
			yuv2rgb_control_REG.yuv2rgb_overlay = 0;		//disable overlay
			yuv2rgb_control_REG.yuv2rgb_main_tab_sel = 0;
			yuv2rgb_control_REG.yuv2rgb_sub_tab_sel = 1;
			break;
	}
	
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_0_reg, yuv2rgb_tab2_data_0_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_1_reg, yuv2rgb_tab2_data_1_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_2_reg, yuv2rgb_tab2_data_2_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_3_reg, yuv2rgb_tab2_data_3_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_4_reg, yuv2rgb_tab2_data_4_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_5_reg, yuv2rgb_tab2_data_5_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_6_reg, yuv2rgb_tab2_data_6_REG.regValue);
	//IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_7_reg, yuv2rgb_tab2_data_7_REG.regValue);
	//IoReg_Write32(YUV2RGB_D_YUV2RGB_Tab2_Data_Clamp_reg, yuv2rgb_d_yuv2rgb_tab2_data_clamp_REG.regValue);
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_reg, yuv2rgb_control_REG.regValue);

	yuv2rgb_control_1_reg.regValue = IoReg_Read32(YUV2RGB_D_YUV2RGB_Control_1_reg);
	yuv2rgb_control_1_reg.yuv2rgb_db_apply = 1;
	IoReg_Write32(YUV2RGB_D_YUV2RGB_Control_1_reg, yuv2rgb_control_1_reg.regValue);
	#endif
}

void Scaler_SetRGBGainDemo(unsigned char onoff)
{
	#if 0
	con_bri_dm_contrast_a_RBUS dm_contrast_a_REG;
	con_bri_ds_color_rgb_ctrl_RBUS ds_color_rgb_ctrl_REG;
	con_bri_ds_contrast_a_RBUS ds_contrast_a_REG;

	dm_contrast_a_REG.regValue = IoReg_Read32(CON_BRI_DM_CONTRAST_A_reg);
	ds_color_rgb_ctrl_REG.regValue = IoReg_Read32(CON_BRI_DS_COLOR_RGB_CTRL_reg);

	if(onoff)
	{
		ds_contrast_a_REG.s_con_a_r = dm_contrast_a_REG.m_con_a_r - 0x80;
		ds_contrast_a_REG.s_con_a_g = dm_contrast_a_REG.m_con_a_g - 0x80;
		ds_contrast_a_REG.s_con_a_b = dm_contrast_a_REG.m_con_a_b - 0x80;
		ds_color_rgb_ctrl_REG.s_con_en = 1;
	}
	else
	{
		ds_contrast_a_REG.s_con_a_r = dm_contrast_a_REG.m_con_a_r;
		ds_contrast_a_REG.s_con_a_g = dm_contrast_a_REG.m_con_a_g;
		ds_contrast_a_REG.s_con_a_b = dm_contrast_a_REG.m_con_a_b;
		ds_color_rgb_ctrl_REG.s_con_en = 0;
	}
	IoReg_Write32(CON_BRI_DS_CONTRAST_A_reg, ds_contrast_a_REG.regValue);
	IoReg_Write32(CON_BRI_DS_COLOR_RGB_CTRL_reg, ds_color_rgb_ctrl_REG.regValue);
	#endif
	
}

void Scaler_SetRGBBrightnessDemo(unsigned char onoff)
{
	#if 0
	con_bri_dm_brightness_1_RBUS con_bri_dm_brightness_1_reg;
	con_bri_ds_brightness_1_RBUS con_bri_ds_brightness_1_reg;
	//con_bri_ds_color_rgb_ctrl_RBUS ds_color_rgb_ctrl_REG;

	con_bri_dm_brightness_1_reg.regValue = IoReg_Read32(CON_BRI_DM_Brightness_1_reg);
	//ds_color_rgb_ctrl_REG.regValue = IoReg_Read32(CON_BRI_DS_COLOR_RGB_CTRL_reg);

	if(onoff)
	{
		con_bri_ds_brightness_1_reg.s_bri1_r = con_bri_dm_brightness_1_reg.m_bri1_r + 0x80;
		con_bri_ds_brightness_1_reg.s_bri1_g = con_bri_dm_brightness_1_reg.m_bri1_g + 0x80;
		con_bri_ds_brightness_1_reg.s_bri1_b = con_bri_dm_brightness_1_reg.m_bri1_b + 0x80;
		//ds_color_rgb_ctrl_REG.s_bri_en = 1;
	}
	else
	{
		con_bri_ds_brightness_1_reg.s_bri1_r = con_bri_dm_brightness_1_reg.m_bri1_r;
		con_bri_ds_brightness_1_reg.s_bri1_g = con_bri_dm_brightness_1_reg.m_bri1_g;
		con_bri_ds_brightness_1_reg.s_bri1_b = con_bri_dm_brightness_1_reg.m_bri1_b;
		//ds_color_rgb_ctrl_REG.s_bri_en = 0;
	}
	IoReg_Write32(CON_BRI_DM_Brightness_1_reg, con_bri_dm_brightness_1_reg.regValue);
	//IoReg_Write32(CON_BRI_DS_COLOR_RGB_CTRL_reg, ds_color_rgb_ctrl_REG.regValue);
	#endif
}

void Scaler_SetDCCDemo(unsigned char onoff)
{
	color_dcc_d_dcc_ctrl_RBUS color_dcc_d_dcc_ctrl_reg;

	color_dcc_d_dcc_ctrl_reg.regValue = IoReg_Read32(COLOR_DCC_D_DCC_CTRL_reg);

	if(onoff)
		color_dcc_d_dcc_ctrl_reg.dcc_main_en = 1;
	else
		color_dcc_d_dcc_ctrl_reg.dcc_main_en = 0;

	IoReg_Write32(COLOR_DCC_D_DCC_CTRL_reg, color_dcc_d_dcc_ctrl_reg.regValue);
}

void Scaler_SetIcmDemo(unsigned char onoff)
{
	color_icm_dm_icm_ctrl_RBUS	 dm_icm_ctrl_reg;
	
	dm_icm_ctrl_reg.regValue = IoReg_Read32(COLOR_ICM_DM_ICM_CTRL_reg);

	if(onoff)
		dm_icm_ctrl_reg.m_icm_bypass_en = 1;
	else
		dm_icm_ctrl_reg.m_icm_bypass_en = 0;

	IoReg_Write32(COLOR_ICM_DM_ICM_CTRL_reg, dm_icm_ctrl_reg.regValue);
}

void Scaler_SetLocalContrastDemo(unsigned char onoff)
{
	DRV_LC_Demo_Window lc_window;

	lc_window.lc_demo_left = (Scaler_GetMAG_H_Region_End() - Scaler_GetMAG_H_Region_Start()) / 2;
	lc_window.lc_demo_right = Scaler_GetMAG_H_Region_End() - 1;
	lc_window.lc_demo_top = Scaler_GetMAG_V_Region_Start();
	lc_window.lc_demo_bottom = Scaler_GetMAG_V_Region_End();
	lc_window.lc_demo_mode = 0;
	lc_window.lc_demo_en = onoff;

	drvif_color_set_LC_Demo_Window(&lc_window);
}

void Scaler_SetLight_Window_Enable(unsigned char onoff)
{
	#if 0
	unsigned short hsta, width, vsta, len;
	ppoverlay_highlight_window_control_RBUS window_ctrl_reg;
	ppoverlay_highlight_window_h_initial_start_width_RBUS window_h_reg;
	ppoverlay_highlight_window_v_initial_start_height_RBUS window_v_reg;

	window_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_control_reg);
	window_h_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_H_initial_start_width_reg);
	window_v_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_V_initial_start_height_reg);

	window_h_reg.hlw_h_ini_sta = Scaler_GetMAG_H_Region_Start();
	window_h_reg.hlw_ini_width = (Scaler_GetMAG_H_Region_End() - Scaler_GetMAG_H_Region_Start()) / 2;
	window_v_reg.hlw_v_ini_sta = Scaler_GetMAG_V_Region_Start();
	window_v_reg.hlw_ini_height = Scaler_GetMAG_V_Region_End() - Scaler_GetMAG_V_Region_Start();

	#if 0
	printk("\n\n\nScaler_SetLight_Window_Enable1111 window_h_reg.hlw_h_ini_sta = (%d)\n\n\n",window_h_reg.hlw_h_ini_sta);
	printk("\n\n\nScaler_SetLight_Window_Enable2222 window_h_reg.hlw_ini_width = (%d)\n\n\n",window_h_reg.hlw_ini_width);
	printk("\n\n\nScaler_SetLight_Window_Enable3333 window_v_reg.hlw_v_ini_sta = (%d)\n\n\n",window_v_reg.hlw_v_ini_sta);
	printk("\n\n\nsScaler_SetLight_Window_Enable4444 window_v_reg.hlw_ini_height = (%d)\n\n\n",window_v_reg.hlw_ini_height);
	#endif
	window_ctrl_reg.hlw_mode = 1;
	window_ctrl_reg.hlw_en = onoff;

	IoReg_Write32(PPOVERLAY_Highlight_window_H_initial_start_width_reg, window_h_reg.regValue);
	IoReg_Write32(PPOVERLAY_Highlight_window_V_initial_start_height_reg, window_v_reg.regValue);
	IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, window_ctrl_reg.regValue);
	IoReg_Write32(PPOVERLAY_Highlight_window_DB_CTRL_reg, 0x1);
	IoReg_SetBits(COLOR_D_VC_Global_CTRL_reg, _BIT28);
	#endif
}


//extern unsigned short Power22InvGammaa[1025];
void Scaler_SetLight_Window_forDemo(Light_Window_forDemo_E demoMode, unsigned char onoff)
{
	_system_setting_info *VIP_system_info_structure_table;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

   unsigned short *invGammaTBL;
	//invGammaTBL = &Power22InvGammaa[0];
	Scaler_SetYUV2RGBDemo(_DISABLE);				// disable all yuv2rgb demo mode
	Scaler_SetRGBGainDemo(_DISABLE);				// disable sub channel rgb gain 
	Scaler_SetRGBBrightnessDemo(_DISABLE);			// disable sub channel rgb offset
	Scaler_SetDCCDemo(_DISABLE);					// disable dcc overlay
	Scaler_SetIcmDemo(_DISABLE);					// disable icm overlay
	Scaler_SetLocalContrastDemo(_DISABLE);			// disable lc demo mode
	Scaler_SetLight_Window_Enable(_DISABLE);	      // disable high light window

	switch(demoMode)
	{
		
		case PQ_DEMO_2K_TO_4K:
			drvif_color_Sharpness_Enable(onoff);
			break;

		#if 0
		case PQ_DEMO_MEMC:
			if(onoff)
				HAL_VPQ_MEMC_SetMotionComp(128, 128, VPQ_MEMC_TYPE_HIGH);
			else
				HAL_VPQ_MEMC_SetMotionComp(0, 0, VPQ_MEMC_TYPE_OFF);
			break;
		#endif
		
		case PQ_DEMO_COLOR_ANALYSIS:
			if(onoff)
			{
				Scaler_SetYUV2RGBDemo(4);		// yuv2rgb demo mode 4 (bt 2020)
				Scaler_SetLight_Window_Enable(_ENABLE);	// enable high light window
			}
			break;

		case PQ_DEMO_COLOR_ENHANCE:
			if(onoff)
			{
				Scaler_SetIcmDemo(_ENABLE);		// ICM overlay
				Scaler_SetLight_Window_Enable(_ENABLE);	// enable high light window
			}
			break;

		case PQ_DEMO_HDR_SIDE_BY_SIDE:
			if(onoff)
			{
				Scaler_SetLocalContrastDemo(_ENABLE);
				Scaler_SetYUV2RGBDemo(3);		// yuv2rgb demo mode 3 (limit range)
				drvif_color_set_LC_Enable(_ENABLE);
				//fwif_color_set_InvGamma(1, 1, invGammaTBL, invGammaTBL, invGammaTBL);//enable sub inverse gamma
				Scaler_SetLight_Window_Enable(_ENABLE);
			}
			break;

		case PQ_DEMO_HDR_DYNAMIC:
			break;

		case PQ_DEMO_HDR_ON_OFF:
			if(!onoff)
				Scaler_SetYUV2RGBDemo(5);
			drvif_color_set_LC_Enable(onoff);
			break;

		case PQ_DEMO_GAMUT_CTRL:
			if(onoff)
			{
				Scaler_SetYUV2RGBDemo(2);		// yuv2rgb demo mode 2
				Scaler_SetLight_Window_Enable(_ENABLE);	// enable high light window
			}
			break;

		case PQ_DEMO_COLOR_REDUCTION:
			if(onoff)
			{
				Scaler_SetYUV2RGBDemo(1);		// yuv2rgb demo mode 1 (saturation)
				Scaler_SetLight_Window_Enable(_ENABLE);	// enable high light window
			}
			break;

		case PQ_DEMO_LUMA_CTRL:
			if(onoff)
			{
				Scaler_SetRGBGainDemo(_ENABLE);
				Scaler_SetRGBBrightnessDemo(_ENABLE);		// set dcc overlay
				Scaler_SetLight_Window_Enable(_ENABLE);	// enable high light window
			}
			break;

		case PQ_DEMO_SDR2HDR:
			if(onoff)
			{
				Scaler_SetLocalContrastDemo(_ENABLE);
				Scaler_SetYUV2RGBDemo(3);		// yuv2rgb demo mode 3 (limit range)
				drvif_color_set_LC_Enable(_ENABLE);
				Scaler_SetLight_Window_Enable(_ENABLE);
			}
			break;

        //============================== 
        case PQ_SDR_ALGORITHM:
                    Scaler_SetYUV2RGBDemo(1);              // yuv2rgb demo mode
                   drvif_color_set_LC_Enable(1);
                    break;
         case PQ_HDR_ALGORITHM:
                    drvif_color_set_icm_Enable(1);
                    drvif_color_set_LC_Enable(1);
                   break;
         case PQ_HDR_ALGORITHM_PASS:
                    drvif_color_set_icm_Enable(0);
                    drvif_color_set_LC_Enable(0);
                    break;
         //============================== 
	}
}

unsigned char Scaler_Get_ADV_API_LEVEL_TBL_Idx(VIP_SOURCE_TIMING VIP_SrcTiming, VIP_ADV_API_LEVEL API_Level)
{
	unsigned char ret_idx, idx;
	SLR_VIP_TABLE_CUSTOM_TV001 *p_Share_Memory_VIP_TABLE_Custom_Struct=NULL;
	extern SLR_VIP_TABLE_CUSTOM_TV001 m_customVipTable;
 	p_Share_Memory_VIP_TABLE_Custom_Struct = &m_customVipTable;

	if (p_Share_Memory_VIP_TABLE_Custom_Struct == NULL)
	{
		printf("~get p_Share_Memory_VIP_TABLE_Custom_Struct Error return, %s->%d, %s~\n",__FILE__, __LINE__,__FUNCTION__);
		return 0;
	}

	idx = p_Share_Memory_VIP_TABLE_Custom_Struct->VIP_QUALITY_Coef_TV001[(unsigned char)VIP_SrcTiming][VIP_QUALITY_FUNCTION_TV001_ADV_API];
	ret_idx = p_Share_Memory_VIP_TABLE_Custom_Struct->ADV_API.VIP_ADV_API_Level_TBL[idx][(unsigned char)API_Level];
	return ret_idx;
};
char g_sGamma_save = 0;
unsigned char g_BLE_save = 0;


char Scaler_get_sGamma(void)
{
	return g_sGamma_save;
}

void Scaler_set_sGamma(char level_index)
{
	unsigned char table_idx;
	VIP_ADV_API_LEVEL API_Level;
	VIP_SOURCE_TIMING VIP_SrcTiming;

	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display,&src_idx);
/*
	SLR_PICTURE_MODE_DATA *pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
	{
		printf("~get picData Error return, %s->%d, %s~\n",__FILE__, __LINE__,__FUNCTION__);
		return;
	}
	pData->adv_gamma= level_index;
*/
	g_sGamma_save = level_index;
	SLR_VIP_TABLE_CUSTOM_TV001 *p_Share_Memory_VIP_TABLE_Custom_Struct=NULL;
	extern SLR_VIP_TABLE_CUSTOM_TV001 m_customVipTable;
 	p_Share_Memory_VIP_TABLE_Custom_Struct = &m_customVipTable;

	if (p_Share_Memory_VIP_TABLE_Custom_Struct == NULL)
	{
		printf("~get p_Share_Memory_VIP_TABLE_Custom_Struct Error return, %s->%d, %s~\n",__FILE__, __LINE__,__FUNCTION__);
		return;
	}

	_RPC_system_setting_info *VIP_RPC_system_info_structure_table=NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if (VIP_RPC_system_info_structure_table == NULL)
	{
		printf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n",__FILE__, __LINE__,__FUNCTION__);
		return;
	}
	VIP_SrcTiming = (VIP_SOURCE_TIMING)VIP_RPC_system_info_structure_table->VIP_source;

	if(level_index<0)
	{
		level_index = level_index * (-1);
		p_Share_Memory_VIP_TABLE_Custom_Struct->ADV_API.ADV_API_CTRL.is_sGamma_Neg = 1;
	}
	else
		p_Share_Memory_VIP_TABLE_Custom_Struct->ADV_API.ADV_API_CTRL.is_sGamma_Neg = 0;

	if(level_index>=VIP_ADV_API_LEVEL_Max)
	{
		API_Level = ADV_API_LEVEL_OFF;
		printf("~level_index>=VIP_ADV_API_LEVEL_Max, level= %d , %s->%d, %s~\n", level_index, __FILE__, __LINE__,__FUNCTION__);
	}
	else
		API_Level = (VIP_ADV_API_LEVEL)level_index;
	table_idx = Scaler_Get_ADV_API_LEVEL_TBL_Idx(VIP_SrcTiming, API_Level);
	p_Share_Memory_VIP_TABLE_Custom_Struct->ADV_API.ADV_API_CTRL.TBL_Select_sGamma = table_idx;
	fwif_color_set_DCC_SC_for_Coef_Change(1,1);

};

unsigned char Scaler_get_BLE(void)
{
	return g_BLE_save;
}

void Scaler_set_BLE(unsigned char level_index)
{
	unsigned char table_idx;
	VIP_ADV_API_LEVEL API_Level;
	VIP_SOURCE_TIMING VIP_SrcTiming;

	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display,&src_idx);

/*
	SLR_PICTURE_MODE_DATA *pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
	{
		printf("~get picData Error return, %s->%d, %s~\n",__FILE__, __LINE__,__FUNCTION__);
		return;
	}
	pData->adv_blackCorrecter= level_index;
*/
	g_BLE_save = level_index;

	SLR_VIP_TABLE_CUSTOM_TV001 *p_Share_Memory_VIP_TABLE_Custom_Struct=NULL;
	extern SLR_VIP_TABLE_CUSTOM_TV001 m_customVipTable;
 	p_Share_Memory_VIP_TABLE_Custom_Struct = &m_customVipTable;

	if (p_Share_Memory_VIP_TABLE_Custom_Struct == NULL)
	{
		printf("~get p_Share_Memory_VIP_TABLE_Custom_Struct Error return, %s->%d, %s~\n",__FILE__, __LINE__,__FUNCTION__);
		return;
	}

	_RPC_system_setting_info *VIP_RPC_system_info_structure_table=NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if (VIP_RPC_system_info_structure_table == NULL)
	{
		printf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n",__FILE__, __LINE__,__FUNCTION__);
		return;
	}
	VIP_SrcTiming = (VIP_SOURCE_TIMING)VIP_RPC_system_info_structure_table->VIP_source;

	if(level_index>=VIP_ADV_API_LEVEL_Max)
	{
		API_Level = ADV_API_LEVEL_OFF;
		printf("~level_index>=VIP_ADV_API_LEVEL_Max, level= %d , %s->%d, %s~\n", level_index, __FILE__, __LINE__,__FUNCTION__);

	}
	else
		API_Level = (VIP_ADV_API_LEVEL)level_index;

	table_idx = Scaler_Get_ADV_API_LEVEL_TBL_Idx(VIP_SrcTiming, API_Level);
	p_Share_Memory_VIP_TABLE_Custom_Struct->ADV_API.ADV_API_CTRL.TBL_Select_BLE = table_idx;
	fwif_color_set_DCC_SC_for_Coef_Change(1,1);

};


unsigned short In_OETF[257];
unsigned short Out_T[1025];

void Scaler_SetBrightness_LUT_OETF(unsigned short *Out_T , BRIGHTNESS_LUT_OETF *pData)
{
	unsigned short Table_length;
		Table_length = pData->un16_length;
	
		unsigned short i,j,bit_diff;
		#if 0//for debug
				UINT16 m;
				printk("1yuan=============\n");
				for (m = 0; m < 256; m++)
					printk("pf_LUT[%d] = %d\n", m, pData->pf_LUT[m]);
		#endif
	
		for(i=0;i<256;i++){
			In_OETF[i] = pData->pf_LUT[i]<<6;
		}
		In_OETF[256] = pData->pf_LUT[255]<<6;
		
		#if 0//for debug
				UINT16 n;
					printk("2yuan=============\n");
				for (n = 0; n < 257; n++)
					printk("In_OETF[%d] = %d\n", n, In_OETF[n]);
		#endif
	
			
		if(Table_length ==256){
			
			for(i=0;i<256;i++){
				
				bit_diff = ((In_OETF[(i+1)]-In_OETF[i])>>2);
				
				for(j = 0 ; j < 4 ; j++){
						Out_T[4*i+j]= In_OETF[i]+bit_diff*j;
					}
			}
		}
		else{
			return; 
		}
				Out_T[1024] = 0xffff;
				
			#if 0//for debug
				UINT16 k;
					printk("3yuan=============\n");
				for (k = 0; k < 1025; k++)
					printk("Out_T[%d] = %d\n", k, Out_T[k]);
			#endif
	
}

void Scaler_SetOETF2Gamma(BRIGHTNESS_LUT_OETF *pData)
{
	unsigned short Table_length;
	Table_length = pData->un16_length;	
	unsigned short i,j,bit_diff;
	extern unsigned short OEFT2Gamma[1025];
	static unsigned short intbl[257];
	             #if 0//for debug
			UINT16 m;
			printk("1yuan====Scaler_SetOETF2Gamma=========\n");
			for (m = 0; m < 256; m++)
				printk("pf_LUT[%d] = %d\n", m, pData->pf_LUT[m]);
	              #endif	

	for(i=0;i<256;i++){
		intbl[i]=(pData->pf_LUT[i])<<2;
	}
	intbl[256]=4095;	
	for(i=0;i<256;i++){
		bit_diff = ((intbl[(i+1)]-intbl[i])>>2);
			for(j = 0 ; j < 4 ; j++)
					OEFT2Gamma[4*i+j]= intbl[i]+bit_diff*j;
	}
	
			#if 0//for debug
			UINT16 k;
			printk("yuan=============\n");
			for (k = 0; k < 1025; k++)
			printk("OEFT2Gamma[%d] = %d\n", k, OEFT2Gamma[k]);
			#endif

}

int osd[6][3];
void Scaler_Set_ColorSpace_D_3dlutTBL(RTK_VPQ_COLORSPACE_INDEX *ColoSpace_T)
{
	short OSD_weight[6][3]={
		{128,128,128},//R
		{512,256,256},//G
		{512,256,256},//B
		{1024,1024,1024},//Y
		{1024,1024,1024},//C
		{256,256,256},//M
	};
	#if 1 //for debug
	printk("yuan2,R:R=%d,G=%d,B=%d\n",ColoSpace_T->CS_CUSTOM_RED.red,ColoSpace_T->CS_CUSTOM_RED.green,ColoSpace_T->CS_CUSTOM_RED.blue);
	printk("yuan2,G:R=%d,G=%d,B=%d\n",ColoSpace_T->CS_CUSTOM_GREEN.red,ColoSpace_T->CS_CUSTOM_GREEN.green,ColoSpace_T->CS_CUSTOM_GREEN.blue);
	printk("yuan2,B:R=%d,G=%d,B=%d\n",ColoSpace_T->CS_CUSTOM_BLUE.red,ColoSpace_T->CS_CUSTOM_BLUE.green,ColoSpace_T->CS_CUSTOM_BLUE.blue);
	printk("yuan2,Y:R=%d,G=%d,B=%d\n",ColoSpace_T->CS_CUSTOM_YELLOW.red,ColoSpace_T->CS_CUSTOM_YELLOW.green,ColoSpace_T->CS_CUSTOM_YELLOW.blue);
	printk("yuan2,C:R=%d,G=%d,B=%d\n",ColoSpace_T->CS_CUSTOM_CYAN.red,ColoSpace_T->CS_CUSTOM_CYAN.green,ColoSpace_T->CS_CUSTOM_CYAN.blue);
	printk("yuan2,M:R=%d,G=%d,B=%d\n",ColoSpace_T->CS_CUSTOM_MAGENTA.red,ColoSpace_T->CS_CUSTOM_MAGENTA.green,ColoSpace_T->CS_CUSTOM_MAGENTA.blue);
	#endif
	
	
	
	//----R
	osd[0][0]= OSD_weight[0][0]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_RED.red);
	osd[0][1]= OSD_weight[0][1]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_RED.green);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_RED.green);
	osd[0][2]= OSD_weight[0][2]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_RED.blue);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_RED.blue);

	//----G
	osd[1][0]= OSD_weight[1][0]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_GREEN.red);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_GREEN.red);
	osd[1][1]= OSD_weight[1][1]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_GREEN.green);
	osd[1][2]= OSD_weight[1][2]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_GREEN.blue);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_GREEN.blue);

	//----B
	osd[2][0]= OSD_weight[2][0]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_BLUE.red);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_BLUE.red);
	osd[2][1]= OSD_weight[2][1]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_BLUE.green);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_BLUE.green);
	osd[2][2]= OSD_weight[2][0]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_BLUE.blue);

	//----Y
	osd[3][0]= OSD_weight[3][0]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_YELLOW.red);
	osd[3][1]= OSD_weight[3][1]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_YELLOW.green);
	osd[3][2]= OSD_weight[3][2]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_YELLOW.blue);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_YELLOW.blue);

	//----C
	osd[4][0]= OSD_weight[4][0]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_CYAN.red);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_CYAN.red);
	osd[4][1]= OSD_weight[4][1]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_CYAN.green);
	osd[4][2]= OSD_weight[4][2]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_CYAN.blue);

	//----M
	osd[5][0]= OSD_weight[5][0]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_MAGENTA.red);
	osd[5][1]= OSD_weight[5][1]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_MAGENTA.green);//fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_MAGENTA.green);
	osd[5][2]= OSD_weight[5][2]*fwif_OSDMapToLUTValue(ColoSpace_T->CS_CUSTOM_MAGENTA.blue);

	#if 1 //for debug
	printk("osd,R:R=%d,G=%d,B=%d\n",osd[0][0],osd[0][1],osd[0][2]);
	printk("osd,G:R=%d,G=%d,B=%d\n",osd[1][0],osd[1][1],osd[1][2]);
	printk("osd,B:R=%d,G=%d,B=%d\n",osd[2][0],osd[2][1],osd[2][2]);
	printk("osd,Y:R=%d,G=%d,B=%d\n",osd[3][0],osd[3][1],osd[3][2]);
	printk("osd,C:R=%d,G=%d,B=%d\n",osd[4][0],osd[4][1],osd[4][2]);
	printk("osd,M:R=%d,G=%d,B=%d\n",osd[5][0],osd[5][1],osd[5][2]);
	#endif	
	
	fwif_color_cal_D_3DLUT_Tbl(VIP_8VERTEX_R);
	fwif_color_cal_D_3DLUT_Tbl(VIP_8VERTEX_G);
	fwif_color_cal_D_3DLUT_Tbl(VIP_8VERTEX_B);

}

char fwif_OSDMapToLUTValue(unsigned char value)
{
	char temp = 0;

	temp=value-50;

	return (char)temp;
}

void fwif_color_cal_D_3DLUT_Tbl(UINT8 axis)
{
	extern unsigned char D_3DLUT_R[VIP_D_3DLUT_999_SIZE];
	extern unsigned char D_3DLUT_G[VIP_D_3DLUT_999_SIZE];
	extern unsigned char D_3DLUT_B[VIP_D_3DLUT_999_SIZE];
	extern unsigned char D_3DLUT_Y[VIP_D_3DLUT_999_SIZE];
	extern unsigned char D_3DLUT_C[VIP_D_3DLUT_999_SIZE];
	extern unsigned char D_3DLUT_M[VIP_D_3DLUT_999_SIZE];
	extern int D_3DLUT_999[VIP_D_3DLUT_999_SIZE][VIP_8VERTEX_RGB_MAX];
	extern int D_3DLUT_999_Reseult[VIP_D_3DLUT_999_SIZE][VIP_8VERTEX_RGB_MAX];
	extern int osd[6][3];
	short i=0;

	//cal Red------------------------------	
	for(i=0;i<VIP_D_3DLUT_999_SIZE;i++){
		D_3DLUT_999_Reseult[i][axis]=(D_3DLUT_R[i]*osd[0][axis])/9+D_3DLUT_999[i][axis];
	
	//prtection-------------------------
	if((D_3DLUT_999_Reseult[i][axis]) <0)
			D_3DLUT_999_Reseult[i][axis]=0;
	
	if((D_3DLUT_999_Reseult[i][axis]) > 65535)
			D_3DLUT_999_Reseult[i][axis]=65535;
	}
	
	//cal Green------------------------------	
	for(i=0;i<VIP_D_3DLUT_999_SIZE;i++){
		D_3DLUT_999_Reseult[i][axis]=(D_3DLUT_G[i]*osd[1][axis])/9+D_3DLUT_999_Reseult[i][axis];
	
	//prtection-------------------------
	if((D_3DLUT_999_Reseult[i][axis]) <0)
			D_3DLUT_999_Reseult[i][axis]=0;
	
	if((D_3DLUT_999_Reseult[i][axis]) > 65535)
			D_3DLUT_999_Reseult[i][axis]=65535;
	}
	
	//cal Blue------------------------------	
	for(i=0;i<VIP_D_3DLUT_999_SIZE;i++){
		D_3DLUT_999_Reseult[i][axis]=(D_3DLUT_B[i]*osd[2][axis])/9+D_3DLUT_999_Reseult[i][axis];
	
	//prtection-------------------------
	if((D_3DLUT_999_Reseult[i][axis]) <0)
			D_3DLUT_999_Reseult[i][axis]=0;
	
	if((D_3DLUT_999_Reseult[i][axis]) > 65535)
			D_3DLUT_999_Reseult[i][axis]=65535;
	}
	//cal Yellow------------------------------	
	for(i=0;i<VIP_D_3DLUT_999_SIZE;i++){
		D_3DLUT_999_Reseult[i][axis]=(D_3DLUT_Y[i]*osd[3][axis])/9+D_3DLUT_999_Reseult[i][axis];
	
	//prtection-------------------------
	if((D_3DLUT_999_Reseult[i][axis]) <0)
			D_3DLUT_999_Reseult[i][axis]=0;
	
	if((D_3DLUT_999_Reseult[i][axis]) > 65535)
			D_3DLUT_999_Reseult[i][axis]=65535;
	}
	
	//cal C------------------------------	
	for(i=0;i<VIP_D_3DLUT_999_SIZE;i++){
		D_3DLUT_999_Reseult[i][axis]=(D_3DLUT_C[i]*osd[4][axis])/9+D_3DLUT_999_Reseult[i][axis];
	
	//prtection-------------------------
	if((D_3DLUT_999_Reseult[i][axis]) <0)
			D_3DLUT_999_Reseult[i][axis]=0;
	
	if((D_3DLUT_999_Reseult[i][axis]) > 65535)
			D_3DLUT_999_Reseult[i][axis]=65535;
	}

	//cal M------------------------------	
	for(i=0;i<VIP_D_3DLUT_999_SIZE;i++){
		D_3DLUT_999_Reseult[i][axis]=(D_3DLUT_M[i]*osd[5][axis])/9+D_3DLUT_999_Reseult[i][axis];
	
	//prtection-------------------------
	if((D_3DLUT_999_Reseult[i][axis]) <0)
			D_3DLUT_999_Reseult[i][axis]=0;
	
	if((D_3DLUT_999_Reseult[i][axis]) > 65535)
			D_3DLUT_999_Reseult[i][axis]=65535;
	}

	fwif_color_cpy_D_3DLUT_TBL();
	

}


void Scaler_Set_ColorSpace_InvGamma_sRGB(unsigned char onoff)
{
	printk("yuan,inv/sRGB=%d\n",onoff);
	if(onoff==1){
		IoReg_SetBits(0xb802c018, _BIT6);/* set Inv Gamma*/
		IoReg_SetBits(0xb802c000,_BIT0);//Enable sRGB		
		}
	else{
		IoReg_ClearBits(0xb802c018,_BIT6);//disable inv Gamma
		IoReg_ClearBits(0xb802c000,_BIT0);//disable sRGB
}

}

RTK_VPQ_MODE_TYPE_TV030 picturemode=PQ_MODE_NORMAL;

void Scaler_Set_PictureMode_PQsetting(RTK_VPQ_MODE_TYPE_TV030 mode)
{
	extern unsigned char str_resume_do_picturemode;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	
	VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	
	printk("yuan,PictureMode=%d\n",mode);
	
	switch(mode){
	case PQ_MODE_BYPASS:
	default:
		Scaler_set_ICM_table(9,0);
		drvif_color_Icm_Enable(OFF);
		break;
		
	case PQ_MODE_NORMAL:
		Scaler_set_ICM_table(0,0);
		break;
		
	case PQ_MODE_xvycc:
	case PQ_MODE_DOLBY:	
	case PQ_MODE_DCIP3:
	case PQ_MODE_HDR_ENHANCE_WIDE:
		Scaler_set_ICM_table(9,0);
		printk("PictureMode_PQsetting :NOT SUPPORT!!\n");
		break;
		
	case PQ_MODE_HDR:
		Scaler_set_ICM_table(1,0);
		break;

	case PQ_MODE_SDR2HDR:
		Scaler_set_ICM_table(2,0);
		break;

	case PQ_MODE_FOOTBALL:
		Scaler_set_ICM_table(3,0);
		break;	

	case PQ_MODE_FILM:
		Scaler_set_ICM_table(4,0);
		break;	

	case PQ_MODE_SHOP_DEMO: //SHOP MODE
		printk("tim_li,HOME -> SHOP dcc !!! \n");
		if(VIP_system_info_structure_table->HDR_flag)
			break;
		Scaler_set_ICM_table(5,0);
		Scaler_SetDCC_Table(5);
		Scaler_SetDCC_Mode(2);
		Scaler_Set_DCC_Color_Independent_Table(4);
		break;
	}
	if((picturemode !=mode) && (picturemode==PQ_MODE_SHOP_DEMO)){
		printk("tim_li,SHOP -> HOME !!! \n");
		Scaler_SetDCC_Table(Scaler_get_dcc_table_by_source(0));
		Scaler_SetDCC_Mode(Scaler_GetDCC_Mode());
		Scaler_Set_DCC_Color_Independent_Table(Scaler_get_dcc_table_by_source(1));
	}
	picturemode=mode;
	
	if(str_resume_do_picturemode)
		str_resume_do_picturemode=0;
}


