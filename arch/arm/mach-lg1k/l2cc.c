#include <linux/kernel.h>

#include <linux/init.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_platform.h>

#include <asm/hardware/cache-l2x0.h>
#include <asm/io.h>
#include <asm/firmware.h>
#include <asm/outercache.h>

#include "smc.h"

struct smc_param smc_param_save;

static void l2cc_resume(void)
{
	call_firmware_op(l2x0_init);
}

static const struct of_device_id lg115x_l2cc_ids[] __initconst = {
	{.compatible = "lg115x-pl310-cache"},
	{},
};

void __init lg115x_init_l2cc(void)
{
	struct device_node *np;

	np = of_find_matching_node(NULL, lg115x_l2cc_ids);
	if (np) {
		u32 tmp[2];
		void __iomem *l2c_tmp_base;

		of_property_read_u32_array(np, "reg", tmp, ARRAY_SIZE(tmp));
		l2c_tmp_base = ioremap(tmp[0], tmp[1]);

		/* save smc parameters for l2cc resume */
		smc_param_save.param[0] = 0x0100;
		smc_param_save.param[1] = readl_relaxed(l2c_tmp_base + L2X0_AUX_CTRL);
		iounmap(l2c_tmp_base);
		/* Debug Control Register */
		smc_param_save.param[4] = 0x0;
		of_property_read_u32(np, "tag-latency-ctrl",
					(u32 *)&smc_param_save.param[2]);
		of_property_read_u32(np, "data-latency-ctrl",
					(u32 *)&smc_param_save.param[3]);
		of_property_read_u32(np, "prefetch-ctrl",
					(u32 *)&smc_param_save.param[5]);
		/* enable pl310-cache */
		call_firmware_op(l2x0_init);
	}
	l2x0_of_init(0, ~0UL);
	/* re-register resume handler */
	outer_cache.resume = l2cc_resume;
}
