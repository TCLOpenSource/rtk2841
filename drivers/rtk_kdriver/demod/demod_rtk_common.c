#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/firmware.h>
#include <linux/device.h>
#include <rtk_kdriver/rtk_crt.h>
#include <mach/io.h>
#include <asm/cacheflush.h>
#include "demod_rtk_common.h"
#include "comm.h"
#include "tv_osal.h"
#include "ifd_analog.h"

//#include "demodrbus/sys_reg_reg.h"
//#include "demodrbus/ifd_108_reg.h"
#include "rbus/tv_sb1_ana_reg.h"
#include "rbus/dtv_frontend_reg.h"
#include "rbus/diseqc_reg.h"
#include "rbus/img_demod_bus_reg.h"
#include "rbus/demod_sd_reg.h"

#include "demodcore/message_func_rtk.h"

#include <linux/dma-mapping.h>


extern unsigned char SecondaryLoader[];
extern unsigned long SecondaryLoaderSize;

extern unsigned char DvbT2LdrArray[];
extern unsigned long DvbT2LdrArraySize;
extern unsigned char DvbT2LdrVersion[];
extern unsigned char DvbT2LdrTunerModule[];
extern unsigned char DvbTLdrArray[];
extern unsigned long DvbTLdrArraySize;
extern unsigned char DvbTLdrVersion[];
extern unsigned char DvbTLdrTunerModule[];
extern unsigned char DvbCLdrArray[];
extern unsigned long DvbCLdrArraySize;
extern unsigned char DvbCLdrVersion[];
extern unsigned char DvbCLdrTunerModule[];
extern unsigned char IsdbtLdrArray[];
extern unsigned long IsdbtLdrArraySize;
extern unsigned char IsdbtLdrVersion[];
extern unsigned char IsdbtLdrTunerModule[];
extern unsigned char DvbS2XLdrArray[];
extern unsigned long DvbS2XLdrArraySize;
extern unsigned char DvbS2XLdrVersion[];
extern unsigned char DvbS2XLdrTunerModule[];
extern unsigned char DvbS2LdrArray[];
extern unsigned long DvbS2LdrArraySize;
extern unsigned char DvbS2LdrVersion[];
extern unsigned char DvbS2LdrTunerModule[];
extern unsigned char DvbSLdrArray[];
extern unsigned long DvbSLdrArraySize;
extern unsigned char DvbSLdrVersion[];
extern unsigned char DvbSLdrTunerModule[];
extern unsigned char DvbSBsLdrArray[];
extern unsigned long DvbSBsLdrArraySize;
extern unsigned char DvbSBsLdrVersion[];
extern unsigned char DvbSBsLdrTunerModule[];
extern unsigned char SpecAnLdrArray[];
extern unsigned long SpecAnLdrArraySize;
extern unsigned char SpecAnLdrVersion[];
extern unsigned char SpecAnLdrTunerModule[];
extern unsigned char AtscLdrArray[];
extern unsigned long AtscLdrArraySize;
extern unsigned char AtscLdrVersion[];
extern unsigned char AtscLdrTunerModule[];
extern unsigned char QamLdrArray[];
extern unsigned long QamLdrArraySize;
extern unsigned char QamLdrVersion[];
extern unsigned char QamLdrTunerModule[];
RTK_DEMOD_MODE m_realtek_TvSys_mode;


/*------------------------------------------------------------------------------
 * Chip Initialization
 *------------------------------------------------------------------------------*/
//#define rtd_outl(addr, value)   pli_writeReg32(addr, value)
//#define rtd_inl(addr)           pli_readReg32(addr)
//#define rtd_maskl(addr, mask, value)    rtd_outl(addr, ((rtd_inl(addr) & mask) | value))

#define _BIT(x)       (1UL <<x)
#define _BIT0          _BIT(0 )
#define _BIT1          _BIT(1 )
#define _BIT2          _BIT(2 )
#define _BIT3          _BIT(3 )
#define _BIT4          _BIT(4 )
#define _BIT5          _BIT(5 )
#define _BIT6          _BIT(6 )
#define _BIT7          _BIT(7 )
#define _BIT8          _BIT(8 )
#define _BIT9          _BIT(9 )
#define _BIT10         _BIT(10)
#define _BIT11         _BIT(11)
#define _BIT12         _BIT(12)
#define _BIT13         _BIT(13)
#define _BIT14         _BIT(14)
#define _BIT15         _BIT(15)
#define _BIT16         _BIT(16)
#define _BIT17         _BIT(17)
#define _BIT18         _BIT(18)
#define _BIT19         _BIT(19)
#define _BIT20         _BIT(20)
#define _BIT21         _BIT(21)
#define _BIT22         _BIT(22)
#define _BIT23         _BIT(23)
#define _BIT24         _BIT(24)
#define _BIT25         _BIT(25)
#define _BIT26         _BIT(26)
#define _BIT27         _BIT(27)
#define _BIT28         _BIT(28)
#define _BIT29         _BIT(29)
#define _BIT30         _BIT(30)
#define _BIT31         _BIT(31)

#define REG_RTK_DEMOD_8051_SRAM_WRITE_EN 0xB807223C

//static int DtvDemodInit = 0;
static int DtvDemodReset = 0;
static int pli_ready = 0;
unsigned long RbusAddr = 0;
unsigned char TunerInputMode = 1;//DVBS Demod default use differential mode

int DtvGetChipVersion()
{
	return 0;
}


int DtvGetICVersion()
{
	return 0;
}


int DtvDemodPowerControl(unsigned char On)
{
	if(On) {
		CRT_CLK_OnOff(DIGDEMOD, CLK_ON, NULL);
		RTK_DEMOD_INFO("demod is power on.\n");
	} else {
		CRT_CLK_OnOff(DIGDEMOD, CLK_OFF, NULL);
		RTK_DEMOD_INFO("demod is power down.\n");
		pli_ready = 0;
	}

	return FUNCTION_SUCCESS;
}


int DtvDemodEnable(RTK_DEMOD_MODE mode)
{
	switch (mode) {
	case RTK_DEMOD_MODE_DTMB:
		CRT_CLK_OnOff(DIGDEMOD_HDIC_EN, CLK_ON, NULL);
		RTK_DEMOD_INFO("DtvDemodEnable to DTMB\n");
		break;

	case RTK_DEMOD_MODE_ATSC:
		CRT_CLK_OnOff(DIGDEMOD_RTK_EN, CLK_ON, NULL);
		RTK_DEMOD_INFO("DtvDemodEnable to ATSC\n");
		break;

	case RTK_DEMOD_MODE_DVBS:
	case RTK_DEMOD_MODE_DVBS2:
	case RTK_DEMOD_MODE_DVBS2X:
	case RTK_DEMOD_MODE_SPEC_AN:
		CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);
		CRT_CLK_OnOff(DIGDEMOD_IMG_EN, CLK_ON, NULL);
		RTK_DEMOD_INFO("DtvDemodEnable to Satellite\n");
		break;
		
	default:
		CRT_CLK_OnOff(DIGDEMOD_IMG_EN, CLK_ON, NULL);
		RTK_DEMOD_INFO("DtvDemodEnable mode = %d\n", mode);
		break;
	}
	return 0;
}


int DtvIsDemodClockEnable(RTK_DEMOD_MODE mode)
{	
	unsigned long sysclk0 = rtd_inl(SYS_REG_SYS_CLKEN0_reg);
	unsigned long sysclk2 = rtd_inl(SYS_REG_SYS_CLKEN2_reg);
	unsigned long sysrst0 = rtd_inl(SYS_REG_SYS_SRST0_reg);
	unsigned long sysrst2 = rtd_inl(SYS_REG_SYS_SRST2_reg);
	unsigned long SysRstCheckCom = 0, SysRstCheckMode = 0;
	unsigned long SysClkCheckCom = 0, SysClkCheckMode = 0;

	SysClkCheckCom = SYS_REG_SYS_CLKEN0_get_clken_dtv_frontend(sysclk0)&SYS_REG_SYS_CLKEN2_get_clken_dtv_demod(sysclk2);
	SysRstCheckCom = SYS_REG_SYS_SRST0_get_rstn_dtv_frontend(sysrst0)&SYS_REG_SYS_SRST2_get_rstn_dtv_demod(sysrst2);

	if (mode == RTK_DEMOD_MODE_DTMB) {
		SysClkCheckMode = SYS_REG_SYS_CLKEN0_get_clken_hdic(sysclk0);
		SysRstCheckMode = SYS_REG_SYS_SRST0_get_rstn_hdic_apb(sysrst0) & SYS_REG_SYS_SRST0_get_rstn_hdic_axi(sysrst0) & SYS_REG_SYS_SRST0_get_rstn_hdic(sysrst0);
	} else if (mode == RTK_DEMOD_MODE_ATSC) {
		SysClkCheckMode = SYS_REG_SYS_CLKEN0_get_clken_rtk_demod(sysclk0);
		SysRstCheckMode = SYS_REG_SYS_SRST0_get_rstn_rtk_demod(sysrst0);
	} else {
		SysClkCheckMode = SYS_REG_SYS_CLKEN0_get_clken_img_demod(sysclk0);
		SysRstCheckMode = SYS_REG_SYS_SRST0_get_rstn_img_demod(sysrst0);
	}

	if (SysClkCheckCom & SysRstCheckCom & SysClkCheckMode &  SysRstCheckMode) {
		return 1;
	} else {
		RTK_DEMOD_WARNING("Check DTV Demod Clock Off in DtvIsDemodClockEnable; standard = %d, SYS_CLKEN0 = %x, SYS_CLKEN2 = %x, SYS_SRST0 =%x, SYS_SRST2 =%x\n", mode, sysclk0, sysclk2, sysrst0, sysrst2);
		return 0;
	}
}

int DtvPGAControl(unsigned char PGAEnable, IFADCGAIN PGAGain)
{
	if (PGAGain<PGAFIX_0DB) 
	{
		RTK_DEMOD_INFO("PGA Control : FIX PGA gain -%d dB\n",PGAGain);
		PGAGain = (-1)*PGAGain;
		rtd_maskl(TV_SB1_ANA_IQADC_CTRL2_reg, ~(0x7 << 4), (PGAGain << 4));
		rtd_maskl(TV_SB1_ANA_IQADC_CTRL5_reg, ~(0x7), (0x0));
	} else {
		RTK_DEMOD_INFO("PGA Control : FIX PGA gain %d dB\n",PGAGain);
		rtd_maskl(TV_SB1_ANA_IQADC_CTRL2_reg, ~(0x7 << 4), (0x0 << 4));
		rtd_maskl(TV_SB1_ANA_IQADC_CTRL5_reg, ~(0x7), (PGAGain));
	}
	return 0;
}


void  DtvDumpShareRegStatus(void)
{
	return;
}


void DemodAdcDefault(void)
{
	//past from script

	//register default
	rtd_outl(0xb8033100,0x00010100);					//IFD MBIAS power on(bit16=1), ADC2X_BG_SEL= 01(1.217V)
	rtd_outl(0xb8033104,0x00000040);					//bit[6:4]= 100, bit24 = 0, other bit = Reserved
	//rtd_outl(0xb8033108,0x00000000);              			//all bit = Reserved
	//rtd_outl(0xb803310c,0x00000000);					//all bit = Reserved
	//rtd_outl(0xb8033110,0x00000000);					//all bit = Reserved
	//rtd_outl(0xb8033114,0x00000000);					//all bit = Reserved
	rtd_outl(0xb8033118,0x30200010);					//REG_CKOUT_SEL_Q: the default is "1:I_CKOUT" on AIF spec
	//rtd_outl(0xb803311c,0x00000000);					//all bit = Reserved								
	rtd_outl(0xb8033120,0x00440000);					//IF_FIX_EN register
	//rtd_outl(0xb8033124,0x00000000);					//PGA/ADC Power Off
	rtd_outl(0xb8033124,0x00000101);					//I_ADC PGA/ADC Power on
	rtd_outl(0xb8033128,0x00000022);					//Default setting(10=20uA), IQ PGA CURRENT  select
		
	//IFADC+IFPGA power on
	rtd_maskl(0xb8033100, 0xFEEEFF00, 0x00010002);		//turn on MBIAS
	rtd_maskl(0xb8033104, 0xFEFFFFFF, 0x01000000);		//REG_ADC2X_DIFPOW, IFADC input cm power on
	rtd_maskl(0xb8033128, 0x8fc8fccc, 0x00020022);		//I PGA input select = IFD input, Q PGA input select = No input, REG_IB20U_IPGA_SEL = 10(20uA)

	//IQADC+IQPGA power on
	rtd_outl(0xb803312C,0x00000000);					//	
	rtd_outl(0xb8033130,0x00000000);					//
	rtd_outl(0xb8033134,0x22000022);					//REG_IADC_LDO_SEL = 010, REG_QADC_LDO_SEL = 010, IADC, QADC_META_POW = turn off, REG_IADC_VREF_SEL = 10, REG_QADC_VREF_SEL = 10

	//Set IFPGA GAIN = 2dB
	rtd_maskl(0xb8033120, 0xfffffc00, 0x00000001);		//IFPGA select depend on REG_IPGA_D<3:0>, FIX gain turn off, IF ADC GAIN FIX EN = 0x1, Q_PGA by DTV
	rtd_maskl(0xb803312c, 0xffffcc00, 0x00000022);		//Q_CKIN_Sel = 00, I_CKIN_Sel = 00: From PLL27X_IFADC, REG_IPGA_Q and REG_IPGA_D GAIN set to 0010(2dB)

}


void DemodAdcSetting(RTK_DEMOD_MODE mode)
{
	CRT_CLK_OnOff(DIGDEMOD_ADC_EN, CLK_ON, NULL);

	DemodAdcDefault();
    
	switch (mode) {
	case RTK_DEMOD_MODE_DVBS:
	case RTK_DEMOD_MODE_DVBS2:
	case RTK_DEMOD_MODE_DVBS2X:
		rtd_outl(0xb8033124,0x00001111);				//I, Q_ADC PGA/ADC Power on
		rtd_maskl(0xb8033128, 0x8fc8fccc, 0x10010022);	//I PGA input select = I input, Q PGA input select = Q input, REG_IB20U_QPGA_SEL = 10(20uA), REG_IB20U_IPGA_SEL= 10(20uA)
		if(TunerInputMode == 0)
		{
			rtd_outl(0xb803312c, 0x00110022);	//Select to Single End
			RTK_DEMOD_INFO("DemodAdcSetting to Satellite(Single End + 2dB)\n");
		}
		else
		{
			rtd_outl(0xb803312c, 0x00000000);	//Select to Differential
			RTK_DEMOD_INFO("DemodAdcSetting to Satellite(Differential + 0dB)\n");
		}
		break;
	case RTK_DEMOD_MODE_SPEC_AN:
		rtd_outl(0xb8033124,0x00001111);				//I, Q_ADC PGA/ADC Power on
		rtd_maskl(0xb8033128, 0x8fc8fccc, 0x10010022);	//I PGA input select = I input, Q PGA input select = Q input, REG_IB20U_QPGA_SEL = 10(20uA), REG_IB20U_IPGA_SEL= 10(20uA)
		rtd_outl(0xb803312c, 0x00000000);	//Use differential for Blindscan
		RTK_DEMOD_INFO("DemodAdcSetting to Satellite Blindscan(Differential + 0dB)\n");
		break;
		
	case RTK_DEMOD_MODE_ATV:
		RTK_DEMOD_INFO("DemodAdcSetting to ATV\n");
		break;
		
	default:
		RTK_DEMOD_INFO("DemodAdcSetting to mode = %d\n",mode);
		break;
		
	udelay(300);
	}
}


int DtvDemodAdcPower(unsigned char on)
{
	return _TRUE;
}


int DtvDemodAdcPowerCheck(void)
{
	int ret = _TRUE;

	if ((rtd_inl(0xb8033114) & 0x1) != 0x0) {
		RTK_DEMOD_INFO("ADC source Fail!!!!!!!!!\n");
		ret = _FALSE;
	}

	return ret;

}


void DemodPllDefault(void)
{
	//past from script

	//register default
	rtd_outl(0xb80004c0,0x00e4a000);				//DTV PLLDIF LFP setting  M<14>+2 = 16(VCO=432M), 同Merlin2
	rtd_outl(0xb80004c4,0x00000000);				//DTV PLLDIF PLLDIF_DIVDIG_SEL = 000(2) 同Merlin2
	rtd_outl(0xb80004c8,0x00000000);				//DTVSystemCLK_Sync_SEL = 0(from PLLDIF) 同Merlin2
	//rtd_outl(0xb80004d0,0x0224000a);				//PLL27X, LFP Setting, M<10>+2=12(VCO =324M), 同Merlin2
	//rtd_outl(0xb80004d4,0x88085501);				//XTAL, LDO PowerOn and VD_PS Setting,同Merlin2
	//rtd_outl(0xb80004d8,0x00000000);				//PLL27X Poweroff and VCORSTB reset.
	//rtd_outl(0xb80004dc,0x2006ce01);				//PLL27X setting, default ATV mode, Bit25 default = 0(L2H Power), 與CRT document default 不同
	rtd_outl(0xb8000500,0x0000000c);				//IFADC CKO SEL Setting, 同Merlin2
	rtd_outl(0xb8000504,0x000a0224);				//IFADC LFP Setting, M<10>+2同=12(VCO=324M)Merlin2
	rtd_outl(0xb8000508,0x00000000);				//IFADC Poweroff and VCORSTB reset,同Merlin2

	//ScalerTimer_DelayXms(5);

	//PLDIF
	rtd_maskl(0xb80004c8, 0xfffffff8, 0x00000000);	//Reset PLLDIF[bit 0:2] set to 0
	rtd_maskl(0xb80004c8, 0xfffffff8, 0x00000006);	//Set PLLDIF_RSTB and PLLDIF_VCO set to normal
	rtd_maskl(0xb80004c8, 0xfffffff8, 0x00000007);  	//Set PLLDIF_POW, PLLDIF_RSTB and PLLDIF_VCO to power on
	rtd_maskl(0xb80004c8, 0x7fffffff, 0x80000000);	//Set DTVSysClk select CKO from PLL27X

	//PLL27X
	//rtd_maskl(0xb80004d4, 0xfff8ffff, 0x00070000);	//PLL_XIXO_Load and PLL_XIXO_Drive_SEL set to 1
	//rtd_maskl(0xb80004d8, 0xffffffe8, 0x00000017);	//PLL27X, [bit0,1,2,4] set to 1, Set PLL27X_POW, PLL23X_RSTB_VCO to power on.
	//rtd_maskl(0xb80004dc, 0xfDfffefe, 0x02000100);	//Set L2H&CKO V33 enable and MUX to DTV Mode
	//PLL27X_IFADC
	rtd_maskl(0xb8000500, 0xfffffff3, 0x0000000C);	//PPLL27X_IFADC_DTV_CKO_SEL = 00(/3), PLL27X_IFADC_ATV_CKO_SEL = 11 (135M or 162M (depend on VCO and REG_PLL27x_IFADC_DIV).
	rtd_maskl(0xb8000508, 0xfffffff8, 0x00000007);	//IFADC, RSTB and VCORSTB Power on

	//rtd_maskl(0xb80004dc, 0xfdfbfeff, 0x02040100);	//CML_L2H power, CKO EN = 1

}


void DemodPllSetting(RTK_DEMOD_MODE mode)
{
	DemodPllDefault();

	switch (mode) {
	case RTK_DEMOD_MODE_DTMB:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00004000);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x00e00000);
		rtd_maskl(0xb80004c4, 0xFFFFFF88, 0x00000000);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x80000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFCFE, 0x02000300);	
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000030);	
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x00100000);	
		RTK_DEMOD_INFO("DemodPllSetting Pll Change to DTMB \n");
		break;

	case RTK_DEMOD_MODE_QAM:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x01200000);
		rtd_maskl(0xb80004c4, 0xFFFFFF88, 0x00000007);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000010);
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to QAM(OpenCable)\n");
		break;

	case RTK_DEMOD_MODE_ATSC:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00004800);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x00E00000);
		rtd_maskl(0xb80004c4, 0xFFFFFF88, 0x00000000);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000100);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		RTK_DEMOD_INFO("DemodPllSetting to ATSC\n");
		break;

	case RTK_DEMOD_MODE_DVBT:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x00D00000);
		rtd_maskl(0xb80004c4, 0xFFFFFF88, 0x00000077);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000010);
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);	
		RTK_DEMOD_INFO("DemodPllSetting to DVBT \n");
		break;

	case RTK_DEMOD_MODE_DVBT2:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x12B00000);
		rtd_maskl(0xb80004c4, 0xFFFFFF88, 0x00000077);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000010);
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to DVBT2 \n");
		break;

	case RTK_DEMOD_MODE_ISDB:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x01200000);
		rtd_maskl(0xb80004c4, 0xFFFFFF88, 0x00000077);//system clock to 540MHz
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000010); 
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to ISDBT\n");
		break;

	case RTK_DEMOD_MODE_DVBS:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		//rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x011000000);//Sys 513M
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x12B00000);//Sys 607.5M
		//rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x13000000);//Sys 675M
		rtd_maskl(0xb80004c4, 0xFFFFFF8F, 0x00001077);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000050);//ADC 90M
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to DVBS\n");
		break;

	case RTK_DEMOD_MODE_DVBS2:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		//rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x011000000);//Sys 513M
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x12B00000);//Sys 607.5M
		//rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x13000000);//Sys 675M
		rtd_maskl(0xb80004c4, 0xFFFFFF8F, 0x00001077);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000050);//ADC 90M
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to DVBS2\n");
		break;

	case RTK_DEMOD_MODE_DVBS2X:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		//rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x011000000);//Sys 513M
		//rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x12B00000);//Sys 607.5M
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x13000000);//Sys 675M
		rtd_maskl(0xb80004c4, 0xFFFFFF8F, 0x00001077);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000050);//ADC 90M
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to DVBS2X\n");
                break; 

	case RTK_DEMOD_MODE_SPEC_AN:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x01100000);
		rtd_maskl(0xb80004c4, 0xFFFFFF8F, 0x00001077);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000010);//ADC 150M
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to SPEC AN\n");
		break;

	case RTK_DEMOD_MODE_DVBC:
	default:
		rtd_maskl(0xb8000214, 0xFFFFB7FF, 0x00000000);
		rtd_maskl(0xb80004c0, 0xC80FFFFF, 0x01200000);
		rtd_maskl(0xb80004c4, 0xFFFFFF88, 0x00000007);
		rtd_maskl(0xb80004c8, 0x7FFFFFFF, 0x00000000);
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000100);
		rtd_maskl(0xb8000500, 0xFFFFFF0F, 0x00000010);
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x02300000);
		RTK_DEMOD_INFO("DemodPllSetting to DVBC \n");
		break;

	case RTK_DEMOD_MODE_ATV:
		rtd_maskl(0xb80004d8, 0xFFFF00FF, 0x00000000);
		rtd_maskl(0xb80004dc, 0xFDFFFEFE, 0x02000101);
		rtd_maskl(0xb8000500, 0xFFFFFFFE, 0x0);
		rtd_maskl(0xb8000500, 0xFFFFFF00, 0x0000001C);
		rtd_maskl(0xb8000504, 0xFC80FFFF, 0x000A0000);
		RTK_DEMOD_INFO("DemodPllSetting to ATV \n");
		break;
	}
	
	udelay(300);
	rtd_maskl(0xb8000508, 0xfffffff8, 0x00000000);
	rtd_maskl(0xb8000508, 0xfffffff8, 0x00000006);
	rtd_maskl(0xb8000508, 0xfffffff8, 0x00000007);
	rtd_maskl(0xb80004c8, 0xfffffff8, 0x00000000);
	rtd_maskl(0xb80004c8, 0xfffffff8, 0x00000006);
	rtd_maskl(0xb80004c8, 0xfffffff8, 0x00000007);
}


int DtvDemodPllSettingCheck(RTK_DEMOD_MODE mode)
{
	int ret = _TRUE;

	switch (mode) {
	case RTK_DEMOD_MODE_DTMB:
	case RTK_DEMOD_MODE_DVBT:
	case RTK_DEMOD_MODE_DVBT2:
	case RTK_DEMOD_MODE_DVBC:
	case RTK_DEMOD_MODE_ATSC:
	case RTK_DEMOD_MODE_QAM:
	case RTK_DEMOD_MODE_ISDB:
	case RTK_DEMOD_MODE_DVBS:
	case RTK_DEMOD_MODE_DVBS2:
	case RTK_DEMOD_MODE_DVBS2X:
	case RTK_DEMOD_MODE_SPEC_AN:
		if ((rtd_inl(0xb80004dc) & 0x1) != 0x0) {
			RTK_DEMOD_INFO("DtvDemodPllSettingCheck Fail!!!!!!!!!\n");
			ret = _FALSE;
		}
		break;
	default:
		ret = _TRUE;
		break;
	}

	return ret;
}


int DtvDemodCRTSettingCheck(void)
{
	unsigned long sysclk0 = rtd_inl(SYS_REG_SYS_CLKEN0_reg);
	unsigned long sysclk2 = rtd_inl(SYS_REG_SYS_CLKEN2_reg);
	unsigned long sysrst0 = rtd_inl(SYS_REG_SYS_SRST0_reg);
	unsigned long sysrst2 = rtd_inl(SYS_REG_SYS_SRST2_reg);

	unsigned long SysRstCheck = 0;
	unsigned long SysClkCheck = 0;

	int ret = _TRUE;
	unsigned int data = 0;
	
	return ret;
}


void DtvDemodFrontendFilter(RTK_DEMOD_MODE mode)
{
	if (mode == RTK_DEMOD_MODE_DTMB)
	{
		#ifdef DEMOD_DTMB_DTVFRONTEND_DOWDSAMPLE
		rtd_outl(0xb8033900, 0x00000000);//tap0&1
		rtd_outl(0xb8033904, 0x00000000);//tap2&3
		rtd_outl(0xb8033908, 0x00000000);//tap4&5
		rtd_outl(0xb803390C, 0x00000000);//tap6&7
		rtd_outl(0xb8033910, 0x00000000);//tap8&9
		rtd_outl(0xb8033914, 0x00000000);//tap10&11
		rtd_outl(0xb8033918, 0x00000000);//tap12&13
		rtd_outl(0xb803391C, 0x00000000);//tap14&15
		rtd_outl(0xb8033920, 0x00000000);//tap16&17
		rtd_outl(0xb8033924, 0x00000000);//tap18&19
		rtd_outl(0xb8033928, 0x00000000);//tap20&21
		rtd_outl(0xb803392C, 0x00000000);//tap22&23
		rtd_outl(0xb8033930, 0x00000000);//tap24&25
		rtd_outl(0xb8033934, 0x00000000);//tap26&27
		rtd_outl(0xb8033938, 0x00000000);//tap28&29
		rtd_outl(0xb803393C, 0x00000000);//tap30&31
		rtd_outl(0xb8033940, 0x00003FFF);//tap32&33
		rtd_outl(0xb8033944, 0x3FFF0000);//tap34&35
		rtd_outl(0xb8033948, 0x00010001);//tap36&37
		rtd_outl(0xb803394C, 0x00010000);//tap38&39
		rtd_outl(0xb8033950, 0x3FFF3FFE);//tap40&41
		rtd_outl(0xb8033954, 0x3FFE0000);//tap42&43
		rtd_outl(0xb8033958, 0x00020004);//tap44&45
		rtd_outl(0xb803395C, 0x00030000);//tap46&47
		rtd_outl(0xb8033960, 0x3FFC3FFA);//tap48&49
		rtd_outl(0xb8033964, 0x3FFB0000);//tap50&51
		rtd_outl(0xb8033968, 0x0007000B);//tap52&53
		rtd_outl(0xb803396C, 0x00080000);//tap54&55
		rtd_outl(0xb8033970, 0x3FF53FEF);//tap56&57
		rtd_outl(0xb8033974, 0x3FF30000);//tap58&59
		rtd_outl(0xb8033978, 0x00100019);//tap60&61
		rtd_outl(0xb803397C, 0x00140000);//tap62&63
		rtd_outl(0xb8033980, 0x3FE83FDA);//tap64&65
		rtd_outl(0xb8033984, 0x3FE30000);//tap66&67
		rtd_outl(0xb8033988, 0x00240037);//tap68&69
		rtd_outl(0xb803398C, 0x002B0000);//tap70&71
		rtd_outl(0xb8033990, 0x3FCD3FB1);//tap72&73
		rtd_outl(0xb8033994, 0x3FC30000);//tap74&75
		rtd_outl(0xb8033998, 0x0048006F);//tap76&77
		rtd_outl(0xb803399C, 0x00550000);//tap78&79
		rtd_outl(0xb80339A0, 0x3F9B3F65);//tap80&81
		rtd_outl(0xb80339A4, 0x3F890000);//tap82&83
		rtd_outl(0xb80339A8, 0x008E00DB);//tap84&85
		rtd_outl(0xb80339AC, 0x00A90000);//tap86&87
		rtd_outl(0xb80339B0, 0x3F363EC6);//tap88&89
		rtd_outl(0xb80339B4, 0x3F0B0000);//tap90&91
		rtd_outl(0xb80339B8, 0x012E01DE);//tap92&93
		rtd_outl(0xb80339BC, 0x017E0000);//tap94&95
		rtd_outl(0xb80339C0, 0x3E073CB5);//tap96&97
		rtd_outl(0xb80339C4, 0x3D2E0000);//tap98&99
		rtd_outl(0xb80339C8, 0x04C40A27);//tap100&101
		rtd_outl(0xb80339CC, 0x0E640FFF);//tap102&103
		#elif defined(DEMOD_DTMB_DTVFRONTEND_BYPASS)
		rtd_outl(0xb8033800, 0x20110000);
		DEMOD_INFO("DTMB Fronted Filter Bypass 0xb8033800 = 0x%x\n", rtd_inl(0xb8033800));
		#endif
	}  else {
		if (rtd_inl(0xb8033900) != 0x1ffa1ffd) {
			RTK_DEMOD_INFO("Frontend Filter Change : load default !\n");
			rtd_outl(0xb8033900, 0x1ffa1ffd);
			rtd_outl(0xb8033904, 0x1ffe1fff);
			rtd_outl(0xb8033908, 0x00020001);
			rtd_outl(0xb803390c, 0x00030003);
			rtd_outl(0xb8033910, 0x1fff0002);
			rtd_outl(0xb8033914, 0x1ffc1ffd);
			rtd_outl(0xb8033918, 0x1ffe1ffc);
			rtd_outl(0xb803391c, 0x00040001);
			rtd_outl(0xb8033920, 0x00050006);
			rtd_outl(0xb8033924, 0x1fff0003);
			rtd_outl(0xb8033928, 0x1ff91ffb);
			rtd_outl(0xb803392c, 0x1ffc1ff9);
			rtd_outl(0xb8033930, 0x00060001);
			rtd_outl(0xb8033934, 0x00090009);
			rtd_outl(0xb8033938, 0x1fff0005);
			rtd_outl(0xb803393c, 0x1ff41ff8);
			rtd_outl(0xb8033940, 0x1ffa1ff5);
			rtd_outl(0xb8033944, 0x000a0002);
			rtd_outl(0xb8033948, 0x000e000f);
			rtd_outl(0xb803394c, 0x1ffe0008);
			rtd_outl(0xb8033950, 0x1fee1ff4);
			rtd_outl(0xb8033954, 0x1ff61fee);
			rtd_outl(0xb8033958, 0x000f0002);
			rtd_outl(0xb803395c, 0x00160016);
			rtd_outl(0xb8033960, 0x1ffe000c);
			rtd_outl(0xb8033964, 0x1fe51fef);
			rtd_outl(0xb8033968, 0x1ff11fe6);
			rtd_outl(0xb803396c, 0x00150003);
			rtd_outl(0xb8033970, 0x00200020);
			rtd_outl(0xb8033974, 0x1ffd0013);
			rtd_outl(0xb8033978, 0x1fda1fe7);
			rtd_outl(0xb803397c, 0x1fea1fda);
			rtd_outl(0xb8033980, 0x001d0003);
			rtd_outl(0xb8033984, 0x002d002e);
			rtd_outl(0xb8033988, 0x1ffd001b);
			rtd_outl(0xb803398c, 0x1fca1fdd);
			rtd_outl(0xb8033990, 0x1fe01fca);
			rtd_outl(0xb8033994, 0x00290004);
			rtd_outl(0xb8033998, 0x00400040);
			rtd_outl(0xb803399c, 0x1ffc0027);
			rtd_outl(0xb80339a0, 0x1fb41fd0);
			rtd_outl(0xb80339a4, 0x1fd21fb4);
			rtd_outl(0xb80339a8, 0x00390004);
			rtd_outl(0xb80339ac, 0x005b005b);
			rtd_outl(0xb80339b0, 0x1ffc0038);
			rtd_outl(0xb80339b4, 0x1f941fbd);
			rtd_outl(0xb80339b8, 0x1fbc1f92);
			rtd_outl(0xb80339bc, 0x00510005);
			rtd_outl(0xb80339c0, 0x00850083);
			rtd_outl(0xb80339c4, 0x1ffb0053);
			rtd_outl(0xb80339c8, 0x1f5f1f9e);
			rtd_outl(0xb80339cc, 0x1f981f5b);
		}
	}
}


int DemodFrontendPathSetting(RTK_DEMOD_MODE mode)
{
	
	switch (mode) {
	case RTK_DEMOD_MODE_DVBT:
		rtd_outl(0xb8033800, 0x10010010); 				//dtv_frontend : DTV_INPUT_CTRL
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CTL
		rtd_outl(0xb8072180, 0x00000017); 				//img_demod_bus : 
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x4 << 28)); 	//gpio_23: DEMOD_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_DVBT);
		RTK_DEMOD_INFO("FrontendPathSetting to DVBT\n");
		break;

	case RTK_DEMOD_MODE_DVBT2:
	default:
		rtd_outl(0xb8033800, 0x10010010);				//dtv_frontend : DTV_INPUT_CTRL
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CTL
		rtd_outl(0xb8072180, 0x0000001B);
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x4 << 28)); 	//gpio_23: DEMOD_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_DVBT2);
		RTK_DEMOD_INFO("FrontendPathSetting to DVBT2\n");
		break;

	case RTK_DEMOD_MODE_DVBC:
		rtd_outl(0xb8033800, 0x10010010); 				//dtv_frontend : DTV_INPUT_CTRL
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CTL
		rtd_outl(0xb8072180, 0x00000013); 
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x4 << 28)); 	//gpio_23: DEMOD_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_DVBC);
		RTK_DEMOD_INFO("FrontendPathSetting to DVBC\n");
		break;

	case RTK_DEMOD_MODE_ATSC:
		rtd_outl(0xb8033800, 0x10310000);
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CTL
		rtd_maskl(0xb807223c, 0xFFFFFFFE, 0x00000000);	//Disable RTK Demod 8051 SRAM Write
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x4 << 28)); 	//gpio_23: DEMOD_IF_AGC
		RTK_DEMOD_INFO("FrontendPathSetting to ATSC\n");
		break;

	case RTK_DEMOD_MODE_QAM:
		rtd_outl(0xb8033800, 0x10010010); 				//dtv_frontend : DTV_INPUT_CTRL
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CTL
		rtd_outl(0xb8072180, 0x0000000F);
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x4 << 28)); 	//gpio_23: DEMOD_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_QAM);
		RTK_DEMOD_INFO("FrontendPathSetting to QAM\n");
		break;

	case RTK_DEMOD_MODE_ISDB:
		rtd_outl(0xb8033800, 0x10010010); 				//dtv_frontend : DTV_INPUT_CTRL
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CTL
		rtd_outl(0xb8072180, 0x0000000B);
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x4 << 28));	//gpio_23: DEMOD_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_ISDB);
		RTK_DEMOD_INFO("FrontendPathSetting to ISDBT\n");
		break;
		
	case RTK_DEMOD_MODE_DVBS:
		rtd_outl(0xb8033800, 0x10020100);               //IQ Normal for Tuner Output
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CTL //AGC Positive(Set AGC Negative in Demod is Workable)
		rtd_outl(0xb8072180, 0x0000001E);
		rtd_maskl(0xb8000824, ~(0xf << 12), (0x6 << 12));	//gpio_41: DEMOD_S_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_DVBS);
		RTK_DEMOD_INFO("FrontendPathSetting to DVBS\n");
		break;
		
	case RTK_DEMOD_MODE_DVBS2:
		rtd_outl(0xb8033800, 0x10020100);               //IQ Normal for Tuner Output
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CT //AGC Negative(Set AGC Negative in Demod is NOT Workable)
		rtd_outl(0xb8072180, 0x00000022);
		rtd_maskl(0xb8000824, ~(0xf << 12), (0x6 << 12));	//gpio_41: DEMOD_S_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_DVBS2);
		RTK_DEMOD_INFO("FrontendPathSetting to DVBS2\n");
		break;
		
	case RTK_DEMOD_MODE_DVBS2X:
		rtd_outl(0xb8033800, 0x10020100);               //IQ Normal for Tuner Output
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CT //AGC Negative(Set AGC Negative in Demod is NOT Workable)
		rtd_outl(0xb8072180, 0x00000022); 
		rtd_maskl(0xb8000824, ~(0xf << 12), (0x6 << 12));	//gpio_41: DEMOD_S_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_DVBS2X);
		RTK_DEMOD_INFO("FrontendPathSetting to DVBS2X\n");
		break;

	case RTK_DEMOD_MODE_SPEC_AN:
		rtd_outl(0xb8033800, 0x10020100);               //IQ Normal for Tuner Output
		rtd_outl(0xb8071000, 0x0000A10A); 				//demod_sd : SIGMA_DELTA_CT //AGC Negative(Set AGC Negative in Demod is NOT Workable)
		rtd_outl(0xb8072180, 0x00000022);
		rtd_maskl(0xb8000824, ~(0xf << 12), (0x6 << 12));	//gpio_41: DEMOD_S_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_SPEC_AN);
		RTK_DEMOD_INFO("FrontendPathSetting to SPEC_AN\n");
		break;

	case RTK_DEMOD_MODE_DTMB:
		rtd_outl(0xb8033800, 0x20110010);
		rtd_outl(0xb8071000, 0x0000A10A);				//demod_sd : SIGMA_DELTA_CT
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x4 << 28));	//gpio_23: DEMOD_IF_AGC
		DtvDemodFrontendFilter(RTK_DEMOD_MODE_DTMB);
		RTK_DEMOD_INFO("FrontendPathSetting to DTMB\n");
		break;

	case RTK_DEMOD_MODE_ATV:
		RTK_DEMOD_INFO("FrontendPathSetting to ATV\n");
		rtd_maskl(0xb8000814, ~(0xf << 28), (0x3 << 28));	//gpio_23: ATV_IF_AGC
		break;
	}

	return FUNCTION_SUCCESS;
}


int ImgDemodFixIfagc(RTK_DEMOD_MODE mode, unsigned char FixIfagcEn, unsigned int FixIfagcVal)
{
	if (mode == RTK_DEMOD_MODE_QAM)
		rtd_maskl(0xb8071004, 0x000effff, (FixIfagcVal << 20)|(FixIfagcEn << 16));
	else
		rtd_maskl(0xb8071004, 0x000effff, (0x0 << 20)|(0x0 << 16));
	
	return FUNCTION_SUCCESS;
}


int LoadDataIntoDram(RTK_DEMOD_MODE mode, unsigned char* SlDataArray, unsigned long SlDataSize, unsigned char* LdrDataArray, unsigned long LdrDataSize)
{
	RTK_DEMOD_INFO("Load SL LDR\n");
	unsigned int DdrOffest;
	static unsigned int DemodVirAddrStart = NULL;
	static unsigned int DemodVirAddrtEnd = NULL;
#ifdef DEMOD_LDR_CAHNGE_BY_FILE
	struct device *dev;
	struct firmware *fw;
	int rc, i;
	int ret = true;
	char filename[256];

	switch (mode) {
	case RTK_DEMOD_MODE_DVBC:
		sprintf(filename, "img_tv_dvbc_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_DVBT:
		sprintf(filename, "img_tv_dvbt_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_DVBT2:
		sprintf(filename, "img_tv_dvbt2_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_DVBS:
		sprintf(filename, "img_tv_dvbs_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_DVBS2:
		sprintf(filename, "img_tv_dvbs2_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_DVBS2X:
		sprintf(filename, "img_tv_dvbs2x_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_SPEC_AN:
		sprintf(filename, "img_tv_specan_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_ATSC:
		sprintf(filename, "img_tv_dvbc_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_QAM:
		sprintf(filename, "img_tv_dvbc_hostport.ldr");
		break;
	case RTK_DEMOD_MODE_ISDB:
		sprintf(filename, "img_tv_dvbc_hostport.ldr");
		break;
	default:
		RTK_DEMOD_INFO("\033[1;32;33m" "Unknow DTV Mode!!!!!!!!!!!!\n" "\033[m");
		break;
	}
#endif

	DemodVirAddrStart = phys_to_virt(DEMOD_MEM_START_PHYS);
	DemodVirAddrtEnd = phys_to_virt(DEMOD_MEM_END_PHYS);

	if (mode == RTK_DEMOD_MODE_DVBT2) {
		DdrOffest = 0x00100000;
	} else if (mode == RTK_DEMOD_MODE_SPEC_AN) {
		DdrOffest = 0x00200000;
	} else {
		DdrOffest = 0x00000000;
	}

	//Copy SL into DRAM
	memcpy((DemodVirAddrStart + DdrOffest), SlDataArray, SlDataSize);
	//Copy LDR into DRAM
#ifdef DEMOD_LDR_CAHNGE_BY_FILE
	dev = get_rtkdemod_device_ptr();
	ret = request_firmware(&fw, filename, dev);
	RTK_DEMOD_INFO("ret=%d\n", ret);
	if (ret < 0)  {
		dev_err(dev, "firmware file '%s' not found\n", filename);
		RTK_DEMOD_INFO("\033[1;32;32m" "firmware file '%s' not found, so load LDR form default\n" "\033[m", filename);
		memcpy((DemodVirAddrStart + DdrOffest + SlDataSize), LdrDataArray, LdrDataSize);
	} else {
		RTK_DEMOD_INFO("\033[1;32;33m" "firmware file '%s' , load LDR form file\n" "\033[m", filename);
		RTK_DEMOD_INFO("\033[1;32;33m" "data=0x%x/0x%x/0x%x/0x%x size=%d\n" "\033[m", *(fw->data), *(fw->data + 1), *(fw->data + 2), *(fw->data + 3), fw->size);
		memcpy((DemodVirAddrStart + DdrOffest + SlDataSize), fw->data, fw->size);
	}
	release_firmware(fw);
#else
	memcpy((DemodVirAddrStart + DdrOffest + SlDataSize), LdrDataArray, LdrDataSize);
#endif

        dma_map_single(NULL, (void *)DemodVirAddrStart, DEMOD_MEM_LENGTH, DMA_BIDIRECTIONAL);  
        //dmac_flush_range(DemodVirAddrStart, DemodVirAddrtEnd);
	//outer_flush_range(DEMOD_MEM_START_PHYS, DEMOD_MEM_END_PHYS);


	//Set the Mem Bus to DRAM Physical Address
	rtd_outl(IMG_DEMOD_BUS_img_mem_bus_ctrl4_reg, 0x00000000);


	return FUNCTION_SUCCESS;
}


int DtvDemodRpuInit(RTK_DEMOD_MODE mode)
{
	unsigned int LsbAddress;

	if (mode == RTK_DEMOD_MODE_DTMB || mode == RTK_DEMOD_MODE_ATSC) {
		RTK_DEMOD_INFO("DTV Demod (%d) is DTMB or RTK ATSC\n", mode);
		return FUNCTION_SUCCESS;
	}

	RTK_DEMOD_INFO("RPU init\n");
	RPUTimeOutPeriodCnt = 0;//clear
	RPUTimeOutTotalCnt = 0;//clear

	//Ext System Bus(Tuner Control)
	rtd_outl(IMG_DEMOD_BUS_img_ext_sys_bus_ctrl1_reg, 0xB8060000);//Set to RBUS

	//Switch Standard Load SL and LDR Here
	switch (mode) {
	case RTK_DEMOD_MODE_DVBS:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_DVBS\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x1E);//Set DVBS Clock Mode
		RTK_DEMOD_INFO("%s\n", DvbSLdrVersion);
		RTK_DEMOD_INFO("%s\n", DvbSLdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_DVBS, SecondaryLoader, SecondaryLoaderSize, DvbSLdrArray, DvbSLdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x007C0000);//Value = (0x01F0_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x005C0000)//Value = (0x0170_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_DVBS2:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_DVBS2\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x22);//Set DVBS2 Clock Mode
		RTK_DEMOD_INFO("%s\n", DvbS2LdrVersion);
		RTK_DEMOD_INFO("%s\n", DvbS2LdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_DVBS2, SecondaryLoader, SecondaryLoaderSize, DvbS2LdrArray, DvbS2LdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x007C0000);//Value = (0x01F0_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x005C0000)//Value = (0x0170_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_DVBS2X:
		RTK_DEMOD_INFO("\033[1;32;32m" "RTD289x_MODE_DVBS2X\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x22);//Set DVBS2 Clock Mode
		RTK_DEMOD_INFO("%s\n", DvbS2XLdrVersion);
		RTK_DEMOD_INFO("%s\n", DvbS2XLdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_DVBS2X, SecondaryLoader, SecondaryLoaderSize, DvbS2XLdrArray, DvbS2XLdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x007C0000);//Value = (0x01F0_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x005C0000)//Value = (0x0170_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_SPEC_AN:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_SPEC_AN\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x22);//Set DVBS2 Clock Mode
		RTK_DEMOD_INFO("%s\n", SpecAnLdrVersion);
		RTK_DEMOD_INFO("%s\n", SpecAnLdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_SPEC_AN, SecondaryLoader, SecondaryLoaderSize, SpecAnLdrArray, SpecAnLdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x00840000);//Value = (0x0180_0000 & 0x03FF_FFFF) >> 2
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_DVBT2:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_DVBT2\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x1B);//Set DVBC Clock Mode
		RTK_DEMOD_INFO("%s\n", DvbT2LdrVersion);
		RTK_DEMOD_INFO("%s\n", DvbT2LdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_DVBT2, SecondaryLoader, SecondaryLoaderSize, DvbT2LdrArray, DvbT2LdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x00800000);//Value = (0x0200_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x00600000)//Value = (0x0180_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_QAM:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_QAM(OpenCable)\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x0F);//Set J83B Clock Mode
		RTK_DEMOD_INFO("%s\n", QamLdrVersion);
		RTK_DEMOD_INFO("%s\n", QamLdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_QAM, SecondaryLoader, SecondaryLoaderSize, QamLdrArray, QamLdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x007C0000);//Value = (0x01F0_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x005C0000)//Value = (0x0170_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_DVBT:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_DVBT\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x17);//Set DVBT Clock Mode
		RTK_DEMOD_INFO("%s\n", DvbTLdrVersion);
		RTK_DEMOD_INFO("%s\n", DvbTLdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_DVBT, SecondaryLoader, SecondaryLoaderSize, DvbTLdrArray, DvbTLdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x007C0000);//Value = (0x01F0_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x005C0000)//Value = (0x0170_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_ISDB:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_ISDBT\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x17);//Set ISDB-T Clock Mode from 0x0B to 0x17
		RTK_DEMOD_INFO("%s\n", IsdbtLdrVersion);
		RTK_DEMOD_INFO("%s\n", IsdbtLdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_ISDB, SecondaryLoader, SecondaryLoaderSize, IsdbtLdrArray, IsdbtLdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x007C0000);//Value = (0x01F0_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x005C0000)//Value = (0x0170_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	case RTK_DEMOD_MODE_DVBC:
		RTK_DEMOD_INFO("\033[1;32;32m" "DEMOD_MODE_DVBC\n" "\033[m");
		rtd_outl(IMG_DEMOD_BUS_img_clkgen_reg_reg, 0x13);//Set DVBC Clock Mode
		RTK_DEMOD_INFO("%s\n", DvbCLdrVersion);
		RTK_DEMOD_INFO("%s\n", DvbCLdrTunerModule);
		//Load SL and LDR into DRAM //Load Here for Multi-Standard System
		LoadDataIntoDram(RTK_DEMOD_MODE_DVBC, SecondaryLoader, SecondaryLoaderSize, DvbCLdrArray, DvbCLdrArraySize);

		DtvDemodEnable(mode);
		//Memory Offset in RPU
		//Set UCCP_SOC_FAB_META0 0x02000770
		rtd_outl(ImgRegAddrConvert(0x02000770), 0x007C0000);//Value = (0x01F0_0000 & 0x03FF_FFFF) >> 2      (default : (0x02000770), 0x005C0000)//Value = (0x0170_0000 & 0x03FF_FFFF) >> 2)
		//Set UCCP_SOC_FAB_META1 0x02000774
		rtd_outl(ImgRegAddrConvert(0x02000774), 0x00200000);//Value = (0x0080_0000 & 0x07FF_FFFF) >> 2
		break;

	}

	//Set Img demod PC to SL Start Address
	ImgIndirectRegAccess(RTK_DEMOD_RPU_TXUXXRXDT_ADDR, 0x60200000);//SL Address

	//Set Img demod to MiniM Mode
	ImgIndirectRegAccess(RTK_DEMOD_RPU_TXPRIVEXT_ADDR, 0x00000080);//Sel TXPRIVEXT to MiniM Mode

	//Update Img demod PC
	ImgIndirectRegAccess(RTK_DEMOD_RPU_TXUXXRXRQ_ADDR, 0x00000005);//Update PC Reigster

	//Enable Img demod thread
	ImgIndirectRegAccess(RTK_DEMOD_RPU_TXENABLE_ADDR, 0x00000001);//Enable Thread

	udelay(50);

	return FUNCTION_SUCCESS;
}


int DtvDemodInitialization(RTK_DEMOD_MODE mode, int force_rst)
{
	if (pli_ready == 0) {
// ?? need to do 20150819
		//pli_init();
		pli_ready = 1;
		force_rst = 1;   // always rst demod at start...
	}
	//if (force_rst || (DtvDemodPllSettingCheck(mode) == _FALSE) || (DtvDemodCRTSettingCheck() == _FALSE) || (DtvDemodAdcPowerCheck() == _FALSE)) {
	if (force_rst || (DtvDemodPllSettingCheck(mode) == _FALSE)) {
		DtvDemodPowerControl(0); //pull reset
		DemodPllSetting(mode);
		udelay(1000);
		DemodAdcSetting(mode);
		udelay(50);
		DtvDemodPowerControl(1); //reset release
		udelay(50);

		force_rst = 1;
		pli_ready = 1;

		//Frontend Path Setting
		DemodFrontendPathSetting(mode);

	} else {
		RTK_DEMOD_WARNING("DtvDemod PLL&ADC not changing.\n");
	}


	if (force_rst) {
		if (mode == RTK_DEMOD_MODE_DTMB || mode == RTK_DEMOD_MODE_ATSC)
			DtvDemodEnable(mode);
		else
			DtvDemodRpuInit(mode);

		DtvDemodReset = _BIT(mode);

	}


	if (!DtvIsDemodClockEnable(mode)) {
		RTK_DEMOD_WARNING("init demod with demod clock disabled, please enable demod clock first\n");
	}

	m_realtek_TvSys_mode = mode;
	return CheckDemodReset(mode);
}


int GetDemodTvSysMode(TV_SYSTEM_TYPE * mode)
{
	if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_DTMB)
		*mode = TV_SYS_TYPE_DTMB;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_DVBT)
		*mode = TV_SYS_TYPE_DVBT;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_DVBT2)
		*mode = TV_SYS_TYPE_DVBT2;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_DVBC)
		*mode = TV_SYS_TYPE_DVBC;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_ATSC)
		*mode = TV_SYS_TYPE_ATSC;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_QAM)
		*mode = TV_SYS_TYPE_OPENCABLE;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_ISDB)
		*mode = TV_SYS_TYPE_ISDBT;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_DVBS)
		*mode = TV_SYS_TYPE_DVBS;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_DVBS2)
		*mode = TV_SYS_TYPE_DVBS2;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_DVBS2X)
		*mode = TV_SYS_TYPE_DVBS2;
	else if (m_realtek_TvSys_mode == RTK_DEMOD_MODE_SPEC_AN)
		*mode = TV_SYS_TYPE_UNKNOWN;

	return FUNCTION_SUCCESS;
}


int CheckDemodReset(RTK_DEMOD_MODE mode)
{
//	assert(mode < RTK_DEMOD_MODE_MAX);
	if (DtvDemodReset & _BIT(mode)) {
		RTK_DEMOD_INFO("CheckDemodReset: Demod %d has been reset (%x)\n", mode, DtvDemodReset);
		return 1;
	}
	return 0;
}


void ClearDemodReset(RTK_DEMOD_MODE mode)
{
	if (CheckDemodReset(mode)) {
		DtvDemodReset &= ~_BIT(mode);
		RTK_DEMOD_INFO("ClearDemodReset: reset flag of Demod %d has been cleared (%x)\n", mode, DtvDemodReset);
	}
}


/*------------------------------------------------------------------------------
 * Analog TV API
 *------------------------------------------------------------------------------*/

int AtvDemodPowerControl(unsigned char On)
{
	if (On) {
		CRT_CLK_OnOff(ANADEMOD, CLK_ON, NULL);
		RTK_DEMOD_INFO("Analog demod is power on.\n");
	} else {
		CRT_CLK_OnOff(ANADEMOD, CLK_OFF, NULL);
		RTK_DEMOD_INFO("Analog demod is power off.\n");
	}
	
	return FUNCTION_SUCCESS;
}

int AtvDemodInitialization(RTK_DEMOD_MODE mode)
{
	RTK_DEMOD_INFO("AtvDemodInitialization : mode %d\n", mode);

	DemodPllSetting(mode);//drv_ifd_adc_clock_init_162M
	udelay(1000);
	DemodAdcSetting(mode);
	udelay(50);
	AtvDemodPowerControl(1);//drv_ifd_power_on
	udelay(50);
	DemodFrontendPathSetting(mode);

	return FUNCTION_SUCCESS;
}


/*------------------------------------------------------------------------------
 * DMA function
 *------------------------------------------------------------------------------*/

unsigned char* DemodDmaAddr;
unsigned char* DemodDmaNonCacheAddr;
unsigned long DemodDmaStartAddr, DemodDmaEndAddr;

int DtvDemodDMAAllocateMemory(void)
{
#if 0
	unsigned long phyAddr;
	//unsigned char* nonCachedAddr;

	if (DemodDmaAddr != 0)
		pli_freeContinuousMemoryMesg("DEMOD DMA", DemodDmaAddr);

	DemodDmaAddr = (unsigned char*)pli_allocContinuousMemoryMesg("DEMOD DMA", 0x800000, &DemodDmaNonCacheAddr, &phyAddr);
	DemodDmaStartAddr = phyAddr;
	DemodDmaEndAddr = phyAddr + 0x800000;
	RTK_DEMOD_INFO("DemodDmaAddr=%x, nonCachedAddr=%x, phyAddr=%x\n", DemodDmaAddr, DemodDmaNonCacheAddr, phyAddr);
	RTK_DEMOD_INFO("DemodDmaStartAddr=%x, DemodDmaEndAddr=%x\n", DemodDmaStartAddr, DemodDmaEndAddr);

	if (DemodDmaAddr == 0) return FUNCTION_ERROR;
	return FUNCTION_SUCCESS;
#endif
// ?? need to do 20150819
	return FUNCTION_ERROR;

}
int DtvDemodDMADump(BASE_INTERFACE_MODULE* pBaseInterface, unsigned char DeviceAddr, unsigned char mode)
{
#if 0
	char sFilePath[128];
	unsigned int iSize = 0;//, Width = 0, Height = 0;
	unsigned char *iStartAddr = 0;
	int iFileNum;
#ifdef CONFIG_DTV_DEMOD_USE_RBUSREG
	unsigned char i;
	unsigned long WritingAddr;

	WritingAddr = 0xE429;
	WritingAddr = WritingAddr * 4 + 0xb8040000;
	for (i = 0; i < 4; i++) {
		rtd_outl(WritingAddr + i * 4, (DemodDmaEndAddr >> (i * 8 + 3)) & 0xff);
	}
	WritingAddr = 0xE42D;
	WritingAddr = WritingAddr * 4 + 0xb8040000;
	for (i = 0; i < 4; i++) {
		rtd_outl(WritingAddr + i * 4, (DemodDmaStartAddr >> (i * 8 + 3)) & 0xff);
	}
	WritingAddr = 0xE438;
	WritingAddr = WritingAddr * 4 + 0xb8040000;
	if (mode == 0) //Dump ADC
		rtd_outl(WritingAddr, 0);
	else
		rtd_outl(WritingAddr, 1);

	//Enable DMA
	WritingAddr = 0xE432;
	WritingAddr = WritingAddr * 4 + 0xb8040000;
	rtd_outl(WritingAddr, 1);
#else
	unsigned char WritingBytes[10], WritingNum = 0;

	WritingBytes[0] = 0xE4;
	WritingBytes[1] = 0x29;
	WritingBytes[2] = (DemodDmaEndAddr >> 3) & 0xff;
	WritingBytes[3] = (DemodDmaEndAddr >> 11) & 0xff;
	WritingBytes[4] = (DemodDmaEndAddr >> 19) & 0xff;
	WritingBytes[5] = (DemodDmaEndAddr >> 27) & 0xff;
	WritingNum = 6;
	__realtek_i2c_write(pBaseInterface, DeviceAddr, &WritingBytes[0], WritingNum);
	WritingBytes[0] = 0xE4;
	WritingBytes[1] = 0x2D;
	WritingBytes[2] = (DemodDmaStartAddr >> 3) & 0xff;
	WritingBytes[3] = (DemodDmaStartAddr >> 11) & 0xff;
	WritingBytes[4] = (DemodDmaStartAddr >> 19) & 0xff;
	WritingBytes[5] = (DemodDmaStartAddr >> 27) & 0xff;
	WritingNum = 6;
	__realtek_i2c_write(pBaseInterface, DeviceAddr, &WritingBytes[0], WritingNum);

	if (mode == 0) { //Dump ADC
		WritingBytes[0] = 0xE4;
		WritingBytes[1] = 0x38;
		WritingBytes[2] = 0x0;
		WritingNum = 3;
	} else { //Dump DAGC
		WritingBytes[0] = 0xE4;
		WritingBytes[1] = 0x38;
		WritingBytes[2] = 0x1;
		WritingNum = 3;
	}
	__realtek_i2c_write(pBaseInterface, DeviceAddr, &WritingBytes[0], WritingNum);

	WritingBytes[0] = 0xE4;
	WritingBytes[1] = 0x32;
	WritingBytes[2] = 0x1; //Enable DMA
	WritingNum = 3;
	__realtek_i2c_write(pBaseInterface, DeviceAddr, &WritingBytes[0], WritingNum);

#endif

	iStartAddr = DemodDmaNonCacheAddr;
	iSize = 0x800000;

	system("mount -t vfat -o remount /dev/sda1 /mnt/usbmounts/sda1");
	sprintf(sFilePath, "%s/%s%s", "/mnt/usbmounts/sda1/", "DEMOD_DMA", ".bin"); //Dump to USB

	RTK_DEMOD_INFO("%s\n", sFilePath);

	FILE *pFile = fopen(sFilePath, "w");
	if (pFile == NULL) {
		RTK_DEMOD_INFO("file open fail...\n");
	} else {
		iFileNum = fileno(pFile);
	}

	if (pFile) {
		unsigned int iCnt = 0, iBufIdx = 0;
		unsigned int *iCurAddr = (unsigned int*)iStartAddr;
		unsigned int bufArray[128];
		unsigned int iBuf = 0;

		while (iCnt < iSize) {
			RTK_DEMOD_INFO(".");
			iBuf = *iCurAddr;
			bufArray[iBufIdx] = iBuf;
			iBufIdx ++;

			if (iBufIdx >= 128) {
				fwrite(bufArray, 128 * 4, 1, pFile);
				iBufIdx = 0;
			}

			iCnt += 4;
			iCurAddr += 1; //move pointer 4byte
		}
		RTK_DEMOD_INFO("\n");
		// last
		if (iBufIdx > 0) {
			fwrite(bufArray, iBufIdx * 4, 1, pFile);
			iBufIdx = 0;
		}
		RTK_DEMOD_INFO(".\n");
		if (0 != fflush(pFile))
			RTK_DEMOD_INFO("Flash to file fail\n");

		// Sync to device

		if (0 != fsync(iFileNum)) {
			RTK_DEMOD_INFO("fsync fail\n");
			if (fdatasync(iFileNum) == -1) {
				RTK_DEMOD_INFO("fdatasync error!!\n");
			}
		}

		fclose(pFile);
		RTK_DEMOD_INFO("write to file %s, size = %d\n", sFilePath, iSize);
	} else {
		RTK_DEMOD_INFO("write file Error!\n");
	}
#ifdef CONFIG_DTV_DEMOD_USE_RBUSREG
	//Disable DMA

	WritingAddr = 0xE432;
	WritingAddr = WritingAddr * 4 + 0xb8040000;
	rtd_outl(WritingAddr, 0);
#else
	WritingBytes[0] = 0xE4;
	WritingBytes[1] = 0x32;
	WritingBytes[2] = 0x0; //Disable DMA
	WritingNum = 3;
	__realtek_i2c_write(pBaseInterface, DeviceAddr, &WritingBytes[0], WritingNum);
#endif
#endif
	return FUNCTION_SUCCESS;

}


/*------------------------------------------------------------------------------
 * Base Interface API
 *------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 * FUNC : __realtek_wait_ms
 *
 * DESC : wait function for merlin2 baseinterface
 *
 * PARM : pBIF  : Private Data that wants contain in this base class
 *        ms    : time to wait in ms
 *
 * RET  : N/A
 *------------------------------------------------------------------------------*/
void __realtek_wait_ms(BASE_INTERFACE_MODULE* pBIF, unsigned long ms)
{
	tv_osal_msleep(ms);
}



/*------------------------------------------------------------------------------
 * FUNC : __rtd299s_i2c_write
 *
 * DESC : i2c write function for rtd299s base if
 *
 * PARM : pBaseInterface    : handle of rtd299s baseif
 *        DeviceAddr        : device address
 *        pWritingBytes     : data to be written
 *        ByteNum           : number of data to write
 *
 * RET  : FUNCTION_SUCCESS / FUNCTION_ERROR
 *------------------------------------------------------------------------------*/
int __realtek_i2c_write(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	const unsigned char*        pWritingBytes,
	unsigned long               ByteNum
)
{
	COMM* pComm;
	pBaseInterface->GetUserDefinedDataPointer(pBaseInterface, (void**)&pComm);
	return ENCODE_RET(pComm->SendWriteCommand(pComm, DeviceAddr, (unsigned char*) pWritingBytes, ByteNum, COMM_FLAG_HIGH_SPEED | COMM_FLAG_NO_GUARD_INTERVAL));
}



/*------------------------------------------------------------------------------
 * FUNC : __rtd299s_i2c_read
 *
 * DESC : i2c read function for rtd299s base if
 *
 * PARM : pBaseInterface    : handle of rtd299s baseif
 *        DeviceAddr        : device address
 *        pReadingBytes     : read data buffer
 *        ByteNum           : number of data to read
 *
 * RET  : FUNCTION_SUCCESS / FUNCTION_ERROR
 *------------------------------------------------------------------------------*/
int __realtek_i2c_read(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	unsigned char*              pReadingBytes,
	unsigned long               ByteNum
)
{

	COMM* pComm ;
	pBaseInterface->GetUserDefinedDataPointer(pBaseInterface, (void**)&pComm);
	return ENCODE_RET(pComm->SendReadCommand(pComm, DeviceAddr, NULL, 0, pReadingBytes, ByteNum, COMM_FLAG_HIGH_SPEED | COMM_FLAG_NO_GUARD_INTERVAL));
}



/*------------------------------------------------------------------------------
 * FUNC : __realtek_rbus_i2c_write
 *
 * DESC : Rbus write function for realtek base if
 *
 * PARM : pBaseInterface    : handle of realtek baseif
 *        DeviceAddr        : device address
 *        pWritingBytes     : data to be written
 *        ByteNum           : number of data to write
 *
 * RET  : FUNCTION_SUCCESS / FUNCTION_ERROR
 *------------------------------------------------------------------------------*/
int __realtek_rbus_i2c_write(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	const unsigned char*        pWritingBytes,
	unsigned long               ByteNum
)
{
	unsigned char i=0;
	unsigned char RbusData;
	unsigned long DemodAddrMsb, DemodAddrLsb;
	unsigned long DemodAddr;

	DemodAddrMsb = pWritingBytes[0];
	DemodAddrLsb = pWritingBytes[1];
	DemodAddr = DemodAddrMsb * 256 + DemodAddrLsb;

	//Demod Address to Rbus Mapping: 0xD000 = 0xB8154000
	RbusAddr = (DemodAddr & 0x00003fff) * 4 + 0xb8150000;
	//printk("===(Write)DemodAddrMsb = 0x%8x, DemodAddrLsb = 0x%x===\n", DemodAddrMsb, DemodAddrLsb);
	//printk("===(Write)RbusAddr = 0x%8x, ByteNum = 0x%x===\n", RbusAddr, ByteNum);

	if (RbusAddr == 0xb815c000)//8051 SRAM Start: 0x3000
	{
		rtd_maskl(REG_RTK_DEMOD_8051_SRAM_WRITE_EN, 0xFFFFFFFE, 0x00000001);
		//printk("[8051_SRAM_S]0xb807223c = 0x%x\n", rtd_inl(0xb807223c));
	}
	
	//If ByteNum<2, Only record RbusAddr.
	if (ByteNum > 2) {
		for (i = 2; i < ByteNum; i++) {
			RbusData = pWritingBytes[i];
			//printk("RbusAddr = 0x%8x, RbusData = 0x%x, 0xb807223c = 0x%x\n", RbusAddr + (i - 2) * 4, RbusData, rtd_inl(0xb807223c));
			
			rtd_outl(RbusAddr + (i - 2) * 4, RbusData);
			tv_osal_usleep(10);
		}
	}
	
	if ((RbusAddr + (i - 3) * 4) == 0xb815effc)//0x3BFF  
	{
		rtd_maskl(REG_RTK_DEMOD_8051_SRAM_WRITE_EN, 0xFFFFFFFE, 0x00000000);
		//printk("[8051_SRAM_E]i = %u, 0xb807223c = 0x%x\n", i, rtd_inl(0xb807223c));
	}
	return FUNCTION_SUCCESS;

}



/*------------------------------------------------------------------------------
 * FUNC : __realtek_rbus_i2c_read
 *
 * DESC : Rbus read function for realtek base if
 *
 * PARM : pBaseInterface    : handle of realtek baseif
 *        DeviceAddr        : device address
 *        pReadingBytes     : read data buffer
 *        ByteNum           : number of data to read
 *
 * RET  : FUNCTION_SUCCESS / FUNCTION_ERROR
 *------------------------------------------------------------------------------*/
int __realtek_rbus_i2c_read(
	BASE_INTERFACE_MODULE*      pBaseInterface,
	unsigned char               DeviceAddr,
	unsigned char*              pReadingBytes,
	unsigned long               ByteNum
)
{
	unsigned char i;
	unsigned char RbusData;
	//printk("===(Read)RbusAddr = 0x%8x, ByteNum = 0x%x===\n", RbusAddr, ByteNum);

	for (i = 0; i < ByteNum; i++) {
		RbusData = rtd_inl(RbusAddr + (i * 4));
		pReadingBytes[i] = RbusData;
		tv_osal_usleep(10);
		
		//printk("===(Read)pReadingBytes[%u] = 0x%8x\n", i,  RbusData);
	}
	return FUNCTION_SUCCESS;
}



/*

int
ImgRegAddrConvert(
    unsigned int AddressIn
)
{
    //static unsigned int gPreAddress;
    unsigned int AddressOut, MsbAddress;

	if (!DtvIsDemodClockEnable(mode))
	{
		RTK_DEMOD_WARNING("\033[1;32;32m" "Demod Register Access without Enable Clock !!!!\n" "\033[m");
		RTK_DEMOD_WARNING("\033[1;32;32m" "Demod Register Access without Enable Clock !!!!\n" "\033[m");
		RTK_DEMOD_WARNING("\033[1;32;32m" "Demod Register Access without Enable Clock !!!!\n" "\033[m");
		RTK_DEMOD_WARNING("\033[1;32;32m" "Demod Register Access without Enable Clock !!!!\n" "\033[m");
	}

    //if((gPreAddress&0xFFFC0000) != (AddressIn&0xFFFC0000))
    //{
        MsbAddress = (AddressIn&0xFFFC0000);
    //[todd] need modified rbus access
        //rtd_outl(IMG_DEMOD_BUS_img_host_sys_bus_ctrl1_reg, MsbAddress);
    //}

    //gPreAddress = AddressIn; // Store Previous Access Address
    AddressOut = ((AddressIn&0x0003FFFF)|0xB80C0000);

    return AddressOut;
}
*/

int
ImgIndirectRegAccess(
	unsigned int RegAddr,
	unsigned int RegVal
)
{
	unsigned int LsbAddress;
	unsigned int timeout_cnt = 200;

	LsbAddress = ImgRegAddrConvert(RTK_DEMOD_RPU_MSLVCTRL1_ADDR);
	RTK_DEMOD_DBG("LsbAddress= %x\n", LsbAddress);
	while (timeout_cnt) {
		if ((rtd_inl(LsbAddress) & 0x01000000) == 0x01000000) //Bit 24
			break;
		timeout_cnt--;
		tv_osal_msleep(2);
	}

	if (timeout_cnt == 0) return FUNCTION_ERROR;

	LsbAddress = ImgRegAddrConvert(RTK_DEMOD_RPU_MSLVCTRL0_ADDR);
	RTK_DEMOD_DBG("LsbAddress= %x\n", LsbAddress);
	rtd_outl(LsbAddress, RegAddr);
	LsbAddress = ImgRegAddrConvert(RTK_DEMOD_RPU_MSLVDATAT_ADDR);
	RTK_DEMOD_DBG("LsbAddress= %x\n", LsbAddress);
	rtd_outl(LsbAddress, RegVal);

	return FUNCTION_SUCCESS;
}
