/*
#include <string.h>

// some include about AP
#include <Platform_Lib/TVScalerControl/scaler/scalerLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerColorLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerTimer.h>
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>

// some include about VIP Driver
#include <Platform_Lib/TVScalerControl/vip/scalerColor.h>
#include <Platform_Lib/TVScalerControl/vip/di_ma.h>
#include <Platform_Lib/TVScalerControl/vip/peaking.h>
#include <Platform_Lib/TVScalerControl/vip/icm.h>
#include <Platform_Lib/TVScalerControl/vip/dcc.h>
#include <Platform_Lib/TVScalerControl/vip/ultrazoom.h>
#include <Platform_Lib/TVScalerControl/vip/color.h>
#include <Platform_Lib/TVScalerControl/vip/xc.h>
#include <Platform_Lib/TVScalerControl/vip/intra.h>
#include <Platform_Lib/TVScalerControl/vip/nr.h>
#include <Platform_Lib/TVScalerControl/vip/film.h>
#include <Platform_Lib/TVScalerControl/vip/pq_adaptive.h>
#include <Platform_Lib/TVScalerControl/vip/gibi_od.h>
#include <Platform_Lib/TVScalerControl/vdc/video.h>
#include "Platform_Lib/TVScalerControl/scaler/scalerSuperResolution.h"

// some include about scaler
#include <scaler/scalerDrvCommon.h>
#include <rbusHistogramReg.h>

// some include about rbus
#include <rbusVDTopReg.h>
#include <rbusScaledownReg.h>
#include <rbusSRGBReg.h>

// some include about device driver
#include <Platform_Lib/TVScalerControl/hdmiRx/hdmiFun.h>
*/
#include <linux/string.h>
//#include <mach/io.h>

#include <tvscalercontrol/scaler/scalerstruct.h>
#include <rbus/memc_mux_reg.h>
#include <tvscalercontrol/vip/memc_mux.h>
#include <tvscalercontrol/vip/color.h>

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

#ifdef CONFIG_HW_SUPPORT_MEMC
static unsigned char tDITHER_SEQUENCE[3][16] = {
	{0xAD, 0x80, 0xE6, 0xA3, 0x9E, 0x47, 0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85},
	{0x2D, 0xB9, 0x12, 0x74, 0x1C, 0x5F, 0xF3, 0xB0, 0x6C, 0x85, 0x0A, 0x68, 0x3E, 0xEA, 0x79, 0xD4},
	{0xAD, 0x80, 0xE6, 0xF3, 0xB0, 0x6C, 0x85, 0xEA, 0x79, 0xD4, 0x92, 0x2B, 0x41, 0xC7, 0xF1, 0x35}
	};

/*static unsigned char tDITHER_TEMPORAL[16] = { 0, 3, 2, 1, 2, 1, 3, 0, 3, 0, 1, 2, 1, 2, 0, 3 };*/
static unsigned char tDITHER_TEMPORAL[16] = { 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3 };

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

void drvif_memc_mux_en(bool enable)
{
	memc_mux_memc_mux_func_ctrl_RBUS color_temp_ctrl_reg;
	color_temp_ctrl_reg.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg);
	color_temp_ctrl_reg.memc_mux_en = enable;
	rtd_outl(MEMC_MUX_MEMC_MUX_FUNC_CTRL_reg, color_temp_ctrl_reg.regValue);
}

void drvif_memc_mux_Dither_ctrl(bool enable, bool temp_en)
{
	memc_mux_memc_mux_di_ctrl_RBUS color_temp_ctrl_reg;
	color_temp_ctrl_reg.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_DI_CTRL_reg);
	color_temp_ctrl_reg.function_enable = enable;
	color_temp_ctrl_reg.temporal_enable = temp_en;
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_CTRL_reg, color_temp_ctrl_reg.regValue);

}

void drvif_memc_mux_in_CSC_ctrl(bool enable)
{
	memc_mux_memc_mux_in_rgb2yuv_ctrl_RBUS color_temp_ctrl_reg;
	color_temp_ctrl_reg.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_IN_RGB2YUV_CTRL_reg);
	color_temp_ctrl_reg.en_rgb2yuv = enable;
	rtd_outl(MEMC_MUX_MEMC_MUX_IN_RGB2YUV_CTRL_reg, color_temp_ctrl_reg.regValue);

}

void drvif_memc_mux_out_CSC_ctrl(bool enable)
{
	memc_mux_memc_mux_out_rgb2yuv_ctrl_RBUS color_temp_ctrl_reg;
	color_temp_ctrl_reg.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_OUT_RGB2YUV_CTRL_reg);
	color_temp_ctrl_reg.en_rgb2yuv = enable;
	rtd_outl(MEMC_MUX_MEMC_MUX_OUT_RGB2YUV_CTRL_reg, color_temp_ctrl_reg.regValue);

}

void drvif_memc_mux_in_CSC_int(bool enable)
{
	memc_mux_memc_mux_in_rgb2yuv_ctrl_RBUS memc_mux_memc_mux_in_rgb2yuv_ctrl_REG;
	memc_mux_memc_mux_in_tab1_m11_m12_RBUS memc_mux_memc_mux_in_tab1_m11_m12_REG;
	memc_mux_memc_mux_in_tab1_m13_m21_RBUS memc_mux_memc_mux_in_tab1_m13_m21_REG;
	memc_mux_memc_mux_in_tab1_m22_m23_RBUS memc_mux_memc_mux_in_tab1_m22_m23_REG;
	memc_mux_memc_mux_in_tab1_m31_m32_RBUS memc_mux_memc_mux_in_tab1_m31_m32_REG;
	memc_mux_memc_mux_in_tab1_m33_y_gain_RBUS memc_mux_memc_mux_in_tab1_m33_y_gain_REG;

	memc_mux_memc_mux_in_rgb2yuv_ctrl_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_IN_RGB2YUV_CTRL_reg);
	memc_mux_memc_mux_in_tab1_m11_m12_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_IN_Tab1_M11_M12_reg);
	memc_mux_memc_mux_in_tab1_m13_m21_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_IN_Tab1_M13_M21_reg);
	memc_mux_memc_mux_in_tab1_m22_m23_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_IN_Tab1_M22_M23_reg);
	memc_mux_memc_mux_in_tab1_m31_m32_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_IN_Tab1_M31_M32_reg);
	memc_mux_memc_mux_in_tab1_m33_y_gain_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_IN_Tab1_M33_Y_Gain_reg);
	// set RGB2YUV ctrl
	memc_mux_memc_mux_in_rgb2yuv_ctrl_REG.sel_rgb=1;
	memc_mux_memc_mux_in_rgb2yuv_ctrl_REG.set_uv_out_offset=1;
	// set RGB2YUV matrix
	memc_mux_memc_mux_in_tab1_m11_m12_REG.m11 = 0x04C8;
	memc_mux_memc_mux_in_tab1_m11_m12_REG.m12 = 0x0964;
	memc_mux_memc_mux_in_tab1_m13_m21_REG.m13 = 0x01D3;
	memc_mux_memc_mux_in_tab1_m13_m21_REG.m21 = 0x7D4D;
	memc_mux_memc_mux_in_tab1_m22_m23_REG.m22 = 0x7AB3;
	memc_mux_memc_mux_in_tab1_m22_m23_REG.m23 = 0x0800;
	memc_mux_memc_mux_in_tab1_m31_m32_REG.m31 = 0x0800;
	memc_mux_memc_mux_in_tab1_m31_m32_REG.m32 = 0x794D;
	memc_mux_memc_mux_in_tab1_m33_y_gain_REG.m33 = 0x7EB3;
	memc_mux_memc_mux_in_tab1_m33_y_gain_REG.yo_gain = 0x12A;

	rtd_outl(MEMC_MUX_MEMC_MUX_IN_RGB2YUV_CTRL_reg, memc_mux_memc_mux_in_rgb2yuv_ctrl_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_IN_Tab1_M11_M12_reg, memc_mux_memc_mux_in_tab1_m11_m12_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_IN_Tab1_M13_M21_reg, memc_mux_memc_mux_in_tab1_m13_m21_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_IN_Tab1_M22_M23_reg, memc_mux_memc_mux_in_tab1_m22_m23_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_IN_Tab1_M31_M32_reg, memc_mux_memc_mux_in_tab1_m31_m32_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_IN_Tab1_M33_Y_Gain_reg, memc_mux_memc_mux_in_tab1_m33_y_gain_REG.regValue);
}

void drvif_memc_mux_out_CSC_int(bool enable)
{
	memc_mux_memc_mux_out_rgb2yuv_ctrl_RBUS memc_mux_memc_mux_out_rgb2yuv_ctrl_REG;
	memc_mux_memc_mux_out_tab1_m11_m12_RBUS memc_mux_memc_mux_out_tab1_m11_m12_REG;
	memc_mux_memc_mux_out_tab1_m13_m21_RBUS memc_mux_memc_mux_out_tab1_m13_m21_REG;
	memc_mux_memc_mux_out_tab1_m22_m23_RBUS memc_mux_memc_mux_out_tab1_m22_m23_REG;
	memc_mux_memc_mux_out_tab1_m31_m32_RBUS memc_mux_memc_mux_out_tab1_m31_m32_REG;
	memc_mux_memc_mux_out_tab1_m33_y_gain_RBUS memc_mux_memc_mux_out_tab1_m33_y_gain_REG;

	memc_mux_memc_mux_out_rgb2yuv_ctrl_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_OUT_RGB2YUV_CTRL_reg);
	memc_mux_memc_mux_out_tab1_m11_m12_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M11_M12_reg);
	memc_mux_memc_mux_out_tab1_m13_m21_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M13_M21_reg);
	memc_mux_memc_mux_out_tab1_m22_m23_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M22_M23_reg);
	memc_mux_memc_mux_out_tab1_m31_m32_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M31_M32_reg);
	memc_mux_memc_mux_out_tab1_m33_y_gain_REG.regValue = rtd_inl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M33_Y_Gain_reg);
	// set YUV2RGB ctrl
	memc_mux_memc_mux_out_rgb2yuv_ctrl_REG.sel_rgb=0;
	memc_mux_memc_mux_out_rgb2yuv_ctrl_REG.set_uv_out_offset=0;
	// set YUV2RGB matrix
	memc_mux_memc_mux_out_tab1_m11_m12_REG.m11 = 0x1000;
	memc_mux_memc_mux_out_tab1_m11_m12_REG.m12 = 0x0000;
	memc_mux_memc_mux_out_tab1_m13_m21_REG.m13 = 0x166E;
	memc_mux_memc_mux_out_tab1_m13_m21_REG.m21 = 0x1000;
	memc_mux_memc_mux_out_tab1_m22_m23_REG.m22 = 0x7A7F;
	memc_mux_memc_mux_out_tab1_m22_m23_REG.m23 = 0x7493;
	memc_mux_memc_mux_out_tab1_m31_m32_REG.m31 = 0x1000;
	memc_mux_memc_mux_out_tab1_m31_m32_REG.m32 = 0x1C5A;
	memc_mux_memc_mux_out_tab1_m33_y_gain_REG.m33 = 0x0000;
	memc_mux_memc_mux_out_tab1_m33_y_gain_REG.yo_gain = 0x12A;

	rtd_outl(MEMC_MUX_MEMC_MUX_OUT_RGB2YUV_CTRL_reg, memc_mux_memc_mux_out_rgb2yuv_ctrl_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M11_M12_reg, memc_mux_memc_mux_out_tab1_m11_m12_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M13_M21_reg, memc_mux_memc_mux_out_tab1_m13_m21_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M22_M23_reg, memc_mux_memc_mux_out_tab1_m22_m23_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M31_M32_reg, memc_mux_memc_mux_out_tab1_m31_m32_REG.regValue);
	rtd_outl(MEMC_MUX_MEMC_MUX_OUT_Tab1_M33_Y_Gain_reg, memc_mux_memc_mux_out_tab1_m33_y_gain_REG.regValue);
}


void drvif_memc_mux_setdithering(unsigned char DI_Bit)   // parameter DI_Bit=2 , 12->10 bit dithering
{

	memc_mux_memc_mux_di_ctrl_RBUS dithering_ctrl_reg;

/*	dithering_SEQUENCE_TABLE_Red_00_07_RBUS	dithering_SEQUENCE_TABLE_Red_00_07_reg;*/
/*	dithering_SEQUENCE_TABLE_Red_08_15_RBUS	dithering_SEQUENCE_TABLE_Red_08_15_reg;*/
/*	dithering_SEQUENCE_TABLE_Red_16_23_RBUS	dithering_SEQUENCE_TABLE_Red_16_23_reg;*/
/*	dithering_SEQUENCE_TABLE_Red_24_31_RBUS	dithering_SEQUENCE_TABLE_Red_24_31_reg;*/
/**/
/*	dithering_SEQUENCE_TABLE_Green_00_07_RBUS	dithering_SEQUENCE_TABLE_Green_00_07_reg;*/
/*	dithering_SEQUENCE_TABLE_Green_08_15_RBUS	dithering_SEQUENCE_TABLE_Green_08_15_reg;*/
/*	dithering_SEQUENCE_TABLE_Green_16_23_RBUS	dithering_SEQUENCE_TABLE_Green_16_23_reg;*/
/*	dithering_SEQUENCE_TABLE_Green_24_31_RBUS	dithering_SEQUENCE_TABLE_Green_24_31_reg;*/
/**/
/*	dithering_SEQUENCE_TABLE_Blue_00_07_RBUS	dithering_SEQUENCE_TABLE_Blue_00_07_reg;*/
/*	dithering_SEQUENCE_TABLE_Blue_08_15_RBUS	dithering_SEQUENCE_TABLE_Blue_08_15_reg;*/
/*	dithering_SEQUENCE_TABLE_Blue_16_23_RBUS	dithering_SEQUENCE_TABLE_Blue_16_23_reg;*/
/*	dithering_SEQUENCE_TABLE_Blue_24_31_RBUS	dithering_SEQUENCE_TABLE_Blue_24_31_reg;*/

	memc_mux_memc_mux_di_temporal_offset_RBUS temporal_offset_reg;


	unsigned int dither_32BIT_DATA = 0;
	unsigned short ii, jj, kk, data_shift = 0;
	unsigned short seq_table_num , tab_shift;

	/*printf( "Panel_Dither_bit = %d\n\n\n\n\n\n\n\n\n\n", DI_Bit);*/

	if (DI_Bit == 3) {/*panel 12bit*/
		dithering_ctrl_reg.function_enable = 0;
		rtd_outl(MEMC_MUX_MEMC_MUX_DI_CTRL_reg, dithering_ctrl_reg.regValue);
		return;
	}

	for(seq_table_num = 0; seq_table_num < 2; seq_table_num++)
	{
		tab_shift = (seq_table_num==0)?0:0xf4;
		for (ii = 0; ii < 3; ii++) {/* rgb order*/

			for (jj = 0; jj < 16; jj++) {
				if ((jj == 0) || (jj == 4) || (jj == 8) || (jj == 12)) {
					dither_32BIT_DATA = 0;
					data_shift = 0;
				}

				/* KWarning: checked ok by allen_zhang*/
				//if(seq_table_num==0)
					dither_32BIT_DATA += tDITHER_SEQUENCE[ii][jj] << data_shift ;
				//else
				//	dither_32BIT_DATA += tDITHER_SEQUENCE[ii][jj] << data_shift ;   //different 2nd Dither_sequence table write here
				data_shift += 8;

				if (jj == 3) {
					switch (ii) {
					case 0:/* red*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_00_07_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 1:/* green*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_00_07_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 2:/* blue*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_00_07_reg+tab_shift, dither_32BIT_DATA);
							break;
					}

				}

				if (jj == 7) {
					switch (ii) {
					case 0:/* red*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_08_15_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 1:/* green*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_08_15_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 2:/* blue*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_08_15_reg+tab_shift, dither_32BIT_DATA);
							break;
					}

				}
				if (jj == 11) {
					switch (ii) {
					case 0:/* red*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_16_23_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 1:/* green*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_16_23_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 2:/* blue*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_16_23_reg+tab_shift, dither_32BIT_DATA);
							break;
					}

				}
				if (jj == 15) {
					switch (ii) {
					case 0:/* red*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Red_24_31_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 1:/* green*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Green_24_31_reg+tab_shift, dither_32BIT_DATA);
							break;
					case 2:/* blue*/
							rtd_outl(MEMC_MUX_MEMC_MUX_DI_SEQUENCE_TABLE_Blue_24_31_reg+tab_shift, dither_32BIT_DATA);
							break;
					}

				}


			}
		}
	}

	for (ii = 0; ii < VIP_DITHERLUT_ROW_MAX; ii++) {
		for (jj = 0; jj < VIP_DITHERLUT_COL_MAX; jj++) {

			dither_32BIT_DATA = 0;
			data_shift = 0;

			for (kk = 0; kk < VIP_DITHERLUT_DEP_MAX; kk++) {
				/* KWarning: checked ok by allen_zhang*/
				dither_32BIT_DATA += (tDITHER_LUT[ii][jj][kk] >> (DI_Bit*2)) << data_shift;
				data_shift += 6;
			}

			switch (ii) {
			case 0: /* red*/
					rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Red_00_reg+4*jj, dither_32BIT_DATA);
					break;
			case 1: /* green*/
					rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Green_00_reg+4*jj, dither_32BIT_DATA);
					break;
			case 2: /* blue*/
					rtd_outl(MEMC_MUX_MEMC_MUX_DI_Memc_Mux_Dither_TABLE_Blue_00_reg+4*jj, dither_32BIT_DATA);
					break;
			}
		}
	}


	dither_32BIT_DATA = 0;

	for (ii = 0; ii < 16; ii++) {
		dither_32BIT_DATA += tDITHER_TEMPORAL[ii] << (ii * 2);
	}

	temporal_offset_reg.regValue = dither_32BIT_DATA;
	rtd_outl(MEMC_MUX_MEMC_MUX_DI_Temporal_offset_reg, temporal_offset_reg.regValue);

	dithering_ctrl_reg.regValue = 0;
	dithering_ctrl_reg.function_enable = 1;
	dithering_ctrl_reg.temporal_enable = 1;
	#if defined(CONFIG_PANEL_TPT_216B1)
	dithering_ctrl_reg.temporal_enable = 0; /*fix noise bug*/
	#endif

	rtd_outl(MEMC_MUX_MEMC_MUX_DI_CTRL_reg, dithering_ctrl_reg.regValue);

}



#endif

