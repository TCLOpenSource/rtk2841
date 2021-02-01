#ifndef _FILMDETECTCTRL_DEF_H_
#define _FILMDETECTCTRL_DEF_H_
typedef enum
{
	_FILM_ALL,
	_FILM_5RGN_TOP,
	_FILM_5RGN_BOT,
	_FILM_5RGN_LFT,
	_FILM_5RGN_RHT,
	_FILM_5RGN_CEN,

	_FILM_MOT_NUM,

}_PQL_FILM_MOT_TYPE;

//////////////////////////////////////////////////////////////////////////
typedef struct  
{
	UBYTE   u1_filmDet_bypass;
	UINT32  u32_filmDet_cadence_en;

	UBYTE   u4_Mot_rgn_diffWgt;
	UBYTE   u4_Mot_all_diffWgt;
	UINT32  u27_Mot_all_min;

	UBYTE   u4_enter_22_cntGain;
	UBYTE   u4_enter_32_cntGain;
	UBYTE   u4_enter_else_cntGain;

	UBYTE  u1_quit_motWgt_auto_en;
	UBYTE  u4_quit_bigMot_wgt;
	UBYTE  u4_quit_smlMot_wgt;
	UBYTE  u8_quit_cnt_th;
	UBYTE  u8_quit_prd_th;

	UBYTE  u1_mixMode_det_en;
	UBYTE  u1_mixMode_rgnEn[5];
	UBYTE  u8_mixMode_enter_cntTh;
	UBYTE  u8_mixMode_cnt_max;
	UINT32 u27_mixMode_rgnMove_minMot;
	UBYTE  u4_mixMode_rgnMove_motWgt; // u1.3

	UBYTE u1_FrcCadSupport_En;
	UBYTE u1_QuickSwitch_En;
	UBYTE u1_DbgPrt_FRChg_En;
	UBYTE u1_StillDetect_En;
	UBYTE u3_DbgPrt_Rgn;
	UBYTE  u1_BadEditSlowOut_En;

	
	UBYTE  u5_dbg_param1;
	UINT32 u32_dbg_param2;
	UINT32 u32_dbg_cnt;

}_PARAM_FilmDetectCtrl;

typedef struct  
{
	UINT32 u27_ipme_motionPool[_FILM_MOT_NUM][8]; // pool length = 8.
	UINT32 u32_Mot_sequence[_FILM_MOT_NUM];
	UBYTE  u1_Mot_selBig;

	/////
	UINT32 u27_quit_bigMot[_FILM_MOT_NUM];
	UINT32 u27_quit_smlMot[_FILM_MOT_NUM];
	UINT32 u27_quit_motTh[_FILM_MOT_NUM];
	UBYTE  u8_quit_cnt[_FILM_MOT_NUM];
	UBYTE  u8_quit_prd[_FILM_MOT_NUM];

	/////
	UBYTE  u8_det_cadence_Id[_FILM_MOT_NUM]; // detected cadence according to motion sequence.
	UBYTE  u8_pre_cadence_Id[_FILM_MOT_NUM]; // previous output cadence.
	UBYTE  u8_cur_cadence_Id[_FILM_MOT_NUM]; // current output cadence.
	UBYTE  u8_phase_Idx[_FILM_MOT_NUM];

	/////
	UBYTE  u1_cad_resync_true[_FILM_MOT_NUM];
	UBYTE  u1_cad_fastOut_true;	
	UBYTE  u8_mixMode_cnt;
	UBYTE  u1_mixMode;

	///
	UINT32 u27_FrmMotion_S[_FILM_MOT_NUM];

	/////
	UINT32 u5_dbg_param1_pre;
	UINT32 u32_dbg_param2_pre;
	UINT32 u32_dbg_cnt_hold;
	UBYTE u8_dbg_motion_t;
	/////
	UBYTE  u8_phT_phase_Idx[_FILM_MOT_NUM];

	/////
	UINT32 u27_FrmMotionSort[26];
	UINT32 u27_FrmMotionSortTick[26];

	/////
	UINT32 u27_g_FrmMot_Th[_FILM_MOT_NUM];

	//--output to other module--
	UBYTE  u8_cur_cadence_out[_FILM_MOT_NUM]; // current output cadence.
	UBYTE  u8_phT_phase_Idx_out[_FILM_MOT_NUM];
	UBYTE  u8_flbk_lvl_cad_cnt;
	//--end of "output to other module"

}_OUTPUT_FilmDetectCtrl;

VOID FilmDetect_Init(_OUTPUT_FilmDetectCtrl *pOutput);
VOID FilmDetectCtrl_Proc(const _PARAM_FilmDetectCtrl *pParam, _OUTPUT_FilmDetectCtrl *pOutput);

//////////////////////////////////////////////////////////////////////////
DEBUGMODULE_BEGIN(_PARAM_FilmDetectCtrl,_OUTPUT_FilmDetectCtrl)
	ADD_PARAM_DES(UBYTE,   u1_filmDet_bypass,         1, "1, force cadId = VIDEO")
	ADD_PARAM_DES(UINT32,  u32_filmDet_cadence_en, 8191, "1 bit for 1 cadence, ordering as cadId. video/22/32/...")
	
	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,   u4_Mot_rgn_diffWgt,    8, "u1.3, sequence gen, motion Th gain")
	ADD_PARAM_DES(UBYTE,   u4_Mot_all_diffWgt,    8, "u1.3")
	ADD_PARAM_DES(UINT32,  u27_Mot_all_min,    4096, "for motion seq = 1, motion >= minMot. only for Mot_all")
	
	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,   u4_enter_22_cntGain,   2, "u3.1, enter_cntTh = cad_outLen * gain >> 1")
	ADD_PARAM_DES(UBYTE,   u4_enter_32_cntGain,   2, "u3.1")
	ADD_PARAM_DES(UBYTE,   u4_enter_else_cntGain, 1, "u3.1, except 11'23, others cadence enter_cntTh")
	
	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,   u1_quit_motWgt_auto_en, 0, "1, bigMot/smlMot auto IIR Alpha based on pre & cur Motion")
	ADD_PARAM_DES(UBYTE,   u4_quit_bigMot_wgt,     5, "u1.3, motTh = (bigMot * wgt + smlMot * wgt)>>3.")
	ADD_PARAM_DES(UBYTE,   u4_quit_smlMot_wgt,     3, "")
	ADD_PARAM_DES(UBYTE,   u8_quit_cnt_th,         4, "")
	ADD_PARAM_DES(UBYTE,   u8_quit_prd_th,         2, "")
	
	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,   u1_mixMode_det_en,          0, "1, detect mixMode")
	ADD_PARAM_ARRAY_DES(UBYTE , u1_mixMode_rgnEn, 5,   0, "L->M: rgn lft/rht/top/bot/cen")
	ADD_PARAM_DES(UBYTE,   u8_mixMode_enter_cntTh,     0, "")
	ADD_PARAM_DES(UBYTE,   u8_mixMode_cnt_max,         0, "")
	ADD_PARAM_DES(UINT32,  u27_mixMode_rgnMove_minMot, 0, "")
	ADD_PARAM_DES(UBYTE,   u4_mixMode_rgnMove_motWgt,  0, "u1.3")

	ADD_PARAM_DES(UBYTE,   u1_FrcCadSupport_En,  1, "choose case support")
	ADD_PARAM_DES(UBYTE,   u1_DbgPrt_FRChg_En,  1, "for debug print")
	ADD_PARAM_DES(UBYTE,   u1_StillDetect_En,  1, "for still detect")
	ADD_PARAM_DES(UBYTE,   u3_DbgPrt_Rgn,  1, "choose which rgn dbg print")

	///// output
	ADD_OUTPUT_DES(UBYTE, u8_cur_cadence_Id[_FILM_ALL], "cadence ID")
DEBUGMODULE_END

#endif

