#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/PQLGlobalDefs.h"

VOID Wrt_7segment_show(const _PARAM_WRT_COM_REG *pParam)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32  u32_wrt_data, u32_wrt_data2;

	if (pParam->u8_show7seg_mode == 0)  //common show
	{
		// 7seg_0

	//	u32_wrt_data = (s_pContext->_output_read_comreg.u3_ipme_filmMode_rb >> 1);
		UINT32 u32_cad_data = 0;
		u32_cad_data = ((s_pContext->_output_filmDetectctrl.u1_mixMode == 1) ? 0xF : s_pContext->_output_filmDetectctrl.u8_cur_cadence_Id[_FILM_ALL])&0xF;
	    	u32_wrt_data = ((u32_cad_data<<4) | (s_pContext->_output_filmDetectctrl.u8_cur_cadence_out[_FILM_ALL]&0xF)) & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 0, 7, u32_wrt_data);

		u32_wrt_data = _MIN_(s_pContext->_output_frc_phtable.u8_deblur_lvl_pre >> 3, 0x0F);	
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 8, 11, u32_wrt_data);

		u32_wrt_data = _MIN_(s_pContext->_output_frc_phtable.u8_dejudder_lvl_pre >> 3, 0x0F);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 12, 15, u32_wrt_data);

		// 7seg_1
			u32_wrt_data = s_pContext->_output_wrt_comreg.u8_FB_lvl;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 16, 23, u32_wrt_data);

		u32_wrt_data = s_pContext->_output_mc_lbmcswitch.u8_lf_lbmcMode;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 24, 27, u32_wrt_data);

		u32_wrt_data = s_pContext->_output_dh_close.u1_closeDh_act;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 28, 31, u32_wrt_data);

		// 7seg_2 SceneAnalysis
		//  fadeIn/out
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_cnt_alpha,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 3, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_acdc_sad_alpha,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 4, 7, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_bv_sad_alpha,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 11, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_conf,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 12, 15, u32_wrt_data);

		//gmv SR
		//u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u8_ME1_searchRange_x,0,255);  //x
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 7, u32_wrt_data);
		//u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u8_ME1_searchRange_y,0,255);  //y
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 15, u32_wrt_data);

		// 7seg_3, //// logo clear flag.
		u32_wrt_data = s_pContext->_output_FRC_LgDet.u1_blkclr_glbstatus;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 16, u32_wrt_data);

		//u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_apl_diff_alpha,0,15);
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 28, 31, u32_wrt_data);

		RTKReadRegister(0xB80282E4, &u32_wrt_data);               
		u32_wrt_data = (270000000/(u32_wrt_data+1))+5;
		
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 27, (u32_wrt_data/10)%10);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 28, 31, (u32_wrt_data/10)/10);

		//u32_wrt_data = s_pContext->_output_FRC_LgDet.u1_blkclr_glbstatus;
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 16, u32_wrt_data);   //x
		//u32_wrt_data = _CLIP_UBOUND_(s_pContext->_output_frc_sceneAnalysis.u2_searchRange_x_status,15);
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 27, u32_wrt_data);
		//u32_wrt_data = _CLIP_UBOUND_(s_pContext->_output_frc_sceneAnalysis.u2_searchRange_y_status,15);  //y
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 28, 31, u32_wrt_data);

		//dehalo close
		u32_wrt_data = s_pContext->_output_dh_close.u1_panning_close;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 20, 23, u32_wrt_data);

		//logo
		u32_wrt_data = s_pContext->_output_FRC_LgDet.u1_blkclr_glbstatus;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 19, u32_wrt_data);

	}
	else if (pParam->u8_show7seg_mode == 1) // for boundary
	{
		// 7seg_0
		//avgSC
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgSc/32, 0, 255)  & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 0, 7, u32_wrt_data);
		//avgTc
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgTc/32,0,255) & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 8, 15, u32_wrt_data);

		//boundary small
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u8_BdySmall_lft_cnt,0,15) & 0x0F;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 16, 19, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u8_BdySmall_rht_cnt,0,15) & 0x0F;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 20, 23, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u8_dynSAD_Diff_Gain,0,255) & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 24, 31, u32_wrt_data);

		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u8_is_insidePan,0,1);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 3, u32_wrt_data);

		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u1_is_saddiff_large,0,1);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 4, 7, u32_wrt_data);

		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgAbsMVY/8,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 11,  u32_wrt_data);

		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u32_insidePan_avgAbsMVX/8,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 12, 15, u32_wrt_data);


		u32_wrt_data =  s_pContext->_output_dh_close.u1_closeDh_act;
		//u32_wrt_data = u32_wrt_data == 1 ? 0 : 1;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 28, 31,u32_wrt_data);

		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u1_is_BdySmall_MV,0,1);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 27,u32_wrt_data);

		u32_wrt_data = s_pContext->_output_dh_close.u1_panning_close;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 20, 23, u32_wrt_data);

		//logo
		u32_wrt_data = s_pContext->_output_FRC_LgDet.u1_blkclr_glbstatus;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 19,u32_wrt_data);

	}
	else if(pParam->u8_show7seg_mode == 2)  //fade in out
	{
		// 7seg_0 SceneAnalysis
		u32_wrt_data = s_pContext->_output_me_sceneAnalysis.u1_casino_RP_detect_true;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 0, 3, u32_wrt_data);

		u32_wrt_data = s_pContext->_output_me_sceneAnalysis.u1_RP_detect_true;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 4, 7, u32_wrt_data);

		u32_wrt_data = s_pContext->_output_me_sceneAnalysis.u1_ToL10_RP_true;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 8, 11, u32_wrt_data);

		u32_wrt_data = s_pContext->_external_info.u1_PictureMode_Chg;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 12, 15, u32_wrt_data);

		// 7seg_1 SceneAnalysis

		// 7seg_2 SceneAnalysis
		//  fadeIn/out
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_cnt_alpha,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 3, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_cnt_Thr_alpha,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 4, 7, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_apl_diff_alpha,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 11, u32_wrt_data);
		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u4_fadeInOut_conf_iir,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 12, 15, u32_wrt_data);

		// 7seg_3, //// logo clear flag.
		u32_wrt_data = s_pContext->_output_FRC_LgDet.u1_blkclr_glbstatus;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 16, u32_wrt_data);     //x

		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u2_searchRange_y_status,0,15);  //y	
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 28, 31, u32_wrt_data);

		//u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u2_searchRange_x_status,0,15);
		//WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 27, u32_wrt_data);

		u32_wrt_data = _CLIP_(s_pContext->_output_frc_sceneAnalysis.u5_dc_ac_bld_alpha,0,15);
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 27, u32_wrt_data);

		u32_wrt_data = s_pContext->_output_dh_close.u1_closeDh_act;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 20, 23, u32_wrt_data);
	}
	else if (pParam->u8_show7seg_mode == 3)
	{
		u32_wrt_data = s_pContext->_output_frc_sceneAnalysis.s2m_12_cnt_iir  & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 0, 7, u32_wrt_data);

		u32_wrt_data = _MIN_(_ABS_(s_pContext->_output_frc_sceneAnalysis.s2m_1st_mvx)/4, 255) & 0xFF;	
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_0_ADDR, 8, 15, u32_wrt_data);

		u32_wrt_data = _MIN_(_ABS_(s_pContext->_output_frc_sceneAnalysis.s2m_1st_mvy)/4, 255) & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 16, 23, u32_wrt_data);

		u32_wrt_data = _MIN_(_ABS_(s_pContext->_output_frc_sceneAnalysis.s2m_2nd_mvx)/8, 15) & 0xF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 24, 27, u32_wrt_data);

		u32_wrt_data = _MIN_(_ABS_(s_pContext->_output_frc_sceneAnalysis.s2m_2nd_mvy)/8, 15) & 0xF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_1_ADDR, 28, 31, u32_wrt_data);

		//goodGMVcnt
		u32_wrt_data = _CLIP_UBOUND_(s_pContext->_output_frc_sceneAnalysis.u8_goodGmv_cnt, 255)  & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 0, 7, u32_wrt_data);
		//diffGMVcnt
		u32_wrt_data = _CLIP_UBOUND_(s_pContext->_output_frc_sceneAnalysis.u8_diffGmv_cnt,255) & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_2_ADDR, 8, 15, u32_wrt_data);

		//
		u32_wrt_data = _CLIP_UBOUND_(s_pContext->_output_frc_sceneAnalysis.s2m_1st_cnt, 255)  & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 23, u32_wrt_data);

		u32_wrt_data = _CLIP_UBOUND_(s_pContext->_output_frc_sceneAnalysis.s2m_2nd_cnt, 255)  & 0xFF;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 31, u32_wrt_data);
	}
	else if(pParam->u8_show7seg_mode == 4)
	{

		u32_wrt_data = s_pContext->_output_me_sceneAnalysis.u8_EPG_apply>0;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 28, 31, u32_wrt_data);

		u32_wrt_data = s_pContext->_output_Patch_Manage.u1_patch_highFreq_rp_true;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 24, 27,u32_wrt_data);

		u32_wrt_data = s_pContext->_output_Patch_Manage.u1_patch_highFreq_zmv_true;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 20, 23, u32_wrt_data);
		
		u32_wrt_data = s_pContext->_output_FRC_LgDet.u1_lg_UXN_patch_det;
		WriteRegister(FRC_TOP__KPOST_TOP__reg_post_seg_disp_data_3_ADDR, 16, 19, u32_wrt_data);
	}
   
}

VOID mc_lbmcMode_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UBYTE u8_lf_lbmcMode = s_pContext->_output_mc_lbmcswitch.u8_lf_lbmcMode;
	UBYTE u8_hf_lbmcMode = s_pContext->_output_mc_lbmcswitch.u8_hf_lbmcMode;

	if (pParam->u1_mc_lbmcMode_en == 1)
	{
		if (u8_lf_lbmcMode != pOutput->u8_lf_lbmcMode_pre)
		{
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_force_mc_mode), u8_lf_lbmcMode);
			pOutput->u8_lf_lbmcMode_pre = u8_lf_lbmcMode;
		}

		if (u8_hf_lbmcMode != pOutput->u8_hf_lbmcMode_pre)
		{
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_force_mc_mode_hf), u8_hf_lbmcMode);
			pOutput->u8_hf_lbmcMode_pre = u8_hf_lbmcMode;
		}
	}
}

VOID scCtrl_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	static UBYTE u1_ori_sc_me1_en = 0;
	static BOOL u1_sc_me1_en_chg = 0;

	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE  u8_cadence_Id = s_pContext->_output_filmDetectctrl.u8_cur_cadence_out[_FILM_ALL];
	PQL_INPUT_FRAME_RATE in_fmRate = s_pContext->_external_data._input_frameRate;

	if(pParam->u1_scCtrl_wrt_en == 0)
		return;
	
	if(s_pContext->_external_info.s16_speed == 256 || s_pContext->_external_info.s16_speed == -256)  // normal speed
	{
		if(u1_sc_me1_en_chg  == 1) //need to recovery
		{
			WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_en),  u1_ori_sc_me1_en);
			u1_sc_me1_en_chg = 0;
		}
	}
	else 
	{
		UINT32 u32_RB_val;
		if(u1_sc_me1_en_chg  == 0) 
		{
			ReadRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_en), &u32_RB_val);
			u1_ori_sc_me1_en = u32_RB_val;
			u1_sc_me1_en_chg = 1;
		}
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_en), 0);
	}
	
	if(s_pContext->_external_data._output_mode != _PQL_OUT_PC_MODE)
	{
		if(s_pContext->_output_frc_sceneAnalysis.u8_VOSeek_prt_apply>0)// add by LRL for VO_seek SC blending ghost @20161124 
		{
	                WriteRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, 0x0);
		}
		else if (s_pContext->_output_frc_phtable.u1_is_inFormat_PureVideo)// video cadence case use large threshold to prevent easy scene change for moving video text
		{
			WriteRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, 0x0);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th_ADDR, 0, 30, 0x980000);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_hold_cnt_ADDR, 0, 7, 0x2);
		}
		else if(s_pContext->_output_me_sceneAnalysis.u8_big_apldiff_hold_cnt != 0)
		{
			if(s_pContext->_output_frc_sceneAnalysis.u1_specialscfb_true)
				WriteRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, 0x0);
			else				
				WriteRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_mc_scene_change_fb);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th_ADDR, 0, 30, s_pContext->_output_me_sceneAnalysis.u32_big_apldiff_saddiff_th);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_hold_cnt_ADDR, 0, 7, s_pContext->_output_me_sceneAnalysis.u8_big_apldiff_sc_hold_cnt);
		}
		else
		{
			if(s_pContext->_output_frc_sceneAnalysis.u1_specialscfb_true)
				WriteRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, 0x0);
			else
				WriteRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_mc_scene_change_fb);
			WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th_ADDR, 0, 30, s_pContext->_output_me_sceneAnalysis.u32_new_saddiff_th);
		
			if (u8_cadence_Id == _CAD_22 || (in_fmRate == _PQL_IN_25HZ && u8_cadence_Id == _CAD_VIDEO))
			{
				WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_hold_cnt_ADDR, 0, 7, 0x1);
			}
			else
			{
				WriteRegister(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_me1_hold_cnt_ADDR, 0, 7, 0x2);
			}
		}
	}	
	else
	{
		UBYTE u8_scfb = 0;
		ReadRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, &u8_scfb);
		if(u8_scfb)
		{
			LogPrintf(DBG_ERROR, "err: PC mode but sc fb not disable.\n");
			WriteRegister(FRC_TOP__MC__reg_mc_scene_change_fb_ADDR, 10, 10, 0x0);
		}
	}
	
}

VOID fbCtrl_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	UINT32 u8_flbk_lvl_wrt = (UINT32)(s_pContext->_output_fblevelctrl.u8_FBLevel);
	UBYTE  u8_flbk_system = s_pContext->_output_fblevelctrl.u8_FBSystem;

	UBYTE  u8_flbk_lvl_FB_FF_Speed = (s_pContext->_external_info.s16_speed != 256 && s_pContext->_external_info.s16_speed != -256) ? _FB_LEVEL_MAX_ : 0;
	UBYTE  u8_flbk_lvl_zoom = (s_pContext->_output_frc_sceneAnalysis.u8_zoom_force_fb_cnt != 0) ? _FB_LEVEL_MAX_ : 0;

	u8_flbk_lvl_wrt = _MAX_(_MAX_(_MAX_(u8_flbk_lvl_FB_FF_Speed
						, u8_flbk_lvl_zoom)
						, u8_flbk_system)
						, u8_flbk_lvl_wrt);

	pOutput->u8_FB_lvl = u8_flbk_lvl_wrt;
	
	if (pParam->u1_FBLevelWr_en == 1)
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_bld_flbk_lvl), u8_flbk_lvl_wrt);
	}

	if(pParam->u1_bigFBlvl_dis_SCdet_en == 1)
	{
		UBYTE u1_disable_saddiff_sc = s_pContext->_output_fblevelctrl.u3_FbLvl_dSCclr_wrt;
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_en), u1_disable_saddiff_sc);	
	}
}

VOID Vbuf_LFSR_updStgh_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
 	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//_PQLPARAMETER *s_pParam       = GetPQLParameter();

	if(pParam->u1_MEUpdStgh_wrt_en== 0)
		return;


	if(s_pContext->_output_me_sceneAnalysis.u1_RP_detect_true == 1 || s_pContext->_output_Patch_Manage.u1_patch_highFreq_rp_true)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_lfsr_mask2_x), 0x1);
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_lfsr_mask2_x), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_lfsr_mask2_x);
	}
}
VOID RimCtrl_wrtAction(const _PARAM_WRT_COM_REG *pParam)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	if (pParam->u1_RimCtrl_wrt_en == 1 && (s_pContext->_output_rimctrl.u1_RimChange == 1))
	{
		// MC
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_top_rim1), s_pContext->_output_rimctrl.u12_mc_rim1[_RIM_TOP]); // Rim1
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_bot_rim1), s_pContext->_output_rimctrl.u12_mc_rim1[_RIM_BOT]);
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_lft_rim1), s_pContext->_output_rimctrl.u12_mc_rim1[_RIM_LFT]);
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_rht_rim1), s_pContext->_output_rimctrl.u12_mc_rim1[_RIM_RHT]);

		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_top_rim0), s_pContext->_output_rimctrl.u12_mc_rim0[_RIM_TOP]); // Rim0
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_bot_rim0), s_pContext->_output_rimctrl.u12_mc_rim0[_RIM_BOT]);
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_lft_rim0), s_pContext->_output_rimctrl.u12_mc_rim0[_RIM_LFT]);
		WriteRegister(KIWI_REG(FRC_TOP__MC__reg_mc_rht_rim0), s_pContext->_output_rimctrl.u12_mc_rim0[_RIM_RHT]);

		// LOGO
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blk_rim_h0), s_pContext->_output_rimctrl.u8_LogoRim_Blk[_RIM_LFT]); // BLOCK
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blk_rim_h1), s_pContext->_output_rimctrl.u8_LogoRim_Blk[_RIM_RHT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blk_rim_v0), s_pContext->_output_rimctrl.u8_LogoRim_Blk[_RIM_TOP]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blk_rim_v1), s_pContext->_output_rimctrl.u8_LogoRim_Blk[_RIM_BOT]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrim_h0), s_pContext->_output_rimctrl.u12_LogoRim_Pxl[_RIM_LFT]); // PIXEL
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrim_h1), s_pContext->_output_rimctrl.u12_LogoRim_Pxl[_RIM_RHT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrim_v0), s_pContext->_output_rimctrl.u12_LogoRim_Pxl[_RIM_TOP]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrim_v1), s_pContext->_output_rimctrl.u12_LogoRim_Pxl[_RIM_BOT]);

		// Dehalo
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_left_ofst),  s_pContext->_output_rimctrl.u9_dh_blk_rim[_RIM_LFT]); // Dehalo retimer rim.
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_right_ofst), s_pContext->_output_rimctrl.u9_dh_blk_rim[_RIM_RHT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_top_ofst),   s_pContext->_output_rimctrl.u9_dh_blk_rim[_RIM_TOP]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_bot_ofst),   s_pContext->_output_rimctrl.u9_dh_blk_rim[_RIM_BOT]);

		// IPME
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_rim_v0), s_pContext->_output_rimctrl.u12_ipme_rim[_RIM_TOP]); // IPME
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_rim_v1), s_pContext->_output_rimctrl.u12_ipme_rim[_RIM_BOT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_rim_h0), s_pContext->_output_rimctrl.u12_ipme_rim[_RIM_LFT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_rim_h1), s_pContext->_output_rimctrl.u12_ipme_rim[_RIM_RHT]);

		// ME1
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_top),   s_pContext->_output_rimctrl.u12_me1_vbuf_blk_rim[_RIM_TOP]); //blk rim
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_bot),   s_pContext->_output_rimctrl.u12_me1_vbuf_blk_rim[_RIM_BOT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_left),  s_pContext->_output_rimctrl.u12_me1_vbuf_blk_rim[_RIM_LFT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_right), s_pContext->_output_rimctrl.u12_me1_vbuf_blk_rim[_RIM_RHT]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pix_rim_top),  s_pContext->_output_rimctrl.u12_me1_vbuf_pix_rim[_RIM_TOP]); //pixel rim
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pix_rim_bot),  s_pContext->_output_rimctrl.u12_me1_vbuf_pix_rim[_RIM_BOT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pix_rim_left), s_pContext->_output_rimctrl.u12_me1_vbuf_pix_rim[_RIM_LFT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pix_rim_right),s_pContext->_output_rimctrl.u12_me1_vbuf_pix_rim[_RIM_RHT]);

		// disable LBME rim, by Heng, 03/14.2016. meander protect.
//		WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_y_start),  s_pContext->_output_rimctrl.u12_me1_lbme_rim[_RIM_TOP]); //LBME pixel rim
//		WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_y_end),    s_pContext->_output_rimctrl.u12_me1_lbme_rim[_RIM_BOT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_x_start),  s_pContext->_output_rimctrl.u12_me1_lbme_rim[_RIM_LFT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_x_end),    s_pContext->_output_rimctrl.u12_me1_lbme_rim[_RIM_RHT]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_meander_blk_rim_top), s_pContext->_output_rimctrl.u12_me1_vbuf_meander_blk_rim[_RIM_TOP]); //meander rim
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_meander_blk_rim_bot), s_pContext->_output_rimctrl.u12_me1_vbuf_meander_blk_rim[_RIM_BOT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_meander_pix_rim_top), s_pContext->_output_rimctrl.u12_me1_vbuf_meander_pix_rim[_RIM_TOP]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_vbuf_meander_pix_rim_bot), s_pContext->_output_rimctrl.u12_me1_vbuf_meander_pix_rim[_RIM_BOT]);

		// ME2
//		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_left),  s_pContext->_output_rimctrl.u12_me2_vbuf_pfv_blk_rim[_RIM_LFT]); // pfv blk rim
//		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_right), s_pContext->_output_rimctrl.u12_me2_vbuf_pfv_blk_rim[_RIM_RHT]);
//		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_top),   s_pContext->_output_rimctrl.u12_me2_vbuf_pfv_blk_rim[_RIM_TOP]);
//		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_bot),   s_pContext->_output_rimctrl.u12_me2_vbuf_pfv_blk_rim[_RIM_BOT]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_ph_blk_rim_left),  s_pContext->_output_rimctrl.u12_me2_vbuf_ph_blk_rim[_RIM_LFT]); // ph blk rim
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_ph_blk_rim_right), s_pContext->_output_rimctrl.u12_me2_vbuf_ph_blk_rim[_RIM_RHT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_ph_blk_rim_top),   s_pContext->_output_rimctrl.u12_me2_vbuf_ph_blk_rim[_RIM_TOP]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_ph_blk_rim_bot),   s_pContext->_output_rimctrl.u12_me2_vbuf_ph_blk_rim[_RIM_BOT]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pix_rim_left),  s_pContext->_output_rimctrl.u12_me2_vbuf_pix_rim[_RIM_LFT]); // pixel
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pix_rim_right), s_pContext->_output_rimctrl.u12_me2_vbuf_pix_rim[_RIM_RHT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pix_rim_top),   s_pContext->_output_rimctrl.u12_me2_vbuf_pix_rim[_RIM_TOP]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pix_rim_bot),   s_pContext->_output_rimctrl.u12_me2_vbuf_pix_rim[_RIM_BOT]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_rim_x_start), s_pContext->_output_rimctrl.u12_me2_lbme_rim[_RIM_LFT]); // lbme2
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_rim_x_end),   s_pContext->_output_rimctrl.u12_me2_lbme_rim[_RIM_RHT]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_rim_y_start), s_pContext->_output_rimctrl.u12_me2_lbme_rim[_RIM_TOP]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_rim_y_end),   s_pContext->_output_rimctrl.u12_me2_lbme_rim[_RIM_BOT]);


		//me2 vbuf2 oor
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_orr_cnt_th),  s_pContext->_output_rimctrl.me2_oor_cnt);

		// 5region & 12region
		UINT32 u32_rb_val = 0;
		u32_rb_val = ((s_pContext->_output_rimctrl.u12_5Rgn1_v1)<<10)+s_pContext->_output_rimctrl.u12_5Rgn1_v0;
		WriteRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region1_v0_ADDR), 0, 31, u32_rb_val);
		u32_rb_val = ((s_pContext->_output_rimctrl.u12_5Rgn2_v1)<<10)+s_pContext->_output_rimctrl.u12_5Rgn2_v0;
		WriteRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region2_v0_ADDR), 0, 31, u32_rb_val);
		u32_rb_val = ((s_pContext->_output_rimctrl.u12_5Rgn3_h1)<<10)+s_pContext->_output_rimctrl.u12_5Rgn3_h0;
		WriteRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region3_h0_ADDR), 0, 31, u32_rb_val);
		u32_rb_val = ((s_pContext->_output_rimctrl.u12_5Rgn4_h1)<<10)+s_pContext->_output_rimctrl.u12_5Rgn4_h0;
		WriteRegister((FRC_TOP__KME_IPME__reg_ipme_fmdet_5region4_h0_ADDR), 0, 31, u32_rb_val);

		// update 12rgn rim
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h0), s_pContext->_output_rimctrl.u12_12Rgn_h0);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h1), s_pContext->_output_rimctrl.u12_12Rgn_h1);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h2), s_pContext->_output_rimctrl.u12_12Rgn_h2);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h3), s_pContext->_output_rimctrl.u12_12Rgn_h3);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_h4), s_pContext->_output_rimctrl.u12_12Rgn_h4);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v0), s_pContext->_output_rimctrl.u12_12Rgn_v0);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v1), s_pContext->_output_rimctrl.u12_12Rgn_v1);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v2), s_pContext->_output_rimctrl.u12_12Rgn_v2);
		WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_fmdet_12region_v3), s_pContext->_output_rimctrl.u12_12Rgn_v3);
 

	}

	if (s_pContext->_output_rimctrl.u1_Resolution_change == 1)
	{
		WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_x_start),    s_pContext->_output_rimctrl.u12_out_resolution[_RIM_TOP]);
	    WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_x_end),      s_pContext->_output_rimctrl.u12_out_resolution[_RIM_BOT]);
	    WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_y_start),    s_pContext->_output_rimctrl.u12_out_resolution[_RIM_LFT]);
	    WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_y_end),      s_pContext->_output_rimctrl.u12_out_resolution[_RIM_RHT]);
	}
}

VOID dhLocalFbLvl_wrtAction(const _PARAM_WRT_COM_REG *pParam)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();


	UBYTE u6_localfallback_lvl = s_pParam->_param_frc_sceneAnalysis.u6_localfallback_lvl;//((U32_DATA>>24) & 0x3f);
	UBYTE u1_fastMotion_lfb_en = s_pParam->_param_frc_sceneAnalysis.u1_fastMotion_lfb_en; //((U32_DATA>>31) & 0x1); 

	if (pParam->u1_localfb_wrt_en == 0)
		return;
	
	if(s_pContext->_output_frc_sceneAnalysis.u1_fastMotion_det == 1)
	{			
		if(u1_fastMotion_lfb_en == 1)
		{
			WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_pfv_gen_force_dehalo_level2), u6_localfallback_lvl);
		}
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_pfv_gen_force_dehalo_level2), 0x20);
	}

	
}

VOID dhClose_wrtAction(const _PARAM_WRT_COM_REG *pParam)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT32 u1_dehalo_en = s_pContext->_output_dh_close.u1_closeDh_act == 1? 0 : 1;

	if (pParam->u1_dhClose_wrt_en == 1)
	{
		//new dh close, because need post-flt
		if (u1_dehalo_en == 0)
		{
			WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_pfv_gen_glb_dehalo_gain), 0);
			WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_bv0_bv1_switch),          1);
			
			//me1 to mode3, ac to mode0, max big
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_dc_obme_mode), 3);
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_dc_obme_mode), 3);
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_ac_obme_mode), 0);
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_ac_obme_mode), 0);
		}
		else
		{
			WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_pfv_gen_glb_dehalo_gain), 64);
			WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_bv0_bv1_switch),          0);

			//me1 to mode3, ac to mode0, default obme
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_dc_obme_mode), 1);
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_dc_obme_mode), 1);
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_ac_obme_mode), 1);
			WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_ac_obme_mode), 1);

			//me2 default is max
		}
	   // WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_en), u1_dehalo_en);
	}
}

VOID ME_acdcBld_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();

	if(pParam->u1_MEacdcBld_wrt_en== 0)
		return;

	if (pParam->u1_dynME_acdcBld_wrt_en == 1)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x1), s_pContext->_output_frc_sceneAnalysis.u8_dynME_acdc_bld_x_act[0]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x2), s_pContext->_output_frc_sceneAnalysis.u8_dynME_acdc_bld_x_act[1]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x3), s_pContext->_output_frc_sceneAnalysis.u8_dynME_acdc_bld_x_act[2]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y1), s_pContext->_output_frc_sceneAnalysis.u6_dynME_acdc_bld_y_act[0]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y2), s_pContext->_output_frc_sceneAnalysis.u6_dynME_acdc_bld_y_act[1]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y3), s_pContext->_output_frc_sceneAnalysis.u6_dynME_acdc_bld_y_act[2]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_slope1), s_pContext->_output_frc_sceneAnalysis.s9_dynME_acdc_bld_s_act[0]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_slope2), s_pContext->_output_frc_sceneAnalysis.s9_dynME_acdc_bld_s_act[1]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_ac_pix_sad_limt), s_pContext->_output_frc_sceneAnalysis.u8_dynME_ac_pix_sad_limt_act);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_ac_pix_sad_limt), s_pContext->_output_frc_sceneAnalysis.u8_dynME_ac_pix_sad_limt_act);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_mm_psad_norm_shft), s_pContext->_output_frc_sceneAnalysis.u4_acdc_bld_psad_shift_act);
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x1), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u8_dynME_acdc_bld_x_act[0]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x2), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u8_dynME_acdc_bld_x_act[1]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_x3), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u8_dynME_acdc_bld_x_act[2]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y1), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u6_dynME_acdc_bld_y_act[0]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y2), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u6_dynME_acdc_bld_y_act[1]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_y3), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u6_dynME_acdc_bld_y_act[2]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_slope1), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .s9_dynME_acdc_bld_s_act[0]);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_psad_alp_slope2), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .s9_dynME_acdc_bld_s_act[1]);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_ac_pix_sad_limt), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u8_dynME_ac_pix_sad_limt_act);
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_ac_pix_sad_limt), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u8_dynME_ac_pix_sad_limt_act);

		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP0__reg_me1_mm_psad_norm_shft), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS .u4_acdc_bld_psad_shift_act);
	}
}

VOID ME_dynSR_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();

	if(s_pContext->_output_frc_sceneAnalysis.u1_still_frame || s_pContext->_output_Patch_Manage.u1_patch_highFreq_zmv_true)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_mvx_range), 0);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_mvy_range), 0);		
	}
	else if (s_pParam->_param_frc_sceneAnalysis.u1_dynSR_en == 1)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_mvx_range), s_pContext->_output_frc_sceneAnalysis.u8_ME1_searchRange_x);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_mvy_range), s_pContext->_output_frc_sceneAnalysis.u8_ME1_searchRange_y);
	}
}

#if 0
VOID ME_dynSAD_Diff_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();
	if (s_pParam->_param_frc_sceneAnalysis.u1_dyn_SAD_Diff_en == 1)
	{	
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th), 
			          (0xE0000 * s_pContext->_output_frc_sceneAnalysis.u8_dynSAD_Diff_Gain) / 255);
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_saddiff_th), 0xE0000);
	}
}
#endif

VOID ME_cand_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
 	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();

	if(pParam->u1_MECand_wrt_en == 0)
		return;

	if(s_pParam->_param_read_comreg.u1_powerSaving_en && s_pContext->_external_data.u1_powerSaving == 1 )
	{
		WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_cand0_en_ADDR, 12, 14, 0x0);
		WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_cand0_en_ADDR, 11, 13, 0x0);
	}
	else if(s_pContext->_output_me_sceneAnalysis.u1_RP_detect_true == 1 || s_pContext->_output_Patch_Manage.u1_patch_highFreq_rp_true)
	{
		WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update1_en_ADDR, 12, 14, 0x0);
		WriteRegister(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update1_en_ADDR, 11, 13, 0x0);
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update1_en), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_update1_en);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update2_en), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_update2_en);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_ip_1st_update3_en), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_vbuf_ip_1st_update3_en);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update1_en), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_update1_en);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update2_en), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_update2_en);
		WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_pi_1st_update3_en), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_vbuf_pi_1st_update3_en);
	}
}

VOID ME_caddpnt_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
 	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//_PQLPARAMETER *s_pParam       = GetPQLParameter();

	if(pParam->u1_MECandPnt_wrt_en == 0)
		return;

	if(s_pContext->_output_me_sceneAnalysis.u1_RP_detect_true == 1 || s_pContext->_output_Patch_Manage.u1_patch_highFreq_rp_true)
	{
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd0_ADDR, 16, 23, 0xFF);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd1_ADDR, 24, 31, 0xFF);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd2_ADDR, 0, 7, 0xFF);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd0_ADDR, 16, 23, 0xFF);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd1_ADDR, 24, 31, 0xFF);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd2_ADDR, 0, 7, 0xFF);
	}
	else
	{
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd0_ADDR, 16, 23, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_ip_cddpnt_rnd0);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd1_ADDR, 24, 31, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_ip_cddpnt_rnd1);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_ip_cddpnt_rnd2_ADDR, 0, 7, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_ip_cddpnt_rnd2);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd0_ADDR, 16, 23, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_pi_cddpnt_rnd0);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd1_ADDR, 24, 31, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_pi_cddpnt_rnd1);
		WriteRegister(FRC_TOP__KME_ME1_TOP0__reg_me1_pi_cddpnt_rnd2_ADDR, 0, 7, s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_pi_cddpnt_rnd2);
	}
}

VOID ME_gmv_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
 	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//_PQLPARAMETER *s_pParam       = GetPQLParameter();

	if(pParam->u1_GMV_wrt_en== 0)
		return;

	if(s_pContext->_output_me_sceneAnalysis.u1_RP_detect_true == 1 || s_pContext->_output_Patch_Manage.u1_patch_highFreq_rp_true)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__reg_me1_gmv_sel), 0x0);
		
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__reg_me1_gmv_sel), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_me1_gmv_sel);
	}
}

VOID ME_scan_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
 	const _PQLCONTEXT *s_pContext = GetPQLContext();
	//_PQLPARAMETER *s_pParam       = GetPQLParameter();

	if(pParam->u1_MEScan_wrt_en == 0)
		return;

	if(s_pContext->_output_me_sceneAnalysis.u1_RP_detect_true == 1 || s_pContext->_output_Patch_Manage.u1_patch_highFreq_rp_true)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_frame_meander_enable), 0x0);
		
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_frame_meander_enable), s_pContext->_output_me_sceneAnalysis.SIS_MEMC.MEMC_STATUS.reg_frame_meander_enable);
	}
}

VOID dynamicME_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	//const _PQLCONTEXT *s_pContext = GetPQLContext();
	ME_acdcBld_wrtAction(pParam,pOutput);
	ME_dynSR_wrtAction(pParam,pOutput);
	ME_cand_wrtAction(pParam,pOutput);
	ME_caddpnt_wrtAction(pParam,pOutput);
	ME_gmv_wrtAction(pParam,pOutput);	
	ME_scan_wrtAction(pParam,pOutput);
	
	//ME_dynSAD_Diff_wrtAction(pParam,pOutput);
}

VOID logoDetect_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	pOutput->u1_LG_mb_wrt_en = 0;

	UBYTE u1_logo_blkgrd_th_set_flg = 0; // hard to clarify all setting... need to fix when K4.2016/12/09

	if(pParam->u1_logoCtrl_wrt_en == 0)
		return;

	//clear write action
	if (pParam->u1_LGClr_wrt_en == 1)
	{
		//sw ctrl
		UINT32 logo_clr_idx = s_pContext->_output_FRC_LgDet.u32_blklogo_clr_idx | s_pContext->_output_frc_sceneAnalysis.u32_RgPan_idx | s_pContext->_output_FRC_LgDet.u32_Rg_unstatic_idx;
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclr_hw_en), (1-s_pContext->_output_FRC_LgDet.u1_sw_clr_en_out));

		// logo hsty clear clear logo 
		if ((pParam->u1_LGPixHstyClr_wrt_en == 1 || pParam->u1_LGBlkHstyClr_wrt_en == 1) && pParam->u1_LGHstyClr_ClrLG_wrt_en == 1)
		{
			logo_clr_idx = logo_clr_idx | s_pContext->_output_FRC_LgDet.u32_logo_hsty_clr_lgclr_idx;
		}
		// logo 14 region patch close clear 
		if (pParam->u1_LG_lg16s_patch_wrt_en == 1 && s_pContext->_output_FRC_LgDet.u1_logo_lg16s_patch_status == 1)
		{
			logo_clr_idx = logo_clr_idx & 0x7FFFFFFF;
		} 

		if (pParam->u1_LGRg_dhclr_ctrl_wrt_en == 1 && pParam->u1_LGRg_rim_unbalance_wrt_en == 1 )
		{
			if (s_pContext->_output_FRC_LgDet.u1_RgDhadp_Rimunbalance_status == 1 && s_pContext->_output_rimctrl.u1_LogoRim_unbalace == 1)
			{
				logo_clr_idx = logo_clr_idx & 0xC3FFFFFF;
			}
		}
		else if (pParam->u1_LGRg_rim_unbalance_wrt_en == 1 && s_pContext->_output_rimctrl.u1_LogoRim_unbalace == 1)
		{
			logo_clr_idx = logo_clr_idx & 0xC3FFFFFF;
		}

		if (logo_clr_idx > 0)  //if clear
		{
			WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_logo_merge_type), 0);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclr_en), logo_clr_idx);
		}
		else
		{
			WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_logo_merge_type), s_pContext->_output_FRC_LgDet.u4_blk_pix_merge_type_out);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclr_en), logo_clr_idx);
		}
	}

	// bai  clear blk hsty write action 
	if( pParam->u1_LGBlkHstyClr_wrt_en == 1 )
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclrblkhsty_en), s_pContext->_output_FRC_LgDet.u32_logo_hsty_clr_idx);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclrblkhsty_en), s_pContext->_output_FRC_LgDet.u32_blklogo_clr_idx);
	}
	//else
	//{
	//	WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclrblkhsty_en), 0);
	//}

	// bai clear  pix hsty write action
	if( pParam->u1_LGPixHstyClr_wrt_en == 1 )
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclrpxlhsty_en), s_pContext->_output_FRC_LgDet.u32_logo_hsty_clr_idx);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclrpxlhsty_en), s_pContext->_output_FRC_LgDet.u32_blklogo_clr_idx);
	}
	//else
	//{
	//	WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxlrgclrpxlhsty_en), 0);
	//}


	if (pParam->u1_LG_netflix_wrt_en == 1  && s_pContext->_output_FRC_LgDet.u1_logo_netflix_status == 1)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 7);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 7);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 7);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 1);

	} 
	else if (pParam->u1_LG_lg16s_patch_wrt_en == 1 && s_pContext->_output_FRC_LgDet.u1_logo_lg16s_patch_status == 1)
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 7);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 7);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 7);
		WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 1);
	}
	else
	{
		
		if (pParam->u1_LGRg_dhclr_ctrl_wrt_en == 1 && pParam->u1_LGRg_rim_unbalance_wrt_en == 1 )
		{
			if (s_pContext->_output_FRC_LgDet.u1_RgDhadp_Rimunbalance_status == 1 && s_pContext->_output_rimctrl.u1_LogoRim_unbalace == 1)
			{
				pOutput->u1_LG_mb_wrt_en = 1;

				// mv diff
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_diff_th_rg0), pParam->u8_logo_mv_diff_diff_th_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_d_th_rg0),     pParam->u8_logo_mv_diff_sad_th_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_t_th_rg0),     pParam->u8_logo_tmv_sad_th_lg); 
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_num_rg0),      pParam->u8_logo_tmv_num_th_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_iir_alpha),         0x18);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_th_rg0), 2);

				// dh region partition
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_v2), 0x6E);

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h1), 0xC4);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h2), 0x40);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h3), 0xC4);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h4), 0x40);

				// logo base coring
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdhor_th),  0);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdp45_th),  0);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdver_th),  0);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdn45_th),  0);
				u1_logo_blkgrd_th_set_flg = 1;

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 4);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 7);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 7);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 0);

			} 
			else
			{
				pOutput->u1_LG_mb_wrt_en = 0; 
				// 4 region 
				if (s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg0 == 1 ||
					s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg1 == 1 ||
					s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg2 == 1 ||
					s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg3 == 1
					)
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 4);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 7);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 7);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 0);
					//mvd setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_diff_th_rg0), 1);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_th_rg0), 3);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_d_th_rg0), 1);

					//tmv setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_t_th_rg0), 2);

				}
				else
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 4);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 4);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 4);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 0);

					//mvd setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_diff_th_rg0), 0x10);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_th_rg0), 2);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_d_th_rg0), 5);

					//tmv setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_t_th_rg0), 5);
				}

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_num_rg0),      0x99);
				//SC write action
				if (pParam->u1_LGSC_ctrl_wrt_en == 1)
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_iir_alpha), s_pContext->_output_FRC_LgDet.u5_iir_alpha_out);
				}
				else
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_iir_alpha),         0x1F);
				}
				

				// dh region partition
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_v2), 0x74);

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h1), 0x40);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h2), 0x77);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h3), 0x90);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h4), 0xC4);

				// logo base coring
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdhor_th),  3);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdp45_th),  3);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdver_th),  3);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdn45_th),  3);

			}
		}
		else 
		{
			if ((pParam->u1_LGRg_dhclr_ctrl_wrt_en == 1 && s_pContext->_output_FRC_LgDet.u1_RgDhadp_Rimunbalance_status == 1)||
				(pParam->u1_LGRg_rim_unbalance_wrt_en == 1 && s_pContext->_output_rimctrl.u1_LogoRim_unbalace == 1))
			{
				pOutput->u1_LG_mb_wrt_en = 1;
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_diff_th_rg0), pParam->u8_logo_mv_diff_diff_th_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_d_th_rg0),     pParam->u8_logo_mv_diff_sad_th_lg);																						   
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_t_th_rg0),     pParam->u8_logo_tmv_sad_th_lg);  
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_num_rg0),      pParam->u8_logo_tmv_num_th_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_iir_alpha),         0x18);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_th_rg0), 2);

				// dh region partition
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_v2), 0x6E);

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h1), 0xC4);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h2), 0x40);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h3), 0xC4);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h4), 0x40);

				// logo base coring
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdhor_th),  0);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdp45_th),  0);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdver_th),  0);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdn45_th),  0);
				u1_logo_blkgrd_th_set_flg = 1;

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 4);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 7);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 7);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 0);
			}
			else
			{
				pOutput->u1_LG_mb_wrt_en = 0; 
				// 4 region 
				if (s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg0 == 1 ||
					s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg1 == 1 ||
					s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg2 == 1 ||
					s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg3 == 1
					)
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 4);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 7);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 7);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 0);
					//mvd setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_diff_th_rg0), 1);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_th_rg0), 3);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_d_th_rg0), 1);

					//tmv setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_t_th_rg0), 2);

				}
				else
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mvd_bypass_rg0), 4);	
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_hor_bypass_rg0), 4);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_ver_bypass_rg0), 4);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_bypass_rg0), 0);

					//mvd setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_diff_th_rg0), 0x10);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_mv_d_th_rg0), 2);
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_d_th_rg0), 5);

					//tmv setting
					WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_sad_t_th_rg0), 5);
				}

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_tmv_num_rg0),      0x99);
				//SC write action
				if (pParam->u1_LGSC_ctrl_wrt_en == 1)
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_iir_alpha), s_pContext->_output_FRC_LgDet.u5_iir_alpha_out);
				}
				else
				{
					WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_iir_alpha),     0x1F);
				}

				// dh region partition
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_v2), 0x74);

				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h1), 0x40);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h2), 0x77);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h3), 0x90);
				WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_rgn_h4), 0xC4);

				// logo base coring
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdhor_th),  3);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdp45_th),  3);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdver_th),  3);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdn45_th),  3);
			}
		}

	}

	if (pParam->u1_LG_netflix_wrt_en  && s_pContext->_output_FRC_LgDet.u1_logo_netflix_status == 1)
	{
		// bai test
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), pParam->u8_logo_blksameth_l_bidx0_lg);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), pParam->u8_logo_blksameth_a_bidx0_lg);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), pParam->u8_logo_blksameth_a_bidx10_lg);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), pParam->u8_logo_blkhsty_pth_bidx10_lg);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), pParam->u8_logo_blkhsty_nth_bidx10_lg);

		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), 0x1A);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), 0x4A);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), 0x50);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), 6);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), 6);

		//////
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx14), 0x45);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx14), 0x20);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx14), 6);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx14), 6);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO2__reg_km_logo_blklogopostdlt_th), 3);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxldf_th_a_pidx14), 0x30);
	} 
	else if (pParam->u1_LG_lg16s_patch_wrt_en == 1 && s_pContext->_output_FRC_LgDet.u1_logo_lg16s_patch_status == 1)
	{
		// bai test
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), pParam->u8_logo_blksameth_l_bidx0_com);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), pParam->u8_logo_blksameth_a_bidx0_com);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), pParam->u8_logo_blksameth_a_bidx10_com);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), pParam->u8_logo_blkhsty_pth_bidx10_com);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), pParam->u8_logo_blkhsty_nth_bidx10_com);

		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), 0x20);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), 0x64);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), 0x64);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), 7);
		//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), 7);
		////// region 14
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx14), 0x45);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx14), 0x20);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx14), 6);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx14), 6);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO2__reg_km_logo_blklogopostdlt_th), 1);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxldf_th_a_pidx14), 0x45);

	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_pxldf_th_a_pidx14), 0x30);
		if (pParam->u1_LGRg_detect_adp_wrt_en)
		{
			if (s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg0 == 1 || s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg2 == 1 || s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg3 == 1)
			{
			// bai test
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), pParam->u8_logo_blksameth_l_bidx0_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), pParam->u8_logo_blksameth_a_bidx0_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), pParam->u8_logo_blksameth_a_bidx10_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), pParam->u8_logo_blkhsty_pth_bidx10_lg);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), pParam->u8_logo_blkhsty_nth_bidx10_lg);

				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), 0x1A);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), 0x4A);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), 0x50);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), 6);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), 6);

				//////
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx14), 0x45);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx14), 0x20);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx14), 6);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx14), 6);
			} 
			else
			{
					// bai test
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), pParam->u8_logo_blksameth_l_bidx0_com);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), pParam->u8_logo_blksameth_a_bidx0_com);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), pParam->u8_logo_blksameth_a_bidx10_com);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), pParam->u8_logo_blkhsty_pth_bidx10_com);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), pParam->u8_logo_blkhsty_nth_bidx10_com);


				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx0), 0x20);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx0), 0x64);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx10), 0x64);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx10), 7);
				//WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx10), 7);
				//////
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx14), 0x64);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx14), 0x64);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_pth_bidx14), 7);
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO1__reg_km_logo_blkhsty_nth_bidx14), 7);
			}
			if ((s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg0 +
				s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg1  +
				s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg2  +
				s_pContext->_output_FRC_LgDet.u1_rg_dh_clr_rg3)>=1)
			{
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO2__reg_km_logo_blklogopostdlt_th), 3);
			} 
			else
			{
				WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO2__reg_km_logo_blklogopostdlt_th), 4);
			}
		}

	}


	if(s_pContext->_output_frc_sceneAnalysis.u1_fadeInOut_logo_clr)
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_logo_en), 0x0);
	}
	else if (pParam->u1_LG_SC_PtClose_wrt_en)
	{
		// 14 region patch open logo pt
		if (pParam->u1_LG_lg16s_patch_wrt_en == 1 && s_pContext->_output_FRC_LgDet.u1_logo_lg16s_patch_status == 1)
		{
			WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_logo_en), 3);
		}
		else if (s_pContext->_output_FRC_LgDet.u1_logo_sc_status == 1)
		{
			WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_logo_en), 1);
		} 
		else
		{
			WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_logo_en), 3);
		}
	}
	else
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_logo_en), 0x3);
	}	


	if(s_pContext->_output_FRC_LgDet.u1_lg_UXN_patch_det == 1)// too hard to merge with above code if least modify...
	{
		//UINT32 U32_DATA = 0;
		//ReadRegister(KIWI_REG(FRC_TOP__PQL_1__pql_rb_ctrl_dummy_b4), &U32_DATA);
		UBYTE u8_blksameth_a_bidx4 = _CLIP_(pParam->u8_blksameth_a_bidx4/*(U32_DATA&0xff)*/, 0x20, 0x64);
		UBYTE u8_blksameth_l_bidx4 = u8_blksameth_a_bidx4;
		UBYTE u8_blksameth_h_bidx4 = _CLIP_(pParam->u8_blksameth_h_bidx4/*((U32_DATA>>8)&0xff)*/, 0x35, 0xBE);
		u8_blksameth_h_bidx4 = _MAX_(u8_blksameth_a_bidx4, u8_blksameth_h_bidx4);

		// logo base coring
		if(u1_logo_blkgrd_th_set_flg == 0)
		{
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdhor_th),  1);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdp45_th),  1);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdver_th),  1);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdn45_th),  1);
		}
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdsum2_th),  2);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdsum_pth),  2);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdsum_cth),  2);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx4), u8_blksameth_a_bidx4);// 0x20
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx4), u8_blksameth_l_bidx4);// 0x20
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_h_bidx4), u8_blksameth_h_bidx4);// 0x35

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO2__reg_km_logo_blklogopost_eroen),  0);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogohstydlt_eroen),  0);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogocurdlt_eroen),  0);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO2__reg_km_logo_blklogopostdlt_th),  3);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogodlthsty_th),  3);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogodltcur_th),  3);


	}
	else{

		if(	(pParam->u1_LG_netflix_wrt_en == 1  && s_pContext->_output_FRC_LgDet.u1_logo_netflix_status == 1) ||
	 		(pParam->u1_LG_lg16s_patch_wrt_en == 1 && s_pContext->_output_FRC_LgDet.u1_logo_lg16s_patch_status == 1))
		{
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdhor_th),  3);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdp45_th),  3);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdver_th),  3);
			WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdn45_th),  3);
		}
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdsum2_th),  6);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdsum_pth),  3);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blkgrdsum_cth),  3);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_a_bidx4), 0x64);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_l_bidx4), 0x64);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blksameth_h_bidx4), 0xBE);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO2__reg_km_logo_blklogopost_eroen),  1);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogohstydlt_eroen),  1);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogocurdlt_eroen),  1);

		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogodlthsty_th),  5);
		WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_blklogodltcur_th),  4);

	}
	
}

VOID Mc2_var_lpf_wrtAction(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	_PQLPARAMETER *s_pParam       = GetPQLParameter();

	if(s_pParam->_param_frc_sceneAnalysis.u1_mc2_var_lpf_wrt_en == 0) // 0906,lisa,temporal use, can be change if sync all dynamicPQ from K2
	{

	}
	else if(s_pContext->_external_data.u8_InputVSXral_FrameRepeatMode > 0)
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en), 0x0);
	}
	else if(s_pContext->_output_frc_sceneAnalysis.u8_HDR_PicChg_prt_apply > 0)
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en), 0x0);
	}
	else if(s_pContext->_output_frc_sceneAnalysis.u8_OSDBrightnessBigChg_prt_apply > 0)
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en), 0x0);
	}
	else if(s_pContext->_output_frc_sceneAnalysis.u8_OSDContrastBigChg_prt_apply> 0)
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en), 0x0);
	}
	else 	if(s_pContext->_output_filmDetectctrl.u8_flbk_lvl_cad_cnt > 0)
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en), 0x0);
	}	
	else if(s_pContext->_external_info.u16_MEMCMode == 3)  // MEMC OFF
	{
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en), 0x0);
	}
	else
	{
		UBYTE u1_ori_reg_mc_var_lpf_en = 0x3;
		if(s_pContext->_external_data._output_mode == _PQL_OUT_VIDEO_MODE)//sync from Mid_Mode_SetInOutMode() setting
			u1_ori_reg_mc_var_lpf_en = 0x3;
		if(s_pContext->_external_data._output_mode == _PQL_OUT_PC_MODE)
			u1_ori_reg_mc_var_lpf_en = 0x0;
		WriteRegister(KIWI_REG(FRC_TOP__MC2__reg_mc_var_lpf_en), u1_ori_reg_mc_var_lpf_en);
	}
}

//////////////////////////////////////////////////////////////////////////

VOID Wrt_ComReg_Init(_OUTPUT_WRT_COM_REG *pOutput)
{
	pOutput->u8_lf_lbmcMode_pre         = _MC_NORMAL_;
	pOutput->u8_hf_lbmcMode_pre         = _MC_NORMAL_;
}

VOID Wrt_ComReg_Proc_oneFifth_outInterrupt(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	RimCtrl_wrtAction(pParam);
}
VOID Wrt_ComReg_Proc_intputInterrupt(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	mc_lbmcMode_wrtAction(pParam, pOutput);
	logoDetect_wrtAction(pParam, pOutput);
}
VOID Wrt_ComReg_Proc_outputInterrupt(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput)
{
	scCtrl_wrtAction(pParam, pOutput);
	fbCtrl_wrtAction(pParam, pOutput);
	dhClose_wrtAction(pParam);
	dhLocalFbLvl_wrtAction(pParam);
	dynamicME_wrtAction(pParam,pOutput);
	Vbuf_LFSR_updStgh_wrtAction(pParam,pOutput);
	Mc2_var_lpf_wrtAction(pParam,pOutput);

	Wrt_7segment_show(pParam);
}


