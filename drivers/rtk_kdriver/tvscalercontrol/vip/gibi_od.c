/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for color related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version 	$Revision$
 */

/**
 * @addtogroup color
 * @{
 */

/*============================ Module dependency  ===========================*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/pageremap.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/auth.h>
#include <linux/semaphore.h>//for semaphore

#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <mach/rtk_log.h>
#include <rbus/lgd_dither_reg.h>
#include <rbus/pcid_reg.h>
#define TAG_NAME "VPQ"
#else

#include <unistd.h>			// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <sys/ioctl.h>

//#include "rtd_regs.h"
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
//#include <Application/AppClass/TvControl/Utils/RtSystem.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerStruct.h>
#include <Platform_Lib/TVScalerControl/scalerDrv/mode.h>
#include <Platform_Lib/TVScalerControl/scalerDrv/scalerMemory.h>
#include <Platform_Lib/TVScalerControl/scaler/source.h>
#include <Platform_Lib/panel/panelAPI.h>
//#include <kernel/scaler/scalerDrv.h>	// kernel space
#include <Platform_Lib/TVScalerControl/scalerDrv/scalerDrv.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#include <Platform_Lib/TVScalerControl/vip/gibi_od.h>
#include "Platform_Lib/TVScalerControl/scalerDrv/scalerMemory.h"
//#include "rtd_struct.h"
//#include <rbusPpOverlayReg.h>
#include <ppoverlay_reg.h>
#include <lgd_dither_reg.h>
#endif

#define OD_TABLE_LEN	17

/*#ifdef OPEN_CELL_PANEL*/
extern unsigned int *ODtable_Coeff;    /*young vippanel*/
/*#endif*/

/*===================================  Types ================================*/

/*================================== Variables ==============================*/
unsigned char bODMemCheck = 0;
/*================================ Definitions ==============================*/
#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif
/*================================== Function ===============================*/


void drvif_color_od_for_demo()
{
	//unsigned int memory_address;

	VIPprintf("[OD] Gibi_od.cpp drvif_color_od_for_demo() calling...\n");

	/* 50% Od table setting*/
	IoReg_Write32(OD_OD_LUT_ADDR_reg, 0x00013000); /* write all channel, delte table*/

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 1
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000001);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000002);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000A);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000014);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000017);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001A);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001C);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001C);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000019);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000014);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000F);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000C);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000008);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 2
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000001);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000008);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000011);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000015);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000018);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001A);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000019);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000001A);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000018);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000013);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000F);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000C);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000008);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 3
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000004);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000D);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000011);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000015);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000017);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000017);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000017);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000018);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000017);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000011);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000F);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000007);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 4
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000006);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000C);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000010);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000013);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000010);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000015);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000016);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000015);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000010);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000E);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000A);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000006);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 5
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000005);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000A);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000E);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000F);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000012);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000014);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000013);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000E);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000D);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000009);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000005);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 6
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000006);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000C);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000D);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000011);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000010);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000D);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000008);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000005);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 7
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F6);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000004);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000007);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000E);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000E);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000A);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000007);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000004);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 8
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000004);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000007);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x0000000B);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000009);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000009);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000006);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000004);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 9
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F2);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F0);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000007);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000008);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000008);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000008);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000005);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 10
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EF);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000ED);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000005);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000006);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000006);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000004);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 11
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F6);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F0);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EC);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F0);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000005);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000002);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 12
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F6);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EF);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EC);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E8);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EC);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F0);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000001);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000002);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000003);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000002);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 13
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FF);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E6);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E6);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000ED);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000001);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000002);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000002);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 14
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E8);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E3);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E8);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F0);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F3);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000002);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000001);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 15
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FD);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F3);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EC);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E5);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EC);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F0);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F8);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FD);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 16
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FB);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000DF);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000DC);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000DE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E0);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FA);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FC);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000); // 17
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F8);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E6);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000DD);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000D7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000D7);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000D9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E1);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E4);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000E8);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000EE);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F6);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000F9);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x000000FD);
	IoReg_Write32(OD_OD_LUT_DATA_reg, 0x00000000);

	IoReg_Write32(OD_OD_LUT_ADDR_reg, 0x00000000);  /* disable table access*/

#if 0
	/* Compression Setting*/
	/* 1920*1080*12*/
	/* 1920*12/32 = 720 = hact, pixelnum*/
	/* D-domain, 2-pixel mode => use disp11 and disp12.*/
	/* ===============================================================*/
	/* Cap:  720*32/128 = 180 = 63*2+54 = len*num+rem (3F * 2 + 36)*/
	/* ===============================================================*/
	/* Disp: 720*32/128 = 180 = 63*2+54 = len*num+rem (3F * 2 + 36)*/
	/*IoReg_Write32(0xb802cf58, 0x00000001); */ /* decomp_clk_en*/
	IoReg_Write32(0xb802cd00, 0x003C0438); /* (Comp) 1-seg, cmp_width = 1920/32 = 60, cmp_height = 1080*/
	IoReg_Write32(0xb802cd04, 0x1002940C); /* (Comp) "a channel" disable, comp = 12bit*/
	IoReg_Write32(0xb802cd14, 0x003C0438); /* (Dcmp) 1-seg, decmp_width = 1920/32 = 60, decmp_height = 1080*/
	IoReg_Write32(0xb802cd18, 0x00020C07); /* (Dcmp) "a channel" disable, decomp = 12bit*/

	IoReg_Write32(0xb802cd44, 0x00000001); /* tr_en*/

	IoReg_Write32(0xb802cdb0, 0x00000000); /* OD-seg = 1 for 1 pixel mode*/
	IoReg_Write32(0xb802cdb4, 0x002a0000); /* Frame-sequence 2D, lr_sep_en = ON*/
	IoReg_Write32(0xb802cdb8, 0x043802d0); /* vact = 1080, hact = 1920*12/32 = 720*/

	/* Display Setting*/
	/* must confirm seq size, display width/seq num*/
	IoReg_Write32(0xB802CE8C, 0x02d00020); /* disp11_pixel_num = 720, water_lv = 180*/

	IoReg_Write32(0xB802CE9C, 0x17BA2020); /* disp11_num = 2, len = 63, rem = 54*/

	IoReg_Write32(0xB802CEAC, 0x00000B40); /* disp11_line_step = 720*32/64 = 360*/

	IoReg_Write32(0xB802CEBC, 0x00000438); /* disp11_line_num = 1080*/

	/*FIX ME frank@12232013 memory_address = drvif_get_dfrc_memory();*/
	memory_address = drvif_memory_alloc_block(MEMIDX_SUB, 0x76A700, MEMALIGN_ANY);
	/* Capture address*/
	IoReg_Write32(0xB802CDE0, memory_address); /* cap_L1_addr*/
	IoReg_Write32(0xB802CDE4, memory_address+0x76A700); /* cap_L2_addr = L1+F (F = 3840*2160*30bit/128)*/

	/* Display address*/
	IoReg_Write32(0xB802CED4, memory_address); /* disp11_L1_addr*/
	IoReg_Write32(0xB802CED8, memory_address+0x76A700); /* disp11_L2_addr*/

	/* Capture Setting, and ENABLE Capture.*/
	IoReg_Write32(0xB802CDBC, 0x00C80000); /* Cap ON*/
	IoReg_Write32(0xB802CDC0, 0x00022020); /* Comp on, 10bit, 444, len = 63, rem = 54*/
	IoReg_Write32(0xB802CDC4, 0x002017BA); /* cap_water_lv = 63, num = 2*/

	/* Display Setting, and ENABLE Display*/
	IoReg_Write32(0xB802CE0C, 0x00000000); /* frc_en = ON*/
	IoReg_Write32(0xB802CE80, 0x02001100); /* l_flag_hs_dly = 0x200, Disp11 ON, Stop_burst_en = 0*/

	/* Fixed HW Bug.*/
	IoReg_Write32(0xb802cd0c, 0x0);  /*disable compression irq*/
	IoReg_Write32(0xb802cd38, 0x0);  /*disable decompression irq*/
	IoReg_Write32(0xb802cf54, 0x0);  /*disable compression irq*/
	IoReg_ClearBits(0xb802ce30, _BIT26);  /*disable decompression irq*/

	/* OD enable*/
	IoReg_Write32(0xb802ca00, 0x00000003);
	IoReg_Write32(0xb802ca08, 0x00040000); /* output mode*/
	IoReg_Write32(0xb802ca30, 0x0f030303); /* NR*/

	IoReg_Write32(0xb802cf58, 0x00000001); /* decomp_clk_en*/
#endif
}

void drvif_color_od_load_table(UINT32 *input_array)
{
/*	VIPprintf("[OD] load table testing\n", input_array[0]);*/
/*	VIPprintf("[OD] load table testing\n", input_array[1]);*/
/*	VIPprintf("[OD] load table testing\n", input_array[2]);*/
/*	VIPprintf("[OD] load table testing\n", input_array[3]);*/
}

// 160615 added by henry
// 160805 modified by henry
// 160810 modified by henry - add the static memory address
//
// === Argument Explanation ===
//
// width & height: 4K - 3840x2160, 2K - 1920x1080
//
// bits: average bits per pixel for whole frame
//
// mode = 1: 1 pixel mode
//        2: 2 pixel mode
//
// bitsPerPixel: compression ratio
//
// dataColor = 0: RGB Compression
//			 = 1: YUV Compression
//
// dataFormat = 0: 444
//			  = 1: 422
//			  = 2: 420 --> not support RGB compression
//			  = 3: 400 --> not support RGB compression
//
// === Example of using OD PQ compression function ===
//
// Video Resolution  : 4K
// Bits per pixel    : 8
// Pixel Mode        : 2
// compression Ratio : 6bits
// Compression Color : RGB
// Compression Format: 422
//
// drvif_color_od_pqc(2160, 3840, 8, 2, 6, 0, 1)
//
unsigned char drvif_color_od_pqc(UINT16 height, UINT16 width, UINT8 bit_sel, UINT8 mode, UINT8 FrameLimitBit, int dataColor, int dataFormat)
{
	unsigned int od_size = 0;
	unsigned int od_addr = 0;
	unsigned int memory_size = 0;
	unsigned int memory_address1 = 0;
	unsigned int memory_address2 = 0;
	unsigned int burst = 0x20; //0x40
	unsigned int length_disp;
	unsigned int length_cap;

	od_size = carvedout_buf_query(CARVEDOUT_SCALER_OD, &od_addr);
	if (od_addr == 0 || od_size == 0) {
		VIPprintf("[%s %d] ERR : %x %x\n", __func__, __LINE__, od_addr, od_size);
		return false;
	}

	memory_size = od_size / 2; //2MB
	memory_address1 = od_addr;
	memory_address2 = memory_address1 + memory_size;
	length_disp = burst;
	length_cap = burst;

	VIPprintf("[OD] Gibi_od.cpp::drvif_color_od_pqc() calling...\n");

	if (memory_address1 == 0 || memory_address2 == 0) /*(memory_address == NULL || memory_address == 0)*/ /*fix compiler warning*/
	{
		VIPprintf("[OD] Gibi_od.cpp::Memory address Error!! \n");
		return false;
	}

	// dataFormat = 0: 444
	//	 		  = 1: 422
	//	 		  = 2: 420 --> not support RGB compression
	//	 		  = 3: 400 --> not support RGB compression
	//
	// dataColor = 0: RGB Compression
	// 			 = 1: YUV Compression
	//
	if (dataColor == 0 && (dataFormat == 2 || dataFormat == 3)) {
		VIPprintf("[OD] Gibi_od.cpp::input value conflict...\n");
		VIPprintf("420 or 400 doesn't support RGB compression\n");
		return false;
	}

	// 1 & 2 pixel mode
	if( mode != 1 && mode != 2) {
		VIPprintf("[OD]:Gibi_od.cpp::Argument of mode is invalid !\n");
		return false;
	}

	// cmp, decmp pair setting
	od_dma_oddma_pq_cmp_pair_RBUS oddma_pq_cmp_pair_reg;
	od_dma_oddma_pq_decmp_pair_RBUS oddma_pq_decmp_pair_reg;
	oddma_pq_cmp_pair_reg.regValue =  IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_PAIR_reg);
	oddma_pq_decmp_pair_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_DECMP_PAIR_reg);
	oddma_pq_cmp_pair_reg.cmp_data_format = dataFormat;
	oddma_pq_decmp_pair_reg.decmp_data_format = dataFormat;
	oddma_pq_cmp_pair_reg.cmp_data_bit_width = 1;
	oddma_pq_cmp_pair_reg.cmp_data_color = dataColor;
	oddma_pq_decmp_pair_reg.decmp_data_bit_width = 1;
	oddma_pq_decmp_pair_reg.decmp_data_color = dataColor;
	IoReg_Write32(OD_DMA_ODDMA_PQ_CMP_PAIR_reg, oddma_pq_cmp_pair_reg.regValue);
	IoReg_Write32(OD_DMA_ODDMA_PQ_DECMP_PAIR_reg, oddma_pq_decmp_pair_reg.regValue);

	// comp decomp clk enable
	od_dma_oddma_comp_decomp_clk_gated_RBUS od_dma_oddma_comp_decomp_clk_gated_reg;
	od_dma_oddma_comp_decomp_clk_gated_reg.regValue = IoReg_Read32(OD_DMA_oddma_comp_decomp_clk_gated_reg);
	od_dma_oddma_comp_decomp_clk_gated_reg.comp_decomp_clk_en = 1;
	IoReg_Write32(OD_DMA_oddma_comp_decomp_clk_gated_reg, od_dma_oddma_comp_decomp_clk_gated_reg.regValue);

	// b802CD00 PQ_CMP enable
	od_dma_oddma_pq_cmp_RBUS oddma_pq_cmp_reg;
	oddma_pq_cmp_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_reg);
	oddma_pq_cmp_reg.cmp_en = 1;
	oddma_pq_cmp_reg.cmp_width_div32 = width >> 5;
	oddma_pq_cmp_reg.cmp_height = height;
	IoReg_Write32(OD_DMA_ODDMA_PQ_CMP_reg, oddma_pq_cmp_reg.regValue);

	// b802cd08 Compression ratio
	od_dma_oddma_pq_cmp_bit_RBUS oddma_pq_cmp_bit_reg;
	oddma_pq_cmp_bit_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_BIT_reg);
	oddma_pq_cmp_bit_reg.frame_limit_bit = FrameLimitBit;
	// DMA buffer line limit clamp
	oddma_pq_cmp_bit_reg.line_limit_bit = 0xc;
	IoReg_Write32(OD_DMA_ODDMA_PQ_CMP_BIT_reg, oddma_pq_cmp_bit_reg.regValue);

	// b802cd60 PQ_DECMP enable
	od_dma_oddma_pq_decmp_RBUS oddma_pq_decmp_reg;
	oddma_pq_decmp_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_DECMP_reg);
	oddma_pq_decmp_reg.decmp_en = 1;
	oddma_pq_decmp_reg.decmp_width_div32 = width >> 5;
	oddma_pq_decmp_reg.decmp_height = height;
	IoReg_Write32(OD_DMA_ODDMA_PQ_DECMP_reg, oddma_pq_decmp_reg.regValue);

	// b802cd68 Saturation enable
	od_dma_oddma_pq_decmp_sat_en_RBUS oddma_pq_decmp_sat_en_reg;
	oddma_pq_decmp_sat_en_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg);
	oddma_pq_decmp_sat_en_reg.saturation_en = 1;
	IoReg_Write32(OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg, oddma_pq_decmp_sat_en_reg.regValue);

	// b802cdb4 LR seperate enable
	#if 0 /* henry @ mac5 161215 */
	od_dma_oddma_lr_separate_ctrl1_RBUS od_dma_oddma_lr_separate_ctrl1_reg;
	od_dma_oddma_lr_separate_ctrl1_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_LR_Separate_CTRL1_reg);
	od_dma_oddma_lr_separate_ctrl1_reg.lr_separate_en = 1;
	IoReg_Write32(OD_DMA_ODDMA_LR_Separate_CTRL1_reg, od_dma_oddma_lr_separate_ctrl1_reg.regValue);
	#endif
	// b802cdb8 vact and hact
	od_dma_oddma_lr_separate_ctrl2_RBUS od_dma_oddma_lr_separate_ctrl2_reg;
	od_dma_oddma_lr_separate_ctrl2_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_LR_Separate_CTRL2_reg);
	od_dma_oddma_lr_separate_ctrl2_reg.hact = width;
	od_dma_oddma_lr_separate_ctrl2_reg.vact = height;
	IoReg_Write32(OD_DMA_ODDMA_LR_Separate_CTRL2_reg, od_dma_oddma_lr_separate_ctrl2_reg.regValue);

	// b802cdc0 cap ctrl 1
	od_dma_oddma_cap_ctl1_RBUS cap_ctl1_reg;
	cap_ctl1_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Cap_CTL1_reg);
	cap_ctl1_reg.bit_sel = 2; // cap_ctl1_reg.bit_sel: 3 - reserved, 2 -10bits, 1 - 8 bits, 0 - 6 bits
	cap_ctl1_reg.cap_write_len = length_cap;
	IoReg_Write32(OD_DMA_ODDMA_Cap_CTL1_reg, cap_ctl1_reg.regValue);

	// b802cdc4 cap ctrl 2
	od_dma_oddma_cap_ctl2_RBUS cap_ctl2_reg;
	cap_ctl2_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Cap_CTL2_reg);
	cap_ctl2_reg.cap_write_num = 0xffff;
	IoReg_Write32(OD_DMA_ODDMA_Cap_CTL2_reg, cap_ctl2_reg.regValue);

	// b802cdd8 Cap LineStep
	od_dma_oddma_cap_linestep_RBUS od_dma_oddma_cap_linestep_reg;
	od_dma_oddma_cap_linestep_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Cap_LineStep_reg);
	od_dma_oddma_cap_linestep_reg.cap_line_step = 0x384;
	IoReg_Write32(OD_DMA_ODDMA_Cap_LineStep_reg, od_dma_oddma_cap_linestep_reg.regValue);

	// b802ce8c Disp pixelNum WTL
	od_dma_oddma_display_numwtl_RBUS od_dma_oddma_display_numwtl_reg;
	od_dma_oddma_display_numwtl_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Display_NumWTL_reg);
	od_dma_oddma_display_numwtl_reg.disp_pixel_num = 0x780;
	od_dma_oddma_display_numwtl_reg.disp_wtlvl = 0xbf;
	IoReg_Write32(OD_DMA_ODDMA_Display_NumWTL_reg, od_dma_oddma_display_numwtl_reg.regValue);

	// b802ce9c Disp ReadNum ReadLen ReadRem
	od_dma_oddma_display_rdnumlenrem_RBUS display_rdnumlenrem_reg;
	display_rdnumlenrem_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Display_RdNumLenRem_reg);
	display_rdnumlenrem_reg.disp_read_num = 0xffff; //num 設極大值 (0xffff), 讓oddma不會算到要用remain, 純粹看PQC給的last pixel
	display_rdnumlenrem_reg.disp_read_len = length_disp; // len設一次burst的大小(0x20或0x40)
	IoReg_Write32(OD_DMA_ODDMA_Display_RdNumLenRem_reg, display_rdnumlenrem_reg.regValue);

	// b802ceac Disp LineStep
	od_dma_oddma_disp_linestep_RBUS od_dma_oddma_disp_linestep_reg;
	od_dma_oddma_disp_linestep_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Disp_LineStep_reg);
	od_dma_oddma_disp_linestep_reg.disp_line_step = 0x384; //900
	IoReg_Write32(OD_DMA_ODDMA_Disp_LineStep_reg, od_dma_oddma_disp_linestep_reg.regValue);

	// b802cebc Disp LineNum
	od_dma_oddma_display_linenum_RBUS od_dma_oddma_display_linenum_reg;
	od_dma_oddma_display_linenum_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Display_LineNum_reg);
	od_dma_oddma_display_linenum_reg.disp_line_number = height;
	IoReg_Write32(OD_DMA_ODDMA_Display_LineNum_reg, od_dma_oddma_display_linenum_reg.regValue);

	// b802cde0 b802cde4 b802ced4 b802ced8 start address
	// 1 & 2 pixel mode both need these setting
	
	printk("\n [Tcon][OD]memory_address1 = 0x%x, memory_address2 = 0x%x, od_size =  0x%x, memory_size = 0x%x, burst = 0x%x \n",memory_address1,memory_address2,od_size,memory_size,burst);
	IoReg_Write32(OD_DMA_ODDMA_Cap_BoundaryAddr1_reg, memory_address2 + memory_size - burst);
	IoReg_Write32(OD_DMA_ODDMA_Cap_BoundaryAddr2_reg, memory_address1);
	IoReg_Write32(OD_DMA_ODDMA_Cap_L1_Start_reg, memory_address1 + burst);
	IoReg_Write32(OD_DMA_ODDMA_Cap_L2_Start_reg, memory_address2);
	IoReg_Write32(OD_DMA_ODDMA_Disp_Start_addr_L1_reg, memory_address1 + burst);
	IoReg_Write32(OD_DMA_ODDMA_Disp_Start_addr_L2_reg, memory_address2);
	#if 0 /* henry @ mac5 161215 */
	// for 2 pixel mode
	if (mode == 2)
	{
		IoReg_Write32(OD_DMA_ODDMA_Cap1_L1_Start_reg, memory_address1 + memory_size - burst);
		IoReg_Write32(OD_DMA_ODDMA_Cap1_L2_Start_reg, memory_address2 + memory_size - burst);
		IoReg_Write32(OD_DMA_ODDMA_Disp1_Start_addr_L1_reg, memory_address1 + memory_size - burst);
		IoReg_Write32(OD_DMA_ODDMA_Disp1_Start_addr_L2_reg, memory_address2 + memory_size - burst);
	}
	#endif

	// b802cdbc b802ce80 cap disp enable
	od_dma_oddma_cap_ctl0_RBUS cap_ctl0_reg;
	cap_ctl0_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Cap_CTL0_reg);
	cap_ctl0_reg.comp_de_comp_bypass = 0;
	cap_ctl0_reg.cap_en = 1;
	IoReg_Write32(OD_DMA_ODDMA_Cap_CTL0_reg, cap_ctl0_reg.regValue);

	od_dma_oddma_display_ctrl_RBUS od_dma_oddma_display_ctrl_reg;
	od_dma_oddma_display_ctrl_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Display_CTRL_reg);
	od_dma_oddma_display_ctrl_reg.disp_3ddma_en = 1;
	IoReg_Write32(OD_DMA_ODDMA_Display_CTRL_reg, od_dma_oddma_display_ctrl_reg.regValue);

	// henry 161114 avoid High frequency distortion
	// using PQDC compensation to make cur pre diff smaller
	od_od_ctrl1_RBUS od_ctrl1_reg;
	od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
//	od_ctrl1_reg.ori_cur_sel= 1; /* henry @ mac5 161215 */
	IoReg_Write32(OD_OD_CTRL1_reg, od_ctrl1_reg.regValue);
	od_dma_oddma_pq_decmp_compensation_RBUS od_dma_oddma_pq_decmp_compensation_reg;
	od_dma_oddma_pq_decmp_compensation_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg);
	od_dma_oddma_pq_decmp_compensation_reg.tr_en = 1;
	IoReg_Write32(OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg, od_dma_oddma_pq_decmp_compensation_reg.regValue);
	// end henry

	VIPprintf("[OD] Gibi_od.cpp::drvif_color_od_pqc() finished...\n");

	return true;
}

// OD IP enable
void drvif_color_od(unsigned char bOD)
{
	od_od_ctrl_RBUS od_ctrl_reg;
	od_od_ctrl1_RBUS od_ctrl1_reg;
	od_od_noise_reduction_ctrl_RBUS noise_reduction_ctrl_reg;


	od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
	od_ctrl1_reg.od_delta_gain = 64-4;
	IoReg_Write32(OD_OD_CTRL1_reg, od_ctrl1_reg.regValue);


	od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
	if (bOD == 0) {
		od_ctrl_reg.od_fun_sel = 0;
		od_ctrl_reg.od_en = 0;
	} else {
		od_ctrl_reg.od_fun_sel = 1;
		od_ctrl_reg.od_en = 1;
	}
	IoReg_Write32(OD_OD_CTRL_reg, od_ctrl_reg.regValue);

	/* default nr*/
	noise_reduction_ctrl_reg.regValue = IoReg_Read32(OD_od_Noise_reduction_ctrl_reg);
	noise_reduction_ctrl_reg.od_nr_mode = 1;
	noise_reduction_ctrl_reg.od_b_nr_en = 1;
	noise_reduction_ctrl_reg.od_g_nr_en = 1;
	noise_reduction_ctrl_reg.od_r_nr_en = 1;
	noise_reduction_ctrl_reg.od_b_nr_thd = 3;
	noise_reduction_ctrl_reg.od_g_nr_thd = 3;
	noise_reduction_ctrl_reg.od_r_nr_thd = 3;
	IoReg_Write32(OD_od_Noise_reduction_ctrl_reg, noise_reduction_ctrl_reg.regValue);
}

void drvif_color_od_Ymode(unsigned char bEn)
{
	/* default y mode and y mode bias*/
	// 170308 henry Mac5p
	od_ymode_ctrl_RBUS od_ymode_ctrl_reg;
	od_ymode_ctrl_reg.regValue = IoReg_Read32(OD_YMODE_CTRL_reg);
	if(bEn == 1)
		od_ymode_ctrl_reg.od_ymode_en = 1;
	else
		od_ymode_ctrl_reg.od_ymode_en = 0;
	od_ymode_ctrl_reg.od_ymode_sat_en = 0;
	od_ymode_ctrl_reg.r_coeff = 0x4D;
	od_ymode_ctrl_reg.g_coeff = 0x96;
	od_ymode_ctrl_reg.b_coeff = 0x1D;
	IoReg_Write32(OD_YMODE_CTRL_reg, od_ymode_ctrl_reg.regValue);

	od_ymode_sat_RBUS od_ymode_sat_reg;
	od_ymode_sat_reg.regValue = IoReg_Read32(OD_YMODE_SAT_reg);
	od_ymode_sat_reg.sat_r_en = 0;
	od_ymode_sat_reg.sat_g_en = 0;
	od_ymode_sat_reg.sat_b_en = 0;
	od_ymode_sat_reg.sat_y_diff_neg_en = 0;
	od_ymode_sat_reg.sat_y_diff_pos_en = 0;
	od_ymode_sat_reg.sat_r_diff_th = 0xA;
	od_ymode_sat_reg.sat_g_diff_th = 0xA;
	od_ymode_sat_reg.sat_b_diff_th = 0xA;
	od_ymode_sat_reg.sat_offset_gain = 0x3;
	od_ymode_sat_reg.sat_offset_clamp_en = 1;
	IoReg_Write32(OD_YMODE_SAT_reg, od_ymode_sat_reg.regValue);

	od_ymode_sat_y_r_RBUS od_ymode_sat_y_r_reg;
	od_ymode_sat_y_r_reg.regValue = IoReg_Read32(OD_YMODE_SAT_Y_R_reg);
	od_ymode_sat_y_r_reg.y_diff_lo_th_r = 0x30;
	od_ymode_sat_y_r_reg.y_diff_hi_th_r = 0x50;
	od_ymode_sat_y_r_reg.offset_lo_th_r = 0x0;
	od_ymode_sat_y_r_reg.offset_hi_th_r = 0x3F;
	IoReg_Write32(OD_YMODE_SAT_Y_R_reg, od_ymode_sat_y_r_reg.regValue);

	od_ymode_sat_y_g_RBUS od_ymode_sat_y_g_reg;
	od_ymode_sat_y_g_reg.regValue = IoReg_Read32(OD_YMODE_SAT_Y_G_reg);
	od_ymode_sat_y_g_reg.y_diff_lo_th_g = 0x30;
	od_ymode_sat_y_g_reg.y_diff_hi_th_g = 0x50;
	od_ymode_sat_y_g_reg.offset_lo_th_g = 0x0;
	od_ymode_sat_y_g_reg.offset_hi_th_g = 0x3F;
	IoReg_Write32(OD_YMODE_SAT_Y_G_reg, od_ymode_sat_y_g_reg.regValue);

	od_ymode_sat_y_b_RBUS od_ymode_sat_y_b_reg;
	od_ymode_sat_y_b_reg.regValue = IoReg_Read32(OD_YMODE_SAT_Y_B_reg);
	od_ymode_sat_y_b_reg.y_diff_lo_th_b = 0x30;
	od_ymode_sat_y_b_reg.y_diff_hi_th_b = 0x50;
	od_ymode_sat_y_b_reg.offset_lo_th_b = 0x0;
	od_ymode_sat_y_b_reg.offset_hi_th_b = 0x3F;
	IoReg_Write32(OD_YMODE_SAT_Y_B_reg, od_ymode_sat_y_b_reg.regValue);

	od_ymode_sat_y_slope_RBUS od_ymode_sat_y_slope_reg;
	od_ymode_sat_y_slope_2_RBUS od_ymode_sat_y_slope_2_reg;
	od_ymode_sat_y_slope_reg.regValue = IoReg_Read32(OD_YMODE_SAT_Y_SLOPE_reg);
	od_ymode_sat_y_slope_2_reg.regValue = IoReg_Read32(OD_YMODE_SAT_Y_SLOPE_2_reg);
	od_ymode_sat_y_slope_reg.offset_slope_r=(od_ymode_sat_y_r_reg.y_diff_hi_th_r-od_ymode_sat_y_r_reg.y_diff_lo_th_r)*256/(od_ymode_sat_y_r_reg.offset_hi_th_r-od_ymode_sat_y_r_reg.offset_lo_th_r);
	od_ymode_sat_y_slope_reg.offset_slope_g=(od_ymode_sat_y_g_reg.y_diff_hi_th_g-od_ymode_sat_y_g_reg.y_diff_lo_th_g)*256/(od_ymode_sat_y_g_reg.offset_hi_th_g-od_ymode_sat_y_g_reg.offset_lo_th_g);
	od_ymode_sat_y_slope_2_reg.offset_slope_b=(od_ymode_sat_y_b_reg.y_diff_hi_th_b-od_ymode_sat_y_b_reg.y_diff_lo_th_b)*256/(od_ymode_sat_y_b_reg.offset_hi_th_b-od_ymode_sat_y_b_reg.offset_lo_th_b);
	IoReg_Write32(OD_YMODE_SAT_Y_SLOPE_reg, od_ymode_sat_y_slope_reg.regValue);
	IoReg_Write32(OD_YMODE_SAT_Y_SLOPE_2_reg, od_ymode_sat_y_slope_2_reg.regValue);
}

void drvif_color_LGD_Dither()
{
	lgd_dither_lgd_dither_ctrl_RBUS lgd_dither_lgd_dither_ctrl_reg;
	lgd_dither_lgd_dither_ctrl_reg.regValue = IoReg_Read32(LGD_DITHER_LGD_DITHER_CTRL_reg);
	lgd_dither_lgd_dither_ctrl_reg.lgd_dither_en = 1;
	IoReg_Write32(LGD_DITHER_LGD_DITHER_CTRL_reg, lgd_dither_lgd_dither_ctrl_reg.regValue);
}

// henry 170309
void drvif_color_od_table_seperate(unsigned int *pODtable, unsigned char tableType)
{
	int i, count = 30;
	od_od_lut_addr_RBUS lut_addr_reg;

	lut_addr_reg.regValue = IoReg_Read32(OD_OD_LUT_ADDR_reg);
	lut_addr_reg.table_type = tableType;
	lut_addr_reg.od_lut_ax_en = 1;
//	lut_addr_reg.od_lut_index = 0; // Mac5 no LUT index
	lut_addr_reg.od_lut_ax_mode = 0;
	lut_addr_reg.od_lut_adr_mode = 0; //col(cur) indexfirst
	lut_addr_reg.od_lut_column_addr = 0;
	lut_addr_reg.od_lut_row_addr = 0;
	IoReg_Write32(OD_OD_LUT_ADDR_reg, lut_addr_reg.regValue);

	for (i = 0; i < OD_table_length; i++) {
		IoReg_Write32(OD_OD_LUT_DATA_reg, *(pODtable+i));
	}
	IoReg_ClearBits(OD_OD_LUT_ADDR_reg, _BIT16);
}

unsigned int od_table_transformed[OD_table_length];
void drvif_color_od_table_seperate_write(unsigned int *pODtable, unsigned char tableType, char channel)
{
	int i;
	od_od_lut_addr_RBUS lut_addr_reg;

	lut_addr_reg.regValue = IoReg_Read32(OD_OD_LUT_ADDR_reg);
	lut_addr_reg.table_type = tableType;
	lut_addr_reg.od_lut_sel = channel;
	lut_addr_reg.od_lut_ax_en = 1;
//	lut_addr_reg.od_lut_index = 0; // Mac5 no LUT index
	lut_addr_reg.od_lut_ax_mode = 0;
	lut_addr_reg.od_lut_adr_mode = 0; //col(cur) indexfirst
	lut_addr_reg.od_lut_column_addr = 0;
	lut_addr_reg.od_lut_row_addr = 0;
	IoReg_Write32(OD_OD_LUT_ADDR_reg, lut_addr_reg.regValue);

	for (i = 0; i < OD_table_length; i++)
		od_table_transformed[i] = *(pODtable+i);

	for (i = 0; i < OD_table_length; i++) {
		IoReg_Write32(OD_OD_LUT_DATA_reg, od_table_transformed[i]);
		
		//rtd_printk(KERN_EMERG, TAG_NAME, "drvif_color_od_table_seperate_write, od_do_resume = %d\n", *(pODtable+i));
	}
	IoReg_ClearBits(OD_OD_LUT_ADDR_reg, _BIT16);
}

void drvif_color_od_table_read(unsigned char *pODtable)
{
    int i;
	od_od_lut_addr_RBUS lut_addr_reg;
	lut_addr_reg.regValue = IoReg_Read32(OD_OD_LUT_ADDR_reg);
	lut_addr_reg.od_lut_row_addr = 0;
	lut_addr_reg.od_lut_column_addr = 0;
	lut_addr_reg.od_lut_ax_en = 1; // auto rolling index
	lut_addr_reg.od_lut_adr_mode = 0; //cur index first
	IoReg_Write32(OD_OD_LUT_ADDR_reg, lut_addr_reg.regValue);

	// target table
	if(lut_addr_reg.table_type)
	{
		for (i = 0; i < OD_table_length; i++){
			RBus_UInt32 regValue_tmp = IoReg_Read32(OD_OD_LUT_DATA_reg);
			// 33 to 17 table
			//*(pODtable+i) = ( regValue_tmp >> 24);

			/* henry mac5p OD table only 17x17 */
			*(pODtable+i) = regValue_tmp;
		}
	}
	// delta table
	else
	{
		unsigned int ODtable_tmp[OD_table_length];
		char ODtable_sign[OD_table_length];

		for (i = 0; i < OD_table_length; i++) {
			ODtable_tmp[i] = IoReg_Read32(OD_OD_LUT_DATA_reg);

			unsigned char quot = i/17, remain = i%17;

			// 33 to 17 table
			//ODtable_sign[i] = (char)(ODtable_tmp[i] >> 24);

			/* henry mac5p OD table only 17x17 */
			ODtable_sign[i] = (char)(ODtable_tmp[i]);

			// add cur pixel value (to target table)
			if(remain != 16)
				*(pODtable+i) = ODtable_sign[i] + 16 * remain;
			else
				*(pODtable+i) = ODtable_sign[i] + 255;

		}

	}
	IoReg_ClearBits(OD_OD_LUT_ADDR_reg, _BIT16);
}
// end henry

void drvif_color_od_table_seperate_read(unsigned char *pODtable, unsigned char channel)
{
    int i;
	od_od_lut_addr_RBUS lut_addr_reg;
	lut_addr_reg.regValue = IoReg_Read32(OD_OD_LUT_ADDR_reg);
	lut_addr_reg.od_lut_row_addr = 0;
	lut_addr_reg.table_type = 0;
	lut_addr_reg.od_lut_sel = channel;
	lut_addr_reg.od_lut_column_addr = 0;
	lut_addr_reg.od_lut_ax_en = 1; // auto rolling index
	lut_addr_reg.od_lut_adr_mode = 0; //cur index first
	IoReg_Write32(OD_OD_LUT_ADDR_reg, lut_addr_reg.regValue);

	// target table
	if(lut_addr_reg.table_type)
	{
		for (i = 0; i < OD_table_length; i++){
			RBus_UInt32 regValue_tmp = IoReg_Read32(OD_OD_LUT_DATA_reg);
			// 33 to 17 table
			//*(pODtable+i) = ( regValue_tmp >> 24);

			/* henry mac5p OD table only 17x17 */
			*(pODtable+i) = regValue_tmp;
		}
	}
	// delta table
	else
	{
		unsigned int ODtable_tmp[OD_table_length];
		char ODtable_sign[OD_table_length];

		for (i = 0; i < OD_table_length; i++) {
			ODtable_tmp[i] = IoReg_Read32(OD_OD_LUT_DATA_reg);

			unsigned char quot = i/17, remain = i%17;

			// 33 to 17 table
			//ODtable_sign[i] = (char)(ODtable_tmp[i] >> 24);

			/* henry mac5p OD table only 17x17 */
			ODtable_sign[i] = (char)(ODtable_tmp[i]);

			// add cur pixel value (to target table)
			if(remain != 16)
				*(pODtable+i) = ODtable_sign[i] + 16 * remain;
			else
				*(pODtable+i) = ODtable_sign[i] + 255;

		}

	}
	IoReg_ClearBits(OD_OD_LUT_ADDR_reg, _BIT16);
}

void drvif_color_od_table(unsigned int *pODtable, unsigned char targetmode)
{
	int i, count = 30;
	od_od_lut_addr_RBUS lut_addr_reg;

	// henry @ Merlin2 write table, disable pod
	// Mac5 differ sram
	//ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
	//struct timespec timeout;
	//timeout = ns_to_timespec(1000 * 1000);

	//drvif_color_pcid_enable(0);
	//drvif_color_pcid2_enable(0);

	//display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	//while((display_timing_ctrl2_reg.pcid2_en || display_timing_ctrl2_reg.pcid_en) && count-- > 0)
	//{
	//	hrtimer_nanosleep(&timeout, NULL, HRTIMER_MODE_REL, CLOCK_MONOTONIC);
	//	display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	//}
	// end henry

	lut_addr_reg.regValue = IoReg_Read32(OD_OD_LUT_ADDR_reg);
	lut_addr_reg.table_type = targetmode;
	lut_addr_reg.od_lut_sel = 3;
	lut_addr_reg.od_lut_ax_en = 1;
//	lut_addr_reg.od_lut_index = 0; // Mac5 no lut select
	lut_addr_reg.od_lut_ax_mode = 0;
	lut_addr_reg.od_lut_adr_mode = 0; //col(cur) indexfirst
	//lut_addr_reg.od_lut_adr_mode = 1; //row(pre) indexfirst
	lut_addr_reg.od_lut_column_addr = 0;
	lut_addr_reg.od_lut_row_addr = 0;
	IoReg_Write32(OD_OD_LUT_ADDR_reg, lut_addr_reg.regValue);

	for (i = 0; i < OD_table_length; i++) {
		IoReg_Write32(OD_OD_LUT_DATA_reg, *(pODtable+i));
	}

	/*	IoReg_Write32(0xb802ca08, 0x00043000);  */ /* disable table access*/
	IoReg_ClearBits(OD_OD_LUT_ADDR_reg, _BIT16);
}

void drvif_color_od_gain(unsigned char ucGain)
{
	od_od_ctrl1_RBUS od_ctrl1_reg;

	if (ucGain > 127)
		ucGain = 127;

	od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
	od_ctrl1_reg.od_delta_gain = ucGain;

	IoReg_Write32(OD_OD_CTRL1_reg, od_ctrl1_reg.regValue);
}

unsigned char drvif_color_get_od_gain(void)
{
	od_od_ctrl1_RBUS od_ctrl1_reg;
	od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
	return od_ctrl1_reg.od_delta_gain ;
}

void drvif_color_pcid_enable(unsigned char bpcid)
{
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
	display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	display_timing_ctrl2_reg.pcid_en = bpcid;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT8); // Set double buffer apply bit
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
}

/* new pcid by willy */
void drvif_color_pcid_valuetable(unsigned int *pPcidtable)
{
	if (!pPcidtable)
	{
		VIPprintf("[Error][%s][%s] Table Ptr is null!\n", __FILE__, __func__);
		return;
	}

	// Enable and setup the table access
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT10); // disable DTG double buffer
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
	display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	display_timing_ctrl2_reg.pcid_en = 1;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT10); // enable DTG double buffer
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/

	// Write table setting
	pcid_pcid_lut_addr_RBUS lut_addr_reg;
	lut_addr_reg.regValue = IoReg_Read32(PCID_PCID_LUT_ADDR_reg);
	lut_addr_reg.pcid_lut_sel = 3;			/* all channels */
	lut_addr_reg.pcid_lut_adr_mode = 0;		/* Increase Current (column) Index first */
	lut_addr_reg.pcid_lut_ax_en = 1;		/* access en */
	lut_addr_reg.pcid_lut_row_addr = 0;		/* PCID only uses table 1 */
	lut_addr_reg.pcid_lut_column_addr = 0;	/* PCID only uses table 1 */
	IoReg_Write32(PCID_PCID_LUT_ADDR_reg, lut_addr_reg.regValue);

	// Write the value into table
	pcid_pcid_lut_data_RBUS lut_data_reg;
	int i=0;
	for(i=0; i<81; i++)
	{
		lut_data_reg.pcid_lut_data = pPcidtable[i];
		IoReg_Write32(PCID_PCID_LUT_DATA_reg, lut_data_reg.regValue);
	}

	// Disable the table access
	lut_addr_reg.regValue = IoReg_Read32(PCID_PCID_LUT_ADDR_reg);
	lut_addr_reg.pcid_lut_ax_en = 0;
	IoReg_Write32(PCID_PCID_LUT_ADDR_reg, lut_addr_reg.regValue);

	// Disable the PCID enable
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT10); // disable DTG double buffer
	display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
	display_timing_ctrl2_reg.pcid_en = 0;
	IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);
	IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT10); // enable DTG double buffer
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/

}

void drvif_color_pcid_pixel_setting(DRV_pcid_data_t* pPcidSetting)
{
	pcid_pcid_ctrl_RBUS pcid_pcid_ctrl_reg;
	pcid_pcid_ctrl_reg.regValue = IoReg_Read32(PCID_PCID_CTRL_reg);
	pcid_pcid_ctrl_2_RBUS pcid_pcid_ctrl_2_reg;
	pcid_pcid_ctrl_2_reg.regValue = IoReg_Read32(PCID_PCID_CTRL_2_reg);
	pcid_pcid_line_1_RBUS pcid_pcid_line_1_reg;
	pcid_pcid_line_1_reg.regValue = IoReg_Read32(PCID_PCID_LINE_1_reg);
	pcid_pcid_line_2_RBUS pcid_pcid_line_2_reg;
	pcid_pcid_line_2_reg.regValue = IoReg_Read32(PCID_PCID_LINE_2_reg);
	pcid_pcid_line_3_RBUS pcid_pcid_line_3_reg;
	pcid_pcid_line_3_reg.regValue = IoReg_Read32(PCID_PCID_LINE_3_reg);
	pcid_pcid_line_4_RBUS pcid_pcid_line_4_reg;
	pcid_pcid_line_4_reg.regValue = IoReg_Read32(PCID_PCID_LINE_4_reg);

	pcid_pcid_ctrl_reg.boundary_mode = pPcidSetting->boundary_mode;
	pcid_pcid_ctrl_reg.lsb_add_en = pPcidSetting->lsb_add_en;
	pcid_pcid_ctrl_reg.lsb_add_nr_en = pPcidSetting->lsb_add_nr_en;
	pcid_pcid_ctrl_reg.lsb_add_nr_thd = pPcidSetting->lsb_add_nr_thd;
	pcid_pcid_ctrl_reg.lsb_add_slope_check_en = pPcidSetting->lsb_add_slope_check_en;
	pcid_pcid_ctrl_reg.ref_4line = pPcidSetting->ref_4line;

	pcid_pcid_ctrl_2_reg.pcid_tab1_b_thd = pPcidSetting->pcid_tbl1_b_th;
	pcid_pcid_ctrl_2_reg.pcid_tab1_g_thd = pPcidSetting->pcid_tbl1_g_th;
	pcid_pcid_ctrl_2_reg.pcid_tab1_r_thd = pPcidSetting->pcid_tbl1_r_th;
	pcid_pcid_ctrl_2_reg.pcid_tab1_xtr_en = pPcidSetting->xtr_tbl1_en;
	pcid_pcid_ctrl_2_reg.pcid_thd_en = pPcidSetting->pcid_thd_en;
	pcid_pcid_ctrl_2_reg.pcid_thd_mode = pPcidSetting->pcid_thd_mode;

	// line 1 pixel reference setting
	pcid_pcid_line_1_reg.line1_even_r_line_select  = pPcidSetting->pixel_ref.line1_even_r.line_sel;
	pcid_pcid_line_1_reg.line1_even_r_point_select = pPcidSetting->pixel_ref.line1_even_r.point_sel;
	pcid_pcid_line_1_reg.line1_even_r_color_select = pPcidSetting->pixel_ref.line1_even_r.color_sel;
	pcid_pcid_line_1_reg.line1_even_g_line_select  = pPcidSetting->pixel_ref.line1_even_g.line_sel;
	pcid_pcid_line_1_reg.line1_even_g_point_select = pPcidSetting->pixel_ref.line1_even_g.point_sel;
	pcid_pcid_line_1_reg.line1_even_g_color_select = pPcidSetting->pixel_ref.line1_even_g.color_sel;
	pcid_pcid_line_1_reg.line1_even_b_line_select  = pPcidSetting->pixel_ref.line1_even_b.line_sel;
	pcid_pcid_line_1_reg.line1_even_b_point_select = pPcidSetting->pixel_ref.line1_even_b.point_sel;
	pcid_pcid_line_1_reg.line1_even_b_color_select = pPcidSetting->pixel_ref.line1_even_b.color_sel;

	pcid_pcid_line_1_reg.line1_odd_r_line_select  = pPcidSetting->pixel_ref.line1_odd_r.line_sel;
	pcid_pcid_line_1_reg.line1_odd_r_point_select = pPcidSetting->pixel_ref.line1_odd_r.point_sel;
	pcid_pcid_line_1_reg.line1_odd_r_color_select = pPcidSetting->pixel_ref.line1_odd_r.color_sel;
	pcid_pcid_line_1_reg.line1_odd_g_line_select  = pPcidSetting->pixel_ref.line1_odd_g.line_sel;
	pcid_pcid_line_1_reg.line1_odd_g_point_select = pPcidSetting->pixel_ref.line1_odd_g.point_sel;
	pcid_pcid_line_1_reg.line1_odd_g_color_select = pPcidSetting->pixel_ref.line1_odd_g.color_sel;
	pcid_pcid_line_1_reg.line1_odd_b_line_select  = pPcidSetting->pixel_ref.line1_odd_b.line_sel;
	pcid_pcid_line_1_reg.line1_odd_b_point_select = pPcidSetting->pixel_ref.line1_odd_b.point_sel;
	pcid_pcid_line_1_reg.line1_odd_b_color_select = pPcidSetting->pixel_ref.line1_odd_b.color_sel;

	// line 2 pixel reference setting
	pcid_pcid_line_2_reg.line2_even_r_line_select  = pPcidSetting->pixel_ref.line2_even_r.line_sel;
	pcid_pcid_line_2_reg.line2_even_r_point_select = pPcidSetting->pixel_ref.line2_even_r.point_sel;
	pcid_pcid_line_2_reg.line2_even_r_color_select = pPcidSetting->pixel_ref.line2_even_r.color_sel;
	pcid_pcid_line_2_reg.line2_even_g_line_select  = pPcidSetting->pixel_ref.line2_even_g.line_sel;
	pcid_pcid_line_2_reg.line2_even_g_point_select = pPcidSetting->pixel_ref.line2_even_g.point_sel;
	pcid_pcid_line_2_reg.line2_even_g_color_select = pPcidSetting->pixel_ref.line2_even_g.color_sel;
	pcid_pcid_line_2_reg.line2_even_b_line_select  = pPcidSetting->pixel_ref.line2_even_b.line_sel;
	pcid_pcid_line_2_reg.line2_even_b_point_select = pPcidSetting->pixel_ref.line2_even_b.point_sel;
	pcid_pcid_line_2_reg.line2_even_b_color_select = pPcidSetting->pixel_ref.line2_even_b.color_sel;

	pcid_pcid_line_2_reg.line2_odd_r_line_select  = pPcidSetting->pixel_ref.line2_odd_r.line_sel;
	pcid_pcid_line_2_reg.line2_odd_r_point_select = pPcidSetting->pixel_ref.line2_odd_r.point_sel;
	pcid_pcid_line_2_reg.line2_odd_r_color_select = pPcidSetting->pixel_ref.line2_odd_r.color_sel;
	pcid_pcid_line_2_reg.line2_odd_g_line_select  = pPcidSetting->pixel_ref.line2_odd_g.line_sel;
	pcid_pcid_line_2_reg.line2_odd_g_point_select = pPcidSetting->pixel_ref.line2_odd_g.point_sel;
	pcid_pcid_line_2_reg.line2_odd_g_color_select = pPcidSetting->pixel_ref.line2_odd_g.color_sel;
	pcid_pcid_line_2_reg.line2_odd_b_line_select  = pPcidSetting->pixel_ref.line2_odd_b.line_sel;
	pcid_pcid_line_2_reg.line2_odd_b_point_select = pPcidSetting->pixel_ref.line2_odd_b.point_sel;
	pcid_pcid_line_2_reg.line2_odd_b_color_select = pPcidSetting->pixel_ref.line2_odd_b.color_sel;

	// line 3 pixel reference setting
	pcid_pcid_line_3_reg.line3_even_r_line_select  = pPcidSetting->pixel_ref.line3_even_r.line_sel;
	pcid_pcid_line_3_reg.line3_even_r_point_select = pPcidSetting->pixel_ref.line3_even_r.point_sel;
	pcid_pcid_line_3_reg.line3_even_r_color_select = pPcidSetting->pixel_ref.line3_even_r.color_sel;
	pcid_pcid_line_3_reg.line3_even_g_line_select  = pPcidSetting->pixel_ref.line3_even_g.line_sel;
	pcid_pcid_line_3_reg.line3_even_g_point_select = pPcidSetting->pixel_ref.line3_even_g.point_sel;
	pcid_pcid_line_3_reg.line3_even_g_color_select = pPcidSetting->pixel_ref.line3_even_g.color_sel;
	pcid_pcid_line_3_reg.line3_even_b_line_select  = pPcidSetting->pixel_ref.line3_even_b.line_sel;
	pcid_pcid_line_3_reg.line3_even_b_point_select = pPcidSetting->pixel_ref.line3_even_b.point_sel;
	pcid_pcid_line_3_reg.line3_even_b_color_select = pPcidSetting->pixel_ref.line3_even_b.color_sel;

	pcid_pcid_line_3_reg.line3_odd_r_line_select  = pPcidSetting->pixel_ref.line3_odd_r.line_sel;
	pcid_pcid_line_3_reg.line3_odd_r_point_select = pPcidSetting->pixel_ref.line3_odd_r.point_sel;
	pcid_pcid_line_3_reg.line3_odd_r_color_select = pPcidSetting->pixel_ref.line3_odd_r.color_sel;
	pcid_pcid_line_3_reg.line3_odd_g_line_select  = pPcidSetting->pixel_ref.line3_odd_g.line_sel;
	pcid_pcid_line_3_reg.line3_odd_g_point_select = pPcidSetting->pixel_ref.line3_odd_g.point_sel;
	pcid_pcid_line_3_reg.line3_odd_g_color_select = pPcidSetting->pixel_ref.line3_odd_g.color_sel;
	pcid_pcid_line_3_reg.line3_odd_b_line_select  = pPcidSetting->pixel_ref.line3_odd_b.line_sel;
	pcid_pcid_line_3_reg.line3_odd_b_point_select = pPcidSetting->pixel_ref.line3_odd_b.point_sel;
	pcid_pcid_line_3_reg.line3_odd_b_color_select = pPcidSetting->pixel_ref.line3_odd_b.color_sel;

	// line 4 pixel reference setting
	pcid_pcid_line_4_reg.line4_even_r_line_select  = pPcidSetting->pixel_ref.line4_even_r.line_sel;
	pcid_pcid_line_4_reg.line4_even_r_point_select = pPcidSetting->pixel_ref.line4_even_r.point_sel;
	pcid_pcid_line_4_reg.line4_even_r_color_select = pPcidSetting->pixel_ref.line4_even_r.color_sel;
	pcid_pcid_line_4_reg.line4_even_g_line_select  = pPcidSetting->pixel_ref.line4_even_g.line_sel;
	pcid_pcid_line_4_reg.line4_even_g_point_select = pPcidSetting->pixel_ref.line4_even_g.point_sel;
	pcid_pcid_line_4_reg.line4_even_g_color_select = pPcidSetting->pixel_ref.line4_even_g.color_sel;
	pcid_pcid_line_4_reg.line4_even_b_line_select  = pPcidSetting->pixel_ref.line4_even_b.line_sel;
	pcid_pcid_line_4_reg.line4_even_b_point_select = pPcidSetting->pixel_ref.line4_even_b.point_sel;
	pcid_pcid_line_4_reg.line4_even_b_color_select = pPcidSetting->pixel_ref.line4_even_b.color_sel;

	pcid_pcid_line_4_reg.line4_odd_r_line_select  = pPcidSetting->pixel_ref.line4_odd_r.line_sel;
	pcid_pcid_line_4_reg.line4_odd_r_point_select = pPcidSetting->pixel_ref.line4_odd_r.point_sel;
	pcid_pcid_line_4_reg.line4_odd_r_color_select = pPcidSetting->pixel_ref.line4_odd_r.color_sel;
	pcid_pcid_line_4_reg.line4_odd_g_line_select  = pPcidSetting->pixel_ref.line4_odd_g.line_sel;
	pcid_pcid_line_4_reg.line4_odd_g_point_select = pPcidSetting->pixel_ref.line4_odd_g.point_sel;
	pcid_pcid_line_4_reg.line4_odd_g_color_select = pPcidSetting->pixel_ref.line4_odd_g.color_sel;
	pcid_pcid_line_4_reg.line4_odd_b_line_select  = pPcidSetting->pixel_ref.line4_odd_b.line_sel;
	pcid_pcid_line_4_reg.line4_odd_b_point_select = pPcidSetting->pixel_ref.line4_odd_b.point_sel;
	pcid_pcid_line_4_reg.line4_odd_b_color_select = pPcidSetting->pixel_ref.line4_odd_b.color_sel;

	IoReg_Write32(PCID_PCID_CTRL_reg, pcid_pcid_ctrl_reg.regValue);
	IoReg_Write32(PCID_PCID_CTRL_2_reg, pcid_pcid_ctrl_2_reg.regValue);
	IoReg_Write32(PCID_PCID_LINE_1_reg, pcid_pcid_line_1_reg.regValue);
	IoReg_Write32(PCID_PCID_LINE_2_reg, pcid_pcid_line_2_reg.regValue);
	IoReg_Write32(PCID_PCID_LINE_3_reg, pcid_pcid_line_3_reg.regValue);
	IoReg_Write32(PCID_PCID_LINE_4_reg, pcid_pcid_line_4_reg.regValue);
}


#if 0
//unsigned char	*m_pODCacheStartAddr = NULL; //Allocate_VirAddr
unsigned int drvif_color_od_memory_alloc_block(unsigned int space, unsigned int *startAddr1, unsigned int *startAddr2)
{
//	unsigned int m_allocate_memory = 0;
	unsigned int space_total;

	space_total = space*2+CONFIG_MDOMAIN_BURST_SIZE;

#if 0
	m_pODCacheStartAddr = (unsigned char *)dvr_malloc_specific((space_total + (1 << 6)), GFP_DCU2_FIRST);
	if(m_pODCacheStartAddr == NULL){
		pr_notice("[ERROR]OD Allocate DCU1 size=%x fail\n",(space_total + (1 << 6)));
		BUG();//add kernel crash function when cma not enough
		return FALSE;
	}
	m_allocate_memory = (unsigned int)dvr_to_phys((void*)m_pODCacheStartAddr);
#endif
	*startAddr1 = drvif_memory_get_data_align(OD_START_ADDRESS_KERNEL, (1 << 5));
	*startAddr2 = drvif_memory_get_data_align((*startAddr1)+space, (1 << 5));

	return TRUE;
}
#endif
void drvif_color_safe_od_enable(unsigned char bEnable, unsigned char bOD_OnOff_Switch)
{
	UINT32 timeoutcnt = 0x032500;
	od_od_ctrl_RBUS od_ctrl_reg;

	// OD function db on
	IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_od_en_dbf_en_mask); //_BIT24
	// OD function db read sel: reg
	IoReg_ClearBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_read_level_mask); //_BIT25

	if (!bEnable) { // OD Disable
		if (bOD_OnOff_Switch) {
			// OD off
			IoReg_ClearBits(OD_OD_CTRL_reg, OD_OD_CTRL_od_en_mask|OD_OD_CTRL_od_fun_sel_mask); //_BIT0|_BIT1

			// OD function db apply
			IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_apply_mask); //_BIT26

			// wait vsync
			od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			while((od_ctrl_reg.regValue & 0x3) != 0 && timeoutcnt-- != 0) {
				od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			}
		}

		IoReg_Write32(OD_DMA_ODDMA_Cap_BoundaryAddr1_reg, IoReg_Read32(OD_DMA_ODDMA_Cap_BoundaryAddr2_reg));
	} else { // OD Enable
		od_od_ctrl1_RBUS od_ctrl1_reg;

		IoReg_Write32(OD_DMA_ODDMA_Cap_BoundaryAddr1_reg, IoReg_Read32(OD_DMA_ODDMA_Cap_L2_Start_reg)+0x800000-0x20);

		IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_apply_mask); //_BIT26
		od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
		while(od_ctrl1_reg.db_apply == 0x1 && timeoutcnt-- != 0) {
			od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
		}

		if (bOD_OnOff_Switch) {
			// OD on
			IoReg_SetBits(OD_OD_CTRL_reg, OD_OD_CTRL_od_en_mask|OD_OD_CTRL_od_fun_sel_mask); //_BIT0|_BIT1

			// OD function db apply
			IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_apply_mask); //_BIT26

			// wait vsync
			timeoutcnt = 0x032500;
			od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			while((od_ctrl_reg.regValue & 0x3) != 0x3 && timeoutcnt-- != 0) {
				od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			}
		}
	}

	// OD function db off
	IoReg_ClearBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_od_en_dbf_en_mask); //_BIT24
	// OD function db read sel: temp
	IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_read_level_mask); //_BIT25
}

void drvif_color_set_od_bits(unsigned char FrameLimitBit, unsigned char input_bit_sel)
{
	od_od_ctrl_RBUS od_ctrl_reg;
	od_dma_oddma_pq_cmp_bit_RBUS oddma_pq_cmp_bit_reg;
	od_dma_oddma_cap_ctl1_RBUS cap_ctl1_reg;

	UINT32 timeoutcnt = 0x032500;
	unsigned char od_dma_enable_status = 0;
	unsigned char od_enable_status = 0;

	od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
	od_enable_status = (od_ctrl_reg.regValue & 0x3)?1:0;
	od_dma_enable_status = drvif_color_get_od_dma_enable();

	if (FrameLimitBit > 0) {
		oddma_pq_cmp_bit_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_BIT_reg);
		oddma_pq_cmp_bit_reg.frame_limit_bit = FrameLimitBit;
		IoReg_Write32(OD_DMA_ODDMA_PQ_CMP_BIT_reg, oddma_pq_cmp_bit_reg.regValue);

		cap_ctl1_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Cap_CTL1_reg);
		cap_ctl1_reg.bit_sel = input_bit_sel; // cap_ctl1_reg.bit_sel: 3 - reserved, 2 -10bits, 1 - 8 bits, 0 - 6 bits
		IoReg_Write32(OD_DMA_ODDMA_Cap_CTL1_reg, cap_ctl1_reg.regValue);

		drvif_color_set_od_dma_enable(1);

		if (!od_enable_status) {
			od_od_ctrl1_RBUS od_ctrl1_reg;

			// OD function db on
			IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_od_en_dbf_en_mask); //_BIT24
			// OD function db read sel: reg
			IoReg_ClearBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_read_level_mask); //_BIT25

			IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_apply_mask); //_BIT26

			if (!od_dma_enable_status) {
				od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
				while(od_ctrl1_reg.db_apply == 0x1 && timeoutcnt-- != 0) {
					od_ctrl1_reg.regValue = IoReg_Read32(OD_OD_CTRL1_reg);
				}
			}

			// OD on
			//IoReg_SetBits(OD_OD_CTRL_reg, OD_OD_CTRL_od_en_mask|OD_OD_CTRL_od_fun_sel_mask); //_BIT0|_BIT1
			drvif_color_od(1);

			// OD function db apply
			IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_apply_mask); //_BIT26

			// wait vsync
			timeoutcnt = 0x032500;
			od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			while((od_ctrl_reg.regValue & 0x3) != 0x3 && timeoutcnt-- != 0) {
				od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			}
		}
	} else {
		if (od_enable_status) {
			// OD function db on
			IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_od_en_dbf_en_mask); //_BIT24
			// OD function db read sel: reg
			IoReg_ClearBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_read_level_mask); //_BIT25

			IoReg_ClearBits(OD_OD_CTRL_reg, OD_OD_CTRL_od_en_mask|OD_OD_CTRL_od_fun_sel_mask); //_BIT0|_BIT1
			IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_apply_mask); //_BIT26
			od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			while((od_ctrl_reg.regValue & 0x3) != 0 && timeoutcnt-- != 0) {
				od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
			}
		}

		drvif_color_set_od_dma_enable(0);
	}

	// OD function db off
	IoReg_ClearBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_od_en_dbf_en_mask); //_BIT24
	// OD function db read sel: temp
	IoReg_SetBits(OD_OD_CTRL1_reg, OD_OD_CTRL1_db_read_level_mask); //_BIT25
}

unsigned char drvif_color_get_od_bits(void)
{
	od_dma_oddma_pq_cmp_bit_RBUS oddma_pq_cmp_bit_reg;
	oddma_pq_cmp_bit_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_PQ_CMP_BIT_reg);

	return oddma_pq_cmp_bit_reg.frame_limit_bit;
}

unsigned char drvif_color_get_od_en(void)
{
	od_od_ctrl_RBUS od_ctrl_reg;
	od_ctrl_reg.regValue = IoReg_Read32(OD_OD_CTRL_reg);
	return od_ctrl_reg.od_en;
}

unsigned char drvif_color_set_od_dma_enable(unsigned char enable)
{
	od_dma_oddma_cap_ctl0_RBUS cap_ctl0_reg;
	od_dma_oddma_display_ctrl_RBUS od_dma_oddma_display_ctrl_reg;

	if (!enable && drvif_color_get_od_en())
		drvif_color_od(0);

	cap_ctl0_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Cap_CTL0_reg);
	cap_ctl0_reg.cap_en = enable;
	IoReg_Write32(OD_DMA_ODDMA_Cap_CTL0_reg, cap_ctl0_reg.regValue);

	od_dma_oddma_display_ctrl_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Display_CTRL_reg);
	od_dma_oddma_display_ctrl_reg.disp_3ddma_en = enable;
	IoReg_Write32(OD_DMA_ODDMA_Display_CTRL_reg, od_dma_oddma_display_ctrl_reg.regValue);

	return TRUE;
}

unsigned char drvif_color_get_od_dma_enable(void)
{
	od_dma_oddma_cap_ctl0_RBUS cap_ctl0_reg;
	od_dma_oddma_display_ctrl_RBUS od_dma_oddma_display_ctrl_reg;

	cap_ctl0_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Cap_CTL0_reg);
	od_dma_oddma_display_ctrl_reg.regValue = IoReg_Read32(OD_DMA_ODDMA_Display_CTRL_reg);

	if (cap_ctl0_reg.cap_en && od_dma_oddma_display_ctrl_reg.disp_3ddma_en)
		return TRUE;
	else
		return FALSE;
}

