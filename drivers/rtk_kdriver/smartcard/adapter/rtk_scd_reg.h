#ifndef __RTK_SCD_REG_H__
#define __RTK_SCD_REG_H__

#include <mach/irqs.h>
//#include <rbus/crt_reg.h>
#include <rbus/misc_reg.h>
#include <rbus/iso_misc_reg.h>
#include <rbus/misc_smartcard0_reg.h>

#define MISC_IRQ                IRQ_MISC

/* Smart Card Feature Block*/

/* SC_FP - SC Frequency Programmer*/
#define SC_CLK_EN(x)            ((x & 0x00000001)<<24)
#define SC_CLKDIV(x)            ((x & 0x0000003F)<<18)
#define SC_BAUDDIV2(x)          ((x & 0x00000003)<<16)
#define SC_BAUDDIV1(x)          ((x & 0x000000FF)<<8)
#define SC_PRE_CLKDIV(x)        ((x & 0x000000FF))
#define SC_CLKDIV_MASK          SC_CLKDIV(0x3F)
#define SC_BAUDDIV2_MASK        SC_BAUDDIV2(0x3)
#define SC_BAUDDIV1_MASK        SC_BAUDDIV1(0xFF)
#define SC_BAUDDIV_MASK         (SC_BAUDDIV1_MASK | SC_BAUDDIV2_MASK)
#define SC_PRE_CLKDIV_MASK      SC_PRE_CLKDIV(0xFF)

#define SC_CLK_EN_VAL(x)        ((x << 24) & 0x00000001)
#define SC_CLKDIV_VAL(x)        ((x << 18) & 0x0000003F)
#define SC_BAUDDIV2_VAL(x)      ((x << 16) & 0x00000003)
#define SC_BAUDDIV1_VAL(x)      ((x <<  8) & 0x000000FF)
#define SC_PRE_CLKDIV_VAL(x)    ((x & 0x000000FF))

/*SC_CR - SC Control Register*/
#define SC_FIFO_RST(x)          ((x & 0x00000001)<<31)
#define SC_RST(x)               ((x & 0x00000001)<<30)
#define SC_SCEN(x)              ((x & 0x00000001)<<29)
#define SC_TX_GO(x)             ((x & 0x00000001)<<28)
#define SC_AUTO_ATR(x)          ((x & 0x00000001)<<27)
#define SC_CONV(x)              ((x & 0x00000001)<<26)
#define SC_CLK_STOP(x)          ((x & 0x00000001)<<25)
#define SC_PS(x)                ((x & 0x00000001)<<24)

#define SC_PS_VAL(x)            ((x >> 24) & 0x00000001)

/*SCPCR - SC Protocol control Register */
#define SC_TXGRDT(x)          ((x & 0x000000FF)<<24)
#define SC_CWI(x)             ((x & 0x0000000F)<<20)
#define SC_BWI(x)             ((x & 0x0000000F)<<16)
#define SC_WWI(x)             ((x & 0x0000000F)<<12)
#define SC_BGT(x)             ((x & 0x0000001F)<<7)
#define SC_EDC_EN(x)          ((x & 0x00000001)<<6)
#define SC_CRC(x)             ((x & 0x00000001)<<5)
#define SC_PROTOCOL_T(x)      ((x & 0x00000001)<<4)
#define SC_T0RTY(x)           ((x & 0x00000001)<<3)
#define SC_T0RTY_CNT(x)       ((x & 0x00000007))

#define MASK_SC_TXGRDT        SC_TXGRDT(0xFF)
#define MASK_SC_CWI           SC_CWI(0xF)
#define MASK_SC_BWI           SC_BWI(0xF)
#define MASK_SC_WWI           SC_WWI(0xF)
#define MASK_SC_BGT           SC_BGT(0x1F)
#define MASK_SC_EDC_EN        SC_EDC_EN(1)
#define MASK_SC_EDC_TYPE      SC_CRC(1)
#define MASK_SC_PROTOCOL      SC_PROTOCOL_T(1)
#define MASK_SC_T0RTY         SC_T0RTY(1)
#define MASK_SC_T0RTY_CNT     SC_T0RTY_CNT(1)

/*SC_FCR - Flow Control Register*/
#define SC_RXFLOW(x)          ((x & 0x00000001)<<1)
#define SC_FLOW_EN(x)         ((x & 0x00000001))

/*SCIRSR & SCIRER - SC Interrupt Status/Enable Register*/
#define SC_DRDY_INT           0x00000001
#define SC_RCV_INT            0x00000002
#define SC_BWT_INT            0x00000004
#define SC_WWT_INT            0x00000008
#define SC_RLEN_INT           0x00000010
#define SC_CWT_INT            0x00000020
#define SC_BGT_INT            0x00000040
#define SC_ATRS_INT           0x00000080
#define SC_RXP_INT            0x00000100
#define SC_RX_FOVER_INT       0x00000200
#define SC_EDCERR_INT         0x00000400
#define SC_TXEMPTY_INT        0x00000800
#define SC_TXDONE_INT         0x00001000
#define SC_TXP_INT            0x00002000
#define SC_TXFLOW_INT         0x00004000
#define SC_CPRES_INT          0x00008000
#define SC_PRES               0x00010000




#define RTK_GPIO_MISC_INT		    MISC_isr_reg
#define RTK_GPIO_MISC_INT_MASK		(0x1 << MISC_isr_gpio_int_shift)
#define RTK_GPIO_ISO_INT		    ISO_MISC_ISR_reg
#define RTK_GPIO_ISO_INT_MASK		(0x1 << ISO_MISC_ISR_gpio_int_shift)


#define MAX_IFD_CNT             1
#define IFD_MODOLE              "RTD284X"
#define SYSTEM_CLK              250000000  /*180000000 ?*/

static const SC_REG SCReg[MAX_IFD_CNT] = {
		{
				.INT_EN   = MISC_isr_reg,  
				.INT_MASK = 0,
				.ISR      = MISC_isr_reg,
				.ISR_MASK = (1<<24),
				.FP       = MISC_SMARTCARD0_SC_FP_reg,
				.CR       = MISC_SMARTCARD0_SC_CR_reg,
				.PCR      = MISC_SMARTCARD0_SC_PCR_reg,
				.TXFIFO   = MISC_SMARTCARD0_SC_TXFIFO_reg,
				.RXFIFO   = MISC_SMARTCARD0_SC_RXFIFO_reg,
				.RXLENR   = MISC_SMARTCARD0_SC_RXLENR_reg,
				.FCR      = MISC_SMARTCARD0_SC_FCR_reg,
				.IRSR     = MISC_SMARTCARD0_SC_IRSR_reg,
				.IRER     = MISC_SMARTCARD0_SC_IRER_reg,
		},		
};




#endif /*__RTK_SCD_REG_H__*/
