#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#ifndef MIPS

  #include "eregdef.h"

  #define eret \
      mfc0 k0,C0_EPC;\
      jr   k0;\
      rfe;
  
  #define sync \
      lw  r0, 0xb801a020;
  
  #define CR_IP2    0x00000400
  #define CR_IP3    0x00000800
  #define CR_IP4    0x00001000
  #define CR_IP5    0x00002000
  #define CR_IP6    0x00004000
  #define CR_IP7    0x00008000
  
#else
  
  #include "regdef.h"
  #include "m32c0.h"

  /*----- hardware registers names ---------------------*/
  #define r0     $0    
  #define r1     $at    
  #define r2     $2    
  #define r3     $3
  #define r4     $4    
  #define r5     $5
  #define r6     $6
  #define r7     $7
  #define r8     $8    
  #define r9     $9
  #define r10    $10
  #define r11    $11
  #define r12    $12
  #define r13    $13
  #define r14    $14
  #define r15    $15
  #define r16    $16        
  #define r17    $17
  #define r18    $18
  #define r19    $19
  #define r20    $20
  #define r21    $21
  #define r22    $22
  #define r23    $23
  #define r24    $24        
  #define r25    $25
  #define r26    $26        
  #define r27    $27
  #define r28    $28        
  #define r29    $29        
  #define r30    $30        
  #define r31    $31        
#endif
#define TEST_END 0x82100000
#define EXCP_BEV0_COMMON       0x80000100
#define GIC_CONFIG_START       0x80000A00
#define USER_PROG_START        0x80004000

#define TEST_PASS              0x80003000
#define TEST_FAIL              0x80003020
#define TEST_PASS_SCPU         TEST_PASS
#define TEST_FAIL_SCPU         TEST_FAIL
#define TEST_PASS_VCPU         0x80103000
#define TEST_FAIL_VCPU         0x80103020
#define TEST_PASS_ACPU         0x80203000
#define TEST_FAIL_ACPU         0x80203020
#define TEST_PASS_KCPU         0x80303000
#define TEST_FAIL_KCPU         0x80303020

#define STACK_START            0x80004000
#define STACK_START_VCPU       0x80104000
#define STACK_START_ACPU       0x80204000
#define STACK_START_KCPU       0x80304000
#define USER_PROG_START_SCPU   0x80004000
#define USER_PROG_START_VCPU   0x80104000
#define USER_PROG_START_ACPU   0x80204000
#define USER_PROG_START_KCPU   0x80304000

#define INIT_MIPS_CACHE        0x80000400  /* whole-chip gatesim */

/**********************************************************/
/* single CPU - IRQ                                       */
/**********************************************************/
#define HW_INTVEC_BASE         0x80001000
#define HW_INTVEC_ADDR0        0x80001040                      //IP0
#define HW_INTVEC_ADDR1        (HW_INTVEC_ADDR0      + 0x04)  //IP1
#define HW_INTVEC_ADDR2        (HW_INTVEC_ADDR1      + 0x04)  //IP2
#define HW_INTVEC_ADDR3        (HW_INTVEC_ADDR2      + 0x04)  //IP3
#define HW_INTVEC_ADDR4        (HW_INTVEC_ADDR3      + 0x04)  //IP4
#define HW_INTVEC_ADDR5        (HW_INTVEC_ADDR4      + 0x04)  //IP5
#define HW_INTVEC_ADDR6        (HW_INTVEC_ADDR5      + 0x04)  //IP6
#define HW_INTVEC_ADDR7        (HW_INTVEC_ADDR6      + 0x04)  //IP7
#define HW_INTVEC_ADDR8        (HW_INTVEC_ADDR7      + 0x04)  //IP8
#define HW_INTVEC_ADDR9        (HW_INTVEC_ADDR8      + 0x04)  //IP9
#define HW_INTVEC_ADDR10       (HW_INTVEC_ADDR9      + 0x04)  //IP10
#define HW_INTVEC_ADDR11       (HW_INTVEC_ADDR10     + 0x04)  //IP11
#define HW_INTVEC_ADDR12       (HW_INTVEC_ADDR11     + 0x04)  //IP12
#define HW_INTVEC_ADDR13       (HW_INTVEC_ADDR12     + 0x04)  //IP13
#define HW_INTVEC_ADDR14       (HW_INTVEC_ADDR13     + 0x04)  //IP14
#define HW_INTVEC_ADDR15       (HW_INTVEC_ADDR14     + 0x04)  //IP15
#define SW_INT_RET_ADDR        (HW_INTVEC_ADDR15     + 0x04)  //SW

/*VCPU*/
#define HW_INTVEC_BASE_VCPU     0x80101000
#define HW_INTVEC_ADDR0_VCPU    0x80101040                      //IP0
#define HW_INTVEC_ADDR1_VCPU    (HW_INTVEC_ADDR0_VCPU  + 0x04)  //IP1
#define HW_INTVEC_ADDR2_VCPU    (HW_INTVEC_ADDR1_VCPU  + 0x04)  //IP2
#define HW_INTVEC_ADDR3_VCPU    (HW_INTVEC_ADDR2_VCPU  + 0x04)  //IP3
#define HW_INTVEC_ADDR4_VCPU    (HW_INTVEC_ADDR3_VCPU  + 0x04)  //IP4
#define HW_INTVEC_ADDR5_VCPU    (HW_INTVEC_ADDR4_VCPU  + 0x04)  //IP5
#define HW_INTVEC_ADDR6_VCPU    (HW_INTVEC_ADDR5_VCPU  + 0x04)  //IP6
#define HW_INTVEC_ADDR7_VCPU    (HW_INTVEC_ADDR6_VCPU  + 0x04)  //IP7
#define HW_INTVEC_ADDR8_VCPU    (HW_INTVEC_ADDR7_VCPU  + 0x04)  //IP8
#define HW_INTVEC_ADDR9_VCPU    (HW_INTVEC_ADDR8_VCPU  + 0x04)  //IP9
#define HW_INTVEC_ADDR10_VCPU   (HW_INTVEC_ADDR9_VCPU  + 0x04)  //IP10
#define HW_INTVEC_ADDR11_VCPU   (HW_INTVEC_ADDR10_VCPU + 0x04)  //IP11
#define HW_INTVEC_ADDR12_VCPU   (HW_INTVEC_ADDR11_VCPU + 0x04)  //IP12
#define HW_INTVEC_ADDR13_VCPU   (HW_INTVEC_ADDR12_VCPU + 0x04)  //IP13
#define HW_INTVEC_ADDR14_VCPU   (HW_INTVEC_ADDR13_VCPU + 0x04)  //IP14
#define HW_INTVEC_ADDR15_VCPU   (HW_INTVEC_ADDR14_VCPU + 0x04)  //IP15
#define SW_INT_RET_ADDR_VCPU    (HW_INTVEC_ADDR15_VCPU + 0x04)  //SW

/*ACPU*/
#define HW_INTVEC_BASE_ACPU     0x80201000
#define HW_INTVEC_ADDR0_ACPU    0x80201040                      //IP0
#define HW_INTVEC_ADDR1_ACPU    (HW_INTVEC_ADDR0_ACPU  + 0x04)  //IP1
#define HW_INTVEC_ADDR2_ACPU    (HW_INTVEC_ADDR1_ACPU  + 0x04)  //IP2
#define HW_INTVEC_ADDR3_ACPU    (HW_INTVEC_ADDR2_ACPU  + 0x04)  //IP3
#define HW_INTVEC_ADDR4_ACPU    (HW_INTVEC_ADDR3_ACPU  + 0x04)  //IP4
#define HW_INTVEC_ADDR5_ACPU    (HW_INTVEC_ADDR4_ACPU  + 0x04)  //IP5
#define HW_INTVEC_ADDR6_ACPU    (HW_INTVEC_ADDR5_ACPU  + 0x04)  //IP6
#define HW_INTVEC_ADDR7_ACPU    (HW_INTVEC_ADDR6_ACPU  + 0x04)  //IP7
#define HW_INTVEC_ADDR8_ACPU    (HW_INTVEC_ADDR7_ACPU  + 0x04)  //IP8
#define HW_INTVEC_ADDR9_ACPU    (HW_INTVEC_ADDR8_ACPU  + 0x04)  //IP9
#define HW_INTVEC_ADDR10_ACPU   (HW_INTVEC_ADDR9_ACPU  + 0x04)  //IP10
#define HW_INTVEC_ADDR11_ACPU   (HW_INTVEC_ADDR10_ACPU + 0x04)  //IP11
#define HW_INTVEC_ADDR12_ACPU   (HW_INTVEC_ADDR11_ACPU + 0x04)  //IP12
#define HW_INTVEC_ADDR13_ACPU   (HW_INTVEC_ADDR12_ACPU + 0x04)  //IP13
#define HW_INTVEC_ADDR14_ACPU   (HW_INTVEC_ADDR13_ACPU + 0x04)  //IP14
#define HW_INTVEC_ADDR15_ACPU   (HW_INTVEC_ADDR14_ACPU + 0x04)  //IP15
#define SW_INT_RET_ADDR_ACPU    (HW_INTVEC_ADDR15_ACPU + 0x04)  //SW

/*KCPU*/
#define HW_BEV_KCPU_BASE        0x80300080
#define HW_INTVEC_BASE_KCPU     0x80301000
#define HW_INTVEC_ADDR0_KCPU    0x80301040                      //IP0
#define HW_INTVEC_ADDR1_KCPU    (HW_INTVEC_ADDR0_KCPU  + 0x04)  //IP1
#define HW_INTVEC_ADDR2_KCPU    (HW_INTVEC_ADDR1_KCPU  + 0x04)  //IP2
#define HW_INTVEC_ADDR3_KCPU    (HW_INTVEC_ADDR2_KCPU  + 0x04)  //IP3
#define HW_INTVEC_ADDR4_KCPU    (HW_INTVEC_ADDR3_KCPU  + 0x04)  //IP4
#define HW_INTVEC_ADDR5_KCPU    (HW_INTVEC_ADDR4_KCPU  + 0x04)  //IP5
#define HW_INTVEC_ADDR6_KCPU    (HW_INTVEC_ADDR5_KCPU  + 0x04)  //IP6
#define HW_INTVEC_ADDR7_KCPU    (HW_INTVEC_ADDR6_KCPU  + 0x04)  //IP7
#define HW_INTVEC_ADDR8_KCPU    (HW_INTVEC_ADDR7_KCPU  + 0x04)  //IP8
#define HW_INTVEC_ADDR9_KCPU    (HW_INTVEC_ADDR8_KCPU  + 0x04)  //IP9
#define HW_INTVEC_ADDR10_KCPU   (HW_INTVEC_ADDR9_KCPU  + 0x04)  //IP10
#define HW_INTVEC_ADDR11_KCPU   (HW_INTVEC_ADDR10_KCPU + 0x04)  //IP11
#define HW_INTVEC_ADDR12_KCPU   (HW_INTVEC_ADDR11_KCPU + 0x04)  //IP12
#define HW_INTVEC_ADDR13_KCPU   (HW_INTVEC_ADDR12_KCPU + 0x04)  //IP13
#define HW_INTVEC_ADDR14_KCPU   (HW_INTVEC_ADDR13_KCPU + 0x04)  //IP14
#define HW_INTVEC_ADDR15_KCPU   (HW_INTVEC_ADDR14_KCPU + 0x04)  //IP15
#define SW_INT_RET_ADDR_KCPU    (HW_INTVEC_ADDR15_KCPU + 0x04)  //SW

/*SCPU*/
#define ARM_INT_ID27 0x8056A06C //PPI
#define ARM_INT_ID28 0x8056A070
#define ARM_INT_ID29 0x8056A074
#define ARM_INT_ID30 0x8056A078
#define ARM_INT_ID31 0x8056A07C
    
#define ARM_INT_ID32 0x8056A080 //SPI
#define ARM_INT_ID33 0x8056A084
#define ARM_INT_ID34 0x8056A088
#define ARM_INT_ID35 0x8056A08C
#define ARM_INT_ID36 0x8056A090
#define ARM_INT_ID37 0x8056A094
#define ARM_INT_ID38 0x8056A098
#define ARM_INT_ID39 0x8056A09C
#define ARM_INT_ID40 0x8056A0A0
#define ARM_INT_ID41 0x8056A0A4
#define ARM_INT_ID42 0x8056A0A8
#define ARM_INT_ID43 0x8056A0AC
#define ARM_INT_ID44 0x8056A0B0
#define ARM_INT_ID45 0x8056A0B4
#define ARM_INT_ID46 0x8056A0B8
#define ARM_INT_ID47 0x8056A0BC
#define ARM_INT_ID48 0x8056A0C0
#define ARM_INT_ID49 0x8056A0C4
#define ARM_INT_ID50 0x8056A0C8
#define ARM_INT_ID51 0x8056A0CC
#define ARM_INT_ID52 0x8056A0D0
#define ARM_INT_ID53 0x8056A0D4
#define ARM_INT_ID54 0x8056A0D8
#define ARM_INT_ID55 0x8056A0DC
#define ARM_INT_ID56 0x8056A0E0
#define ARM_INT_ID57 0x8056A0E4
#define ARM_INT_ID58 0x8056A0E8
#define ARM_INT_ID59 0x8056A0EC
#define ARM_INT_ID60 0x8056A0F0
#define ARM_INT_ID61 0x8056A0F4
#define ARM_INT_ID62 0x8056A0F8
#define ARM_INT_ID63 0x8056A0FC

#define ARM_INT_SPI_00 ARM_INT_ID32 
#define ARM_INT_SPI_01 ARM_INT_ID33 
#define ARM_INT_SPI_02 ARM_INT_ID34 
#define ARM_INT_SPI_03 ARM_INT_ID35 
#define ARM_INT_SPI_04 ARM_INT_ID36 
#define ARM_INT_SPI_05 ARM_INT_ID37 
#define ARM_INT_SPI_06 ARM_INT_ID38 
#define ARM_INT_SPI_07 ARM_INT_ID39 
#define ARM_INT_SPI_08 ARM_INT_ID40 
#define ARM_INT_SPI_09 ARM_INT_ID41 
#define ARM_INT_SPI_10 ARM_INT_ID42 
#define ARM_INT_SPI_11 ARM_INT_ID43 
#define ARM_INT_SPI_12 ARM_INT_ID44 
#define ARM_INT_SPI_13 ARM_INT_ID45 
#define ARM_INT_SPI_14 ARM_INT_ID46 
#define ARM_INT_SPI_15 ARM_INT_ID47 
#define ARM_INT_SPI_16 ARM_INT_ID48 
#define ARM_INT_SPI_17 ARM_INT_ID49 
#define ARM_INT_SPI_18 ARM_INT_ID50 
#define ARM_INT_SPI_19 ARM_INT_ID51 
#define ARM_INT_SPI_20 ARM_INT_ID52 
#define ARM_INT_SPI_21 ARM_INT_ID53 
#define ARM_INT_SPI_22 ARM_INT_ID54 
#define ARM_INT_SPI_23 ARM_INT_ID55 
#define ARM_INT_SPI_24 ARM_INT_ID56 
#define ARM_INT_SPI_25 ARM_INT_ID57 
#define ARM_INT_SPI_26 ARM_INT_ID58 
#define ARM_INT_SPI_27 ARM_INT_ID59 
#define ARM_INT_SPI_28 ARM_INT_ID60 
#define ARM_INT_SPI_29 ARM_INT_ID61 
#define ARM_INT_SPI_30 ARM_INT_ID62 
#define ARM_INT_SPI_31 ARM_INT_ID63 

/**********************************************************/
/* End of IRQ Definition                                  */
/**********************************************************/

#define C0_ESTATUS  $0
#define C0_ECAUSE   $1
#define C0_INTVEC   $2
#define C3_CPUTAG   $16

#include "sbx_reg.h"
#include "me_reg.h"
#include "ve_reg.h"
#include "dc_sys_reg.h"
#include "dc_phy_reg.h"
#include "vo_reg.h"
#include "voregsram_reg.h"
#include "vi_reg.h"
#include "tvd_reg.h"
#include "tve_reg.h"
#include "hdmi_reg.h"
//#include "aio_reg.h"
#include "adsp_reg.h"
#include "mcp_reg.h"
#include "m2m_reg.h"
#include "ata0_reg.h"
#include "ata1_reg.h"
#include "cp_reg.h"
#include "usb_reg.h"
#include "sb2_reg.h"
#include "mis_reg.h"
#include "otp_reg.h"
#include "dp_reg.h"
#include "gspi_reg.h"
#include "iso_reg.h"
#include "crt_sys_reg.h"
#include "md_reg.h"
#include "crt_fw.h"
#include "mhl_cbus_reg.h"
#include "se_reg.h"
#include "codeblkreg_reg.h"
#include "cabac_p2_reg.h"
#include "mvdblk_reg.h"
#include "img_reg.h"
#include "rif_reg_reg.h"
#include "predblk_reg.h"
#include "vma_reg.h"
#include "vmb_reg.h"
#include "deblk_reg.h"
#include "rl_reg.h"
#include "vp8_p2_reg.h"
#include "seg_reg.h"
#include "sao_reg.h"

#include "ime_reg.h"
#include "fme_reg.h"
#include "gcoeff_reg.h"
#include "ipmd_reg.h"
#include "encodeblkreg_reg.h"

#include "sde_reg.h"
#include "vde_reg.h"
#include "sata0_reg.h"
#include "sata1_reg.h"
#include "nf_reg.h"
#include "pcie_reg.h"
#include "tp_reg.h"
#include "cam_emm_reg.h"
#include "sb0_reg.h"
#include "icam_reg.h"
#include "sce_reg.h"
#include "kt_reg.h"
#include "rsa_reg.h"
#include "vfd_reg.h"

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
#define BU_TEST_ARM_RDY        0xa056a300 // ARM BOOTCODE READY
#define BU_TEST_ARM_PT         0x63300000 // DATA @BU_TEST_ARM_RDY
#define BU_TEST_GO_SCPU        0xa0002000
#define BU_TEST_GO_VCPU        0xa0002100
#define BU_TEST_GO_ACPU        0xa0002200
#define BU_TEST_GO_KCPU        0xa0002300
#define BU_TEST_GO_SCPU2       0xa0002400

#define BU_TEST_RESULT_SCPU    0xa0002004
#define BU_TEST_RESULT_VCPU    0xa0002104
#define BU_TEST_RESULT_ACPU    0xa0002204
#define BU_TEST_RESULT_KCPU    0xa0002304
#define BU_TEST_RESULT_SCPU2   0xa0002404

#define BU_COUNTER_SCPU        0xa0002008
#define BU_COUNTER_VCPU        0xa0002108
#define BU_COUNTER_ACPU        0xa0002208
#define BU_COUNTER_KCPU        0xa0002308
#define BU_COUNTER_SCPU2       0xa0002408

#define BU_RETURN_ADDR_SCPU    0xa000200c
#define BU_RETURN_ADDR_VCPU    0xa000210c
#define BU_RETURN_ADDR_ACPU    0xa000220c
#define BU_RETURN_ADDR_KCPU    0xa000230c
#define BU_RETURN_ADDR_SCPU2   0xa000240c

#define BU_VO_DISP_FRAME_CNT   0xa0102100
#define BU_VI_FIELD_CNT        0xa0102104

/**********************************************************/
/* DC Dummy Transactor Flags                              */
/**********************************************************/
#define VO0_DUMMY_BIT          0x10
#define VO1_DUMMY_BIT          0x20
#define VO2_DUMMY_BIT          0x40
#define VO3_DUMMY_BIT          0x80
#define SE_DUMMY_BIT           0x100
#define AEE_DUMMY_BIT          0x200
#define MD_DUMMY_BIT           0x400
#define ETN_DUMMY_BIT          0x800
#define CP_DUMMY_BIT           0x1000
#define TP_DUMMY_BIT           0x2000
#define AO_DUMMY_BIT           0x4000
#define ADE_DUMMY_BIT          0x8000
#define NF_DUMMY_BIT           0x10000
#define SATA_DUMMY_BIT         0x20000
#define CR_DUMMY_BIT           0x40000
#define VDE_DUMMY_BIT          0x80000
#define ME_DUMMY_BIT           0x100000
#define VI_DUMMY_BIT           0x200000
#define CABACP2_DUMMY_BIT      0x400000
#define VEBS_DUMMY_BIT         0x800000
#define VEBS2_DUMMY_BIT        0x1000000
#define VEIT_DUMMY_BIT         0x2000000
#define VEDBK_DUMMY_BIT        0x4000000
#define VEMVD_DUMMY_BIT        0x8000000
#define VENDB_DUMMY_BIT        0x10000000
#define VENDB2_DUMMY_BIT       0x20000000
#define VEPRD_DUMMY_BIT        0x40000000
#define VERL_DUMMY_BIT         0x80000000
#define VEVM1_DUMMY_BIT        0x1
#define VEEBS_DUMMY_BIT        0x2
#define VEEDBK_DUMMY_BIT       0x4
#define VEENDB_DUMMY_BIT       0x8
#define VEEVM1_DUMMY_BIT       0x10
#define VEEVM2_DUMMY_BIT       0x20
#define VEFME_DUMMY_BIT        0x40
#define VEGC_DUMMY_BIT         0x80
#define VEIME_DUMMY_BIT        0x100

#define DC_TEST_GO_VO0         la reg1, SB2_DUMMY_0_reg; li reg2  0x0010; sw reg2,0(reg1)
#define DC_TEST_GO_VO1         la reg1, SB2_DUMMY_0_reg; li reg2  0x0020; sw reg2,0(reg1)
#define DC_TEST_GO_VO2         la reg1, SB2_DUMMY_0_reg; li reg2  0x0040; sw reg2,0(reg1)
#define DC_TEST_GO_VO3         la reg1, SB2_DUMMY_0_reg; li reg2  0x0080; sw reg2,0(reg1)
#define DC_TEST_GO_SE          la reg1, SB2_DUMMY_0_reg; li reg2  0x0100; sw reg2,0(reg1)
#define DC_TEST_GO_AEE         la reg1, SB2_DUMMY_0_reg; li reg2  0x0200; sw reg2,0(reg1)
#define DC_TEST_GO_MD          la reg1, SB2_DUMMY_0_reg; li reg2  0x0400; sw reg2,0(reg1)
#define DC_TEST_GO_ETN         la reg1, SB2_DUMMY_0_reg; li reg2  0x0800; sw reg2,0(reg1)
#define DC_TEST_GO_CP          la reg1, SB2_DUMMY_0_reg; li reg2  0x1000; sw reg2,0(reg1)
#define DC_TEST_GO_TP          la reg1, SB2_DUMMY_0_reg; li reg2  0x2000; sw reg2,0(reg1)
#define DC_TEST_GO_AO          la reg1, SB2_DUMMY_0_reg; li reg2  0x4000; sw reg2,0(reg1)
#define DC_TEST_GO_ADE         la reg1, SB2_DUMMY_0_reg; li reg2  0x8000; sw reg2,0(reg1)
#define DC_TEST_GO_NF          la reg1, SB2_DUMMY_0_reg; lui reg2 0x0001; sw reg2,0(reg1)
#define DC_TEST_GO_SATA        la reg1, SB2_DUMMY_0_reg; lui reg2 0x0002; sw reg2,0(reg1)
#define DC_TEST_GO_CR          la reg1, SB2_DUMMY_0_reg; lui reg2 0x0004; sw reg2,0(reg1)
#define DC_TEST_GO_VDE         la reg1, SB2_DUMMY_0_reg; lui reg2 0x0008; sw reg2,0(reg1)
#define DC_TEST_GO_ME          la reg1, SB2_DUMMY_0_reg; lui reg2 0x0010; sw reg2,0(reg1)
#define DC_TEST_GO_VI          la reg1, SB2_DUMMY_0_reg; lui reg2 0x0020; sw reg2,0(reg1)

#define DC_TEST_GO_CABACP2     la reg1, SB2_DUMMY_0_reg; lui reg2 0x0040; sw reg2,0(reg1)
#define DC_TEST_GO_VEBS        la reg1, SB2_DUMMY_0_reg; lui reg2 0x0080; sw reg2,0(reg1)
#define DC_TEST_GO_VEBS2       la reg1, SB2_DUMMY_0_reg; lui reg2 0x0100; sw reg2,0(reg1)
#define DC_TEST_GO_VEIT        la reg1, SB2_DUMMY_0_reg; lui reg2 0x0200; sw reg2,0(reg1)
#define DC_TEST_GO_VEDBK       la reg1, SB2_DUMMY_0_reg; lui reg2 0x0400; sw reg2,0(reg1)
#define DC_TEST_GO_VEMVD       la reg1, SB2_DUMMY_0_reg; lui reg2 0x0800; sw reg2,0(reg1)
#define DC_TEST_GO_VENDB       la reg1, SB2_DUMMY_0_reg; lui reg2 0x1000; sw reg2,0(reg1)
#define DC_TEST_GO_VENDB2      la reg1, SB2_DUMMY_0_reg; lui reg2 0x2000; sw reg2,0(reg1)
#define DC_TEST_GO_VEPRD       la reg1, SB2_DUMMY_0_reg; lui reg2 0x4000; sw reg2,0(reg1)
#define DC_TEST_GO_VERL        la reg1, SB2_DUMMY_0_reg; lui reg2 0x8000; sw reg2,0(reg1)
#define DC_TEST_GO_VEVM1       la reg1, SB2_DUMMY_1_reg; li  reg2 0x0001; sw reg2,0(reg1)
#define DC_TEST_GO_VEEBS       la reg1, SB2_DUMMY_1_reg; li  reg2 0x0002; sw reg2,0(reg1)
#define DC_TEST_GO_VEEDBK      la reg1, SB2_DUMMY_1_reg; li  reg2 0x0004; sw reg2,0(reg1)
#define DC_TEST_GO_VEENDB      la reg1, SB2_DUMMY_1_reg; li  reg2 0x0008; sw reg2,0(reg1)
#define DC_TEST_GO_VEEVM1      la reg1, SB2_DUMMY_1_reg; li  reg2 0x0010; sw reg2,0(reg1)
#define DC_TEST_GO_VEEVM2      la reg1, SB2_DUMMY_1_reg; li  reg2 0x0020; sw reg2,0(reg1)
#define DC_TEST_GO_VEFME       la reg1, SB2_DUMMY_1_reg; li  reg2 0x0040; sw reg2,0(reg1)
#define DC_TEST_GO_VEGC        la reg1, SB2_DUMMY_1_reg; li  reg2 0x0080; sw reg2,0(reg1)
#define DC_TEST_GO_VEIME       la reg1, SB2_DUMMY_1_reg; li  reg2 0x0100; sw reg2,0(reg1)

/**********************************************************/
/* End of DC Dummy Transactor Flags                       */
/**********************************************************/

//Note: this macro will check CPU type.
#define BU_CHECK_CPU(index, reg1, reg2, reg3) \
     beq reg1, reg2, 1f; \
     nop; \
     mfc0 reg3, C0_PRID; \
     bne  reg3, 0xc601, 2f; \
     lui  r1, 0xa000; \
     mfc3 reg3, C3_CPUTAG; \
     bne reg3, 0x6b656e68, 2f; \
     ori  r1, 0x2210; \
     ori  r1, 0x2110; \
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
     ori  r1, 0x2224; \
     ori  r1, 0x2124; \
2:   ori r1, 0x2024; /*MSG_REG*/\
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
     ori  r1, 0x2230; \
     ori  r1, 0x2130; \
2:   ori r1, 0x2030; /*MSG_INT*/\
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
     la  r1, 0xa0002110; \
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
     la  r1, 0xa0002210; \
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

#define DELAY_C(count) \
    {int i; for(i=count; i>0; i--);}\


#define DELAY(count,reg) \
    li    reg,count;\
9:    sub    reg,1;\
        bne    reg,r0,9b;\
        nop;\

// wait until reg shows matched value.
//use "ori zero, 0x8898" op=34008898 to distinguish
//
#ifdef ARM
#define WAIT_C(addr,mask,value) \
    asm(" nop; nop; nop; nop;"); \
            while( ((*((unsigned int*) addr))&mask)!=value );

#define WAIT_C_BE(addr,mask,value) \
    asm(" nop; nop; nop; nop;"); \
            while( ((*((unsigned int*) addr))&mask)<value );

#define CPU_TRACE_COMPARE_OFF_C \
    asm("nop; nop; nop; nop; nop; nop;");

#define CPU_TRACE_COMPARE_ON_C \
    asm("nop; nop; nop; nop; nop; nop;");

#else
#define WAIT_C(addr,mask,value) \
    asm(" nop; nop; nop; nop; ori $0,0x8898;"); \
            while( ((*((unsigned int*) addr))&mask)!=value );

#define WAIT_C_BE(addr,mask,value) \
    asm(" nop; nop; nop; nop; ori $0,0x8898;"); \
            while( ((*((unsigned int*) addr))&mask)<value );
        
#define CPU_TRACE_COMPARE_OFF_C \
    asm("nop; nop; nop; nop; nop; ori $0, 0x00ff; nop;");

#define CPU_TRACE_COMPARE_ON_C \
    asm("nop; nop; nop; nop; nop; ori $0, 0x0011; nop;");

#endif

#define WAIT_BE(addr,mask,value,reg1,reg2) \
    nop;\
    nop;\
    nop;\
    nop;\
    ori zero, 0x8898;\
8:    lw reg1, addr;\
    nop;\
    and reg1, mask;\
    li reg2, value;\
    blt reg1, reg2, 8b;\
    nop;\

#define WAIT(addr,mask,value,reg1,reg2) \
    nop;\
    nop;\
    nop;\
    nop;\
    ori zero, 0x8898;\
8:    lw reg1, addr;\
    nop;\
    and reg1, mask;\
    li reg2, value;\
    bne reg1, reg2, 8b;\
    nop;\

#define INF_LOOP \
    ori    zero, 0x8898;\
7:    b    7b; \
    nop;    

#define INF_LOOP2 \
    nop;\
    ori    zero, 0x8898;\
7:    b    7b; \
    nop;    

#define CPU_TRACE_COMPARE_OFF \
    nop;\
    nop;\
    nop;\
    nop;\
    ori    zero, 0x00ff;\
    nop;\
    nop;\
    nop;\
    nop;

#define CPU_TRACE_COMPARE_ON \
    nop;\
    nop;\
    nop;\
    nop;\
    nop;\
    nop;\
    nop;\
    nop;\
    ori    zero, 0x0011;\
    nop;\
    nop;\
    nop;\
    nop;
   
#define REG_WR(addr,addr_reg,data,data_reg) \
    la    addr_reg,addr;          \
    li    data_reg,data;          \
    sw    data_reg,(addr_reg);          \

#define REG_RD(addr,addr_reg,data_reg) \
    la    addr_reg,addr;          \
    lw    data_reg,(addr_reg);        \
    nop;\

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
#define CHECK_WR_REG(addr, wr_val, rd_val, mask, reg1, reg2, reg3) \
    la    reg1, addr;              \
    li    reg2, wr_val;            \
    sw    reg2, (reg1);            \
    li    reg3, rd_val;            \
    lw    reg2, (reg1);            \
    nop;                           \
    and    reg2, mask;             \
    bne    reg2, reg3, DIAG_FAIL;  \
    nop
    
#define BU_CHECK_WR_REG(addr, wr_val, rd_val, mask, reg1, reg2, reg3) \
    la    reg1, addr;              \
    li    reg2, wr_val;            \
    sw    reg2, (reg1);            \
    li    reg3, rd_val;            \
    lw    reg2, (reg1);            \
    nop;                           \
    and    reg2, mask;             \
    BU_CHECK_CPU(addr&0xffff, reg2, reg3, reg1); \
    nop
           
#define CHECK_SECURED_REG(addr, wr_val, reg1, reg2, reg3) \
    la   reg1, addr;               \
    li   reg2, wr_val;             \
    sw   reg2, (reg1);             \
    li   reg3, 0xDEADDEAD;         \
    lw   reg2, (reg1);             \
    nop;                           \
    and  reg2, 0xFFFFFFFF;         \
    bne  reg2, reg3, DIAG_FAIL;    \
    nop

#define PROTECTED_RD(addr, reg1, reg2, reg3) \
    la   reg1, addr;                         \
    li   reg2, 0x00000000;                   \
    lw   reg3, (reg1);                       \
    bne  reg2, reg3, DIAG_FAIL;              \
    nop

// from from reg, then compare with rd_val.
// good for R/O reg, and Reset value check.
#define CHECK_RD_REG(addr, rd_val, mask, reg1, reg2, reg3) \
        la    reg1, addr;                     \
        lw    reg2, (reg1);                   \
        nop;                                  \
        and   reg2, mask;                     \
        li    reg3, rd_val;                   \
        bne   reg2, reg3, DIAG_FAIL;          \
        nop
    
#define BU_CHECK_RD_REG(addr, rd_val, mask, reg1, reg2, reg3) \
        la    reg1, addr;                     \
        lw    reg2, (reg1);                   \
        nop;                                  \
        and   reg2, mask;                     \
        li    reg3, rd_val;                   \
        BU_CHECK_CPU(addr&0xffff, reg2, reg3, reg1); \
        nop

#define CHECK_RD_REG_JB(addr, mask, reg1, reg2, jump_label) \
        la    reg1, addr;                     \
        lw    reg2, (reg1);                   \
        nop;                                  \
        and   reg2, mask;                     \
        bgtz  reg2, jump_label;               \
        nop

#define CHECK_RD_REG_JNB(addr, mask, reg1, reg2, jump_label) \
        la    reg1, addr;                     \
        lw    reg2, (reg1);                   \
        nop;                                  \
        not   reg2, reg2;                     \
        and   reg2, mask;                     \
        bgtz  reg2, jump_label;               \
        nop

#define CHECK_RD_REG_JE(addr, rd_val, mask, reg1, reg2, jump_label) \
        la    reg1, addr;                     \
        lw    reg2, (reg1);                   \
        nop;                                  \
        and   reg2, mask;                     \
        li    reg1, rd_val;                   \
        beq   reg2, reg1, jump_label;         \
        nop

#define CHECK_RD_REG_JNE(addr, rd_val, mask, reg1, reg2, jump_label) \
        la    reg1, addr;                     \
        lw    reg2, (reg1);                   \
        nop;                                  \
        and   reg2, mask;                     \
        li    reg1, rd_val;                   \
        bne   reg2, reg1, jump_label;         \
        nop

    
//for whole-chip, multiple-CPUs: SCPU_SYNC_START
//assume SCPU is the first out of boot.
#define SYNC_START_ADDR  0xa0300000 //assume the 8 bytes starting from it is available.

#define SCPU_SYNC_START(addr, reg1, reg2) \
    la    reg1, addr;                     \
    sw    zero, (reg1);                   \
    sw    zero, 4(reg1);                  \
1:  lw    reg2, (reg1);                   \
    nop;                                  \
    beq   reg2, zero, 1b;                 \
    nop;                                  \
1:  lw    reg2, 4(reg1);                  \
    nop;                                  \
    beq   reg2, zero, 1b;                 \
    nop

//for whole-chip, multiple-CPUs: ACPU_SYNC_START
#define ACPU_SYNC_START(addr, reg1, reg2)       \
    WAIT(SB2_HD_SEM_reg, 0x1, 0x1, reg1, reg2); \
    la    reg1, addr;                           \
    li    reg2, 0x1;                            \
    sw    reg2, (reg1);                         \
    la    reg2, SB2_HD_SEM_reg;                 \
    sw    zero, (reg2);                         \
1:  lw    reg2, 4(reg1);                        \
    nop;                                        \
    beq   reg2, zero, 1b;                       \
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
8:  lw reg1, addr;\
    nop;\
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
#define VCPU_SYNC_START(addr, reg1, reg2)       \
    WAIT(SB2_HD_SEM_reg, 0x1, 0x1, reg1, reg2); \
    la    reg1, addr;                           \
    li    reg2, 0x1;                            \
    sw    reg2, 4(reg1);                        \
    la    reg2, SB2_HD_SEM_reg;                 \
    sw    zero, (reg2);                         \
1:  lw    reg2, (reg1);                         \
    nop;                                        \
    beq   reg2, zero, 1b;                       \
    nop

//global sync for all CPUs
#define SYNC_ALL_CPU_START(reg1, reg2, num_of_cpu) \
    WAIT(SB2_HD_SEM_reg, 0x1, 0x1, reg1, reg2);    \
    la    reg1, 0xb801a024;                        \
    lw    reg2, (reg1);                            \
    nop;                                           \
    li    reg1, num_of_cpu;                        \
    bne   reg2, reg1, 1f;                          \
    nop;                                           \
    and   reg2, zero;                              \
1:  add   reg2, 1;                                 \
    la    reg1, 0xb801a024;                        \
    sw    reg2, (reg1);                            \
    la    reg2, SB2_HD_SEM_reg;                    \
    sw    zero, (reg2);                            \
    WAIT(0xb801a024, 0x1f, num_of_cpu, reg1, reg2);

//global sync for all 3 CPUs
#define CPU_SYNC_START(reg1, reg2)              \
    WAIT(SB2_HD_SEM_reg, 0x1, 0x1, reg1, reg2); \
    la    reg1, 0xb801a024;                     \
    lw    reg2, (reg1);                         \
    nop;                                        \
    li    reg1, 0x3;                            \
    bne   reg2, reg1, 1f;                       \
    nop;                                        \
    and   reg2, zero;                           \
1:  add   reg2, 1;                              \
    la    reg1, 0xb801a024;                     \
    sw    reg2, (reg1);                         \
    la    reg2, SB2_HD_SEM_reg;                 \
    sw    zero, (reg2);                         \
    WAIT(0xb801a024, 0x3, 0x3, reg1, reg2);

//reset VE registers
#define RESET_VE_REG() \
        REG_WR(VE_CNTL_reg,       t2, 0xfffffffe, t4);  \
        REG_WR(VE_INT_STATUS_reg, t2, 0xfffffffe, t4);  \
        REG_WR(VE_INTEN_reg,       t2, 0xfffffffe, t4); \
        REG_WR(VE_PCCNTL_reg,       t2, 0xa48888, t4);  \
        REG_WR(VE_PC0_reg,        t2, 0, t4);           \
        REG_WR(VE_PC1_reg,        t2, 0, t4);           \
        REG_WR(VE_PC2_reg,        t2, 0, t4);           \
        REG_WR(VE_DCTCNTL_reg,    t2, 0x6420, t4);      \
        REG_WR(VE_CODECPARAM_reg, t2, 0x7f, t4);        \
        REG_WR(VE_CODECCNTL_reg, t2, 0xbb1, t4);        \
        REG_WR(VE_CODECCNTL1_reg, t2, 0xfffffffe, t4);  \
        REG_WR(VE_CODECCNTL1_reg, t2, 0x41, t4);        \
        REG_WR(VE_DVPARAM_reg   , t2, 0, t4);           \
        REG_WR(VE_VLDTBLPTR_0_reg, t2, 0, t4);          \
        REG_WR(VE_VLDTBLPTR_1_reg, t2, 0, t4);          \
        REG_WR(VE_VLDTBLPTR_2_reg, t2, 0, t4);          \
        REG_WR(VE_VLDTBLPTR_3_reg, t2, 0, t4);          \
        REG_WR(VE_VLDESPPTR_0_reg, t2, 0, t4);          \
        REG_WR(VE_VLDESPPTR_1_reg, t2, 0, t4);          \
        REG_WR(VE_VLDESPPTR_2_reg, t2, 0, t4);          \
        REG_WR(VE_VLDESPPTR_3_reg, t2, 0, t4);          \
        REG_WR(VE_DECBITCNT_reg, t2, 0x400, t4);        \
        REG_WR(VE_BITSTCNT_reg, t2, 0, t4);             \
        REG_WR(VE_FILTCNTL_reg, t2, 0x8102108, t4);     \
        REG_WR(VE_FILTINIT_reg, t2, 0, t4);             \
        REG_WR(VE_CKCNTL_reg, t2, 0, t4);               \
        REG_WR(VE_CKDATA_reg, t2, 0, t4);               \
        REG_WR(VE_ADAPCNTL_reg, t2, 0, t4);             \
        REG_WR(VE_ALPHA_reg, t2, 0, t4);                \
        REG_WR(VE_DEBLKCNTL_reg, t2, 0x62, t4);         \
        REG_WR(VE_DCVAL_reg, t2, 0, t4);                \
        REG_WR(VE_BLKD_THR_reg, t2, 0, t4);             \
        REG_WR(VE_BLKD_WEIGHT_reg, t2, 0, t4);          \
        REG_WR(VE_TAPCOEFF_0_reg, t2, 0, t4);           \
        REG_WR(VE_TAPCOEFF_1_reg, t2, 0, t4);           \
        REG_WR(VE_TAPCOEFF_2_reg, t2, 0, t4);           \
        REG_WR(VE_TAPCOEFF_3_reg, t2, 0, t4);           \
        REG_WR(VE_TAPCOEFF_4_reg, t2, 0, t4);           \
        REG_WR(VE_TAPCOEFF_5_reg, t2, 0, t4);           \
        REG_WR(VE_TAPCOEFF_6_reg, t2, 0, t4);           \
        REG_WR(VE_TAPCOEFF_7_reg, t2, 0, t4);           \
        li       t0, VE_CNTL_codblk_mode(0x3)|VE_CNTL_write_data(0); \
        wrcodreg t0, VE_CNTL_inst;                                   \
        li       t0, VE_CNTL_reset_ptr(1)|VE_CNTL_write_data(1);     \
        wrcodreg t0, VE_CNTL_inst;                                   \
        li       t0, VE_CNTL_reset_ptr(1)|VE_CNTL_write_data(0);     \
        wrcodreg t0, VE_CNTL_inst

#define MD_REG_WR(Addr,DataReg,Mask)  \
        and t0, DataReg, Mask;        \
        la  t4, Addr;                 \
        sw  t0, (t4);                 \
        nop
#define    MD_REG_RD(RegAddr,CmpVal,SelBits,Reg1,Reg2) \
        la   Reg1, RegAddr;             \
        lw   Reg2, (Reg1);              \
        nop;                            \
        and  Reg2, Reg2, SelBits;       \
        bne  Reg2, CmpVal, DIAG_FAIL;   \
        nop
#define    MD_REG_NM_WRITE(RegAddr,WrtVal,Reg1,Reg2) \
        la   Reg1, RegAddr;             \
        li   Reg2 ,WrtVal;              \
        sw   Reg2,(Reg1);               \
        nop
#define    MD_REG_WD_WRITE(RegAddr,WrtDatVal,Reg1,Reg2) \
        la   Reg1, RegAddr;             \
        li   Reg2, WrtDatVal;           \
        sw   Reg2, (Reg1);              \
        nop

#define WAIT_LOOP_JE(addr, rd_val, mask, loop, delay, reg1, reg2, reg3,reg4) \
        li      reg1,loop;\
7:      sub     reg1,1;\
        DELAY(delay,reg2);\
        CHECK_RD_REG_JE(addr,rd_val,mask,reg3,reg4,6f);\
        bne     reg1,r0,7b;\
        nop;\
        b       DIAG_FAIL;\
        nop;\
6:      nop

#define WAIT_LOOP_JNE(addr, rd_val, mask, loop, delay, reg1, reg2, reg3,reg4) \
        li      reg1,loop;\
7:      sub     reg1,1;\
        DELAY(delay,reg2);\
        CHECK_RD_REG_JNE(addr,rd_val,mask,reg3,reg4,6f);\
        bne     reg1,r0,7b;\
        nop;\
        b       DIAG_FAIL;\
        nop;\
6:      nop

#define DC_TEST_GO(val2, val1, reg1, reg2) \
        la reg1, SB2_DUMMY_0_reg; \
        li reg2, val1; \
        sw reg2, 0(reg1); \
        li reg2, val2; \
        sw reg2, 4(reg1);

#define DC_TEST_GO_VE(val, reg1, reg2) \
        la reg1, SB2_SHADOW_0_reg; \
        li reg2, val; \
        sw reg2, 0(reg1);

#define set_DMEM_VALUE(addr,data)   (*((volatile unsigned int*) addr)=data)
#define get_DMEM_VALUE(addr)        (*((volatile unsigned int*) addr))
        
#define ad_initial        ad_initial  
#define ad_mbskip         ad_mbskip
#define ad_fieldflg       ad_fieldflg     r0, 0
#define ad_eos            ad_eos          r0, 0
#define ad_mbtype         ad_mbtype       r0, 0
//#define ad_mbpred         ad_mbpred       r0, 0
#define ad_quant          ad_quant        r0, 0
//#define ad_mbdec          ad_mbdec        r0, 0
#define dec_skiprun       dec_skiprun      r0, 0
#define dec_fieldflg      dec_fieldflg     r0, 0
#define dec_mbtype        dec_mbtype       
#define dec_pcm           dec_pcm
#define dec_mbpred        dec_mbpred
#define dec_quant         dec_quant        r0, 0
#define dec_mbdec         dec_mbdec
#define dec_pred_weight   dec_pred_weight  r0, 0
#define dec_acpred        dec_acpred       r0, 0
#define dec_cbp           dec_cbp          r0, 0
#define dec_bmvtype       dec_bmvtype      r0, 0
#define dec_2mvbp         dec_2mvbp        r0, 0
#define dec_4mvbp         dec_4mvbp        r0, 0
#define dec_mbmode        dec_mbmode       r0, 0
#define dec_overflg       dec_overflg
#define dec_bitpln        dec_bitpln       r0, 0
#define cond_dec_quant    cond_dec_quant   r0, 0
#define cond_dec_acpred   cond_dec_acpred  r0, 0
#define mbadec            mbadec           r0, 0
#define mb_last           mb_last
#define getbits           getbits
#define peekbits          peekbits
#define decstartcode      decstartcode
#define wrcodreg          wrcodreg
#define rdcodreg          rdcodreg
#define slice_start       slice_start      r0, 0
#define ldvldtbl          ldvldtbl
#define stvldtbl          stvldtbl
#define mvxdec            mvxdec           r0,
#define mvydec            mvydec           r0,
#define dec_ue            dec_ue           r0, 0
#define dec_se            dec_se           r0, 0
//#define ldbmem            ldbmem           r0, 0
//#define stbmem            stbmem           r0, 0
#define patsearch         patsearch
#define struvlcdecrv      struvlcdecrv     r0, 0
#define mvxydecrv         mvxydecrv        
#define getsync           getsync          
#define bkdec             bkdec               

#define AD_INITIAL        AD_INITIAL  
#define AD_MBSKIP         AD_MBSKIP
#define AD_FIELDFLG       AD_FIELDFLG     r0, 0
#define AD_EOS            AD_EOs          r0, 0
#define AD_MBTYPE         AD_MBTYPE       r0, 0
//#define AD_MBPRED         AD_MBPRED       r0, 0
#define AD_QUANT          AD_QUANT        r0, 0
//#define AD_MBDEC          AD_MBDEC        r0, 0
#define DEC_SKIPRUN       DEC_SKIPRUN      r0, 0
#define DEC_FIELDFLG      DEC_FIELDFLG     r0, 0
#define DEC_MBTYPE        DEC_MBTYPE       
#define DEC_PCM           DEC_PCM
#define DEC_MBPRED        DEC_MBPRED
#define DEC_QUANT         DEC_QUANT        r0, 0
#define DEC_MBDEC         DEC_MBDEC
#define DEC_PRED_WEIGHT   DEC_PRED_WEIGHT  r0, 0
#define DEC_ACPRED        DEC_ACPRED       r0, 0
#define DEC_CBP           DEC_CBP          r0, 0
#define DEC_BMVTYPE       DEC_BMVTYPE      r0, 0
#define DEC_2MVBP         DEC_2MVBP        r0, 0
#define DEC_4MVBP         DEC_4MVBP        r0, 0
#define DEC_MBMODE        DEC_MBMODE       r0, 0
#define DEC_OVERFLG       DEC_OVERFLG
#define DEC_BITPLN        DEC_BITPLN       r0, 0
#define COND_DEC_QUANT    COND_DEC_QUANT   r0, 0
#define COND_DEC_ACPRED   COND_DEC_ACPRED  r0, 0
#define MBADEC            MBADEC           r0, 0
#define MB_LAST           MB_LAST
#define GETBITS           GETBITS
#define PEEKBITS          PEEKBITS
#define DECSTARTCODE      DECSTARTCODE
#define WRCODREG          WRCODREG
#define RDCODREG          RDCODREG
//#define SLICE_START       SLICE_START      r0, 0
#define LDVLDTBL          LDVLDTBL
#define STVLDTBL          STVLDTBL
#define MVXDEC            MVXDEC           r0,
#define MVYDEC            MVYDEC           r0,
#define DEC_UE            DEC_UE           r0, 0
#define DEC_SE            DEC_SE           r0, 0
//#define LDBMEM            LDBMEM           r0, 0
//#define STBMEM            STBMEM           r0, 0
#define PATSEARCH         PATSEARCH
#define STRUVLCDECRV      STRUVLCDECRV     r0, 0
#define MVXYDECRV         MVXYDECRV        
#define GETSYNC           GETSYNC          
#define BKDEC             BKDEC           

#define PREDBLK_BASEA_0_inst PREDBLK_BASEA_inst
#define PREDBLK_BASEA_1_inst PREDBLK_BASEA_inst
#define PREDBLK_OFFSETA_3_inst PREDBLK_OFFSETA_2_inst

#endif
