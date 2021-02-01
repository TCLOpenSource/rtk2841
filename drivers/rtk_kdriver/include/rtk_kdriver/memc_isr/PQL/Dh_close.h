#ifndef _DH_CLOSE_DEF_H
#define _DH_CLOSE_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	UBYTE  u2_dhClose_bypass;
	UBYTE  u1_dbg_print_en;
	UBYTE  u1_fblvl_en;
	UBYTE  u1_meAllDtl_en;
	UBYTE  u8_dhOff_holdFrm;

	UBYTE  u8_fblvl_holdFrm;
	UBYTE  u8_fbLvl_Th0;
	UBYTE  u8_fbLvl_Th1;

	UINT32 u25_meAllDtl_Th0;
	UINT32 u25_meAllDtl_Th1;

	UBYTE  u1_dh_pfvconf_en;
	UINT32 u20_dh_pfvconf_thrL;
	UBYTE  u6_dh_pfvconf_cnt_thr;
	UBYTE  u5_dh_pfvconf_holdfrm;

	UBYTE  u1_lbmc_switch_en;
	UBYTE  u5_lbmc_switch_holdfrm;
	UBYTE  u1_panning_en;
	UBYTE  u5_panning_holdfrm;
	UBYTE  u1_dh_fadeInOut_en;
	UBYTE  u5_dh_fadeInOut_holdfrm;

	UBYTE  u1_dh_sml_rgnAction_en;
	UBYTE  u8_dh_sml_rgnAction_gmv_x_thr;
	UBYTE  u8_dh_sml_rgnAction_gmv_y_thr;
	UINT32 u12_dh_sml_rgnAction_gmv_cnt_thr;
	UINT32 u12_dh_sml_rgnAction_gmv_ucof_thr;
	UINT32 u10_dh_sml_rgnAction_badrgnsad_thr;
	UINT32 u10_dh_sml_rgnAction_goodrgnsad_thr;
	UINT32 u19_dh_sml_rgnAction_bad_pfvdiff_thr;
	UINT32 u19_dh_sml_rgnAction_good_pfvdiff_thr;
	UBYTE  u5_dh_sml_rgnAction_holdfrm;
	UBYTE  u8_dh_sml_rgnAction_apl_thr;
	UBYTE  u5_dh_sml_rgnAction_goodrgn_cnt_thr;
	UBYTE  u5_dh_sml_rgnAction_badrgn_cnt_thr;

	UINT32 u12_dh_sml_rgnAction_bad_gmv_cnt_thr;
	UINT32 u12_dh_sml_rgnAction_bad_gmv_ucof_thr;

	UBYTE  u1_simple_scene_en;

}_PARAM_DH_CLOSE;

typedef struct
{
	UBYTE  u8_fblvl_holdFrm;
	UBYTE  u8_dhOff_holdFrm;
	UBYTE  u8_pfvconf_holdFrm;
	UBYTE  u8_lbmc_mode;
	UBYTE  u8_lbmc_switch_holdfrm;
	UBYTE  u8_panning_mode;
	UBYTE  u8_panning_holdfrm;
	UBYTE  u1_panning_close;

	UBYTE  u1_fblvl_1frm_close;
	UBYTE  u1_fblvl_close;
	UBYTE  u1_meAllDtl_close;
	UBYTE  u1_pfvconf_close;
	UBYTE  u1_lbmc_switch_close;

	UBYTE  u1_closeDh_sig;
	UBYTE  u1_closeDh_act;
	UBYTE  u1_dh_fadeInOut_close;
	UBYTE  u5_dh_fadeInOut_holdfrm;

	UBYTE  u1_dh_simple_scene_close;

	UBYTE  u1_dh_sml_rgnAction_close;
	UBYTE  u5_dh_sml_rgnAction_holdfrm;

	UBYTE  u5_dh_good_rgn_num;
	UBYTE  u5_dh_bad_rgn_num; 

}_OUTPUT_DH_CLOSE;

VOID Dh_close_Init(_OUTPUT_DH_CLOSE *pOutput);
VOID Dh_close_Proc(const _PARAM_DH_CLOSE *pParam, _OUTPUT_DH_CLOSE *pOutput);
VOID Dh_close_sml_rgnAction(const _PARAM_DH_CLOSE *pParam, _OUTPUT_DH_CLOSE *pOutput);

/////////////////////////////////////////////////////////////////////////////
DEBUGMODULE_BEGIN(_PARAM_DH_CLOSE,_OUTPUT_DH_CLOSE)
	ADD_PARAM_DES(UBYTE,  u2_dhClose_bypass,        0, "0:PQL, 1: force ON, 2, force OFF")
	ADD_PARAM_DES(UBYTE,  u1_dbg_print_en,          0, "")
	ADD_PARAM_DES(UBYTE,  u1_fblvl_en,              1, "")
	ADD_PARAM_DES(UBYTE,  u1_meAllDtl_en,           0, "")
	ADD_PARAM_DES(UBYTE,  u8_dhOff_holdFrm,         0, "extra off hold time, minimum is 0")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u8_fblvl_holdFrm,         1, "fblvl off hold time")
	ADD_PARAM_DES(UBYTE,  u8_fbLvl_Th0,           160, ">=, dh on2off")
	ADD_PARAM_DES(UBYTE,  u8_fbLvl_Th1,            80, "<=, dh off2on")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UINT32, u25_meAllDtl_Th0,    100000, "<=, dh on2off")
	ADD_PARAM_DES(UINT32, u25_meAllDtl_Th1,  10000000, ">=, dh off2on")

	////////////  OUTPUT  //////////////////////////////////////////////////////////////

    ADD_OUTPUT(UBYTE,  u8_fblvl_holdFrm)

	ADD_DUMMY_OUTPUT()
    ADD_OUTPUT(UBYTE,  u1_fblvl_close)
	ADD_OUTPUT(UBYTE,  u1_meAllDtl_close)
	ADD_OUTPUT(UBYTE,  u1_closeDh_sig)
	ADD_OUTPUT(UBYTE,  u1_closeDh_act)

DEBUGMODULE_END

#ifdef __cplusplus
}
#endif

#endif