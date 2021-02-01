#include <linux/kernel.h>

#include <linux/bootmem.h>
#include <linux/kasan.h>
#include <linux/kdebug.h>
#include <linux/memblock.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>

#include <asm/mach/map.h>

#ifdef CONFIG_KASAN_INLINE
static int
kasan_die_handler(struct notifier_block *self, unsigned long val, void *data)
{
	if (val == DIE_GPF) {
		pr_emerg("CONFIG_KASAN_INLINE enabled\n");
		pr_emerg("GPF could be caused by NULL-pointer dereference or "
		         "user memory access\n");
	}
	return NOTIFY_OK;
}

static struct notifier_block kasan_die_notifier = {
	.notifier_call = kasan_die_notifier,
};
#endif

void __init kasan_init(void)
{
	struct map_desc md;

	md.virtual = KASAN_SHADOW_VIRT;
	md.pfn = __phys_to_pfn(KASAN_SHADOW_PHYS);
	md.length = KASAN_SHADOW_SIZE;
	md.type = MT_MEMORY_RW;
	iotable_init(&md, 1);

#ifdef CONFIG_KASAN_INLINE
	register_die_notifier(&kasan_die_notifier);
#endif

	pr_emerg("kasan is initialized: shadow P(%#lx - %#lx), V(%#lx - %#lx)\n",
	       KASAN_SHADOW_PHYS, KASAN_SHADOW_PHYS + KASAN_SHADOW_SIZE,
	       KASAN_SHADOW_VIRT, KASAN_SHADOW_VIRT + KASAN_SHADOW_SIZE);

	current->kasan_depth = 0;
}
