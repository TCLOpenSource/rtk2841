#include <linux/linkage.h>

.arch_extension sec


ENTRY(__smc)
	push	{r4-r7,lr}
	ldm	r0, {r0-r7}
	isb
	dsb
	smc	#0
	pop	{r4-r7,pc}
ENDPROC(__smc)
