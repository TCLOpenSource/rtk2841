#ifndef _FRC_DEC_PHT_GENERATE_H
#define _FRC_DEC_PHT_GENERATE_H

/*-----------------------------------------------------------------------------------------------/
/ YJL: 2015-07-29.
/ 1. provide HW 64 bit & SW member pack & unpack function.
/
/ 2. control in_wrt_table generate and pack based on: cadence
/
/ 3. generate phase table based on:
/        gen_en/flbk_en/cadence/n2m/in_3dFormat/out_3dFormat/filmPh0_inPh/outLR_samePh/ini_status
/
/-------------------------------------------------------------------------------------------------*/

//------------------------------------------
// Definitions of Bits
//------------------------------------------
#define _ZERO                       0x00
#define _BIT0                       0x01
#define _BIT1                       0x02
#define _BIT2                       0x04
#define _BIT3                       0x08
#define _BIT4                       0x10
#define _BIT5                       0x20
#define _BIT6                       0x40
#define _BIT7                       0x80
#define _BIT8                       0x0100
#define _BIT9                       0x0200
#define _BIT10                      0x0400
#define _BIT11                      0x0800
#define _BIT12                      0x1000
#define _BIT13                      0x2000
#define _BIT14                      0x4000
#define _BIT15                      0x8000
#define _BIT16                      0x10000
#define _BIT17                      0x20000
#define _BIT18                      0x40000
#define _BIT19                      0x80000
#define _BIT20                      0x100000
#define _BIT21                      0x200000
#define _BIT22                      0x400000
#define _BIT23                      0x800000
#define _BIT24                      0x1000000
#define _BIT25                      0x2000000
#define _BIT26                      0x4000000
#define _BIT27                      0x8000000
#define _BIT28                      0x10000000
#define _BIT29                      0x20000000
#define _BIT30                      0x40000000
#define _BIT31                      0x80000000


//////////////////////////////////////////////////////////////////////////
#include "memc_isr/PQL/FRC_glb_Context.h"

#define _PHASE_FRC_ME1_TOTAL_BUF_SIZE_     6
#define _PHASE_FRC_ME2_TOTAL_BUF_SIZE_     6
#define _PHASE_FRC_PPFV_BUF_SIZE_      3
#define _PHASE_FRC_ME1FRM_BUF_SIZE_    2
#define _PHASE_FRC_ME2FRM_BUF_SIZE_    1

#define  ME_PHASE_PRECISION          6
#define  MC_PHASE_PRECISION          7

//////////////////////////////////////////////////////////////////////////
typedef  enum { // phase decoder info names, & pack start bit.
	MSB_OUT_3D_ENABLE = 0,
	MSB_FILM_MODE,
	MSB_OUT_PHASE,
	MSB_FILM_PHASE,   // film phase must be next to out-phase. if changed, re-check of _32bit_unpack().

	MSB_ME2_PPFV_BUF_IDX,
	MSB_ME2_IBME_P_INDEX_OFFSET,
	MSB_ME2_IBME_I_INDEX_OFFSET,
	MSB_ME2_PHASE,
	MSB_ME2_FIRST_PHASE,

	MSB_CRTC_MC_HF_INDEX,

	MSB_NAMES_NUM,
}_PH_DECINFO_MSB_NAMES;
typedef   enum    {

	LSB_CRTC_MC_LF_INDEX = 0,

	LSB_ME_LAST_PHASE,
	LSB_ME_DTS_P_INDEX,
	LSB_ME_DTS_I_INDEX,

	LSB_MC_MODE_HF_UPDATE,
	LSB_MC_MODE_LF_UPDATE,
	LSB_MC_CTS_P_INDEX,
	LSB_MC_CTS_I_INDEX,

	LSB_MC_PHASE,
	LSB_MC_HF_INDEX,
	LSB_MC_LF_INDEX,

	LSB_NAMES_NUM,

}_PH_DECINFO_LSB_NAMES_ST;
typedef struct PhaseDecoderPackInfo
{
	UBYTE u8_msb[MSB_NAMES_NUM];
	UBYTE u8_lsb[LSB_NAMES_NUM];
	UBYTE u8_inPhaseLen;
} Ph_Dec_Pack_Info;

//////////////////////////////////////////////////////////////////////////
typedef struct FilmWriteInfo
{
	UBYTE logo_en:1;
	UBYTE me1_in_idx:3;
	UBYTE me2_in_idx:3;

	UBYTE mc_finalPhase:1;
	UBYTE mc_in_idx:3;
} Film_Wrt_Info;

//////////////////////////////////////////////////////////////////////////
typedef enum         {
	_2D_VIDEO = 0,
	_2D_22,
	_2D_32,
	_3D_VIDEO,
	_3D_22,
	_3D_32,
	INI_CAD_END
} _PHT_RECORD_CAD;

typedef struct PhaseDecoderInitInfo
{
	UBYTE ini_me2_i_offset:3;
	UBYTE ini_me2_p_offset:3;
	UBYTE ini_ph_frac_nume;
	UBYTE ini_ph_frac_denom;
	UBYTE ini_me2_chgImg_cnt:3;
} Ph_Dec_Init_Info;

typedef struct PhaseDecoderInfo
{
	UBYTE  out_phase :6;
	UBYTE  film_mode :2;
	UBYTE  film_phase:6;
	UBYTE  in_phase  :4;

	UBYTE  me2_phase:6;
	UBYTE  mc_phase:7;
	UBYTE  frac_phase_nume;

	UBYTE  me1_i_offset:3;
	UBYTE  me1_p_offset:3;

	UBYTE  me2_i_offset:3;
	UBYTE  me2_p_offset:3;

	UBYTE  me1_last:3;
	UBYTE  ppfv_offset:3;

	UBYTE  outPhase_new:4;
	UBYTE  inPhase_new:4;
	UBYTE  cadSeq_new :4;
	UBYTE  me1_wrt_idx_oft:3;
	UBYTE  me2_wrt_idx_oft:3;

} Ph_Dec_Info;


extern Ph_Dec_Info       phTable_DecInfoGen[256];
extern UINT32            phTable_WrtLSB[256];
extern UINT32            phTable_WrtMSB[256];
extern Film_Wrt_Info     phTable_WrtInfoGen[64];
extern Film_Wrt_Info     phTable_WrtInfoGen_Amend[64];

//////////////////////////////////////////////////////////////////////////

typedef struct Ph_decoderTable_Gen_Param
{
	UBYTE u1_goldenPhT_gen_en;
	UBYTE u1_phFlbk_en;

	UBYTE u4_filmPh0_inPh;
	UBYTE u1_LRout_samePh;

	UBYTE  u8_cadence_id;
	UBYTE  u4_sys_N;
	UBYTE  u6_sys_M;

	UBYTE  u8_deblur_lvl;
	UBYTE  u8_dejudder_lvl;
	UBYTE  u8_pulldown_mode;

	PQL_INPUT_3D_FORMAT   in3d_format;
	PQL_OUTPUT_3D_FORMAT  out3d_format;

	UINT16 u16_phT_stIdx;

	UINT16 u8_ph_sys_dly;

}Ph_decGen_Param;

typedef struct Ph_decoderTable_Gen_out
{
	FRC_CADENCE           local_FRC_cadence;

	UBYTE                 u8_fracPh_nume;
	UBYTE                 u8_fracPh_denomi;

	UINT16                u16_phT_stIdx;
	UINT16                u16_phT_endIdx_p1;
	UINT16                u16_phT_length;

	UINT16                u16_filmPh0_tableIdx;
}Ph_decGen_Out;

//////////////////////////////////////////////////////////////////////////
//// 1. HW 64 bit & SW member pack & unpack function.
VOID   FRC_phTable_Init_64bitConfig(VOID);
VOID   FRC_phTable_Init_1n2m_video_22_32(VOID);
VOID   phaseTable_pack(Ph_Dec_Pack_Info *pPackInfo, UINT32 *pU32_pack_LSB, UINT32 *pU32_pack_MSB);
VOID   phaseTable_unpack(UINT32 ui_pack_LSB, UINT32 ui_pack_MSB, Ph_Dec_Info *pPh_DecInfo);
VOID   _32bit_pack(UINT32 *pui_packWord, UBYTE u8_stBit, UBYTE u8_endBit, UINT32 uiVal);
UINT32 _32bit_unpack(UINT32 *pui_packWord, UBYTE u8_stBit, UBYTE u8_endBit);

//// 2. control in_wrt_table generate and pack.
VOID   FRC_phTable_WrtStep_PCmode_Gen(VOID);
VOID   FRC_phTable_WrtStep_VideoMode_Gen( FRC_CADENCE cadInfo);
VOID   FRC_phTable_WrtStep_VideoMode_Gen_idx(FRC_CADENCE cadInfo,UBYTE st_idx);
UBYTE  FRC_phTable_WrtStep_Check_me1(UBYTE u8_filmPh, UBYTE in3d_format);
UBYTE  FRC_phTable_WrtStep_Check_me2(UBYTE u8_filmPh, UBYTE in3d_format);
UBYTE  FRC_phTable_WrtStep_Check_me2_vd_22_32(UBYTE cadence_id, UBYTE u8_filmPh, UBYTE in3d_format);
UINT32 phTable_WrtStep_pack(UBYTE u8_stIdx);
UINT32 phTable_me2_WrtStep_pack(UBYTE u8_stIdx);
UINT32 phTable_WrtStep_pack_vd_22_32(UBYTE u8_stIdx);
UINT32 phTable_me2_WrtStep_pack_vd_22_32(UBYTE u8_stIdx);

//// 3. generate phase table.
VOID FRC_phTable_Init_decGen_config(VOID);
VOID FRC_phTable_LowDelay_Gen_Video(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput, UINT16 u16_k , PQL_INPUT_FRAME_RATE in_fmRate, PQL_OUTPUT_FRAME_RATE out_fmRate, UBYTE u1_lowdelaystate);
VOID FRC_phTable_VideoMode_Proc(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);
VOID FRC_decPhT_PCmode_Proc(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);

////////
VOID FRC_decPhT_goldenGen_Proc(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);
VOID FRC_decPhT_flbk_proc(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);
VOID FRC_phTable_IntpInfo_PackGen(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput, UINT16 phDecInfo_k, Ph_Dec_Pack_Info *pPackInfo);

//////// generate functions
VOID FRC_phTable_basicInfo_Gen(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);
VOID FRC_phTable_inPh_outPh_Gen(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);
VOID FRC_phTable_filmPh_Gen(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);

VOID FRC_phTable_IP_oft_Gen(const Ph_decGen_Param *pParam, Ph_decGen_Out *pOutput);
VOID FRC_phTable_IP_oft_Gen_IPns_me2(Ph_Dec_Info *pDecInfo_pre, Ph_Dec_Info *pDecInfo_cur,UBYTE chgImg_cnt_me2, FRC_CADENCE *pLocalCadence);
VOID FRC_phTable_IP_oft_Gen_IPns_me1(Ph_Dec_Info *pDecInfo_pre, Ph_Dec_Info *pDecInfo_cur,UBYTE chgImg_cnt_me1, FRC_CADENCE *pLocalCadence);
VOID FRC_phTable_IP_oft_Gen_IPs_me2(const Ph_decGen_Param *pParam, Ph_Dec_Info *pDecInfo_pre, Ph_Dec_Info *pDecInfo_cur, UBYTE chgImg_cnt_me2, FRC_CADENCE *pLocalCadence);
VOID FRC_phTable_IP_oft_Gen_IPs_me1(const Ph_decGen_Param *pParam, Ph_Dec_Info *pDecInfo_pre, Ph_Dec_Info *pDecInfo_cur, UBYTE chgImg_cnt_me1, FRC_CADENCE *pLocalCadence);
VOID FRC_phTable_IP_oft_newUsableP_check_me1(UBYTE in3d_format, FRC_CADENCE *pLocalCadence, UBYTE u8_filmPh, UBYTE *pPoffset);
VOID FRC_phTable_IP_oft_newUsableP_check_me2(UBYTE in3d_format, FRC_CADENCE *pLocalCadence, UBYTE u8_filmPh, UBYTE *pPoffset);
////////  flbk functions.
VOID FRC_dejudder_phFlbk_ctrl(UBYTE deJudder_lvl, Ph_decGen_Out *pOutput);
VOID FRC_deblur_phFlbk_ctrl(UBYTE deBlur_lvl, Ph_decGen_Out *pOutput);
VOID FRC_deblur_phFlbk_IPs(Ph_Dec_Info *pDecInfo_n1, Ph_Dec_Info *pDecInfo_0, Ph_Dec_Info *pDecInfo_p1, UBYTE flbk_lvl);


VOID FRC_phTable_me1_deriva_me1(const Ph_decGen_Param *pParam, Ph_Dec_Info *pDecInfo_cur, UBYTE chgImg_cnt_me1, FRC_CADENCE *pLocalCadence);


///////after image
UBYTE after_image_proc(UBYTE u8_filmPhase_pre, UBYTE u8_filmPhase_dtc,UBYTE u8_outPhase, UBYTE u8_cadence_id_pre, UBYTE u8_cadence_id_dtc, UBYTE in_3dFormat,  UBYTE u8_sys_M_pre, UINT16 u16_end_idx);
#endif







