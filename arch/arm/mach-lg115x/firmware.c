#include <linux/kernel.h>
#include <linux/init.h>

#include <asm/io.h>
#include <asm/hw_breakpoint.h>
#include <asm/hardware/cache-l2x0.h>
#include <asm/firmware.h>


#include <mach/resource.h>

#include "l2cc.h"
#include "smc.h"


#define ARM_CA9			0xc09
#define ARM_CA15		0xc0f


#define ARM_CPUID_READ(N, M, OP1, OP2, VAL) do {\
	asm volatile("mrc p15," #OP1 "," " %0 " ", " #N "," #M "," #OP2 : "=r" (VAL));\
} while (0)


/* cp15 read multiprocessor id register */
static u32 __arm_part_num(void)
{
	u32 val;
	
	ARM_CPUID_READ(c0, c0, 0, 0, val);

	return  (val >> 4) & 0xFFF;
}

static u32 __arm_get_ns(void)
{
	u32 dscr;
	
	ARM_DBG_READ(c0, c1, 0, dscr);
	
	return (dscr &= ~(0x1 << 18));
}

static u32 _arm_ns(u32 pn)
{
	return (__arm_get_ns() && (__arm_part_num() == pn));
}

static int _l2x0_init(void)
{
	int ret = 0;
	
	if(_arm_ns(ARM_CA9)) {
		
		struct smc_param param;
		/*
	 	 * 1st-half for non-secure kernel: enable L2CC with desired control
	 	 * values via secure monitor call
	 	 */
		param.param[0] = 0x0100;
		param.param[1] = readl_relaxed(MMIO_P2V(L2CC_BASE + L2X0_AUX_CTRL));
		param.param[2] = L2TLCTRL;
		param.param[3] = L2DLCTRL;
		param.param[4] = L2DBCTRL;
		param.param[5] = L2PFCTRL;
	
		lg115x_smc(&param);
		
	} else 
		ret = -ENOSYS;
	
	return ret;
}

static int _cpu_boot(int cpu)
{
	int ret = 0;
	
	if(_arm_ns(ARM_CA15)){	
		struct smc_param param;
		
		param.param[0] = 0x0104;
		param.param[1] = 1;

		lg115x_smc(&param);
	}
	else 
		ret = -ENOSYS;
	
	return ret;
}


static const struct firmware_ops arm_firmware_ops = {

	.cpu_boot		= _cpu_boot,
	.l2x0_init 		= _l2x0_init,
};

void __init lg115x_arm_firmware_init(void)
{

	/*
	 * LG DTVSoCs are running with secure firmware running in TrustZone secure
	 * world, which changes the way some things have to be initialized. This makes
	 * a need to provide an interface for such platforms to specify available firmware
	 * operations and call them when needed.
	 */
	register_firmware_ops(&arm_firmware_ops);
}

