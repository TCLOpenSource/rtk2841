#ifndef _ASM_ARM_KASAN_H
#define _ASM_ARM_KASAN_H

#include <asm/memory.h>

#define KASAN_SHADOW_OFFSET	_AC(CONFIG_KASAN_SHADOW_OFFSET, UL)
#define KASAN_SHADOW_PHYS	_AC(CONFIG_KASAN_SHADOW_PHYS, UL)
#define KASAN_SHADOW_VIRT	_AC(CONFIG_KASAN_SHADOW_VIRT, UL)
#define KASAN_SHADOW_SIZE	_AC(CONFIG_KASAN_SHADOW_SIZE, UL)

#define KASAN_SHADOW_START	KASAN_SHADOW_VIRT
#define KASAN_SHADOW_END	(KASAN_SHADOW_START + KASAN_SHADOW_SIZE)

#ifndef __ASSEMBLY__

#ifdef CONFIG_KASAN

extern void __init kasan_init(void);

#else

static inline void kasan_init(void) { }

#endif

#endif

#endif
