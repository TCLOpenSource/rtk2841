#include <linux/linkage.h>
#include <linux/init.h>

#include <asm/memory.h>

__vector_table:
	b	__reset	@ reset
	b	.	@ undefined instruction
	b	.	@ SVC
	b	.	@ prefetch abort
	b	.	@ data abort
	nop		@ reserved
	b	.	@ IRQ
	b	.	@ FIQ

__reset:
	mrc	p15, 0, r0, c1, c1, 2	@ read NSACR
	orr	r0, r0, #0x00040000	@ NS-control to ACTLR.SMP bit
	orr	r0, r0, #0x00000800	@ NS-control to CP11
	orr	r0, r0, #0x00000400	@ NS-control to CP10
	mcr	p15, 0, r0, c1, c1, 2	@ write-back to NSACR

	mrc	p15, 4, r0, c15, c0, 0	@ read CBAR
	add	r0, r0, #0x2000		@ r0: base of GIC CPU interface

	ldr	r1, [r0, #0x000]	@ read GICC_CTLR
	orr	r1, r1, #0x00000008	@ FIQEn: signal group 0 IRQs using FIQ
	orr	r1, r1, #0x00000002	@ EnableGrp1: signaling group 1 IRQs
	orr	r1, r1, #0x00000001	@ EnableGrp0: signaling group 0 IRQs
	str	r1, [r0, #0x000]	@ write-back to GICC_CTLR

	mov	r1, #0x000000f0		@ GICC_PMR: support 16 levels
	str	r1, [r0, #0x004]	@ write to GICC_PMR

	mrc	p15, 0, r0, c1, c1, 0	@ read SCR
	orr	r0, r0, #0x00000004	@ FIQs taken in monitor mode
	orr	r0, r0, #0x00000001	@ switch to non-secure mode
	mcr	p15, 0, r0, c1, c1, 0	@ write-back to SCR

	ldr	r0, 2f
1:	ldr	lr, [r0, #0x02dc]	@ get jump address
	cmp	lr, #0x0000
	beq	1b

	mov	pc, lr

2:	.long	0xfd300000		@ physical base address of core_ctrl
3:	.long	. - __vector_table

/*
 * Function to install the low-vector table and related code to support
 * power-recycled hotplug for secondary CPU(s).
 */
ENTRY(lg1k_smp_secondary_prepare)	@ r0: virt: target address
	ldr	r1, =__vector_table	@ r1: source address
	ldr	r2, 3b			@ r2: source size

4:	ldr	r3, [r1], #4		@ r3: buffer
	str	r3, [r0], #4
	subs	r2, r2, #4
	bne	4b

	mov	pc, lr
ENDPROC(lg1k_smp_secondary_prepare)

/*
 * Entry point for secondary CPUs. This provides a "holding pen" into
 * which all secondary cores are held until we're ready for them to initialise.
 */
ENTRY(lg1k_smp_secondary_startup)
	mrc	p15, 0, r0, c0, c0, 5	@ read MPIDR
	and	r0, r0, #0x0f		@ extract CPU ID

	ldr	r1, 2b
5:	ldr	r2, [r1, #0x02e0]	@ get boot CPU ID
	cmp	r2, r0
	bne	5b

	/*
	 * we've been released from the holding pen: secondary_stack
	 * should now contain the SVC stack for this core
	 */
	b	secondary_startup
ENDPROC(lg1k_smp_secondary_startup)
