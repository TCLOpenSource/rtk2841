/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2017/03/16 14:30 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

/**
 * @addtogroup vdc
 * @{
 */

/*================ Module dependency  =============== */
#define kernel_space_dumpdma

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/delay.h>
#ifdef kernel_space_dumpdma
#include <linux/fs.h>
#include <linux/kmod.h>
#include <linux/pageremap.h>
#endif

//#include <rbus/rbusVDTopReg.h>
#include <rbus/vdtop_reg.h>//sunray
//#include <rbus/rbusVDPQReg.h>
#include <rbus/vdpq_reg.h>//sunray
#include <rbus/adc_reg.h>
//#include <rbus/rbusVDIFDinReg.h>
#include <rbus/vd_ifd_input_reg.h>//sunray
#include <uapi/linux/const.h>
#include <linux/mm.h>

#include <tvscalercontrol/vdc/video.h>
#include "tvscalercontrol/frontend/ifd_new.h"
#include <tvscalercontrol/vdc/video_table.h>
#include <tvscalercontrol/vdc/video_input.h>
#include <tvscalercontrol/vdc/video_factory.h>
#include <tvscalercontrol/vdc/yc_separation_vpq.h>
#include <tvscalercontrol/vdc/yc_separation_vpq_table.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scaleradc.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scaler/modeState.h>
#include <tvscalercontrol/scaler/scalertimer.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>

#define _SUCCESS		1
#define _FAIL			0
#define _ENABLE 			1
#define _DISABLE			0
#define _TRUE			1
#define _FALSE			0

char *VD_dma_name_table[] = {
	"VD_M0",
	"VD_M1",
	"VD_M2",
	"VD_M3",
	"VD_M4",
	"VD_M5",
	"VD_M6",
	"VD_M7",
	"VD_M8",
	"VD_M9",
	"VD_MA",
	"VD_MB",
	"IFD",	/* 12 */
	"VBI",	/* 13 */
	"TT",	/* 14 */
};


/*==================== Definitions ================ */
#define Rt_Delay(mSec)	msleep(mSec)
#define rtdf_outl(offset, val)		IoReg_Write32(offset,val)
#define rtdf_inl(offset)			IoReg_Read32(offset)
//#define rtdf_setBits(offset, Mask) 			rtdf_outl(offset, (rtdf_inl(offset) |Mask))
#define rtdf_clearBits(offset, Mask) 		rtdf_outl(offset, ((rtdf_inl(offset) & ~(Mask))))

/*==================== Variables ================== */
unsigned char vdc_factory_testdma_size = 0x03;
unsigned char vdc_factory_debugprint = OFF;
static unsigned char ucVdc_DMA_Count = 0x00;
static unsigned char vdc_debugprint_count = 0x00;
static unsigned char debug_count_num = 0x10;

/*============= Local Functions' Phototype ============== */
#if 0
unsigned char drvif_module_vdc_Debug_Print_Get_Value(void)
{
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] print %x\n", vdc_factory_debugprint);
	return vdc_factory_debugprint;
}
#endif
void drvif_module_vdc_Debug_Print_Set(unsigned char On_Off)
{
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] print set %x\n", On_Off);
	vdc_factory_debugprint = On_Off;
}

void drvif_module_vdc_Debug_Print(unsigned char ucInputSrc)
{
	if (vdc_factory_debugprint == _DISABLE)
		return;

	if (ucInputSrc != _SRC_TV) {
		if (drvif_video_status_reg(VDC_no_signal))
			debug_count_num = 0x10;
		else
			debug_count_num = 0x03;
	} else {
		debug_count_num = 0x10;
	}

	vdc_debugprint_count++;
	if (vdc_debugprint_count != debug_count_num)
		return;
	vdc_debugprint_count = 0x00;

	VDC_DEBUG_MSG(VDC_MSG_FACT,"===== VD log [%x]================\n", debug_count_num);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VD locked  ][9008] %x\n", drvif_video_status_reg(VDC_STATUS_REG1));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VD status1 ][900c] %x\n", drvif_video_status_reg(VDC_STATUS_REG2));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VD status2 ][9010] %x\n", drvif_video_status_reg(VDC_STATUS_REG3));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VD set mode][94a0] %x\n", vdcf_inl(VDTOP_MANUAL_MODE_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VD mode   ][94a4] %x\n", vdcf_inl(VDTOP_MODE_DETECTION_STATUS_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[Noise status][903c] %x\n", drvif_module_vdc_NoiseStatus());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[Burst mag  ][901c] %x\n", drvif_module_vdc_burst_mag_status());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[Dgain         ][9020] %x\n", drvif_module_vdc_Dgain_Factory_Mode_Get_info());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[Cgain         ][9028] %x\n", drvif_module_vdc_Cgain_Factory_Mode_Get_info());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[blank level  ][968c] %x\n", drvif_module_vdc_read_blevel());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[sync level   ][9690] %x\n", drvif_module_vdc_read_slevel());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[C mag        ][9024] %x\n", vdcf_inl(VDTOP_CMAG_STATUS_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[H state read][9164] %x\n", vdcf_inl(VDTOP_HDETECT_LOOPFILTER_SW_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[H state set  ][9134] %x\n", vdcf_inl(VDTOP_H_LOOP_MAXSTATE_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[C state read][9218] %x\n", vdcf_inl(VDTOP_CSTATE_STATUS_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[C state set  ][9410] %x\n", vdcf_inl(VDTOP_CHROMA_LOOPFILTER_STATE_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[HDTO         ][9014] %x\n", drvif_module_vdc_Hdto_Factory_Mode_Get_info());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[CDTO         ][9018] %x\n", drvif_module_vdc_Cdto_Factory_Mode_Get_info());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[V line  1      ][9030] %x\n", drvif_module_vdc_V_1st_line_Factory_Mode_Get_info());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[V line  2      ][9034] %x\n", drvif_module_vdc_V_2nd_line_Factory_Mode_Get_info());
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[FIFO status ][975c] %x\n", vdcf_inl(VDTOP_FIFO_STATUS_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[KILL_FIELD  ][90f0] %x\n", vdcf_inl(VDTOP_KILL_FIELD_reg));
	if (ucInputSrc == _SRC_TV) {
		VDC_DEBUG_MSG(VDC_MSG_FACT,"===== IFD log ================\n");
		/*
				NTSC		PAL			SECAM_L		SECAM_L'
		2080	0x113001	0x116003	0x116003	0x116003
		2114	0xf0			0xf0			0xf1			0xf1
		2040	0x010		0x010		0x010		0x011
		*/
//		VDC_DEBUG_MSG(VDC_MSG_FACT,"IFD_DECIMATION_FILTER_ENABLE_reg[2080]=%x%x\n",rtdf_inl(IFD_DECIMATION_FILTER_ENABLE_reg));
//		VDC_DEBUG_MSG(VDC_MSG_FACT,"IFD_AGC_MAX_COUNT_FOR_COARSE_MODE_AGC_LOCK2_reg[2114]=%x\n",rtdf_inl(IFD_AGC_MAX_COUNT_FOR_COARSE_MODE_AGC_LOCK2_reg));
//		VDC_DEBUG_MSG(VDC_MSG_FACT,"IFD_SHAPE_FILTER_SELECTION_reg[2040]=%x\n",rtdf_inl(IFD_SHAPE_FILTER_SELECTION_reg));
	}
}

unsigned char drvif_module_vdc_TV_DCTIeh_Factory_Mode_Get_Value(void)
{
	return vdc_TV_dctieh_table_value;
}

void drvif_module_vdc_FPGAtest_Factory_Mode_set(unsigned char on_off)
{
	vdtop_fpga_test_reg1_RBUS FPGA_TEST_REG1_reg;
	FPGA_TEST_REG1_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG1_reg);
	FPGA_TEST_REG1_reg.factory_flag = on_off;
	vdcf_outl(VDTOP_FPGA_TEST_REG1_reg, FPGA_TEST_REG1_reg.regValue);
}

unsigned char drvif_module_vdc_FPGAtest_Factory_Mode_read(void)
{
	vdtop_fpga_test_reg1_RBUS FPGA_TEST_REG1_reg;
	FPGA_TEST_REG1_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG1_reg);
	return FPGA_TEST_REG1_reg.factory_flag;
}

unsigned char drvif_module_vdc_TV_DCTIeh_Factory_Mode_Get_info(void)
{
	vdpq_dcti_filter_en_RBUS dcti_filter_en_reg;
	dcti_filter_en_reg.regValue = vdcf_inl(VDPQ_DCTI_FILTER_EN_reg);
	return dcti_filter_en_reg.dcti_filter_en;
}

void drvif_module_vdc_TV_DCTIeh_Factory_Mode(unsigned char mode)
{
	if (mode)
		drvif_module_vpq_TV_DCTIeh_Enable(DCTIeh_ENABLE);
	else
		drvif_module_vpq_TV_DCTIeh_Enable(DCTIeh_DISABLE);
}

unsigned char drvif_module_vdc_AVG_BURST_MAG_STATUS(void)
{
	return drvif_module_vdc_burst_mag_status();
}

unsigned char drvif_module_vdc_Auto_Burst_position_Factory_Mode_Get_info(void)
{
	/* 9458[1] */
	vdtop_separate_443_358_new_function_1_RBUS separate_443_358_new_function_1_reg;
	separate_443_358_new_function_1_reg.regValue = vdcf_inl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_reg);
	return separate_443_358_new_function_1_reg.auto_burst_location_en;
}

void drvif_module_vdc_Auto_Burst_position_enable_Factory_Mode_Set(void)
{
	module_vdc_set_Burst_position(drvif_module_vdc_ReadMode(VDC_DETECT));
}

void drvif_module_vdc_YcSeparation_Factory_Mode(unsigned char set_mode)
{
	unsigned char ucMode = ((drvif_module_vpq_GetYcSep()&0xf0)>>4);
	drvif_module_vdc_SetFactoryModEnable(ON);
	switch (set_mode) {
	default:
	case VDC_YCSEPARATE_1D:
		drvif_module_vpq_1DSet(INPUT_SRC_AV, ucMode );
		vdcf_outl(VDPQ_YC_SEP_MODE_CTRL_reg, 0x00);
		break;
	case  VDC_YCSEPARATE_2D:
		drvif_module_vpq_2DSet(INPUT_SRC_AV, ucMode );
		break;
	case  VDC_YCSEPARATE_3D:
#ifdef CONFIG_ENABLE_3D_SETTING
		drvif_module_vpq_3DSet(INPUT_SRC_AV, ucMode );
#else
		drvif_module_vpq_2DSet(INPUT_SRC_AV, ucMode );
#endif
		break;
	case  VDC_YCSEPARATE_3DFix:
#ifdef CONFIG_ENABLE_3D_SETTING
		drvif_module_vpq_3DSet(INPUT_SRC_AV, ucMode );
		vdcf_outl(VDPQ_YC_SEP_MODE_CTRL_reg, 0x00000002);
		drvif_module_vpq_SetYcSep( (ucMode<<4) | VDC_YCSEPARATE_3DFix);
#else
		drvif_module_vpq_2DSet(INPUT_SRC_AV, ucMode );
#endif
		break;
	}
}

unsigned char drvif_module_vdc_YcSeparation_Factory_Mode_Get_info(void)
{
	unsigned char value;

	value = (((unsigned char)vdcf_inl(VDPQ_YC_SEP_MODE_CTRL_reg)) & 0x03);
	if (value == 0x02)
		return VDC_YCSEPARATE_3DFix;
	if (value == 0x01)
		return VDC_YCSEPARATE_3D;
	if (value == 0x00) {
		value = (((unsigned char)vdcf_inl(VDPQ_YC_SEP_CONTROL_reg)) & 0x03);
		if (value == 0x03)
			return VDC_YCSEPARATE_1D;
		else
			return VDC_YCSEPARATE_2D;
	}
	return VDC_YCSEPARATE_DEFAULT;
}


void scaler_3d_talbe_Factory_Mode(unsigned char value)
{
	drvif_module_vdc_SetFactoryModEnable(ON);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]enter scaler_3d_talbe_Factory_Mode value==%d\n", value);
}


/**
   Set 3D table index

   @param	{ 3D table index }
   @return	{ void }
    add by hsliao 20090330
*/
void drvif_module_vdc_Set3DTableIndex(unsigned char index)
{
	scaler_3d_talbe_Factory_Mode(index);
	return;
}

/**
   Get 3D table index

   @param	{ void }
   @return	{ 3D table index }
    add by hsliao 20090330
*/
unsigned char drvif_module_vdc_Get3DTableIndex(void)
{
#ifdef CONFIG_ENABLE_Adaptive3DThreshold
	return 0;
#else
	return 0;
#endif
}

unsigned char drvif_module_vdc_Fix_Hstate_Factory_Mode_Get_info(void)
{
	return (VDC_VIDEO_FIXHSTATE_MODE)drvif_module_vdc_Read_Hstate_set();
}

void drvif_module_vdc_Fix_Cstate_Factory_Mode(unsigned char value)
{

	switch (value) {
	case 0:
		drvif_module_vdc_Set_Cstate(VDC_FIX_CSTATE0);
		break;
	case 1:
		drvif_module_vdc_Set_Cstate(VDC_FIX_CSTATE1);
		break;
	case 2:
		drvif_module_vdc_Set_Cstate(VDC_FIX_CSTATE2);
		break;
	case 3:
		drvif_module_vdc_Set_Cstate(VDC_FIX_CSTATE3);
		break;
	case 4:
		drvif_module_vdc_Set_Cstate(VDC_FIX_CSTATE4);
		break;
	case 5:
		drvif_module_vdc_Set_Cstate(VDC_FIX_CSTATE5);
		break;
	default:
		drvif_module_vdc_Set_Cstate(VDC_CSTATE_RESET);
		break;

	}
}

void drvif_module_vdc_Fix_Vstate_Factory_Mode(unsigned char value)
{
	switch (value) {
	case 0:
		drvif_module_vdc_Set_Vstate(VDC_FIX_VSTATE0);
		break;
	case 1:
		drvif_module_vdc_Set_Vstate(VDC_FIX_VSTATE1);
		break;
	case 2:
		drvif_module_vdc_Set_Vstate(VDC_FIX_VSTATE2);
		break;
	case 3:
		drvif_module_vdc_Set_Vstate(VDC_FIX_VSTATE3);
		break;
	default:
		drvif_module_vdc_Set_Vstate(VDC_VSTATE_RESET);
		break;
	}
}

unsigned char drvif_module_vdc_Fix_Vstate_Factory_Mode_Get_info(void)
{
	vdtop_vstate_ctrl3_RBUS vstate_ctrl3_reg;
	vstate_ctrl3_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL3_reg);
	if (vstate_ctrl3_reg.vstate_sw_en)
		return 4;
	else
		return vstate_ctrl3_reg.vstate_sw;
}

void drvif_module_vdc_user_ckill_mode_Factory_Mode(unsigned char mode)
{
	drvif_module_vdc_SetFactoryModEnable(ON);
	switch (mode) {
	default:
	case 0:	/* auto */
		drvif_module_vdc_Set_CKill_Mode(CKill_AUTO);
		break;
	case 1:	/* on */
		drvif_module_vdc_Set_CKill_Mode(CKill_ON);
		break;
	case 2:	/* off */
		drvif_module_vdc_Set_CKill_Mode(CKill_OFF);
		break;
	}
}

unsigned char drvif_module_vdc_user_ckill_mode_Factory_Mode_Get_info(void)
{
	drvif_module_vdc_SetFactoryModEnable(ON);
	if (drvif_module_vdc_Get_CKill_Mode() == CKill_OFF)
		return 0x02;	/*auto */
	if (drvif_module_vdc_Get_CKill_Mode() == CKill_ON)
		return 0x01;	/* on */
	return 0x00;	/* off */
}

unsigned short drvif_module_vdc_Dgain_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_read_Dgain();
}

unsigned short drvif_module_vdc_Cgain_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_read_Cgain();
}

unsigned int drvif_module_vdc_Hdto_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_Hdto_status();
}

unsigned int drvif_module_vdc_Cdto_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_Cdto_status();
}

void drvif_module_vdc_Fix_Dgain_Factory_Mode(unsigned char on_off)
{
	if (on_off == 1) {
		drvif_module_vdc_set_Control2_Register(VDC_fix_dgain_enable);
	} else {
		drvif_module_vdc_set_Control2_Register(VDC_fix_dgain_disable);
	}
}

void drvif_module_vdc_Fix_Cagc_Factory_Mode(unsigned char on_off)
{
	if (on_off == 1) {
		drvif_module_vdc_set_Control2_Register(VDC_cagc_disable);
		drvif_module_vdc_set_Basic_Register(VDC_ped_reg_enable);
	} else {
		drvif_module_vdc_set_Control2_Register(VDC_cagc_enable);
		drvif_module_vdc_set_Basic_Register(VDC_ped_reg_disable);
	}
}

#if 0
void drvif_module_vdc_XNREnable_Factory_Mode(unsigned char on_off)
{
}

unsigned char drvif_module_vdc_XNREnable_Factory_Mode_Get_info(void)
{
	return 0;
}
#endif

void drvif_module_vdc_XCCEnable_Factory_Mode(unsigned char on_off)
{
	drvif_module_vpq_set_DeXC_Enable(on_off);
}

unsigned char drvif_module_vdc_XCCEnable_Factory_Mode_Get_info(void)
{
	/* 9f00[4] */
	vdpq_de_xc_ctrl_RBUS de_xc_ctrl_reg;
	de_xc_ctrl_reg.regValue = vdcf_inl(VDPQ_DE_XC_CTRL_reg);
	return de_xc_ctrl_reg.de_xc_en;
}

void drvif_module_vdc_XCC_Threshold_Factory_Mode(unsigned char value)
{
	drvif_module_vpq_set_DeXC_Threshold(value);
}

unsigned char drvif_module_vdc_XCC_Threshold_Factory_Mode_Get_info(void)
{
	return drvif_module_vpq_Get_DeXC_Threshold();
}

void drvif_module_vdc_Dgain_Write_Factory_Mode(unsigned char value)
{
	drvif_module_vdc_Write_Dgain_value(value);
}

void drvif_module_vdc_Cagc_Write_Factory_Mode(unsigned char value)
{
	vdtop_chroma_agc_RBUS chroma_agc_reg;
	chroma_agc_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_reg);
	chroma_agc_reg.cagc = value;
	vdcf_outl(VDTOP_CHROMA_AGC_reg, chroma_agc_reg.regValue);
}

unsigned char drvif_module_vdc_Fix_Dgain_Factory_Mode_Get_info(void)
{
	vdtop_video_control2_RBUS video_control2_reg;
	video_control2_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL2_reg);
	return video_control2_reg.fix_dgain;
}

unsigned char drvif_module_vdc_Fix_Cagc_Factory_Mode_Get_info(void)
{
	vdtop_chroma_agc_RBUS chroma_agc_reg;
	chroma_agc_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_reg);
	return chroma_agc_reg.fix_cgain;
}

unsigned char drvif_module_vdc_Dgain_Write_Factory_Mode_Get_info(void)
{
	vdtop_luma_agc_value_RBUS luma_agc_value_reg;
	luma_agc_value_reg.regValue = vdcf_inl(VDTOP_LUMA_AGC_VALUE_reg);
	return luma_agc_value_reg.hagc;
}

unsigned char drvif_module_vdc_Cagc_Write_Factory_Mode_Get_info(void)
{
	vdtop_chroma_agc_RBUS chroma_agc_reg;
	chroma_agc_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_reg);
	return chroma_agc_reg.cagc;
}

unsigned char drvif_module_vdc_3D_Frame_Buffer_Error_Factory_Mode_Get_info(void)
{
#ifdef CONFIG_ENABLE_3D_SETTING
	return drvif_module_vpq_get_f_num_3d_fail_det_bit();
#else
	return 1;
#endif
}

void drvif_module_vdc_Set_DCTI_Setting_Factory_Mode(unsigned char level)
{
	drvif_module_vpq_DCTI_Set(level);
}

unsigned char drvif_module_vdc_Set_DCTI_Setting_Factory_Mode_Get_info(void)
{
	return drvif_module_vpq_get_dcti_table_index_Factory();
}

void drvif_module_vdc_2D_Chroma_Bw_lo_Factory_Mode(unsigned char value)
{
	vdpq_yc_bw_ctrl_RBUS yc_bw_ctrl_reg;
	yc_bw_ctrl_reg.regValue = vdcf_inl(VDPQ_YC_BW_CTRL_reg);
	yc_bw_ctrl_reg.chroma_bw_lo = value;
	vdcf_outl(VDPQ_YC_BW_CTRL_reg, yc_bw_ctrl_reg.regValue);
}

unsigned char drvif_module_vdc_2D_Chroma_Bw_lo_Factory_Mode_Get_info(void)
{
	vdpq_yc_bw_ctrl_RBUS yc_bw_ctrl_reg;
	yc_bw_ctrl_reg.regValue = vdcf_inl(VDPQ_YC_BW_CTRL_reg);
	return yc_bw_ctrl_reg.chroma_bw_lo;
}

unsigned char drvif_module_vdc_Read_Cstate_Factory_Mode_Get_info(void)
{
	vdtop_cstate_status_RBUS cstate_status_reg;
	cstate_status_reg.regValue = vdcf_inl(VDTOP_CSTATE_STATUS_reg);
	return cstate_status_reg.cstate_status;
}

unsigned char drvif_module_vdc_Read_Vstate_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_Read_Vstate();
}

unsigned char drvif_module_vdc_Read_Hstate_Factory_Mode_Get_info(void)
{
	vdtop_hdetect_loopfilter_sw_RBUS hdetect_loopfilter_sw_reg;
	hdetect_loopfilter_sw_reg.regValue = vdcf_inl(VDTOP_HDETECT_LOOPFILTER_SW_reg);
	return hdetect_loopfilter_sw_reg.hstate_status;
}

unsigned char drvif_module_vdc_Read_Contrast_Factory_Mode_Get_info(void)
{
	vdtop_luma_contrast_adj_RBUS luma_cntrast_adj_reg;
	luma_cntrast_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_CONTRAST_ADJ_reg);
	return luma_cntrast_adj_reg.contrast;
}

unsigned char drvif_module_vdc_Read_Brightness_Factory_Mode_Get_info(void)
{
	vdtop_luma_brightness_adj_RBUS luma_brightness_adj_reg;
	luma_brightness_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_BRIGHTNESS_ADJ_reg);
	return luma_brightness_adj_reg.brightness;
}

unsigned char drvif_module_vdc_Read_Saturation_Factory_Mode_Get_info(void)
{
	vdtop_chroma_saturation_adj_RBUS chroma_saturation_adj_reg;
	chroma_saturation_adj_reg.regValue = vdcf_inl(VDTOP_CHROMA_SATURATION_ADJ_reg);
	return chroma_saturation_adj_reg.saturation;
}

void drvif_module_vdc_Write_ClampMode_Factory_Mode(unsigned char value)
{
	switch (value) {
	default:
	case 0:
		drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_auto);
		break;
	case 1:
		drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_bk_porch);
		break;
	case 2:
		drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_synctip);
		break;
	case 3:
		drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_off);
		break;
	}
}

unsigned char drvif_module_vdc_Read_ClampMode_Factory_Mode_Get_info(void)
{
	vdtop_video_control2_RBUS video_control2_reg;
	video_control2_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL2_reg);
	return video_control2_reg.dc_clamp_mode;
}

unsigned char drvif_module_vdc_Read_Vcr_Flag_Factory_Mode_Get_info(void)
{
	return drvif_video_status_reg(VDC_vcr);
}

void drvif_module_vdc_Chroam_Level_Factory_Mode(unsigned char value)
{
	drvif_module_vdc_Set_CKill_Value(value);
}

unsigned char  drvif_module_vdc_Chroam_Level_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_Read_CKill_Value();
}

unsigned int drvif_module_vdc_V_1st_line_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_read_V_1st_line();
}

unsigned int drvif_module_vdc_V_2nd_line_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_read_V_2nd_line();
}
#if 0
void drvif_module_vdc_Chroma_Vertical_Lpf_enable(unsigned char on_off)
{
	vdpq_yc_bw_ctrl_RBUS yc_bw_ctrl_reg;
	yc_bw_ctrl_reg.regValue = vdcf_inl(VDPQ_YC_BW_CTRL_reg);
	yc_bw_ctrl_reg.chroma_vlpf_en = on_off;
	vdcf_outl(VDPQ_YC_BW_CTRL_reg, yc_bw_ctrl_reg.regValue);
}
#endif
unsigned char drvif_module_vdc_Chroma_Vertical_Lpf_enable_Get_info(void)
{
	vdpq_yc_bw_ctrl_RBUS yc_bw_ctrl_reg;
	yc_bw_ctrl_reg.regValue = vdcf_inl(VDPQ_YC_BW_CTRL_reg);
	return yc_bw_ctrl_reg.chroma_vlpf_en;
}

void drvif_module_vdc_Vsync_Cntl_Factory_Mode(unsigned char value)
{
	switch (value) {
	default:
	case 0:
		drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_org_vsync);
		break;
	case 1:
		drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_directly_vsync);
		break;
	case 2:
		drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_Vpll_vsync);
		break;
	case 3:
		drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_Vpll2_vsync);
		break;
	}
}

void drvif_module_vdc_Vsync_Clamp_mode_Factory_Mode(unsigned char value)
{
	switch (value) {
	default:
	case 0:
		module_vdc_Set_Vsync_clamp_mode(VDC_vsync_clamp_disable);
		break;
	case 1:
		module_vdc_Set_Vsync_clamp_mode(VDC_vsync_clamp_enable);
		break;
	case 2:
		module_vdc_Set_Vsync_clamp_mode(VDC_vsync_clamp_mode1);
		break;
	case 3:
		module_vdc_Set_Vsync_clamp_mode(VDC_vsync_clamp_mode2);
		break;
	}
}

unsigned char drvif_module_vdc_H_Lock_Factory_Mode_Get_info(void)
{
	return drvif_video_status_reg(VDC_hlock);
}

unsigned char drvif_module_vdc_V_Lock_Factory_Mode_Get_info(void)
{
	return drvif_video_status_reg(VDC_vlock);
}

unsigned char drvif_module_vdc_C_Lock_Factory_Mode_Get_info(void)
{
	return drvif_video_status_reg(VDC_chomalock);
}

unsigned char drvif_module_vdc_Nosignal_Factory_Mode_Get_info(void)
{
	return drvif_video_status_reg(VDC_no_signal);
}

unsigned char drvif_module_vdc_Vsync_Cntl_Factory_Mode_Get_info(void)
{
	return drvif_module_vdc_read_Vsync_Cntl_Mode();
}

unsigned char drvif_module_vdc_Vsync_Clamp_mode_Factory_Mode_Get_info(void)
{
	vdtop_vsync_agc_lockout_end_RBUS vsync_agc_lockout_end_reg;
	vsync_agc_lockout_end_reg.regValue = vdcf_inl(VDTOP_VSYNC_AGC_LOCKOUT_END_reg);
	return vsync_agc_lockout_end_reg.vsync_clamp_mode;
}

unsigned char drvif_module_vdc_clamp_rc_rate_enable_Factory_Mode_Get_info(void)
{
	/* 90d4[4], enable when co-ch 1/12 */
	vdtop_new_clampagc_ctrl_RBUS new_clampagc_ctrl_reg;
	new_clampagc_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_CLAMPAGC_CTRL_reg);
	return new_clampagc_ctrl_reg.new_clamp_rc_rate_en;
}

unsigned char drvif_module_vdc_clamp_rc_rate_value_Factory_Mode_Get_info(void)
{
	/* 90d4[3:0], enable when co-ch 1/12 */
	vdtop_new_clampagc_ctrl_RBUS new_clampagc_ctrl_reg;
	new_clampagc_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_CLAMPAGC_CTRL_reg);
	return new_clampagc_ctrl_reg.clampagc_rc_rate;
}

void drvif_module_vdc_clamp_rc_rate_value_Factory_Mode_Set(unsigned char ivalue)
{
	/* 90d4[3:0], enable when co-ch 1/12 */
	vdtop_new_clampagc_ctrl_RBUS new_clampagc_ctrl_reg;
	new_clampagc_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_CLAMPAGC_CTRL_reg);
	new_clampagc_ctrl_reg.clampagc_rc_rate = ivalue;
	vdcf_outl(VDTOP_NEW_CLAMPAGC_CTRL_reg, new_clampagc_ctrl_reg.regValue);
}

unsigned char drvif_module_vdc_FIFO_status_Factory_Mode_Get_info(void)
{
	/* 975c[1:0] */
	vdtop_fifo_status_RBUS fifo_status_reg;
	fifo_status_reg.regValue = vdcf_inl(VDTOP_FIFO_STATUS_reg);
	return ((fifo_status_reg.regValue) & 0x03);
}


/* ======================================================================== */
unsigned char drvif_module_vdc_DMACount_Factory_Mode_Get_info(void)
{
	return ucVdc_DMA_Count;
}

void drvif_module_vdc_DMACount_Factory_Mode(unsigned char count)
{
	ucVdc_DMA_Count = count;
}

void drvif_module_vdc_factory_TestDMA_Setting(void)
{
	vdpq_yc_sep_mode_ctrl_RBUS yc_sep_mode_ctrl_reg;
	vdpq_dma_ctrl5_RBUS	dma_ctrl5_reg;
	vdpq_video_dma_debug_ctrl_RBUS video_dma_debug_ctrl_reg;
	vd_ifd_input_input_debug_RBUS input_debug_reg;

#ifdef CONFIG_ENABLE_3D_SETTING
	Scaler_Set3DEnable(_DISABLE);
#endif
	drvif_module_vpq_SetYcSep(VDC_YCSEPARATE_DEFAULT);
	/* stop Auto MA */
	rtdf_clearBits(0xb8022210, _BIT25);	/* disable auto ma */
	drvif_scaler_vactive_end_irq(_FALSE, _CHANNEL1);
	drvif_scaler_vactive_end_irq(_FALSE, _CHANNEL2);

#ifdef CONFIG_ENABLE_3D_SETTING
	drvif_module_vpq_DisableMemory();
#endif

	yc_sep_mode_ctrl_reg.regValue = vdcf_inl(VDPQ_YC_SEP_MODE_CTRL_reg);
	yc_sep_mode_ctrl_reg.yc_sep_mode = 0;
	vdcf_outl(VDPQ_YC_SEP_MODE_CTRL_reg, yc_sep_mode_ctrl_reg.regValue);

	Rt_Delay(10);
//	rtdf_outl(0xb8034c0c,0x04);	// VBI memory off
//	rtdf_setBits(0xb8024010,_BIT19);	// DI force 2D (memory off)

	dma_ctrl5_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL5_reg);
	dma_ctrl5_reg.mem_off = 1;
	vdcf_outl(VDPQ_DMA_CTRL5_reg, dma_ctrl5_reg.regValue);	// memory off
	Rt_Delay(10);

#if 1
	input_debug_reg.regValue = rtdf_inl(VD_IFD_INPUT_INPUT_DEBUG_reg);
	input_debug_reg.input_debug_sel = 0x03;	// set AD4 (VD ADC)
	rtdf_outl(VD_IFD_INPUT_INPUT_DEBUG_reg, input_debug_reg.regValue);
#else
	rtdf_outl(FEIN_INPUT_DEBUG_reg, 0x03);
#endif

	video_dma_debug_ctrl_reg.regValue = vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg);
	video_dma_debug_ctrl_reg.dma_mode = 1;
	vdcf_outl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg, video_dma_debug_ctrl_reg.regValue);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC][1] 97f8 Tdma mode %x\n", vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg));
}

void drvif_module_vdc_factory_debug_get_dma_prefix(char* prefix)
{
	UINT8 mode = 0;

	vdpq_video_dma_debug_ctrl_RBUS video_dma_debug_ctrl_reg;
	video_dma_debug_ctrl_reg.regValue = vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg);

	switch (video_dma_debug_ctrl_reg.dma_debugmode_sel) {
	case DMA_VD_MODE:
		mode = video_dma_debug_ctrl_reg.dma_debug_vd_sel;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] get dma mode:%x\n", mode);
		break;
	case DMA_IFD_MODE:
		mode = 12;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] test dma mode: IFD\n");
		break;
	case DMA_VBI_MODE:
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] test dma mode: VBI\n");
		mode = 13;
		break;
	case DMA_REG_MODE:
		mode = 14;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] test dma mode: REG_MODE\n");
		break;
	}
//	mode = drvif_module_vdc_factory_debug_get_dma_mode();
	strcpy(prefix, VD_dma_name_table[mode]);
}

void drvif_module_vdc_factory_TestDMA_mode_select(unsigned char value)
{
	vdpq_video_dma_debug_ctrl_RBUS video_dma_debug_ctrl_reg;
	video_dma_debug_ctrl_reg.regValue = vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg);

	switch (value) {
	case DMA_VD_M0:
	case DMA_VD_M1:
	case DMA_VD_M2:
	case DMA_VD_M3:
	case DMA_VD_M4:
	case DMA_VD_M5:
	case DMA_VD_M6:
	case DMA_VD_M7:
	case DMA_VD_M8:
	case DMA_VD_M9:
	case DMA_VD_MA:
	case DMA_VD_MB:
		video_dma_debug_ctrl_reg.dma_debugmode_sel = DMA_VD_MODE;
		video_dma_debug_ctrl_reg.dma_debug_vd_sel = value;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] Test DMA, VD mode:%x\n", value);
		break;
	case DMA_IFD:		// IFD
		video_dma_debug_ctrl_reg.dma_debugmode_sel = DMA_IFD_MODE;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] Test DMA, IFD mode\n");
		break;
	case DMA_VBI:		// VBI
		video_dma_debug_ctrl_reg.dma_debugmode_sel = DMA_VBI_MODE;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] Test DMA, VBI mode\n");
		break;
	case DMA_REG:		// none
		video_dma_debug_ctrl_reg.dma_debugmode_sel = DMA_REG_MODE;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] Test DMA, REG mode\n");
		break;
	}
	vdcf_outl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg, video_dma_debug_ctrl_reg.regValue);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC][2] 97f8 Tdma mode %x\n", vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg));
}

#define GFP_DCU1                        0x00000001
#ifdef kernel_space_dumpdma
unsigned int m_vd_pCasheStartAddr = NULL;
unsigned int m_vd_PhyStartAddr = NULL;
unsigned int m_vd_pNonCacheStartAddr = NULL;
#else
unsigned char *m_vd_pCasheStartAddr = NULL;
unsigned long m_vd_PhyStartAddr;
unsigned char *m_vd_pNonCacheStartAddr;
#endif

#define SLRLIB_PRINTF(format, args...)

void xDumpIFDRawData(unsigned int Length)
{
#if 0
//	unsigned int PhyStartAddr = 0;
	unsigned int iSize = 0;//, Width = 0, Height = 0;
	unsigned char *iStartAddr = 0;
	int iFileNum;

	IoReg_SetBits(0xb8027220, _BIT1);
#if 0
	get_vdc_dump_addr(&PhyStartAddr, &iStartAddr);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[xDumpVDRawData] %x %x...\n", PhyStartAddr, iStartAddr);
#else
	iStartAddr = m_vd_pNonCacheStartAddr;
#endif
	UINT32 * ptr = (UINT32*) iStartAddr;
	VDC_DEBUG_MSG(VDC_MSG_FACT,"%x %x %x %x\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3));

	iSize = Length;


	if (iStartAddr != 0 /*&& iSize != 0*/) {
		char sFilePath[128], sFileName[32];
		drvif_ifd_factorymode_debug_get_dma_prefix(&sFileName[0]);
		VDC_DEBUG_MSG(VDC_MSG_FACT,"%s\n", sFileName);
		system("setprop persist.sampling_profiler 1");
#if 1//------USB----------
		system("mount -t vfat -o remount /dev/sda1 /mnt/usbmounts/sda1");
		//sprintk(sFilePath, "%s/%s%s%s", "/mnt/usbmounts/sda1", "IFD_",sFileName, ".bin"); //Dump to USB
		//sprintk(sFilePath, "%s", "chmod 777 /mnt/media_rw/udisk/*");
		//sprintk(sFilePath, "%s/%s%s%s", "/mnt/media_rw/udisk", "IFD_",sFileName, ".bin");
		sprintk(sFilePath, "%s", "chmod 777 /mnt/usbmounts/sda1/*");
		sprintk(sFilePath, "%s/%s%s%s", "/mnt/usbmounts/sda1", "IFD_", sFileName, ".bin");
#else//------NFS----------
		//system("mount -t nfs -o tcp,nolock 172.21.181.20:/home/yukichen/nfs/ /nfs");
		sprintk(sFilePath, "%s/%s%s%s", "/tmp", "IFD_", sFileName, ".bin"); //Dump to NFS
#endif
		VDC_DEBUG_MSG(VDC_MSG_FACT,"%s\n", sFilePath);

		FILE *pFile = fopen(sFilePath, "w");
		if (pFile == NULL) {
			VDC_DEBUG_MSG(VDC_MSG_FACT,"file open fail...\n");
		} else { //frank@1017 change below code to solve scan tool warning
			iFileNum = fileno(pFile);
		}

		if (pFile) {
			unsigned int iCnt = 0, iBufIdx = 0;
			unsigned int *iCurAddr = (unsigned int*)iStartAddr;
			unsigned int bufArray[128];
			unsigned int iBuf = 0;

			/*
			Info=vdc_endianswap(iSize/4);
			fwrite(&Info,1,4, pFile);
			Info=vdc_endianswap(PhyStartAddr);
			fwrite(&Info, 1, 4,pFile);
			*/

			while (iCnt < iSize) {
				VDC_DEBUG_MSG(VDC_MSG_FACT,".");
				iBuf = *iCurAddr;
				bufArray[iBufIdx] = iBuf;
				iBufIdx ++;

				if (iBufIdx >= 128) {
					fwrite(bufArray, 128 * 4, 1, pFile);
					iBufIdx = 0;
				}

				iCnt += 4;
				iCurAddr += 1; //move pointer 4byte
				//VDC_DEBUG_MSG(VDC_MSG_FACT,"iSize=%x\n",iCnt);
			}
			VDC_DEBUG_MSG(VDC_MSG_FACT,"\n");
			// last
			if (iBufIdx > 0) {
				fwrite(bufArray, iBufIdx * 4, 1, pFile);
				iBufIdx = 0;
			}
			VDC_DEBUG_MSG(VDC_MSG_FACT,".\n");
			if (0 != fflush(pFile))
				VDC_DEBUG_MSG(VDC_MSG_FACT,"Flash to file fail\n");

			// Sync to device

			if (0 != fsync(iFileNum)) {
				VDC_DEBUG_MSG(VDC_MSG_FACT,"fsync fail\n");
				if (fdatasync(iFileNum) == -1) {
					VDC_DEBUG_MSG(VDC_MSG_FACT,"fdatasync error!!\n");
				}
			}



			fclose(pFile);
			VDC_DEBUG_MSG(VDC_MSG_FACT,"write to file %s, size = %d\n", sFilePath, iSize);
		} else {
			VDC_DEBUG_MSG(VDC_MSG_FACT,"write file Error!\n");
		}
	}

	IoReg_ClearBits(0xb8027220, _BIT1);
//   	 dump_adc_rawdata_release();

//	return 0;
#endif
}

#ifdef kernel_space_dumpdma
int exe_remount_usb_storage(void)
{
	int ret = -1;
	char path[] = "/bin/mount";
	char *argv[] = {path, "-t", "vfat","-o","remount,rw","/dev/sda1","/mnt/usbmounts/sda1", NULL};
	char *envp[] = {NULL};

 	VDC_DEBUG_MSG(VDC_MSG_FACT,"EXE %s\n",__FUNCTION__);
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
	if(ret < 0)
		VDC_DEBUG_MSG(VDC_MSG_FACT,"fail ret=%d\n", ret);

	return 0;
}

int exe_chmod_to_high_permision(void)
{
	int ret = -1;
	char path[] = "/bin/chmod";
	char *argv[] = {path, "777", "/mnt/usbmounts/sda1/*", NULL};
	char *envp[] = {NULL};

	VDC_DEBUG_MSG(VDC_MSG_FACT,"EXE %s\n",__FUNCTION__);
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
	if(ret < 0)
		VDC_DEBUG_MSG(VDC_MSG_FACT,"fail ret=%d\n", ret);

	return 0;
}

int exe_mkdir(void)
{
	int ret = -1;
	char path[] = "/bin/mkdir";
	char *argv[] = {path, "/tmp/test123", NULL};
	char *envp[] = {NULL};

	VDC_DEBUG_MSG(VDC_MSG_FACT,"EXE %s\n",__FUNCTION__);
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
	if(ret < 0)
		VDC_DEBUG_MSG(VDC_MSG_FACT,"fail ret=%d\n", ret);

	return 0;
}
#endif //kernel_space_dumpdma

void xDumpVDRawData(unsigned int Length)
{
#if 1
//	unsigned int PhyStartAddr = 0;
	unsigned int iSize = 0;//, Width = 0, Height = 0;
	unsigned char *iStartAddr = 0;
//	int iFileNum;
#ifdef kernel_space_dumpdma
	struct file *pFile;
	loff_t offset = 0;
	ssize_t rc = 0;
#endif //kernel_space_dumpdma

	IoReg_SetBits(0xb8027220, _BIT1);
#if 0
	get_vdc_dump_addr(&PhyStartAddr, &iStartAddr);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[xDumpVDRawData] %x %x...\n", PhyStartAddr, iStartAddr);
#else
	iStartAddr = (unsigned char *)m_vd_pNonCacheStartAddr;
#endif
	UINT32 * ptr = (UINT32*) iStartAddr;
	VDC_DEBUG_MSG(VDC_MSG_FACT,"%x %x %x %x\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3));

	iSize = Length;

	if (iStartAddr != 0 && iSize != 0) {
		char sFilePath[128], sFileName[32];
		drvif_module_vdc_factory_debug_get_dma_prefix(&sFileName[0]);
		VDC_DEBUG_MSG(VDC_MSG_FACT,"file name: %s\n", sFileName);
#ifdef kernel_space_dumpdma
		exe_remount_usb_storage();

		exe_chmod_to_high_permision();

		snprintf(sFilePath, 128, "%s/%s%s%s", "/tmp/usb/sda/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
#else//kernel_space_dumpdma
		system("setprop persist.sampling_profiler 1");
#if 1//------USB----------
		system("mount -t vfat -o remount,rw /dev/sda1 /mnt/usbmounts/sda1");
		sprintk(sFilePath, "%s", "chmod 777 /mnt/usbmounts/sda1/*");
		sprintk(sFilePath, "%s/%s%s%s", "/mnt/usbmounts/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
#else//------NFS----------
//		system("mount -t nfs -o tcp,nolock 172.21.15.135:/home/RTDOMAIN/jenniferchang/nfs/ /nfs");
		sprintk(sFilePath, "%s/%s%s%s", "/nfs", "VdDma_", sFileName, ".bin"); //Dump to NFS
#endif
#endif//kernel_space_dumpdma
		VDC_DEBUG_MSG(VDC_MSG_FACT,"%s\n", sFilePath);

#ifdef kernel_space_dumpdma
		pFile = filp_open(sFilePath,O_CREAT |O_RDWR,0600);

		if(IS_ERR(pFile)) {
  		VDC_DEBUG_MSG(VDC_MSG_FACT,"file open fail...\n");
      snprintf(sFilePath, 128, "%s/%s%s%s", "/mnt/usbmounts/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
      VDC_DEBUG_MSG(VDC_MSG_FACT,"%s\n", sFilePath);
      pFile = filp_open(sFilePath,O_CREAT |O_RDWR,0600);
		  if(IS_ERR(pFile)) {
     		 VDC_DEBUG_MSG(VDC_MSG_FACT,"file222222  open fail...\n");
     		 snprintf(sFilePath, 128, "%s/%s%s%s", "/mnt/media_rw/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
         VDC_DEBUG_MSG(VDC_MSG_FACT,"%s\n", sFilePath);
         pFile = filp_open(sFilePath,O_CREAT |O_RDWR,0600);
         if(IS_ERR(pFile)) {
         	             VDC_DEBUG_MSG(VDC_MSG_FACT,"file3  open fail...\n");
                }
                else
                    {

                      }

		  }
        else
                    {

													}
		}
		else {

		}
#else
		FILE *pFile = fopen(sFilePath, "w");
		if (pFile == NULL) {
			VDC_DEBUG_MSG(VDC_MSG_FACT,"file open fail...\n");
		} else { //frank@1017 change below code to solve scan tool warning
			iFileNum = fileno(pFile);
		}
#endif//kernel_space_dumpdma
		if (pFile) {
			unsigned int iCnt = 0, iBufIdx = 0;
			unsigned int *iCurAddr = (unsigned int*)iStartAddr;
			unsigned int bufArray[128];
			unsigned int iBuf = 0;

			while (iCnt < iSize) {
//				VDC_DEBUG_MSG(VDC_MSG_FACT,".");
				iBuf = *iCurAddr;
				bufArray[iBufIdx] = iBuf;
				iBufIdx ++;

				if (iBufIdx >= 128) {
					#ifdef kernel_space_dumpdma
					rc = kernel_write(pFile, (const char *)bufArray, 128 * 4, offset);
					offset += rc;
					#else
					fwrite(bufArray, 128 * 4, 1, pFile);
					#endif//kernel_space_dumpdma
					iBufIdx = 0;
				}

				iCnt += 4;
				iCurAddr += 1; //move pointer 4byte
				//VDC_DEBUG_MSG(VDC_MSG_FACT,"iSize=%x\n",iCnt);
			}
			VDC_DEBUG_MSG(VDC_MSG_FACT,"\n");
			// last
			if (iBufIdx > 0) {
				#ifdef kernel_space_dumpdma
				kernel_write(pFile, (const char *)bufArray, iBufIdx * 4, offset);
				#else
				fwrite(bufArray, iBufIdx * 4, 1, pFile);
				#endif//kernel_space_dumpdma
				iBufIdx = 0;
			}
			VDC_DEBUG_MSG(VDC_MSG_FACT,".\n");

			#ifndef kernel_space_dumpdma
			if (0 != fflush(pFile))
				VDC_DEBUG_MSG(VDC_MSG_FACT,"Flash to file fail\n");
			#endif//kernel_space_dumpdma

			// Sync to device

			#ifndef kernel_space_dumpdma
			if (0 != fsync(iFileNum)) {
				VDC_DEBUG_MSG(VDC_MSG_FACT,"fsync fail\n");
				if (fdatasync(iFileNum) == -1) {
					VDC_DEBUG_MSG(VDC_MSG_FACT,"fdatasync error!!\n");
				}
			}
			#endif//kernel_space_dumpdma

			#ifdef kernel_space_dumpdma
			filp_close(pFile, NULL);
			#else
			fclose(pFile);
			#endif//kernel_space_dumpdma
			VDC_DEBUG_MSG(VDC_MSG_FACT,"write to file %s, size = %d\n", sFilePath, iSize);
		} else {
			VDC_DEBUG_MSG(VDC_MSG_FACT,"write file Error!\n");
		}
	}

	IoReg_ClearBits(0xb8027220, _BIT1);
#endif
}

/* 21MBits = 0x01500000(Length) ==> 0x002a0000 (byte for 3D addr) */
/* 32MBits = 0x02000000(Length) ==> 0x00400000 (byte for 3D addr) */
static StructMemBlock MemTag[MEMIDX_UNKNOW];	// memory tag information
unsigned int drvif_module_vdc_factory_TestDMA_Enable(unsigned int Length)
{
	vdpq_mem0_addr_ini_RBUS mem0_addr_ini_reg;
	vdpq_mem0_addr_end_RBUS mem0_addr_end_reg;
	vdpq_dma_ctrl5_RBUS dma_ctrl5_reg;
	vdpq_video_dma_debug_ctrl_RBUS video_dma_debug_ctrl_reg;

	unsigned int Data[2];
	unsigned int nAddr;
	unsigned int DMA_Start_Addr = 0;
	unsigned int DMA_Stop_Addr = 0;
	unsigned char i;

	IoReg_SetBits(0xb8027220, _BIT1);
	drvif_module_vdc_factory_TestDMA_Setting();
#if 0
	drvif_memory_free_block(MEMIDX_ALL);
#else
	for ( i=MEMIDX_VDC ; i<MEMIDX_ALL ; ++i ) {	// clear all tag information
		MemTag[i].StartAddr = _DUMMYADDR;
		MemTag[i].Size = 0;
		MemTag[i].Status = UNDEFINED;
	}
#endif
	VDC_DEBUG_MSG(VDC_MSG_FACT, "release all memory !! DMA Go~\n");
#ifdef kernel_space_dumpdma
	m_vd_pCasheStartAddr = (unsigned int)dvr_malloc_uncached_specific(Length, GFP_DCU2_FIRST,(void **)&m_vd_pNonCacheStartAddr);
	if(m_vd_pCasheStartAddr == 0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VDC,"%s.%d\n", __FUNCTION__, __LINE__);
		rtd_printk(KERN_DEBUG, TAG_NAME_VDC,"[VD DMA] alloc idma sequence memory failed[%x]\n", m_vd_pCasheStartAddr);
		return FALSE;
	}
	nAddr = (unsigned int)dvr_to_phys((void *)m_vd_pCasheStartAddr);
	VDC_DEBUG_MSG(VDC_MSG_FACT, "cache:0x%x,noncache:0x%x,phy:0x%x\n",m_vd_pCasheStartAddr,m_vd_pNonCacheStartAddr,nAddr);
#else
#if 0
	m_vd_pCasheStartAddr = (BYTE *)pli_allocContinuousMemorySpecific(m_vd_MallocSize, (char**)&m_vd_pNonCacheStartAddr, &m_vd_PhyStartAddr, GFP_DCU1);
	if (m_vd_pCasheStartAddr == NULL) {
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] release all memory !!\n");
		return _FAIL;
	} else {
		//physical address
		nAddr = (unsigned int)m_vd_PhyStartAddr;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[SLR_MEMORY][PLI][Cache:%x][Phy:%x][Size:%x]\n", (unsigned int)m_vd_pCasheStartAddr, (unsigned int)m_vd_PhyStartAddr, m_vd_MallocSize);
	}
#else
	nAddr = drvif_memory_alloc_block(MEMIDX_VDC, Length, MEMALIGN_ANY) ;
#endif
#endif

	DMA_Start_Addr = (nAddr >> 3) & 0x1fffffff;
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] re-alloc block !!\n");

	mem0_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_INI_reg);
	mem0_addr_ini_reg.frame_addr0 = DMA_Start_Addr;
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]VDC mem0 start = %x \n", DMA_Start_Addr);
	vdcf_outl(VDPQ_MEM0_ADDR_INI_reg, mem0_addr_ini_reg.regValue);

	mem0_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_END_reg);
#if 0	// org. 3D space
	vdpq_mem3_addr_end_RBUS mem3_addr_end_reg;
	mem3_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_END_reg);
	DMA_Stop_Addr = mem3_addr_end_reg.frame_addr3_end;

	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]org. space, mem0 stop = %x\n", DMA_Stop_Addr);
#else
	DMA_Stop_Addr = DMA_Start_Addr + (Length >> 3);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]VDC mem0 stop = %x \n", DMA_Stop_Addr);
#endif
	mem0_addr_end_reg.frame_addr0_end = DMA_Stop_Addr;
	vdcf_outl(VDPQ_MEM0_ADDR_END_reg, mem0_addr_end_reg.regValue);

	dma_ctrl5_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL5_reg);
	dma_ctrl5_reg.mem_off = 0;
	vdcf_outl(VDPQ_DMA_CTRL5_reg, dma_ctrl5_reg.regValue);	// memory on

	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]start addr = 0x%x, length = 0x%x, stop_Addr= 0x%x\n", DMA_Start_Addr, (Length >> 3), DMA_Stop_Addr);

	video_dma_debug_ctrl_reg.regValue = vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg);
	video_dma_debug_ctrl_reg.dma_debugmode_en = 1;
	vdcf_outl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg, video_dma_debug_ctrl_reg.regValue);	// test dma enable

	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC][3]the mode is 97f8 = %x Saving ...\n", vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]9008=%x\n", drvif_video_status_reg(VDC_STATUS_REG1));

	for (Data[0] = 0; Data[0] < 300; Data[0]++) {
		VDC_DEBUG_MSG(VDC_MSG_FACT,".");
		for (Data[1] = 0; Data[1] < 500000; Data[1]++)
			;
	}

	VDC_DEBUG_MSG(VDC_MSG_FACT,"\n[VDC] TDMA Done!!\n");

	video_dma_debug_ctrl_reg.dma_debugmode_en = 0;
	vdcf_outl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg, video_dma_debug_ctrl_reg.regValue);	// test dma disable

	xDumpVDRawData(Length);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] write file to USB Done!!  Please power off !!!\n");

	return (0xa0000000 | DMA_Start_Addr);	// return print address
}
unsigned int drvif_module_vdc_factory_IFDDMA_Enable(unsigned int Length)
{
	vdpq_mem0_addr_ini_RBUS mem0_addr_ini_reg;
	vdpq_mem0_addr_end_RBUS mem0_addr_end_reg;
	vdpq_dma_ctrl5_RBUS dma_ctrl5_reg;
	vdpq_video_dma_debug_ctrl_RBUS video_dma_debug_ctrl_reg;

	unsigned int Data[2];
	unsigned int nAddr;
	unsigned int DMA_Start_Addr = 0;
	unsigned int DMA_Stop_Addr = 0;

	drvif_module_vdc_factory_TestDMA_mode_select(DMA_IFD);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"ifd dump setting\n");
	drvif_module_vdc_factory_TestDMA_Setting();
	drvif_memory_free_block(MEMIDX_ALL);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] release all memory !!\n");
#if 0
	m_vd_pCasheStartAddr = (unsigned char *)pli_allocContinuousMemorySpecific(m_vd_MallocSize, (char**)&m_vd_pNonCacheStartAddr, &m_vd_PhyStartAddr, GFP_DCU1);
	if (m_vd_pCasheStartAddr == NULL) {
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] release all memory !!\n");
		return _FAIL;
	} else {
		//physical address
		nAddr = (unsigned int)m_vd_PhyStartAddr;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[SLR_MEMORY][PLI][Cache:%x][Phy:%x][Size:%x]\n", (unsigned int)m_vd_pCasheStartAddr, (unsigned int)m_vd_PhyStartAddr, m_vd_MallocSize);
	}
#else
	nAddr = drvif_memory_alloc_block(MEMIDX_VDC, Length, MEMALIGN_ANY) ;
#endif

	DMA_Start_Addr = (nAddr >> 3) & 0x1fffffff;
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] re-alloc block !!\n");

	mem0_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_INI_reg);
	mem0_addr_ini_reg.frame_addr0 = DMA_Start_Addr;
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]VDC mem0 start = %x \n", DMA_Start_Addr);
	vdcf_outl(VDPQ_MEM0_ADDR_INI_reg, mem0_addr_ini_reg.regValue);

	mem0_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_END_reg);
#if 0	// org. 3D space
	vdpq_mem3_addr_end_RBUS mem3_addr_end_reg;
	mem3_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_END_reg);
	DMA_Stop_Addr = mem3_addr_end_reg.frame_addr3_end;

	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]org. space, mem0 stop = %x\n", DMA_Stop_Addr);
#else
	DMA_Stop_Addr = DMA_Start_Addr + (Length >> 3);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]VDC mem0 stop = %x \n", DMA_Stop_Addr);
#endif
	mem0_addr_end_reg.frame_addr0_end = DMA_Stop_Addr;
	vdcf_outl(VDPQ_MEM0_ADDR_END_reg, mem0_addr_end_reg.regValue);

	dma_ctrl5_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL5_reg);
	dma_ctrl5_reg.mem_off = 0;
	vdcf_outl(VDPQ_DMA_CTRL5_reg, dma_ctrl5_reg.regValue);	// memory on

	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]start addr = 0x%x, length = 0x%x, stop_Addr= 0x%x\n", DMA_Start_Addr, (Length >> 3), DMA_Stop_Addr);

	video_dma_debug_ctrl_reg.regValue = vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg);
	video_dma_debug_ctrl_reg.dma_debugmode_en = 1;
	vdcf_outl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg, video_dma_debug_ctrl_reg.regValue);	// test dma enable

	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC][3]the mode is 97f8 = %x Saving ...\n", vdcf_inl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg));
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC]9008=%x\n", drvif_video_status_reg(VDC_STATUS_REG1));

	for (Data[0] = 0; Data[0] < 300; Data[0]++) {
		VDC_DEBUG_MSG(VDC_MSG_FACT,".");
		for (Data[1] = 0; Data[1] < 500000; Data[1]++)
			;
	}

	VDC_DEBUG_MSG(VDC_MSG_FACT,"\n[VDC] TDMA Done!!\n");

	video_dma_debug_ctrl_reg.dma_debugmode_en = 0;
	vdcf_outl(VDPQ_VIDEO_DMA_DEBUG_CTRL_reg, video_dma_debug_ctrl_reg.regValue);	// test dma disable

	xDumpIFDRawData(Length);
	VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] write file to USB Done!!  Please power off !!!\n");

	return (0xa0000000 | DMA_Start_Addr);	// return print address
}


/*============================================================================== */

void drvif_module_vdc_2D_Wide_BPF_Sel_Y_Factory_Mode(unsigned char value)
{
	vdpq_bpf_bw_sel_y_RBUS bpf_bw_sel_y_reg;
	bpf_bw_sel_y_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_Y_reg);
	bpf_bw_sel_y_reg.wide_bpf_sel_y = value;
	vdcf_outl(VDPQ_BPF_BW_SEL_Y_reg, bpf_bw_sel_y_reg.regValue);
}

unsigned char drvif_module_vdc_2D_Wide_BPF_Sel_Y_Factory_Get_info(void)
{
	vdpq_bpf_bw_sel_y_RBUS bpf_bw_sel_y_reg;
	bpf_bw_sel_y_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_Y_reg);
	return bpf_bw_sel_y_reg.wide_bpf_sel_y;
}

void drvif_module_vdc_2D_Narrow_BPF_Sel_Y_Factory_Mode(unsigned char value)
{
	vdpq_bpf_bw_sel_y_RBUS bpf_bw_sel_y_reg;
	bpf_bw_sel_y_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_Y_reg);
	bpf_bw_sel_y_reg.narrow_bpf_sel_y = value;
	vdcf_outl(VDPQ_BPF_BW_SEL_Y_reg, bpf_bw_sel_y_reg.regValue);
}

unsigned char drvif_module_vdc_2D_Narrow_BPF_Sel_Y_Factory_Get_info(void)
{
	vdpq_bpf_bw_sel_y_RBUS bpf_bw_sel_y_reg;
	bpf_bw_sel_y_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_Y_reg);
	return bpf_bw_sel_y_reg.narrow_bpf_sel_y;
}

void drvif_module_vdc_2D_Wide_BPF_Sel_C_Factory_Mode(unsigned char value)
{
	vdpq_bpf_bw_sel_c_RBUS bpf_bw_sel_c_reg;
	bpf_bw_sel_c_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_C_reg);
	bpf_bw_sel_c_reg.wide_bpf_sel_c = value;
	vdcf_outl(VDPQ_BPF_BW_SEL_C_reg, bpf_bw_sel_c_reg.regValue);
}

unsigned char drvif_module_vdc_2D_Wide_BPF_Sel_C_Factory_Get_info(void)
{
	vdpq_bpf_bw_sel_c_RBUS bpf_bw_sel_c_reg;
	bpf_bw_sel_c_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_C_reg);
	return bpf_bw_sel_c_reg.wide_bpf_sel_c;
}

void drvif_module_vdc_2D_Narrow_BPF_Sel_C_Factory_Mode(unsigned char value)
{
	vdpq_bpf_bw_sel_c_RBUS bpf_bw_sel_c_reg;
	bpf_bw_sel_c_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_C_reg);
	bpf_bw_sel_c_reg.narrow_bpf_sel_c = value;
	vdcf_outl(VDPQ_BPF_BW_SEL_C_reg, bpf_bw_sel_c_reg.regValue);
}

unsigned char drvif_module_vdc_2D_Narrow_BPF_Sel_C_Factory_Get_info(void)
{
	vdpq_bpf_bw_sel_c_RBUS bpf_bw_sel_c_reg;
	bpf_bw_sel_c_reg.regValue = vdcf_inl(VDPQ_BPF_BW_SEL_C_reg);
	return bpf_bw_sel_c_reg.narrow_bpf_sel_c;
}

void drvif_module_vdc_H2V_Vflag_Remg_thr_Factory_Mode(unsigned char value)
{
	vdpq_adap_bpf_c_th2_RBUS adap_bpf_c_th2_reg;
	adap_bpf_c_th2_reg.regValue = vdcf_inl(VDPQ_ADAP_BPF_C_TH2_reg);
	adap_bpf_c_th2_reg.h2v_vflag_remag_thr = value;
	vdcf_outl(VDPQ_ADAP_BPF_C_TH2_reg, adap_bpf_c_th2_reg.regValue);
}

unsigned char drvif_module_vdc_H2V_Vflag_Remg_thr_Factory_Mode_Get_info(void)
{
	vdpq_adap_bpf_c_th2_RBUS adap_bpf_c_th2_reg;
	adap_bpf_c_th2_reg.regValue = vdcf_inl(VDPQ_ADAP_BPF_C_TH2_reg);
	return adap_bpf_c_th2_reg.h2v_vflag_remag_thr;
}

void drvif_module_vdc_H2V_Vflag_Mag_thr_Factory_Mode(unsigned char value)
{
	vdpq_adap_bpf_c_th2_RBUS adap_bpf_c_th2_reg;
	adap_bpf_c_th2_reg.regValue = vdcf_inl(VDPQ_ADAP_BPF_C_TH2_reg);
	adap_bpf_c_th2_reg.h2v_vflag_mag_thr = value;
	vdcf_outl(VDPQ_ADAP_BPF_C_TH2_reg, adap_bpf_c_th2_reg.regValue);
}

unsigned char drvif_module_vdc_H2V_Vflag_Mag_thr_Factory_Mode_Get_info(void)
{
	vdpq_adap_bpf_c_th2_RBUS adap_bpf_c_th2_reg;
	adap_bpf_c_th2_reg.regValue = vdcf_inl(VDPQ_ADAP_BPF_C_TH2_reg);
	return adap_bpf_c_th2_reg.h2v_vflag_mag_thr;
}

void drvif_module_vdc_H2V_Vflag_Noise_thr_Factory(unsigned char value)
{
	vdpq_h2v_y_noise_thr_RBUS h2v_y_noise_thr_reg;
	h2v_y_noise_thr_reg.regValue = vdcf_inl(VDPQ_H2V_Y_NOISE_THR_reg);
	h2v_y_noise_thr_reg.h2v_y_noise_thr = value;
	vdcf_outl(VDPQ_H2V_Y_NOISE_THR_reg, h2v_y_noise_thr_reg.regValue);
}

unsigned char drvif_module_vdc_H2V_Vflag_Noise_thr_Factory_Mode_Get_info(void)
{
	vdpq_h2v_y_noise_thr_RBUS h2v_y_noise_thr_reg;
	h2v_y_noise_thr_reg.regValue = vdcf_inl(VDPQ_H2V_Y_NOISE_THR_reg);
	return h2v_y_noise_thr_reg.h2v_y_noise_thr;
}

void drvif_module_vdc_H2V_Vflag_Max_HDY_Factory(unsigned char value)
{
	vdpq_h2v_noise_max_hdy_RBUS h2v_noise_max_hdy_reg;
	h2v_noise_max_hdy_reg.regValue = vdcf_inl(VDPQ_H2V_NOISE_MAX_HDY_reg);
	h2v_noise_max_hdy_reg.h2v_noise_max_hdy = value;
	vdcf_outl(VDPQ_H2V_NOISE_MAX_HDY_reg, h2v_noise_max_hdy_reg.regValue);
}

unsigned char drvif_module_vdc_H2V_Vflag_Max_HDY_Factory_Mode_Get_info(void)
{
	vdpq_h2v_noise_max_hdy_RBUS h2v_noise_max_hdy_reg;
	h2v_noise_max_hdy_reg.regValue = vdcf_inl(VDPQ_H2V_NOISE_MAX_HDY_reg);
	return h2v_noise_max_hdy_reg.h2v_noise_max_hdy;
}

void drvif_module_vdc_H2V_Vflag_Noise_YADDC_Factory(unsigned char value)
{
	vdpq_h2v_noise_y_add_dc_RBUS h2v_noise_y_add_dc_reg;
	h2v_noise_y_add_dc_reg.regValue = vdcf_inl(VDPQ_H2V_NOISE_Y_ADD_DC_reg);
	h2v_noise_y_add_dc_reg.v2v_noise_y_add_dc = value;
	vdcf_outl(VDPQ_H2V_NOISE_Y_ADD_DC_reg, h2v_noise_y_add_dc_reg.regValue);
}

unsigned char drvif_module_vdc_H2V_Vflag_Noise_YADDC_Factory_Mode_Get_info(void)
{
	vdpq_h2v_noise_y_add_dc_RBUS h2v_noise_y_add_dc_reg;
	h2v_noise_y_add_dc_reg.regValue = vdcf_inl(VDPQ_H2V_NOISE_Y_ADD_DC_reg);
	return h2v_noise_y_add_dc_reg.v2v_noise_y_add_dc;
}

void drvif_module_vdc_H2V_Vflag_Blend_Ratio_Factory(unsigned char value)
{
	vdpq_h2v_blend_ratio_RBUS h2v_blend_ratio_reg;
	h2v_blend_ratio_reg.regValue = vdcf_inl(VDPQ_H2V_BLEND_RATIO_reg);
	h2v_blend_ratio_reg.h2v_blendratio = value;
	vdcf_outl(VDPQ_H2V_BLEND_RATIO_reg, h2v_blend_ratio_reg.regValue);
}

unsigned char drvif_module_vdc_H2V_Vflag_Blend_Ratio_Factory_Get_info(void)
{
	vdpq_h2v_blend_ratio_RBUS h2v_blend_ratio_reg;
	h2v_blend_ratio_reg.regValue = vdcf_inl(VDPQ_H2V_BLEND_RATIO_reg);
	return h2v_blend_ratio_reg.h2v_blendratio;
}

unsigned char drvif_module_vdc_Read_New_Vdetect_Factory_Get_info(void)
{
	vdtop_new_vdetect_ctrl_RBUS new_vdetect_ctrl_reg;
	new_vdetect_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_VDETECT_CTRL_reg);
	return new_vdetect_ctrl_reg.new_vdetect_en;
}

void drvif_module_vdc_New_Vdetect_setting_Factory_mode(unsigned char value)
{
	if (value)
		drvif_module_vdc_new_vdetect_Enable(New_vedetect);
	else
		drvif_module_vdc_new_vdetect_Enable(Old_vedetect);
}
#if 0
void drvif_module_ADC_LPF_Gain_setting_Factory_mode(unsigned char value)
{
	unsigned char temp = value;	/* fix it jj!!*/
	/* fix it jj!!
		adc_ctl_rgb12_RBUS adc_ctl_rgb12_reg;
		adc_ctl_rgb12_reg.regValue = rtdf_inl(ADC_ADC_CTL_RGB12_reg);
		if(value)
			{
			adc_ctl_rgb12_reg.adc_ctl_rgb1_14 = 1;		// select VD adc path gain = 0.5
			adc_ctl_rgb12_reg.adc_ctl_rgb1_12 = 1;
			}
		else
			{
			adc_ctl_rgb12_reg.adc_ctl_rgb1_14 = 0;		// select VD adc path gain = 0.5
			adc_ctl_rgb12_reg.adc_ctl_rgb1_12 = 0;
			}

		rtdf_outl(ADC_ADC_CTL_RGB12_reg,adc_ctl_rgb12_reg.regValue);
	*/
}
#endif
#if 0
void drvif_module_ADC_SH_Gain_setting_Factory_mode(unsigned char value)
{
	unsigned char temp = value;	/* fix it jj!!*/
	/* fix it jj!!
		adc_dcrestore_ctrl_RBUS adc_dcrestore_ctrl_reg;	// 2_0018
		adc_dcrestore_ctrl_reg.regValue = rtdf_inl(ADC_ADC_DCRESTORE_CTRL_reg);

		switch(value)
		{
			case 0:
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_15_12 = 0x01;		// 2_0018: set SH gain[31:28] //av1
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_7_4 = 0x01;          // 2_0018: set SH gain[23:20] //av2
				break;
			case 1:
			case 2:
			case 3:
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_15_12 = 0x03;		// 2_0018: set SH gain[31:28]
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_7_4 = 0x03;          // 2_0018: set SH gain[23:20]
				break;
			case 4:
			case 5:
			case 6:
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_15_12 = 0x08;		// 2_0018: set SH gain[31:28]
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_7_4 = 0x08;          // 2_0018: set SH gain[23:20]
				break;
			case 7:
			case 8:
			case 9:
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_15_12 = 0xb;		// 2_0018: set SH gain[31:28]
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_7_4 = 0xb;          // 2_0018: set SH gain[23:20]
				break;
			default:
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_15_12 = 0x01;		// 2_0018: set SH gain[31:28] = 0001
				adc_dcrestore_ctrl_reg.adc_ctl_rgb_7_4 = 0x01;          // 2_0018: set SH gain[23:20]
				break;
		}
		rtdf_outl(ADC_ADC_DCRESTORE_CTRL_reg,adc_dcrestore_ctrl_reg.regValue);
	*/
}
#endif
void drvif_module_vdc_Set_clamp_delay_Enable_setting_Factory_mode(unsigned char value)
{
	if (value)
		module_vdc_Set_clamp_delay(_DISABLE, 0xb9);
	else
		module_vdc_Set_clamp_delay(_ENABLE, 0xb9);
}

void drvif_module_VDC_HBlank_Start_setting_Factory_mode(unsigned char value)
{
	if (value) {
		module_vdc_set_Hblank_start(0xE3);
	} else {
		module_vdc_set_Hblank_start(0xda);
	}
}

void drvif_module_VDC_HBlank_End_setting_Factory_mode(unsigned char value)
{
	vdtop_hblank_end_RBUS hblank_end_reg;
	hblank_end_reg.regValue = vdcf_inl(VDTOP_HBLANK_END_reg);

	if (value) {
		hblank_end_reg.hblank_end = 0x4f;
	} else {
		hblank_end_reg.hblank_end = 0x4e;
	}
	vdcf_outl(VDTOP_HBLANK_END_reg, hblank_end_reg.regValue);
}

unsigned char drvif_module_vdc_Noise_box_Delay_lsb_Factory_Get_info(void)
{
	vdtop_new_vdetect_ctrl_RBUS new_vdetect_ctrl_reg;
	new_vdetect_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_VDETECT_CTRL_reg);
	return new_vdetect_ctrl_reg.new_vdetect_en;
}

bool drvif_module_vdc_CheckFactoryModEnable(unsigned char enable)
{
	return vdc_factory_mod_enable == enable;
}

void drvif_module_vdc_SetFactoryModEnable(unsigned char enable)
{
	vdc_factory_mod_enable = enable;
}

