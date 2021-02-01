//Kernel Header file
#include <linux/delay.h>
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>

#include <linux/pageremap.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/spinlock_types.h>/*For spinlock*/

//#include <rtk_kdriver/common.h>
//#include <rtk_kdriver/io.h>
#include <rtk_kdriver/RPCDriver.h>
#include <rtk_kdriver/rtk_pwm.h>
#include <mach/platform.h>
#include <mach/rtk_platform.h>
#include <mach/timex.h>



#include <scalercommon/scalerCommon.h>
#include "scaler_vbedev.h"
#include "scaler_vfedev.h"
#include "scaler_vscdev.h"

#include "tvscalercontrol/io/ioregdrv.h"
#include "tvscalercontrol/scalerdrv/scalerdrv.h"
#include "tvscalercontrol/scalerdrv/scalerdisplay.h"
#include "tvscalercontrol/scalerdrv/adjust.h"
#include "tvscalercontrol/scalerdrv/scalerclock.h"
#include "tvscalercontrol/scalerdrv/framesync.h"
#include "tvscalercontrol/scalerdrv/conversion_2d_3d.h"
#include <tvscalercontrol/scalerdrv/scaler_2dcvt3d_ctrl.h>
#include <tvscalercontrol/vo/rtk_vo.h>
#include <tvscalercontrol/hdmirx/hdmi_vfe.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>
#include <tvscalercontrol/vdac/vdac.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/vip/viptable.h>
#include <tvscalercontrol/scaler_vpqdev.h>
#include <tvscalercontrol/scaler_vpqmemcdev.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/avd/avdctrl.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>

#include <rbus/timer_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/sfg_reg.h>
#include <rbus/pif_reg.h>
#include <rbus/mdomain_cap_reg.h>
//#include <rbus/rbus_DesignSpec_MISC_GPIOReg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/dma_vgip_reg.h>
#include <rbus/h3ddma_rgb2yuv_dither_4xxto4xx_reg.h>
#include <rbus/h3ddma_reg.h>
#include <rbus/h3ddma_hsd_reg.h>
#include <rbus/tve_dma_reg.h>
#include <rbus/tve_reg.h>
#include <rbus/vby1_reg.h>
#include <rbus/tcon_reg.h>
#include <rbus/epi_reg.h>
#include <rbus/pinmux_lvdsphy_reg.h>
#include <rbus/pinmux_reg.h>
#include <rbus/dolby_v_top_reg.h>
#include <linux/i2c.h>
//#include <rbus/d_2d_to_3d_reg.h>
//#include <rbus/dispd_boe_rgbw_reg.h>
#include <rbus/scaleup_reg.h>
#include <rbus/lg_m_plus_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/od_dma_reg.h>
#include <rbus/ldspi_reg.h>

#include <rpc/VideoRPC_System.h>
#include <rpc/VideoRPC_System_data.h>

#ifdef VBE_DISP_TCON_SELF_CHECK
#include <rbus/mdomain_disp_reg.h>
extern unsigned int monitor_rgb_rolling;
#endif

#define DBG_PRINT(s, args...) pr_debug(s, ## args)
#define TAG_NAME_VBE "VBE"

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

#if !defined(CONFIG_CUSTOMER_TV006) && defined(CONFIG_RTK_KDRV_GDMA)
extern int gdma_resume_by_vbe(void);
extern int gdma_suspend_by_vbe(void);
#endif

static struct cdev vbe_cdev;

int vbe_major   = VBE_MAJOR;
int vbe_minor   = 0 ;
int vbe_nr_devs = VBE_NR_DEVS;

static struct semaphore VBE_Semaphore;
static struct semaphore VBE_RGBW_Resume_Semaphore;

module_param(vbe_major, int, S_IRUGO);
module_param(vbe_minor, int, S_IRUGO);
module_param(vbe_nr_devs, int, S_IRUGO);
static struct class *vbe_class;
void vbe_disp_early_resume(void);


static VBE_AVE_SUSPEND_RESUME_T vbe_ave_suspend_resume;
static VBE_DISP_TCON_SUSPEND_RESUME_T vbe_disp_tcon_suspend_resume;
#ifdef CONFIG_PM
void vbe_disp_panel_resume(void);
extern void vpq_memc_disp_suspend(void);
extern void vpq_memc_disp_resume(void);
VBE_DISP_SUSPEND_RESUME_T vbe_disp_suspend_resume;
VBE_DISP_PANEL_EPI_SUSPEND_RESUME_T vbe_disp_panel_epi_suspend_resume;
VBE_DISP_PANEL_TCON_SUSPEND_RESUME_T vbe_disp_panel_tcon_suspend_resume;
#endif

/*******************************************************************************
****************************VBE DISP DRIVER*************************************
*******************************************************************************/
static unsigned char VBE_DISP_Global_Status = VBE_DISP_NOTHING;
unsigned char panel_bl_type;
unsigned char led_bar_type;
unsigned char epi_panel_type;
unsigned char panel_inch;
unsigned char panel_maker;
unsigned int disp_osd_width;
unsigned int disp_osd_height;
BOOLEAN disp_ForceFreeRun=DISP_TIMING_DEFAULT;
unsigned char disp_framerate;
unsigned int vtotal_measure;
unsigned int mask_3d_auto_detect = 0;
static UINT8 first_boot_run_main = FALSE;
extern struct semaphore Iv2dv_Slow_Tuning_Semaphore;
static UINT8 oled_resume_eit_flag = FALSE; //this flag control sfg forcebg when enable OLED panel EIT function
unsigned char vbe_dynamic_memc_bypass_flag = 0;
static unsigned int stBacklihgtStart_Tick = 0;

unsigned char Get_PANEL_BL_type(void)
{
	return panel_bl_type;
}
void Set_PANEL_BL_type(unsigned char type)
{
	panel_bl_type=type;
}
unsigned char Get_PANEL_LED_Bar_type(void)
{
	return led_bar_type;
}
void Set_PANEL_LED_Bar_type(unsigned char type)
{
	led_bar_type=type;
}
unsigned char Get_PANEL_EPI_TYPE(void)
{
	return epi_panel_type;
}
void Set_PANEL_EPI_TYPE(unsigned char type)
{
	epi_panel_type=type;
}
unsigned char Get_PANEL_INCH(void)
{
	return panel_inch;
}
void Set_PANEL_INCH(unsigned char inch)
{
	panel_inch=inch;
}

unsigned char Get_PANEL_MAKER(void)
{
	return panel_maker;
}
void Set_PANEL_MAKER(unsigned char maker)
{
	panel_maker=maker;
}

unsigned int Get_DISP_OSD_Width(void)
{
	return disp_osd_width;
}
void Set_DISP_OSD_Width(unsigned int width)
{
	disp_osd_width=width;
}
unsigned int Get_DISP_OSD_Height(void)
{
	return disp_osd_height;
}
void Set_DISP_OSD_Height(unsigned int height)
{
	disp_osd_height=height;
}
void Disp_Enable_isForceFreeRun(BOOLEAN isForceFreeRun)
{
	if(isForceFreeRun)
	{
		disp_ForceFreeRun=DISP_FREE_RUN;
	}
	else
	{
		disp_ForceFreeRun=DISP_FRAMESYNC;
	}
}
BOOLEAN Disp_Get_isForceFreeRun(void)
{
	 return disp_ForceFreeRun;
}
void Disp_Set_framerate(unsigned char framerate)
{
	disp_framerate=framerate;
}
unsigned char Disp_Get_framerate(void)
{
	return disp_framerate;
}

unsigned char vflip_enable=0;
unsigned char mirror_flag=0;

void Set_Mirror_VFLIP_ENABLE(unsigned char enable)
{
	vflip_enable=enable;
	mirror_flag=1;
}
unsigned char Get_Mirror_VFLIP_ENABLE(void)
{
	mirror_flag=0;
	return vflip_enable;
}
unsigned char Get_vbe_mirror_vflip(void)
{
	if(mirror_flag)
	{
		return vflip_enable;
	}
	else
	{
		return 2; // 2 is bypass vbe mirror
	}
}
unsigned char fll_running_flag=0;

void modestate_set_fll_running_flag(unsigned char bEnable)
{
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"### modestate_set_fll_running_flag (%d) ###\n", bEnable);
	fll_running_flag = bEnable;
}

unsigned char modestate_get_fll_running_flag(void)
{
	return fll_running_flag;
}

unsigned char modestate_decide_display_timing(void)
{
	if(Disp_Get_isForceFreeRun()==DISP_FREE_RUN){
		return DISPLAY_MODE_FRC;
	}else if(_TRUE == Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
		if((Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI) ||
			(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI))
			return DISPLAY_MODE_NEW_FLL_MODE;
		else
			return DISPLAY_MODE_FRAME_SYNC;
	}else if(modestate_check_input_special_framerate()){
		return DISPLAY_MODE_FRC;
	}else
		return DISPLAY_MODE_NEW_FLL_MODE;
}

unsigned char vbe_disp_get_adaptivestream_fs_mode(void)
{
	char keepAdaptiveStreamFsMode=0;
//	vp9_ctrl0_RBUS vodma_vp9_ctrl0_reg;

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI){
		return FALSE;
	}


	keepAdaptiveStreamFsMode = vsc_get_adaptivestream_flag();
/*
	vodma_vp9_ctrl0_reg.regValue = IoReg_Read32(VODMA_VP9_CTRL0_reg);
	if((vodma_vp9_ctrl0_reg.vp9_en == 1)&&(vsc_get_adaptivestream_flag()==1)){
		keepAdaptiveStreamFsMode = 1;
	}else{
		keepAdaptiveStreamFsMode = 0;
	}
*/
	if(Get_DisplayMode_Src(0) != VSC_INPUTSRC_VDEC){
		keepAdaptiveStreamFsMode = 0;
	}

	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"file=%s, function=%s, keepAdaptiveStreamFsMode=%d\n", __FILE__, __FUNCTION__,  keepAdaptiveStreamFsMode);

	return keepAdaptiveStreamFsMode;
}

void modestate_set_display_timing(unsigned char dclk_is_max)
{
	ppoverlay_dv_total_RBUS dv_total_reg;
	if(Disp_Get_isForceFreeRun()==DISP_FREE_RUN){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[modestate_set_display_timing] Disp_Get_isForceFreeRun! \n");
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		return;
	}
//	unsigned int vtotal;
	//framesync mode will set framesync bit at other place
	//if vby1 to hdmi board, used new fll mode

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI){
		// default go new fix last line for vby1 to hdmi compability.
#ifndef ENABLE_VBY1_TO_HDMI_4K2K_DATA_FS
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		return;
#endif
	}else{
		if(_TRUE == Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
			return;
	}

#ifdef CONFIG_DUAL_CHANNEL
	//sub display not apply
	if(SLR_SUB_DISPLAY == Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))
		return;
#endif

	//timing
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	vtotal_measure=dv_total_reg.dv_total;
#if 0
	if(Disp_Get_isForceFreeRun()==DISP_FREE_RUN)
	{
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		vtotal=(Get_DISPLAY_CLOCK_TYPICAL()/Get_DISP_HORIZONTAL_TOTAL()/Disp_Get_framerate());
		dv_total_reg.dv_total = vtotal;
		IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
		printk("DVTotal:%x, 8014:%x\n", vtotal, IoReg_Read32(PPOVERLAY_DV_total_reg));
		vtotal_measure=Get_DISP_VERTICAL_TOTAL();
		return;
	}
	else if(Disp_Get_isForceFreeRun()==DISP_FRAMESYNC)
	{
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
		return;
	}
#endif

	// [SG] 3D free run condition -- SG 3D FRC@120Hz for 3D or 2Dcvt3D mode
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE()){
		if((drvif_scaler3d_get_IDMA3dMode() != SLR_IDMA_MODE_DISABLE)
			|| ((drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE) && drvif_scaelr3d_decide_is_3D_display_mode()))
		{
			// don't change DTG timing to frame sync mode in IDMA data FRC mode
			if(drvif_scaler_get_display_mode() == 0){
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[IDMA] IGNORE FS_EN\n");
				return;
			}
		}
		else if(drvif_scaelr3d_decide_is_3D_display_mode()
			&& (Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() || Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE()))
		{
			// 3D display timing free run for SG or PR to SG 3D panel
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
			return;
		}
	}
#if 0 // marked unused code in merlin by ben_wang
	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1){

/*		if(Get_DISPLAY_2K1K_windows_mode() == 1){
				printf("+++++++ Custom window mode : go FRC timing +++++++++ \n");
 				drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		}
		else{
*/
		{
 			if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE()){
 				printk("+++++++ 2k1k lvds t120Hz iming +++++++++ \n");
				// 3D data FRC path
				if((modestate_I3DDMA_get_In3dMode()|| modestate_get_vo3d_in_framePacking_FRC_mode()
					|| ((drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE) && drvif_scaelr3d_decide_is_3D_display_mode()))
					&& (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE))
				{
					// 3D free run 120Hz
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
	 				printk("[IDMA] 3D=%d, data/timing FRC\n", Scaler_Get3DMode());
				}
				else if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 610) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 1000) && (Scaler_InputSrcGetMainChType()!=_SRC_TV))
				{
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
	 				printk("go FRC timing\n");
				}else{
	 				printk("go Framesync timing\n");
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
				}
 			}
 			else{
 				printk("+++++++ 4k2k lvds 30Hz timing +++++++++ \n");
				printk("go Framesync timing\n");
				drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
 			}
		}
		return;
	}
#endif

	if(modestate_check_input_special_framerate()){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[modestate_set_display_timing] Special input framerate, set timing free run! \n");
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		return;
	}
/*
	if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) < 2048) && (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) < 1200)
	  &&((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 235) || ((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 255) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 290)))){
		printk("[modestate_set_display_timing] Special input framerate, set timing free run! \n");
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
*/
	//enable new fix last line
	{
		drvif_scaler_set_display_mode(DISPLAY_MODE_NEW_FLL_MODE);
		return;
	}


	//USER:LewisLee DATE:2010/12/7
	//to prevent Vflip state, it have frame tear
	//we set framesync at framesync_lastlinefinetune_at_frc_mode()
	//let IVS2DVS delay have good relationship
//	if(_ENABLE == Scaler_Get_Vflip_Enable()) //frank@0517 sync Mac project let timing go framesync to solve mantis#38804 movie delay problem
//	{
//#ifndef VBY_ONE_PANEL //frank@0521 add VBY1 define to solve VBY1 panel shift problem
#if 0 // marked unused code in merlin by ben_wang
		if(_TRUE == Scaler_EnterFRC_LastLine_Condition())
		{
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC); //frank@05232014 enable FS timing when fll flow to solve mantis#75280
			return;
		}
#endif
//#endif
//	}
#if 0

	if (Scaler_InputSrcGetMainChType() == _SRC_TV)
	{

#ifdef CONFIG_ATV_FRC
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		return;
#endif //#ifdef CONFIG_ATV_FRC

#if 1 //#ifdef CONFIG_FV_CHECK
		if (!CTVCheckFVBias() && !Scaler_TVGetScanMode()) {
 			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
			return;
		}
#endif //#ifdef CONFIG_FV_CHECK

		//USER:LewisLee DATE:2012/06/27
		//for customer request, weak signal keep in framesync
		if(_TRUE == drvif_video_status_reg(VDC_hv_lock))
		{
			if(_TRUE == framesync_get_enterlastline_at_frc_mode_flg())
			{
				//In Fix last line mode, can keep in framesync mode
				drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
				printk( "Change to FrameSync7-1\n");
			}
			else// if(_FALSE == framesync_get_enterlastline_at_frc_mode_flg())
			{
				if(_TRUE == Scaler_Get_ATV_WeakSignal_ChangeToFRC_Flag())
				{
					if(drvif_module_vdc_NoiseStatus() < Scaler_Get_ATV_VDC_NoiseLevel_Threshold())
					{
						drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
						printk( "Change to FrameSync7-2\n");
					}
					else
					{
					        drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
					}
				}
				else// if(_FALSE == Scaler_Get_ATV_WeakSignal_ChangeToFRC_Flag())
				{
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
					printk( "Change to FrameSync7-3\n");
				}
			}
		}
		else// if(_FALSE == drvif_video_status_reg(VDC_hv_lock))
		{
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		}
 			//frank@0428, when source is VGA or DVI source,go FRC timing
	}
	else if ((Scaler_InputSrcGetMainChType() == _SRC_VGA) || // VGA
		((Scaler_InputSrcGetMainChFrom() == _SRC_FROM_TMDS) && (!drvif_IsHDMI())) || // DVI & DisplayPort
		((Scaler_InputSrcGetMainChFrom() == _SRC_FROM_TMDS) && drvif_IsHDMI() && (drvif_Hdmi_GetColorSpace()==0) && (Scaler_ModeGetModeInfo(SLR_MODE_IVFREQ)>600)) ) // HDMI via VGA card (HDMI && RGB && IVFreq>60Hz)
	{
		//USER:LewisLee DATE:2011/02/22
		//to prevent VGA have frame tear
		if(_TRUE == dclk_is_max)
		{
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		}
		else// if(_FALSE == dclk_is_max)
		{
			if(_TRUE == Scaler_EnterFRC_LastLine_Condition())
			{
				drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
			}
			else// if(_FALSE == Scaler_EnterFRC_LastLine_Condition())
			{
				//if Vfreq large than 65Hz, need set it as FRC
				if(_TRUE == Scaler_Get_Customer_Force_FRC_Mode(_SRC_VGA))
				        drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
				else
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
			}
		}
	}
	else
#endif
#if 0 // marked unused code in merlin by ben_wang
	{
		if (dclk_is_max) // d-clk is the panel maximun,set frc timing
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
		else
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
	}
#endif
}

// decide it's dynamic bypass memc flow, or not
void vbe_disp_set_dynamic_memc_bypass_flag(unsigned char bOnOff)
{
	vbe_dynamic_memc_bypass_flag = bOnOff;
}

unsigned char vbe_disp_get_dynamic_memc_bypass_flag(void)
{
	//rtd_printk(KERN_EMERG, TAG_NAME_VBE,"vbe_disp_get_dynamic_memc_bypass_flag = %d \n", vbe_dynamic_memc_bypass_flag);
	return vbe_dynamic_memc_bypass_flag;
}

unsigned char vbe_disp_decide_PQ_power_saveing(void)
{
	if(vbe_disp_get_adaptivestream_fs_mode()==TRUE)
		return FALSE;


	if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)||
		(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_JPEG)){

		//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"SLR_INPUT_IPH_ACT_WID_PRE = %d \n", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
		//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"SLR_INPUT_IPV_ACT_LEN_PRE = %d \n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
		//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"SLR_INPUT_V_FREQ = %d \n", Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));

		if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) == 3840) &&
			(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) == 2160) &&
			(((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>495)&&(Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)<505))||
			((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>595)&&(Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)<605)))){
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"Enter PQ power saving mode\n");
			return TRUE;
		}
	}
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"Disable PQ power saving mode\n");
	return FALSE;
}


unsigned char vbe_disp_decide_memc_mux_bypass(void)
{
#if 0
	if(vbe_disp_get_dynamic_memc_bypass_flag() == FALSE){
		// no memc dynamic bypass flow, return it.
		return FALSE;
	}

	if(vbe_disp_get_adaptivestream_fs_mode()==TRUE)
		return FALSE;

	if(Get_DISPLAY_REFRESH_RATE()==60){
		if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)||
			(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_JPEG)){

			//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"SLR_INPUT_IPH_ACT_WID_PRE = %d \n", Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
			//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"SLR_INPUT_IPV_ACT_LEN_PRE = %d \n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE));
			//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"SLR_INPUT_V_FREQ = %d \n", Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));

			if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) == 3840) &&
				(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE) == 2160) &&
				((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>595)&&(Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)<605))){
				//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"Switch to MEMC BYPASS\n");
				return TRUE;
			}
		}
		//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"Switch to MEMC\n");
	}
#endif
	return FALSE;
}

void vbe_disp_game_mode_memc_bypass(unsigned char b_gameMode_onOff)
{
	unsigned char set_memc_bypass = 0;
	unsigned char memc_forcebg_enable = 0;

	if(vbe_disp_get_dynamic_memc_bypass_flag() == FALSE){
		// no memc dynamic bypass flow, return it.
		return;
	}

	if(vbe_disp_decide_memc_mux_bypass())
		set_memc_bypass = 1;

	if(b_gameMode_onOff==1){
		if((Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_REMOVE_RATIO)==1) &&
			(Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_MULTIPLE_RATIO)==1)){
			set_memc_bypass = 1;
		}
	}
	//rtd_printk(KERN_EMERG, TAG_NAME_VBE,"(game=%d), set_memc_bypass=%d\n", b_gameMode_onOff, set_memc_bypass);

	if(set_memc_bypass != Scaler_MEMC_get_Bypass_Status()){
		//only active mode can control MEMC force bg. Avoid DC on noise @Crixus 20161019
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE){
			Scaler_MEMC_output_force_bg_enable(_ENABLE);
			memc_forcebg_enable = 1;
		}

		if(set_memc_bypass){
			//need do memc bypass
			Scaler_MEMC_Bypass_On(1);
		}else{
			Scaler_MEMC_Bypass_On(0);
		}

		//need to wait MEMC detect candence. @Crixus 20161007
		unsigned char force_cnt = 15;
		while(force_cnt != 0){
			WaitFor_Frame_timer();
			force_cnt--;
		}

		//only active mode can control MEMC force bg. Avoid DC on noise @Crixus 20161019
		if(memc_forcebg_enable == 1){
			Scaler_MEMC_output_force_bg_enable(_DISABLE);
			memc_forcebg_enable = 0;
		}
	}
}



extern unsigned char rtk_hal_vsc_GetOutputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * poutregion);
void Scaler_disp_setting(unsigned char display)
{
	unsigned char ret=0;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;
	ppoverlay_dispd_smooth_toggle1_RBUS	dispd_smooth_toggle1_reg;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS 	dispd_stage1_sm_ctrl_reg;
	ppoverlay_dtg_m_multiple_vsync_RBUS   dtg_m_multiple_vsync_reg;
	ppoverlay_dtg_frame_cnt1_RBUS dtg_frame_cnt1_reg;
	unsigned int timeout = 0;
	unsigned int count = 0x3fffff;
	unsigned char frame_idicator=0;
	unsigned char me_protection_flag = 0;
	UINT32 mul_dbuf_cnt=0;
	UINT32 mul_dbuf_cnt2=0;
	VIDEO_RECT_T outregion;
	unsigned long flags;//for spin_lock_irqsave

	down(&VBE_Semaphore);
	if ((SCALER_DISP_CHANNEL)display == SLR_MAIN_DISPLAY) {

#if 0	// k2l flow
		drivf_scaler_reset_freerun();
		modestate_disp_flow_double_buf_enable(_ENABLE);

#if 0 // for bringup marked. @benwang
		//add ME protection when change frame rate @Crixus 20151221
		if((IoReg_Read32(me_04_write_enable_ADDR) & _BIT20) || (IoReg_Read32(me_05_write_enable_ADDR) & _BIT20)){
			me_protection_flag = 1;//if ME si disable, not to protect.
		}
		if(me_protection_flag == 1){
			IoReg_ClearBits(me_04_write_enable_ADDR, _BIT20);
			IoReg_ClearBits(me_05_write_enable_ADDR, _BIT20);
			IoReg_SetBits(KME_ME_TOP1__REG_METOP_SC_CLR_SAD_EN_ADDR, _BIT10);
			WaitFor_DEN_STOP();
			WaitFor_DEN_STOP();
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn off me4.5 ok in disp_setting\n");
		}
#endif
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

		dtg_m_multiple_vsync_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_M_multiple_vsync_reg);
		frame_idicator = dtg_m_multiple_vsync_reg.dtg_m_multiple_vsync;
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"*uzudtg_remove_half_ivs:%d\n", frame_idicator);

		if(frame_idicator > 0){ 	// run frame check
			timeout = 0xa0000; //100ms, 5 frame.
			dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
			while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= (frame_idicator-1))&& --timeout){
				dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
			}
			if(timeout == 0)
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]count timeout !!!\n", __FUNCTION__, __LINE__);
			//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"1. frame_idicator:%d\n", (IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);
			timeout = 0x25000; //20ms, 1 frame.
			//make sure that we can have a full porch apply timing change settings
			while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= frame_idicator)&& --timeout){
				dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
			}
			if(timeout == 0)
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]count timeout !!!\n", __FUNCTION__, __LINE__);
			//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"2. frame_idicator:%d\n", (IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);
		}
		modestate_set_display_timing_gen_clock_div();
		modestate_set_fractional_framesync();

		timeout = 0x25000;	//20ms, 1 frame.
		//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"+++uzudtg line_cnt:%d\n", (IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg)&0x0fff0000)>>16);
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		do{
			dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
		}while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply==1) && (--timeout));
		//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"---uzudtg line_cnt:%d\n", (IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg)&0x0fff0000)>>16);

		if(timeout==0){
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]WARNING! wait dispd_stage1_smooth_toggle_apply timeout!\n", __FUNCTION__, __LINE__);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		}else{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s][%d] wait dispd_stage1_smooth_toggle_apply ok!\n", __FUNCTION__, __LINE__);
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		}
		fw_scaler_dtg_double_buffer_apply();
		modestate_disp_flow_double_buf_enable(_DISABLE);
		modestate_set_display_timing_gen();


#if 0 // for bringup marked. @benwang
		if(me_protection_flag == 1){
			IoReg_ClearBits(KME_ME_TOP1__REG_METOP_SC_CLR_SAD_EN_ADDR, _BIT10);
			IoReg_SetBits(me_04_write_enable_ADDR, _BIT20);
			IoReg_SetBits(me_05_write_enable_ADDR, _BIT20);
			WaitFor_DEN_STOP();
			me_protection_flag = 0;
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn on me4.5 ok in disp_setting\n");
		}
#endif
#else	// k3l flow

	//double buffer D0
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	double_buffer_ctrl_reg.dreg_dbuf_en = 0;
	double_buffer_ctrl_reg.drm_multireg_dbuf_en = 1;
	double_buffer_ctrl_reg.drm_multireg_dbuf_read_sel = 1;
	double_buffer_ctrl_reg.drm_multireg_dbuf_vsync_sel = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
 	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);

	drivf_scaler_reset_freerun();

	//pre-flow. patch, let D8 double buffer works well
	count = 0x3fffff;
	while((count == 0x3fffff)&&(mul_dbuf_cnt<10000)){
		//msleep(10);
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		count = 0x3fffff;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count){
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		}
		if(count==0){
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 1 wait timeout !!!\n");
		}
		mul_dbuf_cnt++;
	}
	modestate_set_fractional_framesyncByDisp(display);

	count = 0x3fffff;
	while((count == 0x3fffff)&&(mul_dbuf_cnt2<10000)){
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		count = 0x3fffff;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count){
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		}
		if(count==0){
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 2 wait timeout !!!\n");
		}
		mul_dbuf_cnt2++;
	}
	modestate_set_display_timing_gen_clock_divByDisp(display);
	count = 0x3fffff;
	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=0;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);

	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply)&& --count){
		dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	}
	if(count==0){
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"dispd_smooth_toggle1 timeout !!!\n");
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	}
	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
	modestate_set_display_timing_genByDisp(display);//set dvtotal
#endif

#ifdef ENABLE_VBY1_TO_HDMI_4K2K_DATA_FS
		if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
			drvif_framesync_gatting_do();
			drvif_framesync_gatting(_DISABLE);
			drvif_framesync_gatting(_ENABLE);

			if((Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI) ||
		(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)){
				modestate_set_fll_running_flag(_ENABLE);
			}
		}else{
		//	framesync_lastlinefinetune_at_new_mode();
		//	modestate_set_display_timing(ret);
			modestate_set_fll_running_flag(_ENABLE);

			if(Scaler_InputSrcGetType(display) == _SRC_TV){
				if(drvif_module_vdc_read_Clamping_path() && drvif_module_vdc_read_scan_flag()){
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"### ATV Channel Scan !!! ###\n");
					modestate_set_fll_running_flag(FALSE);
				}
			}
		}
#else
	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI){
		modestate_set_fll_running_flag(_DISABLE);
		modestate_set_display_timing(ret);
	}
	else{
		if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
			drvif_framesync_gatting(_DISABLE);
			drvif_framesync_gatting_do();
			drvif_framesync_gatting(_ENABLE);
		}else{
		//	framesync_lastlinefinetune_at_new_mode();
		//	modestate_set_display_timing(ret);
			#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
			if ((vbe_disp_get_adaptivestream_fs_mode() == 1) && (Get_DISPLAY_PANEL_TYPE() != P_LVDS_TO_HDMI))  {
				//drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
				modestate_set_fll_running_flag(_DISABLE);
			}else{

				if(vbe_disp_get_dynamic_memc_bypass_flag() == TRUE){
					rtd_printk(KERN_NOTICE, "VBE_DISP", "drv_memory_get_game_mode %d\n", drv_memory_get_game_mode_dynamic_flag());
					vbe_disp_game_mode_memc_bypass(drv_memory_get_game_mode_dynamic_flag());
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"######fw_set_vsc_GameMode(%d) Line=%d #######\n", drv_memory_get_game_mode_dynamic_flag(), __LINE__);
					fw_set_vsc_GameMode(drv_memory_get_game_mode_dynamic_flag());
				}

				if(drv_memory_get_game_mode()){
					fwif_color_safe_od_enable(0);
					modestate_set_fll_running_flag(_DISABLE);
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
					if(Get_DISPLAY_PANEL_OLED_TYPE()== TRUE){
						down(&Iv2dv_Slow_Tuning_Semaphore);
						drv_GameMode_iv2dv_delay(_ENABLE);
						up(&Iv2dv_Slow_Tuning_Semaphore);
					}else{
						drv_GameMode_iv2dv_delay(_ENABLE);
					}
					fwif_color_safe_od_enable(1);
				}else{
					modestate_set_fll_running_flag(_ENABLE);
				}
			}
			#else
				if(drv_memory_get_game_mode()){
					modestate_set_fll_running_flag(_DISABLE);
					if(Get_DISPLAY_PANEL_OLED_TYPE()== TRUE){
						down(&Iv2dv_Slow_Tuning_Semaphore);
						drv_GameMode_iv2dv_delay(_ENABLE);
						up(&Iv2dv_Slow_Tuning_Semaphore);
					}else{
						drv_GameMode_iv2dv_delay(_ENABLE);
					}
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
				}else{
					modestate_set_fll_running_flag(_ENABLE);
				}
			#endif

			if(Scaler_InputSrcGetType(display) == _SRC_TV){
				if(drvif_module_vdc_read_Clamping_path() && drvif_module_vdc_read_scan_flag()){
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"### ATV Channel Scan !!! ###\n");
					modestate_set_fll_running_flag(FALSE);
				}
			}
		}
	}

#endif
	if(drv_memory_get_game_mode_dynamic_flag())	//WOSQRTK-10203 need to do this early	(patch for QA stage)
		Scaler_MEMC_SetInOutFrameRate();


#if 0 // marked unused code in merlin by ben_wang
		if (modestate_decide_double_dvs_enable())
		{
			framesync_syncDoubleDVS(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
		}
		else
		{
	 		if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1){
				IoReg_ClearBits(PPOVERLAY_Display_Timing_CTRL1_reg, _BIT21);	//disable double dvs
	 		}
	 		else{
#if 0	//mag2 un-used dclk sel, move to dpll_o
	 			if(Get_DISPLAY_PORT() == 2)
	 			{
	 				drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
	 			}
	 			else{
				#if 0
	 				// Enable DMA clock sel when disable double dvs frank@04122011 add below for DMACLK
	 				if((GET_IS3DFMT() == 0 && GET_HDMI_3DTYPE() == HDMI3D_FRAMESEQUENCE) &&  Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
	 					&& ((Scaler_InputSrcGetMainChType() == _SRC_VO) ||((Scaler_InputSrcGetMainChType() == _SRC_HDMI)&& (Scaler_Get3DMode()== SLR_3DMODE_3D_AUTO)))){
	 					;
	 				}
	 				else
				#endif
					{
	 					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
	 				}
	 			}
#endif

			}
	 	}
#endif

		if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE())
			state_update_disp3d_info();

		if(_FALSE == Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
		{
		//	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE())
		//		state_update_disp3d_info();
			drvif_scaler_ddomain_switch_irq(_ENABLE);
		}
#ifdef CONFIG_DCLK_CHECK
		framesync_syncDoubleDVS_Frc_Tracking_Framesync(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), _DISABLE);
#endif //#ifdef CONFIG_DCLK_CHECK
		drvif_scalerdisplay_set_sharpness_line_mode();
		if(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)
		{
			drv_adjust_spreadspectrumrange(0);
		}

		// Add for PQ part by Hawaii 20150413
		if (!vpq_get_handler_bypass()) {
			fwif_color_handler();
			fwif_color_video_quality_handler();
			fwif_color_vpq_pic_init();
			fwif_color_SetAutoMAFlag(1);
			Scaler_Set_OD_Bit_By_XML();
		}
		/*
		if((Scaler_InputSrcGetType(display) == _SRC_VO) && ((get_HDMI_HDR_mode() != HDR_MODE_DISABLE) || (get_OTT_HDR_mode() != HDR_MODE_DISABLE) || ((IoReg_Read32(DOLBY_V_TOP_TOP_CTL_reg) & 7) != 0))){
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[DolbyVision] IGNORE VIP FOR DOLBY VISION\n");
			fwif_color_disable_VIP(_ENABLE);
		}*/
		// ======= Add for PQ part End ========

		if (Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE())
		{
			//USER : LewisLee DATE : 2012/11/07
			//only 3D mode need to apply all
			//to pevent 2D -> 3D -> 2D, set aspect ratio, the picture abnormal
			//so need to set scaler_2Dcvt3D_set_userEnableStatus(_FALSE)
			if(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)==SLR_3D_2D_CVT_3D)
			{
				scaler_2Dcvt3D_set_userEnableStatus(_ENABLE);
				scaler_2Dcvt3D_set_shifter(Scaler_Get2DCvt3D_Strength(), Scaler_Get2DCvt3D_Depth());
				scaler_2Dcvt3D_set_tilt_depth(scaler_2Dcvt3D_get_tilt_enable());

			}
			else
				scaler_2Dcvt3D_set_userEnableStatus(_DISABLE);
		}
#if 0 // ben move to modestate_set_display_timing
		if(Disp_Get_isForceFreeRun()==DISP_FREE_RUN)
		{
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
			dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
			vtotal= Get_DISP_VERTICAL_TOTAL(); /*(Get_DISPLAY_CLOCK_TYPICAL()/Get_DISP_HORIZONTAL_TOTAL()/Disp_Get_framerate());*/
			dv_total_reg.dv_total = vtotal-1;
			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
			printk("Disp_Get_isForceFreeRun:DVTotal:%x, 8014:%x\n", vtotal, IoReg_Read32(PPOVERLAY_DV_total_reg));
			disp_ForceFreeRun=DISP_TIMING_DEFAULT;
		}
#endif
		rtk_hal_vsc_GetOutputRegion(VIDEO_WID_0, &outregion);
		if (!((outregion.x == 0)&&(outregion.y == 0)&&(outregion.w == 0)&&(outregion.h == 0)) ){
#if 0//Move after memc
			if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE){
				unsigned int count = 20;
				cap_ddr_fifostatus_RBUS cap_ddr_fifostatus_reg;
				/*check memory cap down*/
				cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
				while(!(cap_ddr_fifostatus_reg.in1_cap_last_wr_flag) && --count){
					cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
					mdelay(10);
				}
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"M domain done\n");
				if(count==0)
					pr_err("M domain timeout !\n");
			}
#endif
			down(get_forcebg_semaphore());
			drvif_scalerdisplay_enable_display(SLR_MAIN_DISPLAY, _ENABLE);
			up(get_forcebg_semaphore());

			//first boot run Main done
			if(first_boot_run_main == FALSE){
				first_boot_run_main = TRUE;
			}
		}
	} else if ((SCALER_DISP_CHANNEL)display == SLR_SUB_DISPLAY) {
#if 0//Move after memc
		if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE){
			unsigned int count = 10;
			cap_ddr_fifostatus_RBUS cap_ddr_fifostatus_reg;
			/*check memory cap down*/
			cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
			while(!(cap_ddr_fifostatus_reg.in2_cap_last_wr_flag) && count--){
				cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
				mdelay(10);
			}
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Sub M domain done\n");
			if(count==0)
				pr_err("Sub M domain timeout !\n");
		}
#endif
		//if first run sub path, it should set disp timing. @Crixus 20151230
		//sync benwang:for k3lp project no mutilview case, remove (drvif_scalerdisplay_get_force_bg_status()) condition for livezoom sub no need set timing(qiangzhou20161104)
		if((first_boot_run_main == FALSE)/*||(drvif_scalerdisplay_get_force_bg_status())*/){
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"First boot run Sub!!!!\n");
#if 0
			modestate_disp_flow_double_buf_enable(_ENABLE);
			modestate_set_display_timing_genByDisp(display);//set dvtotal
			modestate_set_display_timing_gen_clock_div();
			modestate_set_fractional_framesync();
#ifndef CONFIG_MEMC_BYPASS	//bypass memc rzhen@2016-06-29
			//add ME protection when change frame rate @Crixus 20151221
			if((IoReg_Read32(me_04_write_enable_ADDR) & _BIT20) || (IoReg_Read32(me_05_write_enable_ADDR) & _BIT20)){
				me_protection_flag = 1;//if ME si disable, not to protect.
			}
			if(me_protection_flag == 1){
				IoReg_ClearBits(me_04_write_enable_ADDR, _BIT20);
				IoReg_ClearBits(me_05_write_enable_ADDR, _BIT20);
				IoReg_SetBits(KME_ME1_TOP1__ME1_SCENE1_00_ADDR, _BIT0);
				WaitFor_DEN_STOP();
				WaitFor_DEN_STOP();
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn off me4.5 ok in disp_setting\n");
			}
			modestate_disp_flow_double_buf_apply();
			modestate_disp_flow_double_buf_enable(_DISABLE);
			if(me_protection_flag == 1){
				IoReg_ClearBits(KME_ME1_TOP1__ME1_SCENE1_00_ADDR, _BIT0);
				IoReg_SetBits(me_04_write_enable_ADDR, _BIT20);
				IoReg_SetBits(me_05_write_enable_ADDR, _BIT20);
				WaitFor_DEN_STOP();
				me_protection_flag = 0;
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn on me4.5 ok in disp_setting\n");
			}
#endif
#else
			down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			//double buffer D0
			spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			double_buffer_ctrl_reg.dreg_dbuf_en = 0;
			double_buffer_ctrl_reg.drm_multireg_dbuf_en = 1;
			double_buffer_ctrl_reg.drm_multireg_dbuf_read_sel = 1;
			double_buffer_ctrl_reg.drm_multireg_dbuf_vsync_sel = 1;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
			spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
			up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
			ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
			ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);

			drivf_scaler_reset_freerun();

			//pre-flow. patch, let D8 double buffer works well
			count = 0x3fffff;
			while((count == 0x3fffff)&&(mul_dbuf_cnt<10000)){
				//msleep(10);
				down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
				double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
				IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
				up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
				count = 0x3fffff;
				double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count){
					double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				}
				if(count==0){
					rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 1 wait timeout !!!\n");
				}
				mul_dbuf_cnt++;
			}
			modestate_set_fractional_framesyncByDisp(display);

			count = 0x3fffff;
			while((count == 0x3fffff)&&(mul_dbuf_cnt2<10000)){
				down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
				double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
				IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
				up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
				count = 0x3fffff;
				double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count){
					double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
				}
				if(count==0){
					rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 2 wait timeout !!!\n");
				}
				mul_dbuf_cnt2++;
			}
			modestate_set_display_timing_gen_clock_divByDisp(display);
			count = 0x3fffff;
			dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=0;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);

			dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
			while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply)&& --count){
				dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
			}
			if(count==0){
				rtd_printk(KERN_EMERG, TAG_NAME_VBE,"dispd_smooth_toggle1 timeout !!!\n");
				dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
				IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
				dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
				dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
				IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
				dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
				IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			}
			ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
			ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
			ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
			modestate_set_display_timing_genByDisp(display);//set dvtotal

#endif

#ifdef ENABLE_VBY1_TO_HDMI_4K2K_DATA_FS
			if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
				drvif_framesync_gatting_do();
				drvif_framesync_gatting(_DISABLE);
				drvif_framesync_gatting(_ENABLE);
				if((Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI) ||
					(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)){
					modestate_set_fll_running_flag(_ENABLE);
				}
			}else{
				modestate_set_fll_running_flag(_ENABLE);
				if(Scaler_InputSrcGetType(display) == _SRC_TV){
					if(drvif_module_vdc_read_Clamping_path() && drvif_module_vdc_read_scan_flag()){
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"### ATV Channel Scan !!! ###\n");
						modestate_set_fll_running_flag(FALSE);
					}
				}
			}
#else
		if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI){
			modestate_set_fll_running_flag(_DISABLE);
			modestate_set_display_timing(ret);
		}
		else{
			if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)){
				drvif_framesync_gatting_do();
				drvif_framesync_gatting(_DISABLE);
				drvif_framesync_gatting(_ENABLE);
			}else{
			#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
				if(vbe_disp_get_adaptivestream_fs_mode()){
					modestate_set_fll_running_flag(_DISABLE);
					fwif_color_safe_od_enable(0);
					drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
					fwif_color_safe_od_enable(1);
				}else{
					modestate_set_fll_running_flag(_ENABLE);
				}
			#else
				modestate_set_fll_running_flag(_ENABLE);
			#endif
				if(Scaler_InputSrcGetType(display) == _SRC_TV){
					if(drvif_module_vdc_read_Clamping_path() && drvif_module_vdc_read_scan_flag()){
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"### ATV Channel Scan !!! ###\n");
						modestate_set_fll_running_flag(FALSE);
					}
				}
			}
		}

#endif

	if(drv_memory_get_game_mode_dynamic_flag())	//WOSQRTK-10203 need to do this early	(patch for QA stage)
		Scaler_MEMC_SetInOutFrameRate();

			//if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE())
				//state_update_disp3d_info();

			if(_FALSE == Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
			{
				drvif_scaler_ddomain_switch_irq(_ENABLE);
			}
#ifdef CONFIG_DCLK_CHECK
			framesync_syncDoubleDVS_Frc_Tracking_Framesync(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), _DISABLE);
#endif //#ifdef CONFIG_DCLK_CHECK
			drvif_scalerdisplay_set_sharpness_line_mode();
			if(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)
			{
				drv_adjust_spreadspectrumrange(0);
			}

		}
		down(get_forcebg_semaphore());
		drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _ENABLE);
		up(get_forcebg_semaphore());
		drvif_color_setpiprgbcontrastbrightness(0);
	}
	up(&VBE_Semaphore);
}

unsigned int scaler_disp_smooth_get_memc_protect_vtotal(void)
	{
		unsigned char pixelMode=0;
		ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
//		dv_total_RBUS dv_total_reg;
//		uzudtg_dv_total_RBUS uzudtg_dv_total_reg;
//		memcdtg_dv_total_RBUS memcdtg_dv_total_reg;
		UINT32 vFreq=0;
		unsigned int vertical_total=0;

		display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
		pixelMode = 0; //display_timing_ctrl2_reg.dout_pixel_mode;
		vFreq = Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ);

		if((vFreq>235)&&(vFreq<=245)){	//24hz
			if(pixelMode==1){ // 120hz panel
				vertical_total = 2245;
			}else{	//	60hz panel, 24hz to 48hz
				vertical_total = 2809;
			}
		}else if((vFreq>245)&&(vFreq<=255)){ // 25hz
			vertical_total = 2700;
		}else if((vFreq>295)&&(vFreq<=305)){ // 30hz
				vertical_total = 2245;
		}else if((vFreq>495)&&(vFreq<=505)){ // 50hz
			vertical_total = 2700;
		}else if((vFreq>595)&&(vFreq<=605)){ // 60hz
			if(pixelMode==1){	 // 120hz panel
				vertical_total = 2245;
			}
		}else{
			vertical_total = 0;
		}

		if(Get_DISP_VERTICAL_TOTAL() <= 1125){ // 2k panel
			vertical_total = vertical_total * Get_DISP_VERTICAL_TOTAL() / 2250;
		}

		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] protect vtotal=%d\n", __FUNCTION__, vertical_total);
		return vertical_total;


	}


void scaler_disp_smooth_variable_setting()
{
	unsigned char frame_idicator=0;
	unsigned char b_run_frame_check=0;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
	ppoverlay_dtg_frame_cnt1_RBUS dtg_frame_cnt1_reg;
	unsigned int count = 0x3fffff;
	unsigned char me_protection_flag = 0;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
	ppoverlay_dispd_smooth_toggle1_RBUS	 dispd_smooth_toggle1_reg;

	if(vbe_disp_get_adaptivestream_fs_mode() == 1){
		Scaler_MEMC_SetInOutFrameRate();
		return;
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scaler_disp_smooth_variable_setting\n");
	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

	if(Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_MULTIPLE_RATIO) > 1){
		b_run_frame_check = 1;
		frame_idicator = Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_MULTIPLE_RATIO)-1;
	}

	modestate_decide_pixel_mode();
	modestate_decide_dtg_m_mode();
	modestate_decide_fractional_framesync();
	#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if(vbe_disp_get_adaptivestream_fs_mode() == 0){
		drivf_scaler_reset_freerun();
	}
	#else
	drivf_scaler_reset_freerun();
	#endif
	modestate_disp_flow_double_buf_enable(_ENABLE);
	//modestate_set_display_timing_gen();
	modestate_set_display_timing_gen_clock_div();
	modestate_set_fractional_framesync();

	if(Scaler_DispGetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ) == 60)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"######## 48Hz to 60HZ #############\n");
	else if(Scaler_DispGetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ) == 48)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"######## 60Hz to 48HZ #############\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"decide frame_idicator:%d\n", frame_idicator);

#if 0
	/*remove unused memc protect code*/
	//add ME protection when change frame rate @Crixus 20151221
	if((IoReg_Read32(me_04_write_enable_ADDR) & _BIT20) || (IoReg_Read32(me_05_write_enable_ADDR) & _BIT20)){
		me_protection_flag = 1;//if ME is disable, not to protect.
	}
	if(me_protection_flag == 1){
		//disable ME DMA
		IoReg_ClearBits(me_04_write_enable_ADDR, _BIT20);
		IoReg_ClearBits(me_05_write_enable_ADDR, _BIT20);
		IoReg_SetBits(KME_ME1_TOP1__ME1_SCENE1_00_ADDR, _BIT0);
		WaitFor_DEN_STOP();
		WaitFor_DEN_STOP();
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn off me4.5 ok in smooth setting\n");
	}
#endif
	if(b_run_frame_check == 1){
		dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= (frame_idicator-1))&& --count){
			dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		}
		count = 0x3fffff;
		//make sure that we can have a full porch apply timing change settings
		while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= frame_idicator)&& --count){
			dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		}
		if(count == 0)
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"count timeout !!!\n");
		//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"++frame_idicator:%d\n", (IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);
	}else{
		ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_reg;
		new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		while((new_meas1_linecnt_real_reg.memcdtg_line_cnt_rt > 200)&& --count){
			new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		}
	}
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	modestate_set_fractional_framesync();
	fw_scaler_dtg_double_buffer_apply();
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"--- 1frame_idicator:%d\n",(IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);

    	count = 0x3fffff;
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	while((double_buffer_ctrl_reg.dreg_dbuf_set)&& --count){
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	}
	if(count==0){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"double buffer timeout !!!\n");
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"--- 2frame_idicator:%d\n",(IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);

	count = 0x3fffff;
	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply)&& --count){
		dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	}
	if(count==0){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"dispd_smooth_toggle1 timeout !!!\n");
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	}else{
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
	}
	modestate_disp_flow_double_buf_enable(_DISABLE);
	modestate_set_display_timing_gen();//set dvtotal

#if 0
		/*remove unused memc protect code*/
	if(me_protection_flag == 1){
		IoReg_ClearBits(KME_ME1_TOP1__ME1_SCENE1_00_ADDR, _BIT0);
		IoReg_SetBits(me_04_write_enable_ADDR, _BIT20);
		IoReg_SetBits(me_05_write_enable_ADDR, _BIT20);
		WaitFor_DEN_STOP();
		me_protection_flag = 0;
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn on me4.5 ok in smooth setting\n");
	}
#endif
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"--- 3frame_idicator:%d\n",(IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);

#ifdef CONFIG_MEMC_BYPASS
	// do nothing.
#else
	Scaler_MEMC_SetInOutFrameRate();
#endif

	#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if(vbe_disp_get_adaptivestream_fs_mode() == 0){
		modestate_set_fll_running_flag(_ENABLE);
	}else{
		fwif_color_safe_od_enable(0);
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
		fwif_color_safe_od_enable(1);
	}

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]P_VBY1_TO_HDMI=FRC\n",__FUNCTION__,__LINE__);
		modestate_set_fll_running_flag(_DISABLE);
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
	}
	#else
	modestate_set_fll_running_flag(_ENABLE);
	#endif

}

void scaler_disp_smooth_variable_setting_slow(void)
{
	SCALER_DISP_CHANNEL _channel = 0;
	unsigned int count = 0x3fffff;
	unsigned int count2 = 0x3fffff;
	ppoverlay_new_meas1_linecnt_real_RBUS ppoverlay_new_meas1_linecnt_real_reg;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;
	ppoverlay_dispd_smooth_toggle1_RBUS	 dispd_smooth_toggle1_reg;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
	UINT32 mul_dbuf_cnt=0;
	UINT32 mul_dbuf_cnt2=0;
	UINT32 meas0_lineCnt1=0;
	UINT32 meas0_lineCnt2=0;
	UINT32 meas0_lineCnt3=0;
	UINT32 meas1_lineCnt1=0;
	UINT32 meas1_lineCnt2=0;
	UINT32 meas1_lineCnt3=0;
	unsigned long flags;//for spin_lock_irqsave

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"scaler_disp_smooth_variable_setting_slow\n");

	//modestate_decide_pixel_mode();
	//modestate_decide_dtg_m_modeByDisp(_channel);
	//modestate_decide_fractional_framesyncByDisp(_channel);

	//if(vbe_disp_decide_memc_mux_bypass() == FALSE)
		//Scaler_MEMC_Bypass_On(0);

	drivf_scaler_reset_freerun();

	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	//double buffer D0
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	double_buffer_ctrl_reg.dreg_dbuf_en = 0;
	double_buffer_ctrl_reg.drm_multireg_dbuf_en = 1;
	double_buffer_ctrl_reg.drm_multireg_dbuf_read_sel = 1;
	double_buffer_ctrl_reg.drm_multireg_dbuf_vsync_sel = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
#if 1
	//pre-flow. patch, let D8 double buffer works well
	count = 0x3fffff;
	while((count == 0x3fffff)&&(mul_dbuf_cnt<10000)){
		//msleep(10);
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
		//meas0_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
		//meas1_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		count = 0x3fffff;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count){
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		}
		if(count==0){
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 1 wait timeout !!!\n");
		}
		if(double_buffer_ctrl_reg.drm_multireg_dbuf_en==0)
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_en=0 1!!\n");

		//meas0_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
		//meas1_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		mul_dbuf_cnt++;
	}
#endif
	modestate_set_fractional_framesyncByDisp(_channel);

	count2 = 0x3fffff;
	while((count2 == 0x3fffff)&&(mul_dbuf_cnt2<10000)){
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
		meas0_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
		meas1_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		count2 = 0x3fffff;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count2){
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
			meas0_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
			meas1_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
			//if(double_buffer_ctrl_reg.regValue != 0x40007000){
				//dbg_val_1 = double_buffer_ctrl_reg.regValue;
				//dbg_val_2 = IoReg_Read32(0xb8000208);
				//dbg_val_3 = IoReg_Read32(0xb802847c);
				//break;
			//}
		}
		if(count2==0){
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 2 wait timeout !!!\n");
		}
//		meas0_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
//		meas1_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		mul_dbuf_cnt2++;
	}
	modestate_set_display_timing_gen_clock_divByDisp(_channel);
	count = 0x3fffff;

	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=0;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);

	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply)&& --count){
		dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	}
	if(count==0){
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"dispd_smooth_toggle1 timeout !!!\n");
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	}
	meas0_lineCnt3 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
	meas1_lineCnt3 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);

	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
	modestate_set_display_timing_genByDisp(_channel);//set dvtotal
/*
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas0_lineCnt1 (%x)\n", meas0_lineCnt1);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas1_lineCnt1 (%x)\n", meas1_lineCnt1);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas0_lineCnt2 (%x)\n", meas0_lineCnt2);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas1_lineCnt2 (%x)\n", meas1_lineCnt2);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas0_lineCnt3 (%x)\n", meas0_lineCnt3);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas1_lineCnt3 (%x)\n", meas1_lineCnt3);
*/
}

void scaler_disp_smooth_variable_setting_fast(void)
{
	SCALER_DISP_CHANNEL channel = 0;
	unsigned char frame_idicator=0;
	unsigned char b_run_frame_check=0;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
	ppoverlay_dtg_frame_cnt1_RBUS dtg_frame_cnt1_reg;
	unsigned int count = 0x3fffff;
	unsigned char me_protection_flag = 0;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;
	ppoverlay_dispd_smooth_toggle1_RBUS	 dispd_smooth_toggle1_reg;
	unsigned long flags;//for spin_lock_irqsave
	ppoverlay_uzudtg_fractional_fsync_RBUS uzudtg_fractional_fsync_reg;

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"scaler_disp_smooth_variable_setting_fast\n");
	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

	uzudtg_fractional_fsync_reg.regValue = IoReg_Read32(PPOVERLAY_uzudtg_fractional_fsync_reg);
	if(uzudtg_fractional_fsync_reg.uzudtg_remove_half_ivs_mode>0){
		b_run_frame_check = 1;
		frame_idicator = uzudtg_fractional_fsync_reg.uzudtg_remove_half_ivs_mode;
	}

	//modestate_decide_pixel_mode();
	//modestate_decide_dtg_m_modeByDisp(channel);
	//modestate_decide_fractional_framesyncByDisp(channel);
	drivf_scaler_reset_freerun();

	modestate_set_display_timing_gen_clock_divByDisp(channel);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"decide frame_idicator:%d\n", frame_idicator);

	if(b_run_frame_check == 1){
		dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= (frame_idicator-1))&& --count){
			dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		}
		count = 0x3fffff;
		//make sure that we can have a full porch apply timing change settings
		while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= frame_idicator)&& --count){
			dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		}
		if(count == 0)
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"count timeout !!!\n");
	}else{
		ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_reg;
		new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		while(((new_meas1_linecnt_real_reg.uzudtg_line_cnt_rt>200)||(new_meas1_linecnt_real_reg.uzudtg_line_cnt_rt<100))&& --count){
			new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		}
	}
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);

	//local_irq_disable();
	//preempt_disable();
	modestate_disp_flow_double_buf_enable(_ENABLE);
	fw_scaler_dtg_double_buffer_apply();
	count = 0x3fffff;
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	while((double_buffer_ctrl_reg.dreg_dbuf_set)&& --count){
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	}
	if(count==0){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"double buffer timeout !!!\n");
	}
	count = 0x3fffff;
	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply)&& --count){
		dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	}
	if(count==0){
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"dispd_smooth_toggle1 timeout !!!\n");
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	}else{
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
	}
	count = 0x3fffff;
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	double_buffer_ctrl_reg.dmainreg_dbuf_en = 0;
	double_buffer_ctrl_reg.dmainreg_dbuf_set = 0;
	double_buffer_ctrl_reg.dreg_dbuf_en = 0;
	double_buffer_ctrl_reg.dreg_dbuf_set = 0;
	double_buffer_ctrl_reg.drm_multireg_dbuf_en = 0;
	double_buffer_ctrl_reg.drm_multireg_dbuf_set = 0;
	double_buffer_ctrl_reg.drm_multireg_dbuf_vsync_sel = 0;
	double_buffer_ctrl_reg.dsubreg_dbuf_en = 0;
	double_buffer_ctrl_reg.dsubreg_dbuf_set = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	//ppoverlay_double_buffer_ctrl2_reg.osddtgreg_dbuf_en = 0;
	//ppoverlay_double_buffer_ctrl2_reg.osddtgreg_dbuf_set = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_set = 0;
	ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.memc_dtgreg_dbuf_set = 0;
	//ppoverlay_double_buffer_ctrl2_reg.osddtg_dbuf_vsync_sel = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtg_dbuf_vsync_sel = 0;
	ppoverlay_double_buffer_ctrl2_reg.memcdtg_dbuf_vsync_sel = 0;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
	modestate_set_fractional_framesyncByDisp(channel);
	modestate_set_display_timing_genByDisp(channel);//set dvtotal
	//local_irq_enable();
	//preempt_enable();
}

extern struct semaphore* get_double_buffer_semaphore(void);
void scaler_disp_smooth_variable_settingByDisp(unsigned char _channel)
{
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
	UINT32 dclk_fract_a_new, dclk_fract_b_new, dclk_factor_new;
	UINT32 dclk_fract_a_current, dclk_fract_b_current, dclk_factor_current;

	if((Scaler_DispGetInputInfoByDisp(_channel,SLR_INPUT_V_FREQ) > 475) &&
				(Scaler_DispGetInputInfoByDisp(_channel,SLR_INPUT_V_FREQ) < 485)){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"48Hz input is not support.\n");
		return;
	}

	if(vbe_disp_get_adaptivestream_fs_mode() == 1){
		Scaler_MEMC_SetInOutFrameRate();
		return;
	}

	modestate_decide_pixel_mode();
	modestate_decide_dtg_m_modeByDisp(_channel);
	modestate_decide_fractional_framesyncByDisp(_channel);

	if(vbe_disp_decide_memc_mux_bypass() == FALSE)
		Scaler_MEMC_Bypass_On(0);

	dclk_fract_a_new = Scaler_DispGetInputInfoByDisp(0,SLR_INPUT_FRAC_FS_REMOVE_RATIO)-1;
	dclk_fract_b_new = Scaler_DispGetInputInfoByDisp(0,SLR_INPUT_FRAC_FS_MULTIPLE_RATIO)-1;
	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL)
		dclk_fract_a_new = (Scaler_DispGetInputInfoByDisp(0,SLR_INPUT_FRAC_FS_REMOVE_RATIO)*2)-1;
	else
		dclk_fract_a_new = Scaler_DispGetInputInfoByDisp(0,SLR_INPUT_FRAC_FS_REMOVE_RATIO)-1;
	dclk_factor_new = ((dclk_fract_a_new+1)*1000 / (dclk_fract_b_new+1));

	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	dclk_fract_a_current = sys_dispclksel_reg.dclk_fract_a;
	dclk_fract_b_current = sys_dispclksel_reg.dclk_fract_b;
	dclk_factor_current = ((dclk_fract_a_current+1)*1000 / (dclk_fract_b_current+1));

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"clk current (a:%d)(b:%d)(factor:%d)\n", dclk_fract_a_current, dclk_fract_b_current, dclk_factor_current);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"clk new (a:%d)(b:%d)(factor:%d)\n", dclk_fract_a_new, dclk_fract_b_new, dclk_factor_new);
#if 0
	//real cinema mode + true motion off
	if((Scaler_DispGetInputInfoByDisp(_channel,SLR_INPUT_V_FREQ) > 235) &&
			(Scaler_DispGetInputInfoByDisp(_channel,SLR_INPUT_V_FREQ) < 245)){
		scaler_disp_smooth_variable_setting_slow();
	}else{
		if(dclk_factor_current > dclk_factor_new) // change slow
			scaler_disp_smooth_variable_setting_slow();
		else
			scaler_disp_smooth_variable_setting_fast();
	}
#else

	if((dclk_factor_new/dclk_factor_current)>1){ // dclk change fast
		scaler_disp_smooth_variable_setting_fast();
	} else {
		down(get_double_buffer_semaphore());
		scaler_disp_smooth_variable_setting_slow();
		up(get_double_buffer_semaphore());
	}
#endif
	Scaler_MEMC_SetInOutFrameRateByDisp(_channel);/*checked*/
	modestate_set_fll_running_flag(_ENABLE);

	if(vbe_disp_decide_memc_mux_bypass() == TRUE)
		Scaler_MEMC_Bypass_On(1);

#if 0
	SCALER_DISP_CHANNEL channel = _channel;
	unsigned char frame_idicator=0;
	unsigned char b_run_frame_check=0;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
	ppoverlay_dtg_frame_cnt1_RBUS dtg_frame_cnt1_reg;
	unsigned int count = 0x3fffff;
	unsigned char me_protection_flag = 0;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;
	ppoverlay_dispd_smooth_toggle1_RBUS	 dispd_smooth_toggle1_reg;

	if(vbe_disp_get_adaptivestream_fs_mode() == 1){
		Scaler_MEMC_SetInOutFrameRate();
		return;
	}
#if 0
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scaler_disp_smooth_variable_setting\n");
	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

	if(Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_FRAC_FS_MULTIPLE_RATIO) > 1){
		b_run_frame_check = 1;
		frame_idicator = Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_FRAC_FS_MULTIPLE_RATIO)-1;
	}

	modestate_decide_pixel_mode();
	modestate_decide_dtg_m_modeByDisp(_channel);
	modestate_decide_fractional_framesyncByDisp(_channel);
#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if(vbe_disp_get_adaptivestream_fs_mode() == 0){
		drivf_scaler_reset_freerun();
	}
#else
	drivf_scaler_reset_freerun();
#endif
	modestate_disp_flow_double_buf_enable(_ENABLE);
	//modestate_set_display_timing_gen();
	modestate_set_display_timing_gen_clock_divByDisp(_channel);
	modestate_set_fractional_framesyncByDisp(_channel);

	if(Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_DTG_MASTER_V_FREQ) == 60)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"######## 48Hz to 60HZ #############\n");
	else if(Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_DTG_MASTER_V_FREQ) == 48)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"######## 60Hz to 48HZ #############\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"decide frame_idicator:%d\n", frame_idicator);

	//add ME protection when change frame rate @Crixus 20151221
	if((IoReg_Read32(me_04_write_enable_ADDR) & _BIT20) || (IoReg_Read32(me_05_write_enable_ADDR) & _BIT20)){
		me_protection_flag = 1;//if ME is disable, not to protect.
	}
	if(me_protection_flag == 1){
		//disable ME DMA
		IoReg_ClearBits(me_04_write_enable_ADDR, _BIT20);
		IoReg_ClearBits(me_05_write_enable_ADDR, _BIT20);
		IoReg_SetBits(KME_ME_TOP1__REG_METOP_SC_CLR_SAD_EN_ADDR, _BIT10);
		WaitFor_DEN_STOP();
		WaitFor_DEN_STOP();
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn off me4.5 ok in smooth setting\n");
	}

	if(b_run_frame_check == 1){
		dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= (frame_idicator-1))&& --count){
			dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		}
		count = 0x3fffff;
		//make sure that we can have a full porch apply timing change settings
		while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= frame_idicator)&& --count){
			dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
		}
		if(count == 0)
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"count timeout !!!\n");
		//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"++frame_idicator:%d\n", (IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);
	}else{
		ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_reg;
		new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		while((new_meas1_linecnt_real_reg.memcdtg_line_cnt_rt > 200)&& --count){
			new_meas1_linecnt_real_reg.regValue = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		}
	}
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	modestate_set_fractional_framesyncByDisp(_channel);
	fw_scaler_dtg_double_buffer_apply();
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"--- 1frame_idicator:%d\n",(IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);

	count = 0x3fffff;
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	while((double_buffer_ctrl_reg.dreg_dbuf_set)&& --count){
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	}
	if(count==0){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"double buffer timeout !!!\n");
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"--- 2frame_idicator:%d\n",(IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);

	count = 0x3fffff;
	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply)&& --count){
		dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	}
	if(count==0){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"dispd_smooth_toggle1 timeout !!!\n");
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	}else{
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
	}
	modestate_disp_flow_double_buf_enable(_DISABLE);
	modestate_set_display_timing_genByDisp(_channel);//set dvtotal

	if(me_protection_flag == 1){
		IoReg_ClearBits(KME_ME_TOP1__REG_METOP_SC_CLR_SAD_EN_ADDR, _BIT10);
		IoReg_SetBits(me_04_write_enable_ADDR, _BIT20);
		IoReg_SetBits(me_05_write_enable_ADDR, _BIT20);
		WaitFor_DEN_STOP();
		me_protection_flag = 0;
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"turn on me4.5 ok in smooth setting\n");
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"--- 3frame_idicator:%d\n",(IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);
	Scaler_MEMC_SetInOutFrameRateByDisp(_channel);/*checked*/
#ifdef SMOOTH_TOGGLE_DATAFRCFS_TEST
	if(vbe_disp_get_adaptivestream_fs_mode() == 0){
		modestate_set_fll_running_flag(_ENABLE);
	}else{
		drvif_scaler_set_display_modeByDisp(DISPLAY_MODE_FRAME_SYNC,_channel);
	}

	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI){
		modestate_set_fll_running_flag(_DISABLE);
		drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
	}
#else
	modestate_set_fll_running_flag(_ENABLE);
#endif

#else
	UINT32 meas0_lineCnt1=0;
	UINT32 meas0_lineCnt2=0;
	UINT32 meas0_lineCnt3=0;
	UINT32 meas1_lineCnt1=0;
	UINT32 meas1_lineCnt2=0;
	UINT32 meas1_lineCnt3=0;
	UINT32 mul_dbuf_cnt=0;
	UINT32 mul_dbuf_cnt2=0;
	UINT32 db_val=0;
	ppoverlay_new_meas1_linecnt_real_RBUS ppoverlay_new_meas1_linecnt_real_reg;

	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"scaler_disp_smooth_variable_setting\n");

	modestate_decide_pixel_mode();
	modestate_decide_dtg_m_modeByDisp(_channel);
	modestate_decide_fractional_framesyncByDisp(_channel);

	if(vbe_disp_decide_memc_mux_bypass() == FALSE)
		Scaler_MEMC_Bypass_On(0);

	//double buffer D0
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	double_buffer_ctrl_reg.dreg_dbuf_en = 0;
	double_buffer_ctrl_reg.drm_multireg_dbuf_en = 1;
	double_buffer_ctrl_reg.drm_multireg_dbuf_read_sel = 1;
	double_buffer_ctrl_reg.drm_multireg_dbuf_vsync_sel = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
 	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);

	drivf_scaler_reset_freerun();

	//pre-flow. patch, let D8 double buffer works well
	count = 0x3fffff;
	while((count == 0x3fffff)&&(mul_dbuf_cnt<10000)){
		//msleep(10);
		double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
		meas0_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
		meas1_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		count = 0x3fffff;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count){
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		}
		if(count==0){
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 1 wait timeout !!!\n");
		}
		meas0_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
		meas1_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		mul_dbuf_cnt++;
	}
	modestate_set_fractional_framesyncByDisp(_channel);

	count = 0x3fffff;
	while((count == 0x3fffff)&&(mul_dbuf_cnt2<10000)){
		double_buffer_ctrl_reg.drm_multireg_dbuf_set = 1;
		meas0_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
		meas1_lineCnt1 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, double_buffer_ctrl_reg.regValue);
		count = 0x3fffff;
		double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		while((double_buffer_ctrl_reg.drm_multireg_dbuf_set)&& --count){
			double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
		}
		if(count==0){
			rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[double buffer] drm_multireg_dbuf_set 2 wait timeout !!!\n");
		}
		meas0_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
		meas1_lineCnt2 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);
		mul_dbuf_cnt2++;
	}

	modestate_set_display_timing_gen_clock_divByDisp(_channel);
	count = 0x3fffff;

	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=0;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);

	dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply)&& --count){
		dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
	}
	if(count==0){
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"dispd_smooth_toggle1 timeout !!!\n");
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
		dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
		dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
		IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
		dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
		IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	}
	meas0_lineCnt3 = IoReg_Read32(PPOVERLAY_new_meas0_linecnt_real_reg);
	meas1_lineCnt3 = IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg);

	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	ppoverlay_double_buffer_ctrl2_reg.memcdtgreg_dbuf_en = 0;
	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 0;
 	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
	db_val = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	modestate_set_display_timing_genByDisp(_channel);//set dvtotal
	Scaler_MEMC_SetInOutFrameRateByDisp(_channel);/*checked*/
	modestate_set_fll_running_flag(_ENABLE);

	if(vbe_disp_decide_memc_mux_bypass() == TRUE)
		Scaler_MEMC_Bypass_On(1);


#if 0
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas0_lineCnt1 (%x)\n", meas0_lineCnt1);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas1_lineCnt1 (%x)\n", meas1_lineCnt1);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas0_lineCnt2 (%x)\n", meas0_lineCnt2);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas1_lineCnt2 (%x)\n", meas1_lineCnt2);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas0_lineCnt3 (%x)\n", meas0_lineCnt3);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"meas1_lineCnt3 (%x)\n", meas1_lineCnt3);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"mul_dbuf_cnt (%x)\n", mul_dbuf_cnt);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"mul_dbuf_cnt2 (%x)\n", mul_dbuf_cnt2);
	rtd_printk(KERN_EMERG, TAG_NAME_VBE,"db_val (%x)\n", db_val);
#endif

#endif
#endif
}

extern platform_info_t platform_info;
unsigned char HAL_VBE_DISP_Initialize(DISP_PANEL_INFO_T panelInfo)
{
	unsigned char ret=1;
	unsigned long result =0;
	VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *config_data;
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;
	PANEL_CONFIG_PARAMETER parameter;
	sfg_sfg_zz_shift_dbg_ctrl_RBUS sfg_zz_shift_dbg_ctrl_reg;
	pif_lvds_ctrl3_RBUS  lvds_ctrl3;
	pif_lvds_ctrl0_RBUS lvds_ctrl0;

	down(&VBE_Semaphore);

#if 0
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]HAL_VBE_DISP_Initialize###\n");
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.panel_inch = %x\n", panelInfo.panel_inch);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.panel_bl_type = %x\n", panelInfo.panel_bl_type);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.panel_maker = %x\n", panelInfo.panel_maker);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.led_bar_type = %x\n", panelInfo.led_bar_type);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.panelInterface = %x\n", panelInfo.panelInterface);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.panelResolution = %x\n", panelInfo.panelResolution);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.panel_version = %x\n", panelInfo.panel_version);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.frc_type = %x\n", panelInfo.frc_type);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.cell_type = %x\n", panelInfo.cell_type);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.disp_out_resolution = %x\n", panelInfo.disp_out_resolution);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.lvds_bit_mode = %x\n", panelInfo.lvds_bit_mode);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.lvds_type = %x\n", panelInfo.lvds_type);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.disp_out_lane_bw = %x\n", panelInfo.disp_out_lane_bw);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.panelFrameRate = %x\n", panelInfo.panelFrameRate);
 rtd_printk(KERN_EMERG, TAG_NAME_VBE, "####[KERN]panelInfo.user_specific_option = %x\n", panelInfo.user_specific_option);
#endif

	if(VBE_DISP_Global_Status != VBE_DISP_NOTHING){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"KERN_INFO \r\n VBE_DISP_Initialize has initialized.\n");
		up(&VBE_Semaphore);
		return ret;
	}
#if 1 // ben mark it@ restruct disp info not sync with webos
	memset(&parameter,0,sizeof(PANEL_CONFIG_PARAMETER));

	parameter.iCONFIG_DISP_ACT_STA_HPOS=0;
	parameter.iCONFIG_DISP_ACT_END_HPOS=panelInfo.disp_out_resolution.video_width;
	parameter.iCONFIG_DISP_ACT_STA_VPOS=0;
	parameter.iCONFIG_DISP_ACT_END_VPOS=panelInfo.disp_out_resolution.video_height;
	parameter.iCONFIG_DISPLAY_COLOR_BITS=(panelInfo.lvds_bit_mode)?0:1;  //panelInfo.lvds_bit_mode 0 is 8bit,1 is 10bit
	parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE=(panelInfo.lvds_type)?0:1;  //panelInfo.lvds_type 0 is VESA,1 is JEIDA

	lvds_ctrl0.regValue = IoReg_Read32(PIF_LVDS_CTRL0_reg);
	if(panelInfo.panelInterface==DISP_PANEL_EPI)
	{
		parameter.iCONFIG_PANEL_TYPE=P_EPI_TYPE;
		lvds_ctrl0.plt_lvds_mode=2;    //EPI-mode
	}
	else
	{
		parameter.iCONFIG_PANEL_TYPE=P_LVDS_2K1K;
		lvds_ctrl0.plt_lvds_mode=0;    //LVDS-mode
	}
	//IoReg_Write32(PIF_LVDS_CTRL0_reg, lvds_ctrl0.regValue);

	Set_PANEL_BL_type(panelInfo.panel_bl_type);
	Set_PANEL_LED_Bar_type(panelInfo.led_bar_type);
	//Set_PANEL_EPI_TYPE(panelInfo.epi_panel_type);
	Set_PANEL_INCH(panelInfo.panel_inch);
	Set_PANEL_MAKER(panelInfo.panel_maker);
	Set_DISP_OSD_Width(panelInfo.disp_out_resolution.osd_width);
	Set_DISP_OSD_Width(panelInfo.disp_out_resolution.osd_height);

	//temp mark :  panelInfo.useInternalFrc;
	//sfg_zz_shift_dbg_ctrl_reg.regValue = IoReg_Read32(SFG_SFG_ZZ_shift_dbg_CTRL_reg);
	//sfg_zz_shift_dbg_ctrl_reg.dout_mode = parameter.iCONFIG_DISPLAY_COLOR_BITS;  //0 is 30 bit,1 is 24 bit
	//IoReg_Write32(SFG_SFG_ZZ_shift_dbg_CTRL_reg, sfg_zz_shift_dbg_ctrl_reg.regValue);

	//lvds_ctrl3.regValue = IoReg_Read32(PIF_LVDS_CTRL3_reg);
	//lvds_ctrl3.lvds_map = parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE ? 1 : 0;  //0 is JEIDA,1is VESA
	//IoReg_Write32(PIF_LVDS_CTRL3_reg, lvds_ctrl3.regValue);
#endif
	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE), GFP_DCU1, (void**)&vir_addr_noncache);
	//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);
	config_data = (VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *)vir_addr_noncache;
	config_data->videoPlane = VO_VIDEO_PLANE_V1;
	config_data->enable =Get_PANEL_VFLIP_ENABLE();
#ifdef CONFIG_RTK_KDRV_RPC
	if (RPC_FAIL==send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_ConfigVodmaVFlip,phy_addr, 0, &result))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"RPC fail!!\n");
		ret=0;
	}
#endif
	dvr_free((void *)vir_addr);
	drvif_scaler3d_set_panel_info(); //send panel info to video fw

	Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(_ENABLE);
	Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MAX());
	Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MIN());
	Scaler_Set_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag(_ENABLE);
	Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Typical(1125);
	Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Upper(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MAX());
	Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Lower(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MIN());
	Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Typical(1350);
	Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Upper(Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MAX());
	Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Lower(Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MIN());

#ifdef CONFIG_ENABLE_FRC_TO_FRAMESYNC_BY_HW
	Scaler_Set_FreeRun_To_FrameSync_By_HW_Enable(_ENABLE);
#else //#ifdef CONFIG_ENABLE_FRC_TO_FRAMESYNC_BY_HW
	Scaler_Set_FreeRun_To_FrameSync_By_HW_Enable(_DISABLE);
#endif //#ifdef CONFIG_ENABLE_FRC_TO_FRAMESYNC_BY_HW
	Scaler_Set_FreeRun_To_FrameSync_By_HW_LineBufferMode_Enable(_ENABLE);
    Scaler_Set_FreeRun_To_FrameSync_By_HW_LineBufferMode_SpeedUp_TimeOut(200);
	Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp(_ENABLE);
	Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_TimeOut(50);
	Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_Porch(22);
/*
	if(Get_DISPLAY_PANEL_OLED_TYPE()== TRUE){
		Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL2(_ENABLE);
		Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL3(_DISABLE);
	}
	else{
		Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL2(_DISABLE);
		Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL3(_ENABLE);
	}
*/
	Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL2(_DISABLE);
	Scaler_Set_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL3(_ENABLE);

	if(ret)
	{
		VBE_DISP_Global_Status =VBE_DISP_INIT_DONE;
	}
	up(&VBE_Semaphore);
	return ret;
}
unsigned char HAL_VBE_DISP_Uninitialize(void)
{
	down(&VBE_Semaphore);
	if(VBE_DISP_Global_Status != VBE_DISP_INIT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n HAL_VBE_DISP_Uninitialize fail. no initialize.\n");
		up(&VBE_Semaphore);
		return 0;
	}
	Panel_releaseParameter();
	Scaler_ReleaseODMem();
	VBE_DISP_Global_Status =VBE_DISP_NOTHING;
	up(&VBE_Semaphore);
	return 1;
}

unsigned char HAL_VBE_DISP_Resume(DISP_PANEL_INFO_T panelInfo)
{
	unsigned char ret=1;
	//unsigned long result =0;
	//VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *config_data;
	//unsigned int vir_addr, vir_addr_noncache;
	//unsigned int phy_addr;
	//PANEL_CONFIG_PARAMETER parameter;
	//sfg_zz_shift_dbg_ctrl_RBUS sfg_zz_shift_dbg_ctrl_reg;
	//lvds_ctrl3_RBUS  lvds_ctrl3;
	//lvds_ctrl0_RBUS lvds_ctrl0;


	down(&VBE_Semaphore);
/*
	if(VBE_DISP_Global_Status != VBE_DISP_INIT_DONE){
		printk(KERN_INFO "\r\n HAL_VBE_DISP_Resume no initialize.\n");
		up(&VBE_Semaphore);
		return 0;
	}
*/
	printk(KERN_EMERG"[HAL_VBE_DISP_Resume] HAL_VBE_DISP_Resume !\n");
	vbe_disp_resume();

#ifdef VBE_DISP_TCON_SELF_CHECK
	vbe_disp_tcon_lock_self_check();
#ifdef CONFIG_RTK_KDRV_THERMAL_SENSOR
	monitor_rgb_rolling=0; //for run tcon check
#endif
#endif

#if 0
	memset(&parameter,0,sizeof(PANEL_CONFIG_PARAMETER));

	parameter.iCONFIG_DISP_ACT_STA_HPOS=0;
	parameter.iCONFIG_DISP_ACT_END_HPOS=panelInfo.disp_out_resolution.video_width;
	parameter.iCONFIG_DISP_ACT_STA_VPOS=0;
	parameter.iCONFIG_DISP_ACT_END_VPOS=panelInfo.disp_out_resolution.video_height;
	parameter.iCONFIG_DISPLAY_COLOR_BITS=(panelInfo.lvds_bit_mode)?0:1;  //panelInfo.lvds_bit_mode 0 is 8bit,1 is 10bit
	parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE=(panelInfo.lvds_type)?0:1;  //panelInfo.lvds_type 0 is VESA,1 is JEIDA
	lvds_ctrl0.regValue = IoReg_Read32(PIF_LVDS_CTRL0_reg);
	if(panelInfo.panelInterface==DISP_PANEL_HSLVDS)
	{
		parameter.iCONFIG_PANEL_TYPE=P_HSLVDS_TYPE;
		lvds_ctrl0.plt_lvds_mode=1;    // mLVDS-mode
	}
	else if(panelInfo.panelInterface==DISP_PANEL_EPI)
	{
		parameter.iCONFIG_PANEL_TYPE=P_EPI_TYPE;
		lvds_ctrl0.plt_lvds_mode=2;    //EPI-mode
	}
/*
	else if(panelInfo.panelInterface==DISP_PANEL_Vx1)
	{
		parameter.iCONFIG_PANEL_TYPE=P_VBY1_4K2K;
		lvds_ctrl0.plt_lvds_mode=3;    //Vby1-mode
	}
*/
	else
	{
		parameter.iCONFIG_PANEL_TYPE=P_LVDS_2K1K;
		lvds_ctrl0.plt_lvds_mode=0;    //LVDS-mode
	}
	IoReg_Write32(PIF_LVDS_CTRL0_reg, lvds_ctrl0.regValue);

	Set_PANEL_BL_type(panelInfo.panel_bl_type);
	Set_PANEL_LED_Bar_type(panelInfo.led_bar_type);
	Set_PANEL_EPI_TYPE(panelInfo.epi_panel_type);
	Set_PANEL_INCH(panelInfo.panel_inch);
	Set_PANEL_MAKER(panelInfo.panel_maker);
	Set_DISP_OSD_Width(panelInfo.disp_out_resolution.osd_width);
	Set_DISP_OSD_Width(panelInfo.disp_out_resolution.osd_height);

	//temp mark :  panelInfo.useInternalFrc;
	sfg_zz_shift_dbg_ctrl_reg.regValue = IoReg_Read32(SFG_SFG_ZZ_shift_dbg_CTRL_reg);
	sfg_zz_shift_dbg_ctrl_reg.dout_mode = parameter.iCONFIG_DISPLAY_COLOR_BITS;  //0 is 30 bit,1 is 24 bit
	IoReg_Write32(SFG_SFG_ZZ_shift_dbg_CTRL_reg, sfg_zz_shift_dbg_ctrl_reg.regValue);

	lvds_ctrl3.regValue = IoReg_Read32(PIF_LVDS_CTRL3_reg);
	lvds_ctrl3.lvds_map = parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE ? 1 : 0;  //0 is JEIDA,1is VESA
	IoReg_Write32(PIF_LVDS_CTRL3_reg, lvds_ctrl3.regValue);

	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE), GFP_DCU1, (void**)&vir_addr_noncache);
	//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);
	config_data = (VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *)vir_addr_noncache;
	config_data->videoPlane = VO_VIDEO_PLANE_V1;
	config_data->enable =Get_PANEL_VFLIP_ENABLE();
#ifdef CONFIG_RTK_KDRV_RPC
	if (RPC_FAIL==send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_ConfigVodmaVFlip,phy_addr, 0, &result))
	{
		printk("RPC fail!!\n");
		ret=0;
	}
#endif
	dvr_free((void *)vir_addr);
	drvif_scaler3d_set_panel_info(); //send panel info to video fw
	if(ret)
	{
		VBE_DISP_Global_Status =VBE_DISP_INIT_DONE;
	}
#endif
	up(&VBE_Semaphore);
	return ret;
}

void HAL_VBE_DISP_Connect(DISP_WINDOW_T wId)
{
	//do nothing:vsc would do
}
void HAL_VBE_DISP_Disconnect(DISP_WINDOW_T wId)
{
	//do nothing:vsc would do
}

void HAL_VBE_DISP_SetDisplayOutput(BOOLEAN bOnOff)
{
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	//main_display_control_rsv_RBUS main_display_control_rsv_reg;
	ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_reg;
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	//main_display_control_rsv_reg.regValue = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
	ppoverlay_double_buffer_ctrl_reg.regValue=IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	unsigned long flags;//for spin_lock_irqsave

	if(bOnOff)
	{
		display_timing_ctrl1_reg.disp_en=1;
		//main_display_control_rsv_reg.m_disp_en=1;
	}
	else
	{
		//when disable d-domain clock, first enable MEMC output bg in factory mode @Crixus 20151231
		Scaler_MEMC_output_force_bg_enable(_ENABLE);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Enable MEMC BG in SetDisplayOutput!!!\n");

		display_timing_ctrl1_reg.disp_en=0;
		//main_display_control_rsv_reg.m_disp_en=0;
	}
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg,display_timing_ctrl1_reg.regValue);
	//IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg,main_display_control_rsv_reg.regValue);
	if(ppoverlay_double_buffer_ctrl_reg.dreg_dbuf_en)
	{
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		ppoverlay_double_buffer_ctrl_reg.dreg_dbuf_set=1;
		IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg,ppoverlay_double_buffer_ctrl_reg.regValue);
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	}

	if(bOnOff)
	{
		//wait enable d-domain clock, then enable MEMC output bg in factory mode @Crixus 20151231
		//Because intanboot resume will call this function, if instanboot resume, it should be wait resume done.
		if(Scaler_MEMC_Get_instanboot_resume_Done() == 0){
			Scaler_MEMC_output_force_bg_enable(_DISABLE);
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Disable MEMC BG in SetDisplayOutput!!!\n");
		}
	}

}
void vbe_disp_suspend(void);
void vbe_disp_resume(void);

void HAL_VBE_DISP_SetMute(BOOLEAN bOnOff)
{
	sfg_sfg_force_bg_at_dif_RBUS sfg_force_bg_at_dif_reg;

	/*WaitFor_DEN_STOP();*/
	sfg_force_bg_at_dif_reg.regValue = IoReg_Read32(SFG_SFG_FORCE_BG_AT_DIF_reg);
	if(bOnOff){
		sfg_force_bg_at_dif_reg.en_force_bg_dif = 1;  //osd and video all mute
		if(Get_DISPLAY_PANEL_OLED_TYPE() == TRUE){
			oled_resume_eit_flag = TRUE;
		}
	}else{
		sfg_force_bg_at_dif_reg.en_force_bg_dif = 0;
		if(Get_DISPLAY_PANEL_OLED_TYPE() == TRUE){
			oled_resume_eit_flag = FALSE;
		}
	}
	IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, sfg_force_bg_at_dif_reg.regValue);
}

int HAL_VBE_DISP_GetSpreadSpectrum(VBE_DISP_SpreadSpectrum_T *spreadspectrum)
{
	pll27x_reg_sys_dclkss_RBUS dclkss_reg;
	pll27x_reg_sys_pll_disp1_RBUS pll_disp1_reg;
	pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
	pll27x_reg_pll_ssc3_RBUS pll_ssc3_reg;
	pll27x_reg_pll_ssc4_RBUS pll_ssc4_reg;
	pll27x_reg_pll_ssc5_RBUS pll_ssc5_reg;

	UINT32 m_code, f_code, n_code, m_code_ssc, f_code_ssc;
	UINT32 p1, p2;
	UINT32 dot_gran=4, gran_est;
	UINT32 dpll_clk_ssc, ssc_clk, step;
	UINT32 temp, ss_freq;

	pll_disp1_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
	pll_ssc3_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC3_reg);
	pll_ssc4_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);

	m_code = pll_disp1_reg.dpll_m;
	n_code = pll_disp1_reg.dpll_n;
	f_code = pll_ssc0_reg.fcode_t_ssc;
	m_code_ssc = pll_ssc3_reg.ncode_ssc;
	f_code_ssc = pll_ssc3_reg.fcode_ssc;
	gran_est = pll_ssc4_reg.gran_est;

	if (0 == pll_ssc4_reg.en_ssc) {	// sscg disabled
		spreadspectrum->bEnable = 0;
		spreadspectrum->Percenct = 0;
		spreadspectrum->Period = 0;
		return 0;
	} else if (0 == gran_est)
		return -EINVAL;

	p1 = (m_code + 3) * 2048 + f_code;
	p2 = (m_code_ssc + 3) * 2048 + f_code_ssc;

	spreadspectrum->bEnable = 1;
	spreadspectrum->Percenct = ((p1 - p2) * 10000 / p1 + 5) / 10;	// rounding

	if (f_code >= f_code_ssc)
		step = (((m_code - m_code_ssc) * 2048 + f_code - f_code_ssc) * 2 * (1 << (15 - dot_gran))) / gran_est;
	else
		step = (((m_code - 1 - m_code_ssc) * 2048 + (2048 + f_code) - f_code_ssc) * 2 * (1 << (15 - dot_gran))) / gran_est;

	dpll_clk_ssc = p2 * (27 * 1000000 / (n_code + 2) / 2048);
	temp = (10000 * ((m_code - m_code_ssc) * 2048 + f_code - f_code_ssc) / 2 / 2048 + (m_code_ssc + 3) * 10000);
	ssc_clk = dpll_clk_ssc / temp;
	ss_freq = ssc_clk * 10000 / step;

	spreadspectrum->Period = ss_freq / 1000;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "Get spectrum setting, Percent = %d, Period = %d\n", spreadspectrum->Percenct, spreadspectrum->Period);

	return 0;
}

void HAL_VBE_DISP_SetSpreadSpectrum(BOOLEAN bEnable, UINT16 u16Percent, UINT16 u16Period)
{
	UINT16 dclk_sscg_range = 0;
	pll27x_reg_sys_dclkss_RBUS dclkss_reg;
	pll27x_reg_sys_pll_disp1_RBUS pll_disp1_reg;
	pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
	pll27x_reg_pll_ssc3_RBUS pll_ssc3_reg;
	pll27x_reg_pll_ssc4_RBUS pll_ssc4_reg;
	pll27x_reg_pll_ssc5_RBUS pll_ssc5_reg;
	pll27x_reg_sys_pll_disp3_RBUS pll27x_reg_sys_pll_disp3_reg;
	pll27x_reg_dpll_double_buffer_ctrl_RBUS dpll_double_buffer_ctrl_reg;
	UINT16 dclk_ss_reg_table[16]={0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};
	UINT32 m_code, f_code, n_code, n_code_ssc, f_code_ssc;
	UINT32 temp, temp_ssc, tmp_val;
	UINT32 dot_gran=4, gran_est;
	UINT32 dpll_clk, dpll_clk_ssc, ssc_clk, step;
	UINT32 ss_freq = 54*1000; //54K
	UINT32 cnt=0;
	UINT8 tableidx = 0;
	UINT32 dclk_Temp;
	UINT32 ulFreq=0;
	UINT32 div=0;

	//DPLL disable double buffer
	dpll_double_buffer_ctrl_reg.regValue =IoReg_Read32(PLL27X_REG_dpll_Double_Buffer_CTRL_reg);
	dpll_double_buffer_ctrl_reg.double_buf_en=0;
	IoReg_Write32(PLL27X_REG_dpll_Double_Buffer_CTRL_reg,dpll_double_buffer_ctrl_reg.regValue);

	//unsigned char panel_type=((IoReg_Read32(MISC_GPIO_GP2DATI_VADDR)>>18)&0x1);//0xb801bd38[18]=1 OLED
	if(bEnable == 0 || u16Percent ==0)
	tableidx = 0;
	else{
	if(u16Percent % 5 ==0)
		tableidx = ( u16Percent / 5 ) ;
	else
		tableidx = ( u16Percent / 5 )+1 ;

	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n dclk_ss_reg_table[%d] = %d \n", tableidx, dclk_ss_reg_table[tableidx]);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"\n bEnable=%d, u16Percent=%d, u16Period=%d\n", bEnable, u16Percent, u16Period);


	if((u16Period>=10)&&(u16Period<=100))
		ss_freq = u16Period*1000;

/*
	if(u16Period == 25){
		ss_freq = 25000;
	}else{
		ss_freq = 30*1000; //30K
	}
*/
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n dclk_ss_reg_table[%d] = %d \n", tableidx, dclk_ss_reg_table[tableidx]);

	dclk_sscg_range = dclk_ss_reg_table[tableidx];
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n u16Period=%d, ss_freq=%d\n", u16Period, ss_freq);

	ulFreq = Get_DISPLAY_CLOCK_TYPICAL();

	if((ulFreq>=400*1000000) && (ulFreq <= 700*1000000)){
		div = 1;
	}else if((ulFreq>=200*1000000) && (ulFreq <= 350*1000000)){
		div = 2;
		ulFreq = ulFreq*2;
	}else if((ulFreq>=100*1000000) && (ulFreq <= 175*1000000)){
		div = 4;
		ulFreq = ulFreq*4;
	}else if((ulFreq>=60*1000000) && (ulFreq <= 80*1000000)){
		 div = 8;
		 ulFreq = ulFreq*8;
	}else{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Error Dclk Range!\n");
	}
	n_code = 1;
	dclk_Temp = ((ulFreq*(n_code+2)) /(27*100));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "dclk_Temp:%d\n", dclk_Temp);
	m_code = (dclk_Temp/10000)-3;
	f_code = ((dclk_Temp % 10000)*2048)/10000;	// offset
	pll_disp1_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
	pll_ssc3_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC3_reg);
	pll_ssc4_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
	if((tableidx == 0) || (Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI)){
		//set default dclk freq.
		   pll_disp1_reg.dpll_m = m_code;
		pll_disp1_reg.dpll_n = n_code;
		pll_ssc0_reg.fcode_t_ssc = f_code;
		pll_ssc0_reg.oc_en = 0;
		pll_ssc0_reg.oc_step_set = 0x200;
		rtd_outl(PLL27X_REG_SYS_PLL_DISP1_reg, pll_disp1_reg.regValue);
		rtd_outl(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
		pll_ssc0_reg.oc_en = 1;
		rtd_outl(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
		cnt=10;
		do{
			pll_ssc5_reg.regValue = rtd_inl(PLL27X_REG_PLL_SSC5_reg);
			mdelay(1);
		}while((pll_ssc5_reg.oc_done != 1) && (cnt--));
		pll_ssc0_reg.oc_en = 0;
		rtd_outl(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
		//disable sscg
		pll_ssc4_reg.en_ssc = 0;
		rtd_outl(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);
		return;
	}

	temp = ((m_code+3)*10000+ ((f_code*10000)/2048));
	temp = temp+ (temp*(dclk_sscg_range*10)/2)/10000;
	m_code = temp/10000-3;
	f_code = ((temp%10000)*2048)/10000;
	temp_ssc = (temp*(1000-dclk_sscg_range))/1000;
	n_code_ssc = temp_ssc/10000-3;
	f_code_ssc = ((temp_ssc%10000)*2048)/10000;

	pll_disp1_reg.dpll_m = m_code;
	pll_disp1_reg.dpll_n = n_code;
	pll_ssc0_reg.fcode_t_ssc = f_code;
	pll_ssc3_reg.ncode_ssc = n_code_ssc;
	pll_ssc3_reg.fcode_ssc = f_code_ssc;
	pll_ssc0_reg.oc_en = 0;
	pll_ssc0_reg.oc_step_set = 0x200;
	rtd_outl(PLL27X_REG_SYS_PLL_DISP1_reg, pll_disp1_reg.regValue);
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
	IoReg_Write32(PLL27X_REG_PLL_SSC3_reg, pll_ssc3_reg.regValue);

	pll27x_reg_sys_pll_disp3_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_DISP3_reg);
	if(div == 1)
		pll27x_reg_sys_pll_disp3_reg.dpll_o = 0;
	else if(div == 2)
		pll27x_reg_sys_pll_disp3_reg.dpll_o = 1;
	else if(div == 4)
		pll27x_reg_sys_pll_disp3_reg.dpll_o = 2;
	else if(div == 8)
		pll27x_reg_sys_pll_disp3_reg.dpll_o = 3;
	else
		pll27x_reg_sys_pll_disp3_reg.dpll_o = 0;
	rtd_outl(PLL27X_REG_SYS_PLL_DISP3_reg, pll27x_reg_sys_pll_disp3_reg.regValue);


	temp= 0;
	dpll_clk = (((m_code+3)*1000000 + (f_code*1000000)/2048)*27) / (n_code+2);
		dpll_clk_ssc = (dpll_clk/1000*(1000 - dclk_sscg_range));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n dpll_clk:%d, dpll_clk_ssc:%d \n", dpll_clk, dpll_clk_ssc);
	temp = (10000*((m_code-n_code_ssc)*2048+f_code-f_code_ssc)/2/2048 + (n_code_ssc+3)*10000);
	ssc_clk = dpll_clk_ssc /temp;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n temp:%d, ssc_clk:%d \n", temp, dpll_clk_ssc/temp);
	step =	ssc_clk*10000 / ss_freq;
	if(f_code>=f_code_ssc)
		gran_est = (((m_code-n_code_ssc)*2048+f_code-f_code_ssc)*2*(1<<(15-dot_gran))) /step;
	else
		gran_est = (((m_code-1-n_code_ssc)*2048+ (2048+f_code)-f_code_ssc)*2*(1<<(15-dot_gran))) /step;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "m_code:%d, n_code:%d, f_code:%d, n_code_ssc:%d, f_code_ssc:%d\n", m_code , n_code, f_code, n_code_ssc, f_code_ssc);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "\n step:%d, gran_est:%d\n", step , gran_est);

	pll_ssc4_reg.dot_gran = dot_gran;
	pll_ssc4_reg.gran_auto_rst = 1;
	pll_ssc4_reg.gran_est = gran_est;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);

	pll_ssc0_reg.oc_en = 1;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

	cnt=10;
	do{
		pll_ssc5_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC5_reg);
		msleep(10);
	}while((pll_ssc5_reg.oc_done != 1) && (cnt--));

	pll_ssc0_reg.oc_en = 0;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
	pll_ssc4_reg.en_ssc = 1;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);


	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	dclkss_reg.dclk_ss_load = _ENABLE;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, dclkss_reg.regValue);

}

unsigned char HAL_VBE_DISP_SetVideoMirror(BOOLEAN bIsH,BOOLEAN bIsV)
{
	unsigned long result =0;
	VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *config_data;
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;
	sfg_sfg_ctrl_0_RBUS sfg_ctrl_0_reg;
	sfg_ctrl_0_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_0_reg);
	 //hflip
	if(bIsH)
	{
		sfg_ctrl_0_reg.h_flip_en = 1;

	}
	else
	{
		sfg_ctrl_0_reg.h_flip_en = 0;
	}
	if(Get_DISPLAY_PANEL_TYPE() == P_EPI_TYPE){
		//EPI V16DRD Horizontal need hflip, so dirty patch it.
		sfg_ctrl_0_reg.h_flip_en = !sfg_ctrl_0_reg.h_flip_en;
	}
	IoReg_Write32(SFG_SFG_CTRL_0_reg, sfg_ctrl_0_reg.regValue);

	//vflip
	Set_Mirror_VFLIP_ENABLE(bIsV);
	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE), GFP_DCU1, (void**)&vir_addr_noncache);
	//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);
	config_data = (VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *)vir_addr_noncache;
	config_data->videoPlane = VO_VIDEO_PLANE_V1;
	config_data->enable =bIsV;
#ifdef CONFIG_RTK_KDRV_RPC
	if (RPC_FAIL==send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_ConfigVodmaVFlip,phy_addr, 0, &result))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"RPC fail!!\n");
		dvr_free((void *)vir_addr);
		return FALSE;
	}
#endif
	dvr_free((void *)vir_addr);
	drvif_scaler3d_set_panel_info(); //send panel info to video fw
	return TRUE;

}

void HAL_VBE_DISP_SetDisplayFormat(DISP_PANEL_ATTRIBUTE_T * pPanelAttr,UINT8 framerate)
{
	sfg_sfg_zz_shift_dbg_ctrl_RBUS sfg_zz_shift_dbg_ctrl_reg;
	pif_lvds_ctrl3_RBUS  lvds_ctrl3;
	pif_lvds_ctrl0_RBUS lvds_ctrl0;
	unsigned int panel_width,panel_height;
	PANEL_CONFIG_PARAMETER parameter;
	STRUCT_PANEL_SPECIAL_SETTING panel_special_para;
	down(&VBE_Semaphore);
	panel_width=(pPanelAttr->panelResolution>>12)&0xffff;
	panel_height=pPanelAttr->panelResolution&0xfff;

	memset(&parameter,0,sizeof(PANEL_CONFIG_PARAMETER));
#if 0
	lvds_ctrl0.regValue = IoReg_Read32(PIF_LVDS_CTRL0_reg);
	if(pPanelAttr->ePanelInterface==DISP_PANEL_EPI)
	{
		parameter.iCONFIG_PANEL_TYPE=P_EPI_TYPE;
		lvds_ctrl0.plt_lvds_mode = 2;    /*EPI-mode*/
	}
	else
	{
		parameter.iCONFIG_PANEL_TYPE=P_LVDS_2K1K;
		lvds_ctrl0.plt_lvds_mode = 0;    /*LVDS-mode & mLVDS-mode*/
	}
	IoReg_Write32(PIF_LVDS_CTRL0_reg, lvds_ctrl0.regValue);
#endif
	parameter.iCONFIG_DISPLAY_PORT=pPanelAttr->eLVDSPixel;
	parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE=(pPanelAttr->eLVDSSelect)?0:1;  //pPanelAttr.eLVDSSelect 0 is VESA,1 is JEIDA
	parameter.iCONFIG_DISPLAY_COLOR_BITS=(pPanelAttr->eColorDepth)?0:1;   //pPanelAttr.eColorDepth 0 is 8bit,1 is 10bit
	parameter.iCONFIG_DISPLAY_HORIZONTAL_SYNC_NORMAL=1;
	parameter.iCONFIG_DISPLAY_VERTICAL_SYNC_NORMAL=1;

	parameter.iCONFIG_DISP_ACT_STA_HPOS=0;
	parameter.iCONFIG_DISP_ACT_END_HPOS=panel_width;
	parameter.iCONFIG_DISP_ACT_STA_VPOS=0;
	parameter.iCONFIG_DISP_ACT_END_VPOS=panel_height;
	parameter.iCONFIG_DISP_HORIZONTAL_TOTAL=pPanelAttr->horizTypPeriod; //Dh total need as even

	parameter.iCONFIG_DISPLAY_REFRESH_RATE=framerate;
	if(parameter.iCONFIG_PANEL_TYPE==P_LVDS_2K1K)
	{
		if(parameter.iCONFIG_DISPLAY_PORT)
		{
			parameter.iCONFIG_DISPLAY_CLOCK_MIN=126;
			parameter.iCONFIG_DISPLAY_CLOCK_MAX=154;
		}
		else
		{
			parameter.iCONFIG_DISPLAY_CLOCK_MIN=50;
			parameter.iCONFIG_DISPLAY_CLOCK_MAX=85;
		}
	}
	else if((parameter.iCONFIG_PANEL_TYPE==P_EPI_TYPE)||(parameter.iCONFIG_PANEL_TYPE==P_VBY1_4K2K))
	{  //don't use ,fix 297MHz
		parameter.iCONFIG_DISPLAY_CLOCK_MIN=126;
		parameter.iCONFIG_DISPLAY_CLOCK_MAX=154;
	}
	else if(parameter.iCONFIG_PANEL_TYPE==P_LVDS_2K1K_300MHZ) {
		parameter.iCONFIG_DISPLAY_CLOCK_MIN = 126 * 2;
		parameter.iCONFIG_DISPLAY_CLOCK_MAX = 154 * 2;
		printk("%s panel 2K1K_300MHZ set MIN/MAX CLOCK\n", __func__);
	}
	else
	{
		parameter.iCONFIG_DISPLAY_CLOCK_MIN=126;
		parameter.iCONFIG_DISPLAY_CLOCK_MAX=154;
	}
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MIN=pPanelAttr->vertBackPorch50Hz;
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MAX=pPanelAttr->vertTypPeriod50Hz;
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MIN=pPanelAttr->vertBackPorch60Hz;
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MAX=pPanelAttr->vertTypPeriod60Hz;

	if(framerate==48)
	{
		parameter.iCONFIG_DISP_VERTICAL_TOTAL=pPanelAttr->vertTypPeriod48Hz;
		parameter.iCONFIG_DISPLAY_CLOCK_TYPICAL=framerate*pPanelAttr->horizTypPeriod*pPanelAttr->vertTypPeriod48Hz;
		parameter.iCONFIG_DISP_DEN_STA_VPOS=pPanelAttr->vertBackPorch48Hz;
		parameter.iCONFIG_DISP_DEN_END_VPOS=pPanelAttr->vertBackPorch48Hz+panel_height;
		parameter.iCONFIG_DISP_VSYNC_LENGTH=pPanelAttr->vertSyncWidth48Hz;
		parameter.iCONFIG_DISP_HSYNC_WIDTH =pPanelAttr->horizSyncWidth48Hz;
		parameter.iCONFIG_DISP_DEN_STA_HPOS=pPanelAttr->horizBackPorch48Hz;
		parameter.iCONFIG_DISP_DEN_END_HPOS=pPanelAttr->horizBackPorch48Hz+panel_width;
	}
	else if(framerate==50)
	{
		parameter.iCONFIG_DISP_VERTICAL_TOTAL=pPanelAttr->vertTypPeriod50Hz;
		parameter.iCONFIG_DISPLAY_CLOCK_TYPICAL=framerate*pPanelAttr->horizTypPeriod*pPanelAttr->vertTypPeriod50Hz;
		parameter.iCONFIG_DISP_DEN_STA_VPOS=pPanelAttr->vertBackPorch50Hz;
		parameter.iCONFIG_DISP_DEN_END_VPOS=pPanelAttr->vertBackPorch50Hz+panel_height;
		parameter.iCONFIG_DISP_VSYNC_LENGTH=pPanelAttr->vertSyncWidth50Hz;
		parameter.iCONFIG_DISP_HSYNC_WIDTH =pPanelAttr->horizSyncWidth50Hz;
		parameter.iCONFIG_DISP_DEN_STA_HPOS=pPanelAttr->horizBackPorch50Hz;
		parameter.iCONFIG_DISP_DEN_END_HPOS=pPanelAttr->horizBackPorch50Hz+panel_width;
	}
	else
	{
		parameter.iCONFIG_DISP_VERTICAL_TOTAL=pPanelAttr->vertTypPeriod60Hz;
		parameter.iCONFIG_DISPLAY_CLOCK_TYPICAL=framerate*pPanelAttr->horizTypPeriod*pPanelAttr->vertTypPeriod60Hz;
		parameter.iCONFIG_DISP_DEN_STA_VPOS=pPanelAttr->vertBackPorch60Hz;
		parameter.iCONFIG_DISP_DEN_END_VPOS=pPanelAttr->vertBackPorch60Hz+panel_height;
		parameter.iCONFIG_DISP_VSYNC_LENGTH=pPanelAttr->vertSyncWidth60Hz;
		parameter.iCONFIG_DISP_HSYNC_WIDTH =pPanelAttr->horizSyncWidth60Hz;
		parameter.iCONFIG_DISP_DEN_STA_HPOS=pPanelAttr->horizBackPorch60Hz;
		parameter.iCONFIG_DISP_DEN_END_HPOS=pPanelAttr->horizBackPorch60Hz+panel_width;
	}

	parameter.iCONFIG_DISP_HSYNC_LASTLINE=pPanelAttr->horizTypPeriod-1;

	parameter.iVFLIP=Get_Mirror_VFLIP_ENABLE();
//	Panel_InitParameter(&parameter);

	Set_PANEL_INCH(pPanelAttr->ePanelInch);
	Set_PANEL_MAKER(pPanelAttr->ePanelType);
	panel_special_para.HBackPorch48Hz=pPanelAttr->horizBackPorch48Hz;
	panel_special_para.HSyncWidth48Hz=pPanelAttr->horizSyncWidth48Hz;
	panel_special_para.VTypPeriod48Hz=pPanelAttr->vertTypPeriod48Hz;
	panel_special_para.VBackPorch48Hz=pPanelAttr->vertBackPorch48Hz;
	panel_special_para.VSyncWidth48Hz=pPanelAttr->vertSyncWidth48Hz;

	panel_special_para.HBackPorch50Hz=pPanelAttr->horizBackPorch50Hz;
	panel_special_para.HSyncWidth50Hz=pPanelAttr->horizSyncWidth50Hz;
	panel_special_para.VTypPeriod50Hz=pPanelAttr->vertTypPeriod50Hz;
	panel_special_para.VBackPorch50Hz=pPanelAttr->vertBackPorch50Hz;
	panel_special_para.VSyncWidth50Hz=pPanelAttr->vertSyncWidth50Hz;

	panel_special_para.HBackPorch60Hz=pPanelAttr->horizBackPorch60Hz;
	panel_special_para.HSyncWidth60Hz=pPanelAttr->horizSyncWidth60Hz;
	panel_special_para.VTypPeriod60Hz=pPanelAttr->vertTypPeriod60Hz;
	panel_special_para.VBackPorch60Hz=pPanelAttr->vertBackPorch60Hz;
	panel_special_para.VSyncWidth60Hz=pPanelAttr->vertSyncWidth60Hz;

#if 0
	sfg_zz_shift_dbg_ctrl_reg.regValue = IoReg_Read32(SFG_SFG_ZZ_shift_dbg_CTRL_reg);
	sfg_zz_shift_dbg_ctrl_reg.dout_mode = parameter.iCONFIG_DISPLAY_COLOR_BITS;
	IoReg_Write32(SFG_SFG_ZZ_shift_dbg_CTRL_reg, sfg_zz_shift_dbg_ctrl_reg.regValue);

		lvds_ctrl3.regValue = IoReg_Read32(PIF_LVDS_CTRL3_reg);
		lvds_ctrl3.lvds_map = parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE;
		//lvds_ctrl3.lvds_map = Get_DISPLAY_BITMAPPING_TABLE()?1:0;  //0 is JEIDA,1is VESA
		IoReg_Write32(PIF_LVDS_CTRL3_reg, lvds_ctrl3.regValue);
#endif
#if 0

	drvif_scaler3d_set_panel_info(); //send panel info to video fw

	Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Enable_Flag(_ENABLE);
	Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Upper(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MAX());
	Scaler_Set_EnterFRC_LastLine_FixDclk_DVTotoal_Limit_Lower(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MIN());
	Scaler_Set_FixLastLine_DVTotoal_Limit_ByVfreq_Enable_Flag(_ENABLE);
	Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Typical(1125);
	Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Upper(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MAX());
	Scaler_Set_FixLastLine_DVTotal_Limit_60Hz_Lower(Get_PANEL_DISP_VERTICAL_TOTAL_60Hz_MIN());
	Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Typical(1350);
	Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Upper(Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MAX());
	Scaler_Set_FixLastLine_DVTotal_Limit_50Hz_Lower(Get_PANEL_DISP_VERTICAL_TOTAL_50Hz_MIN());
#endif
	up(&VBE_Semaphore);
}

extern unsigned char rtk_rerun_scaler(SCALER_DISP_CHANNEL channel);

void HAL_VBE_DISP_SetFrameRate(BOOLEAN isForceFreeRun,UINT8 frameRates)
{
	unsigned int vtotal = 0;
	ppoverlay_dv_total_RBUS dv_total_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;

	ppoverlay_dispd_smooth_toggle1_RBUS	dispd_smooth_toggle1_reg;
	ppoverlay_dispd_stage1_sm_ctrl_RBUS 	dispd_stage1_sm_ctrl_reg;
	ppoverlay_dtg_m_multiple_vsync_RBUS   dtg_m_multiple_vsync_reg;
	ppoverlay_dtg_frame_cnt1_RBUS dtg_frame_cnt1_reg;
	unsigned int timeout = 0;
	unsigned char frame_idicator=0;

	down(&VBE_Semaphore);

	if(isForceFreeRun)
	{
		Disp_Set_framerate(frameRates);
		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		if(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "data fs do free run need to restart\n");
			Disp_Enable_isForceFreeRun(isForceFreeRun);
			rtk_rerun_scaler(SLR_MAIN_DISPLAY);
			rtk_rerun_scaler(SLR_SUB_DISPLAY);
		}
		else
		{

			modestate_decide_pixel_mode();
			Scaler_DispSetInputInfo(SLR_INPUT_FRAC_FS_REMOVE_RATIO, 1);

			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_1_PIXEL){ //60hz
				if(frameRates == 48){
					Scaler_DispSetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ, 48);
				}else if(frameRates == 50){
					Scaler_DispSetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ, 50);
				}else if(frameRates == 60){
					Scaler_DispSetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ, 60);
				}else{
					rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s]Set Framerate (%d) error. Reset to 60Hz\n", __FUNCTION__, frameRates);
					Scaler_DispSetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ, 60);
				}
			}else{
				if((frameRates == 50)||(frameRates == 100)){
					Scaler_DispSetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ, 50);
				}else if((frameRates == 60)||(frameRates == 120)){
					Scaler_DispSetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ, 60);
				}else{
					rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s]Set Framerate (%d) error. Reset to 120Hz\n", __FUNCTION__, frameRates);
					Scaler_DispSetInputInfo(SLR_INPUT_DTG_MASTER_V_FREQ, 60);
				}
			}

			drivf_scaler_reset_freerun();
			modestate_set_fll_running_flag(_DISABLE);
			modestate_disp_flow_double_buf_enable(_ENABLE);

			dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
			dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
			IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

			dtg_m_multiple_vsync_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_M_multiple_vsync_reg);
			frame_idicator = dtg_m_multiple_vsync_reg.dtg_m_multiple_vsync;
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"*uzudtg_remove_half_ivs:%d\n", frame_idicator);

			if(frame_idicator > 0){ 	// run frame check
				timeout = 0xa0000; //100ms, 5 frame.
				dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
				while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= (frame_idicator-1))&& --timeout){
					dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
				}
				if(timeout == 0)
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]count timeout !!!\n", __FUNCTION__, __LINE__);
				//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"1. frame_idicator:%d\n", (IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);
				timeout = 0x25000; //20ms, 1 frame.
				//make sure that we can have a full porch apply timing change settings
				while((dtg_frame_cnt1_reg.uzudtg_input_frame_cnt!= frame_idicator)&& --timeout){
					dtg_frame_cnt1_reg.regValue = IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg);
				}
				if(timeout == 0)
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]count timeout !!!\n", __FUNCTION__, __LINE__);
				//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"2. frame_idicator:%d\n", (IoReg_Read32(PPOVERLAY_DTG_FRAME_CNT1_reg)&0x3f000000)>>24);
			}
			modestate_set_display_timing_gen_clock_div();
			modestate_set_fractional_framesync();

			timeout = 0x25000;	//20ms, 1 frame.
			//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"+++uzudtg line_cnt:%d\n", (IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg)&0x0fff0000)>>16);
			dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
			IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			do{
				dispd_smooth_toggle1_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_smooth_toggle1_reg);
			}while((dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply==1) && (--timeout));
			//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"---uzudtg line_cnt:%d\n", (IoReg_Read32(PPOVERLAY_new_meas1_linecnt_real_reg)&0x0fff0000)>>16);

			if(timeout==0){
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]WARNING! wait dispd_stage1_smooth_toggle_apply timeout!\n", __FUNCTION__, __LINE__);
				dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 0;
				IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
				dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
				dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
				IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
				dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply = 1;
				IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
			}else{
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[%s][%d] wait dispd_stage1_smooth_toggle_apply ok!\n", __FUNCTION__, __LINE__);
				dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
				dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
				IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
			}
			fw_scaler_dtg_double_buffer_apply();
			modestate_disp_flow_double_buf_enable(_DISABLE);
			modestate_set_display_timing_gen();

		}
	}
	else
	{
		if(display_timing_ctrl1_reg.disp_fsync_en==0) //timing free run
		{
			if(!vtotal_measure)
			{
				vtotal_measure=Get_DISP_VERTICAL_TOTAL()-1;
			}
			/*WaitFor_DEN_STOP();*/
			fw_scaler_dtg_double_buffer_enable(1);
			dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
			dv_total_reg.dv_total = vtotal_measure;
			IoReg_Write32(PPOVERLAY_DV_total_reg, dv_total_reg.regValue);
			fw_scaler_dtg_double_buffer_apply();
		//	fw_scaler_dtg_double_buffer_enable(0);
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"framesync:DVTotal:%x, 8014:%x\n", vtotal, IoReg_Read32(PPOVERLAY_DV_total_reg));
		}
	}
	up(&VBE_Semaphore);
}
#define XTAL_FREQ 27000000
#define IVS_XTAL_CNT 1

void HAL_VBE_DISP_GetOutputFrameRate(UINT8* pframeRates)
{
	ppoverlay_memcdtg_dvs_cnt_RBUS memcdtg_dvs_cnt_reg;
	unsigned int vSyncFreq = 0;

	down(&VBE_Semaphore);

	memcdtg_dvs_cnt_reg.regValue = IoReg_Read32(PPOVERLAY_memcdtg_DVS_cnt_reg);
       vSyncFreq = 270000000 / (memcdtg_dvs_cnt_reg.memcdtg_dvs_cnt);
	if((vSyncFreq%10) >5)
		*pframeRates = (vSyncFreq/10)+1;
	else
		*pframeRates = (vSyncFreq/10);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Get output frame rate : %d \n", *pframeRates);

	up(&VBE_Semaphore);

#if 0	//fix me later by ben.
	unsigned int vSyncFreq = 0;
	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	dv_total_RBUS dv_total_reg;
	dh_total_last_line_length_RBUS dh_total_last_line_length_reg;
	unsigned int dclkVal=0;
	unsigned int ivs_freq=0;
	unsigned int ivs_cnt=0;
	unsigned char ivs_freq_1=0;

	down(&VBE_Semaphore);
	display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	if((display_timing_ctrl1_reg.disp_frc_fsync == 1)&&(display_timing_ctrl1_reg.disp_fsync_en == 1)){	//framesync timing
		framesync_wait_vdc_stable();
		ivs_cnt = ((UINT32) framesync_new_fixlastline_get_stable_xtal_cnt(IVS_XTAL_CNT));
		ivs_freq = (((UINT32) XTAL_FREQ * 100) / ivs_cnt);
	//	vSyncFreq = scalerdisplay_get_framerate(_TYPE_IVS);
		ivs_freq_1 =ivs_freq%100;
		if(ivs_freq_1>=90) //measure value would like 2390 or 2399
		{
			ivs_freq=ivs_freq+(100-ivs_freq_1);
		}
		vSyncFreq=ivs_freq/100;
		if(display_timing_ctrl1_reg.multiple_dvs == 1){
			vSyncFreq = vSyncFreq*2;
		}
	}
	else
	{	// free run timing
		dclkVal= scalerdisplay_get_dclk();
		dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
		dh_total_last_line_length_reg.regValue = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);

		vSyncFreq = ((dclkVal/dh_total_last_line_length_reg.dh_total)/(dv_total_reg.dv_total));
		if(display_timing_ctrl1_reg.multiple_dvs == 1){
			vSyncFreq = vSyncFreq*2;
		}
	}
	printk("Get output frame rate : %d \n", vSyncFreq);
	*pframeRates=vSyncFreq;
	up(&VBE_Semaphore);
#endif
}

void HAL_VBE_DISP_SetBackgroundColor(UINT8 red,UINT8 green,UINT8 blue)
{
	unsigned int color_r, color_b, color_g;

	color_r = red<<8;
	color_g = green<<8;
	color_b = blue<<8;

	drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_BG,  color_r, color_g, color_b);
	/*drvif_scalerDTG_set_bg_color(red,green,blue,1);*/
}

#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO
unsigned char vbe_disp_oled_orbit_enable=FALSE;

void HAL_VBE_DISP_OLED_SetOrbit(BOOLEAN bEnable)
{
	down(&VBE_Semaphore);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_OLED_SetOrbit : %d \n", bEnable);
	vbe_disp_set_orbit(bEnable);

	up(&VBE_Semaphore);
}

void vbe_disp_set_orbit(UINT8 bEnable)
{
	if(bEnable!=vbe_disp_oled_orbit_enable){
		vbe_disp_oled_orbit_enable = bEnable;
		Scaler_reset_orbit();
	}else{
		vbe_disp_oled_orbit_enable = bEnable;
	}
	if(bEnable){
		if(drvif_scalerdisplay_get_force_bg_status()==FALSE) {
			Scaler_start_orbit_algo(TRUE);
		}
    }
}
/*api which have protect by forcebg_semaphore*/
unsigned char vbe_disp_get_orbit(void)
{
	return vbe_disp_oled_orbit_enable;
}

#endif

unsigned char vbe_disp_get_BoeVersion(UINT8 type, DISP_BOE_VERSION_T *pVer)
{
#if 0
	short i, cnt;
	dispd_boe_rgbw_mcu_control_RBUS dispd_boe_rgbw_mcu_control_REG;
	dispd_boe_rgbw_mcu_st_RBUS dispd_boe_rgbw_mcu_st_RBEG;
	dispd_boe_rgbw_apb_w_control_RBUS dispd_boe_rgbw_apb_w_control_REG;
	dispd_boe_rgbw_apb_w_data_RBUS dispd_boe_rgbw_apb_w_data_REG;
	dispd_boe_rgbw_apb_r_control_RBUS dispd_boe_rgbw_apb_r_control_reg;
	dispd_boe_rgbw_apb_r_data_RBUS dispd_boe_rgbw_apb_r_data_reg;

	dispd_boe_rgbw_apb_w_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_control_reg);
	dispd_boe_rgbw_apb_w_data_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_data_reg);

	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc008;
	if(type == BOE_ROM_VERSION)
		dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0xee;
	else if(type == BOE_FW_VERSION)
		dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0xef;
	else{
		dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0xee;
		rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s][%d] [ERROR] Unknow Mode\n", __FUNCTION__,__LINE__);
	}
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	//wclr status
	dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	dispd_boe_rgbw_mcu_st_RBEG.mcu_int_st = 1;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_st_reg, dispd_boe_rgbw_mcu_st_RBEG.regValue);
	rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s][%d] DISPD_BOE_RGBW_mcu_st_reg=%d \n", __FUNCTION__,__LINE__, IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg)&_BIT24);

	// int_in=0 -> wait status=1 -> int_in=1
	dispd_boe_rgbw_mcu_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_control_reg);
	dispd_boe_rgbw_mcu_control_REG.mcu_int_in = 0;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_control_reg, dispd_boe_rgbw_mcu_control_REG.regValue);
	cnt = 0x3ffff;
	do{ // wait b802EC20[24]=1
		dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	}while((cnt--) && dispd_boe_rgbw_mcu_st_RBEG.mcu_int_st == 0);
	if(cnt == 0){
		rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s][%d] [ERROR] mcu_int_st timeout\n", __FUNCTION__,__LINE__);
	}

	dispd_boe_rgbw_apb_r_control_reg.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_r_control_reg);
	dispd_boe_rgbw_apb_r_control_reg.apb_r_addr = 0xc00c;
	IoReg_Write32(DISPD_BOE_RGBW_APB_r_control_reg, dispd_boe_rgbw_apb_r_control_reg.regValue);
	// read data.
	dispd_boe_rgbw_apb_r_data_reg.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_r_data_reg);
	pVer->b0 = dispd_boe_rgbw_apb_r_data_reg.apb_r_data;
	dispd_boe_rgbw_apb_r_data_reg.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_r_data_reg);
	pVer->b1 = dispd_boe_rgbw_apb_r_data_reg.apb_r_data;
	dispd_boe_rgbw_apb_r_data_reg.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_r_data_reg);
	pVer->b2 = dispd_boe_rgbw_apb_r_data_reg.apb_r_data;

	//end communication
	dispd_boe_rgbw_mcu_control_REG.mcu_int_in = 1;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_control_reg, dispd_boe_rgbw_mcu_control_REG.regValue);
	dispd_boe_rgbw_apb_w_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_control_reg);
	dispd_boe_rgbw_apb_w_data_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_w_data_reg);
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc008;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0x00;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_get_BoeVersion] pVer (%x.%x.%x)\n",
		pVer->b0, pVer->b1, pVer->b2);
#endif
	return TRUE;
}

unsigned char vbe_disp_set_BoeMode(UINT8 *pFwData, UINT32 size)
{
#if 0
	UINT32 i, cnt;
	dispd_boe_rgbw_apb_w_control_RBUS dispd_boe_rgbw_apb_w_control_REG;
	dispd_boe_rgbw_apb_w_data_RBUS dispd_boe_rgbw_apb_w_data_REG;
	dispd_boe_rgbw_mcu_control_RBUS dispd_boe_rgbw_mcu_control_REG;
	dispd_boe_rgbw_mcu_st_RBUS dispd_boe_rgbw_mcu_st_RBEG;
	UINT16* pWriteData = (UINT16*)(pFwData);

	// Himax suspend
	dispd_boe_rgbw_apb_w_control_REG.regValue = 0;
	dispd_boe_rgbw_apb_w_data_REG.regValue = 0;
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc008;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0x10;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	//wclr status
	dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	dispd_boe_rgbw_mcu_st_RBEG.mcu_int_st = 1;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_st_reg, dispd_boe_rgbw_mcu_st_RBEG.regValue);
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d] ++DISPD_BOE_RGBW_mcu_st_reg=%d \n", __FUNCTION__,__LINE__, IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg)&_BIT24);

	dispd_boe_rgbw_mcu_control_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_control_reg);
	dispd_boe_rgbw_mcu_control_REG.mcu_int_in = 0;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_control_reg, dispd_boe_rgbw_mcu_control_REG.regValue);
	cnt = 0x3ffff;
	do{ // wait b802EC20[24]=1
		dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	}while((cnt--) && dispd_boe_rgbw_mcu_st_RBEG.mcu_int_st == 0);
	if(cnt == 0){
		rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s][%d] [ERROR] mcu_int_st timeout\n", __FUNCTION__,__LINE__);
	}
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d] DISPD_BOE_RGBW_mcu_st_reg=%d \n", __FUNCTION__,__LINE__, IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg)&_BIT24);

	//end communication
	dispd_boe_rgbw_mcu_control_REG.mcu_int_in = 1;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_control_reg, dispd_boe_rgbw_mcu_control_REG.regValue);
	dispd_boe_rgbw_apb_w_control_REG.regValue = 0;
	dispd_boe_rgbw_apb_w_data_REG.regValue = 0;
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc008;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0x00;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]end communication\n", __FUNCTION__,__LINE__);

	//RESET RGBW-IP-MCU
	dispd_boe_rgbw_apb_w_control_REG.regValue = 0;
	dispd_boe_rgbw_apb_w_data_REG.regValue = 0;
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc000;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0x00;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]RESET RGBW-IP-MCU\n", __FUNCTION__,__LINE__);

	//Access 32K SRAM via APB
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc001;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]Access 32K SRAM via APB\n", __FUNCTION__,__LINE__);

	// === write table 0~0x7dff ===
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 1; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0x0000;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);

	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"pWriteData = %x.%x\n", pWriteData[0], pWriteData[1]);

	for(i = 0; i < (size/2); i++)
	{
		dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = pWriteData[i]&0xff;
		dispd_boe_rgbw_apb_w_data_REG.apb_w_data1 = (pWriteData[i]>>8)&0xff;
		IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	}
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"pWriteData[%d] = %x\n", i-1, pWriteData[i-1]);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d]write table done.\n", __FUNCTION__,__LINE__);

	// === MCU <-> SoC ===
	// C001 = 7; (Control to MCU)
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc001;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 7;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	// wait V-blank
	// C000 = 1; (Reset MCU)
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; // 0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc000;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 1;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
#endif
	return TRUE;
}
void vbe_disp_get_disp_panel_size(DISP_PANEL_SIZE_T *panel_size)
{
	panel_size->DISP_HEIGHT = Get_DISP_ACT_END_VPOS() - Get_DISP_ACT_STA_VPOS();
	panel_size->DISP_WIDTH = Get_DISP_ACT_END_HPOS() - Get_DISP_ACT_STA_HPOS();
}


void vbe_disp_mtg_inner_ptg(UINT8 bOnOff, VBE_DISP_INNER_PTG_TYPE_T type)
{
	if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_R)
		drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_BG,  0x3fff, 0, 0);
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_G)
		drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_BG,  0, 0x3fff, 0);
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_B)
		drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_BG,  0, 0, 0x3fff);
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_WHITE)
		drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_BG,  0x3fff, 0x3fff, 0x3fff);
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_BLACK)
		drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_BG,  0, 0, 0);
	else
		drvif_scalerdisplay_set_bg_color(SLR_MAIN_DISPLAY, _DISPLAY_BG,  0, 0, 0);

	scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, bOnOff);
}

void vbe_disp_memc_inputmux_inner_ptg(UINT8 bOnOff, VBE_DISP_INNER_PTG_TYPE_T type)
{
	ppoverlay_memc_mux_ctrl_RBUS ppoverlay_memc_mux_ctrl_reg;
	ppoverlay_memc_mux_in_color_value_gb_RBUS ppoverlay_memc_mux_in_color_value_gb_reg;
	ppoverlay_memc_mux_in_color_value_r_RBUS ppoverlay_memc_mux_in_color_value_r_reg;
	ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;

	ppoverlay_memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	ppoverlay_memc_mux_in_color_value_gb_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_IN_COLOR_VALUE_GB_reg);
	ppoverlay_memc_mux_in_color_value_r_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_IN_COLOR_VALUE_R_reg);
	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);


	if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_R){
		ppoverlay_memc_mux_in_color_value_gb_reg.in_cb_b_value = 0;
		ppoverlay_memc_mux_in_color_value_gb_reg.in_y_g_value = 0;
		ppoverlay_memc_mux_in_color_value_r_reg.in_cr_r_value = 0xfff;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_G){
		ppoverlay_memc_mux_in_color_value_gb_reg.in_cb_b_value = 0;
		ppoverlay_memc_mux_in_color_value_gb_reg.in_y_g_value = 0xfff;
		ppoverlay_memc_mux_in_color_value_r_reg.in_cr_r_value = 0;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_B){
		ppoverlay_memc_mux_in_color_value_gb_reg.in_cb_b_value = 0xfff;
		ppoverlay_memc_mux_in_color_value_gb_reg.in_y_g_value = 0;
		ppoverlay_memc_mux_in_color_value_r_reg.in_cr_r_value = 0;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_WHITE){
		ppoverlay_memc_mux_in_color_value_gb_reg.in_cb_b_value = 0xfff;
		ppoverlay_memc_mux_in_color_value_gb_reg.in_y_g_value = 0xfff;
		ppoverlay_memc_mux_in_color_value_r_reg.in_cr_r_value = 0xfff;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_BLACK){
		ppoverlay_memc_mux_in_color_value_gb_reg.in_cb_b_value = 0;
		ppoverlay_memc_mux_in_color_value_gb_reg.in_y_g_value = 0;
		ppoverlay_memc_mux_in_color_value_r_reg.in_cr_r_value = 0;
	}
	else{
		ppoverlay_memc_mux_in_color_value_gb_reg.in_cb_b_value = 0;
		ppoverlay_memc_mux_in_color_value_gb_reg.in_y_g_value = 0;
		ppoverlay_memc_mux_in_color_value_r_reg.in_cr_r_value = 0;
	}
	if(bOnOff){
		ppoverlay_memc_mux_ctrl_reg.memc_in_bg_en = 1;
	}else{
		ppoverlay_memc_mux_in_color_value_gb_reg.in_cb_b_value = 0;
		ppoverlay_memc_mux_in_color_value_gb_reg.in_y_g_value = 0;
		ppoverlay_memc_mux_in_color_value_r_reg.in_cr_r_value = 0;
		ppoverlay_memc_mux_ctrl_reg.memc_in_bg_en = 0;
	}
	IoReg_Write32(PPOVERLAY_MEMC_MUX_IN_COLOR_VALUE_GB_reg, ppoverlay_memc_mux_in_color_value_gb_reg.regValue);
	IoReg_Write32(PPOVERLAY_MEMC_MUX_IN_COLOR_VALUE_R_reg, ppoverlay_memc_mux_in_color_value_r_reg.regValue);
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, ppoverlay_memc_mux_ctrl_reg.regValue);

	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_set= 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
}

void vbe_disp_memc_outputmux_inner_ptg(UINT8 bOnOff, VBE_DISP_INNER_PTG_TYPE_T type)
{
	ppoverlay_memc_mux_ctrl_RBUS ppoverlay_memc_mux_ctrl_reg;
	ppoverlay_memc_mux_out1_color_value_gb_RBUS ppoverlay_memc_mux_out1_color_value_gb_reg;
	ppoverlay_memc_mux_out1_color_value_r_RBUS ppoverlay_memc_mux_out1_color_value_r_reg;
	ppoverlay_double_buffer_ctrl2_RBUS ppoverlay_double_buffer_ctrl2_reg;

	ppoverlay_memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	ppoverlay_memc_mux_out1_color_value_gb_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_GB_reg);
	ppoverlay_memc_mux_out1_color_value_r_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_R_reg);
	ppoverlay_double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);


	if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_R){
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_cb_b_value= 0;
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_y_g_value = 0;
		ppoverlay_memc_mux_out1_color_value_r_reg.out_cr_r_value = 0xfff;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_G){
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_cb_b_value = 0;
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_y_g_value = 0xfff;
		ppoverlay_memc_mux_out1_color_value_r_reg.out_cr_r_value = 0;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_B){
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_cb_b_value = 0xfff;
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_y_g_value = 0;
		ppoverlay_memc_mux_out1_color_value_r_reg.out_cr_r_value = 0;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_WHITE){
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_cb_b_value = 0xfff;
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_y_g_value = 0xfff;
		ppoverlay_memc_mux_out1_color_value_r_reg.out_cr_r_value = 0xfff;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_BLACK){
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_cb_b_value = 0;
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_y_g_value = 0;
		ppoverlay_memc_mux_out1_color_value_r_reg.out_cr_r_value = 0;
	}
	else{
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_cb_b_value = 0;
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_y_g_value= 0;
		ppoverlay_memc_mux_out1_color_value_r_reg.out_cr_r_value = 0;
	}
	if(bOnOff){
		ppoverlay_memc_mux_ctrl_reg.memc_out_bg_en = 1;
	}else{
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_cb_b_value = 0;
		ppoverlay_memc_mux_out1_color_value_gb_reg.out_y_g_value = 0;
		ppoverlay_memc_mux_out1_color_value_r_reg.out_cr_r_value = 0;
		ppoverlay_memc_mux_ctrl_reg.memc_out_bg_en = 0;
	}
	IoReg_Write32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_GB_reg, ppoverlay_memc_mux_out1_color_value_gb_reg.regValue);
	IoReg_Write32(PPOVERLAY_MEMC_MUX_OUT1_COLOR_VALUE_R_reg, ppoverlay_memc_mux_out1_color_value_r_reg.regValue);
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg, ppoverlay_memc_mux_ctrl_reg.regValue);

	ppoverlay_double_buffer_ctrl2_reg.uzudtgreg_dbuf_set= 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, ppoverlay_double_buffer_ctrl2_reg.regValue);
}

void vbe_disp_sfg_inner_ptg(UINT8 bOnOff, VBE_DISP_INNER_PTG_TYPE_T type)
{
	sfg_sfg_force_bg_at_dif_RBUS sfg_sfg_force_bg_at_dif_reg;

	sfg_sfg_force_bg_at_dif_reg.regValue = IoReg_Read32(SFG_SFG_FORCE_BG_AT_DIF_reg);

	if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_R){
		sfg_sfg_force_bg_at_dif_reg.bg_dif_red = 0x3ff;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_grn = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_blu = 0;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_G){
		sfg_sfg_force_bg_at_dif_reg.bg_dif_red = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_grn = 0x3ff;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_blu = 0;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_B){
		sfg_sfg_force_bg_at_dif_reg.bg_dif_red = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_grn = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_blu = 0x3ff;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_WHITE){
		sfg_sfg_force_bg_at_dif_reg.bg_dif_red = 0x3ff;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_grn = 0x3ff;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_blu = 0x3ff;
	}
	else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_BLACK){
		sfg_sfg_force_bg_at_dif_reg.bg_dif_red = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_grn = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_blu = 0;
	}
	else{
		sfg_sfg_force_bg_at_dif_reg.bg_dif_red = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_grn = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_blu = 0;
	}
	if(bOnOff){
		sfg_sfg_force_bg_at_dif_reg.en_force_bg_dif = 1;
	}else{
		sfg_sfg_force_bg_at_dif_reg.en_force_bg_dif = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_red = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_grn = 0;
		sfg_sfg_force_bg_at_dif_reg.bg_dif_blu = 0;
	}
	IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, sfg_sfg_force_bg_at_dif_reg.regValue);

}

void vbe_disp_uzu_inner_ptg(UINT8 bOnOff, VBE_DISP_INNER_PTG_TYPE_T type)
{
	scaleup_d_uzu_globle_ctrl_RBUS scaleup_d_uzu_globle_ctrl_reg;
	scaleup_dm_uzu_input_size_RBUS scaleup_dm_uzu_input_size_reg;
	scaleup_d_uzu_patgen_frame_toggle_RBUS scaleup_d_uzu_patgen_frame_toggle_reg;
	unsigned int colorBar_width=0;

	scaleup_d_uzu_globle_ctrl_reg.regValue = IoReg_Read32(SCALEUP_D_UZU_Globle_Ctrl_reg);
	scaleup_dm_uzu_input_size_reg.regValue = IoReg_Read32(SCALEUP_DM_UZU_Input_Size_reg);
	scaleup_d_uzu_patgen_frame_toggle_reg.regValue = IoReg_Read32(SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg);

	colorBar_width = (scaleup_dm_uzu_input_size_reg.hor_input_size/8)-1;
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"colorBar_width=%x\n", colorBar_width);

	if(type == VBE_DISP_INNER_PTG_TYPE_RANDOM_GEN){
		scaleup_d_uzu_globle_ctrl_reg.patgen_mode = 0;
	}else if(type == VBE_DISP_INNER_PTG_TYPE_COLOR_BAR){
		scaleup_d_uzu_globle_ctrl_reg.patgen_mode = 3; // color bar
		scaleup_d_uzu_patgen_frame_toggle_reg.patgen_width = colorBar_width;
	}else{
		scaleup_d_uzu_globle_ctrl_reg.patgen_mode = 0;
	}

	if(bOnOff){
		scaleup_d_uzu_globle_ctrl_reg.patgen_sel = 1;
	}else{
		scaleup_d_uzu_globle_ctrl_reg.patgen_sel = 0;
	}
	IoReg_Write32(SCALEUP_D_UZU_Globle_Ctrl_reg, scaleup_d_uzu_globle_ctrl_reg.regValue);
	IoReg_Write32(SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg, scaleup_d_uzu_patgen_frame_toggle_reg.regValue);
}

void vbe_disp_vgip_inner_ptg(UINT8 bOnOff, VBE_DISP_INNER_PTG_TYPE_T type)
{
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	vgip_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);
	if(bOnOff)
		vgip_vgip_chn1_ctrl_reg.ch1_random_en = 1;
	else
		vgip_vgip_chn1_ctrl_reg.ch1_random_en = 0;
	IoReg_Write32(VGIP_VGIP_CHN1_CTRL_reg, vgip_vgip_chn1_ctrl_reg.regValue);

}

void vbe_disp_set_inner_ptg(UINT8 bOnOff, VBE_DISP_INNER_PTG_BLOCK_T block, VBE_DISP_INNER_PTG_TYPE_T type)
{
	if(block == VBE_DISP_INNER_PTG_BLOCK_VGIP){
		vbe_disp_vgip_inner_ptg(bOnOff, type);
	}else if(block == VBE_DISP_INNER_PTG_BLOCK_MTG){
		vbe_disp_mtg_inner_ptg(bOnOff, type);
	}else if(block == VBE_DISP_INNER_PTG_BLOCK_UZU){
		vbe_disp_uzu_inner_ptg(bOnOff, type);
	}else if(block == VBE_DISP_INNER_PTG_BLOCK_MEMC_INPUTMUX){
		vbe_disp_memc_inputmux_inner_ptg(bOnOff, type);
	}else if(block == VBE_DISP_INNER_PTG_BLOCK_MEMC_OUTPUTMUX){
		vbe_disp_memc_outputmux_inner_ptg(bOnOff, type);
	}else if(block == VBE_DISP_INNER_PTG_BLOCK_SFG){
		vbe_disp_sfg_inner_ptg(bOnOff, type);
	}else{
		rtd_printk(KERN_ERR, TAG_NAME_VBE,"[%s] Error block :%d \n", __FUNCTION__, block);
	}
}

void HAL_VBE_DISP_SetBOEMode(UINT8 *pFwData, UINT32 size)
{
	down(&VBE_Semaphore);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_SetBOEMode, size:%d \n", size);

	down(&VBE_RGBW_Resume_Semaphore);
	vbe_disp_set_BoeMode(pFwData, size);
	up(&VBE_RGBW_Resume_Semaphore);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_GetBOEVersion(DISP_BOE_VERSION_T *pstRomVer, DISP_BOE_VERSION_T *pstFwVer)
{
	down(&VBE_Semaphore);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_GetBOEVersion\n");

	down(&VBE_RGBW_Resume_Semaphore);
	vbe_disp_get_BoeVersion(BOE_ROM_VERSION, pstRomVer);
	vbe_disp_get_BoeVersion(BOE_FW_VERSION, pstFwVer);
	up(&VBE_RGBW_Resume_Semaphore);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_SetMLEMode(VBE_DISP_MLE_MODE_T index)
{
	down(&VBE_Semaphore);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_SetMLEMode : %d \n", index);

	DISP_MLE_MODE_T MLE_Idx = 0;

	memcpy((void*)&MLE_Idx, (void*)&index, sizeof(DISP_MLE_MODE_T));

	fwif_color_set_Mplus_ModeChange_TV006(MLE_Idx);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_SetInnerPattern(UINT8 bOnOff, VBE_DISP_INNER_PTG_BLOCK_T block, VBE_DISP_INNER_PTG_TYPE_T type)
{
	down(&VBE_Semaphore);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_SetInnerPattern\n");
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"bOnOff=%d, block%d, type=%d\n", bOnOff, block, type);

	vbe_disp_set_inner_ptg(bOnOff, block, type);

	up(&VBE_Semaphore);

}

extern void fwif_color_set_SetBOERGBWBypass_TV006(unsigned char BOE_EN);
extern void fwif_color_SetFrameGainLimit_TV006(unsigned short nFrameGainLimit);
extern void fwif_color_GetFrameGainLimit_TV006(unsigned short *nFrameGainLimit);
extern void fwif_color_SetPixelGainLimit_TV006(unsigned short nPixelGainLimit);
extern void fwif_color_GetPixelGainLimit_TV006(unsigned short *nPixelGainLimit);

void HAL_VBE_DISP_SetBOERGBWBypass(BOOLEAN bEnable)
{
	down(&VBE_Semaphore);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_SetBOERGBWBypass : %d \n", bEnable);

	if (Get_DISPLAY_PANEL_BOW_RGBW() == TRUE) /*protection for BOE*/
		fwif_color_set_SetBOERGBWBypass_TV006(bEnable);

	up(&VBE_Semaphore);
}


extern void fwif_color_set_output_gamma_4CHDGA_TV006 (UINT32 *pRedGammaTable, UINT32 * pGreenGammaTable, UINT32 * pBlueGammaTable, UINT32 * pWhiteGammaTable, UINT16 nTableSize);

void HAL_VBE_SetDGA4CH (UINT32 *pRedGammaTable, UINT32 *pGreenGammaTable, UINT32 *pBlueGammaTable, UINT32 *pWhiteGammaTable, UINT16 nTableSize)
{
	down(&VBE_Semaphore);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_SetDGA4CH\n");
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"nTableSize = %d \n", nTableSize);
	fwif_color_set_output_gamma_4CHDGA_TV006(pRedGammaTable,pGreenGammaTable,pBlueGammaTable,pWhiteGammaTable,nTableSize);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_SetFrameGainLimit(UINT16 nFrameGainLimit)
{
	down(&VBE_Semaphore);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_SetFrameGainLimit : %d \n", nFrameGainLimit);

	fwif_color_SetFrameGainLimit_TV006(nFrameGainLimit);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_GetFrameGainLimit (UINT16 *nFrameGainLimit)
{
	down(&VBE_Semaphore);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_GetFrameGainLimit : %d \n", nFrameGainLimit);

	fwif_color_GetFrameGainLimit_TV006(nFrameGainLimit);

	up(&VBE_Semaphore);
}


void HAL_VBE_DISP_SetPixelGainLimit (UINT16 nPixelGainLimit)
{
	down(&VBE_Semaphore);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_SetPixelGainLimit : %d \n", nPixelGainLimit);

	fwif_color_SetPixelGainLimit_TV006(nPixelGainLimit);

	up(&VBE_Semaphore);
}


void HAL_VBE_DISP_GetPixelGainLimit (UINT16 *nPixelGainLimit)
{
	down(&VBE_Semaphore);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_GetPixelGainLimit : %d \n", nPixelGainLimit);

	fwif_color_GetPixelGainLimit_TV006(nPixelGainLimit);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_GetPanelSize(DISP_PANEL_SIZE_T *panel_size)
{
	down(&VBE_Semaphore);

	vbe_disp_get_disp_panel_size(panel_size);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"HAL_VBE_DISP_GetPanelSize : w = %d , h = %d \n", panel_size->DISP_WIDTH, panel_size->DISP_HEIGHT);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_Set_Panel_Ti_Mode(UINT8 table)
{
	pif_lvds_ctrl3_RBUS  lvds_ctrl3_reg;

	down(&VBE_Semaphore);

	lvds_ctrl3_reg.regValue = rtd_inl(PIF_LVDS_CTRL3_reg);
	lvds_ctrl3_reg.lvds_map = (table?1:0);
	rtd_outl(PIF_LVDS_CTRL3_reg, lvds_ctrl3_reg.regValue);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] set table = %d \n", __FUNCTION__, table);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_Set_Panel_Bit_Mode(UINT8 bitMode)
{
	down(&VBE_Semaphore);

	//0: 30bits, 1:24 bits, 2: 18bits
	if(bitMode>2){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] set bitMode = %d err. apply 30bits\n", bitMode);
		bitMode = 0;
	}
	sfg_sfg_zz_shift_dbg_ctrl_RBUS sfg_zz_shift_dbg_ctrl_reg;
	sfg_zz_shift_dbg_ctrl_reg.regValue = rtd_inl(SFG_SFG_ZZ_shift_dbg_CTRL_reg);
	sfg_zz_shift_dbg_ctrl_reg.dout_mode = bitMode;
	rtd_outl(SFG_SFG_ZZ_shift_dbg_CTRL_reg, sfg_zz_shift_dbg_ctrl_reg.regValue);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] set bitMode = %d \n", __FUNCTION__, bitMode);

	up(&VBE_Semaphore);
}

void HAL_VBE_DISP_Set_Panel_Swap_Mode(UINT8 bSwap)
{
	sfg_sfg_swap_ctrl1_RBUS sfg_swap_ctrl1_reg;
	sfg_sfg_swap_ctrl2_RBUS sfg_swap_ctrl2_reg;
	UINT32 port_config1=0;
	UINT8 temp=0;

	down(&VBE_Semaphore);

	port_config1 = Get_DISPLAY_PORT_CONFIG1();

	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] set Get_DISPLAY_PORT_CONFIG1() = %x \n", __FUNCTION__, Get_DISPLAY_PORT_CONFIG1());

	sfg_swap_ctrl1_reg.regValue = rtd_inl(SFG_SFG_SWAP_CTRL1_reg);
	sfg_swap_ctrl2_reg.regValue = rtd_inl(SFG_SFG_SWAP_CTRL2_reg);
	sfg_swap_ctrl1_reg.output_porta = (port_config1&0xf0000000)>>28;
	sfg_swap_ctrl1_reg.output_portb = (port_config1&0x0f000000)>>24;
	sfg_swap_ctrl1_reg.output_portc = (port_config1&0x00f00000)>>20;
	sfg_swap_ctrl1_reg.output_portd = (port_config1&0x000f0000)>>16;
	sfg_swap_ctrl2_reg.output_porte = (port_config1&0x0000f000)>>12;
	sfg_swap_ctrl2_reg.output_portf = (port_config1&0x00000f00)>>8;
	sfg_swap_ctrl2_reg.output_portg = (port_config1&0x000000f0)>>4;
	sfg_swap_ctrl2_reg.output_porth = (port_config1&0x0000000f);
/*
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] output_porta~output_porth(%x.%x.%x.%x.%x.%x.%x.%x)\n", __FUNCTION__,
		sfg_swap_ctrl1_reg.output_porta,
		sfg_swap_ctrl1_reg.output_portb,
		sfg_swap_ctrl1_reg.output_portc,
		sfg_swap_ctrl1_reg.output_portd,
		sfg_swap_ctrl2_reg.output_porte,
		sfg_swap_ctrl2_reg.output_portf,
		sfg_swap_ctrl2_reg.output_portg,
		sfg_swap_ctrl2_reg.output_porth
	);
*/
	if(bSwap){
		temp = sfg_swap_ctrl1_reg.output_porta;
		sfg_swap_ctrl1_reg.output_porta = sfg_swap_ctrl1_reg.output_portb;
		sfg_swap_ctrl1_reg.output_portb = temp;

		temp = sfg_swap_ctrl1_reg.output_portc;
		sfg_swap_ctrl1_reg.output_portc = sfg_swap_ctrl1_reg.output_portd;
		sfg_swap_ctrl1_reg.output_portd = temp;

		temp = sfg_swap_ctrl2_reg.output_porte;
		sfg_swap_ctrl2_reg.output_porte = sfg_swap_ctrl2_reg.output_portf;
		sfg_swap_ctrl2_reg.output_portf = temp;

		temp = sfg_swap_ctrl2_reg.output_portg;
		sfg_swap_ctrl2_reg.output_portg = sfg_swap_ctrl2_reg.output_porth;
		sfg_swap_ctrl2_reg.output_porth = temp;
	}
	rtd_outl(SFG_SFG_SWAP_CTRL1_reg, sfg_swap_ctrl1_reg.regValue);
	rtd_outl(SFG_SFG_SWAP_CTRL2_reg, sfg_swap_ctrl2_reg.regValue);
/*
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] set port_config = (%x.%x)\n", __FUNCTION__, sfg_swap_ctrl1_reg.regValue, sfg_swap_ctrl2_reg.regValue);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] (SWAP) output_porta~output_porth(%x.%x.%x.%x.%x.%x.%x.%x)\n", __FUNCTION__,
		sfg_swap_ctrl1_reg.output_porta,
		sfg_swap_ctrl1_reg.output_portb,
		sfg_swap_ctrl1_reg.output_portc,
		sfg_swap_ctrl1_reg.output_portd,
		sfg_swap_ctrl2_reg.output_porte,
		sfg_swap_ctrl2_reg.output_portf,
		sfg_swap_ctrl2_reg.output_portg,
		sfg_swap_ctrl2_reg.output_porth
	);
*/
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] set swap = %d \n", __FUNCTION__, bSwap);

	up(&VBE_Semaphore);
}

void Scaler_set_lvds_to_hdmi_parameter(DISP_PANEL_ATTRIBUTE_T * pPanelAttr,UINT8 framerate)
{
	unsigned int panel_width,panel_height;
	PANEL_CONFIG_PARAMETER parameter;
	panel_width=(pPanelAttr->panelResolution>>12)&0xffff;
	panel_height=pPanelAttr->panelResolution&0xfff;

	memset(&parameter,0,sizeof(PANEL_CONFIG_PARAMETER));

	parameter.iCONFIG_PANEL_TYPE=P_LVDS_TO_HDMI;

	parameter.iCONFIG_DISPLAY_PORT=pPanelAttr->eLVDSPixel;
	parameter.iCONFIG_DISPLAY_BITMAPPING_TABLE=(pPanelAttr->eLVDSSelect)?0:1;  //pPanelAttr.eLVDSSelect 0 is VESA,1 is JEIDA
	parameter.iCONFIG_DISPLAY_COLOR_BITS=(pPanelAttr->eColorDepth)?0:1;   //pPanelAttr.eColorDepth 0 is 8bit,1 is 10bit
	parameter.iCONFIG_DISPLAY_HORIZONTAL_SYNC_NORMAL=1;
	parameter.iCONFIG_DISPLAY_VERTICAL_SYNC_NORMAL=1;

	parameter.iCONFIG_DISP_ACT_STA_HPOS=0;
	parameter.iCONFIG_DISP_ACT_END_HPOS=panel_width;
	parameter.iCONFIG_DISP_ACT_STA_VPOS=0;
	parameter.iCONFIG_DISP_ACT_END_VPOS=panel_height;
	parameter.iCONFIG_DISP_HORIZONTAL_TOTAL=pPanelAttr->horizTypPeriod; //Dh total need as even

	parameter.iCONFIG_DISPLAY_REFRESH_RATE=framerate;
	parameter.iCONFIG_DISPLAY_CLOCK_MIN=126;
	parameter.iCONFIG_DISPLAY_CLOCK_MAX=154;
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MIN=pPanelAttr->vertBackPorch50Hz;
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_50Hz_MAX=pPanelAttr->vertTypPeriod50Hz;
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MIN=pPanelAttr->vertBackPorch60Hz;
	parameter.iCONFIG_DISP_VERTICAL_TOTAL_60Hz_MAX=pPanelAttr->vertTypPeriod60Hz;

	parameter.iCONFIG_DISP_VERTICAL_TOTAL=pPanelAttr->vertTypPeriod60Hz;
	parameter.iCONFIG_DISPLAY_CLOCK_TYPICAL=framerate*pPanelAttr->horizTypPeriod*pPanelAttr->vertTypPeriod60Hz;
	parameter.iCONFIG_DISP_DEN_STA_VPOS=pPanelAttr->vertBackPorch60Hz;
	parameter.iCONFIG_DISP_DEN_END_VPOS=pPanelAttr->vertBackPorch60Hz+panel_height;
	parameter.iCONFIG_DISP_VSYNC_LENGTH=pPanelAttr->vertSyncWidth60Hz;
	parameter.iCONFIG_DISP_HSYNC_WIDTH =pPanelAttr->horizSyncWidth60Hz;
	parameter.iCONFIG_DISP_DEN_STA_HPOS=pPanelAttr->horizBackPorch60Hz;
	parameter.iCONFIG_DISP_DEN_END_HPOS=pPanelAttr->horizBackPorch60Hz+panel_width;

	parameter.iCONFIG_DISP_HSYNC_LASTLINE=pPanelAttr->horizTypPeriod-1;

	Panel_InitParameter(&parameter);
}
#ifdef CONFIG_PM
//VBE_DISP_SUSPEND_RESUME_T vbe_disp_suspend_resume;

void panel_epi_resume_flow(void)
{
#if 0
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"###[%s][Line:%d]###\n", __FUNCTION__, __LINE__);
	msleep(1);
	rtd_setbits(VBY1_VIDEO_FORMAT_reg, _BIT23);	// 0xb802D700 lane 0~7 disable, lane 8~15 use EPI 8~15, lane 16~23 use EPI 16~23,
	rtd_outl(SFG_SFG_DUMMY_reg, 0x00000000);	// 0xb802D9B8 EPI Clock Disable, Data inverse disable,
	rtd_outl(PINMUX_LVDSPHY_VBY1EPI_90_reg, 0x00000000);	// 0xB8000E90 lane power disable
	rtd_setbits(EPI_EPI_CLOCK_CTRL0_reg, _BIT28);	// 0xb8026064, EPI reset enable, CST/C3/DST packet disable, EPI lock HW mode,
	msleep(1);
	rtd_setbits(SFG_SFG_DUMMY_reg, _BIT30);	//0xb802D9B8  EPI Clock Enable
	msleep(1);
	rtd_clearbits(EPI_EPI_CLOCK_CTRL0_reg, _BIT28);	// 0xb8026064, EPI reset disable
	IoReg_Write32(PINMUX_LVDSPHY_VBY1EPI_90_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_VBY1EPI_90_S_R); // 0xB8000E90 enable lane power
	msleep(1);
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, vbe_disp_suspend_resume.CRT_PLL_SSC4_S_R);
#endif
}

void vbe_disp_panel_mplus_resume_flow(void)
{
/*  //fix me later by benwang
	sys_reg_sys_srst3_RBUS sys_reg_sys_srst3_reg;
	sys_reg_sys_clken3_RBUS sys_reg_sys_clken3_reg;
	ppoverlay_display_timing_ctrl1_RBUS ppoverlay_display_timing_ctrl1_reg;
	ppoverlay_display_timing_ctrl2_RBUS ppoverlay_display_timing_ctrl2_reg;
	lg_m_plus_m_plus_ctl_RBUS lg_m_plus_m_plus_ctl_reg;

	//sys_reg_sys_srst3_reg.regValue = IoReg_Read32(SYS_REG_SYS_SRST3_reg);
	sys_reg_sys_srst3_reg.regValue = 0;
	sys_reg_sys_srst3_reg.rstn_disp_lg_mplus = 1;
	sys_reg_sys_srst3_reg.write_data = 1;
	IoReg_Write32(SYS_REG_SYS_SRST3_reg,sys_reg_sys_srst3_reg.regValue);

	//sys_reg_sys_clken3_reg.regValue = IoReg_Read32(SYS_REG_SYS_CLKEN3_reg);
	sys_reg_sys_clken3_reg.regValue = 0;
	sys_reg_sys_clken3_reg.clken_disp_lg_mplus = 1;
	sys_reg_sys_clken3_reg.write_data = 1;
	IoReg_Write32(SYS_REG_SYS_CLKEN3_reg,sys_reg_sys_clken3_reg.regValue);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"###[%s][Line:%d]###\n", __FUNCTION__, __LINE__);


	//Mplus parameter
	if(Get_DISPLAY_PANEL_CUSTOM_INDEX() == P_EPI_LG_LC430EGG_UHD60_6LANE){
		pr_emerg("////P_EPI_LG_LC430EGG_UHD60_6LANE///// \n");
		rtd_outl(0xB8028C04, 0xF8F1F1F8);//reg00~reg03
		rtd_outl(0xB8028C08, 0xDF100010);//reg04~reg07
		rtd_outl(0xB8028C0C, 0x000F3310);//reg08~reg0B
		rtd_outl(0xB8028C10, 0x00100010);//reg0C~reg0F
		rtd_outl(0xB8028C14, 0x0010D810);//reg10~reg13
		rtd_outl(0xB8028C18, 0x00040004);//reg14~reg17
		rtd_outl(0xB8028C1C, 0x00040004);//reg18~reg1B
		rtd_outl(0xB8028C20, 0x00040000);//reg1C~reg1F
		rtd_outl(0xB8028C24, 0x0FD20000);//reg20~reg23
		rtd_outl(0xB8028C28, 0x7E900000);//reg24~reg27
		rtd_outl(0xB8028C2C, 0x0FD20000);//reg28~reg2B
		rtd_outl(0xB8028C30, 0x7E900000);//reg2C~reg2F
		rtd_outl(0xB8028C34, 0x0FD20000);//reg30~reg33
		rtd_outl(0xB8028C38, 0x0FD20000);//reg34~reg37
		rtd_outl(0xB8028C3C, 0x7E900000);//reg38~reg3B
		rtd_outl(0xB8028C40, 0x0FD20000);//reg3C~reg3F
		rtd_outl(0xB8028C44, 0x7E900000);//reg40~reg43
		rtd_outl(0xB8028C48, 0x0FD20000);//reg44~reg47
		rtd_outl(0xB8028C4C, 0x00000000);//reg48~reg4B
		rtd_outl(0xB8028C50, 0x2AAB2000);//reg4C~reg4F
		rtd_outl(0xB8028C54, 0x20003FFF);//reg50~reg53
		rtd_outl(0xB8028C58, 0x30000606);//reg54~reg57
		rtd_outl(0xB8028C5C, 0x06061001);//reg58~reg5B
		rtd_outl(0xB8028C60, 0x00019801);//reg5C~reg5F
		rtd_outl(0xB8028C64, 0x98019801);//reg60~reg63
		rtd_outl(0xB8028C68, 0x98080008);//reg64~reg67
		rtd_outl(0xB8028C6C, 0x00080008);//reg68~reg6B
		rtd_outl(0xB8028C70, 0x00060606);//reg6C~reg6F
		rtd_outl(0xB8028C74, 0x06200015);//reg70~reg73
		rtd_outl(0xB8028C78, 0x55100010);//reg74~reg77
		rtd_outl(0xB8028C7C, 0x00200010);//reg78~reg7B
		rtd_outl(0xB8028C80, 0x00100010);//reg7C~reg7F
		rtd_outl(0xB8028C84, 0x00100010);//reg80~reg83
		rtd_outl(0xB8028C88, 0x001000FF);//reg84~reg87
		rtd_outl(0xB8028C8C, 0xFFFFFFFF);//reg88~reg8B
		rtd_outl(0xB8028C90, 0x01000200);//reg8C~reg8F
		rtd_outl(0xB8028C94, 0x03000400);//reg90~reg93
		rtd_outl(0xB8028C98, 0x05000600);//reg94~reg97
		rtd_outl(0xB8028C9C, 0x07000800);//reg98~reg9B
		rtd_outl(0xB8028CA0, 0x09000A00);//reg9C~reg9F
		rtd_outl(0xB8028CA4, 0x0B000C00);//regA0~regA3
		rtd_outl(0xB8028CA8, 0x0D000E00);//regA4~regA7
		rtd_outl(0xB8028CAC, 0x0F003000);//regA8~regAB
		rtd_outl(0xB8028CB0, 0x08802000);//regAC~regAF
		rtd_outl(0xB8028CB4, 0x10000818);//regB0~regB3
		rtd_outl(0xB8028CB8, 0x08006010);//regB4~regB7
		rtd_outl(0xB8028CBC, 0x25600C00);//regB8~regBB
		rtd_outl(0xB8028CC0, 0x1AAC6C05);//regBC~regBF
		rtd_outl(0xB8028CC4, 0x05080808);//regC0~regC3
		rtd_outl(0xB8028CC8, 0x98830E1D);//regC4~regC7
		rtd_outl(0xB8028CCC, 0x28405060);//regC8~regCB
		rtd_outl(0xB8028CD0, 0x708090A0);//regCC~regCF
		rtd_outl(0xB8028CD4, 0xB0C0D0E0);//regD0~regD3
		rtd_outl(0xB8028CD8, 0xF0FFFFFF);//regD4~regD7
		rtd_outl(0xB8028CDC, 0xFFFFFFFF);//regD8~regDB
		rtd_outl(0xB8028CE0, 0xFFFFFFFF);//regDC~regDF
		rtd_outl(0xB8028CE4, 0xFF0A06F0);//regE0~regE3
		rtd_outl(0xB8028CE8, 0x0FF00F08);//regE4~regE7
		rtd_outl(0xB8028CEC, 0x00100000);//regE8~regEB
		rtd_outl(0xB8028CF0, 0x00040004);//regEC~regEF
		rtd_outl(0xB8028D1C, 0x0FF01D37);//regF0~regF3
		rtd_outl(0xB8028D20, 0x371D1D37);//regF4~regF7
		rtd_outl(0xB8028D24, 0x371D0000);//regF8~regFB
		rtd_outl(0xB8028D28, 0x00000000);//regFC~regFF
		rtd_outl(0xB8028D2C, 0x0F200105);//reg100~reg103
		rtd_outl(0xB8028D30, 0x00180008);//reg104~reg107
		rtd_outl(0xB8028D34, 0x00000000);//reg108~reg10B
		rtd_outl(0xB8028D38, 0x0400100A);//reg10C~reg10F
		rtd_outl(0xB8028D3C, 0x00000010);//reg110~reg113
		rtd_outl(0xB8028D40, 0x0001FF00);//reg114~reg117
		rtd_outl(0xB8028D44, 0x00040000);//reg118~reg11B
		rtd_outl(0xB8028D48, 0x00000000);//reg11C~reg11F
		rtd_outl(0xB8028D4C, 0x10F50480);//reg120~reg123
		rtd_outl(0xB8028D50, 0x40210000);//reg124~reg127
	}else if(Get_DISPLAY_PANEL_CUSTOM_INDEX() == P_EPI_LG_LC490EGG_UHD60_6LANE){
		pr_emerg("////P_EPI_LG_LC490EGG_UHD60_6LANE///// \n");
		rtd_outl(0xB8028C04, 0xF8F1F1F8);//reg00~reg03
		rtd_outl(0xB8028C08, 0xDF0C0010);//reg04~reg07
		rtd_outl(0xB8028C0C, 0x000C7B10);//reg08~reg0B
		rtd_outl(0xB8028C10, 0x00155510);//reg0C~reg0F
		rtd_outl(0xB8028C14, 0x00148310);//reg10~reg13
		rtd_outl(0xB8028C18, 0x00040004);//reg14~reg17
		rtd_outl(0xB8028C1C, 0x00040004);//reg18~reg1B
		rtd_outl(0xB8028C20, 0x00040000);//reg1C~reg1F
		rtd_outl(0xB8028C24, 0x0FD20000);//reg20~reg23
		rtd_outl(0xB8028C28, 0x7E900000);//reg24~reg27
		rtd_outl(0xB8028C2C, 0x0FD20000);//reg28~reg2B
		rtd_outl(0xB8028C30, 0x7E900000);//reg2C~reg2F
		rtd_outl(0xB8028C34, 0x0FD20000);//reg30~reg33
		rtd_outl(0xB8028C38, 0x0FD20000);//reg34~reg37
		rtd_outl(0xB8028C3C, 0x7E900000);//reg38~reg3B
		rtd_outl(0xB8028C40, 0x0FD20000);//reg3C~reg3F
		rtd_outl(0xB8028C44, 0x7E900000);//reg40~reg43
		rtd_outl(0xB8028C48, 0x0FD20000);//reg44~reg47
		rtd_outl(0xB8028C4C, 0x00000000);//reg48~reg4B
		rtd_outl(0xB8028C50, 0x2AAB2000);//reg4C~reg4F
		rtd_outl(0xB8028C54, 0x20003FFF);//reg50~reg53
		rtd_outl(0xB8028C58, 0x30000606);//reg54~reg57
		rtd_outl(0xB8028C5C, 0x06061001);//reg58~reg5B
		rtd_outl(0xB8028C60, 0x00019801);//reg5C~reg5F
		rtd_outl(0xB8028C64, 0x98019801);//reg60~reg63
		rtd_outl(0xB8028C68, 0x98080008);//reg64~reg67
		rtd_outl(0xB8028C6C, 0x00080008);//reg68~reg6B
		rtd_outl(0xB8028C70, 0x00060606);//reg6C~reg6F
		rtd_outl(0xB8028C74, 0x06200015);//reg70~reg73
		rtd_outl(0xB8028C78, 0x55100010);//reg74~reg77
		rtd_outl(0xB8028C7C, 0x00200010);//reg78~reg7B
		rtd_outl(0xB8028C80, 0x00100010);//reg7C~reg7F
		rtd_outl(0xB8028C84, 0x00100010);//reg80~reg83
		rtd_outl(0xB8028C88, 0x001000FF);//reg84~reg87
		rtd_outl(0xB8028C8C, 0xFFFFFFFF);//reg88~reg8B
		rtd_outl(0xB8028C90, 0x01000200);//reg8C~reg8F
		rtd_outl(0xB8028C94, 0x03000400);//reg90~reg93
		rtd_outl(0xB8028C98, 0x05000600);//reg94~reg97
		rtd_outl(0xB8028C9C, 0x07000800);//reg98~reg9B
		rtd_outl(0xB8028CA0, 0x09000A00);//reg9C~reg9F
		rtd_outl(0xB8028CA4, 0x0B000C00);//regA0~regA3
		rtd_outl(0xB8028CA8, 0x0D000E00);//regA4~regA7
		rtd_outl(0xB8028CAC, 0x0F003000);//regA8~regAB
		rtd_outl(0xB8028CB0, 0x08802000);//regAC~regAF
		rtd_outl(0xB8028CB4, 0x10000818);//regB0~regB3
		rtd_outl(0xB8028CB8, 0x08006010);//regB4~regB7
		rtd_outl(0xB8028CBC, 0x25600C00);//regB8~regBB
		rtd_outl(0xB8028CC0, 0x1AAC6C05);//regBC~regBF
		rtd_outl(0xB8028CC4, 0x05080808);//regC0~regC3
		rtd_outl(0xB8028CC8, 0x98830E1D);//regC4~regC7
		rtd_outl(0xB8028CCC, 0x28405060);//regC8~regCB
		rtd_outl(0xB8028CD0, 0x708090A0);//regCC~regCF
		rtd_outl(0xB8028CD4, 0xB0C0D0E0);//regD0~regD3
		rtd_outl(0xB8028CD8, 0xF0FFFFFF);//regD4~regD7
		rtd_outl(0xB8028CDC, 0xFFFFFFFF);//regD8~regDB
		rtd_outl(0xB8028CE0, 0xFFFFFFFF);//regDC~regDF
		rtd_outl(0xB8028CE4, 0xFF0A06F0);//regE0~regE3
		rtd_outl(0xB8028CE8, 0x0FF00F08);//regE4~regE7
		rtd_outl(0xB8028CEC, 0x00100000);//regE8~regEB
		rtd_outl(0xB8028CF0, 0x00040004);//regEC~regEF
		rtd_outl(0xB8028D1C, 0x0FF01D37);//regF0~regF3
		rtd_outl(0xB8028D20, 0x371D1D37);//regF4~regF7
		rtd_outl(0xB8028D24, 0x371D0000);//regF8~regFB
		rtd_outl(0xB8028D28, 0x00000000);//regFC~regFF
		rtd_outl(0xB8028D2C, 0x0F200105);//reg100~reg103
		rtd_outl(0xB8028D30, 0x00180008);//reg104~reg107
		rtd_outl(0xB8028D34, 0x00000000);//reg108~reg10B
		rtd_outl(0xB8028D38, 0x0400100A);//reg10C~reg10F
		rtd_outl(0xB8028D3C, 0x00000010);//reg110~reg113
		rtd_outl(0xB8028D40, 0x0001FF00);//reg114~reg117
		rtd_outl(0xB8028D44, 0x00040000);//reg118~reg11B
		rtd_outl(0xB8028D48, 0x00000000);//reg11C~reg11F
		rtd_outl(0xB8028D4C, 0x10F50480);//reg120~reg123
		rtd_outl(0xB8028D50, 0x40210000);//reg124~reg127
	}else if(Get_DISPLAY_PANEL_CUSTOM_INDEX() == P_EPI_LG_LC550EGG_UHD60_6LANE){
		pr_emerg("////P_EPI_LG_LC550EGG_UHD60_6LANE///// \n");
		rtd_outl(0xB8028C04, 0xF8F1F1F9);//reg00~reg03
		rtd_outl(0xB8028C08, 0xDF0D9A10);//reg04~reg07
		rtd_outl(0xB8028C0C, 0x000D9A10);//reg08~reg0B
		rtd_outl(0xB8028C10, 0x0012D310);//reg0C~reg0F
		rtd_outl(0xB8028C14, 0x0012D310);//reg10~reg13
		rtd_outl(0xB8028C18, 0x00040004);//reg14~reg17
		rtd_outl(0xB8028C1C, 0x00040004);//reg18~reg1B
		rtd_outl(0xB8028C20, 0x00040000);//reg1C~reg1F
		rtd_outl(0xB8028C24, 0x0FD20000);//reg20~reg23
		rtd_outl(0xB8028C28, 0x7E900000);//reg24~reg27
		rtd_outl(0xB8028C2C, 0x0FD20000);//reg28~reg2B
		rtd_outl(0xB8028C30, 0x7E900000);//reg2C~reg2F
		rtd_outl(0xB8028C34, 0x0FD20000);//reg30~reg33
		rtd_outl(0xB8028C38, 0x0FD20000);//reg34~reg37
		rtd_outl(0xB8028C3C, 0x7E900000);//reg38~reg3B
		rtd_outl(0xB8028C40, 0x0FD20000);//reg3C~reg3F
		rtd_outl(0xB8028C44, 0x7E900000);//reg40~reg43
		rtd_outl(0xB8028C48, 0x0FD20000);//reg44~reg47
		rtd_outl(0xB8028C4C, 0x00000000);//reg48~reg4B
		rtd_outl(0xB8028C50, 0x2AAB2000);//reg4C~reg4F
		rtd_outl(0xB8028C54, 0x20003FFF);//reg50~reg53
		rtd_outl(0xB8028C58, 0x30000606);//reg54~reg57
		rtd_outl(0xB8028C5C, 0x06061001);//reg58~reg5B
		rtd_outl(0xB8028C60, 0x00019801);//reg5C~reg5F
		rtd_outl(0xB8028C64, 0x98019801);//reg60~reg63
		rtd_outl(0xB8028C68, 0x98080008);//reg64~reg67
		rtd_outl(0xB8028C6C, 0x00080008);//reg68~reg6B
		rtd_outl(0xB8028C70, 0x00060606);//reg6C~reg6F
		rtd_outl(0xB8028C74, 0x06200015);//reg70~reg73
		rtd_outl(0xB8028C78, 0x55100010);//reg74~reg77
		rtd_outl(0xB8028C7C, 0x00200010);//reg78~reg7B
		rtd_outl(0xB8028C80, 0x00100010);//reg7C~reg7F
		rtd_outl(0xB8028C84, 0x00100010);//reg80~reg83
		rtd_outl(0xB8028C88, 0x001000FF);//reg84~reg87
		rtd_outl(0xB8028C8C, 0xFFFFFFFF);//reg88~reg8B
		rtd_outl(0xB8028C90, 0x01000200);//reg8C~reg8F
		rtd_outl(0xB8028C94, 0x03000400);//reg90~reg93
		rtd_outl(0xB8028C98, 0x05000600);//reg94~reg97
		rtd_outl(0xB8028C9C, 0x07000800);//reg98~reg9B
		rtd_outl(0xB8028CA0, 0x09000A00);//reg9C~reg9F
		rtd_outl(0xB8028CA4, 0x0B000C00);//regA0~regA3
		rtd_outl(0xB8028CA8, 0x0D000E00);//regA4~regA7
		rtd_outl(0xB8028CAC, 0x0F003000);//regA8~regAB
		rtd_outl(0xB8028CB0, 0x08802000);//regAC~regAF
		rtd_outl(0xB8028CB4, 0x10000818);//regB0~regB3
		rtd_outl(0xB8028CB8, 0x08006010);//regB4~regB7
		rtd_outl(0xB8028CBC, 0x25600C00);//regB8~regBB
		rtd_outl(0xB8028CC0, 0x1AAC6C05);//regBC~regBF
		rtd_outl(0xB8028CC4, 0x05080808);//regC0~regC3
		rtd_outl(0xB8028CC8, 0x98830E1D);//regC4~regC7
		rtd_outl(0xB8028CCC, 0x28405060);//regC8~regCB
		rtd_outl(0xB8028CD0, 0x708090A0);//regCC~regCF
		rtd_outl(0xB8028CD4, 0xB0C0D0E0);//regD0~regD3
		rtd_outl(0xB8028CD8, 0xF07FBFFF);//regD4~regD7
		rtd_outl(0xB8028CDC, 0xBF7F7F7F);//regD8~regDB
		rtd_outl(0xB8028CE0, 0x7F7F7F7F);//regDC~regDF
		rtd_outl(0xB8028CE4, 0x7F0A06F0);//regE0~regE3
		rtd_outl(0xB8028CE8, 0x0FF00F08);//regE4~regE7
		rtd_outl(0xB8028CEC, 0x00100000);//regE8~regEB
		rtd_outl(0xB8028CF0, 0x00040004);//regEC~regEF
		rtd_outl(0xB8028D1C, 0x0FF01D37);//regF0~regF3
		rtd_outl(0xB8028D20, 0x371D1D37);//regF4~regF7
		rtd_outl(0xB8028D24, 0x371D0000);//regF8~regFB
		rtd_outl(0xB8028D28, 0x00000000);//regFC~regFF
		rtd_outl(0xB8028D2C, 0x0F200105);//reg100~reg103
		rtd_outl(0xB8028D30, 0x00180008);//reg104~reg107
		rtd_outl(0xB8028D34, 0x80000000);//reg108~reg10B
		rtd_outl(0xB8028D38, 0x0400100A);//reg10C~reg10F
		rtd_outl(0xB8028D3C, 0x00000010);//reg110~reg113
		rtd_outl(0xB8028D40, 0x0001FF00);//reg114~reg117
		rtd_outl(0xB8028D44, 0x00040000);//reg118~reg11B
		rtd_outl(0xB8028D48, 0x00000000);//reg11C~reg11F
		rtd_outl(0xB8028D4C, 0x10F50480);//reg120~reg123
		rtd_outl(0xB8028D50, 0x40210000);//reg124~reg127
	}else{
		rtd_outl(0xB8028C04, 0xF8F1F1F9);//reg00~reg03
		rtd_outl(0xB8028C08, 0xDF0D9A10);//reg04~reg07
		rtd_outl(0xB8028C0C, 0x000D9A10);//reg08~reg0B
		rtd_outl(0xB8028C10, 0x0012D310);//reg0C~reg0F
		rtd_outl(0xB8028C14, 0x0012D310);//reg10~reg13
		rtd_outl(0xB8028C18, 0x00040004);//reg14~reg17
		rtd_outl(0xB8028C1C, 0x00040004);//reg18~reg1B
		rtd_outl(0xB8028C20, 0x00040000);//reg1C~reg1F
		rtd_outl(0xB8028C24, 0x0FD20000);//reg20~reg23
		rtd_outl(0xB8028C28, 0x7E900000);//reg24~reg27
		rtd_outl(0xB8028C2C, 0x0FD20000);//reg28~reg2B
		rtd_outl(0xB8028C30, 0x7E900000);//reg2C~reg2F
		rtd_outl(0xB8028C34, 0x0FD20000);//reg30~reg33
		rtd_outl(0xB8028C38, 0x0FD20000);//reg34~reg37
		rtd_outl(0xB8028C3C, 0x7E900000);//reg38~reg3B
		rtd_outl(0xB8028C40, 0x0FD20000);//reg3C~reg3F
		rtd_outl(0xB8028C44, 0x7E900000);//reg40~reg43
		rtd_outl(0xB8028C48, 0x0FD20000);//reg44~reg47
		rtd_outl(0xB8028C4C, 0x00000000);//reg48~reg4B
		rtd_outl(0xB8028C50, 0x2AAB2000);//reg4C~reg4F
		rtd_outl(0xB8028C54, 0x20003FFF);//reg50~reg53
		rtd_outl(0xB8028C58, 0x30000606);//reg54~reg57
		rtd_outl(0xB8028C5C, 0x06061001);//reg58~reg5B
		rtd_outl(0xB8028C60, 0x00019801);//reg5C~reg5F
		rtd_outl(0xB8028C64, 0x98019801);//reg60~reg63
		rtd_outl(0xB8028C68, 0x98080008);//reg64~reg67
		rtd_outl(0xB8028C6C, 0x00080008);//reg68~reg6B
		rtd_outl(0xB8028C70, 0x00060606);//reg6C~reg6F
		rtd_outl(0xB8028C74, 0x06200015);//reg70~reg73
		rtd_outl(0xB8028C78, 0x55100010);//reg74~reg77
		rtd_outl(0xB8028C7C, 0x00200010);//reg78~reg7B
		rtd_outl(0xB8028C80, 0x00100010);//reg7C~reg7F
		rtd_outl(0xB8028C84, 0x00100010);//reg80~reg83
		rtd_outl(0xB8028C88, 0x001000FF);//reg84~reg87
		rtd_outl(0xB8028C8C, 0xFFFFFFFF);//reg88~reg8B
		rtd_outl(0xB8028C90, 0x01000200);//reg8C~reg8F
		rtd_outl(0xB8028C94, 0x03000400);//reg90~reg93
		rtd_outl(0xB8028C98, 0x05000600);//reg94~reg97
		rtd_outl(0xB8028C9C, 0x07000800);//reg98~reg9B
		rtd_outl(0xB8028CA0, 0x09000A00);//reg9C~reg9F
		rtd_outl(0xB8028CA4, 0x0B000C00);//regA0~regA3
		rtd_outl(0xB8028CA8, 0x0D000E00);//regA4~regA7
		rtd_outl(0xB8028CAC, 0x0F003000);//regA8~regAB
		rtd_outl(0xB8028CB0, 0x08802000);//regAC~regAF
		rtd_outl(0xB8028CB4, 0x10000818);//regB0~regB3
		rtd_outl(0xB8028CB8, 0x08006010);//regB4~regB7
		rtd_outl(0xB8028CBC, 0x25600C00);//regB8~regBB
		rtd_outl(0xB8028CC0, 0x1AAC6C05);//regBC~regBF
		rtd_outl(0xB8028CC4, 0x05080808);//regC0~regC3
		rtd_outl(0xB8028CC8, 0x98830E1D);//regC4~regC7
		rtd_outl(0xB8028CCC, 0x28405060);//regC8~regCB
		rtd_outl(0xB8028CD0, 0x708090A0);//regCC~regCF
		rtd_outl(0xB8028CD4, 0xB0C0D0E0);//regD0~regD3
		rtd_outl(0xB8028CD8, 0xF07FBFFF);//regD4~regD7
		rtd_outl(0xB8028CDC, 0xBF7F7F7F);//regD8~regDB
		rtd_outl(0xB8028CE0, 0x7F7F7F7F);//regDC~regDF
		rtd_outl(0xB8028CE4, 0x7F0A06F0);//regE0~regE3
		rtd_outl(0xB8028CE8, 0x0FF00F08);//regE4~regE7
		rtd_outl(0xB8028CEC, 0x00100000);//regE8~regEB
		rtd_outl(0xB8028CF0, 0x00040004);//regEC~regEF
		rtd_outl(0xB8028D1C, 0x0FF01D37);//regF0~regF3
		rtd_outl(0xB8028D20, 0x371D1D37);//regF4~regF7
		rtd_outl(0xB8028D24, 0x371D0000);//regF8~regFB
		rtd_outl(0xB8028D28, 0x00000000);//regFC~regFF
		rtd_outl(0xB8028D2C, 0x0F200105);//reg100~reg103
		rtd_outl(0xB8028D30, 0x00180008);//reg104~reg107
		rtd_outl(0xB8028D34, 0x80000000);//reg108~reg10B
		rtd_outl(0xB8028D38, 0x0400100A);//reg10C~reg10F
		rtd_outl(0xB8028D3C, 0x00000010);//reg110~reg113
		rtd_outl(0xB8028D40, 0x0001FF00);//reg114~reg117
		rtd_outl(0xB8028D44, 0x00040000);//reg118~reg11B
		rtd_outl(0xB8028D48, 0x00000000);//reg11C~reg11F
		rtd_outl(0xB8028D4C, 0x10F50480);//reg120~reg123
		rtd_outl(0xB8028D50, 0x40210000);//reg124~reg127
	}

	lg_m_plus_m_plus_ctl_reg.regValue = IoReg_Read32(LG_M_PLUS_M_plus_ctl_reg);
	lg_m_plus_m_plus_ctl_reg.wpr_on = 1;
	IoReg_Write32(LG_M_PLUS_M_plus_ctl_reg,lg_m_plus_m_plus_ctl_reg.regValue);

	ppoverlay_display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	ppoverlay_display_timing_ctrl2_reg.mplus_rgbw_en = 1; //mplus enable, rgbw disable, BOE-rgbw disable
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg,ppoverlay_display_timing_ctrl2_reg.regValue);
*/
}

extern UINT16 romcode_boe_rgbw_table_vivi_160815[16128];
void vbe_disp_panel_boe_resume_flow(void)
{
#if 0 //fix me later by benwang
	short i, cnt;
	UINT16* ptr_tab;

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"###[%s][Line:%d]###\n", __FUNCTION__, __LINE__);

	ptr_tab = romcode_boe_rgbw_table_vivi_160815;

	// === CRT reset off===
	sys_reg_sys_srst3_RBUS sys_reg_sys_srst3_REG;
	sys_reg_sys_clken3_RBUS sys_reg_sys_clken3_REG;

	// flow:  rst_on -> clk_on
	//sys_reg_sys_srst3_REG.regValue = IoReg_Read32(SYS_REG_SYS_SRST3_reg);
	//sys_reg_sys_clken3_REG.regValue = IoReg_Read32(SYS_REG_SYS_CLKEN3_reg);
	sys_reg_sys_srst3_REG.regValue = 0;
	sys_reg_sys_srst3_REG.rstn_d_boe_rgbw_mcu = 1;
	sys_reg_sys_srst3_REG.rstn_d_boe_rgbw_apb = 1;
	sys_reg_sys_srst3_REG.rstn_d_boe_rgbw_pxl = 1;
	sys_reg_sys_srst3_REG.write_data = 1;
	IoReg_Write32(SYS_REG_SYS_SRST3_reg, sys_reg_sys_srst3_REG.regValue);
	sys_reg_sys_clken3_REG.regValue = 0;
	sys_reg_sys_clken3_REG.clken_d_boe_rgbw_mcu = 1;
	sys_reg_sys_clken3_REG.clken_d_boe_rgbw_apb = 1;
	sys_reg_sys_clken3_REG.clken_d_boe_rgbw_pxl = 1;
	sys_reg_sys_clken3_REG.write_data = 1;
	IoReg_Write32(SYS_REG_SYS_CLKEN3_reg, sys_reg_sys_clken3_REG.regValue);

	// === Enable BOE-RGBW ===
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_REG;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_REG;
	dispd_boe_rgbw_apb_latency_RBUS dispd_boe_rgbw_apb_latency_REG;
	od_dma_oddma_pq_cmp_pair_RBUS od_dma_oddma_pq_cmp_pair_REG;
	dispd_boe_rgbw_mcu_st_RBUS dispd_boe_rgbw_mcu_st_RBEG;
	display_timing_ctrl1_REG.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	display_timing_ctrl2_REG.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);

	// flow: disp_en off -> eco_clk on ->rgbw_en on -> self latency check on -> disp_en on
	display_timing_ctrl1_REG.disp_en = 0;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_REG.regValue);

	od_dma_oddma_pq_cmp_pair_REG.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_PAIR_reg);
	od_dma_oddma_pq_cmp_pair_REG.eco_reg_boe_clk_inv = 1;
	IoReg_Write32(OD_DMA_ODDMA_PQ_CMP_PAIR_reg, od_dma_oddma_pq_cmp_pair_REG.regValue);

	display_timing_ctrl2_REG.mplus_rgbw_en = 4; // use rgbw of 0:disable, 1:M+, 2:RTK, 4: BOE
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_REG.regValue);


	// === MCU <-> SoC ===
	dispd_boe_rgbw_apb_w_control_RBUS dispd_boe_rgbw_apb_w_control_REG;
	dispd_boe_rgbw_apb_w_data_RBUS dispd_boe_rgbw_apb_w_data_REG;

	//wclr APB error
	dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	dispd_boe_rgbw_mcu_st_RBEG.apb_error = 1;
	IoReg_Write32(DISPD_BOE_RGBW_mcu_st_reg, dispd_boe_rgbw_mcu_st_RBEG.regValue);

	//RESET RGBW-IP-MCU
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc000;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	//Access 32K SRAM via APB
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc001;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 0;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	// === write table 0~0x7dff ===
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 1; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0x0000;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	for(i = 0; i < 16128; i++)
	{
		//dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = BOE_RGBW_TAB_0000[i]&0xff;
		//dispd_boe_rgbw_apb_w_data_REG.apb_w_data1 = (BOE_RGBW_TAB_0000[i]>>8)&0xff;
		dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = ptr_tab[i]&0xff;
		dispd_boe_rgbw_apb_w_data_REG.apb_w_data1 = (ptr_tab[i]>>8)&0xff;
		IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	}
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"ptr_tab[%d] = %x\n", i-1, ptr_tab[i-1]);

	// === MCU <-> SoC ===
	//Release RGBW-IP-MCU
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc001;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 7;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);
	// wait V-blank
	// C000 = 1; (Reset MCU)
	dispd_boe_rgbw_apb_w_control_REG.apb_w_mode = 0; //	0:addr +1, 1:addr +2, 2:addr +4
	dispd_boe_rgbw_apb_w_control_REG.apb_w_addr= 0xc000;
	dispd_boe_rgbw_apb_w_data_REG.apb_w_data0 = 1;
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_control_reg, dispd_boe_rgbw_apb_w_control_REG.regValue);
	IoReg_Write32(DISPD_BOE_RGBW_APB_w_data_reg, dispd_boe_rgbw_apb_w_data_REG.regValue);

	//check APB error
	dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	if(dispd_boe_rgbw_mcu_st_RBEG.apb_error ==1 )
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d] APB error\n", __FUNCTION__, __LINE__);
	msleep(20);

	dispd_boe_rgbw_apb_latency_REG.regValue = IoReg_Read32(DISPD_BOE_RGBW_APB_latency_reg);
	dispd_boe_rgbw_apb_latency_REG.self_deno_chk_en = 1;
	dispd_boe_rgbw_apb_latency_REG.self_deno_mode = 1;
	dispd_boe_rgbw_apb_latency_REG.latency_golden= 0x31;
	IoReg_Write32(DISPD_BOE_RGBW_APB_latency_reg, dispd_boe_rgbw_apb_latency_REG.regValue);

	display_timing_ctrl1_REG.disp_en = 1;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_REG.regValue);


	dispd_boe_rgbw_mcu_st_RBEG.regValue = IoReg_Read32(DISPD_BOE_RGBW_mcu_st_reg);
	if(dispd_boe_rgbw_mcu_st_RBEG.self_deno_chk_error==1)
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s][%d] APB error\n", __FUNCTION__, __LINE__);
#endif
}

void vbe_disp_panel_rgbw_resume(void)
{
#if 0 //fix me later by benwang
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"###[%s][Line:%d]###\n", __FUNCTION__, __LINE__);

	down(&VBE_RGBW_Resume_Semaphore);
	if(Get_DISPLAY_PANEL_MPLUS_RGBW() == TRUE){
		vbe_disp_panel_mplus_resume_flow();
	}else if(Get_DISPLAY_PANEL_BOW_RGBW() == TRUE){
		vbe_disp_panel_boe_resume_flow();
	}else{
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"not rgbw tcon \n");
	}
	up(&VBE_RGBW_Resume_Semaphore);
#endif
}
void vbe_disp_panel_save_tcon_reg(void)
{
	
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON_CTRL_S_R = 				  IoReg_Read32(TCON_TCON_CTRL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON_IP_EN_S_R =				  IoReg_Read32(TCON_TCON_IP_EN_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_HSE_S_R = 				  IoReg_Read32(TCON_TCON0_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_VSE_S_R = 				  IoReg_Read32(TCON_TCON0_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_CTRL_S_R =				  IoReg_Read32(TCON_TCON0_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON0_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON0_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON0_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_HSE_S_R = 				  IoReg_Read32(TCON_TCON1_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_VSE_S_R = 				  IoReg_Read32(TCON_TCON1_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_CTRL_S_R =				  IoReg_Read32(TCON_TCON1_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON1_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON1_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON1_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_HSE_S_R = 				  IoReg_Read32(TCON_TCON2_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_VSE_S_R = 				  IoReg_Read32(TCON_TCON2_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_CTRL_S_R =				  IoReg_Read32(TCON_TCON2_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON2_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON2_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON2_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_HSE_S_R = 				  IoReg_Read32(TCON_TCON3_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_VSE_S_R = 				  IoReg_Read32(TCON_TCON3_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_CTRL_S_R =				  IoReg_Read32(TCON_TCON3_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON3_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON3_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON3_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_HSE_S_R = 				  IoReg_Read32(TCON_TCON4_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_VSE_S_R = 				  IoReg_Read32(TCON_TCON4_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_CTRL_S_R =				  IoReg_Read32(TCON_TCON4_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON4_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON4_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON4_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_HSE_S_R = 				  IoReg_Read32(TCON_TCON5_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_VSE_S_R = 				  IoReg_Read32(TCON_TCON5_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_CTRL_S_R =				  IoReg_Read32(TCON_TCON5_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON5_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON5_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON5_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_HSE_S_R = 				  IoReg_Read32(TCON_TCON6_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_VSE_S_R = 				  IoReg_Read32(TCON_TCON6_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_CTRL_S_R =				  IoReg_Read32(TCON_TCON6_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON6_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON6_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON6_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_HSE_S_R = 				  IoReg_Read32(TCON_TCON7_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_VSE_S_R = 				  IoReg_Read32(TCON_TCON7_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_CTRL_S_R =				  IoReg_Read32(TCON_TCON7_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON7_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON7_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON7_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_HSE_S_R = 				  IoReg_Read32(TCON_TCON8_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_VSE_S_R = 				  IoReg_Read32(TCON_TCON8_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_CTRL_S_R =				  IoReg_Read32(TCON_TCON8_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON8_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON8_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON8_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_HSE_S_R = 				  IoReg_Read32(TCON_TCON9_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_VSE_S_R = 				  IoReg_Read32(TCON_TCON9_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_CTRL_S_R =				  IoReg_Read32(TCON_TCON9_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_ACROSS_LINE_CONTROL3_S_R =  IoReg_Read32(TCON_TCON9_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_ACROSS_FRAME_CONTROL_S_R =  IoReg_Read32(TCON_TCON9_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON9_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_HSE_S_R =				  IoReg_Read32(TCON_TCON10_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_VSE_S_R =				  IoReg_Read32(TCON_TCON10_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_CTRL_S_R =				  IoReg_Read32(TCON_TCON10_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON10_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON10_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON10_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_HSE_S_R =				  IoReg_Read32(TCON_TCON11_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_VSE_S_R =				  IoReg_Read32(TCON_TCON11_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_CTRL_S_R =				  IoReg_Read32(TCON_TCON11_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON11_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON11_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON11_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_HSE_S_R =				  IoReg_Read32(TCON_TCON12_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_VSE_S_R =				  IoReg_Read32(TCON_TCON12_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_CTRL_S_R =				  IoReg_Read32(TCON_TCON12_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON12_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON12_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON12_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_HSE_S_R =				  IoReg_Read32(TCON_TCON13_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_VSE_S_R =				  IoReg_Read32(TCON_TCON13_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_CTRL_S_R =				  IoReg_Read32(TCON_TCON13_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON13_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON13_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON13_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_HSE_S_R =				  IoReg_Read32(TCON_TCON14_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_VSE_S_R =				  IoReg_Read32(TCON_TCON14_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_CTRL_S_R =				  IoReg_Read32(TCON_TCON14_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON14_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON14_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON14_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_HSE_S_R =				  IoReg_Read32(TCON_TCON15_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_VSE_S_R =				  IoReg_Read32(TCON_TCON15_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_CTRL_S_R =				  IoReg_Read32(TCON_TCON15_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON15_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON15_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON15_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_HSE_S_R =				  IoReg_Read32(TCON_TCON16_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_VSE_S_R =				  IoReg_Read32(TCON_TCON16_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_CTRL_S_R =				  IoReg_Read32(TCON_TCON16_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON16_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON16_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON16_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_HSE_S_R =				  IoReg_Read32(TCON_TCON17_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_VSE_S_R =				  IoReg_Read32(TCON_TCON17_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_CTRL_S_R =				  IoReg_Read32(TCON_TCON17_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON17_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON17_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON17_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_HSE_S_R =				  IoReg_Read32(TCON_TCON18_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_VSE_S_R =				  IoReg_Read32(TCON_TCON18_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_CTRL_S_R =				  IoReg_Read32(TCON_TCON18_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON18_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON18_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON18_FRAME_HL_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_HSE_S_R =				  IoReg_Read32(TCON_TCON19_HSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_VSE_S_R =				  IoReg_Read32(TCON_TCON19_VSE_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_CTRL_S_R =				  IoReg_Read32(TCON_TCON19_Ctrl_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_ACROSS_LINE_CONTROL3_S_R = IoReg_Read32(TCON_TCON19_ACROSS_LINE_CONTROL3_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_ACROSS_FRAME_CONTROL_S_R = IoReg_Read32(TCON_TCON19_ACROSS_FRAME_CONTROL_reg);
	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_FRAME_HL_CONTROL_S_R =	  IoReg_Read32(TCON_TCON19_FRAME_HL_CONTROL_reg);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] tcon reg save  \n",__FUNCTION__);
}

void vbe_disp_panel_suspend(void)
{
	//panel driver setting
	vbe_disp_suspend_resume.PPOVERLAY_Display_Background_Color_S_R = IoReg_Read32(PPOVERLAY_Display_Background_Color_reg);
	vbe_disp_suspend_resume.PPOVERLAY_Display_Background_Color_2_S_R = IoReg_Read32(PPOVERLAY_Display_Background_Color_2_reg);
	vbe_disp_suspend_resume.PPOVERLAY_Main_Display_Control_RSV_S_R = IoReg_Read32(PPOVERLAY_Main_Display_Control_RSV_reg);
	vbe_disp_suspend_resume.PPOVERLAY_Main_Border_Highlight_Border_Color2_S_R = IoReg_Read32(PPOVERLAY_Main_Border_Highlight_Border_Color2_reg);
	vbe_disp_suspend_resume.PPOVERLAY_Main_Border_Highlight_Border_Color3_S_R = IoReg_Read32(PPOVERLAY_Main_Border_Highlight_Border_Color3_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MAIN_DEN_H_Start_End_S_R  = IoReg_Read32(PPOVERLAY_MAIN_DEN_H_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MAIN_DEN_V_Start_End_S_R = IoReg_Read32(PPOVERLAY_MAIN_DEN_V_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MAIN_Background_H_Start_End_S_R = IoReg_Read32(PPOVERLAY_MAIN_Background_H_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MAIN_Background_V_Start_End_S_R  = IoReg_Read32(PPOVERLAY_MAIN_Background_V_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MAIN_Active_H_Start_End_S_R = IoReg_Read32(PPOVERLAY_MAIN_Active_H_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MAIN_Active_V_Start_End_S_R = IoReg_Read32(PPOVERLAY_MAIN_Active_V_Start_End_reg);

	//sfg
	vbe_disp_suspend_resume.SFG_SFG_ZZ_SHIFT_DBG_CTRL_S_R = 		IoReg_Read32(SFG_SFG_ZZ_shift_dbg_CTRL_reg);
	vbe_disp_suspend_resume.SFG_SFG_SWAP_CTRL0_S_R =				IoReg_Read32(SFG_SFG_SWAP_CTRL0_reg);
	vbe_disp_suspend_resume.SFG_SFG_CRC_CTRL_S_R =					IoReg_Read32(SFG_SFG_CRC_CTRL_reg);
	vbe_disp_suspend_resume.SFG_SFG_CRC_RESULT_S_R =				IoReg_Read32(SFG_SFG_CRC_RESULT_reg);
	vbe_disp_suspend_resume.SFG_SFG_CRC_R_RESULT_S_R =				IoReg_Read32(SFG_SFG_CRC_R_RESULT_reg);
	vbe_disp_suspend_resume.SFG_SFG_L_DES_CRC_S_R = 				IoReg_Read32(SFG_SFG_L_DES_CRC_reg);
	vbe_disp_suspend_resume.SFG_SFG_R_DES_CRC_S_R = 				IoReg_Read32(SFG_SFG_R_DES_CRC_reg);
	vbe_disp_suspend_resume.SFG_SFG_CRC_ERR_CNT_S_R =				IoReg_Read32(SFG_SFG_CRC_ERR_CNT_reg);
	vbe_disp_suspend_resume.SFG_SFG_FORCE_BG_AT_DIF_S_R =			IoReg_Read32(SFG_SFG_FORCE_BG_AT_DIF_reg);
	vbe_disp_suspend_resume.SFG_ZZ_CTRL_S_R =						IoReg_Read32(SFG_ZZ_CTRL_reg);
	vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_0A_S_R = 			IoReg_Read32(SFG_SFG_DUMMY_CTRL_0A_reg);
	vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_0B_S_R = 			IoReg_Read32(SFG_SFG_DUMMY_CTRL_0B_reg);
	vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_1A_S_R = 			IoReg_Read32(SFG_SFG_DUMMY_CTRL_1A_reg);
	vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_1B_S_R = 			IoReg_Read32(SFG_SFG_DUMMY_CTRL_1B_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_0_S_R =					IoReg_Read32(SFG_SFG_CTRL_0_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_1_S_R =					IoReg_Read32(SFG_SFG_CTRL_1_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_2_S_R =					IoReg_Read32(SFG_SFG_CTRL_2_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_3_S_R =					IoReg_Read32(SFG_SFG_CTRL_3_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_4_S_R =					IoReg_Read32(SFG_SFG_CTRL_4_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_6_S_R =					IoReg_Read32(SFG_SFG_CTRL_6_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_7_S_R =					IoReg_Read32(SFG_SFG_CTRL_7_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_8_S_R =					IoReg_Read32(SFG_SFG_CTRL_8_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_9_S_R =					IoReg_Read32(SFG_SFG_CTRL_9_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_5_S_R =					IoReg_Read32(SFG_SFG_CTRL_5_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_A_S_R =					IoReg_Read32(SFG_SFG_CTRL_A_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_B_S_R =					IoReg_Read32(SFG_SFG_CTRL_B_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_C_S_R =					IoReg_Read32(SFG_SFG_CTRL_C_reg);
	vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_1_S_R = 				IoReg_Read32(SFG_SFG_TG_AUTO_1_reg);
	vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_2_S_R = 				IoReg_Read32(SFG_SFG_TG_AUTO_2_reg);
	vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_3_S_R = 				IoReg_Read32(SFG_SFG_TG_AUTO_3_reg);
	vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_4_S_R = 				IoReg_Read32(SFG_SFG_TG_AUTO_4_reg);
	vbe_disp_suspend_resume.SFG_SFG_DUMMY_S_R = 					IoReg_Read32(SFG_SFG_DUMMY_reg);
	vbe_disp_suspend_resume.SFG_SFG_BISR_SECOND_RUN_S_R =			IoReg_Read32(SFG_SFG_BISR_SECOND_RUN_reg);
	vbe_disp_suspend_resume.SFG_SFG_BISR_DONE_S_R = 				IoReg_Read32(SFG_SFG_BISR_DONE_reg);
	vbe_disp_suspend_resume.SFG_SFG_BISR_FAIL_GROUP_S_R =			IoReg_Read32(SFG_SFG_BISR_FAIL_GROUP_reg);
	vbe_disp_suspend_resume.SFG_SFG_BISR_FAIL_S_R = 				IoReg_Read32(SFG_SFG_BISR_FAIL_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRF_MODE_S_R =					IoReg_Read32(SFG_SFG_DRF_MODE_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRF_RESUME_S_R =				IoReg_Read32(SFG_SFG_DRF_RESUME_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRF_DONE_S_R =					IoReg_Read32(SFG_SFG_DRF_DONE_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRF_PAUSE_S_R = 				IoReg_Read32(SFG_SFG_DRF_PAUSE_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRF_FAIL_GROUP_S_R =			IoReg_Read32(SFG_SFG_DRF_FAIL_GROUP_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRF_FAI_S_R =					IoReg_Read32(SFG_SFG_DRF_FAI_reg);
	vbe_disp_suspend_resume.SFG_SFG_BIST_OTHER_S_R =				IoReg_Read32(SFG_SFG_BIST_OTHER_reg);
	vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_0_S_R =				IoReg_Read32(SFG_SFG_MID_DUMMY_0_reg);
	vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_1_S_R =				IoReg_Read32(SFG_SFG_MID_DUMMY_1_reg);
	vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_2_S_R =				IoReg_Read32(SFG_SFG_MID_DUMMY_2_reg);
	vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_3_S_R =				IoReg_Read32(SFG_SFG_MID_DUMMY_3_reg);
	vbe_disp_suspend_resume.SFG_SFG_DATA_AFTER_DEN_S_R =			IoReg_Read32(SFG_SFG_data_after_den_reg);
	vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_0_S_R = 		IoReg_Read32(SFG_SFG_insert_subpixel_0_reg);
	vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_1_S_R = 		IoReg_Read32(SFG_SFG_insert_subpixel_1_reg);
	vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_2_S_R = 		IoReg_Read32(SFG_SFG_insert_subpixel_2_reg);
	vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_3_S_R = 		IoReg_Read32(SFG_SFG_insert_subpixel_3_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_10_S_R =					IoReg_Read32(SFG_SFG_ctrl_10_reg);
	vbe_disp_suspend_resume.SFG_SFG_LAST_EXT_PIXEL_LAST_FLIP_S_R =	IoReg_Read32(SFG_SFG_Last_ext_pixel_last_flip_reg);
	vbe_disp_suspend_resume.SFG_SFG_DEBUG_S_R = 					IoReg_Read32(SFG_SFG_debug_reg);
	vbe_disp_suspend_resume.SFG_SFG_DATA_CAPTURE_VH_S_R =			IoReg_Read32(SFG_SFG_data_capture_vh_reg);
	vbe_disp_suspend_resume.SFG_SFG_DATA_CAPTURE_SRC_S_R =			IoReg_Read32(SFG_SFG_data_capture_src_reg);
	vbe_disp_suspend_resume.SFG_SFG_DATA_CAPTURE_READ_DATA_S_R =	IoReg_Read32(SFG_SFG_data_capture_read_data_reg);
	vbe_disp_suspend_resume.SFG_SFG_LAST_SEG_0_S_R =				IoReg_Read32(SFG_SFG_last_seg_0_reg);
	vbe_disp_suspend_resume.SFG_SFG_LAST_SEG_1_S_R =				IoReg_Read32(SFG_SFG_last_seg_1_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_0_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_0_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_1_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_1_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_2_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_2_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_6_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_6_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_7_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_7_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_8_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_8_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_12_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_12_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_13_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_13_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_14_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_14_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_18_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_18_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_19_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_19_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_20_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_20_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_3_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_3_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_4_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_4_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_5_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_5_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_9_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_9_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_10_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_10_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_11_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_11_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_15_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_15_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_16_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_16_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_17_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_17_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_21_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_21_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_22_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_22_reg);
	vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_23_S_R =				IoReg_Read32(SFG_SFG_DRD_CTRL_23_reg);
	vbe_disp_suspend_resume.SFG_SFG_SWAP_CTRL1_S_R =				IoReg_Read32(SFG_SFG_SWAP_CTRL1_reg);
	vbe_disp_suspend_resume.SFG_SFG_SWAP_CTRL2_S_R =				IoReg_Read32(SFG_SFG_SWAP_CTRL2_reg);
	vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_0_S_R =			IoReg_Read32(SFG_SFG1_DUM_DATA_LINE_0_reg);
	vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_1_S_R =			IoReg_Read32(SFG_SFG1_DUM_DATA_LINE_1_reg);
	vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_2_S_R =			IoReg_Read32(SFG_SFG1_DUM_DATA_LINE_2_reg);
	vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_3_S_R =			IoReg_Read32(SFG_SFG1_DUM_DATA_LINE_3_reg);

	//interface common
	vbe_disp_suspend_resume.PIF_LVDS_CTRL3_S_R = IoReg_Read32(PIF_LVDS_CTRL3_reg);
	vbe_disp_suspend_resume.PIF_LVDS_CTRL0_S_R = IoReg_Read32(PIF_LVDS_CTRL0_reg);
	vbe_disp_suspend_resume.PIF_LVDS_PAIR_SELECT_CTRL_0_REG_S_R = IoReg_Read32(PIF_LVDS_pair_select_ctrl_0_reg);
	vbe_disp_suspend_resume.PIF_LVDS_PAIR_SELECT_CTRL_1_REG_S_R = IoReg_Read32(PIF_LVDS_pair_select_ctrl_1_reg);
	vbe_disp_suspend_resume.PIF_LVDS_PAIR_SELECT_CTRL_2_REG_S_R = IoReg_Read32(PIF_LVDS_pair_select_ctrl_2_reg);
	vbe_disp_suspend_resume.PIF_MLVDS_CTRL0_S_R				  = IoReg_Read32(PIF_MLVDS_CTRL0_reg);
	vbe_disp_suspend_resume.PIF_MLVDS_RESET_PUL_CTRL_S_R		  = IoReg_Read32(PIF_MLVDS_Reset_Pul_CTRL_reg);
	vbe_disp_suspend_resume.PIF_MLVDS_CTRL1_S_R				  = IoReg_Read32(PIF_MLVDS_CTRL1_reg);
	vbe_disp_suspend_resume.PIF_MLVDS_CTRL2_S_R				  = IoReg_Read32(PIF_MLVDS_CTRL2_reg);
	vbe_disp_suspend_resume.PIF_MLVDS_CTRL3_S_R				  = IoReg_Read32(PIF_MLVDS_CTRL3_reg);
	vbe_disp_suspend_resume.PIF_MLVDS_CTRL4_S_R				  = IoReg_Read32(PIF_MLVDS_CTRL4_reg);
	vbe_disp_suspend_resume.PIF_MLVDS_MULTI_RESET_PULSE_CTRL_S_R = IoReg_Read32(PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg);

	//local dimming
	vbe_disp_suspend_resume.LDSPI_LD_SPI_H_TOTAL_S_R = IoReg_Read32(LDSPI_ld_spi_h_total_reg);
	vbe_disp_suspend_resume.LDSPI_LD_SPI_V_TOTAL_S_R = IoReg_Read32(LDSPI_ld_spi_v_total_reg);
	vbe_disp_suspend_resume.LDSPI_LD_SPI_REPRODUCE_S_R = IoReg_Read32(LDSPI_ld_spi_reproduce_mode_reg);

	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_0_S_R                    = IoReg_Read32(PINMUX_LVDSPHY_LVDS_0_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_1_S_R                    = IoReg_Read32(PINMUX_LVDSPHY_LVDS_1_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_2_S_R                    = IoReg_Read32(PINMUX_LVDSPHY_LVDS_2_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_3_S_R                    = IoReg_Read32(PINMUX_LVDSPHY_LVDS_3_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_4_S_R                    = IoReg_Read32(PINMUX_LVDSPHY_LVDS_4_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_5_S_R                    = IoReg_Read32(PINMUX_LVDSPHY_LVDS_5_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_PIN_MUX_LVDS_S_R              = IoReg_Read32(PINMUX_LVDSPHY_Pin_Mux_LVDS_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_S_R  = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg);
	vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_S_R = IoReg_Read32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg);
	
	if(Get_DISPLAY_PANEL_TYPE() == P_MINI_LVDS)
	{
		vbe_disp_panel_save_tcon_reg();
	}
}

void vbe_disp_panel_writebcak_tcon_reg(void)
{
	IoReg_Write32(TCON_TCON_CTRL_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON_CTRL_S_R);
	IoReg_Write32(TCON_TCON_IP_EN_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON_IP_EN_S_R);
	IoReg_Write32(TCON_TCON0_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_HSE_S_R);
	IoReg_Write32(TCON_TCON0_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_VSE_S_R);
	IoReg_Write32(TCON_TCON0_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_CTRL_S_R);
	IoReg_Write32(TCON_TCON0_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON0_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON0_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON0_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON1_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_HSE_S_R);
	IoReg_Write32(TCON_TCON1_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_VSE_S_R);
	IoReg_Write32(TCON_TCON1_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_CTRL_S_R);
	IoReg_Write32(TCON_TCON1_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON1_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON1_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON1_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON2_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_HSE_S_R);
	IoReg_Write32(TCON_TCON2_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_VSE_S_R);
	IoReg_Write32(TCON_TCON2_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_CTRL_S_R);
	IoReg_Write32(TCON_TCON2_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON2_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON2_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON2_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON3_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_HSE_S_R);
	IoReg_Write32(TCON_TCON3_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_VSE_S_R);
	IoReg_Write32(TCON_TCON3_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_CTRL_S_R);
	IoReg_Write32(TCON_TCON3_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON3_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON3_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON3_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON4_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_HSE_S_R);
	IoReg_Write32(TCON_TCON4_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_VSE_S_R);
	IoReg_Write32(TCON_TCON4_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_CTRL_S_R);
	IoReg_Write32(TCON_TCON4_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON4_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON4_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON4_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON5_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_HSE_S_R);
	IoReg_Write32(TCON_TCON5_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_VSE_S_R);
	IoReg_Write32(TCON_TCON5_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_CTRL_S_R);
	IoReg_Write32(TCON_TCON5_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON5_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON5_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON5_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON6_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_HSE_S_R);
	IoReg_Write32(TCON_TCON6_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_VSE_S_R);
	IoReg_Write32(TCON_TCON6_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_CTRL_S_R);
	IoReg_Write32(TCON_TCON6_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON6_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON6_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON6_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON7_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_HSE_S_R);
	IoReg_Write32(TCON_TCON7_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_VSE_S_R);
	IoReg_Write32(TCON_TCON7_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_CTRL_S_R);
	IoReg_Write32(TCON_TCON7_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON7_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON7_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON7_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON8_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_HSE_S_R);
	IoReg_Write32(TCON_TCON8_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_VSE_S_R);
	IoReg_Write32(TCON_TCON8_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_CTRL_S_R);
	IoReg_Write32(TCON_TCON8_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON8_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON8_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON8_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON9_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_HSE_S_R);
	IoReg_Write32(TCON_TCON9_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_VSE_S_R);
	IoReg_Write32(TCON_TCON9_Ctrl_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_CTRL_S_R);
	IoReg_Write32(TCON_TCON9_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON9_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON9_FRAME_HL_CONTROL_reg,		vbe_disp_panel_tcon_suspend_resume.TCON_TCON9_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON10_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_HSE_S_R);
	IoReg_Write32(TCON_TCON10_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_VSE_S_R);
	IoReg_Write32(TCON_TCON10_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_CTRL_S_R);
	IoReg_Write32(TCON_TCON10_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON10_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON10_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON10_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON11_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_HSE_S_R);
	IoReg_Write32(TCON_TCON11_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_VSE_S_R);
	IoReg_Write32(TCON_TCON11_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_CTRL_S_R);
	IoReg_Write32(TCON_TCON11_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON11_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON11_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON11_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON12_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_HSE_S_R);
	IoReg_Write32(TCON_TCON12_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_VSE_S_R);
	IoReg_Write32(TCON_TCON12_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_CTRL_S_R);
	IoReg_Write32(TCON_TCON12_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON12_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON12_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON12_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON13_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_HSE_S_R);
	IoReg_Write32(TCON_TCON13_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_VSE_S_R);
	IoReg_Write32(TCON_TCON13_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_CTRL_S_R);
	IoReg_Write32(TCON_TCON13_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON13_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON13_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON13_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON14_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_HSE_S_R);
	IoReg_Write32(TCON_TCON14_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_VSE_S_R);
	IoReg_Write32(TCON_TCON14_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_CTRL_S_R);
	IoReg_Write32(TCON_TCON14_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON14_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON14_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON14_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON15_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_HSE_S_R);
	IoReg_Write32(TCON_TCON15_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_VSE_S_R);
	IoReg_Write32(TCON_TCON15_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_CTRL_S_R);
	IoReg_Write32(TCON_TCON15_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON15_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON15_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON15_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON16_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_HSE_S_R);
	IoReg_Write32(TCON_TCON16_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_VSE_S_R);
	IoReg_Write32(TCON_TCON16_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_CTRL_S_R);
	IoReg_Write32(TCON_TCON16_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON16_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON16_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON16_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON17_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_HSE_S_R);
	IoReg_Write32(TCON_TCON17_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_VSE_S_R);
	IoReg_Write32(TCON_TCON17_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_CTRL_S_R);
	IoReg_Write32(TCON_TCON17_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON17_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON17_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON17_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON18_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_HSE_S_R);
	IoReg_Write32(TCON_TCON18_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_VSE_S_R);
	IoReg_Write32(TCON_TCON18_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_CTRL_S_R);
	IoReg_Write32(TCON_TCON18_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON18_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON18_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON18_FRAME_HL_CONTROL_S_R);
	IoReg_Write32(TCON_TCON19_HSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_HSE_S_R);
	IoReg_Write32(TCON_TCON19_VSE_reg,			vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_VSE_S_R);
	IoReg_Write32(TCON_TCON19_Ctrl_reg, 			vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_CTRL_S_R);
	IoReg_Write32(TCON_TCON19_ACROSS_LINE_CONTROL3_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_ACROSS_LINE_CONTROL3_S_R);
	IoReg_Write32(TCON_TCON19_ACROSS_FRAME_CONTROL_reg,	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_ACROSS_FRAME_CONTROL_S_R);
	IoReg_Write32(TCON_TCON19_FRAME_HL_CONTROL_reg, 	vbe_disp_panel_tcon_suspend_resume.TCON_TCON19_FRAME_HL_CONTROL_S_R);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] tcon reg writeback\n",__FUNCTION__);
}


void vbe_disp_panel_resume(void)
{
	//panel driver setting
	IoReg_Write32(PPOVERLAY_Display_Background_Color_reg,vbe_disp_suspend_resume.PPOVERLAY_Display_Background_Color_S_R );
	IoReg_Write32(PPOVERLAY_Display_Background_Color_2_reg, vbe_disp_suspend_resume.PPOVERLAY_Display_Background_Color_2_S_R);
	IoReg_Write32(PPOVERLAY_Main_Display_Control_RSV_reg, vbe_disp_suspend_resume.PPOVERLAY_Main_Display_Control_RSV_S_R);
	IoReg_Write32(PPOVERLAY_Main_Border_Highlight_Border_Color2_reg, vbe_disp_suspend_resume.PPOVERLAY_Main_Border_Highlight_Border_Color2_S_R);
	IoReg_Write32(PPOVERLAY_Main_Border_Highlight_Border_Color3_reg, vbe_disp_suspend_resume.PPOVERLAY_Main_Border_Highlight_Border_Color3_S_R);
	IoReg_Write32(PPOVERLAY_MAIN_DEN_H_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_MAIN_DEN_H_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_MAIN_DEN_V_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_MAIN_DEN_V_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_MAIN_Background_H_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_MAIN_Background_H_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_MAIN_Background_V_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_MAIN_Background_V_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_MAIN_Active_H_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_MAIN_Active_H_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_MAIN_Active_V_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_MAIN_Active_V_Start_End_S_R);


	//sfg
    IoReg_Write32(SFG_SFG_ZZ_shift_dbg_CTRL_reg,            vbe_disp_suspend_resume.SFG_SFG_ZZ_SHIFT_DBG_CTRL_S_R);
	IoReg_Write32(SFG_SFG_SWAP_CTRL0_reg,                   vbe_disp_suspend_resume.SFG_SFG_SWAP_CTRL0_S_R);
	IoReg_Write32(SFG_SFG_CRC_CTRL_reg,                     vbe_disp_suspend_resume.SFG_SFG_CRC_CTRL_S_R);
	IoReg_Write32(SFG_SFG_CRC_RESULT_reg,                   vbe_disp_suspend_resume.SFG_SFG_CRC_RESULT_S_R);
	IoReg_Write32(SFG_SFG_CRC_R_RESULT_reg,                 vbe_disp_suspend_resume.SFG_SFG_CRC_R_RESULT_S_R);
	IoReg_Write32(SFG_SFG_L_DES_CRC_reg,                    vbe_disp_suspend_resume.SFG_SFG_L_DES_CRC_S_R);
	IoReg_Write32(SFG_SFG_R_DES_CRC_reg,                    vbe_disp_suspend_resume.SFG_SFG_R_DES_CRC_S_R);
	IoReg_Write32(SFG_SFG_CRC_ERR_CNT_reg,                  vbe_disp_suspend_resume.SFG_SFG_CRC_ERR_CNT_S_R);
	//IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg,              vbe_disp_suspend_resume.SFG_SFG_FORCE_BG_AT_DIF_S_R);
	IoReg_Write32(SFG_ZZ_CTRL_reg,                          vbe_disp_suspend_resume.SFG_ZZ_CTRL_S_R);
	IoReg_Write32(SFG_SFG_DUMMY_CTRL_0A_reg,                vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_0A_S_R);
	IoReg_Write32(SFG_SFG_DUMMY_CTRL_0B_reg,                vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_0B_S_R);
	IoReg_Write32(SFG_SFG_DUMMY_CTRL_1A_reg,                vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_1A_S_R);
	IoReg_Write32(SFG_SFG_DUMMY_CTRL_1B_reg,                vbe_disp_suspend_resume.SFG_SFG_DUMMY_CTRL_1B_S_R);
	IoReg_Write32(SFG_SFG_CTRL_0_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_0_S_R);
	IoReg_Write32(SFG_SFG_CTRL_1_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_1_S_R);
	IoReg_Write32(SFG_SFG_CTRL_2_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_2_S_R);
	IoReg_Write32(SFG_SFG_CTRL_3_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_3_S_R);
	IoReg_Write32(SFG_SFG_CTRL_4_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_4_S_R);
	IoReg_Write32(SFG_SFG_CTRL_6_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_6_S_R);
	IoReg_Write32(SFG_SFG_CTRL_7_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_7_S_R);
	IoReg_Write32(SFG_SFG_CTRL_8_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_8_S_R);
	IoReg_Write32(SFG_SFG_CTRL_9_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_9_S_R);
	IoReg_Write32(SFG_SFG_CTRL_5_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_5_S_R);
	IoReg_Write32(SFG_SFG_CTRL_A_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_A_S_R);
	IoReg_Write32(SFG_SFG_CTRL_B_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_B_S_R);
	IoReg_Write32(SFG_SFG_CTRL_C_reg,                       vbe_disp_suspend_resume.SFG_SFG_CTRL_C_S_R);
	IoReg_Write32(SFG_SFG_TG_AUTO_1_reg,                    vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_1_S_R);
	IoReg_Write32(SFG_SFG_TG_AUTO_2_reg,                    vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_2_S_R);
	IoReg_Write32(SFG_SFG_TG_AUTO_3_reg,                    vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_3_S_R);
	IoReg_Write32(SFG_SFG_TG_AUTO_4_reg,                    vbe_disp_suspend_resume.SFG_SFG_TG_AUTO_4_S_R);
	if(Get_DISPLAY_PANEL_TYPE()==P_EPI_TYPE){
		// EPI initial sequence.
	}else{
		IoReg_Write32(SFG_SFG_DUMMY_reg,                    vbe_disp_suspend_resume.SFG_SFG_DUMMY_S_R);
	}
	IoReg_Write32(SFG_SFG_BISR_SECOND_RUN_reg,              vbe_disp_suspend_resume.SFG_SFG_BISR_SECOND_RUN_S_R);
	IoReg_Write32(SFG_SFG_BISR_DONE_reg,                    vbe_disp_suspend_resume.SFG_SFG_BISR_DONE_S_R);
	IoReg_Write32(SFG_SFG_BISR_FAIL_GROUP_reg,              vbe_disp_suspend_resume.SFG_SFG_BISR_FAIL_GROUP_S_R);
	IoReg_Write32(SFG_SFG_BISR_FAIL_reg,                    vbe_disp_suspend_resume.SFG_SFG_BISR_FAIL_S_R);
	IoReg_Write32(SFG_SFG_DRF_MODE_reg,                     vbe_disp_suspend_resume.SFG_SFG_DRF_MODE_S_R);
	IoReg_Write32(SFG_SFG_DRF_RESUME_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRF_RESUME_S_R);
	IoReg_Write32(SFG_SFG_DRF_DONE_reg,                     vbe_disp_suspend_resume.SFG_SFG_DRF_DONE_S_R);
	IoReg_Write32(SFG_SFG_DRF_PAUSE_reg,                    vbe_disp_suspend_resume.SFG_SFG_DRF_PAUSE_S_R);
	IoReg_Write32(SFG_SFG_DRF_FAIL_GROUP_reg,               vbe_disp_suspend_resume.SFG_SFG_DRF_FAIL_GROUP_S_R);
	IoReg_Write32(SFG_SFG_DRF_FAI_reg,                      vbe_disp_suspend_resume.SFG_SFG_DRF_FAI_S_R);
	IoReg_Write32(SFG_SFG_BIST_OTHER_reg,                   vbe_disp_suspend_resume.SFG_SFG_BIST_OTHER_S_R);
	IoReg_Write32(SFG_SFG_MID_DUMMY_0_reg,                  vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_0_S_R);
	IoReg_Write32(SFG_SFG_MID_DUMMY_1_reg,                  vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_1_S_R);
	IoReg_Write32(SFG_SFG_MID_DUMMY_2_reg,                  vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_2_S_R);
	IoReg_Write32(SFG_SFG_MID_DUMMY_3_reg,                  vbe_disp_suspend_resume.SFG_SFG_MID_DUMMY_3_S_R);
	IoReg_Write32(SFG_SFG_data_after_den_reg,               vbe_disp_suspend_resume.SFG_SFG_DATA_AFTER_DEN_S_R);
	IoReg_Write32(SFG_SFG_insert_subpixel_0_reg,            vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_0_S_R);
	IoReg_Write32(SFG_SFG_insert_subpixel_1_reg,            vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_1_S_R);
	IoReg_Write32(SFG_SFG_insert_subpixel_2_reg,            vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_2_S_R);
	IoReg_Write32(SFG_SFG_insert_subpixel_3_reg,            vbe_disp_suspend_resume.SFG_SFG_INSERT_SUBPIXEL_3_S_R);
	IoReg_Write32(SFG_SFG_ctrl_10_reg,                      vbe_disp_suspend_resume.SFG_SFG_CTRL_10_S_R);
	IoReg_Write32(SFG_SFG_Last_ext_pixel_last_flip_reg,     vbe_disp_suspend_resume.SFG_SFG_LAST_EXT_PIXEL_LAST_FLIP_S_R);
	IoReg_Write32(SFG_SFG_debug_reg,                        vbe_disp_suspend_resume.SFG_SFG_DEBUG_S_R);
	IoReg_Write32(SFG_SFG_data_capture_vh_reg,              vbe_disp_suspend_resume.SFG_SFG_DATA_CAPTURE_VH_S_R);
	IoReg_Write32(SFG_SFG_data_capture_src_reg,             vbe_disp_suspend_resume.SFG_SFG_DATA_CAPTURE_SRC_S_R);
	IoReg_Write32(SFG_SFG_data_capture_read_data_reg,       vbe_disp_suspend_resume.SFG_SFG_DATA_CAPTURE_READ_DATA_S_R);
	IoReg_Write32(SFG_SFG_last_seg_0_reg,                   vbe_disp_suspend_resume.SFG_SFG_LAST_SEG_0_S_R);
	IoReg_Write32(SFG_SFG_last_seg_1_reg,                   vbe_disp_suspend_resume.SFG_SFG_LAST_SEG_1_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_0_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_0_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_1_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_1_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_2_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_2_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_6_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_6_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_7_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_7_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_8_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_8_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_12_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_12_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_13_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_13_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_14_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_14_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_18_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_18_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_19_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_19_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_20_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_20_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_3_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_3_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_4_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_4_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_5_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_5_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_9_reg,                   vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_9_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_10_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_10_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_11_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_11_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_15_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_15_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_16_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_16_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_17_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_17_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_21_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_21_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_22_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_22_S_R);
	IoReg_Write32(SFG_SFG_DRD_CTRL_23_reg,                  vbe_disp_suspend_resume.SFG_SFG_DRD_CTRL_23_S_R);
	IoReg_Write32(SFG_SFG_SWAP_CTRL1_reg,                   vbe_disp_suspend_resume.SFG_SFG_SWAP_CTRL1_S_R);
	IoReg_Write32(SFG_SFG_SWAP_CTRL2_reg,                   vbe_disp_suspend_resume.SFG_SFG_SWAP_CTRL2_S_R);
	IoReg_Write32(SFG_SFG1_DUM_DATA_LINE_0_reg,             vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_0_S_R);
	IoReg_Write32(SFG_SFG1_DUM_DATA_LINE_1_reg,             vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_1_S_R);
	IoReg_Write32(SFG_SFG1_DUM_DATA_LINE_2_reg,             vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_2_S_R);
	IoReg_Write32(SFG_SFG1_DUM_DATA_LINE_3_reg,             vbe_disp_suspend_resume.SFG_SFG1_DUM_DATA_LINE_3_S_R);

	//interface common
	IoReg_Write32(PIF_LVDS_CTRL3_reg, vbe_disp_suspend_resume.PIF_LVDS_CTRL3_S_R);
	IoReg_Write32(PIF_LVDS_CTRL0_reg, vbe_disp_suspend_resume.PIF_LVDS_CTRL0_S_R);
	IoReg_Write32(PIF_LVDS_pair_select_ctrl_0_reg, vbe_disp_suspend_resume.PIF_LVDS_PAIR_SELECT_CTRL_0_REG_S_R);
	IoReg_Write32(PIF_LVDS_pair_select_ctrl_1_reg, vbe_disp_suspend_resume.PIF_LVDS_PAIR_SELECT_CTRL_1_REG_S_R);
	IoReg_Write32(PIF_LVDS_pair_select_ctrl_2_reg, vbe_disp_suspend_resume.PIF_LVDS_PAIR_SELECT_CTRL_2_REG_S_R);
	IoReg_Write32(PIF_MLVDS_CTRL0_reg				   , vbe_disp_suspend_resume.PIF_MLVDS_CTRL0_S_R);
	IoReg_Write32(PIF_MLVDS_Reset_Pul_CTRL_reg 	   , vbe_disp_suspend_resume.PIF_MLVDS_RESET_PUL_CTRL_S_R);
	IoReg_Write32(PIF_MLVDS_CTRL1_reg				   , vbe_disp_suspend_resume.PIF_MLVDS_CTRL1_S_R);
	IoReg_Write32(PIF_MLVDS_CTRL2_reg				   , vbe_disp_suspend_resume.PIF_MLVDS_CTRL2_S_R);
	IoReg_Write32(PIF_MLVDS_CTRL3_reg				   , vbe_disp_suspend_resume.PIF_MLVDS_CTRL3_S_R);
	IoReg_Write32(PIF_MLVDS_CTRL4_reg				   , vbe_disp_suspend_resume.PIF_MLVDS_CTRL4_S_R);
	IoReg_Write32(PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg, vbe_disp_suspend_resume.PIF_MLVDS_MULTI_RESET_PULSE_CTRL_S_R);

	//local dimming
	IoReg_Write32(LDSPI_ld_spi_h_total_reg, vbe_disp_suspend_resume.LDSPI_LD_SPI_H_TOTAL_S_R);
	IoReg_Write32(LDSPI_ld_spi_v_total_reg, vbe_disp_suspend_resume.LDSPI_LD_SPI_V_TOTAL_S_R);
	IoReg_Write32(LDSPI_ld_spi_reproduce_mode_reg, vbe_disp_suspend_resume.LDSPI_LD_SPI_REPRODUCE_S_R);

	IoReg_Write32(PINMUX_LVDSPHY_LVDS_0_reg                   , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_0_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDS_1_reg                   , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_1_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDS_2_reg                   , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_2_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDS_3_reg                   , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_3_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDS_4_reg                   , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_4_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDS_5_reg                   , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDS_5_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_Pin_Mux_LVDS_reg             , vbe_disp_suspend_resume.PINMUX_LVDSPHY_PIN_MUX_LVDS_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_4_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_5_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_6_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_7_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_8_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_9_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_11_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_12_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_13_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_14_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_15_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_16_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_4_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_5_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_6_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_7_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_8_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_9_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_11_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_12_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_13_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_14_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_15_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_16_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_10_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_17_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_10_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_17_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_18_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_0_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_2_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_1_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_3_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_18_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_19_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_21_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_19_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_21_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_2_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_0_27_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_3_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_3_2_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_4_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_reg , vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_2_5_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_22_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_23_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_24_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_25_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_26_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_27_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_28_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_29_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_30_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_31_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_32_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_33_S_R);
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_LVDSEPIVBY1_PHY_CTRL_1_34_S_R);

	if(Get_DISPLAY_PANEL_TYPE() == P_MINI_LVDS)
	{
		vbe_disp_panel_writebcak_tcon_reg();
	}	
}

void vbe_disp_first_resume(void)
{
	//frank@1114 add below flow to set up Ddomain related register
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	sys_dispclksel_reg.clken_disp_sfg = 1;
	sys_dispclksel_reg.clken_disp_stage1 = 1;
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);

	IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1);//Let main default value enable force bg
	IoReg_SetBits(PPOVERLAY_MP_Layout_Force_to_Background_reg, _BIT1);//Let sub default value enable force bg

	if(IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg) & _BIT24) {
		return;
	}

	//IoReg_Write32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg, 0x80000000);

	/*DTG*/
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, (vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL1_S_R&(~_BIT24)));
	if(Get_DISPLAY_REFRESH_RATE()==120){
		vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL2_S_R = vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL2_S_R|_BIT29;
	}
	IoReg_Write32(0xb801a610, vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL2_S_R); // dummy register for debug
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL2_S_R);
	IoReg_Write32(PPOVERLAY_DV_Length_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_LENGTH_S_R);
	IoReg_Write32(PPOVERLAY_DV_total_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_TOTAL_S_R);
	IoReg_Write32(PPOVERLAY_DTG_pending_status_reg, vbe_disp_suspend_resume.PPOVERLAY_DTG_PENDING_STATUS_S_R);
	IoReg_Write32(PPOVERLAY_Display_Background_Color_reg, vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_BACKGROUND_COLOR_S_R);
	IoReg_Write32(PPOVERLAY_DH_Width_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_WIDTH_S_R);
	IoReg_Write32(PPOVERLAY_DTG_ie_reg, vbe_disp_suspend_resume.PPOVERLAY_DTG_IE_S_R);
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_S_R);
	IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_DEN_START_END_S_R);
	IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_DEN_START_END_S_R);
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, vbe_disp_suspend_resume.SYS_DISPCLKSEL_S_R);
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING2_S_R);
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING5_S_R);
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING1_S_R);
	IoReg_Write32(PPOVERLAY_uzudtg_DV_TOTAL_reg , vbe_disp_suspend_resume.PPOVERLAY_uzudtg_DV_TOTAL_S_R  );
	IoReg_Write32(PPOVERLAY_uzudtg_DH_TOTAL_reg , vbe_disp_suspend_resume.PPOVERLAY_uzudtg_DH_TOTAL_S_R  );
	IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_DEN_Start_End_S_R );
	IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_DEN_Start_End_S_R );
	IoReg_Write32(PPOVERLAY_UZUDTG_COUNTROL_reg , vbe_disp_suspend_resume.PPOVERLAY_UZUDTG_COUNTROL_S_R  );
	IoReg_Write32(PPOVERLAY_memcdtg_DV_TOTAL_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DV_TOTAL_S_R );
	IoReg_Write32(PPOVERLAY_memcdtg_DH_TOTAL_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DH_TOTAL_S_R );
	IoReg_Write32(PPOVERLAY_memcdtg_DH_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DH_DEN_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DV_DEN_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_MEMCDTG_CONTROL_reg, vbe_disp_suspend_resume.PPOVERLAY_MEMCDTG_CONTROL_S_R  );
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg  , vbe_disp_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_S_R|_BIT12);
	IoReg_Write32(PPOVERLAY_uzudtg_fractional_fsync_reg,vbe_disp_suspend_resume.PPOVERLAY_UZUDTG_FRACTIONAL_FSYNC_S_R);
}

/*VBE disp suspend & resume*/
void vbe_disp_suspend(void)
{
#if !defined(CONFIG_CUSTOMER_TV006) && defined(CONFIG_RTK_KDRV_GDMA)
	gdma_suspend_by_vbe();
#endif
	/*DTG*/
	vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL1_S_R = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL2_S_R = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DV_LENGTH_S_R = IoReg_Read32(PPOVERLAY_DV_Length_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DV_TOTAL_S_R = IoReg_Read32(PPOVERLAY_DV_total_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DTG_PENDING_STATUS_S_R = IoReg_Read32(PPOVERLAY_DTG_pending_status_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_BACKGROUND_COLOR_S_R = IoReg_Read32(PPOVERLAY_Display_Background_Color_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DH_WIDTH_S_R = IoReg_Read32(PPOVERLAY_DH_Width_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DTG_IE_S_R = IoReg_Read32(PPOVERLAY_DTG_ie_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_S_R = IoReg_Read32(PPOVERLAY_DH_Total_Last_Line_Length_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DH_DEN_START_END_S_R = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DV_DEN_START_END_S_R = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
	vbe_disp_suspend_resume.SYS_DISPCLKSEL_S_R = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING2_S_R = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
	vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING5_S_R = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
	vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING1_S_R = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DOUBLE_BUFFER_CTRL_S_R = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_uzudtg_DV_TOTAL_S_R  = IoReg_Read32(PPOVERLAY_uzudtg_DV_TOTAL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_uzudtg_DH_TOTAL_S_R  = IoReg_Read32(PPOVERLAY_uzudtg_DH_TOTAL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DH_DEN_Start_End_S_R = IoReg_Read32(PPOVERLAY_DH_DEN_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_DV_DEN_Start_End_S_R = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_UZUDTG_COUNTROL_S_R  = IoReg_Read32(PPOVERLAY_UZUDTG_COUNTROL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DV_TOTAL_S_R = IoReg_Read32(PPOVERLAY_memcdtg_DV_TOTAL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DH_TOTAL_S_R = IoReg_Read32(PPOVERLAY_memcdtg_DH_TOTAL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DH_DEN_Start_End_S_R = IoReg_Read32(PPOVERLAY_memcdtg_DH_DEN_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DV_DEN_Start_End_S_R = IoReg_Read32(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MEMCDTG_CONTROL_S_R  = IoReg_Read32(PPOVERLAY_MEMCDTG_CONTROL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_S_R    = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
	vbe_disp_suspend_resume.PPOVERLAY_UZUDTG_FRACTIONAL_FSYNC_S_R = IoReg_Read32(PPOVERLAY_uzudtg_fractional_fsync_reg);
	 /*SFG*/
	vbe_disp_suspend_resume.SFG_SFG_FORCE_BG_AT_DIF_S_R = IoReg_Read32(SFG_SFG_FORCE_BG_AT_DIF_reg);
	vbe_disp_suspend_resume.SFG_SFG_CTRL_0_S_R = IoReg_Read32(SFG_SFG_CTRL_0_reg);
 	 /*Clk*/
  	vbe_disp_suspend_resume.CRT_PLL_SSC0_S_R = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
  	vbe_disp_suspend_resume.CRT_PLL_SSC3_S_R = IoReg_Read32(PLL27X_REG_PLL_SSC3_reg);
	vbe_disp_suspend_resume.CRT_PLL_SSC4_S_R = IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
	vbe_disp_suspend_resume.CRT_SYS_DCLKSS_S_R = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	vbe_disp_suspend_resume.CRT_SYS_PLL_DISP1_S_R = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	vbe_disp_suspend_resume.CRT_SYS_PLL_DISP2_S_R = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_reg);
	vbe_disp_suspend_resume.CRT_SYS_PLL_DISP3_S_R = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
	vbe_disp_suspend_resume.CRT_SYS_DISPCLKSEL_S_R = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	Panel_TurnOff();
	msleep(100);//TCL2841-379
	vbe_disp_panel_suspend();
}
void vbe_disp_resume(void)
{
	unsigned int tmp;
//	unsigned char timeout;
	pll27x_reg_pll_ssc5_RBUS pll_ssc5_reg;
	UINT32 cnt=0;


	//frank@1114 add below flow to set up Ddomain related register
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	sys_dispclksel_reg.clken_disp_sfg = 1;
	sys_dispclksel_reg.clken_disp_stage1 = 1;
	sys_dispclksel_reg.clken_disp_memc_out = 1;
	sys_dispclksel_reg.clken_disp_memc_in = 1;
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);

	IoReg_SetBits(PPOVERLAY_Main_Display_Control_RSV_reg, _BIT1);//Let main default value enable force bg
	IoReg_SetBits(PPOVERLAY_MP_Layout_Force_to_Background_reg, _BIT1);//Let sub default value enable force bg

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[vbe_disp_resume] step 1, turn on VBy1 APHY Power\n");
	//IoReg_Write32(PINMUX_LVDSPHY_VBY1EPI_90_reg,0); //disable lane power;

	/*DTG*/
	//frank@02022016 IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, (vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL1_S_R&(~_BIT24)));
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, (vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL1_S_R&(~(_BIT24|_BIT26))));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[vbe_disp_resume] PPOVERLAY_Display_Timing_CTRL1_reg:%x !\n", IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg));
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL2_S_R);
	IoReg_Write32(PPOVERLAY_DV_Length_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_LENGTH_S_R);
	IoReg_Write32(PPOVERLAY_DV_total_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_TOTAL_S_R);
	IoReg_Write32(PPOVERLAY_DTG_pending_status_reg, vbe_disp_suspend_resume.PPOVERLAY_DTG_PENDING_STATUS_S_R);
	IoReg_Write32(PPOVERLAY_Display_Background_Color_reg, vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_BACKGROUND_COLOR_S_R);
	IoReg_Write32(PPOVERLAY_DH_Width_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_WIDTH_S_R);
	IoReg_Write32(PPOVERLAY_DTG_ie_reg, vbe_disp_suspend_resume.PPOVERLAY_DTG_IE_S_R);
	IoReg_Write32(PPOVERLAY_DH_Total_Last_Line_Length_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_S_R);
	IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_DEN_START_END_S_R);
	IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_DEN_START_END_S_R);
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, vbe_disp_suspend_resume.SYS_DISPCLKSEL_S_R);
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING2_S_R);
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING5_S_R);
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, vbe_disp_suspend_resume.PPOVERLAY_FS_IV_DV_FINE_TUNING1_S_R);
	IoReg_Write32(PPOVERLAY_uzudtg_DV_TOTAL_reg , vbe_disp_suspend_resume.PPOVERLAY_uzudtg_DV_TOTAL_S_R  );
	IoReg_Write32(PPOVERLAY_uzudtg_DH_TOTAL_reg , vbe_disp_suspend_resume.PPOVERLAY_uzudtg_DH_TOTAL_S_R  );
	IoReg_Write32(PPOVERLAY_DH_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DH_DEN_Start_End_S_R );
	IoReg_Write32(PPOVERLAY_DV_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_DV_DEN_Start_End_S_R );
	IoReg_Write32(PPOVERLAY_UZUDTG_COUNTROL_reg , vbe_disp_suspend_resume.PPOVERLAY_UZUDTG_COUNTROL_S_R  );
	IoReg_Write32(PPOVERLAY_memcdtg_DV_TOTAL_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DV_TOTAL_S_R );
	IoReg_Write32(PPOVERLAY_memcdtg_DH_TOTAL_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DH_TOTAL_S_R );
	IoReg_Write32(PPOVERLAY_memcdtg_DH_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DH_DEN_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg, vbe_disp_suspend_resume.PPOVERLAY_memcdtg_DV_DEN_Start_End_S_R);
	IoReg_Write32(PPOVERLAY_MEMCDTG_CONTROL_reg, vbe_disp_suspend_resume.PPOVERLAY_MEMCDTG_CONTROL_S_R  );
	//IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg  , vbe_disp_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_S_R|_BIT12); //@benwang marked for resume test
	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg  , vbe_disp_suspend_resume.PPOVERLAY_MEMC_MUX_CTRL_S_R);
	IoReg_Write32(PPOVERLAY_uzudtg_fractional_fsync_reg,vbe_disp_suspend_resume.PPOVERLAY_UZUDTG_FRACTIONAL_FSYNC_S_R);

	/*SFG*/
	//[QEVENT-7662]Fixed OLED panel EIT function sfg setting issue @Crixus 20160527
	if((Get_DISPLAY_PANEL_OLED_TYPE() == TRUE) && (oled_resume_eit_flag == TRUE)){
		IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, (vbe_disp_suspend_resume.SFG_SFG_FORCE_BG_AT_DIF_S_R | _BIT31));// In OLED EIT function, resume must enable SFG forceBG @Crixus 20160527
		oled_resume_eit_flag = FALSE;
	}
	else{
		IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, (vbe_disp_suspend_resume.SFG_SFG_FORCE_BG_AT_DIF_S_R & ~_BIT31));// resume must disable SFG forceBG @Crixus 20160124
	}
	//IoReg_Write32(SFG_SFG_CTRL_0_reg, vbe_disp_suspend_resume.SFG_SFG_CTRL_0_S_R);
	/*Clk*/
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, vbe_disp_suspend_resume.CRT_PLL_SSC0_S_R&~_BIT0);
	IoReg_Write32(PLL27X_REG_PLL_SSC3_reg, vbe_disp_suspend_resume.CRT_PLL_SSC3_S_R);
	if(Get_DISPLAY_PANEL_TYPE() == P_EPI_TYPE){
		//EPI initial flow.
	}else{
		IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, vbe_disp_suspend_resume.CRT_PLL_SSC4_S_R);
	}
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, vbe_disp_suspend_resume.CRT_SYS_DCLKSS_S_R);
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP1_reg, vbe_disp_suspend_resume.CRT_SYS_PLL_DISP1_S_R);
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP2_reg, vbe_disp_suspend_resume.CRT_SYS_PLL_DISP2_S_R);
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, vbe_disp_suspend_resume.CRT_SYS_PLL_DISP3_S_R);
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, vbe_disp_suspend_resume.CRT_SYS_DISPCLKSEL_S_R);
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, (vbe_disp_suspend_resume.PPOVERLAY_DOUBLE_BUFFER_CTRL_S_R)|_BIT0);

	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, (vbe_disp_suspend_resume.CRT_PLL_SSC0_S_R|_BIT0));

#if 0
	cnt=10;
	do{
		pll_ssc5_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC5_reg);
		msleep(10);
	}while((pll_ssc5_reg.oc_done != 1) && (--cnt));
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_resume] pll_ssc5_reg.oc_done=%d, cnt=%d \n", pll_ssc5_reg.oc_done, cnt);
	if(cnt==0)
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_resume]Wait oc_done timeout\n");
#endif
	mdelay(1); //150us for dpll hw apply
	IoReg_ClearBits(PLL27X_REG_PLL_SSC0_reg,_BIT0);

	//power on sequence : panel to LVDS on
	if(Get_DISPLAY_PANEL_TYPE()==P_LVDS_2K1K){
		rtd_printk(KERN_EMERG, TAG_NAME_VBE,"[vbe_disp_resume] Get_PANEL_TO_LVDS_ON_ms = %d\n", Get_PANEL_TO_LVDS_ON_ms());
		mdelay(Get_PANEL_TO_LVDS_ON_ms());
	}
	vbe_disp_panel_resume();
	stBacklihgtStart_Tick = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg);
	//Panel_TurnOn();
	Panel_SetPanelOnOff(1);
	msleep(Get_PANEL_TO_LVDS_ON_ms());
	rtd_outl(0xb8000d90,0x3f3f0000);//enable  lane power
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, ((vbe_disp_suspend_resume.PPOVERLAY_DISPLAY_TIMING_CTRL1_S_R&(~(_BIT26)))|_BIT24));
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, (vbe_disp_suspend_resume.PPOVERLAY_DOUBLE_BUFFER_CTRL_S_R)|_BIT0);

	tmp = 0;
	while(IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0){
		mdelay(2);
		if(++tmp>30)
			break;
	}
	if(tmp > 30)
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[vbe_disp_resume]Wait Display double buffer reg timeout\n");

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_resume] d domain ready\n");


	//IoReg_Write32(PINMUX_LVDSPHY_VBY1EPI_90_reg, vbe_disp_suspend_resume.PINMUX_LVDSPHY_VBY1EPI_90_S_R); //enable lane power
	//vbe_disp_vby1_init_flow();

	//clear first boot flag
	first_boot_run_main = FALSE;

#if !defined(CONFIG_CUSTOMER_TV006) && defined(CONFIG_RTK_KDRV_GDMA)
	gdma_resume_by_vbe();
#endif
}

void vbe_disp_early_resume()
{
	vbe_disp_resume();

}
EXPORT_SYMBOL(vbe_disp_early_resume);

#endif

/*******************************************************************************
****************************VBE DISP TCON DRIVER********************************
*******************************************************************************/
void HAL_VBE_DISP_TCON_Initialize(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
}
void HAL_VBE_DISP_TCON_Uninitialize(void){
	//to do
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
}
void HAL_VBE_DISP_TCON_EnableColorTemp(bool bOnOff){
	//to do
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
}
void HAL_VBE_DISP_TCON_EnableDGA(bool bOnOff){
	//to do
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
}
void HAL_VBE_DISP_TCON_EnableDither(bool bOnOff){
	Color_Fun_Bypass bDither;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, enable = %d\n",__FUNCTION__,bOnOff);
	bDither.idIP = BYPASS_D_DITHER;
	bDither.bypass_switch = bOnOff;

	drvif_color_bypass(&bDither, 1);
}
void HAL_VBE_DISP_TCON_SetDitherMode(DISP_TCON_DITHER_T mode){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
	fwif_color_dither_mode(mode);
}
void HAL_VBE_DISP_TCON_SetGammaTable(UINT32 *pRedGammaTable, UINT32 *pGreenGammaTable, UINT32 *pBlueGammaTable){
	//to do
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
}
void HAL_VBE_DISP_TCON_EnableTCon(bool bOnOff){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
	HAL_VBE_DISP_TCON_EnableColorTemp(bOnOff);
	HAL_VBE_DISP_TCON_EnableDGA(bOnOff);
	HAL_VBE_DISP_TCON_EnableDither(bOnOff);
}
void HAL_VBE_DISP_TCON_H_Reverse(UINT8 u8Mode){
	sfg_sfg_ctrl_0_RBUS sfg_ctrl_0_reg;
	sfg_ctrl_0_reg.regValue = IoReg_Read32(SFG_SFG_CTRL_0_reg);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, u8Mode = %x\n",__FUNCTION__,u8Mode);
	 //hflip
	if(u8Mode){
		sfg_ctrl_0_reg.h_flip_en = 1;
	}
	else{
		sfg_ctrl_0_reg.h_flip_en = 0;
	}

	if(Get_DISPLAY_PANEL_TYPE() == P_EPI_TYPE){
		//EPI V16DRD Horizontal need hflip, so dirty patch it.
		sfg_ctrl_0_reg.h_flip_en = !sfg_ctrl_0_reg.h_flip_en;
	}

	IoReg_Write32(SFG_SFG_CTRL_0_reg, sfg_ctrl_0_reg.regValue);
}
void HAL_VBE_DISP_TCON_SetClock(bool bOnOff){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);

	//---------------------------------------------------------------------------------------------------------------------------------
	//SFG1:Video, DH_ST_END = 0x008C080C, DTG_HS_Width = 16, DTG_VS_Width = 6
	//---------------------------------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------------------------------
	//SFG, 1 Pixel Mode, DH_ST_END = 0x008C080C, DTG_HS_Width = 16, DTG_VS_Width = 6
	//---------------------------------------------------------------------------------------------------------------------------------
	IoReg_Write32(0xb802D900, 0x000018C0);	// 8-bit Mode, Dout Enable, delay chain inverse + 0ns
	IoReg_Write32(0xb802D904, 0x0000FF00);	// PIF_Clock = Dclk, Force to background enable
	IoReg_Write32(0xb802D908, 0xffff3210);	// Port A~H mapping
	IoReg_Write32(0xb802D90c, 0xffffffff);
	IoReg_Write32(0xb802D92C, 0x00005000);	// Line 4n + 0: shift 1 sub-Pixel
						// Line 4n + 1: shift 1 sub-Pixel
						// Line 4n + 2: no sub-Pixel shift
						// Line 4n + 3: no sub-Pixel shift
	IoReg_Write32(0xb802D930, 0x00000000);	// SEG 0/1, Front/End, 4n+0/4n+1 Line, no dummy pixel
	IoReg_Write32(0xb802D934, 0x00000000);	// SEG 2/3, Front/End, 4n+2/4n+3 Line, no dummy pixel
	IoReg_Write32(0xb802D938, 0x00000000);	// SEG 4/5, Front/End, 4n+0/4n+1 Line, no dummy pixel
	IoReg_Write32(0xb802D93c, 0x00000000);	// SEG 6/7, Front/End, 4n+2/4n+3 Line, no dummy pixel
	IoReg_Write32(0xb802D954, 0x25310400);	// DRD input line 0 mapping
	IoReg_Write32(0xb802D958, 0x25310400);	// DRD input line 1 mapping
	IoReg_Write32(0xb802D95c, 0x25310400);	// DRD input line 2 mapping
	IoReg_Write32(0xb802D960, 0x25310400);	// DRD input line 3 mapping
	IoReg_Write32(0xb802D964, 0x10000133);	// DRD Data Mapping, 4-SEG, 4-Port, H-Flip
	IoReg_Write32(0xb802D968, 0x000001E0);	// start address of SEG 0/1 , residue of SEG 0/1
	IoReg_Write32(0xb802D96C, 0x03C005A0);	// start address of SEG 2/3 , residue of SEG 2/3
	IoReg_Write32(0xb802D970, 0x00000000);	// start address of SEG 4/5 , residue of SEG 4/5
	IoReg_Write32(0xb802D974, 0x00000000);	// start address of SEG 6/7 , residue of SEG 6/7
	IoReg_Write32(0xb802D988, 0x40000000);	// Disable ByPass Mode, Auto config mode enable, Disanle SFG P2S Mode
	IoReg_Write32(0xb802D98c, 0x000F088B);	// HS_Width = 16 dclk; hsync_delay = DH_Total  - 13 = 2187;
	IoReg_Write32(0xb802D990, 0x00050000);	// VS_ST = 0; VS_END = 6;
	IoReg_Write32(0xb802D994, 0x008C0086);	// sfg_dh_den_sta = DH_DEN_ST = 140;
						// req_st = hs_back_porch - 6 = 134;
	IoReg_Write32(0xb802D990,0x044C0000);
	IoReg_Write32(0xb802D99C, 0x03C00000);	// final_line_length = 1920/2, hsync_threshold = 0
	IoReg_Write32(0xb802D9a0, 0x00000000);	// Residue_pix_div_12_split_mode (no USE)
						// Final_addr_split_mode for Tri-gate Mode (no USE)
	IoReg_Write32(0xb802D9a4, 0x008b0892);	// hs_den_io_dist = req_st + 6 = 140; (for EPI)
						// hs_io_dist = hs_delay + 6 = 2187 + 6 = 2193; (for EPI)
	IoReg_Write32(0xb802D9B8, 0x00000000);	// Line 4N/4N+1/4N+2/4N+3 => G_0/G_last select original data,
						// decided by zz_shift_lst_sel_0/1/2/3 & zz_shift_last_sel_0/1/2/3 first
						// data not inverse
	IoReg_Write32(0xb802D9E8, 0x00000000);	// SEG 0/1, no middle dummy pixel
	IoReg_Write32(0xb802D9EC, 0x00000000);	// SEG 0/1, no middle dummy pixel
	IoReg_Write32(0xb802D9F0, 0x00000000);	// SEG 0/1, no middle dummy pixel
	IoReg_Write32(0xb802D9F4, 0x00000000);	// SEG 0/1, no middle dummy pixel
	IoReg_Write32(0xb802Da08, 0x00000000);	// Active_pixel_RGB for Tri-Gate Mode & Last_ext_pixel for EPI

	//---------------------------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------------------------------------
	//PIF
	//---------------------------------------------------------------------------------------------------------------------------------
	IoReg_Write32(0xb802D000, 0x0000000C);	// PIF EPI Mode, data is Video, clock is Video_clk,
	IoReg_Write32(0xb802D010, 0x000050F0);	// LVDS A/B/C/D Port Enable, LSB First, LVDS format use Table1,
	IoReg_Write32(0xb802D100, 0x00010203);	// LVDS ARGB de_sel, vs_sel, hs_sel, rev0_sel,
	IoReg_Write32(0xb802D104, 0x04050607);	// LVDS ARGB rev0_sel, a1_sel, a2_sel,
	IoReg_Write32(0xb802D108, 0x0008090A);	// LVDS ARGB a3_sel, a4_sel, a5_sel,

	//---------------------------------------------------------------------------------------------------------------------------------
	//LVDS Pin Share
	//---------------------------------------------------------------------------------------------------------------------------------
	IoReg_Write32(0xb800087C, 0x00000000);	// LVDS A-Port C/D/E/F-Pair Pinshare,
	IoReg_Write32(0xb8000880, 0x00000000);	// LVDS A-Port A/B-Pair Pinshare, LVDS B-Port E/F-Pair Pinshare,
	IoReg_Write32(0xb8000884, 0x00000000);	// LVDS B-Port A/B/C/D-Pair Pinshare,
	IoReg_Write32(0xb8000888, 0x00000000);	// LVDS C-Port C/D/E/F-Pair Pinshare,
	IoReg_Write32(0xb800088C, 0x00000000);	// LVDS C-Port A/B-Pair Pinshare, LVDS D-Port E/F-Pair Pinshare,
	IoReg_Write32(0xb8000890, 0x00000000);	// LVDS D-Port A/B/C/D-Pair Pinshare,


	//---------------------------------------------------------------------------------------------------------------------------------
	//EPI MAC
	//---------------------------------------------------------------------------------------------------------------------------------
      	rtd_maskl(0xb8000204,0xFDFFFFFF,0x00000000); // [25]=0, EPI clk is normal path. (not debug mode) (CRT)
      	rtd_maskl(0xb802D904,0x8FFFFFFF,0x10000000); // [30:28]=001=DIV1, Epi  4-lane mode (SFG spec)

  	// EPI MAC-layer configuration
      	IoReg_Write32(0xb802D500,0x00000015);  // CTR_Start=0x15,CTR_Start_dummy=0x0,[30]=0=PN_no_swap

  	// L0~L7, Embedded bit setting
	IoReg_Write32(0xb802D504,0x00000000);  // L0: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D508,0x00000000);  // L1: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D50C,0x00000000);  // L2: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D510,0x00000000);  // L3: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D514,0x00000000);  // L4: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D518,0x00000000);  // L5: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D51C,0x00000000);  // L6: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D520,0x00000000);  // L7: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D524,0x0000db09);  // L0: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D528,0x0000db09);  // L1: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D52C,0x0000db09);  // L2: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D530,0x0000db09);  // L3: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D534,0x0000db09);  // L4: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D538,0x0000db09);  // L5: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D53C,0x0000db09);  // L6: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D540,0x0000db09);  // L7: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D544,0x00001010);  // L0: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D548,0x00001010);  // L1: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D54C,0x00001810);  // L2: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D550,0x00001810);  // L3: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D554,0x00001810);  // L4: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D558,0x00001810);  // L5: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D55C,0x00001010);  // L6: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D560,0x00001010);  // L7: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)

	// L8~L15, Embedded bit setting
	IoReg_Write32(0xb802D604,0x00000000);  // L0: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D608,0x00000000);  // L1: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D60C,0x00000000);  // L2: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D610,0x00000000);  // L3: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D614,0x00000000);  // L4: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D618,0x00000000);  // L5: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D61C,0x00000000);  // L6: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D620,0x00000000);  // L7: [31:16]=Phase_II_preamble_num=0, [15:0]=Phase_I_preamble_num=0
	IoReg_Write32(0xb802D624,0x0000db09);  // L0: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D628,0x0000db09);  // L1: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D62C,0x0000db09);  // L2: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D630,0x0000db09);  // L3: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D634,0x0000db09);  // L4: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D638,0x0000db09);  // L5: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D63C,0x0000db09);  // L6: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D640,0x0000db09);  // L7: [29:18]=New_CTRL_bit,[17:8]=SOE_rising=0xDB=(T2=222),[7:0]=SOE_falling=0x09=(T1=13)
	IoReg_Write32(0xb802D644,0x00001010);  // L0: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D648,0x00001010);  // L1: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D64C,0x00001810);  // L2: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D650,0x00001810);  // L3: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D654,0x00001810);  // L4: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D658,0x00001810);  // L5: CTR2: LTD2=1, GMAEN=1, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D65C,0x00001010);  // L6: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)
	IoReg_Write32(0xb802D660,0x00001010);  // L7: CTR2: LTD2=1, GMAEN=0, others:0 (LG: C14=1)

  	// Tcon merge setting (for 16lane)
	IoReg_Write32(0xb802D564,0xFFFFFFE1);  // CTR2:Select CTR2(c0 ~c5 ) source. From Tcon or Register(all "1"). (c0,POL from tcon1)//POL
	IoReg_Write32(0xb802D568,0xFFF07FFF);  // CTR2:Select CTR2(c6 ~c11) source. From Tcon or Register(all "1"). (c9,GSP from tcon0)
	IoReg_Write32(0xb802D56C,0xFFFFFFFF);  // CTR2:Select CTR2(c12~c17) source. From Tcon or Register(all "1").
	IoReg_Write32(0xb802D570,0xFFFFFFFF);  // CTR2:Select CTR2(c18~c23) source. From Tcon or Register(all "1").
	IoReg_Write32(0xb802D574,0xFFFFFFFF);  // CTR2:Select CTR2(c24~c29) source. From Tcon or Register(all "1").

 	// EPI mode setting (for 16lane)
	IoReg_Write32(0xb802D578,0x00000000);  // CTR3: reserved for future. bit30=0 to disable.
	IoReg_Write32(0xb802D57C,0x0000002A);  // Data_Start=0x2A,Data_Start_dummy=0x0.
	IoReg_Write32(0xb802D580,0x08000000);  // Bit31=0=No_data_in.(Bit30=1 to reset), Bit29=0=PRBS7_OFF, 8bit
	IoReg_Write32(0xb802D584,0xC0000000);  // [1]=0=Lock_hw_mode
	IoReg_Write32(0xb802D588,0x00093100);  // [21:17]=Port_num=00100=4_port, [16]=1=normal(no_rst),[11:10]=map_table=0

  	// Setting for application
     	rtd_maskl(0xb802d584,0xFFFFFFF9,0x00000006); // [1]=1=Lock_fw_mode, [2]=Lock_fw_value

	//---------------------------------------------------------------------------------------------------------------------------------
	//EPI PHY
	//---------------------------------------------------------------------------------------------------------------------------------
      	// EPI phy setting, 4Lane,
	// Data_rate = (594M/4)*14*2/(4lane) = 1.039Gbps
	// Pixel_clk = (594M/4)/(4lane) = 37.125Mbps
    	IoReg_Write32(0xb802D000, 0x0000000C);	// PIF EPI Mode, data is Video, clock is Video_clk,

  	//EPI_X,Y, Panel power enable
    	IoReg_Write32(0xb8000C74, 0x80000000);  // P0,P1, [31]=PLT_POW=1, All lane power = off
    	IoReg_Write32(0xb8000D74, 0x80000000);  // P0,P1, [31]=PLT_POW=1, All lane power = off

  	//EPI_X,Y, PhyPLL
    	IoReg_Mask32(0xb8000C08,0xFFFF88FF,0x00002300); // [14:12]=DIVM=2+2=4, [10:8]=DIVN=0x3=/8 (8lane)
    	IoReg_Mask32(0xb8000C0C,0xA008F1FF,0x04C20600); // [30]=0=CKPIXEL_NOTINV,[28:26]=1=DIV234=2, [25:20]=DIV_P=0xC(12+2=14) // [18:16]=Icp=0x2=3.75uA, [11:9]=Rs=0x3=12K
    	IoReg_Mask32(0xb8000D08,0xFFFF88FF,0x00002300); // [14:12]=DIVM=2+2=4,[10:8]=DIVN=0x3=/8 (8lane)
    	IoReg_Mask32(0xb8000D0C,0xA008F1FF,0x04C20600); // [30]=0=CKPIXEL_NOTINV,[28:26]=1=DIV234=2, [25:20]=DIV_P=0xC(12+2=14) // [18:16]=Icp=0x2=3.75uA, [11:9]=Rs=0x3=12K

  	//EPI_X (APHY)
	IoReg_Mask32(0xb8000C10,0x03F9FFC0,0x6C000000); // P0_A = Epi mode, [18:17]=00=300ohm, [5:0]=000000=EPI_LVDS_Mode (for A~F)
	IoReg_Mask32(0xb8000C14,0x03F9FFFF,0x6C000000); // P0_B = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C18,0x03F9FFFF,0x6C000000); // P0_C = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C1C,0x03F9FFFF,0x6C000000); // P0_D = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C20,0x03F9FFFF,0x6C000000); // P0_E = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C24,0x03F9FFFF,0x6C000000); // P0_F = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C28,0xDC0FFFFF,0x20000000); // P0, [29]=CK7X_Inv=1, [25:20]=000000=1X_current
	IoReg_Mask32(0xb8000C30,0x03F9FFC0,0x6C000000); // P1_A = Epi mode, [18:17]=00=300ohm, [5:0]=000000=EPI_LVDS_Mode (for A~F)
	IoReg_Mask32(0xb8000C34,0x03F9FFFF,0x6C000000); // P1_B = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C38,0x03F9FFFF,0x6C000000); // P1_C = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C3C,0x03F9FFFF,0x6C000000); // P1_D = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C40,0x03F9FFFF,0x6C000000); // P1_E = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C44,0x03F9FFFF,0x6C000000); // P1_F = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000C48,0xDC0FFFFF,0x20000000); // P1, [29]=CK7X_Inv=1, [25:20]=000000=1X_current
	IoReg_Mask32(0xb8000C50,0x3FFF3FFF,0x0000C000); // P0,P1,[31]=1=IBX, [30]=0=Epi,[15]=1=1VLDO_On,[14]=1=2VLDO_On
	IoReg_Mask32(0xb8000C50,0xFC01FFFF,0x01D00000); // P0,P1,[25:22]=Swing=7=(2.25+7*0.25=4mA), [21:17]=Vcom=8=(0.7+8*0.025=0.9V)
	IoReg_Mask32(0xb8000C54,0xFFC0C0C0,0x003F003F); // P0,[21:16]=111111=2.4mA (>1G),[13:8]=000000=Emp_Off,[5:0]=111111=Zon
	IoReg_Mask32(0xb8000C58,0xC0FFFFFF,0x3F000000); // P0,[29:24]=111111=EPI_CML_mode
	IoReg_Mask32(0xb8000C5C,0xFFC0C0C0,0x003F003F); // P1,[21:16]=111111=2.4mA (>1G),[13:8]=000000=Emp_Off,[5:0]=111111=Zon
	IoReg_Mask32(0xb8000C60,0xC0FFFFFF,0x3F000000); // P1,[29:24]=111111=EPI_CML_mode

	//EPI_Y (APHY)
	IoReg_Mask32(0xb8000D10,0x03F9FFC0,0x6C000000); // P0_A = Epi mode, [18:17]=00=300ohm, [5:0]=000000=EPI_LVDS_Mode (for A~F)
	IoReg_Mask32(0xb8000D14,0x03F9FFFF,0x6C000000); // P0_B = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D18,0x03F9FFFF,0x6C000000); // P0_C = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D1C,0x03F9FFFF,0x6C000000); // P0_D = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D20,0x03F9FFFF,0x6C000000); // P0_E = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D24,0x03F9FFFF,0x6C000000); // P0_F = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D28,0xDC0FFFFF,0x20000000); // P0, [29]=CK7X_Inv=1, [25:20]=000000=1X_current
	IoReg_Mask32(0xb8000D30,0x03F9FFC0,0x6C000000); // P1_A = Epi mode, [18:17]=00=300ohm, [5:0]=000000=EPI_LVDS_Mode (for A~F)
	IoReg_Mask32(0xb8000D34,0x03F9FFFF,0x6C000000); // P1_B = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D38,0x03F9FFFF,0x6C000000); // P1_C = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D3C,0x03F9FFFF,0x6C000000); // P1_D = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D40,0x03F9FFFF,0x6C000000); // P1_E = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D44,0x03F9FFFF,0x6C000000); // P1_F = Epi mode, [18:17]=00=300ohm
	IoReg_Mask32(0xb8000D48,0xDC0FFFFF,0x20000000); // P1, [29]=CK7X_Inv=1, [25:20]=000000=1X_current
	IoReg_Mask32(0xb8000D50,0x3FFF3FFF,0x0000C000); // P0,P1,[31]=1=IBX, [30]=0=Epi,[15]=1=1VLDO_On,[14]=1=2VLDO_On
	IoReg_Mask32(0xb8000D50,0xFC01FFFF,0x01D00000); // P0,P1,[25:22]=Swing=7=(2.25+7*0.25=4mA), [21:17]=Vcom=8=(0.7+8*0.025=0.9V)
	IoReg_Mask32(0xb8000D54,0xFFC0C0C0,0x003F003F); // P0,[21:16]=111111=2.4mA (>1G),[13:8]=000000=Emp_Off,[5:0]=111111=Zon
	IoReg_Mask32(0xb8000D58,0xC0FFFFFF,0x3F000000); // P0,[29:24]=111111=EPI_CML_mode
	IoReg_Mask32(0xb8000D5C,0xFFC0C0C0,0x003F003F); // P1,[21:16]=111111=2.4mA (>1G),[13:8]=000000=Emp_Off,[5:0]=111111=Zon
	IoReg_Mask32(0xb8000D60,0xC0FFFFFF,0x3F000000); // P1,[29:24]=111111=EPI_CML_mode

	//EPI_X,Y, Lane Power Enable
	IoReg_Mask32(0xb8000C74,0xC0FFFFFF,0x3F000000); // [29:24] =epi_lane_pow=111111=X_P0_on
	IoReg_Mask32(0xb8000C74,0xFFC0FFFF,0x003F0000); // [21:16] =epi_lane_pow=111111=X_P1_on
	IoReg_Mask32(0xb8000D74,0xC0FFFFFF,0x3F000000); // [29:24] =epi_lane_pow=111111=Y_P2_on
	IoReg_Mask32(0xb8000D74,0xFFC0FFFF,0x003F0000); // [21:16] =epi_lane_pow=111111=Y_P3_on

	//---------------------------------------------------------------------------------------------------------------------------------
	//TCON SETTING
	//---------------------------------------------------------------------------------------------------------------------------------

    	// Pinshare
    	IoReg_Mask32(0xb8000890,0xFFF0FF00,0x00040044); //pin share MCLK to become Tcon7 //pin share GCLK to become Tcon6 //pin share GST to become Tcon3
    	IoReg_Mask32(0xb800088c,0xFFFFFFF0,0x00000004); //pin share E/O to become Tcon14
	IoReg_Write32(0xb802d42c,0x00000000);	// Tcon grobal disable
	IoReg_Write32(0xb802d42c,0x00000001);	// Tcon grobal enable
	IoReg_Write32(0xb802d200,0x40000000);	// Tcon across line3, across frame enable

	// GST
	IoReg_Write32(0xb802d23c,0x00260052);	// Tcon2 Hstart Hend
	IoReg_Write32(0xb802d240,0x00260028);	// Tcon2 Vstart Vend
	IoReg_Write32(0xb802d244,0x00000180);	// Tcon2 across line1 mode
	IoReg_Write32(0xb802d258,0x040C040C);	// Tcon3 Hstart Hend
	IoReg_Write32(0xb802d25c,0x08A608AE);	// Tcon3 Vstart and Vend
	IoReg_Write32(0xb802d260,0x00000183);	// Tcon3 across line1 mode, Xor with Tcon[n-1]
	///////////////////////////////////////////////////////////////////////////////////////
	//GCLK for magellen
	//rtd_part_outl(0xb8000880,3,0,0x4);//pin share GCLK to become Tcon5
	////////////////////////////////////////////////////////////////////////////////////////
	// GCLK for mag2
	IoReg_Write32(0xb802d274,0x01C00108);	// Tcon4 Hstart Hend
	IoReg_Write32(0xb802d278,0x0024089E);	// Tcon4 Vstart Vend
	IoReg_Write32(0xb802d27c,0x00000280); 	// Tcon4 across line2 mode

	IoReg_Write32(0xb802d290,0x02B80070);	// Tcon5 Hstart Hend
	IoReg_Write32(0xb802d294,0x00220028);	// Tcon5 Vstart Vend
	IoReg_Write32(0xb802d298,0x000001C1);	// Tcon5 across line1 mode, And with Tcon[n-1]

	IoReg_Write32(0xb802d2ac,0x040C040C);	// Tcon6 Hstart Hend
	IoReg_Write32(0xb802d2b0,0x089E08AE);	// Tcon6 Vstart Vend
	IoReg_Write32(0xb802d2b4,0x00000182);	// Tcon6 across line1 mode, Or with Tcon[n-1]
	///////////////////////////////////////////////////////////////////////////////////////////
	// MCLK
	IoReg_Write32(0xb802d2c8,0x009001A8);	// Tcon7 HStart and Hend
	IoReg_Write32(0xb802d2cc,0x002A08A4);	// Tcon7 VStart and Vend
	IoReg_Write32(0xb802d2d0,0x00000080);	// Tcon7 Normal Mode

	// EO
	IoReg_Write32(0xb802d37c,0x040C040C); 	// Tcon13 Hstart Hend
	IoReg_Write32(0xb802d380,0x08AE08AE);	// Tcon13 Vstart Vend
	IoReg_Write32(0xb802d384,0x00000480);	// Tcon13 across frame mode
	IoReg_Write32(0xb802d38c,0x0000007E);	// Tcon13 across frame period
	IoReg_Write32(0xb802d398,0x004C004C);	// Tcon14 Hstart Hend
	IoReg_Write32(0xb802d39c,0x08AF08AF);	// Tcon14 Vstart Vend
	IoReg_Write32(0xb802d3a0,0x00000483);	// Tcon14 across frame mode
	IoReg_Write32(0xb802d3a8,0x0000007E);	// Tcon14 across frame period
	IoReg_Write32(0xb802d42c,0x00000000);	// Tcon grobal disable
	IoReg_Write32(0xb802d42c,0x00000001);	// Tcon grobal enable

	// POL
	IoReg_Write32(0xb802d220,0x004C004C);	// Tcon1 Hstart Hend
	IoReg_Write32(0xb802d224,0x002C002C);	// Tcon1 Vstart Vend
	IoReg_Write32(0xb802d228,0x00000480);	// Tcon1 frame across mode

	// GSP
	IoReg_Write32(0xb802d204,0x005C03A8);	// Tcon0 Hstart Hend
	IoReg_Write32(0xb802d208,0x00280030);	// Tcon0 Vstart Vend
	IoReg_Write32(0xb802d20c,0x00000180);	// Tcon0 across line1 mode

	IoReg_Write32(0xb802d42c,0x00000001);	// Tcon grobal enable


#ifdef CONFIG_PM
	if(bOnOff == TRUE)
		vbe_disp_tcon_suspend_resume.ENALE_SUSPEND_RESUME= TRUE;
	else
		vbe_disp_tcon_suspend_resume.ENALE_SUSPEND_RESUME= FALSE;
#endif
}
void HAL_VBE_DISP_TCON_WriteRegister(UINT32 u32Address, UINT32 u32Data){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
	IoReg_Write32(u32Address, u32Data);
}
void HAL_VBE_DISP_TCON_ReadRegister(UINT32 u32Address, UINT32 *pData){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
	*pData = IoReg_Read32(u32Address);
}
void HAL_VBE_DISP_TCON_SetLvdsFormat(HAL_VBE_DISP_TCON_LVDS_TYPE_T type){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, type = %x\n",__FUNCTION__,type);
	switch(type){
		case HAL_VBE_DISP_TCON_LVDS_VESA:
			rtd_maskl(PIF_LVDS_CTRL3_reg, 0xffffcfff, 0x00001000);
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"HAL_VBE_DISP_TCON_LVDS_VESA!!\n");
			break;

		case HAL_VBE_DISP_TCON_LVDS_JEIDA:
			rtd_maskl(PIF_LVDS_CTRL3_reg, 0xffffcfff, 0x00000000);
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"HAL_VBE_DISP_TCON_LVDS_JEIDA!!\n");
			break;

		default:
			break;
	}
}
void HAL_VBE_DISP_TCON_Debug(void){
	UINT8 item = 0xff;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
	do {
		item = 0xff;//Ventor_GetDebugItem()
          	switch(item){
              	case 0x00:
              	{
                  		// Control the vbe tcon debug message on or off.
              	}
                  	break;

              	case 0x01:
              	{
                  		//IoReg_Write32(u32Address, u32Data);
              	}
                  	break;

              	case 0x02:
              	{
                  		//pData = IoReg_Read32(u32Address);
                  		//print("offset [0x%08x] : data [0x%08x] \n", u32Address, pData);
              	}
                  	break;

              	default :
                  	break;
          }
      } while(item!=0xff);
}

/*******************************************************************************
****************************VBE AVE DRIVER**************************************
*******************************************************************************/
static unsigned char vbe_ave_input_index = 5;//MAX value
static unsigned char VBE_AVE_Global_Status = VBE_AVE_NOTHING;
int HAL_VBE_AVE_Initialize(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_NOTHING){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_AVE_Initialize fail. Source is not VBE_AVE_NOTHING.\n");
		return -1;
	}
	VBE_AVE_Global_Status = VBE_AVE_INIT_DONE;
	return 0;
}

int HAL_VBE_AVE_Uninitialize(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_INIT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_AVE_Uninitialize fail. Source is not VBE_AVE_INIT_DONE.\n");
		return -1;
	}
	VBE_AVE_Global_Status = VBE_AVE_NOTHING;

	return 0;
}

int HAL_VBE_AVE_Open(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_INIT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_AVE_Open fail. Source is not VBE_AVE_INIT_DONE.\n");
		return -1;
	}

	//enable TVE clock
	drvif_module_tve_init();
	VBE_AVE_Global_Status = VBE_AVE_OPEN_DONE;

	return 0;
}

int HAL_VBE_AVE_Close(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if((VBE_AVE_Global_Status != VBE_AVE_OPEN_DONE) && (VBE_AVE_Global_Status != VBE_AVE_CONNECT_DONE)){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_AVE_Close fail. Source is not VBE_AVE_OPEN_DONE.\n");
		return -1;
	}

	//reset tve
	drvif_module_tve_reset();

	VBE_AVE_Global_Status = VBE_AVE_INIT_DONE;

	return 0;
}
extern void scaler_dispDtoI3ddma_prog(TVE_VIDEO_MODE_SEL tve_mode);

int HAL_VBE_AVE_Connect(VBE_AVE_INPUT_INDEX AVEInput){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[scart out]AVEInput = %x \n",AVEInput);
	if(VBE_AVE_Global_Status != VBE_AVE_OPEN_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_AVE_Connect fail. Source is not VBE_AVE_OPEN_DONE.\n");
		return -1;
	}

	VBE_AVE_Global_Status = VBE_AVE_CONNECT_DONE;
	vbe_ave_input_index = AVEInput;

	switch(AVEInput){
		case TUNER_OUTPUT://ATV scart output
			drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_VD);
#ifdef CONFIG_PM
			vbe_ave_suspend_resume.ENALE_SUSPEND_RESUME = VBE_AVE_SUSPEND_RESUME_TUNER_OUTPUT;
#endif
			break;

		case VSC_SCALER0://DTV scart output
		case VSC_SCALER1:
			#if 1
			scaler_vodmatoI3ddma_prog(TVE_PAL_I, Get_PANEL_VFLIP_ENABLE());
			drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_TV_TVE);
			vo_se_scaling_ctrl(_TRUE);
			#else
			/*test only, disp-D=>i3ddma path*/
			scaler_dispDtoI3ddma_prog(TVE_PAL_I);
			drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_TV_TVE);
			#endif
#ifdef CONFIG_PM
			vbe_ave_suspend_resume.ENALE_SUSPEND_RESUME = VBE_AVE_SUSPEND_RESUME_VSC_SCALER;
#endif

			break;

		case VDEC0:
		case VDEC1:
			break;
	}



	//drvif_module_tve_AVout_Enable(TVE_AVOUT_ENABLE);

	return 0;
}

int HAL_VBE_AVE_Disconnect(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_CONNECT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_AVE_Disconnect fail. Source is not VBE_AVE_CONNECT_DONE.\n");
		return -1;
	}

	//Send RPC to disable tveinterrupt checking
	scaler_scart_out_isr_set_enable(_FALSE);
	vo_se_scaling_ctrl(_FALSE);

	//DTV sould de-initial i3ddma path
	if((vbe_ave_input_index == VSC_SCALER0) || (vbe_ave_input_index == VSC_SCALER1)){
		//de-initial i3ddma path
		disable_I3DDMA_dispDtoSub();
	}

	//VDAC source change to no using case, scart-out force background
	drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_IFD_DEBUG);
	VBE_AVE_Global_Status = VBE_AVE_OPEN_DONE;

	return 0;
}

void HAL_VBE_AVE_IsATVWatching(void){
	//to do
	//skip this function
	//rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s\n",__FUNCTION__);
}

void HAL_VBE_AVE_SetATVWatching(VBE_AVE_INPUT_INDEX AVEInput, BOOLEAN bIsATVWatching){
	//printk("###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_CONNECT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n HAL_VBE_AVE_SetATVWatching fail. Source is not VBE_AVE_CONNECT_DONE.\n");
		return;
	}

	if(AVEInput == VSC_SCALER1){
		// DTV watching
         		// do nothing
     	}
      	else if ((AVEInput == TUNER_OUTPUT) && (bIsATVWatching == TRUE)){
		//ATV Watching, Buf Clamp Off
      	}
      	else if ((AVEInput == TUNER_OUTPUT) && (bIsATVWatching == FALSE)){
		//ATV Not Watching, Buf Clamp On
      	}
}

void HAL_VBE_AVE_VBI_SetInsert(VBE_AVE_VBI_TYPE_T type, UINT8 OnOff){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_CONNECT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n HAL_VBE_AVE_VBI_SetInsert fail. Source is not VBE_AVE_CONNECT_DONE.\n");
		return;
	}
	switch(type){
		case VBE_AVE_VBI_PAL_TELETEXT:
			drvif_module_tve_vbi_setting(OnOff);
			break;

		case VBE_AVE_VBI_PAL_WSS:
			drvif_module_tve_wss_setting(OnOff);
			break;

		case VBE_AVE_VBI_PAL_VPS:
			drvif_module_tve_vps_setting(OnOff);
			break;

		case VBE_AVE_VBI_NTSC_CC608:
			drvif_module_tve_cc_setting(OnOff);
			break;

		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VBI type is error 1!!");
			break;
	}
#ifdef CONFIG_PM
	if(OnOff == TRUE){
		vbe_ave_suspend_resume.VBI_DATA_ENALE_SUSPEND_RESUME = TRUE;
		vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME = type;
	}
	else{
		vbe_ave_suspend_resume.VBI_DATA_ENALE_SUSPEND_RESUME = FALSE;
		vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME = VBE_AVE_VBI_MAX_SERVICE;
	}
#endif
}

#define TTX_DATA_MAX_SIZE 16*42 //42 bytes per line, total 16 lines and use 2-buffer
#define TTX_DATA_BUFFER_0	1
#define TTX_DATA_BUFFER_1	0
static UINT8 *ttx_data_pointer;
static unsigned int  ttx_vir_addr, ttx_vir_addr_noncache;
static unsigned int  ttx_phy_addr;
static UINT8 ttx_data_first_run_done = false;
static UINT8 ttx_data_buffer_index = TTX_DATA_BUFFER_0;
void HAL_VBE_AVE_VBI_InsertData (VBE_AVE_VBI_TYPE_T type, UINT32 nrLine, UINT32 *pLines, UINT32 size, UINT8 *pData){
	Struct_TVE_VPS_DATA *VPS_DATA;
	unsigned int  /*vps_vir_addr, */vps_vir_addr_noncache;
//	unsigned int  vps_phy_addr;
	unsigned int insert_vbi_data = 0, i = 0;
	UINT8 pline_count = 0;
	unsigned int top_line_position = 0, bottom_line_position = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_CONNECT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n HAL_VBE_AVE_VBI_InsertData fail. Source is not VBE_AVE_CONNECT_DONE.\n");
		return;
	}
	switch(type){
		case VBE_AVE_VBI_PAL_TELETEXT:
			//memory allocate
			if(ttx_data_first_run_done == false){
				ttx_vir_addr = (unsigned int)dvr_malloc_uncached(sizeof(unsigned char)*TTX_DATA_MAX_SIZE*2, (void**)&ttx_vir_addr_noncache);//use 2-buffer
				//ttx_phy_addr = (unsigned int)virt_to_phys((void*)ttx_vir_addr);
				ttx_phy_addr = (unsigned int)dvr_to_phys((void*)ttx_vir_addr);
				ttx_data_pointer = (void*)ttx_vir_addr_noncache;
				ttx_data_buffer_index = TTX_DATA_BUFFER_0;
				ttx_data_first_run_done = true;
				//printk("[crixus]TTX data furst do OK!!!!!\n");
			}
			else{
				//set the data pointer
				if(ttx_data_buffer_index == TTX_DATA_BUFFER_0){
					ttx_data_buffer_index = TTX_DATA_BUFFER_1;//change the buffer index
					ttx_data_pointer = ttx_data_pointer + sizeof(unsigned char)*TTX_DATA_MAX_SIZE;//change the data pointer to buffer 1
					//printk("[crixus]TTX data chanhe to buffer 1~~~\n");
				}
				else if(ttx_data_buffer_index == TTX_DATA_BUFFER_1){
					ttx_data_buffer_index = TTX_DATA_BUFFER_0;//change the buffer index
					ttx_data_pointer = ttx_data_pointer - sizeof(unsigned char)*TTX_DATA_MAX_SIZE;//change the data pointer to buffer 0
					//printk("[crixus]TTX data chanhe to buffer 0~~~\n");
				}
			}

			memset(ttx_data_pointer,0x0,sizeof(unsigned char)*size);
			memcpy(ttx_data_pointer,pData,sizeof(unsigned char)*size);

			//for(i=0;i<size;i++)
				//printk("ttx_data_pointer[%d] = %x\n",i,ttx_data_pointer[i]);

			//check the line numbr
			for(i=0;i<32;i++){
				pline_count++;
				//printk("pLines[%d] = %d\n",i,pLines[i]);
				if(pLines[i] >= 288){
					top_line_position = pLines[0];
					bottom_line_position = pLines[i];
					pline_count = pline_count -1;
					break;
				}
			}

			//set tt vbi data total line number
			drvif_module_tve_vbi_tt_line_num(pline_count);
			//set top and bottom field lone position
			drvif_module_tve_vbi_pos(top_line_position,bottom_line_position);
			//set memory address
			drvif_module_tve_vbi_memory_setting(ttx_phy_addr);
			//edge trigger to change buffer
			drvif_module_tve_vbidma_trigger(ttx_data_buffer_index);
			break;

		case VBE_AVE_VBI_PAL_WSS:
			//WSS mode use 2 bytes for each line
			insert_vbi_data = ((unsigned int)pData[1] << 8) | pData[0];
			drvif_module_tve_wss_data(insert_vbi_data);
			drvif_module_tve_wss_pos((pLines[0]-1));//there is one line inaccuracy
			break;

		case VBE_AVE_VBI_PAL_VPS:
			//memory allocate
		//	vps_vir_addr = (unsigned int)dvr_malloc_uncached(sizeof(Struct_TVE_VPS_DATA), (void**)&vps_vir_addr_noncache);
			//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
		//	VPS_DATA = (Struct_TVE_VPS_DATA *)vps_vir_addr_noncache;

			//VPS mode use 15 bytes for each line
			VPS_DATA = (Struct_TVE_VPS_DATA *)pData;
			drvif_module_tve_vps_data(VPS_DATA);
			drvif_module_tve_vps_pos(pLines[0]);
		//	dvr_free((void *)vps_vir_addr);
			break;

		case VBE_AVE_VBI_NTSC_CC608:
			//CC mode use 2 bytes for each line
			insert_vbi_data = ((unsigned int)pData[1] << 8) | pData[0];
			drvif_module_tve_cc_data(insert_vbi_data,insert_vbi_data);
			break;

		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VBI type is error 2!!");
			break;
	}
}

void HAL_VBE_AVE_SetVCRWinBlank(bool bOnOff){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_AVE_Global_Status);
	if(VBE_AVE_Global_Status != VBE_AVE_CONNECT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n HAL_VBE_AVE_SetVCRWinBlank fail. Source is not VBE_AVE_CONNECT_DONE.\n");
		return;
	}
	if(vbe_ave_input_index == TUNER_OUTPUT){//ATV mute=>disable DAC
		if(bOnOff == true)
			drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_IFD_DEBUG);
		else
			drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_TV_TVE);
	}
	else{//DTV mute
		drvif_module_tve_forcebg(bOnOff);
	}

}
#ifdef CONFIG_PM
//VBE suspend & resume
void vbe_ave_vdac_suspend(void){
	//VDAC
#if 0 //Fix error by Will Magellan2
	vbe_ave_suspend_resume.IFD_ANALOG_VDAC_VDBSO_S_R=IoReg_Read32(IFD_ANALOG_VDAC_VDBSO_VADDR);
	vbe_ave_suspend_resume.IFD_ANALOG_VDAC_S_R=IoReg_Read32(IFD_ANALOG_VDAC_VADDR);
	vbe_ave_suspend_resume.IFD_ANALOG_VADC_IDACO_CTRL1_S_R=IoReg_Read32(IFD_ANALOG_VADC_IDACO_CTRL1_VADDR);
	vbe_ave_suspend_resume.IFD_ANALOG_VDAC_IDACO_CTRL2_S_R=IoReg_Read32(IFD_ANALOG_VDAC_IDACO_CTRL2_VADDR);
	vbe_ave_suspend_resume.IFD_ANALOG_VDAC_SRC_SEL_S_R=IoReg_Read32(IFD_ANALOG_VDAC_SRC_SEL_VADDR);
#endif
}

//VBE suspend & resume
void vbe_ave_tve_dma_suspend(void){
	//TVEDMA
	vbe_ave_suspend_resume.TVE_DMA_TVE_VDDMA_S_R=IoReg_Read32(TVE_DMA_TVE_VDDMA_reg);
	vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_SATRT0_S_R=IoReg_Read32(TVE_DMA_TVEVDDMA_SATRT0_reg);
	vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_SATRT1_S_R=IoReg_Read32(TVE_DMA_TVEVDDMA_SATRT1_reg);
	vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_SATRT2_S_R=IoReg_Read32(TVE_DMA_TVEVDDMA_SATRT2_reg);
	vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_LINESTEP_S_R=IoReg_Read32(TVE_DMA_TVEVDDMA_LINESTEP_reg);
}

void vbe_ave_vdac_resume(void){
	//VDAC
#if 0 //Fix error by Will Magellan2
	IoReg_Write32(IFD_ANALOG_VDAC_VDBSO_VADDR,vbe_ave_suspend_resume.IFD_ANALOG_VDAC_VDBSO_S_R);
	IoReg_Write32(IFD_ANALOG_VDAC_VADDR,vbe_ave_suspend_resume.IFD_ANALOG_VDAC_S_R);
	IoReg_Write32(IFD_ANALOG_VADC_IDACO_CTRL1_VADDR,vbe_ave_suspend_resume.IFD_ANALOG_VADC_IDACO_CTRL1_S_R);
	IoReg_Write32(IFD_ANALOG_VDAC_IDACO_CTRL2_VADDR,vbe_ave_suspend_resume.IFD_ANALOG_VDAC_IDACO_CTRL2_S_R);
	IoReg_Write32(IFD_ANALOG_VDAC_SRC_SEL_VADDR,vbe_ave_suspend_resume.IFD_ANALOG_VDAC_SRC_SEL_S_R);
#endif
}

void vbe_ave_tve_dma_resume(void){
	//TVEDMA
	IoReg_Write32(TVE_DMA_TVE_VDDMA_reg,vbe_ave_suspend_resume.TVE_DMA_TVE_VDDMA_S_R);
	IoReg_Write32(TVE_DMA_TVEVDDMA_SATRT0_reg,vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_SATRT0_S_R);
	IoReg_Write32(TVE_DMA_TVEVDDMA_SATRT1_reg,vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_SATRT1_S_R);
	IoReg_Write32(TVE_DMA_TVEVDDMA_SATRT2_reg,vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_SATRT2_S_R);
	IoReg_Write32(TVE_DMA_TVEVDDMA_LINESTEP_reg,vbe_ave_suspend_resume.TVE_DMA_TVEVDDMA_LINESTEP_S_R);
}


void vbe_ave_dmavgip_i3ddma_suspend(void){
	//DMAVGIP
	vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_CTRL_S_R=IoReg_Read32(DMA_VGIP_DMA_VGIP_CTRL_reg);
	vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_ACT_HSTA_WIDTH_S_R=IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_ACT_VSTA_LENGTH_S_R=IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);
	vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_DELAY_S_R=IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_S_R=IoReg_Read32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);

	//I3DDMAcolorspace
	vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_S_R=IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
	vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M1_S_R=IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg);
	vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M2_S_R=IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M22_M23_reg);
	vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M3_S_R=IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg);
	vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Y_S_R=IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg);

	//I3DDMAUZD
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_CTRL0_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_VSD_CTRL0_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C0_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C0_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_SCALE_HOR_FACTOR_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_VSD_SCALE_VER_FACTOR_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_HOR_SEGMENT_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_HOR_DELTA1_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_VSD_INITIAL_VALUE_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg);
	vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_INITIAL_VALUE_S_R=IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg);

	//I3DDMACap
	vbe_ave_suspend_resume.I3DDMA_CAP_BOUNDARYADDR2_S_R=IoReg_Read32(H3DDMA_Cap_BoundaryAddr2_reg);
	vbe_ave_suspend_resume.I3DDMA_CAP_BOUNDARYADDR1_S_R=IoReg_Read32(H3DDMA_Cap_BoundaryAddr1_reg);
	vbe_ave_suspend_resume.I3DDMA_LR_SEPARATE_CTRL1_S_R=IoReg_Read32(H3DDMA_LR_Separate_CTRL1_reg);
	vbe_ave_suspend_resume.I3DDMA_LR_SEPARATE_CTRL2_S_R=IoReg_Read32(H3DDMA_LR_Separate_CTRL2_reg);
	vbe_ave_suspend_resume.I3DDMA_CAP_CTL1_S_R=IoReg_Read32(H3DDMA_Cap_CTL1_reg);
	vbe_ave_suspend_resume.I3DDMA_CAP_CTL0_S_R=IoReg_Read32(H3DDMA_Cap_CTL0_reg);
	vbe_ave_suspend_resume.I3DDMA_TG_V1_END_S_R=IoReg_Read32(H3DDMA_TG_v1_end_reg);
	vbe_ave_suspend_resume.I3DDMA_I3DDMA_ENABLE_S_R=IoReg_Read32(H3DDMA_I3DDMA_enable_reg);
	vbe_ave_suspend_resume.I3DDMA_BYTE_CHANNEL_SWAP_S_R=IoReg_Read32(H3DDMA_I3DDMA_byte_channel_swap_reg);
	vbe_ave_suspend_resume.I3DDMA_CAP_L1_START_S_R=IoReg_Read32(H3DDMA_Cap_L1_Start_reg);
	vbe_ave_suspend_resume.I3DDMA_CAP_L2_START_S_R=IoReg_Read32(H3DDMA_Cap_L2_Start_reg);
	vbe_ave_suspend_resume.I3DDMA_CAP_L3_START_S_R=IoReg_Read32(H3DDMA_Cap_L3_Start_reg);
}

void vbe_ave_dmavgip_i3ddma_resume(void){
	//DMA VGIP
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTRL_reg,vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_CTRL_S_R);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg,vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_ACT_HSTA_WIDTH_S_R);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg,vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_ACT_VSTA_LENGTH_S_R);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg,vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_DELAY_S_R);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg,vbe_ave_suspend_resume.DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_S_R);

	//I3DDMA color space
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg,vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_S_R);
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg,vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M1_S_R);
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M13_M21_reg,vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M2_S_R);
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg,vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M3_S_R);
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg,vbe_ave_suspend_resume.I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Y_S_R);

	//I3DDMA UZD
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_CTRL0_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_VSD_CTRL0_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB1_C0_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_UZD_FIR_COEF_TAB2_C0_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_SCALE_HOR_FACTOR_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_VSD_SCALE_VER_FACTOR_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_HOR_SEGMENT_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_HOR_DELTA1_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_VSD_INITIAL_VALUE_S_R);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg,vbe_ave_suspend_resume.I3DDMA_SCALEDOWN_HSD_INITIAL_VALUE_S_R);

	//I3DDMA Cap
	IoReg_Write32(H3DDMA_Cap_BoundaryAddr2_reg,vbe_ave_suspend_resume.I3DDMA_CAP_BOUNDARYADDR2_S_R);
	IoReg_Write32(H3DDMA_Cap_BoundaryAddr1_reg,vbe_ave_suspend_resume.I3DDMA_CAP_BOUNDARYADDR1_S_R);
	IoReg_Write32(H3DDMA_LR_Separate_CTRL1_reg,vbe_ave_suspend_resume.I3DDMA_LR_SEPARATE_CTRL1_S_R);
       	IoReg_Write32(H3DDMA_LR_Separate_CTRL2_reg,vbe_ave_suspend_resume.I3DDMA_LR_SEPARATE_CTRL2_S_R);
	IoReg_Write32(H3DDMA_Cap_CTL1_reg,vbe_ave_suspend_resume.I3DDMA_CAP_CTL1_S_R);
 	IoReg_Write32(H3DDMA_Cap_CTL0_reg,vbe_ave_suspend_resume.I3DDMA_CAP_CTL0_S_R);
 	IoReg_Write32(H3DDMA_TG_v1_end_reg,vbe_ave_suspend_resume.I3DDMA_TG_V1_END_S_R);
 	IoReg_Write32(H3DDMA_I3DDMA_enable_reg,vbe_ave_suspend_resume.I3DDMA_I3DDMA_ENABLE_S_R);
	IoReg_Write32(H3DDMA_I3DDMA_byte_channel_swap_reg,vbe_ave_suspend_resume.I3DDMA_BYTE_CHANNEL_SWAP_S_R);
	IoReg_Write32(H3DDMA_Cap_L1_Start_reg,vbe_ave_suspend_resume.I3DDMA_CAP_L1_START_S_R);
	IoReg_Write32(H3DDMA_Cap_L2_Start_reg,vbe_ave_suspend_resume.I3DDMA_CAP_L2_START_S_R);
	IoReg_Write32(H3DDMA_Cap_L3_Start_reg,vbe_ave_suspend_resume.I3DDMA_CAP_L3_START_S_R);
}

void vbe_ave_vbidata_tt_suspend(void){
/*	//fix me later
	//VBI DATA - TT
	vbe_ave_suspend_resume.TT_CTRL_S_R=IoReg_Read32(TT_CTRL_reg);
	vbe_ave_suspend_resume.TT_VPOS_S_R=IoReg_Read32(TT_VPOS_reg);
	vbe_ave_suspend_resume.TVE_DMA_TVEVBIDMA_CTRL_S_R=IoReg_Read32(TVE_DMA_TVEVBIDMA_CTRL_reg);
	vbe_ave_suspend_resume.TVE_DMA_TVEVBIDMA_START_S_R=IoReg_Read32(TVE_DMA_TVEVBIDMA_START_reg);
	vbe_ave_suspend_resume.TVE_DMA_TVEVBIDMA_READ_WINDOW_S_R=IoReg_Read32(TVE_DMA_TVEVBIDMA_READ_WINDOW_reg);
*/
}

void vbe_ave_vbidata_wss_suspend(void){
/*	//fix me later
	//VBI DATA - WSS
	vbe_ave_suspend_resume.WSS_CTRL_S_R=IoReg_Read32(WSS_CTRL_reg);
	vbe_ave_suspend_resume.WSS_POS_S_R=IoReg_Read32(WSS_POS_reg);
*/
}

void vbe_ave_vbidata_vps_suspend(void){
/*  //fix me later
	//VBI DATA - VPS
	vbe_ave_suspend_resume.VPS_CTRL_S_R=IoReg_Read32(VPS_CTRL_reg);
	vbe_ave_suspend_resume.VPS_DATA_0_S_R=IoReg_Read32(VPS_DATA_0_reg);
	vbe_ave_suspend_resume.VPS_DATA_1_S_R=IoReg_Read32(VPS_DATA_1_reg);
	vbe_ave_suspend_resume.VPS_DATA_2_S_R=IoReg_Read32(VPS_DATA_2_reg);
	vbe_ave_suspend_resume.VPS_DATA_3_S_R=IoReg_Read32(VPS_DATA1_reg);
*/
}

void vbe_ave_vbidata_cc_suspend(void){
/*  //fix me later
	//VBI DATA - CC
	vbe_ave_suspend_resume.IP_CCD_ENBL_S_R=IoReg_Read32(IP_CCD_ENBL_reg);
	vbe_ave_suspend_resume.IP_CCD_ODD_0_S_R=IoReg_Read32(IP_CCD_ODD_0_reg);
	vbe_ave_suspend_resume.IP_CCD_ODD_1_S_R=IoReg_Read32(IP_CCD_ODD_1_reg);
	vbe_ave_suspend_resume.IP_CCD_EVEN_0_S_R=IoReg_Read32(IP_CCD_EVEN_0_reg);
	vbe_ave_suspend_resume.IP_CCD_EVEN_1_S_R=IoReg_Read32(IP_CCD_EVEN_1_reg);
*/
}

void vbe_ave_vbidata_tt_resume(void){
/* //fix me later
	//VBI DATA - TT
	IoReg_Write32(TT_CTRL_reg,vbe_ave_suspend_resume.TT_CTRL_S_R);
	IoReg_Write32(TT_VPOS_reg,vbe_ave_suspend_resume.TT_VPOS_S_R);
	IoReg_Write32(TVE_DMA_TVEVBIDMA_CTRL_reg,vbe_ave_suspend_resume.TVE_DMA_TVEVBIDMA_CTRL_S_R);
	IoReg_Write32(TVE_DMA_TVEVBIDMA_START_reg,vbe_ave_suspend_resume.TVE_DMA_TVEVBIDMA_START_S_R);
	IoReg_Write32(TVE_DMA_TVEVBIDMA_READ_WINDOW_reg,vbe_ave_suspend_resume.TVE_DMA_TVEVBIDMA_READ_WINDOW_S_R);
*/
}

void vbe_ave_vbidata_wss_resume(void){
/* //fix me later
	//VBI DATA - WSS
	IoReg_Write32(WSS_CTRL_reg,vbe_ave_suspend_resume.WSS_CTRL_S_R);
	IoReg_Write32(WSS_POS_reg,vbe_ave_suspend_resume.WSS_POS_S_R);
*/
}

void vbe_ave_vbidata_vps_resume(void){
/*  //fix me later
	//VBI DATA - VPS
	IoReg_Write32(VPS_CTRL_reg,vbe_ave_suspend_resume.VPS_CTRL_S_R);
	IoReg_Write32(VPS_DATA_0_reg,vbe_ave_suspend_resume.VPS_DATA_0_S_R);
	IoReg_Write32(VPS_DATA_1_reg,vbe_ave_suspend_resume.VPS_DATA_1_S_R);
	IoReg_Write32(VPS_DATA_2_reg,vbe_ave_suspend_resume.VPS_DATA_2_S_R);
	IoReg_Write32(VPS_DATA1_reg,vbe_ave_suspend_resume.VPS_DATA_3_S_R);
*/
}

void vbe_ave_vbidata_cc_resume(void){
/* //fix me later
	//VBI DATA - CC
	IoReg_Write32(IP_CCD_ENBL_reg,vbe_ave_suspend_resume.IP_CCD_ENBL_S_R);
	IoReg_Write32(IP_CCD_ODD_0_reg,vbe_ave_suspend_resume.IP_CCD_ODD_0_S_R);
	IoReg_Write32(IP_CCD_ODD_1_reg,vbe_ave_suspend_resume.IP_CCD_ODD_1_S_R);
	IoReg_Write32(IP_CCD_EVEN_0_reg,vbe_ave_suspend_resume.IP_CCD_EVEN_0_S_R);
	IoReg_Write32(IP_CCD_EVEN_1_reg,vbe_ave_suspend_resume.IP_CCD_EVEN_1_S_R);
*/
}
#endif

/*******************************************************************************
****************************VBE_TRIDFMT DRIVER**********************************
*******************************************************************************/

static unsigned char  VBE_Tridfmt_Global_Status = VBE_TRIDFMT_NOTHING;
static HAL_TRIDTV_INPUT_CONFIG_INFO_T vbe_tridtv_cfg_info;
static HAL_TRIDTV_FMT_CTRL_T vbe_tridtv_fmt;
void HAL_VBE_TRIDFMT_Initialize(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_Tridfmt_Global_Status);
	if(VBE_Tridfmt_Global_Status != VBE_TRIDFMT_NOTHING){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_TRIDFMT_Initialize fail. Source is not VBE_TRIDFMT_NOTHING.\n");
		return;
	}
	VBE_Tridfmt_Global_Status = VBE_TRIDFMT_INIT_DONE;
	return;
}

void HAL_VBE_TRIDFMT_Uninitialize(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_Tridfmt_Global_Status);
	if(VBE_Tridfmt_Global_Status != VBE_TRIDFMT_INIT_DONE){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_TRIDFMT_Uninitialize fail. Source is not VBE_TRIDFMT_INIT_DONE.\n");
		return;
	}
	VBE_Tridfmt_Global_Status = VBE_TRIDFMT_NOTHING;

	return;
}

void HAL_VBE_TRIDFMT_Open(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_Tridfmt_Global_Status);
	if(VBE_Tridfmt_Global_Status != VBE_TRIDFMT_INIT_DONE){
		printk("\r\n VBE_TRIDFMT_Open fail. Source is not VBE_TRIDFMT_INIT_DONE.\n");
		return;
	}

	vbe_tridtv_fmt.mode = VBE_TRIDTV_3DMODE_ON;
	vbe_tridtv_fmt.in_fmt = VBE_INPUT_TYPE_3DOFF;
	vbe_tridtv_fmt.out_fmt = VBE_OUT_SINGLE_FS;
	vbe_tridtv_fmt.lr = VBE_INPUT_LR_SEQ ;
	vbe_tridtv_fmt.depthCtrl = 10;
	vbe_tridtv_fmt.convCtrl = 0;
	vbe_tridtv_fmt.bAutoConvMode = 0;
	//VBE_set_tridfmt_connect(&vbe_tridtv_fmt);

	VBE_Tridfmt_Global_Status = VBE_TRIDFMT_OPEN_DONE;

	return;
}

void HAL_VBE_TRIDFMT_Close(void){
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_Tridfmt_Global_Status);
	if((VBE_Tridfmt_Global_Status != VBE_TRIDFMT_OPEN_DONE) && (VBE_Tridfmt_Global_Status != VBE_TRIDFMT_CONNECT_DONE)){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_TRIDFMT_Close fail. Source is not VBE_TRIDFMT_OPEN_DONE.\n");
		return;
	}

	//drvif_module_tve_reset();

	VBE_Tridfmt_Global_Status = VBE_TRIDFMT_INIT_DONE;

	return;
}

void HAL_VBE_TRIDFMT_SetScreenOnOff(BOOLEAN  bOnOff){
	set_display_forcebg_mask(SLR_MAIN_DISPLAY, SLR_FORCE_BG_TYPE_3D, bOnOff);
	down(get_forcebg_semaphore());
	scalerdisplay_force_bg_enable(SLR_MAIN_DISPLAY, bOnOff);
	up(get_forcebg_semaphore());
}

extern unsigned char rtk_output_connect(unsigned char display);
char VBE_set_tridfmt_connect(HAL_TRIDTV_FMT_CTRL_T *TriFRC){
	unsigned char curmode;
	unsigned char support3Dinput[INPUT_TYPE_MAX]= {
		SLR_3DMODE_2D, SLR_3DMODE_3D_TB, SLR_3DMODE_3D_SBS, SLR_3DMODE_2D,
		SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_3D_FP,
		SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_3D_SBS, SLR_3DMODE_2D,
		SLR_3DMODE_2D_CVT_3D};
	if(TriFRC == NULL){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VBE_TRIDFMT_SetFMTMode paramter NULL!!!\n");
		return FALSE;
	}
	if(TriFRC->mode >= VBE_TRIDTV_3DMODE_MAX || TriFRC->mode  < VBE_TRIDTV_3DMODE_OFF
		||TriFRC->in_fmt >= VBE_INPUT_TYPE_MAX || TriFRC->in_fmt < VBE_INPUT_TYPE_3DOFF
		||TriFRC->out_fmt >= VBE_OUT_MAX || TriFRC->out_fmt < VBE_OUT_SINGLE_2D
		||TriFRC->lr >= VBE_INPUT_LR_MAX || TriFRC->lr  < VBE_INPUT_LR_SEQ
		||TriFRC->depthCtrl > 20 || TriFRC->depthCtrl < 0
		|| TriFRC->convCtrl > 10 || TriFRC->convCtrl < -10){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VBE_TRIDFMT_SetFMTMode paramter error!!!\n");
		return FALSE;
	}

	if(TriFRC->mode == VBE_TRIDTV_3DMODE_OFF){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VBE_TRIDFMT_SetFMTMode OFF!change to 2D!\n");
		if(get_3D_mode_enable() == TRUE){
			set_3D_mode_enable(FALSE);
			set_3D_overscan_enable(FALSE);
			Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
			rtk_rerun_scaler(SLR_MAIN_DISPLAY);
		}
		return TRUE;
	}

	if(TriFRC->out_fmt != VBE_OUT_SINGLE_FS)
		TriFRC->out_fmt = VBE_OUT_SINGLE_FS;

	if(TriFRC->out_fmt != VBE_OUT_SINGLE_FS){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VBE_TRIDFMT_SetFMTMode out format no support!change to 2D!\n");
		if(get_3D_mode_enable() == TRUE){
			set_3D_mode_enable(FALSE);
			set_3D_overscan_enable(FALSE);
			Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
  			rtk_output_connect(SLR_MAIN_DISPLAY);
		}
		return TRUE;
	}
	else if(TriFRC->mode == VBE_TRIDTV_3DMODE_ON){
		curmode = TriFRC->in_fmt;
		curmode = support3Dinput[(curmode < VBE_INPUT_TYPE_MAX? curmode: VBE_INPUT_TYPE_3DOFF)];

		if(curmode == SLR_3DMODE_2D){
			if(get_3D_mode_enable() == TRUE){
				set_3D_mode_enable(FALSE);
				set_3D_overscan_enable(FALSE);
				Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
  				rtk_output_connect(SLR_MAIN_DISPLAY);
				return TRUE;
			}
			else{
				return TRUE;
			}
		}

		Scaler_Set3DMode(SLR_MAIN_DISPLAY, curmode, TRUE);
		 if (Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE() && TriFRC->in_fmt == VBE_INPUT_TYPE_2DTO3D){
			// [2D3D] default mode init
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"2d concvt 3d init\n");
			scaler_2Dcvt3D_init();
		}
		 if( drvif_scaler3d_decide_HDMI_framePacking_interlaced_status() && TriFRC->in_fmt == VBE_INPUT_TYPE_FRAMEPAC){
		 	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Interlace Fp 3D, change progress to interlace!\n");
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE,true);
		 }

		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);
  		rtk_output_connect(SLR_MAIN_DISPLAY);

		Scaler_Set3DLRSwap(TriFRC->lr);

		if(curmode == SLR_3DMODE_2D_CVT_3D)
			Scaler_Set2DCvt3D_Depth(TriFRC->depthCtrl);
		else if((curmode > SLR_3DMODE_2D) && (curmode <SLR_3DMODE_2D_CVT_3D))
		{
			/*change 2d cvt 3d to do depth control*/
			scaler_2Dcvt3D_init();
			scaler_2Dcvt3D_set_userEnableStatus(_ENABLE);
			scaler_2Dcvt3D_set_shifter(Scaler_Get2DCvt3D_Strength(), Scaler_Get2DCvt3D_Depth());
			scaler_2Dcvt3D_set_tilt_depth(scaler_2Dcvt3D_get_tilt_enable());
			Scaler_Set2DCvt3D_Depth(TriFRC->depthCtrl);
		}


		drv_2D_to_3D_shifter_offset(TriFRC->convCtrl);
	}
	return TRUE;
}

char HAL_VBE_TRIDFMT_SetFMTMode(VIDEO_WID_T wId,HAL_TRIDTV_FMT_CTRL_T *TriFRC){
#ifdef CONFIG_DUAL_CHANNEL
	if((wId < VIDEO_WID_MIN)||(wId > VIDEO_WID_MAX)){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"wId id is not ok\n");
		return FALSE;
	}
#else
	if(wId !=VIDEO_WID_0){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"wid id is not ok\n");
		return FALSE;
	}
#endif
	vbe_tridtv_fmt.mode = TriFRC->mode;
	vbe_tridtv_fmt.in_fmt = TriFRC->in_fmt;
	vbe_tridtv_fmt.lr = TriFRC->lr;
	vbe_tridtv_fmt.depthCtrl = TriFRC->depthCtrl;
	vbe_tridtv_fmt.convCtrl = TriFRC->convCtrl;
	vbe_tridtv_fmt.out_fmt = VBE_OUT_SINGLE_FS;
	vbe_tridtv_fmt.bAutoConvMode = TriFRC->bAutoConvMode;
	VBE_set_tridfmt_connect(&vbe_tridtv_fmt);

	return TRUE;
}

char HAL_VBE_TRIDFMT_SetFMTMode_TEMP(VIDEO_WID_T wId,HAL_TRIDTV_FMT_CTRL_TEMP_T *TriFRC){
#ifdef CONFIG_DUAL_CHANNEL
	if((wId < VIDEO_WID_MIN)||(wId > VIDEO_WID_MAX)){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"wId id is not ok\n");
		return FALSE;
	}
#else
	if(wId !=VIDEO_WID_0){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"wid id is not ok\n");
		return FALSE;
	}
#endif

	vbe_tridtv_fmt.mode = TriFRC->mode;
	vbe_tridtv_fmt.in_fmt = TriFRC->in_fmt;
	vbe_tridtv_fmt.lr = TriFRC->lr;
	vbe_tridtv_fmt.depthCtrl = TriFRC->depthCtrl;
	vbe_tridtv_fmt.convCtrl = TriFRC->convCtrl;
	vbe_tridtv_fmt.out_fmt = VBE_OUT_SINGLE_FS;
	vbe_tridtv_fmt.bAutoConvMode = TriFRC->bAutoConvMode;
	VBE_set_tridfmt_connect(&vbe_tridtv_fmt);

	return TRUE;
}

void HAL_VBE_TRIDFMT_Set3DModeOnOff(HAL_TRIDTV_INPUT_CONFIG_INFO_T *p3DModeInfo){
	vbe_tridtv_fmt.mode = p3DModeInfo->n3DInputMode;
	vbe_tridtv_fmt.in_fmt = p3DModeInfo->n3DInputType;
	vbe_tridtv_fmt.lr = p3DModeInfo->n3DInputLRSeq;
	vbe_tridtv_fmt.depthCtrl = p3DModeInfo->n3DInputDepthCtrl;
	vbe_tridtv_fmt.convCtrl = p3DModeInfo->n3DInputConvertCtrl;
	vbe_tridtv_fmt.out_fmt = VBE_OUT_SINGLE_FS;
	VBE_set_tridfmt_connect(&vbe_tridtv_fmt);
	return;
}

void HAL_VBE_TRIDFMT_ToggleInputLRFrame(HAL_TRIDTV_INPUT_LR_SEQ_T type){
	if(type >= VBE_INPUT_LR_MAX)
		return;
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() == true)
		Scaler_Set3DLRSwap(type);
}

void HAL_VBE_TRIDFMT_SelectInputFormat(HAL_TRIDTV_INPUT_TYPE_T type){
	vbe_tridtv_fmt.in_fmt = type;
	VBE_set_tridfmt_connect(&vbe_tridtv_fmt);
	return;
}

void HAL_VBE_TRIDFMT_SetInputFrameRate(HAL_TRIDTV_INPUT_FREQ_T type){
	//vbe 3D bypass
	return;
}

void HAL_VBE_TRIDFMT_ToggleOutputLRFrame(HAL_TRIDTV_OUTPUT_LR_SEQ_T type){
	if(type >= VBE_OUTPUT_LR_MAX)
		return;
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() == true)
		Scaler_Set3DLRSwap(type);

}

void HAL_VBE_TRIDFMT_SelectOutputFormat(HAL_TRIDTV_OUTPUT_TYPE_T type){
	vbe_tridtv_fmt.out_fmt = (VBE_3D_OUTPUT)type;
	VBE_set_tridfmt_connect(&vbe_tridtv_fmt);
	return;
}

void HAL_VBE_TRIDFMT_SetOutputFrameRate(HAL_TRIDTV_OUTPUT_FREQ_T type){
	//vbe 3D bypass
	return;
}

void HAL_VBE_TRIDFMT_Get3DCfgInfo(HAL_TRIDTV_CFG_ITEMS_T n3DCfgItems, UINT8 *nCurCfgInfo){
	if(nCurCfgInfo == NULL)
		return;
	if(n3DCfgItems >= VBE_TRIDTV_CFG_ITEMS_MAX)
		return;
	switch(n3DCfgItems){
		case VBE_TRIDTV_3DMODE_STATUS:
			*nCurCfgInfo = vbe_tridtv_cfg_info.n3DInputMode;
			break;
		case VBE_TRIDTV_3D_INPUT_TYPE:
			*nCurCfgInfo = vbe_tridtv_cfg_info.n3DInputType;
			break;
		case VBE_TRIDTV_3D_INPUT_LR_SEQ:
			*nCurCfgInfo = vbe_tridtv_cfg_info.n3DInputLRSeq;
			break;
		default:
			break;
	}
}

void HAL_VBE_TRIDFMT_Set3DCfgInfo(HAL_TRIDTV_INPUT_CONFIG_INFO_T *p3DModeInfo){
	if(p3DModeInfo == NULL)
		return;

	vbe_tridtv_cfg_info.n3DInputMode = p3DModeInfo->n3DInputMode;
	vbe_tridtv_cfg_info.n3DInputType = p3DModeInfo->n3DInputType;
	vbe_tridtv_cfg_info.n3DInputLRSeq = p3DModeInfo->n3DInputLRSeq;
	vbe_tridtv_cfg_info.n3DInputDepthCtrl = p3DModeInfo->n3DInputDepthCtrl;
	vbe_tridtv_cfg_info.n3DInputConvertCtrl = p3DModeInfo->n3DInputConvertCtrl;
	vbe_tridtv_cfg_info.bPositiveDepth = p3DModeInfo->bPositiveDepth;
	vbe_tridtv_cfg_info.bAutoConvMode = p3DModeInfo->bAutoConvMode;

}

void HAL_VBE_TRIDFMT_SetConvValue(char  s8ConvValue){
	if( Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D) {
		drv_2D_to_3D_shifter_offset(s8ConvValue);
	}
	else {
		scaler_2Dcvt3D_init();
		scaler_2Dcvt3D_set_userEnableStatus(_ENABLE);
		scaler_2Dcvt3D_set_shifter(Scaler_Get2DCvt3D_Strength(), Scaler_Get2DCvt3D_Depth());
		scaler_2Dcvt3D_set_tilt_depth(scaler_2Dcvt3D_get_tilt_enable());
		/*Scaler_Set2DCvt3D_Depth(s8ConvValue);*/
		drv_2D_to_3D_shifter_offset(s8ConvValue);
	}

}

void HAL_VBE_TRIDFMT_CtrlDepth(HAL_TRIDTV_3DMODE_FLAG_T n3Dmode, UINT8 u8DepthLevel){
	//unsigned char curmode;
	if(n3Dmode == VBE_TRIDTV_3DMODE_ON) {
		/*change 2d cvt 3d to do depth control*/
		scaler_2Dcvt3D_init();
		scaler_2Dcvt3D_set_userEnableStatus(_ENABLE);
		scaler_2Dcvt3D_set_shifter(Scaler_Get2DCvt3D_Strength(), Scaler_Get2DCvt3D_Depth());
		scaler_2Dcvt3D_set_tilt_depth(scaler_2Dcvt3D_get_tilt_enable());
		Scaler_Set2DCvt3D_Depth(u8DepthLevel);
	}
	else if (n3Dmode == VBE_TRIDTV_3DMODE_2DTO3D) {
		Scaler_Set2DCvt3D_Depth(u8DepthLevel);
	}
}

void HAL_VBE_TRIDFMT_AutoConvergenceEnable(BOOLEAN  bOnOff){
	vbe_tridtv_cfg_info.bAutoConvMode = bOnOff;
	//mac3 is not support
}

void HAL_VBE_TRIDFMT_Set3DVideoOutputMode(UINT32 bIsSGMode){
	//vbe 3D bypass
	return;
}

void HAL_VBE_TRIDFMT_Set3DDepthController(UINT32 bOnOff){
	vbe_tridtv_cfg_info.bPositiveDepth = bOnOff;
}

void HAL_VBE_TRIDFMT_Debug(void){
	//vbe 3D bypass
	return;
}

extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr; // debug scaler flag tracker //extern unsigned int main_opensourceID;
extern void Scaler_SET_VSCDispinfo_WithVFEHMDI(unsigned char display, vfe_hdmi_timing_info_t vfehdmitiminginfo);
extern int drivf_I3DDMA_3D_config(void);
extern void HDMI_set_detect_flag(unsigned char enable);
void HAL_V3D_Initialize (void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"###############%s, status = %d\n",__FUNCTION__,VBE_Tridfmt_Global_Status);
	if(VBE_Tridfmt_Global_Status != VBE_TRIDFMT_NOTHING){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\r\n VBE_TRIDFMT_Initialize fail. Source is not VBE_TRIDFMT_NOTHING.\n");
		return;
	}
	VBE_Tridfmt_Global_Status = VBE_TRIDFMT_INIT_DONE;
	return;
}
char HAL_V3D_Set3DFMT (VIDEO_WID_T wid, V3D_FMT_TYPE_T in_fmt, V3D_FMT_TYPE_T out_fmt)
{
	vfe_hdmi_timing_info_t vfehdmitiminginfo;
	unsigned char curmode;
	unsigned char support3Dinput[INPUT_TYPE_MAX]= {
		SLR_3DMODE_2D, SLR_3DMODE_3D_TB, SLR_3DMODE_3D_SBS, SLR_3DMODE_2D,
		SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_3D_FP,
		SLR_3DMODE_2D, SLR_3DMODE_2D, SLR_3DMODE_3D_SBS, SLR_3DMODE_3D_FP,
		SLR_3DMODE_2D_CVT_3D};
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"v3d:%d=%d\n",in_fmt, out_fmt);

	curmode = in_fmt;
	curmode = support3Dinput[(curmode < INPUT_TYPE_MAX? curmode: INPUT_TYPE_3DOFF)];

	if(in_fmt > V3D_FMT_MAX || in_fmt < V3D_FMT_2D
		||out_fmt > V3D_FMT_MAX ||out_fmt < V3D_FMT_2D)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scaler vsc Set3DForScaler paramter error!!!\n");
		return FALSE;
	}

	set_field_alternative_3d_mode_enable(FALSE);
#if 1
	if(get_line_alternative_3d_mode_enable() == TRUE)
	{
		Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, false);
		set_line_alternative_3d_mode_enable(FALSE);
		DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
	}
#endif
	 if(in_fmt == V3D_FMT_MAX  ||out_fmt == V3D_FMT_MAX)
	{

		if(get_3D_mode_enable() == TRUE)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scaler vsc Set3DForScaler MAXNUM!change to 2D!\n");
			set_3D_mode_enable(FALSE);
			set_3D_overscan_enable(FALSE);
			Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
			down(&VBE_Semaphore);
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
				rtk_output_connect(SLR_MAIN_DISPLAY);
			up(&VBE_Semaphore);
		}
		return TRUE;
	}


	/*force set the out_fmt SC_OUT_SINGLE_FS*/
	if(out_fmt != V3D_FMT_FRAMESEQ)
		out_fmt = V3D_FMT_FRAMESEQ;
#if 0
	if(out_fmt != V3D_FMT_FRAMESEQ)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scaler vsc Set3DForScaler out format no support!change to 2D!\n");
		if(get_3D_mode_enable() == TRUE)
		{
			set_3D_mode_enable(FALSE);
			set_3D_overscan_enable(FALSE);
			Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
			down(&VBE_Semaphore);
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
				rtk_output_connect(SLR_MAIN_DISPLAY);
			up(&VBE_Semaphore);
		}
		return TRUE;
	}
#endif
	if(in_fmt == V3D_FMT_DUALSTREAM)
	{
		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);
		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP, TRUE);
		down(&VBE_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			rtk_output_connect(SLR_MAIN_DISPLAY);
		up(&VBE_Semaphore);

		return TRUE;
	}

	if(in_fmt == V3D_FMT_LINE_ALTERNATIVE/*&& DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI*/)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"input is line alternative\n");
		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_LBL, TRUE);

		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);

		 //DisplayModeInputInfo.type = VSC_INPUTSRC_VDEC;

		if(0!=vfe_hdmi_drv_get_display_timing_info(&vfehdmitiminginfo, ((wid==VIDEO_WID_0)?SLR_MAIN_DISPLAY : SLR_SUB_DISPLAY)))
			return FALSE;
		Scaler_SET_VSCDispinfo_WithVFEHMDI(SLR_MAIN_DISPLAY,vfehdmitiminginfo);
		drvif_I3DDMA_Init();
		HDMI_set_detect_flag(FALSE);
		Scaler_DispSetInputInfo(SLR_INPUT_THROUGH_I3DDMA, true);
		set_line_alternative_3d_mode_enable(TRUE);
		drivf_I3DDMA_3D_config();

		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP, TRUE);
		Scaler_Disp3dSetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE,SLR_3D_FRAME_PACKING);
		Scaler_Set3DMode_Attr(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP);
		set_vo_3d_mode(VO_2D_MODE);

		DbgSclrFlgTkr.main_opensourceID =_UNKNOWN_INPUT;
		down(&VBE_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			rtk_output_connect(SLR_MAIN_DISPLAY);
		up(&VBE_Semaphore);

		return TRUE;


	}
	else if(in_fmt == V3D_FMT_FIELD_ALTERNATIVE/*&& DisplayModeInputInfo.type == VSC_INPUTSRC_HDMI*/)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"input is feild alternative\n");
		Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE,true);
		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);
		set_field_alternative_3d_mode_enable(TRUE);
		Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_3D_FP, TRUE);
		down(&VBE_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			rtk_output_connect(SLR_MAIN_DISPLAY);
		up(&VBE_Semaphore);

		 return TRUE;

	}
	if(wid == VIDEO_WID_0)
	{

		if(curmode == SLR_3DMODE_2D)
		{
			if(get_3D_mode_enable() == TRUE)
			{
				set_3D_mode_enable(FALSE);
				set_3D_overscan_enable(FALSE);
				Scaler_Set3DMode(SLR_MAIN_DISPLAY, SLR_3DMODE_2D, TRUE);
				down(&VBE_Semaphore);
				if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
					rtk_output_connect(SLR_MAIN_DISPLAY);
				up(&VBE_Semaphore);
				return TRUE;
			}
			else
			{
				return TRUE;
			}
		}

		Scaler_Set3DMode(SLR_MAIN_DISPLAY, curmode, TRUE);
	#if 0
		 if (Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE() && in_fmt == INPUT_TYPE_2DTO3D)
		{
			// [2D3D] default mode init
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"2d concvt 3d init\n");
			scaler_2Dcvt3D_init();
		}
	#endif
		 if( drvif_scaler3d_decide_HDMI_framePacking_interlaced_status() && in_fmt == V3D_FMT_FRAMEPAC)
		 {
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Interlace Fp 3D, change progress to interlace!\n");
			Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_INTERLACE,true);
		 }

		set_3D_mode_enable(TRUE);
		set_3D_overscan_enable(FALSE);
		down(&VBE_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			rtk_output_connect(SLR_MAIN_DISPLAY);
		up(&VBE_Semaphore);
	}

	return TRUE;
}


void HAL_V3D_SetLRSeq (V3D_LR_SEQ_T type)
{
	Scaler_Set3DLRSwap(type);
}
void HAL_V3D_CtrlConvergence (INT8 s8ConvValue)
{
	if( Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D) {
		drv_2D_to_3D_shifter_offset(s8ConvValue);
	}
	else {
		scaler_2Dcvt3D_init();
		scaler_2Dcvt3D_set_userEnableStatus(_ENABLE);
		scaler_2Dcvt3D_set_shifter(Scaler_Get2DCvt3D_Strength(), Scaler_Get2DCvt3D_Depth());
		scaler_2Dcvt3D_set_tilt_depth(scaler_2Dcvt3D_get_tilt_enable());
		/*Scaler_Set2DCvt3D_Depth(s8ConvValue);*/
		drv_2D_to_3D_shifter_offset(s8ConvValue);
	}
}
void HAL_V3D_CtrlDepth (UINT8 u8DepthLevel)
{
	if( Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D) {
		drv_2D_to_3D_shifter_offset(u8DepthLevel);
	}  else {
		/*change 2d cvt 3d to do depth control*/
		scaler_2Dcvt3D_init();
		scaler_2Dcvt3D_set_userEnableStatus(_ENABLE);
		scaler_2Dcvt3D_set_shifter(Scaler_Get2DCvt3D_Strength(), Scaler_Get2DCvt3D_Depth());
		scaler_2Dcvt3D_set_tilt_depth(scaler_2Dcvt3D_get_tilt_enable());
		Scaler_Set2DCvt3D_Depth(u8DepthLevel);
	}
}

void HAL_V3D_SetAutoConvEnable(BOOLEAN bOnOff)
{
	if(bOnOff == TRUE) {
		if( Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D) {
			drv_2D_to_3D_shifter_offset(0);
		}  else {
			/*change 2d cvt 3d to do depth control*/
			scaler_2Dcvt3D_init();
			scaler_2Dcvt3D_set_userEnableStatus(_ENABLE);
			scaler_2Dcvt3D_set_shifter(Scaler_Get2DCvt3D_Strength(), Scaler_Get2DCvt3D_Depth());
			scaler_2Dcvt3D_set_tilt_depth(scaler_2Dcvt3D_get_tilt_enable());
			Scaler_Set2DCvt3D_Depth(0);
		}
	}
}

void HAL_V3D_GetAutoDetectingResult (V3D_FMT_TYPE_T * pVideo3Dtype)
{
	unsigned char  curmode;
	if (Scaler_InputSrcGetMainChType() == _SRC_VO)
	{
		if(get_vo_3d_mode() == VO_3D_SIDE_BY_SIDE_HALF)
			*pVideo3Dtype = V3D_FMT_SIDEBYSIDE;
		else if(get_vo_3d_mode() == VO_3D_TOP_AND_BOTTOM)
			*pVideo3Dtype = V3D_FMT_TOPNBOTTOM;
		else
			*pVideo3Dtype = V3D_FMT_2D;
		return;
	}

	Scaler_Set3D_VoAutoDetect_Enable(true);
	check_vo3d_detect_result((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));
	curmode = modestate_get_vo3d_detect_result();
	switch(curmode)
	{
		case VO_2D_MODE:
			*pVideo3Dtype = V3D_FMT_2D;
			break;
		case VO_3D_SIDE_BY_SIDE_HALF:
			*pVideo3Dtype = V3D_FMT_SIDEBYSIDE;
			break;
		case VO_3D_TOP_AND_BOTTOM:
			*pVideo3Dtype = V3D_FMT_TOPNBOTTOM;
			break;
		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Can't detect 3D auto mode!\n");
			break;
	}

	return;
}

void HAL_V3D_SetAutoDetectingType (V3D_FORMAT_TYPE_T mode)
{
	mask_3d_auto_detect |= mode;
}


/*******************************************************************************
****************************VBE DEVICE******************************************
*******************************************************************************/
#ifdef CONFIG_PM

static int vbe_suspend (struct device *p_dev)
{
	//VBE_AVE suspend
	if(VBE_AVE_Global_Status == VBE_AVE_OPEN_DONE){
		vbe_ave_vdac_suspend();
	}
	else if(VBE_AVE_Global_Status == VBE_AVE_CONNECT_DONE){
		if(vbe_ave_suspend_resume.ENALE_SUSPEND_RESUME == VBE_AVE_SUSPEND_RESUME_VSC_SCALER){
			vbe_ave_vdac_suspend();
			vbe_ave_tve_dma_suspend();
			vbe_ave_dmavgip_i3ddma_suspend();
		}

	}

	//VBI DATA suspend
	if(vbe_ave_suspend_resume.VBI_DATA_ENALE_SUSPEND_RESUME == TRUE){
		if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_TELETEXT)
			vbe_ave_vbidata_tt_suspend();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_WSS)
			vbe_ave_vbidata_wss_suspend();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_VPS)
			vbe_ave_vbidata_vps_suspend();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_NTSC_CC608)
			vbe_ave_vbidata_cc_suspend();
	}

	vbe_disp_suspend();
	vpq_memc_disp_suspend_snashop();
	vpq_do_suspend();

	return 0;
}

static int vbe_resume (struct device *p_dev)
{
	//VBE_DISP_TCON resume
	if(vbe_disp_tcon_suspend_resume.ENALE_SUSPEND_RESUME == TRUE){
		HAL_VBE_DISP_TCON_SetClock(TRUE);
	}

	//VBE_AVE resume
	if(VBE_AVE_Global_Status == VBE_AVE_OPEN_DONE){
		drvif_tve_resume_setting();
		vbe_ave_vdac_resume();
	}
	else if(VBE_AVE_Global_Status == VBE_AVE_CONNECT_DONE){
		//both ATV and DTV scart out should do this
		drvif_tve_resume_setting();
		vbe_ave_vdac_resume();

		//DTV-scart out
		if(vbe_ave_suspend_resume.ENALE_SUSPEND_RESUME == VBE_AVE_SUSPEND_RESUME_VSC_SCALER){
			drv_tve_set_video_pal_i();
			vbe_ave_tve_dma_resume();
			vbe_ave_dmavgip_i3ddma_resume();
		}
	}

	//VBI DATA resume
	if(vbe_ave_suspend_resume.VBI_DATA_ENALE_SUSPEND_RESUME == TRUE){
		if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_TELETEXT)
			vbe_ave_vbidata_tt_resume();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_WSS)
			vbe_ave_vbidata_wss_resume();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_VPS)
			vbe_ave_vbidata_vps_resume();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_NTSC_CC608)
			vbe_ave_vbidata_cc_resume();
	}
	vbe_disp_resume();
	vpq_memc_disp_resume_snashop();
	vpq_do_resume();

	return 0;
}

static int vbe_suspend_instanboot (struct device *p_dev)
{
	//VBE_AVE suspend
	if(VBE_AVE_Global_Status == VBE_AVE_OPEN_DONE){
		vbe_ave_vdac_suspend();
	}
	else if(VBE_AVE_Global_Status == VBE_AVE_CONNECT_DONE){
		if(vbe_ave_suspend_resume.ENALE_SUSPEND_RESUME == VBE_AVE_SUSPEND_RESUME_VSC_SCALER){
			vbe_ave_vdac_suspend();
			vbe_ave_tve_dma_suspend();
			vbe_ave_dmavgip_i3ddma_suspend();
		}

	}

	//VBI DATA suspend
	if(vbe_ave_suspend_resume.VBI_DATA_ENALE_SUSPEND_RESUME == TRUE){
		if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_TELETEXT)
			vbe_ave_vbidata_tt_suspend();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_WSS)
			vbe_ave_vbidata_wss_suspend();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_VPS)
			vbe_ave_vbidata_vps_suspend();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_NTSC_CC608)
			vbe_ave_vbidata_cc_suspend();
	}
	vbe_disp_suspend();
	#ifdef CONFIG_HW_SUPPORT_MEMC
	vpq_memc_disp_suspend_instanboot();
	#endif
	vpq_do_suspend();
#ifdef VBE_DISP_TCON_SELF_CHECK
#ifdef CONFIG_RTK_KDRV_THERMAL_SENSOR
	monitor_rgb_rolling=1; //for stop tcon check
#endif
#endif
	return 0;
}

static int vbe_resume_instanboot (struct device *p_dev)
{

	//VBE_DISP_TCON resume
	if(vbe_disp_tcon_suspend_resume.ENALE_SUSPEND_RESUME == TRUE){
		HAL_VBE_DISP_TCON_SetClock(TRUE);
	}

	//VBE_AVE resume
	if(VBE_AVE_Global_Status == VBE_AVE_OPEN_DONE){
		drvif_tve_resume_setting();
		vbe_ave_vdac_resume();
	}
	else if(VBE_AVE_Global_Status == VBE_AVE_CONNECT_DONE){
		//both ATV and DTV scart out should do this
		drvif_tve_resume_setting();
		vbe_ave_vdac_resume();

		//DTV-scart out
		if(vbe_ave_suspend_resume.ENALE_SUSPEND_RESUME == VBE_AVE_SUSPEND_RESUME_VSC_SCALER){
			drv_tve_set_video_pal_i();
			vbe_ave_tve_dma_resume();
			vbe_ave_dmavgip_i3ddma_resume();
		}
	}

	//VBI DATA resume
	if(vbe_ave_suspend_resume.VBI_DATA_ENALE_SUSPEND_RESUME == TRUE){
		if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_TELETEXT)
			vbe_ave_vbidata_tt_resume();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_WSS)
			vbe_ave_vbidata_wss_resume();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_PAL_VPS)
			vbe_ave_vbidata_vps_resume();
		else if(vbe_ave_suspend_resume.VBI_DATA_TYPE_SUSPEND_RESUME == VBE_AVE_VBI_NTSC_CC608)
			vbe_ave_vbidata_cc_resume();
	}
	/*KTASKWBS-4676, wait LG webos call, so we enable first*/
	//vbe_disp_resume();
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[vbe_resume_instanboot] Remove vbe_disp_resume !\n");
	#ifdef CONFIG_HW_SUPPORT_MEMC
	vpq_memc_disp_resume_instanboot();
	#endif
	vpq_do_resume_instanboot();

	//EPI panel need to fix last line 4-align in fs mode @Crixus 20160929
	if(Get_DISPLAY_PANEL_TYPE() == P_EPI_TYPE){
		ppoverlay_fs_fll_mode_control_RBUS ppoverlay_fs_fll_mode_control_reg;
		ppoverlay_fs_fll_mode_control_reg.regValue = rtd_inl(PPOVERLAY_FS_FLL_Mode_Control_reg);
		ppoverlay_fs_fll_mode_control_reg.win_sta = 0x1120;
		ppoverlay_fs_fll_mode_control_reg.win_end = 0x112c;
		ppoverlay_fs_fll_mode_control_reg.fs_fll_range_mode = 1;
		rtd_outl(PPOVERLAY_FS_FLL_Mode_Control_reg, ppoverlay_fs_fll_mode_control_reg.regValue);
	}

	return 0;
}

#define WKSOR_REG   0xb8060574
#define WKSOR_PWR 3
#define WKSOR_WOL 6
#define WKSOR_RTC 8

static int vbe_resume_Backlight_TurnOn (struct device *p_dev)
{
	unsigned int tick1=0, tick2=0; 
	unsigned int pastTimeTick=0;
		
	tick1 = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg);
	if(tick1>=stBacklihgtStart_Tick)
		pastTimeTick = tick1 - stBacklihgtStart_Tick;
	else //loop back
		pastTimeTick = (0xffffffff-stBacklihgtStart_Tick) + tick1;

	if(pastTimeTick >= (Get_LVDS_TO_LIGHT_ON_ms()*90)){
		//no need to delay	
	}else{
		msleep(((Get_LVDS_TO_LIGHT_ON_ms()*90)-pastTimeTick)/90);
	}
	tick2 = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg);
	
	if(Panel_Get_STR_BackLight_Ctrl_Mode() == _BACKLIGHT_STR_CTRL_MODE_BY_KERNEL){
		Panel_SetBackLightMode(1);
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] STR BACKLIGHT CTRL MODE_BY_KERNEL\n",__FUNCTION__);
	}
	else if(Panel_Get_STR_BackLight_Ctrl_Mode() == _BACKLIGHT_STR_CTRL_MODE_BY_AP){
		unsigned int regValue = rtd_inl(WKSOR_REG);
		if(((regValue & 0xff) != 0x0) && ((regValue & 0xff) != WKSOR_WOL) && ((regValue & 0xff) != WKSOR_RTC))
		{
			printk(KERN_NOTICE "wakeup src (%x),(%x)\n", regValue,(regValue & 0xff));
			if((regValue & 0xff) == WKSOR_PWR)
			{
				if(((regValue >> 8) & 0x0000ffff) == 0xfef0)
				{
					printk(KERN_NOTICE "Netflix key(%x) wakeup, Do not Open Backlight\n", regValue);
				} else
					Panel_SetBackLightMode(1);
			}
			else
				Panel_SetBackLightMode(1);

			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] STR BACKLIGHT CTRL MODE_BY_AP\n",__FUNCTION__);
		}
		else
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] WOW wakeup,do not control backlight\n",__FUNCTION__);
		}
	}
	else{
		Panel_SetBackLightMode(1);
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] BACKLIGHT ON\n",__FUNCTION__);	
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[%s] BL_delay=%d(ms), BL_startTick=%x, tick1=%x, tick2=%x, \n",__FUNCTION__,
		Get_LVDS_TO_LIGHT_ON_ms(), stBacklihgtStart_Tick, tick1, tick2);

	return 0;
}
#endif

#ifdef CONFIG_ORBIT_PIXEL_SHIFT_ALGO

#define ORBIT_TABLE_IDX_MAX 44

typedef struct{
	unsigned char					pixel_left;
	unsigned char					pixel_up;
	unsigned char					pixel_right;
	unsigned char					pixel_down;
}ORBIT_PIXEL_SHIFT_TABLE;


ORBIT_PIXEL_SHIFT_TABLE orbit_position[ORBIT_TABLE_IDX_MAX]={
#if 0
	{0,0,0,0},
	{0,0,1,0},
	{0,0,2,0},
	{0,0,3,0},
	{0,0,4,0},
	{0,0,5,0},
	{0,0,5,1},
	{0,0,5,2},
	{0,0,5,3},
	{0,0,5,4},
	{0,0,5,5},
	{0,0,5,6},
	{0,0,5,7},
	{0,0,5,8},
	{0,0,5,9},
	{0,0,5,10},
	{0,0,4,10},
	{0,0,3,10},
	{0,0,2,10},
	{0,0,1,10},
	{0,0,0,10},
	{1,0,0,10},
	{2,0,0,10},
	{3,0,0,10},
	{4,0,0,10},
	{5,0,0,10},
	{5,0,0,9},
	{5,0,0,8},
	{5,0,0,7},
	{5,0,0,6},
	{5,0,0,5},
	{5,0,0,4},
	{5,0,0,3},
	{5,0,0,2},
	{5,0,0,1},
	{5,0,0,0},
	{4,0,0,0},
	{3,0,0,0},
	{2,0,0,0},
	{1,0,0,0}
#else
	{0,0,0,0},
	{0,0,1,0},
	{0,0,2,0},
	{0,0,3,0},
	{0,0,4,0},
	{0,0,5,0},
	{0,0,6,0},
	{0,0,7,0},
	{0,0,7,1},
	{0,0,7,2},
	{0,0,7,3},
	{0,0,7,4},
	{0,0,7,5},
	{0,0,7,6},
	{0,0,7,7},
	{0,0,7,8},
	{0,0,6,8},
	{0,0,5,8},
	{0,0,4,8},
	{0,0,3,8},
	{0,0,2,8},
	{0,0,1,8},
	{0,0,0,8},
	{1,0,0,8},
	{2,0,0,8},
	{3,0,0,8},
	{4,0,0,8},
	{5,0,0,8},
	{6,0,0,8},
	{7,0,0,8},
	{7,0,0,7},
	{7,0,0,6},
	{7,0,0,5},
	{7,0,0,4},
	{7,0,0,3},
	{7,0,0,2},
	{7,0,0,1},
	{7,0,0,0},
	{6,0,0,0},
	{5,0,0,0},
	{4,0,0,0},
	{3,0,0,0},
	{2,0,0,0},
	{1,0,0,0},
#endif
};

#define SHIFT_FACTOR 1
//#define GOLDEN_VSYC_LINE 0x9b
//#define GOLDEN_VSYC_PIXEL 0x40C
#define GOLDEN_VSYC_LINE 0x3c
#define GOLDEN_VSYC_PIXEL 0x1c16

/*api which have protect by forcebg_semaphore*/
void vbe_disp_orbit_position_update(unsigned char tableIdx)
{
	unsigned int orbit_pixel_shift, orbit_line_shift;
	ppoverlay_memcdtg_control3_RBUS memcdtg_control3_reg;
	ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
	ppoverlay_double_buffer_ctrl2_RBUS double_buffer_ctrl2_reg;
	static unsigned char previous_tableIdx=0xff;

	if(Get_DISPLAY_REFRESH_RATE() == 60){
		return;
	}

#ifdef CONFIG_MEMC_BYPASS	//bypass memc rzhen@2016-06-29
	return;
#endif

	if(vbe_disp_get_orbit()==FALSE){

		if(IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg)&_BIT14){
/*
			double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
			double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 1;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl2_reg.regValue);
			memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
			memc_mux_ctrl_reg.memcdtg_golden_vs = 0;
			IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg,memc_mux_ctrl_reg.regValue);
			double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
			double_buffer_ctrl2_reg.uzudtgreg_dbuf_set = 1;
			IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl2_reg.regValue);
*/
			memcdtg_control3_reg.regValue = IoReg_Read32(PPOVERLAY_MEMCDTG_CONTROL3_reg);
			memcdtg_control3_reg.dtgm2goldenpostvs_line = GOLDEN_VSYC_LINE;
			memcdtg_control3_reg.dtgm2goldenpostvs_pixel = GOLDEN_VSYC_PIXEL;
			IoReg_Write32(PPOVERLAY_MEMCDTG_CONTROL3_reg, memcdtg_control3_reg.regValue);
			IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);
		}

		return;
	}

	if(previous_tableIdx!=tableIdx){
		previous_tableIdx=tableIdx;
	}else{
		return;
	}

	if(tableIdx>=ORBIT_TABLE_IDX_MAX){
		tableIdx = 0;
		previous_tableIdx=tableIdx;
	}

	//set golden vs
	double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl2_reg.uzudtgreg_dbuf_en = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl2_reg.regValue);
//	memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
//	memc_mux_ctrl_reg.memcdtg_golden_vs = 1;
//	IoReg_Write32(PPOVERLAY_MEMC_MUX_CTRL_reg,memc_mux_ctrl_reg.regValue);
	double_buffer_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL2_reg);
	double_buffer_ctrl2_reg.uzudtgreg_dbuf_set = 1;
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL2_reg, double_buffer_ctrl2_reg.regValue);

	//set pixel & line shift
	orbit_pixel_shift = GOLDEN_VSYC_PIXEL  + (orbit_position[tableIdx].pixel_left*SHIFT_FACTOR) - (orbit_position[tableIdx].pixel_right*SHIFT_FACTOR);
	orbit_line_shift  = GOLDEN_VSYC_LINE   + (orbit_position[tableIdx].pixel_up*SHIFT_FACTOR) - (orbit_position[tableIdx].pixel_down*SHIFT_FACTOR);
	memcdtg_control3_reg.regValue = IoReg_Read32(PPOVERLAY_MEMCDTG_CONTROL3_reg);
	memcdtg_control3_reg.dtgm2goldenpostvs_line = orbit_line_shift;
	memcdtg_control3_reg.dtgm2goldenpostvs_pixel = orbit_pixel_shift;
	IoReg_Write32(PPOVERLAY_MEMCDTG_CONTROL3_reg, memcdtg_control3_reg.regValue);
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT0);

	 //pr_emerg("\n (tableIdx=%d)orbit_pixel_shift = %d, orbit_line_shift=%d \n",tableIdx, orbit_position[tableIdx].pixel_right-orbit_position[tableIdx].pixel_left, orbit_line_shift-GOLDEN_VSYC_LINE);
}

#endif

extern unsigned char drvif_scaler_frc2fsync_check_fsync_lock(void);

static irqreturn_t vbe_timer_display_interrupt(int irq, void *dev_id)
{
	//static unsigned int before_time = 0;
	//unsigned int after_time = 0;
	if(TIMER_ISR_get_tc7_int(IoReg_Read32(TIMER_ISR_reg))) {
        //after_time = IoReg_Read32(SCPU_CLK90K_LO_reg)/90;

		if(drvif_scaler_frc2fsync_check_fsync_lock()==TRUE){
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"fsync ok#\n");
			// disable timer7
			IoReg_Write32(TIMER_TC7CR_reg, 0);
			// write 1 clear
			IoReg_Write32(TIMER_ISR_reg, TIMER_ISR_tc7_int_mask);
			// disable timer7 interrupt
			IoReg_Write32(TIMER_TC7ICR_reg, 0);
			return IRQ_HANDLED;
		}

        //if(IoReg_Read32(0xb8022288)&_BIT22)
            //pr_emerg("#v(%d)#\n", after_time-before_time);
        //before_time = after_time;

		// disable timer7
		IoReg_Write32(TIMER_TC7CR_reg, 0);
		// write 1 clear
		IoReg_Write32(TIMER_ISR_reg, TIMER_ISR_tc7_int_mask);

		rtk_timer_set_target(7, TIMER_CLOCK/4000); // 2ms

		// enable timer7
		IoReg_Write32(TIMER_TC7CR_reg, TIMER_TC7CR_tc7en_mask);

		return IRQ_HANDLED;
    }
    return IRQ_NONE;
}

void vbe_disp_pwm_frequency_update(bool bEnableDB)
{
	ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_reg;
	ppoverlay_dv_total_RBUS dv_total_reg;
	unsigned int vtotal;
	unsigned int frameRates;
	unsigned long flags;//for spin_lock_irqsave

	//down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	ppoverlay_double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	ppoverlay_double_buffer_ctrl_reg.dreg_dbuf_read_sel = 1;  //D7_read_sel
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_reg.regValue);
	dv_total_reg.regValue = IoReg_Read32(PPOVERLAY_DV_total_reg);
	vtotal = dv_total_reg.dv_total;
	ppoverlay_double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	ppoverlay_double_buffer_ctrl_reg.dreg_dbuf_read_sel = 0;  //D7_read_sel
	IoReg_Write32(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	//up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	frameRates = Get_DISPLAY_CLOCK_TYPICAL() / (Get_DISP_HORIZONTAL_TOTAL()*vtotal);
	if((frameRates>=47) && (frameRates<=49)){
		frameRates = 48;
	}else if((frameRates>49) && (frameRates<51)){
		frameRates = 50;
	}else if(((frameRates>=51) && (frameRates<=59))||
		((frameRates>=45) && (frameRates<=47))){
		// apply it.
	}
	else if((frameRates>59) && (frameRates<61)){
		frameRates = 60;
	}else{
		frameRates = 60;
	}
	rtk_pwm_set_scaler_source(frameRates, 2, bEnableDB);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "########Set PWM framerate:%d##########\r\n", frameRates);

}

void vbe_disp_debug_framerate_change_msg(void)
{

	UINT32 u32_iFrameRateHz_pre = 0;
	UINT32 u32_iFrameRateHz = 0;
	UINT32 u32_oFrameRateHz_pre = 0;
	UINT32 u32_oFrameRateHz = 0;
	UINT32 u32_iFrameRateTh = (27000000/50 - 27000000/60)/2;
	UINT32 u32_oFrameRateTh = (27000000/100 - 27000000/120)/2;
	UINT32 u32_iFrameRate = 0;
	UINT32 u32_oFrameRate = 0;
	UINT32 u32_timingMode = 0;
	static UINT32 u32_iFrameRate_Pre = 0;
	static UINT32 u32_oFrameRate_Pre = 0;
	static UINT32 u32_timingMode_Pre = 0;
	UINT8 u1_trig_iFrameRate_noMatch;
	UINT8 u1_trig_oFrameRate_noMatch;

    u32_iFrameRate = IoReg_Read32(PPOVERLAY_uzudtg_DVS_cnt_reg);
	u32_oFrameRate = IoReg_Read32(PPOVERLAY_memcdtg_DVS_cnt_reg);
	u32_timingMode = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);

	u32_iFrameRateHz_pre    = (u32_iFrameRate_Pre==0) ? 0: (27000000*10/u32_iFrameRate_Pre);
	u32_iFrameRateHz        =  (u32_iFrameRate==0) ? 0: (27000000*10/u32_iFrameRate);
	u32_oFrameRateHz_pre    =  (u32_oFrameRate_Pre==0) ? 0: (27000000*10/u32_oFrameRate_Pre);
	u32_oFrameRateHz        =  (u32_oFrameRate==0) ? 0: (27000000*10/u32_oFrameRate);
	u32_timingMode			=  (u32_timingMode&~(0xE3FFFFFF))>>26;


	u1_trig_iFrameRate_noMatch	= (u32_iFrameRate>u32_iFrameRate_Pre)? ((u32_iFrameRate -u32_iFrameRate_Pre) > u32_iFrameRateTh) : ((u32_iFrameRate_Pre -u32_iFrameRate) > u32_iFrameRateTh);
	u1_trig_oFrameRate_noMatch    = (u32_oFrameRate>u32_oFrameRate_Pre)? ((u32_oFrameRate -u32_oFrameRate_Pre) > u32_oFrameRateTh) : ((u32_oFrameRate_Pre -u32_oFrameRate) > u32_oFrameRateTh);

	if(u1_trig_iFrameRate_noMatch )
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "[FR] in FrameRate Change!!!(%dHz(%d) -> %dHz(%d)),(t:%d)\n\r", u32_iFrameRateHz_pre, u32_iFrameRate_Pre, u32_iFrameRateHz, u32_iFrameRate, rtd_inl(TIMER_SCPU_CLK90K_LO_reg));
	//if(u1_trig_oFrameRate_noMatch  && u1_IOPhase_N2M_logEn)
	if(u1_trig_oFrameRate_noMatch )
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "[FR] out FrameRate Change!!!(%dHz(%d) -> %dHz(%d)),(t:%d)\n\r", u32_oFrameRateHz_pre, u32_oFrameRate_Pre, u32_oFrameRateHz, u32_oFrameRate, rtd_inl(TIMER_SCPU_CLK90K_LO_reg));

	if(u32_timingMode_Pre != u32_timingMode){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "[FR] Time Mode changed!!!(%d -> %d),(t:%d)\n\r", u32_timingMode_Pre, u32_timingMode, rtd_inl(TIMER_SCPU_CLK90K_LO_reg));
	}
	u32_iFrameRate_Pre      = u32_iFrameRate;
	u32_oFrameRate_Pre      = u32_oFrameRate;
	u32_timingMode_Pre		= u32_timingMode;
	//**************************//

}

#ifdef VBE_DISP_TCON_SELF_CHECK
unsigned int p0_lane_power_value;
unsigned int p1_lane_power_value;
unsigned int p2_lane_power_value;
unsigned int p3_lane_power_value;
void vbe_disp_lane_power_off(void)
{
#if 0  //FIXME: need to chedk lane power off setting @qing_liu
	pinmux_lvdsphy_lvdsepi_phy_ctrl_0_27_RBUS lvdsepi_phy_ctrl_0_27_reg;
	pinmux_lvdsphy_lvdsepi_phy_ctrl_1_27_RBUS lvdsepi_phy_ctrl_1_27_reg;
	lvdsepi_phy_ctrl_0_27_reg.regValue=IoReg_Read32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg);
	p0_lane_power_value=lvdsepi_phy_ctrl_0_27_reg.pow_plt_p0_txv;
	p1_lane_power_value=lvdsepi_phy_ctrl_0_27_reg.pow_plt_p1_txv;
	lvdsepi_phy_ctrl_0_27_reg.pow_plt_p0_txv=0;
	lvdsepi_phy_ctrl_0_27_reg.pow_plt_p1_txv=0;
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg,lvdsepi_phy_ctrl_0_27_reg.regValue);
	lvdsepi_phy_ctrl_1_27_reg.regValue=IoReg_Read32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_27_reg);
	p2_lane_power_value=lvdsepi_phy_ctrl_1_27_reg.pow_plt_p2_txv;
	p3_lane_power_value=lvdsepi_phy_ctrl_1_27_reg.pow_plt_p3_txv;
	lvdsepi_phy_ctrl_1_27_reg.pow_plt_p2_txv=0;
	lvdsepi_phy_ctrl_1_27_reg.pow_plt_p3_txv=0;
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_27_reg,lvdsepi_phy_ctrl_1_27_reg.regValue);
#endif
//	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"turn off VBy1 lane Power\n");
}
void vbe_disp_lane_power_on(void)
{
#if 0  //FIXME: need to chedk lane power off setting @qing_liu
	pinmux_lvdsphy_lvdsepi_phy_ctrl_0_27_RBUS lvdsepi_phy_ctrl_0_27_reg;
	lvdsepi_phy_ctrl_1_27_RBUS lvdsepi_phy_ctrl_1_27_reg;
	lvdsepi_phy_ctrl_0_27_reg.regValue=IoReg_Read32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg);
	lvdsepi_phy_ctrl_0_27_reg.pow_plt_p0_txv=0x3f;
	lvdsepi_phy_ctrl_0_27_reg.pow_plt_p1_txv=0x30;
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_0_27_reg,lvdsepi_phy_ctrl_0_27_reg.regValue);
	lvdsepi_phy_ctrl_1_27_reg.regValue=IoReg_Read32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_27_reg);
	lvdsepi_phy_ctrl_1_27_reg.pow_plt_p2_txv=0x03;
	lvdsepi_phy_ctrl_1_27_reg.pow_plt_p3_txv=0x3f;
	IoReg_Write32(PINMUX_LVDSPHY_LVDSEPI_PHY_CTRL_1_27_reg,lvdsepi_phy_ctrl_1_27_reg.regValue);
#endif
//	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[ep4] turn on VBy1 lane Power\n");
}

unsigned char vbe_disp_vby1_lockn_check(void)
{
#if 1  // lockn fw mode
/*
	unsigned char timeout = 1000;
		do{
			vby1_status_fw_ctrl_RBUS vby1_status_fw_ctrl_reg;
			vby1_status_fw_ctrl_reg.regValue = IoReg_Read32(VBY1_VBY1_STATUS_FW_CTRL_reg);
			if((vby1_status_fw_ctrl_reg.hw_lockn==0)&&(vby1_status_fw_ctrl_reg.hw_htpdn==0))
				break;
			mdelay(1);
		}while(--timeout);
	if(timeout == 0) {
	//	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_vby1_check_status] polling lockn FAIL=%d\n!!\n",(100-timeout));
		return 0;
	} else {
	//	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_vby1_check_status]lockn ok\n");
		msleep(100);
		return 1;
	}
*/
	unsigned int tmp = 0;
	unsigned int timeout = 3;
	vby1_vby1_status_fw_ctrl_RBUS vby1_status_fw_ctrl_reg;

	if(Get_DISPLAY_PANEL_CUSTOM_INDEX() == VBY_ONE_PANEL_innolux_4K2K_600M_1S_8L){
		//INX panel use hw lock mode, skip check
		return 1;
	}

	do{
		vby1_status_fw_ctrl_reg.regValue = IoReg_Read32(VBY1_VBY1_STATUS_FW_CTRL_reg);
		if((vby1_status_fw_ctrl_reg.hw_lockn!=0)||(vby1_status_fw_ctrl_reg.hw_htpdn!=0)){
			tmp++;
		}
	}while(--timeout);

	if(tmp)
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_vby1_lockn_check(debounds:%d)\n", tmp);



	if(tmp >= 3) {
		return 0;
	} else {
		return 1;
	}
#else
	unsigned char timeout = 100;
		do{
			vby1_status_fw_ctrl_RBUS vby1_status_fw_ctrl_reg;
			vby1_status_fw_ctrl_reg.regValue = IoReg_Read32(VBY1_VBY1_STATUS_FW_CTRL_reg);
			if((vby1_status_fw_ctrl_reg.hw_lockn==0)&&(vby1_status_fw_ctrl_reg.hw_htpdn==0))
				break;
			mdelay(1);
		}while(--timeout);
	if(timeout == 0) {
	//	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_vby1_check_status] polling lockn FAIL=%d\n!!\n",(100-timeout));
		return 0;
	} else {
	//	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"[vbe_disp_vby1_check_status]lockn ok\n");
		msleep(100);
		return 1;
	}
#endif
}
void lane_power_reset(void)
{
	unsigned char tmp = 0;
	unsigned char timeout = 100;

	vbe_disp_lane_power_off();
	mdelay(5);
#if 1
	IoReg_Write32(VBY1_VBY1_STATUS_FW_CTRL_reg,0xF0000000);
	IoReg_Write32(VBY1_VBY1_STATUS_FW_CTRL_reg,0xD0000000);
	do{
		vby1_vby1_status_fw_ctrl_RBUS vby1_status_fw_ctrl_reg;
		vby1_status_fw_ctrl_reg.regValue = IoReg_Read32(VBY1_VBY1_STATUS_FW_CTRL_reg);
		if((vby1_status_fw_ctrl_reg.hw_lockn==1)&&(vby1_status_fw_ctrl_reg.hw_htpdn==0)) {
			tmp++;
		} else {
			mdelay(2);
		}
	}while((tmp<3)&&(--timeout));
	IoReg_Write32(VBY1_VBY1_STATUS_FW_CTRL_reg,0x80000000);
#endif
	vbe_disp_lane_power_on();
}

void vbe_disp_tcon_on()
{
	unsigned char data[3];
	int ret = 0;

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_tcon_on\n");

	//data[0]=0x29;
	//data[1]=0xA0;

	data[0]=0x2;
	data[1]=0x9A;
	data[2]=0x7F;
	ret = i2c_master_send_ex(3, 0x38, &data[0], 3);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_tcon_on (data=%x, %x, %x)\n", data[0], data[1], data[2]);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_tcon_on (ret=%d)\n", ret);
}

void vbe_disp_tcon_off()
{
	unsigned char data[3];
	int ret = 0;

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_tcon_off\n");

	data[0]=0x2;
	data[1]=0x9A;
	data[2]=0x70;
	ret = i2c_master_send_ex(3, 0x38, &data[0], 3);

	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_tcon_off (data=%x, %x, %x)\n", data[0], data[1], data[2]);
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_tcon_off (ret=%d)\n", ret);

}

void vbe_disp_tcon_verifyOnOff(char *bOnOff)
{
	unsigned char data[3] = {0,0,0};
	int ret = 0;
	data[0]=0xD0;
	ret = i2c_master_recv_ex(2, 0x29, &data[0], 1, &data[1], 2);
	*bOnOff = data[1];
	rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vbe_disp_tcon_verifyOnOff (ret=%d) (data=%d) \n", ret, data[1]);
}
#define VBY1_LANE_NUMBER 16
char vbe_disp_tcon_readStatus()
{
#if 0
	unsigned char data[3]={0,0,0};
	int ret = 0;
	int i=0;
//	unsigned char command=0;
	int checkStatus=0;
	unsigned char read_data[2]={0,0};
	unsigned char lane_status[VBY1_LANE_NUMBER]={0};
	unsigned char panel_type=((IoReg_Read32(MISC_GPIO_GP2DATI_VADDR)>>18)&0x1);//0xb801bd38[18]=1 OLED

#if 1  // lockn fw mode
    if((Get_DISPLAY_REFRESH_RATE() == 60)||(panel_type)){
			return 0; //normal ok
	}
#endif
//t-con checking
	for(i=0; i<VBY1_LANE_NUMBER; i++){
		data[0]=0x2;
		data[1]=0x97;
		data[2]=(unsigned char)(((0xff00)&(1 << i))>>8);
		ret =  i2c_master_send_ex(3,0x38,&data[0],3);
		if(ret<0) {
			if (IoReg_Read32(MDOMAIN_DISP_dispm_comp_decomp_dbg_mux_reg)&_BIT30) {
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"i2c_master_send_ex(0x297) return fail,break\n");
			}
			checkStatus =1392;
			break;
		}
		data[0]=0x2;
		data[1]=0x96;
		data[2]=(unsigned char)((0x00ff)&(1 << i));
		ret =  i2c_master_send_ex(3,0x38,&data[0],3);
		if(ret<0) {
			if (IoReg_Read32(MDOMAIN_DISP_dispm_comp_decomp_dbg_mux_reg)&_BIT30) {
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"i2c_master_send_ex(0x296) return fail,break\n");
			}
			checkStatus =1392;
			break;
		}
		read_data[0]=0xA;
		read_data[1]=0xA9;
		ret = i2c_master_recv_ex(3, 0x38, &read_data[0], 2, &lane_status[i], 1);
		if(ret<0) {
			if (IoReg_Read32(MDOMAIN_DISP_dispm_comp_decomp_dbg_mux_reg)&_BIT30) {
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"i2c_master_recv_ex return fail,break\n");
			}
			checkStatus =1392;
			break;
		}
		checkStatus += lane_status[i];
//		command=0;
	}
	if(checkStatus != 1392) {
		if (IoReg_Read32(MDOMAIN_DISP_dispm_comp_decomp_dbg_mux_reg)&_BIT30) {
			for(i=0; i<VBY1_LANE_NUMBER; i++)
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "lane[%d]=%x\n",i,lane_status[i]);
		}
		return 1; //reset condition
	}
	else
		return 0; //normal ok
#endif
}
#if 1  // lockn fw mode
void vbe_disp_vby1_init_flow(void)
{
	unsigned char tmp = 0;
	unsigned int timeout = 0x250;
	vby1_vby1_status_fw_ctrl_RBUS vby1_status_fw_ctrl_reg;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[VBY1] rtk_disp_vby1_init_flow \n");

	if(Get_DISPLAY_PANEL_CUSTOM_INDEX() == VBY_ONE_PANEL_innolux_4K2K_600M_1S_8L){
		//60hz panel, turn off unused lane power
		IoReg_Write32(0xB8000C74, 0x80003F30);
		IoReg_Write32(0xB8000D74, 0x80000000);
		IoReg_Write32(VBY1_VBY1_STATUS_FW_CTRL_reg,0x00000000);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[VBY1] INX panel use HW lock mode \n");
		return;
	}

	IoReg_Write32(VBY1_VBY1_STATUS_FW_CTRL_reg,0xD0000000);

	do{
		//about 1.8us
		vby1_status_fw_ctrl_reg.regValue = IoReg_Read32(VBY1_VBY1_STATUS_FW_CTRL_reg);

		if(Get_DISPLAY_PANEL_CUSTOM_INDEX() == VBY_ONE_PANEL_innolux_4K2K_600M_1S_8L){
			if((vby1_status_fw_ctrl_reg.hw_lockn==1)&&(vby1_status_fw_ctrl_reg.hw_htpdn==0)){
				tmp++;
			}else{
				tmp=0;
				msleep(10);
			}
		}else{
			if((vby1_status_fw_ctrl_reg.hw_lockn==1)&&(vby1_status_fw_ctrl_reg.hw_htpdn==0))
				tmp++;
			else
				tmp=0;
			msleep(10);
		}
	}while((tmp<3)&&(--timeout));

	if(timeout == 0)
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"polling lockn=1, hot_plug=0 FAIL!!\n");
	else
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"polling lockn=1, hot_plug=0 ok\n");

	///IoReg_Write32(VBY1_VBY1_STATUS_FW_CTRL_reg,0x80000000);

	if((Get_DISPLAY_REFRESH_RATE() == 60) &&
		(Get_DISPLAY_PANEL_CUSTOM_INDEX() == VBY_ONE_PANEL_LG_4K2K_600M_1S_8L))
	{
		//60hz panel, turn off unused lane power
		IoReg_Write32(0xB8000C74, 0x80003F30);
		IoReg_Write32(0xB8000D74, 0x80000000);
	}else{
		IoReg_Write32(0xB8000C74, 0x80003F30);
		IoReg_Write32(0xB8000D74, 0x8000033F);
	}

	tmp=0;
	timeout = 0x25000;
	do{
		//about 1.8us
		vby1_status_fw_ctrl_reg.regValue = IoReg_Read32(VBY1_VBY1_STATUS_FW_CTRL_reg);
		if((vby1_status_fw_ctrl_reg.hw_lockn==0)&&(vby1_status_fw_ctrl_reg.hw_htpdn==0))
			tmp++;
		else
			tmp=0;
	}while((tmp<3)&&(--timeout));

	if(timeout == 0){
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"polling lockn=0, hot_plug=0 FAIL!!\n");
		rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"vby1_status_fw_ctrl_reg(%x)(tmp:%d)\n", vby1_status_fw_ctrl_reg.regValue, tmp);
	}
	else{
		IoReg_Write32(VBY1_VBY1_STATUS_FW_CTRL_reg,0xC3000000);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"[VBY1]rtk_disp_vby1_init_flow OK \n");
	}
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"########## 0xB802D754(%x)\n", IoReg_Read32(0xB802D754));

}
#endif

unsigned char vbe_disp_tcon_lock_self_check()
{
#if 0
#if 1  // lockn fw mode
	unsigned char result=1;
	//unsigned char panel_type=((IoReg_Read32(MISC_GPIO_GP2DATI_VADDR)>>18)&0x1);//0xb801bd38[18]=1 OLED
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"0xb801bd38:%x,panel_type=%d\n",IoReg_Read32(MISC_GPIO_GP2DATI_VADDR),panel_type);
	//if (!panel_type)
	{
		if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K)
		{
			unsigned char tcon_fail_count=0;
			unsigned char lockn_result=0;
			while(tcon_fail_count<2) {
				lockn_result=vbe_disp_vby1_lockn_check();
				if(lockn_result==1)//lockn ok
				{ //0: lock N = high 1: lock N = low
					if(vbe_disp_tcon_readStatus() != 0)
					{// reset condition 1: reset 0: not
						//reset by soc lane power down and up
						tcon_fail_count++;
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check fail=%d\n",tcon_fail_count);
						//lane_power_reset();
						vbe_disp_lane_power_off();
						vbe_disp_vby1_init_flow();
						result=0;//fail
					} else {
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check ok\n");
						result=1;//ok
						break;
					}
				}
				else  //lockn high timeout
				{
					result=0; //fail
					tcon_fail_count++;
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"lockn always high,fail=%d\n",tcon_fail_count);
					//lane_power_reset();
					vbe_disp_lane_power_off();
					vbe_disp_vby1_init_flow();
				}
			}
		}
	}
	return result;
#else
	unsigned char result=1;
	unsigned char panel_type=((IoReg_Read32(MISC_GPIO_GP2DATI_VADDR)>>18)&0x1);//0xb801bd38[18]=1 OLED
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"0xb801bd38:%x,panel_type=%d\n",IoReg_Read32(MISC_GPIO_GP2DATI_VADDR),panel_type);
	if (!panel_type) {//LCD panel
		if(Get_DISPLAY_REFRESH_RATE() == 120)
		{
			unsigned char tcon_fail_count=0;
			unsigned char lockn_result=0;
			while(tcon_fail_count<2) {
				lockn_result=vbe_disp_vby1_lockn_check();
				if(lockn_result==1)//lockn ok
				{ //0: lock N = high 1: lock N = low
					if(vbe_disp_tcon_readStatus() != 0)
					{// reset condition 1: reset 0: not
						//reset by soc lane power down and up
						tcon_fail_count++;
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check fail=%d\n",tcon_fail_count);
						lane_power_reset();
						result=0;//fail
					} else {
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check ok\n");
						result=1;//ok
						break;
					}
				}
				else  //lockn high timeout
				{
					result=0; //fail
					tcon_fail_count++;
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"lockn always high,fail=%d\n",tcon_fail_count);
					lane_power_reset();
				}
			}
		}
		else
		{
			result=1;
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"**********not 120 panel don't do check********\n");
		}
	}
	return result;
#endif
#endif
}

unsigned char vbe_disp_always_check_tcon(void)
{
#if 0
#if 1  // lockn fw mode
	unsigned char result=1;
	//unsigned char panel_type=((IoReg_Read32(MISC_GPIO_GP2DATI_VADDR)>>18)&0x1);//0xb801bd38[18]=1 OLED
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"0xb801bd38:%x,panel_type=%d\n",IoReg_Read32(MISC_GPIO_GP2DATI_VADDR),panel_type);
	//if (!panel_type)
	{
		if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K)
		{
			unsigned char lockn_result=0;
			lockn_result=vbe_disp_vby1_lockn_check();
			if(lockn_result==1)//lockn ok
			{ //0: lock N = high 1: lock N = low
				if(vbe_disp_tcon_readStatus() != 0)
				{// reset condition 1: reset 0: not
					//reset by soc lane power down and up
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check fail\n");
					//lane_power_reset();
					vbe_disp_lane_power_off();
					vbe_disp_vby1_init_flow();
					result=0;//fail
				} else {
					if(IoReg_Read32(MDOMAIN_DISP_dispm_comp_decomp_dbg_mux_reg)&_BIT30)
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check ok\n");
					result=1;//ok
				}
			}
			else  //lockn high timeout
			{
				result=0; //fail
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"lockn always high,fail\n");
				//lane_power_reset();
				vbe_disp_lane_power_off();
				vbe_disp_vby1_init_flow();
			}
		}
	}
	return result;
#else
	unsigned char result=1;
	unsigned char panel_type=((IoReg_Read32(MISC_GPIO_GP2DATI_VADDR)>>18)&0x1);//0xb801bd38[18]=1 OLED
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"0xb801bd38:%x,panel_type=%d\n",IoReg_Read32(MISC_GPIO_GP2DATI_VADDR),panel_type);
	if (!panel_type) {//LCD panel
		if(Get_DISPLAY_REFRESH_RATE() == 120)
		{
			unsigned char lockn_result=0;
			lockn_result=vbe_disp_vby1_lockn_check();
			if(lockn_result==1)//lockn ok
			{ //0: lock N = high 1: lock N = low
				if(vbe_disp_tcon_readStatus() != 0)
				{// reset condition 1: reset 0: not
					//reset by soc lane power down and up
					rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check fail\n");
					lane_power_reset();
					result=0;//fail
				} else {
					if(IoReg_Read32(MDOMAIN_DISP_dispm_comp_decomp_dbg_mux_reg)&_BIT30)
						rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"tcon check ok\n");
					result=1;//ok
				}
			}
			else  //lockn high timeout
			{
				result=0; //fail
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"lockn always high,fail\n");
				lane_power_reset();
			}
		}
		else
		{
			result=1;
			//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"**********not 120 panel don't do check********\n");
		}
	}
	return result;
#endif
#endif
}
#endif

int vbe_open(struct inode *inode, struct file *filp) {
	return 0;	/* success */
}

ssize_t  vbe_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
	return 0;

}

ssize_t vbe_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

int vbe_release(struct inode *inode, struct file *filep)
{
	return 0;
}


long vbe_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{
	int retval = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "VBE: vbe_ioctl, %x;;agr:%x\n", _IOC_NR(cmd), arg);
	if (_IOC_TYPE(cmd) != VBE_IOC_MAGIC || _IOC_NR(cmd) > VBE_IOC_MAXNR) return -ENOTTY ;

	switch (cmd)
	{
		case VBE_IOC_DISP_INITIALIZE:
		{
			DISP_PANEL_INFO_T panel_info;
			if(copy_from_user((void *)&panel_info, (const void __user *)arg, sizeof(DISP_PANEL_INFO_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_INITIALIZE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VBE_DISP_Initialize(panel_info)==0)
				{
					retval = -EFAULT;
				}
			}
			break;
		}
		case VBE_IOC_DISP_UNINITIALIZE:
		{
			if(HAL_VBE_DISP_Uninitialize()==0)
			{
				retval = -EFAULT;
			}
			break;
		}
		case VBE_IOC_DISP_RESUME:
		{
			DISP_PANEL_INFO_T panel_info;
			if(copy_from_user((void *)&panel_info, (const void __user *)arg, sizeof(DISP_PANEL_INFO_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_RESUME failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VBE_DISP_Resume(panel_info)==0)
				{
					retval = -EFAULT;
				}
			}
			break;
		}
		case VBE_IOC_DISP_CONNECT:
		{
			DISP_WINDOW_T disp_window;
			if(copy_from_user((void *)&disp_window, (const void __user *)arg, sizeof(DISP_WINDOW_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_CONNECT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_Connect(disp_window);
			}
			break;
		}
		case VBE_IOC_DISP_DISCONNECT:
		{
			DISP_WINDOW_T disp_window;
			if(copy_from_user((void *)&disp_window, (const void __user *)arg, sizeof(DISP_WINDOW_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_DISCONNECT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_Disconnect(disp_window);
			}
			break;
		}
		case VBE_IOC_DISP_WRITE_DIAPLAYOUTPUT:
		{
			BOOLEAN length;
			if(copy_from_user((void *)&length, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_DIAPLAYOUTPUT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetDisplayOutput(length);
			}
			break;
		}
		case VBE_IOC_DISP_WRITE_MUTE:
		{
			BOOLEAN length;
			if(copy_from_user((void *)&length, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_MUTE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetMute(length);
			}
			break;
		}
		case VBE_IOC_DISP_WRITE_SPREADSPECTRUM:
		{
			VBE_DISP_SpreadSpectrum_T spreadspectrum;
			if(copy_from_user((void *)&spreadspectrum, (const void __user *)arg, sizeof(VBE_DISP_SpreadSpectrum_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_SPREADSPECTRUM failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetSpreadSpectrum(spreadspectrum.bEnable,spreadspectrum.Percenct,spreadspectrum.Period);
			}
			break;
		}
		case VBE_IOC_DISP_WRITE_VIDEO_MIRROR:
		{
			VBE_DISP_VideoMirror_T mirror_enable;
			if(copy_from_user((void *)&mirror_enable, (const void __user *)arg, sizeof(VBE_DISP_VideoMirror_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_VIDEO_MIRROR failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VBE_DISP_SetVideoMirror(mirror_enable.bIsH,mirror_enable.bIsV)==FALSE)
				{
					retval = -EFAULT;
				}
			}
			break;
		}
		case VBE_IOC_DISP_WRITE_DISPLAY_FORMAT:
		{
			VBE_DISP_FORMAT_T panel_info;
			if(copy_from_user((void *)&panel_info, (const void __user *)arg, sizeof(VBE_DISP_FORMAT_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_DISPLAY_FORMAT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetDisplayFormat(&(panel_info.panel_attribute),panel_info.framerate);
			}
			break;
		}
		case VBE_IOC_DISP_WRITE_FRAMERATE:
		{
			VBE_DISP_Framerate_T framerate_info;
			if(copy_from_user((void *)&framerate_info, (const void __user *)arg, sizeof(VBE_DISP_Framerate_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_FRAMERATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetFrameRate(framerate_info.isForceFreeRun,framerate_info.framerate);
			}
			break;
		}
		case VBE_IOC_DISP_READ_OUTPUTFRAMERATE:
		{
			UINT8 framerate=0;
			HAL_VBE_DISP_GetOutputFrameRate(&framerate);
			if(copy_to_user((void __user *)arg, (void *)&framerate, sizeof(UINT8)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_READ_OUTPUTFRAMERATE failed!!!!!!!!!!!!!!!\n");
			}
			break;
		}
		case VBE_IOC_DISP_WRITE_BGCOLOR:
		{
			VBE_DISP_BGColor_T color;
			if(copy_from_user((void *)&color, (const void __user *)arg, sizeof(VBE_DISP_BGColor_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_BGCOLOR failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetBackgroundColor(color.red,color.green,color.blue);
			}
			break;
		}

		case VBE_IOC_DISP_OD_WRITE_TABLE:
		{
			extern unsigned char od_table_tv006_store[OD_table_length];

			enum PLAFTORM_TYPE platform = get_platform();
			if (PLATFORM_KXLP != platform)
				return -1;

			if (copy_from_user(od_table_tv006_store, (void __user *)arg, sizeof(unsigned char)*OD_table_length))
			{
		 		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_OD_WRITE_TABLE fail\n");
				retval = -1;
			}
			else
			{


				extern unsigned char bODInited;
				extern unsigned char bODTableLoaded;
				extern char od_table_mode_store;
				extern unsigned int od_table_store[OD_table_length];
				extern unsigned int od_delta_table[OD_table_length];
				fwif_color_od_table_tv006_convert(od_table_tv006_store, od_table_store);

				fwif_color_od_table_tv006_transform(0, od_table_store, od_delta_table);

				drvif_color_od_table(od_delta_table, 0);// 0:delta mode 1:target mode(output mode)
				od_table_mode_store = 1;// 0:target mode 1:delta mode -1:inverse mode
				bODTableLoaded = TRUE;
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_OD_WRITE_TABLE success\n");
			 	retval = 0;

			}
			break;
		}
		case VBE_IOC_DISP_OD_ENABLE:
		{
			unsigned int tmp;
			if (copy_from_user(&tmp, (unsigned char __user *)arg, sizeof(tmp)))
			{
		 		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_OD_ENABLE fail\n");
				retval = -1;
			}
			else
			{
				extern unsigned char bODInited;
				extern unsigned char bODTableLoaded;
				extern unsigned char bODPreEnable;

				enum PLAFTORM_TYPE platform = get_platform();
				if (PLATFORM_KXLP != platform)
					return -1;

				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_OD_ENABLE = %d\n",tmp);
				bODPreEnable = tmp;
				if (!bODInited || !bODTableLoaded)
					return -1;
				fwif_color_set_od(tmp);
				retval = 0;
			}
			break;
		}

		case VBE_IOC_DISP_PCID_WRITE_TABLE:
		{
#ifdef SCALER_PCID_ENABLE
#if SCALER_PCID_ENABLE
			unsigned char PCIDtable[OD_table_length];
			if (copy_from_user(&PCIDtable[0], (unsigned char __user *)arg, sizeof(unsigned char)*OD_table_length))
			{
		 		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_PCID_WRITE_TABLE fail\n");
				retval = -1;
			}
			else
			{
				drvif_color_pcid_table(PCIDtable);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_PCID_WRITE_TABLE success\n");
			 	retval = 0;
			}
#endif
#endif
			break;

		}
		case VBE_IOC_DISP_PCID_ENABLE:
		{
#ifdef SCALER_PCID_ENABLE
#if SCALER_PCID_ENABLE
			unsigned int tmp;
			if (copy_from_user(&tmp, (unsigned char __user *)arg, sizeof(tmp)))
			{
		 		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_PCID_ENABLE fail\n");
				retval = -1;
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_PCID_ENABLE = %d\n",tmp);
				drvif_color_pcid(tmp);
				retval = 0;
			}
#endif
#endif
			break;
		}

		case VBE_IOC_DISP_SR_INITIALIZE:
		{
			break;
		}
		case VBE_IOC_DISP_SR_UNINITIALIZE:
		{
			break;
		}
		case VBE_IOC_DISP_SR_WRITE_CONTROL:
		{
			break;
		}
		case VBE_IOC_DISP_TCON_INITILIZE:
		{
			HAL_VBE_DISP_TCON_Initialize();
			break;
		}
		case VBE_IOC_DISP_TCON_UNINITILIZE:
		{
			HAL_VBE_DISP_TCON_Uninitialize();
			break;
		}
		case VBE_IOC_DISP_TCON_ENABLE_TCON:
		{
			BOOLEAN enable;
			if(copy_from_user((void *)&enable, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_TCON_ENABLE_TCON failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_TCON_EnableTCon(enable);
			}
			break;
		}
		case VBE_IOC_DISP_TCON_EABLE_COLORTEMP:
		{
			break;
		}
		case VBE_IOC_DISP_TCON_EABLE_DGA:
		{
			break;
		}
		case VBE_IOC_DISP_TCON_ENABLE_DITHER:
		{
			//unsigned int* tmp = (unsigned int*)arg;
			unsigned int tmp;
			if (copy_from_user(&tmp, (unsigned char __user *)arg, sizeof(tmp)))
			{
		 		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_TCON_ENABLE_DITHER fail\n");
				retval = -1;
			}
			else
			{
	 			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_TCON_ENABLE_DITHER = %d\n",tmp);
				HAL_VBE_DISP_TCON_EnableDither(tmp);
				rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_TCON_ENABLE_DITHER success\n");
				retval = 0;
			}

			break;
		}
		case VBE_IOC_DISP_TCON_SET_DITHER_MODE:
		{
			//unsigned int* tmp = (unsigned int*)arg;
			unsigned int tmp;
                        if (copy_from_user(&tmp, (unsigned char __user *)arg, sizeof(tmp)))
                        {
                                rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_TCON_SET_DITHER_MODE fail\n");
                                retval = -1;
                        }
                        else
                        {
	 			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_TCON_SET_DITHER_MODE = %d\n",tmp);
	 			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"kernel VBE_IOC_DISP_TCON_SET_DITHER_MODE = %d\n",tmp);
				HAL_VBE_DISP_TCON_SetDitherMode((DISP_TCON_DITHER_T)tmp);
				retval = 0;
			}
			break;
		}
		case VBE_IOC_DISP_TCON_SET_GAMMA_TABLE:
		{
			break;
		}
		case VBE_IOC_DISP_TCON_H_REVERSE:
		{
			UINT32 h_rev_mode;
			if(copy_from_user((void *)&h_rev_mode, (const void __user *)arg, sizeof(UINT32)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_TCON_H_REVERSE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{

				HAL_VBE_DISP_TCON_H_Reverse(h_rev_mode);
			}
			break;
		}
		case VBE_IOC_DISP_TCON_SET_CLOCK:
		{
			UINT8 bOnOff;
			if(copy_from_user((void *)&bOnOff, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_TCON_SET_CLOCK failed!!!!!!!!!!!!!!!\n");
			}
			else
			{

				HAL_VBE_DISP_TCON_SetClock(bOnOff);
			}
			break;
		}
		case VBE_IOC_DISP_TCON_WRITE_REGISTER:
		{

			HAL_VBE_DISP_TCON_WRITE_REGISTERS disp_tcon_write_reg_info;
			if(copy_from_user((void *)&disp_tcon_write_reg_info, (const void __user *)arg, sizeof(HAL_VBE_DISP_TCON_WRITE_REGISTERS)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_TCON_WRITE_REGISTER failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_TCON_WriteRegister(disp_tcon_write_reg_info.reg_address, disp_tcon_write_reg_info.reg_data);
			}
			break;
		}
		case VBE_IOC_DISP_TCON_READ_REGISTER:
		{
			HAL_VBE_DISP_TCON_READ_REGISTERS disp_tcon_read_reg_info;
			if(copy_from_user((void *)&disp_tcon_read_reg_info, (const void __user *)arg, sizeof(HAL_VBE_DISP_TCON_READ_REGISTERS)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_TCON_READ_REGISTER failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_TCON_ReadRegister(disp_tcon_read_reg_info.reg_address, disp_tcon_read_reg_info.reg_data);
			}
			break;
		}
		case VBE_IOC_DISP_TCON_SET_LVDS_FORMAT:
		{
			HAL_VBE_DISP_TCON_LVDS_TYPE_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(HAL_VBE_DISP_TCON_LVDS_TYPE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_FRAMERATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_TCON_SetLvdsFormat(type);
			}
			break;
		}
		case VBE_IOC_DISP_TCON_DEBUG:
		{
			HAL_VBE_DISP_TCON_Debug();
			break;
		}

		case VBE_IOC_AVE_INITILIZE:
		{
			HAL_VBE_AVE_Initialize();
			break;
		}
		case VBE_IOC_AVE_UNINITILIZE:
		{
			HAL_VBE_AVE_Uninitialize();
			break;
		}
		case VBE_IOC_AVE_OPEN:
		{
			HAL_VBE_AVE_Open();
			break;
		}
		case VBE_IOC_AVE_CLOSE:
		{
			HAL_VBE_AVE_Close();
			break;
		}
		case VBE_IOC_AVE_CONNECT:
		{
			VBE_AVE_INPUT_INDEX AVEInput;
			if(copy_from_user((void *)&AVEInput, (const void __user *)arg, sizeof(VBE_AVE_INPUT_INDEX)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_WRITE_FRAMERATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_AVE_Connect(AVEInput);
			}
			break;
		}
		case VBE_IOC_AVE_DISCONNECT:
		{
			HAL_VBE_AVE_Disconnect();
			break;
		}
		case VBE_IOC_AVE_IS_ATV_WATCHING:
		{
			HAL_VBE_AVE_IsATVWatching();
			break;
		}
		case VBE_IOC_AVE_SET_ATV_WATCHING:
		{
			VBE_AVE_SET_ATVWATCHING_T set_atv_watching_info;

			if(copy_from_user((void *)&set_atv_watching_info, (const void __user *)arg, sizeof(VBE_AVE_SET_ATVWATCHING_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_AVE_SET_ATV_WATCHING failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_AVE_SetATVWatching(set_atv_watching_info.AVEInput, set_atv_watching_info.bIsATVWatching);
			}

			break;
		}
		case VBE_IOC_AVE_VBI_SET_INSERT:
		{
			VBE_AVE_VBI_SET_INSERT_T vbi_set_insert_info;
			if(copy_from_user((void *)&vbi_set_insert_info, (const void __user *)arg, sizeof(VBE_AVE_VBI_SET_INSERT_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_AVE_VBI_SET_INSERT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_AVE_VBI_SetInsert(vbi_set_insert_info.type, vbi_set_insert_info.OnOff);
			}

			break;
		}
		case VBE_IOC_AVE_VBI_INSERT_DATA:
		{
			VBE_AVE_VBI_INSERT_DATA_T vbi_insert_data_info;
			if(copy_from_user((void *)&vbi_insert_data_info, (const void __user *)arg, sizeof(VBE_AVE_VBI_INSERT_DATA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_AVE_VBI_INSERT_DATA failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_AVE_VBI_InsertData(vbi_insert_data_info.type, vbi_insert_data_info.nrLine, vbi_insert_data_info.pLines, vbi_insert_data_info.size, vbi_insert_data_info.pData);
			}
			break;
		}
		case VBE_IOC_AVE_SET_VCR_WIN_BLANK:
		{
			BOOLEAN bOnOff;
			if(copy_from_user((void *)&bOnOff, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_AVE_SET_VCR_WIN_BLANK failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_AVE_SetVCRWinBlank(bOnOff);
			}
			break;
		}
		case VBI_IOC_DISP_LVDS_TO_HDMI:
		{
			VBE_DISP_FORMAT_T panel_info;
			if(copy_from_user((void *)&panel_info, (const void __user *)arg, sizeof(VBE_DISP_FORMAT_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBI_IOC_DISP_LVDS_TO_HDMI failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				Scaler_set_lvds_to_hdmi_parameter(&(panel_info.panel_attribute),panel_info.framerate);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_INITIALIZE:
		{
			HAL_VBE_TRIDFMT_Initialize();
			break;
		}
		case VBE_IOC_TRIDFMT_UNINITIALIZE:
		{
			HAL_VBE_TRIDFMT_Uninitialize();
			break;
		}
		case VBE_IOC_TRIDFMT_OPEN:
		{
			HAL_VBE_TRIDFMT_Open();
			break;
		}
		case VBE_IOC_TRIDFMT_CLOSE:
		{
			HAL_VBE_TRIDFMT_Close();
			break;
		}
		case VBE_IOC_TRIDFMT_SETSCREENONOFF:
		{
			BOOLEAN enable;
			if(copy_from_user((void *)&enable, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SETSCREENONOFF failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SetScreenOnOff(enable);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SETFMTMODE:
		{
			VBE_TRIDFMT_FMT_MODE_T fmtMode;
			if(copy_from_user((void *)&fmtMode, (const void __user *)arg, sizeof(VBE_TRIDFMT_FMT_MODE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SETFMTMODE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SetFMTMode(fmtMode.wId, fmtMode.TriFRC);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SETFMTMODE_TEMP:
		{
			VBE_TRIDFMT_FMT_MODE_TEMP_T fmtMode;
			if(copy_from_user((void *)&fmtMode, (const void __user *)arg, sizeof(VBE_TRIDFMT_FMT_MODE_TEMP_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SETFMTMODE_TEMP failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SetFMTMode_TEMP(fmtMode.wId, fmtMode.TriFRC);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SET3DMODEONOFF:
		{
			HAL_TRIDTV_INPUT_CONFIG_INFO_T cfgInfo;
			if(copy_from_user((void *)&cfgInfo, (const void __user *)arg, sizeof(HAL_TRIDTV_INPUT_CONFIG_INFO_T )))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SET3DMODEONOFF failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_Set3DModeOnOff(&cfgInfo);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_TOGGLEINPUTLRFRAME:
		{
			HAL_TRIDTV_INPUT_LR_SEQ_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(HAL_TRIDTV_INPUT_LR_SEQ_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_TOGGLEINPUTLRFRAME failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_ToggleInputLRFrame(type);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SELECTINPUTFORMAT:
		{
			HAL_TRIDTV_INPUT_TYPE_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(HAL_TRIDTV_INPUT_TYPE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SELECTINPUTFORMAT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SelectInputFormat(type);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SETINPUTFRAMERATE:
		{
			HAL_TRIDTV_INPUT_FREQ_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(HAL_TRIDTV_INPUT_FREQ_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SETINPUTFRAMERATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SetInputFrameRate(type);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_TOGGLEOUTPUTLRFRAME:
		{
			HAL_TRIDTV_OUTPUT_LR_SEQ_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(HAL_TRIDTV_OUTPUT_LR_SEQ_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_TOGGLEOUTPUTLRFRAME failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_ToggleOutputLRFrame(type);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SELECTOUTPUTFORMAT:
		{
			HAL_TRIDTV_OUTPUT_TYPE_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(HAL_TRIDTV_OUTPUT_TYPE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SELECTOUTPUTFORMAT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SelectOutputFormat(type);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SETOUTPUTFRAMERATE:
		{
			HAL_TRIDTV_OUTPUT_FREQ_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(HAL_TRIDTV_OUTPUT_FREQ_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SETOUTPUTFRAMERATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SetOutputFrameRate(type);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_GET3DCFGINFO:
		{
			VBE_TRIDFMT_3D_CFG_INFO_T modeInfo;
			if(copy_from_user((void *)&modeInfo, (const void __user *)arg, sizeof(VBE_TRIDFMT_3D_CFG_INFO_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_GET3DCFGINFO failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_Get3DCfgInfo(modeInfo.n3DCfgItems, modeInfo.nCurCfgInfo);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SET3DCFGINFO:
		{
			HAL_TRIDTV_INPUT_CONFIG_INFO_T *p3DModeInfo;
			if(copy_from_user((void *)&p3DModeInfo, (const void __user *)arg, sizeof(HAL_TRIDTV_INPUT_CONFIG_INFO_T *)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SET3DCFGINFO failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_Set3DCfgInfo(p3DModeInfo);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SETCONVVALUE:
		{
			char convVal;
			if(copy_from_user((void *)&convVal, (const void __user *)arg, sizeof(char)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SETCONVVALUE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_SetConvValue(convVal);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_CTRLDEPTH:
		{
			VBE_TRIDFMT_CTRL_DEPTH_T depthInfo;
			if(copy_from_user((void *)&depthInfo, (const void __user *)arg, sizeof(VBE_TRIDFMT_CTRL_DEPTH_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_CTRLDEPTH failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_CtrlDepth(depthInfo.n3Dmode, depthInfo.u8DepthLevel);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_AUTOCONVERGENCEENABLE:
		{
			BOOLEAN enable;
			if(copy_from_user((void *)&enable, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_AUTOCONVERGENCEENABLE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_AutoConvergenceEnable(enable);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SET3DVIDEOOUTPUTMODE:
		{
			UINT32 bIsSGMode;
			if(copy_from_user((void *)&bIsSGMode, (const void __user *)arg, sizeof(UINT32)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SET3DVIDEOOUTPUTMODE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_Set3DVideoOutputMode(bIsSGMode);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_SET3DDEPTHCONTROLLER:
		{
			UINT32 bOnOff;
			if(copy_from_user((void *)&bOnOff, (const void __user *)arg, sizeof(UINT32)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_TRIDFMT_SET3DDEPTHCONTROLLER failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_TRIDFMT_Set3DDepthController(bOnOff);
			}
			break;
		}
		case VBE_IOC_TRIDFMT_DEBUG:
		{
			HAL_VBE_TRIDFMT_Debug();
			break;
		}
		case VBE_IOC_SETORBIT:
		{
			BOOLEAN enable;
			if(copy_from_user((void *)&enable, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETORBIT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_OLED_SetOrbit(enable);
			}
			break;
		}
		case VBE_IOC_SETBOEMODE:
		{
			UINT32 data_len;
			unsigned char	*m_pCacheStartAddr = NULL;

			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"VBE_IOC_SETBOEMODE\n");

			if(copy_from_user((void *)&data_len, (const void __user *)arg, sizeof(UINT32)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETORBIT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "data_len=%d\n", data_len);
				m_pCacheStartAddr = (unsigned char *)dvr_malloc(data_len);
				if(m_pCacheStartAddr == NULL){
					rtd_printk(KERN_ERR, TAG_NAME_VBE, "[ERROR]VBE_IOC_SETBOEMODE Allocate data_len=%x fail\n",data_len);
					return FALSE;
				}

				if(copy_from_user((void *)m_pCacheStartAddr, (const void __user *)(arg+sizeof(UINT32)), data_len))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETORBIT failed!!!!!!!!!!!!!!!\n");
				}
				HAL_VBE_DISP_SetBOEMode(m_pCacheStartAddr, data_len);

				if(m_pCacheStartAddr){
					dvr_free((void *)m_pCacheStartAddr);
				}
			}

			break;
		}
		case VBE_IOC_GETBOEVERSION:
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"VBE_IOC_GETBOEVERSION\n");
			VBE_DISP_BOE_VERSION_T vbeDispBoeVer;
			DISP_BOE_VERSION_T stRomVer;
			DISP_BOE_VERSION_T stFwVer;

			HAL_VBE_DISP_GetBOEVersion(&stRomVer, &stFwVer);

			//rtd_printk(KERN_EMERG, TAG_NAME_VBE,"stRomVer(%d.%d.%d), stFwVer(%d.%d.%d)\n",
				//stRomVer.b0, stRomVer.b1, stRomVer.b2, stFwVer.b0, stFwVer.b1, stFwVer.b2);

			memcpy((UINT8*)&(vbeDispBoeVer.stRomVer), (UINT8*)&stRomVer, sizeof(DISP_BOE_VERSION_T));
			memcpy((UINT8*)&(vbeDispBoeVer.stFwVer), (UINT8*)&stFwVer, sizeof(DISP_BOE_VERSION_T));

			if(copy_to_user((void __user *)arg, (void *)&vbeDispBoeVer, sizeof(VBE_DISP_BOE_VERSION_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_GETBOEVERSION failed!!!!!!!!!!!!!!!\n");
			}

			break;
		}
		case VBE_IOC_SETMLEMODE:
		{
			VBE_DISP_MLE_MODE_T index;

			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"VBE_IOC_SETMLEMODE\n");

			if(copy_from_user((void *)&index, (const void __user *)arg, sizeof(VBE_DISP_MLE_MODE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code = VBE_IOC_SETMLEMODE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetMLEMode(index);
			}
			break;
		}
		case VBE_IOC_SETINNERPATTERN:
		{
 			VBE_DISP_INNER_PATTERN_CTRL_T dispInnerPtgCtrl;

			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"VBE_IOC_SETINNERPATTERN\n");

			if(copy_from_user((void *)&dispInnerPtgCtrl, (const void __user *)arg, sizeof(VBE_DISP_INNER_PATTERN_CTRL_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code = VBE_IOC_SETINNERPATTERN failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetInnerPattern(dispInnerPtgCtrl.bOnOff, dispInnerPtgCtrl.block, dispInnerPtgCtrl.type);
			}
			break;

		}

		case VBE_IOC_SETBOERGBWBYPASS:
		{
			BOOLEAN enable;
			if(copy_from_user((void *)&enable, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETBOERGBWBYPASS failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetBOERGBWBypass(enable);
			}
			break;
		}

		case VBE_IOC_SETDGA4CH:
		{
			UINT16 table_size;
			unsigned char	*m_pCacheStartAddr = NULL;

			rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"VBE_IOC_SETDGA4CH\n");

			if(copy_from_user((void *)&table_size, (const void __user *)arg, sizeof(UINT16)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETDGA4CH failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "table_size=%d\n", table_size);
				m_pCacheStartAddr = (unsigned char *)dvr_malloc(4*table_size*sizeof(UINT32));
				if(m_pCacheStartAddr == NULL){
					rtd_printk(KERN_ERR, TAG_NAME_VBE, "[ERROR]VBE_IOC_SETDGA4CH Allocate table_size=%x fail\n",table_size);
					return FALSE;
				}

				if(copy_from_user((void *)m_pCacheStartAddr, (const void __user *)(arg+sizeof(UINT16)), 4*table_size*sizeof(UINT32)))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETDGA4CH failed!!!!!!!!!!!!!!!\n");
				}
				HAL_VBE_SetDGA4CH(m_pCacheStartAddr, (m_pCacheStartAddr+table_size*sizeof(UINT32)), (m_pCacheStartAddr+2*table_size*sizeof(UINT32)),
					(m_pCacheStartAddr+3*table_size*sizeof(UINT32)), table_size);

				if(m_pCacheStartAddr){
					dvr_free((void *)m_pCacheStartAddr);
				}
			}

			break;
		}
		case VBE_IOC_SETFRAMEGAINLIMIT:
		{
			unsigned short nFrameGainLimit = 0;
			if(copy_from_user((void *)&nFrameGainLimit, (const void __user *)arg, sizeof(unsigned short)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETFRAMEGAINLIMIT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetFrameGainLimit(nFrameGainLimit);
			}
			break;
		}

		case VBE_IOC_GETFRAMEGAINLIMIT:
		{
			unsigned short nFrameGainLimit=0;
			HAL_VBE_DISP_GetFrameGainLimit(&nFrameGainLimit);
			if(copy_to_user((void __user *)arg, (void *)&nFrameGainLimit, sizeof(unsigned short)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_GETFRAMEGAINLIMIT failed!!!!!!!!!!!!!!!\n");
			}
			break;
		}
		case VBE_IOC_SETPIXELGAINLIMIT:
		{
			unsigned short nPixelGainLimit = 0;
			if(copy_from_user((void *)&nPixelGainLimit, (const void __user *)arg, sizeof(unsigned short)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SETPIXELGAINLIMIT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_VBE_DISP_SetPixelGainLimit(nPixelGainLimit);
			}
			break;
		}
		case VBE_IOC_GETPIXELGAINLIMIT:
		{
			unsigned short nPixelGainLimit=0;
			HAL_VBE_DISP_GetPixelGainLimit(&nPixelGainLimit);
			if(copy_to_user((void __user *)arg, (void *)&nPixelGainLimit, sizeof(unsigned short)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_GETPIXELGAINLIMIT failed!!!!!!!!!!!!!!!\n");
			}
			break;
		}
		case VBE_IOC_GETPANELDISPSIZE:
		{
			DISP_PANEL_SIZE_T panel_size;

			//printk(KERN_EMERG"VBE_IOC_GETPANELDISPSIZE \n");

			HAL_VBE_DISP_GetPanelSize(&panel_size);
			if(copy_to_user((void __user *)arg, (void *)&panel_size, sizeof(DISP_PANEL_SIZE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_GETPANELDISPSIZE failed!!!!!!!!!!!!!!!\n");
			}
			break;
		}

		case V3D_IOC_INITIALIZE:
		{
			HAL_V3D_Initialize();
			break;
		}
		case V3D_IOC_SET3DFMT:
		{
			V3D_Set3DFMT_T v3d_set3dfmt_param;
			if(copy_from_user((void *)&v3d_set3dfmt_param, (const void __user *)arg, sizeof(V3D_Set3DFMT_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=V3D_IOC_SET3DFMT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_V3D_Set3DFMT(v3d_set3dfmt_param.wid, v3d_set3dfmt_param.in_fmt, v3d_set3dfmt_param.out_fmt);
			}
			break;
		}
		case V3D_IOC_SETLRSEQ:
		{
			V3D_LR_SEQ_T type;
			if(copy_from_user((void *)&type, (const void __user *)arg, sizeof(V3D_LR_SEQ_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=V3D_IOC_SETLRSEQ failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_V3D_SetLRSeq(type);
			}
			break;
		}
		case V3D_IOC_CTRLCONVERGENCE:
		{
			INT8 s8ConvValue;
			if(copy_from_user((void *)&s8ConvValue, (const void __user *)arg, sizeof(INT8)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=V3D_IOC_CTRLCONVERGENCE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_V3D_CtrlConvergence(s8ConvValue);
			}
			break;
		}
		case V3D_IOC_CTRLDEPTH:
		{
			UINT8 u8DepthLevel;
			if(copy_from_user((void *)&u8DepthLevel, (const void __user *)arg, sizeof(UINT8)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=V3D_IOC_CTRLDEPTH failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_V3D_CtrlDepth(u8DepthLevel);
			}
			break;
		}
		case V3D_IOC_SETAUTOCONVENABLE:
		{
			BOOLEAN bOnOff;
			if(copy_from_user((void *)&bOnOff, (const void __user *)arg, sizeof(BOOLEAN)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=V3D_IOC_SETAUTOCONVENABLE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_V3D_SetAutoConvEnable(bOnOff);
			}
			break;
		}
		case V3D_IOC_GETAUTODETECTINGRESULT:
		{
			V3D_FMT_TYPE_T pVideo3Dtype;
			if(copy_from_user((void *)&pVideo3Dtype, (const void __user *)arg, sizeof(V3D_FMT_TYPE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=V3D_IOC_GETAUTODETECTINGRESULT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_V3D_GetAutoDetectingResult(&pVideo3Dtype);
			}
			break;
		}
		case V3D_IOC_SETAUTODETECTINGTYPE:
		{
			V3D_FORMAT_TYPE_T mode;
			if(copy_from_user((void *)&mode, (const void __user *)arg, sizeof(V3D_FORMAT_TYPE_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=V3D_IOC_SETAUTODETECTINGTYPE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				HAL_V3D_SetAutoDetectingType(mode);
			}
			break;
		}
		case VBE_IOC_PANEL_MODE_SET:
		{
			KADP_PANEL_MODE_SET_T panel_set;

			if(copy_from_user((void *)&panel_set, (const void __user *)arg, sizeof(KADP_PANEL_MODE_SET_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE, "scaler vbe ioctl code=VBE_IOC_PANEL_POWER_ONOFF failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"panel_set.ctrl_set = %d, enable = %d \n", panel_set.ctrl_set, panel_set.power_enable);
				if (panel_set.ctrl_set == KADP_DISP_PANEL_STR_BACKLIGHT_CTRL_BY_AP) {
					Panel_Set_STR_BackLight_Ctrl_Mode(panel_set.power_enable);
				}
			}
			break;
		}
        case VBE_IOC_SET_FORCEBG_COLOR:
		{
			FORCEBG_COLOR_CTRL_TYPE bgcolortype;
			if(copy_from_user((void *)&bgcolortype, (const void __user *)arg, sizeof(FORCEBG_COLOR_CTRL_TYPE))) {
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SET_FORCEBG_COLOR failed!!!!!!!!!!!!!!!\n");
			} else {
				drvif_scalerdisplay_set_bg_color((unsigned char )bgcolortype.wid, _DISPLAY_BG, ((bgcolortype.COLORRGB >> 16) & 0xFF) << 6 , ((bgcolortype.COLORRGB >> 8) & 0xFF) << 6 , (bgcolortype.COLORRGB  & 0xFF) << 6 );

			}
			break;
		}

		case VBE_IOC_SET_PANEL_SFG:
		{
			unsigned char enable;
			if(copy_from_user((void *)&enable, (const void __user *)arg, sizeof(unsigned char))) {
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SET_PANEL_FG failed!!!!!!!!!!!!!!!\n");
			} else {
				Scaler_ForcePanelBg(enable);

			}
			break;
		}

		case VBE_IOC_SET_PANEL_FORCEBG_COLOR:
		{
			unsigned int panel_bg_color;
			if(copy_from_user((void *)&panel_bg_color, (const void __user *)arg, sizeof(unsigned int))) {
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SET_PANEL_FORCEBG_COLOR failed!!!!!!!!!!!!!!!\n");
			} else {
				drvif_scalerdisplay_set_panel_bg_color(((panel_bg_color >> 16) & 0xFF) << 2 , ((panel_bg_color >> 8) & 0xFF) << 2 , (panel_bg_color  & 0xFF) << 2 );
			}
			break;
		}

		case VBE_IOC_SET_PANEL_TI_MODE:
		{
			unsigned char table;
			if(copy_from_user((void *)&table, (const void __user *)arg, sizeof(unsigned char))) {
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SET_PANEL_TI_MODE failed!!!!!!!!!!!!!!!\n");
			} else {
				HAL_VBE_DISP_Set_Panel_Ti_Mode(table);

			}
			break;
		}
		case VBE_IOC_SET_PANEL_BIT_MODE:
		{
			unsigned char bitMode;
			if(copy_from_user((void *)&bitMode, (const void __user *)arg, sizeof(unsigned char))) {
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SET_PANEL_BIT_MODE failed!!!!!!!!!!!!!!!\n");
			} else {
				HAL_VBE_DISP_Set_Panel_Bit_Mode(bitMode);

			}
			break;
		}
		case VBE_IOC_SET_PANEL_SWAP_MODE:
		{
			unsigned char bSwap;
			if(copy_from_user((void *)&bSwap, (const void __user *)arg, sizeof(unsigned char))) {
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_SET_PANEL_SWAP_MODE failed!!!!!!!!!!!!!!!\n");
			} else {
				HAL_VBE_DISP_Set_Panel_Swap_Mode(bSwap);

			}
			break;
		}
		case VBE_IOC_DISP_READ_SPREADSPECTRUM:
		{
			VBE_DISP_SpreadSpectrum_T spreadspectrum;

			retval = HAL_VBE_DISP_GetSpreadSpectrum(&spreadspectrum);
			if (0 > retval)
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_READ_SPREADSPECTRUM failed!!!!!!!!!!!!!!!\n");

			if(copy_to_user((void __user *)arg, (void *)&spreadspectrum, sizeof(VBE_DISP_SpreadSpectrum_T))) {
				retval = -EFAULT;
				DBG_PRINT("scaler vbe ioctl code=VBE_IOC_DISP_READ_SPREADSPECTRUM failed!!!!!!!!!!!!!!!\n");
			}
			break;
		}
		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Scaler vbe disp: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
			break ;
	}
	return retval;
}

struct file_operations vbe_fops= {
	.owner =    THIS_MODULE,
	.open  =    vbe_open,
	.release =  vbe_release,
	.read  =    vbe_read,
	.write = 	vbe_write,
	.unlocked_ioctl =    vbe_ioctl,
};

#ifdef CONFIG_PM
static const struct dev_pm_ops vbe_pm_ops =
{
	.suspend    = vbe_suspend_instanboot,
	.resume_early = vbe_disp_resume,
	.resume     = vbe_resume_instanboot,
	.complete	= vbe_resume_Backlight_TurnOn,
#ifdef CONFIG_HIBERNATION
	.freeze 	= vbe_suspend,
	.thaw 		= vbe_resume,
	.poweroff 	= vbe_suspend,
	.restore 	= vbe_resume,
#endif
};
#endif // CONFIG_PM


static struct platform_device *vbe_platform_devs;

static struct platform_driver vbe_device_driver = {
	.driver =
	{
        .name         = VBE_DEVICE_NAME,
        .bus          = &platform_bus_type,
#ifdef CONFIG_PM
	 .pm         = &vbe_pm_ops,
#endif

	},
};

static char *vbe_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}
int vbe_module_init(void)
{
	int result;
	int vbe_devno;
	dev_t devno = 0;//vbe device number
	VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *config_data;
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;
	PANEL_CONFIG_PARAMETER *panel_parameter = NULL;

	result = alloc_chrdev_region(&devno, vbe_minor, vbe_nr_devs,VBE_DEVICE_NAME);
	vbe_major = MAJOR(devno);
	if (result < 0) {
		DBG_PRINT(KERN_WARNING "VBE_DEVICE: can't get major %d\n", vbe_major);
		return result;
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"VBE_DEVICE init module major number = %d\n", vbe_major);
	vbe_devno = MKDEV(vbe_major, vbe_minor);

	vbe_class = class_create(THIS_MODULE, VBE_DEVICE_NAME);

	if (IS_ERR(vbe_class))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scalevbe: can not create class...\n");
	    result=PTR_ERR(vbe_class);
		goto fail_class_create;
	}
	vbe_class->devnode = vbe_devnode;
	vbe_platform_devs = platform_device_register_simple(VBE_DEVICE_NAME, -1, NULL, 0);
    if((result=platform_driver_register(&vbe_device_driver)) != 0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"scalebfe: can not register platform driver...\n");
    	goto fail_platform_driver_register;
    }

	cdev_init(&vbe_cdev, &vbe_fops);
	vbe_cdev.owner = THIS_MODULE;
   	vbe_cdev.ops = &vbe_fops;
	result = cdev_add (&vbe_cdev, vbe_devno, 1);
	if (result)
	{
		DBG_PRINT(KERN_NOTICE "Error %d adding VBE_DEVICE!\n", result);
		goto fail_cdev_init;
	}
	device_create(vbe_class, NULL, MKDEV(vbe_major, 0), NULL,VBE_DEVICE_NAME);
	sema_init(&VBE_Semaphore, 1);
	sema_init(&VBE_RGBW_Resume_Semaphore, 1);
	panel_parameter =  (PANEL_CONFIG_PARAMETER *)&platform_info.panel_parameter;
	Panel_InitParameter(panel_parameter);
	Panel_LVDS_To_Hdmi_Converter_Parameter();
	modestate_decide_pixel_mode();
	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE), GFP_DCU1, (void**)&vir_addr_noncache);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);
	config_data = (VIDEO_RPC_VOUT_VODMA_VFLIP_ENABLE *)vir_addr_noncache;
	config_data->videoPlane = VO_VIDEO_PLANE_V1;
	config_data->enable =Get_PANEL_VFLIP_ENABLE();
#ifdef CONFIG_RTK_KDRV_RPC
	if (RPC_FAIL==send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_ConfigVodmaVFlip,phy_addr, 0, &result))
	{
		rtd_printk(KERN_INFO, TAG_NAME_VBE,"VIDEO_RPC_VOUT_ToAgent_ConfigVodmaVFlip RPC fail!!\n");
		dvr_free((void *)vir_addr);
	//	return FALSE;
	}
#endif
	dvr_free((void *)vir_addr);
	if(Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL2() ||
		Scaler_Get_FreeRun_To_FrameSync_By_HW_SpeedUp_ByMcode_HW_CTRL3()){
        if(request_irq(IRQ_MISC, vbe_timer_display_interrupt, IRQF_SHARED, "timer_dv", vbe_timer_display_interrupt)){
            printk(KERN_EMERG"[vbe_timer_display_interrupt]: can't get assigned irq%d\n", IRQ_MISC);
        }
		create_timer(7, TIMER_CLOCK/4000, COUNTER); // 25 us
		//Disable Interrupt
		rtk_timer_control(7, HWT_INT_DISABLE);
		// disable timer7
		IoReg_Write32(TIMER_TC7CR_reg, 0);
		// write 1 clear
		IoReg_Write32(TIMER_ISR_reg, TIMER_ISR_tc7_int_mask);

    }

	ppoverlay_memc_mux_ctrl_RBUS ppoverlay_memc_mux_ctrl_reg;
	ppoverlay_memc_mux_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_MEMC_MUX_CTRL_reg);
/* //fix me later by benwang
	if(ppoverlay_memc_mux_ctrl_reg.memcdtg_golden_vs == 1){
		vbe_disp_set_dynamic_memc_bypass_flag(TRUE);
	}else{
		vbe_disp_set_dynamic_memc_bypass_flag(FALSE);
	}
*/
	return 0;//Success

fail_cdev_init:
	platform_driver_unregister(&vbe_device_driver);
fail_platform_driver_register:
	platform_device_unregister(vbe_platform_devs);
	vbe_platform_devs = NULL;
	class_destroy(vbe_class);
fail_class_create:
	vbe_class = NULL;
	unregister_chrdev_region(vbe_devno, vbe_nr_devs);
	return result;
}

void __exit vbe_module_exit(void)
{
	dev_t devno = MKDEV(vbe_major, vbe_minor);
	DBG_PRINT(KERN_INFO "vbe clean module vbe_major = %d\n", vbe_major);

  	device_destroy(vbe_class, MKDEV(vbe_major, 0));
  	class_destroy(vbe_class);
	vbe_class=NULL;
	cdev_del(&vbe_cdev);

   	/* device driver removal */
	if(vbe_platform_devs)
	{
		platform_device_unregister(vbe_platform_devs);
		vbe_platform_devs=NULL;
	}
  	platform_driver_unregister(&vbe_device_driver);

	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, vbe_nr_devs);
}

module_init(vbe_module_init);
module_exit(vbe_module_exit);
