#include <asm/fncpy.h>

extern void lg1k_sram_reset(void);
extern phys_addr_t lg1k_sram_phys(void __iomem *virt);
void *lg1k_sram_push_address(unsigned long size);

/* Macro to push a function to the internal SRAM, using the fncpy API */
#define lg1k_sram_push(funcp, size) ({				\
	typeof(&(funcp)) _res = NULL;				\
	void *_sram_address = lg1k_sram_push_address(size);	\
	if (_sram_address)					\
		_res = fncpy(_sram_address, &(funcp), size);	\
	_res;							\
})

