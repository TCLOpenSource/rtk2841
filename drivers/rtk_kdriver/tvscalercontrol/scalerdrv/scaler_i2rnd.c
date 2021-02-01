/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	scaler
 */

/**
 * @addtogroup scaler
 * @{
 */

/*============================ Module dependency  ===========================*/
//#include <unistd.h>			// 'close()'
//#include <fcntl.h>				// 'open()'
//#include <stdio.h>
//#include <string.h>
//#include <sys/ioctl.h>
//#include <time.h>
//#include <sys/mman.h>		// mmap
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
#include <rtk_kdriver/RPCDriver.h>
#include <mach/system.h>
#include <mach/timex.h>

#include <linux/pageremap.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/dma-mapping.h>/*DMA*/

#include <rbus/pst_i2rnd_reg.h>
#include <rbus/vodma_reg.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>

#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <scalercommon/scalerDrvCommon.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scaler_vscdev.h>
#include <tvscalercontrol/panel/panelapi.h>

#include <rbus/sensio_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/main_dither_reg.h>
#include <rbus/rgb2yuv_reg.h>
#include <rbus/peaking_reg.h>
#include <rbus/idcti_reg.h>
#include <rbus/histogram_reg.h>
#include <rbus/profile_reg.h>
#include <rbus/ringfilter_reg.h>
#include <rbus/hsd_dither_reg.h>
#include <rbus/mpegnr_reg.h>
#include <rbus/di_reg.h>
#include <rbus/nr_reg.h>
#include <rbus/iedge_smooth_reg.h>
#include <rbus/scaledown_reg.h>
#include <rbus/i_bist_bisr_reg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_vi_main_reg.h>
#include <rbus/de_xcxl_reg.h>
#include <rbus/tc_reg.h>
#include <rbus/color_mb_peaking_reg.h>
//#include <rbus/ipq_decontour_reg.h>
#include <rbus/dfilter_reg.h>

//I2RND
//vodma1  0xb8005000 - 0xb8005158
#define VODMA1_START_REGISTER					VODMA_VODMA_V1_DCFG_reg
#define VODMA1_END_REGISTER					VODMA_VODMA_CLKGEN_reg//VODMA_VODMA_BIST_OTHER_reg
#define VODMA1_REGISTER_NUM					((VODMA1_END_REGISTER -VODMA1_START_REGISTER + 4)/4)
#define VODMA1_register_range(addr)				(((addr>=VODMA1_START_REGISTER) &&(addr <=VODMA1_END_REGISTER)) ? 1: 0 )
#define VODMA1_DDR_range(addr)					((((addr>=VODMA1_START_REGISTER) &&(addr <=VODMA_VODMA_VGIP_INTPOS_reg)) \
												|| (addr==VODMA_VODMA_DBG_reg)  || (addr==VODMA_VODMA_quincunx_setting_reg) \
												|| (addr==VODMA_VODMA_dma_option_reg) \
												|| ((addr>=VODMA_DECOMP_CTRL0_reg) &&(addr <=VODMA_DECOMP_X_WID_C_reg)) \
												|| (addr==VODMA_DECOMP_DMA_IE_reg) \
												|| (addr==VODMA_VODMA_BIST_MODE_reg)  \
												|| ((addr>=VODMA_VODMA_DRF_MODE_reg) &&(addr <=VODMA_VODMA_DRF_RESUME_reg)) \
												|| (addr==VODMA_VODMA_BIST_OTHER_reg) \
												|| (addr==VODMA_VODMA_CLKGEN_reg)) ? 1: 0 )

//sensio : 0xb806b900 -  0xb806b9fc
#define MAIN_SENSIO_START_REGISTER			SENSIO_Sensio_ctrl_0_reg
#define MAIN_SENSIO_END_REGISTER				SENSIO_SENSIO_MBIST_RME_SUB_1_reg
#define MAIN_SENSIO_REGISTER_NUM				((MAIN_SENSIO_END_REGISTER - MAIN_SENSIO_START_REGISTER + 4)/4)
#define Main_SENSIO_register_range(addr)		(((addr>=MAIN_SENSIO_START_REGISTER) &&(addr <=MAIN_SENSIO_END_REGISTER)) ? 1: 0 )
#define Main_SENSIO_DDR_range(addr)			((((addr>=MAIN_SENSIO_START_REGISTER) &&(addr <=SENSIO_decomp_ctrl_0_reg)) \
												|| (addr==SENSIO_vp9_decomp_v_ctrl_reg) \
												|| ((addr>=SENSIO_SENSIO_TIM_CTRL_0_reg) &&(addr <=SENSIO_SENSIO_TIM_CTRL_1_reg)) \
												|| ((addr>=SENSIO_SENSIO_MBIST_LS_0_reg) &&(addr <=SENSIO_SENSIO_MBIST_LS_1_reg)) \
												|| ((addr>=SENSIO_SENSIO_MBIST_RM_0_reg) &&(addr <=SENSIO_SENSIO_MBIST_RM_4_reg)) \
												|| ((addr>=SENSIO_SENSIO_MBIST_RME_0_reg) &&(addr <=SENSIO_SENSIO_MBIST_RME_1_reg))) ? 1: 0 )


//vgip --b8028022200 - b80222ff
#define MAIN_VGIP_START_REGISTER				VGIP_V8_CTRL_reg
#define MAIN_VGIP_END_REGISTER				VGIP_DISPI_IRQ_RECORD_reg
#define MAIN_VGIP_REGISTER_NUM				((MAIN_VGIP_END_REGISTER - MAIN_VGIP_START_REGISTER + 4)/4)
#define Main_VGIP_register_range(addr)			(((addr>=MAIN_VGIP_START_REGISTER) &&(addr <=MAIN_VGIP_END_REGISTER)) ? 1: 0 )
#define Main_VGIP_DDR_range(addr)				((((addr >= VGIP_V8_CTRL_reg) && (addr <= VGIP_VGIP_CHN1_MISC_reg) && (addr != VGIP_VGIP_CHN1_STATUS_reg)) \
												|| ((addr >= VGIP_VGIP_CHN1_WDE_reg)  && (addr <= VGIP_PR_L_R_ONLY_CTRL_CH1_reg)) \
												|| ((addr >= VGIP_ADC_raw_data_DMA_reg)  && (addr <= VGIP_L_R_ACTIVE_ENABLE_CTRL2_reg)) \
												|| (addr == VGIP_DISPI_IRQ_RECORD_reg)) ? 1 : 0)

//dither --b8022600 -b8022650
#define MAIN_DITHER_START_REGISTER			MAIN_DITHER_I_Main_DITHER_CTRL1_reg
#define MAIN_DITHER_END_REGISTER				MAIN_DITHER_I_Main_DITHER_Temp_TB2_reg
#define MAIN_DITHER_REGISTER_NUM				((MAIN_DITHER_END_REGISTER - MAIN_DITHER_START_REGISTER + 4)/4)
#define Main_DITHER_register_range(addr)		(((addr>=MAIN_DITHER_START_REGISTER) &&(addr <=MAIN_DITHER_END_REGISTER)) ? 1: 0 )

//techcolor  --b8022800 - b8022884
#define MAIN_TECHCOLOR_START_REGISTER		TC_TChdr_enable_reg
#define MAIN_TECHCOLOR_END_REGISTER			TC_TChdr_SI_LUT_MBIST_reg
#define MAIN_TECHCOLOR_REGISTER_NUM			((MAIN_TECHCOLOR_END_REGISTER - MAIN_TECHCOLOR_START_REGISTER + 4)/4)
#define Main_TECHCOLOR_register_range(addr)		(((addr>=MAIN_TECHCOLOR_START_REGISTER) &&(addr <=MAIN_TECHCOLOR_END_REGISTER)) ? 1: 0 )

//rgb2yuv -- 0xb8023000- 0xb80230ff
#define RGB2YUV_START_REGISTER				RGB2YUV_ICH1_RGB2YUV_CTRL_reg
#define RGB2YUV_END_REGISTER					RGB2YUV_ICH1_422to444_CTRL_reg
#define RGB2YUV_REGISTER_NUM					((RGB2YUV_END_REGISTER - RGB2YUV_START_REGISTER + 4)/4)
#define RGB2YUV_register_range(addr)			(((addr>=RGB2YUV_START_REGISTER) &&(addr <=RGB2YUV_END_REGISTER)) ? 1: 0 )
#define Main_rgb2yuv_DDR_range(addr)			(((addr == RGB2YUV_ICH1_RGB2YUV_CTRL_reg) || \
												((addr >= RGB2YUV_Tab1_M11_M12_reg) && (addr <= RGB2YUV_Tab1_Yo_reg)) || \
												(addr == RGB2YUV_ICH1_422to444_CTRL_reg)) ? 1 : 0)
#if 0
//Peaking/Coring DLTI/DCTI  --0xb8023100- 0xb8023108
#define MAIN_PKCRI_START_REGISTER				PEAKING_ICH1_PEAKING_FILTER_reg
#define MAIN_PKCRI_END_REGISTER				PEAKING_ICH1_PEAKING_BOUND_reg
#define MAIN_PKCRI_REGISTER_NUM				((MAIN_PKCRI_END_REGISTER - MAIN_PKCRI_START_REGISTER + 4)/4)
#define Main_PKCRI_register_range(addr)			(((addr>=MAIN_PKCRI_START_REGISTER) &&(addr <=MAIN_PKCRI_END_REGISTER)) ? 1: 0 )
#endif
//idlti --0xb8023170-0xb8023180
#define MAIN_IDLTI_START_REGISTER				PEAKING_I_DLTI_CTRL_reg
#define MAIN_IDLTI_END_REGISTER				PEAKING_ICH1_DLTI_C4_reg
#define MAIN_IDLTI_REGISTER_NUM				((MAIN_IDLTI_END_REGISTER - MAIN_IDLTI_START_REGISTER + 4)/4)
#define Main_IDLTI_register_range(addr)			(((addr>=MAIN_IDLTI_START_REGISTER) &&(addr <=MAIN_IDLTI_END_REGISTER)) ? 1: 0 )

//dcti --0xb80231d4- 0xb80231f8
#define MAIN_DCTI_START_REGISTER				IDCTI_I_DCTI_CTRL_1_reg
#define MAIN_DCTI_END_REGISTER				IDCTI_I_DCTI_CTRL_7_reg
#define MAIN_DCTI_REGISTER_NUM				((MAIN_DCTI_END_REGISTER - MAIN_DCTI_START_REGISTER + 4)/4)
#define Main_DCTI_register_range(addr)			(((addr>=MAIN_DCTI_START_REGISTER) &&(addr <=MAIN_DCTI_END_REGISTER)) ? 1: 0 )

//histogram  --0xb802_3200  ~ 0xb802_3338
#define MAIN_HISTOGRAM_START_REGISTER		HISTOGRAM_ICH1_Hist_IN_CSELECT_reg
#define MAIN_HISTOGRAM_END_REGISTER			HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg
#define MAIN_HISTOGRAM_REGISTER_NUM			((MAIN_HISTOGRAM_END_REGISTER - MAIN_HISTOGRAM_START_REGISTER + 4)/4)
#define Main_HISTOGRAM_register_range(addr)	(((addr>=MAIN_HISTOGRAM_START_REGISTER) &&(addr <=MAIN_HISTOGRAM_END_REGISTER)) ? 1: 0 )
#define Main_HISTOGRAM_DDR_range(addr)		((((addr>=HISTOGRAM_ICH1_Hist_IN_CSELECT_reg) &&(addr <=HISTOGRAM_ICH1_Hist_IN_Range_Ver_reg)) \
												|| (addr==HISTOGRAM_ICH1_Bycolor_Debug_reg) || (addr==HISTOGRAM_ICH1_C0_SectionHist_IN_CSELECT_reg) \
												|| ((addr>=HISTOGRAM_ICH1_C0_Hist_Bound_reg) &&(addr <=HISTOGRAM_ICH1_Hist_READ_CTR_reg)) \
												|| ((addr>=HISTOGRAM_ICH1_C1_Hist_Bound_reg) &&(addr <=HISTOGRAM_ICH1_C1_Hist_Bound_V_reg)) \
												|| (addr==HISTOGRAM_ICH1_C1_SectionHist_IN_CSELECT_reg) \
												|| ((addr>=HISTOGRAM_ICH1_MBIST_HIST_2P_BIST_DVSE_reg) &&(addr <=HISTOGRAM_ICH1_MBIST_HIST_1P_BIST_DVS_reg))) ? 1: 0 )


//profile1  --0xb802_3400  ~ 0xb802_34c4
#define MAIN_PROFILE1_START_REGISTER			PROFILE_ICH1_Hist_Profile_CTRL_reg
#define MAIN_PROFILE1_END_REGISTER			PROFILE_ICH1_Hist_Profile2_Diff_bin_H_reg
#define MAIN_PROFILE1_REGISTER_NUM			((MAIN_PROFILE1_END_REGISTER - MAIN_PROFILE1_START_REGISTER + 4)/4)
#define Main_PROFILE1_register_range(addr)		(((addr>=MAIN_PROFILE1_START_REGISTER) &&(addr <=MAIN_PROFILE1_END_REGISTER)) ? 1: 0 )
#define Main_PROFILE1_DDR_range(addr)			((((addr>=MAIN_PROFILE1_START_REGISTER) &&(addr <=PROFILE_ICH1_Hist_Profile_StartV_reg)) \
												|| (addr==PROFILE_ICH1_Hist_Profile_Diff_th_reg) \
												|| ((addr>=PROFILE_ICH1_Hist_Profile2_CTRL_reg) &&(addr <=PROFILE_ICH1_Hist_Profile2_Diff_th_reg))) ? 1: 0 )

//dfilter  --0xb8023500 - 0xb8023504
#define MAIN_DFILTER_START_REGISTER		DFILTER_ICH1_DFILTER_PH_SMR_PRING_reg
#define MAIN_DFILTER_END_REGISTER			DFILTER_ICH1_DFILTER_NRING_MIS_NOS_YPBPR_reg
#define MAIN_DFILTER_REGISTER_NUM			((MAIN_DFILTER_END_REGISTER - MAIN_DFILTER_START_REGISTER + 4)/4)
#define  Main_DFILTER_register_range(addr)	(((addr>=MAIN_DFILTER_START_REGISTER) &&(addr <=MAIN_DFILTER_END_REGISTER)) ? 1: 0 )


//ring_filter  --0xb8023580 - 0xb8023590
#define MAIN_RINGFILTER_START_REGISTER		RINGFILTER_RFILTER_CTRL_reg
#define MAIN_RINGFILTER_END_REGISTER			RINGFILTER_RFILTER_FACTOR_TEST_CTRL_reg
#define MAIN_RINGFILTER_REGISTER_NUM			((MAIN_RINGFILTER_END_REGISTER - MAIN_RINGFILTER_START_REGISTER + 4)/4)
#define  Main_RINGFILTER_register_range(addr)	(((addr>=MAIN_RINGFILTER_START_REGISTER) &&(addr <=MAIN_RINGFILTER_END_REGISTER)) ? 1: 0 )

//di_hsd  --0xb8023600 - 0xb80236b8
#define MAIN_DIHSD_START_REGISTER				HSD_DITHER_SD_Dither_CTRL1_reg
#define MAIN_DIHSD_END_REGISTER				HSD_DITHER_DI_UZD_DB_CTRL_reg
#define MAIN_DIHSD_REGISTER_NUM				((MAIN_DIHSD_END_REGISTER - MAIN_DIHSD_START_REGISTER + 4)/4)
#define  Main_DIHSD_register_range(addr)			(((addr>=MAIN_DIHSD_START_REGISTER) &&(addr <=MAIN_DIHSD_END_REGISTER)) ? 1: 0 )
#define  Main_DIHSD_DDR_range(addr)				((((addr>=MAIN_DIHSD_START_REGISTER) &&(addr <=HSD_DITHER_DI_HSD_Hor_Segment_reg))  \
												||((addr>=HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg) &&(addr <=MAIN_DIHSD_END_REGISTER))) ? 1: 0 )

//profile2  --0xb802_3700  ~ 0xb802_37e0
#define MAIN_PROFILE2_START_REGISTER			PROFILE_SRCDET_CONTROL_reg
#define MAIN_PROFILE2_END_REGISTER			PROFILE_ICH1_Hist_Profile3_Diff_bin_H_reg
#define MAIN_PROFILE2_REGISTER_NUM			((MAIN_PROFILE2_END_REGISTER - MAIN_PROFILE2_START_REGISTER + 4)/4)
#define Main_PROFILE2_register_range(addr)		(((addr>=MAIN_PROFILE2_START_REGISTER) &&(addr <=MAIN_PROFILE2_END_REGISTER)) ? 1: 0 )
#define Main_PROFILE2_DDR_range(addr)			((((addr>=MAIN_PROFILE2_START_REGISTER) &&(addr <=PROFILE_SRCDET_TSH_STEP_MIN_reg)) \
												|| ((addr>=PROFILE_ICH1_Hist_Profile3_CTRL_reg) &&(addr <=PROFILE_ICH1_Hist_Profile3_StartV_reg)) \
												|| (addr==PROFILE_ICH1_Hist_Profile3_Diff_th_reg))? 1: 0 )


//mpegnr --0xb8023820 -0xb80238fc
#define MAIN_MPEGNR_START_REGISTER			MPEGNR_ICH1_blend_NR_Hor_step_reg
#define MAIN_MPEGNR_END_REGISTER				MPEGNR_ICH1_GENERAL_DB_CTRL_reg
#define MAIN_MPEGNR_REGISTER_NUM				((MAIN_MPEGNR_END_REGISTER - MAIN_MPEGNR_START_REGISTER + 4)/4)
#define Main_MPEGNR_register_range(addr)		(((addr>=MAIN_MPEGNR_START_REGISTER) &&(addr <=MAIN_MPEGNR_END_REGISTER)) ? 1: 0 )
#define Main_MPEGNR_DDR_range(addr)			((((addr>=MAIN_MPEGNR_START_REGISTER) &&(addr <=MPEGNR_FSYNC_GENERAL_CTRL2_reg)) \
												|| ((addr>=MPEGNR_ICH1_AccessData_CTRL_PK_reg) &&(addr <=MPEGNR_ICH1_AccessData_PosCtrl_PK_reg)) \
												|| (addr==MPEGNR_ICH1_WriteData_DATA_PK_reg) || (addr ==MPEGNR_ICH1_GENERAL_DB_CTRL_reg)) ? 1: 0 )


//dexcxl:0xb8023900 - 0xb80239e4
#define MAIN_DEXCXL_START_REGISTER			DE_XCXL_De_XCXL_CTRL_reg
#define MAIN_DEXCXL_END_REGISTER				DE_XCXL_DMA_NUM_ERR_reg
#define MAIN_DEXCXL_REGISTER_NUM				((MAIN_DEXCXL_END_REGISTER - MAIN_DEXCXL_START_REGISTER + 4)/4)
#define Main_DEXCXL_register_range(addr)		(((addr>=MAIN_DEXCXL_START_REGISTER) &&(addr <=MAIN_DEXCXL_END_REGISTER)) ? 1: 0 )
#define Main_DEXCXL_DDR_range(addr)			((((addr>=MAIN_DEXCXL_START_REGISTER) &&(addr <=DE_XCXL_De_XCXL_BLEND_reg)) \
												||((addr>=DE_XCXL_Frame_format_reg) &&(addr <=DE_XCXL_WRRD_BndAddr2_reg)) \
												||((addr>=DE_XCXL_DATMemStartAdd2_Odd_S0_reg) &&(addr <=DE_XCXL_DMA_Multi_Req_Set_reg)) \
												|| ((addr>=DE_XCXL_DE_XCXL_BIST_RME_reg) &&(addr <=DE_XCXL_INFMemStartAdd_Odd_S1_reg)) \
												|| (addr==DE_XCXL_DE_XCXL_ASYNC_FIFO_reg) ||(addr ==DE_XCXL_DMA_NUM_ERR_reg)) ? 1: 0 )


//multibamk:0xb802_3c00  ~ 0xb802_3c40
#define MAIN_MULTIBAMK_START_REGISTER		COLOR_MB_PEAKING_MB_PEAKING_CTRL_reg
#define MAIN_MULTIBAMK_END_REGISTER			COLOR_MB_PEAKING_MB_SNR_CORING_reg
#define MAIN_MULTIBAMK_REGISTER_NUM			((MAIN_MULTIBAMK_END_REGISTER - MAIN_MULTIBAMK_START_REGISTER + 4)/4)
#define Main_MULTIBAMK_register_range(addr)		(((addr>=MAIN_MULTIBAMK_START_REGISTER) &&(addr <=MAIN_MULTIBAMK_END_REGISTER)) ? 1: 0 )

//DI --b8024000-b8024bf4
#define MAIN_DI_START_REGISTER				DI_IM_DI_CONTROL_reg
#define MAIN_DI_END_REGISTER					DI_ccdinr_Timing_monitor_st_reg
#define MAIN_DI_REGISTER_NUM					((MAIN_DI_END_REGISTER - MAIN_DI_START_REGISTER + 4)/4)
#define Main_DI_register_range(addr)				(((addr>=MAIN_DI_START_REGISTER) &&(addr <=MAIN_DI_END_REGISTER)) ? 1: 0 )
#define Main_DI_DDR_range(addr)					((((addr>=MAIN_DI_START_REGISTER) &&(addr <=DI_IM_DI_SI_FILM_HB_COUT_reg)) \
												|| ((addr>=DI_IM_DI_TNR_TH_reg) &&(addr <=DI_IM_DI_RTNR_MAD_C_TH_reg)) \
												|| ((addr>=DI_IM_DI_RTNR_EDIFF_CONTROL_reg) &&(addr <=DI_IM_DI_RTNR_LEVEL_BOUND_reg)) \
												|| ((addr>=DI_IM_DI_TNR_XC_CONTROL_reg) &&(addr <=DI_IM_DI_BTR_SOLA_METHOD0_MIN_MAX_reg)) \
												|| ((addr>=DI_IM_DI_BER_SPATIAL_CONTROL_reg) &&(addr <=DI_Mpeg_Hist_Blking_reg)) \
												|| ((addr>=DI_MPEGNR1_reg) &&(addr <=DI_IM_DI_HMC_STATISTIC1_reg)) \
												|| ((addr>=DI_IM_DI_LSB_RTNR_reg) &&(addr <=DI_IM_DI_PAN_DETECTION_CONTROL_2_reg)) \
												|| ((addr>=DI_IM_DI_PAN_DETECTION_STATISTIC_8_reg) &&(addr <=DI_IM_DI_FILM_TopBotLine3_reg)) \
												|| ((addr>=DI_DI_SMD_Control_CandidateList_reg) &&(addr <=DI_IM_DI_RTNR_C_K_reg)) \
												|| ((addr>=DI_DDR_RDATDMA_WTLENNUM_reg) &&(addr <=DI_DDR_INFDMA_RM_reg)) \
												|| ((addr>=DI_DDR_WDE_reg) && (addr <=DI_DI1_WRRD_BoundaryAddr2_reg)) \
												|| ((addr>=DI_DI_Line_Base_Dma_Addr_L_reg) &&(addr <=DI_DI_Line_Base_Dma_Addr_L_reg)) \
												|| ((addr==DI_DI_DMA_Multi_Req_Num_reg)) \
												|| ((addr>=DI_DISPI_BIST_RME_reg) &&(addr <=DI_DISPI_BIST_TEST_RWM_reg)) \
												|| (addr == DI_DI_SMD_dummy_reg) \
												|| ((addr>=DI_DI_SMD_GMVCoeff3_reg) &&(addr <=DI_IM_DI_ZoomMotion_Det_04_reg)) \
												|| ((addr>=DI_IM_DI_ZoomMotion_Det_FM_TH_A_reg) &&(addr <=DI_IM_DI_SlowMotion_Detector_1_reg)) \
												|| ((addr>=DI_IM_DI_SlowMotion_Det_FM_TH_A_reg) &&(addr <=DI_IM_DI_SlowMotion_Det_FM_TH_C_reg)) \
												|| ((addr>=DI_DI_GST_Ctrl_reg) &&(addr <=DI_DI_SMD_CandidateLimitSAD_reg)) \
												|| ((addr>=DI_IM_DI_HMC_ADJUSTABLE_reg) &&(addr <=DI_DI_RTNR_NM_INFOR1_reg)) \
												|| ((addr>=DI_RTNR_OUTPUT_CLAMP_reg) &&(addr <=DI_DI_GST_Compensate_reg)) \
												|| ((addr>=DI_DI_GST_FMV_Pan_Coeff1_reg) &&(addr <=DI_DI_MA_WeaveMode_check_reg)) \
												|| (addr==DI_IM_DI_RTNR_MAD_Y_TH2_C_TH2_reg)  \
												|| ((addr>=DI_MEMC_P_FILM_CTRL0_reg) &&(addr <=DI_MEMC_P_FILM_CTRL2_reg)) \
												|| ((addr>=DI_MEMC_P_FILM_CTRL3_reg) &&(addr <=DI_IM_DI_RTNR_Fading_Detector_reg)) \
												|| ((addr>=DI_IM_DI_MA_Fading_Apply_Bias_reg) &&(addr <=DI_IM_DI_HMC_ME_REFINE_CTRL_2_reg)) \
												|| (addr==DI_IM_DI_HMC_ME_REFINE_CTRL_4_reg) \
												|| ((addr>=DI_IM_NEW_MCNR_CONTROL_reg) &&(addr <=DI_IM_NEW_MCNR_CLAMPING_VALUE_reg)) \
												|| ((addr>=DI_IM_DI_HME_LINE_STATISTIC_9_reg) &&(addr <=DI_DI_DDR_CHECKSUM_CTRL_reg)) \
												|| ((addr>=DI_DI_DDR_CHECKSUM_MASK_0_reg) &&(addr <=DI_DI_SMD_WaterFlow_Teeth_Ctr_reg)) \
												|| ((addr>=DI_DI_SMD_MA_MC_Weight_Ctr_reg) &&(addr <=DI_DI_SMD_Slow_Motion_handle2_reg)) \
												|| ((addr>=DI_IM_NEW_MCNR_CONTROL3_reg) &&(addr <=DI_IM_NEW_MCNR_MV_Debug_Ctrl_reg)) \
												|| ((addr>=DI_IM_NEW_MCNR_CONTROL4_reg) &&(addr <=DI_ccdinr_Timing_monitor_golden_1_reg)) \
												|| ((addr>=DI_DI_PQ_CMP_reg) &&(addr <=DI_DI_PQ_CMP_IRQ_EN_reg)) \
												|| ((addr>=DI_DI_PQ_DECMP_reg) &&(addr <=DI_DI_PQ_DECMP_IRQ_EN_reg)) \
												|| ((addr>=DI_DI_PQ_DECMP_MARK_EN_reg) &&(addr <=DI_DI_PQ_DECMP_MARK_color_422_reg)) \
												|| (addr==DI_DI_DI_SRAM_SELF_TEST_reg)) ? 1: 0 )

//NR --0xb8025000 -  0xb80250c8
#define MAIN_NR1_START_REGISTER				NR_DCH1_DebugMode_reg
#define MAIN_NR1_END_REGISTER					NR_SPNR_ACT_Length_reg
#define MAIN_NR1_REGISTER_NUM					((MAIN_NR1_END_REGISTER - MAIN_NR1_START_REGISTER + 4)/4)
#define Main_NR1_register_range(addr)			(((addr>=MAIN_NR1_START_REGISTER) &&(addr <=MAIN_NR1_END_REGISTER)) ? 1: 0 )
#define Main_NR1_DDR_range(addr)				((((addr>=MAIN_NR1_START_REGISTER) &&(addr <=NR_DCH1_Spatial_Weight_reg)) \
												|| ((addr>=NR_DCH1_Local_Var2_reg) &&(addr <=NR_DCH1_MPEGNR1_reg)) \
												|| ((addr>=NR_DCH1_MASK1_CTRL1_reg) &&(addr <=MAIN_NR1_END_REGISTER))) ? 1: 0 )

//iedge_smooth 0xb8025100 - 0xb80251ec
#define MAIN_IEDGESMOOTH_START_REGISTER		IEDGE_SMOOTH_EdgeSmooth_EX_CTRL_reg
#define MAIN_IEDGESMOOTH_END_REGISTER		IEDGE_SMOOTH_OUT_CLAMP_reg
#define MAIN_IEDGESMOOTH_REGISTER_NUM		((MAIN_IEDGESMOOTH_END_REGISTER - MAIN_IEDGESMOOTH_START_REGISTER + 4)/4)
#define Main_IEDGESMOOTH_register_range(addr)	(((addr>=MAIN_IEDGESMOOTH_START_REGISTER) &&(addr <=MAIN_IEDGESMOOTH_END_REGISTER)) ? 1: 0 )
#define Main_IEDGESMOOTH_DDR_range(addr)		((((addr>=MAIN_IEDGESMOOTH_START_REGISTER) &&(addr <=IEDGE_SMOOTH_SPNR_PORCH_MEAS_reg)) \
												|| ((addr>=IEDGE_SMOOTH_SPNR_DVS0_reg) &&(addr <=IEDGE_SMOOTH_OUT_CLAMP_reg))) ? 1: 0 )

//UZD  0xb8025204 - 0xb802537c
#define MAIN_UZD_START_REGISTER				SCALEDOWN_ICH1_UZD_Ctrl0_reg
#define MAIN_UZD_END_REGISTER					SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg
#define MAIN_UZD_REGISTER_NUM					((MAIN_UZD_END_REGISTER - MAIN_UZD_START_REGISTER + 4)/4)
#define Main_UZD_register_range(addr)			(((addr>=MAIN_UZD_START_REGISTER) &&(addr <=MAIN_UZD_END_REGISTER)) ? 1: 0 )
#define Main_UZD_DDR_range(addr)				((((addr>=MAIN_UZD_START_REGISTER) &&(addr <=SCALEDOWN_ICH1_UZD_CRC_CTRL_reg)) \
												|| ((addr>=SCALEDOWN_ICH1_IBUFF_CTRLI_BUFF_CTRL_reg) &&(addr <=SCALEDOWN_ICH1_UZD_DB_CTRL_reg)) \
												|| ((addr>=SCALEDOWN_AccessData_CTRL_UZD_reg) &&(addr <=SCALEDOWN_AccessData_PosCtrl_UZD_reg)) \
												|| (addr==SCALEDOWN_WriteData_DATA_UZD_reg) ||(addr==SCALEDOWN_ich1_sdnr_linebuf_dvs_reg) \
												|| ((addr>=SCALEDOWN_ich1_sdnr_cutout_range_hor_reg) &&(addr <=SCALEDOWN_ICH1_UZD_FIR_Coef_Tab2_C30_reg)))  ? 1: 0 )

//NR --0xb8025508 -  0xb8025594
#define MAIN_NR2_START_REGISTER				NR_MNR_LEVEL_HISTOGRAM_CTRL_0_reg
#define MAIN_NR2_END_REGISTER					NR_SNR_Timing_monitor_st_reg
#define MAIN_NR2_REGISTER_NUM					((MAIN_NR2_END_REGISTER - MAIN_NR2_START_REGISTER + 4)/4)
#define Main_NR2_register_range(addr)			(((addr>=MAIN_NR2_START_REGISTER) &&(addr <=MAIN_NR2_END_REGISTER)) ? 1: 0 )
#define Main_NR2_DDR_range(addr)				((((addr>=MAIN_NR2_START_REGISTER) &&(addr <=NR_MNR_LEVEL_HISTOGRAM_CTRL_4_reg)) \
												|| ((addr>=NR_MAXMIN_HISTOGRAM_CTRL_0_reg) &&(addr <=NR_MAXMIN_HISTOGRAM_CTRL_2_reg)) \
												|| ((addr>=NR_SNR_Timing_monitor_ctrl_reg) &&(addr <=MAIN_NR2_END_REGISTER))) ? 1: 0 )
#if 0
//decontour: 0xb8025700 - 0xb802575c
#define MAIN_DECONTOUR_START_REGISTER		IPQ_DECONTOUR_De_Contour_CTRL_reg
#define MAIN_DECONTOUR_END_REGISTER			IPQ_DECONTOUR_De_Contour_db_reg_ctl_reg
#define MAIN_DECONTOUR_REGISTER_NUM			((MAIN_DECONTOUR_END_REGISTER - MAIN_DECONTOUR_START_REGISTER + 4)/4)
#define Main_DECONTOUR_register_range(addr)	(((addr>=MAIN_DECONTOUR_START_REGISTER) &&(addr <=MAIN_DECONTOUR_END_REGISTER)) ? 1: 0 )
#define Main_DECONTOUR_DDR_range(addr)		((((addr>=MAIN_DECONTOUR_START_REGISTER) &&(addr <=IPQ_DECONTOUR_De_Contour_Threshold_reg)) \
												||(addr==IPQ_DECONTOUR_De_Contour_db_reg_ctl_reg)) ? 1: 0 )
#endif

//bist: 0xb8025f00 - 0xb8025f5c
#define MAIN_BIST_START_REGISTER				I_BIST_BISR_DISPI_BIST_MODE_reg
#define MAIN_BIST_END_REGISTER				I_BIST_BISR_DISPI_DRF_FAIL_GROUP_1_reg
#define MAIN_BIST_REGISTER_NUM				((MAIN_BIST_END_REGISTER - MAIN_BIST_START_REGISTER + 4)/4)
#define Main_BIST_register_range(addr)			(((addr>=MAIN_BIST_START_REGISTER) &&(addr <=MAIN_BIST_END_REGISTER)) ? 1: 0 )
#define Main_BIST_DDR_range(addr)				(((addr==MAIN_BIST_START_REGISTER) \
												|| ((addr>=I_BIST_BISR_DISPI_DRF_MODE_reg) &&(addr <=I_BIST_BISR_DISPI_DRF_RESUME_reg)) \
												|| (addr==I_BIST_BISR_DISPI_BISR_SECOND_RUN_EN_reg) \
												|| ((addr>=I_BIST_BISR_DISPI_BISR_DRF_MODE_reg) &&(addr <=I_BIST_BISR_DISPI_BISR_DRF_RESUME_reg)) \
												|| (addr==I_BIST_BISR_DISPI_BIST_MODE_1_reg) \
												|| ((addr>=I_BIST_BISR_DISPI_DRF_MODE_1_reg) &&(addr <=I_BIST_BISR_DISPI_DRF_RESUME_1_reg))) ? 1: 0 )

//mcapt: 0xb8027200 - 0xb802722c;b802726c~b8027280;b80272c8~b80272cc;b80272e0~b80272ec;
#define MCAP_START_REGISTER					MDOMAIN_CAP_DDR_In1WTLVL_Num_reg
#define MCAP_END_REGISTER						MDOMAIN_CAP_Smooth_tog_status_0_reg
#define MCAP_REGISTER_NUM						((MCAP_END_REGISTER - MCAP_START_REGISTER + 4)/4)
#define MCAP_register_range(addr)				(((addr>=MCAP_START_REGISTER) &&(addr <=MCAP_END_REGISTER)) ? 1: 0 )
#define Main_mcap_DDR_range(addr)				((((addr >= MDOMAIN_CAP_DDR_In1WTLVL_Num_reg) && (addr <= MDOMAIN_CAP_DDR_In1subCtrl_reg) && (addr != MDOMAIN_CAP_DDR_In1Status_reg)) || \
												((addr >= MDOMAIN_CAP_CapMain_BoundaryAddr1_reg) && (addr <= MDOMAIN_CAP_CapMain_BoundaryAddr2_reg)) || \
												((addr >= MDOMAIN_CAP_Cap_IE_WD_CTRL_reg) && (addr <= MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg)) || \
												((addr >= MDOMAIN_CAP_CAP_DMA_rate_CTRL_reg) && (addr <= MDOMAIN_CAP_Main_SDNR_cxxto64_reg)) || \
												((addr >= MDOMAIN_CAP_main_cmp_resolution_reg) && (addr <= MDOMAIN_CAP_main_compress_reg))) ? 1 : 0)

//mcap_vi:b8027000~b802707c
#define MAIN_VI_MCAP_START_REGISTER			MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_reg
#define MAIN_VI_MCAP_END_REGISTER			MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_reg
#define MAIN_VI_MCAP_REGISTER_NUM			((MAIN_VI_MCAP_END_REGISTER - MAIN_VI_MCAP_START_REGISTER + 4)/4)
#define MAIN_VI_MCAP_register_range(addr)		(((addr>=MAIN_VI_MCAP_START_REGISTER) &&(addr <=MAIN_VI_MCAP_END_REGISTER)) ? 1: 0 )
#define MAIN_VI_MCAP_DDR_range(addr)			((((addr>=MAIN_VI_MCAP_START_REGISTER) &&(addr <=MDOMAIN_VI_MAIN_INTEN_reg)) \
												|| ((addr>=MDOMAIN_VI_MAIN_GCTL_reg) &&(addr <=MAIN_VI_MCAP_END_REGISTER))) ? 1: 0 )


#define I2RND_REGISTER_NUMBER (VODMA1_REGISTER_NUM + MAIN_SENSIO_REGISTER_NUM + MAIN_VGIP_REGISTER_NUM + MAIN_TECHCOLOR_REGISTER_NUM + \
								MAIN_DITHER_REGISTER_NUM+ RGB2YUV_REGISTER_NUM /*+ MAIN_PKCRI_REGISTER_NUM*/ + MAIN_IDLTI_REGISTER_NUM + \
								MAIN_DCTI_REGISTER_NUM + MAIN_HISTOGRAM_REGISTER_NUM + MAIN_PROFILE1_REGISTER_NUM + MAIN_DFILTER_REGISTER_NUM + \
								MAIN_RINGFILTER_REGISTER_NUM + MAIN_DIHSD_REGISTER_NUM + MAIN_PROFILE2_REGISTER_NUM + MAIN_MPEGNR_REGISTER_NUM + \
								MAIN_DEXCXL_REGISTER_NUM + MAIN_MULTIBAMK_REGISTER_NUM + MAIN_DI_REGISTER_NUM + MAIN_NR1_REGISTER_NUM + \
								MAIN_IEDGESMOOTH_REGISTER_NUM + MAIN_UZD_REGISTER_NUM + MAIN_NR2_REGISTER_NUM /*+ MAIN_DECONTOUR_REGISTER_NUM*/ + \
								MAIN_BIST_REGISTER_NUM + MCAP_REGISTER_NUM + MAIN_VI_MCAP_REGISTER_NUM)


#define I2RND_REGISTER_SIZE  8
#define REGISTER_VALUE_SIZE  4

#define I2RND_DMA_LENGTH 16
#define I2RND_DMA_WATERLEVEL 96

#define I2RND_BLOCK_SIZE ((I2RND_REGISTER_NUMBER + ((I2RND_REGISTER_NUMBER%2) ? 1 : 0)) / 2 * 16) //queue size(total block size) = (regisrer num/2) * 128bits = (regisrer num/2) * 16bytes
//#define I2RND_QUEUE_SIZE (I2RND_BLOCK_SIZE*(I2RND_CMD_NUMBER+1)) //queue size(total block size) = (regisrer num/2) * 128bits = (regisrer num/2) * 16bytes


#define FALSE 0
#define TRUE 1


//i2rnd perind define
#define I2RND_VO_CLOCK_180MHZ 180 //for under 2k1k interlace
#define I2RND_VO_CLOCK_360MHZ 360 //for under 2k1k
#define I2RND_VO_CLOCK_600MHZ 600 //for 4k2k
#define I2RND_VO_CLOCK_594MHZ 594 //for 4k2k
#define I2RND_VO_FIX_H_TOTAL_4K2K 4020
#define I2RND_VO_FIX_V_TOTAL_4K2K 2210
#define I2RND_VO_FIX_V_TOTAL_4K1K 1130
#define I2RND_VO_FIX_H_TOTAL_2K1K 2100
#define I2RND_VO_FIX_V_TOTAL_2K1K_P 1130
#define I2RND_VO_FIX_V_TOTAL_2K1K_I 590
#define VO_FIXED_4K2K_HTOTAL 4400
#define VO_FIXED_4K2K_VTOTAL 2250
#define I2RND_XTAL_CLOCK 27000000 //crystal clock: 27MHz
#define I2RND_TMASTER_TIME 40 //writing time of each register is about 40ns

#define I2RND_ENABLE_ADDR_SIZE 4
#define I2RND_WRITE_CMD_ADDR_SIZE 4
#define I2RND_READ_CMD_ADDR_SIZE 4
#define I2RND_PST_POINT_COUNTER 4
#define I2RND_INFO_SIZE (I2RND_ENABLE_ADDR_SIZE + I2RND_WRITE_CMD_ADDR_SIZE + I2RND_READ_CMD_ADDR_SIZE + I2RND_PST_POINT_COUNTER)

/* Swap bytes in 32 bit value.  */

#define __bswap_constant_32(x) \
  ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
   (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))

#define __bswap_32(x) __bswap_constant_32 (x)

/*===================================  Types ================================*/
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

/*================================== Variables ==============================*/
//b05_i2rnd
static I2RND_START_ADDR i2rnd_b05_st_addr;
static I2RND_STEP_SIZE i2rnd_b05_step_size;
static I2RND_CMD_BUF i2rnd_b05_cmd_buf;
static I2RND_SCPU_VIR_START_ADDR i2rnd_b05_scpu_vir_addr;
static unsigned int i2run_b05_addr = 0;
static unsigned int b05_cache_addr = 0;
//static unsigned int i2run_b05_test = 0;
static unsigned int i2run_b05_queue_size = 0;
unsigned int i2run_b05_allocate_size = 0;

static unsigned int vo_fix_htotal_main_4k2k = I2RND_VO_FIX_H_TOTAL_4K2K;
static unsigned int vo_fix_vtotal_main_4k2k = I2RND_VO_FIX_V_TOTAL_4K2K;

//i2rnd
static I2RND_START_ADDR i2rnd_st_addr;
static I2RND_STEP_SIZE i2rnd_step_size;
static I2RND_CMD_BUF i2rnd_cmd_buf;
static I2RND_SCPU_VIR_START_ADDR i2rnd_scpu_vir_addr;

//control
static unsigned char i2rnd_enable = FALSE;
static unsigned char i2rnd_display = I2RND_TABLE_OFF;
static unsigned int i2run_queue_size = 0;
static unsigned int i2run_blk_size = 0;
//static unsigned int i2rnd_final_queue_size = 0; //after align size

//i2rnd period
static unsigned int vo_clock_main = I2RND_VO_CLOCK_360MHZ;
static unsigned int vo_clock_sub = I2RND_VO_CLOCK_360MHZ;
static unsigned int vo_fix_htotal_main = I2RND_VO_FIX_H_TOTAL_2K1K;
static unsigned int vo_fix_htotal_sub = I2RND_VO_FIX_H_TOTAL_2K1K;
static unsigned int vo_fix_vtotal_main = I2RND_VO_FIX_V_TOTAL_2K1K_P;
static unsigned int vo_fix_vtotal_sub = I2RND_VO_FIX_V_TOTAL_2K1K_P;
static unsigned int vo_fix_hload_main = I2RND_VO_FIX_H_TOTAL_2K1K;
static unsigned int vo_fix_hload_sub = I2RND_VO_FIX_H_TOTAL_2K1K;
static unsigned int vo_frame_rate_main = 60;
static unsigned int vo_frame_rate_sub = 60;

static unsigned int i2rnd_period_update_main = 0;
static unsigned int i2rnd_period_update_sub = 0;

//I2RND semaphore
extern struct semaphore I2RND_Semaphore;
/*================================== extern ==============================*/
//extern unsigned short Scaler_DispGetInputInfoByDisp(unsigned char channel, SLR_INPUT_INFO infoList);
extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr;
extern void fw_scalerip_set_di_size_change_hw_detect(unsigned char enable);
/*================================== Function  ==============================*/
#ifdef CONFIG_I2RND_ENABLE
void Scaler_I2rnd_handler(void)
{
	//enable i2rnd
	drvif_scaler_i2rnd_top_ctrl(Scaler_I2rnd_get_enable());

	//toggle DI size let DI address apply @Crixus 20160802
	i2rnd_di_size_toggle();
}

unsigned char Scaler_I2rnd_get_enable(void)
{
	if (i2rnd_scpu_vir_addr.i2rnd_enable_vir_addr) {
		return (*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_enable_vir_addr));
	} else {
		return 0;
	}
}
void Scaler_I2rnd_set_enable(unsigned char enable)
{
	if (i2rnd_scpu_vir_addr.i2rnd_enable_vir_addr) {
		*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_enable_vir_addr) = enable;
	}
}
unsigned char Scaler_I2rnd_get_read_cmd_num(void)
{
	if (i2rnd_scpu_vir_addr.i2rnd_read_cmd_vir_addr) {
		return (*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_read_cmd_vir_addr));
	} else {
		return 0;
	}
}
void Scaler_I2rnd_set_read_cmd_num(unsigned char enable)
{
	if (i2rnd_scpu_vir_addr.i2rnd_read_cmd_vir_addr) {
		*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_read_cmd_vir_addr) = enable;
	}
}
unsigned char Scaler_I2rnd_get_write_cmd_num(void)
{
	if (i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr) {
		return (*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr));
	} else {
		return 0;
	}
}
void Scaler_I2rnd_set_write_cmd_num(void)
{
 	if (i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr) {
#if 1
		unsigned char cmd_num = (*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr));
		if ((cmd_num + 1 )> I2RND_CMD_NUMBER) {
			cmd_num = 0;
		} else {
			cmd_num = cmd_num + 1;
		}
		*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr) = cmd_num;
#else

		*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr) = 0;
#endif
 	}
}
void Scaler_i2rnd_write_default_cmd_num(void)
{
	if (i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr) {
		*(volatile unsigned char *)(i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr) = 0;
	}
}
unsigned int Scaler_i2rnd_cmd_buffer_write_offset_addr(unsigned int addr)
{
	unsigned int curr_addr= 0;
	curr_addr = addr + Scaler_I2rnd_get_write_cmd_num() * i2rnd_st_addr.cmd_buffer_size;
	return curr_addr;
}
unsigned int Scaler_i2rnd_cmd_buffer_read_offset_addr(unsigned int addr)
{
	unsigned int curr_addr= 0;
	curr_addr = addr + Scaler_I2rnd_get_read_cmd_num() * i2rnd_st_addr.cmd_buffer_size;
	return curr_addr;
}

unsigned char Scaler_I2rnd_get_display(void)
{
	return i2rnd_display;
}
void Scaler_I2rnd_set_display(unsigned char display)
{
	down(&I2RND_Semaphore);

	i2rnd_display = display;

	up(&I2RND_Semaphore);

}

/***********************************I2RND**************************************************/
/*
1.allocate i2run memory about cmd buf queue+SCPU/VCPU comulate info(I2run enable or not)
2.send RPC info to VCPU and recored each ip start access address
3.Calculate the I2run DMA setting
*/
void drvif_scaler_i2rnd_initial(void)
{
	unsigned int cache_addr;
	unsigned int blk_size_mod = 0;
	unsigned int i2run_blk_size = 0;
	unsigned int i2run_allocate_size = 0;

	//align total queue size
	i2run_blk_size = I2RND_BLOCK_SIZE;
	blk_size_mod = i2run_blk_size % (I2RND_DMA_LENGTH*8);//No remain so need align length size length*64bits
	if(blk_size_mod != 0){
		i2run_blk_size = i2run_blk_size + ((I2RND_DMA_LENGTH*8) - blk_size_mod);
	}

	i2run_queue_size = i2run_blk_size*(I2RND_CMD_NUMBER+1);
	i2run_allocate_size =i2run_queue_size+I2RND_INFO_SIZE;
	printk(KERN_EMERG"[%s][crixus]i2rnd_final_queue_size = %d\n", __FUNCTION__, i2run_queue_size);

	//share memory allocation
	if (i2rnd_scpu_vir_addr.s0_vo_st_vir_addr == 0) {
		cache_addr= (unsigned int)dvr_malloc_uncached_specific(i2run_allocate_size, GFP_DCU1,(void*)&(i2rnd_scpu_vir_addr.s0_vo_st_vir_addr));
		i2rnd_st_addr.s0_vo_st_addr = (unsigned int)dvr_to_phys((void*)cache_addr);
		i2rnd_st_addr.i2rnd_enable_addr = i2rnd_st_addr.s0_vo_st_addr + i2run_queue_size;
		i2rnd_st_addr.write_cmd_num_addr = i2rnd_st_addr.i2rnd_enable_addr + I2RND_ENABLE_ADDR_SIZE;
		i2rnd_st_addr.read_cmd_num_addr = i2rnd_st_addr.write_cmd_num_addr + I2RND_WRITE_CMD_ADDR_SIZE;
		memset((unsigned char *)i2rnd_scpu_vir_addr.s0_vo_st_vir_addr, 0, sizeof(unsigned char) * i2run_allocate_size);
	}
	if (i2rnd_scpu_vir_addr.s1_vo_st_vir_addr == 0) {
		cache_addr = (unsigned int)dvr_malloc_uncached_specific(i2run_queue_size, GFP_DCU1,(void*)&(i2rnd_scpu_vir_addr.s1_vo_st_vir_addr));
		i2rnd_st_addr.s1_vo_st_addr = (unsigned int)dvr_to_phys((void*)cache_addr);
		memset((unsigned char *)i2rnd_scpu_vir_addr.s1_vo_st_vir_addr, 0, sizeof(unsigned char) * i2run_queue_size);
	}
	i2rnd_st_addr.cmd_buffer_size = i2run_blk_size;

	printk(KERN_EMERG"[%s][crixus]i2rnd_st_addr.s0_vo_st_addr = %x\n", __FUNCTION__, i2rnd_st_addr.s0_vo_st_addr);
	printk(KERN_EMERG"[%s][crixus]i2rnd_st_addr.s1_vo_st_addr = %x\n", __FUNCTION__, i2rnd_st_addr.s1_vo_st_addr);
	printk(KERN_EMERG"[%s][crixus]i2rnd_st_addr.i2rnd_enable_addr = %x\n", __FUNCTION__, i2rnd_st_addr.i2rnd_enable_addr);

	if((i2rnd_st_addr.s0_vo_st_addr == 0) || (i2rnd_st_addr.s1_vo_st_addr == 0)){
		printk(KERN_EMERG"[I2RND]malloc i2rnd buffer fail .......................................\n");
		printk(KERN_EMERG"[I2RND]main_i2rnd_dma_start_addr = %x\n", i2rnd_st_addr.s0_vo_st_addr);
		printk(KERN_EMERG"[I2RND]sub_i2rnd_dma_start_addr = %x\n", i2rnd_st_addr.s1_vo_st_addr);
		return;
	}
	Scaler_i2rnd_setbuffer();
	//i2rnd dma setting
	drvif_scaler_i2rnd_dma_setting(I2RND_CMD_NUMBER, i2run_blk_size);

	//default period setting
	vodma_vodma_i2rnd_m_period_load_RBUS  vo_i2rnd_m_p_load;
	vodma_vodma_i2rnd_m_period_RBUS  vo_i2rnd_m_p;
	vodma_vodma_i2rnd_s_period_load_RBUS  vo_i2rnd_s_p_load;
	vodma_vodma_i2rnd_s_period_RBUS  vo_i2rnd_s_p;
	vodma_vodma_reg_db_ctrl_RBUS vodma_vodma_reg_db_ctrl;
	vodma_vodma_i2rnd_m_period_load_dbg_RBUS vodma_vodma_i2rnd_m_period_load_dbg;
	vodma_vodma_i2rnd_s_period_load_dbg_RBUS vodma_vodma_i2rnd_s_period_load_dbg;

	//disable double buffer
	vodma_vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_vodma_reg_db_ctrl.i2rnd_db_en = 0;
    	IoReg_Write32(VODMA_VODMA_REG_DB_CTRL_reg, vodma_vodma_reg_db_ctrl.regValue);

	//VODMA i2rnd period min & enable xtal clock
	vo_i2rnd_m_p_load.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_load_reg);
	vo_i2rnd_m_p_load.i2rnd_m_period_load = 2200 * 5;//s0_period;//300;
	vo_i2rnd_m_p_load.i2rnd_period_clk_src = 1;//reference xtal clock in mac5p @Crixus 20170104
	IoReg_Write32(VODMA_vodma_i2rnd_m_period_load_reg, vo_i2rnd_m_p_load.regValue);

	//VODMA i2rnd period
	vo_i2rnd_m_p.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_reg);
	vo_i2rnd_m_p.i2rnd_m_period = 2200 * 1090;//s0_period - 300;
	IoReg_Write32(VODMA_vodma_i2rnd_m_period_reg, vo_i2rnd_m_p.regValue);

	//VODMA i2rnd period max
	vodma_vodma_i2rnd_m_period_load_dbg.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_load_dbg_reg);
	vodma_vodma_i2rnd_m_period_load_dbg.i2rnd_m_period_load_max = 2200 * 35;
	vodma_vodma_i2rnd_m_period_load_dbg.i2rnd_period_load_max_dbg_en = 1; //default enable m_period load max measure @Crixus 20170504
	vodma_vodma_i2rnd_m_period_load_dbg.i2rnd_period_load_max_measure_en = 1;
	IoReg_Write32(VODMA_vodma_i2rnd_m_period_load_dbg_reg, vodma_vodma_i2rnd_m_period_load_dbg.regValue);
	//sub period min
	vo_i2rnd_s_p_load.regValue = rtd_inl(VODMA_vodma_i2rnd_s_period_load_reg);
	vo_i2rnd_s_p_load.i2rnd_s_period_load = 2200 * 5;
	IoReg_Write32(VODMA_vodma_i2rnd_s_period_load_reg, vo_i2rnd_s_p_load.regValue);

	//sub period load
	vo_i2rnd_s_p.regValue = rtd_inl(VODMA_vodma_i2rnd_s_period_reg);
	vo_i2rnd_s_p.i2rnd_s_period = 2200 * 1090;
	IoReg_Write32(VODMA_vodma_i2rnd_s_period_reg, vo_i2rnd_s_p.regValue);

	//sub period max
	vodma_vodma_i2rnd_s_period_load_dbg.regValue = rtd_inl(VODMA_vodma_i2rnd_s_period_load_dbg_reg);
	vodma_vodma_i2rnd_s_period_load_dbg.i2rnd_s_period_load_max = 2200 * 35;
	IoReg_Write32(VODMA_vodma_i2rnd_s_period_load_dbg_reg, vodma_vodma_i2rnd_s_period_load_dbg.regValue);
//	i2rnd_scpu_vir_addr.i2rnd_pst_write_pnt_counter = 0;
}

void drvif_scaler_i2rnd_uninitial(void)
{

	//disable i2rnd
	drvif_scaler_i2rnd_top_ctrl(_DISABLE);

	//disable DI hw detect
	fw_scalerip_set_di_size_change_hw_detect(_DISABLE);
	return;//FIX ME,below code will crash
	//free memory
	if((i2rnd_st_addr.s0_vo_st_addr != 0) && (i2rnd_scpu_vir_addr.s0_vo_st_vir_addr != 0)){
		dvr_free((void *)i2rnd_scpu_vir_addr.s0_vo_st_vir_addr);
		i2rnd_st_addr.s0_vo_st_addr = 0;
		i2rnd_scpu_vir_addr.s0_vo_st_vir_addr = 0;

	}

	if((i2rnd_st_addr.s1_vo_st_addr != 0) && (i2rnd_scpu_vir_addr.s1_vo_st_vir_addr != 0)){
		dvr_free((void *)i2rnd_scpu_vir_addr.s1_vo_st_vir_addr);
		i2rnd_st_addr.s1_vo_st_addr = 0;
		i2rnd_scpu_vir_addr.s1_vo_st_vir_addr = 0;
	}
}

void drvif_scaler_i2rnd_top_ctrl(bool i2rnd_en)
{
	vodma_vodma_i2rnd_RBUS    vo_i2rnd;
    	pst_i2rnd_top_ctrl_RBUS   top_ctrl;
	if(i2rnd_en){
	    top_ctrl.regValue = rtd_inl(PST_I2RND_TOP_CTRL_reg);
	    top_ctrl.i2rnd_en = i2rnd_en;
	    IoReg_Write32(PST_I2RND_TOP_CTRL_reg, top_ctrl.regValue);
	}else{
		vo_i2rnd.regValue = rtd_inl(VODMA_vodma_i2rnd_reg);
		vo_i2rnd.i2rnd_timing_mode = _1_MAIN_0_SUB;
		IoReg_Write32(VODMA_vodma_i2rnd_reg, vo_i2rnd.regValue);
		vo_i2rnd.i2rnd_timing_en = 0;
		IoReg_Write32(VODMA_vodma_i2rnd_reg, vo_i2rnd.regValue);
		top_ctrl.regValue = rtd_inl(PST_I2RND_TOP_CTRL_reg);
		top_ctrl.i2rnd_en = i2rnd_en;
		IoReg_Write32(PST_I2RND_TOP_CTRL_reg, top_ctrl.regValue);
	}
}
#if 0
void drvif_scaler_i2rnd_vodma1_flag_fifo_prepare(void)
{
	vodma_vodma_v1_dcfg_RBUS v_v1_dcfg;
	v_v1_dcfg.dma_mode = 0;
	v_v1_dcfg.dma_auto_mode = 1;
	v_v1_dcfg.field_mode = 1;
	IoReg_Write32(VODMA_VODMA_V1_DCFG_reg, v_v1_dcfg.regValue);

	vodma_vodma_v1chroma_fmt_RBUS v_v1chroma_fmt;
	v_v1chroma_fmt.rtnr_addr_hw_mode = 0;
	IoReg_Write32(VODMA_VODMA_V1CHROMA_FMT_reg, v_v1chroma_fmt.regValue);

	vodma_vodma_quincunx_setting_RBUS vodma_quincunx_setting;
	vodma_quincunx_setting.regValue = rtd_inl(VODMA_VODMA_quincunx_setting_reg);
	vodma_quincunx_setting.quincunx_mode_src_sel = 1;
	IoReg_Write32(VODMA_VODMA_quincunx_setting_reg, vodma_quincunx_setting.regValue);
}
#endif
void drvif_scaler_i2rnd_vodma_setting(unsigned char display, unsigned char input_src)
{
	vodma_vodma_i2rnd_RBUS    vo_i2rnd;
    	vodma_vodma_i2rnd_m_flag_RBUS vo_i2rnd_m_flag;
	vodma_vodma_i2rnd_s_flag_RBUS vo_i2rnd_s_flag;
	vodma_vodma_i2rnd_m_period_load_RBUS  vo_i2rnd_m_p_load;
	vodma_vodma_i2rnd_m_period_RBUS  vo_i2rnd_m_p;
	vodma_vodma_i2rnd_s_period_load_RBUS  vo_i2rnd_s_p_load;
	vodma_vodma_i2rnd_s_period_RBUS  vo_i2rnd_s_p;
	vodma_vodma_reg_db_ctrl_RBUS vodma_vodma_reg_db_ctrl;
	vodma_vodma_i2rnd_m_period_load_dbg_RBUS vodma_vodma_i2rnd_m_period_load_dbg;
	vodma_vodma_i2rnd_s_period_load_dbg_RBUS vodma_vodma_i2rnd_s_period_load_dbg;
	vodma_vodma_i2rnd_dma_info_RBUS vodma_i2rnd_dma_info;

	unsigned int frame_period = 0, period_min = 0, period_max = 0, free_period = 0;
	unsigned int h_active = 0, v_active = 0, interlace = 0;
	unsigned char refine_sub_period = 0;

	//i2rnd period
	unsigned int h_load = 0;
	unsigned int fix_htotal = 0;
	unsigned int vo_clock = 0;
	unsigned int frame_rate = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ);
	unsigned int fix_vtotal = 0;
	unsigned int v_load = 0;

	//disable double buffer
	vodma_vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_vodma_reg_db_ctrl.i2rnd_db_en = 0;
    	IoReg_Write32(VODMA_VODMA_REG_DB_CTRL_reg, vodma_vodma_reg_db_ctrl.regValue);

	if(display == SLR_MAIN_DISPLAY){
		vo_i2rnd_m_flag.regValue = rtd_inl(VODMA_vodma_i2rnd_m_flag_reg);
		//vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en = 1;
		vo_i2rnd_m_flag.i2rnd_m_field_fw = 0;
		vo_i2rnd_m_flag.i2rnd_m_block_free_run = 0;
		vo_i2rnd_m_flag.i2rnd_m_block_sel = 1;
		vo_i2rnd_m_flag.i2rnd_m_field_fw = 0;
		if(input_src == VSC_INPUTSRC_VDEC){//DTV use field free @Crixus 20160805
			vo_i2rnd_m_flag.i2rnd_m_field_free_run = 1;
			vo_i2rnd_m_flag.i2rnd_m_field_sel = 3;
		}
		else{
			vo_i2rnd_m_flag.i2rnd_m_field_free_run = 0;
			vo_i2rnd_m_flag.i2rnd_m_field_sel = (Get_PANEL_VFLIP_ENABLE()? 2: 1);
		}

		vo_i2rnd_m_flag.i2rnd_m_lflag_fw = 0;
		vo_i2rnd_m_flag.i2rnd_m_lflag_free_run = 0;
		vo_i2rnd_m_flag.i2rnd_m_lflag_sel = 1;
		IoReg_Write32(VODMA_vodma_i2rnd_m_flag_reg, vo_i2rnd_m_flag.regValue);
	}
	else if(display == SLR_SUB_DISPLAY){
		vo_i2rnd_s_flag.regValue = rtd_inl(VODMA_vodma_i2rnd_s_flag_reg);
		//vo_i2rnd_s_flag.i2rnd_hw_mask_repeat_frame_s_en = 1;
		vo_i2rnd_s_flag.i2rnd_s_field_fw = 0;
		vo_i2rnd_s_flag.i2rnd_s_block_free_run = 0;
		vo_i2rnd_s_flag.i2rnd_s_block_sel = 1;
		vo_i2rnd_s_flag.i2rnd_s_field_fw = 0;
		if(input_src == VSC_INPUTSRC_VDEC){//DTV use field free @Crixus 20160805
			vo_i2rnd_s_flag.i2rnd_s_field_free_run = 1;
			vo_i2rnd_s_flag.i2rnd_s_field_sel = 3;
		}
		else{
			vo_i2rnd_s_flag.i2rnd_s_field_free_run = 0;
			vo_i2rnd_s_flag.i2rnd_s_field_sel = 1;
		}
		vo_i2rnd_s_flag.i2rnd_s_lflag_fw = 0;
		vo_i2rnd_s_flag.i2rnd_s_lflag_free_run = 0;
		vo_i2rnd_s_flag.i2rnd_s_lflag_sel = 1;
		IoReg_Write32(VODMA_vodma_i2rnd_s_flag_reg, vo_i2rnd_s_flag.regValue);
	}

	//clear write point
	vodma_i2rnd_dma_info.regValue = rtd_inl(VODMA_vodma_i2rnd_dma_info_reg);
	vodma_i2rnd_dma_info.dma_info_rptr_fw_dispm = 0;
	vodma_i2rnd_dma_info.dma_info_rptr_fw_set_dispm = 1;
	vodma_i2rnd_dma_info.dma_info_wptr_fw_dispm = 0;
	vodma_i2rnd_dma_info.dma_info_wptr_fw_set_dispm= 1;
	vodma_i2rnd_dma_info.dma_info_rptr_fw_i3ddma = 0;
	vodma_i2rnd_dma_info.dma_info_rptr_fw_set_i3ddma= 1;
	vodma_i2rnd_dma_info.dma_info_wptr_fw_i3ddma = 0;
	vodma_i2rnd_dma_info.dma_info_wptr_fw_set_i3ddma= 1;
	IoReg_Write32(VODMA_vodma_i2rnd_dma_info_reg, vodma_i2rnd_dma_info.regValue);

	//enable fifo mode and timing mode 1:1
   	vo_i2rnd.regValue = rtd_inl(VODMA_vodma_i2rnd_reg);
	vo_i2rnd.i2rnd_flag_fifo_en = 1;
	vo_i2rnd.i2rnd_src_flag_inv = 0;
	vo_i2rnd.i2rnd_timing_mode = _1_MAIN_1_SUB;
	vo_i2rnd.i2rnd_timing_en = _ENABLE;
	IoReg_Write32(VODMA_vodma_i2rnd_reg, vo_i2rnd.regValue);

	if(display == SLR_MAIN_DISPLAY){
		//h_active = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID);
		//v_active = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN);
	       h_active = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
              v_active = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE);
		interlace = Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_INTERLACE);
		frame_rate = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ)/10;

		//repeat mask enable in interlace source, but DTV does not enable @Crixus 20160803
		vo_i2rnd_m_flag.regValue = rtd_inl(VODMA_vodma_i2rnd_m_flag_reg);
		if((interlace) && (input_src != VSC_INPUTSRC_VDEC))
			vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en = 1;
		else
			vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en = 0;
		IoReg_Write32(VODMA_vodma_i2rnd_m_flag_reg, vo_i2rnd_m_flag.regValue);

		i2rnd_period_update_main = 1;
	}else{
		h_active = Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPH_ACT_WID);
		v_active = Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY, SLR_INPUT_IPV_ACT_LEN);
		interlace = DbgSclrFlgTkr.multiview_sub_interlace_flag;

		//repeat mask enable in interlace source, but DTV does not enable @Crixus 20160803
		vo_i2rnd_s_flag.regValue = rtd_inl(VODMA_vodma_i2rnd_s_flag_reg);
		if((interlace) && (input_src != VSC_INPUTSRC_VDEC))
			vo_i2rnd_s_flag.i2rnd_hw_mask_repeat_frame_s_en = 1;
		else
			vo_i2rnd_s_flag.i2rnd_hw_mask_repeat_frame_s_en = 0;
		IoReg_Write32(VODMA_vodma_i2rnd_s_flag_reg, vo_i2rnd_s_flag.regValue);

		i2rnd_period_update_sub = 1;
	}

	printk(KERN_EMERG"[crixus]h_active = %d, v_active = %d, interlace = %d\n", h_active, v_active, interlace);
	printk(KERN_EMERG"[crixus]input_src = %d\n", input_src);
#if 0
	if(((frame_rate % 10) > 4) || ((frame_rate % 10) == 0) )
		frame_rate = frame_rate / 10;
	else
		frame_rate = (frame_rate / 10) + 1;
#else
	frame_rate = 60;
#endif

	if(h_active >= 3000){
		/*if(v_active >= 1000){//4k2k case
			vo_clock = I2RND_VO_CLOCK_600MHZ;
			fix_htotal = I2RND_VO_FIX_H_TOTAL_4K2K;
			fix_vtotal = I2RND_VO_FIX_V_TOTAL_4K2K;
		}else{//4k1k case
			vo_clock= I2RND_VO_CLOCK_600MHZ;
			fix_htotal = I2RND_VO_FIX_H_TOTAL_4K2K;
			fix_vtotal = I2RND_VO_FIX_V_TOTAL_4K1K;
		}*/
		//over 2k1k case, always uzd to 2k1k
		vo_clock = I2RND_VO_CLOCK_360MHZ;
		fix_htotal = I2RND_VO_FIX_H_TOTAL_2K1K;
		fix_vtotal = I2RND_VO_FIX_V_TOTAL_2K1K_P;
	}else{
		if(interlace == 0){//2k1k case
			vo_clock = I2RND_VO_CLOCK_360MHZ;
			fix_htotal = I2RND_VO_FIX_H_TOTAL_2K1K;
			fix_vtotal = I2RND_VO_FIX_V_TOTAL_2K1K_P;
		}else{//2k0.5k case
			vo_clock = I2RND_VO_CLOCK_180MHZ;
			fix_htotal = I2RND_VO_FIX_H_TOTAL_2K1K;
			fix_vtotal = I2RND_VO_FIX_V_TOTAL_2K1K_I;
		}
	}

	if(display == SLR_MAIN_DISPLAY){
		if((i2rnd_period_update_main == 1) && (i2rnd_period_update_sub == 0) && (interlace == 1)){
			vo_clock_main = vo_clock;
			vo_fix_htotal_main = fix_htotal;
			vo_fix_vtotal_main = fix_vtotal;
			vo_fix_hload_main = fix_htotal;
			vo_frame_rate_main = frame_rate;

			vo_clock_sub = vo_clock_main;
			vo_fix_htotal_sub = vo_fix_htotal_main;
			vo_fix_vtotal_sub = vo_fix_vtotal_main;
			vo_fix_hload_sub = vo_fix_hload_main;
			vo_frame_rate_sub = vo_frame_rate_main;

			refine_sub_period = 1;
		}
		else{
			vo_clock_main = vo_clock;
			vo_fix_htotal_main = fix_htotal;
			vo_fix_vtotal_main = fix_vtotal;
			vo_fix_hload_main = fix_htotal;
			vo_frame_rate_main = frame_rate;
		}
	}
	else{
		vo_clock_sub = vo_clock;
		vo_fix_htotal_sub = fix_htotal;
		vo_fix_vtotal_sub = fix_vtotal;
		vo_fix_hload_sub = fix_htotal;
		vo_frame_rate_sub = frame_rate;
	}

	if(i2rnd_period_update_main == 1){
		printk(KERN_EMERG"@@@@@@@@@@@@@@@@@@[MAIN PERIOD REFINE]@@@@@@@@@@@@@@@@@@@@@\n");
		printk(KERN_EMERG"[%s]main_vo_clock = %d, sub_vo_clock = %d, fix_htotal = %d, fix_vtotal = %d, h_load = %d, frame_rate = %d\n", __FUNCTION__, vo_clock_main, vo_clock_sub, vo_fix_htotal_main, vo_fix_vtotal_main, vo_fix_hload_main, vo_frame_rate_main);

		/*
			mac5p reference xtal clock @Crixus 20170104

			load_max = Tmaster * IMD_cmd * 27 / 1000 * 1.05
			load_min = load_max - 32

			free_period = 27000000/frame rate_main
			load_period = (free_period - 100) * src_ratio - load_max

			Default ratio setting: 0.5
		*/
		period_max = I2RND_TMASTER_TIME * I2RND_REGISTER_NUMBER * 27 / 1000 * 10500 / 10000;//refine new period formula @Crixus 20170504
		period_min = period_max - 32;
		printk(KERN_EMERG"[%s]I2RND_TMASTER_TIME = %d, I2RND_REGISTER_NUMBER = %d\n", __FUNCTION__, I2RND_TMASTER_TIME, I2RND_REGISTER_NUMBER);
		printk(KERN_EMERG"[%s]period_max = %d, period_min = %d\n", __FUNCTION__, period_max, period_min);


		free_period = I2RND_XTAL_CLOCK / vo_frame_rate_main;
		frame_period = (free_period - 100) / 2 - period_max;
		printk(KERN_EMERG"[%s]free_period = %d, vo_frame_rate_main = %d\n", __FUNCTION__, free_period, vo_frame_rate_main);
		printk(KERN_EMERG"[%s]period_load = %d\n", __FUNCTION__, frame_period);

		//VODMA i2rnd period min
	    	vo_i2rnd_m_p_load.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_load_reg);
		vo_i2rnd_m_p_load.i2rnd_m_period_load = period_min;//htotal * period_min;//s0_period;//300;
	    	IoReg_Write32(VODMA_vodma_i2rnd_m_period_load_reg, vo_i2rnd_m_p_load.regValue);

		//VODMA i2rnd period
	    	vo_i2rnd_m_p.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_reg);
		vo_i2rnd_m_p.i2rnd_m_period = frame_period;//htotal * period_load;//s0_period - 300;
	    	IoReg_Write32(VODMA_vodma_i2rnd_m_period_reg, vo_i2rnd_m_p.regValue);

		//VODMA i2rnd period max
		vodma_vodma_i2rnd_m_period_load_dbg.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_load_dbg_reg);
		vodma_vodma_i2rnd_m_period_load_dbg.i2rnd_m_period_load_max = period_max;//htotal * period_max;
		IoReg_Write32(VODMA_vodma_i2rnd_m_period_load_dbg_reg, vodma_vodma_i2rnd_m_period_load_dbg.regValue);
	}


	if((i2rnd_period_update_sub == 1) || (refine_sub_period == 1)){
		printk(KERN_EMERG"@@@@@@@@@@@@@@@@@@[SUB PERIOD REFINE]@@@@@@@@@@@@@@@@@@@@@\n");
		printk(KERN_EMERG"[%s]main vo_clock = %d, sub vo_clock = %d, fix_htotal = %d, fix_vtotal = %d, h_load = %d, frame_rate = %d\n", __FUNCTION__, vo_clock_main, vo_clock_sub, vo_fix_htotal_sub, vo_fix_vtotal_sub, vo_fix_hload_sub, vo_frame_rate_sub);

		period_max = I2RND_TMASTER_TIME * I2RND_REGISTER_NUMBER * 27 / 1000 * 10500 / 10000;
		period_min = period_max - 32;
		printk(KERN_EMERG"[%s]I2RND_TMASTER_TIME = %d, I2RND_REGISTER_NUMBER = %d\n", __FUNCTION__, I2RND_TMASTER_TIME, I2RND_REGISTER_NUMBER);
		printk(KERN_EMERG"[%s]period_max = %d, period_min = %d\n", __FUNCTION__, period_max, period_min);


		free_period = I2RND_XTAL_CLOCK / vo_frame_rate_sub;
		frame_period = (free_period - 100) / 2 - period_max;
		printk(KERN_EMERG"[%s]free_period = %d, vo_frame_rate_main = %d\n", __FUNCTION__, free_period, vo_frame_rate_main);
		printk(KERN_EMERG"[%s]period_load = %d\n", __FUNCTION__, frame_period);

		//sub period min
	    	vo_i2rnd_s_p_load.regValue = rtd_inl(VODMA_vodma_i2rnd_s_period_load_reg);
		vo_i2rnd_s_p_load.i2rnd_s_period_load = period_min;//htotal * period_min;
	    	IoReg_Write32(VODMA_vodma_i2rnd_s_period_load_reg, vo_i2rnd_s_p_load.regValue);

		//sub period load
	    	vo_i2rnd_s_p.regValue = rtd_inl(VODMA_vodma_i2rnd_s_period_reg);
		vo_i2rnd_s_p.i2rnd_s_period = frame_period;//htotal * period_load;
	    	IoReg_Write32(VODMA_vodma_i2rnd_s_period_reg, vo_i2rnd_s_p.regValue);

		//sub period max
		vodma_vodma_i2rnd_s_period_load_dbg.regValue = rtd_inl(VODMA_vodma_i2rnd_s_period_load_dbg_reg);
		vodma_vodma_i2rnd_s_period_load_dbg.i2rnd_s_period_load_max = period_max;//htotal * period_max;
		IoReg_Write32(VODMA_vodma_i2rnd_s_period_load_dbg_reg, vodma_vodma_i2rnd_s_period_load_dbg.regValue);
	}

	refine_sub_period = 0;
	//drvif_scaler_i2rnd_vodma1_flag_fifo_prepare();
}

void drvif_scaler_i2rnd_change_fw_mode(void)
{
	//vodma_vodma_i2rnd_RBUS    vo_i2rnd;
    	vodma_vodma_i2rnd_m_flag_RBUS vo_i2rnd_m_flag;
	//vodma_vodma_i2rnd_dma_info_RBUS vodma_vodma_i2rnd_dma_info;

	vo_i2rnd_m_flag.regValue = rtd_inl(VODMA_vodma_i2rnd_m_flag_reg);
	vo_i2rnd_m_flag.i2rnd_m_field_fw = 0;
	vo_i2rnd_m_flag.i2rnd_m_block_free_run = 0;
	vo_i2rnd_m_flag.i2rnd_m_block_sel = 1;
	vo_i2rnd_m_flag.i2rnd_m_field_fw = 0;
	vo_i2rnd_m_flag.i2rnd_m_field_free_run = 1;
	vo_i2rnd_m_flag.i2rnd_m_field_sel = 3;
	vo_i2rnd_m_flag.i2rnd_m_lflag_fw = 0;
	vo_i2rnd_m_flag.i2rnd_m_lflag_free_run = 0;
	vo_i2rnd_m_flag.i2rnd_m_lflag_sel = 1;
	IoReg_Write32(VODMA_vodma_i2rnd_m_flag_reg, vo_i2rnd_m_flag.regValue);

}

void drvif_scaler_i2rnd_step_size(unsigned int blk_size)
{
    /////  block size = (DMA.num*128/8)*N
    i2rnd_step_size.s0_vo_blk_size = blk_size;
    i2rnd_step_size.s1_vo_blk_size = blk_size;
}

/*
1.Calculate the I2run DMA setting num/length and blk size, Blk num
*/
void drvif_scaler_i2rnd_dma_setting(unsigned int cmd_num, unsigned int blk_size)
{

	/*
	block size = 592 * 8 = 4736 bits
	Queue buffer number = cmd_num = 16
	DMA length = 16

	1. register number = (4736 / 128 * 2) * 16 = 1184
	2. total block size = 4736 * 16 = 75776 bits = (1184 / 2) * 128bits
	3. DMA number = (block size / DMA length) / 64   (unit. 64bits)
	                       = (4736 / 16) / 64
	                       = 4
	*/
	pst_i2rnd_dma_buf_num_RBUS dma_buf_num;
	pst_i2rnd_dma_ctrl_RBUS	dma_ctrl;
	pst_i2rnd_dma_num0_RBUS	dma_num0;
	pst_i2rnd_dma_num1_RBUS	dma_num1;
/*	unsigned int blk_size_mod = 0;

	//align
	blk_size_mod = blk_size % (64 * 2);
	if(blk_size_mod != 0){
		blk_size = blk_size + (64 * 2 - blk_size_mod);
	}
*/
	printk(KERN_EMERG"[crixus]cmd_num = %d, blk_size = %d\n", cmd_num, blk_size);


	drvif_scaler_i2rnd_step_size(blk_size);

	//start address
	IoReg_Write32(PST_I2RND_DMA_ADDR0_reg, i2rnd_st_addr.s0_vo_st_addr);
	IoReg_Write32(PST_I2RND_DMA_ADDR2_reg, i2rnd_st_addr.s1_vo_st_addr);
	//block step
	IoReg_Write32(PST_I2RND_DMA_STEP0_reg, i2rnd_step_size.s0_vo_blk_size);
	IoReg_Write32(PST_I2RND_DMA_STEP2_reg, i2rnd_step_size.s1_vo_blk_size);

	//dma number
	dma_buf_num.regValue = rtd_inl(PST_I2RND_DMA_BUF_NUM_reg);
	dma_buf_num.dma_buffer_num = cmd_num;
	IoReg_Write32(PST_I2RND_DMA_BUF_NUM_reg, dma_buf_num.regValue);

	///////////////////////////////////////////
	// WATER/NUM/LENGTH
	///////////////////////////////////////////
	dma_ctrl.regValue = rtd_inl(PST_I2RND_DMA_CTRL_reg);
	dma_ctrl.dma_wtlvl = I2RND_DMA_WATERLEVEL;
	dma_ctrl.dma_len = I2RND_DMA_LENGTH;
	IoReg_Write32(PST_I2RND_DMA_CTRL_reg, dma_ctrl.regValue);

	dma_num0.regValue = rtd_inl(PST_I2RND_DMA_NUM0_reg);
	dma_num0.dma_num_i2rnd_src0_vo = i2rnd_step_size.s0_vo_blk_size/8/dma_ctrl.dma_len;//burst length 64bits=8bytes
	IoReg_Write32(PST_I2RND_DMA_NUM0_reg, dma_num0.regValue);

	dma_num1.regValue = rtd_inl(PST_I2RND_DMA_NUM1_reg);
	dma_num1.dma_num_i2rnd_src1_vo = i2rnd_step_size.s1_vo_blk_size/8/dma_ctrl.dma_len;//burst length 64bits=8bytes
	IoReg_Write32(PST_I2RND_DMA_NUM1_reg, dma_num1.regValue);

	////////////////////////////////////////
	//  update current status
	////////////////////////////////////////
	i2rnd_st_addr.s0_vo_cur_addr = i2rnd_st_addr.s0_vo_st_addr;
	i2rnd_st_addr.s1_vo_cur_addr = i2rnd_st_addr.s1_vo_st_addr;
	i2rnd_cmd_buf.s0_vo_cur_cmd = 0;
	i2rnd_cmd_buf.s1_vo_cur_cmd = 0;
}

/*
1.send RPC the cmd queue buffer info from SCPU to VCPU
2.record I2run S0,S1 Queue each IP start register setting start point in SCPU
*/
unsigned char	Scaler_i2rnd_setbuffer(void)
{
	unsigned int *pulTemp = NULL;
	unsigned int i=0, ulItemCount = 0;
	I2RND_START_ADDR i2rnd_addr_info={0};
#if 0
	if (i2rnd_st_addr.s0_vo_st_vir_addr == 0) {
		i2rnd_st_addr.s0_vo_st_vir_addr= (unsigned int)dvr_malloc_specific(I2RND_QUEUE_SIZE, GFP_DCU1_FIRST);
		i2rnd_st_addr.s0_vo_st_addr = (unsigned int)dvr_to_phys((void*)i2rnd_st_addr.s0_vo_st_vir_addr);
	}
	if (i2rnd_st_addr.s1_vo_st_vir_addr == 0) {
		i2rnd_st_addr.s1_vo_st_vir_addr = (unsigned int)dvr_malloc_specific(I2RND_QUEUE_SIZE, GFP_DCU1_FIRST);
		i2rnd_st_addr.s1_vo_st_addr = (unsigned int)dvr_to_phys((void*)i2rnd_st_addr.s1_vo_st_vir_addr);
	}
#endif
	if (i2rnd_st_addr.s0_vo_st_addr ==0 || i2rnd_st_addr.s1_vo_st_addr == 0) {
		pr_debug(" i2rnd not alloc memroy\n");
		return 0;
	}
	i2rnd_addr_info.s0_vo_st_addr = i2rnd_st_addr.s0_vo_st_addr;
	i2rnd_addr_info.s1_vo_st_addr = i2rnd_st_addr.s1_vo_st_addr;
	i2rnd_addr_info.i2rnd_enable_addr= i2rnd_st_addr.i2rnd_enable_addr;
	i2rnd_addr_info.write_cmd_num_addr = i2rnd_st_addr.write_cmd_num_addr;
	i2rnd_addr_info.read_cmd_num_addr = i2rnd_st_addr.read_cmd_num_addr;
	i2rnd_addr_info.cmd_buffer_size = i2rnd_st_addr.cmd_buffer_size;
	i2rnd_addr_info.s0_vo_cur_addr =  i2rnd_st_addr.s0_vo_st_addr;
	i2rnd_addr_info.s1_vo_cur_addr =  i2rnd_st_addr.s1_vo_st_addr;
	printk(KERN_EMERG"i2rnd s0_phy : %x ,s1 : %x\n",(i2rnd_st_addr.s0_vo_st_addr),(i2rnd_st_addr.s1_vo_st_addr));
	printk(KERN_EMERG"i2rnd s0 _vir: %x ,s1 : %x\n",(i2rnd_scpu_vir_addr.s0_vo_st_vir_addr),(i2rnd_scpu_vir_addr.s1_vo_st_vir_addr));
	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_I2RND_SET_BUFFER);
	ulItemCount = sizeof(I2RND_START_ADDR) /  sizeof(unsigned int);
	if (pulTemp) {
		memcpy(pulTemp, &i2rnd_addr_info, sizeof(I2RND_START_ADDR));
		for (i = 0; i < ulItemCount; i++)
				pulTemp[i] = htonl(pulTemp[i]);

		if (0 != Scaler_SendRPC(SCALERIOC_I2RND_SET_BUFFER,0,0))
		{
			printk(KERN_EMERG"set buffer address for i2rnd fail !!!\n");
			return 0;

		}
	}

	i2rnd_scpu_vir_addr.s0_sensio_st_vir_addr			= i2rnd_scpu_vir_addr.s0_vo_st_vir_addr			+ VODMA1_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_vgip_st_vir_addr			= i2rnd_scpu_vir_addr.s0_sensio_st_vir_addr		+ MAIN_SENSIO_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_Dither_st_vir_addr			= i2rnd_scpu_vir_addr.s0_vgip_st_vir_addr		+ MAIN_VGIP_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_techcolor_st_vir_addr		= i2rnd_scpu_vir_addr.s0_Dither_st_vir_addr		+ MAIN_DITHER_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_rgb2yuv_st_vir_addr			= i2rnd_scpu_vir_addr.s0_techcolor_st_vir_addr	+ MAIN_TECHCOLOR_REGISTER_NUM * I2RND_REGISTER_SIZE;
	//i2rnd_scpu_vir_addr.s0_pkcri_st_vir_addr			= i2rnd_scpu_vir_addr.s0_rgb2yuv_st_vir_addr		+ RGB2YUV_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_idlti_st_vir_addr				= i2rnd_scpu_vir_addr.s0_rgb2yuv_st_vir_addr		+ RGB2YUV_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_dcti_st_vir_addr				= i2rnd_scpu_vir_addr.s0_idlti_st_vir_addr			+ MAIN_IDLTI_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_histogram_st_vir_addr		= i2rnd_scpu_vir_addr.s0_dcti_st_vir_addr			+ MAIN_DCTI_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_profile1_st_vir_addr			= i2rnd_scpu_vir_addr.s0_histogram_st_vir_addr	+ MAIN_HISTOGRAM_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_dfliter_st_vir_addr			= i2rnd_scpu_vir_addr.s0_profile1_st_vir_addr		+ MAIN_PROFILE1_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_ringfilter_st_vir_addr			= i2rnd_scpu_vir_addr.s0_dfliter_st_vir_addr		+ MAIN_DFILTER_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_dihsd_st_vir_addr			= i2rnd_scpu_vir_addr.s0_ringfilter_st_vir_addr		+ MAIN_RINGFILTER_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_profile2_st_vir_addr			= i2rnd_scpu_vir_addr.s0_dihsd_st_vir_addr		+ MAIN_DIHSD_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_mpegnr_st_vir_addr			= i2rnd_scpu_vir_addr.s0_profile2_st_vir_addr		+ MAIN_PROFILE2_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_dexcxl_st_vir_addr			= i2rnd_scpu_vir_addr.s0_mpegnr_st_vir_addr		+ MAIN_MPEGNR_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_multibamk_st_vir_addr		= i2rnd_scpu_vir_addr.s0_dexcxl_st_vir_addr		+ MAIN_DEXCXL_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_di_st_vir_addr				= i2rnd_scpu_vir_addr.s0_multibamk_st_vir_addr	+ MAIN_MULTIBAMK_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_nr1_st_vir_addr				= i2rnd_scpu_vir_addr.s0_di_st_vir_addr			+ MAIN_DI_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_iedgesmooth_st_vir_addr		= i2rnd_scpu_vir_addr.s0_nr1_st_vir_addr			+ MAIN_NR1_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_uzd_st_vir_addr				= i2rnd_scpu_vir_addr.s0_iedgesmooth_st_vir_addr	+ MAIN_IEDGESMOOTH_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_nr2_st_vir_addr				= i2rnd_scpu_vir_addr.s0_uzd_st_vir_addr			+ MAIN_UZD_REGISTER_NUM * I2RND_REGISTER_SIZE;
	//i2rnd_scpu_vir_addr.s0_decontour_st_vir_addr		= i2rnd_scpu_vir_addr.s0_nr2_st_vir_addr			+ MAIN_NR2_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_bist_st_vir_addr				= i2rnd_scpu_vir_addr.s0_nr2_st_vir_addr	+ MAIN_NR2_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_mcap_st_vir_addr			= i2rnd_scpu_vir_addr.s0_bist_st_vir_addr			+ MAIN_BIST_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s0_vi_mcap_st_vir_addr			= i2rnd_scpu_vir_addr.s0_mcap_st_vir_addr		+ MCAP_REGISTER_NUM * I2RND_REGISTER_SIZE;

	i2rnd_scpu_vir_addr.s1_sensio_st_vir_addr			= i2rnd_scpu_vir_addr.s1_vo_st_vir_addr			+ VODMA1_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_vgip_st_vir_addr			= i2rnd_scpu_vir_addr.s1_sensio_st_vir_addr		+ MAIN_SENSIO_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_Dither_st_vir_addr			= i2rnd_scpu_vir_addr.s1_vgip_st_vir_addr		+ MAIN_VGIP_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_techcolor_st_vir_addr		= i2rnd_scpu_vir_addr.s1_Dither_st_vir_addr		+ MAIN_DITHER_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_rgb2yuv_st_vir_addr			= i2rnd_scpu_vir_addr.s1_techcolor_st_vir_addr	+ MAIN_TECHCOLOR_REGISTER_NUM * I2RND_REGISTER_SIZE;
	//i2rnd_scpu_vir_addr.s1_pkcri_st_vir_addr			= i2rnd_scpu_vir_addr.s1_rgb2yuv_st_vir_addr		+ RGB2YUV_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_idlti_st_vir_addr				= i2rnd_scpu_vir_addr.s1_rgb2yuv_st_vir_addr		+ RGB2YUV_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_dcti_st_vir_addr				= i2rnd_scpu_vir_addr.s1_idlti_st_vir_addr			+ MAIN_IDLTI_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_histogram_st_vir_addr		= i2rnd_scpu_vir_addr.s1_dcti_st_vir_addr			+ MAIN_DCTI_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_profile1_st_vir_addr			= i2rnd_scpu_vir_addr.s1_histogram_st_vir_addr	+ MAIN_HISTOGRAM_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_dfliter_st_vir_addr			= i2rnd_scpu_vir_addr.s1_profile1_st_vir_addr		+ MAIN_PROFILE1_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_ringfilter_st_vir_addr			= i2rnd_scpu_vir_addr.s1_dfliter_st_vir_addr		+ MAIN_DFILTER_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_dihsd_st_vir_addr			= i2rnd_scpu_vir_addr.s1_ringfilter_st_vir_addr		+ MAIN_RINGFILTER_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_profile2_st_vir_addr			= i2rnd_scpu_vir_addr.s1_dihsd_st_vir_addr		+ MAIN_DIHSD_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_mpegnr_st_vir_addr			= i2rnd_scpu_vir_addr.s1_profile2_st_vir_addr		+ MAIN_PROFILE2_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_dexcxl_st_vir_addr			= i2rnd_scpu_vir_addr.s1_mpegnr_st_vir_addr		+ MAIN_MPEGNR_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_multibamk_st_vir_addr		= i2rnd_scpu_vir_addr.s1_dexcxl_st_vir_addr		+ MAIN_DEXCXL_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_di_st_vir_addr				= i2rnd_scpu_vir_addr.s1_multibamk_st_vir_addr	+ MAIN_MULTIBAMK_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_nr1_st_vir_addr				= i2rnd_scpu_vir_addr.s1_di_st_vir_addr			+ MAIN_DI_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_iedgesmooth_st_vir_addr		= i2rnd_scpu_vir_addr.s1_nr1_st_vir_addr			+ MAIN_NR1_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_uzd_st_vir_addr				= i2rnd_scpu_vir_addr.s1_iedgesmooth_st_vir_addr	+ MAIN_IEDGESMOOTH_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_nr2_st_vir_addr				= i2rnd_scpu_vir_addr.s1_uzd_st_vir_addr			+ MAIN_UZD_REGISTER_NUM * I2RND_REGISTER_SIZE;
	//i2rnd_scpu_vir_addr.s1_decontour_st_vir_addr		= i2rnd_scpu_vir_addr.s1_nr2_st_vir_addr			+ MAIN_NR2_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_bist_st_vir_addr				= i2rnd_scpu_vir_addr.s1_nr2_st_vir_addr	+ MAIN_NR2_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_mcap_st_vir_addr			= i2rnd_scpu_vir_addr.s1_bist_st_vir_addr			+ MAIN_BIST_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.s1_vi_mcap_st_vir_addr			= i2rnd_scpu_vir_addr.s1_mcap_st_vir_addr		+ MCAP_REGISTER_NUM * I2RND_REGISTER_SIZE;
	i2rnd_scpu_vir_addr.i2rnd_enable_vir_addr			= i2rnd_scpu_vir_addr.s0_vo_st_vir_addr 		+ i2run_queue_size;
	i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr		= i2rnd_scpu_vir_addr.i2rnd_enable_vir_addr 	+ I2RND_ENABLE_ADDR_SIZE;
	i2rnd_scpu_vir_addr.i2rnd_read_cmd_vir_addr		= i2rnd_scpu_vir_addr.i2rnd_write_cmd_vir_addr 	+ I2RND_WRITE_CMD_ADDR_SIZE;
	i2rnd_scpu_vir_addr.i2rnd_pst_pnt_counter_vir_addr		= i2rnd_scpu_vir_addr.i2rnd_read_cmd_vir_addr 	+ I2RND_READ_CMD_ADDR_SIZE;

	printk(KERN_EMERG"s0_end_addr=%x\n",i2rnd_scpu_vir_addr.s0_vo_st_vir_addr +i2run_queue_size);
	printk(KERN_EMERG"s1_end_addr=%x\n",i2rnd_scpu_vir_addr.s1_vo_st_vir_addr +i2run_queue_size);
	//printk(KERN_EMERG"i2rnd_enable_addr=%x->%x\n",i2rnd_scpu_vir_addr.i2rnd_enable_vir_addr,i2rnd_st_addr.i2rnd_enable_addr);
	return 0;
}

unsigned int Scaler_i2rnd_send_apvr_info(void)
{
	unsigned int *pulTemp = NULL;
	unsigned int i=0, ulItemCount = 0;

	I2RND_APVR_INFO i2rnd_apvr_info;
	i2rnd_apvr_info.i2rnd_enable = Scaler_I2rnd_get_enable();
	i2rnd_get_mcap2_address(&i2rnd_apvr_info.s1_buf_addr1, &i2rnd_apvr_info.s1_buf_addr2, &i2rnd_apvr_info.s1_buf_addr3);

	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_I2RND_SET_APVR_INFO);
	ulItemCount = sizeof(I2RND_APVR_INFO) /  sizeof(unsigned int);
	if (pulTemp) {
		memcpy(pulTemp, &i2rnd_apvr_info, sizeof(I2RND_APVR_INFO));
		for (i = 0; i < ulItemCount; i++)
				pulTemp[i] = htonl(pulTemp[i]);

		if (0 != Scaler_SendRPC(SCALERIOC_I2RND_SET_APVR_INFO,0,0))
		{
			printk(KERN_EMERG"send i2run apvr info fail !!!\n");
			return 0;

		}
	}

	return 0;
}

unsigned int Scaler_i2rnd_IP_register_get_cur_write_addr(unsigned int addr,unsigned char display)
{
	unsigned int cur_addr =0;
	unsigned int register_offset_addr =0;
	if (i2rnd_scpu_vir_addr.s0_vo_st_vir_addr && i2rnd_scpu_vir_addr.s1_vo_st_vir_addr) {
		if (Main_VGIP_register_range(addr)) {
			if (Main_VGIP_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_VGIP_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_vgip_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_vgip_st_vir_addr) + register_offset_addr;
				}
			}
		}else if (VODMA1_register_range(addr)) {
			if (VODMA1_DDR_range(addr)) {
				register_offset_addr = ((addr-VODMA1_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_vo_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_vo_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_SENSIO_register_range(addr)) {
			if (Main_SENSIO_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_SENSIO_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_sensio_st_vir_addr)+ register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_sensio_st_vir_addr)+ register_offset_addr;
				}
			}
		} else if (Main_DITHER_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_DITHER_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_Dither_st_vir_addr)+ register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_Dither_st_vir_addr)+ register_offset_addr;
			}
		} else if (Main_TECHCOLOR_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_TECHCOLOR_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_techcolor_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_techcolor_st_vir_addr) + register_offset_addr;
			}
		} else if (RGB2YUV_register_range(addr)) {
			if (Main_rgb2yuv_DDR_range(addr)) {
				register_offset_addr = ((addr-RGB2YUV_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_rgb2yuv_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_rgb2yuv_st_vir_addr) + register_offset_addr;
				}
			}
		#if 0
		} else if (Main_PKCRI_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_PKCRI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_pkcri_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_pkcri_st_vir_addr) + register_offset_addr;
			}
		#endif
		} else if (Main_IDLTI_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_IDLTI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_idlti_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_idlti_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_DCTI_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_DCTI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_dcti_st_vir_addr)+ register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_dcti_st_vir_addr)+ register_offset_addr;
			}
		} else if (Main_HISTOGRAM_register_range(addr)) {
			if (Main_HISTOGRAM_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_HISTOGRAM_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_histogram_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_histogram_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_PROFILE1_register_range(addr)) {
			if (Main_PROFILE1_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_PROFILE1_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_profile1_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_profile1_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_DFILTER_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_DFILTER_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_dfliter_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_dfliter_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_RINGFILTER_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_RINGFILTER_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_ringfilter_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_ringfilter_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_DIHSD_register_range(addr)) {
			if (Main_DIHSD_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DIHSD_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr = Scaler_i2rnd_cmd_buffer_write_offset_addr( i2rnd_scpu_vir_addr.s1_dihsd_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_dihsd_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_PROFILE2_register_range(addr)) {
			if (Main_PROFILE2_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_PROFILE2_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_profile2_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_profile2_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_MPEGNR_register_range(addr)) {
			if (Main_MPEGNR_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_MPEGNR_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_mpegnr_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_mpegnr_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_DEXCXL_register_range(addr)) {
			if (Main_DEXCXL_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DEXCXL_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_dexcxl_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_dexcxl_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_MULTIBAMK_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_MULTIBAMK_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_multibamk_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_multibamk_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_DI_register_range(addr)) {
			if (Main_DI_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_di_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_di_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_NR1_register_range(addr)) {
			if (Main_NR1_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_NR1_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_nr1_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_nr1_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_IEDGESMOOTH_register_range(addr)) {
			if (Main_IEDGESMOOTH_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_IEDGESMOOTH_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_iedgesmooth_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_iedgesmooth_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_UZD_register_range(addr)) {
			if (Main_UZD_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_UZD_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_uzd_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_uzd_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_NR2_register_range(addr)) {
			if (Main_NR2_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_NR2_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_nr2_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_nr2_st_vir_addr) + register_offset_addr;
				}
			}
		#if 0
		} else if (Main_DECONTOUR_register_range(addr)) {
			if (Main_DECONTOUR_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DECONTOUR_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_decontour_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_decontour_st_vir_addr) + register_offset_addr;
				}
			}
		#endif
		} else if (Main_BIST_register_range(addr)) {
			if (Main_BIST_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_BIST_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_bist_st_vir_addr)+ register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_bist_st_vir_addr)+ register_offset_addr;
				}
			}
		} else if (MCAP_register_range(addr)) {
			if (Main_mcap_DDR_range(addr)) {
				register_offset_addr = ((addr-MCAP_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_mcap_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_mcap_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (MAIN_VI_MCAP_register_range(addr)) {
			if (MAIN_VI_MCAP_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_VI_MCAP_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s1_vi_mcap_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_write_offset_addr(i2rnd_scpu_vir_addr.s0_vi_mcap_st_vir_addr) + register_offset_addr;
				}
			}
		}
	}
	return cur_addr;
}
unsigned int Scaler_i2rnd_IP_register_get_cur_read_addr(unsigned int addr,unsigned char display)
{
	unsigned int cur_addr =0;
	unsigned int register_offset_addr =0;
	if (i2rnd_scpu_vir_addr.s0_vo_st_vir_addr && i2rnd_scpu_vir_addr.s1_vo_st_vir_addr) {
		if (Main_VGIP_register_range(addr)) {
			if (Main_VGIP_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_VGIP_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_vgip_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_vgip_st_vir_addr) + register_offset_addr;
				}
			}
		}else if (VODMA1_register_range(addr)) {
			if (VODMA1_DDR_range(addr)) {
				register_offset_addr = ((addr-VODMA1_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_vo_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_vo_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_SENSIO_register_range(addr)) {
			if (Main_SENSIO_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_SENSIO_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_sensio_st_vir_addr)+ register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_sensio_st_vir_addr)+ register_offset_addr;
				}
			}
		} else if (Main_DITHER_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_DITHER_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_Dither_st_vir_addr)+ register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_Dither_st_vir_addr)+ register_offset_addr;
			}
		} else if (Main_TECHCOLOR_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_TECHCOLOR_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_techcolor_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_techcolor_st_vir_addr) + register_offset_addr;
			}
		} else if (RGB2YUV_register_range(addr)) {
			if (Main_rgb2yuv_DDR_range(addr)) {
				register_offset_addr = ((addr-RGB2YUV_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_rgb2yuv_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_rgb2yuv_st_vir_addr) + register_offset_addr;
				}
			}
#if 0
		} else if (Main_PKCRI_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_PKCRI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_pkcri_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_pkcri_st_vir_addr) + register_offset_addr;
			}
#endif
		} else if (Main_IDLTI_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_IDLTI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_idlti_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_idlti_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_DCTI_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_DCTI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_dcti_st_vir_addr)+ register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_dcti_st_vir_addr)+ register_offset_addr;
			}
		} else if (Main_HISTOGRAM_register_range(addr)) {
			if (Main_HISTOGRAM_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_HISTOGRAM_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_histogram_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_histogram_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_PROFILE1_register_range(addr)) {
			if (Main_PROFILE1_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_PROFILE1_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_profile1_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_profile1_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_DFILTER_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_DFILTER_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_dfliter_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_dfliter_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_RINGFILTER_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_RINGFILTER_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_ringfilter_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_ringfilter_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_DIHSD_register_range(addr)) {
			if (Main_DIHSD_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DIHSD_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr = Scaler_i2rnd_cmd_buffer_read_offset_addr( i2rnd_scpu_vir_addr.s1_dihsd_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_dihsd_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_PROFILE2_register_range(addr)) {
			if (Main_PROFILE2_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_PROFILE2_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_profile2_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_profile2_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_MPEGNR_register_range(addr)) {
			if (Main_MPEGNR_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_MPEGNR_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_mpegnr_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_mpegnr_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_DEXCXL_register_range(addr)) {
			if (Main_DEXCXL_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DEXCXL_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_dexcxl_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_dexcxl_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_MULTIBAMK_register_range(addr)) {
			register_offset_addr = ((addr-MAIN_MULTIBAMK_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
			if (display == I2RND_SUB_S1_TABLE) {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_multibamk_st_vir_addr) + register_offset_addr;
			} else {
				cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_multibamk_st_vir_addr) + register_offset_addr;
			}
		} else if (Main_DI_register_range(addr)) {
			if (Main_DI_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_di_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_di_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_NR1_register_range(addr)) {
			if (Main_NR1_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_NR1_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_nr1_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_nr1_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_IEDGESMOOTH_register_range(addr)) {
			if (Main_IEDGESMOOTH_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_IEDGESMOOTH_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_iedgesmooth_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_iedgesmooth_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_UZD_register_range(addr)) {
			if (Main_UZD_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_UZD_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_uzd_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_uzd_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (Main_NR2_register_range(addr)) {
			if (Main_NR2_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_NR2_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_nr2_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_nr2_st_vir_addr) + register_offset_addr;
				}
			}
#if 0
		} else if (Main_DECONTOUR_register_range(addr)) {
			if (Main_DECONTOUR_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_DECONTOUR_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_decontour_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_decontour_st_vir_addr) + register_offset_addr;
				}
			}
#endif
		} else if (Main_BIST_register_range(addr)) {
			if (Main_BIST_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_BIST_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_bist_st_vir_addr)+ register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_bist_st_vir_addr)+ register_offset_addr;
				}
			}
		} else if (MCAP_register_range(addr)) {
			if (Main_mcap_DDR_range(addr)) {
				register_offset_addr = ((addr-MCAP_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_mcap_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_mcap_st_vir_addr) + register_offset_addr;
				}
			}
		} else if (MAIN_VI_MCAP_register_range(addr)) {
			if (MAIN_VI_MCAP_DDR_range(addr)) {
				register_offset_addr = ((addr-MAIN_VI_MCAP_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
				if (display == I2RND_SUB_S1_TABLE) {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s1_vi_mcap_st_vir_addr) + register_offset_addr;
				} else {
					cur_addr =  Scaler_i2rnd_cmd_buffer_read_offset_addr(i2rnd_scpu_vir_addr.s0_vi_mcap_st_vir_addr) + register_offset_addr;
				}
			}
		}
	}
	return cur_addr;
}

void i2rnd_debug(void){
	memcpy((unsigned char *)i2rnd_scpu_vir_addr.s0_vo_st_vir_addr, (unsigned char *)i2rnd_scpu_vir_addr.s1_vo_st_vir_addr, sizeof(unsigned char) * i2run_queue_size);
}
extern void i2rnd_default_allocate_mcap1(void);
extern void i2rnd_default_allocate_mcap2(void);
void i2rnd_default_register_setting(void){
	di_im_di_active_window_control_RBUS di_im_di_active_window_control_reg;

	/*===============s0 table=====================*/
	Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);

	//pre-allocate memory for M-cap1
	i2rnd_default_allocate_mcap1();

	//pre-set DI start & boundary
	i2rnd_default_allocate_DI1();

	//DI default size setting for sub start address sample issue @Crixus 20160725
	di_im_di_active_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
	di_im_di_active_window_control_reg.hsize = 0xa;
	di_im_di_active_window_control_reg.vsize = 0xa;
	IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, di_im_di_active_window_control_reg.regValue);

	/*===============s1 table=====================*/
	Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);

	//pre-allocate memory for M-cap2
	i2rnd_default_allocate_mcap2();

	//pre-set DI start & boundary
	i2rnd_default_allocate_DI2();

	//DI default size setting for sub start address sample issue @Crixus 20160725
	di_im_di_active_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
	di_im_di_active_window_control_reg.hsize = 0xa;
	di_im_di_active_window_control_reg.vsize = 0xa;
	IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, di_im_di_active_window_control_reg.regValue);

	/*===============End=====================*/
	Scaler_I2rnd_set_display(I2RND_TABLE_OFF);

	//DI default size setting for sub start address sample issue @Crixus 20160725
	di_im_di_active_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
	di_im_di_active_window_control_reg.hsize = 0xb;
	di_im_di_active_window_control_reg.vsize = 0xb;
	IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, di_im_di_active_window_control_reg.regValue);

	//DI default size setting for sub start address sample issue @Crixus 20160725
	//DI hw detect does not write to cmd buf
	fw_scalerip_set_di_size_change_hw_detect(_ENABLE);//enable hw detect

	//frank@0815 test
	Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
}

//a register include i2rnd and non-i2rnd function
void i2rnd_group3_s0_to_s1_register_sync(void){
	/*Please add the group 3 register here*/

	//step 1. Read value from s0 table
	Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);

	//step 2. Read value from s1 table
	Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);

	//step 3. Sync the non-i2rnd function from s1 to s0

	//step 4. Change to original table selection
	Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
}
void Scaler_i2rnd_set_write_point(void)
{
	if (Scaler_I2rnd_get_display() == I2RND_MAIN_S0_TABLE) {
		pst_i2rnd_dma_wrt_pnt1_RBUS wrt_pnt1_reg;
		wrt_pnt1_reg.regValue = rtd_inl(PST_I2RND_DMA_WRT_PNT1_reg);
		wrt_pnt1_reg.i2rnd_src0_vo_write_pnt = Scaler_I2rnd_get_write_cmd_num();
		rtd_outl(PST_I2RND_DMA_WRT_PNT1_reg, wrt_pnt1_reg.regValue);
	}
	#if 0
	} else if (Scaler_I2rnd_get_display() == I2RND_SUB_S1_TABLE) {
		pst_i2rnd_dma_wrt_pnt0_RBUS wrt_pnt0_reg;
		wrt_pnt0_reg.regValue = rtd_inl(PST_I2RND_DMA_WRT_PNT0_reg);
		wrt_pnt0_reg.i2rnd_src1_vo_write_pnt = Scaler_I2rnd_get_write_cmd_num();
		rtd_outl(PST_I2RND_DMA_WRT_PNT0_reg, wrt_pnt0_reg.regValue);
	}
	#endif
}
unsigned char Scaler_i2rnd_get_write_point(void)
{
	if (Scaler_I2rnd_get_display() == I2RND_MAIN_S0_TABLE) {
		pst_i2rnd_dma_wrt_pnt1_RBUS wrt_pnt1_reg;
		wrt_pnt1_reg.regValue = rtd_inl(PST_I2RND_DMA_WRT_PNT1_reg);
		return wrt_pnt1_reg.i2rnd_src0_vo_write_pnt;
	} else if (Scaler_I2rnd_get_display() == I2RND_SUB_S1_TABLE) {
		pst_i2rnd_dma_wrt_pnt0_RBUS wrt_pnt0_reg;
		wrt_pnt0_reg.regValue = rtd_inl(PST_I2RND_DMA_WRT_PNT0_reg);
		return wrt_pnt0_reg.i2rnd_src1_vo_write_pnt;
	} else {
		return 0;
	}
}
unsigned char Scaler_i2rnd_get_read_point(void)
{
	if (Scaler_I2rnd_get_display() == I2RND_MAIN_S0_TABLE) {
		pst_i2rnd_dma_read_pnt1_RBUS read_pnt1_reg;
		read_pnt1_reg.regValue = rtd_inl(PST_I2RND_DMA_READ_PNT1_reg);
		return read_pnt1_reg.i2rnd_src0_vo_read_pnt;
	} else if (Scaler_I2rnd_get_display() == I2RND_SUB_S1_TABLE) {
		pst_i2rnd_dma_read_pnt0_RBUS read_pnt0_reg;
		read_pnt0_reg.regValue = rtd_inl(PST_I2RND_DMA_READ_PNT0_reg);
		return read_pnt0_reg.i2rnd_src1_vo_read_pnt;
	} else {
		return 0;
	}
}

void set_i2rnd_pst_write_pnt_counter(unsigned int cnt)
{
	if (i2rnd_scpu_vir_addr.i2rnd_pst_pnt_counter_vir_addr) {
		*(volatile unsigned char *)i2rnd_scpu_vir_addr.i2rnd_pst_pnt_counter_vir_addr = cnt;
	}
}

unsigned int get_i2rnd_pst_write_pnt_counter(void)
{
	if (i2rnd_scpu_vir_addr.i2rnd_pst_pnt_counter_vir_addr) {
		return (*(volatile unsigned char *)i2rnd_scpu_vir_addr.i2rnd_pst_pnt_counter_vir_addr);
	} else {
		return 0;
	}
}

void i2rnd_group3_s1_to_s0_register_sync(void){
	/*Please add the group 3 register here*/
	//0xb80272c8 MDOMAIN_CAP_Capture_byte_swap_reg
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg_s0;
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg_s1;

	//step 1. Read value from s1 table
	Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);
	capture_byte_swap_reg_s1.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	//printk(KERN_EMERG"[%s]capture_byte_swap_reg_s1.regValue = %x\n", __FUNCTION__, capture_byte_swap_reg_s1.regValue);

	//step 2. Read value from s0 table
	Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
	capture_byte_swap_reg_s0.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	//printk(KERN_EMERG"[%s]capture_byte_swap_reg_s0.regValue = %x\n", __FUNCTION__, capture_byte_swap_reg_s0.regValue);


	//step 3. Sync the non-i2rnd function from s1 to s0
	capture_byte_swap_reg_s0.in2_1byte_swap = capture_byte_swap_reg_s1.in2_1byte_swap;
	capture_byte_swap_reg_s0.in2_2byte_swap = capture_byte_swap_reg_s1.in2_2byte_swap;
	capture_byte_swap_reg_s0.in2_4byte_swap = capture_byte_swap_reg_s1.in2_4byte_swap;
	capture_byte_swap_reg_s0.in2_8byte_swap = capture_byte_swap_reg_s1.in2_8byte_swap;
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg_s0.regValue);

	//step 4. Change to original table selection
	Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);
}

void i2rnd_di_size_toggle(void){
	di_im_di_active_window_control_RBUS di_im_di_active_window_control_reg;
	vgip_vgip_chn1_lc_RBUS vgip_vgip_chn1_lc_reg;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_vgip_chn1_act_vsta_length_reg;

	unsigned int v_start = 0;
	unsigned int timeout_cnt = 0x7ffff;
	//unsigned int line_cnt1, line_cnt2, line_cnt3;
	//unsigned int di_value1 = 0, di_value2 = 0;

	//get vgip v_start
	vgip_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
	v_start = vgip_vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta;

	//DI default size setting for sub start address sample issue @Crixus 20160725
	di_im_di_active_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
	di_im_di_active_window_control_reg.hsize = 0xa;
	di_im_di_active_window_control_reg.vsize = 0xa;

	//wait active start to modify the cmd buf because the cmd buf only access in porch @Crixus 20160803
	//wait first Vsync
	while(timeout_cnt--){
		vgip_vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
		if(vgip_vgip_chn1_lc_reg.ch1_line_cnt == v_start){
			//line_cnt1= vgip_vgip_chn1_lc_reg.ch1_line_cnt;
			break;
		}
	}

	//line_cnt1 = vgip_vgip_chn1_lc_reg.ch1_line_cnt;
	IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, di_im_di_active_window_control_reg.regValue);

	//wait Vsync to make sure the cmd buf already write to register.
	//wait second Vsync because there are two Vsync which one is main, one is sub. Need to wait two Vsync. @Crixus 20160811
	timeout_cnt = 0x7ffff;
	while(timeout_cnt--){
		vgip_vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
		if(vgip_vgip_chn1_lc_reg.ch1_line_cnt == 2){
			//line_cnt2 = vgip_vgip_chn1_lc_reg.ch1_line_cnt;
			break;
		}
	}

	timeout_cnt = 0x7ffff;
	while(timeout_cnt--){
		vgip_vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
		if(vgip_vgip_chn1_lc_reg.ch1_line_cnt == 1){
			//line_cnt2 = vgip_vgip_chn1_lc_reg.ch1_line_cnt;
			break;
		}
	}

	di_im_di_active_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
	di_im_di_active_window_control_reg.hsize = Scaler_DispGetInputInfo(SLR_INPUT_DI_WID);// Width;
	di_im_di_active_window_control_reg.vsize = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN); // Height;

	//wait active start to modify the cmd buf because the cmd buf only access in porch @Crixus 20160803
	//WaitFor_IEN_START1();
	timeout_cnt = 0x7ffff;
	while(timeout_cnt--){
		vgip_vgip_chn1_lc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_LC_reg);
		if(vgip_vgip_chn1_lc_reg.ch1_line_cnt == v_start){
		//	line_cnt3 = vgip_vgip_chn1_lc_reg.ch1_line_cnt;
			break;
		}
	}
	IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, di_im_di_active_window_control_reg.regValue);

}

void i2rnd_send_table_idx(unsigned char index){
	int ret = 0;

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_I2RND_SEND_TABLE_IDX, index, 1))){
		pr_debug("[I2RND]ret=%d, SCALERIOC_I2RND_SEND_TABLE_IDX RPC fail !!!\n", ret);
	}

}

void Scaler_i2rnd_buffer_copy(void)
{
	unsigned char i=0;
	for (i=1;i<(I2RND_CMD_NUMBER+1);i++) {
		unsigned int curr_i2rnd_s0_write_buffer_addr=i2rnd_scpu_vir_addr.s0_vo_st_vir_addr+i*i2rnd_st_addr.cmd_buffer_size;
		unsigned int curr_i2rnd_s1_write_buffer_addr=i2rnd_scpu_vir_addr.s1_vo_st_vir_addr+i*i2rnd_st_addr.cmd_buffer_size;
		memcpy((unsigned char *)curr_i2rnd_s0_write_buffer_addr, (unsigned char *)i2rnd_scpu_vir_addr.s0_vo_st_vir_addr, sizeof(unsigned char) * i2rnd_st_addr.cmd_buffer_size);
		memcpy((unsigned char *)curr_i2rnd_s1_write_buffer_addr, (unsigned char *)i2rnd_scpu_vir_addr.s1_vo_st_vir_addr, sizeof(unsigned char) * i2rnd_st_addr.cmd_buffer_size);
	}
}

#if 0 //no using now
void i2rnd_di_control_reg_change_valid_index(unsigned char enable, unsigned char display){
	//DI special case checking, DI disable => DI setting => DI enable @Crixus 20160725
	unsigned int addr =0;
	unsigned int cur_addr =0;
	unsigned int tmp_addr = 0;
	unsigned int register_offset_addr =0;


	printk(KERN_EMERG"[%s]display = %d, enable = %d\n", __FUNCTION__, display, enable);

	addr = DI_IM_DI_CONTROL_reg;
	register_offset_addr = ((addr-MAIN_DI_START_REGISTER) /REGISTER_VALUE_SIZE) *I2RND_REGISTER_SIZE;
	//get virtual address
	if (display == I2RND_SUB_S1_TABLE) {
		cur_addr =	i2rnd_scpu_vir_addr.s1_di_st_vir_addr + register_offset_addr;
	} else {
		cur_addr =	i2rnd_scpu_vir_addr.s0_di_st_vir_addr + register_offset_addr;
	}

	//change the valid index
	if(enable == _DISABLE){
		tmp_addr =((addr>>2)&0x000fffff)|0x00000000;
	}
	else{
		tmp_addr =((addr>>2)&0x000fffff)|0x80000000;
	}

	//write to table
	cur_addr-=4;
	*(volatile unsigned int *)(cur_addr) = __bswap_32(tmp_addr);

	WaitFor_IVS1();
}
#endif

#endif

#ifdef CONFIG_I2RND_B05_ENABLE

/*=======================b05==================================*/
void drvif_scaler_i2rnd_b05_uninitial(void)
{
	 if (Scaler_I2rnd_b05_get_enable()){
			memset((unsigned char *)i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr, 0, sizeof(unsigned char) * i2run_b05_allocate_size);
			drvif_scaler_i2rnd_b05_top_ctrl(_DISABLE);
			printk("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~in_b05_uninitial\n");
			return;
   	     //free memory
	//      if((i2rnd_b05_st_addr.s0_vo_st_addr != 0) && (i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr != 0))
	//      {       dvr_free((void *)i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr);
	//              printk("i2rnd_b05_free_memory\n");
	//              i2rnd_b05_st_addr.s0_vo_st_addr = 0;
	//              i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr = 0;
	//              i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr = 0;
	//              printk("i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr1 =%x\n",i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr);
	//      }
	 }
}


void drvif_scaler_i2rnd_b05_initial(void)
{
        //printk("i2rnd_i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr = %x\n", i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr);
        //unsigned int b05_cache_addr;
        unsigned int i2run_b05_blk_size = 0;            //17*17*40 (34+1+5)= 8440
        unsigned int b05_blk_size_mod = 0;
     //   unsigned int i2run_b05_allocate_size = 0;

        i2run_b05_blk_size = I2RND_b05_BLOCK_SIZE;
        b05_blk_size_mod = i2run_b05_blk_size % (I2RND_DMA_LENGTH * 8);

        if(b05_blk_size_mod != 0) {
                i2run_b05_blk_size = i2run_b05_blk_size + (I2RND_DMA_LENGTH * 8 - b05_blk_size_mod);
        }

        i2run_b05_queue_size = i2run_b05_blk_size * (I2RND_B05_CMD_NUMBER + 1);
        i2run_b05_allocate_size = i2run_b05_queue_size + I2RND_INFO_SIZE;

        printk("i2run_b05_blk_size = %d,i2run_b05_blk_size2=%d,i2run_b05_queue_size= %d,i2run_b05_allocate_size = %d\n", I2RND_b05_BLOCK_SIZE, i2run_b05_blk_size, i2run_b05_queue_size, i2run_b05_allocate_size);
        printk(KERN_EMERG"[%s]i2run_b05_allocate_size = %d\n", __FUNCTION__, i2run_b05_allocate_size);

        //share memory allocation
        //vo_rtd_xxx_get_memory(i2run_b05_blk_size);
        printk(KERN_EMERG"[%s]set_i2rnd_i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr = %x\n", __FUNCTION__, i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr);
        if (i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr == 0) {
                b05_cache_addr = (unsigned int)dvr_malloc_uncached_specific(i2run_b05_allocate_size, GFP_DCU1_FIRST, (void*) & (i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr));
                i2rnd_b05_st_addr.s0_vo_st_addr = (unsigned int)dvr_to_phys((void*)b05_cache_addr);
                i2rnd_b05_st_addr.i2rnd_enable_addr = i2rnd_b05_st_addr.s0_vo_st_addr + i2run_b05_queue_size;
                memset((unsigned char *)i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr, 0, sizeof(unsigned char) * i2run_b05_allocate_size);
       //         printk("i2rnd_b05_cache_addr=%x\n", b05_cache_addr);
               // i2run_b05_test += 1;
        }
        i2rnd_b05_st_addr.cmd_buffer_size = i2run_b05_blk_size;

        printk("i2rnd_b05_cache_addr = %x\n", b05_cache_addr);
       // printk("i2rnd_i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr = %x\n", i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr);

        if(i2rnd_b05_st_addr.s0_vo_st_addr == 0) {
                pr_debug("[I2RND]malloc i2rnd buffer fail .......................................\n");
                printk(KERN_EMERG"[%s]i2rnd_i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr = %x\n", __FUNCTION__, i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr);
                return;
        }

        i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr                   = i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr             + i2run_b05_queue_size;
        i2rnd_b05_scpu_vir_addr.i2rnd_write_cmd_vir_addr                = i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr         + I2RND_ENABLE_ADDR_SIZE;
        i2rnd_b05_scpu_vir_addr.i2rnd_read_cmd_vir_addr         = i2rnd_b05_scpu_vir_addr.i2rnd_write_cmd_vir_addr      + I2RND_WRITE_CMD_ADDR_SIZE;
        printk(KERN_EMERG"b05_s0_end_addr=%x\n", i2rnd_scpu_vir_addr.s0_vo_st_vir_addr + i2run_b05_allocate_size);


        //i2rnd_b05 dma setting
        drvif_scaler_i2rnd_b05_dma_setting(I2RND_B05_CMD_NUMBER, i2run_b05_blk_size);

        //default period setting
        vodma_vodma_i2rnd_m_period_load_RBUS  vo_i2rnd_m_p_load;
        vodma_vodma_i2rnd_m_period_RBUS  vo_i2rnd_m_p;
        vodma_vodma_reg_db_ctrl_RBUS vodma_vodma_reg_db_ctrl;
        vodma_vodma_i2rnd_m_period_load_dbg_RBUS vodma_vodma_i2rnd_m_period_load_dbg;


        //disable double buffer
        vodma_vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
        vodma_vodma_reg_db_ctrl.i2rnd_db_en = 0;
        IoReg_Write32(VODMA_VODMA_REG_DB_CTRL_reg, vodma_vodma_reg_db_ctrl.regValue);

}



void drvif_scaler_i2rnd_b05_dma_setting(unsigned int cmd_num, unsigned int blk_size)
{
        pst_i2rnd_dma_buf_num_RBUS dma_buf_num;
        pst_i2rnd_dma_ctrl_RBUS     dma_ctrl;
        pst_i2rnd_dma_num0_RBUS     dma_num0;
        //pst_i2rnd_dma_num1_RBUS     dma_num1;	//to do: spec change 20161203
        printk(KERN_EMERG"cmd_num = %d, blk_size = %d\n", cmd_num, blk_size);


        i2rnd_b05_step_size.s0_vo_blk_size = blk_size;


        //start address
        IoReg_Write32(PST_I2RND_DMA_ADDR0_reg, i2rnd_b05_st_addr.s0_vo_st_addr);
        //block step
        IoReg_Write32(PST_I2RND_DMA_STEP0_reg, i2rnd_b05_step_size.s0_vo_blk_size);
        //dma number
        dma_buf_num.regValue = rtd_inl(PST_I2RND_DMA_BUF_NUM_reg);
        dma_buf_num.dma_buffer_num = cmd_num;
        IoReg_Write32(PST_I2RND_DMA_BUF_NUM_reg, dma_buf_num.regValue);

        ///////////////////////////////////////////
        // WATER/NUM/LENGTH
        ///////////////////////////////////////////
        dma_ctrl.regValue = rtd_inl(PST_I2RND_DMA_CTRL_reg);
        dma_ctrl.dma_wtlvl = I2RND_B05_DMA_WATERLEVEL;
        dma_ctrl.dma_len = I2RND_B05_DMA_LENGTH;
        IoReg_Write32(PST_I2RND_DMA_CTRL_reg, dma_ctrl.regValue);

        dma_num0.regValue = rtd_inl(PST_I2RND_DMA_NUM0_reg);
        dma_num0.dma_num_i2rnd_src0_vo = i2rnd_b05_step_size.s0_vo_blk_size * 8 / 64 / dma_ctrl.dma_len;
        IoReg_Write32(PST_I2RND_DMA_NUM0_reg, dma_num0.regValue);

        ////////////////////////////////////////
        //  update current status
        ////////////////////////////////////////
        i2rnd_b05_st_addr.s0_vo_cur_addr = i2rnd_b05_st_addr.s0_vo_st_addr;
        i2rnd_b05_cmd_buf.s0_vo_cur_cmd = 0;
}


void drvif_scaler_i2rnd_b05_top_ctrl(bool i2rnd_en)
{
        vodma_vodma_i2rnd_RBUS    vo_i2rnd;
        pst_i2rnd_top_ctrl_RBUS   top_ctrl;
		vodma_vodma_reg_db_ctrl_RBUS vodma_vodma_reg_db_ctrl;

        vodma_vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
        vodma_vodma_reg_db_ctrl.i2rnd_db_en = 0;
        IoReg_Write32(VODMA_VODMA_REG_DB_CTRL_reg, vodma_vodma_reg_db_ctrl.regValue);

        if(i2rnd_en) {
				top_ctrl.regValue = rtd_inl(PST_I2RND_TOP_CTRL_reg);
				top_ctrl.i2rnd_en = i2rnd_en;
				IoReg_Write32(PST_I2RND_TOP_CTRL_reg, top_ctrl.regValue);

				vo_i2rnd.regValue = rtd_inl(VODMA_vodma_i2rnd_reg);
				vo_i2rnd.i2rnd_flag_fifo_en = 1;
				vo_i2rnd.i2rnd_src_flag_inv = 0;
				vo_i2rnd.i2rnd_timing_mode = _1_MAIN_0_SUB;
				vo_i2rnd.i2rnd_timing_en = _ENABLE;
				IoReg_Write32(VODMA_vodma_i2rnd_reg, vo_i2rnd.regValue);
        } else {
                vo_i2rnd.regValue = rtd_inl(VODMA_vodma_i2rnd_reg);
                vo_i2rnd.i2rnd_timing_mode = _1_MAIN_0_SUB;
                IoReg_Write32(VODMA_vodma_i2rnd_reg, vo_i2rnd.regValue);
                vo_i2rnd.i2rnd_timing_en = 0;
                IoReg_Write32(VODMA_vodma_i2rnd_reg, vo_i2rnd.regValue);
                top_ctrl.regValue = rtd_inl(PST_I2RND_TOP_CTRL_reg);
                top_ctrl.i2rnd_en = i2rnd_en;
                IoReg_Write32(PST_I2RND_TOP_CTRL_reg, top_ctrl.regValue);
        }
}

void Scaler_I2rnd_b05_handler(void)
{
        drvif_scaler_i2rnd_b05_top_ctrl(Scaler_I2rnd_b05_get_enable());
 //       printk("^^^^^^^^^^^^^_i2rnd_b05_top_ctrl_^^^^^^^^^^^^^^^^");
}


unsigned char Scaler_I2rnd_b05_get_enable(void)
{
        if (i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr) {
                return (*(volatile unsigned char *)(i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr));
        } else {
      //          printk("^^^^^^^^^^^^^_i2rnd_b05_get_enable_faile_^^^^^^^^^^^^^");
                return 0;
        }
}


void Scaler_I2rnd_b05_set_enable(unsigned char enable)
{
        //printk("i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr1 =%x,__%d\n",i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr,enable);
        if (i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr) {
                *(volatile unsigned char *)(i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr) = enable;
        }

}

void Scaler_i2rnd_b05_buffer_copy(void)
{
	unsigned char i=0;
	for (i=1;i<(I2RND_B05_CMD_NUMBER+1);i++) {
		unsigned int curr_i2rnd_b05_write_buffer_addr=i2rnd_scpu_vir_addr.s0_vo_st_vir_addr+i*i2rnd_st_addr.cmd_buffer_size;
		memcpy((unsigned char *)curr_i2rnd_b05_write_buffer_addr, (unsigned char *)i2rnd_scpu_vir_addr.s0_vo_st_vir_addr, sizeof(unsigned char) * i2rnd_st_addr.cmd_buffer_size);

	}

}

void drvif_scaler_i2rnd_b05_vodma_setting(unsigned char display)
{
	vodma_vodma_i2rnd_RBUS	  vo_i2rnd;
	vodma_vodma_i2rnd_m_flag_RBUS vo_i2rnd_m_flag;
	vodma_vodma_i2rnd_s_flag_RBUS vo_i2rnd_s_flag;
	vodma_vodma_i2rnd_m_period_load_RBUS  vo_i2rnd_m_p_load;
	vodma_vodma_i2rnd_m_period_RBUS  vo_i2rnd_m_p;
	vodma_vodma_i2rnd_s_period_load_RBUS  vo_i2rnd_s_p_load;
	vodma_vodma_i2rnd_s_period_RBUS  vo_i2rnd_s_p;
	vodma_vodma_reg_db_ctrl_RBUS vodma_vodma_reg_db_ctrl;
	vodma_vodma_i2rnd_m_period_load_dbg_RBUS vodma_vodma_i2rnd_m_period_load_dbg;
	vodma_vodma_i2rnd_s_period_load_dbg_RBUS vodma_vodma_i2rnd_s_period_load_dbg;
	vodma_vodma_i2rnd_dma_info_RBUS vodma_i2rnd_dma_info;
	unsigned int period_load = 0, period_time = 0, period_load_max = 0;
	//unsigned int h_active = 0, v_active = 0, interlace = 0;
	//unsigned int h_start = 0, v_start = 0;


	//i2rnd period
	unsigned int h_load = 0;
	unsigned int fix_htotal = 0;
	unsigned int vo_clock = 0;
	unsigned int frame_rate = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ);
	unsigned int fix_vtotal = 0;
	unsigned int v_load = 0;

	unsigned int v_b05_load = 0;
	unsigned int vo_fix_htotal = 0;
	unsigned int vo_fix_vtotal = 0;

	//disable double buffer
	vodma_vodma_reg_db_ctrl.regValue = rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
	vodma_vodma_reg_db_ctrl.i2rnd_db_en = 0;
	IoReg_Write32(VODMA_VODMA_REG_DB_CTRL_reg, vodma_vodma_reg_db_ctrl.regValue);


	vo_i2rnd_m_flag.regValue = rtd_inl(VODMA_vodma_i2rnd_m_flag_reg);
	vo_i2rnd_m_flag.i2rnd_m_field_fw = 0;
	vo_i2rnd_m_flag.i2rnd_m_block_free_run = 0;
	vo_i2rnd_m_flag.i2rnd_m_field_fw = 0;

	vo_i2rnd_m_flag.i2rnd_m_field_free_run = 0;
        vo_i2rnd_m_flag.i2rnd_m_field_sel = (Get_PANEL_VFLIP_ENABLE()? 2: 1);

	vo_i2rnd_m_flag.i2rnd_m_lflag_fw = 0;
	vo_i2rnd_m_flag.i2rnd_m_lflag_free_run = 0;
	vo_i2rnd_m_flag.i2rnd_m_lflag_sel = 0;

	vo_i2rnd_m_flag.i2rnd_m_block_sel = 1;
	vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en = 0;
	IoReg_Write32(VODMA_vodma_i2rnd_m_flag_reg, vo_i2rnd_m_flag.regValue);

	//h_active = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
	//v_active = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE);
	//interlace = Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE);
	//frame_rate = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ);
	//v_start = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_STA_PRE);
	//h_start = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_STA_PRE);
	i2rnd_period_update_main = 1;

	if( ((frame_rate % 10) == 0) )
			frame_rate = frame_rate / 10;
	else
			frame_rate = (frame_rate / 10) + 1;


	SLR_VOINFO* voinfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
	vo_fix_htotal = voinfo->h_total;
	vo_fix_vtotal = voinfo->v_total;

	vo_clock = voinfo->pixel_clk / 1000000;
	fix_htotal = I2RND_VO_FIX_H_TOTAL_4K2K;
	fix_vtotal = I2RND_VO_FIX_V_TOTAL_4K2K;

	printk("vo_clock=%d\n",vo_clock);


	if(display == SLR_MAIN_DISPLAY) {
			vo_clock_main = vo_clock;
			vo_fix_htotal_main = fix_htotal;
			vo_fix_vtotal_main = fix_vtotal;
			vo_fix_hload_main = fix_htotal;
			vo_frame_rate_main = frame_rate;
	} else {
			vo_clock_sub = vo_clock;
			vo_fix_htotal_sub = fix_htotal;
			vo_fix_vtotal_sub = fix_vtotal;
			vo_fix_hload_sub = fix_htotal;
			vo_frame_rate_sub = frame_rate;
	}

	if(i2rnd_period_update_main == 1) {
		  printk(KERN_EMERG"@@@@@@@@@@@@@@@@@@[MAIN PERIOD REFINE]@@@@@@@@@@@@@@@@@@@@@\n");
		  printk(KERN_EMERG"[%s]main_vo_clock = %d, sub_vo_clock = %d, fix_htotal = %d, fix_vtotal = %d, h_load = %d, frame_rate = %d\n", __FUNCTION__, vo_clock_main, vo_clock_sub, vo_fix_htotal_main, vo_fix_vtotal_main, vo_fix_hload_main, vo_frame_rate_main);

		  v_b05_load = 1000000*vo_clock_main/frame_rate/vo_fix_htotal_main*1-vo_fix_vtotal_main;

		  printk("v_b05_load = %d\n",v_b05_load);
		  printk("vo_fix_htotal_main = %d\n",vo_fix_htotal_main);
		  printk("vo_fix_vtotal_main = %d\n",vo_fix_vtotal_main);


		  period_time = vo_fix_htotal_main * vo_fix_vtotal_main;
		  period_load = (v_b05_load * vo_fix_htotal_main) - 2048;
		  period_load_max = period_load + 1024;


		  printk(KERN_EMERG"[%s]period_load = %d\n", __FUNCTION__, period_load);
		  printk(KERN_EMERG"[%s]period_time = %d\n", __FUNCTION__, period_time);
		  printk(KERN_EMERG"[%s]period_load_max = %d\n", __FUNCTION__, period_load_max);

		  //VODMA i2rnd period_load
		  vo_i2rnd_m_p_load.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_load_reg);
		  vo_i2rnd_m_p_load.i2rnd_m_period_load = period_load;
		  IoReg_Write32(VODMA_vodma_i2rnd_m_period_load_reg, vo_i2rnd_m_p_load.regValue);

		  //VODMA i2rnd period
		  vo_i2rnd_m_p.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_reg);
		  vo_i2rnd_m_p.i2rnd_m_period = period_time;
		  IoReg_Write32(VODMA_vodma_i2rnd_m_period_reg, vo_i2rnd_m_p.regValue);

		  //VODMA i2rnd period_load_max
		  vodma_vodma_i2rnd_m_period_load_dbg.regValue = rtd_inl(VODMA_vodma_i2rnd_m_period_load_dbg_reg);
		  vodma_vodma_i2rnd_m_period_load_dbg.i2rnd_m_period_load_max = period_load_max;//htotal * period_max;

		  vodma_vodma_i2rnd_m_period_load_dbg.i2rnd_period_load_max_measure_en = 1;
		  vodma_vodma_i2rnd_m_period_load_dbg.i2rnd_period_load_max_dbg_en = 1;

		  IoReg_Write32(VODMA_vodma_i2rnd_m_period_load_dbg_reg, vodma_vodma_i2rnd_m_period_load_dbg.regValue);

	}

}



void set_b05_var(void)
{
        i2run_b05_addr = 0;

}

void vo_b05_debug(void)
{
        printk("i2run_b05_addr: %x\n", i2run_b05_addr);
        printk("b05_write_ddr_add: %x\n", (i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr + i2run_b05_addr));
        printk("s0_vo_st_vir_addr: %x\n", (i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr));
       // printk("i2run_b05_test: %x\n", i2run_b05_test);

}

void vo_b05_outl(unsigned int addr, unsigned int value)
{
#ifdef CONFIG_I2RND_B05_ENABLE
        //printk("i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr =%x\n",i2rnd_b05_scpu_vir_addr.i2rnd_enable_vir_addr);
        if (Scaler_I2rnd_b05_get_enable()) {
                unsigned int curr_addr;
                curr_addr = i2rnd_b05_scpu_vir_addr.s0_vo_st_vir_addr + i2run_b05_addr;
                if (curr_addr) {
                        unsigned int tmp_addr = ((addr >> 2) & 0x000fffff) | 0x80000000;
                        curr_addr += 4;
                        *(volatile unsigned int *)(curr_addr) = __bswap_32(value);
                        curr_addr -= 4;
                        *(volatile unsigned int *)(curr_addr) = __bswap_32(tmp_addr);
                        //curr_addr+=8;
                        i2run_b05_addr += 8;

                } else {
                        (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr) = value);
                }
        } else {
#endif
                (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr) = value);
#ifdef CONFIG_I2RND_B05_ENABLE
        }
#endif
}



///////////////////////b05//////////////////////////////////////

#endif



/*======================== End of File =======================================*/
/**
*
* @}
*/




