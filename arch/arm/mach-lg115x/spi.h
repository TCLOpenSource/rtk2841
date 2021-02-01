#ifndef __ARCH_LG115X_SPI_H
#define __ARCH_LG115X_SPI_H

#ifndef CONFIG_SPI_PL022

static inline void lg115x_init_spi(void)
{
}

#else	/* CONFIG_SPI_PL022 */

#include <linux/init.h>

extern void __init lg115x_init_spi(void);

#endif	/* CONFIG_SPI_PL022 */

#endif	/* __ARCH_LG115X_SPI_H */
