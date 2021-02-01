#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/include/PQLAPI.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/PQL/PQLVersion.h"

////////////////////////////////////////////////////////////////////////////
VOID _PQLSERVERDLL PQL_Init(VOID)
{
	PQL_ContextInit();
}

VOID _PQLSERVERDLL PQL_PhaseTable_Init(VOID)
{
	PQL_PhaseTableInit();
}

VOID _PQLSERVERDLL PQL_oneFifth_OutputInterrupt_Proc(SINT32 iSliceIdx)
{
	PQL_ContextProc_oneFifth_outputInterrupt(iSliceIdx);
}

VOID _PQLSERVERDLL PQL_InputInterrupt_Proc(SINT32 iSliceIdx)
{
	PQL_ContextProc_inputInterrupt(iSliceIdx);
}

VOID _PQLSERVERDLL PQL_OutputInterrupt_Proc(SINT32 iSliceIdx)
{
	PQL_ContextProc_outputInterrupt(iSliceIdx);
	// DebugCommandCheck();
}

///////////////////////////////////////////////////////////////////////////////////
VOID _PQLSERVERDLL PQL_Command(const UBYTE CmdID,const _PQL_Command *pCommand)
{
	if(pCommand)
	{
		switch(CmdID)
		{
		case PQL_CMD_MEMC_MODULE_RATIO:
#if 0/*need resolve:compiler error*/

			PQL_CMD_MEMC_Module_ratio(&(pCommand->_stc_memc_module_ratio));
#endif
			break;
		case  PQL_CMD_MEMC_MODE_DEJUDDER:
			PQL_CMD_MEMC_Mode_Dejudder(&(pCommand->u4_memc_mode_dejudder_lvl));
			break;
		case  PQL_CMD_MEMC_MODE_DEBLUR:
			PQL_CMD_MEMC_Mode_Deblur(&(pCommand->u4_memc_mode_deblur_lvl));
			break;
		case  PQL_CMD_MEMC_MODE_FB:
			PQL_CMD_MEMC_Mode_FB(&(pCommand->u4_memc_mode_fb_lvl));
			break;
		case PQL_CMD_INPUT_RESOLUTION:
			PQL_CMD_InResolution(&(pCommand->_input_resolution));
			break;
		case PQL_CMD_INPUT_FRAME_RATE:
			PQL_CMD_InFrameRate(&(pCommand->_input_frameRate));
			break;
		case PQL_CMD_INPUT_FORMAT:
			PQL_CMD_In3DFormat(&(pCommand->_input_3dFormat));
			break;
		case PQL_CMD_OUTPUT_RESOLUTION:
			PQL_CMD_OutResolution(&(pCommand->_output_resolution));
			break;
		case PQL_CMD_OUTPUT_FRAME_RATE:
			PQL_CMD_OutFrameRate(&(pCommand->_output_frameRate));
			break;
		case PQL_CMD_OUTPUT_FORMAT:
			PQL_CMD_Out3DFormat(&(pCommand->_output_3dFormat));
			break;
		case PQL_CMD_OUTPUT_MODE:
			PQL_CMD_OutMode(&(pCommand->_output_mode));
			break;
		case PQL_CMD_OSD_FORCE_MODE:
			PQL_CMD_OsdForceMode(&(pCommand->u1_osd_force_mode));
			break;
		case PQL_CMD_LOWDELAYMODE:
			PQL_CMD_LowDelayMode(&(pCommand->u1_lowDelayMode));
			break;
		case PQL_CMD_PULLDOWNMODE:
			PQL_CMD_PullDownMode(&(pCommand->u8_pulldown_mode));
			break;
		case PQL_CMD_INPUTVSXRAL_FRAMEREPEAT_MODE:
			PQL_CMD_InputVSXral_FrameRepeatMode(&(pCommand->u8_InputVSXral_FrameRepeatMode));
			break;
		case PQL_CMD_MEMC_MODE:
			PQL_CMD_MEMC_Mode(&(pCommand->u3_memcMode));
			break;
		case PQL_CMD_POWERSAVING:
			PQL_CMD_PowerSaving(&(pCommand->u1_powerSaving));
			break;
		}
		PQL_PostMessage(CmdID);
	}
}

VOID _PQLSERVERDLL PQL_Request(const UBYTE ReqID,_PQL_Request *pRequest)
{
	if(pRequest)
	{
		switch(ReqID)
		{
		case PQL_VER:
			{
				int i = 0;
				for(i = 0; i < kw_strlen(PQL_VERSION) + kw_strlen(SVNVER) + 1; i++)
				{
					pRequest->_Version[i] = ' ';
				}
				kw_strcpy(pRequest->_Version, PQL_VERSION, kw_strlen(PQL_VERSION), 0);
				kw_strcat(pRequest->_Version, kw_strlen(PQL_VERSION) + kw_strlen(SVNVER) + 1, " ");
				kw_strcat(pRequest->_Version, kw_strlen(PQL_VERSION) + kw_strlen(SVNVER) + 1, SVNVER);
			}
			break;
		}
	}
}

VOID _PQLSERVERDLL PQL_Info(const UBYTE InfoID,const _PQL_Info*pInfo)
{
	if(pInfo)
	{
		switch(InfoID)
		{
		case  PQL_INFO_SRC_VO:
			PQL_INFO_SRCVO(&(pInfo->u1_SRC_VO));
			break;

		case  PQL_INFO_HDR_CHG:
			PQL_INFO_HDR_Chg(&(pInfo->u1_HDR_Chg));
			break;

		case PQL_INFO_BRIGHTNESS:
			PQL_INFO_Brightness(&(pInfo->u16_mBrightness));
			break;

		case PQL_INFO_CONTRAST:
			PQL_INFO_Contrast(&(pInfo->u16_mContrast));
			break;
		case PQL_INFO_SPEED:
			PQL_INFO_Speed(&(pInfo->s16_mSpeed));
			break;
		case PQL_INFO_ZOOM:
			PQL_INFO_Zoom(&(pInfo->u1_ZoomAction));
			break;	
		case PQL_INFO_SHIFT:
			PQL_INFO_Shift(&(pInfo->u1_ShiftAction));
			break;
		case PQL_INFO_VOSEEK:
			PQL_INFO_VOSeek(&(pInfo->u1_mVOSeek));
			break;
		case PQL_INFO_MEMC_MODE:
			PQL_INFO_MEMCMode(&(pInfo->u16_MEMCMode));
			break;		
		case PQL_INFO_DARKLEVEL:
			PQL_INFO_DarkLevel(&(pInfo->u8_mDarkLevel));
			break;
		case PQL_INFO_HIST_SC:
			PQL_INFO_Hist_SC(&(pInfo->u1_hist_sc_flg));
			break;
		case PQL_INFO_SOCCER_Patch:
			PQL_INFO_SoccerPatch(&(pInfo->u8_mSoccer_holdfrm));
			break;
		case PQL_INFO_PICTUREMODE_CHG:
			PQL_INFO_PictureMode_Chg(&(pInfo->u1_PictureMode_Chg));
			break;
		case PQL_INFO_VIP_STILL:
			PQL_INFO_VIP_Still(&(pInfo->u1_mVIP_Still));
			break;
		case PQL_INFO_MIRACAST:
			PQL_INFO_MiraCast(&(pInfo->u1_mMiraCast));
			break;
		default:;	

		}
		PQL_INFO_PostMessage(InfoID);
	}
}


