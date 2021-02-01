/*******************************************************************************
* @file    scalerColorLib.cpp
* @brief
* @note    Copyright (c) 2014 RealTek Technology Co., Ltd.
*		   All rights reserved.
*		   No. 2, Innovation Road II,
*		   Hsinchu Science Park,
*		   Hsinchu 300, Taiwan
*
* @log
* Revision 0.1	2014/01/27
* create
*******************************************************************************/
/*******************************************************************************
 * Header include
******************************************************************************/

#include <linux/delay.h>
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/string.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
//#include <mach/RPCDriver.h>
#include <linux/pageremap.h>
#include <mach/system.h>
#include <linux/hrtimer.h>

#include <tvscalercontrol/vip/vip_reg_def.h>
//#include <rbus/rbusHistogramReg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>

//#include <rbus/rbusODReg.h>
//#include <rbus/rbus_DesignSpec_MISC_LSADCReg.h>
//#include <rbus/rbusColorReg.h>
//#include <rbus/rbusCon_briReg.h>
//#include <rbus/rbusYuv2rgbReg.h>
//#include <rbus/rbusScaleupReg.h>
//#include <rbus/rbusColor_dccReg.h>
//#include <rbus/rbusGammaReg.h>
//#include <rbus/rbusInv_gammaReg.h>
#include <rbus/dm_reg.h>
#include <rbus/dolby_v_top_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/vodma_reg.h>
//#include "rbus/rbusHDMIReg.h"
#include <rbus/h3ddma_hsd_reg.h>


#if CONFIG_FIRMWARE_IN_KERNEL
/*#include </merlin_rbus/hdr/dolby_v_top_reg.h>*/ //Need SW sync,  SW Team not sync from TV001
#else
#include <rbus/dolby_v_top_reg.h>
#endif

//#include <rbus/dtg_reg.h>

/*#include <Application/AppClass/SetupClass.h>*/

/*#include "tvscalercontrol/scaler/scalerSuperResolution.h"*/
/*#include <tvscalercontrol/scaler/scalertimer.h>*/
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/scaler/scalercolorlib_tv001.h>
#include <tvscalercontrol/scaler/scalercolorlib_tv002.h>
/*#include <tvscalercontrol/scaler/scalerlib.h>*/
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/pipmp.h>
//#include <tvscalercontrol/scalerdrv/scalerdrv.h>

#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>
#include <tvscalercontrol/vip/dcc.h>
#include <tvscalercontrol/vip/intra.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/vip/peaking.h>
#include <tvscalercontrol/vip/nr.h>
#include <tvscalercontrol/vip/xc.h>
#include <tvscalercontrol/vip/di_ma.h>

#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <tvscalercontrol/hdmirx/hdmi_vfe.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/panel/panelapi.h>
/*#include <Platform_Lib/Board/pcbMgr.h>*/
/*#include <Platform_Lib/Board/pcb.h>*/
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scaler_vscdev.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>
#include <mach/rtk_log.h>
#if defined(CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT)|| defined(CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT)
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#endif

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
SLR_VIP_TABLE_CUSTOM_TV001	 *g_Share_Memory_VIP_TABLE_Custom_Struct_isr= NULL;
#endif

#define TAG_NAME "VPQ"

/*******************************************************************************
* Macro
******************************************************************************/
#define GET_USER_INPUT_SRC()					(Scaler_GetUserInputSrc(SLR_MAIN_DISPLAY))/*yuan 20130225*/

#define GET_UI_SOURCE_FROM_DISPLAY(display)		(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DATA_ARRAY_IDX))
#ifdef CONFIG_ENABLE_VIP_PSEUDO_RPC
#define vip_SendRPC vip_PseudoRPC
#else
#define vip_SendRPC Scaler_SendRPC
#endif

#define SCALERLIB_DEBUG

#ifdef SCALERLIB_DEBUG
  #define SLRLIB_PRINTF(format, args...) 		rtd_printk(KERN_DEBUG, TAG_NAME, format, ##args)
#else
  #define SLRLIB_PRINTF(format, args...)
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif


#define	GET_MAGIC_PERIOD_STATUS()				((pstMagicPicInfo->magic_parameter & _BIT7)>>7)
#define	SET_MAGIC_PIP_TYPE(x)					(pstMagicPicInfo->magic_parameter = ((pstMagicPicInfo->magic_parameter & (~0x0F)) | x))

/*******************************************************************************
* Constant
******************************************************************************/
/*#define example  100000 */ /* 100Khz */

/* Enable or Disable VIP flag*/

#define SensMax									0xE0
#define SensMin									0x0b
#define RPC_Send_Addr 							0
#define ShareMemAddrDummy 						0

#define AMBIENT_SENCER_ARRAY_SIZE				 30
#define ENABLE_RTK_DCR 1

/*******************************************************************************
 * Structure
 ******************************************************************************/

/*typedef struct*/
/*{*/
/*} MID_example_Param_t;*/


/*******************************************************************************
* enumeration
******************************************************************************/
/*typedef enum*/
/*{*/
/*    MID_Example_SLEEPING = 0,*/
/*    MID_Example_RUNNING,*/
/*} MID_Example_Status_t;*/



/*******************************************************************************
* Variable
******************************************************************************/
/*static unsigned char gExample = 100000;*//* 100K */

/*static UINT16 R_gain_autoview = 128, G_gain_autoview = 128, B_gain_autoview = 128;*/

/*static UINT32  DNR_TABLE_32[5] = {DNR_T0_32, DNR_T1_32, DNR_T2_32, DNR_T3_32, DNR_T4_32};*/
/*static UINT32 DNR_TABLE_8[5] = {DNR_T0, DNR_T1, DNR_T2, DNR_T3, DNR_T4};*/
/*static UINT32 MPEGNR_TABLE_8[5] = {MPEGNR_T0, MPEGNR_T1, MPEGNR_T2, MPEGNR_T3, MPEGNR_T4};*/ /*yuan*/
static unsigned char PQ_bin_info = 0;
unsigned char ucIsPrintVIP = 1;
unsigned char TableDCC;
unsigned char TableNRTemporal;
unsigned char TableNRSpatial;
unsigned char TableNR_RTNR_Y;
unsigned char TableNR_RTNR_C;
unsigned char TableNR_MPEGNR_H;/*sync from AT*/
unsigned char TableNR_MPEGNR_V;/*sync from AT*/

unsigned int Main_total_pixel_inv;


BOOL Low_ConBri_BrightnessBoost_Disable;
BOOL sRGB_User_Sat_Mapping;
/*static UINT16 APL_value;*/
/*static UINT8 ABL_Need_Reset = 1;	*/ /*rock 2012/06/20 change ABL off->on not work*/
#define BRIGHTNESS_BOOST_TIMER 50

/*==== Compal use light sensor compute formula*/
unsigned int LS_DET_SUM;
unsigned char LS_DET_WIDTH = 5;
unsigned char LS_DET_A_SPEED = 10;
unsigned char LS_DET_S_SPEED = 10;
unsigned char LS_DET_AVE = 255;
unsigned char LS_DET_AVE_OLD = 255;
unsigned char LS_DET_MAX;
unsigned char LS_DET_MIN = 255;
unsigned char LS_MAX = 255;


#if 0
#ifdef OPEN_CELL_PANEL
unsigned int *ODtable_Coeff;    /*young vippanel*/
#endif
#endif
/*void * 	p_ODTABLE;*/
/*static unsigned int *TV_AutoNR_Signal_Status_Coef; */ /*2010 csfanchiang*/
unsigned int *i_edge_smooth_coef;    /*20120301 march*/

UINT8 Mega_DCR;
UINT8 Mega_DCR_En;
bool Mega_DCR_Force_Off;
UINT8 Mega_DCR_Weight = 80;
UINT16 Mega_DCR_count;
UINT16 Set_Mega_DCR_count = 280;
//unsigned char g_LGE_HDR_en = 0;	//20151105 roger, use  VIP_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En]	//20150912 roger
unsigned char g_LGE_HDR_CSC_CTRL = 0;



/*static UINT16 Ambient_Sencer_pre[AMBIENT_SENCER_ARRAY_SIZE] = {128, 128, 128, 128, 128, 128, 128, 128, 128, 128,*/
/*																128, 128, 128, 128, 128, 128, 128, 128, 128, 128,*/
/*																128, 128, 128, 128, 128, 128, 128, 128, 128, 128};	*/ /*the array size is 30 ==> MAX BlackAPL_M_ATAB, need to check from spec*/
/*static UINT8 pre_Ambient_Sensor_Detect;*/
/*static UINT8 Display_On_Flag;*/

/*static UINT8 Scaler_APL_BL_MAX;*/
/*static UINT8 Scaler_APL_BL_MIN;*/
/*#if defined(BUILD_TV035_1)*/
/*static UINT8 Scaler_APL_PREBL = 100;*/
/*#else*/
/*static UINT8 Scaler_APL_PREBL = -1;*/
/*#endif*/
static unsigned char m_nowSource = 255;

unsigned char Main_DCC_User_Define_Curve_Table_Select;

BOOL sRGB_User_Sat_Enable;
UINT16 R_Gamma_Clamp_Max;
UINT16 G_Gamma_Clamp_Max;
UINT16 B_Gamma_Clamp_Max;


static COLOR_CALLBACK_FUNC1 m_cbFunc_getQualityCoef;
static COLOR_CALLBACK_FUNC1 m_cbFunc_getQualityExtend;
static COLOR_CALLBACK_FUNC1 m_cbFunc_getQualityExtend2;
static COLOR_CALLBACK_FUNC1 m_cbFunc_getQualityExtend3;
static COLOR_CALLBACK_FUNC1 m_cbFunc_getQualityExtend4;
static COLOR_CALLBACK_FUNC2 m_cbFunc_getColorData;
static COLOR_CALLBACK_FUNC2 m_cbFunc_getColorFacMode;
static COLOR_CALLBACK_FUNC2 m_cbFunc_getColorTempData;
static COLOR_CALLBACK_FUNC2 m_cbFunc_getColorTempData_TSB;
static COLOR_CALLBACK_FUNC2 m_cbFunc_getColorTempLevel;
static COLOR_CALLBACK_FUNC2 m_cbFunc_getPictureModeData;
static COLOR_CALLBACK_FUNC2 m_cbFunc_getDnrMode;
static COLOR_CALLBACK_FUNC3 m_cbFunc_getCurPicMode;
static COLOR_CALLBACK_FUNC4 m_cbFunc_getIcmByTimingPicmode;	/*Elsie 20131224*/
static COLOR_CALLBACK_FUNC5 m_cbFunc_getQuality3Dmode;/*young 3Dtable*/
unsigned char SR_edge_gain;
unsigned char SR_texture_gain;

RTK_VPQ_COLORSPACE_INDEX ColoSpace_Index;

VIP_PANEL_BIT default_vip_panel_bit = VIP_PANEL_BIT10; /*fixed me for link pass*/

unsigned char Table_CDS;
unsigned short Table_EGSM_Postshp;
unsigned char NR_HW_Dering_Level; /*fix compile error */ /* hsinyi21 20100325*/

static unsigned int od_mem_addr;

unsigned char g_picmode_Cinema = 0;

extern unsigned int vpq_project_id;
extern unsigned int vpqex_project_id;
extern unsigned short tRGB2YUV_COEF[RGB2YUV_COEF_MATRIX_MODE_Max][RGB2YUV_COEF_MATRIX_ITEMS_Max];
extern unsigned char g_tv002_demo_fun_flag;
extern RTK_VPQ_MODE_TYPE_TV030 picturemode;

extern UINT8 VipPQ_GetIntra_Ver2_TableSize(void);

static StructMagicPicInfo stMagicPicInfo = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static StructMagicPicInfo *pstMagicPicInfo = &stMagicPicInfo;
static int 				magic_step_x;
static int 				magic_step_y;
static int 				MAG_XSize;
static int 				MAG_YSize;
static int 				magic_zoom_step_x;
static int 				magic_zoom_step_y;
static int 				MAG_ZOOM_XSize;
static int 				MAG_ZOOM_YSize;

extern unsigned char vdc_power_status;

unsigned char MagicPicture_cnt;


static unsigned char m_bHDR_AutoRun=FALSE;
static unsigned char m_bDCCProcess=FALSE;

extern CHIP_LOCAL_CONTRAST_T glc_param;

extern UINT8 hdr_table[HDR_TABLE_NUM][HDR_ITEM_MAX];
extern UINT32 hdr_YUV2RGB[VIP_HDR_DM_CSC1_YUV2RGB_TABLE_Max][12];
extern UINT32 hdr_RGB2OPT[HDR_RGB2OPT_TABLE_NUM][9];
extern unsigned int HDR10_3DLUT_17x17x17[17*17*17*3];
extern UINT16 HDR10_3DLUT_24x24x24[HDR_24x24x24_size][3];
unsigned short OETF_LUT_ByMaxCLL_ByPanelLuminance[1025];

extern unsigned char vsc_get_adaptivestream_flag(void);
extern unsigned char get_sub_OutputVencMode(void);
extern void decide_hdr_mode(void);
extern unsigned char GammaBlendingFlag;
//extern unsigned char GammaBlendOETF;

unsigned short Power22InvGammaa[1025] = {
	0, 4, 7, 11, 14, 18, 21, 25, 28, 32, 36, 39, 43, 46, 50, 53, 57, 60, 64, 68, 71, 75, 78, 82, 85, 89, 92, 96, 100, 103, 107, 110, 114, 117, 121, 124, 128, 132, 135, 139, 142, 146, 149, 153, 156, 160, 164, 167, 171, 174, 178, 181, 185, 188, 192, 196, 199, 203, 206, 210, 213, 217, 220, 224,
	228, 231, 235, 238, 242, 245, 249, 252, 256, 260, 263, 267, 270, 274, 277, 281, 284, 288, 292, 306, 310, 314, 317, 321, 325, 329, 332, 336, 340, 344, 348, 352, 356, 360, 364, 368, 372, 376, 380, 384, 388, 392, 397, 401, 405, 409, 414, 418, 422, 427, 431, 436, 440, 444, 449, 453, 458, 463, 467, 472, 476, 481, 486, 490,
	495, 500, 505, 510, 514, 519, 524, 529, 534, 539, 544, 549, 554, 559, 564, 569, 574, 580, 585, 590, 595, 600, 606, 611, 616, 622, 627, 633, 638, 643, 649, 654, 660, 666, 671, 677, 682, 688, 694, 700, 705, 711, 717, 723, 729, 734, 740, 746, 752, 758, 764, 770, 776, 782, 788, 795, 801, 807, 813, 819, 826, 832, 838, 845,
	851, 857, 864, 870, 877, 883, 890, 896, 903, 909, 916, 923, 929, 936, 943, 950, 956, 963, 970, 977, 984, 991, 998, 1005, 1012, 1019, 1026, 1033, 1040, 1047, 1054, 1061, 1069, 1076, 1083, 1090, 1098, 1105, 1112, 1120, 1127, 1135, 1142, 1150, 1157, 1165, 1172, 1180, 1188, 1195, 1203, 1211, 1218, 1226, 1234, 1242, 1250, 1258, 1266, 1273, 1281, 1289, 1297, 1305,
	1314, 1322, 1330, 1338, 1346, 1354, 1363, 1371, 1379, 1387, 1396, 1404, 1413, 1421, 1429, 1438, 1446, 1455, 1463, 1472, 1481, 1489, 1498, 1507, 1515, 1524, 1533, 1542, 1551, 1560, 1568, 1577, 1586, 1595, 1604, 1613, 1622, 1631, 1641, 1650, 1659, 1668, 1677, 1687, 1696, 1705, 1714, 1724, 1733, 1743, 1752, 1762, 1771, 1781, 1790, 1800, 1809, 1819, 1829, 1838, 1848, 1858, 1868, 1877,
	1887, 1897, 1907, 1917, 1927, 1937, 1947, 1957, 1967, 1977, 1987, 1997, 2008, 2018, 2028, 2038, 2049, 2059, 2069, 2080, 2090, 2100, 2111, 2121, 2132, 2142, 2153, 2164, 2174, 2185, 2196, 2206, 2217, 2228, 2239, 2249, 2260, 2271, 2282, 2293, 2304, 2315, 2326, 2337, 2348, 2359, 2370, 2382, 2393, 2404, 2415, 2427, 2438, 2449, 2461, 2472, 2483, 2495, 2506, 2518, 2529, 2541, 2553, 2564,
	2576, 2588, 2599, 2611, 2623, 2635, 2647, 2658, 2670, 2682, 2694, 2706, 2718, 2730, 2742, 2754, 2766, 2779, 2791, 2803, 2815, 2828, 2840, 2852, 2865, 2877, 2889, 2902, 2914, 2927, 2939, 2952, 2964, 2977, 2990, 3002, 3015, 3028, 3041, 3053, 3066, 3079, 3092, 3105, 3118, 3131, 3144, 3157, 3170, 3183, 3196, 3209, 3222, 3236, 3249, 3262, 3275, 3289, 3302, 3315, 3329, 3342, 3356, 3369,
	3383, 3396, 3410, 3424, 3437, 3451, 3465, 3478, 3492, 3506, 3520, 3534, 3548, 3561, 3575, 3589, 3603, 3617, 3631, 3646, 3660, 3674, 3688, 3702, 3716, 3731, 3745, 3759, 3774, 3788, 3803, 3817, 3832, 3846, 3861, 3875, 3890, 3904, 3919, 3934, 3948, 3963, 3978, 3993, 4008, 4023, 4037, 4052, 4067, 4082, 4097, 4112, 4127, 4143, 4158, 4173, 4188, 4203, 4219, 4234, 4249, 4265, 4280, 4295,
	4311, 4326, 4342, 4357, 4373, 4389, 4404, 4420, 4436, 4451, 4467, 4483, 4499, 4514, 4530, 4546, 4562, 4578, 4594, 4610, 4626, 4642, 4658, 4675, 4691, 4707, 4723, 4739, 4756, 4772, 4788, 4805, 4821, 4838, 4854, 4871, 4887, 4904, 4920, 4937, 4954, 4970, 4987, 5004, 5021, 5037, 5054, 5071, 5088, 5105, 5122, 5139, 5156, 5173, 5190, 5207, 5224, 5242, 5259, 5276, 5293, 5311, 5328, 5345,
	5363, 5380, 5398, 5415, 5433, 5450, 5468, 5485, 5503, 5521, 5539, 5556, 5574, 5592, 5610, 5628, 5645, 5663, 5681, 5699, 5717, 5735, 5753, 5772, 5790, 5808, 5826, 5844, 5863, 5881, 5899, 5918, 5936, 5954, 5973, 5991, 6010, 6028, 6047, 6066, 6084, 6103, 6122, 6140, 6159, 6178, 6197, 6216, 6235, 6253, 6272, 6291, 6310, 6329, 6349, 6368, 6387, 6406, 6425, 6444, 6464, 6483, 6502, 6522,
	6541, 6561, 6580, 6599, 6619, 6639, 6658, 6678, 6697, 6717, 6737, 6757, 6776, 6796, 6816, 6836, 6856, 6876, 6896, 6916, 6936, 6956, 6976, 6996, 7016, 7036, 7056, 7077, 7097, 7117, 7138, 7158, 7178, 7199, 7219, 7240, 7260, 7281, 7301, 7322, 7343, 7363, 7384, 7405, 7426, 7446, 7467, 7488, 7509, 7530, 7551, 7572, 7593, 7614, 7635, 7656, 7678, 7699, 7720, 7741, 7763, 7784, 7805, 7827,
	7848, 7870, 7891, 7913, 7934, 7956, 7977, 7999, 8021, 8042, 8064, 8086, 8108, 8129, 8151, 8173, 8195, 8217, 8239, 8261, 8283, 8305, 8327, 8350, 8372, 8394, 8416, 8439, 8461, 8483, 8506, 8528, 8550, 8573, 8595, 8618, 8641, 8663, 8686, 8709, 8731, 8754, 8777, 8800, 8822, 8845, 8868, 8891, 8914, 8937, 8960, 8983, 9006, 9029, 9052, 9076, 9099, 9122, 9145, 9169, 9192, 9216, 9239, 9262,
	9286, 9309, 9333, 9356, 9380, 9404, 9427, 9451, 9475, 9499, 9522, 9546, 9570, 9594, 9618, 9642, 9666, 9690, 9714, 9738, 9762, 9786, 9811, 9835, 9859, 9883, 9908, 9932, 9957, 9981, 10005, 10030, 10054, 10079, 10104, 10128, 10153, 10178, 10202, 10227, 10252, 10277, 10301, 10326, 10351, 10376, 10401, 10426, 10451, 10476, 10501, 10527, 10552, 10577, 10602, 10628, 10653, 10678, 10704, 10729, 10754, 10780, 10805, 10831,
	10856, 10882, 10908, 10933, 10959, 10985, 11011, 11036, 11062, 11088, 11114, 11140, 11166, 11192, 11218, 11244, 11270, 11296, 11322, 11349, 11375, 11401, 11427, 11454, 11480, 11507, 11533, 11559, 11586, 11612, 11639, 11666, 11692, 11719, 11746, 11772, 11799, 11826, 11853, 11880, 11906, 11933, 11960, 11987, 12014, 12041, 12069, 12096, 12123, 12150, 12177, 12204, 12232, 12259, 12286, 12314, 12341, 12369, 12396, 12424, 12451, 12479, 12507, 12534,
	12562, 12590, 12617, 12645, 12673, 12701, 12729, 12757, 12785, 12813, 12841, 12869, 12897, 12925, 12953, 12981, 13009, 13038, 13066, 13094, 13123, 13151, 13180, 13208, 13237, 13265, 13294, 13322, 13351, 13379, 13408, 13437, 13466, 13494, 13523, 13552, 13581, 13610, 13639, 13668, 13697, 13726, 13755, 13784, 13813, 13843, 13872, 13901, 13930, 13960, 13989, 14019, 14048, 14077, 14107, 14136, 14166, 14196, 14225, 14255, 14285, 14314, 14344, 14374,
	14404, 14434, 14464, 14494, 14524, 14554, 14584, 14614, 14644, 14674, 14704, 14734, 14765, 14795, 14825, 14855, 14886, 14916, 14947, 14977, 15008, 15038, 15069, 15099, 15130, 15161, 15191, 15222, 15253, 15284, 15315, 15346, 15377, 15407, 15438, 15469, 15501, 15532, 15563, 15594, 15625, 15656, 15688, 15719, 15750, 15782, 15813, 15844, 15876, 15907, 15939, 15971, 16002, 16034, 16065, 16097, 16129, 16161, 16192, 16224, 16256, 16288, 16320, 16352, 16384,
};

/*******************************************************************************
* Program
******************************************************************************/
static void Scaler_MagicPictureInit(void);
static void mScalerDisableMagicPicture(void);
static void mScalerMagicStoreContrast(void);
static void mScalerMagicPictureColorOff(void);

extern void scalerVIP_quality_init(unsigned long arg);
extern unsigned int quality_init_value[QUALITY_INIT_MAX];
extern unsigned char ColorSpaceMode;
void LightSensorValRead(UINT8 pad, UINT8  *buf)
{
#if 0 //Fix compiler error for Mac5p by Will
	UINT32 valReg = ST_PAD0_VADDR;
	UINT32 tmp;

	if (pad > 4 || buf == NULL)
		return;

	valReg += (pad*4);
	tmp = IoReg_Read32(valReg);
	*buf = tmp & 0xFF;
#endif
}

bool PQ_demo_mode = 0;
static struct file* file_open(const char* path, int flags, int rights) {
	struct file* filp = NULL;
	mm_segment_t oldfs;
	int err = 0;

	oldfs = get_fs();
	set_fs(get_ds());
	filp = filp_open(path, flags, rights);
	set_fs(oldfs);
	if(IS_ERR(filp)) {
		err = PTR_ERR(filp);
		return NULL;
	}
	return filp;
}

static void file_close(struct file* file) {
	filp_close(file, NULL);
}

static int file_read(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_read(file, data, size, &offset);

	set_fs(oldfs);
	return ret;
}

static int file_write(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_write(file, data, size, &offset);

	set_fs(oldfs);
	return ret;
}

static int file_sync(struct file* file) {
	vfs_fsync(file, 0);
	return 0;
}

void *fwif_color_get_VIP_Extend2_CoefArray(unsigned char src_idx)
{
	if (m_cbFunc_getQualityExtend2 == NULL)
		return NULL;

	return m_cbFunc_getQualityExtend2((VIP_SOURCE_TIMING)src_idx);
}

#if 0
VIP_QUALITY_Extend3_Coef *fwif_color_get_VIP_Extend3_CoefArray(unsigned char src_idx)
{
	if (m_cbFunc_getQualityExtend3 == NULL)
		return NULL;

	return (VIP_QUALITY_Extend3_Coef *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)src_idx);
}

/*young 3Dtable*/
VIP_QUALITY_3Dmode_Coef *fwif_color_get_VIP_3Dmode_CoefArray(unsigned char src_idx)/*young 3Dtable*/
{
	if (m_cbFunc_getQuality3Dmode == NULL)
		return NULL;

	return (VIP_QUALITY_3Dmode_Coef *)m_cbFunc_getQuality3Dmode((VIP_3DSOURCE_TIMING)src_idx);
}

VIP_QUALITY_Extend4_Coef *fwif_color_get_VIP_Extend4_CoefArray(unsigned char src_idx)
{
	if (m_cbFunc_getQualityExtend4 == NULL)
		return NULL;

	return (VIP_QUALITY_Extend4_Coef *)m_cbFunc_getQualityExtend4((VIP_SOURCE_TIMING)src_idx);
}
#endif

StructColorDataType *fwif_color_get_color_data(unsigned char src_idx, unsigned char timing)
{
	if (m_cbFunc_getColorData == NULL)
		return NULL;

	return (StructColorDataType *)m_cbFunc_getColorData(Scaler_InputSrcFormat(src_idx), timing, 0);
}

StructColorDataFacModeType *fwif_color_get_color_fac_mode(unsigned char src_idx, unsigned char timing)
{
	if (m_cbFunc_getColorFacMode == NULL)
		return NULL;

	/*return (StructColorDataFacModeType *)m_cbFunc_getColorFacMode(Scaler_InputSrcFormat(src_idx), timing, fwif_color_get_picture_mode(src_idx));*/
	return (StructColorDataFacModeType *)m_cbFunc_getColorFacMode(Scaler_InputSrcFormat(src_idx), timing, 0);
}

StructColorDataFacModeType *fwif_color_get_color_fac_mode_by_picture(unsigned char src_idx, unsigned char timing, unsigned char pic)
{
	if (m_cbFunc_getColorFacMode == NULL)
		return NULL;

	return (StructColorDataFacModeType *)m_cbFunc_getColorFacMode(Scaler_InputSrcFormat(src_idx), timing, pic);
}

SLR_COLORTEMP_DATA *fwif_color_get_color_tempset_using_colortmp(unsigned char colortmp)
{
	if (m_cbFunc_getColorTempData_TSB == NULL)
		return NULL;

	return (SLR_COLORTEMP_DATA *)m_cbFunc_getColorTempData_TSB(0, 0, colortmp);
}

SLR_COLORTEMP_DATA *scaler_get_color_tempset(unsigned char src_idx, unsigned char timing)
{
	if (m_cbFunc_getColorTempData == NULL)
		return NULL;

	return (SLR_COLORTEMP_DATA *)m_cbFunc_getColorTempData(Scaler_InputSrcFormat(src_idx), timing, 0);
}

unsigned char Scaler_Set_Gamma_level(unsigned char value)
{
	extern unsigned char gammalevel;
	extern unsigned char flag_of_setting_gammacurve_index_without_GammaMode;
	gammalevel = value;
	if(gammalevel != GAMMA_CURVE_RELATE_TO_GAMMA_MODE)
		flag_of_setting_gammacurve_index_without_GammaMode = 1;
	return 0;
}

SLR_COLORTEMP_LEVEL scaler_get_color_temp_level(unsigned char src_idx, unsigned char timing)
{
	SLR_COLORTEMP_LEVEL level;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	level = VIP_system_info_structure_table->OSD_Info.OSD_colorTemp;
	//level = (SLR_COLORTEMP_LEVEL)(*pValue);

	/*VIPprintf("$$$$$$$$== fwif_color_get_color_temp_level = %d =====\n", level);*/
	return level;
}

void scaler_set_color_temp_level(SLR_COLORTEMP_LEVEL level)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	if (m_cbFunc_getColorTempLevel == NULL)
		return SLR_COLORTEMP_NORMAL;
	VIP_system_info_structure_table->OSD_Info.OSD_colorTemp = level;

	//rtd_printk(KERN_EMERG, TAG_NAME, "scaler_set_color_temp_level, level = %d\n", level);
	return;
}


unsigned char scaler_get_color_temp_level_type(unsigned char src_idx)
{
	return scaler_get_color_temp_level(src_idx, 0);
}

unsigned char Scaler_GetIntensity(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Intensity;
}

/*range 0~100*/
void Scaler_SetIntensity(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Intensity = value;
}

unsigned char Scaler_OsdMapToRegValue_Saturation(unsigned char display , unsigned char value)
{
	#if  defined(TV020_STYLE_PQ) || defined(BUILD_TV030_2)
	return  fw_OsdMapToRegValue(display, FAC_SATURATION, value);
	#else
	return 0;
	#endif
}
unsigned char Scaler_OsdMapToRegValue_Hue(unsigned char display , unsigned char value)
{
	#if  defined(TV020_STYLE_PQ) || defined(BUILD_TV030_2)
	return  fw_OsdMapToRegValue(display, FAC_HUE, value);
	#else
	return 0;
	#endif
}


#ifdef OSD_FOUR_LEVEL_MAPPING_ENABLE
unsigned char Scaler_GetFacSaturation(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75)
{
	StructColorDataFacModeType *pTable = NULL;
    unsigned char src_idx = 0;
    unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Saturation_0;
	*retval_50 = pTable->Saturation_50;
	*retval_100 = pTable->Saturation_100;
	*retval_25 = pTable->Saturation_25;
	*retval_75 = pTable->Saturation_75;
	return 0;
}
unsigned char Scaler_SetFacSaturation(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Saturation_0 = val_0;
	pTable->Saturation_50 = val_50;
	pTable->Saturation_100 = val_100;
	pTable->Saturation_25 = val_25;
	pTable->Saturation_75 = val_75;
	return 0;
}

unsigned char Scaler_GetFacHue(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75)
{
	StructColorDataFacModeType *pTable = NULL;
    unsigned char src_idx = 0;
    unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Hue_0;
	*retval_50 = pTable->Hue_50;
	*retval_100 = pTable->Hue_100;
	*retval_25 = pTable->Hue_25;
	*retval_75 = pTable->Hue_75;
	return 0;
}
unsigned char Scaler_SetFacHue(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Hue_0 = val_0;
	pTable->Hue_50 = val_50;
	pTable->Hue_100 = val_100;
	pTable->Hue_25 = val_25;
	pTable->Hue_75 = val_75;
	return 0;
}

#else

unsigned char Scaler_GetFacSaturation(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Saturation_0;
	*retval_50 = pTable->Saturation_50;
	*retval_100 = pTable->Saturation_100;
	return 0;
}

unsigned char Scaler_SetFacSaturation(unsigned char val_0, unsigned char val_50, unsigned char val_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Saturation_0 = val_0;
	pTable->Saturation_50 = val_50;
	pTable->Saturation_100 = val_100;
	return 0;
}

unsigned char Scaler_GetFacHue(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Hue_0;
	*retval_50 = pTable->Hue_50;
	*retval_100 = pTable->Hue_100;
	return 0;
}

unsigned char Scaler_SetFacHue(unsigned char val_0, unsigned char val_50, unsigned char val_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Hue_0 = val_0;
	pTable->Hue_50 = val_50;
	pTable->Hue_100 = val_100;
	return 0;
}

#endif

/*======================= set hue /sat  ============*/
extern unsigned char get_ADC_Input_Source(void);
extern unsigned char get_AVD_Input_Source(void);
void fwif_color_vsc_to_scaler_src_mapping(unsigned char vsc_src, unsigned char *p_scaler_src_type, unsigned char *p_scaler_src_form)
{
	if (p_scaler_src_type == NULL || p_scaler_src_form == NULL)
		return;

	switch(vsc_src)
	{
		case VSC_INPUTSRC_AVD:
			*p_scaler_src_type = get_AVD_Input_Source();
			*p_scaler_src_form = _SRC_FROM_VDC;
			break;
		case VSC_INPUTSRC_ADC:
			*p_scaler_src_type = get_ADC_Input_Source();
			*p_scaler_src_form = _SRC_FROM_ADC;
			break;
		case VSC_INPUTSRC_HDMI:
			*p_scaler_src_type = _SRC_HDMI;
			*p_scaler_src_form = _SRC_FROM_TMDS;
			break;
		case VSC_INPUTSRC_VDEC:
			*p_scaler_src_type = _SRC_VO;
			*p_scaler_src_form = _SRC_FROM_VO;
			break;
		case VSC_INPUTSRC_JPEG:
			*p_scaler_src_type = _SRC_VO;
			*p_scaler_src_form = _SRC_FROM_VO;
			break;
		default:
			;
	}
}

unsigned char fwif_color_get_cur_input_timing_mode(unsigned char display)
{
#ifdef CONFIG_FORCE_RUN_I3DDMA
		if (display == SLR_MAIN_DISPLAY)
			return drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_MODE_CURR);
		else
			return Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
#else
		return Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
#endif
}

unsigned char fwif_vip_HDR10_check(unsigned char display, unsigned char input_src_type)
{
	unsigned char bHDR_flag =FALSE;
	SLR_VOINFO* pVOInfo = NULL;
	pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
	 //  VUI Handler
	_system_setting_info *VIP_system_info_structure_table=NULL;
	VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if(input_src_type == _SRC_VO) {
		fwif_color_VIP_get_VO_Info(input_src_type);
	} else if (input_src_type == _SRC_HDMI) {
		fwif_color_VIP_get_DRM_Info(input_src_type);
	} else {
		VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag = 0;
		VIP_system_info_structure_table->BT2020_CTRL.Mode = BT2020_MODE_Max;
		VIP_system_info_structure_table->HDR_CTRL.EOTF_Mode = HDR_MODE_Max;
	}

	if( (input_src_type == _SRC_VO) || (input_src_type == _SRC_HDMI) ){
		VIPprintf("====   transfer_characteristics  =%d =======\n",pVOInfo->transfer_characteristics );
		VIPprintf("====   matrix_coefficiets  =%d =======\n",pVOInfo->matrix_coefficiets );
		VIPprintf("====   colour_primaries  =%d =======\n",pVOInfo->colour_primaries );
		VIPprintf("====   H_size =%d =======\n",pVOInfo->h_width);
		VIPprintf("====   V_size =%d =======\n",pVOInfo->v_length);
	    VIPprintf("H_Start=%d , V_Start = %d \n",pVOInfo->h_start,pVOInfo->v_start);
		//VIPprintf("====   Dolby_mode =%d =======\n",get_HDR_Dolby_mode());
		//printk("====   HDR10_HDMI =%d =======\n",hdmi_is_drm_info_ready());
		VIPprintf("====   _CTL_reg =%d =======\n",(IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg) & 7));
		VIPprintf("====   input_src_type =%d =======\n",input_src_type);
		#if 0  // meta_data
		VIPprintf("====   nMax_display_mastering_luminance  =%d =======\n",pVOInfo->nMax_display_mastering_luminance);
		VIPprintf("====   nMin_display_mastering_luminance  =%d =======\n",pVOInfo->nMin_display_mastering_luminance);
		VIPprintf("====   MaxFALL  =%d =======\n",pVOInfo->MaxFALL);
		VIPprintf("====   bVideo_full_range_flag  =%d =======\n",pVOInfo->bVideo_full_range_flag);
		VIPprintf("====   rgb x =%d ,%d ,%d =======\n",pVOInfo->nDisplay_primaries_x[0],pVOInfo->nDisplay_primaries_x[1],pVOInfo->nDisplay_primaries_x[2]);
		VIPprintf("====   rgb y =%d ,%d ,%d =======\n",pVOInfo->nDisplay_primaries_y[0],pVOInfo->nDisplay_primaries_y[1],pVOInfo->nDisplay_primaries_y[2]);
		#endif
	}
	if(input_src_type == _SRC_VO || (input_src_type == _SRC_HDMI)){    // usb & hdmi
		if((VIP_system_info_structure_table->HDR_CTRL.EOTF_Mode == ITU_SMPTE2084) && (VIP_system_info_structure_table->BT2020_CTRL.Mode == BT2020_MODE_Non_Constant) && (VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1) )  // BT2020_MODE_Non_Constant
			bHDR_flag = HAL_VPQ_HDR_MODE_HDR10;
		else if((VIP_system_info_structure_table->HDR_CTRL.EOTF_Mode == ITU_SMPTE2084) && (VIP_system_info_structure_table->BT2020_CTRL.Mode == BT2020_MODE_Constant) && (VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1) ) // BT2020_MODE_Constant
			bHDR_flag = HAL_VPQ_HDR_MODE_HDR10;
		else if((VIP_system_info_structure_table->HDR_CTRL.EOTF_Mode == ITU_ARIB_STD_B67) && (VIP_system_info_structure_table->BT2020_CTRL.Mode == BT2020_MODE_Non_Constant) && (VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1))
			bHDR_flag = HAL_VPQ_HDR_MODE_HLG;
		else if((VIP_system_info_structure_table->HDR_CTRL.EOTF_Mode == ITU_ARIB_STD_B67) && (VIP_system_info_structure_table->BT2020_CTRL.Mode == BT2020_MODE_Constant) && (VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1))
			bHDR_flag = HAL_VPQ_HDR_MODE_HLG;
		else
			bHDR_flag = HAL_VPQ_HDR_MODE_SDR;
#if 0
		#if defined(CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT)|| defined(CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT)
		else if(hdmi_is_drm_info_ready()) {   // else if(get_HDR_mode()== HDR_HDR10_HDMI)
		    VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag = 1;
			VIP_system_info_structure_table->BT2020_CTRL.Mode = BT2020_MODE_Non_Constant;
			VIP_system_info_structure_table->HDR_CTRL.EOTF_Mode = ITU_SMPTE2084;
			bHDR_flag = 3 ;
		}
		#endif
#endif
         #if 0  // for skyworth show log
		if (bHDR_flag != FALSE && bHDR_flag != 3 )    // show usb logo
	{
#if __BIONIC__ == 1
			__system_property_set("rtk.stream.type", "HDR10");
		#endif
	}
		#endif
	}
	#if 0  // meta_data
	//  record HDR info
    if(bHDR_flag){
		  VIP_system_info_structure_table->HDR_info.nTransfer_characteristics =pVOInfo->transfer_characteristics;
		  VIP_system_info_structure_table->HDR_info.nMatrix_coefficiets=  pVOInfo->matrix_coefficiets;
		  VIP_system_info_structure_table->HDR_info.nColor_primaries=   pVOInfo->colour_primaries;
		  VIP_system_info_structure_table->HDR_info.bVideo_full_range_flag =pVOInfo->bVideo_full_range_flag;
		  VIP_system_info_structure_table->HDR_info.nDisplay_primaries_x[0]  =  Scaler_ChangeUINT16Endian(pVOInfo->nDisplay_primaries_x[0]);
		  VIP_system_info_structure_table->HDR_info.nDisplay_primaries_x[1]  =  Scaler_ChangeUINT16Endian(pVOInfo->nDisplay_primaries_x[1]);
		  VIP_system_info_structure_table->HDR_info.nDisplay_primaries_x[2]  =  Scaler_ChangeUINT16Endian(pVOInfo->nDisplay_primaries_x[2]);
		  VIP_system_info_structure_table->HDR_info.nDisplay_primaries_y[0]  =  Scaler_ChangeUINT16Endian(pVOInfo->nDisplay_primaries_y[0]);
		  VIP_system_info_structure_table->HDR_info.nDisplay_primaries_y[1]  =  Scaler_ChangeUINT16Endian(pVOInfo->nDisplay_primaries_y[1]);
		  VIP_system_info_structure_table->HDR_info.nDisplay_primaries_y[2]  =  Scaler_ChangeUINT16Endian(pVOInfo->nDisplay_primaries_y[2]);
		  VIP_system_info_structure_table->HDR_info.nWhite_point_x           = Scaler_ChangeUINT16Endian(pVOInfo->nWhite_point_x);
		  VIP_system_info_structure_table->HDR_info.nWhite_point_y           = Scaler_ChangeUINT16Endian(pVOInfo->nWhite_point_y);
		  VIP_system_info_structure_table->HDR_info.nMax_display_mastering_luminance= Scaler_ChangeUINT32Endian(pVOInfo->nMax_display_mastering_luminance);
		  VIP_system_info_structure_table->HDR_info.nMin_display_mastering_luminance= Scaler_ChangeUINT32Endian(pVOInfo->nMin_display_mastering_luminance);
		  VIP_system_info_structure_table->HDR_info.MaxCLL=Scaler_ChangeUINT32Endian(pVOInfo->MaxCLL);
		  VIP_system_info_structure_table->HDR_info.MaxFALL=Scaler_ChangeUINT32Endian(pVOInfo->MaxFALL);

	}
	#endif
	VIP_system_info_structure_table ->HDR_flag = bHDR_flag;

	return bHDR_flag;
}

unsigned char fwif_vip_DolbyHDR_check(unsigned char display, unsigned char input_src_type)
{
	unsigned char bDolby_HDR_flag = FALSE;
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if(input_src_type == _SRC_VO || input_src_type == _SRC_HDMI) // usb & hdmi
	{
		#if defined(CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT)
		if((IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg) & 7) == 2 || Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result())
		#else
		if((IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg) & 7) == 2)
		#endif
			bDolby_HDR_flag = 1;
	}

	if (VIP_system_info_structure_table != NULL)
		VIP_system_info_structure_table ->DolbyHDR_flag = bDolby_HDR_flag;

	return bDolby_HDR_flag;
}

unsigned char fwif_vip_source_check(unsigned char display, unsigned char callmode)
{
	unsigned char which_source = 255;
	unsigned char input_src_type;
	unsigned char input_src_form;
	unsigned char input_timming_info;
	unsigned char input_VO_Form;
	unsigned char input_TVD_Form;
	/*unsigned char NowSourceOption;*/
	unsigned char video_format = COLOR_UNKNOW;
	unsigned char hdmiDataRange = MODE_RAG_UNKNOW;
#ifdef CONFIG_Force_HDMI_RGB_INTO_VIP_Mode
	unsigned char ForceHDMIIntoVIPMode = 0;
#endif
	unsigned char Frame_Packing_mode = 0;
	unsigned char vdc_ColorStandard = VDC_MODE_NO_SIGNAL;
	SLR_RATIO_TYPE ratio_type = SLR_RATIO_DISABLE;
	SLR_VOINFO* pVOInfo = NULL;
	unsigned char bHDR_flag = FALSE;
	unsigned char bDolby_HDR_flag = FALSE;

	_system_setting_info *VIP_system_info_structure_table=NULL;
	VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table=NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

#ifdef CONFIG_Force_HDMI_RGB_INTO_VIP_Mode
	ForceHDMIIntoVIPMode = 1;
#endif

	if (fwif_color_get_force_run_i3ddma_enable(SLR_MAIN_DISPLAY) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_VDEC)) {
		fwif_color_vsc_to_scaler_src_mapping(Get_DisplayMode_Src(SLR_MAIN_DISPLAY), &input_src_type, &input_src_form);
		input_timming_info 	= drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_MODE_CURR);
	} else {
		if (callmode == BY_DISPLAY) {
			input_src_type = Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display);
			input_src_form = Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display);
		} else {
			input_src_type = Scaler_InputSrcGetMainChType();
			input_src_form = Scaler_InputSrcGetMainChFrom();
		}

		input_timming_info 	= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	}

	input_VO_Form		= Scaler_VOFrom(Scaler_Get_CurVoInfo_plane());
	input_TVD_Form		= Scaler_InputSrcGetMainFormat();
	ratio_type		= Scaler_DispGetRatioMode();/*for TV035*/
	/*NowSourceOption		= Get_NowSourceOption();	*/ /*fix me Mac3 no this function*/
	pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());

	if(pVOInfo == NULL){
		VIPprintf("[%s:%d] Warning here!! pVOInfo=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if (vpqex_project_id != 0x00060000) {
			bHDR_flag = fwif_vip_HDR10_check(display,input_src_type);
			bDolby_HDR_flag= fwif_vip_DolbyHDR_check(display,input_src_type);
	} else {
		if(((pVOInfo->transfer_characteristics == 16)/* && (pVOInfo->matrix_coefficiets == 9)*/ && (pVOInfo->colour_primaries == 9))&&(input_src_type == _SRC_VO))
			bHDR_flag = 1 ;
		else
			bHDR_flag = 0 ;

		//rtd_printk(KERN_DEBUG, TAG_NAME, "\n rord get_HDMI_HDR_mode()=%d,get_OTT_HDR_mode()=%d  \n",get_HDMI_HDR_mode(),get_OTT_HDR_mode());

#if CONFIG_FIRMWARE_IN_KERNEL
		if((input_src_type == _SRC_VO)||input_src_type ==_SRC_HDMI )
		{
			if((get_HDMI_HDR_mode() == HDR_DOLBY_HDMI) || (get_HDMI_HDR_mode() == HDR_DOLBY_COMPOSER)||get_OTT_HDR_mode() == HDR_DOLBY_COMPOSER)
			{//HDMI dolby or HDR10 mdoe
				bDolby_HDR_flag =1;

			}
			else
			{
				bDolby_HDR_flag =0;

			}
		}
		else
		{
			bDolby_HDR_flag =0;

		}
#else
		if((input_src_type == _SRC_VO) && ((get_HDMI_HDR_mode() != HDR_MODE_DISABLE)|| (get_OTT_HDR_mode() != HDR_MODE_DISABLE) || ((IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg) & 7) != 0))) {
		#if 0
					pr_notice("[DolbyVision] input_src_type=%d\n",input_src_type);
			pr_notice("[DolbyVision] get_HDR_mode=%d\n",get_HDR_mode());
			pr_notice("[DolbyVision] %x, %x\n",IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg),(IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg) & 7));
	            #endif
			bDolby_HDR_flag = 1;
		} else {
			bDolby_HDR_flag = 0;
		}
#endif
	}


	#if 0
	VIPprintf( "++++++++++++fwif_vip_source_check debug Part.A+++++++++++++++++++\n");
	VIPprintf( "[source_check]input_src_from = %d \n", input_src_form);
	VIPprintf( "[source_check]input_src_type = %d \n", input_src_type);
	VIPprintf( "[source_check]Scaler_VOFrom = %d \n", Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()));
	VIPprintf( "[source_check]drvif_scalerVideo_readMode = %d \n", drvif_module_vdc_ReadMode(VDC_SET));
	VIPprintf( "[source_check]Scaler_DispGetInputInfo = %d \n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
	VIPprintf( "[source_check]Scaler_InputSrcFormat = %d \n", Scaler_InputSrcFormat(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DATA_ARRAY_IDX)));
	VIPprintf( "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	#endif

	if( input_src_form == _SRC_FROM_VDC )
	{
		if( vdc_power_status )
			vdc_ColorStandard = drvif_module_vdc_ReadMode(VDC_SET);

		if( input_src_type == _SRC_TV )
		{

			switch( vdc_ColorStandard )
			{
				case VDC_MODE_NTSC: /*480I*/
					which_source = VIP_QUALITY_TV_NTSC;
					break;
				case VDC_MODE_PALM: /*480I*/
					which_source = VIP_QUALITY_TV_PAL_M;
					break;
				case VDC_MODE_NTSC443: /*480I*/
					which_source = VIP_QUALITY_TV_NTSC443;
					break;
				case VDC_MODE_PALI: /*576I*/
					which_source = VIP_QUALITY_TV_PAL;
					break;
				case VDC_MODE_SECAM: /*576I*/
					which_source = VIP_QUALITY_TV_SECAN;
					break;
				case VDC_MODE_PAL60: /*480I*/
					which_source = VIP_QUALITY_TV_PAL60;
					break;
				case VDC_MODE_PALN: /*576I*/
					which_source = VIP_QUALITY_TV_PALN;
					break;
				case VDC_MODE_NTSC50: /**/
					which_source = VIP_QUALITY_TV_NTSC50;
					break;
				default:
					if( input_timming_info == _MODE_480I )
						which_source = VIP_QUALITY_TV_NTSC;
					else
						which_source = VIP_QUALITY_TV_PAL;
					break;
			}

		}
		else if( input_src_type == _SRC_CVBS )
		{

			switch( vdc_ColorStandard )
			{
				case VDC_MODE_NTSC: /*480I*/
					which_source = VIP_QUALITY_CVBS_NTSC;
					break;
				case VDC_MODE_PALM: /*480I*/
					which_source = VIP_QUALITY_CVBS_PAL_M;
					break;
				case VDC_MODE_PALI: /*576I*/
					which_source = VIP_QUALITY_CVBS_PAL;
					break;
				case VDC_MODE_SECAM: /*576I*/
					which_source = VIP_QUALITY_CVBS_SECAN;
					break;
				case VDC_MODE_NTSC443: /*480I*/
					which_source = VIP_QUALITY_CVBS_NTSC443;
					break;
				case VDC_MODE_PAL60: /*480I*/
					which_source = VIP_QUALITY_CVBS_PAL60;
					break;
				case VDC_MODE_PALN: /*576I*/
					which_source = VIP_QUALITY_CVBS_PALN;
					break;
				case VDC_MODE_NTSC50: /**/
					which_source = VIP_QUALITY_CVBS_NTSC50;
					break;
				default:
					if( input_timming_info == _MODE_480I )
						which_source = VIP_QUALITY_CVBS_NTSC;
					else
						which_source = VIP_QUALITY_CVBS_PAL;
					break;
			}

		}
		else if( (input_src_type == _SRC_SV) || (input_src_type == _SRC_COMPONENT) )
		{

			switch( vdc_ColorStandard )
			{
				case VDC_MODE_NTSC: /*480I*/
					which_source = VIP_QUALITY_CVBS_S_NTSC;
					break;
				case VDC_MODE_PALM: /*480I*/
					which_source = VIP_QUALITY_CVBS_S_PAL_M;
					break;
				case VDC_MODE_PALI: /*576I*/
					which_source = VIP_QUALITY_CVBS_S_PAL;
					break;
				case VDC_MODE_SECAM: /*576I*/
					which_source = VIP_QUALITY_CVBS_S_SECAN;
					break;
				case VDC_MODE_NTSC443: /*480I*/
				case VDC_MODE_PAL60: /*480I*/
				case VDC_MODE_PALN: /*576I*/
				case VDC_MODE_NTSC50: /**/
				default:
					if( input_timming_info == _MODE_480I )
						which_source = VIP_QUALITY_CVBS_S_NTSC;
					else
						which_source = VIP_QUALITY_CVBS_S_PAL;
					break;
			}

		}
#ifdef CONFIG_SCART_ENABLE
		else if( (input_src_type == _SRC_SCART) || (input_src_type == _SRC_SCART_RGB) )
		{
			// RGB
			if( (drvif_module_vdc_read_FSW_value()>=SCART_RGB_CVBS_THRESHOLD) || (input_src_type == _SRC_SCART_RGB) )
			{
				switch( Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR) )
				{
					case _MODE_480I: // NTSC
						if( vdc_ColorStandard == VDC_MODE_PALM )
							which_source = VIP_QUALITY_SCART_RGB_PAL;
						else
							which_source = VIP_QUALITY_SCART_RGB_NTSC;
						break;
					case _MODE_576I: // PAL
						if( vdc_ColorStandard == VDC_MODE_SECAM )
							which_source = VIP_QUALITY_SCART_RGB_SECAN;
						else
							which_source = VIP_QUALITY_SCART_RGB_PAL;
						break;
					default: // PAL
						which_source = VIP_QUALITY_SCART_RGB_PAL;
						break;
				}

			}
			else
			{
				switch (Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR))
				{
					case _MODE_480I: // NTSC
						if(vdc_ColorStandard == VDC_MODE_PALM)
							which_source = VIP_QUALITY_SCART_PAL;
						else
							which_source = VIP_QUALITY_SCART_NTSC;
						break;
					case _MODE_576I: // PAL
						if(vdc_ColorStandard == VDC_MODE_SECAM)
							which_source = VIP_QUALITY_SCART_SECAN;
						else
							which_source = VIP_QUALITY_SCART_PAL;
						break;
					default: // PAL
						which_source = VIP_QUALITY_SCART_PAL;
						break;
				}
			}
		}
#endif
	}
	else if (input_src_type == _SRC_VGA) {
		which_source = VIP_QUALITY_VGA;
	} else if ((input_src_type == _SRC_VO) && (input_VO_Form != VO_FROM_JPEG)) {	/* 0) DTV or  2)GAME*/
		/*if (NowSourceOption == SOURCE_PLAYBACK)			*/ /* USB source  */ /*fix me Mac3 no this function*/
		if (input_TVD_Form == TVD_INFMT_VODMA1)	{		/* USB source*/

			/*USER: Vincent_Lee  DATE: 2012/06/08  TODO: is JPEG?*/
			if (Scaler_VOFromJPEG(Scaler_Get_CurVoInfo_plane()) == 1) {
				which_source = VIP_QUALITY_DTV_JPEG;
			} else {
			switch (input_timming_info) {
			case _MODE_480I:
				which_source = VIP_QUALITY_PVR_480I;
				break;
			case _MODE_576I:
				which_source = VIP_QUALITY_PVR_576I;
				break;
			case  _MODE_480P:
				which_source = VIP_QUALITY_PVR_480P;
				break;
			case _MODE_576P:
				which_source = VIP_QUALITY_PVR_576P;
				break;
			case _MODE_720P50:
			case _MODE_720P60:
				which_source = VIP_QUALITY_PVR_720P;
				break;
			case _MODE_1080I25:
			case _MODE_1080I30:
				which_source = VIP_QUALITY_PVR_1080I;
				break;
			case _MODE_1080P50:
			case _MODE_1080P60:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_PVR_1080p;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_PVR_1080P;
				else
				which_source = VIP_QUALITY_PVR_1080P;
				break;
				/*which_source = VIP_QUALITY_PVR_1080P;*/
				break;
			case _MODE_4k2kI30:
				which_source = VIP_QUALITY_PVR_4k2kI_30;
				break;
			case _MODE_4k2kP30:
			case _MODE_4k2kP24:
			case _MODE_4k2kP25:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_PVR_4k2kP_30;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_PVR_4k2kP;
				else
					which_source = VIP_QUALITY_PVR_4k2kP_30;
				break;
			case _MODE_4k2kP48:
			case _MODE_4k2kP50:
			case _MODE_4k2kP60:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_PVR_4k2kP_60;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_PVR_4k2kP;
				else
					which_source = VIP_QUALITY_PVR_4k2kP_60;
				break;

			default:
				which_source = VIP_QUALITY_PVR_480I;
				break;
			}
		}
	} else {															/* DTV source*/

			switch (input_timming_info) {
			case _MODE_480I:
				which_source = VIP_QUALITY_DTV_480I;
				break;
			case _MODE_576I:
				which_source = VIP_QUALITY_DTV_576I;
				break;
			case  _MODE_480P:
				which_source = VIP_QUALITY_DTV_480P;
				break;
			case _MODE_576P:
				which_source = VIP_QUALITY_DTV_576P;
				break;
			case _MODE_720P50:
			case _MODE_720P60:
				which_source = VIP_QUALITY_DTV_720P;
				break;
			case _MODE_1080I25:
			case _MODE_1080I30:
				which_source = VIP_QUALITY_DTV_1080I;
				break;
			case _MODE_1080P50:
			case _MODE_1080P60:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_DTV_1080p;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_DTV_1080P;
				else
				which_source = VIP_QUALITY_DTV_1080P;
				/*which_source = VIP_QUALITY_DTV_1080P;*/
				break;
			case _MODE_4k2kI30:
				which_source = VIP_QUALITY_DTV_4k2kI_30;
				break;
			case _MODE_4k2kP30:
			case _MODE_4k2kP24:
			case _MODE_4k2kP25:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_DTV_4k2kP_30;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_DTV_4k2kP;
				else
				which_source = VIP_QUALITY_DTV_4k2kP_30;
				break;
			case _MODE_4k2kP48:
			case _MODE_4k2kP50:
			case _MODE_4k2kP60:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_DTV_4k2kP_60;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_DTV_4k2kP;
				else
					which_source = VIP_QUALITY_DTV_4k2kP_60;
				break;

			default:
				which_source = VIP_QUALITY_DTV_480I;
				break;
			}
		}
	} else if ((input_src_type == _SRC_VO) && (input_VO_Form == VO_FROM_JPEG)) {/* VO JPEG source	*/ /* Erin add '100920*/

			/*Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID);  */ /* M domain᪺width*/
			/*Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN);  */ /* M domain᪺height*/

			which_source = VIP_QUALITY_DTV_JPEG;
	} else if (input_src_type == _SRC_YPBPR) {
		switch (input_timming_info) {
		case _MODE_480I:
			which_source = VIP_QUALITY_YPbPr_480I;
			break;
		case _MODE_576I:
			which_source = VIP_QUALITY_YPbPr_576I;
			break;
		case  _MODE_480P:
			which_source = VIP_QUALITY_YPbPr_480P;
			break;
		case _MODE_576P:
			which_source = VIP_QUALITY_YPbPr_576P;
			break;
		case _MODE_720P50:
			which_source = VIP_QUALITY_YPbPr_720P;
			break;
		case _MODE_720P60:
			which_source = VIP_QUALITY_YPbPr_720P;
			break;
		case _MODE_1080I25:
			which_source = VIP_QUALITY_YPbPr_1080I;
			break;
		case _MODE_1080I30:
			which_source = VIP_QUALITY_YPbPr_1080I;
			break;
		case _MODE_1080P50:
			which_source = VIP_QUALITY_YPbPr_1080P;
			break;
		case _MODE_1080P60:
			which_source = VIP_QUALITY_YPbPr_1080P;
			break;
		default:
			which_source = VIP_QUALITY_YPbPr_720P;
			break;
		}
	} else {
		video_format = drvif_Hdmi_GetColorSpace();
		hdmiDataRange =  drvif_IsRGB_YUV_RANGE();

		#if 0
		VIPprintf("++++++++++++fwif_vip_source_check debug Part.B+++++++++++++++++++\n");
		VIPprintf("[source_check] drvif_IsHDMI()= %d			     $$$$$$$$\n", drvif_IsHDMI());
		VIPprintf("[source_check] drvif_Hdmi_HdcpEnabled()= %d   $$$$$$$$\n", drvif_Hdmi_HdcpEnabled());
		VIPprintf("[source_check] video_format = %d				  $$$$$$$$\n", video_format);
		VIPprintf("[source_check] ForceHDMIIntoVIPMode()= %d	     $$$$$$$$\n", ForceHDMIIntoVIPMode);
		VIPprintf("[source_check] drvif_Hdmi_IsAudioLock() = %d    $$$$$$$$\n", drvif_Hdmi_IsAudioLock());
		VIPprintf("[source_check] Scaler_DispGetInputInfo() = %d    $$$$$$$$\n", Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR));
		VIPprintf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		#endif


		/*if (drvif_IsHDMI() && ((drvif_Hdmi_HdcpEnabled()) || (video_format != COLOR_RGB) || (ForceHDMIIntoVIPMode) || (drvif_Hdmi_IsAudioLock()))) {*/ /* HDMI*/
		/* isHDMI + video timing =>  !VGA, accroding to ref set.*/
		if (drvif_IsHDMI()) { /* HDMI*/

					/* checkk if HDMI mode, not DVI mode, modify this by Jerry Wu 20100120,*/
					/* add HDCP check 20100224*/
					/* add YUV mode into this mode 20100903 Jerry Wu*/

			#if defined(BUILD_TV035_1)
			/*alina peng 2013-01-23 for HDMI dot by dot mode*/
			unsigned short TimingMode;
			TimingMode = input_timming_info;
			if (ratio_type == SLR_RATIO_POINTTOPOINT) {
				TimingMode = _MODE_NEW;
			}
			switch (TimingMode)
			#else
			switch (input_timming_info)
			#endif
			{
			case _MODE_480I:
				which_source = VIP_QUALITY_HDMI_480I;
				break;
			case _MODE_576I:
				which_source = VIP_QUALITY_HDMI_576I;
				break;
			case  _MODE_480P:
				which_source = VIP_QUALITY_HDMI_480P;
				break;
			case _MODE_576P:
				which_source = VIP_QUALITY_HDMI_576P;
				break;
#if (defined BUILD_TV005_1_ISDB)
			case _MODE_720P24:
			case _MODE_720P30:
#endif
			case _MODE_720P50:
			case _MODE_720P60:
				which_source = VIP_QUALITY_HDMI_720P;
				break;
			case _MODE_1080I25:
			case _MODE_1080I30:
				which_source = VIP_QUALITY_HDMI_1080I;
				break;
			case _MODE_1080P50:
			case _MODE_1080P60:
	/*==USER: Vincent_Lee  DATE: 2011/08/12  TODO: Add new CASE for 1080P24 mode==*/
			case _MODE_1080P23:
			case _MODE_1080P24:
			case _MODE_1080P25:
			case _MODE_1080P29:
			case _MODE_1080P30:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_HDMI_1080p;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_HDMI_1080P;
				else
					which_source = VIP_QUALITY_HDMI_1080P;
				break;
	/*==USER: Vincent_Lee  DATE: 2011/08/12  TODO: Add new CASE for 1080P24 mode==*/
				/*which_source = VIP_QUALITY_HDMI_1080P;*/
				break;
			case _MODE_4k2kI30:
				which_source = VIP_QUALITY_HDMI_4k2kI_30;
				break;
			case _MODE_4k2kP30:
			case _MODE_4k2kP24:
			case _MODE_4k2kP25:
					if(bHDR_flag)
						which_source = VIP_QUALITY_HDR_HDMI_4k2kP_30;
					else if(bDolby_HDR_flag)
						which_source = VIP_QUALITY_DolbyHDR_HDMI_4k2kP;
					else
						which_source = VIP_QUALITY_HDMI_4k2kP_30;
					break;
			case _MODE_4k2kP48:
			case _MODE_4k2kP50:
			case _MODE_4k2kP60:
				if(bHDR_flag)
					which_source = VIP_QUALITY_HDR_HDMI_4k2kP_60;
				else if(bDolby_HDR_flag)
					which_source = VIP_QUALITY_DolbyHDR_HDMI_4k2kP;
				else
					which_source = VIP_QUALITY_HDMI_4k2kP_60;
				break;

			/*USER: egger  DATE: 2011/09/21  TODO: Add new CASE for frame packing mode*/
			case _MODE_NEW:
				Frame_Packing_mode = Scaler_Get3D_IsFramePacking();
				if (Frame_Packing_mode == 1)
					which_source = VIP_QUALITY_HDMI_720P;
				else if (Frame_Packing_mode == 2)
					which_source = VIP_QUALITY_HDMI_1080P;
				else
				    which_source = VIP_QUALITY_VGA; /* VGA Timing*/
				break;
			default:
				/*which_source = VIP_QUALITY_HDMI_720P;*/
				  which_source = VIP_QUALITY_VGA; /* VGA Timing*/
				break;
			}
		} else { /* DVI*/
			which_source = VIP_QUALITY_VGA;
		}

	}

	/*VIPprintf("\n--- __lhh__  -2  Source = %d\n", which_source);*/
	#if  !defined  IS_TV05_STYLE_PICTUREMODE

		if (which_source == VIP_QUALITY_TV_NTSC443)
			which_source = VIP_QUALITY_TV_NTSC;
	#endif

	/*=== 20140421 CSFC for vip video fw infomation ====*/
	/* setting some information to sharememory*/
	VIP_system_info_structure_table->Input_src_Type		= input_src_type;
	VIP_system_info_structure_table->Input_src_Form		= input_src_form;
	VIP_system_info_structure_table->Input_VO_Form		= input_VO_Form;
	VIP_system_info_structure_table->Input_TVD_Form		= input_TVD_Form;
	VIP_system_info_structure_table->vdc_color_standard	= vdc_ColorStandard;
	VIP_system_info_structure_table->Timing				= input_timming_info;
	VIP_system_info_structure_table->HDMI_video_format	= video_format;
	VIP_RPC_system_info_structure_table->VIP_source 		= which_source;
	VIP_system_info_structure_table->Display_RATIO_TYPE	= ratio_type;
	/*VIP_system_info_structure_table->NowSourceOption	= NowSourceOption; */ /*fix me Mac3 no this function*/
	VIP_system_info_structure_table->HDMI_data_range    = hdmiDataRange;
	VIP_system_info_structure_table ->HDR_flag = bHDR_flag;
	VIP_system_info_structure_table ->DolbyHDR_flag = bDolby_HDR_flag;
	VIP_system_info_structure_table ->VO_Width = pVOInfo->h_width;
	VIP_system_info_structure_table ->VO_Height = pVOInfo->v_length;

	VIP_system_info_structure_table->input_display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	VIP_system_info_structure_table->HDMI_color_space = Scaler_DispGetInputInfo(SLR_INPUT_COLOR_SPACE);
	VIP_system_info_structure_table->IV_Start = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);
	VIP_system_info_structure_table->IH_Start = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA);
	VIP_system_info_structure_table->I_Height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
	VIP_system_info_structure_table->I_Width = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
	VIP_system_info_structure_table->Mem_Height = Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN);
	VIP_system_info_structure_table->Mem_Width = Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID);
	VIP_system_info_structure_table->Cap_Height = Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN);
	VIP_system_info_structure_table->Cap_Width = Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID);
	VIP_system_info_structure_table->DI_Width = Scaler_DispGetInputInfo(SLR_INPUT_DI_WID);
	VIP_system_info_structure_table->D_Height = Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);
	VIP_system_info_structure_table->D_Width = Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID);
	VIP_system_info_structure_table->color_fac_src_idx = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY, SLR_INPUT_DATA_ARRAY_IDX);
	/*============================================*/

	return which_source;
}



/*young 3Dtable*/


unsigned char fwif_vip_3Dsource_check(unsigned char display, unsigned char callmode)
{
	unsigned char which_source = 255;
	unsigned char input_src_type;
	unsigned char input_src_from;
	unsigned char video_format;
	unsigned char ForceHDMIIntoVIPMode = 0;
	/*unsigned char Frame_Packing_mode = 0;*/
	bool boolHd = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_MEM_ACT_WID) > 640 ? 1 : 0;


#ifdef CONFIG_Force_HDMI_RGB_INTO_VIP_Mode
	ForceHDMIIntoVIPMode = 1;
#endif

	if (callmode == BY_DISPLAY) {
		input_src_type = Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display);
		input_src_from = Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display);
	} else {
		input_src_type = Scaler_InputSrcGetMainChType();
		input_src_from = Scaler_InputSrcGetMainChFrom();
	}



	if (input_src_from == _SRC_FROM_VDC) {

	} else if (input_src_type == _SRC_VGA) {

	} else if ((input_src_type == _SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) != 1)) {/* DTV source*/
		if (Scaler_InputSrcGetMainFormat() == TVD_INFMT_VODMA1) {/*USB*/
			/*switch (GET_HDMI_3DTYPE())*/
			switch (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)) {
			case SLR_3D_FRAME_PACKING:
				which_source = (boolHd ? VIP_QUALITY_USB_HD_FP : VIP_QUALITY_USB_SD_FP);
				break;
			case SLR_3D_SIDE_BY_SIDE_HALF:
				which_source = VIP_QUALITY_USB_SBS;
				break;
			case SLR_3D_TOP_AND_BOTTOM:
				which_source = VIP_QUALITY_USB_TOP_BOTTOM;
				break;
			}
		} else {
			switch (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)) {/*DTV*/
			case SLR_3D_FRAME_PACKING:
				which_source = (boolHd ? VIP_QUALITY_DTV_HD_FP : VIP_QUALITY_DTV_SD_FP);
				break;
			case SLR_3D_SIDE_BY_SIDE_HALF:
				which_source = VIP_QUALITY_DTV_SBS;
				break;
			case SLR_3D_TOP_AND_BOTTOM:
				which_source = VIP_QUALITY_DTV_TOP_BOTTOM;
				break;
			}
		}

	} else if ((input_src_from != _SRC_FROM_VDC) && (input_src_type != _SRC_VGA) && (input_src_type == _SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) == 1)) {/* VO JPEG source	*/ /* Erin add '100920*/

	} else if (input_src_type == _SRC_YPBPR) {

	} else {
		video_format = drvif_Hdmi_GetColorSpace();
		if (drvif_IsHDMI() && ((drvif_Hdmi_HdcpEnabled()) || (video_format != 0) || (ForceHDMIIntoVIPMode) || (drvif_Hdmi_IsAudioLock()))) {
			/* HDMI*/
			/* checkk if HDMI mode, not DVI mode, modify this by Jerry Wu 20100120,*/
			/* add HDCP check 20100224*/
			/* add YUV mode into this mode 20100903 Jerry Wu*/

			switch (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)) {
			case SLR_3D_FRAME_PACKING:
				which_source = (boolHd ? VIP_QUALITY_HDMI_HD_FP : VIP_QUALITY_HDMI_SD_FP);
				break;
			case SLR_3D_SIDE_BY_SIDE_HALF:
				which_source = VIP_QUALITY_HDMI_SBS;
				break;
			case SLR_3D_TOP_AND_BOTTOM:
				which_source = VIP_QUALITY_HDMI_TOP_BOTTOM;
				break;
			}
		} else {

		}

	}

	if (which_source == 255) {
		which_source = 0;
	}

	return which_source;
}

/*============================================================================*/
/**
 * fwif_color_video_quality_handler
 * This function is used to set Video Quality function.
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void fwif_color_temptable_handler(unsigned char which_source, unsigned char *temptable)
{
	/*move to uppder stage for speed up.josh@20090326*/
	/*which_source = fwif_vip_source_check(3, NOT_BY_DISPLAY);*/
	if ((which_source == VIP_QUALITY_TV_PAL) || (which_source == VIP_QUALITY_CVBS_PAL)) {
		drvif_color_rtnr_grid_remover_type(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), temptable[0]);/*grid remover  090329 March*/
		fwif_color_set_grid_remove(Scaler_DispGetInputInfo(SLR_INPUT_DATA_ARRAY_IDX), temptable[0]);
	} else {
		drvif_color_rtnr_grid_remover_type(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), 0);
		fwif_color_set_grid_remove(Scaler_DispGetInputInfo(SLR_INPUT_DATA_ARRAY_IDX), 0);
	}

	drvif_color_StillLineCntns(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), temptable[1]); /*conti.Still line*/
	fwif_color_set_conti_still_line(Scaler_DispGetInputInfo(SLR_INPUT_DATA_ARRAY_IDX), temptable[1]);



}

#ifdef RUN_ON_TVBOX
void fwif_color_video_quality_handler(void)/*TVBox Process*/
{
	unsigned char source = 255, input_src_type;
	unsigned char input_display = SLR_MAIN_DISPLAY;

	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	input_display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);/* get display info*/
	input_src_type = Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)input_display);

	unsigned char *pVipCoefArray = NULL;

	if (m_cbFunc_getQualityCoef != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityCoef((VIP_SOURCE_TIMING)source);

	if (!(source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)) {
		Scaler_SetDLti(pVipCoefArray[VIP_QUALITY_FUNCTION_DLTi]);

		Scaler_SetDCti(pVipCoefArray[VIP_QUALITY_FUNCTION_DCTi]);

		Scaler_SetIDLti(pVipCoefArray[VIP_QUALITY_FUNCTION_I_DLTi]);

		Scaler_SetIDCti(pVipCoefArray[VIP_QUALITY_FUNCTION_I_DCTi]);

		Scaler_SetColor_UV_Delay(pVipCoefArray[VIP_QUALITY_FUNCTION_UV_DELAY]);

		Scaler_SetMA_Chroma_Error(pVipCoefArray[VIP_QUALITY_FUNCTION_MA_Chroma_Error]);
	}

	if (source == VIP_QUALITY_CVBS_PAL) {
		Scaler_SetColor_UV_Delay_Enable(1);
		Scaler_SetColor_UV_Delay(33);	/*U_delay =-2, V_delay =-1*/
	}

	if (m_cbFunc_getQualityExtend2 != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend2((VIP_SOURCE_TIMING)source);

	if (!(source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)) {
		Scaler_SetScaleUPH(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_H]);

		Scaler_SetScaleUPV(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_V]);

		Scaler_SetScaleUPH_8tap(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_H_8TAP]);

		Scaler_SetScaleUPV_6tap(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_V_6TAP]);

		Scaler_SetScaleUPDir(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_DIR]);

		Scaler_SetScaleUPDir_Weighting(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_DIR_Weighting]);
	}

}

#else
void fwif_color_video_quality_handler(void)/*TV Process*/
{
	unsigned char ii;/*, jj;*/
	/*unsigned char which_value, pre_value;*/
	unsigned char source = 255;
	static unsigned char pre_source = 255, pre_vpq_project_id = 0xffffffff;
	unsigned char input_display = SLR_MAIN_DISPLAY;
	unsigned char *pVipCoefArray = NULL;
	SLR_VIP_TABLE *gVIP_Table;
	unsigned char *drvSkip_Array;
	unsigned char black_levle = 0;
	unsigned char mCon, mBri, mHue, mSat;
	unsigned char  input_info = 0;
	unsigned char InvGamma_TBL_Sel;
	unsigned short *invGammaTBL;

	/*int ret;*/
	/*unsigned char spatial_y = 0, spatial_c = 0, temporal = 0, rtnr_level_y = 0, rtnr_level_c = 0, s_dnr_level = 0;*/

	/*Elsie 20130509: for speeding up*/
	unsigned short DataArrayIdxInfo;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;

	VIPprintf("+VIP color handler+\n");
	/*force background check*/
	ppoverlay_main_display_control_rsv_RBUS ppoverlay_main_display_control_rsv;
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	ppoverlay_main_display_control_rsv.regValue= IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	if (ppoverlay_main_display_control_rsv.m_force_bg == 0) /*normal mode*/
		VIPprintf("[Warnning] [%s-%s-%d] Start, Not Black Screen", __FILE__, __func__, __LINE__);
	VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL || VIP_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL!(%d,%d) \n",__FILE__, __LINE__,VIP_system_info_structure_table,VIP_RPC_system_info_structure_table);
		return;
	}

	VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_display_check] = 1;

	input_display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);/* get display info*/
	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	DataArrayIdxInfo = Scaler_DispGetInputInfo(SLR_INPUT_DATA_ARRAY_IDX);/*get input src info by channel*/

	//20160218 roger ramrk, it make some init problem
	#if 0
	if( (VIP_system_info_structure_table->Input_src_Type) == _SRC_TV) {
		/*src check, if pre src == current src, return.*/
		if( source == m_nowSource ) {
			return;
		}
	}
	#endif
	m_nowSource = source;

	Scaler_VIP_IP_init(source);/*some vip ip init*/
#ifndef CONFIG_MEMC_BYPASS
	//Scaler_VIP_MEMC_init(source);/*vip MEMC ip init*/
#endif


	Scaler_VIP_Project_ID_init();/*for project ID init, for video fw customization used !!*/

	gVIP_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVIP_Table == NULL)
		return;

#ifdef ENABLE_VIP_TABLE_CHECKSUM
/* === checksum ========== */
	Scaler_checkVIPTable();
/*==========================*/
#endif

	drvSkip_Array = &(gVIP_Table->DrvSetting_Skip_Flag[0]);

/*o------ VIP table : VIP_QUALITY_Coef ------o*/
	/* Load pVipCoefArray*/
	if (m_cbFunc_getQualityCoef != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityCoef((VIP_SOURCE_TIMING)source);
	else
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ table m_cbFunc_getQualityCoef read fail !!!\n");

	rtd_printk(KERN_INFO, TAG_NAME, "VIP SRC=%d\n", source);

	for (ii = 0; ii < VIP_QUALITY_Coef_MAX; ii++) {
		/*VIPprintf("pVipCoefArray[%d] = %d\n", ii, pVipCoefArray[ii]);*/
	}

	if (source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL) {
		VIPprintf("break out--Diane");
	} else {
		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000)
			Scaler_SetDLti(pVipCoefArray[VIP_QUALITY_FUNCTION_DLTi]);
		else
			fwif_color_set_dLti_tv006(pVipCoefArray[VIP_QUALITY_FUNCTION_DLTi], NULL,NULL);

		Scaler_SetIDLti(pVipCoefArray[VIP_QUALITY_FUNCTION_I_DLTi]);

		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000) {
			Scaler_SetDCti(pVipCoefArray[VIP_QUALITY_FUNCTION_DCTi]);
			Scaler_SetIDCti(pVipCoefArray[VIP_QUALITY_FUNCTION_I_DCTi]);
		} else {
			fwif_color_set_iDcti_dDcti_tv006(pVipCoefArray[VIP_QUALITY_FUNCTION_I_DCTi], pVipCoefArray[VIP_QUALITY_FUNCTION_DCTi], NULL);
		}

		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000)
			Scaler_SetVDCti(pVipCoefArray[VIP_QUALITY_FUNCTION_V_DCTi]);
		else
			fwif_color_set_Vdcti_tv006(pVipCoefArray[VIP_QUALITY_FUNCTION_V_DCTi], NULL);

		Scaler_SetColor_UV_Delay_Enable((VIP_UV_DELAY_ENABLE)pVipCoefArray[VIP_QUALITY_FUNCTION_UV_DELAY_ENABLE]);

		Scaler_SetColor_UV_Delay(pVipCoefArray[VIP_QUALITY_FUNCTION_UV_DELAY]);

		if((pre_source != source)||(pre_vpq_project_id!=vpq_project_id)) {	/*rock_rau 20150923 source is same not need change YUV2RGB table*/
			if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000)
				Scaler_set_YUV2RGB(pVipCoefArray[VIP_QUALITY_FUNCTION_YUV2RGB], drvSkip_Array[DrvSetting_Skip_Flag_coefByY], drvSkip_Array[DrvSetting_Skip_Flag_uvOffset]);
			else
				fwif_color_set_YUV2RGB_tv006(0, 0, pVipCoefArray[VIP_QUALITY_FUNCTION_YUV2RGB], drvSkip_Array[DrvSetting_Skip_Flag_coefByY], drvSkip_Array[DrvSetting_Skip_Flag_uvOffset]);
		}

		Scaler_SetFilm_Mode(pVipCoefArray[VIP_QUALITY_FUNCTION_Film]);

		Scaler_SetIntra(pVipCoefArray[VIP_QUALITY_FUNCTION_Intra]);

		Scaler_SetMADI(pVipCoefArray[VIP_QUALITY_FUNCTION_MA]);

		Scaler_SetTNRXC(pVipCoefArray[VIP_QUALITY_FUNCTION_tnr_xc]);

		Scaler_SetMA_Chroma_Error(pVipCoefArray[VIP_QUALITY_FUNCTION_MA_Chroma_Error]);

		Scaler_SetMADI_HME(pVipCoefArray[VIP_QUALITY_FUNCTION_MADI_HME]);

		Scaler_SetMADI_HMC(pVipCoefArray[VIP_QUALITY_FUNCTION_MADI_HMC]);

		Scaler_SetMADI_PAN(pVipCoefArray[VIP_QUALITY_FUNCTION_MADI_PAN]);

		Scaler_SetRTNR_Noise_Measure(pVipCoefArray[VIP_QUALITY_FUNCTION_RTNR_NM]);

		Scaler_SetDiSmd(pVipCoefArray[VIP_QUALITY_FUNCTION_DI_SMD_Level]);

		Scaler_SetNew_UVC(pVipCoefArray[VIP_QUALITY_FUNCTION_COLOR_NEW_UVC]);		/*	add from Mag2 by chris*/

		// Moved to yc_separation_table.c
		//Scaler_SetColor_UV_Delay_TOP(pVipCoefArray[VIP_QUALITY_FUNCTION_UV_DELAY_TOP]);

		Scaler_SetVDCti_LPF(pVipCoefArray[VIP_QUALITY_FUNCTION_V_DCTi_LPF]);

	}
/*o------ VIP table : VIP_QUALITY_Extend_Coef ------o*/
	if (m_cbFunc_getQualityExtend != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend((VIP_SOURCE_TIMING)source);
	else
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ table m_cbFunc_getQualityExtend read fail !!!\n");

	for (ii = 0; ii < VIP_QUALITY_Extend_Coef_MAX; ii++) {
		/*VIPprintf("pVipCoefArray1[%d] = %d\n", ii, pVipCoefArray[ii]);*/
	}

	if (!(source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)) {
		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000)
			Scaler_SetCDSTable(pVipCoefArray[VIP_QUALITY_FUNCTION_CDS_Table]); /*planck 20101103.*/
		else
			fwif_color_set_cds_table_tv006(pVipCoefArray[VIP_QUALITY_FUNCTION_CDS_Table]);

		Scaler_SetEMF_Mk2(pVipCoefArray[VIP_QUALITY_FUNCTION_EMFMk2]);

		Scaler_SetSKIPIR_Ring(pVipCoefArray[VIP_QUALITY_FUNCTION_SKIPIR_Dering]);

		Scaler_SetSKIPIR_Dnoise(pVipCoefArray[VIP_QUALITY_FUNCTION_SKIPIR_dnoise]);

		Scaler_SetskipirdnoiseTable(pVipCoefArray[VIP_QUALITY_FUNCTION_SKIPIR_dnoise_table]);

		Scaler_set_Adaptive_Gamma(pVipCoefArray[VIP_QUALITY_FUNCTION_ADAPTIVE_GAMMA]);

		#ifdef LocalDimming
		Scaler_SetLocalDimmingTable(pVipCoefArray[VIP_QUALITY_FUNCTION_LD_Table]);

		Scaler_SetLocalDimmingEnable(pVipCoefArray[VIP_QUALITY_FUNCTION_LD_Enable]);
		#endif

		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000){
		Scaler_SetLocalContrastTable(pVipCoefArray[VIP_QUALITY_FUNCTION_LC_Table]);

		#ifndef CONFIG_CUSTOMER_TV030 // OSD MENU->fpp->rhal flow had set LC enable status.
		Scaler_SetLocalContrastEnable(pVipCoefArray[VIP_QUALITY_FUNCTION_LC_Enable]);
		#endif
		}
		else{
			fwif_color_set_LocalContrast_table_TV006(&glc_param);

		};

		/*de-xc need a few frame for memory stable after enable, enable control @ scalerMemory*/
		/*Scaler_Set_I_De_XC(pVipCoefArray[VIP_QUALITY_FUNCTION_I_De_XC]);*/
		/*dirty solution, scaler flow don't go "drv_memory_set_ip_fifo_Mer2" while PC Mode, turn off de-xc in PC mode*/
		if ((source == VIP_QUALITY_VGA) || ((Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP) == 0) && (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_RTNR) == 0)))
			Scaler_Set_I_De_XC(pVipCoefArray[VIP_QUALITY_FUNCTION_I_De_XC]);

		// I-decontour not implemented in Mac5p, 20161219 jimmy
		//Scaler_Set_I_De_Contour(pVipCoefArray[VIP_QUALITY_FUNCTION_I_De_Contour]);

#ifdef MAC5_NO_SLD /*SLD, hack, elieli*/
		Scaler_Set_SLD(pVipCoefArray[VIP_QUALITY_FUNCTION_SLD]);
#endif
		#ifndef CONFIG_CUSTOMER_TV030
		//printk("yuan,NOT Scaler_color_colorwrite_Output_InvOutput_gamma\n");
		Scaler_color_colorwrite_Output_InvOutput_gamma(pVipCoefArray[VIP_QUALITY_FUNCTION_Output_InvOutput_GAMMA]);		
		
		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000)
			Scaler_Set3dLUT(pVipCoefArray[VIP_QUALITY_FUNCTION_3dLUT_Table]);
		#endif
	}

/*o------ VIP table : VIP_QUALITY_Extend2_Coef ------o*/
	if (m_cbFunc_getQualityExtend2 != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend2((VIP_SOURCE_TIMING)source);
	else
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ table m_cbFunc_getQualityExtend2 read fail !!!\n");

	for (ii = 0; ii < VIP_QUALITY_Extend2_Coef_MAX; ii++) {
		/*VIPprintf("pVipCoefArray2[%d] = %d\n", ii, pVipCoefArray[ii]);*/
	}

	if (!(source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)) {
		#if 1	//20151001 jyyang, for LGE 4-tab UZU filter select
		Scaler_SetScaleUP_YCHV(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_H],
								pVipCoefArray[VIP_QUALITY_FUNCTION_SU_V],
								pVipCoefArray[VIP_QUALITY_FUNCTION_SU_C_H],
								pVipCoefArray[VIP_QUALITY_FUNCTION_SU_C_V]);

		#else
		Scaler_SetScaleUPH(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_H]);

		Scaler_SetScaleUPV(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_V]);
		#endif

		Scaler_SetScalePK(pVipCoefArray[VIP_QUALITY_FUNCTION_S_PK]);

		Scaler_SetSUPKType(pVipCoefArray[VIP_QUALITY_FUNCTION_SUPK_MASK]);

		Scaler_SetUnsharpMask(pVipCoefArray[VIP_QUALITY_FUNCTION_UNSHARP_MASK]);


		Scaler_setdESM(pVipCoefArray[VIP_QUALITY_FUNCTION_EGSM_Postshp_Table]);

		Scaler_setiESM(pVipCoefArray[VIP_QUALITY_FUNCTION_iESM_table]);

		#ifdef ENABLE_SUPER_RESOLUTION
		//Scaler_set_SuperResolution_init_table(pVipCoefArray[VIP_QUALITY_FUNCTION_SuperResolution_init_table]);
		//SR_edge_gain = pVipCoefArray[VIP_QUALITY_FUNCTION_SuperResolution_edge_gain];
		Scaler_SetSR_edge_gain(pVipCoefArray[VIP_QUALITY_FUNCTION_SuperResolution_edge_gain]);
		//SR_texture_gain = pVipCoefArray[VIP_QUALITY_FUNCTION_SNR_SuperResolution_texture_gain];
		Scaler_SetSR_texture_gain(pVipCoefArray[VIP_QUALITY_FUNCTION_SNR_SuperResolution_texture_gain]);
		#endif

		Scaler_SetScaleDOWNHTable(pVipCoefArray[VIP_QUALITY_FUNCTION_SD_H_Table]);

		Scaler_SetScaleDOWNVTable(pVipCoefArray[VIP_QUALITY_FUNCTION_SD_V_Table]);

		Scaler_SetScaleDOWN444To422(pVipCoefArray[VIP_QUALITY_FUNCTION_SD_444To422]);

		Scaler_SetScaleUPH_8tap(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_H_8TAP]);

		Scaler_SetScaleUPV_6tap(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_V_6TAP]);

		Scaler_SetScaleOSD_Sharpness(pVipCoefArray[VIP_QUALITY_FUNCTION_OSD_SHP]);

		Scaler_SetScaleUPDir(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_DIR]);

		Scaler_SetScaleUPDir_Weighting(pVipCoefArray[VIP_QUALITY_FUNCTION_SU_DIR_Weighting]);
		#if 0 // henry @ mac5 161221
		Scaler_SetScaleUP_TwoStep(pVipCoefArray[VIP_QUALITY_FUNCTION_TwoStep_SU_Table]);
		#endif
	}

/*o------ VIP table : VIP_QUALITY_Extend3_Coef ------o*/
	if (m_cbFunc_getQualityExtend3 != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)source);
	else
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ table m_cbFunc_getQualityExtend3 read fail !!!\n");

	for (ii = 0; ii < VIP_QUALITY_Extend3_Coef_MAX; ii++) {
		/*VIPprintf("pVipCoefArray3[%d] = %d\n", ii, pVipCoefArray[ii]);*/
	}

	if (!(source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)) {

		if(fwif_color_get_NR_Input_tv006()!= 12) //12 is webcam. it is from hal for web cam special case.
		{
		scaler_set_PQA_table(pVipCoefArray[VIP_QUALITY_FUNCTION_PQA_Table]);
		scaler_set_PQA_Input_table(pVipCoefArray[VIP_QUALITY_FUNCTION_PQA_Input_Table]);
		}
		else
		{
			scaler_set_PQA_table(9);
			scaler_set_PQA_Input_table(9);
		}


		if (vdc_power_status)
		{
			if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000) {

				fwif_color_module_vdc_SetConBriHueSat(0, pVipCoefArray[VIP_QUALITY_FUNCTION_VD_ConBriHueSat_Table]);
			} else {
				//Scaler_module_vdc_SetConBriHueSat_Table(pVipCoefArray[VIP_QUALITY_FUNCTION_VD_ConBriHueSat_Table]);
				_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

				black_levle =fwif_color_get_rgb2yuv_black_level_tv006();
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "\n wwwwwwwwwww =%d \n",VIP_system_info_structure_table->Input_src_Type);*/

				if (VIP_system_info_structure_table->Input_src_Type == _SRC_TV )
				{
					input_info = 0; //HAL_VPQ_INPUT_ATV
				}
				else if (VIP_system_info_structure_table->Input_src_Type == _SRC_CVBS )
				{
					input_info = 1; //HAL_VPQ_INPUT_AV;

				}

				//20161111 roger, when sub record, don't change VD con/bri
				if (get_sub_OutputVencMode() == 0)
				{
					if (fwif_color_get_VDBlackLevel_MappingValue(input_info, black_levle-1, &mCon, &mBri, &mHue, &mSat) == 0){
							/*rtd_printk(KERN_DEBUG, TAG_NAME, "\n mCon=%d mBri=%d mHue=%d mSat=%d \n",mCon,mBri,mHue,mSat);*/
							fwif_color_set_VDBlackLevel(mCon, mBri, mHue, mSat);
						}
				}
			}
		}

		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000) { /*pre_id:16 main_id:8 sub1_id:8 sub2_id:8, example->lg=tv006*/

			#ifndef  CONFIG_CUSTOMER_TV030//tcl control gama by themselves nor icm
			Scaler_set_ICM_table(pVipCoefArray[VIP_QUALITY_FUNCTION_ICM],  drvSkip_Array[DrvSetting_Skip_Flag_ICM]);
			if (g_tv002_demo_fun_flag) {
				extern unsigned char g_GammaMode;
				g_GammaMode = pVipCoefArray[VIP_QUALITY_FUNCTION_Gamma];
				fwif_color_set_gamma_from_MagicGamma_MiddleWare();
			} else {
				Scaler_SetGamma_for_Handler(pVipCoefArray[VIP_QUALITY_FUNCTION_Gamma],
												pVipCoefArray[VIP_QUALITY_FUNCTION_S_Gamma_Index],
												pVipCoefArray[VIP_QUALITY_FUNCTION_S_Gamma_Low],
												pVipCoefArray[VIP_QUALITY_FUNCTION_S_Gamma_High], drvSkip_Array[DrvSetting_Skip_Flag_Gamma]);
			}
			#endif

			if((picturemode==PQ_MODE_SHOP_DEMO)&&(VIP_system_info_structure_table->HDR_flag==0)){
				printk("tim_li,qua handler picmode is SHOP!! \n");
				Scaler_SetDCC_Table(5);
				Scaler_Set_DCC_Color_Independent_Table(4);
			}else{
				Scaler_SetDCC_Table(pVipCoefArray[VIP_QUALITY_FUNCTION_DCC_Table_Select]);
				Scaler_Set_DCC_Color_Independent_Table(pVipCoefArray[VIP_QUALITY_FUNCTION_DCC_Skin_Tone_Table_Select]);
			}
			Scaler_Set_DCC_chroma_compensation_Table(pVipCoefArray[VIP_QUALITY_FUNCTION_DCC_Chroma_comp_t_sel]);
		}

		Scaler_SetSharpnessTable(pVipCoefArray[VIP_QUALITY_FUNCTION_SharpTable]);

		if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000) {
			Scaler_SetMBPeaking(pVipCoefArray[VIP_QUALITY_FUNCTION_MB_Peaking]);
			Scaler_set_blue_stretch(pVipCoefArray[VIP_QUALITY_FUNCTION_blue_stretch]);
		} else
			fwif_color_set_MultiBand_Peaking_tv006(pVipCoefArray[VIP_QUALITY_FUNCTION_MB_Peaking], NULL, NULL);

	}

	fwif_color_PQ_ByPass_Handler(0, 1, VIP_RPC_system_info_structure_table, 0);

	fwif_color_set_quality_init_sendRPC();
	scalerVIP_quality_init(&quality_init_value[0]);

	fwif_color_Set_MNR_Enable_Check_tv006();/*snr hw issue, can't get porch while hal function calling, elieli*/

	if (VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] == 1)
		drvif_HDMI_Dither_Enable(1);
	else
		drvif_HDMI_Dither_Enable(0);


	drvif_color_Setditherbit(VIP_PANEL_BIT8);
	drvif_color_setdithering();
	/*fwif_color_video_quality_handler_customization();*/

	/* 3d mode young 3dtable ================*/
	if (drvif_scaelr3d_decide_is_3D_display_mode() == 1) {/*3*/
		/*fwif_color_video_3Dmode_quality_handler();*/
	}

#if 0	//20160926 roger, KTASKWBS-5252 root cause
	// patch for YCbCr color issue in hi-freq. area
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if (input_display == SLR_MAIN_DISPLAY && Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC)
		IoReg_SetBits(H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg, H3DDMA_HSD_I3DDMA_VSD_Ctrl1_lp121_en_mask);
	else
		IoReg_ClearBits(H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg, H3DDMA_HSD_I3DDMA_VSD_Ctrl1_lp121_en_mask);
#endif
	// ============= patch end ====================
#endif

#ifdef CONFIG_CUSTOMER_TV030
/*===========HDR===============*/
//printk("yuan,ColorSpaceMode=%d\n",ColorSpaceMode);
//printk("yuan,HDR_flag=%d\n",VIP_system_info_structure_table ->HDR_flag);

if(ColorSpaceMode==0){//Color Space Mode=Auto
	drvif_color_D_3dLUT_Enable(0);
	fwif_color_set_sRGBMatrix();
}
else if(ColorSpaceMode==1){//Color Space Mode=Native
	drvif_color_D_3dLUT_Enable(0);
	IoReg_ClearBits(0xb802c000,_BIT0);//disable sRGB
}
else if(ColorSpaceMode==2){//Color Space Mode=Custom
	Scaler_Set_ColorSpace_D_3dlutTBL(&ColoSpace_Index);
	drvif_color_D_3dLUT_Enable(1);
	fwif_color_set_sRGBMatrix();
}

if(VIP_system_info_structure_table ->HDR_flag){
 	fwif_color_set_sRGBMatrix();	
	drvif_color_D_3dLUT_Enable(0);
	//GammaBlendOETF=0;
}
	fwif_color_set_gamma_Magic();

	printk("yuan,qua end===\n");
#endif

#ifdef RTK_PQ_demo_mode		//for demo
	static struct file *demo_file = NULL;
	if(PQ_demo_mode == 0){
		demo_file = (file_open("/tmp/usb/sda/sda1/PQdemo.txt", O_RDWR, 0600));
		if (demo_file != NULL){
			PQ_demo_mode = 1;
			file_close(demo_file);
			demo_file = NULL;
		}
	}

	if((PQ_demo_mode) && (pre_source != source)){
		if(source>=VIP_QUALITY_HDR_HDMI_1080p && source<=VIP_QUALITY_DolbyHDR_PVR_4k2kP){			//HDR use LGE setting
			unsigned char buf[1] = {0};
			(fwif_color_get_demo_callback(DEMO_CALLBACKID_ON_OFF_SWITCH))((void *)buf);
		}else{
			unsigned char buf[1] = {1};
			(fwif_color_get_demo_callback(DEMO_CALLBACKID_ON_OFF_SWITCH))((void *)buf);
		}
	}
#endif

	pre_source = source;
	pre_vpq_project_id = vpq_project_id;
	/*force background check*/
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	ppoverlay_main_display_control_rsv.regValue= IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	if (ppoverlay_main_display_control_rsv.m_force_bg == 0) /*normal mode*/
		VIPprintf("[Warnning] [%s-%s-%d] End, Not Black Screen", __FILE__, __func__, __LINE__);

	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY) {
		if(Scaler_DispGetInputInfo(SLR_INPUT_DI_WID) > 1920){
			IoReg_SetBits(DI_IM_DI_RTNR_NEW_CONTROL_reg, _BIT19);	//4K2K support
		}else{
			IoReg_ClearBits(DI_IM_DI_RTNR_NEW_CONTROL_reg, _BIT19);
		}
	}

}

#endif /*ifdef ENABLE_RUN_ON_TVBOX*/

void Scaler_VIP_IP_3DFlow_init(unsigned char Vip_source)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	drvif_color_dcc_Curve_init(display);
}


void fwif_color_video_3Dmode_quality_handler(void)
{
	/*unsigned char ii;*/
	/*unsigned char which_value, pre_value;*/
	/*unsigned char temptable[5] = {7, 1, 1, 1, 1};*/
	unsigned char source = 255;
	unsigned char input_display;
	unsigned char *pVipCoefArray = NULL;
	/*int ret;*/
	/*unsigned char spatial_y = 0, spatial_c = 0, temporal = 0, rtnr_level_y = 0, rtnr_level_c = 0, s_dnr_level = 0;*/

	SLR_VIP_TABLE *gVIP_Table;
	unsigned char *drvSkip_Array;

	input_display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	source = fwif_vip_3Dsource_check(3, NOT_BY_DISPLAY);

	gVIP_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVIP_Table == NULL)
		return;
	drvSkip_Array = &(gVIP_Table->DrvSetting_Skip_Flag[0]);

	VIPprintf("====[Young]3D source = %d ====\n", source);

	if (m_cbFunc_getQuality3Dmode == NULL)
		return;
	pVipCoefArray = (unsigned char *)m_cbFunc_getQuality3Dmode((VIP_3DSOURCE_TIMING)source);

	if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000) {
		Scaler_SetSindex(pVipCoefArray[VIP_QUALITY_3DFUNCTION_S_Gamma_Index]);

		Scaler_SetSlow(pVipCoefArray[VIP_QUALITY_3DFUNCTION_S_Gamma_High]);

		Scaler_SetShigh(pVipCoefArray[VIP_QUALITY_3DFUNCTION_S_Gamma_Low]);
	}

	Scaler_SetScalePK(pVipCoefArray[VIP_QUALITY_3DFUNCTION_S_PK]);

	Scaler_SetSUPKType(pVipCoefArray[VIP_QUALITY_3DFUNCTION_SUPK_MASK]);

	Scaler_SetUnsharpMask(pVipCoefArray[VIP_QUALITY_3DFUNCTION_UNSHARP_MASK]);

	if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000) {
		Scaler_SetSharpnessTable(pVipCoefArray[VIP_QUALITY_3DFUNCTION_Sharpness_table]);

		Scaler_SetDCC_Table(pVipCoefArray[VIP_QUALITY_3DFUNCTION_DCC_Table_Select]);

		/*VIPprintf("In 3D mode!Use 3D_ICM\n");*/
		Scaler_set_ICM_table(pVipCoefArray[VIP_QUALITY_3DFUNCTION_ICM], drvSkip_Array[DrvSetting_Skip_Flag_ICM]);
	}
	fwif_color_set_iESM(Scaler_DispGetInputInfo(SLR_INPUT_DATA_ARRAY_IDX), pVipCoefArray[VIP_QUALITY_3DFUNCTION_iESM_table]);

	/*USER:LewisLee DATE:2010/11/11*/
	/*In MediaBrowser mode, not execute Edge Smooth mode*/
	/*to prevent OSD jitter*/
	if ((_SRC_VO == Scaler_InputSrcGetMainChType()) && (SLR_RATIO_CUSTOM == Scaler_DispGetRatioMode2())) {
		/*VIPprintf("Media Previrw mode, not execute EGEM!\n");*/
	} else {
		/*========= planck add for TV AutoNR ===========*/
		if ((Scaler_SendRPC(SCALERIOC_GET_TABLE_SHP1D2D_EGSM, pVipCoefArray[VIP_QUALITY_3DFUNCTION_SHP1D2D_EGSM], RPC_SEND_VALUE_ONLY)) < 0) {
			/*rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, update TableNR_RTNR_C to driver fail !!!\n", ret);*/
		}

	}
}

void *fwif_color_get_picture_mode_data(unsigned char src_idx, unsigned char value)
{
	if (m_cbFunc_getPictureModeData == NULL)
		return NULL;

	/*VIPprintf("fwif_color_get_picture_mode_data, src_idx = %d, value = %d, Scaler_InputSrcFormat(src_idx) = %d\n", src_idx, value, Scaler_InputSrcFormat(src_idx));*/
	return m_cbFunc_getPictureModeData(Scaler_InputSrcFormat(src_idx), 0, value);
}

void *fwif_color_get_cur_picture_mode_data(unsigned char src_idx)
{
	/* Get current active picture mode level by setting param to 0xFF.*/
	SLR_PICTURE_MODE_DATA *pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_picture_mode_data(src_idx, 0xFF);
	return pData;
}


unsigned char fwif_color_get_backlight(unsigned char src_idx)
{
	/*StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);*/
	SLR_PICTURE_MODE_DATA *pTable = (SLR_PICTURE_MODE_DATA *)fwif_color_get_picture_mode_data(src_idx, 0xff);
	if (pTable == NULL)
		return 0;

	return pTable->BackLight;
}

/*peggy: set value => must be user picmode*/
void fwif_color_set_backlight(unsigned char src_idx, unsigned char value)
{
		/*StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);*/
#if (!defined(PICTURE_MODE_USER)) || ((defined BUILD_TV005_1_ATV) || (defined BUILD_TV005_1_ATSC) || (defined(BUILD_TV057_1_ATV) && defined(IS_TV05_STYLE_PICTUREMODE)))
		SLR_PICTURE_MODE_DATA *pTable = (SLR_PICTURE_MODE_DATA *)fwif_color_get_picture_mode_data(src_idx, 0xff);
#else
		SLR_PICTURE_MODE_DATA *pTable = (SLR_PICTURE_MODE_DATA *)fwif_color_get_picture_mode_data(src_idx, (unsigned char)PICTURE_MODE_USER);
#endif

	if (pTable == NULL)
		return;
	pTable->BackLight = value;
	Scaler_SetOSDBacklight2VIP(value);

}

void fwif_color_set_backlight_TPV(unsigned char src_idx, unsigned char value)
{
	/*StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);*/
#if (!defined(PICTURE_MODE_USER))
	SLR_PICTURE_MODE_DATA *pTable = (SLR_PICTURE_MODE_DATA *)fwif_color_get_picture_mode_data(src_idx, (unsigned char)0xFF);
#else
	SLR_PICTURE_MODE_DATA *pTable = (SLR_PICTURE_MODE_DATA *)fwif_color_get_picture_mode_data(src_idx, (unsigned char)PICTURE_MODE_USER);
#endif
	int ret;
	ret = Scaler_SendRPC(SCALERIOC_DCR_MAX_VALUE, value, RPC_SEND_VALUE_ONLY);
	if (0 != ret) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, set SCALERIOC_DCR_MAX_VALUE  to driver fail !!!\n", ret);
		return;
	}
	if (pTable == NULL)
		return;
	pTable->BackLight = value;
}


unsigned short fwif_color_get_color_temp_r_type_using_colortmp(unsigned char colortmp)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return 0;
	return pTable->R_val;
}

void fwif_color_set_color_temp_r_type_using_colortmp(unsigned char colortmp, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return;
	pTable->R_val = value;
}

unsigned short fwif_color_get_color_temp_g_type_using_colortmp(unsigned char colortmp)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return 0;
	return pTable->G_val;
}

void fwif_color_set_color_temp_g_type_using_colortmp(unsigned char colortmp, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return;
	pTable->G_val = value;
}

unsigned short fwif_color_get_color_temp_b_type_using_colortmp(unsigned char colortmp)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return 0;
	return pTable->B_val;
}

void fwif_color_set_color_temp_b_type_using_colortmp(unsigned char colortmp, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return;
	pTable->B_val = value;
}

unsigned short fwif_color_get_color_temp_r_offset_using_colortmp(unsigned char colortmp)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return 0;
	return pTable->R_offset_val;
}

void fwif_color_set_color_temp_r_offset_using_colortmp(unsigned char colortmp, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return;
	pTable->R_offset_val = value;
}

unsigned short fwif_color_get_color_temp_g_offset_using_colortmp(unsigned char colortmp)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return 0;
	return pTable->G_offset_val;
}

void fwif_color_set_color_temp_g_offset_using_colortmp(unsigned char colortmp, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return;
	pTable->G_offset_val = value;

}

unsigned short fwif_color_get_color_temp_b_offset_using_colortmp(unsigned char colortmp)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return 0;
	return pTable->B_offset_val;
}


void fwif_color_set_color_temp_b_offset_using_colortmp(unsigned char colortmp, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = fwif_color_get_color_tempset_using_colortmp(colortmp);
	if (NULL == pTable)
		return;
	pTable->B_offset_val = value;
}




unsigned char fwif_color_get_picture_mode(unsigned char src_idx)
{
	SLR_PICTURE_MODE_DATA *pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return VIP_COLORSTD_DEFAULT;
	return pData->mode;
}

unsigned char fwif_color_get_vip_debug_mode(unsigned char src_idx)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->VIP_debug_mode;
}

unsigned char Scaler_get_i_dcti()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->I_DCTi;
}

void Scaler_set_i_dcti(unsigned char src_idx, unsigned char value)
{

	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->I_DCTi = value;
}

void fwif_color_set_Vertical_NR_driver(unsigned char src_idx, unsigned char value)
{
	drvif_color_Mixer_ctrl_Vfilter(_MAIN_DISPLAY, value);
}

#ifdef ENABLE_SUPER_RESOLUTION
void fwif_color_set_SR_edge_gain(unsigned char src_idx, unsigned char value)
{

	fwif_color_set_SR_driver(VIP_SR_edge_gain, value);

}

void fwif_color_set_SR_texture_gain(unsigned char src_idx, unsigned char value)
{

	fwif_color_set_SR_driver(VIP_SR_texture_gain, value);

}

void fwif_color_set_SR_driver(unsigned char item_idx, unsigned char value)
{
	switch (item_idx) {
	case VIP_SR_edge_gain:
		drv_SuperResolution_gain(value, SR_texture_gain);
		break;
	case VIP_SR_texture_gain:
		drv_SuperResolution_gain(SR_edge_gain, value);
		break;
	default:
		drv_SuperResolution_gain(SR_edge_gain, SR_texture_gain);
		break;
	}
}
#endif


void fwif_color_set_HMCNR_driver(unsigned char src_idx, unsigned char value)
{
	drvif_color_nr_HMCNR(value);
}


void fwif_color_set_HMCNR_blending_driver(unsigned char src_idx, unsigned char value)
{
	drvif_color_nr_HMCNR_blending(value);
}

#if 0
void fwif_color_set_active_backlight_table(unsigned char src_idx, unsigned char item, unsigned char value)
{

	int ret;
	unsigned char Active_Backlight_info[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	VIPprintf("fwif_color_set_active_backlight_table:::item = %d, value = %d \n", item, value);

	UINT16 Scaler_BlackAPL_a_HSCA = 0;
	UINT16 Scaler_BlackAPL_b_HSCB = 0;
	UINT16 Scaler_BlackAPL_c_HSCC = 0;
	UINT16 Scaler_BlackAPL_d_HSCD = 0;
	UINT16 Scaler_BlackAPL_e_HSCE = 0;
	UINT16 Scaler_BlackAPL_f_HSCF = 0;
	UINT16 Scaler_BlackAPL_g_HSCG = 0;
	UINT16 Scaler_BlackAPL_h_HSCH = 0;

	UINT16 Scaler_BlackAPL_BL_Th1_SABH = 0;
	UINT16 Scaler_BlackAPL_BL_Th1_SABL = 0;
	UINT16 Scaler_BlackAPL_BL_Th2_EABH = 0;
	UINT16 Scaler_BlackAPL_BL_Th2_EABL = 0;
	UINT16 Scaler_BlackAPL_BL_Th3_MLBL = 0;
	UINT16 Scaler_BlackAPL_BL_Th1 = 0;
	UINT16 Scaler_BlackAPL_BL_Th2 = 0;
	UINT16 Scaler_BlackAPL_M_ATAB = 0;
	UINT16 Scaler_BlackAPL_KU_USAB = 0;
	UINT16 Scaler_BlackAPL_KD_DSAB = 0;


	Active_Backlight_info[0] = Scaler_BlackAPL_a_HSCA;
	Active_Backlight_info[1] = Scaler_BlackAPL_b_HSCB;
	Active_Backlight_info[2] = Scaler_BlackAPL_c_HSCC;
	Active_Backlight_info[3] = Scaler_BlackAPL_d_HSCD;
	Active_Backlight_info[4] = Scaler_BlackAPL_e_HSCE;
	Active_Backlight_info[5] = Scaler_BlackAPL_f_HSCF;
	Active_Backlight_info[6] = Scaler_BlackAPL_g_HSCG;
	Active_Backlight_info[7] = Scaler_BlackAPL_h_HSCH;

	Active_Backlight_info[8] = Scaler_BlackAPL_BL_Th1_SABH;
	Active_Backlight_info[9] = Scaler_BlackAPL_BL_Th1_SABL;
	Active_Backlight_info[10] = Scaler_BlackAPL_BL_Th2_EABH;
	Active_Backlight_info[11] = Scaler_BlackAPL_BL_Th2_EABL;
	Active_Backlight_info[12] = Scaler_BlackAPL_BL_Th3_MLBL;
	Active_Backlight_info[13] = Scaler_BlackAPL_M_ATAB;
	Active_Backlight_info[14] = Scaler_BlackAPL_KU_USAB;
	Active_Backlight_info[15] = Scaler_BlackAPL_KD_DSAB;

	Active_Backlight_info[16] = Scaler_APL_BL_MAX;
	Active_Backlight_info[17] = Scaler_APL_BL_MIN;
	if (item <= SLR_APL_BL_MIN) {
		Active_Backlight_info[item] = value;
	}

	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_UPDATE_ACTIVE_BACKLIGHT_TABLE);
	if (pwTemp) {
		/* copy to RPC share memory*/
		memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_UPDATE_ACTIVE_BACKLIGHT_TABLE), &Active_Backlight_info, sizeof(unsigned char)*18);
		if ((Scaler_SendRPC(SCALERIOC_UPDATE_ACTIVE_BACKLIGHT_TABLE, ShareMemAddrDummy, RPC_Send_Addr)) < 0) {
			rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, UPDATE_ACTIVE_BACKLIGHT_TABLE to driver fail !!!\n", ret);
		}
	}
}
#endif
unsigned char fwif_color_get_grid_remove(unsigned char src_idx)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->gridRemove;
}

void fwif_color_set_grid_remove(unsigned char src_idx, unsigned char value)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->gridRemove = value;
}

unsigned char fwif_color_get_conti_still_line(unsigned char src_idx)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ContiStillLine;
}

void fwif_color_set_conti_still_line(unsigned char src_idx, unsigned char value)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ContiStillLine = value;
}

unsigned char fwif_color_reg_callback1(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC1 cbFunc)
{
	if (NULL == cbFunc) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "error : fwif_color_reg_callback1, type = %d cbFunc == NULL\n", type);
		return FALSE;
	}


	switch (type) {
	case COLOR_CALLBACK_GET_QUALITY_COEF:
		m_cbFunc_getQualityCoef = cbFunc;
		break;
	case COLOR_CALLBACK_GET_QUALITY_EXTEND:
		m_cbFunc_getQualityExtend = cbFunc;
		break;
	case COLOR_CALLBACK_GET_QUALITY_EXTEND2:
		m_cbFunc_getQualityExtend2 = cbFunc;
		break;
	case COLOR_CALLBACK_GET_QUALITY_EXTEND3:
		m_cbFunc_getQualityExtend3 = cbFunc;
		break;
	case COLOR_CALLBACK_GET_QUALITY_EXTEND4:
		m_cbFunc_getQualityExtend4 = cbFunc;
		break;

	default:
		return FALSE;
	}

	return TRUE;
}


unsigned char fwif_color_reg_callback2(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC2 cbFunc)
{
	if (NULL == cbFunc) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "error : fwif_color_reg_callback2, type = %d cbFunc == NULL\n", type);
		return FALSE;
	}

	switch (type) {
	case COLOR_CALLBACK_GET_COLOR_DATA:
		m_cbFunc_getColorData = cbFunc;
		break;
	case COLOR_CALLBACK_GET_COLOR_FAC_MODE:
		m_cbFunc_getColorFacMode = cbFunc;
		break;
	case COLOR_CALLBACK_GET_COLOR_TEMP_DATA:
		m_cbFunc_getColorTempData = cbFunc;
		break;
	case COLOR_CALLBACK_GET_COLOR_TEMP_DATA_TSB:
		m_cbFunc_getColorTempData_TSB = cbFunc;
		break;
	case COLOR_CALLBACK_GET_COLOR_TEMP_LEVEL:
		m_cbFunc_getColorTempLevel = cbFunc;
		break;
	case COLOR_CALLBACK_GET_PICTURE_MODE_DATA:
		m_cbFunc_getPictureModeData = cbFunc;
		break;
	case COLOR_CALLBACK_GET_DNR_MODE:
		m_cbFunc_getDnrMode = cbFunc;
		break;

	default:
		return FALSE;
	}

	return TRUE;
}

unsigned char fwif_color_reg_callback3(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC3 cbFunc)
{
	if (NULL == cbFunc) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "error : fwif_color_reg_callback3, type = %d cbFunc == NULL\n", type);
		return FALSE;
	}

	switch (type) {
	case COLOR_CALLBACK_GET_CURPICMODE:
		m_cbFunc_getCurPicMode = cbFunc;
		break;
	default:
		return FALSE;
	}

	return TRUE;
}

/*Elsie 20131224*/
unsigned char fwif_color_reg_callback4(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC4 cbFunc)
{
	if (NULL == cbFunc) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "error : fwif_color_reg_callback4, type = %d cbFunc == NULL\n", type);
		return FALSE;
	}

	switch (type) {
	case COLOR_CALLBACK_GET_ICM_BY_TIMING_PICMODE:
		m_cbFunc_getIcmByTimingPicmode = cbFunc;
		break;
	default:
		return FALSE;
	}

	return TRUE;
}

/*young 3Dtable*/
unsigned char fwif_color_reg_callback5(COLOR_CALLBACK_TYPE type, COLOR_CALLBACK_FUNC5 cbFunc)
{
	if (NULL == cbFunc) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "error : fwif_color_reg_callback5, type = %d cbFunc == NULL\n", type);
		return FALSE;
	}

	switch (type) {

	case COLOR_CALLBACK_GET_QUALITY_3Dmode:
		m_cbFunc_getQuality3Dmode = cbFunc;
		break;

	default:
		return FALSE;
	}

	return TRUE;
}

#if 0
char fwif_color_isUSBSource()
{
	if (m_cbFunc_getCurVipSource != NULL) {
		if (m_cbFunc_getCurVipSource() == VIP_SRC_VO_USB)
			return TRUE;
	}
	return FALSE;
}
#endif

unsigned char fwif_color_get_spread_spectrum(unsigned char src_idx)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Spread_Spectrum;
}

void fwif_color_set_spread_spectrum(unsigned char src_idx, unsigned char value)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Spread_Spectrum = value;
}

void fwif_color_set_vip_debug_mode(unsigned char src_idx, unsigned char value)
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->VIP_debug_mode = value;
}



void fwif_set_ColorMatrix(bool colormartixonoff)
{
	bool mode = 0;
	unsigned short channel;
	SCALER_DISP_CHANNEL display;
	display = (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	channel = Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL);

	if (colormartixonoff == 1)
		mode = 1;
	/*VIPprintf("[Young]fwif_set_ColorMatrix colormartixonoff = %d\n", colormartixonoff);*/
	fwif_color_colorspacergb2yuvtransfer(channel, Scaler_InputSrcGetType(display), mode , 0, 1);
}

#if 1
#ifdef OPEN_CELL_PANEL

void drvif_ODEnable()
{
	if (!Get_OD_ENABEL())
		return;

	if (p_ODTABLE != NULL)
		return;

	Scaler_Set_Open_Cell_Panel_UseOD(true);

/*    if (ODtable_Coeff!= NULL)*/
/*	drvif_ODTable((unsigned int *)ODtable_Coeff);*/
}


/*Elsie 20130823: Other functions of drvif_ODTable() are moved into drvif_color_od_init()(at gibi_od.cpp)*/
unsigned int drvif_ODTable(unsigned int *ptr)   /*young vippanel*/
{
	if (!ptr)
		return FALSE;
	ODtable_Coeff = ptr;
	drvif_color_od(Get_OD_ENABEL());

	return TRUE;
}

#endif	/*#ifdef OPEN_CELL_PANEL*/


#ifdef OPEN_CELL_PANEL
unsigned int drvif_OD_disable(void)   /*young vippanel*/
{
	if (!Get_OD_ENABEL())
		return false;

	if (p_ODTABLE == NULL)
		return false;


	Scaler_Set_Open_Cell_Panel_UseOD(false);

	/* OD disable*/
	IoReg_ClearBits(OD_OD_CTRL1_reg, _BIT29);
	IoReg_SetBits(OD_OD_CTRL1_reg, _BIT30);
	IoReg_ClearBits(OD_OD_CTRL1_reg, _BIT19);

	/* Disable Capture*/
	IoReg_ClearBits(OD_ODDMA_CAP_CTL0_VADDR, _BIT24);
	/* Disable Display*/
	IoReg_ClearBits(OD_ODDMA_DISPLAY_CTRL_VADDR, _BIT8);

	pli_freeContinuousMemoryMesg("OD_TABLE", p_ODTABLE);
	p_ODTABLE = NULL;
	/*pli_listAllMemory();*/

}
#endif
#else
unsigned int drvif_ODTable(void)   /*young vippanel, Elsie 20130930*/
{
	drvif_color_od(Get_OD_ENABEL());
	return TRUE;
}
#endif

void fwif_ByPass_IDomainToMem(void)
{
/*-------------------------------------------------------------------*/
/*--------------------By pass I_domain--------------------------------*/
/*-------------------------------------------------------------------*/

IoReg_Write32(0xb8023028, 0x00000000);		/*disable 422 to 444*/
IoReg_Write32(0xb8023500, 0x00000000);		/*Disable digital filter ph, psmr, nsmr, pring*/
IoReg_Write32(0xb8023504, 0x00000000);		/*Disable digital filter nring, mis, nos, r , g, b*/
IoReg_Write32(0xb8023000, 0x00000000);		/*disable RGB to YUV conversion*/
IoReg_Write32(0xb8023128, 0x00000000);		/*disable I-Hor_MpegNR*/
IoReg_Write32(0xb8025204, 0x00000300);		/*disable scaling down, set 444 10bit output, bypass*/
IoReg_Write32(0xb8023600, 0x00000000);		/*Disable SD dither*/

IoReg_Write32(0xb8022284, 0x00000000);		/*bypass DI*/
IoReg_Write32(0xb8023170, 0x00000000);		/*Disable IDLTI*/
IoReg_Write32(0xb8023118, 0x00000000);		/*Disable I-small-dcti*/


/*rtd_outl(0xb8024000, 0x00000000);		*/ /*disable di, xc, tnr*/
IoReg_Write32(0xb8022278, 0x0002a300);		/*ADC raw data dump pixel*/

}

int fwif_color_get_cur_picMode()
{
	if (m_cbFunc_getCurPicMode == NULL)
		return 0;

	return m_cbFunc_getCurPicMode();
}

/*=====================================*/
/*=============== NEW RTNR ===============*/
/*=====================================*/
void  Scaler_icm_enhancement(unsigned char value)
{
	unsigned char which_value;
	unsigned char source = 255;
	unsigned char *pVipCoefArray = NULL;


	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);

	if (m_cbFunc_getQualityExtend3 == NULL)
		return;
	pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)source);

	which_value = pVipCoefArray[VIP_QUALITY_FUNCTION_ICM];

	fwif_color_icm_enhancement(SLR_MAIN_DISPLAY, which_value, value);
}
void  Scaler_ChannelColourSet(signed char value)
{
	unsigned char which_value;
	unsigned char source = 255;
	unsigned char *pVipCoefArray = NULL;


	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);

	if (m_cbFunc_getQualityExtend3 == NULL)
		return;
	pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)source);

	which_value = pVipCoefArray[VIP_QUALITY_FUNCTION_ICM];

	fwif_color_ChannelColourSet(SLR_MAIN_DISPLAY, which_value, value);
}


#define GAMMA_R 0
#define GAMMA_G 1
#define GAMMA_B 2




#define GET_PIP_BLENDING() 						Scaler_PipGetInfo(SLR_PIP_BLENDING)
void fwif_color_setrgbcontrast_for_engOSD(UINT8 display, UINT8 RGB, UINT8 Value)
{
	UINT16 Red, Green, Blue;

	Red = Green = Blue = 0;
}


UINT16 COsdCtrlGet_R_Drive_RDRV()
{
	return 0;
}

void COsdCtrlSet_R_Drive_RDRV(UINT16  Message)
{
}
UINT16 COsdCtrlGet_G_Drive_GDRV()
{
	return 0;
}

void COsdCtrlSet_G_Drive_GDRV(UINT16  Message)
{
}

UINT16 COsdCtrlGet_B_Drive_BDRV(void)
{
	return 0;

}

void COsdCtrlSet_B_Drive_BDRV(UINT16  Message)
{
}

INT8 COsdCtrlGet_R_CUTOFF_RCUT(void)
{
	return 0;

}

void COsdCtrlSet_R_CUTOFF_RCUT(UINT16  Message)
{
}

INT8 COsdCtrlGet_G_CUTOFF_GCUT(void)
{
	return 0;

}

void COsdCtrlSet_G_CUTOFF_GCUT(UINT16  Message)
{
}

INT8 COsdCtrlGet_B_CUTOFF_BCUT()
{
	return 0;

}

void COsdCtrlSet_B_CUTOFF_BCUT(UINT16  Message)
{
}

INT8 COsdCtrlGet_R_Drive_Offset_Natural_RDON()
{
	/*drive offset is the diff base on cool*/
	return 0;
}
void COsdCtrlSet_R_Drive_Offset_Natural_RDON(UINT16  Message)
{
	/*set value to storage*/
	/*set value to reg*/
}

INT8 COsdCtrlGet_G_Drive_Offset_Natural_GDON()
{
	/*drive offset is the diff base on cool*/
	return 0;

}

void COsdCtrlSet_G_Drive_Offset_Natural_GDON(UINT16  Message)
{
	/*set value to storage*/
	/*set value to reg*/
}

INT8 COsdCtrlGet_B_Drive_Offset_Natural_BDON()
{
	/*drive offset is the diff base on cool*/
	return 0;
}

void COsdCtrlSet_B_Drive_Offset_Natural_BDON(UINT16  Message)
{
	/*set value to storage*/
	/*set value to reg*/
}

INT8 COsdCtrlGet_R_CUTOFF_Offset_Natural_RCON()
{
	return 0;
}

void COsdCtrlSet_R_CUTOFF_Offset_Natural_RCON(UINT16  Message)
{
}

INT8 COsdCtrlGet_G_CUTOFF_Offset_Natural_GCON()
{
	return 0;
}

void COsdCtrlSet_G_CUTOFF_Offset_Natural_GCON(UINT16  Message)
{
}

INT8 COsdCtrlGet_B_CUTOFF_Offset_Natural_BCON()
{
	/*cutoff offset for natural = cutoff for natural - cutoff for cool*/
	return 0;
}

void COsdCtrlSet_B_CUTOFF_Offset_Natural_BCON(UINT16  Message)
{
	/*set value to storage*/
}

INT8 COsdCtrlGet_R_Drive_Offset_Warm_RDOW()
{
	/*drive offset is the diff base on cool*/
	return 0;
}

void COsdCtrlSet_R_Drive_Offset_Warm_RDOW(UINT16  Message)
{
	/*set value to storage*/
	/*set value to reg*/
}

INT8 COsdCtrlGet_G_Drive_Offset_Warm_GDOW()
{
	/*drive offset is the diff base on cool*/
	return 0;
}

void COsdCtrlSet_G_Drive_Offset_Warm_GDOW(UINT16  Message)
{
	/*set value to storage*/
	/*set value to reg*/
}

INT8 COsdCtrlGet_B_Drive_Offset_Warm_BDOW()
{
	/*drive offset is the diff base on cool*/
	return 0;

}

void COsdCtrlSet_B_Drive_Offset_Warm_BDOW(UINT16  Message)
{
	/*set value to storage*/
	/*set value to reg*/
}

INT8 COsdCtrlGet_R_CUTOFF_Offset_Warm_RCOW()
{
	return 0;
}

void COsdCtrlSet_R_CUTOFF_Offset_Warm_RCOW(UINT16  Message)
{
}

INT8 COsdCtrlGet_G_CUTOFF_Offset_Warm_GCOW()
{
	return 0;
}

void COsdCtrlSet_G_CUTOFF_Offset_Warm_GCOW(UINT16  Message)
{
}

INT8 COsdCtrlGet_B_CUTOFF_Offset_Warm_BCOW()
{
	return 0;
}

void COsdCtrlSet_B_CUTOFF_Offset_Warm_BCOW(UINT16  Message)
{
}



UINT8 fwif_vip_Get_Input_DataArrayIndex(UINT8 display)
{
	UINT8 DataArrayIndex = _SOURCE_INDEX_TV05_VGA;
	/*0: VGA 1:TV(NTSC);2:TV(PAL);3:TV(SECAM);4:AV&SV(NTSC);5:AV&SV(PAL);6:AV&SV(SECAM);7:YPbPr SD;8:YPbPr HD;9:HDMI SD;10:HDMI HD;*/
	/**/

	if (m_nowSource == VIP_QUALITY_VGA) {
		DataArrayIndex = _SOURCE_INDEX_TV05_VGA;
	}
	if ((m_nowSource == VIP_QUALITY_TV_NTSC)) {
		DataArrayIndex = _SOURCE_INDEX_TV_NTSC;
	} else if ((m_nowSource == VIP_QUALITY_TV_PAL)) {
		DataArrayIndex = _SOURCE_INDEX_TV_PAL;
	} else if ((m_nowSource == VIP_QUALITY_TV_SECAN)) {
		DataArrayIndex = _SOURCE_INDEX_TV_SECAM;
	} else if ((m_nowSource == VIP_QUALITY_CVBS_NTSC) || (m_nowSource == VIP_QUALITY_CVBS_S_NTSC)) {
		DataArrayIndex = _SOURCE_INDEX_AVSV_NTSC;
	} else if ((m_nowSource == VIP_QUALITY_CVBS_PAL) || (m_nowSource == VIP_QUALITY_CVBS_S_PAL)) {
		DataArrayIndex = _SOURCE_INDEX_AVSV_PAL;
	} else if ((m_nowSource == VIP_QUALITY_CVBS_SECAN) || (m_nowSource == VIP_QUALITY_CVBS_S_SECAN)) {
		DataArrayIndex = _SOURCE_INDEX_AVSV_SECAM;
	} else if ((m_nowSource >= VIP_QUALITY_YPbPr_480I) && (m_nowSource <= VIP_QUALITY_YPbPr_576P)) {
		DataArrayIndex = _SOURCE_INDEX_YPBPR_SD;
	} else if ((m_nowSource >= VIP_QUALITY_YPbPr_720P) && (m_nowSource <= VIP_QUALITY_YPbPr_1080P)) {
		DataArrayIndex = _SOURCE_INDEX_YPBPR_HD;
	} else if ((m_nowSource >= VIP_QUALITY_HDMI_480I) && (m_nowSource <= VIP_QUALITY_HDMI_576P)) {
		DataArrayIndex = _SOURCE_INDEX_HDMI_SD;
	} else if ((m_nowSource >= VIP_QUALITY_HDMI_720P) && (m_nowSource <= VIP_QUALITY_HDMI_1080P)) {
		DataArrayIndex = _SOURCE_INDEX_HDMI_HD;
	}


	return DataArrayIndex;
}


/*------------------------------------------------------------------------------
  *function:	fwif_color_3DPQ_enhance (use Gamma S curve)
 *
  *Parm:		 = [0(off)  1(on)] (default value is off)
  *Return: 	void
 *-----------------------------------------------------------------------------*/
void fwif_color_3DPQ_enhance(unsigned char enable)
{
	StructColorDataType *pTable = NULL;
	unsigned char s_index = Scaler_GetSindex();
	unsigned char s_high = Scaler_GetShigh();
	unsigned char s_low = Scaler_GetSlow();
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);


	VIPprintf("\n ====== fwif_color_3DPQ_enhance ==== enable = %d =====\n", enable);
	if (enable) {
		s_index  -= 5;
		s_high += 5;
		s_low += 5;
	}

	/*FIX ME, no enhance*/
	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	fwif_set_gamma(pTable->Gamma, pTable->Sindex, pTable->Shigh, pTable->Slow);
}




UINT8 Android_mode_flag = 1;		/*0: OFF, TV mode, 1: ON, Android mode*/
UINT8 Scaler_Get_Android_mode(void)
{	/*0: OFF, TV mode, 1: ON, Android mode*/
	return Android_mode_flag;
}

static int g_iBacklightLevelAndroid = -1;
void Scaler_Set_Android_mode(UINT8 mode)
{	/*0: OFF, TV mode, 1: ON, Android mode*/
	rtd_printk(KERN_DEBUG, TAG_NAME, "%s:mode = %d\n", __FUNCTION__, mode);
	Android_mode_flag = mode;

	#if 0	/*mark for compiler, only for TV005 process*/
	if (mode) {
		drvif_color_set_output_gamma(0, 1);
		if (g_iBacklightLevelAndroid != -1) {
			Panel_SetBackLightLevel(BACKLIGHT_USER, g_iBacklightLevelAndroid);
		}
	}
	#endif
}
UINT8 media_player_USB_flag;
UINT8 Scaler_Get_Media_Player_USB_flag(void)
{	/*0: Youtube, 1:USB source, 2: Mira Cast*/
	return media_player_USB_flag;
}
void Scaler_Set_Media_Player_USB_flag(UINT8 flag)
{	/*0: Youtube, 1:USB source, 2: Mira Cast*/
	media_player_USB_flag = flag;
}

void Scaler_SaveAndroidBacklight(int value)
{
    g_iBacklightLevelAndroid = value;
}


/*============================================================================= */ /*DCC CSFC 20140128*/
/*==== NEW_DCC_Flow =====*/

unsigned char Scaler_Get_DCC_Color_Independent_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_Color_Independent_table_select;
}

void Scaler_Set_DCC_Color_Independent_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_Color_Independent_table_select = value;

	VIPprintf("DCC_Color_Independent_select = %d\n", value);
	fwif_color_set_dcc_Color_Independent_driver(src_idx, value);
}

unsigned char Scaler_Get_DCC_chroma_compensation_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 255;
	}
	return pTable->DCC_chroma_compensation_table_select;
}

void Scaler_Set_DCC_chroma_compensation_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_chroma_compensation_table_select = value;

	VIPprintf("DCC_chroma_compensation_table_select = %d\n", value);
	fwif_color_set_dcc_chroma_compensation_driver(src_idx, value);
}

/*o--- source table----o*/
unsigned char Scaler_GetDCC_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_table_select;
}

void Scaler_SetDCC_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_table_select = value;

	fwif_color_set_dcc_table_select(src_idx, value);
}

/*o--- picture mode----o*/
unsigned char Scaler_GetDCC_Mode(void)/* off, low, middle, high, default*/
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}

	VIPprintf("!!!!!!!!pCurPicModeData[mode].DccMode = %d\n", pData->DccMode);
	return pData->DccMode;
}

/* off, low, middle, high, default*/
unsigned char  Scaler_SetDCC_Mode(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}
	pTable->DccMode = value;

	printk("tim_li,set DCC mode =%d  \n",value);
	fwif_color_set_dcc_mode(src_idx, value);
	if (value < SLR_DCC_MODE_MAX) {
		Scaler_set_dcc_Sync_DCC_AP_Level(src_idx, Scaler_GetDCC_Table(), value);
		return TRUE;
	} else {
		rtd_printk(KERN_DEBUG, TAG_NAME, "Warning!! FreshContrast Range 0~3");
		return FALSE;
	}
}

/*o--- table cync. to video ---oo*/
unsigned char Scaler_Get_DCC_Boundary_Check_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_Boundary_Check_Table;
}

void Scaler_Set_DCC_Boundary_Check_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_Boundary_Check_Table = value;

	fwif_color_set_DCC_Boundary_Check_Table(src_idx, value);
}

unsigned char Scaler_Get_DCC_Level_and_Blend_Coef_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_Level_and_Blend_Coef_Table;
}

void Scaler_Set_DCC_Level_and_Blend_Coef_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_Level_and_Blend_Coef_Table = value;

	fwif_color_set_DCC_Level_and_Blend_Coef_Table(src_idx, value);
}


unsigned char Scaler_Get_DCC_database_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_database_Table;
}

void Scaler_Set_DCC_database_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_database_Table = value;

	fwif_color_set_DCC_database_Table(src_idx, value);
}

unsigned char Scaler_Get_DCC_UserCurve_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_UserCurve_Table;
}

void Scaler_Set_DCC_UserCurve_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_UserCurve_Table = value;

	fwif_color_set_DCC_User_Curve_Table(src_idx, value);
}

unsigned char Scaler_Get_DCC_AdaptCtrl_Level_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_adaptive_Level_Table;
}

void Scaler_Set_DCC_AdaptCtrl_Level_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_adaptive_Level_Table = value;

	fwif_color_set_DCC_AdaptCtrl_Level_Table(src_idx, value);
}

unsigned char Scaler_Get_DCC_hist_adjust_table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_hist_adjust_table;
}

void Scaler_Set_DCC_hist_adjust_table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_hist_adjust_table = value;

	Scaler_set_dcc_sync_histogram_adjust_table(src_idx, value); /* for AP eng. menu sync.*/

	fwif_color_set_DCC_hist_adjust_table(src_idx, value);
}

/*o---sync. level and coef base  to video ---o*/
unsigned char Scaler_GetDCL_W(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCL_W;
}

void Scaler_SetDCL_W(int value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCL_W = value;

	fwif_color_set_DCL_W(src_idx, value);
}

unsigned char Scaler_GetDCL_B(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCL_B;
}

void Scaler_SetDCL_B(int value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCL_B = value;

	fwif_color_set_DCL_B(src_idx, value);
}

unsigned char Scaler_GetDCC_W_extend(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_W_expand;
}

void Scaler_SetDCC_W_extend(int value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_W_expand = value;

	fwif_color_set_DCC_W_expand(src_idx, value);
}

unsigned char Scaler_GetDCC_B_extend(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_B_expand;
}

void Scaler_SetDCC_B_extend(int value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	pTable->DCC_B_expand = value;

	fwif_color_set_DCC_B_expand(src_idx, value);
}

unsigned char Scaler_Get_DCC_DelayTime(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_Blending_DelayTime;
}

void Scaler_Set_DCC_DelayTime(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_Blending_DelayTime = value;

	fwif_color_set_DCC_Blending_DelayTime(src_idx, value);
}

unsigned char Scaler_Get_DCC_Step(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_Blending_Step;
}

void Scaler_Set_DCC_Step(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_Blending_Step = value;

	fwif_color_set_DCC_Blending_Step(src_idx, value);
}

void Scaler_Set_DCC_Picture_Mode_Weight(int value)
{
	unsigned char src_idx = GET_USER_INPUT_SRC();
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	pTable->DCC_Picture_Mode_Weight = value;

	fwif_color_set_DCC_Picture_Mode_Weight(src_idx, value);
}

unsigned char Scaler_Get_DCC_Picture_Mode_Weight(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return pTable->DCC_Picture_Mode_Weight;
}

/*o--- sync. table coef. that is non-adaptive table base API to video ---o*/
void Scaler_Set_Dcc_histogram_gain(unsigned char bin_num, unsigned char value, unsigned char SceneChange)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	/*int ret;*/
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	pTable->DCC_Histogram_gain[bin_num] = value;

	fwif_color_set_DCC_histogram_gain(src_idx, value, bin_num);
}

unsigned char Scaler_Get_Dcc_histogram_gain(unsigned char bin_num)
{
	StructColorDataType *pTable = NULL;
	unsigned char Dcc_histogram_gain = 8;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}

	Dcc_histogram_gain = pTable->DCC_Histogram_gain[bin_num];

	VIPprintf("## Dcc_histogram_gain = %d ##\n", Dcc_histogram_gain);

	return Dcc_histogram_gain;
}

void Scaler_Set_Dcc_histogram_offset(unsigned char bin_num, unsigned char value, unsigned char SceneChange)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	/*int ret;*/
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
	rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	pTable->DCC_Histogram_offset[bin_num] = value;

	fwif_color_set_DCC_histogram_offset(src_idx, value, bin_num);
}

unsigned char Scaler_Get_Dcc_histogram_offset(unsigned char bin_num)
{
	StructColorDataType *pTable = NULL;
	unsigned char Dcc_histogram_offset = 8;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}

	Dcc_histogram_offset = pTable->DCC_Histogram_offset[bin_num];

	VIPprintf("## Dcc_histogram_offset = %d ##\n", Dcc_histogram_offset);

	return Dcc_histogram_offset;
}

void Scaler_Set_Dcc_histogram_limit(unsigned char bin_num, unsigned char value, unsigned char SceneChange)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	/*int ret;*/
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	pTable->DCC_Histogram_limit[bin_num] = value;

	fwif_color_set_DCC_histogram_limit(src_idx, value, bin_num);
}

unsigned char Scaler_Get_Dcc_histogram_limit(unsigned char bin_num)
{
	StructColorDataType *pTable = NULL;
	unsigned char Dcc_histogram_limit = 8;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}

	Dcc_histogram_limit = pTable->DCC_Histogram_limit[bin_num];

	VIPprintf("## Dcc_histogram_limit = %d ##\n", Dcc_histogram_limit);

	return Dcc_histogram_limit;
}

/*o--- non-adaptive table coef sync. when table change---o*/
void Scaler_set_dcc_sync_histogram_adjust_table(unsigned char src_idx , unsigned char Tabel_sel) /* for AP eng. menu sync.*/
{
	int i = 0;
	VIP_DCC_Hist_Factor_Table *DCC_Hist_Factor_Table = NULL;
	SLR_VIP_TABLE *prt = fwif_color_GetShare_Memory_VIP_TABLE_Struct();
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);

	if (prt == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get share mem vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	DCC_Hist_Factor_Table = &(prt->DCC_Control_Structure.DCCHist_Factor_Table[pTable->DCC_hist_adjust_table]);

	for (i = 0; i < 32; i++) {
		pTable->DCC_Histogram_gain[i]	=	DCC_Hist_Factor_Table->gain[i];
		pTable->DCC_Histogram_offset[i]	=	DCC_Hist_Factor_Table->offset[i];
		pTable->DCC_Histogram_limit[i]	=	DCC_Hist_Factor_Table->limit[i];
	}

}

void Scaler_set_dcc_Sync_DCC_AP_Level(unsigned char src_idx, unsigned char Tabel_sel, unsigned char Mode_sel)
{
	VIP_DCC_Curve_Control_Coef *DCC_Curve_Control_Coef = NULL;
	VIP_DCC_Level_and_Blend_Coef_Table	*Level_and_Blend_Coef_Table = NULL;

	/*o----get table from share memory---o*/
	VIP_DCC_Curve_Control_Coef *pItemAdjust = NULL;
	StructColorDataType *pTable = NULL;
	VIP_DCC_Level_and_Blend_Coef_Table *pItemAdjust_1 = NULL;
	SLR_VIP_TABLE *prt = fwif_color_GetShare_Memory_VIP_TABLE_Struct();
	if (prt == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get share mem vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	DCC_Curve_Control_Coef = &(prt->DCC_Control_Structure.DCC_Curve_Control_Coef[0][0]);
	Level_and_Blend_Coef_Table = &(prt->DCC_Control_Structure.DCC_Level_and_Blend_Coef_Table[0]);

	/*o---get by table and mode form share memory---o*/
	if (Mode_sel > SLR_DCC_Default)
		Mode_sel = SLR_DCC_Default;
	pItemAdjust = &DCC_Curve_Control_Coef[Tabel_sel*DCC_SELECT_MAX+Mode_sel];

	/*set table to color data*/
	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	/* defined by VIP table, and value fix by src*/
	pTable->DCC_Boundary_Check_Table = pItemAdjust->Boundary_Check_Table;
	pTable->DCC_Level_and_Blend_Coef_Table	=	pItemAdjust->Level_and_Blend_Coef_Table;
	pTable->DCC_hist_adjust_table = pItemAdjust->hist_adjust_table;
	pTable->DCC_adaptive_Level_Table = pItemAdjust->AdaptCtrl_Level_Table;
	pTable->DCC_UserCurve_Table = pItemAdjust->User_Curve_Table;
	pTable->DCC_database_Table = pItemAdjust->database_DCC_Table;
	pTable->DCC_Picture_Mode_Weight = pItemAdjust->Picture_Mode_Weight;

	pItemAdjust_1 = &(prt->DCC_Control_Structure.DCC_Level_and_Blend_Coef_Table[(pTable->DCC_Level_and_Blend_Coef_Table)]);

	pTable->DCL_W = pItemAdjust_1->DCL_W_level;
	pTable->DCL_B = pItemAdjust_1->DCL_B_level;
	/*pTable->DCC_W_expand = pItemAdjust_1->Expand_W_Level;	*/ /*=== marked by Elsie ===*/
	/*pTable->DCC_B_expand = pItemAdjust_1->Expand_B_Level;	*/ /*=== marked by Elsie ===*/
	pTable->DCC_Blending_Step = pItemAdjust_1->Step;
	pTable->DCC_Blending_DelayTime = pItemAdjust_1->Delay_time;

	Scaler_set_dcc_Sync_DCC_Video_Driver_Level(src_idx);

}

void Scaler_set_dcc_Sync_DCC_Video_Driver_Level(unsigned char src_idx)/*Note : must be using when DCC global coef. setting ready!!!, CSFC_20140212*/
{
	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Warning!! Get colordata NULL., %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	/*o--- adaptive table sync --o*/
	fwif_color_set_DCC_Boundary_Check_Table(src_idx, pTable->DCC_Boundary_Check_Table);
	fwif_color_set_DCC_Level_and_Blend_Coef_Table(src_idx, pTable->DCC_Level_and_Blend_Coef_Table);
	fwif_color_set_DCC_hist_adjust_table(src_idx, pTable->DCC_hist_adjust_table);
	fwif_color_set_DCC_AdaptCtrl_Level_Table(src_idx, pTable->DCC_adaptive_Level_Table);
	fwif_color_set_DCC_User_Curve_Table(src_idx, pTable->DCC_UserCurve_Table);
	fwif_color_set_DCC_database_Table(src_idx, pTable->DCC_database_Table);

	/*o--no adaptive level sync --o*/
	fwif_color_set_DCL_W(src_idx, pTable->DCL_W);
	fwif_color_set_DCL_B(src_idx, pTable->DCL_B);
	fwif_color_set_DCC_W_expand(src_idx, pTable->DCC_W_expand);
	fwif_color_set_DCC_B_expand(src_idx, pTable->DCC_B_expand);
	fwif_color_set_DCC_Blending_Step(src_idx, pTable->DCC_Blending_Step);
	fwif_color_set_DCC_Blending_DelayTime(src_idx, pTable->DCC_Blending_DelayTime);
	fwif_color_set_DCC_Picture_Mode_Weight(src_idx, pTable->DCC_Picture_Mode_Weight);

}


unsigned char Scaler_SetDCC_HAL_FreshContrast(unsigned char display , unsigned char uDCMode, UINT32 pstData)
{
	return Scaler_SetDCC_Mode(uDCMode);
}


/*====== About  DCC Function end ==========*/
/*============================================================================= */ /*DCC CSFC 20140128*/



/*============================================================================= */ /*ConBri CSFC 20140128*/
/*             Contrast/brightness*/
/*============================*/


#ifdef OSD_FOUR_LEVEL_MAPPING_ENABLE
unsigned char Scaler_GetFacBrightness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Brightness_0;
	*retval_50 = pTable->Brightness_50;
	*retval_100 = pTable->Brightness_100;
	*retval_25 = pTable->Brightness_25;
	*retval_75 = pTable->Brightness_75;
	return 0;
}

unsigned char Scaler_SetFacBrightness(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Brightness_0 = val_0;
	pTable->Brightness_50 = val_50;
	pTable->Brightness_100 = val_100;
	pTable->Brightness_25 = val_25;
	pTable->Brightness_75 = val_75;
	return 0;
}

unsigned char Scaler_GetFacContrast(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Contrast_0;
	*retval_50 = pTable->Contrast_50;
	*retval_100 = pTable->Contrast_100;
	*retval_25 = pTable->Contrast_25;
	*retval_75 = pTable->Contrast_75;
	return 0;
}
unsigned char Scaler_SetFacContrast(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Contrast_0 = val_0;
	pTable->Contrast_50 = val_50;
	pTable->Contrast_100 = val_100;
	pTable->Contrast_25 = val_25;
	pTable->Contrast_75 = val_75;
	return 0;
}

#else
unsigned char Scaler_GetFacBrightness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Brightness_0;
	*retval_50 = pTable->Brightness_50;
	*retval_100 = pTable->Brightness_100;
	return 0;
}

unsigned char Scaler_SetFacBrightness(unsigned char val_0, unsigned char val_50, unsigned char val_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Brightness_0 = val_0;
	pTable->Brightness_50 = val_50;
	pTable->Brightness_100 = val_100;
	return 0;
}

unsigned char Scaler_GetFacContrast(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Contrast_0;
	*retval_50 = pTable->Contrast_50;
	*retval_100 = pTable->Contrast_100;
	return 0;
}

unsigned char Scaler_SetFacContrast(unsigned char val_0, unsigned char val_50, unsigned char val_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Contrast_0 = val_0;
	pTable->Contrast_50 = val_50;
	pTable->Contrast_100 = val_100;
	return 0;
}

#endif

unsigned char Scaler_OsdMapToRegValue_Contrast(unsigned char display , unsigned char value)
{
	#if  defined(TV020_STYLE_PQ) || defined(BUILD_TV030_2)
		return fw_OsdMapToRegValue(display, FAC_CONTRAST, value);
	#else
		return 0;
	#endif
}
unsigned char Scaler_OsdMapToRegValue_Brightness(unsigned char display , unsigned char value)
{
	#if  defined(TV020_STYLE_PQ) || defined(BUILD_TV030_2)
		return fw_OsdMapToRegValue(display, FAC_BRIGHTNESS, value);
	#else
		return 0;
	#endif
}

#if 0/* Gamma flow fix*/
void Scaler_set_SCurve_driver(unsigned char item_idx, unsigned short value)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);


	if ((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == SLR_MAIN_DISPLAY) {
		/*WaitFor_DEN_STOP();*/
		switch (item_idx) {
		case gamma_mode:
			/*Scaler_SetGamma(value);*/
		break;

		case S_gamma_index:
			/*Scaler_SetSindex(value);*/
		break;

		case S_gamma_high:
			/*Scaler_SetShigh(value);*/
		break;

		case S_gamma_low:
			/*Scaler_SetSlow(value);*/
		break;

		default:
			/*drvif_color_S_Curve(_MAIN_DISPLAY, Scaler_GetGamma(), Scaler_GetSindex(), Scaler_GetSlow(),  Scaler_GetShigh());*/
		break;
		}
		fwif_set_gamma(src_idx);
	}
#ifdef CONFIG_DUAL_CHANNEL
	if ((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == SLR_SUB_DISPLAY) {
		/*WaitFor_DEN_STOP();*/
		switch (item_idx) {
		case gamma_mode:
			/*Scaler_SetGamma(value);*/
		break;

		case S_gamma_index:
			/*Scaler_SetSindex(value);*/
		break;

		case S_gamma_high:
			/*Scaler_SetShigh(value);*/
		break;

		case S_gamma_low:
			/*Scaler_SetSlow(value);*/
		break;

		default:
			/*drvif_color_S_Curve(SLR_SUB_DISPLAY, Scaler_GetGamma(), Scaler_GetSindex(), Scaler_GetSlow(),  Scaler_GetShigh());*/
		break;
		/*FIX ME, NO have sub option*/
		fwif_set_gamma(src_idx);
		}

	}
#endif

}
#endif
unsigned short Scaler_get_color_temp_r_type(unsigned char src_idx)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return 0;
	return pTable->R_val;
}

void Scaler_set_color_temp_r_type(unsigned char src_idx, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return;
	pTable->R_val = value;
}

unsigned short Scaler_get_color_temp_g_type(unsigned char src_idx)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return 0;
	return pTable->G_val;
}

void Scaler_set_color_temp_g_type(unsigned char src_idx, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return;
	pTable->G_val = value;
}

unsigned short Scaler_get_color_temp_b_type(unsigned char src_idx)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return 0;
	return pTable->B_val;
}

void Scaler_set_color_temp_b_type(unsigned char src_idx, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return;
	pTable->B_val = value;
}

unsigned short Scaler_get_color_temp_r_offset(unsigned char src_idx)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return 0;
	return pTable->R_offset_val;
}

void Scaler_set_color_temp_r_offset(unsigned char src_idx, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return;
	pTable->R_offset_val = value;
}

unsigned short Scaler_get_color_temp_g_offset(unsigned char src_idx)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return 0;
	return pTable->G_offset_val;
}

void Scaler_set_color_temp_g_offset(unsigned char src_idx, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return;
	pTable->G_offset_val = value;

}

unsigned short Scaler_get_color_temp_b_offset(unsigned char src_idx)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return 0;
	return pTable->B_offset_val;
}

void Scaler_set_color_temp_b_offset(unsigned char src_idx, unsigned short value)
{
	SLR_COLORTEMP_DATA *pTable = scaler_get_color_tempset(src_idx, 0);
	if (NULL == pTable)
		return;
	pTable->B_offset_val = value;
}



/*==== color temp*/
/*=============================================================================  */ /*ColorTemp CSFC 20140128*/


/*================================================================================= */ /*sharpness CSFC 20140128*/

unsigned int picmode_init_value[PICMODE_INIT_MAX];
void Scaler_set_picmode_init_value(unsigned char item_index, unsigned short value)
{
	if (item_index >= PICMODE_INIT_MAX)
		return;
	picmode_init_value[item_index] = value;
}

int Scaler_set_picmode_init_sendRPC(void)
{
#if 0 // ISR in kernel ! this function is  useless.
	int ret = 1;
	int i = 0;

	unsigned int *pwTemp = (unsigned int *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_VIP_PICMODE_INIT);
	if (pwTemp) {
		memcpy((unsigned int *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_VIP_PICMODE_INIT),
			picmode_init_value, sizeof(unsigned int)*PICMODE_INIT_MAX);

		for (i = 0; i < PICMODE_INIT_MAX; i++) {
			pwTemp[i] = fwif_color_ChangeOneUINT32Endian(pwTemp[i], 0);
			rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_set_picmode_init_sendRPC[%d] = %x\n", i, pwTemp[i]);
		}

			ret = Scaler_SendRPC(SCALERIOC_SET_VIP_PICMODE_INIT, 0, 0);
		}
		return ret;
#endif
}






void Scaler_SetTableNRSpatial(unsigned char value)
{
	int ret;

	/* copy to RPC share memory*/
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_TABLENRSPATIAL), &value, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SET_TABLENRSPATIAL, 0, 0);
	if (0 != ret) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, set TableNRSpatial to driver fail !!!\n", ret);
		return;
	}
}

unsigned char Scaler_GetTableNRSpatial(void)
{
	int ret;
	unsigned char value = 0;

	ret = Scaler_SendRPC(SCALERIOC_GET_TABLENRSPATIAL, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get TableNRSpatial from driver fail !!!\n", ret);
		return 0;
	}
	/* copy from RPC share memory*/
	memcpy(&value, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_TABLENRSPATIAL), sizeof(unsigned char));



	return value;
}

/* move "DNR table select info" to system_info_struct and replace by PQA table, elieli*/
#if 0
void Scaler_SetDNR_table(unsigned char value, unsigned char calledByOSD)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->PQA_Table = value;
	fwif_color_set_DNR_table(value, calledByOSD);
/*	fwif_color_set_DNR_table(GET_USER_INPUT_SRC(), value);*/
}
#endif

unsigned char  Scaler_GetDNR_table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->PQA_Table;
}

void Scaler_SetDNR(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	rtd_printk(KERN_DEBUG, TAG_NAME, "==== Scaler_SetDNR, %d\n", value);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;
	pData->DNR = value;

	rtd_printk(KERN_DEBUG, TAG_NAME, "===== Scaler_SetDNR, %d\n", value);
	IoReg_ClearBits(DI_db_reg_ctl_reg, _BIT1);
	fwif_color_SetDNR(display, value);
	IoReg_SetBits(DI_db_reg_ctl_reg, _BIT1);
}

unsigned char Scaler_GetDNR(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;
	return pData->DNR;
}

void Scaler_SetMPEGNR(unsigned char value, unsigned char calledByOSD)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;
	pData->MPEG = value;

	fwif_color_SetMPEGNR(display, value, calledByOSD);
}

unsigned char Scaler_GetMPEGNR(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;
	return pData->MPEG;
}

DRV_RTNR_General_ctrl *Scaler_GetRTNR_General(void)
{
	return fwif_color_GetRTNR_General(Scaler_GetDNR_table(), Scaler_GetDNR());
}

void Scaler_SetRTNR_Y(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->rtnr_y = value;

}

unsigned char Scaler_GetRTNR_Y(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->rtnr_y;
}

void Scaler_SetRTNR_C(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->rtnr_c = value;

}

unsigned char Scaler_GetRTNR_C(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->rtnr_c;
}

void Scaler_SetNRSpatialY(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->NRSpatialY = value;

}

unsigned char Scaler_GetNRSpatialY(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->NRSpatialY;
}

void Scaler_SetNRSpatialC(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->NRSpatialC = value;

}

unsigned char Scaler_GetNRSpatialC(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->NRSpatialC;
}

void Scaler_SetMpegNR_H(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MPEGNR_H = value;

}

unsigned char Scaler_GetMpegNR_H(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MPEGNR_H;
}

void Scaler_SetMpegNR_V(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MPEGNR_V = value;

}

unsigned char Scaler_GetMpegNR_V(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MPEGNR_V;
}

void Scaler_SetNRTemporal(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->NRTemporal = value;
	fwif_color_Set_NRtemporal(display, value);
}

unsigned char Scaler_GetNRTemporal(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->NRTemporal;
}


#if defined (PQ_005_STYLE)
void Scaler_SetAutoNR(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;
	pData->Auto_NR = value;
}

unsigned char Scaler_GetAutoNR(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;
	return pData->Auto_NR;
}
#endif


unsigned short Scaler_GetICMTable()
{
/*rtd_printk(KERN_DEBUG, TAG_NAME, "@@@@@@@@=== gene 1.Scaler_GetICMTable ==\n");*/
	return Scaler_get_ICM_table();
}
void Scaler_SetICMTable(unsigned char value)
{
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "@@@@@@@@=== gene 1.Scaler_SetICMTable = %d ==\n", value);*/
	Scaler_set_ICM_table(value, 0);
}

void scaler_set_PQA_Input_table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);
	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->PQA_I_Table = value;
	fwif_color_set_PQA_Input_table(value);
}
/* Erin add for Atlantic , 100402*/
void scaler_set_PQA_table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);
	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->PQA_Table = value;

	fwif_color_set_PQA_table(value);
}

unsigned char scaler_get_PQA_Input_table(void)
{
	return fwif_color_get_PQA_Input_table();
}

unsigned char scaler_get_PQA_table(void)
{
	return fwif_color_get_PQA_table();
}

/*add for haier 20111210 by lichun zhao*/
#ifdef TV013UI_1

static unsigned char _2DColorManagemen = TRUE;
static unsigned char _3DColorManagemen[SOURCE_MAX_NUM] = {TRUE};

unsigned char Scaler_Get2DColorManagement()
{
    return _2DColorManagemen;
}


void Scaler_Set2DColorManagement(unsigned char mode)
{
    /* fwif_set_color_management(mode);*/
	 _2DColorManagemen = mode;
}

unsigned char Scaler_Get3DColorManagement(unsigned char input_src_index)
{
 /*   unsigned short input_src_index;*/
 /*   input_src_index = Scaler_InputSrcIndex(Scaler_DispGetInputInfo(SLR_INPUT_INPUT_SRC));*/
rtd_printk(KERN_DEBUG, TAG_NAME, "\n $$$$$$$$$$$$ ScalerLib Scaler_Get3DColorManagement input_src_index = %x \n", input_src_index);

    return _3DColorManagemen[input_src_index];
}

void Scaler_Set3DColorManagement(unsigned char input_src_index, unsigned char mode)
{
    /*unsigned short input_src_index;*/
	/*input_src_index = Scaler_InputSrcIndex(Scaler_DispGetInputInfo(SLR_INPUT_INPUT_SRC));*/
   /* fwif_set_color_management(mode);*/
   /*rtd_printk(KERN_DEBUG, TAG_NAME, "\n $$$$$$$$ input_src_index = %x \n", input_src_index);*/
	_3DColorManagemen[input_src_index] = mode;

}

#endif

/*o =========================================================== o*/
/*o =================== Enginner Menu Start =================== o*/
/*o =========================================================== o*/



unsigned char Scaler_GetScaleDOWNH(void)
{
	return fwif_color_get_scaledownh(GET_USER_INPUT_SRC());
}

/*range 0~17*/
void Scaler_SetScaleDOWNH(unsigned char value)
{
	fwif_color_set_scaledownh(GET_USER_INPUT_SRC(), value);
}

unsigned char Scaler_GetScaleDOWNV(void)
{
	return fwif_color_get_scaledownv(GET_USER_INPUT_SRC());
}

/*range 0~17*/
void Scaler_SetScaleDOWNV(unsigned char value)
{
	fwif_color_set_scaledownv(GET_USER_INPUT_SRC(), value);
}

unsigned short Scaler_GetH8Scaling()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->H8_Scaling;
}

void Scaler_SetH8Scaling(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->H8_Scaling = value;
}

unsigned char Scaler_GetPacificNewIntra(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;

	return pTable->IntraAllPacificNew;
}

void Scaler_SetPacificNewIntra(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->IntraAllPacificNew = value;

	fwif_color_set_intra_all_pacific_new_switch (GET_USER_INPUT_SRC(), value);
}

unsigned short Scaler_GetICcoring()
{
	return 0;
/*	return fwif_color_get_i_ccoring(GET_USER_INPUT_SRC());*/
}

void Scaler_SetICcoring(unsigned char message)
{
	/*drvif_color_chroma_coring(info->display, 0, message);*/
}

unsigned short Scaler_GetDCcoring()
{
	return 0;
}

void Scaler_SetDCcoring(unsigned char message)
{
	/*drvif_color_chroma_coring(info->display, 1, message);*/
}

unsigned char Scaler_GetVertical_NR(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Vertical_NR;
}

/*range 0~1, Lydia*/
void Scaler_SetVertical_NR(unsigned char value)
{
	/*int ret;*/
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Vertical_NR = value;

	if ((Scaler_SendRPC(SCALERIOC_GET_TABLE_VerticalNR, value, RPC_SEND_VALUE_ONLY)) < 0) {
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, update TableNR_VerticalNR to driver fail !!!\n", ret);*/
	}

	fwif_color_set_Vertical_NR_driver(src_idx, value);
}



unsigned char Scaler_GetIESM(void)
{
	return 0;
/*	return fwif_color_get_iEdgeSmooth_en_set(GET_USER_INPUT_SRC());*/
}

/*range 0~1, Lydia*/
void Scaler_SetIESM(unsigned char value)
{
/*	fwif_color_set_iEdgeSmooth_en_set(GET_USER_INPUT_SRC(), value);*/
	drvif_color_iEdgeSmooth_en(value);
}

unsigned char Scaler_GetIESM_Chaos(void)
{
	return 0;
/*	return fwif_color_get_iEdgeSmooth_chaos_set(GET_USER_INPUT_SRC());*/
}

/*range 0~8, Lydia*/
void Scaler_SetIESM_Chaos(unsigned char value)
{
/*	fwif_color_set_iEdgeSmooth_chaos_set(GET_USER_INPUT_SRC(), value);*/
	drvif_color_iEdgeSmooth_chaos_set(value);
}

unsigned char Scaler_GetIESM_Top2Diff(void)
{
	return 0;
/*	return fwif_color_get_iEdgeSmooth_t2df_set(GET_USER_INPUT_SRC());*/
}

/*range 0~8, Lydia*/
void Scaler_SetIESM_Top2Diff(unsigned char value)
{
/*	fwif_color_set_iEdgeSmooth_t2df_set(GET_USER_INPUT_SRC(), value);*/
	drvif_color_iEdgeSmooth_t2df_set(value);
}

unsigned char Scaler_GetIESM_Edge(void)
{
	return 0;
/*	return fwif_color_get_iEdgeSmooth_edge_set(GET_USER_INPUT_SRC());*/
}

/*range 0~8, Lydia*/
void Scaler_SetIESM_Edge(unsigned char value)
{
/*	fwif_color_set_iEdgeSmooth_edge_set(GET_USER_INPUT_SRC(), value);*/
	drvif_color_iEdgeSmooth_edge_set(value);
}

unsigned char Scaler_GetIESM_CRCT(void)
{
	return 0;
/*	return fwif_color_get_iEdgeSmooth_crct_set(GET_USER_INPUT_SRC());*/
}

/*range 0~8, Lydia*/
void Scaler_SetIESM_CRCT(unsigned char value)
{
/*	fwif_color_set_iEdgeSmooth_crct_set(GET_USER_INPUT_SRC(), value);*/
	drvif_color_iEdgeSmooth_crct_set(value);
}

unsigned char Scaler_GetIESM_Exten(void)
{
	return 0;
/*	return fwif_color_get_iEdgeSmooth_extension_set(GET_USER_INPUT_SRC());*/
}

/*range 0~8, Lydia*/
void Scaler_SetIESM_Exten(unsigned char value)
{
/*	fwif_color_set_iEdgeSmooth_extension_set(GET_USER_INPUT_SRC(), value);*/
	drvif_color_iEdgeSmooth_extension_set(value);
}

unsigned char Scaler_GetHMCNR(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);
	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->HMCNR_range;

}

void Scaler_SetHMCNR(unsigned char value)
{
	/*int ret;*/
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->HMCNR_range = value;

	if ((Scaler_SendRPC(SCALERIOC_GET_TABLE_HMCNR, value, RPC_SEND_VALUE_ONLY)) < 0) {
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, update TableNR_HMCNR to driver fail !!!\n", ret);*/
	}

	 fwif_color_set_HMCNR_driver(src_idx, value);

}

unsigned char Scaler_GetHMCNR_blending(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->HMCNR_blending;

}
/*range 0~1, Lydia*/
void Scaler_SetHMCNR_blending(unsigned char value)
{
	/*int ret;*/
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->HMCNR_blending = value;

	fwif_color_set_HMCNR_blending_driver(src_idx, value);

}

unsigned char Scaler_GetMBPeaking(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MBPeaking;
}

/*range 0~40*/
void Scaler_SetMBPeaking(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MBPeaking = value;

	fwif_color_set_MBPK_table(src_idx, value);
}


unsigned short Scaler_GetSharpnessVerticalGain()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Shp_Vgain;
}

void Scaler_SetSharpnessVerticalGain(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Shp_Vgain = value;

	fwif_color_set_shp_vgain(GET_USER_INPUT_SRC(), value);
}

unsigned char Scaler_GetSKIPIR_Islet()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->SKIPIR_islet;
}

void Scaler_SetSKIPIR_Islet(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->SKIPIR_islet = value;

	fwif_color_set_skipir_islet(src_idx, value);
}

unsigned short  Scaler_Getharpness2Dpk_Seg()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Shp_2Dpk_Seg;
}

void Scaler_SetSharpness2Dpk_Seg(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Shp_2Dpk_Seg = value;

	fwif_color_set_shp_2Dpk_Seg(src_idx, value);
}

unsigned short  Scaler_GetSharpness2Dpk_Tex_Detect()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Shp_2Dpk_Tex_Detect;

}

void Scaler_SetSharpness2Dpk_Tex_Detect(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Shp_2Dpk_Tex_Detect = value;

	fwif_color_set_shp_2Dpk_Tex_Detect(src_idx, value);
}

unsigned char Scaler_GetMADI_BTR()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MA_BTR;

}

void Scaler_SetMADI_BTR(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MA_BTR = value;

	fwif_color_set_ma_BTR(src_idx, value);
}

unsigned char Scaler_GetMADI_BER()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MA_BER;
}

void Scaler_SetMADI_BER(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MA_BER = value;

	fwif_color_set_ma_BER(src_idx, value);
}

unsigned char Scaler_GetGridRemove()
{
	return fwif_color_get_grid_remove(GET_USER_INPUT_SRC());
}

void Scaler_SetGridRemove(unsigned char value)
{
	fwif_color_set_grid_remove(GET_USER_INPUT_SRC(), value);
}

unsigned char Scaler_GetContiStillLine()
{
	return fwif_color_get_conti_still_line(GET_USER_INPUT_SRC());
}

void Scaler_SetContiStillLine(unsigned char value)
{
	fwif_color_set_conti_still_line(GET_USER_INPUT_SRC(), value);
}


void Scaler_Set_TVAutoNR_Mode(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_TVAUTONR_Mode);
	if (!pwTemp) {
		return;
	}
	/* copy to RPC share memory*/
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "A. Scaler_Set_TVAutoNR_Mode = %x\n", flag);*/
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_TVAUTONR_Mode), &flag, sizeof(unsigned char));
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "B. Scaler_Set_TVAutoNR_Mode = %x\n", flag);*/
	ret = Scaler_SendRPC(SCALERIOC_SET_TVAUTONR_Mode, 0, 0);
	if (0 != ret) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, set Enter_TVAUTONR_Mode to driver fail !!!\n", ret);
		return;

	}
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "B. SCALERIOC_SET_TVAUTONR_Mode = %x\n", Scaler_GetShareMemVirAddr(SCALERIOC_SET_TVAUTONR_Mode));*/


}

unsigned char Scaler_GetAutoMA1Flag() /* enable/disable AutoMA*/
{
	return fwif_color_GetAutoMA_Struct()->AutoMA1_En;
}

void Scaler_SetAutoMA1Flag(unsigned char flag)
{
	fwif_color_GetAutoMA_Struct()->AutoMA1_En = flag;
	return;
}

unsigned char Scaler_GetAutoMA2Flag() /* enable/disable AutoMA*/
{
	return fwif_color_GetAutoMA_Struct()->AutoMA2_En;
}

void Scaler_SetAutoMA2Flag(unsigned char flag)
{
	fwif_color_GetAutoMA_Struct()->AutoMA2_En = flag;
	return;
}

unsigned char Scaler_GetAutoMA3Flag() /* enable/disable AutoMA*/
{
	return fwif_color_GetAutoMA_Struct()->AutoMA3_En;
}

void Scaler_SetAutoMA3Flag(unsigned char flag)
{
	fwif_color_GetAutoMA_Struct()->AutoMA3_En = flag;
	return;
}

unsigned char Scaler_GetAutoMA4Flag() /* enable/disable AutoMA*/
{
	return fwif_color_GetAutoMA_Struct()->AutoMA4_En;
}

void Scaler_SetAutoMA4Flag(unsigned char flag)
{
	fwif_color_GetAutoMA_Struct()->AutoMA4_En = flag;
	return;
}

unsigned char Scaler_GetAutoMA5Flag() /* enable/disable AutoMA*/
{
	return fwif_color_GetAutoMA_Struct()->AutoMA5_En;
}

void Scaler_SetAutoMA5Flag(unsigned char flag)
{
	fwif_color_GetAutoMA_Struct()->AutoMA5_En = flag;
	return;
}

unsigned char Scaler_GetAutoMA6Flag() /* enable/disable AutoMA*/
{
	return fwif_color_GetAutoMA_Struct()->AutoMA6_En;
}

void Scaler_SetAutoMA6Flag(unsigned char flag)
{
	fwif_color_GetAutoMA_Struct()->AutoMA6_En = flag;
	return;
}

unsigned char Scaler_GetAutoMAFlag(void) /* Is AutoMA running ? set for IRQ/IRC*/
{
	return fwif_color_GetAutoMAFlag();
}

void Scaler_SetAutoMAFlag(unsigned char flag) /* enable/disable AutoMA, set for IRQ/IRC*/
{
	/*if (Scaler_IsUnitTest())*/
	/*	return;*/

#ifdef MAGELLAN_BRING_UP_HACK_VIP
	return;
#endif

	fwif_color_SetAutoMAFlag(flag);
}

unsigned char Scaler_GetAutoMA_VD_3D() /* enable/disable AutoMA*/
{
	int ret;
	unsigned char flag = TRUE;

	/* enable this debug message after remove the debug warning first, pls.*/
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_GetAutoMA4Flag = %d\n", (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETAUTOMAFLAG_4));*/
	ret = Scaler_SendRPC(SCALERIOC_GETAUTOMA_VD_3D, 0, 0);
	if (0 != ret) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, get Enter_AutoMA flag VD 3D from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETAUTOMA_VD_3D), sizeof(unsigned char));


	return flag;
}

void Scaler_SetAutoMA_VD_3D(unsigned char flag)
{
	int ret;

	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETAUTOMA_VD_3D), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SETAUTOMA_VD_3D, 0, 0);
	if (0 != ret) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, set Enter_AutoMA flag VD 3D to driver fail !!!\n", ret);
		return;

	}
}

void Scaler_Set_NR_style(unsigned char flag, unsigned char calledByOSD)
{

	VIPprintf("** *SCALERIOC_SET_NR_style = %d\n", flag);
	if (calledByOSD == CALLED_BY_OSD) {
		int ret;
		VIPprintf("*** SCALERIOC_SET_NR_style = %d\n", flag);
		ret = Scaler_SendRPC(SCALERIOC_SET_NR_style, flag, RPC_SEND_VALUE_ONLY);
		if (0 != ret) {
			SLRLIB_PRINTF("ret = %d, set SCALERIOC_SET_NR_style to driver fail !!!\n", ret);
			return;
		}
	} else
		Scaler_set_picmode_init_value(PICMODE_INIT_NR_STYLE, flag);
}

unsigned char Scaler_GetDNR_log()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETDNR_log);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GETDNR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_DNR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETDNR_log), sizeof(unsigned char));

	return flag;
}

void Scaler_SetDNR_log(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETDNR_log);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETDNR_log), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SETDNR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_DNR_log to driver fail !!!\n", ret);
		return;

	}
}
unsigned char Scaler_GetRTNR_log()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETRTNR_log);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GETRTNR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_RTNR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETRTNR_log), sizeof(unsigned char));

	return flag;
}

void Scaler_SetRTNR_log(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETRTNR_log);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETRTNR_log), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SETRTNR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_RTNR_log to driver fail !!!\n", ret);
		return;

	}
}

unsigned char Scaler_GetSNR_log()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETSNR_log);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GETSNR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_SNR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETSNR_log), sizeof(unsigned char));

	return flag;
}

void Scaler_SetSNR_log(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETSNR_log);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETSNR_log), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SETSNR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_SNR_log to driver fail !!!\n", ret);
		return;
	}
}

unsigned char Scaler_GetINR_log()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETINR_log);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GETINR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_INR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GETINR_log), sizeof(unsigned char));

	return flag;
}

void Scaler_SetINR_log(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETINR_log);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETINR_log), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SETINR_log, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_INR_log to driver fail !!!\n", ret);
		return;
	}
}

unsigned char Scaler_Get_DEBUG_AUTO_NR()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_AUTO_NR);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GET_DEBUG_AUTO_NR, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_INR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_AUTO_NR), sizeof(unsigned char));

	return flag;
}

void Scaler_Set_DEBUG_AUTO_NR(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_AUTO_NR);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_AUTO_NR), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SET_DEBUG_AUTO_NR, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_INR_log to driver fail !!!\n", ret);
		return;
	}
}

unsigned char Scaler_Get_DEBUG_VD_NOISE()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_VD_NOISE);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GET_DEBUG_VD_NOISE, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_INR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_VD_NOISE), sizeof(unsigned char));

	return flag;
}

void Scaler_Set_DEBUG_VD_NOISE(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_VD_NOISE);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_VD_NOISE), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SET_DEBUG_VD_NOISE, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_INR_log to driver fail !!!\n", ret);
		return;
	}
}

unsigned char Scaler_Get_DEBUG_RTNR_MAD()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_RTNR_MAD);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GET_DEBUG_RTNR_MAD, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_INR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_RTNR_MAD), sizeof(unsigned char));

	return flag;
}

void Scaler_Set_DEBUG_RTNR_MAD(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_RTNR_MAD);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_RTNR_MAD), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SET_DEBUG_RTNR_MAD, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_INR_log to driver fail !!!\n", ret);
		return;
	}
}

unsigned char Scaler_Get_DEBUG_HISTOGRAM_MEAN()
{
	int ret;
	unsigned char flag = FALSE;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_HISTOGRAM_MEAN);
	if (!pwTemp) {
		return flag;
	}
	ret = Scaler_SendRPC(SCALERIOC_GET_DEBUG_HISTOGRAM_MEAN, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, get Enter_INR_log from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_DEBUG_HISTOGRAM_MEAN), sizeof(unsigned char));

	return flag;
}

void Scaler_Set_DEBUG_HISTOGRAM_MEAN(unsigned char flag)
{
	int ret;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_HISTOGRAM_MEAN);
	if (!pwTemp) {
		return;
	}
	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DEBUG_HISTOGRAM_MEAN), &flag, sizeof(unsigned char));
	ret = Scaler_SendRPC(SCALERIOC_SET_DEBUG_HISTOGRAM_MEAN, 0, 0);
	if (0 != ret) {
		SLRLIB_PRINTF("ret = %d, set Enter_INR_log to driver fail !!!\n", ret);
		return;
	}
}

unsigned char Scaler_GetVIP_Dbg_Msg(void)
{
#ifdef VIPprintf
	return ucIsPrintVIP;
#else
	return 0;
#endif
}


void Scaler_SetVIP_Dbg_Msg(unsigned char flag)
{
#ifdef VIPprintf
	ucIsPrintVIP = flag;
	SLRLIB_PRINTF("VIP Debug Print = %d\n", ucIsPrintVIP);
#endif
}

unsigned char Scaler_Get_TVAutoNR_Mode()
{
	int ret;
	unsigned char flag = 0;
	unsigned char *pwTemp = (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_TVAUTONR_Mode);
	if (!pwTemp) {
		return flag;
	}

	ret = Scaler_SendRPC(SCALERIOC_GET_TVAUTONR_Mode, 0, 0);
	if (0 != ret) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, get Enter_TVAUTONR_Mode from driver fail !!!\n", ret);
		return FALSE;
	}
	/* copy from RPC share memory*/
	memcpy(&flag, (unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_TVAUTONR_Mode), sizeof(unsigned char));


	return flag;
}

INT8 COsdCtrlGet_DNR_log()
{
	return Scaler_GetDNR_log();
}
void COsdCtrlSet_DNR_log(UINT16  Message)
{
	Scaler_SetDNR_log(Message);
}
INT8 COsdCtrlGet_RTNR_log()
{
	return Scaler_GetRTNR_log();
}
void COsdCtrlSet_RTNR_log(UINT16  Message)
{
	Scaler_SetRTNR_log(Message);
}
INT8 COsdCtrlGet_SNR_log()
{
	return Scaler_GetSNR_log();
}
void COsdCtrlSet_SNR_log(UINT16  Message)
{
	Scaler_SetSNR_log(Message);
}
INT8 COsdCtrlGet_INR_log()
{
	return Scaler_GetINR_log();
}
void COsdCtrlSet_INR_log(UINT16  Message)
{
	Scaler_SetINR_log(Message);
}
INT8 COsdCtrlGet_MPEGNR_log()
{
	/*rock ==== ToDo Need the scaler to implement API*/
	return 0;
}
void COsdCtrlSet_MPEGNR_log(UINT16  Message)
{
	/*rock ==== ToDo Need the scaler to implement API*/
}

/*AUTO_NR_DEBUG*/
INT8 COsdCtrlGet_DEBUG_AUTO_NR()
{
	return Scaler_Get_DEBUG_AUTO_NR();
}
void COsdCtrlSet_DEBUG_AUTO_NR(UINT16  Message)
{
	Scaler_Set_DEBUG_AUTO_NR(Message);
}

INT8 COsdCtrlGet_DEBUG_VD_NOISE()
{
	return Scaler_Get_DEBUG_VD_NOISE();
}
void COsdCtrlSet_DEBUG_VD_NOISE(UINT16  Message)
{
	Scaler_Set_DEBUG_VD_NOISE(Message);
}

INT8 COsdCtrlGet_DEBUG_RTNR_MAD()
{
	return Scaler_Get_DEBUG_RTNR_MAD();
}
void COsdCtrlSet_DEBUG_RTNR_MAD(UINT16  Message)
{
	Scaler_Set_DEBUG_RTNR_MAD(Message);
}

INT8 COsdCtrlGet_DEBUG_HISTOGRAM_MEAN()
{
	return Scaler_Get_DEBUG_HISTOGRAM_MEAN();
}
void COsdCtrlSet_DEBUG_HISTOGRAM_MEAN(UINT16  Message)
{
	Scaler_Set_DEBUG_HISTOGRAM_MEAN(Message);
}
/*o =========================================================== o*/
/*o =================== Enginner Menu END ===================== o*/
/*o =========================================================== o*/



/*o =========================================================== o*/
/*o ==================== OSD MENU Start ======================= o*/
/*o =========================================================== o*/

#ifdef OSD_FOUR_LEVEL_MAPPING_ENABLE
unsigned char Scaler_GetFacSharpness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataFacModeType *pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Sharpness_0;
	*retval_50 = pTable->Sharpness_50;
	*retval_100 = pTable->Sharpness_100;
	*retval_25 = pTable->Sharpness_25;
	*retval_75 = pTable->Sharpness_75;
	return 0;
}

unsigned char Scaler_SetFacSharpness(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataFacModeType *pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Sharpness_0 = val_0;
	pTable->Sharpness_50 = val_50;
	pTable->Sharpness_100 = val_100;
	pTable->Sharpness_25 = val_25;
	pTable->Sharpness_75 = val_75;
	return 0;
}

unsigned char Scaler_GetFacBacklight(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100,
	unsigned char *retval_25, unsigned char *retval_75)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataFacModeType *pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Backlight_0;
	*retval_50 = pTable->Backlight_50;
	*retval_100 = pTable->Backlight_100;
	*retval_25 = pTable->Backlight_25;
	*retval_75 = pTable->Backlight_75;
	return 0;
}

unsigned char Scaler_SetFacBacklight(unsigned char val_0, unsigned char val_50, unsigned char val_100,
	unsigned char val_25, unsigned char val_75)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataFacModeType *pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Backlight_0 = val_0;
	pTable->Backlight_50 = val_50;
	pTable->Backlight_100 = val_100;
	pTable->Backlight_25 = val_25;
	pTable->Backlight_75 = val_75;
	return 0;
}
#else
unsigned char Scaler_GetFacSharpness(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Sharpness_0;
	*retval_50 = pTable->Sharpness_50;
	*retval_100 = pTable->Sharpness_100;
	return 0;
}

unsigned char Scaler_SetFacSharpness(unsigned char val_0, unsigned char val_50, unsigned char val_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Sharpness_0 = val_0;
	pTable->Sharpness_50 = val_50;
	pTable->Sharpness_100 = val_100;
	return 0;
}

unsigned char Scaler_GetFacBacklight(unsigned char *retval_0, unsigned char *retval_50, unsigned char *retval_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	*retval_0 = pTable->Backlight_0;
	*retval_50 = pTable->Backlight_50;
	*retval_100 = pTable->Backlight_100;
	return 0;
}

unsigned char Scaler_SetFacBacklight(unsigned char val_0, unsigned char val_50, unsigned char val_100)
{
	StructColorDataFacModeType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_fac_mode(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Backlight_0 = val_0;
	pTable->Backlight_50 = val_50;
	pTable->Backlight_100 = val_100;
	return 0;
}
#endif


/*o =========================================================== o*/
/*o ==================== OSD MENU End ========================= o*/
/*o =========================================================== o*/



/*for Load Quality handle*/
void Scaler_Get_Display_info(unsigned char *display, unsigned char *src_idx)
{

	*display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);

	if (SLR_MAIN_DISPLAY == *display)
		*src_idx = GET_USER_INPUT_SRC();/*only get main display src*/
	else
		*src_idx = GET_UI_SOURCE_FROM_DISPLAY(*display);/*get display info by channel*/
}

void Scaler_VIP_Project_ID_init()
{
	/*=== 20140520 CSFC for vip video fw infomation ====*/
	/* setting some information to sharememory*/
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if (NULL == VIP_RPC_system_info_structure_table)
		return;

	#if defined(IS_TV003_STYLE_PICTUREMODE)
		/*VIP_system_info_structure_table->Project_ID	= VIP_Project_ID_TV003;*/
		fwif_VIP_set_Project_ID(VIP_Project_ID_TV003);
	#elif defined(BUILD_TV010_2)
		/*VIP_system_info_structure_table->Project_ID	= VIP_Project_ID_TV010;*/
		fwif_VIP_set_Project_ID(VIP_Project_ID_TV010);
	#elif defined(BUILD_TV013_1)
		/*VIP_system_info_structure_table->Project_ID	= VIP_Project_ID_TV013;*/
		fwif_VIP_set_Project_ID(VIP_Project_ID_TV013);
	#elif defined(BUILD_TV035_1)
		/*VIP_system_info_structure_table->Project_ID	= VIP_Project_ID_TV035;*/
		fwif_VIP_set_Project_ID(VIP_Project_ID_TV035);
	#else  /* Realtek defualt used public C file*/
		#ifdef CONFIG_SUPPORT_SCALER
		 /*for Driver Base OS_System Only, ex : TvService or Web_OS, CSFC*/
		if(vpq_project_id == 0x00060000 && vpqex_project_id == 0x00060000)
			fwif_VIP_set_Project_ID(VIP_Project_ID_TV006);
		else
			fwif_VIP_set_Project_ID(VIP_Project_ID_TV001);
		#else
			/*VIP_system_info_structure_table->Project_ID	= VIP_Project_ID_TV001;*/
			fwif_VIP_set_Project_ID(VIP_Project_ID_TV001);
		#endif
	#endif

}

void Scaler_VIP_MEMC_init(unsigned char Vip_source)
{
	if ( Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == SLR_3DMODE_2D) {
		IoReg_SetBits(0xb809d030, _BIT15); /*memc hsc bypass*/
		IoReg_SetBits(0xb809d030, _BIT0);  /*memc vsc bypass*/
	}
}

void Scaler_VIP_IP_init(unsigned char Vip_source)
{
	unsigned char temptable[5] = {7, 1, 1, 1, 1};
	unsigned short temp_width =0, temp_height = 0;
	unsigned short temp_D_width =0, temp_D_height = 0;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;

	/*=== 20140520 CSFC for vip video fw infomation ====*/
	/* setting some information to sharememory*/
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	Scaler_Get_Display_info(&display, &src_idx);

	fwif_Save_PQSource((VIP_SOURCE_TIMING)Vip_source);	/*20140127 roger, set PQSource for scalercolor.cpp using*/
	fwif_Save_SWSource(Scaler_GetUserInputSrc(SLR_MAIN_DISPLAY), Scaler_GetUserInputSrc(SLR_SUB_DISPLAY));	/*20140206 roger, set SWSource for scalercolor.cpp using*/


	/* reset TNR status*/
	di_im_di_control_RBUS im_di_control_reg;
	im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	im_di_control_reg.cp_temporalenable = 0;
	im_di_control_reg.write_enable_6 = 1;
	IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
	//IoReg_ClearBits(DI_IM_DI_CONTROL_reg, DI_IM_DI_CONTROL_cp_temporalenable_mask);//_BIT23

	drvif_color_rtnr_on((SCALER_DISP_CHANNEL)display); /* enable RTNR*/
	#if CONFIG_FIRMWARE_IN_KERNEL
	if (0x00060000 != vpq_project_id || vpqex_project_id != 0x00060000)
		fwif_color_set_DCC_Init(display);
	#else
	fwif_color_set_DCC_Init(display);
	#endif

	//disable ICM bypass function
	drvif_color_icm_set_bypass_onoff(display, 0);

	drvif_color_icm_hue_histo_init();
	drvif_color_iEdgeSmooth_init();

	/* init histogram : need to init by input timing width and Len*/
	if (Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF)
		&& (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_SIDE_BY_SIDE_HALF) == TRUE))) {
		temp_width = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_MEM_ACT_WID) << 1;
	} else {
		temp_width = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_MEM_ACT_WID);
	}
	temp_height = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MEM_ACT_LEN);
	fwif_color_hist_init((SCALER_DISP_CHANNEL)display , temp_width , temp_height, Mode_Orig_32Bin);

	//D-Histogram From Merlin2, 20160630
	temp_D_width = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_WID);;
	temp_D_height = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DISP_LEN);;
#ifdef	CONFIG_HW_SUPPORT_D_HISTOGRAM
	fwif_color_D_hist_init((SCALER_DISP_CHANNEL)display, temp_D_width, temp_D_height);
#endif
	fwif_color_temptable_handler(Vip_source, temptable);

	if (VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] == 1) {
		drvif_set_main_dither();
	} else if (Scaler_InputSrcGetMainChType() == _SRC_VO || Scaler_InputSrcGetMainChType() == _SRC_HDMI) {
		if (vsc_get_adaptivestream_flag() == 1) /* cp */
			drvif_color_set_main_dither(2);
		else
			drvif_color_set_main_dither(1);	/* VO + HDMI*/
	} else {
		drvif_color_set_main_dither(0);	/* disable */
	}

	#ifdef CONFIG_HW_SUPPORT_MEMC
	//MEMC dither, for fix MEMC white window separate issue.
	//drvif_color_set_MEMC_dither();
	fwif_color_set_MEMC_dither();
	#endif
#if 0 // 1d-decontour not implemented in Mac5p, 20161219 jimmy
	/* set de-contour*/
	if (Scaler_InputSrcGetMainChType() == _SRC_VO && vsc_get_adaptivestream_flag() == 1)
		fwif_color_set_de_contour(0, 1);
	else
		fwif_color_set_de_contour(0, 0);
#endif

	#if CONFIG_FIRMWARE_IN_KERNEL
	if (0x00060000 != vpq_project_id || vpqex_project_id != 0x00060000)
		fwif_color_inv_gamma_init();
	#else
	fwif_color_inv_gamma_init();
	#endif
	/*DI Pan init*/
	if (Vip_source == VIP_QUALITY_TV_NTSC || Vip_source == VIP_QUALITY_TV_PAL) {
		drvif_color_ma_Pan_Detection(0);
	} else {
		drvif_color_ma_Pan_Detection(1);
	}

	if (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) >1920)
	{
		drvif_color_DRV_MCNR_TMV(2);

	}
	else if (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 720)
	{
		drvif_color_DRV_MCNR_TMV(1);
	}
	else
	{
		drvif_color_DRV_MCNR_TMV(0);
 	}


	fwif_color_set_MPEG_init();

	#ifdef ENABLE_RTK_DCR //DCR GDBC init
		VIP_system_info_structure_table->RTK_DCR_Enable = 1;
		Scaler_SetBackLightMappingRange(100,0,255,0,1);
	#else
		VIP_system_info_structure_table->RTK_DCR_Enable = 0;
	#endif

	di_di_smd_choosecandidate_RBUS 	smd_choosecandidate_reg;
	smd_choosecandidate_reg.regValue = IoReg_Read32(DI_DI_SMD_ChooseCandidate_reg);
	if( Vip_source == VIP_QUALITY_DTV_576I ){
		smd_choosecandidate_reg.smd_reliablerange_sad_th = 100;
	} else {
		smd_choosecandidate_reg.smd_reliablerange_sad_th = 125;
	}
	IoReg_Write32(DI_DI_SMD_ChooseCandidate_reg, smd_choosecandidate_reg.regValue);

}

unsigned char Scaler_GetMA_Chroma_Error(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MA_Chroma_Error;

}
/*range 0~10*/
void Scaler_SetMA_Chroma_Error(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MA_Chroma_Error = value;

	fwif_color_set_MA_Chroma_Error(src_idx, value);
}

unsigned char Scaler_GetMA_Chroma_Error_En_From_vipTable(void)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	unsigned char *pVipCoefArray = NULL;
	Scaler_Get_Display_info(&display, &src_idx);

	if (m_cbFunc_getQualityCoef == NULL)
		return 0;

	pVipCoefArray = (unsigned char *)m_cbFunc_getQualityCoef((VIP_SOURCE_TIMING)fwif_vip_source_check(3, NOT_BY_DISPLAY));

	return fwif_color_get_MA_Chroma_Error_en_from_vipTable(src_idx, pVipCoefArray[VIP_QUALITY_FUNCTION_MA_Chroma_Error]);
}

unsigned char Scaler_GetMADI_HMC(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MADI_HMC;

}
/*range 0~6*/
void Scaler_SetMADI_HMC(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MADI_HMC = value;

	fwif_set_color_MADI_HMC(src_idx, value);
}

unsigned char Scaler_GetMADI_HME(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MADI_HME;

}
/*range 0~6*/
void Scaler_SetMADI_HME(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MADI_HME = value;

	fwif_set_color_MADI_HME(src_idx, value);
}

unsigned char Scaler_GetMADI_PAN(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MADI_PAN;

}
/*range 0~6*/
void Scaler_SetMADI_PAN(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MADI_PAN = value;

	fwif_set_color_MADI_PAN(src_idx, value);
}

unsigned char Scaler_GetNew_UVC(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->color_new_uvc;

}
/*range 0~3*/
void Scaler_SetNew_UVC(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->color_new_uvc = value;

	fwif_color_set_new_uvc(src_idx, value);
}

unsigned char Scaler_GetDLti(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->DLti;

}


/*range 0~10*/
void Scaler_SetDLti(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->DLti = value;

	fwif_color_set_dlti_driver(src_idx, value);
}

unsigned char Scaler_GetDCti(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->DCti;
}

/*range 0~10*/
void Scaler_SetDCti(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->DCti = value;

	fwif_color_set_dcti(src_idx, value);
}

unsigned char Scaler_GetIDLti(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->I_DLTi;

}

void Scaler_SetIDLti(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->I_DLTi = value;

}

unsigned char Scaler_GetIDCti(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->I_NEWDCTi;

}

/*range 0~6*/
void Scaler_SetIDCti(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->I_NEWDCTi = value;

	fwif_color_set_inewdcti(src_idx, value);


}

unsigned char Scaler_GetVDCti(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->V_DCTi;
}

/*range 0~10*/
void Scaler_SetVDCti(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->V_DCTi = value;

	fwif_color_set_v_dcti_driver(src_idx, value);
}

unsigned char Scaler_GetVDCti_LPF(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->V_DCTi_Lpf;
}

void Scaler_SetVDCti_LPF(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->V_DCTi = value;

	fwif_color_set_v_dcti_lpf_driver(src_idx, value);
}


unsigned char Scaler_GetColor_UV_Delay_Enable()
{
	return drvif_color_Get_Color_UV_Delay_Enable();
}

void Scaler_SetColor_UV_Delay_Enable(unsigned char on_off)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	fwif_color_UV_Delay_Enable(src_idx, on_off);
}

unsigned char Scaler_GetColor_UV_Delay()
{
	return fwif_color_get_UV_Delay();
}

void Scaler_SetColor_UV_Delay(unsigned char value)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	fwif_color_set_UV_Delay(src_idx, value);
}

void Scaler_SetColor_UV_Delay_TOP(unsigned char value)
{

	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display,& src_idx);

	fwif_color_set_UV_Delay_TOP(src_idx,value);

}


unsigned char Scaler_GetFilm_Mode()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Film;

}

void Scaler_SetFilm_Mode(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Film = value;

	fwif_module_set_film_mode(src_idx, value);
}

void Scaler_SetFilmonoff(unsigned char value)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	if (value == 0) /* off*/
		fwif_module_set_film_mode(src_idx, value);
	else /* on*/
		fwif_module_set_film_mode(src_idx, Scaler_GetFilm_Mode());
}

void Scaler_SetFilm_Setting(void)
{
	fwif_module_set_film_setting();
}


unsigned char Scaler_GetIntra(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Intra;

}

/*range 0~11*/
void Scaler_SetIntra(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_THRIP) == 0) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "Warning!! Scaler_SetIntra not through IP\n");
		return;
	}

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Intra = value;

	if (value == 0 || value >= 255) {   /* Intra off*/

		fwif_color_set_Intra_Ver2_driver(src_idx, 0);
	} else if (value < VipPQ_GetIntra_Ver2_TableSize()) {     /*new  Intra*/
		fwif_color_set_Intra_Ver2_driver(src_idx, value);
	} else {                                                 /*old  Intra*/
		fwif_color_set_Intra_Ver2_driver(src_idx, 0);
	}
}

unsigned char Scaler_GetMADI(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->MotionAdaptive;
}

void Scaler_SetMADI(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_SetMADI, value = %d\n", value);

	if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_THRIP) == 0) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "Warning!! Scaler_SetMADI not through IP\n");
		return;
	}

	if(Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane()) == SOURCE_ENCODER) {
		value = 6;
	}

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->MotionAdaptive = value;

	fwif_color_ma_set_DI_MA_Adjust_Table(src_idx, value);

}

void Scaler_SetMADI_INIT()
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	/* Hard code "2"  comes from original init setting in past FW code*/
	fwif_color_ma_set_DI_MA_Adjust_Table(src_idx, 2); /* Init setting from original code*/
	fwif_color_ma_set_DI_MA_Init_Table();
}



unsigned char Scaler_GetTNRXC_Ctrl(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->tnr_xc_ctrl;
}

void Scaler_SetTNRXC_Ctrl(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->tnr_xc_ctrl = value;
	fwif_color_set_TNRXC_Ctrl(src_idx, value);
}
unsigned char Scaler_GetTNRXC_MK2(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->tnrxc_mk2;
}

void Scaler_SetTNRXC_MK2(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	/*unsigned char display = 0;*/

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->tnrxc_mk2 = value;
	fwif_color_set_TNRXC_MK2(src_idx, value);
}
void Scaler_SetTNRXC(unsigned char value)
{
	Scaler_SetTNRXC_Ctrl(value);
	Scaler_SetTNRXC_MK2(value);
}


void Scaler_SetDataFormatHandler(void)
{
	unsigned char en_422to444, InputSrcGetType, InputSrcGetFrom;
	unsigned short mode, channel;
	SCALER_DISP_CHANNEL display;

	mode = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	display = (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	channel = Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL);
	en_422to444 = (unsigned char)Scaler_DispGetStatus(display, SLR_DISP_422);
	InputSrcGetType = Scaler_InputSrcGetType(display);

#ifdef CONFIG_FORCE_RUN_I3DDMA
	/*
	if((display == SLR_MAIN_DISPLAY) && (get_force_i3ddma_enable(display) == true))
		InputSrcGetType = _SRC_VO;
	else
		InputSrcGetType = Scaler_InputSrcGetType(display);
	*/
	if (fwif_color_get_force_run_i3ddma_enable(display)) {
		fwif_color_vsc_to_scaler_src_mapping(Get_DisplayMode_Src(display), &InputSrcGetType, &InputSrcGetFrom);
		mode = fwif_color_get_cur_input_timing_mode(SLR_MAIN_DISPLAY);
	}
#endif
	if (vpq_project_id != 0x00060000 || vpqex_project_id != 0x00060000)
		fwif_color_SetDataFormatHandler(display, mode, channel, en_422to444, InputSrcGetType);
	else
		fwif_color_SetDataFormatHandler_tv006();

}

unsigned char Scaler_get_YUV2RGB(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 255;		/* skip this function if table 255 is selected.*/
	return pTable->YUV2RGB_Table_Select;
}

void Scaler_set_YUV2RGB(unsigned char which_table, unsigned char drvSkip_Flag_coefByY, unsigned char drvSkip_Flag_uvOffset)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->YUV2RGB_Table_Select = which_table;
	VIPprintf("which_table = %d, drvif_write_flag = %d,%d\n", which_table, drvSkip_Flag_coefByY, drvSkip_Flag_uvOffset);

	fwif_color_set_YUV2RGB(src_idx, display, which_table, drvSkip_Flag_coefByY, drvSkip_Flag_uvOffset);

}
#if 0
unsigned char Scaler_get_YUV2RGB_COEF_BY_Y(void)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 255;		/* skip this function if table 255 is selected.*/
	return pTable->YUV2RGB_COEF_BY_Y_Table_Select;
}

void Scaler_set_YUV2RGB_COEF_BY_Y(unsigned char which_table, unsigned char drvSkip_Flag)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->YUV2RGB_COEF_BY_Y_Table_Select = which_table;
	VIPprintf("which_table = %d, drvif_write_flag = %d\n", which_table, drvSkip_Flag);
	if (drvSkip_Flag == 1)
		return;

	/* this path need to remove future. using "fwif_color_set_YUV2RGB_COEF_BY_Y" directly*/
	/*fwif_color_set_YUV2RGB_COEF_BY_Y_driver(src_idx, which_table);*/
	fwif_color_set_YUV2RGB_COEF_BY_Y(src_idx, display, which_table);

}

unsigned char Scaler_get_YUV2RGB_UV_OFFSET_BY_Y(void)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 255;		/* skip this function if table 255 is selected*/
	return pTable->YUV2RGB_UV_OFFSET_BY_Y_Table_Select;

}

void Scaler_set_YUV2RGB_UV_OFFSET_BY_Y(unsigned char which_table, unsigned char drvSkip_Flag)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	StructColorDataType *pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->YUV2RGB_UV_OFFSET_BY_Y_Table_Select = which_table;

	if (drvSkip_Flag == 1)
		return;

	/* this path need to remove future. using "fwif_color_set_YUV2RGB_UV_OFFSET_BY_Y" directly*/
	/*fwif_color_set_YUV2RGB_UV_OFFSET_BY_Y_driver(src_idx, which_table);*/
	fwif_color_set_YUV2RGB_UV_OFFSET_BY_Y(src_idx, display, which_table);

}
#endif


void Scaler_module_vdc_SetConBriHueSat_Table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if ((VIP_system_info_structure_table->Input_src_Form) !=  _SRC_FROM_VDC) {
		VIPprintf("Warning!! It's not vdc Src !!");
		return;
	}

	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->VD_ConBriHueSat_Table = value;

	fwif_color_module_vdc_SetConBriHueSat(src_idx, value);

}
unsigned char Scaler_module_vdc_GetConBriHueSat_Table(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;

	if (Scaler_InputSrcGetMainChFrom() == _SRC_FROM_VDC) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "Warning!! It's not vdc Src !!");
		return 255;
	}

	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->VD_ConBriHueSat_Table;
}


unsigned char Scaler_get_ICM_table()
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	StructColorDataType *pTable = NULL;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	/*VIPprintf("@@@@@@@@=== 1.fwif_color_get_ICM_table ==\n");*/
	if (pTable == NULL)
		return 0;
	/*VIPprintf("@@@@@@@@=== 2.fwif_color_get_ICM_table = %d ==\n", pTable->ICM_Table);*/
	return pTable->ICM_Table;
}

void Scaler_set_ICM_table(unsigned char value, unsigned char drvSkip_Flag)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	StructColorDataType *pTable = NULL;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ICM_Table = value;

	if (drvSkip_Flag == 1)
		return;

	fwif_color_set_ICM_table(src_idx,  value);
}

void Scaler_set_ICM_table_by_VipTable(void)
{
	unsigned char source;
	unsigned char *pVipCoefArray;
	unsigned char *drvSkip_Array;
	SLR_VIP_TABLE *gVIP_Table;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	if (m_cbFunc_getQualityExtend3 == NULL)
		return;

	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)source);

	if (source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)
		return;

	gVIP_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (NULL == gVIP_Table)
		return;

	drvSkip_Array = &(gVIP_Table->DrvSetting_Skip_Flag[0]);
	Scaler_set_ICM_table(pVipCoefArray[VIP_QUALITY_FUNCTION_ICM],  0);
}


unsigned char Scaler_GetGamma(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Gamma;
}


void Scaler_SetGamma(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Gamma = value;

	fwif_set_gamma(pTable->Gamma, pTable->Sindex, pTable->Shigh, pTable->Slow);
}

unsigned char Scaler_GetSindex(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Sindex;
}

unsigned char Scaler_SetSindex(unsigned short value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Sindex = value;

	fwif_set_gamma(pTable->Gamma, pTable->Sindex, pTable->Shigh, pTable->Slow);
	return 0;
}

unsigned char Scaler_GetSlow(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Slow;
}

/*range 0~3*/
unsigned char Scaler_SetSlow(unsigned short value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Slow = value;

	fwif_set_gamma(pTable->Gamma, pTable->Sindex, pTable->Shigh, pTable->Slow);
	return 0;
}

unsigned char Scaler_GetShigh(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Shigh;
}

/*range 0~3*/
unsigned char Scaler_SetShigh(unsigned short value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 1;
	pTable->Shigh = value;

	fwif_set_gamma(pTable->Gamma, pTable->Sindex, pTable->Shigh, pTable->Slow);
	return 0;
}

/*20140212 roger, for avoid to write gamma table 4 times, for fwif_color_video_quality_handler only*/
void Scaler_SetGamma_for_Handler(unsigned char gamma,
															unsigned char s_gamma_index,
															unsigned char s_gamma_low,
															unsigned char s_gamma_high, unsigned char drvSkip_Flag)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;

	pTable->Gamma = gamma;
	pTable->Sindex = s_gamma_index;
	pTable->Slow = s_gamma_low;
	pTable->Shigh = s_gamma_high;

	if (drvSkip_Flag == 1)
		return;

	fwif_set_gamma(pTable->Gamma, pTable->Sindex, pTable->Shigh, pTable->Slow);

}

unsigned char Scaler_Get_blue_stretch(void)
{
#if 1
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->blue_stretch;
#else
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if (m_cbFunc_getQualityExtend3 != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)VIP_system_info_structure_table->VIP_source);

	return pVipCoefArray[VIP_QUALITY_FUNCTION_blue_stretch];

#endif

}

void Scaler_set_blue_stretch(unsigned char table)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->blue_stretch = table;

	fwif_color_set_blue_stretch(src_idx, table);
}

unsigned short Scaler_GetSharpnessTable()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Shp_Table;
}

void Scaler_SetSharpnessTable(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);

	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "fwif_color_set_sharpness_table error %d \n", value);
		return;
	}
	if (value >= Sharp_table_num)
		value = 0;

	pTable->Shp_Table = value;
	if (vpq_project_id == 0x00060000 && vpqex_project_id == 0x00060000) {
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "fwif_color_set_sharpness_table TV006 %d \n", value);*/
		fwif_color_set_sharpness_table_init_TV006(src_idx, value);
	} else {
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "fwif_color_set_sharpness_table TV001 %d \n", value);*/
		fwif_color_set_sharpness_table(src_idx, value);
	}

}
unsigned short Scaler_GetCDSTable()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->CDS_Table;

}
void Scaler_SetCDSTable(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	Table_CDS = value;

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->CDS_Table = value;

	fwif_color_set_cds_table(src_idx, value);
}

unsigned short Scaler_GetEGSM_postshp_level()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Egsm_postshp_level;
}

void Scaler_SetEGSM_postshp_level(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	if (display != SLR_MAIN_DISPLAY) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "Warning!! Dering have to working in SLR_MAIN_DISPLAY!! ");
		rtd_printk(KERN_DEBUG, TAG_NAME, "Return!! ");
		return;
	}

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Egsm_postshp_level = value;

	fwif_color_set_egsm_postshp_level_driver(src_idx, value);


}

unsigned char Scaler_GetEMF_Mk2()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->emf_mk2;
}

void Scaler_SetEMF_Mk2(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->emf_mk2 = value;

	fwif_color_set_emf_mk2_driver(src_idx, value);

}

unsigned char Scaler_GetSKIPIR_Ring()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->SKIPIR_ring;
}

void Scaler_SetSKIPIR_Ring(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->SKIPIR_ring = value;

	fwif_color_set_skipir_ring_driver(src_idx, value);
}

unsigned char Scaler_GetSKIPIR_Dnoise()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->SKIPIR_dnoise;
}

void Scaler_SetSKIPIR_Dnoise(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->SKIPIR_dnoise = value;

	fwif_color_set_skipir_dnoise(src_idx, value);
}

unsigned short Scaler_GetskipirdnoiseTable()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->SKIPIR_dnoise_table;

}

void Scaler_SetskipirdnoiseTable(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->SKIPIR_dnoise_table = value; /*switch Dnoise table*/
										/*get current SKIPIR_Dnoise value then Reset vale*/

	fwif_color_set_skipir_dnoise_table(src_idx, value);

}


unsigned char Scaler_get_Adaptive_Gamma(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Adaptive_Gamma;
}

void Scaler_set_Adaptive_Gamma(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Adaptive_Gamma = value;
	fwif_color_set_Adaptive_Gamma(src_idx, value);
}

unsigned char Scaler_GetRTNR_Noise_Measure(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->RTNR_NM;
}

void Scaler_SetRTNR_Noise_Measure(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->RTNR_NM = value;

	fwif_color_set_RTNR_Noise_Measure_flow(src_idx, value);
}

unsigned char Scaler_GetScaleUPH(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleUpH;
}

void Scaler_SetScaleUPH(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUpH = value;

	fwif_color_set_scaleup_hcoef(src_idx, display, value);
}

unsigned char Scaler_GetScaleUPH_8tap(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleUpH_8tap;
}

/*range 0~11*/
void Scaler_SetScaleUPH_8tap(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUpH_8tap = value;


	fwif_color_set_scaleuph_8tap_driver(src_idx, display, value);

}

unsigned char Scaler_GetScaleUPV(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleUpV;
}

/*range 0~10*/
void Scaler_SetScaleUPV(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUpV = value;

	fwif_color_set_scaleup_vcoef(src_idx, display, value);
}

void Scaler_SetScaleUP_YCHV(unsigned char HY, unsigned char VY, unsigned char HC, unsigned char VC)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUpH = HY;
	pTable->ScaleUpV = VY;

	fwif_color_set_scaleup_hv4tap_coef(src_idx, display, (char)HY, (char)VY, (char)HC, (char)VC);
}

void Scaler_GetScaleUP_YCHV(unsigned char *pHY,unsigned char *pVY,unsigned char *pHC,unsigned char *pVC)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	*pHY = pTable->ScaleUpH;
	*pVY = pTable->ScaleUpV;
	*pHC = pTable->ScaleUpH_C;
	*pVC = pTable->ScaleUpV_C;

}


unsigned char Scaler_GetScaleUPDir(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleUpDir;

}

/*range 0~19*/
void Scaler_SetScaleUPDir(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUpDir = value;

	fwif_color_set_scaleup_dircoef(src_idx, display, value);
}

unsigned char Scaler_GetScaleUPDir_Weighting(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleUpDir_weighting;

}

/*range 0~9*/
void Scaler_SetScaleUPDir_Weighting(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUpDir_weighting = value;

	fwif_color_set_scaleup_dir_weighting_driver(src_idx, value);
}

unsigned char Scaler_GetScalePK(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScalePK;
}

/*range 0~10*/
void Scaler_SetScalePK(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScalePK = value;
	fwif_color_set_scalepk_driver(src_idx, value);
}
unsigned short Scaler_GetSUPKType()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->SUPK_type;
}

void Scaler_SetSUPKType(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->SUPK_type = value;

	fwif_color_set_supk_type_driver(src_idx, value);
}
unsigned short Scaler_GetUnsharpMask()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->UnsharpMask;
}
void Scaler_SetUnsharpMask(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;

	pTable->UnsharpMask = value;


	fwif_color_set_unsharp_mask_driver(src_idx, value);
}



unsigned char Scaler_get_egsm_postshp_table()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Egsm_Postshp_table;
}

void Scaler_color_egsm_postshp_table(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	if (display == SLR_MAIN_DISPLAY) {
		Table_EGSM_Postshp = value;
	}

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Egsm_Postshp_table = value;

	fwif_color_set_egsm_postshp_level_driver(_MAIN_DISPLAY, Scaler_GetEGSM_postshp_level());/* cheange table need to re-set level*/
}
unsigned char Scaler_getdESM(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Egsm_Postshp_table;
}
void Scaler_setdESM(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Egsm_Postshp_table = value;

	fwif_color_set_dESM(display, value);
}

unsigned char Scaler_getiESM(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->iESM;
}


void Scaler_setiESM(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->iESM = value;

	fwif_color_set_iESM(display, value);
}

#ifdef ENABLE_SUPER_RESOLUTION
void Scaler_set_SuperResolution_init_table(unsigned char value)
{
	fwif_color_set_SuperResolution_init_table(value);
}

unsigned char Scaler_GetSR_edge_gain(void)
{
	StructColorDataType *pTable = NULL;
    unsigned char src_idx = 0;
    unsigned char display = 0;
    Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->SR_edge_gain;
}

void Scaler_SetSR_edge_gain(unsigned char value)
{
	StructColorDataType *pTable = NULL;
    unsigned char src_idx = 0;
    unsigned char display = 0;
    Scaler_Get_Display_info(&display, &src_idx);

	SR_edge_gain = value;

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->SR_edge_gain = value;

	fwif_color_set_SR_edge_gain(src_idx, value);
}

unsigned char Scaler_GetSR_texture_gain(void)
{
	StructColorDataType *pTable = NULL;
    unsigned char src_idx = 0;
    unsigned char display = 0;
    Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->SR_texture_gain;
}

/*range 0~1, Lydia*/
void Scaler_SetSR_texture_gain(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	SR_texture_gain = value;

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->SR_texture_gain = value;

	fwif_color_set_SR_texture_gain(GET_USER_INPUT_SRC(), value);
}
#endif

unsigned char Scaler_GetScaleDOWNHTable(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleDownHTable;
}

/*range 0~17*/
void Scaler_SetScaleDOWNHTable(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	/*unsigned char ucScaleDownH = 0;*/
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);


	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleDownHTable = value;

	fwif_color_set_scaledownh_table(GET_USER_INPUT_SRC(), value);
}
unsigned char Scaler_GetScaleDOWNVTable(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleDownVTable;
}

/*range 0~17*/
void Scaler_SetScaleDOWNVTable(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleDownVTable = value;

	fwif_color_set_scaledownv_table(GET_USER_INPUT_SRC(), value);
}
unsigned char Scaler_GetScaleDOWN444To422(void)
{
	return fwif_color_get_scaledown444To422(GET_USER_INPUT_SRC());
}

/*range 0~17*/
void Scaler_SetScaleDOWN444To422(unsigned char value)
{
	fwif_color_set_scaledown444To422(GET_USER_INPUT_SRC(), value);
}


unsigned char Scaler_GetScaleUPV_6tap(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleUpV_6tap;
}
#if 0 // henry @ mac5 161221
 void Scaler_SetScaleUP_TwoStep(unsigned char value)
 {
 	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;

	Scaler_Get_Display_info(&display,& src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUP_TwoStep= value;
	
 	fwif_color_set_twostep_scaleup_coef( src_idx, display, value);
 }

unsigned char Scaler_GetScaleUP_TwoStep(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->ScaleUP_TwoStep;
}
#endif


/*range 0~10*/
void Scaler_SetScaleUPV_6tap(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->ScaleUpV_6tap = value;

	fwif_color_set_scaleupv_6tap_driver(src_idx, display, value);
}

unsigned short Scaler_GetDeRing()
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Dering;

}

void Scaler_SetDeRing(unsigned short value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	if (display != SLR_MAIN_DISPLAY) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "Warning!! Dering have to working in SLR_MAIN_DISPLAY!! ");
		rtd_printk(KERN_DEBUG, TAG_NAME, "Return!! ");
		return;
	}

	NR_HW_Dering_Level = value;

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Dering = value;

	fwif_color_set_dering_driver(src_idx, value);
}
unsigned char Scaler_GetDiSmd(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->DISMDTable;
}

void Scaler_SetDiSmd(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	if (display != SLR_MAIN_DISPLAY) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "Warning!! DI SMD have to working in SLR_MAIN_DISPLAY!! ");
		rtd_printk(KERN_DEBUG, TAG_NAME, "Return!! ");
		return;
	}

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->DISMDTable = value;

	fwif_color_set_dismd_driver(src_idx, value);
}

void Scaler_SetScaleOSD_Sharpness(unsigned char value)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->OSD_Sharpness = value;

	fwif_color_set_scaleosd_sharpness_driver(src_idx, value);
}


unsigned char Scaler_GetScaleOSD_Sharpness(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->OSD_Sharpness;
}


unsigned char Scaler_Debug_Get_UserCurveDCC_Curve_Select(void)
{
	return fwif_color_Debug_Get_UserCurveDCC_Curve_Select();
}

unsigned char Scaler_Debug_Get_HIST_MEAN_VALUE(void)
{
	return fwif_color_Debug_Get_HIST_MEAN_VALUE();
}

unsigned char Scaler_Debug_Get_Pure_Color_Flag(void)
{
	return fwif_color_Debug_Get_Pure_Color_Flag();
}

unsigned char Scaler_Debug_Get_Skin_Tone_Found_Flag(void)
{
	return fwif_color_Debug_Get_Skin_Tone_Found_Flag();
}

unsigned char Scaler_Debug_Get_UserCurveDCC_Curve_Weighting(void)
{
	return fwif_color_Debug_Get_UserCurveDCC_Curve_Weighting(Main_DCC_User_Define_Curve_Table_Select);
}

unsigned char Scaler_Debug_Get_UserCurveDCC_Curve_Weighting_Skin(void)
{
	return fwif_color_Debug_Get_UserCurveDCC_Curve_Weighting_Skin(Main_DCC_User_Define_Curve_Table_Select);
}

void Scaler_Debug_Set_UserCurveDCC_Curve_Select(unsigned char value)
{
	fwif_color_Debug_Set_UserCurveDCC_Curve_Select(value);
}

void Scaler_Debug_Set_UserCurveDCC_Curve_Apply(unsigned char value)
{
	fwif_color_Debug_Set_UserCurveDCC_Curve_Apply(Main_DCC_User_Define_Curve_Table_Select, value);
}

void Scaler_Debug_Set_UserCurveDCC_Curve_Weighting(unsigned char value)
{
	fwif_color_Debug_Set_UserCurveDCC_Curve_Weighting(Main_DCC_User_Define_Curve_Table_Select, value);
}

void Scaler_Debug_Set_UserCurveDCC_Curve_Weighting_Skin(unsigned char value)
{
	fwif_color_Debug_Set_UserCurveDCC_Curve_Weighting_Skin(Main_DCC_User_Define_Curve_Table_Select, value);
}

void Scaler_set_pq_dir_path(char *path, char *patch_path)
{
	fwif_set_pq_dir_path(path, patch_path);
}
unsigned char Scaler_get_average_luma(unsigned char *val)
{
	fwif_get_average_luma(val);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_get_average_luma = %d\n", *val);
	return 1;
}

unsigned char Scaler_get_Y_Total_Hist_Cnt_distribution(UINT8 MODE, UINT8 size, unsigned int *Y_Hist_distr_cnt)
{
	return fwif_get_Y_Total_Hist_Cnt_distribution(MODE, size, &Y_Hist_distr_cnt[0]);
}

unsigned char Scaler_get_luma_level_distribution(unsigned short *luma_distribution, unsigned char size)
{
	int i = 0;
	fwif_get_luma_level_distribution(luma_distribution,  size);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_get_luma_level_distribution\n");

	for (i = 0; i < size; i++) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "\n luma_distribution[%d] = %d ", i, luma_distribution[i]);
	}
	return 1;
}

/**
 * Panel_SetBackLightRange
 * mapping uiMax to actMax,uiMin to actMin,and use uiStep as step size when use Panel_SetBackLightLevel
 *
 * @param {uiMax : 0~255,default 100}
 * @param {uiMin : 0~255,default 0}
 * @param {uiMax : 0~255,default 255}
 * @param {uiMin : 0~255,default 0}
 * @return {TRUE/FALSE }
 *
 */
unsigned char Scaler_SetBackLightMappingRange(unsigned int uiMax, unsigned int uiMin,
							unsigned int actMax, unsigned int actMin,unsigned char increaseMode)
{

	if( (actMax>255) || (actMin>255) || (actMax<=actMin))
		return FALSE;

	if( (uiMax>255) || (uiMin>255) || (uiMax<=uiMin) )
		return FALSE;

	/*=== 20140421 CSFC for vip video fw infomation ====*/
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	VIP_system_info_structure_table->OSD_Info.backlightLevel_actMax = actMax;
	VIP_system_info_structure_table->OSD_Info.backlightLevel_actMin = actMin;
	VIP_system_info_structure_table->OSD_Info.backlightLevel_uiMax = uiMax;
	VIP_system_info_structure_table->OSD_Info.backlightLevel_uiMin = uiMin;
	VIP_system_info_structure_table->OSD_Info.isIncreaseMode_Flag = increaseMode;


	return TRUE;
}

unsigned char Scaler_GetBackLightMappingRange(unsigned int *uiMax,unsigned int *uiMin,unsigned int *actMax,unsigned int *actMin, unsigned char *increaseMode)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}
	*uiMax		= VIP_system_info_structure_table->OSD_Info.backlightLevel_actMax;
	*uiMin		= VIP_system_info_structure_table->OSD_Info.backlightLevel_actMin;
	*actMax		= VIP_system_info_structure_table->OSD_Info.backlightLevel_uiMax;
	*actMin		= VIP_system_info_structure_table->OSD_Info.backlightLevel_uiMin;
	*increaseMode 	= VIP_system_info_structure_table->OSD_Info.isIncreaseMode_Flag;

	return TRUE;
}

unsigned char Scaler_GetDcrMode(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;

	return pData->DCRMode;
}

void Scaler_SetDcrMode(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;

	pData->DCRMode= value;

	Scaler_set_DCR_Enable(value);
}

unsigned char Scaler_SetOSDBacklight2VIP(unsigned char value)
{
#if 0
#ifdef CONFIG_PCBMGR
	static unsigned int m_PIN_BL_ADJ = 0xFFFFFFFF;
	int index, type;
	unsigned long long enum_info = 0;
	unsigned int 	uiMax;
	unsigned int 	uiMin;
	unsigned int 	actMax;
	unsigned int 	actMin;
	unsigned char 	increaseMode;
#endif
#endif
	/*=== 20140421 CSFC for vip video fw infomation ====*/
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	VIP_system_info_structure_table->OSD_Info.OSD_Backlight = value;

#if 0
#ifdef CONFIG_PCBMGR
	if (m_PIN_BL_ADJ == 0xFFFFFFFF) {
		if (pcb_mgr_get_enum_info_byname("PIN_BL_ADJ", &enum_info) < 0) {
			m_PIN_BL_ADJ = 0xFFFFFFFF;
			VIP_system_info_structure_table->OSD_Info.backlight_pin_adj = 0;
		} else {
			if (PCB_PIN_TYPE_ISO_GPIO == GET_PIN_TYPE(enum_info) || PCB_PIN_TYPE_ISO_PWM == GET_PIN_TYPE(enum_info) || PCB_PIN_TYPE_ISO_UNIPWM == GET_PIN_TYPE(enum_info))
				type = 1;
			else
				type = 0;
			index = GET_PIN_INDEX(enum_info);
			m_PIN_BL_ADJ =  ((type & 0xFFFF) << 16) | (index & 0xFFFF);
			VIP_system_info_structure_table->OSD_Info.backlight_pin_adj = fwif_color_ChangeOneUINT32Endian(m_PIN_BL_ADJ, 0);
		}
	}
#endif
#endif

#if 0
	Panel_GetBackLightMappingRange(&uiMax, &uiMin, &actMax, &actMin, &increaseMode);

	VIP_system_info_structure_table->OSD_Info.backlightLevel_actMax = actMax;
	VIP_system_info_structure_table->OSD_Info.backlightLevel_actMin = actMin;
	VIP_system_info_structure_table->OSD_Info.backlightLevel_uiMax = uiMax;
	VIP_system_info_structure_table->OSD_Info.backlightLevel_uiMin = uiMin;
	VIP_system_info_structure_table->OSD_Info.isIncreaseMode_Flag = increaseMode;

#endif

	return TRUE;
}




void Scaler_set_DCR_Enable(UINT8 value)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	VIP_system_info_structure_table->OSD_Info.OSD_DCR_Mode = value;

}

UINT8 Scaler_get_DCR_Enable(void)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}
	return VIP_system_info_structure_table->OSD_Info.OSD_DCR_Mode;

}

UINT32 Scaler_get_DCC_AdapCtrl_Current_Mean(void)
{
	unsigned int pwCopyTemp = 0;
	_clues *VIP_SmartPic_clues = NULL;
	VIP_SmartPic_clues = fwif_color_GetShare_Memory_SmartPic_clue();

	if (VIP_SmartPic_clues == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get Scaler_get_DCC_AdapCtrl_Mean Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	fwif_color_ChangeUINT32Endian_Copy(&(VIP_SmartPic_clues->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_mean]), 1, &pwCopyTemp, 0);

	return pwCopyTemp;
}

UINT32 Scaler_get_DCC_AdapCtrl_Current_Dev(void)
{
	unsigned int pwCopyTemp = 0;
	_clues *VIP_SmartPic_clues = NULL;
	VIP_SmartPic_clues = fwif_color_GetShare_Memory_SmartPic_clue();

	if (VIP_SmartPic_clues == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get Scaler_get_DCC_AdapCtrl_Dev Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	fwif_color_ChangeUINT32Endian_Copy(&(VIP_SmartPic_clues->Adapt_DCC_Info.Adapt_Mean_Dev_info[DCC_Tool_Dev]), 1, &pwCopyTemp, 0);

	return pwCopyTemp;
}

VIP_DCC_AdaptCtrl_Level_Table *Scaler_get_DCC_AdapCtrl_Table(void)
{
	unsigned char AdaptCtrl_Level_Table = 0;
	SLR_VIP_TABLE *prt = fwif_color_GetShare_Memory_VIP_TABLE_Struct();
	if (prt == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdaptCtrl_Level_Table = Scaler_Get_DCC_AdaptCtrl_Level_Table();

	return &(prt->DCC_Control_Structure.DCC_AdaptCtrl_Level_Table[AdaptCtrl_Level_Table]);

}


unsigned char Scaler_get_DCC_AdapCtrl_DCC_Level(void)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	return (DCC_AdaptCtrl_Level_Table->DCC_Level_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev];

}

BOOL Scaler_set_DCC_AdapCtrl_DCC_Level(UINT8 value)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	(DCC_AdaptCtrl_Level_Table->DCC_Level_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev] = value;
	fwif_color_set_DCC_SC_for_Coef_Change(1, 1);

	return TRUE;


}


unsigned char Scaler_get_DCC_AdapCtrl_Cubic_index(void)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	return (DCC_AdaptCtrl_Level_Table->DCC_Cublc_Index_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev];

}

BOOL Scaler_set_DCC_AdapCtrl_Cubic_index(UINT8 value)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	(DCC_AdaptCtrl_Level_Table->DCC_Cublc_Index_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev] = value;

	fwif_color_set_DCC_SC_for_Coef_Change(1, 1);

	return TRUE;

}


unsigned char Scaler_get_DCC_AdapCtrl_Cubic_low(void)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	return (DCC_AdaptCtrl_Level_Table->DCC_Cublc_Low_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev];
}

BOOL Scaler_set_DCC_AdapCtrl_Cubic_low(UINT8 value)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	(DCC_AdaptCtrl_Level_Table->DCC_Cublc_Low_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev] = value;
	fwif_color_set_DCC_SC_for_Coef_Change(1, 1);

	return TRUE;

}

unsigned char Scaler_get_DCC_AdapCtrl_Cubic_high(void)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	return (DCC_AdaptCtrl_Level_Table->DCC_Cublc_High_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev];
}

BOOL Scaler_set_DCC_AdapCtrl_Cubic_high(UINT8 value)
{
	unsigned int AdapCtrl_Current_Mean = 0, AdapCtrl_Current_Dev = 0;
	VIP_DCC_AdaptCtrl_Level_Table *DCC_AdaptCtrl_Level_Table = NULL;

	DCC_AdaptCtrl_Level_Table = Scaler_get_DCC_AdapCtrl_Table();

	if (DCC_AdaptCtrl_Level_Table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~Scaler_get_DCC_AdapCtrl_DCC_Level Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	AdapCtrl_Current_Mean = Scaler_get_DCC_AdapCtrl_Current_Mean();
	AdapCtrl_Current_Dev = Scaler_get_DCC_AdapCtrl_Current_Dev();

	(DCC_AdaptCtrl_Level_Table->DCC_Cublc_High_table)[AdapCtrl_Current_Mean][AdapCtrl_Current_Dev] = value;
	fwif_color_set_DCC_SC_for_Coef_Change(1, 1);

	return TRUE;

}

void Scaler_Get_color_access_TVStatus_DisplayInfo(unsigned int *VIP_Access_Memory_DisplayInfo_Table)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	VIP_Access_Memory_DisplayInfo_Table[inputsrc] = Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display);
	VIP_Access_Memory_DisplayInfo_Table[HDMI_Data_Range]	= drvif_IsRGB_YUV_RANGE();
	VIP_Access_Memory_DisplayInfo_Table[Frame_rate_input] = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ);
	VIP_Access_Memory_DisplayInfo_Table[Frame_rate_output] = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC);

}


#ifdef LocalDimming
void Scaler_SetLocalDimmingEnable(unsigned char enable)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);



	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 1.LD_Enable = %d\n", enable);
	pTable = fwif_color_get_color_data(src_idx, 0);

	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "fwif_color_set_sharpness_table error %d \n", enable);
		return;
	}

	pTable->LocalDimmingEnable = enable;
	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 2.LD_Enable = %d\n", pTable->LocalDimmingEnable);

	fwif_color_set_LD_Enable(src_idx, enable);

}

void Scaler_GetLocalDimmingEnable(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;

	return pData->LocalDimmingEnable;
}


void Scaler_SetLocalDimmingTable(unsigned char TableIdx)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 1.LD_Table = %d\n", TableIdx);
	pTable = fwif_color_get_color_data(src_idx, 0);

	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "fwif_color_set_sharpness_table error %d \n", TableIdx);
		return;
	}

	pTable->LocalDimmingTable = TableIdx;
	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 2.LD_Table = %d\n", pTable->LocalDimmingTable);

	Scaler_fwif_color_set_LocalDimming_table(src_idx, TableIdx);

}

void Scaler_GetLocalDimmingTable(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;

	return pData->LocalDimmingTable;
}


void Scaler_fwif_color_set_LocalDimming_table(unsigned char src_idx, unsigned char TableIdx)
{


	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] TableIdx = %d\n", TableIdx);
	fwif_color_set_LD_Global_Ctrl(src_idx, TableIdx);
	fwif_color_set_LD_Backlight_Decision(src_idx, TableIdx);
	fwif_color_set_LD_Spatial_Filter(src_idx, TableIdx);
	fwif_color_set_LD_Spatial_Remap(src_idx, TableIdx);
	fwif_color_set_LD_Boost(src_idx,TableIdx);
	fwif_color_set_LD_Temporal_Filter(src_idx, TableIdx);
	fwif_color_set_LD_Backlight_Final_Decision(src_idx, TableIdx);
	fwif_color_set_LD_Data_Compensation(src_idx, TableIdx);
	fwif_color_set_LD_Data_Compensation_NewMode_2DTable(src_idx,TableIdx);
	fwif_color_set_LD_Backlight_Profile_Interpolation(src_idx, TableIdx);
	fwif_color_set_LD_BL_Profile_Interpolation_Table(src_idx, TableIdx);
	fwif_color_set_LD_Demo_Window(src_idx, TableIdx);

	return;

}

#endif


unsigned char Scaler_GetLocalContrastEnable(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;

	return pTable->LocalContrastEnable;
	//return fwif_color_get_LC_Enable();
}

void Scaler_SetLocalContrastEnable(unsigned char enable)
{

	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);



	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 1.LC_Enable = %d\n", enable);
	pTable = fwif_color_get_color_data(src_idx, 0);

	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "fwif_color_set_sharpness_table error %d \n", enable);
		return;
	}

	pTable->LocalContrastEnable = enable;
	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 2.LC_Enable = %d\n", pTable->LocalContrastEnable);

	fwif_color_set_LC_Enable(src_idx, enable);


}


void Scaler_SetLocalContrastTable(unsigned char TableIdx)
{

	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 1.LC_Table = %d\n", TableIdx);
	pTable = fwif_color_get_color_data(src_idx, 0);

	if (pTable == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "fwif_color_set_sharpness_table error %d \n", TableIdx);
		return;
	}

	pTable->LocalContrastTable = TableIdx;
	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] 2.LC_Table = %d\n", pTable->LocalContrastTable);

	Scaler_fwif_color_set_LocalContrast_table(src_idx, TableIdx);


}

unsigned char Scaler_GetLocalContrastTable(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->LocalContrastTable;
}


void Scaler_fwif_color_set_LocalContrast_table(unsigned char src_idx, unsigned char TableIdx)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_LC] = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME, "===[scalerColorLib_Default.cpp] TableIdx = %d\n", TableIdx);
	fwif_color_set_LC_Global_Ctrl(src_idx, TableIdx);
	fwif_color_set_LC_Backlight_Decision(src_idx, TableIdx);
	fwif_color_set_LC_Spatial_Filter(src_idx, TableIdx);
	fwif_color_set_LC_Temporal_Filter(src_idx, TableIdx);
	fwif_color_set_LC_Backlight_Profile_Interpolation(src_idx, TableIdx);
	fwif_color_set_LC_Demo_Window(src_idx, TableIdx);
	fwif_color_set_LC_ToneMapping_SetGrid0(src_idx, TableIdx);
	fwif_color_set_LC_ToneMapping_SetGrid2(src_idx, TableIdx);
	fwif_color_set_LC_ToneMapping_CurveSelect(src_idx, TableIdx);
	fwif_color_set_LC_ToneMapping_Blend(src_idx, TableIdx);
	fwif_color_set_LC_Shpnr_Gain1st(src_idx, TableIdx);
	fwif_color_set_LC_Shpnr_Gain2nd(src_idx, TableIdx);
	fwif_color_set_LC_Diff_Ctrl0(src_idx, TableIdx);
//juwen, add LC : tone mapping curve
	fwif_color_set_LC_ToneMappingSlopePoint(src_idx, TableIdx);

	/* enable adaptive LC while LC items is exist in PQA table*/
	VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_LC] = 1;

	return;


}

#if 0 //jyyang20161215 // Dstat is remoived since mac5
int Scaler_GetRGBPixelInfo(RGB_pixel_info *data)
{
	return fwif_color_get_rgb_pixel_info(data);
}
#endif
/*==========================================*/
/*======= DDI API interface ==================*/







/*=========================================*/


/*===========================================*/
/*========== no used fw API, for Custom or Eng. menu =====*/
/*===========================================*/

#ifdef BUILD_TV057_1_ATV
static unsigned char ucEnterDcr_Panasonic_Flag = _FALSE;

void fwif_set_dcr_panasonic_apply(unsigned char value)
{
	int ret;

	memcpy((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_Set_Dcr_Panasonic), &value, sizeof(unsigned char));
	if (0 != (Scaler_SendRPC(SCALERIOC_Set_Dcr_Panasonic, ShareMemAddrDummy, RPC_Send_Addr))) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, set Scaler_Set_dcr_panasonic to driver fail !!!\n", ret);
		return;
	}
}

unsigned char fwif_get_dcr_panasonic(void)
{
	return ucEnterDcr_Panasonic_Flag;
}

void fwif_set_dcr_panasonic(unsigned char value)
{
	VIPprintf("fwif_set_dcr_panasonic, value = %d\n", value);

	/*USER:LewisLee DATE:2013/01/10*/
	/*to prevent have other function use smart fit at same time*/
	/*Ex : DCR in Video CPU, YPbPr/VGA in Main CPU*/
	/*will let smart fit error*/
	if (0 == value) {
		/*DCR Off*/
		Scaler_Set_SmartFit_Be_Used_At_SameTime_Flag(_FALSE);
		ucEnterDcr_Panasonic_Flag = _FALSE;
	} else {/* if (1 == value)*/
		/*DCR On*/
		Scaler_Set_SmartFit_Be_Used_At_SameTime_Flag(_TRUE);
		ucEnterDcr_Panasonic_Flag = _TRUE;
	}

	fwif_set_dcr_panasonic_apply(value);
}

#endif

/*==========================================*/

void Scaler_color_handler(void)
{
	fwif_color_handler();

#ifdef ENABLE_OVERDRIVE
	fwif_color_od_handler();
#endif

}

void Scaler_AllocateODMem(void)
{
	od_mem_addr = (unsigned int)dvr_malloc_specific(0x76A700, GFP_DCU1);
}

void Scaler_ReleaseODMem(void)
{
	if (od_mem_addr) {
		dvr_free((void *)od_mem_addr);
		od_mem_addr = 0;
	}
}

unsigned int Scaler_GetODMem(void)
{
	return od_mem_addr;
}

static SLR_VIP_TABLE_CUSTOM_TV001 gVip_Table_Custom;
SLR_VIP_TABLE_CUSTOM_TV001 *g_Share_Memory_VIP_TABLE_Custom_Struct;

void Scaler_SetPictureMode(unsigned char level)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;
	pData->mode = (PICTURE_MODE)level;

	rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_SetPictureMode, %d\n", level);

	fwif_color_set_set_picture_mode(src_idx, level);/* send to share Memory*/

	/*== get current picture mode OSD data ==*/

	rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_set_picture_mode = %d, value = %d ++++++@@\n", pData->mode, level);
	rtd_printk(KERN_DEBUG, TAG_NAME, "\nset_picture_mode:::src_idx = %d \n", src_idx);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::Contrast = %d \n", pData->Contrast);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::Brightness = %d \n", pData->Brightness);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::Saturation = %d \n", pData->Saturation);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::Hue = %d \n", pData->Hue);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::Sharpness = %d \n", pData->Sharpness);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::BackLight = %d \n", pData->BackLight);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::DNR = %d \n", pData->DNR);
	rtd_printk(KERN_DEBUG, TAG_NAME, "set_picture_mode:::DccMode = %d \n", pData->DccMode);


	/*set HSBC*/
	/* this path(contrast, brightness, saturation) need to remove future. using "Scaler_SetContrast, Scaler_SetBrightness, Scaler_SetSaturation" directly*/
	/*Scaler_setcontrastbrightness_style(_MAIN_DISPLAY); */ /*set OSD contrast and brightness*/
	Scaler_SetContrast(pData->Contrast);
	Scaler_SetBrightness(pData->Brightness);
	Scaler_SetSaturation(pData->Saturation);
	/*Scaler_seticmhuesat_style(_MAIN_DISPLAY); */ /*set OSD contrast and brightness */ /* need set hue, can't not mark, elieli*/
	Scaler_SetHue(pData->Hue);

	fwif_color_RHAL_SetDNR(0); /* Init DNR*/
	/* set NR*/
	Scaler_Set_NR_style(1, CALLED_NOT_BY_OSD);  /*rock_rau :: NR for default*/
	Scaler_SetMPEGNR(pData->MPEG, CALLED_NOT_BY_OSD);
	Scaler_SetDNR(pData->DNR);

	/*rtd_printk(KERN_DEBUG, TAG_NAME, "OKOKOKOKOKOKOKOKOKOKOK\n");*/
	/*return;*/

	/*set sharpness*/
	Scaler_SetSharpness(pData->Sharpness);/*set OSD sharpness*/
	Scaler_SetCDSTable_by_Sharpness(pData->Sharpness);

	/*set DCC*/
	fwif_color_set_dcc_mode(0, 4);
	Scaler_set_dcc_Sync_DCC_AP_Level(0, Scaler_GetDCC_Table(), 4);
	Scaler_SetDCC_Mode(pData->DccMode); /* set dcc mode*/

	/*set Backlight*/
	#if 1
	//Panel_SetBackLightLevel(BACKLIGHT_USER, pData->BackLight);
	Scaler_SetBackLight(pData->BackLight);
	//Scaler_SetOSDBacklight2VIP(pData->BackLight);		/*20120614 roger*/
	Scaler_SetDcrMode(pData->DCRMode);
	#endif

	/*set Color temp*/
	Scaler_SetColorTemp((SLR_COLORTEMP_LEVEL)scaler_get_color_temp_level_type(src_idx)); /*need to fix CSFC*/

	/* set film*/
	Scaler_SetFilm_Setting();

 	/* set CLEAR WHITE GAIN*/
	//fwif_color_set_YUV2RGB_UV_Offset(src_idx, display, 3/*high*/);	//20150504 roger add

	/*Send RPC*/
	//Scaler_set_picmode_init_sendRPC();// ISR in kernel ! this function is  useless.

}

unsigned char Scaler_GetPictureMode()
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return VIP_COLORSTD_DEFAULT;
	return pData->mode;
}


void Scaler_ResetPictureQuality(SCALER_DISP_CHANNEL display)
{
	unsigned short sourceIndex = GET_UI_SOURCE_FROM_DISPLAY(display);
	unsigned char overlap = 0;

	if (display == SLR_SUB_DISPLAY) { /* added by hsliao 20090522*/
		if (!((Scaler_PipGetInfo(SLR_PIP_TYPE) >= SUBTYPE_PIPMLSR) && (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_PIPMLSR_4x3))) {
			overlap = 1;
		}
	}
	/*Scaler_setcontrastbrightness_style(display);*/
	Scaler_SetContrast(Scaler_GetContrast());
	Scaler_SetBrightness(Scaler_GetBrightness());
	/*Scaler_seticmhuesat_style(display);*/
	Scaler_SetSaturation(Scaler_GetSaturation());
	Scaler_SetHue(Scaler_GetHue());

	Scaler_SetSharpness(Scaler_GetSharpness());
	Scaler_SetCDSTable_by_Sharpness(Scaler_GetSharpness());
	Scaler_SetColorTemp((SLR_COLORTEMP_LEVEL)scaler_get_color_temp_level_type(sourceIndex));

	Scaler_SetDNR(Scaler_GetDNR());

	Scaler_SetDCC_Mode(Scaler_GetDCC_Mode());

}

void Scaler_RefreshPictureMode(void)
{
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);
	extern unsigned char g_pq_bypass_lv;
	extern unsigned char hdmi_provider_type_mode;
	extern unsigned char str_resume_do_picturemode;
		
	if (VIP_system_info_structure_table == NULL)
		return;

	if (display == SLR_SUB_DISPLAY)
		return;

	fwif_color_setCon_Bri_Color_Tint_inYUV2RGB_from_OSD_Gain(src_idx, display, VIP_system_info_structure_table);
	Scaler_SetSharpness(Scaler_GetSharpness());
	Scaler_SetCDSTable_by_Sharpness(Scaler_GetSharpness());
	Scaler_SetDNR(Scaler_GetDNR());
	Scaler_SetMPEGNR(Scaler_GetMPEGNR(), CALLED_NOT_BY_OSD);
	Scaler_SetDCC_Mode(Scaler_GetDCC_Mode());
	Scaler_Set_CinemaMode_PQ(Scaler_Get_CinemaMode_PQ());
	if (g_tv002_demo_fun_flag) {
		Scaler_set_sGamma(Scaler_get_sGamma());
		Scaler_set_BLE(Scaler_get_BLE());
		//Scaler_set_LiveColor(Scaler_get_LiveColor());
		fwif_color_set_clarity_resolution();
	}

	if((hdmi_provider_type_mode==ON) && (VIP_system_info_structure_table->Input_src_Type == _SRC_HDMI))
		Scaler_Set_hdmi_provider_type(hdmi_provider_type_mode);
	
	//printk("tim_li,do_picturemode=%d,picturemode=%d,\n",str_resume_do_picturemode,picturemode);
	if(str_resume_do_picturemode){
		Scaler_Set_PictureMode_PQsetting(picturemode);
		//str_resume_do_picturemode=0;
	}
	
	// for Dolby HDR
	if (VIP_system_info_structure_table ->DolbyHDR_flag && g_pq_bypass_lv == 9)
		Scaler_color_Set_PQ_ByPass_Lv(9);
}

unsigned char Scaler_GetContrast(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;

	return pData->Contrast;
}

/*range 0~100*/
void Scaler_SetContrast(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;

	pData->Contrast = value;

	/* this path need to remove future. using "fwif_color_setContrast" directly*/
	/*Scaler_setcontrastbrightness_style(display); */ /*20140115, CSFC. TO_DO : Need to modify set con/bri Driver*/
	fwif_color_setContrast(src_idx, display, value);

}

unsigned char Scaler_GetBrightness(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;
	return pData->Brightness;
}

void Scaler_SetBrightness(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;

	pData->Brightness = value;

	/* this path need to remove future. using "fwif_color_setBrightness" directly*/
	/*Scaler_setcontrastbrightness_style(display); */ /*20140115, CSFC. TO_DO : Need to modify set con/bri Driver*/
	fwif_color_setBrightness(src_idx, display, value);

}

unsigned char Scaler_GetSaturation(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
	 return 0;

	return pData->Saturation;
}

/*range 0~100*/
void Scaler_SetSaturation(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
	 return;

	pData->Saturation = value;

	/* this path need to remove future. using "fwif_color_setSaturation" directly*/
	/*Scaler_seticmhuesat_style(display);*/
	fwif_color_setSaturation(src_idx,  display, value);

}

unsigned char Scaler_GetHue(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 50;

	return pData->Hue;
}

/*range 0~100*/
void Scaler_SetHue(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;

	pData->Hue = value;

	/*Scaler_seticmhuesat_style(display);*/
	fwif_color_setHue(src_idx, display, value);

}

unsigned char Scaler_GetSharpness(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;

	Scaler_Get_Display_info(&display, &src_idx);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;
	return pData->Sharpness;
}

/*User OSD Setting : OSD range 0~100*/
void Scaler_SetSharpness(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_SetSharpness ==> %d", value);
	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;
	pData->Sharpness = value;

	fwif_color_set_sharpness_level(Scaler_GetSharpnessTable(), value);
}

void Scaler_SetCDSTable_by_Sharpness(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	printk("yuan,Scaler_SetCDSTable_by_Sharpness=%d\n",value);
	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;
	pData->Sharpness = value;

	fwif_color_set_CDSTable_level(Scaler_GetCDSTable(), value);
}

unsigned char Scaler_Get_DCR_Backlight(void)
{
	_clues *smartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	if(smartPic_clue == NULL){
		return Scaler_GetBacklight();
	}

	return smartPic_clue->DCR_GDBC_mappingValue;//Range : 0~255
}


unsigned char Scaler_SetBackLight(unsigned char level)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	fwif_color_set_backlight(src_idx, level);
	return TRUE;
}

unsigned char Scaler_GetBacklight(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	return fwif_color_get_backlight(src_idx);
}

SLR_COLORTEMP_LEVEL Scaler_GetColorTemp(void)
{
	return (SLR_COLORTEMP_LEVEL) scaler_get_color_temp_level_type(GET_USER_INPUT_SRC());
}

/* level = 0, 						USER,	*/ /*yy*/
/* level = 1, R = 0x80, G = 0x80, B = 0x80			NORMAL,	*/ /*std*/
/* level = 2, R = 0x9a, G = 0x80, B = 0x9b			WARMER,	*/ /*6500K*/
/* level = 3, R = 0xa7, G = 0x80, B = 0xbc			WARM,	*/ /*7300K*/
/* level = 4, R = 0x91, G = 0x7d, B = 0xc9			COOL,	*/ /*8200K*/
/* level = 5, R = 0x91, G = 0x80, B = 0xef			COOLER,	*/ /*9300K*/

void Scaler_SetColorTemp(SLR_COLORTEMP_LEVEL level)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	//VIP_system_info_structure_table->OSD_Info.OSD_colorTemp = level;
	scaler_set_color_temp_level(level);

	/*20140422 roger*/
	/*set RGB gain/offset, ===========================*/

	fwif_color_setrgbcontrast_By_Table(Scaler_get_color_temp_r_type(src_idx), Scaler_get_color_temp_g_type(src_idx), Scaler_get_color_temp_b_type(src_idx), 0);
	fwif_color_setrgbbrightness_By_Table(Scaler_get_color_temp_r_offset(src_idx), Scaler_get_color_temp_g_offset(src_idx), Scaler_get_color_temp_b_offset(src_idx));
	/*==================================================*/

	/*set gamma curve*/
	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	fwif_set_gamma(pTable->Gamma, pTable->Sindex, pTable->Shigh, pTable->Slow);

}




unsigned char Scaler_PipGetSubBrightness(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	/*Scaler_Get_Display_info(&display, &src_idx);*/
	display = SLR_SUB_DISPLAY; /* fix me !! need call SW get display main/sub info.*/
	src_idx = GET_UI_SOURCE_FROM_DISPLAY(display);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;
	return pData->Contrast;
}

void Scaler_PipSetSubBrightness(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);
	display = SLR_SUB_DISPLAY; /* fix me !! need call SW get display main/sub info.*/

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;

	pData->Contrast = value;

	fwif_color_setBrightness(src_idx, display, value); /*20140115, CSFC. TO_DO : Need to modify set con/bri Driver*/
}

unsigned char Scaler_PipGetSubContrast(void)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	/*Scaler_Get_Display_info(&display, &src_idx);*/
	display = SLR_SUB_DISPLAY; /* fix me !! need call SW get display main/sub info.*/
	src_idx = GET_UI_SOURCE_FROM_DISPLAY(display);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return 0;
	return pData->Brightness;
}

/*range 0~100*/
void Scaler_PipSetSubContrast(unsigned char value)
{
	SLR_PICTURE_MODE_DATA *pData = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	/*Scaler_Get_Display_info(&display, &src_idx);*/
	display = SLR_SUB_DISPLAY; /* fix me !! need call SW get display main/sub info.*/
	src_idx = GET_UI_SOURCE_FROM_DISPLAY(display);

	pData = (SLR_PICTURE_MODE_DATA *)fwif_color_get_cur_picture_mode_data(src_idx);
	if (pData == NULL)
		return;

	pData->Contrast = value;

	/*Scaler_setcontrastbrightness_style(display); */ /*20140115, CSFC. TO_DO : Need to modify set con/bri Driver*/
	fwif_color_setContrast(src_idx, display, value);
}

void Scaler_Load_VipTable_Custom(void *ptr)
{
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "\n\n Scaler_Load_VipTable_Custom \n\n");*/

	int ret;
#if 0/*ndef SLR_VIP_TABLE_CUSTOM*/
	rtd_printk(KERN_DEBUG, TAG_NAME, "\n\n not defined VipTable_Custom \n\n");
	return;
#endif

	if (ptr == NULL) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "load custom pq table error\n");
		return;
	}
	memcpy(&gVip_Table_Custom, ptr, sizeof(SLR_VIP_TABLE_CUSTOM_TV001));

	VIPprintf("=== load_vip_table ===\n");

	/* Initial Share Memory*/
#if CONFIG_RTK_KDEV_VGIP_INTERRUPT
	unsigned int virAddr = Scaler_GetShareMemVirAddr(SCALERIOC_VIP_TABLE_CUSTOM_STRUCT);
	Scaler_Share_Memory_Access_VIP_TABLE_Custom_Struct(virAddr);
#else
	memcpy((void *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_TABLE_CUSTOM_STRUCT), &gVip_Table_Custom, sizeof(SLR_VIP_TABLE_CUSTOM_TV001));
	g_Share_Memory_VIP_TABLE_Custom_Struct = ((SLR_VIP_TABLE_CUSTOM_TV001 *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_TABLE_CUSTOM_STRUCT));

	ret = Scaler_SendRPC(SCALERIOC_VIP_TABLE_CUSTOM_STRUCT, 0, 0);
	if (0 != ret) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "ret = %d, Get SCALERIOC_VIP_TABLE_STRUCT fail !!!\n", ret);
	}
#endif
}

void Scaler_Init_ColorLib_customer_share_memory_struct(void)
{
	/*ToDo : add init share memory code here.*/
}

/*Elsie 20131211: sync from Mac2*/
static UINT8 DI_Force_2D_Enable = _DISABLE;

/*USER:LewisLee DATE:2013/07/24*/
/*for special case, DTV 1080i 60Hz*/
/*In some stream, audio have noise*/
/*need force DI to 2D mode*/
UINT8 Scaler_Get_DI_Force_2D_Enable(void)
{
	return DI_Force_2D_Enable;
}

void Scaler_Set_DI_Force_2D_Enable(UINT8 ucEnable)
{
	DI_Force_2D_Enable = ucEnable;
}

UINT8 Scaler_Enter_DI_Force_2D_Condition(UINT8 ucDisplay)
{
	UINT8 ucInpitSource = _SRC_MAX;
	UINT8 Force_2D_Flag = _DISABLE;

	if (_DISABLE == DI_Force_2D_Enable)
		return _DISABLE;

	if (_FALSE == Scaler_DispGetStatus((SCALER_DISP_CHANNEL)ucDisplay, SLR_DISP_THRIP))
		return _DISABLE;

	ucInpitSource = Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)ucDisplay);

	if (_SRC_VO == ucInpitSource) {
		switch (Scaler_DispGetInputInfoByDisp(ucDisplay, SLR_INPUT_MODE_CURR)) {
		case _MODE_1080I25:
		case _MODE_1080I30:
			Force_2D_Flag = _ENABLE;
		break;

		default:
			Force_2D_Flag = _DISABLE;
		break;
		}
	}

	return Force_2D_Flag;
}

unsigned short Scaler_GetMAG_H_Region_Start(void)
{
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;

	main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);

	return main_active_h_start_end_reg.mh_act_sta;
}

unsigned short Scaler_GetMAG_H_Region_End(void)
{
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;

	main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);

	return main_active_h_start_end_reg.mh_act_end;
}

unsigned short Scaler_GetMAG_H_Region_Width(void)
{
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;

	main_active_h_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);

	return main_active_h_start_end_reg.mh_act_end - main_active_h_start_end_reg.mh_act_sta;
}

unsigned short Scaler_GetMAG_V_Region_Start(void)
{
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

	main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);

	return main_active_v_start_end_reg.mv_act_sta;
}

unsigned short Scaler_GetMAG_V_Region_End(void)
{
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

	main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);

	return main_active_v_start_end_reg.mv_act_end;
}

unsigned short Scaler_GetMAG_V_Region_Len(void)
{
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;

	main_active_v_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);

	return main_active_v_start_end_reg.mv_act_end - main_active_v_start_end_reg.mv_act_sta;
}

unsigned char Scaler_GetMagicPicture_demo_reset(void)
{
	return pstMagicPicInfo->magic_picture;
}


void Scaler_SetMagicPicture_demo_reset(unsigned char level)
{
	if (level == 0)
		MagicPicture_cnt = 0;

	pstMagicPicInfo->magic_picture = MagicPicture_cnt;

	mScalerSetMAG();
}

void Scaler_SetMagicPicture(SLR_MAGIC_TYPE level)
{
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if (pstMagicPicInfo->magic_picture == level)
		return;

	if (VIP_system_info_structure_table->HDR_flag== 1){
		(MagicPicture_cnt)++;
		if (MagicPicture_cnt >= 4) {
			MagicPicture_cnt = 0;
		}
		rtd_printk(KERN_DEBUG, TAG_NAME, "MagicPicture_cnt=%d\n", MagicPicture_cnt);
		pstMagicPicInfo->magic_picture = MagicPicture_cnt;
	}
	else{

		pstMagicPicInfo->magic_picture = level;
	}
	mScalerSetMAG();
}


/*======================= for magic picture ======================*/
unsigned int tmp_Contrast_A2a = 0x00808080;
unsigned int tmp_Contrast_A = 0x00808080;

typedef enum {
	_NORMAL_MODE = 0,
	_MAGIC_MODE,
} MagicModeDef;

MagicModeDef magic_mode = _NORMAL_MODE; /* 0 nomal mode , 1 magic mode*/

void mScalerSetMAG(void)
{
	#ifdef VIP_CONFIG_DUAL_CHANNEL
	con_bri_d_overlay_contrast_a2a_RBUS d_overlay_contrast_a2a_reg;
	#endif
	color_d_vc_global_ctrl_RBUS d_vc_global_ctrl_reg;
	gamma_gamma_ctrl_2_RBUS gamma_ctrl_2_REG;
	inv_gamma_inv_gamma_ctrl_2_RBUS inv_gamma_ctrl_2_REG;
	con_bri_dm_contrast_a_RBUS dm_contrast_a_reg;
	UINT16 _a2a_r, _a2a_g, _a2a_b; /*sync from AT*/
	/*static char mode_cnt;*/
	color_dcc_d_dcc_ctrl_RBUS	 	color_dcc_d_dcc_ctrl_reg;

	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	/*==== sync from AT  =======*/
	dm_contrast_a_reg.regValue = IoReg_Read32(CON_BRI_DM_CONTRAST_A_reg);
	_a2a_r = dm_contrast_a_reg.m_con_a_r;
	_a2a_g = dm_contrast_a_reg.m_con_a_g;
	_a2a_b = dm_contrast_a_reg.m_con_a_b;
	if (_a2a_r == 0)
		_a2a_r = 512;
	if (_a2a_g == 0)
		_a2a_g = 512;
	if (_a2a_b == 0)
		_a2a_b = 512;
	/*============================*/

	/*USER:LewisLee DATE:2010/10/06*/
	/*if we adjust H/V size, we need re-calculate zoom step parameter*/
	rtd_printk(KERN_DEBUG, TAG_NAME, "mScalerSetMAG()= %d\n", pstMagicPicInfo->magic_picture);

	Scaler_MagicPictureInit();

	switch (pstMagicPicInfo->magic_picture) {
	case SLR_MAGIC_OFF:/* off*/
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "SLR_MAGIC_OFF\n");*/
		if (GET_MAGIC_PERIOD_STATUS() == MAGIC_IN_FUNCTION) {/*if still in magic function, send osd msg to make sure not in magic function*/
/*				Scaler_PipSetMode(Scaler_PipGetMode());*/
			SET_MAGIC_PIP_TYPE(SLR_MAGIC_OFF);
		}
		mScalerMagicStoreContrast();
		fw_scaler_disable_measure_subwdg_magicpic();
		if (pstMagicPicInfo->pre_magic_pic)   /*if magic is not on, don't call color off*/
			mScalerMagicPictureColorOff();
		mScalerDisableMagicPicture();

		/*USER: Vincent_Lee  DATE: 2010/10/12  TODO: Add 3 mode(still, optimize, enhance)*/
		/*Scaler_MagicSaturation(SLR_MAIN_DISPLAY, SLR_MAGIC_OFF);*/

		d_vc_global_ctrl_reg.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);
		color_dcc_d_dcc_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_CTRL_reg);
		gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);
		inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);

		#ifdef VIP_CONFIG_DUAL_CHANNEL
		d_vc_global_ctrl_reg.s_vc_en = 0; // mac5 dcc remove, no sub, caroline_170316
		#endif
		color_dcc_d_dcc_ctrl_reg.dcc_main_en = 1;


		gamma_ctrl_2_REG.gamma_m_tab_sel = 1;
		inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 1;

		#ifdef CONFIG_DUAL_CHANNEL
		#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
			d_vc_global_ctrl_reg.s_vc_en = 0;
			//color_dcc_d_dcc_ctrl_reg.dcc_overlay = 0;//mark by caroline
			color_dcc_d_dcc_ctrl_reg.dcc_sub_mode_sel = 0;
			gamma_ctrl_2_REG.gamma_s_tab_sel = 0;
			inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 0;
		#endif
		#endif

		IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, d_vc_global_ctrl_reg.regValue);
		IoReg_Write32(COLOR_DCC_D_DCC_CTRL_reg, color_dcc_d_dcc_ctrl_reg.regValue);
		IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);

		pstMagicPicInfo->pre_magic_pic = SLR_MAGIC_OFF; /*record previous state*/

		break;

	case SLR_MAGIC_STILLDEMO:	/*still*/
	case SLR_MAGIC_STILLDEMO_INVERSE:
	case SLR_MAGIC_FULLSCREEN:
		pstMagicPicInfo->magic_direction = _TRUE;
		if (pstMagicPicInfo->magic_picture == SLR_MAGIC_FULLSCREEN) {

			pstMagicPicInfo->magic_XStartForDynamic = Scaler_GetMAG_H_Region_Start();
			pstMagicPicInfo->magic_XEndForDynamic = Scaler_GetMAG_H_Region_End();

		} else if ((pstMagicPicInfo->magic_picture == SLR_MAGIC_STILLDEMO_INVERSE) || (pstMagicPicInfo->magic_picture == SLR_MAGIC_STILLDEMO)) {

			pstMagicPicInfo->magic_XStartForDynamic = Scaler_GetMAG_H_Region_Width()/2 + Scaler_GetMAG_H_Region_Start();
			pstMagicPicInfo->magic_XEndForDynamic = Scaler_GetMAG_H_Region_End();

		}

		/*pstMagicPicInfo->magic_XStartForDynamic = Scaler_GetMAG_H_Region_Width()/2 + Scaler_GetMAG_H_Region_Start();*/
		/*pstMagicPicInfo->magic_XEndForDynamic = Scaler_GetMAG_H_Region_End();*/
		pstMagicPicInfo->magic_YStartForDynamic = Scaler_GetMAG_V_Region_Start();
		pstMagicPicInfo->magic_YEndForDynamic = Scaler_GetMAG_V_Region_End();

		mScalerDisableMagicPicture();
		/*while (!IoReg_Read32(HD_SEM_reg));*/
		/*while (!IoReg_Read32(HD_SEM_reg));*/
#if 0
		d_overlay_contrast_a2a_reg.regValue = IoReg_Read32(CON_BRI_D_Overlay_CONTRAST_A2A_reg);
		d_overlay_contrast_a2a_reg.v_con_a2a_b = _a2a_b - 32;/*sync from  */ /*0x70;*/
		d_overlay_contrast_a2a_reg.v_con_a2a_g = _a2a_g - 32;/*sync from  */ /*0x70;*/
		d_overlay_contrast_a2a_reg.v_con_a2a_r = _a2a_r - 32;/*sync from  */ /*0x70;*/
		IoReg_Write32(CON_BRI_D_Overlay_CONTRAST_A2A_reg, d_overlay_contrast_a2a_reg.regValue);
		/*IoReg_Write32(HD_SEM_reg, 0);*/
#endif
		d_vc_global_ctrl_reg.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);
		color_dcc_d_dcc_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_CTRL_reg);
		gamma_ctrl_2_REG.regValue = IoReg_Read32(GAMMA_GAMMA_CTRL_2_reg);
		inv_gamma_ctrl_2_REG.regValue = IoReg_Read32(INV_GAMMA_INV_GAMMA_CTRL_2_reg);
#ifdef VIP_CONFIG_DUAL_CHANNEL
		d_vc_global_ctrl_reg.s_vc_en = 1; // mac5 dcc remove,no sub, caroline_170316
		color_dcc_d_dcc_ctrl_reg.dcc_overlay = 1; // mac5 dcc remove,no sub, caroline_170316
#endif
		if (VIP_system_info_structure_table->HDR_flag== 1) {
			if ((pstMagicPicInfo->magic_picture == SLR_MAGIC_STILLDEMO_INVERSE) || (pstMagicPicInfo->magic_picture == SLR_MAGIC_FULLSCREEN)) {

#ifdef VIP_CONFIG_DUAL_CHANNEL
				d_vc_global_ctrl_reg.highlightwin_inv = 1; // mac5 dcc remove,no sub, caroline_170316
#endif

				color_dcc_d_dcc_ctrl_reg.dcc_main_en = 1;

				gamma_ctrl_2_REG.gamma_m_tab_sel = 1;
				inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 1;

				#ifdef CONFIG_DUAL_CHANNEL
				#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
				color_dcc_d_dcc_ctrl_reg.dcc_sub_mode_sel = 2;
				gamma_ctrl_2_REG.gamma_s_tab_sel = 0;
				inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 0
				#endif;
				#endif

			} else {

#ifdef VIP_CONFIG_DUAL_CHANNEL
				d_vc_global_ctrl_reg.highlightwin_inv = 0; // mac5 dcc remove,no sub, caroline_170316
				color_dcc_d_dcc_ctrl_reg.dcc_main_mode_sel = 2; // mac5 dcc remove, caroline_170316
#endif
				gamma_ctrl_2_REG.gamma_m_tab_sel = 0;
				inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 0;

				#ifdef CONFIG_DUAL_CHANNEL
				#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
				color_dcc_d_dcc_ctrl_reg.dcc_sub_mode_sel = 1;
				gamma_ctrl_2_REG.gamma_s_tab_sel = 1;
				inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 1;
				#endif
				#endif
			}

		} else	{

#ifdef VIP_CONFIG_DUAL_CHANNEL
			d_vc_global_ctrl_reg.highlightwin_inv = 1;// mac5 dcc remove,no sub, caroline_170316
#endif

			color_dcc_d_dcc_ctrl_reg.dcc_main_en = 1;

			gamma_ctrl_2_REG.gamma_m_tab_sel = 1;
			inv_gamma_ctrl_2_REG.inv_gamma_m_tab_sel = 1;

			#ifdef CONFIG_DUAL_CHANNEL
			#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
			color_dcc_d_dcc_ctrl_reg.dcc_sub_mode_sel = 1;
			gamma_ctrl_2_REG.gamma_s_tab_sel = 1;
			inv_gamma_ctrl_2_REG.inv_gamma_s_tab_sel = 1;
			#endif
			#endif
		}

		WaitFor_DEN_STOP();/* add wait porch to avoid line flash problem 20101019 Plank Pu*/

		IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, d_vc_global_ctrl_reg.regValue);
		IoReg_Write32(COLOR_DCC_D_DCC_CTRL_reg, color_dcc_d_dcc_ctrl_reg.regValue);
		IoReg_Write32(GAMMA_GAMMA_CTRL_2_reg, gamma_ctrl_2_REG.regValue);
		if (vpq_project_id == 0x00060000 &&  vpqex_project_id == 0x00060000)
			IoReg_Write32(INV_GAMMA_INV_GAMMA_CTRL_2_reg, inv_gamma_ctrl_2_REG.regValue);

		/*mScalerMagicStoreContrast();*/
		fw_scaler_enable_measure_subwdg_magicpic();
		mScalerMagicPictureCtrlForDynamic();/*need setting before enable hl window double buffer*/
		Scaler_MoveMagicPictureForStill(0, 0);
		/*Scaler_MagicSaturation(SLR_MAIN_DISPLAY, SLR_MAGIC_STILLDEMO);*/
		pstMagicPicInfo->pre_magic_pic = pstMagicPicInfo->magic_picture;

		break;

	default:
		mScalerMagicPictureColorOff();
		mScalerDisableMagicPicture();
		break;

	}
}

void Scaler_MagicPictureInit(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME, "magic_DISP_WID_OSD = %d\n", pstMagicPicInfo->magic_DISP_WID_OSD);

	if (pstMagicPicInfo->magic_DISP_WID_OSD == 1280) {
		magic_step_x =  4;
		magic_step_y =  4;
		MAG_XSize  = (Scaler_GetMAG_H_Region_Width() - (196*magic_step_x));
		MAG_YSize = (Scaler_GetMAG_V_Region_Len() - (196*magic_step_y));

		magic_zoom_step_x = 2;
		magic_zoom_step_y = 2;
		MAG_ZOOM_XSize = (Scaler_GetMAG_H_Region_Width() - (240*magic_zoom_step_x*2));
		MAG_ZOOM_YSize = (Scaler_GetMAG_V_Region_Len() - (240*magic_zoom_step_y*2));
	} else if (pstMagicPicInfo->magic_DISP_WID_OSD == 1366) {
		magic_step_x =  5;
		magic_step_y =  3;
		MAG_XSize = (Scaler_GetMAG_H_Region_Width() - (196*magic_step_x));
		MAG_YSize = (Scaler_GetMAG_V_Region_Len() - (196*magic_step_y));

		magic_zoom_step_x = 3;
		magic_zoom_step_y = 2;
		MAG_ZOOM_XSize = (Scaler_GetMAG_H_Region_Width() - (180*magic_zoom_step_x*2));
		MAG_ZOOM_YSize = (Scaler_GetMAG_V_Region_Len() - (180*magic_zoom_step_y*2));
	} else if (pstMagicPicInfo->magic_DISP_WID_OSD == 1920) {
		magic_step_x =  5;
		magic_step_y =  3;
		MAG_XSize  = (Scaler_GetMAG_H_Region_Width() - (240*magic_step_x));
		MAG_YSize = (Scaler_GetMAG_V_Region_Len() - (240*magic_step_y));

		magic_zoom_step_x = 3;
		magic_zoom_step_y = 2;
		MAG_ZOOM_XSize = (Scaler_GetMAG_H_Region_Width() - (240*magic_zoom_step_x*2));
		MAG_ZOOM_YSize = (Scaler_GetMAG_V_Region_Len() - (240*magic_zoom_step_y*2));
	} else if (pstMagicPicInfo->magic_DISP_WID_OSD == 1024) {
		magic_step_x =  3;
		magic_step_y =  3;
		MAG_XSize = (Scaler_GetMAG_H_Region_Width() - (196*magic_step_x));
		MAG_YSize = (Scaler_GetMAG_V_Region_Len() - (196*magic_step_y));

		magic_zoom_step_x = 3;
		magic_zoom_step_y = 2;
		MAG_ZOOM_XSize = (Scaler_GetMAG_H_Region_Width() - (160*magic_zoom_step_x*2));
		MAG_ZOOM_YSize = (Scaler_GetMAG_V_Region_Len() - (160*magic_zoom_step_y*2));

	} else if (pstMagicPicInfo->magic_DISP_WID_OSD == 1712) {
		magic_step_x =  5;
		magic_step_y =  3;
		MAG_XSize = (Scaler_GetMAG_H_Region_Width() - (196*magic_step_x));
		MAG_YSize = (Scaler_GetMAG_V_Region_Len() - (196*magic_step_y));

		magic_zoom_step_x = 3;
		magic_zoom_step_y = 2;
		MAG_ZOOM_XSize = (Scaler_GetMAG_H_Region_Width() - (180*magic_zoom_step_x*2));
		MAG_ZOOM_YSize = (Scaler_GetMAG_V_Region_Len() - (180*magic_zoom_step_y*2));
	} else {
		magic_step_x =  5;
		magic_step_y =  3;
		MAG_XSize = (Scaler_GetMAG_H_Region_Width() - (196*magic_step_x));
		MAG_YSize = (Scaler_GetMAG_V_Region_Len() - (196*magic_step_y));

		magic_zoom_step_x = 3;
		magic_zoom_step_y = 2;
		MAG_ZOOM_XSize = (Scaler_GetMAG_H_Region_Width() - (180*magic_zoom_step_x*2));
		MAG_ZOOM_YSize = (Scaler_GetMAG_V_Region_Len() - (180*magic_zoom_step_y*2));
	}
}

void mScalerDisableMagicPicture(void)
{
#ifdef CONFIG_DUAL_CHANNEL
	PipMpSetMpEnable(_DISABLE);
#endif
	drvif_color_set_sethighlightwindowmin(0, 0); /*set border*/
	drvif_color_sethighlightwindowstep(0, 0, 0, 0);
	drvif_color_sethighlightwindow(_DISABLE, 0, 0, 0, 0, 0);
	/*frank@07152010 add below to solve mantis28460 disable magic picture will appear sub window*/
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
}

void mScalerMagicStoreContrast(void)
{
	if (magic_mode == _NORMAL_MODE) {
#ifdef VIP_CONFIG_DUAL_CHANNEL
		tmp_Contrast_A2a = IoReg_Read32(CON_BRI_D_Overlay_CONTRAST_A2A_reg);// mac5 dcc remove, no sub, caroline_170316
#endif
		tmp_Contrast_A = IoReg_Read32(CON_BRI_DM_CONTRAST_A_reg);
		magic_mode = _MAGIC_MODE;
	}

	IoReg_ClearBits(YUV2RGB_D_YUV2RGB_Control_reg, _BIT1 | _BIT6);

}

void mScalerMagicPictureColorOff(void)
{
/*	con_bri_dm_contrast_a_RBUS dm_contrast_a_reg;*/
/*	con_bri_d_overlay_contrast_a2a_RBUS d_overlay_contrast_a2a_reg;*/
	color_d_vc_global_ctrl_RBUS d_vc_global_ctrl_reg;

/*	rtd_printk(KERN_DEBUG, TAG_NAME, "[debug 1]%x %x\n", tmp_Contrast_A, tmp_Contrast_A2a);*/
	/*while (!IoReg_Read32(HD_SEM_reg));*/
#ifdef VIP_CONFIG_DUAL_CHANNEL
	IoReg_Write32(CON_BRI_D_Overlay_CONTRAST_A2A_reg, tmp_Contrast_A2a); /*restore original value*/// mac5 dcc remove,no sub, caroline_170316
#endif
	IoReg_Write32(CON_BRI_DM_CONTRAST_A_reg, tmp_Contrast_A); /* restore original value*/

	/*IoReg_Write32(HD_SEM_reg, 0);*/
	magic_mode = _NORMAL_MODE;

	d_vc_global_ctrl_reg.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);
#ifdef VIP_CONFIG_DUAL_CHANNEL
	d_vc_global_ctrl_reg.highlightwin_inv = 0;// mac5 dcc remove,no sub, caroline_170316
#endif
	WaitFor_DEN_STOP(); /* add wait porch to avoid line flash problem 20101019 Plank Pu*/
	IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, d_vc_global_ctrl_reg.regValue);
	IoReg_SetBits(YUV2RGB_D_YUV2RGB_Control_reg, _BIT1 | _BIT6);

}

void Scaler_MagicSaturation(unsigned char display, unsigned char MagicMode)
{
	short hue = 0, sat = 0, intensity = 0;
	unsigned char osdHue = 0, osdSat = 0;
	char temp = 0;

	/*USER: Vincent_Lee  DATE: 2011/10/26  TODO: calcu sat by factory data*/
	short startPoint = 0, endPoint = 0;
	StructColorDataFacModeType *pColorFacTable;
	/*if (scaler_2Dcvt3D_get_vgip2EnableStatus())
	{
		pColorFacTable = fwif_color_get_color_fac_mode(scaler_2Dcvt3D_get_vgip2SrcIndex(), 0);
	}
	else*/
	/*{*/
		pColorFacTable = fwif_color_get_color_fac_mode(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX), 0);
	/*}*/
	if (pColorFacTable == NULL)
		return;


	if (display == SLR_MAIN_DISPLAY) {
		/*osdHue = fwif_color_get_hue(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX));*/
		osdHue = Scaler_GetHue();
		temp = (short)(osdHue-50)*(-1);
		hue = (short)(temp*21/10); /*map -50~50 to -128~128*/

		/*osdSat = fwif_color_get_saturation(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX));*/
		osdSat = Scaler_GetSaturation();
		if (MagicMode == SLR_MAGIC_ENHANCE) {
			osdSat += 40;
			if (osdSat > 100)	/*---the value must <= 100*/
				osdSat = 100;

		} else if (MagicMode == SLR_MAGIC_OFF) {
			if (osdSat <= 10)
				osdSat = 0;
			else
				osdSat -= 10;
		}
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler_MagicSaturation: osdSat = %d \n", osdSat);*/
		/*sat = (short)(osdSat*2.55);*/ /*map 0~100 to 0~255*/

		/*USER: Vincent_Lee  DATE: 2011/10/26  TODO: calcu sat by factory data*/
		if (osdSat < 50) {
			startPoint = pColorFacTable->Saturation_0;
			endPoint = pColorFacTable->Saturation_50;
		} else {
			startPoint = pColorFacTable->Saturation_50;
			endPoint = pColorFacTable->Saturation_100;
			osdSat -= 50;
		}
		sat = (unsigned char)(startPoint + (endPoint-startPoint)*osdSat/50);


		/*map 0~100 to -2048~2047*/
		/*intensity = (short)((fwif_color_get_intensity(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX)) *40.95) -2048);*/
		intensity = (short)((Scaler_GetIntensity() * 4095/100) - 2048);
		drvif_color_setuv_sat(display, sat);/* 20100726 modify sat adj.  from sRGB to uv, csfanchiang*/
		/*drvif_color_seticmhsi(display, hue, 0, intensity); */ /*20090305 haifu del saturation in ICM*/
		drvif_color_seticmhsi(display, hue, ICM_Global_hue); /*set ICM global hue, original only hue can work*/
	}

}

void mScalerMagicPictureCtrlForDynamic(void)
{
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	ppoverlay_mp_layout_force_to_background_RBUS  mp_layout_force_to_background_reg;
	ppoverlay_mp_disp_enable_RBUS mp_disp_enable_reg;
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	mp_layout_force_to_background_reg.regValue = IoReg_Read32(PPOVERLAY_MP_Layout_Force_to_Background_reg);
	//fix me later by ben
	//mp_layout_force_to_background_reg.mp_force_bg = 0x0000;/* disable force-to-background each*/
	mp_layout_force_to_background_reg.s_force_bg = 0; /*normal display*/
	mp_layout_force_to_background_reg.s_disp_en = 1;
	IoReg_Write32(PPOVERLAY_MP_Layout_Force_to_Background_reg, mp_layout_force_to_background_reg.regValue);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	mp_disp_enable_reg.regValue = IoReg_Read32(PPOVERLAY_MP_Disp_Enable_reg);
	//fix me later by ben
	//mp_disp_enable_reg.mp_disp_en = 0x01;
	mp_disp_enable_reg.mp_hbd_en = 0;
	IoReg_Write32(PPOVERLAY_MP_Disp_Enable_reg, mp_disp_enable_reg.regValue);
	drvif_color_setpiprgbcontrastbrightness(100);

	drvif_scalerdisplay_set_bg_color(_SUB_DISPLAY, _DISPLAY_EB, 0x00, 0x7b, 0xbc); /*jacklong 2008/01/08 modify colour   0x0f, 0x00, 0x00); */ /* set external border color*/
#endif
#endif
}

void Scaler_MoveMagicPictureForStill(unsigned int timerId, void *msg)
{
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	ppoverlay_highlight_window_control_RBUS vc_reg;

	drvif_color_sethighlightwindowborder(2, BORDERSTYLE_LEFT);
	drvif_color_set_sethighlightwindowmin(4, 4);
	drvif_color_sethighlightwindowstep(0, 0, 0, 0);

	drvif_color_sethighlightwindow(_ENABLE, pstMagicPicInfo->magic_XStartForDynamic, pstMagicPicInfo->magic_YStartForDynamic, pstMagicPicInfo->magic_XEndForDynamic, pstMagicPicInfo->magic_YEndForDynamic, 4);

	vc_reg.regValue = IoReg_Read32(PPOVERLAY_Highlight_window_control_reg);
	vc_reg.hlw_mode = 1;
	vc_reg.hlw_en = 1;
	IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, vc_reg.regValue);
	IoReg_Write32(PPOVERLAY_Highlight_window_DB_CTRL_reg, 0x1);

	if (pstMagicPicInfo->magic_picture == SLR_MAGIC_OFF)
		mScalerDisableMagicPicture();
#endif
}


/*======================= for magic picture end ======================*/
unsigned char Scaler_getDI_SMD_en(unsigned char source)
{
	unsigned char *pVipCoefArray = NULL;

	/* Load pVipCoefArray*/
	if (m_cbFunc_getQualityCoef != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityCoef((VIP_SOURCE_TIMING) source);

	if (!(source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)) {
		return pVipCoefArray[VIP_QUALITY_FUNCTION_DI_SMD_Level];
	} else {
		return 0;
	}
}

void Scaler_Set3dLUT(UINT8 TableIdx)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->d3dLUT= TableIdx;
	
	fwif_color_set_3dLUT_Clear_Code(TableIdx);
}

unsigned char Scaler_Get3dLUT(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->d3dLUT;
}

void Scaler_color_copy_scalerinfo_to_vip(unsigned char display)
{
	/*=== 20140421 CSFC for vip video fw infomation ====*/
	/* setting some information to sharememory*/
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	VIP_system_info_structure_table->Input_src_Type		= Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display);
	VIP_system_info_structure_table->Input_src_Form		= Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display);
	VIP_system_info_structure_table->Input_VO_Form		= Scaler_VOFrom(Scaler_Get_CurVoInfo_plane());
	VIP_system_info_structure_table->Input_TVD_Form		= Scaler_InputSrcGetMainFormat();
	VIP_system_info_structure_table->vdc_color_standard	= drvif_module_vdc_ReadMode(VDC_SET);
	VIP_system_info_structure_table->Timing				= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	VIP_system_info_structure_table->HDMI_video_format	= drvif_Hdmi_GetColorSpace();
	VIP_system_info_structure_table->Display_RATIO_TYPE	= Scaler_DispGetRatioMode();
	VIP_system_info_structure_table->HDMI_data_range    = drvif_IsRGB_YUV_RANGE();

	VIP_system_info_structure_table->input_display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	VIP_system_info_structure_table->HDMI_color_space = Scaler_DispGetInputInfo(SLR_INPUT_COLOR_SPACE);
	VIP_system_info_structure_table->IV_Start = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);
	VIP_system_info_structure_table->IH_Start = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA);
	VIP_system_info_structure_table->I_Height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
	VIP_system_info_structure_table->I_Width = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
	VIP_system_info_structure_table->Mem_Height = Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN);
	VIP_system_info_structure_table->Mem_Width = Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID);
	VIP_system_info_structure_table->Cap_Height = Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN);
	VIP_system_info_structure_table->Cap_Width = Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID);
	VIP_system_info_structure_table->DI_Width = Scaler_DispGetInputInfo(SLR_INPUT_DI_WID);
	VIP_system_info_structure_table->D_Height = Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);
	VIP_system_info_structure_table->D_Width = Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID);
	VIP_system_info_structure_table->color_fac_src_idx = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY, SLR_INPUT_DATA_ARRAY_IDX);
	/*============================================*/
}

void Scaler_color_print_scalerinfo(void)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL || VIP_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL!(%d,%d) \n",__FILE__, __LINE__,VIP_RPC_system_info_structure_table, VIP_system_info_structure_table);
		return;
	}

	rtd_printk(KERN_DEBUG, TAG_NAME, "===== VIP_scaler_info =====\n");
	/*============================================*/
	rtd_printk(KERN_DEBUG, TAG_NAME, "Input_src_Type = %d\n", VIP_system_info_structure_table->Input_src_Type);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Input_src_Form = %d\n", VIP_system_info_structure_table->Input_src_Form);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Input_VO_Form = %d\n", VIP_system_info_structure_table->Input_VO_Form);
	rtd_printk(KERN_DEBUG, TAG_NAME, "input_TVD_Form = %d\n", VIP_system_info_structure_table->Input_TVD_Form);
	rtd_printk(KERN_DEBUG, TAG_NAME, "vdc_color_standard = %d\n", VIP_system_info_structure_table->vdc_color_standard);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Timing = %d\n", VIP_system_info_structure_table->Timing);
	rtd_printk(KERN_DEBUG, TAG_NAME, "HDMI_video_format = %d\n", VIP_system_info_structure_table->HDMI_video_format);
	rtd_printk(KERN_DEBUG, TAG_NAME, "VIP_source = %d\n", VIP_RPC_system_info_structure_table->VIP_source);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Display_RATIO_TYPE = %d\n", VIP_system_info_structure_table->Display_RATIO_TYPE);
	rtd_printk(KERN_DEBUG, TAG_NAME, "HDMI_data_range = %d\n", VIP_system_info_structure_table->HDMI_data_range);

	rtd_printk(KERN_DEBUG, TAG_NAME, "input_display = %d\n", VIP_system_info_structure_table->input_display);
	rtd_printk(KERN_DEBUG, TAG_NAME, "HDMI_color_space = %d\n", VIP_system_info_structure_table->HDMI_color_space);
	rtd_printk(KERN_DEBUG, TAG_NAME, "IV_Start = %d\n", VIP_system_info_structure_table->IV_Start);
	rtd_printk(KERN_DEBUG, TAG_NAME, "IH_Start = %d\n", VIP_system_info_structure_table->IH_Start);
	rtd_printk(KERN_DEBUG, TAG_NAME, "I_Height = %d\n", VIP_system_info_structure_table->I_Height);
	rtd_printk(KERN_DEBUG, TAG_NAME, "I_Width = %d\n", VIP_system_info_structure_table->I_Width);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Mem_Height = %d\n", VIP_system_info_structure_table->Mem_Height);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Mem_Width = %d\n", VIP_system_info_structure_table->Mem_Width);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Cap_Height = %d\n", VIP_system_info_structure_table->Cap_Height);
	rtd_printk(KERN_DEBUG, TAG_NAME, "Cap_Width = %d\n", VIP_system_info_structure_table->Cap_Width);
	rtd_printk(KERN_DEBUG, TAG_NAME, "DI_Width = %d\n", VIP_system_info_structure_table->DI_Width);
	rtd_printk(KERN_DEBUG, TAG_NAME, "D_Height = %d\n", VIP_system_info_structure_table->D_Height);
	rtd_printk(KERN_DEBUG, TAG_NAME, "D_Width = %d\n", VIP_system_info_structure_table->D_Width);
	rtd_printk(KERN_DEBUG, TAG_NAME, "color_fac_src_idx = %d\n", VIP_system_info_structure_table->color_fac_src_idx);
	/*============================================*/
	rtd_printk(KERN_DEBUG, TAG_NAME, "===== VIP_scaler_info end =====\n");

}

/*static unsigned char facPatternColorLevel;*/
void Scaler_SetFacPatternColor(unsigned char val)
{
#if 0	//fix me later by ben
	unsigned int temp;
	static unsigned int old;
	static unsigned char saved;

	facPatternColorLevel = val;

	switch (val) {
	case SCALERLIB_PatternColor_OFF:	/*close*/
		if (saved) {
			IoReg_Write32(SCALEUP_DM_UZU_Input_Size_reg, old);  /*restore origin*/
			saved = 0;
		}

		IoReg_SetBits(SCALEUP_DM_UZU_Ctrl_reg, _BIT9);
		IoReg_ClearBits(SCALEUP_D_UZU_Globle_Ctrl_reg, _BIT0|_BIT1);
		/*Scaler_ForceBg(_MAIN_DISPLAY, SLR_FORCE_BG_SYSTEM, _DISABLE);	*/ /*=== marked by Elsie ===*/
		break;
	case SCALERLIB_PatternColor_RED:	/*red*/
		drvif_scalerdisplay_set_bg_color(_MAIN_DISPLAY, _DISPLAY_BG, 0xFF, 0x00, 0x00); /* set main background color: red*/
		/*frank@0810 mask interrupt status bit IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1); */ /* force BG*/
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) | _BIT1));
		IoReg_WriteByte2(PPOVERLAY_Display_Background_Color_reg, 0x00);	/* why??*/
		drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
		break;
	case SCALERLIB_PatternColor_GREEN: /*green*/
		drvif_scalerdisplay_force_bg(_MAIN_DISPLAY, _TRUE);
		IoReg_Mask32(PPOVERLAY_Main_Background_Color1_reg, 0xffff000, (AND(0, 0xf) << 8) | (AND(0xff, 0xf) << 4) | AND(0x0, 0xf));
		drvif_scalerdisplay_set_bg_color(_MAIN_DISPLAY, _DISPLAY_BG, 0x00, 0xFF, 0x00); /* set main background color: green*/
		/*frank@0810 mask interrupt status bit IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1); */ /* force BG*/
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) | _BIT1));
		IoReg_WriteByte2(PPOVERLAY_Display_Background_Color_reg, 0x00);	/* why ??*/
		drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
		break;
	case SCALERLIB_PatternColor_BLUE: /*blue*/
		drvif_scalerdisplay_force_bg(_MAIN_DISPLAY, _TRUE);
		IoReg_Mask32(PPOVERLAY_Main_Background_Color1_reg, 0xffff000, (AND(0xff, 0x0f) << 8) | (AND(0, 0x0f) << 4) | AND(0xf, 0x0f));
		drvif_scalerdisplay_set_bg_color(_MAIN_DISPLAY, _DISPLAY_BG, 0x00, 0x00, 0xFF); /* set main background color: blue*/
		/*frank@0810 mask interrupt status bit IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1); */ /* force BG*/
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) | _BIT1));
		IoReg_WriteByte2(PPOVERLAY_Display_Background_Color_reg, 0x00);	/* why ??*/
		drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
		break;
	case SCALERLIB_PatternColor_WHITE: /*white*/
		drvif_scalerdisplay_force_bg(_MAIN_DISPLAY, _TRUE);
		IoReg_Mask32(PPOVERLAY_Main_Background_Color1_reg, 0xffff000, (AND(0xff, 0x0f) << 8) | (AND(0, 0x0f) << 4) | AND(0xf, 0x0f));
		drvif_scalerdisplay_set_bg_color(_MAIN_DISPLAY, _DISPLAY_BG, 0xFF, 0xFF, 0xFF); /* set main background color: white*/
		/*frank@0810 mask interrupt status bit IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1); */ /* force BG*/
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) | _BIT1));
		IoReg_WriteByte2(PPOVERLAY_Display_Background_Color_reg, 0x00);	/* why ??*/
		drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
		break;
	case SCALERLIB_PatternColor_BLACK:  /*black*/
		drvif_scalerdisplay_force_bg(_MAIN_DISPLAY, _TRUE);
		IoReg_Mask32(PPOVERLAY_Main_Background_Color1_reg, 0xffff000, (AND(0xff, 0x0f) << 8) | (AND(0, 0x0f) << 4) | AND(0xf, 0x0f));
		if (saved) {
			IoReg_Write32(0xb8071028, old);  /*restore origin*/
			saved = 0;
		}
		drvif_scalerdisplay_set_bg_color(_MAIN_DISPLAY, _DISPLAY_BG, 0x00, 0x00, 0x00); /* set main background color: black*/
		/*frank@0810 mask interrupt status bit IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1); */ /* force BG*/
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, (IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) | _BIT1));
		IoReg_WriteByte2(PPOVERLAY_Display_Background_Color_reg, 0x00);	/* why ??*/
		drvif_scalerdisplay_set_dbuffer_en(SLR_MAIN_DISPLAY, FALSE);
		break;
	case SCALERLIB_PatternColor_COLORBAR: /*color bar*/
		if (!saved) {
			old = IoReg_Read32(SCALEUP_DM_UZU_Input_Size_reg);
			saved = 1;
		}
		temp = (IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg) & 0x00000fff)-((IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg) & 0x0fff0000)>>16); /*width*/
	/*	rtd_printk(KERN_DEBUG, TAG_NAME, "Hstart: %d, Hend: %d\n", (IoReg_Read32(DDOMAIN_MAIN_ACTIVE_H_START_END_VADDR) & 0x000007ff), ((IoReg_Read32(DDOMAIN_MAIN_ACTIVE_H_START_END_VADDR) & 0x07ff0000)>>16));*/
		rtd_printk(KERN_DEBUG, TAG_NAME, "0xb8071028 = %x\n", (temp << 16) | ((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x000007ff)-((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x07ff0000)>>16)));
		IoReg_Write32(SCALEUP_DM_UZU_Input_Size_reg, (temp << 16) | ((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x00000fff)-((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x0fff0000)>>16))); /* set width and length to UZU*/
		temp = ((temp/16-1) << 16) | 0x31;
	/*	rtd_printk(KERN_DEBUG, TAG_NAME, "0xb8071000 = %x\n", temp);*/
		IoReg_Write32(SCALEUP_D_UZU_Globle_Ctrl_reg, temp); /* internal pattern gen*/
		/*frank@0810 mask interrupt status bit IoReg_ClearBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1|_BIT15); */ /* force BG*/
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, ((IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) & ~(_BIT1|_BIT15))));
		IoReg_ClearBits(SCALEUP_DM_UZU_Ctrl_reg, _BIT9); /* 444*/
		/*IoReg_Write32(DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR,  IoReg_Read32(DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR) & 0xFFFFFFFD);*/
		break;
	case SCALERLIB_PatternColor_GRAYBAR:  /*gray bar*/
		drvif_scalerdisplay_force_bg(_MAIN_DISPLAY, _TRUE);
		IoReg_Mask32(PPOVERLAY_Main_Background_Color1_reg, 0xffff000, (AND(0xff, 0x0f) << 8) | (AND(0, 0x0f) << 4) | AND(0xf, 0x0f));
		if (!saved) {
			old = IoReg_Read32(SCALEUP_DM_UZU_Input_Size_reg);
			saved = 1;
		}
		temp = (IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg) & 0x00000fff)-((IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg) & 0x0fff0000)>>16); /*width*/
	/*	rtd_printk(KERN_DEBUG, TAG_NAME, "Hstart: %d, Hend: %d\n", (IoReg_Read32(DDOMAIN_MAIN_ACTIVE_H_START_END_VADDR) & 0x000007ff), ((IoReg_Read32(DDOMAIN_MAIN_ACTIVE_H_START_END_VADDR) & 0x07ff0000)>>16));*/
		rtd_printk(KERN_DEBUG, TAG_NAME, "0xb8071028 = %x\n", (temp << 16) | ((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x000007ff)-((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x07ff0000)>>16)));
		IoReg_Write32(SCALEUP_DM_UZU_Input_Size_reg, (temp << 16) | ((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x00000fff)-((IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg) & 0x0fff0000) >> 16))); /* set width and length to UZU*/
		temp = ((temp/8-1) << 16) | 0x51;
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "0xb8071000 = %x\n", temp);*/
		IoReg_Write32(SCALEUP_D_UZU_Globle_Ctrl_reg, temp); /* internal pattern gen*/
		IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR0_reg, 0x00197788); /* change pattern gen color 0*/
		IoReg_Write32(SCALEUP_D_UZU_PATGEN_COLOR1_reg, 0x005E7788); /* change pattern gen color 1*/
		/*frank@0810 mask interrupt status bit IoReg_ClearBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1|_BIT15); */ /* force BG*/
		IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, ((IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg) & ~(_BIT1|_BIT15))));
		IoReg_ClearBits(SCALEUP_DM_UZU_Ctrl_reg, _BIT9); /* 444*/
		/*IoReg_Write32(DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR,  IoReg_Read32(DDOMAIN_MAIN_DISPLAY_CONTROL_RSV_VADDR) & 0xFFFFFFFD);*/
		break;
	default:
		break;
	}
#endif
}

#ifdef ENABLE_VIP_TABLE_CHECKSUM
/* === checksum ========== */
void Scaler_checkVIPTable(void)
{
	extern VIP_table_crc_value vip_table_crc;
	VIP_table_crc_value vip_table_crc_now;

	color_dcc_d_dcc_fwused_1_RBUS dcc_fwused_1_reg;
	dcc_fwused_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_FWUSED_1_VADDR);

	if(dcc_fwused_1_reg.VipInfo == 1){
		fwif_color_check_VIPTable_crc(&vip_table_crc_now, fwif_color_GetShare_Memory_VIP_TABLE_Struct());

		SLRLIB_PRINTF("[%s %d] checksum: vip_table %x, vip_table_now %x\n", __FILE__, __LINE__,
			vip_table_crc.checkSum, vip_table_crc_now.checkSum);
	}
	#if 0
	SLRLIB_PRINTF("vip_table_crc.VIP_QUALITY_Coef = %x, vip_table_crc_now.VIP_QUALITY_Coef = %x\n",vip_table_crc.VIP_QUALITY_Coef,vip_table_crc_now.VIP_QUALITY_Coef);
	SLRLIB_PRINTF("vip_table_crc.VIP_QUALITY_Extend_Coef = %x, vip_table_crc_now.VIP_QUALITY_Extend_Coef = %x\n",vip_table_crc.VIP_QUALITY_Extend_Coef,vip_table_crc_now.VIP_QUALITY_Extend_Coef);
	SLRLIB_PRINTF("vip_table_crc.VIP_QUALITY_Extend2_Coef = %x, vip_table_crc_now.VIP_QUALITY_Extend2_Coef = %x\n",vip_table_crc.VIP_QUALITY_Extend2_Coef,vip_table_crc_now.VIP_QUALITY_Extend2_Coef);
	SLRLIB_PRINTF("vip_table_crc.VIP_QUALITY_Extend3_Coef = %x, vip_table_crc_now.VIP_QUALITY_Extend3_Coef = %x\n",vip_table_crc.VIP_QUALITY_Extend3_Coef,vip_table_crc_now.VIP_QUALITY_Extend3_Coef);
	SLRLIB_PRINTF("vip_table_crc.VIP_QUALITY_3Dmode_Coef = %x, vip_table_crc_now.VIP_QUALITY_3Dmode_Coef = %x\n",vip_table_crc.VIP_QUALITY_3Dmode_Coef,vip_table_crc_now.VIP_QUALITY_3Dmode_Coef);
	SLRLIB_PRINTF("vip_table_crc.VIP_QUALITY_Extend4_Coef = %x, vip_table_crc_now.VIP_QUALITY_Extend4_Coef = %x\n",vip_table_crc.VIP_QUALITY_Extend4_Coef,vip_table_crc_now.VIP_QUALITY_Extend4_Coef);
	SLRLIB_PRINTF("vip_table_crc.SU_PK_Coeff = %x, vip_table_crc_now.SU_PK_Coeff = %x\n",vip_table_crc.SU_PK_Coeff,vip_table_crc_now.SU_PK_Coeff);
	SLRLIB_PRINTF("vip_table_crc.SR_init_table = %x, vip_table_crc_now.SR_init_table = %x\n",vip_table_crc.SR_init_table,vip_table_crc_now.SR_init_table);
	SLRLIB_PRINTF("vip_table_crc.SU_PK_Coeff_by_timing = %x, vip_table_crc_now.SU_PK_Coeff_by_timing = %x\n",vip_table_crc.SU_PK_Coeff_by_timing,vip_table_crc_now.SU_PK_Coeff_by_timing);
	SLRLIB_PRINTF("vip_table_crc.SD_H_table = %x, vip_table_crc_now.SD_H_table = %x\n",vip_table_crc.SD_H_table,vip_table_crc_now.SD_H_table);
	SLRLIB_PRINTF("vip_table_crc.SD_v_table = %x, vip_table_crc_now.SD_v_table = %x\n",vip_table_crc.SD_V_table,vip_table_crc_now.SD_V_table);

	SLRLIB_PRINTF("vip_table_crc.ODtable_Coeff = %x, vip_table_crc_now.ODtable_Coeff = %x\n",vip_table_crc.ODtable_Coeff,vip_table_crc_now.ODtable_Coeff);
	SLRLIB_PRINTF("vip_table_crc.DCR_TABLE = %x, vip_table_crc_now.DCR_TABLE = %x\n",vip_table_crc.DCR_TABLE,vip_table_crc_now.DCR_TABLE);
	SLRLIB_PRINTF("vip_table_crc.ICM_by_timing_picmode = %x, vip_table_crc_now.ICM_by_timing_picmode = %x\n",vip_table_crc.ICM_by_timing_picmode,vip_table_crc_now.ICM_by_timing_picmode);
	SLRLIB_PRINTF("vip_table_crc.MA_Chroma_Error_Table = %x, vip_table_crc_now.MA_Chroma_Error_Table = %x\n",vip_table_crc.MA_Chroma_Error_Table,vip_table_crc_now.MA_Chroma_Error_Table);

	SLRLIB_PRINTF("vip_table_crc.CDS_ini = %x, vip_table_crc_now.CDS_ini = %x\n",vip_table_crc.CDS_ini,vip_table_crc_now.CDS_ini);
	SLRLIB_PRINTF("vip_table_crc.D_EDGE_Smooth_Coef = %x, vip_table_crc_now.D_EDGE_Smooth_Coef = %x\n",vip_table_crc.D_EDGE_Smooth_Coef,vip_table_crc_now.D_EDGE_Smooth_Coef);
	SLRLIB_PRINTF("vip_table_crc.I_EDGE_Smooth_Coef = %x, vip_table_crc_now.I_EDGE_Smooth_Coef = %x\n",vip_table_crc.I_EDGE_Smooth_Coef,vip_table_crc_now.I_EDGE_Smooth_Coef);

	SLRLIB_PRINTF("vip_table_crc.UV_Gains_1 = %x, vip_table_crc_now.UV_Gains_1 = %x\n",vip_table_crc.UV_Gains_1,vip_table_crc_now.UV_Gains_1);
	SLRLIB_PRINTF("vip_table_crc.UV_Gains_2 = %x, vip_table_crc_now.UV_Gains_2 = %x\n",vip_table_crc.UV_Gains_2,vip_table_crc_now.UV_Gains_2);
	SLRLIB_PRINTF("vip_table_crc.xvYcc_sRGB_Curve = %x, vip_table_crc_now.xvYcc_sRGB_Curve = %x\n",vip_table_crc.xvYcc_sRGB_Curve,vip_table_crc_now.xvYcc_sRGB_Curve);

	SLRLIB_PRINTF("vip_table_crc.YUV2RGB_CSMatrix_Table = %x, vip_table_crc_now.YUV2RGB_CSMatrix_Table = %x\n",vip_table_crc.YUV2RGB_CSMatrix_Table,vip_table_crc_now.YUV2RGB_CSMatrix_Table);

	SLRLIB_PRINTF("vip_table_crc.VD_ConBriHueSat = %x, vip_table_crc_now.VD_ConBriHueSat = %x\n",vip_table_crc.VD_ConBriHueSat,vip_table_crc_now.VD_ConBriHueSat);
	SLRLIB_PRINTF("vip_table_crc.tICM_ini = %x, vip_table_crc_now.tICM_ini = %x\n",vip_table_crc.tICM_ini,vip_table_crc_now.tICM_ini);
	SLRLIB_PRINTF("vip_table_crc.tICM_H_7axis = %x, vip_table_crc_now.tICM_H_7axis = %x\n",vip_table_crc.tICM_H_7axis,vip_table_crc_now.tICM_H_7axis);
	SLRLIB_PRINTF("vip_table_crc.tGAMMA = %x, vip_table_crc_now.tGAMMA = %x\n",vip_table_crc.tGAMMA,vip_table_crc_now.tGAMMA);

	SLRLIB_PRINTF("vip_table_crc.DCC_Control_Structure = %x, vip_table_crc_now.DCC_Control_Structure = %x\n",vip_table_crc.DCC_Control_Structure,vip_table_crc_now.DCC_Control_Structure);
	SLRLIB_PRINTF("vip_table_crc.Ddomain_SHPTable = %x, vip_table_crc_now.Ddomain_SHPTable = %x\n",vip_table_crc.Ddomain_SHPTable,vip_table_crc_now.Ddomain_SHPTable);
	SLRLIB_PRINTF("vip_table_crc.Idomain_MBPKTable = %x, vip_table_crc_now.Idomain_MBPKTable = %x\n",vip_table_crc.Idomain_MBPKTable,vip_table_crc_now.Idomain_MBPKTable);
	SLRLIB_PRINTF("vip_table_crc.Manual_NR_Table = %x, vip_table_crc_now.Manual_NR_Table = %x\n",vip_table_crc.Manual_NR_Table,vip_table_crc_now.Manual_NR_Table);
	SLRLIB_PRINTF("vip_table_crc.PQA_Table = %x, vip_table_crc_now.PQA_Table = %x\n",vip_table_crc.PQA_Table,vip_table_crc_now.PQA_Table);
	SLRLIB_PRINTF("vip_table_crc.PQA_Input_Table = %x, vip_table_crc_now.PQA_Input_Table = %x\n",vip_table_crc.PQA_Input_Table,vip_table_crc_now.PQA_Input_Table);
	SLRLIB_PRINTF("vip_table_crc.Auto_Function_Array1 = %x, vip_table_crc_now.Auto_Function_Array1 = %x\n",vip_table_crc.Auto_Function_Array1,vip_table_crc_now.Auto_Function_Array1);
	SLRLIB_PRINTF("vip_table_crc.Auto_Function_Array2 = %x, vip_table_crc_now.Auto_Function_Array2 = %x\n",vip_table_crc.Auto_Function_Array2,vip_table_crc_now.Auto_Function_Array2);
	SLRLIB_PRINTF("vip_table_crc.Auto_Function_Array3 = %x, vip_table_crc_now.Auto_Function_Array3 = %x\n",vip_table_crc.Auto_Function_Array3,vip_table_crc_now.Auto_Function_Array3);
	SLRLIB_PRINTF("vip_table_crc.Auto_Function_Array4 = %x, vip_table_crc_now.Auto_Function_Array4 = %x\n",vip_table_crc.Auto_Function_Array4,vip_table_crc_now.Auto_Function_Array4);
	SLRLIB_PRINTF("vip_table_crc.Auto_Function_Array5 = %x, vip_table_crc_now.Auto_Function_Array5 = %x\n",vip_table_crc.Auto_Function_Array5,vip_table_crc_now.Auto_Function_Array5);
	SLRLIB_PRINTF("vip_table_crc.DrvSetting_Skip_Flag = %x, vip_table_crc_now.DrvSetting_Skip_Flag = %x\n",vip_table_crc.DrvSetting_Skip_Flag,vip_table_crc_now.DrvSetting_Skip_Flag);
	#endif
}
/*==========================*/
#endif

unsigned char fwif_vip_increase_DI_water_lv(void)
{
	UINT8 vip_source = fwif_vip_source_check(3, 0);
	//rtd_printk(KERN_DEBUG, TAG_NAME, "\n fwif_vip_source_check(3, 0) = %d \n", vip_source);
	if (vip_source == VIP_QUALITY_HDMI_4k2kP_60)
		return 1;

	return 0;

}

void Scaler_set_HDR10_Enable(unsigned char *enable)
{
	if (enable[HDR_EN])
	{
		if (!drvif_color_set_HDR10_Enable(enable))
		{
			rtd_printk(KERN_WARNING, TAG_NAME, "Scaler_set_HDR10_Enable NOT RUN!!\n");
			return;
		}
		drvif_color_set422to444(0, 0);
	}
	else
	{
		drvif_color_set_HDR10_Enable(enable);
	}
}


UINT8 pre_HDR_on = 0;
UINT8 pre_HDR_stauts = 0xff;
void Scaler_LGE_HDR10_Enable(unsigned char enable)
{
	RGB2YUV_BLACK_LEVEL blk_lv;
	UINT8 video_format;
	//_system_setting_info *VIP_system_info_structure_table;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "blk_lv=%d, videoFormat=%d, HDR mode = %d\n", blk_lv, video_format, get_HDR_mode());*/

	blk_lv = fwif_color_get_rgb2yuv_black_level_tv006();
	video_format = drvif_Hdmi_GetColorSpace();
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_enable_Coef] = enable;
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "[HDR10],videoFMT=%d,hdr_mode=%d\n", video_format, get_HDR_mode());*/
	if (enable != 0)	//enable HDR 10
	{
		if (enable > 2) enable = 1; //protect
		Scaler_set_HDR10_Enable(hdr_table[1]);	//enable process
		if(blk_lv == RGB2YUV_BLACK_LEVEL_LOW || (vpqex_project_id != 0x00060000 && blk_lv == RGB2YUV_BLACK_LEVEL_AUTO)) { /* use limit2full*/
			if ((video_format == 0) && (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)) {/*HDMI HDR RGB case*/
				if (pre_HDR_on && (pre_HDR_stauts == 1)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_Limted_235_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(1, &(tRGB2YUV_COEF[RGB2YUV_COEF_RGB_0_255_TO_YCC2020_0_255][0]), 1);
				pre_HDR_stauts = 1;
			} else if (enable == 1) { /* bt 709 */
				if (pre_HDR_on && (pre_HDR_stauts == 2)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT709_Limted_235_240_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 2;
			} else { /* bt 2020*/
				if (pre_HDR_on && (pre_HDR_stauts == 3)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_Limted_235_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 3;
			}
		} else {	/* use limit2limit*/
			if ((video_format == 0) && (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)) {/*HDMI HDR RGB case*/
				if (pre_HDR_on && (pre_HDR_stauts == 4)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_255_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(1, &(tRGB2YUV_COEF[RGB2YUV_COEF_RGB_0_255_TO_YCC2020_0_255][0]), 0);
				pre_HDR_stauts = 4;
			} else if (enable == 1) {/* bt 709 */
				if (pre_HDR_on && (pre_HDR_stauts == 5)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT709_255_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 5;
			} else { /* bt 2020*/
				if (pre_HDR_on && (pre_HDR_stauts == 6)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_255_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 6;
			}
		}
		drvif_set_main_dither();
		pre_HDR_on = 1;
	}
	else
	{
		pre_HDR_on = 0;
		pre_HDR_stauts = 0xff;
		Scaler_set_HDR10_Enable(hdr_table[0]);	//disable process
	}
}

void Scaler_SetHDR_BlackLevel(unsigned char blk_lv)
{
	unsigned char video_format, enable;
	//_system_setting_info *VIP_system_info_structure_table;
	//VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	enable = VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_enable_Coef];


	if (VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] == 0) /*HDR off*/
		return;

	video_format = drvif_Hdmi_GetColorSpace();

	if(blk_lv == RGB2YUV_BLACK_LEVEL_LOW || (vpqex_project_id != 0x00060000 && blk_lv == RGB2YUV_BLACK_LEVEL_AUTO)) { /* use limit2full*/
		if ((video_format == 0) && (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)) {/*HDMI HDR RGB case*/
			drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_Limted_235_to_255]);

		} else if (enable == 1) { /* bt 709 */
			drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT709_Limted_235_240_to_255]);

		} else { /* bt 2020*/
			drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_Limted_235_to_255]);

		}
	} else {	/* use limit2limit*/
		if ((video_format == 0) && (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)) {/*HDMI HDR RGB case*/
			drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_255_to_255]);

		} else if (enable == 1) {/* bt 709 */
			drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT709_255_to_255]);

		} else { /* bt 2020*/
			drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_255_to_255]);

		}
	}

}

void drvif_TV006_SET_HDR_mode_off(void)
{
	drvif_color_set_BBC_Enable(0);
	Scaler_LGE_HDR10_Enable(0);
}

void drvif_TV006_HDR10_init(void)
{
	drvif_TV006_SET_HDR_mode_off();
	drvif_HDR_RGB2OPT(0, hdr_RGB2OPT[HDR_RGB2OPT_2020_TO_709]);
	//20161020 roger mark
	// 1. K3L use 24x24x24
	// 2. when boot/source change... LG set 3DLUT sevaral times
	//fwif_color_set_DM_HDR_3dLUT(0, HDR10_3DLUT_17x17x17);
}

void drvif_TV006_SET_HDR_mode(UINT32* modeinfo)
{
	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	extern unsigned char g_HDR3DLUTForceWrite;

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	//IoReg_Write32(0xb802e4f4, (modeinfo[0] << 16));
	rtd_printk(KERN_INFO, TAG_NAME, "drvif_TV006_SET_HDR_mode, modeinfo = %d, Colorimetry info = %d\n", modeinfo[0], modeinfo[1]);
	if (modeinfo[1] == 0) modeinfo[1] = 2;	//data protect
	//SET_HDR_mode
	switch(modeinfo[0])	//HDR mode
	{
	case HAL_VPQ_HDR_MODE_HDR10:
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		Scaler_LGE_HDR10_Enable(modeinfo[1]);
		drvif_color_set_BBC_Enable(0);
	break;
	case HAL_VPQ_HDR_MODE_HLG:
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		Scaler_LGE_HDR10_Enable(modeinfo[1]);
		drvif_color_set_BBC_Enable(1);
	break;
	case HAL_VPQ_HDR_MODE_SDR:
	case HAL_VPQ_HDR_MODE_HDREFFECT:
		//HDR10 and HLG off
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 0;
		g_HDR3DLUTForceWrite = 1;
		drvif_TV006_SET_HDR_mode_off();
	break;
	default:
		rtd_printk(KERN_ERR, TAG_NAME, "drvif_TV006_SET_HDR_mode, get unknow mode = %d\n", modeinfo[0]);
	break;
	}

}

#ifdef CONFIG_HDR_SDR_SEAMLESS
extern HDR_SDR_SEAMLESS_PQ_STRUCT HDR_SDR_SEAMLESS_PQ;
extern unsigned char hdr_table[HDR_TABLE_NUM][HDR_ITEM_MAX];
extern unsigned int PQModeInfo_flag[5];
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
extern void scalerVIP_Write_RGB2YUV(unsigned long arg);
#endif
void Scaler_hdr_setting_SEAMLESS(unsigned char hdr_enable)
{
	//_system_setting_info *system_info_struct = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	SLR_VOINFO *pVOInfo = NULL;
	//static unsigned char pre_HDR_MODE = 255;
	unsigned int TF_CH;
	// check HDR mode data path -- VE compress mode need through DV normal mode

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if(hdr_enable)
	{
		if (VIP_RPC_system_info_structure_table->VIP_source >= VIP_QUALITY_HDMI_480I && VIP_RPC_system_info_structure_table->VIP_source <= VIP_QUALITY_HDMI_4k2kP_60) {	/* HDMI case*/
			PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_HDR10;
			PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT2020;
			//system_info_struct->Debug_Buff_8[0]++;
		} else {	/* DTV and USB */
			pVOInfo = (SLR_VOINFO *)Scaler_GetShareMemVirAddr(SCALERIOC_GETVOINFO);

			if(pVOInfo == NULL){
				VIPprintf("[%s:%d] Warning here!! pVOInfo=NULL! \n",__FILE__, __LINE__);
				return;
			}

			TF_CH = pVOInfo->transfer_characteristics;
			TF_CH = fwif_color_ChangeOneUINT32Endian(TF_CH, 1);
			//system_info_struct->Debug_Buff_8[1]++;
			if (TF_CH == 16)
			{
				PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_HDR10;
				PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT2020;
			}
			else if (TF_CH == 18)
			{
				PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_HLG;
				PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT2020;
			}
			else
			{
				PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_SDR;
				PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT709;
			}
		}
	}
	else
	{
		PQModeInfo_flag[0] = HAL_VPQ_HDR_MODE_SDR;
		PQModeInfo_flag[1] = HAL_VPQ_COLORIMETRY_BT709;
		//system_info_struct->Debug_Buff_8[2]++;
	}
	//return;
	//system_info_struct->Debug_Buff_8[2] = PQModeInfo_flag[0];
	//system_info_struct->Debug_Buff_8[3] = fwif_color_ChangeOneUINT32Endian(pVOInfo->transfer_characteristics, 1);
	/*
	if (pre_HDR_MODE == PQModeInfo_flag[0]) {
		//system_info_struct->Debug_Buff_8[0]++;
		return;
	} else {
		pre_HDR_MODE = PQModeInfo_flag[0];
		//system_info_struct->Debug_Buff_8[1]++;
	}
	*/
	/* timing recording*/
	VIP_RPC_system_info_structure_table->HDR_info.EOTF_OETF[oetf_eotf_reverse_0] = rtd_inl(0xb801b6a8);
	VIP_RPC_system_info_structure_table->HDR_info.EOTF_OETF[oetf_eotf_reverse_2] =  VGIP_VGIP_CHN1_LC_get_ch1_line_cnt(IoReg_Read32(VGIP_VGIP_CHN1_LC_reg));

	//unsigned char InputSrcGetType = Scaler_InputSrcGetType(SLR_MAIN_DISPLAY);
#if 1
	// write RGB to yuv table
	//fwif_color_colorspacergb2yuvtransfer_Seamless(hdr_enable, InputSrcGetType);
	//scalerVIP_Write_RGB2YUV(1);

	// write yuv to RGB table
	//fwif_color_setCon_Bri_Color_Tint_tv006(0, system_info_struct);

	fwif_color_SetDataFormatHandler_tv006_Seamless(hdr_enable);
#else

	fwif_color_SetDataFormatHandler_tv006();
#endif

	drvif_TV006_SET_HDR_mode_Seamless(PQModeInfo_flag);
	set_HDR10_DM_setting();
//	fwif_color_SetDataFormatHandler_tv006();

	/* timing recording*/
	VIP_RPC_system_info_structure_table->HDR_info.EOTF_OETF[oetf_eotf_reverse_1] = rtd_inl(0xb801b6a8);
	VIP_RPC_system_info_structure_table->HDR_info.EOTF_OETF[oetf_eotf_reverse_3] =  VGIP_VGIP_CHN1_LC_get_ch1_line_cnt(IoReg_Read32(VGIP_VGIP_CHN1_LC_reg));

}

void drvif_TV006_SET_HDR_mode_Seamless(UINT32* modeinfo)
{
	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	extern unsigned char g_HDR3DLUTForceWrite;

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure)

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	//IoReg_Write32(0xb802e4f4, (modeinfo[0] << 16));
	/*rtd_printk(KERN_INFO, TAG_NAME, "drvif_TV006_SET_HDR_mode, modeinfo = %d, Colorimetry info = %d\n", modeinfo[0], modeinfo[1]);*/
	if (modeinfo[1] == 0) modeinfo[1] = 2;	//data protect
	//SET_HDR_mode
	switch(modeinfo[0])	//HDR mode
	{
	case HAL_VPQ_HDR_MODE_HDR10:
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		Scaler_LGE_HDR10_Enable_Seamless(modeinfo[1]);

		drvif_color_set_BBC_Enable(0);
		drvif_DM2_GAMMA_Enable(0);

#ifdef CONFIG_HDR_SDR_SEAMLESS
		drvif_DM2_EOTF_Enable(1, 0);
		drvif_DM2_OETF_Enable(1, 0);
#endif


	break;
	case HAL_VPQ_HDR_MODE_HLG:
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		Scaler_LGE_HDR10_Enable_Seamless(modeinfo[1]);
		drvif_color_set_BBC_Enable(1);
		drvif_DM2_GAMMA_Enable(1);

#ifdef CONFIG_HDR_SDR_SEAMLESS

		drvif_DM2_EOTF_Enable(1, 1);
		drvif_DM2_OETF_Enable(1, 1);

#endif
	break;
	case HAL_VPQ_HDR_MODE_SDR:
	case HAL_VPQ_HDR_MODE_HDREFFECT:
		//HDR10 and HLG off
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 0;
		g_HDR3DLUTForceWrite = 1;
		/*drvif_TV006_SET_HDR_mode_off();*/
		/*drvif_color_set_BBC_Enable(0);*/
		Scaler_LGE_HDR10_Enable_Seamless(0);

	break;

	default:
		rtd_printk(KERN_ERR, TAG_NAME, "drvif_TV006_SET_HDR_mode, get unknow mode = %d\n", modeinfo[0]);
	break;
	}

}

void Scaler_LGE_HDR10_Enable_Seamless(unsigned char enable)
{
	RGB2YUV_BLACK_LEVEL blk_lv;
	UINT8 video_format;
	//_system_setting_info *VIP_system_info_structure_table;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "blk_lv=%d, videoFormat=%d, HDR mode = %d\n", blk_lv, video_format, get_HDR_mode());*/

	blk_lv = fwif_color_get_rgb2yuv_black_level_tv006();
	video_format = drvif_Hdmi_GetColorSpace();
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_HDR10_enable_Coef] = enable;
	/*rtd_printk(KERN_DEBUG, TAG_NAME, "[HDR10],videoFMT=%d,hdr_mode=%d\n", video_format, get_HDR_mode());*/
	if (enable != 0)	//enable HDR 10
	{
		if (enable > 2) enable = 1; //protect
		Scaler_set_HDR10_Enable_Seamless(hdr_table[1]);	//enable process
		if(blk_lv == RGB2YUV_BLACK_LEVEL_LOW) { /* use limit2full*/
			if ((video_format == 0) && (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)) {/*HDMI HDR RGB case*/
				if (pre_HDR_on && (pre_HDR_stauts == 1)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_Limted_235_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(1, &(tRGB2YUV_COEF[RGB2YUV_COEF_RGB_0_255_TO_YCC2020_0_255][0]), 1);
				pre_HDR_stauts = 1;
			} else if (enable == 1) { /* bt 709 */
				if (pre_HDR_on && (pre_HDR_stauts == 2)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT709_Limted_235_240_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 2;
			} else { /* bt 2020*/
				if (pre_HDR_on && (pre_HDR_stauts == 3)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_Limted_235_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 3;
			}
		} else {	/* use limit2limit*/
			if ((video_format == 0) && (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)) {/*HDMI HDR RGB case*/
				if (pre_HDR_on && (pre_HDR_stauts == 4)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_255_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(1, &(tRGB2YUV_COEF[RGB2YUV_COEF_RGB_0_255_TO_YCC2020_0_255][0]), 0);
				pre_HDR_stauts = 4;
			} else if (enable == 1) {/* bt 709 */
				if (pre_HDR_on && (pre_HDR_stauts == 5)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT709_255_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 5;
			} else { /* bt 2020*/
				if (pre_HDR_on && (pre_HDR_stauts == 6)) return;
				drvif_HDR_YUV2RGB(1, hdr_YUV2RGB[HDR_DM_CSC1_YUV2RGB_BT2020_255_to_255]);
				drvif_HDMI_HDR_I3DDMA_RGB2YUV422(0, NULL, 0);
				pre_HDR_stauts = 6;
			}
		}
		drvif_set_main_dither();
		pre_HDR_on = 1;
	}
	else
	{
		pre_HDR_on = 0;
		pre_HDR_stauts = 0xff;
		Scaler_set_HDR10_Enable_Seamless(hdr_table[0]);	//disable process
	}
}

void Scaler_set_HDR10_Enable_Seamless(unsigned char* enable)
{
	if (enable[HDR_EN])
	{
		if (!drvif_color_set_HDR10_Enable_Seamless(enable))
		{
			rtd_printk(KERN_WARNING, TAG_NAME, "Scaler_set_HDR10_Enable NOT RUN!!\n");
			return;
		}
		drvif_color_set422to444(0, 0);
	}
	else
	{
		drvif_color_set_HDR10_Enable_Seamless(enable);
	}
}

#endif

void Scaler_color_HDRIP_AutoRun(void)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
//========check HDR statu ===========
	unsigned char bHDR_flag = FALSE;
	unsigned char bDolby_HDR_flag = FALSE;
	unsigned char input_src_type;
	unsigned char input_src_form;
	unsigned char input_timming_info;
	unsigned int modeinfo[5];

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if(VIP_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if (fwif_color_get_force_run_i3ddma_enable(SLR_MAIN_DISPLAY) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_VDEC)) {
		fwif_color_vsc_to_scaler_src_mapping(Get_DisplayMode_Src(SLR_MAIN_DISPLAY), &input_src_type, &input_src_form);
		input_timming_info 	= drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_MODE_CURR);
	} else {
		input_src_type = Scaler_InputSrcGetMainChType();
		input_src_form = Scaler_InputSrcGetMainChFrom();
		input_timming_info 	= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	}

	bHDR_flag = fwif_vip_HDR10_check(SLR_MAIN_DISPLAY,input_src_type);
	bDolby_HDR_flag= fwif_vip_DolbyHDR_check(SLR_MAIN_DISPLAY,input_src_type);
	//rtd_printk(KERN_INFO, TAG_NAME, "==== HDR_flag =%d,  input_src_type =%d  =======\n",bHDR_flag,input_src_type);
//==========================================

	if(Scaler_color_Get_HDR_AutoRun()) {
		memset(modeinfo, 0, sizeof(modeinfo));

		if(input_src_type == _SRC_VO || input_src_type == _SRC_HDMI) {	//	HDR10
			modeinfo[0] = bHDR_flag;
			if(VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1)
				modeinfo[1]=HAL_VPQ_COLORIMETRY_BT2020;
			else if(VIP_system_info_structure_table->Timing >= _MODE_720P50)  //hd, 2k,4k
				modeinfo[1] = HAL_VPQ_COLORIMETRY_BT709;
			else
				modeinfo[1] = HAL_VPQ_COLORIMETRY_BT601;  // sd
		} else {
			modeinfo[0] = HAL_VPQ_HDR_MODE_SDR;
			if(VIP_system_info_structure_table->Timing >= _MODE_720P50)  //hd, 2k,4k
				modeinfo[1] = HAL_VPQ_COLORIMETRY_BT709;
			else
				modeinfo[1] = HAL_VPQ_COLORIMETRY_BT601;  // sd
		}
		Scaler_color_HDRInfo_Update(modeinfo);
	}
}

void Scaler_color_HDRInfo_Update(UINT32* modeinfo)
{
	extern UINT32 EOTF_LUT_R[1025];
	//extern UINT16 OETF_LUT_R[1025];

	extern unsigned int HLG_EOTF_LUT_R[EOTF_size];
	extern unsigned int HLG_OETF_LUT_R[OETF_size];
	extern unsigned short HLG_3DLUT_24x24x24[HDR_24x24x24_size][3];

	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	extern unsigned char g_HDR3DLUTForceWrite;

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	static PQ_HDR_3dLUT_16_PARAM args;
	args.c3dLUT_16_enable = 1;

	//IoReg_Write32(0xb802e4f4, (modeinfo[0] << 16));
	rtd_printk(KERN_INFO, TAG_NAME, "Scaler_color_HDRInfo_Update, modeinfo = %d, Colorimetry info = %d\n", modeinfo[0], modeinfo[1]);
	if (modeinfo[1] == 0) modeinfo[1] = 2;	//data protect
	//SET_HDR_mode
	switch(modeinfo[0])	//HDR mode
	{
		case HAL_VPQ_HDR_MODE_HDR10:
			VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
			Scaler_LGE_HDR10_Enable(modeinfo[1]);
			drvif_color_set_BBC_Enable(0);
			drvif_DM2_GAMMA_Enable(0);
			args.a3dLUT_16_pArray = &HDR10_3DLUT_24x24x24[0];
			fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(&args);
			fwif_color_set_DM2_EOTF_TV006(EOTF_LUT_R);
			//fwif_color_set_DM2_OETF_TV006(OETF_LUT_R);
			Scaler_color_Get_HDR10_OETF_ByMaxCLL_ByPanelLuminance(OETF_LUT_ByMaxCLL_ByPanelLuminance);
			fwif_color_set_DM2_OETF_TV006(OETF_LUT_ByMaxCLL_ByPanelLuminance);
			drvif_HDR_RGB2OPT(1, hdr_RGB2OPT[HDR_RGB2OPT_2020_TO_DCI]);

		break;
		case HAL_VPQ_HDR_MODE_HLG:
			VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
			Scaler_LGE_HDR10_Enable(modeinfo[1]);
			drvif_color_set_BBC_Enable(1);
			drvif_DM2_GAMMA_Enable(0);		/* gamma is embebed in 3D LUT*/
			args.a3dLUT_16_pArray = &HLG_3DLUT_24x24x24[0][0];
			fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(&args);
			fwif_color_set_DM2_EOTF_TV006(HLG_EOTF_LUT_R);
			fwif_color_set_DM2_OETF_TV006(HLG_OETF_LUT_R);
			//drvif_HDR_RGB2OPT(0, hdr_RGB2OPT[HDR_RGB2OPT_2020_TO_DCI]); //fix_me, mark it due to cause HLG contour

		break;
		case HAL_VPQ_HDR_MODE_SDR:
		case HAL_VPQ_HDR_MODE_HDREFFECT:
			//HDR10 and HLG off
			VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
			g_HDR3DLUTForceWrite = 1;
			drvif_TV006_SET_HDR_mode_off();

		break;
		default:
			rtd_printk(KERN_ERR, TAG_NAME, "Scaler_color_HDRInfo_Update, get unknow mode = %d\n", modeinfo[0]);
		break;

	}

	//fwif_color_SetDataFormatHandler_tv006();

}


void Scaler_color_HDRIP_AutoRun_sRGB(void)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
//========check HDR statu ===========
	unsigned char bHDR_flag = FALSE;
	unsigned char bDolby_HDR_flag = FALSE;
	unsigned char input_src_type;
	unsigned char input_src_form;
	unsigned char input_timming_info;
	unsigned int modeinfo[5];

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if(VIP_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if (fwif_color_get_force_run_i3ddma_enable(SLR_MAIN_DISPLAY) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_VDEC)) {
		fwif_color_vsc_to_scaler_src_mapping(Get_DisplayMode_Src(SLR_MAIN_DISPLAY), &input_src_type, &input_src_form);
		input_timming_info 	= drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_MODE_CURR);
	} else {
		input_src_type = Scaler_InputSrcGetMainChType();
		input_src_form = Scaler_InputSrcGetMainChFrom();
		input_timming_info 	= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	}

	bHDR_flag = fwif_vip_HDR10_check(SLR_MAIN_DISPLAY,input_src_type);
	bDolby_HDR_flag= fwif_vip_DolbyHDR_check(SLR_MAIN_DISPLAY,input_src_type);
	//rtd_printk(KERN_INFO, TAG_NAME, "==== HDR_flag =%d,  input_src_type =%d  =======\n",bHDR_flag,input_src_type);

	if(Scaler_color_Get_HDR_AutoRun()) {
			unsigned int modeinfo[5];
			memset(modeinfo, 0, sizeof(modeinfo));

					if(input_src_type == _SRC_VO || input_src_type == _SRC_HDMI) {	   //	  HDR10
							if((bHDR_flag!=0) ||(get_HDMI_HDR_mode()==HDR_HDR10_HDMI))
								modeinfo[0] = HAL_VPQ_HDR_MODE_HDR10;
							else
							modeinfo[0] = bHDR_flag;
							if(VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1){
									modeinfo[1]=HAL_VPQ_COLORIMETRY_BT2020;
									//set sRGB matrix
									//fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, BT2020_sRGB_APPLY, 1);
							}
							else if(VIP_system_info_structure_table->Timing >= _MODE_720P50){  //hd, 2k,4k
									modeinfo[1] = HAL_VPQ_COLORIMETRY_BT709;
								   //set sRGB matrix
									//fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, CCIR_709_sRGB_APPLY, 1);
							}
							else{
									modeinfo[1] = HAL_VPQ_COLORIMETRY_BT601;  // sd
									//fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, DCI_P3_RGB_APPLY, 1);
							}
					} else {
							modeinfo[0] = HAL_VPQ_HDR_MODE_SDR;
							if(VIP_system_info_structure_table->Timing >= _MODE_720P50) { //hd, 2k,4k
									modeinfo[1] = HAL_VPQ_COLORIMETRY_BT709;
									//fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, CCIR_709_sRGB_APPLY, 1);
	}
							else{
									modeinfo[1] = HAL_VPQ_COLORIMETRY_BT601;  // sd
									//fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, DCI_P3_RGB_APPLY, 1);
	}
					}
					Scaler_color_HDRInfo_Update_sRGB(modeinfo);
	}
}

void Scaler_color_HDRInfo_Update_sRGB(UINT32* modeinfo)
{
	//extern UINT32 EOTF_LUT_R[1025];
	extern UINT16 OETF_LUT_R[1025];

	extern unsigned int HLG_EOTF_LUT_R[EOTF_size];
	extern unsigned int HLG_OETF_LUT_R[OETF_size];
	extern unsigned short HLG_3DLUT_24x24x24[HDR_24x24x24_size][3];

	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	extern unsigned char g_HDR3DLUTForceWrite;

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	static PQ_HDR_3dLUT_16_PARAM args;
	args.c3dLUT_16_enable = 1;
	//printk("yuan,modeinf=%d\n",modeinfo[0]);
	//IoReg_Write32(0xb802e4f4, (modeinfo[0] << 16));
	rtd_printk(KERN_INFO, TAG_NAME, "Scaler_color_HDRInfo_Update, modeinfo = %d, Colorimetry info = %d\n", modeinfo[0], modeinfo[1]);
	if (modeinfo[1] == 0) modeinfo[1] = 2;	//data protect
	//SET_HDR_mode
	switch(modeinfo[0])	//HDR mode
	{
		case HAL_VPQ_HDR_MODE_HDR10:
			VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
			Scaler_LGE_HDR10_Enable(modeinfo[1]);
			drvif_color_set_BBC_Enable(0);
			drvif_DM2_GAMMA_Enable(0);
			args.a3dLUT_16_pArray = &HDR10_3DLUT_24x24x24[0];
			fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(&args);
			//fwif_color_set_DM2_EOTF_TV006(EOTF_LUT_R);
			fwif_color_set_DM2_OETF_TV006(OETF_LUT_R);
			//Scaler_color_Get_HDR10_OETF_ByMaxCLL_ByPanelLuminance(OETF_LUT_ByMaxCLL_ByPanelLuminance);
			//fwif_color_set_DM2_OETF_TV006(OETF_LUT_ByMaxCLL_ByPanelLuminance);
			//drvif_HDR_RGB2OPT(1, hdr_RGB2OPT[HDR_RGB2OPT_2020_TO_DCI]);

		break;
		case HAL_VPQ_HDR_MODE_HLG:
			VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
			Scaler_LGE_HDR10_Enable(modeinfo[1]);
			drvif_color_set_BBC_Enable(1);
			drvif_DM2_GAMMA_Enable(0);		/* gamma is embebed in 3D LUT*/
			args.a3dLUT_16_pArray = &HLG_3DLUT_24x24x24[0][0];
			fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(&args);
			fwif_color_set_DM2_EOTF_TV006(HLG_EOTF_LUT_R);
			fwif_color_set_DM2_OETF_TV006(HLG_OETF_LUT_R);
			//drvif_HDR_RGB2OPT(0, hdr_RGB2OPT[HDR_RGB2OPT_2020_TO_DCI]); //fix_me, mark it due to cause HLG contour

		break;
		case HAL_VPQ_HDR_MODE_SDR:
		case HAL_VPQ_HDR_MODE_HDREFFECT:
			//HDR10 and HLG off
			VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
			g_HDR3DLUTForceWrite = 1;
			drvif_TV006_SET_HDR_mode_off();

		break;
		default:
			rtd_printk(KERN_ERR, TAG_NAME, "Scaler_color_HDRInfo_Update, get unknow mode = %d\n", modeinfo[0]);
		break;

	}

	//fwif_color_SetDataFormatHandler_tv006();

}


void Scaler_LGE_ONEKEY_HDR10_Enable(unsigned char enable)
{

  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! RPC_system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if (enable) {
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		Scaler_LGE_HDR10_Enable(1);
		/*WaitFor_DEN_STOP();
		WaitFor_DEN_STOP();
		drvif_HDR_RGB2OPT(1, hdr_RGB2OPT[0]);
		WaitFor_DEN_STOP();*/
		fwif_color_set_DM_HDR_3dLUT(1, HDR10_3DLUT_17x17x17);

		#if 0
		static UINT8 demo_switch = 0;
		if (demo_switch % 2 == 0)
			Scaler_color_set_HDR_DEMO_Mode_ON();
		else
			Scaler_color_set_HDR_DEMO_Mode_OFF();
		demo_switch++;
		#endif
	}
	else
	{
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 0;
		Scaler_LGE_HDR10_Enable(0);
	}
	set_HDR10_DM_setting();

}

void Scaler_LGE_ONEKEY_BBC_Enable(unsigned char enable)
{

	//20160717 roger, base on HDR10 first
	 unsigned char table_index;
	 unsigned char source = 255;
        unsigned char *pVipCoefArray = NULL;
  	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	SLR_VIP_TABLE *gVip_Table = NULL;
      	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	if (m_cbFunc_getQualityExtend != NULL)
		   pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend((VIP_SOURCE_TIMING)source);
	else
	          rtd_printk(KERN_DEBUG, TAG_NAME, "PQ table m_cbFunc_getQualityExtend read fail !!!\n");

	table_index=pVipCoefArray[VIP_QUALITY_FUNCTION_Tone_Mapping_Table];

	gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	if (enable) {
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 1;
		Scaler_LGE_HDR10_Enable(1);
	}
	else
	{
		VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 0;
		Scaler_LGE_HDR10_Enable(0);
	}
	set_HDR10_DM_setting();

	if (enable)
	{
		drvif_color_set_BBC_Enable(1);
		extern UINT32 EOTF_LUT_R[1025];
		extern UINT16 OETF_LUT_R[1025];
		fwif_color_rtice_DM2_EOTF_Set(EOTF_LUT_R, EOTF_LUT_R, EOTF_LUT_R);
		fwif_color_rtice_DM2_OETF_Set(OETF_LUT_R, OETF_LUT_R, OETF_LUT_R);
		fwif_color_rtice_DM2_ToneMapping_Set(&(gVip_Table->Tone_Mapping_LUT_R[table_index]), &(gVip_Table->Tone_Mapping_LUT_R[table_index]), &(gVip_Table->Tone_Mapping_LUT_R[table_index]));
		drvif_DM2_GAMMA_Enable(1);
		drvif_Set_DM_HDR_3dLUT_24x24x24_16(1, HDR10_3DLUT_24x24x24);
	}
	else
	{
		drvif_color_set_BBC_Enable(0);
	}

}


UINT32 EOTF_LUT_SDR2HDR[1025] = {0};
void Scaler_LGE_ONEKEY_SDR2HDR_Enable(unsigned char enable)
{
	//base no HDR10
	Scaler_LGE_ONEKEY_HDR10_Enable(1);

	extern UINT16 OETF_LUT_R[1025];

	//make identity EOTF
	UINT16 i;
	for (i = 1; i < 1024; i++)
		EOTF_LUT_SDR2HDR[i] = (1 << 22) * i;
	EOTF_LUT_SDR2HDR[1024] = 0xffffffff;
	fwif_color_rtice_DM2_EOTF_Set(EOTF_LUT_SDR2HDR, EOTF_LUT_SDR2HDR, EOTF_LUT_SDR2HDR);
	fwif_color_rtice_DM2_OETF_Set(OETF_LUT_R, OETF_LUT_R, OETF_LUT_R);
	drvif_Set_DM_HDR_3dLUT_24x24x24_16(1, HDR10_3DLUT_24x24x24);

	//DM status for SDR2HDR
	IoReg_Write32(DM_dm_submodule_enable_reg, 0x00000402);
	//apply
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);

	//no channel swap
	IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, 0);

}

void Scaler_color_set_HDR_DEMO_Mode_ON(void)
{
	return;	//20160110 LGE spec out
  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_DEMO_EN] = 1;

	#if 1
	#if 0 // mac5 fix me
	//set screen separate left side main/ right side sub
	IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, 0x00000001);
	IoReg_Write32(PPOVERLAY_Highlight_window_H_initial_start_width_reg, 0x07800780);
	IoReg_Write32(PPOVERLAY_Highlight_window_V_initial_start_height_reg, 0x00000870);
	IoReg_Write32(PPOVERLAY_Highlight_window_update_step_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_H_boundary_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_V_boundary_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_H_status_reg, 0x07800780);
	IoReg_Write32(PPOVERLAY_Highlight_window_V_status_reg, 0x00000870);
	IoReg_Write32(PPOVERLAY_Highlight_window_boundary_condition_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_border_width_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_min_status_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_DB_CTRL_reg, 0x00000000);
	IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, 0x00000003);
	#endif
	//IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, 0xc00c0c1d);//Global control -> bit28=0 //mac5p fix me : need remap
	//IoReg_Write32(0xb802a100, 0x01A0007F);//ICM overlay use sub
	IoReg_Write32(COLOR_DCC_D_DCC_CTRL_reg, 0x80000001);//DCC overlay use sub
	IoReg_Write32(GAMMA_GAMMA_CTRL_1_reg, 0x00000010);//Gamma table

	//set inv gamma to sub
	fwif_color_set_Inv_gamma_DEMO_TV006();

	#else

	IoReg_Write32(0xb8028328, 0x00000000);
	IoReg_Write32(0xb8028328, 0x00000001);
	IoReg_Write32(0xb802832c, 0x07800780);
	IoReg_Write32(0xb8028330, 0x00000870);
	IoReg_Write32(0xb8028334, 0x00000000);
	IoReg_Write32(0xb8028338, 0x00000000);
	IoReg_Write32(0xb802833c, 0x00000000);
	IoReg_Write32(0xb8028340, 0x07800780);
	IoReg_Write32(0xb8028344, 0x00000870);
	IoReg_Write32(0xb8028348, 0x00000000);
	IoReg_Write32(0xb802834c, 0x00000000);
	IoReg_Write32(0xb8028350, 0x00000000);
	IoReg_Write32(0xb8028154, 0x00000000);
	IoReg_Write32(0xb8028328, 0x00000003);
	IoReg_Write32(0xb802a000, 0xc00c0c1d);//Global control -> bit28=0
	//IoReg_Write32(0xb802a100, 0x01A0007F);//ICM overlay use sub
	IoReg_Write32(0xb802e400, 0x80000001);//DCC overlay use sub
	IoReg_Write32(0xb802c104, 0x00000010);//Gamma table




	#endif
}

void Scaler_color_set_HDR_DEMO_Mode_OFF(void)
{
	return;	//20160110 LGE spec out
  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if(VIP_RPC_system_info_structure_table == NULL){
		VIPprintf("[%s:%d] Warning here!! system_info=NULL! \n",__FILE__, __LINE__);
		return;
	}

	VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_DEMO_EN] = 0;

	//0xb802e400 [31] =0
	IoReg_ClearBits(COLOR_DCC_D_DCC_CTRL_reg, _BIT31);
	//set inv gamma off /* mark this, set inv gamma enable in hal function "VPQ_IOC_SET_COLOR_GAMUT", elieli*/
	/*drvif_color_inv_gamma_enable(SLR_MAIN_DISPLAY, 0, 0);*/
	/*drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, 0, 0);*/
	fwif_color_reset_invGamma_tv006(0);

	//setgamma on
	drvif_color_gamma_enable(SLR_SUB_DISPLAY, 1, 0);

	//off demo mode
//	IoReg_Write32(PPOVERLAY_Highlight_window_control_reg, 0x00000002); // mac5 fix me

}

void Scaler_color_set_m_nowSource(unsigned char value) {

	m_nowSource = value;

}


unsigned char Scaler_color_get_m_nowSource(void) {

	return m_nowSource;

}

unsigned char Scaler_Set_I_De_XC_by_viptable(void)//for dexc garbage when power on in Merlin3
{
	SLR_VIP_TABLE *gVIP_Table = NULL;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	unsigned char which_vip_src = 0;
	unsigned char value;

	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	gVIP_Table = fwif_colo_get_AP_vip_table_gVIP_Table();

	if (VIP_RPC_system_info_structure_table == NULL || gVIP_Table == NULL) {
		value = 255;
	} else {
		which_vip_src = VIP_RPC_system_info_structure_table->VIP_source;
		value = gVIP_Table->VIP_QUALITY_Extend_Coef[which_vip_src][VIP_QUALITY_FUNCTION_I_De_XC];
	}

	/*dirty solution, scaler flow don't go "drv_memory_set_ip_fifo_Mer2" while PC Mode, turn off de-xc in PC mode*/
	if ((Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP) == 0) && (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_RTNR) == 0))
		value = 255;

	return fwif_color_Set_I_De_XC(value);
	
}


unsigned char  Scaler_Set_I_De_XC(unsigned char value)
{

	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	pTable->I_De_XC= value;	

	return fwif_color_Set_I_De_XC(value);

}

unsigned char Scaler_Get_I_De_XC(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->I_De_XC;
}


#if 0 // I-decontour not implemented in Mac5p, 20161219 jimmy
unsigned char  Scaler_Set_I_De_Contour(unsigned char value)
{
	return fwif_color_Set_I_De_Contour(value);

}
#endif
#ifdef MAC5_NO_RGBW
void  Scaler_Set_BOE_RGBW(int w_rate)
{
	// 20160627 jyyang
	fwif_color_set_BOE_RGBW(w_rate);
}
#endif

UINT32 andMASK_Table[32]=	{
							0x00000001, 0x00000003, 0x00000007, 0x0000000f,
							0x0000001f, 0x0000003f, 0x0000007f, 0x000000ff,
							0x000001ff, 0x000003ff, 0x000007ff, 0x00000fff,
							0x00001fff, 0x00003fff, 0x00007fff, 0x0000ffff,
							0x0001ffff, 0x0003ffff, 0x0007ffff, 0x000fffff,
							0x001fffff, 0x003fffff, 0x007fffff, 0x00ffffff,
							0x01ffffff, 0x03ffffff, 0x07ffffff, 0x0fffffff,
							0x1fffffff, 0x3fffffff, 0x7fffffff, 0xffffffff
							};

extern PQ_device_struct *g_Share_Memory_PQ_device_struct;
extern bool PQ_check_source_table[PQ_check_MAX][VIP_QUALITY_SOURCE_NUM];

unsigned int vpq_PQ_get_register_value(unsigned int pq_register, unsigned char pq_bitup, unsigned char pq_bitlow){
	unsigned int pq_check_register_value;
	unsigned int and_reg;
	pq_check_register_value = IoReg_Read32(pq_register);
	and_reg = andMASK_Table[(pq_bitup-pq_bitlow)]<<pq_bitlow;
	return ((pq_check_register_value&and_reg)>>pq_bitlow);
}

extern PQ_check_struct PQ_check_register_table[200];

void vpq_PQ_check_register_value(char *item_name, unsigned char source, unsigned int *PQ_check_error, unsigned int *PQ_check_error_count){
	unsigned int i=0;
	unsigned int pq_check_source, pq_check_bitup, pq_check_bitlow, pq_check_value,pq_check_register_value;
	unsigned int and_reg;

	for(i=0; i<200; i++){
		if(PQ_check_register_table[i].PQ_check_table_register.pq_check_register == 0)
			break;
		if((strcmp(PQ_check_register_table[i].PQ_check_table_item, item_name) != 0)&&(strcmp("ALL", item_name) != 0))
			continue;

		if(PQ_check_source_table[PQ_check_register_table[i].PQ_check_source[0]][source] && PQ_check_source_table[PQ_check_register_table[i].PQ_check_source[1]][source] && PQ_check_source_table[PQ_check_register_table[i].PQ_check_source[2]][source] ){
			pq_check_register_value = vpq_PQ_get_register_value(PQ_check_register_table[i].PQ_check_table_register.pq_check_register, PQ_check_register_table[i].PQ_check_table_register.pq_check_bitup, PQ_check_register_table[i].PQ_check_table_register.pq_check_bitlow);

			if(pq_check_register_value != PQ_check_register_table[i].PQ_check_table_value){
				PQ_check_error[(10*(*PQ_check_error_count))+0] = (unsigned int)source;
				PQ_check_error[(10*(*PQ_check_error_count))+1] = (unsigned int)PQ_check_register_table[i].PQ_check_table_register.pq_check_register;
				PQ_check_error[(10*(*PQ_check_error_count))+2] = (unsigned int)PQ_check_register_table[i].PQ_check_table_register.pq_check_bitup;
				PQ_check_error[(10*(*PQ_check_error_count))+3] = (unsigned int)PQ_check_register_table[i].PQ_check_table_register.pq_check_bitlow;
				PQ_check_error[(10*(*PQ_check_error_count))+4] = 0;
				PQ_check_error[(10*(*PQ_check_error_count))+5] = 0;
				PQ_check_error[(10*(*PQ_check_error_count))+6] = 0;
				PQ_check_error[(10*(*PQ_check_error_count))+7] = 0;
				PQ_check_error[(10*(*PQ_check_error_count))+8] = (unsigned int)PQ_check_register_table[i].PQ_check_table_value;
				PQ_check_error[(10*(*PQ_check_error_count))+9] = (unsigned int)pq_check_register_value;
				(*PQ_check_error_count)++;
			}
			if (NULL == g_Share_Memory_PQ_device_struct){
				rtd_printk(KERN_DEBUG, TAG_NAME, "g_Share_Memory_PQ_device_struct == NULL\n");
			}else{
				if(g_Share_Memory_PQ_device_struct->pqautocheck_en){
					rtd_printk(KERN_DEBUG, TAG_NAME, "PQ_auto_check_error source %d, %x[%d,%s]\n", source, PQ_check_register_table[i].PQ_check_table_register.pq_check_register, PQ_check_register_table[i].PQ_check_table_register.pq_check_bitup, PQ_check_register_table[i].PQ_check_table_register.pq_check_bitlow);
				}
			}
		}
	}


}


extern PQ_check_diff_struct PQ_check_register_diff_table[200];

void vpq_PQ_check_diff_register_value(char *item_name, unsigned char source, unsigned int *PQ_check_error, unsigned int *PQ_check_error_count){
	unsigned int i=0;
	unsigned int pq_check_source, pq_check_value=0;
	unsigned int pq_check_register_value_1;
	unsigned int pq_check_register_value_2;
	for(i=0; i<200; i++){
		if((PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_register == 0) && (PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_2.pq_check_register == 0))
			break;
		if((strcmp(PQ_check_register_diff_table[i].PQ_check_register_diff_table_item, item_name) != 0)&&(strcmp("ALL", item_name) != 0))
			continue;

		if(PQ_check_source_table[PQ_check_register_diff_table[i].PQ_check_register_diff_table_source[0]][source] && PQ_check_source_table[PQ_check_register_diff_table[i].PQ_check_register_diff_table_source[1]][source] && PQ_check_source_table[PQ_check_register_diff_table[i].PQ_check_register_diff_table_source[2]][source] ){
			pq_check_register_value_1 = vpq_PQ_get_register_value(PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_register, PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_bitup, PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_bitlow);
			pq_check_register_value_2 = vpq_PQ_get_register_value(PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_2.pq_check_register, PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_2.pq_check_bitup, PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_2.pq_check_bitlow);
			if(PQ_check_register_diff_table[i].PQ_check_register_diff_table_Operand == '+')
				pq_check_value = pq_check_register_value_1 + pq_check_register_value_2;
			else if(PQ_check_register_diff_table[i].PQ_check_register_diff_table_Operand == '-')
				pq_check_value = pq_check_register_value_1 - pq_check_register_value_2;
			else if(PQ_check_register_diff_table[i].PQ_check_register_diff_table_Operand == '&')
				pq_check_value = pq_check_register_value_1 & pq_check_register_value_2;
			else if(PQ_check_register_diff_table[i].PQ_check_register_diff_table_Operand == '|')
				pq_check_value = pq_check_register_value_1 | pq_check_register_value_2;

			if(pq_check_value != PQ_check_register_diff_table[i].PQ_check_register_diff_table_value){
				PQ_check_error[(10*(*PQ_check_error_count))+0] = (unsigned int)source;
				PQ_check_error[(10*(*PQ_check_error_count))+1] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_register;
				PQ_check_error[(10*(*PQ_check_error_count))+2] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_bitup;
				PQ_check_error[(10*(*PQ_check_error_count))+3] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_bitlow;
				PQ_check_error[(10*(*PQ_check_error_count))+4] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_Operand;
				PQ_check_error[(10*(*PQ_check_error_count))+5] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_2.pq_check_register;
				PQ_check_error[(10*(*PQ_check_error_count))+6] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_2.pq_check_bitup;
				PQ_check_error[(10*(*PQ_check_error_count))+7] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_2.pq_check_bitlow;
				PQ_check_error[(10*(*PQ_check_error_count))+8] = (unsigned int)PQ_check_register_diff_table[i].PQ_check_register_diff_table_value;
				PQ_check_error[(10*(*PQ_check_error_count))+9] = (unsigned int)pq_check_value;
				(*PQ_check_error_count)++;
			}
			if (NULL == g_Share_Memory_PQ_device_struct){
				rtd_printk(KERN_DEBUG, TAG_NAME, "g_Share_Memory_PQ_device_struct == NULL\n");
			}else{
				if(g_Share_Memory_PQ_device_struct->pqautocheck_en){
					rtd_printk(KERN_DEBUG, TAG_NAME, "PQ_auto_check_error source %d, %x[%d,%s]\n", source, PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_register, PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_bitup, PQ_check_register_diff_table[i].PQ_check_register_diff_table_register_1.pq_check_bitlow);
				}
			}
		}
	}

}
void vpq_PQ_check_timming(char *item_name, unsigned int *PQ_check_error) {
	unsigned char source = 255;
	unsigned int PQ_check_error_count = 1;

	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);
	vpq_PQ_check_register_value(item_name, source, PQ_check_error, &PQ_check_error_count);
	vpq_PQ_check_diff_register_value(item_name, source, PQ_check_error, &PQ_check_error_count);
	PQ_check_error[0] = PQ_check_error_count-1;
	PQ_check_error[1] = 0;
	PQ_check_error[2] = 0;
	PQ_check_error[3] = 0;
	PQ_check_error[4] = 0;
	PQ_check_error[5] = 0;
	PQ_check_error[6] = 0;
	PQ_check_error[7] = 0;
	PQ_check_error[8] = 0;
	PQ_check_error[9] = 0;

}

unsigned char  Scaler_Set_SLD(unsigned char value)
{
#ifdef MAC5_NO_SLD
#if 0/*SLD, hack, elieli*/
	DRV_Still_Logo_Detection_Table disable = {0};
	DRV_Still_Logo_Detection_Table *ptr;
#endif
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	//SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();

	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 1;
	}

#ifdef MAC5_NO_SLD
/*SLD, hack, elieli*/
	if (value >= SLD_Table_NUM)
		ptr = &disable;
	else
		ptr = &gVip_Table->Still_Logo_Detection_Table[value];

	VIP_system_info_structure_table->PQ_Setting_Info.SLD_INFO.table_sel = value;

	fwif_color_set_SLD_input_size(VIP_system_info_structure_table->D_Width, VIP_system_info_structure_table->D_Height);

	fwif_color_set_SLD_Ctrl(0, ptr);
	fwif_color_set_SLD_curve_map(0, ptr);
	fwif_color_set_SLD_drop(0, ptr);
#endif
	return 0;
#endif
}

void Scaler_color_colorwrite_Output_InvOutput_gamma(unsigned char value)
{
	unsigned char src_idx = 0;
	unsigned char display = 0;
	StructColorDataType *pTable = NULL;

	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;
	pTable->Output_InvOutput_GAMMA= value;

	if (Get_DISPLAY_PANEL_MPLUS_RGBW() != TRUE) /* MPLUS case, use HAL*/
		fwif_color_colorwrite_Output_gamma(value);
	#ifdef MAC5_NO_INV_OUTPUT_GAMMA
	fwif_color_colorwrite_InvOutput_gamma(value);
	#endif

}

unsigned char Scaler_Get_Output_InvOutput_gamma(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;
	return pTable->Output_InvOutput_GAMMA;
}

void set_HDR10_DM_setting(void)
{
	//set HDR10 DM
	extern dm_dm_submodule_enable_RBUS dm_submodule_temp;
	dm_dm_submodule_enable_RBUS dm_submodule_enable;
	dm_submodule_enable.regValue = IoReg_Read32(DM_dm_submodule_enable_reg);

	dm_submodule_enable.dither_en = dm_submodule_temp.dither_en;
	dm_submodule_enable.b0502_enable = dm_submodule_temp.b0502_enable;
	dm_submodule_enable.b0501_enable = dm_submodule_temp.b0501_enable;
	dm_submodule_enable.b04_enable = dm_submodule_temp.b04_enable;
	dm_submodule_enable.b03_enable = dm_submodule_temp.b03_enable;
	dm_submodule_enable.b01_07_enable = dm_submodule_temp.b01_07_enable;
	dm_submodule_enable.b01_06_enable = dm_submodule_temp.b01_06_enable;
	dm_submodule_enable.b01_05_enable = dm_submodule_temp.b01_05_enable;
	dm_submodule_enable.b01_04_enable = dm_submodule_temp.b01_04_enable;
	dm_submodule_enable.b01_03_enable = dm_submodule_temp.b01_03_enable;
	dm_submodule_enable.b01_02_enable = dm_submodule_temp.b01_02_enable;
	dm_submodule_enable.b01_01_422to444_enable = dm_submodule_temp.b01_01_422to444_enable;
	dm_submodule_enable.b01_01_420to422_enable = dm_submodule_temp.b01_01_420to422_enable;

	IoReg_Write32(DM_dm_submodule_enable_reg, dm_submodule_enable.regValue);
	//apply
	dm_hdr_double_buffer_ctrl_RBUS dm_double_buffer_ctrl_reg;
	dm_double_buffer_ctrl_reg.regValue = IoReg_Read32(DM_HDR_Double_Buffer_CTRL_reg);
	dm_double_buffer_ctrl_reg.dm_db_apply = 1;
	IoReg_Write32(DM_HDR_Double_Buffer_CTRL_reg, dm_double_buffer_ctrl_reg.regValue);
}

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
void Scaler_Share_Memory_Access_VIP_TABLE_Custom_Struct(unsigned long arg)
{
	printk("Scaler_Share_Memory_Access_VIP_TABLE_Custom_Struct\n");
	g_Share_Memory_VIP_TABLE_Custom_Struct_isr= ((SLR_VIP_TABLE_CUSTOM_TV001 *)arg);
}
#endif

char Scaler_color_Set_PQ_ByPass_Lv(unsigned char table_idx)
{
	char ret;

	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	ret = fwif_color_PQ_ByPass_Handler(table_idx, 1, VIP_RPC_system_info_structure_table, 0);

	return ret;
}

char Scaler_color_Get_PQ_ByPass_Lv(void)
{
	char ret;

	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;
	VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	ret = fwif_color_PQ_ByPass_Handler(NULL, 0, VIP_RPC_system_info_structure_table, 0);

	return ret;
}

char Scaler_color_Get_HDR10_OETF_ByMaxCLL_ByPanelLuminance(unsigned short *OETF_TBL)
{
	extern VIP_HDR10_OETF_ByLuminace_TBL HDR10_OETF_ByLuminace_TBL;
	unsigned char input_src_type;
	unsigned char input_src_form;
	unsigned char input_timming_info;
	SLR_VOINFO* pVOInfo = NULL;
	vfe_hdmi_drm_t drm_info;
	unsigned short MaxCLL, panel_Luminance, MaxFALL;

	if (fwif_color_get_force_run_i3ddma_enable(SLR_MAIN_DISPLAY) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_VDEC)) {
		fwif_color_vsc_to_scaler_src_mapping(Get_DisplayMode_Src(SLR_MAIN_DISPLAY), &input_src_type, &input_src_form);
		input_timming_info 	= drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_MODE_CURR);
	} else {
		input_src_type = Scaler_InputSrcGetMainChType();
		input_src_form = Scaler_InputSrcGetMainChFrom();
		input_timming_info 	= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	}

	pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
	/* get drm info*/
	vfe_hdmi_drv_get_drm_info(&drm_info);

	if (pVOInfo == NULL || OETF_TBL == NULL) {
		rtd_printk(KERN_EMERG, TAG_NAME, "Scaler_color_Get_HDR10_OETF_ByMaxCLL_ByPanelLuminance, table=NULL, pVOInfo=%p, OETF_TBL=%p, return !!!!\n", pVOInfo, OETF_TBL);
		return -1;
	}

	if(input_src_type == _SRC_VO) {
		MaxCLL = pVOInfo->MaxCLL;
		MaxFALL = pVOInfo->MaxFALL;
	} else if (input_src_type == _SRC_HDMI) {
		MaxCLL = drm_info.maximum_content_light_level;
		MaxFALL = drm_info.maximum_frame_average_light_level;
	} else {
		rtd_printk(KERN_INFO, TAG_NAME, "Scaler_color_Get_HDR10_OETF_ByMaxCLL_ByPanelLuminance, is not VO or HDMI, SRC=%d\n", input_src_type);
		return 1;
	}

	panel_Luminance = HDR10_OETF_ByLuminace_TBL.panel_Luminace;

	rtd_printk(KERN_INFO, TAG_NAME, "OETF get, input_src_type=%d, panel_Luminance=%d, MaxCLL=%d,MaxFALL=%d\n", input_src_type, panel_Luminance, MaxCLL, MaxFALL);

	/*MaxCLL == 0, can not get maxCLL*/
	if ((MaxCLL == 0) || (MaxCLL >= panel_Luminance))
		MaxCLL = panel_Luminance;

	if (MaxCLL <= 100)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_100N[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 150)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_150N[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 200)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_200N[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 250)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_250B[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 300)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_300B[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 350)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_350B[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 400)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_400B[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 500)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_500N6[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 600)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_600N6[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 660)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_660N6[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 700)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_700N6[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 800)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_800N6[0], sizeof(short)*OETF_size);
	else if (MaxCLL <= 1000)
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_1000N6[0], sizeof(short)*OETF_size);
	else
		memcpy((unsigned char*)OETF_TBL, (unsigned char*)&HDR10_OETF_ByLuminace_TBL.OETF_1000Over[0], sizeof(short)*OETF_size);

	return 0;
}

void Scaler_color_Set_HDR_AutoRun(unsigned char nEnable)
{
	m_bHDR_AutoRun = nEnable;
	printk("HDR_AutoRun=%d  \n", m_bHDR_AutoRun);
}
unsigned char Scaler_color_Get_HDR_AutoRun(void)
{
	return m_bHDR_AutoRun;
}

#define REG_DEGREE (110)
#define REG_DEGREE_LV2 (115)
#define REG_DEGREE_LV3 (120)
/*
#define REG_DEGREE (115)
#define REG_DEGREE_LV2 (120)
#define REG_DEGREE_LV3 (125)

*/


/**table_iDX
 * Level = 0 => no bypass?? * Level = 1 => I DCTI?�D_DCTI?�V_DCTI?�DLTI : bypass?? * Level = 2 => I DCTI?�D_DCTI?�V_DCTI?�DLTI?�RTNR Y?�RTNR C?�MCNR?�DI IP Enabl

 *  -> reg_deg : set(1)
 *  --> reg_deg+10 : set(2)
 *  reg_deg-5 <- : set(saved_level)
**/
extern int register_temperature_callback(int degree,void *fn, void* data, char *module_name);
static int saved_level = -1;
void Scaler_PQ_thermal_callback(void *data, int cur_degree , int reg_degree, char *module_name)
{
	int tmp = saved_level;
	rtd_printk(KERN_DEBUG, "[Rtk Monitor]", "Scaler_PQ_thermal_callback\n");
	pr_debug("pq_bypass, cur_deg: %d, reg_deg:%d, saved:%d ->%d \n", cur_degree, reg_degree, tmp, saved_level);
	if (cur_degree >= REG_DEGREE_LV2) {
		if (saved_level == -1) {
			saved_level = Scaler_color_Get_PQ_ByPass_Lv();
			if (saved_level < 1)
				Scaler_color_Set_PQ_ByPass_Lv(2);
			else
				saved_level = -1;
			pr_debug("pq_bypass_1, cur_deg: %d, reg_deg:%d, saved:%d ->%d \n", cur_degree, reg_degree, tmp, saved_level);
		}

		if (cur_degree >= REG_DEGREE_LV3) {
			if (Scaler_color_Get_PQ_ByPass_Lv() != 3)
				Scaler_color_Set_PQ_ByPass_Lv(3);
			pr_debug("pq_bypass_2, cur_deg: %d, reg_deg:%d, saved:%d ->%d \n", cur_degree, reg_degree, tmp, saved_level);
		}
		return;
	}


	if (cur_degree <= REG_DEGREE) {
		if (saved_level != -1) { //restore
			//Scaler_color_Set_PQ_ByPass_Lv(saved_level);
			saved_level = -1;
			pr_debug("pq_bypass_-1, cur_deg: %d, reg_deg:%d, saved:%d ->%d \n", cur_degree, reg_degree, tmp, saved_level);
		}
		return;
	}
}

#if 1 //
int Scaler_register_PQ_thermal_handler(void)
{
	int ret;
	int temp;
	#if 1 // mac5 fix me -- undefined reference to `register_temperature_cal
	rtd_printk(KERN_DEBUG, "[Rtk Monitor]", "Scaler_register_PQ_thermal_handler\n");
	if ((ret = register_temperature_callback(REG_DEGREE, Scaler_PQ_thermal_callback, &temp, "PQ_ByPass_Lv")) < 0)
		printk("register PQ thermal handler fail, ret:%d \n", ret);
	#endif
	return 0;
}

late_initcall(Scaler_register_PQ_thermal_handler);
#endif


unsigned char Scaler_GetIamLC_DemoFunction(void)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return 0;

	return pTable->LocalContrastDemoMode;
}

extern unsigned int LC_Backlight_Profile_Interpolation_table[2][2][125];
unsigned char Scaler_IamLC_DemoFunction(unsigned char mode)
{
	unsigned char ret = 255;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	static unsigned char ori_DCC_init_boundary_Type=255;
//	unsigned char temp = 0;
	StructColorDataType *pTable = NULL;
	_system_setting_info *VIP_system_info_structure_table = NULL;


	unsigned int pwCopyTemp=0;
	_clues *smartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	static unsigned int LC_Backlight_Profile_Interpolation_table_temp[2][2][125] = {
		{
			{8, 8, 8, 8, 8, 139, 139, 139, 139, 139, 730, 730, 730, 730, 730, 139, 139, 139, 139, 139, 8, 8, 8, 8, 8, }, // h
			{8, 8, 8, 8, 8, 139, 139, 139, 139, 139, 730, 730, 730, 730, 730, 139, 139, 139, 139, 139, 8, 8, 8, 8, 8, }, //v
		},
		{
			{8, 8, 8, 8, 8, 139, 139, 139, 139, 139, 730, 730, 730, 730, 730, 139, 139, 139, 139, 139, 8, 8, 8, 8, 8, }, // h
			{8, 8, 8, 8, 8, 139, 139, 139, 139, 139, 730, 730, 730, 730, 730, 139, 139, 139, 139, 139, 8, 8, 8, 8, 8, }, //v
		},

	};
	static unsigned int LC_Backlight_Profile_Interpolation_table_ori[2][2][125] = {
		{
			{0,3,8,16,29,45,76,139,234,390,560,695,730,695,560,390,234,139,76,45,29,16,8,3,0,}, // h
			{0,3,8,16,29,45,76,139,234,390,560,695,730,695,560,390,234,139,76,45,29,16,8,3,0,}, //v
		},
		{
			{0,3,8,16,29,45,76,139,234,390,560,695,730,695,560,390,234,139,76,45,29,16,8,3,0,}, // h
			{0,3,8,16,29,45,76,139,234,390,560,695,730,695,560,390,234,139,76,45,29,16,8,3,0,}, //v
		},
	};

	Scaler_Get_Display_info(&display, &src_idx);
	pTable = fwif_color_get_color_data(src_idx, 0);
	pTable->LocalContrastDemoMode = mode;
	ret = 1;
	switch(mode)	//HDR mode
	{
		case 0:
			Scaler_SetLocalContrastEnable(0);
			break;
		case 1:
			Scaler_SetLocalContrastEnable(1);
			fwif_color_set_LC_Global_Region_Num_Size(src_idx,pTable->LocalContrastTable, LC_BLOCK_4x4);
			IoReg_Write32(LC_LC_Local_Shpnr_1st_gain_8_reg, 0x00000004);
			IoReg_Write32(LC_LC_Local_Shpnr_2nd_gain_8_reg, 0x00000003);
			/*change Coeff curve for damo*/
			memcpy(&LC_Backlight_Profile_Interpolation_table, LC_Backlight_Profile_Interpolation_table_temp, sizeof(LC_Backlight_Profile_Interpolation_table));
			fwif_color_set_LC_Backlight_Profile_Interpolation(src_idx, pTable->LocalContrastTable);
		break;
		case 2:
			Scaler_SetLocalContrastEnable(1);
			fwif_color_set_LC_Global_Region_Num_Size(src_idx,pTable->LocalContrastTable, LC_BLOCK_8x4);
			IoReg_Write32(LC_LC_Local_Shpnr_1st_gain_8_reg, 0x00000004);
			IoReg_Write32(LC_LC_Local_Shpnr_2nd_gain_8_reg, 0x00000003);
			/*change Coeff curve for damo*/
			memcpy(&LC_Backlight_Profile_Interpolation_table, LC_Backlight_Profile_Interpolation_table_temp, sizeof(LC_Backlight_Profile_Interpolation_table));
			fwif_color_set_LC_Backlight_Profile_Interpolation(src_idx, pTable->LocalContrastTable);
		break;
		case 3:
			Scaler_SetLocalContrastEnable(1);
			fwif_color_set_LC_Global_Region_Num_Size(src_idx,pTable->LocalContrastTable, LC_BLOCK_16x8);
			IoReg_Write32(LC_LC_Local_Shpnr_1st_gain_8_reg, 0x00000004);
			IoReg_Write32(LC_LC_Local_Shpnr_2nd_gain_8_reg, 0x00000003);
			/*change Coeff curve for damo*/
			memcpy(&LC_Backlight_Profile_Interpolation_table, LC_Backlight_Profile_Interpolation_table_temp, sizeof(LC_Backlight_Profile_Interpolation_table));
			fwif_color_set_LC_Backlight_Profile_Interpolation(src_idx, pTable->LocalContrastTable);
		break;
		case 4:
			Scaler_SetLocalContrastEnable(1);
			fwif_color_set_LC_Global_Region_Num_Size(src_idx,pTable->LocalContrastTable, LC_BLOCK_32x16);
			IoReg_Write32(LC_LC_Local_Shpnr_1st_gain_8_reg, 0x00000004);
			IoReg_Write32(LC_LC_Local_Shpnr_2nd_gain_8_reg, 0x00000003);
			/*change Coeff curve for damo*/
			memcpy(&LC_Backlight_Profile_Interpolation_table, LC_Backlight_Profile_Interpolation_table_ori, sizeof(LC_Backlight_Profile_Interpolation_table));
			fwif_color_set_LC_Backlight_Profile_Interpolation(src_idx, pTable->LocalContrastTable);

			if(ori_DCC_init_boundary_Type!=255){
				pwCopyTemp = smartPic_clue->Remmping_Src_Timing_index;
				memcpy((unsigned char*)&(VIP_system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Advance_control_table[pwCopyTemp].DCC_init_boundary_Type),&ori_DCC_init_boundary_Type,sizeof(unsigned char));
				ori_DCC_init_boundary_Type = 255;
			}

		break;
		case 5:
			Scaler_SetLocalContrastEnable(1);
			fwif_color_set_LC_Global_Region_Num_Size(src_idx,pTable->LocalContrastTable, LC_BLOCK_48x27);
			IoReg_Write32(LC_LC_Local_Shpnr_1st_gain_8_reg, 0x00000004);
			IoReg_Write32(LC_LC_Local_Shpnr_2nd_gain_8_reg, 0x00000003);
			/*change Coeff curve for damo*/
			memcpy(&LC_Backlight_Profile_Interpolation_table, LC_Backlight_Profile_Interpolation_table_ori, sizeof(LC_Backlight_Profile_Interpolation_table));
			fwif_color_set_LC_Backlight_Profile_Interpolation(src_idx, pTable->LocalContrastTable);
			pwCopyTemp = smartPic_clue->Remmping_Src_Timing_index;
			if(ori_DCC_init_boundary_Type==255)
				ori_DCC_init_boundary_Type = VIP_system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Advance_control_table[pwCopyTemp].DCC_init_boundary_Type;
			memset((unsigned char*)&(VIP_system_info_structure_table->PQ_Setting_Info.DCC_info_coef.DCC_Advance_control_table[pwCopyTemp].DCC_init_boundary_Type), 0, sizeof(unsigned char));

		break;
		default:
			ret = 0;        /* LC = off*/
		break;
	}
	IoReg_Mask32(LC_LC_Global_Ctrl1_reg,~_BIT29,_BIT29);
	printk(TAG_NAME, "Scaler_IamLC_DemoFunction, mode=%d,ret=%d\n", mode, ret);

	return ret;
}

unsigned char pq_src_idx = 0;
void Scaler_color_set_pq_src_idx(unsigned char src_idx) //for i3ddma enabled set real src_idx
{
	pq_src_idx = src_idx;
}

unsigned char Scaler_color_get_pq_src_idx(void) //for i3ddma enabled get real src_idx
{
	return pq_src_idx;
}

HDMI_CSC_DATA_RANGE_MODE_T g_HDMICSCDataRangeMode = HDMI_CSC_DATA_RANGE_MODE_AUTO;
HDMI_CSC_DATA_RANGE_MODE_T Scaler_GetHDMI_CSC_DataRange_Mode(void)
{
	return g_HDMICSCDataRangeMode;
}

void Scaler_SetHDMI_CSC_DataRange_Mode(HDMI_CSC_DATA_RANGE_MODE_T value)
{
	if (value > HDMI_CSC_DATA_RANGE_MODE_LIMITED)
		value = HDMI_CSC_DATA_RANGE_MODE_AUTO;
	g_HDMICSCDataRangeMode = value;
}

void Scaler_recheck_sharpness_table(void)
{
	unsigned char source = 255;
	unsigned char *pVipCoefArray = NULL;

	if (vpqex_project_id == 0x00060000)
		return;

	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/

	if (m_cbFunc_getQualityExtend3 != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)source);
	else {
		rtd_printk(KERN_DEBUG, TAG_NAME, "PQ table m_cbFunc_getQualityExtend3 read fail !!!\n");
		return;
	}

	if (!(source >= VIP_QUALITY_TOTAL_SOURCE_NUM || pVipCoefArray == NULL)) {
		if (Scaler_GetSharpnessTable() != pVipCoefArray[VIP_QUALITY_FUNCTION_SharpTable]) {
			Scaler_SetSharpnessTable(pVipCoefArray[VIP_QUALITY_FUNCTION_SharpTable]);
			Scaler_SetSharpness(Scaler_GetSharpness());
		}
	}
}

unsigned char Scaler_Get_CinemaMode_PQ(void)
{
	return g_picmode_Cinema;
}

void Scaler_Set_CinemaMode_PQ(unsigned char mode)
{
	unsigned char source = 255;
	unsigned char *pVipCoefArray = NULL;
	unsigned char *drvSkip_Array;
	SLR_VIP_TABLE *gVIP_Table;

	g_picmode_Cinema = mode;
	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/

	if (mode != 0) {
		drvif_color_Icm_Enable(0);
	} else {
		if (m_cbFunc_getQualityExtend3 != NULL)
			pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)source);
		else {
			rtd_printk(KERN_DEBUG, TAG_NAME, "PQ table m_cbFunc_getQualityExtend3 read fail !!!\n");
			return;
		}

		gVIP_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
		if (NULL == gVIP_Table)
			return;

		drvSkip_Array = &(gVIP_Table->DrvSetting_Skip_Flag[0]);

		if (!drvSkip_Array[DrvSetting_Skip_Flag_ICM] && (pVipCoefArray[VIP_QUALITY_FUNCTION_ICM] < VIP_ICM_TBL_X))
			drvif_color_Icm_Enable(1);
	}
}

bool Scaler_Init_OD(void)
{
	return fwif_color_od_init(10, 1, 60);
}

unsigned char Scaler_Get_OD_Bits(void)
{
	return fwif_color_get_od_bits();
}

unsigned char Scaler_Set_OD_Bits(unsigned char bits)
{
	return fwif_color_set_od_bits(bits);
}

unsigned char Scaler_Get_OD_Enable(void)
{
	return fwif_color_get_od_en();
}

unsigned char Scaler_OD_Test(unsigned char en)
{
	return fwif_color_od_test(en?1:0);
}

unsigned char Scaler_Get_PQ_table_bin_En(void)
{
	return PQ_bin_info;
}

void Scaler_Set_PQ_table_bin_En(unsigned char en)
{
	PQ_bin_info = en;
}


unsigned char g_cur_picmode_vip_src = 0;
unsigned char g_vip_src_resync_flag = false;
void Scaler_Set_PicMode_VIP_src(unsigned char src)
{
	g_cur_picmode_vip_src = src;
}

void Scaler_Check_VIP_src_resync_flag(void)
{
	unsigned int vipsource = 0;
	extern unsigned char g_pq_bypass_lv;

	vipsource = fwif_vip_source_check(3, NOT_BY_DISPLAY);
	if (g_cur_picmode_vip_src != vipsource && g_pq_bypass_lv != 9) {
		g_cur_picmode_vip_src = vipsource;
		g_vip_src_resync_flag = true;
	} else
		g_vip_src_resync_flag = false;
}

unsigned char Scaler_Get_VIP_src_resync_flag(void)
{
	if (g_vip_src_resync_flag) {
		g_vip_src_resync_flag = false;
		return true;
	}

	return false;
}

unsigned char  Scaler_Set_VIP_HANDLER_RESET(void)
{
	VIPprintf("Scaler_Set_VIP_HANDLER_RESET\n");
	fwif_color_video_quality_handler();

	return TRUE;
}

unsigned char Scaler_Set_OD_Bit_By_XML(void)
{
	if (get_current_driver_pattern(DRIVER_OD_PATTERN) == 0) { //OD_OFF
		return fwif_color_set_od_bits(0);
	} else if (get_current_driver_pattern(DRIVER_OD_PATTERN) == 3) { //OD_3BIT
		return fwif_color_set_od_bits(3);
	} else if (get_current_driver_pattern(DRIVER_OD_PATTERN) == 4) { //OD_4BIT
		return fwif_color_set_od_bits(4);
	} else if (get_current_driver_pattern(DRIVER_OD_PATTERN) == 5) { //OD_5BIT
		return fwif_color_set_od_bits(5);
	} else if (get_current_driver_pattern(DRIVER_OD_PATTERN) == 6) { //OD_6BIT
		return fwif_color_set_od_bits(6);
	} else if (get_current_driver_pattern(DRIVER_OD_PATTERN) == 7) { //OD_7BIT
		return fwif_color_set_od_bits(7);
	}

	return TRUE;
}

void Scaler_color_get_LC_Blight_dat(unsigned int *ptr_out)
{
	fwif_color_get_LC_Blight_dat(ptr_out);
}

void Scaler_color_get_LC_His_dat(unsigned int *plc_out)
{
	 fwif_color_get_LC_Hist_dat(plc_out);
}

UINT8 Scaler_color_get_colorspace_index()
{
	UINT8 colorspace_index = 1; /*default value is 1*/
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if (VIP_system_info_structure_table == NULL) 
		return;

	switch(VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode)
	{
	case YUV2RGB_INPUT_2020_NonConstantY:
	case YUV2RGB_INPUT_2020_ConstantY:
	case YUV2RGB_INPUT_2020_NonConstantY_Full:
	case YUV2RGB_INPUT_2020_ConstantY_Full:
		colorspace_index = 4;	/*case BT2020*/
		break;
	case YUV2RGB_INPUT_709_Limted:
	case YUV2RGB_INPUT_709_Full:
		colorspace_index = 2;	/*case BT709*/
		break;
	default:
		colorspace_index = 1;	/*case default*/
		break;
	}
	return colorspace_index;

}


void Scaler_color_set_DDomain3DLUT_gamma_by_colorspace(UINT8 colorspace_index)
{
	extern UINT8 DDomain3DLUT_Gamma_control[5][3];

	fwif_color_3d_lut_init_tv006();
	fwif_color_set_3dLUT(DDomain3DLUT_Gamma_control[colorspace_index][0]);
	drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, DDomain3DLUT_Gamma_control[colorspace_index][1], 1);
	fwif_set_gamma(DDomain3DLUT_Gamma_control[colorspace_index][2], 0, 0, 0);

}

unsigned char Scaler_get_dcc_table_by_source(unsigned char table_mode)
{
	unsigned char source = 255;
	unsigned char *pVipCoefArray = NULL;
	unsigned char table_num=0;
	
	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	if (m_cbFunc_getQualityExtend3 != NULL)
		pVipCoefArray = (unsigned char *)m_cbFunc_getQualityExtend3((VIP_SOURCE_TIMING)source);
	else{
		printk("m_cbFunc_getQualityExtend3=null,get dcc table fail!!!\n");
		return;
	}

	switch(table_mode)
	{
		case 0: // dcc 
			table_num=pVipCoefArray[VIP_QUALITY_FUNCTION_DCC_Table_Select];
			break;
		case 1: // dcc skintone
			table_num=pVipCoefArray[VIP_QUALITY_FUNCTION_DCC_Skin_Tone_Table_Select];
			break;
		default:
			break;
	}
	//printk("tim_li,get dcc table->table mode=%d,table_num=%d \n",table_mode,table_num);
	
	return table_num;
}
