/*
 * RTD299X sleep code.
 *
 * Copyright (C) 2013 Realtek, Inc.
 *  Santosh Shilimkar <santosh.shilimkar@ti.com>
 *
 * This program is free software,you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/linkage.h>
#include <linux/mm.h>
#include <linux/suspend.h>
#include <asm/tlbflush.h>
#include <asm/cacheflush.h>
#include <asm/system_misc.h>
#include <asm/idmap.h>
#include <asm/suspend.h>
#include <asm/smp_scu.h>
#include <asm/memory.h>
#include <asm/hardware/cache-l2x0.h>
#include <mach/system.h>

extern volatile unsigned int l2x0_ctrl;
extern volatile unsigned int l2x0_aux_ctrl;
extern volatile unsigned int l2x0_prefetch_ctrl;
extern volatile unsigned int l2x0_tag_latency;
extern volatile unsigned int l2x0_data_latency;

#if 0
    #define L2X0_CTRL_VAL               l2x0_ctrl
    #define L2X0_AUX_CTRL_VAL           l2x0_aux_ctrl
    #define L2X0_PREFETCH_CTR_LVAL      l2x0_prefetch_ctrl
    #define L2X0_TAG_LATENCY_VAL        l2x0_tag_latency
    #define L2X0_DATA_LATENCY_VAL       l2x0_data_latency
#else
    #define L2X0_CTRL_VAL               0x00000001
    #define L2X0_AUX_CTRL_VAL           0x02050000
    #define L2X0_PREFETCH_CTR_LVAL      0x04000000
    #define L2X0_TAG_LATENCY_VAL        0x00000010
    #define L2X0_DATA_LATENCY_VAL       0x00000121
#endif

void rtd299x_cpu_resume( void )
{
#ifdef CONFIG_CACHE_L2X0
    // re-store L2 setting
    
    // -------------------------------------------------------------------------
    __asm__ volatile ( "LDR     r0, =0x1801d108" );                             // L2X0_TAG_LATENCY_CTRL address
    __asm__ volatile ( "LDR     r1, =0x00000010" );                             // L2X0_TAG_LATENCY_VAL
    __asm__ volatile ( "STR     r1, [r0]" );                                    // set L2X0_TAG_LATENCY_CTRL
    // -------------------------------------------------------------------------
    __asm__ volatile ( "LDR     r0, =0x1801d10C" );                             // L2X0_DATA_LATENCY_CTRL address
    __asm__ volatile ( "LDR     r1, =0x00000121" );                             // L2X0_DATA_LATENCY_VAL
    __asm__ volatile ( "STR     r1, [r0]" );                                    // set L2X0_DATA_LATENCY_CTRL
    // -------------------------------------------------------------------------
    __asm__ volatile ( "LDR     r0, =0x1801dF60" );                             // L2X0_PREFETCH_CTRL address
    __asm__ volatile ( "LDR     r1, =0x04000000" );                             // L2X0_PREFETCH_CTR_LVAL
    __asm__ volatile ( "STR     r1, [r0]" );                                    // set L2X0_PREFETCH_CTRL
    // -------------------------------------------------------------------------
    __asm__ volatile ( "LDR     r0, =0x1801d104" );                             // L2X0_AUX_CTRL address
    __asm__ volatile ( "LDR     r1, =0x02050000" );                             // L2X0_AUX_CTRL_VAL
    __asm__ volatile ( "STR     r1, [r0]" );                                    // set L2X0_AUX_CTRL
    // -------------------------------------------------------------------------

    // invalidate L2 cache
    // ?? fix me
    
    // enable L2 cache
	__asm__ volatile ( "LDR     r0, =0x1801d100" );                             // L2X0_CTRL address
    __asm__ volatile ( "LDR     r1, =0x00000001" );                             // L2X0_CTRL_VAL
    __asm__ volatile ( "STR     r1, [r0]" );                                    // set L2X0_CTRL
#endif
    
    //cpu_resume();																// call generic CPU resume routinue
#if 0
    __asm__ volatile ( "LDR     r0, =0x00785578" );								// cpu_resume address from System.map
    __asm__ volatile ( "MOV     PC, r0" );
#else
#if 0 // fix me - jinn - kernel porting
    __asm__ volatile ( "LDR     r0, =cpu_resume" );								// get cpu_resume virtual address
    __asm__ volatile ( "BIC     r0, r0, #0xC0000000" );							// convert to physical address ( dirty..., fix me by address relocate )
    __asm__ volatile ( "MOV     PC, r0" );										// jump to cpu_resume
#endif
#endif
}
