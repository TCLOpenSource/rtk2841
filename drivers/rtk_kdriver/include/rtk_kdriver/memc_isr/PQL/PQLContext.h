#ifndef _PQLCONTEXT_H
#define _PQLCONTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "memc_isr/PQL/PQLMessage.h"
#include "memc_isr/PQL/Read_ComReg.h"
#include "memc_isr/PQL/FBLevelCtrl.h"
#include "memc_isr/PQL/RimCtrl.h"
#include "memc_isr/PQL/FilmDetectCtrl.h"
#include "memc_isr/PQL/FRC_SceneAnalysis.h"
#include "memc_isr/PQL/Dh_close.h"
#include "memc_isr/PQL/Patch_Manage.h"
#include "memc_isr/PQL/Mc_lbmcSwitch.h"
#include "memc_isr/PQL/FRC_phTable.h"
#include "memc_isr/PQL/FRC_LogoDetect.h"

#include "memc_isr/PQL/MESceneAnalysis.h"

#include "memc_isr/PQL/Write_ComReg.h"
////////////////////////////////////////////////////////////////////////
typedef struct
{
	_EXTERNAL_PARAM            _param_external;
	_PARAM_ReadComReg          _param_read_comreg;
	_PARAM_FBLevelCtrl         _param_fblevelctrl;
	_PARAM_RimCtrl             _param_rimctrl;
	_PARAM_DH_CLOSE            _param_dh_close;
	_PARAM_MC_LBMC_SWITCH      _param_mc_lbmcswitch;


	_PARAM_FRC_PH_TABLE        _param_frc_phtable;
	_PARAM_FilmDetectCtrl      _param_filmDetectctrl;
	_PARAM_FRC_LGDet           _param_FRC_LGDet;
	_PARAM_FRC_SceneAnalysis   _param_frc_sceneAnalysis;

	_PARAM_ME_SCENE_ANALYSIS   _param_me_sceneAnalysis;

	_PARAM_WRT_COM_REG         _param_wrt_comreg;

	_PARAM_PATCH_M             _param_Patch_Manage;
}_PQLPARAMETER;

typedef struct
{
	_EXTERNAL_INPUT             _external_data;
	_EXTERNAL_INFO             _external_info;
	_OUTPUT_ReadComReg          _output_read_comreg;
	_OUTPUT_FBLevelCtrl         _output_fblevelctrl;
	_OUTPUT_RimCtrl             _output_rimctrl;
	_OUTPUT_DH_CLOSE            _output_dh_close;

	_OUTPUT_MC_LBMC_SWITCH      _output_mc_lbmcswitch;
	_OUTPUT_FRC_PH_TABLE        _output_frc_phtable;
	_OUTPUT_FilmDetectCtrl      _output_filmDetectctrl;
	_OUTPUT_FRC_LGDet           _output_FRC_LgDet;
	_OUTPUT_FRC_SceneAnalysis   _output_frc_sceneAnalysis;

	_OUTPUT_ME_SCENE_ANALYSIS   _output_me_sceneAnalysis;

	_OUTPUT_WRT_COM_REG         _output_wrt_comreg;
	_OUTPUT_PATCH_M             _output_Patch_Manage;
}_PQLCONTEXT;

typedef enum{
	CAD_N = 0,	// no consider this cadence+timing
	CAD_T,		// support
	CAD_F,		// no support
	CAD_TYPE_NUM,
}CAD_SUPPORT_TYPE;



///////////////////////////////////////////////////////////////////////
VOID PQL_MessageInit(const _PQLPARAMETER *pParam,_PQLCONTEXT *pContext);
VOID PQL_ContextInit(VOID);
VOID PQL_PhaseTableInit(VOID);
BOOL PQL_ReadHDF(UINT32 uiAddr, SINT32 ibitStart, SINT32 ibitEnd, UINT32 *puiVal);
VOID PQL_ContextProc_oneFifth_outputInterrupt(SINT32 iSliceIdx);
VOID PQL_ContextProc_inputInterrupt(SINT32 iSliceIdx);
VOID PQL_ContextProc_outputInterrupt(SINT32 iSliceIdx);
VOID PQL_ContextProc_ReadParam(_PQLPARAMETER *pParam);
CAD_SUPPORT_TYPE PQL_FRCCaseSupportJudge(UBYTE CurCadence);
VOID Debug_Msg_Print(_PQLPARAMETER* g_pParam, _PQLCONTEXT* pContext);
VOID DebugCommandCheck(VOID);
BOOL PQL_GetMEMCActSafeStatus(VOID);
VOID Debug_OnlineMeasure(VOID);
VOID RTICEDebug_OnlineMeasure(UBYTE int_type);

const _PQLCONTEXT *GetPQLContext(VOID);
_PQLPARAMETER *GetPQLParameter(VOID);

DEBUGSERVER_BEGIN(_PQLPARAMETER,_PQLCONTEXT)
	ADD_MODULE_NAME_DES(_EXTERNAL_PARAM,           _param_external,           _EXTERNAL_INPUT,             _external_data,           SystemInput,    "external inputs")
	ADD_MODULE_NAME_DES(_PARAM_ReadComReg,         _param_read_comreg,        _OUTPUT_ReadComReg,          _output_read_comreg,      Read-Register,  "Read Common Registers")
	ADD_MODULE_NAME_DES(_PARAM_FBLevelCtrl,        _param_fblevelctrl,        _OUTPUT_FBLevelCtrl,         _output_fblevelctrl,      Fall-back,      "fallback level control")
	ADD_MODULE_NAME_DES(_PARAM_RimCtrl,            _param_rimctrl,            _OUTPUT_RimCtrl,             _output_rimctrl,          Rim-control,    "rim ctrl")
	ADD_MODULE_NAME_DES(_PARAM_DH_CLOSE,           _param_dh_close,           _OUTPUT_DH_CLOSE,            _output_dh_close,         Dh-close,       "dh close")
	ADD_MODULE_NAME_DES(_PARAM_MC_LBMC_SWITCH,     _param_mc_lbmcswitch,      _OUTPUT_MC_LBMC_SWITCH,      _output_mc_lbmcswitch,    LBMC-switch,    "lbmc switch")
	ADD_MODULE_NAME_DES(_PARAM_FRC_PH_TABLE,       _param_frc_phtable,        _OUTPUT_FRC_PH_TABLE,        _output_frc_phtable,      Phase-Table,    "phase table")
	ADD_MODULE_NAME_DES(_PARAM_FilmDetectCtrl,     _param_filmDetectctrl,     _OUTPUT_FilmDetectCtrl,      _output_filmDetectctrl,   Film-Detect,    "film detect control")
	ADD_MODULE_NAME_DES(_PARAM_FRC_LGDet,          _param_FRC_LGDet,          _OUTPUT_FRC_LGDet,           _output_FRC_LgDet,        Logo-Detect,    "Logo Detect control")
	ADD_MODULE_NAME_DES(_PARAM_FRC_SceneAnalysis,  _param_frc_sceneAnalysis,  _OUTPUT_FRC_SceneAnalysis,   _output_frc_sceneAnalysis,Scene-Analysis, "Scene Analysis")
	ADD_MODULE_DES(_PARAM_ME_SCENE_ANALYSIS,  _param_me_sceneAnalysis,   _OUTPUT_ME_SCENE_ANALYSIS,   _output_me_sceneAnalysis,   "ME scene analysis")
	ADD_MODULE_NAME_DES(_PARAM_WRT_COM_REG,        _param_wrt_comreg,         _OUTPUT_WRT_COM_REG,         _output_wrt_comreg,       Write-Register, "Wrt common reg")
DEBUGSERVER_END

#ifdef __cplusplus
}
#endif


#endif
