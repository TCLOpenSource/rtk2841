#include <linux/linkage.h>

ENTRY(__smc)
	push	{r4-r7,lr}
	ldm	r0, {r0-r7}
	isb
	dsb
	.arch_extension sec
	smc	#0
	pop	{r4-r7,pc}
ENDPROC(__smc)
