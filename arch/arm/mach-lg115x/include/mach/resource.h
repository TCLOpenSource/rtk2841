#ifndef __MACH_RESOURCE_H
#define __MACH_RESOURCE_H

#include <linux/compiler.h>

#ifdef CONFIG_MACH_LG1152
#include <asm/resource-lg1152.h>
#endif

#ifdef CONFIG_MACH_LG1154
#include <asm/resource-lg1154.h>
#endif

#ifdef CONFIG_MACH_LG1156
#include <asm/resource-lg1156.h>
#endif

#define MMIO_P2V(x)	((void __iomem *)__MMIO_P2V(x))

#endif

