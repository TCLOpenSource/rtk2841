/*
   comment
//20140930should fix rpc related part

*/
#include <linux/kernel.h>
#include <linux/semaphore.h>

#include <linux/string.h>
//#include <mach/io.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle_lib.h>
#include <tvscalercontrol/panel/panelapi.h>

#include <scalercommon/scalerCommon.h>

#include "tvscalercontrol/scalerdrv/scalerdrv.h"
#include <scalercommon/scalerDrvCommon.h>//rpc SCALERIOC_SENDPANELPARAMTERINFO

#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle.h>

#include <rbus/vodma_reg.h>

#include <tvscalercontrol/vo/rtk_vo.h>
#include "rbus/vodma2_reg.h"
#include <rbus/vgip_reg.h>
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <tvscalercontrol/scalerdrv/scaler_pst.h>
#include <rbus/mdomain_cap_reg.h>

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

static unsigned char need_send_panel_para_flag = TRUE;

static unsigned char enable_smooth_toggle_vo_changeratio[MAX_DISP_CHANNEL_NUM];

//---vopart
//static unsigned char enable_smooth_toggle_vo=0;
//static unsigned char enable_smooth_toggle_zoom_changeratio=0;//rika 20140829 added for tcl api
static unsigned int zoom_smoothtoggle_vo_hwid=0;//rika 20140919 added
static unsigned int zoom_smoothtoggle_vo_vlen=0;
static unsigned char zoom_reset_double_state[2]={_DISABLE};//rika20141125; for vo flow to disable double buffer later

//---other part
static UINT8 Scaler_FRC_Open_Fix_Lastline_DHtotal_Adjust_Enable_Flag = _DISABLE;
static unsigned char MainSubonPRFuc = FALSE;


//----define
#define printf											pr_debug
#define Rt_Sleep(mSec)					msleep(mSec)
#define Rt_Delay(mSec)					msleep(mSec)

#define ZOOM_SMOOTH_LIB_DEBUG

#ifdef ZOOM_SMOOTH_LIB_DEBUG
#define SLRLIB_PRINTF(format, args...) 		pr_debug(format, ##args)
#else
#define SLRLIB_PRINTF(format, args...)
#endif


void Set_send_panel_para_flag(unsigned char flag)
{
	need_send_panel_para_flag = flag;
}
//----
//----------begin of api
void Set_vo_smoothtoggle_changeratio_flag2(unsigned char enable, unsigned char display)
{
	/*
	   for fpp tcl api  : added by rika 20140714
	   */
	///enable_smooth_toggle_vo_changeratio=enable;//sirius version
	enable_smooth_toggle_vo_changeratio[display]=enable;

}
#if 0
void Set_zoom_smoothtoggle_changeratio_flag(unsigned char enable)
{
	/*
	   for fpp tcl api  : added by rika 20140829
	   to prevent memory reallocated
	   */
	enable_smooth_toggle_zoom_changeratio=enable;

}
unsigned char Get_zoom_smoothtoggle_changeratio_flag(void)
{
	/*
	   for fpp tcl api  : added by rika 20140829
	   to prevent  memory reallocated
	   */
	return	enable_smooth_toggle_zoom_changeratio;

}
#endif
void set_zoom_smoothtoggle_vo_hwid(unsigned int hwid)
{//added for tcl api
	zoom_smoothtoggle_vo_hwid=hwid;

}
unsigned int get_zoom_smoothtoggle_vo_hwid(unsigned char display)
{//added for tcl api
	if(zoom_smoothtoggle_vo_hwid)
	{
		return zoom_smoothtoggle_vo_hwid;
	}
	else
	{
		return Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_IPH_ACT_WID_PRE);
	}

}
void set_zoom_smoothtoggle_vo_vlen(unsigned int vlen)
{//added for tcl api
	zoom_smoothtoggle_vo_vlen=vlen;

}
unsigned int get_zoom_smoothtoggle_vo_vlen(unsigned char display)
{//added for tcl api
	if(zoom_smoothtoggle_vo_vlen)
	{
		return zoom_smoothtoggle_vo_vlen;
	}
	else
	{
		return Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_IPV_ACT_LEN_PRE);
	}
}

void clear_imd_smooth_toggle_clk_time2switch_en(unsigned char display)
{
	if(display==SLR_MAIN_DISPLAY){
		vgip_smooth_tog_ctrl_RBUS smooth_tog_ctrl_reg;
		smooth_tog_ctrl_reg.regValue = rtd_inl(VGIP_Smooth_tog_ctrl_reg);
		if(smooth_tog_ctrl_reg.main_imd_smooth_toggle_clk_time2switch_en){
			smooth_tog_ctrl_reg.main_imd_smooth_toggle_clk_time2switch_en = 0; // need reset this register when run scaler
			rtd_outl(VGIP_Smooth_tog_ctrl_reg,smooth_tog_ctrl_reg.regValue);
		}
	}
}

extern struct semaphore* get_double_buffer_semaphore(void);
void set_zoom_reset_double_state(unsigned char enable,unsigned char display)
{
	unsigned int plane = get_vo_plane_flag(display);
	zoom_reset_double_state[display]=enable;
	pr_debug("_rk reset display:%d zoom_double_state later:%d\n",display,zoom_reset_double_state[display]);
	if (enable == _DISABLE) {
		Check_smooth_toggle_update_flag(display);
	}
	if(enable == _DISABLE)
	{
		down(get_double_buffer_semaphore());
		if(display==SLR_MAIN_DISPLAY)
			imd_smooth_enable_main_double_buffer(FALSE);
		else
			imd_smooth_enable_sub_double_buffer(FALSE);
		up(get_double_buffer_semaphore());

		if(display==SLR_MAIN_DISPLAY)
			clear_imd_smooth_toggle_clk_time2switch_en(display);
	}

	if(Scaler_InputSrcGetType(display) == _SRC_VO)
	{
		if(VO_VIDEO_PLANE_V1 == plane)
		{
			vodma_vodma_smooth_toggle_1_RBUS vodma_smooth_toggle_reg;
			vodma_smooth_toggle_reg.regValue=rtd_inl(VODMA_VODMA_SMOOTH_TOGGLE_1_reg);
			if(enable==_DISABLE)
			{
				if(vodma_smooth_toggle_reg.smooth_en==1){
					vodma_smooth_toggle_reg.smooth_en=0;
					rtd_outl(VODMA_VODMA_SMOOTH_TOGGLE_1_reg,vodma_smooth_toggle_reg.regValue);
				}
			}
		}
		else if(VO_VIDEO_PLANE_V2 == plane)
		{
			vodma2_vodma2_smooth_toggle_1_RBUS vodma2_smooth_toggle_reg;
			vodma2_smooth_toggle_reg.regValue=rtd_inl(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg);
			if(enable==_DISABLE)
			{
				if(vodma2_smooth_toggle_reg.smooth_en==1){
					vodma2_smooth_toggle_reg.smooth_en=0;
					rtd_outl(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg,vodma2_smooth_toggle_reg.regValue);
				}
			}
		}
	}
}

unsigned char get_zoom_reset_double_state(unsigned char display)
{
	return zoom_reset_double_state[display];
 }

//other part

void set_mainsubonpr_fuc(unsigned char value)
{
	MainSubonPRFuc = value;
}

unsigned char get_mainsubonpr_fuc(void)
{
	return MainSubonPRFuc;
}
UINT8 Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag(void)
{
	return Scaler_FRC_Open_Fix_Lastline_DHtotal_Adjust_Enable_Flag;
}

void Scaler_Set_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag(UINT8 ucEnable)
{
	Scaler_FRC_Open_Fix_Lastline_DHtotal_Adjust_Enable_Flag = ucEnable;
}


// Check which VO is for the 2D main video
ENUM_TVD_INPUT_FORMAT Scaler_Get_2D_VodmaIndex(void)
{//fix me rika 20141022
	ENUM_TVD_INPUT_FORMAT inPutFmt=TVD_INFMT_VODMA0;

	// [Magellan] VO output select
	//  - VODMA2: for 2D video output(DTV/Playback/Photo)
	//  - VODMA1: for 3D video or PIP application

	// change this VO index define need update CVideoOutFilter::SetVideoOutLayer() too.
#if defined(IS_MAGELLAN_ONLY) && defined(ENABLE_DRIVER_I3DDMA) // VO1 for scaler 3D
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE())
	{
		static unsigned char lastInPutFmt=0;
#ifdef ENABLE_USE_VO_UZU // [VO UZU] VO in VO1 for UZU funciton (bypass IDMA)
		if(Scaler_Get_forceEnable_VO_UZU())
			inPutFmt = TVD_INFMT_VODMA0;
		else
#endif
			inPutFmt = TVD_INFMT_VODMA1;

		if(inPutFmt != lastInPutFmt)
			printf("[VO] Force to VO Plane[%d]\n", (inPutFmt == TVD_INFMT_VODMA1? 1: 0));
		lastInPutFmt = inPutFmt;
	}
#endif

	return inPutFmt;
}

// Check which VO is for the 2D main video
VO_VIDEO_PLANE Scaler_Get_2D_VoPlane(void)
{//fix me rika 20141022
	if(Scaler_Get_2D_VodmaIndex() == TVD_INFMT_VODMA1)
		return VO_VIDEO_PLANE_V2;
	else
		return VO_VIDEO_PLANE_V1;
}


// Check which VO is for the 2D main video
VO_VIDEO_PLANE Scaler_Get_3D_VoPlane(void)
{ //fix me rika 20141022
	return VO_VIDEO_PLANE_V1;
}

SOURCE_INFO_SMOOTH_TOGGLE vo_source_state_smooth_toggle[MAX_DISP_CHANNEL_NUM];
static unsigned char enable_smooth_toggle_vo_timing_change[MAX_DISP_CHANNEL_NUM];
DISPLAY_DATA_SMOOTH_TOGGLE vo_source_force_data_mode[MAX_DISP_CHANNEL_NUM];
//static unsigned char vo_smooth_toggle_start_scaler;
void Set_direct_vo_smoothtoggle_enable(unsigned char enable,DISPLAY_DATA_SMOOTH_TOGGLE data_pach, unsigned char display,unsigned char plane)
{
#ifndef CONFIG_DUAL_CHANNEL
	display=SLR_MAIN_DISPLAY;
#endif
//	unsigned int plane = get_vo_plane_flag(display);

	if(enable)
	{
		vo_force_data_mode_set_enable(data_pach, display);
		vo_smoothtoggle_memory_alloc(display);
		enable_smooth_toggle_vo_timing_change[display]=enable;
		pr_debug("Set_direct_vo_smoothtoggle_start=true\n");
#ifdef NEW_FLL_METHOD
		//When video playback preview, it may cause fll unlock when change file;
		// so we disable fll check under this case.
		// It can enable again, when display on finish.
		framesync_new_fixlastline_threashold_check_enable(0);
#endif
		set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_INIT, display,plane);
		panel_parameter_send_info();
	}
	else
	{
		enable_smooth_toggle_vo_timing_change[display]=enable;
		pr_debug("close vo timing change smooth toggle \n");
		set_vo_open_smooth_toggle_enable(0,display);
		set_vo_run_smooth_toggle_enable(0,display);
		set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_NONE, display,plane);
		smooth_toggle_state_info_rpc(display);
		clear_imd_smooth_toggle_clk_time2switch_en(display);
		if(VO_VIDEO_PLANE_V1 == plane)
		{
			vodma_vodma_smooth_toggle_1_RBUS vodma_smooth_toggle_reg;
			vodma_smooth_toggle_reg.regValue=IoReg_Read32(VODMA_VODMA_SMOOTH_TOGGLE_1_reg);
			if(vodma_smooth_toggle_reg.smooth_en==1)
			{
				vodma_smooth_toggle_reg.smooth_en=0;
				IoReg_Write32(VODMA_VODMA_SMOOTH_TOGGLE_1_reg,vodma_smooth_toggle_reg.regValue);
			}
		}
		else if(VO_VIDEO_PLANE_V2 == plane)
		{
			vodma2_vodma2_smooth_toggle_1_RBUS vodma2_smooth_toggle_reg;
			vodma2_smooth_toggle_reg.regValue=IoReg_Read32(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg);
			if(vodma2_smooth_toggle_reg.smooth_en==1)
			{
				vodma2_smooth_toggle_reg.smooth_en=0;
				IoReg_Write32(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg,vodma2_smooth_toggle_reg.regValue);
			}
		}

		vo_force_data_mode_set_enable(SLR_DISPLAY_DEFAULT, display);
	}
}
#if 0
void Set_direct_vo_stop_smoothtoggle(void)
{
	enable_smooth_toggle_vo_timing_change[SLR_MAIN_DISPLAY]=_DISABLE;
	set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_NONE,SLR_MAIN_DISPLAY);
	vo_source_force_data_mode[SLR_MAIN_DISPLAY]=SLR_DISPLAY_DEFAULT;
#ifdef CONFIG_DUAL_CHANNEL
	enable_smooth_toggle_vo_timing_change[SLR_SUB_DISPLAY]=_DISABLE;
	set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_NONE,SLR_SUB_DISPLAY);
	vo_source_force_data_mode[SLR_SUB_DISPLAY]=SLR_DISPLAY_DEFAULT;
#endif
	printk("Set_direct_vo_stop_smoothtoggle\n");
	zoom_setcropflag(TRUE);
	zoom_setcropflag(TRUE);
}
#endif
#if 0
void Set_vo_smoothtoggle_timingchange_flag(unsigned char enable)
{
	//	pthread_mutex_lock(&scalerMutex);
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	vodma_vodma_smooth_toggle_1_RBUS vodma_smooth_toggle_reg;

	if(enable &&(!Get_vo_smoothtoggle_changeratio_flag()))
	{
		vo_smoothtoggle_memory_alloc();
		Set_vo_smoothtoggle_scaler_enable(TRUE);
	}
	enable_smooth_toggle_vo_timing_change=enable;
	if(_DISABLE==enable)
	{
		int ret = 0;
		SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode2();
		StructSrcRect dispwin=Scaler_DispWindowGet();
		VO_Scaler_State scaler_info;
		scaler_info.type=(unsigned int)ratio_type;
		scaler_info.state=(unsigned int)SLR_SMOOTH_TOGGLE_RELEASE;
		scaler_info.srcx=(unsigned int)dispwin.srcx;
		scaler_info.srcy=(unsigned int)dispwin.srcy;
		scaler_info.src_wid=(unsigned int)dispwin.src_wid;
		scaler_info.src_height=(unsigned int)dispwin.src_height;
		scaler_info.vo_3d_mode=0;

		pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDSMOOTHTOGGLESTATE);
		ulCount = sizeof(VO_Scaler_State) / sizeof(unsigned int);

		// copy to RPC share memory
		memcpy(pulDataTemp, &scaler_info, sizeof(VO_Scaler_State));

		for (i = 0; i < ulCount; i++)
			pulDataTemp[i] = Scaler_ChangeUINT32Endian(pulDataTemp[i]);

		if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDSMOOTHTOGGLESTATE,0,0)))
		{
			printk("ret=%d, send VO's scaler state to driver fail !!!\n", ret);
		}
		printk("close vo timing change smooth toggle \n");

		vodma_smooth_toggle_reg.regValue=IoReg_Read32(VODMA_VODMA_SMOOTH_TOGGLE_1_reg);
		vodma_smooth_toggle_reg.smooth_en=0;
		IoReg_Write32(VODMA_VODMA_SMOOTH_TOGGLE_1_reg,vodma_smooth_toggle_reg.regValue);
		//	drv_imd_smooth_enable_double_buffer(FALSE);
		set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_NONE);
		if((vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FRAME_SYNC)||(vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FS_NO_MEMORY)
				||(vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FS_AND_CUSTOM_MODE))
		{
			//		drvif_force_scaler_data_fs_voFrameRateControl(_DISP_2D,0,1);
		}
		else
		{
			//		drvif_scaler2d_force_voFrameRateControl_lowbound(_DISP_2D,0,1);
		}
		Set_vo_smoothtoggle_scaler_enable(FALSE);
	}
	else
	{
		printf("Set_vo_smoothtoggle_timingchange_flag=true\n");
#ifdef NEW_FLL_METHOD
		//When video playback preview, it may cause fll unlock when change file;
		// so we disable fll check under this case.
		// It can enable again, when display on finish.
		framesync_new_fixlastline_threashold_check_enable(0);
#endif
		set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_INIT);
		smooth_toggle_state_info_rpc();
		if(!Get_vo_smoothtoggle_changeratio_flag())
		{
			panel_parameter_send_info();
		}
#ifdef RUN_ON_TVBOX
		if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX)
		{

		}
#else
		if((vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FRAME_SYNC)||(vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FS_NO_MEMORY)
				||(vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FS_AND_CUSTOM_MODE))
		{
			//		drvif_force_scaler_data_fs_voFrameRateControl(_DISP_2D,1,1);
		}
		else
		{
			//		drvif_scaler2d_force_voFrameRateControl_lowbound(_DISP_2D,1,1);
		}
#endif
	}
	//	pthread_mutex_unlock(&scalerMutex);
}
#endif
unsigned char Get_vo_smoothtoggle_timingchange_flag(unsigned char display)
{
	return enable_smooth_toggle_vo_timing_change[display];
}
#if 0
void Set_vo_smoothtoggle_changeratio_flag(unsigned char enable)
{
	//	pthread_mutex_lock(&scalerMutex);
	int ret = 0;
	SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode2();
	StructSrcRect dispwin=Scaler_DispWindowGet();
	VO_Scaler_State scaler_info;
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	vodma_vodma_smooth_toggle_1_RBUS vodma_smooth_toggle_reg;
	if(enable &&(!Get_vo_smoothtoggle_timingchange_flag()))
	{
		vo_smoothtoggle_memory_alloc();
	}
	enable_smooth_toggle_vo_changeratio=enable;

	if(_DISABLE==enable)
	{
		scaler_info.type=(unsigned int)ratio_type;
		scaler_info.state=(unsigned int)SLR_SMOOTH_TOGGLE_RELEASE;
		scaler_info.srcx=(unsigned int)dispwin.srcx;
		scaler_info.srcy=(unsigned int)dispwin.srcy;
		scaler_info.src_wid=(unsigned int)dispwin.src_wid;
		scaler_info.src_height=(unsigned int)dispwin.src_height;
		scaler_info.vo_3d_mode=0;

		pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDSMOOTHTOGGLESTATE);
		ulCount = sizeof(VO_Scaler_State) / sizeof(unsigned int);

		// copy to RPC share memory
		memcpy(pulDataTemp, &scaler_info, sizeof(VO_Scaler_State));

		for (i = 0; i < ulCount; i++)
			pulDataTemp[i] = htonl(pulDataTemp[i]);

		if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDSMOOTHTOGGLESTATE,0,0)))
		{
			printk("ret=%d, send VO's scaler state to driver fail !!!\n", ret);
		}

		printk("close vo smooth toggle \n");
		vodma_smooth_toggle_reg.regValue=IoReg_Read32(VODMA_VODMA_SMOOTH_TOGGLE_1_reg);
		vodma_smooth_toggle_reg.smooth_en=0;
		IoReg_Write32(VODMA_VODMA_SMOOTH_TOGGLE_1_reg,vodma_smooth_toggle_reg.regValue);
		set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_NONE);
	}
	else
	{
		set_vo_smoothtoggle_state(SLR_SMOOTH_TOGGLE_INIT);
		if(!Get_vo_smoothtoggle_timingchange_flag())
		{
			panel_parameter_send_info();
		}
	}
	//	pthread_mutex_unlock(&scalerMutex);
}
#endif
unsigned char Get_vo_smoothtoggle_changeratio_flag(unsigned char display)
{
	return enable_smooth_toggle_vo_changeratio[display];
}
#if 0
unsigned char Get_vo_smoothtoggle_scaler_enable(void)
{
	return vo_smooth_toggle_start_scaler;
}
void Set_vo_smoothtoggle_scaler_enable(unsigned char enable)
{
	vo_smooth_toggle_start_scaler=enable;
}
#endif

void set_vo_smoothtoggle_state(SOURCE_INFO_SMOOTH_TOGGLE state, unsigned char display,unsigned char plane)
{
#ifndef CONFIG_DUAL_CHANNEL
	display=SLR_MAIN_DISPLAY;
#endif
//	unsigned int plane = get_vo_plane_flag(display);
	vo_source_state_smooth_toggle[display] = state;
	if(VO_VIDEO_PLANE_V1 == plane)
	{
		vodma_vodma_smooth_toggle_1_RBUS vodma_smooth_toggle_reg;
		vodma_vodma_pvs_free_RBUS vodma_pvs_free_reg;
		vodma_pvs_free_reg.regValue = rtd_inl(VODMA_VODMA_PVS_Free_reg);
		vodma_smooth_toggle_reg.regValue = rtd_inl(VODMA_VODMA_SMOOTH_TOGGLE_1_reg);
		if (vo_source_state_smooth_toggle[display] != SLR_SMOOTH_TOGGLE_ACTIVE) {
			down(get_double_buffer_semaphore());
		#ifdef CONFIG_DUAL_CHANNEL
			if (display) {
				imd_smooth_enable_sub_double_buffer(FALSE);
			} else
		#endif
			{
				imd_smooth_enable_main_double_buffer(FALSE);
				clear_imd_smooth_toggle_clk_time2switch_en(display);
			}
			up(get_double_buffer_semaphore());

			if (vodma_smooth_toggle_reg.smooth_en == 1) {
				vodma_smooth_toggle_reg.smooth_en = 0;
				rtd_outl(VODMA_VODMA_SMOOTH_TOGGLE_1_reg, vodma_smooth_toggle_reg.regValue);
				vodma_pvs_free_reg.pvs0_free_period_update = 0;
				rtd_outl(VODMA_VODMA_PVS_Free_reg, vodma_pvs_free_reg.regValue);
			}
		}
	}
	else if(VO_VIDEO_PLANE_V2 == plane)
	{
		vodma2_vodma2_smooth_toggle_1_RBUS vodma2_smooth_toggle_reg;
		vodma2_vodma2_pvs_free_RBUS vodma2_pvs_free_reg;
		vodma2_pvs_free_reg.regValue = rtd_inl(VODMA2_VODMA2_PVS_Free_reg);
		vodma2_smooth_toggle_reg.regValue = rtd_inl(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg);
		if (vo_source_state_smooth_toggle[display] != SLR_SMOOTH_TOGGLE_ACTIVE) {
			down(get_double_buffer_semaphore());
		#ifdef CONFIG_DUAL_CHANNEL
			if (display) {
				imd_smooth_enable_sub_double_buffer(FALSE);
			} else
		#endif
			{
				imd_smooth_enable_main_double_buffer(FALSE);
				clear_imd_smooth_toggle_clk_time2switch_en(display);
			}
			up(get_double_buffer_semaphore());
			if (vodma2_smooth_toggle_reg.smooth_en == 1) {
				vodma2_smooth_toggle_reg.smooth_en = 0;
				rtd_outl(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg, vodma2_smooth_toggle_reg.regValue);
				vodma2_pvs_free_reg.pvs0_free_period_update = 0;
				rtd_outl(VODMA2_VODMA2_PVS_Free_reg, vodma2_pvs_free_reg.regValue);
			}
		}
	}
}
SOURCE_INFO_SMOOTH_TOGGLE get_vo_smoothtoggle_state(unsigned char display)
{
	return vo_source_state_smooth_toggle[display];
}
void vo_force_data_mode_set_enable(DISPLAY_DATA_SMOOTH_TOGGLE enable, unsigned char display)
{
#ifndef CONFIG_DUAL_CHANNEL
	display = SLR_MAIN_DISPLAY;
#endif
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	SMOOTH_TOGGLE_DATA_MODE data_mode_info={display,enable};
	int ret = 0;
	vo_source_force_data_mode[display] = enable;

	pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDSCALERDATAMODE);
	ulCount = sizeof(SMOOTH_TOGGLE_DATA_MODE) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulDataTemp, &data_mode_info, sizeof(SMOOTH_TOGGLE_DATA_MODE));

	for (i = 0; i < ulCount; i++)
		pulDataTemp[i] = htonl(pulDataTemp[i]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDSCALERDATAMODE,0,0)))
		pr_debug( "ret=%d, send SCALERIOC_SENDSCALERDATAMODE to driver fail !!!\n", ret );
	pr_debug("vo_force_data_mode_set_enable[display:%d]=%d\n",display,enable);
}
DISPLAY_DATA_SMOOTH_TOGGLE vo_force_data_mode_get_enable(unsigned char display)
{
	return vo_source_force_data_mode[display];
}
void Smoothtoggle_sendVOupdate_flag(VO_VIDEO_PLANE plane,unsigned char flag)
{
	if(flag==FALSE)
	{
		unsigned int *pulDataTemp = NULL;
		unsigned int ulCount = 0, i = 0;
		int ret = 0;
		SMOOTH_TOGGLE_UPDATE_PLANE_INFO update_plane_info={flag,plane};
		pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDSMOOTHTOGGLEUPDATEFLAG);
		ulCount = sizeof(SMOOTH_TOGGLE_UPDATE_PLANE_INFO) / sizeof(unsigned int);
		// copy to RPC share memory
		memcpy(pulDataTemp, &update_plane_info, sizeof(SMOOTH_TOGGLE_UPDATE_PLANE_INFO));

		for (i = 0; i < ulCount; i++)
			pulDataTemp[i] = htonl(pulDataTemp[i]);

		if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDSMOOTHTOGGLEUPDATEFLAG,0,0)))
			pr_debug( "ret=%d, send Smoothtoggle_sendvoupdate_flag to driver fail !!!\n", ret );
		//	printk("Smoothtoggle_sendvoupdate_flag=%d\n",flag);
	}
}

void vgip_ratio_send_info(unsigned char hratio,unsigned char vratio,short h_start,short h_width,short v_start,short v_length )
{
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	int ret = 0;
	VGIP_Overscan_INFO vgip_ratio={(int)hratio,(int)vratio,(int)h_start,(int)h_width,(int)v_start,(int)v_length,(int)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)};
	pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDVGIPRATIO);
	ulCount = sizeof(VGIP_Overscan_INFO) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulDataTemp, &vgip_ratio, sizeof(VGIP_Overscan_INFO));

	for (i = 0; i < ulCount; i++)
		pulDataTemp[i] = htonl(pulDataTemp[i]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDVGIPRATIO,0,0)))
	{
		pr_debug("ret=%d, SCALERIOC_SENDVGIPRATIO to driver fail !!!\n", ret);
	}
}
void panel_parameter_send_info(void)
{
	Panel_Parameter_INFO parameter_info;
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	int ret = 0;
	if(!need_send_panel_para_flag) {//No need to send parameter again
		pr_debug("No need to send panel parameter!!!\n");
		return;
	} else {
		need_send_panel_para_flag = FALSE;
	}
	parameter_info.disp_h_total=Get_DISP_HORIZONTAL_TOTAL();
	parameter_info.disp_v_total=Get_DISP_VERTICAL_TOTAL();
	parameter_info.disp_clock_max=Get_DISPLAY_CLOCK_MAX();
	parameter_info.disp_clock_min=Get_DISPLAY_CLOCK_MIN();
	parameter_info.disp_clock_typical=Get_DISPLAY_CLOCK_TYPICAL();
	parameter_info.disp_ratio_4x3=Get_DISPLAY_RATIO_4X3();
	parameter_info.disp_den_start_vpos=Get_DISP_DEN_STA_VPOS();
	parameter_info.disp_act_start_vpos=Get_DISP_ACT_STA_VPOS();
	parameter_info.disp_act_end_vpos=Get_DISP_ACT_END_VPOS();
	parameter_info.disp_act_start_hpos=Get_DISP_ACT_STA_HPOS();
	parameter_info.disp_act_end_hpos=Get_DISP_ACT_END_HPOS();
	parameter_info.panel_custom_index=Get_DISPLAY_PANEL_CUSTOM_INDEX();
	parameter_info.panel_type=Get_DISPLAY_PANEL_TYPE();
	parameter_info.DISPLAY_PORT =Get_DISPLAY_PORT();
	parameter_info.DISPLAY_REFRESH_RATE =Get_DISPLAY_REFRESH_RATE();
	parameter_info.panel_support_3d_display=Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE();
	parameter_info.panel_3d_line_alternative_support=Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE();
	parameter_info.panel_3d_PR_outout_LR_swap=Get_PANEL_3D_PR_OUTPUT_LR_SWAP();
	parameter_info.panel_3d_SG_output_120HZ=Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE();
	parameter_info.panel_3d_SG_24HZ_output_FHD=Get_PANEL_3D_SG_24HZ_OUTPUT_FHD_ENABLE();
	parameter_info.panel_3d_PR_to_SG_output_FRC=Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE();
	parameter_info.lvds_converter_to_HDMI=0;
	parameter_info.panel_vflip = Get_PANEL_VFLIP_ENABLE();

	pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDPANELPARAMTERINFO);
	ulCount = sizeof(Panel_Parameter_INFO) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulDataTemp, &parameter_info, sizeof(Panel_Parameter_INFO));

	for (i = 0; i < ulCount; i++)
		pulDataTemp[i] = htonl(pulDataTemp[i]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDPANELPARAMTERINFO,0,0)))
	{
		pr_debug("ret=%d, SCALERIOC_SENDPANELPARAMTERINFO to driver fail !!!\n", ret);
	}
}

void smooth_toggle_state_info_rpc(unsigned char display)
{
	int ret = 0;
	SLR_RATIO_TYPE ratio_type = Scaler_DispGetRatioMode2();
	StructSrcRect dispwin=Scaler_DispWindowGet();
	StructSrcRect overscan_size = Scaler_AdaptiveStream_InputWindowGet();
	VO_Scaler_State scaler_info;
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;

	scaler_info.type=(unsigned int)ratio_type;
	scaler_info.state=(unsigned int)get_vo_smoothtoggle_state(display);

	scaler_info.overscan_x=(unsigned int)overscan_size.srcx;
	scaler_info.overscan_y=(unsigned int)overscan_size.srcy;
	scaler_info.overscan_wid=(unsigned int)overscan_size.src_wid;
	scaler_info.overscan_height=(unsigned int)overscan_size.src_height;

	scaler_info.disp_x=(unsigned int)dispwin.srcx;
	scaler_info.disp_y=(unsigned int)dispwin.srcy;
	scaler_info.disp_wid=(unsigned int)dispwin.src_wid;
	scaler_info.disp_height=(unsigned int)dispwin.src_height;

	scaler_info.vo_3d_mode=Scaler_Get3DMode((SCALER_DISP_CHANNEL)display);
	scaler_info.display = display;

	scaler_info.NewAdaptiveInputFlag = Scaler_AdaptiveStream_NewInputRegionFlagGet(display);

	Check_smooth_toggle_update_flag(display);

	pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDSMOOTHTOGGLESTATE);
	ulCount = sizeof(VO_Scaler_State) / sizeof(unsigned int);

	// copy to RPC share memory
	memcpy(pulDataTemp, &scaler_info, sizeof(VO_Scaler_State));

	for (i = 0; i < ulCount; i++)
		pulDataTemp[i] = htonl(pulDataTemp[i]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDSMOOTHTOGGLESTATE,0,0)))
	{
		pr_debug("ret=%d, send VO's scaler state to driver fail !!!\n", ret);
	}
}

void smooth_toggle_update_scaler_info(void)
{
#if 0
	unsigned char flag = TRUE;
	int ret;
	unsigned int i = 0, ulVOInfoItemCount = 0;
	unsigned int *pulTemp;

	SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
	switch ( pVOInfo->mode )
	{
		case VODMA_DEFAULT_MODE:
		case VODMA_858x525_720x480_60I:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_480I);
			break;
		case VODMA_858x525_720x480_60P:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_480P);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x013b);
			break;
		case VODMA_864x625_720x576_50I:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_576I);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x009D);
			break;
		case VODMA_864x625_720x576_50P:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_576P);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x0138);
			break;
		case VODMA_1980x750_1280x720_50P:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_720P50);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x0177);
			break;
		case VODMA_1650x750_1280x720_60P:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_720P60);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x01C2);
			break;
		case VODMA_2640x1125_1920x1080_50I:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_1080I25);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x0119);
			break;
		case VODMA_2200x1125_1920x1080_60I:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_1080I30);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x0151);
			break;
		case VODMA_2640x1125_1920x1080_50P:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_1080P50);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x0232);
			break;
		case VODMA_2200x1125_1920x1080_60P:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_1080P60);
			//Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, 0x02a3);
			break;
		case VODMA_4120x2192_3840x2160_30I:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_4k2kI30);
			break;
		case VODMA_4120x2192_3840x2160_30P:
			Scaler_DispSetInputInfo(SLR_INPUT_MODE_CURR, _MODE_4k2kP30);
			break;
		default:
			printk("unknown display mode!!!\n");
			flag = FALSE;
			break;
	}

	Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_10BIT,FALSE);

	// start position
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE, pVOInfo->h_start);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE, pVOInfo->v_start);

	// size
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE, pVOInfo->h_width);
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE, pVOInfo->v_length);

	// Set input H-Total,V-Total
	Scaler_DispSetInputInfo(SLR_INPUT_H_LEN, pVOInfo->h_total);
	Scaler_DispSetInputInfo(SLR_INPUT_V_LEN, pVOInfo->v_total);
	// chroma format
	if ( pVOInfo->chroma_fmt == FMT_444 ) {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_422, FALSE);
		Scaler_DispSetInputInfo(SLR_INPUT_COLOR_SPACE , COLOR_YUV444);
	} else if ( pVOInfo->chroma_fmt == FMT_422 ) {
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_422, TRUE);
		Scaler_DispSetInputInfo(SLR_INPUT_COLOR_SPACE , COLOR_YUV422);
	} else {
		printk("impossible chorma format!!!\n");
		flag = FALSE;
	}

	// progressive or interlace
	if ( pVOInfo->progressive ) {	// progressive
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE, FALSE);
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP, FALSE);
	} else {	// interlace
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE, TRUE);
	}

	// horizontal frequency
	Scaler_DispSetInputInfo(SLR_INPUT_H_FREQ, pVOInfo->h_freq);

	// vertical frequency
	Scaler_DispSetInputInfo(SLR_INPUT_V_FREQ, pVOInfo->v_freq);

	// aspect ratio
	Scaler_DispSetInputInfo(SLR_INPUT_ASPECT_RATIO, pVOInfo->i_ratio);

	// afd
	Scaler_DispSetInputInfo(SLR_INPUT_AFD, pVOInfo->afd);

	if (Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE())
	{
		if(pVOInfo->mode_3d){
			if(!pVOInfo->force2d){
				if(pVOInfo->mode_3d == VO_3D_FRAME_PACKING){
					// Enter 3D auto mode only for MVC
					Scaler_Set3DMode_Attr(SLR_3DMODE_3D_AUTO);
					if(Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()) // PR 3D
						Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_FRAME_PACKING);
					else if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE()) // SG 3D
						Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_FRAMESEQUENCE);
				}
				else if(pVOInfo->mode_3d == VO_3D_SIDE_BY_SIDE_HALF){
					Scaler_Set3DMode_Attr(SLR_3DMODE_3D_AUTO);
					Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_SIDE_BY_SIDE_HALF);
				}
				else if(pVOInfo->mode_3d == VO_3D_TOP_AND_BOTTOM){
					Scaler_Set3DMode_Attr(SLR_3DMODE_3D_AUTO);
					Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_TOP_AND_BOTTOM);
				}
				else if(pVOInfo->mode_3d == VO_3D_REALID){
					Scaler_Set3DMode_Attr(SLR_3DMODE_3D_AUTO);
					Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_REALID);
				}
			}else{
				Scaler_Set3DMode_Attr(SLR_3DMODE_3D_AUTO_CVT_2D);
				Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_2D_ONLY);
			}
		} else if(Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA) == FALSE){ // reset last MVC auto 3D mode
			if(Scaler_Get3DMode() == SLR_3DMODE_3D_AUTO)
			{
				printk("[vo] Reset Auto3D from[%d], v=%d\n", Scaler_Disp3dGetInfo(SLR_DISP_3D_3DTYPE), Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
				Scaler_Set3DMode_Attr(SLR_3DMODE_2D);
				Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_2D_ONLY);
			}
		}
#ifdef USE_3D_AUTO_DETECT // reset 3D mode when auto detect reset to 2D mode
		else if((Scaler_Get_CurVoInfo_plane() == VO_VIDEO_PLANE_V2) &&
				((Scaler_Get3DMode() == SLR_3DMODE_3D_AUTO) || ((Scaler_Get3DMode() == SLR_3DMODE_2D) && (Scaler_Disp3dGetInfo(SLR_DISP_3D_3DTYPE) != SLR_3D_2D_ONLY))))
		{
			printk("[vo] Reset 2D from mode/I3D/Type[%d/%d/%d]\n", Scaler_Get3DMode(), Scaler_DispGetInputInfo(SLR_INPUT_THROUGH_I3DDMA), Scaler_Disp3dGetInfo(SLR_DISP_3D_3DTYPE));
			Scaler_Set3DMode_Attr(SLR_3DMODE_2D);
			Scaler_Disp3dSetInfo(SLR_DISP_3D_3DTYPE, SLR_3D_2D_ONLY);
		}
#endif
	}
	printk("smooth_toggle_update_scaler_info\n");
#endif
}
void Share_Memory_Set_Scaler_Run_Flag(unsigned char enable)
{
	unsigned int *sync_flag = NULL;
	unsigned int *pulTemp = NULL;
	unsigned int i = 0, ulItemCount = 0;

	sync_flag = (unsigned int *)Scaler_GetShareMemVirAddr(VO_RUN_SCALER_FLAG);
	*sync_flag = enable;

	ulItemCount = sizeof(unsigned int) /  sizeof(UINT32);
	pulTemp = sync_flag;
	for (i = 0; i < ulItemCount; i++)
		pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);
}

void Check_smooth_toggle_update_flag(unsigned char display)
{
	if((Scaler_InputSrcGetType(display) == _SRC_VO) && (Get_DisplayMode_Src(display) != VSC_INPUTSRC_JPEG))
	{//VO and Not JPEG case, jpag goes kernel smooth toggle
		unsigned char point_out=50;
	#ifdef CONFIG_I2RND_ENABLE
		if (Scaler_I2rnd_get_enable()) {
			if (get_i2rnd_pst_write_pnt_counter()) {
				while(point_out) {
					if (!get_i2rnd_pst_write_pnt_counter()) {
						break;
					}
					msleep(10);
					point_out--;
				}
			}
			point_out= 50;
			if (((Scaler_i2rnd_get_read_point() +1) %(PST_CMD_NUMBER+1)) <= Scaler_i2rnd_get_write_point()) {
				while(point_out) {
					if (Scaler_i2rnd_get_read_point() == Scaler_i2rnd_get_write_point()) {
						break;
					}
					msleep(10);
					point_out--;
				}
			}
			pr_emerg("i2rnd write(%d) exteed read buffer(%d)\n",Scaler_i2rnd_get_write_point(),Scaler_i2rnd_get_read_point());
			#ifdef CONFIG_PST_ENABLE
				if (!Scaler_main_md_pst_get_enable()) {
					return;
				}
			#else
				return;
			#endif
		}
	#endif
		point_out=50;
	#ifdef CONFIG_PST_ENABLE
		if (Scaler_main_md_pst_get_enable()) {
			if (((Scaler_pst_get_read_point(_MAIN_MD) +1) %(PST_CMD_NUMBER+1)) <= Scaler_pst_get_write_point(_MAIN_MD)) {
				while(point_out) {
					if (Scaler_pst_get_write_point(_MAIN_MD) == Scaler_pst_get_read_point(_MAIN_MD)) {
						break;
					}
					msleep(10);
					point_out--;
				}
			}
			pr_emerg("md pst write(%d) exteed read buffer(%d)\n",Scaler_pst_get_write_point(_MAIN_MD),Scaler_pst_get_read_point(_MAIN_MD));
			return;
		}
	#endif

		unsigned int timeout=0x1fffff;//change timeout time = 200ms @Crixus 20151217 ;
		unsigned int frametimeout = 0x1fffff;
		unsigned char check_bit = display?(_BIT5):(_BIT0);
		while(frametimeout) {
			if ((rtd_inl(VGIP_Smooth_tog_ctrl_reg)&check_bit)==0) {
				unsigned int *pulTemp;
				unsigned int i = 0, ulItemCount = 0;
				SMOOTH_TOGGLE_UPDATE_FWINFO_PKG *sm_info_pkg = NULL;
				SMOOTH_TOGGLE_UPDATE_FWINFO_PKG update_info;
				while(timeout) {
					sm_info_pkg = (SMOOTH_TOGGLE_UPDATE_FWINFO_PKG *)Scaler_GetShareMemVirAddr(SCALERIOC_SMOOTHTOGGLE_SHARE_INFO);
					if (sm_info_pkg) {
						memcpy(&update_info, sm_info_pkg, sizeof(SMOOTH_TOGGLE_UPDATE_FWINFO_PKG));
						ulItemCount = sizeof(SMOOTH_TOGGLE_UPDATE_FWINFO_PKG) /  sizeof(UINT32);
						pulTemp = (unsigned int *)&update_info;
						for (i = 0; i < ulItemCount; i++)
							pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);
						if (!update_info.sm_info[display].update_flag) {
							break;
						}
					}
					timeout--;
				}
				break;
			}
			frametimeout--;
		}
		pr_debug("Check_smooth_toggle_update_flag:timeout=%x,%x\n",timeout,frametimeout);
		if(timeout==0){
			unsigned char info=0;
			unsigned char plane = get_vo_plane_flag(display);
			if(display==SLR_MAIN_DISPLAY){
				info=plane;
			} else {
				info=plane+100;
			}
			Scaler_Set_VOsmoothenable(info);
		}
		if(frametimeout==0){
			rtd_clearbits(VGIP_Smooth_tog_ctrl_reg,check_bit);
		}

		if((timeout == 0) || (frametimeout == 0))
		{
			pr_err("Check_smooth_toggle_update_flag timeout=%x, frametimeout=%x\n", timeout, frametimeout);
		}
	}
}

static SCALER_MEMORY_INFO scaler_memory_info;

#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
void send_memory_mapping_for_adaptive_streaming(void)
{
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	int ret = 0;

	if(drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) == 0x0){
		printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN));
	 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC));
	 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD));
	 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1Addr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg));
	 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_2ndAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg));
	 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_3rdAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg));
	 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr1_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg));
	 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr2_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg));
	}
	scaler_memory_info.M_main_first_addr = drvif_memory_get_memtag_startaddr(MEMIDX_MAIN);
	scaler_memory_info.M_main_sec_addr = drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC);
	//scaler_memory_info.M_main_size=m_size;
	scaler_memory_info.M_main_third_addr = drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD);
	pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDSCALERMEMORYINFO);
	ulCount = sizeof(scaler_memory_info) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulDataTemp, &scaler_memory_info, sizeof(scaler_memory_info));

	for (i = 0; i < ulCount; i++)
		pulDataTemp[i] = htonl(pulDataTemp[i]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDSCALERMEMORYINFO,0,0)))
	{
		pr_debug("ret=%d, send SCALERIOC_SENDSCALERMEMORYINFO to driver fail !!!\n", ret);
	}
}
#endif
extern unsigned char vsc_get_adaptivestream_flag(void);
void vo_smoothtoggle_memory_alloc(unsigned char display)
{
	unsigned int di_addr,m_addr_sec,m_addr_first,m_addr_third;
	unsigned int di_size;
	unsigned int m_sub_sec,m_sub_first,m_sub_third;

	unsigned int buffer_alloc = 0;
	//SCALER_MEMORY_INFO scaler_memory_info;
	unsigned int VO_MAX_FRC_SIZE;
#ifdef CONFIG_I2RND_ENABLE
	//sync the multiview buffer size @Crixus 20160722
	if(Scaler_I2rnd_get_enable() == _ENABLE){
		VO_MAX_FRC_SIZE = MDOMAIN_MULTIVIEW_BUFFER_SIZE;
	}
	else
#endif
		VO_MAX_FRC_SIZE = MDOMAIN_MAIN_BUFFER_SIZE;//using fixed memory size @Crixus 20160810
#ifdef Mer2_MEMORY_ALLOC
	buffer_alloc = drv_memory_Get_di_alloc_buffer_Static(0, 0, 0, 0, 0, 0);
#else
	drv_memory_di_alloc_buffer_set(_SRC_VO,1);
	buffer_alloc=drv_memory_di_alloc_buffer_get();
#endif
	if (display==SLR_MAIN_DISPLAY) {
		drvif_memory_free_block(MEMIDX_DI);
#ifndef CONFIG_MDOMAIN_RESERVED_MEMORY
		drvif_memory_free_block(MEMIDX_MAIN_THIRD);
		drvif_memory_free_block(MEMIDX_MAIN_SEC);
		drvif_memory_free_block(MEMIDX_MAIN);
#endif
		if(vo_force_data_mode_get_enable(SLR_MAIN_DISPLAY)==SLR_DISPLAY_DATA_FRAME_SYNC)
		{
			di_addr=drvif_memory_alloc_block(MEMIDX_DI,0x400000, MEMALIGN_ANY);
			m_addr_third=0xffffffff;
			m_addr_sec=0xffffffff;
			m_addr_first=0xffffffff;
		}
		else if(vo_force_data_mode_get_enable(SLR_MAIN_DISPLAY)==SLR_DISPLAY_DATA_FS_NO_MEMORY)
		{
			di_addr=0xffffffff;
			m_addr_third=0xffffffff;
			m_addr_sec=0xffffffff;
			m_addr_first=0xffffffff;
		}
		else //if(vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FRC)
		{
			di_addr=drvif_memory_alloc_block(MEMIDX_DI,buffer_alloc, MEMALIGN_ANY);
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
			m_addr_third=drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD);
			m_addr_sec=drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC);
			m_addr_first=drvif_memory_get_memtag_startaddr(MEMIDX_MAIN);
#else
			m_addr_third=drvif_memory_alloc_block(MEMIDX_MAIN_THIRD,VO_MAX_FRC_SIZE, MEMALIGN_ANY); // the max: 444 ,8 bit:1920*1080*3byte
			m_addr_sec=drvif_memory_alloc_block(MEMIDX_MAIN_SEC,VO_MAX_FRC_SIZE, MEMALIGN_ANY);  // the max: 444 ,10 bit:2160*1440*30bit
			m_addr_first=drvif_memory_alloc_block(MEMIDX_MAIN,VO_MAX_FRC_SIZE, MEMALIGN_ANY);
#endif


		}

		di_size=drv_memory_di_buffer_get();
		//m_size=drvif_memory_get_block_size(MEMIDX_MAIN);
		m_sub_third=drvif_memory_get_block_addr(MEMIDX_SUB_THIRD);
		m_sub_sec=drvif_memory_get_block_addr(MEMIDX_SUB_SEC);
		m_sub_first=drvif_memory_get_block_addr(MEMIDX_SUB);
	}
#ifdef CONFIG_DUAL_CHANNEL
	else {
		drvif_memory_free_block(MEMIDX_SUB_THIRD);
		drvif_memory_free_block(MEMIDX_SUB_SEC);
		drvif_memory_free_block(MEMIDX_SUB);

		if(vo_force_data_mode_get_enable(SLR_SUB_DISPLAY)==SLR_DISPLAY_DATA_FRAME_SYNC)
		{
			m_sub_third=0xffffffff;
			m_sub_sec=0xffffffff;
			m_sub_first=0xffffffff;
		}
		else if(vo_force_data_mode_get_enable(SLR_SUB_DISPLAY)==SLR_DISPLAY_DATA_FS_NO_MEMORY)
		{
			m_sub_third=0xffffffff;
			m_sub_sec=0xffffffff;
			m_sub_first=0xffffffff;
		}
		else //if(vo_force_data_mode_get_enable()==SLR_DISPLAY_DATA_FRC)
		{
			m_sub_third=drvif_memory_alloc_block(MEMIDX_SUB_THIRD,VO_MAX_FRC_SIZE, MEMALIGN_ANY);//0xffffffff;//drvif_memory_alloc_block(MEMIDX_MAIN_THIRD,0x600000, MEMALIGN_ANY); // the max: 444 ,8 bit:1920*1080*3byte
			m_sub_sec=drvif_memory_alloc_block(MEMIDX_SUB_SEC,VO_MAX_FRC_SIZE, MEMALIGN_ANY);  // the max: 444 ,10 bit:2160*1440*30bit
			m_sub_first=drvif_memory_alloc_block(MEMIDX_SUB,VO_MAX_FRC_SIZE, MEMALIGN_ANY);
		}
		di_size=drv_memory_di_buffer_get();
		di_addr=drvif_memory_get_block_addr(MEMIDX_DI);
		m_addr_third=drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD);
		m_addr_sec=drvif_memory_get_block_addr(MEMIDX_MAIN_SEC);
		m_addr_first=drvif_memory_get_block_addr(MEMIDX_MAIN);
	}
#endif
	scaler_memory_info.DI_addr=di_addr;
	scaler_memory_info.DI_size=di_size;
	scaler_memory_info.M_main_first_addr=m_addr_first;
	scaler_memory_info.M_main_sec_addr=m_addr_sec;
	//scaler_memory_info.M_main_size=m_size;
	scaler_memory_info.M_main_third_addr=m_addr_third;

	scaler_memory_info.M_sub_first_addr = m_sub_first;
	scaler_memory_info.M_sub_sec_addr = m_sub_sec;
	scaler_memory_info.M_sub_third_addr = m_sub_third;

#ifndef CONFIG_MDOMAIN_RESERVED_MEMORY
	int ret = 0;
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;

	pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_SENDSCALERMEMORYINFO);
	ulCount = sizeof(scaler_memory_info) / sizeof(unsigned int);

	// copy to RPC share memory
	memcpy(pulDataTemp, &scaler_memory_info, sizeof(scaler_memory_info));

	for (i = 0; i < ulCount; i++)
		pulDataTemp[i] = htonl(pulDataTemp[i]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SENDSCALERMEMORYINFO,0,0)))
	{
		pr_debug("ret=%d, send SCALERIOC_SENDSCALERMEMORYINFO to driver fail !!!\n", ret);
	}
#endif
}

void vodma_smoothtoggle_reset(unsigned char display,unsigned char plane)
{
	if(SLR_MAIN_DISPLAY == display)
		clear_imd_smooth_toggle_clk_time2switch_en(display);

	if(VO_VIDEO_PLANE_V1 == plane) {
		vodma_vodma_smooth_toggle_1_RBUS vodma_smooth_toggle_reg;
		vodma_smooth_toggle_reg.regValue = rtd_inl(VODMA_VODMA_SMOOTH_TOGGLE_1_reg);
		if (vodma_smooth_toggle_reg.smooth_en == 1) {
			vodma_smooth_toggle_reg.smooth_en = 0;
			rtd_outl(VODMA_VODMA_SMOOTH_TOGGLE_1_reg, vodma_smooth_toggle_reg.regValue);
		}
	} else if(VO_VIDEO_PLANE_V2 == plane) {
		vodma2_vodma2_smooth_toggle_1_RBUS vodma2_smooth_toggle_reg;
		vodma2_smooth_toggle_reg.regValue = rtd_inl(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg);
		if (vodma2_smooth_toggle_reg.smooth_en == 1) {
			vodma2_smooth_toggle_reg.smooth_en = 0;
			rtd_outl(VODMA2_VODMA2_SMOOTH_TOGGLE_1_reg, vodma2_smooth_toggle_reg.regValue);
		}
	}
}

void smooth_toggle_disconnect(unsigned char display,unsigned char plane)
{
	Check_smooth_toggle_update_flag(display);
	if(Get_vo_smoothtoggle_timingchange_flag(display)) //direct_vo
	{
		Set_direct_vo_smoothtoggle_enable(0,SLR_DISPLAY_DEFAULT, display,plane); //close smooth toggle
	} else {
		vodma_smoothtoggle_reset(display,plane);
		set_vo_open_smooth_toggle_enable(0,display);
		set_vo_run_smooth_toggle_enable(0,display);
	}
}

//----------end of api
