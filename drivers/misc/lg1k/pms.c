#include <linux/kernel.h>

#include <linux/errno.h>
#include <linux/lg1k/pms.h>

static struct lg1k_pms_ops const *pms_ops;

int lg1k_pms_set_ops(struct lg1k_pms_ops const *ops)
{
	if (pms_ops && ops) {
		pr_err("%s: overriding is not supported\n", __func__);
		return -EBUSY;
	}

	pms_ops = ops;

	return 0;
}

int lg1k_pms_get_cpufreq(int cpu)
{
	if (pms_ops && pms_ops->get_cpufreq)
		return pms_ops->get_cpufreq(cpu);
	return -ENOSYS;
}
EXPORT_SYMBOL(lg1k_pms_get_cpufreq);

int lg1k_pms_set_cpufreq(int cpu, int kHz)
{
	if (pms_ops && pms_ops->set_cpufreq)
		return pms_ops->set_cpufreq(cpu, kHz);
	return -ENOSYS;
}
EXPORT_SYMBOL(lg1k_pms_set_cpufreq);

int lg1k_pms_get_cpuvolt(int cpu)
{
	if (pms_ops && pms_ops->get_cpuvolt)
		return pms_ops->get_cpuvolt(cpu);
	return -ENOSYS;
}
EXPORT_SYMBOL(lg1k_pms_get_cpuvolt);

int lg1k_pms_set_cpuvolt(int cpu, int uV)
{
	if (pms_ops && pms_ops->set_cpuvolt)
		return pms_ops->set_cpuvolt(cpu, uV);
	return -ENOSYS;
}
EXPORT_SYMBOL(lg1k_pms_set_cpuvolt);

int lg1k_pms_get_hotplug(int cpu)
{
	if (pms_ops && pms_ops->get_hotplug)
		return pms_ops->get_hotplug(cpu);
	return -ENOSYS;
}
EXPORT_SYMBOL(lg1k_pms_get_hotplug);

int lg1k_pms_set_hotplug(int cpu, int on)
{
	if (pms_ops && pms_ops->set_hotplug)
		return pms_ops->set_hotplug(cpu, on);
	return -ENOSYS;
}
EXPORT_SYMBOL(lg1k_pms_set_hotplug);
