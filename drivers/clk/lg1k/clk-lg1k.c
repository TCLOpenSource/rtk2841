#include <linux/kernel.h>

#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <linux/clkdev.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/lg1k/pms.h>
#include <linux/of.h>
#include <linux/of_address.h>

struct clk_lg1k {
	struct clk_hw hw;
	void __iomem *base;
	u32 fix[2];
};

#define to_clk_lg1k(_hw)	container_of(_hw, struct clk_lg1k, hw)

#pragma	pack(push, 1)

struct pll_ctrl {
	u32	/* reserved */	: 19;
	u32	m		:  5;
	u32	pre_fd		:  2;
	u32	od_fout		:  2;
	u32	/* reserved */	:  4;

	u32	/* reserved */	: 14;
	u32	nsc		:  4;
	u32	npc		:  6;
	u32	/* reserved */	:  8;
};

#pragma	pack(pop)

#define CTR(n)	((n) << 2)

static unsigned long
clk_lg1k_pll_rate(struct clk_hw *hw, off_t offset, unsigned long parent_rate)
{
	struct clk_lg1k const *clk = to_clk_lg1k(hw);
	u64 rate = (u64)parent_rate;
	u32 base, regs[2];
	struct pll_ctrl *ctrl = (struct pll_ctrl *)regs;

	regs[0] = clk->fix[0] ^ readl_relaxed(clk->base + CTR(offset));
	regs[1] = clk->fix[1] ^ readl_relaxed(clk->base + CTR(offset + 1));

	rate *= ((ctrl->npc << 2) + ctrl->nsc) << ctrl->pre_fd;
	base = (ctrl->m + 1) << ctrl->od_fout;
	do_div(rate, base);

	return (unsigned long)rate;
}

static unsigned long
clk_lg1154_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
	struct clk_lg1k const *clk = to_clk_lg1k(hw);
	u32 div = readl_relaxed(clk->base + CTR(0x1c)) >> 18;
	return clk_lg1k_pll_rate(hw, 0x4a, parent_rate) >> ((div & 0x03) + 1);
}

static unsigned long
clk_lg1156_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
	return clk_lg1k_pll_rate(hw, 0x4a, parent_rate);
}

static unsigned long
clk_lg1210_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
	struct clk_lg1k const *clk = to_clk_lg1k(hw);
	u32 mux = readl_relaxed(clk->base + CTR(0x0f)) & 0x03;

	switch (mux) {
	case 0:	/* CPU-PLL0 */
		return clk_lg1k_pll_rate(hw, 0x20, parent_rate);

	case 1:	/* CPU-PLL1 */
		return clk_lg1k_pll_rate(hw, 0x22, parent_rate);

	default:/* XTAL pass-through */
		return parent_rate;
	}
}

static unsigned long
clk_lg1311_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
	struct clk_lg1k const *clk = to_clk_lg1k(hw);
	u32 div = readl_relaxed(clk->base + CTR(0x1c)) >> 18;
	return clk_lg1k_pll_rate(hw, 0x00, parent_rate) >> ((div & 0x03) + 1);
}

static long clk_lg1k_round_rate(struct clk_hw *hw, unsigned long rate,
                                unsigned long *parent_rate)
{
	return rate;
}

static int clk_lg1k_set_rate(struct clk_hw *hw, unsigned long rate,
                             unsigned long parent_rate)
{
	return -ENOSYS;
}

static int clk_lg1156_set_rate(struct clk_hw *hw, unsigned long rate,
                               unsigned long parent_rate)
{
	unsigned long flags;
	int err;

	/*
	 * NOTE: LG1156 needs disabling both local interrupts and preemption
	 * to minimize intermediate duration where CPU is operating in 24Mhz
	 */
	local_irq_save(flags);
	preempt_disable();

	/* scale CPU-PLL frequency via PMS */
	err = lg1k_pms_set_cpufreq(0, rate / 1000);

	preempt_enable();
	local_irq_restore(flags);

	return err;
}

static struct clk_ops const clk_lg1154_ops = {
	.recalc_rate	= clk_lg1154_recalc_rate,
	.round_rate	= clk_lg1k_round_rate,
	.set_rate	= clk_lg1k_set_rate,
};

static struct clk_ops const clk_lg1156_ops = {
	.recalc_rate	= clk_lg1156_recalc_rate,
	.round_rate	= clk_lg1k_round_rate,
	.set_rate	= clk_lg1156_set_rate,
};

static struct clk_ops const clk_lg1210_ops = {
	.recalc_rate	= clk_lg1210_recalc_rate,
	.round_rate	= clk_lg1k_round_rate,
	.set_rate	= clk_lg1156_set_rate,
};

static struct clk_ops const clk_lg1311_ops = {
	.recalc_rate	= clk_lg1311_recalc_rate,
	.round_rate	= clk_lg1k_round_rate,
	.set_rate	= clk_lg1k_set_rate,
};

static struct clk *
clk_register_lg1k(struct device *dev, char const *name, char const *parent_name,
                  unsigned long flags, struct clk_ops const *ops,
                  void __iomem *base, u32 const fix[])
{
	struct clk_lg1k *clk_lg1k;
	struct clk_init_data init_data;
	struct clk *clk;

	if (!(clk_lg1k = kmalloc(sizeof(struct clk_lg1k), GFP_KERNEL))) {
		pr_err("%s: could not allocate clk-lg1k\n", __func__);
		return ERR_PTR(-ENOMEM);
	}

	init_data.name = name;
	init_data.ops = ops;
	init_data.flags = flags | CLK_IS_BASIC;
	init_data.parent_names = &parent_name;
	init_data.num_parents = 1;

	clk_lg1k->hw.init = &init_data;
	clk_lg1k->base = base;
	clk_lg1k->fix[0] = fix[0];
	clk_lg1k->fix[1] = fix[1];

	clk = clk_register(dev, &clk_lg1k->hw);
	if (IS_ERR(clk))
		kfree(clk_lg1k);

	return clk;
}

static struct clk *
clk_register_lg1154(struct device *dev, char const *name,
                    char const *parent_name, unsigned long flags,
                    void __iomem *base, u32 const fix[])
{
	return clk_register_lg1k(dev, name, parent_name, flags, &clk_lg1154_ops,
	                         base, fix);
}

static struct clk *
clk_register_lg1156(struct device *dev, char const *name,
                    char const *parent_name, unsigned long flags,
                    void __iomem *base, u32 const fix[])
{
	return clk_register_lg1k(dev, name, parent_name, flags, &clk_lg1156_ops,
	                         base, fix);
}

static struct clk *
clk_register_lg1210(struct device *dev, char const *name,
                    char const *parent_name, unsigned long flags,
                    void __iomem *base, u32 const fix[])
{
	return clk_register_lg1k(dev, name, parent_name, flags, &clk_lg1210_ops,
	                         base, fix);
}

static struct clk *
clk_register_lg1311(struct device *dev, char const *name,
                    char const *parent_name, unsigned long flags,
                    void __iomem *base, u32 const fix[])
{
	return clk_register_lg1k(dev, name, parent_name, flags, &clk_lg1311_ops,
	                         base, fix);
}

static void __init clk_lg1154_of_setup(struct device_node *np)
{
	struct clk *clk;
	char const *clk_name = np->name;
	char const *parent_name;
	struct device_node *chip_node;
	void __iomem *chip_base;
	u32 npc_fix = 0;
	u32 nsc_fix = 0;
	u32 fix[2];

	of_property_read_string(np, "clock-output-names", &clk_name);
	parent_name = of_clk_get_parent_name(np, 0);
	of_property_read_u32(np, "npc-fix", &npc_fix);
	of_property_read_u32(np, "nsc-fix", &nsc_fix);

	fix[0] = 0;
	fix[1] = (npc_fix << 18) | (nsc_fix << 14);

	chip_node = of_find_node_by_name(NULL, "chip_ctrl");
	chip_base = of_iomap(chip_node, 0);
	
	if (!parent_name) {
		pr_err("%s: could not find parent clock name\n", __func__);
		return;
	}
	if (!chip_base) {
		pr_err("%s: could not find control address\n", __func__);
		return;
	}

	clk = clk_register_lg1154(NULL, clk_name, parent_name,
	                          CLK_GET_RATE_NOCACHE, chip_base, fix);
	if (!IS_ERR(clk))
		of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
CLK_OF_DECLARE(clk_lg1154, "lge,lg1154-clock", clk_lg1154_of_setup);

static void __init clk_lg1156_of_setup(struct device_node *np)
{
	struct clk *clk;
	char const *clk_name = np->name;
	char const *parent_name;
	struct device_node *chip_node;
	void __iomem *chip_base;
	u32 npc_fix = 0;
	u32 nsc_fix = 0;
	u32 fix[2];

	of_property_read_string(np, "clock-output-names", &clk_name);
	parent_name = of_clk_get_parent_name(np, 0);
	of_property_read_u32(np, "npc-fix", &npc_fix);
	of_property_read_u32(np, "nsc-fix", &nsc_fix);

	fix[0] = 0;
	fix[1] = (npc_fix << 18) | (nsc_fix << 14);

	chip_node = of_find_node_by_name(NULL, "chip_ctrl");
	chip_base = of_iomap(chip_node, 0);
	
	if (!parent_name) {
		pr_err("%s: could not find parent clock name\n", __func__);
		return;
	}
	if (!chip_base) {
		pr_err("%s: could not find control address\n", __func__);
		return;
	}

	clk = clk_register_lg1156(NULL, clk_name, parent_name,
	                          CLK_GET_RATE_NOCACHE, chip_base, fix);
	if (!IS_ERR(clk))
		of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
CLK_OF_DECLARE(clk_lg1156, "lge,lg1156-clock", clk_lg1156_of_setup);

static void __init clk_lg1210_of_setup(struct device_node *np)
{
	struct clk *clk;
	char const *clk_name = np->name;
	char const *parent_name;
	void __iomem *base;
	u32 fix[2];

	of_property_read_string(np, "clock-output-names", &clk_name);
	parent_name = of_clk_get_parent_name(np, 0);
	base = of_iomap(np, 0);
	of_property_read_u32_array(np, "fix", fix, 2);

	if (!parent_name) {
		pr_err("%s: could not find parent clock name\n", __func__);
		return;
	}
	if (!base) {
		pr_err("%s: could not find control address\n", __func__);
		return;
	}

	clk = clk_register_lg1210(NULL, clk_name, parent_name,
	                          CLK_GET_RATE_NOCACHE, base, fix);
	if (!IS_ERR(clk))
		of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
CLK_OF_DECLARE(clk_lg1210, "lge,lg1210-clock", clk_lg1210_of_setup);

static void __init clk_lg1311_of_setup(struct device_node *np)
{
	struct clk *clk;
	char const *clk_name = np->name;
	char const *parent_name;
	struct device_node *chip_node;
	void __iomem *chip_base;
	u32 npc_fix = 0;
	u32 nsc_fix = 0;
	u32 fix[2];

	of_property_read_string(np, "clock-output-names", &clk_name);
	parent_name = of_clk_get_parent_name(np, 0);
	of_property_read_u32(np, "npc-fix", &npc_fix);
	of_property_read_u32(np, "nsc-fix", &nsc_fix);

	fix[0] = 0;
	fix[1] = (npc_fix << 18) | (nsc_fix << 14);

	chip_node = of_find_node_by_name(NULL, "chip_ctrl");
	chip_base = of_iomap(chip_node, 0);
	
	if (!parent_name) {
		pr_err("%s: could not find parent clock name\n", __func__);
		return;
	}
	if (!chip_base) {
		pr_err("%s: could not find control address\n", __func__);
		return;
	}

	clk = clk_register_lg1311(NULL, clk_name, parent_name,
	                          CLK_GET_RATE_NOCACHE, chip_base, fix);
	if (!IS_ERR(clk))
		of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
CLK_OF_DECLARE(clk_lg1311, "lge,lg1311-clock", clk_lg1311_of_setup);
