/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/export.h>
#include <linux/clk.h>

#include <mach/clock.h>

//static LIST_HEAD(clocks);
//static DEFINE_MUTEX(clocks_mutex);
//static DEFINE_SPINLOCK(clockfw_lock);

//static struct clk_functions *arch_clock;

/*
 * Standard clock functions defined in include/linux/clk.h
 */

int clk_enable(struct clk *clk)
{
#if (1)	//TODO
	return 0;
#else
	unsigned long flags;
	int ret;

	if (clk == NULL || IS_ERR(clk))
		return -EINVAL;

	if (!arch_clock || !arch_clock->clk_enable)
		return -EINVAL;

	spin_lock_irqsave(&clockfw_lock, flags);
	ret = arch_clock->clk_enable(clk);
	spin_unlock_irqrestore(&clockfw_lock, flags);

	return ret;
#endif
}
EXPORT_SYMBOL(clk_enable);

void clk_disable(struct clk *clk)
{
#if (0)	//TODO
	unsigned long flags;

	if (clk == NULL || IS_ERR(clk))
		return;

	if (!arch_clock || !arch_clock->clk_disable)
		return;

	spin_lock_irqsave(&clockfw_lock, flags);
	if (clk->usecount == 0) {
		pr_err("Trying disable clock %s with 0 usecount\n",
		       clk->name);
		WARN_ON(1);
		goto out;
	}

	arch_clock->clk_disable(clk);

out:
	spin_unlock_irqrestore(&clockfw_lock, flags);
#endif
}
EXPORT_SYMBOL(clk_disable);

unsigned long clk_get_rate(struct clk *clk)
{
#if (1)	//TODO
	return 0;
#else
	unsigned long flags;
	unsigned long ret;

	if (clk == NULL || IS_ERR(clk))
		return 0;

	spin_lock_irqsave(&clockfw_lock, flags);
	ret = clk->rate;
	spin_unlock_irqrestore(&clockfw_lock, flags);

	return ret;
#endif
}
EXPORT_SYMBOL(clk_get_rate);

/*
 * Optional clock functions defined in include/linux/clk.h
 */

long clk_round_rate(struct clk *clk, unsigned long rate)
{
#if (1)	//TODO
	return 0;
#else
	unsigned long flags;
	long ret;

	if (clk == NULL || IS_ERR(clk))
		return 0;

	if (!arch_clock || !arch_clock->clk_round_rate)
		return 0;

	spin_lock_irqsave(&clockfw_lock, flags);
	ret = arch_clock->clk_round_rate(clk, rate);
	spin_unlock_irqrestore(&clockfw_lock, flags);

	return ret;
#endif
}
EXPORT_SYMBOL(clk_round_rate);

int clk_set_rate(struct clk *clk, unsigned long rate)
{
#if (1)	//TODO
	return 0;
#else
	unsigned long flags;
	int ret = -EINVAL;

	if (clk == NULL || IS_ERR(clk))
		return ret;

	if (!arch_clock || !arch_clock->clk_set_rate)
		return ret;

	spin_lock_irqsave(&clockfw_lock, flags);
	ret = arch_clock->clk_set_rate(clk, rate);
	if (ret == 0)
		propagate_rate(clk);
	spin_unlock_irqrestore(&clockfw_lock, flags);

	return ret;
#endif
}
EXPORT_SYMBOL(clk_set_rate);

int clk_set_parent(struct clk *clk, struct clk *parent)
{
#if (1)	//TODO
	return 0;
#else
	unsigned long flags;
	int ret = -EINVAL;

	if (clk == NULL || IS_ERR(clk) || parent == NULL || IS_ERR(parent))
		return ret;

	if (!arch_clock || !arch_clock->clk_set_parent)
		return ret;

	spin_lock_irqsave(&clockfw_lock, flags);
	if (clk->usecount == 0) {
		ret = arch_clock->clk_set_parent(clk, parent);
		if (ret == 0)
			propagate_rate(clk);
	} else
		ret = -EBUSY;
	spin_unlock_irqrestore(&clockfw_lock, flags);

	return ret;
#endif
}
EXPORT_SYMBOL(clk_set_parent);

struct clk *clk_get_parent(struct clk *clk)
{
	return clk->parent;
}
EXPORT_SYMBOL(clk_get_parent);

void clk_put(struct clk *clk)
{
}

struct clk *clk_get(struct device *dev, const char *con_id)
{
	return 0;
}
