#ifndef __ARCH_LG115X_USB_H
#define __ARCH_LG115X_USB_H

#ifndef CONFIG_USB

static inline void lg115x_init_usb(void)
{
}

#else	/* CONFIG_USB */

#include <linux/init.h>

#if defined(XHCI0_BASE) && defined(XHCI0_IRQ)
#define MACH_HAS_XHCI0
#endif	/* XHCI0_BASE && XHCI0_IRQ */

#if defined(XHCI1_BASE) && defined(XHCI1_IRQ)
#define MACH_HAS_XHCI1
#endif	/* XHCI1_BASE && XHCI1_IRQ */

#if defined(XHCI2_BASE) && defined(XHCI2_IRQ)
#define MACH_HAS_XHCI2
#endif	/* XHCI2_BASE && XHCI2_IRQ */

#if defined(XHCI3_BASE) && defined(XHCI3_IRQ)
#define MACH_HAS_XHCI3
#endif	/* XHCI3_BASE && XHCI3_IRQ */

#if defined(EHCI0_BASE) && defined(EHCI0_IRQ)
#define MACH_HAS_EHCI0
#endif	/* EHCI0_BASE && EHCI0_IRQ */

#if defined(EHCI1_BASE) && defined(EHCI1_IRQ)
#define MACH_HAS_EHCI1
#endif	/* EHCI1_BASE && EHCI1_IRQ */

#if defined(EHCI2_BASE) && defined(EHCI2_IRQ)
#define MACH_HAS_EHCI2
#endif	/* EHCI2_BASE && EHCI2_IRQ */

#if defined(OHCI0_BASE) && defined(OHCI0_IRQ)
#define MACH_HAS_OHCI0
#endif	/* OHCI0_BASE && OHCI0_IRQ */

#if defined(OHCI1_BASE) && defined(OHCI1_IRQ)
#define MACH_HAS_OHCI1
#endif	/* OHCI1_BASE && OHCI1_IRQ */

#if defined(OHCI2_BASE) && defined(OHCI2_IRQ)
#define MACH_HAS_OHCI2
#endif	/* OHCI2_BASE && OHCI2_IRQ */

extern void __init lg115x_init_usb(void);

#endif	/* CONFIG_USB */

#endif	/* __ARCH_LG115X_USB_H */
