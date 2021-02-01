#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/PQLContext.h"




/////////////////////////////////
VOID PQL_ContextProc_ReadParam(_PQLPARAMETER *pParam)
{
	UINT32 u32_RB_val;

	{
		//rim detect
		ReadRegister(FRC_TOP__PQL_0__pql_rim_ctrl_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.u1_RimCtrl_en      =  u32_RB_val        & 0x01;
		pParam->_param_rimctrl.u12_RimDiffTh      = (u32_RB_val >> 1)  & 0xFFF;
		pParam->_param_rimctrl.u8_RimBiggerTh     = (u32_RB_val >> 13) & 0x1F;
		pParam->_param_rimctrl.u8_RimSmallerTh    = (u32_RB_val >> 18) & 0x3F;
		pParam->_param_rimctrl.u8_RimIIRAlpha     = (u32_RB_val >> 24) & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_rim_mc_ptrim_shrink_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.u8_mc_ptRim_shrink   =  u32_RB_val        & 0xFF;
		pParam->_param_rimctrl.u8_me_pixRim_shrink  = (u32_RB_val >>  8) & 0xFF;
		pParam->_param_rimctrl.u8_LogoBlkRimHOffset = (u32_RB_val >> 16) & 0xFF;
		pParam->_param_rimctrl.u8_LogoBlkRimVOffset = (u32_RB_val >> 24) & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_rim_logopixrim_hoffset_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.u8_LogoPixRimHOffset  =  u32_RB_val       & 0xFF;
		pParam->_param_rimctrl.u8_LogoPixRimVOffset  = (u32_RB_val >> 8) & 0xFF;
		pParam->_param_rimctrl.u8_me1_pixRim_offset	 = (u32_RB_val >> 16)& 0xFF; 
		pParam->_param_rimctrl.u8_me1_blkRim_offset	 = (u32_RB_val >> 24)& 0xFF; 

		ReadRegister(FRC_TOP__PQL_0__pql_dh_dummy_64_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.u12_Logo_Rim_Top_thr         = u32_RB_val       & 0xFFFF;
		pParam->_param_rimctrl.u8_Logo_Rim_unbalace_holdfrm = (u32_RB_val >> 16)& 0xFFFF;
	}
	{
		// lbmc mode switch
		ReadRegister(FRC_TOP__PQL_0__pql_lbmc_switch_bypass_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_mc_lbmcswitch.u8_lbmcSwitch_bypass  =  u32_RB_val        & 0xFF;
		pParam->_param_mc_lbmcswitch.u8_lf_Ovlap_s2n_cntTh = (u32_RB_val >>  8) & 0xFF;
		pParam->_param_mc_lbmcswitch.u8_lf_Lmv_s2n_cntTh   = (u32_RB_val >> 16) & 0xFF;
		pParam->_param_mc_lbmcswitch.u8_lf_Ovlap_n2s_cntTh = (u32_RB_val >> 24) & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_lbmc_lf_Lmv_n2s_cntTh_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_mc_lbmcswitch.u8_lf_Lmv_n2s_cntTh   =  u32_RB_val        & 0xFF;
		pParam->_param_mc_lbmcswitch.u8_hf_Ovlap_s2n_cntTh = (u32_RB_val >>  8) & 0xFF;
		pParam->_param_mc_lbmcswitch.u8_hf_Lmv_s2n_cntTh   = (u32_RB_val >> 16) & 0xFF;
		pParam->_param_mc_lbmcswitch.u8_hf_Ovlap_n2s_cntTh = (u32_RB_val >> 24) & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_lbmc_hf_Lmv_n2s_cntTh_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_mc_lbmcswitch.u8_hf_Lmv_n2s_cntTh   =  u32_RB_val        & 0xFF;
		pParam->_param_Patch_Manage.u1_BluceMic_En = 		 (u32_RB_val >>  8) & 0x01;
	}

	{
		//dh control
		ReadRegister(FRC_TOP__PQL_0__pql_dh_close_bypass_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u2_dhClose_bypass   =    u32_RB_val           & 0x03;
		pParam->_param_dh_close.u1_dbg_print_en     =   (u32_RB_val >>  2)    & 0x01;
		pParam->_param_dh_close.u1_fblvl_en         =   (u32_RB_val >>  3)    & 0x01;  
		pParam->_param_dh_close.u1_meAllDtl_en      =   (u32_RB_val >>  4)    & 0x01; 
		pParam->_param_dh_close.u8_dhOff_holdFrm    =   (u32_RB_val >> 24)    & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_fblvl_holdfrm_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u8_fblvl_holdFrm   =  u32_RB_val       & 0xFF;
		pParam->_param_dh_close.u8_fbLvl_Th0       = (u32_RB_val >> 8) & 0xFF;
		pParam->_param_dh_close.u8_fbLvl_Th1       = (u32_RB_val >>16) & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_meAllDtl_th0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u25_meAllDtl_Th0  = u32_RB_val   & 0x1FFFFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_meAllDtl_th1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u25_meAllDtl_Th1  = u32_RB_val   & 0x1FFFFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_pfvconf_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u1_dh_pfvconf_en      =  u32_RB_val         & 0x01;
		pParam->_param_dh_close.u20_dh_pfvconf_thrL   = (u32_RB_val >>  1)  & 0xFFFFF;
		pParam->_param_dh_close.u6_dh_pfvconf_cnt_thr = (u32_RB_val >> 21)  & 0x3F;
		pParam->_param_dh_close.u5_dh_pfvconf_holdfrm = (u32_RB_val >> 27)  & 0x1F;

		//LBMC param read
		ReadRegister(FRC_TOP__PQL_0__pql_dh_lbmc_switch_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u1_lbmc_switch_en      = u32_RB_val & 1;
		pParam->_param_dh_close.u5_lbmc_switch_holdfrm = (u32_RB_val >>  1)  & 0xFF;
        pParam->_param_dh_close.u5_dh_fadeInOut_holdfrm  = (u32_RB_val >>  9)         & 0x1F;
		pParam->_param_dh_close.u1_dh_fadeInOut_en   = (u32_RB_val >>  14)  & 0x01;
		//sml rgnAction
		pParam->_param_dh_close.u1_dh_sml_rgnAction_en = (u32_RB_val >>  15)  & 0x01;
		pParam->_param_dh_close.u8_dh_sml_rgnAction_gmv_x_thr = (u32_RB_val >>  16)  & 0xFF;
		pParam->_param_dh_close.u8_dh_sml_rgnAction_gmv_y_thr = (u32_RB_val >>  24)  & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_sml_rgnActive_goodpfv_diff_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u19_dh_sml_rgnAction_good_pfvdiff_thr = u32_RB_val          & 0x7FFFF;
		pParam->_param_dh_close.u8_dh_sml_rgnAction_apl_thr = (u32_RB_val >>  19)           & 0xFF;
		pParam->_param_dh_close.u5_dh_sml_rgnAction_badrgn_cnt_thr = (u32_RB_val >>  27)    & 0x1F;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_sml_rgnActive_goodRgn_cnt_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u5_dh_sml_rgnAction_goodrgn_cnt_thr = u32_RB_val            & 0x1F;
		pParam->_param_dh_close.u10_dh_sml_rgnAction_goodrgnsad_thr = (u32_RB_val >>  5)    & 0x3FF;
		pParam->_param_dh_close.u5_dh_sml_rgnAction_holdfrm = (u32_RB_val >>  15)           & 0x1F;
		pParam->_param_dh_close.u12_dh_sml_rgnAction_gmv_cnt_thr = (u32_RB_val >>  20)      & 0xFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_sml_rgnActive_gmv_ucof_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u12_dh_sml_rgnAction_gmv_ucof_thr = u32_RB_val              & 0xFFF;
		pParam->_param_dh_close.u19_dh_sml_rgnAction_bad_pfvdiff_thr = (u32_RB_val >>  12)  & 0x7FFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_sml_rgnActive_badRgn_sad_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u10_dh_sml_rgnAction_badrgnsad_thr = u32_RB_val             & 0x3FF;
		pParam->_param_dh_close.u12_dh_sml_rgnAction_bad_gmv_cnt_thr = (u32_RB_val >>  10)  & 0xFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dh_sml_rgnAction_bad_gmv_ucof_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_dh_close.u12_dh_sml_rgnAction_bad_gmv_ucof_thr = u32_RB_val          & 0xFFF;
		pParam->_param_dh_close.u1_panning_en 					= (u32_RB_val >> 12) 		& 0x01;
		pParam->_param_dh_close.u5_panning_holdfrm 				= (u32_RB_val >> 13) 		& 0x1F;	
	    pParam->_param_frc_sceneAnalysis.u12_PanRMV_Cnt 	    = (u32_RB_val >> 18) 		& 0xFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_PanRMV_SmallMV_ADDR, 0, 31, &u32_RB_val); 
		pParam->_param_frc_sceneAnalysis.u10_PanRMV_SmallMV		= u32_RB_val		 		& 0x3FF;
		pParam->_param_frc_sceneAnalysis.u10_PanRMV_LargeMV		= (u32_RB_val >> 10) 		& 0x3FF;
		pParam->_param_frc_sceneAnalysis.u12_PanRMV_Unconf		= (u32_RB_val >> 20) 		& 0xFFF;
	}


	// me scene analysis
	{
		ReadRegister(FRC_TOP__PQL_0__pql_scAls_fdIO_acdc_cnt_thr_low_ADDR, 0, 31, &u32_RB_val);
	    pParam->_param_frc_sceneAnalysis.u20_fdIO_acdc_cnt_low        =  u32_RB_val        & 0xFFFFF; 
		
		ReadRegister(FRC_TOP__PQL_0__pql_scAls_fdIO_acdc_cnt_thr_hig_ADDR, 0, 31, &u32_RB_val);
	    pParam->_param_frc_sceneAnalysis.u20_fdIO_acdc_cnt_hig        =  u32_RB_val        & 0xFFFFF; 
		pParam->_param_frc_sceneAnalysis.u3_fdIO_apl_diff_frm_cnt     =  (u32_RB_val >> 20)  & 0x0F; 

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_fadeInOut_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u1_fadeInOut_en              =   u32_RB_val        & 0x01;   
		pParam->_param_frc_sceneAnalysis.u1_fdIO_acdc_cnt_en          =  (u32_RB_val >> 1)  & 0x01;  
		pParam->_param_frc_sceneAnalysis.u1_fdIO_acdc_ratio_en        =  (u32_RB_val >> 2)  & 0x01; 
		pParam->_param_frc_sceneAnalysis.u1_fdIO_bv_sad_en            =  (u32_RB_val >> 3)  & 0x01; 
		pParam->_param_frc_sceneAnalysis.u1_fdIO_apl_diff_en          =  (u32_RB_val >> 4)  & 0x01; 
		pParam->_param_frc_sceneAnalysis.u1_fdIO_conf_iir_en          =  (u32_RB_val >> 5)  & 0x01; 
		pParam->_param_frc_sceneAnalysis.u1_fdIO_sc_clear_en          =  (u32_RB_val >> 6)  & 0x01; 
		pParam->_param_frc_sceneAnalysis.u4_fadeInOut_dh_close_thr    =  (u32_RB_val >> 7)  & 0xF;
		pParam->_param_frc_sceneAnalysis.u10_fdIO_apl_diff_thr_low    =  (u32_RB_val >>12)  & 0x3FF; 
		pParam->_param_frc_sceneAnalysis.u10_fdIO_apl_diff_thr_hig    =  (u32_RB_val >>22)  & 0x3FF; 

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_fdIO_acdc_cnt_alpha_low_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u8_fdIO_acdc_cnt_alpha_low    =  u32_RB_val         & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u8_fdIO_acdc_cnt_alpha_hig    = (u32_RB_val >>  8)  & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u8_fdIO_acdc_sad_ratio_low    = (u32_RB_val >> 16)  & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u8_fdIO_acdc_sad_ratio_hig    = (u32_RB_val >> 24)  & 0xFF; 


		ReadRegister(FRC_TOP__PQL_0__pql_scAls_fdIO_acdc_dcsad_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u31_fdIO_acdc_dcsad_thr    =  u32_RB_val   & 0xFFFFFFFF; 

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_fdIO_bv_sad_low_ADDR, 0, 31, &u32_RB_val);
        pParam->_param_frc_sceneAnalysis.u16_fdIO_bv_sad_low    =   u32_RB_val         & 0xFFFF; 
		pParam->_param_frc_sceneAnalysis.u16_fdIO_bv_sad_hig    =  (u32_RB_val >> 16)  & 0xFFFF; 

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_fdIO_conf_iir_alpha_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u4_fdIO_conf_iir_alpha       =   u32_RB_val         & 0x0F; 
		pParam->_param_frc_sceneAnalysis.u4_acdc_bld_holdtime         =  (u32_RB_val >>  4)  & 0x0F; 
		pParam->_param_frc_sceneAnalysis.u8_dynME_acdc_bld_x_com[0]   =  (u32_RB_val >>  8)  & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u8_dynME_acdc_bld_x_com[1]   =  (u32_RB_val >> 16)  & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u8_dynME_acdc_bld_x_com[2]   =  (u32_RB_val >> 24)  & 0xFF; 

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_dynMe_acdc_bld_y_com1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u6_dynME_acdc_bld_y_com[0]   =   u32_RB_val         & 0xFF;
		pParam->_param_frc_sceneAnalysis.u6_dynME_acdc_bld_y_com[1]   =  (u32_RB_val >>  8)  & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u6_dynME_acdc_bld_y_com[2]   =  (u32_RB_val >> 16)  & 0xFF;          ;
		pParam->_param_frc_sceneAnalysis.u8_dynME_acdc_bld_x_fdIO[0]  =  (u32_RB_val >> 24)  & 0xFF;  

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_dynMe_acdc_bld_x_fdIO2_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u8_dynME_acdc_bld_x_fdIO[1]  =   u32_RB_val         & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u8_dynME_acdc_bld_x_fdIO[2]  =  (u32_RB_val >>  8)  & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u6_dynME_acdc_bld_y_fdIO[0]  =  (u32_RB_val >> 16)  & 0xFF; 
		pParam->_param_frc_sceneAnalysis.u6_dynME_acdc_bld_y_fdIO[1]  =  (u32_RB_val >> 24)  & 0xFF; 

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_dynMe_acdc_bld_y_fdIO3_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u6_dynME_acdc_bld_y_fdIO[2]  =   u32_RB_val         & 0xFF; 

		ReadRegister(FRC_TOP__PQL_0__pql_dynSR_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u1_dynSR_en              =    u32_RB_val           & 0x01;
		pParam->_param_frc_sceneAnalysis.u11_dynSR_rmv_x_thr0     =   (u32_RB_val >>   1)   & 0x7FF;
		pParam->_param_frc_sceneAnalysis.u10_dynSR_rmv_y_thr0     =   (u32_RB_val >>  12)   & 0x3FF;
		pParam->_param_frc_sceneAnalysis.u10_dynSR_rmv_y_thr1     =   (u32_RB_val >>  22)   & 0x3FF;

		ReadRegister(FRC_TOP__PQL_0__pql_dynSR_rmv_x_thr1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u11_dynSR_rmv_x_thr1     =    u32_RB_val           & 0x7FF;
		pParam->_param_frc_sceneAnalysis.u12_dynSR_rmv_cnt_thr0   =   (u32_RB_val >>  11)   & 0xFFF;
		pParam->_param_frc_sceneAnalysis.u9_dynSR_mvx_range0      =   (u32_RB_val >>  23)   & 0x1FF;

		ReadRegister(FRC_TOP__PQL_0__pql_dynSR_rmv_cnt_thr1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u12_dynSR_rmv_cnt_thr1     =    u32_RB_val           & 0xFFF;
		pParam->_param_frc_sceneAnalysis.u12_dynSR_rmv_unconf_thr0  =   (u32_RB_val >>  12)   & 0xFFF;
		pParam->_param_frc_sceneAnalysis.u8_dynSR_mvy_range0        =   (u32_RB_val >>  24)   & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dynSR_rmv_unconf_thr1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u12_dynSR_rmv_unconf_thr1     =    u32_RB_val           & 0xFFF;
		pParam->_param_frc_sceneAnalysis.u9_dynSR_mvx_range1           =   (u32_RB_val >>  12)   & 0x1FF;
		pParam->_param_frc_sceneAnalysis.u8_dynSR_mvy_range1           =   (u32_RB_val >>  21)   & 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dynSR_rmv_x_num_thr0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u6_dynSR_rmv_x_num_thr0     =    u32_RB_val           & 0x3F;
		pParam->_param_frc_sceneAnalysis.u6_dynSR_rmv_x_num_thr1     =   (u32_RB_val >>   6)   & 0x3F;
		pParam->_param_frc_sceneAnalysis.u6_dynSR_rmv_y_num_thr0     =   (u32_RB_val >>  12)   & 0x3F;
		pParam->_param_frc_sceneAnalysis.u6_dynSR_rmv_y_num_thr1     =   (u32_RB_val >>  18)   & 0x3F;
		pParam->_param_frc_sceneAnalysis.u1_dyn_SAD_Diff_en			 =	 (u32_RB_val >>  24)   & 0x01;		

		//ReadRegister(KIWI_REG(FRC_TOP__PQL_0__pql_dynSR_dummy_a0), &u32_RB_val);
		pParam->_param_wrt_comreg.u8_show7seg_mode 					 =   (u32_RB_val >>  25)   & 0x1F;
		pParam->_param_frc_sceneAnalysis.inUnconf_sel 				 =   (u32_RB_val >>  30)   & 0x01;

		ReadRegister(FRC_TOP__PQL_0__pql_dyn_SAD_Diff_TC_th_l_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u27_dyn_SAD_Diff_TC_th_l		=	u32_RB_val & 0x7FFFFFF;
		
		ReadRegister(FRC_TOP__PQL_0__pql_dyn_SAD_Diff_TC_th_h_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u27_dyn_SAD_Diff_TC_th_h		=	u32_RB_val & 0x7FFFFFF;
		
		ReadRegister(FRC_TOP__PQL_0__pql_dyn_SAD_Diff_sadAll_th_l_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u28_dyn_SAD_Diff_sadAll_th_l	=	u32_RB_val & 0xFFFFFFF;
		
		ReadRegister(FRC_TOP__PQL_0__pql_dyn_SAD_Diff_sadAll_th_h_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u28_dyn_SAD_Diff_sadAll_th_h	=	u32_RB_val & 0xFFFFFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_dyn_SAD_Diff_TC_gain_min_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u8_dyn_SAD_Diff_TC_gain_min	=	u32_RB_val & 0xFF;	
		pParam->_param_frc_sceneAnalysis.u8_dyn_SAD_Diff_TC_gain_max	=	(u32_RB_val >>  8) & 0xFF;	
		pParam->_param_frc_sceneAnalysis.u8_dyn_SAD_Diff_sadAll_gain_min=	(u32_RB_val >> 16) & 0xFF;		
		pParam->_param_frc_sceneAnalysis.u8_dyn_SAD_Diff_sadAll_gain_max=	(u32_RB_val >> 24) & 0xFF;	

		ReadRegister(FRC_TOP__PQL_0__pql_dynME_acdc_bld_alpha_x1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u4_dynME_acdc_bld_alpha_x1    = u32_RB_val				& 0x0F; 
		pParam->_param_frc_sceneAnalysis.u4_dynME_acdc_bld_alpha_x2    = (u32_RB_val >>  4)		& 0x0F; 
		pParam->_param_frc_sceneAnalysis.u8_dynME_ac_pix_sad_limt_com  = (u32_RB_val >>  8)		& 0xFF; 
		pParam->_param_frc_sceneAnalysis.u8_dynME_ac_pix_sad_limt_fdIO = (u32_RB_val >>  16)	& 0xFF; 
		
		ReadRegister(FRC_TOP__PQL_0__pql_dynME_ac_dc_bld_apl_holdfrm_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u6_dynME_ac_dc_bld_apl_holdfrm = u32_RB_val			& 0xFF; 
		pParam->_param_frc_sceneAnalysis.u4_acdc_bld_psad_shift_com 	= (u32_RB_val >> 8)		& 0x0F; 
		pParam->_param_frc_sceneAnalysis.u4_acdc_bld_psad_shift_fdIO 	= (u32_RB_val >> 12)	& 0x0F; 
		pParam->_param_frc_sceneAnalysis.u1_acdc_bld_sc_clear_en 		= (u32_RB_val >> 16)	& 0x01; 
		pParam->_param_frc_sceneAnalysis.u15_PanRMV_FitNumThr 			= (u32_RB_val >> 17)	& 0x7FFF;

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_avgRngTC_Thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u32_avgRngTC_Thr    = u32_RB_val;

		ReadRegister(FRC_TOP__PQL_0__pal_scAls_avgRngSC_Thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u32_avgRngSC_Thr    = u32_RB_val;

		ReadRegister(FRC_TOP__PQL_0__pql_rim_ME2_blkRimsht_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.u8_ME2_blkRimsht  = (u32_RB_val )	& 0xFF;
		pParam->_param_rimctrl.u8_ME2_ignRim  = (u32_RB_val >>8)	& 0xFF;
		pParam->_param_rimctrl.u8_ME2_RimMode  = (u32_RB_val >>  16) & 0xFF;	
		
		ReadRegister(FRC_TOP__PQL_0__pql_scAls_BdySmall_cnt_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u4_BdySmall_cnt_thr  = (u32_RB_val    ) & 0xFF;	 //8bit for quick tuning current
	    pParam->_param_frc_sceneAnalysis.u8_BdySmall_mvx_thr  = (u32_RB_val >>8) & 0xFF;		
	    pParam->_param_frc_sceneAnalysis.u8_BdySmall_mvy_thr  = (u32_RB_val >>16)& 0xFF;		

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_BdySmall_sad_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u15_BdySmall_sad_thr  = (u32_RB_val    ) & 0xFFFF;	 
		pParam->_param_rimctrl.dyn_pan_oor_cnt  = (u32_RB_val >>16) & 0x7;	
		pParam->_param_rimctrl.dyn_scbdy_oor_cnt  = (u32_RB_val >>19) & 0x7;	
		pParam->_param_rimctrl.dyn_smlbdy_oor_cnt  = (u32_RB_val >>22) & 0x7;	
		pParam->_param_rimctrl.dyn_general_oor_cnt  = (u32_RB_val >>25) & 0x7;	  //3bit
		pParam->_param_rimctrl.u1_dynRim_insidePan_en  = (u32_RB_val >>28) & 0x1;	
		pParam->_param_rimctrl.u1_dynRim_ScBdy_en  = (u32_RB_val >>29) & 0x1;
		pParam->_param_rimctrl.u1_dynRim_SmlBdy_en  = (u32_RB_val >>30) & 0x1;

		ReadRegister(FRC_TOP__PQL_0__pql_rim_dyn_pan_gmv_min_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.dyn_pan_gmv_min      = (u32_RB_val >> 0)  & 0x7F;  //7bit
		pParam->_param_rimctrl.dyn_pan_gmv_max      = (u32_RB_val >> 7)  & 0x7F;  //7bit
		pParam->_param_rimctrl.dyn_pan_me2prim_min  = (u32_RB_val >> 14) & 0xF;  //4bit
		pParam->_param_rimctrl.dyn_pan_me2prim_max  = (u32_RB_val >> 18) & 0x1F;   //5bit
		pParam->_param_rimctrl.dyn_pan_mcprim_min  = (u32_RB_val >> 23) & 0xF;  //4bit
		pParam->_param_rimctrl.dyn_pan_mcprim_max  = (u32_RB_val >> 27) & 0x1F;  //5bit

		ReadRegister(FRC_TOP__PQL_0__pql_patch_dummy_d8_ADDR, 0, 31, &u32_RB_val);	
		pParam->_param_frc_sceneAnalysis.u1_zoom_detect_en     	   =   u32_RB_val  & 0x1;
		pParam->_param_frc_sceneAnalysis.u1_mc2_var_lpf_wrt_en     	   =   (u32_RB_val >> 1)  & 0x1;
		pParam->_param_read_comreg.u1_low_delay_test01    = (u32_RB_val >> 2) & 0x1;
		pParam->_param_read_comreg.u1_low_delay_ctrl2     = (u32_RB_val >> 3) & 0x1;
		pParam->_param_read_comreg.u1_low_delay_ctrl3     = (u32_RB_val >> 4) & 0x1;
		pParam->_param_me_sceneAnalysis.u1_LightSword_en		= (u32_RB_val >> 5)  & 0x1;		
		pParam->_param_Patch_Manage.u1_patch_casino_en = (u32_RB_val >> 6)  & 0x1;  // Casino_WrtCtrl
		pParam->_param_me_sceneAnalysis.u1_BigAPLDiff_en     	=   (u32_RB_val >> 7)  & 0x1;
		pParam->_param_me_sceneAnalysis.u1_casino_RP_DetCtrl = (u32_RB_val >> 8)  & 0x1;  // Casino_DetCtrl
		pParam->_param_fblevelctrl.u1_FB_pan_apply_en     	=   (u32_RB_val >> 9)  & 0x1;
		pParam->_param_fblevelctrl.u1_FB_cross_apply_en     	=   (u32_RB_val >> 10)  & 0x1;
		pParam->_param_Patch_Manage.u1_patch_soccer_en = (u32_RB_val >> 11)  & 0x1;  // Soccer_WrtCtrl
		pParam->_param_frc_sceneAnalysis.u1_fastMotion_det_en		=	(u32_RB_val >> 12) & 0x1; // fastmotion det en
		pParam->_param_wrt_comreg.u1_localfb_wrt_en			=	(u32_RB_val >> 13) & 0x1; // localfb wrt en
		pParam->_param_wrt_comreg.u1_scCtrl_wrt_en = (u32_RB_val >> 14)  & 0x1;  // u1_scCtrl_wrt_en;
		pParam->_param_wrt_comreg.u1_MECand_wrt_en = (u32_RB_val >> 15)  & 0x1;  // u1_MECand_wrt_en;
		pParam->_param_wrt_comreg.u1_MECandPnt_wrt_en = (u32_RB_val >> 16)  & 0x1;  // u1_MECandPnt_wrt_en;
		pParam->_param_wrt_comreg.u1_GMV_wrt_en = (u32_RB_val >> 17)  & 0x1;  // u1_GMV_wrt_en;
		pParam->_param_wrt_comreg.u1_MEScan_wrt_en = (u32_RB_val >> 18)  & 0x1;  // u1_MEScan_wrt_en;
		pParam->_param_wrt_comreg.u1_MEUpdStgh_wrt_en = (u32_RB_val >> 19)  & 0x1;  // u1_MEUpdStgh_wrt_en;
		pParam->_param_wrt_comreg.u1_logoCtrl_wrt_en = (u32_RB_val >> 20)  & 0x1;  // u1_logoCtrl_wrt_en;
		pParam->_param_FRC_LGDet.u1_lg_UXN_patch_en = (u32_RB_val >> 21) & 0x1; // u1_lg_UXN_patch_en;
		pParam->_param_frc_phtable.u1_Ph_delay_calc_en    = (u32_RB_val >> 22) & 0x01;  // Ph_delay_calc_en
		pParam->_param_Patch_Manage.u1_patch_highFreq_en =  (u32_RB_val >>  23) & 0x01;  // u1_patch_highFreq_en
		pParam->_param_me_sceneAnalysis.u1_EPG_en     = (u32_RB_val >>  24) & 0x01; //u1_EPG_en
		pParam->_param_wrt_comreg.u1_MEacdcBld_wrt_en = (u32_RB_val >> 25)  & 0x1;  // u1_MEacdcBld_wrt_en;
		pParam->_param_dh_close.u1_simple_scene_en =  (u32_RB_val >>  26) & 0x01;  // u1_simple_scene_en
		pParam->_param_frc_sceneAnalysis.u1_special_scfb_en =  (u32_RB_val >>  27) & 0x01;  // u1_special_scfb_en

		ReadRegister(FRC_TOP__PQL_0__pql_rim_dyn_scbdy_me2prim_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.dyn_scbdy_me2prim      = (u32_RB_val >> 0)  & 0xF;  
		pParam->_param_rimctrl.dyn_scbdy_mcprim       = (u32_RB_val >> 4)  & 0xF;  
		pParam->_param_rimctrl.dyn_smlbdy_me2prim     = (u32_RB_val >> 8)  & 0xF;  
		pParam->_param_rimctrl.dyn_smlbdy_mcprim      = (u32_RB_val >> 12) & 0xF;	
		pParam->_param_frc_sceneAnalysis.u8_dyn_SADGain_thr	=	(u32_RB_val >> 16) & 0xFF;
		pParam->_param_rimctrl.dyn_sc_holdcnt    	        =	(u32_RB_val >> 24) & 0xFF;
	
		ReadRegister(FRC_TOP__PQL_0__pql_scAls_s2m_goodmv_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.s2m_goodmv_thr     = (u32_RB_val >> 0)   & 0xFF;  
		pParam->_param_frc_sceneAnalysis.s2m_goodmv_unconf  = (u32_RB_val >> 8)   & 0xFF;  
		pParam->_param_frc_sceneAnalysis.s2m_diffmv_thr     = (u32_RB_val >> 16)  & 0xFF;  
		pParam->_param_frc_sceneAnalysis.s2m_cnt_iir_alpha  = (u32_RB_val >> 24)  & 0x0F; 
		pParam->_param_fblevelctrl.u1_gmvratio_use          = (u32_RB_val >> 28)  & 0x01;  
		pParam->_param_frc_sceneAnalysis.s2m_method_sel     = (u32_RB_val >> 29)  & 0x01; 
		pParam->_param_rimctrl.u1_RimAbNoramlProcEn         = (u32_RB_val >> 30)  & 0x01; 
		pParam->_param_rimctrl.u1_RimAllBlackProcEn         = (u32_RB_val >> 31)  & 0x01; 

		ReadRegister(FRC_TOP__PQL_0__pql_rim_RimSmallerSCTh_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_rimctrl.u8_RimSmallerSCTh   = (u32_RB_val >> 0)   & 0xFF;  
		pParam->_param_rimctrl.u5_RimLRSmallShift  = (u32_RB_val >> 8)   & 0xFF; 
		pParam->_param_rimctrl.u8_RimAllBlackThr   = (u32_RB_val >> 16)  & 0xFF; 
		
		ReadRegister(FRC_TOP__PQL_0__pql_scAls_RgPan_Detect_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u1_RgPan_Detect_en 		= u32_RB_val 			& 0x01;
		pParam->_param_frc_sceneAnalysis.u5_RgPan_alp_th			= (u32_RB_val >> 1)		& 0xFF;

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_RgPan_rMV_th_l_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u16_RgPan_rMV_th_l               =  u32_RB_val			    & 0xFFFF;
		pParam->_param_frc_sceneAnalysis.u16_RgPan_rMV_th_h               =  (u32_RB_val>>16	)	& 0xFFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_RgPan_rSC_th_l_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u22_RgPan_rSC_th_l             =  u32_RB_val			    & 0xFFFFFFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_RgPan_rSC_th_h_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u22_RgPan_rSC_th_h             =  u32_RB_val			    & 0xFFFFFFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_RgPan_rTC_th_l_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u22_RgPan_rTC_th_l             =  u32_RB_val			    & 0x0FFFFFFF;

		ReadRegister(FRC_TOP__PQL_0__pql_scAls_RgPan_rTC_th_h_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u22_RgPan_rTC_th_h             =  u32_RB_val			    & 0x0FFFFFFF;	
	}

	{
		// film detect
		ReadRegister(FRC_TOP__PQL_1__pql_film_det_bypass_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_filmDetectctrl.u1_filmDet_bypass			=  u32_RB_val        & 0x01;
		pParam->_param_filmDetectctrl.u32_filmDet_cadence_en      = (u32_RB_val >>  1) & 0x7FFF;
		pParam->_param_filmDetectctrl.u1_FrcCadSupport_En		= (u32_RB_val >> 16) & 0x1;
		pParam->_param_filmDetectctrl.u3_DbgPrt_Rgn         = (u32_RB_val >> 17) & 0x7;		
		pParam->_param_read_comreg.u1_powerSaving_en 		= (u32_RB_val >> 26) & 0x1;
		pParam->_param_me_sceneAnalysis.u1_RepeatPattern_en	= (u32_RB_val >> 27) & 0x1;// patch manage
		pParam->_param_filmDetectctrl.u1_BadEditSlowOut_En		= (u32_RB_val >> 28) & 0x1;
		pParam->_param_filmDetectctrl.u1_QuickSwitch_En		= (u32_RB_val >> 29) & 0x1;		
		pParam->_param_filmDetectctrl.u1_StillDetect_En			= (u32_RB_val >> 30) & 0x1;
		pParam->_param_filmDetectctrl.u1_DbgPrt_FRChg_En		= (u32_RB_val >> 31) & 0x1;

		ReadRegister(FRC_TOP__PQL_1__pql_film_mot_rgn_diff_wgt_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_filmDetectctrl.u4_Mot_rgn_diffWgt   =    u32_RB_val            & 0x0F;
		pParam->_param_filmDetectctrl.u4_Mot_all_diffWgt   =   (u32_RB_val  >>  4)    & 0x0F;
		pParam->_param_filmDetectctrl.u27_Mot_all_min      =   (u32_RB_val  >>  8)    & 0xFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_film_enter_22_cnt_gain_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_filmDetectctrl.u4_enter_22_cntGain     =    u32_RB_val            & 0x0F;
		pParam->_param_filmDetectctrl.u4_enter_32_cntGain     =   (u32_RB_val  >>  4)    & 0x0F;
		pParam->_param_filmDetectctrl.u4_enter_else_cntGain   =   (u32_RB_val  >>  8)    & 0x0F;
		pParam->_param_filmDetectctrl.u4_quit_bigMot_wgt      =   (u32_RB_val  >> 12)    & 0x0F;
		pParam->_param_filmDetectctrl.u4_quit_smlMot_wgt      =   (u32_RB_val  >> 16)    & 0x0F;
		pParam->_param_filmDetectctrl.u1_quit_motWgt_auto_en  =   (u32_RB_val  >> 20)    & 0x01;
		pParam->_param_filmDetectctrl.u1_mixMode_det_en       =   (u32_RB_val  >> 26)    & 0x01;
		pParam->_param_filmDetectctrl.u1_mixMode_rgnEn[0]     =   (u32_RB_val  >> 27)    & 0x01;
		pParam->_param_filmDetectctrl.u1_mixMode_rgnEn[1]     =   (u32_RB_val  >> 28)    & 0x01;
		pParam->_param_filmDetectctrl.u1_mixMode_rgnEn[2]     =   (u32_RB_val  >> 29)    & 0x01;
		pParam->_param_filmDetectctrl.u1_mixMode_rgnEn[3]     =   (u32_RB_val  >> 30)    & 0x01;
		pParam->_param_filmDetectctrl.u1_mixMode_rgnEn[4]     =   (u32_RB_val  >> 31)    & 0x01;
		pParam->_param_filmDetectctrl.u5_dbg_param1           =   (u32_RB_val  >> 21)    & 0x1F;

		ReadRegister(FRC_TOP__PQL_1__pql_film_mix_mode_enter_cnt_th_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_filmDetectctrl.u8_mixMode_enter_cntTh     =     u32_RB_val           & 0xFF;
		pParam->_param_filmDetectctrl.u8_mixMode_cnt_max         =    (u32_RB_val  >>  8)   & 0xFF;
		pParam->_param_filmDetectctrl.u8_quit_cnt_th             =    (u32_RB_val  >> 16)   & 0xFF;
		pParam->_param_filmDetectctrl.u8_quit_prd_th             =    (u32_RB_val  >> 24)   & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_film_mix_mode_rgn_move_min_mot_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_filmDetectctrl.u27_mixMode_rgnMove_minMot     =     u32_RB_val          & 0xFFFFFFF;
		pParam->_param_filmDetectctrl.u4_mixMode_rgnMove_motWgt      =    (u32_RB_val >> 28)   & 0x0F;

		ReadRegister(FRC_TOP__PQL_1__pql_film_dbg_param2_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_filmDetectctrl.u32_dbg_param2      =     u32_RB_val          & 0xFFFFFFFF;
		ReadRegister(FRC_TOP__PQL_1__pql_film_dbg_cnt_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_filmDetectctrl.u32_dbg_cnt         =     u32_RB_val          & 0xFFFFFFFF; 
	}

	{
		//phase table
		ReadRegister(FRC_TOP__PQL_1__pql_phT_autoGen_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_phtable.u1_phT_autoGen_en          =       u32_RB_val          & 0x01;   
		pParam->_param_frc_phtable.u8_dejudder_lvl            =      (u32_RB_val >>  1)   & 0x1F; 
		pParam->_param_frc_phtable.u8_deblur_lvl              =      (u32_RB_val >>  6)   & 0x1F; 
		pParam->_param_frc_phtable.u2_candece_id_mode         =      (u32_RB_val >> 11)   & 0x03; 
		pParam->_param_frc_phtable.u4_cadence_id              =      (u32_RB_val >> 13)   & 0x0F; 
		pParam->_param_frc_phtable.in_3dFormat                =      (u32_RB_val >> 17)   & 0x07; 
		pParam->_param_frc_phtable.out_3dFormat               =      (u32_RB_val >> 20)   & 0x03; 
		pParam->_param_frc_phtable.u2_outMode                 =      (u32_RB_val >> 22)   & 0x03; 
		pParam->_param_frc_phtable.u1_outLR_LRsamePh          =      (u32_RB_val >> 24)   & 0x01; 
		pParam->_param_frc_phtable.u1_filmPh_sw_en            =      (u32_RB_val >> 25)   & 0x01;
		pParam->_param_frc_phtable.u1_filmPh_pf_en            =      (u32_RB_val >> 26)   & 0x01;

		
		ReadRegister(FRC_TOP__PQL_1__pql_phT_input_dly_ADDR, 0, 31,  &u32_RB_val);
		pParam->_param_frc_phtable.u8_input_dly               =       u32_RB_val   & 0xFF;
		pParam->_param_fblevelctrl.u12_fblvl_iir_up_good	  =       (u32_RB_val >> 8)   & 0xFFF; 		
	}

	{
		// fall back control
		ReadRegister(FRC_TOP__PQL_1__pql_fb_ctrl_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u1_FBLevelCtrl_en        =  u32_RB_val       & 0x01;
		pParam->_param_fblevelctrl.u1_BadRegionCtrl_en      = (u32_RB_val >> 1) & 0x01;
		pParam->_param_fblevelctrl.u1_FbLvl_gmvCtrl_en      = (u32_RB_val >> 2) & 0x01;
		pParam->_param_fblevelctrl.u1_FbLvl_occlCtrl_en     = (u32_RB_val >> 3) & 0x01;
		pParam->_param_fblevelctrl.u8_fblvl_map_y2_good     = (u32_RB_val >> 4) & 0xFF;
		pParam->_param_fblevelctrl.u8_good_rgn_num_th1     	= (u32_RB_val >> 12)& 0xFF;
		pParam->_param_fblevelctrl.u8_good_rgn_num_th2     	= (u32_RB_val >> 20)& 0xFF;	
		pParam->_param_fblevelctrl.u4_good_scene_hold_cnt	= (u32_RB_val >> 28)& 0x0F;	

		ReadRegister(FRC_TOP__PQL_1__pql_fb_tc_th_h_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u27_Fb_tc_th_h = u32_RB_val & 0x7FFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_tc_th_l_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u27_Fb_tc_th_l = u32_RB_val & 0x7FFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_tc_iir_up_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u8_FBTempConsisIIR_up       =  u32_RB_val        & 0xFF;
		pParam->_param_fblevelctrl.u8_FBTempConsis_IIR_down    = (u32_RB_val >>  8) & 0xFF;
	    pParam->_param_fblevelctrl.u8_FBTempConsis_limit_gain  = (u32_RB_val >> 16) & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_tc_limit_val_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u32_FBTempConsis_limit_val       =  u32_RB_val     & 0xFFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_iir_up_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u12_FBLevelIIRUp       =   u32_RB_val            & 0xFFF;
		pParam->_param_fblevelctrl.u12_FBLevelIIRDown     =  (u32_RB_val  >>  12)   & 0xFFF;
		pParam->_param_fblevelctrl.u8_SC_Gain             =  (u32_RB_val  >>  24)   & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_sc_slope_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u8_SC_slope            =  u32_RB_val        & 0xFF;
		pParam->_param_fblevelctrl.u8_SC_HoldCnt          = (u32_RB_val >>  8) & 0xFF;
		pParam->_param_fblevelctrl.u8_SC_NormCnt          = (u32_RB_val >> 16) & 0xFF;
		pParam->_param_fblevelctrl.u8_badRgn_sad_iirA_up  = (u32_RB_val >> 24) & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badrgn_sad_iirA_down_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u8_badRgn_sad_iirA_down   =  u32_RB_val        & 0xFF;
		pParam->_param_fblevelctrl.u8_badRgn_center_gain     = (u32_RB_val >>  8) & 0xFF;
		pParam->_param_fblevelctrl.u8_badRgn_center_oft      = (u32_RB_val >> 16) & 0xFF;
		pParam->_param_fblevelctrl.u8_BadRegionGainIIR       = (u32_RB_val >> 24) & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badrgn_sad_th_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u23_BadRegionSAD_th         =  u32_RB_val     & 0xFFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badrgn_sad_th_m_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u23_BadRegionSAD_th_m       =  u32_RB_val     & 0xFFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badrgn_sad_th_h_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u23_BadRegionSAD_th_h       =  u32_RB_val     & 0xFFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badregion_gain0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u5_BadRegionGain[0] =  u32_RB_val        & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[1] = (u32_RB_val >>  5) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[2] = (u32_RB_val >> 10) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[3] = (u32_RB_val >> 15) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[4] = (u32_RB_val >> 20) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[5] = (u32_RB_val >> 25) & 0x1F;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badregion_gain6_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u5_BadRegionGain[6]  =  u32_RB_val        & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[7]  = (u32_RB_val >>  5) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[8]  = (u32_RB_val >> 10) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[9]  = (u32_RB_val >> 15) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[10] = (u32_RB_val >> 20) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[11] = (u32_RB_val >> 25) & 0x1F;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badregion_gain12_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u5_BadRegionGain[12] =  u32_RB_val        & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[13] = (u32_RB_val >>  5) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[14] = (u32_RB_val >> 10) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[15] = (u32_RB_val >> 15) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[16] = (u32_RB_val >> 20) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[17] = (u32_RB_val >> 25) & 0x1F;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badregion_gain18_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u5_BadRegionGain[18] =  u32_RB_val        & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[19] = (u32_RB_val >>  5) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[20] = (u32_RB_val >> 10) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[21] = (u32_RB_val >> 15) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[22] = (u32_RB_val >> 20) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[23] = (u32_RB_val >> 25) & 0x1F;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badregion_gain24_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u5_BadRegionGain[24] =  u32_RB_val        & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[25] = (u32_RB_val >>  5) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[26] = (u32_RB_val >> 10) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[27] = (u32_RB_val >> 15) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[28] = (u32_RB_val >> 20) & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[29] = (u32_RB_val >> 25) & 0x1F;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_badregion_gain30_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u5_BadRegionGain[30] =  u32_RB_val        & 0x1F;
		pParam->_param_fblevelctrl.u5_BadRegionGain[31] = (u32_RB_val >>  5) & 0x1F;
		pParam->_param_fblevelctrl.u7_gmv_ratio_thH     = (u32_RB_val >> 10) & 0x7F;
		pParam->_param_fblevelctrl.u7_gmv_ratio_thL     = (u32_RB_val >> 17) & 0x7F;
	    pParam->_param_fblevelctrl.u6_gmv_gain_max      = (u32_RB_val >> 24) & 0x3F;

	    ReadRegister(FRC_TOP__PQL_1__pql_fb_gmv_gain_min_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u6_gmv_gain_min      =   u32_RB_val         & 0x3F;
		pParam->_param_fblevelctrl.u6_gmv_similar_cnt   =  (u32_RB_val >>  6)  & 0x3F;
		pParam->_param_fblevelctrl.u8_gmv_gain_iir      =  (u32_RB_val  >> 12) & 0xFF;
		pParam->_param_fblevelctrl.u12_gmv_rng_cnt_th	=  (u32_RB_val  >> 20) & 0xFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_map_y1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u8_FBLevelMapY1 =  u32_RB_val        & 0xFF;
		pParam->_param_fblevelctrl.u8_FBLevelMapY2 = (u32_RB_val >>  8) & 0xFF;
		pParam->_param_fblevelctrl.u8_FBLevelMapX1 = (u32_RB_val >> 16) & 0xFF;
		pParam->_param_fblevelctrl.u8_FBLevelMapX2 = (u32_RB_val >> 24) & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_dis_iir_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u1_FbLvl_disIIR_en             =  u32_RB_val        & 0x01;
		pParam->_param_fblevelctrl.u8_FbLvl_disIIR_holdCnt        = (u32_RB_val >>  1) & 0xFF;
		pParam->_param_fblevelctrl.u1_scAnalysis_en               = (u32_RB_val >>  9) & 0x01;
		pParam->_param_fblevelctrl.u4_scAnalysis_frmCnt_th        = (u32_RB_val >> 10) & 0x0F;
		pParam->_param_fblevelctrl.u4_scAnalysis_badFrmCnt_th     = (u32_RB_val >> 14) & 0x0F;
	    pParam->_param_fblevelctrl.u8_scAnalysis_st2mo_stPeriodTh = (u32_RB_val >> 18) & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_scAls_sad_all_th0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u28_scAnalysis_sadAll_th0  =  u32_RB_val & 0xFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_scAls_sad_all_th1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u28_scAnalysis_sadAll_th1  =  u32_RB_val & 0xFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_scAls_tc_th0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u27_scAnalysis_TC_th0  =  u32_RB_val & 0xFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_scAls_tc_th1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u27_scAnalysis_TC_th1  =  u32_RB_val & 0xFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_scAls_static_motion_th_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u27_scAnalysis_static_motionTh  =  u32_RB_val & 0xFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_minusDiff_penalth_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u16_minusDiff_penalty  =  u32_RB_val & 0xFFFF;
		pParam->_param_fblevelctrl.u8_sc_bypass_cnt       = (u32_RB_val >> 16) & 0xFF;
		pParam->_param_fblevelctrl.u8_static_cnt_th       = (u32_RB_val >> 24) & 0xFF;
		
		ReadRegister(FRC_TOP__PQL_1__pql_fb_static_mot_th_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u32_static_mot_th  =  u32_RB_val & 0xFFFFFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_dSCclr_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u1_FbLvl_disableSCclr_en       =  u32_RB_val        & 0x01;
		pParam->_param_fblevelctrl.u1_Fblvl_Dh_tcTh_mapEn         = (u32_RB_val >>  1) & 0x01;
		pParam->_param_fblevelctrl.u1_Fblvl_blur_ctrlEn           = (u32_RB_val >>  2) & 0x01;
		pParam->_param_fblevelctrl.u1_Fblvl_judder_ctrlEn         = (u32_RB_val >>  3) & 0x01;
		pParam->_param_fblevelctrl.u8_FbLvl_dSCclr_d2en_th        = (u32_RB_val >>  4) & 0xFF;
		pParam->_param_fblevelctrl.u8_FbLvl_dSCclr_en2d_th        = (u32_RB_val >> 12) & 0xFF;
		pParam->_param_fblevelctrl.u8_FbLvl_dSCclr_holdCnt        = (u32_RB_val >> 20) & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_dh_tc_thl_gain_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u8_FbLvl_Dh_tc_thLgain     =     u32_RB_val           & 0xFF;
		pParam->_param_fblevelctrl.u8_FbLvl_Dh_tc_thHgain     =    (u32_RB_val  >>  8)   & 0xFF;
		pParam->_param_fblevelctrl.u8_DehaloFBlvl_iir         =    (u32_RB_val  >> 16)   & 0xFF;
		pParam->_param_fblevelctrl.u8_FbLvl_blur_tc_thLgain   =    (u32_RB_val  >> 24)   & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_blur_tc_thh_gain_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u8_FbLvl_blur_tc_thHgain        =     u32_RB_val           & 0xFF;
		pParam->_param_fblevelctrl.u8_FbLvl_blur_iir               =    (u32_RB_val  >>  8)   & 0xFF;
		pParam->_param_fblevelctrl.u12_FbLvl_blur_gmvUnconf_th0    =    (u32_RB_val  >> 16)   & 0xFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_blur_gmvUnconf_th1_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u12_FbLvl_blur_gmvUnconf_th1    =      u32_RB_val         & 0xFFF;
		pParam->_param_fblevelctrl.u5_FbLvl_blur_badscene_dftLvl   =     (u32_RB_val  >> 12) & 0x1F;
		pParam->_param_fblevelctrl.u8_FbLvl_judder_tc_thLgain      =     (u32_RB_val  >> 17) & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_fb_lvl_judder_tc_thh_gain_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u8_FbLvl_judder_tc_thHgain      =      u32_RB_val         & 0xFF;
		pParam->_param_fblevelctrl.u8_FbLvl_judder_iir             =     (u32_RB_val >> 8)   & 0xFF;
		pParam->_param_fblevelctrl.u12_gmv_unconf_cnt_th		   =     (u32_RB_val >> 16)   & 0xFFF;
		
		ReadRegister(FRC_TOP__PQL_1__pql_fb_good_rng_sad_th_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_fblevelctrl.u20_good_rgn_sad_th			   =	  u32_RB_val		 & 0xFFFFF;
		pParam->_param_fblevelctrl.u12_good_rgn_gmv_unconf_th	   =	 (u32_RB_val >> 20)  & 0xFFF;
	}

	{
		ReadRegister(FRC_TOP__PQL_1__pql_rb_ctrl_dummy_b0_ADDR, 14, 31, &u32_RB_val);
		pParam->_param_wrt_comreg.u8_blksameth_a_bidx4 = (u32_RB_val & 0xff);
		pParam->_param_wrt_comreg.u8_blksameth_h_bidx4 = (u32_RB_val >> 8)& 0xff;
	}

	{
		// fast motion
		ReadRegister(FRC_TOP__PQL_1__pql_film_dummy_1c_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u8_hpan_th			= (u32_RB_val & 0xff);
		pParam->_param_frc_sceneAnalysis.u8_vpan_th			= (u32_RB_val >> 8) & 0xff;
		pParam->_param_frc_sceneAnalysis.u8_cnt2_th			= (u32_RB_val >> 16) & 0xff;
		pParam->_param_frc_sceneAnalysis.u6_localfallback_lvl	= (u32_RB_val >> 24) & 0x3f;
		pParam->_param_frc_sceneAnalysis.u1_fastMotion_gfb_en	= (u32_RB_val >> 30) & 0x1;
		pParam->_param_frc_sceneAnalysis.u1_fastMotion_lfb_en	= (u32_RB_val >> 31) & 0x1;
	
		ReadRegister(FRC_TOP__PQL_1__pql_rb_ctrl_dummy_b4_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_frc_sceneAnalysis.u25_glb_dtl_th 			= (u32_RB_val & 0xffff);
		pParam->_param_frc_sceneAnalysis.u8_fastMotion_glbfb_min 	= (u32_RB_val >> 24) & 0xff;
	}

	{
		// write register
		ReadRegister(FRC_TOP__PQL_1__pql_wr_mc_lbmc_mode_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_wrt_comreg.u1_mc_lbmcMode_en                =  u32_RB_val        & 0x01;
		pParam->_param_wrt_comreg.u1_FBLevelWr_en                  = (u32_RB_val >>  2) & 0x01;
		pParam->_param_wrt_comreg.u1_RimCtrl_wrt_en                = (u32_RB_val >>  3) & 0x01;
		pParam->_param_wrt_comreg.u1_dhClose_wrt_en                = (u32_RB_val >>  4) & 0x01;
		pParam->_param_wrt_comreg.u1_LGClr_wrt_en                  = (u32_RB_val >>  5) & 0x01;
		pParam->_param_wrt_comreg.u1_LGSC_ctrl_wrt_en              = (u32_RB_val >>  6) & 0x01;
		pParam->_param_wrt_comreg.u1_dynME_acdcBld_wrt_en          = (u32_RB_val >>  7) & 0x01;
		pParam->_param_wrt_comreg.u1_bigFBlvl_dis_SCdet_en         = (u32_RB_val >>  8) & 0x01;

		pParam->_param_wrt_comreg.u1_LGBlkHstyClr_wrt_en         = (u32_RB_val >>  9) & 0x01;
		pParam->_param_wrt_comreg.u1_LGPixHstyClr_wrt_en         = (u32_RB_val >>  10) & 0x01;
		pParam->_param_wrt_comreg.u1_LGHstyClr_ClrLG_wrt_en      = (u32_RB_val >>  11) & 0x01;
		pParam->_param_wrt_comreg.u1_LGRg_dhclr_ctrl_wrt_en      = (u32_RB_val >>  12) & 0x01;
		pParam->_param_wrt_comreg.u1_LGRg_detect_adp_wrt_en      = (u32_RB_val >>  13) & 0x01;
		pParam->_param_wrt_comreg.u1_LG_SC_PtClose_wrt_en        = (u32_RB_val >>  14) & 0x01;
		pParam->_param_wrt_comreg.u1_LG_netflix_wrt_en           = (u32_RB_val >>  15) & 0x01;  

		pParam->_param_wrt_comreg.u1_LG_lg16s_patch_wrt_en       = (u32_RB_val >>  17) & 0x01;

		pParam->_param_wrt_comreg.u1_LGRg_rim_unbalance_wrt_en   = (u32_RB_val >>  18) & 0x01;
	}

	{   // Logo dynamic params
		ReadRegister(FRC_TOP__PQL_1__pql_logo_pql_en_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u1_logo_pql_en                   =  u32_RB_val        & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_sw_clr_en                = (u32_RB_val >>  1) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_rg_clr_en                = (u32_RB_val >>  2) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_glb_clr_en               = (u32_RB_val >>  3) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_left_half_clr_en         = (u32_RB_val >>  4) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_right_half_clr_en        = (u32_RB_val >>  5) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_top_half_clr_en          = (u32_RB_val >>  6) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_bot_half_clr_en          = (u32_RB_val >>  7) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_sc_alpha_ctrl_en         = (u32_RB_val >>  8) & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_sc_logo_clr_en           = (u32_RB_val >>  9) & 0x01;
		pParam->_param_FRC_LGDet.u6_rgClr_holdtime                = (u32_RB_val >> 10) & 0x3F;
		pParam->_param_FRC_LGDet.u6_glbClr_holdtime               = (u32_RB_val >> 16) & 0x3F;
		pParam->_param_FRC_LGDet.u4_blk_pix_merge_type            = (u32_RB_val >> 22) & 0x0F;
		pParam->_param_FRC_LGDet.u5_iir_alpha                     = (u32_RB_val >> 26) & 0x1F;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_clr_rg_thr_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u8_clr_rg_thr   =  u32_RB_val           & 0xFF;
		pParam->_param_FRC_LGDet.u8_clr_glb_thr  = (u32_RB_val >>  8)    & 0xFF;
		pParam->_param_FRC_LGDet.u8_clr_half_thr = (u32_RB_val >> 16)    & 0xFF;
		pParam->_param_FRC_LGDet.u8_clr_rg_thr_l = (u32_RB_val >> 24)    & 0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_c4_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u16_RgDhClr_thr_l = u32_RB_val           & 0xFFFF;
		pParam->_param_FRC_LGDet.u16_RgDhClr_thr_h = (u32_RB_val >> 16)   & 0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_c8_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u1_RgDhClr_thr_en = u32_RB_val           & 0x01;
		pParam->_param_FRC_LGDet.u1_GlbHstyClr_en  = (u32_RB_val >> 1)    & 0x01;
		pParam->_param_FRC_LGDet.u1_RgHstyClr_en   = (u32_RB_val >> 2)    & 0x01;
		pParam->_param_FRC_LGDet.u1_RgHstyClr_Sc_en = (u32_RB_val >>3)    & 0x01;
		pParam->_param_FRC_LGDet.u1_RgHstyClr_glbclr_close_en = (u32_RB_val >>4)    & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_sc_detect_en  = (u32_RB_val >>5)    & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_static_bg_en  = (u32_RB_val >>6)    & 0x01;
		pParam->_param_FRC_LGDet.u1_param_reg_scdetct  = (u32_RB_val >>7)    & 0x01;
		pParam->_param_FRC_LGDet.u1_logo_sc_saddif_en  = (u32_RB_val >>8)    & 0x01; 
		pParam->_param_FRC_LGDet.u1_logo_sc_dtldif_en  = (u32_RB_val >>9)    & 0x01; 
		pParam->_param_FRC_LGDet.u1_logo_sc_Gmv_en     = (u32_RB_val >>10)    & 0x01; 
		pParam->_param_FRC_LGDet.u1_logo_netflix_detct_en = (u32_RB_val >>11)    & 0x01;
		pParam->_param_FRC_LGDet.u1_param_reg_netflix_detect = (u32_RB_val >>12)    & 0x01;

		pParam->_param_FRC_LGDet.u1_param_reg_lg16s_patch =  (u32_RB_val >>14)    & 0x01;


		pParam->_param_FRC_LGDet.u6_logo_static_bg_th_l  = (u32_RB_val >>20)    & 0x3F;
		pParam->_param_FRC_LGDet.u6_logo_static_bg_th_h  = (u32_RB_val >>26)    & 0x3F;

		if (pParam->_param_FRC_LGDet.u1_param_reg_lg16s_patch == 1)
		{
			// patch lg16s setting
			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_cc_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_en           = u32_RB_val        & 0x01;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gapl_en      = (u32_RB_val >>1)  & 0x01;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gdtl_en      = (u32_RB_val >>2)  & 0x01;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gsad_en      = (u32_RB_val >>3)  & 0x01;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gmv_en       = (u32_RB_val >>4)  & 0x01;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Rdtl_num_en  = (u32_RB_val >>5)  & 0x01;

			pParam->_param_FRC_LGDet.u8_logo_lg16s_patch_hold_frm     = (u32_RB_val >>24)    & 0xFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d0_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u10_logo_lg16s_patch_Gapl_th_l   =  u32_RB_val      & 0xFFFF;
			pParam->_param_FRC_LGDet.u10_logo_lg16s_patch_Gapl_th_h   =  (u32_RB_val>>16) & 0xFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d4_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u25_logo_lg16s_patch_Gdtl_th_l   =  u32_RB_val      & 0xFFFFFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d8_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u25_logo_lg16s_patch_Gdtl_th_h   =  u32_RB_val      & 0xFFFFFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_dc_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u28_logo_lg16s_patch_Gsad_th_l   =  u32_RB_val      & 0xFFFFFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_e0_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u28_logo_lg16s_patch_Gsad_th_h   =  u32_RB_val      & 0xFFFFFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_e4_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u11_logo_lg16s_patch_Gmvx_th_l   =  u32_RB_val      & 0xFFFF;
			pParam->_param_FRC_LGDet.u11_logo_lg16s_patch_Gmvx_th_h   =  (u32_RB_val>>16) & 0xFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_e8_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u11_logo_lg16s_patch_Gmvy_th     =  u32_RB_val      & 0xFFFF;
			pParam->_param_FRC_LGDet.u6_logo_sc_Gmv_cnt_th            =  (u32_RB_val>>16) & 0xFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_ec_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u12_logo_lg16s_patch_Gmv_unconf_th  = u32_RB_val      & 0xFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f0_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u20_logo_lg16s_patch_Rdtl_th_l      =   u32_RB_val      & 0xFFFFFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f4_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u20_logo_lg16s_patch_Rdtl_th_h      =   u32_RB_val      & 0xFFFFFFFF;

			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f8_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u6_logo_lg16s_patch_Rdtl_num_th     =    u32_RB_val      & 0xFFFF;


			// other setting const value

			// cc - d4
			pParam->_param_FRC_LGDet.u16_RgHstyClr_Gmv_thr  = 8;
			pParam->_param_FRC_LGDet.u16_RgHstyClr_mv_thr   =2;

			pParam->_param_FRC_LGDet.u10_RgHstyClr_Gsad_thr = 14;
			pParam->_param_FRC_LGDet.u10_RgHstyClr_Rsad_thr = 10;

			pParam->_param_FRC_LGDet.u12_RgHstyClr_Gmv_unconf_thr = 6;
			pParam->_param_FRC_LGDet.u12_RgHstyClr_mv_unconf_thr  = 6;
			// cc - d4
			pParam->_param_FRC_LGDet.u6_logo_sc_Gmv_cnt_th = 0;
			pParam->_param_FRC_LGDet.u12_logo_sc_Gmv_unconf_th = 0;
			pParam->_param_FRC_LGDet.u20_logo_sc_dtldif_th = 0xDF0;

			// d8
			pParam->_param_FRC_LGDet.u8_RgHstyClr_Gmv_cnt_thr     =  0x14;
			pParam->_param_FRC_LGDet.u12_RgHstyClr_mv_cnt_thr     =  0x3DD;

			// dc
			pParam->_param_FRC_LGDet.u31_logo_sc_saddiff_th       =  0x27000; 
			pParam->_param_FRC_LGDet.u1_RgDhClr_static_en         =  0;

			// e0
			pParam->_param_FRC_LGDet.u8_rg_dh_clr_lgclr_hold_frm		 = 8;

			// e4
			pParam->_param_FRC_LGDet.u8_rg_dh_clr_static_hold_frm         =  0;
			pParam->_param_FRC_LGDet.u8_logo_sc_hold_frm                  =  0xA;

			// e8
			pParam->_param_FRC_LGDet.u5_RgDhClr_cnt_th		   =  8;
			pParam->_param_FRC_LGDet.u8_logo_netflix_hold_frm  =  0xF;

			//ec
			pParam->_param_wrt_comreg.u8_logo_blksameth_l_bidx0_lg	   = 0x1A; 
			pParam->_param_wrt_comreg.u8_logo_blksameth_l_bidx0_com 	= 0x20; 

			//f0 - fc
			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lt_th_l  = 0x58;
			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lt_th_h  = 0x130;

			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rt_th_l  = 0;
			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rt_th_h  = 0x20;

			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lb_th_l  = 0x75;
			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lb_th_h  = 0xC0;

			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rb_th_l  = 0x90;
			pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rb_th_h  = 0xF0;

			//f0  -  fc
			pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx0_lg	    = 0x4A;
			pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx0_com 	= 0x64;

			pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx10_lg 	 = 0x50;
			pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx10_com	 = 0x64;

			pParam->_param_wrt_comreg.u8_logo_blkhsty_pth_bidx10_lg 	 = 6;
			pParam->_param_wrt_comreg.u8_logo_blkhsty_pth_bidx10_com	 = 7;

			pParam->_param_wrt_comreg.u8_logo_blkhsty_nth_bidx10_lg 	 = 6;
			pParam->_param_wrt_comreg.u8_logo_blkhsty_nth_bidx10_com	 = 7;

		} 
		else
		{
			// patch lg16s const setting
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_en           = 1;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gapl_en      = 1;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gdtl_en      = 1;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gsad_en      = 0;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Gmv_en       = 1;
			pParam->_param_FRC_LGDet.u1_logo_lg16s_patch_Rdtl_num_en  = 0;

			pParam->_param_FRC_LGDet.u8_logo_lg16s_patch_hold_frm     = 0x20;

			pParam->_param_FRC_LGDet.u10_logo_lg16s_patch_Gapl_th_l   =  0x64;
			pParam->_param_FRC_LGDet.u10_logo_lg16s_patch_Gapl_th_h   =  0xB5;

			pParam->_param_FRC_LGDet.u25_logo_lg16s_patch_Gdtl_th_l   =  0x9EB10;

			pParam->_param_FRC_LGDet.u25_logo_lg16s_patch_Gdtl_th_h   =  0x13D620;

			pParam->_param_FRC_LGDet.u28_logo_lg16s_patch_Gsad_th_l   =  0x30D40;

			pParam->_param_FRC_LGDet.u28_logo_lg16s_patch_Gsad_th_h   =  0x61A80;

			pParam->_param_FRC_LGDet.u11_logo_lg16s_patch_Gmvx_th_l   =  0x40;
			pParam->_param_FRC_LGDet.u11_logo_lg16s_patch_Gmvx_th_h   =  0x12C;

			pParam->_param_FRC_LGDet.u11_logo_lg16s_patch_Gmvy_th     =  0xA;
			pParam->_param_FRC_LGDet.u6_logo_sc_Gmv_cnt_th            =  0x1D;

			pParam->_param_FRC_LGDet.u12_logo_lg16s_patch_Gmv_unconf_th  = 0x10;

			pParam->_param_FRC_LGDet.u20_logo_lg16s_patch_Rdtl_th_l      =   0;

			pParam->_param_FRC_LGDet.u20_logo_lg16s_patch_Rdtl_th_h      =   0;

			pParam->_param_FRC_LGDet.u6_logo_lg16s_patch_Rdtl_num_th     =    0;

			if (pParam->_param_FRC_LGDet.u1_param_reg_scdetct == 0)
			{
		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_cc_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u16_RgHstyClr_Gmv_thr  = u32_RB_val      & 0xFFFF;
		pParam->_param_FRC_LGDet.u16_RgHstyClr_mv_thr   =(u32_RB_val>>16) & 0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u10_RgHstyClr_Gsad_thr = u32_RB_val      &0xFFFF;
		pParam->_param_FRC_LGDet.u10_RgHstyClr_Rsad_thr = (u32_RB_val>>16)&0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d4_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u12_RgHstyClr_Gmv_unconf_thr = u32_RB_val       &0xFFFF;
		pParam->_param_FRC_LGDet.u12_RgHstyClr_mv_unconf_thr  = (u32_RB_val>>16) &0xFFFF;

				/////////
				pParam->_param_FRC_LGDet.u6_logo_sc_Gmv_cnt_th = 0;
				pParam->_param_FRC_LGDet.u12_logo_sc_Gmv_unconf_th = 0;
				pParam->_param_FRC_LGDet.u20_logo_sc_dtldif_th = 0xDF0;
			}
			else if (pParam->_param_FRC_LGDet.u1_param_reg_scdetct == 1)
			{

				pParam->_param_FRC_LGDet.u16_RgHstyClr_Gmv_thr  = 8;
				pParam->_param_FRC_LGDet.u16_RgHstyClr_mv_thr   =2;

				pParam->_param_FRC_LGDet.u10_RgHstyClr_Gsad_thr = 14;
				pParam->_param_FRC_LGDet.u10_RgHstyClr_Rsad_thr = 10;

				pParam->_param_FRC_LGDet.u12_RgHstyClr_Gmv_unconf_thr = 6;
				pParam->_param_FRC_LGDet.u12_RgHstyClr_mv_unconf_thr  = 6;
				///////////////////
				/*			ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_cc_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u6_logo_sc_Gmv_cnt_th =  u32_RB_val      & 0xFFFF;

				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d0_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u12_logo_sc_Gmv_unconf_th = u32_RB_val    & 0xFFFFFFFF;

				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d4_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u20_logo_sc_dtldif_th = u32_RB_val    & 0xFFFFFFFF;*/

				// bai test
				pParam->_param_FRC_LGDet.u6_logo_sc_Gmv_cnt_th = 0;
				pParam->_param_FRC_LGDet.u12_logo_sc_Gmv_unconf_th = 0;
				//pParam->_param_FRC_LGDet.u20_logo_sc_dtldif_th = 0xDF0;

				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_cc_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u16_RgDhadp_Rimunbalance_thr_l = u32_RB_val       & 0xFFFF;
				pParam->_param_FRC_LGDet.u16_RgDhadp_Rimunbalance_thr_h = (u32_RB_val>>16) & 0xFFFF;
				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d0_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_wrt_comreg.u8_logo_mv_diff_diff_th_lg = u32_RB_val       & 0xFF;;
				pParam->_param_wrt_comreg.u8_logo_mv_diff_sad_th_lg  = (u32_RB_val >>  8)    & 0xFF;;
				pParam->_param_wrt_comreg.u8_logo_tmv_num_th_lg      = (u32_RB_val >> 16)    & 0xFF;
				pParam->_param_wrt_comreg.u8_logo_tmv_sad_th_lg      =  (u32_RB_val >> 24)   & 0xFF;

				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d4_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u20_logo_sc_dtldif_th = u32_RB_val    & 0xFFFF;
				pParam->_param_FRC_LGDet.u8_RgDhadp_Rimunbalance_hold_frm = (u32_RB_val>>16) & 0xFFFF;

			}


		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_d8_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u8_RgHstyClr_Gmv_cnt_thr     = u32_RB_val       &0xFFFF;
		pParam->_param_FRC_LGDet.u12_RgHstyClr_mv_cnt_thr     = (u32_RB_val>>16) &0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_dc_ADDR, 0, 31, &u32_RB_val);
			pParam->_param_FRC_LGDet.u31_logo_sc_saddiff_th       = u32_RB_val       &0x7FFFFFFF;
			pParam->_param_FRC_LGDet.u1_RgDhClr_static_en         = (u32_RB_val>>31)      &0x01;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_e0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u8_rg_dh_clr_lgclr_hold_frm         = u32_RB_val       &0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_e4_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u8_rg_dh_clr_static_hold_frm         = u32_RB_val       &0xFFFF;
			pParam->_param_FRC_LGDet.u8_logo_sc_hold_frm                  = (u32_RB_val>>16) &0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_e8_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_FRC_LGDet.u5_RgDhClr_cnt_th         = u32_RB_val       &0xFFFF;
			pParam->_param_FRC_LGDet.u8_logo_netflix_hold_frm  = (u32_RB_val>>16) &0xFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_ec_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_wrt_comreg.u8_logo_blksameth_l_bidx0_lg     = u32_RB_val       &0xFFFF;
		pParam->_param_wrt_comreg.u8_logo_blksameth_l_bidx0_com     = (u32_RB_val>>16) &0xFFFF;


			if (pParam->_param_FRC_LGDet.u1_param_reg_netflix_detect == 1)
			{
				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f0_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lt_th_l  = u32_RB_val 	  &0xFFFF;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lt_th_h  = (u32_RB_val>>16) &0xFFFF;

				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f4_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rt_th_l  = u32_RB_val 	  &0xFFFF;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rt_th_h  = (u32_RB_val>>16) &0xFFFF;

				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f8_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lb_th_l  = u32_RB_val 	  &0xFFFF;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lb_th_h  = (u32_RB_val>>16) &0xFFFF;

				ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_fc_ADDR, 0, 31, &u32_RB_val);
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rb_th_l  = u32_RB_val 	  &0xFFFF;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rb_th_h  = (u32_RB_val>>16) &0xFFFF;


				pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx0_lg	    = 0x4A;
				pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx0_com 	= 0x64;

				pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx10_lg 	 = 0x50;
				pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx10_com	 = 0x64;

				pParam->_param_wrt_comreg.u8_logo_blkhsty_pth_bidx10_lg 	 = 6;
				pParam->_param_wrt_comreg.u8_logo_blkhsty_pth_bidx10_com	 = 7;

				pParam->_param_wrt_comreg.u8_logo_blkhsty_nth_bidx10_lg 	 = 6;
				pParam->_param_wrt_comreg.u8_logo_blkhsty_nth_bidx10_com	 = 7;
			} 
			else
			{
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lt_th_l  = 0x58;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lt_th_h  = 0x130;

				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rt_th_l  = 0;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rt_th_h  = 0x20;

				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lb_th_l  = 0x75;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_lb_th_h  = 0xC0;

				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rb_th_l  = 0x90;
				pParam->_param_FRC_LGDet.u20_logo_netflix_detect_rb_th_h  = 0xF0;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f0_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx0_lg     = u32_RB_val       &0xFFFF;
		pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx0_com     = (u32_RB_val>>16) &0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f4_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx10_lg     = u32_RB_val       &0xFFFF;
		pParam->_param_wrt_comreg.u8_logo_blksameth_a_bidx10_com     = (u32_RB_val>>16) &0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_f8_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_wrt_comreg.u8_logo_blkhsty_pth_bidx10_lg     = u32_RB_val       &0xFFFF;
		pParam->_param_wrt_comreg.u8_logo_blkhsty_pth_bidx10_com     = (u32_RB_val>>16) &0xFFFF;

		ReadRegister(FRC_TOP__PQL_1__pql_logo_dummy_fc_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_wrt_comreg.u8_logo_blkhsty_nth_bidx10_lg     = u32_RB_val       &0xFFFF;
		pParam->_param_wrt_comreg.u8_logo_blkhsty_nth_bidx10_com     = (u32_RB_val>>16) &0xFFFF;

			}

		}


	}

	{
		ReadRegister(FRC_TOP__PQL_1__pql_rb_tc_mode_ADDR, 0, 31, &u32_RB_val);
		pParam->_param_read_comreg.u2_rb_tc_mode  =   u32_RB_val           & 0x03; 
		pParam->_param_read_comreg.u4_rb_tc1_coef =  (u32_RB_val >>  2)    & 0x0F;
		pParam->_param_read_comreg.u4_rb_tc2_coef =  (u32_RB_val >>  6)    & 0x0F;
		pParam->_param_read_comreg.u4_rb_tc3_coef =  (u32_RB_val >> 10)    & 0x0F;
	}
		
}

