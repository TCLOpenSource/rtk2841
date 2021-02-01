#include <linux/kernel.h>

#include <linux/init.h>
#include <linux/ioport.h>

#include <asm/io.h>

#include <mach/resource.h>

#include "smp.h"

#define SYS_FLAGS	0x02dc

void lg115x_flags_set(unsigned long data)
{
	writel_relaxed(data, MMIO_P2V(CPU_CTRL_BASE + SYS_FLAGS));
}
