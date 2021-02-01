#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/FRC_glb_Context.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"
#include <memc_isr/scalerMEMC.h>

#include <mach/rtk_log.h>

/////
extern UBYTE g_scaler_memc_cadence[_FILM_MEMC_NUM];
UBYTE  u8_filmCad_enterCnt[_FRC_CADENCE_NUM_][_FILM_MOT_NUM];	


///////////////////////////////////////////////////////////////////////////////////////////
UINT32 FrameMotionTH26(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, _PQL_FILM_MOT_TYPE motion_T)
{
#if 0
	UBYTE i = 0;
	UINT32 u27_FrmMotTh = 0;

	/*
		25          20                        10                         0
		 o o o o o o o o o o o o o o o o o o o o o o o o o x
	Sort
	Tick
	*/
	// remove oldest element
	UBYTE u5_remove_index = 25;
	for (i = 0; i < 26; i++)
	{
		if (pOutput->u27_FrmMotionSortTick[i] == 25)
		{
			u5_remove_index = i;
			break;
		}
	}

	for (i = u5_remove_index; i > 0; i--)
	{
		pOutput->u27_FrmMotionSort[i] = pOutput->u27_FrmMotionSort[i-1];
		pOutput->u27_FrmMotionSortTick[i] = pOutput->u27_FrmMotionSortTick[i-1];
	}
	// FrmMotionSort[0] and FrmMotionSortTick[0] are empty now, waiting for new data

	// sorting 26 frame motion
	pOutput->u27_FrmMotionSort[0] = pOutput->u27_ipme_motionPool[motion_T][0];
	pOutput->u27_FrmMotionSortTick[0] = 0;

	// switch number and tick
	for (i = 0; i < 25; i++)
	{
		UINT32 tmp;
		if (pOutput->u27_FrmMotionSort[i] > pOutput->u27_FrmMotionSort[i+1])
		{
			tmp = pOutput->u27_FrmMotionSort[i+1];
			pOutput->u27_FrmMotionSort[i+1] = pOutput->u27_FrmMotionSort[i];
			pOutput->u27_FrmMotionSort[i] = tmp;

			tmp = pOutput->u27_FrmMotionSortTick[i+1];
			pOutput->u27_FrmMotionSortTick[i+1] = pOutput->u27_FrmMotionSortTick[i];
			pOutput->u27_FrmMotionSortTick[i] = tmp;
		}
		else
		{
			break;
		}
	}

	// all tick++
	for (i = 0; i < 26; i++)
	{
		pOutput->u27_FrmMotionSortTick[i]++;

		// remove maximum and 9 minimun frame motion
		if (i >= 9 && i < 25)
		{
			u27_FrmMotTh += pOutput->u27_FrmMotionSort[i];
		}
	}
	u27_FrmMotTh = (u27_FrmMotTh>>1);

	return u27_FrmMotTh;
#else
	return 0;
#endif
}

UINT32 FrameMotionTH8(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, _PQL_FILM_MOT_TYPE motion_T, UINT32 u27_FrmMot_sum, UINT32 u27_maxMot, UINT32 u27_secMot)
{

	// clip maxMot using secMot
	UINT32 u27_maxMot_clip = 0x80000;
	UINT32 u27_secFMot_clip = 0;
	UINT32 u27_maxFMot_clip = 0;

	UINT32 u27_FrmMot_sum_t = u27_FrmMot_sum;
	
	if(u27_secMot < 0x10){
		u27_maxMot_clip = _MIN_(u27_maxMot_clip, u27_maxMot); //max=960x540x255=0x7e11700
	}
	else{
		u27_maxMot_clip = _MAX_(_MIN_(u27_maxMot_clip, u27_maxMot), u27_secMot); 
	}

	if(u27_secMot > 32*(1+pOutput->u27_g_FrmMot_Th[motion_T])){	
		u27_secFMot_clip = _MIN_(0x80000, u27_secMot/32);		//max
		u27_maxFMot_clip = _MIN_(0x80000, u27_maxMot/32);	//sec
		u27_FrmMot_sum_t = u27_FrmMot_sum_t - u27_maxMot + u27_maxFMot_clip -u27_secMot + u27_secFMot_clip;
	}
	else if(u27_secMot > 12*(1+pOutput->u27_g_FrmMot_Th[motion_T])){	
		u27_secFMot_clip = _MIN_(0x80000, u27_secMot/16);
		u27_maxFMot_clip = _MIN_(0x80000, u27_maxMot/16);
		u27_FrmMot_sum_t = u27_FrmMot_sum_t - u27_maxMot + u27_maxFMot_clip -u27_secMot + u27_secFMot_clip;
	}
	else{
		u27_FrmMot_sum_t = u27_FrmMot_sum_t - u27_maxMot + u27_maxMot_clip;
	}


	//for debug
	//if(u27_FrmMot_sum_t == u27_FrmMot_sum)
	//	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 8, 11, 0x1);
	//else
	//	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 8, 11, 0x0);


	return u27_FrmMot_sum;

}

VOID Motion_Sequence_Gen(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl * pOutput, _PQL_FILM_MOT_TYPE motion_T)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE  u8_i = 0;
	UBYTE  u1_FrmSeq = 0, u4_Mot_diffWgt = 0, u4_FrmMot_bigCnt = 0;
	UINT32 u27_cur_FrmMot = 0, u27_FrmMot_sum = 0, u27_FrmMot_Th = 0, u27_FrmMot_min = 0, u27_FrmMot_big = 0;

	UINT32 u27_maxMot = 0;
	UINT32 u27_secMot = 0;

	// distinguish information from motionType
	if(motion_T == _FILM_ALL)
	{
		u27_cur_FrmMot = s_pContext->_output_read_comreg.u27_ipme_aMot_rb;
		u4_Mot_diffWgt = pParam->u4_Mot_all_diffWgt;
		u27_FrmMot_min = pParam->u27_Mot_all_min;
	}
	else // 5 region
	{
		u27_cur_FrmMot = s_pContext->_output_read_comreg.u27_ipme_5Mot_rb[motion_T - 1];
		u4_Mot_diffWgt = pParam->u4_Mot_rgn_diffWgt;
		u27_FrmMot_min = 0;
	}

	// update motion loop.
	for (u8_i = 0; u8_i < 8; u8_i ++)
	{
		if (((pOutput->u32_Mot_sequence[motion_T] >> u8_i) & 0x01) == 1)
		{
			u4_FrmMot_bigCnt ++;
			u27_FrmMot_big += pOutput->u27_ipme_motionPool[motion_T][u8_i];
		}
		//record max & sec motion
		if(pOutput->u27_ipme_motionPool[motion_T][u8_i]>=u27_maxMot)
		{
			u27_secMot = u27_maxMot;
			u27_maxMot = pOutput->u27_ipme_motionPool[motion_T][u8_i];
		}
	}
	u27_FrmMot_big = u4_FrmMot_bigCnt > 0? (u27_FrmMot_big * 2 / u4_FrmMot_bigCnt) : 0x20000;


	for (u8_i = 7; u8_i >0; u8_i --)
	{
		u27_FrmMot_sum                              += pOutput->u27_ipme_motionPool[motion_T][u8_i];
		pOutput->u27_ipme_motionPool[motion_T][u8_i] = pOutput->u27_ipme_motionPool[motion_T][u8_i-1];
	}
	u27_FrmMot_sum                           += pOutput->u27_ipme_motionPool[motion_T][0];
	pOutput->u27_ipme_motionPool[motion_T][0] = u27_cur_FrmMot;

	// adjust frame motion th
#if 0	
	if(motion_T == _FILM_ALL){
		UINT32 u27_Frm26Mot_sum = 0;
		u27_Frm26Mot_sum = FrameMotionTH26(pParam, pOutput, motion_T);

		//UINT32 u32_RB_val = 0;
		//ReadRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 0, 31, &u32_RB_val);
		UBYTE u5_Frm26MotS_wgt = 32;// _MIN_(((u32_RB_val >> 17) & 0x3f), 32);

		u27_FrmMot_sum = ((32-u5_Frm26MotS_wgt)*u27_FrmMot_sum + u5_Frm26MotS_wgt*u27_Frm26Mot_sum)>>5;
	}
#else
	u27_FrmMot_sum = FrameMotionTH8(pParam, pOutput, motion_T, u27_FrmMot_sum, u27_maxMot, u27_secMot);
#endif		
	
	// motion limit
	pOutput->u1_Mot_selBig = 0;
	if ((motion_T == _FILM_ALL) && (u27_cur_FrmMot > u27_FrmMot_big) && (u27_cur_FrmMot > u27_FrmMot_min))
	{
		//u27_cur_FrmMot         = u27_FrmMot_big;
		pOutput->u1_Mot_selBig = 1;
	}

	// motion sequence judge
	u27_FrmMot_Th = (u27_FrmMot_sum >> 3) * u4_Mot_diffWgt >> 3;
	u1_FrmSeq     = (u27_cur_FrmMot > u27_FrmMot_Th && u27_cur_FrmMot > u27_FrmMot_min)? 1 : 0;

	pOutput->u27_g_FrmMot_Th[motion_T] = u27_FrmMot_Th;

	//for 32 10110
	if (pOutput->u8_cur_cadence_Id[motion_T] == _CAD_32)
	{
	    if ((pOutput->u8_phT_phase_Idx[motion_T] == 3) && ((pOutput->u32_Mot_sequence[motion_T]&0x1) == 1))
	    {
	        u1_FrmSeq = (u1_FrmSeq == 1) ? 0 : u1_FrmSeq ;
			pOutput->u27_ipme_motionPool[motion_T][0] = pOutput->u27_quit_smlMot[motion_T];
       }
       }
	//for 32322 -> 32232
	if (pOutput->u8_cur_cadence_Id[motion_T] == _CAD_32322)
	{
		if ((pOutput->u8_phT_phase_Idx[motion_T] == 8) && ((pOutput->u32_Mot_sequence[motion_T]&0x1) == 1))
	    {
	        u1_FrmSeq = (u1_FrmSeq == 1) ? 0 : u1_FrmSeq ;
			pOutput->u27_ipme_motionPool[motion_T][0] = pOutput->u27_quit_smlMot[motion_T];
       }
	}



	pOutput->u32_Mot_sequence[motion_T] = (pOutput->u32_Mot_sequence[motion_T] << 1) | u1_FrmSeq;

       // record small motion^M
       if(pOutput->u32_Mot_sequence[motion_T] == 0xffffffff){
               pOutput->u27_FrmMotion_S[motion_T] = pOutput->u27_ipme_motionPool[motion_T][0];
       }
       else if(pOutput->u32_Mot_sequence[motion_T] == 0x0){
               pOutput->u27_FrmMotion_S[motion_T] = pOutput->u27_ipme_motionPool[motion_T][0];
       }
       else if(u1_FrmSeq==0){
               pOutput->u27_FrmMotion_S[motion_T] = (pOutput->u27_FrmMotion_S[motion_T]+pOutput->u27_ipme_motionPool[motion_T][0])/2;
       }
       pOutput->u27_FrmMotion_S[motion_T] = _CLIP_UBOUND_(pOutput->u27_FrmMotion_S[motion_T], 0x10000);

	if ((motion_T == pOutput->u8_dbg_motion_t) && (((pOutput->u5_dbg_param1_pre & BIT_0) >> 0) == 1) && pOutput->u32_dbg_cnt_hold > 0)
    	{
		printk("[MEMC]%s::rbFM=%d, cFM=%d, th=%d, mseq=%d, ph=%d, qTh=%d\n",__FUNCTION__,s_pContext->_output_read_comreg.u27_ipme_aMot_rb,\
					u27_cur_FrmMot,u27_FrmMot_Th,(pOutput->u32_Mot_sequence[motion_T]&0xFFFF),
					pOutput->u8_phT_phase_Idx[motion_T],pOutput->u27_quit_motTh[motion_T]);
       }

}

UBYTE CadenceDetect_QSwitch_Judge(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl * pOutput, UBYTE motion_T)
{
	// long time black bg + video switch to cadence
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE u1_func_en = pParam->u1_QuickSwitch_En;

	UBYTE u1_is_still = 0;
	UBYTE u1_is_sdtl = 0;
	UBYTE u1_is_sapl = 0;
	UBYTE u1_is_qSwitch = 0;

	static UBYTE u8_still_sapl_sdtl_bg_cnt = 0;

	//UINT32 u32_RB_val1 = 0, u32_RB_val2 = 0;
	//ReadRegister(FRC_TOP__PQL_1__pql_fb_dummy_a8_ADDR, 0, 31, &u32_RB_val1);	
	//ReadRegister(FRC_TOP__PQL_1__pql_fb_dummy_ac_ADDR, 0, 31, &u32_RB_val2);	

	UBYTE u8_sm_th = 0x8;// (u32_RB_val1&0xff);//
	UINT32 u25_sdtl_th = 0x100000;// ((u32_RB_val2>>0)&0xffff) << 4;//
	UINT32 u26_sapl_th = 0x100000;// ((u32_RB_val2>>16)&0xffff) << 4 ;// 960x540x2 = 0xfd200

	UBYTE u8_cnt_max = 0x20;// (u32_RB_val1>>8)&0xff;//
	UBYTE u8_cnt_th = 0x8;// (u32_RB_val1>>16)&0xff;//



	if(u1_func_en == 0 || motion_T!=_FILM_ALL){
		return 0;
	}

	if(pOutput->u27_ipme_motionPool[motion_T][0] < u8_sm_th){
		u1_is_still = 1;
	}

	if(s_pContext->_output_read_comreg.u25_me_aDTL_rb < u25_sdtl_th){
		u1_is_sdtl = 1;
	}

	if((s_pContext->_output_read_comreg.u26_me_aAPLi_rb + s_pContext->_output_read_comreg.u26_me_aAPLp_rb)/2 < u26_sapl_th){
		u1_is_sapl = 1;
	}



	if(u1_is_still && u1_is_sdtl && u1_is_sapl){
		u8_still_sapl_sdtl_bg_cnt++;
	}
	else if(u8_still_sapl_sdtl_bg_cnt > 0){
		u8_still_sapl_sdtl_bg_cnt = u8_still_sapl_sdtl_bg_cnt - 1;
	}
	else{
		u8_still_sapl_sdtl_bg_cnt = 0;
	}


	u8_still_sapl_sdtl_bg_cnt = _CLIP_UBOUND_(u8_still_sapl_sdtl_bg_cnt, u8_cnt_max);

	u1_is_qSwitch = (u8_still_sapl_sdtl_bg_cnt > u8_cnt_th) ? 1 : 0;

#if 0//debug
	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 3, u1_is_qSwitch);
	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 4, 7, u1_is_still);
	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 11, u1_is_sdtl);
	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 12, 15, u1_is_sapl);
	WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 23, u8_still_sapl_sdtl_bg_cnt);

	if ((pParam->u3_DbgPrt_Rgn == 0) && (((pOutput->u5_dbg_param1_pre & BIT_0) >> 0) == 1) && pOutput->u32_dbg_cnt_hold > 0)
    	{
		printk("[MEMC]CadDet_QSwitch::qs=%d, still=%d, sdtl=%d, sapl=%d, cnt=%d\n",	u1_is_qSwitch,
																			u1_is_still,
																			u1_is_sdtl,
																			u1_is_sapl,
																			u8_still_sapl_sdtl_bg_cnt);
       }
#endif


	return u1_is_qSwitch;

}


VOID CadenceDetect(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, UBYTE motion_T)
{
	UBYTE u8_i = 0, u8_j = 0;
	UBYTE  u1_match_flag = 0, u1_match_flag_def = 0;
	UBYTE u8_enter_th    = 0;
	UINT32 u32_match_seq_sft = 0;

	UBYTE u1_qSwitch_cond = CadenceDetect_QSwitch_Judge(pParam, pOutput, motion_T);

	pOutput->u8_det_cadence_Id[motion_T] = _CAD_VIDEO;

	for (u8_i = 1; u8_i < _FRC_CADENCE_NUM_; u8_i ++)
	{
		// if match?
		u1_match_flag = 0;
		u32_match_seq_sft = frc_cadTable[u8_i].cad_seq;
		for (u8_j = 0; u8_j < frc_cadTable[u8_i].cad_len; u8_j ++)
		{
			u32_match_seq_sft = (u32_match_seq_sft>>1) | ((u32_match_seq_sft&0x1)<<(frc_cadTable[u8_i].cad_len-1));

			if ((pOutput->u32_Mot_sequence[motion_T] & frc_cadTable[u8_i].cad_check) == u32_match_seq_sft)
			{
				u1_match_flag = 1;
				break;
			}
		}

		// statistics of enter count
		#if 0
		u8_enter_th = (u8_i == _CAD_22)? ((pParam->u4_enter_22_cntGain-1) * frc_cadTable[u8_i].cad_len + 1):
			          (u8_i == _CAD_32)? ((pParam->u4_enter_32_cntGain-1) * frc_cadTable[u8_i].cad_len + 1):
			          (u8_i == _CAD_11i23) ? frc_cadTable[u8_i].cad_len :	((pParam->u4_enter_else_cntGain-1) * frc_cadTable[u8_i].cad_len + 1) ;
		#else // K2 use.
		u8_enter_th = (u8_i == _CAD_22) ? pParam->u4_enter_22_cntGain*frc_cadTable[u8_i].cad_len :
			          (u8_i == _CAD_32) ? pParam->u4_enter_32_cntGain*frc_cadTable[u8_i].cad_len :
				   (u8_i == _CAD_11i23) ? frc_cadTable[u8_i].cad_len :
				   (u8_i == _CAD_44 || u8_i==_CAD_55|| u8_i==_CAD_66) ? (pParam->u4_enter_else_cntGain*frc_cadTable[u8_i].cad_len)/2 :
				   pParam->u4_enter_else_cntGain*frc_cadTable[u8_i].cad_len ;
		#endif

		// dynamic control enter_th if switch from video to others
		if(pOutput->u8_pre_cadence_Id[motion_T] == _CAD_VIDEO && u1_qSwitch_cond){
			u8_enter_th =  (u8_i == _CAD_32 ) ? 1 : u8_enter_th;
			u8_enter_th =  (u8_i == _CAD_32322) ? (frc_cadTable[u8_i].cad_len - 1) : u8_enter_th;
		}


		u8_filmCad_enterCnt[u8_i][motion_T] = (u1_match_flag == 1)? _CLIP_(u8_filmCad_enterCnt[u8_i][motion_T] + 1, 0, u8_enter_th + 4) : 0;

		// ex. for _CAD_32, judge cadence detect successful if motionSeq == 10010.
		u1_match_flag_def = (pOutput->u32_Mot_sequence[motion_T] & frc_cadTable[u8_i].cad_check) == frc_cadTable[u8_i].cad_seq? 1 : 0;
		if (u8_filmCad_enterCnt[u8_i][motion_T] > u8_enter_th && u1_match_flag_def && ((pParam->u32_filmDet_cadence_en >> u8_i) & 1) == 1)
		{
			pOutput->u8_det_cadence_Id[motion_T] = u8_i;
		}
	}

	if ((motion_T == pOutput->u8_dbg_motion_t) && (((pOutput->u5_dbg_param1_pre & BIT_1) >> 1) == 1) && pOutput->u32_dbg_cnt_hold > 0)
	{
		printk("[MEMC]%s::det_cadence_Id=%d \n",__FUNCTION__,pOutput->u8_det_cadence_Id[motion_T]);
	}
}

UBYTE Film_PreFrm_MotWeight_autoGen(UINT32 u27_PreMot, UINT32 u27_CurMot)
{
	UBYTE u5_PreWgt          = 28;

	u27_CurMot  = u27_CurMot + 1;
	u27_PreMot  = u27_PreMot + 1;

	u5_PreWgt   = u27_PreMot * 1   > u27_CurMot? 12 : \
		         (u27_PreMot * 128 < u27_CurMot? 31 : \
			   	 (u27_PreMot * 64  < u27_CurMot? 30 : \
			   	 (u27_PreMot * 32  < u27_CurMot? 29 : \
			   	 (u27_PreMot * 16  < u27_CurMot? 28 : \
			   	 (u27_PreMot * 8   < u27_CurMot? 26 : \
			   	 (u27_PreMot * 4   < u27_CurMot? 24 : \
			   	 (u27_PreMot * 2   < u27_CurMot? 20 : \
			   	 (u27_PreMot * 1   < u27_CurMot? 18 : 28))))))));

	return u5_PreWgt;
}

UINT32 Film_rgnSMot_Avg(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, UBYTE motion_T)
{
	UINT32 u27_rgnSMot_avg = pOutput->u27_quit_smlMot[motion_T];

	switch(motion_T)
	{
		case _FILM_5RGN_TOP:
			u27_rgnSMot_avg = (pOutput->u27_quit_smlMot[_FILM_5RGN_BOT] + pOutput->u27_quit_smlMot[_FILM_5RGN_CEN])/2;
			break;
		case _FILM_5RGN_BOT:
			u27_rgnSMot_avg = (pOutput->u27_quit_smlMot[_FILM_5RGN_TOP] + pOutput->u27_quit_smlMot[_FILM_5RGN_CEN])/2;
			break;
		case _FILM_5RGN_LFT:
			u27_rgnSMot_avg = (pOutput->u27_quit_smlMot[_FILM_5RGN_RHT] + pOutput->u27_quit_smlMot[_FILM_5RGN_CEN])/2;
			break;
		case _FILM_5RGN_RHT:
			u27_rgnSMot_avg = (pOutput->u27_quit_smlMot[_FILM_5RGN_LFT] + pOutput->u27_quit_smlMot[_FILM_5RGN_CEN])/2;
			break;
		default:
			break;
	}



	return u27_rgnSMot_avg;
	
}

VOID Film_motThr_calc(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, UBYTE motion_T)
{
	UBYTE  u8_preCad_id           = pOutput->u8_pre_cadence_Id[motion_T] < _FRC_CADENCE_NUM_ ? pOutput->u8_pre_cadence_Id[motion_T] : _CAD_VIDEO;
	UBYTE  u1_curCad_motFlag      = cadence_seqFlag(frc_cadTable[u8_preCad_id], pOutput->u8_phase_Idx[motion_T]);
	UBYTE  u1_curFrm_isBig        = u8_preCad_id != _CAD_VIDEO? (u1_curCad_motFlag == 1? 1 : 0) : \
		                                 ((pOutput->u32_Mot_sequence[motion_T] & 0x01) ==1? 1 : 0);

	UBYTE  u5_preFrm_adapt_big_motWgt = 0;
	UBYTE  u5_preFrm_adapt_sml_motWgt = 0;
	UINT32 u27_pre_bigMot         = pOutput->u27_quit_bigMot[motion_T];
	UINT32 u27_pre_smlMot         = pOutput->u27_quit_smlMot[motion_T];
	UINT32 u27_curFrm_mot         = pOutput->u27_ipme_motionPool[motion_T][0];

	UINT16 u16_SMot_Th = 256;
	UBYTE u8_SMot_ratio = 20;

	// motion IIR
/*	u5_preFrm_adapt_motWgt = (pParam->u1_quit_motWgt_auto_en == 0)? 28 : \
		                      Film_PreFrm_MotWeight_autoGen(pOutput->u27_quit_motTh[motion_T], u27_curFrm_mot); // u0.5*/
	u5_preFrm_adapt_big_motWgt = (pParam->u1_quit_motWgt_auto_en == 0)? 28 : \
                 Film_PreFrm_MotWeight_autoGen(pOutput->u27_quit_bigMot[motion_T], u27_curFrm_mot); // u0.5

	u5_preFrm_adapt_sml_motWgt = (pParam->u1_quit_motWgt_auto_en == 0)? 28 : \
                 Film_PreFrm_MotWeight_autoGen(pOutput->u27_quit_smlMot[motion_T], u27_curFrm_mot); // u0.5


	if (u1_curFrm_isBig == 1)
	{
		pOutput->u27_quit_bigMot[motion_T] = _2Val_RndBlending_(u27_pre_bigMot, u27_curFrm_mot, u5_preFrm_adapt_big_motWgt, 5);
	}
	else
	{
		pOutput->u27_quit_smlMot[motion_T] = _2Val_RndBlending_(u27_pre_smlMot, u27_curFrm_mot, u5_preFrm_adapt_sml_motWgt, 5);
	}

	pOutput->u27_quit_motTh[motion_T] = (pOutput->u27_quit_bigMot[motion_T] * pParam->u4_quit_bigMot_wgt + \
										 pOutput->u27_quit_smlMot[motion_T] * pParam->u4_quit_smlMot_wgt) >> 3;

	//for mixmode@1112/11112, 1112/11112 is not easy to quit.
	if( motion_T!=_FILM_ALL && motion_T!=_FILM_5RGN_CEN 
		&& (pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN]==_CAD_1112 ||pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN]==_CAD_11112))
	{
		UINT32 u27_rgnSmot_avg = Film_rgnSMot_Avg(pParam, pOutput, motion_T);
		UINT32 u27_bMot_mapping = (pOutput->u27_quit_bigMot[motion_T] > 8*pOutput->u27_quit_smlMot[motion_T]) ? (pOutput->u27_quit_bigMot[motion_T]/8) : 
								(pOutput->u27_quit_bigMot[motion_T] > 4*pOutput->u27_quit_smlMot[motion_T]) ? (pOutput->u27_quit_bigMot[motion_T]/4) : 
								(pOutput->u27_quit_bigMot[motion_T]/2);

		if(u27_rgnSmot_avg < u16_SMot_Th && pOutput->u27_quit_smlMot[motion_T] > u8_SMot_ratio*(1+u27_rgnSmot_avg))
		{
			pOutput->u27_quit_motTh[motion_T] = (u27_bMot_mapping * _MIN_(1, pParam->u4_quit_bigMot_wgt/2) + \
											u27_rgnSmot_avg* pParam->u4_quit_smlMot_wgt) >> 3;
		}

	}
	//--

	if ((motion_T == pOutput->u8_dbg_motion_t) && (((pOutput->u5_dbg_param1_pre & BIT_4) >> 4) == 1) && pOutput->u32_dbg_cnt_hold > 0)
	{
		printk("[MEMC]%s::q_mTh=%d, q_bM=%d, q_sM=%d\n",__FUNCTION__,pOutput->u27_quit_motTh[motion_T],\
			pOutput->u27_quit_bigMot[motion_T], pOutput->u27_quit_smlMot[motion_T]);
	}

}

VOID Film_occasionally_fastOut(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput)
{
	UBYTE u8_curFrm_det_cadId = pOutput->u8_det_cadence_Id[_FILM_ALL];
	UBYTE u8_preFrm_cadId     = pOutput->u8_pre_cadence_Id[_FILM_ALL];

	pOutput->u1_cad_fastOut_true  = 0;
	if (u8_preFrm_cadId == _CAD_32) // rule 1: 32->22 / 32322 / 3223
	{
		if (u8_curFrm_det_cadId == _CAD_22 || u8_curFrm_det_cadId == _CAD_32322 || u8_curFrm_det_cadId == _CAD_3223)
		{
			pOutput->u8_pre_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
			pOutput->u1_cad_fastOut_true          = 1;
		}
	}
	else if (u8_preFrm_cadId == _CAD_22) // 22 -> 32 / 44 / 22224 / 2224 / 11'23
	{
		if (u8_curFrm_det_cadId == _CAD_32 || u8_curFrm_det_cadId == _CAD_44 || u8_curFrm_det_cadId == _CAD_22224 || \
			u8_curFrm_det_cadId == _CAD_2224 || u8_curFrm_det_cadId == _CAD_11i23)
		{
			pOutput->u8_pre_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
			pOutput->u1_cad_fastOut_true          = 1;
		}
	}
	else if (u8_preFrm_cadId == _CAD_11112) // 11112 -> 22. 11i23,32322,22224, not easy to quit
	{
		if (u8_curFrm_det_cadId == _CAD_22 || u8_curFrm_det_cadId == _CAD_11i23 || u8_curFrm_det_cadId == _CAD_32322 || u8_curFrm_det_cadId == _CAD_22224)
		{
			pOutput->u8_pre_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
			pOutput->u1_cad_fastOut_true          = 1;
		}
	}
	else	if(u8_preFrm_cadId == _CAD_1112)// not easy to quit
	{
		if (u8_curFrm_det_cadId == _CAD_32 ||u8_curFrm_det_cadId == _CAD_3223 || u8_curFrm_det_cadId == _CAD_122 )
		{
			pOutput->u8_pre_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
			pOutput->u1_cad_fastOut_true          = 1;
		}
	}

	// 32322 bad-edit adjust, for quick switch 32
	if(u8_preFrm_cadId == _CAD_32322)
	{
		UBYTE u8_cad_enter_cnt_th =  frc_cadTable[_CAD_32322].cad_outLen + 4 - frc_cadTable[_CAD_32].cad_outLen;
		if(u8_curFrm_det_cadId == _CAD_32 && u8_filmCad_enterCnt[_CAD_32][_FILM_ALL]> u8_cad_enter_cnt_th)
		{
			pOutput->u8_pre_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
			pOutput->u1_cad_fastOut_true          = 1;
		}
	}

}

VOID FilmEnter(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, UBYTE motion_T)
{
	UBYTE mot_isSml = 0;

	if(motion_T >= _FILM_MOT_NUM){
		LogPrintf(DBG_WARNING,"[%s]Invalid Motion_Type:%d!!\n",__FUNCTION__,motion_T);
		motion_T = _FILM_ALL;
	}
	mot_isSml = (pOutput->u27_ipme_motionPool[motion_T][0] < pOutput->u27_quit_motTh[motion_T])? 1 : 0;
	if ((pOutput->u8_det_cadence_Id[motion_T] != _CAD_VIDEO) && mot_isSml)
	{
		pOutput->u8_cur_cadence_Id[motion_T] = pOutput->u8_det_cadence_Id[motion_T];
	}
}

VOID FilmQuit_BadEditPatch(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput)
{
	UINT32 flag = 0;
	
	UBYTE j = 0;
	UBYTE u8_checkbit = 16;
	UBYTE u8_totalcheck = 0;
	UBYTE u1_match32322_flag = 0;
	UINT32 u32_match_data_temp = 0;

	u1_match32322_flag = 0;
	u8_totalcheck = u8_checkbit - 5;
	for(j = 0;j <= u8_totalcheck; j++)
	{
		u32_match_data_temp = ((pOutput->u32_Mot_sequence[_FILM_ALL] & ((1<<u8_checkbit)-1))>>j);// at least check 16bits for 32322
		// confirm 32322 seq to quit
		if ((u32_match_data_temp & frc_cadTable[_CAD_32].cad_check) == 0x15)	// 10101(part of 32322)
		{
			u1_match32322_flag = 1;
		}
	}

	if(pOutput->u8_pre_cadence_Id[_FILM_ALL] == _CAD_32322	
		&& (u8_filmCad_enterCnt[_CAD_32322][_FILM_ALL] >= 1 || (pOutput->u32_Mot_sequence[_FILM_ALL] & 0x3f) == 0)
		&& (u8_filmCad_enterCnt[_CAD_32][_FILM_ALL] <= u8_totalcheck || u1_match32322_flag == 1) // avoid 32seq
		&& (pParam->u1_BadEditSlowOut_En == 1))
	{
		pOutput->u8_quit_cnt[_FILM_ALL] = (pOutput->u8_quit_cnt[_FILM_ALL] >= 1) ? pOutput->u8_quit_cnt[_FILM_ALL]-1 : 0;
		flag = 1;
	}

	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 24, 27, flag);
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 28, 31, (UINT32)u1_match32322_flag);
	
}

VOID FilmQuit(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, UBYTE motion_T)
{
	UBYTE  u8_preCad_id = 0,u1_curCad_motFlag = 0;
	UINT32 u27_curFrm_mot = 0,u27_quit_motTh = 0;
	UBYTE u8_pre_quit_prd = 0,u8_pre_quit_cnt = 0,u8_quit_prd_th = 0;

	UBYTE u8_quitCntTh = pParam->u8_quit_cnt_th;
	UBYTE u3_quitCntOffset = 3;

	if(motion_T >= _FILM_MOT_NUM){
		LogPrintf(DBG_WARNING,"[%s]Invalid Motion_Type:%d!!\n",__FUNCTION__,motion_T);
		motion_T = _FILM_ALL;
	}
	u8_preCad_id       = pOutput->u8_pre_cadence_Id[motion_T];
	
	if(u8_preCad_id >= _FRC_CADENCE_NUM_){
		LogPrintf(DBG_WARNING,"[%s]Invalid u8_preCad_id:%d,motion=%d.Resume!\n",\
			__FUNCTION__,u8_preCad_id,motion_T);
		u8_preCad_id = _CAD_VIDEO;
	}
	u1_curCad_motFlag  = cadence_seqFlag(frc_cadTable[u8_preCad_id], pOutput->u8_phase_Idx[motion_T]);

	u27_curFrm_mot     = pOutput->u27_ipme_motionPool[motion_T][0];
	u27_quit_motTh     = pOutput->u27_quit_motTh[motion_T];

	u8_pre_quit_prd     = pOutput->u8_quit_prd[motion_T];
	u8_pre_quit_cnt     = pOutput->u8_quit_cnt[motion_T];
	u8_quit_prd_th      = ((u8_preCad_id == _CAD_1112) || (u8_preCad_id == _CAD_11112)) ? pParam->u8_quit_prd_th/2 : pParam->u8_quit_prd_th;


	// bigger quitCntTh if many '0' in sequence => bad edit need
	if((motion_T == _FILM_ALL) && (pOutput->u8_pre_cadence_Id[motion_T] == _CAD_32322)) 
	{
		u8_quitCntTh = u8_quitCntTh + u3_quitCntOffset;
	}
	else if((motion_T == _FILM_ALL) && (pOutput->u8_pre_cadence_Id[motion_T] == _CAD_22)) // CG_Pattern, video->22(very small motion),not easy to quit
	{
		u8_quitCntTh = (u8_quitCntTh > 1) ? (u8_quitCntTh -1) : 0;
	}
	
	// quit state-machine
	if (u1_curCad_motFlag == 0)
	{
		if (u27_curFrm_mot > u27_quit_motTh)
		{
			pOutput->u8_quit_cnt[motion_T] = _CLIP_(u8_pre_quit_cnt + 1, 0, u8_quitCntTh + 4);
			pOutput->u8_quit_prd[motion_T] = 0;
		}
		else
		{
			pOutput->u8_quit_prd[motion_T] = _MIN_(u8_pre_quit_prd + 1, u8_quit_prd_th);
			pOutput->u8_quit_cnt[motion_T] = pOutput->u8_quit_prd[motion_T] == u8_quit_prd_th ? (u8_pre_quit_cnt <= 1? 0 : u8_pre_quit_cnt-1) : u8_pre_quit_cnt;
		}
	}

	// for 32322 bad-editting 
	if(motion_T == _FILM_ALL){
		FilmQuit_BadEditPatch(pParam, pOutput);
		pOutput->u8_quit_cnt[motion_T] = _CLIP_UBOUND_(pOutput->u8_quit_cnt[motion_T], (u8_quitCntTh+4));
	}	 


	if ((motion_T == pOutput->u8_dbg_motion_t) && (((pOutput->u5_dbg_param1_pre & BIT_3) >> 3) == 1) && pOutput->u32_dbg_cnt_hold > 0)
	{
		printk("[MEMC]%s::quit_cnt=%d, phase_ID=%d \n",__FUNCTION__,pOutput->u8_quit_cnt[motion_T],pOutput->u8_phase_Idx[motion_T]);
	}

	// quit judge
	if (pOutput->u8_quit_cnt[motion_T] >= u8_quitCntTh || (pOutput->u1_mixMode == 1))
	{
		pOutput->u8_cur_cadence_Id[motion_T] = _CAD_VIDEO;
		pOutput->u8_quit_cnt[motion_T]       = 0;
		pOutput->u8_quit_prd[motion_T]       = 0;
	}
	else
	{
		pOutput->u8_cur_cadence_Id[motion_T] = u8_preCad_id;
	}
}

VOID PhaseIdx_set(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput, UBYTE motion_T)
{
	UBYTE u8_cur_cadId = 0;

	if(motion_T >= _FILM_MOT_NUM){
		LogPrintf(DBG_WARNING,"[%s]Invalid Motion_Type:%d!!\n",__FUNCTION__,motion_T);
		motion_T = _FILM_ALL;
	}
	u8_cur_cadId = pOutput->u8_cur_cadence_Id[motion_T];
	if(u8_cur_cadId >= _FRC_CADENCE_NUM_){
		LogPrintf(DBG_WARNING,"[%s]Invalid u8_cur_cadId:%d,motion=%d.Resume!\n",\
			__FUNCTION__,u8_cur_cadId,motion_T);
		u8_cur_cadId = _CAD_VIDEO;
	}
	if (u8_cur_cadId == _CAD_VIDEO)
	{
		pOutput->u8_phase_Idx[motion_T] = 0;
	}
	else
	{
		pOutput->u8_phase_Idx[motion_T] ++;

		if (pOutput->u8_phase_Idx[motion_T] == frc_cadTable[u8_cur_cadId].cad_outLen)
		{
			pOutput->u8_phase_Idx[motion_T] = 0;
		}
	}

	// resync rule
	if ((pOutput->u32_Mot_sequence[motion_T] & frc_cadTable[u8_cur_cadId].cad_check) == frc_cadTable[u8_cur_cadId].cad_seq \
		&& pOutput->u8_phase_Idx[motion_T] != 0)
	{
		pOutput->u1_cad_resync_true[motion_T] = 0;
			pOutput->u8_phase_Idx[motion_T] = 0;
		}


    ////////////
    if (u8_cur_cadId == _CAD_VIDEO)
	{
		pOutput->u8_phT_phase_Idx[motion_T] = 0;
}
//	else if (u8_cur_cadId == _CAD_32)
//	{
//	    UBYTE  u1_curCad_motFlag      = cadence_seqFlag(frc_cadTable[u8_cur_cadId], pOutput->u8_phT_phase_Idx[motion_T]);
//	    UBYTE  u1_curFrm_isBig        = (u1_curCad_motFlag == 1? 1 : 0);
//		UBYTE  u1_seqFrm_isBig        = (pOutput->u32_Mot_sequence[motion_T] & 0x01) ==1? 1 : 0;

//		if (u1_seqFrm_isBig == u1_curFrm_isBig)
//		{
//		    pOutput->u8_phT_phase_Idx[motion_T] ++;
//		}
//		else if (pOutput->u8_phT_phase_Idx[motion_T] == 2 || pOutput->u8_phT_phase_Idx[motion_T] == 3)
//		{
//		    pOutput->u8_phT_phase_Idx[motion_T] ++;
//		}
//		else
//		{
//		    pOutput->u8_phT_phase_Idx[motion_T] = pOutput->u8_phT_phase_Idx[motion_T] + 2;
//		}


//		if (pOutput->u8_phT_phase_Idx[motion_T] >= frc_cadTable[u8_cur_cadId].cad_outLen)
//		{
//			pOutput->u8_phT_phase_Idx[motion_T] = pOutput->u8_phT_phase_Idx[motion_T] - frc_cadTable[u8_cur_cadId].cad_outLen;
//		}
//	}
	else
	{
		pOutput->u8_phT_phase_Idx[motion_T] ++;

		if (pOutput->u8_phT_phase_Idx[motion_T] == frc_cadTable[u8_cur_cadId].cad_outLen)
		{
			pOutput->u8_phT_phase_Idx[motion_T] = 0;
       }
       }



	if ((pOutput->u32_Mot_sequence[motion_T] & frc_cadTable[u8_cur_cadId].cad_check) == frc_cadTable[u8_cur_cadId].cad_seq \
	&& pOutput->u8_phT_phase_Idx[motion_T] != 0)// && pParam->u1_resync_en == 1
	{
		if (u8_cur_cadId == _CAD_32322 && (pOutput->u8_phT_phase_Idx[motion_T] == 7))
		{
			// 32322 <-> 32232 has no re-sync.
		}
		else if ((u8_cur_cadId == _CAD_32) && (pOutput->u8_phT_phase_Idx[motion_T] == 2))
		{
		    //32<->23 has no resync
		}
		else
		{
			pOutput->u8_phT_phase_Idx[motion_T] = 0;
		}
	}
}

VOID MixModeQuit(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput)
{
       UBYTE u1_quit_cond1 = 0;
       UBYTE u1_quit_cond1_dly = 0;
       UINT32 u27_smot_th_l = _MIN_(pParam->u27_mixMode_rgnMove_minMot, 0x200);

       UINT32 u27_smot_th_h = 0x3072;//(u32_RB_val&0x7fffffff);

       // rgn0=rgn1=rgn2=rgn3=rgn4
       u1_quit_cond1 = ((pOutput->u8_pre_cadence_Id[_FILM_5RGN_LFT]==pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN])
                               && (pOutput->u8_pre_cadence_Id[_FILM_5RGN_RHT]==pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN])
                               && (pOutput->u8_pre_cadence_Id[_FILM_5RGN_TOP]==pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN])
                               && (pOutput->u8_pre_cadence_Id[_FILM_5RGN_BOT]==pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN])
                               && (pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN]!=_CAD_VIDEO)) ? 1 : u1_quit_cond1;

       //avoid: 1. center area smot < th, bmot > N*th
       //           2. t/b/l/r area smot > M*th
       u1_quit_cond1_dly = ((pOutput->u27_quit_smlMot[_FILM_5RGN_CEN] < u27_smot_th_l) && (pOutput->u27_quit_bigMot[_FILM_5RGN_CEN] > 8*u27_smot_th_l))
                                       && ((_MIN_(pOutput->u27_quit_smlMot[_FILM_5RGN_LFT], pOutput->u27_quit_bigMot[_FILM_5RGN_LFT]) > 4*u27_smot_th_l)
                                               ||(_MIN_(pOutput->u27_quit_smlMot[_FILM_5RGN_RHT], pOutput->u27_quit_bigMot[_FILM_5RGN_RHT]) > 4*u27_smot_th_l)
                                               ||(_MIN_(pOutput->u27_quit_smlMot[_FILM_5RGN_TOP], pOutput->u27_quit_bigMot[_FILM_5RGN_TOP]) > 4*u27_smot_th_l)

                                               ||(_MIN_(pOutput->u27_quit_smlMot[_FILM_5RGN_BOT], pOutput->u27_quit_bigMot[_FILM_5RGN_BOT]) > 4*u27_smot_th_l));

       if(u1_quit_cond1 && (!u1_quit_cond1_dly)){
               pOutput->u8_mixMode_cnt = (pOutput->u8_mixMode_cnt>2)? (pOutput->u8_mixMode_cnt-2) : 0;
       }

       // 5 region motion big => depend on full region detect
       UBYTE u5_quit_cond2 = 0;
       UBYTE i = 0;
       for(i = _FILM_5RGN_TOP; i <= _FILM_5RGN_CEN; i++){
               if(pOutput->u27_FrmMotion_S[i]> u27_smot_th_h) // th = 0x3072
                       u5_quit_cond2 = u5_quit_cond2 + (1<<i);
       }

       if(u5_quit_cond2 == 0x1f /*&& pParam->u1_MixModeQuitBySmv_En*/){
               pOutput->u8_mixMode_cnt = (pOutput->u8_mixMode_cnt>1)? (pOutput->u8_mixMode_cnt-1) : 0;
       }



}
VOID MixMode_detect(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput)
{
	UBYTE u1_mixMode_status = 0, u1_badMot_status  = 0, u1_badMot_flag = 0, u1_badCad_flag = 0;
	UBYTE u8_k = 0,u8_preCad_Id = 0,u1_preCad_motFlag = 0,u1_ipmeMot_flag = 0;
	UBYTE u8_dbg_1 = 0, u8_dbg_2 = 0, u8_dbg_3 = 0;

	static UBYTE u8_maxPossible_CadId = 0;

	u8_preCad_Id      = pOutput->u8_pre_cadence_Id[_FILM_ALL];
	if(u8_preCad_Id >= _FRC_CADENCE_NUM_){
		LogPrintf(DBG_WARNING,"[%s]Invalid u8_preCad_Id:%d,motion=%d.Resume!\n",\
			__FUNCTION__,u8_preCad_Id,_FILM_ALL);
		u8_preCad_Id = _CAD_VIDEO;
	}
	u1_preCad_motFlag = cadence_seqFlag(frc_cadTable[u8_preCad_Id], pOutput->u8_phase_Idx[_FILM_ALL]);
	u1_ipmeMot_flag  = pOutput->u32_Mot_sequence[_FILM_ALL] & 0x01;

	if ((u8_preCad_Id != _CAD_VIDEO && u1_preCad_motFlag == 0) || (u8_preCad_Id == _CAD_VIDEO && u1_ipmeMot_flag == 0))
	{
		UBYTE u8_mixMode_cnt_p1 = 0, u8_mixMode_cnt_n1 = 0;

		for (u8_k = _FILM_5RGN_TOP; u8_k <= _FILM_5RGN_CEN; u8_k ++)
		{
			UBYTE  u8_preCad_Id_rgn  = pOutput->u8_pre_cadence_Id[u8_k];

			//UINT32 u28_smlMot_xGain  = (pOutput->u27_quit_smlMot[u8_k] * pParam->u4_mixMode_rgnMove_motWgt >> 3);
			UINT32 u27_smlMot = (u8_k==_FILM_5RGN_CEN) ? pOutput->u27_quit_smlMot[_FILM_ALL] : pOutput->u27_quit_smlMot[_FILM_5RGN_CEN];
			UINT32 u28_smlMot_xGain  = (u27_smlMot * pParam->u4_mixMode_rgnMove_motWgt >> 3);
			UINT32 u28_smlMot_badTh  = (u8_k == _FILM_5RGN_CEN)? _MIN_(u28_smlMot_xGain, 0x3000/*0x5000*/) : u28_smlMot_xGain;
			UINT32 u28_badMot_Th     = _MAX_(u28_smlMot_badTh, pParam->u27_mixMode_rgnMove_minMot);

			u1_badMot_flag    = pOutput->u27_ipme_motionPool[u8_k][0] > u28_badMot_Th?   1 : 0;
			UBYTE u1_badCad_cond1 = (pOutput->u1_mixMode == 0 &&(u8_preCad_Id == _CAD_VIDEO || u8_preCad_Id_rgn != u8_preCad_Id));
                       UBYTE u1_badCad_cond2 = (pOutput->u1_mixMode == 1 &&((u8_preCad_Id_rgn != pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN] && u8_k!=_FILM_5RGN_CEN)
                                                                                                                       ||(u8_preCad_Id_rgn == _CAD_VIDEO && u8_k==_FILM_5RGN_CEN)));
                       u1_badCad_flag    = (u1_badCad_cond1 || u1_badCad_cond2)? 1 : 0;
			//u1_badCad_flag    = (u8_preCad_Id == _CAD_VIDEO || u8_preCad_Id_rgn != u8_preCad_Id)? 1 : 0;

			u8_dbg_1 = (u8_dbg_1<<1) |u1_badMot_flag;
			u8_dbg_2 = (u8_dbg_2<<1) |u1_badCad_cond1;
			u8_dbg_3 = (u8_dbg_3<<1) |u1_badCad_cond2;			

			//u1_badMot_status  = u1_badMot_status | u1_badMot_flag;
			u1_badMot_status  = u1_badMot_status | (u1_badMot_flag && pParam->u1_mixMode_rgnEn[u8_k-1]);
			u1_mixMode_status = u1_mixMode_status | (u1_badMot_flag && u1_badCad_flag && pParam->u1_mixMode_rgnEn[u8_k-1]);
		}

		u8_mixMode_cnt_n1 = pOutput->u8_mixMode_cnt > 0? (pOutput->u8_mixMode_cnt - 1) : 0;
		u8_mixMode_cnt_p1 = pOutput->u8_mixMode_cnt == pParam->u8_mixMode_cnt_max? pOutput->u8_mixMode_cnt : (pOutput->u8_mixMode_cnt + 1);
		pOutput->u8_mixMode_cnt =  u1_mixMode_status == 1?  u8_mixMode_cnt_p1 : (u1_badMot_status == 1?  pOutput->u8_mixMode_cnt : u8_mixMode_cnt_n1);
	}

	pOutput->u8_mixMode_cnt = _CLIP_(pOutput->u8_mixMode_cnt, 0, pParam->u8_mixMode_cnt_max);
		
	MixModeQuit(pParam, pOutput);

	u8_maxPossible_CadId = (pOutput->u1_mixMode==0) ? u8_preCad_Id : u8_maxPossible_CadId;
	if(!(pOutput->u8_pre_cadence_Id[_FILM_ALL]==_CAD_VIDEO && pOutput->u1_mixMode==0))
	{
		UBYTE u8_mxMode_enterCnt_th = (u8_maxPossible_CadId==_CAD_1112 || u8_maxPossible_CadId==_CAD_11112) ?
									(pParam->u8_mixMode_enter_cntTh/2) : pParam->u8_mixMode_enter_cntTh;//for mixmode@1112/11112, 1112/11112 is not easy to enter
		pOutput->u1_mixMode = (pOutput->u8_mixMode_cnt >= u8_mxMode_enterCnt_th)? 1 : 0;
	}
	
	if((((pOutput->u5_dbg_param1_pre & BIT_2) >> 2) == 1) && pOutput->u32_dbg_cnt_hold > 0)
	{
		printk("(%d,%d,%d)(%d,%d,%d,%d,%d)(%d,%d)(%d)\n", u8_dbg_1,u8_dbg_2,u8_dbg_3,
					pOutput->u8_pre_cadence_Id[_FILM_5RGN_TOP],pOutput->u8_pre_cadence_Id[_FILM_5RGN_BOT],
					pOutput->u8_pre_cadence_Id[_FILM_5RGN_LFT],pOutput->u8_pre_cadence_Id[_FILM_5RGN_RHT],pOutput->u8_pre_cadence_Id[_FILM_5RGN_CEN],
					pOutput->u8_mixMode_cnt,pOutput->u1_mixMode, u8_preCad_Id);
	}
}

VOID MidLayer_Film_phTable_proc(VOID)
{

}

VOID FilmDetect_UpdateOutput(_OUTPUT_FilmDetectCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE u8_k = 0;
	
	for(u8_k = _FILM_ALL; u8_k < _FILM_MOT_NUM; u8_k++)
	{
		pOutput->u8_cur_cadence_out[u8_k] = pOutput->u8_cur_cadence_Id[u8_k];
		pOutput->u8_phT_phase_Idx_out[u8_k] = pOutput->u8_phT_phase_Idx[u8_k];

		if(CAD_F ==PQL_FRCCaseSupportJudge(pOutput->u8_cur_cadence_Id[u8_k]))//not support & need to fallback
		{
			pOutput->u8_cur_cadence_out[u8_k] = _CAD_VIDEO;
			pOutput->u8_phT_phase_Idx_out[u8_k] = 0;
		}
		
		// special case for real cinema on/off at cadence 4222
		// when 60(4222)in and 60out must keep 4222 sequence when truMotion off
		// when 60(32)in and 60out not need to do anything(default already 32 out)
		if (s_pContext->_external_data._input_frameRate == _PQL_IN_60HZ && s_pContext->_external_data._output_frameRate == _PQL_OUT_60HZ &&
			s_pContext->_external_data.u3_memcMode == 3/*MEMC_OFF*/ && pOutput->u8_cur_cadence_Id[_FILM_ALL] == _CAD_2224)
		{
			pOutput->u8_cur_cadence_out[u8_k] = _CAD_VIDEO;
			pOutput->u8_phT_phase_Idx_out[u8_k] = 0;
		}
		
	}

	//no support & need fallback
	if(CAD_F ==PQL_FRCCaseSupportJudge(pOutput->u8_cur_cadence_Id[_FILM_ALL]))
		pOutput->u8_flbk_lvl_cad_cnt = 4;
	else if(pOutput->u8_flbk_lvl_cad_cnt > 0)
		pOutput->u8_flbk_lvl_cad_cnt = pOutput->u8_flbk_lvl_cad_cnt-1;
	else
		pOutput->u8_flbk_lvl_cad_cnt = 0;
	
}


/////////////////// External functions  ////////////////////////////////////////////////////////////
VOID FilmDetect_Init(_OUTPUT_FilmDetectCtrl *pOutput)
{
	UBYTE u8_k, u8_i;

	for (u8_k = 0; u8_k < _FILM_MOT_NUM; u8_k ++)
	{
		for (u8_i = 0; u8_i < _FRC_CADENCE_NUM_; u8_i ++)
		{
			u8_filmCad_enterCnt[u8_i][u8_k] = 0;
		}

		for (u8_i = 0; u8_i < 8; u8_i ++)
		{
			pOutput->u27_ipme_motionPool[u8_k][u8_i] = 0;
		}

		pOutput->u32_Mot_sequence[u8_k]  = 0;

		pOutput->u8_det_cadence_Id[u8_k] = _CAD_VIDEO;
		pOutput->u8_cur_cadence_Id[u8_k] = _CAD_VIDEO;
		pOutput->u8_pre_cadence_Id[u8_k] = _CAD_VIDEO;
		pOutput->u8_phase_Idx[u8_k]      = 0;

		pOutput->u27_quit_bigMot[u8_k] = 0x1FF;
		pOutput->u27_quit_smlMot[u8_k] = 0;
		pOutput->u27_quit_motTh[u8_k]  = 0;
		pOutput->u8_quit_cnt[u8_k]     = 0;
		pOutput->u8_quit_prd[u8_k]     = 0;

		pOutput->u8_phT_phase_Idx[u8_k] = 0;

		pOutput->u27_FrmMotion_S[u8_k] = 0;

		pOutput->u8_cur_cadence_out[u8_k] = _CAD_VIDEO;
		pOutput->u8_phT_phase_Idx_out[u8_k] = 0;

		pOutput->u27_g_FrmMot_Th[u8_k] = 0;
		
	}

	for(u8_k = 0; u8_k < 26; u8_k ++){
		pOutput->u27_FrmMotionSort[u8_k] = 0;
		pOutput->u27_FrmMotionSortTick[u8_k] = 0;
	}

	pOutput->u5_dbg_param1_pre     = 0;
	pOutput->u32_dbg_param2_pre    = 0;
	pOutput->u32_dbg_cnt_hold      = 0;
	pOutput->u8_dbg_motion_t = _FILM_ALL;

	pOutput->u8_flbk_lvl_cad_cnt = 0;
	
	pOutput->u1_mixMode = 0;
	pOutput->u8_mixMode_cnt = 0;
}


//Input signal and parameters are connected locally
VOID FilmDetectCtrl_Proc(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE mPullDownMode;
	UBYTE u8_k = 0;

	pOutput->u8_dbg_motion_t = _CLIP_(pParam->u3_DbgPrt_Rgn, _FILM_ALL, _FILM_5RGN_CEN);


	if (pParam->u1_filmDet_bypass == 1)
	{
		pOutput->u8_det_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
		pOutput->u8_phase_Idx[_FILM_ALL]      = 0;

		pOutput->u8_cur_cadence_Id[_FILM_ALL] = (FRC_CADENCE_ID)(s_pContext->_output_read_comreg.u3_ipme_filmMode_rb>>1);
	}
	else if ((s_pContext->_external_data._input_3dFormat != _PQL_IN_LR) ||\
		((s_pContext->_external_data._input_3dFormat == _PQL_IN_LR) && (s_pContext->_output_read_comreg.u1_kphase_inLR == _PQL_3D_FRAME_L)))
	{
        pOutput->u32_dbg_cnt_hold = (pOutput->u5_dbg_param1_pre != pParam->u5_dbg_param1 || pOutput->u32_dbg_param2_pre!= pParam->u32_dbg_param2)?\
			                         pParam->u32_dbg_cnt : (pOutput->u32_dbg_cnt_hold > 0 ? (pOutput->u32_dbg_cnt_hold - 1) : 0);

		Motion_Sequence_Gen(pParam, pOutput, _FILM_ALL);
		CadenceDetect(pParam,pOutput, _FILM_ALL);
		Film_motThr_calc(pParam,pOutput, _FILM_ALL);
		Film_occasionally_fastOut(pParam,pOutput);

		if (pParam->u1_mixMode_det_en == 1)
		{
			for (u8_k = _FILM_5RGN_TOP; u8_k <= _FILM_5RGN_CEN; u8_k ++)
			{
				Motion_Sequence_Gen(pParam, pOutput, (_PQL_FILM_MOT_TYPE)u8_k);
				CadenceDetect(pParam, pOutput, (_PQL_FILM_MOT_TYPE)u8_k);
				Film_motThr_calc(pParam, pOutput, (_PQL_FILM_MOT_TYPE)u8_k);

				if (pOutput->u8_pre_cadence_Id[u8_k] == _CAD_VIDEO)
				{
					FilmEnter(pParam, pOutput, (_PQL_FILM_MOT_TYPE)u8_k);
				}
				else
				{
					FilmQuit(pParam, pOutput, (_PQL_FILM_MOT_TYPE)u8_k);
				}

				//cadence+timing support or not
				if(CAD_N == PQL_FRCCaseSupportJudge(pOutput->u8_cur_cadence_Id[u8_k]))
				{
					pOutput->u8_cur_cadence_Id[u8_k] = _CAD_VIDEO;
				}

				PhaseIdx_set(pParam, pOutput, (_PQL_FILM_MOT_TYPE)u8_k);

				pOutput->u8_pre_cadence_Id[u8_k] = pOutput->u8_cur_cadence_Id[u8_k];
			}

			MixMode_detect(pParam, pOutput);
		}
		else
		{
			pOutput->u1_mixMode     = 0;
			pOutput->u8_mixMode_cnt = 0;
		}

		if (pOutput->u8_pre_cadence_Id[_FILM_ALL] == _CAD_VIDEO && pOutput->u1_mixMode == 0)
		{
			FilmEnter(pParam, pOutput, _FILM_ALL);
		}
		else
		{
			FilmQuit(pParam, pOutput, _FILM_ALL);
		}

		//pull down mode
		//input 25hz/30hz/50hz/60hz, TruMotion off, Cinema off => clear cadence to avoid incorrect pulldown
		mPullDownMode = s_pContext->_external_data.u8_pulldown_mode;
		if(pOutput->u8_cur_cadence_Id[_FILM_ALL] != _CAD_VIDEO && s_pContext->_external_data._input_frameRate == _PQL_IN_24HZ &&
			/*mPullDownMode >= _PQL_IN24HZ_TRUMOTOFF_CINEMAON &&*/ mPullDownMode <= _PQL_IN24HZ_TRUMOTOFF_CINEMAOFF)
		{
			pOutput->u8_cur_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
		}

		// FF or FB force to video
		if((s_pContext->_external_info.s16_speed != 256) && (s_pContext->_external_info.s16_speed != -256))
		{
			pOutput->u8_cur_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
		}

		//cadence+timing support or not
		if(CAD_N == PQL_FRCCaseSupportJudge( pOutput->u8_cur_cadence_Id[_FILM_ALL] ))
		{
			pOutput->u8_cur_cadence_Id[_FILM_ALL] = _CAD_VIDEO;
		}

		PhaseIdx_set(pParam, pOutput, _FILM_ALL);

		pOutput->u8_pre_cadence_Id[_FILM_ALL] = pOutput->u8_cur_cadence_Id[_FILM_ALL];

		if(0)// ((((pOutput->u5_dbg_param1_pre & BIT_2) >> 2) == 1) && pOutput->u32_dbg_cnt_hold > 0)
	        {
	    	   printk("[MEMC]%s::cur_cadence_Id=%d, phase_ID=%d, phT_phase_ID=%d \n",__FUNCTION__,pOutput->u8_cur_cadence_Id[_FILM_ALL],pOutput->u8_phase_Idx[_FILM_ALL],pOutput->u8_phT_phase_Idx[_FILM_ALL]);
	        }

		pOutput->u5_dbg_param1_pre  = pParam->u5_dbg_param1;
		pOutput->u32_dbg_param2_pre = pParam->u32_dbg_param2;
	}


	//update output to other module
	//pOutput->u8_cur_cadence_out[u8_k]
	//pOutput->u8_phT_phase_Idx_out[u8_k]
	FilmDetect_UpdateOutput(pOutput);
	
	// Pass out the film information
	g_scaler_memc_cadence[_FILM_MEMC_ALL] = pOutput->u8_cur_cadence_Id[_FILM_ALL];
	g_scaler_memc_cadence[_FILM_MEMC_TOP] = ( pParam->u1_mixMode_det_en == 1 )? pOutput->u8_cur_cadence_Id[_FILM_5RGN_TOP] : 255;
	g_scaler_memc_cadence[_FILM_MEMC_BOT] = ( pParam->u1_mixMode_det_en == 1 )? pOutput->u8_cur_cadence_Id[_FILM_5RGN_BOT] : 255;
	g_scaler_memc_cadence[_FILM_MEMC_LFT] = ( pParam->u1_mixMode_det_en == 1 )? pOutput->u8_cur_cadence_Id[_FILM_5RGN_LFT] : 255;
	g_scaler_memc_cadence[_FILM_MEMC_RHT] = ( pParam->u1_mixMode_det_en == 1 )? pOutput->u8_cur_cadence_Id[_FILM_5RGN_RHT] : 255;
	g_scaler_memc_cadence[_FILM_MEMC_CEN] = ( pParam->u1_mixMode_det_en == 1 )? pOutput->u8_cur_cadence_Id[_FILM_5RGN_CEN] : 255;
	g_scaler_memc_cadence[_FILM_MEMC_OUT_ALL] = pOutput->u8_cur_cadence_out[_FILM_ALL];

}
