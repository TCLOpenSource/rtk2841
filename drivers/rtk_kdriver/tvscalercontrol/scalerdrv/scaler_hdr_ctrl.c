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
#include <linux/pageremap.h>
#include <uapi/linux/const.h>
//#include <mach/io.h>

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
#include <tvscalercontrol/scalerdrv/scaler_hdr_rpc.h>
#endif
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <tvscalercontrol/hdmirx/hdmi_reg.h>
#include <rbus/hdmi_p0_reg.h>
#include <rbus/h3ddma_reg.h>

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
#include <rbus/vgip_reg.h>
#include <rbus/dma_vgip_reg.h>
#include <rbus/h3ddma_hsd_reg.h>
#include <rbus/h3ddma_rgb2yuv_dither_4xxto4xx_reg.h>
#include <rbus/timer_reg.h>
#include <tvscalercontrol/i3ddma/i3ddma.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/dolby_v_top_reg.h>
#include <rbus/di_reg.h>
#include <rbus/ppoverlay_reg.h>

// register dump
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

#define MAX_MD_PKT_BODY_SIZE (100*128)
static HDR_STATE curHdrState={0,0,0};
unsigned char *metadataBody=NULL;
static VIDEO_RPC_DOBLBY_VISION_SHM *hdrDVShmAddr=NULL;
static unsigned int last_WrIdx=0;
#endif

//static unsigned char bHdmiDetectResult=0;
static SCALER_HDR_DOLBY_VISION_HDMI_MODE dv_hdmiDetectState=SLR_DV_HDMI_DETECT_OFF;
static SCALER_HDR10_HDMI_MODE hdr10_hdmiDetectState=SLR_HDR10_HDMI_DETECT_OFF;
static unsigned int hdr10_hdmi_input_ACT_WID=0;

unsigned char Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Result(void)
{
    if((get_HDMI_HDR_mode() == HDR_DOLBY_HDMI)||((drvif_Hdmi_GetColorSpace() == COLOR_RGB) && (drvif_Hdmi_GetInterlace() == 0)))
	{
		//pr_emerg("[%d,%d,%d]\n",(rtd_inl(HDMI_MDD_SR_reg) & _BIT0),((rtd_inl(0xB80258A8) & (_BIT3|_BIT4)) >> 3),((rtd_inl(0xb8028300) & _BIT1) >> 1));
	    //return (rtd_inl(HDMI_MDD_SR_reg) & _BIT0) && ((rtd_inl(H3DDMA_I3DDMA_MDP_CR_reg) & _BIT3) >> 3);
	    return (rtd_inl(HDMI_MDD_SR_reg) & _BIT0);
	}
    else
    {
		return 0;
	}
}


SCALER_HDR_DOLBY_VISION_HDMI_MODE Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Status(void)
{
	return dv_hdmiDetectState;
}


void Scaler_HDR_DolbyVision_Hdmi_Set_Detect_Status(SCALER_HDR_DOLBY_VISION_HDMI_MODE detectStatus)
{
	if(dv_hdmiDetectState != detectStatus){
		pr_debug("[DolbyVision] HdmiSt=%d->%d\n", dv_hdmiDetectState, detectStatus);
		dv_hdmiDetectState = detectStatus;
	}
}


SCALER_HDR10_HDMI_MODE Scaler_HDR10_Hdmi_Get_Detect_Status(void)
{
	return hdr10_hdmiDetectState;
}


void Scaler_HDR10_Hdmi_Set_Detect_Status(SCALER_HDR10_HDMI_MODE detectStatus)
{
	if(hdr10_hdmiDetectState != detectStatus){
		pr_debug("[HDR10] HdmiSt=%d->%d\n", hdr10_hdmiDetectState, detectStatus);
		hdr10_hdmiDetectState = detectStatus;
	}
}

void Scaler_HDR10_Hdmi_Set_Input_ACT_WID_info(unsigned int ACT_WID)
{
	if(hdr10_hdmi_input_ACT_WID != ACT_WID){
		pr_debug("hdr10_hdmi_input_ACT_WID-> ACT_WID=%d->%d\n", hdr10_hdmi_input_ACT_WID,ACT_WID);
		hdr10_hdmi_input_ACT_WID = ACT_WID;
	}
}


unsigned int Scaler_HDR10_Hdmi_Get_Input_ACT_WID_info(void)
{
	return hdr10_hdmi_input_ACT_WID;
}


// Dolby Vision RPC control
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
#define DV_DETECT_COND_NO_MD_CHECK 1            // md detect pass when no_md == 0
#define DV_DETECT_COND_MD_VERSION_CHECK 1   // md detect pass when metadata_version == 0
#define DV_DETECT_COND_MD_TYPE_CHECK 1        // md detect pass when Type == 0 or Type 1->2->2->?K->2->3
#define DV_DETECT_COND_DET_CON_ENTER 1         // md detect pass when CRC detect result correct in <N> times
#define DV_DETECT_COND_DET_CON_EXIT 1         // md detect extra pass when CRC & extra condition detect result correct in <N> times
void Scaler_HDR_DolbyVision_Hdmi_SetDetectConditionExtra_Init(unsigned char enable)
{
    hdmi_p0_port0_mdd_cr_RBUS hdmi_p0_port0_mdd_cr_reg;

    hdmi_p0_port0_mdd_cr_reg.regValue = rtd_inl(HDMI_P0_PORT0_MDD_CR_reg);
    // detect condition extra enable
    hdmi_p0_port0_mdd_cr_reg.det_con_extra = enable;

    // detect condition extra options (function enable no matter det_con_extra=0 or 1)
    hdmi_p0_port0_mdd_cr_reg.no_md_check = DV_DETECT_COND_NO_MD_CHECK;
    hdmi_p0_port0_mdd_cr_reg.metadata_version_check = DV_DETECT_COND_MD_VERSION_CHECK;
    hdmi_p0_port0_mdd_cr_reg.metadata_type_check = DV_DETECT_COND_MD_TYPE_CHECK;

    // detect result enter/exit condition counter (function enable only when set det_con_extra=1)
    hdmi_p0_port0_mdd_cr_reg.det_con_enter = DV_DETECT_COND_DET_CON_ENTER;  // detect result pass condition counter
    hdmi_p0_port0_mdd_cr_reg.det_con_extra = DV_DETECT_COND_DET_CON_EXIT;  // detect result fail condition counter

    rtd_outl(HDMI_P0_PORT0_MDD_CR_reg, hdmi_p0_port0_mdd_cr_reg.regValue);
    return;
}

extern void scaler_dolby_enable_idmacap2_metadata(unsigned char enable);
int Scaler_HDR_DolbyVision_Hdmi_SetDetectEnable(unsigned char detectEn, unsigned char dispEn)
{
#if 1
	enum PLAFTORM_TYPE platform = get_platform();
	if (PLATFORM_KXLP == platform) //Disable dolby function in K3Lp platform
	{
		pr_debug("Current platform is K3Lp, disable dolby function\n");
		return 1;
	}
#endif	
	VIDEO_RPC_DOLBY_VISION_HDMI_SET_DETECT_ENABLE detectInfo;
	int i;

	pr_debug("%s, detect/Disp en=%d/%d\n", __FUNCTION__, detectEn, dispEn);

	//when hdmi detect timing, enable i3dma cap2 metadata
    //scaler_dolby_enable_idmacap2_metadata(detectEn); //mark for restore #7700 issue
	#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	if(hdrDVShmAddr == NULL){
		hdrDVShmAddr = (VIDEO_RPC_DOBLBY_VISION_SHM *)Scaler_GetShareMemVirAddr(SCALERIOC_GET_HDMI_HDR_FRAMEINFO);
		if(hdrDVShmAddr == NULL){
			pr_debug("*** [ERR] hdrDVShmAddr is NULL@%s\n");
			return 1;
		}else{
			// reset write index
			hdrDVShmAddr->picQWr = 0;
			hdrDVShmAddr->picQRd = 0;
		}
	}
	if(detectEn)
	{
		Scaler_HDR_DolbyVision_Hdmi_SetDetectConditionExtra_Init(true);
		rtd_maskl(HDMI_MDD_CR_reg, ~_BIT0, _BIT0);
	}
	else
	{
		Scaler_HDR_DolbyVision_Hdmi_SetDetectConditionExtra_Init(false);
		rtd_maskl(HDMI_MDD_CR_reg, ~_BIT0, 0);
	}
	#else
	detectInfo.instanceID = 0;
	detectInfo.detect_en = htonl(detectEn);
	detectInfo.display_en = htonl(dispEn);
	for(i=0; i<2; i++){
		detectInfo.capInfo.bufAddr_md[i].phyaddr = htonl(0x300);
		detectInfo.capInfo.bufAddr_md[i].size = htonl(0x300);
		detectInfo.capInfo.bufAddr_video[i].phyaddr = htonl(0x500);
		detectInfo.capInfo.bufAddr_video[i].size = htonl(0x500);
		detectInfo.capInfo.bufAddr_graph[i].phyaddr = htonl(0x700);
		detectInfo.capInfo.bufAddr_graph[i].size = htonl(0x700);
	}

	if(Scaler_HDR_vrpc_DolbyVision_Hdmi_SetDetectEnable(&detectInfo))
	{
		pr_debug("RPC Scaler_HDR_vrpc_DolbyVision_Hdmi_Get_Detect_Info failed\n");
		return 1;
	}
	#endif
	Scaler_HDR_DolbyVision_Hdmi_Set_Detect_Status(detectEn? SLR_DV_HDMI_DETECT_ON: SLR_DV_HDMI_DETECT_OFF);

	return 0 ;
}



int Scaler_HDR_DolbyVision_Hdmi_Get_Detect_Info(unsigned int *result)
{

	VIDEO_RPC_DOLBY_VISION_HDMI_GET_DETECT_INFO detectInfo;

	if(!result){
		pr_debug("NULL PTR@%s\n", __FUNCTION__);
		return 1;
	}

	//pr_debug("%s\n", __FUNCTION__);

	detectInfo.instanceID = 0;
	detectInfo.detect_ret = 0;

	if(Scaler_HDR_vrpc_DolbyVision_Hdmi_Get_Detect_Info(&detectInfo))
	{
		pr_debug("RPC rhal_vrpc_DolbyVision_Hdmi_Get_Detect_Info failed\n");
		return 1;
	}

	*result = htonl(detectInfo.detect_ret);
	//pr_debug("detect result=%d\n", *result);

	return 0;
}



int Scaler_HDR_DolbyVision_Hdmi_SetDisplaytEnable(unsigned char dispEn)
{

	VIDEO_RPC_DOLBY_VISION_HDMI_SET_DISPLAY_ENABLE dispInfo;

	pr_debug("%s, Disp en=%d\n", __FUNCTION__, dispEn);
	#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	HDR_DolbyVision_Set_CurHdrDispMode(dispEn);
	#else
	dispInfo.instanceID = 0;
	dispInfo.display_en = htonl(dispEn);

	if(Scaler_HDR_vrpc_DolbyVision_Hdmi_SetDisplayEnable(&dispInfo))
	{
		pr_debug("RPC KADP_VSC_DolbyVision_Hdmi_SetDisplaytEnable failed\n");
		return 1;
	}
	#endif
	return 0;
}

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
void HDR_DolbyVision_Set_DolbyMode(HDR_MODE dMode)
{

	return;//Do set v top. Control by scaler flow
	rtd_maskl(DOLBY_V_TOP_TOP_CTL_reg, ~DOLBY_V_TOP_TOP_CTL_dolby_mode_mask, DOLBY_V_TOP_TOP_CTL_dolby_mode(dMode));
	if(rtd_inl(DOLBY_V_TOP_TOP_D_BUF_reg) & DOLBY_V_TOP_TOP_D_BUF_dolby_double_en_mask)
		rtd_maskl(DOLBY_V_TOP_TOP_D_BUF_reg, ~DOLBY_V_TOP_TOP_D_BUF_dolby_double_apply_mask, DOLBY_V_TOP_TOP_D_BUF_dolby_double_apply_mask);

	return;
}

void HDR_DolbyVision_Set_CurDolbyMode_Status(HDR_MODE hdrDolbyMode)
{
	pr_debug("[DV] HdrMode=%d->%d\n", curHdrState.hdrDolbyMode, hdrDolbyMode);

	// set Dolby mode to bypass
	// [TODO] MOVE TO DATA END
	if(hdrDolbyMode == HDR_MODE_DISABLE)
		HDR_DolbyVision_Set_DolbyMode(HDR_MODE_DISABLE);

	curHdrState.hdrDolbyMode = hdrDolbyMode;
	return;
}

void HDR_DolbyVision_Set_CurHdrDispMode(HDR_DISP_MODE dispMode)
{
	pr_debug("[DV] HdrDispMode=%d->%d\n", curHdrState.hdrDispMode, dispMode);

	curHdrState.hdrDispMode = dispMode;

	if(!dispMode)
	{
		HDR_DolbyVision_Set_CurHdmiMode(DOLBY_HDMI_OFF);
		HDR_DolbyVision_Set_CurDolbyMode_Status(HDR_MODE_DISABLE);
		rtd_maskl(0xB8005304, ~_BIT29, 0); //clear the vsync reseten
	}
	return;
}



void HDR_DolbyVision_Set_CurHdmiMode(DOLBY_HDMI_MODE hdmiMode)
{
	pr_debug("[DV] HdmiMode=%d->%d\n", curHdrState.hdrHdmiMode, hdmiMode);

	// IDMA capture disable
	if((hdmiMode == DOLBY_HDMI_OFF) && (curHdrState.hdrHdmiMode >= DOLBY_HDMI_IDMA_INIT)){
		HDR_DolbyVision_Set_DolbyMode(HDR_MODE_DISABLE);
		drvif_hdr_idma_enable(FALSE);
		pr_debug("[DV] IDMA Disabled!!\n");
	} // IDMA capture init
	else if(hdmiMode == DOLBY_HDMI_IDMA_INIT){
		drvif_hdr_idma_enable(TRUE);
		if(hdrDVShmAddr != NULL)
		{//Minchay@20160309 reset DV shm Queue
		    last_WrIdx = 0;
			//hdrDVShmAddr->picQWr = 0;
			//hdrDVShmAddr->picQRd = 0;
			memset(hdrDVShmAddr,0, sizeof(VIDEO_RPC_DOBLBY_VISION_SHM));
		}
		pr_debug("[DV] IDMA Enabled!!\n");
	}

	curHdrState.hdrHdmiMode = hdmiMode;
	return;
}



HDR_MODE HDR_DolbyVision_Get_CurDolbyMode(void)
{
	return curHdrState.hdrDolbyMode;
}



DOLBY_HDMI_MODE HDR_DolbyVision_Get_CurHdmiMode(void)
{
	return curHdrState.hdrHdmiMode;
}



HDR_DISP_MODE HDR_DolbyVision_Get_CurHdrDispMode(void)
{
	return curHdrState.hdrDispMode;
}



// Dolby Vision HDMI mode detect
unsigned char HDR_DolbyVision_HDMI_check_mode(void)
{
    unsigned char bColorSpaceCheck = (HDR_DolbyVision_Get_CurDolbyMode() ==  HDR_DOLBY_HDMI)   || (drvif_Hdmi_GetColorSpace() == COLOR_RGB);

	// check Dolby Vision detect result
	if(rtd_inl(HDMI_MDD_CR_reg) & _BIT0){
		static unsigned char last_bDolbyVisionDet=0;
        unsigned char bDolbyVisionDetResult= (bColorSpaceCheck? rtd_inl(HDMI_MDD_SR_reg) & (_BIT0|_BIT1): 0);

		if((last_bDolbyVisionDet & _BIT0) != (bDolbyVisionDetResult & _BIT0)){
			pr_debug("[DV] Hdmi Detect=%d\n", bDolbyVisionDetResult & _BIT0);
			last_bDolbyVisionDet = bDolbyVisionDetResult;
			rtd_maskl(HDMI_MDD_SR_reg, _BIT1, 0);
		}
		return (bDolbyVisionDetResult & _BIT0);
	}else
		return 0;
}

void forcebg_wait_porch(unsigned int channel)
{
	//dtg_lc_RBUS dtg_lc_reg;
 	//dtg_pending_status_RBUS dtg_pending_status_reg;
 	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	unsigned int timeoutcount = 0x3ffff;
	unsigned int uzulinecntA =0;
	unsigned int uzulinecntB =0;
	ppoverlay_new_meas1_linecnt_real_RBUS new_meas1_linecnt_real_Reg;
	unsigned int stc_in = rtd_inl(0xB801B6A8);

	if(channel == SLR_MAIN_DISPLAY){//main channel
		dv_den_start_end_reg.regValue = rtd_inl(PPOVERLAY_DV_DEN_Start_End_reg);
		do {
			new_meas1_linecnt_real_Reg.regValue = rtd_inl(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntA = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			new_meas1_linecnt_real_Reg.regValue = rtd_inl(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntB = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			if((uzulinecntA == uzulinecntB)&&((uzulinecntA < (dv_den_start_end_reg.dv_den_sta)) || (uzulinecntA > (dv_den_start_end_reg.dv_den_end)))) {
				rtd_maskl(PPOVERLAY_Main_Display_Control_RSV_reg, ~(_BIT1), _BIT1);
				break;
			}
			timeoutcount--;
		} while(timeoutcount);

		rtd_maskl(PPOVERLAY_Double_Buffer_CTRL_reg, ~_BIT2, 0);

		if(timeoutcount == 0){
			rtd_maskl(PPOVERLAY_Main_Display_Control_RSV_reg, ~(_BIT1), _BIT1);
			rtd_maskl(PPOVERLAY_Double_Buffer_CTRL_reg, ~_BIT2, 0);
			pr_debug("[FBG MAIN]timeout error!!!\n");
		}
	}
	else{//sub channel
		dv_den_start_end_reg.regValue = rtd_inl(PPOVERLAY_DV_DEN_Start_End_reg);
		do {
			new_meas1_linecnt_real_Reg.regValue = rtd_inl(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntA = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			new_meas1_linecnt_real_Reg.regValue = rtd_inl(PPOVERLAY_new_meas1_linecnt_real_reg);
			uzulinecntB = new_meas1_linecnt_real_Reg.uzudtg_line_cnt_rt;
			if((uzulinecntA == uzulinecntB)&&((uzulinecntA < (dv_den_start_end_reg.dv_den_sta)) || (uzulinecntA > (dv_den_start_end_reg.dv_den_end)))) {
				rtd_maskl(PPOVERLAY_MP_Layout_Force_to_Background_reg, ~(_BIT1), _BIT1);
				break;
			}
			timeoutcount--;
		} while(timeoutcount);

		rtd_maskl(PPOVERLAY_Double_Buffer_CTRL_reg, ~_BIT2, 0);

		if(timeoutcount == 0){
			rtd_maskl(PPOVERLAY_MP_Layout_Force_to_Background_reg, ~(_BIT1), _BIT1);
			rtd_maskl(PPOVERLAY_Double_Buffer_CTRL_reg, ~_BIT6, 0);
			pr_debug("[FBG SUB]timeout error!!!\n");
		}

	}

	pr_debug("[HDR] WT=%d@%d\n", timeoutcount, (rtd_inl(0xB801B6A8) - stc_in)/90);
	return;
}

void mdomain_capture_disable(int enable)
{
	if(enable)
		rtd_maskl(MDOMAIN_CAP_Cap_In1_enable_reg, ~(_BIT0), 0);
	else
		rtd_maskl(MDOMAIN_CAP_Cap_In1_enable_reg, ~(_BIT0), _BIT0);


}

void mdomain_capture_freeze(int enable)
{
	mdomain_cap_ddr_in1ctrl_RBUS mdomain_cap_ddr_in1ctrl_reg;
	mdomain_cap_cap_reg_doublbuffer_RBUS mdomain_cap_cap_reg_doublbuffer_reg;

	mdomain_cap_cap_reg_doublbuffer_reg.regValue =rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
	mdomain_cap_ddr_in1ctrl_reg.regValue = rtd_inl(MDOMAIN_CAP_DDR_In1Ctrl_reg);
	mdomain_cap_ddr_in1ctrl_reg.in1_freeze_enable = enable;
	rtd_outl(MDOMAIN_CAP_DDR_In1Ctrl_reg, mdomain_cap_ddr_in1ctrl_reg.regValue);

	if(mdomain_cap_cap_reg_doublbuffer_reg.cap1_db_en){
		mdomain_cap_cap_reg_doublbuffer_reg.cap1_db_apply = 1;
		rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg, mdomain_cap_cap_reg_doublbuffer_reg.regValue);
	}

	return;
}



void DI_freeze(int enable)
{
	di_im_di_weave_window_control_RBUS di_weave_window_control_reg;
	di_weave_window_control_reg.regValue = rtd_inl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
	di_weave_window_control_reg.freeze = enable;
	rtd_outl(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, di_weave_window_control_reg.regValue);

	di_db_reg_ctl_RBUS di_db_reg_ctl_reg ;
	di_db_reg_ctl_reg.regValue = rtd_inl(DI_db_reg_ctl_reg);
	if(di_db_reg_ctl_reg.db_en){
		di_db_reg_ctl_reg.db_apply = 1;
		rtd_outl(DI_db_reg_ctl_reg, di_db_reg_ctl_reg.regValue);
	}

	return;
}


void HDR_DolbyVision_HDMI_md_packet_process(void)
{
	h3ddma_i3ddma_mdp_cr_RBUS i3ddma_mdp_cr_reg;
	HDR_DOLBY_VISION_METADATA_PACKET *metadataPkt;
	int mdPktCnt=0, lastMultiPktCnt=0;
	unsigned int pktLen=0, pktWrtTotal=0;
	unsigned int dumpMdRegAddr, rdIdx;
	unsigned int pktCrc32=0;
	unsigned char bMatchFirstFlag=0, bInvalidPktFlag=0;
	dma_vgip_dma_vgip_act_hsta_width_RBUS	 dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_chn1_act_hsta_width_reg.regValue = rtd_inl(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	
	unsigned char *md_m1_cache_adress = i3ddmaCtrl.cap_buffer[1].uncache + 0x00;
	unsigned char *md_m2_cache_adress = i3ddmaCtrl.cap_buffer[1].uncache + (0x10000);
	unsigned char *md_m3_cache_adress = i3ddmaCtrl.cap_buffer[1].uncache + (0x20000);
	unsigned char *md_m4_cache_adress = i3ddmaCtrl.cap_buffer[1].uncache + (0x30000);

	// exit when md_parser not actived
	if((rtd_inl(H3DDMA_Cap_CTL2_reg) & _BIT31) == 0)
		return;

	// check IDMA vgip line count
	//if(HDR_DolbyVision_HDMI_check_idmaLineCountTimeout(IDMA_CAP2_LAST_WRT_DEND_LC))
	//	return;

	// read the latest md capture buffer data
	rdIdx = (rtd_inl(H3DDMA_Cap_Status_2_reg) & _BIT6? 1: 0);

	if(rdIdx)
		metadataPkt = (HDR_DOLBY_VISION_METADATA_PACKET*)md_m2_cache_adress;
	else
		metadataPkt = (HDR_DOLBY_VISION_METADATA_PACKET*)md_m1_cache_adress;

	i3ddma_mdp_cr_reg.regValue = rtd_inl(H3DDMA_I3DDMA_MDP_CR_reg);
	
	if(hdrDVShmAddr == NULL){
		pr_debug("[ERR] hdrDVShmAddr is NULL@%s\n",__FUNCTION__);
		return;
	}else{
		// write to MD M4 capture start address (not used mmomory space)
		metadataBody = (unsigned char*)(md_m4_cache_adress +(hdrDVShmAddr->picQWr * MAX_MD_PKT_BODY_SIZE));
	}
	//ROSPrintf("Wrt to Mp4 %x/%x\n", (unsigned int)metadataBody, vo_rtd_inl(H3DDMA_md_m4_Start_reg));
	
	// [little endian] for little endian platform (ARM)
		pktCrc32 = htonl(metadataPkt->CRC32);
	do{
		// 1st packet type should be 0: single ot 1: 1st of multi-packet
		if(!bMatchFirstFlag && (metadataPkt->hdrByte0.packet_type > 1)){
			//mdomain_capture_freeze(true);
			pr_debug("[ERR] Invalid type[%d]@CRC[%x]\n", metadataPkt->hdrByte0.packet_type, pktCrc32);
			bInvalidPktFlag = 1;
		}

		// check packet length when single packet or 1st of multi-packet
		if(!bInvalidPktFlag && !bMatchFirstFlag && (metadataPkt->hdrByte0.packet_type <= 1))
			pktLen = ((metadataPkt->body_byte[0] & 0xff)<<8) | (metadataPkt->body_byte[1] & 0xff);

		if(!bInvalidPktFlag && (pktLen > MAX_MD_PKT_BODY_SIZE)) {
			//mdomain_capture_freeze(true);
			pr_debug("[ERR] Invalid size[%x]\n", pktLen);
			bInvalidPktFlag = 1;
		}

		if(metadataPkt->hdrByte2.EOS)
		{
			pr_debug("EOS forcebg\n");
			forcebg_wait_porch(SLR_MAIN_DISPLAY);
			break;
			
		}
		// write to packet body buffer
		if(!bInvalidPktFlag && (i3ddma_mdp_cr_reg.mode == 1) && (pktCrc32 == 0x1)){
	#if 1 // write to packet body buffer
			if(metadataBody == NULL){
				pr_debug("***** [ERR] metadataBody PTR@NULL!!*****\n");
				return;
			}

			if(metadataPkt->hdrByte0.packet_type <= 1){ // packet body= Byte[2]~Byte[120] (size=119byte)
				//
				memcpy(metadataBody, &metadataPkt->body_byte[2], 119);
				pktWrtTotal = 119;
				bMatchFirstFlag = 1;
			}else if(metadataPkt->hdrByte0.packet_type <= 3){ // packet body= Byte[0]~Byte[120] (size=121byte)
				memcpy(metadataBody+pktWrtTotal, &metadataPkt->body_byte[0], 121);
				pktWrtTotal += 121;
			}
	#else
			ROSPrintf("%d|%d|%d|%d,%d|%d(%x), len=%d,%x@%x\n",
				metadataPkt->hdrByte0.packet_type, metadataPkt->hdrByte0.metadata_type, metadataPkt->hdrByte0.metadata_version, metadataPkt->hdrByte0.no_md,
				metadataPkt->hdrByte1.affected_metadata_id, metadataPkt->hdrByte1.current_metadata_id,
				*(unsigned int*)((vo_rtd_inl(dumpMdRegAddr))|0xa0000000),
				pktLen,
				pktCrc32, (unsigned int)metadataPkt);
	#endif
		}
#if 0 // [TEST] metadata test
		else if(i3ddma_mdp_cr_reg.mode == 2){ // dump to UART
			int j;
			ROSPrintf("%d|%d|%d|%d,%d|%d(%x), len=%d,%x@%x\n",
				metadataPkt->hdrByte0.packet_type, metadataPkt->hdrByte0.metadata_type, metadataPkt->hdrByte0.metadata_version, metadataPkt->hdrByte0.no_md,
				metadataPkt->hdrByte1.affected_metadata_id, metadataPkt->hdrByte1.current_metadata_id,
				*(unsigned int*)((vo_rtd_inl(dumpMdRegAddr))|0xa0000000),
				pktLen,
				pktCrc32, (unsigned int)metadataPkt);

			// dump 128 metadata packet
			for(j=0; j<32; j++){
				if(j % 4 == 0)
					ROSPrintf("\n%x ", (unsigned int)((unsigned int*)metadataPkt+j));
				ROSPrintf("%x ", *((unsigned int*)metadataPkt+j));
			}
			ROSPrintf("\n\n");
		}
#endif

		// exit when packet type=0(single packet) or =3(last packet in multiple packet)
		if(!bInvalidPktFlag &&
			(((metadataPkt->hdrByte0.packet_type == 0) && (pktCrc32 == 0x1))||
			((metadataPkt->hdrByte0.packet_type == 3) && (((i3ddma_mdp_cr_reg.mode == 1) && (pktCrc32 == 0x1))|| (i3ddma_mdp_cr_reg.mode == 2)|| (++lastMultiPktCnt > 2)))))
		{
#if 1 // write to buffer for SCPU DM parser
			// update Dolby Vision frame info share memory
			if(hdrDVShmAddr){
				//static unsigned int last_WrIdx=0;
				h3ddma_lr_separate_ctrl2_RBUS lr_separate_ctrl2_reg;
				unsigned int curWrIdx=hdrDVShmAddr->picQWr;
				unsigned char rptPktFlag=0;
				unsigned int md_err=0;
				md_err |= ((i3ddma_mdp_cr_reg.mode != 1) || (pktCrc32 != 0x1)? _BIT0: 0);
				md_err |= ((pktWrtTotal < pktLen)|| ((pktWrtTotal - pktLen) > 120)? _BIT1: 0);

				if((pktLen == hdrDVShmAddr->frameInfo[last_WrIdx].md_pktSize)
					&& (memcmp((unsigned char*)hdrDVShmAddr->frameInfo[last_WrIdx].md_bufPhyAddr, metadataBody, pktLen) == 0))
				{
					rptPktFlag = 1;
					pr_debug("[%d]Rpt %x/%x\n", curWrIdx, hdrDVShmAddr->frameInfo[last_WrIdx].md_bufPhyAddr, (unsigned int)metadataBody);
				}

				if(md_err)
				{
				#if 0
					if(dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid <= 1920){
						DI_freeze(true);
					}else{
						mdomain_capture_disable(true);
					}
				#endif
					forcebg_wait_porch(SLR_MAIN_DISPLAY);
					pr_debug("***** [ERR] S.md CRC error[%d], info[%d/%d/%d/%d],len %d/%d@crc=%d !!*****\n", md_err,
						metadataPkt->hdrByte0.packet_type, metadataPkt->hdrByte0.metadata_type, metadataPkt->hdrByte0.metadata_version, metadataPkt->hdrByte0.no_md,
						pktLen, pktWrtTotal, pktCrc32);
					break;
				}

				lr_separate_ctrl2_reg.regValue = rtd_inl(H3DDMA_LR_Separate_CTRL2_reg);

				/* video info */
				hdrDVShmAddr->frameInfo[curWrIdx].isHdmi = 1;			// Dolby Vision mode (0: HDMI mode, 1: Normal mode)
				hdrDVShmAddr->frameInfo[curWrIdx].picWidth = lr_separate_ctrl2_reg.hact; // picture width
				hdrDVShmAddr->frameInfo[curWrIdx].picLen = lr_separate_ctrl2_reg.vact; // picture height
				hdrDVShmAddr->frameInfo[curWrIdx].picRatioMode = 0; // normal mode BL/EL ratio (0: 1/4 mode, 1: 1:1 mode)

				/* capture buffer info */
				hdrDVShmAddr->frameInfo[curWrIdx].md_status = md_err;	// md_parse error status (0: OK, B[0]: CRC error, B[1]: size error)
				hdrDVShmAddr->frameInfo[curWrIdx].md_pts = ((rtd_inl(TIMER_VCPU_CLK90K_LO_reg) & ~_BIT0)|rptPktFlag);	// update buffer index time, B[0]: repeat packet flag
				hdrDVShmAddr->frameInfo[curWrIdx].md_pktSize = pktLen;	// metadata body size
				//hdrDVShmAddr->frameInfo[curWrIdx].md_bufPhyAddr = (md_err? 0x0: (unsigned int)metadataBody); // metatdata buffer address
				hdrDVShmAddr->frameInfo[curWrIdx].md_bufPhyAddr = (unsigned int)metadataBody; //20161122@modify for coverity issues,ID:147307

				// update write index
				//if((vo_rtd_inl(0xb8022288) & _BIT17) == 0)
				hdrDVShmAddr->picQWr = (curWrIdx >= 15? 0: curWrIdx+1);
				last_WrIdx = curWrIdx;
			#if 1
				if(dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid <= 1920){
					DI_freeze(false);
				}else{
					mdomain_capture_disable(false);
				}
			#endif
				
				//	enable timer6 interrupt (trigger timer ISR on SCPU
				rtd_outl(TIMER_TC6ICR_reg, TIMER_TC6ICR_tc6ie_mask);
				// enable timer6
				rtd_outl(TIMER_TC6CR_reg, TIMER_TC6CR_tc6en_mask);

				// send RPC to Linux kernel
					//VO_SendKernelRPC(RPC_VCPU_ID_0x112_HDR_FRAMEINFO, HDR_DOLBY_HDMI, curWrIdx, NONBLOCK_MODE);
					//Warning("[ERR] NEED FIX RPC ERROR@%s\n", __FUNCTION__);
			}
			//if((pktWrtTotal < pktLen)|| ((pktWrtTotal - pktLen) > 120)){
			//	ROSPrintf("[ERR] Wrt = %d/%d\n", pktWrtTotal, pktLen);
			//}
#else // dump metadataBody data
			int i;
			if(pktWrtTotal >= pktLen){
				unsigned int dumpCnt = (pktLen/4)+(pktLen%4? 1: 0);
				// dump packet body
				for(i=0; i<dumpCnt; i++){
					if(i % 4 == 0)
						printk("\n%x ", (unsigned int)((unsigned int*)metadataBody+i));
					printk("%x ", *((unsigned int*)metadataBody+i));
				}
				printk("\n");
			}
			printk("Wrt = %d/%d\n", pktWrtTotal, pktLen);
#endif
			break;
		}

		if(!bInvalidPktFlag && bMatchFirstFlag && (((i3ddma_mdp_cr_reg.mode == 2)) || (((i3ddma_mdp_cr_reg.mode == 1)) && (pktCrc32 == 0x1)))){ // jump to next non-repeat packet start
			metadataPkt = (HDR_DOLBY_VISION_METADATA_PACKET*)((unsigned int)metadataPkt+(128 * (3- (mdPktCnt%3))));
			mdPktCnt += (2 - (mdPktCnt%3));
		}else if((mdPktCnt%3) != 2){ // check next packet if not the last repeat packet end
			metadataPkt = (HDR_DOLBY_VISION_METADATA_PACKET*)((unsigned int)metadataPkt+128);
		}else{ // CRC check fail when contiune 3 packet CRC error
			pr_debug("[ERR] CRC[%x] Err@Cnt[%d]\n", pktCrc32, mdPktCnt);
		#if 1
			if(dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_wid <= 1920){
				DI_freeze(true);
			}else{
				mdomain_capture_disable(true);
			}
		#endif
			
			//forcebg_wait_porch(SLR_MAIN_DISPLAY);
			break;
		}
	}while(++mdPktCnt < 300);
	

	return;
}



void HDR_DolbyVision_HDMI_Flow_controller(void)
{
	unsigned char bHdrDetRet=0;
	static unsigned char lastHdrDetRet=0;

	if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE) || ((rtd_inl(VGIP_VGIP_CHN1_CTRL_reg) & _BIT0) == 0)
		|| (i3ddmaCtrl.cap_buffer[0].phyaddr == NULL))
		return;

	// check Dolby Vision detect result
	bHdrDetRet = HDR_DolbyVision_HDMI_check_mode();

	// metadata packet process
	if(bHdrDetRet && (HDR_DolbyVision_Get_CurHdmiMode() != DOLBY_HDMI_OFF))
		HDR_DolbyVision_HDMI_md_packet_process();

	//if(bHdrDetRet)
	//	_TEST_HDMI_metadata_dump();

	// enable IDMA md capture when (1) HDR HDMI mode OFF && (2) HDR CRC detected && (3) IDMA enabled && (4) HDR display enabled
	if((HDR_DolbyVision_Get_CurHdmiMode() == DOLBY_HDMI_OFF) && bHdrDetRet
		&& (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) && HDR_DolbyVision_Get_CurHdrDispMode())
	{
		// check md_parser capture address (MUST < 512MB for VCPU constrain)
		if(rtd_inl(H3DDMA_Cap_R1_Start_reg) < 0x20000000){
			HDR_DolbyVision_Set_CurHdmiMode(DOLBY_HDMI_IDMA_INIT);
		}else{
			HDR_DolbyVision_Set_CurHdrDispMode(HDR_DISP_DISABLE);
			pr_emerg("\n*** [ERROR][DolbyVision] MD_PARSER BUFFER > 512MB[%x]\n\n", rtd_inl(H3DDMA_Cap_R1_Start_reg));
		}
	}// disable IDMA captire when (1) capture is enabled && ((A) !detect CRC || (B) !IDMA enabled || (C) !HDR display enabled)
	else if((HDR_DolbyVision_Get_CurHdmiMode() != DOLBY_HDMI_OFF) &&
		(!bHdrDetRet || !HDR_DolbyVision_Get_CurHdrDispMode()))
	{
		HDR_DolbyVision_Set_CurHdmiMode(DOLBY_HDMI_OFF);
	}

	if(lastHdrDetRet != bHdrDetRet){
		pr_debug("[DV] HDMI st=%d\n", bHdrDetRet);
		lastHdrDetRet = bHdrDetRet;
	}

	return;
}

int HDR_DOLBY_VISION_HDMI_Send_Write_Index_RPC(void)
{

	if(hdrDVShmAddr){
		//  enable timer6 interrupt (trigger timer ISR on SCPU
		rtd_outl(TIMER_TC6ICR_reg, TIMER_TC6ICR_tc6ie_mask);
		// enable timer6
		rtd_outl(TIMER_TC6CR_reg, TIMER_TC6CR_tc6en_mask);

		// send RPC to Linux kernel -- HDMI mode data end for B05 setting apply
		//VO_SendKernelRPC(RPC_VCPU_ID_0x112_HDR_FRAMEINFO, HDR_DOLBY_HDMI, hdrDVShmAddr->picQWr, NONBLOCK_MODE);
		//Warning("[ERR] NEED FIX RPC ERROR@%s\n", __FUNCTION__);
	}else{
		//Warning("[DV] NULL PTR@%s\n", __FUNCTION__);
	}

	return 0;
}

void HDR_DolbyVision_HDMI_handler(void)
{
	// [TEST] For HDMI detect enable test only
	//_TEST_HDMI_Detect_Enable();

	if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI){ // check HDMI Dolby Vision status in HDR HDMI mode
		HDR_DolbyVision_HDMI_Flow_controller();
	}

	return;
}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

static  short tScale_Down_Coef_2tap[] = {
    0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,
    31,  95, 159, 223, 287, 351, 415, 479,
    543, 607, 671, 735, 799, 863, 927, 991,
};

static  short tScale_Down_Coef_Blur[] = {
    2,   3,   5,   7,  10,  15,  20,  28,  38,  49,  64,  81, 101, 124, 150, 178,
    209, 242, 277, 314, 351, 389, 426, 462, 496, 529, 556, 582, 602, 618, 629, 635,
};

static  short tScale_Down_Coef_Mid[] = {
    -2,  0,   1,   2,   5,   9,  15,  22,  32,  45,  60,  77,  98, 122, 149, 179,
    211, 245, 281, 318, 356, 394, 431, 468, 502, 533, 561, 586, 606, 620, 630, 636,
};

static  short tScale_Down_Coef_Sharp[] = {
    -2,   0,   1,   3,   6,  10,  15,  22,  32,  43,  58,  75,  95, 119, 145, 174,
    206, 240, 276, 314, 353, 391, 430, 467, 503, 536, 565, 590, 612, 628, 639, 646,
};


static  short *tScaleDown_COEF_TAB[] =
{
    tScale_Down_Coef_Blur,     tScale_Down_Coef_Mid,     tScale_Down_Coef_Sharp,     tScale_Down_Coef_2tap
};


void drvif_hdr_idma_color_colorspacergb2yuvtransfer(void)
{
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS  i3ddma_rgb2yuv_ctrl_reg;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_RBUS hdmi_dither_ctrl1_reg;

	// video input is RGB 8bit, metadata input is YUV422 8bit mode (both are 8bit input/output)
	hdmi_dither_ctrl1_reg.regValue = 0;
	hdmi_dither_ctrl1_reg.dither_bit_sel = 0; // 0: 8bit, 1: 10bit
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, hdmi_dither_ctrl1_reg.regValue);

	// video input is RGB, metadata input is YUV422 mode (both are rgb/yuv bypass mode)
	i3ddma_rgb2yuv_ctrl_reg.regValue = 0;
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_ctrl_reg.regValue);

	return;
}



#define TMPMUL	(16)
/*============================================================================*/
/**
 * CScalerSetScaleDown
 * This function is used to set scaling-down registers, including main and sub display.
 *
 * @param <info> { display-info struecture }
 * @return { none }
 * @note
 * It can be linear or non-linear either, based on the non-linear flag condition:
 */
static void idma_hdr_ultrazoom_set_scale_down(HDR_SZIE* in_Size, HDR_SZIE* out_Size, unsigned char panorama)
{
    unsigned char SDRatio;
    unsigned char SDFilter=0;
    unsigned int tmp_data;
    short *coef_pt;
    unsigned char i;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS			       i3ddma_vsd_ctrl0_reg;
    h3ddma_hsd_i3ddma_hsd_ctrl0_RBUS				i3ddma_hsd_ctrl0_reg;
    h3ddma_hsd_i3ddma_hsd_scale_hor_factor_RBUS	i3ddma_hsd_scale_hor_factor_reg;
    h3ddma_hsd_i3ddma_vsd_scale_ver_factor_RBUS   	i3ddma_vsd_Scale_Ver_Factor_reg;
    h3ddma_hsd_i3ddma_hsd_hor_segment_RBUS		i3ddma_hsd_hor_segment_reg;
    h3ddma_hsd_i3ddma_hsd_hor_delta1_RBUS			i3ddma_hsd_hor_delta1_reg;
    h3ddma_hsd_i3ddma_hsd_initial_value_RBUS		i3ddma_hsd_initial_value_reg;
    h3ddma_hsd_i3ddma_vsd_initial_value_RBUS		i3ddma_vsd_initial_value_reg;

    i3ddma_vsd_ctrl0_reg.regValue		= rtd_inl(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
    i3ddma_hsd_ctrl0_reg.regValue		= rtd_inl(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg);
    i3ddma_hsd_scale_hor_factor_reg.regValue	= rtd_inl(H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg);
    i3ddma_vsd_Scale_Ver_Factor_reg.regValue = rtd_inl(H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg);
    i3ddma_hsd_hor_segment_reg.regValue = rtd_inl(H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg);
    i3ddma_hsd_hor_delta1_reg.regValue	= rtd_inl(H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg);
    i3ddma_hsd_initial_value_reg.regValue	= rtd_inl(H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg);
    i3ddma_vsd_initial_value_reg.regValue = rtd_inl(H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg);


    //o============ H scale-down=============o
    if (in_Size->nWidth > out_Size->nWidth) {
        // o-------calculate scaledown ratio to select one of different bandwith filters.--------o
        if ( out_Size->nWidth == 0 ) {
            pr_debug("[HDR.V] output width = 0 !!!\n");
            SDRatio = 0;
        } else {
            SDRatio = (in_Size->nWidth*TMPMUL) / out_Size->nWidth;
        }

        //ROSPrintf("[IVI.V] CSW SDRatio number=%d\n",SDRatio);

        if(SDRatio <= ((TMPMUL*3)/2))	//<1.5 sharp, wider bw
            SDFilter = 2;
        else if(SDRatio <= (TMPMUL*2) && SDRatio > ((TMPMUL*3)/2) )	// Mid
            SDFilter = 1;
        else		// blurest, narrow bw
            SDFilter = 0;

        //o---------------- fill coefficients into access port--------------------o
        coef_pt = tScaleDown_COEF_TAB[SDFilter];

        i3ddma_hsd_ctrl0_reg.h_y_table_sel = 0;	// TAB1
        i3ddma_hsd_ctrl0_reg.h_c_table_sel = 0;	// TAB1

        for (i=0; i<16; i++)
        {
            tmp_data = ((unsigned int)(*coef_pt++)<<16);
            tmp_data += (unsigned int)(*coef_pt++);
            rtd_outl(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg+ i*4, tmp_data);
        }
    }

	//o============ V scale-down=============o
	if (in_Size->nLength > out_Size->nLength) {
		// o-------calculate scaledown ratio to select one of different bandwith filters.--------o

		 //jeffrey 961231
		if ( out_Size->nLength == 0 ) {
			SDRatio = 0;
		} else {
			SDRatio = (in_Size->nLength*TMPMUL) / out_Size->nLength;
		}

		//ROSPrintf("[IVI.V] CSW SDRatio number=%d\n",SDRatio);

		if(SDRatio <= ((TMPMUL*3)/2))	//<1.5 sharp, wider bw
			SDFilter = 2;
		else if(SDRatio <= (TMPMUL*2) && SDRatio > ((TMPMUL*3)/2) )	// Mid
			SDFilter = 1;
		else		// blurest, narrow bw
			SDFilter = 0;

		//o---------------- fill coefficients into access port--------------------o
		coef_pt = tScaleDown_COEF_TAB[SDFilter];

		i3ddma_vsd_ctrl0_reg.v_y_table_sel = 1;	// TAB2
		i3ddma_vsd_ctrl0_reg.v_c_table_sel = 1;	// TAB2

		for (i=0; i<16; i++)
		{
			tmp_data = ((unsigned int)(*coef_pt++)<<16);
			tmp_data += (unsigned int)(*coef_pt++);
			rtd_outl(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg + i*4, tmp_data);
		}

	}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    unsigned int nFactor;
    unsigned char Hini, Vini;

	if (in_Size->nWidth > out_Size->nWidth) {    // H scale-down
		Hini = 0x80;//0xff;//0x78;
		i3ddma_hsd_initial_value_reg.hor_ini = Hini;
		{
			//frank@0108 add for code exception
			if ( out_Size->nWidth == 0 ) {
				pr_debug("[HDR.V] output width = 0 !!!\n");
				nFactor = 0;
			} else if(in_Size->nWidth>4095){
				//nFactor = (unsigned int)((((in_Size->nWidth-1)<<19) / (out_Size->nWidth-1))<<1);
				nFactor = (unsigned int)((((in_Size->nWidth)<<19) / (out_Size->nWidth))<<1);
			}
			else if(in_Size->nWidth>2047){
				//nFactor = (unsigned int)(((in_Size->nWidth-1)<<20) / (out_Size->nWidth-1));
				nFactor = (unsigned int)(((in_Size->nWidth)<<20) / (out_Size->nWidth));
			} else {
				//nFactor = (unsigned int)(((in_Size->nWidth-1)<<21) / (out_Size->nWidth-1));
				nFactor = (unsigned int)(((in_Size->nWidth)<<21) / (out_Size->nWidth));
				//nFactor = (unsigned int)(((in_Size->nWidth)<<21) / (out_Size->nWidth));//old
				nFactor = SHR(nFactor + 1, 1); //rounding
			}
		}
		//nFactor = SHR(nFactor + 1, 1); //rounding
		i3ddma_hsd_scale_hor_factor_reg.hor_fac = nFactor;
	}else {
		i3ddma_hsd_scale_hor_factor_reg.hor_fac = 0x100000;
	}
	i3ddma_hsd_hor_segment_reg.nl_seg2 = out_Size->nWidth;

	if (in_Size->nLength > out_Size->nLength) {    // V scale-down
//			ich2_uzd_Ctrl0_REG.buffer_mode = 0x02;
		Vini = 0x80;//0xff;//0x78;
		i3ddma_vsd_initial_value_reg.ver_ini = Vini;
		//nFactor = (unsigned int)((ptInSize->nLength << 20) - (Vini<<12)) / (ptOutSize->nLength - 1);
		//frank@0108 add for code exception
		if ( out_Size->nLength == 0 ) {
			pr_debug("[HDR.V] output length = 0 !!!\n");
			nFactor = 0;
		} else if(in_Size->nLength>4095){
				//nFactor = (unsigned int)((((in_Size->nLength-1)<<19) / (out_Size->nLength-1))<<1);
				nFactor = (unsigned int)((((in_Size->nLength)<<19) / (out_Size->nLength))<<1);
			}
			else if(in_Size->nLength>2047){
				//nFactor = (unsigned int)(((in_Size->nLength-1)<<20) / (out_Size->nLength-1));
				nFactor = (unsigned int)(((in_Size->nLength)<<20) / (out_Size->nLength));
			} else {
				//nFactor = (unsigned int)(((in_Size->nLength-1)<<21) / (out_Size->nLength-1));
				nFactor = (unsigned int)(((in_Size->nLength)<<21) / (out_Size->nLength));
				//nFactor = (unsigned int)(((in_Size->nLength)<<21) / (out_Size->nLength));//old
				nFactor = SHR(nFactor + 1, 1); //rounding
			}
		//nFactor = SHR(nFactor+1, 1); //rounding
		i3ddma_vsd_Scale_Ver_Factor_reg.ver_fac = nFactor;
	}else{
//			ich2_uzd_Ctrl0_REG.buffer_mode = 0;
		i3ddma_vsd_Scale_Ver_Factor_reg.ver_fac = 0x100000;
	}

//	ich2_uzd_Ctrl0_REG.output_fmt = 1;
//	CLR_422_Fr_SD();

	rtd_outl(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg, i3ddma_vsd_ctrl0_reg.regValue);
	rtd_outl(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg, i3ddma_hsd_ctrl0_reg.regValue);
	rtd_outl(H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg, i3ddma_hsd_scale_hor_factor_reg.regValue);
	rtd_outl(H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg, i3ddma_vsd_Scale_Ver_Factor_reg.regValue);
	rtd_outl(H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg, i3ddma_hsd_hor_segment_reg.regValue);
	rtd_outl(H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg, i3ddma_hsd_hor_delta1_reg.regValue);
	rtd_outl(H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg, i3ddma_vsd_initial_value_reg.regValue);
	rtd_outl(H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg, i3ddma_hsd_initial_value_reg.regValue);

	return;
}



void drvif_hdr_idma_ultrazoom_config_scaling_down(HDR_SZIE* in_Size, HDR_SZIE* out_Size, unsigned char panorama)
{
	// Scale down setup for Channel1
	h3ddma_hsd_i3ddma_hsd_ctrl0_RBUS i3ddma_hsd_ctrl0_reg;
	h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS i3ddma_vsd_ctrl0_reg;


	i3ddma_hsd_ctrl0_reg.regValue = rtd_inl(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg);
	i3ddma_hsd_ctrl0_reg.h_zoom_en = 0;
	rtd_outl(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg, i3ddma_hsd_ctrl0_reg.regValue);

	i3ddma_vsd_ctrl0_reg.regValue = rtd_inl(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
	i3ddma_vsd_ctrl0_reg.v_zoom_en = 0;
	i3ddma_vsd_ctrl0_reg.buffer_mode = 0;
	i3ddma_vsd_ctrl0_reg.out_bit = 0;
	i3ddma_vsd_ctrl0_reg.sort_fmt = 1; // 444
	i3ddma_vsd_ctrl0_reg.video_comp_en = 0;
	i3ddma_vsd_ctrl0_reg.truncationctrl = 0;
	rtd_outl(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg, i3ddma_vsd_ctrl0_reg.regValue);

	idma_hdr_ultrazoom_set_scale_down(in_Size, out_Size, panorama);

	return;
}



void  drvif_hdr_idma_capture_config(HDR_SZIE capSize)
{
#define CAP_LEN 32
#define CAP_REM 12

	pr_debug("[DV] HDR IDMA Cap Setting...\n");

	unsigned int num, rem;
	unsigned int len, lineunits;
	h3ddma_cap_ctl0_RBUS cap_ctl0_reg;
	h3ddma_cap_ctl1_RBUS cap_ctl1_reg;

	h3ddma_lr_separate_ctrl1_RBUS lr_separate_ctrl1_reg;
	 h3ddma_lr_separate_ctrl2_RBUS lr_separate_ctrl2_reg;
	h3ddma_tg_v1_end_RBUS tg_v1_end_reg;
	h3ddma_i3ddma_byte_channel_swap_RBUS i3ddma_byte_channel_swap_reg;
	h3ddma_i3ddma_enable_RBUS i3ddma_enable_reg;

	// IDMA LR separate control
	lr_separate_ctrl1_reg.regValue = rtd_inl(H3DDMA_LR_Separate_CTRL1_reg);
	lr_separate_ctrl1_reg.chess_board_format = 0;
	lr_separate_ctrl1_reg.hdmi_3d_sel = 0;
	lr_separate_ctrl1_reg.vs_inv = 0;
	lr_separate_ctrl1_reg.hs_inv = 0;
	lr_separate_ctrl1_reg.progressive = 1;
	lr_separate_ctrl1_reg.hdmi_3d_structure = 0xa; // frame 2D
	rtd_outl(H3DDMA_LR_Separate_CTRL1_reg, lr_separate_ctrl1_reg.regValue);

	lr_separate_ctrl2_reg.regValue = rtd_inl(H3DDMA_LR_Separate_CTRL2_reg);
	lr_separate_ctrl2_reg.hact = capSize.nWidth;
	lr_separate_ctrl2_reg.vact = capSize.nLength;
	rtd_outl(H3DDMA_LR_Separate_CTRL2_reg,lr_separate_ctrl2_reg.regValue);
	// IDMA capture FIFO setting
	//num = (capSize.nWidth - CAP_REM) / CAP_LEN;
	//rem = ((capSize.nWidth - CAP_REM) % CAP_LEN) + CAP_REM;

	// RGB444 8bit: 3byte/pixel
	lineunits = (capSize.nWidth * 8 * 3) /128;
	len = 32;
	num = (unsigned int)(lineunits / len);
	rem = (unsigned int)(lineunits % len);
	if(rem == 0)
	{
		rem = 32;
		num -= 1;
	}

	cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
	cap_ctl0_reg.triple_buf_en = 0;
	cap_ctl0_reg.quad_buf_en = 0;
	cap_ctl0_reg.freeze_en = 0;
	cap_ctl0_reg.bit_sel = 0; 			// 8bit (display output 10bit)
	cap_ctl0_reg.pixel_encoding = 0; 	// 0: 444, 1:422
	cap_ctl0_reg.cap_write_len = CAP_LEN;
	cap_ctl0_reg.cap_write_rem = rem;
	rtd_outl(H3DDMA_Cap_CTL0_reg, cap_ctl0_reg.regValue);

	cap_ctl1_reg.regValue = rtd_inl(H3DDMA_Cap_CTL1_reg);
	cap_ctl1_reg.cap_water_lv = CAP_LEN;
	cap_ctl1_reg.cap_write_num = num;
	rtd_outl(H3DDMA_Cap_CTL1_reg, cap_ctl1_reg.regValue);

	i3ddma_byte_channel_swap_reg.regValue = rtd_inl(H3DDMA_I3DDMA_byte_channel_swap_reg);
	i3ddma_byte_channel_swap_reg.dma_1byte_swap = 0;
	i3ddma_byte_channel_swap_reg.dma_2byte_swap = 1;
	i3ddma_byte_channel_swap_reg.dma_4byte_swap = 1;
	i3ddma_byte_channel_swap_reg.dma_8byte_swap = 1;
	rtd_outl(H3DDMA_I3DDMA_byte_channel_swap_reg, i3ddma_byte_channel_swap_reg.regValue);

	tg_v1_end_reg.regValue = rtd_inl(H3DDMA_TG_v1_end_reg);
	tg_v1_end_reg.pullup_en = 0;
	tg_v1_end_reg.tg_hend1 = 2;
	tg_v1_end_reg.tg_vend1 = 2;
	rtd_outl(H3DDMA_TG_v1_end_reg, tg_v1_end_reg.regValue );

	// IDMA timeing gen enable
	i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
	i3ddma_enable_reg.frc_en = 0;
	i3ddma_enable_reg.tg_en = 0;
	i3ddma_enable_reg.lr_separate_en = 1;
	i3ddma_enable_reg.cap_en = 1; // enable IDMA capture before VI capture enable
	rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_enable_reg.regValue );

	return;
}

#define BUS_TV_SB2_LATCNT_CR5SUBDISPLAY_VADDR      (0xb801c418)
void  drvif_hdr_idma_md_parser_config(void)
{
	h3ddma_cap_ctl2_RBUS cap_ctl2_reg;
	h3ddma_i3ddma_mdp_cr_RBUS i3ddma_mdp_cr_reg;
	h3ddma_cap2_byte_swap_RBUS cap2_byte_swap_reg;
	h3ddma_interrupt_enable_RBUS h3ddma_interrupt_enable_reg;

	// TVSB2 arbitration sub-capture switch to IDMA capture2 enable
    //disable cap2 share arb. client with sub-capture
	//rtd_maskl(BUS_TV_SB2_LATCNT_CR5SUBDISPLAY_VADDR, ~_BIT31, _BIT31);

	h3ddma_md_m1_start_RBUS md_m1_start_reg;
	h3ddma_md_m2_start_RBUS md_m2_start_reg;
	h3ddma_md_m3_start_RBUS md_m3_start_reg;
	h3ddma_md_m4_start_RBUS md_m4_start_reg;
	unsigned int mdCapM1, mdCapM2, mdCapM3, mdCapM4;

	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE){
		// use IDMA R-frame
		h3ddma_cap_r1_start_RBUS cap_r1_start_reg;
		h3ddma_cap_r2_start_RBUS cap_r2_start_reg;
		cap_r1_start_reg.regValue = rtd_inl(H3DDMA_Cap_R1_Start_reg);
		cap_r2_start_reg.regValue = rtd_inl(H3DDMA_Cap_R2_Start_reg);
		// IDMA md_parser capture size = 128 * 100 * 3= 0x9600

		mdCapM1 = cap_r1_start_reg.cap_r1_start + 0x0;
		mdCapM2 = cap_r1_start_reg.cap_r1_start + (0x10000>>3);
		mdCapM3 = cap_r1_start_reg.cap_r1_start + (0x20000>>3);
		mdCapM4 = cap_r1_start_reg.cap_r1_start + (0x30000>>3);
	}
	else{
		pr_debug("\n*** [DV][ERROR] IDMA NOT ENABLED YET!! ***\n\n");
		return;
	}

	md_m1_start_reg.md_m1_start = mdCapM1;
	md_m2_start_reg.md_m2_start = mdCapM2;
	md_m3_start_reg.md_m3_start = mdCapM3;
	md_m4_start_reg.md_m4_start = mdCapM4;

	rtd_outl(H3DDMA_md_m1_Start_reg, md_m1_start_reg.regValue);
	rtd_outl(H3DDMA_md_m2_Start_reg, md_m2_start_reg.regValue);
	rtd_outl(H3DDMA_md_m3_Start_reg, md_m3_start_reg.regValue);
	rtd_outl(H3DDMA_md_m4_Start_reg, md_m4_start_reg.regValue);

	pr_debug("[DV] MD_Cap[1]=%x\n", md_m1_start_reg.regValue);
	pr_debug("[DV] MD_Cap[2]=%x\n", md_m2_start_reg.regValue);
	pr_debug("[DV] MD_Cap[3]=%x\n", md_m3_start_reg.regValue);
	pr_debug("[DV] MD_Cap[4]=%x\n", md_m4_start_reg.regValue);

	cap2_byte_swap_reg.regValue = rtd_inl(H3DDMA_cap2_byte_swap_reg);
	cap2_byte_swap_reg.cap2_1byte_swap = 1;
	cap2_byte_swap_reg.cap2_2byte_swap = 1;
	cap2_byte_swap_reg.cap2_4byte_swap = 1;
	cap2_byte_swap_reg.cap2_8byte_swap = 1;
	rtd_outl(H3DDMA_cap2_byte_swap_reg, cap2_byte_swap_reg.regValue );

	i3ddma_mdp_cr_reg.regValue = rtd_inl(H3DDMA_I3DDMA_MDP_CR_reg);
	i3ddma_mdp_cr_reg.max_packet_num = 300;
	i3ddma_mdp_cr_reg.mode = 1;
	i3ddma_mdp_cr_reg.en = 1;
	rtd_outl(H3DDMA_I3DDMA_MDP_CR_reg, i3ddma_mdp_cr_reg.regValue);

	// Meta -data total byte = 100 (packet) x 3 (repeat) x 128 byte (8bits) = 2400 x 128 bits (IDMA/M-domain busH = 128bit)
	// total = (Num*Len)+ Remain
	// Total = 2400
	// Num = 74, Len = 32, Remain = 32 or
	// Num = 37, Len = 64, Remain = 32 or ...

	h3ddma_interrupt_enable_reg.regValue = rtd_inl(H3DDMA_Interrupt_Enable_reg);
	h3ddma_interrupt_enable_reg.cap2_last_wrt_ie = 1;
	rtd_outl(H3DDMA_Interrupt_Enable_reg, h3ddma_interrupt_enable_reg.regValue);

	cap_ctl2_reg.regValue = rtd_inl(H3DDMA_Cap_CTL2_reg);
	cap_ctl2_reg.cap2_write_len = 32;
	cap_ctl2_reg.cap2_write_rem= 32;
	cap_ctl2_reg.cap2_write_num = 74;
	cap_ctl2_reg.cap2_water_lv = 32;
	//disable cap2 share arb. client with sub-capture
	cap_ctl2_reg.cap2_dcu_sel = 0;//1;
	cap_ctl2_reg.md_parser_en = 1;
	rtd_outl(H3DDMA_Cap_CTL2_reg, cap_ctl2_reg.regValue);


	return;
}



void  drvif_hdr_idma_vgip_config(void)
{
	// copy from main VGIP
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS    dma_vgip_chn1_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS   dma_vgip_chn1_act_vsta_length_reg;
	dma_vgip_dma_vgip_delay_RBUS dma_vgip_chn1_delay_reg;
	dma_vgip_dma_vgip_cts_fifo_ctl_RBUS 			 	 dma_cts_fifo_ctl_reg;
	//int dispD_hstaOffset=0;

	dma_vgip_chn1_ctrl_reg.regValue = rtd_inl(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 0;
	rtd_outl(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	// [DOLBYCERT-40] HDR IDMA setting should setting by IDMA control flow
	dma_vgip_chn1_act_hsta_width_reg.regValue = rtd_inl(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_chn1_act_vsta_length_reg.regValue = rtd_inl(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);

	dma_vgip_chn1_act_hsta_width_reg.dma_ih_act_sta = 0;
	dma_vgip_chn1_act_vsta_length_reg.dma_iv_act_sta = 0;
	rtd_outl(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, dma_vgip_chn1_act_hsta_width_reg.regValue);
	rtd_outl(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_chn1_act_vsta_length_reg.regValue);

	// IHS/IVS delay
	dma_vgip_chn1_delay_reg.regValue = rtd_inl(DMA_VGIP_DMA_VGIP_DELAY_reg);
	dma_vgip_chn1_delay_reg.dma_ihs_dly = 0;
	dma_vgip_chn1_delay_reg.dma_ivs_dly = 0;
	rtd_outl(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_chn1_delay_reg.regValue);

	dma_cts_fifo_ctl_reg.regValue = rtd_inl(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg);
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_vgip = 1;
	dma_cts_fifo_ctl_reg.dma_force_ctsfifo_rstn_sdnr = 1;
	dma_cts_fifo_ctl_reg.dma_en_ctsfifo_vsrst_sdnr = 0;
	rtd_outl(DMA_VGIP_DMA_VGIP_CTS_FIFO_CTL_reg, dma_cts_fifo_ctl_reg.regValue);

	dma_vgip_chn1_ctrl_reg.regValue = rtd_inl(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_ctrl_reg.dma_ivrun = 1;
	dma_vgip_chn1_ctrl_reg.dma_in_sel = 0; // HDMI
	dma_vgip_chn1_ctrl_reg.dma_digital_mode = 1; // prevent lost pixels or lines
	dma_vgip_chn1_ctrl_reg.dma_vact_start_ie = 1;
	dma_vgip_chn1_ctrl_reg.dma_vact_end_ie = 1;
	dma_vgip_chn1_ctrl_reg.dma_in_clk_en = 1;
	rtd_outl(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_chn1_ctrl_reg.regValue);

	return;
}


void  drvif_hdr_subCap_md_parser_config(void)
{
	// Sub-VGIP config -- sync from IDMA VGIP

	// Sub MD-parser short path?
	//  - check HW register
	// or
	// Sub-Color converter (dither/dfilter/rgb2yuv) -- bypass
	// Sub-UZD/DI config -- bypass


	// Sub-Capture config -- for metadata only


}



void  drvif_hdr_idma_enable(unsigned char enable)
{

	// IDMA capture disable
	if(enable == FALSE){
		h3ddma_cap_ctl2_RBUS cap_ctl2_reg;
		//h3ddma_i3ddma_enable_RBUS i3ddma_enable_reg;
		h3ddma_interrupt_enable_RBUS h3ddma_interrupt_enable_reg;

		cap_ctl2_reg.regValue = rtd_inl(H3DDMA_Cap_CTL2_reg);
		cap_ctl2_reg.md_parser_en = 0;
		rtd_outl(H3DDMA_Cap_CTL2_reg, cap_ctl2_reg.regValue);

		h3ddma_interrupt_enable_reg.regValue = rtd_inl(H3DDMA_Interrupt_Enable_reg);
		h3ddma_interrupt_enable_reg.cap2_last_wrt_ie = 0;
		rtd_outl(H3DDMA_Interrupt_Enable_reg, h3ddma_interrupt_enable_reg.regValue);

		//msleep(90*50); // delay 50ms for data end
		// TVSB2 arbitration sub-capture switch to IDMA capture2 disable
		//disable cap2 share arb. client with sub-capture
		//rtd_maskl(BUS_TV_SB2_LATCNT_CR5SUBDISPLAY_VADDR, ~_BIT31, 0);

		
		//i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
		//i3ddma_enable_reg.cap_en = 0; // enable IDMA capture before VI capture enable
		//rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_enable_reg.regValue );
		
	} // IDMA capture enable
	else{
		//mark move to decide_hdr_mode of scaler 
		//HDR_IDMA_HANDLER hdrIdma_hdl;
		//vgip_vgip_chn1_act_hsta_width_RBUS vgip_chn1_act_hsta_width_reg;
		//vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_length_reg;

		//vgip_chn1_act_hsta_width_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
		//vgip_chn1_act_vsta_length_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);

		// [FIX-ME] MUST CHANGE TO HDMI CONFIG PICTURE WIDTH/HEIGHT TO AVOID WRONG IDMA SETTING
		//hdrIdma_hdl.inSize.nWidth = hdrIdma_hdl.capSize.nWidth = vgip_chn1_act_hsta_width_reg.ch1_ih_act_wid;
		//hdrIdma_hdl.inSize.nLength = hdrIdma_hdl.capSize.nLength = vgip_chn1_act_vsta_length_reg.ch1_iv_act_len;
		//pr_debug("[HDR.V] IDMA Setup...\n");
		//pr_debug("[HDR] In/Out[(%d,%d)->(%d,%d)] in drvif_hdr_idma_enable\n",
		//	hdrIdma_hdl.inSize.nWidth, hdrIdma_hdl.inSize.nLength, hdrIdma_hdl.capSize.nWidth, hdrIdma_hdl.capSize.nLength);

		//mark move to decide_hdr_mode of scaler  
		// config for video
		//drvif_hdr_idma_vgip_config();
		//drvif_hdr_idma_color_colorspacergb2yuvtransfer();
		//drvif_hdr_idma_ultrazoom_config_scaling_down(&hdrIdma_hdl.inSize, &hdrIdma_hdl.capSize, 0);

		//if(VODMA_3D_Check_Is_Idma3dMode() == FALSE) // ignore IDMA video capture setting when in I3DDMA mode
			//drvif_hdr_idma_capture_config(hdrIdma_hdl.capSize);

		// config & enable IDMA metadata capture
		drvif_hdr_idma_md_parser_config();
	}

	return;
}

#endif
#endif // #ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT

