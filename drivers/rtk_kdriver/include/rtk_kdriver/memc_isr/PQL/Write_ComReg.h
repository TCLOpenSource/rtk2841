#ifndef _WRITE_COM_REG_H_
#define _WRITE_COM_REG_H_

typedef struct
{
	UBYTE u1_mc_lbmcMode_en;

	UBYTE u1_7segShow_en;
	UBYTE u1_FBLevelWr_en;

	UBYTE u1_RimCtrl_wrt_en;
	UBYTE u1_dhClose_wrt_en;
	
	UBYTE u1_LGClr_wrt_en;
	UBYTE u1_LGSC_ctrl_wrt_en;

	UBYTE u1_dynME_acdcBld_wrt_en;
	UBYTE u1_bigFBlvl_dis_SCdet_en;

	UBYTE u1_LGBlkHstyClr_wrt_en;
	UBYTE u1_LGPixHstyClr_wrt_en;

	UBYTE u1_LGHstyClr_ClrLG_wrt_en;

	UBYTE u1_LGRg_dhclr_ctrl_wrt_en;
	UBYTE u1_LGRg_detect_adp_wrt_en;

	UBYTE u1_LGRg_rim_unbalance_wrt_en;

	UBYTE u1_LG_SC_PtClose_wrt_en;

	UBYTE   u8_logo_blksameth_l_bidx0_lg;
	UBYTE   u8_logo_blksameth_l_bidx0_com;

	UBYTE   u8_logo_blksameth_a_bidx0_lg;
	UBYTE   u8_logo_blksameth_a_bidx0_com;

	UBYTE   u8_logo_blksameth_a_bidx10_lg;
	UBYTE   u8_logo_blksameth_a_bidx10_com;

	UBYTE   u8_blksameth_a_bidx4;
	UBYTE   u8_blksameth_h_bidx4;

	UBYTE   u8_logo_blkhsty_pth_bidx10_lg;
	UBYTE   u8_logo_blkhsty_pth_bidx10_com;

	UBYTE   u8_logo_blkhsty_nth_bidx10_lg;
	UBYTE   u8_logo_blkhsty_nth_bidx10_com;

	UBYTE   u8_logo_mv_diff_diff_th_lg;
	UBYTE   u8_logo_mv_diff_sad_th_lg;
	UBYTE   u8_logo_tmv_sad_th_lg;
	UBYTE   u8_logo_tmv_num_th_lg;

	UBYTE   u1_LG_netflix_wrt_en;

	UBYTE   u1_LG_lg16s_patch_wrt_en;
	UBYTE   u8_show7seg_mode;

	UBYTE   u1_localfb_wrt_en;//fast motion
	
	//
	UBYTE  u1_scCtrl_wrt_en;
	UBYTE  u1_MECand_wrt_en;
	UBYTE  u1_MECandPnt_wrt_en;
	UBYTE  u1_GMV_wrt_en;
	UBYTE  u1_MEScan_wrt_en;
	UBYTE  u1_MEUpdStgh_wrt_en;
	UBYTE  u1_logoCtrl_wrt_en;
	UBYTE  u1_MEacdcBld_wrt_en;
	//

}_PARAM_WRT_COM_REG;

typedef struct
{
	UBYTE  u8_lf_lbmcMode_pre;
	UBYTE  u8_hf_lbmcMode_pre;

	UBYTE  u8_FB_lvl;
	UBYTE  u1_LG_mb_wrt_en;

}_OUTPUT_WRT_COM_REG;

VOID Wrt_ComReg_Init(_OUTPUT_WRT_COM_REG *pOutput);

VOID Wrt_ComReg_Proc_oneFifth_outInterrupt(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput);
VOID Wrt_ComReg_Proc_intputInterrupt(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput);
VOID Wrt_ComReg_Proc_outputInterrupt(const _PARAM_WRT_COM_REG *pParam, _OUTPUT_WRT_COM_REG *pOutput);

DEBUGMODULE_BEGIN(_PARAM_WRT_COM_REG, _OUTPUT_WRT_COM_REG)
	ADD_PARAM_DES(UBYTE, u1_mc_lbmcMode_en,            1,  "")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE, u1_7segShow_en,               0,  "")	
	ADD_PARAM_DES(UBYTE, u1_FBLevelWr_en,              1,  "")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE, u1_RimCtrl_wrt_en,            1, "")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE, u1_dhClose_wrt_en,            1, "")

	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE, u1_LGClr_wrt_en,              1, "")
	ADD_PARAM_DES(UBYTE, u1_LGSC_ctrl_wrt_en,          0, "")
	
	ADD_DUMMY_PARAM()
	ADD_PARAM_DES(UBYTE, u1_dynME_acdcBld_wrt_en,         0, "dynamic ME, fadeInout write acdc bld Enable")

	////////  output  //////////////////////////////////////////////////////////////////

//	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE, u8_lf_lbmcMode_pre)
	ADD_OUTPUT(UBYTE, u8_hf_lbmcMode_pre)

	DEBUGMODULE_END

#endif
