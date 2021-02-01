#include "memc_isr/PQL/PQLPlatformDefs.h"

#include "memc_isr/PQL/PQLGlobalDefs.h"

#include "memc_isr/PQL/FRC_glb_Context.h"
#include "memc_isr/PQL/PQLContext.h"
#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/Driver/regio.h"
#include "tvscalercontrol/panel/panelapi.h"

#include <mach/rtk_log.h>

//////////////////////////////////////////////////////////////////////////

Ph_decGen_Out         phT_dec_PC =
{
	{ 0x01, 0x01,   1,  1, 0,  0x1,   1,  0,  _CAD_VIDEO, 0},	//FRC_CADENCE           local_FRC_cadence;
	0,		//UBYTE                 u8_fracPh_nume;
	1,		//UBYTE                 u8_fracPh_denomi;
	0,		//UINT16                u16_phT_stIdx;
	1,		//UINT16                u16_phT_endIdx_p1;
	1,		//UINT16                u16_phT_length;
	0		//UINT16                u16_filmPh0_tableIdx;
};
Ph_decGen_Out         phT_dec_Video =
{
	{ 0x01, 0x01,   1,  1, 0,  0x1,   1,  0,  _CAD_VIDEO, 0},	//FRC_CADENCE           local_FRC_cadence;
	0,		//UBYTE                 u8_fracPh_nume;
	1,		//UBYTE                 u8_fracPh_denomi;
	0,		//UINT16                u16_phT_stIdx;
	1,		//UINT16                u16_phT_endIdx_p1;
	1,		//UINT16                u16_phT_length;
	0		//UINT16                u16_filmPh0_tableIdx;
};
Ph_decGen_Out         phT_dec_Film =
{
	{ 0xA,  0x03,   1,  2, 0,  0xf,   4,  0,  _CAD_22,    0},	//FRC_CADENCE           local_FRC_cadence;
	0,		//UBYTE                 u8_fracPh_nume;
	1,		//UBYTE                 u8_fracPh_denomi;
	0,		//UINT16                u16_phT_stIdx;
	1,		//UINT16                u16_phT_endIdx_p1;
	1,		//UINT16                u16_phT_length;
	0		//UINT16                u16_filmPh0_tableIdx;
};

//////////////////////////////////////////////////////////////////////////

VOID FRC_phTable_Init(_OUTPUT_FRC_PH_TABLE *pOutput)
{
	pOutput->u8_system_start_lock      = 0;
	pOutput->u1_prt_trig               = 0;
	pOutput->u8_phT_print_en_pre       = 0;
	pOutput->u8_phT_print_frmCnt0      = 0;

	pOutput->u8_deblur_lvl_pre         = (1 << _PHASE_FLBK_LVL_PRECISION);
	pOutput->u8_dejudder_lvl_pre       = (1 << _PHASE_FLBK_LVL_PRECISION);
	pOutput->u8_pulldown_mode_pre      = _PQL_PULLDOWN_MODE_ELSE;

	pOutput->u8_filmPh                 = 0;
	pOutput->u8_filmPh0_inPh_pre       = 0;
	pOutput->u8_filmPh0_cnt            = 0;

	pOutput->u8_cadence_id_pre         = _FRC_CADENCE_NUM_;
	pOutput->u8_film_cadence_id_pre    = _CAD_22;
	pOutput->u8_sys_N_pre              = 1;
	pOutput->u8_sys_M_pre              = 2;

	pOutput->in3d_format_pre           = _PQL_IN_2D;
	pOutput->out3d_format_pre          = _PQL_OUT_2D;

	pOutput->u1_outMode_pre            = 0;

	pOutput->u16_phTable_wrt_stIdx     = 0;
	pOutput->u16_phTable_wrt_endIdx_p1 = 0;
	pOutput->u16_phTable_wrt_vd_endIdx_p1 = 1;

	//// after image
	pOutput->u1_after_img               = 0;
	pOutput->u1_after_img_type             = 0;
	pOutput->u8_after_img_cadence_id_pre   = _CAD_VIDEO;

	///// phase table init setting
	FRC_phTable_Init_64bitConfig();
	FRC_phTable_Init_decGen_config();
	FRC_phTable_Init_1n2m_video_22_32();
	FRC_phTable_Init_1n2m_video_22_32_intable();
}

VOID FRC_PhaseTable_Init(_OUTPUT_FRC_PH_TABLE *pOutput)
{
	UINT32 u32InINT_Clear = 0;

	LogPrintf(DBG_MSG,"FRC_PhaseTable_Init Called!!\r\n");

	// reset wclr bit to sure interrupt can continue processing.
	ReadRegister(KIWI_REG(FRC_TOP__kmc_top__reg_kmc_int_wclr), &u32InINT_Clear);
	u32InINT_Clear = u32InINT_Clear & (~( 1 << (UINT32)1)); // INT_TYPE_VSYNC
	WriteRegister(KIWI_REG(FRC_TOP__kmc_top__reg_kmc_int_wclr), u32InINT_Clear);

	ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_wclr), &u32InINT_Clear);
	u32InINT_Clear = u32InINT_Clear & (~( 1 << (UINT32)1)); // INT_TYPE_VSYNC
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_wclr), u32InINT_Clear);

	pOutput->u8_system_start_lock = 0;
	//pOutput->u1_usecase_call = 1;//k2 method, k3 remove but keep code

	// work around patch
	//k2 method, k3 remove but keep code
	//WriteRegister(FRC_TOP__KME_IPME__reg_ipme_h_flp_alp0_ADDR, 0, 31, 0x24242424);
	//WriteRegister(FRC_TOP__KME_IPME__reg_ipme_v_flp_alp0_ADDR, 0, 31, 0x24242424);
}


VOID FRC_phTable_Proc(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput)
{
	if (pParam->u1_phT_autoGen_en == 1)
	{
		FRC_phTable_StateMachine(pParam, pOutput);
		FRC_phTable_Generate(pParam, pOutput);
		FRC_phTable_Write(pParam, pOutput);  // bai  need think and add
		FRC_phTable_Delay_Calc(pParam, pOutput);

		if(pOutput->u1_prt_trig == 1 && pOutput->u8_phT_print_frmCnt0 > 1)
		{
			LogPrintf(DBG_MSG,"video_stIdx = %d, video_endIdx = %d, film_stIdx = %d, film_endIdx = %d, \r\n ", phT_dec_Video.u16_phT_stIdx, phT_dec_Video.u16_phT_endIdx_p1, phT_dec_Film.u16_phT_stIdx, phT_dec_Film.u16_phT_endIdx_p1);
			LogPrintf(DBG_MSG,"outT_stIdx = %d, outT_endIdx = %d \r\n ", pOutput->u16_phTable_wrt_stIdx, pOutput->u16_phTable_wrt_endIdx_p1);
		}

		if(pOutput->u8_system_start_lock == 0)
		{
			pOutput->u8_system_start_lock = pOutput->u8_system_start_lock + 1;
		}
	}
}

VOID FRC_phTable_Delay_Calc(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput)
{
	// MEMC delay time
	static UBYTE Ph_delay_calc_en_pre = 0;
	UBYTE Ph_delay_calc_en_cur = pParam->u1_Ph_delay_calc_en;
	static UBYTE calc_valid = 0;

	if(Ph_delay_calc_en_cur)
	{
		static UBYTE Ph_gen_en_pre = 0;
		UBYTE Ph_gen_en_cur = pOutput->u1_inTable_wrt_en || pOutput->u1_outTable_wrt_en || pOutput->u1_filmPh_wrt_en;

		static UBYTE u8_interrupt_cnt = 0;
		if((Ph_gen_en_pre == 1 && Ph_gen_en_cur == 0) || (Ph_delay_calc_en_pre == 0 && Ph_delay_calc_en_cur == 1))
		{
			u8_interrupt_cnt = 1;
		}

		Ph_gen_en_pre = Ph_gen_en_cur;

		// continuous 12 frames table content
		// toggle
		const _PQLCONTEXT *s_pContext = GetPQLContext();
		UBYTE u8_sys_N = s_pContext->_output_read_comreg.u8_sys_N_rb;
		UBYTE u8_sys_M = s_pContext->_output_read_comreg.u8_sys_M_rb;

		static UINT32 delay_ms = 0;
		
		if(u8_interrupt_cnt == 1)
		{
			WriteRegister(FRC_TOP__kphase__reg_kphase_meter_enable_ADDR, 27, 27, 0);
		}
		else if(u8_interrupt_cnt == 2)
		{
			WriteRegister(FRC_TOP__kphase__reg_kphase_meter_enable_ADDR, 27, 27, 1);
		}
		else if(u8_interrupt_cnt > 12 * u8_sys_N /u8_sys_M + 5)
		{
			// read me2 I/P index
			UINT32 in_me2_index[12] = {0}, me2_p_index[12] = {0}, me2_phase[12] = {0};
			UBYTE i = 0, j = 0;
			for(i = 0; i < 12; i++)
			{
				//in me2 index
				ReadRegister(FRC_TOP__kphase__regr_kphase_g0_in_me2_index_ADDR + 8*i, 13, 15, &in_me2_index[i]);
				//me2 P index
				ReadRegister(FRC_TOP__kphase__regr_kphase_g0_me2_lbme_p_index_ADDR + 8*i, 19, 21, &me2_p_index[i]);
				//me2 phase
				ReadRegister(FRC_TOP__kphase__regr_kphase_g0_me2_phase_ADDR + 8*i, 25, 30, &me2_phase[i]);
			}

			int delay[12];
 			if(pOutput->u1_is_inFormat_PureVideo)
 			{
 				for(i = 0; i < 12; i++)
				{
					delay[i] = -1;
					if(i > 0 && in_me2_index[i] == in_me2_index[i-1])
						continue;
					for(j = i; j <12; j++)
					{
						if(me2_p_index[j] == in_me2_index[i])
						{
							delay[i] = j - i + 1;
							break;
						}
					}
				}
 			}
			else
			{
				for(i = 0; i < 12; i++)
				{
					delay[i] = -1;
					if(i > 0 && in_me2_index[i] == in_me2_index[i-1])
						continue;
					for(j = i; j <12; j++)
					{
						if(me2_p_index[j] == in_me2_index[i] && me2_phase[j] > 0)
						{
							delay[i] = j - i;
							break;
						}
					}
				}
			}

			UBYTE max_delay = 0;
			for(i = 0; i < 12; i++)
			{				
				if(delay[i] >= 0 && delay[i] > max_delay)
				{
					max_delay = delay[i];
				}
			}

			UINT32 out_framerate;
			RTKReadRegister(0xB80282EC, &out_framerate);
			out_framerate = ((270000000 / (out_framerate + 1)) + 5) / 10;

			delay_ms = (max_delay * 1000) / out_framerate;

			calc_valid = 1;
			
/*
			LogPrintf(DBG_WARNING, "[ph](%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n[write] (%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n[read] (%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n[delay] (%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n", 
				me2_phase[0], me2_phase[1], me2_phase[2], me2_phase[3], me2_phase[4], me2_phase[5],
				me2_phase[6], me2_phase[7], me2_phase[8], me2_phase[9], me2_phase[10], me2_phase[11],
				in_me2_index[0], in_me2_index[1], in_me2_index[2], in_me2_index[3], in_me2_index[4], in_me2_index[5],
				in_me2_index[6], in_me2_index[7], in_me2_index[8], in_me2_index[9], in_me2_index[10], in_me2_index[11],
				me2_p_index[0], me2_p_index[1], me2_p_index[2], me2_p_index[3], me2_p_index[4], me2_p_index[5],
				me2_p_index[6], me2_p_index[7], me2_p_index[8], me2_p_index[9], me2_p_index[10], me2_p_index[11],
				delay[0], delay[1], delay[2], delay[3], delay[4], delay[5], delay[6], delay[7], delay[8], delay[9], delay[10], delay[11]);			
*/
			u8_interrupt_cnt = 0;	
		}

		if(u8_interrupt_cnt > 0)
			u8_interrupt_cnt ++;


		if(calc_valid)
		{
			static UBYTE interval = 0;
			if(interval == 0)
			{
				LogPrintf(DBG_WARNING, "[MEMC][Delay] time = %dms\n", delay_ms);
			}
			interval ++;
		}

	}
	else
	{
		calc_valid = 0;
	}

	Ph_delay_calc_en_pre = Ph_delay_calc_en_cur;
}

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
extern int DC_off_on_flg;
#else
int DC_off_on_flg = 0; // for only define CONFIG_RTK_KDEV_MEMC_INTERRUPT
#endif
extern int LowDelay_regen_chk;
int LowDelayGen_cnt = 0;
//////////////////////////////////////////////////////////////////////////
VOID FRC_phTable_StateMachine(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput)
{
		// current frame signal read back.
	const _PQLCONTEXT     *s_pContext = GetPQLContext();
	UBYTE                  u1_in3D_LR = s_pContext->_output_read_comreg.u1_kphase_inLR;
	UBYTE                    u8_sys_N = s_pContext->_output_read_comreg.u8_sys_N_rb;//1;
	UBYTE                    u8_sys_M = s_pContext->_output_read_comreg.u8_sys_M_rb;//2;
	UBYTE                 u4_in_phase = s_pContext->_output_read_comreg.u4_kphase_inPhase;

	UBYTE              u8_filmPh0_cnt = s_pContext->_output_frc_phtable.u8_filmPh0_cnt;
	UBYTE                   u8_filmPh = s_pContext->_output_filmDetectctrl.u8_phT_phase_Idx_out[_FILM_ALL];   // bai  need make sure

	// value of fb lvl
	UBYTE         u8_flbk_deblur_lvl  = (1 << _PHASE_FLBK_LVL_PRECISION) - (s_pContext->_output_fblevelctrl.u16_blur_lvl >> 4);
	UBYTE         u8_flbk_dejudder_lvl = (1 << _PHASE_FLBK_LVL_PRECISION) - (s_pContext->_output_fblevelctrl.u16_judder_lvl >> 4);
	PQL_OUTPUT_FRAME_RATE  out_fmRate = s_pContext->_external_data._output_frameRate;
	PQL_INPUT_FRAME_RATE	in_fmRate = s_pContext->_external_data._input_frameRate;

	// max of fb lvl
	//dejudder&deblur can only get 5 bits for hardware limitation, we should left shift 3 bit to get 128 value
	UBYTE         u8_dejudder_dft_lvl = (pParam->u8_dejudder_lvl == 0)? (s_pContext->_external_data.u8_dejudder_lvl) : ((pParam->u8_dejudder_lvl << 3) - 1);
	UBYTE         u8_deblur_dft_lvl   = (pParam->u8_deblur_lvl   == 0)? (s_pContext->_external_data.u8_deblur_lvl)   : ((pParam->u8_deblur_lvl << 3)  - 1);


	UBYTE                  u1_outMode = (pParam->u2_outMode      == 0)?  s_pContext->_external_data._output_mode     : (pParam->u2_outMode     - 1);
	PQL_INPUT_3D_FORMAT   in_3dFormat = (pParam->in_3dFormat     == 0)?  s_pContext->_external_data._input_3dFormat  : (PQL_INPUT_3D_FORMAT)(pParam->in_3dFormat - 1);
	PQL_OUTPUT_3D_FORMAT out_3dFormat = (pParam->out_3dFormat    == 0)?  s_pContext->_external_data._output_3dFormat : (PQL_OUTPUT_3D_FORMAT)(pParam->out_3dFormat - 1);
	FRC_CADENCE_ID      u8_cadence_id = (pParam->u2_candece_id_mode  == 0) ? (FRC_CADENCE_ID)(s_pContext->_output_read_comreg.u3_ipme_filmMode_rb>>1) : \
		                                ((pParam->u2_candece_id_mode == 1) ? (FRC_CADENCE_ID)s_pContext->_output_filmDetectctrl.u8_cur_cadence_out[_FILM_ALL] : \
										                                     (FRC_CADENCE_ID)pParam->u4_cadence_id) ;

	UBYTE		u2_isPreCadSupport = PQL_FRCCaseSupportJudge(pOutput->u8_film_cadence_id_pre);
	UBYTE u8_film_cadence_id = (u8_cadence_id != _CAD_VIDEO)? u8_cadence_id : ((u2_isPreCadSupport==CAD_T)? pOutput->u8_film_cadence_id_pre : _CAD_22);
	
	UBYTE u8_cadence_outLen = 0,u8_dejudder_lvl = 0,u8_deblur_lvl = 0,u8_pulldown_mode = 0,u1_is_inFormat_PureVideo = 0;
	BOOL u1_osd_force_mode = 0;

	if(u8_sys_N == 0 || u8_sys_M == 0){
		LogPrintf(DBG_ERROR,"[%s]Fatal error:u8_sys_N=%d,u8_sys_M=%d!!\n",__FUNCTION__,u8_sys_N,u8_sys_M);
		u8_sys_N = 1;
		u8_sys_M = 1;
	}
	if(u8_cadence_id >= _FRC_CADENCE_NUM_){

		LogPrintf(DBG_WARNING,"[%s]Invalid u8_cadence_id=%d.Resume!\n",__FUNCTION__,u8_cadence_id);
		u8_cadence_id = _CAD_VIDEO;
	}
	u8_cadence_outLen = frc_cadTable[u8_cadence_id].cad_outLen;
	// clip fb lvl
	u8_dejudder_lvl = _CLIP_UBOUND_(u8_flbk_dejudder_lvl, u8_dejudder_dft_lvl);
	u8_deblur_lvl   = _CLIP_UBOUND_(u8_flbk_deblur_lvl, u8_deblur_dft_lvl);
	u8_pulldown_mode = s_pContext->_external_data.u8_pulldown_mode;
	u1_osd_force_mode = s_pContext->_external_data.u1_osd_force_mode;
	u1_is_inFormat_PureVideo = ((in_fmRate == _PQL_IN_60HZ||(in_fmRate == _PQL_IN_50HZ)) && (u8_cadence_id == _CAD_VIDEO)) ? 1 : 0;

	// game mode param
//	PQL_INPUT_FRAME_RATE in_fmRate = s_pContext->_external_data._input_frameRate;
	UINT16 u8_source_type = s_pContext->_external_info.u16_source_type;
	//UINT16 u16_MEMCMode = s_pContext->_external_info.u16_MEMCMode; //. backup for miracast
	
	UBYTE u1_isLowDelayMode = (s_pContext->_external_data.u1_lowDelayMode == TRUE) ? 1 : 0;
	UBYTE u1_LowDelayMode_chg = (u1_isLowDelayMode == pOutput->u1_lowdelaystate) ? 0 : 1;
	UBYTE u1_LowDelay_inframe_chg = (in_fmRate == pOutput->u1_lowdelay_inframe) ? 0 : 1;
	UBYTE u1_source_type_chg = (u8_source_type == pOutput->u8_source_type_pre) ? 0 : 1;
	//UBYTE u1_MEMCMode_chg = (u16_MEMCMode == pOutput->u16_MEMCMode_pre) ? 0 : 1; //. backup for miracast
//	UBYTE case_num = 0;
	//


	if(u8_dejudder_lvl >  (1 << _PHASE_FLBK_LVL_PRECISION))
	{
		u8_dejudder_lvl =  (1 << _PHASE_FLBK_LVL_PRECISION);
	}

	if(u8_deblur_lvl >  (1 << _PHASE_FLBK_LVL_PRECISION))
	{
		u8_deblur_lvl =  (1 << _PHASE_FLBK_LVL_PRECISION);
	}

	if(u1_osd_force_mode == 1) // clear or user mode
	{
		if (u1_is_inFormat_PureVideo == 1)
		{
			u8_dejudder_lvl =  (1 << _PHASE_FLBK_LVL_PRECISION);
		}
		else
		{
			u8_deblur_lvl =  (1 << _PHASE_FLBK_LVL_PRECISION);
		}
	}


	if (out_fmRate <= _PQL_OUT_60HZ || out_3dFormat != _PQL_OUT_2D)
	{
		u8_deblur_lvl = (1 << _PHASE_FLBK_LVL_PRECISION);
	}

	// synthesize to generate change signal, and merged into phase table control signal
	{
		//UBYTE u1_phT_gen_nor_drive, u1_outTable_PC_wrt, u1_outTable_Video_wrt;
		UBYTE u1_n2m_switch          = (u8_sys_N == pOutput->u8_sys_N_pre && u8_sys_M == pOutput->u8_sys_M_pre)? 0 : 1;
		UBYTE u1_in3dFormat_chg      = (in_3dFormat     == pOutput->in3d_format_pre    )? 0 : 1;
		UBYTE u1_out3dFormat_chg     = (out_3dFormat    == pOutput->out3d_format_pre   )? 0 : 1;
		UBYTE u1_outMode_chg         = (u1_outMode      == pOutput->u1_outMode_pre     )? 0 : 1;
		UBYTE u1_cadence_chg         = (u8_cadence_id   == pOutput->u8_cadence_id_pre  )? 0 : 1;
		UBYTE u1_film_cadence_chg    = (u2_isPreCadSupport==CAD_T) ? ((u8_cadence_id   == pOutput->u8_film_cadence_id_pre || u8_cadence_id == _CAD_VIDEO) ? 0 : 1) : 
														((pOutput->u8_film_cadence_id_pre==_CAD_22)? 0 : 1);
		u1_film_cadence_chg = ((u8_film_cadence_id==pOutput->u8_film_cadence_id_pre)?0:1);

		UBYTE u1_dejudder_lvl_chg    = (u8_dejudder_lvl    == pOutput->u8_dejudder_lvl_pre)? 0 : 1;
		UBYTE u1_deblur_lvl_chg      = (u8_deblur_lvl      == pOutput->u8_deblur_lvl_pre  )? 0 : 1;
		UBYTE u1_pulldown_mode_chg	 = (u8_pulldown_mode == pOutput->u8_pulldown_mode_pre)? 0 : 1;

#if 0
		UBYTE u8_sysN_cadOut_comDiv  = (UBYTE)FRC_phTable_tool_commonDivisor(u8_sys_N, (in_3dFormat == _PQL_IN_LR? u8_cadence_outLen*2 : u8_cadence_outLen));
		UBYTE u1_is2D_is3DL = ((in_3dFormat != _PQL_IN_LR) ||((in_3dFormat == _PQL_IN_LR) && (u1_in3D_LR == _PQL_3D_FRAME_L)));
		UBYTE u8_filmPh0_cnt_cur     =  u1_cadence_chg? 0 : ((u1_is2D_is3DL && u8_filmPh == 0)? (u8_filmPh0_cnt + 1) % u8_sys_N : u8_filmPh0_cnt);
		UBYTE u4_in_phase_use = (u8_sys_N == 0) ? 0 : ((u4_in_phase+1)%u8_sys_N);
		UBYTE u1_filmPh0_inPh_chg    = (u1_is2D_is3DL && u8_filmPh == 0 && u8_filmPh0_cnt_cur == 0 && (u4_in_phase_use % u8_sysN_cadOut_comDiv) != pOutput->u8_filmPh0_inPh_pre)? 1 : 0;

		pOutput->u8_filmPh0_inPh_pre  = u1_filmPh0_inPh_chg? (u4_in_phase_use % u8_sysN_cadOut_comDiv) : pOutput->u8_filmPh0_inPh_pre;
		pOutput->u8_filmPh0_cnt       = u8_filmPh0_cnt_cur;

#else
		UBYTE u8_sysN_cadOut_comDiv  = (UBYTE)FRC_phTable_tool_commonDivisor(u8_sys_N, (in_3dFormat == _PQL_IN_LR? u8_cadence_outLen*2 : u8_cadence_outLen));
		UBYTE u4_in_phase_reverse    =  (u8_sysN_cadOut_comDiv != 2) ? u4_in_phase : (u4_in_phase == 0 ? 1 : 0);
		UBYTE u8_filmPh0_cnt_cur     =  u1_cadence_chg? 0 : ((in_3dFormat == _PQL_IN_LR? (u1_in3D_LR == _PQL_3D_FRAME_L? 1:0): 1) && u8_filmPh == 0? (u8_filmPh0_cnt + 1) % u8_sys_N : u8_filmPh0_cnt);
		UBYTE u1_filmPh0_inPh_chg    = ((in_3dFormat == _PQL_IN_LR?  (u1_in3D_LR == _PQL_3D_FRAME_L? 1:0): 1) && u8_filmPh == 0 && u8_filmPh0_cnt_cur == 0 && (u4_in_phase_reverse % u8_sysN_cadOut_comDiv) != pOutput->u8_filmPh0_inPh_pre)? 1 : 0;


		pOutput->u8_filmPh0_inPh_pre  = u1_filmPh0_inPh_chg? (u4_in_phase_reverse % u8_sysN_cadOut_comDiv) : pOutput->u8_filmPh0_inPh_pre;
		pOutput->u8_filmPh0_cnt       = u8_filmPh0_cnt_cur;
#endif

	//*****  LowDelayMode  *****//
		// force apply LowDelay
//		UINT32 u32_low_delay;
//		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_fc_ADDR, 0, 31, &u32_low_delay);
//		if(((u32_low_delay >> 1) & 1) == 1){
//			pOutput->u1_lowdelay_regen = 1;
//			WriteRegister(FRC_TOP__PQL_1__pql_logo_dummy_fc_ADDR, 1, 1, 0);
//		}
//		u32_low_delay = (u32_low_delay>>4) & 0x00000ff;

		// In_FrameRate change
		if(u1_LowDelay_inframe_chg == 1){
			printk(KERN_EMERG"$$$   hi_LowDelay_InFrameRate_Chg = (%d)(%d)   $$$\n\r", in_fmRate, pOutput->u1_lowdelay_inframe);
		}
		// u1_source_type change
		if(u1_source_type_chg == 1){
			printk(KERN_EMERG"$$$   hi_source_type_chg = (%d)(%d)   $$$\n\r", u8_source_type, pOutput->u8_source_type_pre);
		}

		#if 0 //. backup for miracast
		if(u1_MEMCMode_chg == 1){
			printk(KERN_EMERG"$$$   hi_MEMCMode_chg = (%d)(%d)   $$$\n\r", u16_MEMCMode, pOutput->u16_MEMCMode_pre);
		}
		#endif
		static UINT32 u8_LowDelay_cnt = 0;
#if 1
		if((u1_outMode_chg == 1) || (u1_n2m_switch == 1) || (u1_in3dFormat_chg == 1) || (u1_out3dFormat_chg == 1) || (pOutput->u8_system_start_lock == 0) || (u1_LowDelayMode_chg == 1) || (u1_LowDelay_inframe_chg == 1) || (DC_off_on_flg == 1) || (u1_source_type_chg == 1) /*|| ((s_pContext->_external_info.u1_mMiraCast == 1)&&(u1_MEMCMode_chg))*//*backup for miracast*/){
			pOutput->u1_generate_video_en = 1;
			
			u8_LowDelay_cnt = 1;
			printk(KERN_EMERG"$$$   hi_LowDelay_cnt_01 = (%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)   $$$\n\r", u8_LowDelay_cnt, u1_outMode_chg, u1_n2m_switch, u1_in3dFormat_chg, u1_out3dFormat_chg, pOutput->u8_system_start_lock, u1_LowDelayMode_chg, DC_off_on_flg, u1_LowDelay_inframe_chg, u1_source_type_chg, u1_isLowDelayMode);
			DC_off_on_flg = 0;
		}
		else if((u8_LowDelay_cnt > 0) && (u8_LowDelay_cnt <= 120)){
			pOutput->u1_generate_video_en = 0;
			u8_LowDelay_cnt++;
			//printk(KERN_EMERG"$$$   hi_LowDelay_cnt_02 = (%d)   $$$\n\r", u8_LowDelay_cnt);
		}
		else{
			pOutput->u1_generate_video_en = 0;
			u8_LowDelay_cnt = 0;
		}

		if(u8_LowDelay_cnt > 119){
			pOutput->u1_lowdelay_regen = 1;
			LowDelayGen_cnt++;
			printk(KERN_EMERG"$$$   hi_01_LowDelayRegen = (%d)(%d)(%d)(%d)(%d)   $$$\n\r", pOutput->u1_lowdelay_regen, u1_LowDelayMode_chg, u1_LowDelay_inframe_chg, u8_LowDelay_cnt, LowDelayGen_cnt);
			u8_LowDelay_cnt = 0;
		}
		else{
			pOutput->u1_lowdelay_regen = 0;
		}
		
		if(pOutput->u1_lowdelay_regen == 1){
			pOutput->u1_generate_video_en = 1;
		}
#else
		if((u1_isLowDelayMode == 1) && (u1_outMode_chg || u1_n2m_switch || u1_in3dFormat_chg || u1_out3dFormat_chg||pOutput->u8_system_start_lock == 0 || (u1_LowDelayMode_chg == 1) || (u1_LowDelay_inframe_chg == 1) || (DC_off_on_flg == 1) || (u1_source_type_chg == 1))){
			u8_LowDelay_cnt = 1;
			printk(KERN_EMERG"$$$   hi_LowDelay_cnt_01 = (%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)   $$$\n\r", u8_LowDelay_cnt, u1_outMode_chg, u1_n2m_switch, u1_in3dFormat_chg, u1_out3dFormat_chg, pOutput->u8_system_start_lock, u1_LowDelayMode_chg, DC_off_on_flg, u1_LowDelay_inframe_chg, u1_source_type_chg, u1_isLowDelayMode);
			DC_off_on_flg = 0;
		}
		else if(u8_LowDelay_cnt > 0){
			u8_LowDelay_cnt++;
			printk(KERN_EMERG"$$$   hi_LowDelay_cnt_02 = (%d)   $$$\n\r", u8_LowDelay_cnt);
		}
		else if(u8_LowDelay_cnt > 120){
			u8_LowDelay_cnt = 0;
			printk(KERN_EMERG"$$$   hi_LowDelay_cnt_03 = (%d)   $$$\n\r", u8_LowDelay_cnt);
		}

		if(u8_LowDelay_cnt > 119)
		{
			pOutput->u1_lowdelay_regen = 1;
			LowDelayGen_cnt++;
			printk(KERN_EMERG"$$$   hi_01_LowDelayRegen = (%d)(%d)(%d)(%d)(%d)   $$$\n\r", pOutput->u1_lowdelay_regen, u1_LowDelayMode_chg, u1_LowDelay_inframe_chg, u8_LowDelay_cnt, LowDelayGen_cnt);
			u8_LowDelay_cnt = 0;
		}
		else
			pOutput->u1_lowdelay_regen = 0;
	#if 0
		if(u1_isLowDelayMode == 0){
			u8_LowDelay_cnt = 0;
		}
	#endif
#endif
	//*******************************//

		// synthesize
#if 0
		u1_phT_gen_nor_drive          = (u1_outMode_chg == 1 || u1_n2m_switch || u1_in3dFormat_chg || u1_out3dFormat_chg || pOutput->u8_system_start_lock == 0)? 1 : 0;

		pOutput->u1_generate_PC_en    = (u1_outMode == _PQL_OUT_PC_MODE    && (u1_outMode_chg == 1 || u1_n2m_switch))? 1 : 0;
		pOutput->u1_generate_video_en = (u1_outMode == _PQL_OUT_VIDEO_MODE &&  u1_phT_gen_nor_drive)? 1 : 0;
		//pOutput->u1_generate_film_en  = (u1_outMode == _PQL_OUT_VIDEO_MODE && (u1_phT_gen_nor_drive || u1_film_cadence_chg))? 1 : 0;
		pOutput->u1_generate_film_en  = (u1_outMode == _PQL_OUT_VIDEO_MODE && (u1_phT_gen_nor_drive || u1_filmPh0_inPh_chg|| u1_film_cadence_chg))? 1 : 0;

		pOutput->u1_phFlbk_video_en   = (u1_outMode == _PQL_OUT_VIDEO_MODE && (pOutput->u1_generate_video_en || u1_deblur_lvl_chg || u1_dejudder_lvl_chg))? 1 : 0;
		pOutput->u1_phFlbk_film_en    = (u1_outMode == _PQL_OUT_VIDEO_MODE && (pOutput->u1_generate_film_en || u1_deblur_lvl_chg || u1_dejudder_lvl_chg) )? 1 : 0;


		u1_outTable_PC_wrt            = (pOutput->u1_generate_PC_en || u1_out3dFormat_chg)? 1 : 0;
		u1_outTable_Video_wrt         = (pOutput->u1_phFlbk_film_en || pOutput->u1_phFlbk_video_en)? 1 : 0;
		pOutput->u1_inTable_wrt_en    = (u1_outMode_chg || u1_cadence_chg)? 1 : 0;
		pOutput->u1_outTable_wrt_en   = ((u1_outMode == _PQL_OUT_PC_MODE && u1_outTable_PC_wrt) || (u1_outMode == _PQL_OUT_VIDEO_MODE && u1_outTable_Video_wrt))? 1 : 0;
		pOutput->u1_filmPh_wrt_en     = (u1_outMode_chg || u1_cadence_chg)? 1 : 0;

#else
		pOutput->u1_generate_PC_en    =  (u1_outMode_chg || u1_n2m_switch || pOutput->u8_system_start_lock == 0)? 1 : 0;
		//pOutput->u1_generate_video_en = (u1_outMode_chg || u1_n2m_switch || u1_in3dFormat_chg || u1_out3dFormat_chg||pOutput->u8_system_start_lock == 0 )? 1 : 0;  ||(u1_LowDelayMode_chg == 1) || ((u1_isLowDelayMode == 1) && (DC_off_on_flg == 1))

		//*** merge into line:438 with game mode low delay ***//
		//pOutput->u1_generate_video_en = (u1_outMode_chg || u1_n2m_switch || u1_in3dFormat_chg || u1_out3dFormat_chg || pOutput->u8_system_start_lock == 0 || (u1_LowDelayMode_chg == 1) || (pOutput->u1_lowdelay_regen == 1) || (u1_LowDelay_inframe_chg == 1) || ((u1_isLowDelayMode == 1) && (DC_off_on_flg == 1)) || (u1_source_type_chg == 1))? 1 : 0;
		//********************************************//
		
		if(pOutput->u1_generate_video_en == 1){
			printk(KERN_EMERG"$$$   hi_u1_generate_video_en = (%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)   $$$\n\r", pOutput->u1_lowdelay_regen, u1_outMode_chg, u1_n2m_switch, u1_in3dFormat_chg, u1_out3dFormat_chg, pOutput->u8_system_start_lock, u1_LowDelayMode_chg, u1_LowDelay_inframe_chg, u8_LowDelay_cnt, in_fmRate, out_fmRate, u1_isLowDelayMode, LowDelayGen_cnt, u1_source_type_chg);
			if(u1_in3dFormat_chg){
				printk(KERN_EMERG"$$$   hi_in3dFormat_chg   $$$\n\r$$$   (pre_in, cur_in) = (%d, %d)   $$$\n\r", pOutput->in3d_format_pre, in_3dFormat);
                      }
			if(u1_out3dFormat_chg){
				printk(KERN_EMERG"$$$   hi_out3dFormat_chg   $$$\n\r$$$   (pre_out, cur_out) = (%d, %d)   $$$\n\r", pOutput->out3d_format_pre, out_3dFormat);
			}
		}
		pOutput->u1_generate_film_en  = (u1_outMode_chg || u1_n2m_switch || u1_in3dFormat_chg || u1_out3dFormat_chg||pOutput->u8_system_start_lock == 0|| u1_filmPh0_inPh_chg|| u1_film_cadence_chg)? 1 : 0;

		pOutput->u1_phFlbk_video_en  = (pOutput->u1_generate_video_en || pOutput->u1_generate_film_en || u1_deblur_lvl_chg || u1_dejudder_lvl_chg || u1_pulldown_mode_chg)? 1 : 0;
		pOutput->u1_phFlbk_film_en  = (pOutput->u1_generate_video_en || pOutput->u1_generate_film_en || u1_deblur_lvl_chg || u1_dejudder_lvl_chg || u1_pulldown_mode_chg)? 1 : 0;


		UBYTE u1_inTable_wrt_PC_en    = (u1_outMode == _PQL_OUT_PC_MODE && (u1_outMode_chg ||pOutput->u8_system_start_lock == 0))? 1 : 0;
		UBYTE u1_inTable_wrt_Video_en = (u1_outMode == _PQL_OUT_VIDEO_MODE && (u1_outMode_chg || u1_cadence_chg||(pOutput->u8_system_start_lock == 0)))? 1 : 0;
		pOutput->u1_inTable_wrt_en    = (u1_inTable_wrt_PC_en || u1_inTable_wrt_Video_en);

		UBYTE u1_outTable_wrt_PC_en   = (u1_outMode == _PQL_OUT_PC_MODE && (pOutput->u1_generate_PC_en))? 1 : 0;
		UBYTE u1_outTable_wrt_Video_en   = (u1_outMode == _PQL_OUT_VIDEO_MODE && (pOutput->u1_phFlbk_film_en || pOutput->u1_phFlbk_video_en))? 1 : 0;
		pOutput->u1_outTable_wrt_en   = (u1_outTable_wrt_PC_en || u1_outTable_wrt_Video_en);

		UBYTE u1_filmPh_wrt_PC_en     = (u1_outMode == _PQL_OUT_PC_MODE && (u1_outMode_chg ||pOutput->u8_system_start_lock == 0)) ? 1 : 0;
		UBYTE u1_filmPh_wrt_Video_en     = (u1_outMode == _PQL_OUT_VIDEO_MODE && (u1_outMode_chg || u1_cadence_chg || u1_filmPh0_inPh_chg ||pOutput->u8_system_start_lock == 0)) ? 1 : 0;
		pOutput->u1_filmPh_wrt_en     = (u1_filmPh_wrt_PC_en || u1_filmPh_wrt_Video_en);

#endif
		//// after image
		if(0)
		{
			if(u1_outMode == _PQL_OUT_VIDEO_MODE && (u1_cadence_chg == 1 || s_pContext->_output_filmDetectctrl.u1_cad_resync_true[0] == 1))  // bai need make sure
			{
				pOutput->u1_after_img = 1;
				pOutput->u8_after_img_cadence_id_pre = pOutput->u8_cadence_id_pre;

				if(u1_cadence_chg == 1)
				{
					pOutput->u1_after_img_type = 0;
					//LogPrintf(DBG_MSG,"bai print .cadence_change = 1, pre_cad_id = %d, cur_cad_id = %d, filmph_cur = %d \r\n", pOutput->u8_cadence_id_pre, u8_cadence_id,s_pContext->_output_filmDetectctrl.u8_PhaseIdx);
				}
				if(s_pContext->_output_filmDetectctrl.u1_cad_resync_true[0] == 1)
				{
					pOutput->u1_after_img_type = 1;
					//LogPrintf(DBG_MSG,"bai print . resync_flag = %d \r\n", s_pContext->_output_filmDetectctrl.u1_cad_resync_true[0]);
				}
			}
		}

	}

	// update states
	{
		pOutput->in3d_format_pre        = in_3dFormat;
		pOutput->out3d_format_pre       = out_3dFormat;
		pOutput->u8_sys_N_pre           = u8_sys_N;
		pOutput->u8_sys_M_pre           = u8_sys_M;
		pOutput->u8_cadence_id_pre      = u8_cadence_id;
		pOutput->u8_film_cadence_id_pre = (u8_cadence_id != _CAD_VIDEO)? u8_cadence_id : ((u2_isPreCadSupport==CAD_T)? pOutput->u8_film_cadence_id_pre : _CAD_22);

		pOutput->u8_deblur_lvl_pre      = u8_deblur_lvl;
		pOutput->u8_dejudder_lvl_pre    = u8_dejudder_lvl;
		pOutput->u8_pulldown_mode_pre	= u8_pulldown_mode;
		pOutput->u8_filmPh              = u8_filmPh;  // bai
		pOutput->u1_outMode_pre         = u1_outMode;
		pOutput->u1_is_inFormat_PureVideo  = u1_is_inFormat_PureVideo;

		pOutput->u1_lowdelaystate = u1_isLowDelayMode;
		pOutput->u1_lowdelay_inframe = in_fmRate;
		pOutput->u8_source_type_pre = u8_source_type;
		//pOutput->u16_MEMCMode_pre = u16_MEMCMode; //. backup for miracast
		if(LowDelay_regen_chk == 1){   // prevent force apply error
			pOutput->u1_lowdelay_regen = 0;
			LowDelay_regen_chk = 0;
		}
	}

	// debug print signal control.
	/*	if(pParam->u1_filmPh_pf_en == 1)
		{
			LogPrintf(DBG_MSG,"PC_gen = %d, video_gen = %d, video_flbk = %d, ", pOutput->u1_generate_PC_en, pOutput->u1_generate_video_en, pOutput->u1_phFlbk_video_en);
			LogPrintf(DBG_MSG,"film_gen = %d, film_flbk = %d, ", pOutput->u1_generate_film_en, pOutput->u1_phFlbk_film_en);
			LogPrintf(DBG_MSG,"in_wrt = %d, out_wrt = %d, film_wrt = %d, \r\n", pOutput->u1_inTable_wrt_en, pOutput->u1_outTable_wrt_en, pOutput->u1_filmPh_wrt_en);
			LogPrintf(DBG_MSG,"film_cadence = %d, ", pOutput->u8_cadence_id_pre);
		}*/

}

VOID FRC_phTable_Generate(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput)
{
	const _PQLCONTEXT     *s_pContext = GetPQLContext();
	Ph_decGen_Param  phT_decGen_param;

	phT_decGen_param.u1_LRout_samePh  = pParam->u1_outLR_LRsamePh;
	phT_decGen_param.u4_sys_N         = pOutput->u8_sys_N_pre;
	phT_decGen_param.u6_sys_M         = pOutput->u8_sys_M_pre;
	phT_decGen_param.u8_deblur_lvl    = pOutput->u8_deblur_lvl_pre;
	phT_decGen_param.u8_dejudder_lvl  = pOutput->u8_dejudder_lvl_pre;
	phT_decGen_param.u8_pulldown_mode = pOutput->u8_pulldown_mode_pre;
	phT_decGen_param.in3d_format      = pOutput->in3d_format_pre;
	phT_decGen_param.out3d_format     = pOutput->out3d_format_pre;


	if(pOutput->u1_generate_video_en == 1 || pOutput->u1_generate_film_en == 1)
	{
		UINT32 VSize = Get_DISP_DEN_END_VPOS() - Get_DISP_DEN_STA_VPOS();

		// slave mode, using memc output timing
		UINT32 VTotal;
		RTKReadRegister(0xb8028604, &VTotal);
		VTotal = VTotal & 0x1FFF;
		
		if(VSize > 2100)
		{
			if(VTotal < 2000)
			{
				VTotal = 0x8ca;
				LogPrintf(DBG_WARNING, "4k VTotal is error, use default value 0x8ca \n");
			}
		}
		else if(VSize > 1000)
		{
			if(VTotal < 1000)
			{
				VTotal = 0x44c;
				LogPrintf(DBG_WARNING, "2k VTotal is error, use default value 0x44c \n");
			}
		}
		else
		{
			VTotal = 0x8ca;
			LogPrintf(DBG_WARNING, "VSize is error, use default VTotal value 0x8ca \n");
		}

		phT_decGen_param.u8_ph_sys_dly = ((s_pContext->_output_read_comreg.u13_dec_vtrig_dly * phT_decGen_param.u4_sys_N * 100)\
			/ VTotal) + (pParam->u8_input_dly * phT_decGen_param.u6_sys_M);
	}


	///// generate of table
	if (pOutput->u1_outMode_pre == _PQL_OUT_PC_MODE)
	{
	// pc mode
	if (pOutput->u1_generate_PC_en == 1)
		{
			phT_decGen_param.u16_phT_stIdx    = 0;

			FRC_phTable_WrtStep_PCmode_Gen();
			FRC_decPhT_PCmode_Proc(&phT_decGen_param, &phT_dec_PC);

			pOutput->u16_phTable_wrt_stIdx     = phT_dec_PC.u16_phT_stIdx;
			pOutput->u16_phTable_wrt_endIdx_p1 = phT_dec_PC.u16_phT_endIdx_p1;
			pOutput->u16_phTable_wrt_vd_endIdx_p1 = phT_dec_PC.u16_phT_endIdx_p1;
		}
	}
	else
	{

		// in wrt Table //LISA_161009
		if(pOutput->u1_inTable_wrt_en == 1 || pOutput->u1_generate_video_en == 1)
		{
			FRC_phTable_WrtStep_VideoMode_Gen(frc_cadTable[_CAD_VIDEO]);
		}

  		// out Phase Table
	 	//video
		phT_decGen_param.u1_goldenPhT_gen_en = pOutput->u1_generate_video_en;
		phT_decGen_param.u1_phFlbk_en        = pOutput->u1_phFlbk_video_en;
		phT_decGen_param.u4_filmPh0_inPh    = 0;
		phT_decGen_param.u8_cadence_id       = _CAD_VIDEO;
		phT_decGen_param.u16_phT_stIdx       = 0;

		FRC_phTable_VideoMode_Proc(&phT_decGen_param, &phT_dec_Video);

		pOutput->u16_phTable_wrt_stIdx     = phT_dec_Video.u16_phT_stIdx;
		pOutput->u16_phTable_wrt_endIdx_p1 = phT_dec_Video.u16_phT_endIdx_p1;
		pOutput->u16_phTable_wrt_vd_endIdx_p1 = phT_dec_Video.u16_phT_endIdx_p1;

		// in wrt Table //LISA_161009
		if(pOutput->u1_inTable_wrt_en == 1 || pOutput->u1_generate_film_en == 1)
		{
			FRC_phTable_WrtStep_VideoMode_Gen(frc_cadTable[pOutput->u8_film_cadence_id_pre]);
		}

		//film
		phT_decGen_param.u1_goldenPhT_gen_en = pOutput->u1_generate_film_en;
		phT_decGen_param.u1_phFlbk_en        = pOutput->u1_phFlbk_film_en;
		phT_decGen_param.u4_filmPh0_inPh     = pOutput->u8_filmPh0_inPh_pre;
		phT_decGen_param.u8_cadence_id       = pOutput->u8_film_cadence_id_pre;
		phT_decGen_param.u16_phT_stIdx       = phT_dec_Video.u16_phT_endIdx_p1;

		FRC_phTable_VideoMode_Proc(&phT_decGen_param, &phT_dec_Film);

		pOutput->u16_phTable_wrt_endIdx_p1 = phT_dec_Film.u16_phT_endIdx_p1;

		// in wrt Table //LISA_161009
		if(pOutput->u1_inTable_wrt_en == 1 || pOutput->u1_generate_video_en == 1 || pOutput->u1_generate_film_en == 1)
		{
			FRC_phTable_WrtStep_VideoMode_Gen(frc_cadTable[pOutput->u8_cadence_id_pre]);
		}

	}

//		if(pParam->u1_filmPh_pf_en == 1)
//		{
//			LogPrintf(DBG_MSG,"PC_gen = %d, vd_22_32_gen = %d, ", pOutput->u1_generate_PC_en, pOutput->u1_generate_vd_22_32_en);
//			LogPrintf(DBG_MSG,"film_gen = %d, film_flbk = %d, ", pOutput->u1_generate_film_en, pOutput->u1_phFlbk_film_en);
//			LogPrintf(DBG_MSG,"in_wrt = %d, out_wrt = %d, film_wrt = %d, \r\n", pOutput->u1_inTable_wrt_en, pOutput->u1_outTable_wrt_en, pOutput->u1_filmPh_wrt_en);
//			LogPrintf(DBG_MSG,"vid2232_st = %d, vid2232_end = %d,wt_end = %d,", pOutput->u16_phTable_wrt_stIdx,pOutput->u16_phTable_wrt_vd_22_32_endIdx,pOutput->u16_phTable_wrt_endIdx_p1);
//		}

}
VOID FRC_phTable_Write(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput)
{
	UBYTE u8_filmPhase = 0;

	if(pOutput->u8_cadence_id_pre >= _FRC_CADENCE_NUM_){

		LogPrintf(DBG_WARNING,"[%s]Invalid u8_cadence_id_pre:%d!\n",__FUNCTION__,pOutput->u8_cadence_id_pre);
		pOutput->u8_cadence_id_pre = _CAD_VIDEO;
	}
	if(frc_cadTable[pOutput->u8_cadence_id_pre].cad_outLen == 0){
		LogPrintf(DBG_WARNING,"[%s]Invalid cad_outLen=%d.Resume!\n",__FUNCTION__,frc_cadTable[pOutput->u8_cadence_id_pre].cad_outLen);
		frc_cadTable[pOutput->u8_cadence_id_pre].cad_outLen = 1;
	}
	u8_filmPhase = (pOutput->u1_outMode_pre == _PQL_OUT_PC_MODE)? 0 : (pOutput->u8_filmPh + 1)% frc_cadTable[pOutput->u8_cadence_id_pre].cad_outLen;
	WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_phase), u8_filmPhase);

	// after image and write Kphase
	if(0)
	{
		UBYTE u8_filmPhase_det = (pOutput->u1_outMode_pre == _PQL_OUT_PC_MODE)? 0 : (pOutput->u8_filmPh + 1)% frc_cadTable[pOutput->u8_cadence_id_pre].cad_outLen;
		UBYTE after_img;

		if(pOutput->u1_after_img == 1)
		{
			UINT32 u8_filmPhase_pre;
			UINT32 u8_outPhase;
			UBYTE u8_cadence_id_pre = pOutput->u8_after_img_cadence_id_pre;
			UBYTE u8_cadence_id_dtc = pOutput->u8_cadence_id_pre;

			UINT32 filmPhase_result;

			ReadRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_phase), &u8_filmPhase_pre);
			ReadRegister(KIWI_REG(FRC_TOP__kphase__regr_kphase_out_phase), &u8_outPhase);

			//LogPrintf(DBG_MSG,"bai print . u8_cadence_id_pre = %d, u8_cadence_id_dtc = %d, u8_filmPhase_pre = %d, u8_filmPhase_det = %d, u8_outPhase_pre =%d \r\n", u8_cadence_id_pre, u8_cadence_id_dtc, u8_filmPhase_pre, u8_filmPhase_det, u8_outPhase);

			after_img= after_image_proc(u8_filmPhase_pre, u8_filmPhase_det, u8_outPhase, u8_cadence_id_pre, u8_cadence_id_dtc, pParam->in_3dFormat, pOutput->u8_sys_M_pre,pOutput->u16_phTable_wrt_endIdx_p1);

			//LogPrintf(DBG_MSG,"print bai. after_img = %d \r\n", after_img);

			if(after_img == 1)
			{
				filmPhase_result = u8_filmPhase_det;
				pOutput->u1_after_img = 0;

				FRC_phTable_Kphase_ctrl_Wrt(pParam);

				WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_phase), u8_filmPhase_det);
			}
			else
			{
				filmPhase_result = (u8_filmPhase_pre+ 1)% frc_cadTable[u8_cadence_id_pre].cad_outLen;
				WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_phase), filmPhase_result);
			}
			if(0)
			{
				UINT32 u8_filmPhase;
				UINT32 u8_outPhase;
				UINT32 cad_outLen;
				UINT32 u32_wrt_film_mode;

				ReadRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_mode),  &u32_wrt_film_mode);
				ReadRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_phase_type), &cad_outLen);
				ReadRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_phase), &u8_filmPhase);
				ReadRegister(KIWI_REG(FRC_TOP__kphase__regr_kphase_out_phase), &u8_outPhase);

				LogPrintf(DBG_MSG,"bai print result read back. film_mode = %d, cad_outLen = %d, filmPhase = %d, outPhase = %d \r\n", u32_wrt_film_mode, cad_outLen, u8_filmPhase, u8_outPhase);
			}
		}
		else
		{
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_phase), u8_filmPhase_det);
			if (pOutput->u1_filmPh_wrt_en == 1)
			{
				FRC_phTable_Kphase_ctrl_Wrt(pParam);
			}
		}

	}

	if (pOutput->u1_inTable_wrt_en == 1 && pOutput->u8_cadence_id_pre != _CAD_VIDEO && pOutput->u8_film_cadence_id_pre != _CAD_22 && pOutput->u8_film_cadence_id_pre != _CAD_32)
	{
		FRC_phTable_inDec_Wrt();
	}

	if (pOutput->u1_outTable_wrt_en == 1)
	{
		FRC_phTable_outDec_Wrt(pParam, pOutput);
	}

	if (pOutput->u1_filmPh_wrt_en == 1)
	{
		FRC_phTable_Kphase_ctrl_Wrt(pParam);
	}
}

VOID   FRC_phTable_inDec_Wrt()
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE u8_cadence_id           = s_pContext->_output_frc_phtable.u8_cadence_id_pre;
	UBYTE u8_k = 0;
	UBYTE Len_vid_22_32;
	UBYTE Len_vid_22_32_cadence;
	UBYTE me2_wrt_reg_stId = 0;

	if(u8_cadence_id >= _FRC_CADENCE_NUM_){
		LogPrintf(DBG_WARNING,"[%s]Invalid u8_cadence_id:%d.Resume!\n",__FUNCTION__,u8_cadence_id);
		u8_cadence_id = _CAD_VIDEO;
	}
	FRC_phTable_inDec_amend(u8_cadence_id);

	Len_vid_22_32 = frc_cadTable[_CAD_VIDEO].cad_outLen + frc_cadTable[_CAD_22].cad_outLen + frc_cadTable[_CAD_32].cad_outLen;
	Len_vid_22_32_cadence = Len_vid_22_32 + frc_cadTable[u8_cadence_id].cad_outLen;
	me2_wrt_reg_stId = Len_vid_22_32/2 ;

	for (u8_k = Len_vid_22_32; u8_k < Len_vid_22_32_cadence; u8_k = u8_k + 4)
	{
		UBYTE pack_stIdx = u8_k - Len_vid_22_32;
		UINT32 u32_phT_wrtStep_pack = phTable_WrtStep_pack(pack_stIdx);
		WriteRegister(FRC_TOP__kphase__reg_kphase_in_p00_ADDR + u8_k, 0, 31, u32_phT_wrtStep_pack);
	}
	for (u8_k = 0; u8_k < frc_cadTable[u8_cadence_id].cad_outLen; u8_k = u8_k + 8)
	{
		UINT32 u32_phT_wrtStep_pack = phTable_me2_WrtStep_pack(u8_k);
		WriteRegister(FRC_TOP__kphase__reg_kphase_in_me2_p00_ADDR + me2_wrt_reg_stId, 0, 31, u32_phT_wrtStep_pack);
		me2_wrt_reg_stId = me2_wrt_reg_stId + 4;
	}
}
VOID   FRC_phTable_outDec_Wrt(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput)
{

	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UINT16 phT_stIdx;
	UINT16 phT_endIdx_p1          = s_pContext->_output_frc_phtable.u16_phTable_wrt_endIdx_p1;
	UINT16 clear_st;

	UINT16 u16_k;
	Ph_Dec_Pack_Info packInfo;
	UINT32 ee_addr_base = 0x00000000;//0xC0000000

	clear_st      = 0;
	phT_stIdx     = s_pContext->_output_frc_phtable.u16_phTable_wrt_stIdx;

	FRC_kphase_sram_clear(clear_st, 255);

	WriteRegister(ee_addr_base + 0x4F00, 0, 31, 0);     //Prepare write EEPROM
	WriteRegister(ee_addr_base + 0x4F00, 0, 31, 0x80000000 | phT_stIdx);
	//LogPrintf(DBG_MSG, "%s::phT_stIdx=%d,phT_endIdx_pl=%d \n",__FUNCTION__,phT_stIdx,phT_endIdx_p1);
	for (u16_k = phT_stIdx; u16_k < phT_endIdx_p1; u16_k ++)
	{
		UINT32 pack_MSB = 0, pack_LSB = 0;

		FRC_phTable_allInfo_Pack_Gen(pParam, pOutput, u16_k, &packInfo);
		phaseTable_pack(&packInfo, &pack_LSB, &pack_MSB);

		WriteRegister(ee_addr_base + 0x4F04, 0, 31, pack_LSB);
		WriteRegister(ee_addr_base + 0x4F08, 0, 31, pack_MSB);
	}

	//Protect for outPhase over
	UINT16 phT_endIdx_p1_new = _CLIP_(phT_endIdx_p1+(phT_endIdx_p1-phT_stIdx), 0, 255);
	for (u16_k = phT_endIdx_p1; u16_k < phT_endIdx_p1_new; u16_k ++)
	{
		UINT32 pack_MSB = 0, pack_LSB = 0;

		UINT16 u16_k_phT_idx = u16_k-phT_endIdx_p1+phT_stIdx;
		FRC_phTable_allInfo_Pack_Gen(pParam, pOutput, u16_k_phT_idx, &packInfo);
		if(u16_k_phT_idx < pOutput->u16_phTable_wrt_vd_endIdx_p1)//VIDEO
		{
			packInfo.u8_msb[MSB_OUT_PHASE] = phTable_DecInfoGen[u16_k_phT_idx].out_phase
											+ phTable_DecInfoGen[pOutput->u16_phTable_wrt_vd_endIdx_p1-1].out_phase;
		}
		else
		{
			packInfo.u8_msb[MSB_OUT_PHASE] = phTable_DecInfoGen[u16_k_phT_idx].out_phase
											+ phTable_DecInfoGen[phT_endIdx_p1-1].out_phase;
		}
		phaseTable_pack(&packInfo, &pack_LSB, &pack_MSB);

		WriteRegister(ee_addr_base + 0x4F04, 0, 31, pack_LSB);
		WriteRegister(ee_addr_base + 0x4F08, 0, 31, pack_MSB);
	}

	// change lut selection.
	{
		UINT32 u32_Tmp;
		ReadRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_lut_sel), &u32_Tmp);
		u32_Tmp = ((u32_Tmp&0x01) == 1)? 0 : 1;
		WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_lut_sel), u32_Tmp);
	}

}
VOID   FRC_phTable_Kphase_ctrl_Wrt(const _PARAM_FRC_PH_TABLE *pParam)
{
	const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE  u1_outMode             = s_pContext->_output_frc_phtable.u1_outMode_pre;
	UBYTE  u8_cadence_id          = s_pContext->_output_frc_phtable.u8_cadence_id_pre;
	UINT32 u32_wrt_film_mode      = u8_cadence_id == _CAD_VIDEO? 0 : (u8_cadence_id == _CAD_22? 1 : (u8_cadence_id == _CAD_32? 2 : 3));

	if(u8_cadence_id >= _FRC_CADENCE_NUM_){
		LogPrintf(DBG_WARNING,"[%s]Invalid u8_cadence_id:%d.Resume!\n",__FUNCTION__,u8_cadence_id);
		u8_cadence_id = _CAD_VIDEO;
	}
	if (u1_outMode == _PQL_OUT_PC_MODE)
	{
		WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_en),             1);
		WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_phase),          0);
		WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_mode),              0);
		WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_phase_type),        1);
	}
	else
	{
		if(pParam->u1_filmPh_sw_en == 1)
		{
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_en),                 1);
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_mode),  u32_wrt_film_mode);
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_phase_type), frc_cadTable[u8_cadence_id].cad_outLen);
		}
		else
		{
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_sw_film_en),              0);
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_mode),               0);
			WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_film_phase_type), frc_cadTable[u8_cadence_id].cad_outLen);
		}
	}

}

///////////////////////    phase table  write into sram   //////////////////////////////////
VOID   FRC_phTable_allInfo_Pack_Gen(const _PARAM_FRC_PH_TABLE *pParam, _OUTPUT_FRC_PH_TABLE *pOutput, UINT16 phDecInfo_k, Ph_Dec_Pack_Info *pPackInfo)  // bai  need  change
{
	//const _PQLCONTEXT   *s_pContext = GetPQLContext();
	//PQL_INPUT_3D_FORMAT in_3dFormat = s_pContext->_output_frc_phtable.in3d_format_pre;

	UBYTE u1_out3D_en = (pOutput->out3d_format_pre == _PQL_OUT_SG || pOutput->out3d_format_pre == _PQL_OUT_SG_LLRR || pOutput->out3d_format_pre == _PQL_OUT_PR)? 1 : 0;
	UBYTE mc_hf_idx   = 0;
	UBYTE mc_lf_idx   = 0;

	UBYTE u1_is_firstPhase = 0;
	//UBYTE org_out_3d_lr = 0;

	if(phDecInfo_k >= sizeof(phTable_DecInfoGen) / sizeof(Ph_Dec_Info)){
		LogPrintf(DBG_WARNING,"[%s]Invalid phDecInfo_k=%d.Resume!\n",__FUNCTION__,phDecInfo_k);
		phDecInfo_k= 0;
	}
	mc_hf_idx   = _CLIP_(((phTable_DecInfoGen[phDecInfo_k].mc_phase* 4 + 64) >> 7), 1, 3) - 1;
	mc_lf_idx   = _CLIP_(((phTable_DecInfoGen[phDecInfo_k].mc_phase*10 + 64) >> 7), 3, 7) - 1;
	// firstPhase, lastPhase judge
	{
		UINT16 u16_phT_stIdx, u16_phT_endIdx, u16_phDecInfo_k_n1, u16_phDecInfo_k_p1;
		if (pOutput->u1_outMode_pre == _PQL_OUT_PC_MODE)
		{
			u16_phT_stIdx    = phT_dec_PC.u16_phT_stIdx;
			u16_phT_endIdx   = phT_dec_PC.u16_phT_endIdx_p1 - 1;
		}
		else if (phDecInfo_k < phT_dec_Film.u16_phT_stIdx)
		{
			u16_phT_stIdx    = phT_dec_Video.u16_phT_stIdx;
			u16_phT_endIdx   = phT_dec_Video.u16_phT_endIdx_p1 - 1;

		}
		else
		{
			u16_phT_stIdx    = phT_dec_Film.u16_phT_stIdx;
			u16_phT_endIdx   = phT_dec_Film.u16_phT_endIdx_p1 - 1;
		}
		u16_phDecInfo_k_n1   = (phDecInfo_k == u16_phT_stIdx)?  u16_phT_endIdx : phDecInfo_k - 1;
		u16_phDecInfo_k_p1   = (phDecInfo_k == u16_phT_endIdx)? u16_phT_stIdx  : phDecInfo_k + 1;
		
		if(u16_phDecInfo_k_n1 >= sizeof(phTable_DecInfoGen) / sizeof(Ph_Dec_Info)){
			LogPrintf(DBG_WARNING,"[%s]Invalid u16_phDecInfo_k_n1=%d.Resume!\n",__FUNCTION__,u16_phDecInfo_k_n1);
			u16_phDecInfo_k_n1 = 0;
		}
		u1_is_firstPhase     = (phDecInfo_k == u16_phDecInfo_k_n1)? 1 : ( (phTable_DecInfoGen[phDecInfo_k].me2_phase < phTable_DecInfoGen[u16_phDecInfo_k_n1].me2_phase)? 1 : 0 );
	}

	//// assign
	pPackInfo->u8_msb[MSB_OUT_3D_ENABLE]           = u1_out3D_en;
	pPackInfo->u8_msb[MSB_FILM_MODE]               = phTable_DecInfoGen[phDecInfo_k].film_mode;
	pPackInfo->u8_msb[MSB_OUT_PHASE]               = phTable_DecInfoGen[phDecInfo_k].out_phase;
	pPackInfo->u8_msb[MSB_FILM_PHASE]              = phTable_DecInfoGen[phDecInfo_k].film_phase;
	pPackInfo->u8_msb[MSB_ME2_PPFV_BUF_IDX]        = phTable_DecInfoGen[phDecInfo_k].ppfv_offset;
	pPackInfo->u8_msb[MSB_ME2_IBME_P_INDEX_OFFSET] = phTable_DecInfoGen[phDecInfo_k].me2_p_offset;
	pPackInfo->u8_msb[MSB_ME2_IBME_I_INDEX_OFFSET] = phTable_DecInfoGen[phDecInfo_k].me2_i_offset;
	pPackInfo->u8_msb[MSB_ME2_PHASE]               = phTable_DecInfoGen[phDecInfo_k].me2_phase;
	pPackInfo->u8_msb[MSB_ME2_FIRST_PHASE]         = u1_is_firstPhase;
	pPackInfo->u8_msb[MSB_CRTC_MC_HF_INDEX]        = mc_hf_idx;

	pPackInfo->u8_lsb[LSB_CRTC_MC_LF_INDEX]        = mc_lf_idx;
	pPackInfo->u8_lsb[LSB_ME_LAST_PHASE]           = phTable_DecInfoGen[phDecInfo_k].me1_last;
	pPackInfo->u8_lsb[LSB_ME_DTS_P_INDEX]          = phTable_DecInfoGen[phDecInfo_k].me1_p_offset;
	pPackInfo->u8_lsb[LSB_ME_DTS_I_INDEX]          = phTable_DecInfoGen[phDecInfo_k].me1_i_offset;
	pPackInfo->u8_lsb[LSB_MC_MODE_HF_UPDATE]       = 1;
	pPackInfo->u8_lsb[LSB_MC_MODE_LF_UPDATE]       = 1;
	pPackInfo->u8_lsb[LSB_MC_CTS_P_INDEX]          = phTable_DecInfoGen[phDecInfo_k].me2_p_offset;
	pPackInfo->u8_lsb[LSB_MC_CTS_I_INDEX]          = phTable_DecInfoGen[phDecInfo_k].me2_i_offset;
	pPackInfo->u8_lsb[LSB_MC_PHASE]                = phTable_DecInfoGen[phDecInfo_k].mc_phase;
	pPackInfo->u8_lsb[LSB_MC_HF_INDEX]             = mc_hf_idx;
	pPackInfo->u8_lsb[LSB_MC_LF_INDEX]             = mc_lf_idx;
}

VOID   FRC_phTable_inDec_amend(UBYTE  cadence_id)
{
	UBYTE Len_end;
	Film_Wrt_Info     phTable_WrtInfo_param;
	UBYTE u8_k;

	if(cadence_id >= _FRC_CADENCE_NUM_){
		LogPrintf(DBG_WARNING,"[%s]Invalid u8_cadence_id:%d.Resume!\n",__FUNCTION__,cadence_id);
		cadence_id = _CAD_VIDEO;
	}

	for (u8_k = 0; u8_k < 64; u8_k ++)
	{
		phTable_WrtInfoGen_Amend[u8_k].me1_in_idx     = phTable_WrtInfoGen[u8_k].me1_in_idx ;
		phTable_WrtInfoGen_Amend[u8_k].me2_in_idx     = phTable_WrtInfoGen[u8_k].me2_in_idx ;
		phTable_WrtInfoGen_Amend[u8_k].mc_in_idx      = phTable_WrtInfoGen[u8_k].mc_in_idx ;
		phTable_WrtInfoGen_Amend[u8_k].logo_en        = phTable_WrtInfoGen[u8_k].logo_en ;
		phTable_WrtInfoGen_Amend[u8_k].mc_finalPhase  = phTable_WrtInfoGen[u8_k].mc_finalPhase ;
	}
	Len_end = frc_cadTable[cadence_id].cad_outLen - 1;

	phTable_WrtInfo_param.me1_in_idx = phTable_WrtInfoGen_Amend[0].me1_in_idx ;
	phTable_WrtInfo_param.me2_in_idx = phTable_WrtInfoGen_Amend[0].me2_in_idx ;
	phTable_WrtInfo_param.mc_in_idx  = phTable_WrtInfoGen_Amend[0].mc_in_idx ;
	phTable_WrtInfo_param.logo_en    = phTable_WrtInfoGen_Amend[0].logo_en ;
	phTable_WrtInfo_param.mc_finalPhase  = phTable_WrtInfoGen_Amend[0].mc_finalPhase ;

	for(u8_k = 0; u8_k < Len_end; u8_k++)
	{
		phTable_WrtInfoGen_Amend[u8_k].me1_in_idx = phTable_WrtInfoGen_Amend[u8_k+1].me1_in_idx ;
		phTable_WrtInfoGen_Amend[u8_k].me2_in_idx = phTable_WrtInfoGen_Amend[u8_k+1].me2_in_idx ;
		phTable_WrtInfoGen_Amend[u8_k].mc_in_idx  = phTable_WrtInfoGen_Amend[u8_k+1].mc_in_idx ;
		phTable_WrtInfoGen_Amend[u8_k].logo_en    = phTable_WrtInfoGen_Amend[u8_k+1].logo_en ;
	    phTable_WrtInfoGen_Amend[u8_k].mc_finalPhase  = phTable_WrtInfoGen_Amend[u8_k+1].mc_finalPhase ;
	}

	phTable_WrtInfoGen_Amend[Len_end].me1_in_idx = phTable_WrtInfo_param.me1_in_idx ;
	phTable_WrtInfoGen_Amend[Len_end].me2_in_idx = phTable_WrtInfo_param.me2_in_idx ;
	phTable_WrtInfoGen_Amend[Len_end].mc_in_idx  = phTable_WrtInfo_param.mc_in_idx ;
	phTable_WrtInfoGen_Amend[Len_end].logo_en    = phTable_WrtInfo_param.logo_en ;
	phTable_WrtInfoGen_Amend[Len_end].mc_finalPhase  = phTable_WrtInfo_param.mc_finalPhase ;
}

UINT32  FRC_phTable_tool_commonDivisor(UINT32 v0, UINT32 v1)
{
	// based on LiuWei <<The Nine Chapters on the Mathematical Art>>
	if(v0 == 0 || v1 == 0)
	{
		LogPrintf(DBG_MSG, "phTable:: illegal sys_N or cadence outLength, please check.");
		v0 = 1;
		v1 = 1;
	}

	while(v0 != v1)
	{
		if(v0 > v1)
		{
			v0 = v0 - v1;
		}
		else
		{
			v1 = v1 - v0;
		}
	}

	return v0;
}

//////////////////////////////////////////////////////////////////////////
VOID FRC_kphase_sram_clear(UINT16 stIdx, UINT16 endIdx)
{
	UINT16 u16_k;
	UINT32 ee_addr_base = 0x00000000;//0xC0000000

	WriteRegister(ee_addr_base + 0x4F00, 0, 31, 0);     //Prepare write EEPROM
	WriteRegister(ee_addr_base + 0x4F00, 0, 31, 0x80000000 | stIdx);
	for (u16_k = stIdx; u16_k <= endIdx; u16_k ++)
	{
		UINT32 pack_MSB = 0, pack_LSB = 0;

		WriteRegister(ee_addr_base + 0x4F04, 0, 31, pack_LSB);
		WriteRegister(ee_addr_base + 0x4F08, 0, 31, pack_MSB);
	}
}

VOID FRC_kphase_sram_init()
{
	FRC_kphase_sram_clear(0, 255);

	// change LUT selection.
	{
		UINT32 u32_Tmp;
		ReadRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_lut_sel), &u32_Tmp);
		u32_Tmp = ((u32_Tmp & 0x01) == 1)? 0 : 1;
		WriteRegister(KIWI_REG(FRC_TOP__kphase__reg_kphase_lut_sel), u32_Tmp);
	}
	FRC_kphase_sram_clear(0, 255);
}

VOID FRC_phTable_Init_1n2m_video_22_32_intable()
{
	FRC_phTable_WrtStep_VideoMode_Gen_idx(frc_cadTable[_CAD_VIDEO], 0);
	FRC_phTable_WrtStep_VideoMode_Gen_idx(frc_cadTable[_CAD_22], 1);
	FRC_phTable_WrtStep_VideoMode_Gen_idx(frc_cadTable[_CAD_32], 3);

	FRC_phTable_inDec_Wrt_init();
}

VOID   FRC_phTable_inDec_Wrt_init( )  // bai need change  need know 64 table
{
	//const _PQLCONTEXT *s_pContext = GetPQLContext();
	UBYTE u8_k = 0;
	UBYTE Len_vid_22_32;

	//Film_Wrt_Info phTable_Wrt_param;

	Len_vid_22_32 = frc_cadTable[_CAD_VIDEO].cad_outLen + frc_cadTable[_CAD_22].cad_outLen + frc_cadTable[_CAD_32].cad_outLen;
	for (u8_k = 0; u8_k < Len_vid_22_32; u8_k = u8_k + 4)
	{
		UINT32 u32_phT_wrtStep_pack = phTable_WrtStep_pack_vd_22_32(u8_k);
		WriteRegister(FRC_TOP__kphase__reg_kphase_in_p00_ADDR + u8_k, 0, 31, u32_phT_wrtStep_pack);
	}
	for (u8_k = 0; u8_k < Len_vid_22_32; u8_k = u8_k + 8)
	{
		UINT32 u32_phT_wrtStep_pack = phTable_me2_WrtStep_pack_vd_22_32(u8_k);
		WriteRegister(FRC_TOP__kphase__reg_kphase_in_me2_p00_ADDR + u8_k, 0, 31, u32_phT_wrtStep_pack);
	}

}



