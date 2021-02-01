#ifndef _FRC_SCENEANALYSIS_H_
#define _FRC_SCENEANALYSIS_H_


#ifdef __cplusplus
extern "C" {
#endif


/* Param Definition*/
typedef struct
{
	UBYTE   u1_fadeInOut_en                    ;
	UBYTE	u1_fdIO_acdc_cnt_en			       ;
	UBYTE	u1_fdIO_acdc_ratio_en		       ;
	UBYTE	u1_fdIO_bv_sad_en                  ;
	UBYTE	u1_fdIO_apl_diff_en                ;
	UBYTE	u1_fdIO_conf_iir_en                ;
	UBYTE	u1_fdIO_sc_clear_en                ;

	UINT32  u10_fdIO_apl_diff_thr_low          ;
	UINT32  u10_fdIO_apl_diff_thr_hig          ;
	UINT32  u8_fdIO_acdc_cnt_alpha_low         ;
	UINT32	u8_fdIO_acdc_cnt_alpha_hig         ;
	UINT32  u31_fdIO_acdc_dcsad_thr            ;
	UBYTE   u8_fdIO_acdc_sad_ratio_low         ;  //ac_sad/dc_sad -> 0~256(low, high)->0~16
	UBYTE	u8_fdIO_acdc_sad_ratio_hig         ;
	UINT16  u16_fdIO_bv_sad_low                ;  //each block sad thr
	UINT16	u16_fdIO_bv_sad_hig                ;
	UBYTE   u4_fdIO_conf_iir_alpha             ;
	UBYTE   u4_fadeInOut_dh_close_thr          ;
	UBYTE   u4_acdc_bld_holdtime               ;
	UINT32  u20_fdIO_acdc_cnt_low              ; 
	UINT32	u20_fdIO_acdc_cnt_hig              ;

	UBYTE   u3_fdIO_apl_diff_frm_cnt           ;

	UBYTE   u4_dynME_acdc_bld_alpha_x1         ;
	UBYTE   u4_dynME_acdc_bld_alpha_x2         ;

	UBYTE   u8_dynME_acdc_bld_x_com[3]         ;
	UBYTE   u6_dynME_acdc_bld_y_com[3]         ;
	UBYTE   u8_dynME_acdc_bld_x_fdIO[3]        ;
	UBYTE   u6_dynME_acdc_bld_y_fdIO[3]        ;

	UBYTE   u8_dynME_ac_pix_sad_limt_com       ;
	UBYTE   u8_dynME_ac_pix_sad_limt_fdIO      ;

	UBYTE   u6_dynME_ac_dc_bld_apl_holdfrm     ;

    UBYTE   u4_acdc_bld_psad_shift_com         ;
	UBYTE   u4_acdc_bld_psad_shift_fdIO        ;

	UBYTE   u1_acdc_bld_sc_clear_en            ;

	UBYTE    u1_dynSR_en;
	UINT32   u11_dynSR_rmv_x_thr0;
	UINT32   u10_dynSR_rmv_y_thr0;
	UINT32   u11_dynSR_rmv_x_thr1;
	UINT32   u10_dynSR_rmv_y_thr1;
	UINT32   u12_dynSR_rmv_cnt_thr0;
	UINT32   u12_dynSR_rmv_cnt_thr1;
	UINT32   u12_dynSR_rmv_unconf_thr0;
	UINT32   u12_dynSR_rmv_unconf_thr1;
	UINT32   u9_dynSR_mvx_range0;
	UINT32   u9_dynSR_mvx_range1;
	UINT32   u8_dynSR_mvy_range0;
	UINT32   u8_dynSR_mvy_range1;
	UBYTE    u6_dynSR_rmv_x_num_thr0;
	UBYTE    u6_dynSR_rmv_x_num_thr1;
	UBYTE    u6_dynSR_rmv_y_num_thr0;
	UBYTE    u6_dynSR_rmv_y_num_thr1;
	UBYTE	 u1_dyn_SAD_Diff_en;
	UBYTE    u8_dyn_SADGain_thr;
	UINT32	 u27_dyn_SAD_Diff_TC_th_l;
	UINT32	 u27_dyn_SAD_Diff_TC_th_h;
	UINT32	 u8_dyn_SAD_Diff_TC_gain_min;
	UINT32	 u8_dyn_SAD_Diff_TC_gain_max;	
	UINT32	 u28_dyn_SAD_Diff_sadAll_th_l;
	UINT32	 u28_dyn_SAD_Diff_sadAll_th_h;
	UINT32	 u8_dyn_SAD_Diff_sadAll_gain_min;
	UINT32	 u8_dyn_SAD_Diff_sadAll_gain_max;	

	//////////////////////////////////////////////////////////////////////////
	//InSide panning -> close dh.
	UINT16   u12_PanRMV_Cnt;
	UINT16   u10_PanRMV_SmallMV;  //only x small, or y small
	UINT16   u10_PanRMV_LargeMV;  //only y large, or x large
	UINT16   u12_PanRMV_Unconf;   

	UINT32   u15_PanRMV_FitNumThr;   // larger than thr
	UINT32   u32_avgRngTC_Thr;       // small than thr
	UINT32   u32_avgRngSC_Thr;       // small than thr
	UBYTE  u1_RgPan_Detect_en;
	UINT32 u16_RgPan_rMV_th_h;
	UINT32 u16_RgPan_rMV_th_l;

	UINT32 u22_RgPan_rSC_th_h;
	UINT32 u22_RgPan_rSC_th_l;

	UINT32 u22_RgPan_rTC_th_h;
	UINT32 u22_RgPan_rTC_th_l;

	UBYTE  u5_RgPan_alp_th;

	UBYTE  u4_BdySmall_cnt_thr;
	UBYTE  u8_BdySmall_mvx_thr;
	UBYTE  u8_BdySmall_mvy_thr;
	UINT16 u15_BdySmall_sad_thr;
	
	UBYTE  inUnconf_sel;

	//goodgmv, mvd cnt
	UBYTE	s2m_goodmv_thr;
	UBYTE	s2m_goodmv_unconf;
	UBYTE	s2m_diffmv_thr;
	UBYTE   s2m_cnt_iir_alpha;
	UBYTE   s2m_method_sel;

	UBYTE   u1_zoom_detect_en;
	UBYTE   u1_mc2_var_lpf_wrt_en;

	// fast motion
#if 1
	UINT16 u8_hpan_th; 
	UINT16 u8_vpan_th;
	UINT16 u8_cnt2_th;
	//UBYTE u8_fastMotion_entercnt_th;
	//UBYTE u8_fastMotion_holdCnt_max;
	UINT32 u25_glb_dtl_th;	
	UBYTE u1_fastMotion_gfb_en; 
	UBYTE u8_fastMotion_glbfb_min;	
	UBYTE u1_fastMotion_lfb_en; 
	UBYTE u6_localfallback_lvl;
	UBYTE u1_fastMotion_det_en;

#endif

	UBYTE   u1_special_scfb_en;
}_PARAM_FRC_SceneAnalysis;

typedef struct
{

	UBYTE   u4_fadeInOut_conf				      ; //fadeInOut Scene Confidence
	UBYTE   u4_fadeInOut_conf_iir			      ; //fadeInOut Scene Confidence

	UBYTE   u4_fadeInOut_cnt_alpha				  ;
	UBYTE   u4_fadeInOut_cnt_Thr_alpha			  ;
	UBYTE   u4_fadeInOut_acdc_sad_alpha  		  ;
	UBYTE   u4_fadeInOut_bv_sad_alpha			  ;
	UBYTE	u4_fadeInOut_apl_diff_alpha           ;
	UINT32	u32_apldiff;

	UBYTE   u8_dynME_acdc_bld_x_act[3]            ;
	UBYTE   u6_dynME_acdc_bld_y_act[3]            ;
	SINT16  s9_dynME_acdc_bld_s_act[2]            ;

	UBYTE   u8_dynME_ac_pix_sad_limt_act          ;

	UBYTE   u4_acdc_bld_psad_shift_act            ;

	SINT16  u8_ME1_searchRange_x                  ;
	SINT16  u8_ME1_searchRange_y                  ;
	UBYTE   u2_searchRange_x_status               ;
	UBYTE   u2_searchRange_y_status               ;

	UBYTE   u1_fadeInOut_dh_close                 ;
	UBYTE   u4_fadeInOut_logo_conf_iir; 
	UBYTE   u1_fadeInOut_logo_clr;	
	//UBYTE   u1_fadeInOut_acdc_bld                 ;
	//UBYTE   u1_fadeInOut_acdc_bld_pre             ;
	 
	UBYTE   u5_dc_ac_bld_alpha                        ;
	UBYTE   u5_acdc_bld_holdtime                     ;

	UINT32  u26_Apli[5];
	UINT32  u32_frm_cnt;
	UBYTE   u1_Apli_same               ;
	UBYTE	u1_bad_scene;
	UBYTE	u8_dynSAD_Diff_Gain;
	UINT32  u32_glb_sad_pre;
	UINT32  u32_glb_sad_cur;
	UBYTE	u8_tc_gain;
	UBYTE   u8_saddiff_gain;
	UBYTE   u1_is_saddiff_large;

	UBYTE   u8_insidePan_LargeXnum;
	UBYTE   u8_insidePan_LargeYnum;
	UINT32  u32_insidePan_avgTc;
	UINT32  u32_insidePan_avgSc;
	UBYTE   u8_is_insidePan;
	UBYTE   u8_is_insidePanX;

	UBYTE   u8_goodGmv_cnt;
	UBYTE   u8_diffGmv_cnt;
	UBYTE	s2m_1st_cnt;
	UBYTE	s2m_2nd_cnt;
	UBYTE   s2m_12_cnt_iir;
	SINT32  s2m_1st_mvx;
	SINT32  s2m_1st_mvy;
	SINT32  s2m_2nd_mvx;
	SINT32  s2m_2nd_mvy;

	UINT32  u32_insidePan_avgAbsMVX;
	UINT32  u32_insidePan_avgAbsMVY;
	UINT32  u32_unconf_avg;

	UBYTE   u8_BdySmall_lft_cnt;
	UBYTE	u8_BdySmall_rht_cnt;
	UBYTE   u1_is_BdySmall_MV;
	
	UINT32 u32_RgPan_idx;	

	UBYTE   u4_dc_ac_alpha;
	UBYTE   u4_acdc_bld_holdtime;
	UBYTE   u8_zoom_force_fb_cnt;
	UBYTE   u1_still_frame;

	UBYTE  u1_fastMotion_det;
	UBYTE  u1_specialscfb_true;
	
	//in intp call
	UBYTE u8_HDR_PicChg_prt_apply;
	UINT16 u16_OSDBrightnessVal;
	UINT16 u16_OSDContrastVal;
	UBYTE u8_OSDBrightnessBigChg_prt_apply;
	UBYTE u8_OSDContrastBigChg_prt_apply;
	UBYTE u8_VOSeek_prt_apply;
	UBYTE u8_OSDPictureModeChg_prt_apply;
	//--end of "in intp call"
}_OUTPUT_FRC_SceneAnalysis;


/* MOdule UI Definition*/
DEBUGMODULE_BEGIN(_PARAM_FRC_SceneAnalysis, _OUTPUT_FRC_SceneAnalysis)

	////param
	ADD_PARAM(UBYTE,    u1_fadeInOut_en			     ,	  0 )
	ADD_PARAM(UBYTE,    u1_fdIO_acdc_cnt_en		     ,	  1 )
	ADD_PARAM(UBYTE,    u1_fdIO_acdc_ratio_en        ,	  1 )
	ADD_PARAM(UBYTE,    u1_fdIO_bv_sad_en		     ,	  1 )
	ADD_PARAM(UBYTE,    u1_fdIO_apl_diff_en		     ,	  1 )
	ADD_PARAM(UBYTE,    u1_fdIO_conf_iir_en		     ,	  1 )
	ADD_PARAM(UBYTE,    u1_fdIO_sc_clear_en		     ,	  0 )


	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT32,   u10_fdIO_apl_diff_thr_low    ,	  1,  "<low  ->0" )
	ADD_PARAM_DES(UINT32,   u10_fdIO_apl_diff_thr_hig    ,	  3, ">high ->1" )
	ADD_PARAM(UINT32,		u8_fdIO_acdc_cnt_alpha_low ,	  15  )
	ADD_PARAM(UINT32,		u8_fdIO_acdc_cnt_alpha_hig ,	  128 )
	ADD_PARAM_DES(UINT32,   u31_fdIO_acdc_dcsad_thr      ,	  20,  "need > dc-sad thr" )
	ADD_PARAM_DES(UBYTE,    u8_fdIO_acdc_sad_ratio_low   ,	  30, "ratio<low,  ->1" )
	ADD_PARAM_DES(UBYTE,    u8_fdIO_acdc_sad_ratio_hig   ,	  150, "ratio>high, ->0" )
	ADD_PARAM(UINT16,		u16_fdIO_bv_sad_low			 ,	  40  )
	ADD_PARAM(UINT16,		u16_fdIO_bv_sad_hig          ,    80 )
	ADD_PARAM(UBYTE,		u4_fdIO_conf_iir_alpha       ,    8)
	ADD_PARAM(UBYTE,		u4_fadeInOut_dh_close_thr    ,    8)
	ADD_PARAM(UBYTE,		u4_acdc_bld_holdtime     ,    0 )
	ADD_PARAM(UINT32,		u20_fdIO_acdc_cnt_low    ,    0)
	ADD_PARAM(UINT32,		u20_fdIO_acdc_cnt_hig    ,    8)


	ADD_DUMMY_PARAM()
	ADD_PARAM_ARRAY_DES(UBYTE, u8_dynME_acdc_bld_x_com,  3, 0, "u8.0")
	ADD_PARAM_ARRAY_DES(UBYTE, u6_dynME_acdc_bld_y_com,  3, 0, "u6.0")
	ADD_PARAM_ARRAY_DES(UBYTE, u8_dynME_acdc_bld_x_fdIO, 3, 0, "u8.0")
	ADD_PARAM_ARRAY_DES(UBYTE, u6_dynME_acdc_bld_y_fdIO, 3, 0, "u6.0")

	////output
	ADD_OUTPUT(UBYTE,   u4_fadeInOut_conf)
	ADD_OUTPUT(UBYTE,   u4_fadeInOut_conf_iir)
	ADD_OUTPUT(UBYTE,   u4_fadeInOut_cnt_alpha		)
	ADD_OUTPUT(UBYTE,   u4_fadeInOut_cnt_Thr_alpha		) 
	ADD_OUTPUT(UBYTE,   u4_fadeInOut_acdc_sad_alpha )
	ADD_OUTPUT(UBYTE,   u4_fadeInOut_bv_sad_alpha	)
	ADD_OUTPUT(UBYTE,   u4_fadeInOut_apl_diff_alpha	)
	ADD_OUTPUT(UINT32,   u32_apldiff	)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT_ARRAY_DES(UBYTE,  u8_dynME_acdc_bld_x_act, 3, "")
	ADD_OUTPUT_ARRAY_DES(UBYTE,  u6_dynME_acdc_bld_y_act, 3, "")
	ADD_OUTPUT_ARRAY_DES(SINT16, s9_dynME_acdc_bld_s_act, 2, "")

	ADD_OUTPUT(UBYTE,   u1_fadeInOut_dh_close	)

DEBUGMODULE_END

	/* Function Declaration*/
	VOID FRC_SceneAnalysis_Init(_OUTPUT_FRC_SceneAnalysis *pOutput);
	VOID FRC_Still_Pattern_Detect(const _PARAM_FilmDetectCtrl *pParam,  _OUTPUT_FilmDetectCtrl *pOutput_film,  _OUTPUT_FRC_SceneAnalysis *pOutput);
	VOID FRC_FastMotion_Detect(const _PARAM_FRC_SceneAnalysis *pParam,  _OUTPUT_FRC_SceneAnalysis *pOutput);
	VOID FRC_SceneAnalysis_Proc(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput);
	VOID FRC_SceneAnalysis_Proc_InputIntp(const _PARAM_FRC_SceneAnalysis *pParam, _OUTPUT_FRC_SceneAnalysis *pOutput);

#ifdef __cplusplus
}
#endif


#endif

