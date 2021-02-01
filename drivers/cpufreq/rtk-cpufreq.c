/*
 * Copyright (C) 2012 Freescale Semiconductor, Inc.
 *
 * The OPP code in function cpu0_set_target() is reused from
 * drivers/cpufreq/omap-cpufreq.c
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/cpu.h>
#include <linux/cpufreq.h>
#include <linux/err.h>
#include <linux/module.h>
#include <linux/slab.h>

#include <rtk_kdriver/rtk_clock.h>
#include <rtk_kdriver/rtk_thermal_sensor.h>
#include <mach/platform.h>

static int rtk_cpufreq_init(struct cpufreq_policy *policy);

static struct cpufreq_frequency_table *freq_table;

static struct clk *cpu_clk;
#ifdef CONFIG_REALTEK_POWER_CUT
static DEFINE_MUTEX(cpufreq_lock);
#endif

static int rtk_verify_speed(struct cpufreq_policy *policy)
{
	return cpufreq_frequency_table_verify(policy, freq_table);
}

static unsigned int rtk_get_speed(unsigned int cpu)
{
	return __rtk_clk_get_rate(cpu_clk);
}

void cpu_freq_lock(void)
{
#ifdef CONFIG_REALTEK_POWER_CUT
	mutex_lock(&cpufreq_lock);
#endif
}

void cpu_freq_unlock(void)
{
#ifdef CONFIG_REALTEK_POWER_CUT
	mutex_unlock(&cpufreq_lock);
#endif
}

static int rtk_set_target(struct cpufreq_policy *policy,
			   unsigned int target_freq, unsigned int relation)
{
	struct cpufreq_freqs freqs;
	unsigned long freq_kHz;
	unsigned int index, cpu;
	int i;
	int ret;

	/*if(is_platform_reset_freq())
	{
		__rtk_free_cpufreq_table(&freq_table);
		__rtk_init_cpufreq_table(&freq_table);
		rtk_cpufreq_init(policy);
		clear_platform_reset_freq();
	}*/

	ret = cpufreq_frequency_table_target(policy, freq_table, target_freq,
					     relation, &index);
	if (ret) {
		pr_err("failed to match target freqency %d: %d\n",
		       target_freq, ret);
		return ret;
	}

	freq_kHz = freq_table[index].frequency;

	freqs.new = freq_kHz;
	freqs.old = __rtk_clk_get_rate(cpu_clk);

	if (freqs.old == freqs.new)
		return 0;


	cpufreq_freq_transition_begin(policy, &freqs);

	for (i = 0; freq_table[i].frequency != CPUFREQ_TABLE_END; i++) {
		if (freq_table[i].frequency == CPUFREQ_ENTRY_INVALID)
			continue;

		if (freqs.new == freq_table[i].frequency)
			break;
	}

	if (freqs.new != freq_table[i].frequency)
		return -ENOTSUPP;
	cpu_freq_lock();
	ret = __rtk_clk_set_rate(cpu_clk, freqs.new);
	cpu_freq_unlock();
	if (ret) {
		pr_err("failed to set clock rate: %d\n", ret);
		return ret;
	}

	cpufreq_freq_transition_end(policy, &freqs,0);

#if 0
	for_each_online_cpu(cpu) {
		freqs.cpu = cpu;
		cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
	}
#endif
	return 0;
}

static int rtk_cpufreq_init(struct cpufreq_policy *policy)
{
	int ret;

//	if (policy->cpu != 0)
//		return -EINVAL;


	ret = cpufreq_frequency_table_cpuinfo(policy, freq_table);

	if (ret) {
		pr_err("invalid frequency table: %d\n", ret);
		return ret;
	}

	cpu_clk->rate = policy->cpuinfo.max_freq;
	policy->cpuinfo.transition_latency = 10000;
	policy->cur = __rtk_clk_get_rate(cpu_clk);

	/*
	 * The driver only supports the SMP configuartion where all processors
	 * share the clock and voltage and clock.  Use cpufreq affected_cpus
	 * interface to have all CPUs scaled together.
	 */
	policy->shared_type = CPUFREQ_SHARED_TYPE_ANY;
	cpumask_setall(policy->cpus);
	cpufreq_generic_init(policy, freq_table, policy->cpuinfo.transition_latency );
	//cpufreq_frequency_table_get_attr(freq_table, policy->cpu);
	cpufreq_table_validate_and_show(policy, freq_table);
	printk("Rtk cpu frequency driver init successfully\n");

	return 0;
}

static int rtk_cpufreq_exit(struct cpufreq_policy *policy)
{
	//cpufreq_frequency_table_put_attr(policy->cpu);

	return 0;
}

static struct freq_attr *rtk_cpufreq_attr[] = {
	&cpufreq_freq_attr_scaling_available_freqs,
	NULL,
};

static struct cpufreq_driver rtk_cpufreq_driver = {
	.flags = CPUFREQ_STICKY,
	.verify = rtk_verify_speed,
	.target = rtk_set_target,
	.get = rtk_get_speed,
	.init = rtk_cpufreq_init,
	.exit = rtk_cpufreq_exit,
	.name = "realtek_cpufreq",
	.attr = rtk_cpufreq_attr,
};

static int rtk_cpufreq_driver_init(void)
{
	int ret;

	cpu_clk = __rtk_clk_get(NULL, "cpu_clk");
	if (IS_ERR(cpu_clk)) {
		ret = PTR_ERR(cpu_clk);
		pr_err("failed to get rtk clock: %d\n", ret);
		goto out_put_node;
	}

	ret = __rtk_init_cpufreq_table(&freq_table);
	if (ret) {
		pr_err("failed to init cpufreq table: %d\n", ret);
		goto out_put_node;
	}

	ret = cpufreq_register_driver(&rtk_cpufreq_driver);
	if (ret) {
		pr_err("failed register driver: %d\n", ret);
		goto out_free_table;
	}

	return 0;

out_free_table:
out_put_node:
	__rtk_free_cpufreq_table(&freq_table);
	return ret;
}

fs_initcall(rtk_cpufreq_driver_init);

MODULE_AUTHOR("davidwang <davidwang@realtek.com>");
MODULE_DESCRIPTION("realtek cpufreq driver");
MODULE_LICENSE("GPL");
