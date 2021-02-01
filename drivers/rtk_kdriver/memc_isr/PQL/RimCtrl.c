#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"
///////////////////////////////////////////////////////////////////////////////////////////
VOID RimCtrl_OutResolution_Parse(_OUTPUT_RimCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext   = GetPQLContext();
	PQL_OUTPUT_RESOLUTION outResolution_cur = s_pContext->_external_data._output_resolution;
	pOutput->u1_Resolution_change = 0;

	if (outResolution_cur != (PQL_OUTPUT_RESOLUTION)pOutput->u4_outResolution_pre)
	{
		pOutput->u4_outResolution_pre = outResolution_cur;
		pOutput->u1_Resolution_change = 1;

		switch (outResolution_cur)
		{
		case _PQL_OUT_1920x1080 :
			pOutput->u12_out_resolution[_RIM_LFT] = 0;
			pOutput->u12_out_resolution[_RIM_RHT] = 1919;
			pOutput->u12_out_resolution[_RIM_TOP] = 0;
			pOutput->u12_out_resolution[_RIM_BOT] = 1079;
			break;
		case _PQL_OUT_1920x540:
			pOutput->u12_out_resolution[_RIM_LFT] = 0;
			pOutput->u12_out_resolution[_RIM_RHT] = 1919;
			pOutput->u12_out_resolution[_RIM_TOP] = 0;
			pOutput->u12_out_resolution[_RIM_BOT] = 539;
			break;
		case _PQL_OUT_3840x2160:
			pOutput->u12_out_resolution[_RIM_LFT] = 0;
			pOutput->u12_out_resolution[_RIM_RHT] = 3839;
			pOutput->u12_out_resolution[_RIM_TOP] = 0;
			pOutput->u12_out_resolution[_RIM_BOT] = 2159;
			break;
		case _PQL_OUT_3840x1080:
			pOutput->u12_out_resolution[_RIM_LFT] = 0;
			pOutput->u12_out_resolution[_RIM_RHT] = 3839;
			pOutput->u12_out_resolution[_RIM_TOP] = 0;
			pOutput->u12_out_resolution[_RIM_BOT] = 1079;
			break;
		case _PQL_OUT_3840x540:
			pOutput->u12_out_resolution[_RIM_LFT] = 0;
			pOutput->u12_out_resolution[_RIM_RHT] = 3839;
			pOutput->u12_out_resolution[_RIM_TOP] = 0;
			pOutput->u12_out_resolution[_RIM_BOT] = 539;
			break;
		default: //_PQL_OUT_3840x2160
			pOutput->u12_out_resolution[_RIM_LFT] = 0;
			pOutput->u12_out_resolution[_RIM_RHT] = 3839;
			pOutput->u12_out_resolution[_RIM_TOP] = 0;
			pOutput->u12_out_resolution[_RIM_BOT] = 2159;
			break;
		}
	}
}

VOID RimCtrl_HW_extract(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UINT16 u12_BBD_roughRim[_RIM_NUM], u12_BBD_fineRim[_RIM_NUM], u12_det_Rim[_RIM_NUM], u12_rim_bound[_RIM_NUM];
	UBYTE  u1_BBD_roughValid[_RIM_NUM], u1_BBD_fineValid[_RIM_NUM];
	UBYTE  u8_k;
	UBYTE  apl_avg = 0;
	UBYTE  logo_rim_unbalance;

	// copy data.
	for (u8_k = 0; u8_k < _RIM_NUM; u8_k ++)
	{
		u12_BBD_roughRim[u8_k]  = s_pContext->_output_read_comreg.u12_BBD_roughRim_rb[u8_k];
		u1_BBD_roughValid[u8_k] = s_pContext->_output_read_comreg.u1_BBD_roughValid_rb[u8_k];
		u12_BBD_fineRim[u8_k]   = s_pContext->_output_read_comreg.u12_BBD_fineRim_rb[u8_k];
		u1_BBD_fineValid[u8_k]  = s_pContext->_output_read_comreg.u1_BBD_fineValid_rb[u8_k];
	}

	u12_rim_bound[_RIM_LFT] = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_1920x540) ? 320:  640; // else, Hactive = 3840.
	u12_rim_bound[_RIM_RHT] = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_1920x540) ? 1600:  3200;

	u12_rim_bound[_RIM_TOP] = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_3840x1080)?  180 :
		                      (pOutput->u4_outResolution_pre == _PQL_OUT_3840x2160)?  360 : 90; // else, Vactive = 540.
	u12_rim_bound[_RIM_BOT] = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_3840x1080) ? 900 :
		                      (pOutput->u4_outResolution_pre == _PQL_OUT_3840x2160)? 1800 : 450;

	// rim source select.
	for (u8_k = 0; u8_k < _RIM_NUM; u8_k ++)
	{

		UINT16 u12_roughRim = (u8_k == _RIM_TOP || u8_k == _RIM_BOT)? u12_BBD_roughRim[u8_k] :
			                  (u8_k == _RIM_LFT? (u12_BBD_roughRim[u8_k] * _Rim_Hor_Bin_) : (u12_BBD_roughRim[u8_k] * _Rim_Hor_Bin_ + _Rim_Hor_Bin_ - 1));


		u12_det_Rim[u8_k] = u1_BBD_fineValid[u8_k] == 1? u12_BBD_fineRim[u8_k] :
			               (u1_BBD_roughValid[u8_k] == 1? u12_roughRim : pOutput->u12_out_resolution[u8_k]);
	}

	// logo unbalance
	if ((u12_det_Rim[_RIM_TOP] >= pParam->u12_Logo_Rim_Top_thr) && (u12_det_Rim[_RIM_TOP] > pOutput->u12_out_resolution[_RIM_BOT] - u12_det_Rim[_RIM_BOT] +  pParam->u12_RimDiffTh/4))
	{
		logo_rim_unbalance = 1;
	}
	else
	{
		logo_rim_unbalance = 0;
	}

	if (logo_rim_unbalance == 1)
	{
		pOutput->u1_LogoRim_unbalace = 1;
		pOutput->u8_Logo_Rim_unbalace_holdfrm = pParam->u8_Logo_Rim_unbalace_holdfrm;
	}
	else if (pOutput->u8_Logo_Rim_unbalace_holdfrm > 0)
	{
		pOutput->u1_LogoRim_unbalace = 1;
		pOutput->u8_Logo_Rim_unbalace_holdfrm = pOutput->u8_Logo_Rim_unbalace_holdfrm - 1;
	} 
	else
	{
		pOutput->u1_LogoRim_unbalace = 0;
		pOutput->u8_Logo_Rim_unbalace_holdfrm = 0;
	}

	// Rim qualified for Two-side balancing.
	// Vertical
	if (pOutput->u12_out_resolution[_RIM_BOT] - u12_det_Rim[_RIM_BOT] > u12_det_Rim[_RIM_TOP] +  pParam->u12_RimDiffTh)
	{
		u12_det_Rim[_RIM_BOT] = pOutput->u12_out_resolution[_RIM_BOT] - u12_det_Rim[_RIM_TOP];
	}
	else if (u12_det_Rim[_RIM_TOP] > pOutput->u12_out_resolution[_RIM_BOT] - u12_det_Rim[_RIM_BOT] +  pParam->u12_RimDiffTh)
	{
		u12_det_Rim[_RIM_TOP] = pOutput->u12_out_resolution[_RIM_BOT] - u12_det_Rim[_RIM_BOT];
	}

	// Hortizontal
	if (pOutput->u12_out_resolution[_RIM_RHT] - u12_det_Rim[_RIM_RHT] > u12_det_Rim[_RIM_LFT] + pParam->u12_RimDiffTh)
	{
		u12_det_Rim[_RIM_RHT] = pOutput->u12_out_resolution[_RIM_RHT] - u12_det_Rim[_RIM_LFT];
	}
	else if (u12_det_Rim[_RIM_LFT] > pOutput->u12_out_resolution[_RIM_RHT] - u12_det_Rim[_RIM_RHT] + pParam->u12_RimDiffTh)
	{
		u12_det_Rim[_RIM_LFT] = pOutput->u12_out_resolution[_RIM_RHT] - u12_det_Rim[_RIM_RHT];
	}

	// bound protect.
	//pOutput->u12_Rim_Cur[_RIM_LFT] = (u12_det_Rim[_RIM_LFT] >= u12_rim_bound[_RIM_LFT])? pOutput->u12_Rim_Pre[_RIM_LFT] : u12_det_Rim[_RIM_LFT];
	//pOutput->u12_Rim_Cur[_RIM_RHT] = (u12_det_Rim[_RIM_RHT] <= u12_rim_bound[_RIM_RHT])? pOutput->u12_Rim_Pre[_RIM_RHT] : u12_det_Rim[_RIM_RHT];
	//pOutput->u12_Rim_Cur[_RIM_TOP] = (u12_det_Rim[_RIM_TOP] >= u12_rim_bound[_RIM_TOP])? pOutput->u12_Rim_Pre[_RIM_TOP] : u12_det_Rim[_RIM_TOP];
	//pOutput->u12_Rim_Cur[_RIM_BOT] = (u12_det_Rim[_RIM_BOT] <= u12_rim_bound[_RIM_BOT])? pOutput->u12_Rim_Pre[_RIM_BOT] : u12_det_Rim[_RIM_BOT];

	pOutput->u12_Rim_Cur[_RIM_LFT] = (u12_det_Rim[_RIM_LFT] >= u12_rim_bound[_RIM_LFT])? pOutput->u12_out_resolution[_RIM_LFT] : u12_det_Rim[_RIM_LFT];
	pOutput->u12_Rim_Cur[_RIM_RHT] = (u12_det_Rim[_RIM_RHT] <= u12_rim_bound[_RIM_RHT])? pOutput->u12_out_resolution[_RIM_RHT] : u12_det_Rim[_RIM_RHT];
	pOutput->u12_Rim_Cur[_RIM_TOP] = (u12_det_Rim[_RIM_TOP] >= u12_rim_bound[_RIM_TOP])? pOutput->u12_out_resolution[_RIM_TOP] : u12_det_Rim[_RIM_TOP];
	pOutput->u12_Rim_Cur[_RIM_BOT] = (u12_det_Rim[_RIM_BOT] <= u12_rim_bound[_RIM_BOT])? pOutput->u12_out_resolution[_RIM_BOT] : u12_det_Rim[_RIM_BOT];


	//for 
	if ((_ABS_(pOutput->u12_Rim_Cur[_RIM_RHT] - pOutput->u12_Rim_Cur[_RIM_LFT]) < _ABS_(pOutput->u12_Rim_Cur[_RIM_BOT] - pOutput->u12_Rim_Cur[_RIM_TOP])*4/5) &&
		(pParam->u1_RimAbNoramlProcEn == 1))
	{
		pOutput->u12_Rim_Cur[_RIM_LFT] =  pOutput->u12_out_resolution[_RIM_LFT];
		pOutput->u12_Rim_Cur[_RIM_RHT] =  pOutput->u12_out_resolution[_RIM_RHT];
		pOutput->u12_Rim_Cur[_RIM_TOP] =  pOutput->u12_out_resolution[_RIM_TOP];
		pOutput->u12_Rim_Cur[_RIM_BOT] =  pOutput->u12_out_resolution[_RIM_BOT];
	}
	
	if ((pParam->u1_RimAllBlackProcEn == 1))
	{
		//need change to any blocknum case.
		apl_avg = (s_pContext->_output_read_comreg.u26_me_aAPLi_rb + s_pContext->_output_read_comreg.u26_me_aAPLp_rb)/(240*135*2);
		if (apl_avg < pParam->u8_RimAllBlackThr)
		{
			pOutput->u12_Rim_Cur[_RIM_LFT] =  pOutput->u12_out_resolution[_RIM_LFT];
			pOutput->u12_Rim_Cur[_RIM_RHT] =  pOutput->u12_out_resolution[_RIM_RHT];
			pOutput->u12_Rim_Cur[_RIM_TOP] =  pOutput->u12_out_resolution[_RIM_TOP];
			pOutput->u12_Rim_Cur[_RIM_BOT] =  pOutput->u12_out_resolution[_RIM_BOT];
		}
	}
}

VOID RimCtrl_FastOut(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
/*	const _PQLCONTEXT *s_pContext = GetPQLContext();*/

	int i = 0;
	for (i = 0; i < _RIM_NUM; i ++)
	{
		if (i == _RIM_LFT || i == _RIM_TOP)
		{
			if (pOutput->u12_Rim_Cur[i] < pOutput->u12_Rim_Pre[i])
			{
				pOutput->s8_BiggerCnt[i] =  pOutput->s8_BiggerCnt[i]+1;
			}
			else
			{
				pOutput->s8_BiggerCnt[i] =  _MAX_((pOutput->s8_BiggerCnt[i]-2), 0);
			}

		}
		else // if (i == _RIM_RHT || i == _RIM_BOT)
		{
			if (pOutput->u12_Rim_Cur[i] > pOutput->u12_Rim_Pre[i])
			{
				pOutput->s8_BiggerCnt[i] = pOutput->s8_BiggerCnt[i]+1;
			}
			else
			{
				pOutput->s8_BiggerCnt[i] = _MAX_((pOutput->s8_BiggerCnt[i]-2),0);
			}
		}

		// if change rim?
		if (pOutput->s8_BiggerCnt[i] >= pParam->u8_RimBiggerTh)
		{
			pOutput->u12_Rim_Result[i] = pOutput->u12_Rim_Cur[i];
			pOutput->u1_RimChange      = 1;
			pOutput->s8_BiggerCnt[i]   = 0;
		}
	}
}

VOID RimCtrl_SlowIn(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	int i = 0;
	UINT16 u16_rim_diff = 0;
	UBYTE  u8_thr_coef = 1;
	UBYTE  u8_dyn_thr;
	UBYTE  u8_rim_iir = 0;
	static UBYTE u8_sc_cnt = 0;
	
	for (i = 0; i < _RIM_NUM; i ++)
	{
		if (i < 2)
		{
			u16_rim_diff = _ABS_(pOutput->u12_Rim_Cur[_RIM_TOP] - (pOutput->u12_out_resolution[_RIM_BOT]-pOutput->u12_Rim_Cur[_RIM_BOT]));
		}
		else
		{
		    u16_rim_diff = _ABS_(pOutput->u12_Rim_Cur[_RIM_LFT] - (pOutput->u12_out_resolution[_RIM_RHT]-pOutput->u12_Rim_Cur[_RIM_RHT]));
		}
	   
		if (i == _RIM_LFT || i == _RIM_TOP)
		{
//			if (pOutput->u12_Rim_Cur[i] > pOutput->u12_Rim_Pre[i] && (u16_rim_diff < 8 || pOutput->s8_StableCnt[i] > 30))
			if (pOutput->u12_Rim_Cur[i] > pOutput->u12_Rim_Pre[i])
			{
				pOutput->s8_SmallerCnt[i] = _CLIP_(pOutput->s8_SmallerCnt[i]+1,-128,126);
			}
			else
			{
				pOutput->s8_SmallerCnt[i] = _MAX_((pOutput->s8_SmallerCnt[i]-2),0);
			}

		}
		else // if (i == _RIM_RHT || i == _RIM_BOT)
		{
//			if (pOutput->u12_Rim_Cur[i] < pOutput->u12_Rim_Pre[i] && (u16_rim_diff < 8 || pOutput->s8_StableCnt[i] > 24))
			if (pOutput->u12_Rim_Cur[i] < pOutput->u12_Rim_Pre[i])
			{
				pOutput->s8_SmallerCnt[i] = _CLIP_(pOutput->s8_SmallerCnt[i]+1,-128,126);
			}
			else
			{
				pOutput->s8_SmallerCnt[i] = _MAX_((pOutput->s8_SmallerCnt[i]-2),0);
			}
		}

		
		//dynamic  thr.
		u8_thr_coef = (u16_rim_diff < 20) ? 1: ((u16_rim_diff < 45) ? 4 : 8);
		
		if (i < 2)
		{
			u8_thr_coef=1;   //default u_thr_coef need consider again.
		}
		else  // right/left
		{
			u8_thr_coef= (1<<pParam->u5_RimLRSmallShift);
		}

		// if change rim
		UBYTE u1_Hist_SC_flg;
		u1_Hist_SC_flg = (s_pContext->_external_info.u1_Hist_SC_flg == 1) ? 1 :0;

//		if (s_pContext->_output_read_comreg.u1_sc_status_rb == 1)
		if (u1_Hist_SC_flg == 1)
		{
			u8_dyn_thr = pParam->u8_RimSmallerSCTh*u8_thr_coef;
			u8_sc_cnt = 10;
		}
		else
		{
			u8_dyn_thr = pParam->u8_RimSmallerTh*u8_thr_coef;
			if (u8_sc_cnt > 0)
			{
				u8_sc_cnt--;
			}
		}

		if (pOutput->s8_SmallerCnt[i] >= u8_dyn_thr /*pParam->u8_RimSmallerTh*/)
		{
			u8_rim_iir = pParam->u8_RimIIRAlpha;
			if (u8_sc_cnt > 0)
			{
//				if ((i == _RIM_TOP && (pOutput->u12_Rim_Result[i] < (pOutput->u12_out_resolution[_RIM_TOP]+8))) || (i == _RIM_BOT && (pOutput->u12_Rim_Result[i] > (pOutput->u12_out_resolution[_RIM_BOT]-8))))
				if ((i == _RIM_TOP) || (i == _RIM_BOT))
				{
					u8_rim_iir = 0;
				}
			}
			
			pOutput->u12_Rim_Result[i] = _2Val_FlrBlending_(pOutput->u12_Rim_Pre[i], pOutput->u12_Rim_Cur[i], u8_rim_iir, 8);
			pOutput->u1_RimChange      = 1;
			pOutput->s8_SmallerCnt[i]  = 0;
		}
	}
}


VOID RimCtrl_Dynamic_OfstCalc(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 me2_pix_rim_slp = 0;
	UINT32 mc_pix_rim_slp  = 0;
	UBYTE  cur_is_sc       = 0;
	
	if (s_pContext->_output_read_comreg.u1_sc_status_rb == 1)
	{
		cur_is_sc				= 1;
		pOutput->rim_sc_holdcnt = pParam->dyn_sc_holdcnt;
	}
	else if (pOutput->rim_sc_holdcnt > 0)
	{
		cur_is_sc				= 1;
		pOutput->rim_sc_holdcnt = pOutput->rim_sc_holdcnt - 1;
	}
	else
	{
		cur_is_sc				= 0;
		pOutput->rim_sc_holdcnt = 0;
	}

	pOutput->u1_insidePan_Cond = 0;
	if (s_pContext->_output_frc_sceneAnalysis.u8_is_insidePan == 1 && pParam->u1_dynRim_insidePan_en == 1 && cur_is_sc == 0 && s_pContext->_output_frc_sceneAnalysis.u8_is_insidePanX == 1)  //scoreboard, ...
	{
		me2_pix_rim_slp      = (pParam->dyn_pan_me2prim_max - pParam->dyn_pan_me2prim_min) * 1024 / (pParam->dyn_pan_gmv_max-pParam->dyn_pan_gmv_min);  
		mc_pix_rim_slp       = (pParam->dyn_pan_mcprim_max - pParam->dyn_pan_mcprim_min) * 1024 / (pParam->dyn_pan_gmv_max-pParam->dyn_pan_gmv_min); 
		pOutput->me2_oor_cnt = pParam->dyn_pan_oor_cnt;	
		pOutput->me2_pix_rim_shrink[_RIM_LFT] = _IncreaseCurveMapping(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgAbsMVX,
												pParam->dyn_pan_gmv_min, pParam->dyn_pan_me2prim_min, pParam->dyn_pan_me2prim_max, me2_pix_rim_slp,10);
		pOutput->me2_pix_rim_shrink[_RIM_RHT] = pOutput->me2_pix_rim_shrink[_RIM_LFT];
		pOutput->me2_pix_rim_shrink[_RIM_TOP] = _IncreaseCurveMapping(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgAbsMVY,
												pParam->dyn_pan_gmv_min, pParam->dyn_pan_me2prim_min, pParam->dyn_pan_me2prim_max, me2_pix_rim_slp,10);
		pOutput->me2_pix_rim_shrink[_RIM_BOT] = pOutput->me2_pix_rim_shrink[_RIM_TOP];

		pOutput->mc_pix_rim_shrink[_RIM_LFT]  = _IncreaseCurveMapping(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgAbsMVX,
												pParam->dyn_pan_gmv_min, pParam->dyn_pan_mcprim_min, pParam->dyn_pan_mcprim_max, mc_pix_rim_slp,10);
		pOutput->mc_pix_rim_shrink[_RIM_RHT]  = pOutput->mc_pix_rim_shrink[_RIM_LFT];
		pOutput->mc_pix_rim_shrink[_RIM_TOP]  = _IncreaseCurveMapping(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgAbsMVY,
												pParam->dyn_pan_gmv_min, pParam->dyn_pan_mcprim_min, pParam->dyn_pan_mcprim_max, mc_pix_rim_slp,10);
		pOutput->mc_pix_rim_shrink[_RIM_BOT]  = pOutput->mc_pix_rim_shrink[_RIM_TOP];

		pOutput->u1_insidePan_Cond = 1;
	}
	else if (s_pContext->_output_frc_sceneAnalysis.u1_is_saddiff_large ==1 && pParam->u1_dynRim_ScBdy_en == 1) //sc boundary garbage
	{
		pOutput->me2_oor_cnt = pParam->dyn_scbdy_oor_cnt;	
		pOutput->me2_pix_rim_shrink[_RIM_LFT] = pParam->dyn_scbdy_me2prim;
		pOutput->me2_pix_rim_shrink[_RIM_RHT] =	pParam->dyn_scbdy_me2prim;
		pOutput->me2_pix_rim_shrink[_RIM_TOP] =	pParam->dyn_scbdy_me2prim;
		pOutput->me2_pix_rim_shrink[_RIM_BOT] =	pParam->dyn_scbdy_me2prim;
		pOutput->mc_pix_rim_shrink[_RIM_LFT]  = pParam->dyn_scbdy_mcprim;
		pOutput->mc_pix_rim_shrink[_RIM_RHT]  =	pParam->dyn_scbdy_mcprim;
		pOutput->mc_pix_rim_shrink[_RIM_TOP]  =	pParam->dyn_scbdy_mcprim;
		pOutput->mc_pix_rim_shrink[_RIM_BOT]  =	pParam->dyn_scbdy_mcprim;
	}
	else if( s_pContext->_output_frc_sceneAnalysis.u1_is_BdySmall_MV == 1 && pParam->u1_dynRim_SmlBdy_en == 1 && cur_is_sc == 0) //cheeta, set to 7, 0
	{
		pOutput->me2_oor_cnt = pParam->dyn_smlbdy_oor_cnt;	
		pOutput->me2_pix_rim_shrink[_RIM_LFT] = pParam->dyn_smlbdy_me2prim;
		pOutput->me2_pix_rim_shrink[_RIM_RHT] =	pParam->dyn_smlbdy_me2prim;
		pOutput->me2_pix_rim_shrink[_RIM_TOP] =	pParam->dyn_smlbdy_me2prim;
		pOutput->me2_pix_rim_shrink[_RIM_BOT] =	pParam->dyn_smlbdy_me2prim;
		pOutput->mc_pix_rim_shrink[_RIM_LFT]  = pParam->dyn_smlbdy_mcprim;
		pOutput->mc_pix_rim_shrink[_RIM_RHT]  =	pParam->dyn_smlbdy_mcprim;
		pOutput->mc_pix_rim_shrink[_RIM_TOP]  =	pParam->dyn_smlbdy_mcprim;
		pOutput->mc_pix_rim_shrink[_RIM_BOT]  =	pParam->dyn_smlbdy_mcprim;		
	}
	else  // set to 7, 0.
	{
		pOutput->me2_oor_cnt = pParam->dyn_general_oor_cnt;	
		pOutput->me2_pix_rim_shrink[_RIM_LFT] = pParam->u8_me_pixRim_shrink;
		pOutput->me2_pix_rim_shrink[_RIM_RHT] =	pParam->u8_me_pixRim_shrink;
		pOutput->me2_pix_rim_shrink[_RIM_TOP] =	pParam->u8_me_pixRim_shrink;
		pOutput->me2_pix_rim_shrink[_RIM_BOT] =	pParam->u8_me_pixRim_shrink;
		pOutput->mc_pix_rim_shrink[_RIM_LFT]  = pParam->u8_mc_ptRim_shrink;
		pOutput->mc_pix_rim_shrink[_RIM_RHT]  =	pParam->u8_mc_ptRim_shrink;
		pOutput->mc_pix_rim_shrink[_RIM_TOP]  =	pParam->u8_mc_ptRim_shrink;
		pOutput->mc_pix_rim_shrink[_RIM_BOT]  =	pParam->u8_mc_ptRim_shrink;
	}

	//else if(rim is large, bound rmv is not very large than case1)  //dat-logo is same as cheeta?
	//{
	//		cnt = 7;
	//		rimofst  = 0;
	//}
}

VOID RimCtrl_ME1_Rim_Convert(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	SINT32 ii;
	UINT16 me1_blkV_Resolution = 0, me1_pixV_Resolution = 0;
	UINT16 me1_blkH_Resolution = 0, me1_pixH_Resolution = 0;

	SINT16 me1_pix_rim_oft[_RIM_NUM];
	SINT16 me1_blk_rim_oft[_RIM_NUM];

	if(pOutput->u8_me1_pixH_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me1_pixH_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me1_pixH_sft_bit = 1;
	}
	if(pOutput->u8_me1_pixV_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me1_pixV_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me1_pixV_sft_bit = 1;
	}
	if(pOutput->u8_me1_blkH_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me1_blkH_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me1_blkH_sft_bit = 1;
	}
	if(pOutput->u8_me1_blkV_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me1_blkV_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me1_blkV_sft_bit = 1;
	}

	me1_blkV_Resolution = pOutput->u12_out_resolution[_RIM_BOT] / pOutput->u8_me1_blkV_sft_bit;
	me1_pixV_Resolution = pOutput->u12_out_resolution[_RIM_BOT] / pOutput->u8_me1_pixV_sft_bit;
	me1_blkH_Resolution = pOutput->u12_out_resolution[_RIM_RHT] / pOutput->u8_me1_blkH_sft_bit;
	me1_pixH_Resolution = pOutput->u12_out_resolution[_RIM_RHT] / pOutput->u8_me1_pixV_sft_bit;


	//egg: current just use 0 is ok.
	me1_pix_rim_oft[_RIM_LFT] = pParam->u8_me1_pixRim_offset;
	me1_pix_rim_oft[_RIM_RHT] = pParam->u8_me1_pixRim_offset; 
	me1_pix_rim_oft[_RIM_TOP] = pParam->u8_me1_pixRim_offset; 
	me1_pix_rim_oft[_RIM_BOT] = pParam->u8_me1_pixRim_offset; 

	me1_blk_rim_oft[_RIM_LFT] = pParam->u8_me1_blkRim_offset;
	me1_blk_rim_oft[_RIM_RHT] = pParam->u8_me1_blkRim_offset;
	me1_blk_rim_oft[_RIM_TOP] = pParam->u8_me1_blkRim_offset;
	me1_blk_rim_oft[_RIM_BOT] = pParam->u8_me1_blkRim_offset;


	for (ii = 0; ii < _RIM_NUM; ii++)
	{
		if (me1_pix_rim_oft[ii] > 128)
		{
			me1_pix_rim_oft[ii] = me1_pix_rim_oft[ii] - 256;   //inverse
		} 

		if (me1_blk_rim_oft[ii] > 128)
		{
			me1_blk_rim_oft[ii] = me1_blk_rim_oft[ii] - 256;   //inverse
		} 
	}

	pOutput->u12_me1_lbme_rim[_RIM_LFT] = pOutput->u12_Rim_Result[_RIM_LFT] / pOutput->u8_me1_pixH_sft_bit;
	pOutput->u12_me1_lbme_rim[_RIM_RHT] = pOutput->u12_Rim_Result[_RIM_RHT] / pOutput->u8_me1_pixH_sft_bit;
	pOutput->u12_me1_lbme_rim[_RIM_TOP] = pOutput->u12_Rim_Result[_RIM_TOP] / pOutput->u8_me1_pixV_sft_bit;
	pOutput->u12_me1_lbme_rim[_RIM_BOT] = pOutput->u12_Rim_Result[_RIM_BOT] / pOutput->u8_me1_pixV_sft_bit;

	pOutput->u12_me1_vbuf_pix_rim[_RIM_LFT]  = _CLIP_((SINT16)pOutput->u12_me1_lbme_rim[_RIM_LFT] - me1_pix_rim_oft[_RIM_LFT],0,me1_pixH_Resolution);
	pOutput->u12_me1_vbuf_pix_rim[_RIM_RHT] = _CLIP_((SINT16)pOutput->u12_me1_lbme_rim[_RIM_RHT] + me1_pix_rim_oft[_RIM_RHT],0,me1_pixH_Resolution);
	pOutput->u12_me1_vbuf_pix_rim[_RIM_TOP] = _CLIP_((SINT16)pOutput->u12_me1_lbme_rim[_RIM_TOP] - me1_pix_rim_oft[_RIM_TOP],0,me1_pixV_Resolution);
	pOutput->u12_me1_vbuf_pix_rim[_RIM_BOT] = _CLIP_((SINT16)pOutput->u12_me1_lbme_rim[_RIM_BOT] + me1_pix_rim_oft[_RIM_BOT],0,me1_pixV_Resolution);

	pOutput->u12_me1_vbuf_blk_rim[_RIM_LFT]  = _CLIP_(pOutput->u12_Rim_Result[_RIM_LFT]   / pOutput->u8_me1_blkH_sft_bit - me1_blk_rim_oft[_RIM_LFT],0,me1_blkH_Resolution);
	pOutput->u12_me1_vbuf_blk_rim[_RIM_RHT] = _CLIP_(pOutput->u12_Rim_Result[_RIM_RHT]  / pOutput->u8_me1_blkH_sft_bit + me1_blk_rim_oft[_RIM_RHT],0,me1_blkH_Resolution);
	pOutput->u12_me1_vbuf_blk_rim[_RIM_TOP] = _CLIP_(pOutput->u12_Rim_Result[_RIM_TOP]  / pOutput->u8_me1_blkV_sft_bit - me1_blk_rim_oft[_RIM_TOP],0,me1_blkV_Resolution);
	pOutput->u12_me1_vbuf_blk_rim[_RIM_BOT] = _CLIP_(pOutput->u12_Rim_Result[_RIM_BOT] /  pOutput->u8_me1_blkV_sft_bit + me1_blk_rim_oft[_RIM_BOT],0,me1_blkV_Resolution);

	// meander top/bottom rim.
	pOutput->u12_me1_vbuf_meander_blk_rim[_RIM_TOP] = me1_blkV_Resolution - pOutput->u12_me1_vbuf_blk_rim[_RIM_BOT];
	pOutput->u12_me1_vbuf_meander_blk_rim[_RIM_BOT] = me1_blkV_Resolution - pOutput->u12_me1_vbuf_blk_rim[_RIM_TOP];
	pOutput->u12_me1_vbuf_meander_pix_rim[_RIM_TOP] = me1_pixV_Resolution - pOutput->u12_me1_vbuf_pix_rim[_RIM_BOT];
	pOutput->u12_me1_vbuf_meander_pix_rim[_RIM_BOT] = me1_pixV_Resolution - pOutput->u12_me1_vbuf_pix_rim[_RIM_TOP];

}

VOID RimCtrl_ME2_Rim_Convert(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	//UINT16 me2_pix_rim_oft[_RIM_NUM];
	UINT16 me2_blk_rim_oft[_RIM_NUM];
	UINT16 me2_blkV_Resolution; 
	UINT16 me2_pixV_Resolution;
	UINT16 me2_blkH_Resolution;
	UINT16 me2_pixH_Resolution;
	//SINT32 ii;

	if(pOutput->u8_me2_pixH_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me2_pixH_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me2_pixH_sft_bit = 1;
	}
	if(pOutput->u8_me2_pixV_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me2_pixV_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me2_pixV_sft_bit = 1;
	}
	if(pOutput->u8_me2_BlkH_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me2_BlkH_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me2_BlkH_sft_bit = 1;
	}
	if(pOutput->u8_me2_BlkV_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me2_BlkV_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me2_BlkV_sft_bit = 1;
	}

	me2_blkV_Resolution = pOutput->u12_out_resolution[_RIM_BOT] / pOutput->u8_me2_BlkV_sft_bit;
	me2_pixV_Resolution = pOutput->u12_out_resolution[_RIM_BOT] / pOutput->u8_me2_pixV_sft_bit;
	me2_blkH_Resolution = pOutput->u12_out_resolution[_RIM_RHT] / pOutput->u8_me2_BlkH_sft_bit;
	me2_pixH_Resolution = pOutput->u12_out_resolution[_RIM_RHT] / pOutput->u8_me2_pixH_sft_bit;	

	//if (pParam->u8_ME2_RimMode == 0)
	//{
	//	me2_pix_rim_oft[_RIM_LFT] = _ABS_(pOutput->u12_Rim_Result[_RIM_LFT] - pOutput->u12_out_resolution[_RIM_LFT]) < pParam->u8_ME2_ignRim ?  pParam->u8_me_pixRim_shrink : 0 ;
	//	me2_pix_rim_oft[_RIM_RHT] = _ABS_(pOutput->u12_Rim_Result[_RIM_RHT] - pOutput->u12_out_resolution[_RIM_RHT]) < pParam->u8_ME2_ignRim ?  pParam->u8_me_pixRim_shrink : 0 ;
	//	me2_pix_rim_oft[_RIM_TOP] = _ABS_(pOutput->u12_Rim_Result[_RIM_TOP] - pOutput->u12_out_resolution[_RIM_TOP]) < pParam->u8_ME2_ignRim ?  pParam->u8_me_pixRim_shrink : 0 ;
	//	me2_pix_rim_oft[_RIM_BOT] = _ABS_(pOutput->u12_Rim_Result[_RIM_BOT] - pOutput->u12_out_resolution[_RIM_BOT]) < pParam->u8_ME2_ignRim ?  pParam->u8_me_pixRim_shrink : 0 ;
	//}
	//else
	//{
	//	me2_pix_rim_oft[_RIM_LFT] = _ABS_(pOutput->u12_Rim_Result[_RIM_LFT] - pOutput->u12_out_resolution[_RIM_LFT]) < pParam->u8_ME2_ignRim ?   0 :pParam->u8_me_pixRim_shrink;
	//	me2_pix_rim_oft[_RIM_RHT] = _ABS_(pOutput->u12_Rim_Result[_RIM_RHT] - pOutput->u12_out_resolution[_RIM_RHT]) < pParam->u8_ME2_ignRim ?   0 :pParam->u8_me_pixRim_shrink;
	//	me2_pix_rim_oft[_RIM_TOP] = _ABS_(pOutput->u12_Rim_Result[_RIM_TOP] - pOutput->u12_out_resolution[_RIM_TOP]) < pParam->u8_ME2_ignRim ?   0 :pParam->u8_me_pixRim_shrink;
	//	me2_pix_rim_oft[_RIM_BOT] = _ABS_(pOutput->u12_Rim_Result[_RIM_BOT] - pOutput->u12_out_resolution[_RIM_BOT]) < pParam->u8_ME2_ignRim ?   0 :pParam->u8_me_pixRim_shrink;
	//}

	me2_blk_rim_oft[_RIM_LFT] = pParam->u8_ME2_blkRimsht;
	me2_blk_rim_oft[_RIM_RHT] = pParam->u8_ME2_blkRimsht;
	me2_blk_rim_oft[_RIM_TOP] = pParam->u8_ME2_blkRimsht;
	me2_blk_rim_oft[_RIM_BOT] = pParam->u8_ME2_blkRimsht;

	//for (ii = 0; ii < _RIM_NUM; ii++)
	//{
	//	if (me2_pix_rim_oft[ii] > 128)
	//	{
	//		me2_pix_rim_oft[ii] = me2_pix_rim_oft[ii] - 256;   //inverse
	//	} 

	//	if (me2_blk_rim_oft[ii] > 128)
	//	{
	//		me2_blk_rim_oft[ii] = me2_blk_rim_oft[ii] - 256;   //inverse
	//	} 
	//}

	pOutput->u12_me2_lbme_rim[_RIM_LFT] = pOutput->u12_Rim_Result[_RIM_LFT] / pOutput->u8_me2_pixH_sft_bit;
	pOutput->u12_me2_lbme_rim[_RIM_RHT] = pOutput->u12_Rim_Result[_RIM_RHT] / pOutput->u8_me2_pixH_sft_bit;
	pOutput->u12_me2_lbme_rim[_RIM_TOP] = pOutput->u12_Rim_Result[_RIM_TOP] / pOutput->u8_me2_pixV_sft_bit;
	pOutput->u12_me2_lbme_rim[_RIM_BOT] = pOutput->u12_Rim_Result[_RIM_BOT] / pOutput->u8_me2_pixV_sft_bit;

	pOutput->u12_me2_vbuf_pix_rim[_RIM_LFT] = _CLIP_(pOutput->u12_me2_lbme_rim[_RIM_LFT] + pOutput->me2_pix_rim_shrink[_RIM_LFT], 0, me2_pixH_Resolution);
	pOutput->u12_me2_vbuf_pix_rim[_RIM_RHT] = _CLIP_(pOutput->u12_me2_lbme_rim[_RIM_RHT] - pOutput->me2_pix_rim_shrink[_RIM_RHT], 0, me2_pixH_Resolution);
	pOutput->u12_me2_vbuf_pix_rim[_RIM_TOP] = _CLIP_(pOutput->u12_me2_lbme_rim[_RIM_TOP] + pOutput->me2_pix_rim_shrink[_RIM_TOP], 0, me2_pixV_Resolution);
	pOutput->u12_me2_vbuf_pix_rim[_RIM_BOT] = _CLIP_(pOutput->u12_me2_lbme_rim[_RIM_BOT] - pOutput->me2_pix_rim_shrink[_RIM_BOT], 0, me2_pixV_Resolution);

	pOutput->u12_me2_vbuf_ph_blk_rim[_RIM_LFT] = _CLIP_(pOutput->u12_Rim_Result[_RIM_LFT]    / pOutput->u8_me2_BlkH_sft_bit + me2_blk_rim_oft[_RIM_LFT],0,me2_blkH_Resolution);
	pOutput->u12_me2_vbuf_ph_blk_rim[_RIM_RHT] = _CLIP_(pOutput->u12_Rim_Result[_RIM_RHT]  / pOutput->u8_me2_BlkH_sft_bit - me2_blk_rim_oft[_RIM_RHT],0,me2_blkH_Resolution);
	pOutput->u12_me2_vbuf_ph_blk_rim[_RIM_TOP] = _CLIP_(pOutput->u12_Rim_Result[_RIM_TOP]  / pOutput->u8_me2_BlkV_sft_bit + me2_blk_rim_oft[_RIM_TOP],0,me2_blkV_Resolution);
	pOutput->u12_me2_vbuf_ph_blk_rim[_RIM_BOT] = _CLIP_(pOutput->u12_Rim_Result[_RIM_BOT]/ pOutput->u8_me2_BlkV_sft_bit - me2_blk_rim_oft[_RIM_BOT],0,me2_blkV_Resolution);

}


VOID RimCtrl_MC_Rim_Convert(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
/*	const _PQLCONTEXT *s_pContext = GetPQLContext();*/
	//pOutput->u12_mc_rim0[_RIM_LFT] = pOutput->u12_Rim_Result[_RIM_LFT] + pParam->u8_mc_ptRim_shrink;
	//pOutput->u12_mc_rim0[_RIM_RHT] = pOutput->u12_Rim_Result[_RIM_RHT] - pParam->u8_mc_ptRim_shrink;
	//pOutput->u12_mc_rim0[_RIM_TOP] = pOutput->u12_Rim_Result[_RIM_TOP] + pParam->u8_mc_ptRim_shrink;
	//pOutput->u12_mc_rim0[_RIM_BOT] = pOutput->u12_Rim_Result[_RIM_BOT] - pParam->u8_mc_ptRim_shrink;

	pOutput->u12_mc_rim0[_RIM_LFT] = pOutput->u12_Rim_Result[_RIM_LFT] + pOutput->mc_pix_rim_shrink[_RIM_LFT];
	pOutput->u12_mc_rim0[_RIM_RHT] = pOutput->u12_Rim_Result[_RIM_RHT] - pOutput->mc_pix_rim_shrink[_RIM_RHT];
	pOutput->u12_mc_rim0[_RIM_TOP] = pOutput->u12_Rim_Result[_RIM_TOP] + pOutput->mc_pix_rim_shrink[_RIM_TOP];
	pOutput->u12_mc_rim0[_RIM_BOT] = pOutput->u12_Rim_Result[_RIM_BOT] - pOutput->mc_pix_rim_shrink[_RIM_BOT];

	pOutput->u12_mc_rim1[_RIM_LFT] = pOutput->u12_Rim_Result[_RIM_LFT];
	pOutput->u12_mc_rim1[_RIM_RHT] = pOutput->u12_Rim_Result[_RIM_RHT];
	pOutput->u12_mc_rim1[_RIM_TOP] = pOutput->u12_Rim_Result[_RIM_TOP];
	pOutput->u12_mc_rim1[_RIM_BOT] = pOutput->u12_Rim_Result[_RIM_BOT];
}

VOID RimCtrl_Logo_Rim_Convert(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
/*	const _PQLCONTEXT *s_pContext = GetPQLContext();*/

	UBYTE u8_logoBlk_rim_oft[_RIM_NUM], u8_logoPix_rim_oft[_RIM_NUM];

	//egg: need pure offset
	//blk rim
	//u8_logoBlk_rim_oft[_RIM_LFT] = pOutput->u12_Rim_Result[_RIM_LFT] == pOutput->u12_out_resolution[_RIM_LFT]? 0 : pParam->u8_LogoBlkRimHOffset;
	//u8_logoBlk_rim_oft[_RIM_RHT] = pOutput->u12_Rim_Result[_RIM_RHT] == pOutput->u12_out_resolution[_RIM_RHT]? 0 : pParam->u8_LogoBlkRimHOffset;
	//u8_logoBlk_rim_oft[_RIM_TOP] = pOutput->u12_Rim_Result[_RIM_TOP] == pOutput->u12_out_resolution[_RIM_TOP]? 0 : pParam->u8_LogoBlkRimVOffset;
	//u8_logoBlk_rim_oft[_RIM_BOT] = pOutput->u12_Rim_Result[_RIM_BOT] == pOutput->u12_out_resolution[_RIM_BOT]? 0 : pParam->u8_LogoBlkRimVOffset;

	u8_logoBlk_rim_oft[_RIM_LFT] =  pParam->u8_LogoBlkRimHOffset;
	u8_logoBlk_rim_oft[_RIM_RHT] =  pParam->u8_LogoBlkRimHOffset;
	u8_logoBlk_rim_oft[_RIM_TOP] =  pParam->u8_LogoBlkRimVOffset;
	u8_logoBlk_rim_oft[_RIM_BOT] =  pParam->u8_LogoBlkRimVOffset;


	pOutput->u8_LogoRim_Blk[_RIM_LFT] = (pOutput->u12_Rim_Result[_RIM_LFT] >> pOutput->u8_logo_blkH_sft_bit) + u8_logoBlk_rim_oft[_RIM_LFT];
	pOutput->u8_LogoRim_Blk[_RIM_RHT] = (pOutput->u12_Rim_Result[_RIM_RHT] >> pOutput->u8_logo_blkH_sft_bit) - u8_logoBlk_rim_oft[_RIM_RHT];
	pOutput->u8_LogoRim_Blk[_RIM_TOP] = (pOutput->u12_Rim_Result[_RIM_TOP] >> pOutput->u8_logo_blkV_sft_bit) + u8_logoBlk_rim_oft[_RIM_TOP];
	pOutput->u8_LogoRim_Blk[_RIM_BOT] = (pOutput->u1_insidePan_Cond==1) ? ((pOutput->u12_Rim_Result[_RIM_BOT] >> pOutput->u8_logo_blkV_sft_bit) - u8_logoBlk_rim_oft[_RIM_BOT]) : 
																	(pOutput->u12_Rim_Result[_RIM_BOT] >> pOutput->u8_logo_blkV_sft_bit);
	pOutput->u8_LogoRim_Blk[_RIM_BOT] = _CLIP_(pOutput->u8_LogoRim_Blk[_RIM_BOT], 0, 132);// shift 2 blk to avoid boundary mis-detect logo

	//pixel rim
	//u8_logoPix_rim_oft[_RIM_LFT] = pOutput->u12_Rim_Result[_RIM_LFT] == pOutput->u12_out_resolution[_RIM_LFT]? 0 : pParam->u8_LogoPixRimHOffset;
	//u8_logoPix_rim_oft[_RIM_RHT] = pOutput->u12_Rim_Result[_RIM_RHT] == pOutput->u12_out_resolution[_RIM_RHT]? 0 : pParam->u8_LogoPixRimHOffset;
	//u8_logoPix_rim_oft[_RIM_TOP] = pOutput->u12_Rim_Result[_RIM_TOP] == pOutput->u12_out_resolution[_RIM_TOP]? 0 : pParam->u8_LogoPixRimVOffset;
	//u8_logoPix_rim_oft[_RIM_BOT] = pOutput->u12_Rim_Result[_RIM_BOT] == pOutput->u12_out_resolution[_RIM_BOT]? 0 : pParam->u8_LogoPixRimVOffset;

	u8_logoPix_rim_oft[_RIM_LFT] =  pParam->u8_LogoPixRimHOffset;
	u8_logoPix_rim_oft[_RIM_RHT] =  pParam->u8_LogoPixRimHOffset;
	u8_logoPix_rim_oft[_RIM_TOP] =  pParam->u8_LogoPixRimVOffset;
	u8_logoPix_rim_oft[_RIM_BOT] =  pParam->u8_LogoPixRimVOffset;

	pOutput->u12_LogoRim_Pxl[_RIM_LFT] = (pOutput->u12_Rim_Result[_RIM_LFT] >> pOutput->u8_logo_pixH_sft_bit) + u8_logoPix_rim_oft[_RIM_LFT];
	pOutput->u12_LogoRim_Pxl[_RIM_RHT] = (pOutput->u12_Rim_Result[_RIM_RHT] >> pOutput->u8_logo_pixH_sft_bit) - u8_logoPix_rim_oft[_RIM_RHT];
	pOutput->u12_LogoRim_Pxl[_RIM_TOP] = (pOutput->u12_Rim_Result[_RIM_TOP] >> pOutput->u8_logo_pixV_sft_bit) + u8_logoPix_rim_oft[_RIM_TOP];
	pOutput->u12_LogoRim_Pxl[_RIM_BOT] = (pOutput->u1_insidePan_Cond==1) ? ((pOutput->u12_Rim_Result[_RIM_BOT] >> pOutput->u8_logo_pixV_sft_bit) - u8_logoPix_rim_oft[_RIM_BOT]) : 
																	(pOutput->u12_Rim_Result[_RIM_BOT] >> pOutput->u8_logo_pixV_sft_bit);
	pOutput->u12_LogoRim_Pxl[_RIM_BOT] = _CLIP_(pOutput->u12_LogoRim_Pxl[_RIM_BOT], 0, 531);// shift 2 blk(8 pixel) to avoid boundry mis-detect logo
	
}

VOID RimCtrl_Film5RgnPos_Convert(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
/*		const _PQLCONTEXT *s_pContext = GetPQLContext();*/
	UBYTE  u4_Res_H_Divide = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_1920x540) ? 2 : 
		                     			(pOutput->u4_outResolution_pre == _PQL_OUT_3840x2160 || pOutput->u4_outResolution_pre == _PQL_OUT_3840x1080 ||pOutput->u4_outResolution_pre == _PQL_OUT_3840x540) ? 3 : 0;
    	UBYTE  u4_Res_V_Divide = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_3840x1080) ? 1 : 
	                         			(pOutput->u4_outResolution_pre == _PQL_OUT_3840x2160) ? 2 : 0;

	UINT16 u12_filmResolutionB = pOutput->u12_out_resolution[_RIM_BOT]>>u4_Res_V_Divide;
	UINT16 u12_filmResolutionR = pOutput->u12_out_resolution[_RIM_RHT]>>u4_Res_H_Divide;

	UINT16 u10_film5Region1_v0 = 0;
	UINT16 u10_film5Region1_v1 = 0;
	UINT16 u10_film5Region2_v0 = 0;
	UINT16 u10_film5Region2_v1 = 0;
	UINT16 u10_film5Region3_h0 = 0;
	UINT16 u10_film5Region3_h1 = 0;
	UINT16 u10_film5Region4_h0 = 0;
	UINT16 u10_film5Region4_h1 = 0;

	//UINT32 u32_rb_val = 0;
	
	// K2:PQL_ReadHDF
	// Need to confirm t/b/l/r order
	//ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region1_v0_ADDR), 0, 31, &u32_rb_val);//top
	u10_film5Region1_v0 = 0x4;//(u32_rb_val) & 0x3ff;
	u10_film5Region1_v1 = 0x58;//(u32_rb_val>>10) & 0x3ff;
	//ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region2_v0_ADDR), 0, 31, &u32_rb_val);//bottom
	u10_film5Region2_v0 = 0x1bc;//(u32_rb_val) & 0x3ff;
	u10_film5Region2_v1 = 0x20d;//(u32_rb_val>>10) & 0x3ff;
	//ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region3_h0_ADDR), 0, 31, &u32_rb_val);//left
	u10_film5Region3_h0 = 0x2;//(u32_rb_val) & 0x3ff;
	u10_film5Region3_h1 = 0x60;//(u32_rb_val>>10) & 0x3ff;
	//ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region4_h0_ADDR), 0, 31, &u32_rb_val);//bottom
	u10_film5Region4_h0 = 0x140;//(u32_rb_val) & 0x3ff;
	u10_film5Region4_h1 = 0x1d4;//(u32_rb_val>>10) & 0x3ff;


	//top
	{	
		UINT16 u10_rgnHWshift = ((pOutput->u12_ipme_rim[_RIM_TOP]>u10_film5Region1_v0) ? (pOutput->u12_ipme_rim[_RIM_TOP]-u10_film5Region1_v0) : 0);
		u10_film5Region1_v0 += u10_rgnHWshift + 13;
		u10_film5Region1_v1 += u10_rgnHWshift;
		u10_film5Region1_v1 = (u10_film5Region1_v1<u10_film5Region1_v0) ? u10_film5Region1_v0 : u10_film5Region1_v1;
	}

	//bot
	{
		UINT16 u10_rgnHWshift = ((pOutput->u12_ipme_rim[_RIM_BOT]<u10_film5Region2_v1) ? (u10_film5Region2_v1-pOutput->u12_ipme_rim[_RIM_BOT]) : 0);
		u10_film5Region2_v0 -= u10_rgnHWshift;
		u10_film5Region2_v1 -= (u10_rgnHWshift + 13);
		u10_film5Region2_v0 = (u10_film5Region2_v0>u10_film5Region2_v1) ? u10_film5Region2_v1 : u10_film5Region2_v0;
	}

	//left
	{
		UINT16 u10_rgnHWshift = ((pOutput->u12_ipme_rim[_RIM_LFT]>u10_film5Region3_h0) ? (pOutput->u12_ipme_rim[_RIM_LFT]-u10_film5Region3_h0) : 0);
		u10_film5Region3_h0 += u10_rgnHWshift + 13;
		u10_film5Region3_h1 += u10_rgnHWshift;
		u10_film5Region3_h1 = (u10_film5Region3_h1<u10_film5Region3_h0) ? u10_film5Region3_h0 : u10_film5Region3_h1;
	}
	
	//right
	{
		UINT16 u10_rgnHWshift = ((pOutput->u12_ipme_rim[_RIM_RHT]<u10_film5Region4_h1) ? (u10_film5Region4_h1-pOutput->u12_ipme_rim[_RIM_RHT]) : 0);
		u10_film5Region4_h0 -= u10_rgnHWshift;
		u10_film5Region4_h1 -= (u10_rgnHWshift + 4);
		u10_film5Region4_h0 = (u10_film5Region4_h0>u10_film5Region4_h1) ? u10_film5Region4_h1 : u10_film5Region4_h0;
	}


	u10_film5Region1_v0 = _CLIP_UBOUND_(u10_film5Region1_v0, u12_filmResolutionB-1);
	u10_film5Region1_v1 = _CLIP_UBOUND_(u10_film5Region1_v1, u12_filmResolutionB-1);
	u10_film5Region2_v0 = _CLIP_UBOUND_(u10_film5Region2_v0, u12_filmResolutionB-1);
	u10_film5Region2_v1 = _CLIP_UBOUND_(u10_film5Region2_v1, u12_filmResolutionB-1);
	u10_film5Region3_h0 = _CLIP_UBOUND_(u10_film5Region3_h0, u12_filmResolutionR-1);
	u10_film5Region3_h1 = _CLIP_UBOUND_(u10_film5Region3_h1, u12_filmResolutionR-1);
	u10_film5Region4_h0 = _CLIP_UBOUND_(u10_film5Region4_h0, u12_filmResolutionR-1);
	u10_film5Region4_h1 = _CLIP_UBOUND_(u10_film5Region4_h1, u12_filmResolutionR-1);


 	pOutput->u12_5Rgn1_v0 = u10_film5Region1_v0;
	pOutput->u12_5Rgn1_v1 = u10_film5Region1_v1;
	pOutput->u12_5Rgn2_v0 = u10_film5Region2_v0;
	pOutput->u12_5Rgn2_v1 = u10_film5Region2_v1;
	pOutput->u12_5Rgn3_h0 = u10_film5Region3_h0;
	pOutput->u12_5Rgn3_h1 = u10_film5Region3_h1;
	pOutput->u12_5Rgn4_h0 = u10_film5Region4_h0;
	pOutput->u12_5Rgn4_h1 = u10_film5Region4_h1;

	// update 12rgn rim
     	pOutput->u12_12Rgn_v0 = u10_film5Region1_v0;
	pOutput->u12_12Rgn_v1 = u10_film5Region1_v1;
	pOutput->u12_12Rgn_v2 = u10_film5Region2_v0;
	pOutput->u12_12Rgn_v3 = u10_film5Region2_v1;
	pOutput->u12_12Rgn_h0 = u10_film5Region3_h0;
	pOutput->u12_12Rgn_h1 = u10_film5Region3_h1;
	pOutput->u12_12Rgn_h2 = (u10_film5Region3_h1+u10_film5Region4_h0)/2;
	pOutput->u12_12Rgn_h3 = u10_film5Region4_h0;
	pOutput->u12_12Rgn_h4 = u10_film5Region4_h1;	
 
     
}

VOID RimCtrl_Film_Rim_Convert(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{

	UBYTE  u4_Res_H_Divide = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_1920x540) ? 2 : 
		                     			(pOutput->u4_outResolution_pre == _PQL_OUT_3840x2160 || pOutput->u4_outResolution_pre == _PQL_OUT_3840x1080 ||pOutput->u4_outResolution_pre == _PQL_OUT_3840x540) ? 3 : 0;
    	UBYTE  u4_Res_V_Divide = (pOutput->u4_outResolution_pre == _PQL_OUT_1920x1080 || pOutput->u4_outResolution_pre == _PQL_OUT_3840x1080) ? 1 : 
	                         			(pOutput->u4_outResolution_pre == _PQL_OUT_3840x2160) ? 2 : 0;

	//pOutput->u12_ipme_rim[_RIM_LFT] = pOutput->u12_me1_vbuf_pix_rim[_RIM_LFT]/2+2; //two pixel
	//pOutput->u12_ipme_rim[_RIM_RHT] = pOutput->u12_me1_vbuf_pix_rim[_RIM_RHT]/2-2; //two pixel
	//pOutput->u12_ipme_rim[_RIM_TOP] = pOutput->u12_me1_vbuf_pix_rim[_RIM_TOP]+2;
	//pOutput->u12_ipme_rim[_RIM_BOT] = pOutput->u12_me1_vbuf_pix_rim[_RIM_BOT]-2;

	pOutput->u12_ipme_rim[_RIM_LFT] = ((pOutput->u12_Rim_Result[_RIM_LFT] + (1<<u4_Res_H_Divide)/2) >> u4_Res_H_Divide)+2; 
	pOutput->u12_ipme_rim[_RIM_RHT] = (pOutput->u12_Rim_Result[_RIM_RHT] >> u4_Res_H_Divide)-2; 
	pOutput->u12_ipme_rim[_RIM_TOP] = ((pOutput->u12_Rim_Result[_RIM_TOP] + (1<<u4_Res_V_Divide)/2) >> u4_Res_V_Divide)+2;
	pOutput->u12_ipme_rim[_RIM_BOT] = (pOutput->u12_Rim_Result[_RIM_BOT] >> u4_Res_V_Divide)-2;



	RimCtrl_Film5RgnPos_Convert(pParam, pOutput);
}

VOID RimCtrl_Dh_Rim_Convert(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	if(pOutput->u8_me1_blkH_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me1_blkH_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me1_blkH_sft_bit = 1;
	}
	if(pOutput->u8_me1_blkV_sft_bit == 0){
		LogPrintf(DBG_WARNING,"[%s]pOutput->u8_me1_blkV_sft_bit is zero!!\n",__FUNCTION__);
		pOutput->u8_me1_blkV_sft_bit = 1;
	}

	
	//egg
	pOutput->u9_dh_blk_rim[_RIM_LFT] = pOutput->u12_me1_vbuf_blk_rim[_RIM_LFT];
	pOutput->u9_dh_blk_rim[_RIM_RHT] = (pOutput->u12_out_resolution[_RIM_RHT] / pOutput->u8_me1_blkH_sft_bit) - pOutput->u12_me1_vbuf_blk_rim[_RIM_RHT];
	pOutput->u9_dh_blk_rim[_RIM_TOP] = pOutput->u12_me1_vbuf_blk_rim[_RIM_TOP];
	pOutput->u9_dh_blk_rim[_RIM_BOT] = (pOutput->u12_out_resolution[_RIM_BOT] / pOutput->u8_me1_blkV_sft_bit) - pOutput->u12_me1_vbuf_blk_rim[_RIM_BOT];


	//pOutput->u9_dh_blk_rim[_RIM_LFT] = pOutput->u12_me1_vbuf_blk_rim[_RIM_LFT] ;
	//pOutput->u9_dh_blk_rim[_RIM_RHT] = _CLIP_((SINT16)(pOutput->u12_out_resolution[_RIM_RHT] / pOutput->u8_me1_blkH_sft_bit) -1 - (SINT16)pOutput->u12_me1_vbuf_blk_rim[_RIM_RHT]
	//									0,(pOutput->u12_out_resolution[_RIM_RHT] / pOutput->u8_me1_blkH_sft_bit) -1) ;
	//pOutput->u9_dh_blk_rim[_RIM_TOP] = pOutput->u12_me1_vbuf_blk_rim[_RIM_TOP] ;
	//pOutput->u9_dh_blk_rim[_RIM_BOT] = _CLIP_((SINT16)(pOutput->u12_out_resolution[_RIM_BOT] / pOutput->u8_me1_blkV_sft_bit) -1 - (SINT16)pOutput->u12_me1_vbuf_blk_rim[_RIM_BOT]
	//									 0,(pOutput->u12_out_resolution[_RIM_BOT] / pOutput->u8_me1_blkV_sft_bit) -1) ;


}

VOID RimCtrl_Output(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	RimCtrl_Dynamic_OfstCalc(pParam,pOutput);

	if (pOutput->u1_RimChange == 1)
	{
		//Vetical.
		pOutput->u8_me1_pixV_sft_bit    = (pOutput->u12_out_resolution[_RIM_BOT] + 1)/s_pContext->_output_read_comreg.u12_ME1_pix_size[_RIM_VSIZE];
		pOutput->u8_me1_blkV_sft_bit    = (pOutput->u12_out_resolution[_RIM_BOT] + 1)/s_pContext->_output_read_comreg.u12_ME1_blk_size[_RIM_VSIZE]; 

		pOutput->u8_me2_pixV_sft_bit    = (pOutput->u12_out_resolution[_RIM_BOT] + 1)/s_pContext->_output_read_comreg.u12_ME2_pix_size[_RIM_VSIZE];
		pOutput->u8_me2_BlkV_sft_bit    = (pOutput->u12_out_resolution[_RIM_BOT] + 1)/s_pContext->_output_read_comreg.u12_ME2_blk_size[_RIM_VSIZE];


		//Horizotal
		pOutput->u8_me1_pixH_sft_bit    = (pOutput->u12_out_resolution[_RIM_RHT] + 1)/s_pContext->_output_read_comreg.u12_ME1_pix_size[_RIM_HSIZE];
		pOutput->u8_me1_blkH_sft_bit    = (pOutput->u12_out_resolution[_RIM_RHT] + 1)/s_pContext->_output_read_comreg.u12_ME1_blk_size[_RIM_HSIZE];

		pOutput->u8_me2_pixH_sft_bit    = (pOutput->u12_out_resolution[_RIM_RHT] + 1)/s_pContext->_output_read_comreg.u12_ME2_pix_size[_RIM_HSIZE];
		pOutput->u8_me2_BlkH_sft_bit    = (pOutput->u12_out_resolution[_RIM_RHT] + 1)/s_pContext->_output_read_comreg.u12_ME2_blk_size[_RIM_HSIZE];

		
		if (pOutput->u12_out_resolution[_RIM_BOT] == 2159)
		{
//			pOutput->u8_me1_pixV_sft_bit    = 2; // 540
//			pOutput->u8_me1_blkV_sft_bit    = 3; // 270

//			pOutput->u8_me2_pixV_sft_bit    = 3; // 270
//			pOutput->u8_me2_BlkV_sft_bit    = 4; // 135

			pOutput->u8_logo_pixV_sft_bit   = 2; // 540
			pOutput->u8_logo_blkV_sft_bit   = 4; // 135
		}
		else if (pOutput->u12_out_resolution[_RIM_BOT] == 1079)
		{
//			pOutput->u8_me1_pixV_sft_bit    = 1; // 540
//			pOutput->u8_me1_blkV_sft_bit    = 3; // 135

//			pOutput->u8_me2_pixV_sft_bit    = 2; // 270
//			pOutput->u8_me2_BlkV_sft_bit    = 3; // 135

			pOutput->u8_logo_pixV_sft_bit   = 1; // 540
			pOutput->u8_logo_blkV_sft_bit   = 3; // 135
		}
		else // if (pOutput->u12_out_resolution[_RIM_BOT] == 539)
		{
//			pOutput->u8_me1_pixV_sft_bit    = 1; // 270
//			pOutput->u8_me1_blkV_sft_bit    = 2; // 135

//			pOutput->u8_me2_pixV_sft_bit    = 2; // 135
//			pOutput->u8_me2_BlkV_sft_bit    = 3; // 68

			pOutput->u8_logo_pixV_sft_bit   = 0; // 540
			pOutput->u8_logo_blkV_sft_bit   = 2; // 135
		}

		// Horizontal.
		if (pOutput->u12_out_resolution[_RIM_RHT] == 1919)
		{
//			pOutput->u8_me1_pixH_sft_bit    = 1; // 960
//			pOutput->u8_me1_blkH_sft_bit    = 3; // 240

//			pOutput->u8_me2_pixH_sft_bit    = 2; // 480
//			pOutput->u8_me2_BlkH_sft_bit    = 3;   // 240

			pOutput->u8_logo_pixH_sft_bit   = 1; // 960
			pOutput->u8_logo_blkH_sft_bit   = 3; // 240
		}
		else // Hactive = 3839
		{
//			pOutput->u8_me1_pixH_sft_bit    = 2; // 960
//			pOutput->u8_me1_blkH_sft_bit    = 3; // 480

//			pOutput->u8_me2_pixH_sft_bit    = 3; // 480
//			pOutput->u8_me2_BlkH_sft_bit  = 4; // 240

			pOutput->u8_logo_pixH_sft_bit   = 2; // 960
			pOutput->u8_logo_blkH_sft_bit   = 4; // 240
		}

		RimCtrl_ME1_Rim_Convert(pParam, pOutput);
		RimCtrl_ME2_Rim_Convert(pParam, pOutput);
		RimCtrl_Logo_Rim_Convert(pParam, pOutput);
		RimCtrl_MC_Rim_Convert(pParam, pOutput);

		RimCtrl_Film_Rim_Convert(pParam, pOutput);
		RimCtrl_Dh_Rim_Convert(pParam, pOutput);
	}
}

VOID RimCtrl_Stable(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
    int i = 0; 
    for (i = 0; i < _RIM_NUM; i ++)
    {
         pOutput->s8_StableCnt[i] = (_ABS_(pOutput->u12_Rim_Cur[i]-pOutput->u12_Rim_Pre_Det[i]) < 3) ? (pOutput->s8_StableCnt[i] + 1) :\
		 	                        ((_ABS_(pOutput->u12_Rim_Cur[i]-pOutput->u12_Rim_Pre_Det[i]) < 8) ? pOutput->s8_StableCnt[i] :\
		 	                        ((_ABS_(pOutput->u12_Rim_Cur[i]-pOutput->u12_Rim_Pre_Det[i]) < 16) ? (pOutput->s8_StableCnt[i] - 1) : 0));
		 pOutput->s8_StableCnt[i] = (pOutput->s8_StableCnt[i] > 32) ? 32 : ((pOutput->s8_StableCnt[i] < 0) ? 0 : pOutput->s8_StableCnt[i]);
    }
}

VOID RimCtrl_Panning_Detect(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	//const _PQLCONTEXT *s_pContext = GetPQLContext();
	//UINT16 u16_rb_smv_posCnt, u16_rb_Lmv_posCnt, u16_rb_smv_negCnt, u16_rb_Lmv_negCnt;
	//UINT16 u16_cnt_totalNum = (s_pContext->_output_read_comreg.u8_me1_Vbuf_Hsize_rb * s_pContext->_output_read_comreg.u8_me1_Vbuf_Vsize_rb);
	//UINT16 u16_cnt_th = u16_cnt_totalNum * pParam->u8_PanningCntTH / 255;
	//SINT32 i;
	//UBYTE u8_panning_good_rgn_num = 0;

	//u16_rb_smv_posCnt		 = s_pContext->_output_read_comreg.u17_me_posCnt_0_rb;
	//u16_rb_Lmv_posCnt		 = s_pContext->_output_read_comreg.u17_me_posCnt_1_rb;
	//u16_rb_smv_negCnt		 = s_pContext->_output_read_comreg.u17_me_negCnt_0_rb;
	//u16_rb_Lmv_negCnt		 = s_pContext->_output_read_comreg.u17_me_negCnt_1_rb;

	//for(i=0;i<32;i++)
	//{
	//	if((_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]) < pParam->u10_PanningRMVXTH)&&
	//		(_ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]) > pParam->u10_PanningRMVYTH)&&
	//		(s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > pParam->u12_PanningGMVRngCnt)&& 
	//		(s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < pParam->u12_PanningGMVUnconf))
	//	{
	//		u8_panning_good_rgn_num++;
	//	}
	//}

	//if(((u16_rb_smv_posCnt > u16_cnt_th) || (u16_rb_Lmv_posCnt > u16_cnt_th)) && 
	//	(u8_panning_good_rgn_num >= pParam->u8_PanningGoodRngCntTH))
	//{
	//	pOutput->u8_PanningMode = _PANNING_DOWN;	
	//	//ROSPrintf("[MEMC]::_PANNING_DOWN \r\n");
	//}
	//else if(((u16_rb_smv_negCnt > u16_cnt_th) || (u16_rb_Lmv_negCnt > u16_cnt_th)) && 
	//	    (u8_panning_good_rgn_num >= pParam->u8_PanningGoodRngCntTH))
	//{
	//	pOutput->u8_PanningMode = _PANNING_UP;
	//	//ROSPrintf("[MEMC]::_PANNING_UP \r\n");
	//}
	//else
	//{
	//	pOutput->u8_PanningMode = _PANNING_NORMAL;
	//	//ROSPrintf("[MEMC]::_PANNING_NORMAL \r\n");
	//}
}

//////////////////////////////////////////////////////////////////////////


VOID RimCtrl_Init(_OUTPUT_RimCtrl *pOutput)
{
	UBYTE u8_i = 0;

	pOutput->u4_outResolution_pre         = _PQL_OUT_1920x1080;
	pOutput->u12_out_resolution[_RIM_LFT] = 0;
	pOutput->u12_out_resolution[_RIM_RHT] = 1919;
	pOutput->u12_out_resolution[_RIM_TOP] = 0;
	pOutput->u12_out_resolution[_RIM_BOT] = 1079;
	pOutput->u1_RimControl_pre            = 1;
	pOutput->u1_Resolution_change         = 0;

	for(u8_i=0; u8_i<_RIM_NUM;u8_i++)
	{
		pOutput->u12_Rim_Cur[u8_i] = (u8_i==_RIM_TOP ||u8_i==_RIM_LFT)?0:((u8_i==_RIM_BOT)?2159:3839);	       // current rim  0:top 1:bottom 2:right 3:left 
		pOutput->u12_Rim_Pre[u8_i] = (u8_i==_RIM_TOP ||u8_i==_RIM_LFT)?0:((u8_i==_RIM_BOT)?2159:3839);          // previous rim
		pOutput->u12_Rim_Result[u8_i] = (u8_i==_RIM_TOP ||u8_i==_RIM_LFT)?0:((u8_i==_RIM_BOT)?2159:3839);       // rim result
		pOutput->u12_Rim_Pre_Det[u8_i] = (u8_i==_RIM_TOP ||u8_i==_RIM_LFT)?0:((u8_i==_RIM_BOT)?2159:3839);          // rim result

		pOutput->s8_BiggerCnt[u8_i] = 0;
		pOutput->s8_SmallerCnt[u8_i] = 0;
		pOutput->s8_StableCnt[u8_i] = 0;

		pOutput->me2_pix_rim_shrink[u8_i] = 0;
		pOutput->mc_pix_rim_shrink[u8_i]  = 0;

	}

	pOutput->u12_5Rgn1_v0 = 0x4;
	pOutput->u12_5Rgn1_v1 = 0x58;
	pOutput->u12_5Rgn2_v0 = 0x1bc;
	pOutput->u12_5Rgn2_v1 = 0x20d;
	pOutput->u12_5Rgn3_h0 = 0x2;
	pOutput->u12_5Rgn3_h1 = 0x60;
	pOutput->u12_5Rgn4_h0 = 0x140;
	pOutput->u12_5Rgn4_h1 = 0x1d0;

	pOutput->u12_12Rgn_v0 = 0x4;
	pOutput->u12_12Rgn_v1 = 0x58;
	pOutput->u12_12Rgn_v2 = 0x1bc;
	pOutput->u12_12Rgn_v3 = 0x20d;
	pOutput->u12_12Rgn_h0 = 0x2;
	pOutput->u12_12Rgn_h1 = 0x60;
	pOutput->u12_12Rgn_h2 = 0xd0;
	pOutput->u12_12Rgn_h3 = 0x140;
	pOutput->u12_12Rgn_h4 = 0x1d0;	

	pOutput->me2_oor_cnt    = 0;
	pOutput->rim_sc_holdcnt = 0;

	pOutput->u1_insidePan_Cond = 0;
}

VOID RimCtrl_DynamicBlackTh(VOID)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	//UINT32 u32_rb_val = 0;
	//ReadRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kme_dummy3), &u32_rb_val);
	//UBYTE u1_dynamic_en, u4_black_offset;

	//u1_dynamic_en = (u32_rb_val & 0x01);
	//u4_black_offset = ((u32_rb_val>>1) & 0x07);

	UBYTE u8_black_th;
	UBYTE u8_darklevel = (s_pContext->_external_info.u8_DarkLevel/*+u4_black_offset*/);

	//if (u1_dynamic_en)
	{
		if (u8_darklevel < 0x24)
		{
			u8_black_th = 0x24;
		}
		else if (u8_darklevel > 0x40)
		{
			u8_black_th = 0x40;
		}
		else
		{
			u8_black_th = u8_darklevel;
		}
		//ROSPrintf("[MEMC]DarkLevel = %d\r\n", u8_black_th);
		
		WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_black_th), u8_black_th);
	}

}


//Input signal and parameters are connected locally
VOID RimCtrl_Proc(const _PARAM_RimCtrl *pParam, _OUTPUT_RimCtrl *pOutput)
{
	//const _PQLCONTEXT *s_pContext = GetPQLContext();

	RimCtrl_OutResolution_Parse(pOutput);
	//RimCtrl_Panning_Detect(pParam, pOutput);

	if (pParam->u1_RimCtrl_en == 1)
	{
		int i = 0;
		UINT32 rimSize = 0;

		RimCtrl_DynamicBlackTh();
		
		pOutput->u1_RimChange = 1;  //egg set always change, need dynamic
		RimCtrl_HW_extract(pParam, pOutput);

		RimCtrl_FastOut(pParam, pOutput);
		RimCtrl_SlowIn(pParam, pOutput);

		RimCtrl_Output(pParam, pOutput);

		RimCtrl_Stable(pParam, pOutput);

		for (i = 0; i < _RIM_NUM; i ++)
		{
			pOutput->u12_Rim_Pre[i] = pOutput->u12_Rim_Result[i];
			pOutput->u12_Rim_Pre_Det[i] = pOutput->u12_Rim_Cur[i];
		}

		//calculate rim ratio
		rimSize = (pOutput->u12_Rim_Result[_RIM_RHT]-pOutput->u12_Rim_Result[_RIM_LFT] + 1)*(pOutput->u12_Rim_Result[_RIM_BOT]-pOutput->u12_Rim_Result[_RIM_TOP] + 1);
		pOutput->u32_rimRatio = (rimSize == 0) ? 128 :((pOutput->u12_out_resolution[_RIM_RHT]*pOutput->u12_out_resolution[_RIM_BOT])<<7) / rimSize;

		pOutput->u1_RimControl_pre = pParam->u1_RimCtrl_en;
	}
	else
	{
		pOutput->u1_RimChange = (pOutput->u1_RimControl_pre !=  pParam->u1_RimCtrl_en) ? 1 : 0;

		pOutput->u12_Rim_Result[_RIM_LFT] = pOutput->u12_out_resolution[_RIM_LFT];
		pOutput->u12_Rim_Result[_RIM_RHT] = pOutput->u12_out_resolution[_RIM_RHT];
		pOutput->u12_Rim_Result[_RIM_TOP] = pOutput->u12_out_resolution[_RIM_TOP];
		pOutput->u12_Rim_Result[_RIM_BOT] = pOutput->u12_out_resolution[_RIM_BOT];

		RimCtrl_Output(pParam, pOutput);
	}

	pOutput->u1_RimControl_pre = pParam->u1_RimCtrl_en;
}

