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
//#include <mach/io.h>

//#include <mach/video_driver.h>
//#include <mach/RPCDriver.h>


#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <tvscalercontrol/i3ddma/i3ddma.h>
//#include <rbus/scaler/rbusI3DDMA_rgb2yuv_dither_4xxto4xxReg.h>
#include <rbus/h3ddma_rgb2yuv_dither_4xxto4xx_reg.h>
#include <rbus/h3ddma_hsd_reg.h>
#include <rbus/dma_vgip_reg.h>

#include <tvscalercontrol/scaler/modeState.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scaler/scalerlib.h>
//#include <hdmiInternal.h>

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

extern I3DDMA_3DDMA_CTRL_T i3ddmaCtrl;

//#ifdef I3DDMA_HAVE_HDMI_DMA
#if 1

static char convert_4xxto4xx[4][4] = {

	{ 0, 0x2, 0, 0x3 },		// RGB444 -->
	{ -1, 0, -1, 0x1 },		// YUV422 -->
	{ 0,	0x02, 0x0, 0x3 },	// YUV444 -->
	{ -1, -1, -1, 0x0 }		// YUV411 -->


};


char I3DDMA_4xxto4xx_Downsample(I3DDMA_COLOR_SPACE_T source, I3DDMA_COLOR_SPACE_T target) {

	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg;
	h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS i3ddma_vsd_ctrl0_reg;
#if 0//fixed me, remove in mag2 @ Crixus 0305
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_RBUS i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg;
#endif
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
#if 0//fixed me, remove in mag2 @ Crixus 0305
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.regValue = rtd_inl(I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_4XXTO4XX_CTRL_VADDR);
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.yuv_4xxto4xx_sel = 0;
	rtd_outl(I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_4XXTO4XX_CTRL_VADDR, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.regValue);
#endif
	pr_notice("[HDMI-DMA][CVT] en/src/targ[%d/%d/%d], 4xxto4xx=%d\n", i3ddmaCtrl.hw_4xxto4xx_enable, source, target, convert_4xxto4xx[source][target] );

#if 1
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_422to444_ctrl_RBUS i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg;
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_422to444_CTRL_reg);
	if(source == I3DDMA_COLOR_YUV422){
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.en_422to444 = 1;
	}
	else
	{
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.en_422to444 = 0;
	}
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_422to444_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.regValue);
#endif

	i3ddma_vsd_ctrl0_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
	/*i3ddma_vsd_ctrl0_reg.sort_fmt = 0;*/ //i3ddma always capture yuv422
	 if(source == I3DDMA_COLOR_YUV422){
	 	
	 	if(target == I3DDMA_COLOR_YUV422)
			i3ddma_vsd_ctrl0_reg.sort_fmt = 0; //444 to 422
		else
	 		i3ddma_vsd_ctrl0_reg.sort_fmt = 1; //yuv422 bypass (1)
		
	 }
	 else if(source == I3DDMA_COLOR_RGB)
	 {
	 	if(target == I3DDMA_COLOR_YUV422)
	 		i3ddma_vsd_ctrl0_reg.sort_fmt = 0; //444 to 422
	 	else
			i3ddma_vsd_ctrl0_reg.sort_fmt = 1;//keep 444
	 }
	 else
	 {//input 444
	 	if(target == I3DDMA_COLOR_YUV422)
			i3ddma_vsd_ctrl0_reg.sort_fmt = 0; //444 to 422
		else
			i3ddma_vsd_ctrl0_reg.sort_fmt = 1;//keep 444
	 }
	 
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg, i3ddma_vsd_ctrl0_reg.regValue);
	// RGB2YUV color conversion
	if (source == I3DDMA_COLOR_RGB) {
#ifdef CONFIG_FORCE_RUN_I3DDMA
		if(DMA_VGIP_DMA_VGIP_CTRL_get_dma_in_sel(rtd_inl(DMA_VGIP_DMA_VGIP_CTRL_reg)) == VGIP_SRC_ATV)
		{
			pr_debug("av source, idma bypass rgb2yuv\n");
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
			rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
		}
		else if(target != I3DDMA_COLOR_RGB) 
#else
			if(target != I3DDMA_COLOR_RGB) 
#endif
		{
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 1;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.sel_rgb = 1;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.set_uv_out_offset = 1;
			rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
		}
	} else {
		if(target != I3DDMA_COLOR_RGB) {
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.sel_rgb = 0;
			i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.set_uv_out_offset = 0;
			rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);
		}
	}

	// 4xxto4xx color conversion
	if (i3ddmaCtrl.hw_4xxto4xx_enable == 0) 		return I3DDMA_ERR_NO;

	if (target == I3DDMA_COLOR_RGB) {
		pr_debug("4xxto4xx convert in RGB space is not allow\n");
		return I3DDMA_ERR_4XXTO4XX_WRONG_PARAM;

	}
	if (source == target) {
		pr_debug("input no need to do 4xxto4xx\n");
		return I3DDMA_ERR_NO;
	}

	if (convert_4xxto4xx[source][target] < 0) {
		pr_debug("convert is not allow 4xxto4xx\n");
		return I3DDMA_ERR_4XXTO4XX_WRONG_PARAM;
	}
#if 0//fixed me, remove in mag2 @ Crixus 0305
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.regValue = rtd_inl(I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_4XXTO4XX_CTRL_VADDR);
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.yuv_4xxto4xx_sel = convert_4xxto4xx[source][target];
	rtd_outl(I3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_4XXTO4XX_CTRL_VADDR, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_4xxto4xx_ctrl_reg.regValue);
#endif
	return I3DDMA_ERR_NO;

}
#endif



#ifdef I3DDMA_HAVE_HDMI_DITHER_12X10
#define I3DDMA_DITHERLUT_ROW_MAX		3
#define I3DDMA_DITHERLUT_COL_MAX		4
#define I3DDMA_DITHERLUT_DEP_MAX		4

static unsigned char tI3DDMA_DITHER_SEQUENCE[3][16] = {
	{0xAD, 0x80, 0xE6, 0xA3, 0x9E, 0x47, 0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85},
	{0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85, 0x0A, 0x68, 0x3E, 0xEA, 0x79, 0xD4},
	{0xAD, 0x80, 0xE6, 0xF3, 0xB0, 0x6C, 0x85, 0xEA, 0x79, 0xD4, 0x92, 0x2B, 0x41, 0xC7, 0xF1, 0x35}
};

static unsigned char tI3DDMA_DITHER_LUT[3][16][4] = {
	{
		{0x00, 0x30, 0x20, 0x10}, {0x29, 0x19, 0x39, 0x09}, {0x3E, 0x0E, 0x1E, 0x2E}, {0x17, 0x27, 0x07, 0x37},
		{0x0C, 0x3C, 0x2C, 0x1C}, {0x25, 0x15, 0x35, 0x05}, {0x32, 0x02, 0x12, 0x22}, {0x1B, 0x2B, 0x0B, 0x3B},
		{0x08, 0x38, 0x28, 0x18}, {0x2D, 0x1D, 0x3D, 0x0D}, {0x36, 0x06, 0x16, 0x26}, {0x13, 0x23, 0x03, 0x33},
		{0x04, 0x34, 0x24, 0x14}, {0x21, 0x11, 0x31, 0x01}, {0x3A, 0x0A, 0x1A, 0x2A}, {0x1F, 0x2F, 0x0F, 0x3F}
	},
	{
		{0x28, 0x18, 0x38, 0x08}, {0x3D, 0x0D, 0x1D, 0x2D}, {0x16, 0x26, 0x06, 0x36}, {0x03, 0x33, 0x23, 0x13},
		{0x24, 0x14, 0x34, 0x04}, {0x31, 0x01, 0x11, 0x21}, {0x1A, 0x2A, 0x0A, 0x3A}, {0x0F, 0x3F, 0x2F, 0x1F},
		{0x2C, 0x1C, 0x3C, 0x0C}, {0x35, 0x05, 0x15, 0x25}, {0x12, 0x22, 0x02, 0x32}, {0x0B, 0x3B, 0x2B, 0x1B},
		{0x20, 0x10, 0x30, 0x00}, {0x39, 0x09, 0x19, 0x29}, {0x1E, 0x2E, 0x0E, 0x3E}, {0x07, 0x37, 0x27, 0x17},
	},
	{
		{0x3C, 0x0C, 0x1C, 0x2C}, {0x15, 0x25, 0x05, 0x35}, {0x02, 0x32, 0x22, 0x12}, {0x2B, 0x1B, 0x3B, 0x0B},
		{0x30, 0x00, 0x10, 0x20}, {0x19, 0x29, 0x09, 0x39}, {0x0E, 0x3E, 0x2E, 0x1E}, {0x27, 0x17, 0x37, 0x07},
		{0x34, 0x04, 0x14, 0x24}, {0x11, 0x21, 0x01, 0x31}, {0x0A, 0x3A, 0x2A, 0x1A}, {0x2F, 0x1F, 0x3F, 0x0F},
		{0x38, 0x08, 0x18, 0x28}, {0x1D, 0x2D, 0x0D, 0x3D}, {0x06, 0x36, 0x26, 0x16}, {0x23, 0x13, 0x33, 0x03},
	}
};


static unsigned char tI3DDMA_DITHER_TEMPORAL[16] = { 0, 3, 2, 1, 2, 1, 3, 0, 3, 0, 1, 2, 1, 2, 0, 3 };

char I3DDMA_Dithering12to10(I3DDMA_COLOR_DEPTH_T source, I3DDMA_COLOR_DEPTH_T target) {

	int ii, jj, kk, data_shift = 0,shift_bit=0;
	unsigned int dither_32BIT_DATA = 0;

	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_RBUS i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg;

	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg);
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.dither_bit_sel = source != I3DDMA_COLOR_DEPTH_8B;
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue);

	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.err_dif_enable= 0;
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);

	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg);
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.ch2_temporal_enable = 0;
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.ch2_dithering_table_select = 0;
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue);

	if (i3ddmaCtrl.hw_dither12x10_enable == 0) return I3DDMA_ERR_NO;

	if (source == I3DDMA_COLOR_DEPTH_8B) {  // no need to do dithering
		return I3DDMA_ERR_NO;
	}

	if (source == I3DDMA_COLOR_DEPTH_10B) {	//source: 10 bits
		switch (target) {
				case I3DDMA_COLOR_DEPTH_8B:
					shift_bit = 2;
				break;
				case I3DDMA_COLOR_DEPTH_10B:// no need to do dithering
				case I3DDMA_COLOR_DEPTH_12B:// no need to do dithering
				case I3DDMA_COLOR_DEPTH_16B:	// no need to do dithering
				default:
					return I3DDMA_ERR_NO;
		}

	} else {	// source : 12 bit or 16 bits
		switch (target) {
				case I3DDMA_COLOR_DEPTH_8B:
					shift_bit = 4;
				break;
				case I3DDMA_COLOR_DEPTH_10B:
					shift_bit = 2;
				break;
				case I3DDMA_COLOR_DEPTH_12B:// no need to do dithering
				case I3DDMA_COLOR_DEPTH_16B:	// no need to do dithering
				default:
					return I3DDMA_ERR_NO;
		}

	}

	// generate DITHER SEQ
	for(ii = 0; ii < 3; ii++) // rgb order
	{
		for(jj = 0; jj < 16; jj++)
		{
			if((jj == 0) || (jj == 8) )
			{
				dither_32BIT_DATA = 0;
				data_shift = 0;
			}
			dither_32BIT_DATA +=(tI3DDMA_DITHER_SEQUENCE[ii][jj]%16) << data_shift ;
			data_shift += 4;

			if(jj == 7)
			{
				switch(ii)
				{
					case 0:// red
							rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_R_00_15_reg, dither_32BIT_DATA);
							break;
					case 1:// green
							rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_G_00_07_reg, dither_32BIT_DATA);
							break;
					case 2:// blue
							rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_B_00_15_reg, dither_32BIT_DATA);
							break;
				}
			}

			if(jj == 15)
			{
				switch(ii)
				{
					case 0: // red
							rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_R_16_31_reg,dither_32BIT_DATA);
							break;
					case 1: // green
							rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_G_16_31_reg, dither_32BIT_DATA);
							break;
					case 2: // blue
							rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_SEQ_B_16_31_reg, dither_32BIT_DATA);
							break;
				}
			}
		}
	}
	if(target >= I3DDMA_COLOR_DEPTH_10B)
	{
		for(ii = 0; ii < I3DDMA_DITHERLUT_ROW_MAX; ii++)
		{
			for(jj = 0; jj < I3DDMA_DITHERLUT_COL_MAX; jj++)
			{
				if((jj == 0) || (jj == 2) )
				{
					dither_32BIT_DATA = 0;
					data_shift = 0;
				}

				for(kk = 0; kk < 4; kk++)
	 	                {
					dither_32BIT_DATA += (tI3DDMA_DITHER_LUT[ii][jj][kk] >> shift_bit) << data_shift;
					data_shift += I3DDMA_DITHERLUT_DEP_MAX;
		                }

				if(jj == 1)
				{
					switch(ii)
					{
						case 0: // red
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_R_00_reg, dither_32BIT_DATA);
								break;
						case 1: // green
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_G_00_reg, dither_32BIT_DATA);
								break;
						case 2: // blue
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_B_00_reg, dither_32BIT_DATA);
								break;
					}
				}

				if(jj == 3)
				{
					switch(ii)
					{
						case 0: // red
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_R_02_reg, dither_32BIT_DATA);
								break;
						case 1: // green
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_G_02_reg, dither_32BIT_DATA);
								break;
						case 2: // blue
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB1_B_02_reg, dither_32BIT_DATA);
								break;
					}
				}


			}
		}

		dither_32BIT_DATA=0;
		for(ii = 0; ii < 16; ii++)
		{
			dither_32BIT_DATA += tI3DDMA_DITHER_TEMPORAL[ii] << (ii *2);
		}

		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_Temp_TB1_reg, dither_32BIT_DATA);

		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg);
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.ch2_temporal_enable = 1;
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.ch2_dithering_table_select = 1;
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue);
	}else
	{
		for(ii = 0; ii < I3DDMA_DITHERLUT_ROW_MAX; ii++)
		{
			for(jj = 0; jj < I3DDMA_DITHERLUT_COL_MAX; jj++)
			{
				if((jj == 0) || (jj == 2) )
				{
					dither_32BIT_DATA = 0;
					data_shift = 0;
				}

				for(kk = 0; kk < 4; kk++)
	 	                {
					dither_32BIT_DATA += (tI3DDMA_DITHER_LUT[ii][jj][kk] >> shift_bit) << data_shift;
					data_shift += I3DDMA_DITHERLUT_DEP_MAX;
		                }

			if(jj == 1)
				{
					switch(ii)
					{
						case 0: // red
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_R_00_reg, dither_32BIT_DATA);
								break;
						case 1: // green
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_G_00_reg, dither_32BIT_DATA);
								break;
						case 2: // blue
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_B_00_reg, dither_32BIT_DATA);
								break;
					}
				}

				if(jj == 3)
				{
					switch(ii)
					{
						case 0: // red
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_R_02_reg, dither_32BIT_DATA);
								break;
						case 1: // green
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_G_02_reg, dither_32BIT_DATA);
								break;
						case 2: // blue
								rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_TB2_B_02_reg, dither_32BIT_DATA);
								break;
					}
				}


			}
		}

		dither_32BIT_DATA=0;
		for(ii = 0; ii < 16; ii++)
		{
			dither_32BIT_DATA += tI3DDMA_DITHER_TEMPORAL[ii] << (ii *2);
		}

		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_Temp_TB2_reg, dither_32BIT_DATA);

		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg);
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.ch2_temporal_enable = 1;
		i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.ch2_dithering_table_select = 2;
		rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_DITHER_CTRL1_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_dither_ctrl1_reg.regValue);
		}

	// select input bits
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue = rtd_inl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.err_dif_bits= target;
	i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.err_dif_enable= 1;
	rtd_outl(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_reg.regValue);

	return I3DDMA_ERR_NO;
}

#endif

  unsigned char I3DDMA_Check_EnableDmaCapture_for_4k2k_video(I3DDMA_TIMING_T* tx_timing)
  {
  #ifdef ENABLE_HDMI_DMA_FOR_4K2K
	return (Scaler_GetHdmiDmaCapture_Enable() && (tx_timing->h_act_len >= 3840));
  #endif
  	return FALSE;
  }

void I3DDMA_BandWidth_Control(I3DDMA_TIMING_T* tx_timing, I3DDMA_TIMING_T*gen_timing) {

	if (((gen_timing->i3ddma_3dformat < I3DDMA_2D_ONLY)|| I3DDMA_Check_EnableDmaCapture_for_4k2k_video(tx_timing)) && (i3ddmaCtrl.hw_i3ddma_dma != I3DDMA_3D_OPMODE_DISABLE) && (i3ddmaCtrl.hw_i3ddma_dma != I3DDMA_3D_OPMODE_HW_NODMA)) {
		if (tx_timing->depth == I3DDMA_COLOR_DEPTH_8B) {
			gen_timing->depth = I3DDMA_COLOR_DEPTH_8B;
		} else {
			gen_timing->depth = I3DDMA_COLOR_DEPTH_10B;
		}

		switch(tx_timing->color) {
			case I3DDMA_COLOR_RGB:
			case I3DDMA_COLOR_YUV444:
				// bypass 4xxto4xx color conversion
				if((i3ddmaCtrl.targetColor == I3DDMA_COLOR_RGB) || (i3ddmaCtrl.targetColor == I3DDMA_COLOR_YUV444))
				{
					pr_debug("[DBG] Bypass 4xxto4xx cvt, src/des=%d/%d\n", tx_timing->color, i3ddmaCtrl.targetColor);
					return;
				}

				// [HDMI-DMA] HDMI-DMA capture for 4k2k video
				i3ddmaCtrl.hw_4xxto4xx_enable = 1;
	#if 1 // force convert to YUV422
				gen_timing->color = i3ddmaCtrl.targetColor;
	#else
				if(gen_timing->i3ddma_3dformat == I3DDMA_2D_ONLY)
					gen_timing->color = I3DDMA_COLOR_YUV422;
				else
					gen_timing->color = I3DDMA_COLOR_YUV411;
//				gen_timing->color = tx_timing->color;
	#endif
			break;
			case I3DDMA_COLOR_YUV422:
				// [HDMI-DMA] HDMI-DMA capture for 4k2k video
	#if 0 // force convert to YUV422
				if(gen_timing->i3ddma_3dformat == I3DDMA_2D_ONLY)
					; // don't need convert
				else{
					i3ddmaCtrl.hw_4xxto4xx_enable = 1;
					gen_timing->color = I3DDMA_COLOR_YUV411;
				}
	#endif
			break;

			case I3DDMA_COLOR_YUV411:
				//gen_timing->color = I3DDMA_COLOR_YUV411;
			default:
			break;

		}
	} else {
		if (tx_timing->depth == I3DDMA_COLOR_DEPTH_8B) {
			gen_timing->depth = I3DDMA_COLOR_DEPTH_8B;
		} else {
			gen_timing->depth = I3DDMA_COLOR_DEPTH_10B;
		}

	}
}




/*================================== Variables ==============================*/
/*extern unsigned char tDITHER_SEQUENCE[3][32] ;
extern unsigned char tDITHER_TEMPORAL[16] ;
extern  unsigned char tDITHER_LUT[3][4][4] ;*/
extern unsigned short tRGB2YUV_COEF_709_YUV_0_255[];
extern unsigned short tRGB2YUV_COEF_709_RGB_0_255[];
extern unsigned short tRGB2YUV_COEF_601_RGB_0_255[];

#if 0
static unsigned short tRGB2YUV_COEF_709_YUV_0_255[] =
 	{
	// CCIR 709 YPbPr
		0x1000, 	// m11
		0x0196, 	// m12
		0x0311,		// m13
		0x0000, 	// m21 >> 2
		0x0fd6, 	// m22 >> 1
		0x7e3a, 	// m23 >> 2
		0x0000, 	// m31 >> 2
		0x7ed7, 	// m32 >> 2  1ed up bits at AT Name: cychen2 , Date: 2010/3/25
		0x0fbc, 	// m33 >> 1

		0x0000, 	// Yo_even
		0x0000, 	// Yo_odd
		0x0100, 	// Y_gain
		0x0000,  // sel_RGB
		0x0000,  // sel_Yin_offset
		0x0001,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0000,  // Matrix_bypass

		0x0001,  // Enable_Y_gain


 	};


static unsigned short tRGB2YUV_COEF_709_RGB_0_255[] =
 	{
	// CCIR 709 RGB
		0x04c8,	// m11
		0x0964,  // m12
		0x01d2,  // m13

		0x7d4d,   // m21 >> 2 0x01D5 up bits at AT Name: cychen2 , Date: 2010/3/25
		0x7ab2,   // m22 >> 1
		0x0800,   // m23 >> 2
		0x0800,   // m31 >> 2
		0x794d,   // m32 >> 2 0x0195  up bits at AT Name: cychen2 , Date: 2010/3/25
		0x7eb2,   // m33 >> 1

		0x0000, 	// Yo_even
		0x0000, 	// Yo_odd
		0x0100, 	// Y_gain
		0x0001,  // sel_RGB
		0x0000,  // sel_Yin_offset
		0x0001,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0000,  // Matrix_bypass
		0x0001,  // Enable_Y_gain
	};


static   unsigned short tRGB2YUV_COEF_601_RGB_0_255[] =
 	{
	// CCIR 601 RGB

		0x04c8, 	// m11
		0x0964,   // m12
		0x01d2,   // m13
		0x7d4d,   // m21 >> 2 0x01D5 up bits at AT Name: cychen2 , Date: 2010/3/25
		0x7ab2,   // m22 >> 1
		0x0800,   // m23 >> 2
		0x0800,   // m31 >> 2
		0x794d,   // m32 >> 2 0x0195  up bits at AT Name: cychen2 , Date: 2010/3/25
		0x7eb2,   // m33 >> 1

		0x0000, 	// Yo_even
		0x0000, 	// Yo_odd
		0x0100, 	// Y_gain
		0x0001,  // sel_RGB
		0x0000,  // sel_Yin_offset
		0x0001,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0000,  // Matrix_bypass
		0x0001,  // Enable_Y_gain


	};
#endif
#if 0//not used
static   unsigned short tRGB2YUV_COEF_601_RGB_16_235[] =
 	{
	// CCIR 601 RGB
		0x0132, 	// m11
		0x0259,   // m12
		0x0075,   // m13
		0x03D5,   // m21 >> 2  0x01D5 up bits at AT Name: cychen2 , Date: 2010/3/25
		0x0356,   // m22 >> 1
		0x0080,   // m23 >> 2
		0x0080,   // m31 >> 2
		0x0795,   // m32 >> 2 0x0195  up bits at AT Name: cychen2 , Date: 2010/3/25
		0x03d6,   // m33 >> 1

		0x0000,//0x07e0,	// Yo_even
		0x0000,//0x07e0,	// Yo_odd
		0x0129,//0x0110,	// Y_gain
		0x0001,  // sel_RGB
		0x0001,//0x0000,  // sel_Yin_offset
		0x0001,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0000,  // Matrix_bypass
		0x0001,  // Enable_Y_gain

	};
#endif


static   unsigned short tRGB2YUV_COEF_601_YCbCr_0_255[] =
 	{
	// CCIR 601 YCbCr
		0x0000, 	// m11
		0x0000,   // m12
		0x0000,   // m13
		0x0000,   // m21 >> 2
		0x0000,   // m22 >> 1
		0x0000,   // m23 >> 2
		0x0000,   // m31 >> 2
		0x0000,   // m32 >> 2
		0x0000,   // m33 >> 1

		0x0000,  	// Yo_even
		0x0000,  	// Yo_odd
		0x0100,  	// Y_gain

		0x0000,  // sel_RGB
		0x0000,  // sel_Yin_offset
		0x0001,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0001,  // Matrix_bypass
		0x0001,  // Enable_Y_gain


	};
#if 0//not used
static   unsigned short tRGB2YUV_COEF_601_YCbCr_16_235[] =
 	{
	// CCIR 601 YCbCr
		0x0000, 	// m11
		0x0000,   // m12
		0x0000,   // m13
		0x0000,   // m21 >> 2
		0x0000,   // m22 >> 1
		0x0000,   // m23 >> 2
		0x0000,   // m31 >> 2
		0x0000,   // m32 >> 2
		0x0000,   // m33 >> 1

		0x0000,//0x07e0,	// Yo_even
		0x0000,//0x07e0,	// Yo_odd
		0x0129,//0x0110,	// Y_gain

		0x0000,  // sel_RGB
		0x0001,//0x0000,  // sel_Yin_offset
		0x0001,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0001,  // Matrix_bypass
		0x0001,  // Enable_Y_gain



	};

static   unsigned short tRGB2YUV_COEF_601_YCbCr_16_255[] = //for hitachi Japan 20110419
 	{
	// CCIR 601 YCbCr
		0x0000, 	// m11
		0x0000,   // m12
		0x0000,   // m13
		0x0000,   // m21 >> 2
		0x0000,   // m22 >> 1
		0x0000,   // m23 >> 2
		0x0000,   // m31 >> 2
		0x0000,   // m32 >> 2
		0x0000,   // m33 >> 1

		0x07e0, 	// Yo_even
		0x07e0, 	// Yo_odd
		0x010f, 	// Y_gain

		0x0000,  // sel_RGB
		0x0000,  // sel_Yin_offset
		0x0001,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0001,  // Matrix_bypass
		0x0001,  // Enable_Y_gain



	};


static   unsigned short tRGB2YUV_COEF_Input_YCbCr[] =
 	{
	// Input YCbCr to RGB (in RGB2YUV block)
		0x0400, 	// m11 1 		U(11,10)
		0x0000,   // m12 0 		U(10,10)
		0x059b,   // m13 1.402   U(11,10)
		0x0100,   // m21 1		 S(10,8)
		0x0350,   // m22 -0.3441 S(10,9)
		0x014a,   // m23 -0.7141 S(9,8)
		0x0100,   // m31 1		 S(10,8)
		0x01c5,   // m32 1.772	 S(11,8)
		0x0000,   // m33 0		 S(10,9)

		0x0000,  	// Yo_even
		0x0000,  	// Yo_odd
		0x0000,  	// Y_gain
		0x0000,  // sel_RGB
		0x0000,  // sel_Yin_offset
		0x0000,  // sel_UV_out_offset
		0x0000,  // sel_UV_off
		0x0000,  // Matrix_bypass
		0x0000,  // Enable_Y_gain



	};


static   unsigned short tYUV2RGB_COEF_601_YCbCr[] =
 	{

		0x0100, // k11
		0x0166, // k13
		0x0058, // k22
		0x00b6, // k23
		0x01c5, // k32
		0x0000, // R-offset
		0x0000, // G-offset
		0x0000, // B-offset

		0x0001, // Y Clamp (Y-16)
		0x0001, // UV Clamp (UV-512)

 	};

/*static   unsigned short tYUV2RGB_COEF_709_YPbPr[] =
 	{
		0x0100, // k11
		0x0193, // k13
		0x002f, // k22
		0x0077, // k23
		0x01db, // k32
		0x0000, // R-offset
		0x0000, // G-offset
		0x0000, // B-offset

		0x0000, // Y Clamp (Y-16)
		0x0001, // UV Clamp (UV-512)


 	};*/

static  unsigned char tDLTI_COEF[10][9] =
 	{
// unsigned char HF_Enable, unsigned char HF_Th,  unsigned char Gain, unsigned char Gain_th, unsigned char  AdvanceDelay, unsigned char Long, unsigned char Near, unsigned char Contour_enable, unsigned char Contour_th
		{0x01, 0x2A, 0x02, 0x04, 0x00, 0x01, 0x01, 0x01, 0x0A},// 1
		{0x01, 0x2A, 0x02, 0x04, 0x00, 0x01, 0x01, 0x01, 0x0A},	// 2
		{0x01, 0x2A, 0x03, 0x04, 0x00, 0x01, 0x01, 0x01, 0x08},	// 3
		{0x01, 0x2A, 0x04, 0x01, 0x00, 0x01, 0x01, 0x01, 0x04},	// 4
		{0x01, 0x2A, 0x0A, 0x01, 0x00, 0x01, 0x01, 0x01, 0x06},	// 5
		{0x01, 0x2A, 0x0C, 0x04, 0x00, 0x01, 0x01, 0x01, 0x06},	// 6
		{0x01, 0x2A, 0x0D, 0x04, 0x01, 0x01, 0x01, 0x01, 0x03},	// 7
		{0x01, 0x2A, 0x0D, 0x05, 0x01, 0x01, 0x01, 0x01, 0x02},	// 8
		{0x01, 0x2A, 0x0D, 0x06, 0x01, 0x01, 0x01, 0x01, 0x02},	// 9
		{0x01, 0x2A, 0x0D, 0x07, 0x01, 0x01, 0x01, 0x01, 0x02},	// 10

 	};


static  unsigned char tDCTI_COEF[10][6] =
 	{
//	unsigned char Prevent_PE,  unsigned char F_Gain, unsigned char F_th, unsigned char S_DCTI_Enable, unsigned char S_Gain, unsigned char S_Th
		{0x01, 0x00, 0x00, 0x00, 0x00, 0x00},	// 1
		{0x01, 0x03, 0x01, 0x00, 0x00, 0x00},	// 2
		{0x00, 0x06, 0x01, 0x00, 0x00, 0x00},	// 3
		{0x00, 0x09, 0x01, 0x00, 0x00, 0x00},	// 4
		{0x00, 0x0C, 0x01, 0x00, 0x00, 0x00},	// 5
		{0x00, 0x0F, 0x02, 0x00, 0x00, 0x00},	// 6
		{0x00, 0x03, 0x02, 0x01, 0x03, 0x10},	// 7
		{0x00, 0x06, 0x02, 0x01, 0x06, 0x20},	// 8
		{0x00, 0x0A, 0x10, 0x01, 0x0A, 0x30},	// 9
		{0x00, 0x0F, 0x1F, 0x01, 0x0F, 0x3F},	// 10

 	};



static unsigned char tDITHER_SEQUENCE[3][16] = {
	{0xAD, 0x80, 0xE6, 0xA3, 0x9E, 0x47, 0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85},
	{0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85, 0x0A, 0x68, 0x3E, 0xEA, 0x79, 0xD4},
	{0xAD, 0x80, 0xE6, 0xF3, 0xB0, 0x6C, 0x85, 0xEA, 0x79, 0xD4, 0x92, 0x2B, 0x41, 0xC7, 0xF1, 0x35}
	};

static unsigned char tDITHER_TEMPORAL[16] = { 0, 3, 2, 1, 2, 1, 3, 0, 3, 0, 1, 2, 1, 2, 0, 3 };


static unsigned char tDITHER_LUT[3][16][4] = {
	{
		{0x00, 0x30, 0x20, 0x10}, {0x29, 0x19, 0x39, 0x09}, {0x3E, 0x0E, 0x1E, 0x2E}, {0x17, 0x27, 0x07, 0x37},
		{0x0C, 0x3C, 0x2C, 0x1C}, {0x25, 0x15, 0x35, 0x05}, {0x32, 0x02, 0x12, 0x22}, {0x1B, 0x2B, 0x0B, 0x3B},
		{0x08, 0x38, 0x28, 0x18}, {0x2D, 0x1D, 0x3D, 0x0D}, {0x36, 0x06, 0x16, 0x26}, {0x13, 0x23, 0x03, 0x33},
		{0x04, 0x34, 0x24, 0x14}, {0x21, 0x11, 0x31, 0x01}, {0x3A, 0x0A, 0x1A, 0x2A}, {0x1F, 0x2F, 0x0F, 0x3F}
	},
	{
		{0x28, 0x18, 0x38, 0x08}, {0x3D, 0x0D, 0x1D, 0x2D}, {0x16, 0x26, 0x06, 0x36}, {0x03, 0x33, 0x23, 0x13},
		{0x24, 0x14, 0x34, 0x04}, {0x31, 0x01, 0x11, 0x21}, {0x1A, 0x2A, 0x0A, 0x3A}, {0x0F, 0x3F, 0x2F, 0x1F},
		{0x2C, 0x1C, 0x3C, 0x0C}, {0x35, 0x05, 0x15, 0x25}, {0x12, 0x22, 0x02, 0x32}, {0x0B, 0x3B, 0x2B, 0x1B},
		{0x20, 0x10, 0x30, 0x00}, {0x39, 0x09, 0x19, 0x29}, {0x1E, 0x2E, 0x0E, 0x3E}, {0x07, 0x37, 0x27, 0x17},
	},
	{
		{0x3C, 0x0C, 0x1C, 0x2C}, {0x15, 0x25, 0x05, 0x35}, {0x02, 0x32, 0x22, 0x12}, {0x2B, 0x1B, 0x3B, 0x0B},
		{0x30, 0x00, 0x10, 0x20}, {0x19, 0x29, 0x09, 0x39}, {0x0E, 0x3E, 0x2E, 0x1E}, {0x27, 0x17, 0x37, 0x07},
		{0x34, 0x04, 0x14, 0x24}, {0x11, 0x21, 0x01, 0x31}, {0x0A, 0x3A, 0x2A, 0x1A}, {0x2F, 0x1F, 0x3F, 0x0F},
		{0x38, 0x08, 0x18, 0x28}, {0x1D, 0x2D, 0x0D, 0x3D}, {0x06, 0x36, 0x26, 0x16}, {0x23, 0x13, 0x33, 0x03},
	}
	};
#endif




//[mark by crixus-mac3 linux based] wiil add		extern unsigned char RGB2YUV_if_RGB_mode;
#if 0//[mark by crixus-mac3 linux based]
extern "C" HDMI_DVI_MODE_T IsHDMI(void);
#else
extern HDMI_DVI_MODE_T IsHDMI(void);
#endif
/**
 * ColorSpaceTransfer
 * Set Color space rgb2yuv conversion matrix
 * for source CCIR 601 YCbCr: Bypass RGB2YUV
 * for source CCIR 601 RGB: Use Tab-1 as ccir601 RGB2YUV
 * for source CCIR 709 YPbPr: overwrite Tab-2 as ccir709 YPbPr to 601 YCbCr
 * for source CCIR 709 RGB: overwrite Tab-2 as ccir709 RGB to 601 YCbCr
 */
 void I3DDMA_ColorSpacergb2yuvtransfer(unsigned char nSrcType, unsigned char nSD_HD, unsigned char VO_Jpeg_Back_YUV)
{

	unsigned char video_format;
	unsigned char which_color_space = 0;
//	unsigned char temp_value = 0;
	unsigned short *table_index = 0;

	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS  ich2_RGB2YUV_CTRL_REG;


	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m11_m12_RBUS tab2_M11_M12_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m13_m21_RBUS tab2_M13_M21_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m22_m23_RBUS tab2_M22_M23_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m31_m32_RBUS tab2_M31_M32_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m33_ygain_RBUS tab2_M33_YGain_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_yo_RBUS tab2_Yo_REG;


        //[mark by crixus-mac3 linux based] wiil add		RGB2YUV_if_RGB_mode = FALSE;



	ich2_RGB2YUV_CTRL_REG.regValue = IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);

	//ich2_RGB2YUV_CTRL_REG.sel_table = 1;
	ich2_RGB2YUV_CTRL_REG.en_rgb2yuv= 0;

	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, ich2_RGB2YUV_CTRL_REG.regValue);

	//which_tab = 2;




	if (nSrcType == _SRC_VGA) {
		table_index = tRGB2YUV_COEF_601_RGB_0_255;

		//[mark by crixus-mac3 linux based] wiil add		RGB2YUV_if_RGB_mode = TRUE;

	} else if (nSrcType == _SRC_YPBPR) {
		if(!nSD_HD)
		{
			table_index = tRGB2YUV_COEF_601_YCbCr_0_255;
		}
		else
		{
			table_index = tRGB2YUV_COEF_709_YUV_0_255;
		}
	}
#ifdef CONFIG_INPUT_SOURCE_IPG
	else if (nSrcType == _SRC_IPG) {
		if(!nSD_HD)
		{
			table_index = tRGB2YUV_COEF_601_YCbCr_0_255;
		}
		else
		{
			table_index = tRGB2YUV_COEF_709_YUV_0_255;
		}
		}
#endif
#if 1//def CONFIG_TV_ENABLE
	else if(nSrcType == _SRC_TV) {
		//table_index = tRGB2YUV_COEF_601_YCbCr_16_235;
		table_index = tRGB2YUV_COEF_601_YCbCr_0_255;

	}
#endif

        else if((nSrcType == _SRC_CVBS) || (nSrcType == _SRC_SV) || (nSrcType  == _SRC_COMPONENT)
#if 1//def CONFIG_SCART_ENABLE
		|| (nSrcType == _SRC_SCART) || (nSrcType == _SRC_SCART_RGB)
#endif
		){
		//table_index = tRGB2YUV_COEF_601_YCbCr_16_235;
		table_index = tRGB2YUV_COEF_601_YCbCr_0_255;

	}
        else if (nSrcType == _SRC_HDMI) {

		//read HDMI color space and info
		/* //Thur modified for compile 20090113
		***********Must Check Here ¡I¡I¡I¡I¡I¡I**********************
		video_format = IoReg_ReadByte0(HDMI_HDMI_ACRCR_RO_VADDR);
		IoReg_Write32(HDMI_HDMI_PSAPR_VADDR, 0x05);
		temp_value =  IoReg_ReadByte0(HDMI_HDMI_PSDPR_D_VADDR);
		*/
		//***********Must Check Here ¡I¡I¡I¡I¡I¡I**********************
		video_format = drvif_Hdmi_GetColorSpace();

		//modified since Darwin, so marked by nick187 @20101223
/*

			IoReg_Write32(HDMI_HDMI_PSAP_VADDR, 0x05);
			temp_value =  IoReg_ReadByte0(HDMI_HDMI_PSDP_VADDR);
*/
		/*HDMI_RGB_YUV_RANGE_MODE_T yuv_range;
		yuv_range = drvif_IsRGB_YUV_RANGE();
		if(yuv_range == MODE_RAG_LIMIT) { // CCIR 601
			which_color_space = 1;
		} else if(yuv_range == MODE_RAG_FULL) { // CCIR 709
			which_color_space = 2;
		}*/
		if(drvif_IsHDMI()&&(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_MODECURR) !=_MODE_NEW)) // HDMI Video Mode,  gary for xoceco 20071227
		{
			if(video_format != 0 ) { //YUV444 or YUV422
				/* mark due to only need SD/HD detection
				if(which_color_space == 1)
				{
					table_index = tRGB2YUV_COEF_601_YCbCr_0_255;//tRGB2YUV_COEF_601_YCbCr_16_235;//for JP inhouse demotRGB2YUV_COEF_601_YCbCr_16_235;
				}
				else if(which_color_space == 2)
				{
					table_index = tRGB2YUV_COEF_709_YUV_0_255;//tRGB2YUV_COEF_709_YUV_16_235;//for JP inhouse demo
				}
				else */
				{

					 // modified by Jerry Wu 20080516 for solve hdmi color space input detect error
					if(!nSD_HD)
					{
						table_index = tRGB2YUV_COEF_601_YCbCr_0_255;//tRGB2YUV_COEF_601_YCbCr_16_235;//for JP inhouse demo
					}
					else
					{
						table_index = tRGB2YUV_COEF_709_YUV_0_255;//tRGB2YUV_COEF_601_YCbCr_16_235;//for JP inhouse demo
					}
				}
					pr_debug("RGB2YUV_SRC_HDMI_YUV\n");
			} else {//RGB

				//[mark by crixus-mac3 linux based] wiil add		RGB2YUV_if_RGB_mode = TRUE;
				/*if(which_color_space == 1)
				{
					table_index =tRGB2YUV_COEF_601_RGB_0_255; //tRGB2YUV_COEF_601_RGB_16_235; modify by Jerry 20080317
				}
				else if(which_color_space == 2)
				{
					table_index =tRGB2YUV_COEF_709_RGB_0_255; //tRGB2YUV_COEF_709_RGB_16_235; modify by Jerry 20080317
				}
				else
					//table_index = tRGB2YUV_COEF_709_RGB_0_255;  //tRGB2YUV_COEF_709_RGB_16_235; modify by Jerry 20080317
				*/
				{ 	 // modified by Jerry Wu 20080516 for solve hdmi color space input detect error

					 if(!nSD_HD)
					 {
						table_index = tRGB2YUV_COEF_601_RGB_0_255;
					 }
					else
					{
						table_index = tRGB2YUV_COEF_709_RGB_0_255;
					}
				}

					pr_debug("RGB2YUV_SRC_HDMI_RGB\n");
			}

		}
		else // DVI mode
		{
			if((video_format&(_BIT4|_BIT5)) ) { //YUV444 or YUV422

				if(which_color_space == 1)//20071107 gary for HDMI gray saturation
					table_index =tRGB2YUV_COEF_601_YCbCr_0_255;
				else if(which_color_space == 2)
					table_index = tRGB2YUV_COEF_709_YUV_0_255;
				else
					table_index = tRGB2YUV_COEF_709_YUV_0_255;

					//printk("RGB2YUV_SRC_HDMI_YUV\n");
			} else {//RGB
				//[mark by crixus-mac3 linux based] wiil add		RGB2YUV_if_RGB_mode = TRUE;
				if(which_color_space == 1)
					table_index =tRGB2YUV_COEF_601_RGB_0_255;
				else if(which_color_space == 2)
					table_index = tRGB2YUV_COEF_709_RGB_0_255;
				else
				{
					table_index = tRGB2YUV_COEF_709_RGB_0_255;
				}

					pr_debug("RGB2YUV_SRC_DVI_RGB\n");
			}

		}


			//printk("RGB2YUV_SRC_FROM_HDMI\n");
	}
  else if ( nSrcType == _SRC_VO )
  {
		// GAME source must enter RGB to YUV
		if (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane())==2 )
    		{
			if(!nSD_HD)
				table_index = tRGB2YUV_COEF_601_RGB_0_255;
			else
				table_index = tRGB2YUV_COEF_709_RGB_0_255;
		}
    	else if(Scaler_VOFrom(Scaler_Get_CurVoInfo_plane())==0  ) // DTV source
    	{
			/* chang by frank@0305*/
			if(!nSD_HD)
			{
			//frank@20100601 solve mantice26967 to show red word on white board
			//	table_index = tRGB2YUV_COEF_601_YCbCr_16_235;
				table_index = tRGB2YUV_COEF_601_YCbCr_0_255;

			}
			else
			{
			//frank@20100601 solve mantice26967 to show red word on white board
			//	table_index = tRGB2YUV_COEF_709_YUV_16_235;
				table_index = tRGB2YUV_COEF_709_YUV_0_255;
			}
		}
		else  //Jpeg source
		{
/*
			if(VO_Jpeg_Back_YUV)//20100413 set Jpeg 2 mode.  March
			{
				table_index = tRGB2YUV_COEF_601_RGB_0_255;
			}
			else
			{
				table_index = tRGB2YUV_COEF_Input_YCbCr;
			}
*/
			// 20110711 Since Darwin. No longer use VGE for scene-change-effect (M-domain VGE at Atlantic adopts RGB)
			table_index = tRGB2YUV_COEF_601_YCbCr_0_255;
		}
  	}
  else
  {
		//which_tab = 0;
		pr_debug("unhandler type%d\n", nSrcType);
		return;
	}



		 //sub  all tab-2
		tab2_M11_M12_REG.m11 = table_index [_RGB2YUV_m11];
		tab2_M11_M12_REG.m12 = table_index [_RGB2YUV_m12];
		IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg, tab2_M11_M12_REG.regValue);

		tab2_M13_M21_REG.m13 = table_index [_RGB2YUV_m13];
		tab2_M13_M21_REG.m21 = table_index [_RGB2YUV_m21];
		IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M13_M21_reg, tab2_M13_M21_REG.regValue);

		tab2_M22_M23_REG.m22 = table_index [_RGB2YUV_m22];
		tab2_M22_M23_REG.m23 = table_index [_RGB2YUV_m23];
		IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M22_M23_reg, tab2_M22_M23_REG.regValue);

		tab2_M31_M32_REG.m31 = table_index [_RGB2YUV_m31];
		tab2_M31_M32_REG.m32 = table_index [_RGB2YUV_m32];
		IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg, tab2_M31_M32_REG.regValue);

		tab2_M33_YGain_REG.m33 = table_index [_RGB2YUV_m33];
		tab2_M33_YGain_REG.y_gain= table_index [_RGB2YUV_Y_gain];
		IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M33_YGain_reg, tab2_M33_YGain_REG.regValue);

		//tab2_Yo_and_Y_Gain_REG.yo_even= table_index [_RGB2YUV_Yo_even];
		//tab2_Yo_and_Y_Gain_REG.yo_odd= table_index [_RGB2YUV_Yo_odd];
		tab2_Yo_REG.yo_odd= table_index [_RGB2YUV_Yo_odd];
		IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg, tab2_Yo_REG.regValue);

#if 1
		ich2_RGB2YUV_CTRL_REG.sel_rgb= table_index [_RGB2YUV_sel_RGB];
		ich2_RGB2YUV_CTRL_REG.set_r_in_offset= table_index [_RGB2YUV_set_Yin_offset];
		ich2_RGB2YUV_CTRL_REG.set_uv_out_offset= table_index [_RGB2YUV_set_UV_out_offset];
		ich2_RGB2YUV_CTRL_REG.sel_uv_off= table_index [_RGB2YUV_sel_UV_off];
		ich2_RGB2YUV_CTRL_REG.matrix_bypass= table_index [_RGB2YUV_Matrix_bypass];
		ich2_RGB2YUV_CTRL_REG.sel_y_gain= table_index [_RGB2YUV_Enable_Y_gain];

		//ich2_RGB2YUV_CTRL_REG.sel_table= 1;
		ich2_RGB2YUV_CTRL_REG.en_rgb2yuv = 1;

// 20110711 Since Darwin. No longer use VGE for scene-change-effect (M-domain VGE at Atlantic adopts RGB)
//		if(table_index == tRGB2YUV_COEF_Input_YCbCr ) // 20100412 expertment code  March
//			ich1_RGB2YUV_CTRL_REG.en_rgb2yuv = 2;


		IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, ich2_RGB2YUV_CTRL_REG.regValue);

	#endif

}

/*move from sirius @Crixus 20150331*/
void I3DDMA_color_colorspacergb2yuvtransfer_dispDtoI3ddma(IDMA_DISPD_CAPTURE_INFO cap_info)
{
	unsigned short *table_index = 0;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS  i3ddma_rgb2yuv_ctrl_reg;
	//i3ddma_rgb2yuv_tab1_m1_RBUS i3ddma_rgb2yuv_tab1_m1_reg;
	//i3ddma_rgb2yuv_tab1_m2_RBUS i3ddma_rgb2yuv_tab1_m2_reg;
	//i3ddma_rgb2yuv_tab1_m3_RBUS i3ddma_rgb2yuv_tab1_m3_reg;
	//i3ddma_rgb2yuv_tab1_y_RBUS i3ddma_rgb2yuv_tab1_y_reg;
	//display_timing_ctrl2_RBUS display_timing_ctrl2_reg;

	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m11_m12_RBUS tab2_M11_M12_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m13_m21_RBUS tab2_M13_M21_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m22_m23_RBUS tab2_M22_M23_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m31_m32_RBUS tab2_M31_M32_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m33_ygain_RBUS tab2_M33_YGain_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_yo_RBUS tab2_Yo_REG;

	// IDMA VGIP DispD input source select
	//display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_DISPLAY_TIMING_CTRL2_VADDR);
	//display_timing_ctrl2_reg.d2i3ddma_src_sel = cap_info.capSrc;
	//IoReg_Write32(PPOVERLAY_DISPLAY_TIMING_CTRL2_VADDR, display_timing_ctrl2_reg.regValue);
#if 0
	switch(idmaDispD_in_sel)
	{
	    case CAP_SRC_SUBTITLE:
	        //table_index = tRGB2YUV_COEF_709_RGB_0_255_SUB_OSD_MIXER1;
	        table_index = tRGB2YUV_COEF_709_RGB_0_255;
	        break;
	    case CAP_SRC_OSD:
	    case CAP_SRC_DITHER:
	        //table_index = tRGB2YUV_COEF_709_RGB_0_255_OSD_MIXER2;
	        table_index = tRGB2YUV_COEF_709_RGB_0_255;
	        break;
	    default:
	        table_index = tRGB2YUV_COEF_709_RGB_0_255;
	        break;
	}
	#endif

//#ifdef ENABLE_DTV_SCART_OUT
	table_index = tRGB2YUV_COEF_709_RGB_0_255;
//#else
//	if(cap_info.capLen <720 && cap_info.capWid < 1280)
//     		table_index = tRGB2YUV_COEF_TVE_SD_0_255;
//	else
//		table_index = tRGB2YUV_COEF_TVE_HD_0_255;
//#endif

#if 0
	//main  all tab-1
	i3ddma_rgb2yuv_tab1_m1_reg.m11 = table_index [_RGB2YUV_m11];
	i3ddma_rgb2yuv_tab1_m1_reg.m12 = table_index [_RGB2YUV_m12];
	i3ddma_rgb2yuv_tab1_m1_reg.m13 = table_index [_RGB2YUV_m13];
	printf("i3ddma_rgb2yuv_tab1_m1_reg.regValue = %x\n", i3ddma_rgb2yuv_tab1_m1_reg.regValue);
	IoReg_Write32(I3DDMA_RGB2YUV_TAB1_M1_VADDR, i3ddma_rgb2yuv_tab1_m1_reg.regValue);

	i3ddma_rgb2yuv_tab1_m2_reg.m21 = table_index [_RGB2YUV_m21];
	i3ddma_rgb2yuv_tab1_m2_reg.m22 = table_index [_RGB2YUV_m22];
	i3ddma_rgb2yuv_tab1_m2_reg.m23 = table_index [_RGB2YUV_m23];
	i3ddma_rgb2yuv_tab1_m2_reg.res1 = 0;
	printf("i3ddma_rgb2yuv_tab1_m2_reg.regValue = %x\n", i3ddma_rgb2yuv_tab1_m2_reg.regValue);
	IoReg_Write32(I3DDMA_RGB2YUV_TAB1_M2_VADDR, i3ddma_rgb2yuv_tab1_m2_reg.regValue);

	i3ddma_rgb2yuv_tab1_m3_reg.m31 = table_index [_RGB2YUV_m31];
	i3ddma_rgb2yuv_tab1_m3_reg.m32 = table_index [_RGB2YUV_m32];
	i3ddma_rgb2yuv_tab1_m3_reg.m33 = table_index [_RGB2YUV_m33];
	printf("i3ddma_rgb2yuv_tab1_m3_reg.regValue = %x\n", i3ddma_rgb2yuv_tab1_m3_reg.regValue);
	IoReg_Write32(I3DDMA_RGB2YUV_TAB1_M3_VADDR, i3ddma_rgb2yuv_tab1_m3_reg.regValue);

	i3ddma_rgb2yuv_tab1_y_reg.yo= table_index [_RGB2YUV_Yo_odd];
	i3ddma_rgb2yuv_tab1_y_reg.yo_gain= table_index [_RGB2YUV_Y_gain];
	printf("i3ddma_rgb2yuv_tab1_y_reg.regValue = %x\n", i3ddma_rgb2yuv_tab1_y_reg.regValue);
	IoReg_Write32(I3DDMA_RGB2YUV_TAB1_Y_VADDR, i3ddma_rgb2yuv_tab1_y_reg.regValue);
#endif
	 //sub  all tab-2
	tab2_M11_M12_REG.m11 = table_index [_RGB2YUV_m11];
	tab2_M11_M12_REG.m12 = table_index [_RGB2YUV_m12];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg, tab2_M11_M12_REG.regValue);

	tab2_M13_M21_REG.m13 = table_index [_RGB2YUV_m13];
	tab2_M13_M21_REG.m21 = table_index [_RGB2YUV_m21];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M13_M21_reg, tab2_M13_M21_REG.regValue);

	tab2_M22_M23_REG.m22 = table_index [_RGB2YUV_m22];
	tab2_M22_M23_REG.m23 = table_index [_RGB2YUV_m23];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M22_M23_reg, tab2_M22_M23_REG.regValue);

	tab2_M31_M32_REG.m31 = table_index [_RGB2YUV_m31];
	tab2_M31_M32_REG.m32 = table_index [_RGB2YUV_m32];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg, tab2_M31_M32_REG.regValue);

	tab2_M33_YGain_REG.m33 = table_index [_RGB2YUV_m33];
	tab2_M33_YGain_REG.y_gain= table_index [_RGB2YUV_Y_gain];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M33_YGain_reg, tab2_M33_YGain_REG.regValue);

	//tab2_Yo_and_Y_Gain_REG.yo_even= table_index [_RGB2YUV_Yo_even];
	//tab2_Yo_and_Y_Gain_REG.yo_odd= table_index [_RGB2YUV_Yo_odd];
	tab2_Yo_REG.yo_odd= table_index [_RGB2YUV_Yo_odd];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg, tab2_Yo_REG.regValue);


	i3ddma_rgb2yuv_ctrl_reg.regValue = IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);

	i3ddma_rgb2yuv_ctrl_reg.sel_rgb= table_index [_RGB2YUV_sel_RGB];
	i3ddma_rgb2yuv_ctrl_reg.set_r_in_offset= table_index [_RGB2YUV_set_Yin_offset];
	i3ddma_rgb2yuv_ctrl_reg.set_uv_out_offset= table_index [_RGB2YUV_set_UV_out_offset];
	i3ddma_rgb2yuv_ctrl_reg.sel_uv_off= table_index [_RGB2YUV_sel_UV_off];
	i3ddma_rgb2yuv_ctrl_reg.matrix_bypass= table_index [_RGB2YUV_Matrix_bypass];
	i3ddma_rgb2yuv_ctrl_reg.sel_y_gain= table_index [_RGB2YUV_Enable_Y_gain];

	//i3ddma_rgb2yuv_ctrl_reg.idmaDispD_in_sel = idmaDispD_in_sel;
	if(cap_info.capSrc== CAP_SRC_UZU)
		i3ddma_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
	else
		i3ddma_rgb2yuv_ctrl_reg.en_rgb2yuv = 1;

	pr_debug("[IVI] rgb2yuv=%d\n", i3ddma_rgb2yuv_ctrl_reg.en_rgb2yuv);

	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_ctrl_reg.regValue);

	return;
}




