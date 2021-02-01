#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/of_platform.h>
#include <linux/amba/pl08x.h>
#include <linux/amba/pl080.h>

extern struct pl08x_platform_data dmac_data;
extern struct pl022_ssp_controller spi0_data;
extern struct pl022_ssp_controller spi1_data;

static struct of_dev_auxdata lg115x_auxdata_lookup[] __initdata = {
	OF_DEV_AUXDATA("arm,pl080", 0xff200000, "dmac", &dmac_data),
	OF_DEV_AUXDATA("arm,pl022", 0xfe800000, "spi0", &spi0_data),
	OF_DEV_AUXDATA("arm,pl022", 0xfe900000, "spi1", &spi1_data),
	{ },
};

static int __init lg115x_init_machine(void)
{
	of_platform_populate(NULL, of_default_bus_match_table,
				lg115x_auxdata_lookup, NULL);
	return 0;
}
arch_initcall(lg115x_init_machine);

