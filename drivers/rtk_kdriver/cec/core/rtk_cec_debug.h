/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_CEC_DEBUG_H__
#define __RTK_CEC_DEBUG_H__

#include <mach/rtk_log.h>


/*-- cec debug messages*/
/*#define CONFIG_CEC_DBG*/
/*#define CEC_TX_DBG*/
/*#define CEC_RX_DBG*/



#ifdef CONFIG_CEC_DBG
#define cec_dbg(fmt, args...)	rtd_printk(KERN_DEBUG, "CEC","[DBG] " fmt, ## args)
#else
#define cec_dbg(args...)
#endif

#ifdef CEC_TX_DBG
#define cec_tx_dbg(fmt, args...)              rtd_printk(KERN_DEBUG, "CEC","[TX DBG] " fmt, ## args)
#else
#define cec_tx_dbg(args...)
#endif

#ifdef CEC_RX_DBG
#define cec_rx_dbg(fmt, args...)              rtd_printk(KERN_DEBUG, "CEC","[RX DBG] " fmt, ## args)
#else
#define cec_rx_dbg(args...)
#endif

#define cec_info(fmt, args...)		rtd_printk( KERN_INFO , "CEC",  "[Info] " fmt, ## args)
#define cec_warn(fmt, args...)		rtd_printk( KERN_WARNING , "CEC", "[Warn] " fmt, ## args)
#define cec_error(fmt, args...)		rtd_printk( KERN_ERR , "CEC", "[error] " fmt, ## args)

#endif /*__RTK_CEC_DEBUG_H__*/
