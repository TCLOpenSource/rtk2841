#ifndef	__LINUX_LG1K_PMS_H
#define	__LINUX_LG1K_PMS_H

struct lg1k_pms_ops {
	int (*get_cpufreq)(int cpu);
	int (*set_cpufreq)(int cpu, int kHz);
	int (*get_cpuvolt)(int cpu);
	int (*set_cpuvolt)(int cpu, int uV);
	int (*get_hotplug)(int cpu);
	int (*set_hotplug)(int cpu, int on);
};

extern int lg1k_pms_set_ops(struct lg1k_pms_ops const *ops);

extern int lg1k_pms_get_cpufreq(int cpu);
extern int lg1k_pms_set_cpufreq(int cpu, int kHz);
extern int lg1k_pms_get_cpuvolt(int cpu);
extern int lg1k_pms_set_cpuvolt(int cpu, int uV);
extern int lg1k_pms_get_hotplug(int cpu);
extern int lg1k_pms_set_hotplug(int cpu, int on);

#endif	/* __LINUX_LG1K_PMS_H */
