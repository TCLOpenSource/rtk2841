#ifndef __ARCH_LG115X_DMAC_H
#define __ARCH_LG115X_DMAC_H

#ifndef CONFIG_AMBA_PL08X

static inline void lg115x_init_dmac(void)
{
}

#else	/* CONFIG_AMBA_PL08X */

#include <linux/init.h>

extern void __init lg115x_init_dmac(void);

#endif	/* CONFIG_AMBA_PL08X */

#endif	/* __ARCH_LG115X_DMAC_H */
