#ifndef __ARCH_LG115X_SMC_H
#define __ARCH_LG115X_SMC_H

struct smc_param {
	unsigned long param[8];
};


extern void lg115x_smc(struct smc_param const *param);


#endif	/* __ARCH_LG115X_SMC_H */
