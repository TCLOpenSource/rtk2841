/***************************************************************************
                          scalerVideoTable.c  -  description
                             -------------------
    begin                : Mon April 26 2010
    copyright           : (C) 2008 by jennifer
    email                : jenniferchang@realtek.com
 ***************************************************************************/

// oliver-
/*
#include <linux/version.h>	// kernel version

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0)
	#ifndef __KERNEL__
		#define __KERNEL__
	#endif
#endif

#include <linux/module.h>	// normal module use
#include <linux/kernel.h>	// printk()
*/

// oliver+
//#include <auto_conf.h>

//#include <rtd_macro.h>
// oliver-
//#include <realtek/irc.h>

// driver header
#include <scalercommon/scalerCommon.h>
//#include <kernel/scaler/scalerInfo.h>
#include "vgip_isr/scalerVideo.h"
#include "vgip_isr/scalerVIP.h"
//#include <kernel/scaler/scalerDrv.h>
//#include <kernel/scaler/scalerIRQ.h>
//#include <kernel/scaler/scalerIRC.h>
//#include <rbus/rbusVideoDecoderReg.h>

  #include <rbus/vdpq_reg.h>
  #include <rbus/vdtop_reg.h>


//#include <libs/vdc/video.h>
//#include <libs/vdc/yc_separation_vpq.h>


// lib header, need discussion (Kernel should not include lib's header.)
//#include <libs/scaler/source.h>
//#include <libs/scaler/modeState.h>


//#define _Table_total 4
//#define _ms_total 7

unsigned short PAL_3D_TH_TV_TABLE[][3] =
{
	{0x3200, 0x3600, 0x3A00},
	{0x4000, 0x4400, 0x4800},
	{0x6000, 0x6400, 0x6800},
	{0x8000, 0x8400, 0x8800}
};

unsigned short PALMN_3D_TH_TV_TABLE[][3] =
{
	{0x3200, 0x3600, 0x3A00},
	{0x4000, 0x4400, 0x4800},
	{0x6000, 0x6400, 0x6800},
	{0x8000, 0x8400, 0x8800}
};

unsigned short NTSC_3D_TH_TABLE[][3] =
{
	{0x2A00, 0x3000, 0x5000},
	{0x2B00, 0x3200, 0x5200},
	{0x2D00, 0x3200, 0x5200},
	{0x3000, 0x3200, 0x5200}
};

unsigned short PAL_3D_TH_TABLE[][3] =
{
	{0x1C00, 0x2200, 0x2800},
	{0x2000, 0x2600, 0x2A00},
	{0x2400, 0x2A00, 0x3000},
	{0x2800, 0x3000, 0x3600}
};




unsigned int VD_MA_TH_TABLE[_Table_total][_ms_total][3] =
{
	{	// _TV_NTSC
		{0x000001d0, 0x00000160, 0x0000009f},	// _ms_0, still
		{0x00000a00, 0x000004d0, 0x00000500},	// _ms_1
		{0x00007000, 0x00000800, 0x00001000},	// _ms_2
		{0x00010000, 0x00002200, 0x00002000},	// _ms_3
		{0x0001A000, 0x00002200, 0x00002800},	// _ms_4
		{0x00020000, 0x00004000, 0x00005000},	// _ms_5
		{0x00030000, 0x00004000, 0x00008000}	// _ms_6
	},
	{	// _TV_PAL
		{0x000001D0, 0x00000160, 0x0000009F},	// _ms_0, still
		{0x00000a00, 0x000004d0, 0x00000500},	// _ms_1
		{0x00007000, 0x00000800, 0x00001000},	// _ms_2
		{0x00010000, 0x00008000, 0x00004000},	// _ms_3
		{0x0001A000, 0x00002200, 0x00002800},	// _ms_4
		{0x00020000, 0x00004000, 0x00005000},	// _ms_5
		{0x00030000, 0x00004000, 0x00008000}	// _ms_6
	},
	{	// _AV_NTSC
		{0x000001D0, 0x00000160, 0x0000009F},	// _ms_0, still
		{0x00000a00, 0x000004d0, 0x00000500},	// _ms_1
		{0x00007000, 0x00000800, 0x00001000},	// _ms_2
		{0x00010000, 0x00002200, 0x00002000},	// _ms_3
		{0x0001A000, 0x00002200, 0x00002800},	// _ms_4
		{0x00020000, 0x00020000, 0x00005000},	// _ms_5
		{0x00030000, 0x00004000, 0x00008000}	// _ms_6
	},
	{	// _AV_PAL
		{0x000001D0, 0x00000160, 0x0000009F},	// _ms_0, still
		{0x00000a00, 0x000004d0, 0x00000500},	// _ms_1
		{0x00007000, 0x00000800, 0x00001000},	// _ms_2
		{0x00010000, 0x00008000, 0x00004000},	// _ms_3
		{0x0001A000, 0x00002200, 0x00002800},	// _ms_4
		{0x00020000, 0x00004000, 0x00005000},	// _ms_5
		{0x00030000, 0x00004000, 0x00008000}	// _ms_6
	}
};

#if 0 //frank@1127 reduce code
UINT8  VDC_1D_SET1[]=
//no_signal, NTSC, NTSC_443, NTSC_50, SECAM
{
	4, HIGH_BYTE(VDC_YC_SEP_CONTROL_VADDR), LOW_BYTE(VDC_YC_SEP_CONTROL_VADDR), 0x03,
	4, HIGH_BYTE(VDC_ADAP_BPF_C_TH1_VADDR), LOW_BYTE(VDC_ADAP_BPF_C_TH1_VADDR), 0x0c,
	4, HIGH_BYTE(VDC_ADAP_BPF_C_TH2_VADDR), LOW_BYTE(VDC_ADAP_BPF_C_TH2_VADDR), 0x14,
	4, HIGH_BYTE(VDC_ADAP_BPF_Y_TH2_VADDR), LOW_BYTE(VDC_ADAP_BPF_Y_TH2_VADDR), 0x03,
	4, HIGH_BYTE(VDC_YC_BW_CTRL_VADDR), LOW_BYTE(VDC_YC_BW_CTRL_VADDR), 0x01,
	4, HIGH_BYTE(VDC_YC_SEP_MODE_CTRL_VADDR), LOW_BYTE(VDC_YC_SEP_MODE_CTRL_VADDR), 0x00,
	4, HIGH_BYTE(VDC_DMA_CTRL5_VADDR), LOW_BYTE(VDC_DMA_CTRL5_VADDR), 0x4c,
	4, HIGH_BYTE(VDC_BPF_BW_SEL_Y_VADDR), LOW_BYTE(VDC_BPF_BW_SEL_Y_VADDR), 0x43,
	_TBL_END
};

UINT8  VDC_1D_SET2[]=
//PAL_I, PAL_M, PAL_N
{
	4, HIGH_BYTE(VDC_YC_SEP_CONTROL_VADDR), LOW_BYTE(VDC_YC_SEP_CONTROL_VADDR), 0x03,
	4, HIGH_BYTE(VDC_ADAP_BPF_C_TH1_VADDR), LOW_BYTE(VDC_ADAP_BPF_C_TH1_VADDR), 0x03,
	4, HIGH_BYTE(VDC_ADAP_BPF_C_TH2_VADDR), LOW_BYTE(VDC_ADAP_BPF_C_TH2_VADDR), 0x0c,
	4, HIGH_BYTE(VDC_ADAP_BPF_Y_TH2_VADDR), LOW_BYTE(VDC_ADAP_BPF_Y_TH2_VADDR), 0x13,
	4, HIGH_BYTE(VDC_YC_BW_CTRL_VADDR), LOW_BYTE(VDC_YC_BW_CTRL_VADDR), 0x49,
	4, HIGH_BYTE(VDC_YC_SEP_MODE_CTRL_VADDR), LOW_BYTE(VDC_YC_SEP_MODE_CTRL_VADDR), 0x00,
	4, HIGH_BYTE(VDC_DMA_CTRL5_VADDR),        LOW_BYTE(VDC_DMA_CTRL5_VADDR), 0x4c,
	4, HIGH_BYTE(VDC_BPF_BW_SEL_Y_VADDR), LOW_BYTE(VDC_BPF_BW_SEL_Y_VADDR), 0x43,
	_TBL_END
};

UINT8  VDC_1D_SET3[]=
//PAL_60
{
	4, HIGH_BYTE(VDC_VIDEO_CONTROL0_VADDR), LOW_BYTE(VDC_VIDEO_CONTROL0_VADDR), 0x0e,
	4, HIGH_BYTE(VDC_YC_SEP_CONTROL_VADDR), LOW_BYTE(VDC_YC_SEP_CONTROL_VADDR), 0x03,
	4, HIGH_BYTE(VDC_YC_BW_CTRL_VADDR), LOW_BYTE(VDC_YC_BW_CTRL_VADDR), 0x49,
	4, HIGH_BYTE(VDC_YC_SEP_MODE_CTRL_VADDR), LOW_BYTE(VDC_YC_SEP_MODE_CTRL_VADDR), 0x00,
	4, HIGH_BYTE(VDC_DMA_CTRL5_VADDR), LOW_BYTE(VDC_DMA_CTRL5_VADDR), 0x4c,
	4, HIGH_BYTE(VDC_BPF_BW_SEL_Y_VADDR), LOW_BYTE(VDC_BPF_BW_SEL_Y_VADDR), 0x43,
	_TBL_END
};
#endif
