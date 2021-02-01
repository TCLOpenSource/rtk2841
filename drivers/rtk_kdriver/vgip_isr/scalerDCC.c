
/*******************************************************************************
 * Header include
******************************************************************************/
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <rtd_types.h>
//#include <rtd_gpio.h>
#include <asm/div64.h>	//for 64-bit integer division

//#include <kernel/scaler/scalerDrv.h>
//#include <kernel/scaler/scalerInfo.h>
#include "vgip_isr/scalerVIP.h"
//#include <kernel/scaler/scalerIRQ.h>
#include "vgip_isr/scalerDI.h"
#include "vgip_isr/scalerVideo.h"
#include "vgip_isr/scalerDCC.h"
#include <scalercommon/scalerDrvCommon.h>
#include <scalercommon/vipCommon.h>
#include <scalercommon/vipRPCCommon.h>
#include <scalercommon/vdcCommon.h>

#include <rbus/vdpq_reg.h>
#include <rbus/color_dcc_reg.h>
#include <rbus/histogram_reg.h>
//#include <rbus/d_histogram_reg.h>

#include <rbus/di_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/profile_reg.h>
#include <rbus/mdomain_cap_reg.h>

#include <tvscalercontrol/vip/vip_reg_def.h>
#include "tvscalercontrol/scaler/scalerstruct.h"
#include <tvscalercontrol/scaler/scalercolorlib_tv002.h>
/*******************************************************************************
* Macro
******************************************************************************/

#define false FALSE
#define true TRUE
#define rtdf_outl 				rtd_outl
#define rtdf_inl				rtd_inl
#define ABS(x,y)				((x > y) ? (x-y) : (y-x))
#define CLAMP(a,b,c) ( (a)<(b) ? (b) : ((a)>(c)?(c):(a)) )    //!< clamp a to the range of [b;c]
#ifdef VIP_DEBUG_ENABLE
  #define VIP_DEBUG_PRINTF	ROSPrintf
#else
  #define VIP_DEBUG_PRINTF(x,y...)
#endif

//For debug use
#define DCC_Debug_flag (0)
#define DCC_info_flag (0)
#define DCC_Curve_Debug_flag (0)
#define DCC_Dummy_Debug_flag (1)
#define DCC_USER_S_SWAP 1



unsigned char Main_DCC_Level=0;
unsigned char Sub_DCC_Level=0;
unsigned char DCC_TABLE_Select=0;
unsigned char DCC_MODE_Select=0;
//unsigned char Main_DCC_User_Define_Curve_Table_Select=0;

static unsigned int *reg_HistCnt_Sub;
unsigned char 	Sub_Set_SC=0;

unsigned int Scene_change_DCC_apply_delay_enable = 1;
static unsigned int dcc_histogram_to_write[TableSeg_num_Max] = {0};
static unsigned int dcc_histogram_to_write_sub[TableSeg_num_Max] = {0};
static unsigned char dcc_histogram_write_flag = FALSE;	//TRUE = Need to write new DCC table

extern unsigned int Total_HistCnt_Sub;
unsigned int reg_HistCnt_prev[COLOR_HISTOGRAM_LEVEL]={0};
unsigned char score_NaturalImage = 0;
extern unsigned char SubSceneChange;
//extern unsigned char Main_Set_SC;
//extern _clues *SmartPic_clue;
extern Start_Print_info_t Start_Print;
//extern unsigned short H_Block[16];
//extern unsigned short V_Block[16];
extern unsigned char is3DLRmode;
//extern RPC_DCC_FUNCTION_Enable 	*g_DCC_FUNCTION_Struct;
//extern _system_setting_info	*system_info_structure_table;
//extern RPC_DCC_LAYER_Array_Flag *g_DCC_LAYER_Array_Struct;
extern unsigned int MA_print_count;
unsigned int cnt_dISR =0;
//extern unsigned int last_DCC_Histogram_Mean_value;

int GzbySH[bin_Curve_num_Max],Gz[Curve_num_Max],Identity[Curve_num_Max],DCurve[Curve_num_Max],UserCurve[Curve_num_Max],Weighting_Identity[Curve_num_Max];
unsigned int SH[COLOR_HISTOGRAM_LEVEL], SSH[COLOR_HISTOGRAM_LEVEL], LP_SH[COLOR_HISTOGRAM_LEVEL];
int BASE[TableSeg_num_Max], G0[TableSeg_num_Max], G1[TableSeg_num_Max];

unsigned int HighResSH[HighRes_bin_num_Max], HighResSSH[HighRes_bin_num_Max];
int ThreeSEGIdentity[Curve_num_Max];
int HighResGz[Curve_num_Max];

unsigned char HistCnt1stId = 0; // reg_HistSec1Cnt[8]
unsigned char HistCnt2ndId = 0;
unsigned char HistCnt3rdId = 0;
unsigned char HistCnt4thId = 0;
unsigned char Color0Section1Id = 0;

unsigned int reg_HistSec1Cnt[COLOR_HISTOGRAM_SECTION_LEVEL_MAX] = {0};
unsigned int reg_HistSec2Cnt[COLOR_HISTOGRAM_SECTION_LEVEL_MAX] = {0};

extern unsigned int DCCsqrt_table[4096];

unsigned char bSkipHistIIR = 0;

//======= define Main blending curve Temp===================
static int Database_blending_Identity[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

static int Main_preH[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

static int Main_panel_compensation_Curve[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

static int Main_range_remapping_Curve[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

static int skin_tone_curve[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,156,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

//======= S_Curve in DCC start===================
static int Main_S_Curve[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

//======= extend S_Curve in DCC start===================
static int Main_extend_Curve[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

//======= user define curve DCC start===================
static int Main_User_Define_Curve[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

//======= user define curve DCC start===================
static int Main_database_Curve[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

//======= define Main blending curve Temp===================
static int Main_Curve_Temp[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

//======= define sub blending curve Temp===================
static int Sub_preH[Curve_num_Max]=
{0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
200,208,216,224,232,240,258,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
400,408,416,424,432,440,458,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
600,608,616,624,632,640,658,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
800,808,816,824,832,840,858,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
1000,1008,1016,1023};

//=========== define for TV002 ADV API (gain multiply by 1024) =======================
#define base_curve_benchmark_tv002 1024
#define ADV_API_ModeGain_Max_tv002 10
unsigned int factor_curve_tv002[Curve_num_Max]; //using global to prevent stack overflow
int G0_tv002[Curve_num_Max];
int G1_tv002[Curve_num_Max];
unsigned short ADV_API_BaseCurve_TV002[Curve_num_Max]={
0,25,50,75,100,125,150,175,200,224,249,273,297,321,345,369,392,415,438,460,483,505,526,548,569,590,610,
630,650,669,688,706,724,742,759,775,792,807,822,837,851,865,878,891,903,915,926,936,946,955,964,972,
980,987,993,999,1004,1009,1013,1016,1019,1021,1023,1024,1024,1024,1023,1021,1019,1016,1013,1009,1004,
999,993,987,980,972,964,955,946,936,926,915,903,891,878,865,851,837,822,807,792,775,759,742,724,706,
688,669,650,630,610,590,569,548,526,505,483,460,438,415,392,369,345,321,297,273,249,224,200,175,150,
125,100,75,50,25,0}; //multiply by 1024
unsigned int mode_Gain_tv002[ADV_API_ModeGain_Max_tv002]={10240, 15000, 20480, 30000, 40960, 50000, 60000, 70000, 81920, 102400}; //multiply by 1024
unsigned char index_tv002[Curve_num_Max]={0};

extern int table_number_of_S_curve_mean;
extern unsigned int S_curve_mean[table_number_of_S_curve_mean_MAX][mean_value_index_MAX];


/*******************************************************************************
* Program
******************************************************************************/

//====================================
//Comments :   Hisogram refresh by Scaler_VGIPDSR() , 20160704
#ifdef CONFIG_HW_SUPPORT_D_HISTOGRAM
void scalerVIP_ddomain_colorHistISR(unsigned char channel)
{
/* // for debug used!

	unsigned int reg_value = 0;
	reg_value = rtd_inl(0xb802e4f8);

	if((reg_value & BIT(31))== 0){
		return;
	}
*/

	cnt_dISR++;

	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_system_setting_info* system_info_structure_table = NULL;
	system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	if((SmartPic_clue == NULL) || (system_info_structure_table == NULL)){
		if((cnt_dISR%600==0)&&(Start_Print.HIST==TRUE)){
			ROSPrintf("Share Memory PQ data ERROR, _clue = %x\n, system_info = %x\n, \n",
			 SmartPic_clue, system_info_structure_table);
		}
		return;
	}

	d_histogram_d_ich1_hist_in_cselect_RBUS d_ich1_hist_in_cselect_Reg;

	int i;
	unsigned int *reg_D_HistCnt=(SmartPic_clue->Y_Main_D_Hist);
	unsigned int DCC_Histogram_MAX=0;
	unsigned int Total_HistCnt=0;
	unsigned int Main_total_pixel_inv=0;
	unsigned int DC_average=0, DC_average_base=0;

	d_ich1_hist_in_cselect_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_IN_CSELECT_reg);

	if (d_ich1_hist_in_cselect_Reg.ch1_his_enable_histog == 0)
		return;

	//o----Check & Modify Histogram Bin Mode, avoid setting error. 20160624 -----o
	//SEC_HIST_MAX = COLOR_HISTOGRAM_SECTION_LEVEL_MAX;
	//HistSecExp_check = 4;
	if( (d_ich1_hist_in_cselect_Reg.bin_mode == 0)) { //HW setting 32bin
		DC_average_base = 8;
		if((COLOR_D_HISTOGRAM_LEVEL == 128)) {
			if((cnt_dISR%600==0)&&(Start_Print.HIST==TRUE)) {
				//ROSPrintf("Error!!! D_Hist_Bin_Mode setting missmatch!!\n");
				//ROSPrintf("Please Check the common Version of vipCommon.h with system or Kernel !!\n");
			}
			SmartPic_clue->D_Hist_Final_Bin_Mode = Mode_HistError;
		} else {
			SmartPic_clue->D_Hist_Final_Bin_Mode = system_info_structure_table->D_Histogram_Bin_Mode;
		}

	}else { //HW Setting 128 bin
		DC_average_base = 2;
		if((COLOR_D_HISTOGRAM_LEVEL == 32)){
			if((cnt_dISR%600==0)&&(Start_Print.HIST==TRUE)){
				//ROSPrintf("Warning!!! D_Hist_Bin_Mode setting missmatch!!\n");
				//ROSPrintf("Please Check the common Version of vipCommon.h with system or Kernel !!\n");
				//ROSPrintf("Bin_Mode -> change BinMode to Mode_Orig_32Bin \n");
			}
			SmartPic_clue->D_Hist_Final_Bin_Mode = Mode_128to32Bin;
		} else {
			SmartPic_clue->D_Hist_Final_Bin_Mode = system_info_structure_table->D_Histogram_Bin_Mode;
		}
	}

	drvif_color_Get_Ddomain_Y_histogram(channel, Hist_color_channel_0, reg_D_HistCnt);

//=========================
//=== some histogram infomation ====
//=========================
	Total_HistCnt=0;
	DCC_Histogram_MAX =0;
	for(i=0;i<COLOR_D_HISTOGRAM_LEVEL;i++) {
		Total_HistCnt+=reg_D_HistCnt[i]; //all his point num

		DC_average+= reg_D_HistCnt[i]*( i*DC_average_base);   /* Leo Chen, 20100809 moved from pacific_tpv */
		if(DCC_Histogram_MAX<reg_D_HistCnt[i]) {
			DCC_Histogram_MAX= reg_D_HistCnt[i];
			SmartPic_clue->D_Hist_Y_MAX_bin_index = i ;
			if((MA_print_count%600==0)&&(Start_Print.HIST==TRUE)) {
				//ROSPrintf("ooo---reg_D_HistCnt[%d]=%d ---ooo\n",i,reg_D_HistCnt[i] );
			}
		}
	}

	Main_total_pixel_inv = (1<<24)/(Total_HistCnt+1);
	SmartPic_clue->D_Hist_Y_Total_sum = Total_HistCnt;
	SmartPic_clue->D_Hist_Y_MAX_bin_ratio = (((unsigned long long)100*DCC_Histogram_MAX*Main_total_pixel_inv) >> 24);
	SmartPic_clue->D_Hist_Y_Mean_Value = (((unsigned long long)100*DC_average*Main_total_pixel_inv) >> 32) ;// 32=8+24 /* Leo Chen, 20100809 moved from pacific_tpv */
/*
	if((cnt_dISR%600==0)&&(Start_Print.HIST==TRUE)) {
		ROSPrintf("ooo---Y_Total_sum=%d ---ooo\n",SmartPic_clue->D_Hist_Y_Total_sum );
		ROSPrintf("ooo---DC_average_base=%d ---ooo\n",DC_average_base );
		ROSPrintf("ooo---DC_average=%d,Main_total_pixel_inv=%d ---ooo\n",DC_average,Main_total_pixel_inv );
		ROSPrintf("ooo---Mean_Value=%d ---ooo\n",SmartPic_clue->D_Hist_Y_Mean_Value );
		ROSPrintf("ooo---MAX_bin index=%d, ratio=%d ---ooo\n",SmartPic_clue->D_Hist_Y_MAX_bin_index,SmartPic_clue->D_Hist_Y_MAX_bin_ratio );
	}
*/
	d_histogram_d_ich1_hist_max_min_RBUS d_ich1_hist_max_min_Reg;
	d_ich1_hist_max_min_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_Max_Min_reg);
	SmartPic_clue->D_Hist_Peak_White_Pixel_value = d_ich1_hist_max_min_Reg.ch1_his_max_val;
	SmartPic_clue->D_Hist_Peak_Dark_Pixel_value  = d_ich1_hist_max_min_Reg.ch1_his_min_val;
	SmartPic_clue->D_Hist_Peak_White_IRE_Value   = ((SmartPic_clue->D_Hist_Peak_White_Pixel_value)*100)>>10;//mapping to 0 ~ 100 IRE
	SmartPic_clue->D_Hist_Peak_Dark_IRE_Value    = ((SmartPic_clue->D_Hist_Peak_Dark_Pixel_value)*100)>>10;//mapping to 0 ~ 100 IRE
/*
	if((cnt_dISR%300==0)&&(Start_Print.HIST==TRUE)) {
		ROSPrintf("ooo---peak_w=%d ---ooo\n",SmartPic_clue->D_Hist_Peak_White_Pixel_value );
		ROSPrintf("ooo---peak_D=%d ---ooo\n",SmartPic_clue->D_Hist_Peak_Dark_Pixel_value );
		ROSPrintf("ooo---Peak_W_IRE=%d ---ooo\n",SmartPic_clue->D_Hist_Peak_White_IRE_Value );
		ROSPrintf("ooo---Peak_D_IRE=%d ---ooo\n",SmartPic_clue->D_Hist_Peak_Dark_IRE_Value );
	}
*/
	scalerVIP_color_D_Hist_Get_APL(channel, NULL);

}
#endif


void scalerVIP_score_NaturalImage_detector(unsigned char channel, unsigned char bin_mode)
{
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_system_setting_info* system_info_structure_table = NULL;
	system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	if((SmartPic_clue == NULL) || (system_info_structure_table == NULL)){
		if((MA_print_count%360==0)&&(Start_Print.HIST==TRUE)){
			ROSPrintf("Share Memory PQ data ERROR, _clue = %x\n, system_info = %x\n, \n",
			 SmartPic_clue, system_info_structure_table);
		}
		return;
	}

	int i, j;
	unsigned char SEC_HIST_MAX = 0, HistSecExp_check=0, HistLocal_max = 0;
	unsigned int HistAllTotal=0,HistSecTotal=0;
	unsigned int *reg_HistCnt=(SmartPic_clue->Y_Main_Hist);

    	unsigned int HistCnt1stCnt = 0;
    	unsigned int HistCnt2ndCnt = 0;
    	unsigned int HistCnt3rdCnt = 0;
    	unsigned int HistCnt4thCnt = 0;
	int HistSecVar=0,HistAllVar=0,HistVarTmp1=0,HistVarTmp2=0;
	unsigned char HistSecExp=0;

	unsigned int reg_HistLocalTmp[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned int reg_HistLocal[9]={0,0,0,0,0,0,0,0,0};

	/* === Sorting  ===*/
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++){
		(SmartPic_clue->Y_Main_Hist)[i] = reg_HistCnt[i];

		if (HistCnt1stCnt < reg_HistCnt[i]) {
            // sort information move forward
            HistCnt4thCnt = HistCnt3rdCnt;
            HistCnt4thId = HistCnt3rdId;
            HistCnt3rdCnt = HistCnt2ndCnt;
            HistCnt3rdId = HistCnt2ndId;
            HistCnt2ndCnt = HistCnt1stCnt;
            HistCnt2ndId = HistCnt1stId;
			HistCnt1stCnt = reg_HistCnt[i];
			HistCnt1stId = i;
		} else if (HistCnt2ndCnt < reg_HistCnt[i]) {
            HistCnt4thCnt = HistCnt3rdCnt;
            HistCnt4thId = HistCnt3rdId;
            HistCnt3rdCnt = HistCnt2ndCnt;
            HistCnt3rdId = HistCnt2ndId;
			HistCnt2ndCnt = reg_HistCnt[i];
            HistCnt2ndId = i;
		} else if(HistCnt3rdCnt < reg_HistCnt[i]) {
            HistCnt4thCnt = HistCnt3rdCnt;
            HistCnt4thId = HistCnt3rdId;
            HistCnt3rdCnt = reg_HistCnt[i];
            HistCnt3rdId = i;
        	} else if( HistCnt4thCnt < reg_HistCnt[i] ) {
            HistCnt4thCnt = reg_HistCnt[i];
            HistCnt4thId = i;
        }
		HistAllTotal = HistAllTotal + reg_HistCnt[i];
	}
	HistAllTotal=HistAllTotal+1;

//==========================
//======= Section histogram refresh==
//==========================
	unsigned int HistSecTmp=0;
	//unsigned int Temp_reg_HistSec[4]={0,0,0,0};
	unsigned int HistLocal_start=0, HistLocal_End=0, HistLocal_boundary = 0;
	unsigned int HistCnt_start=0, HistCnt_End=0, HistCnt_boundary=0;
	unsigned int HistSecMax=0;

	if(bin_mode == 1) {

		SEC_HIST_MAX = COLOR_HISTOGRAM_MODE1_SECTION_LEVEL_MAX;/*Bin_Mode = 128, section histogram only 2 bins*/
		HistSecExp_check = 1;

		drvif_color_Get_Section_histogram(channel, Hist_color_channel_0, Hist_section0, HistCnt1stId, &reg_HistSec1Cnt[0]);
#if 1
		HistLocal_max = 4;
		if( HistCnt1stId >= ( COLOR_HISTOGRAM_LEVEL - 1 ) ){
			Color0Section1Id = HistCnt1stId - 1;
		} else if( HistCnt1stId <= 0){
			Color0Section1Id = HistCnt1stId + 1;
		} else {
			if(reg_HistSec1Cnt[0] >= reg_HistSec1Cnt[1]){
				reg_HistLocalTmp[3] = reg_HistSec1Cnt[0];
				reg_HistLocalTmp[4] = reg_HistSec1Cnt[1];
				Color0Section1Id = HistCnt1stId - 1;
			} else {
				reg_HistLocalTmp[0] = reg_HistSec1Cnt[0];
				reg_HistLocalTmp[1] = reg_HistSec1Cnt[1];
				Color0Section1Id = HistCnt1stId + 1;
			}
		}

		//set section histogram for bin 0~ 3
		drvif_color_Get_Section_histogram(channel, Hist_color_channel_0, Hist_section1, Color0Section1Id, &reg_HistSec2Cnt[0]);

		if(reg_HistSec1Cnt[0] >= reg_HistSec1Cnt[1]){
			reg_HistLocalTmp[0] = reg_HistSec2Cnt[0];
			reg_HistLocalTmp[1] = reg_HistSec2Cnt[1];
		} else {
			reg_HistLocalTmp[3] = reg_HistSec2Cnt[0];
			reg_HistLocalTmp[4] = reg_HistSec2Cnt[1];
		}


#else
		HistLocal_max = 16;
		if( HistCnt1stId > 124 ){
			HistCnt_start = (HistCnt1stId-3)-(HistCnt1stId-124);
			HistCnt_End = 127;
			HistCnt_boundary = (HistCnt_start-1);

			HistLocal_start = 1;
			HistLocal_End = 7;
			HistLocal_boundary = 0;
		} else if( HistCnt1stId < 3){
			HistCnt_start = 0;
			HistCnt_End = (HistCnt1stId+3)+(3-HistCnt1stId);
			HistCnt_boundary = (HistCnt_End+1);

			HistLocal_start = 0;
			HistLocal_End = 6;
			HistLocal_boundary = 14;
		} else {
			if(Temp_reg_HistSec1Cnt[0] >= Temp_reg_HistSec1Cnt[1]){
				HistCnt_start = (HistCnt1stId-3);
				HistCnt_End = (HistCnt1stId+3);
				HistCnt_boundary = (HistCnt1stId-4);

				HistLocal_start = 1;
				HistLocal_End = 7;
				HistLocal_boundary = 0;
			} else {
				HistCnt_start = (HistCnt1stId-3);
				HistCnt_End = (HistCnt1stId+3);
				HistCnt_boundary = (HistCnt1stId+4);

				HistLocal_start = 0;
				HistLocal_End = 6;
				HistLocal_boundary = 14;
			}
		}
		//set boundary section histogram for bin 0~ 1 or bin 14 ~15
		drvif_color_Get_Section_histogram(channel, Hist_color_channel_0, Hist_section1, HistCnt_boundary, &reg_HistLocalTmp[HistLocal_boundary]);

		//set others section histogram  for bn 2~15 or 0 ~ 13
		for(i=HistCnt_start;i<=HistCnt_End;i++){
			for(j = HistLocal_start; j <= HistLocal_End; j++){
				drvif_color_Get_Section_histogram(channel, Hist_color_channel_0, Hist_section0, i, &reg_HistLocalTmp[j*2]);
			}
		}
#endif

		for( i=0 ; i< 16 ; i++ ) {
			if(i < HistLocal_max) { //find the max on 0 ~ 3
			if( reg_HistLocalTmp[i]>HistSecMax ) {
				HistSecMax = reg_HistLocalTmp[i];
				HistSecExp = i;
			}
			} else {
				reg_HistLocalTmp[i] = 0;
			}
		}

	} else {

		SEC_HIST_MAX = COLOR_HISTOGRAM_SECTION_LEVEL_MAX; /*Bin_Mode = 32, section histogram 8 bins*/
		HistSecExp_check = 4;

	drvif_color_Get_Section_histogram(channel, Hist_color_channel_0, Hist_section0, HistCnt1stId, &reg_HistSec1Cnt[0]);

	// calculate peak position
		for( i=0 ; i<SEC_HIST_MAX ; i++ ) { //find max
			if( reg_HistSec1Cnt[i]>HistSecTmp ) {
			HistSecTmp = reg_HistSec1Cnt[i];
			HistSecExp = i;
		}
	}

		if( HistSecExp >= HistSecExp_check ) { // choice left or right bin of max bin!
	    Color0Section1Id = HistCnt1stId + 1;
	    	} else {
        Color0Section1Id = HistCnt1stId - 1;
    }

    drvif_color_Get_Section_histogram(channel, Hist_color_channel_0, Hist_section1, Color0Section1Id, &reg_HistSec2Cnt[0]);

	// merge 2 section histogram
		if(HistSecExp>=HistSecExp_check){
			for(i=0;i<SEC_HIST_MAX;i++) {
			reg_HistLocalTmp[i]=reg_HistSec1Cnt[i];
				reg_HistLocalTmp[i+SEC_HIST_MAX]=reg_HistSec2Cnt[i];

				if(HistSecMax < reg_HistSec1Cnt[i]) {
				HistSecExp = i;
				HistSecMax = reg_HistSec1Cnt[i];
				}

				if(HistSecMax < reg_HistSec2Cnt[i]) {
					HistSecExp = i+SEC_HIST_MAX;
				HistSecMax = reg_HistSec2Cnt[i];
			}
		}
		} else {
			for(i=0;i<SEC_HIST_MAX;i++) {
				reg_HistLocalTmp[i+SEC_HIST_MAX]=reg_HistSec1Cnt[i];
			reg_HistLocalTmp[i]=reg_HistSec2Cnt[i];

				if(HistSecMax < reg_HistSec1Cnt[i]) {
					HistSecExp = i+SEC_HIST_MAX;
				HistSecMax = reg_HistSec1Cnt[i];
				}

				if(HistSecMax < reg_HistSec2Cnt[i]) {
				HistSecExp = i;
				HistSecMax = reg_HistSec2Cnt[i];
			}
		}
	}

	if(HistSecExp<4)
		HistSecExp=4;
	else if(HistSecExp>11)
		HistSecExp=11;

	}



	/*o----Calculate the score_NaturalImage BY reg_HistLocalTmp-----o*/
	// "get peak+-4 only for 32 bin" and "get 0~4 only for 128 bin"
	for(i=0;i<9;i++) {
		if(HistLocal_max == 4){
			reg_HistLocal[i]=reg_HistLocalTmp[i];
		} else {
		reg_HistLocal[i]=reg_HistLocalTmp[i+HistSecExp-4];
		}
		HistSecTotal=HistSecTotal+reg_HistLocal[i];
	}
	HistSecTotal = HistSecTotal+1;

	unsigned int largest=0,secondlargest=0,thirdlargest=0,first_third_ratio;
	for(i=0;i<9;i++) {
		if (largest < reg_HistLocal[i]) {
			thirdlargest = secondlargest;
			secondlargest = largest;
			largest = reg_HistLocal[i];
		} else if (secondlargest < reg_HistLocal[i]) {
			thirdlargest = secondlargest;
			secondlargest = reg_HistLocal[i];
		} else if (thirdlargest < reg_HistLocal[i]) {
			thirdlargest = reg_HistLocal[i];
		}
	}
	first_third_ratio = 100*largest/(thirdlargest+1);

	// calculate variance of local(section) histogram
	if(HistLocal_max == 4) {
		HistVarTmp2=256*reg_HistLocal[HistSecExp];
		do_div(HistVarTmp2,HistSecTotal);
	} else {
	HistVarTmp2=256*reg_HistLocal[4];
	do_div(HistVarTmp2,HistSecTotal);
	}

	for(i=0;i<9;i++) {
		if(HistLocal_max < 4) {
		HistVarTmp1=256*reg_HistLocal[i];
		do_div(HistVarTmp1,HistSecTotal);
		HistSecVar = HistSecVar + (HistVarTmp1-HistVarTmp2)*(HistVarTmp1-HistVarTmp2);
	}
	}
	if(HistLocal_max == 4) {
		HistSecVar = HistSecVar>>2;
	} else {
	HistSecVar = HistSecVar/9;
	}

	//calculate vaiance of global histogram
	HistVarTmp2=256*HistCnt1stCnt/HistAllTotal;
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++) {
		HistVarTmp1=256*reg_HistCnt[i];
		do_div(HistVarTmp1,HistAllTotal);
		//HistVarTmp1=256*reg_HistCnt[i]/HistAllTotal;
		HistAllVar = HistAllVar + (HistVarTmp1-HistVarTmp2)*(HistVarTmp1-HistVarTmp2);
	}
	do_div(HistAllVar,COLOR_HISTOGRAM_LEVEL);

	//calculate vaiance of global histogram except the largest value
	//float HistAllVarNoLargest=0;
	int HistAllVarNoLargest=0;
	if ((HistAllTotal-HistCnt1stCnt) == 0){
		HistAllTotal = HistAllTotal+1;
	}

		HistVarTmp2=256*HistCnt2ndCnt;
		do_div(HistVarTmp2,(HistAllTotal-HistCnt1stCnt));
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++) {
		if(i==HistCnt1stId) continue;
		HistVarTmp1=256*reg_HistCnt[i];
		do_div(HistVarTmp1,(HistAllTotal-HistCnt1stCnt));
		HistAllVarNoLargest = HistAllVarNoLargest + (HistVarTmp1-HistVarTmp2)*(HistVarTmp1-HistVarTmp2);
	}
	do_div(HistAllVarNoLargest,(COLOR_HISTOGRAM_LEVEL-1));

	unsigned short score;
	score=HistSecVar/100 + HistAllVar/2000 + 20*first_third_ratio/300;
	if(HistSecVar>2000 && HistSecVar<=5000) {
		if((HistAllVar*10)/(abs((int)HistAllVarNoLargest-(int)HistAllVar)+1) < 15)
			score=(score<80)?0:(score-80);
	} else if(HistSecVar>5000 && HistSecVar<11000) {
		if(HistAllVarNoLargest<1300)
			score=(score<80)?0:(score-80);
	}

	SmartPic_clue->score_NaturalImage = CLAMP(score,0,255);

}



void scalerVIP_colorHistISR(unsigned char channel)
{
	histogram_ich1_hist_in_cselect_RBUS ich1_hist_in_cselect_Reg;
	// Get SmartPic_clue Information
	extern unsigned char g_IsNot4KVO;
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_RPC_clues* RPC_SmartPic_clue=NULL;
	RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();
	_system_setting_info* system_info_structure_table = NULL;
	system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();
	_RPC_system_setting_info* RPC_system_info_structure_table = NULL;
	RPC_system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	if((RPC_SmartPic_clue ==NULL) || (SmartPic_clue == NULL) || (system_info_structure_table == NULL) || (RPC_system_info_structure_table == NULL)){
		if((MA_print_count%360==0)&&(Start_Print.HIST==TRUE)){
			ROSPrintf("Share Memory PQ data ERROR, _clue = %x\n, system_info = %x\n, , RPC_system_info = %x\n",
			 SmartPic_clue, system_info_structure_table, RPC_system_info_structure_table);
		}
		return;
	}


	int i, j;
	unsigned int DCC_Histogram_MAX=0;
	unsigned int	Total_HistCnt=0;
	unsigned int Main_total_pixel_inv=0;
	unsigned char DCC_IIR_prev_factor = 0;	//0<=DCC_IIR_prev_factor<8
	unsigned int *reg_HistCnt=(SmartPic_clue->Y_Main_Hist);
	unsigned int DC_average=0, DC_average_base=0;
	unsigned char Hist_Bin_Mode = 0;
#if 0

	unsigned int HistAllTotal=0,HistSecTotal=0;

	unsigned char SEC_HIST_MAX = 0, HistSecExp_check=0;

	unsigned int reg_HistLocalTmp[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned int reg_HistLocal[9]={0,0,0,0,0,0,0,0,0};
	int HistSecVar=0,HistAllVar=0,HistVarTmp1=0,HistVarTmp2=0;
	unsigned char HistSecExp=0;

    	unsigned int HistCnt1stCnt = 0;
    	unsigned int HistCnt2ndCnt = 0;
    	unsigned int HistCnt3rdCnt = 0;
    	unsigned int HistCnt4thCnt = 0;
#endif
	static unsigned char smooth_Toggle_cnt = 0;

	ich1_hist_in_cselect_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg);

	if (ich1_hist_in_cselect_Reg.ch1_his_enable_histog == 0)
		return;

	//o--------- For NetFlex Application, hist_init_flag enable when Netflex timing change-------o
#if 0
	if(SmartPic_clue->S_NetFlix_info.NetFlix_smooth_Toggle_info.hist_init_flag== 1) {
		SmartPic_clue->S_NetFlix_info.NetFlix_smooth_Toggle_info.hist_init_flag = 0;
		return;
	}
#else
	if(RPC_SmartPic_clue->S_NetFlix_info.NetFlix_smooth_Toggle_info.hist_init_flag ==  1 || smooth_Toggle_cnt  !=0) {
		if (RPC_SmartPic_clue->S_NetFlix_info.NetFlix_smooth_Toggle_info.hist_init_flag !=0 ) {
			smooth_Toggle_cnt = 1;
			RPC_SmartPic_clue->S_NetFlix_info.NetFlix_smooth_Toggle_info.hist_init_flag = 0;
		} else {
			smooth_Toggle_cnt --;
		}
 		return;
	}
#endif

	//o----Check & Modify Histogram Bin Mode, avoid setting error. 20160624 -----o
	//SEC_HIST_MAX = COLOR_HISTOGRAM_SECTION_LEVEL_MAX;
	//HistSecExp_check = 4;
	if( (ich1_hist_in_cselect_Reg.bin_mode == 0)) { //HW setting 32bin
		Hist_Bin_Mode = 0;
		DC_average_base = 8;
		if((COLOR_HISTOGRAM_LEVEL == 128)) {
			if((MA_print_count%360==0)&&(Start_Print.HIST==TRUE)) {
				ROSPrintf("Error!!! Hist_Bin_Mode setting missmatch!!\n");
				ROSPrintf("Please Check the common Version of vipCommon.h with system or Kernel !!\n");
			}
			SmartPic_clue->Hist_Final_Bin_Mode = Mode_HistError;
		} else {
			SmartPic_clue->Hist_Final_Bin_Mode = system_info_structure_table->Histogram_Bin_Mode;
		}

	} else { //HW Setting 128 bin
		Hist_Bin_Mode = 1;
		DC_average_base = 2;
		if((COLOR_HISTOGRAM_LEVEL == 32)) {
			if((MA_print_count%360==0)&&(Start_Print.HIST==TRUE)){
				ROSPrintf("Warning!!! Hist_Bin_Mode setting missmatch!!\n");
				ROSPrintf("Please Check the common Version of vipCommon.h with system or Kernel !!\n");
				ROSPrintf("Bin_Mode -> change BinMode to Mode_Orig_32Bin \n");
			}
			SmartPic_clue->Hist_Final_Bin_Mode = Mode_128to32Bin;
		} else {
			SmartPic_clue->Hist_Final_Bin_Mode = system_info_structure_table->Histogram_Bin_Mode;
		}
	}

//===============================
//======= main histogram refresh=========
//==============================

	#if 1
		drvif_color_Get_Idomain_Y_histogram(channel, Hist_color_channel_0, reg_HistCnt);
	#else
	        drvif_color_Get_Y_histogram(channel, Hist_color_channel_0, reg_HistCnt);
	#endif


if (g_IsNot4KVO) {

//=================================================
//======= Section histogram refresh and Get the score of NaturalImage ==
//=================================================

	scalerVIP_score_NaturalImage_detector(channel,  Hist_Bin_Mode);

//======================================
//=== Elsie 20130129, Add IIR filter for DCC histogram ===
//======================================
	if(!(RPC_SmartPic_clue->SceneChange) && !bSkipHistIIR)	//not scene change, do IIR filtering
	{
		for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
		{
			reg_HistCnt[i]=(reg_HistCnt_prev[i]*DCC_IIR_prev_factor+reg_HistCnt[i]*(8-DCC_IIR_prev_factor))>>3;
			reg_HistCnt_prev[i]=reg_HistCnt[i];
		}
	}
	else	//scene change, clear previous data
	{
		for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
		{
			reg_HistCnt_prev[i]=reg_HistCnt[i];
		}
	}

//=========================
//=== some histogram infomation ====
//=========================
	Total_HistCnt=0;
	DCC_Histogram_MAX =0;
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
	{
		Total_HistCnt+=reg_HistCnt[i];	//all his point num
		(SmartPic_clue->Y_Main_Hist)[i] = reg_HistCnt[i];//from IIR result

		DC_average+= reg_HistCnt[i]*( i*DC_average_base);   /* Leo Chen, 20100809 moved from pacific_tpv */
		if(DCC_Histogram_MAX<reg_HistCnt[i])
		{
			DCC_Histogram_MAX= reg_HistCnt[i];
			SmartPic_clue->Hist_Y_MAX_bin_index = i ;
		}
	}

	Main_total_pixel_inv = (1<<24)/(Total_HistCnt+1);
	SmartPic_clue->Hist_Y_Total_sum = Total_HistCnt;
	SmartPic_clue->Hist_Y_MAX_bin_ratio = (((unsigned long long)100*DCC_Histogram_MAX*Main_total_pixel_inv) >> 24);
	SmartPic_clue->Hist_Y_Mean_Value = (((unsigned long long)100*DC_average*Main_total_pixel_inv) >> 32) ;// 32=8+24 /* Leo Chen, 20100809 moved from pacific_tpv */
	//SmartPic_clue->Hist_Y_MAX_bin_ratio = DCC_Histogram_MAX_ratio;
	//SmartPic_clue->Hist_Y_Mean_Value = DCC_Histogram_Mean_value;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
	{
		ROSPrintf("ooo---Y_Total_sum=%d ---ooo\n",SmartPic_clue->Hist_Y_Total_sum );
		ROSPrintf("ooo---DC_average=%d,Main_total_pixel_inv=%d ---ooo\n",DC_average,Main_total_pixel_inv );
		ROSPrintf("ooo---Mean_Value=%d ---ooo\n",SmartPic_clue->Hist_Y_Mean_Value );
		ROSPrintf("ooo---MAX_bin index=%d, ratio=%d ---ooo\n",SmartPic_clue->Hist_Y_MAX_bin_index,SmartPic_clue->Hist_Y_MAX_bin_ratio );
		ROSPrintf("ooo---score_NaturalImage=%d ---ooo\n",SmartPic_clue->score_NaturalImage );
	}
}

	histogram_ich1_hist_max_min_RBUS ich1_hist_max_min_Reg;
	ich1_hist_max_min_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_Max_Min_reg);
	SmartPic_clue->Hist_Peak_White_Pixel_value = ich1_hist_max_min_Reg.ch1_his_max_val;//Range: 0~1023
	SmartPic_clue->Hist_Peak_Dark_Pixel_value = ich1_hist_max_min_Reg.ch1_his_min_val;//Range: 0~1023
	SmartPic_clue->Hist_Peak_White_IRE_Value = ((SmartPic_clue->Hist_Peak_White_Pixel_value)*100)>>10;//mapping to 0 ~ 100 IRE
	SmartPic_clue->Hist_Peak_Dark_IRE_Value = ((SmartPic_clue->Hist_Peak_Dark_Pixel_value)*100)>>10;//mapping to 0 ~ 100 IRE

	//== check SC information
	if(RPC_system_info_structure_table->Project_ID == VIP_Project_ID_TV002)
		drvif_color_DCC_SC_TV002(channel);
	else if(RPC_system_info_structure_table->Project_ID == VIP_Project_ID_TV010)
		drvif_color_DCC_SC_TV010(channel);
	else
		drvif_color_IHIST_SC(channel);

	scalerVIP_colorHist_Get_APL(channel, NULL);

}

#if 1 //from Merlin2 20160629
#ifdef CONFIG_HW_SUPPORT_D_HISTOGRAM
unsigned int temp_reg_D_HistCnt[COLOR_D_HISTOGRAM_LEVEL]; //avoid stack overflow
void drvif_color_Get_Ddomain_Y_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned int *reg_HistCnt)
{
	//return;

	unsigned int i = 0, sram_block_cnt = 0;
	unsigned int baseAddress = 0;
	unsigned char sram_block_cnt_th = 0;
	unsigned char sram_bin_base = 0;
	unsigned char Hist_Total_Bin = 0;

	const unsigned short timeout = 3000;
	static unsigned short read_timer = timeout;

	static unsigned int cnt =0;
	cnt++;

	if(channel>SLR_SUB_DISPLAY){ //prevent the channel selection error!

		channel = SLR_MAIN_DISPLAY;
	}

	if(channel == SLR_MAIN_DISPLAY){

		d_histogram_d_ich1_hist_read_ctr_RBUS  d_ich1_hist_read_ctr_Reg;
		d_histogram_d_ich1_hist_in_cselect_RBUS d_ich1_hist_in_cselect_Reg;
		d_ich1_hist_read_ctr_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_READ_CTR_reg);
		d_ich1_hist_in_cselect_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_IN_CSELECT_reg);

		if(d_ich1_hist_in_cselect_Reg.bin_mode == 0){
			sram_block_cnt_th = 1;
			Hist_Total_Bin = 32;
		} else {
			sram_block_cnt_th = 4;
			Hist_Total_Bin = 128;

			if( d_ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag == 1 ){
				d_ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag = 1;
				rtd_outl(D_HISTOGRAM_D_ICH1_Hist_READ_CTR_reg,d_ich1_hist_read_ctr_Reg.regValue);
			}

		}

		// Read ich1_hist_in_data_01_00_reg once a time can speed up by caching mechanism.
		// And because the structure of ich1_hist_in_data_01_00_reg ~ ich1_hist_in_data_31_30_reg are all the same,
		// we can declare ich1_hist_in_data_01_00_reg only for reduce the number of variable.
		histogram_ich1_c0_hist_in_data_01_00_RBUS	ich1_hist_in_data_reg;

		if( C_Channel_select == 0){
			baseAddress = D_HISTOGRAM_D_ICH1_C0_Hist_IN_Data_01_00_reg;
		} else if ( C_Channel_select == 1 )  {
			baseAddress = D_HISTOGRAM_D_ICH1_C1_Hist_IN_Data_01_00_reg;
		}
#if 0
		if((MA_print_count%600==0)&&(Start_Print.HIST==TRUE)) {
			d_ich1_hist_read_ctr_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_HIST_READ_CTR_reg);
			ROSPrintf("1.Get_Ddomain_Y_histogram(%d,%d)\n",read_timer,d_ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag);
		}
#endif

		for(sram_block_cnt=0; sram_block_cnt<sram_block_cnt_th; sram_block_cnt++){

			/*o----init the read setting for hist sram---o*/
			d_ich1_hist_read_ctr_Reg.ch1_sram_block = sram_block_cnt;
			rtd_outl(D_HISTOGRAM_D_ICH1_Hist_READ_CTR_reg,d_ich1_hist_read_ctr_Reg.regValue);
			d_ich1_hist_read_ctr_Reg.ch1_sram_read = 1;
			rtd_outl(D_HISTOGRAM_D_ICH1_Hist_READ_CTR_reg,d_ich1_hist_read_ctr_Reg.regValue);

			/*o----check sram read status and avoide the infinite loop !!----o*/
			do{
				d_ich1_hist_read_ctr_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_READ_CTR_reg);
				read_timer--;

				if( read_timer == 0 ){
					read_timer = timeout;
					if((cnt_dISR%60==0)&&(Start_Print.HIST==TRUE)) {
						//ROSPrintf("2.Warring!!! D-histogram Reading timeout, sram_read !=0 !! \n");
					}
					return; // wait until next ISR
				}

			}while(d_ich1_hist_read_ctr_Reg.ch1_sram_read == 1);

			/*o----Read histogram ----o*/
			for(i=0; i<COLOR_HISTOGRAM_DATA_BIN_NUM; i++){
				ich1_hist_in_data_reg.regValue = scaler_rtd_inl(baseAddress + i*4);
				sram_bin_base = (i<<1) + (sram_block_cnt<<5);
				temp_reg_D_HistCnt[sram_bin_base] = ich1_hist_in_data_reg.ch1_c0_hist00;
				temp_reg_D_HistCnt[sram_bin_base+1] = ich1_hist_in_data_reg.ch1_c0_hist01;
#if 0
				if((cnt_dISR%600==0)&&(Start_Print.HIST==TRUE)) {
					ROSPrintf("[%d]=%d, [%d]=%d \n",sram_bin_base,temp_reg_D_HistCnt[sram_bin_base],(sram_bin_base+1),temp_reg_D_HistCnt[sram_bin_base+1]);
				}
#endif
			}
		}

		/*o----avoide to read wrong Histogram !!----o*/
		if( sram_block_cnt_th == 4 ){
			d_ich1_hist_read_ctr_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_READ_CTR_reg);
			if(d_ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag == 1){
				if((cnt_dISR%120==0)&&(Start_Print.HIST==TRUE)) {
					//ROSPrintf("Warring!!! inconsistent frame for D-histogram Reading !! (%d) \n",cnt);
				}
				return; // wait until next ISR
			}
		}

		if( Hist_Total_Bin != COLOR_D_HISTOGRAM_LEVEL ){
			if((cnt_dISR%120==0)&&(Start_Print.HIST==TRUE)) {
				//ROSPrintf("Get_Ddomain_Y_histogram !! \n");
				//ROSPrintf("Warring!!! Bin_Mode setting not match with D-HISTOGRAM_LEVEL !! \n");
			}
		}

		/*o----Read finish and move to SmartPic_clue----o*/
		for(i=0; i<Hist_Total_Bin; i++){
			reg_HistCnt[i] = temp_reg_D_HistCnt[i];
#if 0
			if(cnt_dISR%600==0) {
				ROSPrintf("D_HistCnt[%d]=%d \n",i,temp_reg_D_HistCnt[i]);
			}
#endif
		}
#if 0
		if(cnt_dISR%600==0) {
			ROSPrintf("read_timer=%d (cnt=%d)\n",read_timer, MA_print_count);
		}
#endif
		read_timer = timeout;
	} else if(channel == SLR_SUB_DISPLAY){
		//need to fix sub channel
	}
}
#endif



unsigned int temp_reg_I_HistCnt[COLOR_HISTOGRAM_LEVEL];//avoid stack overflow
void drvif_color_Get_Idomain_Y_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned int *reg_HistCnt)
{

	unsigned int i = 0, sram_block_cnt = 0;
	unsigned int baseAddress = 0;
	unsigned char sram_block_cnt_th = 0;
	unsigned char sram_bin_base = 0;
	unsigned char Hist_Total_Bin = 0;

	const unsigned char timeout = 255;
	static unsigned char read_timer = timeout;
	static unsigned int cnt = 0;
	cnt++;

	if(channel>SLR_SUB_DISPLAY){ //prevent the channel selection error!

		channel = SLR_MAIN_DISPLAY;
	}

	if(channel == SLR_MAIN_DISPLAY){

		histogram_ich1_hist_read_ctr_RBUS ich1_hist_read_ctr_Reg;
		histogram_ich1_hist_in_cselect_RBUS ich1_hist_in_cselect_Reg;
		ich1_hist_read_ctr_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_READ_CTR_reg);
		ich1_hist_in_cselect_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg);

		if(ich1_hist_in_cselect_Reg.bin_mode == 0){
			sram_block_cnt_th = 1;
			Hist_Total_Bin = 32;
		} else {
			sram_block_cnt_th = 4;
			Hist_Total_Bin = 128;

			if( ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag == 1 ){
				ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag = 1;
				rtd_outl(HISTOGRAM_ICH1_Hist_READ_CTR_reg,ich1_hist_read_ctr_Reg.regValue);
			}

		}

		// Read ich1_hist_in_data_01_00_reg once a time can speed up by caching mechanism.
		// And because the structure of ich1_hist_in_data_01_00_reg ~ ich1_hist_in_data_31_30_reg are all the same,
		// we can declare ich1_hist_in_data_01_00_reg only for reduce the number of variable.
		histogram_ich1_c0_hist_in_data_01_00_RBUS	ich1_hist_in_data_reg;

		if( C_Channel_select == 0){
			baseAddress = HISTOGRAM_ICH1_C0_Hist_IN_Data_01_00_reg;
		} else if ( C_Channel_select == 1 )  {
			baseAddress = HISTOGRAM_ICH1_C1_Hist_IN_Data_01_00_reg;
		}
#if 0
		if(MA_print_count%300==0) {
			ich1_hist_read_ctr_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_HIST_READ_CTR_reg);
			ROSPrintf("1.drvif_color_Get_Idomain_Y_histogram(%d,%d)\n",read_timer,ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag);
		}
#endif

		for(sram_block_cnt=0; sram_block_cnt<sram_block_cnt_th; sram_block_cnt++){

			/*o----init the read setting for hist sram---o*/
			ich1_hist_read_ctr_Reg.ch1_sram_block = sram_block_cnt;
			rtd_outl(HISTOGRAM_ICH1_Hist_READ_CTR_reg,ich1_hist_read_ctr_Reg.regValue);
			ich1_hist_read_ctr_Reg.ch1_sram_read = 1;
			rtd_outl(HISTOGRAM_ICH1_Hist_READ_CTR_reg,ich1_hist_read_ctr_Reg.regValue);

			/*o----check sram read status and avoide the infinite loop !!----o*/
			do{
				ich1_hist_read_ctr_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_READ_CTR_reg);
				read_timer--;

				if( read_timer == 0 ){
					read_timer = timeout;
					if((MA_print_count%120==0)&&(Start_Print.HIST==TRUE)) {
						//ROSPrintf("2.Warring!!! I-histogram Reading timeout, sram_read !=0 !! \n");
					}
					return; // wait until next ISR
				}
			}while(ich1_hist_read_ctr_Reg.ch1_sram_read == 1);

			/*o----Read histogram ----o*/
			for(i=0; i<COLOR_HISTOGRAM_DATA_BIN_NUM; i++){
				ich1_hist_in_data_reg.regValue = scaler_rtd_inl(baseAddress + i*4);
				sram_bin_base = (i<<1) + (sram_block_cnt<<5);
				temp_reg_I_HistCnt[sram_bin_base] = ich1_hist_in_data_reg.ch1_c0_hist00;
				temp_reg_I_HistCnt[sram_bin_base+1] = ich1_hist_in_data_reg.ch1_c0_hist01;
#if 0
				if(MA_print_count%300==0) {
					ROSPrintf("(%d, %d), sram_bin_base=%d \n",i,sram_block_cnt, sram_bin_base);
					ROSPrintf("[%d]=%d, [%d]=%d \n",sram_bin_base,temp_reg_HistCnt[sram_bin_base],(sram_bin_base+1),temp_reg_HistCnt[sram_bin_base+1]);
				}
#endif
			}
		}

		/*o----avoide to read wrong Histogram !!----o*/
		if( sram_block_cnt_th == 4 ){
			ich1_hist_read_ctr_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_READ_CTR_reg);
			if(ich1_hist_read_ctr_Reg.ch1_sram_read_consistent_flag == 1){
				if((MA_print_count%500==0)&&(Start_Print.HIST==TRUE)) {
					  //ROSPrintf("Warring!!! inconsistent frame for I-Histogram Reading(%d) !! \n",cnt);
				}
				return; // wait until next ISR
			}

		}

		if( Hist_Total_Bin != COLOR_HISTOGRAM_LEVEL ){
			if((MA_print_count%120==0)&&(Start_Print.HIST==TRUE)) {
				//ROSPrintf("Warring!!! Bin_Mode setting not match with HISTOGRAM_LEVEL !! \n");
			}
		}

		/*o----Read finish and move to SmartPic_clue----o*/
		for(i=0; i<Hist_Total_Bin; i++){
			reg_HistCnt[i] = temp_reg_I_HistCnt[i];
#if 0
			if(MA_print_count%300==0) {
				ROSPrintf("I_HistCnt[%d]=%d \n",i,temp_reg_I_HistCnt[i]);
			}
#endif
		}
#if 0
		if(MA_print_count%300==0) {
			ROSPrintf("read_timer=%d (cnt=%d)\n",read_timer, MA_print_count);
		}
#endif
		read_timer = timeout;
	} else if(channel == SLR_SUB_DISPLAY){
		//need to fix sub channel
	}

}


#else
void drvif_color_Get_Y_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned int *reg_HistCnt)
{
	if(channel>SLR_SUB_DISPLAY || channel<SLR_MAIN_DISPLAY)//prevent the channel selection error!
	{
		channel = SLR_MAIN_DISPLAY;
	}

	if(channel == SLR_MAIN_DISPLAY)
	{
		if( C_Channel_select == 0)
		{

			// Read ich1_hist_in_data_01_00_reg once a time can speed up by caching mechanism.
			// And because the structure of ich1_hist_in_data_01_00_reg ~ ich1_hist_in_data_31_30_reg are all the same,
			// we can declare ich1_hist_in_data_01_00_reg only for reduce the number of variable.
			histogram_ich1_c0_hist_in_data_01_00_RBUS	ich1_hist_in_data_reg;

			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_01_00_reg);
			reg_HistCnt[0]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[1]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_03_02_reg);
			reg_HistCnt[2]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[3]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_05_04_reg);
			reg_HistCnt[4]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[5]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_07_06_reg);
			reg_HistCnt[6]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[7]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_09_08_reg);
			reg_HistCnt[8]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[9]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_11_10_reg);
			reg_HistCnt[10]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[11]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_13_12_reg);
			reg_HistCnt[12]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[13]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_15_14_reg);
			reg_HistCnt[14]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[15]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_17_16_reg);
			reg_HistCnt[16]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[17]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_19_18_reg);
			reg_HistCnt[18]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[19]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_21_20_reg);
			reg_HistCnt[20]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[21]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_23_22_reg);
			reg_HistCnt[22]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[23]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_25_24_reg);
			reg_HistCnt[24]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[25]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_27_26_reg);
			reg_HistCnt[26]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[27]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_29_28_reg);
			reg_HistCnt[28]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[29]=ich1_hist_in_data_reg.ch1_c0_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_HIST_IN_DATA_31_30_reg);
			reg_HistCnt[30]=ich1_hist_in_data_reg.ch1_c0_hist00;
			reg_HistCnt[31]=ich1_hist_in_data_reg.ch1_c0_hist01;

		}
		else if( C_Channel_select == 1)
		{

			// Read ich1_hist_in_data_01_00_reg once a time can speed up by caching mechanism.
			// And because the structure of ich1_hist_in_data_01_00_reg ~ ich1_hist_in_data_31_30_reg are all the same,
			// we can declare ich1_hist_in_data_01_00_reg only for reduce the number of variable.
			histogram_ich1_c1_hist_in_data_01_00_RBUS	ich1_hist_in_data_reg;

			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_01_00_reg);
			reg_HistCnt[0]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[1]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_03_02_reg);
			reg_HistCnt[2]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[3]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_05_04_reg);
			reg_HistCnt[4]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[5]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_07_06_reg);
			reg_HistCnt[6]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[7]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_09_08_reg);
			reg_HistCnt[8]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[9]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_11_10_reg);
			reg_HistCnt[10]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[11]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_13_12_reg);
			reg_HistCnt[12]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[13]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_15_14_reg);
			reg_HistCnt[14]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[15]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_17_16_reg);
			reg_HistCnt[16]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[17]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_19_18_reg);
			reg_HistCnt[18]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[19]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_21_20_reg);
			reg_HistCnt[20]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[21]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_23_22_reg);
			reg_HistCnt[22]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[23]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_25_24_reg);
			reg_HistCnt[24]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[25]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_27_26_reg);
			reg_HistCnt[26]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[27]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_29_28_reg);
			reg_HistCnt[28]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[29]=ich1_hist_in_data_reg.ch1_c1_hist01;
			ich1_hist_in_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_HIST_IN_DATA_31_30_reg);
			reg_HistCnt[30]=ich1_hist_in_data_reg.ch1_c1_hist00;
			reg_HistCnt[31]=ich1_hist_in_data_reg.ch1_c1_hist01;

		}
	}
	else if(channel == SLR_SUB_DISPLAY)
	{
		//need to fix sub channel in next chip (Mag_2)
	}
	else // check the channel selection
	{
		if(MA_print_count%100==0)
		{
			ROSPrintf("Warring!!! Please check the histogram channel number\n");
			ROSPrintf("channel=%d\n",channel);
		}
	}

}
#endif


void drvif_color_Get_Section_histogram(unsigned char channel, unsigned char C_Channel_select, unsigned char Section_Select, unsigned char Section_bin_Select, unsigned int *Section_Hist)
{
	if(channel>SLR_SUB_DISPLAY) {//prevent the channel selection error!
		channel = SLR_MAIN_DISPLAY;
	}

	/*select Display channel*/
	if(channel == SLR_MAIN_DISPLAY){

		histogram_ich1_hist_in_cselect_RBUS ich1_hist_in_cselect_Reg;
		ich1_hist_in_cselect_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg);

		/*select Hist channel*/
		if( C_Channel_select == 0) {
			histogram_ich1_c0_sectionhist_in_cselect_RBUS ich1_sectionhist_in_cselect_reg;
			ich1_sectionhist_in_cselect_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg);

			/*select section channel*/
			if(Section_Select==0) {
				/*select bin of section*/
				ich1_sectionhist_in_cselect_reg.ch1_c0_section0_bin_sel = Section_bin_Select;
				scaler_rtd_outl(HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg,ich1_sectionhist_in_cselect_reg.regValue);
				histogram_ich1_c0_section0_data_01_00_RBUS ich1_section_hist_data_reg;
				ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section0_Data_01_00_reg);
				Section_Hist[0] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist00;
				Section_Hist[1] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist01;

				if( ich1_hist_in_cselect_Reg.bin_mode == 0 ){
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section0_Data_03_02_reg);
					Section_Hist[2] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist00;
					Section_Hist[3] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section0_Data_05_04_reg);
					Section_Hist[4] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist00;
					Section_Hist[5] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section0_Data_07_06_reg);
					Section_Hist[6] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist00;
					Section_Hist[7] = ich1_section_hist_data_reg.ch1_c0_section_his0_hist01;
				} else {
					Section_Hist[2] = 0;
					Section_Hist[3] = 0;
					Section_Hist[4] = 0;
					Section_Hist[5] = 0;
					Section_Hist[6] = 0;
					Section_Hist[7] = 0;
				}
			} else if(Section_Select==1) {
				/*select bin of section*/
				ich1_sectionhist_in_cselect_reg.ch1_c0_section1_bin_sel = Section_bin_Select;
				scaler_rtd_outl(HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg,ich1_sectionhist_in_cselect_reg.regValue);
				histogram_ich1_c0_section1_data_01_00_RBUS ich1_section_hist_data_reg;
				ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section1_Data_01_00_reg);
				Section_Hist[0] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist00;
				Section_Hist[1] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist01;
				if( ich1_hist_in_cselect_Reg.bin_mode == 0 ){
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section1_Data_03_02_reg);
					Section_Hist[2] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist00;
					Section_Hist[3] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section1_Data_05_04_reg);
					Section_Hist[4] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist00;
					Section_Hist[5] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C0_Section1_Data_07_06_reg);
					Section_Hist[6] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist00;
					Section_Hist[7] = ich1_section_hist_data_reg.ch1_c0_section_his1_hist01;
				} else {
					Section_Hist[2] = 0;
					Section_Hist[3] = 0;
					Section_Hist[4] = 0;
					Section_Hist[5] = 0;
					Section_Hist[6] = 0;
					Section_Hist[7] = 0;
				}
			}

		} else if(C_Channel_select == 1) {

			histogram_ich1_c1_sectionhist_in_cselect_RBUS ich1_sectionhist_in_cselect_reg;
			ich1_sectionhist_in_cselect_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg);

			/*select section channel*/
			if(Section_Select==0) {
				/*select bin of section*/
				ich1_sectionhist_in_cselect_reg.ch1_c1_section0_bin_sel = Section_bin_Select;
				scaler_rtd_outl(HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg,ich1_sectionhist_in_cselect_reg.regValue);

				histogram_ich1_c1_section0_data_01_00_RBUS ich1_section_hist_data_reg;

				ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section0_Data_01_00_reg);
				Section_Hist[0] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist00;
				Section_Hist[1] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist01;
				ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section0_Data_03_02_reg);
				if( ich1_hist_in_cselect_Reg.bin_mode == 0 ){
					Section_Hist[2] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist00;
					Section_Hist[3] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section0_Data_05_04_reg);
					Section_Hist[4] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist00;
					Section_Hist[5] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section0_Data_07_06_reg);
					Section_Hist[6] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist00;
					Section_Hist[7] = ich1_section_hist_data_reg.ch1_c1_section_his0_hist01;
				} else {
					Section_Hist[2] = 0;
					Section_Hist[3] = 0;
					Section_Hist[4] = 0;
					Section_Hist[5] = 0;
					Section_Hist[6] = 0;
					Section_Hist[7] = 0;
				}
			} else if(Section_Select==1) {
				/*select bin of section*/
				ich1_sectionhist_in_cselect_reg.ch1_c1_section1_bin_sel = Section_bin_Select;
				scaler_rtd_outl(HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg,ich1_sectionhist_in_cselect_reg.regValue);

				histogram_ich1_c1_section1_data_01_00_RBUS ich1_section_hist_data_reg;

				ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section1_Data_01_00_reg);
				Section_Hist[0] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist00;
				Section_Hist[1] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist01;
				ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section1_Data_03_02_reg);
				if( ich1_hist_in_cselect_Reg.bin_mode == 0 ){
					Section_Hist[2] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist00;
					Section_Hist[3] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section1_Data_05_04_reg);
					Section_Hist[4] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist00;
					Section_Hist[5] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist01;
					ich1_section_hist_data_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_C1_Section1_Data_07_06_reg);
					Section_Hist[6] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist00;
					Section_Hist[7] = ich1_section_hist_data_reg.ch1_c1_section_his1_hist01;
				} else {
					Section_Hist[2] = 0;
					Section_Hist[3] = 0;
					Section_Hist[4] = 0;
					Section_Hist[5] = 0;
					Section_Hist[6] = 0;
					Section_Hist[7] = 0;
				}
			}
		}


	} else if(channel == SLR_SUB_DISPLAY) {
		//need to fix sub channel in next chip (Mag_2)
	}

}


void drvif_color_DCC_Curve_Blending(unsigned char channel,unsigned char bin,unsigned int *Adavance_Control_Curve_Blending_info,unsigned int *Adavance_Control_info)
{
	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();

	if(SmartPic_clue == NULL) {
		if(MA_print_count%360==0)
			ROSPrintf("drvif_color_DCC_Curve_Blending Share Memory PQ data ERROR,SmartPic_clue = %x, \n",SmartPic_clue);
		return;
	}

	unsigned int SC_Thl;
	unsigned char diff =0;
	static unsigned char Pre_mean_value=0;
	unsigned char SC_th_ratio = 0;

	SC_th_ratio = 24;//default : 24 means 75%, per step +-(3.125%)
	SC_Thl= ((SmartPic_clue->Hist_Y_Total_sum)*SC_th_ratio)>>5;  //SC Threshold

	diff = abs((SmartPic_clue->Hist_Y_Mean_Value)-Pre_mean_value);

	static unsigned int DCC_mean_pre = 0;
	static char DCC_dev_pre = 0;
	unsigned int mean_diff = 0;
	unsigned int dev_diff = 0;

	//=== DCC  mean value ===
	mean_diff = abs(Adavance_Control_info[DCC_mean_no_debounce] - DCC_mean_pre);
	Adavance_Control_Curve_Blending_info[DCC_mean_diff] = mean_diff;

	//=== DCC Histogram variance ===
	dev_diff = abs(Adavance_Control_info[DCC_Dev_no_debounce] - DCC_dev_pre);
	Adavance_Control_Curve_Blending_info[DCC_Dev_diff] = dev_diff;

	if((Adavance_Control_Curve_Blending_info[DCC_mean_diff]>=5) && (Adavance_Control_Curve_Blending_info[DCC_Dev_diff]>=4))
		SmartPic_clue->SceneChange_by_diff_mean_Dev = 1;
	else
		SmartPic_clue->SceneChange_by_diff_mean_Dev = 0;


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		ROSPrintf("====================================================\n");
		ROSPrintf("diff=%d , mean=%d, Pre_mean= %d\n",diff,(SmartPic_clue->Hist_Y_Mean_Value), Pre_mean_value);

		ROSPrintf("mean_diff=%d , dev_diff=%d\n",mean_diff,dev_diff);
		ROSPrintf("mean_curren = %d, DCC_mean_pre=%d \n",Adavance_Control_info[DCC_mean_no_debounce],DCC_mean_pre);
		ROSPrintf("Dev_current = %d, DCC_dev_pre=%d \n",Adavance_Control_info[DCC_Dev_no_debounce],DCC_dev_pre);
		ROSPrintf("====================================================\n");
	}

	if((Start_Print.Dcc_1==TRUE))
	{
		if((mean_diff!=0) || (dev_diff!=0))
		{
			ROSPrintf(" DCC mean or dev change!!!!\n");
			if((mean_diff>=3) && (dev_diff>=2) )
			{
				ROSPrintf("***********************************************\n");
				ROSPrintf("SceneChange_by_diff_mean_Dev=%d\n",SmartPic_clue->SceneChange_by_diff_mean_Dev);
				ROSPrintf("diff=%d , mean=%d, Pre_mean= %d\n",diff,(SmartPic_clue->Hist_Y_Mean_Value), Pre_mean_value);
				ROSPrintf("mean_diff=%d , dev_diff=%d\n",mean_diff,dev_diff);
				ROSPrintf("mean_curren = %d, DCC_mean_pre=%d \n",Adavance_Control_info[DCC_mean_no_debounce],DCC_mean_pre);
				ROSPrintf("Dev_current = %d, DCC_dev_pre=%d \n",Adavance_Control_info[DCC_Dev_no_debounce],DCC_dev_pre);
				ROSPrintf("***********************************************\n");
			}
		}
	}


	Pre_mean_value = (SmartPic_clue->Hist_Y_Mean_Value);
	DCC_mean_pre = Adavance_Control_info[DCC_mean_no_debounce];
	DCC_dev_pre = Adavance_Control_info[DCC_Dev_no_debounce];

}
#ifdef CONFIG_HW_SUPPORT_D_HISTOGRAM
unsigned char scalerVIP_color_D_Hist_Get_APL(unsigned char channel, unsigned int *pHist_Y_APL)
{
	unsigned short width, height;
	unsigned int totalPixel = 0;
	unsigned long long sumval = 0, apl;
	_clues* SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_system_setting_info* system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	if (SmartPic_clue == NULL || system_info_structure_table == NULL)
		return FALSE;

	if (channel == SLR_MAIN_DISPLAY)
	{
		d_histogram_d_ich1_hist_sumval_low_RBUS d_ich1_hist_sumval_low_reg;
		d_histogram_d_ich1_hist_sumval_high_RBUS d_ich1_hist_sumval_high_reg;

		d_ich1_hist_sumval_low_reg.regValue = scaler_rtd_inl(D_HISTOGRAM_D_ICH1_Hist_SumVal_Low_reg);
		d_ich1_hist_sumval_high_reg.regValue = scaler_rtd_inl(D_HISTOGRAM_D_ICH1_Hist_SumVal_High_reg);

		scalerDCC_get_D_hist_window(&width, &height);
		totalPixel = width*height;
		/*totalPixel = ((system_info_structure_table->D_Width>>8)+((system_info_structure_table->D_Width&0xff)<<8))
			*((system_info_structure_table->D_Height>>8)+((system_info_structure_table->D_Height&0xff)<<8));*/

		if (totalPixel == 0)
		{
			SmartPic_clue->D_Hist_Y_APL_Exact = 0;
			if (pHist_Y_APL)
				*pHist_Y_APL = SmartPic_clue->D_Hist_Y_APL_Exact;
			return FALSE;
		}

		sumval = d_ich1_hist_sumval_high_reg.regValue;
		sumval = (sumval<<24)+d_ich1_hist_sumval_low_reg.regValue;
		apl = (sumval+(totalPixel>>1));
		do_div(apl,totalPixel);
		//apl = (sumval+(totalPixel>>1))/totalPixel;

		if (apl <= 1023)
			SmartPic_clue->D_Hist_Y_APL_Exact = apl;
		else if (SmartPic_clue->D_Hist_Y_APL_Exact > 1023)
			SmartPic_clue->D_Hist_Y_APL_Exact = 512;

		if (pHist_Y_APL)
			*pHist_Y_APL = SmartPic_clue->D_Hist_Y_APL_Exact;

/*
		if(cnt_dISR%300==0)
		{
			ROSPrintf("w%d,h%d,D_Hist_Y_APL = %d\n",
			((system_info_structure_table->D_Width>>8)+((system_info_structure_table->D_Width&0xff)<<8)),
			((system_info_structure_table->D_Height>>8)+((system_info_structure_table->D_Height&0xff)<<8)),
			SmartPic_clue->D_Hist_Y_APL_Exact);
		}
*/


		return TRUE;
	} else {
		return FALSE;
	}
}
#endif

unsigned char scalerVIP_colorHist_Get_APL(unsigned char channel, unsigned int *pHist_Y_APL)
{
	unsigned short width, height;
	unsigned int totalPixel = 0;
	unsigned long long sumval = 0, apl;
	_clues* SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_system_setting_info* system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	if (SmartPic_clue == NULL || system_info_structure_table == NULL)
		return FALSE;

	if (channel == SLR_MAIN_DISPLAY)
	{
		histogram_ich1_hist_sumval_low_RBUS ich1_hist_sumval_low_reg;
		histogram_ich1_hist_sumval_high_RBUS ich1_hist_sumval_high_reg;

		ich1_hist_sumval_low_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_Hist_SumVal_Low_reg);
		ich1_hist_sumval_high_reg.regValue = scaler_rtd_inl(HISTOGRAM_ICH1_Hist_SumVal_High_reg);

		scalerDCC_get_hist_window(&width, &height);
		totalPixel = width*height;
		/*totalPixel = ((system_info_structure_table->Mem_Width>>8)+((system_info_structure_table->Mem_Width&0xff)<<8))
			*((system_info_structure_table->Mem_Height>>8)+((system_info_structure_table->Mem_Height&0xff)<<8));*/

		if (totalPixel == 0)
		{
			SmartPic_clue->Hist_Y_APL_Exact = 0;
			if (pHist_Y_APL)
				*pHist_Y_APL = SmartPic_clue->Hist_Y_APL_Exact;
			return FALSE;
		}

		sumval = ich1_hist_sumval_high_reg.regValue;
		sumval = (sumval<<24)+ich1_hist_sumval_low_reg.regValue;
		apl=sumval+(totalPixel>>1);
		do_div(apl,totalPixel);
		//apl = (sumval+(totalPixel>>1))/totalPixel;

		if (apl <= 1023)
			SmartPic_clue->Hist_Y_APL_Exact = apl;
		else if (SmartPic_clue->Hist_Y_APL_Exact > 1023)
			SmartPic_clue->Hist_Y_APL_Exact = 512;

		if (pHist_Y_APL)
			*pHist_Y_APL = SmartPic_clue->Hist_Y_APL_Exact;

		/*
		if(MA_print_count%300==0){
			ROSPrintf("w%d,h%d,Hist_Y_APL = %d\n",
			((system_info_structure_table->Mem_Width>>8)+((system_info_structure_table->Mem_Width&0xff)<<8)),
			((system_info_structure_table->Mem_Height>>8)+((system_info_structure_table->Mem_Height&0xff)<<8)),
			SmartPic_clue->Hist_Y_APL_Exact);
		}
		*/

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//====================================
//Comments :   Write DCC Table , 201407

void histogram_new_dcc_write_table(unsigned char display, unsigned char Total_Curve_segment, unsigned char double_buffer_mode_on)
{
	_RPC_clues* RPC_SmartPic_clue=NULL;
	RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();

	if(RPC_SmartPic_clue == NULL) {
		if(MA_print_count%360==0)
			ROSPrintf("histogram_new_dcc_write_table Share Memory PQ data ERROR,SmartPic_clue = %x, \n",RPC_SmartPic_clue);
		return;
	}

	int i=0;
	const unsigned char timeout = 10;

	int DCCNum = Total_Curve_segment;
	unsigned char gain =50;

	static unsigned char tab_sel = 0; // table select for double buffer mode
	static unsigned int dcc_histogram_temp[64] = {0};
	static unsigned char index=0;
	static unsigned char write_timer = timeout;
	unsigned short write_timer2 = timeout*gain;
	static unsigned char write_unfinished = false;


	color_dcc_sram_tab_ctl_0_RBUS	 color_dcc_sram_tab_ctl_0_reg;
	if(dcc_histogram_write_flag == TRUE)
	{
		//write sram table init setting
		color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_index = index;
		color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 1;
		color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel = tab_sel;  //  // TODO: double buffer mechanism on 2 tables
		rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);

		// Curve Change Process
		if( (write_unfinished == false)|| (RPC_SmartPic_clue->SceneChange==1)) // modify new Curve for writing
		{
			index = 0;

			for( i=0; i<DCCNum; i++ )
			{
				dcc_histogram_temp[i] = dcc_histogram_to_write[i];
			}

			color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);

			if(RPC_SmartPic_clue->SceneChange)
			{
				write_timer = write_timer*gain;
			}

			do
			{
				write_timer--;
				if( write_timer == 0 )
				{
					if(MA_print_count%180==0)
					{
						ROSPrintf("1.DCC SRAM timeout! %d, %d\n",MA_print_count);
					}

					color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
					color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
					rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);
					write_timer = timeout;
					return; // wait until next ISR
				}

			}while(color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_ready != 1);

			write_timer = timeout;

		}


		//=== Curve Apply Process ====
		for( i=index; i<DCCNum; i++ )
		{

			do
			{
				write_timer2 --;
				color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				if(write_timer2==0)
				{
					index = i; // store current progress
					//if(MA_print_count%180==0)
					{
						ROSPrintf("2.DCC SRAM timeout! %d, %d\n",MA_print_count);
					}

					color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
					color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
					rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);

					write_unfinished = true;
					write_timer2=timeout*gain;

					return;
				}

			}while((color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_ready != 1));

			write_timer2=timeout*gain;

			color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);

			if(i != color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_index_cur)     //cur != index
			{
				do
				{
					write_timer--;
					if( write_timer == 0 )
					{

						index = i; // store current progress
						//if(MA_print_count%180==0)
						{
							ROSPrintf("3.DCC SRAM timeout! %d, %d\n",MA_print_count);
						}

						color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
						color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
						rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);

						write_unfinished = true;
						write_timer= timeout;

						return; // wait until next ISR
					}

					color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				}while((index != color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_index_cur));

				rtdf_outl(COLOR_DCC_SRAM_TAB_PORT_reg, dcc_histogram_temp[i]);

			}
			else	//cur = index
			{
				rtdf_outl(COLOR_DCC_SRAM_TAB_PORT_reg, dcc_histogram_temp[i]);
			}

			write_timer = timeout;

		}


		// get to this point -> write finished
		write_unfinished = false;
		write_timer = timeout;
		write_timer2 = timeout*gain;

		color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
		rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);

	}

	dcc_histogram_write_flag = FALSE;

}

//====================================



#if 1

/**
 * histogram_new_dcc_write_table
 * This function is used to write DCC table at D-domain porch.
 *
 * @param { channel: main ro sub }
 * @param { osd_level: RTNR level }
 * @return { void }
 *
 */

//====================================
//==== new DCC histogram III =======

void Driver_DCC_hist_adjust(unsigned char display,unsigned char bin,unsigned int Bef_Total_HCnt,VIP_DCC_Hist_Factor_Table	*Hist_Factor_Table,unsigned int *Aft_Total_HCnt,unsigned int *Hist_Cnt )
{
	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();

	if(SmartPic_clue == NULL) {
		if(MA_print_count%360==0)
			ROSPrintf("Share Memory PQ data ERROR,SmartPic_clue = %x, \n",SmartPic_clue);
		return;
	}

	int i,j;
        unsigned char temp_mapping = 1, temp_mapping_check = 0;
	unsigned int factor_gain_Black   = 0, factor_gain_white	= 0, factor_gain	= 0;
	unsigned int factor_offset_Black = 0, factor_offset_white = 0, factor_offset 	= 0;//range defined : %
	unsigned int factor_limit_Black_Level  = 0, factor_limit_white_Level	= 0, factor_limit_Level	= 0;//adjust range:0~31
	unsigned int factor_limit_Black_Ratio  = 0, factor_limit_white_Ratio	= 0, factor_limit_Ratio	= 0;

	unsigned int hist_cnt_limit =0;

	unsigned short Peak_white=0;
	unsigned short Peak_Dark=0;
	unsigned short APL_value=0;
	Peak_white = (SmartPic_clue->Hist_Peak_White_IRE_Value);
	Peak_Dark = 0;
	APL_value = (SmartPic_clue->Hist_Y_Mean_Value);

	*Aft_Total_HCnt=0;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("hist_adjust, region_index[0]=%d, region_index[1]=%d\n ",(Hist_Factor_Table->Hist_init_coef.bin_th0),(Hist_Factor_Table->Hist_init_coef.bin_th1));
		ROSPrintf("hist_adjust, Hist_Cnt=%d, Aft_Total_HCnt=%d \n",Bef_Total_HCnt,*Aft_Total_HCnt);
		for(i=0;i<(bin);i++)
		{
			ROSPrintf("hist_adjust, (before Adjust)HistCnt[%d]=%d\n ",i,Hist_Cnt[i]);
		}
			//DCCHist_Factor_Table = &(g_Share_Memory_VIP_TABLE_Struct->DCCHist_Factor_Table)[0][0][0];
		for(i=0;i<(Histogram_adjust_bin_num);i++)
		{
			ROSPrintf("hist_adjust, Factor_Table Gain[%d]=%d\n ",i,((Hist_Factor_Table->gain)[i]));
			ROSPrintf("hist_adjust, Factor_Table offset[%d]=%d\n ",i,((Hist_Factor_Table->offset)[i]));
			ROSPrintf("hist_adjust, Factor_Table Limit[%d]=%d\n ",i,((Hist_Factor_Table->limit)[i]));
		}
	}

        temp_mapping_check = (bin%Histogram_adjust_bin_num);

	if(((Hist_Factor_Table->Hist_init_coef.Mode)<2) && (temp_mapping_check == 0)){

		temp_mapping = bin/Histogram_adjust_bin_num;

	if((Hist_Factor_Table->Hist_init_coef.Mode)==0) {
			//for(i=(Hist_Factor_Table->Hist_init_coef.bin_th0);i<(Hist_Factor_Table->Hist_init_coef.bin_th1);i++)
			for(i=0;i<bin;i++) {
				j = i/temp_mapping;
				if( (i>=(Hist_Factor_Table->Hist_init_coef.bin_th0)) && (i<(Hist_Factor_Table->Hist_init_coef.bin_th1))){
			//get Hist adjust factor
					factor_gain			=	((Hist_Factor_Table->gain)[j]);
					factor_offset		=	((Hist_Factor_Table->offset)[j]);
					factor_limit_Level	=	((Hist_Factor_Table->limit)[j]);

			//Gain and Offset
			Hist_Cnt[i] = ((factor_gain*Hist_Cnt[i])/8) + ((Bef_Total_HCnt*factor_offset)/100);
			//get Limit Ratio,
			factor_limit_Ratio = (factor_limit_Level*100)/31; //middle range %, adjust range: 0~31
			//get Limit cnt,
			hist_cnt_limit = (Bef_Total_HCnt*factor_limit_Ratio)/100;

			//Limit condition
					if(Hist_Cnt[i]>=hist_cnt_limit ) {
				Hist_Cnt[i] = hist_cnt_limit;
			}
				}

			*Aft_Total_HCnt+=Hist_Cnt[i];

		}

	}
	else if((Hist_Factor_Table->Hist_init_coef.Mode)==1)//adjust for 3 region: black, middle, dark by 2 region th
	{
		//get black range factor
		factor_gain_Black		=	((Hist_Factor_Table->gain)[0]);
		factor_offset_Black 	=	((Hist_Factor_Table->offset)[0]);
		factor_limit_Black_Level=	((Hist_Factor_Table->limit)[0]);

		//get middle range factor
		factor_gain 		=	((Hist_Factor_Table->gain)[Hist_Factor_Table->Hist_init_coef.bin_th0]);
		factor_offset		=	((Hist_Factor_Table->offset)[Hist_Factor_Table->Hist_init_coef.bin_th0]);
		factor_limit_Level	=	((Hist_Factor_Table->limit)[Hist_Factor_Table->Hist_init_coef.bin_th0]);

		//get white range factor
		factor_gain_white		=	((Hist_Factor_Table->gain)[Hist_Factor_Table->Hist_init_coef.bin_th1]);
		factor_offset_white 	=	((Hist_Factor_Table->offset)[Hist_Factor_Table->Hist_init_coef.bin_th1]);
		factor_limit_white_Level=	((Hist_Factor_Table->limit)[Hist_Factor_Table->Hist_init_coef.bin_th1]);

		//get limit ratio
		factor_limit_Black_Ratio = factor_limit_Black_Level;//(factor_limit_Black_Level*100)/31;//low range %, adjust Level range: 0~31
		factor_limit_white_Ratio = factor_limit_white_Level;//(factor_limit_white_Level*100)/31;//high range %, adjust Level range: 0~31
		factor_limit_Ratio = factor_limit_Level;//(factor_limit_Level*100)/31;			 //middle range %, adjust Level range: 0~31

			for(i=0;i<bin;i++) {

				if(i<(Hist_Factor_Table->Hist_init_coef.bin_th0)) {
				//Gain and Offset
				Hist_Cnt[i] = ((factor_gain_Black*Hist_Cnt[i])/8) + ((Bef_Total_HCnt*factor_offset_Black)/100);
				//get Limit cnt,
				hist_cnt_limit = (Bef_Total_HCnt*factor_limit_Black_Ratio)/100;
				} else if(i>=(Hist_Factor_Table->Hist_init_coef.bin_th1)) {
				//Gain and Offset
				Hist_Cnt[i] = ((factor_gain_white*Hist_Cnt[i])/8) + ((Bef_Total_HCnt*factor_offset_white)/100);
				//get Limit cnt,
				hist_cnt_limit = (Bef_Total_HCnt*factor_limit_white_Ratio)/100;
				} else {
				//Gain and Offset
				Hist_Cnt[i] = ((factor_gain*Hist_Cnt[i])/8) + ((Bef_Total_HCnt*factor_offset)/100);
				//get Limit cnt,
				hist_cnt_limit = (Bef_Total_HCnt*factor_limit_Ratio)/100;
			}

			//Limit condition
				if(Hist_Cnt[i]>=hist_cnt_limit ) {
				Hist_Cnt[i] = hist_cnt_limit;
			}

			*Aft_Total_HCnt+=Hist_Cnt[i];

		}
	}
	} else {

		*Aft_Total_HCnt = Bef_Total_HCnt;
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
			ROSPrintf("[Warning!!][DCC_DCC_hist_adjust]Mode setting = 0!!\n");
			ROSPrintf("[Warning!!][DCC_DCC_hist_adjust]Result: Bypass hist adjust function\n");
		}

		return;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
		ROSPrintf("hist_adjust, Aft_Total_HCnt=%d\n ",*Aft_Total_HCnt);
		for(i=0;i<(bin);i++) {
			ROSPrintf("hist_adjust, (After Adjust)HistCnt[%d]=%d\n ",i,Hist_Cnt[i]);
		}
	}


}

void Driver_DCC_hist_normalized(unsigned char display,unsigned char bin,unsigned int org_Total_HCnt,unsigned int Hist_adjust_Total_HCnt,unsigned int *Hist_Cnt )
{
	int i;
	unsigned int nomalize_count=0;
	nomalize_count = ((org_Total_HCnt<<5)/(Hist_adjust_Total_HCnt+1));

	for(i=0;i<bin;i++)
	{
		Hist_Cnt[i]= (Hist_Cnt[i]*nomalize_count)>>5;
	}
	//o---- check total histcnt ----
	Hist_adjust_Total_HCnt=0;
	for(i=0;i<bin;i++)
	{
		Hist_adjust_Total_HCnt+= Hist_Cnt[i];
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("hist_normalized, org_Total_HCnt=%d,Hist_adjust_Total_HCnt=%d\n ",org_Total_HCnt,Hist_adjust_Total_HCnt);
		ROSPrintf("hist_normalized, nomalize_count=%d\n ",nomalize_count);
		ROSPrintf("hist_normalized, Hist_adjust_Total_HCnt=%d\n ",Hist_adjust_Total_HCnt);
		for(i=0;i<(bin);i++)
		{
			ROSPrintf("hist_normalized, org_HistCnt[%d]=%d\n ",i,Hist_Cnt[i]);
		}
	}

	unsigned int Total_HCnt_diff = 0;
	unsigned int hisfac_Total_HCnt_2=0;
	if(Hist_adjust_Total_HCnt<org_Total_HCnt) // compensate total pixel cnt for histogram_factor gain
	{
		Total_HCnt_diff = org_Total_HCnt - Hist_adjust_Total_HCnt;

		for(i=0;i<bin;i++)
		{
			Hist_Cnt[i] = Hist_Cnt[i] + ((((Hist_Cnt[i]*100)/(Hist_adjust_Total_HCnt+1))*Total_HCnt_diff)/100);
			hisfac_Total_HCnt_2+=	Hist_Cnt[i];
		}
	}
	else if(Hist_adjust_Total_HCnt>org_Total_HCnt)
	{
		Total_HCnt_diff = Hist_adjust_Total_HCnt-org_Total_HCnt ;

		for(i=0;i<bin;i++)
		{
			Hist_Cnt[i] = Hist_Cnt[i] - ((((Hist_Cnt[i]*100)/(Hist_adjust_Total_HCnt+1))*Total_HCnt_diff)/100);
			hisfac_Total_HCnt_2+=	Hist_Cnt[i];
		}

	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("hist_normalized, org_Total_HCnt=%d, Total_HCnt_2=%d \n",org_Total_HCnt,hisfac_Total_HCnt_2);
		for(i=0;i<(bin);i++)
		{
			ROSPrintf("hist_normalized, nor_HistCnt[%d]=%d\n ",i,Hist_Cnt[i]);
		}
	}


}


int Identity_temp[Curve_num_Max];

// == 10 bit Curve ==
int Curve_Identity[Curve_num_Max]=
		{ 0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
		200,208,216,224,232,240,248,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
		400,408,416,424,432,440,448,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
		600,608,616,624,632,640,648,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
		800,808,816,824,832,840,848,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
		1000,1008,1016,1023};
int Curve_Identity_2[Curve_num_Max]=
		{ 0,  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,112,120,128,136,144,152,160,168,176,184,192,
		200,208,216,224,232,240,248,256,264,272,280,288,296,304,312,320,328,336,344,352,360,368,376,384,392,
		400,408,416,424,432,440,448,456,464,472,480,488,496,504,512,520,528,536,544,552,560,568,576,584,592,
		600,608,616,624,632,640,648,656,664,672,680,688,696,704,712,720,728,736,744,752,760,768,776,784,792,
		800,808,816,824,832,840,848,856,864,872,880,888,896,904,912,920,928,936,944,952,960,968,976,984,992,
		1000,1008,1016,1023};


/* == 12 bit Curve ==
int Curve_Identity[Curve_num_Max]=
		{  0,   32,  64,  96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512, 544, 576, 608, 640, 672, 704, 736, 768,
		 800,  832, 864, 896, 928, 960, 992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,
		1600, 1632,1664,1696,1728,1760,1792,1824,1856,1888,1920,1952,1984,2016,2048,2080,2112,2144,2176,2208,2240,2272,2304,2336,2368,
		2400, 2432,2464,2496,2528,2560,2592,2624,2656,2688,2720,2752,2784,2816,2848,2880,2912,2944,2976,3008,3040,3072,3104,3136,3168,
		3200, 3232,3264,3296,3328,3360,3392,3424,3456,3488,3520,3552,3584,3616,3648,3680,3712,3744,3776,3808,3840,3872,3904,3936,3968,
		4000, 4032,4064,4095};

int Curve_Identity_2[Curve_num_Max]=
		{  0,   32,  64,  96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512, 544, 576, 608, 640, 672, 704, 736, 768,
		 800,  832, 864, 896, 928, 960, 992,1024,1056,1088,1120,1152,1184,1216,1248,1280,1312,1344,1376,1408,1440,1472,1504,1536,1568,
		1600, 1632,1664,1696,1728,1760,1792,1824,1856,1888,1920,1952,1984,2016,2048,2080,2112,2144,2176,2208,2240,2272,2304,2336,2368,
		2400, 2432,2464,2496,2528,2560,2592,2624,2656,2688,2720,2752,2784,2816,2848,2880,2912,2944,2976,3008,3040,3072,3104,3136,3168,
		3200, 3232,3264,3296,3328,3360,3392,3424,3456,3488,3520,3552,3584,3616,3648,3680,3712,3744,3776,3808,3840,3872,3904,3936,3968,
		4000, 4032,4064,4095};
*/


void Driver_DCC_Curve_Identity(unsigned char display,unsigned char Curve_bit_num,unsigned char DCC_bin_identity_flag)
{
	_RPC_system_setting_info* RPC_system_info_structure_table = NULL;
	_RPC_clues* RPC_SmartPic_clue = NULL;
	RPC_system_info_structure_table = scaler_GetShare_Memory_RPC_system_setting_info_Struct();
	RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();

	if((RPC_system_info_structure_table == NULL) || (RPC_SmartPic_clue == NULL) ) {
		if(MA_print_count%360==0)
			ROSPrintf("Share Memory PQ data ERROR,system_info = %x,%x \n",RPC_system_info_structure_table, RPC_SmartPic_clue);
		return;
	}
	int i;
	//int timeout = 10;
	int index;
	color_dcc_sram_tab_ctl_0_RBUS 	color_dcc_sram_tab_ctl_0_reg;
	int Data_Path_bit_num = 10;
	unsigned short Base_I=0;
	unsigned short G0_I=0;
	unsigned short G1_I=0;
	int diff_low=0,bound_denominator_factor=0,bound_gain_factor=0;
	int Curve_data_range = 1<<DCC_Curve_DataRang_bit;
	int Curve_segment_range = 1<<DCC_Curve_Segment_bit;

	RPC_Adapt_DCC_Info_Item *pDCC_Adapt_DCC_Info_Item = &(RPC_SmartPic_clue->RPC_Adapt_DCC_Info);

	//o-----modify identity Curve boundary if  DCC_bin_boundary_flag=1-------o
	if(DCC_bin_identity_flag) {
		if(Curve_Identity[Curve_zero_point]>=0) {
			diff_low = (0-Curve_Identity[Curve_zero_point]);
		} else {
			diff_low = (0+Curve_Identity[Curve_zero_point]);
		}
		bound_gain_factor = DataRange_MAX;
		bound_denominator_factor = Curve_Identity[Curve_max_point]+diff_low;

		if(bound_denominator_factor==0)
			bound_denominator_factor = bound_denominator_factor+1;

		for(i=0;i<(Curve_num_Max);i++) {
			if(i<Curve_zero_point){
				Identity_temp[i]=0;
			} else if(i>Curve_max_point) {
				Identity_temp[i]=DataRange_MAX;
			} else {
				Identity_temp[i] = (Curve_Identity[i]+diff_low)*bound_gain_factor;
				Identity_temp[i] = Identity_temp[i]/bound_denominator_factor;
			}

			Curve_Identity[i]= Identity_temp[i];
			pDCC_Adapt_DCC_Info_Item->Apply_Curve[i] = Curve_Identity[i];
		}
	} else {
		G0_I=(1<<Data_Path_bit_num)>>(Curve_bit_num);
		G1_I=(1<<Data_Path_bit_num)>>(Curve_bit_num);

		for(i=0;i<(Curve_num_Max);i++) {
			pDCC_Adapt_DCC_Info_Item->Apply_Curve[i] = i*G0_I;
		}
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		ROSPrintf("Driver_DCC_Curve_Identity");
	}

	dcc_histogram_write_flag = TRUE;
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	RPC_system_info_structure_table->SCPU_ISRIINFO_TO_VCPU.DCC_Curve_apply_flag = dcc_histogram_write_flag;
#endif
		
#if 0
	color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
	color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_index = 0;
	color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 1;
	color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel = 0;
	rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);
	index = -1;
	for(i = 0; i < TableSeg_num_Max; i++)
	{
		//Identity Curve defined
		if(DCC_bin_identity_flag)
		{
			if(i==0)
			{
				Base_I = (Curve_Identity[0]+Curve_data_range)%Curve_data_range;
			}
			else
			{
				Base_I = Curve_Identity[i<<1]%Curve_data_range;
			}
			G0_I = (Curve_Identity[(i<<1)+1] - Curve_Identity[i<<1])%Curve_segment_range;
			G1_I = (Curve_Identity[(i<<1)+2] - Curve_Identity[(i<<1)+1])%Curve_segment_range;
		}
		else
		{
			Base_I=i*(G0_I+G1_I)-1;
		}

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
		{
			ROSPrintf("[DCC]i=%d,Base_I=%d,G0_I=%d,G1_I=%d\n",i,Base_I,G0_I,G1_I);
		}

		dcc_histogram_to_write[i] = ((Base_I<<16)+(G0_I<<8)+G1_I);/*Mac5p ---> 10bits*/
		//dcc_histogram_to_write[i] = ((Base_I<<20)+(G0_I<<10)+G1_I);//Magellan2 --> 10bit to 12bit
		dcc_histogram_write_flag = TRUE;
		#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
		RPC_system_info_structure_table->SCPU_ISRIINFO_TO_VCPU.DCC_Curve_apply_flag = dcc_histogram_write_flag;
		#endif


		#if 0

		//o---- write DCC SRAM Table ----o
		color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		while(color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_ready != 1)
		{
			timeout--;
			if(timeout < 0)
			{
				ROSPrintf("DCC SRAM time out!\n");
				color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
				rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);
				return;
			}
			color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		}
		index++;
		if(index != color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_index_cur)     //cur = index
		{
			ROSPrintf("DCC SRAM index error!\n");
			color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
			color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
			rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);
			return;
		}
		rtdf_outl(COLOR_DCC_SRAM_TAB_PORT_reg, ((Base_I<<16)+(G0_I<<8)+G1_I));

		#endif


	}
#endif	
/*
	color_dcc_sram_tab_ctl_0_reg.regValue = rtdf_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
	color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
	rtdf_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);
*/
}


void Driver_DCC_Histogram_HighRes_Boundary_check(unsigned char display,unsigned char DCC_SC,unsigned char bin,unsigned int org_Total_HCnt,VIP_DCC_Boundary_check_Table *Boundary_check_Table,unsigned int *Hist_Cnt,unsigned char *Black_boundary_bin_num,unsigned char *white_boundary_bin_num, unsigned char Temp_Curve_num_gain)
{

    int i = 0;
//    unsigned int cnt_check=0;
    unsigned int black_cnt = 0, white_cnt = 0;
    unsigned int Black_th0 = 0, Black_th1 = 0;
    unsigned int white_th0 = 0, white_th1 = 0;

    unsigned short BlackSeg0Cnt = 0, BlackSeg1Cnt = 0;
    unsigned short WhiteSeg0Cnt = 0, WhiteSeg1Cnt = 0;

    short black_bin_seg0 = -1, black_bin_seg1 = -1;
    short white_bin_seg0 = -1, white_bin_seg1 = -1;

    static short black_bin_seg0_pre = 0, black_bin_seg1_pre = 0;
    static short white_bin_seg0_pre = 0, white_bin_seg1_pre = 0;

    static short black_bin_debounce0 = 32, black_bin_debounce1 = 32;
    static short white_bin_debounce0 = 32, white_bin_debounce1 = 32;

    Black_th0 = ( (Boundary_check_Table->Black_th_ratio_seg0)*org_Total_HCnt) >> 10;
    Black_th1 = ( (Boundary_check_Table->Black_th_ratio_seg1)*org_Total_HCnt) >> 10;
    white_th0 = ( (Boundary_check_Table->white_th_ratio_seg0)*org_Total_HCnt) >> 10;
    white_th1 = ( (Boundary_check_Table->white_th_ratio_seg1)*org_Total_HCnt) >> 10;

    BlackSeg0Cnt = Boundary_check_Table->Black_Bounday_seg1_limit *   Temp_Curve_num_gain; // limited range for black seg 0
    BlackSeg1Cnt = Boundary_check_Table->Black_Bounday_search_range * Temp_Curve_num_gain; // limited range for black seg 1
    WhiteSeg0Cnt = Boundary_check_Table->white_Bounday_seg1_limit *   Temp_Curve_num_gain; // limited range for white seg 0
    WhiteSeg1Cnt = Boundary_check_Table->white_Bounday_search_range * Temp_Curve_num_gain; // limited range for white seg 1

    // debug msg
/*
    if( Start_Print.VD_LOG_ENABLE == TRUE && MA_print_count%debug_print_delay_time==0 )
    {
        ROSPrintf("/---------------- BOUNDARY CHECK ----------------/\n");
        ROSPrintf("OriTotalCnt=%d\n\n",org_Total_HCnt);
        ROSPrintf("Black ratio seg0 = [%d], seg1 = [%d]\n" ,Boundary_check_Table->Black_th_ratio_seg0, Boundary_check_Table->Black_th_ratio_seg1);
        ROSPrintf("Black th0 = [%d], Black th1 = [%d]\n", Black_th0, Black_th1);
        ROSPrintf("Black limit seg0 = [%d], seg1 = [%d]\n", BlackSeg0Cnt, BlackSeg1Cnt);
        ROSPrintf("Black debounced threshold = [%d]\n\n", Boundary_check_Table->Bin_debounce_th_Black);

        ROSPrintf("White ratio seg0 = [%d], seg1 = [%d]\n", Boundary_check_Table->white_th_ratio_seg0, Boundary_check_Table->white_th_ratio_seg1);
        ROSPrintf("White th0 = [%d], white th1 = [%d]\n ", white_th0, white_th1);
        ROSPrintf("White limit seg0 = [%d], seg1 = [%d]\n", WhiteSeg0Cnt, WhiteSeg1Cnt);
        ROSPrintf("White debounced threshold = [%d]\n\n", Boundary_check_Table->Bin_debounce_th_white);
    }
*/

    //-------------------------------
    //---------- black boundary check

    // avoid setting error
    if( Black_th1 < Black_th0 )
    {
        Black_th1 = Black_th0;
    }
    if( BlackSeg1Cnt < BlackSeg0Cnt )
    {
        BlackSeg1Cnt = BlackSeg0Cnt;
    }
    Black_boundary_bin_num[0] = 0;
    Black_boundary_bin_num[1] = 0;

    black_cnt = 0;
    for( i=0; i<BlackSeg1Cnt; i++)
    {
        black_cnt += Hist_Cnt[i];
        if( (black_cnt <= Black_th0) && (i < BlackSeg0Cnt) )
        {
            Black_boundary_bin_num[0] = i;
        }
        if( black_cnt <= Black_th1 )
        {
            Black_boundary_bin_num[1] = i;
        }
    }
    Black_boundary_bin_num[0] = Black_boundary_bin_num[0] + 1; // willy 20150707, to fit the normal boundary check
    if( Black_boundary_bin_num[0] > Black_boundary_bin_num[1] )
    {
        Black_boundary_bin_num[0] = Black_boundary_bin_num[1];
    }

    //o----- debounce -----o
    black_bin_seg0 = Black_boundary_bin_num[0];
    black_bin_seg1 = Black_boundary_bin_num[1];
    if(DCC_SC)
    {
        black_bin_seg0_pre = black_bin_seg0;
        black_bin_seg1_pre = black_bin_seg1;
    }

    if( black_bin_seg0 != black_bin_seg0_pre )
    {
        black_bin_debounce0 -= abs(black_bin_seg0-black_bin_seg0_pre);

        if(black_bin_debounce0 <= 0 )
        {
            black_bin_debounce0 = (Boundary_check_Table->Bin_debounce_th_Black); // assign a new number?
            black_bin_seg0_pre = black_bin_seg0;
        }
        else
        {
            black_bin_seg0 = black_bin_seg0_pre;
        }
    }
    else
    {
        black_bin_debounce0++;
        if(black_bin_debounce0 > (Boundary_check_Table->Bin_debounce_th_Black))
            black_bin_debounce0 = (Boundary_check_Table->Bin_debounce_th_Black);
    }


    if( black_bin_seg1 != black_bin_seg1_pre )
    {
        black_bin_debounce1 -= abs(black_bin_seg1-black_bin_seg1_pre);
        if(black_bin_debounce1 <= 0 )
        {
            black_bin_debounce1 =  (Boundary_check_Table->Bin_debounce_th_Black);
            black_bin_seg1_pre = black_bin_seg1;
        }
        else
        {
            black_bin_seg1 = black_bin_seg1_pre;
        }
    }
    else
    {
        black_bin_debounce1++;
        if(black_bin_debounce1 > (Boundary_check_Table->Bin_debounce_th_Black))
            black_bin_debounce1 = (Boundary_check_Table->Bin_debounce_th_Black);
    }
    //o-----------------o

    Black_boundary_bin_num[0] = black_bin_seg0;
    Black_boundary_bin_num[1] = black_bin_seg1;
    //------------------------------- end of black boundary check

    //-------------------------------
    // white boundary check

    // avoid setting error
    if( white_th1 < white_th0 )
    {
        white_th1 = white_th0;
    }
    if( WhiteSeg1Cnt < WhiteSeg0Cnt )
    {
        WhiteSeg1Cnt = WhiteSeg0Cnt;
    }
    white_boundary_bin_num[0] = 0;
    white_boundary_bin_num[1] = 0;

    white_cnt = 0;
    for( i=0; i<WhiteSeg1Cnt; i++ )
    {
        white_cnt += Hist_Cnt[(bin-1)-i];
        if( (white_cnt <= white_th0) && (i< WhiteSeg0Cnt) )
        {
            white_boundary_bin_num[0] = i;
        }
        if( white_cnt <= white_th1 )
        {
            white_boundary_bin_num[1] = i;
        }
    }
    white_boundary_bin_num[0] = white_boundary_bin_num[0] + 1; // willy 20150707, to fit the normal boundary check
    if( white_boundary_bin_num[0] > white_boundary_bin_num[1] )
    {
        white_boundary_bin_num[0] = white_boundary_bin_num[1];
    }

    //o----- debounce -----o
    white_bin_seg0 = white_boundary_bin_num[0];
    white_bin_seg1 = white_boundary_bin_num[1];

    if(DCC_SC)
    {
        white_bin_seg0_pre = white_bin_seg0;
        white_bin_seg1_pre = white_bin_seg1;
    }

    if( white_bin_seg0 != white_bin_seg0_pre )
    {
        white_bin_debounce0 -= abs(white_bin_seg0-white_bin_seg0_pre);
        if(white_bin_debounce0 <= 0 )
        {
            white_bin_debounce0 =  (Boundary_check_Table->Bin_debounce_th_white);
            white_bin_seg0_pre = white_bin_seg0;
        }
        else
        {
            white_bin_seg0 = white_bin_seg0_pre;
        }
    }
    else
    {
        white_bin_debounce0++;
        if(white_bin_debounce0 > (Boundary_check_Table->Bin_debounce_th_white))
            white_bin_debounce0 = (Boundary_check_Table->Bin_debounce_th_white);
    }

    if( white_bin_seg1 != white_bin_seg1_pre )
    {
        white_bin_debounce1 -= abs(white_bin_seg1-white_bin_seg1_pre);
        if(white_bin_debounce1<=0 )
        {
            white_bin_debounce1 = (Boundary_check_Table->Bin_debounce_th_white);
            white_bin_seg1_pre = white_bin_seg1;
        }
        else
        {
            white_bin_seg1 = white_bin_seg1_pre;
        }
    }
    else
    {
        white_bin_debounce1++;
        if(white_bin_debounce1 > (Boundary_check_Table->Bin_debounce_th_white))
            white_bin_debounce1 = (Boundary_check_Table->Bin_debounce_th_white);
    }
    //o--------------------o

    white_boundary_bin_num[0]= white_bin_seg0;
    white_boundary_bin_num[1]= white_bin_seg1;

}


void Driver_DCC_Histogram_Boundary_check(unsigned char display,unsigned char DCC_SC,unsigned char bin,unsigned int org_Total_HCnt,VIP_DCC_Boundary_check_Table *Boundary_check_Table,unsigned int *Hist_Cnt,unsigned char *Black_boundary_bin_num,unsigned char *white_boundary_bin_num)
{

	int i=0;
	unsigned char cnt_check=0;
	unsigned int Black_th0 = 0, Black_th1 = 0;
	unsigned int white_th0 = 0, white_th1 = 0;
	unsigned int black_cnt = 0, white_cnt =0;

	char dark_bin_seg0=-1,dark_bin_seg1=-1;
	char white_bin_seg0 = -1,white_bin_seg1 = -1;

	static char dark_bin_seg0_pre = 0,dark_bin_seg1_pre = 0;
	static char white_bin_seg0_pre = 0,white_bin_seg1_pre = 0;
	static char dark_bin_debounce0 = 32,dark_bin_debounce1 = 32;
	static char white_bin_debounce0 = 32,white_bin_debounce1 = 32;

	if (Boundary_check_Table == NULL ||
		Hist_Cnt == NULL ||
		Black_boundary_bin_num == NULL ||
		white_boundary_bin_num == NULL)
	{
		if(MA_print_count%360==0)
		{
			ROSPrintf("\n====Memory PQ data ERROR====\n\n");
			ROSPrintf(" Driver_DCC_Histogram_Boundary_check\n");
			ROSPrintf(" Boundary_check_Table = %x\n", Boundary_check_Table);
			ROSPrintf(" Hist_Cnt = %x\n", Hist_Cnt);
			ROSPrintf(" Black_boundary_bin_num = %x\n", Black_boundary_bin_num);
			ROSPrintf(" white_boundary_bin_num = %x\n", white_boundary_bin_num);
			ROSPrintf("\n===============================\n\n");
		}
		return;
	}


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		for(i=0;i<bin;i++) {
			ROSPrintf("Boundary_chec,Hist_Cnt[%d]=%d\n ",i,Hist_Cnt[i]);
		}

		ROSPrintf("========================================================\n");
		ROSPrintf("Boundary_chec,org_Total_HCnt=%d\n",org_Total_HCnt);
		ROSPrintf("Boundary_chec,B_ratio_seg0=%d,B_ratio_seg1=%d\n",Boundary_check_Table->Black_th_ratio_seg0,Boundary_check_Table->Black_th_ratio_seg1);
		ROSPrintf("Boundary_chec,W_ratio_seg0=%d,W_ratio_seg1=%d\n",Boundary_check_Table->white_th_ratio_seg0,Boundary_check_Table->white_th_ratio_seg1);
		ROSPrintf("Boundary_chec,B_seg1_limit=%d,W_seg1_limit=%d\n",Boundary_check_Table->Black_Bounday_seg1_limit,Boundary_check_Table->white_Bounday_seg1_limit);
		ROSPrintf("Boundary_chec,B_search_range=%d,W_search_range=%d\n",Boundary_check_Table->Black_Bounday_search_range,Boundary_check_Table->white_Bounday_search_range);
		ROSPrintf("========================================================\n");
	}

	Black_th0 = (Boundary_check_Table->Black_th_ratio_seg0)*org_Total_HCnt;
	Black_th1 = (Boundary_check_Table->Black_th_ratio_seg1)*org_Total_HCnt;
	white_th0 = (Boundary_check_Table->white_th_ratio_seg0)*org_Total_HCnt;
	white_th1 = (Boundary_check_Table->white_th_ratio_seg1)*org_Total_HCnt;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		ROSPrintf("Black_th0=%d,Black_th1=%d\n ",Black_th0,Black_th1);
		ROSPrintf("white_th0=%d,white_th1=%d\n ",white_th0,white_th1);
	}

	//black boundary check
	cnt_check =0;
	Black_boundary_bin_num[0] = 0;
	for(i=0;i<(Boundary_check_Table->Black_Bounday_search_range);i++)
	{
		black_cnt += Hist_Cnt[i];
		cnt_check++;
#if 0
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
		{
			ROSPrintf("[DCC] black_cnt=%d, cnt_check=%d\n",black_cnt,cnt_check);
		}
#endif
		if(black_cnt <=(Black_th0>>10))
		{
			//case : normal
			Black_boundary_bin_num[0] = cnt_check;

			//case : sum "search_range"  is  small than Black_th0
			if(i==((Boundary_check_Table->Black_Bounday_search_range)-1))
			{
				Black_boundary_bin_num[1] = cnt_check;
			}

			if(Black_boundary_bin_num[0] > (Boundary_check_Table->Black_Bounday_seg1_limit))
			{
				Black_boundary_bin_num[0] = (Boundary_check_Table->Black_Bounday_seg1_limit);
			}

		}
		else if((black_cnt>=(Black_th1>>10)))
		{
			if(i==0)//case : sum "search_range"  is  small than Black_th0
			{
				Black_boundary_bin_num[0] = 0;
				Black_boundary_bin_num[1] = 0;
			}
			else//case normal
			{
				Black_boundary_bin_num[1] = cnt_check;
			}

			break;
		}
		else
		{
		   if(i==((Boundary_check_Table->Black_Bounday_search_range)-1))
		   {
			   Black_boundary_bin_num[1] = cnt_check;
		   }
		}
	}


	//o----- debounce -----o
	dark_bin_seg0 = Black_boundary_bin_num[0];
	dark_bin_seg1 = Black_boundary_bin_num[1];
	if(DCC_SC)
	{
		dark_bin_seg0_pre = dark_bin_seg0;
		dark_bin_seg1_pre = dark_bin_seg1;
	}

	if( dark_bin_seg0 != dark_bin_seg0_pre )
	{
		dark_bin_debounce0 -= abs(dark_bin_seg0-dark_bin_seg0_pre);
		//ROSPrintf("[DCC] Dark bin dark_bin_debounce0= %d\n",dark_bin_debounce0);
		if(dark_bin_debounce0<=0 )
		{
			dark_bin_debounce0 =  (Boundary_check_Table->Bin_debounce_th_Black);
			//ROSPrintf("[DCC] Dark bin seg0 changed from %d to %d\n", dark_bin_seg0_pre, dark_bin_seg0 );
			dark_bin_seg0_pre = dark_bin_seg0;
		}
		else
		{
			dark_bin_seg0 = dark_bin_seg0_pre;
		}
	}
	else
	{
		dark_bin_debounce0++;
		if(dark_bin_debounce0>(Boundary_check_Table->Bin_debounce_th_Black))
			dark_bin_debounce0 = (Boundary_check_Table->Bin_debounce_th_Black);
	}


	if( dark_bin_seg1 != dark_bin_seg1_pre )
	{
		dark_bin_debounce1 -= abs(dark_bin_seg1-dark_bin_seg1_pre);
		//ROSPrintf("[DCC] Dark bin dark_bin_debounce1= %d\n",dark_bin_debounce1);
		if(dark_bin_debounce1<=0 )
		{
			dark_bin_debounce1 =  (Boundary_check_Table->Bin_debounce_th_Black);
			//ROSPrintf("[DCC] Dark bin seg1 changed from %d to %d\n", dark_bin_seg1_pre, dark_bin_seg1 );
			dark_bin_seg1_pre = dark_bin_seg1;
		}
		else
		{
			dark_bin_seg1 = dark_bin_seg1_pre;
		}
	}
	else
	{
		dark_bin_debounce1++;
		if(dark_bin_debounce1>(Boundary_check_Table->Bin_debounce_th_Black))
			dark_bin_debounce1 = (Boundary_check_Table->Bin_debounce_th_Black);
	}
	//o-----------------o

	Black_boundary_bin_num[0] = dark_bin_seg0;
	Black_boundary_bin_num[1] = dark_bin_seg1;




	//white boundary check
	cnt_check =0;
	white_boundary_bin_num[0] = 0;
	for(i=0;i<(Boundary_check_Table->white_Bounday_search_range);i++)
	{
		white_cnt += Hist_Cnt[(bin-1)-i];
		cnt_check++;
#if 0
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
		{
			ROSPrintf("[DCC] white_cnt=%d, cnt_check=%d\n",white_cnt,cnt_check);
		}
#endif
		if(white_cnt <= (white_th0>>10))
		{
			white_boundary_bin_num[0]=cnt_check;

			if(i==((Boundary_check_Table->white_Bounday_search_range)-1))
			{
				white_boundary_bin_num[1] = cnt_check;
			}

			if(white_boundary_bin_num[0] >(Boundary_check_Table->white_Bounday_seg1_limit))
			{
				white_boundary_bin_num[0] = (Boundary_check_Table->white_Bounday_seg1_limit);
			}

		}
		else if(white_cnt>=(white_th1>>10))
		{
			if(i==0)
			{
				white_boundary_bin_num[0] = 0;
				white_boundary_bin_num[1] = 0;
			}
			else
			{
				white_boundary_bin_num[1] = cnt_check;
			}

			break;
		}
		else
		{
		   if(i==((Boundary_check_Table->white_Bounday_search_range)-1))
		   {
				white_boundary_bin_num[1] = cnt_check;
		   }
		}
	}


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		ROSPrintf("[DCC] white_cnt=%d,cnt_check=%d\n",white_cnt,cnt_check);
		ROSPrintf("[DCC] bin_num[0]= %d, bin_num[1] %d\n", white_boundary_bin_num[0],white_boundary_bin_num[1] );
	}

	//o----- debounce -----o
	white_bin_seg0 = white_boundary_bin_num[0];
	white_bin_seg1 = white_boundary_bin_num[1];

	if(DCC_SC)
	{
		white_bin_seg0_pre = white_bin_seg0;
		white_bin_seg1_pre = white_bin_seg1;
	}

	if( white_bin_seg0 != white_bin_seg0_pre )
	{
		white_bin_debounce0 -= abs(white_bin_seg0-white_bin_seg0_pre);
		//ROSPrintf("[DCC] white bin white_bin_debounce0= %d\n",white_bin_debounce0);
		if(white_bin_debounce0<=0 )
		{
			white_bin_debounce0 =  (Boundary_check_Table->Bin_debounce_th_white);
			//ROSPrintf("[DCC] white bin seg1 changed from %d to %d\n", white_bin_seg0_pre, dark_bin_seg1_pre );
			white_bin_seg0_pre = white_bin_seg0;
		}
		else
		{
			white_bin_seg0 = white_bin_seg0_pre;
		}
	}
	else
	{
		white_bin_debounce0++;
		if(white_bin_debounce0>(Boundary_check_Table->Bin_debounce_th_white))
			white_bin_debounce0 = (Boundary_check_Table->Bin_debounce_th_white);
	}

	if( white_bin_seg1 != white_bin_seg1_pre )
	{
		white_bin_debounce1 -= abs(white_bin_seg1-white_bin_seg1_pre);
		//ROSPrintf("[DCC] white bin white_bin_debounce1= %d\n",white_bin_debounce1);
		if(white_bin_debounce1<=0 )
		{
			white_bin_debounce1 =  (Boundary_check_Table->Bin_debounce_th_white);
			//ROSPrintf("[DCC] white bin seg1 changed from %d to %d\n", white_bin_seg1_pre, white_bin_seg1 );
			white_bin_seg1_pre = white_bin_seg1;
		}
		else
		{
			white_bin_seg1 = white_bin_seg1_pre;
		}
	}
	else
	{
		white_bin_debounce1++;
		if(white_bin_debounce1>(Boundary_check_Table->Bin_debounce_th_white))
			white_bin_debounce1 = (Boundary_check_Table->Bin_debounce_th_white);
	}
	//o--------------------o

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		ROSPrintf("[DCC] white_bin_seg0 = %d, white_bin_seg1= %d\n", white_bin_seg0,white_bin_seg1 );
	}

	white_boundary_bin_num[0]= white_bin_seg0;
	white_boundary_bin_num[1]= white_bin_seg1;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		ROSPrintf("========================================================\n");
		ROSPrintf("Boundary_chec,Black_th0=%d,Black_th1=%d\n",Black_th0,Black_th1);
		ROSPrintf("Boundary_chec,white_th0=%d,white_th1=%d\n",white_th0,white_th1);
		ROSPrintf("Boundary_chec,white_boundary_bin_num[0]=%d,white_boundary_bin_num[1]=%d\n",white_boundary_bin_num[0],white_boundary_bin_num[1]);
		ROSPrintf("Boundary_chec,Black_boundary_bin_num[0]=%d,Black_boundary_bin_num[1]=%d\n",Black_boundary_bin_num[0],Black_boundary_bin_num[1]);
		ROSPrintf("========================================================\n");
	}

}




void Driver_DCC_SH_of_SEG_EQ(unsigned char Display,unsigned int *HistCnt,int Mean,unsigned int OriTotalHistCnt,unsigned char StartBin,unsigned char EndBin, unsigned char DCCLevel,unsigned char DEVOffset)
{

    unsigned int Dev=0, Diff=0, DiffMean=0;
    long TmpDev;
    int DevFac0 =0 , DevFac1 = 0;
    int DCCLevelBoundary = 10;

    // sum of SD
    int i;
    for(i=StartBin;i<EndBin;i++)
    {
        Dev += abs_dcc(HistCnt[i]-Mean);
    }

    // DCC linear gain level check
    DCCLevel = (DCCLevel>DCCLevelBoundary)? DCCLevelBoundary : DCCLevel;
    DevFac0 = 12-DCCLevel;
    DevFac1 = DEVOffset;

    // generate FSD, IDK HOW TO ADJUST
    TmpDev = (((long)Dev * DevFac0)<<10)/OriTotalHistCnt+(DevFac1<<10);
    Dev = (int)((TmpDev+(1<<9))>>10);

    if(Dev!=0)
    {
        // copy the compressed histCnt to result vector and get the diff between original data and result
        for(i = StartBin; i<EndBin; i++)
        {
            HighResSH[i] = (HistCnt[i]/(Dev)); //temp of SH[i]
            Diff += (HistCnt[i]-HighResSH[i]); //diff
        }

        // get diff mean
        if((EndBin-StartBin)!=0)
        {
            DiffMean = Diff/(EndBin-StartBin); // diff_mean
        }
        else
        {
            DiffMean = 0;
        }

        // final result for HR EQ
        for(i=StartBin;i<EndBin;i++)
            HighResSH[i] = HighResSH[i] + DiffMean;
    }
}


void Driver_DCC_SH_of_HighRes_EQ(unsigned char display,unsigned int *Hist_Cnt,int mean,unsigned int org_Total_HCnt,unsigned char start_bin,unsigned char End_bin, unsigned char DCC_Level,unsigned char DEV_offset)
{

    unsigned int Dev=0, diff=0, diff_mean=0;
    long Dev_temp;
    int Dev_fac_0 =0 , Dev_fac_1= 0;
    int DCC_level_boundary = 10;

    // sum of SD
    int i;
    for(i=start_bin;i<End_bin;i++)
    {
        Dev += abs_dcc(Hist_Cnt[i]-mean);
    }

    // DCC linear gain level check
    DCC_Level = (DCC_Level>DCC_level_boundary)? DCC_level_boundary : DCC_Level;
    Dev_fac_0 = 12-DCC_Level;
    Dev_fac_1 = DEV_offset;

    // generate FSD, POTENTIAL PROBLEM. WHAT IF DEV = 0?
    Dev_temp = (((long)Dev * Dev_fac_0)<<10)/org_Total_HCnt+(Dev_fac_1<<10);
    Dev = (int)((Dev_temp+512)>>10);

    // copy the compressed histCnt to result vector and get the diff between original data and result
    for(i = start_bin; i<End_bin; i++)
    {
        HighResSH[i] = (Hist_Cnt[i]/(Dev)); //temp of SH[i]
        diff += (Hist_Cnt[i]-HighResSH[i]); //diff
    }

    // get diff mean
    if((End_bin-start_bin)!=0)
    {
        diff_mean = diff/(End_bin-start_bin); // diff_mean
    }
    else
    {
        diff_mean = 0;
    }

    // final result for HR EQ
    for(i=start_bin;i<End_bin;i++)
        HighResSH[i] = HighResSH[i] + diff_mean;

}

void Driver_DCC_SH_of_EQ(unsigned char display,unsigned int *Hist_Cnt,int mean,unsigned int org_Total_HCnt,unsigned char start_bin,unsigned char End_bin, unsigned char DCC_Level,unsigned char DEV_offset)
{
	int i;
	int Dev_fac_0 =0 , Dev_fac_1= 0;
	unsigned int Dev=0, diff=0,diff_mean=0;
	long 	Dev_temp;
	//static unsigned int *HistCnt;

	int DCC_level_boundary = 10; //Defined : DCC level Range

	//HistCnt= reg_HistCnt;

	for(i=start_bin;i<End_bin;i++)
		Dev+=abs_dcc(Hist_Cnt[i]-mean); //sum of SD

	//DCC linear Gain Level
	DCC_Level = (DCC_Level>DCC_level_boundary)?DCC_level_boundary:DCC_Level; //bounder DCC_level : 0 ~10
	Dev_fac_0 = 12-DCC_Level;
	Dev_fac_1 = DEV_offset;

	Dev_temp = (((long)Dev * Dev_fac_0)<<10)/org_Total_HCnt+(Dev_fac_1<<10);
	Dev = (int)((Dev_temp+512)>>10);//level factor of SD, FSD

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("SH_of_EQ, DCC_Level=%d,Dev_fac_0=%d,Dev_fac_1=%d\n ",DCC_Level,Dev_fac_0,Dev_fac_1);
		ROSPrintf("SH_of_EQ, Dev_temp=%d,Dev=%d,mean=%d\n ",Dev_temp,Dev,mean);
	}

	for(i=start_bin;i<End_bin;i++)
	{
		SH[i]=Hist_Cnt[i]/(Dev);//temp of SH[i]
		diff+=(Hist_Cnt[i]-SH[i]);//diff

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
		{
			ROSPrintf("SH_of_EQ, SH[%d]=%d, Hist_Cnt[%d]=%d,Dev=%d\n ",i,SH[i],i,Hist_Cnt[i],Dev);
		}
	}

	if((End_bin-start_bin)!=0)
	{
		diff_mean=diff/(End_bin-start_bin); // diff_mean
	}
	else
	{
		diff_mean=0;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		//ROSPrintf("SH_of_EQ, diff=%d,diff_mean=%d\n ",diff,diff_mean);
	}

	for(i=start_bin;i<End_bin;i++)
		SH[i]+=diff_mean; //SH[i]

}


void Driver_DCC_Histogram_LPF(unsigned char display,unsigned char LPF_tap,unsigned int *mean_diff_SH,unsigned char start_bin,unsigned char End_bin )
{

		unsigned int sum=0;
		int i=0, id=0, m=0;

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
		{
			ROSPrintf("Histogram_LPF, start_bin=%d, End_bin=%d,LPF_tap=%d \n",start_bin,End_bin, LPF_tap);
			for(i=0;i<(32);i++)
			{
				ROSPrintf("Histogram_LPF, mean_diff_SH[%d]=%d\n",i,mean_diff_SH[i]);
			}
		}

		if(LPF_tap!=0)
		{
			for(i=start_bin;i<End_bin;i++)
			{
				sum=0;
				for(m=-LPF_tap;m<=LPF_tap;m++)
				{
					id=i+m;
					if(id<(0+start_bin))
						id=(0+start_bin);
					if(id>(End_bin-1))
						id=(End_bin-1);

					sum += SH[id];

				}
				LP_SH[i]=(sum+2)/(LPF_tap*2+1);
			}
		}

		for(i=start_bin;i<End_bin;i++)
			SH[i] = LP_SH[i];

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
		{
			for(i=0;i<(32);i++)
			{
				ROSPrintf("Histogram_LPF, after_SH[%d]=%d\n ",i,SH[i]);
			}
		}


}





void Driver_DCC_HighRes_DCL(unsigned char display,unsigned char bin,unsigned char MainDCC_SC,unsigned int *Hist_Cnt ,unsigned int Total_HCnt,unsigned char DCL_B,unsigned char DCL_W,unsigned short *white_extend,unsigned short *black_extend )
{

	unsigned int 	white_acc=0,black_acc=0;
	static unsigned int pre_white_acc=0,pre_black_acc=0;
	static unsigned short pre_white_extend=32,pre_black_extend=32;
	short 	white_index=(bin-1),black_index=0;
	unsigned int 	white_thl=0,black_thl=0;

	if( DCL_B !=0 )
	{
		black_thl =(Total_HCnt*24)>>10; // noise defense : ~2%

		while(black_index<bin)
		{

			black_acc+=Hist_Cnt[black_index];

			if(black_acc >= black_thl)
			{
				//normal style
				*black_extend=(DCL_B*6)+(black_index *(black_index<64? (black_index<32 ? (black_index>>1): 32) : 64))+(black_thl -pre_black_acc+1)*16/(Hist_Cnt[black_index]+1);

				if(MainDCC_SC == 1)
				{
					pre_black_extend=*black_extend;
				}
				else
				{
					*black_extend = (pre_black_extend*11 + *black_extend+6)/12;//for DCC extend blending
					pre_black_extend=*black_extend;
				}

				break;
			}
			pre_black_acc=black_acc;
			black_index++;
		}

		if(*black_extend > (DCL_B*12)+16) *black_extend=(DCL_B*12)+16;//black extend boundary for DCC black extend

	}

	if( DCL_W !=0 )
	{

		white_thl = Total_HCnt*24>>10;
		while(white_index>=0)
		{
			white_acc+=Hist_Cnt[white_index];
			if(white_acc >= white_thl)
			{
				//normal style
				*white_extend=(DCL_W*6)+((127-white_index) *((127-white_index)<64? ((127-white_index)<32 ? ((127-white_index)>>1): 32) : 64))+(white_thl -pre_white_acc+1)*16/(Hist_Cnt[white_index]+1);

				if(MainDCC_SC == 1)
				{
					pre_white_extend=*white_extend;
				}
				else
				{
					*white_extend = (pre_white_extend*11 + *white_extend+6)/12;//for DCC extend blending
					pre_white_extend=*white_extend;
				}

				break;
			}
			pre_white_acc=white_acc;
			white_index--;
		}

		if(*white_extend> (DCL_W*12)+16) *white_extend=(DCL_W*12)+16;//white extend boundary for DCC white extend
	}


}

void Driver_DCC_DCL(unsigned char display,unsigned char bin,unsigned char MainDCC_SC,unsigned int *Hist_Cnt ,unsigned int Total_HCnt,unsigned char DCL_B,unsigned char DCL_W,unsigned short *white_extend,unsigned short *black_extend )
{

	unsigned int 	white_acc=0,black_acc=0;
	static unsigned int pre_white_acc=0,pre_black_acc=0;
	static unsigned short pre_white_extend=32,pre_black_extend=32;
	short 	white_index=(bin-1),black_index=0;

	unsigned int 	white_thl=0,black_thl=0;

	int i=0;
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		for(i=0;i<bin;i++)
			ROSPrintf("DCC_DCL,Hist_Cnt[%d]=%d\n ",i,Hist_Cnt[i]);
	}

	if( DCL_B !=0 )
	{
		black_thl =(Total_HCnt*24)>>10; // noise defense : ~2%

		while(black_index<bin)
		{

			black_acc+=Hist_Cnt[black_index];

			if(black_acc >= black_thl)
			{
				//normal style
				*black_extend=(DCL_B*6)+(black_index *(black_index<16? (black_index<8 ? (black_index>>1): 8) : 16))+(black_thl -pre_black_acc+1)*16/(Hist_Cnt[black_index]+1);

				if(MainDCC_SC == 1)
				{
					pre_black_extend=*black_extend;
				}
				else
				{
					*black_extend = (pre_black_extend*11 + *black_extend+6)/12;//for DCC extend blending
					pre_black_extend=*black_extend;
				}

				break;
			}
			pre_black_acc=black_acc;
			black_index++;
		}

		if(*black_extend > (DCL_B*12)+16) *black_extend=(DCL_B*12)+16;//black extend boundary for DCC black extend

	}

	if( DCL_W !=0 )
	{

		white_thl = Total_HCnt*24>>10;
		while(white_index>=0)
		{
			white_acc+=Hist_Cnt[white_index];
			if(white_acc >= white_thl)
			{
				//normal style
				*white_extend=(DCL_W*6)+((31-white_index) *((31-white_index)<16? ((31-white_index)<8 ? ((31-white_index)>>1): 8) : 16))+(white_thl -pre_white_acc+1)*16/(Hist_Cnt[white_index]+1);

				if(MainDCC_SC == 1)
				{
					pre_white_extend=*white_extend;
				}
				else
				{
					*white_extend = (pre_white_extend*11 + *white_extend+6)/12;//for DCC extend blending
					pre_white_extend=*white_extend;
				}

				break;
			}
			pre_white_acc=white_acc;
			white_index--;
		}

		if(*white_extend> (DCL_W*12)+16) *white_extend=(DCL_W*12)+16;//white extend boundary for DCC white extend
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("DCC_DCL,black_index=%d, white_index=%d\n ",black_index,white_index );
		ROSPrintf("DCC_DCL,black_extend=%d, white_extend=%d\n ",*black_extend,*white_extend );
	}


}

void Driver_DCC_DCL_tv005(unsigned char display,unsigned char bin,unsigned char MainDCC_SC,unsigned int *Hist_Cnt ,unsigned int Total_HCnt,unsigned char DCL_B,unsigned char DCL_W,unsigned short *white_extend,unsigned short *black_extend )
{

	unsigned int 	white_acc=0,black_acc=0;
	static unsigned int pre_white_acc=0,pre_black_acc=0;
	static unsigned short pre_white_extend=32,pre_black_extend=32;
	short 	white_index=(bin-1),black_index=0;

	unsigned int 	white_thl=0,black_thl=0;

	if( DCL_B !=0 )
	{
		black_thl =(Total_HCnt*24)>>10; // noise defense : ~2%

		while(black_index<bin)
		{

			black_acc += Hist_Cnt[black_index];

			if(black_acc >= black_thl)
			{

				*black_extend=(DCL_B*4)+black_index*16+(black_thl -pre_black_acc+1)*16/(Hist_Cnt[black_index]+1);//TV005 style

				if(MainDCC_SC == 1)
				{
					pre_black_extend=*black_extend;
				}
				else
				{
					*black_extend = (pre_black_extend*11 + *black_extend+6)/12;//for DCC extend blending
					pre_black_extend=*black_extend;
				}

				break;
			}
			pre_black_acc=black_acc;
			black_index++;
		}

		if(*black_extend > (DCL_B*12)+16) *black_extend=(DCL_B*12)+16;//black extend boundary for DCC black extend

	}

	if( DCL_W !=0 )
	{

		white_thl = Total_HCnt*24>>10;
		while(white_index>=0)
		{
			white_acc+=Hist_Cnt[white_index];
			if(white_acc >= white_thl)
			{
				*white_extend=(DCL_W*4)+(31-white_index)*16+(white_thl -pre_white_acc+1)*16/(Hist_Cnt[white_index]+1);//TV005 style

				if(MainDCC_SC == 1)
				{
					pre_white_extend=*white_extend;
				}
				else
				{
					*white_extend = (pre_white_extend*11 + *white_extend+6)/12;//for DCC extend blending
					pre_white_extend=*white_extend;
				}

				break;
			}
			pre_white_acc=white_acc;
			white_index--;
		}

		if(*white_extend> (DCL_W*12)+16) *white_extend=(DCL_W*12)+16;//white extend boundary for DCC white extend
	}



}

void Driver_DCC_Curve_change_method(unsigned char display, unsigned char *dcc_delay_time,unsigned char *dcc_Curve_change_step )
{
/*
	// sync. dcc_delay_time from TSB 2674
		if(((SmartPic_clue->PureColor) == 1) || ((SmartPic_clue->PureColor) == 1))
		{
			*dcc_delay_time = 1;
		}
		else
		{
			*dcc_delay_time = Main_DCC_Delay_Time_Normal;
		}


		*dcc_Curve_change_step = DCC_step;
*/
}

void Driver_DCC_Curve_Slope_Weight_Mapping( unsigned char display, unsigned char score_NaturalImage, unsigned char weight_th, unsigned char *weight)
{
	//score_NaturalImage : 0~255
	if(score_NaturalImage>=weight_th)
	{
		*weight = ((score_NaturalImage-weight_th)*32)/(255-weight_th);
	}
	else
	{
		*weight=0;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf(" score_NaturalImage=%d\n",score_NaturalImage);
		ROSPrintf(" weight_th=%d\n",weight_th);
		ROSPrintf(" weight=%d\n",*weight);

	}

}




void Driver_DCC_HighRes_Curve_Slope_Limit( unsigned char display, unsigned int* SH_ori, unsigned int* SH_new, unsigned int SH_total, unsigned int slope_th, unsigned char weight,unsigned int HighResStartBin,unsigned int HighResEndBin )
{
    int i,j,k;
    const int filter[5] = {1,2,2,2,1};
    unsigned int TmpSlopeLimitSH[128] = {0};
    unsigned int max_SH = 0, max_SH_idx = 0;
    unsigned int N_inv = ( (1023<<16) + ((SH_total+1)>>1) )/(SH_total+1);

    for( i=0; i<128; i++ )
    {

        if ( SH_ori[i] > max_SH )
        {
            max_SH = SH_ori[i];
            max_SH_idx = i;
        }

        if( MA_print_count%debug_print_delay_time==0 && ((Start_Print.VD_LOG_ENABLE == TRUE)||(Start_Print.Dcc_1==TRUE)) )
        {
            ROSPrintf("[HighRes] LPF [%d] Slope:%d th:%d\n", i, ((SH_ori[i] * N_inv + (1<<15) )>>16 ), slope_th);
        }

        if(((SH_ori[i] * N_inv + (1<<15) )>>16 ) > slope_th )
        {

            if( MA_print_count%debug_print_delay_time==0 && (Start_Print.VD_LOG_ENABLE == TRUE||(Start_Print.Dcc_1==TRUE)) )
            {
                ROSPrintf("[HighRes] DO!\n");
            }

            for( j=-2; j<=2; j++ )
            {
                k = i+j;
                if( k<HighResStartBin ) k=HighResStartBin;
                else if( k>=128 ) k=127;
                TmpSlopeLimitSH[k] += (SH_ori[i]*filter[j+2]) >> 3;
            }
        }
        else
        {
            TmpSlopeLimitSH[i] += SH_ori[i];
        }

    }

    for( i=0; i<128; i++ )
    {
        SH_new[i] = ( TmpSlopeLimitSH[i]*weight + SH_ori[i]*(16-weight) ) >> 4;
    }

}


unsigned int Slope_Limit_SH_temp[COLOR_HISTOGRAM_LEVEL];
void Driver_DCC_Curve_Slope_Limit( unsigned char display, unsigned int* SH_ori, unsigned int* SH_new, unsigned int SH_total, unsigned int slope_th, unsigned char weight,unsigned char start_bin,unsigned char End_bin , unsigned char H_LPF_Tap)
{
	int i,j,k;

	const int filter[3]={1,2,1}; // 1->3tap
	const int filter_5tap[5]={1,2,2,2,1};// 2-> 5tap
	const int filter_7tap[7]={1,2,2,2,2,2,1};// 3-> 7tap
	const int filter_9tap[9]={1,2,2,2,2,2,2,2,1};// 4-> 9tap
	const int filter_11tap[11]={1,2,2,2,2,2,2,2,2,2,1};// 5-> 11tap

	unsigned char tap_num=0;

	unsigned int N_inv = ( (1023<<16) + ((SH_total+1)>>1) )/(SH_total+1);
	unsigned int max_SH = 0, max_SH_idx = 0;

	if(H_LPF_Tap==1)
	{
		tap_num=1;
	}
	else if(H_LPF_Tap==2)
	{
		tap_num=2;
	}
	else if (H_LPF_Tap==3)
	{
		tap_num=3;
	}
	else if (H_LPF_Tap==4)
	{
		tap_num=4;
	}
	else if (H_LPF_Tap==5)
	{
		tap_num=5;
	}
	else
	{
		tap_num=0; //not supported LP tap
	}
    //matrix init, set all 0
 	for( i=0; i<COLOR_HISTOGRAM_LEVEL; i++ ){
    		Slope_Limit_SH_temp[i] = 0;
        }

 	for( i=0; i<COLOR_HISTOGRAM_LEVEL; i++ ) {
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
			ROSPrintf("Before Curve_Slope_Limit, SH[%d] = %d,Limit_SH_temp[%d] = %d\n", i, SH_ori[i],i,Slope_Limit_SH_temp[i] );
		}

		if ( SH_ori[i] > max_SH ) {
			max_SH = SH_ori[i];
			max_SH_idx = i;
		}

        	if( MA_print_count%debug_print_delay_time==0 && Start_Print.Dcc_2 == TRUE ) {
	        	ROSPrintf("[Normal] LPF [%d] Slope:%d th:%d\n", i, ((SH_ori[i] * N_inv + (1<<15) )>>16 ), slope_th);
	        }

		///*
    		// mutiple -tap LPF to spread peak
    		//if( MA_print_count%debug_print_delay_time==0)
    		//ROSPrintf("[MHH][%d]Before: slope = %d\n", i,( ( ( SH_ori[i] * N_inv + (1<<15) )>>16 )));
    		if( ( ( ( SH_ori[i] * N_inv + (1<<15) )>>16 ) > slope_th) && (tap_num != 0) ) {

			if( MA_print_count%debug_print_delay_time==0 && Start_Print.Dcc_2 == TRUE ){
				ROSPrintf("[Normal] DO!\n");
			}

            for( j=-tap_num; j<=tap_num; j++ )
			{
             	k = i+j;
                if( k<start_bin )
                	k = start_bin;
                else if( k >End_bin -1)
                	k = End_bin -1;

				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)){
					ROSPrintf(" [%d]SH_temp= %d\n", k,Slope_Limit_SH_temp[k]);
				}

                		if(tap_num == 1)
                		{
							Slope_Limit_SH_temp[k] += (SH_ori[i]*filter[j+tap_num]) >> 2;//mainly use the LPF
                		}
						else if(tap_num == 2)
						{
							Slope_Limit_SH_temp[k] += (SH_ori[i]*filter_5tap[j+tap_num]) >> 3;//mainly use the LPF
						}
						else if(tap_num == 3)
						{
							Slope_Limit_SH_temp[k] += (SH_ori[i]*filter_7tap[j+tap_num])/12;//mainly use the LPF
						}
						else if(tap_num == 4)
						{
							Slope_Limit_SH_temp[k] += (SH_ori[i]*filter_9tap[j+tap_num]) >> 4;//mainly use the LPF
						}
						else if(tap_num == 5)
						{
							Slope_Limit_SH_temp[k] += (SH_ori[i]*filter_11tap[j+tap_num])/20;//mainly use the LPF
						}

				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)){
					ROSPrintf(" [%d]SH_temp= %d,SH_ori[%d]=%d,filter[%d]=%d \n", k,Slope_Limit_SH_temp[k],i,SH_ori[i],j,filter[j+2]);
				}

            }

				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)){
					ROSPrintf(" [%d]normalized value= %d,weight=%d \n", i,( ( SH_ori[i] * N_inv + (1<<15) )>>16 ),weight);
				}


        	}else{
         		Slope_Limit_SH_temp[i] += SH_ori[i];

			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)){
				ROSPrintf("Before Curve_Slope_Limit, SH[%d] = %d,Limit_SH_temp[%d] = %d\n", i, SH_ori[i],i,Slope_Limit_SH_temp[i] );
			}

        	}
        	//*/

   	 }

    	for( i=0; i<COLOR_HISTOGRAM_LEVEL; i++ ){
    		SH_new[i] = ( Slope_Limit_SH_temp[i]*weight + SH_ori[i]*(32-weight) ) >> 5; //DO

		//if( MA_print_count%debug_print_delay_time==0)
    		//ROSPrintf("[MHH][%d]After: slope = %d\n", i,( ( ( SH_new[i] * N_inv + (1<<15) )>>16 )));

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
			ROSPrintf("After Curve_Slope_Limit, SH[%d] = %d,\n", i, SH_new[i] );
    	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)){
		ROSPrintf(" Driver_DCC_Curve_Slope_Limit\n");
		ROSPrintf(" Max SH is %d, at idx %d,\n", max_SH, max_SH_idx );
		ROSPrintf("SH_total = %d, N_inv = %d\n", SH_total, N_inv );
		ROSPrintf(" normalized value is %d\n", ( max_SH * N_inv + (1<<15) )>>16 ) ;
	}

}

int OSD_Blending_G0[Curve_num_Max], OSD_Blending_G1[Curve_num_Max];
void drvif_color_DCC_Curve_OSD_Blending(unsigned char Curve_num,int* histogram_curve,int *target_curve,unsigned char weight)
{
	unsigned char weight_max =32;
	int i;

	if(weight >= weight_max)
		weight = weight_max;

	for(i = 0; i<Curve_num_Max ;i++)
	{
		//init matrix value : all set 0
		OSD_Blending_G0[i]=0;
		OSD_Blending_G1[i]=0;

		//set value
		OSD_Blending_G0[i]=histogram_curve[i];
		OSD_Blending_G1[i]=target_curve[i];

		Main_Curve_Temp[i]=((weight_max-weight)*OSD_Blending_G1[i] + weight*OSD_Blending_G0[i])>>5;
	}

	//return *Main_Curve_Temp;

}

int panel_compensation_G0[Curve_num_Max], panel_compensation_G1[Curve_num_Max];
void drvif_color_DCC_panel_compensation(unsigned char Curve_num,int* histogram_curve,unsigned int* compensation_curve, unsigned char Y_gain, unsigned char Y_offset)
{
	unsigned short i = 0;
	unsigned short Base_I = Y_offset;
	unsigned short Global_gain = Y_gain;
	unsigned int check_sum = 0;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
		ROSPrintf(" drvif_color_DCC_panel_compensation\n");
		ROSPrintf(" Curve_num=%d\n",Curve_num);
	}

	if(&compensation_curve==NULL){
		return;
	}

	//for 129 DCC segment
	for(i = 0; i<=Curve_num ;i++) {
		//Curve matrix init
		panel_compensation_G0[i]=0;
		panel_compensation_G1[i]=0;

		panel_compensation_G0[i]=histogram_curve[i]; //Input Curve
		panel_compensation_G1[i]=compensation_curve[i]*Global_gain; //Compensation Curve
		check_sum += panel_compensation_G1[i];

	}

//for debug
#if 1
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {

		ROSPrintf(" drvif_color_DCC_panel_compensation\n");

		ROSPrintf(" G0\n");
		for(i = 0; i <(Curve_num+1); i++) {
			ROSPrintf(" %d\n",panel_compensation_G0[i]);
		}

		ROSPrintf(" G1\n");
		for(i = 0; i <(Curve_num+1); i++) {
			ROSPrintf(" %d\n",panel_compensation_G1[i]);
		}
	}
#endif

#if 0 //for full Curve Remmping "Speed up" Process , only for linear mapping Curve..

		int temp_2=0;
		unsigned char j=0;
		for(i=0;i<=bin_num;i++) {
			j = panel_compensation_G0[i]/input_seg_range;
			temp_2 = j*input_seg_range;

			if( panel_compensation_G0[i]<=0 ) {
				Main_panel_compensation_Curve[i] = Base_I;
			} else if( panel_compensation_G0[i]>=DataRange_MAX ) {
				Main_panel_compensation_Curve[i] = max;
			} else {
				Main_panel_compensation_Curve[i] =  panel_compensation_G1[j]+(((panel_compensation_G1[j+1]-panel_compensation_G1[j])*(panel_compensation_G0[i]-temp_2)+(input_seg_range>>1))/input_seg_range);
			}

			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
				ROSPrintf(" i=%d, j=%d, temp_2=%d \n",i,j,temp_2 );
			}

		}

#else //for full Curve Remmping Process !! for all kind of mapping Curve ...

	unsigned int temp = 0;
	int temp_2=0;
	unsigned char j=0;
	unsigned short seg_range = (1<<DCC_Curve_DataRang_bit)/Curve_num;

	if(check_sum == 0){
		for(i = 0; i<=Curve_num ;i++) {
			panel_compensation_G1[i] = Main_panel_compensation_Curve[i];
		}
	}

	for(i=0;i<=Curve_num;i++) {
		for(j=0;j<Curve_num;j++) {
			temp_2 = j*seg_range;
			if( panel_compensation_G0[i]<=0 ) {
				Main_panel_compensation_Curve[i] = Base_I;
			} else if( panel_compensation_G0[i]>=DataRange_MAX ) {
				Main_panel_compensation_Curve[i] = DataRange_MAX;
			} else if((panel_compensation_G0[i]>0) && (panel_compensation_G0[i]>=temp_2) && (panel_compensation_G0[i]<(temp_2+seg_range)) ) {
				temp = ((panel_compensation_G1[j+1]-panel_compensation_G1[j])*(panel_compensation_G0[i]-temp_2)+16);
				temp = temp>>5;
				Main_panel_compensation_Curve[i] = panel_compensation_G1[j]+temp;
			}
		}
	}

#endif

#if 1
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
		for(i = 0; i <Curve_num_Max; i++) {
			ROSPrintf(" compensation_Curve[%d]=  %d\n",i,Main_panel_compensation_Curve[i]);
		}

	}
#endif
}



int range_remapping_G0[Curve_num_Max], range_remapping_G1[Curve_num_Max];
void drvif_color_DCC_Curve_range_remapping(unsigned char Curve_num,int* histogram_curve,unsigned short boundary_output_high,unsigned short boundary_output_low, unsigned char bin_num, unsigned char zero_bin, unsigned char max_bin_offset)
{

	static unsigned short dcc_scurve_counter=0;

	unsigned short i=0;
	unsigned short max=boundary_output_high;//=1<<Data_Path_bit_num;
	unsigned short Base_I = boundary_output_low;

	unsigned short Seg_I_B=32,Seg_I_W=32,Seg_I_middle=32;///for 0 point
	unsigned char DCC_bin_range=28;//default : 2 ~30
	unsigned char max_bin = bin_num;
	unsigned short input_seg_range = (1<<DCC_Curve_DataRang_bit)/bin_num;

	max_bin = max_bin-max_bin_offset;

	if(((max_bin-zero_bin)!=0)&&(max_bin<=bin_num))
	{
		DCC_bin_range = max_bin-zero_bin;
	}

	if(zero_bin==0)
	{
		Seg_I_B = 0;
	}
	else
	{
		Seg_I_B=(boundary_output_low-Base_I)/zero_bin;
	}

	if(max_bin_offset==0)
	{
		Seg_I_W =0;
	}
	else
	{
		Seg_I_W=(max-boundary_output_high)/max_bin_offset;
	}

	Seg_I_middle = ((boundary_output_high-boundary_output_low)+(DCC_bin_range>>1))/DCC_bin_range;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf(" drvif_color_DCC_Curve_range_remapping\n");
		ROSPrintf(" bou_high=%d, bou_low=%d\n",boundary_output_high,boundary_output_low);
		ROSPrintf(" bit_num=%d,zero_bin=%d,max_bin=%d,max_bin_offset=%d\n",bin_num,zero_bin,max_bin,max_bin_offset);
		ROSPrintf(" DCC_bin_range=%d\n",DCC_bin_range);
		ROSPrintf(" Seg_I_B=%d,Seg_I_W=%d,Seg_I_middle=%d\n",Seg_I_B,Seg_I_W,Seg_I_middle);
	}

	//for 32 DCC segment from MacArthur
	for(i = 0; i<=bin_num ;i++)
	{
		//Curve matrix init
		range_remapping_G0[i]=0;
		range_remapping_G1[i]=0;

		range_remapping_G0[i]=histogram_curve[i];

		if(i < zero_bin)
		{
			range_remapping_G1[i]= (i*Seg_I_B) + Base_I;
			if(range_remapping_G1[i]<=Base_I)
				range_remapping_G1[i]=Base_I;
		}
		else if(i==zero_bin)
		{
			range_remapping_G1[i] = boundary_output_low;
		}
		else if(i==max_bin)
		{
			range_remapping_G1[i] = boundary_output_high;
		}
		else if(i>max_bin)
		{
			range_remapping_G1[i]=(i-max_bin)*(Seg_I_W) + boundary_output_high;

			if( range_remapping_G1[i] >= max)
			{
				range_remapping_G1[i] = max;
			}
		}
		else
		{
			range_remapping_G1[i]=(i-zero_bin)*Seg_I_middle + boundary_output_low;
		}
	}

//for debug
#if 1
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
/*
		for(i = 0; i <33; i++)
		{
			ROSPrintf(" ((i*i*32)/index)=%d \n",((i*i*32)/index));
			ROSPrintf(" ((i*i*32)*scale)/index=%d \n",(((i*i*32)/index)/32));
			ROSPrintf(" temp=%d,temp1=%d\n",temp,temp1);
		}
*/
		ROSPrintf(" drvif_color_DCC_Curve_range_remapping\n");

		ROSPrintf(" G0\n");
		for(i = 0; i <Curve_num_Max; i++)
		{
			ROSPrintf(" %d\n",range_remapping_G0[i]);
		}

		ROSPrintf(" G1\n");
		for(i = 0; i <Curve_num_Max; i++)
		{
			ROSPrintf(" %d\n",range_remapping_G1[i]);
		}
	}
#endif

#if 1 //for full Curve Remmping "Speed up" Process , only for linear mapping Curve..

		int temp_2=0;
		unsigned char j=0;
		for(i=0;i<=bin_num;i++)
		{
			j = range_remapping_G0[i]/input_seg_range;
			temp_2 = j*input_seg_range;

			if( range_remapping_G0[i]<=0 )
			{
				Main_range_remapping_Curve[i] = Base_I;
			}
			else if( range_remapping_G0[i]>=DataRange_MAX )
			{
				Main_range_remapping_Curve[i] = max;
			}
			else
			{
				Main_range_remapping_Curve[i] =  range_remapping_G1[j]+(((range_remapping_G1[j+1]-range_remapping_G1[j])*(range_remapping_G0[i]-temp_2)+(input_seg_range>>1))/input_seg_range);
			}

			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
			{
				ROSPrintf(" i=%d, j=%d, temp_2=%d \n",i,j,temp_2 );

			}

		}

#else //for full Curve Remmping Process !! for all kind of mapping Curve ...


	int temp_2=0;
	unsigned char j=0;

	for(i=0;i<=bin_num;i++)
	{
		for(j=0;j<bin_num;j++)
		{
			temp_2 = j*32;

			if( G0[i]<=0 )
			{
				Main_range_remapping_Curve[i] = Base_I;
			}
			else if( G0[i]>=1023 )
			{
				Main_range_remapping_Curve[i] = max;
			}
			else if((G0[i]>0) && (G0[i]>=temp_2) && (G0[i]<(temp_2+32)) )
			{
				Main_range_remapping_Curve[i] = G1[j]+(((G1[j+1]-G1[j])*(G0[i]-temp_2)+16)/32);
			}
		}
	}

#endif

#if 1
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		for(i = 0; i <Curve_num_Max; i++)
		{
			ROSPrintf(" remmping_Curve[%d]=  %d\n",i,Main_range_remapping_Curve[i]);
		}
	}
#endif

	dcc_scurve_counter++;

}




void drvif_color_dcc_Advance_Level_control_by_mean_variance_interpolation(unsigned char bin,unsigned char MainDCC_SC,unsigned char DCC_debounce_th ,unsigned int *Hist_Cnt,unsigned int *Adavance_Control_info)
{
	_clues* SmartPic_clue = NULL;
	unsigned int DCC_Tool_sum_histo=0;
	unsigned int DCC_Tool_histo_total=0;
	unsigned int DCC_Tool_mean_64x=0; // add mean precision
	unsigned char i=0;

	static unsigned int DCC_mean_pre = 0;
	static int DCC_dev_pre = 0;
	static int DCC_mean_debounce = 15; // 100x compared to original setting

	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	if(SmartPic_clue == NULL) {
		ROSPrintf("Share Memory PQ data ERROR, drvif_color_dcc_Advance_Level_control_by_mean_variance_interpolation\n");
		return;
	}

	//static char DCC_mean_debounce = 15;

	if(DCC_debounce_th>=32)
		DCC_debounce_th =32;

//=== DCC  mean value ===
	for (i=0;i<bin;i++)
	{
		DCC_Tool_sum_histo+= i*Hist_Cnt[i];
		DCC_Tool_histo_total += Hist_Cnt[i];
	}

	DCC_Tool_mean_64x = (DCC_Tool_sum_histo<<6) / (DCC_Tool_histo_total+1);
	Adavance_Control_info[DCC_Tool_mean] = SmartPic_clue->Hist_Y_Mean_Value;
	Adavance_Control_info[DCC_mean_no_debounce] = Adavance_Control_info[DCC_Tool_mean];


//=== DCC Histogram variance ===
	for(i=0;i<bin;i++)
	{
		//Adavance_Control_info[DCC_Tool_Dev]+=((abs_dcc(i-Adavance_Control_info[DCC_Tool_mean]))*(Hist_Cnt[i])); //SD-> diff sum
		Adavance_Control_info[DCC_Tool_Dev]+=((abs_dcc((i<<6)-DCC_Tool_mean_64x))*(Hist_Cnt[i])); //SD-> diff sum
	}
	//Adavance_Control_info[DCC_Tool_Dev] = Adavance_Control_info[DCC_Tool_Dev] / (DCC_Tool_histo_total+1);
	Adavance_Control_info[DCC_Tool_Dev] = Adavance_Control_info[DCC_Tool_Dev]/(DCC_Tool_histo_total+1);
	Adavance_Control_info[DCC_Dev_no_debounce] = Adavance_Control_info[DCC_Tool_Dev];


	//*** mean debounce to avoid flicker ***
	if( Adavance_Control_info[DCC_Tool_mean] != DCC_mean_pre )
	{
		if( (abs(Adavance_Control_info[DCC_Tool_mean] - DCC_mean_pre) <= (1<<6)) && (MainDCC_SC==0) )
		{
			DCC_mean_debounce--;
			if( DCC_mean_debounce==0 ) // let mean & var change
			{
				DCC_mean_debounce = DCC_debounce_th;
				DCC_mean_pre = Adavance_Control_info[DCC_Tool_mean];
				DCC_dev_pre = Adavance_Control_info[DCC_Tool_Dev];
			}
			else // keep previous value
			{
				Adavance_Control_info[DCC_Tool_mean] = DCC_mean_pre;
				Adavance_Control_info[DCC_Tool_Dev] = DCC_dev_pre;
			}
		}
		else // APL change > 1 or scene change
		{
			DCC_mean_debounce = DCC_debounce_th;
			DCC_mean_pre = Adavance_Control_info[DCC_Tool_mean];
			DCC_dev_pre = Adavance_Control_info[DCC_Tool_Dev];
		}
	}
	else // APL not changed
	{
		DCC_mean_debounce++;
		if(DCC_mean_debounce>DCC_debounce_th)
			DCC_mean_debounce = DCC_debounce_th;
	}


//=== seg. info boundary ===
	if (Adavance_Control_info[DCC_Tool_Dev] > (13<<6))
		Adavance_Control_info[DCC_Tool_Dev] = (13<<6);



}


void drvif_color_dcc_Advance_Level_control_by_mean_variance(unsigned char bin,unsigned char MainDCC_SC,unsigned char DCC_debounce_th ,unsigned int *Hist_Cnt,unsigned int *Adavance_Control_info)
{
	_clues* SmartPic_clue = NULL;
	unsigned int DCC_Tool_sum_histo=0;
	unsigned int DCC_Tool_histo_total=0;
	unsigned int DCC_Tool_mean_100x=0; // add mean precision
	unsigned char i=0;
	unsigned char Hist_shift = 0;

	static unsigned int DCC_mean_pre = 0;
	static char DCC_dev_pre = 0;
	static char DCC_mean_debounce = 15;

	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	if(SmartPic_clue == NULL) {
		ROSPrintf("Share Memory PQ data ERROR, drvif_color_dcc_Advance_Level_control_by_mean_variance\n");
		return;
	}

	//static char DCC_mean_debounce = 15;

	if(DCC_debounce_th>=32)
		DCC_debounce_th =32;

//=== DCC  mean value ===
	for (i=0;i<bin;i++)
	{
		DCC_Tool_sum_histo+= i*Hist_Cnt[i];
		DCC_Tool_histo_total += Hist_Cnt[i];
	}

	//mean range, normalize to 0 ~ 31
	DCC_Tool_mean_100x = (DCC_Tool_sum_histo*100) / (DCC_Tool_histo_total+1);
	if(bin == mean_value_index_MAX){
		Adavance_Control_info[DCC_Tool_mean] = SmartPic_clue->Hist_Y_Mean_Value;
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
			ROSPrintf("(bin == mean_value_index_MAX)\n");
		Hist_shift = 0;
	} else {
		Adavance_Control_info[DCC_Tool_mean] = SmartPic_clue->Hist_Y_Mean_Value;
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
			ROSPrintf("(bin != mean_value_index_MAX)\n");
		Hist_shift = 2;
	}

	Adavance_Control_info[DCC_mean_no_debounce] = Adavance_Control_info[DCC_Tool_mean];


//=== DCC Histogram variance ===
	for(i=0;i<bin;i++)
	{
		//Adavance_Control_info[DCC_Tool_Dev]+=((abs_dcc(i-Adavance_Control_info[DCC_Tool_mean]))*(Hist_Cnt[i])); //SD-> diff sum
		Adavance_Control_info[DCC_Tool_Dev]+=((abs_dcc(i*100-DCC_Tool_mean_100x))*(Hist_Cnt[i])); //SD-> diff sum
	}

	//Adavance_Control_info[DCC_Tool_Dev] = Adavance_Control_info[DCC_Tool_Dev] / (DCC_Tool_histo_total+1);
	Adavance_Control_info[DCC_Tool_Dev] = Adavance_Control_info[DCC_Tool_Dev]/(DCC_Tool_histo_total+1);
	Adavance_Control_info[DCC_Tool_Dev] = Adavance_Control_info[DCC_Tool_Dev]/100;

	Adavance_Control_info[DCC_Tool_Dev]= Adavance_Control_info[DCC_Tool_Dev]>>Hist_shift;
	Adavance_Control_info[DCC_Dev_no_debounce] = Adavance_Control_info[DCC_Tool_Dev];


	//*** mean debounce to avoid flicker ***
	if( Adavance_Control_info[DCC_Tool_mean] != DCC_mean_pre )
	{
		//ROSPrintf("DCC_Tool_mean=%d\n ",Adavance_Control_info[DCC_Tool_mean]);

		if( (abs(Adavance_Control_info[DCC_Tool_mean] - DCC_mean_pre)==1) && (MainDCC_SC==0) )
		{
			DCC_mean_debounce--;
			if( DCC_mean_debounce==0 ) // let mean & var change
			{
				DCC_mean_debounce = DCC_debounce_th;
				DCC_mean_pre = Adavance_Control_info[DCC_Tool_mean];
				DCC_dev_pre = Adavance_Control_info[DCC_Tool_Dev];
			}
			else // keep previous value
			{
				Adavance_Control_info[DCC_Tool_mean] = DCC_mean_pre;
				Adavance_Control_info[DCC_Tool_Dev] = DCC_dev_pre;
			}
		}
		else // APL change > 1 or scene change
		{
			DCC_mean_debounce = DCC_debounce_th;
			DCC_mean_pre = Adavance_Control_info[DCC_Tool_mean];
			DCC_dev_pre = Adavance_Control_info[DCC_Tool_Dev];
		}
	}
	else // APL not changed
	{
		DCC_mean_debounce++;
		if(DCC_mean_debounce>DCC_debounce_th)
			DCC_mean_debounce = DCC_debounce_th;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
	//if((MA_print_count%debug_print_delay_time==0))
	{
		ROSPrintf("Before boundary\n ");
		ROSPrintf("DCC_Tool_Dev=%d\n ",Adavance_Control_info[DCC_Tool_Dev]);
	}

//=== seg. info boundary ===
	/*
	if (Adavance_Control_info[DCC_Tool_mean]>22)
		Adavance_Control_info[DCC_Tool_mean]=22;
	*/
	if (Adavance_Control_info[DCC_Tool_Dev]>13)
		Adavance_Control_info[DCC_Tool_Dev]=13;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	//if((MA_print_count%debug_print_delay_time==0))
	{
		ROSPrintf("DCC_Tool_mean=%d\n ",Adavance_Control_info[DCC_Tool_mean]);
		ROSPrintf("DCC_Tool_Dev=%d\n ",Adavance_Control_info[DCC_Tool_Dev]);
	}


}


void drvif_color_DHist_SC(unsigned char channel)
{
	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_RPC_clues* RPC_SmartPic_clue=NULL;
	RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();

	if(SmartPic_clue == NULL || RPC_SmartPic_clue == NULL) {
		if(MA_print_count%360==0)
			ROSPrintf("drvif_color_DHist_SC Share Memory PQ data ERROR,SmartPic_clue = %x,%x, \n",SmartPic_clue,RPC_SmartPic_clue);
		return;
	}

	static UINT32 pre_Hist[COLOR_D_HISTOGRAM_LEVEL] = {0};
	unsigned char i;
	unsigned int diff_sum = 0,diff_sum_SR=0,diff_sum_SL=0,diff_sum_even_SR=0,diff_sum_odd_SR=0;
	unsigned int SC_Thl;
	unsigned int SceneChange=0;
	static char SC_count=0;
	unsigned int *reg_HistCnt=(SmartPic_clue->Y_Main_D_Hist);

	unsigned char diff =0,SC_ratio_offset=0;
	static UINT8 Pre_mean_value=0;
	unsigned char SC_th_ratio = 0;

	diff = abs((SmartPic_clue->D_Hist_Y_Mean_Value)-Pre_mean_value);
	if(diff <=10)
	{

		SC_ratio_offset=10-diff;
	}

	SC_th_ratio = 48+SC_ratio_offset;//default : 48 means 75%, per step +-(1.5625%)
	SC_Thl= ((SmartPic_clue->D_Hist_Y_Total_sum)*SC_th_ratio)>>6;  //SC Threshold

	Pre_mean_value = (SmartPic_clue->D_Hist_Y_Mean_Value);
	//scalerDrvPrint("infoTemp->MEM_ACT_WID = %d,infoTemp->MEM_ACT_LEN=%d \n",infoTemp->MEM_ACT_WID,infoTemp->MEM_ACT_LEN);
	//Total_HistCnt=0;

	for(i=0;i<COLOR_D_HISTOGRAM_LEVEL;i++)
	{
		diff_sum += (UINT32)ABS(reg_HistCnt[i], pre_Hist[i]);
		//Total_HistCnt+=reg_HistCnt[i];
	}

	for(i=0;i<(COLOR_D_HISTOGRAM_LEVEL-1);i++)
	{
		diff_sum_SR += (UINT32)ABS(reg_HistCnt[i+1], pre_Hist[i]);
		diff_sum_SL += (UINT32)ABS(reg_HistCnt[i], pre_Hist[i+1]);

	}
	for(i=0;i<64;i++)//(COLOR_D_HISTOGRAM_LEVEL<<1)
	{
		diff_sum_even_SR += (UINT32)ABS((reg_HistCnt[i*2]+reg_HistCnt[i*2+1]),(pre_Hist[i*2]+pre_Hist[i*2+1]));
		if(i<63)//(COLOR_D_HISTOGRAM_LEVEL<<1)-1
			diff_sum_odd_SR += (UINT32)ABS((reg_HistCnt[i*2+1]+reg_HistCnt[i*2+2]),(pre_Hist[i*2+1]+pre_Hist[i*2+2]));
	}

	//diff_sum += (UINT32)ABS((reg_HistCnt[i]+reg_HistCnt[i+1]),pre_Hist[i]+pre_Hist[i+1])
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		ROSPrintf("T=%d  d=%d SC_Thl=%d \n",(SmartPic_clue->D_Hist_Y_Total_sum),diff_sum,SC_Thl);
		ROSPrintf("dR=%d  d=%d,%d,%d\n",diff_sum_SR,diff_sum_SL,diff_sum_even_SR,diff_sum_odd_SR);
	}

	if( (diff_sum>SC_Thl)&&(diff_sum_SR>SC_Thl)&&(diff_sum_SL>SC_Thl)&&(diff_sum_even_SR>SC_Thl) &&((diff_sum_odd_SR>SC_Thl))&& (channel== SLR_MAIN_DISPLAY) )
	{
		SceneChange=1;                      // Scene Change detected
		SC_count=1;//times of SC

		//ROSPrintf("Total_HistCnt=%d,diff_sum=%d SC_Thl=%d \n",(SmartPic_clue->Hist_Y_Total_sum),diff_sum,SC_Thl);
		//ROSPrintf("diff_sum_SR=%d,diff_sum_SL=%d  \n",diff_sum_SR,diff_sum_SL);
		//ROSPrintf("even_SR=%d,odd_SR=%d  \n",diff_sum_even_SR,diff_sum_odd_SR);
		//ROSPrintf("diff=%d,SC_th_ratio=%d\n",diff,SC_th_ratio);
		//ROSPrintf("Mean_Value=%d\n",(SmartPic_clue->Hist_Y_Mean_Value));

	}
	else
	{
		SC_count--;
		SC_count= (SC_count<0)? 0: SC_count;

		if(SC_count == 0)
		{
			SceneChange=0;
		}
		//else
			//ROSPrintf(" SceneChange=%d  SC_count =%d \n",SceneChange,SC_count);
	}


	RPC_SmartPic_clue->D_SceneChange = SceneChange;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		if(SceneChange!=0)
		{
			ROSPrintf(" DCC sense change =%d\n",RPC_SmartPic_clue->D_SceneChange);
			ROSPrintf(" DCC sense change, SC_count =%d\n",SC_count);
		}
	}


	// record current Hist
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
		pre_Hist[i]=reg_HistCnt[i];

}

void drvif_color_IHIST_SC(unsigned char channel)
{
	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_RPC_clues* RPC_SmartPic_clue=NULL;
	RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();
	_RPC_system_setting_info* RPC_system_info_structure_table = NULL;
	RPC_system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	if((RPC_system_info_structure_table == NULL) || (SmartPic_clue == NULL) || (RPC_SmartPic_clue==NULL) ) {
		if(MA_print_count%360==0)
			ROSPrintf("drvif_color_IHIST_SC Share Memory PQ data ERROR,RPC_system_info = %x, \n",RPC_system_info_structure_table);
		return;
	}

	static unsigned int pre_Hist[COLOR_HISTOGRAM_LEVEL] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
							       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
							       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
							       0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned char i;
	unsigned int diff_sum = 0,diff_sum_SR=0,diff_sum_SL=0,diff_sum_even_SR=0,diff_sum_odd_SR=0;
	unsigned int SC_Thl,SC_Thl_even_odd = 0;
	unsigned int SceneChange=0;
	static unsigned char SceneChange_NR=0;
	static char SC_count=0;
	static short SC_count_NR=0;
	unsigned int *reg_HistCnt=(SmartPic_clue->Y_Main_Hist);

	unsigned char diff =0,SC_ratio_offset=0;
	static unsigned char Pre_mean_value=0;
	unsigned char SC_th_ratio = 0;
        unsigned char Histo_smooth_move_shift_flag = 0;
	unsigned char video_book_flag = 0;
	unsigned int SC_Thl_video_book = 0;

	diff = abs((SmartPic_clue->Hist_Y_Mean_Value)-Pre_mean_value);
	if(diff <=10)
	{

		SC_ratio_offset=10-diff;
	}

	SC_th_ratio = 48+SC_ratio_offset;//default : 48 means 75%, per step +-(1.5625%)
	SC_Thl= ((SmartPic_clue->Hist_Y_Total_sum)*SC_th_ratio)>>6;  //SC Threshold
	SC_Thl_even_odd = SC_Thl>>1;
	SC_Thl_video_book = ((SmartPic_clue->Hist_Y_Total_sum)*3)>>1;

	Pre_mean_value = (SmartPic_clue->Hist_Y_Mean_Value);
	//scalerDrvPrint("infoTemp->MEM_ACT_WID = %d,infoTemp->MEM_ACT_LEN=%d \n",infoTemp->MEM_ACT_WID,infoTemp->MEM_ACT_LEN);
	//Total_HistCnt=0;

	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
	{
		diff_sum += (unsigned int)ABS(reg_HistCnt[i], pre_Hist[i]);
		//Total_HistCnt+=reg_HistCnt[i];
	}

	for(i=0;i<(COLOR_D_HISTOGRAM_LEVEL-1);i++)
	{
		diff_sum_SR += (unsigned int)ABS(reg_HistCnt[i+1], pre_Hist[i]);
		diff_sum_SL += (unsigned int)ABS(reg_HistCnt[i], pre_Hist[i+1]);

	}
	for(i=0;i<64;i++)//(COLOR_D_HISTOGRAM_LEVEL<<1)
	{
		diff_sum_even_SR += (unsigned int)ABS((reg_HistCnt[i*2]+reg_HistCnt[i*2+1]),(pre_Hist[i*2]+pre_Hist[i*2+1]));
		if(i<63)//(COLOR_D_HISTOGRAM_LEVEL<<1) -1
			diff_sum_odd_SR += (unsigned int)ABS((reg_HistCnt[i*2+1]+reg_HistCnt[i*2+2]),(pre_Hist[i*2+1]+pre_Hist[i*2+2]));
	}

        if(((diff_sum_even_SR>SC_Thl)&&(diff_sum_odd_SR>SC_Thl)) || ((diff_sum_even_SR>SC_Thl)&&(diff_sum_odd_SR>SC_Thl_even_odd))||((diff_sum_even_SR>SC_Thl_even_odd)&&(diff_sum_odd_SR>SC_Thl)))
	{
		Histo_smooth_move_shift_flag = 0;
	}
	else
	{
		Histo_smooth_move_shift_flag = 1;
	}

	if(RPC_system_info_structure_table->Project_ID == VIP_Project_ID_TV010)
	{
		if( ((SmartPic_clue->Hist_Y_Mean_Value)<20) && (diff_sum_SR>SC_Thl) && (diff_sum_SL>SC_Thl) &&
		    ((diff_sum+diff_sum_even_SR+diff_sum_odd_SR)>SC_Thl_video_book) &&
		    ((diff_sum_even_SR+diff_sum_odd_SR)>(SmartPic_clue->Hist_Y_Total_sum)) &&
		    (((diff_sum_even_SR*10) > diff_sum_odd_SR) && (diff_sum_even_SR < (diff_sum_odd_SR*10))))
		{
			video_book_flag = 1;
		}
		else
		{
			video_book_flag = 0 ;
		}
	}

	//diff_sum += (unsigned int)ABS((reg_HistCnt[i]+reg_HistCnt[i+1]),pre_Hist[i]+pre_Hist[i+1])
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		ROSPrintf("T=%d  d_sum=%d SC_Thl=%d\n",(SmartPic_clue->Hist_Y_Total_sum),diff_sum);
                ROSPrintf("SC_Thl=%d,SC_Thl_even_odd=%d,SC_Thl_video_book=%d \n",SC_Thl,SC_Thl_even_odd,SC_Thl_video_book);
		ROSPrintf("dR=%d  dL=%d,%d,%d\n",diff_sum_SR,diff_sum_SL,diff_sum_even_SR,diff_sum_odd_SR);
                ROSPrintf("smooth_move=%d, diff=%d\n",Histo_smooth_move_shift_flag,diff);
		ROSPrintf("Mean_Value=%d\n",(SmartPic_clue->Hist_Y_Mean_Value));
	}


	if( (((diff_sum>SC_Thl)&&(diff_sum_SR>SC_Thl)&&(diff_sum_SL>SC_Thl)&&(Histo_smooth_move_shift_flag==0))||(video_book_flag==1))&& (channel== SLR_MAIN_DISPLAY) )
	{
		SceneChange=1;                      // Scene Change detected
		SceneChange_NR=1;
		SC_count=1;//times of SC
		SC_count_NR = 10;//NR scnene change control is by the function "scalerVIP_RTNR_SceneChange_Policy()"

		//ROSPrintf("T=%d  d_sum=%d \n",(SmartPic_clue->Hist_Y_Total_sum),diff_sum);
		//ROSPrintf("SC_Thl=%d,SC_Thl_even_odd=%d,SC_Thl_video_book=%d \n",SC_Thl,SC_Thl_even_odd,SC_Thl_video_book);
		//ROSPrintf("diff_sum_SR=%d,diff_sum_SL=%d  \n",diff_sum_SR,diff_sum_SL);
		//ROSPrintf("even_SR=%d,odd_SR=%d  \n",diff_sum_even_SR,diff_sum_odd_SR);
		//ROSPrintf("diff=%d,SC_th_ratio=%d\n",diff,SC_th_ratio);
		//ROSPrintf("Mean_Value=%d\n",(SmartPic_clue->Hist_Y_Mean_Value));
/*
		for(i=0;i<32;i++)
		{
			ROSPrintf("reg_HistCnt[%d]=%d \n",i,reg_HistCnt[i]);

		}
		for(i=0;i<32;i++)
		{
			ROSPrintf("pre_reg_HistCnt[%d]=%d \n",i,pre_Hist[i]);
		}
*/

	}
	else
	{
		SC_count--;
		SC_count_NR--;
		SC_count= (SC_count<0)? 0: SC_count;
		SC_count_NR= (SC_count_NR<0)? 0: SC_count_NR;

		if(SC_count_NR == 0)
		{
			SceneChange_NR=0;
		}
		if(SC_count == 0)
		{
			SceneChange=0;
		}
		//else
			//ROSPrintf(" SceneChange=%d  SC_count =%d \n",SceneChange,SC_count);
	}

/*//for DCC I and D timing sync debug, CSFC to be continued ...
	color_dcc_d_dcc_fwused_0_RBUS ds_DCC_DUMMY_0_Reg;
	ds_DCC_DUMMY_0_Reg.regValue = rtd_inl(COLOR_DCC_D_DCC_FWUSED_0_reg);

	new_meas0_linecnt_real_RBUS new_meas0_linecnt_real_reg;
	new_meas0_linecnt_real_reg.regValue = rtd_inl(PPOVERLAY_NEW_MEAS0_LINECNT_REAL_reg);

	if((SceneChange==1)&&(ds_DCC_DUMMY_0_Reg.DCC_algo_Curve_New_mode==1))
	{
		//ROSPrintf("1 line_cnt_rt=%d\n",new_meas0_linecnt_real_reg.line_cnt_rt);
		//ROSPrintf("1 DCC sense change=%d, SC_count =%d\n",SceneChange,SC_count);
	}
*/
	RPC_SmartPic_clue->SceneChange = SceneChange;
	SmartPic_clue->SceneChange_NR= SceneChange_NR;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		if(SceneChange!=0)
		{
			ROSPrintf(" DCC sense change =%d\n",RPC_SmartPic_clue->SceneChange);
			ROSPrintf(" DCC sense change, SC_count =%d\n",SC_count);
		}
	}


	// record current Hist
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
		pre_Hist[i]=reg_HistCnt[i];

}

void drvif_color_DCC_SC_TV010(unsigned char channel)
{
#if 0
	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_system_setting_info* system_info_structure_table = NULL;
	system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	static UINT32 pre_Hist[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned char i;
	unsigned int diff_sum = 0,diff_sum_SR=0,diff_sum_SL=0,diff_sum_even_SR=0,diff_sum_odd_SR=0;
	unsigned int SC_Thl = 0,SC_Thl_even_odd = 0;
	static unsigned int SceneChange=0;
	static unsigned char SceneChange_NR=0;
	static char SC_count=0;
	static unsigned short SC_count_NR=0;
	unsigned int *reg_HistCnt=(SmartPic_clue->Y_Main_Hist);

	unsigned char diff =0,SC_ratio_offset=0;
	static unsigned char Pre_mean_value=0;
	unsigned char SC_th_ratio = 0;
	unsigned char Histo_smooth_move_shift_flag = 0;
	unsigned char video_book_flag = 0;
	unsigned int SC_Thl_video_book = 0;
	static unsigned int diff_max=0;

	diff = abs((SmartPic_clue->Hist_Y_Mean_Value)-Pre_mean_value);
	if(diff <=1)
		SC_ratio_offset=10;
	else if(diff <= 3)
		SC_ratio_offset = 5;
	else if(diff <=7)
		SC_ratio_offset = 3 ;
	else
		SC_ratio_offset = 0;


	SC_th_ratio = 48+SC_ratio_offset;//default : 48 means 75%, per step +-(1.5625%)
	SC_Thl= ((SmartPic_clue->Hist_Y_Total_sum)*SC_th_ratio)>>6;  //SC Threshold
	SC_Thl_even_odd = SC_Thl>>1;
	SC_Thl_video_book = ((SmartPic_clue->Hist_Y_Total_sum)*5)>>2;

	Pre_mean_value = (SmartPic_clue->Hist_Y_Mean_Value);
	//scalerDrvPrint("infoTemp->MEM_ACT_WID = %d,infoTemp->MEM_ACT_LEN=%d \n",infoTemp->MEM_ACT_WID,infoTemp->MEM_ACT_LEN);
	//Total_HistCnt=0;

	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
	{
		diff_sum += (UINT32)ABS(reg_HistCnt[i], pre_Hist[i]);
		//Total_HistCnt+=reg_HistCnt[i];
	}

	for(i=0;i<31;i++)
	{
		diff_sum_SR += (UINT32)ABS(reg_HistCnt[i+1], pre_Hist[i]);
		diff_sum_SL += (UINT32)ABS(reg_HistCnt[i], pre_Hist[i+1]);
	}
	for(i=0;i<16;i++)
	{
		diff_sum_even_SR += (UINT32)ABS((reg_HistCnt[i*2]+reg_HistCnt[i*2+1]),(pre_Hist[i*2]+pre_Hist[i*2+1]));
		if(i<15)
			diff_sum_odd_SR += (UINT32)ABS((reg_HistCnt[i*2+1]+reg_HistCnt[i*2+2]),(pre_Hist[i*2+1]+pre_Hist[i*2+2]));
	}
	if(((diff_sum_even_SR>SC_Thl)&&(diff_sum_odd_SR>SC_Thl)) || ((diff_sum_even_SR>SC_Thl)&&(diff_sum_odd_SR>SC_Thl_even_odd))||((diff_sum_even_SR>SC_Thl_even_odd)&&(diff_sum_odd_SR>SC_Thl)))
	{
		Histo_smooth_move_shift_flag = 0;
	}
	else
	{
		Histo_smooth_move_shift_flag = 1;
	}



	if( ((diff_sum_SR>SC_Thl) || (diff_sum_SL>SC_Thl)) &&
	    ((diff_sum+diff_sum_even_SR+diff_sum_odd_SR)>SC_Thl_video_book) &&
	    //((diff_sum_even_SR+diff_sum_odd_SR)>(SmartPic_clue->Hist_Y_Total_sum)) &&
	    (((diff_sum_even_SR*8) > diff_sum_odd_SR) && (diff_sum_even_SR < (diff_sum_odd_SR*8))))
	{
		video_book_flag = 1;
	}
	else
	{
		video_book_flag = 0;
	}

	//diff_sum += (UINT32)ABS((reg_HistCnt[i]+reg_HistCnt[i+1]),pre_Hist[i]+pre_Hist[i+1])
	//if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	if((Start_Print.ID_Pattern_195==TRUE))
	{
		if(diff_sum > diff_max)
	 		diff_max = diff_sum;
		ROSPrintf("T=%d  d_sum=%d ,diff_max=%d \n",(SmartPic_clue->Hist_Y_Total_sum),diff_sum,diff_max);
		ROSPrintf("SC_Thl=%d,SC_Thl_even_odd=%d,SC_Thl_video_book=%d \n",SC_Thl,SC_Thl_even_odd,SC_Thl_video_book);
		ROSPrintf("dR=%d  dL=%d,%d,%d\n",diff_sum_SR,diff_sum_SL,diff_sum_even_SR,diff_sum_odd_SR);
		ROSPrintf("smooth_move=%d, diff=%d\n",Histo_smooth_move_shift_flag,diff);
		ROSPrintf("Mean_Value=%d\n",(SmartPic_clue->Hist_Y_Mean_Value));
		ROSPrintf("video_book_flag =%d\n",video_book_flag);
/*
		for(i=0;i<32;i++)
		{
			ROSPrintf("reg_HistCnt[%d]=%d \n",i,reg_HistCnt[i]);

		}
		for(i=0;i<32;i++)
		{
			ROSPrintf("pre_reg_HistCnt[%d]=%d \n",i,pre_Hist[i]);
		}
*/
	}


	if( (((diff_sum>SC_Thl)&&((diff_sum_SR>SC_Thl)||(diff_sum_SL>SC_Thl)))||(video_book_flag==1))&&(Histo_smooth_move_shift_flag==0)&& (channel== SLR_MAIN_DISPLAY) )
	{
		SceneChange=1;                      // Scene Change detected
		SceneChange_NR=1;
		SC_count=5;//times of SC
		SC_count_NR = 10;//NR scnene change control is by the function "scalerVIP_RTNR_SceneChange_Policy()"
		//ROSPrintf("T=%d  d_sum=%d ,diff_max=%d \n",(SmartPic_clue->Hist_Y_Total_sum),diff_sum,diff_max);
		//ROSPrintf("SC_Thl=%d,SC_Thl_even_odd=%d,SC_Thl_video_book=%d \n",SC_Thl,SC_Thl_even_odd,SC_Thl_video_book);
		//ROSPrintf("dR=%d  dL=%d,%d,%d\n",diff_sum_SR,diff_sum_SL,diff_sum_even_SR,diff_sum_odd_SR);
		//ROSPrintf("smooth_move=%d, diff=%d\n",Histo_smooth_move_shift_flag,diff);
		//ROSPrintf("Mean_Value=%d\n",(SmartPic_clue->Hist_Y_Mean_Value));
		//ROSPrintf("video_book_flag =%d\n",video_book_flag);


	}
	else
	{
		SC_count--;
		SC_count_NR--;
		SC_count= (SC_count<0)? 0: SC_count;
		SC_count_NR= (SC_count_NR<0)? 0: SC_count_NR;

		if(SC_count_NR == 0)
		{
			SceneChange_NR=0;
		}
		if(SC_count == 0)
		{
			SceneChange=0;
		}
		//else
			//ROSPrintf(" SceneChange=%d  SC_count =%d \n",SceneChange,SC_count);
	}

	SmartPic_clue->SceneChange = SceneChange;
	SmartPic_clue->SceneChange_NR= SceneChange_NR;

	//if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	if((Start_Print.ID_Pattern_195==TRUE))
	{
		if(SceneChange)
			diff_max = 0;
		//if(SceneChange!=0)
		{
			ROSPrintf(" DCC sense change =%d\n",SmartPic_clue->SceneChange);
			ROSPrintf(" DCC sense change, SC_count =%d\n",SC_count);
		}
	}


	// record current Hist
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
		pre_Hist[i]=reg_HistCnt[i];
#endif
}

void drvif_color_DCC_SC_TV002(unsigned char channel)
{
#if 0
	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	_system_setting_info* system_info_structure_table;
	system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	unsigned char printf_Flag = system_info_structure_table->ISR_Printf_Flag.TV002_Flag;
	unsigned char print_delay = system_info_structure_table->ISR_Printf_Flag.Delay_Time;

	static unsigned int pre_Hist[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned char i;
	unsigned int diff_sum = 0,diff_sum_SR=0,diff_sum_SL=0,diff_sum_even_SR=0,diff_sum_odd_SR=0;
	unsigned int SC_Thl;
	unsigned int SceneChange=0;
	static unsigned char SceneChange_NR=0;
	static char SC_count=0;
	static short SC_count_NR=0;
	unsigned int *reg_HistCnt=(SmartPic_clue->Y_Main_Hist);

	unsigned char diff =0,SC_ratio_offset=0;
	static unsigned char Pre_mean_value=0;
	unsigned char SC_th_ratio = 0;
	//infoTemp = (StructDisplayInfo*)&scaler_disp_info[SLR_MAIN_DISPLAY];   // Erin tmp 100308
	//SC_Thl= (infoTemp->MEM_ACT_WID*infoTemp->MEM_ACT_LEN)/32;     //SC Threshold

	diff = abs((SmartPic_clue->Hist_Y_Mean_Value)-Pre_mean_value);

	/*
	if(diff <=10)
	{

		SC_ratio_offset=10-diff;
	}
	*/

	//SC_th_ratio = 48+SC_ratio_offset;//default : 48 means 75%, per step +-(1.5625%)
	SC_th_ratio = 41+SC_ratio_offset;	// modified for PQ 2009
	SC_Thl= ((SmartPic_clue->Hist_Y_Total_sum)*SC_th_ratio)>>6;  //SC Threshold

	Pre_mean_value = (SmartPic_clue->Hist_Y_Mean_Value);
	//scalerDrvPrint("infoTemp->MEM_ACT_WID = %d,infoTemp->MEM_ACT_LEN=%d \n",infoTemp->MEM_ACT_WID,infoTemp->MEM_ACT_LEN);
	//Total_HistCnt=0;

	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
	{
		diff_sum += (unsigned int)ABS(reg_HistCnt[i], pre_Hist[i]);
		//Total_HistCnt+=reg_HistCnt[i];
	}

	for(i=0;i<(COLOR_HISTOGRAM_LEVEL-1);i++)
	{
		diff_sum_SR += (unsigned int)ABS(reg_HistCnt[i+1], pre_Hist[i]);
		diff_sum_SL += (unsigned int)ABS(reg_HistCnt[i], pre_Hist[i+1]);

	}
	for(i=0;i<(COLOR_HISTOGRAM_LEVEL>>1);i++)
	{
		diff_sum_even_SR += (unsigned int)ABS((reg_HistCnt[i*2]+reg_HistCnt[i*2+1]),(pre_Hist[i*2]+pre_Hist[i*2+1]));
		if(i<15)
			diff_sum_odd_SR += (unsigned int)ABS((reg_HistCnt[i*2+1]+reg_HistCnt[i*2+2]),(pre_Hist[i*2+1]+pre_Hist[i*2+2]));
	}

	//diff_sum += (unsigned int)ABS((reg_HistCnt[i]+reg_HistCnt[i+1]),pre_Hist[i]+pre_Hist[i+1])
/*
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		ROSPrintf("T=%d  d=%d SC_Thl=%d \n",(SmartPic_clue->Hist_Y_Total_sum),diff_sum,SC_Thl);
		ROSPrintf("dR=%d  d=%d,%d,%d\n",diff_sum_SR,diff_sum_SL,diff_sum_even_SR,diff_sum_odd_SR);
	}
*/

	if( (diff_sum>SC_Thl)&&(diff_sum_SR>SC_Thl)&&(diff_sum_SL>SC_Thl)&&(diff_sum_even_SR>SC_Thl) &&((diff_sum_odd_SR>SC_Thl))&& (channel== SLR_MAIN_DISPLAY) )
	{
		SceneChange=1;                      // Scene Change detected
		SceneChange_NR=1;
		SC_count=1;//times of SC
		SC_count_NR = 10;//NR scnene change control is by the function "scalerVIP_RTNR_SceneChange_Policy()"

		//ROSPrintf("Total_HistCnt=%d,diff_sum=%d SC_Thl=%d \n",(SmartPic_clue->Hist_Y_Total_sum),diff_sum,SC_Thl);
		//ROSPrintf("diff_sum_SR=%d,diff_sum_SL=%d  \n",diff_sum_SR,diff_sum_SL);
		//ROSPrintf("even_SR=%d,odd_SR=%d  \n",diff_sum_even_SR,diff_sum_odd_SR);
		//ROSPrintf("diff=%d,SC_th_ratio=%d\n",diff,SC_th_ratio);
		//ROSPrintf("Mean_Value=%d\n",(SmartPic_clue->Hist_Y_Mean_Value));

/*
		for(i=0;i<32;i++)
		{
			ROSPrintf("reg_HistCnt[%d]=%d \n",i,reg_HistCnt[i]);

		}
		for(i=0;i<32;i++)
		{
			ROSPrintf("pre_reg_HistCnt[%d]=%d \n",i,pre_Hist[i]);
		}
*/
	}
	else
	{
		SC_count--;
		SC_count_NR--;
		SC_count= (SC_count<0)? 0: SC_count;
		SC_count_NR= (SC_count_NR<0)? 0: SC_count_NR;

		if(SC_count_NR == 0)
		{
			SceneChange_NR=0;
		}
		if(SC_count == 0)
		{
			SceneChange=0;
		}
		//else
			//ROSPrintf(" SceneChange=%d  SC_count =%d \n",SceneChange,SC_count);
	}

/*//for DCC I and D timing sync debug, CSFC to be continued ...
	color_dcc_d_dcc_fwused_0_RBUS ds_DCC_DUMMY_0_Reg;
	ds_DCC_DUMMY_0_Reg.regValue = rtd_inl(COLOR_DCC_D_DCC_FWUSED_0_reg);

	new_meas0_linecnt_real_RBUS new_meas0_linecnt_real_reg;
	new_meas0_linecnt_real_reg.regValue = rtd_inl(PPOVERLAY_NEW_MEAS0_LINECNT_REAL_reg);

	if((SceneChange==1)&&(ds_DCC_DUMMY_0_Reg.DCC_algo_Curve_New_mode==1))
	{
		//ROSPrintf("1 line_cnt_rt=%d\n",new_meas0_linecnt_real_reg.line_cnt_rt);
		//ROSPrintf("1 DCC sense change=%d, SC_count =%d\n",SceneChange,SC_count);
	}
*/
	SmartPic_clue->SceneChange = SceneChange;
	SmartPic_clue->SceneChange_NR= SceneChange_NR;
/*//for DCC I and D timing sync debug, CSFC to be continued ...	if((SceneChange==1)&&(ds_DCC_DUMMY_0_Reg.DCC_algo_Curve_New_mode==1))
	{
		//ROSPrintf("2.line_cnt_rt=%d\n",new_meas0_linecnt_real_reg.line_cnt_rt);
		//ROSPrintf("2.DCC sense change=%d, SC_count =%d\n",SceneChange,SC_count);
	}
*/
/*
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		if(SceneChange!=0)
		{
			ROSPrintf(" DCC sense change =%d\n",SmartPic_clue->SceneChange);
			ROSPrintf(" DCC sense change, SC_count =%d\n",SC_count);
		}
	}
*/

	// record current Hist
	for(i=0;i<COLOR_HISTOGRAM_LEVEL;i++)
		pre_Hist[i]=reg_HistCnt[i];

	//for debug.
	if(((printf_Flag&_BIT6)!=0))
	{
		if(MA_print_count%print_delay==0)
		{
			ROSPrintf("SC0,th=%d,di=%d,of=%d,rt=%d,\n",
			 SC_Thl, diff, SC_ratio_offset, SC_th_ratio);
		}
	}
	if(((printf_Flag&_BIT7)!=0))
	{
		if(MA_print_count%print_delay==0)
		{
			ROSPrintf("SC1,su=%d,sr=%d,sl=%d,esr=%d,osr=%d,\n",
			diff_sum, diff_sum_SR, diff_sum_SL, diff_sum_even_SR, diff_sum_odd_SR);
		}
	}
	if(((printf_Flag&_BIT8)!=0))
	{
		if(MA_print_count%print_delay==0)
		{
			ROSPrintf("SC2,sc=%d,scN=%d,scC=%d,sCN=%d,pre=%d,\n",
			SceneChange, SceneChange_NR, SC_count, SC_count_NR,Pre_mean_value);
		}
	}
#endif
}



unsigned char drvif_color_detected_black_region(unsigned char precision_mode, unsigned char DCC_SCENE_CHANGE, _clues* SmartPic_clue) // USER:haifu DATE:2011/1/10
{
	unsigned char i=0,index=0;
	unsigned char histogram_mode=100;
	unsigned short H_block_thl=0;
	unsigned int H_Block_sum=0;
	static unsigned char pre_histogram_mode=100;

	unsigned short *H_Block = &(SmartPic_clue->Profile_Cal_INFO.H_Block_Y[0]);
	//unsigned short *V_Block = &(SmartPic_clue->Profile_Cal_INFO.V_Block_Y[0]);

	profile_ich1_hist_profile_ctrl_RBUS	hist_profile_ctrl_reg;
	hist_profile_ctrl_reg.regValue = rtd_inl(PROFILE_ICH1_Hist_Profile_CTRL_reg);

	profile_ich1_hist_profile_size_RBUS hist_profile_size_reg;
	hist_profile_size_reg.regValue = rtd_inl(PROFILE_ICH1_Hist_Profile_size_reg);

	vgip_vgip_chn1_act_hsta_width_RBUS vgip_chn1_act_hsta_width_reg;
	vgip_chn1_act_hsta_width_reg.regValue  = rtd_inl(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);

	if(precision_mode !=0)
	{
		H_block_thl=20*(hist_profile_size_reg.ch1_pf_vsize * vgip_chn1_act_hsta_width_reg.ch1_ih_act_wid)>>(hist_profile_ctrl_reg.ch1_pf_hnsr+7);

		for(i=8;i<16;i++)
			H_Block_sum+=H_Block[i];

		while(index<16)
		{
			if(index>=6)
			{
				//ROSPrintf("detected_black_region Not found index=%d \n",index);
				if(DCC_SCENE_CHANGE ==1)
					pre_histogram_mode=100;
				#if 0
				printk("H_block_thl=%d \n",H_block_thl);
				printk("H_Block_sum=%d  15*H_block_thl=%d\n",H_Block_sum,15*H_block_thl);
				printk("H[0]=%d H[1]=%d H[2]=%d H[3]=%d H[4]=%d H[5]=%d H[6]=%d\n",H_Block[0],H_Block[1],H_Block[2],H_Block[3],H_Block[4],H_Block[5],H_Block[6]);
				printk("H[13]=%d H[14]=%d H[15]=%d\n",H_Block[13],H_Block[14],H_Block[15]);
				#endif

				return pre_histogram_mode;
			}
			if((H_Block[index] > H_block_thl) && (H_Block_sum > 15*H_block_thl))
			{
				//printk("H_Block_sum =%d\n",H_Block_sum);
				break;
			}
				index++;
		}
		if(index != 0)
			index=index+1;
		histogram_mode=100-((100*index*2)/48);//count percentage

	}else
	{
		H_block_thl=40*(hist_profile_size_reg.ch1_pf_vsize * vgip_chn1_act_hsta_width_reg.ch1_ih_act_wid)>>(hist_profile_ctrl_reg.ch1_pf_hnsr+7);
		if((H_Block[0] < H_block_thl) && ((H_Block[7]+H_Block[8]) > 4*H_block_thl))
			index=6;
		else
			index=0;
		histogram_mode=100-((100*index*2)/48);//count percentage
	}
	pre_histogram_mode=histogram_mode;

#if 0
	printk("H_block_thl=%d \n",H_block_thl);
	printk("H_Block_sum=%d  15*H_block_thl=%d\n",H_Block_sum,15*H_block_thl);
	printk("H[0]=%d H[1]=%d H[2]=%d H[3]=%d H[4]=%d H[5]=%d H[6]=%d\n",H_Block[0],H_Block[1],H_Block[2],H_Block[3],H_Block[4],H_Block[5],H_Block[6]);
	printk("H[13]=%d H[14]=%d H[15]=%d\n",H_Block[13],H_Block[14],H_Block[15]);
#endif

	return histogram_mode;
}


int Cubic_G0[Curve_num_Max]={0}, Cubic_G1[Curve_num_Max]={0},Temp_Main_S_Curve[Curve_num_Max]={0};
void drvif_color_DCC_Cubic_Curve(unsigned char Curve_num,int *histogram_curve,unsigned short index, char Cubic_low, char Cubic_high,unsigned char Curve_Zero_s_point,unsigned char Curve_Max_s_point)
{
	static unsigned short dcc_scurve_counter=0;
	SLR_VIP_TABLE_CUSTOM_TV002* custom_TBL_TV002 = NULL;
	int i=0;
	unsigned short Temp_index=index;
	unsigned char Temp_Curve_gain=0;
	unsigned char shift_bit=5;
	unsigned char Level_Max= 32;
	unsigned char Level_center= 16;
	//unsigned int temp_index_0 = 1,temp_index_1 = 1, temp_0=0,temp_1=0;

	int temp_p=0;
	int temp_q=0;

	if (histogram_curve == NULL)
	{
		if(MA_print_count%360==0)
		{
			ROSPrintf("\n====Memory PQ data ERROR====\n\n");
			ROSPrintf(" drvif_color_DCC_Cubic_Curve\n");
			ROSPrintf(" histogram_curve = %x\n", histogram_curve);
			ROSPrintf("\n===============================\n\n");
		}
		return;
	}

	/* only for TV002*/
	if (Scaler_access_Project_TV002_Style(0, 0) == Project_TV002_Style_1) {
		custom_TBL_TV002 = Scaler_get_tv002_Custom_struct();
		if (custom_TBL_TV002 == NULL) {
			if(MA_print_count%360==0) {
				ROSPrintf("\ndrvif_color_DCC_Cubic_Curve, custom_TBL_TV002 == NULL\n");
			}
		} else {
			Cubic_high = Cubic_high + custom_TBL_TV002->DBC.DBC_STATUS.DBC_DCC_S_High_CMPS;
			Cubic_high = (Cubic_high>32)?(32):((Cubic_high<0)?(0):(Cubic_high));
		}
	}

	Level_Max = 1<<shift_bit;
	Level_center = 1<<(shift_bit-1);

	//Temp_index = Temp_index*4;

	if(Temp_index <= 0)
		Temp_index = 1;
	else if(Temp_index > Curve_num)
		Temp_index = Curve_num;

	if(Curve_num==0)
	{
		Temp_Curve_gain = 8;// 1024/128
	}
	else
	{
		Temp_Curve_gain = (DataRange_MAX+1)/Curve_num;// 1024/128
	}

#if 0
	if(Temp_index!=0)
	{
		temp_0 = Temp_index*Temp_index;
		temp_index_0 = (1<<16)/temp_0;
	}
	else
	{
		temp_index_0 = 1;
	}

	if((Temp_index-Curve_num)!=0)
	{
		temp_1= ((Curve_num-Temp_index)*(Curve_num-Temp_index));
		temp_index_1 = (1<<16)/temp_1;
	}
	else
	{
		temp_index_1 = 1;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("gain=%d\n",Temp_Curve_gain);
		ROSPrintf("t0=%d,t1=%d\n",temp_0,temp_1);
		ROSPrintf("index=%d , num=%d \n",Temp_index,Curve_num);
		ROSPrintf("index_0=%d , index_1=%d \n",temp_index_0,temp_index_1);
	}





	for(i=0;i<=Curve_num;i++)
	{
		Cubic_G0[i]=histogram_curve[i];
		Cubic_G1[i]=0;

		if(i<Temp_index)
		{
			temp_p = (i*i*i*Temp_Curve_gain);
			temp_q = (temp_p*temp_index_0);
			Cubic_G1[i] = (temp_q>>16);// /(Temp_index*Temp_index);
			//G1[i] = ((i*i*i*Temp_Curve_gain)*temp_index_0)>>16;
		}
		else
		{
			temp_p = ((i-Curve_num)*(i-Curve_num)*(i-Curve_num)*Temp_Curve_gain);
			temp_q = temp_p*temp_index_1;
			Cubic_G1[i] = DataRange_MAX +(temp_q>>16);// /((Temp_index-Curve_num)*(Temp_index-Curve_num))));
			//G1[i] = DataRange_MAX + ((((i-Curve_num)*(i-Curve_num)*(i-Curve_num)*Temp_Curve_gain)*temp_index_1)>>16);
		}
#if 0
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
		{
			if(i%4==0)
			{
				ROSPrintf("1.i=%d,p=%d,q=%d,Gz=%d\n",i,temp_p,temp_q,G1[i]);
			}
		}
#endif
		Cubic_G1[i]=((Cubic_G1[i]) > DataRange_MAX) ? DataRange_MAX : ((Cubic_G1[i]) < 0) ? 0 : (Cubic_G1[i]);
#if 0
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
		{
			if(i%4==0)
			{
				ROSPrintf("2.i=%d,Gz=%d \n",i,Cubic_G1[i]);
			}
		}
#endif
	}
#else

	for(i=0;i<=Curve_num;i++)
	{

		Cubic_G0[i]=histogram_curve[i];

		if(i<Temp_index)
			Cubic_G1[i] = (i*i*i*Temp_Curve_gain)/(Temp_index*Temp_index);
		else
			Cubic_G1[i] = DataRange_MAX+((int)(((i-Curve_num)*(i-Curve_num)*(i-Curve_num)*Temp_Curve_gain)/((Temp_index-Curve_num)*(Temp_index-Curve_num))));

		Cubic_G1[i]=((Cubic_G1[i]) > DataRange_MAX) ? DataRange_MAX : ((Cubic_G1[i]) < 0) ? 0 : (Cubic_G1[i]);

	}



#endif

#if 1
	for(i=0;i<=Curve_num;i++)
	{
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
		{
			ROSPrintf("2.i=%d,Cubic_G1=%d\n",i,Cubic_G1[i]);
			//ROSPrintf("SC G1[0]=%d\n",G1[0]);
			//ROSPrintf("SC G1[10]=%d\n",G1[10]);
			//ROSPrintf("SC G1[20]=%d\n",G1[20]);
		}
	}
#endif

	//return;

	int max_offset=0,min_offset=0;
	int max_step=0,min_step=0, smooth_range = Curve_num-40;

	min_offset= Cubic_G1[Curve_Zero_s_point];
	max_offset= (DataRange_MAX-Cubic_G1[Curve_Max_s_point]);

	if(smooth_range==0)
	{
		min_step = 0;
		max_step = 0;
	}
	else
	{
		temp_p = (min_offset<<10);
		temp_q = (max_offset<<10);
		min_step = temp_p/smooth_range;
		max_step = temp_q/smooth_range;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("min_ofs=%d,max_ofs=%d,min_stp=%d,max_stp =%d\n",min_offset,max_offset,min_step,max_step);
	}


#if 1
	for(i=0;i<=smooth_range;i++)
	{
		if(Cubic_G1[i]>(min_offset))
		{
			//temp_p = ((min_step)*(smooth_range-i));
			//temp_q = (temp_p>>7);
			//G1[i] = G1[i]-temp_q;
			Cubic_G1[i] = Cubic_G1[i]-(((min_step)*(smooth_range-i))>>10);
		}
		else
			Cubic_G1[i] =0;
	}

	for(i=Curve_num;i>=(Curve_num-smooth_range);i--)
	{
		if(Cubic_G1[i]<(DataRange_MAX-max_offset))
		{
			//temp_p = ((max_step)*(smooth_range-(i-Curve_num)));
			//temp_q = temp_p>>7;
			//G1[i] = G1[i]+temp_q;
			Cubic_G1[i] = Cubic_G1[i]+(((max_step)*(smooth_range-(i-Curve_num)))>>10);
		}
		else
			Cubic_G1[i] =DataRange_MAX;
	}
#endif
	//return;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("Temp_Cu_ga=%d,Temp_index =%d, smooth_R=%d\n",Temp_Curve_gain,Temp_index,smooth_range);
		ROSPrintf("Cu_Zero=%d,Cu_Max =%d\n",Curve_Zero_s_point,Curve_Max_s_point);
		ROSPrintf("min_offset=%d,min_step =%d\n",min_offset,min_step);
		ROSPrintf("max_offset=%d,max_step =%d\n",max_offset,max_step);
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		for(i=0;i<=Curve_num;i++)
		{
			ROSPrintf("S_Curve G1[%d]=%d\n",i,Cubic_G1[i]);
		}
	}

	for(i=0;i<=Curve_num;i++)
	{
		if(i<Temp_index)
		{
			Temp_Main_S_Curve[i]=(int)(((Cubic_G1[i]*Cubic_low)+Cubic_G0[i]*(Level_Max-Cubic_low)+Level_center)>>shift_bit);
		}
		else
		{
			Temp_Main_S_Curve[i]=(int)(((Cubic_G1[i]*Cubic_high)+Cubic_G0[i]*(Level_Max-Cubic_high)+Level_center)>>shift_bit);
		}

		Main_S_Curve[i]=Temp_Main_S_Curve[i];
		//Main_Curve_Temp[i] =  Temp_Main_S_Curve[i];

	}

	//return;

	//check Curve must be Increasing Curve, check and do 12221 lpf
	if(Temp_Main_S_Curve[Temp_index]<Temp_Main_S_Curve[Temp_index-1])
	{
		for(i=Temp_index-5;i<=Temp_index+5;i++)
		{
			Temp_Main_S_Curve[i]=(Temp_Main_S_Curve[i-2]+Temp_Main_S_Curve[i-1]*2+Temp_Main_S_Curve[i]*2+Temp_Main_S_Curve[i+1]*2+Temp_Main_S_Curve[i+2])>>3;
			Main_S_Curve[i] = Temp_Main_S_Curve[i];
		}


	}


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
	{
		for(i=0;i<=Curve_num;i++)
		{
			ROSPrintf("Temp_Main_S_Curve[%d]=%d, 	\n",i,Temp_Main_S_Curve[i]);
		}
	}

/*
	for (i=0;i<32;i++)
		FirstOrderDiff[i]=Temp_Main_S_Curve[i+1]-Temp_Main_S_Curve[i];

	for (i=0;i<31;i++)
		SecondOrderDiff[i]=FirstOrderDiff[i+1]-FirstOrderDiff[i];
*/


#if 1
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf("!!!!!!!!!!!!!!!!In Cubic Curve!!!!!!!!!!!!!!!!!\n");
		ROSPrintf("DCC cubic curve index = %d \n",Temp_index );
		ROSPrintf("DCC cubic curve Cubic_low = %d \n",Cubic_low );
		ROSPrintf("DCC cubic curve Cubic_high = %d \n",Cubic_high );
		//ROSPrintf("G1[index]  = %d \n",G1[Temp_index]  );
	}
#endif


	dcc_scurve_counter++;

	//return *Main_Curve_Temp;

}


int Compensation_Expand_G0[Curve_num_Max];
void drvif_color_DCC_Curve_Compensation_Expand(unsigned char Curve_num,unsigned char Temp_Curve_num_gain,int* histogram_curve, unsigned char white_extend, unsigned char black_extend,unsigned char *Black_boundary_bin,unsigned char *white_boundary_bin)
{
	static unsigned short dcc_scurve_counter=0;
	unsigned short i;
	int extend_B_level=0, extend_w_level=0;
	unsigned char extend_level_max = 32, level_gain=2;
	int Black_Step_temp=0,white_Step_temp=0,Black_smooth_Step_temp=0,white_smooth_Step_temp=0;
	int Black_Step=0,white_Step=0,Black_smooth_Step=0,white_smooth_Step=0;
	unsigned char smooth_range=0;
	unsigned char white_b_point_0 = 0, white_b_point_1 = 0, Black_b_point_0 = 0,Black_b_point_1 = 0;
	white_b_point_0=(white_boundary_bin[0]*Temp_Curve_num_gain);
	white_b_point_1=(white_boundary_bin[1]*Temp_Curve_num_gain);
	Black_b_point_0=(Black_boundary_bin[0]*Temp_Curve_num_gain);
	Black_b_point_1=(Black_boundary_bin[1]*Temp_Curve_num_gain);


	for(i=0;i<=Curve_num;i++)
	{
		Compensation_Expand_G0[i]=histogram_curve[i];
	}

	extend_B_level = black_extend-extend_level_max;
	extend_w_level = white_extend-extend_level_max;

	if(abs(extend_B_level)>=extend_level_max)
		extend_B_level = (extend_B_level>=extend_level_max)?extend_level_max:(0-extend_level_max);

	if(abs(extend_w_level)>=extend_level_max)
		extend_w_level = (extend_w_level>=extend_level_max)?extend_level_max:(0-extend_level_max);

	Black_Step_temp = (extend_B_level*level_gain);
	white_Step_temp = (extend_w_level*level_gain);
	Black_smooth_Step_temp = Black_Step_temp;
	white_smooth_Step_temp = white_Step_temp;
	smooth_range = (Curve_num-white_b_point_1)-Black_b_point_1-1;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf(" DCC_extend_normal \n");
		ROSPrintf(" extend_B_level=%d,extend_w_level=%d \n",extend_B_level,extend_w_level);
		ROSPrintf(" Black_Step_temp=%d,white_Step_temp=%d \n",Black_Step_temp,white_Step_temp);
		ROSPrintf(" Black_smooth_Step_temp=%d,white_smooth_Step_temp=%d \n",Black_smooth_Step_temp,white_smooth_Step_temp);
		ROSPrintf(" smooth_range=%d \n",smooth_range);
	}

	for(i=0;i<=Curve_num;i++)
	{
		if((i>Black_b_point_0)&&(i<=Black_b_point_1))//for black region_2 control
		{
			Black_Step = (Black_Step_temp*(i-Black_b_point_0))/(Black_b_point_1-Black_b_point_0);
			Compensation_Expand_G0[i]=(int)histogram_curve[i] + Black_Step;
		}
		else if( (i>Black_b_point_1) && (i<(Curve_num-white_b_point_1)))//for black region_2 smooth
		{
			Black_smooth_Step= (Black_smooth_Step_temp*((Curve_num-white_b_point_1)-i))/smooth_range;
			Compensation_Expand_G0[i] = (int)histogram_curve[i] + Black_smooth_Step;
		}

		if((i>=(Curve_num-white_b_point_1))&&(i<(Curve_num-white_b_point_0)))//for white region_2 control
		{
			white_Step = (white_Step_temp*((Curve_num-white_b_point_0)-i))/(white_b_point_1-white_b_point_0);
			Compensation_Expand_G0[i]=(int)histogram_curve[i] + white_Step;
		}
		else if( (i>Black_b_point_1) && (i<(Curve_num-white_b_point_1)))//for white region_2 smooth
		{
			white_smooth_Step= (white_smooth_Step_temp*(i-Black_b_point_1))/smooth_range;
			Compensation_Expand_G0[i] = (int)histogram_curve[i]+white_smooth_Step;
		}

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
		{
			ROSPrintf("[%d] Black_Step=%d,white_Step=%d \n",i,Black_Step,white_Step);
			ROSPrintf("[%d] Black_smooth_Step=%d,white_smooth_Step=%d \n",i,Black_smooth_Step,white_smooth_Step);
			ROSPrintf("[%d] G0=%d,histogram_curve=%d \n",i,Compensation_Expand_G0[i],histogram_curve[i]);
		}

		Main_extend_Curve[i]=(int)Compensation_Expand_G0[i];
		//Main_Curve_Temp[i]=(int)G0[i];

	}
/*
	for(i=0;i<=Curve_num;i++)
	{
		//Main_extend_Curve[i]=(int)G0[i];
		Main_Curve_Temp[i]=(int)G0[i];
	}
*/
	dcc_scurve_counter++;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE))
	{
		ROSPrintf(" DCC_extend_normal \n");
		ROSPrintf(" extend_curve <G0> \n");
		//ROSPrintf(" white_index=%d,black_index=%d \n",white_index,black_index);
		ROSPrintf(" white_extend=%d,black_extend=%d \n",white_extend,black_extend);
		ROSPrintf(" bb_bin[0]=%d,bb_bin[1]=%d \n",Black_b_point_0,Black_b_point_1);
		ROSPrintf(" wb_bin[0]=%d,wb_bin[1]=%d \n",white_b_point_0,white_b_point_1);
		for(i = 0; i <=Curve_num; i++)
		{
			ROSPrintf(" hist_curve[%d]=%d \n",i,histogram_curve[i]);
		}

		ROSPrintf(" blending_curve <Main_extend_Curve> \n");
		for(i = 0; i <=Curve_num; i++)
		{
			ROSPrintf(" Extend_Curve[%d]=%d \n",i,Main_extend_Curve[i]);
			//ROSPrintf(" Extend_Curve[%d]=%d \n",i,Main_Curve_Temp[i]);
		}

	}

	//return *Main_Curve_Temp;

}


int User_Define_Curve_G0[Curve_num_Max], User_Define_Curve_G1[Curve_num_Max], User_Define_Curve_dcc0[Curve_num_Max], User_Define_Curve_dcc1[Curve_num_Max];

void drvif_color_DCC_User_Define_Curve_DCC(unsigned char Curve_num,int* histogram_curve, VIP_USER_DEFINE_CURVE_DCC_CRTL_ITEM *USER_DEFINE_CURVE_DCC_CRTL_ITEM, unsigned int DCC_HISTO_MEAN_VALUE,unsigned char skin_tone_found_flag,unsigned char Curve_Zero_s_point,unsigned char Curve_Max_s_point)
{
	unsigned char i;
	unsigned char curve_index;
	unsigned char level_max=32, shift_bit =5;//max of blending Weight.
	int y_th0, y_th1;
	unsigned char weighting;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
		ROSPrintf("[VPQ][DCC]=== DCC_User_Define_Curve_DCC ===\n");
	    	ROSPrintf("[VPQ][DCC]MEAN_VALUE=%d,skin_tone=%d \n",DCC_HISTO_MEAN_VALUE,skin_tone_found_flag);
	}

	USER_CURVE_DCC_HisMean_th_ITEM *DCC_HisMean_th = &(USER_DEFINE_CURVE_DCC_CRTL_ITEM->USER_CURVE_Weight_Mapping.USER_CURVE_DCC_HisMean_th);
	USER_CURVE_DCC_HisSeg_Weighting_ITEM *HisSeg_Weighting=&(USER_DEFINE_CURVE_DCC_CRTL_ITEM->USER_CURVE_Weight_Mapping.USER_CURVE_DCC_HisSeg_Weighting);
	unsigned int  *g_user_define_curve_dcc_table=&(USER_DEFINE_CURVE_DCC_CRTL_ITEM->user_define_curve_dcc_table[0][0]);

	//avoid crash
	if((DCC_HisMean_th->USER_DEFINE_CURVE_DCC_CURVE_NUM)>=USER_DEFINE_CURVE_DCC_CURVE_SKIN) {
		if(MA_print_count%250==0)
			ROSPrintf("[VPQ][DCC]USER_DEFINE_CURVE_DCC_CURVE_NUM error\n");
		return;
	}
	//Step 1 : Get Blending Curve index by MEAN_VALUE
	for(curve_index=0;curve_index<(DCC_HisMean_th->USER_DEFINE_CURVE_DCC_CURVE_NUM);curve_index++) {// get current index for Curve blending by APL
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
	   		 ROSPrintf("[VPQ][DCC]HisMean_th[%d] \n",curve_index);
		}
		//if(DCC_HISTO_MEAN_VALUE<=((&(DCC_HisMean_th->APL_th0))[curve_index]))
		if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th0)))&&(curve_index==0))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th1)))&&(curve_index==1))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th2)))&&(curve_index==2))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th3)))&&(curve_index==3))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th4)))&&(curve_index==4))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th5)))&&(curve_index==5))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th6)))&&(curve_index==6))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th7)))&&(curve_index==7))
			break;
		else if((DCC_HISTO_MEAN_VALUE<=((DCC_HisMean_th->APL_th8)))&&(curve_index==8))
			break;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
	    ROSPrintf("[VPQ][DCC]DCC_CURVE_NUM=%d, curve_index=%d\n",DCC_HisMean_th->USER_DEFINE_CURVE_DCC_CURVE_NUM,curve_index);
	}

	//check Current Status for Blending
	if(skin_tone_found_flag==1) {
		for(i=0;i<=Curve_num;i++)
			User_Define_Curve_G1[i] = (int)(*(g_user_define_curve_dcc_table+(USER_DEFINE_CURVE_DCC_CURVE_SKIN*USER_DEFINE_CURVE_DCC_SEGMENT_NUM)+i));
	} else if(curve_index == 0) {//mean value < th0, use curve 0

		for(i=0;i<=Curve_num;i++)
			User_Define_Curve_G1[i] = (int)(*(g_user_define_curve_dcc_table+(USER_DEFINE_CURVE_DCC_CURVE_LEVEL0*USER_DEFINE_CURVE_DCC_SEGMENT_NUM)+i));

	} else if(curve_index == (DCC_HisMean_th->USER_DEFINE_CURVE_DCC_CURVE_NUM)){ //mean value > last th setting

		for(i=0;i<=Curve_num;i++)
			User_Define_Curve_G1[i] = (int)(*(g_user_define_curve_dcc_table+((curve_index-1)*USER_DEFINE_CURVE_DCC_SEGMENT_NUM)+i));

	} else {// blending curve

		//Step 2 : Get Y_th by Mean Value index
//		y_th0 =	((&(DCC_HisMean_th->APL_th0))[curve_index-1]);
//		y_th1 = ((&(DCC_HisMean_th->APL_th0))[curve_index]);
		if(curve_index==1){
			y_th0 = ((DCC_HisMean_th->APL_th0));
			y_th1 = ((DCC_HisMean_th->APL_th1));
		}else if(curve_index==2){
			y_th0 = ((DCC_HisMean_th->APL_th1));
			y_th1 = ((DCC_HisMean_th->APL_th2));
		}else if(curve_index==3){
			y_th0 = ((DCC_HisMean_th->APL_th2));
			y_th1 = ((DCC_HisMean_th->APL_th3));
		}else if(curve_index==4){
			y_th0 = ((DCC_HisMean_th->APL_th3));
			y_th1 = ((DCC_HisMean_th->APL_th4));
		}else if(curve_index==5){
			y_th0 = ((DCC_HisMean_th->APL_th4));
			y_th1 = ((DCC_HisMean_th->APL_th5));
		}else if(curve_index==6){
			y_th0 = ((DCC_HisMean_th->APL_th5));
			y_th1 = ((DCC_HisMean_th->APL_th6));
		}else if(curve_index==7){
			y_th0 = ((DCC_HisMean_th->APL_th6));
			y_th1 = ((DCC_HisMean_th->APL_th7));
	}



		if((y_th1 - y_th0)==0) {
			if(MA_print_count%250==0)
				ROSPrintf("[VPQ][DCC]y_tmp = y_th1 - y_th0=0\n");
			return;
		}

		//Step 3 : Get Mix Curve. Blending by mean Value.
		for(i=0;i<=Curve_num;i++){
			User_Define_Curve_dcc0[i] = (int)(*(g_user_define_curve_dcc_table+((curve_index-1)*USER_DEFINE_CURVE_DCC_SEGMENT_NUM)+i));
			User_Define_Curve_dcc1[i] = (int)(*(g_user_define_curve_dcc_table+((curve_index)*USER_DEFINE_CURVE_DCC_SEGMENT_NUM)+i));
			if(User_Define_Curve_dcc1[i] >= User_Define_Curve_dcc0[i])
				User_Define_Curve_G1[i] = (DCC_HISTO_MEAN_VALUE - y_th0) * (User_Define_Curve_dcc1[i] - User_Define_Curve_dcc0[i]) / (y_th1 - y_th0) + User_Define_Curve_dcc0[i];
			else
				User_Define_Curve_G1[i] =  User_Define_Curve_dcc0[i] - (DCC_HISTO_MEAN_VALUE - y_th0)*(User_Define_Curve_dcc0[i] - User_Define_Curve_dcc1[i])/(y_th1 - y_th0);
		}

	}

	// Get bounded user curve.
	if((Curve_Zero_s_point || Curve_Max_s_point) && (Curve_Max_s_point-Curve_Zero_s_point)) {
		int tmp_User_Define_Curve_G1[Curve_num_Max];
		int factor = (Curve_num<<10)/(Curve_Max_s_point-Curve_Zero_s_point);
		int index;

		for(i=0;i<=Curve_num;i++) {
			if(i<=Curve_Zero_s_point) {
				tmp_User_Define_Curve_G1[i] = 0;
				index = 0;
			} else if(i>=Curve_Max_s_point) {
				tmp_User_Define_Curve_G1[i] = DataRange_MAX;
				index = Curve_num;
			} else {
				index = (i-Curve_Zero_s_point)*factor>>10;
				tmp_User_Define_Curve_G1[i] = User_Define_Curve_G1[index];
			}
		}

		for(i=0;i<=Curve_num;i++)
			User_Define_Curve_G1[i] = tmp_User_Define_Curve_G1[i];
	}

	//Step 3 : Get User Curve Blending Weight!
	if(skin_tone_found_flag==1) {
		weighting = HisSeg_Weighting->APL_skin_WEIGHTING;
	} else {
		//weighting = (&(HisSeg_Weighting->APL_seg0_WEIGHTING))[curve_index];
		if(curve_index==0){
			weighting = ((HisSeg_Weighting->APL_seg0_WEIGHTING));
		}else if(curve_index==1){
			weighting = ((HisSeg_Weighting->APL_seg1_WEIGHTING));
		}else if(curve_index==2){
			weighting = ((HisSeg_Weighting->APL_seg2_WEIGHTING));
		}else if(curve_index==3){
			weighting = ((HisSeg_Weighting->APL_seg3_WEIGHTING));
		}else if(curve_index==4){
			weighting = ((HisSeg_Weighting->APL_seg4_WEIGHTING));
		}else if(curve_index==5){
			weighting = ((HisSeg_Weighting->APL_seg5_WEIGHTING));
		}else if(curve_index==6){
			weighting = ((HisSeg_Weighting->APL_seg6_WEIGHTING));
		}else if(curve_index==7){
			weighting = ((HisSeg_Weighting->APL_seg7_WEIGHTING));
		}else if(curve_index==8){
			weighting = ((HisSeg_Weighting->APL_seg8_WEIGHTING));
		}else{
			weighting = ((HisSeg_Weighting->APL_seg9_WEIGHTING));
		}

	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
		ROSPrintf("[VPQ][DCC] curve_index=%d, weighting=%d \n",curve_index, weighting );
	}

	//Step 4 : blending with original DCC curve
	for(i=0;i<=Curve_num;i++){
		User_Define_Curve_G0[i]=histogram_curve[i];
		Main_User_Define_Curve[i]= weighting*User_Define_Curve_G0[i] + (level_max - weighting)*User_Define_Curve_G1[i];
		Main_User_Define_Curve[i] = Main_User_Define_Curve[i]>>shift_bit;
		//Main_Curve_Temp[i]= weighting*G0[i] + (level_max - weighting)*G1[i];
		//Main_Curve_Temp[i] = Main_Curve_Temp[i]>>shift_bit;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
		for(i=0;i<(Curve_num+1);i++) {
			ROSPrintf("[VPQ][DCC] G0[%d]=%d,G1[%d]=%d,weighting = %d \n",i,User_Define_Curve_G0[i],i,User_Define_Curve_G1[i],weighting );
		}
	}

	//return *Main_Curve_Temp;

}


void scalerVIP_DCC_Curve_smooth(int* DCurve,unsigned char Curve_num,unsigned char filter_tap,unsigned char Curve_Zero_s_point, unsigned char Curve_Max_s_point)
{
	//== smooth ==
	int filter[3]={1,2,1}; // 1->3tap
	int filter_5tap[5]={1,2,2,2,1};// 2-> 5tap
	int filter_7tap[7]={1,2,2,2,2,2,1};// 3-> 7tap
	int filter_9tap[9]={1,2,2,2,2,2,2,2,1};// 4-> 9tap
	int filter_11tap[11]={1,2,2,2,2,2,2,2,2,2,1};// 5-> 11tap
	//int DCC_smooth_Curve[Curve_num_Max];
	int m, id, i;
	int sum_filter = 0;
	int LPF_start = 0, LPF_END = Curve_num_Max; //Curve point : Total 33 points ( before Sirius )
	unsigned char tap_sum=0, tap_num=0;
	//int temp_offset=0, temp_gain=0;


	LPF_start = Curve_Zero_s_point;
	LPF_END = Curve_Max_s_point;

	id=0;
	m=0;
	i=0;

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
	{
#if DCC_Curve_Debug_flag
		ROSPrintf("Curve LPF, LPF_start=%d,LPF_END=%d \n ", LPF_start, LPF_END);
		ROSPrintf("Curve LPF, filter_tap=%d \n ", filter_tap);
		for(i=0;i<(Curve_num+1);i++)
		{
			ROSPrintf("Curve LPF,Before:DCurve[%d]=%d, Main_preH[%d] =%d \n ",i,DCurve[i],i,Main_preH[i]);
		}
#endif
	}

	if(filter_tap==1)
	{
		tap_num=1;
	}
	else if(filter_tap==2)
	{
		tap_num=2;
	}
	else if (filter_tap==3)
	{
		tap_num=3;
	}
	else if (filter_tap==4)
	{
		tap_num=4;
	}
	else if (filter_tap==5)
	{
		tap_num=5;
	}

	if((filter_tap<=5) && (filter_tap!=0) )
	{
		for(m=-tap_num;m<=tap_num;m++)
		{
			if(filter_tap==1)
			{
				// KWarning: checked ok by rock_rau@realtek.com
				tap_sum += filter[m+1];
			}
			else if(filter_tap==2)
			{
				// KWarning: checked ok by rock_rau@realtek.com
				tap_sum += filter_5tap[m+2];
			}
			else if(filter_tap==3)
			{
				// KWarning: checked ok by rock_rau@realtek.com
				tap_sum += filter_7tap[m+3];
			}
			else if(filter_tap==4)
			{
				// KWarning: checked ok by rock_rau@realtek.com
				tap_sum += filter_9tap[m+4];
			}
			else if( filter_tap==5 )
			{
				// KWarning: checked ok by rock_rau@realtek.com
				tap_sum += filter_11tap[m+5];
			}
		}

		if(tap_sum<=0)
			return;

		for(i=0;i<(Curve_num+1);i++)
		{
			sum_filter=0;
			if((i>LPF_start) && (i<LPF_END))
			{
				for(m=-tap_num;m<=tap_num;m++)
				{
					id=i+m;
					if(id<(0))//boundary condition repeat method
						id=0;
					if(id>((Curve_num+1)-1))//boundary condition repeat method
						id=((Curve_num+1)-1);

					if(tap_num==1)
					{
						// KWarning: checked ok by rock_rau@realtek.com
						sum_filter += DCurve[id]*filter[m+1];
					}
					else if(tap_num==2)
					{
						// KWarning: checked ok by rock_rau@realtek.com
						sum_filter += DCurve[id]*filter_5tap[m+2];
					}
					else if (tap_num==3)
					{
						// KWarning: checked ok by rock_rau@realtek.com
						sum_filter += DCurve[id]*filter_7tap[m+3];
					}
					else if (tap_num==4)
					{
						// KWarning: checked ok by rock_rau@realtek.com
						sum_filter += DCurve[id]*filter_9tap[m+4];
					}
					else if (tap_num==5)
					{
						// KWarning: checked ok by rock_rau@realtek.com
						sum_filter += DCurve[id]*filter_11tap[m+5];
					}
				}

				Main_Curve_Temp[i]=(sum_filter+(tap_sum>>1))/tap_sum;

			}
			else
			{
				Main_Curve_Temp[i] = DCurve[i];
			}
		}


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
	{
#if DCC_Curve_Debug_flag
		for(i=0;i<(Curve_num+1);i++)
		{
			//ROSPrintf("Curve LPF,After:DCurve[%d]=%d \n ",i,Main_Curve_Temp[i]);
		}
		ROSPrintf("Curve LPF,After:start=%d, end=%d \n ",Main_Curve_Temp[LPF_start],Main_Curve_Temp[LPF_END]);
#endif
	}

#if 0 //. don't do remap in curve smooth function.
		if(Main_Curve_Temp[LPF_start]!=0)
		{
			temp_offset = Main_Curve_Temp[LPF_start];
			temp_gain =  (Main_Curve_Temp[Curve_num]<<10); // (DataRange_MAX<<10);
			temp_gain = temp_gain/((Main_Curve_Temp[Curve_num]-temp_offset));
			for(i=0;i<(Curve_num+1);i++)
			{
				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
				{
					ROSPrintf("Main_Curve_Temp[%d]=%d,diff=%d\n ",i,Main_Curve_Temp[i],(Main_Curve_Temp[i]-temp_offset));
				}

				if((Main_Curve_Temp[i]>=temp_offset))
				{
					Main_Curve_Temp[i] = ((Main_Curve_Temp[i]-temp_offset)*temp_gain)>>10;
				}
				else
				{
					Main_Curve_Temp[i] = 0;
				}
			}
		}
#endif

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
		{
#if DCC_Curve_Debug_flag
			ROSPrintf("smooth tap_sum=%d\n ",tap_sum);
#endif
		}

	}

}




unsigned int HistCnt_ratio[COLOR_HISTOGRAM_LEVEL],HistCnt_entry[COLOR_HISTOGRAM_LEVEL];
unsigned int database_entry[Histogram_adjust_bin_num],database_ratio[Histogram_adjust_bin_num],database_histogram[Histogram_adjust_bin_num];


void database_DCC(unsigned char bin,unsigned char Curve_num,unsigned char database_DCC_Table,unsigned int Total_HCnt,VIP_DCC_Control_Structure *DCC_Control_Structure)
{

	// Get SmartPic_clue Information
	_clues* SmartPic_clue=NULL;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();

	if(SmartPic_clue == NULL) {
		if(MA_print_count%360==0)
			ROSPrintf("database_DCC Share Memory PQ data ERROR,SmartPic_clue = %x, \n",SmartPic_clue);
		return;
	}

	RPC_DCC_LAYER_Array_Struct *g_DCC_LAYER_Array_Struct = &(SmartPic_clue->Adapt_DCC_Info.S_RPC_DCC_LAYER_Array);

	unsigned int databaseDCC_mode = 0;
	unsigned int gain = 0;
	unsigned int adjust_lowerbound = 0;
	unsigned int adjust_upperbound = 0;
	unsigned int gain_boundary=0;
	unsigned int *HistCnt=NULL;
	unsigned int inner_product=0;
	unsigned char i,j,k,z;
	static unsigned int print_count=0;
	unsigned int max_vector_length=0;
	unsigned int blending_ratio =0;
	unsigned int inner_product_MAX=0;
	unsigned int inner_product_MAX_index=0;
	unsigned short weight_boundary = 223, shift_bit=5,blending_boundary=0;
	unsigned int database_hist_check = 0;
	unsigned char Passivation_offset = 2;// 2 => 1<<2 = 4 = 128/32 = COLOR_HISTOGRAM_LEVEL/Histogram_adjust_bin_num
	unsigned char Passivation_index = 0 , Passivation_adaptive = 0;
	unsigned char Passivation_sum_bound = 1;
	unsigned char Passivation_index_for_TOOL = 0;
	unsigned char Passivation_sum_bound_for_TOOL = 1;
	unsigned int tmp_database_curve[Curve_num_Max] = {0};
	unsigned int tmp_database_curve1[Curve_num_Max] = {0};

	color_dcc_d_dcc_fwused_0_RBUS  d_dcc_fwused_0_reg;
	d_dcc_fwused_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_FWUSED_0_reg);


	Passivation_adaptive = d_dcc_fwused_0_reg.res1;

	VIP_DCC_Database_Curve_CRTL_Table *g_Database_Curve_defined_Item = NULL;
	blending_boundary = 1<<shift_bit;
	gain_boundary = 1<<shift_bit;

	Passivation_index_for_TOOL = 1<<(Passivation_offset);
	Passivation_sum_bound_for_TOOL = Passivation_index_for_TOOL - 1;

	Passivation_index = 1<<(Passivation_offset + Passivation_adaptive);
	Passivation_sum_bound = Passivation_index - 1;

	//avoid crash
	if(DCC_Control_Structure == NULL) {
		if(MA_print_count%250==0)
			ROSPrintf("share mem vip table = Null, database_DCC\n");
		return;
	}
#if 0
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
		for (j=0;j<Database_DCC_Curve_Case_Item_MAX;j++) {
			g_Database_Curve_defined_Item = &(DCC_Control_Structure->Database_Curve_CRTL_Table[database_DCC_Table][j]);
			for (i=0;i<bin;i++) {
				ROSPrintf("[NO. %d]database_histogram[%d]=%d\n",j,i,(g_Database_Curve_defined_Item->database_histogram[i]));
			}
		}
	}
#endif

	//matrix reset to 0
	for (i=0;i<Histogram_adjust_bin_num;i++) {
		database_entry[i] = 0;
	}


	//o-----Input Image histogram vector------o
	HistCnt= (SmartPic_clue->Y_Main_Hist);
	unsigned long long tmplonglong;
	k= 0;
	for (i=0;i<bin;i++) {

		/*step1: normalized to 4096 for sqrt_table remapping*/
		tmplonglong = HistCnt[i];
		tmplonglong = tmplonglong<<12;
		do_div(tmplonglong, (Total_HCnt+1));
		HistCnt_ratio[i]= tmplonglong;
		//HistCnt_ratio[i]= (tmplonglong/(Total_HCnt+1));//range : 0~4096

		/*step2: remapping by sqrt_table-> this information is for debug checking!!*/
		HistCnt_entry[i]= DCCsqrt_table[(HistCnt_ratio[i])];//for ensure the inner product do not overflow

		k = i>>(Passivation_offset );
		if( i%Passivation_index_for_TOOL == Passivation_sum_bound_for_TOOL ){
			database_ratio[k] = 0;
			for(z=0;z<Passivation_index_for_TOOL;z++){
				database_ratio[k]+=HistCnt_ratio[(k*Passivation_index_for_TOOL)+z];
			}
			/*step2: remapping by sqrt_table*/
			g_DCC_LAYER_Array_Struct->Database_entry_Histogram[k]= ((DCCsqrt_table[(database_ratio[k])])>>8);//for ensure the inner product do not overflow
		}
		#if 0
		if( i%Passivation_index == Passivation_sum_bound){

			database_ratio[k] = 0;
			database_entry[k] = 0;
			for(z=0;z<Passivation_index;z++){
				//database_ratio[k]+=HistCnt_ratio[(k*Passivation_index)+z];
				database_entry[k]+=HistCnt_entry[(k*Passivation_index)+z];
			}
			/*step2: remapping by sqrt_table*/
			//database_entry[k]= DCCsqrt_table[(database_ratio[k])];//for ensure the inner product do not overflow

		}
		#else

		k = i>>(Passivation_offset + Passivation_adaptive);
		if( i%Passivation_index == Passivation_sum_bound){
			database_ratio[k] = 0;
			for(z=0;z<Passivation_index;z++){
				database_ratio[k]+=HistCnt_ratio[(k*Passivation_index)+z];
			}
			/*step2: remapping by sqrt_table*/
			database_entry[k]= DCCsqrt_table[(database_ratio[k])];//for ensure the inner product do not overflow
		}
		#endif

	}
#if 0
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
		for (i=0;i<COLOR_HISTOGRAM_LEVEL;i++) {
			ROSPrintf("1.[VPQ][DCC] HistCnt_ratio[%d] = %d, %d\n",i,HistCnt_ratio[i], HistCnt_entry[i]);
		}
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
		for (i=0;i<Histogram_adjust_bin_num;i++) {
			ROSPrintf("1.[VPQ][DCC] database_entry[%d] = %d\n",i,database_entry[i]);
		}
	}
#endif
	//o-----matching by Database histogram vector item------o
	unsigned int tmpint_sum, tmpint;
	Passivation_index = 1<<(Passivation_adaptive);
	Passivation_sum_bound = Passivation_index - 1;
	k= 0;
	for (j=0;j<Database_DCC_Curve_Case_Item_MAX;j++) {
		g_Database_Curve_defined_Item = &(DCC_Control_Structure->Database_Curve_CRTL_Table[database_DCC_Table][j]);


		for (i=0;i<Histogram_adjust_bin_num;i++) {
			database_hist_check += (g_Database_Curve_defined_Item->database_histogram[i]);
		}

		if(database_hist_check == 0){
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
				ROSPrintf("[VPQ][DCC] break!! database_histogram[%d]\n",j);
			}
			break;
		}

		for (i=0;i<Histogram_adjust_bin_num;i++) {

			k = i>>(Passivation_adaptive);
			tmpint_sum = 0;
			if(Passivation_adaptive != 0){
				if( i%Passivation_index == Passivation_sum_bound){
					database_histogram[k] = 0;
					for(z=0;z<Passivation_index;z++){
						tmpint = (g_Database_Curve_defined_Item->database_histogram[(k*Passivation_index)+z]);
						tmpint = tmpint*tmpint;
						tmpint = tmpint>>4;
						tmpint_sum += tmpint;
						//database_histogram[k] += (g_Database_Curve_defined_Item->database_histogram[(k*Passivation_index)+z]);
					}
					database_histogram[k] = DCCsqrt_table[tmpint_sum]>>8;// 2^10 -> 2^2
					inner_product += database_histogram[k]*database_entry[k];
				}
			} else {
				inner_product+=((g_Database_Curve_defined_Item->database_histogram[i]) * database_entry[i]);
			}
		}
#if 0

		if((MA_print_count%debug_print_delay_time==0)&&((Start_Print.Dcc_2==TRUE)|| ( Passivation_adaptive != 0 ))) {
			ROSPrintf("[VPQ][DCC] inner_product[%d] = %d\n",j,inner_product);
		}
#endif
		if (inner_product>inner_product_MAX){
			inner_product_MAX_index = j;
			inner_product_MAX = inner_product;
		}

		inner_product=0;
		database_hist_check =0;
	}

	max_vector_length=DCCsqrt_table[4095]<<8;//<<8>>10
#if 1
	if((MA_print_count%debug_print_delay_time==0)&&((Start_Print.Dcc_2==TRUE)|| ( Passivation_adaptive != 0 ))) {
		ROSPrintf("[VPQ][DCC]inner_product_MAX_index=%d\n",inner_product_MAX_index);
		ROSPrintf("[VPQ][DCC]inner_product_MAX=%d\n",inner_product_MAX);
		ROSPrintf("[VPQ][DCC]max_vector_length=%d\n",max_vector_length);
	}
/*
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
		g_Database_Curve_defined_Item = &(DCC_Control_Structure->Database_Curve_CRTL_Table[database_DCC_Table][inner_product_MAX_index]);
		for (i=0;i<Histogram_adjust_bin_num;i++) {
			ROSPrintf("[NO. %d]database_histogram[%d]=%d\n",inner_product_MAX_index,i,(g_Database_Curve_defined_Item->database_histogram[i]));
		}
	}
*/
#endif
	//o--- get max inner product databaseCurve---o

	g_Database_Curve_defined_Item = &(DCC_Control_Structure->Database_Curve_CRTL_Table[database_DCC_Table][inner_product_MAX_index]);

	databaseDCC_mode = g_Database_Curve_defined_Item->database_adjust[0];
	gain = g_Database_Curve_defined_Item->database_adjust[1];
	adjust_lowerbound = g_Database_Curve_defined_Item->database_adjust[2];
	adjust_upperbound = g_Database_Curve_defined_Item->database_adjust[3];

	tmplonglong = inner_product_MAX;
	tmplonglong = tmplonglong<<8;
	do_div(tmplonglong, (max_vector_length+1));

	blending_ratio = tmplonglong;//define blending ratio
	if (blending_ratio>=255) {
		blending_ratio=255;
	}
#if 0
	if((MA_print_count%debug_print_delay_time==0)&&((Start_Print.Dcc_2==TRUE)|| ( Passivation_adaptive != 0 ))) {
		ROSPrintf("[VPQ][DCC]blending_ratio=%d\n",blending_ratio);
	}
#endif




	if(blending_ratio >= weight_boundary) {
		if((blending_ratio-weight_boundary)>= blending_boundary ){
			blending_ratio = blending_boundary;
		} else {
			blending_ratio = blending_ratio - weight_boundary;
		}



		if(databaseDCC_mode == 0)  //Disable the index
		{
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
				ROSPrintf("Disable the nidex\n");
			}
			for(i=0;i<(Curve_num+1);i++) {
				Main_database_Curve[i]=(int)Gz[i];
			}
		}
		else if(databaseDCC_mode == 1)  //default mode
		{
			for(i=0;i<(Curve_num+1);i++) {
				Main_database_Curve[i]=(int)(((blending_boundary-blending_ratio)*Gz[i])+((blending_ratio)*(g_Database_Curve_defined_Item->database_curve[i])))>>shift_bit;
				//Main_Curve_Temp[i]=(int)(((256-blending_ratio)*Gz[i])+((blending_ratio-weight_boundary)*(g_Database_Curve_defined_Item->database_curve[i])))>>shift_bit;
			}

			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
				ROSPrintf("[[[0-9]]]Main_database_Curve = \n[");//
				for(i=0;i<(Curve_num+1);i++)//
					{//
						ROSPrintf("%d, ",Main_database_Curve[i]);//
				}//
				ROSPrintf("]\n\n");//
			}


		}

		else if(databaseDCC_mode == 2) //replacing mode , smoothing by weighting
		{
			int adjust_weighting = gain;
			for(i=0;i<(Curve_num+1);i++)
			{
				adjust_weighting = gain;
				if(i >= adjust_lowerbound && i <= adjust_upperbound)
				{
					if(abs(adjust_lowerbound - i) > abs(adjust_upperbound - i))
					{
						adjust_weighting = (gain>>1) + abs(adjust_lowerbound - i);
					}
					else
					{
						adjust_weighting = (gain>>1) + abs(adjust_upperbound - i);
					}
					if(adjust_weighting > gain)
						adjust_weighting = gain;

					Main_database_Curve[i]=(int)(((gain_boundary-adjust_weighting)*Gz[i])+((adjust_weighting)*(g_Database_Curve_defined_Item->database_curve[i])))>>shift_bit;
				}
				else if(i < adjust_lowerbound)
				{
					adjust_weighting = (gain>>1) - abs(adjust_lowerbound - i);
					if(adjust_weighting < 0)
						adjust_weighting = 0;

					Main_database_Curve[i]=(int)(((gain_boundary-adjust_weighting)*Gz[i])+((adjust_weighting)*(g_Database_Curve_defined_Item->database_curve[i])))>>shift_bit;
				}
				else if(i > adjust_upperbound)
				{
					adjust_weighting = (gain>>1) - abs(adjust_upperbound - i);
					if(adjust_weighting < 0)
						adjust_weighting = 0;

					Main_database_Curve[i]=(int)(((gain_boundary-adjust_weighting)*Gz[i])+((adjust_weighting)*(g_Database_Curve_defined_Item->database_curve[i])))>>shift_bit;
				}
			}
		}
		else
		{
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
				ROSPrintf("Error: databaseDCC_mode is not in control range.\n");
			}
		}



		//====== SmartPic_clue info for DCC TOOL =========
		SmartPic_clue->Adapt_DCC_Info.database_case_num = inner_product_MAX_index;//range 0~10
		SmartPic_clue->Adapt_DCC_Info.database_weight = blending_ratio;//range 0~32
	}
	else
	{

		//====== SmartPic_clue info for DCC TOOL =========
		SmartPic_clue->Adapt_DCC_Info.database_case_num = 255;//255 means baending ratio is 0
		SmartPic_clue->Adapt_DCC_Info.database_weight = 255;//255 means baending ratio is 0
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
		ROSPrintf("[VPQ][DCC]database HistCnt_entry\n");
		for (i=0;i<bin;i++) {
			ROSPrintf("2.[VPQ][DCC]HistCnt_entry[%d]  = %d \n",i,(HistCnt_entry[i]>>8));
		}
		for (i=0;i<Histogram_adjust_bin_num;i++) {
			ROSPrintf("2.[VPQ][DCC]database_entry[%d] = %d, %d\n",i,(database_entry[i]>>8), g_DCC_LAYER_Array_Struct->Database_entry_Histogram[i]);
		}
		ROSPrintf("[VPQ][DCC] Database Curve\n");
		for(i=0;i<(Curve_num+1);i++) {
			ROSPrintf("[VPQ][DCC] DBCurve,Gz : [%d] = %d, %d \n",i,g_Database_Curve_defined_Item->database_curve[i], Gz[i]);
		}
	}

	print_count++;

	//return *Main_Curve_Temp;

}




int drvif_DCC_SC_smoothing_for_curve_delay_applied_condition_check(unsigned char MainDCC_SC, int* Main_preH, int* Gz, unsigned long Curve_diff_thershold, int* Scene_change_DCC_apply_delay_flag)
{
	_clues* SmartPic_clue=NULL;
	unsigned long curve_diff_total = 0;
	unsigned int mean_diff = 0;
	unsigned int dev_diff = 0;
	static unsigned int DCC_mean_pre = 0;
	static char DCC_dev_pre = 0;
	unsigned long temp_curve_diff[Curve_num_Max] = {0};
	int i = 0;
	int Curve_diff = 0;
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();

	//get mean diff and variance diff
	mean_diff = abs(SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_mean_no_debounce] - DCC_mean_pre);
	dev_diff = abs(SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Dev_no_debounce] - DCC_dev_pre);
	DCC_mean_pre = SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_mean_no_debounce];
	DCC_dev_pre = SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Dev_no_debounce];

	//SC, check if entering our algo
	if(MainDCC_SC == 1)
	{
		//curve_diff get
		curve_diff_total = 0;
		for(i=0;i<(Curve_num_Max);i++)
		{
			temp_curve_diff[i] = abs(Main_preH[i]-Gz[i]);
			curve_diff_total += temp_curve_diff[i];
		}
		//if curve_diff is large, mean_diff and dev_diff is small(easy to found flash)
		Curve_diff = curve_diff_total/Curve_num_Max;

		//if(Curve_diff > Curve_diff_thershold && mean_diff < 5 && dev_diff < 3)//flash when mean_diff and dev_diff are low will be relatively easy to be found
		if(Curve_diff > Curve_diff_thershold)
			Scene_change_DCC_apply_delay_flag = 1;
		else
			Scene_change_DCC_apply_delay_flag = 0;
	}

	//not SC, check if keeping entering our algo
	if(Scene_change_DCC_apply_delay_flag == 1)
	{
		curve_diff_total = 0;
		for(i=0;i<(Curve_num_Max);i++)
		{
			temp_curve_diff[i] = abs(Main_preH[i]-Gz[i]);
			curve_diff_total += temp_curve_diff[i];
		}
		Curve_diff = curve_diff_total/Curve_num_Max;
		if(Curve_diff < (Curve_diff_thershold >> 2))
			Scene_change_DCC_apply_delay_flag = 0;
	}
	//debug

	curve_diff_total = 0;
	for(i=0;i<(Curve_num_Max);i++)
	{
		temp_curve_diff[i] = abs(Main_preH[i]-Gz[i]);
		curve_diff_total += temp_curve_diff[i];
	}
	if(Start_Print.DCC_3==TRUE)
	{
		ROSPrintf("Curve_diff_thershold = %d\n", Curve_diff_thershold);
	}
	//ROSPrintf("curve_diff_total/Curve_num_Max = %d, mean_diff = %d, dev_diff = %d\n", curve_diff_total/Curve_num_Max, mean_diff, dev_diff);

	return Scene_change_DCC_apply_delay_flag;
}




void histogram_mean_variance_table_2D_interpolation(unsigned short* Result, unsigned int* Adavance_Control_info_interpolation, unsigned char TargetTable[][Variance_index_MAX])
{

    //----------------------------------------
    // INDEX LOCATE AND OFFSET CALCULATION
    unsigned int ToolMeanIndex0 = (Adavance_Control_info_interpolation[DCC_Tool_mean]>>6);
    unsigned int ToolMeanIndex1 = 0;
    if( (ToolMeanIndex0<<6) > Adavance_Control_info_interpolation[DCC_Tool_mean] )
    {
        ToolMeanIndex0--;
    }
    ToolMeanIndex1 = ToolMeanIndex0 + 1;

    unsigned int ToolDevIndex0 = (Adavance_Control_info_interpolation[DCC_Tool_Dev]>>6);
    unsigned int ToolDevIndex1 = 0;
    if( (ToolDevIndex0<<6) > Adavance_Control_info_interpolation[DCC_Tool_Dev] )
    {
        ToolDevIndex0--;
    }
    ToolDevIndex1 = ToolDevIndex0 + 1;

    // mean interpolation, expand shift 3 bit
    unsigned int MeanOffset = (Adavance_Control_info_interpolation[DCC_Tool_mean]>>3) - (ToolMeanIndex0<<3);
    unsigned int DevOffset = (Adavance_Control_info_interpolation[DCC_Tool_Dev]>>3) - (ToolDevIndex0<<3);
    //---------------------------------------- END OF INDEX LOCATE AND OFFSET CALCULATION

    //----------------------------------------
    // 2D INTERPOLATION
    unsigned int Val0 = 0;
    unsigned int Val1 = 0;
    unsigned int Val2 = 0;
    unsigned int Val3 = 0;
    unsigned int TargetVal0 = 0;
    unsigned int TargetVal1 = 0;

    //self defined DBG parameters
    //MeanOffset = 5;
    //DevOffset = 5;
    //Val0 = (10 << 3);
    //Val1 = (5 << 3);

//Val2 = (4 << 3);
    //Val3 = (12 << 3);

    //      dev
    // mean [ Val0 Val2 ]
    //      [ Val1 Val3 ]
    Val0 = (((TargetTable)[ToolMeanIndex0][ToolDevIndex0])<<3);
    Val1 = (((TargetTable)[ToolMeanIndex1][ToolDevIndex0])<<3);
    TargetVal0 = (Val0 + MeanOffset*((Val1-Val0)>>3));
    Val2 = (((TargetTable)[ToolMeanIndex0][ToolDevIndex1])<<3);
    Val3 = (((TargetTable)[ToolMeanIndex1][ToolDevIndex1])<<3);
    TargetVal1 = (Val2 + MeanOffset*((Val3-Val2)>>3));
    *Result = (((DevOffset*(TargetVal1-TargetVal0)+(TargetVal0<<3))+(1<<3)) >> 6);
    //---------------------------------------- END OF 2D INTERPOLATION

    /*
    if(MA_print_count%540==0)
    {
        ROSPrintf("==================== INTERPOLATION INFORMATION ====================\n");
        ROSPrintf("[%d]\t[%d]\n[%d]\t[%d]\n", (TargetTable)[ToolMeanIndex0][ToolDevIndex0], (TargetTable)[ToolMeanIndex0][ToolDevIndex1], (TargetTable)[ToolMeanIndex1][ToolDevIndex0], (TargetTable)[ToolMeanIndex1][ToolDevIndex1]);
        ROSPrintf("MeanOffset = [%d], DevOffset = [%d]\n", MeanOffset, DevOffset);
        ROSPrintf("Val0 = [%d], Val1 = [%d], Val2 = [%d], Val3 = [%d]\n", Val0, Val1, Val2, Val3);
        ROSPrintf("TargetVal0 = [%d], TargetVal1 = [%d], Result = [%d]\n", TargetVal0, TargetVal1, *Result);
        ROSPrintf("===================================================================\n");
    }
    */

}

//===================================================================
//=========== define for TV002 ADV API (gain multiply by 1024) =======================
void scalerVIP_Gamma_Cal_byLevel(int* histogram_curve)
{
	SLR_VIP_TABLE_CUSTOM_TV001*VIP_customer_TBL = (SLR_VIP_TABLE_CUSTOM_TV001*)scalerVIP_Get_Share_Memory_VIP_TABLE_Custom_Struct();
	extern SLR_VIP_TABLE_CUSTOM_TV001 m_customVipTable;
	VIP_customer_TBL = &m_customVipTable;
	if((VIP_customer_TBL==NULL))
	{
		if(MA_print_count%360==0)
			ROSPrintf("==Customer table Error, return==\n");
		return;
	}

	unsigned char tbl_sel = VIP_customer_TBL->ADV_API.ADV_API_CTRL.TBL_Select_sGamma;
	unsigned char log_delay = VIP_customer_TBL->ADV_API.ADV_API_CTRL.Debug_Log_Delay;
	unsigned char log0 = VIP_customer_TBL->ADV_API.ADV_API_CTRL.Debug_Log_Flag_0;
	unsigned char i;
	unsigned short factor = VIP_customer_TBL->ADV_API.ADV_API_TBL[tbl_sel].ADV_API_sGamma_TBL.sGamma_Lv;
	unsigned char En_flag = VIP_customer_TBL->ADV_API.ADV_API_TBL[tbl_sel].ADV_API_sGamma_TBL.Enable_Flag;
	unsigned char is_Neg = VIP_customer_TBL->ADV_API.ADV_API_CTRL.is_sGamma_Neg;
	unsigned char Mode = VIP_customer_TBL->ADV_API.ADV_API_CTRL.extend_Mode;

	//unsigned int factor_curve[Curve_num_Max];	//using global to prevent stack overflow
	//int G0[Curve_num_Max];
	//unsigned char factor_scale;

	//prevent crash
	if(log_delay==0)
		log_delay=100;

	if(Mode>=ADV_API_ModeGain_Max_tv002)
		Mode=0;

	factor = (factor * mode_Gain_tv002[Mode])>>10;

	if(En_flag!=1||factor==0)//.
		return;

	for(i=0;i<Curve_num_Max;i++)
	{
		G0_tv002[i] = *(histogram_curve+i);
		if(G0_tv002[i]<0)
			G0_tv002[i]=0;
	}

	if(is_Neg==1)//negative
	{
		for(i=0;i<Curve_num_Max;i++)
		{
			factor_curve_tv002[i] = (base_curve_benchmark_tv002<<10) - (ADV_API_BaseCurve_TV002[i] * factor);//modify power curve slope, and gain up to 1024(base_curve_benchmark)
			G1_tv002[i] = (G0_tv002[i] * factor_curve_tv002[i])>>20;//factor and factor_curve is left shift
			*(histogram_curve+i) = G1_tv002[i];
		}
	}
	else
	{
		for(i=0;i<Curve_num_Max;i++)
		{
			factor_curve_tv002[i] = (ADV_API_BaseCurve_TV002[i] * factor) + (base_curve_benchmark_tv002<<10);
			G1_tv002[i] = (G0_tv002[i] * factor_curve_tv002[i])>>20;//factor and factor_curve is left shift
			*(histogram_curve+i) = G1_tv002[i];
		}
	}

	if((log0&_BIT0)!=0)
	{
		if(MA_print_count%log_delay==0)
		{
			ROSPrintf("factor=%d,extendMode=%d,factor_curve=\n",factor,Mode);
			for(i=0;i<Curve_num_Max;i++)
				ROSPrintf("%d,",(factor_curve_tv002[i]));
			ROSPrintf("\n");
			ROSPrintf("G0");
			for(i=0;i<Curve_num_Max;i++)
				ROSPrintf("%d,",G0_tv002[i]);
			ROSPrintf("\n");
			ROSPrintf("G1");
			for(i=0;i<Curve_num_Max;i++)
				ROSPrintf("%d,",G1_tv002[i]);
			ROSPrintf("\n");
		}
	}
}

void scalerVIP_BlackCorrector_Cal_byLevel(int* histogram_curve)
{
	SLR_VIP_TABLE_CUSTOM_TV001*VIP_customer_TBL = (SLR_VIP_TABLE_CUSTOM_TV001*)scalerVIP_Get_Share_Memory_VIP_TABLE_Custom_Struct();
	extern SLR_VIP_TABLE_CUSTOM_TV001 m_customVipTable;
	VIP_customer_TBL = &m_customVipTable;
	if((VIP_customer_TBL==NULL))
	{
		if(MA_print_count%360==0)
			ROSPrintf("==Customer table Error, return==\n");
		return;
	}


	unsigned char tbl_sel = VIP_customer_TBL->ADV_API.ADV_API_CTRL.TBL_Select_BLE;
	unsigned char ble_range = VIP_customer_TBL->ADV_API.ADV_API_TBL[tbl_sel].ADV_API_BLE_TBL.BLE_Range;
	unsigned short ble_factor = VIP_customer_TBL->ADV_API.ADV_API_TBL[tbl_sel].ADV_API_BLE_TBL.BLE_Lv;
	unsigned char En_flag = VIP_customer_TBL->ADV_API.ADV_API_TBL[tbl_sel].ADV_API_BLE_TBL.Enable_Flag;
	unsigned char is_Reverse = VIP_customer_TBL->ADV_API.ADV_API_TBL[tbl_sel].ADV_API_BLE_TBL.isBLE_Lv_Reverse;
	unsigned char Mode = VIP_customer_TBL->ADV_API.ADV_API_CTRL.extend_Mode;

	unsigned char start_bin = 8; // for 16-235
	unsigned char log_delay = VIP_customer_TBL->ADV_API.ADV_API_CTRL.Debug_Log_Delay;
	unsigned char log0 = VIP_customer_TBL->ADV_API.ADV_API_CTRL.Debug_Log_Flag_0;
	unsigned char end_bin;
	//unsigned int ble_factor_curve[Curve_num_Max];
	unsigned short sampling;
	unsigned char idx,i;
	unsigned char smooth_point=5;
	//unsigned char factor_scale = 10;

	//prevent crash
	if(log_delay==0)
		log_delay=100;
	//int G0[Curve_num_Max];	//using global to prevent stack overflow

	if(Mode>=ADV_API_ModeGain_Max_tv002)
		Mode=0;

	ble_factor = (ble_factor * mode_Gain_tv002[Mode])>>10;
	end_bin = start_bin+ble_range;

	if(En_flag!=1||ble_factor==0||ble_range == 0)
		return;

	if((end_bin<=start_bin) || (end_bin-start_bin>(Curve_num_Max>>1)))
		return;

	sampling = ((Curve_num_Max)<<10)/ble_range;

	for(i=start_bin;i<end_bin;i++)
		index_tv002[i]=(sampling*(i-start_bin))>>10;

	index_tv002[end_bin]=Curve_num_Max;

	for(i=0;i<Curve_num_Max;i++)
	{
		G0_tv002[i] = *(histogram_curve+i);
		if(G0_tv002[i]<0)
			G0_tv002[i]=0;
	}

	if(is_Reverse==1)
	{
		for(i=start_bin;i<end_bin;i++)
		{
			idx = index_tv002[i];
			factor_curve_tv002[i] = (ADV_API_BaseCurve_TV002[idx] * ble_factor) + (base_curve_benchmark_tv002<<10);
			G1_tv002[i] = (G0_tv002[i] * factor_curve_tv002[i])>>20;//factor and factor_curve is left shift
			*(histogram_curve+i) = G1_tv002[i];
		}
	}
	else
	{
		for(i=start_bin;i<end_bin;i++)
		{
			idx = index_tv002[i];
			factor_curve_tv002[i] = (base_curve_benchmark_tv002<<10) - (ADV_API_BaseCurve_TV002[idx] * ble_factor);//modify power curve slope, and gain up to 1024(base_curve_benchmark)
			G1_tv002[i] = (G0_tv002[i] * factor_curve_tv002[i])>>20;//factor and factor_curve is left shift
			*(histogram_curve+i) = G1_tv002[i];
		}
	}

	// smooth
	for(i=0;i<smooth_point;i++)
	{
		G1_tv002[end_bin+i] = (2*G0_tv002[end_bin+i]+G0_tv002[end_bin+i-1]+G0_tv002[end_bin+i+1])>>2;
		*(histogram_curve+end_bin+i) = G1_tv002[end_bin+i];
	}

	if((log0&_BIT1)!=0)
	{
		if(MA_print_count%log_delay==0)
		{
			ROSPrintf("ble_factor=%d,Level=%d,factor_curve=\n",ble_factor);
			for(i=0;i<Curve_num_Max;i++)
				ROSPrintf("%d,",(factor_curve_tv002[i]));
			ROSPrintf("\n");
			for(i=0;i<Curve_num_Max;i++)
				ROSPrintf("%d,",G0_tv002[i]);
			ROSPrintf("\n");
			ROSPrintf("G1");
			for(i=0;i<Curve_num_Max;i++)
				ROSPrintf("%d,",G1_tv002[i]);
			ROSPrintf("\n");
		}
	}
}
//=========== define for TV002 ADV API (gain multiply by 1024) =======================
//===================================================================





void histogram_new_III_dcc(unsigned char display,UINT8 bit_num,unsigned char Curve_bit_num)
{
	//=================================
	//==== global coef. sync. anfd check =====
	//=================================
	SLR_VIP_TABLE* vipTable_shareMem = NULL;
	_clues* SmartPic_clue=NULL;
	_RPC_clues* RPC_SmartPic_clue=NULL;
	_system_setting_info* system_info_structure_table = NULL;
	_RPC_system_setting_info* RPC_system_info_structure_table = NULL;

	vipTable_shareMem = scaler_GetShare_Memory_VIP_TABLE_Struct();
	SmartPic_clue = scaler_GetShare_Memory_SmartPic_Clue_Struct();
	RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();
	system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();
	RPC_system_info_structure_table = scaler_GetShare_Memory_RPC_system_setting_info_Struct();

	if(vipTable_shareMem == NULL || (SmartPic_clue == NULL) ||(RPC_SmartPic_clue==NULL) || (system_info_structure_table == NULL)|| (RPC_system_info_structure_table == NULL)) {
		if(MA_print_count%360==0)
			ROSPrintf("Share Memory PQ data ERROR,Table_shareMem = %x, _clue = %x, _RPC_clue = %x , system_info = %x,  RPC_system_info = %x \n",
			vipTable_shareMem , SmartPic_clue, RPC_SmartPic_clue, system_info_structure_table, RPC_system_info_structure_table);
		return;
	}
	//====================================

	static unsigned int print_count=1; // for debug used
	unsigned char bin = COLOR_HISTOGRAM_LEVEL;//di_pow(2, bit_num);//default, bit_num = 5, bin=32
	unsigned char Curve_num = di_pow(2, Curve_bit_num); //Curve_bit_num = 6 or 7 , default : 7, Curve_num=128
	unsigned char Temp_Curve_num_gain = di_pow(2,(Curve_bit_num-bit_num));//for bin and Curve seg. num mapping

//==================================
//===  DCC variable defined
//==================================
	//o------ Curve data Range------o
	int Curve_data_range = 1<<DCC_Curve_DataRang_bit;
	int Curve_segment_range = 1<<DCC_Curve_Segment_bit;

	//o------ internal variables declare ------o
	static unsigned int *HistCnt;
	static unsigned int Total_HCnt=0;

	int 	i,j,k;
	unsigned int temp_sh,Curve_temp;
	unsigned int 	N=0;
	int 	mean=0;// = N/bin;
	unsigned int 	Grey_level;//for EQ
	unsigned int 	N_inv;//for EQ
	static unsigned int scene_count_main=0,scene_count_sub=0,Curve_change_count=0;;//for DCC Curve blending
	unsigned int 	INTERP_DATA=0; // for DCC Curve apply

	unsigned char DCL_Enable_falg=1;
	unsigned char 	DCC_Level=0,DCL_B=0,DCL_W=0;// basic DCC used

	//o------AdaptCtrl Table-----o
	unsigned char AdaptCtrl_enable = 0;

	//o----DCC Level and histogram error check ----o
	unsigned char shift_bit = 0;
	unsigned int Total_HistCnt_thl = 0;

	//o-----for S-index adaptive by mean value---o
	unsigned short index_0_adaptive=0;

	//transform the mean of S curve index(range from 0 - 31) to APL(range from 0 - 100)
	int DCC_S_curve_mean_index = 0;

	//o-----for histogram LPF---o
	int H_LPF_Tap = 0;
	unsigned short Hist_th=0;//slope_th  //
	unsigned char Hist_smooth_Weight_offset = 0; //

	//o-----for DCL ---o
	unsigned short white_extend=0,black_extend=0;

	//o--- for bin and Curve boundary
	unsigned char start_bin = 0, End_bin = bin;
 	unsigned char start_bin_offset=0, End_bin_offset =0;
 	unsigned char Curve_Zero_s_point=0,Curve_Max_s_point=Curve_num;

	//o----- histogram Boundary check ----o
	//output
	static unsigned char Black_boundary_bin_num[2]={0,0};//bin num, 0: <ratio[0], 1: ratio[0]~ratio[1]	  //memory share
	static unsigned char white_boundary_bin_num[2]={0,0};//bin num, 0: <ratio[0], 1: ratio[0]~ratio[1]	   //memory share

	//o------ For movie black region cut ------o, currently un-used !!
	unsigned char 	Dcc_histogram_mode=100;//for movie black region cut
	unsigned int 	cut_black_region=0;//for movie black region cut

	//o------ For DCC Curve extend ------o
	unsigned char 	DCC_Expand_Enable = 0; //turkey control falg by DCC_style
	unsigned char DCC_W_expand = 0, DCC_B_expand = 0;//DCC extend Curve

	//o------ For DCC  S Curve Y ------o
	unsigned char 	S_Curve_Enable=0; //turkey control falg by DCC_style
	int		index_0=0;
	unsigned short 	DCC_Sindex=0,DCC_Slow=0,DCC_Shigh=0;//index_1=0
	int S_curve_mean_mapping_flag = 1;

	//o------ For database DCC ------o
	unsigned char  	databaseDCC_enable = 0; //turkey control falg by DCC_style

	//o------ For User defined & adjust mode ------o
	unsigned char 	DCC_UserAdjust_flag = 0; //turkey control falg by DCC_style
	unsigned char DCC_User_Curve_table_sel=0;

	//o------ For DCC histogram weighting factor ------o
	unsigned char 	DCC_hist_adjust_flag = 0; //turkey control falg by DCC_style
	static unsigned int hisfac_Total_HCnt =0;

	//o------ For DCC  Curve Blending ------o
	int step=4; //org:2, //for DCC Curve blending
	int dcc_delay_time = 4, dcc_Curve_change_step=1;

    // ------ fwused_reg 1 & fwused_reg 3 Register read ------
 #if 0 //mark_from_Merlin2 20160629
    unsigned char HighResCurveEnable = FALSE;
#endif
    unsigned char SCurveCoefInterpolationEnable = FALSE;
    unsigned char  SectionGammaEnable = FALSE;
    unsigned short SectionGammaStart = 0;
    unsigned short SectionGammaEnd = 0;
    unsigned char  SectionGammaStr = 3;

    color_dcc_d_dcc_fwused_1_RBUS d_dcc_fwused_1_reg;
    d_dcc_fwused_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_FWUSED_1_reg);
    #if 0 //mark_from_Merlin2 20160629
    HighResCurveEnable = d_dcc_fwused_1_reg.HighResCurveEnable;
    #endif
    SCurveCoefInterpolationEnable = d_dcc_fwused_1_reg.CurveCoefInterpolationEnable;
    SectionGammaEnable = d_dcc_fwused_1_reg.ThreeSegCurveEnable;
    SectionGammaStart = d_dcc_fwused_1_reg.ThreeSEGXIndex0;
    SectionGammaEnd = d_dcc_fwused_1_reg.ThreeSEGXIndex1;
    SectionGammaStr = d_dcc_fwused_1_reg.Res1;
    if( SectionGammaStr < 2 ) SectionGammaStr = 2;
    if( SectionGammaStr > 4 ) SectionGammaStr = 4;

	//o------ init variables declare ------o
	
	unsigned char DCC_which_table = system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Table;
	unsigned char DCC_which_Mode = system_info_structure_table->OSD_Info.OSD_DCC_Mode;
	unsigned char DCC_FW_ONOFF_FLAG = system_info_structure_table->DCC_FW_ONOFF;

	//o-------- get info from share memory ---------o
	VIP_DCC_Control_Structure *DCC_Control_Structure = &(vipTable_shareMem->DCC_Control_Structure);
	VIP_DCC_Curve_Control_Coef *DCC_Curve_Control_Coef = &(DCC_Control_Structure->DCC_Curve_Control_Coef[DCC_which_table][DCC_which_Mode]);

	//o---- DCC function table select ----o
	unsigned char	Boundary_Check_table_sel = DCC_Curve_Control_Coef->Boundary_Check_Table;
	unsigned char	Level_and_Blend_Coef_Table_sel = DCC_Curve_Control_Coef->Level_and_Blend_Coef_Table;
	unsigned char	hist_adjust_table = DCC_Curve_Control_Coef->hist_adjust_table;
	unsigned char	AdaptCtrl_Level_Table = DCC_Curve_Control_Coef->AdaptCtrl_Level_Table;
	unsigned char	User_Curve_Table = DCC_Curve_Control_Coef->User_Curve_Table;
	unsigned char	Pic_Mode_Weight = DCC_Curve_Control_Coef->Picture_Mode_Weight;
	unsigned char	database_DCC_Table = DCC_Curve_Control_Coef->database_DCC_Table;

    unsigned char	DCC_boundary_Type = DCC_Curve_Control_Coef->boundary_type;
	//unsigned int pwCopyTemp=0;
	//pwCopyTemp = SmartPic_clue->Remmping_Src_Timing_index;
	//memcpy((unsigned char*)&(system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Advance_control_table[pwCopyTemp].DCC_init_boundary_Type),DCC_boundary_Type,sizeof(unsigned char));
	unsigned char	S_Curve_mean_mapping_table_select = DCC_Curve_Control_Coef->S_Curve_mean_mapping_table_select;

	//o------ Advance DCC Control Structure ------o
	RPC_DCC_Advance_control_table *Advance_control_table_by_source = NULL;
	Advance_control_table_by_source = &(system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Advance_control_table[(SmartPic_clue->Remmping_Src_Timing_index)]);

	RPC_DCC_Curve_boundary_table *Curve_boundary = NULL;
	Curve_boundary = &(system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Curve_boundary_table[DCC_boundary_Type]);
	unsigned char	DCC_bin_boundary_flag = Curve_boundary->Bin_Boundary_Flag; //for check data start bin, end bin
	unsigned char	DCC_Limit_range_Hist_Cut_Flag = Curve_boundary->Limit_range_Hist_Cut_Flag; // Cut histogram bin cnt when Y<start and Y>end, for bin(valid only if DCC_bin_boundary_flag = 1)
	unsigned char	DCC_Limit_range_Hist_Cut_start = Curve_boundary->Limit_range_Hist_Cut_start;
	unsigned char	DCC_Limit_range_Hist_Cut_end   = Curve_boundary->Limit_range_Hist_Cut_end;
	unsigned char	DCC_Fix_output_range_Flag = Curve_boundary->Fix_output_range_Flag;// if  0: output data range fix in 0 ~1023, 1 : output data range fix in start~end, for output Curve
	unsigned char	DCC_Fix_output_range_start = Curve_boundary->Fix_output_range_start;
	unsigned char	DCC_Fix_output_range_end  = Curve_boundary->Fix_output_range_end;
	unsigned char	DCC_output_range_linear_black_flag = Curve_boundary->Linear_black_Flag; // (valid only if DCC_Limit_range_Hist_Cut_Flag = 1)
	unsigned char	DCC_output_range_linear_white_flag = Curve_boundary->Linear_white_Flag; // (valid only if DCC_Limit_range_Hist_Cut_Flag = 1)
	unsigned char	DCC_panel_compensation_Flag = Curve_boundary->panel_compensation_Flag;
	unsigned char 	DCC_Hist_LPF_Enable = (Advance_control_table_by_source->DCC_LPF_Control)[Hist_LPF_enable] ;	// default off
	unsigned char 	DCC_Curve_LPF_Enable = (Advance_control_table_by_source->DCC_LPF_Control)[Curve_LPF_enable];	// default on
	unsigned char   filter_tap = (Advance_control_table_by_source->DCC_LPF_Control)[Curve_LPF_tap];
	H_LPF_Tap	= (Advance_control_table_by_source->DCC_LPF_Control)[Hist_LPF_tap];// dd=2 : 5 tap lpf  dd=1 : 3 tap lpf
	Hist_smooth_Weight_offset	= (Advance_control_table_by_source->DCC_LPF_Control)[EQ_slope_limit_weighting_offset];//weighting_offset 0~31
	Hist_th	= (Advance_control_table_by_source->DCC_LPF_Control)[EQ_slope_limit_slope_thershold];// slope_thershold 0~no limit

	unsigned char 	pure_color = (SmartPic_clue->PureColor);
	unsigned char skin_tone_flag = (SmartPic_clue->skintoneflag);
	unsigned char 	MainDCC_SC = (RPC_SmartPic_clue->SceneChange);
	unsigned char SubDCC_SC = (RPC_SmartPic_clue->SceneChange);

	//o------ DCC read from share memory ------o
//	unsigned char DCC_Read_From_Tool_Enable = g_DCC_FUNCTION_Struct->DCC_Read_From_Tool_Enable; // for DCC read from share memory

	//o------ For 3d mode DCC ------o
	static unsigned char DCC_3D_count = 0;

//=====Dummy Reg. debug mode enable check===========
	color_dcc_d_dcc_ctrl_RBUS d_dcc_ctrl_Reg;
	d_dcc_ctrl_Reg.regValue = rtd_inl(COLOR_DCC_D_DCC_CTRL_reg);
//==================================

	//o----Get DCC function table  ----o
	VIP_DCC_Boundary_check_Table *Boundary_check_Table= &(DCC_Control_Structure->DCC_Boundary_check_Table[Boundary_Check_table_sel]);
	VIP_DCC_Level_and_Blend_Coef_Table *Level_and_Blend_Coef_Table= &(DCC_Control_Structure->DCC_Level_and_Blend_Coef_Table[Level_and_Blend_Coef_Table_sel]);
	VIP_DCC_Hist_Factor_Table	*DCCHist_Factor_Table = &(DCC_Control_Structure->DCCHist_Factor_Table[hist_adjust_table]);
	VIP_DCC_AdaptCtrl_Level_Table	*DCC_AdaptCtrl_Level_Table = &(DCC_Control_Structure->DCC_AdaptCtrl_Level_Table[AdaptCtrl_Level_Table]);
	VIP_USER_DEFINE_CURVE_DCC_CRTL_ITEM	 *USER_DEFINE_CURVE_DCC_CRTL_ITEM = &(DCC_Control_Structure->USER_DEFINE_CURVE_DCC_CRTL_Table[User_Curve_Table]);

	//o-----get DCC Curve Temp by share memory -----o
	RPC_DCC_LAYER_Array_Struct *g_DCC_LAYER_Array_Struct = &(SmartPic_clue->Adapt_DCC_Info.S_RPC_DCC_LAYER_Array);
	RPC_Adapt_DCC_Info_Item *g_DCC_RPC_Adapt_DCC_Info_Item = &(RPC_SmartPic_clue->RPC_Adapt_DCC_Info);


	//o-----  for DCC EQ boundary range defined -----o
	unsigned short EQ_output_Y_range=DataRange_MAX, EQ_output_Y_offset=0;
	unsigned short Grey_level_identity = DataRange_MAX;

	//o-----  for DCC Output boundary range defined -----o

	//o-----  for DCC Curve Output boundary -----o
	unsigned short output_Y_Max =DataRange_MAX,output_Y_offset=0;

	//o-----  for change source smooth toggle 20150626 jimmy.lin -----o
	unsigned char which_source = (RPC_system_info_structure_table->VIP_source);
	static unsigned char pre_which_source = VIP_QUALITY_VGA;

	//***** DCC_Debug_Printf *****
        UINT8 bDCC_USER_S_SWAP=0;

        #if DCC_USER_S_SWAP
		bDCC_USER_S_SWAP=0;
        #else
		bDCC_USER_S_SWAP=1;
        #endif


//===   For DCC turkey flow select ======
//== reset to basic DCC Setting : original DCC + DCL
	S_Curve_Enable 		= Level_and_Blend_Coef_Table->S_Curve_Enable;
	DCC_Expand_Enable	= Level_and_Blend_Coef_Table->Expand_Eable;

	AdaptCtrl_enable	= 0;
	databaseDCC_enable 	= 0;
	DCC_hist_adjust_flag= 0;
	DCC_UserAdjust_flag = 0;

	if(((DCC_Curve_Control_Coef->AdaptCtrl_Level_Table)<=DCC_AdaptCtrl_Level_TABLE_MAX)&&((Advance_control_table_by_source->DCC_Advance_Level_Control_Flag)[Advance_Level_General_Control_enable]==1))
		AdaptCtrl_enable = 1;

	if(((DCC_Curve_Control_Coef->database_DCC_Table)<=Database_DCC_Curve_TABLE_MAX)&&((Level_and_Blend_Coef_Table->Database_Enable)==1))
		databaseDCC_enable = 1;

	if(((DCC_Curve_Control_Coef->hist_adjust_table)<=DCCHist_Factor_Table_MAX)&&((Level_and_Blend_Coef_Table->Hist_Adjust_Enable)==1))
		DCC_hist_adjust_flag = 1;

	if(((DCC_Curve_Control_Coef->User_Curve_Table)<=USER_DEFINE_CURVE_DCC_TBL_NUM)&&((Level_and_Blend_Coef_Table->User_Curve_Eable)==1))
		DCC_UserAdjust_flag = 1;

//==================================
//====== DCC function enable	=======
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		ROSPrintf("[VPQ][DCC]Function Status CHECK\n ");

	ROSPrintf("Project_ID=%d\n",RPC_system_info_structure_table->Project_ID);

		ROSPrintf("[VPQ][DCC]Ad_Ctrl_en=%d \n ",	AdaptCtrl_enable);
		ROSPrintf("[VPQ][DCC]CoefInterp_En=%d\n",	SCurveCoefInterpolationEnable);
		ROSPrintf("[VPQ][DCC]Hist_Adj_Flag=%d \n ",	DCC_hist_adjust_flag);
		ROSPrintf("[VPQ][DCC]DCL=%d \n ",		DCL_Enable_falg);
		ROSPrintf("[VPQ][DCC]DCC_Exp_En=%d \n ",	DCC_Expand_Enable);
		ROSPrintf("[VPQ][DCC]SCu=%d \n ",		S_Curve_Enable);
		ROSPrintf("[VPQ][DCC]UCu=%d \n ",		DCC_UserAdjust_flag);
		ROSPrintf("[VPQ][DCC]DBDCC=%d \n ",		databaseDCC_enable);

		ROSPrintf("[VPQ][DCC]Hist_LPF_En=%d \n ",	DCC_Hist_LPF_Enable);
		ROSPrintf("[VPQ][DCC]Cu_LPF_En=%d \n ",		DCC_Curve_LPF_Enable);

		ROSPrintf("[VPQ][DCC]boundary_Type=%d \n",			DCC_boundary_Type);
		ROSPrintf("[VPQ][DCC]bin_boundary_flag=%d \n",			DCC_bin_boundary_flag);
		ROSPrintf("[VPQ][DCC]Limit_range_Hist_Cut_Flag=%d \n",		DCC_Limit_range_Hist_Cut_Flag);
		ROSPrintf("[VPQ][DCC]Limit_range_Hist_Cut_start=%d \n",		DCC_Limit_range_Hist_Cut_start);
		ROSPrintf("[VPQ][DCC]Limit_range_Hist_Cut_end=%d \n",		DCC_Limit_range_Hist_Cut_end);
		ROSPrintf("[VPQ][DCC]Fix_output_range_Flag=%d \n",		DCC_Fix_output_range_Flag);
		ROSPrintf("[VPQ][DCC]Fix_output_range_start=%d \n",		DCC_Fix_output_range_start);
		ROSPrintf("[VPQ][DCC]Fix_output_range_end=%d \n",		DCC_Fix_output_range_end);
		ROSPrintf("[VPQ][DCC]output_range_linear_black_flag=%d \n",	DCC_output_range_linear_black_flag);
		ROSPrintf("[VPQ][DCC]output_range_linear_white_flag=%d \n",	DCC_output_range_linear_white_flag);
		ROSPrintf("panel_comp_Flag=%d \n",		DCC_panel_compensation_Flag);

		ROSPrintf("D_T=%d\n",debug_print_delay_time);

	}
//==================================


//==================================
//=======DCC adjust by mean value =========

		//o-------Decide APL and Var  ---------o
		unsigned char adapt_level_debounce = Boundary_check_Table->adapt_level_debounce_th;
		static unsigned int Adavance_Control_info[DCC_Tool_Item_Max]={0,0,0,0};
        static unsigned int Adavance_Control_info_Interpolation[DCC_Tool_Item_Max]={0,0,0,0};
		HistCnt= (SmartPic_clue->Y_Main_Hist);
		drvif_color_dcc_Advance_Level_control_by_mean_variance(bin,MainDCC_SC,adapt_level_debounce ,&HistCnt[0],&Adavance_Control_info[0]);
		if( SCurveCoefInterpolationEnable == 1 ) {
        	drvif_color_dcc_Advance_Level_control_by_mean_variance_interpolation(bin,MainDCC_SC,adapt_level_debounce ,&HistCnt[0],&Adavance_Control_info_Interpolation[0]);
		}
		if(S_curve_mean_mapping_flag == 1)
		{
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
				ROSPrintf("S_Curve_mean_mapping_table_select = %d \n",S_Curve_mean_mapping_table_select);
				for(i=0;i<mean_value_index_MAX;i++)
					ROSPrintf("S_curve_mean[S_Curve_mean_mapping_table_select][%d]=%d \n",i, S_curve_mean[S_Curve_mean_mapping_table_select][i]);
			}

			//match current APL to S-curve mean index
			if(S_curve_mean[S_Curve_mean_mapping_table_select][mean_value_index_MAX - 1] < Adavance_Control_info[DCC_Tool_mean])//current APL greater than upper bound of mapping table of mean of Scurve
			{
				DCC_S_curve_mean_index = mean_value_index_MAX - 1;//assigen the greatest value of mapping table to it
			}
			else
			{
				for(i=0;i<mean_value_index_MAX;i++)
				{
					if(S_curve_mean[S_Curve_mean_mapping_table_select][i] >= Adavance_Control_info[DCC_Tool_mean])//current APL between i ~ i-1,then mean index = i
					{
						DCC_S_curve_mean_index = i;
						break;
					}
				}
			}
		}
		//current frame APL
		//assigen to variables tool using
		//Adavance_Control_info[DCC_Tool_mean] = APL(0-100)
		//DCC_S_curve_mean_index = index(0-31)
		SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]= DCC_S_curve_mean_index;//Adavance_Control_info[DCC_Tool_mean];
		SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]=Adavance_Control_info[DCC_Tool_Dev];
		SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_mean_no_debounce]=Adavance_Control_info[DCC_mean_no_debounce];
		SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Dev_no_debounce]=Adavance_Control_info[DCC_Dev_no_debounce];
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("DCC_S_curve_mean_index = %d\n ", DCC_S_curve_mean_index);
			ROSPrintf("Adavance_Control_info[DCC_Tool_mean] = %d\n ", Adavance_Control_info[DCC_Tool_mean]);
			ROSPrintf("S_curve_mean[S_Curve_mean_mapping_table_select][DCC_S_curve_mean_index] = %d\n ", S_curve_mean[S_Curve_mean_mapping_table_select][DCC_S_curve_mean_index]);
		}
		//o-------Curve Blending coef. by mean and APL---------o
		static unsigned int DCC_Curve_Blending_info[DCC_blending_control_Item_Max]={0,0};
		drvif_color_DCC_Curve_Blending(display,COLOR_HISTOGRAM_LEVEL,&DCC_Curve_Blending_info[0],&Adavance_Control_info[0]);
		static int DCC_Status_Change_for_SCsmooth_flag = 0;
		if (display == SLR_MAIN_DISPLAY)  //main channel init
		{
			//==  system info ===
			HistCnt= (SmartPic_clue->Y_Main_Hist);
			Total_HCnt=(SmartPic_clue->Hist_Y_Total_sum)+1;
			if((system_info_structure_table->DCC_Status_Change) == 1)
			{
				DCC_Status_Change_for_SCsmooth_flag = 1; 
			}
			if(((system_info_structure_table->DCC_Status_Change) == 1)||(SmartPic_clue->SceneChange_by_diff_mean_Dev==1))//If set DCC  function level, setting the SC for Curve apply
			{
				MainDCC_SC=1;
				system_info_structure_table->DCC_Status_Change = 0;
			}

			//==Decide DCC item level by APL and Var==
			if(AdaptCtrl_enable==1) {
				//if level control only_by_mean_enable always let the DCC_Tool_Dev =0
				if((Advance_control_table_by_source->DCC_Advance_Level_Control_Flag)[Advance_control_only_by_mean_enable]==1) {
					Adavance_Control_info[DCC_Tool_Dev] = 0;
				}

				if((Advance_control_table_by_source->DCC_Advance_Level_Control_Flag)[Advance_Level_by_mean_dev_enable]==1) {
					DCC_Level = (DCC_AdaptCtrl_Level_Table->DCC_Level_table)[SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]][SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]];
				}

				if((Advance_control_table_by_source->DCC_Advance_Level_Control_Flag)[Advance_Cublc_by_mean_dev_enable]==1)
				{
					DCC_Slow = (DCC_AdaptCtrl_Level_Table->DCC_Cublc_Low_table)[SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]][SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]];
					DCC_Shigh = (DCC_AdaptCtrl_Level_Table->DCC_Cublc_High_table)[SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]][SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]];
					DCC_Sindex =(DCC_AdaptCtrl_Level_Table->DCC_Cublc_Index_table)[SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]][SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]];
					DCC_W_expand = (DCC_AdaptCtrl_Level_Table->DCC_W_Ex_table)[SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]][SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]];
					DCC_B_expand = (DCC_AdaptCtrl_Level_Table->DCC_B_Ex_table)[SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]][SmartPic_clue->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]];
				}
				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
					ROSPrintf("DCC_Slow = %d\n ", DCC_Slow);
					ROSPrintf("DCC_Shigh = %d\n ", DCC_Shigh);
					ROSPrintf("DCC_Sindex = %d\n ", DCC_Sindex);
				}
                //=======================
                // TALBE INTERPOLATION
                if( SCurveCoefInterpolationEnable == 1 )
                {
                    unsigned short InterLevel = 0;
                    unsigned short InterSlow = 0;
                    unsigned short InterHigh = 0;
                    unsigned short InterIndex = 0;
                    unsigned short InterWExpand = 0;
                    unsigned short InterBExpand = 0;

                    histogram_mean_variance_table_2D_interpolation(&InterLevel, Adavance_Control_info_Interpolation, DCC_AdaptCtrl_Level_Table->DCC_Level_table);
                    histogram_mean_variance_table_2D_interpolation(&InterSlow, Adavance_Control_info_Interpolation, DCC_AdaptCtrl_Level_Table->DCC_Cublc_Low_table);
                    histogram_mean_variance_table_2D_interpolation(&InterHigh, Adavance_Control_info_Interpolation, DCC_AdaptCtrl_Level_Table->DCC_Cublc_High_table);
                    histogram_mean_variance_table_2D_interpolation(&InterIndex, Adavance_Control_info_Interpolation, DCC_AdaptCtrl_Level_Table->DCC_Cublc_Index_table);
                    histogram_mean_variance_table_2D_interpolation(&InterWExpand, Adavance_Control_info_Interpolation, DCC_AdaptCtrl_Level_Table->DCC_W_Ex_table);
                    histogram_mean_variance_table_2D_interpolation(&InterBExpand, Adavance_Control_info_Interpolation, DCC_AdaptCtrl_Level_Table->DCC_B_Ex_table);

                    DCC_Level = InterLevel;
                    DCC_Slow = InterSlow;
                    DCC_Shigh = InterHigh;
                    DCC_Sindex = InterIndex;
                    DCC_W_expand = InterWExpand;
                    DCC_B_expand = InterBExpand;
                }				
				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
					ROSPrintf("[END OF TALBE INTERPOLATION]DCC_Slow = %d\n ", DCC_Slow);
					ROSPrintf("[END OF TALBE INTERPOLATION]DCC_Shigh = %d\n ", DCC_Shigh);
					ROSPrintf("[END OF TALBE INTERPOLATION]DCC_Sindex = %d\n ", DCC_Sindex);
				}
				//======================= END OF TALBE INTERPOLATION
			}else{
				DCC_Level		= (DCC_AdaptCtrl_Level_Table->DCC_Level_table)[0][0];
				DCC_Slow		= (DCC_AdaptCtrl_Level_Table->DCC_Cublc_Low_table)[0][0];
				DCC_Shigh		= (DCC_AdaptCtrl_Level_Table->DCC_Cublc_High_table)[0][0];
				DCC_Sindex		= (DCC_AdaptCtrl_Level_Table->DCC_Cublc_Index_table)[0][0];
				DCC_W_expand 	= (DCC_AdaptCtrl_Level_Table->DCC_W_Ex_table)[0][0];
				DCC_B_expand	= (DCC_AdaptCtrl_Level_Table->DCC_B_Ex_table)[0][0];
			}

			DCL_B			= Level_and_Blend_Coef_Table->DCL_B_level;
			DCL_W			= Level_and_Blend_Coef_Table->DCL_W_level;

			//Curve Blending info
			dcc_Curve_change_step = Level_and_Blend_Coef_Table->Step;
			dcc_delay_time  = Level_and_Blend_Coef_Table->Delay_time;

			//UserCurve by APL Table select
			DCC_User_Curve_table_sel	= DCC_Curve_Control_Coef->User_Curve_Table;

		} else if(display ==SLR_SUB_DISPLAY) {//sub channel


			for(i=0;i<bin;i++) {
				HistCnt[i]= reg_HistCnt_Sub[i];
			}
			Total_HCnt=Total_HistCnt_Sub+1;

			SubDCC_SC=SubSceneChange;

			if(Sub_Set_SC == 1) {
				SubDCC_SC=1;
				Sub_Set_SC=0;
			}

			// sub-channal not adaptive all used adaptive[0][0]
			DCC_Level		= (DCC_AdaptCtrl_Level_Table->DCC_Level_table)[0][0];
			DCC_Slow		= (DCC_AdaptCtrl_Level_Table->DCC_Cublc_Low_table)[0][0];
			DCC_Shigh		= (DCC_AdaptCtrl_Level_Table->DCC_Cublc_High_table)[0][0];
			DCC_Sindex		= (DCC_AdaptCtrl_Level_Table->DCC_Cublc_Index_table)[0][0];
			DCC_W_expand 	= (DCC_AdaptCtrl_Level_Table->DCC_W_Ex_table)[0][0];
			DCC_B_expand	= (DCC_AdaptCtrl_Level_Table->DCC_B_Ex_table)[0][0];

			//same as main channal
			DCL_B			= Level_and_Blend_Coef_Table->DCL_B_level;
			DCL_W			= Level_and_Blend_Coef_Table->DCL_W_level;

		} else {
			return;
		}


		if(AdaptCtrl_enable!=1) {
			index_0_adaptive = (((SmartPic_clue->Hist_Y_Mean_Value)<<1)+3)/(3<<1);// for adaptive adjust, mapping to 32 segment, total : 33 point

			//define DCC Scurve level boundary
			if(DCC_Sindex<10) {
				index_0 = (index_0_adaptive > (10-DCC_Sindex)) ? (index_0_adaptive-(10-DCC_Sindex)) : 1;
			} else if(DCC_Sindex>10) {
				index_0 = index_0_adaptive+(DCC_Sindex-10);
			} else {
				index_0 = index_0_adaptive;
			}
			index_0 = (index_0>=Curve_num)?Curve_num:((index_0<=0)?0:index_0);
		} else {
			index_0 = DCC_Sindex;
		}


		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("====== [DCC]Level CHECK PRINT ====\n ");

			ROSPrintf("[VPQ][DCC]T_HCnt=%d\n ",Total_HCnt);
			ROSPrintf("[VPQ][DCC]pure_color=%d \n ",	pure_color);
			ROSPrintf("[VPQ][DCC]SC=%d \n ",		MainDCC_SC);
			ROSPrintf("[VPQ][DCC]Skin_found=%d \n ",	skin_tone_flag);
			ROSPrintf("[VPQ][DCC]DCC_FW_ONOFF_FLAG=%d \n ",	DCC_FW_ONOFF_FLAG);

			ROSPrintf("[VPQ][DCC]Boundary_T=%d\n",		Boundary_Check_table_sel);
			ROSPrintf("[VPQ][DCC]L_and_B_Coef_T=%d\n",	Level_and_Blend_Coef_Table_sel);
			ROSPrintf("[VPQ][DCC]DCC_which_table=%d\n ",	DCC_which_table);
			ROSPrintf("[VPQ][DCC]hist_Adj_T=%d\n",		hist_adjust_table);
			ROSPrintf("[VPQ][DCC]Adap_Level_T=%d\n",	AdaptCtrl_Level_Table);
			ROSPrintf("[VPQ][DCC]DCC_which_Mode=%d \n ",	DCC_which_Mode);
			ROSPrintf("[VPQ][DCC]PM_Wei=%d\n",		Pic_Mode_Weight);
			ROSPrintf("[VPQ][DCC]UC_T=%d\n",		User_Curve_Table);
			ROSPrintf("[VPQ][DCC]DB_T=%d\n",		database_DCC_Table);

			ROSPrintf("[VPQ][DCC]Control_info mean=%d, DeV=%d \n",Adavance_Control_info[DCC_Tool_mean],Adavance_Control_info[DCC_Tool_Dev]);
			ROSPrintf("[VPQ][DCC]Level=%d,DCL_B=%d,DCL_W=%d \n ",DCC_Level,DCL_B,DCL_W);
			ROSPrintf("[VPQ][DCC]Slow=%d	,Shigh=%d,Sindex=%d \n ",DCC_Slow,DCC_Shigh,DCC_Sindex);
			ROSPrintf("[VPQ][DCC]W_exp=%d	,B_exp=%d\n ",DCC_W_expand,DCC_B_expand);
		}

//==================================

#if DCC_Dummy_Debug_flag
	color_dcc_d_dcc_fwused_0_RBUS  d_dcc_fwused_0_reg;
	d_dcc_fwused_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_FWUSED_0_reg);

	if(d_dcc_fwused_0_reg.Dummy_debug_enable ==1) {
		pure_color 			= d_dcc_fwused_0_reg.PureColor; 		// bit :1
		MainDCC_SC 			= d_dcc_fwused_0_reg.SceneChange; 		// bit :2
		skin_tone_flag 		= d_dcc_fwused_0_reg.SkinTone;			// bit :3

		DCL_Enable_falg 	= d_dcc_fwused_0_reg.DCL_Enable;		// bit :4
		DCC_Expand_Enable 	= d_dcc_fwused_0_reg.Expand_Enable;		// bit :5
		S_Curve_Enable 		= d_dcc_fwused_0_reg.Scurve_Enable;		// bit :6
		databaseDCC_enable 	= d_dcc_fwused_0_reg.Database_Enable;	// bit :7
		DCC_UserAdjust_flag = d_dcc_fwused_0_reg.UserCurve_Enable;	// bit :8

		DCC_hist_adjust_flag 	= d_dcc_fwused_0_reg.Hist_Adjust_Enable;	// bit :9
		DCC_bin_boundary_flag 	= d_dcc_fwused_0_reg.Bin_boundary_Enable;	// bit :10
		DCC_Limit_range_Hist_Cut_Flag 	= d_dcc_fwused_0_reg.Limit_range_Hist_Cut_Enable;	// bit :11
		DCC_Fix_output_range_Flag 	= d_dcc_fwused_0_reg.Output_LimitRange_Enable;		// bit :12

		DCC_Hist_LPF_Enable	= d_dcc_fwused_0_reg.Hist_LPF_Enable;	// bit :13
		DCC_Curve_LPF_Enable= d_dcc_fwused_0_reg.Curve_LPF_Enable;	// bit :14
		filter_tap			= d_dcc_fwused_0_reg.C_LPF_Tap;		// bit :15~17
		DCC_boundary_Type = d_dcc_fwused_0_reg.Boundary_Type; // bit :18~21
		H_LPF_Tap			= d_dcc_fwused_0_reg.H_LPF_Tap; 		// bit :23~27
		DCC_Level = d_dcc_fwused_0_reg.DCC_Level; // bit :28~31
		DCC_panel_compensation_Flag 	= d_dcc_fwused_0_reg.Panel_compensation; // bit :22

		Curve_boundary = &(system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Curve_boundary_table[DCC_boundary_Type]);
		//DCC_bin_boundary_flag = Curve_boundary->Bin_Boundary_Flag;
		DCC_Limit_range_Hist_Cut_Flag = Curve_boundary->Limit_range_Hist_Cut_Flag;
		DCC_Limit_range_Hist_Cut_start = Curve_boundary->Limit_range_Hist_Cut_start;
		DCC_Limit_range_Hist_Cut_end = Curve_boundary->Limit_range_Hist_Cut_end;
		DCC_Fix_output_range_Flag = Curve_boundary->Fix_output_range_Flag;
		DCC_Fix_output_range_start = Curve_boundary->Fix_output_range_start;
		DCC_Fix_output_range_end = Curve_boundary->Fix_output_range_end;
		DCC_output_range_linear_black_flag = Curve_boundary->Linear_black_Flag;
		DCC_output_range_linear_white_flag = Curve_boundary->Linear_white_Flag;
	} else {
		d_dcc_fwused_0_reg.PureColor			=	pure_color;
		d_dcc_fwused_0_reg.SceneChange			=	MainDCC_SC;
		d_dcc_fwused_0_reg.SkinTone				=	skin_tone_flag;

		d_dcc_fwused_0_reg.DCL_Enable			=	DCL_Enable_falg;
		d_dcc_fwused_0_reg.Expand_Enable		=	DCC_Expand_Enable;
		d_dcc_fwused_0_reg.Scurve_Enable		=	S_Curve_Enable;
		d_dcc_fwused_0_reg.Database_Enable		=	databaseDCC_enable;
		d_dcc_fwused_0_reg.UserCurve_Enable		=	DCC_UserAdjust_flag;
		d_dcc_fwused_0_reg.Hist_Adjust_Enable	=	DCC_hist_adjust_flag;
		d_dcc_fwused_0_reg.Bin_boundary_Enable	=	DCC_bin_boundary_flag;
		d_dcc_fwused_0_reg.Limit_range_Hist_Cut_Enable	=	DCC_Limit_range_Hist_Cut_Flag;
		d_dcc_fwused_0_reg.Output_LimitRange_Enable	=	DCC_Fix_output_range_Flag;
		d_dcc_fwused_0_reg.Hist_LPF_Enable		=	DCC_Hist_LPF_Enable;
		d_dcc_fwused_0_reg.H_LPF_Tap			= 	H_LPF_Tap;
		d_dcc_fwused_0_reg.Curve_LPF_Enable		=	DCC_Curve_LPF_Enable;
		d_dcc_fwused_0_reg.C_LPF_Tap			= 	filter_tap;
		d_dcc_fwused_0_reg.Boundary_Type		=	DCC_boundary_Type;
		d_dcc_fwused_0_reg.DCC_Level			=	DCC_Level;
		d_dcc_fwused_0_reg.Panel_compensation		=	DCC_panel_compensation_Flag;

		rtd_outl(COLOR_DCC_D_DCC_FWUSED_0_reg,d_dcc_fwused_0_reg.regValue);

	}

	if((d_dcc_fwused_0_reg.Dummy_debug_enable ==1)&&(MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		ROSPrintf("[DCC]Status CHECK PRINT\n ");

		ROSPrintf("pure_color=%d \n ",pure_color);
		ROSPrintf("SC=%d \n ",MainDCC_SC);
		ROSPrintf("Skin_found=%d \n ",skin_tone_flag);

		ROSPrintf("DCL=%d \n ",DCL_Enable_falg);
		ROSPrintf("DCC_Exp_En=%d \n ",DCC_Expand_Enable);
		ROSPrintf("SCu=%d \n ",S_Curve_Enable);
		ROSPrintf("DBDCC=%d \n ",databaseDCC_enable);
		ROSPrintf("UCu=%d \n ",DCC_UserAdjust_flag);

		ROSPrintf("Hist_LPF_En=%d \n ",DCC_Hist_LPF_Enable);
		ROSPrintf("Cu_LPF_En=%d \n ",DCC_Curve_LPF_Enable);

		ROSPrintf("Hist_Adj_Flag=%d \n ",	DCC_hist_adjust_flag);
		ROSPrintf("Bin_Boun_Flag=%d \n",	DCC_bin_boundary_flag);

		ROSPrintf("Limit_range_Cut_Flag=%d from %d to %d\n",	DCC_Limit_range_Hist_Cut_Flag, DCC_Limit_range_Hist_Cut_start, DCC_Limit_range_Hist_Cut_end);
		ROSPrintf("Fix_out_R_Flag=%d from %d to %d\n",	DCC_Fix_output_range_Flag, DCC_Fix_output_range_start, DCC_Fix_output_range_end);
		ROSPrintf("Linear black=%d white=%d\n",	DCC_output_range_linear_black_flag, DCC_output_range_linear_white_flag);

		ROSPrintf("hist_adj_flag=%d\n",DCC_hist_adjust_flag);
		ROSPrintf("bin_boun_flag=%d\n",DCC_bin_boundary_flag);
		ROSPrintf("D_T=%d\n",debug_print_delay_time);

	}

#endif

	if(DCC_Fix_output_range_Flag && !pure_color) {
		output_Y_Max = DCC_Fix_output_range_end<<DCC_OutputShift;
		output_Y_offset = DCC_Fix_output_range_start<<DCC_OutputShift;
	} else {
		//output_Y_Max = output_Y_Max;
		//output_Y_offset = output_Y_offset;
	}

//==================================
//======DCC Level and histogram error check =====

	//if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_WID)>=3000) ||
	//		(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DISP_LEN)>=1800))//for 4k2k case
	//{
		shift_bit = (RPC_system_info_structure_table->DCC_hist_shift_bit)+1;//half of total cnt
	//}
	//else
	//{
	//	shift_bit = (system_info_structure_table->DCC_hist_shift_bit)+1;//half of total cnt
	//}

	unsigned int adapt_w = 0, adapt_h = 0, adapt_stream = 0;
	adapt_stream = Scaler_ChangeUINT32Endian(RPC_SmartPic_clue->S_NetFlix_info.Netflix_Enable);
	adapt_w = Scaler_ChangeUINT32Endian(RPC_SmartPic_clue->S_NetFlix_info.Netflix_CapWid);
	adapt_h = Scaler_ChangeUINT32Endian(RPC_SmartPic_clue->S_NetFlix_info.Netflix_CapLen);
	static unsigned char adapt_stream_smt_flag = 0;

	if(adapt_stream == 1 && RPC_SmartPic_clue->S_NetFlix_info.NetFlix_smooth_Toggle_info.smooth_toggle_update_flag && adapt_stream_smt_flag == 0)
		adapt_stream_smt_flag = 1;
	else if (adapt_stream == 0)
		adapt_stream_smt_flag = 0;

	if(adapt_stream_smt_flag == 1)	//adapt stream and run smooth toggle
		Total_HistCnt_thl = ((adapt_w* adapt_h)>>shift_bit);
	else
		Total_HistCnt_thl = ((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID)*Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN))>>shift_bit);  // Erin tmp 100310

	//***** DCC_Debug_Printf *****
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		ROSPrintf("sf_bit=%d\n",shift_bit);
		ROSPrintf("T_HistCnt_thl=%d\n",Total_HistCnt_thl);
		ROSPrintf("His_Y_T_sum=%d\n",SmartPic_clue->Hist_Y_Total_sum);
		ROSPrintf("Pic_M_Wei=%d\n",Pic_Mode_Weight);
	}

	if(Total_HCnt <= 1)
		SmartPic_clue->Total_Hist_Cnt_less_than_one = 1;
	else
		SmartPic_clue->Total_Hist_Cnt_less_than_one = 0;
	if((SmartPic_clue->Hist_Y_Total_sum)<Total_HistCnt_thl)
		SmartPic_clue->Hist_Y_Total_sum_less_than_Total_HistCnt_thl = 1;
	else
		SmartPic_clue->Hist_Y_Total_sum_less_than_Total_HistCnt_thl = 0;
	if(pure_color == 1)
		SmartPic_clue->PureColor= 1;
	else
		SmartPic_clue->PureColor= 0;

	int DCC_bin_identity_flag = 0;
	if((DCC_FW_ONOFF_FLAG ==0)||(Total_HCnt <= 1)||((SmartPic_clue->Hist_Y_Total_sum)<Total_HistCnt_thl)) { //all off DCC application, using linear DCC Cruve
		if( (DCC_bin_boundary_flag == 0)|| (DCC_Fix_output_range_Flag == 1) || (DCC_boundary_Type == 11))
			DCC_bin_identity_flag = 0;
		else
			DCC_bin_identity_flag = 1;
		Driver_DCC_Curve_Identity(display,Curve_bit_num,DCC_bin_identity_flag);
		if(((Total_HCnt <= 0)||((SmartPic_clue->Hist_Y_Total_sum)<Total_HistCnt_thl)) && (MA_print_count%120)==0) {
			#if DCC_info_flag
				ROSPrintf("[DCC][Error Message]Histogram count error!! Result: fix DCC Curve 'Linear'\n");
			#endif
		}


		return;
	}
//==================================


//==================================
	if((Boundary_check_Table->Boundary_check_condiction_enable)) {
		Driver_DCC_Histogram_Boundary_check(display,MainDCC_SC,bin,Total_HCnt,Boundary_check_Table, &HistCnt[0],&Black_boundary_bin_num[0],&white_boundary_bin_num[0]);
	} else {
		Black_boundary_bin_num[0] = 0;
		Black_boundary_bin_num[1] = 0;
		white_boundary_bin_num[0] = 0;
		white_boundary_bin_num[1] = 0;
	}
//==================================


//==================================
//===Adaptive_histogram_range using profile for dcc  start===//
//to do :  this function need to fix .....
	if(Scaler_InputSrcGetMainChType() == _SRC_TV) {//muat sync with profile in isr
		Dcc_histogram_mode=drvif_color_detected_black_region(0,MainDCC_SC, SmartPic_clue);//0 for TV because of drvif_color_chessboard_detection limited profile
	}

	cut_black_region=(Total_HCnt*(100-Dcc_histogram_mode))/100;

	for(i=0;i<bin;i++) {
		if(cut_black_region>HistCnt[i]) {
			cut_black_region=cut_black_region - HistCnt[i];
			HistCnt[i]=0;
		} else {
			HistCnt[i]=HistCnt[i] - cut_black_region;
			break;
		}
	}
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		ROSPrintf("cut_black_region=%d\n ",cut_black_region);
	}
//==================================


//==================================
//====== histogram re-distribution start========
	if(DCC_hist_adjust_flag==1)
	{
		//histogram adjust block
		Driver_DCC_hist_adjust( display,bin,Total_HCnt,DCCHist_Factor_Table,&hisfac_Total_HCnt,&HistCnt[0]);

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("[VPQ][DCC] hist_adjust, MODE=%d, Total_HCnt=%d,hisfac_Total_HCnt=%d\n ",Total_HCnt,hisfac_Total_HCnt);
#if DCC_Curve_Debug_flag
			for(i=0;i<(bin);i++) {
				ROSPrintf("[VPQ][DCC] hist_adjust, HistCnt[%d]=%d \n",i,HistCnt[i]);
			}
#endif
		}

		//o---- normalize to total pixel num----
		if(Total_HCnt!=hisfac_Total_HCnt) {
			Driver_DCC_hist_normalized(display,bin,Total_HCnt,hisfac_Total_HCnt,&HistCnt[0] );
		} else {
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
			{
				ROSPrintf("[Hint!!]The Total_HCnt after hisfac adjust is same as orginal!!");
			}
		}

		// only read from DCC tool
		for(i=0;i<(bin);i++) {
			(g_DCC_LAYER_Array_Struct->HistCnt_Of_Adj)[i]=HistCnt[i];
#if DCC_Curve_Debug_flag
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
				ROSPrintf("[VPQ][DCC] hist_adj_share, Reg_HistCnt[%d]=%d  \n",i,(g_DCC_LAYER_Array_Struct->HistCnt_Of_Adj)[i]);
#endif
		}

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("[VPQ][DCC] DCC_hist_adjust_flag = Y\n ");
			ROSPrintf("[VPQ][DCC] hist_norm, MODE=%d, T_HCnt=%d\n ",Total_HCnt);
#if DCC_Curve_Debug_flag
			for(i=0;i<(bin);i++) {
				ROSPrintf("[VPQ][DCC] hist_norm, HistCnt[%d]=%d\n ",i,HistCnt[i]);
			}
#endif
		}

}

//==================================


//==================================
//o-------some factor for EQ start------o

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)){
			ROSPrintf("[VPQ][DCC] EQ, B_boun_bin=%d, w_boun_bin=%d\n ",Black_boundary_bin_num[0],white_boundary_bin_num[0]);
			ROSPrintf("[VPQ][DCC] EQ, start_bin=%d, End_bin=%d, Temp_gain=%d\n ",start_bin,End_bin, Temp_Curve_num_gain);
    }

    		if( DCC_bin_boundary_flag ) {
			start_bin = start_bin + Black_boundary_bin_num[0];
			End_bin = End_bin - white_boundary_bin_num[0];

			if(DCC_Limit_range_Hist_Cut_Flag!=0) { // fix histogram range: hist cut start~end
#if 1
				Curve_Zero_s_point = (DCC_Limit_range_Hist_Cut_start+1)>>1;
				Curve_Max_s_point = (DCC_Limit_range_Hist_Cut_end+1)>>1;

				if( Temp_Curve_num_gain > 1 ){
					start_bin_offset = ( Curve_Zero_s_point+(Temp_Curve_num_gain-1) )>>(Curve_bit_num-bit_num);
				} else {
					start_bin_offset = Curve_Zero_s_point;
        }

				if(start_bin < start_bin_offset) {
					start_bin=start_bin_offset;
    		}

				if( Temp_Curve_num_gain > 1 ) {
					End_bin_offset = ( Curve_Max_s_point+(Temp_Curve_num_gain-1) )>>(Curve_bit_num-bit_num);
				} else {
					End_bin_offset = Curve_Max_s_point;
    }

				if(End_bin > End_bin_offset) {
					End_bin=End_bin_offset;
		}
#else
				start_bin_offset = DCC_Limit_range_Hist_Cut_start>>DCC_HistShiftBin;
				if(start_bin < start_bin_offset)
				{
					start_bin=start_bin_offset;
				}

				End_bin_offset = (255-DCC_Limit_range_Hist_Cut_end)>>DCC_HistShiftBin;
                // 20150702 willy, should be (bin-End_bin_offset)...
				if(End_bin > (bin-End_bin_offset))
				{
					End_bin=(bin-End_bin_offset);
				}

#endif
			} else {
				start_bin_offset = 0;
				End_bin_offset = 0;
			}

			for(i=0;i<(Boundary_check_Table->Black_Bounday_seg1_limit);i++) { //dark bin : seg0_limit

				if(i<start_bin) {
					SH[i]=0;
				}
			}

			for(i=0;i<(Boundary_check_Table->white_Bounday_seg1_limit);i++) {//white bin : seg0_limit
				if(((bin-1)-i)>=End_bin) {
					SH[bin-1-i]=0;
				}
			}

			#if 0
			Curve_Zero_s_point = start_bin*Temp_Curve_num_gain;
			Curve_Max_s_point = End_bin*Temp_Curve_num_gain;
			#endif

		} else {
			start_bin = 0;
			End_bin = bin;
			Curve_Zero_s_point = start_bin*Temp_Curve_num_gain;
			Curve_Max_s_point = End_bin*Temp_Curve_num_gain;
		}

        if( MA_print_count%debug_print_delay_time == 0 && Start_Print.VD_LOG_ENABLE==TRUE ) {
            ROSPrintf("[WILLY Normal] Start = %d, End = %d\n", start_bin, End_bin);
            ROSPrintf("[WILLY Normal] B[0] = %d, B[1] = %d, W[0] = %d, W[1] = %d\n",
                Black_boundary_bin_num[0], Black_boundary_bin_num[1],
                white_boundary_bin_num[0], white_boundary_bin_num[1] );
        }

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("[VPQ][DCC] EQ, start_bin=%d, End_bin=%d\n ",start_bin,End_bin);
			ROSPrintf("[VPQ][DCC] EQ, T_HCnt=%d,\n ",Total_HCnt);
#if DCC_Curve_Debug_flag
			for(i=0;i<(bin);i++) {
				ROSPrintf("[VPQ][DCC] EQ, SH[%d]=%d\n ",i,SH[i]);
			}
#endif
		}
//==================================

//==================================
//=======Generate SH of EQ ==============
		if(End_bin>start_bin) {
			mean = (Total_HCnt -cut_black_region) /(End_bin-start_bin);
		} else {
			mean =0;
		}

		int Dev_offset=1;

		Driver_DCC_SH_of_EQ(display,&HistCnt[0], mean,Total_HCnt,start_bin,End_bin,DCC_Level,Dev_offset);

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
#if DCC_Curve_Debug_flag
			ROSPrintf("[VPQ][DCC] EQ, start_bin=%d, End_bin=%d\n ",start_bin,End_bin);
			ROSPrintf("[VPQ][DCC] EQ, Cu_Zero_p=%d, Cu_Max_point=%d\n ",Curve_Zero_s_point,Curve_Max_s_point);
			ROSPrintf("[VPQ][DCC] EQ, mean=%d\n ",mean);
			ROSPrintf("[VPQ][DCC] EQ, T_HCnt=%d, cut_b_region=%d\n ",Total_HCnt,cut_black_region);

			for(i=0;i<(bin);i++) {
				ROSPrintf("[VPQ][DCC] SH_of_EQ, SH[%d]=%d\n ",i,SH[i]);
			}
#endif
		}

//==================================

//==================================
//========== histogram LPF==============
		unsigned char score_th=160;//range : 0~255
		unsigned char Hist_smooth_Weight = 0;

		if( DCC_Hist_LPF_Enable == 1) {

			// curve slope limit by jimmy 20141006
			unsigned int SH_total = 0;
			for( i=0; i<COLOR_HISTOGRAM_LEVEL; i++ ) {
				if( i>=start_bin && i<End_bin ) {
					SSH[i] = SH[i];
					SH_total += SH[i];
				} else {
					SSH[i] = 0;
				}
			}
			Driver_DCC_Curve_Slope_Weight_Mapping(display,SmartPic_clue->score_NaturalImage,score_th,&Hist_smooth_Weight);
			int slope_limit_enable = 1;
			if(slope_limit_enable == 1)
			{
				Hist_smooth_Weight = Hist_smooth_Weight + Hist_smooth_Weight_offset;
				if(Hist_smooth_Weight >= 32)
				{
					Hist_smooth_Weight = 32;
				}

				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
				{
					ROSPrintf("[MHH][DCC] H_LPF_Tap = %d \n ", H_LPF_Tap);
					ROSPrintf("[MHH][DCC] Hist_th = %d \n ", Hist_th);
					ROSPrintf("[MHH][DCC] Hist_th = %d \n ", Hist_smooth_Weight);
				}
				Driver_DCC_Curve_Slope_Limit( display, SSH, SH, SH_total, Hist_th, Hist_smooth_Weight,start_bin,End_bin,H_LPF_Tap );
			}
		}

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("[VPQ][DCC] his_LPF, LPF_Tap=%d, DCC_Hist_LPF_Enable=%d\n",H_LPF_Tap, DCC_Hist_LPF_Enable);
			ROSPrintf("[VPQ][DCC] Check3 \n ");
		}
//===================================

//==================================================
// Dynamic Contrast Limit control (DCL) for black and white
//==================================================

		if(((DCL_B ==0) && (DCL_W ==0))||(DCL_Enable_falg==0)||(pure_color==1)) {
			black_extend=0;
			white_extend=0;
		} else {
			if((RPC_system_info_structure_table->Project_ID)==VIP_Project_ID_TV005)
				Driver_DCC_DCL_tv005(display,bin,MainDCC_SC,&HistCnt[0],Total_HCnt,DCL_B,DCL_W,&white_extend,&black_extend);
			else
				Driver_DCC_DCL(display,bin,MainDCC_SC,&HistCnt[0],Total_HCnt,DCL_B,DCL_W,&white_extend,&black_extend);
		}

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
			ROSPrintf("[VPQ][DCC] DCL,b_lv=%d, w_lv=%d\n ",black_extend,white_extend );
		}

//===========================================


//==========================================
//========Identity Curve Defined ==========
		//o----- define identity curve Linear_Curve+DCL_W+DCL_B ----o
		if(DCC_Level == 0) { //pure identity Curve
			black_extend = 0;
			white_extend = 0;
		}

		//o--- Difined : default identity Curve ---o
			Identity[0]=0-black_extend;
			Identity[Curve_num]= EQ_output_Y_range + white_extend;
			Grey_level_identity = EQ_output_Y_range + white_extend;

		for(i=1;i<(Curve_num+1);i++) {  //(bin+1) for Total Curve Node
			if(i<=(Curve_num-40)) { //(bin-10) for Curve smooth by data trancate
				Identity[i]=((((i*Grey_level_identity<<10)+(Curve_num>>1))/Curve_num)>>10)-black_extend; 				//for Equalization Transfer Function(ETF)+DCL_B
			} else {
				Identity[i]=((((i*Grey_level_identity<<10)+(Curve_num>>1))/Curve_num)>>10)-(black_extend*(Curve_num-i)/40); 	// for extend mode smooth, from:22~32
			}
		}

		//***** DCC_Debug_Printf *****

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			if(DCC_Level == 0 ) {
 				ROSPrintf("[VPQ][DCC] Pure Identity Curve (DCC_Level=0 )\n");
			} else {
				ROSPrintf("[VPQ][DCC] Identity curve extend  \n");
			}
			ROSPrintf("[VPQ][DCC] Identity curve org Identity \n");
			for(i=0;i<(Curve_num+1);i++) {
				ROSPrintf("[VPQ][DCC] %d \n",Identity[i]);
			}
		}

		int diff_low=0,bound_denominator_factor=0,bound_gain_factor=0;
		int boundary_Curve[Curve_num_Max];

		//o-----modify identity Curve boundary-------o
		if( ((DCC_bin_boundary_flag) || (DCC_Fix_output_range_Flag)) && (Boundary_check_Table->Boundary_check_condiction_enable) && (DCC_boundary_Type != 11)) {
			UINT16 a, b, temp_bound;
			if(DCC_Fix_output_range_Flag) {
				a = DCC_Fix_output_range_start;
				b = DCC_Fix_output_range_end;
			} else {
				a = 0;
				b = 255;
			}

			if(Identity[Curve_zero_point]>=0) {
				temp_bound = (a+1)>>1;
				diff_low = (Identity[temp_bound]-Identity[Curve_zero_point]);
			} else {
				temp_bound = (a+1)>>1;
				diff_low = (Identity[temp_bound]+Identity[Curve_zero_point]);
			}

			temp_bound = (b+1)>>1;
			bound_gain_factor = Identity[temp_bound];
			bound_denominator_factor = Identity[Curve_max_point]+diff_low;

			if(bound_denominator_factor==0)
				bound_denominator_factor = bound_denominator_factor+1;

			for(i=0;i<Curve_num_Max;i++) {
				boundary_Curve[i] = (Identity[i]+diff_low)*bound_gain_factor;
				boundary_Curve[i] = boundary_Curve[i]/bound_denominator_factor;

				Identity[i]= boundary_Curve[i];
			}

		}
		for(i=0;i<(Curve_num+1);i++) {
			(g_DCC_LAYER_Array_Struct->ByPass_Curve)[i] = Identity[i];
		}

		//***** DCC_Debug_Printf *****
 		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
 			for(i=0;i<(Curve_num+1);i++) {
 				ROSPrintf("[VPQ][DCC] %d, %d \n",Identity[i],((g_DCC_LAYER_Array_Struct->ByPass_Curve)[i]));
			}
		}

//================================================


//==========================================
//========Evaluation of transformation function ==========

	temp_sh=0;
	if(DCC_Level == 0) {//fix equalization

		for(i=0 ;i<(Curve_num+1); i++) {
			Gz[i] = Identity[i];
		}

		if(skin_tone_flag == 1) {
			for(i=0;i<(Curve_num+1);i++) {
				skin_tone_curve[i]= Identity[i];
			}
		}
	} else {
		//o-------  boundary Limit Range defined by DCL -------o
		//Gz[] Curve for DCC function flow
		Gz[0]=0-black_extend;			//Data offset + DCL_black extend
		Gz[Curve_num]=DataRange_MAX+white_extend;		//Data Bright Limit + DCL_white extend

		//DCurve[] for DCC Curve apply flow
		DCurve[0]=0-black_extend;		//Data offset + DCL_black extend
		DCurve[Curve_num]=DataRange_MAX+white_extend;	//Data Bright Limit + DCL_white extend

		//Evaluation factor of transformation function
		N=0;
		for(i=start_bin;i<End_bin;i++)
			N+= SH[i];

		Grey_level=EQ_output_Y_range+white_extend; //Data Range + DCL_white extend
		N_inv=((Grey_level<<16)+((N+1)>>1))/(N+1);			//normalization for Equalization Transfer Function(ETF)
		//o---------------------------------------------------o
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("[VPQ][DCC] black_extend=%d,EQ_output_Y_offset=%d\n",black_extend,EQ_output_Y_offset);
			ROSPrintf("[VPQ][DCC] N_inv=%d \n",N_inv);
		}

		//unsigned int SH_t[32]={0,0,3000,3506,2840,2901,2692,2835,2742,3213,2634,2908,2638,2611,2646,2798,2630,2870,
				//2661,2633,3287,2717,2975,2614,2647,2712,2836,2668,4739,7244,0,0};

		//o------- Equalization Transfer Function, note : Curve by bin num-------
		for(i=1;i<(bin+1);i++) {
			temp_sh+=SH[i-1];
			//Gz[i] =Long_Division(temp_sh, N, 10);

			if(i<=(bin-10)) {//(bin-10) for Curve smooth by data trancate
				GzbySH[i] = (((temp_sh*N_inv)+(1<<15))>>16)-black_extend+EQ_output_Y_offset; // for eq & DCL_B & Limit range mode
			} else {
				GzbySH[i] = (((temp_sh*N_inv)+(1<<15))>>16)-(black_extend*(bin-i)/10)+EQ_output_Y_offset; // for DCL mode smooth, from:22~32
			}
			//***** DCC_Debug_Printf	*****
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_2==TRUE)) {
				ROSPrintf("[VPQ][DCC] SH[%d]=%d, temp_sh=%d, temp_GZ=%d \n",i,temp_sh,SH[i-1],(((temp_sh*N_inv)+(1<<15))>>16));
				}
		}

		GzbySH[0]=Gz[0];
		GzbySH[bin]=Gz[Curve_num];
		if(GzbySH[bin]<=GzbySH[bin-1]) {
			GzbySH[bin] = GzbySH[bin-1];
		}

		//avoid fw Crash
		if(Temp_Curve_num_gain==0) {
			Driver_DCC_Curve_Identity(display,Curve_bit_num,DCC_bin_boundary_flag);

			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
				ROSPrintf("[VPQ][DCC] Warring!!,Setting Error for numbers of DCC_Curve and Hist_bin");

			return;
		}

		//mapping histogram bin Curve to DCC SRAM Curve
		for(i=1;i<(Curve_num+1);i++) {

			if((i%Temp_Curve_num_gain==0)&&(Temp_Curve_num_gain>1)) {

				UINT8 cnt = Temp_Curve_num_gain;
				k= i/Temp_Curve_num_gain;

				if((i>Curve_Max_s_point) && (Curve_Max_s_point>(i-Temp_Curve_num_gain))) {

					cnt = Curve_Max_s_point-(i-Temp_Curve_num_gain);
					Curve_temp = (GzbySH[k]-GzbySH[k-1])/cnt;

					//reset value
					for(j=1;j<Temp_Curve_num_gain;j++) {
						Gz[i-j] = GzbySH[k];
					}

					//set value
					for(j=1;j<cnt;j++) {
						Gz[i-4+j] = GzbySH[k-1]+Curve_temp*j;
					}

				} else if(((i-Temp_Curve_num_gain)<Curve_Zero_s_point)&&(Curve_Zero_s_point<i)) {

					cnt = i-Curve_Zero_s_point;
					Curve_temp = (GzbySH[k]-GzbySH[k-1])/cnt;

					//reset value
					for(j=1;j<Temp_Curve_num_gain;j++) {
						Gz[i-j] = GzbySH[k-1];
					}

					//set value
					for(j=1;j<cnt;j++) {
						Gz[i-j] = GzbySH[k]-Curve_temp*j;
					}

				} else {
					Gz[i] =	GzbySH[k];
				Curve_temp = (GzbySH[k]-GzbySH[k-1])/Temp_Curve_num_gain;
					for(j=1;j<Temp_Curve_num_gain;j++) {
						Gz[i-j] = GzbySH[k]-Curve_temp*j;
					}
			}
			} else {
				Gz[i] =	GzbySH[i];
		}

		}

#if 0 //mark_from_Merlin2 20160629
        // update the information for high resolution histogram
        if( HighResCurveEnable == TRUE )
        {
            for(i=0;i<Curve_num_Max;i++)
            {
                Gz[i] = HighResGz[i];
            }
            Curve_Zero_s_point = HighResStartBin;
            Curve_Max_s_point = HighResEndBin;

            if((MA_print_count%540==0)&&(Start_Print.Dcc_1==TRUE))
            {
                ROSPrintf("=====[DCC DEBUG LOG]=====\n");
		ROSPrintf("start:[H]%d,[O]%d end:[H]%d,[O]%d\n", HighResStartBin, start_bin, HighResEndBin, End_bin);
	    }

        }
#endif
			//***** DCC_Debug_Printf *****
#if DCC_Curve_Debug_flag
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
				ROSPrintf("===histogram bin curve ===\n");
				ROSPrintf("[VPQ][DCC] num_gain=%d\n",Temp_Curve_num_gain);
				for(i=0;i<(bin+1);i++) {
					ROSPrintf("[VPQ][DCC] %d \n",GzbySH[i]);
				}
				ROSPrintf("===DCC SRAM Curve Format===\n");
				for(i=0;i<(Curve_num+1);i++) {
					ROSPrintf("[VPQ][DCC] %d \n",Gz[i]);
				}
			}
#endif
//======================================
			// record histogram curve, for DCC TOOL by share memory
			for(i=0;i<(Curve_num+1);i++) {
				(g_DCC_LAYER_Array_Struct->Histogram_Curve)[i]=Gz[i];
#if DCC_Curve_Debug_flag
				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
					ROSPrintf("[VPQ][DCC] HisCu[%d] =  %d \n",i,(g_DCC_LAYER_Array_Struct->Histogram_Curve)[i]);
#endif
			}

//============================================================
if(bDCC_USER_S_SWAP){
//o------------DCC User Curve Adjust by mean value-----o
	if(DCC_UserAdjust_flag) {
		if(skin_tone_flag== 1) {
			drvif_color_DCC_User_Define_Curve_DCC(Curve_num,skin_tone_curve, USER_DEFINE_CURVE_DCC_CRTL_ITEM, SmartPic_clue->Hist_Y_Mean_Value, skin_tone_flag, Curve_Zero_s_point,Curve_Max_s_point);
			for(i=0;i<(Curve_num+1);i++) {
				skin_tone_curve[i]=Main_User_Define_Curve[i];
			}

		} else {
			drvif_color_DCC_User_Define_Curve_DCC(Curve_num,Gz, USER_DEFINE_CURVE_DCC_CRTL_ITEM, SmartPic_clue->Hist_Y_Mean_Value, skin_tone_flag, Curve_Zero_s_point,Curve_Max_s_point);
			for(i=0;i<(Curve_num+1);i++) {
				Gz[i]=Main_User_Define_Curve[i];
			}
		}

		for(i=0;i<(Curve_num+1);i++) {
			//   record extend curve for Tool Access
			(g_DCC_LAYER_Array_Struct->User_Curve)[i]=Main_User_Define_Curve[i];
	}

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
			ROSPrintf("[VPQ][DCC] DCC_UserAdjust_flag = Y (SWAP = %d) \n", bDCC_USER_S_SWAP);
			if(skin_tone_flag) {
				ROSPrintf("[VPQ][DCC] skin_tone_flag = Y \n");
	}
			for(i=0;i<(Curve_num+1);i++) {
				ROSPrintf("User_Curve[%d] = %d	\n",i,(g_DCC_LAYER_Array_Struct->User_Curve)[i]);
			}
		}
	}

}


//===== DCC apply Curve compensation =======


//o-------------- for DCC S_Curve --------------------o

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("SCu_En=%d,Curve_num=%d\n",S_Curve_Enable,Curve_num);
			ROSPrintf("ind_0=%d,Slow=%d,Shigh=%d \n",index_0,DCC_Slow,DCC_Shigh);
		}

		//S_Curve_Enable =0;
		if((S_Curve_Enable == 1)&&(DCC_Slow+DCC_Shigh)!=0) {
			if(skin_tone_flag == 1) {

				drvif_color_DCC_Cubic_Curve(Curve_num,Identity,index_0, DCC_Slow, DCC_Shigh,Curve_Zero_s_point,Curve_Max_s_point);//jimmy new S curve by cubic

				for(i=0;i<(Curve_num+1);i++) {
					skin_tone_curve[i]=Main_S_Curve[i];
				}
			} else {

				drvif_color_DCC_Cubic_Curve(Curve_num,Gz,index_0, DCC_Slow, DCC_Shigh,Curve_Zero_s_point,Curve_Max_s_point);//jimmy new S curve by cubic

				for(i=0;i<(Curve_num+1);i++) {
					Gz[i]=Main_S_Curve[i];
				}
			}

		} else {
			if(skin_tone_flag == 1) {
				for(i=0;i<(Curve_num+1);i++) {
					skin_tone_curve[i]= Identity[i];
				}
			}
		}

		// record S curve, for DCC TOOL by share memory
		for(i=0;i<(Curve_num+1);i++) {
			if(skin_tone_flag==1) {
				// record S curve, for DCC TOOL by share memory
				(g_DCC_LAYER_Array_Struct->S_Curve)[i]=skin_tone_curve[i];
			} else {
				(g_DCC_LAYER_Array_Struct->S_Curve)[i]=Gz[i];
			}
			}

#if DCC_Debug_flag
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
			if((S_Curve_Enable == 1)&&(DCC_Slow+DCC_Shigh)!=0){
				ROSPrintf("[VPQ][DCC] S_Curve_Enable = Y\n");
			} else {
				ROSPrintf("[VPQ][DCC] S_Curve_Enable = N\n");
			}
			for(i=0;i<(Curve_num+1);i++) {
				if(i%4==0)
					ROSPrintf("[VPQ][DCC] SCu[%d] = %d \n",i,(g_DCC_LAYER_Array_Struct->S_Curve)[i]);
			}
		}
#endif
//o-------------------------------------------------o


//o-------------- for SectionGamma, willy 20150709 --------------------o

    if( MA_print_count%debug_print_delay_time==0 && Start_Print.VD_LOG_ENABLE == TRUE) {
        ROSPrintf("=====[ WILLY, SECTION GAMMA INFORMATION ]=====\n");
        ROSPrintf("[VPQ][DCC] Enable = %d\n", SectionGammaEnable);
        ROSPrintf("[VPQ][DCC] Start Bin = %d\n", SectionGammaStart);
        ROSPrintf("[VPQ][DCC] End Bin = %d\n\n", SectionGammaEnd);
    }

    if( SectionGammaEnable == TRUE) {
        // copy Gz
        static int SectionGammaGz[Curve_num_Max] = {0};
        for(i=0; i<Curve_num_Max; i++) {
            SectionGammaGz[i] = Gz[i];
        }

        // setting error check protection
        if( SectionGammaEnd >= Curve_num_Max-1 ) {
            SectionGammaEnd = Curve_num_Max-1;
        }
        if( SectionGammaStart >= Curve_num_Max-1 ) {
            SectionGammaStart = Curve_num_Max-1;
        }
        if( SectionGammaStart >= SectionGammaEnd ) {
            SectionGammaStart = 0;
            SectionGammaEnd = 0;
        }

        // generate the ratio, boundary including start and end
        static unsigned int SectionGammaRatio[Curve_num_Max] = {0};
        unsigned int RatioSum = 0;
        unsigned int ValueDiff = SectionGammaGz[SectionGammaEnd] - SectionGammaGz[SectionGammaStart];
        unsigned short IdxDiff = SectionGammaEnd - SectionGammaStart;

        for(i=SectionGammaStart; i<=SectionGammaEnd; i++) {
            unsigned short TmpIdx = i-SectionGammaStart;
            unsigned int Dividen = 1;
            unsigned int Divisor = 1;

            unsigned int j=0;
            for(j=0; j<SectionGammaStr; j++) {
                Dividen = Dividen*TmpIdx;
            }
            for(j=0; j<SectionGammaStr-1; j++) {
                Divisor = Divisor*IdxDiff;
            }
            SectionGammaRatio[i] = (IdxDiff<<8) - (Dividen<<8)/(Divisor+1);
            //SectionGammaRatio[i] = (IdxDiff<<8) - ((TmpIdx*TmpIdx*TmpIdx)<<8)/(IdxDiff*IdxDiff+1);
            RatioSum += SectionGammaRatio[i];

            if( MA_print_count%debug_print_delay_time==0 && Start_Print.VD_LOG_ENABLE == TRUE){
                ROSPrintf("[%d] %d - ( %d )^3/(( %d )^2+1) = %d (%d)\n", i, IdxDiff, TmpIdx, IdxDiff, SectionGammaRatio[i], SectionGammaRatio[i]>>8);
            }

        }
        RatioSum = RatioSum >> 8;


        if( MA_print_count%debug_print_delay_time==0 && Start_Print.VD_LOG_ENABLE == TRUE) {
            ROSPrintf("\n=====[ Pre gamma curve ]===\n");
            for(i=SectionGammaStart; i<=SectionGammaEnd; i++) {
                ROSPrintf("[%d] %d\t", i, SectionGammaGz[i]);
                if((i+1)%8 == 0) {
                    ROSPrintf("\n");
                }
            }
            ROSPrintf("\n");
        }

        // re dispatch the delta by the ratio
        for(i=SectionGammaStart; i<SectionGammaEnd; i++) {
            if( i==0 ) continue;
            unsigned int Delta = ( (ValueDiff*SectionGammaRatio[i])/(RatioSum+1))>>8;
            SectionGammaGz[i] = SectionGammaGz[i-1] + Delta;

            if( MA_print_count%debug_print_delay_time==0 && Start_Print.VD_LOG_ENABLE == TRUE) {
                ROSPrintf("[%d] %d * ( %d / %d ) = %d\n", i, ValueDiff, SectionGammaRatio[i], RatioSum+1, Delta);
            }

        }

        if( MA_print_count%debug_print_delay_time==0 && Start_Print.VD_LOG_ENABLE == TRUE) {
            ROSPrintf("\n=====[ Post gamma curve ]===\n");
            for(i=SectionGammaStart; i<=SectionGammaEnd; i++) {
                ROSPrintf("[%d] %d\t", i, SectionGammaGz[i]);
                if((i+1)%8 == 0) {
                    ROSPrintf("\n");
                }
            }
            ROSPrintf("\n");
        }

        // assign the result back to orginal curve, by blending?
        for(i=0; i<Curve_num_Max; i++) {
            Gz[i] = SectionGammaGz[i];
        }

    }

//o-------------------------------------------------o

//o------------DCC Curve expand --------------o
	if((DCC_Expand_Enable==1)&&((DCC_W_expand + DCC_B_expand)!=0)) {
		if(skin_tone_flag == 1) {
			drvif_color_DCC_Curve_Compensation_Expand(Curve_num,Temp_Curve_num_gain,Identity, DCC_W_expand, DCC_B_expand,&Black_boundary_bin_num[0],&white_boundary_bin_num[0]);
			for(i=0;i<(Curve_num+1);i++) {
				Identity[i]=Main_extend_Curve[i];
			}
		} else {
			drvif_color_DCC_Curve_Compensation_Expand(Curve_num,Temp_Curve_num_gain,Gz, DCC_W_expand, DCC_B_expand,&Black_boundary_bin_num[0],&white_boundary_bin_num[0]);
		}

		for(i=0;i<(Curve_num+1);i++) {
			Gz[i]=Main_extend_Curve[i];
			//   record extend curve for Tool Access
			(g_DCC_LAYER_Array_Struct->Expand_Curve)[i]=Gz[i];
		}

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
			ROSPrintf("[VPQ][DCC] DCC_Expand_Enable = Y \n");
#if DCC_Curve_Debug_flag
						if(i%4==0)
				ROSPrintf("[VPQ][DCC] EP_Cu[%d] = %d \n",i,(g_DCC_LAYER_Array_Struct->Expand_Curve)[i]);
			#endif
		}

	}

//o-------------------------------------------------o
//==========================================================
 }//if(DCC_Level == 0) //fix equalization



//==========================================================
//========= Self-refined Curve  Process : User Curve and database DCC =========
if(!bDCC_USER_S_SWAP){
//o------------DCC User Curve Adjust by mean value-----o
	if(DCC_UserAdjust_flag) {
		if(skin_tone_flag== 1) {
			drvif_color_DCC_User_Define_Curve_DCC(Curve_num,skin_tone_curve, USER_DEFINE_CURVE_DCC_CRTL_ITEM, SmartPic_clue->Hist_Y_Mean_Value, skin_tone_flag, Curve_Zero_s_point,Curve_Max_s_point);
			for(i=0;i<(Curve_num+1);i++) {
				skin_tone_curve[i]=Main_User_Define_Curve[i];
			}

		} else {
			drvif_color_DCC_User_Define_Curve_DCC(Curve_num,Gz, USER_DEFINE_CURVE_DCC_CRTL_ITEM, SmartPic_clue->Hist_Y_Mean_Value, skin_tone_flag, Curve_Zero_s_point,Curve_Max_s_point);
			for(i=0;i<(Curve_num+1);i++) {
				Gz[i]=Main_User_Define_Curve[i];
			}
		}

		for(i=0;i<(Curve_num+1);i++) {
			//   record extend curve for Tool Access
			(g_DCC_LAYER_Array_Struct->User_Curve)[i]=Main_User_Define_Curve[i];
	}

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
			ROSPrintf("DCC_UserAdjust_flag = Y (SWAP = %d) \n", bDCC_USER_S_SWAP);
			if(skin_tone_flag) {
				ROSPrintf("[VPQ][DCC] skin_tone_flag = Y \n");
			}
#if DCC_Curve_Debug_flag
			for(i=0;i<(Curve_num+1);i++) {
	 	 		ROSPrintf("[VPQ][DCC] Main_User_Define_Curve[%d] = %d \n",i,(g_DCC_LAYER_Array_Struct->User_Curve)[i]);
	}
#endif
	}
}
}
//o-------------------------------------------------o


//o--------------Database DCC-------------------o
	if((databaseDCC_enable==1)&&(skin_tone_flag==0)&&(vipTable_shareMem!=NULL))
	{
		database_DCC(bin,Curve_num,database_DCC_Table,Total_HCnt,DCC_Control_Structure);//MHH

		if((SmartPic_clue->Adapt_DCC_Info.database_case_num!=255) && (SmartPic_clue->Adapt_DCC_Info.database_weight!=255))
		{
			for(i=0;i<(Curve_num+1);i++)
			{
				Gz[i]=Main_database_Curve[i]; //actually, its not panel compensation, but a variable temperally load output curve
				(g_DCC_LAYER_Array_Struct->Database_Curve)[i]=Main_database_Curve[i];
			}
		}
	}

#if 0
	if((databaseDCC_enable==1)&&(skin_tone_flag==0)&&(vipTable_shareMem!=NULL)) {

		database_DCC(bin,Curve_num,database_DCC_Table,Total_HCnt,DCC_Control_Structure);

		if((SmartPic_clue->Adapt_DCC_Info.database_case_num!=255) && (SmartPic_clue->Adapt_DCC_Info.database_weight!=255)) {

			for(i=0;i<Curve_num_Max;i++) {
				Gz[i]=Main_database_Curve[i];
				//   record extend curve for Tool Access
				(g_DCC_LAYER_Array_Struct->Database_Curve)[i]=Main_database_Curve[i];
			}
		}

		//***** DCC_Debug_Printf *****
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
			ROSPrintf("[VPQ][DCC] Database Curve Enable = Y \n");
#if DCC_Curve_Debug_flag
			ROSPrintf("[VPQ][DCC] Database Curve result\n");
			for(i=0;i<Curve_num_Max;i++) {
				ROSPrintf("[VPQ][DCC] Gz[%d] = %d \n",i,Gz[i]);
			}
#endif
		}
	}
#endif
//o----------------------------------------------o
	if(DCC_panel_compensation_Flag == 1){
		drvif_color_DCC_panel_compensation(Curve_num,&Gz[0],&(vipTable_shareMem->panel_compensation_curve[0]),1,0);

		for(i=0;i<Curve_num_Max;i++){
			Gz[i]=Main_panel_compensation_Curve[i];
		}
	}


	if(DCC_Fix_output_range_Flag) {//default setting : output Curve mapping to output range start~end
		//drvif_color_DCC_Curve_range_remapping(Curve_num,Gz,DataRange_MAX,0,Curve_Zero_s_point,Curve_Max_s_point);
		drvif_color_DCC_Curve_range_remapping(Curve_num,Gz,output_Y_Max,output_Y_offset,Curve_num,0,0);
		for(i=0;i<Curve_num_Max;i++) {
			Gz[i]=Main_range_remapping_Curve[i];
		}
	}

	drvif_color_DCC_Curve_OSD_Blending(Curve_num,Gz,Identity,Pic_Mode_Weight);
	for(i=0;i<Curve_num_Max;i++) {
		Gz[i]=Main_Curve_Temp[i];
	}

//==========================================

//===================================================================
//=========== define for TV002 ADV API (gain multiply by 1024) =======================
	if(RPC_system_info_structure_table->Project_ID == VIP_Project_ID_TV002 || scalerVIP_access_tv002_style_demo_flag(0, NULL)) {
		scalerVIP_Gamma_Cal_byLevel(Gz);
		scalerVIP_BlackCorrector_Cal_byLevel(Gz);
	}

//========================================
//===== DCC Curve Blending  process  ===========

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)) {
		ROSPrintf("[VPQ][DCC] Default curver blending Coef \n ");
		ROSPrintf("[VPQ][DCC] dcc_delay_time=%d,dcc_Curve_change_step=%d \n ",dcc_delay_time,dcc_Curve_change_step);
	}

	if(pure_color == 1) {
		dcc_delay_time = 1;
	} else {
		dcc_delay_time += ((Advance_control_table_by_source->DCC_Curve_Blending_DT_table)[DCC_Curve_Blending_info[DCC_mean_diff]][DCC_Curve_Blending_info[DCC_Dev_diff]]);
	}
	dcc_Curve_change_step -= ((Advance_control_table_by_source->DCC_Curve_Blending_Step_table)[DCC_Curve_Blending_info[DCC_mean_diff]][DCC_Curve_Blending_info[DCC_Dev_diff]]);

	if(dcc_delay_time<=1)
		dcc_delay_time =1;

	if(dcc_Curve_change_step<=1)
		dcc_Curve_change_step =1;
	//========================================
	//===== DCC SC avoid flash process	===========

		//for Scene Change DCC curve apply with delay, if DCC curve can be applied without delay
		//**//20170526 hugh: for those drastic change of DCC curve, I use curve difference to measure the level of DCC changes of last scene and new scene.
		//					   If the index [Curve_diff], in  driver, of last scene and new scene is high, it will cause flash when SC. We will smooth the DCC change.
		unsigned long Curve_diff_thershold = 22; //it can be adjusted by who feel the flash, lower mean easier to enter the algorithm and less feel the flash.
		Curve_diff_thershold = Curve_diff_thershold >> shift_bit;
		static int Scene_change_DCC_apply_delay_flag = 0;
		Scene_change_DCC_apply_delay_flag = drvif_DCC_SC_smoothing_for_curve_delay_applied_condition_check( MainDCC_SC, Main_preH, Gz, Curve_diff_thershold, Scene_change_DCC_apply_delay_flag);
		//do
		if((Scene_change_DCC_apply_delay_enable == 1)  && (Scene_change_DCC_apply_delay_flag == 1) && (MainDCC_SC == 1) && (DCC_Status_Change_for_SCsmooth_flag != 1) && pure_color != 1 && skin_tone_flag != 1)
		{
			ROSPrintf("[DCC]do SC_delay\n");
			MainDCC_SC = 0;
			dcc_delay_time = 1;
			dcc_Curve_change_step = dcc_Curve_change_step + 10;
		}
		DCC_Status_Change_for_SCsmooth_flag = 0;
		//**//20170526 hugh end

		//SC register control
		if(d_dcc_fwused_0_reg.Dummy_debug_enable ==1) {
			MainDCC_SC			= d_dcc_fwused_0_reg.SceneChange;		// bit :2
		} else {
			d_dcc_fwused_0_reg.SceneChange			=	MainDCC_SC;
			rtd_outl(COLOR_DCC_D_DCC_FWUSED_0_reg,d_dcc_fwused_0_reg.regValue);

		}

	unsigned int Curve_diff = 0;
	int pure_color_weighting_for_DCC = 0;
	pure_color_weighting_for_DCC = drvif_Get_Purecolor_Weighting(); //weighting of pure color
	if((MA_print_count%debug_print_delay_time==0) && (Start_Print.DCC_3==TRUE))
	{
		ROSPrintf("[MHH]pure_color = %d\n", pure_color);
		ROSPrintf("[MHH]pure_color_weighting_for_DCC=%d \n",pure_color_weighting_for_DCC);
	}
	//doing blending of  identity line and original curve by weighting of purecolor
	for(i=0;i<(Curve_num+1);i++)
		Weighting_Identity[i] = (Identity[i] * pure_color_weighting_for_DCC + Gz[i] * (32 - pure_color_weighting_for_DCC)) >> 5;

	//Driver_DCC_Curve_change_method(display,&dcc_delay_time,&dcc_Curve_change_step );//TO DO...CSFC 201408

		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE)){
			ROSPrintf("[VPQ][DCC] Remaping DCC curver blending Coef \n ");
			ROSPrintf("[VPQ][DCC] dcc_delay_time=%d,dcc_Curve_change_step=%d \n ",dcc_delay_time,dcc_Curve_change_step);
		}

		if(display == SLR_MAIN_DISPLAY) {
			if(MainDCC_SC == 0 ) {//&& error_dist==0)
				if(scene_count_main % dcc_delay_time== 0) {//org:10
					if(pure_color == 1) { //if(((SmartPic_clue->skintoneflag) == 1) || (pure_color == 1))//for DCC S curve  20111109

						for(i=0;i<(Curve_num+1);i++) {

							step=( (i / 40)+dcc_Curve_change_step+1);
							if( abs(Main_preH[i]-Weighting_Identity[i]) > 100 ) // 20140315 jimmy: make step larger when distance is large
								step += 3;

							if(Main_preH[i] > Weighting_Identity[i]) {

								DCurve[i]=Main_preH[i]-step;
								if(DCurve[i] < Weighting_Identity[i])
									DCurve[i] = Weighting_Identity[i];

							}else if(Main_preH[i] < Weighting_Identity[i]) {

								DCurve[i]=Main_preH[i]+step;
								if(DCurve[i] > Weighting_Identity[i])
									DCurve[i] = Weighting_Identity[i];

							}else {
								DCurve[i]=Weighting_Identity[i];
							}

							if(i>0) {//be a nondecrease
								if((DCurve[i]-DCurve[i-1] )< 0){
									DCurve[i]=DCurve[i-1];
								}
							}
						}

					} else if( pre_which_source != which_source ){
					// 20150626 jimmy: for smooth toggle, change target to identity without making step larger
						for(i=0;i<(Curve_num+1);i++) {

							step=( (i / 40)+dcc_Curve_change_step+1);

							if(Main_preH[i] > Identity[i]) {

								DCurve[i]=Main_preH[i]-step;
								if(DCurve[i] < Identity[i])
									DCurve[i] = Identity[i];

							}else if(Main_preH[i] < Identity[i]) {

								DCurve[i]=Main_preH[i]+step;
								if(DCurve[i] > Identity[i])
									DCurve[i] = Identity[i];

							}else {
								DCurve[i]=Identity[i];
							}

							if(i>0) {//be a nondecrease
								if((DCurve[i]-DCurve[i-1] )< 0) {
									DCurve[i]=DCurve[i-1];
								}
							}
						}
						pre_which_source = which_source;
					} else if(skin_tone_flag == 1) {//for DCC S curve  20111109

						for(i=0;i<(Curve_num+1);i++)
						{
							step=( (i / 40)+dcc_Curve_change_step+1);
							if( abs(Main_preH[i]-skin_tone_curve[i]) > 100 ) // 20140315 jimmy: make step larger when distance is large
								step += 3;

							if(Main_preH[i] > skin_tone_curve[i]) {

								DCurve[i]=Main_preH[i]-step;
								if(DCurve[i] < skin_tone_curve[i])
									DCurve[i] = skin_tone_curve[i];

							}else if(Main_preH[i] < skin_tone_curve[i]) {

								DCurve[i]=Main_preH[i]+step;
								if(DCurve[i] > skin_tone_curve[i])
									DCurve[i] = skin_tone_curve[i];

							}else {
								DCurve[i]=skin_tone_curve[i];
							}

							if(i>0) {//be a nondecrease
								if((DCurve[i]-DCurve[i-1] )< 0) {
									DCurve[i]=DCurve[i-1];
								}
							}
						}

					} else {
						for(i=0;i<(Curve_num+1);i++) {
							Curve_diff += abs(Main_preH[i]-Gz[i]);

							step=( (i / 40)+dcc_Curve_change_step+1);
							if( abs(Main_preH[i]-DCurve[i]) > 100 ) {// 20140315 jimmy: make step larger when distance is large
								step += 3;
							}

							if(Main_preH[i] > Gz[i]) {

								DCurve[i]=Main_preH[i]-step;
								if(DCurve[i] < Gz[i])
									DCurve[i] = Gz[i];

							} else if(Main_preH[i] < Gz[i]) {

								DCurve[i]=Main_preH[i]+step;
								if(DCurve[i] > Gz[i])
									DCurve[i] = Gz[i];

							} else {
								DCurve[i]=Gz[i];
							}

							if(i>0){ //be a nondecrease
								if((DCurve[i]-DCurve[i-1] )< 0){
									DCurve[i]=DCurve[i-1];
								}
							}

						}

			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
				ROSPrintf("[VPQ][DCC]Curve_Blending_Enable = Y\n ");
				ROSPrintf("[VPQ][DCC]Curve step=%d,dcc_delay_time=%d ,scene_count_main=%d\n ",step,dcc_delay_time,scene_count_main);
#if DCC_Curve_Debug_flag
				for(i=0;i<(Curve_num+1);i++) {
					ROSPrintf("[VPQ][DCC]DCurve[%d] = %d\n ",i,DCurve[i]);
				}
#endif
			}

					}
				}else {
					for(i=0;i<(Curve_num+1);i++)
						DCurve[i] = Main_preH[i];
				}

			} else {
				if((Start_Print.Dcc_1==TRUE)) {

					if((Start_Print.DCC_3==TRUE)) {
						ROSPrintf("*************** [VPQ][DCC] Scene Change!!!!! ***************\n" );
					}

				}

				if(pure_color== 1) {
					if((Start_Print.DCC_3==TRUE)) {
						ROSPrintf("***************[VPQ][DCC] pure_color!!!!! ***************\n" );
					}
					for(i=0;i<(Curve_num+1);i++)
						DCurve[i] =Weighting_Identity[i];
				} else if(skin_tone_flag == 1) {
					if((Start_Print.DCC_3==TRUE)) {
						ROSPrintf("***************[VPQ][DCC] skin_tone_flag ***************\n" );
					}
					for(i=0;i<(Curve_num+1);i++)
						DCurve[i] = skin_tone_curve[i];
				} else {
					if((Start_Print.DCC_3==TRUE)) {
						ROSPrintf("***************[VPQ][DCC] Scene Change!!!!! SC_by_Dev_mean=%d ********\n",SmartPic_clue->SceneChange_by_diff_mean_Dev );

					}

					for(i=0;i<(Curve_num+1);i++) {
						DCurve[i] = Gz[i];

						if(i>0){ //be a nondecrease
							if((DCurve[i]-DCurve[i-1] )< 0){
								DCurve[i]=DCurve[i-1];
							}
						}
					}
				}
			}


			if(0) {//(Start_Print.DCC_3==TRUE))
				if(Curve_diff>=10) {
					Curve_change_count++;
					ROSPrintf("*******[VPQ][DCC] scene_count=%d, [%d]Curve_diff = %d *******\n",scene_count_main,Curve_change_count,Curve_diff );
				} else {
					Curve_change_count=0;
				}
			}

			// update the previous output-buffer
			for(i=0;i<(Curve_num+1);i++) {

				if(is3DLRmode) {
					if(DCC_3D_count == 0) {
						Main_preH[i]=DCurve[i];
					}
					DCC_3D_count = (DCC_3D_count+1)%2;
				} else {
					Main_preH[i]=DCurve[i];
				}
			}

			scene_count_main++;
			if( scene_count_main >= (1<<31) )
				scene_count_main=0;

		}else {	//Sub channel
			if(SubDCC_SC == 0) {
				if(scene_count_sub%10 == 0) {
					for(i=0;i<(Curve_num+1);i++) {
						if(Sub_preH[i] > Gz[i]) {

							DCurve[i]=Sub_preH[i]-step;
							if(DCurve[i] < Gz[i])	DCurve[i] = Gz[i];

						} else if(Sub_preH[i] < Gz[i]) {

							DCurve[i]=Sub_preH[i]+step;
							if(DCurve[i] > Gz[i])	DCurve[i] = Gz[i];

						} else {
							DCurve[i]=Gz[i];
						}

						if(i>0){ //be a nondecrease
							if((DCurve[i]-DCurve[i-1] )< 0) {
								DCurve[i]=DCurve[i-1];
							}
						}
					}
				}else {
					for(i=0;i<(Curve_num+1);i++)
						DCurve[i] = Sub_preH[i];
				}
			} else {
				for(i=0;i<(Curve_num+1);i++)
					DCurve[i] = Gz[i];
			}

			if(Total_HistCnt_Sub<Total_HistCnt_thl) {
				for(i=0;i<(Curve_num+1);i++)
					DCurve[i]=Identity[i];
			}

			// update the previous output-buffer
			for(i=0;i<(Curve_num+1);i++) {
				Sub_preH[i]=DCurve[i];
			}

			scene_count_sub++;

		}

//===================================





//==================================
//=== DCC Curve smooth ========

	if((DCC_Curve_LPF_Enable == 1)&&(pure_color_weighting_for_DCC!=32)) {
		scalerVIP_DCC_Curve_smooth(&DCurve[0],Curve_num,filter_tap,Curve_Zero_s_point,Curve_Max_s_point);
		for(i=0;i<(Curve_num+1);i++) {
			DCurve[i] = Main_Curve_Temp[i];
		}
		}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)) {
		ROSPrintf("[VPQ][DCC] DCC_Curve_LPF_Enable = Y \n ");
		ROSPrintf("[VPQ][DCC] After LPF result \n ");
		for(i=0;i<(Curve_num+1);i++) {
			ROSPrintf("[VPQ][DCC] DCurve[%d]=%d \n ",i,DCurve[i]);
			}
		}
//==================================

	//==== for boundary condition ======
		for(i=0;i<=(Curve_num);i++) {
			if(DCurve[i]<=output_Y_offset)
				DCurve[i]=output_Y_offset;

			if(DCurve[i]>=output_Y_Max)
				DCurve[i]=output_Y_Max;
		}

	//==== for boundary linear ======
	if(DCC_Limit_range_Hist_Cut_Flag && DCC_Fix_output_range_Flag && !pure_color) {
		if(DCC_output_range_linear_black_flag) {
			unsigned char linear_black = Curve_Zero_s_point;
			int numerator_of_linear = DCurve[linear_black]-0;
			int denominator_of_liear = linear_black-0;
			for(i=0; i<=linear_black-1; i++)
			{
				DCurve[i] = i*numerator_of_linear/denominator_of_liear;
			}
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)){
				ROSPrintf("[DCC][linear black]numerator = %d",numerator_of_linear);
				ROSPrintf("[DCC][linear black]denominator_of_liear = %d",denominator_of_liear);
			}
		}

		if(DCC_output_range_linear_white_flag) {
			unsigned char linear_white = Curve_Max_s_point;
			int numerator_of_linear = DataRange_MAX-DCurve[linear_white];
			int denominator_of_liear = COLOR_HISTOGRAM_LEVEL-linear_white;
			for(i=linear_white+1;i<=(Curve_num);i++)
			{
				DCurve[i] = (i-linear_white)*numerator_of_linear/denominator_of_liear + DCurve[linear_white];
			}
			if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)){
				ROSPrintf("[DCC][linear white]numerator_of_linear = %d",numerator_of_linear);
				ROSPrintf("[DCC][linear white]denominator_of_liear = %d",denominator_of_liear);
			}
		}
	}
	//==== for DCC_Fix_output_range_Flag boundary smooth======
	if(DCC_Fix_output_range_Flag) //
	{
		for(i=0;i<(Curve_num+1);i++) {
			Main_Curve_Temp[i] = DCurve[i];
		}
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
		{
			for(i=0;i<Curve_num_Max;i++) 
				ROSPrintf("[DCC][BEFORE]DCurve[%d] = %d\n",i, DCurve[i]);
		}
		if(DCC_Fix_output_range_start != 0)
		{
			for(i = 0; i< 5; ++i)
			{
				int ii = ((DCC_Fix_output_range_start+1)>>1) + i;
				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
					ROSPrintf("[DCC][low]Sum = %d\n", (Main_Curve_Temp[ii-1] + 2*Main_Curve_Temp[ii] + Main_Curve_Temp[ii+1])>>2);
				DCurve[ii] = (Main_Curve_Temp[ii-1] + 2*Main_Curve_Temp[ii] + Main_Curve_Temp[ii+1])>>2;
			}
		}
		if(DCC_Fix_output_range_end != (DataRange_MAX+1)>>DCC_OutputShift)
		{
			for(i = 0; i< 5; ++i)
			{
				int ii = ((DCC_Fix_output_range_end+1)>>1) - i;
				if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
					ROSPrintf("[DCC][high]Sum = %d\n", (Main_Curve_Temp[ii-1] + 2*Main_Curve_Temp[ii] + Main_Curve_Temp[ii+1])>>2);
				DCurve[ii] = (Main_Curve_Temp[ii-1] + 2*Main_Curve_Temp[ii] + Main_Curve_Temp[ii+1])>>2;
			}
		}
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE))
		{
			for(i=0;i<Curve_num_Max;i++) 
			{
				ROSPrintf("[DCC][AFTER]DCurve[%d] = %d\n",i, DCurve[i]);
			}
			ROSPrintf("[DCC]LP after remapping, DCC_Fix_output_range_start = %d\n", DCC_Fix_output_range_start);
			ROSPrintf("[DCC]LP after remapping, DCC_Fix_output_range_end = %d\n", DCC_Fix_output_range_end);
		}
		for(i=0;i<Curve_num_Max;i++) {
			Gz[i]=DCurve[i];
		}
	}
	//==========================
	//==== for curve progressive increase======
	for(i=0;i<=(Curve_num);i++)
	{
		if(i > 0 && DCurve[i]<DCurve[i-1])
			DCurve[i]=DCurve[i-1];
	}
	//==== for curve progressive increase======

	for(i=0;i<Curve_num_Max;i++) {
		//	 record extend curve for Tool Access
		(g_DCC_RPC_Adapt_DCC_Info_Item->Apply_Curve)[i]=DCurve[i];
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.DCC_3==TRUE)){
			ROSPrintf("[VPQ][DCC] ApplyCu[%d] = %d \n",i,(g_DCC_RPC_Adapt_DCC_Info_Item->Apply_Curve)[i]);
		}
	}


	for( i = 0; i <(TableSeg_num_Max); i++ ) {
		//for 32 DCC segment from MacArthur
		if(i==0) {
			BASE[i] = (DCurve[0]+Curve_data_range)%Curve_data_range;
		} else {
			BASE[i] = DCurve[i<<1]%Curve_data_range;
		}
		G0[i] = (DCurve[(i<<1)+1] - DCurve[i<<1])%Curve_segment_range;
		G1[i] = (DCurve[(i<<1)+2] - DCurve[(i<<1)+1])%Curve_segment_range;
	}

	if(display == SLR_MAIN_DISPLAY) {
		for( i = 0; i <(TableSeg_num_Max); i++ ) {
			INTERP_DATA=(BASE[i]<<16)+(G0[i]<<8)+G1[i];/*Mac5p ---> 10bits*/
			//INTERP_DATA=(BASE[i]<<20)+(G0[i]<<10)+G1[i];//Magellan2 --> 10bit to 12bit
			dcc_histogram_to_write[i]=INTERP_DATA;//move to D-domain ISR to write DCC table!! Reduce Write timing miss match!!( histogram_new_dcc_write_table() )
		}
		dcc_histogram_write_flag = TRUE;
		#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
		RPC_system_info_structure_table->SCPU_ISRIINFO_TO_VCPU.DCC_Curve_apply_flag = dcc_histogram_write_flag;
		#endif
	} else {
		for( i = 0; i <(TableSeg_num_Max); i++ ) {
			INTERP_DATA=(BASE[i]<<20)+(G0[i]<<10)+G1[i];
			dcc_histogram_to_write_sub[i] = INTERP_DATA;
		}
			dcc_histogram_write_flag = TRUE;
		#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
		RPC_system_info_structure_table->SCPU_ISRIINFO_TO_VCPU.DCC_Curve_apply_flag = dcc_histogram_write_flag;
		#endif
	}
	print_count++;

}

#endif

void scalerDCC_tv006_apply_dcc(unsigned char display, unsigned char Curve_bit_num)
{
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	_RPC_system_setting_info* RPC_system_info_structure_table = NULL;
	RPC_system_info_structure_table = scaler_GetShare_Memory_RPC_system_setting_info_Struct();

	if(display == SLR_MAIN_DISPLAY && RPC_system_info_structure_table)
		RPC_system_info_structure_table->SCPU_ISRIINFO_TO_VCPU.DCC_Curve_apply_flag = TRUE;
#else
	_RPC_clues* RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();
	int i;
	unsigned short Curve_num = 2 << Curve_bit_num;

	unsigned int INTERP_DATA = 0;
	unsigned int Curve_data_range = 1 << DCC_Curve_DataRang_bit;
	unsigned int Curve_segment_range = 1 << DCC_Curve_Segment_bit;

	if (NULL == RPC_SmartPic_clue)
		return;

	RPC_Adapt_DCC_Info_Item *pDCC_RPC_Adapt_DCC_Info_Item = &(RPC_SmartPic_clue->RPC_Adapt_DCC_Info);

	for (i=0;i<(Curve_num+1);i++)
	{
		DCurve[i] = pDCC_RPC_Adapt_DCC_Info_Item->Apply_Curve[i];
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
			ROSPrintf("ApplyCu[%d] = %d \n",i,(pDCC_RPC_Adapt_DCC_Info_Item->Apply_Curve)[i]);
	}

	for( i = 0; i <(TableSeg_num_Max); i++ )
	{
		//for 32 DCC segment from MacArthur
		if(i==0)
		{
			BASE[i] = (DCurve[0]+Curve_data_range)%Curve_data_range;
		}
		else
		{
			BASE[i] = DCurve[i<<1]%Curve_data_range;
		}
		G0[i] = (DCurve[(i<<1)+1] - DCurve[i<<1])%Curve_segment_range;
		G1[i] = (DCurve[(i<<1)+2] - DCurve[(i<<1)+1])%Curve_segment_range;
	}

	if(display == SLR_MAIN_DISPLAY)
	{
		for( i = 0; i <(TableSeg_num_Max); i++ )
		{
			INTERP_DATA=(BASE[i]<<16)+(G0[i]<<8)+G1[i];/*Mac5p ---> 10bits*/
			//INTERP_DATA=(BASE[i]<<20)+(G0[i]<<10)+G1[i];//Magellan2 --> 10bit to 12bit
			dcc_histogram_to_write[i]=INTERP_DATA;//move to D-domain ISR to write DCC table!! Reduce Write timing miss match!!( histogram_new_dcc_write_table() )
		}
		dcc_histogram_write_flag = TRUE;
	}
	/*
	else
	{
		for( i = 0; i <(TableSeg_num_Max); i++ )
		{
			INTERP_DATA=(BASE[i]<<20)+(G0[i]<<10)+G1[i];
			dcc_histogram_to_write_sub[i] = INTERP_DATA;
		}
			dcc_histogram_write_flag = TRUE;
	}
	*/
#endif
}


#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
void scalerDCC_SCPU_ISR_apply_dcc(UINT8 display, UINT8 Curve_bit_num)
{
	_RPC_clues* RPC_SmartPic_clue = scaler_GetShare_Memory_RPC_SmartPic_Clue_Struct();
	int i;
	unsigned short Curve_num = 2 << Curve_bit_num;

	unsigned int INTERP_DATA = 0;
	unsigned int Curve_data_range = 1 << DCC_Curve_DataRang_bit;
	unsigned int Curve_segment_range = 1 << DCC_Curve_Segment_bit;


	if (NULL == RPC_SmartPic_clue)
		return;

	RPC_Adapt_DCC_Info_Item *pDCC_RPC_Adapt_DCC_Info_Item = &(RPC_SmartPic_clue->RPC_Adapt_DCC_Info);

	for (i=0;i<(Curve_num+1);i++)
	{
		DCurve[i] = pDCC_RPC_Adapt_DCC_Info_Item->Apply_Curve[i];
		if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Dcc_1==TRUE))
			ROSPrintf("ApplyCu[%d] = %d \n",i,(pDCC_RPC_Adapt_DCC_Info_Item->Apply_Curve)[i]);
	}

	scalerVIP_DCCCurve_ChangeINT32Endian(&(DCurve[0]), DCC_Curve_Node_MAX );

	for( i = 0; i <(TableSeg_num_Max); i++ )
	{
		//for 32 DCC segment from MacArthur
		if(i==0)
		{
			BASE[i] = (DCurve[0]+Curve_data_range)%Curve_data_range;
		}
		else
		{
			BASE[i] = DCurve[i<<1]%Curve_data_range;
		}
		G0[i] = (DCurve[(i<<1)+1] - DCurve[i<<1])%Curve_segment_range;
		G1[i] = (DCurve[(i<<1)+2] - DCurve[(i<<1)+1])%Curve_segment_range;
	}

	if(display == SLR_MAIN_DISPLAY)
	{
		for( i = 0; i <(TableSeg_num_Max); i++ )
		{
			INTERP_DATA=(BASE[i]<<16)+(G0[i]<<8)+G1[i];/*Mac5p ---> 10bits*/
			//INTERP_DATA=(BASE[i]<<20)+(G0[i]<<10)+G1[i];//Magellan2 --> 10bit to 12bit
			dcc_histogram_to_write[i]=INTERP_DATA;//move to D-domain ISR to write DCC table!! Reduce Write timing miss match!!( histogram_new_dcc_write_table() )
		}
		dcc_histogram_write_flag = TRUE;
	}
}
#endif

void driver_DCC_Chroma_enhance_gain_cal(unsigned char display,unsigned char Table_sel, int *DCC_Apply_Curve,VIP_DCC_Chroma_Compensation_TABLE *table)
{
	int i = 0,m = 0, id =0;
	int chroma_gain[Chroma_Gain_Seg_MAX];
	int chroma_gain_t0[Chroma_Gain_Seg_MAX]={
			0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8,
			64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
			128, 128, 128, 128, 128, 128, 128, 128, 196, 196, 196, 196, 196, 196, 196, 128,
			256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256,
			256,
			};
	int chroma_gain_t1[Chroma_Gain_Seg_MAX]={
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0,
			};

	int filter[3]={1,2,1};//1->3tap
	int filter_5tap[5]={1,2,2,2,1};// 2-> 5tap
	int filter_7tap[7]={1,2,2,2,2,2,1};// 3-> 7tap
	int filter_9tap[9]={1,2,2,2,2,2,2,2,1};// 4-> 9tap
	int filter_11tap[11]={1,2,2,2,2,2,2,2,2,2,1};// 5-> 11tap
	int DCC_chroma_gain_Curve[Chroma_Gain_Seg_MAX];
	int sum_filter = 0;
	unsigned char tap_sum=0, tap_num=0, filter_tap = 2;

	filter_tap = 2;

	id=0;
	m=0;


	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Reverse_11==TRUE))
	{
		ROSPrintf("driver_DCC_Chroma_enhance_gain_cal!!\n");
	}

	for(i = 0; i < Chroma_Gain_Seg_MAX; i++) {
		table->chroma_gain_t0[i] = chroma_gain_t0[i];
		table->chroma_gain_t1[i] = chroma_gain_t1[i];
		if((table->chroma_gain_t0[i])<=128) {
			chroma_gain[i] = (((DCC_Apply_Curve[i*2] - Curve_Identity_2[i*2])*(int)(table->chroma_gain_t0[i]))/128) + (int)(table->chroma_gain_t1[i]);
		}else {
			chroma_gain[i] = (((DCC_Apply_Curve[i*2] - Curve_Identity_2[i*2])*(int)(table->chroma_gain_t0[i]))/64) + (int)(table->chroma_gain_t1[i]);
		}

		if(chroma_gain[i]>=63){
			chroma_gain[i]=63;
		}
		else if (chroma_gain[i]<=-63){
			chroma_gain[i]=-63;
		}
	}

	if(filter_tap==1)
	{
		tap_num=1;
	}
	else if(filter_tap==2)
	{
		tap_num=2;
	}
	else if (filter_tap==3)
	{
		tap_num=3;
	}
	else if (filter_tap==4)
	{
		tap_num=4;
	}
	else if (filter_tap==5)
	{
		tap_num=5;
	}

	for(m=-tap_num;m<=tap_num;m++)
	{
		if(filter_tap==1)
		{
			tap_sum += filter[m+1];
		}
		else if(filter_tap==2)
		{
			tap_sum += filter_5tap[m+2];
		}
		else if(filter_tap==3)
		{
			tap_sum += filter_7tap[m+3];
		}
		else if(filter_tap==4)
		{
			tap_sum += filter_9tap[m+4];
		}
		else if( filter_tap==5 )
		{
			tap_sum += filter_11tap[m+5];
		}
	}

	if(tap_sum<=0)
		return;

	for(i=0;i<(Chroma_Gain_Seg_MAX);i++)
	{
		sum_filter=0;
		for(m=-tap_num;m<=tap_num;m++)
		{
			id=i+m;
			if(id<(0))//boundary condition repeat method
				id=0;
			if(id>=Chroma_Gain_Seg_MAX)//boundary condition repeat method
				id=Chroma_Gain_Seg_MAX-1;

			if(tap_num==1)
			{
				sum_filter += chroma_gain[id]*filter[m+1];
			}
			else if(tap_num==2)
			{
				sum_filter += chroma_gain[id]*filter_5tap[m+2];
			}
			else if (tap_num==3)
			{
				sum_filter += chroma_gain[id]*filter_7tap[m+3];
			}
			else if (tap_num==4)
			{
				sum_filter += chroma_gain[id]*filter_9tap[m+4];
			}
			else if (tap_num==5)
			{
				sum_filter += chroma_gain[id]*filter_11tap[m+5];
			}
		}
		DCC_chroma_gain_Curve[i]=(sum_filter+(tap_sum>>1))/tap_sum;
	}

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Reverse_10==TRUE))
	{
		for(i = 0; i < Chroma_Gain_Seg_MAX; i++) {
			ROSPrintf("[%d]Cg=%d,diff=%d\n",i,chroma_gain[i],(DCC_Apply_Curve[i*2] - Curve_Identity_2[i*2]));
		}
	}
	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Reverse_11==TRUE))
	{
		for(i = 0; i < Chroma_Gain_Seg_MAX; i++) {
			ROSPrintf("[%d]AC=%d,CI=%d\n",i,chroma_gain[i] ,DCC_chroma_gain_Curve[i]);
		}
	}

	driver_DCC_Chroma_enhance_gain_apply(display, Table_sel, &DCC_chroma_gain_Curve[0]);
}



void driver_DCC_Chroma_enhance_gain_apply(unsigned char display,unsigned char Table_sel, int *chroma_gain)
{
return;
#if 0// mac5 dcc remove, chorma dosen't use sram, bypass chroma, caroline_170316
	/*set chroma gain table value*/
	int index, timeout = 10000;
	int chromaGainParaNum = 32;
	int base[32], g0[32], g1[32];
	int i, j;

	color_dcc_dcc_c_sram_tab_ctl_RBUS     dcc_c_sram_tab_ctl_reg;
	color_dcc_dcc_c_sram_tab_port_RBUS    dcc_c_sram_tab_port_reg;

	j = Table_sel;

	/*calc base, g0, g1*/
	for (i = 0; i < chromaGainParaNum; i++) {
		base[i] = chroma_gain[2 * i];
		g0[i] = chroma_gain[2 * i + 1] - chroma_gain[2 * i];
		g1[i] = chroma_gain[2 * i + 2] - chroma_gain[2 * i + 1];
		/*ROSPrintf( "[DCC] chroma[%d], base =%d, g0 =%d, g1 =%d\n", i, base[i], g0[i], g1[i] );*/
	}

	dcc_c_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg);
	dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_acc_index = 0;
	dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_rw_sel = 1;
	dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_acc_sel = j;
	rtd_outl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg, dcc_c_sram_tab_ctl_reg.regValue);

	index = -1;
	for (i = 0; i < chromaGainParaNum; i++) {
		do {
			dcc_c_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg);
			} while ((dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_acc_ready != 1) && ((timeout--) > 0));
		if (timeout < 0) {
			dcc_c_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg);
			dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_rw_sel = 0;
			rtd_outl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg, dcc_c_sram_tab_ctl_reg.regValue);
			ROSPrintf("DCC Chroma Table Init. Write DCC Chroma Init Table Fault at %d: Time Out!!\n", i);
			return;
		}
		index++;
		if (index != dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_acc_index_cur) {     /*cur = index*/
			dcc_c_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg);
			dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_rw_sel = 0;
			rtd_outl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg, dcc_c_sram_tab_ctl_reg.regValue);
			ROSPrintf("DCC Chroma Table Init. Write DCC Chroma Init Table Fault at %d: Index Error!!\n", i);
			return;
		}

		dcc_c_sram_tab_port_reg.regValue = rtd_inl(COLOR_DCC_DCC_C_SRAM_TAB_PORT_reg);
		dcc_c_sram_tab_port_reg.dcc_c_sram_tab_base = base[i];
		dcc_c_sram_tab_port_reg.dcc_c_sram_tab_g0 = g0[i];
		dcc_c_sram_tab_port_reg.dcc_c_sram_tab_g1 = g1[i];
		rtd_outl(COLOR_DCC_DCC_C_SRAM_TAB_PORT_reg, dcc_c_sram_tab_port_reg.regValue);
	}

	dcc_c_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg);
	dcc_c_sram_tab_ctl_reg.dcc_c_sram_tab_rw_sel = 0;
	rtd_outl(COLOR_DCC_DCC_C_SRAM_TAB_CTL_reg, dcc_c_sram_tab_ctl_reg.regValue);

	if((MA_print_count%debug_print_delay_time==0)&&(Start_Print.Reverse_11==TRUE))
	{
		ROSPrintf("driver_DCC_Chroma_enhance_gain_apply Final! %d\n",timeout);
	}
#endif
}

void scalerDCC_get_hist_window(unsigned short *pWidth, unsigned short *pHeight)
{
	histogram_ich1_hist_in_range_hor_RBUS ich1_hist_in_range_hor_Reg;
	histogram_ich1_hist_in_range_ver_RBUS ich1_hist_in_range_ver_Reg;

	ich1_hist_in_range_hor_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg);
	*pWidth = ich1_hist_in_range_hor_Reg.ch1_his_horend-ich1_hist_in_range_hor_Reg.ch1_his_horstart+1;
	rtd_outl(HISTOGRAM_ICH1_Hist_IN_Range_Hor_reg, ich1_hist_in_range_hor_Reg.regValue);
	ich1_hist_in_range_ver_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg);
	*pHeight = ich1_hist_in_range_ver_Reg.ch1_his_verend-ich1_hist_in_range_ver_Reg.ch1_his_verstart+1;
}
#ifdef CONFIG_HW_SUPPORT_D_HISTOGRAM
void scalerDCC_get_D_hist_window(unsigned short *pWidth, unsigned short *pHeight)
{
	d_histogram_d_ich1_hist_in_range_hor_RBUS d_ich1_hist_in_range_hor_Reg;
	d_histogram_d_ich1_hist_in_range_ver_RBUS d_ich1_hist_in_range_ver_Reg;

	d_ich1_hist_in_range_hor_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_IN_Range_Hor_reg);
	*pWidth = d_ich1_hist_in_range_hor_Reg.ch1_his_horend-d_ich1_hist_in_range_hor_Reg.ch1_his_horstart+1;
	rtd_outl(D_HISTOGRAM_D_ICH1_Hist_IN_Range_Hor_reg, d_ich1_hist_in_range_hor_Reg.regValue);
	d_ich1_hist_in_range_ver_Reg.regValue = rtd_inl(D_HISTOGRAM_D_ICH1_Hist_IN_Range_Ver_reg);
	*pHeight = d_ich1_hist_in_range_ver_Reg.ch1_his_verend-d_ich1_hist_in_range_ver_Reg.ch1_his_verstart+1;
}
#endif


