#ifndef _FRC_LOGODETECT_H_
#define _FRC_LOGODETECT_H_


#define PIX_LOGO_RG_PIXCNT  (120*135)
#define PIX_LOGO_PIXCNT     (960*540)
#define BLK_LOGO_RG_BLKCNT  (30*34)
#define BLK_LOGO_BLKCNT     (240*135)
#define RG_15               (15)

#define LOGO_DEBUG_PRINTF   (0)

/* Param Definition*/
typedef struct  
{
	UBYTE  u1_logo_pql_en                    ;
	UBYTE  u1_logo_sw_clr_en                 ;
	UBYTE  u1_logo_rg_clr_en                 ;
	UBYTE  u1_logo_glb_clr_en                ;
	UBYTE  u1_logo_left_half_clr_en          ;
	UBYTE  u1_logo_right_half_clr_en         ;
	UBYTE  u1_logo_top_half_clr_en           ;
	UBYTE  u1_logo_bot_half_clr_en           ;
	UBYTE  u1_logo_sc_alpha_ctrl_en			 ;
	UBYTE  u1_logo_sc_logo_clr_en            ;
	//////////////////////////////////////////////////////////////////////////

	UBYTE  u8_clr_rg_thr                     ;
	UBYTE  u8_clr_rg_thr_l                   ;
	UBYTE  u8_clr_glb_thr                    ;
	UBYTE  u8_clr_half_thr                   ;
	UBYTE  u6_rgClr_holdtime 		         ;
	UBYTE  u6_glbClr_holdtime		         ;
	UBYTE  u4_blk_pix_merge_type             ;
	UBYTE  u5_iir_alpha				         ;

	UBYTE  u1_RgDhClr_thr_en                 ; 
	UINT32 u16_RgDhClr_thr_l                   ;
	UINT32 u16_RgDhClr_thr_h                   ;
	UINT32 u5_RgDhClr_cnt_th                   ;

	UBYTE  u1_RgHstyClr_en                    ;
	UBYTE  u1_GlbHstyClr_en                   ;
	UBYTE  u1_RgHstyClr_Sc_en                 ;

	UINT32 u16_RgHstyClr_mv_thr               ;
	UINT32 u12_RgHstyClr_mv_cnt_thr          ;
	UINT32 u12_RgHstyClr_mv_unconf_thr       ;
	UINT32 u10_RgHstyClr_Rsad_thr             ;

	UINT32 u16_RgHstyClr_Gmv_thr               ;
	UBYTE  u8_RgHstyClr_Gmv_cnt_thr          ;
	UINT32 u12_RgHstyClr_Gmv_unconf_thr       ;
	UINT32 u10_RgHstyClr_Gsad_thr             ;

	UBYTE  u1_RgHstyClr_glbclr_close_en       ;

	UBYTE  u1_RgDhClr_static_en;

	UBYTE   u8_rg_dh_clr_lgclr_hold_frm;
	UBYTE   u8_rg_dh_clr_static_hold_frm;

	UBYTE  u1_logo_sc_detect_en;
	UBYTE  u1_logo_sc_saddif_en;
	UBYTE  u1_logo_sc_Gmv_en;
	UBYTE  u1_logo_sc_dtldif_en;
	UINT32 u31_logo_sc_saddiff_th;
	UBYTE  u6_logo_sc_Gmv_cnt_th;
	UINT32 u12_logo_sc_Gmv_unconf_th;
	UINT32 u20_logo_sc_dtldif_th;
	UINT32 u8_logo_sc_hold_frm;

	UBYTE u1_logo_static_bg_en;
	UBYTE u6_logo_static_bg_th_l;
	UBYTE u6_logo_static_bg_th_h;

	UBYTE u1_param_reg_scdetct;

	UBYTE u1_logo_netflix_detct_en;
	
	UINT32 u20_logo_netflix_detect_lt_th_l;
	UINT32 u20_logo_netflix_detect_lt_th_h;
	UINT32 u20_logo_netflix_detect_rt_th_l;
	UINT32 u20_logo_netflix_detect_rt_th_h;

	UINT32 u20_logo_netflix_detect_lb_th_l;
	UINT32 u20_logo_netflix_detect_lb_th_h;
	UINT32 u20_logo_netflix_detect_rb_th_l;
	UINT32 u20_logo_netflix_detect_rb_th_h;

	UBYTE  u8_logo_netflix_hold_frm;

	UBYTE  u1_param_reg_netflix_detect;

	UBYTE  u1_param_reg_lg16s_patch;

	UBYTE  u1_logo_lg16s_patch_en;
	UBYTE  u1_logo_lg16s_patch_Gapl_en;
	UBYTE  u1_logo_lg16s_patch_Gdtl_en;
	UBYTE  u1_logo_lg16s_patch_Gsad_en;
	UBYTE  u1_logo_lg16s_patch_Gmv_en;	
	UBYTE  u1_logo_lg16s_patch_Rdtl_num_en;

	UINT32 u10_logo_lg16s_patch_Gapl_th_l;
	UINT32 u10_logo_lg16s_patch_Gapl_th_h;

	UINT32 u25_logo_lg16s_patch_Gdtl_th_l;
	UINT32 u25_logo_lg16s_patch_Gdtl_th_h;

	UINT32 u28_logo_lg16s_patch_Gsad_th_l;
	UINT32 u28_logo_lg16s_patch_Gsad_th_h;

	UINT32 u11_logo_lg16s_patch_Gmvx_th_l;
	UINT32 u11_logo_lg16s_patch_Gmvx_th_h;
    UINT32 u11_logo_lg16s_patch_Gmvy_th;
	UBYTE  u6_logo_lg16s_patch_Gmv_cnt_th;
	UINT32 u12_logo_lg16s_patch_Gmv_unconf_th;

	UINT32 u20_logo_lg16s_patch_Rdtl_th_l;
	UINT32 u20_logo_lg16s_patch_Rdtl_th_h;
	UBYTE  u6_logo_lg16s_patch_Rdtl_num_th;

	UBYTE  u8_logo_lg16s_patch_hold_frm;

	UINT32 u16_RgDhadp_Rimunbalance_thr_l;
	UINT32 u16_RgDhadp_Rimunbalance_thr_h ;
	UBYTE  u8_RgDhadp_Rimunbalance_hold_frm;


	UBYTE u1_lg_UXN_patch_en;

	//UBYTE  u1_logo_dynY_en                   ;
	//UBYTE  u1_logo_dynBlkTh_en               ;
	//UBYTE  u1_logo_dynPixTh_en               ;
	//UBYTE  u1_logo_dynBlkStep_en             ;
	//UBYTE  u1_logo_dynPixStep_en             ;
	//UBYTE  u1_logo_dynAlpha_en               ;
	//UBYTE  u1_logo_dynDelogo_en              ;
	//UBYTE u1_logo_pixRgClr_en 				 ;
	//UBYTE u1_logo_pixGlbClr_en				 ;
	//UBYTE u1_logo_blkGlbClrHsty_en			 ;
	//UBYTE u1_logo_pixGlbClrHsty_en			 ;
	//UBYTE u1_logo_blkRgClrHsty_en 			 ;
	//UBYTE u1_logo_pixRgClrHsty_en 			 ;									
	//UBYTE u1_logo_delogoGlbClr_en 			 ;
	//UBYTE u1_logo_delogoRgClr_en  			 ;
	//UBYTE u1_logo_delogoGlbClrHsty_en		 ;
	//UBYTE u1_logo_delogoRgClrHsty_en 		 ;									
	//UBYTE u1_logo_SCalphaClr_en				 ;
	//UBYTE u1_logo_SCHstyClr_en 				 ;
	//UBYTE u1_logo_SCLogoClr_en 				 ;

	//UBYTE  u8_clr_rg_thr;
	//UBYTE  u8_clr_glb_thr;
	//UBYTE  u8_dynBlkTh_cnt;
	//UBYTE  u8_dynPixTh_cnt;
	//UBYTE  u8_dynBlkStep_cnt;
	//UBYTE  u8_dynPixStep_cnt;
	//UINT16 u16_dynDelogo_mv_th;
	//UBYTE  u8_dynDelogo_rat_th;


	//UBYTE u6_SCalpha_holdtime 		  ;
	//UBYTE u6_SCclrHsty_holdtime 	  ;
	//UBYTE u6_SCclrlogo_holdtime 	  ;
	//UBYTE u8_pixRgClr_thr 			  ;
	//UBYTE u8_pixGlbClr_thr			  ;
	//UBYTE u8_dynY_cnt 				  ;
	//UBYTE u8_delogoRgclr_thr 		  ;
	//UBYTE u8_delogoGlbClr_thr		  ;

	////maybe in output is easy init.

	//UINT32 u32_pxRgYDf_bypass_0_31    ;
	//UBYTE  u4_blklogo_pStep           ;
	//UBYTE  u4_pixlogo_pStep           ;

	//UBYTE  u8_cmo_clear_thr           ;  //(thr)
	//UINT32 u32_cmo_clear_idx          ;  //(idx)
	//UBYTE  u8_gg_mvd12_thr            ;  //good gmv
	//UBYTE  u8_gg_mvx_thr              ;
	//UBYTE  u8_gg_mvy_thr              ;
	//UBYTE  u8_gg_alpha_thr            ;
	//UINT32 u32_gg_sad_thr             ;
	//UBYTE  u8_gg_num_thr              ;
	//UBYTE  u8_reg_mvd                 ;
	//UBYTE  u8_reg_tmv                 ;
	//UBYTE  u1_printf_en               ;
	//UBYTE  u1_blkHsty_upmet           ;   
	//


}_PARAM_FRC_LGDet;


/* Output Definition*/
//typedef struct  
//{
//	UINT32 u14_pixlogo_rgcnt[RG_32];
//	UINT32 u20_pixlogo_rgaccY[RG_32];
//}_OUTPUT_FRC_LGDet_RB;
//
//typedef struct  
//{
//	UINT16 u14_pixlogo_rgcnt[RG_32];
//	UINT32 u20_pixlogo_rgY[RG_32];
//	UINT32 u32_frm_cnt; 
//}_OUTPUT_FRC_LGDet_DynSet;
//
//
////total
//typedef struct  
//{
//	_OUTPUT_FRC_LGDet_RB       sLogo_rb;
//	_OUTPUT_FRC_LGDet_DynSet   sLogo_dyn_set;
//}_OUTPUT_FRC_LGDet;


typedef struct  
{

	SINT16  s16_blklogo_rgclr_cnt[LOGO_RG_32];
	SINT16  s16_blklogo_glbclr_cnt;
	UINT32  u32_blklogo_clr_idx;
	UBYTE	u1_sw_clr_en_out;
	UBYTE   u1_blkclr_glbstatus;
	UBYTE   u4_blk_pix_merge_type_out;	
	UBYTE   u5_iir_alpha_out;

	UBYTE   u1_rg_dh_clr_rg0;
	UBYTE   u1_rg_dh_clr_rg1;
	UBYTE   u1_rg_dh_clr_rg2;
	UBYTE   u1_rg_dh_clr_rg3;

	UBYTE   u8_rg_dh_clr_lgclr_hold_frm;
	UBYTE   u8_rg_dh_clr_static_hold_frm;

	UINT32  u32_logo_hsty_clr_idx;
	UINT32  u32_logo_hsty_clr_lgclr_idx;
	UBYTE   u1_logo_cnt_glb_clr_status;
	UBYTE   u1_logo_sc_glb_clr_status;

	UBYTE  u1_logo_static_status;

	UBYTE  u1_logo_sc_status;
	UINT32 u31_logo_sad_pre;
	UINT32 u20_logo_dtl_pre[32];
	UBYTE  u1_logo_sc_saddif_status;
	UBYTE  u1_logo_sc_Gmv_status;
	UBYTE  u1_logo_sc_dtldif_status;

	UINT32 u8_logo_sc_hold_frm;

	UBYTE  u8_Rg_static_num;
	UINT32 u32_Rg_unstatic_idx;

	UBYTE  u1_logo_netflix_status;
	UBYTE  u8_logo_netflix_hold_frm;

	UBYTE  u1_logo_lg16s_patch_Gapli_status;
	UBYTE  u1_logo_lg16s_patch_Gaplp_status;
	UBYTE  u1_logo_lg16s_patch_Gdtl_status;
	UBYTE  u1_logo_lg16s_patch_Gsad_status;
	UBYTE  u1_logo_lg16s_patch_Gmv_status;	
	UBYTE  u1_logo_lg16s_patch_Rdtl_num_status;
	UBYTE  u1_logo_lg16s_patch_status;
	UBYTE  u8_logo_lg16s_patch_hold_frm;

	UBYTE  u8_RgDhadp_Rimunbalance_hold_frm;
	UBYTE  u1_RgDhadp_Rimunbalance_status;

	// UXN Patch
	UBYTE u1_lg_UXN_patch_det;

	//UINT32 u14_pixlogo_rgcnt[RG_32];
	//UINT32 u20_pixlogo_rgaccY[RG_32];

	//
	//SINT16  s16_gmv_x_max[RG_32];
	//SINT16  s16_gmv_y_max[RG_32];
	//UBYTE   u8_gmv_rat_max[RG_32];

	//SINT16  s16_gmv_x_sec[RG_32];
	//SINT16  s16_gmv_y_sec[RG_32];
	//UBYTE   u8_gmv_rat_sec[RG_32];

	//UINT32  u32_region_sad_sum[RG_32];
	//SINT16  s16_pixlogo_rgclr_cnt[RG_32];
	//SINT16  s16_pixlogo_glbclr_cnt;

	//SINT16  s16_SC_clrAlpha_cnt;
	//SINT16  s16_SC_clrLogo_cnt;
	//SINT16	s16_SC_holdHsty_cnt;

	//UINT32 u32_frm_cnt; 
	//UINT32 u32_acc_pixlg_cnt;


	//UBYTE  u1_pixclr_glbstatus;

	//UBYTE  u1_blkclr_glbHsty_status;
	//UBYTE  u1_pixclr_glbHsty_status;

	//UBYTE  u5_alpha_bld;
	//UBYTE  u4_blklogo_pStep_cur;
	//UBYTE  u4_pixlogo_pStep_cur;


	//UINT32 u32_pixlogo_clr_idx;

}_OUTPUT_FRC_LGDet;


/* MOdule UI Definition*/
DEBUGMODULE_BEGIN(_PARAM_FRC_LGDet,_OUTPUT_FRC_LGDet)
	//param old
	ADD_PARAM(UBYTE,    u1_logo_pql_en				    ,	  0     )
	ADD_PARAM(UBYTE,    u1_logo_sw_clr_en	    	    ,	  1     )
	ADD_PARAM(UBYTE,    u1_logo_rg_clr_en				,	  0    	)
	ADD_PARAM(UBYTE,    u1_logo_glb_clr_en			    ,	  1    	)
	ADD_PARAM(UBYTE,    u1_logo_left_half_clr_en	    ,	  1    	)
	ADD_PARAM(UBYTE,    u1_logo_right_half_clr_en	    ,	  1    	)
	ADD_PARAM(UBYTE,    u1_logo_top_half_clr_en		    ,	  1    	)
	ADD_PARAM(UBYTE,    u1_logo_bot_half_clr_en		    ,	  1    	)
	ADD_PARAM(UBYTE,    u1_logo_sc_alpha_ctrl_en        ,	  1    	)
	ADD_PARAM(UBYTE,    u1_logo_sc_logo_clr_en          ,	  1    	)
	
	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,    u8_clr_rg_thr		            ,     215   )
	ADD_PARAM(UBYTE,    u8_clr_glb_thr		            ,     80    )
	ADD_PARAM(UBYTE, 	u8_clr_half_thr     	        ,     70	)
	ADD_PARAM(UBYTE,    u6_rgClr_holdtime		        ,     5     )
	ADD_PARAM(UBYTE,    u6_glbClr_holdtime		        ,     5     )
	ADD_DUMMY_PARAM()
	ADD_PARAM(UBYTE,    u4_blk_pix_merge_type		    ,     0     )
	ADD_PARAM(UBYTE,    u5_iir_alpha                 	,     31    )


	//ADD_PARAM(UBYTE,  u1_logo_dynY_en				,	  0    	)
	//ADD_PARAM(UBYTE,  u1_logo_dynBlkTh_en			,	  1    	)
	//ADD_PARAM(UBYTE,  u1_logo_dynPixTh_en			,	  1    	)
	//ADD_PARAM(UBYTE,  u1_logo_dynBlkStep_en			,	  1    	)
	//ADD_PARAM(UBYTE,  u1_logo_dynPixStep_en			,	  1    	)
	//ADD_PARAM(UBYTE,  u1_logo_dynAlpha_en			,	  1    	)
	//ADD_PARAM(UBYTE,  u1_logo_dynDelogo_en			,	  0    	)
	//ADD_PARAM(UBYTE,  u1_logo_pixRgClr_en 			,     0		)
	//ADD_PARAM(UBYTE,  u1_logo_pixGlbClr_en			,     0		)
	//ADD_PARAM(UBYTE,  u1_logo_blkGlbClrHsty_en		,	  0		)
	//ADD_PARAM(UBYTE,  u1_logo_pixGlbClrHsty_en		,     0		)
	//ADD_PARAM(UBYTE,  u1_logo_blkRgClrHsty_en 		,     0		)
	//ADD_PARAM(UBYTE,  u1_logo_pixRgClrHsty_en 		,     0		)
	//ADD_PARAM(UBYTE,  u1_logo_delogoGlbClr_en 		,     0		)
	//ADD_PARAM(UBYTE,  u1_logo_delogoRgClr_en  		,     0		)
	//ADD_PARAM(UBYTE,  u1_logo_delogoGlbClrHsty_en	,	  0		)
	//ADD_PARAM(UBYTE,  u1_logo_delogoRgClrHsty_en 	,	  0		)
	//ADD_PARAM(UBYTE,  u1_logo_SCalphaClr_en			,	  1		)
	//ADD_PARAM(UBYTE,  u1_logo_SCHstyClr_en 			,	  1		)
	//ADD_PARAM(UBYTE,  u1_logo_SCLogoClr_en 			,	  1		)


	//ADD_PARAM(UBYTE,    u8_clr_rg_thr		        ,     215   	)
	//ADD_PARAM(UBYTE,    u8_clr_glb_thr		        ,     60    	)
	//ADD_PARAM(UBYTE,    u8_dynBlkTh_cnt 		    ,     10    	)
	//ADD_PARAM(UBYTE,    u8_dynPixTh_cnt 		    ,     10    	)
	//ADD_PARAM(UBYTE,    u8_dynBlkStep_cnt			,     10    	)
	//ADD_PARAM(UBYTE,    u8_dynPixStep_cnt			,     10    	)
	//ADD_PARAM(UINT16,   u16_dynDelogo_mv_th 		,     15  		)
	//ADD_PARAM(UBYTE,    u8_dynDelogo_rat_th	    	,     180		)
	//ADD_PARAM(UBYTE,    u6_rgClr_holdtime 		    ,     5			)
	//ADD_PARAM(UBYTE,    u6_glbClr_holdtime		    ,     5			)
	//ADD_PARAM(UBYTE,    u6_SCalpha_holdtime 	    ,     1			)
	//ADD_PARAM(UBYTE,    u6_SCclrHsty_holdtime 	    ,     1			)
	//ADD_PARAM(UBYTE,    u6_SCclrlogo_holdtime 	    ,     1			)
	//ADD_PARAM(UBYTE,    u8_pixRgClr_thr 		    ,     215		)
	//ADD_PARAM(UBYTE,    u8_pixGlbClr_thr		    ,     67		)
	//ADD_PARAM(UBYTE,    u8_dynY_cnt 			    ,     10		)
	//ADD_PARAM(UBYTE,    u8_delogoRgclr_thr 	        ,     215		)
	//ADD_PARAM(UBYTE,    u8_delogoGlbClr_thr	        ,	  67		)

	//ADD_PARAM(UINT32,   u32_pxRgYDf_bypass_0_31     ,      0		)
	//ADD_PARAM(UBYTE,    u4_blklogo_pStep            ,      1		)
	//ADD_PARAM(UBYTE,    u4_pixlogo_pStep            ,      1		)

	//ADD_PARAM(UBYTE, 	u8_cmo_clear_thr     		,	  55		)
	//ADD_PARAM(UINT32, 	u32_cmo_clear_idx    		,	  240		)
	//ADD_PARAM(UBYTE, 	u8_gg_mvd12_thr      		,	  20		)
	//ADD_PARAM(UBYTE, 	u8_gg_mvx_thr        		,	  10		)
	//ADD_PARAM(UBYTE, 	u8_gg_mvy_thr        		,	  10		)
	//ADD_PARAM(UBYTE, 	u8_gg_alpha_thr      		,	  100		)
	//ADD_PARAM(UINT32, 	u32_gg_sad_thr       		,	  32000		)
	//ADD_PARAM(UBYTE, 	u8_gg_num_thr        		,	  28		)
	//ADD_PARAM(UBYTE, 	u8_reg_mvd           		,	  0			)
	//ADD_PARAM(UBYTE, 	u8_reg_tmv           		,	  0			)
	//ADD_PARAM(UBYTE, 	u1_printf_en         		,	  0			)
	//ADD_PARAM(UBYTE, 	u1_blkHsty_upmet     	    ,      1		)




	//////////////////////////////////////////////////////////////////////////
	//output

	 ADD_OUTPUT(UBYTE,  u1_blkclr_glbstatus)
	 ADD_OUTPUT(UINT32, u32_blklogo_clr_idx)
	 ADD_OUTPUT(UBYTE,  u5_iir_alpha_out)	 


	//ADD_OUTPUT_ARRAY(UINT32, u14_pixlogo_rgcnt,     RG_32)
	//ADD_OUTPUT_ARRAY(UINT32, u20_pixlogo_rgaccY,    RG_32)


	//ADD_OUTPUT_ARRAY(SINT16, s16_gmv_x_max,     RG_32)
	//ADD_OUTPUT_ARRAY(SINT16, s16_gmv_y_max,     RG_32)
	//ADD_OUTPUT_ARRAY(UBYTE,  u8_gmv_rat_max,    RG_32)

	//ADD_OUTPUT_ARRAY(SINT16,  s16_gmv_x_sec,     RG_32)
	//ADD_OUTPUT_ARRAY(SINT16,  s16_gmv_y_sec,     RG_32)
	//ADD_OUTPUT_ARRAY(UBYTE,   u8_gmv_rat_sec,    RG_32)

	//ADD_OUTPUT_ARRAY(UINT32,   u32_region_sad_sum,    RG_32)

	//ADD_OUTPUT_ARRAY(SINT16,  s16_blklogo_rgclr_cnt,     RG_32)
	//ADD_OUTPUT(SINT16,  s16_blklogo_glbclr_cnt)

	//ADD_OUTPUT_ARRAY(SINT16,  s16_pixlogo_rgclr_cnt,     RG_32)
	//ADD_OUTPUT(SINT16,  s16_pixlogo_glbclr_cnt)

	//ADD_OUTPUT(SINT16,  s16_SC_clrAlpha_cnt)
	//ADD_OUTPUT(SINT16,  s16_SC_clrLogo_cnt)
	//ADD_OUTPUT(SINT16,  s16_SC_holdHsty_cnt)

	//ADD_OUTPUT(UINT32,u32_frm_cnt)
 //	ADD_OUTPUT(UINT32,u32_acc_pixlg_cnt)


	//ADD_OUTPUT(UBYTE, u1_pixclr_glbstatus)

	//ADD_OUTPUT(UBYTE, u1_blkclr_glbHsty_status)
	//ADD_OUTPUT(UBYTE, u1_pixclr_glbHsty_status)

	//ADD_OUTPUT(UBYTE, u5_alpha_bld)
	//ADD_OUTPUT(UBYTE, u4_blklogo_pStep_cur)
	//ADD_OUTPUT(UBYTE, u4_pixlogo_pStep_cur)

	//ADD_OUTPUT(UINT32, u32_blklogo_clr_idx)
	//ADD_OUTPUT(UINT32, u32_pixlogo_clr_idx)

	//ADD_OUTPUT_ARRAY(UINT32, u14_pixlogo_rgcnt, RG_32)
DEBUGMODULE_END


	/* Function Declaration*/
	VOID FRC_LogoDet_Init(_OUTPUT_FRC_LGDet *pOutput);
    VOID FRC_LogoDet_Proc(const _PARAM_FRC_LGDet *pParam, _OUTPUT_FRC_LGDet *pOutput);

#endif
