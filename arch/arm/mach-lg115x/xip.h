#ifndef __ARCH_LG115X_XIP_H
#define __ARCH_LG115X_XIP_H

#ifndef CONFIG_LG_XIP

static inline void lg115x_reserve_xip(void)
{
}

#else	/* CONFIG_LG_XIP */

#include <linux/init.h>

extern void __init lg115x_reserve_xip(void);

#endif	/* CONFIG_LG_XIP */

#endif	/* __ARCH_LG115X_XIP_H */
