#define SRCCPY_MEM_INI(start_addr, end_addr, ini_val, reg1, reg2) \
	la	reg2, ini_val; \
	la	reg1, start_addr|0x80000000; \
SRCCPY_MEM_INITIAL: \
	sw	reg2, (reg1); \
	addi	reg1, 0x4; \
	bne	reg1, (end_addr+4)|0x80000000, SRCCPY_MEM_INITIAL; \
	nop;

