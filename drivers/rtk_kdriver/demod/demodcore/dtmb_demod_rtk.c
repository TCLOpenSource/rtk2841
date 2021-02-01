#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <mach/io.h>
#include "dtmb_demod_rtk_type.h"
#include "dtmb_demod_rtk.h"
#include "dtmb_demod_rtk_user.h"
#include "dtmb_demod_base.h"
//#include <math.h>

#define DTMBIP_DEBUG_INFO_OPEN	        0
#define SYSTEM_NOT_SUPPORT_LOG10	    1
#define DTMBIP_SPECTRUM_ADJUST_OPEN	    0
#define FREQUENCY_SAMPLE                30.375
#define FREQUENCY_SYMBOL                7.56
/**********************************************
6M SystemBandWidth switch
**********************************************/
//#define DTMBIP_BANDWIDTH_6M             1   //enable bandwidth 6M support turn off

/*********************************************
define RBUS commit
**********************************************/
/*
#define rtd_outl(addr, value)   pli_writeReg32(addr, value)
#define rtd_inl(addr)           pli_readReg32(addr)
#define rtd_maskl(addr, mask, value)    rtd_outl(addr, ((rtd_inl(addr) & mask) | value))
*/

//static UINT8 HD2311_WorkMode = HDIC2311_DTMB_SELECT;

#if SYSTEM_NOT_SUPPORT_LOG10
static UINT16 SNR_log_table_int[] = {
	0, 100,
	2, 104,
	4, 109,
	6, 114,
	8, 120,
	10, 125,
	12, 131,
	14, 138,
	16, 144,
	18, 151,
	20, 158,
	22, 166,
	24, 173,
	26, 182,
	28, 190,
	30, 199,
	32, 208
};

static UINT16 Left_Table(UINT16 InValue)
{
	UINT16 OutValue = 0;
	UINT16 TableSize = sizeof(SNR_log_table_int) / sizeof(UINT16);
	UINT16 i;
	for (i = 0; i < TableSize; i += 2) {
		if (InValue <= SNR_log_table_int[i + 1]) {
			OutValue = SNR_log_table_int[i];
			return OutValue;
		}
	}

	OutValue = 32;
	return OutValue;
}

static UINT32 Log10_Convert(UINT32 InValue)
{
	UINT32 u32_temp = 1;
	UINT8  indx = 0;
	UINT32 InValue_left;
	UINT32 log_ret;

	do {
		u32_temp = u32_temp << 1;
		if (InValue < u32_temp)
			break;
	} while (++indx < 32);

	log_ret = (301 * indx + 50) / 100;
	InValue_left = InValue * 100 / (1 << indx);
	//log_ret = log_ret + Left_Table(InValue_left) / 10;
	log_ret = log_ret * 10000 + Left_Table(InValue_left) * 1000 ;
	return log_ret;
}
#endif



UINT8 DTMBIP_SetWorkMode()
{
	UINT8 err = DTMB_NO_ERROR;
/*
	rtd_outl(0xB8140A7C, 0x00000010);
	rtd_outl(0xB8140A70, 0x00000010);
	rtd_outl(0xB8140A28, 0x000000F7);
	rtd_outl(0xB8140A18, 0x000000F5);
	rtd_outl(0xB8140A00, 0x000000E7);
	rtd_outl(0xB8140BE8, 0x00000020);
	rtd_outl(0xB8140BF8, 0x00000040);
	rtd_outl(0xB8140AC8, 0x00000020);
	rtd_outl(0xB8140BBC, 0x00000030);
	rtd_outl(0xB8140980, 0x00000000);
	rtd_outl(0xB81409D4, 0x00000001);
	rtd_outl(0xB81409D8, 0x0000003E);
	//  For ch522MHz issue modify
	rtd_outl(0xB8140BA8, 0x00000014); //PN輔助信道估計的二階路更新因子low bit default is 0x04
	rtd_outl(0xB814089C, 0x00000004);   //Data輔助信道估計的二階路更新因子 default is 0x18
	rtd_outl(0xB8140C00, 0x00000008);	//Set to 0x08
	rtd_outl(0xB81400DC, 0x00000042);	//增大Carrier_gain loop and bandwedith
	rtd_outl(0xB8140108, 0x00000010); 	//降低EQ input level
	rtd_outl(0xB8140C0C, 0x00000000); 	//Set to 0x00
	//fixed Guangzhou_482MHz
	rtd_outl(0xB8140B80, 0x00000090); 	//default is 0x60
	rtd_outl(0xB814090C, 0x00000002); 	//default is 0x04
	rtd_outl(0xB8140910, 0x00000007); 	//default is 0x05
	rtd_outl(0xB8140918, 0x00000080); 	//default is 0x78
	//fixed changsha_722MHz
	rtd_outl(0xB8140330, 0x00000006); 	//default is 0x0A
	rtd_outl(0xB8140618, 0x00000001); 	//default is 0x03
	rtd_outl(0xB814061C, 0x00000080); 	//default is 0xfb
*/
		DTMBIP_WriteRegister(0x029F, 0x10);
		DTMBIP_WriteRegister(0x029C, 0x10);
		DTMBIP_WriteRegister(0x028A, 0xF7);
		DTMBIP_WriteRegister(0x0286, 0xF5);
		DTMBIP_WriteRegister(0x0280, 0xE7);
		DTMBIP_WriteRegister(0x02FA, 0x20);
		DTMBIP_WriteRegister(0x02FE, 0x40);
		DTMBIP_WriteRegister(0x02B2, 0x20);
		DTMBIP_WriteRegister(0x02EF, 0x30);
		DTMBIP_WriteRegister(0x0260, 0x00);
		DTMBIP_WriteRegister(0x0275, 0x01);
		DTMBIP_WriteRegister(0x0276, 0x3E);
		//fixed ch522MHz_3D
		DTMBIP_WriteRegister(0x02EA, 0x14); //  default is 0x04
		DTMBIP_WriteRegister(0x0227, 0x04); //  default is 0x18
		DTMBIP_WriteRegister(0x0300, 0x08); //  set to 0x08
		DTMBIP_WriteRegister(0x0037, 0x42); //  default is 0x22
		DTMBIP_WriteRegister(0x0042, 0x10); //  default is 0x15
		DTMBIP_WriteRegister(0x0303, 0x00); //  set to 0x00
	    //fixed Guangzhou_482MHz
	    DTMBIP_WriteRegister(0x02E0, 0x90); //  default is 0x60
	    DTMBIP_WriteRegister(0x0243, 0x02); //  default is 0x04
	    DTMBIP_WriteRegister(0x0244, 0x07); //  default is 0x05
	    DTMBIP_WriteRegister(0x0246, 0x80); //  default is 0x78
	    //fixed Changsha_722MHz
	    DTMBIP_WriteRegister(0x00CC, 0x06); //  default is 0x0A
	    DTMBIP_WriteRegister(0x0186, 0x00); //  default is 0x03
	    DTMBIP_WriteRegister(0x0187, 0x80); //  default is 0xFB
	
	return err;
}

UINT8 DTMBIP_SetAutoMode()
{
	UINT8 err = DTMB_NO_ERROR;

	REALTEK_H_DTMB_BASE_DBG("Set AutoMode ");

	/*饜离峈赻雄耀宒*/
	rtd_outl(0xB8140008, 0x00000000);
	return err;
}


BOOL DTMBIP_IsDemodLocked(BOOL PrintInfo, UINT8 *presult, UINT8 *locked, UINT8 *Status)
{
#if DTMBIP_DEBUG_INFO_OPEN
	long SNR, BER, LBER;
	UINT8 Carrier, Mode, Rate, InterleaverLength, PnMode, PnVariable;
	UINT32 FieldStrength, NCOValue;
#endif

	//*locked = rtd_inl(0xB8140044);
	//*Status = rtd_inl(0xB8140040);
	
	    DTMBIP_ReadRegister(0x0011, locked);
		DTMBIP_ReadRegister(0x0010, Status);
	

#if DTMBIP_DEBUG_INFO_OPEN
	DTMBIP_GetSignalSNR(&SNR);
	DTMBIP_GetSignalBER(&BER);
	DTMBIP_GetParameters(&Carrier, &Mode, &Rate, &InterleaverLength, &PnMode, &PnVariable);
	DTMBIP_GetFieldStrength(&FieldStrength);
	DTMBIP_GetLdpcBER(&LBER);
	DTMBIP_GetNCOValue(&NCOValue);
	//REALTEK_H_DTMB_BASE_DBG("SNR: %f,BER: %f,LBER: %f,FS: %d,NCO: 0x%06x", SNR, BER, LBER, FieldStrength, NCOValue);

	REALTEK_H_DTMB_BASE_DBG("Mode:");
	switch (Mode) {
	case DTMB_DTMB_4QAM_NR:
		REALTEK_H_DTMB_BASE_DBG("4QAM_NR, ");
		break;
	case DTMB_DTMB_4QAM:
		REALTEK_H_DTMB_BASE_DBG("4QAM, ");
		break;
	case DTMB_DTMB_16QAM:
		REALTEK_H_DTMB_BASE_DBG("16QAM, ");
		break;
	case DTMB_DTMB_32QAM:
		REALTEK_H_DTMB_BASE_DBG("32QAM, ");
		break;
	case DTMB_DTMB_64QAM:
		REALTEK_H_DTMB_BASE_DBG("64QAM, ");
		break;
	default:
		break;
	}

	REALTEK_H_DTMB_BASE_DBG("PNMode:");
	switch (PnMode) {
	case DTMB_PN_945:
		REALTEK_H_DTMB_BASE_DBG("945, ");
		break;
	case DTMB_PN_595:
		REALTEK_H_DTMB_BASE_DBG("595, ");
		break;
	case DTMB_PN_420:
		REALTEK_H_DTMB_BASE_DBG("420, ");
		break;
	default:
		break;
	}

	REALTEK_H_DTMB_BASE_DBG("Rate:");
	switch (Rate) {
	case DTMB_RATE_04:
		REALTEK_H_DTMB_BASE_DBG("0.4, ");
		break;
	case DTMB_RATE_06:
		REALTEK_H_DTMB_BASE_DBG("0.6, ");
		break;
	case DTMB_RATE_08:
		REALTEK_H_DTMB_BASE_DBG("0.8, ");
		break;
	default:
		break;
	}

	REALTEK_H_DTMB_BASE_DBG("Carrier:");
	switch (Carrier) {
	case DTMB_CARRIER_SINGLE:
		REALTEK_H_DTMB_BASE_DBG("Single, ");
		break;
	case DTMB_CARRIER_MULTI:
		REALTEK_H_DTMB_BASE_DBG("Multi, ");
		break;
	default:
		break;
	}

	REALTEK_H_DTMB_BASE_DBG("Interleave:");
	switch (InterleaverLength) {
	case DTMB_INTERLEAVER_720:
		REALTEK_H_DTMB_BASE_DBG("720, ");
		break;
	case DTMB_INTERLEAVER_240:
		REALTEK_H_DTMB_BASE_DBG("240, ");
		break;
	default:
		break;
	}

	REALTEK_H_DTMB_BASE_DBG("PNVariable:");
	switch (PnVariable) {
	case DTMB_PN_VARIABLE:
		REALTEK_H_DTMB_BASE_DBG("Variable ");
		break;
	case DTMB_PN_FIXED:
		REALTEK_H_DTMB_BASE_DBG("Fixed ");
		break;
	default:
		break;
	}

	REALTEK_H_DTMB_BASE_DBG("\n");
#endif

	if (PrintInfo)
		REALTEK_H_DTMB_BASE_DBG("0x%02x 0x%02x!", *Status, *locked);

	if ((*locked) & 0x01) {
		*presult = 1;
		return TRUE;
	} else {
		*presult = 0;
		return FALSE;
	}
}



UINT8 DTMBIP_SetManualMode(UINT8 CarrierMode, UINT8 mode, UINT8 rate, UINT8 interleaverLength, UINT8 pnmode, UINT8 PnVariable)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData = 0, WriteData = 0;

	REALTEK_H_DTMB_BASE_DBG("Set Manual Mode !");

	//rtd_outl(0xB8140008, 0x000000FF);
	DTMBIP_WriteRegister(0x0002, 0xFF);

	//ReadData = rtd_inl(0xB814000C);
	DTMBIP_ReadRegister(0x0003, &ReadData);
	WriteData = ReadData & 0xE8;
	WriteData |= pnmode;
	WriteData |= (PnVariable << 2);
	WriteData |= (CarrierMode << 4);
	//rtd_outl(0xB814000C, WriteData);
	DTMBIP_WriteRegister(0x0003, WriteData);
	REALTEK_H_DTMB_BASE_DBG("0xB814000C  0x%02x !", WriteData);

	//ReadData = rtd_inl(0xB8140010);
	DTMBIP_ReadRegister(0x0004, &ReadData);
	WriteData = ReadData & 0x88;
	WriteData |= mode;
	WriteData |= (rate << 4);
	WriteData |= (interleaverLength << 6);
	//rtd_outl(0xB8140010, WriteData);
    DTMBIP_WriteRegister(0x0004, WriteData);
	REALTEK_H_DTMB_BASE_DBG("0xB8140010  0x%02x !", WriteData);

	return err;
}


UINT8 DTMBIP_GetNCOValue(UINT32 *NCOValue)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData = 0;

	//ReadData = rtd_inl(0xB8140164);
	DTMBIP_ReadRegister(0x0059, &ReadData);
	*NCOValue = ReadData;

	//ReadData = rtd_inl(0xB8140168);
	DTMBIP_ReadRegister(0x005A, &ReadData);
	*NCOValue <<= 8;
	*NCOValue |= ReadData;

	//ReadData = rtd_inl(0xB814016C);
	DTMBIP_ReadRegister(0x005B, &ReadData);
	*NCOValue <<= 8;
	*NCOValue |= ReadData;

	REALTEK_H_DTMB_BASE_DBG("DemodIP_NCOValue value = %x\n", *NCOValue);
	REALTEK_H_DTMB_BASE_DBG("DemodIP_NCOValue value = %x\n", *NCOValue);
	return err;
}


UINT8 DTMBIP_SetNCOValue(UINT32 NCOValue, UINT32 CO1, UINT32 CO2)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 temp1 = 0, temp2 = 0, temp3 = 0;

	temp1 = (UINT8)((NCOValue & 0x00ff0000) >> 16);
	temp2 = (UINT8)((NCOValue & 0x0000ff00) >> 8);
	temp3 = (UINT8)((NCOValue & 0x000000ff));

	REALTEK_H_DTMB_BASE_DBG("Updage NCO 0x%02x,0x%02x,0x%02x", temp1, temp2, temp3);

	/*Set DTMB related registers*/
	/*初始頻偏控制字計算*/
	//rtd_outl(0xB81400A0, temp1);
	//rtd_outl(0xB81400A4, temp2);
	//rtd_outl(0xB81400A8, temp3);
	
	    DTMBIP_WriteRegister(0x0028, temp1);
		DTMBIP_WriteRegister(0x0029, temp2);
		DTMBIP_WriteRegister(0x002A, temp3);
	
	temp1 = (UINT8)((CO1 & 0x0000ff00) >> 8);
	temp2 = (UINT8)((CO1 & 0x000000ff));
	REALTEK_H_DTMB_BASE_DBG("Updage CO1 0x%02x,0x%02x", temp1, temp2);

	/*掃頻控制字計算*/
	//rtd_outl(0xB8140620, temp1);
	//rtd_outl(0xB8140624, temp2);
	
		DTMBIP_WriteRegister(0x0188, temp1);
		DTMBIP_WriteRegister(0x0189, temp2);
	
	temp1 = (UINT8)((CO2 & 0x0000ff00) >> 8);
	temp2 = (UINT8)((CO2 & 0x000000ff));
	REALTEK_H_DTMB_BASE_DBG("Updage CO2 0x%02x,0x%02x", temp1, temp2);

	/*假鎖頻點補償計算*/
	//rtd_outl(0xB8140618, temp1);
	//rtd_outl(0xB814061C, temp2);
	
		DTMBIP_WriteRegister(0x0186, temp1);
		DTMBIP_WriteRegister(0x0187, temp2);
	
	return err;
}

UINT8 DTMBIP_SetTimeFreq()
{
	UINT8 err = DTMB_NO_ERROR;
    UINT8 ReadData = 0, ReadData1 = 0;
	/*
		long FrequencySample = FREQUENCY_SAMPLE;
		UINT32 TF = 0;
		UINT8 temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;

		TF = (UINT32)((FrequencySample-30.24)/30.24*0x40000000);
		temp1 = (UINT8)((TF & 0xff000000) >> 24);
		temp2 = (UINT8)((TF & 0x00ff0000) >> 16);
		temp3 = (UINT8)((TF & 0x0000ff00) >> 8);
		temp4 = (UINT8)((TF & 0x000000ff));

		REALTEK_H_DTMB_BASE_DBG("Updage Time Frequency 0x%02x,0x%02x,0x%02x,0x%02x", temp1, temp2, temp3, temp4);
	    //rtd_outl(0xB81400E0,temp1);
	    //rtd_outl(0xB81400E4,temp2);
	    //rtd_outl(0xB81400E8,temp3);
	    //rtd_outl(0xB81400EC,temp4);

		DTMBIP_WriteRegister(0x0038, temp1);
		DTMBIP_WriteRegister(0x0039, temp2);
		DTMBIP_WriteRegister(0x003A, temp3);
		DTMBIP_WriteRegister(0x003B, temp4);

		temp1 = (UINT8)(FrequencySample/30.24*25);
		temp1 &= 0x3f;
		temp1 |= 0x80;
	    //rtd_outl(0xB814065C,temp1);
		DTMBIP_WriteRegister(0x0197, temp1);
	    //temp1 = rtd_inl(0xB8140088);
		DTMBIP_ReadRegister(0x0022, &temp1);
		temp1 |= 0x0A;  // bit3 = 1  and bit1 = 1 adc_data format = unsigned
	    //rtd_outl(0xB8140088,temp1);
		DTMBIP_WriteRegister(0x0022, temp1);
	*/
    DTMBIP_WriteRegister(0x0038,0x00);
    DTMBIP_WriteRegister(0x0039,0x49);
    DTMBIP_WriteRegister(0x003a,0x24);
    DTMBIP_WriteRegister(0x003b,0x92);
	//rtd_outl(0xB81400E0, 0x00);
	//rtd_outl(0xB81400E4, 0x49);
	//rtd_outl(0xB81400E8, 0x24);
	//rtd_outl(0xB81400EC, 0x92);

	// b.碼捕獲計算
	//rtd_maskl(0xB814065C, 0xFFFFFF40, 0x00000099);
	DTMBIP_ReadRegister(0x0197, &ReadData);
    DTMBIP_WriteRegister(0x0197,(ReadData&0xFFFFFF40) | 0x00000099);
    

// c.手動輸入enable
	//rtd_maskl(0xB8140088, 0xFFFFFFF7, 0x0000000A); 	// adc format offset_binary_en 偏移二?制?? [bit1 ]: 1 = 偏移二?制 ;  0 = 2的補數
    DTMBIP_ReadRegister(0x0022, &ReadData1);
    DTMBIP_WriteRegister(0x0022,(ReadData1&0xFFFFFFF5) | 0x0000000A);
    
	return err;
}

UINT8 DTMBIP_SetAXIBus(UINT32 AXIBus)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;

	temp1 = (UINT8)((AXIBus & 0xff000000) >> 24);
	temp2 = (UINT8)((AXIBus & 0x00ff0000) >> 16);
	temp3 = (UINT8)((AXIBus & 0x0000ff00) >> 8);
	temp4 = (UINT8)((AXIBus & 0x000000ff));

	REALTEK_H_DTMB_BASE_DBG("Updage AXI Offset 0x%02x,0x%02x,0x%02x,0x%02x", temp1, temp2, temp3, temp4);
	//rtd_outl(0xB8142024, temp1);
	//rtd_outl(0xB8142020, temp2);
	//rtd_outl(0xB814201C, temp3);
	//rtd_outl(0xB8142018, temp4);
	
		DTMBIP_WriteRegister(0x0809, temp1);
		DTMBIP_WriteRegister(0x0808, temp2);
		DTMBIP_WriteRegister(0x0807, temp3);
		DTMBIP_WriteRegister(0x0806, temp4);
	
	return err;
}

UINT8 DTMBIP_SetSpectrum(UINT8 SpectrumMode)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData = 0, WriteData = 0;

	//ReadData = rtd_inl(0xB8140084);
	DTMBIP_ReadRegister(0x0021, &ReadData);
	if (SpectrumMode == DTMB_SPECTRUM_NEGATIVE) {
		WriteData = ReadData & 0xDF;
	} else if (DTMB_SPECTRUM_POSITIVE) {
		WriteData = ReadData | 0x20;
	}
	//rtd_outl(0xB8140084, WriteData);
	DTMBIP_WriteRegister(0x0021, WriteData);

	return err;
}

#if 0
static long DTMBIP_ABS(long x)
{
	return x < 0 ? -x : x;
}
#endif


UINT8 DTMBIP_CalculateNCOValue(long TunerIF, UINT32 *NCOValue, UINT32 *CO1, UINT32 *CO2)
{
	UINT8 err = DTMB_NO_ERROR;
#if 0
	long FrequencySample = FREQUENCY_SAMPLE;
	long FrequencySymble = FREQUENCY_SYMBOL;
	unsigned long Temp;

	if (TunerIF == 0) {
		*NCOValue = 0;
		/*
				return err;
			}

			if(CrystalSelect == HDIC2311_CRYSTAL_27M )
			{
				FrequencySample = 30.375;
			}
			else if(CrystalSelect == HDIC2311_CRYSTAL_304M )
			{
				FrequencySample = 30.4;
		*/
	} else {
		Temp = DTMBIP_ABS(FrequencySample - TunerIF);
		if (Temp < TunerIF) {
			*NCOValue = (UINT32)(Temp / FrequencySample * 0x800000);
		} else {
			*NCOValue = (UINT32)(TunerIF / FrequencySample * 0x800000);
		}
	}
	*CO1 = (UINT32)((FrequencySymble * 100) / (5000 * FrequencySample) / 100 * 0x800000);
	*CO2 = (UINT32)((FrequencySymble * 100) / (2048 * FrequencySample) / 100 * 0x800000);
#endif
	*NCOValue = 0x1511e8;
	*CO1 = 0x01a2;
	*CO2 = 0x03fb;

	return err;
}


UINT8 DTMBIP_GetParameters(UINT8 *CarrierMode, UINT8 *pmode,
						   UINT8 *prate, UINT8 *pinterleaverLength, UINT8 *Pnmode, UINT8 *PnVariable)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData1 = 0, ReadData2 = 0;

	REALTEK_H_DTMB_BASE_DBG("DemoIP_GetParameters_HDIC_GetParameters_HDIC_GetParameters\n");

	//ReadData1 = rtd_inl(0xB8140014);
	//ReadData2 = rtd_inl(0xB8140018);
	DTMBIP_ReadRegister(0x0005, &ReadData1);
	DTMBIP_ReadRegister(0x0006, &ReadData2);

	//REALTEK_H_DTMB_BASE_INFO("DemoIP_0x0005 = %d\n",ReadData1);
	//REALTEK_H_DTMB_BASE_INFO("DemoIP_0x0006 = %d\n",ReadData2);

	*Pnmode = ReadData1 & 0x03;
	//REALTEK_H_DTMB_BASE_INFO("DemoIP_PNmode = %d, Pnmode_tmp = %d\n",*Pnmode);
	*PnVariable = ReadData1 & 0x04;
	*PnVariable >>= 2;
	//REALTEK_H_DTMB_BASE_INFO("DemoIP_PNVariable = %d\n",*PnVariable );
	*CarrierMode = ReadData1 & 0x10;
	*CarrierMode >>= 4;
	//REALTEK_H_DTMB_BASE_INFO("DemoIP_CarrierMode = %d\n",*CarrierMode );

	*pmode = ReadData2 & 0x07;
	//REALTEK_H_DTMB_BASE_INFO("DemoIP_pmode = %d\n",*pmode );
	*prate = ReadData2 & 0x30;
	*prate >>= 4;
	//REALTEK_H_DTMB_BASE_INFO("DemoIP_prate = %d\n",*prate );
	*pinterleaverLength = ReadData2 & 0x40;
	*pinterleaverLength >>= 6;
	//REALTEK_H_DTMB_BASE_INFO("DemoIP_pinterleaverLength = %d\n",*pinterleaverLength );

	return err;
}


UINT8 DTMBIP_GetSignalSNRMC(long *SignalSNR)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData1 = 0, ReadData2 = 0;
	UINT32 value_reg;

	//ReadData1 = rtd_inl(0xB8140B24);
	//ReadData2 = rtd_inl(0xB8140B20);
	DTMBIP_ReadRegister(0x02C9, &ReadData1);
	DTMBIP_ReadRegister(0x02C8, &ReadData2);

	value_reg = ReadData1 * 256 + ReadData2;

	if ((value_reg != 0) && (value_reg != 0xFFFF)) {
		if (value_reg < 16) {
			value_reg = 16;
		}

#if SYSTEM_NOT_SUPPORT_LOG10
		*SignalSNR = Log10_Convert((UINT32)(value_reg / 16));
#else
		*SignalSNR = 10 * log10((long)(value_reg) / 16);
#endif
	}

	//REALTEK_H_DTMB_BASE_DBG("SNR_MC %d ",(UINT8)(*SignalSNR));

	return err;
}

UINT8 DTMBIP_GetSignalSNRSC(long *SignalSNR)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData1 = 0, ReadData2 = 0;
	UINT32 value_reg;
	UINT8 Pnmode;
	UINT32 PnValue = 0;
	long value_temp = 0;

	//ReadData1 = rtd_inl(0xB8140014);
	DTMBIP_ReadRegister(0x0005, &ReadData1);
	Pnmode = ReadData1 & 0x03;

	if (Pnmode == DTMB_PN_945) {
		PnValue = 945;
	} else if (Pnmode == DTMB_PN_595) {
		PnValue = 595;
	} else if (Pnmode == DTMB_PN_420) {
		PnValue = 420;
	}

	//ReadData1 = rtd_inl(0xB8140A94);
	//ReadData2 = rtd_inl(0xB8140A90);
	DTMBIP_ReadRegister(0x02A5, &ReadData1);
	DTMBIP_ReadRegister(0x02A4, &ReadData2);

	value_reg = ReadData1 * 256 + ReadData2;
	if ((value_reg != 0) && (value_reg != 0xFFFF)) {
		value_temp = (81 * PnValue) / value_reg / 2;


		if (value_temp < 1) {
			value_temp = 1;
		}

#if SYSTEM_NOT_SUPPORT_LOG10
		*SignalSNR = Log10_Convert((UINT32)value_temp);
#else
		*SignalSNR = 10 * log10(value_temp);
#endif

	} else {
		*SignalSNR = 0;
	}

	//REALTEK_H_DTMB_BASE_INFO("DemoIP_SNR_SC = %d\n ",*SignalSNR); //Get SNR_SC
	return (err);
}



/****************************
Get Signal SNR
****************************/
UINT8 DTMBIP_GetSignalSNR(long *SignalSNR)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData1 = 0;
	UINT8 CarrierMode;

	/*Get Working Mode,DTMB or Cable*/

	//ReadData1 = rtd_inl(0xB8140014);
	DTMBIP_ReadRegister(0x0005, &ReadData1);
	CarrierMode = ReadData1 & 0x10;
	CarrierMode >>= 4;

	if (CarrierMode == DTMB_CARRIER_SINGLE) {
		DTMBIP_GetSignalSNRSC(SignalSNR);
	} else if (CarrierMode == DTMB_CARRIER_MULTI) {
		DTMBIP_GetSignalSNRMC(SignalSNR);
	}
	return err;
}


/****************************
In Dtmb Mode, Get LDPC BER
****************************/
UINT8 DTMBIP_GetLdpcBER(long *pLdpcBER)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData1 = 0, ReadData2 = 0;

	//ReadData1 = rtd_inl(0xB81402A8);
    //ReadData2 = rtd_inl(0xB81402A4);
	DTMBIP_ReadRegister(0x00AA, &ReadData1);
	DTMBIP_ReadRegister(0x00A9, &ReadData2);

	//*pLdpcBER = ((ReadData2&0x0f)*256+ReadData1)/4096;
	*pLdpcBER = ((ReadData2 & 0x0f) * 256 + ReadData1);
	//REALTEK_H_DTMB_BASE_INFO("DTMBIP_GetLBER = %d\n",*pLdpcBER);  // printf DTMBIP_LBER

	return err;
}

/****************************
In Dtmb Mode, Get Signal BER
****************************/
UINT8 DTMBIP_GetSignalBER(long *pSignalBER)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData1 = 0, ReadData2 = 0;

	//ReadData1 = rtd_inl(0xB814029C);
	//ReadData2 = rtd_inl(0xB81402A0);
	DTMBIP_ReadRegister(0x00A7, &ReadData1);
	DTMBIP_ReadRegister(0x00A8, &ReadData2);

	//*pSignalBER = (long)(ReadData1 * 256 + ReadData2) / 6666664;
	*pSignalBER = (ReadData1 * 256 + ReadData2);

	return (err);
}
/****************************
****************************/
UINT8 DTMBIP_GetFieldStrength(UINT32 *FieldStrength)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData1 = 0, ReadData2 = 0;

	//ReadData1 = rtd_inl(0xB8140184);
	//ReadData2 = rtd_inl(0xB8140188);
	DTMBIP_ReadRegister(0x0061, &ReadData1);
	DTMBIP_ReadRegister(0x0062, &ReadData2);

	*FieldStrength = (UINT16)(ReadData1 * 256 + ReadData2);

	//REALTEK_H_DTMB_BASE_DBG("FieldStrength %d\n",*FieldStrength);

	return (err);
}
/************************************
*************************************/
UINT8 DTMBIP_SoftReset()
{
	UINT8 err = DTMB_NO_ERROR;

	/*鳳�★尤鷵�宒,DTMB*/
//	rtd_outl(0xB8140024, 0x00000010);
//	tv_osal_msleep(10);
//	rtd_outl(0xB8140024, 0x00000000);
	
		DTMBIP_WriteRegister(0x0009, 0x10);
		DTMBIP_Wait(10);
		DTMBIP_WriteRegister(0x0009, 0x00);
	
	return (err);
}

/************************************
*************************************/
UINT8 DTMBIP_SetTunerType(UINT8 Type)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData = 0, WriteData = 0;

	//ReadData = rtd_inl(0xB8140088);
	DTMBIP_ReadRegister(0x0022, &ReadData);

	if (Type == DTMB_TUNER_ZERO_IF) {
		WriteData = ReadData | 0x01;
	} else {
		WriteData = ReadData & 0xFE;
	}
	//rtd_outl(0xB8140088, WriteData);
	DTMBIP_WriteRegister(0x0022, WriteData);

	return (err);
}
/************************************
*************************************/
UINT8 DTMBIP_SetTsFormat(UINT8 Serial, UINT8 CLK_Polarity, UINT8 CLK_Valid, UINT8 Null_Packet, UINT8 Serial_Output, UINT8 Serial_Order, UINT8 Serial_Sync)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData = 0, WriteData = 0;

	//ReadData = rtd_inl(0xB814028C);
	DTMBIP_ReadRegister(0x00A3, &ReadData);

	WriteData = ReadData & 0x60;

	if (Serial == DTMB_TS_OUTPUT_PARALLEL) {
		WriteData |= 0x08;
	}

	if (CLK_Polarity == DTMB_TS_DATA_SAMPLE_RISING) {
		WriteData |= 0x04;
	}

	if (CLK_Valid == DTMB_TS_CLK_WITH_TSVLD) {
		WriteData |= 0x02;
	}

	if (Null_Packet == DTMB_TS_NULLPACKET_DELETED) {
		WriteData |= 0x01;
	}

	if (Serial_Output == DTMB_TS_SERIAL_OUTPUT_D0) {
		WriteData |= 0x10;
	}

	if (Serial_Order == DTMB_TS_SERIAL_LSB_TO_MSB) {
		WriteData |= 0x80;
	}

	//rtd_outl(0xB814028C, WriteData);
	DTMBIP_WriteRegister(0x00A3, WriteData);

	REALTEK_H_DTMB_BASE_DBG("TS Format 0x%02x\n", WriteData);

	return (err);
}

/****************************
Open I2C Transmitted Function
****************************/
/*
UINT8 HDIC2311_OpenTunerI2C(UINT8 Address)
{
	UINT8 err = HDIC_NO_ERROR;
	UINT8 ReadData = 0;

	HDICTBX_Print(("Set 2311 Tuner I2C Address 0x%02x!!\n",Address));
	Address &= 0xFE;
	HDIC2311_WriteRegister(0x000F,Address);
	HDIC2311_WriteRegister(0x000E,0x01);
	return (err);

}
*/
/****************************
Close I2C Transmitted Function
****************************/
/*
UINT8 HDIC2311_CloseTunerI2C(void)
{
	UINT8 err = HDIC_NO_ERROR;

	HDICTBX_Print(("2311 Close Tuner I2C!"));

	err = HDIC2311_WriteRegister(0x000E,0x00);

	return (err);
}
*/

/********************************
Get Signal Stength
If tuner AGC is auto control, please using tuner signal strength function
********************************/
UINT8 DTMBIP_GetSignalStrength(UINT8 *SignalStrength)
{
	UINT8 err = DTMB_NO_ERROR;
	UINT32 FieldStrength;

	DTMBIP_GetFieldStrength(&FieldStrength);

	/* It can modify this function to get expect reasonable signal strength, the range is 0~100
	*/
	if (FieldStrength >= 0x800)
		FieldStrength = 0x800;
	if (FieldStrength <= 0x418)
		FieldStrength = 0x418;
	*SignalStrength = (UINT8)((0x800 - FieldStrength) / 12);

	REALTEK_H_DTMB_BASE_DBG("SignalStrength %d !!!", *SignalStrength);

	return err;
}

/********************************
Get Signal Quality
********************************/
UINT8 DTMBIP_GetSignalQuality(UINT8 *SignalQuality)
{
	UINT8 err = DTMB_NO_ERROR;
	long SignalSNR, SQI;

	DTMBIP_GetSignalSNR(&SignalSNR);

	//*SignalQuality = (UINT8)SignalSNR;
	//(*SignalQuality) *= 3;

	SQI = (SignalSNR * 3) / 10000;

	*SignalQuality = (UINT8) SQI ;

	if (*SignalQuality >= 98) {
		*SignalQuality = 98;
	}

	REALTEK_H_DTMB_BASE_DBG("DTMB_DemodIP_SignalQuality %d !!!", *SignalQuality);
	return err;
}
//#if DTMBIP_BANDWIDTH_6M
/************************************
** 扢离炵苀湍遵ㄩ
**DTMBIP_BANDWIDTH_6M
*************************************/
UINT8 DTMBIP_SetSytemBandwidth6M()
{
	UINT8 err = DTMB_NO_ERROR;
	UINT8 ReadData = 0, WriteData = 0;


	DTMBIP_ReadRegister(0x0022, &ReadData);
	ReadData |= 0x08;                           //bit3 : timing_cw_manual_en set to 1 then could modify
	DTMBIP_WriteRegister(0x0022, ReadData);

	err = DTMBIP_WriteRegister(0x0038, 0x15);   //update in 2018/04/02
	err = DTMBIP_WriteRegister(0x0039, 0xB6);
	err = DTMBIP_WriteRegister(0x003A, 0xDB);
	err = DTMBIP_WriteRegister(0x003B, 0x6D);
	err = DTMBIP_WriteRegister(0x0180, 0x0E);
	err = DTMBIP_WriteRegister(0x0181, 0xCB);			
	err = DTMBIP_WriteRegister(0x0182, 0x02);
	err = DTMBIP_WriteRegister(0x0183, 0xE4);			
	err = DTMBIP_WriteRegister(0x0184, 0x06);
	err = DTMBIP_WriteRegister(0x0185, 0x75);			
	err = DTMBIP_WriteRegister(0x0186, 0x03);
	err = DTMBIP_WriteRegister(0x0187, 0x5C);			
	err = DTMBIP_WriteRegister(0x0188, 0x01);
	err = DTMBIP_WriteRegister(0x0189, 0x39);			
	err = DTMBIP_WriteRegister(0x0197, 0x2B);						

	return err;
}
//#endif 

/********************************
IC Initialization, it is called during system initialization
********************************/
UINT8 DTMBIP_Init()
{
	UINT8 err = DTMB_NO_ERROR;
	UINT32 NCOValue = 0;
	UINT32 CO1 = 0;
	UINT32 CO2 = 0;
	UINT32 AXIBus = 0x02000000;
	DTMBIP_Init_Info InitInfo;

	/*Initialize HD2311 Allocation*/
	//InitInfo.WorkMode         = HDIC2311_DTMB_SELECT;			/*Working Mode: Terrestrial and Cable*/
	InitInfo.TunerType          = DTMB_TUNER_NORMAL;			/*LNB Type, Zero-IF or Other*/
	/*the IF of the LNB, Units: MHz, Zero-IF LNB is assigned to 0 */
	InitInfo.TunerIF            = 5;							/*the IF of the LNB, Units: MHz, Zero-IF LNB is assigned to 0 */
	//InitInfo.CrystalSelect    = HDIC2311_CRYSTAL_24M;			/*Crystal Selection, Units: MHZ, 16Mhz/24Mhz/27Mhz/30.4Mhz */
	InitInfo.TsType             = DTMB_TS_OUTPUT_PARALLEL;		/*TS Output Mode, serial or parallel mode*/
	InitInfo.TsClockPolarity    = DTMB_TS_DATA_SAMPLE_RISING;	/*Sample at rising or falling edges*/
	InitInfo.TsClockValid       = DTMB_TS_CLK_WITH_TSVLD;		/* Valid Clock Method, always valid or depends on valid signals*/
	InitInfo.TsNullPacket       = DTMB_TS_NULLPACKET_DELETED;	/*Null Packets detected enable */
	InitInfo.TsSerialOutPut     = DTMB_TS_SERIAL_OUTPUT_D7;		/*In Serial TS Mode, output pin is TS_D7 or TS_D0 */
	InitInfo.TsSerialOrder      = DTMB_TS_SERIAL_MSB_TO_LSB;
	InitInfo.TsSerialSyncMode   = DTMB_TS_SERIAL_SYNC_BIT;

	/* HWReset DTMBIP*/
	DTMBIP_HWReset();

	//DTMBIP_TunerInit();
	/* According Tuner IF and Crystals to count NCO */
	DTMBIP_CalculateNCOValue(InitInfo.TunerIF, &NCOValue, &CO1, &CO2);
	/* Set NCO */
	DTMBIP_SetNCOValue(NCOValue, CO1, CO2);

	DTMBIP_SetTimeFreq();

	/* Set Tuner Type, Zero-IF or Other*/
	DTMBIP_SetTunerType(InitInfo.TunerType);

	DTMBIP_SetSpectrum(DTMB_SPECTRUM_POSITIVE);

	/* Set TS Ouput Format*/
	DTMBIP_SetTsFormat(InitInfo.TsType, InitInfo.TsClockPolarity, InitInfo.TsClockValid, InitInfo.TsNullPacket, InitInfo.TsSerialOutPut, InitInfo.TsSerialOrder, InitInfo.TsSerialSyncMode);
	//DTMBIP_SetIfInverse();
	/* Set Working Mode */

	DTMBIP_SetAXIBus(AXIBus); //set AXI

	DTMBIP_SetAutoMode();

	DTMBIP_SetWorkMode();

	DTMBIP_SoftReset();
	//tv_osal_msleep(100);

//    #if DTMBIP_BANDWIDTH_6M
//	    /* Set Bandwidth6M*/
//	    DTMBIP_SetSytemBandwidth6M();
//	#endif
	REALTEK_H_DTMB_BASE_DBG("RealtekH_DTMB init done!!");
	return (err);
}

/********************************
the function that set frequency in cable signal
********************************/
BOOL DTMBIP_DTMBSetFrequency(UINT32 Frequency)
{
	UINT8 CheckLockTemp, LockResult, locked, status;
	BOOL SignalDetect = FALSE;
	//UINT8 ReadData = 0;
#if DTMBIP_SPECTRUM_ADJUST_OPEN
	UINT8 ReadData0 = 0, ReadData1 = 0, ReadData2 = 0;
#endif

	/********************
	** It needs to set Tuner Frequency first
	********************/
	if (DTMBIP_TunerLock(Frequency) != TRUE) {
		return FALSE;
	}

	/* Setting the work mode is auto*/
	DTMBIP_SetAutoMode();
	//HDIC2311_SoftReset();

#if DTMBIP_SPECTRUM_ADJUST_OPEN
	DTMBIP_SetSpectrum(DTMB_SPECTRUM_NEGATIVE);
	DTMBIP_SoftReset();
	for (CheckLockTemp = 0; CheckLockTemp < 20; CheckLockTemp++) {
		tv_osal_msleep(100); /* wait 100 ms */
		DTMBIP_IsDemodLocked(TRUE, &LockResult, &locked, &status);
		if ((status & 0xf0) > 0x20) {
			SignalDetect = TRUE;
		}
		if ((SignalDetect == FALSE) && (CheckLockTemp == 15)) {
			REALTEK_H_DTMB_BASE_WARNING("---> [DTMBIP] DTMBIP DTMB No Signal \n");
			return FALSE;
		}
		if (LockResult == 1) {
			//ReadData0 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData0);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData1 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData1);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData2 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData2);
			CheckLockTemp++;
			CheckLockTemp++;
			if ((ReadData0 == ReadData1) && (ReadData1 == ReadData2)) {
				/*	ReadData0 &= 0x07;
					if(ReadData0 == 0x02)
					{
				        //rtd_outl(0xB8142CFC,0x00000000);
				        //rtd_outl(0xB8142770,0x00000000);
						DTMBIP_WriteRegister(0x0b3f, 0x00);
						DTMBIP_WriteRegister(0x09d0, 0x00);
					}
					else
					{
				        //rtd_outl(0xB8142CFC,0x00000001);
				        //rtd_outl(0xB8142770,0x00000001);
						DTMBIP_WriteRegister(0x0b3f, 0x01);
						DTMBIP_WriteRegister(0x09d0, 0x01);
					}*/
				REALTEK_H_DTMB_BASE_DBG("---> [DTMBIP] DTMBIP DTMB is locked \n");
				return TRUE;
			} else {
				break;
			}
		}
	}
	/*Do Spectrum Adjust Try*/
	DTMBIP_SetSpectrum(DTMB_SPECTRUM_POSITIVE);
	DTMBIP_SoftReset();
	SignalDetect = FALSE;

	for (CheckLockTemp = 0; CheckLockTemp < 20; CheckLockTemp++) {
		tv_osal_msleep(100); /* wait 100 ms */
		DTMBIP_IsDemodLocked(TRUE, &LockResult, &locked, &status);
		if ((status & 0xf0) > 0x20) {
			SignalDetect = TRUE;
		}
		if ((SignalDetect == FALSE) && (CheckLockTemp == 15)) {
			REALTEK_H_DTMB_BASE_WARNING("---> [DTMBIP] DTMBIP DTMB No Signal \n");
			return FALSE;
		}
		if (LockResult == 1) {
			//ReadData0 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData0);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData1 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData1);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData2 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData2);
			CheckLockTemp++;
			CheckLockTemp++;
			if ((ReadData0 == ReadData1) && (ReadData1 == ReadData2)) {
				ReadData0 &= 0x07;
				if (ReadData0 == 0x02) {
					//rtd_outl(0xB8142CFC, 0x00000000);
					//rtd_outl(0xB8142770, 0x00000000);
					DTMBIP_WriteRegister(0x0b3f, 0x00);
					DTMBIP_WriteRegister(0x09d0, 0x00);
				} else {
					//rtd_outl(0xB8142CFC, 0x00000001);
					//rtd_outl(0xB8142770, 0x00000001);
					DTMBIP_WriteRegister(0x0b3f, 0x01);
					DTMBIP_WriteRegister(0x09d0, 0x01);
				}

				REALTEK_H_DTMB_BASE_DBG("---> [DTMBIP] DTMBIP DTMB is locked \n");
				return TRUE;
			} else {
				break;
			}
		}
	}
	DTMBIP_SetSpectrum(DTMB_SPECTRUM_NEGATIVE);
	DTMBIP_SoftReset();
#else
	DTMBIP_SoftReset();
	for (CheckLockTemp = 0; CheckLockTemp < 30; CheckLockTemp++) {
		tv_osal_msleep(100); /* wait 100 ms */
		DTMBIP_IsDemodLocked(TRUE, &LockResult, &locked, &status);
		if ((status & 0xf0) > 0x20) {
			SignalDetect = TRUE;
		}
		if ((SignalDetect == FALSE) && (CheckLockTemp == 15)) {
			REALTEK_H_DTMB_BASE_WARNING("---> [DTMBIP] DTMBIP DTMB No Signal \n");
			return FALSE;
		}
		if (LockResult == 1) {
			/*   ReadData = rtd_inl(0xB8140018);
			//DTMBIP_ReadRegister(0x0006, &ReadData);
			ReadData &= 0x07;
			if(ReadData == 0x02)
			{
			    //rtd_outl(0xB8142CFC,0x00000000);
			    //rtd_outl(0xB8142770,0x00000000);
				DTMBIP_WriteRegister(0x0b3f, 0x00);
				DTMBIP_WriteRegister(0x09d0, 0x00);
			}
			else
			{
			    //rtd_outl(0xB8142CFC,0x00000001);
			    //rtd_outl(0xB8142770,0x00000001);
				DTMBIP_WriteRegister(0x0b3f, 0x01);
				DTMBIP_WriteRegister(0x09d0, 0x01);
			}*/

			REALTEK_H_DTMB_BASE_DBG("---> [DTMBIP] DTMBIP DTMB is locked \n");
			return TRUE;
		}
	}
#endif
	return FALSE;
}

/********************************
Manual Set Dtmb Frequency
********************************/
BOOL DTMBIP_DTMBManualSetFrequency(UINT32 Frequency, UINT8 CarrierMode, UINT8 mode, UINT8 rate, UINT8 interleaverLength, UINT8 pnmode, UINT8 PnVariable)
{
	UINT8 CheckLockTemp, LockResult, locked, status = 0;
	BOOL SignalDetect = FALSE;
#if DTMBIP_SPECTRUM_ADJUST_OPEN
	UINT8 ReadData0 = 0, ReadData1 = 0, ReadData2 = 0;
#endif

	/********************
	** It needs to set tuner first
	********************/
	if (DTMBIP_TunerLock(Frequency) != TRUE) {
		return FALSE;
	}

	/* Set Manual Mode */
	DTMBIP_SetManualMode(CarrierMode, mode, rate, interleaverLength, pnmode, PnVariable);
#if DTMBIP_SPECTRUM_ADJUST_OPEN
	DTMBIP_SetSpectrum(DTMB_SPECTRUM_NEGATIVE);
	DTMBIP_SoftReset();

	for (CheckLockTemp = 0; CheckLockTemp < 50; CheckLockTemp++) {
		tv_osal_msleep(100); /* wait 100 ms */
		DTMBIP_IsDemodLocked(TRUE, &LockResult, &locked, &status);
		//HDIC2311_Wait(100); /* wait 100 ms */
		if ((status & 0xf0) > 0x20) { /* When no signal continues 2 secs, it will exit */
			SignalDetect = TRUE;
		}
		if ((SignalDetect == FALSE) && (CheckLockTemp == 15)) {
			REALTEK_H_DTMB_BASE_WARNING("---> [DTMBIP] DTMBIP DTMB No Signal \n");
			return FALSE;
		}
		if (LockResult == 1) {
			//ReadData0 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData0);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData1 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData1);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData2 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData2);
			CheckLockTemp++;
			CheckLockTemp++;
			if ((ReadData0 == ReadData1) && (ReadData1 == ReadData2)) {
				REALTEK_H_DTMB_BASE_DBG("---> [DTMBIP] DTMBIP DTMB is locked \n");
				return TRUE;
			} else {
				break;
			}
		}
	}
	/*Do Spectrum Adjust Try*/
	DTMBIP_SetSpectrum(DTMB_SPECTRUM_POSITIVE);
	DTMBIP_SoftReset();
	SignalDetect = FALSE;

	for (CheckLockTemp = 0; CheckLockTemp < 20; CheckLockTemp++) {
		tv_osal_msleep(100); /* wait 100 ms */
		DTMBIP_IsDemodLocked(TRUE, &LockResult, &locked, &status);
		if ((status & 0xf0) > 0x20) {
			SignalDetect = TRUE;
		}
		if ((SignalDetect == FALSE) && (CheckLockTemp == 15)) {
			REALTEK_H_DTMB_BASE_WARNING("---> [DTMBIP] DTMBIP DTMB No Signal \n");
			return FALSE;
		}
		if (LockResult == 1) {
			//ReadData0 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData0);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData1 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData1);
			tv_osal_msleep(100); /* wait 100 ms */
			//ReadData0 = rtd_inl(0xB8140018);
			DTMBIP_ReadRegister(0x0006, &ReadData2);
			CheckLockTemp++;
			CheckLockTemp++;
			if ((ReadData0 == ReadData1) && (ReadData1 == ReadData2)) {
				REALTEK_H_DTMB_BASE_DBG("---> [DTMBIP] DTMBIP DTMB is locked \n");
				return TRUE;
			} else {
				break;
			}
		}
	}
	DTMBIP_SetSpectrum(DTMB_SPECTRUM_NEGATIVE);
	DTMBIP_SoftReset();
#else
	DTMBIP_SoftReset();
	for (CheckLockTemp = 0; CheckLockTemp < 30; CheckLockTemp++) {
		tv_osal_msleep(100); /* wait 100 ms */
		DTMBIP_IsDemodLocked(TRUE, &LockResult, &locked, &status);
		if ((status & 0xf0) > 0x20) { /*拸陓瘍2鏃豖堤*/
			SignalDetect = TRUE;
		}
		if ((SignalDetect == FALSE) && (CheckLockTemp == 15)) {
			REALTEK_H_DTMB_BASE_WARNING("---> [DTMBIP] DTMBIP DTMB No Signal \n");
			return FALSE;
		}
		if (LockResult == 1) {
			REALTEK_H_DTMB_BASE_DBG("---> [DTMBIP] DTMBIP DTMB is locked \n");
			return TRUE;
		}
	}
#endif
	return FALSE;
}

