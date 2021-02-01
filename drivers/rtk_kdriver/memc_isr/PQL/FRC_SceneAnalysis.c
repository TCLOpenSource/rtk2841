#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/FRC_SceneAnalysis.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"
#include "memc_isr/PQL/Read_ComReg.h"
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

VOID FRC_SceneAnalysis_Init(_OUTPUT_FRC_SceneAnalysis *pOutput)
{
	//////////////////////////////////////////////////////////////////////////
	//Fade In/Out
	//////////////////////////////////////////////////////////////////////////
	pOutput->u4_fadeInOut_conf				= 0;
	pOutput->u4_fadeInOut_conf_iir          = 0;
	pOutput->u4_fadeInOut_cnt_alpha			= 0;
	pOutput->u4_fadeInOut_bv_sad_alpha		= 0;
	pOutput->u4_fadeInOut_acdc_sad_alpha	= 0;
	pOutput->u4_fadeInOut_apl_diff_alpha    = 0;
	pOutput->u8_ME1_searchRange_x           = 0;
	pOutput->u8_ME1_searchRange_y           = 0;
	pOutput->u2_searchRange_x_status        = 0;
	pOutput->u2_searchRange_y_status        = 0;
	pOutput->u1_fadeInOut_dh_close          = 0;
	pOutput->u4_fadeInOut_logo_conf_iir	= 0;
	pOutput->u1_fadeInOut_logo_clr		= 0;
	//pOutput->u1_fadeInOut_acdc_bld          = 0;
	//pOutput->u1_fadeInOut_acdc_bld_pre      = 0;
	pOutput->u5_dc_ac_bld_alpha             = 0;
	pOutput->u5_acdc_bld_holdtime           = 0;
	pOutput->u8_zoom_force_fb_cnt		= 0;
	pOutput->u1_still_frame	        	= 0;

	//
	pOutput->u8_HDR_PicChg_prt_apply = 0;
	pOutput->u16_OSDBrightnessVal = 0;
	pOutput->u16_OSDContrastVal = 0;
	pOutput->u8_OSDBrightnessBigChg_prt_apply = 0;
	pOutput->u8_OSDContrastBigChg_prt_apply = 0;
	pOutput->u8_VOSeek_prt_apply = 0;

	pOutput->u8_dynME_ac_pix_sad_limt_act   = 0;
	pOutput->u4_acdc_bld_psad_shift_act     = 0;

	pOutput->u32_glb_sad_pre                = 0;
	pOutput->u32_glb_sad_cur                = 0;

	pOutput->u26_Apli[0]                    = 0;
	pOutput->u26_Apli[1]                    = 0;
	pOutput->u26_Apli[2]                    = 0;
	pOutput->u26_Apli[3]                    = 0;
	pOutput->u26_Apli[4]                    = 0;
	pOutput->u32_frm_cnt                    = 0;
	pOutput->u1_Apli_same                   = 0;
	pOutput->u8_is_insidePan                = 0;
	pOutput->u8_is_insidePanX               = 0;

	pOutput->u32_insidePan_avgAbsMVX        = 0;
	pOutput->u32_insidePan_avgAbsMVY        = 0;
	pOutput->s2m_12_cnt_iir                 = 0;

	pOutput->u1_fastMotion_det = 0;
}

SINT32 MVDiff_Calc(SINT16 mvx1, SINT16 mvy1, SINT16 mvx2, SINT16 mvy2)
{
	SINT32 mvxd = _ABS_(mvx1 - mvx2) + _ABS_(mvy1 - mvy2);
	return mvxd;
}


//
VOID FRC_Scene2Motion_Hist(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	SINT32 i,j;
	UBYTE good_cnt		 = 0;
	UBYTE mv_type_cnt	 = 0;
	SINT32 mvx;
	SINT32 mvy;
	
	const SINT32 valid_num    = 6;
	const SINT32 valid_num1   = 950;
	const SINT32 bin_x_length = 32;
	const SINT32 bin_y_length = 16;

	UBYTE  mv_cnt[32*16];
	SINT16 max_mv_x = bin_x_length/2 * pParam->s2m_diffmv_thr;
	SINT16 max_mv_y = bin_y_length/2 * pParam->s2m_diffmv_thr;
	SINT16 mvx_bin,mvy_bin;
	SINT16 first_idx = 0, find_first = 0;

	UBYTE max_cnt     = 0;
	UBYTE sec_cnt     = 0;
	UBYTE max_cnt_i = 0,max_cnt_j = 0;
	UBYTE sec_cnt_i = 0,sec_cnt_j = 0;

	for (i=0;i<bin_x_length*bin_y_length;i++)
	{
		mv_cnt[i] = 0;
	}

	for (i = 0; i< 32; i++)
	{
		if((_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]) >= pParam->s2m_goodmv_thr || 
			 _ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]) >= pParam->s2m_goodmv_thr) && 
			(s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > valid_num) && 
			(s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < pParam->s2m_goodmv_unconf)&& 
			((s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i]> valid_num && 
			  s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[i] < pParam->s2m_goodmv_unconf) ||
			s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i]<= valid_num))
		{
			good_cnt++;
		}

		find_first = 0;
		if (s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > valid_num && 
			s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < pParam->s2m_goodmv_unconf)
		{
			mvx = s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i];
			mvy = s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i];
			mvx = _CLIP_(mvx, -max_mv_x, max_mv_x-1) + pParam->s2m_diffmv_thr/2;
			mvy = _CLIP_(mvy, -max_mv_y, max_mv_y-1) + pParam->s2m_diffmv_thr/2;
			mvx_bin = _CLIP_((mvx + max_mv_x)/pParam->s2m_diffmv_thr,0,bin_x_length-1);
			mvy_bin = _CLIP_((mvy + max_mv_y)/pParam->s2m_diffmv_thr,0,bin_y_length-1);

			if (mv_cnt[mvy_bin*bin_x_length + mvx_bin] == 0)
			{
				mv_type_cnt = mv_type_cnt + 1;
			}

			mv_cnt[mvy_bin*bin_x_length + mvx_bin] = mv_cnt[mvy_bin*bin_x_length + mvx_bin] + 1;
			find_first = 1;
			first_idx  = mvy_bin*bin_x_length + mvx_bin;
		}

		if (s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i] > valid_num && 
			s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[i] < pParam->s2m_goodmv_unconf)
		{
			mvx = s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i];
			mvy = s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i];
			mvx = _CLIP_(mvx, -max_mv_x, max_mv_x-1) + pParam->s2m_diffmv_thr/2;
			mvy = _CLIP_(mvy, -max_mv_y, max_mv_y-1) + pParam->s2m_diffmv_thr/2;
			mvx_bin = _CLIP_((mvx + max_mv_x)/pParam->s2m_diffmv_thr,0,bin_x_length-1);
			mvy_bin = _CLIP_((mvy + max_mv_y)/pParam->s2m_diffmv_thr,0,bin_y_length-1);
			if (mv_cnt[mvy_bin*bin_x_length + mvx_bin] == 0)
			{
				mv_type_cnt = mv_type_cnt + 1;
			}
			mv_cnt[mvy_bin*bin_x_length + mvx_bin] = mv_cnt[mvy_bin*bin_x_length + mvx_bin] + 1;
		}
		else if(s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i] <= valid_num && 
			    s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > valid_num1 && 
			    find_first == 1)
		{
			mv_cnt[first_idx] = mv_cnt[first_idx] + 1;
		}
	}

	for (j=0; j<bin_y_length; j++)
	{
		for (i=0; i<bin_x_length; i++)
		{
			if (mv_cnt[j*bin_x_length + i] > max_cnt)
			{
				max_cnt   = mv_cnt[j*bin_x_length + i];
				max_cnt_i = i;
				max_cnt_j = j;
			}
		}
	}

	for (j=0; j<bin_y_length; j++)
	{
		for (i=0; i<bin_x_length; i++)
		{
			if (mv_cnt[j*bin_x_length + i] > max_cnt && (i!=max_cnt_i && j!=max_cnt_j))
			{
				sec_cnt   = mv_cnt[j*bin_x_length + i];
				sec_cnt_i = i;
				sec_cnt_j = j;
			}
		}
	}

	pOutput->s2m_1st_cnt    = max_cnt;
	pOutput->s2m_1st_mvx    = (max_cnt_i * pParam->s2m_diffmv_thr) - pParam->s2m_diffmv_thr/2 - max_mv_x;
	pOutput->s2m_1st_mvy    = (max_cnt_j * pParam->s2m_diffmv_thr) - pParam->s2m_diffmv_thr/2 - max_mv_y;
	pOutput->s2m_2nd_cnt    = sec_cnt;
	pOutput->s2m_2nd_mvx    = (sec_cnt_i * pParam->s2m_diffmv_thr) - pParam->s2m_diffmv_thr/2 - max_mv_x;
	pOutput->s2m_2nd_mvy    = (sec_cnt_j * pParam->s2m_diffmv_thr) - pParam->s2m_diffmv_thr/2 - max_mv_y;
	pOutput->s2m_12_cnt_iir = _2Val_RndBlending_(pOutput->s2m_12_cnt_iir,(max_cnt + sec_cnt),pParam->s2m_cnt_iir_alpha,4);
	pOutput->u8_goodGmv_cnt = good_cnt;
	pOutput->u8_diffGmv_cnt = mv_type_cnt;
}



VOID FRC_Scene2Motion(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	SINT32 i,j;
	UBYTE good_cnt		 = 0;
	UBYTE mv_type_cnt	 = 0;
	SINT32 mvdiff		 = 0;
	SINT32 min_classdif	 = 1000000;
	SINT32 min_class_idx = 0;

	SINT32 find_class  = 0;
	SINT16 mvx[65];
	SINT16 mvy[65];
	UBYTE mv_cnt[65];

	UBYTE max_cnt     = 0;
	UBYTE sec_cnt     = 0;
	UBYTE max_cnt_idx = 0;
	UBYTE sec_cnt_idx = 0;

	const SINT32 valid_num   = 6;

	for (i=0;i<65;i++)
	{
		mv_cnt[i] = 0;
	}

	for (i = 0; i< 32; i++)
	{
		if((_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]) >= pParam->s2m_goodmv_thr || _ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]) >= pParam->s2m_goodmv_thr) 
			&& s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > valid_num && s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < pParam->s2m_goodmv_unconf
			&& ((s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i]> valid_num && s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[i] < pParam->s2m_goodmv_unconf) ||
				s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i]<= valid_num))
			
		{
			good_cnt++;
		}

		if (i == 0)
		{
			if (s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > valid_num)
			{
				mvx[mv_type_cnt] = s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i];
				mvy[mv_type_cnt] = s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i];
				mv_cnt[mv_type_cnt]++;
				mv_type_cnt++;			
			}

			if (mv_type_cnt > 0)
			{
				mvdiff = MVDiff_Calc(mvx[0],mvy[0],s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[i],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[i]);
				if (s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i] > valid_num && mvdiff > pParam->s2m_diffmv_thr)
				{
					mvx[mv_type_cnt] = s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[i];
					mvy[mv_type_cnt] = s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[i];
					mv_cnt[mv_type_cnt]++;
					mv_type_cnt++;
				}
				else if (s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i] > valid_num)
				{
					mvx[0] = (mvx[0] + s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[i])/2 ;
					mvy[0] = (mvy[0] + s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[i])/2;
					mv_cnt[0]++;
				}
			}
			else if (s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i] > valid_num)
			{
				mvx[mv_type_cnt] = s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[i];
				mvy[mv_type_cnt] = s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[i];
				mv_cnt[mv_type_cnt]++;
				mv_type_cnt++;
			}
		}

		if (i > 0)
		{
			mv_type_cnt = _CLIP_UBOUND_(mv_type_cnt, 64);
			if (s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > valid_num)
			{
				find_class    = 0;
				min_classdif  = 1000000000;
				min_class_idx = 0;
				for (j=0; j< mv_type_cnt; j++)
				{
					mvdiff = MVDiff_Calc(mvx[j],mvy[j],s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i],s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]);
					if (mvdiff <= pParam->s2m_diffmv_thr)
					{
						find_class    = 1;
						if (mvdiff < min_classdif)
						{
							min_classdif  = mvdiff;
							min_class_idx = j;
						}
					}
				}

				if (find_class == 1)
				{
					mvx[min_class_idx]    = (mvx[min_class_idx] + s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i])/2;
					mvy[min_class_idx]    = (mvy[min_class_idx] + s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i])/2;
					mv_cnt[min_class_idx]++;
				}
				else
				{
					mvx[mv_type_cnt] = s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i];
					mvy[mv_type_cnt] = s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i];
					mv_cnt[mv_type_cnt] = 1;
					mv_type_cnt++;
				}
			}

			mv_type_cnt = _CLIP_(mv_type_cnt,0, 64);
			if (s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i] > valid_num)
			{
				find_class    = 0;
				min_classdif  = 1000000000;
				min_class_idx = 0;
				for (j=0; j< mv_type_cnt; j++)
				{
					mvdiff = MVDiff_Calc(mvx[j],mvy[j],s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[i],s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[i]);
					if (mvdiff <= pParam->s2m_diffmv_thr)
					{
						find_class    = 1;
						if (mvdiff < min_classdif)
						{
							min_classdif  = mvdiff;
							min_class_idx = j;
						}
					}
				}

				if (find_class == 1)
				{
					mvx[min_class_idx]    = (mvx[min_class_idx] + s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[i])/2;
					mvy[min_class_idx]    = (mvy[min_class_idx] + s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[i])/2;
					mv_cnt[min_class_idx]++;
				}
				else
				{
					mvx[mv_type_cnt] = s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[i];
					mvy[mv_type_cnt] = s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[i];
					mv_cnt[mv_type_cnt] = 1;
					mv_type_cnt++;
				}
			}
		}
	}

	
	//find max
	mv_type_cnt = _CLIP_(mv_type_cnt,0, 64);
	for (i=0; i<mv_type_cnt; i++)
	{
		if (mv_cnt[i] > max_cnt)
		{
			max_cnt = mv_cnt[i];
			max_cnt_idx = i;	
		}
	}

	for (i=0; i<mv_type_cnt; i++)
	{
		if (mv_cnt[i] > sec_cnt && i != max_cnt_idx)
		{
			sec_cnt = mv_cnt[i];
			sec_cnt_idx = i;	
		}
	}


	pOutput->s2m_1st_cnt    = max_cnt;
	pOutput->s2m_1st_mvx    = mvx[max_cnt_idx];
	pOutput->s2m_1st_mvy    = mvy[max_cnt_idx];
	pOutput->s2m_2nd_cnt    = sec_cnt;
	pOutput->s2m_2nd_mvx    = mvx[sec_cnt_idx];
	pOutput->s2m_2nd_mvy    = mvy[sec_cnt_idx];
	pOutput->s2m_12_cnt_iir = _2Val_RndBlending_(pOutput->s2m_12_cnt_iir,(max_cnt + sec_cnt),pParam->s2m_cnt_iir_alpha,4);
	pOutput->u8_goodGmv_cnt = good_cnt;
	pOutput->u8_diffGmv_cnt = mv_type_cnt;
}


VOID FRC_FadeInOut_Detect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	if (pParam->u1_fadeInOut_en == 1)
	{
		UINT32 cnt_alpha_use, cnt_total_use, apl_diff, i; 
		//UBYTE p_cnt = 0; 
		//UBYTE n_cnt = 0; 
		//condier whole block cnt is accurate.
		UINT16 u16_cnt_totalNum = (s_pContext->_output_read_comreg.u8_me1_Vbuf_Hsize_rb * s_pContext->_output_read_comreg.u8_me1_Vbuf_Vsize_rb);

		//scene change/menu is both small, cnt/sad-sum
		UINT32 acGreateDc_cnt  = s_pContext->_output_read_comreg.u20_me_ZMV_AcGreatDc_cnt_rb;
		UINT32 dcGreateAc_cnt  = s_pContext->_output_read_comreg.u20_me_ZMV_DcGreatAc_cnt_rb;

		//UINT32	apl_diff       = u16_cnt_totalNum > 0 ? _ABS_(((SINT32)s_pContext->_output_read_comreg.u26_me_aAPLi_rb - (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLp_rb))/u16_cnt_totalNum : 
		//						 _ABS_(((SINT32)s_pContext->_output_read_comreg.u26_me_aAPLi_rb - (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLp_rb));

		//n.5 prec. max=64x32=2048
		UINT32 acdc_cnt_ratio      = acGreateDc_cnt == 0 ? dcGreateAc_cnt*32 : (dcGreateAc_cnt * 32 / acGreateDc_cnt);
		UINT32 cnt_alpha_diff_prm  = pParam->u8_fdIO_acdc_cnt_alpha_hig - pParam->u8_fdIO_acdc_cnt_alpha_low;
		UINT32 acdc_cnt_slope      = cnt_alpha_diff_prm <= 0 ? 0 : 16 * 256 / cnt_alpha_diff_prm;


		UINT32 acdc_cnt_total      = acGreateDc_cnt + dcGreateAc_cnt;
		UINT32 cnt_thr_diff_prm    = pParam->u20_fdIO_acdc_cnt_hig - pParam->u20_fdIO_acdc_cnt_low;
		UINT32 acdc_thr_slope      = cnt_thr_diff_prm <= 0 ? 0 : 16 * 256 / cnt_thr_diff_prm;

		UBYTE  u3_apl_diff_cnt     = _CLIP_((5 - pParam->u3_fdIO_apl_diff_frm_cnt),0,4);
		
		UBYTE u4_fadeInOut_logo_conf = 0;
		//UBYTE rgn_cnt = 0;
		//UINT32 rapl_diff[32] = {0};
		//UINT32 rapl_diff_avg = 0;
		//UINT16 u16_cnt_rgnNum = 30*33;
		
		acdc_cnt_ratio = (acdc_cnt_ratio>>12);
		acdc_cnt_total = (acdc_cnt_total>>6);
		
		for(i=0; i<4; i++)
		{
			pOutput->u26_Apli[i] = pOutput->u26_Apli[i+1];
		}
		pOutput->u26_Apli[4] = (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLi_rb;

		pOutput->u1_Apli_same = (pOutput->u26_Apli[u3_apl_diff_cnt] == (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLi_rb)? 1:0;

		if(pOutput->u32_frm_cnt > 5)
		{
			apl_diff       = u16_cnt_totalNum > 0 ? _ABS_(((SINT32)pOutput->u26_Apli[u3_apl_diff_cnt] - (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLp_rb))/u16_cnt_totalNum : 
							_ABS_(((SINT32)pOutput->u26_Apli[u3_apl_diff_cnt] - (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLp_rb));
		}
		else
		{
			apl_diff       = u16_cnt_totalNum > 0 ? _ABS_(((SINT32)s_pContext->_output_read_comreg.u26_me_aAPLi_rb - (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLp_rb))/u16_cnt_totalNum : 
							_ABS_(((SINT32)s_pContext->_output_read_comreg.u26_me_aAPLi_rb - (SINT32)s_pContext->_output_read_comreg.u26_me_aAPLp_rb));
		}

		//for(i=0; i<32; i++)
		//{
		//	rapl_diff[i] = _ABS_((SINT32)s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i]- (SINT32)s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i])/u16_cnt_rgnNum;
		//	rapl_diff_avg += rapl_diff[i];
		//}
		//rapl_diff_avg = (rapl_diff_avg>>5);

		//for(i=0; i<32; i++)
		//{
		//	if(rapl_diff_avg>3 && _ABS_((SINT32)rapl_diff_avg-(SINT32)rapl_diff[i])<3)
		//		rgn_cnt++;
		//}
		
		pOutput->u4_fadeInOut_cnt_alpha      = _IncreaseCurveMapping(acdc_cnt_ratio, pParam->u8_fdIO_acdc_cnt_alpha_low, 0, 16, acdc_cnt_slope, 8);
		pOutput->u4_fadeInOut_cnt_Thr_alpha  = _IncreaseCurveMapping(acdc_cnt_total, pParam->u20_fdIO_acdc_cnt_low, 0, 16, acdc_thr_slope, 8);
		pOutput->u4_fadeInOut_apl_diff_alpha = (apl_diff < pParam->u10_fdIO_apl_diff_thr_low) ? 0 : (apl_diff > pParam->u10_fdIO_apl_diff_thr_hig ? 16 : 8);

		cnt_alpha_use      = pParam->u1_fdIO_acdc_cnt_en   == 1  ? pOutput->u4_fadeInOut_cnt_alpha      : 16;
		cnt_total_use   = pParam->u1_fdIO_acdc_ratio_en == 1  ? pOutput->u4_fadeInOut_cnt_Thr_alpha  : 16;
	

		pOutput->u4_fadeInOut_conf = cnt_alpha_use * cnt_total_use / 16;
		pOutput->u4_fadeInOut_conf = (apl_diff < pParam->u10_fdIO_apl_diff_thr_low) ?  0 : pOutput->u4_fadeInOut_conf;
		pOutput->u4_fadeInOut_conf = (apl_diff > pParam->u10_fdIO_apl_diff_thr_hig) ? 16 : pOutput->u4_fadeInOut_conf;

		u4_fadeInOut_logo_conf =  cnt_total_use;
		u4_fadeInOut_logo_conf = (apl_diff < pParam->u10_fdIO_apl_diff_thr_low) ?  0 : u4_fadeInOut_logo_conf;
		u4_fadeInOut_logo_conf = (apl_diff > pParam->u10_fdIO_apl_diff_thr_hig) ? 16 : u4_fadeInOut_logo_conf;
		pOutput->u4_fadeInOut_logo_conf_iir = pParam->u1_fdIO_conf_iir_en == 0 ? u4_fadeInOut_logo_conf :
			(pOutput->u4_fadeInOut_logo_conf_iir * pParam->u4_fdIO_conf_iir_alpha + u4_fadeInOut_logo_conf * (16 - pParam->u4_fdIO_conf_iir_alpha) + (1<<3))/16;
		pOutput->u1_fadeInOut_logo_clr = (pOutput->u4_fadeInOut_logo_conf_iir >= (pParam->u4_fadeInOut_dh_close_thr)) ? 1 : 0;

		pOutput->u4_fadeInOut_conf_iir = pParam->u1_fdIO_conf_iir_en == 0 ? pOutput->u4_fadeInOut_conf :
			(pOutput->u4_fadeInOut_conf_iir * pParam->u4_fdIO_conf_iir_alpha + pOutput->u4_fadeInOut_conf * (16 - pParam->u4_fdIO_conf_iir_alpha) + (1<<3))/16;

		pOutput->u1_fadeInOut_dh_close = (pOutput->u4_fadeInOut_conf_iir >= pParam->u4_fadeInOut_dh_close_thr) ? 1 : 0;
		
		//except sc	
		if(pParam->u1_fdIO_sc_clear_en == 1)
		{
			pOutput->u1_fadeInOut_dh_close = (s_pContext->_output_read_comreg.u1_sc_status_dh_rb==1) ? 0 : pOutput->u1_fadeInOut_dh_close;
		}

		pOutput->u32_frm_cnt = pOutput->u32_frm_cnt + 1;
		pOutput->u32_frm_cnt = _CLIP_(pOutput->u32_frm_cnt,0,14);


#if 0
	UINT32 ip31=0,ip30=0;
	ReadRegister(FRC_TOP__kmc_top__dummy24_ADDR,31,31,&ip31);
	ReadRegister(FRC_TOP__kmc_top__dummy24_ADDR,30,30,&ip30);
	
	if(ip31)
		printk("[fdio] %x %x %x\t2) %x %x %x\t3) %x %x %x\t4) %x %x\t5) %x %x %x\n", 
			pOutput->u1_fadeInOut_dh_close, pOutput->u1_fadeInOut_logo_clr, pOutput->u4_fadeInOut_logo_conf_iir,
			pOutput->u4_fadeInOut_cnt_alpha,pOutput->u4_fadeInOut_cnt_Thr_alpha, pOutput->u4_fadeInOut_apl_diff_alpha,			
			cnt_alpha_use*cnt_total_use/16, pOutput->u4_fadeInOut_conf, pOutput->u4_fadeInOut_conf_iir, 
			acGreateDc_cnt,dcGreateAc_cnt,
			acdc_cnt_ratio, acdc_cnt_total, apl_diff);
	if(ip30)
		printk("[fdio] %x %x\t %d %x \t%x %x %x %x %x %x %x %x...%x %x %x %x %x %x %x %x...%x %x %x %x %x %x %x %x...%x %x %x %x %x %x %x %x\n", 
			pOutput->u1_fadeInOut_dh_close, pOutput->u1_fadeInOut_logo_clr, 
			rgn_cnt, rapl_diff_avg,
			rapl_diff[0],rapl_diff[1],rapl_diff[2],rapl_diff[3],rapl_diff[4],rapl_diff[5],rapl_diff[6],rapl_diff[7],
			rapl_diff[8],rapl_diff[9],rapl_diff[10],rapl_diff[11],rapl_diff[12],rapl_diff[13],rapl_diff[14],rapl_diff[15],
			rapl_diff[16],rapl_diff[17],rapl_diff[18],rapl_diff[19],rapl_diff[20],rapl_diff[21],rapl_diff[22],rapl_diff[23],
			rapl_diff[24],rapl_diff[25],rapl_diff[26],rapl_diff[27],rapl_diff[28],rapl_diff[29],rapl_diff[30],rapl_diff[31]);
#endif		
	}
	else
	{
		pOutput->u4_fadeInOut_conf     = 0;
		pOutput->u4_fadeInOut_conf_iir = 0;
		pOutput->u4_fadeInOut_logo_conf_iir = 0;
		pOutput->u1_fadeInOut_logo_clr = 0;
	}
}

//Inside Win Panning Detection(inside good rmv > thr, and no tc, no sc)
//need close dh.
//stream: vertical_monster 
//Lin Zha
VOID FRC_InsidePanning_Detect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//UINT16 u16_cnt_totalNum = (s_pContext->_output_read_comreg.u8_me1_Vbuf_Hsize_rb * s_pContext->_output_read_comreg.u8_me1_Vbuf_Vsize_rb);
	SINT32 i;
		
	UBYTE u8_largeMVY = 0;
	UBYTE u8_largeMVX = 0;

	//16=1
	UINT16 tc_rgn_weight[32] = {0,  0,   0,   0,   0,   0,    0,  0, 
		                              0,  8,  16,  16,  16,   16,   8,  0, 
									  0,  8,  16,  16,  16,   16,   8,  0,  
									  0,  0,   0,   0,   0,   0,    0,  0,  
		                              };

	UINT16 sc_rgn_weight[32] = {0,  0,   0,   0,   0,   0,    0,  0, 
									  0,  8,  16,  16,  16,   16,   8,  0, 
									  0,  8,  16,  16,  16,   16,   8,  0,  
									  0,  0,   0,   0,   0,   0,    0,  0,  
								      };

	UINT16 mv_rgn_weight[32] = {0,  0,   0,   0,   0,   0,    0,  0, 
								      0,  8,  16,  16,  16,   16,   8,  0, 
									  0,  8,  16,  16,  16,   16,   8,  0,  
									  0,  0,   0,   0,   0,   0,    0,  0,  
									  };

	 UINT16 unconf_rgn_weight_center[32] = {0,  0,   0,   0,   0,   0,    0,  0, 
									      0,  8,  16,  16,  16,   16,   8,  0, 
									      0,  8,  16,  16,  16,   16,   8,  0,  
										  0,  0,   0,   0,   0,   0,    0,  0,  
	                                       };

	 UINT16 unconf_rgn_weight_all[32] = {16,  16,  16,  16,  16,   16,  16, 16, 
									      16,  16,  16,  16,  16,   16,  16, 16, 
									      16,  16,  16,  16,  16,   16,  16, 16,  
									      16,  16,  16,  16,  16,   16,  16, 16, };

	UINT32 tc_avg = 0;
	UINT32 sc_avg = 0;	
	SINT32 mvx_avg		= 0;
	SINT32 mvy_avg		= 0;
	SINT32 mv_w_sum		= 0;
	UINT32 unconf_avg   = 0;
	UINT32 unconf_w_sum = 0;
	UINT16 *unconf_w_use;

	for(i=0;i<32;i++) //32 region
	{
		//large mvy, small mvx
		if (  (_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]) < pParam->u10_PanRMV_SmallMV) && 
			  (_ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]) > pParam->u10_PanRMV_LargeMV) &&
			  (s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > pParam->u12_PanRMV_Cnt)           &&
			  (s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < pParam->u12_PanRMV_Unconf) 
		    )
		{
			u8_largeMVY++;
		}

		if (  (_ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]) < pParam->u10_PanRMV_SmallMV) && 
			(_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]) > pParam->u10_PanRMV_LargeMV) &&
			(s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > pParam->u12_PanRMV_Cnt)           &&
			(s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i] < pParam->u12_PanRMV_Unconf) 
			)
		{
			u8_largeMVX++;
		}

		unconf_w_use = (pParam->inUnconf_sel == 0) ? unconf_rgn_weight_all : unconf_rgn_weight_center;
		if ( s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i] > 5)
		{
			unconf_w_sum += unconf_w_use[i];
			unconf_avg    = unconf_avg + unconf_w_use[i]*(s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i]);
		}

		if ( s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[i] > 5)
		{
			unconf_w_sum += unconf_w_use[i];
			unconf_avg    = unconf_avg + unconf_w_use[i]*(s_pContext->_output_read_comreg.u12_me_rMV_2nd_unconf_rb[i]);
	}

		unconf_avg = (unconf_w_sum == 0) ? 15 : unconf_avg/unconf_w_sum;
	}

	pOutput->u32_unconf_avg         = unconf_avg;
	pOutput->u8_insidePan_LargeXnum = u8_largeMVX;
	pOutput->u8_insidePan_LargeYnum = u8_largeMVY;

	for(i=0;i<32;i++) //32 region
	{
		tc_avg += s_pContext->_output_read_comreg.u22_me_rTC_rb[i] * tc_rgn_weight[i];
		sc_avg += s_pContext->_output_read_comreg.u22_me_rSC_rb[i] * sc_rgn_weight[i];
		mvx_avg   += s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i] * mv_rgn_weight[i];
		mvy_avg   += s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i] * mv_rgn_weight[i];
		mv_w_sum  += mv_rgn_weight[i];
	}
	
	pOutput->u32_insidePan_avgAbsMVX = _ABS_(mvx_avg)/mv_w_sum;
	pOutput->u32_insidePan_avgAbsMVY = _ABS_(mvy_avg)/mv_w_sum;
	pOutput->u32_insidePan_avgSc = sc_avg/16/32;  //each region.
	pOutput->u32_insidePan_avgTc = tc_avg/16/32;  //each region.

	//current only Y
	if (pOutput->u32_insidePan_avgSc < pParam->u32_avgRngSC_Thr && pOutput->u32_insidePan_avgTc < pParam->u32_avgRngTC_Thr &&
		(pOutput->u8_insidePan_LargeXnum > pParam->u15_PanRMV_FitNumThr || pOutput->u8_insidePan_LargeYnum > pParam->u15_PanRMV_FitNumThr))
	{
		pOutput->u8_is_insidePan = 1;
		if (pOutput->u8_insidePan_LargeXnum > pParam->u15_PanRMV_FitNumThr)
		{
			pOutput->u8_is_insidePanX = 1;
		}
	}
	else
	{
		pOutput->u8_is_insidePan = 0;
		pOutput->u8_is_insidePanX  = 0;
	}


	//temp, just try, need write in write_comReg.c
	//if (pOutput->u8_is_insidePan == 1)
	//{
	//	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_TOP_REG__reg_me2_ph_invalid_sel), 1);  //gmv
	//}
	//else
	//{
	//	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_TOP_REG__reg_me2_ph_invalid_sel), 3);  //pfv1
	//}
}

//Lin: boundary sad is not bad, boundary mv is small, first test left/right boundary
VOID FRC_BdySmallMV_Detect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	SINT32 i, lft_i, rht_i;

	SINT32 lft_idx_lut[4] = {0, 8, 16, 24};
	SINT32 rht_idx_lut[4] = {7, 15, 23, 31};
	
	SINT32 lft_smallMV_cnt = 0;
	SINT32 rht_smallMV_cnt = 0;
	for (i = 0; i < 4; i++)
	{
		lft_i = lft_idx_lut[i];
		rht_i = rht_idx_lut[i];

		if(_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[lft_i]) < pParam->u8_BdySmall_mvx_thr && 
		   _ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[lft_i]) < pParam->u8_BdySmall_mvy_thr &&
		   s_pContext->_output_read_comreg.u25_me_rSAD_rb[lft_i] < pParam->u15_BdySmall_sad_thr)
		{
			lft_smallMV_cnt++;
		}

		if(_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[rht_i]) < pParam->u8_BdySmall_mvx_thr && 
			_ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[rht_i]) < pParam->u8_BdySmall_mvy_thr &&
			s_pContext->_output_read_comreg.u25_me_rSAD_rb[rht_i] < pParam->u15_BdySmall_sad_thr)
		{
			rht_smallMV_cnt++;
		}
	}

	pOutput->u8_BdySmall_lft_cnt = lft_smallMV_cnt;
	pOutput->u8_BdySmall_rht_cnt = rht_smallMV_cnt;

	if (lft_smallMV_cnt >= pParam->u4_BdySmall_cnt_thr || rht_smallMV_cnt >= pParam->u4_BdySmall_cnt_thr)
	{
		pOutput->u1_is_BdySmall_MV = 1;
	}
	else
	{
		pOutput->u1_is_BdySmall_MV = 0;
	}
}


VOID FRC_Dynamic_ACDCBld(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//fadeIn/Out for acdc.
	if ((pParam->u1_fadeInOut_en == 1))
	{
		UBYTE u5_ac_dc_bld_apl_sig;
		SINT32 i;
		UINT32 acdc_bld_alpha_slope;
		if(pOutput->u4_fadeInOut_conf_iir >= pParam->u4_dynME_acdc_bld_alpha_x2)
		{
			u5_ac_dc_bld_apl_sig = 16;
		}
		else
		{
            acdc_bld_alpha_slope = (pParam->u4_dynME_acdc_bld_alpha_x2-pParam->u4_dynME_acdc_bld_alpha_x1)==0? 0 : 256 * 16/(pParam->u4_dynME_acdc_bld_alpha_x2-pParam->u4_dynME_acdc_bld_alpha_x1);			
		 	u5_ac_dc_bld_apl_sig = _IncreaseCurveMapping2(pOutput->u4_fadeInOut_conf_iir, pParam->u4_dynME_acdc_bld_alpha_x1, 16, acdc_bld_alpha_slope, 8);//_IncreaseCurveMapping(pOutput->u4_fadeInOut_conf_iir, pParam->u4_dynME_acdc_bld_alpha_x1, 0, 16, acdc_bld_alpha_slope, 8)
		}

		u5_ac_dc_bld_apl_sig = _CLIP_UBOUND_(u5_ac_dc_bld_apl_sig,16);

		u5_ac_dc_bld_apl_sig = ((pParam->u1_acdc_bld_sc_clear_en == 1)&&(s_pContext->_output_read_comreg.u1_sc_status_rb == 1)) ? 0 : u5_ac_dc_bld_apl_sig;

		if(u5_ac_dc_bld_apl_sig == 16)
		{
			pOutput->u5_dc_ac_bld_alpha = 16;
			pOutput->u5_acdc_bld_holdtime = pParam->u6_dynME_ac_dc_bld_apl_holdfrm;
		}
		else if(pOutput->u5_acdc_bld_holdtime>0)
		{
			pOutput->u5_dc_ac_bld_alpha = 16;
			pOutput->u5_acdc_bld_holdtime = pOutput->u5_acdc_bld_holdtime - 1;
		}
		else
		{
			pOutput->u5_dc_ac_bld_alpha = u5_ac_dc_bld_apl_sig;
			pOutput->u5_acdc_bld_holdtime = 0;
		}
	 
		for (i=0; i<3; i++)
		{
			pOutput->u8_dynME_acdc_bld_x_act[i] = _2Val_RndBlending_(pParam->u8_dynME_acdc_bld_x_fdIO[i],
				pParam->u8_dynME_acdc_bld_x_com[i],pOutput->u5_dc_ac_bld_alpha, 4);
			pOutput->u6_dynME_acdc_bld_y_act[i] = _2Val_RndBlending_(pParam->u6_dynME_acdc_bld_y_fdIO[i],
				pParam->u6_dynME_acdc_bld_y_com[i],pOutput->u5_dc_ac_bld_alpha, 4);
		}

		for (i=0; i<2; i++)
		{
			pOutput->s9_dynME_acdc_bld_s_act[i] = ((SINT32)pOutput->u8_dynME_acdc_bld_x_act[i+1]-(SINT32)pOutput->u8_dynME_acdc_bld_x_act[i]) == 0 ? 255 :
				((SINT32)pOutput->u6_dynME_acdc_bld_y_act[i+1]-(SINT32)pOutput->u6_dynME_acdc_bld_y_act[i])*16 / ((SINT32)pOutput->u8_dynME_acdc_bld_x_act[i+1]-(SINT32)pOutput->u8_dynME_acdc_bld_x_act[i]);

			pOutput->s9_dynME_acdc_bld_s_act[i] = _CLIP_(pOutput->s9_dynME_acdc_bld_s_act[i], -256, 255);
			pOutput->s9_dynME_acdc_bld_s_act[i] = pOutput->s9_dynME_acdc_bld_s_act[i] < 0 ? pOutput->s9_dynME_acdc_bld_s_act[i] + 512 :
												  pOutput->s9_dynME_acdc_bld_s_act[i];
		}

		pOutput->u8_dynME_ac_pix_sad_limt_act = _2Val_RndBlending_(pParam->u8_dynME_ac_pix_sad_limt_fdIO, 
				pParam->u8_dynME_ac_pix_sad_limt_com,pOutput->u5_dc_ac_bld_alpha, 4);

		pOutput->u4_acdc_bld_psad_shift_act = _2Val_RndBlending_(pParam->u4_acdc_bld_psad_shift_fdIO, 
				pParam->u8_dynME_ac_pix_sad_limt_com,pOutput->u5_dc_ac_bld_alpha, 4);

	}
	else
	{
		SINT32 i;
		for (i=0; i<3; i++)
		{
			pOutput->u8_dynME_acdc_bld_x_act[i] = pParam->u8_dynME_acdc_bld_x_com[i];
			pOutput->u6_dynME_acdc_bld_y_act[i] = pParam->u6_dynME_acdc_bld_y_com[i];
		}	

		for (i=0; i<2; i++)
		{
			pOutput->s9_dynME_acdc_bld_s_act[i] = ((SINT32)pOutput->u8_dynME_acdc_bld_x_act[i+1]-(SINT32)pOutput->u8_dynME_acdc_bld_x_act[i]) == 0 ? 255 :
				((SINT32)pOutput->u6_dynME_acdc_bld_y_act[i+1]-(SINT32)pOutput->u6_dynME_acdc_bld_y_act[i])*16 / ((SINT32)pOutput->u8_dynME_acdc_bld_x_act[i+1]-(SINT32)pOutput->u8_dynME_acdc_bld_x_act[i]);

			pOutput->s9_dynME_acdc_bld_s_act[i] = _CLIP_(pOutput->s9_dynME_acdc_bld_s_act[i], -256, 255);
			pOutput->s9_dynME_acdc_bld_s_act[i] = pOutput->s9_dynME_acdc_bld_s_act[i] < 0 ? pOutput->s9_dynME_acdc_bld_s_act[i] + 512 :
												  pOutput->s9_dynME_acdc_bld_s_act[i];
		}	
		pOutput->u8_dynME_ac_pix_sad_limt_act = pParam->u8_dynME_ac_pix_sad_limt_com;
		pOutput->u4_acdc_bld_psad_shift_act = pParam->u4_acdc_bld_psad_shift_com;
	}
}

VOID FRC_Dynamic_SearchRange(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();
	
	if (pParam->u1_dynSR_en == 1)
	{
		//for mvx
		int i;
		UINT32 large_mv_num_x   = 0;
		UINT32 middle_mv_num_x  = 0;
		UINT32 small_mv_num_x   = 0;
		UINT32 middle_mvx_avg   = 0;

		UINT32 large_mv_num_y   = 0;
		UINT32 middle_mv_num_y  = 0;
		UINT32 small_mv_num_y   = 0;
		UINT32 middle_mvy_avg   = 0;
		UBYTE  dynSR_mvy_range0 = 0;

		for (i=0; i<32; i++)  //32 region
		{
			UINT32 mvx       = _ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]);
			UINT32 mv_cnt    = s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i];
			UINT32 mv_unconf = s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i];

			if (mvx >= pParam->u11_dynSR_rmv_x_thr1 && mv_cnt >= pParam->u12_dynSR_rmv_cnt_thr1 && mv_unconf <= pParam->u12_dynSR_rmv_unconf_thr1)
			{
				large_mv_num_x++;
			}
			else if (mvx >= pParam->u11_dynSR_rmv_x_thr0 && mvx < pParam->u11_dynSR_rmv_x_thr1 && mv_cnt >= pParam->u12_dynSR_rmv_cnt_thr0 && mv_unconf <= pParam->u12_dynSR_rmv_unconf_thr0)
			{
				middle_mvx_avg += mvx;
				middle_mv_num_x++;
			}
			else
			{
				small_mv_num_x++;
			}
		}

		if (large_mv_num_x > pParam->u6_dynSR_rmv_x_num_thr1)
		{
			pOutput->u8_ME1_searchRange_x = pParam->u9_dynSR_mvx_range1;
			pOutput->u2_searchRange_x_status = 3;
		}
		else if (middle_mv_num_x > pParam->u6_dynSR_rmv_x_num_thr0)
		{
			int delta_mv_sr; 
			middle_mvx_avg = middle_mv_num_x > 0 ?  middle_mvx_avg/middle_mv_num_x : 0;
			delta_mv_sr    = (middle_mvx_avg - pParam->u11_dynSR_rmv_x_thr0) * (pParam->u9_dynSR_mvx_range1 - pParam->u9_dynSR_mvx_range0) / (pParam->u11_dynSR_rmv_x_thr1 - pParam->u11_dynSR_rmv_x_thr0);
			pOutput->u8_ME1_searchRange_x = pParam->u9_dynSR_mvx_range0 + delta_mv_sr;
			pOutput->u2_searchRange_x_status = 2;
}
		else
		{
			pOutput->u8_ME1_searchRange_x = pParam->u9_dynSR_mvx_range0;
			pOutput->u2_searchRange_x_status = 1;
		}

		pOutput->u8_ME1_searchRange_x = pOutput->u8_ME1_searchRange_x >> 2; // for pix perc.

		//for mvy
		for (i=0; i<32; i++)  //32 region
		{
			UINT32 mvy       = _ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]);
			UINT32 mv_cnt    = s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[i];
			UINT32 mv_unconf = s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[i];

			if (mvy >= pParam->u10_dynSR_rmv_y_thr1 && mv_cnt >= pParam->u12_dynSR_rmv_cnt_thr1 && mv_unconf <= pParam->u12_dynSR_rmv_unconf_thr1)
			{
				large_mv_num_y++;
			}
			else if (mvy >= pParam->u10_dynSR_rmv_y_thr0 && mvy < pParam->u10_dynSR_rmv_y_thr1 && mv_cnt >= pParam->u12_dynSR_rmv_cnt_thr0 && mv_unconf <= pParam->u12_dynSR_rmv_unconf_thr0)
			{
				middle_mvy_avg += mvy;
				middle_mv_num_y++;
			}
			else
			{
				small_mv_num_y++;
			}
		}

		if((s_pContext->_output_Patch_Manage.u1_BluceMic_Detected == 1) && (s_pParam->_param_Patch_Manage.u1_BluceMic_En == 1))
		{
			dynSR_mvy_range0 = 0xA0;
		}
		else
		{
			dynSR_mvy_range0 = pParam->u8_dynSR_mvy_range0;
		}
		
		if (large_mv_num_y > pParam->u6_dynSR_rmv_y_num_thr1)
		{
			pOutput->u8_ME1_searchRange_y = pParam->u8_dynSR_mvy_range1;
			pOutput->u2_searchRange_y_status = 3;
		}
		else if (middle_mv_num_y > pParam->u6_dynSR_rmv_y_num_thr0)
		{
			int delta_mv_sr; 
			middle_mvy_avg = middle_mv_num_y > 0 ?  middle_mvy_avg/middle_mv_num_y : 0;
			delta_mv_sr    = (middle_mvy_avg - pParam->u10_dynSR_rmv_y_thr0) * (pParam->u8_dynSR_mvy_range1 - dynSR_mvy_range0) / (pParam->u10_dynSR_rmv_y_thr1 - pParam->u10_dynSR_rmv_y_thr0);
			pOutput->u8_ME1_searchRange_y = dynSR_mvy_range0 + delta_mv_sr;
			pOutput->u2_searchRange_y_status = 2;
		}
		else
		{
			pOutput->u8_ME1_searchRange_y = dynSR_mvy_range0;
			pOutput->u2_searchRange_y_status = 1;
		}

		pOutput->u8_ME1_searchRange_y = pOutput->u8_ME1_searchRange_y >> 2; // for pix perc.
	}
}

VOID FRC_Dynamic_SAD_Diff(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 u27_tc_rb     = s_pContext->_output_read_comreg.u27_me_aTC_rb;
	UINT32 sad_diff;
	UINT32 tc_slp, sad_slp;
	
	//all rightshift 4bit 
	tc_slp     = (pParam->u8_dyn_SAD_Diff_TC_gain_max - pParam->u8_dyn_SAD_Diff_TC_gain_min) *  65536 / ((pParam->u27_dyn_SAD_Diff_TC_th_h>>4) - (pParam->u27_dyn_SAD_Diff_TC_th_l>>4));
	pOutput->u8_tc_gain = _IncreaseCurveMapping((u27_tc_rb>>4), (pParam->u27_dyn_SAD_Diff_TC_th_l>>4), pParam->u8_dyn_SAD_Diff_TC_gain_min, pParam->u8_dyn_SAD_Diff_TC_gain_max,tc_slp, 16);

	//becare, Lin, This need use sad diff prev-cur, not absolute sad; shift6bit.
	pOutput->u32_glb_sad_cur = s_pContext->_output_read_comreg.u30_me_aSAD_rb;
	sad_diff                 = (_ABS_DIFF_(pOutput->u32_glb_sad_cur , pOutput->u32_glb_sad_pre))>>6;
	sad_slp				     = (pParam->u8_dyn_SAD_Diff_sadAll_gain_max - pParam->u8_dyn_SAD_Diff_sadAll_gain_min) *  65536 / ((pParam->u28_dyn_SAD_Diff_sadAll_th_h>>6) - (pParam->u28_dyn_SAD_Diff_sadAll_th_l>>6));
	pOutput->u8_saddiff_gain = _IncreaseCurveMapping(sad_diff,(pParam->u28_dyn_SAD_Diff_sadAll_th_l>>6), pParam->u8_dyn_SAD_Diff_sadAll_gain_min, pParam->u8_dyn_SAD_Diff_sadAll_gain_max,sad_slp, 16);
	
	pOutput->u8_dynSAD_Diff_Gain = pOutput->u8_tc_gain * pOutput->u8_saddiff_gain / 255;
	
	if (pOutput->u8_dynSAD_Diff_Gain >= pParam->u8_dyn_SADGain_thr)
	{
		pOutput->u1_is_saddiff_large = 1;
	}
	else
	{
		pOutput->u1_is_saddiff_large = 0;
	}

	pOutput->u32_glb_sad_pre = pOutput->u32_glb_sad_cur;
}

VOID FRC_RgPanning_Detect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	
	if (pParam->u1_RgPan_Detect_en == 1)
	{
		int idx;
		UBYTE  rg_pann_alp;
		UINT32 rg_mv_diff_prm  = pParam->u16_RgPan_rMV_th_h - pParam->u16_RgPan_rMV_th_l;
		UINT32 rg_mv_slope      = rg_mv_diff_prm <= 0 ? 0 : 16 * 255 / rg_mv_diff_prm;

		UINT32 rg_sc_diff_prm  = pParam->u22_RgPan_rSC_th_h - pParam->u22_RgPan_rSC_th_l;
		UINT32 rg_sc_slope      = rg_sc_diff_prm <= 0 ? 0 : 16 * 255 / rg_sc_diff_prm;

		UINT32 rg_tc_diff_prm  = pParam->u22_RgPan_rTC_th_h - pParam->u22_RgPan_rTC_th_l;
		UINT32 rg_tc_slope      = rg_tc_diff_prm <= 0 ? 0 : 16 * 255 / rg_tc_diff_prm;

		pOutput->u32_RgPan_idx  = 0;

		for (idx=0; idx<32; idx++)
		{
			UINT32 rg_mv = _ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[idx]) + _ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[idx]);
			UBYTE  rg_mv_alp = _IncreaseCurveMapping2(rg_mv, pParam->u16_RgPan_rMV_th_l, 16, rg_mv_slope, 8);//_IncreaseCurveMapping(rg_mv, pParam->u16_RgPan_rMV_th_l, 0, 16, rg_mv_slope, 8)
			
			UBYTE  rg_sc_alp = _IncreaseCurveMapping2(s_pContext->_output_read_comreg.u22_me_rSC_rb[idx], pParam->u22_RgPan_rSC_th_l, 16, rg_sc_slope, 8);//_IncreaseCurveMapping(s_pContext->_output_read_comreg.u22_me_rSC_rb[idx], pParam->u22_RgPan_rSC_th_l, 0, 16, rg_sc_slope, 8)
			
			UBYTE  rg_tc_alp = _IncreaseCurveMapping2(s_pContext->_output_read_comreg.u22_me_rTC_rb[idx], pParam->u22_RgPan_rTC_th_l, 16, rg_tc_slope, 8);//_IncreaseCurveMapping(s_pContext->_output_read_comreg.u22_me_rTC_rb[idx], pParam->u22_RgPan_rTC_th_l, 0, 16, rg_tc_slope, 8)

			rg_sc_alp = _CLIP_((16- rg_sc_alp),0,16);
			rg_tc_alp = _CLIP_((16- rg_tc_alp),0,16);

			rg_pann_alp = (rg_mv_alp * rg_sc_alp * rg_tc_alp)/(16*16);

			if (rg_pann_alp > pParam->u5_RgPan_alp_th)
			{
				pOutput->u32_RgPan_idx = pOutput->u32_RgPan_idx | (1<<idx);
			}

		}
	} 
	else
	{
		pOutput->u32_RgPan_idx = 0;
	}
}

VOID FRC_Still_Pattern_Detect(const _PARAM_FilmDetectCtrl *pParam,  _OUTPUT_FilmDetectCtrl *pOutput_film,  _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	static UINT32 still_cnt = 0;
	UBYTE u1_still = 0;
	static UBYTE u8_pre_cadence_Id = 0;
	UINT32 mot_diff_th = 0x8;
	UINT32 frmCnt_th = 4 * frc_cadTable[pOutput_film->u8_cur_cadence_out[_FILM_ALL]].cad_outLen / frc_cadTable[pOutput_film->u8_cur_cadence_out[_FILM_ALL]].cad_inLen;
	UINT32 mot_diff = pOutput_film->u27_ipme_motionPool[_FILM_ALL][0];

	if(u8_pre_cadence_Id != pOutput_film->u8_cur_cadence_out[_FILM_ALL])
	{
		u8_pre_cadence_Id = pOutput_film->u8_cur_cadence_out[_FILM_ALL];
		still_cnt = 0;
	}
	if(pOutput_film->u8_cur_cadence_out[_FILM_ALL] >= _FRC_CADENCE_NUM_)
	{
		LogPrintf(DBG_WARNING,"[%s]Invalid u8_cur_cadence_out[_FILM_ALL]=%d.Resume!\n",__FUNCTION__,pOutput_film->u8_cur_cadence_out[_FILM_ALL]);
		pOutput_film->u8_cur_cadence_out[_FILM_ALL] = _CAD_VIDEO;
	}

	if(mot_diff < mot_diff_th)
	{
		still_cnt = ((still_cnt < 255) ? (still_cnt + 1) : 255);
	}
	else
	{
		still_cnt = 0;
	}

	if(pOutput_film->u8_cur_cadence_out[_FILM_ALL] == _CAD_22)
	{
		frmCnt_th = 16;
	}

	if(pParam->u1_StillDetect_En == 1 && still_cnt > frmCnt_th)
	{
		u1_still = 1;
	}

	pOutput->u1_still_frame = u1_still;
}

VOID FRC_Zoom_Detect(const _PARAM_FRC_SceneAnalysis *pParam,  _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	if(pParam->u1_zoom_detect_en)
	{
		if(s_pContext->_external_info.u1_ZoomAction == 1 || s_pContext->_external_info.u1_ShiftAction == 1)
		{
			pOutput->u8_zoom_force_fb_cnt = 20;
		}
		else if(pOutput->u8_zoom_force_fb_cnt != 0)
		{
			pOutput->u8_zoom_force_fb_cnt--;
		}
		else
		{
			pOutput->u8_zoom_force_fb_cnt = 0;	
		}
	}
	else
	{
		pOutput->u8_zoom_force_fb_cnt = 0;
	}

}


VOID FRC_FastMotion_Detect(const _PARAM_FRC_SceneAnalysis *pParam,  _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UINT32 u32_rimRatio       = (s_pContext->_output_rimctrl.u32_rimRatio == 0) ? 128 : s_pContext->_output_rimctrl.u32_rimRatio;
	u32_rimRatio = (u32_rimRatio > 128) ? 128:u32_rimRatio;


	UINT32 hpan_th_rb = pParam->u8_hpan_th;
	UINT32 vpan_th_rb = pParam->u8_vpan_th;
	UINT32 cnt2_th_rb = pParam->u8_cnt2_th;

	UINT16 hpan_th = (hpan_th_rb<<8)*u32_rimRatio/128; 
	UINT16 vpan_th = (vpan_th_rb<<8)*u32_rimRatio/128;
	UINT16 cnt2_th = cnt2_th_rb<<4;

	UBYTE u8_fastMotion_entercnt_th = 0x0;
	UBYTE u8_fastMotion_holdCnt_max = 0x18;

	UINT32 u25_glb_dtl_th = (pParam->u25_glb_dtl_th)<<8;	

	UINT32 u20_hpan_cnt = s_pContext->_output_read_comreg.u20_me_Hpan_cnt_rb;
	UINT32 u20_vpan_cnt = s_pContext->_output_read_comreg.u20_me_Vpan_cnt_rb;
	UINT32 u25_me_glb_dtl = s_pContext->_output_read_comreg.u25_me_aDTL_rb;

	static UBYTE u8_fastMotion_holdcnt = 0;
	static UBYTE u8_fastMotion_entercnt = 0;
	UBYTE u1_fastMotion_cond = 0;
	UBYTE u1_fastMotion_det = 0;

	if( u20_hpan_cnt < hpan_th
	&& u20_vpan_cnt < vpan_th
	&& (s_pContext->_output_read_comreg.u17_me_posCnt_2_rb+s_pContext->_output_read_comreg.u17_me_negCnt_2_rb) > cnt2_th
	&& u25_me_glb_dtl > u25_glb_dtl_th
	)
	{
		u1_fastMotion_cond = 1;
	}
	else
	{	
		u1_fastMotion_cond = 0;
	}

	u8_fastMotion_entercnt = (u1_fastMotion_cond == 1) ? (u8_fastMotion_entercnt + 1) : 0;
	u8_fastMotion_entercnt = _CLIP_UBOUND_(u8_fastMotion_entercnt, 254);

	u8_fastMotion_holdcnt = (u8_fastMotion_entercnt > u8_fastMotion_entercnt_th) ? u8_fastMotion_holdCnt_max : 
						((u8_fastMotion_holdcnt > 0) ? (u8_fastMotion_holdcnt - 1) : 0);

	pOutput->u1_fastMotion_det = (u8_fastMotion_holdcnt > 0 && pParam->u1_fastMotion_det_en) ? 1 : 0;
						
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 19, _MIN_(u8_fastMotion_holdcnt, 0xf));
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 20, 23, _MIN_(u8_fastMotion_entercnt, 0xf));
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 27, _MIN_(pOutput->u1_fastMotion_det, 0xf));

}

VOID FRC_SpecialSCFB_Detect(const _PARAM_FRC_SceneAnalysis *pParam,  _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE  u8_cadence_Id = s_pContext->_output_filmDetectctrl.u8_cur_cadence_out[_FILM_ALL];
	PQL_INPUT_FRAME_RATE in_fmRate = s_pContext->_external_data._input_frameRate;
	
	if(pParam->u1_special_scfb_en && s_pContext->_output_wrt_comreg.u8_FB_lvl<0x20 && 
		(u8_cadence_Id == _CAD_22 || u8_cadence_Id == _CAD_32 || ((in_fmRate == _PQL_IN_24HZ || in_fmRate == _PQL_IN_25HZ) && (u8_cadence_Id == _CAD_VIDEO))))
	{
		pOutput->u1_specialscfb_true = 1;
	}
	else
	{
		pOutput->u1_specialscfb_true = 0;
	}
}
VOID FRC_SceneAnalysis_Proc(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	FRC_FadeInOut_Detect(pParam, pOutput);
	FRC_InsidePanning_Detect(pParam, pOutput);
	FRC_Dynamic_ACDCBld(pParam,		pOutput);
	FRC_Dynamic_SearchRange(pParam, pOutput);
	FRC_Dynamic_SAD_Diff(pParam, 	pOutput);
	FRC_BdySmallMV_Detect(pParam, pOutput);
	if (pParam->s2m_method_sel == 0)
	{
		FRC_Scene2Motion_Hist(pParam, pOutput);
	}
	else
	{
		FRC_Scene2Motion(pParam,pOutput);
	}

	FRC_RgPanning_Detect(pParam, 	pOutput);

	FRC_Zoom_Detect(pParam, pOutput);

	FRC_SpecialSCFB_Detect(pParam, pOutput);

}


//---------------------
//INPUT INTERRUPT CALL:
//---------------------
VOID MEMC_HDR_PicChg_Protect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	if(s_pContext->_external_info.u1_HDR_Chg)
		pOutput->u8_HDR_PicChg_prt_apply = 6;

	else if(s_pContext->_output_frc_sceneAnalysis.u8_HDR_PicChg_prt_apply > 0)
		pOutput->u8_HDR_PicChg_prt_apply = s_pContext->_output_frc_sceneAnalysis.u8_HDR_PicChg_prt_apply - 1;
	else
		pOutput->u8_HDR_PicChg_prt_apply = 0;

}


VOID MEMC_OSDBrightnessBigChg_Protect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE u8_OSDBri_sub_pre = (pOutput->u16_OSDBrightnessVal >> 8);
	UBYTE u8_OSDBri_main_pre = (pOutput->u16_OSDBrightnessVal & 0xff);

	UBYTE u8_OSDBri_sub_cur = (s_pContext->_external_info.u16_Brightness >> 8);
	UBYTE u8_OSDBri_main_cur = (s_pContext->_external_info.u16_Brightness & 0xff);


	UBYTE u8_brightness_th_l = 6; // UI Brightness Range: [0,100] , th Range: [0,255]

	if((_ABS_DIFF_(u8_OSDBri_main_pre, u8_OSDBri_main_cur) > u8_brightness_th_l)
		|| (_ABS_DIFF_(u8_OSDBri_sub_pre, u8_OSDBri_sub_cur) > u8_brightness_th_l))
		pOutput->u8_OSDBrightnessBigChg_prt_apply = 5;
	else if(pOutput->u8_OSDBrightnessBigChg_prt_apply > 0)
		pOutput->u8_OSDBrightnessBigChg_prt_apply = pOutput->u8_OSDBrightnessBigChg_prt_apply - 1;
	else
		pOutput->u8_OSDBrightnessBigChg_prt_apply = 0;

	pOutput->u16_OSDBrightnessVal = s_pContext->_external_info.u16_Brightness;

	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 7, u8_OSDBri_main_cur);
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 15, u8_OSDBri_main_pre);
}


VOID MEMC_OSDContrastBigChg_Protect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE u8_OSDCon_sub_pre = (pOutput->u16_OSDContrastVal >> 8);
	UBYTE u8_OSDCon_main_pre = (pOutput->u16_OSDContrastVal & 0xff);

	UBYTE u8_OSDCon_sub_cur = (s_pContext->_external_info.u16_Contrast >> 8);
	UBYTE u8_OSDCon_main_cur = (s_pContext->_external_info.u16_Contrast & 0xff);


	UBYTE u8_contrast_th_l = 6; // UI Contrast Range: [0,100] , th Range: [0,255]

	if((_ABS_DIFF_(u8_OSDCon_main_pre, u8_OSDCon_main_cur) > u8_contrast_th_l)
		|| (_ABS_DIFF_(u8_OSDCon_sub_pre, u8_OSDCon_sub_cur) > u8_contrast_th_l))
		pOutput->u8_OSDContrastBigChg_prt_apply = 5;
	else if(pOutput->u8_OSDContrastBigChg_prt_apply > 0)
		pOutput->u8_OSDContrastBigChg_prt_apply = pOutput->u8_OSDContrastBigChg_prt_apply - 1;
	else
		pOutput->u8_OSDContrastBigChg_prt_apply = 0;

	pOutput->u16_OSDContrastVal = s_pContext->_external_info.u16_Contrast;

	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 23, u8_OSDCon_main_cur);
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 31, u8_OSDCon_main_pre);

}

VOID MEMC_VOSeek_Protect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();

	UBYTE u1_voseek_en = s_pParam->_param_frc_sceneAnalysis.u1_mc2_var_lpf_wrt_en; // 0912,lisa,temporal use, can be change if sync all dynamicPQ from K2

	if(s_pContext->_external_info.u1_mVOSeek == 1)
		pOutput->u8_VOSeek_prt_apply = 12;
	else if(pOutput->u8_VOSeek_prt_apply >= 1)
		pOutput->u8_VOSeek_prt_apply = pOutput->u8_VOSeek_prt_apply-1;
	else
		pOutput->u8_VOSeek_prt_apply = 0;

	if(u1_voseek_en == 0)
		pOutput->u8_VOSeek_prt_apply = 0;
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 19, pOutput->u8_VOSeek_prt_apply);

}

VOID MEMC_OSDPictureModeChg_Protect(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	if((s_pContext->_external_info.u1_PictureMode_Chg == 1) /*&& (pOutput->u1_still_frame == 1)*/){
		pOutput->u8_OSDPictureModeChg_prt_apply = 16;
	}
	else if(pOutput->u8_OSDPictureModeChg_prt_apply > 0)
		pOutput->u8_OSDPictureModeChg_prt_apply = pOutput->u8_OSDPictureModeChg_prt_apply - 1;
	else
		pOutput->u8_OSDPictureModeChg_prt_apply = 0;

	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 7, u8_OSDBri_main_cur);
	//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 15, u8_OSDBri_main_pre);
}

VOID FRC_SceneAnalysis_Proc_InputIntp(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput)
{
	//hdr <-> normal
      	MEMC_HDR_PicChg_Protect(pParam, pOutput);

	//osd brightness big change, broken, need fallback
	MEMC_OSDBrightnessBigChg_Protect(pParam, pOutput);
	MEMC_OSDContrastBigChg_Protect(pParam, pOutput);

	// vo seek
	MEMC_VOSeek_Protect(pParam, pOutput);

	// Picture Mode
	MEMC_OSDPictureModeChg_Protect(pParam, pOutput);
}

