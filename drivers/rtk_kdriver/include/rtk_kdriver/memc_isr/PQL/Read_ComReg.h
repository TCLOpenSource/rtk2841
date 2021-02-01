#ifndef _READ_COMREG_H
#define _READ_COMREG_H

#define LOGO_RG_32  (32)


typedef struct
{
	UBYTE  u1_me_VbufSize_rb_en;
	UBYTE  u1_sc_status_rb_en;

	UBYTE  u1_me_aTC_rb_en;
	UBYTE  u1_me_aSC_rb_en;
	UBYTE  u1_me_aSAD_rb_en;
	UBYTE  u1_me_aDTL_rb_en;
	UBYTE  u1_me_aAPLi_rb_en;
	UBYTE  u1_me_aAPLp_rb_en;

	UBYTE  u1_me_ZMV_cnt_rb_en;
	UBYTE  u1_me_ZMV_dtl_cnt_rb_en;
	UBYTE  u1_me_ZMV_psad_rb_en;
	UBYTE  u1_me_ZGMV_cnt_rb_en;

	UBYTE  u1_me_Hpan_cnt_rb_en;
	UBYTE  u1_me_Vpan_cnt_rb_en;
	UBYTE  u1_me_pnMV_cnt_rb_en;	

	UBYTE  u1_me_GMV_1st_rb_en;
	UBYTE  u1_me_GMV_2nd_rb_en;

	UINT32  u32_me_rTC_rb_en;
	UINT32  u32_me_rSC_rb_en;
	UINT32  u32_me_rSAD_rb_en;
	UINT32  u32_me_rDTL_rb_en;
	UINT32  u32_me_rAPLi_rb_en;
	UINT32  u32_me_rAPLp_rb_en;

	UINT32  u32_me_rMV_1st_rb_en;
	UINT32  u32_me_rMV_2nd_rb_en;

	UBYTE  u1_ipme_aMot_rb_en;
	UBYTE  u1_ipme_5rMot_rb_en;
	UBYTE  u1_ipme_12rMot_rb_en;
	UBYTE  u1_ipme_filmMode_rb_en;

	UBYTE  u1_BBD_rb_en;

	UBYTE  u1_lg_blk_cnt_rb_en;

	UBYTE  u1_kphase_rb_en;

	UBYTE  u2_rb_tc_mode;
	UBYTE  u4_rb_tc1_coef;
	UBYTE  u4_rb_tc2_coef;
	UBYTE  u4_rb_tc3_coef;

	UBYTE  u1_dh_rb_en;

	UBYTE  u1_low_delay_test01;
	UBYTE  u1_low_delay_ctrl2;
	UBYTE  u1_low_delay_ctrl3;
	UBYTE  u1_Debug_OnlineMeasure;

	UBYTE  u1_mc_HVdtl_rb_en;
	UBYTE  u1_me_ZMV_cnt_en;

	UBYTE  u1_powerSaving_en;
}_PARAM_ReadComReg;


typedef struct 
{
	UBYTE  u8_me1_Vbuf_Hsize_rb;
	UBYTE  u8_me1_Vbuf_Vsize_rb;
	UBYTE  u1_sc_status_rb;			 //me1
	UBYTE  u1_sc_status_logo_rb;     //logo
	UBYTE  u1_sc_status_dh_rb;      //dh

	UINT32 u27_me_aTC_rb;
	UINT32 u27_me_aSC_rb;
	UINT32 u30_me_aSAD_rb;
	UINT32 u25_me_aDTL_rb;
	UINT32 u26_me_aAPLi_rb;
	UINT32 u26_me_aAPLp_rb;


	UINT32 u17_me_ZMV_cnt_rb;
	UINT32 u17_me_ZMV_dtl_cnt_rb;
	UINT32 u31_me_ZMV_psad_dc_rb;
	UINT32 u31_me_ZMV_psad_ac_rb;
	UINT32 u20_me_ZMV_DcGreatAc_cnt_rb;
	UINT32 u20_me_ZMV_AcGreatDc_cnt_rb;
	UBYTE  u6_me_ZGMV_cnt_rb;

	UINT32 u20_me_Hpan_cnt_rb;
	UINT32 u20_me_Vpan_cnt_rb;

	UINT32 u17_me_posCnt_0_rb;
	UINT32 u17_me_posCnt_1_rb;
	UINT32 u17_me_posCnt_2_rb;
	UINT32 u17_me_posCnt_3_rb;

	UINT32 u17_me_negCnt_0_rb;
	UINT32 u17_me_negCnt_1_rb;
	UINT32 u17_me_negCnt_2_rb;
	UINT32 u17_me_negCnt_3_rb;

	SINT16 s11_me_GMV_1st_vx_rb;
	SINT16 s10_me_GMV_1st_vy_rb;
	UBYTE  u6_me_GMV_1st_cnt_rb;
	UINT16 u12_me_GMV_1st_unconf_rb;

	SINT16 s11_me_GMV_2nd_vx_rb;
	SINT16 s10_me_GMV_2nd_vy_rb;
	UBYTE  u6_me_GMV_2nd_cnt_rb;
	UINT16 u12_me_GMV_2nd_unconf_rb;

	UINT16  u16_mc_Hdtl_cnt;
	UINT16  u16_mc_Vdtl_cnt;
	UINT16  u10_mc_VHdtl_rb[32];

	UINT32 u22_me_rTC_rb[32];
	UINT32 u22_me_rSC_rb[32];
	UINT32 u25_me_rSAD_rb[32];
	UINT32 u20_me_rDTL_rb[32];
	UINT32 u20_me_rAPLi_rb[32];
	UINT32 u20_me_rAPLp_rb[32];

	SINT16 s11_me_rMV_1st_vx_rb[32];
	SINT16 s10_me_rMV_1st_vy_rb[32];
	UINT16 u12_me_rMV_1st_cnt_rb[32];
	UINT16 u12_me_rMV_1st_unconf_rb[32];

	SINT16 s11_me_rMV_2nd_vx_rb[32];
	SINT16 s10_me_rMV_2nd_vy_rb[32];
	UINT16 u12_me_rMV_2nd_cnt_rb[32];
	UINT16 u12_me_rMV_2nd_unconf_rb[32];

	//
	UINT32 u27_ipme_aMot_rb;
	UBYTE  u3_ipme_filmMode_rb;
	UINT32 u27_ipme_5Mot_rb[5];
	UINT32 u27_ipme_12Mot_rb[12];

	//
	UINT16 u12_BBD_roughRim_rb[4];
	UBYTE  u1_BBD_roughValid_rb[4];
	UINT16 u12_BBD_fineRim_rb[4];
	UBYTE  u1_BBD_fineValid_rb[4];

	UINT32 u12_ME1_blk_size[2];
	UINT32 u12_ME1_pix_size[2];
	UINT32 u12_ME2_blk_size[2];
	UINT32 u12_ME2_pix_size[2];


	//Logo cnt
	UINT32 u10_blklogo_rgcnt[LOGO_RG_32];

	UINT32 u16_blklogo_dh_clrcnt[4];

	UINT32 u16_blklogo_dh_clrcnt_bot[3];
	UINT32 u16_blklogo_dh_clrcnt_top[3];
	//
	UBYTE  u1_kphase_inLR;
	UBYTE  u4_kphase_inPhase;
	UBYTE  u8_sys_N_rb;
	UBYTE  u8_sys_M_rb;

	UINT16 u13_dec_vtrig_dly;
	UINT16 u13_vtotal;

	//dh
	UINT32 u20_dh_pfvconf[32];

}_OUTPUT_ReadComReg;

VOID ReadComReg_Init( _OUTPUT_ReadComReg *pOutput);
VOID ReadComReg_Proc(const _PARAM_ReadComReg *pParam, _OUTPUT_ReadComReg *pOutput);

VOID ReadComReg_Proc_oneFifth_OutInterrupt(const _PARAM_ReadComReg *pParam, _OUTPUT_ReadComReg *pOutput);
VOID ReadComReg_Proc_inputInterrupt(const _PARAM_ReadComReg *pParam, _OUTPUT_ReadComReg *pOutput);
VOID ReadComReg_Proc_outputInterrupt(const _PARAM_ReadComReg *pParam, _OUTPUT_ReadComReg *pOutput);

DEBUGMODULE_BEGIN(_PARAM_ReadComReg,_OUTPUT_ReadComReg)

	ADD_PARAM(UBYTE,   u1_me_VbufSize_rb_en,     1)
	ADD_PARAM(UBYTE,   u1_sc_status_rb_en,       1)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,   u1_me_aTC_rb_en,          1)
	ADD_PARAM(UBYTE,   u1_me_aSC_rb_en,          0)
	ADD_PARAM(UBYTE,   u1_me_aSAD_rb_en,         1)
	ADD_PARAM(UBYTE,   u1_me_aDTL_rb_en,         0)
	ADD_PARAM(UBYTE,   u1_me_aAPLi_rb_en,        1)
	ADD_PARAM(UBYTE,   u1_me_aAPLp_rb_en,        1)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,   u1_me_ZMV_cnt_rb_en,      0)
	ADD_PARAM(UBYTE,   u1_me_ZMV_dtl_cnt_rb_en,  0)
	ADD_PARAM(UBYTE,   u1_me_ZMV_psad_rb_en,     1)
	ADD_PARAM(UBYTE,   u1_me_ZGMV_cnt_rb_en,     0)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,   u1_me_Hpan_cnt_rb_en,     0)
	ADD_PARAM(UBYTE,   u1_me_Vpan_cnt_rb_en,     0)
	ADD_PARAM(UBYTE,   u1_me_pnMV_cnt_rb_en,     1)
	
	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,   u1_me_GMV_1st_rb_en,      0)
	ADD_PARAM(UBYTE,   u1_me_GMV_2nd_rb_en,      0)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UINT32,  u32_me_rTC_rb_en,         0)
	ADD_PARAM(UINT32,  u32_me_rSC_rb_en,         0)
	ADD_PARAM(UINT32,  u32_me_rSAD_rb_en,        0)
	ADD_PARAM(UINT32,  u32_me_rDTL_rb_en,        0)
	ADD_PARAM(UINT32,  u32_me_rAPLi_rb_en,       0)
	ADD_PARAM(UINT32,  u32_me_rAPLp_rb_en,       0)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UINT32,  u32_me_rMV_1st_rb_en,     0)
	ADD_PARAM(UINT32,  u32_me_rMV_2nd_rb_en,     0)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,  u1_ipme_aMot_rb_en,        0)
	ADD_PARAM(UBYTE,  u1_ipme_5rMot_rb_en,       0)
	ADD_PARAM(UBYTE,  u1_ipme_12rMot_rb_en,      0)
	ADD_PARAM(UBYTE,  u1_ipme_filmMode_rb_en,    1)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,  u1_BBD_rb_en,              1)

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,  u1_lg_blk_cnt_rb_en,       1)	

	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,  u1_kphase_rb_en,           0)

	////////////  OUTPUT  //////////////////////////////////////////////////////////////
	ADD_OUTPUT(UBYTE,         u8_me1_Vbuf_Hsize_rb)
	ADD_OUTPUT(UBYTE,         u8_me1_Vbuf_Vsize_rb)
	ADD_OUTPUT(UBYTE,         u1_sc_status_rb)  
	ADD_OUTPUT(UBYTE,         u1_sc_status_logo_rb)
	ADD_OUTPUT(UBYTE,         u1_sc_status_dh_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UINT32,         u27_me_aTC_rb)
	ADD_OUTPUT(UINT32,         u27_me_aSC_rb)
	ADD_OUTPUT(UINT32,         u30_me_aSAD_rb)
	ADD_OUTPUT(UINT32,         u25_me_aDTL_rb)
	ADD_OUTPUT(UINT32,         u26_me_aAPLi_rb)
	ADD_OUTPUT(UINT32,         u26_me_aAPLp_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UINT32,        u17_me_ZMV_cnt_rb)
	ADD_OUTPUT(UINT32,        u17_me_ZMV_dtl_cnt_rb)
	ADD_OUTPUT(UINT32,        u31_me_ZMV_psad_dc_rb)
	ADD_OUTPUT(UINT32,        u31_me_ZMV_psad_ac_rb)
	ADD_OUTPUT(UINT32,        u20_me_ZMV_DcGreatAc_cnt_rb)
	ADD_OUTPUT(UINT32,        u20_me_ZMV_AcGreatDc_cnt_rb)
	ADD_OUTPUT(UBYTE,         u6_me_ZGMV_cnt_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UINT32,        u17_me_Hpan_cnt_rb)
	ADD_OUTPUT(UINT32,        u17_me_Vpan_cnt_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UINT32,        u17_me_posCnt_0_rb)
	ADD_OUTPUT(UINT32,        u17_me_posCnt_1_rb)
	ADD_OUTPUT(UINT32,        u17_me_posCnt_2_rb)
	ADD_OUTPUT(UINT32,        u17_me_posCnt_3_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UINT32,         u17_me_negCnt_0_rb)
	ADD_OUTPUT(UINT32,         u17_me_negCnt_1_rb)
	ADD_OUTPUT(UINT32,         u17_me_negCnt_2_rb)
	ADD_OUTPUT(UINT32,         u17_me_negCnt_3_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(SINT16,        s11_me_GMV_1st_vx_rb)
	ADD_OUTPUT(SINT16,        s10_me_GMV_1st_vy_rb)
	ADD_OUTPUT(UBYTE,         u6_me_GMV_1st_cnt_rb)
	ADD_OUTPUT(UINT16,        u12_me_GMV_1st_unconf_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(SINT16,        s11_me_GMV_2nd_vx_rb)
	ADD_OUTPUT(SINT16,        s10_me_GMV_2nd_vy_rb)
	ADD_OUTPUT(UBYTE,         u6_me_GMV_2nd_cnt_rb)
	ADD_OUTPUT(UINT16,        u12_me_GMV_2nd_unconf_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UINT32,         u27_ipme_aMot_rb)
	ADD_OUTPUT(UBYTE,          u3_ipme_filmMode_rb)

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT_ARRAY_DES(UINT32, u25_me_rSAD_rb, 32, "rgn sad")

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT_ARRAY_DES(UINT32, u10_blklogo_rgcnt, LOGO_RG_32, "blk logo cnt")

	ADD_DUMMY_OUTPUT()
	ADD_OUTPUT(UBYTE,          u1_kphase_inLR)
	ADD_OUTPUT(UBYTE,          u4_kphase_inPhase)

DEBUGMODULE_END

#endif

