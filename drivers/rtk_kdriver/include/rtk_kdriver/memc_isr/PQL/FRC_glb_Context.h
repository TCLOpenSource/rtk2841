#ifndef _FRC_GLB_CONTEXT_DEF_H
#define _FRC_GLB_CONTEXT_DEF_H

typedef enum{
	_CAD_VIDEO,        //0
	_CAD_22,           //1
	_CAD_32,           //2
	_CAD_32322,        //3
	_CAD_334,          //4
	_CAD_22224,        //5
	_CAD_2224,         //6
	_CAD_3223,         //7
	_CAD_55,           //8
	_CAD_66,           //9
	_CAD_44,           //0xA
	_CAD_1112,         //0xB
	_CAD_11112,        //0xC
	_CAD_122,          //0xD
	_CAD_11i23,        //0xE
	_FRC_CADENCE_NUM_,
}FRC_CADENCE_ID;

typedef struct
{
	UINT32 cad_seq;
	UINT32 cad_usableFlag;
	UBYTE  cad_inLen;
	UBYTE  cad_outLen;
	UBYTE  cad_isLRin;

	UINT32 cad_check;
	UBYTE  cad_len;
	UBYTE  cad_film_resync_phId;

	UBYTE  cad_id;
	UBYTE  u1_isLowFrameRate;
	
} FRC_CADENCE;

extern FRC_CADENCE  frc_cadTable[_FRC_CADENCE_NUM_];

// void  cadenceTable_int();

void  cadence_copy_change(FRC_CADENCE_ID cpy_cadId, UBYTE isLR, FRC_CADENCE *pOut_cadInfo);
UBYTE cadence_seqFlag(FRC_CADENCE cadInfo, UBYTE filmPh);
UBYTE cadence_usableFlag(FRC_CADENCE cadInfo, UBYTE filmPh);
UBYTE cadence_prePhase(FRC_CADENCE cadInfo, UBYTE filmPh, UBYTE k);
UBYTE cadence_nxtPhase(FRC_CADENCE cadInfo, UBYTE filmPh, UBYTE k);

#endif

