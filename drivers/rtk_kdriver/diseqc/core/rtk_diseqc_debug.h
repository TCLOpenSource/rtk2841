/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_CEC_DISEQC_H__
#define __RTK_CEC_DISEQC_H__

#include <mach/rtk_log.h>


/*#define CONFIG_CEC_DBG*/

/*#define CEC_TX_DBG*/

/*#define CEC_RX_DBG*/



#ifdef CONFIG_DISEQC_DBG
#define diseqc_dbg(fmt, args...)	rtd_printk(KERN_DEBUG, "diseqc","[DBG] " fmt, ## args)
#else
#define diseqc_dbg(args...)
#endif

#ifdef DISEQC_TX_DBG
#define diseqc_tx_dbg(fmt, args...)	rtd_printk(KERN_DEBUG, "diseqc","[TX DBG] " fmt, ## args)
#else
#define diseqc_tx_dbg(args...)
#endif

#ifdef DISEQC_RX_DBG
#define diseqc_rx_dbg(fmt, args...)	rtd_printk(KERN_DEBUG, "diseqc","[RX DBG] " fmt, ## args)
#else
#define diseqc_rx_dbg(args...)
#endif

#define diseqc_info(fmt, args...)	rtd_printk( KERN_INFO    , "diseqc", "[Info] " fmt, ## args)
#define diseqc_warn(fmt, args...)	rtd_printk( KERN_WARNING , "diseqc", "[Warn] " fmt, ## args)
#define diseqc_err(fmt, args...)	rtd_printk( KERN_ERR	, "diseqc", "[Error] " fmt, ## args)

#endif
