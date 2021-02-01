/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
//#include <../../../../../linux-3.10.0/arch/mips/include/asm/mach-generic/spaces.h>
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
#include <linux/auth.h>

//#include <mach/video_driver.h>
#include <rtk_kdriver/RPCDriver.h>


#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <tvscalercontrol/i3ddma/i3ddma.h>
#include <rbus/dma_vgip_reg.h>
//#include <rbus/scaler/rbusI3DDMAReg.h>
#include <rbus/h3ddma_reg.h>
#include <rbus/vodma_reg.h>
//#include <H3DDMA_fw.h>
//#include <rbusI3DDMA_ScaleDownReg.h>
#include <rbus/h3ddma_rgb2yuv_dither_4xxto4xx_reg.h>
#include <rbus/h3ddma_hsd_reg.h>
//#include <H3DDMA_fw.h>

#include <rtk_kdriver/rpc/VideoRPC_System.h>
#include <rtk_kdriver/rpc/VideoRPC_System_data.h>
#include <tvscalercontrol/scaler/modeState.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/scaler_vscdev.h>
//#include <mach/RPCDriver.h>

I3DDMA_3DDMA_CTRL_T i3ddmaCtrl;
I3DDMA_3DDMA_CTRL_T metadataCtrl;

/*
 * This gives the physical RAM offset.
 */
#define UNCAC_BASE		_AC(0xa0000000, UL)

#define IDMA_CAP_FRAME_SIZE_SRC_2K2K_3D 	(1920 * 1080 * 4) 	// (2k2k * 1/2) 10bit 444 (4byte/pixel) -- for HDMI 1080p FP source
#define IDMA_CAP_FRAME_SIZE_SRC_2K1K_3D 	(1920 * 540 * 4) 	// (2k1k * 1/2) 10bit 444 (4byte/pixel) -- non-1080pFP 3D source

#define VODMA_IV2PV_DELAY_CAL_MARGIN 1
#define I3DDMA_DRAM_MARGIN 10
// dynamic allocate IDMA capture buffer memory from video FW
//#define I3DDMA_DYNAMIC_MEMORY_ALLOCATE_ENABLE

// allocate/release IDMA memory dynamic
#define ENABLE_I3DDMA_ALLOC_RELEASE_MEMORY_DYNAMIC

//extern int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue);
//int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue);
//[K3LG-282] because can't allocate mem issue
extern int VBM_ReturnMemChunk(unsigned long buffer_addr, unsigned long buffer_size);
extern int VBM_BorrowMemChunk(unsigned long *buffer_addr, unsigned long *buffer_size, UINT32 reqSize);

//#include <tvscalercontrol/scaler/modeState.h>
typedef struct  {

    char *name;
    int progressive;
    unsigned int h_act_len;
    unsigned int v_act_len;
    unsigned int lr_v_act_len;
    unsigned int v_active_space1;
    unsigned int v_active_space2;

}I3DDMA_ACTIVE_SPACE_TABLE_T;

I3DDMA_ACTIVE_SPACE_TABLE_T i3ddma_active_space_table[] = {
	{ "1080P FramePacking",  1, 1920,  1080*2 + 45, 1080, 45, 0 },
	{ "720P FramePacking",  1, 1280,  720*2 + 30, 720, 30, 0 },
	{ "480P FramePacking",  1, 720,  480*2 + 45, 480, 45, 0 },
	{ "576P FramePacking",  1, 720,  576*2 + 49, 576, 49, 0 },
	{ "1080I FramePacking",  0, 1920,  540*4 + 22 + 23*2, 540, 23, 22 },
	{ "576I FramePacking",  0, 1440,  288*4 + 32 + 21*2, 288, 21, 32 },
	{ "480I FramePacking",  0, 1440,  240*4 + 22 + 23*2, 240, 23, 22 },
	{ NULL,  1, 1920,  520, 40, 0 },
};


//#ifdef HDMI_HAVE_HDMI_3D_TG
#if 0
unsigned char g_ucFp1080i_status=FALSE, g_ucFp1080i_fix_vStart_status=FALSE;
void I3DDMA_Set_FP1080i_status(I3DDMA_TIMING_T *gen_timing)
{
	g_ucFp1080i_status = ((gen_timing->i3ddma_3dformat == I3DDMA_FRAME_PACKING) && (gen_timing->progressive == 0));
	return;
}

unsigned char I3DDMA_Get_FP1080i_status(void)
{
	return g_ucFp1080i_status;
}


// [FIX-ME] change v-sync start position for HDMI 1080iFP 3D to 2D mode (3->1)
void I3DDMA_Set_FP1080i_3Dcvt2D_fix_vStart_status(unsigned char mode)
{
	g_ucFp1080i_fix_vStart_status = mode;
}

unsigned char I3DDMA_Get_FP1080i_3Dcvt2D_fix_vStart_status(void)
{
	return g_ucFp1080i_fix_vStart_status;
}
#endif

VO_CHROMA_FMT VOColorMap[4] = {
	VO_CHROMA_RGB888,
	VO_CHROMA_YUV422,
	VO_CHROMA_YUV444,
	VO_CHROMA_YUV411,

};

#if 0
char I3DDMA_ResetVODMA4K2K(void)
{

	VIDEO_RPC_VOUT_CONFIG_HDMI_3D config;
	CLNT_STRUCT clnt;

	printk("%s\n", __FUNCTION__);
	clnt = prepareCLNT(BLOCK_MODE | USE_INTR_BUF | SEND_VIDEO_CPU, VIDEO_SYSTEM, VERSION);

	memset(&config, 0, sizeof(VIDEO_RPC_VOUT_CONFIG_HDMI_3D));
	config.width = 0;
	config.height = 0;
	config.videoPlane = VO_VIDEO_PLANE_V1;
	HRESULT* hr = VIDEO_RPC_VOUT_ToAgent_ConfigHDMI_3D_0(&config, &clnt);
	if (hr < 0) {
		printk("CONFIG HDMI 3D RPC fail\n");
		return FALSE;
	}
    free(hr);

	return TRUE;

}

#endif


unsigned char I3DDMA_Get3DAllocReleaseMemoryDynamic(void)
{
#ifdef ENABLE_I3DDMA_ALLOC_RELEASE_MEMORY_DYNAMIC
	return TRUE;
#endif
	return FALSE;
}

char I3DDMA_ForceVODMA2D(UINT8 enable, UINT8 LR) {
	VIDEO_RPC_VOUT_FORCE_HDMI_2D *config;
	unsigned long ret;
	unsigned int  vir_addr, vir_addr_noncache;
	unsigned int  phy_addr;

	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VOUT_FORCE_HDMI_2D), GFP_DCU1, (void*)&vir_addr_noncache);
	//phy_addr = (unsigned int)virt_to_phys((void*)vir_addr);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);

	config = (VIDEO_RPC_VOUT_FORCE_HDMI_2D *)vir_addr_noncache;
	config->force2d = enable;
	config->l_flag = LR;
	config->videoPlane = VO_VIDEO_PLANE_V1;
	config->videoPlane = htonl(config->videoPlane);
#ifdef CONFIG_RTK_KDRV_RPC
	if (send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_Force_HDMI_2D, phy_addr, 0, &ret))
		printk("RPC fail!!\n");
#endif
	dvr_free((void *)vir_addr);


	return TRUE;
}

void I3DDMA_SetupLRSeparator(I3DDMA_TIMING_T *tx_timing, I3DDMA_TIMING_T *gen_timing) {

	int genvs_startpos_pixels;
	int genvs_endpos_pixels;

	h3ddma_i3ddma_enable_RBUS 	i3ddma_i3ddma_enable_reg;
	h3ddma_lr_separate_ctrl1_RBUS   i3ddma_lr_separate_ctrl1_reg;
	h3ddma_lr_separate_ctrl2_RBUS   i3ddma_lr_separate_ctrl2_reg;
	h3ddma_lr_separate_insert_vs_start_RBUS i3ddma_lr_separate_insert_vs_start_reg;
	h3ddma_lr_separate_insert_vs_end_RBUS  i3ddma_lr_separate_insert_vs_end_reg;


	printk("!!!!!!!!!!!! %s\n", __FUNCTION__);

/*
	// update FP 1080i status
	I3DDMA_Set_FP1080i_status(gen_timing);
	I3DDMA_Set_FP1080i_3Dcvt2D_fix_vStart_status(FALSE);
*/

	i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
	i3ddma_i3ddma_enable_reg.lr_separate_en = 0;
	rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);


#if 0 // [To Be Confirmed] Input HS/VS Signal Polarity Invert setup move to Main VGIP
	//Fix me : benwang 20121128
	//rtd_maskl(GET_VGIP_CHNx_CTRL_VADDR(), ~(VGIP_CHN1_CTRL_ch1_vs_inv_mask | VGIP_CHN1_CTRL_ch1_hs_inv_mask ), 0); // Let HS negtive polarity to positive polarity
	rtd_maskl(VGIP_CHN1_CTRL_reg, ~(VGIP_CHN1_CTRL_ch1_vs_inv_mask | VGIP_CHN1_CTRL_ch1_hs_inv_mask ), 0); // Let HS negtive polarity to positive polarity

	switch(tx_timing->polarity) {

		case _SYNC_HP_VP:
			rtd_maskl(I3DDMA_LR_SEPARATE_CTRL1_VADDR, ~(I3DDMA_LR_SEPARATE_CTRL1_vs_inv_mask | I3DDMA_LR_SEPARATE_CTRL1_hs_inv_mask), 0);
			break;
		case _SYNC_HN_VP:
			rtd_maskl(I3DDMA_LR_SEPARATE_CTRL1_VADDR, ~(I3DDMA_LR_SEPARATE_CTRL1_vs_inv_mask | I3DDMA_LR_SEPARATE_CTRL1_hs_inv_mask),
								I3DDMA_LR_SEPARATE_CTRL1_vs_inv(0) | I3DDMA_LR_SEPARATE_CTRL1_hs_inv(1));
			break;
		case _SYNC_HP_VN:
			rtd_maskl(I3DDMA_LR_SEPARATE_CTRL1_VADDR, ~(I3DDMA_LR_SEPARATE_CTRL1_vs_inv_mask | I3DDMA_LR_SEPARATE_CTRL1_hs_inv_mask),
				I3DDMA_LR_SEPARATE_CTRL1_vs_inv(1) | I3DDMA_LR_SEPARATE_CTRL1_hs_inv(0));

			break;
		case _SYNC_HN_VN:
			rtd_maskl(I3DDMA_LR_SEPARATE_CTRL1_VADDR, ~(I3DDMA_LR_SEPARATE_CTRL1_vs_inv_mask | I3DDMA_LR_SEPARATE_CTRL1_hs_inv_mask),
				I3DDMA_LR_SEPARATE_CTRL1_vs_inv(1) | I3DDMA_LR_SEPARATE_CTRL1_hs_inv(1));
			break;
	}
#endif

	// Setup LR Separate for :Frame packing and TopBottom, Line alternative
	// [HDMI-DMA] HDMI DMA capture control for 4k2k 2D timing
	i3ddma_lr_separate_ctrl1_reg.regValue = rtd_inl(H3DDMA_LR_Separate_CTRL1_reg);
	if((tx_timing->i3ddma_3dformat == I3DDMA_2D_ONLY) && (gen_timing->i3ddma_3dformat == I3DDMA_2D_ONLY)){
		i3ddma_lr_separate_ctrl1_reg.hdmi_3d_structure = 0xa;
	}else if(tx_timing->i3ddma_3dformat == I3DDMA_VERTICAL_STRIPE){
		i3ddma_lr_separate_ctrl1_reg.hdmi_3d_structure = 0xf;
	}else if(tx_timing->i3ddma_3dformat == I3DDMA_CHECKER_BOARD){
		i3ddma_lr_separate_ctrl1_reg.hdmi_3d_structure = 0xf;
	}else if((tx_timing->i3ddma_3dformat == I3DDMA_SENSIO)|| (tx_timing->i3ddma_3dformat == I3DDMA_REALID)){
		i3ddma_lr_separate_ctrl1_reg.hdmi_3d_structure = I3DDMA_SIDE_BY_SIDE_HALF;
	}else if(tx_timing->i3ddma_3dformat == I3DDMA_FRAMESEQUENCE){
		i3ddma_lr_separate_ctrl1_reg.hdmi_3d_structure = I3DDMA_FRAME_PACKING;
	}
	else
		i3ddma_lr_separate_ctrl1_reg.hdmi_3d_structure = gen_timing->i3ddma_3dformat;


	if(gen_timing->i3ddma_3dformat == I3DDMA_FRAMESEQUENCE){	// Framesequence use progressive LR separator setting, use to 3D type set Framepacking
		i3ddma_lr_separate_ctrl1_reg.progressive = 1;

	}else{
		i3ddma_lr_separate_ctrl1_reg.progressive = gen_timing->progressive;
	}

	pr_debug("[IDMA] Fmt/Ctrl=%d/0x%x\n", tx_timing->i3ddma_3dformat, rtd_inl(H3DDMA_LR_Separate_CTRL1_reg));


	i3ddma_lr_separate_ctrl1_reg.fp_vact_space1 = gen_timing->v_active_space1;
	i3ddma_lr_separate_ctrl1_reg.fp_vact_space2 = gen_timing->v_active_space2;
	rtd_outl(H3DDMA_LR_Separate_CTRL1_reg, i3ddma_lr_separate_ctrl1_reg.regValue);

	i3ddma_lr_separate_ctrl2_reg.regValue = rtd_inl(H3DDMA_LR_Separate_CTRL2_reg);
	if ((gen_timing->i3ddma_3dformat == I3DDMA_SIDE_BY_SIDE_HALF) || (gen_timing->i3ddma_3dformat == I3DDMA_SENSIO)|| (gen_timing->i3ddma_3dformat == I3DDMA_REALID)) {
			i3ddma_lr_separate_ctrl2_reg.vact = gen_timing->v_act_len;
			i3ddma_lr_separate_ctrl2_reg.hact = gen_timing->h_act_len*2;
	} else if (gen_timing->i3ddma_3dformat == I3DDMA_TOP_AND_BOTTOM) {
			i3ddma_lr_separate_ctrl2_reg.vact = gen_timing->v_act_len*2;
			i3ddma_lr_separate_ctrl2_reg.hact = gen_timing->h_act_len;
	} else if(gen_timing->i3ddma_3dformat == I3DDMA_VERTICAL_STRIPE) {
			i3ddma_lr_separate_ctrl2_reg.vact = gen_timing->v_act_len;
			i3ddma_lr_separate_ctrl2_reg.hact = gen_timing->h_act_len*2;
	}else if(gen_timing->i3ddma_3dformat == I3DDMA_CHECKER_BOARD) {
			i3ddma_lr_separate_ctrl2_reg.vact = gen_timing->v_act_len;
			i3ddma_lr_separate_ctrl2_reg.hact = gen_timing->h_act_len*2;
	}
	else {
			i3ddma_lr_separate_ctrl2_reg.vact = gen_timing->v_act_len;
			i3ddma_lr_separate_ctrl2_reg.hact = gen_timing->h_act_len;
	}
	rtd_outl(H3DDMA_LR_Separate_CTRL2_reg, i3ddma_lr_separate_ctrl2_reg.regValue);

	if (gen_timing->i3ddma_3dformat == I3DDMA_FRAME_PACKING && gen_timing->progressive == 0) {
//          FIXME:
		genvs_startpos_pixels = (tx_timing->v_total * tx_timing->h_total + 1) / 2;
		genvs_startpos_pixels -= ((gen_timing->v_act_sta + gen_timing->v_active_space1 + gen_timing->v_act_len * 2) * gen_timing->h_total);
		genvs_endpos_pixels = genvs_startpos_pixels + tx_timing->h_total * 2;
/*
		// [FIX-ME]: 1080i60 FP 3Dto2D unknown 1 lines diff (3->1)
		if((i3ddmaCtrl.force_3dto2d_enable == TRUE) && (genvs_startpos_pixels > (2*tx_timing->h_total))){
			printk("[FP1080i] V.start=%d->%d\n", genvs_startpos_pixels/tx_timing->h_total, (genvs_startpos_pixels-(2*tx_timing->h_total))/tx_timing->h_total);
			genvs_startpos_pixels -= (2*tx_timing->h_total);
			I3DDMA_Set_FP1080i_3Dcvt2D_fix_vStart_status(TRUE);
		}
*/
		i3ddma_lr_separate_insert_vs_start_reg.regValue = rtd_inl(H3DDMA_LR_Separate_insert_vs_start_reg);
		i3ddma_lr_separate_insert_vs_start_reg.vstart = genvs_startpos_pixels/tx_timing->h_total;
		i3ddma_lr_separate_insert_vs_start_reg.hstart = genvs_startpos_pixels%tx_timing->h_total;
		rtd_outl(H3DDMA_LR_Separate_insert_vs_start_reg, i3ddma_lr_separate_insert_vs_start_reg.regValue);

		i3ddma_lr_separate_insert_vs_end_reg.regValue = rtd_inl(H3DDMA_LR_Separate_insert_vs_end_reg);
		i3ddma_lr_separate_insert_vs_end_reg.vend = genvs_endpos_pixels/tx_timing->h_total;
		i3ddma_lr_separate_insert_vs_end_reg.hend = genvs_endpos_pixels%tx_timing->h_total;
		rtd_outl(H3DDMA_LR_Separate_insert_vs_end_reg, i3ddma_lr_separate_insert_vs_end_reg.regValue);
	}
	//rtd_maskl(I3DDMA_LR_SEPARATE_CTRL1_VADDR, ~(I3DDMA_LR_SEPARATE_CTRL1_lr_separate_en_mask),
					//I3DDMA_LR_SEPARATE_CTRL1_lr_separate_en(1));

	i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
	i3ddma_i3ddma_enable_reg.lr_separate_en = 1;
	rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);

}

I3DDMA_ERR_T I3DDMA_MeasureActiveSpace(I3DDMA_TIMING_T *tx_timing, I3DDMA_TIMING_T *gen_timing) {

	int i = 0;
	int fields;

	//I3DDMA_printk("tx_timing->h_act_len = %d\n", tx_timing->h_act_len);
	//I3DDMA_printk("tx_timing->v_act_len = %d\n", tx_timing->v_act_len);


	while(i3ddma_active_space_table[i].name) {
			//I3DDMA_printk(" hdmi_active_space_table[%d].h_act_len = %d\n", i, i3ddma_active_space_table[i].h_act_len);
			//I3DDMA_printk(" hdmi_active_space_table[%d].v_act_len = %d\n", i, i3ddma_active_space_table[i].v_act_len);

		if (/*tx_timing->h_act_len == hdmi_active_space_table[i].h_act_len &&*/ tx_timing->v_act_len == i3ddma_active_space_table[i].v_act_len) {

			gen_timing->v_act_len = i3ddma_active_space_table[i].lr_v_act_len;
			tx_timing->v_active_space1 = i3ddma_active_space_table[i].v_active_space1;
			tx_timing->v_active_space2 = i3ddma_active_space_table[i].v_active_space2;
			gen_timing->v_active_space1 = i3ddma_active_space_table[i].v_active_space1;
			gen_timing->v_active_space2 = i3ddma_active_space_table[i].v_active_space2;
			gen_timing->progressive = i3ddma_active_space_table[i].progressive;
			fields = gen_timing->progressive ? 2 : 4;
		//	gen_timing->progressive = tx_timing->progressive;
			gen_timing->color = tx_timing->color;
			gen_timing->depth = tx_timing->depth;
			gen_timing->v_freq = (gen_timing->progressive? (drvif_scaler3d_decide_3d_SG_data_FRC()? tx_timing->v_freq * 2: 1200): tx_timing->v_freq * fields);
			gen_timing->v_total = tx_timing->v_total / fields;
			gen_timing->h_freq = tx_timing->h_freq;
			gen_timing->h_act_len = tx_timing->h_act_len;
			gen_timing->h_total = tx_timing->h_total;
			gen_timing->h_act_sta = tx_timing->h_act_sta;
			gen_timing->v_act_sta = tx_timing->v_act_sta;	 // no used
			pr_debug("%s \n", i3ddma_active_space_table[i].name);
			return I3DDMA_ERR_NO;
		}
		i++;
	}

	gen_timing->progressive = 1;
	fields = gen_timing->progressive ? 2 : 4;
//	gen_timing->progressive = tx_timing->progressive;
	gen_timing->color = tx_timing->color;
	gen_timing->depth = tx_timing->depth;

	gen_timing->v_freq = (gen_timing->progressive? 1200: tx_timing->v_freq * fields);
	gen_timing->v_total = tx_timing->v_total / fields;
	gen_timing->h_freq = tx_timing->h_freq;
	gen_timing->h_act_len = tx_timing->h_act_len;
	gen_timing->h_total = tx_timing->h_total;
	gen_timing->h_act_sta = tx_timing->h_act_sta;
	gen_timing->v_act_sta = tx_timing->v_act_sta;	 // no used
	gen_timing->v_act_len = (tx_timing->v_act_len - tx_timing->v_act_sta) / 2;
	gen_timing->v_active_space1 = tx_timing->v_act_sta;
	gen_timing->v_active_space2 = 0;
	tx_timing->v_active_space1 = tx_timing->v_act_sta;
	tx_timing->v_active_space2 = 0;

	pr_debug("Unknow frame packing fomat and force to 2D\n");

	return I3DDMA_EER_MEASURE_ACTIVESPACE_FAIL;

}


void I3DDMA_Setup3Dtg(I3DDMA_TIMING_T *timing,  char frame_rate_x2) {
#if 0
	int fields, i;
	int genvs_start_pixels, genvs_end_pixels;
	int genvs_width, genvs_period;

	printk("!!!!!!!!!!!! %s\n", __FUNCTION__);

	frame_rate_x2 = 1;

	if (frame_rate_x2){
		fields = 8;
		genvs_width = 3;
		genvs_period = timing->v_total / 2;
	}else if(I3DDMA_Get_FP1080i_status() && i3ddmaCtrl.force_3dto2d_enable){
		fields = 2;
		genvs_width = 3;
		printk("[ I3DDMA] FP1080i 3Dto2D mode\n");
	} else {
//		fields = 4;
		fields = 2;
		genvs_width = 3;
		genvs_period = timing->v_total / 2;
	}

	printk("[HDMI-3DTG] FR*2=%d, field/period[%d/%d]\n", frame_rate_x2, fields, genvs_period);

	if(I3DDMA_Get_FP1080i_3Dcvt2D_fix_vStart_status()){
		// Ignore 3DTG v-sync insertion in HDMI 1080i FP video 3D to 2D mode (set vStart/vEnd=0xfff)
		genvs_start_pixels = (timing->h_total << 12)-timing->h_total;
		genvs_end_pixels = genvs_start_pixels;
	}
	// [HDMI-DMA] HDMI DMA capture timing for 4k2k 2D video
	else if(timing->i3ddma_3dformat == I3DDMA_2D_ONLY){
		// Ignore 3DTG v-sync insertion in 4k2k 2D mode (set vStart/vEnd=0xfff)
		genvs_start_pixels = 0; //(timing->h_total << 12)-timing->h_total;
		genvs_end_pixels = 0; //genvs_start_pixels;
		genvs_period = 0;
	}
	else{
		printk("[DBG] FP1080i/3Dto2D=%d/%d\n", I3DDMA_Get_FP1080i_status(), hdmi.force_3dto2d_enable);
		genvs_start_pixels = (timing->v_total * timing->h_total  + (fields/2))/fields;
		genvs_end_pixels = genvs_start_pixels + 3 * timing->h_total;
	}

	printk("[ I3DDMA-3DTG] start pixel/end pixel [%d /%d], vtotal/htotal [%d/%d]\n", genvs_start_pixels, genvs_end_pixels, timing->v_total, timing->h_total);


	// Timing Gen setting
	rtd_maskl(I3DDMA_TG_V1_END_reg, ~(I3DDMA_TG_V1_END_tg_vend1_mask | I3DDMA_TG_V1_END_tg_hend1_mask),
					I3DDMA_TG_V1_END_tg_vend1(3) | I3DDMA_TG_V1_END_tg_hend1(0));

	// FP 1080i 3Dto2D: field == 2
	if((fields == 2) && I3DDMA_Get_FP1080i_status() && i3ddmaCtrl.force_3dto2d_enable){
		rtd_maskl(I3DDMA_TG_V2_START_reg, ~(I3DDMA_TG_V2_START_tg_vstart2_mask | I3DDMA_TG_V2_START_tg_hstart2_mask) ,
						(I3DDMA_TG_V2_START_tg_vstart2(genvs_period) | I3DDMA_TG_V2_START_tg_hstart2(genvs_start_pixels%timing->h_total)));
		rtd_maskl(I3DDMA_TG_V2_END_reg, ~(I3DDMA_TG_V2_END_tg_vend2_mask | I3DDMA_TG_V2_END_tg_hend2_mask) ,
					(I3DDMA_TG_V2_END_tg_vend2(genvs_end_pixels/timing->h_total) | I3DDMA_TG_V2_END_tg_hend2(genvs_end_pixels%timing->h_total)));
	}
	else if(fields == 2){
		rtd_maskl(I3DDMA_TG_V2_START_reg, ~(I3DDMA_TG_V2_START_tg_vstart2_mask | I3DDMA_TG_V2_START_tg_hstart2_mask) ,
						(I3DDMA_TG_V2_START_tg_vstart2(genvs_period) | I3DDMA_TG_V2_START_tg_hstart2(genvs_start_pixels%timing->h_total)));
		rtd_maskl(I3DDMA_TG_V2_END_reg, ~(I3DDMA_TG_V2_END_tg_vend2_mask | I3DDMA_TG_V2_END_tg_hend2_mask) ,
					(I3DDMA_TG_V2_END_tg_vend2(genvs_end_pixels/timing->h_total) | I3DDMA_TG_V2_END_tg_hend2(genvs_end_pixels%timing->h_total)));
	}
	else{
		for (i=0; i<(fields/2-1); i++) {
	//		rtd_maskl(I3DDMA_TG_V2_START_reg + 8 * i, ~(I3DDMA_TG_V2_START_tg_vstart2_mask | I3DDMA_TG_V2_START_tg_hstart2_mask) ,
	//						(I3DDMA_TG_V2_START_tg_vstart2(genvs_start / timing->h_total) | I3DDMA_TG_V2_START_tg_hstart2(genvs_start % timing->h_total)));
	//		rtd_maskl(I3DDMA_TG_V2_END_reg+ 8 * i, ~(I3DDMA_TG_V2_END_tg_vend2_mask | I3DDMA_TG_V2_END_tg_hend2_mask) ,
	//					(I3DDMA_TG_V2_END_tg_vend2(genvs_end / timing->h_total) | I3DDMA_TG_V2_END_tg_hend2(genvs_end % timing->h_total)));
	//#ifdef ENABLE_HDMI_3DDMA_TEST
	#if 0
			rtd_maskl(I3DDMA_TG_V2_START_reg + 8 * i, ~(I3DDMA_TG_V2_START_tg_vstart2_mask | I3DDMA_TG_V2_START_tg_hstart2_mask) ,
							(I3DDMA_TG_V2_START_tg_vstart2(genvs_period) | I3DDMA_TG_V2_START_tg_hstart2(genvs_start_pixels%timing->h_total)));
			rtd_maskl(I3DDMA_TG_V2_END_reg+ 8 * i, ~(I3DDMA_TG_V2_END_tg_vend2_mask | I3DDMA_TG_V2_END_tg_hend2_mask) ,
						(I3DDMA_TG_V2_END_tg_vend2(genvs_period+genvs_width) | I3DDMA_TG_V2_END_tg_hend2(genvs_end_pixels%timing->h_total)));
	#else
			rtd_maskl(I3DDMA_TG_V2_START_reg + 8 * i, ~(I3DDMA_TG_V2_START_tg_vstart2_mask | I3DDMA_TG_V2_START_tg_hstart2_mask) ,
							(I3DDMA_TG_V2_START_tg_vstart2(genvs_start_pixels/timing->h_total) | I3DDMA_TG_V2_START_tg_hstart2(genvs_start_pixels%timing->h_total)));
			rtd_maskl(I3DDMA_TG_V2_END_reg+ 8 * i, ~(I3DDMA_TG_V2_END_tg_vend2_mask | I3DDMA_TG_V2_END_tg_hend2_mask) ,
						(I3DDMA_TG_V2_END_tg_vend2(genvs_end_pixels/timing->h_total) | I3DDMA_TG_V2_END_tg_hend2(genvs_end_pixels%timing->h_total)));
	#endif
		}
	}

	if((timing->i3ddma_3dformat != I3DDMA_2D_ONLY)){
		rtd_maskl(I3DDMA_LR_SEPARATE_CTRL1_VADDR, ~(I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_sel_mask),
		I3DDMA_LR_SEPARATE_CTRL1_hdmi_3d_sel(1));
	}

	// enable double frame rate
	//if(I3DDMA_Get_FP1080i_status() == TRUE){
		rtd_maskl(I3DDMA_TG_V1_END_reg, ~(I3DDMA_TG_V1_END_pulldown_en_mask),
						I3DDMA_TG_V1_END_pulldown_en(frame_rate_x2!=0));
	//}

	// timing gen enable
	rtd_maskl(I3DDMA_TG_V1_END_reg, ~(I3DDMA_TG_V1_END_tg_en_mask),
					I3DDMA_TG_V1_END_tg_en(1));

#else

	int fields, i;
	int genvs_start_pixels, genvs_end_pixels;
	int genvs_width, genvs_period;
	int start_pixels_tmp;

	h3ddma_tg_v1_end_RBUS i3ddma_tg_v1_end_reg;
	h3ddma_tg_v2_start_RBUS i3ddma_tg_v2_start_reg;
	h3ddma_tg_v2_end_RBUS i3ddma_tg_v2_end_reg;
	h3ddma_lr_separate_ctrl1_RBUS   i3ddma_lr_separate_ctrl1_reg;
	h3ddma_i3ddma_enable_RBUS 	i3ddma_i3ddma_enable_reg;

	pr_debug("!!!!!!!!!!!! 2 %s\n", __FUNCTION__);

	if(frame_rate_x2){
		fields = 8;
		genvs_width = 3;
		genvs_period = timing->v_total / 2;
	}else if((timing->progressive == 0) && (timing->i3ddma_3dformat != I3DDMA_2D_ONLY)
			&& (timing->i3ddma_3dformat != I3DDMA_FRAME_PACKING)){
		fields = 4;
		genvs_width = 3;
	} else{
		fields = 2;
		genvs_width = 3;
		genvs_period = timing->v_total / 2;
	}

	if(timing->i3ddma_3dformat == I3DDMA_2D_ONLY){
		genvs_start_pixels = 0; //(timing->h_total << 12)-timing->h_total;
		genvs_end_pixels = 0; //genvs_start_pixels;
		genvs_period = 0;
	}
	else{
		genvs_start_pixels = (timing->v_total * timing->h_total); //(timing->v_total * timing->h_total  + (fields/2))/fields;
		genvs_end_pixels = genvs_start_pixels + 3 * timing->h_total;
	}

	pr_debug("[ I3DDMA-3DTG] start pixel/end pixel [%d /%d], vtotal/htotal [%d/%d]\n", genvs_start_pixels, genvs_end_pixels, timing->v_total, timing->h_total);
	pr_debug("[ I3DDMA-3DTG] progressive / fields / 3d format  [%d/%d/%d]\n", timing->progressive, fields, timing->i3ddma_3dformat);


	// Timing Gen setting
	i3ddma_tg_v1_end_reg.regValue = rtd_inl(H3DDMA_TG_v1_end_reg);
	i3ddma_tg_v1_end_reg.tg_vend1 = 3;
	i3ddma_tg_v1_end_reg.tg_hend1 = 0;
	rtd_outl(H3DDMA_TG_v1_end_reg, i3ddma_tg_v1_end_reg.regValue);

	if(fields == 2){
		i3ddma_tg_v2_start_reg.regValue = rtd_inl(H3DDMA_TG_v2_start_reg);
		i3ddma_tg_v2_start_reg.tg_vstart2 = genvs_start_pixels/timing->h_total;
		i3ddma_tg_v2_start_reg.tg_hstart2 = genvs_start_pixels%timing->h_total;
		rtd_outl(H3DDMA_TG_v2_start_reg, i3ddma_tg_v2_start_reg.regValue);

		i3ddma_tg_v2_end_reg.regValue = rtd_inl(H3DDMA_TG_v2_end_reg);
		i3ddma_tg_v2_end_reg.tg_vend2 = genvs_end_pixels/timing->h_total;
		i3ddma_tg_v2_end_reg.tg_hend2 = genvs_end_pixels%timing->h_total;
		rtd_outl(H3DDMA_TG_v2_end_reg, i3ddma_tg_v2_end_reg.regValue);
	}
	else if(fields == 4){	//interlace mode

		start_pixels_tmp = genvs_start_pixels;

		for (i=0; i<(fields/2+1); i++) {

			genvs_start_pixels = (i+1) * start_pixels_tmp;
			genvs_end_pixels = genvs_start_pixels + 3 * timing->h_total;


			i3ddma_tg_v2_start_reg.regValue = rtd_inl(H3DDMA_TG_v2_start_reg + 8*i);
			i3ddma_tg_v2_start_reg.tg_vstart2 = genvs_start_pixels/timing->h_total;
			i3ddma_tg_v2_start_reg.tg_hstart2 = genvs_start_pixels%timing->h_total;
			rtd_outl(H3DDMA_TG_v2_start_reg + 8*i, i3ddma_tg_v2_start_reg.regValue);

			i3ddma_tg_v2_end_reg.regValue = rtd_inl(H3DDMA_TG_v2_end_reg + 8*i);
			i3ddma_tg_v2_end_reg.tg_vend2 = genvs_end_pixels/timing->h_total;
			i3ddma_tg_v2_end_reg.tg_hend2 = genvs_end_pixels%timing->h_total;
			rtd_outl(H3DDMA_TG_v2_end_reg + 8*i, i3ddma_tg_v2_end_reg.regValue);
		}
	}

	if((timing->i3ddma_3dformat != I3DDMA_2D_ONLY)){
		i3ddma_lr_separate_ctrl1_reg.regValue = rtd_inl(H3DDMA_LR_Separate_CTRL1_reg);
		i3ddma_lr_separate_ctrl1_reg.hdmi_3d_sel = 1;
		rtd_outl(H3DDMA_LR_Separate_CTRL1_reg, i3ddma_lr_separate_ctrl1_reg.regValue);

	}

	// enable double frame rate
	i3ddma_tg_v1_end_reg.regValue = rtd_inl(H3DDMA_TG_v1_end_reg);
	i3ddma_tg_v1_end_reg.pullup_en = frame_rate_x2!=0;
	rtd_outl(H3DDMA_TG_v1_end_reg, i3ddma_tg_v1_end_reg.regValue);

	// timing gen enable
//	rtd_maskl(I3DDMA_TG_V1_END_VADDR, ~(I3DDMA_TG_V1_END_tg_en_mask),	I3DDMA_TG_V1_END_tg_en(1));

	i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
	i3ddma_i3ddma_enable_reg.tg_en = 1;
	rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);


#endif

}

//#endif  //#endif HDMI_HAVE_HDMI_3D_TG

//#ifdef HDMI_HAVE_HDMI_DMA
unsigned int DEPTH2BITS[4] = {
	8,
	10,
	10,
	10,
};

unsigned int components[4] = {
	12,
	8,
	12,
	6,
};

unsigned char I3DDMA_check_idma_shareMemWithVideoFW(void)
{
#ifdef I3DDMA_DYNAMIC_MEMORY_ALLOCATE_ENABLE
	return TRUE;
#else
	return FALSE;
#endif
}


#ifdef I3DDMA_DYNAMIC_MEMORY_ALLOCATE_ENABLE
unsigned int I3DDMA_check_idma_memory_space(I3DDMA_TIMING_T *gen_timing)
{
	unsigned int	IDMA_rpcAllocStartAddr=0, IDMA_rpcAllocSize=0;
	unsigned int capFramesize, i;

	if(gen_timing){
		if((drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_SRC_TYPE) == _SRC_HDMI) /*&& (gen_timing->i3ddma_3dformat == I3DDMA_FRAME_PACKING)*/
			&& (gen_timing->h_act_len * gen_timing->v_act_len > (1920*540)))
		{
			capFramesize = IDMA_CAP_FRAME_SIZE_SRC_2K2K_3D;	// (1920x1080) 10bit 444 (4byte/pixel) -- for HDMI 1080p FP source
		}else{
			capFramesize = IDMA_CAP_FRAME_SIZE_SRC_2K1K_3D;	// (1920x540) 10bit 444 (4byte/pixel) -- non-1080pFP 3D source
		}
		pr_debug("[IDMA] alloc=%d * 4KB, 3D Fmt/Wid/Len=%d/%d/%d\n", capFramesize >> 10,
			gen_timing->i3ddma_3dformat, gen_timing->h_act_len, gen_timing->v_act_len);
	}else{
		pr_debug("\n**** [IDMA] ERR: %s ****\n\n", __FUNCTION__);
		Rt_Sleep(5000);
		return 1;
	}

	// [IDMA] IDMA capture buffer share memory with video decoder
	SCALERDRV_ALLOCBUFFER_INFO stAllocBufferInfo_idma;
	if(drvif_scaler_getValidMemInfo_fromVideo(&stAllocBufferInfo_idma) < 0){
		pr_debug("[IDMA] fail to get memory information\n");
		IDMA_rpcAllocStartAddr = 0;
		IDMA_rpcAllocSize = 0;
	}else{
		if(drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_SRC_TYPE) == _SRC_VO){
			IDMA_rpcAllocStartAddr = stAllocBufferInfo_idma.optimize_mem_addr;
			IDMA_rpcAllocSize = stAllocBufferInfo_idma.optimize_mem_size;
		}else{
			IDMA_rpcAllocStartAddr = stAllocBufferInfo_idma.normal_mem_addr;
			IDMA_rpcAllocSize = stAllocBufferInfo_idma.normal_mem_size;
		}
		pr_debug("[IDMA] Src[%d], RPC addr=%x, size req/alloc=%d/%d KB\n", drvif_I3DDMA_Get_Input_Info_Vaule(I3DDMA_INFO_INPUT_SRC_TYPE),
			IDMA_rpcAllocStartAddr, (capFramesize * 4)>> 10, IDMA_rpcAllocSize >> 10);
	}

	if(IDMA_rpcAllocStartAddr && (IDMA_rpcAllocSize >= (capFramesize * 4))){
		for (i=0; i<4; i++) {
			i3ddmaCtrl.cap_buffer[i].cache = (void*)(IDMA_rpcAllocStartAddr + i* capFramesize);
			i3ddmaCtrl.cap_buffer[i].phyaddr = (unsigned long)i3ddmaCtrl.cap_buffer[i].cache;// & ~0x80000000) | 0x40000000;
			i3ddmaCtrl.cap_buffer[i].size = capFramesize;
			pr_debug("[IDMA] cap_buf[%d]=%x(%d KB)\n", i, (UINT32)i3ddmaCtrl.cap_buffer[i].cache, i3ddmaCtrl.cap_buffer[i].size >> 10);
		}
	}else{
		pr_debug("\n*** [IDMA] ERR: capFramesize req/alloc=%d/%d (KB) ***\n\n", (capFramesize * 4) >> 10, IDMA_rpcAllocSize >> 10);
		Rt_Sleep(5000);
		return 1;
	}

	return 0;
}
#endif


unsigned char I3DDMA_3D_Init(void);
char I3DDMA_SetupCaptureInit(I3DDMA_CAPTURE_BUFFER_T *cap_buffer, I3DDMA_TIMING_T *timing, I3DDMA_3D_OPMODE_T mode) {

	int size, rem, len, num;
	unsigned int h_act_len;

	h3ddma_cap_ctl0_RBUS i3ddma_cap_ctl0_reg;
	h3ddma_cap_ctl1_RBUS i3ddma_cap_ctl1_reg;
	h3ddma_i3ddma_enable_RBUS i3ddma_i3ddma_enable_reg;

	pr_debug("!!!!!!!!!!!! %s\n", __FUNCTION__);

	//rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask),
	//			I3DDMA_CAP_CTL0_cap_en(0));
	i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
	i3ddma_i3ddma_enable_reg.cap_en = 0;
	rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);
#if 0
#ifdef I3DDMA_DYNAMIC_MEMORY_ALLOCATE_ENABLE
		int i, ret;

		// allocate IDMA capture buffer address dynamic
	ret = I3DDMA_check_idma_memory_space(timing);
		if(ret == 0){
			for(i=0; i<4; i++)
				cap_buffer[i].phyaddr = i3ddmaCtrl.cap_buffer[i].phyaddr;
		}else{
			pr_debug("*** [IDMA] ERR: MEMORY ALLOC FAIL!! ***\n\n");
			return I3DDMA_ERR_3D_NO_MEM;
		}
#else

	// [IDMA] allocate/release IDMA memory dynamic
	if(I3DDMA_Get3DAllocReleaseMemoryDynamic() == TRUE){
		int i, ret;
		// [DolbyVison] IDMA capture buffer allocate
		if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI || get_HDMI_HDR_mode() == HDR_HDR10_HDMI)
			ret = I3DDMA_DolbyVision_HDMI_Init();
		else
			ret = I3DDMA_3D_Init();

		if(ret == 0){
			for(i=0; i<4; i++)
				cap_buffer[i].phyaddr = i3ddmaCtrl.cap_buffer[i].phyaddr;
		}else{
			pr_debug("*** [IDMA] ERR: Dynamic MEMORY ALLOC FAIL!! ***\n\n");
			return I3DDMA_ERR_3D_NO_MEM;
		}
	}
#endif
#endif

	int i;
	for(i=0; i<4; i++)
		cap_buffer[i].phyaddr = i3ddmaCtrl.cap_buffer[i].phyaddr;

	switch (mode){

		case I3DDMA_3D_OPMODE_HW:
			size = cap_buffer[0].size / 4;
			rtd_outl(H3DDMA_Cap_L1_Start_reg, cap_buffer[0].phyaddr);
			rtd_outl(H3DDMA_Cap_R1_Start_reg, cap_buffer[1].phyaddr);
			rtd_outl(H3DDMA_Cap_L2_Start_reg, cap_buffer[2].phyaddr);
			rtd_outl(H3DDMA_Cap_R2_Start_reg, cap_buffer[3].phyaddr);
		break;
		case I3DDMA_3D_OPMODE_HW_2DONLY_L:
			size = cap_buffer[0].size / 2;
			rtd_outl(H3DDMA_Cap_L1_Start_reg, cap_buffer[0].phyaddr);
			rtd_outl(H3DDMA_Cap_L2_Start_reg, cap_buffer[1].phyaddr);
			rtd_outl(H3DDMA_Cap_R1_Start_reg, 0);
			rtd_outl(H3DDMA_Cap_R2_Start_reg, 0);

		break;
		case I3DDMA_3D_OPMODE_HW_2DONLY_R:
			size = cap_buffer[0].size / 2;
			rtd_outl(H3DDMA_Cap_R1_Start_reg, cap_buffer[0].phyaddr);
			rtd_outl(H3DDMA_Cap_R2_Start_reg, cap_buffer[1].phyaddr);
			rtd_outl(H3DDMA_Cap_L1_Start_reg, 0);
			rtd_outl(H3DDMA_Cap_L2_Start_reg, 0);
		break;

		case I3DDMA_3D_OPMODE_SW:

		default:

		break;
	}
	if(drvif_i3ddma_triplebuf_flag())
		rtd_outl(H3DDMA_Cap_L3_Start_reg, cap_buffer[4].phyaddr);

	// 128 bits = 16 bytes
	pr_debug("DEPTH2BITS[timing->depth] = %d\n", DEPTH2BITS[timing->depth]);
	pr_debug("components[timing->color] = %d\n", components[timing->color]);
	pr_debug("timing->h_act_len = %d\n", timing->h_act_len);

	h_act_len  = (DEPTH2BITS[timing->depth] * (timing->h_act_len /4) * components[timing->color] + 127) / 128;
	pr_debug("h_act_len = %d\n", h_act_len);
	rem = 12;
	len = 32;
	num = (h_act_len - rem) / len;
	rem = (h_act_len - rem) % len + rem;
	pr_debug("len = %d\n", len);
	pr_debug("rem = %d\n", rem);
	pr_debug("num = %d\n", num);

	i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
	i3ddma_cap_ctl0_reg.cap_write_len = len;
	i3ddma_cap_ctl0_reg.cap_write_rem = rem;
	rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

	i3ddma_cap_ctl1_reg.regValue = rtd_inl(H3DDMA_Cap_CTL1_reg);
	i3ddma_cap_ctl1_reg.cap_water_lv = len;
	i3ddma_cap_ctl1_reg.cap_write_num = num;
	rtd_outl(H3DDMA_Cap_CTL1_reg, i3ddma_cap_ctl1_reg.regValue);
//	rtd_outl(I3DDMA_CAP_BOUNDARYADDR1_VADDR, cap_buffer[0].phyaddr);
//	rtd_outl(I3DDMA_CAP_BOUNDARYADDR2_VADDR, cap_buffer[0].phyaddr + cap_buffer->size);


	rtd_outl(H3DDMA_Cap_Status_reg, 0x1F);

	return I3DDMA_ERR_NO;
}



void I3DDMA_Get3DGenTiming(I3DDMA_TIMING_T *tx_timing, I3DDMA_TIMING_T *gen_timing) {

//	int fields;
#if 0	//remove path policy
 #ifdef ENABLE_HDMI_DMA_FOR_4K2K // [HDMI-DMA] HDMI DMA capture enable control for 4k2k timing
	if((tx_timing->h_act_len == 3840) && (tx_timing->v_act_len == 2160) && (tx_timing->v_freq <= 310))
		Scaler_SetHdmiDmaCapture_Enable(TRUE);

	if(Scaler_GetHdmiDmaCapture_Enable())
 		i3ddmaCtrl.path_policy = I3DDMA_PATH_POLICY_3D_DMA;
	else
		i3ddmaCtrl.path_policy = I3DDMA_PATH_POLICY_3D_NODMA;
	printk("[DBG][HDMI] path_policy=%d\n", i3ddmaCtrl.path_policy);
//#elif ENABLE_HDMI_3DDMA_TEST
//	Scaler_SetI3DDMACapture_Enable(TRUE);
 #endif

	// determine output 3D format
	switch (i3ddmaCtrl.path_policy) {

		case I3DDMA_PATH_POLICY_2D_ONLY:
			gen_timing->i3ddma_3dformat = I3DDMA_2D_ONLY;
			i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_DISABLE;
		break;
		case I3DDMA_PATH_POLICY_3D_NODMA:
			i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_DISABLE;
			if (tx_timing->i3ddma_3dformat == I3DDMA_FRAME_PACKING)
				gen_timing->i3ddma_3dformat = I3DDMA_FRAME_PACKING;
			else
				gen_timing->i3ddma_3dformat = I3DDMA_2D_ONLY;
		break;
		case I3DDMA_PATH_POLICY_3D_DMA:
			if (i3ddmaCtrl.i3ddma_3d_capability == 0) gen_timing->i3ddma_3dformat = I3DDMA_2D_ONLY;
			else if (i3ddmaCtrl.force_all_3d_disable) gen_timing->i3ddma_3dformat = I3DDMA_2D_ONLY;
			else if (i3ddmaCtrl.force_2dto3d_enable && tx_timing->i3ddma_3dformat == I3DDMA_2D_ONLY) {
					gen_timing->i3ddma_3dformat = i3ddmaCtrl.force_2dto3d_mode;
					i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_HW;
			} else if (i3ddmaCtrl.force_3dto2d_enable && tx_timing->i3ddma_3dformat != I3DDMA_2D_ONLY) {
					if (i3ddmaCtrl.force_3dto2d_lr_sel) {
							i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_HW_2DONLY_L;
					} else {
							i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_HW_2DONLY_R;
					}
			} else {
				gen_timing->i3ddma_3dformat = tx_timing->i3ddma_3dformat;
				if (gen_timing->i3ddma_3dformat != I3DDMA_2D_ONLY) {
					i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_HW;
				} else {
					i3ddmaCtrl.hw_i3ddma_dma = I3DDMA_3D_OPMODE_DISABLE;
				}
			}
		break;
	}
#endif

	gen_timing->i3ddma_3dformat = tx_timing->i3ddma_3dformat;
	gen_timing->colorimetry = tx_timing->colorimetry;
	gen_timing->color = i3ddmaCtrl.targetColor; //tx_timing->color;
	gen_timing->depth = i3ddmaCtrl.targetDepth; //tx_timing->depth;
//	gen_timing->quincunx_en = 0;

	switch (gen_timing->i3ddma_3dformat) {
			case I3DDMA_2D_ONLY:
				if (tx_timing->i3ddma_3dformat != I3DDMA_2D_ONLY) {  // 3d convert to 2D , don't do DI
					gen_timing->progressive = 1;
				} else {
					gen_timing->progressive = tx_timing->progressive;
				}
				gen_timing->v_total = tx_timing->v_total;
				gen_timing->v_act_len = tx_timing->v_act_len;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->h_total = tx_timing->h_total;
				gen_timing->h_act_len = tx_timing->h_act_len;
				gen_timing->h_act_sta = tx_timing->h_act_sta;
				gen_timing->v_freq = tx_timing->v_freq;
				gen_timing->h_freq = tx_timing->h_freq;
			break;

			case I3DDMA_FRAMESEQUENCE:
				pr_debug("I3DDMA_FRAMESEQUENCE \n");
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->color = tx_timing->color;
				gen_timing->depth = tx_timing->depth;
				gen_timing->v_total = tx_timing->v_total;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;
				gen_timing->h_act_len = tx_timing->h_act_len;
				gen_timing->h_total = tx_timing->h_total;
				gen_timing->h_act_sta = tx_timing->h_act_sta;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->v_act_len = tx_timing->v_act_len;
				gen_timing->v_active_space1 = tx_timing->v_act_sta;
				gen_timing->v_active_space2 = 0;
				tx_timing->v_active_space1 = tx_timing->v_act_sta;
				tx_timing->v_active_space2 = 0;
			break;

			case I3DDMA_FRAME_PACKING:
				I3DDMA_MeasureActiveSpace(tx_timing, gen_timing);
			break;
			case I3DDMA_LINE_ALTERNATIVE:
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->v_total = tx_timing->v_total/2;
				gen_timing->v_act_len = tx_timing->v_act_len/2;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->h_total = tx_timing->h_total;
				gen_timing->h_act_len = tx_timing->h_act_len;
				gen_timing->h_act_sta = tx_timing->h_act_sta;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;
			break;

			case I3DDMA_SIDE_BY_SIDE_FULL:
				//I3DDMA_printk("I3DDMA_SIDE_BY_SIDE_FULL\n");
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->v_total = tx_timing->v_total/2;
				gen_timing->v_act_len = tx_timing->v_act_len;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->h_total = tx_timing->h_total/2;
				gen_timing->h_act_len = tx_timing->h_act_len/2;
				gen_timing->h_act_sta = tx_timing->h_act_sta/2;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;
			break;
			case I3DDMA_TOP_AND_BOTTOM:
				//I3DDMA_printk("I3DDMA_TOP_AND_BOTTOM\n");
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->v_total = tx_timing->v_total/2;
				gen_timing->v_act_len = tx_timing->v_act_len/2;
				gen_timing->v_act_sta = tx_timing->v_act_sta/2;
				gen_timing->h_total = tx_timing->h_total;
				gen_timing->h_act_len = tx_timing->h_act_len;
				gen_timing->h_act_sta = tx_timing->h_act_sta;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;
			break;

			case I3DDMA_REALID:
			case I3DDMA_SENSIO:
			case I3DDMA_SIDE_BY_SIDE_HALF:
				//I3DDMA_printk("%s\n", (gen_timing->i3ddma_3dformat == I3DDMA_SIDE_BY_SIDE_HALF? "I3DDMA_SIDE_BY_SIDE_HALF": "I3DDMA_SENSIO"));
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->v_total = tx_timing->v_total/2;
				gen_timing->v_act_len = tx_timing->v_act_len;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->h_total = tx_timing->h_total/2;
				gen_timing->h_act_len = tx_timing->h_act_len/2;
				gen_timing->h_act_sta = tx_timing->h_act_sta/2;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;

			break;
			case I3DDMA_FIELD_ALTERNATIVE:
				//I3DDMA_printk("I3DDMA_FIELD_ALTERNATIVE\n");
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->v_total = tx_timing->v_total/2;
				gen_timing->v_act_len = tx_timing->v_act_len;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->h_total = tx_timing->h_total;
				gen_timing->h_act_len = tx_timing->h_act_len;
				gen_timing->h_act_sta = tx_timing->h_act_sta;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;
			break;

			case I3DDMA_VERTICAL_STRIPE:
				//I3DDMA_printk("I3DDMA_VERTICAL_STRIPE\n");
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->v_total = tx_timing->v_total/2;
				gen_timing->v_act_len = tx_timing->v_act_len;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->h_total = tx_timing->h_total/2;
				gen_timing->h_act_len = tx_timing->h_act_len/2;
				gen_timing->h_act_sta = tx_timing->h_act_sta/2;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;
			break;

			case I3DDMA_CHECKER_BOARD:
				//I3DDMA_printk("I3DDMA_CHECKER_BOARD\n");
				gen_timing->progressive = tx_timing->progressive;
				gen_timing->v_total = tx_timing->v_total/2;
				gen_timing->v_act_len = tx_timing->v_act_len;
				gen_timing->v_act_sta = tx_timing->v_act_sta;
				gen_timing->h_total = tx_timing->h_total/2;
				gen_timing->h_act_len = tx_timing->h_act_len/2;
				gen_timing->h_act_sta = tx_timing->h_act_sta/2;
				//gen_timing->v_freq = tx_timing->v_freq*2;
				gen_timing->v_freq = 1200;
				gen_timing->h_freq = tx_timing->h_freq;
			break;

			default:
			break;
	}

	// [IDMA] interlaced video data FRC in M-domain, IDMA VO go auto mode
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if((drvif_scaler3d_decide_3d_SG_data_FRC() == TRUE) || drvif_scaler3d_decide_3d_PR_enable_IDMA())
#else
	if(/*(tx_timing->progressive == 0) ||*/ (drvif_scaler3d_decide_3d_SG_data_FRC() == TRUE) || drvif_scaler3d_decide_3d_PR_enable_IDMA())
#endif
	{
		if((gen_timing->i3ddma_3dformat != I3DDMA_FRAME_PACKING) && (get_HDMI_HDR_mode() == HDR_MODE_DISABLE))//dolby and hdr have no 3d till now
			gen_timing->v_freq = tx_timing->v_freq*2;

		pr_debug("[IDMA] 3DFmt[%d]@%c%d Hz\n", gen_timing->i3ddma_3dformat, (tx_timing->progressive? 'p': 'i'), gen_timing->v_freq);
	}

	pr_debug("[3DDMA] frame_rate_x2 %x, h_freq : %x \n", i3ddmaCtrl.frame_rate_x2, gen_timing->h_freq);

	if(i3ddmaCtrl.frame_rate_x2 == 1){
		gen_timing->v_freq = gen_timing->v_freq*2;
	}

	if(drvif_i3ddma_triplebuf_flag()){
#ifdef CONFIG_ALL_SOURCE_DATA_FS
	if(Get_PANEL_VFLIP_ENABLE() && (tx_timing->v_freq >495&& tx_timing->v_freq < 505)) {
		gen_timing->v_freq = tx_timing->v_freq;
	} else if(Get_PANEL_VFLIP_ENABLE() && (tx_timing->v_freq > 310 && tx_timing->v_freq < 590)) {
		gen_timing->v_freq = 500;
	}
        // [MAC5P-2291] force VO output frame rate >= 48hz
        else if(tx_timing->v_freq <= 310){
            // 24->48Hz, 25/30->50/60Hz
            gen_timing->v_freq = (tx_timing->v_freq > 235? tx_timing->v_freq * 2: 600);
            pr_debug("[IDMA][Force Data FS] Frame rate = %d->%d\n", tx_timing->v_freq, gen_timing->v_freq);
        }else
#endif
		gen_timing->v_freq = 600;
       }

	pr_debug("[3DDMA] hw_i3ddma_dma : %x \n", i3ddmaCtrl.hw_i3ddma_dma);
	pr_debug("[3DDMA] i3ddma_3dformat : %x \n", gen_timing->i3ddma_3dformat);
	pr_debug("[3DDMA] progressive : %x \n", gen_timing->progressive);
	pr_debug("[3DDMA] chroma : %x \n", gen_timing->color);
	pr_debug("[3DDMA] v_total : %x \n", gen_timing->v_total);
	pr_debug("[3DDMA] v_act_len : %x \n", gen_timing->v_act_len);
	pr_debug("[3DDMA] v_act_sta : %x \n", gen_timing->v_act_sta);
	pr_debug("[3DDMA] h_total : %x \n", gen_timing->h_total);
	pr_debug("[3DDMA] h_act_len : %x \n", gen_timing->h_act_len);
	pr_debug("[3DDMA] h_act_sta : %x \n", gen_timing->h_act_sta);
	pr_debug("[3DDMA] v_freq : %x \n", gen_timing->v_freq);
	pr_debug("[3DDMA] h_freq : %x \n", gen_timing->h_freq);

}


unsigned int encodemap[4] = {
	0,
	1,
	0,
	2,
};


char I3DDMA_Setup3DDMA(I3DDMA_3DDMA_CTRL_T* ctrl, I3DDMA_3D_OPMODE_T opmode) {

	//i3ddma_enable_RBUS 	i3ddma_i3ddma_enable_reg;
	h3ddma_i3ddma_enable_RBUS  i3ddma_i3ddma_enable_reg;
	//lr_separate_ctrl1_RBUS   i3ddma_lr_separate_ctrl1_reg;
	h3ddma_lr_separate_ctrl1_RBUS  i3ddma_lr_separate_ctrl1_reg;
	//cap_ctl0_RBUS i3ddma_cap_ctl0_reg;
	h3ddma_cap_ctl0_RBUS  i3ddma_cap_ctl0_reg;



	switch (opmode){

		case I3DDMA_3D_OPMODE_DISABLE:
			//I3DDMA_printk("I3DDMA_3D_OPMODE_DISABLE\n");

//			rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask), I3DDMA_CAP_CTL0_cap_en(0));

			i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
			i3ddma_lr_separate_ctrl1_reg.regValue = rtd_inl(H3DDMA_LR_Separate_CTRL1_reg);
			i3ddma_lr_separate_ctrl1_reg.hdmi_3d_sel = 0;
			i3ddma_i3ddma_enable_reg.cap_en = 0;
			rtd_outl(H3DDMA_LR_Separate_CTRL1_reg, i3ddma_lr_separate_ctrl1_reg.regValue);
			rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);
			i3ddmaCtrl.enable_3ddma = 0;

		break;
		case I3DDMA_3D_OPMODE_HW:
			//I3DDMA_printk("I3DDMA_3D_OPMODE_HW\n");
			//rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask), I3DDMA_CAP_CTL0_cap_en(0));

			i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
			i3ddma_i3ddma_enable_reg.cap_en = 0;
			rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);

			i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
			i3ddma_cap_ctl0_reg.bit_sel = ctrl->pgen_timing->depth != I3DDMA_COLOR_DEPTH_8B;
			i3ddma_cap_ctl0_reg.pixel_encoding = encodemap[ctrl->pgen_timing->color];
			rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

			I3DDMA_SetupLRSeparator(ctrl->ptx_timing, ctrl->pgen_timing);
			I3DDMA_Setup3Dtg(ctrl->pgen_timing, ctrl->frame_rate_x2);
			I3DDMA_SetupCaptureInit(ctrl->cap_buffer, ctrl->pgen_timing, opmode);

			i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
			i3ddma_cap_ctl0_reg.auto_block_sel_en = 1;
			i3ddma_cap_ctl0_reg.half_wr_sel = 0;
			i3ddma_cap_ctl0_reg.half_wr_en = 0;
			if(drvif_i3ddma_triplebuf_flag())
				i3ddma_cap_ctl0_reg.triple_buf_en = 1;
			else
				i3ddma_cap_ctl0_reg.triple_buf_en = 0;
			rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);
			//rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask),
				//I3DDMA_CAP_CTL0_cap_en(1));

			i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
			i3ddma_i3ddma_enable_reg.cap_en = 1;
			rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);

			I3DDMA_SetupVODMA(ctrl->pgen_timing);
#ifdef ENABLE_HDMI_DMA_FOR_4K2K // [HDMI-DMA] HDMI/VO DMA enabled
			if(Scaler_GetHdmiDmaCapture_Status() != HDMI_DMA_4K2K_STATE_CHANGE_SRC)
				Scaler_SetHdmiDmaCapture_Status(HDMI_DMA_4K2K_STATE_DMA_ENABLE);
#endif
			i3ddmaCtrl.enable_3ddma = 1;
		break;

		case I3DDMA_3D_OPMODE_HW_2DONLY_L:
			//I3DDMA_printk("I3DDMA_3D_OPMODE_HW_2DONLY_L\n");
			//rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask), I3DDMA_CAP_CTL0_cap_en(0));
			i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
			i3ddma_i3ddma_enable_reg.cap_en = 0;
			rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);

			i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
			i3ddma_cap_ctl0_reg.bit_sel = ctrl->pgen_timing->depth != I3DDMA_COLOR_DEPTH_8B;
			i3ddma_cap_ctl0_reg.pixel_encoding = encodemap[ctrl->pgen_timing->color];
			rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

			I3DDMA_SetupLRSeparator(ctrl->ptx_timing, ctrl->pgen_timing);
			I3DDMA_Setup3Dtg(ctrl->pgen_timing, ctrl->frame_rate_x2);
			I3DDMA_SetupCaptureInit(ctrl->cap_buffer, ctrl->pgen_timing, opmode);

			i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
			i3ddma_cap_ctl0_reg.auto_block_sel_en = 1;
			i3ddma_cap_ctl0_reg.half_wr_sel = 0;
			i3ddma_cap_ctl0_reg.half_wr_en = 1;
			rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

			//rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask),I3DDMA_CAP_CTL0_cap_en(1));
			i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
			i3ddma_i3ddma_enable_reg.cap_en = 1;
			rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);
			I3DDMA_SetupVODMA(ctrl->pgen_timing);
			i3ddmaCtrl.enable_3ddma = 1;

		break;
		case I3DDMA_3D_OPMODE_HW_2DONLY_R:
			//I3DDMA_printk("I3DDMA_3D_OPMODE_HW_2DONLY_R\n");
			//rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask), I3DDMA_CAP_CTL0_cap_en(0));
			i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
			i3ddma_i3ddma_enable_reg.cap_en = 0;
			rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);

			i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
			i3ddma_cap_ctl0_reg.bit_sel = ctrl->pgen_timing->depth != I3DDMA_COLOR_DEPTH_8B;
			i3ddma_cap_ctl0_reg.pixel_encoding = encodemap[ctrl->pgen_timing->color];
			rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

			I3DDMA_SetupLRSeparator(ctrl->ptx_timing, ctrl->pgen_timing);
			I3DDMA_Setup3Dtg(ctrl->pgen_timing, ctrl->frame_rate_x2);
			I3DDMA_SetupCaptureInit(ctrl->cap_buffer, ctrl->pgen_timing, opmode);

			i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
			i3ddma_cap_ctl0_reg.auto_block_sel_en = 1;
			i3ddma_cap_ctl0_reg.half_wr_sel = 1;
			i3ddma_cap_ctl0_reg.half_wr_en = 1;
			rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

			//rtd_maskl(I3DDMA_CAP_CTL0_VADDR, ~(I3DDMA_CAP_CTL0_cap_en_mask),I3DDMA_CAP_CTL0_cap_en(1));
			i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
			i3ddma_i3ddma_enable_reg.cap_en = 1;
			rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);
			I3DDMA_SetupVODMA(ctrl->pgen_timing);
			i3ddmaCtrl.enable_3ddma = 1;


		break;
		case I3DDMA_3D_OPMODE_HW_NODMA:
			//I3DDMA_printk("I3DDMA_3D_OPMODE_HW_NODMA\n");
			I3DDMA_SetupLRSeparator(ctrl->ptx_timing, ctrl->pgen_timing);
			I3DDMA_Setup3Dtg(ctrl->pgen_timing, ctrl->frame_rate_x2);
			pr_debug("%s %d\n", __FUNCTION__, __LINE__);
			i3ddmaCtrl.enable_3ddma = 0;
		break;
		case I3DDMA_3D_OPMODE_SW:
		default:
			return I3DDMA_ERR_3D_WRONG_OPMODE;
		break;

	}


	return I3DDMA_ERR_NO;

}

#ifdef CONFIG_FORCE_RUN_I3DDMA //dump i3ddma buf for debug
#define I3DDMA_FILE_PATH "/tmp/nfs/i3ddma_dump.raw"
#include <linux/fs.h>
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

int i3ddma_dump_data_to_file(unsigned int bufferindex)
{
	struct file* filp = NULL;
	if (i3ddmaCtrl.cap_buffer[bufferindex].cache != NULL) {
		pr_emerg( "\n\n\n\n *****************  i3ddma_dump_data_to_file start  ******%x***************\n\n\n\n",i3ddmaCtrl.cap_buffer[bufferindex].cache);
		struct file* filp = file_open(I3DDMA_FILE_PATH, O_RDWR | O_CREAT, 0);
		if (filp == NULL) {
			pr_emerg("file open fail\n");
			return FALSE;
		}
		unsigned long outfileOffset = 0;
		//file_write(filp, outfileOffset, (unsigned char*)i3ddmaCtrl.cap_buffer[bufferindex].cache, 1920*1080*3);
		file_write(filp, outfileOffset, (unsigned char*)i3ddmaCtrl.cap_buffer[bufferindex].uncache, i3ddmaCtrl.cap_buffer[bufferindex].size);
		file_sync(filp);
		file_close(filp);
		pr_emerg( "\n\n\n\n *****************  i3ddma_dump_data_to_file end  *********************\n\n\n\n");
		return TRUE;
	} else {
		pr_emerg( "\n\n\n\n *****************  i3ddma_dump_data_to_file NG for null buffer address  *********************\n\n\n\n");
		return FALSE;
	}
}
#endif

unsigned long I3DDMA_GetMemChunkAddr(unsigned int size)
{
#define _OFFSET_BYTES    (30*1024*1024)//offset 30M Bytes//32*1024*1024
    unsigned long ulPhyaddr = NULL;

    if(i3ddmaCtrl.cap_buffer[0].phyaddr)
	{

		if (size >  i3ddmaCtrl.cap_buffer[0].getsize - _OFFSET_BYTES)
		{
			pr_emerg("I3DDMA_GetMemChunkAddr get size(%d) fai\n",size);
		 	return 0;
		}


	    ulPhyaddr = i3ddmaCtrl.cap_buffer[0].phyaddr+_OFFSET_BYTES;
	}
	return ulPhyaddr;
}

extern unsigned char get_i3dma_uzd(void);
unsigned char I3DDMA_DolbyVision_HDMI_Init(void) {
#define _1M_SIZE               (1024 * 1024)
#define _4K_2K_10BIT_SIZE      (4096 * 2160 * 30/8)//(3840 * 2160 * 3)
#define _2K_1K_10BIT_SIZE      (1920 * 1080 * 30/8)

	unsigned int size_metadata = _1M_SIZE; // 1MB for metadata buffer
	unsigned int size_video = _2K_1K_10BIT_SIZE ;//4096*2160 RGB444 10bit sequence buffer //mac5p idma always run 2k
	int i;
	int allocSize = 0,getSize = 0;
	char bAlloc = false;
	unsigned int malloccacheaddr_metadata = NULL;
	unsigned int malloccacheaddr_video_phyaddr = NULL;//(unsigned int)dvr_malloc_uncached_specific(size_video*2, GFP_DCU2_FIRST, NULL);//(unsigned int)dvr_malloc(size_video*2);//for double buffer use
	int cur_act_w=0, cur_act_h=0;

#if 0//def CONFIG_FORCE_RUN_I3DDMA
		if(i3ddmaCtrl.i3ddma_3d_capability == 1)
		{
			pr_debug("I3DDMA_DolbyVision_HDMI_Init memory have alloc\n");
			return 0;
		}
#endif
#ifdef CONFIG_I2RND_ENABLE
	if(Scaler_I2rnd_get_enable() == _ENABLE){
		//dma uzd¨ì2K1K (MULTIVIEW CASE), set vmb size to 2k*1k from 4k*2k
		size_video = _2K_1K_10BIT_SIZE ;
	}
    else
#endif
    {
		cur_act_w = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);//Orignal source size
		if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE))
			cur_act_h = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)*2;//Orignal source size
		else
			cur_act_h = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE);//Orignal source size
		//printk(KERN_EMERG "[Minchay] cur_act_w:%d, cur_act_h:%d \n",cur_act_w,cur_act_h);
		if((cur_act_w <= 1920)&&(cur_act_h <= 1080))
		{//video under 2k*1k size, set vmb size to 2k*1k from 4k*2k
		    size_video = _2K_1K_10BIT_SIZE ;
		}else if(0==get_i3dma_uzd())
			size_video = _4K_2K_10BIT_SIZE;
	}

	pr_debug("%s.%d\n", __FUNCTION__, __LINE__);


	if(drvif_i3ddma_triplebuf_flag())
	{
		size_video = _2K_1K_10BIT_SIZE;
		allocSize = size_video*3;
	}
	else
	{
	    	allocSize = size_video*2;
	}

	/*
	rtd_outl(H3DDMA_Cap_L1_Start_reg, cap_buffer[0].phyaddr);
	rtd_outl(H3DDMA_Cap_L2_Start_reg, cap_buffer[2].phyaddr);
	rtd_outl(H3DDMA_Cap_R1_Start_reg, cap_buffer[1].phyaddr);
	rtd_outl(H3DDMA_Cap_R2_Start_reg, cap_buffer[3].phyaddr);
	*/
	//video capture buffer
	bAlloc = false;
	if(i3ddmaCtrl.cap_buffer[0].phyaddr == NULL)
	{
	   bAlloc = true;
	}
	else if((i3ddmaCtrl.cap_buffer[0].getsize < allocSize)){
	// capture mem < allocSize need realloc mem
	    pr_emerg("[DolbyVision][Minchay][%s] Error: vbm mem has alloced size(getSize:%d ) < allocSize(%d) \n", __FUNCTION__ , i3ddmaCtrl.cap_buffer[0].getsize, allocSize);
	    I3DDMA_DolbyVision_HDMI_DeInit();
	    bAlloc = true;
	}
	if(bAlloc)
    {
#ifdef CONFIG_SCALER_BRING_UP
			malloccacheaddr_video_phyaddr = (unsigned int)dvr_malloc_uncached_specific(allocSize, GFP_DCU1,(void **)&i3ddmaCtrl.cap_buffer[0].uncache);
			if(malloccacheaddr_video_phyaddr == (unsigned int)NULL)
			{
				pr_emerg("[DolbyVision] alloc idma sequence metadata memory failed[%x]\n", malloccacheaddr_video_phyaddr);
				return 1; //malloc memory fail
			}
			i3ddmaCtrl.cap_buffer[0].cache= malloccacheaddr_video_phyaddr;
			malloccacheaddr_video_phyaddr=(unsigned int)dvr_to_phys((void*)malloccacheaddr_video_phyaddr);
#else
	pr_debug("[DolbyVision][%s] call VBM_BorrowMemChunk\n",__FUNCTION__);
	// buffer[0][2] -- video capture buffer
	    if (VBM_BorrowMemChunk((unsigned long *)(&malloccacheaddr_video_phyaddr), (unsigned long *)(&getSize), allocSize) != 0) {
			pr_emerg("[DolbyVision] alloc idma video sequence memory failed[%x]\n",  malloccacheaddr_video_phyaddr);
			return 1; //malloc memory fail
		}
		if(getSize < _2K_1K_10BIT_SIZE)
		    pr_emerg("[DolbyVision][Minchay][%s] Error: vbm mem size(getSize:%d) is not 64M \n", __FUNCTION__ ,getSize);
#endif

		/*pr_debug*/
		pr_notice("[VBM] allocSize:%d, getSize:%d w:%d h:%d\n", allocSize, getSize, cur_act_w, cur_act_h);
		i3ddmaCtrl.cap_buffer[0].cache= NULL;//(void*)(malloccacheaddr_video);
		i3ddmaCtrl.cap_buffer[0].phyaddr =  (unsigned int)malloccacheaddr_video_phyaddr;//(unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[0].cache);
	    i3ddmaCtrl.cap_buffer[0].getsize = getSize;
    }
    if(i3ddmaCtrl.cap_buffer[0].phyaddr)
    {
		// buffer[0][2] -- video capture buffer
		//i3ddmaCtrl.cap_buffer[0].cache= NULL;//(void*)(malloccacheaddr_video);
		//i3ddmaCtrl.cap_buffer[0].phyaddr =  (unsigned int)malloccacheaddr_video_phyaddr;//(unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[0].cache);
		i3ddmaCtrl.cap_buffer[0].size = size_video;
		//i3ddmaCtrl.cap_buffer[0].getsize = getSize;
		pr_debug("[DolbyVision][Video] buf[0]=%x(%d KB), phy(%x) \n", (UINT32)i3ddmaCtrl.cap_buffer[0].cache, i3ddmaCtrl.cap_buffer[0].size >> 10, (UINT32)i3ddmaCtrl.cap_buffer[0].phyaddr);

		i3ddmaCtrl.cap_buffer[2].cache= NULL;//(void*)(malloccacheaddr_video + size_video);
		i3ddmaCtrl.cap_buffer[2].phyaddr = (unsigned int)i3ddmaCtrl.cap_buffer[0].phyaddr + size_video; //(unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[2].cache);
		i3ddmaCtrl.cap_buffer[2].size = size_video;
		//i3ddmaCtrl.cap_buffer[2].getsize = getSize;
		pr_debug("[DolbyVision][Video] buf[2]=%x(%d KB), phy(%x) \n", (UINT32)i3ddmaCtrl.cap_buffer[2].cache, i3ddmaCtrl.cap_buffer[2].size >> 10, (UINT32)i3ddmaCtrl.cap_buffer[2].phyaddr);

		if(drvif_i3ddma_triplebuf_flag())
		{
			i3ddmaCtrl.cap_buffer[4].cache= NULL;//(void*)(malloccacheaddr_video + size_video);
			i3ddmaCtrl.cap_buffer[4].phyaddr = (unsigned int)i3ddmaCtrl.cap_buffer[0].phyaddr + size_video*2; //(unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[2].cache);
			i3ddmaCtrl.cap_buffer[4].size = size_video;
			//i3ddmaCtrl.cap_buffer[4].getsize = getSize;
			pr_debug("[DolbyVision][Video] buf[2]=%x(%d KB), phy(%x) \n", (UINT32)i3ddmaCtrl.cap_buffer[4].cache, i3ddmaCtrl.cap_buffer[4].size >> 10, (UINT32)i3ddmaCtrl.cap_buffer[4].phyaddr);
		}
		//i3ddma protection
		rtd_outl(H3DDMA_Cap_BoundaryAddr2_reg, i3ddmaCtrl.cap_buffer[0].phyaddr);//low limit
		if(drvif_i3ddma_triplebuf_flag())
		{
			rtd_outl(H3DDMA_Cap_BoundaryAddr1_reg, i3ddmaCtrl.cap_buffer[4].phyaddr + size_video);//high limit
		}
		else
		{
			rtd_outl(H3DDMA_Cap_BoundaryAddr1_reg, i3ddmaCtrl.cap_buffer[2].phyaddr + size_video);//high limit
		}
    }

    if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)&&
	   ((get_HDMI_HDR_mode() == HDR_DOLBY_HDMI) || (get_HDMI_HDR_mode() == HDR_HDR10_HDMI))) {
		//not force i3ddma case
		if (i3ddmaCtrl.cap_buffer[1].cache == NULL ){
			#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
			malloccacheaddr_metadata = (unsigned int)dvr_malloc_uncached_specific(size_metadata*2, GFP_DCU1, (void **)&i3ddmaCtrl.cap_buffer[1].uncache);//(unsigned int)dvr_malloc(size_metadata*2);//for double buffer use
			#else
			malloccacheaddr_metadata = (unsigned int)dvr_malloc_uncached_specific(size_metadata*2, GFP_DCU1, NULL);//(unsigned int)dvr_malloc(size_metadata*2);//for double buffer use
			#endif
			if(malloccacheaddr_metadata == (unsigned int)NULL)
			{
				pr_emerg("[DolbyVision] alloc idma sequence metadata memory failed[%x]\n", malloccacheaddr_metadata);
				return 1; //malloc memory fail
			}

			// buffer[1] -- metadata capture buffer
			i3ddmaCtrl.cap_buffer[1].cache= (void*)(malloccacheaddr_metadata);
			i3ddmaCtrl.cap_buffer[1].phyaddr =  (unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[1].cache);
			i3ddmaCtrl.cap_buffer[1].size = size_metadata;
			pr_debug("[DolbyVision][Meta] buf[1]=%x(%d KB), phy(%x) \n", (UINT32)i3ddmaCtrl.cap_buffer[1].cache, i3ddmaCtrl.cap_buffer[1].size >> 10, (UINT32)i3ddmaCtrl.cap_buffer[1].phyaddr);

			// buffer[3] -- not used yet
			i3ddmaCtrl.cap_buffer[3].cache= (void*)(malloccacheaddr_metadata + size_metadata);
			i3ddmaCtrl.cap_buffer[3].phyaddr =  (unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[3].cache);
			i3ddmaCtrl.cap_buffer[3].size = size_metadata;
			pr_debug("[DolbyVision][Meta] buf[3]=%x(%d KB), phy(%x) \n", (UINT32)i3ddmaCtrl.cap_buffer[3].cache, i3ddmaCtrl.cap_buffer[3].size >> 10, (UINT32)i3ddmaCtrl.cap_buffer[3].phyaddr);
	    }

		//i3ddma protection
		if(i3ddmaCtrl.cap_buffer[1].phyaddr < i3ddmaCtrl.cap_buffer[0].phyaddr)
		{
			rtd_outl(H3DDMA_Cap_BoundaryAddr2_reg, i3ddmaCtrl.cap_buffer[1].phyaddr); //low limit
			if(drvif_i3ddma_triplebuf_flag())
			{
				rtd_outl(H3DDMA_Cap_BoundaryAddr1_reg, i3ddmaCtrl.cap_buffer[4].phyaddr + size_video);//high limit
			}
			else
			{
				rtd_outl(H3DDMA_Cap_BoundaryAddr1_reg, i3ddmaCtrl.cap_buffer[2].phyaddr + size_video);//high limit
			}
		}
		else
		{
			rtd_outl(H3DDMA_Cap_BoundaryAddr2_reg, i3ddmaCtrl.cap_buffer[0].phyaddr); //low limit
			rtd_outl(H3DDMA_Cap_BoundaryAddr1_reg, i3ddmaCtrl.cap_buffer[3].phyaddr + size_metadata);//high limit
		}
	}
#if 0
	for (i=0; i<4; i++)
	{
		if ((i3ddmaCtrl.cap_buffer[i].cache == NULL)&&(i3ddmaCtrl.cap_buffer[i].phyaddr == NULL)) {
			pr_emerg("[DolbyVision] malloc HDMI buffer fail .......................................\n");
			i3ddmaCtrl.i3ddma_3d_capability = 0;
			return 1;
		}
	}
#endif
#if 0//def CONFIG_FORCE_RUN_I3DDMA
		i3ddmaCtrl.i3ddma_3d_capability = 1;
#endif

	return 0;
}

void I3DDMA_DolbyVision_buf_setting(void)
{
	rtd_outl(H3DDMA_Cap_L1_Start_reg, metadataCtrl.cap_buffer[0].phyaddr);
	rtd_outl(H3DDMA_Cap_R1_Start_reg, metadataCtrl.cap_buffer[1].phyaddr);
	rtd_outl(H3DDMA_Cap_L2_Start_reg, metadataCtrl.cap_buffer[2].phyaddr);
	rtd_outl(H3DDMA_Cap_R2_Start_reg, metadataCtrl.cap_buffer[3].phyaddr);
}

unsigned char I3DDMA_DolbyVision_MetaData_Init(void) {
	unsigned int size_metadata = 1024 * 1024; // 1MB for metadata buffer
	unsigned int size_video = 3840 * 40 * 3 ;//RGB444 8bit sequence buffer
	int i;
    int getSize = 0;

	if(metadataCtrl.i3ddma_3d_capability == 1)
	{
		pr_emerg("metadata memory have exsit, so return!\n");
		return 0;
	}
	unsigned int malloccacheaddr_metadata = (unsigned int)dvr_malloc_uncached_specific(size_metadata*2, GFP_DCU1, NULL);//(unsigned int)dvr_malloc(size_metadata*2);//for double buffer use
	//unsigned int malloccacheaddr_video = (unsigned int)dvr_malloc_uncached_specific(size_video*2, GFP_DCU2_FIRST, NULL);//(unsigned int)dvr_malloc(size_video*2);//for double buffer use
    unsigned int malloccacheaddr_video_phyaddr = NULL;

	pr_debug("%s.%d\n", __FUNCTION__, __LINE__);
	if((malloccacheaddr_metadata == (unsigned int)NULL)/*|| (malloccacheaddr_video == (unsigned int)NULL)*/)
	{
		pr_emerg("[DolbyVision] alloc idma sequence metadata memory failed[%x]\n", malloccacheaddr_metadata);
		return 1; //malloc memory fail
	}
    pr_debug("[DolbyVision][%s] call VBM_BorrowMemChunk\n",__FUNCTION__);
    if (VBM_BorrowMemChunk((unsigned long *)(&malloccacheaddr_video_phyaddr), (unsigned long *)(&getSize), size_video*2) != 0) {
		pr_emerg("[DolbyVision] alloc idma video sequence memory failed[%x]\n",  malloccacheaddr_video_phyaddr);
		return 1; //malloc memory fail
	}

	/*
	rtd_outl(H3DDMA_Cap_L1_Start_reg, cap_buffer[0].phyaddr);
	rtd_outl(H3DDMA_Cap_L2_Start_reg, cap_buffer[2].phyaddr);
	rtd_outl(H3DDMA_Cap_R1_Start_reg, cap_buffer[1].phyaddr);
	rtd_outl(H3DDMA_Cap_R2_Start_reg, cap_buffer[3].phyaddr);
	*/

	// buffer[0][2] -- video capture buffer
	metadataCtrl.cap_buffer[0].cache= NULL;//(void*)(malloccacheaddr_video);
	metadataCtrl.cap_buffer[0].phyaddr = (unsigned int)malloccacheaddr_video_phyaddr; //(unsigned int)dvr_to_phys((void*)metadataCtrl.cap_buffer[0].cache);
	metadataCtrl.cap_buffer[0].size = size_video;
	metadataCtrl.cap_buffer[0].getsize = getSize;
	pr_debug("[DolbyVision][Video] buf[0]=%x(%d KB), phy(%x) \n", (UINT32)metadataCtrl.cap_buffer[0].cache, metadataCtrl.cap_buffer[0].size >> 10, (UINT32)metadataCtrl.cap_buffer[0].phyaddr);

	metadataCtrl.cap_buffer[2].cache= NULL;//(void*)(malloccacheaddr_video + size_video);
	metadataCtrl.cap_buffer[2].phyaddr = (unsigned int)malloccacheaddr_video_phyaddr + size_video;//(unsigned int)dvr_to_phys((void*)metadataCtrl.cap_buffer[2].cache);
	metadataCtrl.cap_buffer[2].size = size_video;
	metadataCtrl.cap_buffer[2].getsize = getSize;
	pr_debug("[DolbyVision][Video] buf[2]=%x(%d KB), phy(%x) \n", (UINT32)metadataCtrl.cap_buffer[2].cache, metadataCtrl.cap_buffer[2].size >> 10, (UINT32)metadataCtrl.cap_buffer[2].phyaddr);

	// buffer[1] -- metadata capture buffer
	metadataCtrl.cap_buffer[1].cache= (void*)(malloccacheaddr_metadata);
	metadataCtrl.cap_buffer[1].phyaddr =  (unsigned int)dvr_to_phys((void*)metadataCtrl.cap_buffer[1].cache);
	metadataCtrl.cap_buffer[1].size = size_metadata;
	pr_debug("[DolbyVision][Meta] buf[1]=%x(%d KB), phy(%x) \n", (UINT32)metadataCtrl.cap_buffer[1].cache, metadataCtrl.cap_buffer[1].size >> 10, (UINT32)metadataCtrl.cap_buffer[1].phyaddr);

	// buffer[3] -- not used yet
	metadataCtrl.cap_buffer[3].cache= (void*)(malloccacheaddr_metadata + size_metadata);
	metadataCtrl.cap_buffer[3].phyaddr =  (unsigned int)dvr_to_phys((void*)metadataCtrl.cap_buffer[3].cache);
	metadataCtrl.cap_buffer[3].size = size_metadata;
	pr_debug("[DolbyVision][Meta] buf[3]=%x(%d KB), phy(%x) \n", (UINT32)metadataCtrl.cap_buffer[3].cache, metadataCtrl.cap_buffer[3].size >> 10, (UINT32)metadataCtrl.cap_buffer[3].phyaddr);

	metadataCtrl.i3ddma_3d_capability = 1;
	for (i=0; i<4; i++)
	{
		if ((metadataCtrl.cap_buffer[i].cache == NULL)&&(metadataCtrl.cap_buffer[i].phyaddr == NULL)) {
			pr_emerg("[DolbyVision] malloc HDMI buffer fail .......................................\n");
			metadataCtrl.i3ddma_3d_capability = 0;
			return 1;
		}
	}


	return 0;
}

unsigned char I3DDMA_DolbyVision_MetaData_DeInit(void){
	int i;
	if ((metadataCtrl.cap_buffer[0].cache)||(metadataCtrl.cap_buffer[0].phyaddr))
	{
		//dvr_free(metadataCtrl.cap_buffer[0].cache);
		if(metadataCtrl.cap_buffer[0].phyaddr)
		{
		    pr_debug("[DolbyVision][%s] call VBM_ReturnMemChunk\n",__FUNCTION__);
			VBM_ReturnMemChunk(metadataCtrl.cap_buffer[0].phyaddr,metadataCtrl.cap_buffer[0].getsize);
		}
	}

	if (metadataCtrl.cap_buffer[1].cache)
	{
		dvr_free(metadataCtrl.cap_buffer[1].cache);
	}

	for (i=0; i<4; i++) {
		if ((metadataCtrl.cap_buffer[i].cache)||(metadataCtrl.cap_buffer[i].phyaddr)) {
			metadataCtrl.cap_buffer[i].cache = NULL;
			metadataCtrl.cap_buffer[i].phyaddr = (unsigned long)NULL;
			metadataCtrl.cap_buffer[i].size = 0;
			metadataCtrl.cap_buffer[i].getsize = 0;
		}
	}
	metadataCtrl.i3ddma_3d_capability= 0;
	pr_debug("[DolbyVision] Deinit done!\n");

	return 0;
}


unsigned char I3DDMA_3D_Init(void) {
	unsigned int size = 1920 * 1080 * 4 ;//up 444 10bit sequence buffer
	int i;
	unsigned int malloccacheaddr = (unsigned int)dvr_malloc(size*4);//for double buffer use

	if(malloccacheaddr == (unsigned int)NULL)
	{
		pr_debug("alloc idma sequence memory failed\n");
		return 1;
	}

	for (i=0; i<4; i++) {
		if(i3ddmaCtrl.cap_buffer[i].cache == NULL){
			i3ddmaCtrl.cap_buffer[i].cache= (void*)(malloccacheaddr+i*size);
			i3ddmaCtrl.cap_buffer[i].phyaddr =  (unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[i].cache);
			i3ddmaCtrl.cap_buffer[i].size = size;
			pr_debug("[HDMI-3D] buf[%d]=%x(%d KB), phy(%x) \n", i, (UINT32)i3ddmaCtrl.cap_buffer[i].cache, i3ddmaCtrl.cap_buffer[i].size >> 10, (UINT32)i3ddmaCtrl.cap_buffer[i].phyaddr);
		}

		if (i3ddmaCtrl.cap_buffer[i].cache == NULL) {
			pr_debug("malloc HDMI buffer fail .......................................\n");
			i3ddmaCtrl.i3ddma_3d_capability = 0;
			return 1;
		}
	}

	return 0;
}

unsigned char I3DDMA_3DDMAInit(void) {
	unsigned int size = 1920 * 1080 * 4 * 2;//up 422 sequence buffer 4k2k
	int i;
	unsigned int malloccacheaddr = (unsigned int)dvr_malloc_uncached_specific(size*2, GFP_DCU2_FIRST, NULL);

	if(malloccacheaddr == (unsigned int)NULL)
	{
		pr_debug("alloc idma sequence memory failed\n");
		return 1;
	}

	for (i=0; i<2; i++) {
		if(i3ddmaCtrl.cap_buffer[i].cache == NULL){
			i3ddmaCtrl.cap_buffer[i].cache= (void*)(malloccacheaddr+i*size);
			//i3ddmaCtrl.cap_buffer[i].phyaddr =  (unsigned int)virt_to_phys((void*)i3ddmaCtrl.cap_buffer[i].cache);
			i3ddmaCtrl.cap_buffer[i].phyaddr =  (unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[i].cache);
			i3ddmaCtrl.cap_buffer[i].size = size;
			pr_debug("[HDMI-3D] buf[%d]=%x(%d KB), phy(%x) \n", i, (UINT32)i3ddmaCtrl.cap_buffer[i].cache, i3ddmaCtrl.cap_buffer[i].size >> 10, (UINT32)i3ddmaCtrl.cap_buffer[i].phyaddr);
		}

		if (i3ddmaCtrl.cap_buffer[i].cache == NULL) {
			pr_debug("malloc HDMI buffer fail .......................................\n");
			i3ddmaCtrl.i3ddma_3d_capability = 0;
			return 1;
		}
	}

	return 0;
}


void I3DDMA_DolbyVision_HDMI_DeInit(void) {
	int i;

	if ((i3ddmaCtrl.cap_buffer[0].cache)|| (i3ddmaCtrl.cap_buffer[0].phyaddr))
	{
		//dvr_free(i3ddmaCtrl.cap_buffer[0].cache);
		if(i3ddmaCtrl.cap_buffer[0].phyaddr)
		{
		    pr_debug("[DolbyVision][%s] call VBM_ReturnMemChunk\n",__FUNCTION__);
			VBM_ReturnMemChunk(i3ddmaCtrl.cap_buffer[0].phyaddr,i3ddmaCtrl.cap_buffer[0].getsize);
		}
	}

	if (i3ddmaCtrl.cap_buffer[1].cache)
	{
		dvr_free(i3ddmaCtrl.cap_buffer[1].cache);
	}

	for (i=0; i<4; i++) {
		if ((i3ddmaCtrl.cap_buffer[i].cache)||(i3ddmaCtrl.cap_buffer[i].phyaddr)) {
			i3ddmaCtrl.cap_buffer[i].cache = NULL;
			i3ddmaCtrl.cap_buffer[i].phyaddr = (unsigned long)NULL;
			i3ddmaCtrl.cap_buffer[i].size = 0;
			i3ddmaCtrl.cap_buffer[i].getsize = 0;//test
		}
	}
	i3ddmaCtrl.i3ddma_3d_capability= 0;
	pr_debug("[DolbyVision] Deinit done!\n");
}


void I3DDMA_3DDMADeInit(void) {
	int i;
	if (i3ddmaCtrl.cap_buffer[0].cache)
	{
		dvr_free(i3ddmaCtrl.cap_buffer[0].cache);
	}
	for (i=0; i<2; i++) {
		if (i3ddmaCtrl.cap_buffer[i].cache) {
			//pli_freeContinuousMemory(i3ddmaCtrl.cap_buffer[i].cache);
			i3ddmaCtrl.cap_buffer[i].cache = NULL;
			i3ddmaCtrl.cap_buffer[i].phyaddr = (unsigned long)NULL;
			i3ddmaCtrl.cap_buffer[i].size = 0;
		}
	}
	i3ddmaCtrl.i3ddma_3d_capability= 0;
	pr_debug("[HDMI-3D] Deinit done!\n");
}
extern int Get_GamemodeSaveI3ddmaGetcurMode(void);
void drv_I3ddmaVodma_GameMode_iv2pv_delay(unsigned char enable){
	if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC){
		printk("##VDEC source no need set iv2pv delay\n");
		return; 
	}

	UINT32 id2pv_delay = 0;
	UINT32 timeout;
	vodma_vodma_pvs0_gen_RBUS vodma_vodma_pvs0_gen_Reg;

	UINT32 voHtotal;
	UINT32 voVactive;
	UINT32 VoClock;
	UINT32 i3ddmaVtotal;
	UINT32 i3ddmaVstart;
	UINT32 i3ddmaVactive;
	UINT32 i3ddmaVfreq;
	UINT32 temp1;
	UINT32 ulI3ddmaDenEnd;
	unsigned char ret;
	SLR_VOINFO *pVOInfo = NULL;

	printk("\r\n####func:%s start line:%d####%d\r\n", __FUNCTION__, __LINE__,enable);
	printk("[qiangzhou]SLR_INPUT_MODE_CURR = %d\n",Get_GamemodeSaveI3ddmaGetcurMode());
	/*all i3ddma source  vodma will sync i3ddma, so all i3ddma source, need setting gamemode iv2pv delay*/
	if (enable == _ENABLE){
		/*Modify to use formula to calculate the iv2pv delay @Crixus 20161130*/
		voHtotal = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_LEN);
		voVactive = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN);
		pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());

		VoClock = pVOInfo->pixel_clk;

		i3ddmaVtotal = i3ddmaCtrl.pgen_timing->v_total;
		i3ddmaVstart = i3ddmaCtrl.pgen_timing->v_act_sta;
		i3ddmaVactive = i3ddmaCtrl.pgen_timing->v_act_len;
		i3ddmaVfreq = i3ddmaCtrl.pgen_timing->v_freq;
		if(i3ddmaVfreq % 10 > 4)
			i3ddmaVfreq = i3ddmaVfreq / 10 + 1;
		else
			i3ddmaVfreq = i3ddmaVfreq / 10;

		//printk(KERN_EMERG"[crixus]VoClock = %d, voHtotal = %d, voVactive = %d\n", VoClock, voHtotal, voVactive);
		//printk(KERN_EMERG"[crixus]i3ddmaVtotal = %d, i3ddmaVstart = %d, i3ddmaVactive = %d, i3ddmaVfreq = %d\n", i3ddmaVtotal, i3ddmaVstart, i3ddmaVactive, i3ddmaVfreq);

		/*
			formula: 1/i3ddma_clock * i3ddma_Htotal * (i3ddma_Vactive + i3ddma_Vstart) <= 1/vo_clock * vo_Htotal * (vo_Vactive + iv2pv_delay)
			temp1 = 1/(i3ddma_Htotal*i3ddma_Vtotal*i3ddma_freq) * i3ddma_Htotal * (i3ddma_Vactive + i3ddma_Vstart)
				   = 1/(i3ddma_Vtotal*i3ddma_freq) * (i3ddma_Vactive + i3ddma_Vstart)
				   = (i3ddma_Vactive + i3ddma_Vstart) / (i3ddma_Vtotal*i3ddma_freq)
			iv2pv_delay >= temp1 * (vo_clock / vo_Htotal) - vo_Vactive;
		*/

		temp1 = (i3ddmaVactive + i3ddmaVstart) * 1000000 / (i3ddmaVtotal * i3ddmaVfreq);


		ulI3ddmaDenEnd = temp1 * (VoClock / voHtotal) / 1000000;
		//printk(KERN_EMERG"[crixus]1.temp1 = %d,  ulI3ddmaDenEnd = %d\n", temp1, ulI3ddmaDenEnd);

		if(ulI3ddmaDenEnd  < voVactive) {
			id2pv_delay = 2;
			printk("[crixus] ulI3ddmaDenEnd  < voVactive, id2pv_delay = 2\n");
		}
		else
		{

			//temp1 = temp1 * (VoClock / voHtotal) / 1000000 - voVactive;/*Modify to use VO real clock to calculate @Crixus 20161230*/
			temp1 = ulI3ddmaDenEnd - voVactive;/*Modify to use VO real clock to calculate @Crixus 20161230*/
			//printk(KERN_EMERG"[crixus]2.temp1 = %d\n", temp1);

			id2pv_delay = temp1 + VODMA_IV2PV_DELAY_CAL_MARGIN + I3DDMA_DRAM_MARGIN;
			//printk(KERN_EMERG"[crixus]delay line = %d\n", id2pv_delay);

			id2pv_delay = id2pv_delay * Scaler_DispGetInputInfo(SLR_INPUT_H_LEN);
			//printk(KERN_EMERG"[crixus]id2pv_delay = 0x%x\n", id2pv_delay);
		}
	}
	else{
		id2pv_delay = 2;//default setting
	}

//	vodma_vodma_pvs0_gen_Reg.regValue = IoReg_Read32(VODMA_VODMA_PVS0_Gen_reg);
//	vodma_vodma_pvs0_gen_Reg.iv2pv_dly = id2pv_delay;
//	IoReg_Write32(VODMA_VODMA_PVS0_Gen_reg, vodma_vodma_pvs0_gen_Reg.regValue);
//	pr_debug("[Game Mode] i3ddma vodma iv2pv delay = %x\n", id2pv_delay);
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SET_IV2PV_DELAY, id2pv_delay, 1))){	//info video fw change iv2pv_delay
		pr_err("ret=%d, SCALERIOC_SET_IV2PV_DELAY RPC fail !!!\n", ret);
	}

}

extern StructSrcRect get_main_input_size(void);
unsigned int drv_I3ddmaVodma_get_vodma_overscan_shift_data(void)
{
	StructSrcRect main_input_size;
	unsigned int data_bit_width;
	unsigned int vpos;
	unsigned int videoWidth;
	unsigned int shift_pixel;
	unsigned int shift_vertical_data;

	main_input_size = get_main_input_size();

	//check i3ddma timing gen is ready
	if(i3ddmaCtrl.pgen_timing == NULL){
		pr_emerg("[%s] i3ddma pgen_timing == NULL \n", __FUNCTION__);
		return 0;
	}

	//VOColorMap size = 4
	if(i3ddmaCtrl.pgen_timing->color >= I3DDMA_COLOR_UNKNOW){
		pr_emerg("[%s] over color size (%d)\n", __FUNCTION__, i3ddmaCtrl.pgen_timing->color);
		return 0;
	}

	if(i3ddmaCtrl.pgen_timing->progressive == 0){
		vpos = main_input_size.srcy/2;
	}else{
		vpos = main_input_size.srcy;
	}
	videoWidth = i3ddmaCtrl.pgen_timing->h_act_len;

	//plane->shift_vertical_data = vpos * ((config_hdmi_info_save.data_bit_width * (plane->displayWin.width/4) * shift_pixel + 127) / 128)*16;
	data_bit_width = (i3ddmaCtrl.pgen_timing->depth == I3DDMA_COLOR_DEPTH_8B)? 8: 10;

	if (VOColorMap[i3ddmaCtrl.pgen_timing->color] == VO_CHROMA_YUV420) {
		shift_pixel = 6;
	} else if (VOColorMap[i3ddmaCtrl.pgen_timing->color] == VO_CHROMA_YUV422) {
		shift_pixel = 8;
	} else if (VOColorMap[i3ddmaCtrl.pgen_timing->color] == VO_CHROMA_YUV444) {
		shift_pixel = 12;
	} else if (VOColorMap[i3ddmaCtrl.pgen_timing->color] == VO_CHROMA_ARGB8888) {
		shift_pixel = 16;
	} else if (VOColorMap[i3ddmaCtrl.pgen_timing->color] == VO_CHROMA_RGB888) {
		shift_pixel = 12;
	} else {
		shift_pixel = 12;
	}
	shift_vertical_data = vpos * ((data_bit_width * (videoWidth/4) * shift_pixel + 127) / 128)*16;
	//pr_emerg("[%s] main_input_size (%d.%d.%d.%d) \n", __FUNCTION__, main_input_size.srcx, main_input_size.srcy, main_input_size.src_wid, main_input_size.src_height);
	//pr_emerg("[%s] vpos=%d, progressive = %d\n", __FUNCTION__, vpos, i3ddmaCtrl.pgen_timing->progressive);
	//pr_emerg("[%s] videoWidth=%d\n", __FUNCTION__, videoWidth);
	//pr_emerg("[%s] data_bit_width=%d, targetDepth=%d\n", __FUNCTION__, data_bit_width, i3ddmaCtrl.targetDepth);
	//pr_emerg("[%s] shift_pixel=%d, VOColorMap=%d, color=%d\n", __FUNCTION__, shift_pixel, VOColorMap[i3ddmaCtrl.pgen_timing->color], i3ddmaCtrl.pgen_timing->color);
	//pr_emerg("[%s] shift_vertical_data=%d\n", __FUNCTION__, shift_vertical_data);

	return shift_vertical_data;
}

extern unsigned char get_AVD_Input_Source(void);
void drv_I3ddmaVodma_SingleBuffer_GameMode(unsigned char enable)
{
	StructSrcRect main_input_size;
	unsigned int shift_vertical_data = 0;
	int block_offset=0;

	vodma_vodma_i2rnd_fifo_th_RBUS vodma_vodma_i2rnd_fifo_th_Reg;
	vodma_vodma_i2rnd_fifo_th_Reg.regValue = IoReg_Read32(VODMA_vodma_i2rnd_fifo_th_reg);
	vodma_vodma_i2rnd_dma_info_RBUS vodma_vodma_i2rnd_dma_info_Reg;
	vodma_vodma_i2rnd_dma_info_Reg.regValue = 0;

	pr_notice("[%s] enable=%d\n", __FUNCTION__, enable);

#ifdef CONFIG_ALL_SOURCE_DATA_FS
	VSC_INPUT_TYPE_T srctype;
	unsigned char ch = Scaler_Get_CurVoInfo_plane();
	unsigned int v_len,interlace;
	extern StructDisplayInfo *Get_VO_Dispinfo(unsigned char ch);

	if ((Get_VO_Dispinfo(ch)->disp_status&_BIT8)>>8) { // interlace
		v_len=(Get_VO_Dispinfo(ch)->IPV_ACT_LEN_PRE<<1);
		interlace=1;
	} else {
		v_len=Get_VO_Dispinfo(ch)->IPV_ACT_LEN_PRE;
		interlace=0;
	}

	main_input_size = get_main_input_size();

	pr_notice("main_input_size.src_height= %d, v_len = %d \n", main_input_size.src_height, v_len);

	//vo not do overscan
	if(main_input_size.src_height != v_len){
		return 0;
	}

	srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);
	if((srctype != VSC_INPUTSRC_VDEC) && (srctype != VSC_INPUTSRC_JPEG) ){
		//vodma do overscan, so the vo display buffer should cut overscan address.
		shift_vertical_data = drv_I3ddmaVodma_get_vodma_overscan_shift_data();
		pr_notice("[%s] shift_vertical_data=%d\n", __FUNCTION__, shift_vertical_data);
	}
#endif

    // vflip buffer start address offset control
    if(Get_PANEL_VFLIP_ENABLE() && i3ddmaCtrl.pgen_timing){
        unsigned int TotalBits;
        unsigned char data_bit_width, chroma_bit_width;
        data_bit_width = i3ddmaCtrl.pgen_timing->depth == I3DDMA_COLOR_DEPTH_8B? 8: 10;
        chroma_bit_width = VOColorMap[i3ddmaCtrl.pgen_timing->color] == VO_CHROMA_YUV422? 2: 3;
        TotalBits = i3ddmaCtrl.pgen_timing->h_act_len * chroma_bit_width * data_bit_width ;
        TotalBits = (TotalBits+127)/128*128;
	block_offset = (TotalBits * (i3ddmaCtrl.pgen_timing->v_act_len - 1) ) / 8;

        pr_debug("[Game Mode][VFlip] H/V=%dx%d, depth/chroma/size=%d/%d/%d\n",
            i3ddmaCtrl.pgen_timing->h_act_len, i3ddmaCtrl.pgen_timing->v_act_len,
            data_bit_width, chroma_bit_width, TotalBits);

        if(!enable){
            pr_debug("[Game Mode][VFlip] buffer[2]=%x->%x+%d\n", IoReg_Read32(VODMA_VODMA_V1_SEQ_3D_L2_reg), (unsigned int)i3ddmaCtrl.cap_buffer[2].phyaddr, block_offset);
        }
    }
#if 0
    else
        pr_debug("[Game Mode] VFLip/PGen=%d/%x\n", Get_PANEL_VFLIP_ENABLE(), (unsigned int)i3ddmaCtrl.pgen_timing);
#endif
	//Eric@20180706 [TCL2841-2661] Work Arround : 576i timing use i3ddma 2buffer
	if((enable == TRUE) && !((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID) == 720) && (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN) == 288))){
		IoReg_Write32(H3DDMA_Cap_L2_Start_reg, i3ddmaCtrl.cap_buffer[0].phyaddr);
		if(Get_PANEL_VFLIP_ENABLE() && i3ddmaCtrl.pgen_timing)
		    IoReg_Write32(VODMA_VODMA_V1_SEQ_3D_L2_reg, i3ddmaCtrl.cap_buffer[0].phyaddr + block_offset - shift_vertical_data);
		else
		    IoReg_Write32(VODMA_VODMA_V1_SEQ_3D_L2_reg, i3ddmaCtrl.cap_buffer[0].phyaddr + shift_vertical_data + block_offset);

		vodma_vodma_i2rnd_fifo_th_Reg.dma_info_th_dispm = 1;
		vodma_vodma_i2rnd_fifo_th_Reg.dma_info_th_i3ddma = 1;

		vodma_vodma_i2rnd_dma_info_Reg.dma_info_rptr_fw_set_dispm = 1;
		vodma_vodma_i2rnd_dma_info_Reg.dma_info_rptr_fw_set_i3ddma = 1;
		vodma_vodma_i2rnd_dma_info_Reg.dma_info_wptr_fw_set_dispm = 1;
		vodma_vodma_i2rnd_dma_info_Reg.dma_info_wptr_fw_set_i3ddma = 1;
	}else if(i3ddmaCtrl.cap_buffer[2].phyaddr){
		IoReg_Write32(H3DDMA_Cap_L2_Start_reg, i3ddmaCtrl.cap_buffer[2].phyaddr);
		if(Get_PANEL_VFLIP_ENABLE() && i3ddmaCtrl.pgen_timing)
		    IoReg_Write32(VODMA_VODMA_V1_SEQ_3D_L2_reg, i3ddmaCtrl.cap_buffer[2].phyaddr + block_offset - shift_vertical_data);
		else		
		    IoReg_Write32(VODMA_VODMA_V1_SEQ_3D_L2_reg, i3ddmaCtrl.cap_buffer[2].phyaddr + shift_vertical_data + block_offset);
		vodma_vodma_i2rnd_fifo_th_Reg.dma_info_th_dispm = 2;
		vodma_vodma_i2rnd_fifo_th_Reg.dma_info_th_i3ddma = 2;

		vodma_vodma_i2rnd_dma_info_Reg.dma_info_rptr_fw_set_dispm = 1;
		vodma_vodma_i2rnd_dma_info_Reg.dma_info_rptr_fw_set_i3ddma = 1;
		vodma_vodma_i2rnd_dma_info_Reg.dma_info_wptr_fw_set_dispm = 1;
		vodma_vodma_i2rnd_dma_info_Reg.dma_info_wptr_fw_set_i3ddma = 1;
	}
	IoReg_Write32(VODMA_vodma_i2rnd_fifo_th_reg, vodma_vodma_i2rnd_fifo_th_Reg.regValue);
	IoReg_Write32(VODMA_vodma_i2rnd_dma_info_reg, vodma_vodma_i2rnd_dma_info_Reg.regValue);
	pr_debug("[Game Mode] i3ddma and vodma game mode done enable=%d!!, L2=%x\n",enable, IoReg_Read32(VODMA_VODMA_V1_SEQ_3D_L2_reg));
}
#ifdef CONFIG_SCALER_BRING_UP
extern int VODMA_ConfigHDMI(VIDEO_RPC_VOUT_CONFIG_HDMI_3D *HDMI_INFO);
#endif
char I3DDMA_SetupVODMA(I3DDMA_TIMING_T *timing) {
#if 0//[mark by crixus-mac3 linux based]
	VIDEO_RPC_VOUT_CONFIG_HDMI_3D config;
	CLNT_STRUCT clnt;

	printk("%s\n", __FUNCTION__);
	clnt = prepareCLNT(BLOCK_MODE | USE_INTR_BUF | SEND_VIDEO_CPU, VIDEO_SYSTEM, VERSION);

	memset(&config, 0, sizeof(VIDEO_RPC_VOUT_CONFIG_HDMI_3D));
	config.chroma_fmt = VOColorMap[timing->color];
	config.width = timing->h_act_len;
	config.height = timing->v_act_len;
	config.framerate = timing->v_freq * 100;

	// [IDMA] interlaced video data FRC in M-domain, IDMA VO go auto mode
	if((timing->progressive == 0)|| (drvif_scaler3d_decide_3d_SG_data_FRC() == TRUE))
		config.hw_auto_mode = 1;
	else
		config.hw_auto_mode = 0;

/*
	if (timing->i3ddma_3dformat == I3DDMA_SIDE_BY_SIDE_HALF) {
		config.quincunx_en = timing->quincunx_en;
		config.quincunx_mode_fw = timing->quincunx_mode;
	} else {
		config.quincunx_en = 0;
	}
*/
	config.quincunx_en = 0;

	config.l1_st_adr = rtd_inl(I3DDMA_CAP_L1_START_VADDR);
	config.r1_st_adr = rtd_inl(I3DDMA_CAP_R1_START_VADDR);
	config.l2_st_adr = rtd_inl(I3DDMA_CAP_L2_START_VADDR);
	config.r2_st_adr = rtd_inl(I3DDMA_CAP_R2_START_VADDR);
	config.progressive = timing->progressive;
	printk("~~~~~~ I3DDMA_SetupVODMA ~~~ progressive (%d) \n", config.progressive);
	config.videoPlane = VO_VIDEO_PLANE_V1;
	config.data_bit_width = (timing->depth == I3DDMA_COLOR_DEPTH_8B)? 8: 10;
	config.sensio3D_en = (timing->i3ddma_3dformat == I3DDMA_SENSIO? 1: 0);
	config.sg3d_dataFrc = drvif_scaler3d_decide_3d_SG_data_FRC()|| drvif_scaler3d_decide_3d_PR_enable_IDMA();

	HRESULT* hr = VIDEO_RPC_VOUT_ToAgent_ConfigHDMI_3D_0(&config, &clnt);
	if (hr < 0) {
		printk("CONFIG HDMI 3D RPC fail\n");
		return FALSE;
	}
	free(hr);
#endif
#if 1

#ifdef CONFIG_RTK_KDRV_RPC
	unsigned long result = 0;
#endif
	VIDEO_RPC_VOUT_CONFIG_HDMI_3D *config_data;

	//struct page *page = 0;
	//page = alloc_page(GFP_KERNEL);
	//config_datatmp = (VIDEO_RPC_VOUT_SET_3D_MODE *)page_address(page);
	unsigned int vir_addr, vir_addr_noncache;
	unsigned int phy_addr;

	vir_addr = (unsigned int)dvr_malloc_uncached_specific(sizeof(VIDEO_RPC_VOUT_CONFIG_HDMI_3D), GFP_DCU1, (void **)&vir_addr_noncache);
	phy_addr = (unsigned int)dvr_to_phys((void*)vir_addr);

	config_data = (VIDEO_RPC_VOUT_CONFIG_HDMI_3D *)vir_addr_noncache;

	memset(config_data, 0, sizeof(VIDEO_RPC_VOUT_CONFIG_HDMI_3D));
	config_data->width = timing->h_act_len;
	config_data->height = timing->v_act_len;
	if(timing->color < I3DDMA_COLOR_UNKNOW)	//Klocwork: buffer may overflow.
		config_data->chroma_fmt = VOColorMap[timing->color];
	else
		config_data->chroma_fmt = VOColorMap[I3DDMA_COLOR_RGB];
	config_data->data_bit_width = (timing->depth == I3DDMA_COLOR_DEPTH_8B)? 8: 10;
	config_data->framerate =  timing->v_freq * 100;
	config_data->framerate_ori = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_V_FREQ) * 100;
	config_data->progressive = timing->progressive;
	config_data->l1_st_adr = rtd_inl(H3DDMA_Cap_L1_Start_reg);
	config_data->r1_st_adr = rtd_inl(H3DDMA_Cap_R1_Start_reg);
	config_data->l2_st_adr = rtd_inl(H3DDMA_Cap_L2_Start_reg);
	config_data->r2_st_adr = rtd_inl(H3DDMA_Cap_R2_Start_reg);
	config_data->l3_st_adr = rtd_inl(H3DDMA_Cap_L3_Start_reg);//input fast use 3-buffer @Crixus 20170508
	config_data->r3_st_adr = rtd_inl(H3DDMA_Cap_R3_Start_reg);
	//config_data->hw_auto_mode = 1;
	// Dolby Vision force in FW mode
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if(drvif_i3ddma_triplebuf_flag())
		config_data->hw_auto_mode = 1;
	else
		config_data->hw_auto_mode = 1;
#else
		config_data->hw_auto_mode = ((get_HDMI_HDR_mode() == HDR_DOLBY_HDMI)|| (get_HDMI_HDR_mode() == HDR_HDR10_HDMI)? 0: 1);
#endif
	config_data->quincunx_en = 0;
	config_data->videoPlane = VO_VIDEO_PLANE_V1;
	config_data->i2rnd_sub_src = _DISABLE;

#ifdef CONFIG_I2RND_ENABLE
	if(Scaler_I2rnd_get_enable() == _ENABLE)
		config_data->i2rnd_display_table = I2RND_MAIN_S0_TABLE;
	else
#endif
		config_data->i2rnd_display_table = I2RND_TABLE_MAX;

	config_data->htotal = timing->h_total;
	config_data->vtotal = timing->v_total;


#ifdef CONFIG_SCALER_BRING_UP
	printk("width = %d\n", config_data->width);
	printk("height = %d\n", config_data->height);
	printk("progressive = %d\n", config_data->progressive);
	printk("framerate = %d\n", config_data->framerate);
	printk("framerate_ori = %d\n", config_data->framerate_ori);
	printk("chroma_fmt = %d\n", config_data->chroma_fmt);
	printk("data_bit_width = %d\n", config_data->data_bit_width);
	printk("hw_auto_mode = %d\n", config_data->hw_auto_mode);
	printk("l1_sta_adr = %x\n", config_data->l1_st_adr);
	printk("r1_sta_adr = %x\n", config_data->r1_st_adr);
	printk("l2_sta_adr = %x\n", config_data->l2_st_adr);
	printk("r2_sta_adr = %x\n", config_data->r2_st_adr);
	printk("quincunx_en = %d\n", config_data->quincunx_en);
	printk("quincunx_mode_fw = %d\n", config_data->quincunx_mode_fw);
	printk("sensio3D_en = %d\n", config_data->sensio3D_en);
	printk("sg3d_dataFrc = %d\n", config_data->sg3d_dataFrc);
	printk("i2rnd_sub_src = %d\n", config_data->i2rnd_sub_src);
	printk("i2rnd_display_table = %d\n", config_data->i2rnd_display_table);
	printk("htotal = %d\n", config_data->htotal);
	printk("vtotal = %d\n", config_data->vtotal);
	printk("hw_auto_mode = %d\n", config_data->hw_auto_mode);
	//VODMA_ConfigHDMI(config_data);
#else
	config_data->width = htonl(config_data->width);
	config_data->height = htonl(config_data->height);
	config_data->chroma_fmt = htonl(config_data->chroma_fmt);
	config_data->data_bit_width = htonl(config_data->data_bit_width);
	config_data->framerate =  htonl(config_data->framerate);
	config_data->framerate_ori =  htonl(config_data->framerate_ori);
	config_data->progressive = htonl(config_data->progressive);
	config_data->l1_st_adr = htonl(config_data->l1_st_adr);
	config_data->r1_st_adr = htonl(config_data->r1_st_adr);
	config_data->l2_st_adr = htonl(config_data->l2_st_adr);
	config_data->r2_st_adr = htonl(config_data->r2_st_adr);
	config_data->l3_st_adr = htonl(config_data->l3_st_adr);//input fast use 3-buffer @Crixus 20170508
	config_data->r3_st_adr = htonl(config_data->r3_st_adr);
	config_data->hw_auto_mode = htonl(config_data->hw_auto_mode);
	config_data->quincunx_en = htonl(config_data->quincunx_en);
	config_data->videoPlane = htonl(config_data->videoPlane);
	config_data->i2rnd_sub_src = htonl(config_data->i2rnd_sub_src);
	config_data->i2rnd_display_table = htonl(config_data->i2rnd_display_table);
	config_data->htotal = htonl(config_data->htotal);
	config_data->vtotal = htonl(config_data->vtotal);

#ifdef CONFIG_RTK_KDRV_RPC
	if (RPC_FAIL==send_rpc_command(RPC_VIDEO, VIDEO_RPC_VOUT_ToAgent_ConfigHDMI_3D,phy_addr, 0, &result))
	{
		pr_debug(KERN_INFO "RPC fail!!\n");
		dvr_free((void *)vir_addr);
		return FALSE;
	}
#endif
#endif

	dvr_free((void *)vir_addr);
#endif
	return TRUE;

}

I3DDMA_CAPTURE_BUFFER_T idma_cap_buf[3];
//#define DISP2TVE_IDMA_CAPSIZE  1920 * 1080 * 3// per byte => 3*8 = 24bits
#define SCART_OUT_TVE_IDMA_CAPSIZE  720 * 576 * 2// per byte => 2*8 = 16bits

unsigned char I3DDMA_disp2tve_CapBufInit() {

	unsigned int size = SCART_OUT_TVE_IDMA_CAPSIZE;

#ifdef I3DDMA_DYNAMIC_MEMORY_ALLOCATE_ENABLE
		// allocate IDMA capture buffer before enable IDMA
		pr_debug("[IDMA] Dynamic memory alloc!!\n");
		return 0;
#endif

		if(idma_cap_buf[0].phyaddr == 0)
		{
				/*Use pli memory allocation @Crixus 20150801*/
				idma_cap_buf[0].phyaddr=pli_malloc((size*4 + 512), GFP_DCU2_FIRST);

				if (idma_cap_buf[0].phyaddr == INVALID_VAL) {
					pr_debug("malloc idma buffer fail .......................................\n");
					return 1;
				}
				idma_cap_buf[0].size = size;

				pr_debug("[idma-cap-buf] buf[0] phy=%x(%d KB)\n", (UINT32)idma_cap_buf[0].phyaddr, idma_cap_buf[0].size >> 10);

				idma_cap_buf[1].phyaddr = idma_cap_buf[0].phyaddr+ idma_cap_buf[0].size;
				idma_cap_buf[1].size = size;
				pr_debug("[idma-cap-buf] buf[1] phy=%x(%d KB)\n", (UINT32)idma_cap_buf[1].phyaddr, idma_cap_buf[1].size >> 10);

				idma_cap_buf[2].phyaddr = idma_cap_buf[1].phyaddr+ idma_cap_buf[1].size;
				idma_cap_buf[2].size = size;
				pr_debug("[idma-cap-buf] buf[2] phy=%x(%d KB)\n", (UINT32)idma_cap_buf[2].phyaddr, idma_cap_buf[2].size >> 10);

				idma_cap_buf[3].phyaddr = idma_cap_buf[2].phyaddr+ idma_cap_buf[2].size;
				idma_cap_buf[3].size = size;
				pr_debug("[idma-cap-buf] buf[3] phy=%x(%d KB)\n", (UINT32)idma_cap_buf[3].phyaddr, idma_cap_buf[3].size >> 10);

				rtd_outl(H3DDMA_Cap_BoundaryAddr2_reg, idma_cap_buf[0].phyaddr );
				rtd_outl(H3DDMA_Cap_BoundaryAddr1_reg, idma_cap_buf[3].phyaddr + idma_cap_buf[3].size);

		}
	return 0;
}

//add to disconnect api
void I3DDMA_disp2tve_CapBufDeInit(void) {
	if (idma_cap_buf[0].phyaddr) {
		/*Use pli memory allocation @Crixus 20150801*/
		pli_free(idma_cap_buf[0].phyaddr);
		idma_cap_buf[0].phyaddr = 0;

		pr_debug("[idma-cap-buf] idma cap buffer is not empty!!free the buffer!\n");
	}

	pr_debug("[idma-cap-buf] Deinit done!\n");
}


#ifdef CONFIG_HDR_SDR_SEAMLESS
I3DDMA_COLOR_SPACE_T decide_i3ddma_output_foramt(I3DDMA_TIMING_T *timing)
{
	// In Vertical strip & Checker board 3D, I3DDMA only support YUV444 capture
	if((timing->i3ddma_3dformat == I3DDMA_VERTICAL_STRIPE)|| (timing->i3ddma_3dformat == I3DDMA_CHECKER_BOARD))
	{
		return I3DDMA_COLOR_YUV444;
	} // [Dolby Vision] IDMA capture in RGB format
	else if((get_HDMI_HDR_mode() == HDR_DOLBY_HDMI) && (timing->color == I3DDMA_COLOR_RGB)){
		return I3DDMA_COLOR_RGB;
	}
	else if((get_HDMI_HDR_mode() == HDR_HDR10_HDMI) /*&& (i3ddma_timing.color != I3DDMA_COLOR_RGB)*/){
		return I3DDMA_COLOR_YUV422;
	}else if(timing->color == I3DDMA_COLOR_RGB) {
		return I3DDMA_COLOR_YUV444;
	}else {
        // [WOSQRTK-10007][BW] Force enable HDMI 444(420) to 422!!
        if((timing->h_act_len >= 3800) && (timing->v_freq > 480)
            && (timing->color == I3DDMA_COLOR_YUV444) && (timing->depth > 0))
        {
        	return I3DDMA_COLOR_YUV422;
        }else {
			return timing->color;
    	}
	}
}

void I3ddma_format_changed_seamless(I3DDMA_TIMING_T *timing, I3DDMA_COLOR_SPACE_T target)
{
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg;
	h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS i3ddma_vsd_ctrl0_reg;
	/*i3ddma capture setting*/
	int size, rem, len, num;
	unsigned int h_act_len;
	h3ddma_i3ddma_enable_RBUS  i3ddma_i3ddma_enable_reg;
	h3ddma_cap_ctl0_RBUS  i3ddma_cap_ctl0_reg;
	h3ddma_cap_ctl1_RBUS i3ddma_cap_ctl1_reg;
	I3DDMA_COLOR_SPACE_T source = timing->color;

	/*i3ddma 422 444 setting*/
	i3ddma_vsd_ctrl0_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
	if(source == I3DDMA_COLOR_YUV422)
		i3ddma_vsd_ctrl0_reg.sort_fmt = 1; //yuv422 bypass (1)
	else if(source == I3DDMA_COLOR_RGB) {
		if(target == I3DDMA_COLOR_YUV422)
	 		i3ddma_vsd_ctrl0_reg.sort_fmt = 0; //444 to 422
	 	else
			i3ddma_vsd_ctrl0_reg.sort_fmt = 1;//keep 444
	} else {//input 444
		if(target == I3DDMA_COLOR_YUV422)
			i3ddma_vsd_ctrl0_reg.sort_fmt = 0; //444 to 422
		else
			i3ddma_vsd_ctrl0_reg.sort_fmt = 1;//keep 444
	}
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg, i3ddma_vsd_ctrl0_reg.regValue);

	/*i3ddma rgb2yuv setting*/
	if (source == I3DDMA_COLOR_RGB) {
		if(DMA_VGIP_DMA_VGIP_CTRL_get_dma_in_sel(rtd_inl(DMA_VGIP_DMA_VGIP_CTRL_reg)) == VGIP_SRC_ATV) {
			/*av source, idma bypass rgb2yuv*/
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
			rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
		}
		else if(target != I3DDMA_COLOR_RGB) {
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 1;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.sel_rgb = 1;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.set_uv_out_offset = 1;
			rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
		} else {
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.sel_rgb = 0;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.set_uv_out_offset = 0;
			rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
		}
	} else {
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.sel_rgb = 0;
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.set_uv_out_offset = 0;
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
	}

	/*i3ddma capture setting*/
	h_act_len  = (DEPTH2BITS[timing->depth] * (timing->h_act_len /4) * components[timing->color] + 127) / 128;
	rem = 12;
	len = 32;
	num = (h_act_len - rem) / len;
	rem = (h_act_len - rem) % len + rem;

	i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
	i3ddma_i3ddma_enable_reg.cap_en = 0;
	rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);

	i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
	i3ddma_cap_ctl0_reg.pixel_encoding = encodemap[timing->color];
	rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

	i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
	i3ddma_cap_ctl0_reg.cap_write_len = len;
	i3ddma_cap_ctl0_reg.cap_write_rem = rem;
	rtd_outl(H3DDMA_Cap_CTL0_reg, i3ddma_cap_ctl0_reg.regValue);

	i3ddma_cap_ctl1_reg.regValue = rtd_inl(H3DDMA_Cap_CTL1_reg);
	i3ddma_cap_ctl1_reg.cap_water_lv = len;
	i3ddma_cap_ctl1_reg.cap_write_num = num;
	rtd_outl(H3DDMA_Cap_CTL1_reg, i3ddma_cap_ctl1_reg.regValue);

	i3ddma_i3ddma_enable_reg.regValue = rtd_inl(H3DDMA_I3DDMA_enable_reg);
	i3ddma_i3ddma_enable_reg.cap_en = 1;
	rtd_outl(H3DDMA_I3DDMA_enable_reg, i3ddma_i3ddma_enable_reg.regValue);
	return;
}
#endif

#ifdef CONFIG_SCALER_BRING_UP
typedef struct
{
	unsigned int HTotal;		// h_threshold
	unsigned int VTotal;		// v_threshold
	unsigned int HWidth;		// h_active
	unsigned int VHeight;		// v_active
	unsigned int HStartPos;		// h_active_start
	unsigned int VStartPos;		// v_active_start
	unsigned int isProg;		// progressive or interlace
	unsigned int SampleRate;	// sample rate in 100Hz
	unsigned int FrameRate;	//Frame Rate, //vfreq unit 0.001Hz

} VO_TIMING ;


typedef enum _DOLBY_HDMI_MODE {
     DOLBY_HDMI_OFF		= 0x0,
     DOLBY_HDMI_IDMA_INIT	= 0x1,
     DOLBY_HDMI_CAPTURE	= 0x2,
     DOLBY_HDMI_VO_RUN		= 0x3
} DOLBY_HDMI_MODE;

//VO_DMEM *VO_Dmem=NULL;
//VO_DATA *vo=NULL;
VODMA_HDMI_AUTO_MODE hdmi_autoMode=0;
static unsigned int vsyncgen_pixel_freq=0;



#define VO_MAIN_DCU_INDEX_Y     0
#define VO_MAIN_DCU_INDEX_C1    1
#define VO_MAIN_DCU_INDEX_C2    2
#define VO_MAIN_SEQ_ADDR        ((unsigned int)(0x08200000))
#define PCR_PLL			27000000
#define APLL			108000000

extern VODMA_MODE Mode_Decision(unsigned int width, unsigned int height, bool isProg);
extern HDR_MODE HDR_DolbyVision_Get_CurDolbyMode(void);
extern DOLBY_HDMI_MODE HDR_DolbyVision_Get_CurHdmiMode(void);
extern void Scaler_I2rnd_set_display(unsigned char display);

void dma_set_v1(VO_VIDEO_PLANE plane, VO_TIMING *tmode,VIDEO_RPC_VOUT_CONFIG_HDMI_3D *HDMI_INFO , VODMA_DMA_MODE dma_mode, VODMA_DDOMAIN_CHROMA Ddomain_Chroma)
{
	vodma_vodma_v1_dcfg_RBUS		DMA_v1_dcfg;		//0xb800_5000
	vodma_vodma_v1_dsize_RBUS		DMA_v1_dsize;		//0xb800_5004
	vodma_vodma_vd1_ads_RBUS		DMA_v1_YC;			//0xb800_5008
	vodma_vodma_v1_seq_RBUS		DMA_v1_staddr;		//0xb800_500c
	vodma_vodma_v1_blk1_RBUS		DMA_v1_hoffset;		//0xb800_5010
	vodma_vodma_v1_blk2_RBUS		DMA_v1_voffset;		//0xb800_5014
	vodma_vodma_v1_blk3_RBUS		DMA_v1_voffset2;	//0xb800_5018
	vodma_vodma_v1_blk4_RBUS		DMA_v1_hoffset2;		//0xb800_5010
	vodma_vodma_v1_blk5_RBUS		DMA_v1_hoffset3;		//0xb800_5010
	vodma_vodma_v1_seq_3d_l1_RBUS DMA_v1_seq_3d_l1;	//0xb800_501c
	vodma_vodma_v1_seq_3d_r1_RBUS DMA_v1_seq_3d_r1;	//0xb800_5020
	vodma_vodma_v1_seq_3d_l2_RBUS DMA_v1_seq_3d_l2;	//0xb800_5024
	vodma_vodma_v1_seq_3d_r2_RBUS DMA_v1_seq_3d_r2;	//0xb800_5028
	vodma_vodma_v1_seq_3d_l3_RBUS DMA_v1_seq_3d_l3;	//0xb800_51c0
	vodma_vodma_v1_seq_3d_r3_RBUS DMA_v1_seq_3d_r3;	//0xb800_51c4
	vodma_vodma_v1_seq_3d_l4_RBUS DMA_v1_seq_3d_l4;	//0xb800_51c8
	vodma_vodma_v1_seq_3d_r4_RBUS DMA_v1_seq_3d_r4;	//0xb800_51cc
	vodma_vodma_v1_v_flip_RBUS	DMA_v1_seq_v_flip;	//0xb800_502c
	vodma_vodma_v1chroma_fmt_RBUS	V1_C_up_fmt;		//0xb800_5030
	vodma_vodma_v1_cu_RBUS		V1_C_up_mode420;	//0xb800_5034
	vodma_vodma_v1422_to_444_RBUS	V1_C_up_mode422;	//0xb800_5038
	vodma_vodma_line_select_RBUS	line_sel;			//0xb800_5040
	vodma_vodma_quincunx_setting_RBUS	quincunx_setting;	//0xb800_50e0

	DMA_v1_dcfg.merge_forward = 0;
	DMA_v1_dcfg.merge_backward = 0;
	DMA_v1_dcfg.pd_switch = 0;
	DMA_v1_dcfg.pd_seq = 0;
	DMA_v1_dcfg.film_condition = 0;

	DMA_v1_dcfg.field_mode = 0;
	DMA_v1_dcfg.field_fw = 0;
	DMA_v1_dcfg.l_flag_fw = 0;
	DMA_v1_dcfg.force_2d_en = 0;
	DMA_v1_dcfg.force_2d_sel = 0;
	DMA_v1_dcfg.dma_auto_mode = 1;

	DMA_v1_dcfg.seq_data_pack_type = 0; //1:field based, 0:line based
	DMA_v1_dcfg.seq_data_width = (HDMI_INFO->data_bit_width == 8)? 0: 1 ; // 8bits, 10bits;

	DMA_v1_dcfg.double_chroma = 0;
	DMA_v1_dcfg.uv_off =  0;
	DMA_v1_dcfg.pxl_swap_sel = 0;
	DMA_v1_dcfg.keep_go_en = 0;
	DMA_v1_dcfg.dma_state_reset_en = 1;
	DMA_v1_dcfg.v_flip_en = 0;
	DMA_v1_dcfg.chroma_swap_en = 0;
	DMA_v1_dcfg.double_pixel_mode = 0;

	DMA_v1_dcfg.dma_mode = dma_mode;		//0:seq 1:blk
	DMA_v1_dcfg.vodma_go = 1;


	DMA_v1_dsize.p_y_len = tmode->HWidth;	//width
	DMA_v1_dsize.p_y_nline = tmode->VHeight; //height

	if (dma_mode == DMA_BLOCK_MODE) {
		DMA_v1_YC.p_v_ads = VO_MAIN_DCU_INDEX_C2;
		DMA_v1_YC.p_u_ads = VO_MAIN_DCU_INDEX_C1;
		DMA_v1_YC.p_y_ads = VO_MAIN_DCU_INDEX_Y;

		DMA_v1_hoffset3.v_h_offset = 0;
		DMA_v1_hoffset3.u_h_offset = 0;
		DMA_v1_hoffset.y_ha_shift = 0;
		DMA_v1_hoffset2.y_h_offset = 0;

		DMA_v1_voffset.p_y_offset = 0;
		DMA_v1_voffset.p_u_offset = 0;

		DMA_v1_voffset2.p_v_offset = 0;
	}
	else {

#if 0
		vodma->V1_seq_3D_L1.st_adr = (HDMI_INFO->r2_st_adr & 0x7FFFFFF0) >> 3;
		vodma->V1_seq_3D_R1.st_adr = (HDMI_INFO->l1_st_adr & 0x7FFFFFF0) >> 3;
		vodma->V1_seq_3D_L2.st_adr = (HDMI_INFO->r1_st_adr & 0x7FFFFFF0) >> 3;
		vodma->V1_seq_3D_R2.st_adr = (HDMI_INFO->l2_st_adr & 0x7FFFFFF0) >> 3;
#endif
//		DMA_v1_staddr.st_adr = (HDMI_INFO->r2_st_adr & 0x7FFFFFF0) >> 3;

		DMA_v1_seq_3d_l1.st_adr = (HDMI_INFO->l1_st_adr & 0x7FFFFFF0) >> 3;
		DMA_v1_seq_3d_r1.st_adr = (HDMI_INFO->r1_st_adr & 0x7FFFFFF0) >> 3;
		DMA_v1_seq_3d_l2.st_adr = (HDMI_INFO->l2_st_adr & 0x7FFFFFF0) >> 3;
		DMA_v1_seq_3d_r2.st_adr = (HDMI_INFO->r2_st_adr & 0x7FFFFFF0) >> 3;
//		DMA_v1_seq_3d_l3.st_adr = (VO_MAIN_SEQ_ADDR) >> 3;
//		DMA_v1_seq_3d_r3.st_adr = (VO_MAIN_SEQ_ADDR) >> 3;
//		DMA_v1_seq_3d_l4.st_adr = (VO_MAIN_SEQ_ADDR) >> 3;
//		DMA_v1_seq_3d_r4.st_adr = (VO_MAIN_SEQ_ADDR) >> 3;

		DMA_v1_hoffset3.v_h_offset = 0;
		DMA_v1_hoffset3.u_h_offset = 0;
		DMA_v1_hoffset.y_ha_shift = 0;
		DMA_v1_hoffset2.y_h_offset = 0;

		DMA_v1_voffset.p_y_offset = 0;
		DMA_v1_voffset.p_u_offset = 0;

		DMA_v1_voffset2.p_v_offset = 0;

		DMA_v1_seq_v_flip.line_step = 0 ;
		//DMA_v1_seq_v_flip.line_step = ( (tmode->VHeight * (Ddomain_Chroma_fmt == DDOMAIN_FMT_422?2:3) * (DMA_v1_dcfg.seq_data_width?10:8)) + 127)/128;
	}

	/*
	 * chroma upsampling
	 * 0: YUV 420->422 (blk only)
	 * 1: YUV 420->444 (blk only)
	 * 2: YUV 422->444 (seq or blk)
	 * 3: YUV 422 bypass (seq or blk)
	 * 4: YUV 444 bypass (seq only)
	 * 5: ARGB8888 444 bypass (seq only)
	 * 6: RGB888 444 bypass (seq only)
	 * 7: RGB565 444 bypass (seq only)
	 * 8: YUV 444 bypass (blk only)
	 * 9: YUV 422v->444 (blk only)
	 */
	V1_C_up_fmt.g_position = 0;
	V1_C_up_fmt.seq_color_swap = (HDMI_INFO->chroma_fmt==CHROMA_YUV422)? 2: (HDMI_INFO->chroma_fmt==CHROMA_YUV444)? 3: 5; //YUV422: 2 // YUV444: 3 //ARGB8888,RGB888,RGB565: 5
	V1_C_up_fmt.alpha_position = 0;
	if (dma_mode == DMA_SEQUENTIAL_MODE) {
		if (Ddomain_Chroma == DDOMAIN_FMT_422) // ddomain 422
		{
			if (HDMI_INFO->chroma_fmt == CHROMA_YUV411)
				V1_C_up_fmt.encfmt = 6;	//411->422
			else
				V1_C_up_fmt.encfmt = 3;	//422 bypass
		}
		else // ddomain 444
		{
			if (HDMI_INFO->chroma_fmt == CHROMA_YUV444 || HDMI_INFO->chroma_fmt == CHROMA_RGB888)
				V1_C_up_fmt.encfmt = 4;	//444 bypass
			else if (HDMI_INFO->chroma_fmt == CHROMA_ARGB8888)
				V1_C_up_fmt.encfmt = 5;	//ARGB8888 444 bypass
			else if (HDMI_INFO->chroma_fmt == CHROMA_YUV411)
				V1_C_up_fmt.encfmt = 0xa;	//YUV411 444 bypass
			else if (HDMI_INFO->chroma_fmt == CHROMA_RGB565)
				V1_C_up_fmt.encfmt = 7;	//RGB565 444 bypass
			else
				V1_C_up_fmt.encfmt = 2; //422->444
		}
	}
	else {
		if (Ddomain_Chroma == DDOMAIN_FMT_422) // ddomain 422
		{
			if (HDMI_INFO->chroma_fmt== CHROMA_YUV422)
				V1_C_up_fmt.encfmt = 3;	//422 bypass
			else
				V1_C_up_fmt.encfmt = 0;	//420->422
		}
		else // ddomain 444
		{
			V1_C_up_fmt.encfmt = 1; //420->444
		}
	}
	V1_C_up_fmt.encfmt = 4;


	V1_C_up_mode420.mode = 0;


	V1_C_up_mode422.fir422_sel = 0;


	//even or odd line selection
	line_sel.y1_line_select = !tmode->isProg;
	line_sel.c1_line_select = !tmode->isProg;

	quincunx_setting.hori_drop_mode = 0 ;
	quincunx_setting.hori_drop_en = 0 ;
	quincunx_setting.quincunx_mode_src_sel = HDMI_INFO->hw_auto_mode;
	quincunx_setting.quincunx_int_mode = HDMI_INFO->quincunx_en ;
	quincunx_setting.quincunx_int_en = 0 ;
	quincunx_setting.quincunx_mode_fw = HDMI_INFO->quincunx_mode_fw ;

	if (plane == VO_VIDEO_PLANE_V1)
	{
		rtd_outl(VODMA_VODMA_V1_DCFG_reg, DMA_v1_dcfg.regValue);
		rtd_outl(VODMA_VODMA_V1_DSIZE_reg, DMA_v1_dsize.regValue);
		rtd_outl(VODMA_VODMA_VD1_ADS_reg, DMA_v1_YC.regValue);
		rtd_outl(VODMA_VODMA_V1_BLK1_reg, DMA_v1_hoffset.regValue);
		rtd_outl(VODMA_VODMA_V1_BLK2_reg, DMA_v1_voffset.regValue);
		rtd_outl(VODMA_VODMA_V1_BLK3_reg, DMA_v1_voffset2.regValue);
        rtd_outl(VODMA_VODMA_V1_BLK4_reg, DMA_v1_hoffset2.regValue);
        rtd_outl(VODMA_VODMA_V1_BLK5_reg, DMA_v1_hoffset3.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_reg, DMA_v1_staddr.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_L1_reg, DMA_v1_seq_3d_l1.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_R1_reg, DMA_v1_seq_3d_r1.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_L2_reg, DMA_v1_seq_3d_l2.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_R2_reg, DMA_v1_seq_3d_r2.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_L3_reg, DMA_v1_seq_3d_l1.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_R3_reg, DMA_v1_seq_3d_r1.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_L4_reg, DMA_v1_seq_3d_l2.regValue);
		rtd_outl(VODMA_VODMA_V1_SEQ_3D_R4_reg, DMA_v1_seq_3d_r2.regValue);
		rtd_outl(VODMA_VODMA_V1_V_FLIP_reg, DMA_v1_seq_v_flip.regValue);
		rtd_outl(VODMA_VODMA_V1CHROMA_FMT_reg, V1_C_up_fmt.regValue);
		rtd_outl(VODMA_VODMA_V1_CU_reg, V1_C_up_mode420.regValue);
		rtd_outl(VODMA_VODMA_V1422_TO_444_reg, V1_C_up_mode422.regValue);
		rtd_outl(VODMA_VODMA_LINE_SELECT_reg, line_sel.regValue);
		rtd_outl(VODMA_VODMA_quincunx_setting_reg, quincunx_setting.regValue);
	}

}

void timinggen_set_v1(VO_VIDEO_PLANE plane, VO_TIMING *tmode)
{
	vodma_vodma_v1sgen_RBUS 			V1_syncGen ;
	vodma_vodma_v1int_RBUS 			V1_syncGen_mode ;
	vodma_vodma_v1vgip_ivs1_RBUS		V1_vgipPos_topIVS ;
	vodma_vodma_v1vgip_ivs2_RBUS 		V1_vgipPos_botIVS ;
	vodma_vodma_v1vgip_ihs_RBUS 		V1_vgipPos_IHS ;
	vodma_vodma_v1vgip_fd_RBUS		V1_vgipPos_topFld ;
	vodma_vodma_v1vgip_fd2_RBUS 		V1_vgipPos_botFld ;
	vodma_vodma_v1vgip_hact_RBUS		V1_vgipPos_HACT ;
	vodma_vodma_v1vgip_vact1_RBUS		V1_vgipPos_topVACT ;
	vodma_vodma_v1vgip_vact2_RBUS		V1_vgipPos_botVACT ;
	vodma_vodma_v1vgip_hbg_RBUS		V1_vgipPos_HBG ;
	vodma_vodma_v1vgip_vbg1_RBUS		V1_vgipPos_topVBG ;
	vodma_vodma_v1vgip_vbg2_RBUS		V1_vgipPos_botVBG ;
	vodma_vodma_v1vgip_bg_clr_RBUS	V1_vgipPos_BGCLR ;
 	vodma_vodma_v1vgip_intpos_RBUS	V1_vgipPos_intrpt ;

	unsigned int HTotal,VTotal, HActStart, HActEnd, VActStart, VActEnd;

	HTotal		= tmode->HTotal;
	VTotal		= tmode->VTotal;
	HActStart	= tmode->HStartPos;
	HActEnd		= tmode->HStartPos + tmode->HWidth;
	VActStart	= tmode->VStartPos;
	VActEnd		= tmode->VStartPos + tmode->VHeight;

	V1_syncGen.vthr_rst1 = 0;
	V1_syncGen.v_thr = 0xfff; //VTotal;
	V1_syncGen.h_thr = HTotal;

	V1_syncGen_mode.vgip_en = 1;
	V1_syncGen_mode.interlace = !tmode->isProg;
	V1_syncGen_mode.top_fld_indc = 0;
	V1_syncGen_mode.v_thr = 0xfff;

	V1_vgipPos_topIVS.v_end = 6;
	V1_vgipPos_topIVS.v_st = 4;

	V1_vgipPos_botIVS.v_end = 6;
	V1_vgipPos_botIVS.v_st = 4;

	V1_vgipPos_IHS.h_st = 0;

	//should cover active window
	V1_vgipPos_topFld.v_end = 0xfff;
	V1_vgipPos_topFld.v_st = 0xfff;

	//should cover active window
	V1_vgipPos_botFld.v_end = 0xfff;
	V1_vgipPos_botFld.v_st = 4;

	V1_vgipPos_HACT.h_end = HActEnd;
	V1_vgipPos_HACT.h_st = HActStart;

	/* v active move -20 */
	V1_vgipPos_topVACT.v_end = VActEnd;
	V1_vgipPos_topVACT.v_st = VActStart;

	/* v active move -20 */
	/* no matter progressive or interlace, the below reg must be assigned */
	V1_vgipPos_botVACT.v_end = V1_vgipPos_topVACT.v_end;
	V1_vgipPos_botVACT.v_st = V1_vgipPos_topVACT.v_st;

	V1_vgipPos_HBG.h_end = HActEnd;
	V1_vgipPos_HBG.h_st = HActStart;

	V1_vgipPos_topVBG.v_end = VActEnd;
	V1_vgipPos_topVBG.v_st = VActStart;

	V1_vgipPos_botVBG.v_end = VActEnd;
	V1_vgipPos_botVBG.v_st = VActStart;

//	V1_vgipPos_BGCLR.bg_y = 0;
//	V1_vgipPos_BGCLR.bg_u = 0;
//	V1_vgipPos_BGCLR.bg_v = 0;

	V1_vgipPos_intrpt.v2 = 8;
	V1_vgipPos_intrpt.v1 = 8;

	if (plane == VO_VIDEO_PLANE_V1)
	{
		rtd_outl(VODMA_VODMA_V1SGEN_reg, V1_syncGen.regValue);
		rtd_outl(VODMA_VODMA_V1INT_reg, V1_syncGen_mode.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_IVS1_reg, V1_vgipPos_topIVS.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_IVS2_reg, V1_vgipPos_botIVS.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_IHS_reg, V1_vgipPos_IHS.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_FD_reg, V1_vgipPos_topFld.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_FD2_reg, V1_vgipPos_botFld.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_HACT_reg, V1_vgipPos_HACT.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_VACT1_reg, V1_vgipPos_topVACT.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_VACT2_reg, V1_vgipPos_botVACT.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_HBG_reg, V1_vgipPos_HBG.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_VBG1_reg, V1_vgipPos_topVBG.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_VBG2_reg, V1_vgipPos_botVBG.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_BG_CLR_reg, V1_vgipPos_BGCLR.regValue);
		rtd_outl(VODMA_VODMA_V1VGIP_INTPOS_reg, V1_vgipPos_intrpt.regValue);
	}
}

void vsyncgen_set_v1(VO_VIDEO_PLANE plane, VO_TIMING *tmode)
{
	vodma_vodma_clkgen_RBUS	clkgen;
	vodma_vodma_pvs_free_RBUS		pvs_free;
	vodma_vodma_pvs_ctrl_RBUS		pvs_ctrl;
	vodma_vodma_pvs0_gen_RBUS		pvs0;
	vodma_vodma_pvs_width_ctrl_RBUS pvs_width_ctrl;

	unsigned int vodmapll, vodmapll0, freerun_clk;
	unsigned int nMCode, nNCode, nOCode, regValue, busclk = 0;

	IV_SRC timgen_src = IV_SRC_SEL_PIXELCLOCK; //PLLDDS, MAINIVS, MAINDVS, PIXELCLOCK
	VODMA_CLK_SRC vodma_clk_src = VODMA_CLK_SEL_PLLBUS_2;
	PVS0_FREE_CLK_SRC free_clk_src = PVS0_FREE_CLK_SEL_PCRACLK; //PVS0_FREE_CLK_SEL_PCRCLK, PVS0_FREE_CLK_SEL_PIXELCLK

	//set pcr pll
#if 0
	sys_pll_2_bus1_RBUS PLL_2_BUS1_REG;
	PLL_2_BUS1_REG.regValue = vo_rtd_inl(SYSTEM_SYS_PLL_2_BUS1_reg);
	PLL_2_BUS1_REG.pllbus_m_h = 14;
	PLL_2_BUS1_REG.pllbus_n_h = 0;
	vo_rtd_outl(SYSTEM_SYS_PLL_2_BUS1_reg, PLL_2_BUS1_REG.regValue);
	sys_pll_2_bus3_RBUS	PLL_2_BUS3_REG;
	PLL_2_BUS3_REG.regValue = vo_rtd_inl(SYSTEM_SYS_PLL_3_BUS1_reg);
	PLL_2_BUS3_REG.pcr_psaud_rstb = 1;
	PLL_2_BUS3_REG.plldds_pwdn = 0;
	PLL_2_BUS3_REG.plldds_rstb = 1;
	PLL_2_BUS3_REG.plldds_oeb = 0;
	PLL_2_BUS3_REG.plldds_ddsen = 1;
	vo_rtd_outl(SYSTEM_SYS_PLL_3_BUS1_reg, PLL_2_BUS3_REG.regValue);
#endif

	/* vodma clk gen */
	clkgen.vodma_enclk = 1;
	clkgen.vodma_clk_sel = vodma_clk_src;
	clkgen.vodma_clk_div2_en = !tmode->isProg;
	clkgen.vodma_clk_div_n = 0;
	clkgen.vodma_clk_ratio_n_off = 0;

	switch(clkgen.vodma_clk_sel) {
	case VODMA_CLK_SEL_ADCCLK:
		vodmapll = APLL;
		break;
	case VODMA_CLK_SEL_HDMICLK:
	case VODMA_CLK_SEL_PLLBUS_2:
	default:
#if 1
		regValue = rtd_inl(0xB8000460);
		nMCode = ((regValue & 0x000ff000)>>12);
		nNCode = ((regValue & 0x00300000)>>20);
		nOCode = ((regValue & 0x00000180)>>7);

		busclk = 27000000*(nMCode+2)/(nNCode+1)/(nOCode+1);

		//ROSPrintfInternal("PLL_VODMA m: %d, n: %d, o: %d, clk: %d\n", nMCode, nNCode, nOCode, busclk);

		vodmapll = busclk ;
#endif
		break;
	}
	vodmapll0 = vodmapll ;

#if 1
	int div_n = 0;
	if((vodmapll/2)>(tmode->SampleRate*10000)){
		div_n = (vodmapll/(tmode->SampleRate*10000))-1;
		vodmapll = vodmapll / (div_n + 1);
		clkgen.vodma_clk_div_n = div_n;
		//ROSPrintfInternal("div_n: %d, clk: %d\n", clkgen.vodma_clk_div_n, vodmapll);
	}
#endif

#if 1
	int ratio_n_off = 0;
	if ((vodmapll/32*31)>(tmode->SampleRate*10000)) {
		ratio_n_off = 32 - (tmode->SampleRate*32/(vodmapll/10000)) - 1;
		vodmapll = (vodmapll/32) * (32 - ratio_n_off);
		clkgen.vodma_clk_ratio_n_off = ratio_n_off ;
		//ROSPrintfInternal("ratio_n_off: %d, clk: %d\n", clkgen.vodma_clk_ratio_n_off, vodmapll);
	}
#endif

	if (clkgen.vodma_clk_div2_en)
	{
		vodmapll = vodmapll / 2;
		//ROSPrintfInternal("div2: %d, clk: %d\n", clkgen.vodma_clk_div2_en, vodmapll);
	}

	clkgen.gating_src_sel = 0;
	clkgen.en_fifo_full_gate = 0;
	clkgen.en_fifo_empty_gate = 0 ;


	/* pvs freerun */
	pvs_free.pvs0_free_en = 1;		//0: disable(clk from vodma), 1:enable(clk from PCK_CLK)
	pvs_free.pvs0_free_vs_reset_en = 0;
	pvs_free.pvs0_free_period_update = 1;
  	pvs_ctrl.pvs0_free_clk_sel = free_clk_src;
	switch(pvs_ctrl.pvs0_free_clk_sel) {
	case PVS0_FREE_CLK_SEL_PIXELCLK:
		freerun_clk = vodmapll;
		break;
	case PVS0_FREE_CLK_SEL_PCRACLK:
	case PVS0_FREE_CLK_SEL_PCRBCLK:
	case PVS0_FREE_CLK_SEL_CRYSTALCLK:
	default:
		freerun_clk = PCR_PLL ;
		break;
	}
	vsyncgen_pixel_freq=vodmapll;
	pvs_free.pvs0_free_period = (freerun_clk / ((int)tmode->FrameRate) ) * 1000;  //vfreq unit 0.001Hz


	pvs_width_ctrl.pvs0_vs_width = pvs_free.pvs0_free_period / tmode->VTotal ;


	pvs_ctrl.pvs0_free_l_flag_en = 0 ;
	pvs_ctrl.pvs0_free_vs_inv_en = 0 ;
	pvs_ctrl.pvs0_free_vs_sel = 0 ;
	pvs_ctrl.mask_one_vs = 0 ;
	pvs_ctrl.dummy18005308_29_11 = 0x40000;

	/* pvs0 gen */
	pvs0.en_pvgen = 1;
	pvs0.en_pfgen = 1;
	pvs0.pfgen_inv = 0;
	pvs0.iv_inv_en = 0;
	pvs0.iv_src_sel = timgen_src;
	pvs0.iv2pv_dly = 2;

	if (plane == VO_VIDEO_PLANE_V1)
	{
		rtd_outl(VODMA_VODMA_CLKGEN_reg, clkgen.regValue);
		rtd_outl(VODMA_VODMA_PVS_Free_reg, pvs_free.regValue);
		rtd_outl(VODMA_VODMA_PVS_WIDTH_CTRL_reg, pvs_width_ctrl.regValue);
		rtd_outl(VODMA_VODMA_PVS_CTRL_reg, pvs_ctrl.regValue);
		rtd_outl(VODMA_VODMA_PVS0_Gen_reg, pvs0.regValue);

		//ROSPrintfInternal("vodma clkgen = %x/%x\n", clkgen.regValue, vo_rtd_inl(VODMA_VODMA_CLKGEN_reg));
		//ROSPrintfInternal("PVS_FREE = %x/%x\n", pvs_free.regValue, vo_rtd_inl(VODMA_VODMA_PVS_Free_reg));
		//ROSPrintfInternal("PVS0_GEN = %x/%x\n", pvs0.regValue, vo_rtd_inl(VODMA_VODMA_PVS0_Gen_reg));
	}
}

static void VODMA_HDMI_Set_AutoMode(VODMA_HDMI_AUTO_MODE autoMode)
{

	hdmi_autoMode = autoMode;
	return;
}
VODMA_HDMI_AUTO_MODE VODMA_HDMI_Get_AutoMode(void)
{
	return hdmi_autoMode;
}

void VODMA_Verifier_WriteDisable(VO_VIDEO_PLANE VideoPlane)
{
    vodma_vodma_reg_db_ctrl_RBUS V1_vodma_reg_db_ctrl;
   // vodma2_vodma2_reg_db_ctrl_RBUS V2_vodma_reg_db_ctrl;

    V1_vodma_reg_db_ctrl.regValue= rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
   // V2_vodma_reg_db_ctrl.regValue= rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);

	switch (VideoPlane) {
	case VO_VIDEO_PLANE_V1:
        V1_vodma_reg_db_ctrl.vodma_db_rdy = 0;
        V1_vodma_reg_db_ctrl.vodmavsg_db_rdy = 0;
        rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, V1_vodma_reg_db_ctrl.regValue);
		break;

#ifdef VODMA2_EXIST
	case VO_VIDEO_PLANE_V2:
        V2_vodma_reg_db_ctrl.vodma_db_rdy = 0;
        V2_vodma_reg_db_ctrl.vodmavsg_db_rdy = 0;
        rtd_outl(VODMA2_VODMA2_REG_DB_CTRL_reg, V2_vodma_reg_db_ctrl.regValue);
		break;
#endif

	case VO_VIDEO_PLANE_NONE:
	default:
		break;
	}
}

void VODMA_Verifier_WriteEnable(VO_VIDEO_PLANE VideoPlane)
{
    vodma_vodma_reg_db_ctrl_RBUS V1_vodma_reg_db_ctrl;
    //vodma2_vodma2_reg_db_ctrl_RBUS V2_vodma_reg_db_ctrl;

    V1_vodma_reg_db_ctrl.regValue= rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);
    //V2_vodma_reg_db_ctrl.regValue= rtd_inl(VODMA_VODMA_REG_DB_CTRL_reg);

	switch (VideoPlane) {
	case VO_VIDEO_PLANE_V1:
        V1_vodma_reg_db_ctrl.vodma_db_rdy = 1;
        V1_vodma_reg_db_ctrl.vodmavsg_db_rdy = 1;
        rtd_outl(VODMA_VODMA_REG_DB_CTRL_reg, V1_vodma_reg_db_ctrl.regValue);

		break;

#ifdef VODMA2_EXIST
	case VO_VIDEO_PLANE_V2:
        V2_vodma_reg_db_ctrl.vodma_db_rdy = 1;
        V2_vodma_reg_db_ctrl.vodmavsg_db_rdy = 1;
        rtd_outl(VODMA2_VODMA2_REG_DB_CTRL_reg, V2_vodma_reg_db_ctrl.regValue);

		break;
#endif

	case VO_VIDEO_PLANE_NONE:
	default:
		break;
	}
}
extern void Config_VO_Dispinfo(SLR_VOINFO *pVOInfo);
void VODMA_SetVOInfo(unsigned int ch, VO_TIMING *timemode, unsigned char source,VODMA_DDOMAIN_CHROMA Ddomain_Chroma,VO_COLORSPACE colorspace)
{
	//VO_DATA *vo = &vodma_data[0];
		SLR_VOINFO VOInfo;
		unsigned char isRGB = 0;

		pr_debug("[vo] vomda_set_voinfo\n");

		memset(&VOInfo, 0, sizeof(SLR_VOINFO));

		/*isRGB = ((vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ARGB) ||
			 (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_ABGR) ||
			 (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_BGR) ||
			 (vo->image[ch].pixel_format == HAL_VO_PIXEL_FORMAT_RGB));*/

		VOInfo.plane = VO_VIDEO_PLANE_V1;
		VOInfo.port = ch;
		VOInfo.mode = Mode_Decision(timemode->HWidth, timemode->VHeight, timemode->isProg);
		VOInfo.h_total = timemode->HTotal;
		VOInfo.v_total = (timemode->isProg) ? timemode->VTotal : timemode->VTotal/2;
		VOInfo.h_start = timemode->HStartPos;
		VOInfo.v_start = timemode->VStartPos - 2 - 1; /* IVS_START = 2 */
		VOInfo.h_width = timemode->HWidth;
		VOInfo.v_length = timemode->VHeight;
		VOInfo.h_freq = vsyncgen_pixel_freq / timemode->HTotal / 100;
		VOInfo.v_freq = timemode->FrameRate/100;
		VOInfo.pixel_clk = vsyncgen_pixel_freq;
		VOInfo.progressive = timemode->isProg;
		VOInfo.chroma_fmt = Ddomain_Chroma;
		VOInfo.i_ratio =  0; /* 0. 16:9, 1. 4:3 //480*100/720=66.67 */
		VOInfo.source =  0; /* 3 for rgb, or just set 0 */
		VOInfo.isJPEG = 0;
		VOInfo.vdec_source = VOInfo.isJPEG;
		VOInfo.colorspace = colorspace;
		VOInfo.mode_3d = 0;
		VOInfo.force2d = 0;
		VOInfo.afd = 8;
		VOInfo.pixelAR_hor = 1;
		VOInfo.pixelAR_ver = 1;
		VOInfo.launcher = 0;
		VOInfo.src_h_wid = timemode->HWidth;
		VOInfo.src_v_len = timemode->VHeight;

		printk("\nSet Voinfo:\n");
		printk("plane=%d\n", VOInfo.plane);
		printk("port=%d\n", VOInfo.port);
		printk("mode=%d\n", VOInfo.mode);
		printk("h_start=%d\n", VOInfo.h_start);
		printk("v_start=%d\n", VOInfo.v_start);
		printk("h_width=%d\n", VOInfo.h_width);
		printk("v_length=%d\n", VOInfo.v_length);
		printk("h_total=%d\n", VOInfo.h_total);
		printk("v_total=%d\n", VOInfo.v_total);
		printk("chroma_fmt=%d\n", VOInfo.chroma_fmt);
		printk("progressive=%d\n", VOInfo.progressive);
		printk("h_freq=%d\n", VOInfo.h_freq);
		printk("v_freq=%d\n", VOInfo.v_freq);
		printk("pixel_clk=%d\n", VOInfo.pixel_clk);
		printk("i_ratio=%d\n", VOInfo.i_ratio);
		printk("source=%d\n", VOInfo.source);
		printk("isJPEG=%d\n", VOInfo.isJPEG);
		printk("mode_3d=%d\n", VOInfo.mode_3d);
		printk("force2d=%d\n", VOInfo.force2d);
		printk("afd=%d\n", VOInfo.afd);
		printk("HPAR=%d\n", VOInfo.pixelAR_hor);
		printk("VPAR=%d\n", VOInfo.pixelAR_ver);
		printk("src_h_wid=%d\n", VOInfo.src_h_wid);
		printk("src_v_len=%d\n", VOInfo.src_v_len);
		printk("rotate=%d\n", VOInfo.screenRotation);
		printk("launcher=%d\n", VOInfo.launcher);

		//set_zoom_smoothtoggle_vo_hwid(VOInfo.src_h_wid);
		//set_zoom_smoothtoggle_vo_vlen(VOInfo.src_v_len);
		//if ((get_vo_nosignal_flag(ch) == 0) && (memcmp(&vo->videoPlane[ch].VOInfo, &VOInfo, sizeof(SLR_VOINFO) - (sizeof(SLR_AFD_TYPE) + (sizeof(unsigned int)*4))) == 0)) { /* don't compare voinfo AFD, PixelAR and launcher*/
		//	pr_debug("[vo] enter the same timing\n");
		//	return S_FAIL;
		//}

		//memcpy(&vo->videoPlane[ch].VOInfo, &VOInfo, sizeof(SLR_VOINFO));
		memcpy(Scaler_VOInfoPointer(ch), &VOInfo, sizeof(SLR_VOINFO));
		Scaler_DispSetInputInfoByDisp(ch, SLR_INPUT_VO_SOURCE_TYPE, VOInfo.isJPEG);
		//set_vo_nosignal_flag(ch, 0);
		Config_VO_Dispinfo(&VOInfo);

		return 1;

}




int VODMA_ConfigHDMI(VIDEO_RPC_VOUT_CONFIG_HDMI_3D *HDMI_INFO)
{
	//vo = VO_Dmem->VO_data;
	//VO_VPLANE_ATTR *plane = VO_Dmem->VO_data->videoPlane[HDMI_INFO->videoPlane];
	VO_TIMING timemode;
	VODMA_DDOMAIN_CHROMA_FMT Ddomain_Chroma_fmt;
	//unsigned int porch_extend = (HDR_DolbyVision_Get_CurDolbyMode() == HDR_DOLBY_HDMI? 80: 0);
	unsigned int porch_extend = 0;

	// select IDMA auto mode
	VODMA_HDMI_Set_AutoMode(HDMI_INFO->hw_auto_mode? HDMI_AUTO_MODE_HW_MODE2: HDMI_AUTO_MODE_DISABLE);

    // use  IDMA auto mode and flag fifo
    if (HDMI_INFO->hw_auto_mode)
    {
        VODMA_HDMI_Set_AutoMode(HDMI_AUTO_MODE_HW_MODE1);

        //VODMA_Flag_FIFO_enable(true);
    }

    //set i2rnd display table
	//if(Scaler_i2rnd_enable_get())
	//	Scaler_I2rnd_set_display(HDMI_INFO->i2rnd_display_table);
	//else
		//Scaler_I2rnd_set_display(_DISABLE);


	printk("VODMA_ConfigHDMI:\n");
	printk("videoPlane = %d\n", HDMI_INFO->videoPlane);
	printk("width = %d\n", HDMI_INFO->width);
	printk("height = %d\n", HDMI_INFO->height);
	printk("progressive = %d\n", HDMI_INFO->progressive);
	printk("framerate = %d\n", HDMI_INFO->framerate);
	printk("chroma_fmt = %d\n", HDMI_INFO->chroma_fmt);
	printk("data_bit_width = %d\n", HDMI_INFO->data_bit_width);
	printk("hw_auto_mode = %d\n", VODMA_HDMI_Get_AutoMode());
	printk("l1_sta_adr = %x\n", HDMI_INFO->l1_st_adr);
	printk("r1_sta_adr = %x\n", HDMI_INFO->r1_st_adr);
	printk("l2_sta_adr = %x\n", HDMI_INFO->l2_st_adr);
	printk("r2_sta_adr = %x\n", HDMI_INFO->r2_st_adr);
	printk("quincunx_en = %d\n", HDMI_INFO->quincunx_en);
	printk("quincunx_mode_fw = %d\n", HDMI_INFO->quincunx_mode_fw);
	printk("sensio3D_en = %d\n", HDMI_INFO->sensio3D_en);
	printk("sg3d_dataFrc = %d\n", HDMI_INFO->sg3d_dataFrc);
	printk("i2rnd_sub_src = %d\n", HDMI_INFO->i2rnd_sub_src);
	printk("i2rnd_display_table = %d\n", HDMI_INFO->i2rnd_display_table);
	printk("htotal = %d\n", HDMI_INFO->htotal);
	printk("vtotal = %d\n", HDMI_INFO->vtotal);
	printk("hw_auto_mode = %d\n", HDMI_INFO->hw_auto_mode);




	//i2rnd_sub_vodma = HDMI_INFO->i2rnd_sub_src;
	//check porch_extend
	//if(HDMI_INFO->i2rnd_sub_src == _ENABLE)
		//porch_extend = 0;
	//else
	 	//porch_extend = (HDR_DolbyVision_Get_CurDolbyMode() == HDR_DOLBY_HDMI? 80: 0);
		porch_extend =0;
	if ( HDMI_INFO->videoPlane > 2)
    {
        printk( "[vo] Invalid plane %d @ %s\n", HDMI_INFO->videoPlane, __FUNCTION__);
		return -1 ;
    }

    if ( HDMI_INFO->width < 86)
    {
        printk("[vo] HDMI width=%d!!\n", HDMI_INFO->width);
        return -1 ;
    }

    //plane->secure = 0;

	if (HDMI_INFO->videoPlane == VO_VIDEO_PLANE_V3)
		Ddomain_Chroma_fmt =FMT_444;
	else
		Ddomain_Chroma_fmt = (HDMI_INFO->chroma_fmt == VO_CHROMA_YUV422 || HDMI_INFO->chroma_fmt == VO_CHROMA_YUV411)? FMT_422: FMT_444; // no 420

#if 0//def __DOLBY_VTOP_422TO444__
	if (HDR_DolbyVision_Get_CurDolbyMode()==HDR_HDR10_HDMI)
	        VODMA_DOLBY_V_TOP_Enable_422to444(HDMI_INFO->videoPlane, false);
	else
		VODMA_DOLBY_V_TOP_Enable_422to444(HDMI_INFO->videoPlane, (plane->Ddomain_Chroma_fmt == FMT_422));
    plane->Ddomain_Chroma_fmt = FMT_444;
 #endif

	//plane->displayWin.width = plane->pictureWin.width = HDMI_INFO->width ;
	//plane->displayWin.height = plane->pictureWin.height = HDMI_INFO->height ;
	//plane->displayWin.x = plane->pictureWin.x = 0 ;
	//plane->displayWin.y = plane->pictureWin.y = 0 ;

    // [WOSQRTK-8914][Merlin2] pixel align for 1360/1366 RGB444 sequential mode vodma underflow issue
    if(((HDMI_INFO->width == 1360) || (HDMI_INFO->width == 1366))
        && ((HDMI_INFO->chroma_fmt == VO_CHROMA_YUV444) || (HDMI_INFO->chroma_fmt == VO_CHROMA_RGB888)))
    {
        HDMI_INFO->width = ((HDMI_INFO->width + 0x1f) & ~0x1f); // 1360 -> 1376
        //printk("[HDMI] Pixel Align %d->%d@%d\n", plane->pictureWin.width, HDMI_INFO->width, HDMI_INFO->chroma_fmt);
    }

	timemode.isProg 	= HDMI_INFO->progressive;// 1 ;
	timemode.HWidth 	= (HDMI_INFO->quincunx_en|| HDMI_INFO->sensio3D_en)? HDMI_INFO->width*2: HDMI_INFO->width;
	timemode.VHeight 	= HDMI_INFO->height;
	timemode.HStartPos 	= (HDMI_INFO->videoPlane == VO_VIDEO_PLANE_V3)? 140: 70;//140;
	timemode.VStartPos 	= 20;
	//htotal decision flow
	/*protection: make sure there is a enough porch*/
	if(HDMI_INFO->htotal > (timemode.HWidth + timemode.HStartPos)){
		//porch enough case, use source total.
		timemode.HTotal = HDMI_INFO->htotal;
		//if source total smaller than h start*2 + width, refine h start
		if(timemode.HTotal < (timemode.HStartPos * 2 + timemode.HWidth)){
			timemode.HStartPos = (timemode.HTotal - timemode.HWidth) / 2;
		}
	}
	else{
		//porch not enough case, calculate the safe total.
		timemode.HTotal = timemode.HWidth + (timemode.HStartPos * 2);
	}
#if 0
	if (((HDR_DolbyVision_Get_CurDolbyMode()==HDR_DOLBY_HDMI) ||((HDR_DolbyVision_Get_CurDolbyMode()==HDR_HDR10_HDMI) && (VO_Get_603MHzStatus() == TRUE))) && timemode.HWidth<=3840
		&& (HDMI_INFO->i2rnd_sub_src == _DISABLE)) {
		timemode.HTotal = VO_FIXED_4K2K_HTOTAL;
		timemode.HStartPos = 320;
	}
#endif
	timemode.FrameRate	= (HDMI_INFO->framerate == 0)? 60000: HDMI_INFO->framerate ;

	//vtotal decision flow
	/*protection: make sure there is a enough porch*/
	if(HDMI_INFO->vtotal > (timemode.VHeight + timemode.VStartPos)){
		//porch enough case, use source total.
		timemode.VTotal = (timemode.isProg? HDMI_INFO->vtotal: HDMI_INFO->vtotal * 2) + ((timemode.isProg) ?0:(timemode.FrameRate <= 100000? 18: 8)) + porch_extend;//add enough porch for vo isr and dolby case.

		//if source total smaller than v start*2 + length, refine v start
		if(timemode.isProg){
			if(timemode.VTotal < (timemode.VStartPos * 2 + timemode.VHeight)){
				timemode.VStartPos = (timemode.VTotal - timemode.VHeight) / 2;
			}
		}
		else{
			if(timemode.VTotal < (timemode.VStartPos * 2 + timemode.VHeight * 2)){
				timemode.VStartPos = (timemode.VTotal - timemode.VHeight * 2) / 2;
			}
		}
	}
	else{
		//porch not enough case, calculate the safe total.
		timemode.VTotal = (timemode.isProg? HDMI_INFO->height: HDMI_INFO->height * 2) + (timemode.VStartPos * 2) + ((timemode.isProg) ?0:(timemode.FrameRate <= 100000? 18: 8)) + porch_extend;
	}

	//ROSPrintfInternal("timemode.VStartPos = %d\n", timemode.VStartPos);
	//ROSPrintfInternal("timemode.VHeight = %d\n", timemode.VHeight);
	//ROSPrintfInternal("timemode.VTotal = %d\n", timemode.VTotal);
#if 0
	if((HDR_DolbyVision_Get_CurDolbyMode()==HDR_HDR10_HDMI) && (VO_Get_603MHzStatus() == TRUE)
		&& (HDMI_INFO->i2rnd_sub_src == _DISABLE)){
		timemode.VTotal = VO_FIXED_4K2K_VTOTAL;
	}
#endif
	//timemode.SampleRate	= (timemode.HTotal * timemode.VTotal * (timemode.FrameRate/(float)1000) + 9999)/ (float)10000;
	timemode.SampleRate = (timemode.HTotal * timemode.VTotal * (timemode.FrameRate / 1000) + 9999) / 10000;
//I2rnd fixed VO clock and h_total/h_porch
#if 0
	if(Scaler_i2rnd_enable_get()){
		timemode.SampleRate = Scaler_i2rnd_get_vo_clock(HDMI_INFO->width, HDMI_INFO->height, HDMI_INFO->progressive, HDMI_INFO->framerate);

		//htotal and vtotal decision
		if(HDMI_INFO->progressive == 1){
			/*if(HDMI_INFO->width >= 3000){//4k2k or 4k1k case
				if(HDMI_INFO->height > 1000){//4k2k
					timemode.HTotal = 4020;
					timemode.VTotal = 2210;
				}
				else{//4k1k
					timemode.HTotal = 4020;
					timemode.VTotal = 1130;
				}
			}
			else{
			*/
			//2k1k case
				timemode.HTotal = 2100;
				timemode.VTotal = 1130;
			//}
		}
		else{//2k0.5k case
			timemode.HTotal = 2100;
			timemode.VTotal = 590 * 2;
		}
		//fixed h_porch 180 => start 90 to avoid den and hs error issue @Crixus
		timemode.HStartPos = 90;

		//fixed frame rate
		timemode.FrameRate = 60000;

	}
	// [ECNMAC5P-189] support VO flag fifo input fast mode
	if(Scaler_i2rnd_enable_get()){
		vodma_vodma_i2rnd_fifo_th_RBUS vodma_vodma_i2rnd_fifo_th_reg;
		h3ddma_cap_ctl0_RBUS  i3ddma_cap_ctl0_reg;
		vodma_vodma_i2rnd_fifo_th_reg.regValue = vo_rtd_inl(VODMA_vodma_i2rnd_fifo_th_reg);
		i3ddma_cap_ctl0_reg.regValue = rtd_inl(H3DDMA_Cap_CTL0_reg);
		// decide input fast mode
		if(HDMI_INFO->i2rnd_sub_src){
			vodma_vodma_i2rnd_fifo_th_reg.flag_fifo_style_dispm = (i3ddma_cap_ctl0_reg.triple_buf_en? 1: 0);
		}else{
			vodma_vodma_i2rnd_fifo_th_reg.flag_fifo_style_i3ddma = (i3ddma_cap_ctl0_reg.triple_buf_en? 1: 0);
		}
		vo_rtd_outl(VODMA_vodma_i2rnd_fifo_th_reg, vodma_vodma_i2rnd_fifo_th_reg.regValue);
	}
#endif
	printk("[vo] p%d timemode:Prog %d,[%d/%d/%d/%d/%d/%d],FR/SR[%d(%d)/%d]\n",
		HDMI_INFO->videoPlane,	timemode.isProg,
		timemode.HTotal, timemode.VTotal, timemode.HStartPos, timemode.VStartPos, timemode.HWidth, timemode.VHeight,
		timemode.FrameRate, HDMI_INFO->framerate, timemode.SampleRate);

	//memcpy (&plane->timemode, &timemode, sizeof(VO_TIMING)) ;

	//VO_ENTER_CRITICAL();

    drivf_scaler_reset_freerun();

	switch (HDMI_INFO->videoPlane) {
	case VO_VIDEO_PLANE_V1:

	VODMA_Verifier_WriteDisable(VO_VIDEO_PLANE_V1);

	/* syncgen */
	timinggen_set_v1(0, &timemode);

	/* dma */
	dma_set_v1(0, &timemode, HDMI_INFO, DMA_SEQUENTIAL_MODE, Ddomain_Chroma_fmt);

	/* i-domain timing gen */
	vsyncgen_set_v1(0, &timemode);

    VODMA_Verifier_WriteEnable(VO_VIDEO_PLANE_V1);

		//VO_Dmem->vodma_ctrl.v1I3DDMA = 1;
		//VO_Dmem->vodma_ctrl.v1sg3dDataFrc = HDMI_INFO->sg3d_dataFrc;
		//VO_Dmem->vodma_ctrl.v1HDMI = (HDMI_INFO->hw_auto_mode == HDMI_AUTO_MODE_DISABLE) ? 1 : 0 ;
		//VO_Dmem->vodma_ctrl.v1Sensio3D = HDMI_INFO->sensio3D_en;

		break;

	default:
		break;
	}

	//rpcVoReady();
//elieli
	//VO_EXIT_CRITICAL();
	//VODMA_SetVOInfo(HDMI_INFO->videoPlane, &timemode, 5, 0, 0, 0, VO_COLORSPACE_YUV, 0);
	VODMA_SetVOInfo(VO_VIDEO_PLANE_V1, &timemode, 5,Ddomain_Chroma_fmt,VO_COLORSPACE_YUV);


	return 0 ;

}

#endif



