#ifndef _LINUX_RTK_VGIP_ISR_H
#define _LINUX_RTK_VGIP_ISR_H

#include <linux/module.h>
#include <linux/kernel.h>

#define VGIP_ISR_MAJOR 242

typedef struct {
	int dummy;
} dummy_vgip_isr_struct;

/* Use 'V' as magic number */
#define VGIP_ISR_IOC_MAGIC  'V'

#define VGIP_ISR_IOCT_DUMMY		_IOW(VGIP_ISR_IOC_MAGIC, 1, dummy_vgip_isr_struct)

#endif

