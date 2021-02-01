/*
 * arch/arm/mach-lg1152/ion.h
 */

#ifndef _LG115X_ION_H
#define _LG115X_ION_H

#define LG115X_ION_CARVEOUT_BLOCK0_BASE	(0x90000000)
#define LG115X_ION_CARVEOUT_BLOCK0_SIZE (0x7200000) /* 114MB */

#ifdef CONFIG_ION_LG115X
void lg115x_ion_init(void);
void lg115x_register_ion(void);
#else
inline void lg115x_ion_init(void) { return; }
inline void lg115x_register_ion(void) { return; }
#endif

#endif
