#ifndef _PQL_MESSAGE_H
#define _PQL_MESSAGE_H


#ifdef __cplusplus
extern "C" {
#endif

#include "memc_isr/include/PQLAPI.h"

VOID PQL_PostMessage(const UBYTE CmdID);
VOID PQL_MessageProc(VOID);

VOID PQL_INFO_PostMessage(const UBYTE CmdID);
VOID PQL_INFO_MessageProc(VOID);

/////////////////////////////////////////////////external access to context
VOID PQL_ContextRequest0(_PQL_Request0 *pRequest0);
VOID PQL_ContextRequest1(_PQL_Request1 *pRequest1);

VOID PQL_CMD_MEMC_Module_ratio(const _PQL_MEMC_MODULE_RATIO *pCommand);

VOID PQL_CMD_MEMC_Mode_Dejudder(const UBYTE   *pCommand);
VOID PQL_CMD_MEMC_Mode_Deblur(const    UBYTE  *pCommand);
VOID PQL_CMD_MEMC_Mode_FB(const        UBYTE  *pCommand);

VOID PQL_CMD_InResolution(const  PQL_INPUT_RESOLUTION *pCommand);
VOID PQL_CMD_InFrameRate(const   PQL_INPUT_FRAME_RATE *pCommand);
VOID PQL_CMD_In3DFormat(const     PQL_INPUT_3D_FORMAT *pCommand);

VOID PQL_CMD_OutResolution(const PQL_OUTPUT_RESOLUTION *pCommand);
VOID PQL_CMD_OutFrameRate(const  PQL_OUTPUT_FRAME_RATE *pCommand);
VOID PQL_CMD_Out3DFormat(const    PQL_OUTPUT_3D_FORMAT *pCommand);

VOID PQL_CMD_OutMode(const PQL_OUT_MODE_ *pCommand);
VOID PQL_CMD_LR_Swap(const         UBYTE *pCommand);
VOID PQL_CMD_InsertBlack(const     UBYTE *pCommand);

VOID PQL_CMD_crtc_N(const     UBYTE *pCommand);
VOID PQL_CMD_crtc_M(const     UBYTE *pCommand);
VOID PQL_CMD_OsdForceMode(const     BOOL *pCommand);
VOID PQL_CMD_PullDownMode(const     UBYTE *pCommand);
VOID PQL_CMD_InputVSXral_FrameRepeatMode(const     UBYTE *pCommand);
VOID PQL_CMD_LowDelayMode(const     UBYTE *pCommand);
VOID PQL_CMD_MEMC_Mode(const     UBYTE *pCommand);
VOID PQL_CMD_PowerSaving(const     UBYTE *pCommand);

VOID PQL_INFO_SRCVO(const     UBYTE *pInfo);
VOID PQL_INFO_HDR_Chg(const     UBYTE *pInfo);
VOID PQL_INFO_Brightness(const UINT16  *pInfo);
VOID PQL_INFO_Contrast(const UINT16  *pInfo);
VOID PQL_INFO_Speed(const SINT16  *pInfo);
VOID PQL_INFO_Zoom(const UBYTE  *pInfo);
VOID PQL_INFO_Shift(const UBYTE  *pInfo);
VOID PQL_INFO_SourceType(const UINT16  *pInfo);
VOID PQL_INFO_VOSeek(const UBYTE  *pInfo);
VOID PQL_INFO_MEMCMode(const UINT16  *pInfo);
VOID PQL_INFO_DarkLevel(const UBYTE  *pInfo);
VOID PQL_INFO_Hist_SC(const UBYTE  *pInfo);
VOID PQL_INFO_SoccerPatch(const UBYTE  *pInfo);
VOID PQL_INFO_PictureMode_Chg(const UBYTE  *pInfo);
VOID PQL_INFO_VIP_Still(const     UBYTE *pInfo);
VOID PQL_INFO_MiraCast(const UBYTE  *pInfo);
////////////////////////////////
VOID PQL_REQ_cadenceID(UBYTE *pRequest);


DBGDATA_DEFS(PQL_INPUT_RESOLUTION)
DBGDATA_DEFS(PQL_INPUT_3D_FORMAT)
DBGDATA_DEFS(PQL_INPUT_FRAME_RATE)
DBGDATA_DEFS(PQL_OUTPUT_RESOLUTION)
DBGDATA_DEFS(PQL_OUTPUT_3D_FORMAT)
DBGDATA_DEFS(PQL_OUTPUT_FRAME_RATE)
DBGDATA_DEFS(PQL_OUT_MODE_)


typedef struct
{
	UBYTE u8Dummy;
}_EXTERNAL_PARAM;

typedef struct
{
	_PQL_MEMC_MODULE_RATIO    _stc_memc_module_ratio;

	UBYTE                     u8_deblur_lvl;        // U1.4
	UBYTE                     u8_dejudder_lvl;      // U1.4
	UBYTE                     u8_flbk_lvl;          // U2.6

	PQL_INPUT_RESOLUTION      _input_resolution;
	PQL_INPUT_3D_FORMAT       _input_3dFormat;
	PQL_INPUT_FRAME_RATE      _input_frameRate;

	PQL_OUTPUT_RESOLUTION     _output_resolution;
	PQL_OUTPUT_3D_FORMAT      _output_3dFormat;
	PQL_OUTPUT_FRAME_RATE     _output_frameRate;

	PQL_OUT_MODE_             _output_mode;
	UBYTE                     u1_LR_swap;
	UBYTE                     u1_InsertBlack;
	UBYTE                     u8_crtc_m;
	UBYTE                     u8_crtc_n;
	BOOL		u1_osd_force_mode;
	UBYTE		u8_pulldown_mode;
	UBYTE		u8_InputVSXral_FrameRepeatMode;
	UBYTE		u1_lowDelayMode;
	UBYTE		u3_memcMode;
	BOOL		u1_powerSaving;
	/////
}_EXTERNAL_INPUT;

typedef struct
{
	BOOL                     u1_SRC_VO;
	BOOL                     u1_HDR_Chg;
	UINT16                  u16_Brightness;
	UINT16					u16_Contrast;
	SINT16			s16_speed;
	BOOL			u1_ZoomAction;
	BOOL      		u1_ShiftAction;
	UINT16			u16_source_type;
	UBYTE			u1_mVOSeek;
	UINT16			u16_MEMCMode;
	UBYTE			u8_DarkLevel;
	BOOL			u1_Hist_SC_flg;
	UBYTE			u8_Soccer_holdfrm;
	BOOL			u1_PictureMode_Chg;
	BOOL			u1_VIP_Still;
	UBYTE			u1_mMiraCast;
}_EXTERNAL_INFO;

DEBUGMODULE_BEGIN(_EXTERNAL_PARAM,_EXTERNAL_INPUT)

	ADD_PARAM(UBYTE, u8Dummy,0)

	//////////////////////////////////////////////////////
	ADD_OUTPUT(UBYTE,                 u8_deblur_lvl)
	ADD_OUTPUT(UBYTE,                 u8_dejudder_lvl)
	ADD_OUTPUT(UBYTE,                 u8_flbk_lvl)

	ADD_DUMMY_OUTPUT()

	ADD_OUTPUT(PQL_INPUT_RESOLUTION,  _input_resolution)
	ADD_OUTPUT(PQL_INPUT_3D_FORMAT,  _input_3dFormat)
	ADD_OUTPUT(PQL_INPUT_FRAME_RATE,  _input_frameRate)

	ADD_DUMMY_OUTPUT()

	ADD_OUTPUT(PQL_OUTPUT_RESOLUTION,  _output_resolution)
	ADD_OUTPUT(PQL_OUTPUT_3D_FORMAT,  _output_3dFormat)
	ADD_OUTPUT(PQL_OUTPUT_FRAME_RATE,  _output_frameRate)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(PQL_OUT_MODE_,     _output_mode)
	ADD_OUTPUT(UBYTE,             u1_LR_swap)
	ADD_OUTPUT(UBYTE,             u1_InsertBlack)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,             u8_crtc_m)
	ADD_OUTPUT(UBYTE,             u8_crtc_n)
	ADD_OUTPUT(BOOL,               u1_osd_user_mode)
	ADD_OUTPUT(UBYTE,             u8_pulldown_mode)
	ADD_OUTPUT(UBYTE,             u8_InputVSXral_FrameRepeatMode)
	ADD_OUTPUT(UBYTE,             u1_lowDelayMode)
	ADD_OUTPUT(UBYTE,             u1_powerSaving)

DEBUGMODULE_END

#ifdef __cplusplus
}
#endif


#endif
