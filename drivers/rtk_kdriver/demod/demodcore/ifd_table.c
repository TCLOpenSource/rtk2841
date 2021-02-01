/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date:
 * @version 	$Revision: 0.1 $
 * @ingroup 	ifd
 */

/**
 * @addtogroup ifd
 * @{
 */
#include "tuner.h"
#include "ifd_new.h"


/*================ Module dependency  =============== */

//#include <ifd_new.h>

//StructIFDDataType stIFDdefaultUserData;
StructIFDDataType stIFDUserData;


void drv_ifd_CrBpf_init(unsigned short  tuner_id)
{

	//IFD_DEBUG_MSG(IFD_MSG_INIT, "\n[IFD] user data init \n");
	UINT8 k;

	switch (tuner_id) {

	case TV_TUNER_NXP_TDA18275A : {

		StructCrBpfNew stCrBpfArrayMN[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayB[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayGHI[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayDK[] = {
			{IFD_CRBPF_NEG_16M},
		};
		StructCrBpfNew stCrBpfArrayL[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayLA[] = {
			{IFD_CRBPF_POS_16M_N22P5,},
		};

		for (k = 0; k < IFD_CR_BPF_TABLE_SIZE; k++) {
			stIFDUserData.CRBpf_Table_MN[k] = stCrBpfArrayMN[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_B[k] = stCrBpfArrayB[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_GH[k] = stCrBpfArrayB[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_I[k] = stCrBpfArrayGHI[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_DK[k] = stCrBpfArrayDK[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_L [k] = stCrBpfArrayL[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_LA[k] = stCrBpfArrayLA[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_SCAN[k] = stCrBpfArrayDK[0].CrBpf_Table[k];
		}
	}
	break;

	case TV_TUNER_SILICONLABS_SI2178B:
	case TV_TUNER_SILICONLABS_SI2151:
	case TV_TUNER_NO_TUNER: {

		StructCrBpfNew stCrBpfArrayMN[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayB[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayGHI[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayDK[] = {
			{IFD_CRBPF_NEG_16M},
		};
		StructCrBpfNew stCrBpfArrayL[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayLA[] = {
			{IFD_CRBPF_NEG_16M,},
		};

		for (k = 0; k < IFD_CR_BPF_TABLE_SIZE; k++) {
			stIFDUserData.CRBpf_Table_MN[k] = stCrBpfArrayMN[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_B[k] = stCrBpfArrayB[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_GH[k] = stCrBpfArrayGHI[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_I[k] = stCrBpfArrayGHI[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_DK[k] = stCrBpfArrayDK[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_L [k] = stCrBpfArrayL[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_LA[k] = stCrBpfArrayLA[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_SCAN[k] = stCrBpfArrayB[0].CrBpf_Table[k];
		}
	}
	break;

	case TV_TUNER_MAXLINEAR_MXL661: {

		StructCrBpfNew stCrBpfArrayMN[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayB[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayGHI[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayDK[] = {
			{IFD_CRBPF_NEG_16M},
		};
		StructCrBpfNew stCrBpfArrayL[] = {
			{IFD_CRBPF_NEG_16M,},
		};
		StructCrBpfNew stCrBpfArrayLA[] = {
			{IFD_CRBPF_POS_16M_N22P5,},
		};

		for (k = 0; k < IFD_CR_BPF_TABLE_SIZE; k++) {
			stIFDUserData.CRBpf_Table_MN[k] = stCrBpfArrayMN[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_B[k] = stCrBpfArrayB[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_GH[k] = stCrBpfArrayGHI[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_I[k] = stCrBpfArrayGHI[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_DK[k] = stCrBpfArrayDK[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_L [k] = stCrBpfArrayL[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_LA[k] = stCrBpfArrayLA[0].CrBpf_Table[k];
			stIFDUserData.CRBpf_Table_SCAN[k] = stCrBpfArrayB[0].CrBpf_Table[k];
		}
	}
	break;


	default:
		IFD_DEBUG_MSG(IFD_MSG_INFO, "[Realtek_ATV]  unkonw tuner id %d, can't load IFD CrBpf table\n", tuner_id);
		break;

	}


}


void drv_ifd_OutputLpf_init(unsigned short  tuner_id)
{

	//IFD_DEBUG_MSG(IFD_MSG_INIT, "\n[IFD] user data init \n");
	UINT8 k;

	switch (tuner_id) {
	case TV_TUNER_NXP_TDA18275A : {

		StructOuputLpfCoef stStructOuputLpfCoefNtsc[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_MN,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalBg[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_BG,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalI[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_I,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalDKL[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_DKL,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefSecam[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_DKL,},
		};

		for (k = 0; k < IFD_OUTPUT_LPF_TABLE_SIZE; k++) {
			stIFDUserData.VideoLpfNTSC[k] = stStructOuputLpfCoefNtsc[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_BG[k] = stStructOuputLpfCoefPalBg[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_I[k] = stStructOuputLpfCoefPalI[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_DKL[k] = stStructOuputLpfCoefPalDKL[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfSECAM[k] = stStructOuputLpfCoefSecam[0].StructOuputLpfCoef_Table[k];
		}
	}
	break;

	case TV_TUNER_SILICONLABS_SI2178B:
	case TV_TUNER_SILICONLABS_SI2151:
	case TV_TUNER_NO_TUNER: {

		StructOuputLpfCoef stStructOuputLpfCoefNtsc[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_MN_FOR_SILICON2178B,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalBg[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_BG_SILICONLABS_SI2151_7D75,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalI[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_I_SILICONLABS_SI2151_7D75,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalDKL[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_DKL,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefSecam[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_DKL,},
		};

		for (k = 0; k < IFD_OUTPUT_LPF_TABLE_SIZE; k++) {
			stIFDUserData.VideoLpfNTSC[k] = stStructOuputLpfCoefNtsc[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_BG[k] = stStructOuputLpfCoefPalBg[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_I[k] = stStructOuputLpfCoefPalI[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_DKL[k] = stStructOuputLpfCoefPalDKL[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfSECAM[k] = stStructOuputLpfCoefSecam[0].StructOuputLpfCoef_Table[k];
		}
	}
	break;

	case TV_TUNER_MAXLINEAR_MXL661: {

		StructOuputLpfCoef stStructOuputLpfCoefNtsc[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_MN_SHARP,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalBg[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_BG_SHARP,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalI[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_I_SHARP,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefPalDKL[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_DKL_SHARP,},
		};
		StructOuputLpfCoef stStructOuputLpfCoefSecam[] = {
			{IFD_OUTPUTLPF_COEF_TABLE_DKL_SHARP,},
		};

		for (k = 0; k < IFD_OUTPUT_LPF_TABLE_SIZE; k++) {
			stIFDUserData.VideoLpfNTSC[k] = stStructOuputLpfCoefNtsc[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_BG[k] = stStructOuputLpfCoefPalBg[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_I[k] = stStructOuputLpfCoefPalI[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfPAL_DKL[k] = stStructOuputLpfCoefPalDKL[0].StructOuputLpfCoef_Table[k];
			stIFDUserData.VideoLpfSECAM[k] = stStructOuputLpfCoefSecam[0].StructOuputLpfCoef_Table[k];
		}
	}
	break;


	default:
		IFD_DEBUG_MSG(IFD_MSG_INFO, "[Realtek_ATV]  unkonw tuner id %d, can't load IFD Output LPF table\n", tuner_id);
		break;

	}
}

void drv_ifd_eq_init(unsigned short  tuner_id)
{

	//IFD_DEBUG_MSG(IFD_MSG_INIT, "\n[IFD] user data init \n");
	UINT8 k;

	switch (tuner_id) {

	case TV_TUNER_NXP_TDA18275A : {

		StructEQNotch stEqNotchNtsc[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_NTSC_0,},
		};
		StructEQNotch stEqNotchPalBG[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_PALBG_0,},
		};
		StructEQNotch stEqNotchPalI[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_PALI_0,},
		};
		StructEQNotch stEqNotchPalDK[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALDKL_0,},
		};
		StructEQNotch stEqNotchSecamL[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALDKL_0,},
		};
		StructEQNotch stEqNotchSecamLA[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALDKL_0,},
		};

		stIFDUserData.EQ_Table_NTSC_En = stEqNotchNtsc[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_BG_En = stEqNotchPalBG[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_I_En = stEqNotchPalI[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_DK_En = stEqNotchPalDK[0].EQNotch_En;
		stIFDUserData.EQ_Table_SECAM_L_En = stEqNotchSecamL[0].EQNotch_En;
		stIFDUserData.EQ_Table_SECAM_LA_En = stEqNotchSecamLA[0].EQNotch_En;
		for (k = 0; k < IFD_EQ_TABLE_SIZE; k++) {
			stIFDUserData.EQ_Table_NTSC[k] = stEqNotchNtsc[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_BG[k] = stEqNotchPalBG[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_I[k] = stEqNotchPalI[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_DK[k] = stEqNotchPalDK[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_SECAM_L[k] = stEqNotchSecamL[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_SECAM_LA[k] = stEqNotchSecamLA[0].EQNotch_Table[k];
		}
	}
	break;

	case TV_TUNER_SILICONLABS_SI2178B:
	case TV_TUNER_SILICONLABS_SI2151:
	case TV_TUNER_NO_TUNER: {

		StructEQNotch stEqNotchNtsc[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_NTSC_SI2178B_7D75_LG,},
		};
		StructEQNotch stEqNotchPalBG[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALBG_SI2151_7D75,},
		};
		StructEQNotch stEqNotchPalI[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALI_SI2151_7D75,},
		};
		StructEQNotch stEqNotchPalDK[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALDKL_SI2151_7D5,},
		};
		StructEQNotch stEqNotchSecamL[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALDKL_SI2151_7D5,},
		};
		StructEQNotch stEqNotchSecamLA[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_PALDKL_SI2151_7D5,},
		};

		stIFDUserData.EQ_Table_NTSC_En = stEqNotchNtsc[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_BG_En = stEqNotchPalBG[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_I_En = stEqNotchPalI[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_DK_En = stEqNotchPalDK[0].EQNotch_En;
		stIFDUserData.EQ_Table_SECAM_L_En = stEqNotchSecamL[0].EQNotch_En;
		stIFDUserData.EQ_Table_SECAM_LA_En = stEqNotchSecamLA[0].EQNotch_En;
		for (k = 0; k < IFD_EQ_TABLE_SIZE; k++) {
			stIFDUserData.EQ_Table_NTSC[k] = stEqNotchNtsc[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_BG[k] = stEqNotchPalBG[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_I[k] = stEqNotchPalI[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_DK[k] = stEqNotchPalDK[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_SECAM_L[k] = stEqNotchSecamL[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_SECAM_LA[k] = stEqNotchSecamLA[0].EQNotch_Table[k];
		}
	}
	break;

	case TV_TUNER_MAXLINEAR_MXL661: {

		StructEQNotch stEqNotchNtsc[] = {
			{IFD_ENABLE, IFD_EQ_TABLE_NTSC_MXL601,},
		};
		StructEQNotch stEqNotchPalBG[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_PALBG_MXL601,},
		};
		StructEQNotch stEqNotchPalI[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_PALI_MXL601,},
		};
		StructEQNotch stEqNotchPalDK[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_PALDKL_MXL601,},
		};
		StructEQNotch stEqNotchSecamL[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_PALDKL_MXL601,},
		};
		StructEQNotch stEqNotchSecamLA[] = {
			{IFD_DISABLE, IFD_EQ_TABLE_PALDKL_MXL601,},
		};

		stIFDUserData.EQ_Table_NTSC_En = stEqNotchNtsc[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_BG_En = stEqNotchPalBG[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_I_En = stEqNotchPalI[0].EQNotch_En;
		stIFDUserData.EQ_Table_PAL_DK_En = stEqNotchPalDK[0].EQNotch_En;
		stIFDUserData.EQ_Table_SECAM_L_En = stEqNotchSecamL[0].EQNotch_En;
		stIFDUserData.EQ_Table_SECAM_LA_En = stEqNotchSecamLA[0].EQNotch_En;
		for (k = 0; k < IFD_EQ_TABLE_SIZE; k++) {
			stIFDUserData.EQ_Table_NTSC[k] = stEqNotchNtsc[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_BG[k] = stEqNotchPalBG[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_I[k] = stEqNotchPalI[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_PAL_DK[k] = stEqNotchPalDK[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_SECAM_L[k] = stEqNotchSecamL[0].EQNotch_Table[k];
			stIFDUserData.EQ_Table_SECAM_LA[k] = stEqNotchSecamLA[0].EQNotch_Table[k];
		}
	}
	break;


	default:
		IFD_DEBUG_MSG(IFD_MSG_INFO, "[REALTEK_ATV]  unkonw tuner id %d, can't load EQ table\n", tuner_id);
		break;

	}


}


void drv_ifd_groupdelay_init(unsigned short  tuner_id)
{

	//IFD_DEBUG_MSG(IFD_MSG_INIT, "\n[IFD] user data init \n");
	UINT8 k;

	switch (tuner_id) {

	case TV_TUNER_NXP_TDA18275A : {

		StructGroupDelay stStructGroupDelayM[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_M,},
		};
		StructGroupDelay stStructGroupDelayN[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_N,},
		};
		StructGroupDelay stStructGroupDelayBG[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_BG_CURVE_B,},
		};
		StructGroupDelay stStructGroupDelayI[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_DK_CZECH,},
		};
		StructGroupDelay stStructGroupDelayDK[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_DK_CZECH,},
		};
		StructGroupDelay stStructGroupDelayL[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_DK_CZECH,},
		};
		StructGroupDelay stStructGroupDelayLA[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_DK_CZECH,},
		};

		stIFDUserData.GRPdelayM_En = stStructGroupDelayM[0].GroupDelay_En;
		stIFDUserData.GRPdelayN_En = stStructGroupDelayN[0].GroupDelay_En;
		stIFDUserData.GRPdelayBG_En = stStructGroupDelayBG[0].GroupDelay_En;
		stIFDUserData.GRPdelayI_En = stStructGroupDelayI[0].GroupDelay_En;
		stIFDUserData.GRPdelayDK_En = stStructGroupDelayDK[0].GroupDelay_En;
		stIFDUserData.GRPdelayL_En = stStructGroupDelayL[0].GroupDelay_En;
		stIFDUserData.GRPdelayLA_En = stStructGroupDelayLA[0].GroupDelay_En;
		for (k = 0; k < IFD_GP_BPF_TABLE_SIZE; k++) {
			stIFDUserData.GRPdelayTableM[k] = stStructGroupDelayM[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableN[k] = stStructGroupDelayN[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableBG[k] = stStructGroupDelayBG[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableI[k] = stStructGroupDelayI[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableDK[k] = stStructGroupDelayDK[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableL[k] = stStructGroupDelayL[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableLA[k] = stStructGroupDelayLA[0].GroupDelay_Table[k];

		}
	}
	break;

	case TV_TUNER_SILICONLABS_SI2178B:
	case TV_TUNER_SILICONLABS_SI2151:
	case TV_TUNER_NO_TUNER: {

		StructGroupDelay stStructGroupDelayM[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_M_SILICONLABS_SI2178B_7D75_LG},
		};
		StructGroupDelay stStructGroupDelayN[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_N,},
		};
		StructGroupDelay stStructGroupDelayBG[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_BG_SILICONLABS_SI2151_7D75},
		};
		StructGroupDelay stStructGroupDelayI[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_I_SILICONLABS_SI2178B,},
		};
		StructGroupDelay stStructGroupDelayDK[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_DK_FOR_SILICON2151_7D75,},
		};
		StructGroupDelay stStructGroupDelayL[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_DK_CZECH,},
		};
		StructGroupDelay stStructGroupDelayLA[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_DK_CZECH,},
		};

		stIFDUserData.GRPdelayM_En = stStructGroupDelayM[0].GroupDelay_En;
		stIFDUserData.GRPdelayN_En = stStructGroupDelayN[0].GroupDelay_En;
		stIFDUserData.GRPdelayBG_En = stStructGroupDelayBG[0].GroupDelay_En;
		stIFDUserData.GRPdelayI_En = stStructGroupDelayI[0].GroupDelay_En;
		stIFDUserData.GRPdelayDK_En = stStructGroupDelayDK[0].GroupDelay_En;
		stIFDUserData.GRPdelayL_En = stStructGroupDelayL[0].GroupDelay_En;
		stIFDUserData.GRPdelayLA_En = stStructGroupDelayLA[0].GroupDelay_En;
		for (k = 0; k < IFD_GP_BPF_TABLE_SIZE; k++) {
			stIFDUserData.GRPdelayTableM[k] = stStructGroupDelayM[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableN[k] = stStructGroupDelayN[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableBG[k] = stStructGroupDelayBG[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableI[k] = stStructGroupDelayI[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableDK[k] = stStructGroupDelayDK[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableL[k] = stStructGroupDelayL[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableLA[k] = stStructGroupDelayLA[0].GroupDelay_Table[k];

		}
	}
	break;

	case TV_TUNER_MAXLINEAR_MXL661: {

		StructGroupDelay stStructGroupDelayM[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_M},
		};
		StructGroupDelay stStructGroupDelayN[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_N,},
		};
		StructGroupDelay stStructGroupDelayBG[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_BG_CURVE_MXL601},
		};
		StructGroupDelay stStructGroupDelayI[] = {
			{IFD_DISABLE, IFD_GROUPDELAY_TABLE_DK_CZECH,},
		};
		StructGroupDelay stStructGroupDelayDK[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_DK_MXL601,},
		};
		StructGroupDelay stStructGroupDelayL[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_DK_MXL601,},
		};
		StructGroupDelay stStructGroupDelayLA[] = {
			{IFD_ENABLE, IFD_GROUPDELAY_TABLE_DK_MXL601,},
		};

		stIFDUserData.GRPdelayM_En = stStructGroupDelayM[0].GroupDelay_En;
		stIFDUserData.GRPdelayN_En = stStructGroupDelayN[0].GroupDelay_En;
		stIFDUserData.GRPdelayBG_En = stStructGroupDelayBG[0].GroupDelay_En;
		stIFDUserData.GRPdelayI_En = stStructGroupDelayI[0].GroupDelay_En;
		stIFDUserData.GRPdelayDK_En = stStructGroupDelayDK[0].GroupDelay_En;
		stIFDUserData.GRPdelayL_En = stStructGroupDelayL[0].GroupDelay_En;
		stIFDUserData.GRPdelayLA_En = stStructGroupDelayLA[0].GroupDelay_En;
		for (k = 0; k < IFD_GP_BPF_TABLE_SIZE; k++) {
			stIFDUserData.GRPdelayTableM[k] = stStructGroupDelayM[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableN[k] = stStructGroupDelayN[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableBG[k] = stStructGroupDelayBG[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableI[k] = stStructGroupDelayI[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableDK[k] = stStructGroupDelayDK[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableL[k] = stStructGroupDelayL[0].GroupDelay_Table[k];
			stIFDUserData.GRPdelayTableLA[k] = stStructGroupDelayLA[0].GroupDelay_Table[k];

		}
	}
	break;


	default:
		IFD_DEBUG_MSG(IFD_MSG_INFO, "[REALTEK_ATV]  unkonw tuner id %d, can't load group delay table\n", tuner_id);
		break;

	}


}


void drv_ifd_InputFilter_init(unsigned short  tuner_id)
{

	//IFD_DEBUG_MSG(IFD_MSG_INIT, "\n[IFD] user data init \n");
	UINT8 k;

	switch (tuner_id) {

	case TV_TUNER_NXP_TDA18275A : {

		StructInputFltCoef stStructInputBpfMNB[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_NULL,},
		};
		StructInputFltCoef stStructInputBpfDKL[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_NULL,},
		};
		StructInputFltCoef stStructInputBpfG[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_NULL,},
		};

		stIFDUserData.InputFltNtsc_En = stStructInputBpfMNB[0].InputFilter_En;
		stIFDUserData.InputFltPalD_En = stStructInputBpfDKL[0].InputFilter_En;
		stIFDUserData.InputFltPalG_En = stStructInputBpfG[0].InputFilter_En;
		for (k = 0; k < IFD_INPUT_FILTER_TABLE_SIZE; k++) {
			stIFDUserData.InputFltTableNtsc[k] = stStructInputBpfMNB[0].InputFilter_Table[k];
			stIFDUserData.InputFltTablePalD[k] = stStructInputBpfDKL[0].InputFilter_Table[k];
			stIFDUserData.InputFltTablePalG[k] = stStructInputBpfG[0].InputFilter_Table[k];
		}
	}
	break;

	case TV_TUNER_SILICONLABS_SI2178B:
	case TV_TUNER_SILICONLABS_SI2151:
	case TV_TUNER_NO_TUNER: {

		StructInputFltCoef stStructInputBpfMNB[] = {
			{IFD_ENABLE, IFD_INPUTFILTER_TABLE_MNB_7D75,},
		};
		StructInputFltCoef stStructInputBpfDKL[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_DKL,},
		};
		StructInputFltCoef stStructInputBpfG[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_G,},
		};

		stIFDUserData.InputFltNtsc_En = stStructInputBpfMNB[0].InputFilter_En;
		stIFDUserData.InputFltPalD_En = stStructInputBpfDKL[0].InputFilter_En;
		stIFDUserData.InputFltPalG_En = stStructInputBpfG[0].InputFilter_En;
		for (k = 0; k < IFD_INPUT_FILTER_TABLE_SIZE; k++) {
			stIFDUserData.InputFltTableNtsc[k] = stStructInputBpfMNB[0].InputFilter_Table[k];
			stIFDUserData.InputFltTablePalD[k] = stStructInputBpfDKL[0].InputFilter_Table[k];
			stIFDUserData.InputFltTablePalG[k] = stStructInputBpfG[0].InputFilter_Table[k];
		}
	}
	break;

	case TV_TUNER_MAXLINEAR_MXL661: {

		StructInputFltCoef stStructInputBpfMNB[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_NULL,},
		};
		StructInputFltCoef stStructInputBpfDKL[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_NULL,},
		};
		StructInputFltCoef stStructInputBpfG[] = {
			{IFD_DISABLE, IFD_INPUTFILTER_TABLE_NULL,},
		};

		stIFDUserData.InputFltNtsc_En = stStructInputBpfMNB[0].InputFilter_En;
		stIFDUserData.InputFltPalD_En = stStructInputBpfDKL[0].InputFilter_En;
		stIFDUserData.InputFltPalG_En = stStructInputBpfG[0].InputFilter_En;
		for (k = 0; k < IFD_INPUT_FILTER_TABLE_SIZE; k++) {
			stIFDUserData.InputFltTableNtsc[k] = stStructInputBpfMNB[0].InputFilter_Table[k];
			stIFDUserData.InputFltTablePalD[k] = stStructInputBpfDKL[0].InputFilter_Table[k];
			stIFDUserData.InputFltTablePalG[k] = stStructInputBpfG[0].InputFilter_Table[k];
		}
	}
	break;


	default:
		IFD_DEBUG_MSG(IFD_MSG_INFO, "[REALTEK_ATV]  unkonw tuner id %d, can't load IFD tuner table\n", tuner_id);
		break;

	}


}

//=================================================================
/**
 * drv_ifd_user_data_init
 *
 *
 * @param {void}
 * @return {void}
 */
void drv_ifd_user_data_init(unsigned short  tuner_id)
{

	//IFD_DEBUG_MSG(IFD_MSG_INIT, "\n[IFD] user data init \n");


	switch (tuner_id) {

	case TV_TUNER_NXP_TDA18275A : {

		drv_ifd_CrBpf_init(tuner_id);
		drv_ifd_OutputLpf_init(tuner_id);
		drv_ifd_eq_init(tuner_id);
		drv_ifd_groupdelay_init(tuner_id);
		drv_ifd_InputFilter_init(tuner_id);

		stIFDUserData.ifdMagicCode = IFD_FLASH_MAGIC_CODE;
		stIFDUserData.ifdAGCPGAMode = IFD_AGC_DOUBLE_IFAMP_FIXPGA;
		stIFDUserData.ifdAGCFixPGAValue = IFD_MODE_AGC_PGA_FIXGAIN_LEVEL_2P5DB;
		stIFDUserData.AFClockthd = 3;
		stIFDUserData.AFC_STAGE_MAX_COUNT = 15;
		stIFDUserData.SCANdelay = 80;
		stIFDUserData.SETCHANNELdelay = 0;
		stIFDUserData.CRPhaseInverseThr = 0;
		stIFDUserData.CRinverse_debounce = 16;
		stIFDUserData.CRSt3pgain = 0x1;
		stIFDUserData.CRSt3igain = 0x6;
		stIFDUserData.CRSt2pgain = 0x2;
		stIFDUserData.CRSt2igain = 0x7;
		stIFDUserData.CRSt0pgain = 0x5;
		stIFDUserData.CRSt0igain = 0x9;
		stIFDUserData.CRpgain = 0x2;
		stIFDUserData.CRigain = 0x7;
		stIFDUserData.CRlock_err_thd = 8;
		stIFDUserData.CRweight_speed = 0;
		stIFDUserData.CRphasebad_en = IFD_ENABLE;
		stIFDUserData.CRphasebad_en_st4 = IFD_DISABLE;
		stIFDUserData.CRphasebad_en_st2 = IFD_ENABLE;
		stIFDUserData.CRphasebad_en_st0 = IFD_ENABLE;
		stIFDUserData.CR_phase_var_st0_thr = 0x40;
		stIFDUserData.CR_freq_var_st0_thr = 0x1a;
		stIFDUserData.CR_phase_var_st2_thr = 0x40;
		stIFDUserData.CR_freq_var_vcheck_thr = 0x30;
		stIFDUserData.CR_freq_var_st2_up_thr = 0x50;
		stIFDUserData.CR_freq_var_st2_low_thr = 0x18;
		stIFDUserData.CR_freq_var_st4_thr = 0x40;
		stIFDUserData.CR_freq_var_st3_thr = 0x30;
		stIFDUserData.CR_weight_shift_st4_thr = 0x2;
		stIFDUserData.CR_weight_shift_st2_thr = 0x0;
		stIFDUserData.CR_weight_shift_st0_thr = 0x1;
		stIFDUserData.CR_st2_dn_update_sel = 0x0;
		stIFDUserData.CRvariance_thr = 0x52;
		stIFDUserData.CRInnerLpf_MN = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_BGH = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_IDKL = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_LA = IFD_CR_INNER_LPF_4ORDER;
		stIFDUserData.CRInnerLpf_SCAN = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRShift_en = IFD_ENABLE;
		stIFDUserData.CRShift_Target_Freq = IFD_IF_FREQ_16M;
		stIFDUserData.CRPower_Lock = IFD_ENABLE;
		stIFDUserData.CRPower_Lock_Thr = 0x2710; //10000 in decimal
		stIFDUserData.AGC_if_max = 0xf00; //IF_AGC = 1.5V
		stIFDUserData.AGC_if_min = 0x650; //0x70;//IF_AGC=0.65V
		stIFDUserData.AGCloop1_maxtargetNTSC = 0x300; //To match IF_AGC=0.65~1.5V Curve
		stIFDUserData.AGCloop1_maxtargetPAL = 0x300;
		stIFDUserData.AGCloop1_maxtargetSECAM = 0x300;
		stIFDUserData.AGCloop1_difftarget = 0x110;
		stIFDUserData.AGCloop1_peaktarget = 0x790;
		stIFDUserData.AGCloop1_peakforce_en = IFD_DISABLE;
		stIFDUserData.AGCloop1_kpgain = 0x12;
		stIFDUserData.AGCloop1_kigain = 0x7;
		stIFDUserData.AGCloop1_kpkishift = 0xb;
		stIFDUserData.AGCloop1_dnsample = 0x3;//TODO: need to confirm with DIC.//0x00;
		stIFDUserData.AGCloop1_finednsample = 0x000;
		stIFDUserData.AGCloop2_kpgain = 0x1;
		stIFDUserData.AGCloop2_kigain = 0x0;
		stIFDUserData.AGCloop2_kpshift = 0x3;
		stIFDUserData.AGCloop2_kishift = 0x7;
		stIFDUserData.AGCloop2_dnsample = 0x0F;
		stIFDUserData.AGCloop2_finednsample = 0x0FFF;
		stIFDUserData.AGC_RfHasten_en = IFD_DISABLE;
		stIFDUserData.AGC_RfHasten_ki = 0x6;
		stIFDUserData.AGC_RfHasten_cntl = 0x1;
		stIFDUserData.AGC_RfHasten_thr = 0x5c0;
		stIFDUserData.AGC_SepRfIf_en = IFD_DISABLE;
		stIFDUserData.AGC_SepRfIf_IfKp = 0x0;
		stIFDUserData.AGC_SepRfIf_IfKi = 0x3;
		stIFDUserData.AGCadapt_fineinterval = 0x7f;
		stIFDUserData.AGCadapt_interval = 0xf;
		stIFDUserData.AGCadapt_en = IFD_ENABLE;
		stIFDUserData.AGCadapt_incthr = 0x100; //To match IF_AGC=0.65~1.5V Curve
		stIFDUserData.AGCadapt_mindifftarget = 0x10;
		stIFDUserData.AGCadapt_minmaxtarget = 0x40;
		stIFDUserData.AGCadapt_finetargetthr = 0x70;
		stIFDUserData.AGCadapt_diffcoarsestep = 0x8;
		stIFDUserData.AGCSigmaDeltaDnSel = 0x4;
		stIFDUserData.AGCDataTarg = 0x300;
		stIFDUserData.DataGainSel = IFD_VIDEOPATH_OUTPUT_GAIN_ADAPTIVE;
		stIFDUserData.CLAMPscale_scanch = IFD_CLAMP_SCALE_1D4;
		stIFDUserData.CLAMPscale_setch = IFD_CLAMP_SCALE_1D64;
		stIFDUserData.SHAPEfilter_bw = IFD_SHAPING_BW_SEL_0P86M;
		stIFDUserData.VideoUpsampleLPF_NTSC = IFD_UPSAMPLE_LP_SEL_NTSC;
		stIFDUserData.VideoUpsampleLPF_PAL = IFD_UPSAMPLE_LP_SEL_PAL;
		stIFDUserData.ADCInput_ShaGain = IFD_ADC_SHAGAIN_0P6X;
		stIFDUserData.ADCInput_FullScale = IFD_ADC_FULLSCALE_1P40V;
		stIFDUserData.ADCInput_clock = IFD_CLK_RATE_162M;
		stIFDUserData.ADCinput_dn_filter_sel = IFD_INPUT_DN_FILTER_162M_LPF;
		stIFDUserData.AFC_Max_Freq = 4;

		stIFDUserData.tunerPara.tunerI2C_ADD = 0xc0; // tuner i2c device address
		stIFDUserData.tunerPara.tunerMinFreq = 452500;
		stIFDUserData.tunerPara.tunerMaxFreq = 8660000;
		stIFDUserData.tunerPara.tunerPIF = 54000;
		stIFDUserData.tunerPara.tunerPIF_MN = IFD_IF_FREQ_5P4M;
		stIFDUserData.tunerPara.tunerPIF_B = IFD_IF_FREQ_6P25M;
		stIFDUserData.tunerPara.tunerPIF_GH = IFD_IF_FREQ_6P75M;
		stIFDUserData.tunerPara.tunerPIF_I = IFD_IF_FREQ_7M;
		stIFDUserData.tunerPara.tunerPIF_DK = IFD_IF_FREQ_6P85M;
		stIFDUserData.tunerPara.tunerPIF_L = IFD_IF_FREQ_6P75M;
		stIFDUserData.tunerPara.tunerPIF_LA = IFD_IF_FREQ_1P25M;
		stIFDUserData.tunerPara.tunerPIF_SCAN = IFD_IF_FREQ_6P85M;
		stIFDUserData.tunerPara.tunerIFType = TUNER_IF_TYPE_NEG;
		stIFDUserData.tunerPara.tunerRATIOStepSize = 625;

		stIFDUserData.tunerPara.tunerUsedTag = _FALSE;
		stIFDUserData.tunerPara.tunerAGCtype = TUNER_RFAGC_IC_IFAGC;
		stIFDUserData.tunerPara.tunerAGCpolarity = TUNER_RF_NONE_IF_POS;
		stIFDUserData.tunerPara.tunerType = TUNER_LOW_IF;
		stIFDUserData.tunerPara.tunerSpecificTag = 0;
		stIFDUserData.tunerPara.tunerID = TUNER_NXP_TDA18275A;

	}
	break;

	case TV_TUNER_SILICONLABS_SI2178B:
	case TV_TUNER_SILICONLABS_SI2151:
	case TV_TUNER_NO_TUNER: {

		drv_ifd_CrBpf_init(tuner_id);
		drv_ifd_OutputLpf_init(tuner_id);
		drv_ifd_eq_init(tuner_id);
		drv_ifd_groupdelay_init(tuner_id);
		drv_ifd_InputFilter_init(tuner_id);

		stIFDUserData.ifdMagicCode = IFD_FLASH_MAGIC_CODE;
		stIFDUserData.ifdAGCPGAMode = IFD_AGC_DOUBLE_IFAMP_FIXPGA;
		stIFDUserData.ifdAGCFixPGAValue = IFD_MODE_AGC_PGA_FIXGAIN_LEVEL_2P5DB;
		stIFDUserData.AFClockthd = 3;
		stIFDUserData.AFC_STAGE_MAX_COUNT = 15;
		stIFDUserData.SCANdelay = 100;
		stIFDUserData.SETCHANNELdelay = 100;
		stIFDUserData.CRPhaseInverseThr = 0;
		stIFDUserData.CRinverse_debounce = 16;
		stIFDUserData.CRSt3pgain = 0x1;
		stIFDUserData.CRSt3igain = 0x6;
		stIFDUserData.CRSt2pgain = 0x2;
		stIFDUserData.CRSt2igain = 0x7;
		stIFDUserData.CRSt0pgain = 0x5;
		stIFDUserData.CRSt0igain = 0xb;
		stIFDUserData.CRpgain = 0x2;
		stIFDUserData.CRigain = 0x7;
		stIFDUserData.CRlock_err_thd = 0x18;
		stIFDUserData.CRweight_speed = 0;
		stIFDUserData.CRphasebad_en = IFD_DISABLE;
		stIFDUserData.CRphasebad_en_st4 = IFD_DISABLE;
		stIFDUserData.CRphasebad_en_st2 = IFD_ENABLE;
		stIFDUserData.CRphasebad_en_st0 = IFD_ENABLE;
		stIFDUserData.CR_phase_var_st0_thr = 0x28;
		stIFDUserData.CR_freq_var_st0_thr = 0x1a;
		stIFDUserData.CR_phase_var_st2_thr = 0x30;
		stIFDUserData.CR_freq_var_vcheck_thr = 0x30;
		stIFDUserData.CR_freq_var_st2_up_thr = 0x50;
		stIFDUserData.CR_freq_var_st2_low_thr = 0x10;
		stIFDUserData.CR_freq_var_st4_thr = 0x30;
		stIFDUserData.CR_freq_var_st3_thr = 0x30;
		stIFDUserData.CR_weight_shift_st4_thr = 0x2;
		stIFDUserData.CR_weight_shift_st2_thr = 0x2;//WOSLQEVENT-69564//0x0;
		stIFDUserData.CR_weight_shift_st0_thr = 0x1;
		stIFDUserData.CR_st2_dn_update_sel = 0x0;
		stIFDUserData.CRvariance_thr = 0x52;
		stIFDUserData.CRInnerLpf_MN = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_BGH = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_IDKL = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_LA = IFD_CR_INNER_LPF_4ORDER;
		stIFDUserData.CRInnerLpf_SCAN = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRShift_en = IFD_ENABLE;
		stIFDUserData.CRShift_Target_Freq = IFD_IF_FREQ_16M;
		stIFDUserData.CRPower_Lock = IFD_ENABLE;
		stIFDUserData.CRPower_Lock_Thr = 0x2710; //10000 in decimal
		stIFDUserData.AGC_if_max = 0x1400; //IF_AGC = 2.0V
		stIFDUserData.AGC_if_min = 0x480; //IF_AGC=0.5V
		stIFDUserData.AGCloop1_maxtargetNTSC = 0x300;
		stIFDUserData.AGCloop1_maxtargetPAL = 0x300;
		stIFDUserData.AGCloop1_maxtargetSECAM = 0x300;
		stIFDUserData.AGCloop1_difftarget = 0x110;
		stIFDUserData.AGCloop1_peaktarget = 0x790;
		stIFDUserData.AGCloop1_peakforce_en = IFD_ENABLE;
		stIFDUserData.AGCloop1_kpgain = 0x12;
		stIFDUserData.AGCloop1_kigain = 0x7;
		stIFDUserData.AGCloop1_kpkishift = 0xb;
		stIFDUserData.AGCloop1_dnsample = 0x3;//TODO: need to confirm with DIC.//0x00;
		stIFDUserData.AGCloop1_finednsample = 0x000;
		stIFDUserData.AGCloop2_kpgain = 0x1;
		stIFDUserData.AGCloop2_kigain = 0x0;
		stIFDUserData.AGCloop2_kpshift = 0x3;
		stIFDUserData.AGCloop2_kishift = 0x7;
		stIFDUserData.AGCloop2_dnsample = 0x0F;
		stIFDUserData.AGCloop2_finednsample = 0x0FFF;
		stIFDUserData.AGC_RfHasten_en = IFD_DISABLE;
		stIFDUserData.AGC_RfHasten_ki = 0x6;
		stIFDUserData.AGC_RfHasten_cntl = 0x1;
		stIFDUserData.AGC_RfHasten_thr = 0x5c0;
		stIFDUserData.AGC_SepRfIf_en = IFD_DISABLE;
		stIFDUserData.AGC_SepRfIf_IfKp = 0x0;
		stIFDUserData.AGC_SepRfIf_IfKi = 0x3;
		stIFDUserData.AGCadapt_fineinterval = 0x7f;
		stIFDUserData.AGCadapt_interval = 0xf;
		stIFDUserData.AGCadapt_en = IFD_ENABLE;
		stIFDUserData.AGCadapt_incthr = 0x100; //To match IF_AGC=0.65~1.5V Curve
		stIFDUserData.AGCadapt_mindifftarget = 0x10;
		stIFDUserData.AGCadapt_minmaxtarget = 0x40;
		stIFDUserData.AGCadapt_finetargetthr = 0x70;
		stIFDUserData.AGCadapt_diffcoarsestep = 0x8;
		stIFDUserData.AGCSigmaDeltaDnSel = 0x4;
		stIFDUserData.AGCDataTarg = 0x400;
		stIFDUserData.DataGainSel = IFD_VIDEOPATH_OUTPUT_GAIN_ADAPTIVE;
		stIFDUserData.CLAMPscale_scanch = IFD_CLAMP_SCALE_1D4;
		stIFDUserData.CLAMPscale_setch = IFD_CLAMP_SCALE_1D64;
		stIFDUserData.SHAPEfilter_bw = IFD_SHAPING_BW_SEL_0P86M;
		stIFDUserData.VideoUpsampleLPF_NTSC = IFD_UPSAMPLE_LP_SEL_NTSC;
		stIFDUserData.VideoUpsampleLPF_PAL = IFD_UPSAMPLE_LP_SEL_NTSC;
		stIFDUserData.ADCInput_ShaGain = IFD_ADC_SHAGAIN_1P0X;
		stIFDUserData.ADCInput_FullScale = IFD_ADC_FULLSCALE_1P40V;
		stIFDUserData.ADCInput_clock = IFD_CLK_RATE_162M;
		stIFDUserData.ADCinput_dn_filter_sel = IFD_INPUT_DN_FILTER_162M_LPF;
		stIFDUserData.AFC_Max_Freq = 1;

		stIFDUserData.tunerPara.tunerI2C_ADD = 0xc6; // tuner i2c device address
		stIFDUserData.tunerPara.tunerMinFreq = 452500;
		stIFDUserData.tunerPara.tunerMaxFreq = 8632500;
		stIFDUserData.tunerPara.tunerPIF = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_MN = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_B = IFD_IF_FREQ_7P25M;
		stIFDUserData.tunerPara.tunerPIF_GH = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_I = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_DK = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_L = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_LA = IFD_IF_FREQ_2P75M;
		stIFDUserData.tunerPara.tunerPIF_SCAN = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerIFType = TUNER_IF_TYPE_NEG;
		stIFDUserData.tunerPara.tunerRATIOStepSize = 500;

		stIFDUserData.tunerPara.tunerUsedTag = _FALSE;
		stIFDUserData.tunerPara.tunerAGCtype = TUNER_RFAGC_IC_IFAGC;
		stIFDUserData.tunerPara.tunerAGCpolarity = TUNER_RF_NONE_IF_POS;
		stIFDUserData.tunerPara.tunerType = TUNER_LOW_IF;
		stIFDUserData.tunerPara.tunerSpecificTag = 0;
		if (TV_TUNER_SILICONLABS_SI2178B) stIFDUserData.tunerPara.tunerID = TUNER_SILICONLABS_SI2178B;
		else if (TV_TUNER_SILICONLABS_SI2151) stIFDUserData.tunerPara.tunerID = TUNER_SILICONLABS_SI2151;
		else stIFDUserData.tunerPara.tunerID = TV_TUNER_NO_TUNER;

	}
	break;

	case TV_TUNER_MAXLINEAR_MXL661: {

		drv_ifd_CrBpf_init(tuner_id);
		drv_ifd_OutputLpf_init(tuner_id);
		drv_ifd_eq_init(tuner_id);
		drv_ifd_groupdelay_init(tuner_id);
		drv_ifd_InputFilter_init(tuner_id);

		stIFDUserData.ifdMagicCode = IFD_FLASH_MAGIC_CODE;
		stIFDUserData.ifdAGCPGAMode = IFD_AGC_DOUBLE_IFAMP_FIXPGA;
		stIFDUserData.ifdAGCFixPGAValue = IFD_MODE_AGC_PGA_FIXGAIN_LEVEL_2P5DB;
		stIFDUserData.AFClockthd = 3;
		stIFDUserData.AFC_STAGE_MAX_COUNT = 15;
		stIFDUserData.SCANdelay = 100;
		stIFDUserData.SETCHANNELdelay = 0;
		stIFDUserData.CRPhaseInverseThr = 0;
		stIFDUserData.CRinverse_debounce = 16;
		stIFDUserData.CRSt3pgain = 0x1;
		stIFDUserData.CRSt3igain = 0x6;
		stIFDUserData.CRSt2pgain = 0x2;
		stIFDUserData.CRSt2igain = 0x7;
		stIFDUserData.CRSt0pgain = 0x5;
		stIFDUserData.CRSt0igain = 0x9;
		stIFDUserData.CRpgain = 0x2;
		stIFDUserData.CRigain = 0x7;
		stIFDUserData.CRlock_err_thd = 8;
		stIFDUserData.CRweight_speed = 0;
		stIFDUserData.CRphasebad_en = IFD_DISABLE;
		stIFDUserData.CRphasebad_en_st4 = IFD_DISABLE;
		stIFDUserData.CRphasebad_en_st2 = IFD_ENABLE;
		stIFDUserData.CRphasebad_en_st0 = IFD_DISABLE;
		stIFDUserData.CR_phase_var_st0_thr = 0x20;
		stIFDUserData.CR_freq_var_st0_thr = 0x1a;
		stIFDUserData.CR_phase_var_st2_thr = 0x20;
		stIFDUserData.CR_freq_var_vcheck_thr = 0x30;
		stIFDUserData.CR_freq_var_st2_up_thr = 0x50;
		stIFDUserData.CR_freq_var_st2_low_thr = 0x12;
		stIFDUserData.CR_freq_var_st4_thr = 0x40;
		stIFDUserData.CR_freq_var_st3_thr = 0x28;
		stIFDUserData.CR_weight_shift_st4_thr = 0x2;
		stIFDUserData.CR_weight_shift_st2_thr = 0x0;
		stIFDUserData.CR_weight_shift_st0_thr = 0x1;
		stIFDUserData.CR_st2_dn_update_sel = 0x0;
		stIFDUserData.CRvariance_thr = 0x52;
		stIFDUserData.CRInnerLpf_MN = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_BGH = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_IDKL = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_LA = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRInnerLpf_SCAN = IFD_CR_INNER_LPF_6ORDER;
		stIFDUserData.CRShift_en = IFD_ENABLE;
		stIFDUserData.CRShift_Target_Freq = IFD_IF_FREQ_16M;
		stIFDUserData.CRPower_Lock = IFD_ENABLE;
		stIFDUserData.CRPower_Lock_Thr = 0x2710; //10000 in decimal
		stIFDUserData.AGC_if_max = 0x1d52; //IF_AGC = 2.5V
		stIFDUserData.AGC_if_min = 0x580; ;//IF_AGC=0.5V
		stIFDUserData.AGCloop1_maxtargetNTSC = 0x300; //To match IF_AGC=0.65~1.5V Curve
		stIFDUserData.AGCloop1_maxtargetPAL = 0x300;
		stIFDUserData.AGCloop1_maxtargetSECAM = 0x300;
		stIFDUserData.AGCloop1_difftarget = 0x110;
		stIFDUserData.AGCloop1_peaktarget = 0x790;
		stIFDUserData.AGCloop1_peakforce_en = IFD_ENABLE;
		stIFDUserData.AGCloop1_kpgain = 0x12;
		stIFDUserData.AGCloop1_kigain = 0x7;
		stIFDUserData.AGCloop1_kpkishift = 0xb;
		stIFDUserData.AGCloop1_dnsample = 0xf;
		stIFDUserData.AGCloop1_finednsample = 0x000;
		stIFDUserData.AGCloop2_kpgain = 0x1;
		stIFDUserData.AGCloop2_kigain = 0x0;
		stIFDUserData.AGCloop2_kpshift = 0x3;
		stIFDUserData.AGCloop2_kishift = 0x9;
		stIFDUserData.AGCloop2_dnsample = 0x0F;
		stIFDUserData.AGCloop2_finednsample = 0x0FFF;
		stIFDUserData.AGC_RfHasten_en = IFD_DISABLE;
		stIFDUserData.AGC_RfHasten_ki = 0x6;
		stIFDUserData.AGC_RfHasten_cntl = 0x1;
		stIFDUserData.AGC_RfHasten_thr = 0x5c0;
		stIFDUserData.AGC_SepRfIf_en = IFD_DISABLE;
		stIFDUserData.AGC_SepRfIf_IfKp = 0x0;
		stIFDUserData.AGC_SepRfIf_IfKi = 0x3;
		stIFDUserData.AGCadapt_fineinterval = 0x7f;
		stIFDUserData.AGCadapt_interval = 0xf;
		stIFDUserData.AGCadapt_en = IFD_ENABLE;
		stIFDUserData.AGCadapt_incthr = 0x20;
		stIFDUserData.AGCadapt_mindifftarget = 0x10;
		stIFDUserData.AGCadapt_minmaxtarget = 0x40;
		stIFDUserData.AGCadapt_finetargetthr = 0x70;
		stIFDUserData.AGCadapt_diffcoarsestep = 0x8;
		stIFDUserData.AGCSigmaDeltaDnSel = 0x4;
		stIFDUserData.AGCDataTarg = 0x400;
		stIFDUserData.DataGainSel = IFD_VIDEOPATH_OUTPUT_GAIN_ADAPTIVE;
		stIFDUserData.CLAMPscale_scanch = IFD_CLAMP_SCALE_1D4;
		stIFDUserData.CLAMPscale_setch = IFD_CLAMP_SCALE_1D2;
		stIFDUserData.SHAPEfilter_bw = IFD_SHAPING_BW_SEL_0P86M;
		stIFDUserData.VideoUpsampleLPF_NTSC = IFD_UPSAMPLE_LP_SEL_NTSC;
		stIFDUserData.VideoUpsampleLPF_PAL = IFD_UPSAMPLE_LP_SEL_PAL;
		stIFDUserData.ADCInput_ShaGain = IFD_ADC_SHAGAIN_1P0X;
		stIFDUserData.ADCInput_FullScale = IFD_ADC_FULLSCALE_1P40V;
		stIFDUserData.ADCInput_clock = IFD_CLK_RATE_162M;
		stIFDUserData.ADCinput_dn_filter_sel = IFD_INPUT_DN_FILTER_162M_LPF;
		stIFDUserData.AFC_Max_Freq = 2;

		stIFDUserData.tunerPara.tunerI2C_ADD = 0xc0; // tuner i2c device address
		stIFDUserData.tunerPara.tunerMinFreq = 452500;
		stIFDUserData.tunerPara.tunerMaxFreq = 8660000;
		stIFDUserData.tunerPara.tunerPIF = IFD_IF_FREQ_6P75M;
		stIFDUserData.tunerPara.tunerPIF_MN = IFD_IF_FREQ_6P75M;
		stIFDUserData.tunerPara.tunerPIF_B = IFD_IF_FREQ_7P25M;
		stIFDUserData.tunerPara.tunerPIF_GH = IFD_IF_FREQ_7P25M;
		stIFDUserData.tunerPara.tunerPIF_I = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_DK = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_L = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerPIF_LA = IFD_IF_FREQ_2P25M;
		stIFDUserData.tunerPara.tunerPIF_SCAN = IFD_IF_FREQ_7P75M;
		stIFDUserData.tunerPara.tunerIFType = TUNER_IF_TYPE_NEG;
		stIFDUserData.tunerPara.tunerRATIOStepSize = 500;

		stIFDUserData.tunerPara.tunerUsedTag = _FALSE;
		stIFDUserData.tunerPara.tunerAGCtype = TUNER_RFAGC_IC_IFAGC;
		stIFDUserData.tunerPara.tunerAGCpolarity = TUNER_RF_NONE_IF_POS;
		stIFDUserData.tunerPara.tunerType = TUNER_LOW_IF;
		stIFDUserData.tunerPara.tunerSpecificTag = 0;
		stIFDUserData.tunerPara.tunerID = TUNER_MAXLINEAR_MXL661;

		}
		break;


	default:
		IFD_DEBUG_MSG(IFD_MSG_INFO, "[REALTEK_ATV]  unkonw tuner id %d, can't load IFD tuner table\n", tuner_id);
		break;

	}


}



