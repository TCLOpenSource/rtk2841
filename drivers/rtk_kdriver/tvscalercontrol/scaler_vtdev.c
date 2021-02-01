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
#include <mach/rtk_log.h>
#include <linux/fs.h>/*for dump buffer to usb file*/
#include <linux/hrtimer.h>/*for wait vsync hr sleep*/

#include <rtk_kdriver/RPCDriver.h>
#include <rbus/dc2h_dma_reg.h>
#include <rbus/dc2h_vi_reg.h>
#include <rbus/dc2h_scaledown_reg.h>
#include <rbus/dc2h_rgb2yuv_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/scaleup_reg.h>
#include <rbus/yuv2rgb_reg.h>

#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/panel/panelapi.h>
#ifdef CONFIG_KDRIVER_USE_NEW_COMMON
	#include <scaler/scalerCommon.h>
#else
	#include <scalercommon/scalerCommon.h>
#endif
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scalerdrv/pipmp.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>

#include "scaler_vtdev.h"
#include "scaler_vscdev.h"

struct semaphore VT_Semaphore;
static struct semaphore VTBlock_Semaphore;

#define _ALIGN(val, align) (((val) + ((align) - 1)) & ~((align) - 1))
#define __4KPAGE  0x1000
#define NV_FORMAT_YBUFFER_SIZE _ALIGN(1920*1080,__4KPAGE)
#define NV12_FORMAT_CBUFFER_SIZE _ALIGN(1920*540,__4KPAGE)
#define NV16_FORMAT_CBUFFER_SIZE _ALIGN(1920*1080,__4KPAGE)
unsigned int VT_CAPTURE_BUFFER_UNITSIZE;

VT_CAPTURE_CTRL_T CaptureCtrl_VT;

static dev_t vivt_devno = 0;//vt device number
static struct cdev vivt_cdev;

#ifndef CONFIG_KDRIVER_USE_NEW_COMMON
#define FALSE   0
#define TRUE    1
#endif


#define TAG_NAME "VT" //log refine

static KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VFODState = {FALSE,FALSE,TRUE,1};
static KADP_VT_DUMP_LOCATION_TYPE_T VTDumpLocation = KADP_VT_DISPLAY_OUTPUT;
static VT_CUR_CAPTURE_INFO curCapInfo;
extern unsigned char get_vsc_mutestatus(void);
static unsigned char VtFunction = FALSE;
static unsigned int VtBufferNum = 3;
static unsigned char VtSwBufferMode = FALSE;
static unsigned char VtCaptureVDC = FALSE;

/*ARGB8888_FORMAT for roku
  RGB888 for LGE*/
static VT_CAP_FMT VT_Pixel_Format = VT_CAP_RGB888;

static unsigned int DC2H_InputWidthSta;
static unsigned int DC2H_InputLengthSta;
static unsigned int DC2H_InputWidth;
static unsigned int DC2H_InputLength;

unsigned char Capture_BufferMemInit_VT(unsigned int buffernum);
void Capture_BufferMemDeInit_VT(unsigned int buffernum);
void drvif_DC2H_dispD_CaptureConfig(VT_CUR_CAPTURE_INFO capInfo,unsigned char waitbufferfresh);

unsigned char get_vt_function(void)
{
	return VtFunction;
}

void set_vt_function(unsigned char value)
{
	VtFunction = value;
}

unsigned int get_vt_VtBufferNum(void)
{
	return VtBufferNum;
}

void set_vt_VtBufferNum(unsigned int value)
{
	VtBufferNum = value;
}

unsigned char get_vt_VtSwBufferMode(void)
{
	return VtSwBufferMode;
}

void set_vt_VtSwBufferMode(unsigned char value)
{
	VtSwBufferMode = value;
}

unsigned char get_vt_VtCaptureVDC(void)
{
	return VtCaptureVDC;
}

void set_vt_VtCaptureVDC(unsigned char value)
{
	VtCaptureVDC = value;
}

void set_VT_Pixel_Format(VT_CAP_FMT value)
{
	VT_Pixel_Format = value;
}

VT_CAP_FMT get_VT_Pixel_Format(void)
{
	return VT_Pixel_Format;
}


#if 1/*qiangzhou:move dc2h driver from kernel to kernel here start*/
#include <tvscalercontrol/vip/ultrazoom.h>
/*
D-domain Capture to Handler input data select, from :
0 : No input (data all 0)
1 : Select data from main_uzu output
2 .Select data from yuv2rgb output
3 : Select data from Sub-Title Mixer output
4 : Select data from OSD Mixer output 
5 : Select data from Dither output 
6 : Select data from Sub UZU output
7: Select data from Memc mux output
8. select data from VD output
*/
typedef enum _DC2H_IN_SEL
{
    _NO_INPUT= 0,
    _MAIN_UZU,
    _MAIN_YUV2RGB,
    _SUB_TITLE,
    _OSD_MIXER,
    _Dither_Output,  
    _Sub_UZU_Output,
    _Memc_mux_Output,
    _VD_OUTPUT
}DC2H_IN_SEL;



typedef struct
{
    unsigned int reserved:18 ;
    unsigned int y_pic_no:7;
    unsigned int c_pic_no:7;
} DC2H_YC_PIC_NO ;


typedef struct
{
    SIZE in_size;
    SIZE out_size;
    DC2H_YC_PIC_NO yc_pic_no;
    //unsigned char current_idx;
    unsigned char dc2h_init;
    unsigned char dc2h_en;
    unsigned char dc2h_in_sel;
    unsigned char panorama;
    unsigned char set_bit;
    unsigned char done_bit;
} DC2H_HANDLER ;


DC2H_HANDLER *pdc2h_hdl = NULL;
static DC2H_HANDLER dc2h_hdl;

#define CAP_LEN 32
#define CAP_REM 12

#define _RGB2YUV_m11				0x00
#define _RGB2YUV_m12				0x01
#define _RGB2YUV_m13				0x02
#define _RGB2YUV_m21				0x03
#define _RGB2YUV_m22				0x04
#define _RGB2YUV_m23				0x05
#define _RGB2YUV_m31				0x06
#define _RGB2YUV_m32				0x07
#define _RGB2YUV_m33				0x08
#define _RGB2YUV_Yo_even			0x09
#define _RGB2YUV_Yo_odd			0x0a
#define _RGB2YUV_Y_gain				0x0b
#define _RGB2YUV_sel_RGB			0x0c
#define _RGB2YUV_set_Yin_offset		0x0d
#define _RGB2YUV_set_UV_out_offset	0x0e
#define _RGB2YUV_sel_UV_off			0x0f
#define _RGB2YUV_Matrix_bypass		0x10
#define _RGB2YUV_Enable_Y_gain		0x11

/*YUV to RBG table for RGB888 and ARGB888 capture format*/
static unsigned short tYUV2RGB_COEF_709_RGB_0_255[] =
{

// CCIR 709 RGB
        0x129f,   // m11
        0x0000,  // m12
        0x1660,  // m13

        0x129f,   // m21 >> 2 0x01D5 up bits at AT Name: cychen2 , Date: 2010/3/25
        0x7a80,   // m22 >> 1
        0x74a0,   // m23 >> 2
        0x129f,   // m31 >> 2
        0x1c50,   // m32 >> 2 0x0195  up bits at AT Name: cychen2 , Date: 2010/3/25
        0x0000,   // m33 >> 1

        0x0000,          // Yo_even
        0x0000,          // Yo_odd
        0x0000,          // Y_gain

        0x0000,  // sel_RGB
        0x0001,  // sel_Yin_offset
        0x0000,  // sel_UV_out_offset
        0x0000,  // sel_UV_off
        0x0000,  // Matrix_bypass
        0x0000,  // Enable_Y_gain

};

/*RGB to YUV table for nv12 nv16 capture format*/
static unsigned short tYUV2RGB_COEF_709_RGB_16_235[] =
{
    // CCIR 709 RGB
            0x04c8,   // m11
            0x0964,   // m12
            0x01d2,   // m13
			/*nv12 uv need swap*/
            0x0800,   // m31 >> 2
            0x794d,   // m32 >> 2 0x0195  up bits at AT Name: cychen2 , Date: 2010/3/25
            0x7eb2,   // m33 >> 1

            0x7d4d,   // m21 >> 2 0x01D5 up bits at AT Name: cychen2 , Date: 2010/3/25
            0x7ab2,   // m22 >> 1
            0x0800,   // m23 >> 2
#if 0 /*uv channel could swap*/

			0x7d4d,   // m21 >> 2 0x01D5 up bits at AT Name: cychen2 , Date: 2010/3/25
			0x7ab2,   // m22 >> 1
			0x0800,   // m23 >> 2
			0x0800,   // m31 >> 2
			0x794d,   // m32 >> 2 0x0195  up bits at AT Name: cychen2 , Date: 2010/3/25
			0x7eb2,   // m33 >> 1
#endif
            0x0000,//0x07e0,          // Yo_even
            0x0000,//0x07e0,          // Yo_odd
            0x0129,//0x0110,          // Y_gain

            0x0001,  // sel_RGB
            0x0001,//0x0000,  // sel_Yin_offset
            0x0001,  // sel_UV_out_offset
            0x0000,  // sel_UV_off
            0x0000,  // Matrix_bypass
            0x0001,  // Enable_Y_gain

};


static short tScale_Down_Coef_2tap[] = {
    0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,
    31,  95, 159, 223, 287, 351, 415, 479,
    543, 607, 671, 735, 799, 863, 927, 991,
};

static short tScale_Down_Coef_Blur[] = {
	//2,   3,   5,   7,  10,  15,  20,  28,  38,  49,  64,  81, 101, 124, 150, 178,
	//209, 242, 277, 314, 351, 389, 426, 462, 496, 529, 556, 582, 602, 618, 629, 635,
	213,  217,  221,  222,  224,  229,  232,  234,
	239,  242,  245,  249,  252,  255,  259,  262,
	265,  266,  267,  269,  271,  272,  273,  275,
	276,  277,  278,  280,  281,  281,  282,  284,
};

static short tScale_Down_Coef_Mid[] = {
	//-2,  0,   1,   2,   5,   9,  15,  22,  32,  45,  60,  77,  98, 122, 149, 179,
	//211, 245, 281, 318, 356, 394, 431, 468, 502, 533, 561, 586, 606, 620, 630, 636,
	131,  125,  124,  126,  130,  135,  142,  151,
	161,  172,  183,  195,  208,  221,  234,  245,
	260,  275,  290,  304,  318,  330,  341,  351,
	361,  369,  376,  381,  386,  389,  390,  388,
};


static short tScale_Down_Coef_Sharp[] = {
    -2,   0,   1,   3,   6,  10,  15,  22,  32,  43,  58,  75,  95, 119, 145, 174,
    206, 240, 276, 314, 353, 391, 430, 467, 503, 536, 565, 590, 612, 628, 639, 646,
};


static  short *tScaleDown_COEF_TAB[] =
{
    tScale_Down_Coef_Blur,     tScale_Down_Coef_Mid,     tScale_Down_Coef_Sharp,     tScale_Down_Coef_2tap
};

void dc2h_wait_porch(void)
{
#if 0
	 dtg_lc_RBUS dtg_lc_reg;
	 dtg_pending_status_RBUS dtg_pending_status_reg;
	 ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	 UINT32 timeout = 0x3ffff;

	 //clear line compare status
	 dtg_pending_status_reg.regValue = 0;
	 dtg_pending_status_reg.dtg_vlc_status = 1;
	 rtd_outl(PPOVERLAY_DTG_pending_status_reg, dtg_pending_status_reg.regValue);
	 dv_den_start_end_reg.regValue = rtd_inl(PPOVERLAY_DV_DEN_Start_End_reg);


	 //enable line compare function
	 dtg_lc_reg.dtg_vlcen= 0;
	 dtg_lc_reg.dtg_vlc_mode = 0;
	 dtg_lc_reg.dtg_vlc_src_sel = 1;
	 dtg_lc_reg.dtg_vln = dv_den_start_end_reg.dv_den_end + 10;//frank@20150903 add some scan line avoid DC2H not write finish
	 rtd_outl(PPOVERLAY_DTG_LC_reg, dtg_lc_reg.regValue);

	 do {
	  dtg_lc_reg.dtg_vlcen= 1;
	  rtd_outl(PPOVERLAY_DTG_LC_reg, dtg_lc_reg.regValue);
	  if((rtd_inl(PPOVERLAY_DTG_pending_status_reg) & _BIT4)) {
	   break;
	  }
	  timeout--;
	 } while(timeout);

	 if(timeout == 0){

	  rtd_printk(KERN_DEBUG, TAG_NAME,"[wait uzu dtg end]timeout error!!!\n");
	 }

	 //disable line compare function
	 dtg_lc_reg.regValue = 0;
	 rtd_outl(PPOVERLAY_DTG_LC_reg, dtg_lc_reg.regValue);
	 //clear line compare status
	 dtg_pending_status_reg.regValue = 0;
	 dtg_pending_status_reg.dtg_vlc_status = 1;
	 rtd_outl(PPOVERLAY_DTG_pending_status_reg, dtg_pending_status_reg.regValue);
#else
	unsigned int uzulinecntA =0;
	unsigned int uzulinecntB =0;

	unsigned int timeoutcount = 0x3ffff;
	ppoverlay_dv_den_start_end_RBUS dv_den_start_end_reg;
	ppoverlay_new_meas0_linecnt_real_RBUS new_meas0_linecnt_real_Reg;

	dv_den_start_end_reg.regValue = rtd_inl(PPOVERLAY_DV_DEN_Start_End_reg);
	do {
		new_meas0_linecnt_real_Reg.regValue = rtd_inl(PPOVERLAY_new_meas0_linecnt_real_reg);
		uzulinecntA = new_meas0_linecnt_real_Reg.line_cnt_rt;
		new_meas0_linecnt_real_Reg.regValue = rtd_inl(PPOVERLAY_new_meas0_linecnt_real_reg);
		uzulinecntB = new_meas0_linecnt_real_Reg.line_cnt_rt;
		if((uzulinecntA == uzulinecntB)&&(/*(uzulinecntA < (dv_den_start_end_reg.dv_den_sta)) || */(uzulinecntA > (dv_den_start_end_reg.dv_den_end + 10)))&&(uzulinecntA < (dv_den_start_end_reg.dv_den_end + 12))) {
			break;
		}
		timeoutcount--;
	} while(timeoutcount);

	if(timeoutcount == 0){
		rtd_printk(KERN_DEBUG, TAG_NAME,"[SUB DEN]timeout error!!!\n");
	}
#endif

}

void drvif_dc2h_swmode_inforpc(unsigned int onoff,unsigned int buffernumber,unsigned int width,unsigned int length){

	DC2H_SWMODE_STRUCT_T *swmode_infoptr;
	unsigned int ulCount = 0;
	int ret;

	swmode_infoptr = (DC2H_SWMODE_STRUCT_T *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_DC2H_SWMODE_ENABLE);
	ulCount = sizeof(DC2H_SWMODE_STRUCT_T) / sizeof(unsigned int);

	swmode_infoptr->SwModeEnable = onoff;
	swmode_infoptr->buffernumber = buffernumber;
	swmode_infoptr->cap_format = (UINT32)get_VT_Pixel_Format();
	swmode_infoptr->cap_width = width;
	swmode_infoptr->cap_length = length;
	swmode_infoptr->cap_buffer[0] = (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
	swmode_infoptr->cap_buffer[1] = (UINT32)CaptureCtrl_VT.cap_buffer[1].phyaddr;
	swmode_infoptr->cap_buffer[2] = (UINT32)CaptureCtrl_VT.cap_buffer[2].phyaddr;
	swmode_infoptr->cap_buffer[3] = (UINT32)CaptureCtrl_VT.cap_buffer[3].phyaddr;
	swmode_infoptr->cap_buffer[4] = (UINT32)CaptureCtrl_VT.cap_buffer[4].phyaddr;


	//change endian
	swmode_infoptr->SwModeEnable = htonl(swmode_infoptr->SwModeEnable);
	swmode_infoptr->buffernumber = htonl(swmode_infoptr->buffernumber);
	swmode_infoptr->cap_format = htonl(swmode_infoptr->cap_format);
	swmode_infoptr->cap_width = htonl(swmode_infoptr->cap_width);
	swmode_infoptr->cap_length = htonl(swmode_infoptr->cap_length);
	swmode_infoptr->cap_buffer[0] = htonl(swmode_infoptr->cap_buffer[0]);
	swmode_infoptr->cap_buffer[1] = htonl(swmode_infoptr->cap_buffer[1]);
	swmode_infoptr->cap_buffer[2] = htonl(swmode_infoptr->cap_buffer[2]);
	swmode_infoptr->cap_buffer[3] = htonl(swmode_infoptr->cap_buffer[3]);
	swmode_infoptr->cap_buffer[4] = htonl(swmode_infoptr->cap_buffer[4]);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SET_DC2H_SWMODE_ENABLE,0,0))){
		pr_emerg("[dc2h]ret=%d, SCALERIOC_SET_DC2H_SWMODE_ENABLE RPC fail !!!\n", ret);
	}
}

void drvif_color_colorspaceyuv2rgbtransfer(DC2H_IN_SEL dc2h_in_sel)
{
	unsigned short *table_index = 0;
	
	dc2h_rgb2yuv_dc2h_rgb2yuv_ctrl_RBUS  dc2h_rgb2yuv_ctrl_reg;
	dc2h_rgb2yuv_dc2h_tab1_m11_m12_RBUS dc2h_tab1_m11_m12_reg;
	dc2h_rgb2yuv_dc2h_tab1_m13_m21_RBUS dc2h_tab1_m13_m21_reg;
	dc2h_rgb2yuv_dc2h_tab1_m22_m23_RBUS dc2h_tab1_m22_m23_reg;
	dc2h_rgb2yuv_dc2h_tab1_m31_m32_RBUS dc2h_tab1_m31_m32_reg;
	dc2h_rgb2yuv_dc2h_tab1_m33_y_gain_RBUS dc2h_tab1_m33_y_gain_reg;
	dc2h_rgb2yuv_dc2h_tab1_yo_RBUS dc2h_tab1_yo_reg;

	if((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16))
		table_index = tYUV2RGB_COEF_709_RGB_16_235;
	else
		table_index = tYUV2RGB_COEF_709_RGB_0_255;

	//main  all tab-1
	dc2h_tab1_m11_m12_reg.m11 = table_index [_RGB2YUV_m11];
	dc2h_tab1_m11_m12_reg.m12 = table_index [_RGB2YUV_m12];
	//printf("dc2h_tab1_m11_m12_reg.regValue = %x\n", dc2h_tab1_m11_m12_reg.regValue);
	rtd_outl(DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg, dc2h_tab1_m11_m12_reg.regValue);

	dc2h_tab1_m13_m21_reg.m21 = table_index [_RGB2YUV_m21];
	dc2h_tab1_m13_m21_reg.m13 = table_index [_RGB2YUV_m13];
	//printf("dc2h_tab1_m13_m21_reg.regValue = %x\n", dc2h_tab1_m13_m21_reg.regValue);
	rtd_outl(DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg, dc2h_tab1_m13_m21_reg.regValue);

	dc2h_tab1_m22_m23_reg.m22 = table_index [_RGB2YUV_m22];
	dc2h_tab1_m22_m23_reg.m23 = table_index [_RGB2YUV_m23];
	//printf("dc2h_tab1_m22_m23_reg.regValue = %x\n", dc2h_tab1_m22_m23_reg.regValue);
	rtd_outl(DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg, dc2h_tab1_m22_m23_reg.regValue);

	dc2h_tab1_m31_m32_reg.m31 = table_index [_RGB2YUV_m31];
	dc2h_tab1_m31_m32_reg.m32 = table_index [_RGB2YUV_m32];
	//printf("dc2h_tab1_m31_m32_reg.regValue = %x\n", dc2h_tab1_m31_m32_reg.regValue);
	rtd_outl(DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg, dc2h_tab1_m31_m32_reg.regValue);

	dc2h_tab1_m33_y_gain_reg.m33 = table_index [_RGB2YUV_m33];
	dc2h_tab1_m33_y_gain_reg.yo_gain= table_index [_RGB2YUV_Y_gain];
	//printf("dc2h_tab1_m33_y_gain_reg.regValue = %x\n", dc2h_tab1_m33_y_gain_reg.regValue);
	rtd_outl(DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg, dc2h_tab1_m33_y_gain_reg.regValue);

	dc2h_tab1_yo_reg.yo_even= table_index [_RGB2YUV_Yo_even];
	dc2h_tab1_yo_reg.yo_odd= table_index [_RGB2YUV_Yo_odd];
	//printf("dc2h_tab1_yo_reg.regValue = %x\n", dc2h_tab1_yo_reg.regValue);
	rtd_outl(DC2H_RGB2YUV_DC2H_Tab1_Yo_reg, dc2h_tab1_yo_reg.regValue);

	dc2h_rgb2yuv_ctrl_reg.regValue = rtd_inl(DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg);
	dc2h_rgb2yuv_ctrl_reg.sel_rgb= table_index [_RGB2YUV_sel_RGB];
	dc2h_rgb2yuv_ctrl_reg.set_r_in_offset= table_index [_RGB2YUV_set_Yin_offset];
	dc2h_rgb2yuv_ctrl_reg.set_uv_out_offset= table_index [_RGB2YUV_set_UV_out_offset];
	dc2h_rgb2yuv_ctrl_reg.sel_uv_off= table_index [_RGB2YUV_sel_UV_off];
	dc2h_rgb2yuv_ctrl_reg.matrix_bypass= table_index [_RGB2YUV_Matrix_bypass];
	dc2h_rgb2yuv_ctrl_reg.sel_y_gain= table_index [_RGB2YUV_Enable_Y_gain];
	dc2h_rgb2yuv_ctrl_reg.dc2h_in_sel = dc2h_in_sel;

	
	if((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16)){
		if(dc2h_in_sel > _MAIN_UZU){
			dc2h_rgb2yuv_ctrl_reg.en_rgb2yuv = 1;//Enable RGB to YUV conversion (YUV out)
		}else{
			dc2h_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
		}
	} else {
		if(dc2h_in_sel > _MAIN_UZU){
			dc2h_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
		}else{
			dc2h_rgb2yuv_ctrl_reg.en_rgb2yuv = 2;//Enable YUV to RGB conversion (GBR out)
		}
	}
	rtd_outl(DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg, dc2h_rgb2yuv_ctrl_reg.regValue);

}

void drvif_color_ultrazoom_set_dc2h_scale_down(DC2H_HANDLER *pdc2h_hdl)
{
	unsigned int SDRatio;
	unsigned int SDFilter=0;
	unsigned int tmp_data;
	short *coef_pt;
	unsigned int i;
	unsigned long long tmpLength = 0;
	unsigned int nFactor, D;
	unsigned char Hini, Vini, a;
	unsigned short S1,S2;

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	dc2h_scaledown_dc2h_hsd_ctrl0_RBUS        dc2h_hsd_ctrl0_reg;
	dc2h_scaledown_dc2h_vsd_ctrl0_RBUS                      dc2h_vsd_ctrl0_reg;
	dc2h_scaledown_dc2h_hsd_scale_hor_factor_RBUS  dc2h_hsd_scale_hor_factor_reg;
	dc2h_scaledown_dc2h_vsd_scale_ver_factor_RBUS  dc2h_vsd_scale_ver_factor_reg;
	dc2h_scaledown_dc2h_hsd_hor_segment_RBUS    dc2h_hsd_hor_segment_reg;
	dc2h_scaledown_dc2h_hsd_hor_delta1_RBUS      dc2h_hsd_hor_delta1_reg;
	dc2h_scaledown_dc2h_hsd_initial_value_RBUS      dc2h_hsd_initial_value_reg;
	dc2h_scaledown_dc2h_vsd_initial_value_RBUS      dc2h_vsd_initial_value_reg;

	dc2h_hsd_ctrl0_reg.regValue    = rtd_inl(DC2H_SCALEDOWN_DC2H_HSD_Ctrl0_reg);
	dc2h_vsd_ctrl0_reg.regValue    = rtd_inl(DC2H_SCALEDOWN_DC2H_VSD_Ctrl0_reg);
	dc2h_hsd_scale_hor_factor_reg.regValue  = rtd_inl(DC2H_SCALEDOWN_DC2H_HSD_Scale_Hor_Factor_reg);
	dc2h_vsd_scale_ver_factor_reg.regValue  = rtd_inl(DC2H_SCALEDOWN_DC2H_VSD_Scale_Ver_Factor_reg);
	dc2h_hsd_hor_segment_reg.regValue = rtd_inl(DC2H_SCALEDOWN_DC2H_HSD_Hor_Segment_reg);
	dc2h_hsd_hor_delta1_reg.regValue  = rtd_inl(DC2H_SCALEDOWN_DC2H_HSD_Hor_Delta1_reg);
	dc2h_hsd_initial_value_reg.regValue  = rtd_inl(DC2H_SCALEDOWN_DC2H_HSD_Initial_Value_reg);
	dc2h_vsd_initial_value_reg.regValue  = rtd_inl(DC2H_SCALEDOWN_DC2H_VSD_Initial_Value_reg);

	#define TMPMUL  (16)

	//o============ H scale-down=============o
	if (pdc2h_hdl->in_size.nWidth > pdc2h_hdl->out_size.nWidth)
	{
		// o-------calculate scaledown ratio to select one of different bandwith filters.--------o
		if ( pdc2h_hdl->out_size.nWidth == 0 ) {
		rtd_printk(KERN_DEBUG, TAG_NAME,"output width = 0 !!!\n");
		SDRatio = 0;
		} else {
		SDRatio = (pdc2h_hdl->in_size.nWidth*TMPMUL) / pdc2h_hdl->out_size.nWidth;
		}

		//UltraZoom_Printf("CSW SDRatio number=%d\n",SDRatio);

		if(SDRatio <= ((TMPMUL*3)/2))  //<1.5 sharp, wider bw
		SDFilter = 2;
		else if(SDRatio <= (TMPMUL*2) && SDRatio > ((TMPMUL*3)/2) )  // Mid
		SDFilter = 1;
		else    // blurest, narrow bw
		SDFilter = 0;

		//o---------------- fill coefficients into access port--------------------o
		coef_pt = tScaleDown_COEF_TAB[SDFilter];

		dc2h_hsd_ctrl0_reg.h_y_table_sel = 0;  // TAB1
		dc2h_hsd_ctrl0_reg.h_c_table_sel = 0;  // TAB1

		for (i=0; i<16; i++)
		{
		tmp_data = ((unsigned int)(*coef_pt++)<<16);
		tmp_data += (unsigned int)(*coef_pt++);
		rtd_outl(DC2H_SCALEDOWN_DC2H_UZD_FIR_Coef_Tab1_C0_reg + i*4, tmp_data);
		}
	}

	//o============ V scale-down=============o
	if (pdc2h_hdl->in_size.nLength > pdc2h_hdl->out_size.nLength)
	{
		// o-------calculate scaledown ratio to select one of different bandwith filters.--------o
		//jeffrey 961231
		if ( pdc2h_hdl->out_size.nLength == 0 ) {
		SDRatio = 0;
		} else {
		SDRatio = (pdc2h_hdl->in_size.nLength*TMPMUL) /pdc2h_hdl->out_size.nLength;
		}

		//UltraZoom_Printf("CSW SDRatio number=%d\n",SDRatio);

		if(SDRatio <= ((TMPMUL*3)/2))  //<1.5 sharp, wider bw
		SDFilter = 2;
		else if(SDRatio <= (TMPMUL*2) && SDRatio > ((TMPMUL*3)/2) )  // Mid
		SDFilter = 1;
		else    // blurest, narrow bw
		SDFilter = 0;

		rtd_printk(KERN_DEBUG, TAG_NAME,"filter number=%d\n",SDFilter);

		//o---------------- fill coefficients into access port--------------------o
		coef_pt = tScaleDown_COEF_TAB[SDFilter];

		dc2h_vsd_ctrl0_reg.v_y_table_sel = 1;  // TAB2
		dc2h_vsd_ctrl0_reg.v_c_table_sel = 1;  // TAB2

		for (i=0; i<16; i++)
		{
		tmp_data = ((unsigned int)(*coef_pt++)<<16);
		tmp_data += (unsigned int)(*coef_pt++);
		rtd_outl(DC2H_SCALEDOWN_DC2H_UZD_FIR_Coef_Tab2_C0_reg + i*4, tmp_data);
		}
	} else {
		//no need  V scale-down, use bypass filter
	}

	// Decide Output data format for scale down
	//============H Scale-down============
	if (pdc2h_hdl->in_size.nWidth > pdc2h_hdl->out_size.nWidth)
	{    // H scale-down
		Hini = 0x80;//0xff;//0x78;
		dc2h_hsd_initial_value_reg.hor_ini = Hini;
		a = 5;

		if(pdc2h_hdl->panorama)
		{// CSW+ 0960830 Non-linear SD
			S1 = (pdc2h_hdl->out_size.nWidth) >> 2;
			S2 = (pdc2h_hdl->out_size.nWidth) - S1*2;
			//=vv==old from TONY, if no problem, use this=vv==
			nFactor = (unsigned int)(((pdc2h_hdl->in_size.nWidth)<<21) - ((unsigned int)Hini<<13));
			//=vv==Thur debugged=vv==
			//nFactor = ((((unsigned long long)(ptInSize->nWidth))*(ptOutSize->nWidth-1))<<21) / ptOutSize->nWidth;
			//===================
			nFactor = nFactor /((2*a+1)*S1 + (a+1)*S2 - a) * a;
			D = nFactor / a / S1;
			nFactor = SHR((nFactor + 1), 1); //rounding
			D = SHR(D + 1, 1); //rounding
			rtd_printk(KERN_DEBUG, TAG_NAME,"\nPANORAMA2 TEST 111\n");
			rtd_printk(KERN_DEBUG, TAG_NAME,"nPANORAMA2 Factor = %d\n",nFactor);
			rtd_printk(KERN_DEBUG, TAG_NAME,"PANORAMA2 S1=%d, S2=%d, D = %d\n",S1, S2, D);

			if(nFactor < 1048576) {
				rtd_printk(KERN_DEBUG, TAG_NAME,"PANORAMA2 Can't do nonlinear SD \n");
				//nFactor = (unsigned int)(((ptInSize->nWidth)<<21) - ((unsigned int)Hini<<13)) / (ptOutSize->nWidth-1);
				nFactor = (unsigned int)(((pdc2h_hdl->in_size.nWidth)<<21)) / (pdc2h_hdl->out_size.nWidth);
				nFactor = SHR(nFactor + 1, 1); //rounding
				rtd_printk(KERN_DEBUG, TAG_NAME,"PANORAMA2 nFactor=%x, input Wid=%d, Out Wid=%d\n",nFactor, pdc2h_hdl->in_size.nWidth, pdc2h_hdl->out_size.nWidth);
				S1 = 0;
				S2 = pdc2h_hdl->out_size.nWidth;
				D = 0;
			}
        	}else{
			if ( pdc2h_hdl->out_size.nWidth == 0 ) {
				rtd_printk(KERN_DEBUG, TAG_NAME,"output width = 0 !!!\n");
				nFactor = 0;
			}else if(pdc2h_hdl->in_size.nWidth>4095){
				//nFactor = (unsigned int)((((pdc2h_hdl->in_size.nWidth-1)<<19) / (pdc2h_hdl->out_size.nWidth-1))<<1);
				nFactor = (unsigned int)((((pdc2h_hdl->in_size.nWidth)<<19) / (pdc2h_hdl->out_size.nWidth))<<1);
			}else if(pdc2h_hdl->in_size.nWidth>2047){
				//nFactor = (unsigned int)(((pdc2h_hdl->in_size.nWidth-1)<<20) / (pdc2h_hdl->out_size.nWidth-1));
				nFactor = (unsigned int)(((pdc2h_hdl->in_size.nWidth)<<20) / (pdc2h_hdl->out_size.nWidth));
			}else {
				//nFactor = (unsigned int)(((pdc2h_hdl->in_size.nWidth-1)<<21) / (pdc2h_hdl->out_size.nWidth-1));
				nFactor = (unsigned int)(((pdc2h_hdl->in_size.nWidth)<<21) / (pdc2h_hdl->out_size.nWidth));
				nFactor = SHR(nFactor + 1, 1); //rounding
			}

			rtd_printk(KERN_DEBUG, TAG_NAME,"nFactor=%d, input Wid=%d, Out Wid=%d\n",nFactor, pdc2h_hdl->in_size.nWidth, pdc2h_hdl->out_size.nWidth);
			S1 = 0;
			S2 = pdc2h_hdl->out_size.nWidth;
			D = 0;
		}
	}else {
		nFactor = 0x100000;
		S1 = 0;
		S2 = pdc2h_hdl->out_size.nWidth;
		D = 0;
	}

	dc2h_hsd_scale_hor_factor_reg.hor_fac = nFactor;
	dc2h_hsd_hor_segment_reg.nl_seg1 = S1;
	dc2h_hsd_hor_segment_reg.nl_seg2 = S2;
	dc2h_hsd_hor_delta1_reg.nl_d1 = D;
	//UltraZoom_Printf("reg_seg1=%x, reg_Seg_all=%x\n",dc2h_hsd_hor_segment_reg.nl_seg1, dc2h_hsd_hor_segment_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME,"nFactor=%x, input_Wid=%d, Output_Wid=%d\n",nFactor, pdc2h_hdl->in_size.nWidth, pdc2h_hdl->out_size.nWidth);

	//================V Scale-down=================
	if (pdc2h_hdl->in_size.nLength > pdc2h_hdl->out_size.nLength) {    // V scale-down
		Vini = 0xff;//0x78;
		dc2h_vsd_initial_value_reg.ver_ini = Vini;
		if ( pdc2h_hdl->out_size.nLength == 0 ) {
			rtd_printk(KERN_DEBUG, TAG_NAME,"output length = 0 !!!\n");
			nFactor = 0;
		} else {
			//frank@1018 sync with pacific to solve 3d vide 1920X2205 scaler down fail
			//nFactor = (unsigned int)(((ptInSize->nLength)<<21) / (ptOutSize->nLength));
			//nFactor = (unsigned int)(((unsigned long long)(pdc2h_hdl->in_size.nLength)<<21) / (pdc2h_hdl->out_size.nLength));
			tmpLength = ((unsigned long long)(pdc2h_hdl->in_size.nLength)<<21);
			do_div(tmpLength, (pdc2h_hdl->out_size.nLength));
			nFactor = tmpLength;
		}
		rtd_printk(KERN_DEBUG, TAG_NAME,"Ch1 Ver: CAP=%d, Disp=%d, factor=%d\n", pdc2h_hdl->in_size.nLength, pdc2h_hdl->out_size.nLength, nFactor);
		nFactor = SHR(nFactor + 1, 1); //rounding
	} else {
		nFactor = 0x100000;
	}

	dc2h_vsd_scale_ver_factor_reg.ver_fac = nFactor;

	rtd_outl(DC2H_SCALEDOWN_DC2H_HSD_Ctrl0_reg, dc2h_hsd_ctrl0_reg.regValue);
	rtd_outl(DC2H_SCALEDOWN_DC2H_VSD_Ctrl0_reg, dc2h_vsd_ctrl0_reg.regValue);
	rtd_outl(DC2H_SCALEDOWN_DC2H_HSD_Scale_Hor_Factor_reg, dc2h_hsd_scale_hor_factor_reg.regValue);
	rtd_outl(DC2H_SCALEDOWN_DC2H_VSD_Scale_Ver_Factor_reg, dc2h_vsd_scale_ver_factor_reg.regValue);
	rtd_outl(DC2H_SCALEDOWN_DC2H_HSD_Hor_Segment_reg, dc2h_hsd_hor_segment_reg.regValue);
	rtd_outl(DC2H_SCALEDOWN_DC2H_HSD_Hor_Delta1_reg, dc2h_hsd_hor_delta1_reg.regValue);
	rtd_outl(DC2H_SCALEDOWN_DC2H_HSD_Initial_Value_reg, dc2h_hsd_initial_value_reg.regValue);
	rtd_outl(DC2H_SCALEDOWN_DC2H_VSD_Initial_Value_reg, dc2h_vsd_initial_value_reg.regValue);
}


void drvif_color_ultrazoom_config_dc2h_scaling_down(DC2H_HANDLER *pdc2h_hdl)
{
	// Scale down setup for Channel1
	dc2h_scaledown_dc2h_hsd_ctrl0_RBUS dc2h_hsd_ctrl0_reg;
	dc2h_scaledown_dc2h_vsd_ctrl0_RBUS dc2h_vsd_ctrl0_reg;

	dc2h_hsd_ctrl0_reg.regValue = rtd_inl(DC2H_SCALEDOWN_DC2H_HSD_Ctrl0_reg);
	dc2h_hsd_ctrl0_reg.h_zoom_en = (pdc2h_hdl->in_size.nWidth > pdc2h_hdl->out_size.nWidth);
	rtd_outl(DC2H_SCALEDOWN_DC2H_HSD_Ctrl0_reg, dc2h_hsd_ctrl0_reg.regValue);

	dc2h_vsd_ctrl0_reg.regValue = rtd_inl(DC2H_SCALEDOWN_DC2H_VSD_Ctrl0_reg);
	if(pdc2h_hdl->in_size.nLength > pdc2h_hdl->out_size.nLength){
		dc2h_vsd_ctrl0_reg.v_zoom_en = 1;
		dc2h_vsd_ctrl0_reg.buffer_mode = 2;
	}else{
		dc2h_vsd_ctrl0_reg.v_zoom_en = 0;
		dc2h_vsd_ctrl0_reg.buffer_mode = 0;
	}
	if((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16)){
		dc2h_vsd_ctrl0_reg.sort_fmt = 0;
	} else {
		dc2h_vsd_ctrl0_reg.sort_fmt = 1;
	}
	rtd_outl(DC2H_SCALEDOWN_DC2H_VSD_Ctrl0_reg, dc2h_vsd_ctrl0_reg.regValue);

	drvif_color_ultrazoom_set_dc2h_scale_down(pdc2h_hdl);
}

void drvif_dc2h_input_overscan_config(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_RBUS dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg;
	dc2h_rgb2yuv_dc2h_overscan_ctrl0_RBUS dc2h_rgb2yuv_dc2h_overscan_ctrl0_Reg;
	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_RBUS dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_Reg;

	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.regValue = rtd_inl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg);
	dc2h_rgb2yuv_dc2h_overscan_ctrl0_Reg.regValue = rtd_inl(DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg);
	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_Reg.regValue = rtd_inl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg);

	dc2h_rgb2yuv_dc2h_overscan_ctrl0_Reg.dc2h_overscan_left = x;
	dc2h_rgb2yuv_dc2h_overscan_ctrl0_Reg.dc2h_overscan_right = x+w-1;
	rtd_outl(DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg, dc2h_rgb2yuv_dc2h_overscan_ctrl0_Reg.regValue);

	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_Reg.dc2h_overscan_top = y;
	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_Reg.dc2h_overscan_bottom = y+h-1;
	rtd_outl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg, dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_Reg.regValue);

	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.dc2h_3dmaskto2d_3dformat = 5;/*overscan*/
	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.dc2h_3dmaskto2d_en = 1;
	rtd_outl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg, dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.regValue);
	
}

unsigned int drvif_dc2hmemory_get_data_align(unsigned int Value, unsigned int unit)
{
	unsigned int AlignVal;

	AlignVal = Value;
	unit -= 1;
	if (Value & unit)
		AlignVal = (Value & (~unit)) + unit + 1;
	return AlignVal;
}


void drvif_vi_config(unsigned int nWidth, unsigned int nLength, unsigned int data_format)
{
	unsigned int LineSize;
    dc2h_vi_dc2h_v1_output_fmt_RBUS dc2h_v1_output_fmt_reg;//DC2H_RGB2YUV_DC2H_V1_OUTPUT_FMT_VADDR
    dc2h_vi_dc2h_cwvh1_RBUS dc2h_cwvh1_reg;//w,h //DC2H_RGB2YUV_DC2H_CWVH1_VADDR
    dc2h_vi_dc2h_cwvh1_2_RBUS dc2h_cwvh1_2_reg;
	dc2h_vi_dc2h_dmactl_RBUS vi_dmactl_reg;//dmaen	//I3DDMA_VI_IDMA_DMACTL_VADDR
	dc2h_vi_dc2h_vi_addcmd_transform_RBUS dc2h_vi_dc2h_vi_addcmd_transform_reg;
	dc2h_dma_dc2h_seq_interrupt_enable_RBUS dc2h_dma_dc2h_seq_interrupt_enable_Reg;
	
    dc2h_v1_output_fmt_reg.regValue = rtd_inl(DC2H_VI_DC2H_V1_OUTPUT_FMT_reg);
	dc2h_v1_output_fmt_reg.data_format = data_format;/*0:420	1:422*/
	dc2h_v1_output_fmt_reg.swap_1byte = 0;
	dc2h_v1_output_fmt_reg.swap_2byte = 0;
	dc2h_v1_output_fmt_reg.swap_4byte = 0;
	dc2h_v1_output_fmt_reg.swap_8byte = 0;
    rtd_outl(DC2H_VI_DC2H_V1_OUTPUT_FMT_reg, dc2h_v1_output_fmt_reg.regValue);

    dc2h_cwvh1_reg.regValue = rtd_inl(DC2H_VI_DC2H_CWVH1_reg);
    dc2h_cwvh1_reg.hsize = nWidth;
    dc2h_cwvh1_reg.vsize = nLength;
    rtd_outl(DC2H_VI_DC2H_CWVH1_reg, dc2h_cwvh1_reg.regValue);

   	dc2h_cwvh1_2_reg.regValue = rtd_inl(DC2H_VI_DC2H_CWVH1_2_reg);
    dc2h_cwvh1_2_reg.vsize_c = nLength >> (data_format == 1? 0: 1);
    rtd_outl(DC2H_VI_DC2H_CWVH1_2_reg, dc2h_cwvh1_2_reg.regValue);
	LineSize = drvif_dc2hmemory_get_data_align(nWidth*8, 64);
	LineSize = (unsigned int)SHR(LineSize, 6);	// (pixels of per line * 8 / 32), unit: 32bits

	dc2h_vi_dc2h_vi_addcmd_transform_reg.regValue = rtd_inl(DC2H_VI_DC2H_vi_addcmd_transform_reg);
	dc2h_vi_dc2h_vi_addcmd_transform_reg.line_step = LineSize;
	dc2h_vi_dc2h_vi_addcmd_transform_reg.vi_addcmd_trans_en = 1;
	rtd_outl(DC2H_VI_DC2H_vi_addcmd_transform_reg, dc2h_vi_dc2h_vi_addcmd_transform_reg.regValue);

	if (get_vt_VtSwBufferMode()) {
		dc2h_dma_dc2h_seq_interrupt_enable_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_seq_Interrupt_Enable_reg);
		dc2h_dma_dc2h_seq_interrupt_enable_Reg.vs_rising_ie = 1;
	}	
	
	//dc2h_wait_porch();
	vi_dmactl_reg.regValue = rtd_inl(DC2H_VI_DC2H_DMACTL_reg);
	vi_dmactl_reg.dmaen1 = 1;
	vi_dmactl_reg.seq_blk_sel =1; //0: YV16 or RGB888 1: NV12 or NV16
	rtd_outl(DC2H_VI_DC2H_DMACTL_reg, vi_dmactl_reg.regValue);
	
	if (get_vt_VtSwBufferMode()) {
		rtd_outl(DC2H_DMA_dc2h_seq_Interrupt_Enable_reg, dc2h_dma_dc2h_seq_interrupt_enable_Reg.regValue);
	}	
}

void drvif_dc2h_seq_config(DC2H_HANDLER *pdc2h_hdl)
{
	unsigned int num, rem;
	unsigned int lineunits, len;

	dc2h_dma_dc2h_seq_mode_ctrl1_RBUS dc2h_seq_mode_ctrl1_reg;
	dc2h_dma_dc2h_seq_mode_ctrl2_RBUS dc2h_seq_mode_ctrl2_reg;
	dc2h_dma_dc2h_seq_interrupt_enable_RBUS dc2h_dma_dc2h_seq_interrupt_enable_Reg;
	dc2h_dma_dc2h_cap_ctl0_RBUS dc2h_cap_ctl0_reg;
	dc2h_dma_dc2h_cap_ctl1_RBUS dc2h_cap_ctl1_reg;
	//dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_reg;
	//dc2h_cap_l2_start_RBUS dc2h_cap_l2_start_reg;
	//dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_reg;
	dc2h_dma_dc2h_seq_byte_channel_swap_RBUS dc2h_seq_byte_channel_swap_reg;

	dc2h_vi_dc2h_dmactl_RBUS vi_dmactl_reg;//dmaen
	vi_dmactl_reg.regValue = rtd_inl(DC2H_VI_DC2H_DMACTL_reg);
	//vi_dmactl_reg.dmaen1 = 1;
	vi_dmactl_reg.seq_blk_sel =0;
	rtd_outl(DC2H_VI_DC2H_DMACTL_reg, vi_dmactl_reg.regValue);

	dc2h_seq_mode_ctrl1_reg.regValue = rtd_inl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg);
	dc2h_seq_mode_ctrl1_reg.cap_en = 0;
	rtd_outl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg, dc2h_seq_mode_ctrl1_reg.regValue);

	if (pdc2h_hdl->dc2h_en == FALSE)
		return;

	dc2h_seq_mode_ctrl2_reg.regValue = rtd_inl(DC2H_DMA_dc2h_Seq_mode_CTRL2_reg);
	dc2h_seq_mode_ctrl2_reg.hact = pdc2h_hdl->out_size.nWidth;
	dc2h_seq_mode_ctrl2_reg.vact = pdc2h_hdl->out_size.nLength;
	rtd_outl(DC2H_DMA_dc2h_Seq_mode_CTRL2_reg, dc2h_seq_mode_ctrl2_reg.regValue);

	//num = (pdc2h_hdl->out_size.nWidth - CAP_REM) / CAP_LEN;
	//rem = ((pdc2h_hdl->out_size.nWidth - CAP_REM) % CAP_LEN) + CAP_REM;

	if((get_VT_Pixel_Format() == VT_CAP_ABGR8888)||(get_VT_Pixel_Format() == VT_CAP_ARGB8888))
		lineunits = (pdc2h_hdl->out_size.nWidth * 8 * 4) /128;
	else
		lineunits = (pdc2h_hdl->out_size.nWidth * 8 * 3) /128;
	len = 32;
	num = (unsigned int)(lineunits / len);
	rem = (unsigned int)(lineunits % len);

	if (rem == 0) { // remainder is not allowed to be zero
		rem = len;
		num -= 1;
	}

	dc2h_cap_ctl0_reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_CTL0_reg);
	dc2h_cap_ctl0_reg.bit_sel = 0;
	dc2h_cap_ctl0_reg.pixel_encoding = 0;
	//dc2h_cap_ctl0_reg.triple_buf_en = 1;
	if(get_vt_VtBufferNum() == 1) {
		dc2h_cap_ctl0_reg.triple_buf_en = 0;
		dc2h_cap_ctl0_reg.auto_block_sel_en = 0;
		//dc2h_cap_ctl0_reg.cap_block_fw = 0;
	} else {
		if(get_vt_VtCaptureVDC()) {
			dc2h_cap_ctl0_reg.triple_buf_en = 1;
			dc2h_cap_ctl0_reg.auto_block_sel_en = 1;
		} else {
			if (get_vt_VtSwBufferMode()) {
				dc2h_cap_ctl0_reg.triple_buf_en = 0;
				dc2h_cap_ctl0_reg.auto_block_sel_en = 0;
			} else {
				dc2h_cap_ctl0_reg.triple_buf_en = 0;
				dc2h_cap_ctl0_reg.auto_block_sel_en = 1;
			}
		}
	}
	dc2h_cap_ctl0_reg.cap_write_len = CAP_LEN;
	dc2h_cap_ctl0_reg.cap_write_rem = rem;
	rtd_outl(DC2H_DMA_dc2h_Cap_CTL0_reg, dc2h_cap_ctl0_reg.regValue);

	dc2h_cap_ctl1_reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_CTL1_reg);
	dc2h_cap_ctl1_reg.cap_water_lv =CAP_LEN ;
	dc2h_cap_ctl1_reg.cap_write_num = num;
	rtd_outl(DC2H_DMA_dc2h_Cap_CTL1_reg, dc2h_cap_ctl1_reg.regValue);

	//dc2h_seq_mode_ctrl1_reg.regValue = rtd_inl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg);
	//dc2h_seq_mode_ctrl1_reg.cap_en = 1;
	//rtd_outl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg, dc2h_seq_mode_ctrl1_reg.regValue);

	dc2h_seq_byte_channel_swap_reg.regValue = rtd_inl(DC2H_DMA_dc2h_seq_byte_channel_swap_reg);
	dc2h_seq_byte_channel_swap_reg.dma_1byte_swap = 1;
	dc2h_seq_byte_channel_swap_reg.dma_2byte_swap = 1;
	dc2h_seq_byte_channel_swap_reg.dma_4byte_swap = 1;
	dc2h_seq_byte_channel_swap_reg.dma_8byte_swap = 1;
	//if(get_VT_Pixel_Format() == VT_CAP_ARGB8888)
		dc2h_seq_byte_channel_swap_reg.dma_channel_swap = 0;
	//else
	//	dc2h_seq_byte_channel_swap_reg.dma_channel_swap = 1;
	rtd_outl(DC2H_DMA_dc2h_seq_byte_channel_swap_reg, dc2h_seq_byte_channel_swap_reg.regValue);

	dc2h_seq_mode_ctrl1_reg.regValue = rtd_inl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg);
	dc2h_seq_mode_ctrl1_reg.cap_en = 1;

	if((get_VT_Pixel_Format() == VT_CAP_ABGR8888)||(get_VT_Pixel_Format() == VT_CAP_ARGB8888)){
		dc2h_seq_mode_ctrl1_reg.argb_dummy_data = 0xFF;
		dc2h_seq_mode_ctrl1_reg.rgb_to_argb_en = 1;
		dc2h_seq_mode_ctrl1_reg.argb_swap = 1;
	}
	else
		dc2h_seq_mode_ctrl1_reg.rgb_to_argb_en = 0;

	if (get_vt_VtSwBufferMode()) {
		dc2h_dma_dc2h_seq_interrupt_enable_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_seq_Interrupt_Enable_reg);
		dc2h_dma_dc2h_seq_interrupt_enable_Reg.vs_rising_ie = 1;
	}
	//dc2h_wait_porch();
	rtd_outl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg, dc2h_seq_mode_ctrl1_reg.regValue);
	if (get_vt_VtSwBufferMode()) {
		rtd_outl(DC2H_DMA_dc2h_seq_Interrupt_Enable_reg, dc2h_dma_dc2h_seq_interrupt_enable_Reg.regValue);
	}
	return;
}


void drvif_dc2h_seqmode_conifg(unsigned char enable, int capWid, int capLen, int capSrc)
{
	dc2h_rgb2yuv_dc2h_rgb2yuv_ctrl_RBUS	dc2h_rgb2yuv_ctrl_reg;
	dc2h_scaledown_dc2h_hsd_ctrl0_RBUS dc2h_hsd_ctrl0_reg;
	dc2h_scaledown_dc2h_vsd_ctrl0_RBUS dc2h_vsd_ctrl0_reg;
	dc2h_dma_dc2h_seq_mode_ctrl1_RBUS dc2h_seq_mode_ctrl1_reg;
	dc2h_dma_dc2h_seq_interrupt_enable_RBUS dc2h_dma_dc2h_seq_interrupt_enable_Reg;
	dc2h_vi_dc2h_dmactl_RBUS vi_dmactl_reg;
	dc2h_vi_dc2h_vi_addcmd_transform_RBUS dc2h_vi_dc2h_vi_addcmd_transform_reg;
	
	ppoverlay_main_den_h_start_end_RBUS main_den_h_start_end_Reg;
	ppoverlay_main_den_v_start_end_RBUS main_den_v_start_end_Reg;
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_Reg;
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_Reg;
	dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_RBUS dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg;
	
	main_den_h_start_end_Reg.regValue = rtd_inl(PPOVERLAY_MAIN_DEN_H_Start_End_reg);
	main_den_v_start_end_Reg.regValue = rtd_inl(PPOVERLAY_MAIN_DEN_V_Start_End_reg);
	main_active_h_start_end_Reg.regValue = rtd_inl(PPOVERLAY_MAIN_Active_H_Start_End_reg);
	main_active_v_start_end_Reg.regValue = rtd_inl(PPOVERLAY_MAIN_Active_V_Start_End_reg);

	pdc2h_hdl = &dc2h_hdl;
	memset(pdc2h_hdl, 0 , sizeof(DC2H_HANDLER));
	pdc2h_hdl->out_size.nWidth = capWid;
	pdc2h_hdl->out_size.nLength = capLen;
	pdc2h_hdl->dc2h_en = enable;


	if(/*(capSrc == 2)&&*/(get_vt_VtCaptureVDC())){
			pdc2h_hdl->in_size.nWidth = DC2H_InputWidth;
			pdc2h_hdl->in_size.nLength = DC2H_InputLength;
			pdc2h_hdl->dc2h_in_sel = _VD_OUTPUT;
	} else {
		if(capSrc == VT_CAP_SRC_VIDEO_NOPQ) {
			/*ppoverlay_uzudtg_control1_RBUS ppoverlay_uzudtg_control1_reg;
			ppoverlay_uzudtg_control1_reg.regValue = rtd_inl(PPOVERLAY_uzudtg_control1_reg);
			if(ppoverlay_uzudtg_control1_reg.two_step_uzu_en ==1) {
				pdc2h_hdl->in_size.nWidth = 1920;
				pdc2h_hdl->in_size.nLength = 1080;
			}else*/ {
				pdc2h_hdl->in_size.nWidth = main_active_h_start_end_Reg.mh_act_end - main_active_h_start_end_Reg.mh_act_sta;
				pdc2h_hdl->in_size.nLength = main_active_v_start_end_Reg.mv_act_end - main_active_v_start_end_Reg.mv_act_sta;
			}

			pdc2h_hdl->dc2h_in_sel = _MAIN_UZU;
		} else {
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL)
				pdc2h_hdl->in_size.nWidth = (main_den_h_start_end_Reg.mh_den_end - main_den_h_start_end_Reg.mh_den_sta)/2;
			else
				pdc2h_hdl->in_size.nWidth = main_den_h_start_end_Reg.mh_den_end - main_den_h_start_end_Reg.mh_den_sta;
			pdc2h_hdl->in_size.nLength = main_den_v_start_end_Reg.mv_den_end - main_den_v_start_end_Reg.mv_den_sta;
			if(capSrc == VT_CAP_SRC_VIDEO_PQ)
				pdc2h_hdl->dc2h_in_sel = _Memc_mux_Output;
			else if(capSrc == VT_CAP_SRC_VIDEO_OSD)
				pdc2h_hdl->dc2h_in_sel = _OSD_MIXER;
		}
	}

	if (enable == TRUE) {
		if(get_vt_VtSwBufferMode())
			drvif_dc2h_swmode_inforpc(TRUE,get_vt_VtBufferNum(),capWid,capLen);
		if(get_vt_VtCaptureVDC()){
			drvif_dc2h_input_overscan_config(DC2H_InputWidthSta, DC2H_InputLengthSta, pdc2h_hdl->in_size.nWidth, pdc2h_hdl->in_size.nLength);
		} else {
			dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.regValue = rtd_inl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg);
			dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.dc2h_3dmaskto2d_3dformat = 0;
			dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.dc2h_3dmaskto2d_en = 0;
			rtd_outl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg, dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.regValue);
		}
		drvif_color_colorspaceyuv2rgbtransfer(pdc2h_hdl->dc2h_in_sel);
		drvif_color_ultrazoom_config_dc2h_scaling_down(pdc2h_hdl);
		if(get_VT_Pixel_Format() == VT_CAP_NV12)
			drvif_vi_config(pdc2h_hdl->out_size.nWidth,pdc2h_hdl->out_size.nLength,0);
		else if (get_VT_Pixel_Format() == VT_CAP_NV16)
			drvif_vi_config(pdc2h_hdl->out_size.nWidth,pdc2h_hdl->out_size.nLength,1);
		else
			drvif_dc2h_seq_config(pdc2h_hdl);
	} else {
		if (get_vt_VtSwBufferMode())
			drvif_dc2h_swmode_inforpc(FALSE,get_vt_VtBufferNum(),capWid,capLen);
		if ((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16))
		{
			vi_dmactl_reg.regValue = rtd_inl(DC2H_VI_DC2H_DMACTL_reg);
			vi_dmactl_reg.dmaen1 = 0;
			rtd_outl(DC2H_VI_DC2H_DMACTL_reg, vi_dmactl_reg.regValue);
			
			dc2h_vi_dc2h_vi_addcmd_transform_reg.regValue = rtd_inl(DC2H_VI_DC2H_vi_addcmd_transform_reg);
			dc2h_vi_dc2h_vi_addcmd_transform_reg.vi_addcmd_trans_en = 0;
			rtd_outl(DC2H_VI_DC2H_vi_addcmd_transform_reg, dc2h_vi_dc2h_vi_addcmd_transform_reg.regValue);			
		}
		dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.regValue = rtd_inl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg);
		dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.dc2h_3dmaskto2d_3dformat = 0;
		dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.dc2h_3dmaskto2d_en = 0;
		rtd_outl(DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg, dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_Reg.regValue);

	
		dc2h_rgb2yuv_ctrl_reg.regValue = rtd_inl(DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg);
		dc2h_rgb2yuv_ctrl_reg.dc2h_in_sel = 0;
		dc2h_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
		rtd_outl(DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg, dc2h_rgb2yuv_ctrl_reg.regValue);

		dc2h_hsd_ctrl0_reg.regValue = rtd_inl(DC2H_SCALEDOWN_DC2H_HSD_Ctrl0_reg);
		dc2h_hsd_ctrl0_reg.h_zoom_en = 0;
		rtd_outl(DC2H_SCALEDOWN_DC2H_HSD_Ctrl0_reg, dc2h_hsd_ctrl0_reg.regValue);

		dc2h_vsd_ctrl0_reg.regValue = rtd_inl(DC2H_SCALEDOWN_DC2H_VSD_Ctrl0_reg);
		dc2h_vsd_ctrl0_reg.v_zoom_en = 0;
		dc2h_vsd_ctrl0_reg.buffer_mode = 0;
		rtd_outl(DC2H_SCALEDOWN_DC2H_VSD_Ctrl0_reg, dc2h_vsd_ctrl0_reg.regValue);
		
		dc2h_dma_dc2h_seq_interrupt_enable_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_seq_Interrupt_Enable_reg);
		dc2h_dma_dc2h_seq_interrupt_enable_Reg.vs_rising_ie = 0;
		rtd_outl(DC2H_DMA_dc2h_seq_Interrupt_Enable_reg, dc2h_dma_dc2h_seq_interrupt_enable_Reg.regValue);

		dc2h_seq_mode_ctrl1_reg.regValue = rtd_inl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg);
		if((get_VT_Pixel_Format() == VT_CAP_ABGR8888)||(get_VT_Pixel_Format() == VT_CAP_ARGB8888))
			dc2h_seq_mode_ctrl1_reg.rgb_to_argb_en = 0;
		dc2h_seq_mode_ctrl1_reg.cap_en = 0;
		rtd_outl(DC2H_DMA_dc2h_Seq_mode_CTRL1_reg, dc2h_seq_mode_ctrl1_reg.regValue);
	}
}

#endif/*qiangzhou:move dc2h driver from kernel to kernel here end*/

unsigned char IndexOfFreezedVideoFrameBuffer = 0;
unsigned int freezebufferaddr;
unsigned int lastcapbufferindex = 0;
void set_vfod_freezed(unsigned char boffon)
{
	if (boffon == TRUE) {
		if((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16)){
			if(get_vt_VtBufferNum()==5) {
				dc2h_vi_dc2h_vi_ads_start_y_RBUS DC2H_VI_DC2H_vi_ads_start_y_Reg;
				dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_Reg;
				unsigned int lastcapbufferaddr = 0;
				DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue = rtd_inl(DC2H_VI_DC2H_vi_ads_start_y_reg);
				dc2h_cap_l3_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L3_Start_reg);
		
				if(DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[4].phyaddr;
				}else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
				}else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
				}else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
				}else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[4].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
				}
		
				if(lastcapbufferaddr == dc2h_cap_l3_start_Reg.regValue){
					if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[4].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[4].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
					}
				}
				if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 0;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 1;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 2;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 3;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[4].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 4;
				}
				rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg,lastcapbufferaddr);
			} else if(get_vt_VtBufferNum()==4) {
				dc2h_vi_dc2h_vi_ads_start_y_RBUS DC2H_VI_DC2H_vi_ads_start_y_Reg;
				dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_Reg;
				unsigned int lastcapbufferaddr = 0;
				DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue = rtd_inl(DC2H_VI_DC2H_vi_ads_start_y_reg);
				dc2h_cap_l3_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L3_Start_reg);

		
				if(DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
				}else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
				}else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
				}else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
				}
		
				if(lastcapbufferaddr == dc2h_cap_l3_start_Reg.regValue){
					if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
					}
				}
				if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 0;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 1;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 2;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 3;
				}	
				rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg,lastcapbufferaddr);
			} else if(get_vt_VtBufferNum()==3) {
				dc2h_vi_dc2h_vi_ads_start_y_RBUS DC2H_VI_DC2H_vi_ads_start_y_Reg;
				dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_Reg;
				unsigned int lastcapbufferaddr = 0;
				DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue = rtd_inl(DC2H_VI_DC2H_vi_ads_start_y_reg);
				dc2h_cap_l3_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L3_Start_reg);


	           if(DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
	                   lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
	           }else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
	                   lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
	           }else if (DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
	                   lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
	           }

	           if(lastcapbufferaddr == dc2h_cap_l3_start_Reg.regValue){
	                   if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
	                           lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
	                   }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
	                           lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
	                   }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
	                           lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
	                   }
	           }
	           if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
	                   IndexOfFreezedVideoFrameBuffer = 0;
	           }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
	                   IndexOfFreezedVideoFrameBuffer = 1;
	           }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
	                   IndexOfFreezedVideoFrameBuffer = 2;
	           }       
	           rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg,lastcapbufferaddr);
	        }

		} else {
			if(get_vt_VtBufferNum()==5) {
				dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_Reg;
				dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_Reg;
				unsigned int lastcapbufferaddr = 0;
				dc2h_cap_l1_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L1_Start_db_reg);
				
				dc2h_cap_l3_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L3_Start_reg);
		
				if(dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[4].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[4].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
				}
		
				if(lastcapbufferaddr == dc2h_cap_l3_start_Reg.regValue){
					if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[4].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[4].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
					}
				}
				if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 0;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 1;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 2;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 3;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[4].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 4;
				}
				rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg,lastcapbufferaddr);
			} else if(get_vt_VtBufferNum()==4) {
				dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_Reg;
				dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_Reg;
				unsigned int lastcapbufferaddr;
				dc2h_cap_l1_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L1_Start_db_reg);
				
				dc2h_cap_l3_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L3_Start_reg);
		
				if(dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
				}
		
				if(lastcapbufferaddr == dc2h_cap_l3_start_Reg.regValue){
					if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
					}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
						lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
					}
				}
				if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 0;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 1;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 2;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					IndexOfFreezedVideoFrameBuffer = 3;
				}	
				rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg,lastcapbufferaddr);
			} else if(get_vt_VtBufferNum()==3) {
	           dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_Reg;
	           dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_Reg;
	           unsigned int lastcapbufferaddr = 0;
	           dc2h_cap_l1_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L1_Start_db_reg);
	           
	           dc2h_cap_l3_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L3_Start_reg);

	           if(dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
	                   lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
	           }else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
	                   lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
	           }else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
	                   lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
	           }

	           if(lastcapbufferaddr == dc2h_cap_l3_start_Reg.regValue){
	                   if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
	                           lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
	                   }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
	                           lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
	                   }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
	                           lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
	                   }
	           }
	           if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
	                   IndexOfFreezedVideoFrameBuffer = 0;
	           }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
	                   IndexOfFreezedVideoFrameBuffer = 1;
	           }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
	                   IndexOfFreezedVideoFrameBuffer = 2;
	           }       
	           rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg,lastcapbufferaddr);
	        }
		}
	}else{
		//rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg,0);
		//do nothing
	}
}

unsigned char Capture_BufferMemInit_VT(unsigned int buffernum) {
	unsigned int size;// = VT_CAPTURE_BUFFER_UNITSIZE;
	int i;
	unsigned int malloccacheaddr;

	if((get_VT_Pixel_Format() == VT_CAP_ABGR8888)||(get_VT_Pixel_Format() == VT_CAP_ARGB8888))
		VT_CAPTURE_BUFFER_UNITSIZE = _ALIGN(1920*1080*4,__4KPAGE);
	else if(get_VT_Pixel_Format() == VT_CAP_NV12)
		VT_CAPTURE_BUFFER_UNITSIZE = NV_FORMAT_YBUFFER_SIZE + NV12_FORMAT_CBUFFER_SIZE;
	else if(get_VT_Pixel_Format() == VT_CAP_NV16)
		VT_CAPTURE_BUFFER_UNITSIZE = NV_FORMAT_YBUFFER_SIZE + NV16_FORMAT_CBUFFER_SIZE;
	else
		VT_CAPTURE_BUFFER_UNITSIZE = _ALIGN(1920*1080*3,__4KPAGE);
	size = VT_CAPTURE_BUFFER_UNITSIZE;
	malloccacheaddr = (unsigned int)dvr_malloc_specific(size * buffernum, GFP_DCU2_FIRST);
	if(malloccacheaddr == (unsigned int)NULL)
	{
		
		rtd_printk(KERN_NOTICE, TAG_NAME,"Warning:alloc VT memory failed\n");
		return FALSE;
	}

	for (i=0; i<buffernum; i++) {
		if(CaptureCtrl_VT.cap_buffer[i].cache == NULL){
			CaptureCtrl_VT.cap_buffer[i].cache = (void*)(malloccacheaddr+i*size);
			//CaptureCtrl_VT.cap_buffer[i].phyaddr =  (unsigned int)virt_to_phys((void*)CaptureCtrl_VT.cap_buffer[i].cache);
			CaptureCtrl_VT.cap_buffer[i].phyaddr =  (unsigned int)dvr_to_phys((void*)CaptureCtrl_VT.cap_buffer[i].cache);
			CaptureCtrl_VT.cap_buffer[i].size = size;
			rtd_printk(KERN_DEBUG, TAG_NAME,"[VT memory allocate] buf[%d]=%x(%d KB), phy(%x) \n", i, (UINT32)CaptureCtrl_VT.cap_buffer[i].cache, CaptureCtrl_VT.cap_buffer[i].size >> 10, (UINT32)CaptureCtrl_VT.cap_buffer[i].phyaddr);
		}
	}
	return TRUE;
}

void Capture_BufferMemDeInit_VT(unsigned int buffernum) {
	int i;
	if (CaptureCtrl_VT.cap_buffer[0].cache)
	{
		dvr_free(CaptureCtrl_VT.cap_buffer[0].cache);
	}

	for (i=0; i<buffernum; i++)
	{
		if (CaptureCtrl_VT.cap_buffer[i].cache)
		{
			CaptureCtrl_VT.cap_buffer[i].cache = NULL;
			CaptureCtrl_VT.cap_buffer[i].phyaddr = (unsigned long)NULL;
			CaptureCtrl_VT.cap_buffer[i].size = 0;
		}
	}
	rtd_printk(KERN_DEBUG, TAG_NAME,"[VT memory free] Deinit done!\n");
}


/*qiangzhou implement for k2h vt with dc2h squence rgb mode*/

void drvif_DC2H_dispD_CaptureConfig(VT_CUR_CAPTURE_INFO capInfo,unsigned char waitbufferfresh)
{
	struct timespec timeout_s;
	unsigned int waitbufferms = 32;

	if(capInfo.enable == TRUE){
		if((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16)){		
			dc2h_vi_dc2h_vi_ads_start_y_RBUS DC2H_VI_DC2H_vi_ads_start_y_Reg;
			dc2h_vi_dc2h_vi_ads_start_c_RBUS dc2h_vi_dc2h_vi_ads_start_c_Reg;
			dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_reg;
			dc2h_scaledown_dc2h_444to422_ctrl_RBUS dc2h_scaledown_dc2h_444to422_ctrl_reg;

			dc2h_scaledown_dc2h_444to422_ctrl_reg.regValue = rtd_inl(DC2H_SCALEDOWN_DC2H_444to422_CTRL_reg);
			if(VTDumpLocation==KADP_VT_SCALER_OUTPUT)
				dc2h_scaledown_dc2h_444to422_ctrl_reg.cbcr_swap_en =1;
			else
				dc2h_scaledown_dc2h_444to422_ctrl_reg.cbcr_swap_en =0;
			rtd_outl(DC2H_SCALEDOWN_DC2H_444to422_CTRL_reg, dc2h_scaledown_dc2h_444to422_ctrl_reg.regValue);  //used record freeze buffer
			
			dc2h_cap_l3_start_reg.regValue= 0;
			rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg, dc2h_cap_l3_start_reg.regValue);  //used record freeze buffer

			DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue = (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
			IoReg_Write32(DC2H_VI_DC2H_vi_ads_start_y_reg, DC2H_VI_DC2H_vi_ads_start_y_Reg.regValue);
			
			dc2h_vi_dc2h_vi_ads_start_c_Reg.regValue = (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr + NV_FORMAT_YBUFFER_SIZE;
			IoReg_Write32(DC2H_VI_DC2H_vi_ads_start_c_reg, dc2h_vi_dc2h_vi_ads_start_c_Reg.regValue);
		} else {
			if(get_vt_VtBufferNum() == 1) {
				dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_reg;
				dc2h_dma_dc2h_cap_boundaryaddr1_RBUS dc2h_cap_boundaryaddr1_reg;
				dc2h_dma_dc2h_cap_boundaryaddr2_RBUS dc2h_cap_boundaryaddr2_reg;
				dc2h_cap_l1_start_reg.regValue= (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
				rtd_outl(DC2H_DMA_dc2h_Cap_L1_Start_reg, dc2h_cap_l1_start_reg.regValue);  // block0, DDR buffer L1 start address

				dc2h_cap_boundaryaddr1_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr +  (UINT32)CaptureCtrl_VT.cap_buffer[0].size;
				rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg, dc2h_cap_boundaryaddr1_reg.regValue);

				dc2h_cap_boundaryaddr2_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
				rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg, dc2h_cap_boundaryaddr2_reg.regValue);
			} else {
				dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_reg;
				dc2h_dma_dc2h_cap_l2_start_RBUS dc2h_cap_l2_start_reg;
				dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_reg;

				dc2h_dma_dc2h_cap_boundaryaddr1_RBUS dc2h_cap_boundaryaddr1_reg;
				dc2h_dma_dc2h_cap_boundaryaddr2_RBUS dc2h_cap_boundaryaddr2_reg;

				if (get_vt_VtCaptureVDC()){
						dc2h_cap_l1_start_reg.regValue= (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_L1_Start_reg, dc2h_cap_l1_start_reg.regValue);  // block0, DDR buffer L1 start address

						dc2h_cap_l2_start_reg.regValue= (UINT32)CaptureCtrl_VT.cap_buffer[1].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_L2_Start_reg, dc2h_cap_l2_start_reg.regValue);  // block0, DDR buffer L2 start address

						dc2h_cap_l3_start_reg.regValue= (UINT32)CaptureCtrl_VT.cap_buffer[2].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg, dc2h_cap_l3_start_reg.regValue);  // block0, DDR buffer L3 start address

						dc2h_cap_boundaryaddr1_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[2].phyaddr +  (UINT32)CaptureCtrl_VT.cap_buffer[2].size;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg, dc2h_cap_boundaryaddr1_reg.regValue);

						dc2h_cap_boundaryaddr2_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg, dc2h_cap_boundaryaddr2_reg.regValue);			
				} else {
					if(get_vt_VtBufferNum()==5) {
						dc2h_cap_l1_start_reg.regValue= (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_L1_Start_reg, dc2h_cap_l1_start_reg.regValue);  // block0, DDR buffer L1 start address

						dc2h_cap_l2_start_reg.regValue= 0;
						rtd_outl(DC2H_DMA_dc2h_Cap_L2_Start_reg, dc2h_cap_l2_start_reg.regValue);  // block0, DDR buffer L2 start address

						dc2h_cap_l3_start_reg.regValue= 0;
						rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg, dc2h_cap_l3_start_reg.regValue);  // block0, DDR buffer L3 start address

						dc2h_cap_boundaryaddr1_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[4].phyaddr +  (UINT32)CaptureCtrl_VT.cap_buffer[4].size;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg, dc2h_cap_boundaryaddr1_reg.regValue);

						dc2h_cap_boundaryaddr2_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg, dc2h_cap_boundaryaddr2_reg.regValue);
					} else if(get_vt_VtBufferNum()==4){
						dc2h_cap_l1_start_reg.regValue= (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_L1_Start_reg, dc2h_cap_l1_start_reg.regValue);	// block0, DDR buffer L1 start address

						dc2h_cap_l2_start_reg.regValue= 0;
						rtd_outl(DC2H_DMA_dc2h_Cap_L2_Start_reg, dc2h_cap_l2_start_reg.regValue);	// block0, DDR buffer L2 start address

						dc2h_cap_l3_start_reg.regValue= 0;
						rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg, dc2h_cap_l3_start_reg.regValue);	// block0, DDR buffer L3 start address

						dc2h_cap_boundaryaddr1_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[3].phyaddr +  (UINT32)CaptureCtrl_VT.cap_buffer[3].size;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg, dc2h_cap_boundaryaddr1_reg.regValue);

						dc2h_cap_boundaryaddr2_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg, dc2h_cap_boundaryaddr2_reg.regValue);

					} else if(get_vt_VtBufferNum()==3){
						dc2h_cap_l1_start_reg.regValue= (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_L1_Start_reg, dc2h_cap_l1_start_reg.regValue);	// block0, DDR buffer L1 start address

						dc2h_cap_l2_start_reg.regValue= 0;
						rtd_outl(DC2H_DMA_dc2h_Cap_L2_Start_reg, dc2h_cap_l2_start_reg.regValue);	// block0, DDR buffer L2 start address

						dc2h_cap_l3_start_reg.regValue= 0;
						rtd_outl(DC2H_DMA_dc2h_Cap_L3_Start_reg, dc2h_cap_l3_start_reg.regValue);	// block0, DDR buffer L3 start address

						dc2h_cap_boundaryaddr1_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[2].phyaddr +  (UINT32)CaptureCtrl_VT.cap_buffer[2].size;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg, dc2h_cap_boundaryaddr1_reg.regValue);

						dc2h_cap_boundaryaddr2_reg.regValue =  (UINT32)CaptureCtrl_VT.cap_buffer[0].phyaddr;
						rtd_outl(DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg, dc2h_cap_boundaryaddr2_reg.regValue);

					}
				}
			}
		}
		drvif_dc2h_seqmode_conifg(TRUE, capInfo.capWid, capInfo.capLen, capInfo.capSrc);

		if(waitbufferfresh == TRUE) {
			rtd_printk(KERN_DEBUG, TAG_NAME,"waitbufferms = %d\n", waitbufferms);
			timeout_s = ns_to_timespec(waitbufferms * 1000 * 1000);
			hrtimer_nanosleep(&timeout_s, NULL, HRTIMER_MODE_REL, CLOCK_MONOTONIC);
		}
	} else {
		if((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16)){		
			dc2h_scaledown_dc2h_444to422_ctrl_RBUS dc2h_scaledown_dc2h_444to422_ctrl_reg;
			
			dc2h_scaledown_dc2h_444to422_ctrl_reg.regValue = rtd_inl(DC2H_SCALEDOWN_DC2H_444to422_CTRL_reg);
			if(VTDumpLocation==KADP_VT_SCALER_OUTPUT)
				dc2h_scaledown_dc2h_444to422_ctrl_reg.cbcr_swap_en =0;
			rtd_outl(DC2H_SCALEDOWN_DC2H_444to422_CTRL_reg, dc2h_scaledown_dc2h_444to422_ctrl_reg.regValue);  //used record freeze buffer
		}
		drvif_dc2h_seqmode_conifg(FALSE, capInfo.capWid, capInfo.capLen, capInfo.capSrc);
	}
}

unsigned char HAL_VT_InitEx(unsigned int buffernum)
{
	down(&VT_Semaphore);
	
	if(get_vt_function()==FALSE) {
		
		set_vt_function(TRUE);
		curCapInfo.enable = 1; //iMode;
		curCapInfo.capSrc =  VT_CAP_SRC_VIDEO_PQ;  //0:scaler output 1:display output
		curCapInfo.capMode = VT_CAP_MODE_SEQ;
		curCapInfo.capWid = 1280; //iWid;
		curCapInfo.capLen = 720;
		
		if (Capture_BufferMemInit_VT(buffernum) == FALSE) {
			rtd_printk(KERN_NOTICE, TAG_NAME, "VT init allocate memory fail;%s=%d \n", __FUNCTION__, __LINE__);
			up(&VT_Semaphore);
			return FALSE;
		}
		set_vt_VtBufferNum(buffernum);
		set_vt_VtSwBufferMode(TRUE);
		set_vt_VtCaptureVDC(FALSE);
		drvif_DC2H_dispD_CaptureConfig(curCapInfo,FALSE);
#if 0/*data dump verify*/		
		msleep(1000);
		vt_dump_data_to_file(0, 1920*1080+1920*540);
#endif
		VFODState.bEnabled =TRUE;
		VFODState.bAppliedPQ=TRUE;
		VFODState.bFreezed =FALSE;
		VFODState.framerateDivide =FALSE;
		VTDumpLocation = KADP_VT_DISPLAY_OUTPUT;
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT init Success;%s=%d \n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	} else {
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT have inited,do nothing;%s=%d \n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	}
	
}

unsigned char HAL_VT_Init(void)
{
	rtd_printk(KERN_NOTICE, TAG_NAME, "%s=%d \n", __FUNCTION__, __LINE__);		

	if(HAL_VT_InitEx(3)==FALSE)
		return FALSE;
	else
		return TRUE;
#if 0/*ATV enter dc2h test code*/
	down(&VT_Semaphore);
	VIDEO_RECT_T inregion;
	VIDEO_RECT_T outregion;
	inregion.x = 0x96;
	inregion.y = 0x14;
	inregion.w = 1440;
	inregion.h = 288;

	outregion.x = 0;
	outregion.y = 0;
	outregion.w = 1440;
	outregion.h = 288;	
	rtk_dc2h_capturevdc_config(TRUE, inregion, outregion);

	msleep(2000);
	//vt_dump_data_to_file(0);
	Scaler_SubMDispWindow_VFB(TRUE);

	up(&VT_Semaphore);
#endif
}

unsigned char HAL_VT_Finalize(void)
{
	down(&VT_Semaphore);
	if(get_vt_function()==TRUE) {
		curCapInfo.enable = 0; //iMode;
		drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
		Capture_BufferMemDeInit_VT(get_vt_VtBufferNum());
		set_vt_VtBufferNum(3);
		set_VT_Pixel_Format(VT_CAP_RGB888);
		set_vt_VtSwBufferMode(FALSE);
		VFODState.bEnabled =FALSE;
		VFODState.bAppliedPQ=TRUE;
		VFODState.bFreezed =FALSE;
		VFODState.framerateDivide =FALSE;
		VTDumpLocation = KADP_VT_DISPLAY_OUTPUT;
		set_vt_function(FALSE);
		up(&VT_Semaphore);
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT finalize Success;%s=%d \n", __FUNCTION__, __LINE__);
		return TRUE;
	} else {
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT have finalized,do nothing;%s=%d \n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	}

}

unsigned char HAL_VT_GetDeviceCapability(KADP_VT_DEVICE_CAPABILITY_INFO_T *pDeviceCapabilityInfo)
{
	down(&VT_Semaphore);
	pDeviceCapabilityInfo->numOfVideoWindow = 1;
	up(&VT_Semaphore);
	return TRUE;
}


unsigned char HAL_VT_GetVideoFrameBufferCapability(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T *pVideoFrameBufferCapabilityInfo)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	pVideoFrameBufferCapabilityInfo ->numOfVideoFrameBuffer = get_vt_VtBufferNum();//i3ddma triple buffer mode

	if((get_VT_Pixel_Format() == VT_CAP_NV12)||(get_VT_Pixel_Format() == VT_CAP_NV16)){	
		pVideoFrameBufferCapabilityInfo ->numOfPlane = KADP_VT_VIDEO_FRAME_BUFFER_PLANE_SEMI_PLANAR;
	} else {
		pVideoFrameBufferCapabilityInfo ->numOfPlane = KADP_VT_VIDEO_FRAME_BUFFER_PLANE_INTERLEAVED;//sequence buffer
	}
	up(&VT_Semaphore);
	return TRUE;
}

unsigned char HAL_VT_GetVideoFrameOutputDeviceCapability(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T *pVideoFrameOutputDeviceCapabilityInfo)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	pVideoFrameOutputDeviceCapabilityInfo ->bSupportedControlEnabled = TRUE;
	pVideoFrameOutputDeviceCapabilityInfo ->bSupportedControlFreezed = TRUE;//VI block mode disble endma
	pVideoFrameOutputDeviceCapabilityInfo ->bSupportedControlFramerateDivide = FALSE;
	pVideoFrameOutputDeviceCapabilityInfo ->bSupportedControlPQ = FALSE;
	up(&VT_Semaphore);
	return TRUE;
}

unsigned char HAL_VT_GetVideoFrameOutputDeviceLimitation(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T *pVideoFrameOutputDeviceLimitationInfo)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	pVideoFrameOutputDeviceLimitationInfo->maxResolution = (KADP_VT_RECT_T){0,0,1280,720};
	pVideoFrameOutputDeviceLimitationInfo->bLeftTopAlign = FALSE;
	pVideoFrameOutputDeviceLimitationInfo->bSupportInputVideoDeInterlacing =FALSE;
	pVideoFrameOutputDeviceLimitationInfo->bSupportDisplayVideoDeInterlacing = FALSE;
	pVideoFrameOutputDeviceLimitationInfo->bSupportScaleUp = FALSE;
	pVideoFrameOutputDeviceLimitationInfo->scaleUpLimitWidth = 0;
	pVideoFrameOutputDeviceLimitationInfo->scaleUpLimitHeight = 0;
	pVideoFrameOutputDeviceLimitationInfo->bSupportScaleDown = TRUE;
	pVideoFrameOutputDeviceLimitationInfo->scaleDownLimitWidth = 60;//nfactor upto 32
	pVideoFrameOutputDeviceLimitationInfo->scaleDownLimitHeight = 34;
	up(&VT_Semaphore);
	return TRUE;
}

unsigned char HAL_VT_GetAllVideoFrameBufferProperty(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T *pVideoFrameBufferProperty)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	if(get_vt_function() == TRUE) {
		/*rtd_printk(KERN_DEBUG, TAG_NAME, "Kernel: pVideoFrameBufferProperty->ppPhysicalAddress addr =%x\n", (unsigned int)(pVideoFrameBufferProperty->ppPhysicalAddress));*/

	if(get_VT_Pixel_Format() == VT_CAP_NV16){	
		pVideoFrameBufferProperty->pixelFormat = KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_SEMI_PLANAR;
		pVideoFrameBufferProperty->stride = curCapInfo.capWid;
		pVideoFrameBufferProperty->width = curCapInfo.capWid;		
	}else if(get_VT_Pixel_Format() == VT_CAP_NV12){	
		pVideoFrameBufferProperty->pixelFormat = KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_SEMI_PLANAR;
		pVideoFrameBufferProperty->stride = curCapInfo.capWid;
		pVideoFrameBufferProperty->width = curCapInfo.capWid;		
	}else if((get_VT_Pixel_Format() == VT_CAP_ABGR8888)||(get_VT_Pixel_Format() == VT_CAP_ARGB8888)) {
		pVideoFrameBufferProperty->pixelFormat = KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_ARGB;
		pVideoFrameBufferProperty->stride = curCapInfo.capWid*4;
		pVideoFrameBufferProperty->width = curCapInfo.capWid*4;
	} else {
		pVideoFrameBufferProperty->pixelFormat = KADP_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_RGB;
		pVideoFrameBufferProperty->stride = curCapInfo.capWid*3;
		pVideoFrameBufferProperty->width = curCapInfo.capWid*3;
	}
		pVideoFrameBufferProperty->height = curCapInfo.capLen;
		pVideoFrameBufferProperty->ppPhysicalAddress0 = CaptureCtrl_VT.cap_buffer[0].phyaddr;
		pVideoFrameBufferProperty->ppPhysicalAddress1 = CaptureCtrl_VT.cap_buffer[1].phyaddr;
		pVideoFrameBufferProperty->ppPhysicalAddress2 = CaptureCtrl_VT.cap_buffer[2].phyaddr;
		pVideoFrameBufferProperty->ppPhysicalAddress3 = CaptureCtrl_VT.cap_buffer[3].phyaddr;
		pVideoFrameBufferProperty->ppPhysicalAddress4 = CaptureCtrl_VT.cap_buffer[4].phyaddr;
		pVideoFrameBufferProperty->vfbbuffernumber = get_vt_VtBufferNum();
		up(&VT_Semaphore);
		return TRUE;
	} else {
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT is not Inited So return False;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return FALSE;
	}
}

unsigned char HAL_VT_GetVideoFrameBufferIndex(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned int *pIndexOfCurrentVideoFrameBuffer)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);

	if(get_vt_function() == TRUE) {
		if(VFODState.bFreezed == TRUE) {
			*pIndexOfCurrentVideoFrameBuffer = IndexOfFreezedVideoFrameBuffer;
			rtd_printk(KERN_DEBUG, TAG_NAME,  "VFOD is freezed\n");
		} else {
			rtd_printk(KERN_DEBUG, TAG_NAME,  "VFOD is not freezed\n");
			if (get_vt_VtBufferNum() == 5){
				dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_Reg;
				unsigned int lastcapbufferaddr;
				dc2h_cap_l1_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L1_Start_db_reg);
			
				//dc2h_dma_dc2h_cap_l3_start_RBUS dc2h_cap_l3_start_Reg;
				//dc2h_cap_l3_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L3_Start_reg);

				if(dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[4].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[4].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
				}
				
				if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 0;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 1;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 2;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 3;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[4].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 4;
				}	
			} else if(get_vt_VtBufferNum() == 4){
				dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_Reg;
				unsigned int lastcapbufferaddr = 0;
				dc2h_cap_l1_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L1_Start_db_reg);
						
				if(dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[3].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
				}else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
				}

				if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 0;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 1;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 2;
				}else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[3].phyaddr){
					*pIndexOfCurrentVideoFrameBuffer = 3;
				}
			} else if(get_vt_VtBufferNum() == 3){
               dc2h_dma_dc2h_cap_l1_start_RBUS dc2h_cap_l1_start_Reg;
               unsigned int lastcapbufferaddr = 0;
               dc2h_cap_l1_start_Reg.regValue = rtd_inl(DC2H_DMA_dc2h_Cap_L1_Start_db_reg);

               if(dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[0].phyaddr){
                       lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
              }else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[1].phyaddr){
                       lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[0].phyaddr;
               }else if (dc2h_cap_l1_start_Reg.regValue == CaptureCtrl_VT.cap_buffer[2].phyaddr){
                       lastcapbufferaddr = CaptureCtrl_VT.cap_buffer[1].phyaddr;
               }

               if(lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[0].phyaddr){
                       *pIndexOfCurrentVideoFrameBuffer = 0;
               }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[1].phyaddr){
                       *pIndexOfCurrentVideoFrameBuffer = 1;
               }else if (lastcapbufferaddr == CaptureCtrl_VT.cap_buffer[2].phyaddr){
                       *pIndexOfCurrentVideoFrameBuffer = 2;
               }
       		}				
		}
		up(&VT_Semaphore);
		return TRUE;
	} else {
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT is not Inited So return False;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return FALSE;
	}
}

unsigned char HAL_VT_GetVideoFrameOutputDeviceState(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T *pVideoFrameOutputDeviceState)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	*pVideoFrameOutputDeviceState = VFODState;
	up(&VT_Semaphore);
	return TRUE;
}

unsigned char HAL_VT_SetVideoFrameOutputDeviceState(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T videoFrameOutputDeviceStateFlags, KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T *pVideoFrameOutputDeviceState)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	if(videoFrameOutputDeviceStateFlags==KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX is do nothing\n");
		return TRUE;
	}
#if 0//not support aplly pq and framerate divide
	if(videoFrameOutputDeviceStateFlags&HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE) {
		printk("HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE is not support\n");
		return FALSE;
	}

	if(videoFrameOutputDeviceStateFlags&HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_APPLIED_PQ) {
		if(pVideoFrameOutputDeviceState->bAppliedPQ)
			curCapInfo.capSrc =  VT_CAP_SRC_SUBTITLE;
		else
			curCapInfo.capSrc =  VT_CAP_SRC_UZU;
		VFODState.bAppliedPQ = pVideoFrameOutputDeviceState->bAppliedPQ;
		if(pVideoFrameOutputDeviceState->bAppliedPQ)
			VTDumpLocation = HAL_VT_DISPLAY_OUTPUT;
		else
			VTDumpLocation = HAL_VT_SCALER_OUTPUT;
	}
#endif
	down(&VT_Semaphore);
	if (videoFrameOutputDeviceStateFlags&KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_ENABLED) {
		if (VFODState.bEnabled != pVideoFrameOutputDeviceState->bEnabled) {
			curCapInfo.enable = pVideoFrameOutputDeviceState->bEnabled;
			VFODState.bEnabled = pVideoFrameOutputDeviceState->bEnabled;
			drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
		}
	}

	if(videoFrameOutputDeviceStateFlags&KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE is %d\n",pVideoFrameOutputDeviceState->framerateDivide);
		VFODState.framerateDivide = pVideoFrameOutputDeviceState->framerateDivide;
		
	}

	/*freeze do last*/
	if(videoFrameOutputDeviceStateFlags&KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED) {
		if(get_vt_function() == TRUE) {
			if(pVideoFrameOutputDeviceState->bFreezed == VFODState.bFreezed) {
				rtd_printk(KERN_DEBUG, TAG_NAME, "HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED is the same as you setting\n");
			} else {
				set_vfod_freezed(pVideoFrameOutputDeviceState->bFreezed);
				VFODState.bFreezed = pVideoFrameOutputDeviceState->bFreezed;
			}
		} else {
			rtd_printk(KERN_NOTICE, TAG_NAME, "VFOD is not inited, so no freeze cmd!\n");
		}
	}
	up(&VT_Semaphore);
	return TRUE;
}

/*qiangzhou:please refer modestate_decide_dtg_m_mode api SLR_INPUT_DTG_MASTER_V_FREQ setting*/
unsigned short Get_VFOD_FrameRate(void)
{
		unsigned short framerate = 0;

		framerate = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DTG_MASTER_V_FREQ);

		if ((framerate != 50)&&(framerate != 60)&&(framerate != 48)) {
			
			rtd_printk(KERN_NOTICE, TAG_NAME, "[warning] get SLR_INPUT_DTG_MASTER_V_FREQ not right!!!\n");
			framerate = 60;
		}

		if (Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL) {
			if(framerate == 48){/*qiangzhou: not happen case, mention here*/
				framerate = 120;
			} else {	
				framerate = framerate*2;
			}
		}
		return framerate;

}

unsigned char HAL_VT_GetVideoFrameOutputDeviceFramerate(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned int *pVideoFrameOutputDeviceFramerate)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	
	if(get_vt_function() == TRUE) {	
		*pVideoFrameOutputDeviceFramerate = Get_VFOD_FrameRate();
		up(&VT_Semaphore);
		return TRUE;
	} else {
		*pVideoFrameOutputDeviceFramerate = 0;
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT is not Inited So return pVideoFrameOutputDeviceFramerate 0;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	}
}

unsigned char HAL_VT_GetVideoFrameOutputDeviceDumpLocation(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_DUMP_LOCATION_TYPE_T *pDumpLocation)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	if(get_vt_function() == TRUE) {
		*pDumpLocation = VTDumpLocation;
		up(&VT_Semaphore);
		return TRUE;
	} else {
		*pDumpLocation = VTDumpLocation;
		rtd_printk(KERN_NOTICE, TAG_NAME, "[Warning]VT is not Inited when get dump location;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	}
}

unsigned char HAL_VT_SetVideoFrameOutputDeviceDumpLocation(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_DUMP_LOCATION_TYPE_T dumpLocation)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	if(get_vt_function() == TRUE)
	{
		if(VTDumpLocation == dumpLocation) {
			rtd_printk(KERN_DEBUG, TAG_NAME, "VTDumpLocation is the same as you setting\n");
		} else {
			curCapInfo.enable = 0; //close vfod first then rerun
			drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
			curCapInfo.enable = 1;

			if(dumpLocation==KADP_VT_DISPLAY_OUTPUT)
				curCapInfo.capSrc =  VT_CAP_SRC_VIDEO_PQ;
			else if(dumpLocation==KADP_VT_SCALER_OUTPUT)
				curCapInfo.capSrc =  VT_CAP_SRC_VIDEO_NOPQ;
			else if(dumpLocation==KADP_VT_OSDVIDEO_OUTPUT)
				curCapInfo.capSrc =  VT_CAP_SRC_VIDEO_OSD;
			
			drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
			
			if(dumpLocation==KADP_VT_SCALER_OUTPUT)
				VFODState.bAppliedPQ = FALSE;
			else
				VFODState.bAppliedPQ = TRUE;
			VTDumpLocation = dumpLocation;

			if(VFODState.bFreezed == TRUE) {
				set_vfod_freezed(TRUE);//revert freezed status
			}
		}
		up(&VT_Semaphore);
		return TRUE;
	} else {
		rtd_printk(KERN_NOTICE, TAG_NAME, "[Warning]VT is not Inited when set dump location;%s=%d\n", __FUNCTION__, __LINE__);
		VTDumpLocation = dumpLocation;
		up(&VT_Semaphore);
		return TRUE;
	}
}

unsigned char HAL_VT_GetVideoFrameOutputDeviceOutputInfo(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_DUMP_LOCATION_TYPE_T dumpLocation, KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T *pOutputInfo)
{
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;
	ppoverlay_main_den_h_start_end_RBUS main_den_h_start_end_Reg;
	ppoverlay_main_den_v_start_end_RBUS main_den_v_start_end_Reg;
	unsigned int x,y,w,h;
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	//Main Active H pos
	main_active_h_start_end_reg.regValue = rtd_inl(PPOVERLAY_MAIN_Active_H_Start_End_reg);
	//Main Active V pos
	main_active_v_start_end_reg.regValue = rtd_inl(PPOVERLAY_MAIN_Active_V_Start_End_reg);

	main_den_h_start_end_Reg.regValue = rtd_inl(PPOVERLAY_MAIN_DEN_H_Start_End_reg);
	main_den_v_start_end_Reg.regValue = rtd_inl(PPOVERLAY_MAIN_DEN_V_Start_End_reg);
	
	if((get_vt_function() == TRUE)&&(dumpLocation ==VTDumpLocation )) {
		if((KADP_VT_DISPLAY_OUTPUT==dumpLocation)||(KADP_VT_OSDVIDEO_OUTPUT==dumpLocation)){
			pOutputInfo->maxRegion.x = 0;
			pOutputInfo->maxRegion.y =0;
			pOutputInfo->maxRegion.w = curCapInfo.capWid;
			pOutputInfo->maxRegion.h = curCapInfo.capLen;

			x = main_active_h_start_end_reg.mh_act_sta;
			y =main_active_v_start_end_reg.mv_act_sta;
			w =main_active_h_start_end_reg.mh_act_end - main_active_h_start_end_reg.mh_act_sta;
			h = main_active_v_start_end_reg.mv_act_end - main_active_v_start_end_reg.mv_act_sta;

			//scaledown:
			x = x*curCapInfo.capWid;
			x = x/(main_den_h_start_end_Reg.mh_den_end -main_den_h_start_end_Reg.mh_den_sta);

			y = y*curCapInfo.capLen;
			y = y/(main_den_v_start_end_Reg.mv_den_end - main_den_v_start_end_Reg.mv_den_sta);

			w = w*curCapInfo.capWid;
			w = w/(main_den_h_start_end_Reg.mh_den_end -main_den_h_start_end_Reg.mh_den_sta);

			h = h*curCapInfo.capLen;
			h = h/(main_den_v_start_end_Reg.mv_den_end - main_den_v_start_end_Reg.mv_den_sta);

			pOutputInfo->activeRegion.x = x;
			pOutputInfo->activeRegion.y =y;
			pOutputInfo->activeRegion.w = w;
			pOutputInfo->activeRegion.h = h;
			pOutputInfo->stride = curCapInfo.capWid;
		} else if(KADP_VT_SCALER_OUTPUT==dumpLocation) {
			pOutputInfo->maxRegion.x = 0;
			pOutputInfo->maxRegion.y =0;
			pOutputInfo->maxRegion.w = curCapInfo.capWid;
			pOutputInfo->maxRegion.h = curCapInfo.capLen;

			pOutputInfo->activeRegion.x = 0;
			pOutputInfo->activeRegion.y =0;
			pOutputInfo->activeRegion.w = curCapInfo.capWid;
			pOutputInfo->activeRegion.h = curCapInfo.capLen;

			pOutputInfo->stride = curCapInfo.capWid;
		}
		up(&VT_Semaphore);
		return TRUE;
	} else {
		pOutputInfo->maxRegion.x = 0;
		pOutputInfo->maxRegion.y =0;
		pOutputInfo->maxRegion.w = 0;
		pOutputInfo->maxRegion.h = 0;

		pOutputInfo->activeRegion.x = 0;
		pOutputInfo->activeRegion.y =0;
		pOutputInfo->activeRegion.w =0;
		pOutputInfo->activeRegion.h = 0;

		pOutputInfo->stride = 0;

		rtd_printk(KERN_NOTICE, TAG_NAME, "VFOD is not inited or vfod dump location not matches you want;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	}
}

unsigned char HAL_VT_SetVideoFrameOutputDeviceOutputRegion(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_DUMP_LOCATION_TYPE_T dumpLocation, KADP_VT_RECT_T *pOutputRegion)
{
	if (videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	if(get_vt_function() == TRUE) {
#if 0		
		if((dumpLocation==VTDumpLocation)&&(pOutputRegion->w==curCapInfo.capWid)&&(pOutputRegion->h==curCapInfo.capLen)) {
			rtd_printk(KERN_DEBUG, TAG_NAME, "all SetVideoFrameOutputDeviceOutputRegion is the same with now\n");
		} else
#endif		
		if((pOutputRegion->x!=0)||(pOutputRegion->y!=0)) {
			rtd_printk(KERN_NOTICE, TAG_NAME, "[warning]only support output region x y is 0\n");
			up(&VT_Semaphore);
			return FALSE;
		} else if((pOutputRegion->w>(Get_DISP_DEN_END_HPOS() - Get_DISP_DEN_STA_HPOS()))||(pOutputRegion->w<60)||(pOutputRegion->h>(Get_DISP_DEN_END_VPOS() - Get_DISP_DEN_STA_VPOS()))||(pOutputRegion->h<34)) {
			rtd_printk(KERN_NOTICE, TAG_NAME, "[warning]OutputRegion over limitation!!!!\n");
			up(&VT_Semaphore);
			return FALSE;
		} else {
			curCapInfo.enable = 0; //close vfod first then rerun
			drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
			curCapInfo.enable = 1;

			if(dumpLocation==KADP_VT_DISPLAY_OUTPUT)
				curCapInfo.capSrc =  VT_CAP_SRC_VIDEO_PQ;
			else if(dumpLocation==KADP_VT_SCALER_OUTPUT)
				curCapInfo.capSrc =  VT_CAP_SRC_VIDEO_NOPQ;
			else if(dumpLocation==KADP_VT_OSDVIDEO_OUTPUT)
				curCapInfo.capSrc =  VT_CAP_SRC_VIDEO_OSD;
			
			curCapInfo.capWid = pOutputRegion->w;
			curCapInfo.capLen = pOutputRegion->h;
			drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
			
			if(dumpLocation==KADP_VT_SCALER_OUTPUT)
				VFODState.bAppliedPQ = FALSE;
			else
				VFODState.bAppliedPQ = TRUE;
			VTDumpLocation = dumpLocation;

			if(VFODState.bFreezed == TRUE)
			{
				set_vfod_freezed(TRUE);//revert freezed status
			}
		}
		up(&VT_Semaphore);
		return TRUE;
	} else {
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT is not Inited So return False;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return FALSE;
	}
}

unsigned char HAL_VT_WaitVsync(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	if(get_vt_function() == TRUE) {
		unsigned int sleeptime;
		
		unsigned int vtframerate;
		struct timespec timeout_s;
		unsigned int waitvsyncframerate;
		vtframerate = Get_VFOD_FrameRate();/*Get_VFOD_FrameRate not return 0*/


		if(VFODState.framerateDivide !=0)
			waitvsyncframerate = vtframerate/VFODState.framerateDivide;
		else
			waitvsyncframerate = vtframerate;

		sleeptime = 1000/waitvsyncframerate;
	
		timeout_s = ns_to_timespec(sleeptime * 1000 * 1000);

		hrtimer_nanosleep(&timeout_s, NULL, HRTIMER_MODE_REL, CLOCK_MONOTONIC);
	}
	return TRUE;
}

unsigned char HAL_VT_GetInputVideoInfo(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_INPUT_VIDEO_INFO_T *pInputVideoInfo)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	if(get_vt_function() == TRUE) {
		pInputVideoInfo->region.x = 0;
		pInputVideoInfo->region.y = 0;
		pInputVideoInfo->region.w =Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
		pInputVideoInfo->region.h = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE);
		if (Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE) == TRUE)
		{
			pInputVideoInfo->type = KADP_VT_VIDEO_PROGRESSIVE;
			pInputVideoInfo->region.h = pInputVideoInfo->region.h *2;
		} else {
			pInputVideoInfo->type = KADP_VT_VIDEO_PROGRESSIVE;
		}
		pInputVideoInfo->bIs3DVideo = FALSE;
		up(&VT_Semaphore);
		return TRUE;
	} else {
		pInputVideoInfo->region.x = 0;
		pInputVideoInfo->region.y =0;
		pInputVideoInfo->region.w =0;
		pInputVideoInfo->region.h = 0;
		pInputVideoInfo->type = KADP_VT_VIDEO_PROGRESSIVE;
		pInputVideoInfo->bIs3DVideo = FALSE;
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT is not Inited So return InputVideoregion 0;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	}
}

unsigned char HAL_VT_GetOutputVideoInfo(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, KADP_VT_OUTPUT_VIDEO_INFO_T *pOutputVideoInfo)
{
	ppoverlay_main_active_h_start_end_RBUS main_active_h_start_end_reg;
	ppoverlay_main_active_v_start_end_RBUS main_active_v_start_end_reg;
	unsigned int x,y,w,h;
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	main_active_h_start_end_reg.regValue = rtd_inl(PPOVERLAY_MAIN_Active_H_Start_End_reg);
	main_active_v_start_end_reg.regValue = rtd_inl(PPOVERLAY_MAIN_Active_V_Start_End_reg);
	x = main_active_h_start_end_reg.mh_act_sta;
	y =main_active_v_start_end_reg.mv_act_sta;
	w =main_active_h_start_end_reg.mh_act_end - main_active_h_start_end_reg.mh_act_sta;
	h = main_active_v_start_end_reg.mv_act_end - main_active_v_start_end_reg.mv_act_sta;

	if(get_vt_function() == TRUE) {
		if((KADP_VT_DISPLAY_OUTPUT==VTDumpLocation)||(KADP_VT_OSDVIDEO_OUTPUT==VTDumpLocation)) {
			pOutputVideoInfo->maxRegion.x = Get_DISP_ACT_STA_HPOS();
			pOutputVideoInfo->maxRegion.y = Get_DISP_ACT_STA_VPOS();
			pOutputVideoInfo->maxRegion.w = Get_DISP_ACT_END_HPOS() - Get_DISP_ACT_STA_HPOS();
			pOutputVideoInfo->maxRegion.h = Get_DISP_ACT_END_VPOS() - Get_DISP_ACT_STA_VPOS();

			pOutputVideoInfo->activeRegion.x = x;
			pOutputVideoInfo->activeRegion.y = y;
			pOutputVideoInfo->activeRegion.w = w;
			pOutputVideoInfo->activeRegion.h = h;
			pOutputVideoInfo->type = KADP_VT_VIDEO_PROGRESSIVE;
		} else if(KADP_VT_SCALER_OUTPUT==VTDumpLocation) {
			pOutputVideoInfo->maxRegion.x = x;
			pOutputVideoInfo->maxRegion.y = y;
			pOutputVideoInfo->maxRegion.w = w;
			pOutputVideoInfo->maxRegion.h = h;

			pOutputVideoInfo->activeRegion.x = x;
			pOutputVideoInfo->activeRegion.y = y;
			pOutputVideoInfo->activeRegion.w = w;
			pOutputVideoInfo->activeRegion.h = h;

			pOutputVideoInfo->type = KADP_VT_VIDEO_PROGRESSIVE;
		}
		up(&VT_Semaphore);
		return TRUE;
	} else {
		pOutputVideoInfo->maxRegion.x = 0;
		pOutputVideoInfo->maxRegion.y =0;
		pOutputVideoInfo->maxRegion.w = 0;
		pOutputVideoInfo->maxRegion.h = 0;

		pOutputVideoInfo->activeRegion.x = 0;
		pOutputVideoInfo->activeRegion.y =0;
		pOutputVideoInfo->activeRegion.w = 0;
		pOutputVideoInfo->activeRegion.h = 0;

		pOutputVideoInfo->type = KADP_VT_VIDEO_PROGRESSIVE;
		up(&VT_Semaphore);
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT is not Inited So return OutputVideoregion 0;%s=%d\n", __FUNCTION__, __LINE__);
		return TRUE;
	}
}

unsigned char HAL_VT_GetVideoMuteStatus(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char *pbOnOff)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VT_Semaphore);
	if(get_vt_function() == TRUE) {
		*pbOnOff = get_vsc_mutestatus();
		up(&VT_Semaphore);
		return TRUE;
	} else {
		*pbOnOff = TRUE;
		rtd_printk(KERN_NOTICE, TAG_NAME, "VT is not Inited So return MuteStatus true;%s=%d\n", __FUNCTION__, __LINE__);
		up(&VT_Semaphore);
		return TRUE;
	}
}
static unsigned char VdecSecureStatus = FALSE;

void set_vdec_securestatus(unsigned char value)
{
	VdecSecureStatus = value;
}

unsigned char get_vdec_securestatus(void)
{
	return VdecSecureStatus;
}

unsigned char HAL_VT_GetVideoFrameBufferSecureVideoState(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char *pIsSecureVideo)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	if (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC) {
		* pIsSecureVideo = get_vdec_securestatus();
	} else {
		* pIsSecureVideo = FALSE;
	}
	return TRUE;
}


static unsigned char VTBlockStatus = FALSE;
unsigned char HAL_VT_GetVideoFrameOutputDeviceBlockState(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char *pbBlockState)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VTBlock_Semaphore);
	*pbBlockState = VTBlockStatus;
	up(&VTBlock_Semaphore);
	return TRUE;
}

unsigned char HAL_VT_SetVideoFrameOutputDeviceBlockState(KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char bBlockState)
{
	if(videoWindowID != KADP_VT_VIDEO_WINDOW_0) {
		rtd_printk(KERN_NOTICE, TAG_NAME, "videoWindowID id is not ok;%s=%d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	down(&VTBlock_Semaphore);
	VTBlockStatus = bBlockState;
	up(&VTBlock_Semaphore);
	return TRUE;
}

unsigned char HAL_VT_set_Pixel_Format(VT_CAP_FMT value)
{
	down(&VT_Semaphore);
	if((value >= VT_CAP_RGB888)&&(value <= VT_CAP_NV16)) {
		if (value != get_VT_Pixel_Format()) {
			set_VT_Pixel_Format(value);
			/*close vt, and release last pixel format buffer start*/
			curCapInfo.enable = 0; //iMode;
			drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
			Capture_BufferMemDeInit_VT(get_vt_VtBufferNum());
			/*close vt, and release last pixel format buffer end*/

			/*open vt, and allocate new pixel format buffer start*/
			curCapInfo.enable = 1; //iMode;		
			if (Capture_BufferMemInit_VT(get_vt_VtBufferNum()) == FALSE) {
				rtd_printk(KERN_NOTICE, TAG_NAME, "VT init allocate memory fail when set_VT_Pixel_Format;%s=%d \n", __FUNCTION__, __LINE__);
				up(&VT_Semaphore);
				return FALSE;
			}
			drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);	
			/*open vt, and allocate new pixel format buffer end*/
		}
		up(&VT_Semaphore);
		return TRUE;
	} else {
		up(&VT_Semaphore);
		return FALSE;
	}
}

/************************************start of DC2H capture VDC(ATV or CVBS) data function********************************/
void rtk_dc2h_capturevdc_config(unsigned char connect, VIDEO_RECT_T inregion, VIDEO_RECT_T outregion)
{
	if (connect == TRUE) {
		curCapInfo.enable = 1; //iMode;
		curCapInfo.capSrc = 2;  //0:scaler output 1:display output 2:VD output
		curCapInfo.capMode = VT_CAP_MODE_SEQ;
		curCapInfo.capWid = outregion.w; //iWid;
		curCapInfo.capLen = outregion.h;

		DC2H_InputWidthSta = inregion.x;
		DC2H_InputLengthSta = inregion.y;
		DC2H_InputWidth = inregion.w;
		DC2H_InputLength = inregion.h;		

		if (Capture_BufferMemInit_VT(3) == FALSE) {
			rtd_printk(KERN_NOTICE, TAG_NAME, "VT init allocate memory fail;%s=%d \n", __FUNCTION__, __LINE__);
			up(&VT_Semaphore);
			return ;
		}
		set_vt_VtBufferNum(3);
		set_vt_VtSwBufferMode(FALSE);
		set_vt_VtCaptureVDC(TRUE);
		//freezebufferaddr = CaptureCtrl_VT.cap_buffer[2].phyaddr;
		drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
	} else {
		curCapInfo.enable = 0; //iMode;
		drvif_DC2H_dispD_CaptureConfig(curCapInfo, TRUE);
		Capture_BufferMemDeInit_VT(get_vt_VtBufferNum());
		set_vt_VtBufferNum(0);
		set_vt_VtSwBufferMode(FALSE);
		set_vt_VtCaptureVDC(FALSE);
	}
}
/************************************end of DC2H capture VDC(ATV or CVBS) data function********************************/


/************************************start of VT buffer show by sub display function********************************/
#define _BURSTLENGTH2 	(0x78) // 0x78 (120) for sub-channel
#define _FIFOLENGTH2 	(0x80) //sub path FIFO
void memory_set_sub_displaywindow_DispVT(VIDEO_RECT_T s_dispwin)
{
	SCALER_DISP_CHANNEL display = SLR_SUB_DISPLAY;
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int burstLen = _BURSTLENGTH2;
	unsigned int MemShiftAddr = 0;
	unsigned short droppixel = 0;
	unsigned int subctrltemp = 0;
	mdomain_disp_ddr_subprevstart_RBUS mdomain_disp_ddr_subprevstart_Reg;
	mdomain_disp_display_byte_channel_swap_RBUS display_sub_byte_channel_swap_reg;
	
	mdomain_disp_ddr_subprevstart_Reg.regValue = rtd_inl(MDOMAIN_DISP_DDR_SubPreVStart_reg);
	if(s_dispwin.y <= 100) {
		mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = 7;
	} else {
		mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = (s_dispwin.y-4);
	}
	rtd_outl(MDOMAIN_DISP_DDR_SubPreVStart_reg, mdomain_disp_ddr_subprevstart_Reg.regValue);


	MemGetBlockShiftAddr(display, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
	TotalSize = memory_get_disp_line_size1(display, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xffc00000, (( ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x3FFF) << 8) | ((fifoLen - (burstLen>>1))>>1)));


	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0x00000000, (Quotient << 16) | (burstLen << 8) | Remainder);


	TotalSize = memory_get_capture_size(display, MEMCAPTYPE_LINE);
	/*TotalSize = Quotient * burstLen + Remainder; 	// count one line, 64bits unit
	TotalSize = drvif_memory_get_data_align(TotalSize, 4);	// times of 4*/

	rtd_outl(MDOMAIN_DISP_DDR_SubLineStep_reg,  (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule

	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));

	rtd_outl(MDOMAIN_DISP_DDR_SubAddr_reg, (CaptureCtrl_VT.cap_buffer[0].phyaddr + MemShiftAddr) & 0x7ffffff0);
	rtd_outl(MDOMAIN_DISP_DDR_Sub2ndAddr_reg, (CaptureCtrl_VT.cap_buffer[1].phyaddr + MemShiftAddr) & 0x7ffffff0);
	rtd_outl(MDOMAIN_DISP_DDR_Sub3rdAddr_reg, (CaptureCtrl_VT.cap_buffer[2].phyaddr + MemShiftAddr) & 0x7ffffff0);

	rtd_outl(MDOMAIN_DISP_DDR_SubAddrDropBits_reg,droppixel);

	subctrltemp = _BIT6;
	subctrltemp |=_BIT7;//set Mdomain display triple buffer
	//subctrltemp |= (_BIT1);
	//disp ctrl default setting
	subctrltemp |= (_BIT25 | _BIT28);
	subctrltemp |= Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP) ? 0 : _BIT17;
	//subctrltemp |= (_BIT19);/*for VT data is RGB*/
	rtd_outl(MDOMAIN_DISP_DDR_SubCtrl_reg, subctrltemp);

	display_sub_byte_channel_swap_reg.regValue = rtd_inl(MDOMAIN_DISP_Display_byte_channel_swap_reg);
	display_sub_byte_channel_swap_reg.sub_1byte_swap = 1;
	display_sub_byte_channel_swap_reg.sub_2byte_swap = 1;
	display_sub_byte_channel_swap_reg.sub_4byte_swap = 1;
	display_sub_byte_channel_swap_reg.sub_8byte_swap = 0;
	display_sub_byte_channel_swap_reg.sub_channel_swap = 4;
	rtd_outl(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_sub_byte_channel_swap_reg.regValue);
	rtd_outl(MDOMAIN_DISP_Disp_sub_enable_reg, _BIT0);
}

extern void magnifier_color_ultrazoom_config_scaling_up(unsigned char display);
extern void Scaler_disp_setting(unsigned char display);
unsigned char Scaler_SubMDispWindow_VFB(bool enable)
{
	rtd_printk(KERN_DEBUG, TAG_NAME,"Scaler_SubMDispWindow_VFB curCapInfo.enable==%d\n",curCapInfo.enable);
	if (curCapInfo.enable){
		SCALER_DISP_CHANNEL display = SLR_SUB_DISPLAY;
		mdomain_disp_ddr_mainsubctrl_RBUS mdomain_disp_ddr_mainsubctrl_Reg;
		ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_Reg;
		scaleup_ds_uzu_db_ctrl_RBUS scaleup_ds_uzu_db_ctrl_Reg;
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT17);
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = rtd_inl(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_enable = 0;
		rtd_outl(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Enable dtg double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = rtd_inl(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 0;
		rtd_outl(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_SetBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
		scaleup_ds_uzu_db_ctrl_Reg.regValue = rtd_inl(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_ds_uzu_db_ctrl_Reg.db_en = 0;
		rtd_outl(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);	
		if(enable == TRUE) {
			unsigned short VTCapLen = curCapInfo.capLen;
			unsigned short VTCapWid = curCapInfo.capWid;
			VIDEO_RECT_T outputwin;
			yuv2rgb_d_yuv2rgb_control_RBUS yuv2rgb_d_yuv2rgb_control_Reg;
			
			outputwin.x = 0;
			outputwin.y = 0;
			outputwin.w = VTCapWid;
			outputwin.h = VTCapLen;
			

			
			Scaler_DispSetStatus(display, SLR_DISP_422CAP, FALSE);/*VT buffer is RGB888,so go 444*/
			Scaler_DispSetStatus(display, SLR_DISP_10BIT, FALSE);/*VT buffer is RGB888,so go 8bit*/
			Scaler_DispSetStatus(display, SLR_DISP_INTERLACE, FALSE);
			
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_FRAMESYNC, FALSE);
			
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_CAP_LEN, VTCapLen);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_CAP_WID, VTCapWid);

			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, VTCapLen);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, 0);
			
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, VTCapWid);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, 0);

			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_WID, VTCapWid);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_LEN, VTCapLen);

			if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) <= Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID)){
				Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, TRUE);
			}else{
				Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, FALSE);
			}

			if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) <= Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN))
				Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, TRUE);
			else
				Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, FALSE);

			memory_set_sub_displaywindow_DispVT(outputwin);
			
			/*sub uzu*/
			magnifier_color_ultrazoom_config_scaling_up(display);
#if 0
			/*sub yuv2rgb*/
			yuv2rgb_d_yuv2rgb_control_Reg.regValue = rtd_inl(YUV2RGB_D_YUV2RGB_Control_reg);
			if(curCapInfo.capSrc == 1) {//memc
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_overlay = 1;
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_sub_en = 0;
			} else{//uzu
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_overlay = 0;
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_sub_en = 1;
			}
			rtd_outl(YUV2RGB_D_YUV2RGB_Control_reg, yuv2rgb_d_yuv2rgb_control_Reg.regValue);
#endif			
			PipmpSetSubDisplayWindow(
				outputwin.x, outputwin.x + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID) - 1,
				outputwin.y, outputwin.y + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN) - 1,
				0);

			PipmpSetSubActiveWindow(
				0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID)  - 1,
				0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN) - 1);

			Scaler_disp_setting(display);

			set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_VSC, FALSE);

			down(get_forcebg_semaphore());
			scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
			up(get_forcebg_semaphore());			
		} else {
			rtd_outl(MDOMAIN_DISP_Disp_sub_enable_reg, 0x00000000);

			down(get_forcebg_semaphore());
			drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
			up(get_forcebg_semaphore());
		}
	} else {
		return FALSE;
	}
	return TRUE;
}

void memory_set_displaysubwindow_DispVT(VIDEO_RECT_T s_dispwin, unsigned long phyaddr)
{
	SCALER_DISP_CHANNEL display = SLR_SUB_DISPLAY;
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int burstLen = _BURSTLENGTH2;
	unsigned int MemShiftAddr = 0;
	unsigned short droppixel = 0;
	unsigned int subctrltemp = 0;
	mdomain_disp_ddr_subprevstart_RBUS mdomain_disp_ddr_subprevstart_Reg;
	mdomain_disp_display_byte_channel_swap_RBUS display_sub_byte_channel_swap_reg;
	
	mdomain_disp_ddr_subprevstart_Reg.regValue = rtd_inl(MDOMAIN_DISP_DDR_SubPreVStart_reg);
	if(s_dispwin.y <= 100) {
		mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = 7;
	} else {
		mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = (s_dispwin.y-4);
	}
	rtd_outl(MDOMAIN_DISP_DDR_SubPreVStart_reg, mdomain_disp_ddr_subprevstart_Reg.regValue);


	MemGetBlockShiftAddr(display, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
	TotalSize = memory_get_disp_line_size1(display, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xffc00000, (( ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x3FFF) << 8) | ((fifoLen - (burstLen>>1))>>1)));


	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0x00000000, (Quotient << 16) | (burstLen << 8) | Remainder);


	TotalSize = memory_get_capture_size(display, MEMCAPTYPE_LINE);
	/*TotalSize = Quotient * burstLen + Remainder; 	// count one line, 64bits unit
	TotalSize = drvif_memory_get_data_align(TotalSize, 4);	// times of 4*/

	rtd_outl(MDOMAIN_DISP_DDR_SubLineStep_reg,  (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule

	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));

#if 1
	rtd_outl(MDOMAIN_DISP_DDR_SubAddr_reg, (phyaddr + MemShiftAddr) & 0x7ffffff0);
#else
	rtd_outl(MDOMAIN_DISP_DDR_SubAddr_reg, (CaptureCtrl_VT.cap_buffer[0].phyaddr + MemShiftAddr) & 0x7ffffff0);
	rtd_outl(MDOMAIN_DISP_DDR_Sub2ndAddr_reg, (CaptureCtrl_VT.cap_buffer[1].phyaddr + MemShiftAddr) & 0x7ffffff0);
	rtd_outl(MDOMAIN_DISP_DDR_Sub3rdAddr_reg, (CaptureCtrl_VT.cap_buffer[2].phyaddr + MemShiftAddr) & 0x7ffffff0);
#endif

	rtd_outl(MDOMAIN_DISP_DDR_SubAddrDropBits_reg,droppixel);

//	subctrltemp = _BIT6;
//	subctrltemp |=_BIT7;//set Mdomain display triple buffer
	//subctrltemp |= (_BIT1);
	//disp ctrl default setting
	subctrltemp |= (_BIT25 | _BIT28);
	subctrltemp |= Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP) ? 0 : _BIT17;
	//subctrltemp |= (_BIT19);/*for VT data is RGB*/
	rtd_outl(MDOMAIN_DISP_DDR_SubCtrl_reg, subctrltemp);

	display_sub_byte_channel_swap_reg.regValue = rtd_inl(MDOMAIN_DISP_Display_byte_channel_swap_reg);
	display_sub_byte_channel_swap_reg.sub_1byte_swap = 1;
	display_sub_byte_channel_swap_reg.sub_2byte_swap = 1;
	display_sub_byte_channel_swap_reg.sub_4byte_swap = 1;
	display_sub_byte_channel_swap_reg.sub_8byte_swap = 0;
	display_sub_byte_channel_swap_reg.sub_channel_swap = 4;
	rtd_outl(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_sub_byte_channel_swap_reg.regValue);
	rtd_outl(MDOMAIN_DISP_Disp_sub_enable_reg, _BIT0);
}

unsigned char Scaler_Rowdata_SubMDispWindow(KADP_VT_ROWDATA_SHOW_ONSUBDISP_T *VT_ROWDATA_SHOW_ONSUBDISP)
{
		ppoverlay_memc_mux_ctrl_RBUS memc_mux_ctrl_reg;
		SCALER_DISP_CHANNEL display = SLR_SUB_DISPLAY;
		mdomain_disp_ddr_mainsubctrl_RBUS mdomain_disp_ddr_mainsubctrl_Reg;
		ppoverlay_double_buffer_ctrl_RBUS ppoverlay_double_buffer_ctrl_Reg;
		scaleup_ds_uzu_db_ctrl_RBUS scaleup_ds_uzu_db_ctrl_Reg;

		memc_mux_ctrl_reg.regValue = rtd_inl(PPOVERLAY_MEMC_MUX_CTRL_reg);
		memc_mux_ctrl_reg.memc_out_bg_en = 0;
		rtd_outl(PPOVERLAY_MEMC_MUX_CTRL_reg, memc_mux_ctrl_reg.regValue);
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT17);
		mdomain_disp_ddr_mainsubctrl_Reg.regValue = rtd_inl(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		mdomain_disp_ddr_mainsubctrl_Reg.disp2_double_enable = 0;
		rtd_outl(MDOMAIN_DISP_DDR_MainSubCtrl_reg, mdomain_disp_ddr_mainsubctrl_Reg.regValue);

		//IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT6);//Enable dtg double buffer register
		ppoverlay_double_buffer_ctrl_Reg.regValue = rtd_inl(PPOVERLAY_Double_Buffer_CTRL_reg);
		ppoverlay_double_buffer_ctrl_Reg.dsubreg_dbuf_en = 0;
		rtd_outl(PPOVERLAY_Double_Buffer_CTRL_reg, ppoverlay_double_buffer_ctrl_Reg.regValue);

		//IoReg_SetBits(SCALEUP_DS_UZU_DB_CTRL_reg, _BIT2);//Enable uzu double buffer register
		scaleup_ds_uzu_db_ctrl_Reg.regValue = rtd_inl(SCALEUP_DS_UZU_DB_CTRL_reg);
		scaleup_ds_uzu_db_ctrl_Reg.db_en = 0;
		rtd_outl(SCALEUP_DS_UZU_DB_CTRL_reg, scaleup_ds_uzu_db_ctrl_Reg.regValue);	
		if(VT_ROWDATA_SHOW_ONSUBDISP->enable == TRUE) {
			unsigned short VTCapLen = VT_ROWDATA_SHOW_ONSUBDISP->height;
			unsigned short VTCapWid = VT_ROWDATA_SHOW_ONSUBDISP->width;
			VIDEO_RECT_T outputwin;
			yuv2rgb_d_yuv2rgb_control_RBUS yuv2rgb_d_yuv2rgb_control_Reg;

			outputwin.x = VT_ROWDATA_SHOW_ONSUBDISP->OutputRegion.x;
			outputwin.y = VT_ROWDATA_SHOW_ONSUBDISP->OutputRegion.y;
			outputwin.w = VT_ROWDATA_SHOW_ONSUBDISP->OutputRegion.w;
			outputwin.h = VT_ROWDATA_SHOW_ONSUBDISP->OutputRegion.h;

			Scaler_DispSetStatus(display, SLR_DISP_422CAP, FALSE);/*VT buffer is RGB888,so go 444*/
			Scaler_DispSetStatus(display, SLR_DISP_10BIT, FALSE);/*VT buffer is RGB888,so go 8bit*/
			Scaler_DispSetStatus(display, SLR_DISP_INTERLACE, FALSE);
			
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_FRAMESYNC, FALSE);
			
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_CAP_LEN, VTCapLen);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_CAP_WID, VTCapWid);

			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN, VTCapLen);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA, 0);
			
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID, VTCapWid);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA, 0);

			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_WID, outputwin.w);
			Scaler_DispSetInputInfoByDisp(display, SLR_INPUT_DISP_LEN, outputwin.h);

			if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) <= Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID)){
				Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, TRUE);
			}else{
				Scaler_DispSetScaleStatus(display, SLR_SCALE_H_UP, FALSE);
			}

			if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) <= Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN))
				Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, TRUE);
			else
				Scaler_DispSetScaleStatus(display, SLR_SCALE_V_UP, FALSE);

			memory_set_displaysubwindow_DispVT(outputwin, VT_ROWDATA_SHOW_ONSUBDISP->phyaddr);
			
			/*sub uzu*/
			magnifier_color_ultrazoom_config_scaling_up(display);
#if 0
			/*sub yuv2rgb*/
			yuv2rgb_d_yuv2rgb_control_Reg.regValue = rtd_inl(YUV2RGB_D_YUV2RGB_Control_reg);
			if(curCapInfo.capSrc == 1) {//memc
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_overlay = 1;
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_sub_en = 0;
			} else{//uzu
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_overlay = 0;
				yuv2rgb_d_yuv2rgb_control_Reg.yuv2rgb_sub_en = 1;
			}
			rtd_outl(YUV2RGB_D_YUV2RGB_Control_reg, yuv2rgb_d_yuv2rgb_control_Reg.regValue);
#endif			
			PipmpSetSubDisplayWindow(
				outputwin.x, outputwin.x + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_WID) - 1,
				outputwin.y, outputwin.y + Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_DISP_LEN) - 1,
				0);

			PipmpSetSubActiveWindow(
				0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_WID)  - 1,
				0, Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_DISP_LEN) - 1);

			Scaler_disp_setting(display);

			set_display_forcebg_mask(SLR_SUB_DISPLAY, SLR_FORCE_BG_TYPE_VSC, FALSE);

			down(get_forcebg_semaphore());
			scalerdisplay_force_bg_enable(SLR_SUB_DISPLAY, FALSE);
			up(get_forcebg_semaphore());		
		} else {
			rtd_outl(MDOMAIN_DISP_Disp_sub_enable_reg, 0x00000000);

			down(get_forcebg_semaphore());
			drvif_scalerdisplay_enable_display(SLR_SUB_DISPLAY, _DISABLE);
			up(get_forcebg_semaphore());
		}
	return TRUE;
}
/************************************end of VT buffer show by sub display function********************************/

unsigned char ColorBlock_Compare(unsigned int bufferaddr, unsigned int R, unsigned int G, unsigned int B, VIDEO_RECT_T block)
{
	
	unsigned int sumR, sumG, sumB;
	unsigned int i,j;
	unsigned char* bufferpoint;
	
	if((block.w==0)&&(block.h==0))
		return TRUE;
	
	sumR = 0;
	sumG = 0;
	sumB = 0;
	bufferpoint = (unsigned char*)bufferaddr;
	
	for(i=0;i<block.h;i++)
	{
		for(j=0;j<block.w;j++)
		{
			sumR += bufferpoint[1920*3*(i+block.y)+(block.x+j)*3];
			sumG += bufferpoint[1920*3*(i+block.y)+(block.x+j)*3+1];
			sumB += bufferpoint[1920*3*(i+block.y)+(block.x+j)*3+2];
		}
	}
	sumR = sumR/(block.w*block.h);
	sumG = sumG/(block.w*block.h);
	sumB = sumB/(block.w*block.h);
	rtd_printk(KERN_EMERG, TAG_NAME, "@@@@@@@");
	rtd_printk(KERN_EMERG, TAG_NAME, "R=%d;sumR=%d\n",R,sumR);
	rtd_printk(KERN_EMERG, TAG_NAME, "G=%d;sumG=%d\n",G,sumG);
	rtd_printk(KERN_EMERG, TAG_NAME, "B=%d;sumB=%d\n",B,sumB);
	
	if((abs(R-sumR)<80)&&(abs(G-sumG)<80)&&(abs(B-sumB)<80))
		return TRUE;
	else{
		if(abs(R-sumR)>=80)
			rtd_printk(KERN_EMERG, TAG_NAME, "!!!!!!@@@R_Diff_value =%ld\n",abs(R-sumR));
		if(abs(G-sumR)>=80)
			rtd_printk(KERN_EMERG, TAG_NAME, "!!!!!!@@@G_Diff_value =%ld\n",abs(G-sumR));
		if(abs(B-sumR)>=80)
			rtd_printk(KERN_EMERG, TAG_NAME, "!!!!!!@@@B_Diff_value =%ld\n",abs(B-sumR));
		return FALSE;
	}
}

extern unsigned char rtk_hal_vsc_GetInputRegion(VIDEO_WID_T wid, VIDEO_RECT_T * pinregion);
unsigned char Check_colorbar_window_cal(VIDEO_RECT_T *GrayBlock, VIDEO_RECT_T *YellowBlock, VIDEO_RECT_T *LittleBlueBlock, VIDEO_RECT_T *GreenBlock, VIDEO_RECT_T *PinkBlock, VIDEO_RECT_T *RedBlock, VIDEO_RECT_T *BlueBlock, VIDEO_RECT_T *BlackBlock)
{
	unsigned int SourceWidth;
	unsigned int OverscanWidth;
	VIDEO_RECT_T inregion;
	unsigned int input_w;
	unsigned int nooverscancolorbarWidth;
	unsigned int overscancolorbarWidth;
	unsigned int colorbarnum;
	unsigned int sidecolorwidth;
	VSC_INPUT_TYPE_T srctype;
	srctype = Get_DisplayMode_Src(SLR_MAIN_DISPLAY);

	SourceWidth = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPH_ACT_WID_PRE);
	rtk_hal_vsc_GetInputRegion(VIDEO_WID_0, &inregion);
	input_w = Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHWID);
	if(input_w > 3840){
		inregion.x = 3840*inregion.x/input_w;
		inregion.w = 3840*inregion.w/input_w;
	}

	if ((srctype == VSC_INPUTSRC_AVD))
	{
		OverscanWidth = Scaler_CalAVD27MWidth(SLR_MAIN_DISPLAY,inregion.w);
	} else {
		OverscanWidth = inregion.w;
	}

	nooverscancolorbarWidth = SourceWidth/8;
	overscancolorbarWidth = 1920*nooverscancolorbarWidth/OverscanWidth;
	sidecolorwidth = (960%overscancolorbarWidth)?(960%overscancolorbarWidth):overscancolorbarWidth;
	colorbarnum =( 8 - 2*((SourceWidth - OverscanWidth) / (nooverscancolorbarWidth*2)));
	
	rtd_printk(KERN_EMERG, TAG_NAME, "SourceWidth=%d;OverscanWidth=%d\n",SourceWidth,OverscanWidth);
	rtd_printk(KERN_EMERG, TAG_NAME, "overscancolorbarWidth=%d;sidecolorwidth=%d\n",overscancolorbarWidth,sidecolorwidth);
	rtd_printk(KERN_EMERG, TAG_NAME, "colorbarnum=%d\n",colorbarnum);

	if(8 == colorbarnum ){
		/*line one*/
		GreenBlock[0].x = 960 - overscancolorbarWidth/2 -5;
		GreenBlock[0].y = 175;
		GreenBlock[0].w = 10;
		GreenBlock[0].h = 10;

		PinkBlock[0].x = 960 + overscancolorbarWidth/2 -5;
		PinkBlock[0].y = 175;
		PinkBlock[0].w = 10;
		PinkBlock[0].h = 10;		

		LittleBlueBlock[0].x = 960 - 3*overscancolorbarWidth/2 -5;
		LittleBlueBlock[0].y = 175;
		LittleBlueBlock[0].w = 10;
		LittleBlueBlock[0].h = 10;

		RedBlock[0].x = 960 + 3*overscancolorbarWidth/2 -5;
		RedBlock[0].y = 175;
		RedBlock[0].w = 10;
		RedBlock[0].h = 10;

		YellowBlock[0].x = 960 - 5*overscancolorbarWidth/2 -5;
		YellowBlock[0].y = 175;
		YellowBlock[0].w = 10;
		YellowBlock[0].h = 10;

		BlueBlock[0].x = 960 + 5*overscancolorbarWidth/2 -5;
		BlueBlock[0].y = 175;
		BlueBlock[0].w = 10;
		BlueBlock[0].h = 10;

		if(sidecolorwidth >= 30){
			GrayBlock[0].x = 960 - 3*overscancolorbarWidth - sidecolorwidth/2 -5;
			GrayBlock[0].y = 175;
			GrayBlock[0].w = 10;
			GrayBlock[0].h = 10;
			
			BlackBlock[0].x = 960 + 3*overscancolorbarWidth + sidecolorwidth/2 -5;
			BlackBlock[0].y = 175;
			BlackBlock[0].w = 10;
			BlackBlock[0].h = 10;
		} else {
			GrayBlock[0].x = 0;
			GrayBlock[0].y = 0;
			GrayBlock[0].w = 0;
			GrayBlock[0].h = 0;
			
			BlackBlock[0].x = 0;
			BlackBlock[0].y = 0;
			BlackBlock[0].w = 0;
			BlackBlock[0].h = 0;
		}

		/*line two*/
		GreenBlock[1].x = 960 - overscancolorbarWidth/2 -5;
		GreenBlock[1].y = 535;
		GreenBlock[1].w = 10;
		GreenBlock[1].h = 10;

		PinkBlock[1].x = 960 + overscancolorbarWidth/2 -5;
		PinkBlock[1].y = 535;
		PinkBlock[1].w = 10;
		PinkBlock[1].h = 10;		

		LittleBlueBlock[1].x = 960 - 3*overscancolorbarWidth/2 -5;
		LittleBlueBlock[1].y = 535;
		LittleBlueBlock[1].w = 10;
		LittleBlueBlock[1].h = 10;

		RedBlock[1].x = 960 + 3*overscancolorbarWidth/2 -5;
		RedBlock[1].y = 535;
		RedBlock[1].w = 10;
		RedBlock[1].h = 10;

		YellowBlock[1].x = 960 - 5*overscancolorbarWidth/2 -5;
		YellowBlock[1].y = 535;
		YellowBlock[1].w = 10;
		YellowBlock[1].h = 10;

		BlueBlock[1].x = 960 + 5*overscancolorbarWidth/2 -5;
		BlueBlock[1].y = 535;
		BlueBlock[1].w = 10;
		BlueBlock[1].h = 10;

		if(sidecolorwidth >= 30){
			GrayBlock[1].x = 960 - 3*overscancolorbarWidth - sidecolorwidth/2 -5;
			GrayBlock[1].y = 535;
			GrayBlock[1].w = 10;
			GrayBlock[1].h = 10;
			
			BlackBlock[1].x = 960 + 3*overscancolorbarWidth + sidecolorwidth/2 -5;
			BlackBlock[1].y = 535;
			BlackBlock[1].w = 10;
			BlackBlock[1].h = 10;
		} else {
			GrayBlock[1].x = 0;
			GrayBlock[1].y = 0;
			GrayBlock[1].w = 0;
			GrayBlock[1].h = 0;
			
			BlackBlock[1].x = 0;
			BlackBlock[1].y = 0;
			BlackBlock[1].w = 0;
			BlackBlock[1].h = 0;
		}

		/*line three*/
		GreenBlock[2].x = 960 - overscancolorbarWidth/2 -5;
		GreenBlock[2].y = 895;
		GreenBlock[2].w = 10;
		GreenBlock[2].h = 10;

		PinkBlock[2].x = 960 + overscancolorbarWidth/2 -5;
		PinkBlock[2].y = 895;
		PinkBlock[2].w = 10;
		PinkBlock[2].h = 10;		

		LittleBlueBlock[2].x = 960 - 3*overscancolorbarWidth/2 -5;
		LittleBlueBlock[2].y = 895;
		LittleBlueBlock[2].w = 10;
		LittleBlueBlock[2].h = 10;

		RedBlock[2].x = 960 + 3*overscancolorbarWidth/2 -5;
		RedBlock[2].y = 895;
		RedBlock[2].w = 10;
		RedBlock[2].h = 10;

		YellowBlock[2].x = 960 - 5*overscancolorbarWidth/2 -5;
		YellowBlock[2].y = 895;
		YellowBlock[2].w = 10;
		YellowBlock[2].h = 10;

		BlueBlock[2].x = 960 + 5*overscancolorbarWidth/2 -5;
		BlueBlock[2].y = 895;
		BlueBlock[2].w = 10;
		BlueBlock[2].h = 10;

		if(sidecolorwidth >= 30){
			GrayBlock[2].x = 960 - 3*overscancolorbarWidth - sidecolorwidth/2 -5;
			GrayBlock[2].y = 895;
			GrayBlock[2].w = 10;
			GrayBlock[2].h = 10;
			
			BlackBlock[2].x = 960 + 3*overscancolorbarWidth + sidecolorwidth/2 -5;
			BlackBlock[2].y = 895;
			BlackBlock[2].w = 10;
			BlackBlock[2].h = 10;
		} else {
			GrayBlock[2].x = 0;
			GrayBlock[2].y = 0;
			GrayBlock[2].w = 0;
			GrayBlock[2].h = 0;
			
			BlackBlock[2].x = 0;
			BlackBlock[2].y = 0;
			BlackBlock[2].w = 0;
			BlackBlock[2].h = 0;
		}	
	} else if (6 == colorbarnum ){
			/*line one*/
			GreenBlock[0].x = 960 - overscancolorbarWidth/2 -5;
			GreenBlock[0].y = 175;
			GreenBlock[0].w = 10;
			GreenBlock[0].h = 10;
			
			PinkBlock[0].x = 960 + overscancolorbarWidth/2 -5;
			PinkBlock[0].y = 175;
			PinkBlock[0].w = 10;
			PinkBlock[0].h = 10;		
			
			LittleBlueBlock[0].x = 960 - 3*overscancolorbarWidth/2 -5;
			LittleBlueBlock[0].y = 175;
			LittleBlueBlock[0].w = 10;
			LittleBlueBlock[0].h = 10;
			
			RedBlock[0].x = 960 + 3*overscancolorbarWidth/2 -5;
			RedBlock[0].y = 175;
			RedBlock[0].w = 10;
			RedBlock[0].h = 10;
			
			if(sidecolorwidth >= 30){
				YellowBlock[0].x = 960 - 2*overscancolorbarWidth-sidecolorwidth/2 -5;
				YellowBlock[0].y = 175;
				YellowBlock[0].w = 10;
				YellowBlock[0].h = 10;
				
				BlueBlock[0].x = 960 + 2*overscancolorbarWidth+sidecolorwidth/2 -5;
				BlueBlock[0].y = 175;
				BlueBlock[0].w = 10;
				BlueBlock[0].h = 10;

			} else {
				YellowBlock[0].x = 0;
				YellowBlock[0].y = 0;
				YellowBlock[0].w = 0;
				YellowBlock[0].h = 0;
				
				BlueBlock[0].x = 0;
				BlueBlock[0].y = 0;
				BlueBlock[0].w = 0;
				BlueBlock[0].h = 0;

			}

			GrayBlock[0].x = 0;
			GrayBlock[0].y = 0;
			GrayBlock[0].w = 0;
			GrayBlock[0].h = 0;
			
			BlackBlock[0].x = 0;
			BlackBlock[0].y = 0;
			BlackBlock[0].w = 0;
			BlackBlock[0].h = 0;			
			/*line two*/
			GreenBlock[1].x = 960 - overscancolorbarWidth/2 -5;
			GreenBlock[1].y = 535;
			GreenBlock[1].w = 10;
			GreenBlock[1].h = 10;
			
			PinkBlock[1].x = 960 + overscancolorbarWidth/2 -5;
			PinkBlock[1].y = 535;
			PinkBlock[1].w = 10;
			PinkBlock[1].h = 10;		
			
			LittleBlueBlock[1].x = 960 - 3*overscancolorbarWidth/2 -5;
			LittleBlueBlock[1].y = 535;
			LittleBlueBlock[1].w = 10;
			LittleBlueBlock[1].h = 10;
			
			RedBlock[1].x = 960 + 3*overscancolorbarWidth/2 -5;
			RedBlock[1].y = 535;
			RedBlock[1].w = 10;
			RedBlock[1].h = 10;
					
			if(sidecolorwidth >= 30){
				YellowBlock[1].x = 960 - 2*overscancolorbarWidth-sidecolorwidth/2 -5;
				YellowBlock[1].y = 535;
				YellowBlock[1].w = 10;
				YellowBlock[1].h = 10;
				
				BlueBlock[1].x = 960 + 2*overscancolorbarWidth+sidecolorwidth/2 -5;
				BlueBlock[1].y = 535;
				BlueBlock[1].w = 10;
				BlueBlock[1].h = 10;
			} else {
				YellowBlock[1].x = 0;
				YellowBlock[1].y = 0;
				YellowBlock[1].w = 0;
				YellowBlock[1].h = 0;
				
				BlueBlock[1].x = 0;
				BlueBlock[1].y = 0;
				BlueBlock[1].w = 0;
				BlueBlock[1].h = 0;
			}
			GrayBlock[1].x = 0;
			GrayBlock[1].y = 0;
			GrayBlock[1].w = 0;
			GrayBlock[1].h = 0;
			
			BlackBlock[1].x = 0;
			BlackBlock[1].y = 0;
			BlackBlock[1].w = 0;
			BlackBlock[1].h = 0;
			
			/*line three*/
			GreenBlock[2].x = 960 - overscancolorbarWidth/2 -5;
			GreenBlock[2].y = 895;
			GreenBlock[2].w = 10;
			GreenBlock[2].h = 10;
			
			PinkBlock[2].x = 960 + overscancolorbarWidth/2 -5;
			PinkBlock[2].y = 895;
			PinkBlock[2].w = 10;
			PinkBlock[2].h = 10;		
			
			LittleBlueBlock[2].x = 960 - 3*overscancolorbarWidth/2 -5;
			LittleBlueBlock[2].y = 895;
			LittleBlueBlock[2].w = 10;
			LittleBlueBlock[2].h = 10;
			
			RedBlock[2].x = 960 + 3*overscancolorbarWidth/2 -5;
			RedBlock[2].y = 895;
			RedBlock[2].w = 10;
			RedBlock[2].h = 10;
			
			if(sidecolorwidth >= 30){
				YellowBlock[2].x = 960 - 2*overscancolorbarWidth-sidecolorwidth/2 -5;
				YellowBlock[2].y = 895;
				YellowBlock[2].w = 10;
				YellowBlock[2].h = 10;
				
				BlueBlock[2].x = 960 + 2*overscancolorbarWidth+sidecolorwidth/2 -5;
				BlueBlock[2].y = 895;
				BlueBlock[2].w = 10;
				BlueBlock[2].h = 10;

			} else {
				YellowBlock[2].x = 0;
				YellowBlock[2].y = 0;
				YellowBlock[2].w = 0;
				YellowBlock[2].h = 0;
				
				BlueBlock[2].x = 0;
				BlueBlock[2].y = 0;
				BlueBlock[2].w = 0;
				BlueBlock[2].h = 0;
			}
			GrayBlock[2].x = 0;
			GrayBlock[2].y = 0;
			GrayBlock[2].w = 0;
			GrayBlock[2].h = 0;
			
			BlackBlock[2].x = 0;
			BlackBlock[2].y = 0;
			BlackBlock[2].w = 0;
			BlackBlock[2].h = 0;
	} else if (4 == colorbarnum){
		/*line one*/
		GreenBlock[0].x = 960 - overscancolorbarWidth/2 -5;
		GreenBlock[0].y = 175;
		GreenBlock[0].w = 10;
		GreenBlock[0].h = 10;
		
		PinkBlock[0].x = 960 + overscancolorbarWidth/2 -5;
		PinkBlock[0].y = 175;
		PinkBlock[0].w = 10;
		PinkBlock[0].h = 10;		
		
		if(sidecolorwidth >= 30){
			LittleBlueBlock[0].x = 960 - overscancolorbarWidth-sidecolorwidth/2 -5;
			LittleBlueBlock[0].y = 175;
			LittleBlueBlock[0].w = 10;
			LittleBlueBlock[0].h = 10;
			
			RedBlock[0].x = 960 + overscancolorbarWidth+sidecolorwidth/2 -5;
			RedBlock[0].y = 175;
			RedBlock[0].w = 10;
			RedBlock[0].h = 10;
		} else {
			LittleBlueBlock[0].x = 0;
			LittleBlueBlock[0].y = 0;
			LittleBlueBlock[0].w = 0;
			LittleBlueBlock[0].h = 0;
			
			RedBlock[0].x = 0;
			RedBlock[0].y = 0;
			RedBlock[0].w = 0;
			RedBlock[0].h = 0;
		}
		YellowBlock[0].x = 0;
		YellowBlock[0].y = 0;
		YellowBlock[0].w = 0;
		YellowBlock[0].h = 0;
		
		BlueBlock[0].x = 0;
		BlueBlock[0].y = 0;
		BlueBlock[0].w = 0;
		BlueBlock[0].h = 0;	
		
		GrayBlock[0].x = 0;
		GrayBlock[0].y = 0;
		GrayBlock[0].w = 0;
		GrayBlock[0].h = 0;
		
		BlackBlock[0].x = 0;
		BlackBlock[0].y = 0;
		BlackBlock[0].w = 0;
		BlackBlock[0].h = 0; 		

		/*line two*/
		GreenBlock[1].x = 960 - overscancolorbarWidth/2 -5;
		GreenBlock[1].y = 535;
		GreenBlock[1].w = 10;
		GreenBlock[1].h = 10;
		
		PinkBlock[1].x = 960 + overscancolorbarWidth/2 -5;
		PinkBlock[1].y = 535;
		PinkBlock[1].w = 10;
		PinkBlock[1].h = 10;		
		
		if(sidecolorwidth >= 30){
			LittleBlueBlock[1].x = 960 - overscancolorbarWidth-sidecolorwidth/2 -5;
			LittleBlueBlock[1].y = 535;
			LittleBlueBlock[1].w = 10;
			LittleBlueBlock[1].h = 10;
			
			RedBlock[1].x = 960 + overscancolorbarWidth+sidecolorwidth/2 -5;
			RedBlock[1].y = 535;
			RedBlock[1].w = 10;
			RedBlock[1].h = 10;
		} else {
			LittleBlueBlock[1].x = 0;
			LittleBlueBlock[1].y = 0;
			LittleBlueBlock[1].w = 0;
			LittleBlueBlock[1].h = 0;
			
			RedBlock[1].x = 0;
			RedBlock[1].y = 0;
			RedBlock[1].w = 0;
			RedBlock[1].h = 0;
		}
		YellowBlock[1].x = 0;
		YellowBlock[1].y = 0;
		YellowBlock[1].w = 0;
		YellowBlock[1].h = 0;
		
		BlueBlock[1].x = 0;
		BlueBlock[1].y = 0;
		BlueBlock[1].w = 0;
		BlueBlock[1].h = 0;	
		
		GrayBlock[1].x = 0;
		GrayBlock[1].y = 0;
		GrayBlock[1].w = 0;
		GrayBlock[1].h = 0;
		
		BlackBlock[1].x = 0;
		BlackBlock[1].y = 0;
		BlackBlock[1].w = 0;
		BlackBlock[1].h = 0; 		

		/*line three*/
		GreenBlock[2].x = 960 - overscancolorbarWidth/2 -5;
		GreenBlock[2].y = 895;
		GreenBlock[2].w = 10;
		GreenBlock[2].h = 10;
		
		PinkBlock[2].x = 960 + overscancolorbarWidth/2 -5;
		PinkBlock[2].y = 895;
		PinkBlock[2].w = 10;
		PinkBlock[2].h = 10;		
		
		if(sidecolorwidth >= 30){
			LittleBlueBlock[2].x = 960 - overscancolorbarWidth-sidecolorwidth/2 -5;
			LittleBlueBlock[2].y = 895;
			LittleBlueBlock[2].w = 10;
			LittleBlueBlock[2].h = 10;
			
			RedBlock[2].x = 960 + overscancolorbarWidth+sidecolorwidth/2 -5;
			RedBlock[2].y = 895;
			RedBlock[2].w = 10;
			RedBlock[2].h = 10;
		} else {
			LittleBlueBlock[2].x = 0;
			LittleBlueBlock[2].y = 0;
			LittleBlueBlock[2].w = 0;
			LittleBlueBlock[2].h = 0;
			
			RedBlock[2].x = 0;
			RedBlock[2].y = 0;
			RedBlock[2].w = 0;
			RedBlock[2].h = 0;
		}
		YellowBlock[2].x = 0;
		YellowBlock[2].y = 0;
		YellowBlock[2].w = 0;
		YellowBlock[2].h = 0;
		
		BlueBlock[2].x = 0;
		BlueBlock[2].y = 0;
		BlueBlock[2].w = 0;
		BlueBlock[2].h = 0;	
		
		GrayBlock[2].x = 0;
		GrayBlock[2].y = 0;
		GrayBlock[2].w = 0;
		GrayBlock[2].h = 0;
		
		BlackBlock[2].x = 0;
		BlackBlock[2].y = 0;
		BlackBlock[2].w = 0;
		BlackBlock[2].h = 0; 		

	}else if ((2 == colorbarnum) || (0 == colorbarnum)) {
		/*line one*/
		GreenBlock[0].x = 475;
		GreenBlock[0].y = 175;
		GreenBlock[0].w = 10;
		GreenBlock[0].h = 10;
		
		PinkBlock[0].x = 475;
		PinkBlock[0].y = 175;
		PinkBlock[0].w = 10;
		PinkBlock[0].h = 10;		
		
		LittleBlueBlock[0].x = 0;
		LittleBlueBlock[0].y = 0;
		LittleBlueBlock[0].w = 0;
		LittleBlueBlock[0].h = 0;
		
		RedBlock[0].x = 0;
		RedBlock[0].y = 0;
		RedBlock[0].w = 0;
		RedBlock[0].h = 0;

		YellowBlock[0].x = 0;
		YellowBlock[0].y = 0;
		YellowBlock[0].w = 0;
		YellowBlock[0].h = 0;
		
		BlueBlock[0].x = 0;
		BlueBlock[0].y = 0;
		BlueBlock[0].w = 0;
		BlueBlock[0].h = 0;	
		
		GrayBlock[0].x = 0;
		GrayBlock[0].y = 0;
		GrayBlock[0].w = 0;
		GrayBlock[0].h = 0;
		
		BlackBlock[0].x = 0;
		BlackBlock[0].y = 0;
		BlackBlock[0].w = 0;
		BlackBlock[0].h = 0; 

		/*line two*/
		GreenBlock[1].x = 475;
		GreenBlock[1].y = 535;
		GreenBlock[1].w = 10;
		GreenBlock[1].h = 10;
		
		PinkBlock[1].x = 475;
		PinkBlock[1].y = 535;
		PinkBlock[1].w = 10;
		PinkBlock[1].h = 10;		
		
		LittleBlueBlock[1].x = 0;
		LittleBlueBlock[1].y = 0;
		LittleBlueBlock[1].w = 0;
		LittleBlueBlock[1].h = 0;
		
		RedBlock[1].x = 0;
		RedBlock[1].y = 0;
		RedBlock[1].w = 0;
		RedBlock[1].h = 0;

		YellowBlock[1].x = 0;
		YellowBlock[1].y = 0;
		YellowBlock[1].w = 0;
		YellowBlock[1].h = 0;
		
		BlueBlock[1].x = 0;
		BlueBlock[1].y = 0;
		BlueBlock[1].w = 0;
		BlueBlock[1].h = 0;	
		
		GrayBlock[1].x = 0;
		GrayBlock[1].y = 0;
		GrayBlock[1].w = 0;
		GrayBlock[1].h = 0;
		
		BlackBlock[1].x = 0;
		BlackBlock[1].y = 0;
		BlackBlock[1].w = 0;
		BlackBlock[1].h = 0; 

		/*line three*/
		GreenBlock[2].x = 475;
		GreenBlock[2].y = 895;
		GreenBlock[2].w = 10;
		GreenBlock[2].h = 10;
		
		PinkBlock[2].x = 475;
		PinkBlock[2].y = 895;
		PinkBlock[2].w = 10;
		PinkBlock[2].h = 10;		
		
		LittleBlueBlock[2].x = 0;
		LittleBlueBlock[2].y = 0;
		LittleBlueBlock[2].w = 0;
		LittleBlueBlock[2].h = 0;
		
		RedBlock[2].x = 0;
		RedBlock[2].y = 0;
		RedBlock[2].w = 0;
		RedBlock[2].h = 0;

		YellowBlock[2].x = 0;
		YellowBlock[2].y = 0;
		YellowBlock[2].w = 0;
		YellowBlock[2].h = 0;
		
		BlueBlock[2].x = 0;
		BlueBlock[2].y = 0;
		BlueBlock[2].w = 0;
		BlueBlock[2].h = 0;	
		
		GrayBlock[2].x = 0;
		GrayBlock[2].y = 0;
		GrayBlock[2].w = 0;
		GrayBlock[2].h = 0;
		
		BlackBlock[2].x = 0;
		BlackBlock[2].y = 0;
		BlackBlock[2].w = 0;
		BlackBlock[2].h = 0; 
	} 
	return TRUE;
}

/*colorbar type is master7800 PTG pattern 32 colorbar 75%*/
unsigned char Check_DisplayFrame_isRightColorbar(void)
{
	KADP_VT_RECT_T OutputRegion;
	KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T VideoFrameOutputDeviceState;
	unsigned int IndexOfCurrentVideoFrameBuffer;
	unsigned int colorbarbufferaddr;

	VIDEO_RECT_T GrayBlock[3];
	VIDEO_RECT_T YellowBlock[3];
	VIDEO_RECT_T LittleBlueBlock[3];
	VIDEO_RECT_T GreenBlock[3];
	VIDEO_RECT_T PinkBlock[3];
	VIDEO_RECT_T RedBlock[3];
	VIDEO_RECT_T BlueBlock[3];
	VIDEO_RECT_T BlackBlock[3];
	
	if (HAL_VT_InitEx(5) == FALSE){
		rtd_printk(KERN_EMERG, TAG_NAME, "HAL_VT_Init fail!%s=%d \n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	
	OutputRegion.x = 0;
	OutputRegion.y = 0;
	OutputRegion.w = 1920;
	OutputRegion.h = 1080;
	if (HAL_VT_SetVideoFrameOutputDeviceOutputRegion(KADP_VT_VIDEO_WINDOW_0, KADP_VT_DISPLAY_OUTPUT, &OutputRegion) == FALSE){
		rtd_printk(KERN_EMERG, TAG_NAME, "HAL_VT_SetVideoFrameOutputDeviceOutputRegion fail!%s=%d \n", __FUNCTION__, __LINE__);
		HAL_VT_Finalize();
		return FALSE;
	}
	
	VideoFrameOutputDeviceState.bAppliedPQ = 0;
	VideoFrameOutputDeviceState.bEnabled = 1;
	VideoFrameOutputDeviceState.framerateDivide = 0;
	VideoFrameOutputDeviceState.bFreezed = 1;
	if (HAL_VT_SetVideoFrameOutputDeviceState(KADP_VT_VIDEO_WINDOW_0, KADP_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED, &VideoFrameOutputDeviceState) ==FALSE){
		rtd_printk(KERN_EMERG, TAG_NAME, "HAL_VT_SetVideoFrameOutputDeviceState fail!%s=%d \n", __FUNCTION__, __LINE__);
		HAL_VT_Finalize();
		return FALSE;	
	}

	if (HAL_VT_GetVideoFrameBufferIndex(KADP_VT_VIDEO_WINDOW_0, &IndexOfCurrentVideoFrameBuffer) == FALSE){
		rtd_printk(KERN_EMERG, TAG_NAME, "HAL_VT_SetVideoFrameOutputDeviceState fail!%s=%d \n", __FUNCTION__, __LINE__);
		HAL_VT_Finalize();
		return FALSE;			
	}	

	colorbarbufferaddr =(unsigned int) CaptureCtrl_VT.cap_buffer[IndexOfCurrentVideoFrameBuffer].cache;

	Check_colorbar_window_cal(GrayBlock,YellowBlock,LittleBlueBlock,GreenBlock,PinkBlock,RedBlock,BlueBlock,BlackBlock);

	rtd_printk(KERN_EMERG, TAG_NAME, "GrayBlock[0] x=%d;y=%d\n",GrayBlock[0].x,GrayBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "GrayBlock[1] x=%d;y=%d\n",GrayBlock[1].x,GrayBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "GrayBlock[2] x=%d;y=%d\n",GrayBlock[2].x,GrayBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "YellowBlock[0] x=%d;y=%d\n",YellowBlock[0].x,YellowBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "YellowBlock[1] x=%d;y=%d\n",YellowBlock[1].x,YellowBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "YellowBlock[2] x=%d;y=%d\n",YellowBlock[2].x,YellowBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "LittleBlueBlock[0] x=%d;y=%d\n",LittleBlueBlock[0].x,LittleBlueBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "LittleBlueBlock[1] x=%d;y=%d\n",LittleBlueBlock[1].x,LittleBlueBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "LittleBlueBlock[2] x=%d;y=%d\n",LittleBlueBlock[2].x,LittleBlueBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "GreenBlock[0] x=%d;y=%d\n",GreenBlock[0].x,GreenBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "GreenBlock[1] x=%d;y=%d\n",GreenBlock[1].x,GreenBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "GreenBlock[2] x=%d;y=%d\n",GreenBlock[2].x,GreenBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "PinkBlock[0] x=%d;y=%d\n",PinkBlock[0].x,PinkBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "PinkBlock[1] x=%d;y=%d\n",PinkBlock[1].x,PinkBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "PinkBlock[2] x=%d;y=%d\n",PinkBlock[2].x,PinkBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "RedBlock[0] x=%d;y=%d\n",RedBlock[0].x,RedBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "RedBlock[1] x=%d;y=%d\n",RedBlock[1].x,RedBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "RedBlock[2] x=%d;y=%d\n",RedBlock[2].x,RedBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "BlueBlock[0] x=%d;y=%d\n",BlueBlock[0].x,BlueBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "BlueBlock[1] x=%d;y=%d\n",BlueBlock[1].x,BlueBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "BlueBlock[2] x=%d;y=%d\n",BlueBlock[2].x,BlueBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "BlackBlock[0] x=%d;y=%d\n",BlackBlock[0].x,BlackBlock[0].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "BlackBlock[1] x=%d;y=%d\n",BlackBlock[1].x,BlackBlock[1].y);
	rtd_printk(KERN_EMERG, TAG_NAME, "BlackBlock[2] x=%d;y=%d\n",BlackBlock[2].x,BlackBlock[2].y);

	rtd_printk(KERN_EMERG, TAG_NAME, "Check_DisplayFrame_isRightColorbar start!%s=%d \n", __FUNCTION__, __LINE__);
	if(ColorBlock_Compare(colorbarbufferaddr,0xBE,0xBE,0xC2,GrayBlock[0]) == FALSE) 
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xBE,0xBE,0xC2,GrayBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xBE,0xBE,0xC2,GrayBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xBC,0xBB,0,YellowBlock[0]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xBC,0xBB,0,YellowBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xBC,0xBB,0,YellowBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0xB7,0xB5,LittleBlueBlock[0]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0xB7,0xB5,LittleBlueBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0xB7,0xB5,LittleBlueBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0xB5,0,GreenBlock[0]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0xB5,0,GreenBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0xB5,0,GreenBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xB6,0,0xB9,PinkBlock[0]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xB6,0,0xB9,PinkBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xB6,0,0xB9,PinkBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xB8,0,0,RedBlock[0]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xB8,0,0,RedBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0xB8,0,0,RedBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0,0xC0,BlueBlock[0]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0,0xC0,BlueBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0,0xC0,BlueBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0,0,BlackBlock[0]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0,0,BlackBlock[1]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	if(ColorBlock_Compare(colorbarbufferaddr,0,0,0,BlackBlock[2]) == FALSE)
	{
		HAL_VT_Finalize();
		return FALSE;
	}
	HAL_VT_Finalize();
	rtd_printk(KERN_EMERG, TAG_NAME, "Check_DisplayFrame_isRightColorbar success!%s=%d \n", __FUNCTION__, __LINE__);
	return TRUE;

}

/* =======================================VT_BUFFER_DUMP_DEBUG======================================================*/
#define VT_FILE_PATH "/tmp/VtCapture.raw"

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

/*static int file_read(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_read(file, data, size, &offset);

	set_fs(oldfs);
	return ret;
}*/

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

int vt_dump_data_to_file(unsigned int bufferindex, unsigned int size)
{
	struct file* filp = NULL;
	unsigned long outfileOffset = 0;
	if (CaptureCtrl_VT.cap_buffer[bufferindex].cache != NULL) {
		rtd_printk(KERN_EMERG, TAG_NAME,"\n\n\n\n *****************  vt_dump_data_to_file start  ******%x***************\n\n\n\n",(unsigned int)CaptureCtrl_VT.cap_buffer[bufferindex].cache);
		filp = file_open(VT_FILE_PATH, O_RDWR | O_CREAT, 0);
		if (filp == NULL) {
			rtd_printk(KERN_NOTICE, TAG_NAME,"file open fail\n");
			return FALSE;
		}
		file_write(filp, outfileOffset, (unsigned char*)CaptureCtrl_VT.cap_buffer[bufferindex].cache, size);
		file_sync(filp);
		file_close(filp);
		rtd_printk(KERN_EMERG, TAG_NAME,"\n\n\n\n *****************  vt_dump_data_to_file end  *********************\n\n\n\n");
		return TRUE;
	} else {
		rtd_printk(KERN_EMERG, TAG_NAME,"\n\n\n\n *****************  vt_dump_data_to_file NG for null buffer address  *********************\n\n\n\n");
		return FALSE;
	}
}
/* =======================================VT_BUFFER_DUMP_DEBUG======================================================*/

unsigned int VIVT_PM_REGISTER_DATA[][2]
=
{
	{DC2H_DMA_dc2h_Cap_L1_Start_reg, 0},
	{DC2H_DMA_dc2h_Cap_L2_Start_reg, 0},
	{DC2H_DMA_dc2h_Cap_L3_Start_reg, 0},

	{DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg, 0},
	{DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg, 0},
	{DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg, 0},
	{DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg, 0},
	{DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg, 0},
	{DC2H_RGB2YUV_DC2H_Tab1_Yo_reg, 0},
	{DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg, 0},

	{DC2H_SCALEDOWN_DC2H_HSD_Scale_Hor_Factor_reg, 0},
	{DC2H_SCALEDOWN_DC2H_VSD_Scale_Ver_Factor_reg, 0},
	{DC2H_SCALEDOWN_DC2H_HSD_Hor_Segment_reg, 0},
	{DC2H_SCALEDOWN_DC2H_HSD_Hor_Delta1_reg, 0},
	{DC2H_SCALEDOWN_DC2H_HSD_Initial_Value_reg, 0},
	{DC2H_SCALEDOWN_DC2H_VSD_Initial_Value_reg, 0},
	{DC2H_SCALEDOWN_DC2H_HSD_Ctrl0_reg, 0},
	{DC2H_SCALEDOWN_DC2H_VSD_Ctrl0_reg, 0},

	{DC2H_VI_DC2H_DMACTL_reg, 0},
	{DC2H_DMA_dc2h_Seq_mode_CTRL2_reg, 0},
	{DC2H_DMA_dc2h_Cap_CTL0_reg, 0},
	{DC2H_DMA_dc2h_Cap_CTL1_reg, 0},
	{DC2H_DMA_dc2h_seq_byte_channel_swap_reg, 0},
	{DC2H_DMA_dc2h_Seq_mode_CTRL1_reg, 0},
};

#ifdef CONFIG_PM
static int vivt_suspend (struct device *p_dev)
{
	int i,size;

	size = (sizeof(VIVT_PM_REGISTER_DATA)/4)/2;
	for(i=0; i<size; i++)
	{
		VIVT_PM_REGISTER_DATA[i][1]=rtd_inl(VIVT_PM_REGISTER_DATA[i][0]);
	}
	return 0;
}

static int vivt_resume (struct device *p_dev)
{
	int i, size;
	size = (sizeof(VIVT_PM_REGISTER_DATA)/4)/2;
	for(i=0; i<size; i++)
	{
		rtd_outl(VIVT_PM_REGISTER_DATA[i][0],VIVT_PM_REGISTER_DATA[i][1]);
	}
	return 0;
}
#endif

int vivt_open(struct inode *inode, struct file *filp) {
	return 0;
}

ssize_t  vivt_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
	return 0;

}

ssize_t vivt_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

int vivt_release(struct inode *inode, struct file *filep)
{
	return 0;
}

long vivt_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{
	int retval = 0;
	if (_IOC_TYPE(cmd) != VT_IOC_MAGIC || _IOC_NR(cmd) > VT_IOC_MAXNR) return -ENOTTY ;
	
	switch (cmd)
	{
		case VT_IOC_INIT:
		{
			if(HAL_VT_Init()==FALSE)
				retval = -1;
			break;
		}
		case VT_IOC_INITEX:
		{
			unsigned int buffernum;
			if(copy_from_user((void *)&buffernum, (const void __user *)arg, sizeof(unsigned int)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_INITEX failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_InitEx(buffernum)==FALSE)
					retval =  -1;
			}
			break;
		}		
		case VT_IOC_FINALIZE:
		{
			//addr = *((unsigned int *)arg);
			if(HAL_VT_Finalize()==FALSE)
				retval = -1;
			break;
		}
		case VT_IOC_GET_DEVICE_CAPABILITY:
		{
			KADP_VT_DEVICE_CAPABILITY_INFO_T DeviceCapabilityInfo;
			if(HAL_VT_GetDeviceCapability(&DeviceCapabilityInfo)==FALSE) {
				retval = -1;
			} else {
				if(copy_to_user((void __user *)arg, (void *)&DeviceCapabilityInfo, sizeof(KADP_VT_DEVICE_CAPABILITY_INFO_T)))
				{
					retval = -EFAULT;
					rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_DEVICE_CAPABILITY failed!!!!!!!!!!!!!!!\n");
				}
			}

			break;
		}
		case VT_IOC_GET_VFB_CAPABILITY:
		{
			KADP_VT_VFB_CAPINFO_T vfb_capinfo;
			if(copy_from_user((void *)&vfb_capinfo, (const void __user *)arg, sizeof(KADP_VT_VFB_CAPINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFB_CAPABILITY failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameBufferCapability(vfb_capinfo.wid,&vfb_capinfo.vfbCapInfo)==FALSE) {
					retval = -1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfb_capinfo, sizeof(KADP_VT_VFB_CAPINFO_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFB_CAPABILITY failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VT_IOC_GET_VFOD_CAPABILITY:
		{
			KADP_VT_VFOD_CAPINFO_T vfod_capinfo;
			if(copy_from_user((void *)&vfod_capinfo, (const void __user *)arg, sizeof(KADP_VT_VFOD_CAPINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFOD_CAPABILITY failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameOutputDeviceCapability(vfod_capinfo.wid,&vfod_capinfo.vfodCapInfo)==FALSE) {
					retval = -1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfod_capinfo, sizeof(KADP_VT_VFOD_CAPINFO_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFOD_CAPABILITY failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VT_IOC_GET_VFOD_LIMITATION:
		{
			KADP_VT_VFOD_LIMITATIONINFO_T vfod_limitationinfo;
			if(copy_from_user((void *)&vfod_limitationinfo, (const void __user *)arg, sizeof(KADP_VT_VFOD_LIMITATIONINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFOD_LIMITATION failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameOutputDeviceLimitation(vfod_limitationinfo.wid,&vfod_limitationinfo.vfodlimitationInfo)==FALSE) {
					retval = -1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfod_limitationinfo, sizeof(KADP_VT_VFOD_LIMITATIONINFO_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFOD_LIMITATION failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VT_IOC_GET_ALLVFB_PROPERTY:
		{
			KADP_VT_VFB_PROPERTY_T vfb_property;
			if(copy_from_user((void *)&vfb_property, (const void __user *)arg, sizeof(KADP_VT_VFB_PROPERTY_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_ALLVFB_PROPERTY failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetAllVideoFrameBufferProperty(vfb_property.wid,&vfb_property.vfbProInfo)==FALSE) {
					retval = -1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfb_property, sizeof(KADP_VT_VFB_PROPERTY_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_ALLVFB_PROPERTY failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VT_IOC_GET_VFB_INDEX:
		{
			KADP_VT_GET_VFBINDEX_T vfb_index;
			if(copy_from_user((void *)&vfb_index, (const void __user *)arg, sizeof(KADP_VT_GET_VFBINDEX_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFB_INDEX failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameBufferIndex(vfb_index.wid,&vfb_index.IndexCurVFB)==FALSE) {
					retval = -1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfb_index, sizeof(KADP_VT_GET_VFBINDEX_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFB_INDEX failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VT_IOC_GET_VFOD_STATE:
		{
			KADP_VT_VFOD_GET_STATEINFO_T vfodgetstateinfo;
			if(copy_from_user((void *)&vfodgetstateinfo, (const void __user *)arg, sizeof(KADP_VT_VFOD_GET_STATEINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFOD_STATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameOutputDeviceState(vfodgetstateinfo.wid,&vfodgetstateinfo.VFODstate)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfodgetstateinfo, sizeof(KADP_VT_VFOD_GET_STATEINFO_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFOD_STATE failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VT_IOC_SET_VFOD_STATE:
		{
			KADP_VT_VFOD_SET_STATEINFO_T vfodsetstateinfo;
			if(copy_from_user((void *)&vfodsetstateinfo, (const void __user *)arg, sizeof(KADP_VT_VFOD_SET_STATEINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_SET_VFOD_STATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_SetVideoFrameOutputDeviceState(vfodsetstateinfo.wid,vfodsetstateinfo.vfodStateFlag,&vfodsetstateinfo.VFODstate)==FALSE)
					retval =-1;
			}

			break;
		}
		case VT_IOC_GET_VFOD_FRAMERATE:
		{
			KADP_VT_VFOD_GET_FRAMERATE_T vfodgetfr;
			if(copy_from_user((void *)&vfodgetfr, (const void __user *)arg, sizeof(KADP_VT_VFOD_GET_FRAMERATE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFOD_FRAMERATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameOutputDeviceFramerate(vfodgetfr.wid,&vfodgetfr.framerate)==FALSE) {
					retval = -1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfodgetfr, sizeof(KADP_VT_VFOD_GET_FRAMERATE_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFOD_FRAMERATE failed!!!!!!!!!!!!!!!\n");
					}
				}
			}

			break;
		}
		case VT_IOC_GET_VFOD_DUMPLOCATION:
		{
			KADP_VT_VFOD_GET_DUMPLOCATION_T vfodgetdumplocation;
			if(copy_from_user((void *)&vfodgetdumplocation, (const void __user *)arg, sizeof(KADP_VT_VFOD_GET_DUMPLOCATION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFOD_DUMPLOCATION failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameOutputDeviceDumpLocation(vfodgetdumplocation.wid,&vfodgetdumplocation.DumpLocation)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfodgetdumplocation, sizeof(KADP_VT_VFOD_GET_DUMPLOCATION_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFOD_DUMPLOCATION failed!!!!!!!!!!!!!!!\n");
					}
				}
			}

			break;
		}
		case VT_IOC_SET_VFOD_DUMPLOCATION:
		{
			KADP_VT_VFOD_SET_DUMPLOCATION_T vfodsetdumplocation;
			if(copy_from_user((void *)&vfodsetdumplocation, (const void __user *)arg, sizeof(KADP_VT_VFOD_SET_DUMPLOCATION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_SET_VFOD_DUMPLOCATION failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_SetVideoFrameOutputDeviceDumpLocation(vfodsetdumplocation.wid,vfodsetdumplocation.DumpLocation)==FALSE)
					retval =-1;
			}

			break;
		}
		case VT_IOC_GET_VFOD_OUTPUTINFO:
		{
			KADP_VT_VFOD_GET_OUTPUTINFO_T vfodgetoututinfo;
			if(copy_from_user((void *)&vfodgetoututinfo, (const void __user *)arg, sizeof(KADP_VT_VFOD_GET_OUTPUTINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFOD_OUTPUTINFO failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameOutputDeviceOutputInfo(vfodgetoututinfo.wid,vfodgetoututinfo.DumpLocation,&vfodgetoututinfo.OutputInfo)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfodgetoututinfo, sizeof(KADP_VT_VFOD_GET_OUTPUTINFO_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFOD_OUTPUTINFO failed!!!!!!!!!!!!!!!\n");
					}
				}
			}

			break;
		}
		case VT_IOC_SET_VFOD_OUTPUTREGION:
		{
			KADP_VT_VFOD_SET_OUTPUTREGION_T vfodsetoututinfo;
			if(copy_from_user((void *)&vfodsetoututinfo, (const void __user *)arg, sizeof(KADP_VT_VFOD_SET_OUTPUTREGION_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_SET_VFOD_OUTPUTREGION failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_SetVideoFrameOutputDeviceOutputRegion(vfodsetoututinfo.wid,vfodsetoututinfo.DumpLocation,&vfodsetoututinfo.OutputRegion)==FALSE)
					retval =-1;
			}

			break;
		}
		case VT_IOC_WAIT_VSYNC:
		{
			KADP_VT_VIDEO_WINDOW_TYPE_T videoWindowID;
			if(copy_from_user((void *)&videoWindowID, (const void __user *)arg, sizeof(KADP_VT_VIDEO_WINDOW_TYPE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vt ioctl code=VT_IOC_WAIT_VSYNC failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_WaitVsync(videoWindowID)==FALSE)
					retval =-1;
			}
			break;
		}
		case VT_IOC_GET_INPUTVIDEOINFO:
		{
			KADP_VT_GET_INPUTVIDEOINFO_T inputvideoinfo;
			if(copy_from_user((void *)&inputvideoinfo, (const void __user *)arg, sizeof(KADP_VT_GET_INPUTVIDEOINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_INPUTVIDEOINFO failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetInputVideoInfo(inputvideoinfo.wid,&inputvideoinfo.InputVideoInfo)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&inputvideoinfo, sizeof(KADP_VT_GET_INPUTVIDEOINFO_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_INPUTVIDEOINFO failed!!!!!!!!!!!!!!!\n");
					}
				}
			}

			break;
		}
		case VT_IOC_GET_OUTPUTVIDEOINFO:
		{
			KADP_VT_GET_OUTPUTVIDEOINFO_T onputvideoinfo;
			if(copy_from_user((void *)&onputvideoinfo, (const void __user *)arg, sizeof(KADP_VT_GET_OUTPUTVIDEOINFO_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vt ioctl code=VT_IOC_GET_OUTPUTVIDEOINFO failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetOutputVideoInfo(onputvideoinfo.wid,&onputvideoinfo.OutputVideoInfo)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&onputvideoinfo, sizeof(KADP_VT_GET_OUTPUTVIDEOINFO_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_OUTPUTVIDEOINFO failed!!!!!!!!!!!!!!!\n");
					}
				}
			}

			break;
		}
		case VT_IOC_GET_VIDEOMUTESTATUS:
		{
			KADP_VT_GET_VIDEOMUTESTATUS_T videomutestatus;
			if(copy_from_user((void *)&videomutestatus, (const void __user *)arg, sizeof(KADP_VT_GET_VIDEOMUTESTATUS_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VIDEOMUTESTATUS failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoMuteStatus(videomutestatus.wid,&videomutestatus.bOnOff)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&videomutestatus, sizeof(KADP_VT_GET_VIDEOMUTESTATUS_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VIDEOMUTESTATUS failed!!!!!!!!!!!!!!!\n");
					}
				}
			}

			break;
		}
		case VT_IOC_GET_VFB_SVSTATE:
		{
			KADP_VT_GET_VFBSVSTATE_T vfbsvstatus;
			if(copy_from_user((void *)&vfbsvstatus, (const void __user *)arg, sizeof(KADP_VT_GET_VFBSVSTATE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "copy_from_user:scaler vt ioctl code=VT_IOC_GET_VFB_SVSTATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameBufferSecureVideoState(vfbsvstatus.wid,&vfbsvstatus.IsSecureVideo)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfbsvstatus, sizeof(KADP_VT_GET_VFBSVSTATE_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFB_SVSTATE failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		case VT_IOC_GET_VFOD_BLOCKSTATE:
		{
			KADP_VT_GET_VFODBLOCKSTATE_T vfodblockstatus;
			if(copy_from_user((void *)&vfodblockstatus, (const void __user *)arg, sizeof(KADP_VT_GET_VFODBLOCKSTATE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vt ioctl code=VT_IOC_GET_VFOD_BLOCKSTATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_GetVideoFrameOutputDeviceBlockState(vfodblockstatus.wid,&vfodblockstatus.bBlockState)==FALSE) {
					retval =-1;
				} else {
					if(copy_to_user((void __user *)arg, (void *)&vfodblockstatus, sizeof(KADP_VT_GET_VFODBLOCKSTATE_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_GET_VFOD_BLOCKSTATE failed!!!!!!!!!!!!!!!\n");
					}

				}
			}
			break;
		}
		case VT_IOC_SET_VFOD_BLOCKSTATE:
		{
			KADP_VT_SET_VFODBLOCKSTATE_T setvfodblockstatus;
			if(copy_from_user((void *)&setvfodblockstatus, (const void __user *)arg, sizeof(KADP_VT_SET_VFODBLOCKSTATE_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vt ioctl code=VT_IOC_SET_VFOD_BLOCKSTATE failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_SetVideoFrameOutputDeviceBlockState(setvfodblockstatus.wid,setvfodblockstatus.bBlockState)==FALSE)
					retval =-1;
			}
			break;
		}
		case VT_IOC_VFB_DATASHOW_ONSUBDISP:
		{	
			unsigned char vfbdatashowonsub;
			if(copy_from_user((void *)&vfbdatashowonsub, (const void __user *)arg, sizeof(unsigned char)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vt ioctl code=VT_IOC_VFB_DATASHOW_ONSUBDISP failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(Scaler_SubMDispWindow_VFB(vfbdatashowonsub)==FALSE)
					retval =-1;
			}
			break;
		}
		case VT_IOC_SET_PIXEL_FORMAT:
		{	
			VT_CAP_FMT format;
			if(copy_from_user((void *)&format, (const void __user *)arg, sizeof(VT_CAP_FMT)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vt ioctl code=VT_IOC_SET_PIXEL_FORMAT failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(HAL_VT_set_Pixel_Format(format)==FALSE)
					retval =-1;
			}
			break;
		}		
		case VT_IOC_ROWDATA_SHOW_ONSUBDISP:
		{	
			KADP_VT_ROWDATA_SHOW_ONSUBDISP_T VT_ROWDATA_SHOW_ONSUBDISP;
			if(copy_from_user((void *)&VT_ROWDATA_SHOW_ONSUBDISP, (const void __user *)arg, sizeof(KADP_VT_ROWDATA_SHOW_ONSUBDISP_T)))
			{
				retval = -EFAULT;
				rtd_printk(KERN_DEBUG, TAG_NAME, "scaler vt ioctl code=VT_IOC_VFB_DATASHOW_ONSUBDISP failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(Scaler_Rowdata_SubMDispWindow(&VT_ROWDATA_SHOW_ONSUBDISP)==FALSE)
					retval =-1;
				 else 
				 {
					if(copy_to_user((void __user *)arg, (void *)&VT_ROWDATA_SHOW_ONSUBDISP, sizeof(KADP_VT_ROWDATA_SHOW_ONSUBDISP_T)))
					{
						retval = -EFAULT;
						rtd_printk(KERN_DEBUG, TAG_NAME, "copy_to_user:scaler vt ioctl code=VT_IOC_ROWDATA_SHOW_ONSUBDISP failed!!!!!!!!!!!!!!!\n");
					}
				}
			}
			break;
		}
		default:
			rtd_printk(KERN_DEBUG, TAG_NAME, "Scaler vt disp: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
			break ;
		}
	return retval;
}

int vivt_major   = VT_MAJOR;
int vivt_minor   = 0 ;
int vivt_nr_devs = VT_NR_DEVS;

module_param(vivt_major, int, S_IRUGO);
module_param(vivt_minor, int, S_IRUGO);
module_param(vivt_nr_devs, int, S_IRUGO);


static struct class *vivt_class = NULL;
static struct platform_device *vivt_platform_devs = NULL;

struct file_operations vivt_fops= {
	.owner =    THIS_MODULE,
	.open  =    vivt_open,
	.release =  vivt_release,
	.read  =    vivt_read,
	.write = 	vivt_write,
	.unlocked_ioctl = 	vivt_ioctl,
};

#ifdef CONFIG_PM
static const struct dev_pm_ops vivt_pm_ops =
{
	.suspend    = vivt_suspend,
	.resume     = vivt_resume,
#ifdef CONFIG_HIBERNATION
	.freeze 	= vivt_suspend,
	.thaw		= vivt_resume,
	.poweroff	= vivt_suspend,
	.restore	= vivt_resume,
#endif

};
#endif

static struct platform_driver vivt_device_driver = {
    .driver = {
        .name       = VT_DEVICE_NAME,
        .bus        = &platform_bus_type,
#ifdef CONFIG_PM
	.pm 		= &vivt_pm_ops,
#endif

    },
} ;


static char *vivt_devnode(struct device *dev, mode_t *mode)
{
	*mode =0666;
	return NULL;
}

int vivt_init_module(void)
{
	int result;
  	int devno;
	dev_t dev = 0;

	rtd_printk(KERN_DEBUG, TAG_NAME, "\n\n\n\n *****************  vt init module  *********************\n\n\n\n");
	if (vivt_major) {
		dev = MKDEV(vivt_major, vivt_minor);
		result = register_chrdev_region(dev, vivt_nr_devs, VT_DEVICE_NAME);
	} else {
		result = alloc_chrdev_region(&dev, vivt_minor, vivt_nr_devs,VT_DEVICE_NAME);
		vivt_major = MAJOR(dev);
	}
	if (result < 0) {
		rtd_printk(KERN_DEBUG, TAG_NAME, "vt: can't get major %d\n", vivt_major);
		return result;
	}

	rtd_printk(KERN_DEBUG, TAG_NAME, "vt init module major number = %d\n", vivt_major);

	vivt_class = class_create(THIS_MODULE,VT_DEVICE_NAME);

	if (IS_ERR(vivt_class))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "scalevt: can not create class...\n");
		result = PTR_ERR(vivt_class);
		goto fail_class_create;
	}

	vivt_class->devnode = vivt_devnode;

	vivt_platform_devs = platform_device_register_simple(VT_DEVICE_NAME, -1, NULL, 0);

    	if((result=platform_driver_register(&vivt_device_driver)) != 0){
		rtd_printk(KERN_DEBUG, TAG_NAME, "scalevt: can not register platform driver...\n");
		result = -ENOMEM;
		goto fail_platform_driver_register;
    	}

    	devno = MKDEV(vivt_major, vivt_minor);
    	cdev_init(&vivt_cdev, &vivt_fops);
    	vivt_cdev.owner = THIS_MODULE;
   	vivt_cdev.ops = &vivt_fops;
	result = cdev_add (&vivt_cdev, devno, 1);
	if (result<0)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "scalevt: can not add character device...\n");
		goto fail_cdev_init;
	}
    	device_create(vivt_class, NULL, MKDEV(vivt_major, 0), NULL, VT_DEVICE_NAME);
	sema_init(&VT_Semaphore, 1);
	sema_init(&VTBlock_Semaphore, 1);
    return 0;	//success

fail_cdev_init:
	platform_driver_unregister(&vivt_device_driver);
fail_platform_driver_register:
	platform_device_unregister(vivt_platform_devs);
	vivt_platform_devs = NULL;
	class_destroy(vivt_class);
fail_class_create:
	vivt_class = NULL;
	unregister_chrdev_region(vivt_devno, 1);
	return result;
}

void __exit vivt_cleanup_module(void)
{
	dev_t devno = MKDEV(vivt_major, vivt_minor);
	rtd_printk(KERN_DEBUG, TAG_NAME, "rtice clean module vt_major = %d\n", vivt_major);
  	device_destroy(vivt_class, MKDEV(vivt_major, 0));
  	class_destroy(vivt_class);
	vivt_class = NULL;
	cdev_del(&vivt_cdev);
   	/* device driver removal */
	if(vivt_platform_devs) {
		platform_device_unregister(vivt_platform_devs);
		vivt_platform_devs = NULL;
	}
  	platform_driver_unregister(&vivt_device_driver);
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, vivt_nr_devs);
}

module_init(vivt_init_module) ;
module_exit(vivt_cleanup_module) ;
