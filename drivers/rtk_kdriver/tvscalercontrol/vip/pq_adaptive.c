/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/
#if CONFIG_FIRMWARE_IN_KERNEL
/* some include about VIP Driver*/
#include <tvscalercontrol/vip/pq_adaptive.h>
#include <tvscalercontrol/vip/scalerColor.h>

/* some include about io*/
#include <tvscalercontrol/io/ioregdrv.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"
#else
// some include about VIP Driver
#include <Platform_Lib/TVScalerControl/vip/pq_adaptive.h>
#include <Platform_Lib/TVScalerControl/vip/scalerColor.h>

  // some include about io
//#include "Platform_Lib/TVScalerControl/io/ioRegDrv.h"
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif

/*=======================*/
UINT32 andMASK_Table1[32] =	{
							0xfffffffe, 0xfffffffc, 0xfffffff8, 0xfffffff0,
							0xffffffe0, 0xffffffc0, 0xffffff80, 0xffffff00,
							0xfffffe00, 0xfffffc00, 0xfffff800, 0xfffff000,
							0xffffe000, 0xffffc000, 0xffff8000, 0xffff0000,
							0xfffe0000, 0xfffc0000, 0xfff80000, 0xfff00000,
							0xffe00000, 0xffc00000, 0xff800000, 0xff000000,
							0xfe000000, 0xfc000000, 0xf8000000, 0xf0000000,
							0xe0000000, 0xc0000000, 0x80000000, 0x00000000
							};
UINT32 andMASK_Table2[32] =	{
							0x00000000, 0x00000001, 0x00000003, 0x00000007,
							0x0000000f, 0x0000001f, 0x0000003f, 0x0000007f,
							0x000000ff, 0x000001ff, 0x000003ff, 0x000007ff,
							0x00000fff, 0x00001fff, 0x00003fff, 0x00007fff,
							0x0000ffff, 0x0001ffff, 0x0003ffff, 0x0007ffff,
							0x000fffff, 0x001fffff, 0x003fffff, 0x007fffff,
							0x00ffffff, 0x01ffffff, 0x03ffffff, 0x07ffffff,
							0x0fffffff, 0x1fffffff, 0x3fffffff, 0x7fffffff
							};
/*=======================*/

void drvif_color_PQ_Adaptive_offset_temp(unsigned int *PQA_TABLE, unsigned char src, unsigned char index, unsigned int *PQA_TABLE_OFFSET_TEMP)
{
	UINT16 PQA_ITEM_count;
	UINT32 PQA_row, NR_Table = ((src*PQA_MODE_MAX*PQA_ITEM_MAX*PQA_LEVEL_MAX) + (PQA_MODE_OFFSET*PQA_ITEM_MAX*PQA_LEVEL_MAX));

	UINT32 PQA_Reg;
	UINT8 PQA_Bitup, PQA_Bitlow, PQA_Input_type, mask_idx;

	if (!PQA_TABLE) {
		VIPprintf( "PQ data ERROR, PQA_TABLE is NULL!!\n");
		return;
	}

	for (PQA_ITEM_count = 0; PQA_ITEM_count < PQA_ITEM_MAX; PQA_ITEM_count++) {
		/*=======================================================================*/
		PQA_row = NR_Table + (PQA_ITEM_count*PQA_LEVEL_MAX);


		/*=======================================================================*/
		PQA_Reg = *(PQA_TABLE+PQA_row+PQA_reg);
		PQA_Bitup = *(PQA_TABLE+PQA_row+PQA_bitup);
		PQA_Bitlow = *(PQA_TABLE+PQA_row+PQA_bitlow);
		PQA_Input_type = *(PQA_TABLE+PQA_row+PQA_input_type);

		/*=======================================================================*/
		if (PQA_Reg == 0xffffffff || PQA_ITEM_count >= PQA_ITEM_MAX)						/*Data Finish*/
			break;

		mask_idx = PQA_Bitup-PQA_Bitlow+1;

		if (index == PQA_Input_type && mask_idx < 32) {
			PQA_TABLE_OFFSET_TEMP[PQA_ITEM_count] = (IoReg_Read32(PQA_Reg) >> PQA_Bitlow) & andMASK_Table2[mask_idx];	/*data*/
		}
		VIPprintf( "PQ_Adaptive PQA_Reg %x PQA_Bitup %d PQA_Bitlow %d %d\n", PQA_Reg, PQA_Bitup, PQA_Bitlow, (IoReg_Read32(PQA_Reg) >> PQA_Bitlow) & andMASK_Table2[mask_idx]);

	}
	fwif_color_ChangeUINT32Endian(PQA_TABLE_OFFSET_TEMP , PQA_ITEM_count, 0);

}


