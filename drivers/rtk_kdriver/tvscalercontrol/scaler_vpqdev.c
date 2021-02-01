/*Kernel Header file*/
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/fs.h>		/* everything... */
#include <linux/cdev.h>
#include <linux/platform_device.h>

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/pageremap.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/hrtimer.h>
#include <linux/vmalloc.h>

/*RBUS Header file*/
#include <scalercommon/scalerCommon.h>

/*TVScaler Header file*/
#include "tvscalercontrol/io/ioregdrv.h"
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>
#include <tvscalercontrol/vip/viptable.h>
#include <tvscalercontrol/scaler_vpqmemcdev.h>
#include "scaler_vpqdev.h"
#include "scaler_vscdev.h"
#include <tvscalercontrol/vip/pq_rpc.h>
//#include <mach/RPCDriver.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scalerdrv/scalerip.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <rbus/mis_gpio_reg.h>
#include <mach/rtk_log.h>
#include <tvscalercontrol/panel/panelapi.h>
//#include <tvscalercontrol/vo/rtk_vo.h>


#define TAG_NAME "VPQ"

static dev_t vpq_devno;/*vpq device number*/
static struct cdev vpq_cdev;

static struct semaphore VPQ_Semaphore;
struct semaphore VPQ_DM_3DLUT_Semaphore;
struct semaphore VPQ_Semaphore_extern;

extern unsigned int PCID_ValueTBL[81];
extern unsigned int POD_ValueTBL_1[81];
extern unsigned int POD_ValueTBL_2[81];

extern UINT32 EOTF_LUT_HLG_DEFAULT[1025];
extern UINT16 OETF_LUT_HLG_DEFAULT[1025];
extern UINT16 HDR10_3DLUT_24x24x24[HDR_24x24x24_size][3];

static unsigned char PQ_Dev_Status = PQ_DEV_NOTHING;
static unsigned char Demo_Flag = false;

static GAMMA_RGB_T gamma;
extern COLORELEM_TAB_T icm_tab_elem_of_vip_table;
extern COLORELEM_TAB_T icm_tab_elem_write;

extern unsigned char bODInited;


UINT8 g_Color_Mode = COLOR_MODE_ADV;
UINT8 g_flag_cm_adv_init_ok;
UINT8 g_flag_cm_exp_init_ok;
CHIP_CM_REGION_T g_cm_rgn_adv = {{
	{{	TRUE,
		CHIP_CM_COLOR_REGION_RED,		//INDEX_0	//INDEX_1	//INDEX_2	//INDEX_3	//INDEX_4	//INDEX_5//INDEX_6//INDEX_7
		{5632, 5760, 5888, 5888, 0, 64, 128, 192 }, //HUE_index //0~6016
		{174, 220, 220, 220, 220, 220, 190, 170 }, //HUE_gain //0~255
		{384, 512, 1024, 1536, 2048, 3072, 3584, 4096 }, //SAT_index //0~4095
		{128, 215, 230, 220, 200, 201, 180, 130 }, //SAT_gain //0~255
		{512, 1024, 1536, 2048, 2560, 3072, 3584, 4096 }, //ITN_index //0~4095
		{128, 250, 250, 250, 250, 180, 180, 160 }, //ITN_gain //0~255
	},

	{	TRUE,
		CHIP_CM_COLOR_REGION_GRN,		//INDEX_0	//INDEX_1	//INDEX_2	//INDEX_3	//INDEX_4	//INDEX_5//INDEX_6//INDEX_7
		{1152, 1216, 1408, 1536, 2432, 2560, 2688, 2752 }, //HUE_index //0~6016
		{174, 220, 220, 220, 220, 220, 190, 170 }, //HUE_gain //0~255
		{384, 512, 1024, 1536, 2048, 3072, 3584, 4096 }, //SAT_index //0~4095
		{128, 215, 230, 220, 200, 201, 180, 130 }, //SAT_gain //0~255
		{512, 1024, 1536, 2048, 2560, 3072, 3584, 4096 }, //ITN_index //0~4095
		{128, 250, 250, 250, 250, 180, 180, 160 }, //ITN_gain //0~255
	},

	{	TRUE,
		CHIP_CM_COLOR_REGION_BLU,		//INDEX_0	//INDEX_1	//INDEX_2	//INDEX_3	//INDEX_4	//INDEX_5//INDEX_6//INDEX_7
		{2752, 2816, 2944, 3072, 3456, 3584, 3712, 3840 }, //HUE_index //0~6016
		{174, 218, 220, 220, 220, 220, 190, 170 }, //HUE_gain //0~255
		{384, 512, 1024, 1536, 2048, 3072, 3584, 4096 }, //SAT_index //0~4095
		{128, 193, 230, 220, 200, 201, 180, 130 }, //SAT_gain //0~255
		{512, 1024, 1536, 2048, 2560, 3072, 3584, 4096 }, //ITN_index //0~4095
		{110, 160, 220, 220, 220, 180, 180, 160 }, //ITN_gain //0~255
	},

	{	TRUE,
		CHIP_CM_COLOR_REGION_CYN,		//INDEX_0	//INDEX_1	//INDEX_2	//INDEX_3	//INDEX_4	//INDEX_5//INDEX_6//INDEX_7
		{3840, 3840, 3968, 4096, 4224, 4352, 4480, 4480 }, //HUE_index //0~6016
		{174, 174, 220, 220, 220, 220, 190, 190 }, //HUE_gain //0~255
		{384, 512, 1024, 1536, 2048, 3072, 3584, 4096 }, //SAT_index //0~4095
		{128, 206, 230, 220, 200, 201, 180, 130 }, //SAT_gain //0~255
		{0, 512, 1536, 2048, 2560, 3072, 3584, 4096 }, //ITN_index //0~4095
		{128, 250, 250, 250, 250, 180, 180, 160 }, //ITN_gain //0~255
	},

	{	TRUE,
		CHIP_CM_COLOR_REGION_MGT,		//INDEX_0	//INDEX_1	//INDEX_2	//INDEX_3	//INDEX_4	//INDEX_5//INDEX_6//INDEX_7
		{4672, 4736, 4864, 5120, 5248, 5504, 5760, 5888 }, //HUE_index //0~6016
		{174, 220, 220, 220, 220, 220, 190, 170 }, //HUE_gain //0~255
		{384, 512, 1024, 1536, 2048, 3072, 3584, 4096 }, //SAT_index //0~4095
		{128, 215, 230, 220, 200, 201, 180, 130 }, //SAT_gain //0~255
		{0, 512, 1536, 2048, 2560, 3072, 3584, 4096 }, //ITN_index //0~4095
		{128, 250, 250, 250, 250, 180, 180, 160 }, //ITN_gain //0~255
	},

	{	TRUE,
		CHIP_CM_COLOR_REGION_YLW,		//INDEX_0	//INDEX_1	//INDEX_2	//INDEX_3	//INDEX_4	//INDEX_5//INDEX_6//INDEX_7
		{640, 704, 704, 768, 832, 832, 896, 1024 }, //HUE_index //0~6016
		{174, 220, 220, 220, 220, 220, 190, 170 }, //HUE_gain //0~255
		{384, 512, 1024, 1536, 2048, 3072, 3584, 4096 }, //SAT_index //0~4095
		{128, 215, 230, 220, 200, 201, 180, 130 }, //SAT_gain //0~255
		{0, 512, 1536, 2048, 2560, 3072, 3584, 4096 }, //ITN_index //0~4095
		{128, 250, 250, 250, 250, 180, 180, 160 }, //ITN_gain //0~255
	},

	{	TRUE,
		CHIP_CM_COLOR_REGION_SKIN,		//INDEX_0	//INDEX_1	//INDEX_2	//INDEX_3	//INDEX_4	//INDEX_5//INDEX_6//INDEX_7
		{256, 320, 320, 384, 384, 384, 512, 640 }, //HUE_index //0~6016
		{174, 220, 220, 220, 220, 220, 190, 170 }, //HUE_gain //0~255
		{384, 512, 1024, 1536, 2048, 3072, 3584, 4096 }, //SAT_index //0~4095
		{128, 215, 230, 220, 200, 201, 180, 130 }, //SAT_gain //0~255
		{0, 512, 1536, 2048, 2560, 3072, 3584, 4096 }, //ITN_index //0~4095
		{128, 250, 250, 250, 250, 180, 180, 160 }, //ITN_gain //0~255
	},},
	0,
}};
CHIP_CM_REGION_T g_cm_rgn_exp;
CHIP_COLOR_CONTROL_T g_cm_ctrl_adv;
CHIP_COLOR_CONTROL_T g_cm_ctrl_exp;
unsigned char g_cm_need_refresh = 1;
unsigned char g_cm_keep_Y = 0;
extern unsigned char set_PS_in_ISR;
extern UINT16 GOut_R[1025];
extern UINT16 GOut_G[1025];
extern UINT16 GOut_B[1025];

extern unsigned int final_GAMMA_R[512];
extern unsigned int final_GAMMA_G[512];
extern unsigned int final_GAMMA_B[512];

unsigned char g_InvGammaPowerMode=0;
unsigned char g_IsInvGammaPowerNewMode=0;
unsigned char g_HDR3DLUTForceWrite = 1;
extern unsigned short Power1div22Gamma[1025];
extern unsigned short Power22InvGamma[1025];
unsigned short g_GammaRemap[4097];

unsigned char uc3DCorrectionEn;
extern unsigned char bForceHist3DCtrl;

unsigned char g_srgbForceUpdate=1;
unsigned char str_resume_do_picturemode=0;
unsigned char g_srgbForceUpdate2=1;
static unsigned char ucColorFilterMode;
static COLORTEMP_ELEM_T curColorTemp = {512, 512, 512, 512, 512, 512};
DRV_Sharpness_Table tDRV_Sharpness_Table;

//Game mode cmd checking flow @Cixus 20161204
extern unsigned int game_mode_cmd_check;

unsigned int vpq_project_id = 0x00060000; /*pre_id:16 main_id:8 sub1_id:8 sub2_id:8, example->lg=tv006*/
extern unsigned int vpqex_project_id;

CHIP_SHARPNESS_UI_T tCurCHIP_SHARPNESS_UI_T;
CHIP_SHARPNESS_UI_T t3DCHIP_SHARPNESS_UI_T;
CHIP_EDGE_ENHANCE_UI_T tCurCHIP_EDGE_ENHANCE_UI_T;
CHIP_SR_UI_T tCurCHIP_SR_UI_T;
CHIP_LOCAL_CONTRAST_T glc_param={
	0,0,0,128,
	{0,0,1,1,2,2,2,2},
	{32,64,128,192,704,83,896,960},
	{
		0,64,128,192,256,320,384,448,512,576,640,704,768,832,896,960,1024,1088,1152,1216,1280,1344,1408,1472,1536,1600,1664,1728,1792,1856,1920,1984,
		0,64,128,192,256,320,384,448,512,576,640,704,768,832,896,960,1024,1088,1152,1216,1280,1344,1408,1472,1536,1600,1664,1728,1792,1856,1920,1984,
		0,128,256,384,512,640,768,896,1024,1152,1280,1408,1536,1664,1792,1920,2048,2176,2304,2432,2560,2688,2816,2944,3072,3200,3328,3456,3584,3712,3840,3968,
		0,128,256,384,512,640,768,896,1024,1152,1280,1408,1536,1664,1792,1920,2048,2176,2304,2432,2560,2688,2816,2944,3072,3200,3328,3456,3584,3712,3840,3968,
		0,2048,2112,2176,2240,2304,2368,2432,2496,2560,2624,2688,2752,2816,2880,2944,3008,3072,3136,3200,3264,3328,3392,3456,3520,3584,3648,3712,3776,3840,3904,4032,
		0,2048,2112,2176,2240,2304,2368,2432,2496,2560,2624,2688,2752,2816,2880,2944,3008,3072,3136,3200,3264,3328,3392,3456,3520,3584,3648,3712,3776,3840,3904,4032,
		0,2048,2112,2176,2240,2304,2368,2432,2496,2560,2624,2688,2752,2816,2880,2944,3008,3072,3136,3200,3264,3328,3392,3456,3520,3584,3648,3712,3776,3840,3904,4032,
		0,2048,2112,2176,2240,2304,2368,2432,2496,2560,2624,2688,2752,2816,2880,2944,3008,3072,3136,3200,3264,3328,3392,3456,3520,3584,3648,3712,3776,3840,3904,4032,
	},
};

unsigned short tShp_Val[7];
static unsigned char g_prevent_force_write_dcc = 0;

unsigned char g_bAPLColorGainClr = 1;
unsigned char g_bGamut3DLUT_LGDB_NeedUpdated = 0;
unsigned char g_3DLUT_LastInternalSelect = 0; // 0: RTK DB, 1: LG DB
unsigned char g_3DLUT_LastEnableSatus = 0;
unsigned char g_3DLUT_Resume = 0;
extern GAMUT_3D_LUT_17x17x17_T g_LGDB_3D_LUT_BUF[1];
GAMUT_3D_LUT_17x17x17_T g_buf3DLUT_LGDB;

extern struct semaphore Memc_Realcinema_Semaphore;/*For adaptive streaming info Semaphore*/
extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr;//extern char memc_realcinema_run_flag;

unsigned char g_bDIGameModeOnlyDebug = FALSE;

UINT8 g_pcid_en = 0;
UINT8 g_pcid2_en = 0;

unsigned char od_table_store_r[OD_table_length];
unsigned char od_table_store_g[OD_table_length];
unsigned char od_table_store_b[OD_table_length];
unsigned char od_table_store_w[OD_table_length];
unsigned int od_delta_table_resume[OD_table_length];
unsigned int OD_FPP_Table[OD_table_length];

extern unsigned char rtk_vsc_setFilmMode(bool value);
unsigned char rtk_hal_vsc_GetInputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * pinregion);
extern unsigned char rtk_hal_vsc_SetInputRegion(VIDEO_WID_T wid, VIDEO_RECT_T  inregion);
unsigned char rtk_hal_vsc_GetOutputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * poutregion);
unsigned char rtk_hal_vsc_SetOutputRegion(VIDEO_WID_T wid, VIDEO_RECT_T outregion);

extern void memc_realcinema_framerate(void);
extern unsigned char get_sub_OutputVencMode(void);

extern PQ_device_struct *g_Share_Memory_PQ_device_struct;

#ifdef CONFIG_HDR_SDR_SEAMLESS
extern HDR_SDR_SEAMLESS_PQ_STRUCT HDR_SDR_SEAMLESS_PQ;
#endif

int vpq_open(struct inode *inode, struct file *filp)
{
	return 0;
}

ssize_t  vpq_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
#if 1
	return count;
#else
	return 0;
#endif

}

ssize_t vpq_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
#if 1
	if(NULL == g_Share_Memory_PQ_device_struct)
		return count;
	if(strcmp(buffer, "enable_pqautocheck\n") == 0){
		g_Share_Memory_PQ_device_struct->pqautocheck_en=1;
		printk(KERN_EMERG "enable_pqautocheck\n");
	}

	if(strcmp(buffer, "disable_pqautocheck\n") == 0){
		g_Share_Memory_PQ_device_struct->pqautocheck_en=0;
		printk(KERN_EMERG "disable_pqautocheck\n");
	}

	if(strcmp(buffer, "pqautocheck_all\n") == 0){
		unsigned int PQ_check_error[200];
		vpq_PQ_check_timming("all", PQ_check_error);
		printk(KERN_EMERG "pqautocheck_all\n");
	}

	return count;
#else
	return 0;
#endif
}

int vpq_release(struct inode *inode, struct file *filep)
{
	return 0;
}

void vpq_set_color_temp_filter(void)
{
	COLORTEMP_ELEM_T ct;
	static COLORTEMP_ELEM_T ctStore = {0};
	static unsigned char ucColorFilterModeStore = 0;
	unsigned char waitSync = 0;
	memcpy(&ct, &curColorTemp, sizeof(COLORTEMP_ELEM_T));

	if (ucColorFilterModeStore != ucColorFilterMode ) {
		waitSync = 1;
		ucColorFilterModeStore = ucColorFilterMode;
	}

	if (memcmp(&ctStore, &curColorTemp, sizeof(COLORTEMP_ELEM_T)) != 0) {
		waitSync = 1;
		memcpy(&ctStore, &curColorTemp, sizeof(COLORTEMP_ELEM_T));
	}

	switch (ucColorFilterMode) {
	case 1: /*SET filter gain value to RED only*/
			ct.Green_Gain = ct.Blue_Gain = 0;
			break;
	case 2: /*SET filter gain value to GREEN only*/
			ct.Red_Gain = ct.Blue_Gain = 0;
			break;
	case 3: /*SET filter gain value to BLUE only*/
			ct.Red_Gain = ct.Green_Gain = 0;
			break;
	case 0: /*SET filter gain value to off mode*/
	default:
			break;
			;
	}

	/*
	fwif_color_setrgbcontrast_By_Table(ct.Red_Gain, ct.Green_Gain, ct.Blue_Gain, 0);
	fwif_color_setrgbbrightness_By_Table(ct.Red_Offset, ct.Green_Offset, ct.Blue_Offset);
	*/
	fwif_color_set_color_temp_tv006(TRUE, ct.Red_Gain<<2, ct.Green_Gain<<2, ct.Blue_Gain<<2, (ct.Red_Offset<<2)-2048, (ct.Green_Offset<<2)-2048, (ct.Blue_Offset<<2)-2048, waitSync);
}

void vpq_init_gamma(void)
{
	int i;

	for (i = 0; i < 1024; i++)
		gamma.Gamme_Red[i] = gamma.Gamme_Green[i] = gamma.Gamme_Blue[i] = i;
}

void vpq_gamma_multiply_remap(GAMMA_RGB_T *pGammaRGBIn)
{
	int i, j, hdiff, qdiff;
	if (NULL == pGammaRGBIn)
		return;

	// R
	for (i = 0, j = 0; i < 4096; i+=4, j++) {
		g_GammaRemap[i] = pGammaRGBIn->Gamme_Red[j] << 2;
	}
	g_GammaRemap[4096] = (pGammaRGBIn->Gamme_Red[1023] << 2) + (pGammaRGBIn->Gamme_Red[1023] >> 8);

	for (i = 0; i < 4096; i+=4) {
		hdiff = (g_GammaRemap[i+4]-g_GammaRemap[i])>>1;
		qdiff = hdiff>>1;
		g_GammaRemap[i+1] = g_GammaRemap[i]+qdiff;
		g_GammaRemap[i+2] = g_GammaRemap[i]+hdiff;
		g_GammaRemap[i+3] = g_GammaRemap[i+2]+qdiff;
	}

	for (i = 0; i < 1025; i++) {
		GOut_R[i] = g_GammaRemap[Power1div22Gamma[i]];
	}

	// G
	for (i = 0, j = 0; i < 4096; i+=4, j++) {
		g_GammaRemap[i] = pGammaRGBIn->Gamme_Green[j] << 2;
	}
	g_GammaRemap[4096] = (pGammaRGBIn->Gamme_Green[1023] << 2) + (pGammaRGBIn->Gamme_Green[1023] >> 8);

	for (i = 0; i < 4096; i+=4) {
		hdiff = (g_GammaRemap[i+4]-g_GammaRemap[i])>>1;
		qdiff = hdiff>>1;
		g_GammaRemap[i+1] = g_GammaRemap[i]+qdiff;
		g_GammaRemap[i+2] = g_GammaRemap[i]+hdiff;
		g_GammaRemap[i+3] = g_GammaRemap[i+2]+qdiff;
	}

	for (i = 0; i < 1025; i++) {
		GOut_G[i] = g_GammaRemap[Power1div22Gamma[i]];
	}


	// B
	for (i = 0, j = 0; i < 4096; i+=4, j++) {
		g_GammaRemap[i] = pGammaRGBIn->Gamme_Blue[j] << 2;
	}
	g_GammaRemap[4096] = (pGammaRGBIn->Gamme_Blue[1023] << 2) + (pGammaRGBIn->Gamme_Blue[1023] >> 8);

	for (i = 0; i < 4096; i+=4) {
		hdiff = (g_GammaRemap[i+4]-g_GammaRemap[i])>>1;
		qdiff = hdiff>>1;
		g_GammaRemap[i+1] = g_GammaRemap[i]+qdiff;
		g_GammaRemap[i+2] = g_GammaRemap[i]+hdiff;
		g_GammaRemap[i+3] = g_GammaRemap[i+2]+qdiff;
	}

	for (i = 0; i < 1025; i++) {
		GOut_B[i] = g_GammaRemap[Power1div22Gamma[i]];
	}

}

void vpq_mapping_gamma_by_gamut_mode(void)
{
	int i;
	unsigned char bGammaDo2p2 = FALSE;

	switch(g_InvGammaPowerMode) {
	case VPQ_GAMMA_MODE_INV_OFF_INNER_BYPASS:
	case VPQ_GAMMA_MODE_INV_ON_INNER_BYPASS:
	default:
		bGammaDo2p2 = FALSE;
		break;
	case VPQ_GAMMA_MODE_INV_OFF_INNER_ON:
	case VPQ_GAMMA_MODE_INV_ON_INNER_ON:
		bGammaDo2p2 = TRUE;
		break;
	}

	if (bGammaDo2p2) {
		vpq_gamma_multiply_remap(&gamma);
	} else {
		for (i = 0; i < 1024; i++) {
			GOut_R[i] = (gamma.Gamme_Red[i] << 2) + (gamma.Gamme_Red[i] >> 8);
			GOut_G[i] = (gamma.Gamme_Green[i] << 2) + (gamma.Gamme_Green[i] >> 8);
			GOut_B[i] = (gamma.Gamme_Blue[i] << 2) + (gamma.Gamme_Blue[i] >> 8);
		}

		GOut_R[1024] = GOut_R[1023];
		GOut_G[1024] = GOut_G[1023];
		GOut_B[1024] = GOut_B[1023];
	}

}

void vpq_set_gamma(unsigned char ucDoCtrlBack, unsigned char useRPC)
{
	down(&VPQ_Semaphore);
	if (!useRPC) {
		vpq_mapping_gamma_by_gamut_mode();
		fwif_color_gamma_control_front(SLR_MAIN_DISPLAY);
		fwif_color_gamma_encode(final_GAMMA_R, final_GAMMA_G, final_GAMMA_B, GOut_R, GOut_G, GOut_B);
		/*fwif_color_gamma_encode(final_GAMMA_R, final_GAMMA_G, final_GAMMA_B, gamma.Gamme_Red, gamma.Gamme_Green, gamma.Gamme_Blue);*/
		/*WaitFor_DEN_STOP();*/
		fwif_color_set_gamma_encode(final_GAMMA_R, final_GAMMA_G, final_GAMMA_B);
		if (ucDoCtrlBack)
			fwif_color_gamma_control_back(SLR_MAIN_DISPLAY, 1);

	} else {
		static UINT32 temp[1536];
		vpq_mapping_gamma_by_gamut_mode();
		//fwif_color_gamma_control_front(SLR_MAIN_DISPLAY);
		fwif_color_gamma_encode(final_GAMMA_R, final_GAMMA_G, final_GAMMA_B, GOut_R, GOut_G, GOut_B);

		memcpy(temp, final_GAMMA_R, sizeof(UINT32)*512);
		memcpy(temp+512, final_GAMMA_G, sizeof(UINT32)*512);
		memcpy(temp+1024, final_GAMMA_B, sizeof(UINT32)*512);

		fwif_color_ChangeUINT32Endian(temp, 1536, 1);		//gamma run to d domain isr need enfian

		if (drvif_color_Gamma_Read_Write_Check())
			WaitFor_DEN_START();

		memcpy((UINT32 *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_GAMMA), temp, sizeof(UINT32)*3*(512));
		if ((Scaler_SendRPC(SCALERIOC_SET_GAMMA, 0, 0)) < 0) {
			rtd_printk(KERN_ERR, TAG_NAME, " update GAMMA to driver fail !!!\n");
		}
	}
	up(&VPQ_Semaphore);

}

void vpq_set_inv_gamma(unsigned char ucDoCtrlBack)
{
	down(&VPQ_Semaphore);
	fwif_color_inv_gamma_control_front(SLR_MAIN_DISPLAY);
	fwif_color_gamma_encode(final_GAMMA_R, final_GAMMA_G, final_GAMMA_B, Power22InvGamma, Power22InvGamma, Power22InvGamma);
	fwif_color_set_inv_gamma_encode_tv006();
	if (ucDoCtrlBack)
		fwif_color_inv_gamma_control_back(SLR_MAIN_DISPLAY, 1);

	up(&VPQ_Semaphore);
}

unsigned int out_GAMMA_R[128], out_GAMMA_G[128], out_GAMMA_B[128];
void vpq_set_out_gamma(void)
{
	extern unsigned short LEDOutGamma[257];
	static unsigned char panelTypeDef = 0;
	unsigned char panel_type=((IoReg_Read32(MIS_GPIO_GP2DATI_reg)>>18)&0x1);//0xb801bd38[18]=1 OLED
	if (panel_type)
		panelTypeDef = 1;

	down(&VPQ_Semaphore);
	if (panel_type || panelTypeDef) {
		fwif_color_out_gamma_control_front();
		fwif_color_out_gamma_encode(out_GAMMA_R, out_GAMMA_G, out_GAMMA_B, LEDOutGamma, LEDOutGamma, LEDOutGamma);
		fwif_color_set_out_gamma_encode_tv006();
		fwif_color_out_gamma_control_back();
		fwif_color_out_gamma_control_enable(1);
	} else
		fwif_color_out_gamma_control_enable(0);

	up(&VPQ_Semaphore);
}

void vpq_update_icm(unsigned char waiting)
{
	down(&VPQ_Semaphore);
	fwif_color_set_ICM_table_driver_tv006(&icm_tab_elem_write, waiting);
	up(&VPQ_Semaphore);
}

void vpq_cm_global_init(void)
{
	int rgn;
	memcpy(&g_cm_rgn_exp, &g_cm_rgn_adv, sizeof(CHIP_CM_REGION_T));

	for (rgn = 0; rgn < CHIP_CM_COLOR_REGION_MAX; rgn++) {
		g_cm_ctrl_adv.stColor[rgn].masterGain = 0;
		g_cm_ctrl_adv.stColor[rgn].stColorGain.stColorGainHue = 128;
		g_cm_ctrl_adv.stColor[rgn].stColorGain.stColorGainSat = 128;
		g_cm_ctrl_adv.stColor[rgn].stColorGain.stColorGainInt = 128;
	}

	memcpy(&g_cm_ctrl_exp, &g_cm_ctrl_adv, sizeof(CHIP_COLOR_CONTROL_T));
}

void vpq_set_3d_lut_index(unsigned char idx, unsigned char bForceWrite)
{
	static unsigned char last3dlut_idx = 0xff;

	if (idx > IDX_3DLUT_MAX)
		return;

	if (bForceWrite || (last3dlut_idx > 0 && (last3dlut_idx-1) != fwif_color_3d_lut_access_index(ACCESS_MODE_GET, 0)))
		bForceWrite = 1;

	down(&VPQ_Semaphore);
	if (last3dlut_idx != idx || bForceWrite) {
		fwif_color_set_3dLUT(idx);
		last3dlut_idx = idx;
	}
	if (idx > 0)
		fwif_color_3d_lut_access_index(ACCESS_MODE_SET, idx-1);
	up(&VPQ_Semaphore);
}

unsigned char vpq_set_Gamut_3D_Lut_LGDB(GAMUT_3D_LUT_17x17x17_T *pLut, unsigned int iEnable, unsigned char bOnlySetEnable)
{
	int idx;
	static unsigned int pLUT3D[LUT3D_TBL_ITEM];
	extern unsigned char lastLUT_tbl_index;// RTK last index

	if (NULL == pLut)
		return FALSE;

	down(&VPQ_Semaphore);
	lastLUT_tbl_index = 0xff; //clear rtk DB last index
	fwif_color_3d_lut_access_index(ACCESS_MODE_SET, 0); //clear rtk DB index

	if (bOnlySetEnable && iEnable) {
		fwif_color_WaitFor_DEN_STOP_UZUDTG();
		drvif_color_D_3dLUT_Enable(1);
	} else {
		for (idx = 0; idx < 4913; idx++) {
			pLUT3D[idx<<1] = (pLut->pt[idx].r_data<<16)+pLut->pt[idx].g_data;
			pLUT3D[(idx<<1)+1] = pLut->pt[idx].b_data;
		}

		fwif_color_WaitFor_DEN_STOP_UZUDTG();

		if (iEnable)
			drvif_color_D_3dLUT(1, pLUT3D);
		else
			drvif_color_D_3dLUT(0, pLUT3D);
	}
	up(&VPQ_Semaphore);

	return TRUE;
}


void vpq_boot_init(void)
{
	DRV_Sharpness_Level Sharpness_Level;
	fwif_color_DI_Addr_Boundary_ini();
	vpq_cm_global_init();
	vpq_init_gamma();
	vpq_set_inv_gamma(0);
	vpq_set_out_gamma();
	vpq_set_gamma(0, 0);
	fwif_color_inv_gamma_control_back(SLR_MAIN_DISPLAY, 0);
	fwif_color_gamma_control_back(SLR_MAIN_DISPLAY, 0);
	drvif_color_set_Vivid_Color_Enable(TRUE);
	drvif_color_set_sub_Vivid_Color_Enable(TRUE);
	Scaler_VIP_Project_ID_init();
	fwif_color_set_ICM_table_driver_init_tv006();
	fwif_color_set_ICM_table_driver_init_elem_tv006(&icm_tab_elem_write);
	memcpy(&icm_tab_elem_of_vip_table, &icm_tab_elem_write, sizeof(COLORELEM_TAB_T));
	vpq_update_icm(FALSE);
	drvif_color_Icm_Enable(0);
	fwif_color_SetDNR_tv006(2);	/*rock_rau 20150922 vpq_project_id 0x00060000 NR set use fwif_color_SetDNR_tv006 function*/
	memset(&Sharpness_Level, 0, sizeof(DRV_Sharpness_Level));
	drvif_color_set_Sharpness_level(&Sharpness_Level);
	fwif_color_3d_lut_init_tv006();
	set_PS_in_ISR = 0;
#if 0
	drvif_DM2_OETF_Enable(1, 0);
	drvif_DM2_OETF_Set((unsigned short *)&OETF_LUT_HLG_DEFAULT, (unsigned short *)&OETF_LUT_HLG_DEFAULT, (unsigned short *)&OETF_LUT_HLG_DEFAULT);

	drvif_DM2_EOTF_Enable(1, 0);
	drvif_DM2_EOTF_Set((unsigned int*)&EOTF_LUT_HLG_DEFAULT, (unsigned int*)&EOTF_LUT_HLG_DEFAULT, (unsigned int*)&EOTF_LUT_HLG_DEFAULT);

	//extern struct semaphore VPQ_DM_3DLUT_Semaphore;
	static PQ_HDR_3dLUT_16_PARAM args;
	args.c3dLUT_16_enable = 1;
	args.a3dLUT_16_pArray = (UINT16*)HDR10_3DLUT_24x24x24;

	//rtd_printk(KERN_INFO, TAG_NAME, "\n rord vip init, 3DLUT args[3]=%d,args[6]=%d,",args.a3dLUT_16_pArray[3],args.a3dLUT_16_pArray[6] );
	drvif_Set_DM_HDR_CLK(); // enable DM & Composer clock
	//down(&VPQ_DM_3DLUT_Semaphore);
	fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(&args);
	//up(&VPQ_DM_3DLUT_Semaphore);
#endif

	/* always on for snr hw issue, elieli*/
	if (drvif_color_Get_DRV_SNR_Clock(0) == 1) {
		drvif_color_Set_DRV_SNR_Clock(0);
		drvif_color_DRV_SNR_Mosquito_NR_En(0xF);
		drvif_color_iEdgeSmooth_en(0xF);
		drvif_color_Set_DRV_SNR_Clock(1);
	} else {
		drvif_color_DRV_SNR_Mosquito_NR_En(0xF);
		drvif_color_iEdgeSmooth_en(0xF);
	}

	/* always on for UZU_Bypass_No_PwrSave hw issue, elieli*/
	drvif_color_Access_UZU_Bypass_No_PwrSave(1, 1);

	/* set panel dither*/
	if (Get_DISPLAY_PANEL_MPLUS_RGBW() == TRUE || Get_DISPLAY_PANEL_BOW_RGBW() == TRUE)
		drvif_color_Setditherbit(VIP_PANEL_BIT8);
	else
		drvif_color_Setditherbit(VIP_PANEL_BIT10);
	drvif_color_setdithering();

	if (Scaler_Init_OD()) {
		fwif_color_set_liner_od_table();
		Scaler_Set_OD_Bit_By_XML();
	}

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K)
		drvif_color_set_outgamma_10bits();
}

void *vpq_demo_overscan_func(void *param)
{
	VIDEO_WID_T wid;
	VIDEO_RECT_T inregion;
	VIDEO_RECT_T outregion;
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = NULL;

	wid = VIDEO_WID_0;
	if(Scaler_AdaptiveStream_NewInputRegionFlagGet(wid)){
		StructSrcRect newInput = cal_new_input_for_Adaptive(wid);
		inregion.x = newInput.srcx;
		inregion.y = newInput.srcy;
		inregion.h = newInput.src_height;
		inregion.w = newInput.src_wid;
	}else{
		rtk_hal_vsc_GetInputRegion(wid, &inregion);
	}

	if ( !rtk_hal_vsc_GetOutputRegion(wid, &outregion))
		return NULL;

	if (param != NULL) {
		unsigned short *ocInfo = (unsigned short *)param;
		switch(ocInfo[0]) {
		case 1:/*read*/
			ocInfo[1] = inregion.x;
			ocInfo[2] = inregion.y;
			ocInfo[3] = inregion.w;
			ocInfo[4] = inregion.h;

			ocInfo[5] = outregion.x;
			ocInfo[6] = outregion.y;
			ocInfo[7] = outregion.w;
			ocInfo[8] = outregion.h;
			return NULL;
			break;
		case 2:/*write*/
			if (ocInfo[3] && ocInfo[4]) {
				inregion.x = ocInfo[1];
				inregion.y = ocInfo[2];
				inregion.w = ocInfo[3];
				inregion.h = ocInfo[4];
			}

			if (ocInfo[7] && ocInfo[8]) {
				outregion.x = ocInfo[5];
				outregion.y = ocInfo[6];
				outregion.w = ocInfo[7];
				outregion.h = ocInfo[8];
			}
			break;
		default:
			return NULL;
		}
	}else {/*custom overscan by source*/
		VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

		if((VIP_RPC_system_info_structure_table == NULL) ) {
			rtd_printk( KERN_ERR,TAG_NAME, "Warning! Share Memory PQ data NULL,RPC_VIP_system_info = %x\n",VIP_RPC_system_info_structure_table);
			return NULL;
		}

		switch (VIP_RPC_system_info_structure_table->VIP_source) {

			case VIP_QUALITY_HDMI_1080I:
			case VIP_QUALITY_HDMI_1080P:

				inregion.x = 39;
				inregion.y = 23;
				inregion.w = 1847;
				inregion.h = 1037;

				break;
			case VIP_QUALITY_CVBS_PAL:
			case VIP_QUALITY_CVBS_S_PAL:
			case VIP_QUALITY_TV_PAL:
				inregion.x = 18;
				inregion.y = 18;
				inregion.w = 668;
				inregion.h = 539;

				break;


		default:
			return NULL;
		}
	}

	rtk_hal_vsc_SetInputRegion(wid, inregion);
	rtk_hal_vsc_SetOutputRegion(wid, outregion);

	return NULL;
}

void *vpq_demo_pq_func(void *param)
{
	unsigned char enable;

	if (param == NULL)
		return NULL;

	enable = *((unsigned char*)param);

	if (enable==1 && vpq_project_id != 0x00010000) {
		vpq_project_id = 0x00010000;
		fwif_color_set_pq_demo_flag_rpc(1);
		Scaler_VIP_Project_ID_init();
		fwif_color_handler();
		fwif_color_video_quality_handler();
		fwif_color_vpq_pic_init();
		Scaler_SetDNR(4);
		Scaler_SetMPEGNR(4, CALLED_NOT_BY_OSD);
		fwif_color_set_PQA_motion_threshold_TV006();
		fwif_color_SetAutoMAFlag(1);
		vpq_demo_overscan_func(NULL);
		// henry Mac5p
		if (bODInited) {
			drvif_color_od_for_demo();
			drvif_color_od_gain(45);
			fwif_color_set_od(1);
		}
		// end henry
		Demo_Flag = 1;
	} else if (enable==0 && vpq_project_id != 0x00060000) {
		vpq_project_id = 0x00060000;
		g_InvGammaPowerMode = 0;
		g_IsInvGammaPowerNewMode = 0;
		fwif_color_set_pq_demo_flag_rpc(0);
		Scaler_VIP_Project_ID_init();
		vpq_boot_init();
		fwif_color_inv_gamma_control_back(SLR_MAIN_DISPLAY, 0);
		drvif_color_inv_gamma_enable(SLR_MAIN_DISPLAY, 0, 0);
		drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, 0, 0);
		fwif_color_gamma_control_back(SLR_MAIN_DISPLAY, 1);
		fwif_color_SetDNR_tv006(0);		/*rock_rau 20150922 vpq_project_id 0x00060000 NR set use fwif_color_SetDNR_tv006 function*/
		fwif_color_set_DCC_Init(SLR_MAIN_DISPLAY);
		fwif_color_handler();
		fwif_color_video_quality_handler();
		fwif_color_vpq_pic_init();
		fwif_color_SetAutoMAFlag(1);
		Demo_Flag = 0;
	} else if (enable==2 && vpq_project_id != 0x00010000) {			//rock_rau 20150813 PQ by pass
		DRV_VIP_YUV2RGB_CSMatrix drv_vipCSMatrix_t;
		vpq_project_id = 0x00010000;
		fwif_color_set_pq_demo_flag_rpc(1);
		Scaler_VIP_Project_ID_init();
		fwif_color_handler();
		fwif_color_video_quality_handler();
		fwif_color_vpq_pic_init();
		fwif_color_SetAutoMAFlag(1);
/*==============================================*/
		Scaler_SetContrast(50);
		Scaler_SetBrightness(50);
		Scaler_SetSaturation(50);
		Scaler_SetHue(50);
		fwif_color_RHAL_SetDNR(0);

		Scaler_SetMPEGNR(0, CALLED_NOT_BY_OSD);
		Scaler_SetDNR(0);
		Scaler_SetSharpness(50);
		Scaler_SetDCC_Mode(0);

		Scaler_set_ICM_table(255, 0);
		Scaler_SetSharpnessTable(255);
		Scaler_SetMBPeaking(255);
		memset(&drv_vipCSMatrix_t, 0, sizeof(DRV_VIP_YUV2RGB_CSMatrix));
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_UVOffset_ctrl, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);


//		Color_Fun_Bypass color_fun_bypass[3];
//		color_fun_bypass[0].idIP = BYPASS_RGB_CON;
//		color_fun_bypass[0].bypass_switch = 0;
//		color_fun_bypass[1].idIP = BYPASS_RGB_BRI;
//		color_fun_bypass[1].bypass_switch = 0;
//		color_fun_bypass[2].idIP = BYPASS_GAMMA;
//		color_fun_bypass[2].bypass_switch = 0;
//		color_fun_bypass[3].idIP = BYPASS_D_DITHER;
//		color_fun_bypass[3].bypass_switch = 0;
//		color_fun_bypass[4].idIP = BYPASS_SRGB;
//		color_fun_bypass[4].bypass_switch = 0;
//		drvif_color_bypass(&color_fun_bypass, 3);

		vpq_demo_overscan_func(NULL);
		Demo_Flag = 1;
/*==============================================*/


	}

	return NULL;
}

#ifdef CONFIG_PM
OD_SUSPEND_RESUME_T od_suspend_resume;
void od_do_suspend(void)
{
	//extern unsigned char bODInited;
	extern unsigned char od_table_tv006_store[OD_table_length];

	od_od_ctrl_RBUS od_ctrl_reg;

	//if (!bODInited)
		//return;
	//open OD double buffer for STR
	od_od_ctrl1_RBUS od_od_ctrl1_reg;
	od_od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
	od_od_ctrl1_reg.od_en_dbf_en = 1;
	IoReg_Write32(OD_OD_CTRL1_reg, od_od_ctrl1_reg.regValue);
	
	od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
	od_suspend_resume.od_enable = od_ctrl_reg.od_en;
	
	drvif_color_od_table_seperate_read(&(od_table_store_r[0]), 0);//R
	drvif_color_od_table_seperate_read(&(od_table_store_g[0]), 1);//G
	drvif_color_od_table_seperate_read(&(od_table_store_b[0]), 2);//B
}

void pcid_do_suspend(void)
{
	int i=0;
	for(i=0; i<81; i++)
	{
		PCID_ValueTBL[i] = 0;
		POD_ValueTBL_1[i] = 0;
		POD_ValueTBL_2[i] = 0;
	}
}

VPQ_SUSPEND_RESUME_T vpq_suspend_resume;
void vpq_do_suspend(void)
{
	*((unsigned char *)Scaler_GetShareMemVirAddr(SCALERIOC_SETAUTOMAFLAG)) = 0;

	vpq_suspend_resume.CRT_PLL_SSC0_S_R = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
  	vpq_suspend_resume.CRT_PLL_SSC3_S_R = IoReg_Read32(PLL27X_REG_PLL_SSC3_reg);
	vpq_suspend_resume.CRT_PLL_SSC4_S_R = IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
	vpq_suspend_resume.CRT_SYS_DCLKSS_S_R = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	vpq_suspend_resume.CRT_SYS_PLL_DISP1_S_R = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	vpq_suspend_resume.CRT_SYS_PLL_DISP2_S_R = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_reg);
	vpq_suspend_resume.CRT_SYS_PLL_DISP3_S_R = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
	vpq_suspend_resume.CRT_SYS_DISPCLKSEL_S_R = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);

	od_do_suspend();
	pcid_do_suspend();
}

void vpq_do_resume_instanboot(void)
{
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, vpq_suspend_resume.CRT_PLL_SSC0_S_R&~_BIT0);
	IoReg_Write32(PLL27X_REG_PLL_SSC3_reg, vpq_suspend_resume.CRT_PLL_SSC3_S_R);
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, vpq_suspend_resume.CRT_PLL_SSC4_S_R);
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, vpq_suspend_resume.CRT_SYS_DCLKSS_S_R);
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP1_reg, vpq_suspend_resume.CRT_SYS_PLL_DISP1_S_R);
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP2_reg, vpq_suspend_resume.CRT_SYS_PLL_DISP2_S_R);
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, vpq_suspend_resume.CRT_SYS_PLL_DISP3_S_R);
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, vpq_suspend_resume.CRT_SYS_DISPCLKSEL_S_R);
 	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, (vpq_suspend_resume.CRT_PLL_SSC0_S_R|_BIT0));
	mdelay(1);
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, (vpq_suspend_resume.CRT_PLL_SSC0_S_R&~_BIT0));

	vpq_do_resume();
}

void od_do_resume(void)
{
	extern unsigned char bODInited;
	
	extern unsigned char od_table_tv006_store[OD_table_length];
	//extern unsigned char bODTableLoaded;
	//extern char od_table_mode_store;// 0:target mode 1:delta mode -1:inverse mode

	bODInited = 0;
	if (Scaler_Init_OD()) {
#if 0
		if (bODTableLoaded && od_table_mode_store == 1)
			fwif_color_od_table_restore();
		else
			fwif_color_set_liner_od_table();
#endif
		fwif_color_od_table_17x17_transform(0, od_table_store_r, od_delta_table_resume);
		drvif_color_od_table_seperate_write(&(od_delta_table_resume[0]), 0, 0);// 0:delta mode 1:target mode(output mode) R
		fwif_color_od_table_17x17_transform(0, od_table_store_g, od_delta_table_resume);
		drvif_color_od_table_seperate_write(&(od_delta_table_resume[0]), 0, 1);// 0:delta mode 1:target mode(output mode) G
		fwif_color_od_table_17x17_transform(0, od_table_store_b, od_delta_table_resume);
		drvif_color_od_table_seperate_write(&(od_delta_table_resume[0]), 0, 2);// 0:delta mode 1:target mode(output mode) B

		if (vpqex_project_id != 0x00060000) {
			if (od_suspend_resume.od_enable)
				fwif_color_set_od(TRUE);
			else
				fwif_color_set_od(FALSE);
			//Scaler_Set_OD_Bit_By_XML();
		} else
			fwif_color_set_od(1);
	}
}

void vpq_do_resume(void)
{
	extern unsigned char lastLUT_tbl_index;
	extern unsigned char g_bNotFirstRun_LD_Data_Compensation_NewMode_2DTable;
	DRV_Sharpness_Level Sharpness_Level;
  	//_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info *VIP_RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);

	VIP_RPC_system_info_structure_table->HDR_info.Ctrl_Item[TV006_HDR_En] = 0;
	g_cm_need_refresh = 1;
	g_srgbForceUpdate = 1;
	g_srgbForceUpdate2 = 1;
	g_InvGammaPowerMode = 0;
	g_IsInvGammaPowerNewMode = 0;
	g_HDR3DLUTForceWrite = 1;
	lastLUT_tbl_index = 0xff;
	g_3DLUT_Resume = 1;
	g_prevent_force_write_dcc = 0;
	g_bNotFirstRun_LD_Data_Compensation_NewMode_2DTable = 0;
	g_pcid_en = 0;
	g_pcid2_en = 0;
	set_PS_in_ISR = 0;
	str_resume_do_picturemode=1;
	fwif_color_DI_Addr_Boundary_ini();
	Scaler_color_set_m_nowSource(255);
	vpq_set_out_gamma();
	vpq_init_gamma();
	vpq_set_inv_gamma(0);
	fwif_color_inv_gamma_control_back(SLR_MAIN_DISPLAY, 0);
	vpq_set_gamma(1, 0);
	fwif_color_gamma_control_back(SLR_SUB_DISPLAY, 1);
	drvif_color_inv_gamma_enable(SLR_MAIN_DISPLAY, 0, 0);
	drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, 0, 0);
	drvif_color_set_Vivid_Color_Enable(TRUE);
	drvif_color_set_sub_Vivid_Color_Enable(TRUE);
	fwif_color_set_ICM_table_driver_init_tv006();
	vpq_update_icm(FALSE);
	drvif_color_Icm_Enable(0);
	memset(&Sharpness_Level, 0, sizeof(DRV_Sharpness_Level));
	drvif_color_set_Sharpness_level(&Sharpness_Level);
	fwif_color_set_DCC_Init(SLR_MAIN_DISPLAY);
	vpq_set_3d_lut_index(0, 0);
	od_do_resume();
	drvif_Set_DM_HDR_CLK();	// enable DM & Composer clock
	hdr_resume();

	/* always on for snr hw issue, elieli*/
	if (drvif_color_Get_DRV_SNR_Clock(0) == 1) {
		drvif_color_Set_DRV_SNR_Clock(0);
		drvif_color_DRV_SNR_Mosquito_NR_En(0xFF);
		drvif_color_iEdgeSmooth_en(0xFF);
		drvif_color_Set_DRV_SNR_Clock(1);
	} else {
		drvif_color_DRV_SNR_Mosquito_NR_En(0xFF);
		drvif_color_iEdgeSmooth_en(0xFF);
	}

	/* always on for UZU_Bypass_No_PwrSave hw issue, elieli*/
	drvif_color_Access_UZU_Bypass_No_PwrSave(1, 1);

	/* set panel dither*/
	if (Get_DISPLAY_PANEL_MPLUS_RGBW() == TRUE || Get_DISPLAY_PANEL_BOW_RGBW() == TRUE)
		drvif_color_Setditherbit(VIP_PANEL_BIT8);
	else
		drvif_color_Setditherbit(VIP_PANEL_BIT10);
	drvif_color_setdithering();

#ifdef ENABLE_VIP_TABLE_CHECKSUM
/* === checksum ========== */
	extern VIP_table_crc_value vip_table_crc;
	VIP_table_crc_value vip_table_crc_now;
	fwif_color_check_VIPTable_crc(&vip_table_crc_now, fwif_color_GetShare_Memory_VIP_TABLE_Struct());
	rtd_printk(KERN_DEBUG, TAG_NAME, "[%s %d] VIP_table_checksum: %x, resume_checksum %x\n", __FILE__, __LINE__,
	vip_table_crc.checkSum, vip_table_crc_now.checkSum);

	if(vip_table_crc.checkSum != vip_table_crc_now.checkSum)
		rtd_printk(KERN_DEBUG, TAG_NAME, "[%s %d] Error! Checksum changed.\n", __FILE__, __LINE__);
/* ===================== */
#endif
	//return 0;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K)
		drvif_color_set_outgamma_10bits();


}

static int vpq_suspend(struct device *p_dev)
{
	return 0;
}

static int vpq_resume(struct device *p_dev)
{
	return 0;
}

#ifdef CONFIG_HIBERNATION
typedef struct {
	unsigned int id;
	unsigned int size;
	void *vaddr;
} STD_SHAREMEM_SAVE;

STD_SHAREMEM_SAVE vpq_std_save[] = {
	{SCALERIOC_VIP_system_info_structure, sizeof(_system_setting_info), NULL},
	{SCALERIOC_VIP_RPC_system_info_structure, sizeof(_RPC_system_setting_info), NULL},
	{SCALERIOC_VIP_SMARTPIC_CLUS, sizeof(_clues), NULL},
	{SCALERIOC_VIP_RPC_SMARTPIC_CLUS, sizeof(_RPC_clues), NULL},
	{SCALERIOC_VIP_TABLE_STRUCT, sizeof(SLR_VIP_TABLE), NULL},
	{SCALERIOC_VIP_RPC_TABLE_STRUCT, sizeof(RPC_SLR_VIP_TABLE), NULL},
	{SCALERIOC_VIP_TABLE_CUSTOM_STRUCT, sizeof(SLR_VIP_TABLE_CUSTOM_TV001), NULL},
	{SCALERIOC_VIP_TABLE_CRC_STRUCT, sizeof(VIP_table_crc_value), NULL},
};

static int vpq_suspend_std(struct device *p_dev)
{
	int i;
	unsigned int smAddr = NULL;
	for (i = 0; i < sizeof(vpq_std_save)/sizeof(STD_SHAREMEM_SAVE); i++) {
		vpq_std_save[i].vaddr = vmalloc(vpq_std_save[i].size);
		if (vpq_std_save[i].vaddr) {
			smAddr = Scaler_GetShareMemVirAddr(vpq_std_save[i].id);
			if (smAddr) {
				memcpy(vpq_std_save[i].vaddr, (void*)smAddr, vpq_std_save[i].size);
			}
		}
	}

	return 0;
}

static int vpq_resume_std(struct device *p_dev)
{
	int i;
	unsigned int smAddr = NULL;
	for (i = 0; i < sizeof(vpq_std_save)/sizeof(STD_SHAREMEM_SAVE); i++) {
		if (vpq_std_save[i].vaddr) {
			smAddr = Scaler_GetShareMemVirAddr(vpq_std_save[i].id);
			if (smAddr) {
				memcpy((void*)smAddr, vpq_std_save[i].vaddr, vpq_std_save[i].size);
			}
			vfree(vpq_std_save[i].vaddr);
			vpq_std_save[i].vaddr = NULL;
		}
	}
	return 0;
}
#endif

#endif

static bool film_fw_tsk_running_flag = FALSE;
static struct task_struct *p_film_fw_tsk = NULL;
static int vpq_film_fw_tsk(void *p)
{
	extern FILM_FW_ShareMem *g_Share_Memory_FILM_FW;


	struct timespec timeout_s, timeout_l;
	current->flags &= ~PF_NOFREEZE;
	timeout_s = ns_to_timespec(500 * 1000);
	timeout_l = ns_to_timespec(14 * 1000 * 1000);

	while(1) {

		//vpq_od_init(); //dude to memc init refine, so no more use this

		if (g_Share_Memory_FILM_FW->smooth_toggle_film != 0xff) {	////smooth_toggle_film change timming
			switch (g_Share_Memory_FILM_FW->smooth_toggle_film) {
			case _MODE_480I: /*60Hz SD*/
					fwif_module_set_film_table_t(0);
					break;
			case _MODE_1080I30: /*60Hz HD*/
					fwif_module_set_film_table_t(1);
					break;
			case _MODE_576I: /*50Hz SD*/
					fwif_module_set_film_table_t(4);
					break;
			case _MODE_1080I25: /*50Hz HD*/
					fwif_module_set_film_table_t(3);
					break;
			default:
					fwif_module_set_film_table_t(0);
			}

			g_Share_Memory_FILM_FW->smooth_toggle_film = 0xff;		////smooth_toggle_film change timming
		}
		if (g_Share_Memory_FILM_FW->flag_Trigger) {
			extern unsigned char g_st_DI_STATUS_VPAN;

			g_Share_Memory_FILM_FW->flag_Trigger = 0;
			//rtd_printk(KERN_DEBUG, TAG_NAME, "p_sw_film_tsk running\n");
			g_st_DI_STATUS_VPAN = g_Share_Memory_FILM_FW->st_DI_STATUS_VPAN;
			scalerVIP_film_FWmode();
			hrtimer_nanosleep(&timeout_l, NULL, HRTIMER_MODE_REL, CLOCK_MONOTONIC);
		}
		hrtimer_nanosleep(&timeout_s, NULL, HRTIMER_MODE_REL, CLOCK_MONOTONIC);
		if (freezing(current))
			try_to_freeze();
		if (kthread_should_stop())
			break;
	}

	return 0;
}

static void delete_film_fw_tsk(void)
{
	int ret;
	if (film_fw_tsk_running_flag) {
 		ret = kthread_stop(p_film_fw_tsk);
 		if (!ret) {
 			p_film_fw_tsk = NULL;
 			film_fw_tsk_running_flag = FALSE;
			rtd_printk(KERN_INFO, TAG_NAME, "film_fw_tsk thread stopped\n");
 		}
	}
}

static void create_film_fw_tsk(void)
{
	int err;
	if (film_fw_tsk_running_flag == FALSE && fwif_color_set_FILM_FW_ShareMemory()) {
		p_film_fw_tsk = kthread_create(vpq_film_fw_tsk, NULL, "vpq_film_fw_tsk");
		if (p_film_fw_tsk) {
			wake_up_process(p_film_fw_tsk);
			film_fw_tsk_running_flag = TRUE;
		} else {
		    	err = PTR_ERR(p_film_fw_tsk);
		    	rtd_printk(KERN_ERR, TAG_NAME, "Unable to start film_fw_tsk (err_id = %d)./n", err);
		}
	}
}

bool vpq_check_array(unsigned int *arg, unsigned int *pre_arg, unsigned int len)
{
	unsigned int i;

	for(i=0;i<len;i++) {
		if(arg[i] != pre_arg[i])
			return 0;
	}
	return 1;
}

unsigned char ioctl_cmd_stop[256] = {0};
unsigned char vpq_ioctl_get_stop_run(unsigned int cmd)
{
	return (ioctl_cmd_stop[_IOC_NR(cmd)&0xff]|ioctl_cmd_stop[0]);
}

unsigned char vpq_ioctl_get_stop_run_by_idx(unsigned char cmd_idx)
{
	return ioctl_cmd_stop[cmd_idx];
}

void vpq_ioctl_set_stop_run_by_idx(unsigned char cmd_idx, unsigned char stop)
{
	ioctl_cmd_stop[cmd_idx] = stop;
}

unsigned char vpq_get_handler_bypass(void)
{
#ifdef CONFIG_SCALER_BRING_UP
	return 1;
#endif

	return ioctl_cmd_stop[VPQ_IOC_PQ_CMD_OPEN];
}

COLORTEMP_ELEM_T ct;
DRV_film_mode film_mode;
DRV_film_table_t film_table;
DRV_Sharpness_Level Sharpness_Level;
CHIP_NOISE_REDUCTION_T NR_Level;
CHIP_MPEG_NOISE_REDUCTION_T MPEGNR_Level;
CHIP_DCC_T tFreshContrast_coef;
FreshContrastLUT_T tFreshContrastLUT;
VPQ_SetPicCtrl_T pic_ctrl = {0, {100, 50, 50, 0}, {128, 128, 128, 128}};
COLOR_GAMUT_T gamutData;
VPQ_SAT_LUT_T satLutData;
HDR_Set3DLUT_16_T phdr3dlut16;
UINT32 Eotf_table32[1025] = {0};
UINT16 Oetf_table16[1025] = {0};
UINT32 PQModeInfo_flag[5] = {0};
CHIP_CM_REGION_EXT_T cmRegionExt;//for CM ioctl tmp
UINT8 game_process = 0;
extern struct semaphore* get_gamemode_check_semaphore(void);

int PictureMode_flg = 0;  // for MEMC wrt by JerryWang 20161125

long vpq_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{
	int ret = 0;
	unsigned char live_zoom_tune = 0;
	static UINT16 zoom_c;
	unsigned char isBlack_LvDiff_Flag = 0;
	extern bool PQ_demo_mode;
	if (vpq_ioctl_get_stop_run(cmd))
		return 0;

#ifdef RTK_PQ_demo_mode		//for demo
	if(PQ_demo_mode == 1 && cmd == VPQ_IOC_SET_PQModeInfo){
		unsigned char buf[1] = {0};
		(fwif_color_get_demo_callback(DEMO_CALLBACKID_ON_OFF_SWITCH))((void *)buf);
		PQ_demo_mode = 0;
	}
#endif

	if (vpq_project_id != 0x00060000) {
		if (VPQ_IOC_INIT == cmd) {
			vpq_project_id = 0x00060000;
			vpq_boot_init();
		} else {
			if (Demo_Flag && VPQ_IOC_SET_PIC_CTRL == cmd)
				vpq_demo_overscan_func(NULL);

			return -1;
		}
	}

	if (VPQ_IOC_INIT == cmd) {
		fwif_color_inv_gamma_control_back(SLR_MAIN_DISPLAY, 0);
		fwif_color_gamma_control_back(SLR_MAIN_DISPLAY, 1);
		fwif_color_gamma_control_back(SLR_SUB_DISPLAY, 1);
#ifdef CONFIG_DUAL_CHANNEL
		fwif_color_inv_gamma_control_back(SLR_SUB_DISPLAY, 0);
		fwif_color_gamma_control_back(SLR_SUB_DISPLAY, 1);
#endif
		fwif_color_set_DCC_Init(SLR_MAIN_DISPLAY);
		/*fwif_color_set_DCC_Init_tv006();*/
		fwif_color_set_dcc_force_write_flag_RPC(1, 0);

		// enable DM & Composer clock
		drvif_Set_DM_HDR_CLK();
		drvif_TV006_HDR10_init();
#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
		create_film_fw_tsk();
#else
		fwif_color_set_FILM_FW_ShareMemory();
#endif
		fwif_color_set_Picture_Control_tv006(pic_ctrl.wId, &pic_ctrl);
		PQ_Dev_Status = PQ_DEV_INIT_DONE;
		return 0;
	} else if (VPQ_IOC_UNINIT == cmd) {
		PQ_Dev_Status = PQ_DEV_UNINIT;
		return 0;
	} else if (VPQ_IOC_OPEN == cmd || VPQ_IOC_CLOSE == cmd) {
		return 0;
	} else if (VPQ_IOC_SET_PROJECT_ID == cmd) {
		//vpq_project_id = arg;
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "vpq_project_id = %x\n", vpq_project_id);*/
		return 0;
	}

	if (PQ_Dev_Status != PQ_DEV_INIT_DONE)
		return -1;

	if(Get_Live_zoom_mode() != LIVE_ZOOM_OFF) {
		if ((zoom_c & 0x000f) != 0)
			live_zoom_tune = 1;
	}
	zoom_c++;

	switch (cmd) {
	case VPQ_IOC_SET_COLOR_TEMP:
		{

			if (copy_from_user(&ct, (int __user *)arg, sizeof(COLORTEMP_ELEM_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_COLOR_TEMP fail\n");
				ret = -1;
			} else {
				memcpy(&curColorTemp, &ct, sizeof(COLORTEMP_ELEM_T));
				vpq_set_color_temp_filter();
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_COLOR_TEMP success\n");*/
				ret = 0;
			}
		}
		break;

	case VPQ_IOC_SET_COLOR_FILTER:
		{
			unsigned int args;
			if (copy_from_user(&args, (int __user *)arg, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_PIC_CTRL fail\n");
				ret = -1;
			} else {
				ucColorFilterMode = (unsigned char)args;
				vpq_set_color_temp_filter();
				ret = 0;
			}
		}
		break;

	case VPQ_IOC_GET_MOTION_LEVEL:
		{
			_clues *smartPic_clue;
			UINT32 PQA_Motion_Level = 0;

			/* Get Info from Share Mem*/
			smartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
			if (0 == smartPic_clue)
				return -1;
			fwif_color_ChangeUINT32Endian_Copy(&smartPic_clue->motion_ratio, 1, &PQA_Motion_Level, 0);
			if (copy_to_user((void __user *)arg, (void *)&PQA_Motion_Level, sizeof(UINT32))) {
				ret = -1;
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_MOTION_LEVEL fail\n");
			} else {
				ret = 0;
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_GET_MOTION_LEVEL success\n");*/
			}

		}
		break;
	case VPQ_IOC_GET_NOISE_LEVEL:
		{
			_clues *smartPic_clue;
			UINT32 PQA_Noise_Level = 0;

			/* Get Info from Share Mem*/
			smartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
			if (0 == smartPic_clue)
				return -1;
			fwif_color_ChangeUINT32Endian_Copy(&smartPic_clue->noise_ratio, 1, &PQA_Noise_Level, 0);
			if (copy_to_user((void __user *)arg, (void *)&PQA_Noise_Level, sizeof(UINT16))) {
				ret = -1;
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_NOISE_LEVEL fail\n");
			} else {
				ret = 0;
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_GET_NOISE_LEVEL success\n");*/
			}

		}
		break;
	case VPQ_IOC_GET_Input_V_Freq:
		{
			unsigned int Input_V_Freq;

			Input_V_Freq = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ);
			if (copy_to_user((void __user *)arg, (void *)&Input_V_Freq, sizeof(unsigned int))) {
				ret = -1;
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_Input_V_Freq fail\n");
			} else {
				ret = 0;
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_GET_Input_V_Freq success\n");*/
			}
		}
		break;
	case VPQ_IOC_SET_GAMMA_LUT:
		{
			if (copy_from_user(&gamma, (int __user *)arg, sizeof(gamma))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_GAMMA_LUT fail\n");
				ret = -1;
			} else {
				vpq_set_gamma(0, 1);
				fwif_color_gamma_control_back(SLR_MAIN_DISPLAY, 0);
				ret = 0;
			}
		}
		break;
	case VPQ_IOC_SET_SPLIT_DEMO:
		{
			bool bOnOff;

			if (copy_from_user(&bOnOff, (int __user *)arg, sizeof(bool))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_SPLIT_DEMO fail\n");
				ret = -1;
			} else {
				if (bOnOff == TRUE)
					Scaler_SetMagicPicture(SLR_MAGIC_STILLDEMO);
				else
					Scaler_SetMagicPicture(SLR_MAGIC_OFF);
			}
		}
		break;
	case VPQ_IOC_SET_IRE_INNER_PATTERN:
		{
			unsigned int args;
			if (copy_from_user(&args, (int __user *)arg, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_IRE_INNER_PATTERN fail\n");
				ret = -1;
			} else {
				fwif_color_set_WB_Pattern_IRE(args>>16, args&0xffff);
				ret = 0;
			}
		}
		break;
	case VPQ_IOC_SET_FILM_MODE:
		{
			unsigned char bCinemaMode;
			if (copy_from_user(&film_mode, (int __user *)arg, sizeof(film_mode))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_FILM_MODE fail\n");
				ret = -1;
			} else {
				down(get_DI_semaphore());
				drvif_module_film_mode((DRV_film_mode *) &film_mode);
				up(get_DI_semaphore());
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_FILM_MODE success\n");*/

				down(&Memc_Realcinema_Semaphore);
				if (film_mode.film_status ==0)
					bCinemaMode = 0;
				else
					bCinemaMode = 1;
				if ((Get_Live_zoom_mode() != LIVE_ZOOM_OFF) || (Get_LivezoomOffMainForceBG() == TRUE)){
					/*qiangzhou:livezoom no need setting dtg three times*/
				}else{
					//memc_realcinema_framerate();
					DbgSclrFlgTkr.memc_realcinema_run_flag = TRUE;//Run memc mode
				}
				fwif_color_set_cinema_mode_en(bCinemaMode);
				up(&Memc_Realcinema_Semaphore);
				ret = Scaler_MEMC_set_cinema_mode_en(bCinemaMode);
			}
		}
		break;
	case VPQ_IOC_SET_FILM_TABLE:
		{
			return 0;/*fix table not match from hal, use internal finetune*/
			if (copy_from_user(&film_table, (int __user *)arg, sizeof(DRV_film_table_t))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_FILM_TABLE fail\n");
				ret = -1;
			} else {
				down(get_DI_semaphore());
				drvif_module_film_setting((DRV_film_table_t *) &film_table);
				up(get_DI_semaphore());
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_FILM_TABLE success\n");*/
				ret = 0;
			}

		}
		break;

	case VPQ_IOC_SET_FILM_FPS:
		{
			unsigned int args;
			if (copy_from_user(&args, (int __user *)arg, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_FILM_FPS fail\n");
				ret = -1;
			} else {
				unsigned char bIs48HzMode = false;
				bIs48HzMode = (args&0xff) ? 1 : 0;
				rtk_vsc_setFilmMode(bIs48HzMode);
				ret = 0;
			}
		}
		break;

	case VPQ_IOC_SET_SHARPNESS_LEVEL:
		{
			if (copy_from_user(&Sharpness_Level, (int __user *)arg, sizeof(DRV_Sharpness_Level))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_SHARPNESS_LEVEL fail\n");
				ret = -1;
			} else {
				drvif_color_set_Sharpness_level((DRV_Sharpness_Level *) &Sharpness_Level);
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_SHARPNESS_LEVEL success\n");*/
				ret = 0;
			}
		}
		break;

	case VPQ_IOC_SET_SHARPNESS_TABLE:
		{
			static CHIP_SHARPNESS_UI_T tCHIP_SHARPNESS_UI_T;
			/*CHIP_EDGE_ENHANCE_UI_T tCHIP_EDGE_ENHANCE_UI_T;*/
			/*UINT16 sEdgeEnhanceValue = tShp_Val[4];*/ /* 0: off 1:on*/

			if (live_zoom_tune)
				return 0;

			if (copy_from_user(&tCHIP_SHARPNESS_UI_T, (void __user *)arg, sizeof(CHIP_SHARPNESS_UI_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_SHARPNESS_TABLE fail\n");
				ret = -1;
			} else {
				memcpy(&tCurCHIP_SHARPNESS_UI_T, &tCHIP_SHARPNESS_UI_T, sizeof(CHIP_SHARPNESS_UI_T));
				/*memcpy(&tCHIP_EDGE_ENHANCE_UI_T, &tCurCHIP_EDGE_ENHANCE_UI_T, sizeof(CHIP_EDGE_ENHANCE_UI_T));*/
				/*if (uc3DCorrectionEn == false) {*/
					fwif_color_set_sharpness_table_TV006(&tCurCHIP_SHARPNESS_UI_T, &tCurCHIP_EDGE_ENHANCE_UI_T, &tCurCHIP_SR_UI_T);
				/*
					drvif_color_set_Vertical_Peaking_Enable(true);
				} else {
					fwif_color_set_SharpnessFilterCoef_for_3D((CHIP_SHARPNESS_UI_T *)&tCHIP_SHARPNESS_UI_T, (CHIP_SHARPNESS_UI_T *) &t3DCHIP_SHARPNESS_UI_T);
					fwif_color_set_sharpness_table_TV006(tCHIP_SHARPNESS_UI_T, tCHIP_EDGE_ENHANCE_UI_T, sEdgeEnhanceValue);
					drvif_color_set_Vertical_Peaking_Enable(false);
				}
				*/
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_SHARPNESS_TABLE success\n");*/
				ret = 0;
			}
		}
	break;

	case VPQ_IOC_SET_VPQ_Shp_Val:
	{
		if (copy_from_user(&tShp_Val, (int __user *)arg, sizeof(UINT16)*7)) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_VPQ_Shp_Val fail\n");
			ret = -1;
		} else {

			/*fwif_color_set_sharpness_level_TV006(&tShp_Val[0]);*/
			rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_VPQ_Shp_Val success\n");
			ret = 0;
		}
	}
	break;

	case VPQ_IOC_SET_EDGE_ENHANCE:
	{
		CHIP_EDGE_ENHANCE_UI_T tCHIP_EDGE_ENHANCE_UI_T;
		/*CHIP_SHARPNESS_UI_T tCHIP_SHARPNESS_UI_T;*/

		if (live_zoom_tune)
			return 0;

		if (copy_from_user((void *)&tCHIP_EDGE_ENHANCE_UI_T,(void __user *)arg , sizeof(CHIP_EDGE_ENHANCE_UI_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_EDGE_ENHANCE fail\n");
			ret = -1;
		} else {
			memcpy(&tCurCHIP_EDGE_ENHANCE_UI_T, &tCHIP_EDGE_ENHANCE_UI_T, sizeof(CHIP_EDGE_ENHANCE_UI_T));
			/*memcpy(&tCHIP_SHARPNESS_UI_T, &tCurCHIP_SHARPNESS_UI_T, sizeof(CHIP_SHARPNESS_UI_T));*/
			/*if (uc3DCorrectionEn == false) {*/
				fwif_color_set_sharpness_table_TV006(&tCurCHIP_SHARPNESS_UI_T, &tCurCHIP_EDGE_ENHANCE_UI_T, &tCurCHIP_SR_UI_T);
			/*
				drvif_color_set_Vertical_Peaking_Enable(true);
			} else {
				fwif_color_set_SharpnessFilterCoef_for_3D((CHIP_SHARPNESS_UI_T *)&tCHIP_SHARPNESS_UI_T, (CHIP_SHARPNESS_UI_T *) &t3DCHIP_SHARPNESS_UI_T);
				fwif_color_set_sharpness_table_TV006(tCHIP_SHARPNESS_UI_T, tCHIP_EDGE_ENHANCE_UI_T, uEeVal);
				drvif_color_set_Vertical_Peaking_Enable(false);
			}
			*/
			/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_EDGE_ENHANCE success\n");*/
			ret = 0;
		}
	}
	break;

	case VPQ_IOC_SET_SR_TABLE:
	{
		RTK_SR_UI_T tRTK_SR_UI_T;

		if (live_zoom_tune)
			return 0;

		if (copy_from_user((void *)&tRTK_SR_UI_T,(void __user *)arg , sizeof(tRTK_SR_UI_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_EDGE_ENHANCE fail\n");
			ret = -1;
		} else {
			memcpy(&tCurCHIP_SR_UI_T, &tRTK_SR_UI_T.sr_ui, sizeof(CHIP_SR_UI_T));
			fwif_color_set_sharpness_table_TV006(&tCurCHIP_SHARPNESS_UI_T, &tCurCHIP_EDGE_ENHANCE_UI_T, &tCurCHIP_SR_UI_T);
			ret = 0;
		}
	}
	break;

	case VPQ_IOC_SET_NR_PQA_TABLE:
		{
			unsigned char PQA_Table_Idx = 0;
			if (copy_from_user(&PQA_Table_Idx, (int __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_NR_PQA_TABLE fail\n");
				ret = -1;
			} else {
				fwif_color_set_PQA_table(PQA_Table_Idx);
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_NR_PQA_TABLE success\n");*/
				ret = 0;
			}
		}
	break;

	case VPQ_IOC_SET_NR_PQA_INPUT_TABLE:
		{
			unsigned char PQA_Input_Table_Idx = 0;
			if (copy_from_user(&PQA_Input_Table_Idx, (int __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_NR_PQA_INPUT_TABLE fail\n");
				ret = -1;
			} else {
				fwif_color_set_PQA_Input_table(PQA_Input_Table_Idx);
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_NR_PQA_INPUT_TABLE success\n");*/
				ret = 0;
			}
		}
	break;
	case VPQ_IOC_SET_NR_LEVEL:
		{
			if (copy_from_user(&NR_Level, (int __user *)arg, sizeof(CHIP_NOISE_REDUCTION_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_NR_LEVEL fail\n");
				ret = -1;
			} else {

				fwif_color_Set_NR_Table_tv006(&NR_Level);
				fwif_color_SetDNR_tv006(NR_Level.NR_LEVEL);
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_NR_LEVEL success\n");*/
				ret = 0;
			}
		}

	break;
	case VPQ_IOC_SET_NR_INPUT:
		{
			unsigned char args = 0;
			if (copy_from_user(&args, (int __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_NR_INPUT fail\n");
				ret = -1;
			} else {
				fwif_color_Set_NR_Input_tv006(args);
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_NR_PQA_TABLE success\n");*/
				ret = 0;
			}

		}

	break;

	case VPQ_IOC_SET_MPEGNR_LEVEL:
		{

			if (copy_from_user(&MPEGNR_Level, (void __user *)arg, sizeof(CHIP_MPEG_NOISE_REDUCTION_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_MPEGNR_LEVEL fail\n");
				ret = -1;
			} else {
				fwif_color_Set_MPEGNR_Table_tv006(&MPEGNR_Level);
				fwif_color_Set_MPEGNR_tv006(MPEGNR_Level.MPEG_LEVEL);

				/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_MPEGNR_LEVEL success\n");*/
				ret = 0;
			}
		}

	break;
	case VPQ_IOC_GET_HistoData_Countbins:
	{
		UINT32 HistoData_bin[TV006_VPQ_chrm_bin];

		if (fwif_color_get_HistoData_Countbins(TV006_VPQ_chrm_bin, &(HistoData_bin[0])) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Countbins fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&HistoData_bin[0], sizeof(HistoData_bin))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Countbins fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;
	case VPQ_IOC_GET_HistoData_chrm_bin:
	{
		UINT32 chrm_bin[COLOR_AutoSat_HISTOGRAM_LEVEL];

		if (fwif_color_get_HistoData_chrmbins(COLOR_AutoSat_HISTOGRAM_LEVEL, &(chrm_bin[0])) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_chrm_bin fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&chrm_bin[0], sizeof(chrm_bin))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_chrm_bin fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;
	case VPQ_IOC_GET_HistoData_hue_bin:
	{
		UINT32 hue_bin[COLOR_HUE_HISTOGRAM_LEVEL];

		if (fwif_color_get_HistoData_huebins(COLOR_HUE_HISTOGRAM_LEVEL, &(hue_bin[0])) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_Countbins fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&hue_bin[0], sizeof(hue_bin))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_hue_bin fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;
	case VPQ_IOC_GET_HistoData_APL:
	{
		unsigned int DC_APL = 0;

		if (fwif_color_get_HistoData_APL(&DC_APL) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_APL fail\n");
			ret = -1;
		} else {
			if (drvif_color_get_WB_pattern_on())
				DC_APL = 940;
			if (copy_to_user((void __user *)arg, (void *)&DC_APL, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_APL fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_Min:
	{
		signed int DC_min = 0;

		if (fwif_color_get_HistoData_Min(&DC_min) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_Min fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&DC_min, sizeof(signed int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Min fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_Max:
	{
		signed int DC_max = 0;

		if (fwif_color_get_HistoData_Max(&DC_max) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_Max fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&DC_max, sizeof(signed int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Max fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_PeakLow:
	{
		signed int DC_peak_low = 0;

		if (fwif_color_get_HistoData_PeakLow(&DC_peak_low) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_PeakLow fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&DC_peak_low, sizeof(signed int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_PeakLow fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_PeakHigh:
	{
		signed int DC_peak_high;

		if (fwif_color_get_HistoData_PeakHigh(&DC_peak_high) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_PeakHigh fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&DC_peak_high, sizeof(signed int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_PeakHigh fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_skin_count:
	{
		unsigned int skin_count;

		if (fwif_color_get_HistoData_skinCount(&skin_count) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_skinCount fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&skin_count, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_skin_count fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_sat_status:
	{
		unsigned int sat_status;

		if (fwif_color_get_HistoData_SatStatus(&sat_status) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_SatStatus fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&sat_status, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_SatStatus fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_diff_sum:
	{
		unsigned int diff_sum;

		/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_diff_sum\n");*/
		if (fwif_color_get_HistoData_diffSum(&diff_sum) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_diffSum fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&diff_sum, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_diff_sum fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;
	case VPQ_IOC_GET_HistoData_motion:
	{
		unsigned int motion;

		/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_motion\n");*/
		if (fwif_color_get_HistoData_motion(&motion) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_motion fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&motion, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_motion fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_GET_HistoData_texture:
	{
		unsigned int texture;

		/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_texture\n");*/
		if (fwif_color_get_HistoData_texture(&texture) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_texture fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&texture, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_texture fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;
	case VPQ_IOC_SET_FreshContrast:
	{

		if (fwif_color_vpq_stop_ioctl(STOP_VPQ_IOC_SET_FreshContrast, ACCESS_MODE_GET, 0))
			return 0;

		if (copy_from_user(&tFreshContrast_coef, (void __user *)arg, sizeof(CHIP_DCC_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_FreshContrast fail\n");
			ret = -1;
		} else {

			if (fwif_color_set_dcc_FreshContrast_tv006(&tFreshContrast_coef) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_set_dcc_FreshContrast_tv006 fail\n");
				ret = -1;
			} else {
				/*rtd_printk(KERN_DEBUG, TAG_NAME, "5.kernel VPQ_IOC_SET_FreshContrast success\n");*/
				ret = 0;
			}
		}
	}
	break;

	case VPQ_IOC_SET_FreshContrastLUT:
	{
		if (fwif_color_vpq_stop_ioctl(STOP_VPQ_IOC_SET_FreshContrastLUT, ACCESS_MODE_GET, 0))
			return 0;

		if (copy_from_user(&tFreshContrastLUT, (int __user *)arg, sizeof(FreshContrastLUT_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_FreshContrastLUT fail\n");
			ret = -1;
		} else {
			if (drvif_color_get_WB_pattern_on()) {
				if (!fwif_color_set_bypass_dcc_Curve_Write_tv006()) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_set_dcc_Curve_Write_tv006 fail\n");
						ret = -1;
				} else if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE) {
					if (!g_prevent_force_write_dcc)
						fwif_color_set_dcc_force_write_flag_RPC(0, 1);
					g_prevent_force_write_dcc = 1;
					return 0;
				}
			} else if (fwif_color_set_dcc_Curve_Write_tv006(&tFreshContrastLUT.FreshContrastLUT[0]) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_set_dcc_Curve_Write_tv006 fail\n");
				ret = -1;
			} else
				ret = 0;

			g_prevent_force_write_dcc = 0;
		}
	}
	break;

	case VPQ_IOC_GET_FreshContrastBypassLUT:
	{
		FreshContrastLUT_T tFreshContrastLUT;

		if (fwif_color_get_FreshContrastBypassLUT(DCC_Curve_Node_MAX, &(tFreshContrastLUT.FreshContrastLUT[0])) == FALSE) {
			rtd_printk(KERN_ERR, TAG_NAME, "fwif_color_get_FreshContrastBypassLUT fail\n");
			ret = -1;
		} else {
			if (copy_to_user((void __user *)arg, (void *)&(tFreshContrastLUT.FreshContrastLUT[0]), sizeof(FreshContrastLUT_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_FreshContrastBypassLUT copy_to_user fail\n");
				ret = -1;
			} else
				ret = 0;
		}
	}
	break;

	case VPQ_IOC_SET_ColorGain:
	{
		RTK_COLOR_GAIN_T colorGain;

		if (fwif_color_vpq_stop_ioctl(STOP_VPQ_IOC_SET_SAT_LUT, ACCESS_MODE_GET, 0))
			return 0;

		if (copy_from_user(&colorGain, (void __user *)arg, sizeof(RTK_COLOR_GAIN_T))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_ColorGain fail\n");
					ret = -1;
		} else {
			fwif_color_access_apl_color_gain_tv006(colorGain.wId, &colorGain.uCgVal, ACCESS_MODE_WRITE);
			if (g_bAPLColorGainClr) {
				fwif_color_update_YUV2RGB_CSC_tv006(colorGain.wId);
				g_bAPLColorGainClr = 0;
			} else
				g_bAPLColorGainClr = 1;
		}
	}
	break;

	case VPQ_IOC_SET_CLEAR_WHITE_GAIN:
	{
		HAL_VPQ_CLEAR_WHITE clear_white;
		DRV_VIP_YUV2RGB_UV_Offset uvOffset;

		if (copy_from_user(&clear_white, (void __user *)arg, sizeof(HAL_VPQ_CLEAR_WHITE))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_CLEAR_WHITE_GAIN fail\n");
			ret = -1;
		} else {
			memcpy(&uvOffset.Uoffset[0], &clear_white.Uoffset[0], sizeof(unsigned char)*VIP_YUV2RGB_Y_Seg_Max);
			memcpy(&uvOffset.Voffset[0], &clear_white.Voffset[0], sizeof(unsigned char)*VIP_YUV2RGB_Y_Seg_Max);
			memcpy(&uvOffset.Ustep[0], &clear_white.Ustep[0], sizeof(unsigned char)*VIP_YUV2RGB_Y_Seg_Max);
			memcpy(&uvOffset.Vstep[0], &clear_white.Vstep[0], sizeof(unsigned char)*VIP_YUV2RGB_Y_Seg_Max);
			memcpy(&uvOffset.UV_index[0], &clear_white.UV_index[0], sizeof(unsigned char)*(VIP_YUV2RGB_Y_Seg_Max-1));
			if (!fwif_color_set_YUV2RGB_UV_Offset_tv006(clear_white.wId, clear_white.enable, clear_white.mode, &uvOffset))
				return -1;
			/*rtd_printk(KERN_DEBUG, TAG_NAME, "kernel VPQ_IOC_SET_CLEAR_WHITE_GAIN,%d,%d, ret =%d\n", level, display, ret);*/
		}
	}
	break;

	case VPQ_IOC_SET_BLUE_STRETCH:
	{
		RTK_BLUE_STRETCH_T blue_stretch;

		if (copy_from_user(&blue_stretch, (void __user *)arg, sizeof(RTK_BLUE_STRETCH_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_BLUE_STRETCH fail\n");
			ret = -1;
		} else {
			drvif_color_set_Blue_Stretch(&blue_stretch.gamma_bs);
		}
	}
	break;
	case VPQ_IOC_SET_LOCALCONTRAST_PARAM:
		{

			if (copy_from_user(&glc_param, (void __user *)arg, sizeof(CHIP_LOCAL_CONTRAST_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_LOCALCONTRAST_PARAM fail\n");
				ret = -1;
			} else {
				fwif_color_set_LocalContrast_table_TV006(&glc_param);

				ret = 0;
			}
		}
	break;

	case VPQ_IOC_SET_INIT_COLOR_ADV:
	{
		if (COLOR_MODE_ADV != g_Color_Mode)
			g_cm_need_refresh = 1;

		if (copy_from_user(&cmRegionExt, (void __user *)arg, sizeof(CHIP_CM_REGION_EXT_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_INIT_COLOR_ADV fail\n");
			ret = -1;
		} else {
			int i;

			if (cmRegionExt.ctrl[0] != 4) //verion4, add keepY
				return -1;

			// check param
			for (i = 0; i < CHIP_CM_COLOR_REGION_MAX; i++) {
				if (cmRegionExt.cm_rgn.stColorRegionType.stColorRegion[i].regionNum >= CHIP_CM_COLOR_REGION_MAX) {
					rtd_printk(KERN_WARNING, TAG_NAME, "[VPQ][kernel] %d-regionNum(%d) > CHIP_CM_COLOR_REGION_MAX, return!!\n",
						i, cmRegionExt.cm_rgn.stColorRegionType.stColorRegion[i].regionNum);
					return -1;
				}
			}

			memcpy(&g_cm_rgn_adv, &cmRegionExt.cm_rgn, sizeof(CHIP_CM_REGION_T));
			g_cm_keep_Y = g_cm_rgn_adv.stColorRegionType.keepY;
			fwif_color_set_ICM_table_driver_init_tv006();
			g_flag_cm_adv_init_ok = 1;
		}
	}
	break;

	case VPQ_IOC_SET_INIT_COLOR_EXP:
	{
		if (COLOR_MODE_EXP != g_Color_Mode)
			g_cm_need_refresh = 1;

		if (copy_from_user(&cmRegionExt, (void __user *)arg, sizeof(CHIP_CM_REGION_EXT_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_INIT_COLOR_EXP fail\n");
			ret = -1;
		} else {
			int i;

			if (cmRegionExt.ctrl[0] != 4) //verion4, add keepY
				return -1;

			// check param
			for (i = 0; i < CHIP_CM_COLOR_REGION_MAX; i++) {
				if (cmRegionExt.cm_rgn.stColorRegionType.stColorRegion[i].regionNum >= CHIP_CM_COLOR_REGION_MAX) {
					rtd_printk(KERN_WARNING, TAG_NAME, "[VPQ][kernel] %d-regionNum(%d) > CHIP_CM_COLOR_REGION_MAX, return!!\n",
						i, cmRegionExt.cm_rgn.stColorRegionType.stColorRegion[i].regionNum);
					return -1;
				}
			}

			memcpy(&g_cm_rgn_exp, &cmRegionExt.cm_rgn, sizeof(CHIP_CM_REGION_T));
			g_cm_keep_Y = g_cm_rgn_exp.stColorRegionType.keepY;
			fwif_color_set_ICM_table_driver_init_tv006();
			g_flag_cm_exp_init_ok = 1;
		}
	}
	break;

	case VPQ_IOC_SET_FRESH_COLOR:
	{
		CHIP_COLOR_CONTROL_FRESH_T cmControl;
		int ret_compare;

		if (live_zoom_tune)
			return 0;

		if (copy_from_user(&cmControl, (void __user *)arg, sizeof(CHIP_COLOR_CONTROL_FRESH_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_FRESH_COLOR fail\n");
			return -1;
		}

		if (cmRegionExt.ctrl[0] != 4) //verion4, add keepY
			return -1;

		if (COLOR_MODE_ADV == g_Color_Mode) {
			if (g_flag_cm_adv_init_ok) {
				ret_compare = memcmp(&g_cm_ctrl_adv, &cmControl.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				if (ret_compare == 0 && !g_cm_need_refresh) {
					return 0;
				}
				memcpy(&g_cm_ctrl_adv, &cmControl.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				fwif_color_calc_ICM_gain_table_driver_tv006(&g_cm_rgn_adv.stColorRegionType, &g_cm_ctrl_adv, &icm_tab_elem_of_vip_table, &icm_tab_elem_write);
				vpq_update_icm(TRUE);
				g_cm_need_refresh = 0;
			}
		} else {
			if (g_flag_cm_exp_init_ok) {
				ret_compare = memcmp(&g_cm_ctrl_exp, &cmControl.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				if (ret_compare == 0 && !g_cm_need_refresh) {
					return 0;
				}
				memcpy(&g_cm_ctrl_exp, &cmControl.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				fwif_color_calc_ICM_gain_table_driver_tv006(&g_cm_rgn_exp.stColorRegionType, &g_cm_ctrl_exp, &icm_tab_elem_of_vip_table, &icm_tab_elem_write);
				vpq_update_icm(TRUE);
				g_cm_need_refresh = 0;
			}
		}
	}
	break;

	case VPQ_IOC_SET_PREFERRED_COLOR:
	{
		CHIP_COLOR_CONTROL_ADV_EXT_T cmControlExt;

		if (live_zoom_tune)
			return 0;

		if (copy_from_user(&cmControlExt, (void __user *)arg, sizeof(CHIP_COLOR_CONTROL_ADV_EXT_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_PREFERRED_COLOR fail\n");
			ret = -1;
		} else {
			if (cmRegionExt.ctrl[0] != 4) //verion4, add keepY
				return -1;
			if (g_flag_cm_adv_init_ok) {
				int ret_compare;
				ret_compare = memcmp(&g_cm_ctrl_adv, &cmControlExt.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				if (ret_compare == 0 && !g_cm_need_refresh && g_Color_Mode == COLOR_MODE_ADV) {
					return 0;
				}
				memcpy(&g_cm_ctrl_adv, &cmControlExt.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				fwif_color_calc_ICM_gain_table_driver_tv006(&g_cm_rgn_adv.stColorRegionType, &g_cm_ctrl_adv, &icm_tab_elem_of_vip_table, &icm_tab_elem_write);
				vpq_update_icm(TRUE);
				g_Color_Mode = COLOR_MODE_ADV;
				g_cm_need_refresh = 0;
			} else {
				rtd_printk(KERN_WARNING, TAG_NAME, "[VPQ][kernel] need call HAL_VPQ_InitColorForAdvanced first!\n");
				ret = -1;
			}
		}
	}
	break;

	case VPQ_IOC_SET_COLOR_MANAGEMENT:
	{
		CHIP_COLOR_CONTROL_EXP_EXT_T cmControlExt;

		if (live_zoom_tune)
			return 0;

		if (copy_from_user(&cmControlExt, (void __user *)arg, sizeof(CHIP_COLOR_CONTROL_EXP_EXT_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_COLOR_MANAGEMENT fail\n");
			ret = -1;
		} else {
			if (cmRegionExt.ctrl[0] != 4) //verion4, add keepY
				return -1;
			if (g_flag_cm_exp_init_ok) {
				int ret_compare;
				ret_compare = memcmp(&g_cm_ctrl_exp, &cmControlExt.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				if (ret_compare == 0 && !g_cm_need_refresh && g_Color_Mode == COLOR_MODE_EXP) {
					return 0;
				}
				memcpy(&g_cm_ctrl_exp, &cmControlExt.cm_ctrl, sizeof(CHIP_COLOR_CONTROL_T));
				fwif_color_calc_ICM_gain_table_driver_tv006(&g_cm_rgn_exp.stColorRegionType, &g_cm_ctrl_exp, &icm_tab_elem_of_vip_table, &icm_tab_elem_write);
				vpq_update_icm(TRUE);
				g_Color_Mode = COLOR_MODE_EXP;
				g_cm_need_refresh = 0;
			} else {
				rtd_printk(KERN_WARNING, TAG_NAME, "[VPQ][kernel] need call HAL_VPQ_InitColorForExpert first!\n");
			}
		}
	}
	break;

	case VPQ_IOC_SET_ICM_ELEM:
	{
		if (copy_from_user(&icm_tab_elem_write, (int __user *)arg, sizeof(COLORELEM_TAB_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_ICM_ELEM fail\n");
			ret = -1;
		} else {
			vpq_update_icm(TRUE);
		}
	}
	break;

	case VPQ_IOC_SET_3D_COLOR_CORRECTION:
		{
			unsigned char c3DMode;
			unsigned int args;
			/*
			CHIP_SHARPNESS_UI_T tCHIP_SHARPNESS_UI_T;
			CHIP_EDGE_ENHANCE_UI_T tCHIP_EDGE_ENHANCE_UI_T;
			*/

			//static BOOLEAN lowdelaymode;
			if (copy_from_user(&args, (int __user *)arg, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_PIC_CTRL fail\n");
				ret = -1;
			} else {
				uc3DCorrectionEn = args&0xff;
				c3DMode = (args>>8)&0xff;

				if (HAL_VPQ_3D_MODE_3D_FS == c3DMode)
					bForceHist3DCtrl = true;
				else
					bForceHist3DCtrl = false;

				fwif_color_set_hist_3d_en(bForceHist3DCtrl);
				ret = 0;
			}

			/*
			memcpy(&tCHIP_SHARPNESS_UI_T, &tCurCHIP_SHARPNESS_UI_T, sizeof(CHIP_SHARPNESS_UI_T));
			memcpy(&tCHIP_EDGE_ENHANCE_UI_T, &tCurCHIP_EDGE_ENHANCE_UI_T, sizeof(CHIP_EDGE_ENHANCE_UI_T));
			if (uc3DCorrectionEn == false) {
				fwif_color_set_sharpness_table_TV006(tCHIP_SHARPNESS_UI_T, tCHIP_EDGE_ENHANCE_UI_T, uEeVal);
				drvif_color_set_Vertical_Peaking_Enable(true);
			} else {
				fwif_color_set_SharpnessFilterCoef_for_3D((CHIP_SHARPNESS_UI_T *)&tCHIP_SHARPNESS_UI_T, (CHIP_SHARPNESS_UI_T *) &t3DCHIP_SHARPNESS_UI_T);
				fwif_color_set_sharpness_table_TV006(tCHIP_SHARPNESS_UI_T, tCHIP_EDGE_ENHANCE_UI_T, uEeVal);
				drvif_color_set_Vertical_Peaking_Enable(false);
			}
			*/
			/*ToDo :: add sharpness v peaking and 2d coeff table*/
			ret = 0;
		}
		break;
	case VPQ_IOC_SET_PIC_CTRL:
	{
		/*unsigned char display = 0;*/
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "~~kernel VPQ_IOC_SET_CLEAR_WHITE_GAIN~~\n");*/

		PictureMode_flg = 1;  // for MEMC wrt by JerryWang 20161125
		if (copy_from_user(&pic_ctrl, (int __user *)arg, sizeof(VPQ_SetPicCtrl_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_PIC_CTRL fail\n");
			ret = -1;
		} else {
			ret = fwif_color_set_Picture_Control_tv006(pic_ctrl.wId, &pic_ctrl);
		}
		break;
	}
	case VPQ_IOC_SET_BLACK_LEVEL:
	{

		rtd_printk(KERN_INFO, TAG_NAME, "SET_BLACK_LEVEL\n");
		HAL_VPQ_SET_BLACK_LEVEL blackLv;
		unsigned char mCon, mBri, mHue, mSat;
		unsigned char  input_info;
		unsigned char  level;
		extern unsigned char g_LGE_HDR_CSC_CTRL;

		if (copy_from_user(&blackLv, (int __user *)arg, sizeof(HAL_VPQ_SET_BLACK_LEVEL))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_BLACK_LEVEL fail\n");
			ret = -1;
		} else {

			input_info = blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_Input_Info];

			g_LGE_HDR_CSC_CTRL = 0;
			if ((blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_HDR_CSC1] == HAL_VPQ_HDR_CSC1_BT709 ||
				blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_HDR_CSC1] == HAL_VPQ_HDR_BT2020) /*&&
				Scaler_InputSrcGetMainChType() == _SRC_VO*/)	/* HDR on/off is controlled by hal, remove src check.*/
			{
				g_LGE_HDR_CSC_CTRL = blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_HDR_CSC1];
				rtd_printk(KERN_INFO, TAG_NAME, "HDR10, HDR10 ON\n");

				//static UINT32 HDR10_en_count = 0;
				//HDR10_en_count++;
				//rtd_printk(KERN_DEBUG, TAG_NAME, "HDR10_en_count = %d\n", HDR10_en_count);
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME, "force disable HDR flow!!\n");
				rtd_printk(KERN_INFO, TAG_NAME, "HDR10, HDR10 OFF\n");
				blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_HDR_CSC1] = HAL_VPQ_HDR_OFF;
				g_LGE_HDR_CSC_CTRL = 0;
			}

			switch (blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_Level])
			{
			case UI_LEVEL_LOW:
				level = RGB2YUV_BLACK_LEVEL_LOW;
				break;
			case UI_LEVEL_HIGH:
				level = RGB2YUV_BLACK_LEVEL_HIGH;
				break;
			case UI_LEVEL_AUTO:
				level = RGB2YUV_BLACK_LEVEL_AUTO;
				break;
			default:
				level = RGB2YUV_BLACK_LEVEL_AUTO;
			}

			//20161111 roger, when sub record, don't change VD con/bri, WOSQRTK-9730
			if ((input_info == HAL_VPQ_INPUT_ATV || input_info == HAL_VPQ_INPUT_AV) && (get_sub_OutputVencMode() == 0)) {
				if (fwif_color_get_VDBlackLevel_MappingValue(input_info, level-1, &mCon, &mBri, &mHue, &mSat) == 0)
				{
					fwif_color_set_VDBlackLevel(mCon, mBri, mHue, mSat);

				}
			}

			/*20151128 roger, WOSQRTK-3568, LG want input_info == HAL_VPQ_INPUT_MEDIA_MOVIE, and level == RGB2YUV_BLACK_LEVEL_AUTO then level = RGB2YUV_BLACK_LEVEL_LOW directly*/
			if (input_info == HAL_VPQ_INPUT_MEDIA_MOVIE)
			{
				if (level == RGB2YUV_BLACK_LEVEL_AUTO)
					level = RGB2YUV_BLACK_LEVEL_LOW;
			}

			/* compare with previous, change black lv from UI while comparation is differnet*/
			if (level == fwif_color_get_rgb2yuv_black_level_tv006())
				isBlack_LvDiff_Flag = 0;
			else
				isBlack_LvDiff_Flag = 1;

			fwif_color_set_rgb2yuv_black_level_tv006(level);

#ifndef CONFIG_HDR_SDR_SEAMLESS	/* seamless need to check force bg and mode active*/
			fwif_color_SetDataFormatHandler_tv006();
			//HDR flow for LGE, 20160923 roger mark, K3L change HDR10 flow
			//Scaler_LGE_HDR10_Enable(blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_HDR_CSC1]);
			Scaler_SetHDR_BlackLevel(level);
#else
			if ((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE))
			{
				if (isBlack_LvDiff_Flag == 1) {
					fwif_color_SetDataFormatHandler_tv006();
					//HDR flow for LGE, 20160923 roger mark, K3L change HDR10 flow
					//Scaler_LGE_HDR10_Enable(blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_HDR_CSC1]);
					Scaler_SetHDR_BlackLevel(level);
				} else {
					/* seamless. do seamless process in isr (void Scaler_hdr_setting_SEAMLESS()), avoid transient noise*/
					;
				}
			} else {
				fwif_color_SetDataFormatHandler_tv006();
				//HDR flow for LGE, 20160923 roger mark, K3L change HDR10 flow
				//Scaler_LGE_HDR10_Enable(blackLv.uBlVal[SET_BLACK_LEVEL_ITEM_HDR_CSC1]);
				Scaler_SetHDR_BlackLevel(level);
			}
			HDR_SDR_SEAMLESS_PQ.HDR_SDR_SEAMLESS_PQ_SET[HDR_SDR_SEAMLESS_PQ_HAL_PQModeInfo]=1;
#endif
			ret = 0;
		}
		break;
	}

	case VPQ_IOC_SET_HDR_GAMUTMATRIX:
	{
		rtd_printk(KERN_INFO, TAG_NAME, "HDR10, SET_HDR_GAMUTMATRIX\n");
		if (PQModeInfo_flag[0] != HAL_VPQ_HDR_MODE_HDR10) break;
		HDR_SetGamut33Matrix_T gamut33;
		if (copy_from_user(&gamut33, (int __user *)arg, sizeof(HDR_SetGamut33Matrix_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_HDR_GAMUTMATRIX fail\n");
			ret = -1;
		} else {
			drvif_HDR_RGB2OPT(1, gamut33.Gamut33Matrix);
		}
		break;
	}

	case VPQ_IOC_SET_HDR_3DLUT_16: //new
	{
		//rtd_printk(KERN_INFO, TAG_NAME, "HDR10, get 3DLUT, 17x17x17 16bit\n");
		UINT8 data_protect_cfu = 100;
		//20151112 roger, fail ==> try again, I can't get the batter way to fix this copy fail issue
		while(copy_from_user(&phdr3dlut16, (void __user *)arg, sizeof(short) * VIP_DM_HDR_3D_LUT_UI_TBL_SIZE) && (data_protect_cfu > 0))
		{
			msleep(10);
			data_protect_cfu--;
		}

		if (data_protect_cfu == 0)
		{
			rtd_printk(KERN_ERR, TAG_NAME, "HDR10, kernel VPQ_IOC_SET_GAMUT_3D_LUT_N17_BUFFER fail\n");
			ret = -1;
		}
		else
		{
			//static struct task_struct *p_pq_tsk_HDR_3dLUT_16 = NULL;

			static PQ_HDR_3dLUT_16_PARAM args;
			args.c3dLUT_16_enable = 1;
			args.a3dLUT_16_pArray = (UINT16*)(void __user *)&(phdr3dlut16.hdr_3dlut);

			//UINT32 rc = 0;
			//for (rc = 0; rc < 10; rc++)
			//	printk("3dlut[%d]= %d, 3dlut[%d]= %d, 3dlut[%d]= %d\n", 3*rc, phdr3dlut16.hdr_3dlut[3*rc], 3*rc + 1, phdr3dlut16.hdr_3dlut[3*rc + 1], 3*rc + 2, phdr3dlut16.hdr_3dlut[3*rc + 2]);

			#if 0
			p_pq_tsk_HDR_3dLUT_16 = kthread_create(fwif_color_set_DM_HDR_3dLUT_16, (void *)&args, "fwif_color_set_DM_HDR_3dLUT_16");
			if (p_pq_tsk_HDR_3dLUT_16) {
				wake_up_process(p_pq_tsk_HDR_3dLUT_16);
			}
			#else
			if (fwif_HDR_compare_3DLUT(&args, OLD_17x17x17))
			{
				down(&VPQ_DM_3DLUT_Semaphore);
				fwif_color_set_DM_HDR_3dLUT_16(&args);
				up(&VPQ_DM_3DLUT_Semaphore);
			}
			#endif
		}
		break;

	}

	case VPQ_IOC_SET_HDR_3DLUT_24x24x24_16_1:
	{
		//rtd_printk(KERN_INFO, TAG_NAME, "HDR10, get 3DLUT, 24x24x24 16bit, FRONT\n");
		UINT8 data_protect_cfu = 100;
		while(copy_from_user(&phdr3dlut16, (void __user *)arg, (sizeof(short) * ((HDR_24x24x24_size*3)>>1))) && (data_protect_cfu > 0))
		{
			msleep(10);
			data_protect_cfu--;
		}

		if (data_protect_cfu == 0)
		{
			rtd_printk(KERN_ERR, TAG_NAME, "HDR10, CSC3 table copy fail\n");
			ret = -1;
		}
		break;

	}

	case VPQ_IOC_SET_HDR_3DLUT_24x24x24_16_2:
	{
		rtd_printk(KERN_INFO, TAG_NAME, "HDR10, get 3DLUT, 24x24x24 16bit, END\n");
		UINT8 data_protect_cfu = 100;
		while(copy_from_user(((UINT16*)(void __user *)&(phdr3dlut16.hdr_3dlut)) + ((HDR_24x24x24_size*3)>>1), (void __user *)arg, (sizeof(short) * ((HDR_24x24x24_size*3)>>1))) && (data_protect_cfu > 0))
		{
			msleep(10);
			data_protect_cfu--;
		}

		if (data_protect_cfu == 0)
		{
			rtd_printk(KERN_ERR, TAG_NAME, "HDR10, CSC3 table copy fail 2\n");
			ret = -1;
		}
		else
		{
			static PQ_HDR_3dLUT_16_PARAM args;
			args.c3dLUT_16_enable = 1;
			args.a3dLUT_16_pArray = (UINT16*)(void __user *)&(phdr3dlut16.hdr_3dlut);
			drvif_Set_DM_HDR_CLK();	// enable DM & Composer clock
			fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(&args);
		}

		break;
	}
	case VPQ_IOC_SET_HDR_Eotf:
	{
		rtd_printk(KERN_INFO, TAG_NAME, "HDR10, SET_HDR_Eotf\n");
		HAL_VPQ_DATA_T Eotf_data;
		if (copy_from_user(&Eotf_data, (int __user *)arg, sizeof(HAL_VPQ_DATA_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "HDR10, Eotf struct copy fail\n");
			ret = -1;
			break;
		}

		UINT8 data_protect_cfu = 100;
		while(copy_from_user(Eotf_table32, (int __user *)Eotf_data.pData, EOTF_size * 4) && data_protect_cfu)
		{
			msleep(10);
			data_protect_cfu--;
		}

		if (data_protect_cfu == 0)
		{
			rtd_printk(KERN_ERR, TAG_NAME, "HDR10, Eotf table copy fail\n");
			ret = -1;
		}
		else
		{
			Eotf_table32[EOTF_size - 1] = 0xffffffff;
			//UINT16 i;
			//for (i = 0; i < EOTF_size; i++)
				//printk("roger, Eotf[%d] = %d\n", i, Eotf_table32[i]);

			fwif_color_set_DM2_EOTF_TV006(Eotf_table32);
		}
		break;
	}
	case VPQ_IOC_SET_HDR_Oetf:
	{
		rtd_printk(KERN_INFO, TAG_NAME, "HDR10, SET_HDR_Oetf\n");
		HAL_VPQ_DATA_T Oetf_data;
		if (copy_from_user(&Oetf_data, (int __user *)arg, sizeof(HAL_VPQ_DATA_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "HDR10, Oetf struct copy fail\n");
			ret = -1;
			break;
		}

		UINT8 data_protect_cfu = 100;
		while(copy_from_user(Oetf_table16, (int __user *)Oetf_data.pData, OETF_size * 2) && data_protect_cfu)
		{
			msleep(10);
			data_protect_cfu--;
		}

		if (data_protect_cfu == 0)
		{
			rtd_printk(KERN_ERR, TAG_NAME, "HDR10, Oetf table copy fail\n");
			ret = -1;
		}
		else
		{
			Oetf_table16[OETF_size - 1] = 0xffff;
			//UINT16 i;
			//for (i = 0; i < OETF_size; i++)
				//printk("roger, Oetf[%d] = %d\n", i, Oetf_table16[i]);

			fwif_color_set_DM2_OETF_TV006(Oetf_table16);
		}
		break;
	}

	case VPQ_IOC_SET_PQModeInfo:
	{
		rtd_printk(KERN_INFO, TAG_NAME, "HDR main contorl, SET_PQModeInfo\n");
		HAL_VPQ_DATA_T PQModeInfo_data;
		if (copy_from_user(&PQModeInfo_data, (int __user *)arg, sizeof(HAL_VPQ_DATA_T))) {
			rtd_printk(KERN_ERR, TAG_NAME, "HDR main contorl, PQModeInfo struct copy fail\n");
			ret = -1;
			break;
		}

		if(copy_from_user(PQModeInfo_flag, (int __user *)PQModeInfo_data.pData, PQModeInfo_data.length))
		{
			rtd_printk(KERN_ERR, TAG_NAME, "HDR main contorl, PQModeInfo table copy fail\n");
			ret = -1;
		}
		else
		{
#ifndef CONFIG_HDR_SDR_SEAMLESS	/* seamless need to check force bg and mode active*/
			drvif_TV006_SET_HDR_mode(PQModeInfo_flag);
			fwif_color_SetDataFormatHandler_tv006();
#else
			if ((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE))
			{
				/* seamless. do seamless process in isr (void Scaler_hdr_setting_SEAMLESS()), avoid transient noise*/;
			} else {
				//IoReg_Write32(0xb802e4f4, (IoReg_Read32(0xb802e4f4) | (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) << 16) | (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) << 8)));
				drvif_TV006_SET_HDR_mode(PQModeInfo_flag);
				fwif_color_SetDataFormatHandler_tv006();
			}
			HDR_SDR_SEAMLESS_PQ.HDR_SDR_SEAMLESS_PQ_SET[HDR_SDR_SEAMLESS_PQ_HAL_PQModeInfo]=1;
#endif
		}
		break;
	}

	case VPQ_IOC_GET_HDR_PicInfo:
	{
		//get histogram protect
		if (fwif_color_get_DM_HDR10_enable_TV006() == 0) {
			//rtd_printk(KERN_NOTICE, TAG_NAME, "kernel fwif_color_get_DM2_HDR_histogram_TV006 should not run in SDR content\n");
			ret = -1;
			break;
		}
		UINT32 HDR_info_bin[131] = {0};

		if (fwif_color_get_DM2_HDR_histogram_TV006(HDR_info_bin) == 0) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_DM2_HDR_histogram_TV006 fail\n");
			ret = -1;
		} else {
			if (copy_to_user(arg, HDR_info_bin, 131 * 4)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HDR_PicInfo fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
	}

	case VPQ_IOC_SET_HDR_InvGamma:
	{
		rtd_printk(KERN_INFO, TAG_NAME, "HDR10, SET_HDR_InvGamma\n");
		UINT8 HDR_InvGamma_en = 0;
		if (copy_from_user(&HDR_InvGamma_en, arg, 1)) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_HDR_InvGamma fail\n");
			ret = -1;
		} else {
#ifndef CONFIG_HDR_SDR_SEAMLESS	/* seamless need to check force bg and mode active*/
			drvif_DM2_GAMMA_Enable(HDR_InvGamma_en);
#else
			if ((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && (Check_AP_Set_Enable_ForceBG(SLR_MAIN_DISPLAY) == FALSE))
			{
				/* seamless. do seamless process in isr (void Scaler_hdr_setting_SEAMLESS()), avoid transient noise*/;
			} else {
				drvif_DM2_GAMMA_Enable(HDR_InvGamma_en);
			}
			//HDR_SDR_SEAMLESS_PQ.HDR_SDR_SEAMLESS_PQ_SET[HDR_SDR_SEAMLESS_PQ_HAL_PQModeInfo]=1;
#endif
		}
		break;
	}

	case VPQ_IOC_HDR_DEMO_Mode_ON:
	{
		Scaler_color_set_HDR_DEMO_Mode_ON();
		break;
	}
	case VPQ_IOC_HDR_DEMO_Mode_OFF:
	{
		Scaler_color_set_HDR_DEMO_Mode_OFF();
		break;
	}

	case VPQ_IOC_SET_COLOR_GAMUT:
		{
			if (copy_from_user(&gamutData, (void __user *)arg, sizeof(COLOR_GAMUT_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_COLOR_GAMUT fail\n");
				ret = -1;
			} else {
				unsigned char invgamma_enable;
				short sRGBMatrix[3][3];

				invgamma_enable = gamutData.gamutMapping.invgamma_enable & 0xff;

				/*rtd_printk(KERN_DEBUG, TAG_NAME, "gamutData.gamutMapping.invgamma_enable = %d, invgamma_enable = %d\n", gamutData.gamutMapping.invgamma_enable, invgamma_enable);*/

				if (g_InvGammaPowerMode != invgamma_enable) {
					g_InvGammaPowerMode = invgamma_enable;

					switch(g_InvGammaPowerMode)
					{
						case VPQ_GAMMA_MODE_INV_OFF_INNER_BYPASS:
						default:
							drvif_color_inv_gamma_enable(SLR_MAIN_DISPLAY, 0, 1);
							drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, 0, 1);
							break;
						case VPQ_GAMMA_MODE_INV_OFF_INNER_ON:
							drvif_color_inv_gamma_enable(SLR_MAIN_DISPLAY, 0, 1);
							drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, 0, 1);
							break;
						case VPQ_GAMMA_MODE_INV_ON_INNER_BYPASS:
							drvif_color_inv_gamma_enable(SLR_MAIN_DISPLAY, 1, 1);
							drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, 1, 1);
							break;
						case VPQ_GAMMA_MODE_INV_ON_INNER_ON:
							drvif_color_inv_gamma_enable(SLR_MAIN_DISPLAY, 1, 1);
							drvif_color_inv_gamma_enable(SLR_SUB_DISPLAY, 1, 1);
							break;
					}
					vpq_set_gamma(1, 1);
				}

				sRGBMatrix[0][0] = gamutData.gamutMapping.gamutmatrix_00;
				sRGBMatrix[0][1] = gamutData.gamutMapping.gamutmatrix_01;
				sRGBMatrix[0][2] = gamutData.gamutMapping.gamutmatrix_02;
				sRGBMatrix[1][0] = gamutData.gamutMapping.gamutmatrix_10;
				sRGBMatrix[1][1] = gamutData.gamutMapping.gamutmatrix_11;
				sRGBMatrix[1][2] = gamutData.gamutMapping.gamutmatrix_12;
				sRGBMatrix[2][0] = gamutData.gamutMapping.gamutmatrix_20;
				sRGBMatrix[2][1] = gamutData.gamutMapping.gamutmatrix_21;
				sRGBMatrix[2][2] = gamutData.gamutMapping.gamutmatrix_22;

				fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, sRGBMatrix, g_srgbForceUpdate);
				g_srgbForceUpdate = 0;

				/*=== Gamut 3D LUT ===*/
				if (gamutData.gamutMapping.b3DLUT_internalselect) {//0:RTK DB, 1:LG DB
					if (g_3DLUT_LastInternalSelect != gamutData.gamutMapping.b3DLUT_internalselect || g_3DLUT_Resume) {
						vpq_set_Gamut_3D_Lut_LGDB(&g_buf3DLUT_LGDB, gamutData.gamutMapping.b3DLUT_enable, 0);
						g_3DLUT_Resume = 0;
					} else {
						/*compare table*/
						if (memcmp(&g_buf3DLUT_LGDB.pt, &g_LGDB_3D_LUT_BUF[0].pt, sizeof(GAMUT_3D_LUT_PT_T)*4913) != 0) {//different
							vpq_set_Gamut_3D_Lut_LGDB(&g_buf3DLUT_LGDB, gamutData.gamutMapping.b3DLUT_enable, 0);
						} else if (g_3DLUT_LastEnableSatus == 0 && gamutData.gamutMapping.b3DLUT_enable == 1) {
							vpq_set_Gamut_3D_Lut_LGDB(&g_buf3DLUT_LGDB, gamutData.gamutMapping.b3DLUT_enable, 1);
						}
					}
					if (gamutData.gamutMapping.b3DLUT_enable) {
						memcpy(&g_LGDB_3D_LUT_BUF[0].pt, &g_buf3DLUT_LGDB.pt, sizeof(GAMUT_3D_LUT_PT_T)*4913);
					}
				} else {
					if (g_3DLUT_LastInternalSelect != gamutData.gamutMapping.b3DLUT_internalselect) {
						vpq_set_3d_lut_index(gamutData.gamutMapping.b3DLUT_enable?(gamutData.gamutMapping.u3DLUT_index+1):0, 1); //force write
					} else {
						vpq_set_3d_lut_index(gamutData.gamutMapping.b3DLUT_enable?(gamutData.gamutMapping.u3DLUT_index+1):0, 0);
					}
				}
				g_3DLUT_LastInternalSelect = gamutData.gamutMapping.b3DLUT_internalselect;
				g_3DLUT_LastEnableSatus = gamutData.gamutMapping.b3DLUT_enable;
				/*====================*/
				ret = 0;
			}
		}
		break;

	case VPQ_IOC_SET_SAT_LUT:
		{

			if (fwif_color_vpq_stop_ioctl(STOP_VPQ_IOC_SET_SAT_LUT, ACCESS_MODE_GET, 0))
				return 0;

			if (copy_from_user(&satLutData, (int __user *)arg, sizeof(VPQ_SAT_LUT_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_SAT_LUT fail\n");
				ret = -1;
			} else {
				ret = fwif_color_set_DSE_tv006(SLR_MAIN_DISPLAY, &satLutData);
				if (ret == 0)
					g_bAPLColorGainClr = 0;
			}
		}
		break;

	case VPQ_IOC_SET_DITHER_BIT:
		{
			unsigned int args;
			if (copy_from_user(&args, (int __user *)arg, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_PIC_CTRL fail\n");
				ret = -1;
			} else {
				drvif_color_Setditherbit(args);
				drvif_color_setdithering();
				ret = 0;
			}
		}
		break;
	/*
	case VPQ_IOC_SET_GAMUT_3D_LUT_N9_BUFFER:
		{
			GAMUT_3D_LUT_9x9x9_T *pLut = NULL;
			pLut = (GAMUT_3D_LUT_9x9x9_T *)kmalloc(sizeof(GAMUT_3D_LUT_9x9x9_T), GFP_KERNEL);
			if (pLut == NULL) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_GAMUT_3D_LUT_N9_BUFFER malloc fail\n");
				return -1;
			}

			if (copy_from_user(pLut, (void __user *)arg, sizeof(GAMUT_3D_LUT_9x9x9_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_GAMUT_3D_LUT_N9_BUFFER fail\n");
				ret = -1;
			} else
				ret = fwif_color_set_Gamut_3D_Lut_N9_to_N17_tv006(pLut)?0:-1;

			kfree(pLut);
		}
			break;
	*/
	case VPQ_IOC_SET_GAMUT_3D_LUT_N17_BUFFER:
		{
			if (copy_from_user(&g_buf3DLUT_LGDB.pt, (void __user *)arg, sizeof(GAMUT_3D_LUT_PT_T)*4913)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_GAMUT_3D_LUT_N17_BUFFER fail\n");
				ret = -1;
			} else {
				g_bGamut3DLUT_LGDB_NeedUpdated = 1;
			}
		}
		break;
	case VPQ_IOC_SET_GAMUT_3D_LUT_INDEX:
		{
			unsigned int value;
			if (copy_from_user(&value, (void __user *)arg, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_SET_GAMUT_3D_LUT_INDEX fail\n");
				ret = -1;
			} else {
				fwif_color_set_3dLUT(value);
				ret = 0;
			}
		}
		break;
	case VPQ_IOC_SET_LOWDELAY_MODE:
		{
			game_process = 0;
			if (Get_Factory_SelfDiagnosis_Mode() /*|| (Get_LivezoomOffMainForceBG() == TRUE) || (Get_Live_zoom_mode()!=LIVE_ZOOM_OFF)*/) {
				/*qiangzhou added20151228:livezoom,magnifier and self diagnosis not support low delay setting*/
				ret = 0;
			} else {
				bool lowdelaymode;
				static bool pre_lowdelaymode;
				if (copy_from_user(&lowdelaymode, (int __user *)arg, sizeof(bool))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_LOWDELAY_MODE fail\n");
					ret = -1;
				} else {
					game_process = 1;
					fw_scalerip_set_di_gamemode(lowdelaymode);
					pre_lowdelaymode = lowdelaymode;
					if(((lowdelaymode == FALSE) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE))||(rtk_hal_vsc_GetRGB444Mode() == TRUE&&(Get_DisplayMode_Src(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) == VSC_INPUTSRC_HDMI))){ //not game mode and not _MODE_STATE_ACTIVE
						//fw_scalerip_set_di_gamemode(lowdelaymode);
						//drv_memory_set_game_mode_dynamic(_DISABLE);
						fw_scalerip_set_di_gamemode_setting(_DISABLE);
						//ret = 0;
						//break;
					}
					if (g_bDIGameModeOnlyDebug) //for di game mode debug, only can enabled by rtice tool
						return ret;
#if 0
					if(((pre_lowdelaymode == lowdelaymode) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))) {
						//fw_scalerip_set_di_gamemode(lowdelaymode);
						ret = 0;
						break;
					}
#endif
					if(lowdelaymode) {
						//printk(KERN_EMERG"[crixus]VPQ_IOC_SET_LOWDELAY_MODE1\n");
						//game mode dynamic, check in vsc task @Crixus 20151228
						drv_memory_set_game_mode_dynamic(_ENABLE);
					} else {
						//printk(KERN_EMERG"[crixus]VPQ_IOC_SET_LOWDELAY_MODE0\n");
						//game mode dynamic, check in vsc task @Crixus 20151228
						drv_memory_set_game_mode_dynamic(_DISABLE);
					}

					//Game mode cmd checking flow @Cixus 20161204
					if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE){
						down(get_gamemode_check_semaphore());
						/*overflow protection*/
						if(game_mode_cmd_check == 0xffffffff)
							game_mode_cmd_check = 0;
						else if(lowdelaymode != drv_memory_get_game_mode_flag())	// game_mode_cmd_check + 1 when current  != AP setting in picture mode
							game_mode_cmd_check = game_mode_cmd_check + 1;
						up(get_gamemode_check_semaphore());
						//printk(KERN_EMERG"[crixus]game_mode_cmd_check = %d\n", game_mode_cmd_check);
					}
					ret = 0;
				}
			}
		}
		break;

	case VPQ_IOC_SET_OdExtentions:
		{

			HAL_VPQ_DATA_T OD_Ext_Info;
			HAL_VPQ_OD_Extention_T OD_Ext_Data;

			if( copy_from_user(&OD_Ext_Info, (int __user *)arg, sizeof(HAL_VPQ_DATA_T)) )
			{
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_OdExtentions fail\n");
				ret = -1;
				break;
			}
			else
			{
				if( copy_from_user(&OD_Ext_Data, (int __user *)OD_Ext_Info.pData, sizeof(HAL_VPQ_OD_Extention_T)) )
				{
					rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_OdExtentions_pData fail\n");
					ret = -1;
				}
				else
				{
					if( OD_Ext_Data.extType == 1 ) /*PCID*/
					{
						if( OD_Ext_Data.extLength != PCID_TABLE_LEN )
						{
							rtd_printk(KERN_ERR, TAG_NAME, "PCID LUT length = %d error!\n", OD_Ext_Data.extLength);
							ret = -1;
						}
						else
						{
							unsigned char* pLUT = NULL;
							pLUT = (unsigned char *)dvr_malloc(PCID_TABLE_LEN*sizeof(unsigned char));
							if(pLUT == NULL)
							{
								rtd_printk(KERN_ERR, TAG_NAME, "[ERROR] VPQ_IOC_SET_OdExtentions PCID Table allocate fail\n");
								return -1;
							}

							if( copy_from_user(pLUT, (int __user *)OD_Ext_Data.pExtData, 289*sizeof(UINT8)) )
							{
								rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_OdExtentions_pData(PCID) fail\n");
								ret = -1;
							}
							else
							{
								fwif_color_set_pcid_valuetable(pLUT);
								fwif_color_set_pcid_pixel_setting();
								drvif_color_pcid_enable(1);
								g_pcid_en = 1;
								g_pcid2_en = 0;
								ret = 0;
							}
							dvr_free(pLUT);
						}
					}
					else
					{
						rtd_printk(KERN_ERR, TAG_NAME, "OD Extend type error = %d error\n", OD_Ext_Data.extType);
						ret = -1;
					}
				}
			}
		}
		break;
		case VPQ_IOC_SET_Od:
		{
			extern unsigned char od_table_tv006_store[OD_table_length];
			HAL_VPQ_DATA_T OD_Info;
			int i;

			if (copy_from_user(&OD_Info, (int __user *)arg, sizeof(HAL_VPQ_DATA_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_OdExtentions fail\n");
				ret = -1;
				break;
			} else {

				if (copy_from_user(&OD_FPP_Table[0], (int __user *)OD_Info.pData, (OD_Info.length)*sizeof(unsigned int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_IOC_SET_OdExtentions_pData fail\n");
					ret = -1;

				} else {
					extern unsigned char bODInited;
					extern unsigned char bODTableLoaded;
					extern unsigned char bODPreEnable;
					extern char od_table_mode_store;
					//extern unsigned int od_table_store[OD_table_length];
					extern unsigned int od_delta_table[OD_table_length];

					//open OD double buffer
					od_od_ctrl1_RBUS od_od_ctrl1_reg;
					od_od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
					od_od_ctrl1_reg.od_en_dbf_en = 1;
					IoReg_Write32(OD_OD_CTRL1_reg, od_od_ctrl1_reg.regValue);

					for(i=0;i<289;i++)
					{
						od_table_tv006_store[i] = (unsigned char)OD_FPP_Table[i];
					}
					 fwif_color_od_table_17x17_transform(0, od_table_tv006_store, od_delta_table);
					 drvif_color_od_table_seperate_write(od_delta_table, 0, 3); // 3: write to rgb channel

					//drvif_color_od_table(od_delta_table, 0);// 0:delta mode 1:target mode(output mode)
					// Mac5p seperate PCID and OD, mark by henry
					/*if (g_pcid2_en)
						drvif_color_pcid2_enable(1);
					else if (g_pcid_en)
						drvif_color_pcid_enable(1);*/

					od_table_mode_store = 1;// 0:target mode 1:delta mode -1:inverse mode
					bODTableLoaded = TRUE;

					/*Enable OD*/
					bODPreEnable = TRUE;
					if (!bODInited || !bODTableLoaded)
						return -1;
					fwif_color_set_od(TRUE);

					ret = 0;

				}


			}

		}
		break;

	default:
		rtd_printk(KERN_DEBUG, TAG_NAME, "kernel IO command %d not found!\n", cmd);
		return -1;
			;
	}
	return ret;/*Success*/

}


struct file_operations vpq_fops = {
	.owner = THIS_MODULE,
	.open = vpq_open,
	.release = vpq_release,
	.read  = vpq_read,
	.write = vpq_write,
	.unlocked_ioctl = vpq_ioctl,
};

#ifdef CONFIG_PM
static const struct dev_pm_ops vpq_pm_ops =
{
        .suspend    = vpq_suspend,
        .resume     = vpq_resume,
#ifdef CONFIG_HIBERNATION
	.freeze 	= vpq_suspend_std,
	.thaw		= vpq_resume_std,
	.poweroff	= vpq_suspend_std,
	.restore	= vpq_resume_std,
#endif

};
#endif // CONFIG_PM

static struct class *vpq_class = NULL;
static struct platform_device *vpq_platform_devs = NULL;
static struct platform_driver vpq_platform_driver = {
	.driver = {
		.name = "vpqdev",
		.bus = &platform_bus_type,
#ifdef CONFIG_PM
		.pm = &vpq_pm_ops,
#endif
    },
} ;

static char *vpq_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

typedef struct{
	unsigned long para1;
	unsigned long para2;
} PQ_THREAD_PARAM;

enum {
	RPC_V2K_FW_FILM = 0,
	RPC_V2K_MAX
};

static struct task_struct *p_pq_tsk = NULL;
unsigned char vgip_isr_flag = FALSE;
static int vpq_vgip_isr_tsk(void *p)
{
	PQ_THREAD_PARAM *pParam = (PQ_THREAD_PARAM *)p;

	switch(pParam->para1&0xff) {
	case RPC_V2K_FW_FILM:
	{
		extern unsigned char g_st_DI_STATUS_VPAN;
		g_st_DI_STATUS_VPAN = pParam->para2&0xff;
		scalerVIP_film_FWmode();
		break;
	}
	default:
		;
	}
	vgip_isr_flag = FALSE;
	return 0;
}

unsigned int rpc_vgip_isr_vact_start(unsigned long para1, unsigned long para2)
{
	int err = 0;
	static PQ_THREAD_PARAM arg;
	arg.para1 = para1;
	arg.para2 = para2;

	if (!vgip_isr_flag) {
		p_pq_tsk = kthread_create(vpq_vgip_isr_tsk, (void *)&arg, "vpq_vgip_isr_tsk");

		if (p_pq_tsk) {
			    wake_up_process(p_pq_tsk);
			    vgip_isr_flag = TRUE;
		} else {
		    err = PTR_ERR(p_pq_tsk);
		    rtd_printk(KERN_ERR, TAG_NAME, "Unable to start rpc_vgip_isr_vact_start (err_id = %d)./n", err);
		}
	}/* else
		rtd_printk(KERN_DEBUG, TAG_NAME, "rpc_vgip_isr_vact_start vgip_isr_flag = TRUE\n");*/

	return 0;
}


int vpq_module_init(void)
{
	int result;
	result = alloc_chrdev_region(&vpq_devno, 0, 1, "vpqdevno");

	if (result != 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "Cannot allocate VPQ device number\n");
		return result;
	}

	vpq_class = class_create(THIS_MODULE, "vpqdev");
	if (IS_ERR(vpq_class)) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpq: can not create class...\n");
		result = PTR_ERR(vpq_class);
		goto fail_class_create;
	}

	vpq_class->devnode = vpq_devnode;

	vpq_platform_devs = platform_device_register_simple("vpqdev", -1, NULL, 0);
	if (platform_driver_register(&vpq_platform_driver) != 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpq: can not register platform driver...\n");
		result = -ENOMEM;
		goto fail_platform_driver_register;
	}

	cdev_init(&vpq_cdev, &vpq_fops);
	result = cdev_add(&vpq_cdev, vpq_devno, 1);
	if (result < 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpq: can not add character device...\n");
		goto fail_cdev_init;
	}

	device_create(vpq_class, NULL, vpq_devno, NULL, "vpqdev");

	sema_init(&VPQ_Semaphore, 1);
	sema_init(&VPQ_DM_3DLUT_Semaphore,1);
	sema_init(&VPQ_Semaphore_extern, 1);

	if (0x00060000 == vpq_project_id) {
		vpq_boot_init();
	} else
		fwif_color_set_pq_demo_flag_rpc(1);
	fwif_color_reg_demo_callback(DEMO_CALLBACKID_ON_OFF_SWITCH, vpq_demo_pq_func);
	fwif_color_reg_demo_callback(DEMO_CALLBACKID_OVERSCAN, vpq_demo_overscan_func);
	//register_kernel_rpc(RPC_VCPU_ID_0x130_VGIP_ISR_VACT_START, (FUNC_PTR)&rpc_vgip_isr_vact_start);

	//fwif_color_od_init(10,0,60);

	return 0;/*Success*/

fail_cdev_init:
	platform_driver_unregister(&vpq_platform_driver);
fail_platform_driver_register:
	platform_device_unregister(vpq_platform_devs);
	vpq_platform_devs = NULL;
	class_destroy(vpq_class);
fail_class_create:
	vpq_class = NULL;
	unregister_chrdev_region(vpq_devno, 1);
	return result;

}



void __exit vpq_module_exit(void)
{
	if (vpq_platform_devs == NULL)
		BUG();

	delete_film_fw_tsk();
	device_destroy(vpq_class, vpq_devno);
	cdev_del(&vpq_cdev);

	platform_driver_unregister(&vpq_platform_driver);
	platform_device_unregister(vpq_platform_devs);
	vpq_platform_devs = NULL;

	class_destroy(vpq_class);
	vpq_class = NULL;

	unregister_chrdev_region(vpq_devno, 1);
}

module_init(vpq_module_init);
module_exit(vpq_module_exit);
