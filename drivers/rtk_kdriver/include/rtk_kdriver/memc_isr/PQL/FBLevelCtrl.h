#ifndef _FBLEVELCTRL_DEF_H_
#define _FBLEVELCTRL_DEF_H_


#ifdef __cplusplus
extern "C" {
#endif

#define _FB_LEVEL_MAX_   0xff

typedef struct
{
	UBYTE  u1_FBLevelCtrl_en;
	UBYTE  u1_BadRegionCtrl_en;
	UBYTE  u1_FBLevelShow_en;
	UBYTE  u1_FbLvl_occlCtrl_en;
	UBYTE  u1_FbLvl_gmvCtrl_en;
	UBYTE  u1_FbLvl_disableSCclr_en;

	UBYTE  u8_FbLvl_dSCclr_d2en_th;
	UBYTE  u8_FbLvl_dSCclr_en2d_th;
	UBYTE  u8_FbLvl_dSCclr_holdCnt;

	UBYTE  u1_Fblvl_Dh_tcTh_mapEn;
	UBYTE  u8_FbLvl_Dh_tc_thLgain;
	UBYTE  u8_FbLvl_Dh_tc_thHgain;
	UBYTE  u8_DehaloFBlvl_iir;

	UBYTE  u1_Fblvl_blur_ctrlEn;
	UBYTE  u8_FbLvl_blur_tc_thLgain;
	UBYTE  u8_FbLvl_blur_tc_thHgain;
	UBYTE  u8_FbLvl_blur_iir;
	UINT16 u12_FbLvl_blur_gmvUnconf_th0;
	UINT16 u12_FbLvl_blur_gmvUnconf_th1;
	UBYTE  u5_FbLvl_blur_badscene_dftLvl;

	UBYTE  u1_Fblvl_judder_ctrlEn;
	UBYTE  u8_FbLvl_judder_tc_thLgain;
	UBYTE  u8_FbLvl_judder_tc_thHgain;
	UBYTE  u8_FbLvl_judder_iir;


	UINT32 u27_Fb_tc_th_h;
	UINT32 u27_Fb_tc_th_l;
	UBYTE  u8_FBTempConsisIIR_up;
	UBYTE  u8_FBTempConsis_IIR_down;
	UBYTE  u8_FBTempConsis_limit_gain;
	UINT32 u32_FBTempConsis_limit_val;
	UINT16 u12_FBLevelIIRUp;
	UINT16 u12_FBLevelIIRDown;

	UBYTE  u8_SC_Gain;
	UBYTE  u8_SC_slope;
	UBYTE  u8_SC_HoldCnt;
	UBYTE  u8_SC_NormCnt;

	UBYTE  u8_badRgn_sad_iirA_up;
	UBYTE  u8_badRgn_sad_iirA_down;
	UINT32 u23_BadRegionSAD_th;
	UINT32 u23_BadRegionSAD_th_m;
	UINT32 u23_BadRegionSAD_th_h;
	UBYTE  u8_badRgn_center_gain;
	UBYTE  u8_badRgn_center_oft;
	UBYTE  u5_BadRegionGain[32];
	UBYTE  u8_BadRegionGainIIR;

	UBYTE  u1_gmvratio_use;
	UBYTE  u7_gmv_ratio_thH;
	UBYTE  u7_gmv_ratio_thL;
	UBYTE  u6_gmv_gain_max;
	UBYTE  u6_gmv_gain_min;
	UBYTE  u6_gmv_similar_cnt;
	UBYTE  u8_gmv_gain_iir;
	UINT16 u12_gmv_rng_cnt_th;
	UINT16 u12_gmv_unconf_cnt_th;

	UBYTE  u8_FBLevelMapY1;
	UBYTE  u8_FBLevelMapY2;
	UBYTE  u8_FBLevelMapX1;
	UBYTE  u8_FBLevelMapX2;

	UBYTE  u1_FbLvl_disIIR_en;
	UBYTE  u8_FbLvl_disIIR_holdCnt;
	UBYTE  u1_scAnalysis_en;
	UBYTE  u4_scAnalysis_frmCnt_th;
	UBYTE  u4_scAnalysis_badFrmCnt_th;

	UINT32 u28_scAnalysis_sadAll_th0;
	UINT32 u28_scAnalysis_sadAll_th1;
	UINT32 u27_scAnalysis_TC_th0;
	UINT32 u27_scAnalysis_TC_th1;
	UINT32 u27_scAnalysis_static_motionTh;
	UBYTE  u8_scAnalysis_st2mo_stPeriodTh;

	UINT16 u16_minusDiff_penalty;

	UBYTE  u8_sc_bypass_cnt;
	UBYTE  u8_static_cnt_th;
	UINT32 u32_static_mot_th;

	UINT32 u20_good_rgn_sad_th;
	UINT16 u12_good_rgn_gmv_unconf_th;
	UBYTE  u8_fblvl_map_y2_good;
	UINT16 u12_fblvl_iir_up_good;
	UBYTE  u8_good_rgn_num_th1;
	UBYTE  u8_good_rgn_num_th2;
	UBYTE  u4_good_scene_hold_cnt;

	UBYTE  u1_FB_pan_apply_en;
	UBYTE  u1_FB_cross_apply_en;
}_PARAM_FBLevelCtrl;

typedef struct
{
	UINT32 u27_TempConsis_Th_h;
	UINT32 u27_TempConsis_Th_l;
	UINT32 u27_SC_TC_Th_h;
	UINT32 u27_SC_TC_Th_l;
	UBYTE  u8_SCHoldCnt;
	UBYTE  u8_SCNormCnt;
	UINT32 u27_FBTempConsis;
	UINT32 u27_FBTempConsisPre;
	UINT32 u27_FBTempConsisPre_raw;

	UINT32  u25_badRgn_iirRgnSad[32];
	UBYTE  u6_BadRegionCnt;
	UBYTE  u5_BadRegionGain;
	UINT16  u9_BadRegionGainPre;

	UBYTE  u4_gmv_gain;
	UBYTE  u4_gmv_gain_pre;

	UBYTE  u8_Dehalo_FBLevel;
	UINT16 u16_judder_lvl;
	UINT16 u16_blur_lvl;	
	UBYTE  u1_deBlur_gmvU_isGood;


	UBYTE  u8_FBLevel;
	UBYTE  u8_FBSystem;
	UINT32 u8_FBResult;
	UINT32 u20_FBPreResult;

	UBYTE  u1_FbLvl_dSCclr;
	UBYTE  u8_FbLvl_dSCclr_holdCnt;


	UBYTE  u1_HW_sc_true;
	UBYTE  u1_SW_sc_true;
	UBYTE  u8_HW_sc_badFrm_cnt;
	UBYTE  u8_HW_sc_Frm_cnt;
	UBYTE  u1_preFrm_isBadScene;

	UBYTE  u1_swSC_static2move_true;
	UBYTE  u8_swSC_static_frmCnt;
	UBYTE  u8_swSC_disIIR_holdCnt;

	UBYTE  u1_badRgn_rgnSAD_noIIR;
	UBYTE  u1_fbLvl_tc_noIIR;
	UBYTE  u1_fbLvl_result_noIIR;

	UBYTE u3_FbLvl_dSCclr_wrt;

	UBYTE   u1_sc_signal;
	UBYTE   u8_sc_bypass_cnt;
	UINT32  u8_mc_phase_pre;
	UBYTE   u8_static_cnt;

	UBYTE	u1_good_scene;
	UBYTE	u8_good_scene_cnt;
	UBYTE	u1_bad_scene;
	UBYTE	u8_fblvl_map_y2;
	UINT16	u12_fblvl_iir_up;
	UBYTE	u8_good_rgn_cnt;

	UBYTE	u1_panx_scene;
	UBYTE	u1_pany_scene;
	UBYTE	u8_pan_scene_hold_cnt;
	
	UBYTE	u8_pre_pan_cond;
	SINT16	s11_pre_2nd_gmv_mvx;
	UBYTE	u8_cross_scene;
	
}_OUTPUT_FBLevelCtrl;

VOID FBLevelCtrl_Init(_OUTPUT_FBLevelCtrl *pOutput);
VOID FBLevelCtrl_Proc(const _PARAM_FBLevelCtrl *pParam, _OUTPUT_FBLevelCtrl *pOutput);

DEBUGMODULE_BEGIN(_PARAM_FBLevelCtrl,_OUTPUT_FBLevelCtrl)
	ADD_PARAM(UBYTE,  u1_FBLevelCtrl_en,       1)
	ADD_PARAM(UBYTE,  u1_BadRegionCtrl_en,           0)
	ADD_PARAM(UBYTE,  u1_FBLevelShow_en,             0)
	ADD_PARAM(UBYTE,  u1_FbLvl_occlCtrl_en,    0)
	ADD_PARAM(UBYTE,  u1_FbLvl_gmvCtrl_en,           0)
	ADD_PARAM(UBYTE,  u1_FbLvl_disableSCclr_en,     1)

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_dSCclr_d2en_th,   128, ">, disable 2 enable Th")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_dSCclr_en2d_th,   64, "<")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_dSCclr_holdCnt,    2, "extra hold time")

	ADD_DUMMY_PARAM()
    ADD_PARAM_DES(UBYTE,  u1_Fblvl_Dh_tcTh_mapEn,    1,  "0:ori_propose, 1:A-B th")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_Dh_tc_thLgain,     20,  "u2.6")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_Dh_tc_thHgain,     30,  "")
	ADD_PARAM_DES(UBYTE,  u8_DehaloFBlvl_iir,       100, "u0.8")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u1_Fblvl_blur_ctrlEn,              0, "1-enable")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_blur_tc_thLgain,         16, "u2.6")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_blur_tc_thHgain,         32, "")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_blur_iir,               200, "u0.8")
	ADD_PARAM_DES(UINT16, u12_FbLvl_blur_gmvUnconf_th0,    110, "<=,  bad-to-good")
	ADD_PARAM_DES(UINT16, u12_FbLvl_blur_gmvUnconf_th1,    100, ">=,  good to bad")
	ADD_PARAM_DES(UBYTE,  u5_FbLvl_blur_badscene_dftLvl,     8, "u1.4, if bad scene, FRC result would not be better than default.")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u1_Fblvl_judder_ctrlEn,            0, "1-enable")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_judder_tc_thLgain,       16, "u2.6")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_judder_tc_thHgain,       32, "")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_judder_iir,              64, "u0.8")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT32, u27_Fb_tc_th_h,                 680000,  "u28.0")
	ADD_PARAM_DES(UINT32, u27_Fb_tc_th_l,                 380000,  "u28.0")
	ADD_PARAM_DES(UBYTE,  u8_FBTempConsisIIR_up,              40,  "u0.8")
	ADD_PARAM_DES(UBYTE,  u8_FBTempConsis_IIR_down,          120,  "u0.8")
	ADD_PARAM_DES(UBYTE,  u8_FBTempConsis_limit_gain,         32,  "u6.2")
	ADD_PARAM_DES(UINT32,  u32_FBTempConsis_limit_val,    800000,  "u32")
	ADD_PARAM_DES(UINT16, u12_FBLevelIIRUp,                  600,  "u0.12")
	ADD_PARAM_DES(UINT16, u12_FBLevelIIRDown,               1000,  "u0.12")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u8_SC_Gain,                  3,  "if sc, th = para_th*gain>>slope")
	ADD_PARAM_DES(UBYTE,  u8_SC_slope,                 1,  "suppose gain > (1<<slope)")
	ADD_PARAM_DES(UBYTE,  u8_SC_HoldCnt,               2,  "in hold time, sc_th keep ini")
	ADD_PARAM_DES(UBYTE,  u8_SC_NormCnt,               2,  "after hold, in Norm, from ini back to para_th")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u8_badRgn_sad_iirA_up,        0, "u1.8")
	ADD_PARAM_DES(UBYTE,  u8_badRgn_sad_iirA_down,      0, "u1.8")
	ADD_PARAM_DES(UINT32, u23_BadRegionSAD_th,     100000, "")
	ADD_PARAM_DES(UINT32, u23_BadRegionSAD_th_m,   180000, "")
	ADD_PARAM_DES(UINT32, u23_BadRegionSAD_th_h,  3000000, "")
	ADD_PARAM_DES(UBYTE,  u8_badRgn_center_gain,        0, "u4.4, for center 4x2 rgn, add extra cnt")
	ADD_PARAM_DES(UBYTE,  u8_badRgn_center_oft,         1, "total bad rgn cnt <= 31")

	ADD_DUMMY_PARAM()
    ADD_PARAM_ARRAY_DES(UBYTE, u5_BadRegionGain, 32, 0, "uX.4")
	ADD_PARAM_DES(UBYTE,  u8_BadRegionGainIIR,  160, "u0.8")

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,  u7_gmv_ratio_thH,             100)
	ADD_PARAM(UBYTE,  u7_gmv_ratio_thL,             60)
	ADD_PARAM_DES(UBYTE,  u6_gmv_gain_max,          32, "uX.4")
	ADD_PARAM(UBYTE,  u6_gmv_gain_min,              16)
	ADD_PARAM(UBYTE,  u6_gmv_similar_cnt,           3)
	ADD_PARAM(UBYTE,  u8_gmv_gain_iir,              0)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,  u8_FBLevelMapY1,      22)
	ADD_PARAM(UBYTE,  u8_FBLevelMapY2,     255)
	ADD_PARAM(UBYTE,  u8_FBLevelMapX1,      3)
	ADD_PARAM(UBYTE,  u8_FBLevelMapX2 ,    255)

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u1_FbLvl_disIIR_en,              0, "if big fblvl, no fb result iir")
	ADD_PARAM_DES(UBYTE,  u8_FbLvl_disIIR_holdCnt,         0, "")
	ADD_PARAM_DES(UBYTE,  u1_scAnalysis_en,                0, "1-scene change in FB need sw analysis, (in FPGA, set 0)")
	ADD_PARAM_DES(UBYTE,  u4_scAnalysis_frmCnt_th,         3, "u4.0")
	ADD_PARAM_DES(UBYTE,  u4_scAnalysis_badFrmCnt_th,      4, "u4.0, should < frmCnt")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT32, u28_scAnalysis_sadAll_th0,       1, "u28.0")
	ADD_PARAM_DES(UINT32, u28_scAnalysis_sadAll_th1,      16, "")
	ADD_PARAM_DES(UINT32, u27_scAnalysis_TC_th0,           1, "u27.0")
	ADD_PARAM_DES(UINT32, u27_scAnalysis_TC_th1,          16, "")
	ADD_PARAM_DES(UINT32, u27_scAnalysis_static_motionTh,  1, "u27.0, <")
	ADD_PARAM_DES(UBYTE,  u8_scAnalysis_st2mo_stPeriodTh, 16, "u8.0, >")


	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT16, u16_minusDiff_penalty,     1, "can't be 0")


	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u8_sc_bypass_cnt,      1, "")
	ADD_PARAM_DES(UBYTE,  u8_static_cnt_th,      4, "")
	ADD_PARAM_DES(UINT32, u32_static_mot_th,     2000, "")


	//////////////////////////////////////////////////////////////////////////
	ADD_OUTPUT(UINT32, u27_TempConsis_Th_h)
	ADD_OUTPUT(UINT32, u27_TempConsis_Th_l)
    ADD_OUTPUT(UINT32, u27_SC_TC_Th_h)
	ADD_OUTPUT(UINT32, u27_SC_TC_Th_l)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,  u8_SCHoldCnt)
	ADD_OUTPUT(UBYTE,  u8_SCNormCnt)
	ADD_OUTPUT(UINT32, u27_FBTempConsis)
	ADD_OUTPUT(UINT32, u27_FBTempConsisPre)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,  u6_BadRegionCnt)
	ADD_OUTPUT(UBYTE,  u5_BadRegionGain)
	ADD_OUTPUT(UINT16,  u9_BadRegionGainPre)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,   u4_gmv_gain)
	ADD_OUTPUT(UBYTE,   u4_gmv_gain_pre)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,   u8_Dehalo_FBLevel)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,   u1_deBlur_gmvU_isGood)
	ADD_OUTPUT(UINT16,  u9_blur_lvl)
	ADD_OUTPUT(UINT16,  u9_judder_lvl)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,   u8_FBLevel)
	ADD_OUTPUT(UINT32,  u8_FBResult)
	ADD_OUTPUT(UINT32,  u20_FBPreResult)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,  u1_FbLvl_dSCclr)
	ADD_OUTPUT(UBYTE,  u8_FbLvl_dSCclr_holdCnt)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,  u3_FbLvl_dSCclr_wrt)
DEBUGMODULE_END


#ifdef __cplusplus
}
#endif



#endif
