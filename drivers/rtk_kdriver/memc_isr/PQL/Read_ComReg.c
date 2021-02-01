#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"

//////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
VOID ReadComReg_Init(_OUTPUT_ReadComReg *pOutput)
{

}

//Input signal and parameters are connected locally

VOID ReadComReg_Proc_oneFifth_OutInterrupt(const _PARAM_ReadComReg *pParam, _OUTPUT_ReadComReg *pOutput)
{
	UINT32 u32_rb_val;

	if (pParam->u1_me_VbufSize_rb_en == 1)
	{
		ReadRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_hactive_ADDR, 0, 31, &u32_rb_val);
		pOutput->u8_me1_Vbuf_Hsize_rb =  u32_rb_val       & 0x1FF;
		pOutput->u8_me1_Vbuf_Vsize_rb = (u32_rb_val >> 9) & 0x1FF;
	}

	if (pParam->u1_BBD_rb_en == 1)
	{
		UBYTE u8_k = 0;
		for (u8_k = 0; u8_k < _RIM_NUM; u8_k ++)
		{
			ReadRegister(FRC_TOP__BBD__reg_BBD_top_sketchy_active_line_ADDR + u8_k * 4, 0, 31, &u32_rb_val);
			pOutput->u12_BBD_roughRim_rb[u8_k]  =  u32_rb_val        & 0x1fff;
			pOutput->u1_BBD_roughValid_rb[u8_k] = (u32_rb_val >> 13) & 0x01;
			pOutput->u12_BBD_fineRim_rb[u8_k]   = (u32_rb_val >> 16) & 0x1fff;
			pOutput->u1_BBD_fineValid_rb[u8_k]  = (u32_rb_val >> 29) & 0x01;
		}
		
        ReadRegister(FRC_TOP__KME_DM_TOP2__reg_mv05_hactive_ADDR, 0, 31, &u32_rb_val);
		pOutput->u12_ME1_blk_size[0] =   u32_rb_val        & 0xfff;
		pOutput->u12_ME1_blk_size[1] =  (u32_rb_val >> 12) & 0xfff;

		ReadRegister(FRC_TOP__KME_DM_TOP0__reg_kme_me_hactive_ADDR, 0, 31, &u32_rb_val);
		pOutput->u12_ME1_pix_size[0] =   u32_rb_val        & 0xfff;
		pOutput->u12_ME1_pix_size[1] =  (u32_rb_val >> 12) & 0xfff;

		ReadRegister(FRC_TOP__KME_DM_TOP2__reg_mv01_hactive_ADDR, 0, 31, &u32_rb_val);
		pOutput->u12_ME2_blk_size[0] =   u32_rb_val        & 0xfff;
		pOutput->u12_ME2_blk_size[1] =  (u32_rb_val >> 12) & 0xfff;

		ReadRegister(FRC_TOP__KME_DM_TOP2__reg_mv12_hactive_ADDR, 0, 31, &u32_rb_val);
		pOutput->u12_ME2_pix_size[0] =   u32_rb_val        & 0xfff;
		pOutput->u12_ME2_pix_size[1] =  (u32_rb_val >> 12) & 0xfff;
	
	}
}

VOID ReadComReg_Proc_inputInterrupt(const _PARAM_ReadComReg *pParam, _OUTPUT_ReadComReg *pOutput)
{
	UINT32 u32_RB_val;

	//////////////////////////////////////////////////////////////////////////
	// gmv all information
	//////////////////////////////////////////////////////////////////////////
	if (pParam->u1_me_GMV_1st_rb_en == 1)
	{
		ReadRegister(FRC_TOP__KME_ME1_TOP2__regr_me1_gmv_grp0_mvx_ADDR, 0, 31, &u32_RB_val);
		pOutput->s11_me_GMV_1st_vx_rb = ((u32_RB_val >> 10) &1) == 0? (u32_RB_val         & 0x7ff) : ((u32_RB_val         & 0x7ff)  - (1<<11));
		pOutput->s10_me_GMV_1st_vy_rb = ((u32_RB_val >> 20) &1) == 0? ((u32_RB_val >> 11) & 0x3ff) : (((u32_RB_val >> 11) & 0x3ff)  - (1<<10));
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__regr_me1_gmv_grp0_cnt), &u32_RB_val);
		pOutput->u6_me_GMV_1st_cnt_rb = u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__regr_me1_gmv_grp0_unconf), &u32_RB_val);
		pOutput->u12_me_GMV_1st_unconf_rb = u32_RB_val;
	}

	if (pParam->u1_me_GMV_2nd_rb_en == 1)
	{
		ReadRegister(FRC_TOP__KME_ME1_TOP2__regr_me1_gmv_grp1_mvx_ADDR, 0, 31, &u32_RB_val);
		pOutput->s11_me_GMV_2nd_vx_rb = ((u32_RB_val >> 10) &1) == 0? (u32_RB_val         & 0x7ff) : ((u32_RB_val         & 0x7ff) - (1<<11));
		pOutput->s10_me_GMV_2nd_vy_rb = ((u32_RB_val >> 20) &1) == 0? ((u32_RB_val >> 11) & 0x3ff) : (((u32_RB_val >> 11) & 0x3ff) - (1<<10));
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__regr_me1_gmv_grp1_cnt), &u32_RB_val);
		pOutput->u6_me_GMV_2nd_cnt_rb = u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__regr_me1_gmv_grp1_unconf), &u32_RB_val);
		pOutput->u12_me_GMV_2nd_unconf_rb = u32_RB_val;
	}

	//////////////////////////////////////////////////////////////////////////
	// panning cnt
	//////////////////////////////////////////////////////////////////////////
	if(pParam->u1_me_Hpan_cnt_rb_en)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_hpan_cnt), &u32_RB_val);
		pOutput->u20_me_Hpan_cnt_rb = u32_RB_val;
	}

	if(pParam->u1_me_Vpan_cnt_rb_en)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_vpan_cnt), &u32_RB_val);
		pOutput->u20_me_Vpan_cnt_rb = u32_RB_val;
	}
	

	//////////////////////////////////////////////////////////////////////////
	// for LBMC mode switch.
	//////////////////////////////////////////////////////////////////////////
	if (pParam->u1_me_pnMV_cnt_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_pcnt0), &u32_RB_val);
		pOutput->u17_me_posCnt_0_rb =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_pcnt1), &u32_RB_val);
		pOutput->u17_me_posCnt_1_rb =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_pcnt2), &u32_RB_val);
		pOutput->u17_me_posCnt_2_rb =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_pcnt3), &u32_RB_val);
		pOutput->u17_me_posCnt_3_rb =  u32_RB_val;

		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_ncnt0), &u32_RB_val);
		pOutput->u17_me_negCnt_0_rb =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_ncnt1), &u32_RB_val);
		pOutput->u17_me_negCnt_1_rb =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_ncnt2), &u32_RB_val);
		pOutput->u17_me_negCnt_2_rb =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_bvy_ncnt3), &u32_RB_val);
		pOutput->u17_me_negCnt_3_rb =  u32_RB_val;
	}

	//////////////////////////////////////////////////////////////////////////
	// ipme, film detect information
	//////////////////////////////////////////////////////////////////////////
	UINT32 u27_ipme_h0Mot_rb = 0;
	UINT32 u27_ipme_h1Mot_rb = 0;
	UINT32 u27_ipme_v0Mot_rb = 0;
	UINT32 u27_ipme_v1Mot_rb = 0;
	{	
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_h0_rim), &u32_RB_val);
		u27_ipme_h0Mot_rb = u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_h1_rim), &u32_RB_val);
		u27_ipme_h1Mot_rb = u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_v0_rim), &u32_RB_val);
		u27_ipme_v0Mot_rb = u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_v1_rim), &u32_RB_val);
		u27_ipme_v1Mot_rb = u32_RB_val;
	}

	
	if (pParam->u1_ipme_aMot_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_all), &u32_RB_val);
		pOutput->u27_ipme_aMot_rb    =  u32_RB_val;

		//minus rim line motion from bad-DI, use 12rgn motion to avoid bad-DI affect, but keep this idea here
		UINT32 u27_ipme_rimMot_rb = (u27_ipme_h0Mot_rb + u27_ipme_h1Mot_rb + u27_ipme_v0Mot_rb + u27_ipme_v1Mot_rb);
		u27_ipme_rimMot_rb = 0;
		pOutput->u27_ipme_aMot_rb = (pOutput->u27_ipme_aMot_rb < u27_ipme_rimMot_rb) ? 0 : (pOutput->u27_ipme_aMot_rb - u27_ipme_rimMot_rb);
	}
	if(pParam->u1_ipme_5rMot_rb_en == 1)
	{
		UINT16 u16_top_v0 = 0;
		UINT16 u16_top_v1 = 0;
		UINT16 u16_bot_v0 = 0;
		UINT16 u16_bot_v1 = 0;
		UINT16 u16_lft_h0 = 0;
		UINT16 u16_lft_h1 = 0;
		UINT16 u16_rgt_h0 = 0;
		UINT16 u16_rgt_h1 = 0;
		UINT16 u16_ipme_res_x = 960/2;
		UINT16 u16_ipme_res_y = 540;

		ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region1_v0_ADDR), 0, 31, &u32_RB_val);//top
		u16_top_v0 = (u32_RB_val) & 0x3ff;
		u16_top_v1 = (u32_RB_val>>10) & 0x3ff;
		ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region2_v0_ADDR), 0, 31, &u32_RB_val);//bottom
		u16_bot_v0 = (u32_RB_val) & 0x3ff;
		u16_bot_v1 = (u32_RB_val>>10) & 0x3ff;
		ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region3_h0_ADDR), 0, 31, &u32_RB_val);//left
		u16_lft_h0 = (u32_RB_val) & 0x3ff;
		u16_lft_h1 = (u32_RB_val>>10) & 0x3ff;
		ReadRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region4_h0_ADDR), 0, 31, &u32_RB_val);//bottom
		u16_rgt_h0 = (u32_RB_val) & 0x3ff;
		u16_rgt_h1 = (u32_RB_val>>10) & 0x3ff;
	
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_5region1), &u32_RB_val);//top
		pOutput->u27_ipme_5Mot_rb[0] =  u32_RB_val;
		UINT16 u16_LR_rimMot_t = (u27_ipme_h0Mot_rb + u27_ipme_h1Mot_rb)*((u16_top_v1<u16_top_v0)?0:(u16_top_v1-u16_top_v0))/u16_ipme_res_y;
		u16_LR_rimMot_t = 0;
		pOutput->u27_ipme_5Mot_rb[0]= (pOutput->u27_ipme_5Mot_rb[0] < u16_LR_rimMot_t) ? 0 : (pOutput->u27_ipme_5Mot_rb[0] - u16_LR_rimMot_t);

		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_5region2), &u32_RB_val);//bot
		pOutput->u27_ipme_5Mot_rb[1] =  u32_RB_val;
		UINT16 u16_LR_rimMot_b = (u27_ipme_h0Mot_rb + u27_ipme_h1Mot_rb)*((u16_bot_v1<u16_bot_v0)?0:(u16_bot_v1- u16_bot_v0))/u16_ipme_res_y;
		u16_LR_rimMot_b = 0;
		pOutput->u27_ipme_5Mot_rb[1]= (pOutput->u27_ipme_5Mot_rb[1] < u16_LR_rimMot_b) ? 0 : (pOutput->u27_ipme_5Mot_rb[1] - u16_LR_rimMot_b);

		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_5region3), &u32_RB_val);//left
		pOutput->u27_ipme_5Mot_rb[2] =  u32_RB_val;
		UINT16 u16_TB_rimMot_l = (u27_ipme_v0Mot_rb + u27_ipme_v1Mot_rb)*((u16_lft_h1< u16_lft_h0)?0:(u16_lft_h1- u16_lft_h0))/u16_ipme_res_x;
		u16_TB_rimMot_l = 0;
		pOutput->u27_ipme_5Mot_rb[2]= (pOutput->u27_ipme_5Mot_rb[2] < u16_TB_rimMot_l) ? 0 : (pOutput->u27_ipme_5Mot_rb[2] - u16_TB_rimMot_l);

		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_5region4), &u32_RB_val);//right
		pOutput->u27_ipme_5Mot_rb[3] =  u32_RB_val;
		UINT16 u16_TB_rimMot_r = (u27_ipme_v0Mot_rb + u27_ipme_v1Mot_rb)*((u16_rgt_h1< u16_rgt_h0)?0:(u16_rgt_h1- u16_rgt_h0))/u16_ipme_res_x;
		u16_TB_rimMot_r = 0;
		pOutput->u27_ipme_5Mot_rb[3]= (pOutput->u27_ipme_5Mot_rb[3] < u16_TB_rimMot_r) ? 0 : (pOutput->u27_ipme_5Mot_rb[3] - u16_TB_rimMot_r);

		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_5region5), &u32_RB_val);//cen
		pOutput->u27_ipme_5Mot_rb[4] =  u32_RB_val;
	}
	if(pParam->u1_ipme_12rMot_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region1), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[0] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region2), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[1] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region3), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[2] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region4), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[3] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region5), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[4] =  u32_RB_val;

		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region6), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[5] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region7), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[6] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region8), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[7] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region9), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[8] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region10), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[9] =  u32_RB_val;

		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region11), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[10] =  u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_mot_12region12), &u32_RB_val);
		pOutput->u27_ipme_12Mot_rb[11] =  u32_RB_val;
	}

	{
		//use 12 rgn motion for mixmode to avoid outside of rim
		//top
		UINT32 u27_12rgn_top = 	pOutput->u27_ipme_12Mot_rb[0] + 
								pOutput->u27_ipme_12Mot_rb[1] + 
								pOutput->u27_ipme_12Mot_rb[2] + 
								pOutput->u27_ipme_12Mot_rb[3];
		//bot
		UINT32 u27_12rgn_bot = 	pOutput->u27_ipme_12Mot_rb[8] + 
								pOutput->u27_ipme_12Mot_rb[9] + 
								pOutput->u27_ipme_12Mot_rb[10] + 
								pOutput->u27_ipme_12Mot_rb[11];
		//lft
		UINT32 u27_12rgn_lft = 	pOutput->u27_ipme_12Mot_rb[0] + 
								pOutput->u27_ipme_12Mot_rb[4] + 
								pOutput->u27_ipme_12Mot_rb[8];
		//rgt
		UINT32 u27_12rgn_rgt = 	pOutput->u27_ipme_12Mot_rb[3] + 
								pOutput->u27_ipme_12Mot_rb[7] + 
								pOutput->u27_ipme_12Mot_rb[11];

		pOutput->u27_ipme_5Mot_rb[0]= u27_12rgn_top;
		pOutput->u27_ipme_5Mot_rb[1]= u27_12rgn_bot;
		pOutput->u27_ipme_5Mot_rb[2]= u27_12rgn_lft;
		pOutput->u27_ipme_5Mot_rb[3]= u27_12rgn_rgt;

	}

	if (pParam->u1_ipme_filmMode_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_IPME__rdbk_ipme_fdet_film_mode), &u32_RB_val);
		pOutput->u3_ipme_filmMode_rb = u32_RB_val;
	}

	//////////////////////////////////////////////////////////////////////////
	// kphase information
	//////////////////////////////////////////////////////////////////////////
	if (pParam->u1_kphase_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__kphase__regr_kphase_in_phase), &u32_RB_val);
		pOutput->u4_kphase_inPhase   = u32_RB_val;

		ReadRegister(KIWI_REG(FRC_TOP__kphase__regr_kphase_in_lr), &u32_RB_val);
		pOutput->u1_kphase_inLR      = u32_RB_val;

		ReadRegister(FRC_TOP__CRTC1__reg_crtc1_n_ADDR, 8, 23, &u32_RB_val);
		pOutput->u8_sys_N_rb      =  u32_RB_val       & 0xFF;
		pOutput->u8_sys_M_rb      = (u32_RB_val >> 8) & 0xFF;

		ReadRegister(FRC_TOP__CRTC1__reg_crtc1_dec_vtrig_dly_ADDR, 6, 18, &u32_RB_val);
		pOutput->u13_dec_vtrig_dly       =  u32_RB_val       & 0x1FFF;

		ReadRegister(FRC_TOP__CRTC1__regr_crtc1_vspll_finer_v_total_ADDR,  0,  12,  &u32_RB_val);
		pOutput->u13_vtotal              =  u32_RB_val       & 0x1FFF;
	}

	//////////////////////////////////////////////////////////////////////////
	//Logo cnt readback
	//////////////////////////////////////////////////////////////////////////
	//no enable currently
	//if(pParam->u1_lg_blk_cnt_rb_en == 1)
	{
		UINT32 idx;
		for (idx=0; idx < LOGO_RG_32; idx++)
		{
			ReadRegister(FRC_TOP__KME_LOGO2__reg_rdbk_km_logo_blkrg_idx0_cnt_ADDR + idx * 4,
						FRC_TOP__KME_LOGO2__reg_rdbk_km_logo_blkrg_idx0_cnt_BITSTART,
						FRC_TOP__KME_LOGO2__reg_rdbk_km_logo_blkrg_idx0_cnt_BITEND, pOutput->u10_blklogo_rgcnt + idx);
		}
		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_00), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt[0] = u32_RB_val     & 0xFF;
		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_04), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt[1] = u32_RB_val     & 0xFF;
		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_20), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt[2] = u32_RB_val     & 0xFF;
		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_24), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt[3] = u32_RB_val     & 0xFF;

		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_21), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt_bot[0] = u32_RB_val     & 0xFF;

		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_22), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt_bot[1] = u32_RB_val     & 0xFF;

		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_23), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt_bot[2] = u32_RB_val     & 0xFF;

		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_01), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt_top[0] = u32_RB_val     & 0xFF;

		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_02), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt_top[1] = u32_RB_val     & 0xFF;

		ReadRegister(KIWI_REG(FRC_TOP__KME_DEHALO__regr_dh_logo_rdbk_03), &u32_RB_val);		
		pOutput->u16_blklogo_dh_clrcnt_top[2] = u32_RB_val     & 0xFF;

	}
}
VOID ReadComReg_Proc_outputInterrupt(const _PARAM_ReadComReg *pParam, _OUTPUT_ReadComReg *pOutput)
{
	UINT32 u32_RB_val;
	UINT32 u32_i;

	// scene change
	if (pParam->u1_sc_status_rb_en == 1)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__regr_me1_sc_sync_me1), 0x01);
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__regr_me1_sc_sync_me1), &u32_RB_val);
		pOutput->u1_sc_status_rb = u32_RB_val;

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__regr_me1_sc_sync_logo), 0x01);
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__regr_me1_sc_sync_logo), &u32_RB_val);
		pOutput->u1_sc_status_logo_rb = u32_RB_val;

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__regr_me1_sc_sync_dh), 0x01);
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__regr_me1_sc_sync_dh), &u32_RB_val);
		pOutput->u1_sc_status_dh_rb = u32_RB_val;
	}

	if (pParam->u1_me_aTC_rb_en == 1)
	{
		UINT32 u32_RB_val1 = 0, u32_RB_val2 = 0, u32_RB_val3 = 0;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_glb_tcss), &u32_RB_val);

		if (pParam->u2_rb_tc_mode == 0)
		{
		pOutput->u27_me_aTC_rb = u32_RB_val;
	}
		else if (pParam->u2_rb_tc_mode == 1)
		{
			ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_tcss_th_cnt1), &u32_RB_val1);
			ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_tcss_th_cnt2), &u32_RB_val2);
			ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_tcss_th_cnt3), &u32_RB_val3);

			pOutput->u27_me_aTC_rb = u32_RB_val1*pParam->u4_rb_tc1_coef + u32_RB_val2*pParam->u4_rb_tc2_coef + u32_RB_val3*pParam->u4_rb_tc3_coef;
		}
		else //if (pParam->u2_rb_tc_mode == 2)
		{
			ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_tcss_th_sum1), &u32_RB_val1);
			ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_tcss_th_sum2), &u32_RB_val2);
			ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_tcss_th_sum3), &u32_RB_val3);

			pOutput->u27_me_aTC_rb = u32_RB_val1*pParam->u4_rb_tc1_coef + u32_RB_val2*pParam->u4_rb_tc2_coef + u32_RB_val3*pParam->u4_rb_tc3_coef;
		}
	}
	if (pParam->u1_me_aSC_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_glb_scss), &u32_RB_val);
		pOutput->u27_me_aSC_rb = u32_RB_val;
	}
	if (pParam->u1_me_aSAD_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_glb_sad), &u32_RB_val);
		pOutput->u30_me_aSAD_rb = u32_RB_val;
	}
	if (pParam->u1_me_aDTL_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_glb_dtl), &u32_RB_val);
		pOutput->u25_me_aDTL_rb = u32_RB_val;
	}

	if (pParam->u1_me_aAPLi_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_glb_apli), &u32_RB_val);
		pOutput->u26_me_aAPLi_rb = u32_RB_val;
	}
	if (pParam->u1_me_aAPLp_rb_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_glb_aplp), &u32_RB_val);
		pOutput->u26_me_aAPLp_rb = u32_RB_val;
	}

	// 32 rgn sad, dtl, apl, tc, sc, rmv
	for (u32_i = 0; u32_i < 32; u32_i ++)
	{
		// sad
		if (((pParam->u32_me_rSAD_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP7__regr_me1_statis_rgn00_sad_ADDR + 4 * u32_i, 0, 24, &u32_RB_val);
			pOutput->u25_me_rSAD_rb[u32_i] = u32_RB_val;
		}
		else
		{
			pOutput->u25_me_rSAD_rb[u32_i] = 0;
		}

		// detail
		if (((pParam->u32_me_rDTL_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP7__regr_me1_statis_rgn00_dtl_ADDR + 4 * u32_i, 0, 19, &u32_RB_val);
			pOutput->u20_me_rDTL_rb[u32_i] = u32_RB_val;
		}
		else
		{
			pOutput->u20_me_rDTL_rb[u32_i] = 0;
		}

		// apl_i
		if (((pParam->u32_me_rAPLi_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP9__regr_me1_statis_rgn00_apli_ADDR + 4 * u32_i, 0, 19, &u32_RB_val);
			pOutput->u20_me_rAPLi_rb[u32_i] = u32_RB_val;
		}
		else
		{
			pOutput->u20_me_rAPLi_rb[u32_i] = 0;
		}

		// apl_p
		if (((pParam->u32_me_rAPLp_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP9__regr_me1_statis_rgn00_aplp_ADDR + 4 * u32_i, 0, 19, &u32_RB_val);
			pOutput->u20_me_rAPLp_rb[u32_i] = u32_RB_val;
		}
		else
		{
			pOutput->u20_me_rAPLp_rb[u32_i] = 0;
		}

		// temporal consistency
		if (((pParam->u32_me_rTC_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP8__regr_me1_statis_rgn00_tcss_ADDR + 4 * u32_i, 0, 19, &u32_RB_val);
			pOutput->u22_me_rTC_rb[u32_i] = u32_RB_val;
		}
		else
		{
			pOutput->u22_me_rTC_rb[u32_i] = 0;
		}

		// spatial consistency
		if (((pParam->u32_me_rSC_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP8__regr_me1_statis_rgn00_scss_ADDR + 4 * u32_i, 0, 19, &u32_RB_val);
			pOutput->u22_me_rSC_rb[u32_i] = u32_RB_val;
		}
		else
		{
			pOutput->u22_me_rSC_rb[u32_i] = 0;
		}

		// rmv_1st
		if (((pParam->u32_me_rMV_1st_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP4__regr_me1_rgn00_grp0_mvx_ADDR + 8 * u32_i, 0, 20, &u32_RB_val);
			pOutput->s11_me_rMV_1st_vx_rb[u32_i] = ((u32_RB_val >> 10) &1) == 0? (u32_RB_val         & 0x7ff) : ((u32_RB_val & 0x7ff) - (1<<11));
			pOutput->s10_me_rMV_1st_vy_rb[u32_i] = ((u32_RB_val >> 20) &1) == 0? ((u32_RB_val >> 11) & 0x3ff) : (((u32_RB_val >> 11) & 0x3ff) - (1<<10));

			ReadRegister(FRC_TOP__KME_ME1_TOP5__regr_me1_rgn00_grp0_cnt_ADDR + 4 * u32_i, 0, 31, &u32_RB_val);
			pOutput->u12_me_rMV_1st_cnt_rb[u32_i] = u32_RB_val & 0xfff;

			ReadRegister(FRC_TOP__KME_ME1_TOP5__regr_me1_rgn00_grp0_unconf_ADDR + 4 * u32_i, 0, 31, &u32_RB_val);
			pOutput->u12_me_rMV_1st_unconf_rb[u32_i] = u32_RB_val & 0xfff;
		}
		else
		{
			pOutput->s11_me_rMV_1st_vx_rb[u32_i]     = 0;
			pOutput->s10_me_rMV_1st_vy_rb[u32_i]     = 0;
			pOutput->u12_me_rMV_1st_cnt_rb[u32_i]    = 0;
			pOutput->u12_me_rMV_1st_unconf_rb[u32_i] = 0;
		}

		// rmv_2nd
		if (((pParam->u32_me_rMV_2nd_rb_en >> u32_i)&0x1) == 1)
		{
			ReadRegister(FRC_TOP__KME_ME1_TOP4__regr_me1_rgn00_grp1_mvx_ADDR + 8 * u32_i, 0, 20, &u32_RB_val);
			pOutput->s11_me_rMV_2nd_vx_rb[u32_i] = ((u32_RB_val >> 10) &1) == 0? (u32_RB_val         & 0x7ff) : ((u32_RB_val & 0x7ff) - (1<<11));
			pOutput->s10_me_rMV_2nd_vy_rb[u32_i] = ((u32_RB_val >> 20) &1) == 0? ((u32_RB_val >> 11) & 0x3ff) : (((u32_RB_val >> 11) & 0x3ff) - (1<<10));

			ReadRegister(FRC_TOP__KME_ME1_TOP5__regr_me1_rgn00_grp1_cnt_ADDR + 4 * u32_i, 0, 31, &u32_RB_val);
			pOutput->u12_me_rMV_2nd_cnt_rb[u32_i] = (u32_RB_val >> 12) & 0xfff;

			ReadRegister(FRC_TOP__KME_ME1_TOP5__regr_me1_rgn00_grp1_unconf_ADDR + 4 * u32_i, 0, 31, &u32_RB_val);
			pOutput->u12_me_rMV_2nd_unconf_rb[u32_i] = (u32_RB_val >> 12) & 0xfff;
		}
		else
		{
			pOutput->s11_me_rMV_2nd_vx_rb[u32_i]     = 0;
			pOutput->s10_me_rMV_2nd_vy_rb[u32_i]     = 0;
			pOutput->u12_me_rMV_2nd_cnt_rb[u32_i]    = 0;
			pOutput->u12_me_rMV_2nd_unconf_rb[u32_i] = 0;
		}

		//dh readback
		if (pParam->u1_dh_rb_en == 1)
		{
			ReadRegister(FRC_TOP__KME_DEHALO2__regr_dh_pfvconf_00_ADDR + 4 * u32_i, 0, 31, &u32_RB_val);
			pOutput->u20_dh_pfvconf[u32_i] = u32_RB_val & 0xFFFFF;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	//ZMV dc/ac psad, and
	//////////////////////////////////////////////////////////////////////////
	if (pParam->u1_me_ZMV_psad_rb_en)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_zmv_sad_dc_sum), &u32_RB_val);
		pOutput->u31_me_ZMV_psad_dc_rb = u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_zmv_sad_ac_sum), &u32_RB_val);
		pOutput->u31_me_ZMV_psad_ac_rb = u32_RB_val;

		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_zmv_sad_dc_cnt), &u32_RB_val);
		pOutput->u20_me_ZMV_DcGreatAc_cnt_rb = u32_RB_val;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_zmv_sad_ac_cnt), &u32_RB_val);
		pOutput->u20_me_ZMV_AcGreatDc_cnt_rb = u32_RB_val;

	}

	if (pParam->u1_mc_HVdtl_rb_en == 1)
	{		
		ReadRegister(FRC_TOP__kmc_top__regr_vhdtl_h_o_ADDR, 0, 31, &u32_RB_val);
		pOutput->u16_mc_Hdtl_cnt = u32_RB_val & 0xFFFF;
		pOutput->u16_mc_Vdtl_cnt = u32_RB_val >> 16;
	}

	//mc rdtl 
	for (u32_i = 0; u32_i < 4; u32_i ++)
	{
		if (pParam->u1_mc_HVdtl_rb_en == 1)
		{		
			ReadRegister(FRC_TOP__kmc_top__regr_vhdtl_rgn00_ADDR + 12 * u32_i, 0, 31, &u32_RB_val);
			pOutput->u10_mc_VHdtl_rb[8*u32_i] = u32_RB_val & 0x3FF;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+1] = (u32_RB_val>>10) & 0x3FF;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+2] = (u32_RB_val>>20) & 0x3FF;
			ReadRegister(FRC_TOP__kmc_top__regr_vhdtl_rgn00_ADDR + 12 * u32_i + 4, 0, 31, &u32_RB_val);
			pOutput->u10_mc_VHdtl_rb[8*u32_i+3] = u32_RB_val & 0x3FF;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+4] = (u32_RB_val>>10) & 0x3FF;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+5] = (u32_RB_val>>20) & 0x3FF;
			ReadRegister(FRC_TOP__kmc_top__regr_vhdtl_rgn00_ADDR + 12 * u32_i + 8, 0, 31, &u32_RB_val);
			pOutput->u10_mc_VHdtl_rb[8*u32_i+6] = u32_RB_val & 0x3FF;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+7] = (u32_RB_val>>10) & 0x3FF;
		}
		else
		{
			pOutput->u10_mc_VHdtl_rb[8*u32_i] = 0;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+1] = 0;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+2] = 0;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+3] = 0;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+4] = 0;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+5] = 0;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+6] = 0;
			pOutput->u10_mc_VHdtl_rb[8*u32_i+7] = 0;
		}
	}

	if (pParam->u1_me_ZMV_cnt_en == 1)
	{
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_zmv_cnt), &u32_RB_val);
		pOutput->u17_me_ZMV_cnt_rb = u32_RB_val;

		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_zmv_dtl), &u32_RB_val);		
		pOutput->u17_me_ZMV_dtl_cnt_rb = u32_RB_val & 0xFFFFF;		
	}
}


 
