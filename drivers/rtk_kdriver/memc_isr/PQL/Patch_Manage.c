#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"
#include "memc_isr/PQL/Patch_Manage.h"

VOID  patch_BluceMic_detect(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 u32_RB_val = 0;
	UBYTE i = 0, u8_sad_match_cnt = 0, u8_tc_match_cnt = 0, u8_dtl_match_cnt = 0, u8_apl_match_cnt = 0;
		
	for(i = 0; i < 32; i++)
	{
		// region sad match
		if(s_pContext->_output_read_comreg.u25_me_rSAD_rb[i] < 0x7000) 
		{
			u8_sad_match_cnt++;
		}
		if(u8_sad_match_cnt >= 26)
		{
			pOutput->u1_sad_matched = 1;
		}
		else
		{
			pOutput->u1_sad_matched = 0;
		}
		// region tc match		
		if(s_pContext->_output_read_comreg.u22_me_rTC_rb[i] < 0x1C00)
		{
			u8_tc_match_cnt++;
		}
		if(u8_tc_match_cnt >= 26)
		{
			pOutput->u1_tc_matched = 1;
		}
		else
		{
			pOutput->u1_tc_matched = 0;
		}
		// region detail match
		if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[i] < 0x13000)
		{
			u8_dtl_match_cnt++;
		}
		if(u8_dtl_match_cnt >= 28)
		{
			pOutput->u1_dtl_matched = 1;
		}
		else
		{
			pOutput->u1_dtl_matched = 0;
		}	
		// region apl match
		if((s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i] > 0xc000) &&
		   (s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i] < 0x30000) &&
		   (s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i] > 0xc000) &&
		   (s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i] < 0x30000)
		  )
		{
			u8_apl_match_cnt++;
		}
		if(u8_apl_match_cnt >= 30)
		{
			pOutput->u1_apl_matched = 1;
		}
		else
		{
			pOutput->u1_apl_matched = 0;
		}		
	}
	
	if((s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP] == 0) &&
		(s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_BOT] == 2159) &&
		(s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_LFT] == 0) &&
		(s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_RHT] == 3839) &&	// no rim
		(pOutput->u1_sad_matched && pOutput->u1_tc_matched && pOutput->u1_dtl_matched && pOutput->u1_apl_matched) &&
		(s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb >= 0) &&
		(s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb < 0x10) &&
		(s_pContext->_output_read_comreg.u25_me_aDTL_rb > 0xF0000) &&
		(s_pContext->_output_read_comreg.u25_me_aDTL_rb < 0x190000) &&
		(s_pContext->_output_read_comreg.u26_me_aAPLi_rb > 0x390000) &&
		(s_pContext->_output_read_comreg.u26_me_aAPLi_rb < 0x450000) &&
		(s_pContext->_output_read_comreg.u26_me_aAPLp_rb > 0x390000) &&
		(s_pContext->_output_read_comreg.u26_me_aAPLp_rb < 0x450000)
	   )		
	{
		pOutput->u1_BluceMic_Detected = 1;
	}
	else
	{
		pOutput->u1_BluceMic_Detected = 0;
	}
}

VOID  patch_BluceMic_action(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
	if(pParam->u1_BluceMic_En == 1)
	{
		if(pOutput->u1_BluceMic_Detected == 1)
		{
	        WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_lfsr_mask0_x_ADDR, 0, 31, 0xFFFFFFFF);
	        WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_lfsr_mask0_x_ADDR, 0, 31, 0xFFFFFFFF);
		}
		else
		{
	        WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_lfsr_mask0_x_ADDR, 0, 31, 0x11131111);
	        WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_lfsr_mask0_x_ADDR, 0, 31, 0x11111111);
		}
	}
}

VOID  patch_casino_action(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
#if 1/*need resolve:compiler error*/
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	if (pParam->u1_patch_casino_en == 1){
		if (s_pContext->_output_me_sceneAnalysis.u1_casino_RP_detect_true == 1)
		{
			WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_gmvd_cost_limt_ADDR, 0, 12, 0x20);
			WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_gmvd_cost_limt_ADDR, 0, 12, 0x20);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_gmvd_ucf_y1_ADDR, 16, 23, 0x10);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_gmvd_ucf_slope1_ADDR, 8, 18, 0x7F9);
		}
		else // if (pOutput->u1_patchCasio_true == 0 && pOutput->u1_patchCasio_preTrue == 1)
		{
			WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_gmvd_cost_limt_ADDR, 0, 12, 0x6);
			WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_gmvd_cost_limt_ADDR, 0, 12, 0x6);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_gmvd_ucf_y1_ADDR, 16, 23, 0xC);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_gmvd_ucf_slope1_ADDR, 8, 18, 0x7FB);
		}
	}
#endif
}

VOID  patch_HighFreqPlayerOSD_detect(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{

	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT16 u16_mc_Hdtl_rb         = s_pContext->_output_read_comreg.u16_mc_Hdtl_cnt;
	UINT16 u16_mc_Vdtl_rb         = s_pContext->_output_read_comreg.u16_mc_Vdtl_cnt;
	static UBYTE u8_vipStill_cnt = 0;
	static UBYTE u8_mcdtl_cnt = 0;
	UBYTE u1_mc_rdtl_true = 0, mc_rdtl_cnt = 0, u1_me_sad_true = 0, me_sad_cnt = 0, i=0;

	for(i=0; i<32; i++)
	{
		if(s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[i]<0x3)
			mc_rdtl_cnt++;
		
		if(s_pContext->_output_read_comreg.u25_me_rSAD_rb[i]<0x30)
			me_sad_cnt++;
			
	}

	if(mc_rdtl_cnt>20)
		u1_mc_rdtl_true = 1;

	if(me_sad_cnt>10)
		u1_me_sad_true = 1;
		
	if(u1_me_sad_true && u1_mc_rdtl_true && (s_pContext->_external_info.u1_VIP_Still || u8_vipStill_cnt>0) && u16_mc_Hdtl_rb>0x1c00 && u16_mc_Vdtl_rb>0x500)
	{
		pOutput->u1_patch_highFreq_zmv_true = 1;

		if(s_pContext->_external_info.u1_VIP_Still)
			u8_vipStill_cnt = 20;
		else
			u8_vipStill_cnt--;
	}
	else
	{
		pOutput->u1_patch_highFreq_zmv_true = 0;
		u8_vipStill_cnt = 0;
	}
	
	if(u1_me_sad_true && u16_mc_Hdtl_rb>0x4000 && u16_mc_Vdtl_rb>0x2000)
	{
		pOutput->u1_patch_highFreq_rp_true = 1;
		u8_mcdtl_cnt = 20;
	}
	else if(u1_me_sad_true && u8_mcdtl_cnt>0)
	{
		u8_mcdtl_cnt--;
	}
	else
	{
		pOutput->u1_patch_highFreq_rp_true = 0;
		u8_mcdtl_cnt = 0;
	}

	
#if 0
	UINT32 ip30=0, ip29=0, ip28=0;
	ReadRegister(FRC_TOP__kmc_top__dummy24_ADDR,30,30,&ip30);
	ReadRegister(FRC_TOP__kmc_top__dummy24_ADDR,29,29,&ip29);
	ReadRegister(FRC_TOP__kmc_top__dummy24_ADDR,28,28,&ip28);

	if(ip30)
	printk("%d %d..%d %d.. %d %d.. %x %x\n", pOutput->u1_patch_highFreq_zmv_true, pOutput->u1_patch_highFreq_rp_true,
	mc_rdtl_cnt, me_sad_cnt, 
	s_pContext->_external_info.u1_VIP_Still, u8_vipStill_cnt, 
	u16_mc_Hdtl_rb, u16_mc_Vdtl_rb);

	if(ip29)
	printk("sad %d %d.. %x %x %x %x %x %x %x %x .. %x %x %x %x %x %x %x %x.. %x %x %x %x %x %x %x %x..%x %x %x %x %x %x %x %x \n", mc_rdtl_cnt, me_sad_cnt, 
	s_pContext->_output_read_comreg.u25_me_rSAD_rb[0], s_pContext->_output_read_comreg.u25_me_rSAD_rb[1], s_pContext->_output_read_comreg.u25_me_rSAD_rb[2], s_pContext->_output_read_comreg.u25_me_rSAD_rb[3], s_pContext->_output_read_comreg.u25_me_rSAD_rb[4], s_pContext->_output_read_comreg.u25_me_rSAD_rb[5], s_pContext->_output_read_comreg.u25_me_rSAD_rb[6], s_pContext->_output_read_comreg.u25_me_rSAD_rb[7], 
	s_pContext->_output_read_comreg.u25_me_rSAD_rb[8], s_pContext->_output_read_comreg.u25_me_rSAD_rb[9], s_pContext->_output_read_comreg.u25_me_rSAD_rb[10], s_pContext->_output_read_comreg.u25_me_rSAD_rb[11], s_pContext->_output_read_comreg.u25_me_rSAD_rb[12], s_pContext->_output_read_comreg.u25_me_rSAD_rb[13], s_pContext->_output_read_comreg.u25_me_rSAD_rb[14], s_pContext->_output_read_comreg.u25_me_rSAD_rb[15], 
	s_pContext->_output_read_comreg.u25_me_rSAD_rb[16], s_pContext->_output_read_comreg.u25_me_rSAD_rb[17], s_pContext->_output_read_comreg.u25_me_rSAD_rb[18], s_pContext->_output_read_comreg.u25_me_rSAD_rb[19], s_pContext->_output_read_comreg.u25_me_rSAD_rb[20], s_pContext->_output_read_comreg.u25_me_rSAD_rb[21], s_pContext->_output_read_comreg.u25_me_rSAD_rb[22], s_pContext->_output_read_comreg.u25_me_rSAD_rb[23], 
	s_pContext->_output_read_comreg.u25_me_rSAD_rb[24], s_pContext->_output_read_comreg.u25_me_rSAD_rb[25], s_pContext->_output_read_comreg.u25_me_rSAD_rb[26], s_pContext->_output_read_comreg.u25_me_rSAD_rb[27], s_pContext->_output_read_comreg.u25_me_rSAD_rb[28], s_pContext->_output_read_comreg.u25_me_rSAD_rb[29], s_pContext->_output_read_comreg.u25_me_rSAD_rb[30], s_pContext->_output_read_comreg.u25_me_rSAD_rb[31]);

	if(ip28)
	printk("dtl %d %d.. %x %x %x %x %x %x %x %x .. %x %x %x %x %x %x %x %x.. %x %x %x %x %x %x %x %x..%x %x %x %x %x %x %x %x \n", mc_rdtl_cnt, me_sad_cnt, 
	s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[0], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[1], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[2], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[3], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[4], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[5], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[6], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[7], 
	s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[8], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[9], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[10], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[11], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[12], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[13], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[14], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[15], 
	s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[16], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[17], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[18], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[19], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[20], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[21], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[22], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[23], 
	s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[24], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[25], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[26], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[27], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[28], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[29], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[30], s_pContext->_output_read_comreg.u10_mc_VHdtl_rb[31]);
#endif

}

VOID  patch_golfBall_detect(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
#if 0/*need resolve:compiler error*/

	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT16 u16_mc_Hdtl_rb         = s_pContext->_output_read_comreg.u16_mc_Hdtl_cnt;
	UINT16 u16_mc_Vdtl_rb         = s_pContext->_output_read_comreg.u16_mc_Vdtl_cnt;

	UBYTE  u1_Vdtl_true           = u16_mc_Vdtl_rb >= pParam->u16_golfBall_bHsV_Vdtl_th0 && u16_mc_Vdtl_rb <= pParam->u16_golfBall_bHsV_Vdtl_th1;
	UBYTE  u1_Hdtl_true           = u16_mc_Hdtl_rb >= pParam->u16_golfBall_bHsV_Hdtl_th0 && u16_mc_Hdtl_rb <= pParam->u16_golfBall_bHsV_Hdtl_th1;

	u1_Vdtl_true                       = u1_Vdtl_true || pParam->u1_golfBall_Vdtl_byp;
	u1_Hdtl_true                       = u1_Hdtl_true || pParam->u1_golfBall_Hdtl_byp;
	pOutput->u1_golfBall_HVdtl_FB_true = u1_Vdtl_true && u1_Hdtl_true;
#endif
}
VOID  patch_golfBall_action(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
#if 0/*need resolve:compiler error*/

	if(pOutput->u1_golfBall_HVdtl_FB_true == 1 && pOutput->u1_golfBall_HVdtl_FB_preTrue == 0)
	{
		UINT32 u32_rb_data;

		ReadRegister(FRC_TOP__KME_ME_TOP__reg_metop_ss_ip_obme_mode_ADDR, 8, 19, &u32_rb_data);
		pOutput->u12_golfBall_bk_obmeMode = u32_rb_data;

		ReadRegister(FRC_TOP__MC2__reg_mc_var_fir_y_min_ADDR, 12, 19, &u32_rb_data);
		pOutput->u8_golfBall_bk_varLPF_y  = u32_rb_data;


		WriteRegister(FRC_TOP__KME_ME_TOP__reg_metop_ss_ip_obme_mode_ADDR, 8, 19, 0);
		WriteRegister(FRC_TOP__MC2__reg_mc_var_fir_y_min_ADDR, 12, 19,            0);

		pOutput->u1_golfBall_HVdtl_FB_preTrue = 1;
	}
	else if(pOutput->u1_golfBall_HVdtl_FB_true == 0 && pOutput->u1_golfBall_HVdtl_FB_preTrue == 1)
	{
		WriteRegister(FRC_TOP__KME_ME_TOP__reg_metop_ss_ip_obme_mode_ADDR, 8, 19, pOutput->u12_golfBall_bk_obmeMode);
		WriteRegister(FRC_TOP__MC2__reg_mc_var_fir_y_min_ADDR, 12, 19,            pOutput->u8_golfBall_bk_varLPF_y);

		pOutput->u1_golfBall_HVdtl_FB_preTrue = 0;
	}
#endif

}


VOID  patch_BallJump_detect(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
#if 0
	//const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 u32_background_tc = 0;
	UINT32 u32_background_sad = 0;

	UINT32 u32_foreground_sad = 0;
	UINT32 u32_foreground_tc[4] = {0};
	UINT32 u32_foreground_tc_diff[4] = {0};

	UINT32 u32_background_tc_th = 0xFF;
	UINT32 u32_background_sad_th = 0xF00;
	UINT32 u32_foreground_tc_th = 0x4F00;
	UINT32 u32_foreground_sad_th_h = 0x18000;
	UINT32 u32_foreground_sad_th_l = 0x3000;

	UBYTE  u1_tc_diff_true = 0;
	UBYTE  u1_apl_true = 1;

 	UINT32 u32_RB_val = 0;
// 	UINT32 u32_RB_param;
#if 0/*need resolve:compiler error*/

 	ReadRegister(FRC_TOP__PQL_0__pql_patch_dummy_F4_ADDR, 0, 31, &u32_RB_val);
#endif

// 	ReadRegister(FRC_TOP__PQL_0__pql_patch_dummy_F8_ADDR, 0, 31, &u32_RB_param);
// 	u32_background_sad_th = u32_RB_param & 0xFFFFFFFF;
// 	ReadRegister(FRC_TOP__PQL_0__pql_patch_dummy_FC_ADDR, 0, 31, &u32_RB_param);
// 	u32_foreground_tc_th = (u32_RB_param>>8) & 0xFFFFFF;
// 	ReadRegister(FRC_TOP__PQL_0__pql_patch_dummy_D0_ADDR, 0, 31, &u32_RB_param);
// 	u32_foreground_sad_th_h  = u32_RB_param & 0xFFFFFFFF;
// 	ReadRegister(FRC_TOP__PQL_0__pql_patch_dummy_D4_ADDR, 0, 31, &u32_RB_param);
// 	u32_foreground_sad_th_l  = u32_RB_param & 0xFFFFFFFF;


	UBYTE  i = 0;
#if 0/*need resolve:compiler error*/
	for (i = 0; i < 32; i ++)
	{
		UINT32 u23_rgnSad_rb = s_pContext->_output_read_comreg.u23_subSAD[i];
		UINT32 u23_rgnTC_rb = s_pContext->_output_read_comreg.u23_subTC[i];

		if (((i%8)>=2) && ((i%8)<=5))
		{
			u32_foreground_sad += u23_rgnSad_rb;
			u32_foreground_tc[i/8] += u23_rgnTC_rb;
		}
		else
		{
			if (((i%8)>5) || (i<16))
			{
				u32_background_sad += u23_rgnSad_rb;
			}

			u32_background_tc  += u23_rgnTC_rb;
		}
	}

#endif
	for (i = 0; i < 4; i ++)
	{
		u32_foreground_tc_diff[i] = _ABS_DIFF_(u32_foreground_tc[i], pOutput->u32_foreground_tc_pre[i]);
		pOutput->u32_foreground_tc_pre[i] = u32_foreground_tc[i];

		if (u32_foreground_tc_diff[i] > u32_foreground_tc_th)
		{
			u1_tc_diff_true = 1;
		}
	}
#if 0/*need resolve:compiler error*/

	for (i = 0; i < 6; i ++)
	{
		if ((s_pContext->_output_read_comreg.u8_lbme_apl_rb[26+i] < 140) || (s_pContext->_output_read_comreg.u8_lbme_apl_rb[24+i] > 160))
		{
			u1_apl_true = 0;
		}
	}
#endif
	if (((u32_background_tc < u32_background_tc_th) || ((u32_RB_val>>25)&0x1))
		&& ((u32_background_sad < u32_background_sad_th)  || ((u32_RB_val>>26)&0x1))
		&& ((u32_foreground_sad > u32_foreground_sad_th_l)  || ((u32_RB_val>>27)&0x1))
		&& ((u32_foreground_sad < u32_foreground_sad_th_h) || ((u32_RB_val>>28)&0x1))
		&& ((u1_tc_diff_true == 1) || ((u32_RB_val>>29)&0x1))
		&& ((u1_apl_true == 1) || ((u32_RB_val>>30)&0x1)))
	{
		pOutput->u1_BallJump_true = 1;
		pOutput->s8_BallJump_holdCnt = 28;
	}
	else
	{
		pOutput->u1_BallJump_true = 0;
		pOutput->s8_BallJump_holdCnt = (pOutput->s8_BallJump_holdCnt <= 0) ? 0 : (pOutput->s8_BallJump_holdCnt-1);
	}
#else
	pOutput->u1_BallJump_true = 0;
	pOutput->s8_BallJump_holdCnt = 0;
#endif
}
VOID  patch_BallJump_action(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
	if (pOutput->s8_BallJump_holdCnt > 0)
	{
		pOutput->u1_dh_close = 1;
	}
	else
	{
		pOutput->u1_dh_close = 0;
	}
}

VOID  patch_Soccer_detect(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{

}
VOID  patch_Soccer_action(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	if(pParam->u1_patch_soccer_en == 0)
		return;

	if (pParam->u1_patch_soccer_en && s_pContext->_external_info.u8_Soccer_holdfrm > 0)
	{
		WriteRegister(FRC_TOP__IPPRE__reg_kmc_blend_y_alpha_ADDR, 4, 11, 0x90);
		WriteRegister(FRC_TOP__IPPRE__reg_kmc_blend_uv_alpha_ADDR, 16, 23, 0x80);
		
		WriteRegister(FRC_TOP__MC__reg_mc_bld_mvd_y_min_ADDR, 16, 23, 0xFF);
		WriteRegister(FRC_TOP__MC__reg_mc_bld_mvd_y_max_ADDR, 24, 31, 0xFF);
		
		WriteRegister(FRC_TOP__KME_DEHALO2__reg_dh_pfv_check_dif_gain_i_ADDR, 1, 7, 0x0);
		WriteRegister(FRC_TOP__KME_DEHALO2__reg_dh_pfv_check_dif_gain_p_ADDR, 8, 14, 0x0);
	}
	else
	{
		WriteRegister(FRC_TOP__IPPRE__reg_kmc_blend_y_alpha_ADDR, 4, 11, 0xFF);
		WriteRegister(FRC_TOP__IPPRE__reg_kmc_blend_uv_alpha_ADDR, 16, 23, 0x20);
		
		WriteRegister(FRC_TOP__MC__reg_mc_bld_mvd_y_min_ADDR, 16, 23, 0xC0);
		WriteRegister(FRC_TOP__MC__reg_mc_bld_mvd_y_max_ADDR, 24, 31, 0xFF);
		
		WriteRegister(FRC_TOP__KME_DEHALO2__reg_dh_pfv_check_dif_gain_i_ADDR, 1, 7, 0x10);
		WriteRegister(FRC_TOP__KME_DEHALO2__reg_dh_pfv_check_dif_gain_p_ADDR, 8, 14, 0xC);
	}
}
/////////////////////////////////////////////////////////////////////////

VOID PatchManage_Init(_OUTPUT_PATCH_M *pOutput)
{
	pOutput->u1_patchArm_preTrue       = 0;
	pOutput->u8_arm_hcnt               = 0;
	pOutput->u8_arm_detCnt             = 0;

	pOutput->u1_Print_En               = 0;
	pOutput->s32_PrintCnt              = 0;

	pOutput->u1_CoringThr_State        = 0;

	pOutput->u1_golfBall_HVdtl_FB_preTrue = 0;
	pOutput->u1_golfBall_HVdtl_FB_true    = 0;

	pOutput->u1_BallJump_true          = 0;
	pOutput->s8_BallJump_holdCnt       = 0;
	pOutput->u32_foreground_tc_pre[0]  = 0;
	pOutput->u32_foreground_tc_pre[1]  = 0;
	pOutput->u32_foreground_tc_pre[2]  = 0;
	pOutput->u32_foreground_tc_pre[3]  = 0;
	pOutput->u1_dh_close               = 0;

	pOutput->u1_sad_matched = 0;
	pOutput->u1_tc_matched = 0;	
	pOutput->u1_dtl_matched = 0;
	pOutput->u1_apl_matched = 0;
	pOutput->u1_BluceMic_Detected = 0;	
}

VOID Patch_CoringThr(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
#if 0/*need resolve:compiler error*/

   UINT32 u32GlbDtl;
   ReadRegister(KIWI_REG(FRC_TOP__KME_ME_TOP5__regr_metop_rdbk_dtl_all),&u32GlbDtl);

   if(pOutput->u1_CoringThr_State == 1 && u32GlbDtl < 0x500000)
   	{
   	    pOutput->u1_CoringThr_State= 0;
   	}

    if(pOutput->u1_CoringThr_State == 0 && u32GlbDtl > 0x550000)
    {
	    pOutput->u1_CoringThr_State= 1;
    }


    if(pOutput->u1_CoringThr_State)
    {
        WriteRegister(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_sad_th_curve_y1),pParam->u8_patchCoring_sad1);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_sad_th_curve_y2),0x4);
    }else
    {
        WriteRegister(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_sad_th_curve_y1),pParam->u8_patchCoring_sad0);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_sad_th_curve_y2),0x2);
    }
#endif
}

VOID PatchManage_Proc(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
	Patch_detect(pParam, pOutput);
	Patch_Action(pParam, pOutput);

	Patch_CoringThr(pParam, pOutput);

	if (pOutput->u1_Print_En == 1 && pOutput->s32_PrintCnt < 500)
	{
		pOutput->s32_PrintCnt++;
	}

	if (pOutput->s32_PrintCnt >= 500)
    {
		if (pParam->u1_Print_en && pOutput->u1_Print_En == 0)
		{
			pOutput->s32_PrintCnt = 0;
			pOutput->u1_Print_En = 1;
		}
	}
	pOutput->u1_Print_En  = 0;
	pOutput->s32_PrintCnt = 100000;
}

VOID Patch_detect(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
	// golf ball
	if(pParam->u1_patch_golfBall_en == 1)
	{
		patch_golfBall_detect(pParam, pOutput);
	}
	else
	{
		pOutput->u1_golfBall_HVdtl_FB_true = 0;
	}

	if(pParam->u1_patch_ballJump_en == 1)
	{
		patch_BallJump_detect(pParam, pOutput);
	}
	else
	{
		pOutput->s8_BallJump_holdCnt = 0;
	}

	if(pParam->u1_BluceMic_En == 1)
	{
		patch_BluceMic_detect(pParam, pOutput);
	}
	else
	{
		pOutput->u1_BluceMic_Detected = 0;
	}

	if(pParam->u1_patch_highFreq_en == 1)
	{
		patch_HighFreqPlayerOSD_detect(pParam, pOutput);
	}
	else
	{
		pOutput->u1_patch_highFreq_zmv_true = 0;
		pOutput->u1_patch_highFreq_rp_true = 0;
	}
}
VOID Patch_Action(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput)
{
	// const _PQLCONTEXT *s_pContext = GetPQLContext();

	patch_casino_action(pParam, pOutput);     // casino action

	patch_golfBall_action(pParam, pOutput);   // golf ball

	patch_BallJump_action(pParam, pOutput);   // hisense ball jump

	patch_BluceMic_action(pParam, pOutput);

	patch_Soccer_action(pParam, pOutput);     // soccer
	//// double scan action
	{
		pOutput->u1_dbScan_en = pParam->u1_dbScan_en;
	}



}


