#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"

//////////////////////////////////////////////////////////////////////////
static VOID LbmcMode_Detect_onlyCnt(const _PARAM_MC_LBMC_SWITCH *pParam, _OUTPUT_MC_LBMC_SWITCH *pOutput, UBYTE band_Type)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT16 u16_cnt_totalNum = (s_pContext->_output_read_comreg.u8_me1_Vbuf_Hsize_rb * s_pContext->_output_read_comreg.u8_me1_Vbuf_Vsize_rb);

	UBYTE  u8_param_Ovlap_s2n_cntTh, u8_param_Lmv_s2n_cntTh, u8_param_Ovlap_n2s_cntTh, u8_param_Lmv_n2s_cntTh, u8_lbmc_mode;
	UINT16 u16_rb_smv_posCnt, u16_rb_smv_negCnt, u16_rb_Lmv_posCnt, u16_rb_Lmv_negCnt;
	if (band_Type == _LBMC_LF_) // LF
	{
		u16_rb_smv_posCnt        = s_pContext->_output_read_comreg.u17_me_posCnt_0_rb;
		u16_rb_smv_negCnt        = s_pContext->_output_read_comreg.u17_me_negCnt_0_rb;
		u16_rb_Lmv_posCnt        = s_pContext->_output_read_comreg.u17_me_posCnt_1_rb;
		u16_rb_Lmv_negCnt        = s_pContext->_output_read_comreg.u17_me_negCnt_1_rb;

		u8_param_Ovlap_s2n_cntTh = pParam->u8_lf_Ovlap_s2n_cntTh;
		u8_param_Lmv_s2n_cntTh   = pParam->u8_lf_Lmv_s2n_cntTh;
		u8_param_Ovlap_n2s_cntTh = pParam->u8_lf_Ovlap_n2s_cntTh;
		u8_param_Lmv_n2s_cntTh   = pParam->u8_lf_Lmv_n2s_cntTh;

		u8_lbmc_mode             = pOutput->u8_lf_lbmcMode;
	}
	else // Hf
	{
		u16_rb_smv_posCnt        = 0x7E90;// s_pContext->_output_read_comreg.u17_me_posCnt_2_rb; // no use before fastmotion rule, & used by fastmotion
		u16_rb_smv_negCnt        = 0x0;// s_pContext->_output_read_comreg.u17_me_negCnt_2_rb;
		u16_rb_Lmv_posCnt        = s_pContext->_output_read_comreg.u17_me_posCnt_3_rb;
		u16_rb_Lmv_negCnt        = s_pContext->_output_read_comreg.u17_me_negCnt_3_rb;

		u8_param_Ovlap_s2n_cntTh = pParam->u8_hf_Ovlap_s2n_cntTh;
		u8_param_Lmv_s2n_cntTh   = pParam->u8_hf_Lmv_s2n_cntTh;
		u8_param_Ovlap_n2s_cntTh = pParam->u8_hf_Ovlap_n2s_cntTh;
		u8_param_Lmv_n2s_cntTh   = pParam->u8_hf_Lmv_n2s_cntTh;

		u8_lbmc_mode             = pOutput->u8_hf_lbmcMode;
	}

	// mode switch
	{
		UINT16 u16_smv_near0_cnt, u16_ovlap_posCnt, u16_ovlap_negCnt;
		UBYTE  u1_n2su_en = 0, u1_n2sd_en = 0, u1_su2n_en = 0, u1_sd2n_en = 0;

		u16_smv_near0_cnt = (u16_cnt_totalNum < (u16_rb_smv_posCnt + u16_rb_smv_negCnt))? 0 : (u16_cnt_totalNum - (u16_rb_smv_posCnt + u16_rb_smv_negCnt));
		u16_ovlap_posCnt  = _MIN_(u16_rb_smv_posCnt + u16_smv_near0_cnt, 0xFFFF);
		u16_ovlap_negCnt  = _MIN_(u16_rb_smv_negCnt + u16_smv_near0_cnt, 0xFFFF);

		u1_n2su_en = ((u16_ovlap_negCnt  << 8) > u16_cnt_totalNum * pParam->u8_lf_Ovlap_n2s_cntTh ) && \
					 ((u16_rb_Lmv_negCnt << 8) > u16_cnt_totalNum * pParam->u8_lf_Lmv_n2s_cntTh);
		u1_su2n_en = ((u16_ovlap_negCnt  << 8) < u16_cnt_totalNum * pParam->u8_lf_Ovlap_s2n_cntTh) || \
					 ((u16_rb_Lmv_negCnt << 8) < u16_cnt_totalNum * pParam->u8_lf_Lmv_s2n_cntTh);

		u1_n2sd_en = ((u16_ovlap_posCnt  << 8) > u16_cnt_totalNum * pParam->u8_lf_Ovlap_n2s_cntTh) && \
					 ((u16_rb_Lmv_posCnt << 8) > u16_cnt_totalNum * pParam->u8_lf_Lmv_n2s_cntTh);
		u1_sd2n_en = ((u16_ovlap_posCnt  << 8) < u16_cnt_totalNum * pParam->u8_lf_Ovlap_s2n_cntTh) || \
					 ((u16_rb_Lmv_posCnt << 8) < u16_cnt_totalNum * pParam->u8_lf_Lmv_s2n_cntTh  );

		if (u8_lbmc_mode == _MC_NORMAL_)
		{
			u8_lbmc_mode = (u1_n2su_en == 1)? _MC_SINGLE_UP_ : ((u1_n2sd_en == 1)? _MC_SINGLE_DOWN_ : _MC_NORMAL_);
		}
		else if (u8_lbmc_mode == _MC_SINGLE_UP_)
		{
			u8_lbmc_mode = (u1_su2n_en == 1)? _MC_NORMAL_ : _MC_SINGLE_UP_;
		}
		else
		{
			u8_lbmc_mode = (u1_sd2n_en == 1)? _MC_NORMAL_ : _MC_SINGLE_DOWN_;
		}

		if(0)
		{
			LogPrintf(DBG_MSG,"ovp_posCnt = %d, ovp_negCnt = %d, Lmv_posCnt = %d, Lmv_negCnt = %d, total_cnt = %d \r\n", \
				u16_ovlap_posCnt, u16_ovlap_negCnt, u16_rb_Lmv_posCnt, u16_rb_Lmv_negCnt, u16_cnt_totalNum);
		}
	}


	if (band_Type == _LBMC_LF_)
	{
		pOutput->u8_lf_lbmcMode = u8_lbmc_mode;
	}
	else
	{
		pOutput->u8_hf_lbmcMode = u8_lbmc_mode;
	}

	// debug printf
	if(0)
	{
		if(band_Type == _LBMC_LF_)
		{
			LogPrintf(DBG_MSG, "lf_lbmc_mode = %d \r\n", pOutput->u8_lf_lbmcMode);
		}
		else
		{
			LogPrintf(DBG_MSG, "Hf_lbmc_mode = %d \r\n", pOutput->u8_hf_lbmcMode);
		}
	}

}
//////////////////////////////////////////////////////////////////////////

VOID Mc_lbmcSwitch_Init( _OUTPUT_MC_LBMC_SWITCH *pOutput)
{
	pOutput->u8_lf_lbmcMode = _MC_NORMAL_;
	pOutput->u8_hf_lbmcMode = _MC_NORMAL_;
}

VOID Mc_lbmcSwitch_Proc(const _PARAM_MC_LBMC_SWITCH *pParam, _OUTPUT_MC_LBMC_SWITCH *pOutput)
{
/*	const _PQLCONTEXT *s_pContext = GetPQLContext();*/

	if (pParam->u8_lbmcSwitch_bypass == 0)
	{
		LbmcMode_Detect_onlyCnt(pParam, pOutput, _LBMC_LF_);
		LbmcMode_Detect_onlyCnt(pParam, pOutput, _LBMC_HF_);
	}
	else
	{
		pOutput->u8_lf_lbmcMode = pParam->u8_lbmcSwitch_bypass - 1;
		pOutput->u8_hf_lbmcMode = pParam->u8_lbmcSwitch_bypass - 1;
	}
}






