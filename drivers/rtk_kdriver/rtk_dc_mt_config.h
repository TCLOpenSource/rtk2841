#ifndef __DC_MT_CFG__
#define __DC_MT_CFG__

#include <mach/irqs.h>
#include <rbus/dc_sys_reg.h>

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define DCU_IRQ                             gic_irq_find_mapping(IRQ_DCSYS)
#else
#define DCU_IRQ                             IRQ_DCSYS
#endif



/*-------------------------------------------------------------
 * RTD299o DC SYS register
 *-------------------------------------------------------------*/
#define DC_MTEX_ENTRY_START                4
#define DC_MT_ENTRY_COUNT                   8

#define DC_MT_OFST(i)                       (i<<2)

#define DC_MT_MODE_WE5          (1<<2)
#define DC_MT_MODE_MODE(x)      (x & 0x3)

#define DC_MT_TABLE_ENTRY(x)    (x&0xFF)
#define DC_MT_TABLE_MODULE0(x)  (DC_MT_TABLE_ENTRY(x)<<24)
#define DC_MT_TABLE_MODULE1(x)  (DC_MT_TABLE_ENTRY(x)<<16)
#define DC_MT_TABLE_MODULE2(x)  (DC_MT_TABLE_ENTRY(x)<<8)
#define DC_MT_TABLE_MODULE3(x)  (DC_MT_TABLE_ENTRY(x))

#define DC_MT_ACCESS_TYPE(x)        (x&0x03)
#define DC_MT_ACCESS_TYPE0(x)   (DC_MT_ACCESS_TYPE(x)<<30)
#define DC_MT_ACCESS_TYPE1(x)   (DC_MT_ACCESS_TYPE(x)<<28)
#define DC_MT_ACCESS_TYPE2(x)   (DC_MT_ACCESS_TYPE(x)<<26)
#define DC_MT_ACCESS_TYPE3(x)   (DC_MT_ACCESS_TYPE(x)<<24)

#define DC_MT_ADDCMD_HI_EVER_TRAP            (1 << 22)

#define DC_INT_EN_RD_TAG_MISMATCH_INT_EN     (0x1UL<<23)
#define DC_INT_EN_ERR_SEQ_SA_ODD_INT_EN      (0x1UL<<22)
#define DC_INT_EN_ERR_SEQ_BL_ZERO_INT_EN     (0x1UL<<21)
#define DC_INT_EN_ERR_SEQ_BL_ODD_INT_EN      (0x1UL<<20)
#define DC_INT_EN_ERR_BLK_8X2_ON_64_INT_EN   (0x1UL<<19)
#define DC_INT_EN_ERR_BLK_SIZE_EXCEED_INT_EN (0x1UL<<18)
#define DC_INT_EN_ERR_BLK_H_ZERO_INT_EN      (0x1UL<<17)
#define DC_INT_EN_ERR_BLK_W_ZERO_INT_EN      (0x1UL<<16)
#define DC_INT_EN_MT_3_MOD3_INT_EN           (0x1UL<<12)
#define DC_INT_EN_MT_3_MOD2_INT_EN           (0x1UL<<11)
#define DC_INT_EN_MT_3_MOD1_INT_EN           (0x1UL<<10)
#define DC_INT_EN_MT_2_MOD3_INT_EN           (0x1UL<<9)
#define DC_INT_EN_MT_2_MOD2_INT_EN           (0x1UL<<8)
#define DC_INT_EN_MT_2_MOD1_INT_EN           (0x1UL<<7)
#define DC_INT_EN_MT_1_MOD3_INT_EN           (0x1UL<<6)
#define DC_INT_EN_MT_1_MOD2_INT_EN           (0x1UL<<5)
#define DC_INT_EN_MT_1_MOD1_INT_EN           (0x1UL<<4)
#define DC_INT_EN_MT_0_MOD3_INT_EN           (0x1UL<<3)
#define DC_INT_EN_MT_0_MOD2_INT_EN           (0x1UL<<2)
#define DC_INT_EN_MT_0_MOD1_INT_EN           (0x1UL<<1)
#define DC_INT_EN_WRITE_DATA                 (0x1UL<<0)

#define DC_INT_EN_MT_0_INTS             (DC_INT_EN_MT_0_MOD1_INT_EN | DC_INT_EN_MT_0_MOD2_INT_EN | DC_INT_EN_MT_0_MOD3_INT_EN)
#define DC_INT_EN_MT_1_INTS             (DC_INT_EN_MT_1_MOD1_INT_EN | DC_INT_EN_MT_1_MOD2_INT_EN | DC_INT_EN_MT_1_MOD3_INT_EN)
#define DC_INT_EN_MT_2_INTS             (DC_INT_EN_MT_2_MOD1_INT_EN | DC_INT_EN_MT_2_MOD2_INT_EN | DC_INT_EN_MT_2_MOD3_INT_EN)
#define DC_INT_EN_MT_3_INTS             (DC_INT_EN_MT_3_MOD1_INT_EN | DC_INT_EN_MT_3_MOD2_INT_EN | DC_INT_EN_MT_3_MOD3_INT_EN)

#define DC_INT_STATUS_RD_TAG_MISMATCH_INT       (0x1UL<<23)
#define DC_INT_STATUS_ERR_SEQ_SA_ODD_INT        (0x1UL<<22)
#define DC_INT_STATUS_ERR_SEQ_BL_ZERO_INT       (0x1UL<<21)
#define DC_INT_STATUS_ERR_SEQ_BL_ODD_INT        (0x1UL<<20)
#define DC_INT_STATUS_ERR_BLK_8X2_ON_64_INT     (0x1UL<<19)
#define DC_INT_STATUS_ERR_BLK_SIZE_EXCEED_INT   (0x1UL<<18)
#define DC_INT_STATUS_ERR_BLK_H_ZERO_INT        (0x1UL<<17)
#define DC_INT_STATUS_ERR_BLK_W_ZERO_INT        (0x1UL<<16)
#define DC_INT_STATUS_MT_3_MOD3_INT             (0x1UL<<12)
#define DC_INT_STATUS_MT_3_MOD2_INT             (0x1UL<<11)
#define DC_INT_STATUS_MT_3_MOD1_INT             (0x1UL<<10)
#define DC_INT_STATUS_MT_2_MOD3_INT             (0x1UL<<9)
#define DC_INT_STATUS_MT_2_MOD2_INT             (0x1UL<<8)
#define DC_INT_STATUS_MT_2_MOD1_INT             (0x1UL<<7)
#define DC_INT_STATUS_MT_1_MOD3_INT             (0x1UL<<6)
#define DC_INT_STATUS_MT_1_MOD2_INT             (0x1UL<<5)
#define DC_INT_STATUS_MT_1_MOD1_INT             (0x1UL<<4)
#define DC_INT_STATUS_MT_0_MOD3_INT             (0x1UL<<3)
#define DC_INT_STATUS_MT_0_MOD2_INT             (0x1UL<<2)
#define DC_INT_STATUS_MT_0_MOD1_INT             (0x1UL<<1)
#define DC_INT_STATUS_WRITE_DATA                (0x1UL<<0)

#define DC_INT_STATUS_MOD1_INT              (0x1UL<<0)
#define DC_INT_STATUS_MOD2_INT              (0x1UL<<1)
#define DC_INT_STATUS_MOD3_INT              (0x1UL<<2)
#define DC_INT_STATUS_INTS                  (DC_INT_STATUS_MOD1_INT | DC_INT_STATUS_MOD2_INT | DC_INT_STATUS_MOD3_INT)

#define DC_INT_STATUS_MTx_MOD3_INT(i)       (DC_INT_STATUS_MOD3_INT<<((3*i) +1))
#define DC_INT_STATUS_MTx_MOD2_INT(i)       (DC_INT_STATUS_MOD2_INT<<((3*i) +1))
#define DC_INT_STATUS_MTx_MOD1_INT(i)       (DC_INT_STATUS_MOD1_INT<<((3*i) +1))

#define DC_INT_STATUS_MTx_INT_MASK(i)       (DC_INT_STATUS_INTS << ((3*i) +1))
#define DC_INT_STATUS_MTx_INT_MASK_NO_WRITE_DATA(i)       (DC_INT_STATUS_INTS << (3*i))

//DCU1
#define MODULE_TVSB2_DIW            MODULE_ID(0, 0)
#define MODULE_TVSB2_DIR            MODULE_ID(0, 1)
#define MODULE_TVSB2_M_CAP          MODULE_ID(0, 2)
#define MODULE_TVSB2_M_DISP         MODULE_ID(0, 3)
#define MODULE_TVSB2_S_CAP          MODULE_ID(0, 4)
#define MODULE_TVSB2_S_DISP         MODULE_ID(0, 5)
#define MODULE_TVSB2_VO1_Y          MODULE_ID(0, 6)
#define MODULE_TVSB2_VO1_C          MODULE_ID(0, 7)
#define MODULE_TVSB2_VO2_Y          MODULE_ID(0, 8)
#define MODULE_TVSB2_VO2_C          MODULE_ID(0, 9)
#define MODULE_TVSB2_I3DDMA         MODULE_ID(0, 0xa)
#define MODULE_TVSB2_DE_XC_W        MODULE_ID(0, 0xb)
#define MODULE_TVSB2_DE_XC_R        MODULE_ID(0, 0xc)
#define MODULE_TVSB2_SNR_R          MODULE_ID(0, 0xd)
#define MODULE_TVSB2         MODULE_ID(0, 0xf)

#define MODULE_TVSB1_VD             MODULE_ID(1, 0)
#define MODULE_TVSB1_AUDIO1          MODULE_ID(1, 1)
#define MODULE_TVSB1_AUDIO2       MODULE_ID(1, 2)
#define MODULE_TVSB1_VBI            MODULE_ID(1, 3)
#define MODULE_TVSB1_TVE_VD         MODULE_ID(1, 4)
#define MODULE_TVSB1_TVE_VBI        MODULE_ID(1, 5)
#define MODULE_TVSB1        MODULE_ID(1, 0xf)


#define MODULE_SB1_CP_KC            MODULE_ID(2, 0)
#define MODULE_SB1_USB_EX               MODULE_ID(2, 1)
#define MODULE_SB1_USB              MODULE_ID(2, 2)
#define MODULE_SB1_TP2              MODULE_ID(2, 4)
#define MODULE_SB1_ETN              MODULE_ID(2, 5)
#define MODULE_SB1_TP_KC            MODULE_ID(2, 6)
#define MODULE_SB1_EMMC_KC          MODULE_ID(2, 7)
#define MODULE_SB1_CP_NKC           MODULE_ID(2, 0xa)
#define MODULE_SB1_TP2_NKC          MODULE_ID(2, 0xc)
#define MODULE_SB1_TP_NKC           MODULE_ID(2, 0xd)
#define MODULE_SB1_EMMC_NKC         MODULE_ID(2, 0xe)
#define MODULE_SB1         MODULE_ID(2, 0xf)


#define MODULE_SB2_KCPU             MODULE_ID(3, 0)
#define MODULE_SB2_ACPU             MODULE_ID(3, 1)
#define MODULE_SB2_ACPU2            MODULE_ID(3, 2)
#define MODULE_SB2_VCPU             MODULE_ID(3, 3)
#define MODULE_SB2_VCPU2            MODULE_ID(3, 4)
#define MODULE_SB2_UART             MODULE_ID(3, 5)
#define MODULE_SB2_HOST_IF          MODULE_ID(3, 6)
#define MODULE_SB2         MODULE_ID(3, 0xf)


#define MODULE_SB3_AEE              MODULE_ID(4, 0)
#define MODULE_SB3_ADE              MODULE_ID(4, 1)
#define MODULE_SB3_ME               MODULE_ID(4, 2)
#define MODULE_SB3_MD_KC            MODULE_ID(4, 3)
#define MODULE_SB3_VE               MODULE_ID(4, 4)
#define MODULE_SB3_VDE              MODULE_ID(4, 5)
#define MODULE_SB3_UART2            MODULE_ID(4, 0xa)
#define MODULE_SB3_MD_NKC           MODULE_ID(4, 0xb)
#define MODULE_SB3_MD_VC            MODULE_ID(4, 0xc)
#define MODULE_SB3            MODULE_ID(4, 0xf)

//#define MODULE_VE                   MODULE_ID(5, 0)
#define MODULE_VE                   MODULE_ID(5,0xf)
#define MODULE_VE_0                 MODULE_ID(5,0)
#define MODULE_VE_1                 MODULE_ID(5,1)
#define MODULE_VE_2                 MODULE_ID(5,2)
#define MODULE_VE_3                 MODULE_ID(5,3)
#define MODULE_VE_4                 MODULE_ID(5,4)
#define MODULE_VE_5                 MODULE_ID(5,5)
#define MODULE_VE_6                 MODULE_ID(5,6)
#define MODULE_VE_7                 MODULE_ID(5,7)
#define MODULE_VE_8                 MODULE_ID(5,8)
#define MODULE_VE_9                 MODULE_ID(5,9)
#define MODULE_VE_10                 MODULE_ID(5,10)
#define MODULE_VE_11                 MODULE_ID(5,11)
#define MODULE_VE_12                 MODULE_ID(5,12)
#define MODULE_VE_13                 MODULE_ID(5,13)
#define MODULE_VE_14                 MODULE_ID(5,14)

#define MODULE_TVSB3_PST             MODULE_ID(6, 0)
#define MODULE_TVSB3      MODULE_ID(6, 0xf)

#define MODULE_GPU_0                  MODULE_ID(7, 0)
#define MODULE_GPU_1                  MODULE_ID(7, 1)
#define MODULE_GPU_2                  MODULE_ID(7, 2)
#define MODULE_GPU_3                  MODULE_ID(7, 3)
#define MODULE_GPU_4                  MODULE_ID(7, 4)
#define MODULE_GPU_5                  MODULE_ID(7, 5)
#define MODULE_GPU_6                  MODULE_ID(7, 6)
#define MODULE_GPU_7                  MODULE_ID(7, 7)
#define MODULE_GPU_8                  MODULE_ID(7, 8)
#define MODULE_GPU_9                  MODULE_ID(7, 9)
#define MODULE_GPU_10                  MODULE_ID(7, 10)
#define MODULE_GPU_11                  MODULE_ID(7, 11)
#define MODULE_GPU_12                  MODULE_ID(7, 12)
#define MODULE_GPU_13                  MODULE_ID(7, 13)
#define MODULE_GPU_14                  MODULE_ID(7, 14)
#define MODULE_GPU                  MODULE_ID(7,0xf)

#define MODULE_TVSB5_DEMOD          MODULE_ID(8, 0)
#define MODULE_TVSB5_DBGDMA            MODULE_ID(8, 1)
#define MODULE_TVSB5            MODULE_ID(8, 0xf)

#define MODULE_SE2_Q0               MODULE_ID(0xa, 0)
#define MODULE_SE2_Q1               MODULE_ID(0xa, 1)
#define MODULE_SE2               MODULE_ID(0xa, 0xf)

#define MODULE_TVSB4_ODW            MODULE_ID(0xb, 0)
#define MODULE_TVSB4_ODR            MODULE_ID(0xb, 1)
#define MODULE_TVSB4_DC2H           MODULE_ID(0xb, 2)
#define MODULE_TVSB4_SUBT           MODULE_ID(0xb, 3)
#define MODULE_TVSB4_OSD1           MODULE_ID(0xb, 4)
#define MODULE_TVSB4_OSD2           MODULE_ID(0xb, 5)
#define MODULE_TVSB4_OSD3           MODULE_ID(0xb, 6)
#define MODULE_TVSB4_DMATO3DLUTR   MODULE_ID(0xb, 0xb)
#define MODULE_TVSB4_OSD_FBDC   MODULE_ID(0xb, 0xe)
#define MODULE_TVSB4         MODULE_ID(0xb, 0xf)

#define MODULE_ANY                  MODULE_ID(0xf, 0xf)

#define isnumber(c)      (c>=0x30 && c<=0x39)
#define isalphabet(c)    (c>=0x41 && c<=0x5A) || (c>=0x61 && c<=0x7A)
#define isalnum(c)       (isnumber(c) || isalphabet(c))


#endif //__DC_MT_CFG__
