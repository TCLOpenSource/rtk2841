#ifndef __ASM_ARM_SUSPEND_H
#define __ASM_ARM_SUSPEND_H

struct sleep_save_sp {
	u32 *save_ptr_stash;
	u32 save_ptr_stash_phys;
};

extern void cpu_resume(void);
extern void cpu_resume_arm(void);
extern int cpu_suspend(unsigned long, int (*)(unsigned long));

static inline int arch_prepare_suspend(void) { return 0; }

#endif
