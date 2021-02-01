#ifndef RTKDEMUX_REGISTER_H
#define RTKDEMUX_REGISTER_H

#if defined(CONFIG_ARCH_RTK289X)//merlin2

	#include <tp/rbusTPReg.h>
	//tp registers
	#define TP_TP_PCRA_90K_CNT_reg 				TP_PCRA_90K_CNT_VADDR
	#define TP_TP_PCRA_90K_CNT_HIGH_reg			TP_PCRA_90K_CNT_HIGH_VADDR
	#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	#define TP_TP_PCRB_90K_CNT_reg 				TP_PCRB_90K_CNT_VADDR
	#define TP_TP_PCRB_90K_CNT_HIGH_reg			TP_PCRB_90K_CNT_HIGH_VADDR
	#endif

#else//end merlin2
// auto parse tp register auto parse
#include <rbus/tp_reg.h>
	#ifndef TP_TP_PCRA_90K_CNT_reg
	#define TP_TP_PCRA_90K_CNT_reg			TP_TP_PCRA_CNT_LOW_reg
	#endif

	#ifndef TP_TP_PCRA_90K_CNT_HIGH_reg
	#define TP_TP_PCRA_90K_CNT_HIGH_reg		TP_TP_PCRA_CNT_HIGH_reg
	#endif

	#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	#ifndef TP_TP_PCRB_90K_CNT_reg
	#define TP_TP_PCRB_90K_CNT_reg			TP_TP_PCRB_CNT_LOW_reg
	#endif
	#ifndef TP_TP_PCRB_90K_CNT_HIGH_reg
	#define TP_TP_PCRB_90K_CNT_HIGH_reg		TP_TP_PCRB_CNT_HIGH_reg
	#endif

	#endif
#endif

#endif
