/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: sky $
 * @date 	$Date: 2013/06/05 03:07 $
 * @version 	$Revision: 0.1 $
 * @ingroup 		TVE
 */

/**
 * @addtogroup VIDEO_ENCODER
 * @{
 */

/*================ Module dependency  =============== */
#define __TVE__

// linux lib
/*
#include <unistd.h>		// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <pthread.h>
*/
#include <linux/kernel.h>
#include <linux/delay.h>


//#include <rbusSYSTEMReg.h>
//#include <scalercommon/scalerDrvCommon.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/io/ioregdrv.h>
//#include <tvscalercontrol/scaler/scalerStruct.h>
//#include <tvscalercontrol/scaler/source.h>
//#include <tvscalercontrol/scaler/modeState.h>
//#include <tvscalercontrol/scaler/scalerTimer.h>
//#include <tvscalercontrol/scaler/scalerAtv.h>
//#include <tvscalercontrol/scaler/scalerVideo.h>
#include <tvscalercontrol/tve/tve.h>
#include <rbus/tv_sb1_ana_reg.h>
//#include <rbus/scaler/rbusCRTReg.h>
//#include <rbus/crt_reg.h>
#include <rbus/sys_reg_reg.h>//sunray
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <tvscalercontrol/vdac/vdac.h>
#include <rbus/h3ddma_reg.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <rbus/tve_dma_reg.h>
#include <rbus/tve_reg.h>
//#include <mach/rtk_crt.h>
#include <rtk_kdriver/rtk_crt.h>//sunray

#define _SUCCESS		1
#define _FAIL			0
#define _ENABLE 			1
#define _DISABLE			0
#define _TRUE			1
#define _FALSE			0

/*==================== Definitions ================ */
typedef unsigned char BIT;
#define ScalerTimer_DelayXms(mSec)	msleep(mSec)
#define rtdf_outl(offset, val)		IoReg_Write32(offset,val)
#define rtdf_inl(offset)			IoReg_Read32(offset)
#define rtdf_maskl(offset, andMask, orMask)	IoReg_Mask32(offset,andMask,orMask)

#ifndef rtd_maskl
#define rtd_maskl(x, y, z)	IoReg_Mask32(x, y, z)
#endif

/*=================== Hardware semaphore =============== */
/*
#define SB2_HD_SEM_NEW_5_reg 0xB801A634
extern char moduleName[32];

#define SB2_HD_SEM_NEW_5_reg 0xB801A634
#define Get_HD_SEM_NEW_5() while(!IoReg_Read32(SB2_HD_SEM_NEW_5_reg)){printk("#@# %s wait SB2_HD_SEM_NEW_5_reg ready\n", moduleName); msleep(20);}
#define Set_HD_SEM_NEW_5() IoReg_Write32(SB2_HD_SEM_NEW_5_reg, 0);

//#define Get_HD_SEM_NEW_5() while(!IoReg_Read32(SB2_HD_SEM_NEW_5_reg)){;}
#define Set_HD_SEM_NEW_5() IoReg_Write32(SB2_HD_SEM_NEW_5_reg, 0);
*/


/*==================== Variables ================== */

unsigned int tve_new_linestep = 0;

/*=====================function=====================*/
extern unsigned char scaler_dispDtoI3ddma_get_enable(void);

//=================================================================
/**
 * rtdf_tvedma_inl(offset)
 *
 *
 * @param <mode>
 * @return {void}
 */
 unsigned int rtdf_tvedma_inl (unsigned int addr)
{
	unsigned char value=0;
	unsigned int offset;
	value=rtdf_inl(TVE_ip_mvfcr_reg);
	offset=rtdf_inl(addr);
	return offset;

}


void drvif_module_tve_AVout_Setting(void)
{
	drvif_vdac_init();//Acc
	//rtd_outl(TV_SB1_ANA_VDAC_VDBSO_reg, (0x1<<24)|(0x1<<20)|(0x1<<16)|(0x1));//sunray
}

//=================================================================
/**
 * drv_tve_set_video_ntsc_m
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_tve_set_video_ntsc_m(void)
{
		rtd_outl(0xb801f478,00000003);
		rtdf_outl(TVE_video_dac_ctrl_0_reg,0x00785145);
		rtdf_outl(TVE_video_dac_ctrl_1_reg,0x00785145);
		rtdf_outl(TVE_dac_mux_reg,0x00001fc0);
		rtdf_outl(TVE_cmp_dly_reg,0x00000124);
		rtdf_outl(TVE_dac_misc_reg,0x00000020);
		rtdf_outl(TVE_video_dac_ctrl2_0_reg,0x0000591e);
		rtdf_outl(TVE_video_dac_ctrl2_1_reg,0x0000591e);
		rtdf_outl(TVE_syncgen_rst_reg,0x000002AA);
		rtdf_outl(TVE_ip_y_gain_reg,0x00000225);
		rtdf_outl(TVE_ip_phs_0_reg,0x00000060);//33
		rtdf_outl(TVE_ip_phs_1_reg,0x0000007a);//7b
		rtdf_outl(TVE_ip_phs_2_reg,0x000000f0);
		rtdf_outl(TVE_ip_phs_3_reg,0x00000021);
		rtdf_outl(TVE_ip_sctoh_0_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_1_reg,0x00000002);
		rtdf_outl(TVE_ip_sctoh_2_reg,0x00000002);
		rtdf_outl(TVE_ip_sctoh_3_reg,0x00000044);
		rtdf_outl(TVE_ip_f_ctrl_reg,0x00000002);
		rtdf_outl(TVE_ip_blck_lvl_reg,0x0000008d);
		rtdf_outl(TVE_ip_blnk_lvl_reg,0x00000078);
		rtdf_outl(TVE_ip_clamp_lvl_reg,0x00000010);
		rtdf_outl(TVE_ip_sync_lvl_reg,0x00000007);
		rtdf_outl(TVE_ip_y_ctrl_reg,0x00000098);///1c
		rtdf_outl(TVE_ip_test_param_reg,0x00000020);
		rtdf_outl(TVE_ip_test_t_byp_cups_reg,0x00000002);
		rtdf_outl(TVE_ip_o_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_nba_reg,0x000000C2);//0xc8
		rtdf_outl(TVE_ip_pba_reg,0x00000000);
		rtdf_outl(TVE_ip_c_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_s_ctrl_reg,0x00000008);
		rtdf_outl(TVE_ip_vso0_reg,0x00000031);
		rtdf_outl(TVE_ip_vso1_reg,0x00000006);
		rtdf_outl(TVE_ip_hso0_reg,0x00000006);
		rtdf_outl(TVE_ip_hso1_reg,0x000000b3);
		rtdf_outl(TVE_ip_hlc0_reg,0x00000003);
		rtdf_outl(TVE_ip_hlc1_reg,0x00000059);
		rtdf_outl(TVE_ip_sync_lvl2_reg,0x00000069); //0x64
		rtdf_outl(TVE_ip_sync_lvl3_reg,0x0000002d);
		rtdf_outl(TVE_ip_sync_lvl4_reg,0x00000007);
		rtdf_outl(TVE_ip_synclpf_gain_reg,0x00000053);///1a
		rtdf_outl(TVE_ip_mvfcr_reg,0x00000000);
		rtdf_outl(TVE_ip_mvcsl1_reg,0x0000003a);
		rtdf_outl(TVE_ip_mvcls1_reg,0x00000011);
		rtdf_outl(TVE_ip_mvcsl2_reg,0x0000004b);
		rtdf_outl(TVE_ip_mvcls2_reg,0x00000011);
		rtdf_outl(TVE_ip_mvcssp_reg,0x0000003c);
		rtdf_outl(TVE_ip_mvpsd_reg,0x0000001b);
		rtdf_outl(TVE_ip_mvpsl_reg,0x0000001b);
		rtdf_outl(TVE_ip_mvpss_reg,0x00000024);
		rtdf_outl(TVE_ip_mvpsls0_reg,0x00000007);
		rtdf_outl(TVE_ip_mvpsls1_reg,0x000000f8);
		rtdf_outl(TVE_ip_mvpsfs0_reg,0x00000000);
		rtdf_outl(TVE_ip_mvpsfs1_reg,0x00000000);
		rtdf_outl(TVE_ip_mvpsagca_reg,0x0000000f);
		rtdf_outl(TVE_ip_mvpsagcb_reg,0x0000000f);
		rtdf_outl(TVE_ip_mveofbpc_reg,0x00000060);
		rtdf_outl(TVE_ip_mvpbz1_reg,0x000000a0);
		rtdf_outl(TVE_ip_mvpbz3_reg,0x00000054);
		rtdf_outl(TVE_ip_mvpcslimd0_reg,0x000000ff);
		rtdf_outl(TVE_ip_mvpcslimd1_reg,0x00000003);
		rtdf_outl(TVE_ip_mv_ctrl_reg,0x00000010);
		rtdf_outl(TVE_ip_sync_strt_reg,0x0000000d);//0x0c
		rtdf_outl(TVE_ip_sync_end_reg,0x0000004b);
		rtdf_outl(TVE_ip_sync_srend_reg,0x0000007a);
		rtdf_outl(TVE_ip_sync_eqend_reg,0x0000002b);
		rtdf_outl(TVE_ip_actv_strt_reg,0x0000008e);//89
		rtdf_outl(TVE_ip_actv_end_reg,0x00000090); //aa
		rtdf_outl(TVE_ip_wbrst_strt_reg,0x0000005a);
		rtdf_outl(TVE_ip_nbrst_strt_reg,0x0000005f);//62
		rtdf_outl(TVE_ip_nbrst_end_reg,0x00000082);//84
		rtdf_outl(TVE_syncgen_i_reg,0x02832359);
		rtdf_outl(TVE_ip_vsyncpos_reg,0x00306505);
		rtdf_outl(TVE_ip_hsyncpos_reg,0x00000359);
		rtdf_outl(TVE_av_i_hpos_reg,0x08212353);
		rtdf_outl(TVE_slew_i_hpos_reg,0x00242753);
		rtdf_outl(TVE_itop_vpos_reg,0x00815904);
		rtdf_outl(TVE_ibot_vpos_reg,0x0091ca0b);
		rtdf_outl(TVE_av_slew_reg,0x00000330);
		rtdf_outl(TVE_av_ctrl_reg,0x0000007E);     // 0x19   pattern gen enable    7E patterngen disable
		rtdf_outl(TVE_i_colorbar_hpos_reg,0x0022cc82);
		rtdf_outl(TVE_comp_ctrl_reg,0x00003ffe);      //  control
		rtdf_outl(TVE_comp_ctrl_reg,0x00003409);      //  vbi_mux_on Y/G  hsync high active component oru enable SDTV on
		rtdf_outl(TVE_srstn_reg,0x00000001);
		rtdf_outl(TVE_syncgen_rst_reg,0x000002aa);		  //  syncgen rst
		rtdf_outl(TVE_syncgen_rst_reg,0x000003c0);		  //  syncgen rst
		rtdf_outl(TVE_DMA_TVE_VDDMA_reg,0x20052014);
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,0x00400000);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,0x00600000);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,0x00800000);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,0x00a00000);	  //  dma addr

}


//=================================================================
/**
 * drv_tve_set_video_ntsc_443
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_tve_set_video_ntsc_443(void)
{
	rtd_outl(0xb801f478,00000003);
	rtdf_outl(TVE_video_dac_ctrl_0_reg,0x00785145);
	rtdf_outl(TVE_video_dac_ctrl_1_reg,0x00485145);
	rtdf_outl(TVE_cmp_dly_reg,0x00000124);
	rtdf_outl(TVE_dac_mux_reg,0x00001fc0);
	rtdf_outl(TVE_dac_misc_reg,0x00200000);
	rtdf_outl(TVE_video_dac_ctrl2_0_reg,0x0000591e);
	rtdf_outl(TVE_video_dac_ctrl2_1_reg,0x0000591e);
	rtdf_outl(TVE_ip_y_gain_reg,0x00000200);
	rtdf_outl(TVE_ip_phs_0_reg,0x000000cb);
	rtdf_outl(TVE_ip_phs_1_reg,0x0000008a);
	rtdf_outl(TVE_ip_phs_2_reg,0x00000009);
	rtdf_outl(TVE_ip_phs_3_reg,0x0000002a);
	rtdf_outl(TVE_ip_sctoh_0_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_1_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_2_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_3_reg,0x00000000);
	rtdf_outl(TVE_ip_f_ctrl_reg,0x00000000);
	rtdf_outl(TVE_ip_blck_lvl_reg,0x0000008d);
	rtdf_outl(TVE_ip_blnk_lvl_reg,0x00000078);
	rtdf_outl(TVE_ip_clamp_lvl_reg,0x00000010);
	rtdf_outl(TVE_ip_sync_lvl_reg,0x00000004);
	rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001c);
	rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001c);
	rtdf_outl(TVE_ip_test_param_reg,0x00000020);
	rtdf_outl(TVE_ip_test_t_byp_cups_reg,0x00000002);
	rtdf_outl(TVE_ip_o_ctrl_reg,0x00000000);
	rtdf_outl(TVE_ip_nba_reg,0x000000c8);
	rtdf_outl(TVE_ip_pba_reg,0x00000000);
	rtdf_outl(TVE_ip_c_ctrl_reg,0x00000000);
	rtdf_outl(TVE_ip_s_ctrl_reg,0x00000008);
	rtdf_outl(TVE_ip_vso0_reg,0x00000031);
	rtdf_outl(TVE_ip_vso1_reg,0x00000006);
	rtdf_outl(TVE_ip_hso0_reg,0x00000006);
	rtdf_outl(TVE_ip_hso1_reg,0x000000b3);
	rtdf_outl(TVE_ip_hlc0_reg,0x00000003);
	rtdf_outl(TVE_ip_hlc1_reg,0x00000059);
	rtdf_outl(TVE_ip_sync_lvl2_reg,0x00000064);
	rtdf_outl(TVE_ip_sync_lvl3_reg,0x0000002d);
	rtdf_outl(TVE_ip_sync_lvl4_reg,0x00000007);
	rtdf_outl(TVE_ip_synclpf_gain_reg,0x00000018);
	rtdf_outl(TVE_ip_sync_strt_reg,0x0000000c);
	rtdf_outl(TVE_ip_sync_end_reg,0x0000004b);
	rtdf_outl(TVE_ip_sync_srend_reg,0x0000007a);
	rtdf_outl(TVE_ip_sync_eqend_reg,0x0000002b);
	rtdf_outl(TVE_ip_actv_strt_reg,0x00000085);
	rtdf_outl(TVE_ip_actv_end_reg,0x000000aa);
	rtdf_outl(TVE_ip_wbrst_strt_reg,0x0000005a);
	rtdf_outl(TVE_ip_nbrst_strt_reg,0x00000062);
	rtdf_outl(TVE_ip_nbrst_end_reg,0x00000084);
	rtdf_outl(TVE_syncgen_i_reg,0x02832359);
	rtdf_outl(TVE_syncgen_p_reg,0x0e832359);
	rtdf_outl(TVE_syncgen_hdmi_reg,0x0e832359);
	rtdf_outl(TVE_ip_vsyncpos_reg,0x00306505);
	rtdf_outl(TVE_ip_hsyncpos_reg,0x00000319);
	rtdf_outl(TVE_av_i_hpos_reg,0x08112313);
	rtdf_outl(TVE_slew_i_hpos_reg,0x00222713);
	rtdf_outl(TVE_itop_vpos_reg,0x00815904);
	rtdf_outl(TVE_ibot_vpos_reg,0x0091ca0b);
	rtdf_outl(TVE_av_p_hpos1_reg,0x38222358);
	rtdf_outl(TVE_p_vpos1_reg,0x0082aa09);
	rtdf_outl(TVE_av_h_hpos1_reg,0x28222358);
	rtdf_outl(TVE_h_vpos1_reg,0x00815904);
	rtdf_outl(TVE_h_vpos2_reg,0x0091ca0b);
	rtdf_outl(TVE_av_slew_reg,0x000003b4);
	rtdf_outl(TVE_av_ctrl_reg,0x0000007E);
	rtdf_outl(TVE_i_colorbar_hpos_reg,0x0022d450);
	rtdf_outl(TVE_comp_synclvl_reg,0x1a081000);
	rtdf_outl(TVE_comp_pbpr_synclvl_reg,0x02081bb0);
	rtdf_outl(TVE_av_coeff1_reg,0x80008800);
	rtdf_outl(TVE_av_coeff2_reg,0x80008000);
	rtdf_outl(TVE_av_coeff3_reg,0x937c937c);
	rtdf_outl(TVE_av_coeff4_reg,0x8380a003);
	rtdf_outl(TVE_av_coeff5_reg,0x0000a003);
	rtdf_outl(TVE_blnk_coeff_reg,0x88008380);
	rtdf_outl(TVE_comp_pbpr_blnklvl_reg,0x02781800);
	rtdf_outl(TVE_comp_ctrl_reg,0x00003ffe);
	rtdf_outl(TVE_mv_ctrl_reg,0x0000000c);
	rtdf_outl(TVE_comp_ctrl_reg,0x00003149);
	rtdf_outl(TVE_mv_ctrl_reg,0x00000005);
	rtdf_outl(TVE_srstn_reg,0x00000001);
	rtdf_outl(TVE_syncgen_rst_reg,0x000002aa);
	rtdf_outl(TVE_syncgen_rst_reg,0x000003d5);
	rtdf_outl(TVE_syncgen_rst_reg,0x000003c0);	  //  syncgen rst
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,0x00010000);	  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,0x00010000);	  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,0x00010000);	  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,0x00010000);	  //  dma addr

}






//=================================================================
/**
 * drv_tve_set_video_ntsc_j
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_tve_set_video_ntsc_j(void)
{
		rtd_outl(0xb801f478,00000003);
		rtdf_outl(TVE_video_dac_ctrl_0_reg,0x00785145);
		rtdf_outl(TVE_video_dac_ctrl_1_reg,0x00785145);
		rtdf_outl(TVE_dac_mux_reg,0x00001fc0);
		rtdf_outl(TVE_cmp_dly_reg,0x00000124);
		rtdf_outl(TVE_dac_misc_reg,0x00200000);
		rtdf_outl(TVE_video_dac_ctrl2_0_reg,0x0000591e);
		rtdf_outl(TVE_video_dac_ctrl2_1_reg,0x0000591e);
		rtdf_outl(TVE_ip_y_gain_reg,0x00000224);
		rtdf_outl(TVE_ip_phs_0_reg,0x0000001f);
		rtdf_outl(TVE_ip_phs_1_reg,0x0000007c);
		rtdf_outl(TVE_ip_phs_2_reg,0x000000f0);
		rtdf_outl(TVE_ip_phs_3_reg,0x00000021);
		rtdf_outl(TVE_ip_sctoh_0_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_1_reg,0x00000002);
		rtdf_outl(TVE_ip_sctoh_2_reg,0x00000002);
		rtdf_outl(TVE_ip_sctoh_3_reg,0x00000044);
		rtdf_outl(TVE_ip_f_ctrl_reg,0x00000002);
		rtdf_outl(TVE_ip_blck_lvl_reg,0x00000070);
		rtdf_outl(TVE_ip_blnk_lvl_reg,0x00000070);
		rtdf_outl(TVE_ip_clamp_lvl_reg,0x00000010);
		rtdf_outl(TVE_ip_sync_lvl_reg,0x00000007);
		rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001c);
		rtdf_outl(TVE_ip_test_param_reg,0x00000020);
		rtdf_outl(TVE_ip_test_t_byp_cups_reg,0x00000002);
		rtdf_outl(TVE_ip_o_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_nba_reg,0x000000c8);
		rtdf_outl(TVE_ip_pba_reg,0x00000000);
		rtdf_outl(TVE_ip_c_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_s_ctrl_reg,0x00000008);
		rtdf_outl(TVE_ip_vso0_reg,0x00000031);
		rtdf_outl(TVE_ip_vso1_reg,0x00000006);
		rtdf_outl(TVE_ip_hso0_reg,0x00000006);
		rtdf_outl(TVE_ip_hso1_reg,0x000000b3);
		rtdf_outl(TVE_ip_hlc0_reg,0x00000003);
		rtdf_outl(TVE_ip_hlc1_reg,0x00000059);
		rtdf_outl(TVE_ip_sync_lvl2_reg,0x00000064);
		rtdf_outl(TVE_ip_sync_lvl3_reg,0x0000002d);
		rtdf_outl(TVE_ip_sync_lvl4_reg,0x00000007);
		rtdf_outl(TVE_ip_synclpf_gain_reg,0x00000014);
		rtdf_outl(TVE_ip_sync_strt_reg,0x0000000c);
		rtdf_outl(TVE_ip_sync_end_reg,0x0000004b);
		rtdf_outl(TVE_ip_sync_srend_reg,0x0000007a);
		rtdf_outl(TVE_ip_sync_eqend_reg,0x0000002b);
		rtdf_outl(TVE_ip_actv_strt_reg,0x00000085);
		rtdf_outl(TVE_ip_actv_end_reg,0x000000aa);
		rtdf_outl(TVE_ip_wbrst_strt_reg,0x0000005a);
		rtdf_outl(TVE_ip_nbrst_strt_reg,0x00000062);
		rtdf_outl(TVE_ip_nbrst_end_reg,0x00000084);
		rtdf_outl(TVE_syncgen_i_reg,0x02832359);
		rtdf_outl(TVE_ip_vsyncpos_reg,0x00306505);
		rtdf_outl(TVE_ip_hsyncpos_reg,0x00000359);
		rtdf_outl(TVE_av_i_hpos_reg,0x08212353);
		rtdf_outl(TVE_itop_vpos_reg,0x00815904);
		rtdf_outl(TVE_slew_i_hpos_reg,0x00242753);
		rtdf_outl(TVE_ibot_vpos_reg,0x0091ca0b);
		rtdf_outl(TVE_av_slew_reg,0x00000330);
		rtdf_outl(TVE_av_ctrl_reg,0x0000007E);
		rtdf_outl(TVE_i_colorbar_hpos_reg,0x0022cc82);
		rtdf_outl(TVE_comp_ctrl_reg,0x00003ffe);      //  control
		rtdf_outl(TVE_comp_ctrl_reg,0x00003409);      //  vbi_mux_on Y/G  hsync high active component oru enable SDTV on
		rtdf_outl(TVE_srstn_reg,0x00000001);
		rtdf_outl(TVE_syncgen_rst_reg,0x000002aa);
		rtdf_outl(TVE_syncgen_rst_reg,0x000003c0);  	  //  syncgen rst
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,0x00010000);  	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,0x00010000);  	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,0x00010000);  	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,0x00010000);  	  //  dma addr

}

//=================================================================
/**
 * drv_tve_set_video_pal_60
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_tve_set_video_pal_60(void)
{
		rtd_outl(0xb801f478,00000003);
		rtdf_outl(TVE_cmp_dly_reg,0x00000124);
		rtdf_outl(TVE_dac_mux_reg,0x00001fc0);
		rtdf_outl(TVE_dac_misc_reg,0x00238000);
		rtdf_outl(TVE_video_dac_ctrl_0_reg,0x0078b000);
		rtdf_outl(TVE_video_dac_ctrl_1_reg,0x0078c30c);
		rtdf_outl(TVE_video_dac_ctrl2_0_reg,0x00005b1e);
		rtdf_outl(TVE_video_dac_ctrl2_1_reg,0x00005b1e);
		rtdf_outl(TVE_ip_y_gain_reg,0x00000200);
		rtdf_outl(TVE_ip_phs_0_reg,0x000000cb);
		rtdf_outl(TVE_ip_phs_1_reg,0x0000008a);
		rtdf_outl(TVE_ip_phs_2_reg,0x00000009);
		rtdf_outl(TVE_ip_phs_3_reg,0x0000002a);
		rtdf_outl(TVE_ip_sctoh_0_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_1_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_2_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_3_reg,0x00000000);
		rtdf_outl(TVE_ip_f_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_blck_lvl_reg,0x0000008d);
		rtdf_outl(TVE_ip_blnk_lvl_reg,0x00000078);
		rtdf_outl(TVE_ip_clamp_lvl_reg,0x00000010);
		rtdf_outl(TVE_ip_sync_lvl_reg,0x00000004);
		rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001d);
		rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001d);
		rtdf_outl(TVE_ip_test_param_reg,0x00000020);
		rtdf_outl(TVE_ip_test_t_byp_cups_reg,0x00000002);
		rtdf_outl(TVE_ip_o_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_nba_reg,0x000000d7);
		rtdf_outl(TVE_ip_pba_reg,0x00000029);
		rtdf_outl(TVE_ip_c_ctrl_reg,0x00000003);
		rtdf_outl(TVE_ip_s_ctrl_reg,0x0000000a);
		rtdf_outl(TVE_ip_vso0_reg,0x00000031);
		rtdf_outl(TVE_ip_vso1_reg,0x00000006);
		rtdf_outl(TVE_ip_hso0_reg,0x00000006);
		rtdf_outl(TVE_ip_hso1_reg,0x000000b3);
		rtdf_outl(TVE_ip_hlc0_reg,0x00000003);
		rtdf_outl(TVE_ip_hlc1_reg,0x00000058);
		rtdf_outl(TVE_ip_sync_lvl2_reg,0x00000064);
		rtdf_outl(TVE_ip_sync_lvl3_reg,0x0000002d);
		rtdf_outl(TVE_ip_sync_lvl4_reg,0x00000007);
		rtdf_outl(TVE_ip_synclpf_gain_reg,0x00000018);
		rtdf_outl(TVE_ip_sync_strt_reg,0x0000000c);
		rtdf_outl(TVE_ip_sync_end_reg,0x0000004b);
		rtdf_outl(TVE_ip_sync_srend_reg,0x0000007a);
		rtdf_outl(TVE_ip_sync_eqend_reg,0x0000002b);
		rtdf_outl(TVE_ip_actv_strt_reg,0x00000085);
		rtdf_outl(TVE_ip_actv_end_reg,0x000000aa);
		rtdf_outl(TVE_ip_wbrst_strt_reg,0x0000005a);
		rtdf_outl(TVE_ip_nbrst_strt_reg,0x00000062);
		rtdf_outl(TVE_ip_nbrst_end_reg,0x00000084);
		rtdf_outl(TVE_syncgen_i_reg,0x02832359);
		rtdf_outl(TVE_syncgen_p_reg,0x0e832359);
		rtdf_outl(TVE_syncgen_hdmi_reg,0x0e832359);
		rtdf_outl(TVE_ip_vsyncpos_reg,0x00306505);
		rtdf_outl(TVE_ip_hsyncpos_reg,0x00000319);
		rtdf_outl(TVE_av_i_hpos_reg,0x08112313);
		rtdf_outl(TVE_slew_i_hpos_reg,0x00222713);
		rtdf_outl(TVE_itop_vpos_reg,0x00815904);
		rtdf_outl(TVE_ibot_vpos_reg,0x0091ca0b);
		rtdf_outl(TVE_av_p_hpos1_reg,0x38222358);
		rtdf_outl(TVE_p_vpos1_reg,0x0082aa09);
		rtdf_outl(TVE_av_h_hpos1_reg,0x28112313);
		rtdf_outl(TVE_h_vpos1_reg,0x00815904);
		rtdf_outl(TVE_h_vpos2_reg,0x0091ca0b);
		rtdf_outl(TVE_av_slew_reg,0x000003b4);
		rtdf_outl(TVE_av_ctrl_reg,0x0000007E);
		rtdf_outl(TVE_i_colorbar_hpos_reg,0x0022d450);
		rtdf_outl(TVE_av_coeff1_reg,0x80008800);
		rtdf_outl(TVE_av_coeff2_reg,0x80008000);
		rtdf_outl(TVE_av_coeff3_reg,0x937c937c);
		rtdf_outl(TVE_av_coeff4_reg,0x8380a003);
		rtdf_outl(TVE_av_coeff5_reg,0x0000a003);
		rtdf_outl(TVE_blnk_coeff_reg,0x88008380);
		rtdf_outl(TVE_comp_pbpr_blnklvl_reg,0x02781800);
		rtdf_outl(TVE_comp_synclvl_reg,0x1a081000);
		rtdf_outl(TVE_comp_pbpr_synclvl_reg,0x02081bb0);
		rtdf_outl(TVE_comp_ctrl_reg,0x00003ffe);
		rtdf_outl(TVE_mv_ctrl_reg,0x0000000c);
		rtdf_outl(TVE_comp_ctrl_reg,0x00003149);
		rtdf_outl(TVE_mv_ctrl_reg,0x00000005);
		rtdf_outl(TVE_srstn_reg,0x00000001);
		rtdf_outl(TVE_syncgen_rst_reg,0x000002aa);
		rtdf_outl(TVE_syncgen_rst_reg,0x000003c0);
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,0x00010000);		  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,0x00010000);		  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,0x00010000);		  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,0x00010000);		  //  dma addr

}


//=================================================================
/**
 * drv_tve_set_video_pal_cn
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_tve_set_video_pal_cn(void)
{
		rtd_outl(0xb801f478,00000003);
		rtdf_outl(TVE_cmp_dly_reg,0x00000124);
		rtdf_outl(TVE_dac_mux_reg,0x00001fc0);
		rtdf_outl(TVE_dac_misc_reg,0x00238000);
		rtdf_outl(TVE_video_dac_ctrl_0_reg,0x0078b000);
		rtdf_outl(TVE_video_dac_ctrl_1_reg,0x0078c30c);
		rtdf_outl(TVE_video_dac_ctrl2_0_reg,0x00005b1e);
		rtdf_outl(TVE_video_dac_ctrl2_1_reg,0x00005b1e);
		rtdf_outl(TVE_ip_y_gain_reg,0x00000205);
		rtdf_outl(TVE_ip_phs_0_reg,0x00000046);
		rtdf_outl(TVE_ip_phs_1_reg,0x00000094);
		rtdf_outl(TVE_ip_phs_2_reg,0x000000f6);
		rtdf_outl(TVE_ip_phs_3_reg,0x00000021);
		rtdf_outl(TVE_ip_sctoh_0_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_1_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_2_reg,0x00000000);
		rtdf_outl(TVE_ip_sctoh_3_reg,0x00000000);
		rtdf_outl(TVE_ip_f_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_blck_lvl_reg,0x00000078);
		rtdf_outl(TVE_ip_blnk_lvl_reg,0x00000078);
		rtdf_outl(TVE_ip_clamp_lvl_reg,0x00000010);
		rtdf_outl(TVE_ip_sync_lvl_reg,0x00000003);
		rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001d);
		rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001d);
		rtdf_outl(TVE_ip_test_param_reg,0x00000020);
		rtdf_outl(TVE_ip_test_t_byp_cups_reg,0x00000002);
		rtdf_outl(TVE_ip_o_ctrl_reg,0x00000000);
		rtdf_outl(TVE_ip_nba_reg,0x000000d7);
		rtdf_outl(TVE_ip_pba_reg,0x00000029);
		rtdf_outl(TVE_ip_c_ctrl_reg,0x00000003);
		rtdf_outl(TVE_ip_s_ctrl_reg,0x00000009);
		rtdf_outl(TVE_ip_vso0_reg,0x00000031);
		rtdf_outl(TVE_ip_vso1_reg,0x00000038);
		rtdf_outl(TVE_ip_hso0_reg,0x00000006);
		rtdf_outl(TVE_ip_hso1_reg,0x000000bf);
		rtdf_outl(TVE_ip_hlc0_reg,0x00000003);
		rtdf_outl(TVE_ip_hlc1_reg,0x0000005f);
		rtdf_outl(TVE_ip_sync_lvl2_reg,0x0000005c);
		rtdf_outl(TVE_ip_sync_lvl3_reg,0x00000040);
		rtdf_outl(TVE_ip_sync_lvl4_reg,0x00000024);
		rtdf_outl(TVE_ip_synclpf_gain_reg,0x0000002b);
		rtdf_outl(TVE_ip_sync_strt_reg,0x00000000);
		rtdf_outl(TVE_ip_sync_end_reg,0x0000003f);
		rtdf_outl(TVE_ip_sync_srend_reg,0x00000071);
		rtdf_outl(TVE_ip_sync_eqend_reg,0x00000020);
		rtdf_outl(TVE_ip_actv_strt_reg,0x00000080);
		rtdf_outl(TVE_ip_actv_end_reg,0x000000a4);
		rtdf_outl(TVE_ip_wbrst_strt_reg,0x00000050);
		rtdf_outl(TVE_ip_nbrst_strt_reg,0x00000057);
		rtdf_outl(TVE_ip_nbrst_end_reg,0x00000075);
		rtdf_outl(TVE_syncgen_i_reg,0x029c235f);
		rtdf_outl(TVE_syncgen_p_reg,0x0e9c235f);
		rtdf_outl(TVE_syncgen_hdmi_reg,0x0e9c235f);
		rtdf_outl(TVE_ip_vsyncpos_reg,0x0029ae6d);
		rtdf_outl(TVE_ip_hsyncpos_reg,0x0000031b);
		rtdf_outl(TVE_av_i_hpos_reg,0x080fa30d);
		rtdf_outl(TVE_slew_i_hpos_reg,0x0021f70d);
		rtdf_outl(TVE_itop_vpos_reg,0x00816935);
		rtdf_outl(TVE_ibot_vpos_reg,0x0094fa6e);
		rtdf_outl(TVE_av_p_hpos1_reg,0x381f234c);
		rtdf_outl(TVE_p_vpos1_reg,0x0082ca6b);
		rtdf_outl(TVE_av_h_hpos1_reg,0x280fa30d);
		rtdf_outl(TVE_h_vpos1_reg,0x00816935);
		rtdf_outl(TVE_h_vpos2_reg,0x0094fa6e);
		rtdf_outl(TVE_av_slew_reg,0x000003b4);
		rtdf_outl(TVE_av_ctrl_reg,0x0000007E);
		rtdf_outl(TVE_i_colorbar_hpos_reg,0x0022d43c);
		rtdf_outl(TVE_comp_synclvl_reg,0x1a081000);
		rtdf_outl(TVE_comp_pbpr_synclvl_reg,0x02081bb0);
		rtdf_outl(TVE_comp_ctrl_reg,0x00003ffe);
		rtdf_outl(TVE_mv_ctrl_reg,0x0000000c);
		rtdf_outl(TVE_comp_ctrl_reg,0x00003149);
		rtdf_outl(TVE_mv_ctrl_reg,0x00000005);
		rtdf_outl(TVE_av_coeff1_reg,0x80008800);
		rtdf_outl(TVE_av_coeff2_reg,0x80008000);
		rtdf_outl(TVE_av_coeff3_reg,0x937c937c);
		rtdf_outl(TVE_av_coeff4_reg,0x8380a003);
		rtdf_outl(TVE_av_coeff5_reg,0x0000a003);
		rtdf_outl(TVE_blnk_coeff_reg,0x88008380);
		rtdf_outl(TVE_comp_pbpr_blnklvl_reg,0x02781800);
		rtdf_outl(TVE_srstn_reg,0x00000001);
		rtdf_outl(TVE_syncgen_rst_reg,0x000002aa);
		rtdf_outl(TVE_syncgen_rst_reg,0x000003c0);
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,0x00010000);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,0x00010000);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,0x00010000);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,0x00010000);	  //  dma addr
}


//=================================================================
/**
 * drv_tve_set_video_pal_i
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_tve_set_video_pal_i(void)
{
	rtd_outl(0xb801f478,00000003);
	rtdf_outl(TVE_comp_ctrl_reg,0x00003ffe);
	rtdf_outl(TVE_comp_ctrl_reg,0x00003409);
	rtdf_outl(TVE_video_dac_ctrl_0_reg,0x00785145);
	rtdf_outl(TVE_video_dac_ctrl_1_reg,0x00785145);
	rtdf_outl(TVE_dac_mux_reg,0x00001fc0);
	rtdf_outl(TVE_cmp_dly_reg,0x00000124);
	rtdf_outl(TVE_dac_misc_reg,0x00200000);
	rtdf_outl(TVE_video_dac_ctrl2_0_reg,0x00005b1e);
	rtdf_outl(TVE_video_dac_ctrl2_1_reg,0x00005b1e);
	rtdf_outl(TVE_ip_y_gain_reg,0x0000022d);//208
	rtdf_outl(TVE_ip_phs_0_reg,0x00000098);
	rtdf_outl(TVE_ip_phs_1_reg,0x0000008a);
	rtdf_outl(TVE_ip_phs_2_reg,0x00000009);
	rtdf_outl(TVE_ip_phs_3_reg,0x0000002a);
	rtdf_outl(TVE_ip_sctoh_0_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_1_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_2_reg,0x00000090);//00
	rtdf_outl(TVE_ip_sctoh_3_reg,0x00000099);
	rtdf_outl(TVE_ip_f_ctrl_reg,0x00000002);
	rtdf_outl(TVE_ip_blck_lvl_reg,0x00000078);
	rtdf_outl(TVE_ip_blnk_lvl_reg,0x00000078);
	rtdf_outl(TVE_ip_clamp_lvl_reg,0x00000010);
	rtdf_outl(TVE_ip_sync_lvl_reg,0x00000003);
	rtdf_outl(TVE_ip_y_ctrl_reg,0x00000095);///1d
	rtdf_outl(TVE_ip_test_param_reg,0x00000020);
	rtdf_outl(TVE_ip_test_t_byp_cups_reg,0x00000002);
	rtdf_outl(TVE_ip_o_ctrl_reg,0x00000000);
	rtdf_outl(TVE_ip_nba_reg,0x000000cb);//d7
	rtdf_outl(TVE_ip_pba_reg,0x0000001a);//29
	rtdf_outl(TVE_ip_c_ctrl_reg,0x00000003);
	rtdf_outl(TVE_ip_s_ctrl_reg,0x00000009);
	rtdf_outl(TVE_ip_vso0_reg,0x00000031);
	rtdf_outl(TVE_ip_vso1_reg,0x00000038);
	rtdf_outl(TVE_ip_hso0_reg,0x00000006);
	rtdf_outl(TVE_ip_hso1_reg,0x000000bf);
	rtdf_outl(TVE_ip_hlc0_reg,0x00000003);
	rtdf_outl(TVE_ip_hlc1_reg,0x0000005f);
	rtdf_outl(TVE_ip_sync_lvl2_reg,0x00000058);
	rtdf_outl(TVE_ip_sync_lvl3_reg,0x0000003e);
	rtdf_outl(TVE_ip_sync_lvl4_reg,0x00000028);
	rtdf_outl(TVE_ip_synclpf_gain_reg,0x00000065);//29
	rtdf_outl(TVE_ip_sync_strt_reg,0x00000000);
	rtdf_outl(TVE_ip_sync_end_reg,0x00000041);
	rtdf_outl(TVE_ip_sync_srend_reg,0x00000071);
	rtdf_outl(TVE_ip_sync_eqend_reg,0x00000020);
	rtdf_outl(TVE_ip_actv_strt_reg,0x00000080);
	rtdf_outl(TVE_ip_actv_end_reg,0x00000090);
	rtdf_outl(TVE_ip_wbrst_strt_reg,0x00000050);
	rtdf_outl(TVE_ip_nbrst_strt_reg,0x00000056);
	rtdf_outl(TVE_ip_nbrst_end_reg,0x00000074);
	rtdf_outl(TVE_syncgen_i_reg,0x029c235f);
	rtdf_outl(TVE_ip_vsyncpos_reg,0x0029ae6d);
	rtdf_outl(TVE_ip_hsyncpos_reg,0x0000031b);
	rtdf_outl(TVE_av_i_hpos_reg,0x080fa30d);
	rtdf_outl(TVE_slew_i_hpos_reg,0x0021f70d);
	rtdf_outl(TVE_itop_vpos_reg,0x00817936);
	rtdf_outl(TVE_ibot_vpos_reg,0x00950a6e);////0094fa6e
	rtdf_outl(TVE_av_slew_reg,0x00000330);
	rtdf_outl(TVE_av_ctrl_reg,0x0000007E);
	rtdf_outl(TVE_i_colorbar_hpos_reg,0x0022cc3e);
	rtdf_outl(TVE_srstn_reg,0x00000001);
	rtdf_outl(TVE_syncgen_rst_reg,0x000002aa);
	rtdf_outl(TVE_syncgen_rst_reg,0x000003c0);  //  syncgen rst
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,0x00040000);  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,0x00040000);  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,0x00040000);  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,0x00040000);  //  dma addr
	//rtdf_outl(WSS_CTRL_reg,0x73006aaa);//for IC verification
	rtdf_outl(TVE_wss_ctrl_reg,0x13006aaa);//default no enable WSS
	rtdf_outl(TVE_wss_pos_reg,0x00429416);
	rtdf_outl(TVE_wss_625p_wss_pos_reg,0x0042954f);
	rtdf_outl(TVE_vps_data1_reg,0x000000aa);
	rtdf_outl(TVE_vps_data_2_reg,0xaaaaaaaa);
	rtdf_outl(TVE_vps_data_1_reg,0xaaaaaaaa);
	rtdf_outl(TVE_vps_data_0_reg,0xaaaaaaaa);
	rtdf_outl(TVE_vps_ctrl_reg,0x0434c103);
/*
	rtdf_outl(0xb801F174,0x73006aaa);
	rtdf_outl(0xb801F178,0x00429416);
	rtdf_outl(1801F17c,0x73006123);
	rtdf_outl(1801F180,0x0042954f);
	rtdf_outl(1801F1ac,0x000000aa);
	rtdf_outl(1801F1a8,0xaaaaaaaa);
	rtdf_outl(1801F1a4,0xaaaaaaaa);
	rtdf_outl(1801F1a0,0xaaaaaaaa);
	rtdf_outl(1801F198,0x0434c103);
*/
}
//=================================================================
/**
 * drv_tve_set_video_pal_m
 *
 *
 * @param <mode>
 * @return {void}
 */
void drv_tve_set_video_pal_m(void)
{
	rtd_outl(0xb801f478,00000003);
	rtdf_outl(TVE_cmp_dly_reg,0x00000124);
	rtdf_outl(TVE_dac_mux_reg,0x00001fc0);
	rtdf_outl(TVE_dac_misc_reg,0x00238000);
	rtdf_outl(TVE_video_dac_ctrl_0_reg,0x0078b000);
	rtdf_outl(TVE_video_dac_ctrl_1_reg,0x0078c30c);
	rtdf_outl(TVE_video_dac_ctrl2_0_reg,0x00005b1e);
	rtdf_outl(TVE_video_dac_ctrl2_1_reg,0x00005b1e);
	rtdf_outl(TVE_ip_y_gain_reg,0x00000200);
	rtdf_outl(TVE_ip_phs_0_reg,0x000000a3);
	rtdf_outl(TVE_ip_phs_1_reg,0x000000ef);
	rtdf_outl(TVE_ip_phs_2_reg,0x000000e6);
	rtdf_outl(TVE_ip_phs_3_reg,0x00000021);
	rtdf_outl(TVE_ip_sctoh_0_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_1_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_2_reg,0x00000000);
	rtdf_outl(TVE_ip_sctoh_3_reg,0x00000000);
	rtdf_outl(TVE_ip_f_ctrl_reg,0x00000000);
	rtdf_outl(TVE_ip_blck_lvl_reg,0x0000008d);
	rtdf_outl(TVE_ip_blnk_lvl_reg,0x00000078);
	rtdf_outl(TVE_ip_clamp_lvl_reg,0x00000010);
	rtdf_outl(TVE_ip_sync_lvl_reg,0x00000004);
	rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001d);
	rtdf_outl(TVE_ip_y_ctrl_reg,0x0000001d);
	rtdf_outl(TVE_ip_test_param_reg,0x00000020);
	rtdf_outl(TVE_ip_test_t_byp_cups_reg,0x00000002);
	rtdf_outl(TVE_ip_o_ctrl_reg,0x00000000);
	rtdf_outl(TVE_ip_nba_reg,0x000000d7);
	rtdf_outl(TVE_ip_pba_reg,0x00000029);
	rtdf_outl(TVE_ip_c_ctrl_reg,0x00000003);
	rtdf_outl(TVE_ip_s_ctrl_reg,0x0000000a);
	rtdf_outl(TVE_ip_vso0_reg,0x00000031);
	rtdf_outl(TVE_ip_vso1_reg,0x00000006);
	rtdf_outl(TVE_ip_hso0_reg,0x00000006);
	rtdf_outl(TVE_ip_hso1_reg,0x000000b3);
	rtdf_outl(TVE_ip_hlc0_reg,0x00000003);
	rtdf_outl(TVE_ip_hlc1_reg,0x00000058);
	rtdf_outl(TVE_ip_sync_lvl2_reg,0x00000064);
	rtdf_outl(TVE_ip_sync_lvl3_reg,0x0000002d);
	rtdf_outl(TVE_ip_sync_lvl4_reg,0x00000007);
	rtdf_outl(TVE_ip_synclpf_gain_reg,0x00000018);
	rtdf_outl(TVE_ip_sync_strt_reg,0x0000000c);
	rtdf_outl(TVE_ip_sync_end_reg,0x0000004b);
	rtdf_outl(TVE_ip_sync_srend_reg,0x0000007a);
	rtdf_outl(TVE_ip_sync_eqend_reg,0x0000002b);
	rtdf_outl(TVE_ip_actv_strt_reg,0x00000085);
	rtdf_outl(TVE_ip_actv_end_reg,0x000000aa);
	rtdf_outl(TVE_ip_wbrst_strt_reg,0x0000005a);
	rtdf_outl(TVE_ip_nbrst_strt_reg,0x00000062);
	rtdf_outl(TVE_ip_nbrst_end_reg,0x00000084);
	rtdf_outl(TVE_syncgen_i_reg,0x02832359);
	rtdf_outl(TVE_syncgen_p_reg,0x0e832359);
	rtdf_outl(TVE_syncgen_hdmi_reg,0x0e832359);
	rtdf_outl(TVE_ip_vsyncpos_reg,0x00306505);
	rtdf_outl(TVE_ip_hsyncpos_reg,0x00000319);
	rtdf_outl(TVE_av_i_hpos_reg,0x08112313);
	rtdf_outl(TVE_slew_i_hpos_reg,0x00222713);
	rtdf_outl(TVE_itop_vpos_reg,0x00815904);
	rtdf_outl(TVE_ibot_vpos_reg,0x0091ca0b);
	rtdf_outl(TVE_av_p_hpos1_reg,0x38222358);
	rtdf_outl(TVE_p_vpos1_reg,0x0082aa09);
	rtdf_outl(TVE_av_h_hpos1_reg,0x28112313);
	rtdf_outl(TVE_h_vpos1_reg,0x00815904);
	rtdf_outl(TVE_h_vpos2_reg,0x0091ca0b);
	rtdf_outl(TVE_av_slew_reg,0x000003b4);
	rtdf_outl(TVE_av_ctrl_reg,0x0000007E);
	rtdf_outl(TVE_i_colorbar_hpos_reg,0x0022d450);
	rtdf_outl(TVE_av_coeff1_reg,0x80008800);
	rtdf_outl(TVE_av_coeff2_reg,0x80008000);
	rtdf_outl(TVE_av_coeff3_reg,0x937c937c);
	rtdf_outl(TVE_av_coeff4_reg,0x8380a003);
	rtdf_outl(TVE_av_coeff5_reg,0x0000a003);
	rtdf_outl(TVE_blnk_coeff_reg,0x88008380);
	rtdf_outl(TVE_comp_pbpr_blnklvl_reg,0x02781800);
	rtdf_outl(TVE_comp_synclvl_reg,0x1a081000);
	rtdf_outl(TVE_comp_pbpr_synclvl_reg,0x02081bb0);
	rtdf_outl(TVE_comp_ctrl_reg,0x00003ffe);
	rtdf_outl(TVE_mv_ctrl_reg,0x0000000c);
	rtdf_outl(TVE_comp_ctrl_reg,0x00003149);
	rtdf_outl(TVE_mv_ctrl_reg,0x00000005);
	rtdf_outl(TVE_srstn_reg,0x00000001);
	rtdf_outl(TVE_syncgen_rst_reg,0x000002aa);
	rtdf_outl(TVE_syncgen_rst_reg,0x000003c0);
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,0x00010000);	  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,0x00010000);	  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,0x00010000);	  //  dma addr
	rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,0x00010000);	  //  dma addr

}

void drvif_module_tve_init(void)
	{
		//PLL RST and Enable CLK
		//initialize clk for VD
		//PLL RST and Enable CLK MacArthur3-DesignSpec-CRT.doc
		//Get_HD_SEM_NEW_5();
		sys_reg_sys_srst1_RBUS	sys_srst1_reg;
		sys_reg_sys_srst2_RBUS	sys_srst2_reg;
		sys_reg_sys_clken1_RBUS sys_clken1_reg;
		sys_reg_sys_clken2_RBUS sys_clken2_reg;
		sys_srst1_reg.regValue = IoReg_Read32(SYS_REG_SYS_SRST1_reg);
		sys_srst2_reg.regValue = IoReg_Read32(SYS_REG_SYS_SRST2_reg);
		sys_clken1_reg.regValue = IoReg_Read32(SYS_REG_SYS_CLKEN1_reg);
		sys_clken2_reg.regValue = IoReg_Read32(SYS_REG_SYS_CLKEN2_reg);
	
#if 1//for ma3 LGE project
	
	
		if(!(sys_clken1_reg.clken_vdec)){
			sys_srst1_reg.rstn_vdec = 1;//[21]RSTN_VDEC
			sys_srst1_reg.rstn_vdec2 = 1;//[22]RSTN_VDEC2
			sys_srst1_reg.write_data = 1;
			IoReg_Write32(SYS_REG_SYS_SRST1_reg, sys_srst1_reg.regValue);
			sys_clken1_reg.clken_vdec = 1;//[22]CLKEN_VDEC
			sys_clken1_reg.write_data = 1;		
			IoReg_Write32(SYS_REG_SYS_CLKEN1_reg, sys_clken1_reg.regValue);
		}
	
		//check [11]RSTN_APLL_ADC
		if(!(sys_clken1_reg.clken_apll_adc)){
			sys_srst1_reg.rstn_apll_adc = 1;//[11]RSTN_APLL_ADC
			sys_srst1_reg.write_data = 1;
			IoReg_Write32(SYS_REG_SYS_SRST1_reg, sys_srst1_reg.regValue);
			ScalerTimer_DelayXms(1);
			sys_clken1_reg.clken_apll_adc = 1;//[11]CLKEN_APLL_ADC
			sys_clken1_reg.write_data = 1;	
			IoReg_Write32(SYS_REG_SYS_CLKEN1_reg, sys_clken1_reg.regValue);
		}
	
		//check [27]RSTN_ATVIN2[26]RSTN_ATVIN
		if(!(sys_clken2_reg.clken_atvin_vd)){
			sys_srst2_reg.rstn_atvin2 = 1;//[27]RSTN_ATVIN2
			sys_srst2_reg.rstn_atvin = 1;//[26]RSTN_ATVIN
			sys_srst2_reg.write_data = 1;
			IoReg_Write32(SYS_REG_SYS_SRST2_reg, sys_srst2_reg.regValue);
			sys_clken2_reg.clken_atvin_vd = 1;//[27]CLKEN_ATVIN_VD
			sys_clken2_reg.write_data = 1;
			IoReg_Write32(SYS_REG_SYS_CLKEN2_reg, sys_clken2_reg.regValue);
		}
	
		//check [26]CLKEN_ATVIN_IFD
		if(!(sys_clken2_reg.clken_atvin_ifd)){
			sys_clken2_reg.clken_atvin_ifd = 1;//[26]CLKEN_ATVIN_IFD
			sys_clken2_reg.write_data = 1;
			IoReg_Write32(SYS_REG_SYS_CLKEN2_reg, sys_clken2_reg.regValue);
		}
	
		//check [15]CLKEN_IFADC
		if(!(sys_clken1_reg.clken_ifadc)){
			sys_srst1_reg.rstn_ifadc = 1;//[15]RSTN_IFADC
			sys_srst1_reg.write_data = 1;
			IoReg_Write32(SYS_REG_SYS_SRST1_reg, sys_srst1_reg.regValue);
			sys_clken1_reg.clken_ifadc = 1;//[15]CLKEN_IFADC
			sys_clken1_reg.write_data = 1;	
			IoReg_Write32(SYS_REG_SYS_CLKEN1_reg, sys_clken1_reg.regValue);
		}
	
		//check [23]CLKEN_IF_DEMOD
		if(!(sys_clken1_reg.clken_if_demod)){
			sys_clken1_reg.clken_if_demod = 1;//[23]CLKEN_IF_DEMOD
			sys_clken1_reg.write_data = 1;	
			IoReg_Write32(SYS_REG_SYS_CLKEN1_reg, sys_clken1_reg.regValue);
		}
	
		rtd_maskl(SYS_REG_SYS_CLKSEL_reg,0xFFFCFFFe,0x00020001);//[17]ATVIN_CLK_SEL] = 0x1, 0x0: IFD, 0x1: VD [16]ATVIN_VD_CLK_SEL = 0x0, 0x0: 108MHz 0x1: 27MHz
	
#else
		rtd_maskl(SYS_REG_SYS_SRST1_VADDR,0xFF9FF7FF,0x00600800);//[22]RSTN_VDEC[21]RSTN_VDEC2[11]RSTN_APLL_ADC
		rtd_maskl(SYS_REG_SYS_SRST2_VADDR,0xF3FFFFFF,0x0C000000);//[27]RSTN_ATVIN2[26]RSTN_ATVIN
		rtd_maskl(SYS_REG_SYS_CLKEN1_VADDR,0xFFBFF7FF,0x00400800);//[22]CLKEN_VDEC[11]CLKEN_APLL_ADC
		rtd_maskl(SYS_REG_SYS_CLKEN2_VADDR,0xFFBFFFFF,0x00400000);//[27]CLKEN_ATVIN_VD
		rtd_maskl(SYS_REG_SYS_CLKSEL_VADDR,0xFFFCFFFF,0x00020000);//[17]ATVIN_CLK_SEL] = 0x1, 0x0: IFD, 0x1: VD [16]ATVIN_VD_CLK_SEL = 0x0, 0x0: 108MHz 0x1: 27MHz
	
		rtd_maskl(SYS_REG_SYS_SRST1_VADDR,0xFffF7fFF,0x00008000);//[15]RSTN_IFADC
		rtd_maskl(SYS_REG_SYS_CLKEN2_VADDR,0xFbfFFfFF,0x04000000);//[26]CLKEN_ATVIN_IFD
	
		rtd_maskl(SYS_REG_SYS_SRST2_VADDR,0xF3fFFfFF,0x0c000000);//[26]RSTN_ATVIN ,[27]RSTN_ATVIN2
		rtd_maskl(SYS_REG_SYS_CLKEN1_VADDR,0xFF7fFFFF,0x00800000);//[23]CLKEN_IF_DEMOD
		rtd_maskl(SYS_REG_SYS_CLKEN1_VADDR,0xFFff7FFF,0x00008000);//[15]CLKEN_IFADC
		//not to disable ATV @ Crixus 20141106
		//rtd_maskl(SYS_REG_SYS_CLKSEL_VADDR,0xFFFCFFFF,0x00000000);
#endif
	
	
	
		//initialize clk 27x domain for VD
		////PLL27x Clock : 108M
		rtd_maskl(PLL27X_REG_SYS_PLL_27X1_reg,0xFFFFFFE0,0x0000000E);//432MHzPLL27X_M[6:0] = 0x0E
		rtd_maskl(PLL27X_REG_SYS_PLL_27X2_reg,0xFFFFFFFF,0x00000000);// do nothing
		rtd_maskl(PLL27X_REG_SYS_PLL_27X4_reg,0xFDFC0FFF,0x0201F000);//[25]PLL_L2H_CML_POW [17:16]PLL27X_CK108M_DIV = 0x1, divide by 4 (use when VCO=432MHz) [15:14]PLL27X_YPPADC_CKO_SEL = 0x3,YPPADC clock outpu 11:108M [13]PLL27X_YPPADC_CKO_EN[12]PLL27X_YPPADC_CK54M_EN
		rtd_maskl(PLL27X_REG_SYS_PLL_27X3_reg,0x00000000,0x00000000);//Power off and rst PLL27x
		rtd_maskl(PLL27X_REG_SYS_PLL_27X3_reg,0x00000000,0x00000017);//Power on PLL27x [4]PLL27X_PS_EN[3]PLL27X_PS_DIV2[2]PLL27X_VCORSTB[1]PLL27X_RSTB[0]PLL27X_POW
		ScalerTimer_DelayXms(5);
	
		//tve reset
	
		sys_srst1_reg.rstn_tve = 1;//[26]RSTN_TVE
		sys_srst1_reg.write_data = 1;
		IoReg_Write32(SYS_REG_SYS_SRST1_reg, sys_srst1_reg.regValue);
		//tve clock enable - digital
		sys_clken1_reg.clken_tve = 1;//[26]CLKEN_TVE
		sys_clken1_reg.write_data = 1;	
		IoReg_Write32(SYS_REG_SYS_CLKEN1_reg, sys_clken1_reg.regValue);
	
		//Set_HD_SEM_NEW_5();
	
		//tve
		drvif_module_tve_AVout_Setting();
	  //rtd_maskl(TV_SB1_ANA_VADC_IDACO_CTRL1_reg,0xFffFF8FF,0x00000100);
		//VDAC source change to no using case, scart-out force background
		drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_TV_TVE);
	
		//tve clock enable - analog
			drvif_module_tve_AVout_Enable(TVE_AVOUT_ENABLE);
	}


void drvif_module_tve_set_mode(TVE_VIDEO_MODE_SEL mode)
{
	switch(mode)
	{
	 case TVE_NTSC:
			drv_tve_set_video_ntsc_m();
	 break;
	 case TVE_NTSC_J:
			drv_tve_set_video_ntsc_j();
	 break;
	 case TVE_NTSC_443:
			drv_tve_set_video_ntsc_443();
	 break;
	 case TVE_PAL_I:
			drv_tve_set_video_pal_i();
	 break;
	 case TVE_PAL_M:
			drv_tve_set_video_pal_m();
	 break;
	 case TVE_PAL_60:
			drv_tve_set_video_pal_60();
	 break;
	 case TVE_PAL_N:
			drv_tve_set_video_pal_cn();
	 break;

	}

}



  /**
  drvif_module_tve_clock_enable

  @param
             < on_off >   clock on or off
  @return <void>         { void }

*/

 void drvif_module_tve_clock_enable(TVE_CLOCK on_off)
 {
	enum CRT_CLK clken = CLK_ON;
	clken = on_off ? CLK_ON : CLK_OFF;
	CRT_CLK_OnOff(SCALER_TVE_2, clken , NULL);
 }


/**
  drvif_module_tve_AVout_MODE

  @param
             < mode >   tve or vd
  @return <void>         { void }

*/

void drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL mode)
{
	//rtd_maskl(IFD_ANALOG_VDAC_SRC_SEL_VADDR,0xf8,mode);
	drvif_vdac_source_sel(mode);
}

/**
  drvif_module_TVE_AVoutEnable

  @param
             < yes_no >   { _YES : select AVout is displaying source
                                    _No : select AVout is not displaying source }
  @return <void>         { void }

*/
void drvif_module_tve_AVout_Enable(TVE_AVOUT_EN on_off)
{
//Access through DAC APIs to avoid unknown error.
/*
	if(on_off==TVE_AVOUT_ENABLE)
		rtdf_maskl(IFD_ANALOG_VDAC_TV_CTRL2_VADDR,~_BIT4, _BIT4);
	else
		rtdf_maskl(IFD_ANALOG_VDAC_TV_CTRL2_VADDR,~_BIT4, 0);
*/
	if(on_off==TVE_AVOUT_ENABLE)
		drvif_vdac_tvdac_power_on(1);
	else
		drvif_vdac_tvdac_power_on(0);
}



/**
  drvif_module_tve_video_memory_setting

  @param

  @return <void>         { void }

   setting the tve video data memory address
*/
#define TVE_VFLIP_SIZE_OFFSET 720*575*2
void drvif_module_tve_video_memory_setting(unsigned char vflip_en)
{
	rtdf_outl(TVE_DMA_TVE_VDDMA_reg,0x20052014);
	if(vflip_en == false){

		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,rtdf_inl(H3DDMA_Cap_L1_Start_reg)/8);	  //  dma addr  //和3d dma差了8倍
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,rtdf_inl(H3DDMA_Cap_L2_Start_reg)/8);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,rtdf_inl(H3DDMA_Cap_L3_Start_reg)/8);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,rtdf_inl(H3DDMA_Cap_L4_Start_reg)/8);	  //  dma addr
	}
	else if(vflip_en == true){
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT0_reg,(rtdf_inl(H3DDMA_Cap_L1_Start_reg)+TVE_VFLIP_SIZE_OFFSET)/8 );	  //  dma addr  //和3d dma差了8倍
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT1_reg,(rtdf_inl(H3DDMA_Cap_L2_Start_reg)+TVE_VFLIP_SIZE_OFFSET)/8);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT2_reg,(rtdf_inl(H3DDMA_Cap_L3_Start_reg)+TVE_VFLIP_SIZE_OFFSET)/8);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_SATRT3_reg,(rtdf_inl(H3DDMA_Cap_L4_Start_reg)+TVE_VFLIP_SIZE_OFFSET)/8);	  //  dma addr
		rtdf_outl(TVE_DMA_TVEVDDMA_LINESTEP_reg, (~0xb4) + 1);
	}
}


/**
  drvif_module_tve_vbi_memory_setting

  @param

  @return <void>         { void }

   setting the tve VBI data memory address
*/
void drvif_module_tve_vbi_memory_setting(unsigned int vbi_addr)
{
	rtdf_outl(TVE_DMA_TVEVBIDMA_CTRL_reg,0x00001200);//use 2 buffer
	//rtdf_outl(TVE_DMA_TVEVBIDMA_START_VADDR,vbi_addr / 8);//dma addr   //和3d dma差了8倍
	rtdf_maskl(TVE_DMA_TVEVBIDMA_START_reg, 0xe0000000, (vbi_addr / 8));
	rtdf_outl(TVE_DMA_TVEVBIDMA_READ_WINDOW_reg,0x00000030);
}
void drvif_module_tve_vbi_pos(UINT32 top_val, UINT32 bottom_val)
{
	UINT32 bottom_enable;
	UINT32 bottom_value;
	UINT32 top_enable;
	UINT32 top_value;
	UINT32 finial_value;

	bottom_enable=0x8000;
	top_enable=0x20;

	bottom_value=bottom_enable|(bottom_val<<6);
	top_value=top_enable|top_val;
	finial_value=top_value|bottom_value;

	rtdf_maskl(TVE_tt_vpos_reg,0xffff0000,finial_value);
}


/**
  drvif_module_tve_vbi_setting

  @param
             < on_off >     { TVE_VBI_DISABLE : use the vbi setting
                                    TVE_VBI_ENABLE :  don not use the vbi setting }
  @return <void>         { void }

notice: when the tve setting (PAL) ,user can use this function
*/

void drvif_module_tve_vbi_setting(TVE_VBI_EN on_off)
{
	//rtdf_outl(TT_VPOS_reg,0x0000cfe6);
	rtdf_outl(TVE_tt_ctrl_reg,0x01088002);
	if(on_off==TVE_VBI_DISABLE)
	{
			rtdf_maskl(TVE_tt_ctrl_reg,0xfffffffc,0x02);
		}
	else
		{
			rtdf_maskl(TVE_tt_ctrl_reg,0xfffffffc,0x03);

		}
	//rtdf_outl(TT_CTRL_reg,0x01089103);


}

/**
  drvif_module_tve_cc_setting

  @param
             < on_off >     { TVE_CC_DISABLE : use the vbi setting
                                    TVE_CC_ENABLE :  don not use the vbi setting }
  @return <void>         { void }

notice: when the tve setting (NTSC) ,user can use this function
*/

void drvif_module_tve_cc_setting(TVE_CC_MODE mode)
{
	//default is mode=3
  	rtdf_maskl(TVE_ip_ccd_enbl_reg,0xfffffffc,mode);
	//rtdf_outl(IP_CCD_ENBL_reg,0x00000003);

}

/**
  drvif_module_tve_cc_data

  @param
  		<data>		wss data

  @return <void>         { void }

notice: when the tve setting (ntsc) ,user can use this function
*/
void drvif_module_tve_cc_data(unsigned int odd_data,unsigned int even_data )
{

	unsigned char odd_data_MSB=0;
	unsigned char odd_data_LSB=0;
	unsigned char even_data_MSB=0;
	unsigned char even_data_LSB=0;
	odd_data_LSB=odd_data&0x00ff;
	odd_data_MSB=(odd_data&0xff00)>>8;
	even_data_LSB=even_data&0x00ff;
	even_data_MSB=(even_data&0xff00)>>8;
	rtdf_outl(TVE_ip_ccd_odd_0_reg,odd_data_LSB);
	rtdf_outl(TVE_ip_ccd_odd_1_reg,odd_data_MSB);
	rtdf_outl(TVE_ip_ccd_even_0_reg,even_data_LSB);
	rtdf_outl(TVE_ip_ccd_even_1_reg,even_data_MSB);

}

void drvif_module_tve_vps_pos(UINT32 value)
{
	UINT32 vps_enable;
	UINT32 vps_value;
	vps_enable=0x4000;
	vps_value=vps_enable|value;
	rtdf_maskl(TVE_vps_ctrl_reg,0xffff800f,vps_value);





}
/**
  drvif_module_tve_vps_setting

  @param
             < on_off >     { TVE_VPS_DISABLE : use the vbi setting
                                    TVE_VPS_ENABLE :  don not use the vbi setting }
  @return <void>         { void }

notice: when the tve setting (PAL) ,user can use this function
*/

void drvif_module_tve_vps_setting(TVE_VPS_EN on_off)
{
	rtdf_maskl(TVE_vps_ctrl_reg,0x00007ff0,0x04348002);

	//rtdf_outl(VPS_CTRL_reg,0x0434c102);
	if(on_off==TVE_VPS_DISABLE)
		rtdf_maskl(TVE_vps_ctrl_reg,0xfffffffc,0x02);
	else
		rtdf_maskl(TVE_vps_ctrl_reg,0xfffffffc,0x03);
	//rtdf_outl(VPS_CTRL_reg,0x0434c103);
}
/**
  drvif_module_tve_vps_data

  @param
  		<data>		vps data

  @return <void>         { void }

notice: when the tve setting (pal) ,user can use this function
*/
void drvif_module_tve_vps_data(Struct_TVE_VPS_DATA *VPS_DATA)
{
	unsigned int vps_data_set = 0;

	//check pointer
	if(VPS_DATA == NULL) {
		pr_debug("NULL pointer in %s\n",__FUNCTION__);
		return;
	}

	//byte 2~5
	vps_data_set = (VPS_DATA->VPS_BYTE_2 << 24) | (VPS_DATA->VPS_BYTE_3 << 16) | (VPS_DATA->VPS_BYTE_4 << 8) | VPS_DATA->VPS_BYTE_5;
	rtdf_outl(TVE_vps_data_0_reg,vps_data_set);

	//byte 6~9
	vps_data_set = 0;
	vps_data_set = (VPS_DATA->VPS_BYTE_6 << 24) | (VPS_DATA->VPS_BYTE_7 << 16) | (VPS_DATA->VPS_BYTE_8 << 8) | VPS_DATA->VPS_BYTE_9;
	rtdf_outl(TVE_vps_data_1_reg,vps_data_set);

	//byte 10~13
	vps_data_set = 0;
	vps_data_set = (VPS_DATA->VPS_BYTE_10 << 24) | (VPS_DATA->VPS_BYTE_11 << 16) | (VPS_DATA->VPS_BYTE_12 << 8) | VPS_DATA->VPS_BYTE_13;
	rtdf_outl(TVE_vps_data_2_reg,vps_data_set);

	//byte 14
	vps_data_set = 0;
	vps_data_set = vps_data_set | VPS_DATA->VPS_BYTE_14;
	rtdf_outl(TVE_vps_data1_reg,vps_data_set);
}

void drvif_module_tve_wss_pos(UINT32 value)
{
	UINT32 pos_enable;
	UINT32 pos_value;
	pos_enable=0x400;
	pos_value=pos_enable|value;
	rtdf_maskl(TVE_wss_pos_reg,0xfffffc00,pos_value);
}


/**
  drvif_module_tve_wss_setting

  @param
             < on_off >     { TVE_WSS_DISABLE : use the vbi setting
                                    TVE_WSS_ENABLE :  don not use the vbi setting }
  @return <void>         { void }

notice: when the tve setting (PAL) ,user can use this function
*/

void drvif_module_tve_wss_setting(TVE_WSS_EN on_off)
{
	//rtdf_maskl(WSS_POS_reg,0xff0007ff,0x429000);//for IC verification
	//rtdf_outl(WSS_POS_reg,0x00429416);
	//rtdf_outl(WSS_CTRL_reg,0x53006aaa);//for IC verification
	if(on_off==TVE_WSS_DISABLE)
		rtdf_maskl(TVE_wss_ctrl_reg,0x1fffffff,0x40000000);
	else
		rtdf_maskl(TVE_wss_ctrl_reg,0x1fffffff,0x60000000);
	//rtdf_outl(WSS_CTRL_reg,0x73006aaa);
}





/**
  drvif_module_tve_wss_data

  @param
  		<data>		wss data

  @return <void>         { void }

notice: when the tve setting (PAL) ,user can use this function
*/

void drvif_module_tve_wss_data(unsigned int data)
{
	unsigned int write_bit=_BIT14;
	unsigned int value=0x00;
	value=data|write_bit;
	rtdf_maskl(TVE_wss_ctrl_reg,0xffff8000,value);

}



void drvif_module_tve_interrupt(int enable)
{
	if(enable)
	{
		pr_debug("drvif_module_tve_interrupt\n");
		//rtdf_outl(TVE_intvbi_i_reg, TVE_intvbi_i_write_en2(1)|TVE_intvbi_i_int_vpos(2)|TVE_intvbi_i_write_en1(1)|TVE_intvbi_i_int_hpos(2));//init interrupt at vpos 2 hpos 2
		rtdf_outl(TVE_inten_reg, TVE_inten_inten_i(1)|TVE_inten_write_data(1)); //enable tve interrupt
		rtdf_outl(TVE_intpos_i_reg, TVE_intpos_i_write_en2(1)|TVE_intpos_i_int_vpos(2)|TVE_intpos_i_write_en1(1)|TVE_intpos_i_int_hpos(2));//init interrupt at vpos 2 hpos 2
	}
	else
	{
		rtdf_outl(TVE_DMA_TVEVDDMA_LINESTEP_reg, 0xb4); //line step=>720x16/64 = 180 = 0xb4
		rtdf_outl(TVE_inten_reg, TVE_inten_inten_i(1)|TVE_inten_write_data(1));
		rtdf_outl(TVE_inten_reg, TVE_inten_inten_i(1));
	}

}

void drvif_module_tve_forcebg(int enable)
{
	if(enable)
	{
	//	WaitFor_IEN_STOP2();
		rtdf_outl(TVE_av_ctrl_reg, 0x07);
	}
	else
	{
	//	WaitFor_IEN_STOP2();
		rtdf_outl(TVE_av_ctrl_reg, 0x7e);
	}
}

void drvif_module_tve_change_memory_setting(unsigned int in_width, unsigned char vflip_en){
	unsigned int line_step = 0;
	//tve_dma_tve_vddma_RBUS tve_dma_tve_vddma_reg;

	//tve_dma_tve_vddma_reg.regValue = rtdf_inl(TVE_DMA_TVE_VDDMA_VADDR);

	//line step
	/*if(in_width < 720){
		line_step = 720 * 16 / 64;
	}
	else{
		line_step = 720 * 16 / 64;
	}*///fix Coverity 147414
	line_step = 720 * 16 / 64;

	//num,length,remain
	//tve_dma_tve_vddma_reg.tve_vddma_num = line_step / 32;
	//tve_dma_tve_vddma_reg.tve_vddma_remain = line_step % 32;
	//rtdf_outl(TVE_DMA_TVE_VDDMA_VADDR, tve_dma_tve_vddma_reg.regValue);
	if  (scaler_dispDtoI3ddma_get_enable() == FALSE) {
	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
		line_step = line_step / 2;
	}

	tve_new_linestep = line_step;

	if(vflip_en == true){
		line_step = (~line_step) + 1;
	}

	pr_debug("[crixus]line_step = %x\n",line_step);

	rtdf_outl(TVE_DMA_TVEVDDMA_LINESTEP_reg, line_step);
}


void drvif_module_tve_reset(void){
	//VDAC source change to no using case, scart-out force background
	drvif_module_tve_AVout_MODE(VDAC_TV_SRC_SEL_IFD_DEBUG);


	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_TVE_3, clken , NULL);

	//tve clock disable - analog
    	drvif_module_tve_AVout_Enable(TVE_AVOUT_DISABLE);
	//tve ip reset

	CRT_CLK_OnOff(SCALER_TVE_4, clken , NULL);

}


void drvif_module_tve_vbi_tt_line_num(UINT32 line_num)
{
	UINT32 finial_value;
	UINT32 enable_bit;

	enable_bit=0x1000;
	finial_value=enable_bit|(line_num << 4);
	//printk("finial_value = %x\n",finial_value);
	rtdf_maskl(TVE_tt_ctrl_reg,0xfffff00f,finial_value);
}

void drvif_module_tve_vbidma_trigger(UINT8 trigger_en){
	//dege trigger
	if(trigger_en == 0)
		rtdf_maskl(TVE_DMA_TVEVBIDMA_START_reg, 0x1fffffff, 0x00000000);
	else
		rtdf_maskl(TVE_DMA_TVEVBIDMA_START_reg, 0x1fffffff, 0x20000000);
}

void drvif_tve_resume_setting(void)
{


	//PLL RST and Enable CLK
	//initialize clk for VD
	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_TVE_5, clken , NULL);

}













