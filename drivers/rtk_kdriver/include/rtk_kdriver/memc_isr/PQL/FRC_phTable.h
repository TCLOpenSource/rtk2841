#ifndef _FRC_PH_TABLE_DEF_
#define _FRC_PH_TABLE_DEF_

#include "memc_isr/PQL/FRC_decPhT_generate.h"
//////////////////////////////////////////////////////////////////////////
typedef struct  
{
	UBYTE  u1_phT_autoGen_en;

	UBYTE  u8_dejudder_lvl;
	UBYTE  u8_deblur_lvl;
	UBYTE  u2_candece_id_mode;
	UBYTE  u4_cadence_id;

	UBYTE  in_3dFormat;
	UBYTE  out_3dFormat;
	UBYTE  u2_outMode;

	UBYTE  u1_outLR_LRsamePh;
	UBYTE  u1_filmPh_sw_en;
	UBYTE  u1_filmPh_pf_en;

	UBYTE  u8_input_dly;

	UBYTE u1_Ph_delay_calc_en;
}_PARAM_FRC_PH_TABLE;

typedef struct  
{
	UBYTE                 u8_system_start_lock;
	UBYTE                 u1_prt_trig;
	UBYTE                 u8_phT_print_en_pre;
	UBYTE                 u8_phT_print_frmCnt0;

	////
	PQL_INPUT_3D_FORMAT   in3d_format_pre;
	PQL_OUTPUT_3D_FORMAT  out3d_format_pre;
	UBYTE                 u8_sys_N_pre;
	UBYTE                 u8_sys_M_pre;
	UBYTE                 u8_cadence_id_pre;
	UBYTE                 u8_film_cadence_id_pre;

	UBYTE                 u8_deblur_lvl_pre;
	UBYTE                 u8_dejudder_lvl_pre;
	UBYTE                 u8_pulldown_mode_pre;

	UBYTE                 u8_filmPh;
	UBYTE                 u8_filmPh0_inPh_pre;
	UBYTE                 u8_filmPh0_cnt;

	UBYTE                 u1_outMode_pre;

	/////
	UBYTE                 u1_generate_PC_en;
	UBYTE                 u1_generate_video_en;
	UBYTE                 u1_generate_film_en;
	UBYTE                 u1_generate_vd_22_32_en;

	UBYTE                 u1_phFlbk_film_en;
	UBYTE                 u1_phFlbk_video_en;
	UBYTE                 u1_phFlbk_22_en;
	UBYTE                 u1_phFlbk_32_en;
	
	UBYTE                 u1_inTable_wrt_en;
	UBYTE                 u1_outTable_wrt_en;
	UBYTE                 u1_filmPh_wrt_en;

	/////
	UINT16                u16_phTable_wrt_vd_22_32_endIdx;
	UINT16                u16_phTable_wrt_stIdx;
	UINT16                u16_phTable_wrt_endIdx_p1;
	UINT16		    u16_phTable_wrt_vd_endIdx_p1;

	////////
	UINT32                u32_debug_LSB[2];
	UINT32                u32_debug_MSB[2];

	UBYTE                 u1_is_inFormat_PureVideo;

	//// after image
	UBYTE                 u1_after_img;
	UBYTE                 u1_after_img_type;
	UBYTE                 u8_after_img_cadence_id_pre;

	UBYTE                 u1_lowdelaystate;
	UBYTE                 u1_lowdelay_regen;
	UBYTE                 u1_lowdelay_inframe;
	UINT16		     u8_source_type_pre;
	//UINT16		     u16_MEMCMode_pre; //. backup for miracast
}_OUTPUT_FRC_PH_TABLE;



VOID FRC_phTable_Init( _OUTPUT_FRC_PH_TABLE *pOutput);
VOID FRC_PhaseTable_Init( _OUTPUT_FRC_PH_TABLE *pOutput);

VOID FRC_phTable_Proc(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput);

VOID FRC_phTable_Delay_Calc(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput);

//// 
VOID FRC_phTable_StateMachine(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput);
VOID FRC_phTable_Generate(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput);
VOID FRC_phTable_Write(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput);

//// 
VOID FRC_kphase_sram_clear(UINT16 stIdx, UINT16 endIdx);
VOID FRC_kphase_sram_init(VOID);

//// FRC table write control.
VOID   FRC_phTable_Kphase_ctrl_Wrt(const _PARAM_FRC_PH_TABLE *pParam);
VOID   FRC_phTable_inDec_Wrt(VOID);
VOID   FRC_phTable_outDec_Wrt(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput);

VOID   FRC_phTable_allInfo_Pack_Gen(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput, UINT16 phDecInfo_k, Ph_Dec_Pack_Info *pPackInfo);
UINT32 FRC_phTable_tool_commonDivisor(UINT32 v0, UINT32 v1);
VOID   FRC_phTable_inDec_amend(UBYTE  cadence_id);


VOID FRC_phTable_Init_1n2m_video_22_32_intable(VOID);
VOID   FRC_phTable_inDec_Wrt_init(VOID);

/////////////////////////////////////////////////////////////////////////////
DEBUGMODULE_BEGIN(_PARAM_FRC_PH_TABLE,_OUTPUT_FRC_PH_TABLE)
	ADD_PARAM_DES(UBYTE, u1_phT_autoGen_en,     1, "1-en")
	ADD_PARAM_DES(UBYTE, u8_dejudder_lvl,      17, "0: PQL, else: forceVal = reg - 1.")
	ADD_PARAM_DES(UBYTE, u8_deblur_lvl,        17, "0: PQL, else: forceVal = reg - 1.")
	ADD_PARAM_DES(UBYTE, u2_candece_id_mode,    0, "0-HW, 1-force")
	ADD_PARAM_DES(UBYTE, u4_cadence_id,         2, "video/22/32/else")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  in_3dFormat,          0, "0: PQL, else: forceVal = reg - 1., 2D/SBS/TB/LR/LBL/FP")
	ADD_PARAM_DES(UBYTE,  out_3dFormat,         0, "0: PQL, else: forceVal = reg - 1., 2D/SG/PR")
	ADD_PARAM_DES(UBYTE,  u2_outMode,           0, "0: PQL, else: forceVal = reg - 1., Video / PCmode")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE,  u1_outLR_LRsamePh,    0, "if LR-out, LR same memc-phase")
	ADD_PARAM_DES(UBYTE,  u1_filmPh_sw_en,      1, "")
	ADD_PARAM_DES(UBYTE,  u1_filmPh_pf_en,      0, "")
	//ADD_PARAM_DES(UBYTE,  u1_mePhase_nearIP_en, 0, "")
	ADD_PARAM_DES(UBYTE,  u8_input_dly,         0, "")
	ADD_PARAM_DES(UBYTE,  u1_Ph_delay_calc_en,         0, "")

	//////// output
	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE, u8_deblur_lvl_pre)
	ADD_OUTPUT(UBYTE, u8_dejudder_lvl_pre)


	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE, u8_sys_N_pre)
	ADD_OUTPUT(UBYTE, u8_sys_M_pre)
	ADD_OUTPUT(UBYTE, u8_cadence_id_pre)

	ADD_OUTPUT(UINT32, u32_debug_LSB[0])
	ADD_OUTPUT(UINT32, u32_debug_LSB[1])
	ADD_OUTPUT(UINT32, u32_debug_MSB[0])
	ADD_OUTPUT(UINT32, u32_debug_MSB[1])

	DEBUGMODULE_END

#endif

