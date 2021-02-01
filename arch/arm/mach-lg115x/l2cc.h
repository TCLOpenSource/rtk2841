#ifndef __ARCH_LG115X_L2CC_H
#define __ARCH_LG115X_L2CC_H

#ifndef CONFIG_CACHE_L2X0

static inline void lg115x_init_l2cc(void)
{
}

#else	/* CONFIG_CACHE_L2X0 */

#include <linux/init.h>

#ifndef CONFIG_L2CC_PREFETCH_DATA
#define __PREFETCH_DAT	(0 << 28)
#else
#define __PREFETCH_DAT	(1 << 28)
#endif

#ifndef CONFIG_L2CC_PREFETCH_INST
#define __PREFETCH_INS	(0 << 29)
#else
#define __PREFETCH_INS	(1 << 29)
#endif

#ifndef CONFIG_L2CC_PREFETCH_OFFSET
#define __PREFETCH_OFS	0
#else
#define __PREFETCH_OFS	CONFIG_L2CC_PREFETCH_OFFSET
#endif

#ifndef CONFIG_L2CC_DEBUG_DCL
#define __DEBUG_DCL	0
#else
#define __DEBUG_DCL	1
#endif

#ifndef CONFIG_L2CC_DEBUG_DWB
#define __DEBUG_DWB	(0 << 1)
#else
#define __DEBUG_DWB	(1 << 1)
#endif

#define L2TLCTRL	CONFIG_L2CC_LATENCY_TAG
#define L2DLCTRL	CONFIG_L2CC_LATENCY_DATA
#define L2PFCTRL	(__PREFETCH_DAT | __PREFETCH_INS | __PREFETCH_OFS)
#define L2DBCTRL	(__DEBUG_DCL | __DEBUG_DWB)

extern void __init lg115x_init_l2cc(void);

#endif	/* CONFIG_CACHE_L2X0 */

#endif	/* __ARCH_LG115X_L2CC_H */
