#ifndef _PATCH_MANAGE_H
#define _PATCH_MANAGE_H

typedef struct  
{
	UBYTE u1_Print_en;
	UBYTE u1_dbScan_en;

	// casino only.
	UBYTE  u1_patch_casino_en;

	// arm only
	UBYTE  u1_patch_arm_en;
	UBYTE  u8_patch_arm_holdCnt;
	UBYTE  u8_patch_arm_detCntTh;
	UBYTE  u8_patch_arm_detCnt_dStep;

	UBYTE  u1_arm_rgnSad_byp;
	UBYTE  u1_arm_gmv_byp;
	UBYTE  u1_arm_rim_byp;
	UBYTE  u1_arm_mcDtl_byp;

	UINT32 u23_arm_rgnSad_smallTh;
	UBYTE  u5_arm_rgnSad_Scnt_thL;
	UBYTE  u5_arm_rgnSad_Scnt_thH;
	UINT32 u23_arm_rgnSad_largeTh;
	UBYTE  u5_arm_rgnSad_Lcnt_thL;
	UBYTE  u5_arm_rgnSad_Lcnt_thH;

	SINT16 s11_arm_gmvX_thL;
	SINT16 s11_arm_gmvX_thH;
	SINT16 s10_arm_gmvY_thL;
	SINT16 s10_arm_gmvY_thH;
	UBYTE  u8_arm_gmvXratio_thL;
	UBYTE  u8_arm_gmvXratio_thH;
	UBYTE  u8_arm_gmvYratio_thL;
	UBYTE  u8_arm_gmvYratio_thH;

	UINT16 u16_arm_rimLft_th;
	UINT16 u16_arm_rimRgt_th;
	UINT16 u16_arm_rimUp_th;
	UINT16 u16_arm_rimDn_th;
	UBYTE  u8_arm_rim_delta;

	UINT16 u16_arm_mcHdtl_thL;
	UINT16 u16_arm_mcHdtl_thH;
	UINT16 u16_arm_mcVdtl_thL;
	UINT16 u16_arm_mcVdtl_thH;

	UBYTE  u8_patchCoring_sad0;
	UBYTE  u8_patchCoring_sad1;

	// golf ball
	UBYTE  u1_patch_golfBall_en;
	UBYTE  u1_golfBall_Hdtl_byp;
	UBYTE  u1_golfBall_Vdtl_byp;
	UINT16 u16_golfBall_bHsV_Vdtl_th0;
	UINT16 u16_golfBall_bHsV_Vdtl_th1;
	UINT16 u16_golfBall_bHsV_Hdtl_th0;
	UINT16 u16_golfBall_bHsV_Hdtl_th1;	

	//ball jump
	UBYTE  u1_patch_ballJump_en;

	//// Bluce Mic
	UBYTE u1_BluceMic_En;	

	//soccer
	UBYTE u1_patch_soccer_en;	

	//high-freq player osd
	UBYTE u1_patch_highFreq_en;
}_PARAM_PATCH_M;

typedef struct  
{
//	UINT32 u27_TempConsis_pre;
	UBYTE  u1_Print_En;
	SINT32 s32_PrintCnt;

	UBYTE  u1_dbScan_en;

	// arm
	UBYTE  u1_patchArm_true;
	UBYTE  u1_patchArm_preTrue;
	UBYTE  u8_arm_hcnt;
	UBYTE  u8_arm_detCnt;

	UBYTE  u1_CoringThr_State;

	// golf ball
	UBYTE  u1_golfBall_HVdtl_FB_true;
	UBYTE  u1_golfBall_HVdtl_FB_preTrue;
	
	UINT16 u12_golfBall_bk_obmeMode;
	UINT16 u8_golfBall_bk_varLPF_y;

	//ball jump
	UBYTE   u1_BallJump_true;
	SCHAR   s8_BallJump_holdCnt;
	UINT32  u32_foreground_tc_pre[4];
	UBYTE   u1_dh_close;
	
	//// Bluce Mic
	UBYTE u1_sad_matched;
	UBYTE u1_tc_matched;	
	UBYTE u1_dtl_matched;
	UBYTE u1_apl_matched;
	UBYTE u1_BluceMic_Detected;

	//high-freq player osd
	UBYTE u1_patch_highFreq_zmv_true;
	UBYTE u1_patch_highFreq_rp_true;	
}_OUTPUT_PATCH_M;

VOID PatchManage_Init(_OUTPUT_PATCH_M *pOutput);
VOID PatchManage_Proc(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput);

VOID Patch_detect(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput);
VOID Patch_Action(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput);
VOID Patch_CoringThr(const _PARAM_PATCH_M *pParam, _OUTPUT_PATCH_M *pOutput);

// VOID DoubleScan_Action(UBYTE dbScan_en, UBYTE smallObj_en, UBYTE dh_close_en, _OUTPUT_PATCH_M *pOutput);

DEBUGMODULE_BEGIN(_PARAM_PATCH_M,_OUTPUT_PATCH_M)

	ADD_PARAM_DES(UBYTE, u1_Print_en,             0,  "")
	ADD_PARAM_DES(UBYTE, u1_dbScan_en,            0,  "patch ctrl dbScan")

	/// casino
	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE, u1_patch_casino_en,                0,  "patch_casino")
	ADD_PARAM_DES(UBYTE, u8_patch_casino_holdCnt,           6,  "")
	ADD_PARAM_DES(UBYTE,  u8_patch_casino_detCntTh,         1,  " >= ")
	ADD_PARAM_DES(UBYTE,  u8_patch_casino_detCnt_dStep,     2,  " ")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u1_casino_meDtl_byp,              0,  "")
	ADD_PARAM_DES(UBYTE,  u1_casino_gmv_byp,                0,  "")
	ADD_PARAM_DES(UBYTE,  u1_casino_rim_byp,                0,  "")
	ADD_PARAM_DES(UBYTE,  u1_casino_mcDtl_byp,              0,  " ")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT32, u20_casino_meRgnDtl_diffTh[0],    0, "diff_10_17, <=")
	ADD_PARAM_DES(UINT32, u20_casino_meRgnDtl_diffTh[1],    0, "diff_10_20")
	ADD_PARAM_DES(UINT32, u20_casino_meRgnDtl_diffTh[2],    0, "diff_10_27")
	ADD_PARAM_DES(UINT32, u20_casino_meRgnDtl_diffTh[3],    0, "diff_17_20")
	ADD_PARAM_DES(UINT32, u20_casino_meRgnDtl_diffTh[4],    0, "diff_17_27")
	ADD_PARAM_DES(UINT32, u20_casino_meRgnDtl_diffTh[5],    0, "diff_20_27")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(SINT16, s11_casino_gmvX_thL,          0,  " for patch_casino")
	ADD_PARAM_DES(SINT16, s11_casino_gmvX_thH,          0,  " <= H, s9.2")
	ADD_PARAM_DES(SINT16, s10_casino_gmvY_thL,          0,  " >= L, s8.2")
	ADD_PARAM_DES(SINT16, s10_casino_gmvY_thH,          0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_casino_gmvXratio_thL,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_casino_gmvXratio_thH,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_casino_gmvYratio_thL,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_casino_gmvYratio_thH,      0,  " ")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT16, u16_casino_rimLft_th,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_casino_rimRgt_th,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_casino_rimUp_th,      0,  " ")
	ADD_PARAM_DES(UINT16, u16_casino_rimDn_th,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_casino_rim_delta,      2,  " lft-rht-up-dn delta")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT16, u16_casino_mcHdtl_thL,     0,  " u16.0 ")
	ADD_PARAM_DES(UINT16, u16_casino_mcHdtl_thH,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_casino_mcVdtl_thL,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_casino_mcVdtl_thH,     0,  " ")

	//// arm
	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE, u1_patch_arm_en,                0,  "patch_arm")
	ADD_PARAM_DES(UBYTE, u8_patch_arm_holdCnt,           6,  "")
	ADD_PARAM_DES(UBYTE,  u8_patch_arm_detCntTh,         1,  " >= ")
	ADD_PARAM_DES(UBYTE,  u8_patch_arm_detCnt_dStep,     2,  "  ")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u1_arm_rgnSad_byp,             0,  "")
	ADD_PARAM_DES(UBYTE,  u1_arm_gmv_byp,                0,  "")
	ADD_PARAM_DES(UBYTE,  u1_arm_rim_byp,                0,  "")
	ADD_PARAM_DES(UBYTE,  u1_arm_mcDtl_byp,              0,  " ")


	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT32, u23_arm_rgnSad_smallTh,     0,  " <= ")
	ADD_PARAM_DES(UBYTE,  u5_arm_rgnSad_Scnt_thL,     0,  " ")
	ADD_PARAM_DES(UBYTE,  u5_arm_rgnSad_Scnt_thH,     0,  " ")
	ADD_PARAM_DES(UINT32, u23_arm_rgnSad_largeTh,     0,  " >= ")
	ADD_PARAM_DES(UBYTE,  u5_arm_rgnSad_Lcnt_thL,     0,  " ")
	ADD_PARAM_DES(UBYTE,  u5_arm_rgnSad_Lcnt_thH,     0,  " ")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(SINT16, s11_arm_gmvX_thL,          0,  "for patch_arm")
	ADD_PARAM_DES(SINT16, s11_arm_gmvX_thH,          0,  " <= H , s9.2")
	ADD_PARAM_DES(SINT16, s10_arm_gmvY_thL,          0,  " >= L,  s8.2")
	ADD_PARAM_DES(SINT16, s10_arm_gmvY_thH,          0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_arm_gmvXratio_thL,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_arm_gmvXratio_thH,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_arm_gmvYratio_thL,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_arm_gmvYratio_thH,      0,  " ")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT16, u16_arm_rimLft_th,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_arm_rimRgt_th,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_arm_rimUp_th,      0,  " ")
	ADD_PARAM_DES(UINT16, u16_arm_rimDn_th,      0,  " ")
	ADD_PARAM_DES(UBYTE,  u8_arm_rim_delta,      2,  " ")	

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT16, u16_arm_mcHdtl_thL,     0,  " u16.0 ")
	ADD_PARAM_DES(UINT16, u16_arm_mcHdtl_thH,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_arm_mcVdtl_thL,     0,  " ")
	ADD_PARAM_DES(UINT16, u16_arm_mcVdtl_thH,     0,  " ")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u8_patchCoring_sad0,     2, "")
	ADD_PARAM_DES(UBYTE,  u8_patchCoring_sad1,    4, "")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,   u1_patch_golfBall_en,	    0, "")
	ADD_PARAM_DES(UBYTE,   u1_golfBall_Hdtl_byp, 	    0, "")
	ADD_PARAM_DES(UBYTE,   u1_golfBall_Vdtl_byp,	    0, "")
	ADD_PARAM_DES(UINT16,  u16_golfBall_bHsV_Vdtl_th0,	0, "u16.0, >")
	ADD_PARAM_DES(UINT16,  u16_golfBall_bHsV_Vdtl_th1, 	0, "u16.0, <")
	ADD_PARAM_DES(UINT16,  u16_golfBall_bHsV_Hdtl_th0,	0, "u16.0, >")
	ADD_PARAM_DES(UINT16,  u16_golfBall_bHsV_Hdtl_th1, 	0, "u16.0, <")

	////////  output  //////////////////////////////////////////////////////////////////
    
	ADD_OUTPUT(UBYTE,  u1_Print_En)
	ADD_OUTPUT(SINT32, s32_PrintCnt)
    
	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,  u1_dbScan_en)

	ADD_DUMMY_OUTPUT()
    ADD_OUTPUT(UBYTE,  u1_patchCasio_true)
	ADD_OUTPUT(UBYTE,  u1_patchCasio_preTrue)
	ADD_OUTPUT(UBYTE,  u8_casino_hcnt)
	ADD_OUTPUT(UBYTE,  u8_casino_detCnt)


	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,  u1_patchArm_true)
	ADD_OUTPUT(UBYTE,  u1_patchArm_preTrue)
	ADD_OUTPUT(UBYTE,  u8_arm_hcnt)
	ADD_OUTPUT(UBYTE,  u8_arm_detCnt)

	DEBUGMODULE_END

#endif
