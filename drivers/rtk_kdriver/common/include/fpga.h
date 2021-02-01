#ifndef MIPS
#include "eregdef.h"
#define eret \
mfc0 k0,C0_EPC;\
jr k0;\
rfe;
#define sync \
lw      r0,0xb801a020;
#define CR_IP2		0x00000400
#define CR_IP3		0x00000800
#define CR_IP4		0x00001000
#define CR_IP5		0x00002000
#define CR_IP6		0x00004000
#define CR_IP7		0x00008000
#else
#include "regdef.h"
#include "m32c0.h"
/*----- hardware registers names ---------------------*/
#define r0	$0	
#define r1	$at	
#define r2	$2	
#define r3	$3
#define r4	$4	
#define r5	$5
#define r6	$6
#define r7	$7
#define r8	$8	
#define r9	$9
#define r10	$10
#define r11	$11
#define r12	$12
#define r13	$13
#define r14	$14
#define r15	$15
#define r16	$16		
#define r17	$17
#define r18	$18
#define r19	$19
#define r20	$20
#define r21	$21
#define r22	$22
#define r23	$23
#define r24	$24		
#define r25	$25
#define r26	$26		
#define r27	$27
#define r28	$28		
#define r29	$29		
#define r30	$30		
#define r31	$31		
#endif

#define USER_PROG_START  0x80004000
#define EXCP_BEV0_COMMON 0x80000100
#define HW_INTVEC_BASE   0x80001000
#define HW_INTVEC_ADDR8  0x80001040 /* IP8 */
#define HW_INTVEC_ADDR9  0x80001044 /* IP9 */
#define HW_INTVEC_ADDR10 0x80001048 /* IP10 */
#define HW_INTVEC_ADDR11 0x8000104c /* IP11 */
#define HW_INTVEC_ADDR12 0x80001050 /* IP12 */
#define HW_INTVEC_ADDR13 0x80001054 /* IP13 */
#define HW_INTVEC_ADDR14 0x80001058 /* IP14 */
#define HW_INTVEC_ADDR15 0x8000105c /* IP15 */
#define SW_INT_RET_ADDR  0x80001060 /* IP0..7 */
#define TEST_PASS 0x80003000
#define TEST_FAIL 0x80003020
#define TEST_PASS_VCPU 0x80103000
#define TEST_FAIL_VCPU 0x80103020
#define TEST_PASS_ACPU 0x80203000
#define TEST_FAIL_ACPU 0x80203020
#define STACK_START 0x80004000
#define STACK_START_VCPU 0x80104000
#define STACK_START_ACPU 0x80204000
#define USER_PROG_START_VCPU  0x80104000
#define USER_PROG_START_ACPU  0x80204000
#define INIT_MIPS_CACHE       0x80000400 /* whole-chip gatesim */

/* for whole-chip interrupts */
#define HW_INTVEC_ADDR0_SCPU  0x80000300
#define HW_INTVEC_ADDR1_SCPU  0x80000304
#define HW_INTVEC_ADDR2_SCPU  0x80000308
#define HW_INTVEC_ADDR3_SCPU  0x8000030c
#define HW_INTVEC_ADDR4_SCPU  0x80000310
#define HW_INTVEC_ADDR5_SCPU  0x80000314
#define HW_INTVEC_ADDR6_SCPU  0x80000318
#define HW_INTVEC_ADDR7_SCPU  0x8000031c

#define HW_INTVEC_BASE_VCPU   0x80101000
#define HW_INTVEC_ADDR0_VCPU  0x80101040
#define HW_INTVEC_ADDR1_VCPU  0x80101044
#define HW_INTVEC_ADDR2_VCPU  0x80101048
#define HW_INTVEC_ADDR3_VCPU  0x8010104c
#define HW_INTVEC_ADDR4_VCPU  0x80101050
#define HW_INTVEC_ADDR5_VCPU  0x80101054
#define HW_INTVEC_ADDR6_VCPU  0x80101058
#define HW_INTVEC_ADDR7_VCPU  0x8010105c
#define HW_INTVEC_ADDR8_VCPU  0x80101060
#define HW_INTVEC_ADDR9_VCPU  0x80101064
#define HW_INTVEC_ADDR10_VCPU  0x80101068
#define HW_INTVEC_ADDR11_VCPU  0x8010106c
#define HW_INTVEC_ADDR12_VCPU  0x80101070
#define HW_INTVEC_ADDR13_VCPU  0x80101074
#define HW_INTVEC_ADDR14_VCPU  0x80101078
#define HW_INTVEC_ADDR15_VCPU  0x8010107c
#define SW_INT_RET_ADDR_VCPU   0x80101080

#define HW_INTVEC_BASE_ACPU   0x80201000
#define HW_INTVEC_ADDR0_ACPU  0x80201040
#define HW_INTVEC_ADDR1_ACPU  0x80201044
#define HW_INTVEC_ADDR2_ACPU  0x80201048
#define HW_INTVEC_ADDR3_ACPU  0x8020104c
#define HW_INTVEC_ADDR4_ACPU  0x80201050
#define HW_INTVEC_ADDR5_ACPU  0x80201054
#define HW_INTVEC_ADDR6_ACPU  0x80201058
#define HW_INTVEC_ADDR7_ACPU  0x8020105c
#define HW_INTVEC_ADDR8_ACPU  0x80201060
#define HW_INTVEC_ADDR9_ACPU  0x80201064
#define HW_INTVEC_ADDR10_ACPU  0x80201068
#define HW_INTVEC_ADDR11_ACPU  0x8020106c
#define HW_INTVEC_ADDR12_ACPU  0x80201070
#define HW_INTVEC_ADDR13_ACPU  0x80201074
#define HW_INTVEC_ADDR14_ACPU  0x80201078
#define HW_INTVEC_ADDR15_ACPU  0x8020107c
#define SW_INT_RET_ADDR_ACPU   0x80201080


#define C0_ESTATUS $0
#define C0_ECAUSE  $1
#define C0_INTVEC  $2
#define C3_CPUTAG  $16

#include "me_reg.h"
#include "vc_reg.h"
#include "ve_reg.h"
#include "dc_reg.h"
#include "se_reg.h"
#include "tvd_reg.h"
#include "tve_reg.h"
#include "aio_reg.h"
#include "adsp_reg.h"
#include "mcp_reg.h"
#include "ata0_reg.h"
#include "ata1_reg.h"
#include "cp_reg.h"
#include "usb_reg.h"
#include "sb1_reg.h"
#include "sb2_reg.h"
#include "mis_reg.h"
#include "sys_reg.h"
#include "vpfpga_vi_reg.h"	// for FPGA testing
#include "vpfpga_vo_reg.h"	// for FPGA testing
/* Physical Memory Map */
/*
  virtual address
bfc0_0180 - xxxx_xxxx exception handler bev=1 (uncached)in flash memory
bfc0_0160 - bfc0_017f sdram parameters
bfc0_0000 - xxxx_xxxx boot code (uncached) in flash memory



8000_4000 - xxxx_xxxx diag code
8000_3040 - 8000_4000 stack for C program
8000_3020 - 8000_303f test_fail
8000_3000 - 8000_301f test_pass
8000_1000 - xxxx_xxxx vectored interrupts
8000_0100 - 8000_017f exception handler bev=0 (shared)
8000_00c0 - 8000_00df exception handler bev=0 (ACPU)
8000_00a0 - 8000_00bf exception handler bev=0 (VCPU)
8000_0080 - 8000_009f exception handler bev=0 (MIPS)
8000_0000 - 
*/

/* bringup */
#define BU_TEST_GO_SCPU		0xa0002000
#define BU_TEST_GO_VCPU		0xa0102000
#define BU_TEST_GO_ACPU		0xa0202000

#define BU_TEST_RESULT_SCPU	0xa0002004
#define BU_TEST_RESULT_VCPU	0xa0102004
#define BU_TEST_RESULT_ACPU	0xa0202004

#define BU_COUNTER_SCPU		0xa0002008
#define BU_COUNTER_VCPU		0xa0102008
#define BU_COUNTER_ACPU		0xa0202008

#define BU_RETURN_ADDR_SCPU	0xa000200c
#define BU_RETURN_ADDR_VCPU	0xa010200c
#define BU_RETURN_ADDR_ACPU	0xa020200c

#define BU_VO_DISP_FRAME_CNT	0xa0102100
#define BU_VI_FIELD_CNT		0xa0102104

//Note: this macro will check CPU type.
#define BU_CHECK_CPU(index, reg1, reg2, reg3) \
     beq reg1, reg2, 1f; \
     nop; \
     mfc0 reg3, C0_PRID; \
     bne  reg3, 0xc601, 2f; \
     lui  r1, 0xa000; \
     mfc3 reg3, C3_CPUTAG; \
     bne reg3, 0x6b656e68, 2f; \
     lui  r1, 0xa020; \
     lui  r1, 0xa010; \
2:   ori r1, 0x2010; \
     sw  reg1, (r1); \
     sw  reg2, 4(r1); \
     li  reg1, index; \
     sw  reg1, 8(r1); \
     lw  reg1, (r1); \
     b DIAG_FAIL; \
     nop; \
1:   nop

//BU_PRINT_REG (reg1, tmpreg) 
// print reg1 value to address MSG_END.
#define BU_PRINT_REG(reg1, tmpreg) \
     mfc0 tmpreg, C0_PRID; \
     bne  tmpreg, 0xc601, 2f; \
     lui  r1, 0xa000; \
     mfc3 tmpreg, C3_CPUTAG; \
     bne tmpreg, 0x6b656e68, 2f; \
     lui  r1, 0xa020; \
     lui  r1, 0xa010; \
2:   ori r1, 0x2204; /*MSG_REG*/\
     sw  reg1, (r1); \
     nop

//BU_PRINT_INT (value, tmpreg) 
// print value to address MSG_END.
#define BU_PRINT_INT(value, tmpreg) \
     mfc0 tmpreg, C0_PRID; \
     bne  tmpreg, 0xc601, 2f; \
     lui  r1, 0xa000; \
     mfc3 tmpreg, C3_CPUTAG; \
     bne tmpreg, 0x6b656e68, 2f; \
     lui  r1, 0xa020; \
     lui  r1, 0xa010; \
2:   ori r1, 0x2200; /*MSG_INT*/\
     li  tmpreg, value; \
     sw  tmpreg, (r1); \
     nop

//Note: 2010 & 2014 is used for expected and actual data.
// 2018 is for index.
#define BU_CHECK_SCPU(index, reg1, reg2) \
     beq reg1, reg2, 1f; \
     nop; \
     la  r1, 0xa0002010; \
     sw  reg1, (r1); \
     sw  reg2, 4(r1); \
     li  reg1, index; \
     sw  reg1, 8(r1); \
     lw  reg1, (r1); \
     b DIAG_FAIL; \
     nop; \
1:   nop
     
#define BU_CHECK_VCPU(index, reg1, reg2) \
     beq reg1, reg2, 1f; \
     nop; \
     la  r1, 0xa0102010; \
     sw  reg1, (r1); \
     sw  reg2, 4(r1); \
     li  reg1, index; \
     sw  reg1, 8(r1); \
     lw  reg1, (r1); \
     b DIAG_FAIL; \
     nop; \
1:   nop
     
#define BU_CHECK_ACPU(index, reg1, reg2) \
     beq reg1, reg2, 1f; \
     nop; \
     la  r1, 0xa0202010; \
     sw  reg1, (r1); \
     sw  reg2, 4(r1); \
     li  reg1, index; \
     sw  reg1, 8(r1); \
     lw  reg1, (r1); \
     b DIAG_FAIL; \
     nop; \
1:   nop
     
/**/

#define FILL_CACHE_LINE .rept 8; .word 0x0; .endr;

#define DELAY(count,reg) \
	li	reg,count;\
9:	sub	reg,1;\
        bne	reg,r0,9b;\
        nop;\

// wait until reg shows matched value.
//use "ori zero, 0x8898" op=34008898 to distinguish
#define WAIT(addr,mask,value,reg1,reg2) \
	nop;\
	nop;\
	nop;\
	nop;\
	ori zero, 0x8898;\
8:	lw reg1, addr;\
	and reg1, mask;\
	li reg2, value;\
	bne reg1, reg2, 8b;\
	nop;\

#define INF_LOOP \
	ori	zero, 0x8898;\
7:	b	7b; \
	nop;	

#define INF_LOOP2 \
	nop;\
	ori	zero, 0x8898;\
7:	b	7b; \
	nop;	


   
#define REG_WR(addr,addr_reg,data,data_reg) \
	la	addr_reg,addr;  	    \
	li	data_reg,data;  	    \
	sw	data_reg,(addr_reg);  	    \

#define REG_RD(addr,addr_reg,data_reg) \
	la	addr_reg,addr;  	    \
	lw	data_reg,(addr_reg);	    \

#define PUSH_STACK() \
  	sw      t0, -4(sp);  \
  	sw      t1, -8(sp);  \
  	sw      t2, -12(sp); \
  	sw      t3, -16(sp); \
  	sw      t4, -20(sp); \
  	sw      t5, -24(sp); \
  	sw      t6, -28(sp); \
  	sw      t7, -32(sp); \
  	sw      t8, -36(sp); \
  	sw      t9, -40(sp); \
  	sw      s0, -44(sp); \
  	sw      s1, -48(sp); \
  	sw      s2, -52(sp); \
  	sw      s3, -56(sp); \
  	sw      s4, -60(sp); \
  	sw      s5, -64(sp); \
  	sw      s6, -68(sp); \
  	sw      s7, -72(sp); \
  	sw      a0, -76(sp); \
  	sw      a1, -80(sp); \
  	sw      a2, -84(sp); \
  	sw      a3, -88(sp); \
  	sw      v0, -92(sp); \
  	sw      v1, -96(sp); \
  	sw      AT, -100(sp);\
  	sw      ra, -104(sp);
	// ISR won't touch $sp and no need to save k0 and k1.

#define POP_STACK() \
  	lw      t0, -4(sp);  \
  	lw      t1, -8(sp);  \
  	lw      t2, -12(sp); \
  	lw      t3, -16(sp); \
  	lw      t4, -20(sp); \
  	lw      t5, -24(sp); \
  	lw      t6, -28(sp); \
  	lw      t7, -32(sp); \
  	lw      t8, -36(sp); \
  	lw      t9, -40(sp); \
  	lw      s0, -44(sp); \
  	lw      s1, -48(sp); \
  	lw      s2, -52(sp); \
  	lw      s3, -56(sp); \
  	lw      s4, -60(sp); \
  	lw      s5, -64(sp); \
  	lw      s6, -68(sp); \
  	lw      s7, -72(sp); \
  	lw      a0, -76(sp); \
  	lw      a1, -80(sp); \
  	lw      a2, -84(sp); \
  	lw      a3, -88(sp); \
  	lw      v0, -92(sp); \
  	lw      v1, -96(sp); \
  	lw      AT, -100(sp);\
  	lw      ra, -104(sp);

// write wr_val to reg, then read it back, compare with rd_val.
#define	CHECK_WR_REG(addr, wr_val, rd_val, mask, reg1, reg2, reg3) \
  	la	reg1, addr;			\
	li	reg2, wr_val;			\
	sw	reg2, (reg1);			\
	li	reg3, rd_val;			\
	lw	reg2, (reg1);			\
	and	reg2, mask;			\
	bne	reg2, reg3, DIAG_FAIL;		\
	nop
	
#define	BU_CHECK_WR_REG(addr, wr_val, rd_val, mask, reg1, reg2, reg3) \
  	la	reg1, addr;			\
	li	reg2, wr_val;			\
	sw	reg2, (reg1);			\
	li	reg3, rd_val;			\
	lw	reg2, (reg1);			\
	and	reg2, mask;			\
	BU_CHECK_CPU(addr&0xffff, reg2, reg3, reg1); \
	nop
	
// from from reg, then compare with rd_val.
// good for R/O reg, and Reset value check.
#define	CHECK_RD_REG(addr, rd_val, mask, reg1, reg2, reg3) \
  	la	reg1, addr;			\
	lw	reg2, (reg1);			\
	and	reg2, mask;			\
	li	reg3, rd_val;			\
	bne	reg2, reg3, DIAG_FAIL;		\
	nop
	
#define	BU_CHECK_RD_REG(addr, rd_val, mask, reg1, reg2, reg3) \
  	la	reg1, addr;			\
	lw	reg2, (reg1);			\
	and	reg2, mask;			\
	li	reg3, rd_val;			\
	BU_CHECK_CPU(addr&0xffff, reg2, reg3, reg1); \
	nop
	
//for whole-chip, multiple-CPUs: SCPU_SYNC_START
//assume SCPU is the first out of boot.
#define SYNC_START_ADDR  0xa0300000 //assume the 8 bytes starting from it is available.
#define SCPU_SYNC_START(addr, reg1, reg2) 	\
	la	reg1, addr;			\
	sw	zero, (reg1);			\
	sw	zero, 4(reg1);			\
1:	lw	reg2, (reg1);			\
	beq	reg2, zero, 1b;			\
	nop;					\
1:	lw	reg2, 4(reg1);			\
	beq	reg2, zero, 1b;			\
	nop

//for whole-chip, multiple-CPUs: ACPU_SYNC_START
#define ACPU_SYNC_START(addr, reg1, reg2) 	\
	WAIT(SB2_HD_SEM_reg, 0x1, 0x1, reg1, reg2); \
	la	reg1, addr;			\
	li	reg2, 0x1;			\
	sw	reg2, (reg1);			\
	la	reg2, SB2_HD_SEM_reg;		\
	sw	zero, (reg2);			\
1:	lw	reg2, 4(reg1);			\
	beq	reg2, zero, 1b;			\
	nop

//WAIT2: for some loop, the program only interested
	//in some fields, while other fields might
	//be different between C-model and RTL. In that
	//case, the cpu compare need to be turned off
	//temporarily. E.g., ACPU dma done register.
#define WAIT2(addr,mask,value,reg1,reg2) \
	nop;\
	nop;\
	nop;\
	nop;\
	nop;\
	ori zero, 0x00ff;\
8:	lw reg1, addr;\
	and reg1, mask;\
	li reg2, value;\
	bne reg1, reg2, 8b;\
	nop;\
	nop;\
	nop;\
	nop;\
	nop;\
	nop;\
	ori zero, 0x0011;\
	nop;\



//for whole-chip, multiple-CPUs: VCPU_SYNC_START
#define VCPU_SYNC_START(addr, reg1, reg2) 	\
	WAIT(SB2_HD_SEM_reg, 0x1, 0x1, reg1, reg2); \
	la	reg1, addr;			\
	li	reg2, 0x1;			\
	sw	reg2, 4(reg1);			\
	la	reg2, SB2_HD_SEM_reg;		\
	sw	zero, (reg2);			\
1:	lw	reg2, (reg1);			\
	beq	reg2, zero, 1b;			\
	nop
//global sync for all 3 CPUs
#define CPU_SYNC_START(reg1, reg2) 	\
	WAIT(SB2_HD_SEM_reg, 0x1, 0x1, reg1, reg2); \
	la	reg1, 0xb801a134;		\
	lw	reg2, (reg1);			\
	li	reg1, 0x3;			\
	bne	reg2, reg1, 1f;			\
	nop;					\
	and	reg2, zero;			\
1:	add	reg2, 1;			\
	la	reg1, 0xb801a134;		\
	sw	reg2, (reg1);			\
	la	reg2, SB2_HD_SEM_reg;		\
	sw	zero, (reg2);			\
	WAIT(0xb801a134, 0x3, 0x3, reg1, reg2);

//reset VE registers
#define RESET_VE_REG() \
	REG_WR(VE_CNTL_reg,       t2, 0xfffffffe, t4);	\
	REG_WR(VE_INT_STATUS_reg, t2, 0xfffffffe, t4);	\
	REG_WR(VE_INTEN_reg, 	  t2, 0xfffffffe, t4);	\
	REG_WR(VE_PCCNTL_reg, 	  t2, 0xa48888, t4);	\
	REG_WR(VE_PC0_reg,        t2, 0, t4);		\
	REG_WR(VE_PC1_reg,        t2, 0, t4);		\
	REG_WR(VE_PC2_reg,        t2, 0, t4);		\
	REG_WR(VE_DCTCNTL_reg,    t2, 0x6420, t4);	\
	REG_WR(VE_CODECPARAM_reg, t2, 0x7f, t4);	\
	REG_WR(VE_CODECCNTL_reg, t2, 0xbb1, t4);	\
	REG_WR(VE_CODECCNTL1_reg, t2, 0xfffffffe, t4);	\
	REG_WR(VE_CODECCNTL1_reg, t2, 0x41, t4);	\
	REG_WR(VE_DVPARAM_reg   , t2, 0, t4);		\
	REG_WR(VE_VLDTBLPTR_0_reg, t2, 0, t4);		\
	REG_WR(VE_VLDTBLPTR_1_reg, t2, 0, t4);		\
	REG_WR(VE_VLDTBLPTR_2_reg, t2, 0, t4);		\
	REG_WR(VE_VLDTBLPTR_3_reg, t2, 0, t4);		\
	REG_WR(VE_VLDESPPTR_0_reg, t2, 0, t4);		\
	REG_WR(VE_VLDESPPTR_1_reg, t2, 0, t4);		\
	REG_WR(VE_VLDESPPTR_2_reg, t2, 0, t4);		\
	REG_WR(VE_VLDESPPTR_3_reg, t2, 0, t4);		\
	REG_WR(VE_DECBITCNT_reg, t2, 0x400, t4);	\
	REG_WR(VE_BITSTCNT_reg, t2, 0, t4);		\
	REG_WR(VE_FILTCNTL_reg, t2, 0x8102108, t4);		\
	REG_WR(VE_FILTINIT_reg, t2, 0, t4);		\
	REG_WR(VE_CKCNTL_reg, t2, 0, t4);		\
	REG_WR(VE_CKDATA_reg, t2, 0, t4);		\
	REG_WR(VE_ADAPCNTL_reg, t2, 0, t4);		\
	REG_WR(VE_ALPHA_reg, t2, 0, t4);		\
	REG_WR(VE_DEBLKCNTL_reg, t2, 0x62, t4);		\
	REG_WR(VE_DCVAL_reg, t2, 0, t4);		\
	REG_WR(VE_BLKD_THR_reg, t2, 0, t4);		\
	REG_WR(VE_BLKD_WEIGHT_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_0_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_1_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_2_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_3_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_4_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_5_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_6_reg, t2, 0, t4);		\
	REG_WR(VE_TAPCOEFF_7_reg, t2, 0, t4);		\
        li       t0, VE_CNTL_codblk_mode(0x3)|VE_CNTL_write_data(0);\
        wrcodreg t0, VE_CNTL_inst;\
        li       t0, VE_CNTL_reset_ptr(1)|VE_CNTL_write_data(1);\
        wrcodreg t0, VE_CNTL_inst;\
        li       t0, VE_CNTL_reset_ptr(1)|VE_CNTL_write_data(0);\
        wrcodreg t0, VE_CNTL_inst
