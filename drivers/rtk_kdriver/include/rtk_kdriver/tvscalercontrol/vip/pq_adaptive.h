#ifndef _PQA_H_
#define _PQA_H_
#if CONFIG_FIRMWARE_IN_KERNEL
#include <scalercommon/vipCommon.h>	/* in common*/
#else
#include <scaler/vipCommon.h>	// in common
#endif

void drvif_color_PQ_Adaptive_offset_temp(unsigned int *PQA_TABLE, unsigned char src, unsigned char index, unsigned int *PQA_TABLE_OFFSET_TEMP);

#endif