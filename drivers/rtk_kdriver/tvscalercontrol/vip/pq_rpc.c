#if CONFIG_FIRMWARE_IN_KERNEL

#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
//#include <mach/io.h>
//#include <mach/RPCDriver.h>
#include <linux/pageremap.h>
#include <tvscalercontrol/vip/pq_rpc.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"

// for register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

#else

/*some include about AP*/
#include <Platform_Lib/TVScalerControl/scaler/scalerLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerColorLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerTimer.h>
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>

/*some include about VIP Driver*/
/*#include <tvscalercontrol/vip/scalerColor.h>*/
#include <Platform_Lib/TVScalerControl/vip/scalerColor_tv006.h>
#include <Platform_Lib/TVScalerControl/vip/di_ma.h>
#include <Platform_Lib/TVScalerControl/vip/peaking.h>
#include <Platform_Lib/TVScalerControl/vip/icm.h>
#include <Platform_Lib/TVScalerControl/vip/dcc.h>
#include <Platform_Lib/TVScalerControl/vip/ultrazoom.h>
#include <Platform_Lib/TVScalerControl/vip/color.h>
#include <Platform_Lib/TVScalerControl/vip/xc.h>
#include <Platform_Lib/TVScalerControl/vip/intra.h>
#include <Platform_Lib/TVScalerControl/vip/nr.h>
#include <Platform_Lib/TVScalerControl/vip/film.h>
#include <Platform_Lib/TVScalerControl/vip/pq_adaptive.h>
#include <Platform_Lib/TVScalerControl/vip/gibi_od.h>
#include <Platform_Lib/TVScalerControl/vdc/video.h>
#include <Platform_Lib/TVScalerControl/vip/localdimming.h>
/*some include about scaler*/
#include <scaler/scalerDrvCommon.h>
#include <rbusHistogramReg.h>
/*some include about rbus*/
/*some include about device driver*/
#include <Platform_Lib/TVScalerControl/hdmiRx/hdmiFun.h>
#endif
#if CONFIG_FIRMWARE_IN_KERNEL
//#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)	//20150822 roger mark for image release
#define VIPprintf(fmt, args...)
#define	vip_malloc(x)	kmalloc(x, GFP_KERNEL)
#define	vip_free(x)	kfree(x)
#else
//#define VIPprintf(fmt, args...)	printf(fmt, ##args)	//20150822 roger mark for image release
#define VIPprintf(fmt, args...)
#define	vip_malloc(x)	malloc(x)
#define	vip_free(x)	free(x)
#endif
extern unsigned char DynamicOptimizeSystem[200];

unsigned int StatusFrameStaticPattern=0,StatusFrameStaticPattern_H1=0,StatusFrameStaticPattern_H2=0,StatusFrameStaticPattern_H3=0;
unsigned int StatusFrameStaticPattern_V1=0,StatusFrameStaticPattern_V2=0,StatusFrameStaticPattern_V3=0,StatusFrameStaticPattern_C=0;
unsigned int StatusFramePairPattern=0,StatusFramePairPattern_H1=0,StatusFramePairPattern_H2=0,StatusFramePairPattern_H3=0;
unsigned int StatusFramePairPattern_V1=0,StatusFramePairPattern_V2=0,StatusFramePairPattern_V3=0,StatusFramePairPattern_C=0;
unsigned int StatusPrevStaticPattern=0,StatusPrevStaticPattern_H1=0,StatusPrevStaticPattern_H2=0,StatusPrevStaticPattern_H3=0;
unsigned int StatusPrevStaticPattern_V1=0,StatusPrevStaticPattern_V2=0,StatusPrevStaticPattern_V3=0,StatusPrevStaticPattern_C=0;
unsigned int StatusNextStaticPattern=0,StatusNextStaticPattern_H1=0,StatusNextStaticPattern_H2=0,StatusNextStaticPattern_H3=0;
unsigned int StatusNextStaticPattern_V1=0,StatusNextStaticPattern_V2=0,StatusNextStaticPattern_V3=0,StatusNextStaticPattern_C=0;
unsigned int StatusPrevStaticPattern2=0,StatusPrevStaticPattern2_H1=0,StatusPrevStaticPattern2_H2=0,StatusPrevStaticPattern2_H3=0;
unsigned int StatusPrevStaticPattern2_V1=0,StatusPrevStaticPattern2_V2=0,StatusPrevStaticPattern2_V3=0,StatusPrevStaticPattern2_C=0;
unsigned int StatusNextStaticPattern2=0,StatusNextStaticPattern2_H1=0,StatusNextStaticPattern2_H2=0,StatusNextStaticPattern2_H3=0;
unsigned int StatusNextStaticPattern2_V1=0,StatusNextStaticPattern2_V2=0,StatusNextStaticPattern2_V3=0,StatusNextStaticPattern2_C=0;
unsigned int StatusNextStaticPattern_film22=0,StatusNextStaticPattern_film22_H1=0,StatusNextStaticPattern_film22_H2=0,StatusNextStaticPattern_film22_H3=0;
unsigned int StatusNextStaticPattern_film22_V1=0,StatusNextStaticPattern_film22_V2=0,StatusNextStaticPattern_film22_V3=0,StatusNextStaticPattern_film22_C=0;
unsigned int* StatusNextStaticPattern_film22_PTR[8];
unsigned int fw_StatusPrevFieldMotion_film22[8];
unsigned int fw_StatusNextFieldMotion_film22[8];
unsigned int StatusNextStaticPattern2_film22=0;//,StatusNextStaticPattern2_film22_H1=0,StatusNextStaticPattern2_film22_H2=0,StatusNextStaticPattern2_film22_H3=0;
//unsigned int StatusNextStaticPattern2_film22_V1=0,StatusNextStaticPattern2_film22_V2=0,StatusNextStaticPattern2_film22_V3=0,StatusNextStaticPattern2_film22_C=0;

unsigned int index32,index32_H1,index32_H2,index32_H3,index32_V1,index32_V2,index32_V3,index32_C;
unsigned int stillpix_count32=0,stillpix_count32_H1=0,stillpix_count32_H2=0,stillpix_count32_H3=0,stillpix_count32_V1=0,stillpix_count32_V2=0,stillpix_count32_V3=0,stillpix_count32_C=0;
unsigned char Status32Detected1=0,Status32Detected1_H1=0,Status32Detected1_H2=0,Status32Detected1_H3=0,Status32Detected1_V1=0,Status32Detected1_V2=0,Status32Detected1_V3=0,Status32Detected1_C=0;
unsigned int Status32Sequence1,Status32Sequence1_H1,Status32Sequence1_H2,Status32Sequence1_H3,Status32Sequence1_V1,Status32Sequence1_V2,Status32Sequence1_V3,Status32Sequence1_C;

unsigned int index322,index322_H1,index322_H2,index322_H3,index322_V1,index322_V2,index322_V3,index322_C;
unsigned char Status32Detected2=0,Status32Detected2_H1=0,Status32Detected2_H2=0,Status32Detected2_H3=0,Status32Detected2_V1=0,Status32Detected2_V2=0,Status32Detected2_V3=0,Status32Detected2_C=0;
unsigned int Status32Sequence2,Status32Sequence2_H1,Status32Sequence2_H2,Status32Sequence2_H3,Status32Sequence2_V1,Status32Sequence2_V2,Status32Sequence2_V3,Status32Sequence2_C;

unsigned int index22,index22_H1,index22_H2,index22_H3,index22_V1,index22_V2,index22_V3,index22_C;
unsigned int stillpix_count22=0,stillpix_count22_H1=0,stillpix_count22_H2=0,stillpix_count22_H3=0,stillpix_count22_V1=0,stillpix_count22_V2=0,stillpix_count22_V3=0,stillpix_count22_C=0;
unsigned char Status22Detected=0,Status22Detected_H1=0,Status22Detected_H2=0,Status22Detected_H3=0,Status22Detected_V1=0,Status22Detected_V2=0,Status22Detected_V3=0,Status22Detected_C=0;
unsigned int Status22Sequence,Status22Sequence_H1,Status22Sequence_H2,Status22Sequence_H3,Status22Sequence_V1,Status22Sequence_V2,Status22Sequence_V3,Status22Sequence_C;

unsigned int Status32Detected1_cnt=0,Status32Detected1_H1_cnt=0,Status32Detected1_H2_cnt=0,Status32Detected1_H3_cnt=0;
unsigned int Status32Detected1_V1_cnt=0,Status32Detected1_V2_cnt=0,Status32Detected1_V3_cnt=0,Status32Detected1_C_cnt=0;
unsigned int Status32Detected2_cnt=0,Status32Detected2_H1_cnt=0,Status32Detected2_H2_cnt=0,Status32Detected2_H3_cnt=0;
unsigned int Status32Detected2_V1_cnt=0,Status32Detected2_V2_cnt=0,Status32Detected2_V3_cnt=0,Status32Detected2_C_cnt=0;
unsigned int Status22Detected_cnt=0,Status22Detected_H1_cnt=0,Status22Detected_H2_cnt=0,Status22Detected_H3_cnt=0;
unsigned int Status22Detected_V1_cnt=0,Status22Detected_V2_cnt=0,Status22Detected_V3_cnt=0,Status22Detected_C_cnt=0;

unsigned char MisMatch32=0, MisMatch22=0;
unsigned char MixedFilmConfuse;

unsigned char StatusFilmDetected=0;
unsigned int StatusFilmSequence=0;
unsigned char StatusMixedFilmDetected=0;
unsigned int film_index=0;
unsigned char fw_DI_3A;
unsigned char force_weave_flag=0;
unsigned char weave_prev;
unsigned char NextTopDetected;
unsigned char PrevTopDetected;
//unsigned char TopDetected_d;
unsigned char PrevTopDetected_d;
unsigned char NextTopDetected_d;
unsigned int  TopLine, BotLine;
unsigned int  TopLine2, BotLine2;
unsigned int  TopLine3, BotLine3;

unsigned int StatusFramePairPattern2=0,StatusFramePairPattern2_H1=0,StatusFramePairPattern2_H2=0,StatusFramePairPattern2_H3=0;
unsigned int StatusFramePairPattern2_V1=0,StatusFramePairPattern2_V2=0,StatusFramePairPattern2_V3=0,StatusFramePairPattern2_C=0;

unsigned int Film22_StatusNextStaticPattern_noH3=0;

unsigned char g_st_DI_STATUS_VPAN = 0;
bool HFT_prev=1;//,HFT_prev_H1=1,HFT_prev_H2=1,HFT_prev_H3=1,HFT_prev_V1=1,HFT_prev_V2=1,HFT_prev_V3=1,HFT_prev_C=1;
unsigned int FW_HFT;
unsigned int FW_StatusNextHighFreqTerm=0;	// for enchance 22
unsigned int FW_StatusNextStaticPattern2_film22=0;	// for enchance 22
int A22_StatusFrameDiffSum[8][8];
int A22_StatusPrevDiffSum[8][8];
int A22_StatusNextDiffSum[8][8];
int* p22_StatusPrevDiffSum[8];
int* p22_StatusNextDiffSum[8];
int fw_di_film_sawtooth_comparePrevNext=0;
int rpt_di_film_spear2_hifreq=0;
int vc_di_film_getDiffSumRemap(int x){
	// copy from experimental C-Model
	// You can adjust this curve in FW.
	int y=0;
	int k;
	int z;
	x=(x+0)>>3;// no round because bitnum issue
	for(k=0;k<4&&x>0;k++){
		z=x>32?32:x;// experimental registers, default 32
		y=y+z;
		x=(x-z)>>1;
	}
	return y+x;
}

int scalerVIP_film_FWmode_22all_suspect32(int xFrameStatic){
	switch(xFrameStatic&0x3ff)
	{
		case 0x21:
		case 0x42:
		case 0x84:
		case 0x108:
		case 0x210:
		return 1;
	}
	return 0;
}
void scalerVIP_film_FWmode_detection22q(
	unsigned char NextStaticPattern, unsigned char FramePairPattern,
	unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,
	unsigned char *p22Detected, unsigned int *p22Sequence)
{
	*ExactMatch=0;
	*Violate=0;
	if((NextStaticPattern&3)==1){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 2 : 1;
		*film_index=FILM22;
	}else if((NextStaticPattern&3)==2){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 1 : 2;
		*film_index=FILM22;
	}else if((FramePairPattern&3)==2){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 2 : 1;
		*film_index=FILM22;
	}else if((FramePairPattern&3)==1){
		*ExactMatch=1;
		*p22Detected=1;
		*p22Sequence=(fw_DI_3A) ? 1 : 2;
		*film_index=FILM22;
	}else if((NextStaticPattern&3)==3){
		*ExactMatch=0;
		//*Violate=1;
		*p22Detected=0;
		*p22Sequence=0;
		*film_index=0;
	}else if(p22Sequence[0]==1){
		*p22Sequence=2;
	}else if(p22Sequence[0]==2){
		*p22Sequence=1;
	}
}
void scalerVIP_film_FWmode_Quick_detection(
	int x32enable,
	unsigned int FrameStaticPattern,unsigned int FramePairPattern,
	unsigned char NextStaticPattern,unsigned char NextStaticPattern22,
	unsigned char *ExactMatch321, unsigned char *Violate321, unsigned int *index321,
	unsigned char *p32Detected1, unsigned int *p32Sequence1,
	unsigned char *ExactMatch322, unsigned char *Violate322, unsigned int *index322,
	unsigned char *p32Detected2, unsigned int *p32Sequence2,
	unsigned char *ExactMatch22, unsigned char *Violate22, unsigned int *index22,
	unsigned char *p22Detected, unsigned int *p22Sequence
){
	int z32enable=0;//x32enable;// side effect found, only do 22

	if(x32enable&&p32Detected2[0]){
		*p22Detected=0;
		*p22Sequence=0;
	}else{
		scalerVIP_film_FWmode_detection22q(
			NextStaticPattern22, FramePairPattern,
			ExactMatch22, Violate22,index22,
			p22Detected, p22Sequence
		);
	}
}
int framestaticonly;
FILM_FWMode DETECTION_scalerVIP_film_FWmode()
{
	// fw film setting
	// 0 -> 22 enchance
	// 1 -> FILM3223
	// 2 -> FILM64
	// 3 -> FILM55
	// 4 -> FILM2224
	// 5 -> FILM32322
	// 6 -> FILM87

	/// fw film control setting  ///

	static unsigned char fw_film_control_force_weave_en=0;
	static unsigned int MarkMargin=32;

	static unsigned int Weave_Mode_d=2,StatusFilmWeaveMode=2;

	static unsigned char enchance22_en,film3223_en,film64_en,film55_en,film2224_en,film32322_en,film87_en;
	static unsigned char filmQuick_en;

	// parameters from hw  hw_XXX read from register
	static unsigned char hw_film_Status32Detected1,hw_film_Status32Detected2,hw_film_Status22Detected;
	static unsigned char hw_film_StatusFilmDetected,hw_film_StatusMixedFilmDetected,hw_film_MixedFilmConfuse;
	static unsigned int hw_film_StatusFilmSequence;
	static unsigned char hw_film_VerScrollingText_en,hw_film_thumbnail_en;
	static unsigned int hw_film_32Film,hw_film_22Film;
	static unsigned char hw_film_Enable;
	static unsigned char hw_AdoptHDMethod,hw_RTNR_Interlace_Force2D_En;
	static unsigned char hw_film_BadEditor_flag;
	static unsigned int hw_StatusFrameStaticPattern_All,hw_StatusFramePairPattern_All,hw_StatusPrevStaticPattern_All; // 40c8
	static unsigned int hw_StatusNextStaticPattern_All,hw_StatusPrevStaticPattern2_All,hw_StatusNextStaticPattern2_All,hw_StatusNextFieldMotion_All; //40cc
	static unsigned int hw_StatusPrevFieldMotion_All,hw_StatusPrevFieldMotion_film22_All;
	static unsigned int hw_StatusNextFieldMotion_film22_All,hw_StatusNextStaticPattern_film22_All;
	static unsigned int hw_FieldStaticSumThl,hw_FieldMotionSumThl;
	static unsigned int hw_PrevTopMark,hw_PrevBotMark;
	static unsigned int hw_PrevTopMark2,hw_PrevBotMark2;
	static unsigned int hw_PrevTopMark3,hw_PrevBotMark3;
	static unsigned int hw_NextTopMark,hw_NextBotMark;
	static unsigned int hw_NextTopMark2,hw_NextBotMark2;
	static unsigned int hw_NextTopMark3,hw_NextBotMark3;
	static unsigned int hw_PrevTopMarkp,hw_PrevBotMarkp;
	static unsigned int hw_PrevTopMark2p,hw_PrevBotMark2p;
	static unsigned int hw_PrevTopMark3p,hw_PrevBotMark3p;
	static unsigned int hw_NextTopMarkp,hw_NextBotMarkp;
	static unsigned int hw_NextTopMark2p,hw_NextBotMark2p;
	static unsigned int hw_NextTopMark3p,hw_NextBotMark3p;
	static unsigned int PrevTopLine, PrevBotLine;  	// fw match hw
	static unsigned int PrevTopLine2, PrevBotLine2;   // fw match hw
	static unsigned int PrevTopLine3, PrevBotLine3;   // fw match hw
	static unsigned int NextTopLine, NextBotLine;  	// fw match hw
	static unsigned int NextTopLine2, NextBotLine2;   // fw match hw
	static unsigned int NextTopLine3, NextBotLine3;   // fw match hw

	// parameters for calculate
	static unsigned char ExactMatch321,ExactMatch321_H1,ExactMatch321_H2,ExactMatch321_H3,ExactMatch321_V1,ExactMatch321_V2,ExactMatch321_V3,ExactMatch321_C;
	static unsigned char Violate321,Violate321_H1,Violate321_H2,Violate321_H3,Violate321_V1,Violate321_V2,Violate321_V3,Violate321_C;
	static unsigned char ExactMatch322,ExactMatch322_H1,ExactMatch322_H2,ExactMatch322_H3,ExactMatch322_V1,ExactMatch322_V2,ExactMatch322_V3,ExactMatch322_C;
	static unsigned char Violate322,Violate322_H1,Violate322_H2,Violate322_H3,Violate322_V1,Violate322_V2,Violate322_V3,Violate322_C;
	static unsigned char ExactMatch22,ExactMatch22_H1,ExactMatch22_H2,ExactMatch22_H3,ExactMatch22_V1,ExactMatch22_V2,ExactMatch22_V3,ExactMatch22_C;
	static unsigned char Violate22,Violate22_H1,Violate22_H2,Violate22_H3,Violate22_V1,Violate22_V2,Violate22_V3,Violate22_C;
	static unsigned char Detected_Sub32, Detected_Sub22;
	static unsigned char Detected_Sub32H, Detected_Sub22H;
	static unsigned char Detected_Sub32V, Detected_Sub22V;
	static unsigned int  Sequence_Sub32, Sequence_Sub22;
	static unsigned int  Sequence_Sub32H, Sequence_Sub22H;
	static unsigned int  Sequence_Sub32V, Sequence_Sub22V;
	static unsigned int Detected_Sub32_Num, Detected_Sub22_Num;
	static unsigned int film_index_Sub32,film_index_Sub22;

	// fw results
	static int is_24to25=0;
	static unsigned int fw_TopLine=0x438,fw_BotLine=0x438;
	static unsigned int fw_TopLine2=0x438,fw_BotLine2=0x438;
	static unsigned int fw_TopLine3=0x438,fw_BotLine3=0x438;

	static unsigned int fw_StatusFilmWeaveMode=2,fw_StatusFilmSequence=0;
	static unsigned char fw_Status32Detected1=0,fw_Status32Detected2=0,fw_Status22Detected=0;
	static unsigned char fw_StatusMixedFilmDetected=0,fw_StatusFilmDetected=0,fw_MixedFilmConfuse=0;
	static unsigned char film_Pair_en_auto,film_Pair1_en,film_Violate_strict_en,film_HiFreq_flag,film32_debounce_FieldNum,film22_debounce_FieldNum;
	static unsigned int StatusFilmSequence_tmp = 0;	// considering film double buffer

	// RBUS //
	static di_im_di_control_RBUS im_di_control_reg;
	static di_im_di_film_sawtooth_filmframe_th_RBUS im_di_film_sawtooth_filmframe_th_reg;
	static di_im_di_film_static_sum_th_RBUS im_di_film_static_sum_th_reg;
	static di_im_di_film_motion_sum_th_RBUS im_di_film_motion_sum_th_reg;
	static di_im_di_si_film_final_result_RBUS im_di_si_film_final_result_reg;
	static di_im_di_si_film_pattern_a_RBUS im_di_si_film_pattern_a_reg;
	static di_im_di_si_film_pattern_b_RBUS im_di_si_film_pattern_b_reg;
	static di_im_di_si_film_32_result_1_a_RBUS im_di_si_film_32_result_1_a_reg;
	static di_im_di_si_film_32_result_2_a_RBUS im_di_si_film_32_result_2_a_reg;
	static di_im_di_si_film_22_result_a_RBUS im_di_si_film_22_result_a_reg;
	static di_im_di_si_film22_detector_pattern_RBUS im_di_si_film22_detector_pattern_reg;
	static di_im_di_rtnr_control_RBUS im_di_rtnr_control_reg;

	static di_im_di_film_prev_fieldmotion_RBUS im_di_film_prev_fieldmotion_reg;
	static di_im_di_film_mark_information_RBUS im_di_film_mark_information_reg;
	static di_im_di_film_mark_prev1_RBUS im_di_film_mark_prev1_reg;
	static di_im_di_film_mark_prev2_RBUS im_di_film_mark_prev2_reg;
	static di_im_di_film_mark_prev3_RBUS im_di_film_mark_prev3_reg;
	static di_im_di_film_mark_next1_RBUS im_di_film_mark_next1_reg;
	static di_im_di_film_mark_next2_RBUS im_di_film_mark_next2_reg;
	static di_im_di_film_mark_next3_RBUS im_di_film_mark_next3_reg;
	static di_im_di_film_new_function_main_RBUS im_di_film_new_function_main_reg;	// double buffer use

	// enchance 22 use
	static unsigned char Status22Detected2=0;
	static unsigned int Status22Sequence2=0;
	static unsigned int index22new=0;
	static unsigned int FrameDiff=0xff;

	static unsigned int FW_HFT_thd = 120;//120;//480;  		// racer 120
	static unsigned int FW_HFT_rato_thd = 22;//0.17;//0.17;//0.3;  		// racer 0.17
	static unsigned int FW_HFT_diff_thd = 35;//35;//135;  	// racer 35
	static unsigned int ratioPrevNext = 10;//10;//5;
	static unsigned int PrevDiffMax,NextDiffMax;
	static unsigned int FrameDiff_H1,FrameDiff_H2,FrameDiff_H3,FrameDiff_V1,FrameDiff_V2,FrameDiff_V3,FrameDiff_C;
	static unsigned int PrevDiff,PrevDiff_H1,PrevDiff_H2,PrevDiff_H3,PrevDiff_V1,PrevDiff_V2,PrevDiff_V3,PrevDiff_C;
	static unsigned int NextDiff,NextDiff_H1,NextDiff_H2,NextDiff_H3,NextDiff_V1,NextDiff_V2,NextDiff_V3,NextDiff_C;
	static unsigned int NextDiff_noH3;
	//enchance 22 detection
	static di_im_di_si_film_motion_RBUS im_di_si_film_motion_reg;
	static di_im_di_si_film_motion_h_t_RBUS im_di_si_film_motion_h_t_reg;
	static di_im_di_si_film_motion_h_m_RBUS im_di_si_film_motion_h_m_reg;
	static di_im_di_si_film_motion_h_b_RBUS im_di_si_film_motion_h_b_reg;
	static di_im_di_si_film_motion_v_l_RBUS im_di_si_film_motion_v_l_reg;
	static di_im_di_si_film_motion_v_m_RBUS im_di_si_film_motion_v_m_reg;
	static di_im_di_si_film_motion_v_r_RBUS im_di_si_film_motion_v_r_reg;
	static di_im_di_si_film_motion_c_RBUS im_di_si_film_motion_c_reg;

	static di_im_di_si_film_motion_next_RBUS im_di_si_film_motion_next_reg; //IM_DI_SI_FILM_MOTION_NEXT
	static di_im_di_si_film_motion_next_h_t_RBUS im_di_si_film_motion_next_h_t_reg; //H1
	static di_im_di_si_film_motion_next_h_m_RBUS im_di_si_film_motion_next_h_m_reg; //H2
	static di_im_di_si_film_motion_next_h_b_RBUS im_di_si_film_motion_next_h_b_reg; //H3
	static di_im_di_si_film_motion_next_v_l_RBUS im_di_si_film_motion_next_v_l_reg; //V1
	static di_im_di_si_film_motion_next_v_m_RBUS im_di_si_film_motion_next_v_m_reg; //V2
	static di_im_di_si_film_motion_next_v_r_RBUS im_di_si_film_motion_next_v_r_reg; //V3
	static di_im_di_si_film_motion_next_c_RBUS im_di_si_film_motion_next_c_reg; //C

	static di_im_di_si_film_motion_pre_RBUS im_di_si_film_motion_pre_reg; //IM_DI_SI_FILM_MOTION_PRE
	static di_im_di_si_film_motion_pre_h_t_RBUS im_di_si_film_motion_pre_h_t_reg; //H1
	static di_im_di_si_film_motion_pre_h_m_RBUS im_di_si_film_motion_pre_h_m_reg; //H2
	static di_im_di_si_film_motion_pre_h_b_RBUS im_di_si_film_motion_pre_h_b_reg; //H3
	static di_im_di_si_film_motion_pre_v_l_RBUS im_di_si_film_motion_pre_v_l_reg; //V1
	static di_im_di_si_film_motion_pre_v_m_RBUS im_di_si_film_motion_pre_v_m_reg; //V2
	static di_im_di_si_film_motion_pre_v_r_RBUS im_di_si_film_motion_pre_v_r_reg; //V3
	static di_im_di_si_film_motion_pre_c_RBUS im_di_si_film_motion_pre_c_reg; //C
	static FILM_FWMode DetInformation;

	_clues * SmartPic_clue = fwif_color_GetShare_Memory_SmartPic_clue();

	if (NULL == SmartPic_clue) {
		FILM_FWMode tt;
		memset(&tt, 0, sizeof(tt));
		return tt;
	}

	im_di_si_film_motion_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_reg);
	im_di_si_film_motion_h_t_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_T_reg);
	im_di_si_film_motion_h_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_M_reg);
	im_di_si_film_motion_h_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_H_B_reg);
	im_di_si_film_motion_v_l_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_L_reg);
	im_di_si_film_motion_v_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_M_reg);
	im_di_si_film_motion_v_r_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_V_R_reg);
	im_di_si_film_motion_c_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_C_reg);

	im_di_si_film_motion_next_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_reg);
	im_di_si_film_motion_next_h_t_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_T_reg);
	im_di_si_film_motion_next_h_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_M_reg);
	im_di_si_film_motion_next_h_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_H_B_reg);
	im_di_si_film_motion_next_v_l_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_V_L_reg);
	im_di_si_film_motion_next_v_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_V_M_reg);
	im_di_si_film_motion_next_v_r_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_V_R_reg);
	im_di_si_film_motion_next_c_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_NEXT_C_reg);

	im_di_si_film_motion_pre_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_reg);
	im_di_si_film_motion_pre_h_t_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_T_reg);
	im_di_si_film_motion_pre_h_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_M_reg);
	im_di_si_film_motion_pre_h_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_H_B_reg);
	im_di_si_film_motion_pre_v_l_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_V_L_reg);
	im_di_si_film_motion_pre_v_m_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_V_M_reg);
	im_di_si_film_motion_pre_v_r_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_V_R_reg);
	im_di_si_film_motion_pre_c_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_MOTION_PRE_C_reg);
	//

	im_di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
	im_di_film_sawtooth_filmframe_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg);
	im_di_film_static_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_TH_reg);
	im_di_film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_reg);
	im_di_si_film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_reg);
	im_di_si_film_pattern_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_PATTERN_A_reg);
	im_di_si_film_pattern_b_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_PATTERN_B_reg);
	im_di_si_film_32_result_1_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_32_RESULT_1_A_reg);
	im_di_si_film_32_result_2_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_32_RESULT_2_A_reg);

	im_di_si_film_22_result_a_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_22_RESULT_A_reg);

	im_di_si_film22_detector_pattern_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM22_DETECTOR_PATTERN_reg);
	im_di_rtnr_control_reg.regValue = rtd_inl(DI_IM_DI_RTNR_CONTROL_reg);

	im_di_film_prev_fieldmotion_reg.regValue = rtd_inl(DI_IM_DI_FILM_PREV_FIELDMOTION_reg);
	im_di_film_mark_information_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_INFORMATION_reg);
	im_di_film_mark_prev1_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_PREV1_reg);
	im_di_film_mark_prev2_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_PREV2_reg);
	im_di_film_mark_prev3_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_PREV3_reg);
	im_di_film_mark_next1_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_NEXT1_reg);
	im_di_film_mark_next2_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_NEXT2_reg);
	im_di_film_mark_next3_reg.regValue = rtd_inl(DI_IM_DI_FILM_MARK_NEXT3_reg);

	im_di_film_new_function_main_reg.regValue = rtd_inl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);

	{
		enchance22_en = 0;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x01);
		film3223_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x02)>>1;
		film64_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x04)>>2;
		film55_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x08)>>3;
		film2224_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x10)>>4;
		film32322_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x20)>>5;
		film87_en = 1;//(im_di_film_motion_sum_th_reg.dummy180240b4_23_16 & 0x40)>>6;
		filmQuick_en = (im_di_si_film_final_result_reg.regValue&0x8000)?1:0;
		framestaticonly = (im_di_si_film_final_result_reg.regValue&0x4000)?1:0;

	}

	hw_AdoptHDMethod = im_di_control_reg.ma_3aenable;
	hw_film_Enable = (im_di_control_reg.film_enable & 0x10)>>4;
	hw_film_32Film = ((im_di_control_reg.film_enable & 0x8)>>3) + ((im_di_control_reg.film_enable & 0x2)>>1);
	hw_film_22Film = ((im_di_control_reg.film_enable & 0x4)>>2) + (im_di_control_reg.film_enable & 0x1);
	hw_film_VerScrollingText_en=im_di_film_sawtooth_filmframe_th_reg.film_verscrollingtext_en;
	hw_film_thumbnail_en=im_di_film_sawtooth_filmframe_th_reg.film_thumbnail_en;
	film_Pair_en_auto=im_di_film_sawtooth_filmframe_th_reg.film_pair_en_auto; // 0
	film_Pair1_en = im_di_film_sawtooth_filmframe_th_reg.film_pair1_en; // 1
	film_Violate_strict_en = im_di_film_sawtooth_filmframe_th_reg.film_violate_strict_en; // 1
	hw_FieldStaticSumThl = im_di_film_static_sum_th_reg.film22_fistaticsthl;
	hw_FieldMotionSumThl = im_di_film_motion_sum_th_reg.film22_fieldmotionsumthl;
	film32_debounce_FieldNum = im_di_film_motion_sum_th_reg.film32_debounce_fieldnum;
	film22_debounce_FieldNum = im_di_film_motion_sum_th_reg.film22_debounce_fieldnum;

	hw_film_StatusFilmDetected = im_di_si_film_final_result_reg.film_detected;
	hw_film_StatusMixedFilmDetected = im_di_si_film_final_result_reg.film_subdetected;
	hw_film_StatusFilmSequence = im_di_si_film_final_result_reg.film_sequence;
	hw_film_MixedFilmConfuse = im_di_si_film_final_result_reg.film_confuse;
	film_HiFreq_flag = im_di_si_film_final_result_reg.film_hifreq_flag;
	hw_StatusFrameStaticPattern_All = im_di_si_film_pattern_a_reg.film_framestatic;
	hw_StatusFramePairPattern_All = im_di_si_film_pattern_a_reg.film_framepair;
	hw_StatusPrevStaticPattern_All = im_di_si_film_pattern_a_reg.film_prefistatic1;
	hw_StatusNextStaticPattern_All = im_di_si_film_pattern_b_reg.film_nxtfistatic1;
	hw_StatusPrevStaticPattern2_All = im_di_si_film_pattern_b_reg.film_prefistatic2;
	hw_StatusNextStaticPattern2_All = im_di_si_film_pattern_b_reg.film_nxtfistatic2;
	hw_StatusNextFieldMotion_All = im_di_si_film_pattern_b_reg.film_nxtfimotion;
	hw_film_Status32Detected1 = (im_di_si_film_32_result_1_a_reg.film_detected321 & 0x80)>>7;
	hw_film_Status32Detected2 = (im_di_si_film_32_result_2_a_reg.film_detected322 & 0x80)>>7;
	hw_film_Status22Detected = (im_di_si_film_22_result_a_reg.film_detected22 & 0x80)>>7;
	hw_StatusNextFieldMotion_film22_All = im_di_si_film22_detector_pattern_reg.film22_nxtfimotion;
	hw_StatusNextStaticPattern_film22_All = im_di_si_film22_detector_pattern_reg.film22_nxtfistatic1;
	hw_RTNR_Interlace_Force2D_En = im_di_rtnr_control_reg.cp_rtnr_interlace_force2d_en;

	hw_StatusPrevFieldMotion_All = im_di_film_prev_fieldmotion_reg.film_prevfilmmotion;
	hw_StatusPrevFieldMotion_film22_All = im_di_film_prev_fieldmotion_reg.film22_prevfilmmotion;
	hw_film_BadEditor_flag = im_di_film_prev_fieldmotion_reg.film_badeditor_flag;
	NextTopDetected = im_di_film_mark_information_reg.film_nexttopdetected1;
	PrevTopDetected = im_di_film_mark_information_reg.film_prevtopdetected1;

	fw_DI_3A = hw_AdoptHDMethod || hw_RTNR_Interlace_Force2D_En;

	//scalerVIP_film_FWmode_3D_start();

	StatusFrameStaticPattern = (StatusFrameStaticPattern<<1) + ((hw_StatusFrameStaticPattern_All & 0x80)>>7);
	StatusFrameStaticPattern_H1 = (StatusFrameStaticPattern_H1<<1) + ((hw_StatusFrameStaticPattern_All & 0x40)>>6);
	StatusFrameStaticPattern_H2 = (StatusFrameStaticPattern_H2<<1) + ((hw_StatusFrameStaticPattern_All & 0x20)>>5);
	StatusFrameStaticPattern_H3 = (StatusFrameStaticPattern_H3<<1) + ((hw_StatusFrameStaticPattern_All & 0x10)>>4);
	StatusFrameStaticPattern_V1 = (StatusFrameStaticPattern_V1<<1) + ((hw_StatusFrameStaticPattern_All & 0x08)>>3);
	StatusFrameStaticPattern_V2 = (StatusFrameStaticPattern_V2<<1) + ((hw_StatusFrameStaticPattern_All & 0x04)>>2);
	StatusFrameStaticPattern_V3 = (StatusFrameStaticPattern_V3<<1) + ((hw_StatusFrameStaticPattern_All & 0x02)>>1);
	StatusFrameStaticPattern_C = (StatusFrameStaticPattern_C<<1) + ((hw_StatusFrameStaticPattern_All & 0x01));

	StatusFramePairPattern = ( StatusFramePairPattern<<2 ) + ( (hw_StatusFramePairPattern_All & 0xc000)>>14);
	StatusFramePairPattern_H1 = ( StatusFramePairPattern_H1<<2 ) + ( (hw_StatusFramePairPattern_All & 0x3000)>>12);
	StatusFramePairPattern_H2 = ( StatusFramePairPattern_H2<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0c00)>>10);
	StatusFramePairPattern_H3 = ( StatusFramePairPattern_H3<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0300)>>8);
	StatusFramePairPattern_V1 = ( StatusFramePairPattern_V1<<2 ) + ( (hw_StatusFramePairPattern_All & 0x00c0)>>6);
	StatusFramePairPattern_V2 = ( StatusFramePairPattern_V2<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0030)>>4);
	StatusFramePairPattern_V3 = ( StatusFramePairPattern_V3<<2 ) + ( (hw_StatusFramePairPattern_All & 0x000c)>>2);
	StatusFramePairPattern_C = ( StatusFramePairPattern_C<<2 ) + ( (hw_StatusFramePairPattern_All & 0x0003));

	StatusPrevStaticPattern = ( StatusPrevStaticPattern<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x80)>>7);
	StatusPrevStaticPattern_H1 = ( StatusPrevStaticPattern_H1<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x40)>>6);
	StatusPrevStaticPattern_H2 = ( StatusPrevStaticPattern_H2<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x20)>>5);
	StatusPrevStaticPattern_H3 = ( StatusPrevStaticPattern_H3<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x10)>>4);
	StatusPrevStaticPattern_V1 = ( StatusPrevStaticPattern_V1<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x08)>>3);
	StatusPrevStaticPattern_V2 = ( StatusPrevStaticPattern_V2<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x04)>>2);
	StatusPrevStaticPattern_V3 = ( StatusPrevStaticPattern_V3<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x02)>>1);
	StatusPrevStaticPattern_C = ( StatusPrevStaticPattern_C<<1 ) + ( (hw_StatusPrevStaticPattern_All & 0x01));

	StatusNextStaticPattern = ( StatusNextStaticPattern<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x80)>>7);
	StatusNextStaticPattern_H1 = ( StatusNextStaticPattern_H1<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x40)>>6);
	StatusNextStaticPattern_H2 = ( StatusNextStaticPattern_H2<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x20)>>5);
	StatusNextStaticPattern_H3 = ( StatusNextStaticPattern_H3<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x10)>>4);
	StatusNextStaticPattern_V1 = ( StatusNextStaticPattern_V1<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x08)>>3);
	StatusNextStaticPattern_V2 = ( StatusNextStaticPattern_V2<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x04)>>2);
	StatusNextStaticPattern_V3 = ( StatusNextStaticPattern_V3<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x02)>>1);
	StatusNextStaticPattern_C = ( StatusNextStaticPattern_C<<1 ) + ( (hw_StatusNextStaticPattern_All & 0x01));

	StatusPrevStaticPattern2 = ( StatusPrevStaticPattern2<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x80)>>7);
	StatusPrevStaticPattern2_H1 = ( StatusPrevStaticPattern2_H1<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x40)>>6);
	StatusPrevStaticPattern2_H2 = ( StatusPrevStaticPattern2_H2<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x20)>>5);
	StatusPrevStaticPattern2_H3 = ( StatusPrevStaticPattern2_H3<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x10)>>4);
	StatusPrevStaticPattern2_V1 = ( StatusPrevStaticPattern2_V1<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x08)>>3);
	StatusPrevStaticPattern2_V2 = ( StatusPrevStaticPattern2_V2<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x04)>>2);
	StatusPrevStaticPattern2_V3 = ( StatusPrevStaticPattern2_V3<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x02)>>1);
	StatusPrevStaticPattern2_C = ( StatusPrevStaticPattern2_C<<1 ) + ( (hw_StatusPrevStaticPattern2_All & 0x01));

	StatusNextStaticPattern2 = ( StatusNextStaticPattern2<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x80)>>7);
	StatusNextStaticPattern2_H1 = ( StatusNextStaticPattern2_H1<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x40)>>6);
	StatusNextStaticPattern2_H2 = ( StatusNextStaticPattern2_H2<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x20)>>5);
	StatusNextStaticPattern2_H3 = ( StatusNextStaticPattern2_H3<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x10)>>4);
	StatusNextStaticPattern2_V1 = ( StatusNextStaticPattern2_V1<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x08)>>3);
	StatusNextStaticPattern2_V2 = ( StatusNextStaticPattern2_V2<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x04)>>2);
	StatusNextStaticPattern2_V3 = ( StatusNextStaticPattern2_V3<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x02)>>1);
	StatusNextStaticPattern2_C = ( StatusNextStaticPattern2_C<<1 ) + ( (hw_StatusNextStaticPattern2_All & 0x01));

	// Pattern Recognization
	fw_di_film_sawtooth_comparePrevNext=0;
	
	if(is_24to25>0)
	{
		if(StatusFrameStaticPattern&1)
		{
			is_24to25=0;
			filmQuick_en = (im_di_si_film_final_result_reg.regValue&0x8000)?1:0;
		}
		else
		if(is_24to25>25)
		{
			is_24to25=0;
			filmQuick_en = (im_di_si_film_final_result_reg.regValue&0x8000)?1:0;
		}
		else
		{
			is_24to25=is_24to25-1;
			filmQuick_en = 1;
		}
	}
	if((StatusFrameStaticPattern&0x02000001)==0x02000001&&(((StatusFrameStaticPattern&0x1555554)>>1)==(StatusFrameStaticPattern&0xaaaaaa)))
	{
		is_24to25=99;
		filmQuick_en = 1;
	}

	if(DynamicOptimizeSystem[175]==1)
		rpt_di_film_spear2_hifreq =1;
	else
		rpt_di_film_spear2_hifreq =0;
	if(rpt_di_film_spear2_hifreq){
		enchance22_en=0;
		fw_di_film_sawtooth_comparePrevNext=1;
	}

	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern, StatusFramePairPattern,
						StatusPrevStaticPattern2, StatusNextStaticPattern2, 1,
						&ExactMatch321, &Violate321,&index32,&stillpix_count32,
						&Status32Detected1, &Status32Sequence1,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern_H1, StatusFramePairPattern_H1,
						StatusPrevStaticPattern_H1, StatusNextStaticPattern_H1, 1,
						&ExactMatch321_H1, &Violate321_H1,&index32_H1,&stillpix_count32_H1,
						&Status32Detected1_H1, &Status32Sequence1_H1,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern_H2, StatusFramePairPattern_H2,
						StatusPrevStaticPattern_H2, StatusNextStaticPattern_H2, 1,
						&ExactMatch321_H2, &Violate321_H2,&index32_H2,&stillpix_count32_H2,
						&Status32Detected1_H2, &Status32Sequence1_H2,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern_H3, StatusFramePairPattern_H3,
						StatusPrevStaticPattern_H3, StatusNextStaticPattern_H3, 1,
						&ExactMatch321_H3, &Violate321_H3,&index32_H3,&stillpix_count32_H3,
						&Status32Detected1_H3, &Status32Sequence1_H3,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern_V1, StatusFramePairPattern_V1,
						StatusPrevStaticPattern_V1, StatusNextStaticPattern_V1, 1,
						&ExactMatch321_V1, &Violate321_V1,&index32_V1,&stillpix_count32_V1,
						&Status32Detected1_V1, &Status32Sequence1_V1,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern_V2, StatusFramePairPattern_V2,
						StatusPrevStaticPattern_V2, StatusNextStaticPattern_V2, 1,
						&ExactMatch321_V2, &Violate321_V2,&index32_V2,&stillpix_count32_V2,
						&Status32Detected1_V2, &Status32Sequence1_V2,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern_V3, StatusFramePairPattern_V3,
						StatusPrevStaticPattern_V3, StatusNextStaticPattern_V3, 1,
						&ExactMatch321_V3, &Violate321_V3,&index32_V3,&stillpix_count32_V3,
						&Status32Detected1_V3, &Status32Sequence1_V3,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection1(StatusFrameStaticPattern_C, StatusFramePairPattern_C,
						StatusPrevStaticPattern_C, StatusNextStaticPattern_C, 1,
						&ExactMatch321_C, &Violate321_C,&index32_C,&stillpix_count32_C,
						&Status32Detected1_C, &Status32Sequence1_C,film_Pair_en_auto,
						film_Pair1_en,film_HiFreq_flag,film_Violate_strict_en);

	// detection 2
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern, 1,StatusFrameStaticPattern ,
						(hw_StatusPrevFieldMotion_All & 0x80)>>7, (hw_StatusNextFieldMotion_All & 0x80)>>7,
						&ExactMatch322, &Violate322,&index322,&Status32Detected2, &Status32Sequence2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern_H1, 1,StatusFrameStaticPattern_H1,
						(hw_StatusPrevFieldMotion_All & 0x40)>>6, (hw_StatusNextFieldMotion_All & 0x40)>>6,
						&ExactMatch322_H1, &Violate322_H1,&index322_H1,&Status32Detected2_H1, &Status32Sequence2_H1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern_H2, 1,StatusFrameStaticPattern_H2,
						(hw_StatusPrevFieldMotion_All & 0x20)>>5, (hw_StatusNextFieldMotion_All & 0x20)>>5,
						&ExactMatch322_H2, &Violate322_H2, &index322_H2,&Status32Detected2_H2, &Status32Sequence2_H2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern_H3, 1,StatusFrameStaticPattern_H3,
						(hw_StatusPrevFieldMotion_All & 0x10)>>4, (hw_StatusNextFieldMotion_All & 0x10)>>4,
						&ExactMatch322_H3, &Violate322_H3,&index322_H3,&Status32Detected2_H3, &Status32Sequence2_H3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern_V1, 1,StatusFrameStaticPattern_V1,
						(hw_StatusPrevFieldMotion_All & 0x08)>>3, (hw_StatusNextFieldMotion_All & 0x08)>>3,
						&ExactMatch322_V1, &Violate322_V1,&index322_V1,&Status32Detected2_V1, &Status32Sequence2_V1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern_V2, 1,StatusFrameStaticPattern_V2,
						(hw_StatusPrevFieldMotion_All & 0x04)>>2, (hw_StatusNextFieldMotion_All & 0x04)>>2,
						&ExactMatch322_V2, &Violate322_V2,&index322_V2,&Status32Detected2_V2, &Status32Sequence2_V2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern_V3, 1,StatusFrameStaticPattern_V3,
						(hw_StatusPrevFieldMotion_All & 0x02)>>1, (hw_StatusNextFieldMotion_All & 0x02)>>1,
						&ExactMatch322_V3, &Violate322_V3,&index322_V3,&Status32Detected2_V3, &Status32Sequence2_V3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection2(StatusNextStaticPattern_C, 1,StatusFrameStaticPattern_C,
						(hw_StatusPrevFieldMotion_All & 0x01), (hw_StatusNextFieldMotion_All & 0x01),
						&ExactMatch322_C, &Violate322_C,&index322_C,&Status32Detected2_C, &Status32Sequence2_C,film_Violate_strict_en);

	//debounce for film32 flag, flora add (Darwin)////////////////////////////////////////////
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1,&Status32Detected1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2,&Status32Detected2_cnt,film32_debounce_FieldNum);

	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_H1,&Status32Detected1_H1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_H2,&Status32Detected1_H2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_H3,&Status32Detected1_H3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_V1,&Status32Detected1_V1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_V2,&Status32Detected1_V2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_V3,&Status32Detected1_V3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected1_C ,&Status32Detected1_C_cnt,film32_debounce_FieldNum );

	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_H1,&Status32Detected2_H1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_H2,&Status32Detected2_H2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_H3,&Status32Detected2_H3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_V1,&Status32Detected2_V1_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_V2,&Status32Detected2_V2_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_V3,&Status32Detected2_V3_cnt,film32_debounce_FieldNum);
	scalerVIP_film_FWmode_film32_debounce(&Status32Detected2_C ,&Status32Detected2_C_cnt,film32_debounce_FieldNum );
	//end of decounce//////////////////////////////////////////////////////////////////////////
	FrameDiff = im_di_si_film_motion_reg.film_motionstatus_399_380;
	FrameDiff_H1 = im_di_si_film_motion_h_t_reg.film_motionstatus_379_360;
	FrameDiff_H2 = im_di_si_film_motion_h_m_reg.film_motionstatus_359_340;
	FrameDiff_H3 = im_di_si_film_motion_h_b_reg.film_motionstatus_339_320;
	FrameDiff_V1 = im_di_si_film_motion_v_l_reg.film_motionstatus_319_300;
	FrameDiff_V2 = im_di_si_film_motion_v_m_reg.film_motionstatus_299_280;
	FrameDiff_V3 = im_di_si_film_motion_v_r_reg.film_motionstatus_279_260;
	FrameDiff_C = im_di_si_film_motion_c_reg.film_motionstatus_259_240;

	PrevDiff = im_di_si_film_motion_pre_reg.film_motionstatus_559_540;
	PrevDiff_H1 = im_di_si_film_motion_pre_h_t_reg.film_motionstatus_539_520;
	PrevDiff_H2 = im_di_si_film_motion_pre_h_m_reg.film_motionstatus_519_500;
	PrevDiff_H3 = im_di_si_film_motion_pre_h_b_reg.film_motionstatus_499_480;
	PrevDiff_V1 = im_di_si_film_motion_pre_v_l_reg.film_motionstatus_479_460;
	PrevDiff_V2 = im_di_si_film_motion_pre_v_m_reg.film_motionstatus_459_440;
	PrevDiff_V3 = im_di_si_film_motion_pre_v_r_reg.film_motionstatus_439_420;
	PrevDiff_C = im_di_si_film_motion_pre_c_reg.film_motionstatus_419_400;

	NextDiff = im_di_si_film_motion_next_reg.film_motionstatus_719_700;
	NextDiff_H1 = im_di_si_film_motion_next_h_t_reg.film_motionstatus_699_680;
	NextDiff_H2 = im_di_si_film_motion_next_h_m_reg.film_motionstatus_679_660;
	NextDiff_H3 = im_di_si_film_motion_next_h_b_reg.film_motionstatus_659_640;
	NextDiff_V1 = im_di_si_film_motion_next_v_l_reg.film_motionstatus_639_620;
	NextDiff_V2 = im_di_si_film_motion_next_v_m_reg.film_motionstatus_619_600;
	NextDiff_V3 = im_di_si_film_motion_next_v_r_reg.film_motionstatus_599_580;
	NextDiff_C = im_di_si_film_motion_next_c_reg.film_motionstatus_579_560;
	p22_StatusPrevDiffSum[0]=&PrevDiff;
	p22_StatusPrevDiffSum[1]=&PrevDiff_H1;
	p22_StatusPrevDiffSum[2]=&PrevDiff_H2;
	p22_StatusPrevDiffSum[3]=&PrevDiff_H3;
	p22_StatusPrevDiffSum[4]=&PrevDiff_V1;
	p22_StatusPrevDiffSum[5]=&PrevDiff_V2;
	p22_StatusPrevDiffSum[6]=&PrevDiff_V3;
	p22_StatusPrevDiffSum[7]=&PrevDiff_C;
	p22_StatusNextDiffSum[0]=&NextDiff;
	p22_StatusNextDiffSum[1]=&NextDiff_H1;
	p22_StatusNextDiffSum[2]=&NextDiff_H2;
	p22_StatusNextDiffSum[3]=&NextDiff_H3;
	p22_StatusNextDiffSum[4]=&NextDiff_V1;
	p22_StatusNextDiffSum[5]=&NextDiff_V2;
	p22_StatusNextDiffSum[6]=&NextDiff_V3;
	p22_StatusNextDiffSum[7]=&NextDiff_C;
	StatusNextStaticPattern_film22_PTR[0]=&StatusNextStaticPattern_film22;
	StatusNextStaticPattern_film22_PTR[1]=&StatusNextStaticPattern_film22_H1;
	StatusNextStaticPattern_film22_PTR[2]=&StatusNextStaticPattern_film22_H2;
	StatusNextStaticPattern_film22_PTR[3]=&StatusNextStaticPattern_film22_H3;
	StatusNextStaticPattern_film22_PTR[4]=&StatusNextStaticPattern_film22_V1;
	StatusNextStaticPattern_film22_PTR[5]=&StatusNextStaticPattern_film22_V2;
	StatusNextStaticPattern_film22_PTR[6]=&StatusNextStaticPattern_film22_V3;
	StatusNextStaticPattern_film22_PTR[7]=&StatusNextStaticPattern_film22_C;
	if(fw_di_film_sawtooth_comparePrevNext){
		int i,j,k;
		int reg_vc_di_film22_observe_many_frames=0;// tunable, 0~3
		hw_StatusPrevFieldMotion_film22_All=0;
		hw_StatusNextFieldMotion_film22_All=0;
		for(i=0;i<8;i++){// region number
			for(j=(1<<reg_vc_di_film22_observe_many_frames);j<8;j++){
                A22_StatusPrevDiffSum[i][j]=0;
                A22_StatusNextDiffSum[i][j]=0;
			}
			for(j=(1<<reg_vc_di_film22_observe_many_frames)-1;j>0;j--){
                A22_StatusPrevDiffSum[i][j]=A22_StatusPrevDiffSum[i][j-1];
                A22_StatusNextDiffSum[i][j]=A22_StatusNextDiffSum[i][j-1];
			}
			A22_StatusPrevDiffSum[i][0]=vc_di_film_getDiffSumRemap(p22_StatusPrevDiffSum[i][0]);
			A22_StatusNextDiffSum[i][0]=vc_di_film_getDiffSumRemap(p22_StatusNextDiffSum[i][0]);
			k=(1<<reg_vc_di_film22_observe_many_frames)>>1;
			for(j=0;j<8;j+=2){
				k+=A22_StatusNextDiffSum[i][j]-A22_StatusPrevDiffSum[i][j]
				-A22_StatusNextDiffSum[i][j|1]+A22_StatusPrevDiffSum[i][j|1];
			}
			k=k>>reg_vc_di_film22_observe_many_frames;

			p22_StatusPrevDiffSum[i][0]=128-k;
			p22_StatusNextDiffSum[i][0]=128+k;
			hw_StatusPrevFieldMotion_film22_All=hw_StatusPrevFieldMotion_film22_All| (p22_StatusPrevDiffSum[i][0] > (i?0x90:0xa0) ? 1<<(7^i) : 0);
			StatusNextStaticPattern_film22_PTR[i][0] = (StatusNextStaticPattern_film22_PTR[i][0]<<1)|(p22_StatusNextDiffSum[i][0] < (i?0x90:0xa0) ? 1 : 0);
			hw_StatusNextFieldMotion_film22_All=hw_StatusNextFieldMotion_film22_All| (p22_StatusNextDiffSum[i][0] > (i?0x90:0xa0) ? 1<<(7^i) : 0);
		}
	}else{
		// detection 22
		StatusNextStaticPattern_film22 = ( StatusNextStaticPattern_film22<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x80)>>7);
		StatusNextStaticPattern_film22_H1 = ( StatusNextStaticPattern_film22_H1<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x40)>>6);
		StatusNextStaticPattern_film22_H2 = ( StatusNextStaticPattern_film22_H2<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x20)>>5);
		StatusNextStaticPattern_film22_H3 = ( StatusNextStaticPattern_film22_H3<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x10)>>4);
		StatusNextStaticPattern_film22_V1 = ( StatusNextStaticPattern_film22_V1<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x08)>>3);
		StatusNextStaticPattern_film22_V2 = ( StatusNextStaticPattern_film22_V2<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x04)>>2);
		StatusNextStaticPattern_film22_V3 = ( StatusNextStaticPattern_film22_V3<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x02)>>1);
		StatusNextStaticPattern_film22_C = ( StatusNextStaticPattern_film22_C<<1 ) + ( (hw_StatusNextStaticPattern_film22_All & 0x01));
	}

	if(FrameDiff>(PrevDiff<<7)&&FrameDiff>(NextDiff<<7)){
		StatusNextStaticPattern_film22&=-2;
		hw_StatusPrevFieldMotion_film22_All|=0x80;
		hw_StatusNextFieldMotion_film22_All|=0x80;
	}else if(PrevDiff>NextDiff*48){
		StatusNextStaticPattern_film22=(StatusNextStaticPattern_film22&-4)|1;
		hw_StatusPrevFieldMotion_film22_All&=-129;
		hw_StatusNextFieldMotion_film22_All|=0x80;
	}else if(PrevDiff*48<NextDiff){
		StatusNextStaticPattern_film22=(StatusNextStaticPattern_film22&-4)|2;
		hw_StatusPrevFieldMotion_film22_All|=0x80;
		hw_StatusNextFieldMotion_film22_All&=-129;
	}
	{
		int i=0;
		int j=0;
		for(j=7;j>0;j--){
			A22_StatusFrameDiffSum[i][j]=A22_StatusFrameDiffSum[i][j-1];
		}
		A22_StatusFrameDiffSum[i][0]=FrameDiff;
		/*
		if(StatusFrameStaticPattern&1)
		{
			int FrameDiffSumSum=FrameDiff;
			for(j=7;j>0;j--){
				FrameDiffSumSum=FrameDiffSumSum+A22_StatusFrameDiffSum[i][j];
			}
			if((FrameDiff+1)*8<FrameDiffSumSum)
			{
				StatusNextStaticPattern_film22=StatusNextStaticPattern_film22>>1;
				StatusNextStaticPattern_film22_H1=StatusNextStaticPattern_film22_H1>>1;
				StatusNextStaticPattern_film22_H2=StatusNextStaticPattern_film22_H2>>1;
				StatusNextStaticPattern_film22_H3=StatusNextStaticPattern_film22_H3>>1;
				StatusNextStaticPattern_film22_V1=StatusNextStaticPattern_film22_V1>>1;
				StatusNextStaticPattern_film22_V2=StatusNextStaticPattern_film22_V2>>1;
				StatusNextStaticPattern_film22_V3=StatusNextStaticPattern_film22_V3>>1;
				StatusNextStaticPattern_film22_C=StatusNextStaticPattern_film22_C>>1;
				hw_StatusPrevFieldMotion_film22_All=0;
				hw_StatusNextFieldMotion_film22_All=0;
			}
		}
		//*/
	}
	if(im_di_si_film_final_result_reg.regValue&0x400){


		rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_disconfort]frame=%d prev=%d next=%d[/fw_film_disconfort]\t"
			,FrameDiff
			,PrevDiff
			,NextDiff
		);
	}

	if(!filmQuick_en){
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22, scalerVIP_film_FWmode_22all_suspect32(StatusFrameStaticPattern),
						((hw_StatusPrevFieldMotion_film22_All & 0x80)>>7), ((hw_StatusNextFieldMotion_film22_All & 0x80)>>7),
						&ExactMatch22, &Violate22,&index22, &stillpix_count22,
						&Status22Detected, &Status22Sequence,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22_H1, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x40)>>6), ((hw_StatusNextFieldMotion_film22_All & 0x40)>>6),
						&ExactMatch22_H1, &Violate22_H1,&index22_H1, &stillpix_count22_H1,
						&Status22Detected_H1, &Status22Sequence_H1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22_H2, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x20)>>5), ((hw_StatusNextFieldMotion_film22_All & 0x20)>>5),
						&ExactMatch22_H2, &Violate22_H2,&index22_H2, &stillpix_count22_H2,
						&Status22Detected_H2, &Status22Sequence_H2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22_H3, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x10)>>4), ((hw_StatusNextFieldMotion_film22_All & 0x10)>>4),
						&ExactMatch22_H3, &Violate22_H3,&index22_H3, &stillpix_count22_H3,
						&Status22Detected_H3, &Status22Sequence_H3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22_V1, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x08)>>3), ((hw_StatusNextFieldMotion_film22_All & 0x08)>>3),
						&ExactMatch22_V1, &Violate22_V1,&index22_V1, &stillpix_count22_V1,
						&Status22Detected_V1, &Status22Sequence_V1,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22_V2, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x04)>>2), ((hw_StatusNextFieldMotion_film22_All & 0x04)>>2),
						&ExactMatch22_V2, &Violate22_V2,&index22_V2, &stillpix_count22_V2,
						&Status22Detected_V2, &Status22Sequence_V2,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22_V3, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x02)>>1), ((hw_StatusNextFieldMotion_film22_All & 0x02)>>1),
						&ExactMatch22_V3, &Violate22_V3,&index22_V3, &stillpix_count22_V3,
						&Status22Detected_V3, &Status22Sequence_V3,film_Violate_strict_en);
	scalerVIP_film_FWmode_detection22(StatusNextStaticPattern_film22_C, 1,
						((hw_StatusPrevFieldMotion_film22_All & 0x01)), ((hw_StatusNextFieldMotion_film22_All & 0x01)),
						&ExactMatch22_C, &Violate22_C,&index22_C, &stillpix_count22_C,
						&Status22Detected_C, &Status22Sequence_C,film_Violate_strict_en);
	}

	if(enchance22_en)
	{
		PrevDiffMax = MAX(MAX(PrevDiff_H1,PrevDiff_H2),PrevDiff_H3);
		PrevDiffMax = MAX(PrevDiffMax,MAX(MAX(PrevDiff_V1,PrevDiff_V2),PrevDiff_V3));
		NextDiffMax = MAX(MAX(NextDiff_H1,NextDiff_H2),NextDiff_H3);
		NextDiffMax = MAX(NextDiffMax,MAX(MAX(NextDiff_V1,NextDiff_V2),NextDiff_V3));

		// enachance 22
		// 1. - detect high freq term exists
		if(HFT_prev==1 && (FW_HFT<FW_HFT_thd) && (FrameDiff>700)
			&& (((abs(PrevDiff-FW_HFT)<((FW_HFT_rato_thd*FW_HFT)>>7)) || (abs(PrevDiff-FW_HFT)< FW_HFT_diff_thd)) ||
			(NextDiff > 20000)) // scene change
		)
		{
			FW_HFT = PrevDiff;
			FW_StatusNextHighFreqTerm = (FW_StatusNextHighFreqTerm<<1) + 1;
			HFT_prev = 0;
		}
		else if(HFT_prev==0 && (FW_HFT<FW_HFT_thd) && (FrameDiff>700)
 		&& (((abs(NextDiff-FW_HFT)<((FW_HFT_rato_thd*FW_HFT)>>7)) || (abs(NextDiff-FW_HFT)< FW_HFT_diff_thd))||
 			(PrevDiff > 20000)) // scene change
 		)
		{
			FW_HFT = NextDiff;
			FW_StatusNextHighFreqTerm = (FW_StatusNextHighFreqTerm<<1) + 1;
			HFT_prev = 1;
		}
		else
		{
			FW_HFT = NextDiff;
			FW_StatusNextHighFreqTerm = (FW_StatusNextHighFreqTerm<<1);
			HFT_prev = 1;
		}

		// 2. - use pair to do detection
		if(HFT_prev==0 && ((FW_StatusNextHighFreqTerm&0xf)==0xf) && (PrevDiff * ratioPrevNext < NextDiff))// && (PrevDiff*1.6 < FrameDiff))
		{
			FW_StatusNextStaticPattern2_film22 = (FW_StatusNextStaticPattern2_film22<<1);
		}
		else if(HFT_prev==1 && ((FW_StatusNextHighFreqTerm&0xf)==0xf) && (NextDiff* ratioPrevNext < PrevDiff))// && (NextDiff*1.6 < FrameDiff))
		{
			FW_StatusNextStaticPattern2_film22 = (FW_StatusNextStaticPattern2_film22<<1) + 1;
		}
		else
		{
			FW_StatusNextStaticPattern2_film22 = (FW_StatusNextStaticPattern2_film22<<1);
		}

		scalerVIP_film_FWmode_detection22new(FW_StatusNextStaticPattern2_film22,1,
		((hw_StatusPrevFieldMotion_film22_All & 0x80)>>7), ((hw_StatusNextFieldMotion_film22_All & 0x80)>>7),
		&ExactMatch22, &Violate22,&index22new, &stillpix_count22,&Status22Detected2, &Status22Sequence2);

		if(!Status22Detected && Status22Detected2 && FrameDiff>300) 	// if motion is large enough
		{
			Status22Detected = Status22Detected2;
			Status22Sequence = Status22Sequence2;
			index22 = index22new;
		}

		// FW_Status22Sequence = 1 -> next
		// FW_Status22Sequence = 2 -> prev

/* // Marked due to still scene with high frequency contents will go intra path
		if(Status22Detected && ((FrameDiff<100) ||
			(Status22Sequence == 1 && (PrevDiff*5 < FrameDiff))||(Status22Sequence == 2 && (NextDiff*5 < FrameDiff)))
		)
		{
			Status22Detected = 0;
			index22 = 0;
		}
*/
	}

	//debounce for film22 flag, flora add (Darwin)////////////////////////////////////////////
	if(!filmQuick_en){
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected,&Status22Detected_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_H1,&Status22Detected_H1_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_H2,&Status22Detected_H2_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_H3,&Status22Detected_H3_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_V1,&Status22Detected_V1_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_V2,&Status22Detected_V2_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_V3,&Status22Detected_V3_cnt,film22_debounce_FieldNum);
	scalerVIP_film_FWmode_film22_debounce(&Status22Detected_C ,&Status22Detected_C_cnt ,film22_debounce_FieldNum);
	}
	//end of debounce//////////////////////////////////////////////////////////////////////////
	if(filmQuick_en){
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_H1, StatusFramePairPattern_H1,
			StatusNextStaticPattern_H1,StatusNextStaticPattern_film22_H1,
			&ExactMatch321_H1, &Violate321_H1,&index32_H1,
			&Status32Detected1_H1, &Status32Sequence1_H1,
			&ExactMatch322_H1, &Violate322_H1,&index322_H1,
			&Status32Detected2_H1, &Status32Sequence2_H1,
			&ExactMatch22_H1, &Violate22_H1,&index22_H1,
			&Status22Detected_H1, &Status22Sequence_H1
		);
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_H2, StatusFramePairPattern_H2,
			StatusNextStaticPattern_H2,StatusNextStaticPattern_film22_H2,
			&ExactMatch321_H2, &Violate321_H2,&index32_H2,
			&Status32Detected1_H2, &Status32Sequence1_H2,
			&ExactMatch322_H2, &Violate322_H2,&index322_H2,
			&Status32Detected2_H2, &Status32Sequence2_H2,
			&ExactMatch22_H2, &Violate22_H2,&index22_H2,
			&Status22Detected_H2, &Status22Sequence_H2
		);
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_H3, StatusFramePairPattern_H3,
			StatusNextStaticPattern_H3,StatusNextStaticPattern_film22_H3,
			&ExactMatch321_H3, &Violate321_H3,&index32_H3,
			&Status32Detected1_H3, &Status32Sequence1_H3,
			&ExactMatch322_H3, &Violate322_H3,&index322_H3,
			&Status32Detected2_H3, &Status32Sequence2_H3,
			&ExactMatch22_H3, &Violate22_H3,&index22_H3,
			&Status22Detected_H3, &Status22Sequence_H3
		);
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_V1, StatusFramePairPattern_V1,
			StatusNextStaticPattern_V1,StatusNextStaticPattern_film22_V1,
			&ExactMatch321_V1, &Violate321_V1,&index32_V1,
			&Status32Detected1_V1, &Status32Sequence1_V1,
			&ExactMatch322_V1, &Violate322_V1,&index322_V1,
			&Status32Detected2_V1, &Status32Sequence2_V1,
			&ExactMatch22_V1, &Violate22_V1,&index22_V1,
			&Status22Detected_V1, &Status22Sequence_V1
		);
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_V2, StatusFramePairPattern_V2,
			StatusNextStaticPattern_V2,StatusNextStaticPattern_film22_V2,
			&ExactMatch321_V2, &Violate321_V2,&index32_V2,
			&Status32Detected1_V2, &Status32Sequence1_V2,
			&ExactMatch322_V2, &Violate322_V2,&index322_V2,
			&Status32Detected2_V2, &Status32Sequence2_V2,
			&ExactMatch22_V2, &Violate22_V2,&index22_V2,
			&Status22Detected_V2, &Status22Sequence_V2
		);
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_V3, StatusFramePairPattern_V3,
			StatusNextStaticPattern_V3,StatusNextStaticPattern_film22_V3,
			&ExactMatch321_V3, &Violate321_V3,&index32_V3,
			&Status32Detected1_V3, &Status32Sequence1_V3,
			&ExactMatch322_V3, &Violate322_V3,&index322_V3,
			&Status32Detected2_V3, &Status32Sequence2_V3,
			&ExactMatch22_V3, &Violate22_V3,&index22_V3,
			&Status22Detected_V3, &Status22Sequence_V3
		);
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&2,
			StatusFrameStaticPattern_C, StatusFramePairPattern_C,
			StatusNextStaticPattern_C,StatusNextStaticPattern_film22_C,
			&ExactMatch321_C, &Violate321_C,&index32_C,
			&Status32Detected1_C, &Status32Sequence1_C,
			&ExactMatch322_C, &Violate322_C,&index322_C,
			&Status32Detected2_C, &Status32Sequence2_C,
			&ExactMatch22_C, &Violate22_C,&index22_C,
			&Status22Detected_C, &Status22Sequence_C
		);
		scalerVIP_film_FWmode_Quick_detection(
			im_di_control_reg.film_enable&8,
			StatusFrameStaticPattern, StatusFramePairPattern,
			StatusNextStaticPattern,StatusNextStaticPattern_film22,
			&ExactMatch321, &Violate321,&index32,
			&Status32Detected1, &Status32Sequence1,
			&ExactMatch322, &Violate322,&index322,
			&Status32Detected2, &Status32Sequence2,
			&ExactMatch22, &Violate22,&index22,
			&Status22Detected, &Status22Sequence
		);
	}
	if(im_di_si_film_final_result_reg.regValue&0x400){
		if((StatusNextStaticPattern_film22&3)==1){
			rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_temp]quick=next1 is_24to25=%d %d %d[/fw_film_temp]\t"
				,is_24to25,Status22Detected,Status22Sequence
			);
		}else if((StatusNextStaticPattern_film22&3)==2){
			rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_temp]quick=next2 is_24to25=%d %d %d[/fw_film_temp]\t"
				,is_24to25,Status22Detected,Status22Sequence
			);
		}else if((StatusFramePairPattern&3)==2){
			rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_temp]quick=pair2 is_24to25=%d %d %d[/fw_film_temp]\t"
				,is_24to25,Status22Detected,Status22Sequence
			);
		}else if((StatusFramePairPattern&3)==1){
			rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_temp]quick=pair1 is_24to25=%d %d %d[/fw_film_temp]\t"
				,is_24to25,Status22Detected,Status22Sequence
			);
		}else if((StatusNextStaticPattern_film22&3)==3){
			rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_temp]quick=next3 is_24to25=%d %d %d[/fw_film_temp]\t"
				,is_24to25,Status22Detected,Status22Sequence
			);
		}else if(Status22Sequence==1){
			rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_temp]quick=seq1 is_24to25=%d %d %d[/fw_film_temp]\t"
				,is_24to25,Status22Detected,Status22Sequence
			);
		}else if(Status22Sequence==2){
			rtd_printk(KERN_EMERG, TAG_NAME, "\n[fw_film_temp]quick=seq2 is_24to25=%d %d %d[/fw_film_temp]\t"
				,is_24to25,Status22Detected,Status22Sequence
			);
		}
	}

	// decision
	// combined sequence of 32 sub-detections
	Sequence_Sub32 = Status32Sequence1_H1|Status32Sequence1_H2|Status32Sequence1_H3|
					Status32Sequence1_V1|Status32Sequence1_V2|Status32Sequence1_V3|
					 Status32Sequence1_C |
					 Status32Sequence2_H1|Status32Sequence2_H2|Status32Sequence2_H3|
					 Status32Sequence2_V1|Status32Sequence2_V2|Status32Sequence2_V3|
				  	 Status32Sequence2_C |
					 Status32Sequence1   |Status32Sequence2;
	Sequence_Sub32H = Status32Sequence1_H1|Status32Sequence1_H2|Status32Sequence1_H3|
					  Status32Sequence2_H1|Status32Sequence2_H2|Status32Sequence2_H3;

	Sequence_Sub32V = Status32Sequence1_V1|Status32Sequence1_V2|Status32Sequence1_V3|
					  Status32Sequence2_V1|Status32Sequence2_V2|Status32Sequence2_V3;

	// combined sequence of 22 sub-detections
	Sequence_Sub22 = Status22Sequence_H1|Status22Sequence_H2|Status22Sequence_H3|
					 Status22Sequence_V1|Status22Sequence_V2|Status22Sequence_V3|
					 Status22Sequence_C |Status22Sequence;
	Sequence_Sub22H = Status22Sequence_H1|Status22Sequence_H2|Status22Sequence_H3;
	Sequence_Sub22V = Status22Sequence_V1|Status22Sequence_V2|Status22Sequence_V3;
	// combined detected state of 32 sub-detections
	Detected_Sub32 =!(!((Status32Detected1_H1||Status32Detected1_H2||Status32Detected1_H3) ||
			                (Status32Detected2_H1||Status32Detected2_H2||Status32Detected2_H3)  ) &&
					   ((Status32Detected1_V1||Status32Detected1_V2||Status32Detected1_V3) ||
			                (Status32Detected2_V1||Status32Detected2_V2||Status32Detected2_V3)  )  ) &&
					((Status32Detected1_H1||Status32Detected1_H2||Status32Detected1_H3||
					Status32Detected1_V1||Status32Detected1_V2||Status32Detected1_V3||
					Status32Detected1_C) ||
					(Status32Detected2_H1||Status32Detected2_H2||Status32Detected2_H3||
					Status32Detected2_V1||Status32Detected2_V2||Status32Detected2_V3||
					Status32Detected2_C) );

	Detected_Sub32H = (Sequence_Sub32H!=0);
	Detected_Sub32V = (Sequence_Sub32V!=0);
	// combined detected state of 22 sub-detections
	Detected_Sub22 = (Sequence_Sub22!=0);
	Detected_Sub22H = (Sequence_Sub22H!=0);
	Detected_Sub22V = (Sequence_Sub22V!=0);

	Detected_Sub22 = (!((!(Status22Detected_H1||Status22Detected_H2||Status22Detected_H3)) &&
						(Status22Detected_V1||Status22Detected_V2||Status22Detected_V3) )) &&
					  (Status22Detected_H1||Status22Detected_H2||Status22Detected_H3||
					   Status22Detected_V1||Status22Detected_V2||Status22Detected_V3||
					   Status22Detected_C) ;

	// use exact pattern match detection as any sub detectors violate film mode
	if( Violate321   ||	Violate322   ||
		Violate321_H1||	Violate321_H2||	Violate321_H3||
		Violate321_V1||	Violate321_V2||	Violate321_V3||
		Violate321_C ||
		Violate322_H1||	Violate322_H2||	Violate322_H3||
		Violate322_V1||	Violate322_V2||	Violate322_V3||
		Violate322_C ||
		MisMatch32)
	{
		Status32Detected1_H1 = ExactMatch321_H1;
		Status32Detected1_H2 = ExactMatch321_H2;
		Status32Detected1_H3 = ExactMatch321_H3;
		Status32Detected1_V1 = ExactMatch321_V1;
		Status32Detected1_V2 = ExactMatch321_V2;
		Status32Detected1_V3 = ExactMatch321_V3;
		Status32Detected1_C  = ExactMatch321_C;
		Status32Detected2_H1 = ExactMatch322_H1;
		Status32Detected2_H2 = ExactMatch322_H2;
		Status32Detected2_H3 = ExactMatch322_H3;
		Status32Detected2_V1 = ExactMatch322_V1;
		Status32Detected2_V2 = ExactMatch322_V2;
		Status32Detected2_V3 = ExactMatch322_V3;
		Status32Detected2_C  = ExactMatch322_C;
	}

	if( Violate22   ||
		Violate22_H1||	Violate22_H2||	Violate22_H3||
		Violate22_V1||	Violate22_V2||	Violate22_V3||
		Violate22_C ||
		MisMatch22)
	{
		Status22Detected_H1 = ExactMatch22_H1;
		Status22Detected_H2 = ExactMatch22_H2;
		Status22Detected_H3 = ExactMatch22_H3;
		Status22Detected_V1 = ExactMatch22_V1;
		Status22Detected_V2 = ExactMatch22_V2;
		Status22Detected_V3 = ExactMatch22_V3;
		Status22Detected_C  = ExactMatch22_C;
	}

	Detected_Sub32_Num = (int) (Status32Detected1_H1||Status32Detected2_H1) +
		                 (int) (Status32Detected1_H2||Status32Detected2_H2) +
						 (int) (Status32Detected1_H3||Status32Detected2_H3) +
						 (int) (Status32Detected1_V1||Status32Detected2_V1) +
		                 (int) (Status32Detected1_V2||Status32Detected2_V2) +
						 (int) (Status32Detected1_V3||Status32Detected2_V3) +
						 (int) (Status32Detected1_C ||Status32Detected2_C ) ;

	Detected_Sub22_Num = (int) Status22Detected_H1 +
		                 (int) Status22Detected_H2 +
						 (int) Status22Detected_H3 +
						 (int) Status22Detected_V1 +
			                 (int) Status22Detected_V2 +
						 (int) Status22Detected_V3 +
							 (int) Status22Detected_C ;
	MisMatch32 = MisMatch22 = MixedFilmConfuse = 0;
	film_index_Sub32 = index32_H1|index32_H2|index32_H3|
						  index32_V1|index32_V2|index32_V3|index32_C;
	film_index_Sub22 = index22_H1|index22_H2|index22_H3|
						  index22_V1|index22_V2|index22_V3|index22_C;
	film_index_Sub32 = ((
		(int)((film_index_Sub32 & 0x80)>>7)+ (int)((film_index_Sub32 & 0x40)>>6) + (int)((film_index_Sub32 & 0x20)>>5) +
		(int)((film_index_Sub32 & 0x10)>>4)+ (int)((film_index_Sub32 & 0x08)>>3) + (int)((film_index_Sub32 & 0x04)>>2) +
		(int)((film_index_Sub32 & 0x02)>>1)+ (int)((film_index_Sub32 & 0x01)))==1
		)? film_index_Sub32:0;
	film_index_Sub22 = ((
		(int)((film_index_Sub22 & 0x80)>>7)+ (int)((film_index_Sub22 & 0x40)>>6) + (int)((film_index_Sub22 & 0x20)>>5) +
		(int)((film_index_Sub22 & 0x10)>>4)+ (int)((film_index_Sub22 & 0x08)>>3) + (int)((film_index_Sub22 & 0x04)>>2) +
		(int)((film_index_Sub22 & 0x02)>>1)+ (int)((film_index_Sub22 & 0x01)))==1
		)? film_index_Sub22:0;

	Detected_Sub32_Num = (film_index_Sub32==0)? 0:Detected_Sub32_Num;
	Detected_Sub22_Num = (film_index_Sub22==0)? 0:Detected_Sub22_Num;
	film_index_Sub32 = (Detected_Sub32_Num==0)? 0:film_index_Sub32;
	film_index_Sub22 = (Detected_Sub22_Num==0)? 0:film_index_Sub22;

	// film detection rule
	// detect whole 32 film by 32detection1
	if(Status32Detected1 && hw_film_32Film !=0)
	{
		StatusFilmDetected = Status32Detected1;
		StatusFilmSequence = Status32Sequence1;
		StatusMixedFilmDetected = 0;
		film_index=index32;

		// exit film as detect 22 with different weave direction too
		if( Detected_Sub22 && !filmQuick_en)
		{
			switch(film_index)
			{
				case FILM32:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
			 			(Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM3223:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==4 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128 || StatusFilmSequence==512 || StatusFilmSequence==1)) ||
			 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==256)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM64:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==64)) ||
			 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==128)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM55:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1)) ||
			 			(Sequence_Sub22==2 && (StatusFilmSequence==2)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM2224:
					if(film_index_Sub22==FILM22)
					{
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==4 || StatusFilmSequence==16 || StatusFilmSequence==64)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128)))
				 		)
					 	{
							StatusFilmDetected = 0;
							MixedFilmConfuse = 1;

						}
					}
					else if(film_index_Sub22==FILM2224)
					{
						/*
						if(Sequence_Sub22!=StatusFilmSequence)
					 	{
							StatusFilmDetected = 0;
							MixedFilmConfuse = 1;

						}
						*/
					}

					break;
				case FILM32322:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==256 || StatusFilmSequence==1024)) ||
			 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==512 || StatusFilmSequence==2048)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM87:
					if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==256)) ||
			 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==512)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				default:
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
						break;
			}
		}
	}
	// detect whole 32 film by 32detection2
	else if(Status32Detected2 && hw_film_32Film !=0)
	{
		StatusFilmDetected = Status32Detected2;
		StatusFilmSequence = Status32Sequence2;
		StatusMixedFilmDetected = 0;
		film_index=index322;
		// exit film as detect 22 with different weave direction too
		if(Detected_Sub22 && !filmQuick_en &&
			((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
			 (Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8))))
		{
			StatusFilmDetected = 0;
			MixedFilmConfuse = 1;
		}
	}
	// detect whole 22 film by 22detection
	else if(Status22Detected && hw_film_22Film!=0)
	{
		StatusFilmDetected = Status22Detected;
		StatusFilmSequence = Status22Sequence;
		StatusMixedFilmDetected = 0;
		film_index=index22;
		// exit film as detect 32 with different weave direction too
		if(Detected_Sub32 && !filmQuick_en)
		{
			switch(film_index_Sub32)
			{
				case FILM32:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==2 || Sequence_Sub32==4 || Sequence_Sub32==16)) ||
			 			(StatusFilmSequence==2 && (Sequence_Sub32==1 || Sequence_Sub32==8)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM3223:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==4 || Sequence_Sub32==8 || Sequence_Sub32==32 || Sequence_Sub32==128 || Sequence_Sub32==512 || Sequence_Sub32==1)) ||
			 			(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==16 || Sequence_Sub32==64 || Sequence_Sub32==256)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM64:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==64)) ||
			 			(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==128)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM55:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1)) ||
			 			(StatusFilmSequence==2 && (Sequence_Sub32==2)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM2224:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==4 || Sequence_Sub32==16 || Sequence_Sub32==64)) ||
			 			(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==8 || Sequence_Sub32==32 || Sequence_Sub32==128)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM32322:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==8 || Sequence_Sub32==32 || Sequence_Sub32==256 || Sequence_Sub32==1024)) ||
			 			(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==16 || Sequence_Sub32==64 || Sequence_Sub32==512 || Sequence_Sub32==2048)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;
				case FILM87:
					if(((StatusFilmSequence==1 && (Sequence_Sub32==1 || Sequence_Sub32==256)) ||
			 			(StatusFilmSequence==2 && (Sequence_Sub32==2 || Sequence_Sub32==512)))
			 		)
				 	{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;

				default:
					{
						StatusFilmDetected = 0;
						MixedFilmConfuse = 1;
					}
					break;

			}
		}

	}
	else
	{
		StatusFilmDetected = 0;
		film_index=0;
		StatusFilmSequence=0;
		StatusMixedFilmDetected = 0;

		#if 0
		unsigned char thumbnail_case1,thumbnail_case2,thumbnail_case3;
		// 32 sub film detected
		if( Detected_Sub32_Num && (hw_film_32Film  ==2) )
		{
			StatusMixedFilmDetected = 1;
			StatusFilmSequence = Sequence_Sub32;
			film_index=film_index_Sub32;
			// exit film as detect 22 with different weave direction too
			if(Detected_Sub22 && !filmQuick_en)
			{
				switch(film_index)
				{
					case FILM32:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM3223:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==4 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128 || StatusFilmSequence==512 || StatusFilmSequence==1)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==256)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM64:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==64)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==128)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM55:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM2224:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==4 || StatusFilmSequence==16 || StatusFilmSequence==64)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM32322:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==256 || StatusFilmSequence==1024)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==512 || StatusFilmSequence==2048)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM87:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==256)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==512)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					default:
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
				}
			}
			// exit film as detect different sequences
			else if((Status32Sequence1_H1!=0 && StatusFilmSequence!=Status32Sequence1_H1)||
					(Status32Sequence1_H2!=0 && StatusFilmSequence!=Status32Sequence1_H2)||
					(Status32Sequence1_H3!=0 && StatusFilmSequence!=Status32Sequence1_H3)||
					(Status32Sequence1_V1!=0 && StatusFilmSequence!=Status32Sequence1_V1)||
					(Status32Sequence1_V2!=0 && StatusFilmSequence!=Status32Sequence1_V2)||
					(Status32Sequence1_V3!=0 && StatusFilmSequence!=Status32Sequence1_V3)||
					(Status32Sequence1_C!=0 && StatusFilmSequence!=Status32Sequence1_C)||
					(Status32Sequence2_H1!=0 && StatusFilmSequence!=Status32Sequence2_H1)||
					(Status32Sequence2_H2!=0 && StatusFilmSequence!=Status32Sequence2_H2)||
					(Status32Sequence2_H3!=0 && StatusFilmSequence!=Status32Sequence2_H3)||
					(Status32Sequence2_V1!=0 && StatusFilmSequence!=Status32Sequence2_V1)||
					(Status32Sequence2_V2!=0 && StatusFilmSequence!=Status32Sequence2_V2)||
					(Status32Sequence2_V3!=0 && StatusFilmSequence!=Status32Sequence2_V3)||
					(Status32Sequence2_C!=0 && StatusFilmSequence!=Status32Sequence2_C))
			{
				MisMatch32 = 1;
				StatusMixedFilmDetected = 0;
			}
			else if(!Detected_Sub32H && Detected_Sub32V)
			{
				//V1 is film, V2 or V3 is still (1073 play thumbnail)
				thumbnail_case1=(Status32Sequence1_V1|Status32Sequence2_V1) &&
								( ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) ) ||
								  ( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V2 is film, V1 or V3 is still
				thumbnail_case2=(Status32Sequence1_V2|Status32Sequence2_V2) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
								  ( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V3 is film, V1 or V2 is still
				thumbnail_case3=(Status32Sequence1_V3|Status32Sequence2_V3) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
								  ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) )   );

				if( hw_film_thumbnail_en && (thumbnail_case1 || thumbnail_case2 || thumbnail_case3) )
				{
					//StatusMixedFilmDetected = 1;
				}
				else if(hw_film_VerScrollingText_en)//vertical scrolling text
					StatusMixedFilmDetected = 0;
			}
		}
		// 22 sub film detected
		else if((Detected_Sub22_Num>2) && (hw_film_22Film == 2))
		{
			StatusMixedFilmDetected = 1;
			StatusFilmSequence = Sequence_Sub22;
			film_index=film_index_Sub22;
			// exit film as detect 32 with different weave direction too
			if(Detected_Sub32 && !filmQuick_en)
			{
				switch(film_index_Sub32)
				{
					case FILM32:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==2 || StatusFilmSequence==4 || StatusFilmSequence==16)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==1 || StatusFilmSequence==8)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM3223:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==4 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128 || StatusFilmSequence==512 || StatusFilmSequence==1)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==256)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM64:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==64)) ||
				 			(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==128)))
				 		)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM55:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM2224:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==4 || StatusFilmSequence==16 || StatusFilmSequence==64)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==128)))
						)
					 	{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM32322:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==8 || StatusFilmSequence==32 || StatusFilmSequence==256 || StatusFilmSequence==1024)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==16 || StatusFilmSequence==64 || StatusFilmSequence==512 || StatusFilmSequence==2048)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					case FILM87:
						if(((Sequence_Sub22==1 && (StatusFilmSequence==1 || StatusFilmSequence==256)) ||
							(Sequence_Sub22==2 && (StatusFilmSequence==2 || StatusFilmSequence==512)))
						)
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
					default:
						{
							StatusMixedFilmDetected = 0;
							MixedFilmConfuse = 1;
						}
						break;
				}
			}
			else if((Status22Sequence_H1!=0 && StatusFilmSequence!=Status22Sequence_H1)||
					(Status22Sequence_H2!=0 && StatusFilmSequence!=Status22Sequence_H2)||
					(Status22Sequence_H3!=0 && StatusFilmSequence!=Status22Sequence_H3)||
					(Status22Sequence_V1!=0 && StatusFilmSequence!=Status22Sequence_V1)||
					(Status22Sequence_V2!=0 && StatusFilmSequence!=Status22Sequence_V2)||
					(Status22Sequence_V3!=0 && StatusFilmSequence!=Status22Sequence_V3)||
					(Status22Sequence_C!=0 && StatusFilmSequence!=Status22Sequence_C))
			{
				MisMatch22 = 1;
				StatusMixedFilmDetected = 0;
			}
			else if(!Detected_Sub22H && Detected_Sub22V)
			{
				//V1 is film, V2 or V3 is still (1073 play thumbnail)
				thumbnail_case1=(Status22Sequence_V1) &&
								( ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) ) ||
						  		( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V2 is film, V1 or V3 is still
				thumbnail_case2=(Status22Sequence_V2) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
						  		( (StatusFrameStaticPattern_V3&1) && (StatusPrevStaticPattern_V3&1) && (StatusNextStaticPattern_V3&1) )   );
				//V3 is film, V1 or V2 is still
				thumbnail_case3=(Status22Sequence_V3) &&
								( ( (StatusFrameStaticPattern_V1&1) && (StatusPrevStaticPattern_V1&1) && (StatusNextStaticPattern_V1&1) ) ||
								  ( (StatusFrameStaticPattern_V2&1) && (StatusPrevStaticPattern_V2&1) && (StatusNextStaticPattern_V2&1) )   );

				if( hw_film_thumbnail_en && (thumbnail_case1 || thumbnail_case2 || thumbnail_case3) )
				{
					//StatusMixedFilmDetected = 1;
				}
				else if(hw_film_VerScrollingText_en)//vertical scrolling text
					StatusMixedFilmDetected = 0;
			}

		}
		// no any film mode detected
		else
		{
			StatusMixedFilmDetected = 0;
			StatusFilmSequence = 0;
		}
		#endif
	}

#define bad_edit_test 0
	SmartPic_clue->film_bad_edit_det = 0;
	if(bad_edit_test)
	{
		bool Status22Detected_noH3 = 0;
		int Status22Sequence_noH3 = 0;

		// 	for HQV BD - football court 22
		//	(H1 && H2 && V1 && V3 && C) && (All - H3) && (H3 inverse)

		NextDiff_noH3 = NextDiff - NextDiff_H3;

		if(NextDiff_noH3 < (hw_FieldStaticSumThl *2))
			Film22_StatusNextStaticPattern_noH3 = (Film22_StatusNextStaticPattern_noH3<<1)+1;
		else
			Film22_StatusNextStaticPattern_noH3 = Film22_StatusNextStaticPattern_noH3<<1;

		if((Film22_StatusNextStaticPattern_noH3 & 0xffff) == 0xaaaa)
		{
			Status22Detected_noH3 = 1;
			Status22Sequence_noH3 = (fw_DI_3A) ? 1 : 2;
		}
		else if((Film22_StatusNextStaticPattern_noH3 & 0xffff) == 0x5555)
		{
			Status22Detected_noH3 = 1;
			Status22Sequence_noH3 = (fw_DI_3A) ? 2 : 1;
		}
		else
		{
			Status22Detected_noH3 = 0;
			Status22Sequence_noH3 = 0;
		}

		if((((int)Status22Detected_H1 + (int)Status22Detected_H2
			+ (int)Status22Detected_V1 + (int)Status22Detected_V3
			+ (int)Status22Detected_C)>=3) &&
			(Status22Detected_noH3)	&&
			(Status22Detected_H3 && (Status22Sequence_H3 != Status22Sequence_noH3))
		)
		{
			SmartPic_clue->film_bad_edit_det = 1;
		}
		else
		{
			SmartPic_clue->film_bad_edit_det = 0;
		}

		if(SmartPic_clue->film_bad_edit_det)
		{
			StatusFilmDetected = 1;
			film_index = FILM22;
			StatusFilmSequence = Status22Sequence_noH3;
		}
	}

	// weave
	if(StatusFilmDetected || StatusMixedFilmDetected)
	{
		StatusFilmWeaveMode = 2;
		Weave_Mode_d = 2;
		force_weave_flag=0;
		if(film_index==FILM22) // 22
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 4)? 1:StatusFilmSequence_tmp;
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 2:// 1:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
		}
		else if(film_index==FILM32)  // 32
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 32)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 1 || StatusFilmSequence_tmp == 8)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 16)
				Weave_Mode_d = 0;
			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 16:// 1:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM3223 && film3223_en) // 3223
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 1024)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 16 ||
				StatusFilmSequence_tmp == 64 || StatusFilmSequence_tmp == 256)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 32 ||
				StatusFilmSequence_tmp == 128 || StatusFilmSequence_tmp == 512)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 512:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM64 && film64_en) // 64
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 1024)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 128)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 256)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 512:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM55 && film55_en) // 55
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 32)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 16:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM2224 && film2224_en) // 2224
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 1024)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 8 ||
				StatusFilmSequence_tmp == 32 || StatusFilmSequence_tmp == 128)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 16 ||
				StatusFilmSequence_tmp == 64 || StatusFilmSequence_tmp == 256)
				Weave_Mode_d = 0;
			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 512:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM32322 && film32322_en) // 32322
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 4096)? 1:StatusFilmSequence_tmp;

			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 16 ||
				StatusFilmSequence_tmp == 64 || StatusFilmSequence_tmp == 512 ||
				StatusFilmSequence_tmp == 2048)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 1 || StatusFilmSequence_tmp == 32 ||
				StatusFilmSequence_tmp == 1024)
				Weave_Mode_d = 0;
			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 2048:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 1024:// 512:// 1024:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 2048:// 1024:// 2048:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else if(film_index==FILM87 && film87_en) // 87
		{
			StatusFilmSequence_tmp = StatusFilmSequence << (im_di_film_new_function_main_reg.fw_film_doublebuffer_en);
			StatusFilmSequence_tmp = (StatusFilmSequence_tmp == 32768)? 1:StatusFilmSequence_tmp;
			if (StatusFilmSequence_tmp == 2 || StatusFilmSequence_tmp == 512)
				StatusFilmWeaveMode = 1;

			if (StatusFilmSequence_tmp == 4 || StatusFilmSequence_tmp == 1024)
				Weave_Mode_d = 0;

			/*
			switch(StatusFilmSequence_tmp)
			{
				case 1:// 16384:// 1:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 2:// 1:// 2:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 4:// 2:// 4:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 8:// 4:// 8:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16:// 8:// 16:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 32:// 16:// 32:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 64:// 32:// 64:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 128:// 64:// 128:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 256:// 128:// 256:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 512:// 256:// 512:
					StatusFilmWeaveMode = 1;
					Weave_Mode_d = 2;
					break;
				case 1024:// 512:// 1024:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 0;
					break;
				case 2048:// 1024:// 2048:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 4096:// 2048:// 4096:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 8192:// 4096:// 8192:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				case 16384:// 8192:// 16384:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
				default:
					StatusFilmWeaveMode = 2;
					Weave_Mode_d = 2;
					break;
			}
			*/
		}
		else//chris 20130220
		{
			StatusFilmDetected=0;
			StatusMixedFilmDetected = 0;
			StatusFilmSequence = 0;
		}
	}
	else
	{
		switch(StatusFilmSequence)
		{
			case 1:
				StatusFilmWeaveMode = 1;
				Weave_Mode_d = 2;
				break;
			case 2:
				StatusFilmWeaveMode = 2;
				Weave_Mode_d = 0;
				break;
			default:
				StatusFilmWeaveMode = 2;
				Weave_Mode_d = 2;
				break;
		}
		if(fw_film_control_force_weave_en)
		{
			if(!force_weave_flag && ((StatusFrameStaticPattern&3)==1) && !hw_film_BadEditor_flag)
			{
				force_weave_flag=1;
				weave_prev=1;
			}
			else if(force_weave_flag && ((StatusFrameStaticPattern&1)==1) && !hw_film_BadEditor_flag)
			{
				StatusFilmWeaveMode = 2;
				Weave_Mode_d = 2;
				weave_prev=1;
			}
			else if(force_weave_flag && ((StatusFrameStaticPattern&1)==0) && weave_prev && ((((StatusPrevStaticPattern&1)==1) && ((StatusNextStaticPattern&2)==2)) || (StatusFramePairPattern&7)==1) && !hw_film_BadEditor_flag)
			{
				StatusFilmWeaveMode =  (fw_DI_3A) ? 1:2;
				Weave_Mode_d = (fw_DI_3A) ? 2:0;
				weave_prev=!weave_prev;
			}
			else if(force_weave_flag && ((StatusFrameStaticPattern&1)==0) && !weave_prev && ((((StatusPrevStaticPattern&2)==2) && ((StatusNextStaticPattern&1)==1)) || (StatusFramePairPattern&11)==2) && !hw_film_BadEditor_flag)
			{
				StatusFilmWeaveMode = (fw_DI_3A)? 2:1;
				Weave_Mode_d =  (fw_DI_3A) ? 0:2;
				weave_prev=!weave_prev;
			}
			else
				force_weave_flag=0;
		}
	}

	// determine mixedfilm region
	hw_PrevTopMark = im_di_film_mark_prev1_reg.film_prevtopmark1;
	hw_PrevBotMark = im_di_film_mark_prev1_reg.film_prevbotmark1;
	hw_PrevTopMark2 = im_di_film_mark_prev2_reg.film_prevtopmark2;
	hw_PrevBotMark2 = im_di_film_mark_prev2_reg.film_prevbotmark2;
	hw_PrevTopMark3 = im_di_film_mark_prev3_reg.film_prevtopmark3;
	hw_PrevBotMark3 = im_di_film_mark_prev3_reg.film_prevbotmark3;
	hw_NextTopMark = im_di_film_mark_next1_reg.film_nexttopmark1;
	hw_NextBotMark = im_di_film_mark_next1_reg.film_nextbotmark1;
	hw_NextTopMark2 = im_di_film_mark_next2_reg.film_nexttopmark2;
	hw_NextBotMark2 = im_di_film_mark_next2_reg.film_nextbotmark2;
	hw_NextTopMark3 = im_di_film_mark_next3_reg.film_nexttopmark3;
	hw_NextBotMark3 = im_di_film_mark_next3_reg.film_nextbotmark3;

	hw_PrevTopMarkp = hw_PrevTopMark*2;
	hw_PrevBotMarkp = hw_PrevBotMark*2;
	hw_PrevTopMark2p = hw_PrevTopMark2*2;
	hw_PrevBotMark2p = hw_PrevBotMark2*2;
	hw_PrevTopMark3p = hw_PrevTopMark3*2;
	hw_PrevBotMark3p = hw_PrevBotMark3*2;

	hw_NextTopMarkp = hw_NextTopMark*2;
	hw_NextBotMarkp = hw_NextBotMark*2;
	hw_NextTopMark2p = hw_NextTopMark2*2;
	hw_NextBotMark2p = hw_NextBotMark2*2;
	hw_NextTopMark3p = hw_NextTopMark3*2;
	hw_NextBotMark3p = hw_NextBotMark3*2;

	PrevTopLine = (hw_PrevTopMarkp>MarkMargin) ? hw_PrevTopMarkp-MarkMargin : 0;
	PrevBotLine = hw_PrevBotMarkp + MarkMargin +2;
	PrevTopLine2 = hw_PrevTopMark2p - MarkMargin;
	PrevBotLine2 = hw_PrevBotMark2p + MarkMargin +2;
	PrevTopLine3 = hw_PrevTopMark3p - MarkMargin;
	PrevBotLine3 = hw_PrevBotMark3p + MarkMargin +2;

	PrevTopLine = (hw_PrevTopMark==0x7ef)? 0x800:PrevTopLine;
	PrevBotLine = (hw_PrevBotMark==0x7ef)? 0x800:PrevBotLine;
	PrevTopLine2 = (hw_PrevTopMark2==0x7ef)? 0x800:PrevTopLine2;
	PrevBotLine2 = (hw_PrevBotMark2==0x7ef)? 0x800:PrevBotLine2;
	PrevTopLine3 = (hw_PrevTopMark3==0x7ef)? 0x800:PrevTopLine3;
	PrevBotLine3 = (hw_PrevBotMark3==0x7ef)? 0x800:PrevBotLine3;

	NextTopLine = (hw_NextTopMarkp>MarkMargin) ? hw_NextTopMarkp-MarkMargin : 0;
	NextBotLine = hw_NextBotMarkp + MarkMargin +2;
	NextTopLine2 = hw_NextTopMark2p - MarkMargin;
	NextBotLine2 = hw_NextBotMark2p + MarkMargin +2;
	NextTopLine3 = hw_NextTopMark3p - MarkMargin;
	NextBotLine3 = hw_NextBotMark3p + MarkMargin +2;

	NextTopLine = (hw_NextTopMark==0x7ef)? 0x800:NextTopLine;
	NextBotLine = (hw_NextBotMark==0x7ef)? 0x800:NextBotLine;
	NextTopLine2 = (hw_NextTopMark2==0x7ef)? 0x800:NextTopLine2;
	NextBotLine2 = (hw_NextBotMark2==0x7ef)? 0x800:NextBotLine2;
	NextTopLine3 = (hw_NextTopMark3==0x7ef)? 0x800:NextTopLine3;
	NextBotLine3 = (hw_NextBotMark3==0x7ef)? 0x800:NextBotLine3;

	// get the non-film region
	// weave next field
	if(( (!hw_AdoptHDMethod && !hw_RTNR_Interlace_Force2D_En) && StatusFilmWeaveMode==1) || ( fw_DI_3A && Weave_Mode_d==0))
	{
		if(NextTopDetected_d && !NextTopDetected)
		{
			NextTopLine = TopLine;
			NextBotLine = BotLine;
			NextTopLine2 = TopLine2;
			NextBotLine2 = BotLine2;
			NextTopLine3 = TopLine3;
			NextBotLine3 = BotLine3;
		}
		TopLine = NextTopLine;
		BotLine = NextBotLine;
		TopLine2 = NextTopLine2;
		BotLine2 = NextBotLine2;
		TopLine3 = NextTopLine3;
		BotLine3 = NextBotLine3;
		NextTopDetected_d = NextTopDetected;
	}
	else// weave pre field
	{
		if(PrevTopDetected_d && !PrevTopDetected)
		{
			PrevTopLine = TopLine;
			PrevBotLine = BotLine;
			PrevTopLine2 = TopLine2;
			PrevBotLine2 = BotLine2;
			PrevTopLine3 = TopLine3;
			PrevBotLine3 = BotLine3;
		}
		TopLine = PrevTopLine;
		BotLine = PrevBotLine;
		TopLine2 = PrevTopLine2;
		BotLine2 = PrevBotLine2;
		TopLine3 = PrevTopLine3;
		BotLine3 = PrevBotLine3;
		PrevTopDetected_d = PrevTopDetected;
	}
	// write back
	fw_Status32Detected1 =  Status32Detected1;
	fw_Status32Detected2 =  Status32Detected2;
	fw_Status22Detected  = (g_st_DI_STATUS_VPAN != 0)? 0 : Status22Detected;
	fw_StatusMixedFilmDetected = ((g_st_DI_STATUS_VPAN != 0) &&
						((Status32Detected1==0) && (Status32Detected2==0)))? 0:StatusMixedFilmDetected;
	fw_StatusFilmDetected = ((g_st_DI_STATUS_VPAN != 0) &&
						((Status32Detected1==0) && (Status32Detected2==0)))? 0:(StatusFilmDetected || force_weave_flag);
	/*
	#if LG_Demo_flag
	fw_Status32Detected1 = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : Status32Detected1;
	fw_Status32Detected2 = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : Status32Detected2;
	fw_Status22Detected = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : Status22Detected;
	fw_StatusMixedFilmDetected = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : StatusMixedFilmDetected;
	fw_StatusFilmDetected = (scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN) != 0)? 0 : (StatusFilmDetected || force_weave_flag);
	#else
	fw_Status32Detected1 =  Status32Detected1;
	fw_Status32Detected2 =  Status32Detected2;
	fw_Status22Detected  =  Status22Detected;
	fw_StatusMixedFilmDetected = StatusMixedFilmDetected;
	fw_StatusFilmDetected = (StatusFilmDetected || force_weave_flag);
	#endif
	*/
	fw_MixedFilmConfuse = MixedFilmConfuse;

	fw_StatusFilmWeaveMode = StatusFilmWeaveMode;
	fw_StatusFilmSequence = hw_film_StatusFilmSequence;

	fw_TopLine = TopLine>>1;
	fw_BotLine =BotLine>>1;
	fw_TopLine2 =TopLine2>>1;
	fw_BotLine2 = BotLine2>>1;
	fw_TopLine3 =TopLine3>>1;
	fw_BotLine3 = BotLine3>>1;

	//scalerVIP_film_FWmode_3D_end();

	DetInformation.Fw_StatusFilmDetected = fw_StatusFilmDetected;
	DetInformation.Fw_StatusMixedFilmDetected = fw_StatusMixedFilmDetected;
	DetInformation.fw_StatusFilmSequence = fw_StatusFilmSequence;
	DetInformation.Fw_StatusFilmWeaveMode = fw_StatusFilmWeaveMode;
	DetInformation.Fw_MixedFilmConfuse = fw_MixedFilmConfuse;
	DetInformation.fw_Status32Detected1 = fw_Status32Detected1;
	DetInformation.fw_Status32Detected2 = fw_Status32Detected2;
	DetInformation.fw_Status22Detected = fw_Status22Detected;
	DetInformation.Fw_TopLine1= fw_TopLine;
	DetInformation.Fw_BotLine1 = fw_BotLine;
	DetInformation.Fw_TopLine2= fw_TopLine2;
	DetInformation.Fw_BotLine2 = fw_BotLine2;
	DetInformation.Fw_TopLine3= fw_TopLine3;
	DetInformation.Fw_BotLine3 = fw_BotLine3;

	return DetInformation;
}


void APPLY_scalerVIP_film_FWmode(FILM_FWMode DetInformation)
{
	di_im_di_film_new_function_main_RBUS im_di_film_new_function_main_reg;
	di_im_di_film_topbotline1_RBUS im_di_film_topbotline1_reg;
	di_im_di_film_topbotline2_RBUS im_di_film_topbotline2_reg;
	di_im_di_film_topbotline3_RBUS im_di_film_topbotline3_reg;

	im_di_film_new_function_main_reg.regValue = rtd_inl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);
	im_di_film_topbotline1_reg.regValue = rtd_inl(DI_IM_DI_FILM_TopBotLine1_reg);
	im_di_film_topbotline2_reg.regValue = rtd_inl(DI_IM_DI_FILM_TopBotLine2_reg);
	im_di_film_topbotline3_reg.regValue = rtd_inl(DI_IM_DI_FILM_TopBotLine3_reg);

	im_di_film_new_function_main_reg.fw_film_mixedfilmdetected = DetInformation.Fw_StatusMixedFilmDetected;
	im_di_film_new_function_main_reg.fw_film_filmweavemode = DetInformation.Fw_StatusFilmWeaveMode;
	im_di_film_new_function_main_reg.fw_film_filmsequence = DetInformation.fw_StatusFilmSequence;
	im_di_film_new_function_main_reg.fw_film_filmdetected = DetInformation.Fw_StatusFilmDetected;
	im_di_film_new_function_main_reg.fw_film_32detected1 = DetInformation.fw_Status32Detected1;
	im_di_film_new_function_main_reg.fw_film_32detected2 = DetInformation.fw_Status32Detected2;
	im_di_film_new_function_main_reg.fw_film_22detected = DetInformation.fw_Status22Detected;
	im_di_film_new_function_main_reg.fw_film_mixedfilmconfuse = DetInformation.Fw_MixedFilmConfuse;

	/*	for Sirius ECO v.3 need to update rbus
	if(SmartPic_clue->film_bad_edit_det && timing = 1080i)	// turn bad edit off
		im_di_film_new_function_main_reg.film_bad_edit_en = 0;
	else									// turn bad edit on
		im_di_film_new_function_main_reg.film_bad_edit_en = 1;
	*/
	di_im_di_control_RBUS im_di_control_reg;
	im_di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_reg);
	if((im_di_control_reg.film_enable & 0x10)>>4) {
		//if(((film_index == 0) || (film_index == FILM22) || (film_index == FILM32))) {
		//	im_di_film_new_function_main_reg.fw_film_en = 0;
		//
		//} else {
				im_di_film_new_function_main_reg.fw_film_en = 1;
		//}
	}

	rtd_outl(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg, im_di_film_new_function_main_reg.regValue);

	im_di_film_topbotline1_reg.fw_topline1 = MIN(1080,DetInformation.Fw_TopLine1);
	im_di_film_topbotline1_reg.fw_botline1 = MIN(1080,DetInformation.Fw_BotLine1);
	rtd_outl(DI_IM_DI_FILM_TopBotLine1_reg, im_di_film_topbotline1_reg.regValue);

	im_di_film_topbotline2_reg.fw_topline2 = MIN(1080,DetInformation.Fw_TopLine2);
	im_di_film_topbotline2_reg.fw_botline2 = MIN(1080,DetInformation.Fw_BotLine2);
	rtd_outl(DI_IM_DI_FILM_TopBotLine2_reg, im_di_film_topbotline2_reg.regValue);

	im_di_film_topbotline3_reg.fw_topline3 = MIN(1080,DetInformation.Fw_TopLine3);
	im_di_film_topbotline3_reg.fw_botline3 = MIN(1080,DetInformation.Fw_BotLine3);
	rtd_outl(DI_IM_DI_FILM_TopBotLine3_reg, im_di_film_topbotline3_reg.regValue);

	#if 0
	unsigned char fw_film_en;
	unsigned char hw_film_StatusFilmDetected,hw_film_StatusMixedFilmDetected;
	di_im_di_si_film_final_result_RBUS im_di_si_film_final_result_reg;
	im_di_si_film_final_result_reg.regValue = rtd_inl(DI_IM_DI_SI_FILM_FINAL_RESULT_VADDR);
	hw_film_StatusFilmDetected = im_di_si_film_final_result_reg.film_detected;
	hw_film_StatusMixedFilmDetected = im_di_si_film_final_result_reg.film_subdetected;

	di_im_di_debug_mode_RBUS reg18024008_Reg;
	reg18024008_Reg.regValue = rtd_inl(DI_IM_DI_DEBUG_MODE_VADDR);
	d_yuv2rgb_control_RBUS reg1802a700_Reg;
	reg1802a700_Reg.regValue = rtd_inl(YUV2RGB_D_YUV2RGB_CONTROL_VADDR);
	fw_film_en = im_di_film_new_function_main_reg.fw_film_en;
	if(fw_film_en)
	{
		if(reg18024008_Reg.film_debugmode && (DetInformation.Fw_StatusFilmDetected || DetInformation.Fw_StatusMixedFilmDetected))
			reg1802a700_Reg.yuv2rgb_main_en = 0x0;
		else
			reg1802a700_Reg.yuv2rgb_main_en = 0x1;
	}
	else
	{
		if(reg18024008_Reg.film_debugmode && (hw_film_StatusFilmDetected || hw_film_StatusMixedFilmDetected))
			reg1802a700_Reg.yuv2rgb_main_en = 0x0;
		else
			reg1802a700_Reg.yuv2rgb_main_en = 0x1;
	}
	rtd_outl(YUV2RGB_D_YUV2RGB_CONTROL_VADDR, reg1802a700_Reg.regValue);
	//Count++;
	//if(Count>=600 && Count%60==0 && reg18024008_Reg.film_debugmode)
	//{}
	#endif
}


void	scalerVIP_film_FWmode_detection1(unsigned int FrameStaticPattern,unsigned int FramePairPattern,
		unsigned int PrevStaticPattern, unsigned int NextStaticPattern, unsigned char Strict,
		unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,unsigned int *count_still,
		unsigned char *p32Detected1, unsigned int *p32Sequence1,unsigned char film_Pair_en_auto,
		unsigned char film_Pair1_en,unsigned char film_HiFreq_flag,unsigned char film_Violate_strict_en)
{
	unsigned char LeaveQuick_en=0,reg_vc_di_film_violate_stillpix_en=0;
	unsigned char Pair_en;//,film_Pair_en_auto,film_Pair1_en,film_Violate_strict_en,film_HiFreq_flag;

	if(film_Pair_en_auto)
	{
		if(*p32Detected1 && film_HiFreq_flag)
			Pair_en = 0;
		else
			Pair_en = 1;
	}
	else
		Pair_en = film_Pair1_en;

	*ExactMatch = 0;
	*Violate = 0;

	if(reg_vc_di_film_violate_stillpix_en && (FrameStaticPattern&1)==0 && *p32Detected1)
	{
		if(*count_still%2==1)
		{
			*Violate=1;
			*count_still=0;
			*film_index=0;
			*p32Sequence1=0;
			*p32Detected1=0;
		}
		else
		{
			*count_still=0;
		}
	}


	if(*p32Detected1 && film_Violate_strict_en)
	{
		if(*film_index==FILM32)
		{
				*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34 	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 	)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 	)) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x29)==0x28 	))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0)									))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM3223)
		{
				*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1b)==0x1a 	)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 	)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 	)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34 	)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34 	)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14 	)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 								)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 								)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM64)
		{
				*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x37)==0x36 	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c 	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1f)==0x1e 	)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c 	)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) 	|| (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 								)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1   	))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM55)
		{
				*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2f)==0x2e    )) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c    )) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1         )) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	    )) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	    ))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0)	 || (FrameStaticPattern&0x1)!=1		))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM2224)
		{
				*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x17)==0x16	 	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c  	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1d)==0x1c  	)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34  	)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34 	)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14 	)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x15)==0x14 	)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14 	)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)     								)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 								)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1       ))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM32322)
		{
				*p32Sequence1 = (*p32Sequence1==2048) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34 		)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	 		)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    			)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34 		)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 			)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)    && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 		)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)   && ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x2d)==0x2c    		)) ||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 		)) ||
						(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x35)==0x34	))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)  								)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A) 	&& ((!Pair_en || (FramePairPattern&1)!=0)      								)) ||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
						(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0) 								))
					)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
		if(*film_index==FILM87)
		{
				*p32Sequence1 = (*p32Sequence1==16384) ? 1 : (*p32Sequence1<<1);
				if(LeaveQuick_en)
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e 	)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c 	)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e 	)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A) 	&& ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x3d)==0x3c    ))||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
						(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
						(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
						(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
						(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1  ))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
				else
				{
					if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
						(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
						(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
						(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 								)) ||
						(*p32Sequence1==(unsigned int)(512<<fw_DI_3A) 	&& ((!Pair_en || (FramePairPattern&1)!=0)   								)) ||
						(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
						(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
						(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
						(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
						(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1  ))
				  	)
						{
							*Violate = 1;
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*film_index = 0;
						}
				}
		}
	}

	if(*p32Detected1) // check FrameStaticPattern and decide pSeq
	{
		if(*film_index==FILM32)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x84210:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619866 && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) )
				  	)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x8421:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866198) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
			  		)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x10842:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)!=0x2a) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && ((!LeaveQuick_en || PrevStaticPattern&0x2b)!=0x2a) )
				  	)

					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x21084:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  	)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x42108:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986619 && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) )
				 	 )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
						*ExactMatch = 1;
						*film_index=FILM32;
					}
					else
					{
						*p32Detected1=0;
						*p32Sequence1=0;
						*film_index=0;
					}
					break;

				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:
					{
						if(framestaticonly){
							if( (FrameStaticPattern&0x1)!=1 &&
								(*p32Sequence1==(unsigned int)(2<<fw_DI_3A))
							  )
							{
								*p32Detected1 = 0;
								*p32Sequence1 = 0;
								*Violate = 1;
								*count_still=0;
								*film_index=0;
							}
						}else
						if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
						{
							if(!film_Violate_strict_en)
							{
									*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
									if(LeaveQuick_en)
										{
											if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34 	)) ||
												(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
												(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 	)) ||
												(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 	)) ||
												(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x29)==0x28 	))
											  )
											 {
												*p32Detected1 = 0;
												*p32Sequence1 = 0;
												*Violate = 1;
												*count_still=0;
												*film_index=0;
											}
										}
										else
										{
											if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
												(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
												(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
												(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0)									)) ||
												(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&2)!=0)									))
											  )
											{
												*p32Detected1 = 0;
												*p32Sequence1 = 0;
												*Violate = 1;
												*count_still=0;
												*film_index=0;
											}
										}
							}
							if(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)) *count_still=0;
							else *count_still=*count_still+1;
						}
						else
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
						break;
					}
			}
		}
		else if(*film_index==FILM3223)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x40902:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26186661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a		) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x81204:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c		) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x2409:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21866618) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x4812:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6199861 && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9024:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666186 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x12048:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x24090:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x48120:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x90240:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26618666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x20481:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19861998) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
						*ExactMatch = 1;
						*film_index=FILM3223;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1b)==0x1a 	)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 	)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 	)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34 	)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34 	)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14 	)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
								  )
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 								)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 								)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
								  )
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) ) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
					break;
			}
		}
		else if(*film_index==FILM64)
		{
			switch(FrameStaticPattern&0xfffff)
			{

				case 0x799e6:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18180181 && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf33cc:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20600606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c) )
					)
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe6799:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1801818) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;

					}
					break;
				case 0xccf33:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6006060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x99e67:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18018180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x33ccf:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20060600) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x6799e:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x181801 && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xcf33c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x606006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;

					}
					break;
				case 0x9e679:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1818018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x3ccf3:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6060060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
						*ExactMatch = 1;
						*film_index=FILM64;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(32<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x37)==0x36 	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c 	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1f)==0x1e 	)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c 	)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) 	|| (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 								)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1   	))
							  	)
								{
										*p32Detected1 = 0;
										*p32Sequence1 = 0;
										*Violate = 1;
										*count_still=0;
										*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8<<fw_DI_3A)
						|| *p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(32<<fw_DI_3A)
						||*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)))
							*count_still=0;
						else
							*count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
					break;
			}
		}
		else if(*film_index==FILM55)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x739ce:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20180601 && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe739c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x601806 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xce739:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1806018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9ce73:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6018060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x39ce7:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18060180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
						*ExactMatch = 1;
						*film_index=FILM55;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==16) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2f)==0x2e    )) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c    )) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1         )) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	    )) ||
									(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	    ))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4)) && ((!Pair_en || (FramePairPattern&3)!=0)	 || (FrameStaticPattern&0x1)!=1		))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}

						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8<<fw_DI_3A) || *p32Sequence1==(unsigned int)(16>>(fw_DI_3A*4))) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
				break;
			}
		}
		else if(*film_index==FILM2224)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x1806:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18199981 && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x300c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20666606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x6018:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1999819 && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xc030:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6666066 && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x18060:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19998199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x300c0:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26660666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x60180:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19981999 && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xc0300:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26606666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x80601:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19819998) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xc03:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26066660) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
						*ExactMatch = 1;
						*film_index=FILM2224;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==512) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x17)==0x16	 	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x1d)==0x1c  	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x1d)==0x1c  	)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34  	)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34 	)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14 	)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x15)==0x14 	)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14 	)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1    	))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)     								)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 								)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0)  || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1       ))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}

						}
						if(*p32Sequence1==(unsigned int)(256<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(512>>(fw_DI_3A*9))) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
					break;
			}
		}
		else if(*film_index==FILM32322)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0x20420:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34	) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34		) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x40840:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x81081:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661998) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x2102:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x4204:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x8408:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x10810:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26199866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x21021:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666198) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x42042:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x84084:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x8108:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x10210:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26619866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 2048;
						*ExactMatch = 1;
						*film_index=FILM32322;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(128<<fw_DI_3A)
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==2048) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x35)==0x34 		)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x15)==0x14	 		)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    			)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x2d)==0x2c 		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x35)==0x34 		)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 			)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)    && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2b)==0x2a 		)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A)   && ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x2d)==0x2c    		)) ||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x2d)==0x2c 		)) ||
									(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x35)==0x34	))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1		)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)  								)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A) 	&& ((!Pair_en || (FramePairPattern&1)!=0)      								)) ||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0)								)) ||
									(*p32Sequence1==(unsigned int)(2048>>(fw_DI_3A*11)) && ((!Pair_en || (FramePairPattern&1)!=0) 								))
								)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(128<<fw_DI_3A)) *count_still=0;
						else *count_still=*count_still+1;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*Violate = 1;
						*count_still=0;
						*film_index=0;
					}
				break;
			}
		}
		else if(*film_index==FILM87)
		{
			switch(FrameStaticPattern&0xfffff)
			{
				case 0xf3f3e:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20006001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe7e7c:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xcfcf9:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9f9f3:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x3f3e7:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x7e7cf:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800600) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfcf9f:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6001800) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf9f3f:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006000) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf3e7e:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20018001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xe7cfc:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xcf9f9:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180018) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x9f3f3:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600060) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 4096 : 2048;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x3e7e7:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800180) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 8192 : 4096;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0x7cfcf:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6000600) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 16384 : 8192;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xf9f9f:
					if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18001800) || framestaticonly ||
						( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
					  )
					{
						*p32Detected1 = 1;
						*p32Sequence1 = (fw_DI_3A) ? 1 : 16384;
						*ExactMatch = 1;
						*film_index=FILM87;
					}
					else
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
					}
					break;
				case 0xfffff:
					if(Strict)
					{
						*p32Detected1 = 0;
						*p32Sequence1 = 0;
						*film_index=0;
						break;
					}

				default:   // decide still pix
					if(framestaticonly){
						if( (FrameStaticPattern&0x1)!=1 &&
							(
								*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(32<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(64<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(128<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(1024<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(2048<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(4096<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(8192<<fw_DI_3A) ||
								*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14))
							)
						  )
						{
							*p32Detected1 = 0;
							*p32Sequence1 = 0;
							*Violate = 1;
							*count_still=0;
							*film_index=0;
						}
					}else
					if((FrameStaticPattern&1) || (FramePairPattern&3)==0)
					{
						if(!film_Violate_strict_en)
						{
							*p32Sequence1 = (*p32Sequence1==16384) ? 1 : (*p32Sequence1<<1);
							if(LeaveQuick_en)
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e 	)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) || (NextStaticPattern&0x3d)==0x3c 	)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) || (PrevStaticPattern&0x3f)==0x3e 	)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A) 	&& ((!Pair_en || (FramePairPattern&1)!=0) ||  (NextStaticPattern&0x3d)==0x3c    ))||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
									(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1	)) ||
									(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
									(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
									(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1  ))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
							else
							{
								if(	(*p32Sequence1==(unsigned int)(1<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(2<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&1)!=0) 									)) ||
									(*p32Sequence1==(unsigned int)(4<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1    		)) ||
									(*p32Sequence1==(unsigned int)(8<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(16<<fw_DI_3A)     && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(32<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(64<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(128<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 		)) ||
									(*p32Sequence1==(unsigned int)(256<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&2)!=0) 								)) ||
									(*p32Sequence1==(unsigned int)(512<<fw_DI_3A) 	&& ((!Pair_en || (FramePairPattern&1)!=0)   								)) ||
									(*p32Sequence1==(unsigned int)(1024<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
									(*p32Sequence1==(unsigned int)(2048<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
									(*p32Sequence1==(unsigned int)(4096<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
									(*p32Sequence1==(unsigned int)(8192<<fw_DI_3A)      && ((!Pair_en || (FramePairPattern&3)!=0) || (FrameStaticPattern&0x1)!=1 	)) ||
									(*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14)) && ((!Pair_en || (FramePairPattern&3)!=0) ||  (FrameStaticPattern&0x1)!=1  ))
							  	)
								{
									*p32Detected1 = 0;
									*p32Sequence1 = 0;
									*Violate = 1;
									*count_still=0;
									*film_index=0;
								}
							}
						}
						if(*p32Sequence1==(unsigned int)(4<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(16<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(32<<fw_DI_3A) ||
							*p32Sequence1==(unsigned int)(64<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(128<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(1024<<fw_DI_3A) ||
							*p32Sequence1==(unsigned int)(2048<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(4096<<fw_DI_3A) ||*p32Sequence1==(unsigned int)(8192<<fw_DI_3A) ||
							*p32Sequence1==(unsigned int)(16384>>(fw_DI_3A*14))
						) {*count_still=0;}
						else *count_still=*count_still+1;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*Violate = 1;
					*count_still=0;
					*film_index=0;
				}
				break;
			}
		}
		else
		{
			*p32Detected1 = 0;
			*p32Sequence1 = 0;
			*Violate = 1;
			*count_still=0;
			*film_index=0;
		}
	}
	else    // initila detection  p32detection=0
	{
		*count_still=0;
		*p32Detected1 = 0;
		*p32Sequence1 = 0;
		*film_index=0;
		switch(FrameStaticPattern&0xfffff)
		{
// index=5 {5,5}
			case 0x739ce:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20180601 && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2f)==0x2e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe739c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x601806 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xce739:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1806018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9ce73:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6018060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x39ce7:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18060180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
					*ExactMatch = 1;
					*film_index=FILM55;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=4 {6,4}
			case 0x799e6:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18180181 && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x37)!=0x36) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf33cc:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20600606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c	) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)!=0x1c) )
				)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe6799:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1801818) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xccf33:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6006060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x99e67:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18018180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x33ccf:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20060600) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x6799e:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x181801 && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1f)==0x1e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xcf33c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x606006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;

				}
				break;
			case 0x9e679:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1818018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x3ccf3:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6060060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
					*ExactMatch = 1;
					*film_index=FILM64;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;

// index=6 {2,2,2,4}
			case 0x1806:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18199981 && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x17)!=0x16) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x300c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20666606 && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x1d)==0x1c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x6018:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1999819 && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1d)==0x1c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xc030:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6666066 && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)==0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x18060:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19998199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x300c0:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26660666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x60180:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19981999 && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x15)==0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xc0300:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26606666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x80601:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19819998) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xc03:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26066660) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
					*ExactMatch = 1;
					*film_index=FILM2224;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=3 {3,2,2,3}
			case 0x40902:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26186661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x81204:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x2409:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21866618) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x4812:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6199861 && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x1b)==0x1a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9024:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666186 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x12048:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x24090:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x48120:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x90240:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26618666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x20481:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19861998) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 512;
					*ExactMatch = 1;
					*film_index=FILM3223;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;

// index=7 {3,2,3,2,2}
			case 0x20420:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866199 && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34	) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x35)==0x34		) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x40840:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198666 && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x15)!=0x14) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x81081:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661998) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x2102:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x4204:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x8408:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x10810:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26199866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x21021:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18666198) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x42042:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21998661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2b)==0x2a) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x84084:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x8108:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19986619 && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x2d)==0x2c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x10210:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26619866 && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x35)!=0x34) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 2048;
					*ExactMatch = 1;
					*film_index=FILM32322;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=2 {3,2}
			case 0x84210:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6619866 && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x31)!=0x30) )
			  	)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x8421:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x19866198) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
		  		)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x10842:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x26198661 && (!LeaveQuick_en || (PrevStaticPattern&0x2b)!=0x2a) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && ((!LeaveQuick_en || PrevStaticPattern&0x2b)!=0x2a) )
			  	)

				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x21084:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18661986 && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x2d)!=0x2c) )
			  	)
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x42108:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x21986619 && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x29)!=0x28) )
			 	 )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 16;
					*ExactMatch = 1;
					*film_index=FILM32;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
// index=8 {8,7}
			case 0xf3f3e:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20006001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)==0x3e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2 : 1;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe7e7c:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)==0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4 : 2;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xcfcf9:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8 : 4;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9f9f3:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16 : 8;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x3f3e7:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 32 : 16;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x7e7cf:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800600) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 64 : 32;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xfcf9f:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6001800) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 128 : 64;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf9f3f:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18006000) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 256 : 128;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf3e7e:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x20018001 && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&2)==0) && (!LeaveQuick_en || (PrevStaticPattern&0x3f)!=0x3e) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 512 : 256;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xe7cfc:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x60006 && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) ) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&1)==0) && (!LeaveQuick_en || (NextStaticPattern&0x3d)!=0x3c) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1024 : 512;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xcf9f9:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x180018) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 2048 : 1024;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x9f3f3:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x600060) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 4096 : 2048;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x3e7e7:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x1800180) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 8192 : 4096;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0x7cfcf:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x6000600) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 16384 : 8192;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			case 0xf9f9f:
				if(	(!*p32Detected1 && (FramePairPattern&0x3fffffff)==0x18001800) || framestaticonly ||
					( *p32Detected1 && (!Pair_en || (FramePairPattern&3)==0) )
				  )
				{
					*p32Detected1 = 1;
					*p32Sequence1 = (fw_DI_3A) ? 1 : 16384;
					*ExactMatch = 1;
					*film_index=FILM87;
				}
				else
				{
					*p32Detected1 = 0;
					*p32Sequence1 = 0;
					*film_index=0;
				}
				break;
			default:
				*p32Detected1 = 0;
				*p32Sequence1 = 0;
				*film_index=0;
				*ExactMatch=0;
				break;

		}
	}
	*count_still = (*count_still>=0xff2)? 0xf0:*count_still;
}
void scalerVIP_film_FWmode_detection2(unsigned int NextStaticPattern, unsigned char Strict,
								unsigned int FrameStaticPattern,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,
								unsigned char *p32Detected2, unsigned int *p32Sequence2,unsigned char film_Violate_strict_en)
{
	*ExactMatch = 0;
	*Violate = 0;

	if(*p32Detected2 && film_Violate_strict_en)
	{
		*p32Sequence2 = (*p32Sequence2==16) ? 1 : (*p32Sequence2<<1);
		if(	(*p32Sequence2==(unsigned int)(2<<fw_DI_3A) && (NextFieldMotion || PrevFieldMotion || (FrameStaticPattern&1)!=1)) ||
			((*p32Sequence2==(unsigned int)(1<<fw_DI_3A) || *p32Sequence2==(unsigned int)(8 <<fw_DI_3A  )) && NextFieldMotion) ||
			((*p32Sequence2==(unsigned int)(4<<fw_DI_3A) || *p32Sequence2==(unsigned int)(16>>fw_DI_3A*4)) && PrevFieldMotion)
		  )
		{
			*Violate = 1;
			*p32Detected2 = 0;
			*p32Sequence2 = 0;
			*film_index = 0;
		}
	}

	// check frame static pattern for film detection
	switch(NextStaticPattern&0xfffff)
	{
		case 0x5ad6b:
			if((FrameStaticPattern&0x8421)==0x8421)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 4 : 2;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xb5ad6:
			if((FrameStaticPattern&0x10842)==0x10842)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 8 : 4;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0x6b5ad:
			if((FrameStaticPattern&0x21084)==0x21084)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 16 : 8;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xd6b5a:
			if((FrameStaticPattern&0x42108)==0x42108)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 1 : 16;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xad6b5:
			if((FrameStaticPattern&0x84210)==0x84210)
			{
				*p32Detected2 = 1;
				*p32Sequence2 = (fw_DI_3A) ? 2 : 1;
				*ExactMatch = 1;
				*film_index=FILM32;
			}
			else
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
			}
			break;
		case 0xfffff:
			if(Strict)
			{
				*p32Detected2 = 0;
				*p32Sequence2 = 0;
				*film_index=0;
				break;
			}
		default:
			if(!*p32Detected2)
			{
				switch(NextStaticPattern&0xff)
				{
				case 0x6b://0x0b:
					*p32Sequence2 = (fw_DI_3A) ? 4 : 2;
					break;
				case 0xd6://0x16:
					*p32Sequence2 = (fw_DI_3A) ? 8 : 4;
					break;
				case 0xad://0x0d:
					*p32Sequence2 = (fw_DI_3A) ? 16 : 8;
					break;
				case 0x5a://0x1a:
					*p32Sequence2 = (fw_DI_3A) ? 1 : 16;
					break;
				case 0xb5://0x15:
					*p32Sequence2 = (fw_DI_3A) ? 2 : 1;
					break;
				default:
					*p32Sequence2 = 0;
					break;
				}

			}
			else
			{
				if(!film_Violate_strict_en)
				{
					*p32Sequence2 = (*p32Sequence2==16) ? 1 : (*p32Sequence2<<1);
					if(	(*p32Sequence2==(unsigned int)(2<<fw_DI_3A) && (NextFieldMotion || PrevFieldMotion || (FrameStaticPattern&1)!=1)) ||
						((*p32Sequence2==(unsigned int)(1<<fw_DI_3A) || *p32Sequence2==(unsigned int)(8 <<fw_DI_3A  )) && NextFieldMotion) ||
						((*p32Sequence2==(unsigned int)(4<<fw_DI_3A) || *p32Sequence2==(unsigned int)(16>>fw_DI_3A*4)) && PrevFieldMotion)
					  )
					{
						*p32Detected2 = 0;
						*p32Sequence2 = 0;
						*Violate = 1;
						*film_index=0;
					}
				}
			}
			break;
	}//end of switch
}

void	scalerVIP_film_FWmode_detection22(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence,unsigned char film_Violate_strict_en)
{
	unsigned char reg_vc_di_film_violate_stillpix_en=0;

	*ExactMatch = 0;
	*Violate = 0;

	if(reg_vc_di_film_violate_stillpix_en && NextFieldMotion && !PrevFieldMotion  && *p22Detected)
	{
		if(*count_still22%2==1)
		{
			*Violate=1;
			*count_still22=0;
			*film_index=0;
			*p22Sequence=0;
			*p22Detected=0;
			*ExactMatch=0;
		}
		else
		{
			*count_still22=0;
		}
	}

	if(*p22Detected && film_Violate_strict_en)
	{
		if(*film_index == FILM22)
		{
			*p22Sequence = (*p22Sequence==2) ? 1 : 2;
			if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A)) && NextFieldMotion) ||
				((*p22Sequence==(unsigned int)(2>>fw_DI_3A)) && PrevFieldMotion))
			{
				*Violate = 1;
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
			}
		}

		else if(*film_index == FILM2224)
		{
			*p22Sequence = (*p22Sequence==512) ? 1 : (*p22Sequence<<1);
			if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(4<<fw_DI_3A) )
				||(*p22Sequence==(unsigned int)(16<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(64<<fw_DI_3A) )
				) && PrevFieldMotion) ||
				((*p22Sequence==(unsigned int)(2<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(8<<fw_DI_3A) ) ||
				(*p22Sequence==(unsigned int)(32<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(128<<fw_DI_3A) )
				) && NextFieldMotion)||
				((*p22Sequence==(unsigned int)(256<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(512>>9*fw_DI_3A) )
				)&& (NextFieldMotion || PrevFieldMotion))
			)
			{
				*Violate = 1;
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
			}
		}

	}

	// check frame static pattern for film detection
	switch(NextStaticPattern&0xfffff)
	{
		// (2,2)
		case 0xaaaaa:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 1 : 2;
			*ExactMatch = 1;
			break;
		}
		case 0x55555:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 2 : 1;
			*ExactMatch = 1;
			break;
		}


		/// film 2224
		case 0xabaae: // 1010101110
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 2 : 1;
			*ExactMatch = 1;
			break;
		}
		case 0x5755d: // 0101011101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 4 : 2;
			*ExactMatch = 1;
			break;
		}
		case 0xaeaba: // 1010111010
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 8 : 4;
			*ExactMatch = 1;
			break;
		}
		case 0x5d575: // 0101110101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 16 : 8;
			*ExactMatch = 1;
			break;
		}
		case 0xbaaea: // 1011101010
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 32 : 16;
			*ExactMatch = 1;
			break;
		}
		case 0x755d5: // 0111010101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 64 : 32;
			*ExactMatch = 1;
			break;
		}
		case 0xeabaa: // 1110101010
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 128 : 64;
			*ExactMatch = 1;
			break;
		}
		case 0xd5755: // 1101010101
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 256 : 128;
			*ExactMatch = 1;
			break;
		}
		case 0xaaeab: // 1010101011
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 512 : 256;
			*ExactMatch = 1;
			break;
		}
		case 0x55d57: // 0101010111
		{
			*film_index=FILM2224;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 1 : 512;
			*ExactMatch = 1;
			break;
		}

		case 0xfffff:
			if(Strict)
			{
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
				break;
			}
		default:
		{
			if(!*p22Detected)
			{
				switch(NextStaticPattern&0x3ff)
				{
					case 0x155://0x5555://349525:
					// added for special 32 film aabbccdddd
					case 0x157://0x5d57: // 0101010111
					case 0x355://0x5755: // 1101010101
					case 0x1d5://0x55d5: // 0111010101
					case 0x175://0xd575: // 0101110101
					case 0x15d://0x755d: // 0101011101
						*p22Sequence = (fw_DI_3A) ? 2 : 1;
						break;
					case 0x2aa://0xaaaa://699050:
					// added for special 32 film aabbccdddd
					case 0x2ab://0xaeab: // 1010101011
					case 0x3aa://0xabaa: // 1110101010
					case 0x2ea://0xaaea: // 1011101010
					case 0x2ba://0xeaba: // 1010111010
					case 0x2ae://0xbaae: // 1010101110
						*p22Sequence = (fw_DI_3A) ? 1 : 2;
						break;
					default:
						*p22Sequence = 0;
						break;
				}
			}
			else
			{
				if(!film_Violate_strict_en)
				{
					if(*film_index == FILM22)
					{
						*p22Sequence = (*p22Sequence==2) ? 1 : 2;
						if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A)) && NextFieldMotion) ||
							((*p22Sequence==(unsigned int)(2>>fw_DI_3A)) && PrevFieldMotion))
						{
							*Violate = 1;
							*p22Detected = 0;
							*p22Sequence = 0;
							*film_index=0;
						}
					}
					else if(*film_index == FILM2224)
					{
						*p22Sequence = (*p22Sequence==512) ? 1 : (*p22Sequence<<1);
						if(	((*p22Sequence==(unsigned int)(1<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(4<<fw_DI_3A) )
							||(*p22Sequence==(unsigned int)(16<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(64<<fw_DI_3A) )
							) && PrevFieldMotion) ||
							((*p22Sequence==(unsigned int)(2<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(8<<fw_DI_3A) ) ||
							(*p22Sequence==(unsigned int)(32<<fw_DI_3A) ) ||(*p22Sequence==(unsigned int)(128<<fw_DI_3A) )
							) && NextFieldMotion)||
							((*p22Sequence==(unsigned int)(256<<fw_DI_3A) ||(*p22Sequence==(unsigned int)(512>>9*fw_DI_3A) )
							)&& (NextFieldMotion || PrevFieldMotion))
						)
						{
							*Violate = 1;
							*p22Detected = 0;
							*p22Sequence = 0;
							*film_index=0;
						}
					}
				}
			}
			break;
		}
	}
	*count_still22 = (*count_still22>=0xff2)? 0xf0:*count_still22;
}

void	scalerVIP_film_FWmode_detection22new(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence)
{
	*ExactMatch = 0;
	*Violate = 0;
	// check frame static pattern for film detection
	switch(NextStaticPattern&0xfffff)
	{
		// (2,2)
		case 0xaaaaa:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 1 : 2;
			*ExactMatch = 1;
			break;
		}
		case 0x55555:
		{
			*film_index=FILM22;
			*p22Detected = 1;
			*p22Sequence = (fw_DI_3A) ? 2 : 1;
			*ExactMatch = 1;
			break;
		}
		case 0xfffff:
			if(Strict)
			{
				*p22Detected = 0;
				*p22Sequence = 0;
				*film_index=0;
				break;
			}
		default:
		{
			*p22Detected = 0;
			*p22Sequence = 0;
			*film_index=0;
			break;
		}
	}
}

void scalerVIP_film_FWmode_film32_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum)
{
	if(*Detected_flag)
	{
		(*Detected_cnt)++;
		if(*Detected_cnt>0xf)
			*Detected_cnt=0xf;
	}
	else
		*Detected_cnt=0;

	if(*Detected_cnt>FieldNum)
		*Detected_flag=1;
	else
		*Detected_flag=0;
}
void scalerVIP_film_FWmode_film22_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum)
{
	if(*Detected_flag)
	{
		(*Detected_cnt)++;
		if(*Detected_cnt>0xf)
			*Detected_cnt=0xf;
	}
	else
		*Detected_cnt=0;

	if(*Detected_cnt>FieldNum)
		*Detected_flag=1;
	else
		*Detected_flag=0;
}

void scalerVIP_film_FWmode(void)
{
	FILM_FWMode DetInfo;

	DetInfo = DETECTION_scalerVIP_film_FWmode();

	APPLY_scalerVIP_film_FWmode(DetInfo);
}
