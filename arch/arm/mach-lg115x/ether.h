#ifndef __ARCH_LG115X_ETHER_H
#define __ARCH_LG115X_ETHER_H

#include <linux/init.h>

#if defined(EMAC_BASE) && defined(EMAC_IRQ)
#define MACH_HAS_EMAC
#endif	/* EMAC_BASE && EMAC_IRQ */

#if defined(MACB_BASE) && defined(MACB_IRQ)
#define MACH_HAS_MACB
#endif	/* MACB_BASE && MACB_IRQ */

extern void __init lg115x_reserve_ether(void);
extern void __init lg115x_init_ether(void);

#endif	/* __ARCH_LG115X_ETHER_H */
