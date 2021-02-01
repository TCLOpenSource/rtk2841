#include "memc_isr/PQL/PQLPlatformDefs.h"
//#include "stdio.h"
//#include "stdlib.h"
#include "memc_isr/PQL/PQLContext.h"
//#include "MESceneAnalysis.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"
#ifndef rtd_inl
#define rtd_inl(offset)		(*(volatile unsigned long *)(offset))
#endif


//////////////////////////////////////////////////////////////////////////

#define FRAME_CHANGE_CNT	5

//////////////////////////////////////////////////////////////////////////

VOID Me_sceneAnalysis_Init(_OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{	
	/* SIS MEMC Initial here */
	MEMC_MiddleWare_StatusInit(pOutput);

	pOutput->u1_RP_detect_true = 0;

	pOutput->s10_me_GMV_1st_vy_rb_iir = 0;
	pOutput->u6_me_GMV_1st_cnt_rb_iir = 0;
	pOutput->u1_chaos_true = 0;
    pOutput->u8_chaos_apply = 0;
	pOutput->u8_big_apldiff_hold_cnt = 0;
	pOutput->u32_glb_sad_pre = 0;
	pOutput->u32_big_apldiff_saddiff_th = 0;
	pOutput->u8_big_apldiff_sc_hold_cnt = 1;
	pOutput->u32_big_apldiff_sad_pre = 0;
}

VOID Me_sceneAnalysis_Proc_OutputIntp(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput, SINT32 iSliceIdx)
{
	MEMC_MiddleWare_StatusUpdate(pParam, pOutput, iSliceIdx);
}



/* SIS MEMC function implement here */
VOID MEMC_MiddleWare_StatusInit(_OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{
	pOutput->SIS_MEMC.Frame_Couter = 0;

	PQL_ReadHDF(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_lfsr_mask2_x_ADDR, 16, 19, &pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_lfsr_mask2_x);
	PQL_ReadHDF(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update1_en_ADDR, 12, 12, &pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_update1_en);
	PQL_ReadHDF(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update2_en_ADDR, 13, 13, &pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_update2_en);
	PQL_ReadHDF(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update3_en_ADDR, 14, 14, &pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_update3_en);
	PQL_ReadHDF(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update1_en_ADDR, 11, 11, &pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_update1_en);
	PQL_ReadHDF(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update2_en_ADDR, 12, 12, &pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_update2_en);
	PQL_ReadHDF(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update3_en_ADDR, 13, 13, &pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_update3_en);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd0_ADDR, 16, 23, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_ip_cddpnt_rnd0);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd1_ADDR, 24, 31, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_ip_cddpnt_rnd1);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd2_ADDR, 0, 7, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_ip_cddpnt_rnd2);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd0_ADDR, 16, 23, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_pi_cddpnt_rnd0);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd1_ADDR, 24, 31, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_pi_cddpnt_rnd1);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd2_ADDR, 0, 7, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_pi_cddpnt_rnd2);	
	PQL_ReadHDF(FRC_TOP__KME_TOP__reg_frame_meander_enable_ADDR, 29, 29, &pOutput->SIS_MEMC.MEMC_STATUS.reg_frame_meander_enable);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP2__reg_me1_gmv_sel_ADDR, 0, 0, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_gmv_sel);

	
	PQL_ReadHDF(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, &pOutput->SIS_MEMC.MEMC_STATUS.reg_mc_scene_change_fb);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th_ADDR, 0, 30, &pOutput->SIS_MEMC.MEMC_STATUS.reg_me1_sc_saddiff_th);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th_ADDR, 0, 30, &pOutput->u32_new_saddiff_th);
	PQL_ReadHDF(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th_ADDR, 0, 30, &pOutput->u32_new_saddiff_th_pre);

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x1), &pOutput->SIS_MEMC.MEMC_STATUS.u8_dynME_acdc_bld_x_act[0]);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x2), &pOutput->SIS_MEMC.MEMC_STATUS.u8_dynME_acdc_bld_x_act[1]);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x3), &pOutput->SIS_MEMC.MEMC_STATUS.u8_dynME_acdc_bld_x_act[2]);	
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y1), &pOutput->SIS_MEMC.MEMC_STATUS.u6_dynME_acdc_bld_y_act[0]);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y2), &pOutput->SIS_MEMC.MEMC_STATUS.u6_dynME_acdc_bld_y_act[1]);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y3), &pOutput->SIS_MEMC.MEMC_STATUS.u6_dynME_acdc_bld_y_act[2]);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_slope1), &pOutput->SIS_MEMC.MEMC_STATUS.s9_dynME_acdc_bld_s_act[0]);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_slope2), &pOutput->SIS_MEMC.MEMC_STATUS.s9_dynME_acdc_bld_s_act[1]);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_ac_pix_sad_limt), &pOutput->SIS_MEMC.MEMC_STATUS.u8_dynME_ac_pix_sad_limt_act);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_ac_pix_sad_limt), &pOutput->SIS_MEMC.MEMC_STATUS.u8_dynME_ac_pix_sad_limt_act);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_mm_psad_norm_shft), &pOutput->SIS_MEMC.MEMC_STATUS.u4_acdc_bld_psad_shift_act);

/*
	UINT32 u32_rb_data;

	pOutput->SIS_MEMC.MEMC_WIDTH = 3840;
	pOutput->SIS_MEMC.MEMC_HEIGHT = 2160;

	pOutput->SIS_MEMC.MEMC_BLOCK_X = 240;
	pOutput->SIS_MEMC.MEMC_BLOCK_Y = 135;

	pOutput->SIS_MEMC.Frame_Couter = 0;

	// SIS_MEMC initial
	pOutput->SIS_MEMC.MEMC_PAN_STATUS.wrt_idx = 0;

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP1__reg_metop_smallobj_en),&pOutput->SIS_MEMC.MEMC_PAN_STATUS.reg_metop_smallobj_en);

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_1st_lfsr_mask_x),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ph_1st_lfsr_mask_x);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_1st_lfsr_mask_y),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ph_1st_lfsr_mask_y);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_2nd_lfsr_mask_x),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ph_2nd_lfsr_mask_x);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_2nd_lfsr_mask_y),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ph_2nd_lfsr_mask_y);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en),&pOutput->SIS_MEMC.MEMC_STATUS.reg_mc_var_lpf_en);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__MC2__reg_mc_var_mvd_x_th),&pOutput->SIS_MEMC.MEMC_STATUS.reg_mc_var_lpf_mvd_x_th);

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_lfsr_mask_x),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_lfsr_mask_x);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_lfsr_mask_y),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_lfsr_mask_y);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_2nd_lfsr_mask_x),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_2nd_lfsr_mask_x);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_2nd_lfsr_mask_y),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_2nd_lfsr_mask_y);

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_lfsr_mask_x),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_lfsr_mask_x);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_lfsr_mask_y),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_lfsr_mask_y);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_2nd_lfsr_mask_x),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_2nd_lfsr_mask_x);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_2nd_lfsr_mask_y),&pOutput->SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_2nd_lfsr_mask_y);

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ss_ip_update0_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ip_update0_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ss_ip_update1_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ip_update1_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ss_pi_update0_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_pi_update0_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ss_pi_update1_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_pi_update1_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ss_ph_update0_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ph_update0_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ss_ph_update1_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ph_update1_penalty);

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ds_ip_update0_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ip_update0_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ds_ip_update1_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ip_update1_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ds_pi_update0_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_pi_update0_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ds_pi_update1_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_pi_update1_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ds_ph_update0_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ph_update0_penalty);
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_ME_TOP__reg_metop_ds_ph_update1_penalty),&pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ph_update1_penalty);

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_cand1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ip_1st_cand1_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_cand5_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ip_1st_cand5_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ip_1st_update1_offsetx = u32_rb_data;

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_cand1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_pi_1st_cand1_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_cand5_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_pi_1st_cand5_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_pi_1st_update1_offsetx = u32_rb_data;

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_1st_cand1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_1st_cand1_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_1st_cand2_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_1st_cand2_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_1st_cand2_offsety), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_1st_cand2_offsety = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_1st_cand5_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_1st_cand5_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_1st_update1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_1st_update1_offsetx = u32_rb_data;

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_2nd_cand1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ip_2nd_cand1_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_2nd_cand5_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ip_2nd_cand5_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_2nd_update1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ip_2nd_update1_offsetx = u32_rb_data;

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_2nd_cand1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_pi_2nd_cand1_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_2nd_cand5_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_pi_2nd_cand5_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_2nd_update1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_pi_2nd_update1_offsetx = u32_rb_data;

	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_2nd_cand1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_2nd_cand1_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_2nd_cand2_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_2nd_cand2_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_2nd_cand2_offsety), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_2nd_cand2_offsety = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_2nd_cand5_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_2nd_cand5_offsetx = u32_rb_data;
	PQL_ReadHDF(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ph_2nd_update1_offsetx), &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.u3_ph_2nd_update1_offsetx = u32_rb_data;

	PQL_ReadHDF(FRC_TOP__KME_ME_TOP__reg_metop_sad_th_mode_sel_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_sad_th_mode_sel = u32_rb_data&0x3;

	PQL_ReadHDF(FRC_TOP__KME_ME_TOP__reg_metop_ss_ip_penalty_z_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ip_penalty_z = u32_rb_data&0xff;
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ip_penalty_g = (u32_rb_data>>8)&0xff;
	PQL_ReadHDF(FRC_TOP__KME_ME_TOP__reg_metop_ss_pi_penalty_z_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_pi_penalty_z = u32_rb_data&0xff;
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_pi_penalty_g = (u32_rb_data>>8)&0xff;
	PQL_ReadHDF(FRC_TOP__KME_ME_TOP__reg_metop_ss_ph_penalty_z_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ph_penalty_z = u32_rb_data&0xff;
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ss_ph_penalty_g = (u32_rb_data>>8)&0xff;

	PQL_ReadHDF(FRC_TOP__KME_ME_TOP__reg_metop_ds_ip_penalty_z_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ip_penalty_z = u32_rb_data&0xff;
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ip_penalty_g = (u32_rb_data>>8)&0xff;
	PQL_ReadHDF(FRC_TOP__KME_ME_TOP__reg_metop_ds_pi_penalty_z_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_pi_penalty_z = u32_rb_data&0xff;
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_pi_penalty_g = (u32_rb_data>>8)&0xff;
	PQL_ReadHDF(FRC_TOP__KME_ME_TOP__reg_metop_ds_ph_penalty_z_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ph_penalty_z = u32_rb_data&0xff;
	pOutput->SIS_MEMC.MEMC_STATUS.reg_metop_ds_ph_penalty_g = (u32_rb_data>>8)&0xff;

	PQL_ReadHDF(FRC_TOP__DEHALO__reg_dh_empty_proc_en_ADDR, 0, 31, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_dh_empty_proc_en = (u32_rb_data>>13)&0x1;

	PQL_ReadHDF(FRC_TOP__PQL_1__pql_fb_tc_iir_ADDR, 0, 7, &u32_rb_data);
	pOutput->SIS_MEMC.MEMC_STATUS.reg_pql_fb_tc_iir = (u32_rb_data)&0xff;
*/
}

VOID MEMC_MiddleWare_Reg_Status_Cad1(_OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{
	//register value get when candence is 1

	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE  u8_cadence_phId  = s_pContext->_output_filmDetectctrl.u8_phT_phase_Idx_out[_FILM_ALL];
	UBYTE  u8_cadence_Id    = s_pContext->_output_filmDetectctrl.u8_cur_cadence_out[_FILM_ALL];
	UBYTE  u1_cad_motionSeq    = cadence_seqFlag(frc_cadTable[u8_cadence_Id], cadence_prePhase(frc_cadTable[u8_cadence_Id],u8_cadence_phId, 1));

	UINT32 u32_RB_val;
	UBYTE u8_k;


	if(u1_cad_motionSeq==1)
	{
		pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all_pre = pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all;
		ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__regr_me1_statis_glb_dtl), &u32_RB_val);
		pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all = u32_RB_val&0x1ffffff;


		pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all_intervel5_pre = pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all_intervel5;
		pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all_intervel5 = pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all;
	

	

			//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 0, 3, pOutput->SIS_MEMC.MEMC_STATUS.u1_apl_inc);
			//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 4, 7, pOutput->SIS_MEMC.MEMC_STATUS.u1_apl_dec);

	}
}

VOID MEMC_MiddleWare_StatusUpdate(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput, SINT32 iSliceIdx)
{
	if (pOutput->SIS_MEMC.Frame_Couter > 65535)
		pOutput->SIS_MEMC.Frame_Couter = 0;
	else
		pOutput->SIS_MEMC.Frame_Couter++;

	if (iSliceIdx == 0)
	{
		
	}
	else if (iSliceIdx == 1)
	{
		
	}
	else if (iSliceIdx == 2)
	{
	}
	else if (iSliceIdx == 3)
	{
		MEMC_LightSwordDetect(pParam, pOutput);
	}
	else if (iSliceIdx == 4)
	{
		
		MEMC_RepeatPattern_detect(pParam, pOutput);
	}
	else
	{
		// don't use function put here
	}
	MEMC_Big_APLDiff_Detect(pParam, pOutput);
	MEMC_EPG_Protect(pParam, pOutput);
	MEMC_Simple_Scene_Detect(pParam, pOutput);
}

static UINT32 frm_cnt = 0;
VOID MEMC_RepeatPattern_detect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	static UBYTE u6_RP_frm_in_cnt = 0;
	static UBYTE u8_RP_frm_hold_cnt = 0;
	static UBYTE u8_RP_frm_hold_cnt_max = 0;
	UBYTE u1_det_true;
	UBYTE u1_basic_cond_true;

	UINT16 u16_mcDTL_thmin = 0x200;
	UINT16 u16_mcDTL_th0 = 0x400;
	UINT16 u16_mcDTL_th1 = 0x700;
	UINT16 u16_mcDTL_th2 = 0x900;
	UINT16 u16_mcDTL_th3 = 0x1000;
	
	UBYTE u8_GMV_th0 = 0xA;
	UBYTE u8_GMV_th1 =0xA;
	UBYTE u8_GMV_th2 = 0x1B;
	UBYTE u8_GMV_diff = 0x8;

	SINT16 s11_maxGMV_x = (s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb)>>2;
	SINT16 s11_secGMV_x = (s_pContext->_output_read_comreg.s11_me_GMV_2nd_vx_rb)>>2;

	SINT16 s10_maxGMV_y = (s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb)>>2;
	SINT16 s10_secGMV_y = (s_pContext->_output_read_comreg.s10_me_GMV_2nd_vy_rb)>>2;

	UINT16 u16_mcHdtl = s_pContext->_output_read_comreg.u16_mc_Hdtl_cnt;
	UINT16 u16_mcVdtl = s_pContext->_output_read_comreg.u16_mc_Vdtl_cnt;

//	UBYTE u1_gmv_true = 1, u1_mcDtl_move_true = 1, u1_tc_true = 1, u1_rim_true = 1, u1_dtl_all_cond_true = 1;
	UBYTE u1_gmv_true = 1, u1_mcDtl_move_true = 1, u1_tc_true = 1, u1_rDTL_move_true = 1, u1_dtl_all_cond_true = 1;
	UBYTE u2_mcDtl_HV;	// 0: dtl small, 1: v dtl, 2: h dtl

	UBYTE u1_maxGMV_x_t;
	UBYTE u1_secGMV_x_t;
	UBYTE u1_maxGMV_y_t;
	UBYTE u1_secGMV_y_t;
	UBYTE u1_GMV32_t;

	UBYTE u1_black_sc=0;		//black scene or sc occur
	static UBYTE u8_black_sc_cnt = 0;
	UBYTE u1_det_start=0;

	UBYTE u11_GMV_x_max;	// 0: similar, 1:y, 2:x
	UBYTE u10_GMV_y_max;	// 0: similar, 1:y, 2:x
	UBYTE u2_GMV_single_move;	// 0: similar, 1:y, 2:x

//	UINT16 u16_rimUp  = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP];
	//rmv, rdtl
	UINT32 u32_rDTL_th_1 = 70000, u32_rDTL_th_2 = 80000;
	UBYTE  u8_rmove_1_cnt= 0, u8_rmove_2_cnt= 0, u8_rmove_3_cnt= 0, u8_rmove_4_cnt = 0,  u8_rmove_cnt_th = 16;
	UBYTE u8_rDTL_RMV_mark[32] = {0}, u8_rmove_rgn1_cnt= 0, u8_rmove_rgn2_cnt= 0, u8_rmove_rgn3_cnt= 0, u8_rmove_rgn4_cnt = 0;
	static SCHAR u2_rDTL_RMV_cnt = 0;
	
//	UINT32 temp = 0;
//	ReadRegister(FRC_TOP__KME_TOP__reg_kme_dummy3_ADDR, 6, 31, &temp);  // 0xb809b03c

	int i;

	UBYTE u8_black_sc_cnt_th = 60;

	// gmv
	{
		u1_maxGMV_x_t = (_ABS_(s11_maxGMV_x) <= u8_GMV_th0)? 1 : 0;
		u1_maxGMV_y_t = (_ABS_(s10_maxGMV_y) <= u8_GMV_th0)? 1 : 0;

		u11_GMV_x_max = s11_maxGMV_x;
		u10_GMV_y_max = s10_maxGMV_y;

		if(s_pContext->_output_read_comreg.u6_me_GMV_2nd_cnt_rb>0)
		{
			u1_secGMV_x_t = (_ABS_(s11_secGMV_x) <= u8_GMV_th1)? 1 : 0;

			u11_GMV_x_max = _MAX_(u11_GMV_x_max, s11_secGMV_x);

			u1_secGMV_y_t = (_ABS_(s10_secGMV_y) <= u8_GMV_th1)? 1 : 0;

			u10_GMV_y_max = _MAX_(u10_GMV_y_max, s10_secGMV_y);
		}
		else
		{
			u1_secGMV_x_t = 1;

			u1_secGMV_y_t = 1;
		}

		u1_GMV32_t = 1;

		UBYTE  u8_bad_region_cnt = 0;
		for (i=0; i<32; i++)
		{
			if((_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i])>u8_GMV_th2)||(_ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i])>u8_GMV_th2))
			{
				u8_bad_region_cnt++;
				//u1_GMV32_t = 0;
			}

			// rDtl move th1
			if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[i]>u32_rDTL_th_1 && (s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i] || s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i])){
		#if 1
				if((s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]<=12 && s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>=0) && (s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]<=12 && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>=0))
					u8_rmove_1_cnt++;
				if((s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>=(-12) && s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]<=0) && (s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]<=12 && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>=0))
					u8_rmove_2_cnt++;
				if((s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>=(-12) && s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]<=0) && (s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>=(-12) && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]<=0))
					u8_rmove_3_cnt++;
				if((s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]<=12 && s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>=0) && (s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>=(-12) && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]<=0))
					u8_rmove_4_cnt++;
		#else
				if(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>=0 && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>=0)
					u8_rmove_1_cnt++;
				if(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]<=0 && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>=0)
					u8_rmove_2_cnt++;
				if(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]<=0 && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]<=0)
					u8_rmove_3_cnt++;
				if(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>=0 && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]<=0)
					u8_rmove_4_cnt++;
		#endif
			}
			
		#if 1
			// rDtl move th2
			if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[i]>u32_rDTL_th_2 && (s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]!=0 || s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]!=0)){
				if((s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]<=12 && s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[i]>=(-12)) && (s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]<=12 && s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[i]>=(-12)))
					u8_rDTL_RMV_mark[i] = 1;
			}
		#endif

		}
		if(u8_bad_region_cnt > 1)
			u1_GMV32_t = 0;
		
		u1_gmv_true = (u1_maxGMV_x_t && u1_maxGMV_y_t && u1_secGMV_x_t && u1_secGMV_y_t && u1_GMV32_t)? 1 : 0;
	}

	//gmv sigle move
	if(u11_GMV_x_max > u10_GMV_y_max + u8_GMV_diff)
	{
		u2_GMV_single_move = 2;
	}
	else if(u10_GMV_y_max>u11_GMV_x_max+u8_GMV_diff)
	{
		u2_GMV_single_move = 1;
	}
	else
	{
		u2_GMV_single_move = 0;
	}


	// mcDtl
	if (((u16_mcHdtl > u16_mcDTL_thmin) && (u16_mcHdtl > u16_mcVdtl * 30)) ||\
		((u16_mcHdtl > u16_mcDTL_th0) && (u16_mcHdtl > u16_mcVdtl * 15)) ||\
		((u16_mcHdtl > u16_mcDTL_th1) && (u16_mcHdtl > u16_mcVdtl * 10)) ||\
		((u16_mcHdtl > u16_mcDTL_th2) && (u16_mcHdtl > u16_mcVdtl * 8)) ||\
		((u16_mcHdtl > u16_mcDTL_th3) && (u16_mcHdtl > u16_mcVdtl * 4)))
	{
		u2_mcDtl_HV = 2;	//vertical lines
	}
	else if(((u16_mcVdtl > u16_mcDTL_thmin) && (u16_mcVdtl > u16_mcHdtl * 30))||\
		((u16_mcVdtl > u16_mcDTL_th0) && (u16_mcVdtl > u16_mcHdtl * 15))||\
		((u16_mcVdtl > u16_mcDTL_th1) && (u16_mcVdtl > u16_mcHdtl * 10)) ||\
		((u16_mcVdtl > u16_mcDTL_th2) && (u16_mcVdtl > u16_mcHdtl * 8)) ||\
		((u16_mcVdtl > u16_mcDTL_th3) && (u16_mcVdtl > u16_mcHdtl * 4)))

	{
		u2_mcDtl_HV = 1;	//horizantal lines
	}
	else
	{
		u2_mcDtl_HV = 0;
	}

	//mcDtl move
	if(((u2_mcDtl_HV==2)&&(u2_GMV_single_move !=1))||((u2_mcDtl_HV==1)&&(u2_GMV_single_move !=2)))
	{
		u1_mcDtl_move_true = 1;
	}
	else
	{
		u1_mcDtl_move_true = 0;
	}


#if 1
	//rgn rDtl move
	u8_rmove_rgn1_cnt = u8_rDTL_RMV_mark[0] + u8_rDTL_RMV_mark[1] + u8_rDTL_RMV_mark[8] + u8_rDTL_RMV_mark[9] + u8_rDTL_RMV_mark[16] + u8_rDTL_RMV_mark[17] + u8_rDTL_RMV_mark[24] + u8_rDTL_RMV_mark[25];
	u8_rmove_rgn2_cnt = u8_rDTL_RMV_mark[2] + u8_rDTL_RMV_mark[3] + u8_rDTL_RMV_mark[10] + u8_rDTL_RMV_mark[11] + u8_rDTL_RMV_mark[18] + u8_rDTL_RMV_mark[19] + u8_rDTL_RMV_mark[26] + u8_rDTL_RMV_mark[27];
	u8_rmove_rgn3_cnt = u8_rDTL_RMV_mark[4] + u8_rDTL_RMV_mark[5] + u8_rDTL_RMV_mark[12] + u8_rDTL_RMV_mark[13] + u8_rDTL_RMV_mark[20] + u8_rDTL_RMV_mark[21] + u8_rDTL_RMV_mark[28] + u8_rDTL_RMV_mark[29];
	u8_rmove_rgn4_cnt = u8_rDTL_RMV_mark[6] + u8_rDTL_RMV_mark[7] + u8_rDTL_RMV_mark[14] + u8_rDTL_RMV_mark[15] + u8_rDTL_RMV_mark[22] + u8_rDTL_RMV_mark[23] + u8_rDTL_RMV_mark[30] + u8_rDTL_RMV_mark[31];
	
	if((u8_rmove_1_cnt+u8_rmove_2_cnt)>u8_rmove_cnt_th || (u8_rmove_2_cnt+u8_rmove_3_cnt)>u8_rmove_cnt_th || (u8_rmove_3_cnt+u8_rmove_4_cnt)>u8_rmove_cnt_th || (u8_rmove_4_cnt+u8_rmove_1_cnt)>u8_rmove_cnt_th){
		u2_rDTL_RMV_cnt++;
	}
	else if(u8_rmove_rgn1_cnt>1 || u8_rmove_rgn2_cnt>1 || u8_rmove_rgn3_cnt>1 || u8_rmove_rgn4_cnt>1){
		u2_rDTL_RMV_cnt++;
	}
	else{
		u2_rDTL_RMV_cnt--;
	}

	if(u2_rDTL_RMV_cnt>5) u2_rDTL_RMV_cnt = 5;
	if(u2_rDTL_RMV_cnt<0) u2_rDTL_RMV_cnt = 0;

	if(u2_rDTL_RMV_cnt>0){
		u1_rDTL_move_true = 1;
		//u1_gmv_true = 1; // ignore gmv
		u8_black_sc_cnt = u8_black_sc_cnt_th; //quick start
	}
	else{
		u1_rDTL_move_true = 0;
	}
#endif

	//black pattern&sc but not static
	u1_black_sc = ((u16_mcHdtl==0)&&(u16_mcVdtl==0))||((s_pContext->_output_read_comreg.u1_sc_status_rb==1)&&(s_pContext->_output_read_comreg.u17_me_ZMV_cnt_rb<0x6000));

	if(u1_black_sc)	// for after black pattern, img dtl not stable
	{
		u8_black_sc_cnt = 0;
	}
	else
	{
		u8_black_sc_cnt += FRAME_CHANGE_CNT;

		if(u8_black_sc_cnt>60)
		{
			u8_black_sc_cnt = 60;
		}
	}

	if(u8_black_sc_cnt>=60)
	{
		u1_det_start = 1;
	}
	else
	{
		u1_det_start = 0;
	}

	UINT32 u28_tc_th = 0x20000;
	u1_tc_true = s_pContext->_output_read_comreg.u27_me_aTC_rb< u28_tc_th;//0x6000;

	//dtl all

	u1_dtl_all_cond_true = (u16_mcHdtl>(s_pContext->_output_read_comreg.u25_me_aDTL_rb>>11))||(u16_mcVdtl>(s_pContext->_output_read_comreg.u25_me_aDTL_rb>>11));

	//rim
	//u1_rim_true = (u16_rimUp<0x80);

	// result

	u1_basic_cond_true = u1_gmv_true&&u1_tc_true;//&&u1_rim_true;

	u1_det_true = (u1_det_start&&u1_basic_cond_true && u1_mcDtl_move_true &&u1_dtl_all_cond_true) ? 1 : 0;


	if(u1_det_true)
	{
		u6_RP_frm_in_cnt++;

		u6_RP_frm_in_cnt = (u6_RP_frm_in_cnt>8)? 8:u6_RP_frm_in_cnt;
	}
	else
	{
		u6_RP_frm_in_cnt = 0;
	}

	if((u1_det_start == 0)||(u1_basic_cond_true==0))		//black or sc, basic condition not match, quit
	{
		u8_RP_frm_hold_cnt = 0;
		u8_RP_frm_hold_cnt_max = 0;
	}
	else if(u6_RP_frm_in_cnt>=8)
	{
		u8_RP_frm_hold_cnt += FRAME_CHANGE_CNT;

		u8_RP_frm_hold_cnt = (u8_RP_frm_hold_cnt>240)? 240:u8_RP_frm_hold_cnt;			//video end not detect protect

		u8_RP_frm_hold_cnt_max = u8_RP_frm_hold_cnt;
	}
	else if((u8_RP_frm_hold_cnt_max==240)&&(u8_RP_frm_hold_cnt>FRAME_CHANGE_CNT)\
		&&(pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all_intervel5_pre>pOutput->SIS_MEMC.MEMC_STATUS.u25_rdbk_dtl_all_intervel5))	//hold only when repeat pattern move dispeared
	{
		u8_RP_frm_hold_cnt -= FRAME_CHANGE_CNT;
	}
	else if((u8_RP_frm_hold_cnt_max==240)&&(u8_RP_frm_hold_cnt>FRAME_CHANGE_CNT*2)&&u1_basic_cond_true)
	{
		u8_RP_frm_hold_cnt -= FRAME_CHANGE_CNT*2;
	}
	else
	{
		u8_RP_frm_hold_cnt = 0;
		u8_RP_frm_hold_cnt_max = 0;
	}
	
	if(u8_RP_frm_hold_cnt>0)
	{
		pOutput->u1_RP_detect_true = 1;
	}
	else
	{
		pOutput->u1_RP_detect_true = 0;
	}

	// Casino_patch : write by Jerry Wang @ 20161018
	static UBYTE casino_frm_cnt = 0;
	static UBYTE casino_frm_hold_cnt = 0;
	UBYTE casino_RP_true;
	UBYTE casino_rgn_mark[32] = {0};
	UBYTE casino_rgn_cnt = 0;
	static UBYTE casino_start = 0;
	UBYTE casino_rim_t = 1, casino_rgnDtl_diff_t = 1;
	UINT16 u16_rimLft = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_LFT];
	UINT16 u16_rimRht = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_RHT];
	UINT16 u16_rimUp  = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP];
	UINT16 u16_rimDn  = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_BOT];

	// rim
	{
		UBYTE u8_rim_delta = pParam->u8_casino_rim_delta;
		if ((u16_rimLft + u8_rim_delta < pParam->u16_casino_rimLft_th || (u16_rimLft > pParam->u16_casino_rimLft_th + u8_rim_delta)) || \
			(u16_rimRht + u8_rim_delta < pParam->u16_casino_rimRht_th || (u16_rimRht > pParam->u16_casino_rimRht_th + u8_rim_delta)) || \
			(u16_rimUp + u8_rim_delta < pParam->u16_casino_rimUp_th || (u16_rimUp > pParam->u16_casino_rimUp_th + u8_rim_delta)) || \
			(u16_rimDn + u8_rim_delta < pParam->u16_casino_rimDn_th || (u16_rimDn > pParam->u16_casino_rimDn_th + u8_rim_delta)))
		{
			casino_rim_t = 0;
		}
	}
	
	// rgnDtl
	for (i=0; i<32; i++){
		if((i <= 7) || (i == 24) || (i == 31)){
			if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[i]>29000)
				casino_rgn_mark[i] = 1;
			else
				casino_rgn_mark[i] = 0;
		}
		else if((i == 8) || (i == 9) || (i == 14) || (i == 15) || (i == 16) || (i == 17) || (i == 22) || (i == 23)){
			if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[i]>60000)
				casino_rgn_mark[i] = 1;
			else
				casino_rgn_mark[i] = 0;
		}
		else if((i == 10) || (i == 18)){
			if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[i]>43000)
				casino_rgn_mark[i] = 1;
			else
				casino_rgn_mark[i] = 0;
		}
		casino_rgn_cnt = casino_rgn_cnt + casino_rgn_mark[i];
	}

	// me_rgnDtl
	{
		UINT32 u20_meRgnDtl_diff[3];
		u20_meRgnDtl_diff[0] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[8], s_pContext->_output_read_comreg.u20_me_rDTL_rb[16]);
		u20_meRgnDtl_diff[1] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[8], s_pContext->_output_read_comreg.u20_me_rDTL_rb[23]);
		u20_meRgnDtl_diff[2] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[16], s_pContext->_output_read_comreg.u20_me_rDTL_rb[23]);
		for (i = 0; i < 3; i ++)
		{
			if (u20_meRgnDtl_diff[i] > 15500)
			{
				casino_rgnDtl_diff_t = 0;
			}
		}
	}

	if((casino_rgn_cnt >= 19) && (casino_rim_t == 1) && (casino_rgnDtl_diff_t == 1))
		casino_frm_cnt++;
	else
		casino_frm_cnt = 0;
 
	if(casino_frm_cnt >= 5)
		casino_frm_cnt = 5;
	if(casino_frm_cnt <= 0)
		casino_frm_cnt = 0;
 
	if(casino_frm_cnt >= 5)
		casino_start = 1;
	else
		casino_start = 0;
 
	if((casino_start == 1) && (casino_frm_hold_cnt == 0)){
		casino_frm_hold_cnt++;
		casino_RP_true = 1;
	}
	else if((casino_frm_hold_cnt > 0) && (casino_frm_hold_cnt <= 48)){
		casino_frm_hold_cnt++;
		casino_RP_true = 1;
	}
	else{
		casino_frm_hold_cnt = 0;
		casino_RP_true = 0;
		casino_start = 0;
	}

	if(casino_start == 0)
		casino_RP_true = 0;

	pOutput->u1_casino_RP_detect_true = (casino_RP_true && (pParam->u1_casino_RP_DetCtrl));

	// Avenger_patch : write by Jerry Wang @ 20161018
	UBYTE  avenger_rgn_mark_lft[4] = {0}, avenger_rgn_mark_rht[6] = {0};

	UINT32 avenger_th_lft = 12000, avenger_th_rht = 90000;
	//	6	7
	//	14	15
	//	22	23
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[6] >= avenger_th_rht)
		avenger_rgn_mark_rht[0] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[7] >= avenger_th_rht)
		avenger_rgn_mark_rht[1] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[14] >= avenger_th_rht)
		avenger_rgn_mark_rht[2] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[15] >= avenger_th_rht)
		avenger_rgn_mark_rht[3] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[22] >= avenger_th_rht)
		avenger_rgn_mark_rht[4] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[23] >= avenger_th_rht)
		avenger_rgn_mark_rht[5] = 1;

	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[1] <= avenger_th_lft)
		avenger_rgn_mark_lft[0] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[9] <= avenger_th_lft)
		avenger_rgn_mark_lft[1] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[17] <= avenger_th_lft)
		avenger_rgn_mark_lft[2] = 1;
	if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[25] <= avenger_th_lft)
		avenger_rgn_mark_lft[3] = 1;


	UBYTE avenger_rgn_cnt_col1 = 0;
	UBYTE avenger_rgn_cnt_col6 = 0;
	UBYTE avenger_rgn_cnt_col7 = 0;
	// col1		col6 col7
	//	0		0	1
	//	1		2	3
	//	2		4	5
	//	3

	// 20161202 robin: for prevent sonycam to fall into this patch (Q-10035)
	avenger_rgn_cnt_col1 = avenger_rgn_mark_lft[0] + avenger_rgn_mark_lft[1] + avenger_rgn_mark_lft[2] + avenger_rgn_mark_lft[3];

	avenger_rgn_cnt_col6 = avenger_rgn_mark_rht[0] + avenger_rgn_mark_rht[2] + avenger_rgn_mark_rht[4];
	avenger_rgn_cnt_col7 = avenger_rgn_mark_rht[1] + avenger_rgn_mark_rht[3] + avenger_rgn_mark_rht[5];
	
	static UBYTE avenger_frm_cnt = 0;
	static UBYTE avenger_frm_hold_cnt = 0;
	UBYTE avenger_RP_true;
	static UBYTE avenger_start = 0;
	if((avenger_rgn_cnt_col1 >= 2) && ((avenger_rgn_cnt_col6 <= 2 && avenger_rgn_cnt_col7 >= 2) || (avenger_rgn_cnt_col6 >= 2 && avenger_rgn_cnt_col7 <= 2))){
		avenger_frm_cnt++;
	}
	else{
		avenger_frm_cnt = 0;
	}
	
	if(avenger_frm_cnt >= 5)
		avenger_frm_cnt = 5;
	if(avenger_frm_cnt <= 0)
		avenger_frm_cnt = 0;

	if(avenger_frm_cnt >= 5)
		avenger_start = 1;
	else
		avenger_start = 0;

	if((avenger_start == 1) && (avenger_frm_hold_cnt == 0)){
		avenger_frm_hold_cnt++;
		avenger_RP_true = 1;
	}
	else if((avenger_frm_hold_cnt > 0) && (avenger_frm_hold_cnt <= 48)){
		avenger_frm_hold_cnt++;
		avenger_RP_true = 1;
	}
	else{
		avenger_frm_hold_cnt = 0;
		avenger_RP_true = 0;
		avenger_start = 0;
	}

	
	// ToL_10_patch : write by Jerry Wang @ 20161108
	UBYTE ToL10_rgn_mark[32] = {0};
	UINT32 ToL10_th = 90000;
	UBYTE ToL10_rgn_cnt_1 = 0, ToL10_rgn_cnt_2 = 0, ToL10_rgn_cnt_3 = 0, ToL10_rgn_cnt_4 = 0, ToL10_rgn_cnt_5 = 0, ToL10_rgn_cnt_6 = 0, ToL10_rgn_cnt_7 = 0;
	UBYTE ToL10_RP_true;
	static UBYTE ToL10_frm_cnt = 0;
	static UBYTE ToL10_frm_hold_cnt = 0;
	static UBYTE ToL10_start = 0;
	UBYTE ToL10_rgnDtl_diff_t = 1;
	UINT32 ToL10_RgnDtl_diff[6];
	UINT32 ToL10_RgnDtl_diff_mark[8] = {0};
	UINT32 ToL10_RgnDtl_diff_sum = 0;
	UINT32 ToL10_RgnDtl_avg[8] = {0};
	UBYTE ToL10_RgnDtl_avg_cnt = 0;
	UBYTE ToL10_RgnDtl_avg_true = 0;
	for (i=0; i<32; i++){
		if(s_pContext->_output_read_comreg.u20_me_rDTL_rb[i] > ToL10_th){
			ToL10_rgn_mark[i] = 1;
		}
		else{
			ToL10_rgn_mark[i] = 0;
		}
	}

	if((ToL10_rgn_mark[0]+ToL10_rgn_mark[1]+ToL10_rgn_mark[8]+ToL10_rgn_mark[9]+ToL10_rgn_mark[16]+ToL10_rgn_mark[17]+ToL10_rgn_mark[24]+ToL10_rgn_mark[25]) >= 8){
		ToL10_rgn_cnt_1 = 1;
	}
	else{
		ToL10_rgn_cnt_1 = 0;
	}
	if((ToL10_rgn_mark[1]+ToL10_rgn_mark[2]+ToL10_rgn_mark[9]+ToL10_rgn_mark[10]+ToL10_rgn_mark[17]+ToL10_rgn_mark[18]+ToL10_rgn_mark[25]+ToL10_rgn_mark[26]) >= 8){
		ToL10_rgn_cnt_2 = 1;
	}
	else{
		ToL10_rgn_cnt_2 = 0;
	}
	if((ToL10_rgn_mark[2]+ToL10_rgn_mark[3]+ToL10_rgn_mark[10]+ToL10_rgn_mark[11]+ToL10_rgn_mark[18]+ToL10_rgn_mark[19]+ToL10_rgn_mark[26]+ToL10_rgn_mark[27]) >= 8){
		ToL10_rgn_cnt_3 = 1;
	}
	else{
		ToL10_rgn_cnt_3 = 0;
	}
	if((ToL10_rgn_mark[3]+ToL10_rgn_mark[4]+ToL10_rgn_mark[11]+ToL10_rgn_mark[12]+ToL10_rgn_mark[19]+ToL10_rgn_mark[20]+ToL10_rgn_mark[27]+ToL10_rgn_mark[28]) >= 8){
		ToL10_rgn_cnt_4 = 1;
	}
	else{
		ToL10_rgn_cnt_4 = 0;
	}
	if((ToL10_rgn_mark[4]+ToL10_rgn_mark[5]+ToL10_rgn_mark[12]+ToL10_rgn_mark[13]+ToL10_rgn_mark[20]+ToL10_rgn_mark[21]+ToL10_rgn_mark[28]+ToL10_rgn_mark[29]) >= 8){
		ToL10_rgn_cnt_5 = 1;
	}
	else{
		ToL10_rgn_cnt_5 = 0;
	}
	if((ToL10_rgn_mark[5]+ToL10_rgn_mark[6]+ToL10_rgn_mark[13]+ToL10_rgn_mark[14]+ToL10_rgn_mark[21]+ToL10_rgn_mark[22]+ToL10_rgn_mark[29]+ToL10_rgn_mark[30]) >= 8){
		ToL10_rgn_cnt_6 = 1;
	}
	else{
		ToL10_rgn_cnt_6 = 0;
	}
	if((ToL10_rgn_mark[6]+ToL10_rgn_mark[7]+ToL10_rgn_mark[14]+ToL10_rgn_mark[15]+ToL10_rgn_mark[22]+ToL10_rgn_mark[23]+ToL10_rgn_mark[30]+ToL10_rgn_mark[31]) >= 8){
		ToL10_rgn_cnt_7 = 1;
	}
	else{
		ToL10_rgn_cnt_7 = 0;
	}

	// me_rgnDtl_diff
	for (i = 0; i < 8; i ++){
		ToL10_RgnDtl_diff[0] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[0+i], s_pContext->_output_read_comreg.u20_me_rDTL_rb[8+i]);
		ToL10_RgnDtl_diff[1] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[8+i], s_pContext->_output_read_comreg.u20_me_rDTL_rb[16+i]);
		ToL10_RgnDtl_diff[2] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[16+i], s_pContext->_output_read_comreg.u20_me_rDTL_rb[24+i]);
		ToL10_RgnDtl_diff[3] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[8+i], s_pContext->_output_read_comreg.u20_me_rDTL_rb[24+i]);
		ToL10_RgnDtl_diff[4] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[0+i], s_pContext->_output_read_comreg.u20_me_rDTL_rb[16+i]);
		ToL10_RgnDtl_diff[5] = _ABS_DIFF_(s_pContext->_output_read_comreg.u20_me_rDTL_rb[0+i], s_pContext->_output_read_comreg.u20_me_rDTL_rb[24+i]);

		if((s_pContext->_output_read_comreg.u20_me_rDTL_rb[0+i] > ToL10_th) && (s_pContext->_output_read_comreg.u20_me_rDTL_rb[8+i] > ToL10_th)
			&& (s_pContext->_output_read_comreg.u20_me_rDTL_rb[16+i] > ToL10_th) && (s_pContext->_output_read_comreg.u20_me_rDTL_rb[24+i] > ToL10_th)
			&& (ToL10_RgnDtl_diff[0] < 9000) && (ToL10_RgnDtl_diff[1] < 9000) && (ToL10_RgnDtl_diff[2] < 9000)
			&& (ToL10_RgnDtl_diff[3] < 9000) && (ToL10_RgnDtl_diff[4] < 9000) && (ToL10_RgnDtl_diff[5] < 9000))
		{
			ToL10_RgnDtl_diff_mark[i] = 1;
		}
		ToL10_RgnDtl_diff_sum = ToL10_RgnDtl_diff_sum + ToL10_RgnDtl_diff_mark[i];

		// 20161202 robin: for prevent sonycam to fall into this patch (Q-10035)
		ToL10_RgnDtl_avg[i] = (s_pContext->_output_read_comreg.u20_me_rDTL_rb[0+i] + s_pContext->_output_read_comreg.u20_me_rDTL_rb[8+i]
							+ s_pContext->_output_read_comreg.u20_me_rDTL_rb[16+i] + s_pContext->_output_read_comreg.u20_me_rDTL_rb[24+i]) >> 2;
	}
#if 1

	// 20161202 robin: for prevent sonycam to fall into this patch (Q-10035)
	for (i = 0; i < 8; i ++){
		ToL10_RgnDtl_avg_cnt += (ToL10_RgnDtl_avg[i] > 60000 && ToL10_RgnDtl_avg[i] < 120000) ? 1 : 0;
	}

	ToL10_RgnDtl_avg_true = (ToL10_RgnDtl_avg_cnt > 5) ? 0 : 1;

	if(ToL10_RgnDtl_avg_true && (ToL10_rgn_cnt_1 || ToL10_rgn_cnt_2 || ToL10_rgn_cnt_3 || ToL10_rgn_cnt_4 || ToL10_rgn_cnt_5 || ToL10_rgn_cnt_6 || ToL10_rgn_cnt_7 || ((ToL10_RgnDtl_diff_sum > 0) && (ToL10_RgnDtl_diff_sum < 3)))){
		ToL10_frm_cnt++;
	}
	else{
		ToL10_frm_cnt = 0;
	}

	if(ToL10_frm_cnt >= 10){
		ToL10_frm_cnt = 10;
	}
	if(ToL10_frm_cnt <= 0){
		ToL10_frm_cnt = 0;
	}

	if((ToL10_frm_cnt >= 10) ){
		ToL10_start = 1;
	}
	else{
		ToL10_start = 0;
	}

	if((ToL10_start == 1) && (ToL10_frm_hold_cnt == 0)){
		ToL10_frm_hold_cnt++;
		ToL10_RP_true = 1;
	}
	else if((ToL10_frm_hold_cnt > 0) && (ToL10_frm_hold_cnt <= 60)){
		ToL10_frm_hold_cnt++;
		ToL10_RP_true = 1;
	}
	else{
		ToL10_frm_hold_cnt = 0;
		ToL10_RP_true = 0;
		ToL10_start = 0;
	}

//	if(ToL10_start == 0)
//		ToL10_RP_true = 0;
#else
	if(ToL10_rgn_cnt_1 || ToL10_rgn_cnt_2 || ToL10_rgn_cnt_3 || ToL10_rgn_cnt_4 || ToL10_rgn_cnt_5 || ToL10_rgn_cnt_6 || ToL10_rgn_cnt_7 || ((ToL10_RgnDtl_diff_sum > 0) && (ToL10_RgnDtl_diff_sum < 3))){
		ToL10_RP_true = 1;
	}
	else{
		ToL10_RP_true = 0;
	}
#endif

	pOutput->u1_ToL10_RP_true = ToL10_RP_true;

	//
	//printk("detect=%d, casino=%d, avenger=%d, ToL10=%d\n", pOutput->u1_RP_detect_true, pOutput->u1_casino_RP_detect_true, avenger_RP_true, ToL10_RP_true);
	
	if(pOutput->u1_RP_detect_true == 1 && pOutput->u1_casino_RP_detect_true == 1){
		pOutput->u1_RP_detect_true =0;
	}
	else	if(pOutput->u1_RP_detect_true == 0 && avenger_RP_true == 1){
		pOutput->u1_RP_detect_true = 1;
	}
	else	if(pOutput->u1_RP_detect_true == 0 && ToL10_RP_true == 1){
		pOutput->u1_RP_detect_true = 1;
	}

	pOutput->u1_RP_detect_true = pParam->u1_RepeatPattern_en && pOutput->u1_RP_detect_true;
	
	//else if(){
	//}

	#if 0
	if (frm_cnt % 30 == 0){
		printk(KERN_EMERG"[lsy] [%d %d %d (%d %d) %d] [%d %d %d %d] [%d %d %d %d][%d %d %d %d, %d %d %d %d, %d %d %d %d]\n",
			u1_det_true, u1_det_start, u1_basic_cond_true, u1_mcDtl_move_true, u1_rDTL_move_true, u1_dtl_all_cond_true,
			u2_mcDtl_HV, u2_GMV_single_move, u2_rDTL_RMV_cnt, s_pContext->_output_read_comreg.u27_me_aTC_rb,
			u1_maxGMV_x_t, u1_maxGMV_y_t, u1_secGMV_x_t, u1_secGMV_y_t,
			u16_mcVdtl, u16_mcHdtl, u11_GMV_x_max, u10_GMV_y_max, u8_rmove_1_cnt, u8_rmove_2_cnt, u8_rmove_3_cnt, u8_rmove_4_cnt, u8_rmove_rgn1_cnt, u8_rmove_rgn2_cnt, u8_rmove_rgn3_cnt, u8_rmove_rgn4_cnt);
			s_pContext->_output_read_comreg.u22_me_rTC_rb[31], s_pContext->_output_read_comreg.u22_me_rSC_rb[31], s_pContext->_output_read_comreg.u25_me_rSAD_rb[31]);
		#if 1
		printk(KERN_EMERG"$$$   [%d %d %d %d %d %d]   $$$\n\r$$$   [(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d)]   $$$\n\r$$$   [(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d)]   $$$\n\r$$$   [(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d)]   $$$\n\r$$$   [(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d),\t(%d %d %d)]   $$$\n\r",
			u16_mcVdtl, u16_mcHdtl, u10_GMV_y_max, u11_GMV_x_max, s11_secGMV_x, s10_secGMV_y,
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[0], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[0], s_pContext->_output_read_comreg.u20_me_rDTL_rb[0],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[1], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[1], s_pContext->_output_read_comreg.u20_me_rDTL_rb[1],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[2], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[2], s_pContext->_output_read_comreg.u20_me_rDTL_rb[2],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[3], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[3], s_pContext->_output_read_comreg.u20_me_rDTL_rb[3],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[4], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[4], s_pContext->_output_read_comreg.u20_me_rDTL_rb[4],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[5], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[5], s_pContext->_output_read_comreg.u20_me_rDTL_rb[5],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[6], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[6], s_pContext->_output_read_comreg.u20_me_rDTL_rb[6],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[7], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[7], s_pContext->_output_read_comreg.u20_me_rDTL_rb[7],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[8], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[8], s_pContext->_output_read_comreg.u20_me_rDTL_rb[8],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[9], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[9], s_pContext->_output_read_comreg.u20_me_rDTL_rb[9],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[10], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[10], s_pContext->_output_read_comreg.u20_me_rDTL_rb[10],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[11], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[11], s_pContext->_output_read_comreg.u20_me_rDTL_rb[11],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[12], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[12], s_pContext->_output_read_comreg.u20_me_rDTL_rb[12],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[13], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[13], s_pContext->_output_read_comreg.u20_me_rDTL_rb[13],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[14], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[14], s_pContext->_output_read_comreg.u20_me_rDTL_rb[14],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[15], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[15], s_pContext->_output_read_comreg.u20_me_rDTL_rb[15],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[16], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[16], s_pContext->_output_read_comreg.u20_me_rDTL_rb[16],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[17], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[17], s_pContext->_output_read_comreg.u20_me_rDTL_rb[17],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[18], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[18], s_pContext->_output_read_comreg.u20_me_rDTL_rb[18],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[19], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[19], s_pContext->_output_read_comreg.u20_me_rDTL_rb[19],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[20], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[20], s_pContext->_output_read_comreg.u20_me_rDTL_rb[20],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[21], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[21], s_pContext->_output_read_comreg.u20_me_rDTL_rb[21],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[22], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[22], s_pContext->_output_read_comreg.u20_me_rDTL_rb[22],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[23], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[23], s_pContext->_output_read_comreg.u20_me_rDTL_rb[23],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[24], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[24], s_pContext->_output_read_comreg.u20_me_rDTL_rb[24],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[25], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[25], s_pContext->_output_read_comreg.u20_me_rDTL_rb[25],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[26], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[26], s_pContext->_output_read_comreg.u20_me_rDTL_rb[26],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[27], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[27], s_pContext->_output_read_comreg.u20_me_rDTL_rb[27],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[28], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[28], s_pContext->_output_read_comreg.u20_me_rDTL_rb[28],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[29], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[29], s_pContext->_output_read_comreg.u20_me_rDTL_rb[29],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[30], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[30], s_pContext->_output_read_comreg.u20_me_rDTL_rb[30],
			s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[31], s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[31], s_pContext->_output_read_comreg.u20_me_rDTL_rb[31]);
		#endif
	}
	// casino
 	if (frm_cnt % 10 == 0){
		printk(KERN_EMERG"$$$   [(%d),\t(%d),\t(%d),\t(%d)]   $$$\n\r", casino_RP_true, casino_rim_t, casino_rgnDtl_diff_t, casino_rgn_cnt);
	}
	// ToL_10
 	if (frm_cnt % 10 == 0){
		printk(KERN_EMERG"$$$   [(%d),\t(%d),\t(%d)]   $$$\n\r$$$   [(%d),\t(%d),\t(%d),\t(%d),\t(%d),\t(%d),\t(%d)]   $$$\n\r$$$   [(%d),\t(%d),\t(%d),\t(%d),\t(%d),\t(%d),\t(%d),\t(%d)]   $$$\n\r", 
			ToL10_RP_true, ToL10_frm_hold_cnt, ToL10_RgnDtl_diff_sum,
			ToL10_rgn_cnt_1, ToL10_rgn_cnt_2, ToL10_rgn_cnt_3, ToL10_rgn_cnt_4, ToL10_rgn_cnt_5, ToL10_rgn_cnt_6, ToL10_rgn_cnt_7,
			ToL10_RgnDtl_diff_mark[0], ToL10_RgnDtl_diff_mark[1], ToL10_RgnDtl_diff_mark[2], ToL10_RgnDtl_diff_mark[3], ToL10_RgnDtl_diff_mark[4], ToL10_RgnDtl_diff_mark[5], ToL10_RgnDtl_diff_mark[6], ToL10_RgnDtl_diff_mark[7]);
 	}
	#endif

	frm_cnt ++;
	if (frm_cnt >= 100000) frm_cnt = 0;
}

VOID MEMC_SaddiffTh_calc(_OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{
	UINT32 u32_saddiff_th_step = 0;
	UINT32 u32_saddiff_th_tmp = 0;
	UINT32 u32_i = 0, u32_rmv_cnt_sum = 0, u32_cnt = 0, rmv_cnt_avg = 0;

	const _PQLCONTEXT *s_pContext = GetPQLContext();
	
	SINT16 u11_gmv_mvx = (s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb)>>2;
	SINT16 u10_gmv_mvy = (s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb)>>2;
	UBYTE u6_gmv_cnt = s_pContext->_output_read_comreg.u6_me_GMV_1st_cnt_rb;

	pOutput->u32_new_saddiff_th =  s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_sc_saddiff_th;
		
	if ((u6_gmv_cnt>28) && (_ABS_(u11_gmv_mvx)>=2 || _ABS_(u10_gmv_mvy)>=1))
	{
//		u32_saddiff_th_step = ((_MAX_(0x500000-s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_sc_saddiff_th, 0)<<2)/(0x3E8-0x320));
		u32_saddiff_th_tmp = 0x500000 - _MIN_(s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_sc_saddiff_th , 0x500000);
		u32_saddiff_th_step = ((u32_saddiff_th_tmp<<2)/(0x3E8-0x320));

		for (u32_i = 0; u32_i < 32; u32_i ++)
		{				
			if(s_pContext->_output_read_comreg.u12_me_rMV_1st_unconf_rb[u32_i]<5 && _ABS_(u11_gmv_mvx-(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[u32_i]>>2)) < 8 && _ABS_(u10_gmv_mvy-(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[u32_i]>>2)) < 6)
			{
				u32_rmv_cnt_sum += s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[u32_i];
				u32_cnt++;
			}
		}
				
		if(u32_cnt)
		{
			rmv_cnt_avg = u32_rmv_cnt_sum/u32_cnt;
			
			if(rmv_cnt_avg >= 0x3E8)
			{ 
				pOutput->u32_new_saddiff_th = 0x500000;	
			}
			else if(rmv_cnt_avg > 0x320)
			{ 
				pOutput->u32_new_saddiff_th = (((rmv_cnt_avg-0x320)*u32_saddiff_th_step)>>2) + \
						s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_sc_saddiff_th;
			}

		}
	}

	pOutput->u32_new_saddiff_th = (pOutput->u32_new_saddiff_th*1+pOutput->u32_new_saddiff_th_pre*7)>>3;
	pOutput->u32_new_saddiff_th_pre= pOutput->u32_new_saddiff_th;

}

VOID MEMC_LightSwordDetect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{

	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE  chaos_true = 0;
	UBYTE  chaos_apply_num = 10;

	// gmv
	UBYTE  gmv_iir = 50;

	int       me_GMV_1st_vy_rb_iir = 0;
	UBYTE me_GMV_1st_cnt_rb_iir  = 0;
	UINT32 me_GMV_1st_unconf_rb_iir = 0;
	UBYTE gmv_true = 0;

	me_GMV_1st_vy_rb_iir = (gmv_iir * (pOutput->s10_me_GMV_1st_vy_rb_iir) + (256-gmv_iir) * s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb) >> 8;
	me_GMV_1st_cnt_rb_iir  = (gmv_iir * (pOutput->u6_me_GMV_1st_cnt_rb_iir) + (256-gmv_iir) * s_pContext->_output_read_comreg.u6_me_GMV_1st_cnt_rb) >> 8;
	me_GMV_1st_unconf_rb_iir = (gmv_iir * (pOutput->u12_me_GMV_1st_unconf_rb_iir) + (256-gmv_iir) * s_pContext->_output_read_comreg.u12_me_GMV_1st_unconf_rb) >> 8;
	if( _ABS_(me_GMV_1st_vy_rb_iir) < 6 && me_GMV_1st_cnt_rb_iir > 30 && me_GMV_1st_unconf_rb_iir < 50)
	{
		gmv_true = 1;
	}


	// reiong gmv
	UBYTE rg_idx;
	UBYTE rg_cnt = 0;
//	UBYTE unconf_1st_th = 0x30;
//	UBYTE unconf_2nd_th = 0x20;
//	UINT32 grp_cnt_th = 1000;
	UBYTE rmv_diff_th = 0x46;
	UBYTE rg_cnt_th = 5;
	UBYTE rmv_true = 0;
	
	for(rg_idx = 8; rg_idx < 24; rg_idx++)
	{		
		int vx_1st, vy_1st, cnt_1st;
		int vx_2nd, vy_2nd, cnt_2nd;
		vx_1st = s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[rg_idx];
		vy_1st = s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[rg_idx];
		cnt_1st = s_pContext->_output_read_comreg.u12_me_rMV_1st_cnt_rb[rg_idx];
		vx_2nd = s_pContext->_output_read_comreg.s11_me_rMV_2nd_vx_rb[rg_idx];
		vy_2nd = s_pContext->_output_read_comreg.s10_me_rMV_2nd_vy_rb[rg_idx];
		cnt_2nd = s_pContext->_output_read_comreg.u12_me_rMV_2nd_cnt_rb[rg_idx];

		if((_ABS_(vx_1st - vx_2nd) + _ABS_(vy_1st - vy_2nd) > rmv_diff_th) && (cnt_1st != 0 && cnt_2nd != 0))
			rg_cnt ++;
	}

	rmv_true = (rg_cnt > rg_cnt_th) ? 1 : 0;

	// rim
	UBYTE  rim_delta_H = 20;
	UBYTE  rim_delta_Up = 40;
	UBYTE  rim_delta_Dn = 60;
	UINT32 rimLft_th = 0;
	UINT32 rimRgt_th = 3840;
	UINT32 rimUp_th = 240;
	UINT32 rimDn_th = 1940;
	
	

	UINT32 rimLft = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_LFT];
	UINT32 rimRht = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_RHT];
	UINT32 rimUp = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP];
	UINT32 rimDn = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_BOT];

	UBYTE rim_true = 1;
	if ((rimLft > rimLft_th + rim_delta_H) || \
	    (rimRht < rimRgt_th -rim_delta_H) || \
	    (rimUp < rimUp_th - rim_delta_Up  || rimUp > rimUp_th + rim_delta_Up) || \
	    (rimDn < rimDn_th - rim_delta_Dn || rimDn > rimDn_th + rim_delta_Dn))
	{
		rim_true = 0;
	}

	// apl
	UBYTE apl_true, apl_true_con0, apl_true_con1, apl_true_con2;
	UINT32 apl_th =  0xFF00;
	UINT32 apl_cnt_th = 3;
	UINT32 max_rgn_apl, min_rgn_apl, rgn_apl,  apl_cnt;

	apl_true = apl_true_con0 = apl_true_con1 = apl_true_con2 = 0;

	apl_cnt= 0;
	if(s_pContext->_output_read_comreg.u20_me_rAPLp_rb[8] < apl_th)
	{
		apl_cnt++;
	}
	if(s_pContext->_output_read_comreg.u20_me_rAPLp_rb[15] < apl_th)
	{
		apl_cnt++;
	}
	if(s_pContext->_output_read_comreg.u20_me_rAPLp_rb[16] < apl_th)
	{
		apl_cnt++;
	}
	if(s_pContext->_output_read_comreg.u20_me_rAPLp_rb[23] < apl_th)
	{
		apl_cnt++;
	}
	if(apl_cnt >= apl_cnt_th)
	{
		apl_true_con0 = 1;	
	}

	max_rgn_apl = min_rgn_apl = s_pContext->_output_read_comreg.u20_me_rAPLp_rb[8];
	for(rg_idx = 9; rg_idx < 16; rg_idx++)
	{
		rgn_apl = s_pContext->_output_read_comreg.u20_me_rAPLp_rb[rg_idx];
		if(rgn_apl > max_rgn_apl)	
		{
			max_rgn_apl = rgn_apl;	
		}
		if(rgn_apl < min_rgn_apl)
		{
			min_rgn_apl = rgn_apl;
		}
	}
	if(max_rgn_apl > (min_rgn_apl * 3 / 2))
	{
		apl_true_con1 = 1;
	}

	max_rgn_apl = min_rgn_apl = s_pContext->_output_read_comreg.u20_me_rAPLp_rb[16];
	for(rg_idx = 17; rg_idx < 24; rg_idx++)
	{
		rgn_apl = s_pContext->_output_read_comreg.u20_me_rAPLp_rb[rg_idx];
		if(rgn_apl > max_rgn_apl)	
		{
			max_rgn_apl = rgn_apl;	
		}
		if(rgn_apl < min_rgn_apl)
		{
			min_rgn_apl = rgn_apl;
		}
	}
	if(max_rgn_apl > (min_rgn_apl * 3 / 2))
	{
		apl_true_con2 = 1;
	}

	apl_true = ((apl_true_con0 == 1) && ((apl_true_con1 == 1) || (apl_true_con2 == 1))) ? 1 : 0;
	

	chaos_true = rim_true && rmv_true && gmv_true && apl_true && pParam->u1_LightSword_en;	

	// detection
	if(chaos_true)
	{
		pOutput->u8_chaos_apply = chaos_apply_num;
	}
	else if(pOutput->u8_chaos_apply > 0)
	{
		pOutput->u8_chaos_apply = pOutput->u8_chaos_apply - 1;
	}
	else
	{
		pOutput->u8_chaos_apply = 0;
	}
	
	pOutput->u1_chaos_true = chaos_true;
	pOutput->s10_me_GMV_1st_vy_rb_iir = me_GMV_1st_vy_rb_iir;
	pOutput->u6_me_GMV_1st_cnt_rb_iir = me_GMV_1st_cnt_rb_iir;
	pOutput->u12_me_GMV_1st_unconf_rb_iir = me_GMV_1st_unconf_rb_iir;

/*
	// dump
	UINT32 u32_RB_val;
	ReadRegister(0x000040A8, 25, 25, &u32_RB_val);
	if(u32_RB_val)
	{
		printk("i:(%d,%d,%d,%d,%d,%d,%d,%d); (%d,%d,%d,%d,%d,%d,%d,%d)\n",
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[9],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[10],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[11],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[12],
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[12],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[13],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[14],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[15],
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[16],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[17],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[18],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[19],
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[20],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[21],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[22],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[23]);
		printk("p:(%d,%d,%d,%d,%d,%d,%d,%d); (%d,%d,%d,%d,%d,%d,%d,%d)\n",
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[9],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[10],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[11],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[12],
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[12],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[13],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[14],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[15],
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[16],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[17],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[18],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[19],
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[20],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[21],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[22],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[23]);
		

		//printk("rim:(%d,%d,%d,%d)\n", s_pContext->_output_rimctrl.u12_Rim_Result[0], s_pContext->_output_rimctrl.u12_Rim_Result[1], s_pContext->_output_rimctrl.u12_Rim_Result[2], s_pContext->_output_rimctrl.u12_Rim_Result[3]);
		printk("rim=%d:(%d,%d,%d,%d), (%d,%d,(%d,%d),(%d,%d))\n", rim_true, rimLft, rimRht, rimUp, rimDn, rimLft_th + rim_delta_H, rimRgt_th -rim_delta_H, rimUp_th - rim_delta_V, rimUp_th + rim_delta_V, rimDn_th - rim_delta_V, rimDn_th + rim_delta_V);
	}
*/
}

VOID MEMC_Big_APLDiff_Detect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE  u8_cadence_Id = s_pContext->_output_filmDetectctrl.u8_cur_cadence_out[_FILM_ALL];
	PQL_INPUT_FRAME_RATE in_fmRate = s_pContext->_external_data._input_frameRate;
	UBYTE u8_cand_cond_hold_cnt = 0;
	
	UINT32 apl_diff, big_apldiff_th, big_apldiff_rgn_cnt, min_rgn_apl;
	UINT32 i, j;
	UINT32 ratio = 107;//96;//128;
	UINT32 big_apldiff_rgn_cnt_th = 18; 	

	UINT16 rim_lft, rim_rht, rim_top, rim_bot, width, height;	
	UINT16 h_sta_rgn, h_end_rgn, v_sta_rgn, v_end_rgn;

	SINT16 gmv0_x, gmv0_y, gmv1_x, gmv1_y;
	UBYTE gmv0_cnt, gmv1_cnt;
	UINT16 gmv0_ucf, gmv1_ucf;
	UINT32 gmv_mv_th = 0x80;//0xA0;
	UBYTE gmv_cnt_th = 0x10;
	UINT16 gmv_ucf_th = 0x10;

	UINT32 glb_sad;
	UINT32 glb_sad_th_h = 0xE00000;
	UINT32 glb_sad_th_l = 0x20;

	UBYTE  u1_big_apldiff_true, u1_big_motion_true, u1_pan_motion_true, u1_sad_zero2big;
	
	if (u8_cadence_Id == _CAD_22 || (in_fmRate == _PQL_IN_25HZ && u8_cadence_Id == _CAD_VIDEO))
	{
		u8_cand_cond_hold_cnt = 1;
	}
	else
	{
		u8_cand_cond_hold_cnt = 2;
	}

	pOutput->u32_big_apldiff_saddiff_th = 0x4000;//0xF000;
	
	if(pParam->u1_BigAPLDiff_en)
	{	
#if 0	
		// find min available rgn_apl
		rim_lft = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_LFT];	
	 	rim_rht = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_RHT];	
		rim_top = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_TOP];	
		rim_bot = s_pContext->_output_rimctrl.u12_Rim_Result[_RIM_BOT];
		width = s_pContext->_output_rimctrl.u12_out_resolution[_RIM_RHT] - s_pContext->_output_rimctrl.u12_out_resolution[_RIM_LFT];
		height =  s_pContext->_output_rimctrl.u12_out_resolution[_RIM_BOT] - s_pContext->_output_rimctrl.u12_out_resolution[_RIM_TOP];
		min_rgn_apl = 0xFFFFF;
		width = (width == 0) ? 1 : width;
		height = (height == 0) ? 1 : height;
		h_sta_rgn = (2 * 8 * rim_lft / width + 1) >> 1;
		h_end_rgn = (2 * 8 * rim_rht / width - 1) >> 1;
		v_sta_rgn = (2 * 4 * rim_top / height + 1) >> 1;
		v_end_rgn = (2 * 4 * rim_bot / height - 1) >> 1;
		
		for(i = v_sta_rgn; i < v_end_rgn; i++)
		{
			for(j = h_sta_rgn; j < h_end_rgn; j++)
			{
				if(s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i * 8 + j] < min_rgn_apl)
				{
					min_rgn_apl = s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i * 8 + j];
				}
				if(s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i * 8 + j] < min_rgn_apl)
				{
					min_rgn_apl = s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i * 8 + j];
				}
			}
		}
		
		// calc rgn apl th
		//big_apldiff_th = 0x4000;
		big_apldiff_th = min_rgn_apl * ratio >> 8;

		// calc big apldiff rgn cnt 
		big_apldiff_rgn_cnt = 0;
		for(i = 0; i < 32; i++)
		{
			if(s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i] > s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i])
			{
				apl_diff = s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i] - s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i];
			}
			else
			{
				apl_diff = s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i] - s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i];
			}
			if(apl_diff >= big_apldiff_th)
			{
				big_apldiff_rgn_cnt++;
			}
		}
#endif

#if 1
	ratio = 0x28;
	{
		// calc big apldiff rgn cnt 		
		big_apldiff_rgn_cnt = 0;
		for(i = 0; i < 32; i++)
		{
			if(s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i] > s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i])
			{
				apl_diff = s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i] - s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i];
				big_apldiff_th = (s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i] * ratio) >> 8;
			}
			else
			{
				apl_diff = s_pContext->_output_read_comreg.u20_me_rAPLp_rb[i] - s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i];
				big_apldiff_th = (s_pContext->_output_read_comreg.u20_me_rAPLi_rb[i] * ratio) >> 8;
			}
			if(apl_diff >= big_apldiff_th)
			{
				big_apldiff_rgn_cnt++;
			}
		}
	}
#endif

		if(big_apldiff_rgn_cnt >= big_apldiff_rgn_cnt_th)
		{
			u1_big_apldiff_true = 1;
		}
		else
		{
			u1_big_apldiff_true = 0;
		}

		// big motion
		gmv0_x = s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb;
		gmv0_y = s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb;
		gmv0_cnt = s_pContext->_output_read_comreg.u6_me_GMV_1st_cnt_rb;
		gmv0_ucf = s_pContext->_output_read_comreg.u12_me_GMV_1st_unconf_rb;

		gmv1_x = s_pContext->_output_read_comreg.s11_me_GMV_2nd_vx_rb;
		gmv1_y = s_pContext->_output_read_comreg.s10_me_GMV_2nd_vy_rb;
		gmv1_cnt = s_pContext->_output_read_comreg.u6_me_GMV_2nd_cnt_rb;
		gmv1_ucf = s_pContext->_output_read_comreg.u12_me_GMV_2nd_unconf_rb;

		u1_big_motion_true = 0;
		if((_ABS_(gmv0_x) >= gmv_mv_th || _ABS_(gmv0_y) >= gmv_mv_th)
			&& (gmv0_cnt >= gmv_cnt_th) && (gmv0_ucf <= gmv_ucf_th))
		{
			u1_big_motion_true = 1;
		}

		if((_ABS_(gmv1_x) >= gmv_mv_th || _ABS_(gmv1_y) >= gmv_mv_th)
			&& (gmv1_cnt >= gmv_cnt_th) && (gmv1_ucf <= gmv_ucf_th))
		{
			u1_big_motion_true = 1;
		}
		
		// pan
		gmv_mv_th = 0x3C;
	 	gmv_cnt_th = 0x1E;
		gmv_ucf_th = 0x5;

		u1_pan_motion_true = 0;
		if((_ABS_(gmv0_x) >= gmv_mv_th || _ABS_(gmv0_y) >= gmv_mv_th)
			&& (gmv0_cnt >= gmv_cnt_th) && (gmv0_ucf <= gmv_ucf_th))
		{
			u1_pan_motion_true = 1;
		}

		if((_ABS_(gmv1_x) >= gmv_mv_th || _ABS_(gmv1_y) >= gmv_mv_th)
			&& (gmv1_cnt >= gmv_cnt_th) && (gmv1_ucf <= gmv_ucf_th))
		{
			u1_pan_motion_true = 1;
		}

		// change from still
		glb_sad = s_pContext->_output_read_comreg.u30_me_aSAD_rb;
		if((pOutput->u32_big_apldiff_sad_pre < glb_sad_th_l) && (glb_sad > glb_sad_th_h))
		{
			u1_sad_zero2big = 1;
		}
		else
		{
			u1_sad_zero2big = 0;
		}
		pOutput->u32_big_apldiff_sad_pre = glb_sad;
	
		if((u1_big_apldiff_true == 1) && (u1_big_motion_true == 0) && (u1_pan_motion_true == 0))
		{
			pOutput->u8_big_apldiff_hold_cnt = 5;	
			if(u1_sad_zero2big == 1)
			{
				pOutput->u8_big_apldiff_sc_hold_cnt = 4;// 1;
			}
		}
		else if(pOutput->u8_big_apldiff_hold_cnt != 0)
		{
			pOutput->u8_big_apldiff_hold_cnt--;
			pOutput->u8_big_apldiff_sc_hold_cnt = u8_cand_cond_hold_cnt;
		}
		else
		{
			pOutput->u8_big_apldiff_hold_cnt = 0;
			pOutput->u8_big_apldiff_sc_hold_cnt = u8_cand_cond_hold_cnt;
		}
	
	}
	else
	{
		pOutput->u8_big_apldiff_hold_cnt = 0;
		pOutput->u8_big_apldiff_sc_hold_cnt = u8_cand_cond_hold_cnt;
	}
#if 0
	// dump
	UINT32 u32_RB_val;
	ReadRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 12, 12, &u32_RB_val);
	if(u32_RB_val)
	{
	/*
		printk("i:(%d,%d,%d,%d,%d,%d,%d,%d); (%d,%d,%d,%d,%d,%d,%d,%d)\n",
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[9],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[10],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[11],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[12],
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[12],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[13],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[14],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[15],
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[16],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[17],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[18],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[19],
			s_pContext->_output_read_comreg.u20_me_rAPLi_rb[20],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[21],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[22],s_pContext->_output_read_comreg.u20_me_rAPLi_rb[23]);
		printk("p:(%d,%d,%d,%d,%d,%d,%d,%d); (%d,%d,%d,%d,%d,%d,%d,%d)\n",
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[9],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[10],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[11],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[12],
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[12],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[13],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[14],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[15],
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[16],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[17],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[18],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[19],
			s_pContext->_output_read_comreg.u20_me_rAPLp_rb[20],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[21],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[22],s_pContext->_output_read_comreg.u20_me_rAPLp_rb[23]);
	*/	

		//printk("rim:(%d,%d,%d,%d)\n", s_pContext->_output_rimctrl.u12_Rim_Result[0], s_pContext->_output_rimctrl.u12_Rim_Result[1], s_pContext->_output_rimctrl.u12_Rim_Result[2], s_pContext->_output_rimctrl.u12_Rim_Result[3]);
		printk("GMV0:(%d, %d, %d, %d); GMV1:(%d, %d, %d, %d)\n", gmv0_x, gmv0_y, gmv0_cnt, gmv0_ucf,  gmv1_x, gmv1_y, gmv1_cnt, gmv1_ucf);
		printk("rgn_cnt:%d, saddiff:%d\n", big_apldiff_rgn_cnt, s_pContext->_output_read_comreg.u30_me_aSAD_rb);
	}
#endif

}

VOID MEMC_EPG_Protect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE stillGMV_true = 0;
	UBYTE moveROI_true = 0;
	UBYTE stillNonROI_true = 0;
	UINT32 moveROI_sad = 0;
	UBYTE moveROI_cnt = 0;
	UBYTE dtl_hv_prt_true = 0;
	UBYTE dtl_all_prt_true = 0;
	UBYTE dtl_rgn_prt_true = 0;
	UBYTE stillNonROI_cnt = 0;
	UINT32 stillNonROI_sad = 0;
	UBYTE u8_i = 0;
	UBYTE EPG_true = 0;
	static UBYTE EPG_detCnt = 0;

	UINT32 moveROI_aplDiff = 0;
	UINT32 stillNonROI_aplDiff = 0;
	UINT32 u32_rimRatio = (s_pContext->_output_rimctrl.u32_rimRatio == 0) ? 128 : s_pContext->_output_rimctrl.u32_rimRatio;
	
	stillGMV_true = ((s_pContext->_output_read_comreg.u12_me_GMV_1st_unconf_rb == 0) &&
		          (_ABS_((s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb)>>2) == 0) &&
		          (_ABS_((s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb)>>2) == 0))? 1:0;

	for(u8_i = 0;u8_i < 32; u8_i++)
	{
		if(u8_i >= 9 && u8_i <= 14)
		{
			if(_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[u8_i]>>2) == 0 &&
				_ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[u8_i]>>2) == 0)
				moveROI_cnt++;

			moveROI_sad += s_pContext->_output_read_comreg.u25_me_rSAD_rb[u8_i] ;
			moveROI_aplDiff = (s_pContext->_output_read_comreg.u25_me_rSAD_rb[u8_i]>moveROI_aplDiff)?s_pContext->_output_read_comreg.u25_me_rSAD_rb[u8_i]:moveROI_aplDiff;
		}
		else
		{
			if(_ABS_(s_pContext->_output_read_comreg.s11_me_rMV_1st_vx_rb[u8_i]>>2) == 0 &&
				_ABS_(s_pContext->_output_read_comreg.s10_me_rMV_1st_vy_rb[u8_i]>>2) == 0)
			{
				stillNonROI_cnt++;
				stillNonROI_sad += s_pContext->_output_read_comreg.u25_me_rSAD_rb[u8_i] ;
				stillNonROI_aplDiff = (s_pContext->_output_read_comreg.u25_me_rSAD_rb[u8_i]>stillNonROI_aplDiff)?s_pContext->_output_read_comreg.u25_me_rSAD_rb[u8_i]:stillNonROI_aplDiff;
			}
		}
	}

	if((moveROI_cnt*u32_rimRatio>>7 >= 4) && (moveROI_sad*u32_rimRatio>>7 >= 0x20000))
		moveROI_true = 1;
	else if((moveROI_cnt*u32_rimRatio>>7 >= 4) && (moveROI_sad*u32_rimRatio>>7 <= 0x200))
		moveROI_true = 0;
	 else
	 	moveROI_true = s_pContext->_output_me_sceneAnalysis.u8_EPG_moveROI;

	 pOutput->u8_EPG_moveROI= moveROI_true;

	stillNonROI_true = ((stillNonROI_cnt*u32_rimRatio>>7 >= 25) && (stillNonROI_sad*u32_rimRatio>>7 < 0x8000))? 1:0;

	dtl_hv_prt_true = (s_pContext->_output_read_comreg.u17_me_ZMV_cnt_rb*u32_rimRatio>>7 > 0x7000) && (s_pContext->_output_read_comreg.u17_me_ZMV_dtl_cnt_rb*u32_rimRatio>>7 > 0x3000);

	dtl_rgn_prt_true = ((s_pContext->_output_read_comreg.u20_me_rDTL_rb[17]<s_pContext->_output_read_comreg.u20_me_rDTL_rb[18])
					&&(s_pContext->_output_read_comreg.u20_me_rDTL_rb[18]<s_pContext->_output_read_comreg.u20_me_rDTL_rb[19])
					&&(s_pContext->_output_read_comreg.u20_me_rDTL_rb[17]*u32_rimRatio>>7 >0xb000));
	
	EPG_true = (stillGMV_true == 1 && moveROI_true == 1 && stillNonROI_true == 1 && dtl_hv_prt_true == 1 && dtl_rgn_prt_true==1);

	if(EPG_true)
		EPG_detCnt = (EPG_detCnt>=8)?8:(EPG_detCnt+1);
	else
		EPG_detCnt = 0;
		
	if(EPG_detCnt == 8 && EPG_true)
		pOutput->u8_EPG_apply = 15;
	else if(dtl_hv_prt_true == 0)
		pOutput->u8_EPG_apply = 0;
	else if(s_pContext->_output_me_sceneAnalysis.u8_EPG_apply > 0)
		pOutput->u8_EPG_apply = s_pContext->_output_me_sceneAnalysis.u8_EPG_apply - 1;
	else
		pOutput->u8_EPG_apply = 0;

	if(pParam->u1_EPG_en==0)
		pOutput->u8_EPG_apply = 0;
#if 0
	UINT32 ip31=0;
	ReadRegister(FRC_TOP__kmc_top__dummy24_ADDR,31,31,&ip31);

	if(ip31)
	printk("%d %d..%d %d %d %d %d %d..%d %x.. %d %x.. %x %x.. %x %x %x %x.. %x %x\n", pOutput->u8_EPG_apply, s_pContext->_output_rimctrl.u32_rimRatio,
	EPG_detCnt, stillGMV_true, moveROI_true, stillNonROI_true, dtl_hv_prt_true, dtl_rgn_prt_true,
	moveROI_cnt*u32_rimRatio>>7 , moveROI_sad*u32_rimRatio>>7 ,
	stillNonROI_cnt*u32_rimRatio>>7, stillNonROI_sad*u32_rimRatio>>7,
	s_pContext->_output_read_comreg.u16_mc_Hdtl_cnt*u32_rimRatio>>7, s_pContext->_output_read_comreg.u16_mc_Vdtl_cnt*u32_rimRatio>>7,
	s_pContext->_output_read_comreg.u20_me_rDTL_rb[17],s_pContext->_output_read_comreg.u20_me_rDTL_rb[18],s_pContext->_output_read_comreg.u20_me_rDTL_rb[19], s_pContext->_output_read_comreg.u20_me_rDTL_rb[17]*u32_rimRatio>>7,
	s_pContext->_output_read_comreg.u17_me_ZMV_cnt_rb*u32_rimRatio>>7, s_pContext->_output_read_comreg.u17_me_ZMV_dtl_cnt_rb*u32_rimRatio>>7);
#endif
}

VOID MEMC_Simple_Scene_Detect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	
	UINT32 u32_i;
	SINT16 cond_sad_cnt = 0, cond_dtl_cnt = 0, cond_dhconf_cnt = 0;
	SINT16 cond_dtl_zero_cnt = 0, cond_dhconf_zero_cnt = 0;
	SINT16 cond_sad_score = 0, cond_dtl_score = 0, cond_dhconf_score = 0, cond_dhconf_zero_score = 0;

	UINT32 cur_simple_scene_score = 0;
	
	SINT16 s11_1st_gmv_mvx = (s_pContext->_output_read_comreg.s11_me_GMV_1st_vx_rb)>>2;
	SINT16 s10_1st_gmv_mvy = (s_pContext->_output_read_comreg.s10_me_GMV_1st_vy_rb)>>2;
	SCHAR  s6_1st_gmv_cnt  = s_pContext->_output_read_comreg.u6_me_GMV_1st_cnt_rb;
	
	SINT16 s11_2nd_gmv_mvx = (s_pContext->_output_read_comreg.s11_me_GMV_2nd_vx_rb)>>2;
	SINT16 s10_2nd_gmv_mvy = (s_pContext->_output_read_comreg.s10_me_GMV_2nd_vy_rb)>>2;
	SCHAR  s6_2nd_gmv_cnt  = s_pContext->_output_read_comreg.u6_me_GMV_2nd_cnt_rb;

	
	for (u32_i = 0; u32_i < 32; u32_i ++)
	{
		if (s_pContext->_output_read_comreg.u25_me_rSAD_rb[u32_i] < 0x4800)
		{
			cond_sad_cnt++;
		}

		if (s_pContext->_output_read_comreg.u20_me_rDTL_rb[u32_i] < 0x5000)
		{
			cond_dtl_cnt++;
		}
		
		if (s_pContext->_output_read_comreg.u20_me_rDTL_rb[u32_i] == 0)
		{
			cond_dtl_zero_cnt++;
		}
		
		if (s_pContext->_output_read_comreg.u20_dh_pfvconf[u32_i] < 0x8000)
		{
			cond_dhconf_cnt++;
		}
		
		if (s_pContext->_output_read_comreg.u20_dh_pfvconf[u32_i] == 0)
		{
			cond_dhconf_zero_cnt++;
		}
	}

/*
score
     |         
64  |---- .  .  .  .
     |      .  |
     |   .16  |
0   |.____________
     24      28      32  cnt
*/
	cond_sad_score = _IncreaseCurveMapping(cond_sad_cnt, 24, 0, 64, 16, 0);
	cond_dtl_score = _IncreaseCurveMapping(cond_dtl_cnt, 24, 0, 64, 16, 0);
	cond_dhconf_score = _IncreaseCurveMapping(cond_dhconf_cnt, 24, 0, 64, 16, 0);
	
	cond_dhconf_zero_score = _IncreaseCurveMapping(cond_dhconf_zero_cnt, 16, 0, 64, 8, 0);

	if (_ABS_(s11_1st_gmv_mvx) <= 1 && _ABS_(s10_1st_gmv_mvy) <= 1 && s6_1st_gmv_cnt >= 30 && cond_dtl_zero_cnt >= 2)
	{
		cur_simple_scene_score = cond_sad_score + cond_dtl_score + cond_dhconf_score + cond_dhconf_zero_score;
	}
	cur_simple_scene_score = (_CLIP_(cur_simple_scene_score, 0, 256)<<8);

	pOutput->u16_simple_scene_score_pre = ((pOutput->u16_simple_scene_score_pre*248+cur_simple_scene_score*8+128)>>8);

#if 0
	printk("[MEMC]:%2x:%2x(%2x) %2x(%2x):%2x(%2x)%2x:%2x(%2x):%2x(%2x) %2x,%3x\n\r", 
		_ABS_(s11_1st_gmv_mvx), _ABS_(s10_1st_gmv_mvy), s6_1st_gmv_cnt, 
		cond_sad_cnt, cond_sad_score, 
		cond_dtl_cnt, cond_dtl_score, cond_dtl_zero_cnt, 
		cond_dhconf_cnt, cond_dhconf_score, 
		cond_dhconf_zero_cnt, cond_dhconf_zero_score, 
		(cur_simple_scene_score>>8), ((pOutput->u16_simple_scene_score_pre+128)>>8));
#endif
}

