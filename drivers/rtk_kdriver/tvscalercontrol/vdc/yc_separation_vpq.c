
/* REGISTER FILES */
#include <rbus/vdpq_reg.h>
#include <rbus/vdtop_reg.h>
/* DRIVER HEADER FILES */
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/vdc/video_factory.h>
#include <tvscalercontrol/vdc/yc_separation_vpq.h>
#include <tvscalercontrol/vdc/yc_separation_vpq_table.h>
#include <vgip_isr/scalerVideo.h>
#define TAG_NAME "VPQ"

/* CONFIGURATION ************************************************************************/
#define FUNC_CHECK_2D_H2V_LK
#define DBUG_INTERFACE

/* GLOBAL PARAMETERS */
static unsigned char ucVdpqPrjId = 0;
static unsigned char ucYcSeparationStatus = VDC_YCSEPARATE_DEFAULT;
static unsigned char ucPreInputAVTV = INPUT_SRC_MAX;
#ifdef FUNC_CHECK_2D_H2V_LK
static unsigned char uc3DFailCounter = 0;
#define H2V_LOCK_COUNT	10
#endif
#ifdef DBUG_INTERFACE
static unsigned char ucDebugPreFormat = VDC_MODE_NO_SIGNAL;
static unsigned char ucDebugPreStatus = VDC_YCSEPARATE_DEFAULT;
static unsigned char ucDebugPreInputAVTV = INPUT_SRC_MAX;
static const unsigned char ucDebugPrint = _ENABLE;
#endif
unsigned int VPQ_3D_FrameMemStaAddr[4] = {0};
unsigned int VPQ_3D_FrameMemEndAddr[4] = {0};
unsigned char VPQ_2D_TableIndex = 0;
unsigned char VPQ_DCTI_TableIndex = 0;

/* FUNCTION IMPLMENT */
void drvif_module_vpq_YcSeparation(unsigned char ucInputSrc, unsigned char ucInputFormat, unsigned char uc3DEnable)
{
#ifdef DBUG_INTERFACE
	// dummy register 6(9ff4)
	// 4~0		: Debug1DCnt, how many times set to 1D status
	// 9~5		: Debug2DCnt, how many times set to 2D status
	// 14~10	: Debug3DCnt, how many times set to 3D status
	// 17~15	: DebugFormatCnt, how many times does the format change
	// 18		: ResetDebugCount, reset the debug record counter
	// 21~19	: Fix_VDPQTableSel, force to select a PQ table
	// 23~22	: DeubgCurrentStatus,
	// 24		: Fix_VDPQTableEnablem, force PQ table enable
	// 25		: VDPQ_AutoMA_bypass
	// 31~16	: Reserved
	vdpq_dummy_6_RBUS VDPQ_DUMMY_6_REG;
	VDPQ_DUMMY_6_REG.regValue = vdcf_inl(VDPQ_Dummy_6_reg);

	static unsigned char Debug1DCnt = 0;
	static unsigned char Debug2DCnt = 0;
	static unsigned char Debug3DCnt = 0;
	static unsigned char DebugFormatCnt = 0;
#endif

	unsigned char ucCurFormat = VDC_MODE_NO_SIGNAL;
	unsigned char ucCurStatus = VDC_YCSEPARATE_DEFAULT;

	unsigned char ucPreFormat = ((drvif_module_vpq_GetYcSep()&0xf0)>>4);
	unsigned char ucPreStatus = (drvif_module_vpq_GetYcSep()&0x0f);

	unsigned char ucCurInputAVTV = INPUT_SRC_AV;
	unsigned char uc1DCheckStatus = drvif_module_vdc_YC1D_Check();

	if(drvif_module_vdc_CheckFactoryModEnable(ON))
		return;

	// Current format
	if(!vdc_LockStatus)
		ucCurFormat = VDC_MODE_NO_SIGNAL;
	else
		ucCurFormat = ucInputFormat;

	// Current status
	if( uc1DCheckStatus != 0)
		ucCurStatus = VDC_YCSEPARATE_1D;
	else if( uc3DEnable == 0 )
		ucCurStatus = VDC_YCSEPARATE_2D;
	else
		ucCurStatus = VDC_YCSEPARATE_3D;

#ifdef DBUG_INTERFACE
	if( scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 24, 24, 0, VD_BIT_GET) )
	{
		ucCurFormat = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 19, 21, 0, VD_BIT_GET);
	}
#endif

	// Current source
	switch(ucInputSrc)
	{
		default:
		case _SRC_CVBS:
		case _SRC_SCART:
			ucCurInputAVTV = INPUT_SRC_AV;
		break;
		case _SRC_TV:
		case _SRC_SCART_RGB:
			ucCurInputAVTV = (drvif_module_vdc_read_Clamping_path() == 1)? INPUT_SRC_TV : INPUT_SRC_EXTV;
		break;
	}

	// Change VDPQ setting when the format or status change
	if( (ucCurFormat != ucPreFormat) || (ucCurStatus != ucPreStatus) || (ucCurInputAVTV != ucPreInputAVTV) )
	{
		if( ucCurStatus == VDC_YCSEPARATE_1D )
		{
			drvif_module_vpq_1DSet(ucCurInputAVTV, ucCurFormat);
		}
		else if( ucCurStatus == VDC_YCSEPARATE_2D )
		{
#ifdef FUNC_CHECK_2D_H2V_LK
			if((ucInputSrc == _SRC_TV) && (ucPreStatus == VDC_YCSEPARATE_3D) && (ucCurFormat == VDC_MODE_PALI))
			{
				// for toshiba TV channel : EU 7 3D fail bug
				if(drvif_module_vpq_get_f_num_3d_fail_det_bit())
				{
					module_vpq_clear_f_num_3d_fail_det_bit();
					uc3DFailCounter ++;
				}
				if(uc3DFailCounter > H2V_LOCK_COUNT)
				{
					module_vpq_h2v_lk_en(OFF);
					uc3DFailCounter = H2V_LOCK_COUNT;
				}
			}
#endif
		drvif_module_vpq_2DSet(ucCurInputAVTV, ucCurFormat);
		}
		else
		{
			drvif_module_vpq_3DSet(ucCurInputAVTV, ucCurFormat);
		}

		rtd_printk(KERN_DEBUG, TAG_NAME, "[%s] PQTable change, InputSrc = %d, YcStatus = %d, InputFormat = %d\n", ucCurInputAVTV, ucCurStatus, ucCurFormat);
		ucPreInputAVTV = ucCurInputAVTV;
	}

#ifdef DBUG_INTERFACE
	if( ucDebugPreStatus != ucCurStatus )
	{
		if( ucCurStatus == VDC_YCSEPARATE_1D )
			Debug1DCnt = (Debug1DCnt >= 32)? 0 : Debug1DCnt + 1;
		else if( ucCurStatus == VDC_YCSEPARATE_2D )
			Debug2DCnt = (Debug2DCnt >= 32)? 0 : Debug2DCnt + 1;
		else if( ucCurStatus == VDC_YCSEPARATE_3D )
			Debug3DCnt = (Debug3DCnt >= 32)? 0 : Debug3DCnt + 1;

		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue,  0,  4, Debug1DCnt, VD_BIT_SET);
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue,  5,  9, Debug2DCnt, VD_BIT_SET);
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 10, 14, Debug3DCnt, VD_BIT_SET);
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 22, 23, ucCurStatus, VD_BIT_SET);
		vdcf_outl(VDPQ_Dummy_6_reg, VDPQ_DUMMY_6_REG.regValue);
		if(ucDebugPrint == _ENABLE)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME, "[VDPQ_INTERFACE] Status change, CurStatus = %d, PreStatus =%d\n", ucCurStatus, ucDebugPreStatus);
		}
	}

	if( ucDebugPreFormat != ucCurFormat)
	{
		DebugFormatCnt = (DebugFormatCnt >= 32)? 0 : DebugFormatCnt + 1;
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 15, 17, DebugFormatCnt, VD_BIT_SET);
		vdcf_outl(VDPQ_Dummy_6_reg, VDPQ_DUMMY_6_REG.regValue);
		if(ucDebugPrint == _ENABLE)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME, "[VDPQ_INTERFACE] Format change, CurFormat = %d, PreFormat =%d \n", ucCurFormat, ucDebugPreFormat);
		}
	}

	if(scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 18, 18, 0, VD_BIT_GET))
	{
		//reset cnt to 0
		Debug1DCnt = 0;
		Debug2DCnt = 0;
		Debug3DCnt = 0;
		DebugFormatCnt = 0;
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue,  0,  4, 0, VD_BIT_SET);
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue,  5,  9, 0, VD_BIT_SET);
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 10, 14, 0, VD_BIT_SET);
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 15, 17, 0, VD_BIT_SET);
		VDPQ_DUMMY_6_REG.regValue = scalerVideo_BitWiseOperation(VDPQ_DUMMY_6_REG.regValue, 18, 18, 0, VD_BIT_SET);
		vdcf_outl(VDPQ_Dummy_6_reg, VDPQ_DUMMY_6_REG.regValue);
	}

	ucDebugPreFormat = ucCurFormat;
	ucDebugPreStatus = ucCurStatus;
	ucDebugPreInputAVTV = ucCurInputAVTV;
#endif

}

#if 0
// 1D_RELATED_FUNCTION
#endif

void drvif_module_vpq_1DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	/*
	ucInputSrc	: AV or TV
	ucFormat	: Video format
	*/

	module_vpq_disable_video_auto();
	module_vpq_IC_hardware_reset();

	module_vpq_VDTOP_1DSet(ucInputSrc, ucFormat);
	module_vpq_VDPQTable_1DSet(ucInputSrc, ucFormat);

	drvif_module_vpq_DmaAccessCtrl(OFF);
	module_vpq_format_change_bit_to_fw();
	module_vpq_enable_video_auto();
	drvif_module_vpq_SetYcSep((((ucFormat & 0x0f) << 4) | VDC_YCSEPARATE_1D));

}

void module_vpq_VDPQTable_1DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{

	// Parameter/array boundary protection
	ucFormat = module_vpq_Param_FormatRemapping(ucFormat);
	if( ucInputSrc >= INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucFormat >= FORMAT_MAX )
		ucFormat = FORMAT_PALI;

	module_vpq_digital_filter_set(YCSEP_STATUS_1D, ucInputSrc, ucFormat);
	module_vpq_1DTableWrite(VPQ_1D_TABLE_REMAPPING[ucInputSrc][ucFormat]);
	drvif_module_vpq_DCTI_Set(VPQ_CTI_TABLE_REMAPPING[VPQ_DCTI_1D][ucInputSrc][ucFormat]); // Should move to pq table?
	module_vpq_YCbCrDelay(_ENABLE, YCSEP_STATUS_1D, ucInputSrc, ucFormat);
}

void module_vpq_VDTOP_1DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	if( ucInputSrc > INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucFormat >= FORMAT_MAX )
		ucFormat = FORMAT_PALI;

	if(ucFormat == VDC_MODE_NO_SIGNAL)
		drvif_module_vdc_set_ColorMode(VDC_MODE_PALI);
	else
		drvif_module_vdc_set_ColorMode(ucFormat);

	module_vdc_Hactive_Start(VTOP_1D_HSYNC_START_TBL[ucInputSrc][ucFormat][0], VTOP_1D_HSYNC_START_TBL[ucInputSrc][ucFormat][1]);
}

void module_vpq_1DTableWrite(unsigned char ucTableSel)
{
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_1D_TBL);
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	switch(ucTableSel)
	{
		case TABLE1:
			module_vpq_TableWrite(VPQ_1D_SET1[ucPrjTblIdx]);
			break;
		case TABLE2:
			module_vpq_TableWrite(VPQ_1D_SET2[ucPrjTblIdx]);
			break;
		case TABLE3:
			module_vpq_TableWrite(VPQ_1D_SET3[ucPrjTblIdx]);
			break;
		case TABLE4:
			module_vpq_TableWrite(VPQ_1D_SET4[ucPrjTblIdx]);
			break;
		case TABLE5:
			module_vpq_TableWrite(VPQ_1D_SET5[ucPrjTblIdx]);
			break;
		case TABLE6:
			module_vpq_TableWrite(VPQ_1D_SET6[ucPrjTblIdx]);
			break;
		case TABLE7:
			module_vpq_TableWrite(VPQ_1D_SET7[ucPrjTblIdx]);
			break;
		case TABLE8:
			module_vpq_TableWrite(VPQ_1D_SET8[ucPrjTblIdx]);
			break;
		case TABLE9:
			module_vpq_TableWrite(VPQ_1D_SET9[ucPrjTblIdx]);
			break;
		default:
			break;
	}
	module_vpq_table_info_to_fw(VDC_YCSEPARATE_1D, ucTableSel);
}


#if 0
// 2D_RELATED_FUNCTION
#endif

void drvif_module_vpq_2DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	/*
	ucInputSrc	: AV or TV
	ucFormat	: Video format
	*/

	module_vpq_disable_video_auto();
	module_vpq_IC_hardware_reset();

	module_vpq_VDTOP_2DSet(ucInputSrc, ucFormat);
	module_vpq_VDPQTable_2DSet(ucInputSrc, ucFormat);

	module_vpq_format_change_bit_to_fw();
	module_vpq_enable_video_auto();
	drvif_module_vpq_SetYcSep((((ucFormat & 0x0f) << 4) | VDC_YCSEPARATE_2D));
}

void module_vpq_VDPQTable_2DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_2D_POSTP_ALPHA);

	// Parameter/array boundary protection
	ucFormat = module_vpq_Param_FormatRemapping(ucFormat);
	if( ucInputSrc >= INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucFormat >= FORMAT_MAX )
		ucFormat = FORMAT_PALI;
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	/*----- general setting -----*/
	drvif_module_vpq_DmaAccessCtrl(OFF);

	/*----- Picture quality setting -----*/
	module_vpq_digital_filter_set(YCSEP_STATUS_2D3D, ucInputSrc, ucFormat);
	module_vpq_2DTableWrite(VPQ_2D_TABLE_REMAPPING[ucInputSrc][ucFormat]);
	module_vpq_YCbCrDelay(_ENABLE, YCSEP_STATUS_2D3D, ucInputSrc, ucFormat);
	module_vpq_postp_alpha_weight_table_write(VPQ_2D_POSTP_ALPHAWEI_SET[ucPrjTblIdx][ucInputSrc][ucFormat]);

	/*----- special setting -----*/
	switch (ucFormat)
	{
		case FORMAT_NTSC:
		case FORMAT_PALI:
			module_vpq_DMA_cnt_inverse();
			break;
		default:
			break;
	}

}

void module_vpq_VDTOP_2DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	if( ucInputSrc > INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucFormat >= FORMAT_MAX )
		ucFormat = FORMAT_PALI;

	if(ucFormat == VDC_MODE_NO_SIGNAL)
		drvif_module_vdc_set_ColorMode(VDC_MODE_PALI);
	else
		drvif_module_vdc_set_ColorMode(ucFormat);

	module_vdc_Hactive_Start(VTOP_2D_HSYNC_START_TBL[ucInputSrc][ucFormat][0], VTOP_2D_HSYNC_START_TBL[ucInputSrc][ucFormat][1]);
}

void module_vpq_2DTableWrite(unsigned char ucTableSel)
{
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_2D_TBL);
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	VPQ_2D_TableIndex = ucTableSel;
	switch(ucTableSel)
	{
		case TABLE1: //new 2d table CVBS NTSC
			module_vpq_TableWrite(VPQ_2D_SET1[ucPrjTblIdx]);
			break;
		case TABLE2: //new 2d table CVBS PAL
			module_vpq_TableWrite(VPQ_2D_SET2[ucPrjTblIdx]);
			break;
		case TABLE3: //old 2d table
			module_vpq_TableWrite(VPQ_2D_SET3[ucPrjTblIdx]);
			break;
		case TABLE4: //old  2d table
			module_vpq_TableWrite(VPQ_2D_SET4[ucPrjTblIdx]);
			break;
		case TABLE5: //from new 2d table CVBS NTSC 443
			module_vpq_TableWrite(VPQ_2D_SET5[ucPrjTblIdx]);
			break;
		case TABLE6: //from new 2d table CVBS PAL M
			module_vpq_TableWrite(VPQ_2D_SET6[ucPrjTblIdx]);
			break;
		case TABLE7: //from new 2d table CVBS NTSC 50
			module_vpq_TableWrite(VPQ_2D_SET7[ucPrjTblIdx]);
			break;
		case TABLE8: //from new 2d table CVBS PAL N
			module_vpq_TableWrite(VPQ_2D_SET8[ucPrjTblIdx]);
			break;
		case TABLE9: //from new 2d table CVBS PAL 60
			module_vpq_TableWrite(VPQ_2D_SET9[ucPrjTblIdx]);
			break;
		case TABLE10: //from new 2d table TV NTSC
			module_vpq_TableWrite(VPQ_2D_SET10[ucPrjTblIdx]);
			break;
		case TABLE11: //from new 2d table TV PAL_M
			module_vpq_TableWrite(VPQ_2D_SET11[ucPrjTblIdx]);
			break;
		case TABLE12: //from new 2d table TV NTSC_50
			module_vpq_TableWrite(VPQ_2D_SET12[ucPrjTblIdx]);
			break;
		case TABLE13: //from new 2d table TV NTSC443
			module_vpq_TableWrite(VPQ_2D_SET13[ucPrjTblIdx]);
			break;
		case TABLE14: //from new 2d table TV PAL_60
			module_vpq_TableWrite(VPQ_2D_SET14[ucPrjTblIdx]);
			break;
		case TABLE15: //from new 2d table TV PAL
			module_vpq_TableWrite(VPQ_2D_SET15[ucPrjTblIdx]);
			break;
		case TABLE16: //from new 2d table TV SECAM
			module_vpq_TableWrite(VPQ_2D_SET16[ucPrjTblIdx]);
			break;
		default:
			break;
	}
	module_vpq_table_info_to_fw(VDC_YCSEPARATE_2D, ucTableSel);
}

#if 0
// 3D_RELATED_FUNCTION
#endif

void drvif_module_vpq_3DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	/*
	ucInputSrc	: AV or TV
	ucFormat	: Video format
	*/

	module_vpq_3D_MemCheck();
	module_vpq_disable_video_auto();
	module_vpq_IC_hardware_reset();

	module_vpq_VDTOP_3DSet(ucInputSrc, ucFormat);
	module_vpq_VDPQTable_3DSet(ucInputSrc, ucFormat);

	module_vpq_format_change_bit_to_fw();
	module_vpq_enable_video_auto();
	module_vpq_clear_f_num_3d_fail_det_bit();
	drvif_module_vpq_SetYcSep((((ucFormat & 0x0f) << 4) | VDC_YCSEPARATE_3D));
}

void module_vpq_VDPQTable_3DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_3D_POSTP_ALPHA);

	// Parameter/array boundary protection
	ucFormat = module_vpq_Param_FormatRemapping(ucFormat);
	if( ucInputSrc > INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucFormat >= FORMAT_MAX )
		ucFormat = FORMAT_PALI;
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	/*----- general setting -----*/
	drvif_module_vpq_DmaAccessCtrl(OFF);

	/*----- Picture quality setting -----*/
	module_vpq_digital_filter_set(YCSEP_STATUS_2D3D, ucInputSrc, ucFormat);
	module_vpq_3DDMATableWrite(VPQ_3D_TABLE_REMAPPING[ucInputSrc][ucFormat]);
	module_vpq_3DTableWrite(VPQ_3D_TABLE_REMAPPING[ucInputSrc][ucFormat]);
	module_vpq_YCbCrDelay(_ENABLE, YCSEP_STATUS_2D3D, ucInputSrc, ucFormat);
	module_vpq_postp_alpha_weight_table_write(VPQ_3D_POSTP_ALPHAWEI_SET[ucPrjTblIdx][ucInputSrc][ucFormat]);

	/*----- special setting -----*/
	switch(ucFormat)
	{
		case FORMAT_NTSC:
		case FORMAT_PALI:
			module_vpq_DMA_cnt_inverse();
			break;
		default:
			break;
	}

}

void module_vpq_VDTOP_3DSet(unsigned char ucInputSrc, unsigned char ucFormat)
{
	if( ucInputSrc > INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucFormat >= FORMAT_MAX )
		ucFormat = FORMAT_PALI;

	if(ucFormat == VDC_MODE_NO_SIGNAL)
		drvif_module_vdc_set_ColorMode(VDC_MODE_PALI);
	else
		drvif_module_vdc_set_ColorMode(ucFormat);

	module_vdc_Hactive_Start(VTOP_3D_HSYNC_START_TBL[ucInputSrc][ucFormat][0], VTOP_3D_HSYNC_START_TBL[ucInputSrc][ucFormat][1]);
}

void module_vpq_3DTableWrite(unsigned char ucTableSel)
{
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_3D_TBL);
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	switch(ucTableSel)
	{
		case TABLE1:
			module_vpq_TableWrite(VPQ_3D_SET1[ucPrjTblIdx]);
			break;
		case TABLE2:
			module_vpq_TableWrite(VPQ_3D_SET2[ucPrjTblIdx]);
			break;
		case TABLE3:
			module_vpq_TableWrite(VPQ_3D_SET3[ucPrjTblIdx]);
			break;
		case TABLE4:
			module_vpq_TableWrite(VPQ_3D_SET4[ucPrjTblIdx]);
			break;
		case TABLE5:
			module_vpq_TableWrite(VPQ_3D_SET5[ucPrjTblIdx]);
			break;
		case TABLE6:
			module_vpq_TableWrite(VPQ_3D_SET6[ucPrjTblIdx]);
			break;
		case TABLE7:
			module_vpq_TableWrite(VPQ_3D_SET7[ucPrjTblIdx]);
			break;
		case TABLE8:
			module_vpq_TableWrite(VPQ_3D_SET8[ucPrjTblIdx]);
			break;
		case TABLE9:
			module_vpq_TableWrite(VPQ_3D_SET9[ucPrjTblIdx]);
			break;
		case TABLE10:
			module_vpq_TableWrite(VPQ_3D_SET10[ucPrjTblIdx]);
			break;
		case TABLE11:
			module_vpq_TableWrite(VPQ_3D_SET11[ucPrjTblIdx]);
			break;
		case TABLE12:
			module_vpq_TableWrite(VPQ_3D_SET12[ucPrjTblIdx]);
			break;
		case TABLE13:
			module_vpq_TableWrite(VPQ_3D_SET13[ucPrjTblIdx]);
			break;
		case TABLE14:
			module_vpq_TableWrite(VPQ_3D_SET14[ucPrjTblIdx]);
			break;
		case TABLE15:
			module_vpq_TableWrite(VPQ_3D_SET15[ucPrjTblIdx]);
			break;
		case TABLE16:
			module_vpq_TableWrite(VPQ_3D_SET16[ucPrjTblIdx]);
			break;
		default:
			break;
	}
    module_vpq_table_info_to_fw(VDC_YCSEPARATE_3D, ucTableSel);
}

void module_vpq_3DDMATableWrite(unsigned char ucTableSel)
{
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_3DDMA_TBL);
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	switch(ucTableSel)
	{
		case TABLE1:
			module_vpq_TableWrite(VPQ_3DDMA_SET1[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
			break;
		case TABLE2:
			module_vpq_TableWrite(VPQ_3DDMA_SET2[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
			break;
		case TABLE3:
			module_vpq_TableWrite(VPQ_3DDMA_SET3[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
			break;
		case TABLE4:
			module_vpq_TableWrite(VPQ_3DDMA_SET4[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
			break;
		case TABLE5:
			module_vpq_TableWrite(VPQ_3DDMA_SET5[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
			break;
		case TABLE6:
			module_vpq_TableWrite(VPQ_3DDMA_SET6[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
			break;
		case TABLE7:
			module_vpq_TableWrite(VPQ_3DDMA_SET7[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
			break;
		case TABLE8:
			module_vpq_TableWrite(VPQ_3DDMA_SET8[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
			break;
		case TABLE9:
			module_vpq_TableWrite(VPQ_3DDMA_SET9[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
			break;
        case TABLE10:
            module_vpq_TableWrite(VPQ_3DDMA_SET10[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
            break;
        case TABLE11:
            module_vpq_TableWrite(VPQ_3DDMA_SET11[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
            break;
        case TABLE12:
            module_vpq_TableWrite(VPQ_3DDMA_SET12[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
            break;
        case TABLE13:
            module_vpq_TableWrite(VPQ_3DDMA_SET13[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
            break;
        case TABLE14:
            module_vpq_TableWrite(VPQ_3DDMA_SET14[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
            break;
        case TABLE15:
            module_vpq_TableWrite(VPQ_3DDMA_SET15[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(OFF);
            break;
        case TABLE16:
            module_vpq_TableWrite(VPQ_3DDMA_SET16[ucPrjTblIdx]);
			drvif_module_vpq_DmaAccessCtrl(ON);
            break;
        default:
            break;
	}
}

#if 0
// MOUDLE LOCAL FUNCTION
#endif
unsigned char module_vpq_Get_TableIdxByPrjID(unsigned char ItemSel)
{
	unsigned char ucTblIdx = PRJ_NO_0;

	if( ItemSel >= PRJ_TBL_ITEM_MAX )
		ucTblIdx = PRJ_NO_0;
	else
		ucTblIdx = VPQ_PRJ_TABLE_SEL[ucVdpqPrjId][ItemSel];

	return ucTblIdx;
}

unsigned char module_vpq_Param_FormatRemapping(unsigned char ucFormat)
{
	/* To remap parameter from VDC definition to VPQ definition */
	unsigned char ucRemapFormat = FORMAT_PALI;
	switch(ucFormat)
	{
		case VDC_MODE_NTSC:
			ucRemapFormat = FORMAT_NTSC;
			break;
		case VDC_MODE_PALM:
			ucRemapFormat = FORMAT_PALM;
			break;
		case VDC_MODE_NTSC50:
			ucRemapFormat = FORMAT_NTSC50;
			break;
		case VDC_MODE_PALN:
			ucRemapFormat = FORMAT_PALN;
			break;
		case VDC_MODE_NTSC443:
			ucRemapFormat = FORMAT_NTSC443;
			break;
		case VDC_MODE_PAL60:
			ucRemapFormat = FORMAT_PAL60;
			break;
		case VDC_MODE_PALI:
			ucRemapFormat = FORMAT_PALI;
			break;
		case VDC_MODE_SECAM:
			ucRemapFormat = FORMAT_SECAM;
			break;
		case VDC_MODE_AUTO:
		case VDC_MODE_ERROR:
		case VDC_MODE_CLEAN:
		case VDC_MODE_NO_SIGNAL:
		default:
			ucRemapFormat = FORMAT_PALI;
			break;
	}
	return ucRemapFormat;
}

unsigned char module_vpq_Param_YcSepStatusRemapping(unsigned char ucYcSepStatus)
{
	/* To remap parameter from VDC definition to VPQ definition */
	unsigned char ucRemapYcSepStatus = YCSEP_STATUS_2D3D;

	switch(ucYcSepStatus)
	{
		default:
		case VDC_YCSEPARATE_DEFAULT:
		case VDC_YCSEPARATE_2D:
		case VDC_YCSEPARATE_3D:
			ucRemapYcSepStatus = YCSEP_STATUS_2D3D;
			break;
		case VDC_YCSEPARATE_1D:
			ucRemapYcSepStatus = YCSEP_STATUS_1D;
			break;
	}

	return ucRemapYcSepStatus;
}

void module_vpq_3D_MemCheck(void)
{
	// check the memory setting
	vdpq_mem0_addr_ini_RBUS mem0_addr_ini_reg;
	vdpq_mem1_addr_ini_RBUS mem1_addr_ini_reg;
	vdpq_mem2_addr_ini_RBUS mem2_addr_ini_reg;
	vdpq_mem3_addr_ini_RBUS mem3_addr_ini_reg;
	vdpq_mem0_addr_end_RBUS mem0_addr_end_reg;
	vdpq_mem1_addr_end_RBUS mem1_addr_end_reg;
	vdpq_mem2_addr_end_RBUS mem2_addr_end_reg;
	vdpq_mem3_addr_end_RBUS mem3_addr_end_reg;

	mem0_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_INI_reg);
	mem1_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM1_ADDR_INI_reg);
	mem2_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM2_ADDR_INI_reg);
	mem3_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_INI_reg);
	mem0_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_END_reg);
	mem1_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM1_ADDR_END_reg);
	mem2_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM2_ADDR_END_reg);
	mem3_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_END_reg);

	if( mem0_addr_ini_reg.frame_addr0 != VPQ_3D_FrameMemStaAddr[0] || mem1_addr_ini_reg.frame_addr1 != VPQ_3D_FrameMemStaAddr[1] ||
	    mem2_addr_ini_reg.frame_addr2 != VPQ_3D_FrameMemStaAddr[2] || mem3_addr_ini_reg.frame_addr3 != VPQ_3D_FrameMemStaAddr[3] ||
	    mem0_addr_end_reg.frame_addr0_end != VPQ_3D_FrameMemEndAddr[0] || mem1_addr_end_reg.frame_addr1_end != VPQ_3D_FrameMemEndAddr[1] ||
	    mem2_addr_end_reg.frame_addr2_end != VPQ_3D_FrameMemEndAddr[2] || mem3_addr_end_reg.frame_addr3_end != VPQ_3D_FrameMemEndAddr[3] ||
	    ((mem0_addr_end_reg.frame_addr0_end - mem0_addr_ini_reg.frame_addr0) != (_SDRAM_3D_ONE_FRAME_USE-1) ) ||
	    ((mem1_addr_end_reg.frame_addr1_end - mem1_addr_ini_reg.frame_addr1) != (_SDRAM_3D_ONE_FRAME_USE-1) ) ||
	    ((mem2_addr_end_reg.frame_addr2_end - mem2_addr_ini_reg.frame_addr2) != (_SDRAM_3D_ONE_FRAME_USE-1) ) ||
	    ((mem3_addr_end_reg.frame_addr3_end - mem3_addr_ini_reg.frame_addr3) != (_SDRAM_3D_ONE_FRAME_USE-1) )
	    )
	{
		rtd_printk(KERN_ERR, TAG_NAME, "VDPQ Memory Check Error\n");
		int i=0;
		for(i=0; i<4; i++)
		{
			rtd_printk(KERN_ERR, TAG_NAME, "Frame %d Sta = %x, End = %x, Offset = %x\n",
				i, VPQ_3D_FrameMemStaAddr[i], VPQ_3D_FrameMemEndAddr[i], VPQ_3D_FrameMemEndAddr[i]-VPQ_3D_FrameMemStaAddr[i]);
		}
	}
}

void module_vpq_postp_alpha_weight_table_write(unsigned char *table)
{
	vdpq_postp_3d2dalpha_blend_ctrl_1_RBUS POSTP_3D2DALPHA_BLEND_CTRL_1;
	vdpq_postp_3d2dalpha_blend_ctrl_2_RBUS POSTP_3D2DALPHA_BLEND_CTRL_2;


	//vdpq_postp_3d2dalpha_blend_ctrl_1_RBUS POSTP_3D2DALPHA_BLEND_CTRL_1;
	POSTP_3D2DALPHA_BLEND_CTRL_1.regValue = vdcf_inl(VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg);

	POSTP_3D2DALPHA_BLEND_CTRL_1.xnr_alpha_2d_weight = table[0];
	POSTP_3D2DALPHA_BLEND_CTRL_1.xnr_alpha_bld_weight = table[1];
	POSTP_3D2DALPHA_BLEND_CTRL_1.xnr_alpha_3d_weight = table[2];

	POSTP_3D2DALPHA_BLEND_CTRL_1.dlti_alpha_2d_weight = table[6];
	POSTP_3D2DALPHA_BLEND_CTRL_1.dlti_alpha_bld_weight = table[7];
	POSTP_3D2DALPHA_BLEND_CTRL_1.dlti_alpha_3d_weight = table[8];

	POSTP_3D2DALPHA_BLEND_CTRL_1.pk_alpha_2d_weight = table[9];
	POSTP_3D2DALPHA_BLEND_CTRL_1.pk_alpha_bld_weight = table[10];
	POSTP_3D2DALPHA_BLEND_CTRL_1.pk_alpha_3d_weight = table[11];

	vdcf_outl(VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg, POSTP_3D2DALPHA_BLEND_CTRL_1.regValue);


	POSTP_3D2DALPHA_BLEND_CTRL_2.regValue = vdcf_inl(VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg);

	POSTP_3D2DALPHA_BLEND_CTRL_2.snr_alpha_2d_weight = table[12];
	POSTP_3D2DALPHA_BLEND_CTRL_2.snr_alpha_bld_weight = table[13];
	POSTP_3D2DALPHA_BLEND_CTRL_2.snr_alpha_3d_weight = table[14];

	POSTP_3D2DALPHA_BLEND_CTRL_2.alphablend_round_en = table[15];

	POSTP_3D2DALPHA_BLEND_CTRL_2.notch_force_upbnd = table[16];
	POSTP_3D2DALPHA_BLEND_CTRL_2.notch_force_3dweight = table[17];
	POSTP_3D2DALPHA_BLEND_CTRL_2.mfnotch_alpha_2d_weight = table[18];

	vdcf_outl(VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg, POSTP_3D2DALPHA_BLEND_CTRL_2.regValue);
}

void module_vpq_TableWrite(unsigned int *pArray)
{
	unsigned int Addr_Index=0, Reg_data=0;
	do
	{
		if (pArray[0] == _TBL_END)
			return;

		Addr_Index = pArray[0];
		Reg_data = pArray[1];
		vdcf_outl(Addr_Index,Reg_data);
		pArray += 2; // go to next line
	}
	while (1);
}

void module_vpq_Y_EQ_Filter(unsigned char ucInputSrc, unsigned char unInputFormat)
{
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_Y_EQ_FILTER);
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	if( ucInputSrc == INPUT_SRC_TV ) // ATV
	{
		switch(unInputFormat)
		{
			case FORMAT_NTSC:
				module_vpq_Y_EQ_Filter_Write(VPQ_Y_EQ_FILTER[ucPrjTblIdx][1]);
				break;
			default:
				module_vpq_Y_EQ_Filter_Write(VPQ_Y_EQ_FILTER[ucPrjTblIdx][0]);
				break;
		}
	}
	else
	{
		module_vpq_Y_EQ_Filter_Write(VPQ_Y_EQ_FILTER[ucPrjTblIdx][0]);
	}
}

void module_vpq_Y_EQ_Filter_Write(unsigned int* ptr)
{
	// Write the Filter coefficient
	unsigned int i = 0;
	vdtop_y_path_eq_filter_RBUS vdtop_y_path_eq_filter_reg;
	vdtop_y_path_eq_filter_reg.regValue = vdcf_inl(VDTOP_Y_PATH_EQ_FILTER_reg);

	for(i=0; i<=40; i++)
	{
		vdtop_y_path_eq_filter_reg.y_path_eq_en = 1;
		vdtop_y_path_eq_filter_reg.y_path_coef_num = i;
		vdtop_y_path_eq_filter_reg.y_path_coef_value = ptr[i];
		vdcf_outl(VDTOP_Y_PATH_EQ_FILTER_reg, vdtop_y_path_eq_filter_reg.regValue);
	}

	// Adjust the H sync start position
	// Delay for enable the y eq filter
	/*
	vdtop_hsync_pulse_start_RBUS vdtop_hsync_pulse_start_reg;
	vdtop_hsync_pulse_start_reg.regValue = vdcf_inl(VDTOP_HSYNC_PULSE_START_reg);
	vdtop_hsync_pulse_start_reg.hsync_start = 32;
	vdcf_outl(VDTOP_HSYNC_PULSE_START_reg, vdtop_hsync_pulse_start_reg.regValue);
	*/

}

void module_vpq_27M_FrontDigitalFilterEnable(unsigned char ucMode)
{
	ucMode = (ucMode > 7)? 7: ucMode;

	/* 934c[3:1] */
	vdtop_sync_midpt_v2_RBUS sync_midpt_v2_reg;
	sync_midpt_v2_reg.regValue = vdcf_inl(VDTOP_SYNC_MIDPT_V2_reg);
	if (sync_midpt_v2_reg.adc_lpf_sel != ucMode)
	{
		sync_midpt_v2_reg.adc_lpf_sel = ucMode;
		vdcf_outl(VDTOP_SYNC_MIDPT_V2_reg, sync_midpt_v2_reg.regValue);
	}
}

void module_vpq_cresample_lpf_sel(unsigned char ucMode)
{
	ucMode = (ucMode > 3)? 3: ucMode;

	/* 9410[5:4] */
	vdtop_chroma_loopfilter_state_RBUS chroma_loopfilter_state_reg;
	chroma_loopfilter_state_reg.regValue = vdcf_inl(VDTOP_CHROMA_LOOPFILTER_STATE_reg);
	if( chroma_loopfilter_state_reg.cresample_lpf_sel != ucMode )
	{
		chroma_loopfilter_state_reg.cresample_lpf_sel = ucMode;
		vdcf_outl(VDTOP_CHROMA_LOOPFILTER_STATE_reg, chroma_loopfilter_state_reg.regValue);
	}
}

void module_vpq_disable_video_auto(void)
{
	int RegValue = vdcf_inl(VDPQ_Dummy_8_reg);
	RegValue = ( RegValue | (_BIT14) );
	vdcf_outl(VDPQ_Dummy_8_reg, RegValue);
}

void module_vpq_enable_video_auto(void)
{
	int RegValue = vdcf_inl(VDPQ_Dummy_8_reg);
	RegValue = ( RegValue & (~(_BIT14)) );
	vdcf_outl(VDPQ_Dummy_8_reg, RegValue);
}

void module_vpq_table_info_to_fw(unsigned char ucFormat, unsigned char ucTBL)
{
	// 20151110, willy, Record the table number to Dummy register 7
	vdpq_dummy_7_RBUS vdpq_dummy_7_reg;
	vdpq_dummy_7_reg.regValue = vdcf_inl(VDPQ_Dummy_7_reg);
	vdpq_dummy_7_reg.regValue = scalerVideo_BitWiseOperation(vdpq_dummy_7_reg.regValue, 24, 25, ucFormat, VD_BIT_SET);
	vdpq_dummy_7_reg.regValue = scalerVideo_BitWiseOperation(vdpq_dummy_7_reg.regValue, 26, 31, ucTBL+1, VD_BIT_SET);
	vdpq_dummy_7_reg.regValue = scalerVideo_BitWiseOperation(vdpq_dummy_7_reg.regValue, 20, 22, ucVdpqPrjId, VD_BIT_SET);
	vdcf_outl(VDPQ_Dummy_7_reg, vdpq_dummy_7_reg.regValue);
}

void module_vpq_format_change_bit_to_fw(void)
{
  // 20151001, willy, handshake with video FW to save VD register initial value
  vdpq_dummy_8_RBUS VDPQ_DUMMY_8_REG;
  VDPQ_DUMMY_8_REG.regValue = vdcf_inl(VDPQ_Dummy_8_reg);
  VDPQ_DUMMY_8_REG.regValue = ((VDPQ_DUMMY_8_REG.regValue) | (0x00200000));
  vdcf_outl(VDPQ_Dummy_8_reg, VDPQ_DUMMY_8_REG.regValue);
}

void module_vpq_clear_f_num_3d_fail_det_bit(void)
{
	vdpq_frame_buf_chk3d_ctrl1_RBUS frame_buf_chk3d_ctrl1_reg;
	frame_buf_chk3d_ctrl1_reg.regValue = vdcf_inl(VDPQ_FRAME_BUF_CHK3D_CTRL1_reg);
	frame_buf_chk3d_ctrl1_reg.f_num_3d_fail_det = 1;
	vdcf_outl(VDPQ_FRAME_BUF_CHK3D_CTRL1_reg,frame_buf_chk3d_ctrl1_reg.regValue);
}

void module_vpq_h2v_lk_en(unsigned char on_off)
{
	vdpq_adap_bpf_c_th1_RBUS adap_bpf_c_th1_reg;
	adap_bpf_c_th1_reg.regValue = vdcf_inl(VDPQ_ADAP_BPF_C_TH1_reg);
	adap_bpf_c_th1_reg.h2v_lk_en = on_off;
	vdcf_outl(VDPQ_ADAP_BPF_C_TH1_reg,adap_bpf_c_th1_reg.regValue);
}


void module_vpq_digital_filter_set(unsigned char ucInYcSep, unsigned char ucInputSrc, unsigned char ucInputFormat)
{

	/* PARAMETERS */
	unsigned char FrontDigitalFilter_108M = 0;
	unsigned char FrontDigitalFilter_108M_oversamp = 0;
	unsigned char FrontDigitalFilter_27M = 0;
	unsigned char FrontDigitalFilter_27M_oversamp = 0;
	unsigned char cresample_lpf_sel = 0;
	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_DIGITAL_FILTER);

	// Parameter/array boundary protection
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;
	if( ucInYcSep >= YCSEP_STATUS_MAX )
		ucInYcSep = YCSEP_STATUS_2D3D;
	if( ucInputSrc >= INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucInputFormat >= FORMAT_MAX )
		ucInputFormat = FORMAT_PALI;

	FrontDigitalFilter_108M          = VPQ_FRONT_DIGITAL_FILTER[ucPrjTblIdx][ucInYcSep][ucInputFormat][ucInputSrc][0];
	FrontDigitalFilter_108M_oversamp = VPQ_FRONT_DIGITAL_FILTER[ucPrjTblIdx][ucInYcSep][ucInputFormat][ucInputSrc][1];
	FrontDigitalFilter_27M           = VPQ_FRONT_DIGITAL_FILTER[ucPrjTblIdx][ucInYcSep][ucInputFormat][ucInputSrc][2];
	FrontDigitalFilter_27M_oversamp  = VPQ_FRONT_DIGITAL_FILTER[ucPrjTblIdx][ucInYcSep][ucInputFormat][ucInputSrc][3];
	cresample_lpf_sel                = VPQ_FRONT_DIGITAL_FILTER[ucPrjTblIdx][ucInYcSep][ucInputFormat][ucInputSrc][4];

	/****************** WRITE TO REGISTERS ******************/

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
	module_vpq_27M_FrontDigitalFilterEnable(FrontDigitalFilter_27M_oversamp);
#else
	module_vpq_27M_FrontDigitalFilterEnable(FrontDigitalFilter_27M);
#endif
	module_vpq_cresample_lpf_sel(cresample_lpf_sel);

}


void module_vpq_YCbCrDelay(unsigned char ucEnable, unsigned char ucInYcSep, unsigned char ucInputSrc, unsigned char ucInputFormat)
{
	vdtop_output_control_RBUS vdtop_output_control_reg;
	vdtop_chroma_delay_ctrl_RBUS vdtop_chroma_delay_ctrl_reg;
	vdtop_auto_pos_ctrl_RBUS vdtop_auto_pos_ctrl_reg;
	vdtop_auto_pos_ctrl_2_RBUS vdtop_auto_pos_ctrl_2_reg;
	vdpq_yc_sep_yuv_delay_RBUS vdpq_yc_sep_yuv_delay_reg;

	unsigned char ucYDelay = 0, ucCbDelay = 0, ucCrDelay = 0;
	unsigned char ucNewYDelay = 0, ucNewCbDelay = 0, ucNewCrDelay = 0, ucNewCKYDelay = 0;
	unsigned char uc4fscYDelay = 0, uc4fscCbDelay = 0, uc4fscCrDelay = 0;

	unsigned char ucPrjTblIdx = module_vpq_Get_TableIdxByPrjID(PRJ_TBL_IDX_DEALY);

	// Parameter/array boundary protection
	if( ucInYcSep >= YCSEP_STATUS_MAX )
		ucInYcSep = YCSEP_STATUS_2D3D;
	if( ucInputSrc >= INPUT_SRC_MAX )
		ucInputSrc = INPUT_SRC_AV;
	if( ucInputFormat >= FORMAT_MAX )
		ucInputFormat = FORMAT_PALI;
	if( ucPrjTblIdx >= PRJ_NUM_MAX )
		ucPrjTblIdx = PRJ_NO_0;

	// -----------------------------------------------------------------------------------------------------
	// Old YC delay ----------------------------------------------------------------------------------------
	ucYDelay  = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_Y];
	ucCbDelay = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_CB];
	ucCrDelay = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_CR];

	vdtop_output_control_reg.regValue = vdcf_inl(VDTOP_OUTPUT_CONTROL_reg);
	vdtop_chroma_delay_ctrl_reg.regValue = vdcf_inl(VDTOP_CHROMA_DELAY_CTRL_reg);

	if(vdtop_output_control_reg.yc_delay != ucYDelay)
	{
		vdtop_output_control_reg.yc_delay = ucYDelay;
		vdcf_outl(VDTOP_OUTPUT_CONTROL_reg, vdtop_output_control_reg.regValue);
	}

	if( (vdtop_chroma_delay_ctrl_reg.cb_delay != ucCbDelay) || (vdtop_chroma_delay_ctrl_reg.cr_delay != ucCrDelay) )
	{
		vdtop_chroma_delay_ctrl_reg.cb_delay = ucCbDelay;
		vdtop_chroma_delay_ctrl_reg.cr_delay = ucCrDelay;
		vdcf_outl(VDTOP_CHROMA_DELAY_CTRL_reg, vdtop_chroma_delay_ctrl_reg.regValue);
	}
	// -----------------------------------------------------------------------------------------------------

	// -----------------------------------------------------------------------------------------------------
	// New YC delay ----------------------------------------------------------------------------------------
	ucNewYDelay   = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_NEW_Y];
	ucNewCbDelay  = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_NEW_CB];
	ucNewCrDelay  = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_NEW_CR];
	ucNewCKYDelay = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_NEW_CKY];

	vdtop_auto_pos_ctrl_reg.regValue = vdcf_inl(VDTOP_AUTO_POS_CTRL_reg);
	vdtop_auto_pos_ctrl_2_reg.regValue = vdcf_inl(VDTOP_AUTO_POS_CTRL_2_reg);

	vdtop_auto_pos_ctrl_reg.y1delayreg_en   = ucEnable;
	vdtop_auto_pos_ctrl_reg.cb1delayreg_en  = ucEnable;
	vdtop_auto_pos_ctrl_reg.cr1delayreg_en  = ucEnable;
	vdtop_auto_pos_ctrl_reg.new_y1delay_en  = ucEnable;
	vdtop_auto_pos_ctrl_reg.new_cb1delay_en = ucEnable;
	vdtop_auto_pos_ctrl_reg.new_cr1delay_en = ucEnable;
	vdtop_auto_pos_ctrl_reg.y1delay  = ucNewYDelay;
	vdtop_auto_pos_ctrl_reg.cb1delay = ucNewCbDelay;
	vdtop_auto_pos_ctrl_reg.cr1delay = ucNewCrDelay;

	vdtop_auto_pos_ctrl_2_reg.ckill_y1delayreg_en  = 1;
	vdtop_auto_pos_ctrl_2_reg.ckill_cb1delayreg_en = 1;
	vdtop_auto_pos_ctrl_2_reg.ckill_cr1delayreg_en = 1;
	vdtop_auto_pos_ctrl_2_reg.ckill_y1delay = ucNewCKYDelay;

	vdcf_outl(VDTOP_AUTO_POS_CTRL_reg, vdtop_auto_pos_ctrl_reg.regValue);
	vdcf_outl(VDTOP_AUTO_POS_CTRL_2_reg, vdtop_auto_pos_ctrl_2_reg.regValue);
	// -----------------------------------------------------------------------------------------------------

	// -----------------------------------------------------------------------------------------------------
	// 4fsc YC delay ---------------------------------------------------------------------------------------
	uc4fscYDelay =  VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_4FSC_Y];
	uc4fscCbDelay = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_4FSC_CB];
	uc4fscCrDelay = VPQ_YCBCR_DELAY_TABLE[ucPrjTblIdx][ucInYcSep][ucInputSrc][ucInputFormat][YCDELAY_4FSC_CR];

	vdpq_yc_sep_yuv_delay_reg.regValue = vdcf_inl(VDPQ_YC_SEP_YUV_DELAY_reg);
	vdpq_yc_sep_yuv_delay_reg.y_delay_4fsc = uc4fscYDelay;
	vdpq_yc_sep_yuv_delay_reg.cb_delay_4fsc = uc4fscCbDelay;
	vdpq_yc_sep_yuv_delay_reg.cr_delay_4fsc = uc4fscCrDelay;
	vdcf_outl(VDPQ_YC_SEP_YUV_DELAY_reg, vdpq_yc_sep_yuv_delay_reg.regValue);
	// -----------------------------------------------------------------------------------------------------

}



void module_vpq_DCTI_Table_write(unsigned char *table)
{
	vdpq_cadap_enable_ctrl_RBUS cadap_enable_ctrl_reg;
	vdpq_cadap_gain_ctrl_RBUS cadap_gain_ctrl_reg;
	vdpq_cadap_zc_th_RBUS cadap_zc_th_reg;
	vdpq_cadap_zc_th2_RBUS cadap_zc_th2_reg;
	vdpq_cadap_ver_uniformity_th_RBUS cadap_ver_uniformity_th_reg;
	vdpq_cadap_sync_uniformity_th_RBUS adap_sync_uniformity_th_reg;
	vdpq_cadap_lut_level_th_RBUS cadap_lut_level_th_reg;
	vdpq_cadap_lut_gain_th_RBUS cadap_lut_gain_th_reg;


	// 9f0c ~ 9f2c
	//vdpq_cadap_enable_ctrl_RBUS cadap_enable_ctrl_reg;
	cadap_enable_ctrl_reg.regValue = vdcf_inl(VDPQ_CADAP_ENABLE_CTRL_reg);
	cadap_enable_ctrl_reg.cadap_cti_en = table[0];		// 9f0c[0]
	cadap_enable_ctrl_reg.cadap_yuvsync_en = table[1];	// 9f0c[1]
	cadap_enable_ctrl_reg.cadap_uvsync_en = table[2];	// 9f0c[2]
	cadap_enable_ctrl_reg.cadap_spatial_lpf_out = table[3];	// 9f0c[5]
	vdcf_outl(VDPQ_CADAP_ENABLE_CTRL_reg, cadap_enable_ctrl_reg.regValue);

	//vdpq_cadap_gain_ctrl_RBUS cadap_gain_ctrl_reg;
	cadap_gain_ctrl_reg.regValue = vdcf_inl(VDPQ_CADAP_GAIN_CTRL_reg);
	cadap_gain_ctrl_reg.cadap_level = table[4];	//9f14[3:0]
	cadap_gain_ctrl_reg.cadap_gain = table[5];	//9f14[7:4]
	vdcf_outl(VDPQ_CADAP_GAIN_CTRL_reg, cadap_gain_ctrl_reg.regValue);

	//vdpq_cadap_zc_th_RBUS cadap_zc_th_reg;
	cadap_zc_th_reg.regValue = vdcf_inl(VDPQ_CADAP_ZC_TH_reg);
	cadap_zc_th_reg.cadap_zc_mag_th_y_c = table[6];	//9f18[3:0]
	cadap_zc_th_reg.cadap_zc_mag_th_y = table[7];	//9f18[7:4]
	vdcf_outl(VDPQ_CADAP_ZC_TH_reg, cadap_zc_th_reg.regValue);

	//vdpq_cadap_zc_th2_RBUS cadap_zc_th2_reg;
	cadap_zc_th2_reg.regValue = vdcf_inl(VDPQ_CADAP_ZC_TH2_reg);
	cadap_zc_th2_reg.cadap_dir_det_gain = table[8];	//9f1c[3:0]
	cadap_zc_th2_reg.cadap_zc_mag_th_c = table[9];	//9f1c[7:6]
	vdcf_outl(VDPQ_CADAP_ZC_TH2_reg, cadap_zc_th2_reg.regValue);

	//vdpq_cadap_ver_uniformity_th_RBUS cadap_ver_uniformity_th_reg;
	cadap_ver_uniformity_th_reg.regValue = vdcf_inl(VDPQ_CADAP_VER_UNIFORMITY_TH_reg);
	cadap_ver_uniformity_th_reg.cadap_dir_uni_th = table[10];	//9f20[3:0]
	cadap_ver_uniformity_th_reg.cadap_ver_uni_th = table[11];	//9f20[7:6]
	vdcf_outl(VDPQ_CADAP_VER_UNIFORMITY_TH_reg, cadap_ver_uniformity_th_reg.regValue);

	//vdpq_cadap_sync_uniformity_th_RBUS adap_sync_uniformity_th_reg;
	adap_sync_uniformity_th_reg.regValue = vdcf_inl(VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg);
	adap_sync_uniformity_th_reg.cadap_uv_sync_uni_th= table[12];	//9f24[3:0]
	adap_sync_uniformity_th_reg.cadap_y_sync_uni_th= table[13];	//9f24[7:6]
	vdcf_outl(VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg, adap_sync_uniformity_th_reg.regValue);

	//vdpq_cadap_lut_level_th_RBUS cadap_lut_level_th_reg;
	cadap_lut_level_th_reg.regValue = vdcf_inl(VDPQ_CADAP_LUT_LEVEL_TH_reg);
	cadap_lut_level_th_reg.cadap_lut_level_thb= table[14];	//9f28[3:0]
	cadap_lut_level_th_reg.cadap_lut_level_tha= table[15];	//9f28[7:6]
	vdcf_outl(VDPQ_CADAP_LUT_LEVEL_TH_reg, cadap_lut_level_th_reg.regValue);

	//vdpq_cadap_lut_gain_th_RBUS cadap_lut_gain_th_reg;
	cadap_lut_gain_th_reg.regValue = vdcf_inl(VDPQ_CADAP_LUT_GAIN_TH_reg);
	cadap_lut_gain_th_reg.cadap_lut_gain_thb= table[16];	//9f2c[3:0]
	cadap_lut_gain_th_reg.cadap_lut_gain_tha= table[17];	//9f2c[7:6]
	vdcf_outl(VDPQ_CADAP_LUT_GAIN_TH_reg, cadap_lut_gain_th_reg.regValue);
}

void module_vpq_DMA_cnt_inverse(void)
{
	vdpq_dma_ctrl6_RBUS DMA_CTRL6;
	vdtop_vsync_time_const_RBUS VSYNC_TIME_CONST;

	DMA_CTRL6.regValue = vdcf_inl(VDPQ_DMA_CTRL6_reg);
	VSYNC_TIME_CONST.regValue = vdcf_inl(VDTOP_VSYNC_TIME_CONST_reg);

	if(VSYNC_TIME_CONST.field_polarity==1)
		DMA_CTRL6.dma_field_inv=0;
	else
		DMA_CTRL6.dma_field_inv=1;

	vdcf_outl(VDPQ_DMA_CTRL6_reg, DMA_CTRL6.regValue);
}

void module_vpq_IC_hardware_reset(void)
{
	// DMA related setting
	vdcf_maskl(0xb8019854, 0xfffffffb, 0x00000000); // dma field inverse reset

	// PQ related registers
	vdcf_outl(0xb8019904, 0x00000550);
	vdcf_outl(0xb8019908, 0x00000440);
	vdcf_outl(0xb801990c, 0x0000000a);
	vdcf_outl(0xb8019910, 0x00000077);
	vdcf_outl(0xb8019914, 0x00000042);
	vdcf_outl(0xb8019918, 0x00000007);
	vdcf_outl(0xb8019928, 0x00000000);
	vdcf_outl(0xb801992c, 0x00000001);
	vdcf_outl(0xb8019930, 0x00000000);
	vdcf_outl(0xb8019934, 0x00000010);
	vdcf_outl(0xb8019938, 0x00000020);
	vdcf_outl(0xb801993c, 0x00000008);
	vdcf_outl(0xb8019940, 0x00000002);
	vdcf_outl(0xb8019944, 0x04053222);
	vdcf_outl(0xb8019948, 0x00020221);
	vdcf_outl(0xb801994c, 0x00000006);
	vdcf_outl(0xb8019950, 0x00000015);
	vdcf_outl(0xb8019954, 0x0000000f);
	vdcf_outl(0xb8019958, 0x0000000a);
	vdcf_outl(0xb801995c, 0x00000004);
	vdcf_outl(0xb8019960, 0x00000000);
	vdcf_outl(0xb8019964, 0x00081e00);
	vdcf_outl(0xb8019968, 0x0019a221);
	vdcf_outl(0xb8019970, 0x00325050);
	vdcf_outl(0xb8019974, 0x0000190c);
	vdcf_outl(0xb8019978, 0x519321e0);
	vdcf_outl(0xb801997c, 0x00283194);
	vdcf_outl(0xb8019988, 0x00001e00);
	vdcf_outl(0xb801998c, 0xc8643246);
	vdcf_outl(0xb8019990, 0x000a0a78);
	vdcf_outl(0xb8019994, 0x02d0008c);
	vdcf_outl(0xb8019998, 0x028a012c);
	vdcf_outl(0xb801999c, 0x00000a19);
	vdcf_outl(0xb80199a0, 0x052230a7);
	vdcf_outl(0xb80199a4, 0x19114144);
	vdcf_outl(0xb80199a8, 0x000042b7);
	vdcf_outl(0xb80199d0, 0x0000000c);
	vdcf_outl(0xb80199d4, 0x08070504);
	vdcf_outl(0xb80199d8, 0x0a05040a);
	vdcf_outl(0xb80199dc, 0x0003100d);
	vdcf_outl(0xb80199e0, 0x00060402);
	vdcf_outl(0xb80199e4, 0x50405808);
	vdcf_outl(0xb80199e8, 0x00a0c051);
	vdcf_outl(0xb80199ec, 0x00000608);
	vdcf_outl(0xb80199f0, 0x02141601);
	vdcf_outl(0xb80199f4, 0x00a81914);
	vdcf_outl(0xb80199f8, 0x06080a0c);
	vdcf_outl(0xb80199fc, 0x00000023);
	vdcf_outl(0xb8019b28, 0x00000000);
	vdcf_outl(0xb8019b2c, 0x00000000);
	vdcf_outl(0xb8019b30, 0x00000080);
	vdcf_outl(0xb8019b34, 0x00000000); // 4fsc yc delay
	vdcf_outl(0xb8019cfc, 0x00403080);
	vdcf_outl(0xb8019d00, 0x00000000);
	vdcf_outl(0xb8019d04, 0x00050000);
	vdcf_outl(0xb8019d08, 0x00050000);
	vdcf_outl(0xb8019d0c, 0xa1414280);
	vdcf_outl(0xb8019d10, 0x0030f3ca);
	vdcf_outl(0xb8019d14, 0x0023a28a);
	vdcf_outl(0xb8019d18, 0x0050f140);
	vdcf_outl(0xb8019d1c, 0x0305140a);
	vdcf_outl(0xb8019d20, 0x00000000);
	vdcf_outl(0xb8019d24, 0x23264000);
	vdcf_outl(0xb8019d28, 0x140db976);
	vdcf_outl(0xb8019d2c, 0x00151442);
	vdcf_outl(0xb8019d30, 0x000000f0);
	vdcf_outl(0xb8019d34, 0x00000140);
	vdcf_outl(0xb8019d38, 0x0000000a);
	vdcf_outl(0xb8019d3c, 0x19103251);
	vdcf_outl(0xb8019d40, 0x07010814);
	vdcf_outl(0xb8019d44, 0x00a0a20a);
	vdcf_outl(0xb8019d48, 0x0125060a);
	vdcf_outl(0xb8019d4c, 0x0000000f);
	vdcf_outl(0xb8019d50, 0x0001e3e0);
	vdcf_outl(0xb8019d54, 0x00f50c0a);
	vdcf_outl(0xb8019d58, 0x08090b0b);
	vdcf_outl(0xb8019d5c, 0x06070707);
	vdcf_outl(0xb8019d60, 0x0f0f0606);
	vdcf_outl(0xb8019d64, 0x0f141414);
	vdcf_outl(0xb8019d68, 0x0f0f0f0f);
	vdcf_outl(0xb8019d6c, 0x050f0f0f);
	vdcf_outl(0xb8019d70, 0x1e214002);
	vdcf_outl(0xb8019d74, 0x0000050f);
	vdcf_outl(0xb8019d78, 0x02614082);
	vdcf_outl(0xb8019d7c, 0x26050f1e);
	vdcf_outl(0xb8019d80, 0x000140f1);
	vdcf_outl(0xb8019d84, 0x000a1108);
	vdcf_outl(0xb8019d88, 0x00000000);
	vdcf_outl(0xb8019d8c, 0x00000000);
	vdcf_outl(0xb8019d90, 0x00000000);
	vdcf_outl(0xb8019d94, 0x00000000);
	vdcf_outl(0xb8019d98, 0x0000f050);
	vdcf_outl(0xb8019d9c, 0x440f0712);
	vdcf_outl(0xb8019da0, 0x00000000);
	vdcf_outl(0xb8019da4, 0x192170f0);
	vdcf_outl(0xb8019da8, 0x190f2d14);
	vdcf_outl(0xb8019dac, 0x0000000f);
	vdcf_outl(0xb8019db0, 0x00a29240);
	vdcf_outl(0xb8019db4, 0x00001914);
	vdcf_outl(0xb8019db8, 0x0190c30a);
	vdcf_outl(0xb8019dbc, 0x0f0a0a0a);
	vdcf_outl(0xb8019dc0, 0x05050505);
	vdcf_outl(0xb8019dc4, 0x0a191404);
	vdcf_outl(0xb8019dc8, 0x00001919);
	vdcf_outl(0xb8019dcc, 0x1e0f4b5a);
	vdcf_outl(0xb8019dd0, 0x0000c30a);
	vdcf_outl(0xb8019dd4, 0x050a1428);
	vdcf_outl(0xb8019dd8, 0x0a19141e);
	vdcf_outl(0xb8019ddc, 0x1e1e190c);
	vdcf_outl(0xb8019de0, 0x051e0f0f);
	vdcf_outl(0xb8019de4, 0x23661e0f);
	vdcf_outl(0xb8019de8, 0x00ffa006);
	vdcf_outl(0xb8019dec, 0x2680230a);
	vdcf_outl(0xb8019df0, 0x00000000);
	vdcf_outl(0xb8019df4, 0x00000044);
	vdcf_outl(0xb8019df8, 0x00000080);
	vdcf_outl(0xb8019e04, 0x00000000);
	vdcf_outl(0xb8019e08, 0x00000015);
	vdcf_outl(0xb8019e0c, 0x00000033);
	vdcf_outl(0xb8019e10, 0x00000022);
	vdcf_outl(0xb8019e14, 0x0d08143f);
	vdcf_outl(0xb8019e18, 0x0000d086);
	vdcf_outl(0xb8019e1c, 0x0000011a);
	vdcf_outl(0xb8019e20, 0x001e011e);
	vdcf_outl(0xb8019e24, 0x00ff050a);
	vdcf_outl(0xb8019e28, 0x07e00ab7);
	vdcf_outl(0xb8019e2c, 0x00003040);
	vdcf_outl(0xb8019e30, 0x01206010);
	vdcf_outl(0xb8019e34, 0xb0c14300);
	vdcf_outl(0xb8019e38, 0x51920058);
	vdcf_outl(0xb8019e3c, 0x64fab400);
	vdcf_outl(0xb8019e40, 0x00000444);
	vdcf_outl(0xb8019e44, 0x00000000);
	vdcf_outl(0xb8019e48, 0x33333210);
	vdcf_outl(0xb8019e4c, 0x03333333);
	vdcf_outl(0xb8019e50, 0x00013050);
	vdcf_outl(0xb8019e54, 0x2a2a0444);
	vdcf_outl(0xb8019e58, 0x04445002);
	vdcf_outl(0xb8019e60, 0x00000000);
	vdcf_outl(0xb8019e64, 0x00000000);
	vdcf_outl(0xb8019e68, 0x07000000);
	vdcf_outl(0xb8019e6c, 0x000c0603);
	vdcf_outl(0xb8019e70, 0x0000c000);
	vdcf_outl(0xb8019e74, 0x00000000);
	vdcf_outl(0xb8019e78, 0x00000000);
	vdcf_outl(0xb8019e7c, 0x01408780);
	vdcf_outl(0xb8019e80, 0x19440505);
	vdcf_outl(0xb8019e84, 0x44440a04);
	vdcf_outl(0xb8019e88, 0x0044843c);
	vdcf_outl(0xb8019ee8, 0x00000000); // 2D/3D Alpha blending weight from Merlin2
	vdcf_outl(0xb8019eec, 0x00000000); // 2D/3D Alpha blending weight
	vdcf_outl(0xb8019ef0, 0x00040808); // 2D/3D Alpha blending weight
	vdcf_outl(0xb8019ef4, 0x0c0c0e0e); // 2D/3D Alpha blending weight
	vdcf_outl(0xb8019ef8, 0x10101010); // 2D/3D Alpha blending weight
	vdcf_outl(0xb8019efc, 0x000ff880); // 2D/3D Alpha blending weight
	vdcf_outl(0xb8019f00, 0x00000003);
	vdcf_outl(0xb8019f04, 0x00000000);
	vdcf_outl(0xb8019f0c, 0x00000018);
	vdcf_outl(0xb8019f10, 0x00000007);
	vdcf_outl(0xb8019f14, 0x00000068);
	vdcf_outl(0xb8019f18, 0x00000034);
	vdcf_outl(0xb8019f1c, 0x00000074);
	vdcf_outl(0xb8019f20, 0x00000055);
	vdcf_outl(0xb8019f24, 0x00000055);
	vdcf_outl(0xb8019f28, 0x00000067);
	vdcf_outl(0xb8019f2c, 0x0000007d);
	vdcf_outl(0xb8019f30, 0x00000000);
	vdcf_outl(0xb8019f34, 0x00000000);
	vdcf_outl(0xb8019f38, 0x00000000);
	vdcf_outl(0xb8019f3c, 0x00000000);
	vdcf_outl(0xb8019f40, 0x00000000);
	vdcf_outl(0xb8019f44, 0x00000000);
	vdcf_outl(0xb8019f48, 0x00000000);
	vdcf_outl(0xb8019f4c, 0x04040a0a);
	vdcf_outl(0xb8019f50, 0x00003232);
	vdcf_outl(0xb8019f54, 0x01000519);
	vdcf_outl(0xb8019f58, 0x00000400);
	vdcf_outl(0xb8019f68, 0x000a0000); // Noise status
	vdcf_outl(0xb8019f6c, 0x00000000); // Noise status
	vdcf_outl(0xb8019f7c, 0x00001031); // Noise status
	vdcf_outl(0xb8019f70, 0x00041400); // Post SECAM setting
	vdcf_outl(0xb8019f74, 0x04010314); // Post SECAM setting
	vdcf_outl(0xb8019f78, 0x00000403); // Post SECAM setting
	vdcf_outl(0xb8019f80, 0x00000000); // Directional 3D
	vdcf_outl(0xb8019f90, 0x00000000); // Window
	vdcf_outl(0xb8019f94, 0x00000000); // Window
	vdcf_outl(0xb8019f98, 0x00000000); // Window
}

#if 0
// MODULE API
#endif
unsigned char drvif_module_vpq_get_ProjectId(void)
{
	return ucVdpqPrjId;
}

unsigned char drvif_module_vpq_set_ProjectId(unsigned char Id)
{
	ucVdpqPrjId = Id;
	if( ucVdpqPrjId >= PRJ_NUM_MAX )
		ucVdpqPrjId = PRJ_NO_0;
}

unsigned char drvif_module_vpq_get_f_num_3d_fail_det_bit(void)
{
	vdpq_frame_buf_chk3d_ctrl1_RBUS frame_buf_chk3d_ctrl1_reg;
	frame_buf_chk3d_ctrl1_reg.regValue = vdcf_inl(VDPQ_FRAME_BUF_CHK3D_CTRL1_reg);
	return frame_buf_chk3d_ctrl1_reg.f_num_3d_fail_det;
}

void drvif_module_vpq_DmaAccessCtrl(unsigned char on_off)
{
	if (on_off == ON)
	{
		vdpq_dma_ctrl5_RBUS vdpq_dma_ctrl5_reg; /* 1_9850 */
		vdpq_dma_ctrl5_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL5_reg); /* 1_9850 */
		vdpq_dma_ctrl5_reg.mem_off = 0;
		vdcf_outl(VDPQ_DMA_CTRL5_reg, vdpq_dma_ctrl5_reg.regValue);
		//rtd_printk(KERN_INFO, TAG_NAME_VDC,"%s set ON\n", __FUNCTION__);
	}
	else if (on_off == OFF)
	{
		vdpq_dma_ctrl5_RBUS vdpq_dma_ctrl5_reg; /* 1_9850 */
		vdpq_dma_ctrl5_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL5_reg); /* 1_9850 */
		vdpq_dma_ctrl5_reg.mem_off = 1;
		vdcf_outl(VDPQ_DMA_CTRL5_reg, vdpq_dma_ctrl5_reg.regValue);
		//rtd_printk(KERN_INFO, TAG_NAME_VDC,"%s set OFF\n", __FUNCTION__);
	}
}

void drvif_module_vpq_3D_mem_Initial(unsigned int mem_addr)
{
	unsigned int nRegAddr;
	vdpq_mem0_addr_ini_RBUS mem0_addr_ini_reg;
	vdpq_mem1_addr_ini_RBUS mem1_addr_ini_reg;
	vdpq_mem2_addr_ini_RBUS mem2_addr_ini_reg;
	vdpq_mem3_addr_ini_RBUS mem3_addr_ini_reg;
	vdpq_mem0_addr_end_RBUS mem0_addr_end_reg;
	vdpq_mem1_addr_end_RBUS mem1_addr_end_reg;
	vdpq_mem2_addr_end_RBUS mem2_addr_end_reg;
	vdpq_mem3_addr_end_RBUS mem3_addr_end_reg;

	nRegAddr = (mem_addr>>3)&0x1fffffff;
	rtd_printk(KERN_DEBUG, TAG_NAME, "[%s] Initial set addr = %x, _SDRAM_3D_ONE_FRAME_USE = %x\n", __func__, nRegAddr, _SDRAM_3D_ONE_FRAME_USE);

	mem0_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_INI_reg);
	mem1_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM1_ADDR_INI_reg);
	mem2_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM2_ADDR_INI_reg);
	mem3_addr_ini_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_INI_reg);
	mem0_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM0_ADDR_END_reg);
	mem1_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM1_ADDR_END_reg);
	mem2_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM2_ADDR_END_reg);
	mem3_addr_end_reg.regValue = vdcf_inl(VDPQ_MEM3_ADDR_END_reg);

	// frame 0 start
	mem0_addr_ini_reg.frame_addr0 = nRegAddr;
	// frame 0 end
	nRegAddr = nRegAddr + _SDRAM_3D_ONE_FRAME_USE - 1;
	mem0_addr_end_reg.frame_addr0_end = nRegAddr;

	// frame 1 start
	nRegAddr = nRegAddr + 1;
	mem1_addr_ini_reg.frame_addr1 = nRegAddr;

	// frame 1 end
	nRegAddr = nRegAddr + _SDRAM_3D_ONE_FRAME_USE - 1;
	mem1_addr_end_reg.frame_addr1_end = nRegAddr;

	// frame 2 start
	nRegAddr = nRegAddr + 1;
	mem2_addr_ini_reg.frame_addr2 = nRegAddr;

	// frame 2 end
	nRegAddr = nRegAddr + _SDRAM_3D_ONE_FRAME_USE - 1;
	mem2_addr_end_reg.frame_addr2_end = nRegAddr;

	// frame 3 start
	nRegAddr = nRegAddr + 1;
	mem3_addr_ini_reg.frame_addr3 = nRegAddr;

	// frame 3 end
	nRegAddr = nRegAddr + _SDRAM_3D_ONE_FRAME_USE - 1;
	mem3_addr_end_reg.frame_addr3_end = nRegAddr;

	vdcf_outl(VDPQ_MEM0_ADDR_INI_reg,mem0_addr_ini_reg.regValue);
	vdcf_outl(VDPQ_MEM1_ADDR_INI_reg,mem1_addr_ini_reg.regValue);
	vdcf_outl(VDPQ_MEM2_ADDR_INI_reg,mem2_addr_ini_reg.regValue);
	vdcf_outl(VDPQ_MEM3_ADDR_INI_reg,mem3_addr_ini_reg.regValue);
	vdcf_outl(VDPQ_MEM0_ADDR_END_reg,mem0_addr_end_reg.regValue);
	vdcf_outl(VDPQ_MEM1_ADDR_END_reg,mem1_addr_end_reg.regValue);
	vdcf_outl(VDPQ_MEM2_ADDR_END_reg,mem2_addr_end_reg.regValue);
	vdcf_outl(VDPQ_MEM3_ADDR_END_reg,mem3_addr_end_reg.regValue);

	rtd_printk(KERN_DEBUG, TAG_NAME, "[%s] memory set done\n", __func__);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Frame 0 : %x - %X\n", mem0_addr_ini_reg.regValue, mem0_addr_end_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Frame 0 : %x - %X\n", mem1_addr_ini_reg.regValue, mem1_addr_end_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Frame 0 : %x - %X\n", mem2_addr_ini_reg.regValue, mem2_addr_end_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Frame 0 : %x - %X\n", mem3_addr_ini_reg.regValue, mem3_addr_end_reg.regValue);

	VPQ_3D_FrameMemStaAddr[0] = mem0_addr_ini_reg.regValue;
	VPQ_3D_FrameMemStaAddr[1] = mem1_addr_ini_reg.regValue;
	VPQ_3D_FrameMemStaAddr[2] = mem2_addr_ini_reg.regValue;
	VPQ_3D_FrameMemStaAddr[3] = mem3_addr_ini_reg.regValue;
	VPQ_3D_FrameMemEndAddr[0] = mem0_addr_end_reg.regValue;
	VPQ_3D_FrameMemEndAddr[1] = mem1_addr_end_reg.regValue;
	VPQ_3D_FrameMemEndAddr[2] = mem2_addr_end_reg.regValue;
	VPQ_3D_FrameMemEndAddr[3] = mem3_addr_end_reg.regValue;
}

void drvif_module_vpq_FRAME_BUF_CHK3D_control(unsigned char chk_3d_sel,unsigned char open_3d_cnt,unsigned char close_3d_cnt)
{
	vdpq_frame_buf_chk3d_ctrl0_RBUS vdpq_frame_buf_chk3d_ctrl0_reg;
	vdpq_frame_buf_chk3d_ctrl2_RBUS vdpq_frame_buf_chk3d_ctrl2_reg;

	vdpq_frame_buf_chk3d_ctrl0_reg.regValue = vdcf_inl(VDPQ_FRAME_BUF_CHK3D_CTRL0_reg);
	vdpq_frame_buf_chk3d_ctrl2_reg.regValue = vdcf_inl(VDPQ_FRAME_BUF_CHK3D_CTRL2_reg);

	vdpq_frame_buf_chk3d_ctrl0_reg.f_num_chk_3d_sel = chk_3d_sel;
	vdpq_frame_buf_chk3d_ctrl2_reg.f_num_open3d_cnt = open_3d_cnt;
	vdpq_frame_buf_chk3d_ctrl2_reg.f_num_close3d_cnt = close_3d_cnt;

	vdcf_outl(VDPQ_FRAME_BUF_CHK3D_CTRL0_reg, vdpq_frame_buf_chk3d_ctrl0_reg.regValue);
	vdcf_outl(VDPQ_FRAME_BUF_CHK3D_CTRL2_reg, vdpq_frame_buf_chk3d_ctrl2_reg.regValue);
}

void drvif_module_vpq_DMA_CHK3D_VCNT_control(unsigned char dma_3d_on_vcnt)
{
	vdpq_dma_ctrl4_RBUS dma_ctrl4_reg;
	dma_ctrl4_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL4_reg);
	dma_ctrl4_reg.dma_3d_on_vcnt = dma_3d_on_vcnt;
	vdcf_outl(VDPQ_DMA_CTRL4_reg,dma_ctrl4_reg.regValue);
}

unsigned char drvif_module_vpq_GetYcSep(void)
{
	return ucYcSeparationStatus;
}

unsigned char drvif_module_vpq_SetYcSep(unsigned char YcSep)
{
	/*int ret;*/
	_system_setting_info *VIP_system_info_structure_table = NULL;
	ucYcSeparationStatus = YcSep;

	VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	VIP_system_info_structure_table->YC_separation_status = ucYcSeparationStatus;
	return TRUE;
}

void drvif_module_vpq_set_2d_table_index_Factory(unsigned char value)
{
	VPQ_2D_TableIndex = value;
	module_vpq_2DTableWrite(VPQ_2D_TableIndex);
}

unsigned char drvif_module_vpq_get_2d_table_index_Factory(void)
{
	return VPQ_2D_TableIndex;
}

void drvif_module_vpq_DisableMemory(void)
{
	vdpq_dma_ctrl5_RBUS dma_ctrl5_reg;
	dma_ctrl5_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL5_reg);
	if(dma_ctrl5_reg.mem_off == 0)	// if memory on
	{
		vdpq_yc_sep_mode_ctrl_RBUS yc_sep_mode_ctrl_reg;
		yc_sep_mode_ctrl_reg.regValue = vdcf_inl(VDPQ_YC_SEP_MODE_CTRL_reg);
		yc_sep_mode_ctrl_reg.yc_sep_mode = 0x00;
		vdcf_outl(VDPQ_YC_SEP_MODE_CTRL_reg,yc_sep_mode_ctrl_reg.regValue);
		drvif_module_vpq_DmaAccessCtrl(OFF);
		rtd_printk(KERN_DEBUG, TAG_NAME, "[%s] 3D disable!! memory off\n", __func__);
	}
}

void drvif_module_vpq_TV_DCTIeh_Enable(unsigned char on_off)
{
	vdpq_dcti_filter_en_RBUS dcti_filter_en_reg;
	dcti_filter_en_reg.regValue = vdcf_inl(VDPQ_DCTI_FILTER_EN_reg);
	if(dcti_filter_en_reg.dcti_filter_en != on_off)
	{
		dcti_filter_en_reg.dcti_filter_en = on_off;
		vdcf_outl(VDPQ_DCTI_FILTER_EN_reg, dcti_filter_en_reg.regValue);
		rtd_printk(KERN_DEBUG, TAG_NAME, "TV DCTIeh : %x\n", on_off);
	}
}

void drvif_module_vpq_set_DeXC_Enable(unsigned char on_off)
{
	vdpq_de_xc_ctrl_RBUS de_xc_ctrl_reg;
	de_xc_ctrl_reg.regValue = vdcf_inl(VDPQ_DE_XC_CTRL_reg);
	de_xc_ctrl_reg.xc_blend_en= on_off;
	de_xc_ctrl_reg.de_xc_en = on_off;
	vdcf_outl(VDPQ_DE_XC_CTRL_reg, de_xc_ctrl_reg.regValue);
}

void drvif_module_vpq_set_DeXC_Threshold(unsigned char value)
{
	vdpq_de_xc_ctrl_RBUS de_xc_ctrl_reg;
	de_xc_ctrl_reg.regValue = vdcf_inl(VDPQ_DE_XC_CTRL_reg);
	de_xc_ctrl_reg.de_xc_thr = value;
	vdcf_outl(VDPQ_DE_XC_CTRL_reg, de_xc_ctrl_reg.regValue);
}

unsigned char drvif_module_vpq_Get_DeXC_Threshold(void)
{
	vdpq_de_xc_ctrl_RBUS de_xc_ctrl_reg;
	de_xc_ctrl_reg.regValue = vdcf_inl(VDPQ_DE_XC_CTRL_reg);
	return de_xc_ctrl_reg.de_xc_thr;
}

void drvif_module_vpq_DCTI_Set(unsigned char ucMode)
{
	VPQ_DCTI_TableIndex = ucMode;
	switch(ucMode)
	{

		case TABLE1:
			module_vpq_DCTI_Table_write(VPQ_POSTP_CTI_SET1);
			break;
		case TABLE2:
			module_vpq_DCTI_Table_write(VPQ_POSTP_CTI_SET2);
			break;
		case TABLE3:
			module_vpq_DCTI_Table_write(VPQ_POSTP_CTI_SET3);
			break;
		case TABLE4:
			module_vpq_DCTI_Table_write(VPQ_POSTP_CTI_SET4);
			break;
		case TABLE5:
			module_vpq_DCTI_Table_write(VPQ_POSTP_CTI_SET5);
			break;
		default:
			break;
	}
}

unsigned char drvif_module_vpq_get_dcti_table_index_Factory(void)
{
	return VPQ_DCTI_TableIndex;
}
