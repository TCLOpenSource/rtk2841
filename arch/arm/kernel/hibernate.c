/*
 * Hibernation support specific for ARM
 *
 * Derived from work on ARM hibernation support by:
 *
 * Ubuntu project, hibernation support for mach-dove
 * Copyright (C) 2010 Nokia Corporation (Hiroshi Doyu)
 * Copyright (C) 2010 Texas Instruments, Inc. (Teerth Reddy et al.)
 *  https://lkml.org/lkml/2010/6/18/4
 *  https://lists.linux-foundation.org/pipermail/linux-pm/2010-June/027422.html
 *  https://patchwork.kernel.org/patch/96442/
 *
 * Copyright (C) 2006 Rafael J. Wysocki <rjw@sisk.pl>
 *
 * License terms: GNU General Public License (GPL) version 2
 */

#include <linux/mm.h>
#include <linux/suspend.h>
#include <linux/slab.h>
#include <asm/system_misc.h>
#include <asm/idmap.h>
#include <asm/suspend.h>
#include <asm/memory.h>
#include <asm/sections.h>
#include "reboot.h"
#include <asm/outercache.h>

int pfn_is_nosave(unsigned long pfn)
{
	unsigned long nosave_begin_pfn = virt_to_pfn(&__nosave_begin);
	unsigned long nosave_end_pfn = virt_to_pfn(&__nosave_end - 1);

	return (pfn >= nosave_begin_pfn) && (pfn <= nosave_end_pfn);
}

void notrace save_processor_state(void)
{
	WARN_ON(num_online_cpus() != 1);
	local_fiq_disable();
}

void notrace restore_processor_state(void)
{
#ifdef CONFIG_LG_SNAPSHOT_BOOT
	extern int in_suspend;
	if(!in_suspend)
		outer_resume();
#endif
	local_fiq_enable();
}

/*
 * Snapshot kernel memory and reset the system.
 *
 * swsusp_save() is executed in the suspend finisher so that the CPU
 * context pointer and memory are part of the saved image, which is
 * required by the resume kernel image to restart execution from
 * swsusp_arch_suspend().
 *
 * soft_restart is not technically needed, but is used to get success
 * returned from cpu_suspend.
 *
 * When soft reboot completes, the hibernation snapshot is written out.
 */
static int notrace arch_save_image(unsigned long unused)
{
	int ret;

	ret = swsusp_save();
	if (ret == 0)
		_soft_restart(virt_to_phys(cpu_resume), false);
	return ret;
}

/*
 * Save the current CPU state before suspend / poweroff.
 */
int notrace swsusp_arch_suspend(void)
{
	return cpu_suspend(0, arch_save_image);
}

#ifdef CONFIG_LG_SNAPSHOT_BOOT
extern unsigned long  __nosave_backup_phys, __nosave_begin_phys, __nosave_end_phys;

static int __init swsusp_arch_init(void)
{
	char *backup;
	size_t len;

	len = &__nosave_end - &__nosave_begin;
	if(!len)
		return 0;

	backup = kmalloc(len, GFP_KERNEL);
	if(!backup) {
		printk("%s %d kmalloc fail, can't save nosave data!\n", __func__, __LINE__);
		return -1;
	}
	memcpy(backup, &__nosave_begin, len);

	__nosave_backup_phys = virt_to_phys(backup);
	__nosave_begin_phys = virt_to_phys(&__nosave_begin);
	__nosave_end_phys = virt_to_phys(&__nosave_end);

	return 0;
}
late_initcall(swsusp_arch_init);
#else	// CONFIG_LG_SNAPSHOT_BOOT
/*
 * Restore page contents for physical pages that were in use during loading
 * hibernation image.  Switch to idmap_pgd so the physical page tables
 * are overwritten with the same contents.
 */
static void notrace arch_restore_image(void *unused)
{
	struct pbe *pbe;

	cpu_switch_mm(idmap_pgd, &init_mm);
	for (pbe = restore_pblist; pbe; pbe = pbe->next)
		copy_page(pbe->orig_address, pbe->address);

	_soft_restart(virt_to_phys(cpu_resume), false);
}

static u64 resume_stack[PAGE_SIZE/2/sizeof(u64)] __nosavedata;

/*
 * Resume from the hibernation image.
 * Due to the kernel heap / data restore, stack contents change underneath
 * and that would make function calls impossible; switch to a temporary
 * stack within the nosave region to avoid that problem.
 */
int swsusp_arch_resume(void)
{
	call_with_stack(arch_restore_image, 0,
		resume_stack + ARRAY_SIZE(resume_stack));
	return 0;
}
#endif	// CONFIG_LG_SNAPSHOT_BOOT