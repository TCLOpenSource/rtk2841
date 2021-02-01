#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/include/PQLAPI.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/FRC_SceneAnalysis.h"
#include "memc_isr/PQL/MESceneAnalysis.h"
#include "io.h"

#define FILE_HEADER_SIZE		64
#define PAGE_HEADER_SIZE		16
#define PAGE_CONTENT_SIZE		256
//#define PAGE_ADDRESS_OFFSET		4
#define PAGE_SIZE_OFFSET		8

extern unsigned char u8HDF_Array[FILE_HEADER_SIZE+ 42*(PAGE_HEADER_SIZE+PAGE_CONTENT_SIZE)];


///////////////////////////////////////////////////////////////////////
//Global parameters & contexts
_PQLPARAMETER	*s_pParam;

_PQLCONTEXT s_Context;

#define	_VIDEO_N	CAD_N
#define	_22_N		CAD_N
#define	_32_N		CAD_N
#define	_32322_N	CAD_N
#define	_334_N		CAD_N
#define	_22224_N	CAD_N
#define	_2224_N	CAD_N
#define	_3223_N	CAD_N
#define	_55_N		CAD_N
#define	_66_N		CAD_N
#define	_44_N		CAD_N
#define	_1112_N	CAD_N
#define	_11112_N	CAD_N
#define	_122_N		CAD_N
#define	_11i23_N	CAD_N


#define	_VIDEO_T	CAD_T
#define	_22_T		CAD_T
#define	_32_T		CAD_T
#define	_32322_T	CAD_T
#define	_334_T		CAD_T
#define	_22224_T	CAD_T
#define	_2224_T		CAD_T
#define	_3223_T		CAD_T
#define	_55_T		CAD_T
#define	_66_T		CAD_T
#define	_44_T		CAD_T
#define	_1112_T		CAD_T
#define	_11112_T	CAD_T
#define	_122_T		CAD_T
#define	_11i23_T	CAD_T

#define	_VIDEO_F	CAD_F
#define	_22_F		CAD_F
#define	_32_F		CAD_F
#define	_32322_F	CAD_F
#define	_334_F		CAD_F
#define	_22224_F	CAD_F
#define	_2224_F		CAD_F
#define	_3223_F		CAD_F
#define	_55_F		CAD_F
#define	_66_F		CAD_F
#define	_44_F		CAD_F
#define	_1112_F		CAD_F
#define	_11112_F	CAD_F
#define	_122_F		CAD_F
#define	_11i23_F	CAD_F

const UBYTE g_FRCCADEN_120HZOUT_T[_PQL_IN_96HZ][_FRC_CADENCE_NUM_] =
{
	//_PQL_IN_24HZ,
	{_VIDEO_T, _22_F, _32_N, _32322_N, _334_N, _22224_N, _2224_N, _3223_N, _55_N, _66_N, _44_N, _1112_N, _11112_N, _122_N, _11i23_N},	
	//_PQL_IN_25HZ,
	{_VIDEO_T, _22_N, _32_N, _32322_N, _334_N, _22224_N, _2224_N, _3223_N, _55_N, _66_N, _44_N, _1112_N, _11112_N, _122_N, _11i23_N},
	//_PQL_IN_30HZ,
	{_VIDEO_T, _22_F, _32_F, _32322_N, _334_N, _22224_N, _2224_F, _3223_F, _55_N, _66_N, _44_N, _1112_T, _11112_T, _122_N, _11i23_N},
	//_PQL_IN_48HZ,
	{_VIDEO_T, _22_N, _32_N, _32322_N, _334_N, _22224_N, _2224_N, _3223_N, _55_N, _66_N, _44_N, _1112_N, _11112_N, _122_N, _11i23_N},
	//_PQL_IN_50HZ,
	{_VIDEO_T, _22_T, _32_N, _32322_N, _334_F, _22224_N, _2224_N, _3223_N, _55_F, _66_F, _44_F, _1112_N, _11112_N, _122_T, _11i23_F},
	//_PQL_IN_60HZ,
	{_VIDEO_T, _22_T, _32_T, _32322_T, _334_F, _22224_T, _2224_T, _3223_T, _55_F, _66_F, _44_F, _1112_F, _11112_T, _122_N, _11i23_N},
};


const UBYTE g_FRCCADEN_60HZOUT_T[_PQL_IN_96HZ][_FRC_CADENCE_NUM_] = 
{
	//_PQL_IN_24HZ,
	{_VIDEO_T, _22_F, _32_N, _32322_N, _334_N, _22224_N, _2224_N, _3223_N, _55_N, _66_N, _44_N, _1112_N, _11112_N, _122_N, _11i23_N},	
	//_PQL_IN_25HZ,
	{_VIDEO_T, _22_N, _32_N, _32322_N, _334_N, _22224_N, _2224_N, _3223_N, _55_N, _66_N, _44_N, _1112_N, _11112_N, _122_N, _11i23_N},
	//_PQL_IN_30HZ,
	{_VIDEO_T, _22_F, _32_F, _32322_N, _334_N, _22224_N, _2224_F, _3223_F, _55_N, _66_N, _44_N, _1112_T, _11112_T, _122_N, _11i23_N},
	//_PQL_IN_48HZ,
	{_VIDEO_T, _22_N, _32_N, _32322_N, _334_N, _22224_N, _2224_N, _3223_N, _55_N, _66_N, _44_N, _1112_N, _11112_N, _122_N, _11i23_N},
	//_PQL_IN_50HZ,
	{_VIDEO_T, _22_T, _32_N, _32322_N, _334_F, _22224_N, _2224_N, _3223_N, _55_F, _66_F, _44_F, _1112_N, _11112_N, _122_T, _11i23_F},
	//_PQL_IN_60HZ,
	{_VIDEO_T, _22_T, _32_T, _32322_T, _334_F, _22224_T, _2224_T, _3223_T, _55_F, _66_F, _44_F, _1112_F, _11112_T, _122_N, _11i23_N},
};


void DebugCommandCheck(VOID);
//////////////////////////////////////////////////////////////////////////////////////

VOID Debug_Msg_Print(_PQLPARAMETER* g_pParam, _PQLCONTEXT* pContext)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//*******************************//
	//********FrameRate Change********//
	UINT32 in_phase=0;
	UINT32 out_phase=0;
	ReadRegister(KIWI_REG(FRC_TOP__kphase__regr_kphase_in_phase), &in_phase);
	ReadRegister(KIWI_REG(FRC_TOP__kphase__regr_kphase_out_phase), &out_phase);

	UINT32 u32_iFrameRateHz_pre = 0;
	UINT32 u32_iFrameRateHz = 0;
	UINT32 u32_oFrameRateHz_pre = 0;
	UINT32 u32_oFrameRateHz = 0;
	UINT32 u32_iFrameRateTh = (27000000/50 - 27000000/60)/2;
	UINT32 u32_oFrameRateTh = (27000000/100 - 27000000/120)/2;
	UINT32 u32_iFrameRate = 0;
	UINT32 u32_oFrameRate = 0;
	static UINT32 u32_iFrameRate_Pre = 0;
	static UINT32 u32_oFrameRate_Pre = 0;
	RTKReadRegister(0xb80282e4, &u32_iFrameRate);
	RTKReadRegister(0xb80282ec, &u32_oFrameRate);

	u32_iFrameRateHz_pre    = (u32_iFrameRate_Pre==0) ? 0: (27000000*10/u32_iFrameRate_Pre);
	u32_iFrameRateHz        =  (u32_iFrameRate==0) ? 0: (27000000*10/u32_iFrameRate);
	u32_oFrameRateHz_pre    =  (u32_oFrameRate_Pre==0) ? 0: (27000000*10/u32_oFrameRate_Pre);
	u32_oFrameRateHz        =  (u32_oFrameRate==0) ? 0: (27000000*10/u32_oFrameRate);

	UBYTE u1_trig_inPhase_noMatch		= (in_phase >= s_pContext->_output_frc_phtable.u8_sys_N_pre);
	UBYTE u1_trig_outPhase_noMatch		= (out_phase > s_pContext->_output_frc_phtable.u8_sys_M_pre);
	UBYTE u1_trig_iFrameRate_noMatch	= (u32_iFrameRate>u32_iFrameRate_Pre)? ((u32_iFrameRate -u32_iFrameRate_Pre) > u32_iFrameRateTh) : ((u32_iFrameRate_Pre -u32_iFrameRate) > u32_iFrameRateTh);
	UBYTE u1_trig_oFrameRate_noMatch    = (u32_oFrameRate>u32_oFrameRate_Pre)? ((u32_oFrameRate -u32_oFrameRate_Pre) > u32_oFrameRateTh) : ((u32_oFrameRate_Pre -u32_oFrameRate) > u32_oFrameRateTh);

	UBYTE u1_IOPhase_N2M_logEn = g_pParam->_param_filmDetectctrl.u1_DbgPrt_FRChg_En;

	if(u1_trig_inPhase_noMatch && u1_IOPhase_N2M_logEn)
		LogPrintf(DBG_WARNING, "[FR] inPhase >= N!!!(inPh = %d, N = %d)\n\r", in_phase, s_pContext->_output_frc_phtable.u8_sys_N_pre);
	if(u1_trig_outPhase_noMatch && u1_IOPhase_N2M_logEn)
		LogPrintf(DBG_WARNING, "[FR] outPhase > M!!!(outPh = %d, M = %d)\n\r", out_phase, s_pContext->_output_frc_phtable.u8_sys_M_pre);
	if(u1_trig_iFrameRate_noMatch  && u1_IOPhase_N2M_logEn)
		LogPrintf(DBG_WARNING, "[FR] in FrameRate Change!!!(%dHz(%d) -> %dHz(%d))\n\r", u32_iFrameRateHz_pre, u32_iFrameRate_Pre, u32_iFrameRateHz, u32_iFrameRate);
	if(u1_trig_oFrameRate_noMatch  && u1_IOPhase_N2M_logEn)
		LogPrintf(DBG_WARNING, "[FR] out FrameRate Change!!!(%dHz(%d) -> %dHz(%d))\n\r", u32_oFrameRateHz_pre, u32_oFrameRate_Pre, u32_oFrameRateHz, u32_oFrameRate);

	u32_iFrameRate_Pre      = u32_iFrameRate;
	u32_oFrameRate_Pre      = u32_oFrameRate;
	//**************************//

}

VOID PQL_ContextInit(VOID)
{
#ifndef _WIN32
	s_pParam = GetPQLParameter();
#endif

	PQL_MessageInit(s_pParam,&s_Context);

	/////////////////////////////////////
	ReadComReg_Init(&(s_Context._output_read_comreg));
	RimCtrl_Init(&(s_Context._output_rimctrl));
	FilmDetect_Init(&(s_Context._output_filmDetectctrl));
	FBLevelCtrl_Init(&(s_Context._output_fblevelctrl));

	Dh_close_Init(&(s_Context._output_dh_close));
	Mc_lbmcSwitch_Init(&(s_Context._output_mc_lbmcswitch));
	FRC_phTable_Init(&(s_Context._output_frc_phtable));
	FRC_LogoDet_Init(&(s_Context._output_FRC_LgDet));

	FRC_SceneAnalysis_Init(&s_Context._output_frc_sceneAnalysis);

	Me_sceneAnalysis_Init(&(s_Context._output_me_sceneAnalysis));
	Wrt_ComReg_Init(&(s_Context._output_wrt_comreg));

	PatchManage_Init(&(s_Context._output_Patch_Manage));

	//PQL_ContextProc_ReadParam(s_pParam);
}

BOOL PQL_ReadHDF(UINT32 uiAddr, SINT32 ibitStart, SINT32 ibitEnd, UINT32 *puiVal)
{
	BOOL bRet = TRUE;
	UINT32 u32Mask = 0xffffffff;

	UINT32 u32PageSize = 0, u32HdfPoint = 0;
	UINT32 uiAddr_page, uiAddr_content;
	UBYTE u8_page_mapping[0x47] = {  0,  1,  2,  3,  4,255,  5,  6,255,  7,  8,  9,255,255,255,255,
                                   255,255,255,255,255,255,255,255,255,255,255,255,255,255, 10,255,
                                    11,255, 12, 13, 14, 15, 16,255,255, 17,255, 18, 19, 20, 21, 22,
                                    23, 24, 25,255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,255,
                                    37, 38,255,255, 39, 40, 41};
	
	u32PageSize = (u8HDF_Array[FILE_HEADER_SIZE + PAGE_SIZE_OFFSET + 3] << 24) + 
				  (u8HDF_Array[FILE_HEADER_SIZE + PAGE_SIZE_OFFSET + 2] << 16) + 
				  (u8HDF_Array[FILE_HEADER_SIZE + PAGE_SIZE_OFFSET + 1] << 8) + 
				   u8HDF_Array[FILE_HEADER_SIZE + PAGE_SIZE_OFFSET];

	uiAddr_page     = (uiAddr & 0x0000FF00)>>8;
	uiAddr_content  = (uiAddr & 0x000000FF);

	*puiVal = 0xDEADDEAD;

	if (/*uiAddr_page >= 0x00 &&*/ uiAddr_page <= 0x46)
	{
		if (u8_page_mapping[uiAddr_page] != 255)
		{
			uiAddr_page = u8_page_mapping[uiAddr_page];
		}
		else
		{
			uiAddr_page = 0;
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
	
	u32HdfPoint = FILE_HEADER_SIZE + PAGE_HEADER_SIZE + uiAddr_page*(PAGE_HEADER_SIZE + u32PageSize) + uiAddr_content;
	//ROSPrintf("%x => %x\n\r", uiAddr, u32HdfPoint);

	if (ibitEnd < ibitStart)
	{
		return FALSE;
	}
	
	*puiVal = (u8HDF_Array[u32HdfPoint + 3] << 24) + 
			  (u8HDF_Array[u32HdfPoint + 2] << 16) + 
			  (u8HDF_Array[u32HdfPoint + 1] << 8) + 
			  (u8HDF_Array[u32HdfPoint + 0] << 0);
	
	if ((uiAddr % 4 == 0) && (ibitEnd - ibitStart == 31))
	{
		return bRet;
	}
	else
	{
		// get mask
		u32Mask = u32Mask << (31 - ibitEnd);
		u32Mask = u32Mask >> (31 - ibitEnd);
		u32Mask = u32Mask >> ibitStart;
		u32Mask = u32Mask << ibitStart;

		// set mask
		*puiVal &= u32Mask;
		*puiVal = *puiVal >> ibitStart;

		return bRet;
	}
}

VOID PQL_PhaseTableInit(VOID)
{
#ifndef _WIN32
	s_pParam = GetPQLParameter();
#endif
	PQL_MessageInit(s_pParam,&s_Context);
	FRC_PhaseTable_Init(&(s_Context._output_frc_phtable));
	//k2 method, k3 remove but keep code
	//PatchManage_Init(&(s_Context._output_Patch_Manage));
	//k2 method, k3 remove but keep code
	Me_sceneAnalysis_Init(&(s_Context._output_me_sceneAnalysis));
}

VOID PQL_ContextProc_oneFifth_outputInterrupt(SINT32 iSliceIdx)
{
	UINT32 u32_rb_data = 0xFFFFFFFF;
	ReadRegister(KIWI_REG(FRC_TOP__PQL_0__pql_pql_onefifth_intp_en), &u32_rb_data);

	if(u32_rb_data)
	{
		PQL_ContextProc_ReadParam(s_pParam);

		ReadComReg_Proc_oneFifth_OutInterrupt(&(s_pParam->_param_read_comreg),&(s_Context._output_read_comreg));

		RimCtrl_Proc(&(s_pParam->_param_rimctrl),&(s_Context._output_rimctrl));

		Wrt_ComReg_Proc_oneFifth_outInterrupt(&(s_pParam->_param_wrt_comreg), &(s_Context._output_wrt_comreg));

	}
}

VOID PQL_ContextProc_inputInterrupt(SINT32 iSliceIdx)
{
	UINT32 u32_rb_data = 0xFFFFFFFF;
	ReadRegister(KIWI_REG(FRC_TOP__PQL_0__pql_pql_input_intp_en), &u32_rb_data);

	RTICEDebug_OnlineMeasure(0);

	if(u32_rb_data)
	{
		ReadComReg_Proc_inputInterrupt(&(s_pParam->_param_read_comreg),&(s_Context._output_read_comreg));
		FilmDetectCtrl_Proc(&(s_pParam->_param_filmDetectctrl),&(s_Context._output_filmDetectctrl));//60HZ
		FRC_phTable_Proc(&(s_pParam->_param_frc_phtable), &(s_Context._output_frc_phtable));

		FRC_SceneAnalysis_Proc_InputIntp(&(s_pParam->_param_frc_sceneAnalysis), &(s_Context._output_frc_sceneAnalysis));

		// still pattern detect
		FRC_Still_Pattern_Detect(&(s_pParam->_param_filmDetectctrl), &(s_Context._output_filmDetectctrl), &(s_Context._output_frc_sceneAnalysis));
		FRC_LogoDet_Proc(&(s_pParam->_param_FRC_LGDet), &(s_Context._output_FRC_LgDet));
		Mc_lbmcSwitch_Proc(&(s_pParam->_param_mc_lbmcswitch), &(s_Context._output_mc_lbmcswitch));
		MEMC_MiddleWare_Reg_Status_Cad1(&(s_Context._output_me_sceneAnalysis));
		MEMC_SaddiffTh_calc(&(s_Context._output_me_sceneAnalysis));
		Wrt_ComReg_Proc_intputInterrupt(&(s_pParam->_param_wrt_comreg), &(s_Context._output_wrt_comreg));

	}
}

VOID PQL_ContextProc_outputInterrupt(SINT32 iSliceIdx)
{
	UINT32 u32_rb_data = 0xFFFFFFFF;
	ReadRegister(KIWI_REG(FRC_TOP__PQL_0__pql_pql_output_intp_en), &u32_rb_data);

	//Debug_OnlineMeasure();
	RTICEDebug_OnlineMeasure(1);
	
	if(u32_rb_data)
	{
		ReadComReg_Proc_outputInterrupt(&(s_pParam->_param_read_comreg),&(s_Context._output_read_comreg));

#ifdef _WIN32
		PQL_ContextProc_oneFifth_outputInterrupt(0);
		PQL_ContextProc_inputInterrupt(0);
#endif

		PQL_MessageProc();
		Me_sceneAnalysis_Proc_OutputIntp(&(s_pParam->_param_me_sceneAnalysis),&(s_Context._output_me_sceneAnalysis), iSliceIdx);

		//FRC_phTable_Proc(&(s_pParam->_param_frc_phtable), &(s_Context._output_frc_phtable));
		PatchManage_Proc(&(s_pParam->_param_Patch_Manage), &(s_Context._output_Patch_Manage));

		FRC_FastMotion_Detect(&(s_pParam->_param_frc_sceneAnalysis), &(s_Context._output_frc_sceneAnalysis)); //fastmotion, front of fb & dh_close

		FBLevelCtrl_Proc(&(s_pParam->_param_fblevelctrl),&(s_Context._output_fblevelctrl));
		Dh_close_Proc(&(s_pParam->_param_dh_close), &(s_Context._output_dh_close));
		FRC_SceneAnalysis_Proc(&(s_pParam->_param_frc_sceneAnalysis), &(s_Context._output_frc_sceneAnalysis));


		Wrt_ComReg_Proc_outputInterrupt(&(s_pParam->_param_wrt_comreg), &(s_Context._output_wrt_comreg));

	}

	//*************************//
        //Debug Msg
        Debug_Msg_Print(s_pParam, &s_Context);
        //*************************//

}


CAD_SUPPORT_TYPE PQL_FRCCaseSupportJudge(UBYTE CurCadence)
{
	const _PQLCONTEXT     *s_pContext = GetPQLContext();

	UBYTE u1_func_en = s_pParam->_param_filmDetectctrl.u1_FrcCadSupport_En;

	PQL_OUTPUT_FRAME_RATE  u8_out_fmRate = s_pContext->_external_data._output_frameRate;
	PQL_INPUT_FRAME_RATE	u8_in_fmRate = s_pContext->_external_data._input_frameRate;


	if(!u1_func_en)
		return 1;

	if(CurCadence>=_FRC_CADENCE_NUM_)
		return 0;

	if(u8_in_fmRate>=_PQL_IN_96HZ)
		u8_in_fmRate = _PQL_IN_60HZ;

	if(u8_out_fmRate<=_PQL_OUT_60HZ)
		return g_FRCCADEN_60HZOUT_T[u8_in_fmRate][CurCadence];
	else
		return g_FRCCADEN_120HZOUT_T[u8_in_fmRate][CurCadence];

}

///////////////////////////////////////////
const _PQLCONTEXT *GetPQLContext()
{
	return (const _PQLCONTEXT *)&s_Context;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
enum _SERVERCOMMAND {SCMD_VOID,SCMD_RESET,SCMD_BASEADDR,SCMD_TARGETSIZE,
	SCMD_SETPARA,SCMD_GETPARA,SCMD_GETDATA};

//command mailbox registers
#define _CMDREG_0 0x00004500
#define _CMDREG_1 0x00004504
#define _CMDREG_2 0x00004508
#define _CMDREG_3 0x0000450C

VOID DebugCommandCheck()
{
	unsigned int uiCmd;
	static unsigned int suiCount = 0;
	suiCount++;
	WriteRegister(_CMDREG_3, 0, 31, suiCount);
	ReadRegister(_CMDREG_0,0,31,&uiCmd);

	if (uiCmd & 0xFF)
	{//if tx ready
		switch ((uiCmd>>16) & 0xFF)
		{
		case SCMD_RESET:

			break;

		case SCMD_TARGETSIZE:
			WriteRegister(_CMDREG_1,0,31,(unsigned int)sizeof(_PQLPARAMETER));
			WriteRegister(_CMDREG_2,0,31,(unsigned int)sizeof(_PQLCONTEXT));
			break;

		case SCMD_BASEADDR:
			WriteRegister(_CMDREG_1,0,31,(unsigned int)s_pParam);
			WriteRegister(_CMDREG_2,0,31,(unsigned int)&s_Context);
			break;

		case SCMD_GETPARA:
			{
				unsigned int uiAddr;
				//unsigned int uiData0 = 0;
				unsigned int uiData = 0;
				int i;
				ReadRegister(_CMDREG_1,0,31,&uiAddr);
				/*if (uiAddr >= (unsigned int)s_pParam && uiAddr < (unsigned int)s_pParam+sizeof(_PQLPARAMETER))
				{
				   uiData0 = *(volatile unsigned long *)uiAddr;
				}
 				uiData = 0;
 				for (i = 3; i >= 0; i--) {
 					uiData <<= 8;
 					uiData += (uiData0&0xFF);
					uiData0 >>= 8;
 				}*/
 				uiData = 0;
				for (i = 3; i >= 0; i--) {
					uiData <<= 8;
					uiData += *(volatile unsigned char *)(uiAddr+i);
				}
				WriteRegister(_CMDREG_2,0,31,uiData);
				//LogPrintf(DBG_MSG, "status address: \n",uiAddr);
				//LogPrintf(DBG_MSG, "status val: \n",uiData);
			}
		    break;

		case SCMD_GETDATA:
			{
				unsigned int uiAddr;
				//unsigned int uiData0 = 0;
				unsigned int uiData = 0;
                int i;
				ReadRegister(_CMDREG_1,0,31,&uiAddr);
				/*if (uiAddr >= (unsigned int)&s_Context && uiAddr < (unsigned int)&s_Context+sizeof(_PQLCONTEXT))
				{
					uiData0 = *(volatile unsigned long *)uiAddr;
				}
 				uiData = 0;
 				for (i = 3; i >= 0; i--) {
 					uiData <<= 8;
 					uiData += (uiData0&0xFF);
					uiData0 >>= 8;
 				}*/
 				uiData = 0;
				for (i = 3; i >= 0; i--) {
					uiData <<= 8;
					uiData += *(volatile unsigned char *)(uiAddr+i);
				}

				WriteRegister(_CMDREG_2,0,31,uiData);
				//LogPrintf(DBG_MSG, "status address: \n",uiAddr);
				//LogPrintf(DBG_MSG, "status val: \n",uiData);
			}
			break;
		case SCMD_SETPARA:
			{
				unsigned int uiAddr;
				unsigned int uiData;
				unsigned int uiShiftData;
				unsigned int uiPackData0;

				ReadRegister(_CMDREG_1,0,31,&uiAddr);
				ReadRegister(_CMDREG_2,0,31,&uiData);

                uiPackData0 = *(volatile unsigned long *)(uiAddr&0xFFFFFFFC);
				//ReadRegister(uiAddr&0xFFFFFFFC,0,31,&uiPackData0);

				switch (uiCmd>>24) {
				case 1: {
					uiShiftData = uiData&0xFF;
					switch (uiAddr&0x3) {
					case 3:
						uiPackData0 &= 0xFFFFFF00;
						uiPackData0 |= uiShiftData;
						break;
					case 2:
						uiPackData0 &= 0xFFFF00FF;
						uiPackData0 |= (uiShiftData<<8);
						break;
					case 1:
						uiPackData0 &= 0xFF00FFFF;
						uiPackData0 |= (uiShiftData<<16);
						break;
					case 0:
						uiPackData0 &= 0xFFFFFF;
						uiPackData0 |= (uiShiftData<<24);
						break;
					}
						}
						break;
				case 2: {
					uiShiftData = ((uiData&0xFF)<<8)|((uiData>>8)&0xFF);
					switch (uiAddr&0x3) {
					case 2:
						uiPackData0 &= 0xFFFF0000;
						uiPackData0 |= uiShiftData;
						break;
					case 0:
						uiPackData0 &= 0xFFFF;
						uiPackData0 |= (uiShiftData<<16);
						break;
					}
						}
						break;
				case 4: {
					uiShiftData = ((uiData&0xFF)<<24)|((uiData&0xFF00)<<8)|((uiData
						&0xFF0000)>>8)|((uiData&0xFF000000)>>24);
					uiPackData0 = uiShiftData;
						}
						break;
				}
				//LogPrintf(DBG_MSG, "para address: \n",uiAddr);
				//LogPrintf(DBG_MSG, "para size: \n",uiCmd>>24);
				//LogPrintf(DBG_MSG, "para val: \n",uiPackData0);
			//	WriteRegister((uiAddr&0xFFFFFFFC),0,31,uiPackData0);

				uiAddr &= 0xFFFFFFFC;
				if (uiAddr >= (unsigned int)s_pParam && uiAddr < (unsigned int)s_pParam+sizeof(_PQLPARAMETER))
				{//protection
				   //WriteRegister((uiAddr&0xFFFFFFFC),0,31,uiPackData0);
				   *(volatile unsigned long *)uiAddr = uiPackData0;
				}
			}
			break;
		}//switch case

		//acknowledgement
		uiCmd &= 0xFF0000;
		uiCmd |= 0x0100;
		WriteRegister(_CMDREG_0,0,31,uiCmd);
	}

	WriteRegister(0x00004510, 0, 31, suiCount);
}

BOOL PQL_GetMEMCActSafeStatus(VOID)
{
	static UINT32 blending_cnt = 0;
	UINT32 blending_mode = 0;
	ReadRegister(KIWI_REG(FRC_TOP__MC__reg_mc_bld_bypass), &blending_mode);

	if (blending_mode == 0)
	{
		if (blending_cnt > 9)
			blending_cnt = 9;
		else
			blending_cnt++;
	}
	else
	{
		blending_cnt = 0;
	}

	if(blending_cnt == 9)
		return TRUE;
	else
		return FALSE;
}
VOID Debug_OnlineMeasure()
{
	UINT32 u32_En = 0;
	UINT32 u32_En_pre = 0;
	
	UINT32 u32_InVtotal = 0,  u32_OutVtotal = 0;
	UINT32 u32_InHtotal = 0,  u32_OutHtotal = 0;
	UINT32 u32_InVact = 0,  u32_OutVact = 0;
	UINT32 u32_InHact = 0,  u32_OutHact = 0;
	UBYTE u8_ErrorFlag = 0;
	UINT32 u32_IzLFData = 0, u32_IzLFLine = 0, u32_IzHFData = 0, u32_IzHFLine = 0;
	UINT32 u32_PzLFData = 0, u32_PzLFLine = 0, u32_PzHFData = 0, u32_PzHFLine = 0;

	static UINT32 pre_InVtotal = 0; 
	static UINT32 pre_OutVtotal = 0;
	static UINT32 pre_InHtotal = 0;
	static UINT32 pre_OutHtotal = 0;
	static UINT32 pre_InVact = 0;
	static UINT32 pre_OutVact = 0;
	static UINT32 pre_InHact = 0;
	static UINT32 pre_OutHact = 0;
	static UINT32 pre_IzLFData = 0;
	static UINT32 pre_IzLFLine = 0;
	static UINT32 pre_IzHFData = 0;
	static UINT32 pre_IzHFLine = 0;
	static UINT32 pre_PzLFData = 0;
	static UINT32 pre_PzLFLine = 0;
	static UINT32 pre_PzHFData = 0;
	static UINT32 pre_PzHFLine = 0;

	UINT32 masterDTG_dh_total, masterDTG_dv_total, uzuDTG_dh_total, uzuDTG_dv_total;
	UINT32 uzuDTG_dh_den_sta, uzuDTG_dh_den_end, uzuDTG_dv_den_sta, uzuDTG_dv_den_end;
	UINT32 memcDTG_dh_total, memcDTG_dv_total;
	UINT32 memc_dh_den_sta, memc_dh_den_end, memc_dv_den_sta, memc_dv_den_end;

	static UINT32 pre_masterDTG_dh_total = 0; 
	static UINT32 pre_masterDTG_dv_total = 0; 
	static UINT32 pre_uzuDTG_dh_total = 0; 
	static UINT32 pre_uzuDTG_dv_total = 0;
	static UINT32 pre_uzuDTG_dh_den_sta = 0; 
	static UINT32 pre_uzuDTG_dh_den_end = 0; 
	static UINT32 pre_uzuDTG_dv_den_sta = 0; 
	static UINT32 pre_uzuDTG_dv_den_end = 0;
	static UINT32 pre_memcDTG_dh_total = 0; 
	static UINT32 pre_memcDTG_dv_total = 0;
	static UINT32 pre_memc_dh_den_sta = 0; 
	static UINT32 pre_memc_dh_den_end = 0; 
	static UINT32 pre_memc_dv_den_sta = 0; 
	static UINT32 pre_memc_dv_den_end = 0;

	UINT32 kme_overflow_error_0, kme_overflow_error_4, kme_overflow_error_5, kme_overflow_error_8, kme_overflow_error_10, kme_overflow_error_12, kme_overflow_error_14;
	UINT32 kmc_00_wram_err, kmc_01_wram_err;

	static UINT32 FrameCnt = 0;
	static UINT32 FirstFrame = 1;//first readback data is wrong, ignore it

	u32_En = 1;
	ReadRegister(KIWI_REG(FRC_TOP__kmc_top__reg_kmc_in_measure_en), &u32_En_pre);
	
	//if(u32_En_pre != u32_En) //fix me
	{
		WriteRegister(FRC_TOP__kmc_top__reg_kmc_in_measure_en_ADDR, 6, 6, u32_En);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_out_measure_en_ADDR, 19, 19, u32_En);

		WriteRegister(FRC_TOP__kmc_top__reg_kmc_in_measure_en_ADDR, 3, 5, 0x7);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_out_measure_en_ADDR, 16, 18, 0x7);

		WriteRegister(FRC_TOP__kmc_top__reg_kmc_in_measure_en_ADDR, 7, 18, 0x121);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_out_measure_en_ADDR, 20, 31, 0x121);
	}
	
	if(u32_En == 1)
	{
	//[MEMC_OnlineMeasure]--------
		ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_vtot_measure), &u32_InVtotal);
		ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_htot_measure), &u32_InHtotal);
		ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_vact_measure), &u32_InVact);
		ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_hact_measure), &u32_InHact);

		ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_vtot_measure), &u32_OutVtotal);
		ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_htot_measure), &u32_OutHtotal);
		ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_vact_measure), &u32_OutVact);
		ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_hact_measure), &u32_OutHact);

		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_lf_get_data_num), &u32_IzLFData);
		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_lf_get_line_num), &u32_IzLFLine);
		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_hf_get_data_num), &u32_IzHFData);
		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_hf_get_line_num), &u32_IzHFLine);
		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_lf_get_data_num), &u32_PzLFData);
		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_lf_get_line_num), &u32_PzLFLine);
		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_hf_get_data_num), &u32_PzHFData);
		ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_hf_get_line_num), &u32_PzHFLine);

	//[MEMC_dtg]-------------
		masterDTG_dh_total = (rtd_inl(0xb802800c)>>16)&0x1FFF;
		masterDTG_dv_total = (rtd_inl(0xb8028014)&0x1FFF);
		uzuDTG_dh_total = (rtd_inl(0xb8028508)&0x1FFF);
		uzuDTG_dv_total = (rtd_inl(0xb8028504)&0x1FFF);

		uzuDTG_dh_den_sta = (rtd_inl(0xb8028518)>>16)&0x1FFF;
		uzuDTG_dh_den_end = (rtd_inl(0xb8028518)&0x1FFF);		
		uzuDTG_dv_den_sta = (rtd_inl(0xb802851c)>>16)&0x1FFF;
		uzuDTG_dv_den_end = (rtd_inl(0xb802851c)&0x1FFF);
		
		memcDTG_dh_total = (rtd_inl(0xb8028608)&0x1FFF);
		memcDTG_dv_total = (rtd_inl(0xb8028604)&0x1FFF);
		memc_dh_den_sta = (rtd_inl(0xb802861c)>>16)&0x1FFF;
		memc_dh_den_end = (rtd_inl(0xb802861c)&0x1FFF);
		memc_dv_den_sta =  (rtd_inl(0xb8028618)>>16)&0x1FFF;
		memc_dv_den_end = (rtd_inl(0xb8028618)&0x1FFF);

	//[MEMC_overflow]-------------
		ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_00_overflow_error), &kme_overflow_error_0);
		ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_04_overflow_error), &kme_overflow_error_4);
		ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_05_overflow_error), &kme_overflow_error_5);
		ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_08_overflow_error), &kme_overflow_error_8);
		ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_10_overflow_error), &kme_overflow_error_10);
		ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_12_overflow_error), &kme_overflow_error_12);
		ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_14_overflow_error), &kme_overflow_error_14);

		ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_00_wram_rw_err), &kmc_00_wram_err);
		ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_01_wram_rw_err), &kmc_01_wram_err);

	}

	if(u32_En == 1 && FirstFrame == 0)
	{		
	//[MEMC_OnlineMeasure]--------
		if((u32_InVtotal <= 0x8b9 || u32_InVtotal>=0x8d9) && (pre_InVtotal != u32_InVtotal))
		{
			printk("[MEMC_OnlineMeasure] MC_InVtotal = %d -> %d, MC_InFrameCnt = %d \r\n", pre_InVtotal, u32_InVtotal, FrameCnt);
			u8_ErrorFlag += (1<<0); 
		}
		if((u32_OutVtotal <= 0x8b9 || u32_OutVtotal>=0x8d9) && ( pre_OutVtotal != u32_OutVtotal))
		{
			printk( "[MEMC_OnlineMeasure] MC_OutVtotal = %d -> %d, MC_OutFrameCnt = %d \r\n", pre_OutVtotal, u32_OutVtotal, FrameCnt);
			u8_ErrorFlag += (1<<1); 
		}
		if((u32_InHtotal <= 0x888 || u32_InHtotal>=0x8a8) && ( pre_InHtotal != u32_InHtotal))
		{
			printk("[MEMC_OnlineMeasure] MC_InHtotal = %d -> %d, MC_InFrameCnt = %d \r\n", pre_InHtotal, u32_InHtotal, FrameCnt);
			u8_ErrorFlag += (1<<2); 
		}
		if((u32_OutHtotal <= 0x43c || u32_OutHtotal>=0x45c) && ( pre_OutHtotal != u32_OutHtotal))
		{
			printk( "[MEMC_OnlineMeasure] MC_OutHtotal = %d -> %d, MC_OutFrameCnt = %d \r\n", pre_OutHtotal, u32_OutHtotal, FrameCnt);
			u8_ErrorFlag += (1<<3); 
		}
		if((u32_InVact <= 0x860 ||u32_InVact>=0x880) && ( pre_InVact != u32_InVact))
		{
			printk("[MEMC_OnlineMeasure] MC_InVact = %d, %d -> MC_InFrameCnt = %d \r\n", pre_InVact, u32_InVact, FrameCnt);
			u8_ErrorFlag += (1<<4); 
		}
		if((u32_OutVact <= 0x860 || u32_OutVact>= 0x880) && ( pre_OutVact != u32_OutVact))
		{
			printk( "[MEMC_OnlineMeasure] MC_OutVact = %d -> %d, MC_OutFrameCnt = %d \r\n", pre_OutVact, u32_OutVact, FrameCnt);
			u8_ErrorFlag += (1<<5); 
		}
		if((u32_InHact <= 0x770 || u32_InHact>=0x790) && ( pre_InHact != u32_InHact))
		{
			printk("[MEMC_OnlineMeasure] MC_InHact = %d -> %d, MC_InFrameCnt = %d \r\n", pre_InHact, u32_InHact, FrameCnt);
			u8_ErrorFlag += (1<<6); 
		}
		if((u32_OutHact <= 0x3b0 || u32_OutHact>= 0x3d0) && (pre_OutHact != u32_OutHact))
		{
			printk( "[MEMC_OnlineMeasure] MC_OutHact = %d -> %d, MC_OutFrameCnt = %d \r\n", pre_OutHact, u32_OutHact, FrameCnt);
			u8_ErrorFlag += (1<<7); 
		}

		if(u8_ErrorFlag > 0)
		{
			printk("[MEMC Online Measure] IzLFDataNum = %d , IzLFLineNum = %d , IzHFDataNum = %d , IzHFLineNum = %d, PzLFDataNum = %d , PzLFLineNum = %d , PzHFDataNum = %d , PzHFLineNum = %d",
				u32_IzLFData, u32_IzLFLine, u32_IzHFData, u32_IzHFLine, u32_PzLFData, u32_PzLFLine, u32_PzHFData, u32_PzHFLine);
		}


		{
			pre_InVtotal = u32_InVtotal; 
			pre_OutVtotal = u32_OutVtotal ;
			pre_InHtotal = u32_InHtotal;
			pre_OutHtotal = u32_OutHtotal;
			pre_InVact = u32_InVact;
			pre_OutVact = u32_OutVact;
			pre_InHact = u32_InHact;
			pre_OutHact = u32_OutHact;
			pre_IzLFData = u32_IzLFData;
			pre_IzLFLine = u32_IzLFLine;
			pre_IzHFData = u32_IzHFData;
			pre_IzHFLine = u32_IzHFLine;
			pre_PzLFData = u32_PzLFData;
			pre_PzLFLine = u32_PzLFLine;
			pre_PzHFData = u32_PzHFData;
			pre_PzHFLine = u32_PzHFLine;
		}
			
	//[MEMC_dtg]-------------		
		if((masterDTG_dh_total<=4383 || masterDTG_dh_total>=4415) && (pre_masterDTG_dh_total != masterDTG_dh_total))
		{
			printk("[MEMC_dtg] masterDTG_dh_total = %d -> %d, FrameCnt = %d \r\n", pre_masterDTG_dh_total, masterDTG_dh_total, FrameCnt);
		}
		
		if((masterDTG_dv_total<=2233 || masterDTG_dv_total>=2265) && (pre_masterDTG_dv_total != masterDTG_dv_total)) 
		{
			printk("[MEMC_dtg] masterDTG_dv_total = %d -> %d, FrameCnt = %d \r\n", pre_masterDTG_dv_total, masterDTG_dv_total, FrameCnt);
		}

		if((uzuDTG_dh_total<=4383 || uzuDTG_dh_total>=4415) && (pre_uzuDTG_dh_total != uzuDTG_dh_total)) 
		{
			printk("[MEMC_dtg] uzuDTG_dh_total = %d -> %d, FrameCnt = %d \r\n", pre_uzuDTG_dh_total, uzuDTG_dh_total, FrameCnt);
		}

		if((uzuDTG_dv_total<=2233 || uzuDTG_dv_total>=2265) && (pre_uzuDTG_dv_total != uzuDTG_dv_total)) 
		{
			printk("[MEMC_dtg] uzuDTG_dv_total = %d -> %d, FrameCnt = %d \r\n", pre_uzuDTG_dv_total, uzuDTG_dv_total, FrameCnt);
		}


		if(((uzuDTG_dh_den_end - uzuDTG_dh_den_sta)<=3824 || (uzuDTG_dh_den_end - uzuDTG_dh_den_sta)>=3856) && ((pre_uzuDTG_dh_den_end - pre_uzuDTG_dh_den_sta) != (uzuDTG_dh_den_end - uzuDTG_dh_den_sta)))
		{
			printk("[MEMC_dtg] uzuDTG_dh_den_sta = %d -> %d, uzuDTG_dh_den_end = %d -> %d, end-sta = %d, FrameCnt = %d \r\n", pre_uzuDTG_dh_den_sta, uzuDTG_dh_den_sta, pre_uzuDTG_dh_den_end, uzuDTG_dh_den_end, uzuDTG_dh_den_end - uzuDTG_dh_den_sta, FrameCnt);
		}


		if(((uzuDTG_dv_den_end-uzuDTG_dv_den_sta)<=2144 || (uzuDTG_dv_den_end-uzuDTG_dv_den_sta)>=2176) && ((pre_uzuDTG_dv_den_end-pre_uzuDTG_dv_den_sta) != (uzuDTG_dv_den_end-uzuDTG_dv_den_sta))) 
		{
			printk("[MEMC_dtg] uzuDTG_dv_den_sta = %d -> %d, uzuDTG_dv_den_end = %d -> %d, end-sta = %d, FrameCnt = %d \r\n", pre_uzuDTG_dv_den_sta, uzuDTG_dv_den_sta, pre_uzuDTG_dv_den_end, uzuDTG_dv_den_end, uzuDTG_dv_den_end-uzuDTG_dv_den_sta, FrameCnt);
		}

		if((memcDTG_dh_total<=4383 || memcDTG_dh_total>=4415) && (pre_memcDTG_dh_total != memcDTG_dh_total))
		{
			printk("[MEMC_dtg] memcDTG_dh_total = %d -> %d, FrameCnt = %d \r\n", pre_memcDTG_dh_total, memcDTG_dh_total, FrameCnt);
		}


		if((memcDTG_dv_total<=2233 || memcDTG_dv_total>=2265) && (pre_memcDTG_dv_total != memcDTG_dv_total))
		{
			printk("[MEMC_dtg] memcDTG_dv_total = %d -> %d, FrameCnt = %d \r\n", pre_memcDTG_dv_total, memcDTG_dv_total, FrameCnt);
		}

		if(((memc_dh_den_end-memc_dh_den_sta)<=3824 || (memc_dh_den_end-memc_dh_den_sta)>=3856) && ((pre_memc_dh_den_end-pre_memc_dh_den_sta) != (memc_dh_den_end-memc_dh_den_sta)))
		{
			printk("[MEMC_dtg] memc_dh_den_sta = %d -> %d, memc_dh_den_end = %d -> %d, end-sta = %d, FrameCnt = %d \r\n", pre_memc_dh_den_sta, memc_dh_den_sta, pre_memc_dh_den_end, memc_dh_den_end, (memc_dh_den_end-memc_dh_den_sta), FrameCnt);
		}

		if(((memc_dv_den_end-memc_dv_den_sta)<=2144 || (memc_dv_den_end-memc_dv_den_sta)>=2176) && ((pre_memc_dv_den_end-pre_memc_dv_den_sta) != (memc_dv_den_end-memc_dv_den_sta)))
		{
			printk("[MEMC_dtg] memc_dv_den_sta = %d -> %d, memc_dv_den_end = %d -> %d, end-sta = %d, FrameCnt = %d \r\n", pre_memc_dv_den_sta, memc_dv_den_sta, pre_memc_dv_den_end, memc_dv_den_end, memc_dv_den_end-memc_dv_den_sta, FrameCnt);
		}

		{
			pre_masterDTG_dh_total = masterDTG_dh_total; 
			pre_masterDTG_dv_total = masterDTG_dv_total; 
			pre_uzuDTG_dh_total = uzuDTG_dh_total; 
			pre_uzuDTG_dv_total = uzuDTG_dv_total;
			pre_uzuDTG_dh_den_sta = uzuDTG_dh_den_sta; 
			pre_uzuDTG_dh_den_end = uzuDTG_dh_den_end;
			pre_uzuDTG_dv_den_sta = uzuDTG_dv_den_sta; 
			pre_uzuDTG_dv_den_end = uzuDTG_dv_den_end;
			pre_memcDTG_dh_total = memcDTG_dh_total; 
			pre_memcDTG_dv_total = memcDTG_dv_total;
			pre_memc_dh_den_sta = memc_dh_den_sta; 
			pre_memc_dh_den_end = memc_dh_den_end; 
			pre_memc_dv_den_sta = memc_dv_den_sta; 
			pre_memc_dv_den_end = memc_dv_den_end;
		}
		
	//[MEMC_overflow]-------------
#if 0//TBD
		static BOOL wram_err_flag = 0;
		UINT32 me1_ip_dummy0_29=0;
		ReadRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_dummy0_ADDR,29,29,&me1_ip_dummy0_29);
		
		if(me1_ip_dummy0_29)
		{
			if(wram_err_flag)
			{
				WriteRegister(FRC_TOP__KMC_DM_TOP__regr_kmc_00_wram_rw_err_ADDR, 6, 7, 1);
				WriteRegister(FRC_TOP__KME_DM_TOP0__regr_kme_00_overflow_error_ADDR, 25, 31, 1);
				wram_err_flag = 0;
			}

			if((kme_overflow_error_0 ||kme_overflow_error_4 ||kme_overflow_error_5 ||
				kme_overflow_error_8 ||kme_overflow_error_10 ||kme_overflow_error_12 ||
				kme_overflow_error_14 ||kmc_00_wram_err || kmc_01_wram_err) && !wram_err_flag)
			{
				extern void smooth_toggle_set_screen_freeze(void);
				smooth_toggle_set_screen_freeze();
				wram_err_flag = 1;
				WriteRegister(FRC_TOP__KMC_DM_TOP__regr_kmc_00_wram_rw_err_ADDR, 6, 7, 0);
				WriteRegister(FRC_TOP__KME_DM_TOP0__regr_kme_00_overflow_error_ADDR, 25, 31, 0);
			}

		}
		else
		{
			wram_err_flag = 0;
		}

		if(me1_ip_dummy0_29)
		{
			if(u8_ErrorFlag)
			{
				extern void smooth_toggle_set_screen_freeze(void);
				smooth_toggle_set_screen_freeze();
			}				
		}
		else
		{
			u8_ErrorFlag = 0;
		}
#endif

		FrameCnt++;
	}
	else if (u32_En == 1 && FirstFrame == 1)
	{
		FirstFrame = 0;
		FrameCnt++;
	}
	else
	{
		FirstFrame = 1;
		FrameCnt = 0;
	}
}


VOID RTICEDebug_OnlineMeasure(UBYTE int_type)
{
	/*
		_BIT31: dump log mode (0: each isr, 1: diff pre value)
		_BIT30 ~ _BIT24: (value*4) of log print timer
		_BIT23: m domain blk print
		
		// DUMP control
		_BIT18: KMC_fail
		_BIT17: KMC_headerfail
		_BIT16: KMV_overflow_error
		_BIT15: KME_overflow_error
		_BIT14: SUB Active Start/End
		_BIT13: SUB Background Start/ENd
		_BIT12: SUB DEN Start/End
		_BIT11: MAIN Active Start/End
		_BIT10: MAIN Background Start/End
		_BIT09: MAIN DEN Start/End
		_BIT08: LBMC HF num
		_BIT07: LBMC LF num
		_BIT06: KPost Out Size
		_BIT05: KMC In Size
		_BIT04: MEMC DEN Start/End
		_BIT03: MEMC DTG Size
		_BIT02: UZU DEN Start/End
		_BIT01: UZU DTG Size
		_BIT00: Master DTG Size
	*/
	UINT32 u32_reg_value = 0;
	UBYTE u8_dump_mode = 0;
	static UINT16 u16_dump_timer = 0;
	UBYTE u1_dump_mdomain_blk = 0;
	static UINT16 blk_repeated_cnt = 0, blk_dropped_cnt = 0;
	
	UBYTE u1_bit00_en = 0;
	UBYTE u1_bit01_en = 0;
	UBYTE u1_bit02_en = 0;
	UBYTE u1_bit03_en = 0;
	UBYTE u1_bit04_en = 0;
	UBYTE u1_bit05_en = 0;
	UBYTE u1_bit06_en = 0;
	UBYTE u1_bit07_en = 0;
	UBYTE u1_bit08_en = 0;
	UBYTE u1_bit09_en = 0;
	UBYTE u1_bit10_en = 0;
	UBYTE u1_bit11_en = 0;
	UBYTE u1_bit12_en = 0;
	UBYTE u1_bit13_en = 0;
	UBYTE u1_bit14_en = 0;
	UBYTE u1_bit15_en = 0;
	UBYTE u1_bit16_en = 0;
	UBYTE u1_bit17_en = 0;
	UBYTE u1_bit18_en = 0;
	
	ReadRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_dummy0_ADDR, 0, 31, &u32_reg_value);

	u8_dump_mode = u32_reg_value>>31;
	if (u16_dump_timer == 0)
	{
		u16_dump_timer = ((u32_reg_value>>24) & 0x7f) * 32;
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_dummy0_ADDR, 24, 30, 0);
		
		blk_repeated_cnt = 0;
		blk_dropped_cnt = 0;
	}
	u1_dump_mdomain_blk = (u32_reg_value>>23) & 0x1;

	u1_bit00_en = (u32_reg_value>>0) & 0x00000001;
	u1_bit01_en = (u32_reg_value>>1) & 0x00000001;
	u1_bit02_en = (u32_reg_value>>2) & 0x00000001;
	u1_bit03_en = (u32_reg_value>>3) & 0x00000001;
	u1_bit04_en = (u32_reg_value>>4) & 0x00000001;
	u1_bit05_en = (u32_reg_value>>5) & 0x00000001;
	u1_bit06_en = (u32_reg_value>>6) & 0x00000001;
	u1_bit07_en = (u32_reg_value>>7) & 0x00000001;
	u1_bit08_en = (u32_reg_value>>8) & 0x00000001;
	u1_bit09_en = (u32_reg_value>>9) & 0x00000001;
	u1_bit10_en = (u32_reg_value>>10) & 0x00000001;
	u1_bit11_en = (u32_reg_value>>11) & 0x00000001;
	u1_bit12_en = (u32_reg_value>>12) & 0x00000001;
	u1_bit13_en = (u32_reg_value>>13) & 0x00000001;
	u1_bit14_en = (u32_reg_value>>14) & 0x00000001;
	u1_bit15_en = (u32_reg_value>>15) & 0x00000001;
	u1_bit16_en = (u32_reg_value>>16) & 0x00000001;
	u1_bit17_en = (u32_reg_value>>17) & 0x00000001;
	u1_bit18_en = (u32_reg_value>>18) & 0x00000001;

	if (u16_dump_timer > 0)
	{
		u16_dump_timer--;

		if (int_type == 0) // input interrupt domain
		{
			if (u1_dump_mdomain_blk)
			{
				UINT32 value, blk_value;
				static UBYTE pre_blk_value, max_blk_value;
				
				RTKReadRegister(0xb8027330, &value);
				blk_value = ((value>>4)&0x3);
				//printk("[M-domain blk]: %d\r\n", blk_value);

				if (blk_value > max_blk_value)
				{
					max_blk_value = blk_value;
				}
				
				if (pre_blk_value == blk_value)
				{
					printk("[M-domain blk]: repeated %d->%d\r\n", pre_blk_value, blk_value);
					blk_repeated_cnt++;
				}

				if ((pre_blk_value!=max_blk_value && (blk_value-pre_blk_value)!=1) || (pre_blk_value==max_blk_value && blk_value!=0))
				{
					printk("[M-domain blk]: dropped %d->%d\r\n", pre_blk_value, blk_value);
					blk_dropped_cnt++;
				}

				pre_blk_value = blk_value;

				if (u16_dump_timer == 0)
				{
					printk("[M-domain blk]: %d repeated\r\n", blk_repeated_cnt);
					printk("[M-domain blk]: %d dropped\r\n", blk_dropped_cnt);
				}
			}
			
			if (u1_bit00_en) // Master DTG Size
			{
				UINT32 value=0, tmp=0, tmp2=0, tmp3=0;
				
				RTKReadRegister(0xb802800c, &value);
				tmp = (value>>16) & 0x1fff;
				tmp2 = value & 0x1fff;
				RTKReadRegister(0xb8028014, &value);
				tmp3 = value & 0x1fff;
				
				printk("[MEMC][Master DTG Size] DH/DH_last_line/DV total: %d, %d, %d\r\n", tmp, tmp2, tmp3);
			}
			
			if (u1_bit01_en) // UZU DTG Size
			{
				UINT32 value=0, tmp=0, tmp2=0, tmp3=0;
				
				RTKReadRegister(0xb8028508, &value);
				tmp = value & 0x1fff;
				tmp2 = (value>>16) & 0x1fff;
				RTKReadRegister(0xb8028504, &value);
				tmp3 = value & 0x1fff;
				
				printk("[MEMC][UZU DTG Size] DH/DH_last_line/DV total: %d, %d, %d\r\n", tmp, tmp2, tmp3);
			}

			if (u1_bit02_en) // UZU DEN Start/End
			{
				UINT32 value=0, tmp=0, tmp2=0, tmp3=0, tmp4=0;
				
				RTKReadRegister(0xb8028518, &value);
				tmp = (value>>16) & 0x1fff;
				tmp2 = value & 0x1fff;
				RTKReadRegister(0xb802851c, &value);
				tmp3 = (value>>16) & 0x1fff;
				tmp4 = value & 0x1fff;
				
				printk("[MEMC][UZU DEN] DH start/end: %d, %d, %d\r\n", tmp, tmp2, (tmp2-tmp));
				printk("[MEMC][UZU DEN] DV start/end: %d, %d, %d\r\n", tmp3, tmp4, (tmp4-tmp3));
			}

			if (u1_bit03_en) // MEMC DTG Size
			{
				UINT32 value=0, tmp=0, tmp2=0, tmp3=0;
				
				RTKReadRegister(0xb8028608, &value);
				tmp = value & 0x1fff;
				tmp2 = (value>>16) & 0x1fff;
				RTKReadRegister(0xb8028604, &value);
				tmp3 = value & 0x1fff;
				
				printk("[MEMC][MEMC DTG Size] DH/DH_last_line/DV total: %d, %d, %d\r\n", tmp, tmp2, tmp3);
			}
			
			if (u1_bit04_en) // MEMC DEN Start/End
			{
				UINT32 value=0, tmp=0, tmp2=0, tmp3=0, tmp4=0;
				
				RTKReadRegister(0xb802861c, &value);
				tmp = (value>>16) & 0x1fff;
				tmp2 = value & 0x1fff;
				RTKReadRegister(0xb8028618, &value);
				tmp3 = (value>>16) & 0x1fff;
				tmp4 = value & 0x1fff;
				
				printk("[MEMC][MEMC DEN] DH start/end: %d, %d, %d\r\n", tmp, tmp2, (tmp2-tmp));
				printk("[MEMC][MEMC DEN] DV start/end: %d, %d, %d\r\n", tmp3, tmp4, (tmp4-tmp3));
			}
			
			if (u1_bit05_en) // KMC In Size
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_hact_measure), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_vact_measure), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_htot_measure), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__kmc_top__regr_kmc_in_vtot_measure), &tmp4);
				
				printk("[MEMC][KMC In Size] hact/vact/htot/vtot %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4);
			}
		}
		else // oututp interrupt domain
		{
			if (u1_bit06_en) // KPost Out Size
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_hact_measure), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_vact_measure), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_htot_measure), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_out_vtot_measure), &tmp4);
				
				printk("[MEMC][KPost Out Size] hact/vact/htot/vtot %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4);
			}
			
			if (u1_bit07_en) // LBMC LF num
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_lf_get_data_num), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_lf_get_line_num), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_lf_get_data_num), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_lf_get_line_num), &tmp4);
				
				printk("[MEMC][LBMC LF num] i_data/i_line/p_data/p_line: %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4);
			}
			
			if (u1_bit08_en) // LBMC HF num
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_hf_get_data_num), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_i_hf_get_line_num), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_hf_get_data_num), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__LBMC__regr_lbmc_p_hf_get_line_num), &tmp4);
				
				printk("[MEMC][LBMC HF num] i_data/i_line/p_data/p_line: %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4);
			}
			
			if (u1_bit09_en) // MAIN DEN Start/End
			{
			}
			if (u1_bit10_en) // MAIN Background Start/End
			{
			}
			if (u1_bit11_en) // MAIN Active Start/End
			{
			}
			if (u1_bit12_en) //  SUB DEN Start/End
			{
			}
			if (u1_bit13_en) // SUB Background Start/ENd
			{
			}
			if (u1_bit14_en) // SUB Active Start/End
			{
			}
			
			if (u1_bit15_en) // KME_overflow_error
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0, tmp5=0, tmp6=0, tmp7=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_00_overflow_error), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_04_overflow_error), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_05_overflow_error), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_08_overflow_error), &tmp4);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_10_overflow_error), &tmp5);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_12_overflow_error), &tmp6);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__regr_kme_14_overflow_error), &tmp7);
				
				printk("[MEMC][KME overflow] 00/04/05/08/10/12/14: %d, %d, %d, %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7);
			}
			
			if (u1_bit16_en) // KMV_overflow_error
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0, tmp5=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__regr_mv01_overflow_error), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__regr_mv02_overflow_error), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__regr_mv04_overflow_error), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__regr_mv05_overflow_error), &tmp4);
				ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__regr_mv12_overflow_error), &tmp5);
				
				printk("[MEMC][KMV overflow] 01/02/04/05/12: %d, %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4, tmp5);
			}
			
			if (u1_bit17_en) // KMC_headerfail
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0, tmp5=0, tmp6=0, tmp7=0, tmp8=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_00_headerfail), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_01_headerfail), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_02_headerfail), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_03_headerfail), &tmp4);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_04_headerfail), &tmp5);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_05_headerfail), &tmp6);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_06_headerfail), &tmp7);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_07_headerfail), &tmp8);
				
				printk("[MEMC][KMC headerfail] 0~8: %d, %d, %d, %d, %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8);
			}
			
			if (u1_bit18_en) // KMC_fail
			{
				UINT32 tmp=0, tmp2=0, tmp3=0, tmp4=0, tmp5=0, tmp6=0, tmp7=0, tmp8=0;
				
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_00_fail), &tmp);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_01_fail), &tmp2);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_02_fail), &tmp3);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_03_fail), &tmp4);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_04_fail), &tmp5);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_05_fail), &tmp6);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_06_fail), &tmp7);
				ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__regr_kmc_07_fail), &tmp8);
				
				printk("[MEMC][KMC fail] 0~8: %d, %d, %d, %d, %d, %d, %d, %d\r\n", tmp, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8);
			}
		}
		

	}

}

