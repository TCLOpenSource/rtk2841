/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmi_driver.c
 *
 * author: 	Spider Man, Peter Parker
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include <linux/slab.h>
#include "hdmi_common.h"
#include "hdmi_table.h"
#include "hdmi_edid.h"
#include "hdmi_perf_log.h"
#include "hdmi_vfe_config.h"
#include <tvscalercontrol/hdmirx/hdmi_vfe.h>

//20151206 andy modify for HPD low delayed work
//#include <linux/workqueue.h>
//20151206 andy modify for HPD low delayed work
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#include <rbus/h3ddma_reg.h>





/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/
#define HDCP_AKSV_SIZE_BYTES 	5
#define TOTAL_3D 		16




/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/
enum vfe_hdmi_drv_state_e {
	VFE_HDMI_DRV_SUSPEND_STATE,
	VFE_HDMI_DRV_INIT_STATE,
	VFE_HDMI_DRV_SERVICE_STATE,
};

enum hdmi_drv_error_e {
	HDMI_DRV_NO_ERR = 0,
	HDMI_DRV_STATE_ERR,
	HDMI_DRV_ARG_ERR,
	HDMI_DRV_HW_ERR,
};

typedef struct {
	unsigned char port;
	unsigned char pre_state;
              unsigned char cur_state;
} hdmi_drv_connect_state_st;

#ifdef CONFIG_PM

typedef struct {
	unsigned char port;
	int pre_b_value;
} hdmi_drv_resume_st;

#endif /*CONFIG_PM*/


/* 3d format mapping */
unsigned char mapping3dformat[TOTAL_3D] = {
	VFE_HDMI_3D_FORMAT_FRAME_PACKING,
	VFE_HDMI_3D_FORMAT_FIELD_ALTERNATIVE,
	VFE_HDMI_3D_FORMAT_LINE_ALTERNATIVE,
	VFE_HDMI_3D_FORMAT_SIDEBYSIDE_FULL,
	VFE_HDMI_3D_FORMAT_2D, // rtk:HDMI3D_L_DEPTH //to check 3
	VFE_HDMI_3D_FORMAT_2D, // rtk:HDMI3D_L_DEPTH_GPX //to check 3
	VFE_HDMI_3D_FORMAT_TOP_BOTTOM,
	VFE_HDMI_3D_FORMAT_FRAME_SEQ,
	VFE_HDMI_3D_FORMAT_SIDEBYSIDE_HALF,
	VFE_HDMI_3D_FORMAT_LINE_INTERLEAVE_HALF, // rtk:HDMI3D_LINE_BY_LINE // to check 3
	VFE_HDMI_3D_FORMAT_COLUMN_INTERLEAVE, // rtk:HDMI3D_VERTICAL_STRIPE // to check 3
	VFE_HDMI_3D_FORMAT_CHECKER_BOARD,
	VFE_HDMI_3D_FORMAT_2D, // rtk:HDMI3D_REALID // to check 3
	VFE_HDMI_3D_FORMAT_2D, // rtk:HDMI3D_SENSIO // to check 3
	VFE_HDMI_3D_FORMAT_2D,
	VFE_HDMI_3D_FORMAT_2D
};



/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/

unsigned int g_hdmi_drv_state = VFE_HDMI_DRV_SUSPEND_STATE;
#ifdef HDMI_PORT_MUX
unsigned char g_hdmi_drv_port_use_connect_flag[HDMI_RX_PORT_MAX_NUM] = {0};
#else
unsigned char g_hdmi_drv_port_use_connect_flag[HDMI_RX_PORT_MAX_NUM] = {0};
#endif


#ifdef CONFIG_PM
hdmi_drv_resume_st g_resume_param;
#endif /*CONFIG_PM*/

static unsigned char resume_hpd_control = 0;


//#define AVI_INFO_COMPARE	1

char* g_avi_csc_string_table[4] = {"CSC_RGB", "CSC_YCBCR422", "CSC_YCBCR444","CSC_FUTURE"};
char* g_avi_bi_string_table[4] = {"INVALID", "V", "H","VERTHORIZVALID"};
char* g_avi_scan_info_string_table[4] = {"NODATA", "OVERSCANNED", "UNDERSCANNED","FUTURE"};
char* g_avi_colorimetry_string_table[4] = {"NODATA", "SMPTE170", "ITU709","COLORIMETRY_FUTURE"};
char* g_avi_arc_string_table[4] = {"NODATA", "4_3", "16_9","FUTURE"};
char* g_avi_active_arc_string_table[5] = {"ARC_PICTURE", "4_3CENTER", "16_9CENTER","14_9CENTER", "OTHER"};
char* g_avi_scaling_string_table[4] = {"NOSCALING", "HS", "VS","HVS"};
char* g_avi_itcontent_string_table[3] = {"NODATA", "ITCONTENT"};
char* g_avi_extcolorimetry_string_table[8] = {"XVYCC601", "XVYCC709","sYCC601","AdobeYCC601","AdobeRGB","ITURBT2020YCCBCCRC,","ITURBT2020RGBorYCBCR", "RESERED"};
char* g_avi_rgb_quantization_string_table[4] = {"DEFAULT", "LIMIT", "FULL","RESERVED"};
char* g_avi_ycc_quantization_string_table[3] = {"LIMIT", "FULL", "RESERVED"};
char* g_avi_content_type_string_table[5] = {"GRAPHICS ", "PHOTO", "CINEMA","GAME","MAX"};

UINT8 HDCP_key_loaded[VFE_HDCP_MAX] = {0};

#define HDCP_2P2_RECEIVER_ID_SIZE	5
UINT8 HDCP_2p2_ReceiverdId[HDCP_2P2_RECEIVER_ID_SIZE] = {0};

/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/

#ifdef AVI_INFO_COMPARE
bool Cmp_AviInfoFrame(vfe_hdmi_avi_t *info_frameA,vfe_hdmi_avi_t *info_frameB);
#endif //AVI_INFO_COMPARE
char hdmi_suspend_set_hotplug_flag=0;


/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/


/*-------------------------------------------
 * Func : HdmiTable_Init
 *
 * Desc : init EDID & HDCP key resource
 *
 * Para : N/A
 *
 * Retn : N/A
 *-------------------------------------------*/
static void HdmiTable_Init(void)
{
	unsigned int i;
	HDMI_CHANNEL_T_PCB_INFO default_channel[HDMI_PHY_TOTAL_NUM];

	/* Initial */
	for (i=0; i < HDMI_PHY_TOTAL_NUM; i++) {
		default_channel[i].phy_port = i;
		default_channel[i].ddc_selected = i;
		default_channel[i].edid_type = HDMI_EDID_ONCHIP;
		//default_channel[i].edid_initialized = 0;
	}

	/* By PCB Define */
	for (i=0; i<HDMI_PHY_TOTAL_NUM; i++) {
		 if (hdmi_vfe_get_rx_port_info(i,  &default_channel[i]) == 0) {
			//printf("HDMI%d get board info fail\n", i);
			continue;
		 }
	}

	/* Save to hdmi_rx structure array */
	for (i=0; i<HDMI_PHY_TOTAL_NUM; i++)
	{
		drvif_hdmi_save_pcbinfo(i, &default_channel[i]);

    if (!newbase_hdmi_edid_initialized(i))
      vfe_hdmi_drv_write_edid(i, default_hdmi_edid_table[i], 256, 0);  // write edid to a given hdmi port without enable it
	}


#if USE_DEFAULT_HDCP14
	drvif_hdmi_save_hdcp(&default_hdcpkey);
#else
	//Customerize your HDCP key
#endif

	return;
}




/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/

/*-------------------------------------------
 * Func : vfe_hdmi_drv_init
 *
 * Desc : init HDMI video frontend. 
 *
 * Para : N/A
 *
 * Retn : 0 : success, others : failed
 *-------------------------------------------*/
int vfe_hdmi_drv_init(void)
{
	unsigned char i =0;
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SUSPEND_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}
	
	g_hdmi_drv_state = VFE_HDMI_DRV_INIT_STATE;

	lib_hdmi_reg_init(); //to prevent load HDCP reg NG

	HdmiTable_Init();

	newbase_hdmi_init();

	g_hdmi_drv_state = VFE_HDMI_DRV_SERVICE_STATE;

#ifdef __HDMI_PERF_LOG__
	end_time = GET_SCPU_CLK_TIME();
	pr_debug("[%s] [- PERF_LOG] =>\n", __func__);
	LOG_SCPU_TIME_SUB(end_time, start_time);
#endif

	for(i = 0; i < HDMI_RX_PORT_MAX_NUM; i++)
	{	
		g_hdmi_drv_port_use_connect_flag[i] = 0;
		newbase_hdmi_init_source(i);
	}

#if HDMI_STR_HPD_SPEED_UP_ENABLE
	// if CEC disable, newbase_hdmi_init_source() will enable hotplug
	if(1 == lib_hdmi_cec_is_enabled())
	{
		resume_hpd_control = 0;
		newbase_hdmi_hpd_delay_work_init();
	}
#else //#if HDMI_STR_HPD_SPEED_UP_ENABLE
	resume_hpd_control = 0;
	#ifndef CONFIG_CUSTOMER_TV030
	newbase_hdmi_hpd_delay_work_init();
	#endif
#endif //#if HDMI_STR_HPD_SPEED_UP_ENABLE
	hdmi_suspend_set_hotplug_flag=0;

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_uninit(void)
{
	unsigned char i;
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}


	for (i = 0; i < HDMI_RX_PORT_MAX_NUM; i++)
	{
		newbase_hdmi_release_source(i);
	}
	newbase_hdmi_uninit();

	g_hdmi_drv_state = VFE_HDMI_DRV_SUSPEND_STATE;

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_open(void)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	//drvif_Hdmi_Init();
	//g_hdmi_drv_state = VFE_HDMI_DRV_SERVICE_STATE;
	//Hdmi_Power(1);

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_close(void)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_connect(unsigned char port)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR] port = %d\n", port);
		return HDMI_DRV_ARG_ERR;
	}
#if 0
	if(port ==1) {
		int i =0;
		
		pr_debug("1st start\n");
		for(i =0; i<256; i+=8) {
			pr_debug(",0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x\n", edidone[i], edidone[i+1], edidone[i+2], edidone[i+3], edidone[i+4], edidone[i+5], edidone[i+6], edidone[i+7]);

		}
		pr_debug("1st end\n");
		msleep(20);
		pr_debug("2nd start");
		for(i =0; i<256; i+=8) {
			pr_debug(",0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x\n", edidtwo[i], edidtwo[i+1], edidtwo[i+2], edidtwo[i+3], edidtwo[i+4], edidtwo[i+5], edidtwo[i+6], edidtwo[i+7]);

		}
		pr_debug("2nd end\n");
		msleep(20);
		pr_debug("3th start");
		for(i =0; i<256; i+=8) {
			pr_debug(",0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x\n", edidthree[i], edidthree[i+1], edidthree[i+2], edidthree[i+3], edidthree[i+4], edidthree[i+5], edidthree[i+6], edidthree[i+7]);

		}

		pr_debug("3th end\n");
		msleep(20);
		//for(i =0; i<256; i+=8) {
		//	pr_debug(",0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x\n", edidfour[i], edidfour[i+1], edidfour[i+2], edidfour[i+3], edidfour[i+4], edidfour[i+5], edidfour[i+6], edidfour[i+7]);

		//}

		//msleep(20);
	}
#endif


	g_hdmi_drv_port_use_connect_flag[port] = 1;
	newbase_hdmi_hdr10_enable(_ENABLE);//Minchay@20160607-a add hdr10

	hdmi_time_mesaure_stop();
	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_disconnect(unsigned char port)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR] port = %d\n", port);
		return HDMI_DRV_ARG_ERR;
	}

	newbase_hdmi_disconnect_source(port);
	newbase_hdmi_hdr_disable();//Minchay@20160607-a-s add hdr10 and dolby version hdr
	g_hdmi_drv_port_use_connect_flag[port] = 0;

	return HDMI_DRV_NO_ERR;
}

unsigned char vfe_hdmi_drv_detect_mode(void)
{
unsigned char port;
	//pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

#if BIST_PLUG_CABLE
	if (hdmi_in(DBG_FW_ADDR) & DBG_31_PLUG_CABLE_TEST) {
		bist_hdmi_cable_plug_test();
	}
#endif

	down(HDMI_SMPHR_DETECT_GET());

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			newbase_hdmi_detect_mode(port);
			break;
		}
	}

	up(HDMI_SMPHR_DETECT_GET());

	return HDMI_DRV_NO_ERR;

}

int vfe_hdmi_drv_get_port_timing_info(vfe_hdmi_timing_info_t *timing_info)
{
	HDMI_TIMING_T tm;
	unsigned char port;

	//printk(KERN_EMERG "[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (timing_info == NULL) {
		pr_debug("[- ARG ERR] timing_info is NULL \n");
		return HDMI_DRV_ARG_ERR;
	}

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

	memset(timing_info, 0, sizeof(vfe_hdmi_timing_info_t));

#if BIST_PLUG_CABLE
	if (hdmi_in(DBG_FW_ADDR) & DBG_31_PLUG_CABLE_TEST)	return HDMI_DRV_STATE_ERR;
#endif

	if (!newbase_hdmi_get_timing(port, &tm))
	{
		return HDMI_DRV_NO_ERR;
	}

	timing_info->h_freq    = tm.h_freq;

#if HDMI_120HZ_SHORT_TIME_PATCH
	if((ABS(tm.h_act_len, 1920) < 10) && (ABS(tm.v_act_len, 1080) < 10))
	{
		if(tm.v_freq >= 900) // 1080P 100Hz
			tm.v_freq = 500;
		else if(tm.v_freq > 1100) // 1080P 120Hz
			tm.v_freq = 600;
	}
#endif //#if HDMI_120HZ_SHORT_TIME_PATCH

	timing_info->v_freq    = tm.v_freq;
	timing_info->h_total   = tm.h_total;
	timing_info->v_total   = tm.v_total;
	timing_info->h_porch   = tm.h_act_sta;
	timing_info->v_porch   = tm.v_act_sta;
	timing_info->active.x = 0;
	timing_info->active.y = 0;
	timing_info->active.w  = tm.h_act_len;
	timing_info->active.h  = tm.v_act_len;
	timing_info->scan_type = (!tm.is_interlace);
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
	timing_info->isDolbyHDR = Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result();//rtd_inl(HDMI_MDD_SR_reg) & _BIT0;
#else
	timing_info->isDolbyHDR = 0;
#endif

	if (tm.h3dformat < TOTAL_3D && tm.h_act_len > 0 &&  tm.v_act_len > 0) {
		timing_info->full_3d_timing = mapping3dformat[tm.h3dformat];
	} else {
		timing_info->full_3d_timing = VFE_HDMI_3D_FORMAT_2D;
	}

	/* S2B will not use it */
	timing_info->video_lr_order = VFE_HDMI_3D_LR;
	if (tm.h_act_len > 0 &&  tm.v_act_len > 0)
		timing_info->vidoe_fmt = tm.hvf;
	else
		timing_info->vidoe_fmt = 0;

	timing_info->struct_3d = (vfe_hdmi_vsi_3d_structure_e) tm.h3dformat;
	/* for some timing is pixel repeat */
	timing_info->pixel_repeat = tm.pixel_repeat;

	timing_info->mode_table_index = tm.modetable_index;
	timing_info->mode_id = tm.mode_id;
//=============================================
// FOR RTK Timing info
//=============================================
	timing_info->hsync = tm.h_total;
	timing_info->vsync = tm.v_total;

	timing_info->mode_id = tm.mode_id;
	timing_info->mode_table_index = tm.modetable_index;

	timing_info->polarity = tm.polarity;

	timing_info->color_space  = newbase_hdmi_get_colorspace(port);
	timing_info->color_depth  = tm.colordepth;
	timing_info->color_imetry = tm.colorimetry;
	timing_info->IVSyncPulseCount = tm.IVSyncPulseCount;
//=============================================
// FOR RTK Timing info
//=============================================
#if 0
	printk(KERN_EMERG "[- HDMI TIMING]\n");
	printk(KERN_EMERG "==========================================\n");
	printk(KERN_EMERG "timing_info->h_freq	 = %d\n", timing_info->h_freq);
	printk(KERN_EMERG "timing_info->v_freq	 = %d\n", timing_info->v_freq);
	printk(KERN_EMERG "timing_info->h_total	 = %d\n", timing_info->h_total);
	printk(KERN_EMERG "timing_info->v_total	 = %d\n", timing_info->v_total);
	printk(KERN_EMERG "timing_info->active.x  = %d\n", timing_info->active.x);
	printk(KERN_EMERG "timing_info->active.y  = %d\n", timing_info->active.y);
	printk(KERN_EMERG "timing_info->active.w  = %d\n", timing_info->active.w);
	printk(KERN_EMERG "timing_info->active.h  = %d\n", timing_info->active.h);
	printk(KERN_EMERG "timing_info->scan_type = %d\n", timing_info->scan_type);
	printk(KERN_EMERG "timing_info->x_offset 		= %d\n", timing_info->x_offset);
	printk(KERN_EMERG "timing_info->y_offset 		= %d\n", timing_info->y_offset);
	printk(KERN_EMERG "timing_info->mode_id			= %d\n", timing_info->mode_id);
	printk(KERN_EMERG "timing_info->mode_table_index = %d\n", timing_info->mode_table_index);
	printk(KERN_EMERG "timing_info->polarity 		= %d\n", timing_info->polarity);
	printk(KERN_EMERG "timing_info->color_space		= %d\n", timing_info->color_space);
	printk(KERN_EMERG "timing_info->color_depth		= %d\n", timing_info->color_depth);
	printk(KERN_EMERG "timing_info->color_imetry 	= %d\n", timing_info->color_imetry);
	printk(KERN_EMERG "timing_info->full_3d_timing	= %d\n",
		timing_info->full_3d_timing);
	printk(KERN_EMERG "timing_info->vidoe_fmt(eVideoFormat) = %d\n",
		timing_info->vidoe_fmt);
	printk(KERN_EMERG "timing_info->struct_3d(e3DStructure) = %d\n",
		timing_info->struct_3d);
	printk(KERN_EMERG "==========================================\n");
#endif
#if 0//for debug timing data change
	if (Cmp_TiminginfoFrame(&tim_info_T,timing_info)  == FALSE)
	{
		HDMI_PRINTF("[ERROR] Cmp_TimingInfoFrame False\n");
	}
	memcpy(&tim_info_T,timing_info,sizeof(vfe_hdmi_timing_info_t));
#endif

	return HDMI_DRV_NO_ERR;
}

#if 0//for debug avi data change
bool Cmp_TiminginfoFrame(vfe_hdmi_timing_info_t *info_frameA,vfe_hdmi_timing_info_t *info_frameB)
{
	bool result =TRUE;
	if (info_frameA->h_freq != info_frameB->h_freq)
	{
		HDMI_PRINTF("C(1)\n");
		result= FALSE;
	}

	if (info_frameA->v_freq != info_frameB->v_freq)
	{
		HDMI_PRINTF("C(3)\n");
		result= FALSE;
	}
	if (info_frameA->h_total!= info_frameB->h_total)
	{
		HDMI_PRINTF("C(4)\n");
		result= FALSE;
	}
	if (info_frameA->v_total != info_frameB->v_total)
	{
		HDMI_PRINTF("C(5)\n");
		result= FALSE;
	}
	if (info_frameA->h_porch != info_frameB->h_porch)
	{
		HDMI_PRINTF("C(6)\n");
		result= FALSE;
	}
	if (info_frameA->active.x!= info_frameB->active.x)
	{
		HDMI_PRINTF("C(7)\n");
		result= FALSE;
	}
	
	if (info_frameA->active.y != info_frameB->active.y)
	{
		HDMI_PRINTF("C(8)\n");
		result= FALSE;
	}
	if (info_frameA->active.w != info_frameB->active.w)
	{
		HDMI_PRINTF("C(9)\n");
		result= FALSE;
	}
	if (info_frameA->active.h!= info_frameB->active.h)
	{
		HDMI_PRINTF("C(10)\n");
		result= FALSE;
	}
	if (info_frameA->scan_type != info_frameB->scan_type)
	{
		HDMI_PRINTF("C(11)\n");
		result= FALSE;
	}
	if (info_frameA->full_3d_timing != info_frameB->full_3d_timing)
	{
		HDMI_PRINTF("C(12)\n");
		result= FALSE;
	}
	if (info_frameA->video_lr_order!= info_frameB->video_lr_order)
	{
		HDMI_PRINTF("C(13)\n");
		result= FALSE;
	}
	if (info_frameA->vidoe_fmt != info_frameB->vidoe_fmt)
	{
		HDMI_PRINTF("C(14)\n");
		result= FALSE;
	}
	if (info_frameA->struct_3d != info_frameB->struct_3d)
	{
		HDMI_PRINTF("C(15)\n");
		result= FALSE;
	}
	if (info_frameA->mode_id != info_frameB->mode_id)
	{
		HDMI_PRINTF("C(16)\n");
		result= FALSE;
	}
	if (info_frameA->mode_table_index != info_frameB->mode_table_index) 
	{
		HDMI_PRINTF("C(17)\n");
		result= FALSE;
	}
	if (info_frameA->polarity != info_frameB->polarity)
	{
		HDMI_PRINTF("C(18)\n");
		result= FALSE;
	}
	if (info_frameA->color_space != info_frameB->color_space) 
	{
		HDMI_PRINTF("C(19)\n");
		result= FALSE;
	}
	if (info_frameA->color_depth != info_frameB->color_depth) 
	{
		HDMI_PRINTF("C(20)\n");
		result= FALSE;
	}
	if (info_frameA->color_imetry != info_frameB->color_imetry)	{
		HDMI_PRINTF("C(21)\n");
		result= FALSE;
	}

	return result;
}
#endif

int vfe_hdmi_drv_get_display_timing_info(vfe_hdmi_timing_info_t *timing_info, unsigned char vsc_ch)
{
	unsigned char port;
	HDMI_TIMING_T t1;
	printk(KERN_EMERG "[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (timing_info == NULL) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

#if BIST_PLUG_CABLE
	if (hdmi_in(DBG_FW_ADDR) & DBG_31_PLUG_CABLE_TEST)	return HDMI_DRV_STATE_ERR;
#endif

	if (!newbase_hdmi_get_timing(port, &t1))
	{
		return HDMI_DRV_STATE_ERR;
	}

	timing_info->x_offset = t1.h_act_sta;
	timing_info->y_offset = t1.v_act_sta;

#if HDMI_MEASURE_BY_SMART_FIT
	if (newbase_hdmi_get_hvstart(port, &t1, vsc_ch))
	{
		timing_info->x_offset = t1.h_act_sta;
		timing_info->y_offset = t1.v_act_sta;
	}
	else
	{
		return HDMI_DRV_HW_ERR;	/* Need to return fail */
	}
#endif //#ifdef HDMI_MEASURE_BY_SMART_FIT

	timing_info->h_freq = t1.h_freq;
#if HDMI_120HZ_SHORT_TIME_PATCH
	if((ABS(t1.h_act_len, 1920) < 10) && (ABS(t1.v_act_len, 1080) < 10))
	{
		if(t1.v_freq >= 900) // 1080P 100Hz
			t1.v_freq = 500;
		else if(t1.v_freq > 1100) // 1080P 120Hz
			t1.v_freq = 600;
	}
#endif //#if HDMI_120HZ_SHORT_TIME_PATCH
	timing_info->v_freq = t1.v_freq;

	timing_info->h_total = t1.h_total;
	timing_info->v_total = t1.v_total;

	timing_info->h_porch = t1.h_act_sta;
	timing_info->v_porch = t1.v_act_sta;

	timing_info->active.x = 0;
	timing_info->active.y = 0;
	timing_info->active.w = t1.h_act_len;
	timing_info->active.h = t1.v_act_len;

	timing_info->scan_type = !t1.is_interlace;

	if (t1.h3dformat < TOTAL_3D) {
		timing_info->full_3d_timing = mapping3dformat[t1.h3dformat];
	} else {
		timing_info->full_3d_timing = VFE_HDMI_3D_FORMAT_2D;
	}

	timing_info->vidoe_fmt = t1.hvf;

	timing_info->struct_3d = (vfe_hdmi_vsi_3d_structure_e) t1.h3dformat;

	timing_info->pixel_repeat = t1.pixel_repeat;//for some timing is pixel repeat
	// TODO : timing_info->video_lr_order

	timing_info->hsync = t1.h_total;
	timing_info->vsync = t1.v_total;

	timing_info->mode_id = t1.mode_id;
	timing_info->mode_table_index = t1.modetable_index;

	timing_info->polarity = t1.polarity;

	//timing_info->color_space  = t1.colorspace;
	timing_info->color_space  = newbase_hdmi_get_colorspace(port); //KTASKWBS-5744
	timing_info->color_depth  = t1.colordepth;
	timing_info->color_imetry = t1.colorimetry;
	timing_info->IVSyncPulseCount = t1.IVSyncPulseCount;

	//printk(KERN_EMERG "Timing=%dp%d\n", timing_info->active.h, timing_info->v_freq);


	pr_debug(KERN_INFO "[- HDMI TIMING]\n");
	pr_debug(KERN_INFO "==========================================\n");
	pr_debug(KERN_INFO "timing_info->h_freq    = %d\n", timing_info->h_freq);
	pr_debug(KERN_INFO "timing_info->v_freq    = %d\n", timing_info->v_freq);
	pr_debug(KERN_INFO "timing_info->h_total   = %d\n", timing_info->h_total);
	pr_debug(KERN_INFO "timing_info->v_total   = %d\n", timing_info->v_total);
	pr_debug(KERN_INFO "timing_info->active.x  = %d\n", timing_info->active.x);
	pr_debug(KERN_INFO "timing_info->active.y  = %d\n", timing_info->active.y);
	pr_debug(KERN_INFO "timing_info->active.w  = %d\n", timing_info->active.w);
	pr_debug(KERN_INFO "timing_info->active.h  = %d\n", timing_info->active.h);
	pr_debug(KERN_INFO "timing_info->scan_type = %d\n", timing_info->scan_type);
	pr_debug(KERN_INFO "timing_info->x_offset         = %d\n", timing_info->x_offset);
	pr_debug(KERN_INFO "timing_info->y_offset         = %d\n", timing_info->y_offset);
	pr_debug(KERN_INFO "timing_info->mode_id          = %d\n", timing_info->mode_id);
	pr_debug(KERN_INFO "timing_info->mode_table_index = %d\n", timing_info->mode_table_index);
	pr_debug(KERN_INFO "timing_info->polarity         = %d\n", timing_info->polarity);
	pr_debug(KERN_INFO "timing_info->color_space      = %d\n", timing_info->color_space);
	pr_debug(KERN_INFO "timing_info->color_depth      = %d\n", timing_info->color_depth);
	pr_debug(KERN_INFO "timing_info->color_imetry     = %d\n", timing_info->color_imetry);
	pr_debug(KERN_INFO "timing_info->full_3d_timing   = %d\n",
			 timing_info->full_3d_timing);
	pr_debug(KERN_INFO "timing_info->vidoe_fmt(eVideoFormat) = %d\n",
			 timing_info->vidoe_fmt);
	pr_debug(KERN_INFO "timing_info->struct_3d(e3DStructure) = %d\n",
			 timing_info->struct_3d);
	pr_debug(KERN_INFO "==========================================\n");

	return HDMI_DRV_NO_ERR;
}

void vfe_hdmi_drv_handle_on_line_measure_error(unsigned char vfe_call)
{
	unsigned char port;

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM)
	{
		pr_debug("[- ARG ERR]\n");
		return;
	}


	newbase_hdmi_audio_close(port);
	if (vfe_call) {
		newbase_hdmi_port_var_init(port);
		newbase_rxphy_force_clear_clk_st(port);
	} else {
		newbase_hdmi_reset_video_state(port);
	}
	newbase_hdmi_watchdog_apply(_DISABLE, HDMI_WD_ALL_COND);

#if HDMI_TOGGLE_HPD_Z0_ENABLE
	lib_hdmi_toggle_hpd_z0_check(port, _TRUE);
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

	HDMI_EMG("[%s %d] starts\n", __func__, __LINE__);

}

void vfe_hdmi_drv_adapter(void)
{
	pr_debug("[%s %d] starts\n", __func__, __LINE__);
	//RHAL_HDMI_ADAPT_EN();
}
int vfe_hdmi_drv_get_drm_info(vfe_hdmi_drm_t *info_frame)
{
	unsigned char port;
	HDMI_DRM_T drm_info;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM)
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_drm_t));
		HDMI_PRINTF("[WARNING1] drm_info forget to connect hdmi port\n");
		return HDMI_DRV_ARG_ERR;
	}

	if (newbase_hdmi_get_drm_infoframe(port, &drm_info))
	{
		memcpy(info_frame, &drm_info, sizeof(vfe_hdmi_drm_t));
	}
	else
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_drm_t));
	}

	if (hdmi_in(DEBUG_REG_ADDR)&_BIT18) {
		HDMI_EMG("[willychou] drm_info (eotf:%d, len:%d, ver:%d, x0:%d, y0:%d)\n",
			info_frame->eEOTFtype, info_frame->len, info_frame->ver, 
			info_frame->display_primaries_x0, info_frame->display_primaries_y0);
	}

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_port_vsi_info(vfe_hdmi_vsi_t *info_frame)
{
	HDMI_VSI_T vsi_info;

	unsigned char port;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (info_frame == NULL)		{
		pr_debug("[- ARG ERR] info_frame is NULL \n");
		return HDMI_DRV_ARG_ERR;
	}

	port = info_frame->port;

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM)
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_vsi_t));
		info_frame->port = port;
		pr_debug(KERN_INFO "[WARNING1] vsi_info forget to connect hdmi port\n");
		return HDMI_DRV_ARG_ERR;
	}

	if (newbase_hdmi_get_vs_infoframe(port, &vsi_info))
	{
		info_frame->header.type    = vsi_info.VSIF_TypeCode;
		info_frame->header.version = vsi_info.VSIF_Version;
		info_frame->header.length  = vsi_info.Length;
		memcpy(info_frame->ieee_reg_id, vsi_info.Reg_ID, VFE_HDMI_VENDOR_SPECIFIC_REGID_LEN);
		memcpy(info_frame->payload, vsi_info.Payload, VFE_HDMI_VENDOR_SPECIFIC_PAYLOAD_LEN) ;
		info_frame->vidoe_fmt = newbase_hdmi_get_video_format(port);
		info_frame->struct_3d = newbase_hdmi_get_3d_structure(port);
		info_frame->extdata_3d = lib_hdmi_get_3d_extdata(port);
		info_frame->vic = lib_hdmi_get_vsi_vic(port);;
		info_frame->packetStatus = VFE_HDMI_PACKET_STATUS_UPDATED;
	}
	else
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_vsi_t));
	}

	info_frame->port = port;

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_port_spd_info(vfe_hdmi_spd_t *info_frame)
{

	HDMI_SPD_T spd_info;
	unsigned char port;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (info_frame == NULL)		{
		pr_debug("[- ARG ERR] info_frame is NULL \n");
		return HDMI_DRV_ARG_ERR;
	}

	port = info_frame->port;

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM)
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_spd_t));
		info_frame->port = port;
		pr_debug(KERN_INFO "[WARNING1] vsi_info forget to connect hdmi port\n");
		return HDMI_DRV_ARG_ERR;
	}

	if (newbase_hdmi_get_spd_infoframe(port, &spd_info))
	{
		info_frame->header.type    = spd_info.type_code;
		info_frame->header.version = spd_info.ver;
		info_frame->header.length  = spd_info.len;
		memcpy(info_frame->vendor_name, spd_info.VendorName, 8);
		memcpy(info_frame->product_desc, spd_info.ProductDesc, 16);
		info_frame->src_dev_info   = spd_info.SourceInfo;
		info_frame->packetStatus   = VFE_HDMI_PACKET_STATUS_UPDATED;
	}
	else
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_spd_t));
	}

	info_frame->port = port;

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_port_avi_info(vfe_hdmi_avi_t *info_frame)
{

	HDMI_AVI_T avi_info;

#ifdef AVI_INFO_COMPARE
	static vfe_hdmi_avi_t avi_info_T;
#endif //#ifdef AVI_INFO_COMPARE

	unsigned char port;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (info_frame == NULL)		{
		pr_debug("[- ARG ERR] info_frame is NULL \n");
		return HDMI_DRV_ARG_ERR;
	}

	port = info_frame->port;

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM)
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_avi_t));
		info_frame->port = port;
		pr_debug(KERN_INFO "[WARNING1] av_info forget to connect hdmi port\n");
		return HDMI_DRV_ARG_ERR;
	}

	if (newbase_hdmi_get_avi_infoframe(port, &avi_info))
	{
		info_frame->header.type          = avi_info.type_code;
		info_frame->header.version       = avi_info.ver;
		info_frame->header.length        = avi_info.len;
		info_frame->mode                 = 1;
		info_frame->pixel_encoding       = (vfe_hdmi_avi_csc_e) avi_info.Y;
		info_frame->active_info          = (vfe_hdmi_avi_active_info_e) avi_info.A;
		info_frame->bar_info             = (vfe_hdmi_avi_bar_info_e) avi_info.B;
		info_frame->scan_info            = (vfe_hdmi_avi_scan_info_e) avi_info.S;
		info_frame->colorimetry          = (vfe_hdmi_avi_colorimetry_e) avi_info.C;
		info_frame->picture_aspect_ratio = (vfe_hdmi_avi_picture_arc_e) avi_info.M;

		info_frame->active_format_aspect_ratio = (vfe_hdmi_avi_active_format_arc_e) avi_info.R;
		info_frame->scaling                    = (vfe_hdmi_avi_scaling_e) avi_info.SC;
		info_frame->video_id_code              = (unsigned char) avi_info.VIC;
		info_frame->pixel_repeat               = avi_info.PR;
		info_frame->it_content                 = (vfe_hdmi_avi_it_content_e) avi_info.ITC;

		info_frame->extended_colorimetry   = (vfe_hdmi_avi_ext_colorimetry_e) avi_info.EC;
		info_frame->rgb_quantization_range = (vfe_hdmi_avi_rgb_quantization_range_e) avi_info.Q;
		info_frame->ycc_quantization_range = (vfe_hdmi_avi_ycc_quantization_range_e) avi_info.YQ;
		info_frame->content_type           = (vfe_hdmi_avi_content_type_e) avi_info.CN;
		//info_frame->it_content             = (vfe_hdmi_avi_it_content_e) avi_info.ITC;

		info_frame->TopBarEndLineNumber      = (avi_info.ETB15_08<<8 | avi_info.ETB07_00);
		info_frame->BottomBarStartLineNumber = (avi_info.SBB15_08<<8 | avi_info.SBB07_00);
		info_frame->LeftBarEndPixelNumber    = (avi_info.ELB15_08<<8 | avi_info.ELB07_00);
		info_frame->RightBarEndPixelNumber   = (avi_info.SRB15_08<<8 | avi_info.SRB07_00);
		info_frame->packetStatus             = VFE_HDMI_PACKET_STATUS_UPDATED;
	}
	else
	{
		memset(info_frame, 0, sizeof(vfe_hdmi_avi_t));

		//USER:Lewislee DATE:2016/10/05
		//if no avi info, it remain need send correct HDMI mode for webos
		if(newbase_hdmi_get_hdmi_mode_infoframe(port))
		{
			info_frame->mode                 = 1;
		}
	}
	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_17_PRINT_AVI)
	{
		pr_emerg("[AVI] header len = %d, PE = %s\n",info_frame->header.length,g_avi_csc_string_table[info_frame->pixel_encoding]);
		pr_emerg( "[AVI] AVI_ACTIVE_INFO = %d, bar_info = %s\n",info_frame->active_info, g_avi_bi_string_table[info_frame->bar_info]);
		pr_emerg("[AVI] scan_info = %s, colorimetry = %s\n",g_avi_scan_info_string_table[info_frame->scan_info], g_avi_colorimetry_string_table[info_frame->colorimetry]);
		pr_emerg("[AVI] picture_aspect_ratio = %s, active_format_aspect_ratio = %d\n",g_avi_arc_string_table[info_frame->picture_aspect_ratio], info_frame->active_format_aspect_ratio);
		pr_emerg("[AVI] scaling = %s, video_id_code = %d\n",g_avi_scaling_string_table[info_frame->scaling], info_frame->video_id_code);
		pr_emerg("[AVI] pixel_repeat = %d, it_content = %s\n",info_frame->pixel_repeat, g_avi_itcontent_string_table[info_frame->it_content]);
		pr_emerg("[AVI] extended_colorimetry = %s(%d), rgb_quantization_range = %s\n",g_avi_extcolorimetry_string_table[info_frame->extended_colorimetry],info_frame->extended_colorimetry,  g_avi_rgb_quantization_string_table[info_frame->rgb_quantization_range]);
		pr_emerg("[AVI] ycc_quantization_range = %s, content_type = %s\n",g_avi_ycc_quantization_string_table[info_frame->ycc_quantization_range], g_avi_content_type_string_table[info_frame->content_type]);
		pr_emerg("[AVI] TopBar=%d, BottomBar=%d, LeftBar=%d, RightBar=%d\n",info_frame->TopBarEndLineNumber, info_frame->BottomBarStartLineNumber, info_frame->LeftBarEndPixelNumber, info_frame->RightBarEndPixelNumber);
	}
	info_frame->port = port;

#ifdef AVI_INFO_COMPARE //for debug avi data change
	if (FALSE == Cmp_AviInfoFrame(&avi_info_T,info_frame))
	{
		HDMI_PRINTF(KERN_EMERG "[ERROR] Cmp_AviInfoFrame False\n");
	}

	memcpy(&avi_info_T,info_frame,sizeof(vfe_hdmi_avi_t));
#endif //#ifdef AVI_INFO_COMPARE

	return HDMI_DRV_NO_ERR;
}

#ifdef AVI_INFO_COMPARE //for debug avi data change
bool Cmp_AviInfoFrame(vfe_hdmi_avi_t *info_frameA,vfe_hdmi_avi_t *info_frameB)
{
	bool result =TRUE;
	if (info_frameA->header.type != info_frameB->header.type)
	{
		HDMI_PRINTF("C(1), A:%x, B:%x\n", info_frameA->header.type, info_frameB->header.type);
		result= FALSE;
	}

	if (info_frameA->mode != info_frameB->mode)
	{
		HDMI_PRINTF("C(3), A:%x, B:%x\n", info_frameA->mode, info_frameB->mode);
		result= FALSE;
	}

	if (info_frameA->pixel_encoding!= info_frameB->pixel_encoding)
	{
		HDMI_PRINTF("C(4), A:%x, B:%x\n", info_frameA->pixel_encoding, info_frameB->pixel_encoding);
		result= FALSE;
	}

	if (info_frameA->active_info != info_frameB->active_info)
	{
		HDMI_PRINTF("C(5), A:%x, B:%x\n", info_frameA->active_info, info_frameB->active_info);
		result= FALSE;
	}

	if (info_frameA->bar_info != info_frameB->bar_info)
	{
		HDMI_PRINTF("C(6), A:%x, B:%x\n", info_frameA->bar_info, info_frameB->bar_info);
		result= FALSE;
	}

	if (info_frameA->scan_info!= info_frameB->scan_info)
	{
		HDMI_PRINTF("C(7), A:%x, B:%x\n", info_frameA->scan_info, info_frameB->scan_info);
		result= FALSE;
	}

	if (info_frameA->colorimetry != info_frameB->colorimetry)
	{
		HDMI_PRINTF("C(8), A:%x, B:%x\n", info_frameA->colorimetry, info_frameB->colorimetry);
		result= FALSE;
	}

	if (info_frameA->picture_aspect_ratio != info_frameB->picture_aspect_ratio)
	{
		HDMI_PRINTF("C(9), A:%x, B:%x\n", info_frameA->picture_aspect_ratio, info_frameB->picture_aspect_ratio);
		result= FALSE;
	}

	if (info_frameA->active_format_aspect_ratio!= info_frameB->active_format_aspect_ratio)
	{
		HDMI_PRINTF("C(10), A:%x, B:%x\n", info_frameA->active_format_aspect_ratio, info_frameB->active_format_aspect_ratio);
		result= FALSE;
	}

	if (info_frameA->scaling != info_frameB->scaling)
	{
		HDMI_PRINTF("C(11), A:%x, B:%x\n", info_frameA->scaling, info_frameB->scaling);
		result= FALSE;
	}

	if (info_frameA->video_id_code != info_frameB->video_id_code)
	{
		HDMI_PRINTF("C(12), A:%x, B:%x\n", info_frameA->video_id_code, info_frameB->video_id_code);
		result= FALSE;
	}

	if (info_frameA->pixel_repeat!= info_frameB->pixel_repeat)
	{
		HDMI_PRINTF("C(13), A:%x, B:%x\n", info_frameA->pixel_repeat, info_frameB->pixel_repeat);
		result= FALSE;
	}

	if (info_frameA->it_content != info_frameB->it_content)
	{
		HDMI_PRINTF("C(14), A:%x, B:%x\n", info_frameA->it_content, info_frameB->it_content);
		result= FALSE;
	}

	if (info_frameA->extended_colorimetry != info_frameB->extended_colorimetry)
	{
		HDMI_PRINTF("C(15), A:%x, B:%x\n", info_frameA->extended_colorimetry, info_frameB->extended_colorimetry);
		result= FALSE;
	}

	if (info_frameA->rgb_quantization_range != info_frameB->rgb_quantization_range)
	{
		HDMI_PRINTF("C(16), A:%x, B:%x\n", info_frameA->rgb_quantization_range, info_frameB->rgb_quantization_range);
		result= FALSE;
	}

	if (info_frameA->ycc_quantization_range != info_frameB->ycc_quantization_range)
	{
		HDMI_PRINTF("C(17), A:%x, B:%x\n", info_frameA->ycc_quantization_range, info_frameB->ycc_quantization_range);
		result= FALSE;
	}

	if (info_frameA->content_type != info_frameB->content_type)
	{
		HDMI_PRINTF("C(18), A:%x, B:%x\n", info_frameA->content_type, info_frameB->content_type);
		result= FALSE;
	}

	if (info_frameA->TopBarEndLineNumber != info_frameB->TopBarEndLineNumber)
	{
		HDMI_PRINTF("C(19), A:%x, B:%x\n", info_frameA->TopBarEndLineNumber, info_frameB->TopBarEndLineNumber);
		result= FALSE;
	}

	if (info_frameA->BottomBarStartLineNumber != info_frameB->BottomBarStartLineNumber)
	{
		HDMI_PRINTF("C(20), A:%x, B:%x\n", info_frameA->BottomBarStartLineNumber, info_frameB->BottomBarStartLineNumber);
		result= FALSE;
	}

	if (info_frameA->LeftBarEndPixelNumber != info_frameB->LeftBarEndPixelNumber)
	{
		HDMI_PRINTF("C(21), A:%x, B:%x\n", info_frameA->LeftBarEndPixelNumber, info_frameB->LeftBarEndPixelNumber);
		result= FALSE;
	}

	if (info_frameA->TopBarEndLineNumber != info_frameB->TopBarEndLineNumber)
	{
		HDMI_PRINTF("C(22), A:%x, B:%x\n", info_frameA->TopBarEndLineNumber, info_frameB->TopBarEndLineNumber);
		result= FALSE;
	}

	if (info_frameA->RightBarEndPixelNumber != info_frameB->RightBarEndPixelNumber)
	{
		HDMI_PRINTF("C(23), A:%x, B:%x\n", info_frameA->RightBarEndPixelNumber, info_frameB->RightBarEndPixelNumber);
		result= FALSE;
	}

	if (info_frameA->packetStatus != info_frameB->packetStatus)
	{
		HDMI_PRINTF("C(24), A:%x, B:%x\n", info_frameA->packetStatus, info_frameB->packetStatus);
		result= FALSE;
	}

	if (info_frameA->header.length != info_frameB->header.length)
	{
		HDMI_PRINTF("C(2):(%d,%d)\n",info_frameA->header.length,info_frameB->header.length);
		result= FALSE;
	}
/*
	if(FALSE == result)
	{

		HDMI_PRINTF("header.type, A:%x, B:%x\n",info_frameA->header.type, info_frameB->header.type);
		HDMI_PRINTF("header.version, A:%x, B:%x\n",info_frameA->header.version, info_frameB->header.version);
		HDMI_PRINTF("header.length, A:%x, B:%x\n",info_frameA->header.length, info_frameB->header.length);
		HDMI_PRINTF("mode, A:%x, B:%x\n",info_frameA->mode, info_frameB->mode);
		HDMI_PRINTF("pixel_encoding, A:%x, B:%x\n",info_frameA->pixel_encoding, info_frameB->pixel_encoding);
		HDMI_PRINTF("active_info, A:%x, B:%x\n",info_frameA->active_info, info_frameB->active_info);
		HDMI_PRINTF("bar_info, A:%x, B:%x\n",info_frameA->bar_info, info_frameB->bar_info);
		HDMI_PRINTF("scan_info, A:%x, B:%x\n",info_frameA->scan_info, info_frameB->scan_info);
		HDMI_PRINTF("colorimetry, A:%x, B:%x\n",info_frameA->colorimetry, info_frameB->colorimetry);
		HDMI_PRINTF("picture_aspect_ratio, A:%x, B:%x\n",info_frameA->picture_aspect_ratio, info_frameB->picture_aspect_ratio);
		HDMI_PRINTF("active_format_aspect_ratio, A:%x, B:%x\n",info_frameA->active_format_aspect_ratio, info_frameB->active_format_aspect_ratio);
		HDMI_PRINTF("scaling, A:%x, B:%x\n",info_frameA->scaling, info_frameB->scaling);
		HDMI_PRINTF("video_id_code, A:%x, B:%x\n",info_frameA->video_id_code, info_frameB->video_id_code);
		HDMI_PRINTF("pixel_repeat, A:%x, B:%x\n",info_frameA->pixel_repeat, info_frameB->pixel_repeat);
		HDMI_PRINTF("it_content, A:%x, B:%x\n",info_frameA->it_content, info_frameB->it_content);
		HDMI_PRINTF("extended_colorimetry, A:%x, B:%x\n",info_frameA->extended_colorimetry, info_frameB->extended_colorimetry);
		HDMI_PRINTF("rgb_quantization_range, A:%x, B:%x\n",info_frameA->rgb_quantization_range, info_frameB->rgb_quantization_range);
		HDMI_PRINTF("it_content, A:%x, B:%x\n",info_frameA->it_content, info_frameB->it_content);
		HDMI_PRINTF("TopBarEndLineNumber, A:%x, B:%x\n",info_frameA->TopBarEndLineNumber, info_frameB->TopBarEndLineNumber);
		HDMI_PRINTF("BottomBarStartLineNumber, A:%x, B:%x\n",info_frameA->BottomBarStartLineNumber, info_frameB->BottomBarStartLineNumber);
		HDMI_PRINTF("LeftBarEndPixelNumber, A:%x, B:%x\n",info_frameA->LeftBarEndPixelNumber, info_frameB->LeftBarEndPixelNumber);
		HDMI_PRINTF("RightBarEndPixelNumber, A:%x, B:%x\n",info_frameA->RightBarEndPixelNumber, info_frameB->RightBarEndPixelNumber);
		HDMI_PRINTF("packetStatus, A:%x, B:%x\n",info_frameA->packetStatus, info_frameB->packetStatus);
		HDMI_PRINTF("port, A:%x, B:%x\n",info_frameA->port, info_frameB->port);
	}
*/
	return result;

}
#endif //#ifdef AVI_INFO_COMPARE

int vfe_hdmi_drv_get_port_allpacket_info(vfe_hdmi_all_packet_t *info_frame)
{
	unsigned char port;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}


	if ((info_frame == NULL)) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	memset(info_frame, 0, sizeof(vfe_hdmi_all_packet_t));

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug(KERN_INFO "[WARNING1] vfe_hdmi_all_packet_t forget to connect hdmi port\n");
		return HDMI_DRV_ARG_ERR;
	}

	if (newbase_hdmi_get_video_state(port) < MAIN_FSM_HDMI_MEASURE) {
		pr_debug( "[WARNING1] get_port_allpacket no data\n");
		return HDMI_DRV_NO_ERR;
	}

	if (vfe_hdmi_drv_get_port_avi_info(&info_frame->stAVI) != HDMI_DRV_NO_ERR) {
		//memset(&info_frame->stAVI, 0, sizeof(vfe_hdmi_avi_t));
		//info_frame->stAVI.packetStatus = VFE_HDMI_PACKET_STATUS_NOT_RECEIVED;
		info_frame->mode = info_frame->stAVI.mode;
	}

	if (vfe_hdmi_drv_get_port_spd_info(&info_frame->stSPD) != HDMI_DRV_NO_ERR) {
		//memset(&info_frame->stSPD, 0, sizeof(vfe_hdmi_spd_t));
		//info_frame->stSPD.packetStatus = VFE_HDMI_PACKET_STATUS_NOT_RECEIVED;
	}

	if (vfe_hdmi_drv_get_port_vsi_info(&info_frame->stVSI) != HDMI_DRV_NO_ERR) {
		//memset(&info_frame->stVSI, 0, sizeof(vfe_hdmi_vsi_t));
		//info_frame->stVSI.packetStatus = VFE_HDMI_PACKET_STATUS_NOT_RECEIVED;
	}

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_connection_state(vfe_hdmi_connect_state_t *con_state)
{
	if(newbase_hdmi_get_5v_state(con_state->port))
		con_state->state = 1;
	else
		con_state->state = 0;

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_enable_hpd(void)
{
	unsigned char i;
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (resume_hpd_control) {
		HDMI_PRINTF("need to ensure minimum hpd_low period.\n");
		resume_hpd_control = 0;
#if HDMI_STR_HPD_SPEED_UP_ENABLE
		//if CEC disable, It will pull HPD at power off/on
		if(1 == lib_hdmi_cec_is_enabled())
		{
		newbase_hdmi_hpd_delay_work_init();
		return HDMI_DRV_NO_ERR;
	}
#else //#if HDMI_STR_HPD_SPEED_UP_ENABLE
		newbase_hdmi_hpd_delay_work_init();
		return HDMI_DRV_NO_ERR;
#endif //#if HDMI_STR_HPD_SPEED_UP_ENABLE
	}

	for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++)
	{
		lib_hdmi_z0_set(i, LN_ALL, 1);   // Q10235 PS4 toggle HPD only, it causes noise
		newbase_hdmi_set_hpd(i, 1, 1);
	}

	return HDMI_DRV_NO_ERR;

}

int vfe_hdmi_drv_disable_hpd(void)
{
	unsigned char i;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++)
	{
		// Q10235 PS4 toggle HPD only, it causes noise
		if (newbase_hdmi_get_video_state(i) >= MAIN_FSM_HDMI_DISPLAY_ON) {
			lib_hdmi_z0_set(i, LN_ALL, 0);
		}
		newbase_hdmi_set_hpd(i, 0, 1);
	}

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_disable_internal_edid_access(unsigned char port)
{
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}
#if 0 //def HDMI_PORT_MUX
               if (port ==HDMI_RX_PORT_IDX_3)
               {
                        pr_notice("OLED model only 3 internal edid\n");
                        return HDMI_DRV_ARG_ERR;
               }
#endif

	newbase_hdmi_edid_enable(port, 0);

	return HDMI_DRV_NO_ERR;
}

/*------------------------------------------------------------------
 * Func :  vfe_hdmi_drv_read_edid
 *
 * Desc : Read EDID from a given HDMI channel
 *
 * Para : [IN] ch     : HDMI channel (0~N-1)
 *        [IN] p_edid : EDID data to be written
 *        [IN] len    : size of EDID data. the possible value of it is 256 & 512
 *
 * Retn :   0 : ok; others fail 
 *------------------------------------------------------------------*/
int vfe_hdmi_drv_read_edid(
	unsigned char           ch, 
	unsigned char*          p_edid, 
	unsigned short          len
	)
{
	unsigned char port = ch;

	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state == VFE_HDMI_DRV_SUSPEND_STATE) {
		HDMI_EMG("read edid of HDMI-%d failed, unable update edid in suspend state\n", ch);
		return HDMI_DRV_STATE_ERR;
	}

	if (p_edid==NULL || len!=256) 
	{
		HDMI_EMG("read edid of HDMI-%d failed, invalid parameter\n", ch);
		return HDMI_DRV_ARG_ERR;
	}
	
	if (hdmi_vfe_get_hdmi_port(ch, &port)<0) 
	{
		HDMI_EMG("write edid of HDMI-%d failed, get HDMI port failed\n", ch);
		return HDMI_DRV_ARG_ERR;
	}

	newbase_hdmi_read_edid(port, p_edid, len);

	return HDMI_DRV_NO_ERR;
}


/*------------------------------------------------------------------
 * Func : vfe_hdmi_drv_write_edid
 *
 * Desc : Write EDID to a given HDMI channel
 *
 * Para : [IN] ch     : HDMI channel (0~N-1)
 *        [IN] p_edid : EDID data to be written
 *        [IN] len    : size of EDID data. the possible value of it is 256 & 512
 *        [IN] flags  : controlling flags 
 *          APPLY_EDID_IMMEDIATELY : enable EDID immediately
 *
 * Retn :   0 : ok; others fail 
 *------------------------------------------------------------------*/ 
int vfe_hdmi_drv_write_edid(
	unsigned char           ch, 
	const unsigned char*          p_edid, 
	unsigned short          len, 
	unsigned long           flags
	)
{
	unsigned char port;
	unsigned char edid[256];

	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state == VFE_HDMI_DRV_SUSPEND_STATE) {
		HDMI_EMG("write edid of HDMI-%d failed, unable update edid in suspend state\n", ch);
		return HDMI_DRV_STATE_ERR;
	}
	
	if (p_edid==NULL || len!=256) 
	{
		HDMI_EMG("write edid of HDMI-%d failed, invalid parameter\n", ch);
		return HDMI_DRV_ARG_ERR;
	}

	if (hdmi_vfe_get_hdmi_port(ch, &port)<0) 
	{
		HDMI_EMG("write edid of HDMI-%d failed, get HDMI port failed\n", ch);
		return HDMI_DRV_ARG_ERR;
	}
		
	memcpy(edid, p_edid, 256);                    // copy edid for modification
	newbase_hdmi_check_hdmi_edid(edid + 128);   // update edid if necessary
	newbase_hdmi_save_edid(port, edid, 256);

	if ((flags & APPLY_EDID_IMMEDIATELY))
	{
		newbase_hdmi_write_edid(port, p_edid, 256);
		newbase_hdmi_edid_enable(port, 1);
	}
	else
	{
		HDMI_INFO("write edid of HDMI-%d without immedately apply\n", ch);
	}

	return HDMI_DRV_NO_ERR;
}


int vfe_hdmi_drv_read_hdcp(vfe_hdmi_hdcp_data_t *hdcp_data)
{
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if ((hdcp_data == NULL) ||
		(hdcp_data->pksv == NULL) ||
		(hdcp_data->pdevice_key == NULL)) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

	newbase_hdmi_read_hdcp14_key(hdcp_data->pksv, hdcp_data->pdevice_key);

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_write_hdcp(vfe_hdmi_hdcp_data_t hdcp_data)
{
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	newbase_hdmi_write_hdcp14_key(hdcp_data.pksv, hdcp_data.pdevice_key);

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_src_ksv_data(vfe_hdmi_ksv_data_t *ksv_data)
{
	unsigned char port;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if ((ksv_data == NULL) ||
		(ksv_data->pksv == NULL)) {
		pr_debug("[- ARG ERR] ksv_data is NULL \n");
		return HDMI_DRV_ARG_ERR;
	}

	port = ksv_data->port;

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

	if (g_hdmi_drv_port_use_connect_flag[port] == 0) {
		memset(ksv_data->pksv, 0, sizeof(HDCP_AKSV_SIZE_BYTES));
		pr_debug("[WARNING] forget to connect hdmi port %d\n", port);
	} else {
		newbase_hdmi_read_aksv(port, ksv_data->pksv);
		pr_debug("%s = %02x %02x %02x %02x %02x\n", __func__, ksv_data->pksv[0], ksv_data->pksv[1], ksv_data->pksv[2], ksv_data->pksv[3], ksv_data->pksv[4]);
	}

	ksv_data->port = port;

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_is_mhl_mode(void)
{
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return false;
	}


	return 0;
}

int vfe_hdmi_drv_send_msc_msg_cmd(vfe_hdmi_mhl_msc_msg_t msc_info)
{
	int ret = HDMI_DRV_NO_ERR;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}


	ret = HDMI_DRV_HW_ERR;

	return ret;
}

int vfe_hdmi_drv_send_msc_write_burst_cmd(vfe_hdmi_mhl_msc_write_burst_cmd_t msc_info)
{
	int ret = HDMI_DRV_NO_ERR;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	ret = HDMI_DRV_HW_ERR;

	return ret;
}

int vfe_hdmi_drv_read_msc_write_burst_cmd(vfe_hdmi_mhl_msc_write_burst_cmd_t *msc_info)
{
	int ret = HDMI_DRV_NO_ERR;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);


	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if ((msc_info == NULL) ||
	    (msc_info->pdata_bytes == NULL)) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

	ret = HDMI_DRV_HW_ERR;

	return ret;
}

unsigned char vfe_hdmi_drv_get_mhl_mode(unsigned char port)
{
	bool ret;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return false;
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR]\n");
		return false;
	}

	ret = false;

	return ret;
}

unsigned char vfe_hdmi_drv_get_clock_status(unsigned char port)
{
	bool ret=false;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR]\n");
		return false;
	}

	if (newbase_hdmi_get_video_state(port) >= MAIN_FSM_HDMI_DISPLAY_ON)
	{
		if (newbase_hdmi_get_tmds_clockx10(port) > 250)
			ret = true;
		else
			ret = false;
	}
	else
	{
		pr_debug("[%s]VIDEO_FSM not stable\n", __func__);
		ret = false;
	}

	return ret;
}

bool vfe_hdmi_drv_chk_is_rcp_msg(void)
{
	bool ret;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return false;
	}

	ret = false;

	return ret;
}

int vfe_hdmi_drv_get_msc_msg(vfe_hdmi_mhl_msc_msg_t *msc_info)
{
	int ret = HDMI_DRV_NO_ERR;
	pr_debug("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if (msc_info == NULL) {
		pr_debug("[- ARG ERR]\n");
		return false;
	}

	ret = HDMI_DRV_HW_ERR;

	return ret;
}

int vfe_hdmi_drv_get_audio_coding_type(unsigned char *coding_type)
{
	unsigned char tmp = 0;

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		*coding_type = VFE_HDMI_AUDIO_HDMI_NO_AUDIO;
		return HDMI_DRV_STATE_ERR;
	}

	if (newbase_hdmi_get_audio_coding_type(&tmp)) {

		pr_debug(KERN_INFO "[- AUDIO INFO] audio ct value = %d\n", tmp);

		switch (tmp) {
			case 1:
				*coding_type = VFE_HDMI_AUDIO_HDMI_PCM;
				break;
			case 2:
				*coding_type = VFE_HDMI_AUDIO_HDMI_AC3;
				break;
			case 3:
			case 5:
				*coding_type = VFE_HDMI_AUDIO_HDMI_MPEG;
				break;
			case 6:
				*coding_type = VFE_HDMI_AUDIO_HDMI_AAC;
				break;
			case 7:
				*coding_type = VFE_HDMI_AUDIO_HDMI_DTS;
				break;
			case 11:
				*coding_type = VFE_HDMI_AUDIO_HDMI_DTS_HD_MA;
				break;
			default:
				*coding_type = VFE_HDMI_AUDIO_HDMI_NO_AUDIO;
				break;
		}

		if (drvif_IsHDMI() == MODE_DVI) {
			*coding_type = VFE_HDMI_AUDIO_HDMI_DVI;
		}
	} else {
		*coding_type = VFE_HDMI_AUDIO_HDMI_NO_AUDIO;
	}

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_set_hpd_low_delay(unsigned int delay_timer)
{
	pr_debug("[%s] starts (delay=%d)\n", __func__, delay_timer);
	//newbase_hdmi_set_hpd_low_delay(delay_timer);
	return HDMI_DRV_NO_ERR;
}
bool vfe_hdmi_drv_get_avmute(void)
{
	unsigned char port;

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	if (port >= HDMI_RX_PORT_MAX_NUM) {
		pr_debug("[- ARG ERR]\n");
		return HDMI_DRV_ARG_ERR;
	}

	return newbase_hdmi_get_avmute(port);
}


int vfe_hdmi_drv_write_hdcp_apply(vfe_hdmi_hdcp_data_apply_t hdcp_data)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);
	unsigned char i;

	if(hdcp_data.apply)
	{
		#if 1
		//To Do
		if(hdcp_data.version==1)
		{
			newbase_hdmi_save_customer_hdcp2p2(hdcp_data.pksv, 878);
		}
		else if(hdcp_data.version==0)
		{
			newbase_hdmi_save_customer_hdcp1p4(hdcp_data.pksv, 325);
			newbase_hdmi_write_hdcp14_key(hdcp_data.pksv, hdcp_data.pksv+5);
			for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++) {
				lib_hdmi_hdcp14_enable(i,1);
			}
		}
		#endif

	}
	else
	{
		if(hdcp_data.version==1)
		{
			newbase_hdmi_save_customer_hdcp2p2(hdcp_data.pksv, 878);
		}
		else
		{
			newbase_hdmi_save_customer_hdcp1p4(hdcp_data.pksv, 325);
		}
	}

	return HDMI_DRV_NO_ERR;
}

char vfe_hdmi_drv_get_arc_channel(void)
{
    unsigned char ui_port;
	unsigned char arc_port_num=0;
	char arc_port = 0;
	HDMI_CHANNEL_T_PCB_INFO pcb_info;

	for (ui_port = 0; ui_port < HDMI_RX_PORT_MAX_NUM; ui_port++)
	{
		if (hdmi_vfe_get_rx_port_info(ui_port, &pcb_info)!=0)
		{
			pr_err("get_ARC_channel for port %d failed!\n",ui_port);
		}
		else
		{
			if (pcb_info.arc_support)
			{
				arc_port = ui_port;
				arc_port_num++;
			}
		}
	}

	if (arc_port_num==0)
		arc_port = NONE_ARC_PORT;
	else if (arc_port_num > 1)
		arc_port= MULTI_ARC_PORT;

	pr_err("get_ARC_channel = (%x)\n", arc_port);
	return arc_port;	
}

int vfe_hdmi_drv_get_rx_port_cnt(unsigned char* port_cnt)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	*port_cnt = HDMI_RX_PORT_MAX_NUM;

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_hdmi_support_version(vfe_hdmi_support_ver_t* hdmi_version)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		return HDMI_DRV_STATE_ERR;
	}

	hdmi_time_mesaure_start();

	if(hdmi_version->port < HDMI_RX_PORT_MAX_NUM)
	{
//		unsigned char hdmi_ver; // [bit 0] : HDMI 1.4, [Bit 1] : HDMI 2.0
#if HDMI2p0
		hdmi_version->hdmi_ver = 3;
#else //#if HDMI2p0
		hdmi_version->hdmi_ver = 1;
#endif //#if HDMI2p0
	}
	else //if(hdcp_ver->port >= HDMI_RX_PORT_MAX_NUM)
	{
		hdmi_version->hdmi_ver = 0;
	}

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_hdcp_version(vfe_hdmi_hdcp_ver_t* hdcp_version)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		return HDMI_DRV_STATE_ERR;
	}

	hdmi_time_mesaure_start();

	if(hdcp_version->port < HDMI_RX_PORT_MAX_NUM)
	{
		hdcp_version->hdcp_ver = newbase_hdcp_get_auth_mode(hdcp_version->port);
	}
	else //if(hdcp_ver->port >= HDMI_RX_PORT_MAX_NUM)
	{
		hdcp_version->hdcp_ver = NO_HDCP;
	}

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_set_hdcp_support(vfe_hdcp_table_t hdcp_support)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if(VFE_HDCP_1P4 == hdcp_support.hdcp_ver)
	{
		HDCP_key_loaded[VFE_HDCP_1P4] = hdcp_support.key_load;
	}
	else if(VFE_HDCP_2P2 == hdcp_support.hdcp_ver)
	{
		HDCP_key_loaded[VFE_HDCP_2P2] = hdcp_support.key_load;
	}

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_hdcp_support(vfe_hdcp_table_t* hdcp_support)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if(VFE_HDCP_1P4 == hdcp_support->hdcp_ver)
	{
		hdcp_support->key_load = HDCP_key_loaded[VFE_HDCP_1P4];
	}
	else if(VFE_HDCP_2P2 == hdcp_support->hdcp_ver)
	{
		hdcp_support->key_load = HDCP_key_loaded[VFE_HDCP_2P2];
	}
	else
	{
		hdcp_support->key_load = false;
	}

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_SetHDCPReceiverId(UINT8* ReceiverId)
{
	UINT8 i;

	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if(ReceiverId == NULL)
		return HDMI_DRV_STATE_ERR;

	for(i=0; i<HDCP_2P2_RECEIVER_ID_SIZE; i++)
		HDCP_2p2_ReceiverdId[i] = ReceiverId[i];

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_GetHDCPReceiverId(UINT8* ReceiverId)
{
	UINT8 i;

	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if(ReceiverId == NULL)
		return HDMI_DRV_STATE_ERR;

	for(i=0; i<HDCP_2P2_RECEIVER_ID_SIZE; i++)
		ReceiverId[i] = HDCP_2p2_ReceiverdId[i];

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}
int vfe_hdmi_drv_set_hpd(vfe_hdmi_hpd_t* hpd_value)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_debug("[- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return HDMI_DRV_STATE_ERR;
	}

	if(hpd_value->port >= HDMI_RX_PORT_MAX_NUM)
		return HDMI_DRV_STATE_ERR;

	if(hpd_value->hpd_ctl) {
		lib_hdmi_z0_set(hpd_value->port, LN_ALL, 1);   // Q10235 PS4 toggle HPD only, it causes noise
		newbase_hdmi_set_hpd(hpd_value->port, 1, 1);
	} else {
		lib_hdmi_z0_set(hpd_value->port, LN_ALL, 0);   // Q10235 PS4 toggle HPD only, it causes noise
		newbase_hdmi_set_hpd(hpd_value->port, 0, 1);
	}

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}

int vfe_hdmi_drv_get_logical_port(unsigned char* logical_port)
{
	unsigned char port;

	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	hdmi_time_mesaure_start();

	for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++)
	{
		if (g_hdmi_drv_port_use_connect_flag[port])
		{
			break;
		}
	}

	//If HDMI not connect, it will return HDMI_RX_PORT_MAX_NUM
	*logical_port = port;

	hdmi_time_mesaure_stop();

	return HDMI_DRV_NO_ERR;
}
#ifdef CONFIG_PM

extern void HDMI_set_detect_flag(unsigned char enable);
void vfe_hdmi_drv_suspend_afterDisconnectClose(void)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);
	unsigned char port;
	bool isConnet=FALSE;
	memset(&g_resume_param, 0, sizeof(hdmi_drv_resume_st));

	if (g_hdmi_drv_state == VFE_HDMI_DRV_SERVICE_STATE) {
		/*get which port is connect*/

		for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++) {
			if (g_hdmi_drv_port_use_connect_flag[port]) {
				g_resume_param.port = port;
				isConnet = TRUE;
			}
			//newbase_hdmi_set_hpd(port, 0, 1);
#if HDMI_STR_HPD_SPEED_UP_ENABLE
			if(0 == lib_hdmi_cec_is_enabled())
				newbase_hdmi_set_hpd(port, 0, 1);//pull low HPD
#endif//HDMI_STR_TOGGLE_HPD_ENABLE
		}

		/* STR ON, DC ON:
		ori  : lo->webos(hi)->resume_init(lo)->webos(hi)
		new: lo->resume_init(lo)->webos(hi)  */

		pr_debug("vfe_hdmi_drv_suspend SUS :%d\n",g_resume_param.port);
		//drvif_Hdmi_SetWebosSetHPD(FALSE);
		HDMI_ISR_THREAD(0);

		HDMI_INFOPKT_THREAD(0);
#if AUDIO_THREAD_MODIFY
		HDMI_AUDIO_THREAD(0);
#endif //#if AUDIO_THREAD_MODIFY

		newbase_hdmi_release_source(g_resume_param.port);

		hdmi_suspend_set_hotplug_flag=1;
		if(!isConnet)//g_hdmi_drv_port_use_connect_flag[0~4] is zero
		{
			g_resume_param.port =HDMI_RX_PORT_MAX_NUM;//for default value can't Zero,avoid resume port is 0 case
		}
	}
}
void vfe_hdmi_drv_suspend(void)
{
	pr_notice("[%s %d] starts\n", __func__, __LINE__);
	unsigned char port;
	bool isConnet=FALSE;
	memset(&g_resume_param, 0, sizeof(hdmi_drv_resume_st));

	if (g_hdmi_drv_state == VFE_HDMI_DRV_SERVICE_STATE) {
		/*get which port is connect*/

		for (port = 0; port < HDMI_RX_PORT_MAX_NUM; port++) {
			if (g_hdmi_drv_port_use_connect_flag[port]) {
				g_resume_param.port = port;
				isConnet=TRUE;
			}
			//newbase_hdmi_set_hpd(port, 0, 1);
#if HDMI_STR_HPD_SPEED_UP_ENABLE
			if(0 == lib_hdmi_cec_is_enabled())
				newbase_hdmi_set_hpd(port, 0, 1);//pull low HPD
#endif//HDMI_STR_TOGGLE_HPD_ENABLE
		}

		/* STR ON, DC ON:
		ori  : lo->webos(hi)->resume_init(lo)->webos(hi)
		new: lo->resume_init(lo)->webos(hi)  */

		pr_debug("vfe_hdmi_drv_suspend SUS :%d\n",g_resume_param.port);

		newbase_hdmi_uninit();
		newbase_hdmi_release_source(g_resume_param.port);
		if(!isConnet)//g_hdmi_drv_port_use_connect_flag[0~4] is zero
		{
			g_resume_param.port =HDMI_RX_PORT_MAX_NUM;//for default value can't Zero,avoid resume port is 0 case

		}
		#ifdef CONFIG_CUSTOMER_TV030
		//for (port = 0; port <HDMI_RX_PORT_MAX_NUM; port++)
		//	newbase_hdmi_set_hpd(port, 0, 1);  // Pull low the HotPlug here manually when STR OFF
		hdmi_suspend_set_hotplug_flag=1;
		#endif
	}

}
void vfe_hdmi_drv_resume_init(void)
{
	unsigned int i = 0;
	pr_notice("[%s %d] starts\n", __func__, __LINE__);

	//willychou add for SinaNoAP case
	//DC on ->PM suspend -> vfe_hdmi_drv_resume_init -> PM suspend -> vfe_hdmi_drv_resume_init crash
	if (g_hdmi_drv_state != VFE_HDMI_DRV_SERVICE_STATE) {
		pr_emerg("vfe_hdmi_drv_resume_init [- STATE ERR] fsm = %d\n", g_hdmi_drv_state);
		return ;
	}

	/*init*/
	newbase_hdmi_init();
	for(i = 0; i < HDMI_RX_PORT_MAX_NUM; i++)
	{
		g_hdmi_drv_port_use_connect_flag[i] = 0;
		newbase_hdmi_init_source(i);

#if HDMI_STR_TOGGLE_HPD_ENABLE
		if(HDMI_STR_HPD_TOGGLE_ENTER == lib_hdmi_get_str_toggle_hpd_state(i))
			lib_hdmi_set_str_toggle_hpd_state(i, HDMI_STR_HPD_TOGGLE_READY);
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE
	}

#if HDMI_STR_HPD_SPEED_UP_ENABLE
	// if CEC disable, newbase_hdmi_init_source() will enable hotplug
	if(1 == lib_hdmi_cec_is_enabled())
	{
		resume_hpd_control = 1;
		newbase_hdmi_hpd_delay_work_init();
	}
#else //#if HDMI_STR_HPD_SPEED_UP_ENABLE
	        resume_hpd_control = 1;
		newbase_hdmi_hpd_delay_work_init();
#endif //#if HDMI_STR_HPD_SPEED_UP_ENABLE
	hdmi_suspend_set_hotplug_flag=0;
}

void vfe_hdmi_drv_resume(void)
{
	HDMI_EMG("[%s %d] starts :%d \n", __func__, __LINE__,g_resume_param.port);

	if(g_resume_param.port < HDMI_RX_PORT_MAX_NUM)
		g_hdmi_drv_port_use_connect_flag[g_resume_param.port] = 1;
	//newbase_hdmi_hdr10_enable(_ENABLE);//Minchay@20160607-a add hdr10
}

void vfe_hdmi_drv_resume_std(void)
{
	unsigned int i = 0;
	pr_notice("[%s %d] starts\n", __func__, __LINE__);
	/*init*/
	newbase_hdmi_init();
	for(i = 0; i < HDMI_RX_PORT_MAX_NUM; i++)
	{                        
		g_hdmi_drv_port_use_connect_flag[i] = 0;
		newbase_hdmi_init_source(i);
	}

#if HDMI_STR_HPD_SPEED_UP_ENABLE
	// if CEC disable, newbase_hdmi_init_source() will enable hotplug
	if(1 == lib_hdmi_cec_is_enabled())
	{
		resume_hpd_control = 1;
		newbase_hdmi_hpd_delay_work_init();
	}
#else //#if HDMI_STR_HPD_SPEED_UP_ENABLE
	        resume_hpd_control = 1;
		newbase_hdmi_hpd_delay_work_init();
#endif //#if HDMI_STR_HPD_SPEED_UP_ENABLE

	pr_notice("[%s %d] starts :%d \n", __func__, __LINE__,g_resume_param.port);

	g_hdmi_drv_port_use_connect_flag[g_resume_param.port] = 1;
	newbase_hdmi_hdr10_enable(_ENABLE);//Minchay@20160607-a add hdr10
}

//USER:LewisLee DATE:2017/05/05
//Enable power, to prevent STD on, it had not call MHL module init
//The power had not enable
void vfe_hdmi_drv_resume_crt_setting(void)
{
#if MHL_SUPPORT
	CRT_CLK_OnOff(MHL, CLK_ON, NULL);

	rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, SYS_REG_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_mask | SYS_REG_INT_CTRL_SCPU_write_data(1));
#endif //#if MHL_SUPPORT
}

void vfe_hdmi_drv_suspend_no_connect_setting(void)
{
	g_resume_param.port =HDMI_RX_PORT_MAX_NUM;//for default value can't Zero,avoid resume port is 0 case
	
	if (VFE_HDMI_DRV_SERVICE_STATE != g_hdmi_drv_state)
		return;

	newbase_hdmi_uninit();
}
#endif /*CONFIG_PM*/


#if BIST_PLUG_CABLE

unsigned int bist_hdmi_detect_timing(unsigned char port)
{
	#define DETECT_LOOP 	150	//150*40 = 6000ms
	unsigned char det_cnt = 0;
	for (det_cnt=0; det_cnt<DETECT_LOOP; det_cnt++) {
		if (_MODE_SUCCESS == newbase_hdmi_detect_mode(port)) {
			return 1;
		}
		msleep(40);
	}
	return 0;
}

// -----------------------------------------------------------------------
//	bist_hdmi_cable_plug_test
// 	Simulate that unplug/plug cable, then perform testing, measure timing & compare
//
// -----------------------------------------------------------------------
unsigned int bist_hdmi_cable_plug_test(void)
{
#define PORT0 1
#define PORT1 0
#define PORT2 0
#define PORT3 1

#define HDMI_PRINTF_TEST(fmt, args...)			rtd_printk(KERN_EMERG, TAG_NAME_HDMI, fmt, ##args)

unsigned char i = 0;
unsigned char port_en[HDMI_RX_PORT_MAX_NUM] = {PORT0, PORT1, PORT2 };
HDMI_TIMING_T tm, prev_tm[HDMI_RX_PORT_MAX_NUM];

	while (hdmi_in(DBG_FW_ADDR) & DBG_31_PLUG_CABLE_TEST) {

		// unplug cable
		for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++) {
			lib_hdmi_z0_set(i, LN_ALL, 0);
			newbase_hdmi_set_hpd(i, 0, 1);
		}
		msleep(1500);

		// plug cable
		for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++) {
			lib_hdmi_z0_set(i, LN_ALL, 1);
			newbase_hdmi_set_hpd(i, 1, 1);
		}
		msleep(400);


		for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++) {

			if (!port_en[i]) continue;

			// detect for 6000ms
			if (bist_hdmi_detect_timing(i) && newbase_hdmi_get_timing(i, &tm)) {
				// ok! detected successfully
				HDMI_PRINTF_TEST("[P%d] %dx%d@%dHz\n", i, tm.h_act_len, tm.v_act_len, tm.v_freq);

				if (prev_tm[i].h_act_len != tm.h_act_len ||
					prev_tm[i].v_act_len != tm.v_act_len ||
					ABS(prev_tm[i].v_freq, tm.v_freq)>5 ) {

					prev_tm[i].h_act_len = tm.h_act_len ;
					prev_tm[i].v_act_len = tm.v_act_len ;
					prev_tm[i].v_freq = tm.v_freq ;
					HDMI_PRINTF_TEST("[P%d] Failed!!! Different with previous round\n", i);
				}

			} else {
				HDMI_PRINTF_TEST("[P%d] Detect Failed!!!\n", i);
			}
		}

		msleep(500);
	}

}
#endif
