#include <linux/kernel.h>

#include "smc.h"

extern int __smc(struct smc_param const *param);

void lg115x_smc(struct smc_param const *param)
{
	if(param)
		__smc(param);
}
