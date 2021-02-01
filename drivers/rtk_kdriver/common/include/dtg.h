
#define SET_DTG_80x80() \
	REG_WR(0xb8028000, t0, 0x00000000, t1) \
	REG_WR(0xb8028008, t0, 0x0000000c, t1) \
	REG_WR(0xb802800c, t0, 0x00780078, t1) \
	REG_WR(0xb8028010, t0, 0x00000002, t1) \
	REG_WR(0xb8028014, t0, 0x00000064, t1) \
	REG_WR(0xb8028018, t0, 0x00080058, t1) \
	REG_WR(0xb802801c, t0, 0x00030053, t1) \
	REG_WR(0xb8028028, t0, 0x00000004, t1) \
	REG_WR(0xb8028000, t0, 0x13010000, t1) 

#define SET_DTG_240x240() \
	REG_WR(0xb8028000, t0, 0x00000000, t1) \
	REG_WR(0xb8028008, t0, 0x0000000c, t1) \
	REG_WR(0xb802800c, t0, 0x01280128, t1) \
	REG_WR(0xb8028010, t0, 0x00000002, t1) \
	REG_WR(0xb8028014, t0, 0x00000128, t1) \
	REG_WR(0xb8028018, t0, 0x00100100, t1) \
	REG_WR(0xb802801c, t0, 0x000300f3, t1) \
	REG_WR(0xb8028028, t0, 0x00000004, t1) \
	REG_WR(0xb8028000, t0, 0x13010000, t1) 

#define SET_DTG_720x480() \
	REG_WR(0xb8028000, t0, 0x00000000, t1) \
	REG_WR(0xb8028008, t0, 0x0000001f, t1) \
	REG_WR(0xb802800c, t0, 0x03000300, t1) \
	REG_WR(0xb8028010, t0, 0x00000002, t1) \
	REG_WR(0xb8028014, t0, 0x00000200, t1) \
	REG_WR(0xb8028018, t0, 0x001002e0, t1) \
	REG_WR(0xb802801c, t0, 0x000301e3, t1) \
	REG_WR(0xb8028028, t0, 0x00000004, t1) \
	REG_WR(0xb8028000, t0, 0x13010000, t1) 

#define SET_DTG_1024x1024() \
	REG_WR(0xb8028000, t0, 0x00000000, t1) \
	REG_WR(0xb8028008, t0, 0x0000001f, t1) \
	REG_WR(0xb802800c, t0, 0x04500450, t1) \
	REG_WR(0xb8028010, t0, 0x00000005, t1) \
	REG_WR(0xb8028014, t0, 0x00000450, t1) \
	REG_WR(0xb8028018, t0, 0x00350435, t1) \
	REG_WR(0xb802801c, t0, 0x00280428, t1) \
	REG_WR(0xb8028028, t0, 0x00000004, t1) \
	REG_WR(0xb8028000, t0, 0x13010000, t1) 

#define SET_DTG_1280x1280() \
	REG_WR(0xb8028000, t0, 0x00000000, t1) \
	REG_WR(0xb8028008, t0, 0x0000001f, t1) \
	REG_WR(0xb802800c, t0, 0x05500550, t1) \
	REG_WR(0xb8028010, t0, 0x00000005, t1) \
	REG_WR(0xb8028014, t0, 0x00000550, t1) \
	REG_WR(0xb8028018, t0, 0x00350535, t1) \
	REG_WR(0xb802801c, t0, 0x00280528, t1) \
	REG_WR(0xb8028028, t0, 0x00000004, t1) \
	REG_WR(0xb8028000, t0, 0x13010000, t1) 

#define SET_DTG(width, height) \
	REG_WR(0xb8028110, t0, width, t1) \
	REG_WR(0xb8028114, t0, height, t1) \
	REG_WR(0xb8028118, t0, width, t1) \
	REG_WR(0xb802811c, t0, height, t1) \
	REG_WR(0xb8028120, t0, width, t1) \
	REG_WR(0xb8028124, t0, height, t1) \
	REG_WR(0xb8028000, t0, 0x1, t1) \
	REG_WR(0xb8028008, t0, 0x0000000a, t1) \
	REG_WR(0xb8028010, t0, 0x00000004, t1) \
	addi t1, r0, 32; \
	sll  t1, t1, 16; \
	addi t1, r0, width; \
	addi t1, t1, 32; \
	li   t0, 0xb8028018; \
	sw   t1, (t0); \
	add  t2, t1, 63; \
	sll  t3, t2, 16; \
	or   t3, t2, t3; \
	li   t0, 0xb802800c; \
	sw   t3, (t0); \
	addi t1, r0, 16; \
	sll  t1, t1, 16; \
	addi t1, r0, height; \
	addi t1, t1, 16; \
	li   t0, 0xb802801c; \
	sw   t1, (t0); \
	add  t2, t1, 15; \
	li   t0, 0xb8028014; \
	sw   t2, (t0); \
	REG_WR(0xb8028028, t0, 0x00000004, t1) \
	REG_WR(0xb8028000, t0, 0x13010000, t1)

