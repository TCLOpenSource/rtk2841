//Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
#ifndef __PADLOCK_H__
#define __PADLOCK_H__

#include <linux/mutex.h>

////////////////////////////// define /////////////////////////
typedef enum {    
	PAD_PCMCIA = 0,    
	PAD_SD_CHECK,    
	PAD_SD_ACTION,
}PAD_ID;

#define MAX_PADMUX_VAL_CNT  4

typedef struct {        
    unsigned char       valid;
    unsigned long       addr;
    unsigned long       mask;
    unsigned long       val[MAX_PADMUX_VAL_CNT];
}PAD_MUX_REG;

typedef struct {        
    struct mutex*       lock;
    unsigned int        n_regs;
    PAD_MUX_REG*        regs;    
}PAD_MUX_CFG;


#define PAD_MUX_REG_CNT(x)          (sizeof(x) / sizeof(PAD_MUX_REG))

////////////////////////////// api /////////////////////////

#ifdef CONFIG_RTK_KDRV_PAD_LOCK

extern void padlock(PAD_ID pad_id);

extern void padunlock(PAD_ID pad_id);

extern int _pad_lock_and_zap_pinmux(PAD_MUX_CFG* config, unsigned char id);

extern int _pad_unlock(PAD_MUX_CFG* config, unsigned char id);

#else

#define padlock(pad_id) {}
#define padunlock(pad_id)  {}

#endif


////////////////////////////// DBG /////////////////////////

#ifdef PL_DBG_EN
#define PL_DBG(fmt, args...)        printk("[PADLOCK] DBG," fmt, ##args)
#else
#define PL_DBG(fmt, args...)        
#endif
#define PL_WARNING(fmt, args...)    printk("[PADLOCK] WARNING," fmt, ##args)


#endif /* !(__PADLOCK_H__) */

