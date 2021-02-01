/*
  *Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
  */
#ifndef __RTK_PCMCIA_REG_H__
#define __RTK_PCMCIA_REG_H__


#include <rbus/pcmcia_reg.h>
#include <rtk_kdriver/rtk_crt.h>

#define CONFIG_ENABLE_PCMCIA_FIFO_MODE

#define PCMCIA_SOFT_RESET      SYS_REG_SYS_SRST2_reg
#define PCMCIA_CLOCK_ENABLE    SYS_REG_SYS_CLKEN2_reg


void PCMCIA_ClockEnable(unsigned char On)
{
    if (On)
    {
        CRT_CLK_OnOff(PCMCIA, CLK_ON, NULL);
    }
    else
    {
        CRT_CLK_OnOff(PCMCIA, CLK_OFF, NULL);
    }
}

#define TP_OUT_CTRL_REG             (0xB8014094)
#define TP_OUT_SHARE_MODE(x)        (((x) & 0x01) << 24)
#define TP_OUT_SHARE_HW_MODE        TP_OUT_SHARE_MODE(1)
#define TP_OUT_SHARE_EN             (1 << 23)
#define TP_OUT_STOP_MODE            (1 << 22)
#define TP_OUT_DATA_SEL(x)          (((x) & 0x01) << 4)
#define TP_OUT_DATA_SEL_PCMCIA      TP_OUT_DATA_SEL(1)

#define TP_OUT_INT_REG              (0xB8014098)
#define TP_PAUSE_INT                (1 << 2)
#define TP_OUT_INT_WRITE_DATA       (1 << 0)

#define SET_TP_OUT_CTRL_REG(x)       rtd_outl(TP_OUT_CTRL_REG, x)
#define GET_TP_OUT_CTRL_REG()        rtd_inl(TP_OUT_CTRL_REG)
#define GET_TP_OUT_INT_REG()         rtd_inl(TP_OUT_INT_REG)
#define SET_TP_OUT_INT_REG(x)        rtd_outl(TP_OUT_INT_REG, x)
#define CLEAR_TP_PUASE_INT()         SET_TP_OUT_INT_REG(TP_PAUSE_INT)

#define PCMCIA_INT             (0xB801B000)
#define PCMCIA_INT_MASK        (0x00000001 << 21)


#define EJTAG_MODE_EN_MASK          (0x2)
#define EJTAG_MODE_REG              (0xB8060008)
#define GET_EJTAG_MODE_REG()        (rtd_inl(EJTAG_MODE_REG))
#define IS_EJTAG_MODE_ENABLE()      (!(GET_EJTAG_MODE_REG() & EJTAG_MODE_EN_MASK))

#define PCMCIA_REG_CMDFF            PCMCIA_MIS_PCMCIA0_CMDFF_reg
#define PCMCIA_REG_CTRL             (PCMCIA_REG_CMDFF + 0x4)
#define PCMCIA_REG_STS              (PCMCIA_REG_CMDFF + 0x8)
#define PCMCIA_REG_AMTC_0           (PCMCIA_REG_CMDFF + 0xC)
#define PCMCIA_REG_AMTC_1           (PCMCIA_REG_CMDFF + 0x28)
#define PCMCIA_REG_IOMTC            (PCMCIA_REG_CMDFF + 0x10)
#define PCMCIA_REG_MATC_0           (PCMCIA_REG_CMDFF + 0x14)
#define PCMCIA_REG_MATC_1           (PCMCIA_REG_CMDFF + 0x2C)
#define PCMCIA_REG_ACTRL            (PCMCIA_REG_CMDFF + 0x18)
#define PCMCIA_REG_FIFO_CTRL        (PCMCIA_REG_CMDFF + 0x1C)
#define PCMCIA_REG_NUM_TOTAL        (PCMCIA_REG_CMDFF + 0x30)
#define PCMCIA_REG_FIFO_STATUS      (PCMCIA_REG_CMDFF + 0x20)
#define PCMCIA_REG_PIN_SEL          (PCMCIA_REG_CMDFF + 0x24)

/*-- PCMCIA_CMDFF --*/
#define PC_CT(x)                   (((x) & 0x01) << 24)
#define PC_CT_READ                 PC_CT(0)
#define PC_CT_WRITE                PC_CT(1)
#define PC_AT(x)                   (((x) & 0x01) << 23)
#define PC_AT_IO                   PC_AT(0)
#define PC_AT_ATTRMEM              PC_AT(1)
#define PC_PA(x)                   (((x) & 0x7FFF) << 8)
#define PC_DF(x)                   (((x) & 0xFF))

/*-- PCMCIA_CTRL --*/
#define PC_PSR                    (0x00000001 << 31)
#define PC_CE1_CARD1              (0x00000001 << 30)
#define PC_CE1_CARD2              (0x00000001 << 29)
#define PC_CE2_CARD1              (0x00000001 << 28)
#define PC_CE2_CARD2              (0x00000001 << 27)
#define PC_CE_MASK                (PC_CE1_CARD1 | PC_CE1_CARD2 | PC_CE2_CARD1 | PC_CE2_CARD2)

#define PC_PCR1                   (0x00000001 << 26)
#define PC_PCR2                   (0x00000001 << 25)
#define PC_PCR1_OE                (0x00000001 << 24)
#define PC_PCR2_OE                (0x00000001 << 23)
#define PC_PCR_SEL(x)             (((x) & 0x3) << 21)
#define PC_PCR_SEL_MASK           (0x3 << 21)
#define PC_FIFO_R_EN              (0x00000001 << 11)
#define PC_FIFO_W_EN              (0x00000001 << 10)
#define PC_FIFO_ERROR_EN          (0x00000001 << 9)
#define PC_FIFO_WR_OVER_EN        (0x00000001 << 8)
#define PC_PIIE1                  (0x00000001 << 7)
#define PC_PCIIE1                 (0x00000001 << 6)
#define PC_PCRIE1                 (0x00000001 << 5)
#define PC_PIIE2                  (0x00000001 << 4)
#define PC_PCIIE2                 (0x00000001 << 3)
#define PC_PCRIE2                 (0x00000001 << 2)
#define PC_AFIE                   (0x00000001 << 1)
#define PC_APFIE                  (0x00000001)

#define PC_ACCESS_INT             (PC_AFIE | PC_APFIE)
#define PC_CARD_DETECT1_INT       (PC_PCIIE1 | PC_PCRIE1)
#define PC_CARD_DETECT2_INT       (PC_PCIIE2 | PC_PCRIE2)
#define PC_FIFO_INT               (PC_FIFO_R_IE | PC_FIFO_W_IE | PC_FIFO_ERRO_IE | PC_FIFO_WR_OVER_IE)
#define PC_FIFO_RX_INT            (PC_FIFO_R_IE | PC_FIFO_ERRO_IE | PC_FIFO_WR_OVER_IE)
#define PC_FIFO_TX_INT            (PC_FIFO_W_IE | PC_FIFO_ERRO_IE | PC_FIFO_WR_OVER_IE)

/*-- PCMCIA_STS --*/
#define PC_PRES1                  (0x00000001 << 13)
#define PC_PRES2                  (0x00000001 << 12)
#define PC_FIFO_R_IE              (0x00000001 << 11)
#define PC_FIFO_W_IE              (0x00000001 << 10)
#define PC_FIFO_ERRO_IE           (0x00000001 << 9)
#define PC_FIFO_WR_OVER_IE        (0x00000001 << 8)
#define PC_PII1                   (0x00000001 << 7)
#define PC_PCII1                  (0x00000001 << 6)
#define PC_PCRI1                  (0x00000001 << 5)
#define PC_PII2                   (0x00000001 << 4)
#define PC_PCII2                  (0x00000001 << 3)
#define PC_PCRI2                  (0x00000001 << 2)
#define PC_AFI                    (0x00000001 << 1)
#define PC_APFI                   (0x00000001)

#ifdef CONFIG_MACH_RTK_294X
/* in Mac3 demo board , the interrupt pin is connnected with Int1. */
/* other control pins are connected with Card0. */
#undef PC_PII1
#undef PC_PII2
#undef PC_PIIE1
#undef PC_PIIE2

#define PC_PII1         (0x00000001 << 4)
#define PC_PII2         (0x00000001 << 7)

#define PC_PIIE1        (0x00000001 << 4)
#define PC_PIIE2        (0x00000001 << 7)

#endif    /*
 */

/*-- PCMCIA_AMTC_0 --*/
#define PC_TWE(x)       (((x) & 0x3FF) << 16)
#define PC_THD(x)       (((x) & 0xFF) << 8)
#define PC_TSU(x)       (((x) & 0xFF))

/*-- PCMCIA_AMTC_1 --*/
#define PC_TAOE(x)      (((x) & 0x3FF) << 16)
#define PC_THCE(x)      (((x) & 0x3F))


/*-- PCMCIA_IOMTC --*/
#define PC_TDIORD(x)     (((x) & 0xFF) << 24)
#define PC_TSUIO(x)      (((x) & 0xFF) << 16)
#define PC_TDINPACK(x)   (((x) & 0x7F) << 8)
#define PC_TDWT(x)       (((x) & 0x7F))

/*-- PCMCIA_MATC_0 --*/
#define PC_TC(x)         (((x) & 0x3FF) << 16)
#define PC_THDIO(x)      (((x) & 0x3F))

/*-- PCMCIA_MATC_1 --*/
#define PC_TCIO(x)       (((x) & 0x1FF) << 16)
#define PC_TWIOWR(x)     (((x) & 0x1FF))

/*-- PCMCIA_ACTRL --*/
#define PC_OE(x)         (((x) & 0x7FFF))


/*-- PCMCIA_FIFO_CTRL --*/
#define PC_ADDR_STEP(x)                     (((x) & 0x1) << 31)
#define PC_WR_NUM(x)                        (((x) & 0x7FFF) << 8)
#define PC_FIFO_R_TRIG(x)                   (((x) & 0x3) << 4)
#define PC_PIN_SHARE_SEL(x)                 (((x) & 0x1) << 3)
#define PC_PIN_SHARE_SEL_SOFT_MODE          PC_PIN_SHARE_SEL(1)
#define PC_FIFO_WR_MODE(x)                  (((x) & 0x3) << 1)
#define PC_FIFO_WR_MODE_ADDRESS_NOCHANGE    PC_FIFO_WR_MODE(0)
#define PC_FIFO_WR_MODE_ADDRESS_INCREASE    PC_FIFO_WR_MODE(1)
#define PC_FIFO_WR_MODE_ADDRESS_DECREASE    PC_FIFO_WR_MODE(2)
#define PC_FIFO_EN(x)                       (((x) & 0x1))

/*-- PCMCIA_NUM_TOTAL --*/
#define PC_WR_NUM_TOTAL(x)        ((x))

/*-- PCMCIA_FIFO_STATUS --*/
#define PC_FIFO_LEN(x)        (((x) >> 8) & 0x3F)
#define PC_FIFO_EMPTY(x)      (((x) >> 1) & 0x1)
#define PC_FIFO_FULL(x)       (((x) & 0x01))


/*-- PCMCIA_PIN_SEL  --*/
#define PC_INPACK1_DIS(x)     (((x) & 0x01) << 5)
#define PC_INPACK0_DIS(x)     (((x) & 0x01) << 4)
#define PC_WAIT1_DIS(x)       (((x) & 0x03) << 2)
#define PC_WAIT0_DIS(x)       (((x) & 0x03))


#define SET_PCMCIA_CMDFF(x)                   rtd_outl(PCMCIA_REG_CMDFF,   x)
#define SET_PCMCIA_CTRL(x)                    rtd_outl(PCMCIA_REG_CTRL,    x)
#define SET_PCMCIA_STS(x)                     rtd_outl(PCMCIA_REG_STS,     x)
#define SET_PCMCIA_AMTC_0(x)                  rtd_outl(PCMCIA_REG_AMTC_0,  x)
#define SET_PCMCIA_AMTC_1(x)                  rtd_outl(PCMCIA_REG_AMTC_1,  x)
#define SET_PCMCIA_IOMTC(x)                   rtd_outl(PCMCIA_REG_IOMTC,   x)
#define SET_PCMCIA_MATC_0(x)                  rtd_outl(PCMCIA_REG_MATC_0,  x)
#define SET_PCMCIA_MATC_1(x)                  rtd_outl(PCMCIA_REG_MATC_1,  x)
#define SET_PCMCIA_ACTRL(x)                   rtd_outl(PCMCIA_REG_ACTRL,   x)
#define SET_PCMCIA_FIFO_CTRL(x)               rtd_outl(PCMCIA_REG_FIFO_CTRL,   x)
#define SET_PCMCIA_NUM_TOTAL(x)               rtd_outl(PCMCIA_REG_NUM_TOTAL,   x)
#define SET_PCMCIA_FIFO_STATUS(x)             rtd_outl(PCMCIA_REG_FIFO_STATUS, x)
#define SET_PCMCIA_FIFO_DATA( reg , data )    ( reg = (reg & 0xFFFFFF00) | (data) )


#define GET_PCMCIA_CMDFF()          rtd_inl(PCMCIA_REG_CMDFF)
#define GET_PCMCIA_CTRL()           rtd_inl(PCMCIA_REG_CTRL)
/*#define GET_PCMCIA_STS()          rtd_inl(PCMCIA_REG_STS)*/
#define GET_PCMCIA_AMTC_0()         rtd_inl(PCMCIA_REG_AMTC_0)
#define GET_PCMCIA_AMTC_1()         rtd_inl(PCMCIA_REG_AMTC_1)
#define GET_PCMCIA_IOMTC()          rtd_inl(PCMCIA_REG_IOMTC)
#define GET_PCMCIA_MATC_0()         rtd_inl(PCMCIA_REG_MATC_0)
#define GET_PCMCIA_MATC_1()         rtd_inl(PCMCIA_REG_MATC_1)
#define GET_PCMCIA_ACTRL()          rtd_inl(PCMCIA_REG_ACTRL)
#define GET_PCMCIA_FIFO_CTRL()      rtd_inl(PCMCIA_REG_FIFO_CTRL)
#define GET_PCMCIA_NUM_TOTAL()      rtd_inl(PCMCIA_REG_NUM_TOTAL)
#define GET_PCMCIA_FIFO_STATUS()	rtd_inl(PCMCIA_REG_FIFO_STATUS)
#define GET_PCMCIA_FIFO_DATA()      ( (unsigned char)(GET_PCMCIA_CMDFF() & 0xFF) )


#endif
