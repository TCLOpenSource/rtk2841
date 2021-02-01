#ifndef _ME_SCENE_ANALYSIS_DEF_H
#define _ME_SCENE_ANALYSIS_DEF_H


typedef struct  
{
	UBYTE  u1_RepeatPattern_en;
	UBYTE  u1_LightSword_en;
	UBYTE  u1_BigAPLDiff_en;

	// casino
	UINT32 u16_casino_rimLft_th;
	UINT32 u16_casino_rimRht_th;
	UINT32 u16_casino_rimUp_th;
	UINT32 u16_casino_rimDn_th;
	UBYTE  u8_casino_rim_delta;
	UBYTE  u1_casino_RP_DetCtrl;

	UBYTE  u1_EPG_en;
	
}_PARAM_ME_SCENE_ANALYSIS;

/*
	SMART INTEGRATION STATUS (SIS) for MEMC ver. by LearnRPG@20150911

	Collection and combination all those status by long time experience.
	We suggest in kernal API don't have below code
	(that's mean kernal API must independent operation)
	1. no global variable, must use function parameter be input.
	2. don't change global status in function, must use middle layer to update status.

*/

typedef struct _MemcStatus
{
/*
	UINT32 reg_vbuf_ph_1st_lfsr_mask_x;
	UINT32 reg_vbuf_ph_1st_lfsr_mask_y;
	UINT32 reg_vbuf_ph_2nd_lfsr_mask_x;
	UINT32 reg_vbuf_ph_2nd_lfsr_mask_y;

	UINT32 reg_vbuf_ip_1st_lfsr_mask_x;
	UINT32 reg_vbuf_ip_1st_lfsr_mask_y;
	UINT32 reg_vbuf_ip_2nd_lfsr_mask_x;
	UINT32 reg_vbuf_ip_2nd_lfsr_mask_y;

	UINT32 reg_vbuf_pi_1st_lfsr_mask_x;
	UINT32 reg_vbuf_pi_1st_lfsr_mask_y;
	UINT32 reg_vbuf_pi_2nd_lfsr_mask_x;
	UINT32 reg_vbuf_pi_2nd_lfsr_mask_y;

	UINT32 reg_metop_ss_ip_update0_penalty;
	UINT32 reg_metop_ss_ip_update1_penalty;
	UINT32 reg_metop_ss_pi_update0_penalty;
	UINT32 reg_metop_ss_pi_update1_penalty;
	UINT32 reg_metop_ss_ph_update0_penalty;
	UINT32 reg_metop_ss_ph_update1_penalty;

	UINT32 reg_metop_ds_ip_update0_penalty;
	UINT32 reg_metop_ds_ip_update1_penalty;
	UINT32 reg_metop_ds_pi_update0_penalty;
	UINT32 reg_metop_ds_pi_update1_penalty;
	UINT32 reg_metop_ds_ph_update0_penalty;
	UINT32 reg_metop_ds_ph_update1_penalty;

	UBYTE  u3_ip_1st_cand1_offsetx;
	UBYTE  u3_ip_1st_cand5_offsetx;
	UBYTE  u3_ip_1st_update1_offsetx;
	UBYTE  u3_pi_1st_cand1_offsetx;
	UBYTE  u3_pi_1st_cand5_offsetx;
	UBYTE  u3_pi_1st_update1_offsetx;
	UBYTE  u3_ph_1st_cand1_offsetx;
	UBYTE  u3_ph_1st_cand2_offsetx;
	UBYTE  u3_ph_1st_cand2_offsety;
	UBYTE  u3_ph_1st_cand5_offsetx;
	UBYTE  u3_ph_1st_update1_offsetx;

	UBYTE  u3_ip_2nd_cand1_offsetx;
	UBYTE  u3_ip_2nd_cand5_offsetx;
	UBYTE  u3_ip_2nd_update1_offsetx;
	UBYTE  u3_pi_2nd_cand1_offsetx;
	UBYTE  u3_pi_2nd_cand5_offsetx;
	UBYTE  u3_pi_2nd_update1_offsetx;
	UBYTE  u3_ph_2nd_cand1_offsetx;
	UBYTE  u3_ph_2nd_cand2_offsetx;
	UBYTE  u3_ph_2nd_cand2_offsety;
	UBYTE  u3_ph_2nd_cand5_offsetx;
	UBYTE  u3_ph_2nd_update1_offsetx;
	
	UINT32 reg_mc_var_lpf_en;
	UINT32 reg_mc_var_lpf_mvd_x_th;

	UBYTE reg_metop_sad_th_mode_sel;
	UBYTE reg_metop_ss_ip_penalty_g;
	UBYTE reg_metop_ss_pi_penalty_g;
	UBYTE reg_metop_ss_ph_penalty_g;
	UBYTE reg_metop_ds_ip_penalty_g;
	UBYTE reg_metop_ds_pi_penalty_g;
	UBYTE reg_metop_ds_ph_penalty_g;
	
	UBYTE reg_metop_ss_ip_penalty_z;
	UBYTE reg_metop_ss_pi_penalty_z;
	UBYTE reg_metop_ss_ph_penalty_z;
	UBYTE reg_metop_ds_ip_penalty_z;
	UBYTE reg_metop_ds_pi_penalty_z;
	UBYTE reg_metop_ds_ph_penalty_z;
	
	UBYTE reg_dh_empty_proc_en;

	UINT32 reg_metop_sc_clr_saddiff_th;
	UBYTE reg_pql_fb_tc_iir;
	
        //RO reg
	UINT32 u25_rdbk_dtl_all;
	UINT32 u25_rdbk_dtl_all_pre;
	UINT32 u25_rdbk_dtl_all_intervel5;
	UINT32 u25_rdbk_dtl_all_intervel5_pre;
	UBYTE  u8_rgn_apl_p_rb[32];
	UBYTE  u8_rgn_apl_p_rb_pre[32];

	//analysis result
	UBYTE u1_apl_inc;	
	UBYTE u1_apl_dec;
*/	

	UBYTE reg_vbuf_ip_1st_lfsr_mask2_x;

	UBYTE reg_vbuf_ip_1st_update1_en;
	UBYTE reg_vbuf_ip_1st_update2_en;
	UBYTE reg_vbuf_ip_1st_update3_en;
	UBYTE reg_vbuf_pi_1st_update1_en;
	UBYTE reg_vbuf_pi_1st_update2_en;
	UBYTE reg_vbuf_pi_1st_update3_en;
	// candidate penalty
	UBYTE reg_me1_ip_cddpnt_rnd0;
	UBYTE reg_me1_ip_cddpnt_rnd1;
	UBYTE reg_me1_ip_cddpnt_rnd2;
	UBYTE reg_me1_pi_cddpnt_rnd0;
	UBYTE reg_me1_pi_cddpnt_rnd1;
	UBYTE reg_me1_pi_cddpnt_rnd2;
	
	UBYTE reg_frame_meander_enable;
	UBYTE reg_me1_gmv_sel;

	UINT32 u25_rdbk_dtl_all;
	UINT32 u25_rdbk_dtl_all_pre;
	UINT32 u25_rdbk_dtl_all_intervel5;
	UINT32 u25_rdbk_dtl_all_intervel5_pre;

	BOOL reg_mc_scene_change_fb;
	UINT32 reg_me1_sc_saddiff_th;

	UBYTE   u8_dynME_acdc_bld_x_act[3];
	UBYTE   u6_dynME_acdc_bld_y_act[3];
	SINT16  s9_dynME_acdc_bld_s_act[2];
	UBYTE   u8_dynME_ac_pix_sad_limt_act;
	UBYTE   u4_acdc_bld_psad_shift_act;

}MemcStatus;

typedef struct _ScalerMEMCGlobalStatus
{
	MemcStatus MEMC_STATUS;

	UINT32 Frame_Couter;
	
} ScalerMEMCGlobalStatus;

typedef struct  
{		
	ScalerMEMCGlobalStatus SIS_MEMC;

	UBYTE u1_RP_detect_true;
	UBYTE u1_casino_RP_detect_true;
	UINT32 u32_new_saddiff_th;
	UINT32 u32_new_saddiff_th_pre;
        int   s10_me_GMV_1st_vy_rb_iir;
	UBYTE  u6_me_GMV_1st_cnt_rb_iir;
	UINT32 u12_me_GMV_1st_unconf_rb_iir;
	UBYTE  u1_chaos_true;
        UBYTE  u8_chaos_apply;
	UBYTE   u8_big_apldiff_hold_cnt;
	UBYTE  u1_ToL10_RP_true;
	UINT32  u32_glb_sad_pre;
	UINT32	u32_big_apldiff_saddiff_th;	
	UBYTE	u8_big_apldiff_sc_hold_cnt;
	UINT32	u32_big_apldiff_sad_pre;
	UBYTE u8_EPG_apply;
	UBYTE u8_EPG_moveROI;
	UINT32  u16_simple_scene_score_pre;
	
}_OUTPUT_ME_SCENE_ANALYSIS;

VOID Me_sceneAnalysis_Init(_OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID Me_sceneAnalysis_Proc_OutputIntp(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput, SINT32 iSliceIdx);

VOID MEMC_MiddleWare_StatusInit(_OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID MEMC_MiddleWare_Reg_Status_Cad1(_OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID MEMC_MiddleWare_StatusUpdate(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput, SINT32 iSliceIdx);

VOID MEMC_LightSwordDetect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID MEMC_RepeatPattern_detect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID MEMC_SaddiffTh_calc(_OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID MEMC_Big_APLDiff_Detect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID MEMC_EPG_Protect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput);
VOID MEMC_Simple_Scene_Detect(const _PARAM_ME_SCENE_ANALYSIS *pParam, _OUTPUT_ME_SCENE_ANALYSIS *pOutput);

/////////////////////////////////////////////////////////////////////////////

DEBUGMODULE_BEGIN(_PARAM_ME_SCENE_ANALYSIS,_OUTPUT_ME_SCENE_ANALYSIS)
 //   ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u1_RepeatPattern_en,         1, "")
	ADD_PARAM_DES(UBYTE,  u1_LightSword_en,         1, "")	
	ADD_PARAM_DES(UBYTE,  u1_BigAPLDiff_en,		 1, "")
DEBUGMODULE_END

#endif


