#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"
#include "memc_isr/PQL/FRC_glb_Context.h"
#include <memc_isr/PQL/FBLevelCtrl.h>


VOID SceneChage_Analysis(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FB_static2move_swSC_det(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
void SC_Signal_Proc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);

VOID FBTCCurveCalc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBTCCurve_SC(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBTCCurve_ME(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBTCCurve_GMV(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBGood_Scene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBPan_Scene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBCross_Scene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBLevelCalc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID FBTCCurve_TH_specialScene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);

VOID  fbTC_dhClose_ctrl(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID  fbTC_deBlur_ctrl(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
VOID  fbTC_deJudder_ctrl(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);

UINT32 AutoTh_CurveMapping(UINT32 iVal, UINT32 autoThL, UINT32 autoThH, UBYTE outPrecision);
UINT32 Multiply_2Val_protect(UINT32 multiA, UINT32 multiB, UBYTE divideBit_A);
VOID FBSystemCtrl_Proc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);
//////////////////////////////////////////////////////////////////////////

VOID FBLevelCtrl_Init(_OUTPUT_FBLevelCtrl *pOutput)
{
	UBYTE u8_k = 0;
	for(u8_k = 0; u8_k < 32; u8_k ++)
	{
		pOutput->u25_badRgn_iirRgnSad[u8_k] = 0;
	}
	pOutput->u27_FBTempConsisPre            = 0;
	pOutput->u27_FBTempConsisPre_raw        = 0;

	pOutput->u1_FbLvl_dSCclr                = 0;
	pOutput->u8_FbLvl_dSCclr_holdCnt        = 0;

	pOutput->u8_Dehalo_FBLevel              = 0;
	pOutput->u16_judder_lvl                  = 0;
	pOutput->u16_blur_lvl                    = 0;	
	pOutput->u1_deBlur_gmvU_isGood          = 0;

	pOutput->u8_HW_sc_badFrm_cnt            = 0;
	pOutput->u8_HW_sc_Frm_cnt               = 0;
	pOutput->u1_preFrm_isBadScene           = 0;
	pOutput->u1_swSC_static2move_true       = 0;
	pOutput->u8_swSC_static_frmCnt          = 0;
	pOutput->u8_swSC_disIIR_holdCnt         = 0;

	pOutput->u1_badRgn_rgnSAD_noIIR         = 0;
	pOutput->u1_fbLvl_tc_noIIR              = 0;
	pOutput->u1_fbLvl_result_noIIR          = 0;

	pOutput->u1_sc_signal                   = 0;
	pOutput->u8_sc_bypass_cnt               = 0;
	pOutput->u8_mc_phase_pre                = 0;
	pOutput->u8_static_cnt                  = 0;
}

//Input signal and parameters are connected locally
VOID FBLevelCtrl_Proc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
//	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//LogPrintf(DBG_MSG, "\r\n");

	if (pParam->u1_FBLevelCtrl_en == 1)
	{
		SC_Signal_Proc(pParam, pOutput);

		FB_static2move_swSC_det(pParam, pOutput);
		SceneChage_Analysis(pParam, pOutput);

		{
			UBYTE  u1_bigFBlvl_disIIR = pParam->u1_FbLvl_disIIR_en == 1 && pOutput->u1_FbLvl_dSCclr == 1? 1 : 0;
			UBYTE  u1_SW_sc_disIIR	  = (pOutput->u8_swSC_disIIR_holdCnt > 0)? 1 : 0;
			UBYTE  u1_noIIR_en		  = (pParam->u1_scAnalysis_en == 1)? u1_SW_sc_disIIR : u1_bigFBlvl_disIIR;	

			pOutput->u1_badRgn_rgnSAD_noIIR     = u1_noIIR_en; // for chip, u1_noIIR_en;
			pOutput->u1_fbLvl_tc_noIIR          = 0; // for chip, u1_noIIR_en;
			pOutput->u1_fbLvl_result_noIIR      = u1_noIIR_en; // for chip, u1_noIIR_en;
						                             // because FPGA PC-running is very slow, so there is no need to disable IIR.
		}

		FBTCCurveCalc(pParam, pOutput);

		FBLevelCalc(pParam, pOutput);
	}
	else
	{
	    pOutput->u8_FBLevel = 0;
	}

	// flbk effect ctrl.
	{
		if (pParam->u1_FbLvl_disableSCclr_en == 1)
		{
			UBYTE u1_disable_SCclr_en;
			if (pOutput->u8_FBLevel > pParam->u8_FbLvl_dSCclr_en2d_th)
			{
				u1_disable_SCclr_en = 1;
				pOutput->u8_FbLvl_dSCclr_holdCnt = pParam->u8_FbLvl_dSCclr_holdCnt;
			}
			else if (pOutput->u8_FBLevel < pParam->u8_FbLvl_dSCclr_d2en_th)
			{
				u1_disable_SCclr_en = 0;
				pOutput->u8_FbLvl_dSCclr_holdCnt = pOutput->u8_FbLvl_dSCclr_holdCnt<1? 0 : (pOutput->u8_FbLvl_dSCclr_holdCnt - 1);
			}
			else
			{
				u1_disable_SCclr_en = pOutput->u1_FbLvl_dSCclr;
				pOutput->u8_FbLvl_dSCclr_holdCnt = pOutput->u8_FbLvl_dSCclr_holdCnt<1? 0 : (pOutput->u8_FbLvl_dSCclr_holdCnt - 1);
			}
			pOutput->u1_FbLvl_dSCclr = (u1_disable_SCclr_en || pOutput->u8_FbLvl_dSCclr_holdCnt > 0);
		}
		else
		{
			pOutput->u1_FbLvl_dSCclr = 0;
		}

		pOutput->u3_FbLvl_dSCclr_wrt = (pOutput->u1_FbLvl_dSCclr == 1)? 0 : 1;
	}

	//For system fallback
	FBSystemCtrl_Proc(pParam, pOutput);

}

VOID FBTCCurveCalc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	//const _PQLCONTEXT *s_pContext = GetPQLContext();

	FBTCCurve_SC(pParam, pOutput);

	if (pOutput->u8_SCHoldCnt == 0 && pOutput->u8_SCNormCnt == pParam->u8_SC_NormCnt)
	{
		FBTCCurve_TH_specialScene(pParam, pOutput);
		
		//bad region control
		FBTCCurve_ME(pParam, pOutput);

		//GMV control
		FBTCCurve_GMV(pParam, pOutput);

		FBGood_Scene(pParam, pOutput);

		FBPan_Scene(pParam, pOutput);

		FBCross_Scene(pParam, pOutput);
	}
/*
	// user defined fb level, controled by gain. need overflow protection.
	{
		UBYTE u8_dft_fbLvl_gain      = s_pContext->_external_data.u8_flbk_lvl;
		pOutput->u27_TempConsis_Th_h = (Multiply_2Val_protect(pOutput->u27_TempConsis_Th_h, u8_dft_fbLvl_gain, 8) + 32) >> 6;
		pOutput->u27_TempConsis_Th_l = (Multiply_2Val_protect(pOutput->u27_TempConsis_Th_l, u8_dft_fbLvl_gain, 8) + 32) >> 6;
	}
*/
}

VOID FBTCCurve_SC(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UINT32 u1_sc_status = s_pContext->_output_read_comreg.u1_sc_status_rb;//pOutput->u1_SW_sc_true;

	if (u1_sc_status == 1)
	{
		pOutput->u27_SC_TC_Th_h = (pParam->u27_Fb_tc_th_h * (pParam->u8_SC_Gain)) >> (pParam->u8_SC_slope);
		pOutput->u27_SC_TC_Th_l = (pParam->u27_Fb_tc_th_l * (pParam->u8_SC_Gain)) >> (pParam->u8_SC_slope);

		pOutput->u8_SCHoldCnt = pParam->u8_SC_HoldCnt;
		pOutput->u8_SCNormCnt = 0;
	}
	else if (s_pContext->_output_fblevelctrl.u8_SCHoldCnt != 0)
	{
		pOutput->u8_SCHoldCnt = (s_pContext->_output_fblevelctrl.u8_SCHoldCnt > 1) ? (s_pContext->_output_fblevelctrl.u8_SCHoldCnt-1) : 0;

		pOutput->u27_FBTempConsisPre = 0;
		pOutput->u20_FBPreResult     = 0;
	}
	else if (s_pContext->_output_fblevelctrl.u8_SCNormCnt < pParam->u8_SC_NormCnt)
	{
		UINT32 fb_sc_gain_Norm;
		pOutput->u8_SCNormCnt = pOutput->u8_SCNormCnt + 1;
		fb_sc_gain_Norm       = pParam->u8_SC_Gain * (pParam->u8_SC_NormCnt - pOutput->u8_SCNormCnt) + (1 << pParam->u8_SC_slope) * pOutput->u8_SCNormCnt;

		if(pOutput->u8_SCNormCnt == 0){
			LogPrintf(DBG_WARNING,"[%s]SCNormalCnt is zero!!\n",__FUNCTION__);
			pOutput->u8_SCNormCnt = 1;
		}
		pOutput->u27_SC_TC_Th_h = (Multiply_2Val_protect(pParam->u27_Fb_tc_th_h, fb_sc_gain_Norm, 14) / pParam->u8_SC_NormCnt) >> pParam->u8_SC_slope;
		pOutput->u27_SC_TC_Th_l = (Multiply_2Val_protect(pParam->u27_Fb_tc_th_l, fb_sc_gain_Norm, 14) / pParam->u8_SC_NormCnt) >> pParam->u8_SC_slope;

		//LogPrintf(DBG_MSG, "fb_sc_norm_gain = %d, \r\n", fb_sc_gain_Norm);
		//LogPrintf(DBG_MSG, "sc_th_H = %d, sc_th_L = %d\r\n", pOutput->u27_SC_TC_Th_h, pOutput->u27_SC_TC_Th_l);
	}
	else
	{
		pOutput->u27_SC_TC_Th_h =  pParam->u27_Fb_tc_th_h;
		pOutput->u27_SC_TC_Th_l =  pParam->u27_Fb_tc_th_l;
	}

	pOutput->u27_TempConsis_Th_h = pOutput->u27_SC_TC_Th_h;
	pOutput->u27_TempConsis_Th_l = pOutput->u27_SC_TC_Th_l;
	//LogPrintf(DBG_MSG,"sc_status = %d\n", u1_sc_status);
}

VOID FBTCCurve_TH_specialScene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	//UINT32 u32_RB_val;

	//static UBYTE cnt = 0;

	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 12,15, s_pContext->_output_me_sceneAnalysis.u1_fb_special_chaos_true&&s_pContext->_output_me_sceneAnalysis.u1_chaos_true);

	if( s_pContext->_output_me_sceneAnalysis.u8_chaos_apply != 0)
	{
		pOutput->u27_TempConsis_Th_h = 0x10000;
		pOutput->u27_TempConsis_Th_l = 0x8000;
	}
#if 0
	// GMV
	UINT32 u32_RB_val;
	ReadRegister(0x000040A8, 25, 25, &u32_RB_val);
	if(u32_RB_val)
	{
		printk("Ph=%d: (%d,%d,%d,%d),(%d,%d,%d,%d)\n",
			s_pContext->_output_filmDetectctrl.u8_phase_Idx[_FILM_ALL],
			s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb, s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb, s_pContext->_output_read_comreg.u6_me_GMV_1st_cnt_rb, s_pContext->_output_read_comreg.u12_me_GMV_1st_unconf_rb,
			s_pContext->_output_read_comreg.s11_me_GMV_2nd_vx_rb, s_pContext->_output_read_comreg.s10_me_GMV_2nd_vy_rb, s_pContext->_output_read_comreg.u6_me_GMV_2nd_cnt_rb, s_pContext->_output_read_comreg.u12_me_GMV_2nd_unconf_rb);

	// 32 regions
		printk("[8-11]:(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d)\n", 
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[8],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[8], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[8], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[8],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[8],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[8], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[8], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[8],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[9],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[9], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[9], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[9],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[9],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[9], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[9], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[9],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[10],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[10], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[10], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[10],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[10],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[10], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[10], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[10],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[11],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[11], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[11], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[11],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[11],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[11], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[11], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[11]);
		printk("[12-15]:(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d)\n", 
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[12],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[12], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[12], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[12],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[12],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[12], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[12], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[12],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[13],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[13], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[13], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[13],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[13],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[13], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[13], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[13],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[14],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[14], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[14], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[14],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[14],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[14], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[14], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[14],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[15],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[15], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[15], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[15],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[15],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[15], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[15], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[15]);
		printk("[16-19]:(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d)\n", 
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[16],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[16], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[16], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[16],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[16],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[16], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[16], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[16],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[17],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[17], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[17], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[17],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[17],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[17], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[17], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[17],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[18],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[18], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[18], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[18],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[18],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[18], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[18], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[18],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[19],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[19], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[19], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[19],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[19],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[19], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[19], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[19]);
		printk("[20-23]:(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d);(%d,%d,%d,%d),(%d,%d,%d,%d)\n", 
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[8],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[20], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[20], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[20],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[8],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[20], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[20], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[20],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[9],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[21], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[21], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[21],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[9],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[21], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[21], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[21],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[10],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[22], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[22], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[22],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[10],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[22], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[22], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[22],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[11],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[23], s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[23], s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[23],
			s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[11],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[23], s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[23], s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[23]);
	}
#endif

	/*if(cnt>30)
	{
		cnt = 0;

		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 15, (pOutput->u27_TempConsis_Th_h>>8));
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 31, (pOutput->u27_TempConsis_Th_l>>8));

	}
	else
	{
		cnt++;
	}*/
	
}

VOID FBTCCurve_ME(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE  i, u8_bad_region_cnt_step, u8_BadRegion_cnt = 0;
	UINT16 u16_BadRegion_Gain;
	for (i = 0; i < 32; i ++)
	{
		UINT32 u25_rgnSad_rb = s_pContext->_output_read_comreg.u25_me_rSAD_rb[i];
		UBYTE  u8_rgnSad_iirA = (pOutput->u1_badRgn_rgnSAD_noIIR == 1 || s_pContext->_output_read_comreg.u1_sc_status_rb == 1)? 0 : \
			                    ((u25_rgnSad_rb >= pOutput->u25_badRgn_iirRgnSad[i])? pParam->u8_badRgn_sad_iirA_up : pParam->u8_badRgn_sad_iirA_down);

		pOutput->u25_badRgn_iirRgnSad[i] = _2Val_RndBlending_(pOutput->u25_badRgn_iirRgnSad[i], u25_rgnSad_rb, u8_rgnSad_iirA, 8);
		u8_bad_region_cnt_step = (pOutput->u25_badRgn_iirRgnSad[i] > pParam->u23_BadRegionSAD_th_h)? 3 : \
	                             (pOutput->u25_badRgn_iirRgnSad[i] > pParam->u23_BadRegionSAD_th_m)? 2 : \
							     (pOutput->u25_badRgn_iirRgnSad[i] > pParam->u23_BadRegionSAD_th  )? 1 : 0;

		if (((i >= 10) && (i <= 13)) || ((i >= 18) && (i <= 21)))
		{
			u8_bad_region_cnt_step = u8_bad_region_cnt_step + ((u8_bad_region_cnt_step * pParam->u8_badRgn_center_gain) >>4) + pParam->u8_badRgn_center_oft;
		}

		u8_BadRegion_cnt = _MIN_(u8_BadRegion_cnt + u8_bad_region_cnt_step, 255);
	}

	// calculate gain.
	pOutput->u6_BadRegionCnt  = _CLIP_(u8_BadRegion_cnt, 0, 31);
	if(u8_BadRegion_cnt > 31)
		u8_BadRegion_cnt = 31;	
	u16_BadRegion_Gain        = (pParam->u5_BadRegionGain[u8_BadRegion_cnt] << 4);

//	LogPrintf(DBG_MSG, "fb badRgn_gain = %d\r\n", u16_BadRegion_Gain);
	u16_BadRegion_Gain        = _2Val_RndBlending_(pOutput->u9_BadRegionGainPre, u16_BadRegion_Gain, pParam->u8_BadRegionGainIIR, 8);

	pOutput->u9_BadRegionGainPre = u16_BadRegion_Gain; // u5.4
	pOutput->u5_BadRegionGain    = u16_BadRegion_Gain >> 4;

	pOutput->u5_BadRegionGain    = (pParam->u1_BadRegionCtrl_en == 0)? 16 : _CLIP_UBOUND_(pOutput->u5_BadRegionGain, 16);
	pOutput->u27_TempConsis_Th_h = (pOutput->u27_TempConsis_Th_h * pOutput->u5_BadRegionGain + (1<<3)) >> 4;
	pOutput->u27_TempConsis_Th_l = (pOutput->u27_TempConsis_Th_l * pOutput->u5_BadRegionGain + (1<<3)) >> 4;
}

VOID FBTCCurve_GMV(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE  gmv_gain       = 0;
	SINT32 i;
	UBYTE u8_rmv_cnt = 0, u8_unconf_cnt = 0;
	UBYTE  gmv_ratio      = 128;
	
	for(i = 0; i < 32; i++)
	{
		if(s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > pParam->u12_gmv_rng_cnt_th)
		{
			u8_rmv_cnt++;
		}
		if(s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < pParam->u12_gmv_unconf_cnt_th)
		{
			u8_unconf_cnt++;
		}
	}
	
	if (pParam->u1_gmvratio_use == 0)
	{
			gmv_ratio = _CLIP_(s_pContext->_output_frc_sceneAnalysis.s2m_12_cnt_iir*2, 0 , 127);
	}
	else
	{
			gmv_ratio = _CLIP_(u8_rmv_cnt * u8_unconf_cnt * 127 / 32 / 32, 0 , 127);
	}

	if (gmv_ratio <= pParam->u7_gmv_ratio_thL)
	{
		gmv_gain = pParam->u6_gmv_gain_min;
	}
	else if (gmv_ratio > pParam->u7_gmv_ratio_thH)
	{
		gmv_gain = pParam->u6_gmv_gain_max;
	}
	else
	{
		UINT32 slope = 0;

		if(pParam->u7_gmv_ratio_thH > pParam->u7_gmv_ratio_thL){
			slope = ((pParam->u6_gmv_gain_max-pParam->u6_gmv_gain_min) << 8)/(pParam->u7_gmv_ratio_thH-pParam->u7_gmv_ratio_thL);
		}else{
			LogPrintf(DBG_WARNING,"[%s]Invalid gmv_ratio_th(high:%d,low:%d)!\n",\
					__FUNCTION__,pParam->u7_gmv_ratio_thH,pParam->u7_gmv_ratio_thL);
			slope = ((pParam->u6_gmv_gain_max-pParam->u6_gmv_gain_min) << 8);
		}
		gmv_gain = pParam->u6_gmv_gain_min + (((gmv_ratio-pParam->u7_gmv_ratio_thL)* slope + (1<<7)) >> 8);
	}

	gmv_gain = _CLIP_(gmv_gain, pParam->u6_gmv_gain_min, pParam->u6_gmv_gain_max);

	pOutput->u4_gmv_gain = _2Val_RndBlending_(pOutput->u4_gmv_gain_pre, gmv_gain, pParam->u8_gmv_gain_iir, 8);
	pOutput->u4_gmv_gain = (pParam->u1_FbLvl_gmvCtrl_en == 0)? 16 : pOutput->u4_gmv_gain;

	pOutput->u4_gmv_gain_pre     = pOutput->u4_gmv_gain;
	pOutput->u27_TempConsis_Th_h = (pOutput->u27_TempConsis_Th_h * pOutput->u4_gmv_gain + (1<<3))>>4;
	pOutput->u27_TempConsis_Th_l = (pOutput->u27_TempConsis_Th_l * pOutput->u4_gmv_gain + (1<<3))>>4;

}

VOID FBGood_Scene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	SINT32 i;
	UBYTE u8_GoodRegion_cnt = 0;
	UINT32 ui_Rng_SAD_th = 0, ui_gmv_unconf_th = 0;
	
	for(i = 0; i < 32; i++)
	{
		if(s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP] >= 16)
		{
			if((i >= 0 && i < 8) || (i >= 24 && i < 32))
			{
				ui_Rng_SAD_th = (540 - s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP]) * pParam->u20_good_rgn_sad_th / 540;
				ui_gmv_unconf_th = (540 - s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP]) * pParam->u12_good_rgn_gmv_unconf_th / 540;
			}
			else
			{
				ui_Rng_SAD_th = pParam->u20_good_rgn_sad_th;
				ui_gmv_unconf_th = pParam->u12_good_rgn_gmv_unconf_th;
			}
		}
		else if(s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_LFT] >= 24)
		{
			if((i == 0) || (i == 8) || (i == 16) || (i == 24) || (i == 7) || (i == 15) || (i == 23) || (i == 31))
			{
				ui_Rng_SAD_th = (480 - s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_LFT]) * pParam->u20_good_rgn_sad_th / 480;
				ui_gmv_unconf_th = (480 - s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_LFT]) * pParam->u12_good_rgn_gmv_unconf_th / 480;
			}
			else
			{
				ui_Rng_SAD_th = pParam->u20_good_rgn_sad_th;
				ui_gmv_unconf_th = pParam->u12_good_rgn_gmv_unconf_th;
			}
		}
		else
		{
			ui_Rng_SAD_th = pParam->u20_good_rgn_sad_th;
			ui_gmv_unconf_th = pParam->u12_good_rgn_gmv_unconf_th;
		}
		
		if((s_pContext->_output_read_comreg.u25_me_rSAD_rb[i] < ui_Rng_SAD_th) &&
		   (s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < ui_gmv_unconf_th))
		{
			u8_GoodRegion_cnt++;
		}
	}
	pOutput->u8_good_rgn_cnt = u8_GoodRegion_cnt;
	if(u8_GoodRegion_cnt >= pParam->u8_good_rgn_num_th1)
	{
		pOutput->u8_good_scene_cnt++;
	}
	else
	{
		pOutput->u8_good_scene_cnt = 0;
	}

	if(pOutput->u8_good_scene_cnt > pParam->u4_good_scene_hold_cnt)
	{
		pOutput->u1_good_scene = 1;
	}
	else
	{
		pOutput->u1_good_scene = 0;
	}
	
	if(u8_GoodRegion_cnt <= pParam->u8_good_rgn_num_th2)
	{
		pOutput->u1_bad_scene = 1;
		pOutput->u8_good_scene_cnt = 0;
	}
	else
	{
		pOutput->u1_bad_scene = 0;
	}
	
	if(pOutput->u1_bad_scene)
	{
		pOutput->u8_fblvl_map_y2 = pParam->u8_FBLevelMapY2;
		pOutput->u12_fblvl_iir_up = pParam->u12_FBLevelIIRUp;
	}
	
	if(pOutput->u1_good_scene)
	{
		pOutput->u8_fblvl_map_y2 = pParam->u8_fblvl_map_y2_good;
		pOutput->u12_fblvl_iir_up = pParam->u12_fblvl_iir_up_good;
	}	
}

VOID FBPan_Scene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	SINT16 u11_gmv_mvx = (s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb)>>2;
	SINT16 u10_gmv_mvy = (s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb)>>2;
	UBYTE u6_gmv_cnt = s_pContext->_output_read_comreg.u6_me_GMV_1st_cnt_rb;
	SINT32 s32_mvx_avg = 0, s32_mvy_avg = 0;
	UBYTE i = 0, panx_cnt = 0, pany_cnt = 0;
	
	if ((u6_gmv_cnt>25) && (_ABS_(u11_gmv_mvx)>3 || _ABS_(u10_gmv_mvy)>3))
	{
		for (i = 0; i < 32; i ++)
		{				
			s32_mvx_avg += (s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>>2);
			s32_mvy_avg += (s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>>2);
		}
		s32_mvx_avg = (s32_mvx_avg>>5);
		s32_mvy_avg = (s32_mvy_avg>>5);
		
		for (i = 0; i < 32; i ++)
		{	
			if(_ABS_(u11_gmv_mvx)>3 && _ABS_(s32_mvx_avg-(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>>2))<3)
			{
				panx_cnt++;
			}

			if(_ABS_(u10_gmv_mvy)>3 && _ABS_(s32_mvy_avg-(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>>2))<3)
			{
				pany_cnt++;
			}

		}
	}

	if(panx_cnt>28)
	{
		pOutput->u1_panx_scene = 1;
	}
	else
	{
		pOutput->u1_panx_scene = 0;
	}

	if(pany_cnt>28)
	{
		pOutput->u1_pany_scene = 1;
	}
	else
	{
		pOutput->u1_pany_scene = 0;
	}

	if((pOutput->u1_panx_scene == 1) || (pOutput->u1_pany_scene == 1))
	{
		pOutput->u8_pan_scene_hold_cnt = 5;
	}
	else if(pOutput->u8_pan_scene_hold_cnt != 0)
	{
		pOutput->u8_pan_scene_hold_cnt--;
	}
	else
	{
		pOutput->u8_pan_scene_hold_cnt = 0;
	}

	if(pParam->u1_FB_pan_apply_en)
	{
		if((pOutput->u1_panx_scene == 1 || pOutput->u1_pany_scene == 1) && (pOutput->u27_TempConsis_Th_l <0x8000))
		{
			pOutput->u27_TempConsis_Th_l +=0x2000;
			pOutput->u27_TempConsis_Th_h += 0x80000;
		}		
	}
}

VOID FBCross_Scene(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	
	SINT16 s11_1st_gmv_mvx = (s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb)>>2;
	SINT16 s10_1st_gmv_mvy = (s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb)>>2;
	SCHAR  s6_1st_gmv_cnt  = s_pContext->_output_read_comreg.u6_me_GMV_1st_cnt_rb;
	
	SINT16 s11_2nd_gmv_mvx = (s_pContext->_output_read_comreg.s11_me_GMV_2nd_vx_rb)>>2;
	SINT16 s10_2nd_gmv_mvy = (s_pContext->_output_read_comreg.s10_me_GMV_2nd_vy_rb)>>2;
	SCHAR  s6_2nd_gmv_cnt  = s_pContext->_output_read_comreg.u6_me_GMV_2nd_cnt_rb;
	
	UBYTE cur_pan_cond = 0;
	BOOL u1_pan_status = 0;
	
	if (pOutput->u1_panx_scene || pOutput->u1_pany_scene)
	{
		cur_pan_cond = 255;
	}
	else
	{
		cur_pan_cond = 0;
	}

	if (pOutput->u8_pre_pan_cond > 192)
	{
		u1_pan_status = 1;
	}
	else if (pOutput->u8_pre_pan_cond < 16)
	{
		u1_pan_status = 0;
	}

	if (u1_pan_status == 1 && _ABS_(pOutput->s11_pre_2nd_gmv_mvx - s11_2nd_gmv_mvx) >= 1)
	{
		if (s6_2nd_gmv_cnt >= 2)
		{
			pOutput->u8_cross_scene += 3;
		}
	}
	else
	{
		if (pOutput->u8_cross_scene > 0)
		{
			pOutput->u8_cross_scene--;
		}
	}

	UINT32 u32_i;
	UINT32 bad_conf_num = 0;
	static UINT32 pre_bad_conf_num = 0;
	
	UINT32 u32_rb_val = 0;
	//ReadRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kme_dummy3), &u32_rb_val);
	u32_rb_val = 0x00005AC7;
	UINT32 gmv_1st_2nd_diff_th = (u32_rb_val & 0xF);
	UINT32 bad_conf_num_diff_th = ((u32_rb_val & 0xF0)>>4);
	UINT32 gmv_speed_th = ((u32_rb_val & 0xF00)>>8);
	UINT32 cross_scene_add = ((u32_rb_val & 0xF000)>>12);

	//printk("[MEMC] : %x, %x, %x, %x\n\r", gmv_1st_2nd_diff_th, bad_conf_num_diff_th, gmv_speed_th, cross_scene_add);
	
	for (u32_i = 0; u32_i < 32; u32_i ++)
	{
		if (s_pContext->_output_read_comreg.u20_dh_pfvconf[u32_i] > 0xE000)
		{
			bad_conf_num++;
		}
	}
	
	if (_ABS_(s6_1st_gmv_cnt-s6_2nd_gmv_cnt) <= gmv_1st_2nd_diff_th && pre_bad_conf_num >= bad_conf_num_diff_th)
	{
		if ((s11_1st_gmv_mvx > gmv_speed_th && s11_2nd_gmv_mvx < -gmv_speed_th) || (s11_1st_gmv_mvx < -gmv_speed_th && s11_2nd_gmv_mvx > gmv_speed_th))
		{
			pOutput->u8_cross_scene += cross_scene_add;
		}
	}
	
	pOutput->u8_cross_scene = _CLIP_(pOutput->u8_cross_scene, 0, 48);
	
	BOOL cross_det_en = 1;
	SINT32 slope = 0;
	SINT32 cross_gain = 0, cross_gain_min = 64, cross_gain_max = 256;
	SINT32 cross_thL = 0, cross_thH = 48;
	if (pOutput->u8_cross_scene > 0)
	{
	#if 1

		slope = ((cross_gain_min-cross_gain_max) << 8)/(cross_thH-cross_thL);

		cross_gain = cross_gain_max + (((pOutput->u8_cross_scene-cross_thL) * slope + (1<<7)) >> 8);
		cross_gain = (cross_det_en == 0)? 256 : cross_gain;

		if(pParam->u1_FB_cross_apply_en)
		{
			pOutput->u27_TempConsis_Th_h = (pOutput->u27_TempConsis_Th_h * cross_gain + (1<<7))>>8;
			pOutput->u27_TempConsis_Th_l = (pOutput->u27_TempConsis_Th_l * cross_gain + (1<<7))>>8;
		}
	
	#else
		if (pOutput->u27_TempConsis_Th_l > 0x4000)
		{
			pOutput->u27_TempConsis_Th_l -= 0x4000;
		}
		else
		{
			pOutput->u27_TempConsis_Th_l = 0;
		}

		if (pOutput->u27_TempConsis_Th_h > 0x30000)
		{
			pOutput->u27_TempConsis_Th_h -= 0x30000;
		}
		else
		{
			pOutput->u27_TempConsis_Th_h = 0;
		}
	#endif
	}
	//printk("[MEMC]: %2x:%2x , %2x(%2x) %2x,%2x\n\r", s6_1st_gmv_cnt, s6_2nd_gmv_cnt, bad_conf_num, pre_bad_conf_num, pOutput->u8_cross_scene, cross_gain);

	//printk("[MEMC - %x] %3x,%3x,%3x,%3x\n\r", pOutput->u1_cross_scene, pOutput->u8_pre_2nd_gmv_mvx, u11_2nd_gmv_mvx, pOutput->u8_pre_pan_cond, cur_pan_cond);

	pOutput->u8_pre_pan_cond = (pOutput->u8_pre_pan_cond*224+cur_pan_cond*32)/256;
	pOutput->s11_pre_2nd_gmv_mvx = (pOutput->s11_pre_2nd_gmv_mvx*0+s11_2nd_gmv_mvx*256)/256;
	pre_bad_conf_num = (pre_bad_conf_num*64+bad_conf_num*192)/256;
	
}

VOID FBLevelCalc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();

	// temp consistency mapping u8_FBResult
	{
		// TC limit
		UINT32 u32_rimRatio       = (s_pContext->_output_rimctrl.u32_rimRatio == 0) ? 128 : s_pContext->_output_rimctrl.u32_rimRatio;
		UINT32 u27_mv_tempconsis  = s_pContext->_output_read_comreg.u27_me_aTC_rb * u32_rimRatio >> 7;
		UINT32 u27_mv_tempconsis_limit = 0;
		if(pParam->u1_FB_pan_apply_en)
		{
			u27_mv_tempconsis_limit = (pOutput->u1_panx_scene == 1 || pOutput->u1_pany_scene == 1)? \
				(_MIN_(_MIN_(pParam->u32_FBTempConsis_limit_val,pOutput->u27_FBTempConsisPre_raw*pParam->u8_FBTempConsis_limit_gain>>2), u27_mv_tempconsis)): \
				((u27_mv_tempconsis>pParam->u32_FBTempConsis_limit_val)&&(u27_mv_tempconsis>pOutput->u27_FBTempConsisPre_raw*pParam->u8_FBTempConsis_limit_gain>>2)? \
				_MIN_(pParam->u32_FBTempConsis_limit_val,pOutput->u27_FBTempConsisPre_raw*pParam->u8_FBTempConsis_limit_gain>>2):u27_mv_tempconsis);
		}
		else
		{
			u27_mv_tempconsis_limit = (u27_mv_tempconsis>pParam->u32_FBTempConsis_limit_val)&&
				                        (u27_mv_tempconsis>pOutput->u27_FBTempConsisPre_raw*pParam->u8_FBTempConsis_limit_gain>>2)?
										_MIN_(pParam->u32_FBTempConsis_limit_val,pOutput->u27_FBTempConsisPre_raw*pParam->u8_FBTempConsis_limit_gain>>2):u27_mv_tempconsis;
		}

		// TC iir.
		UBYTE  u8_tc_iirA         =  pOutput->u1_fbLvl_tc_noIIR == 1? 0 : \
			                        (u27_mv_tempconsis_limit > pOutput->u27_FBTempConsisPre? pParam->u8_FBTempConsisIIR_up : pParam->u8_FBTempConsis_IIR_down);
		pOutput->u27_FBTempConsis = _2Val_RndBlending_(pOutput->u27_FBTempConsisPre,u27_mv_tempconsis_limit,u8_tc_iirA,8);
		pOutput->u8_FBResult      = AutoTh_CurveMapping(pOutput->u27_FBTempConsis, pOutput->u27_TempConsis_Th_l, pOutput->u27_TempConsis_Th_h, 16) >> 8;
		
#if 0
		LogPrintf(DBG_MSG, "FB_tc_iirA = %d, sc = %d \r\n", u8_tc_iirA, s_pContext->_output_read_comreg.u1_sc_status_rb);
		LogPrintf(DBG_MSG, "FB_tc_cur = %d, FB_tc_pre = %d \r\n", u27_mv_tempconsis, pOutput->u27_FBTempConsisPre);
#endif

		pOutput->u27_FBTempConsisPre     = pOutput->u27_FBTempConsis;
		pOutput->u27_FBTempConsisPre_raw = u27_mv_tempconsis;
	}

	// option for fastmotion
	{
		UBYTE u1_fastMotion_gfb_en = s_pParam->_param_frc_sceneAnalysis.u1_fastMotion_gfb_en;//((U32_DATA>>30) & 0x1); 

		UBYTE u8_fastMotion_glbfb_min = s_pParam->_param_frc_sceneAnalysis.u8_fastMotion_glbfb_min;//(U32_DATA>>24)&0xff;	
		
		if(s_pContext->_output_frc_sceneAnalysis.u1_fastMotion_det)
		{
			if(u1_fastMotion_gfb_en == 1)
			{
				pOutput->u8_FBResult = (pOutput->u8_FBResult < u8_fastMotion_glbfb_min) ? u8_fastMotion_glbfb_min : (pOutput->u8_FBResult);
			}
		}
	}

	// fb_result IIR
	{
		UINT32 u20_cur_FBResult   = pOutput->u8_FBResult << 12; // u8.12
		UINT16 u12_FBlvl_iirA     = 0;
		if(pParam->u1_FB_pan_apply_en)
		{
		 	u12_FBlvl_iirA     = pOutput->u1_fbLvl_result_noIIR == 1? 0 : \
			                        (pOutput->u8_pan_scene_hold_cnt>0)?(pParam->u12_FBLevelIIRDown):(u20_cur_FBResult > pOutput->u20_FBPreResult? pOutput->u12_fblvl_iir_up : pParam->u12_FBLevelIIRDown);
		}
		else
		{
		 	u12_FBlvl_iirA     = pOutput->u1_fbLvl_result_noIIR == 1? 0 : \
				                        (u20_cur_FBResult > pOutput->u20_FBPreResult? pOutput->u12_fblvl_iir_up : pParam->u12_FBLevelIIRDown);
		}

		u20_cur_FBResult          = _2Val_FlrBlending_(pOutput->u20_FBPreResult, (pOutput->u8_FBResult << 12), u12_FBlvl_iirA, 12);

		pOutput->u20_FBPreResult  = u20_cur_FBResult; // u8.12
		pOutput->u8_FBResult      = (u20_cur_FBResult >> 12) + ((u20_cur_FBResult >> 11) & 0x01); // u8.0, rounding.

#if 0
		LogPrintf(DBG_MSG, "FB_lvl_iirA = %d\r\n", u12_FBlvl_iirA);
		LogPrintf(DBG_MSG, "FB_lvl_cur = %d, FB_lvl_pre = %d, iir_result = %d,8bit_iir = %d, \r\n", u20_FBLevel_Temp, pOutput->u20_FBPreResult, pOutput->u20_FBPreResult, pOutput->u20_FBResult);
#endif
	}

	// other module fall back level calc.
 	fbTC_dhClose_ctrl(pParam, pOutput);

	fbTC_deBlur_ctrl(pParam, pOutput);
	fbTC_deJudder_ctrl(pParam, pOutput);

	//fb_result map to final fb_level
	if (pOutput->u8_FBResult <= pParam->u8_FBLevelMapX1)
	{
		pOutput->u8_FBLevel = 0;
	}
	else if (pOutput->u8_FBResult > pParam->u8_FBLevelMapX2)
	{
		//pOutput->u8_FBLevel = _FB_LEVEL_MAX_;
		pOutput->u8_FBLevel = pOutput->u8_fblvl_map_y2;
	}
	else
	{
		UINT32 u32_slope = 0;

		if(pParam->u8_FBLevelMapX2 > pParam->u8_FBLevelMapX1){
			u32_slope = ((pOutput->u8_fblvl_map_y2-pParam->u8_FBLevelMapY1)<<8)/(pParam->u8_FBLevelMapX2-pParam->u8_FBLevelMapX1);
		}else{
			LogPrintf(DBG_WARNING,"[%s]Invalid FBLevelMapX(x1:%d,x2:%d)!\n",\
				__FUNCTION__,pParam->u8_FBLevelMapX1,pParam->u8_FBLevelMapX2);
			u32_slope = ((pParam->u8_FBLevelMapY2-pParam->u8_FBLevelMapY1)<<8);	
		}
		pOutput->u8_FBLevel = pParam->u8_FBLevelMapY1 + (((pOutput->u8_FBResult-pParam->u8_FBLevelMapX1)*u32_slope)>>8);
	}

	//pOutput->u8_FBLevel = (pOutput->u8_FBLevel > _FB_LEVEL_MAX_) ? _FB_LEVEL_MAX_ : pOutput->u8_FBLevel;
	pOutput->u8_FBLevel = _CLIP_UBOUND_(pOutput->u8_FBLevel, pOutput->u8_fblvl_map_y2);
}

UINT32 AutoTh_CurveMapping(UINT32 iVal, UINT32 autoThL, UINT32 autoThH, UBYTE outPrecision)
{
	UINT32 u32_rtVal = 0;
	if (iVal < autoThL)
	{
		u32_rtVal = 0;
	}
	else if (iVal >= autoThH)
	{
		u32_rtVal = (1 << outPrecision);
	}
	else
	{
		if(autoThH > autoThL){
		u32_rtVal = ((iVal - autoThL) << outPrecision) / (autoThH - autoThL);
		}else{
			LogPrintf(DBG_WARNING,"[%s]Invalid autoThr(H:%d,L:%d)!\n",\
								__FUNCTION__,autoThH,autoThL);
			u32_rtVal = (iVal - autoThL) << outPrecision;
		}
	}

	return u32_rtVal;
}

VOID fbTC_dhClose_ctrl(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	UINT32 u27_tc_thL, u27_tc_thH;
	UBYTE  u8_Dh_FbLvl_cur;
	if (pParam->u1_Fblvl_Dh_tcTh_mapEn == 0)
	{
		u27_tc_thL = pOutput->u27_TempConsis_Th_l;
		u27_tc_thH = pOutput->u27_TempConsis_Th_h;
	}
	else
	{
		u27_tc_thL = pOutput->u27_TempConsis_Th_l*pParam->u8_FbLvl_Dh_tc_thLgain >> 6/*_MIN_(pOutput->u27_TempConsis_Th_l*pParam->u8_FbLvl_Dh_tc_thLgain >> 6, 0x7ffffff)*/;
		u27_tc_thH = pOutput->u27_TempConsis_Th_h*pParam->u8_FbLvl_Dh_tc_thHgain >> 6/*_MIN_(pOutput->u27_TempConsis_Th_h*pParam->u8_FbLvl_Dh_tc_thHgain >> 6, 0x7ffffff)*/;
	}

	u8_Dh_FbLvl_cur            = _MIN_(0xFF, AutoTh_CurveMapping(pOutput->u27_FBTempConsis, u27_tc_thL, u27_tc_thH, 16) >> 8);
	pOutput->u8_Dehalo_FBLevel = _2Val_FlrBlending_(pOutput->u8_Dehalo_FBLevel, u8_Dh_FbLvl_cur, pParam->u8_DehaloFBlvl_iir, 8);

#if 0
	LogPrintf(DBG_MSG, "FB_Dh, TC = %d, thL = %d, thH = %d\r\n", pOutput->u27_FBTempConsis, u27_tc_thL, u27_tc_thH);
	LogPrintf(DBG_MSG, "FB_Dh, 1frm = %d, iir = %d\r\n---------------\r\n", u8_Dh_FbLvl_cur, pOutput->u8_Dehalo_FBLevel);
#endif
}
VOID fbTC_deBlur_ctrl(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 u27_TempConsis_ThL = s_pContext->_output_fblevelctrl.u27_TempConsis_Th_l;
	UINT32 u27_TempConsis_ThH = s_pContext->_output_fblevelctrl.u27_TempConsis_Th_h;
	UINT16 u12_gmv_unconf_rb   = s_pContext->_output_read_comreg.u12_me_GMV_1st_unconf_rb;

	UBYTE  u1_Scene_isGood    = 0;
	UINT16 u16_blur_FBlvl_cur  = 0;
	UINT32 u27_tc_thL         = u27_TempConsis_ThL*pParam->u8_FbLvl_blur_tc_thLgain >> 6/*_CLIP_(u27_TempConsis_ThL*pParam->u8_FbLvl_blur_tc_thLgain >> 6, 0, 0x7ffffff)*/;
	UINT32 u27_tc_thH         = u27_TempConsis_ThH*pParam->u8_FbLvl_blur_tc_thHgain >> 6/*_CLIP_(u27_TempConsis_ThH*pParam->u8_FbLvl_blur_tc_thHgain >> 6, 0, 0x7ffffff)*/;

	u16_blur_FBlvl_cur        = _MIN_(0x80, AutoTh_CurveMapping(pOutput->u27_FBTempConsis, u27_tc_thL, u27_tc_thH, _PHASE_FLBK_LVL_PRECISION));

	if(pOutput->u1_deBlur_gmvU_isGood == 0 && (u12_gmv_unconf_rb <= pParam->u12_FbLvl_blur_gmvUnconf_th0))
	{
		u1_Scene_isGood = 1;
	}
	else if(pOutput->u1_deBlur_gmvU_isGood == 1 && (u12_gmv_unconf_rb >= pParam->u12_FbLvl_blur_gmvUnconf_th1))
	{
		u1_Scene_isGood = 0;
	}
	else
	{
		u1_Scene_isGood = pOutput->u1_deBlur_gmvU_isGood;
	}

	u16_blur_FBlvl_cur              = u1_Scene_isGood == 1? u16_blur_FBlvl_cur : _MAX_(u16_blur_FBlvl_cur, pParam->u5_FbLvl_blur_badscene_dftLvl);
	u16_blur_FBlvl_cur              = _2Val_FlrBlending_(pOutput->u16_blur_lvl, (u16_blur_FBlvl_cur << 4), pParam->u8_FbLvl_blur_iir, 8); // ux.4
	pOutput->u16_blur_lvl           = (pParam->u1_Fblvl_blur_ctrlEn == 1)? u16_blur_FBlvl_cur : 0;
	pOutput->u1_deBlur_gmvU_isGood = u1_Scene_isGood;
}

VOID fbTC_deJudder_ctrl(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	UINT16 u16_judder_FBlvl_cur = 0;
	UINT32 u27_tc_thL = pOutput->u27_TempConsis_Th_l*pParam->u8_FbLvl_judder_tc_thLgain >> 6/*_CLIP_(pOutput->u27_TempConsis_Th_l*pParam->u8_FbLvl_judder_tc_thLgain >> 6, 0, 0x7ffffff)*/;
	UINT32 u27_tc_thH = pOutput->u27_TempConsis_Th_h*pParam->u8_FbLvl_judder_tc_thHgain >> 6/*_CLIP_(pOutput->u27_TempConsis_Th_h*pParam->u8_FbLvl_judder_tc_thHgain >> 6, 0, 0x7ffffff)*/;

	u16_judder_FBlvl_cur     = _MIN_(0x80, AutoTh_CurveMapping(pOutput->u27_FBTempConsis, u27_tc_thL, u27_tc_thH, _PHASE_FLBK_LVL_PRECISION));
	u16_judder_FBlvl_cur     = _2Val_FlrBlending_(pOutput->u16_judder_lvl, (u16_judder_FBlvl_cur<<4), pParam->u8_FbLvl_judder_iir, 8); // UX.4
	pOutput->u16_judder_lvl  = (pParam->u1_Fblvl_judder_ctrlEn == 1)? u16_judder_FBlvl_cur : 0;
}
VOID SceneChage_Analysis(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 u27_tc_rb     = s_pContext->_output_read_comreg.u27_me_aTC_rb;
	UINT32 u28_sadAll_rb = s_pContext->_output_read_comreg.u30_me_aSAD_rb;
	UBYTE u1_HW_sc_true  = pOutput->u1_HW_sc_true || s_pContext->_output_read_comreg.u1_sc_status_rb;

	// frame cnt statistic in current
	UBYTE u1_badScene_true, u8_badFrm_cnt, u8_frm_cnt;
	{
		UBYTE u1_scene_good2bad = u27_tc_rb >= pParam->u27_scAnalysis_TC_th0 || u28_sadAll_rb >= pParam->u28_scAnalysis_sadAll_th0;
		UBYTE u1_scene_bad2good = u27_tc_rb <= pParam->u27_scAnalysis_TC_th1 && u28_sadAll_rb <= pParam->u28_scAnalysis_sadAll_th1;
		u1_badScene_true = _AB_Threshold_Status(pOutput->u1_preFrm_isBadScene, u1_scene_good2bad, u1_scene_bad2good);

		u8_badFrm_cnt = (u1_badScene_true == 1 && u1_HW_sc_true == 1)? (pOutput->u8_HW_sc_badFrm_cnt + 1) :(pOutput->u8_HW_sc_badFrm_cnt);
		u8_frm_cnt    = (u1_HW_sc_true == 1)? pOutput->u8_HW_sc_Frm_cnt + 1 : 0;
	}

	// generate of SW_scene change
	pOutput->u1_SW_sc_true = 0;
	if(u1_HW_sc_true == 1)
	{
		if(u8_frm_cnt == pParam->u4_scAnalysis_frmCnt_th)
		{
			pOutput->u1_SW_sc_true        = u8_badFrm_cnt < pParam->u4_scAnalysis_badFrmCnt_th? 1 : 0;
			pOutput->u1_HW_sc_true        = 0;
			pOutput->u8_HW_sc_badFrm_cnt  = 0;
			pOutput->u8_HW_sc_Frm_cnt     = 0;
			pOutput->u1_preFrm_isBadScene = 0;
		}
		else
		{
			pOutput->u1_SW_sc_true        = 0;
			pOutput->u1_HW_sc_true        = u1_HW_sc_true;
			pOutput->u8_HW_sc_badFrm_cnt  = u8_badFrm_cnt;
			pOutput->u8_HW_sc_Frm_cnt     = u8_frm_cnt;
			pOutput->u1_preFrm_isBadScene = u1_badScene_true;
		}
	}
	else
	{
		pOutput->u1_SW_sc_true        = 0;
		pOutput->u1_HW_sc_true        = 0;
		pOutput->u8_HW_sc_badFrm_cnt  = 0;
		pOutput->u8_HW_sc_Frm_cnt     = 0;
		pOutput->u1_preFrm_isBadScene = 0;
	}

	// status update
	pOutput->u1_SW_sc_true = (pParam->u1_scAnalysis_en == 0)? s_pContext->_output_read_comreg.u1_sc_status_rb : (pOutput->u1_SW_sc_true || pOutput->u1_swSC_static2move_true);

	if(pOutput->u1_SW_sc_true == 1)
	{
		pOutput->u8_swSC_disIIR_holdCnt = pParam->u8_FbLvl_disIIR_holdCnt;
	}
	else
	{
		pOutput->u8_swSC_disIIR_holdCnt = (pOutput->u8_swSC_disIIR_holdCnt > 0)? (pOutput->u8_swSC_disIIR_holdCnt- 1) : 0;
	}
}
VOID FB_static2move_swSC_det(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
#if 0
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 u27_ipme_motion  = s_pContext->_output_read_comreg.u27_fdet_mot_all_rb;
	UBYTE  u8_cadence_phId  = s_pContext->_output_filmDetectctrl.u8_PhaseIdx;
	UBYTE  u8_cadence_Id    = s_pContext->_output_filmDetectctrl.u8_CurCadence;
	UBYTE  u8_staticFrm_cnt = pOutput->u8_swSC_static_frmCnt;
	UBYTE  u1_staticScene_true = 0,u1_cad_motionSeq = 0,u1_curFrame_state = 0;

	if(u8_cadenceId >= _FRC_CADENCE_NUM_){
		LogPrintf(DBG_WARNING,"[%s]Invalid Cadence:%d,Resume to '_CAD_VIDEO'!\n",__FUNCTION__,u8_cadenceId);
		u8_cadenceId = _CAD_VIDEO;	
	}
	u1_staticScene_true = u27_ipme_motion < pParam->u27_scAnalysis_static_motionTh? 1 : 0;
	u1_cad_motionSeq    = cadence_seqFlag(frc_cadTable[u8_cadence_Id], cadence_prePhase(frc_cadTable[u8_cadence_Id],u8_cadence_phId, 1));
	u1_curFrame_state   = u1_cad_motionSeq == 0? 0 : (u1_staticScene_true == 1? 1 : 2); // 0: no consider, 1: static, 2: move

	pOutput->u1_swSC_static2move_true = (u1_curFrame_state == 2 && u8_staticFrm_cnt >= pParam->u8_scAnalysis_st2mo_stPeriodTh)? 1 : 0;
	pOutput->u8_swSC_static_frmCnt    =  u1_curFrame_state == 0? u8_staticFrm_cnt : (u1_curFrame_state == 1? _MIN_(u8_staticFrm_cnt + 1, 255) : 0);
#endif
}


VOID SC_Signal_Proc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
#if 0
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE u1_hw_sc_signal = s_pContext->_output_read_comreg.u1_sc_status_rb;
	UINT32 u8_mc_phase = 0;
	UBYTE  u1_phase_start_en;

	ReadRegister(KIWI_REG(FRC_TOP__MC__regr_mc_phase), &u8_mc_phase);
	u1_phase_start_en = (u8_mc_phase < pOutput->u8_mc_phase_pre) ? 1 : 0;

	if (s_pContext->_output_read_comreg.u27_fdet_mot_all_rb < pParam->u32_static_mot_th)
	{
		pOutput->u8_static_cnt ++;
		pOutput->u8_static_cnt = _CLIP_(pOutput->u8_static_cnt, 0, 30);
	}
	else
	{
		pOutput->u8_static_cnt = 0;
	}


	if (pOutput->u1_sc_signal == 1)
	{
		if (pOutput->u8_sc_bypass_cnt > 0)
		{
			pOutput->u8_sc_bypass_cnt --;
		}
		else
		{
			if (u1_phase_start_en == 1)
			{
				if (pOutput->u8_static_cnt >= pParam->u8_static_cnt_th)
				{
					pOutput->u8_sc_bypass_cnt = pParam->u8_sc_bypass_cnt;
				}
				else
				{
					pOutput->u1_sc_signal = 0;
				}
			}
		}
	}

	if (u1_hw_sc_signal == 1)
	{
		pOutput->u1_sc_signal = 1;
		pOutput->u8_sc_bypass_cnt = pParam->u8_sc_bypass_cnt;
	}

	pOutput->u8_mc_phase_pre = u8_mc_phase;
#endif
}

UINT32 Multiply_2Val_protect(UINT32 multiA, UINT32 multiB, UBYTE divideBit_A)
{
	//multiplication distributive property
	UINT32 multiA_h = multiA >> divideBit_A;
	UINT32 multiA_l = multiA  - (multiA_h << divideBit_A);

	UINT32 multi_h = multiA_h * multiB;
	UINT32 multi_l = multiA_l * multiB;

	// protect.
	UINT32 retV;
	if ((UINT32)(multi_h + (multi_l >> divideBit_A)) > (UINT32)((1 << (32 - divideBit_A)) - 1))
	{
		retV = 0xFFFFFFFF;
	}
	else
	{
		retV = (multi_h << divideBit_A) + multi_l;
	}

	return retV;
}


//Input signal and parameters are connected locally
VOID FBSystemCtrl_Proc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE  u8_flbk_lvl_FrameRepeatMode = 0;
	UBYTE  u8_flbk_lvl_HDR_PicChg = 0;
	UBYTE  u8_flbk_lvl_OSDBrightnessBigChg = 0;
	UBYTE  u8_flbk_lvl_OSDContrastBigChg = 0;
	UBYTE  u8_flbk_lvl_cad = 0;
	UBYTE  u8_flbk_lvl_voseek = 0;
	UBYTE  u8_flbk_lvl_OSDPictureModeChg = 0;
	UBYTE  u8_flbk_lvl_EPG = 0;

	if(s_pContext->_external_data.u8_InputVSXral_FrameRepeatMode > 0)
	{
		u8_flbk_lvl_FrameRepeatMode = _FB_LEVEL_MAX_;
	}

	if(s_pContext->_output_frc_sceneAnalysis.u8_HDR_PicChg_prt_apply > 0)
		u8_flbk_lvl_HDR_PicChg = _FB_LEVEL_MAX_;

	if(s_pContext->_output_frc_sceneAnalysis.u8_OSDBrightnessBigChg_prt_apply > 0)
		u8_flbk_lvl_OSDBrightnessBigChg = _MIN_(_FB_LEVEL_MAX_, (_FB_LEVEL_MAX_/5)*s_pContext->_output_frc_sceneAnalysis.u8_OSDBrightnessBigChg_prt_apply);

	if(s_pContext->_output_frc_sceneAnalysis.u8_OSDContrastBigChg_prt_apply > 0)
		u8_flbk_lvl_OSDContrastBigChg = _MIN_(_FB_LEVEL_MAX_, (_FB_LEVEL_MAX_/5)*s_pContext->_output_frc_sceneAnalysis.u8_OSDContrastBigChg_prt_apply);

	if(s_pContext->_output_filmDetectctrl.u8_flbk_lvl_cad_cnt > 0)
		u8_flbk_lvl_cad = _MIN_(_FB_LEVEL_MAX_, _FB_LEVEL_MAX_*s_pContext->_output_filmDetectctrl.u8_flbk_lvl_cad_cnt/4);

	if(s_pContext->_output_frc_sceneAnalysis.u8_VOSeek_prt_apply > 0)
		u8_flbk_lvl_voseek =  _MIN_(_FB_LEVEL_MAX_*s_pContext->_output_frc_sceneAnalysis.u8_VOSeek_prt_apply/12, _FB_LEVEL_MAX_);

	if(s_pContext->_output_me_sceneAnalysis.u8_EPG_apply > 0)
		u8_flbk_lvl_EPG = _FB_LEVEL_MAX_;

	if((16>=s_pContext->_output_frc_sceneAnalysis.u8_OSDPictureModeChg_prt_apply) && (s_pContext->_output_frc_sceneAnalysis.u8_OSDPictureModeChg_prt_apply>=6))
		u8_flbk_lvl_OSDPictureModeChg = _FB_LEVEL_MAX_;
	if((5>=s_pContext->_output_frc_sceneAnalysis.u8_OSDPictureModeChg_prt_apply) && (s_pContext->_output_frc_sceneAnalysis.u8_OSDPictureModeChg_prt_apply>0))
		u8_flbk_lvl_OSDPictureModeChg = _MIN_(_FB_LEVEL_MAX_, (_FB_LEVEL_MAX_/5)*s_pContext->_output_frc_sceneAnalysis.u8_OSDPictureModeChg_prt_apply);
	pOutput->u8_FBSystem =  _MAX_(_MAX_(_MAX_(_MAX_(_MAX_(_MAX_(_MAX_(u8_flbk_lvl_FrameRepeatMode
							, u8_flbk_lvl_HDR_PicChg)
							, u8_flbk_lvl_OSDBrightnessBigChg)
							, u8_flbk_lvl_OSDContrastBigChg)
							, u8_flbk_lvl_cad)
							, u8_flbk_lvl_voseek)
		                                   , u8_flbk_lvl_EPG)
							, u8_flbk_lvl_OSDPictureModeChg);
	                                                         
}






