#include "memc_isr/PQL/PQLPlatformDefs.h"
#include "memc_isr/PQL/FRC_glb_Context.h"

// cadence table.
FRC_CADENCE  frc_cadTable[_FRC_CADENCE_NUM_]=
{
	//0: video
	{ 0x01, 0x01,   1,  1, 0,  0x1,   1, 0, _CAD_VIDEO, 0},

	//1: 22
	{ 0xA,  0x03,   1,  2, 0,  0xf,   4, 0, _CAD_22,    0},

	//2: 32
	{ 0x12, 0x1B,   2,  5, 0,  0x1f,  5, 0, _CAD_32,    0},

	//3: 32322
	{ 0x94A, 0xFEF, 5, 12, 0, 0xfff, 12,  0, _CAD_32322, 0},

	//4: 334
	{ 0x248, 0x3FF, 3, 10, 0, 0x3ff, 10,  0, _CAD_334,   0},

	//5: 22224
	{ 0xAA8, 0xFFF, 5, 12, 0, 0xfff, 12,  0, _CAD_22224, 0},

	//6: 2224
	{ 0x2A8, 0x3FF, 4, 10, 0, 0x3ff, 10,  0, _CAD_2224,  0},

	//7: 3223
	{ 0x254, 0x3FF, 4, 10, 0, 0x3ff, 10,  0, _CAD_3223,  0},

	//8: 55
	{ 0x210,  0x1F, 1,  5, 0, 0x3ff, 10,  0, _CAD_55,    1},

	//9: 66
	{ 0x820,  0x3F, 1,  6, 0, 0xfff, 12,  0, _CAD_66,    1},

	//0xA: 44
	{ 0x88,   0x0F, 1,  4, 0,  0xff,  8,  0, _CAD_44,    1},

	//0xB: 1112
	{ 0x1E,   0x1F, 4,  5, 0,  0x1f,  5,  0, _CAD_1112,  0},

	//0xC: 11112
	{ 0x3E,   0x3F, 5,  6, 0,  0x3f,  6,  0, _CAD_11112, 0},

	//0xD: 122
	{ 0x1A,   0x1F, 3,  5, 0,  0x1f,  5,  0, _CAD_122,   0},

	//0xE: 11'23
	{ 0x1555554, 0x1FFFFFF, 12, 25, 0, 0x1ffffff,  25,  0, _CAD_11i23, 0},

};

void cadence_copy_change(FRC_CADENCE_ID cpy_cadId, UBYTE isLR, FRC_CADENCE *pOut_cadInfo)
{
	pOut_cadInfo->cad_id         = frc_cadTable[cpy_cadId].cad_id;
	pOut_cadInfo->cad_inLen      = frc_cadTable[cpy_cadId].cad_inLen;
	pOut_cadInfo->cad_seq        = frc_cadTable[cpy_cadId].cad_seq ;
	pOut_cadInfo->cad_usableFlag = frc_cadTable[cpy_cadId].cad_usableFlag;

	pOut_cadInfo->cad_outLen     = (isLR == 0)? frc_cadTable[cpy_cadId].cad_outLen : frc_cadTable[cpy_cadId].cad_outLen * 2;
	pOut_cadInfo->cad_isLRin     = (isLR == 0)? 0 : 1;
}

UBYTE cadence_seqFlag(FRC_CADENCE cadInfo, UBYTE filmPh)
{
	UBYTE ret_seqFlag = 0;
	if (cadInfo.cad_isLRin == 0)
	{
		ret_seqFlag = ((cadInfo.cad_seq >> (cadInfo.cad_outLen - 1 - filmPh))& 1);
	}
	else
	{
		ret_seqFlag = ((filmPh & 0x01) == 1)? 0 : ((cadInfo.cad_seq >> ((cadInfo.cad_outLen>>1) - 1 - (filmPh >> 1)))& 1);
	}
	return ret_seqFlag;
}
UBYTE cadence_usableFlag(FRC_CADENCE cadInfo, UBYTE filmPh)
{
	UBYTE ret_usableFlag = 0;
	if (cadInfo.cad_isLRin == 0)
	{
		ret_usableFlag = ((cadInfo.cad_usableFlag >> (cadInfo.cad_outLen - 1 - filmPh))& 1);
	}
	else
	{
		ret_usableFlag = ((cadInfo.cad_usableFlag >> ((cadInfo.cad_outLen>>1) - 1 - (filmPh>>1)))& 1);
	}

	return ret_usableFlag;
}
UBYTE cadence_prePhase(FRC_CADENCE cadInfo, UBYTE filmPh, UBYTE k)
{
	UBYTE ret_prePh = 0;
	if (cadInfo.cad_isLRin == 0)
	{
		ret_prePh = (((filmPh - k) <  0)? (filmPh - k + cadInfo.cad_outLen) : (filmPh - k));
	}
	else
	{
		ret_prePh = (((filmPh - 2*k) <  0)? (filmPh - 2*k + cadInfo.cad_outLen) : (filmPh - 2*k));
	}

	return ret_prePh;
}
UBYTE cadence_nxtPhase(FRC_CADENCE cadInfo, UBYTE filmPh, UBYTE k)
{
	UBYTE ret_nxtPh = 0;
	if (cadInfo.cad_isLRin == 0)
	{
		ret_nxtPh = (((filmPh + k) >= cadInfo.cad_outLen )? (filmPh + k - cadInfo.cad_outLen) : (filmPh + k));
	}
	else
	{
		ret_nxtPh = (((filmPh + 2*k) >= cadInfo.cad_outLen )? (filmPh + 2*k - cadInfo.cad_outLen) : (filmPh + 2*k));
	}

	return ret_nxtPh;
}


