#ifndef __VIP_TABLE_H__
#define __VIP_TABLE_H__

#include <tvscalercontrol/scaler/vipinclude.h>

/*------------------------------------------------------------------------------*/
/*										*/
/*	class VipTable								*/
/*	 - each VIP_SOURCE_OPTION_TYPE source has one table, this should be customized	*/
/*	 - save as binary files under /user/local/etc/dvdplayer/vipTable			*/
/*										*/
/*	usage:									*/
/*		VipTable::GetInstance()->Init()  //to load table and register tables/callbacks */
/*------------------------------------------------------------------------------*/

typedef struct _PIC_MODE_DATA {
	SLR_PICTURE_MODE_DATA picMode[PICTURE_MODE_MAX];
} PIC_MODE_DATA;

typedef struct _COLOR_TEMP_DATA {
	SLR_COLORTEMP_DATA colorTempData[SLR_COLORTEMP_MAX_NUM];
} COLOR_TEMP_DATA;

typedef enum _SourceOption {
	SOURCE_OSD = 0,
	SOURCE_ATV1,
	SOURCE_ATV2,
	SOURCE_DTV1,
	SOURCE_DTV2,
	SOURCE_AV1,
	SOURCE_AV2,
	SOURCE_AV3,	/*(Gilbert)TSB: 3 AV inputs*/
	SOURCE_SV1,
	SOURCE_SV2,
	SOURCE_YPP1,	/*10*/
	SOURCE_YPP2,
	SOURCE_YPP3,
	SOURCE_YPP4,
	SOURCE_VGA1,
	SOURCE_VGA2,
	SOURCE_HDMI1,
	SOURCE_HDMI2,
	SOURCE_HDMI3,
	SOURCE_HDMI4,
	SOURCE_HDMI5,	/*20*/
	SOURCE_HDMI6,
	SOURCE_SCART1,
	SOURCE_SCART2,
	SOURCE_PLAYBACK,
	SOURCE_MIC,
	/* Virtual Sources.*/
	SOURCE_AUTO, /*SOURCE_AUTO is not an actual source, it is only used for boot up source in setup menu*/
	SOURCE_IDTV1, /*30, This is a conceptual source.*/
	SOURCE_BROWSER, /* This is a fake source.*/
	SOURCE_NULL,
/* by Jackie, Move to Bottom for Android TvServer Use*/
	SOURCE_HDMI1_DVI,
	SOURCE_HDMI2_DVI,
	SOURCE_HDMI3_DVI,
/* by Jackie, Move to Bottom for Android TvServer Use*/
	SOURCE_MAX_NUM
} SourceOption;

typedef enum _VIP_SOURCE_OPTION_TYPE {
	VIP_SOURCE_TYPE_ATV = 0,
	VIP_SOURCE_TYPE_AV,
	VIP_SOURCE_TYPE_SV,
	VIP_SOURCE_TYPE_YPP,
	VIP_SOURCE_TYPE_SCART,
	VIP_SOURCE_TYPE_DTV,
	VIP_SOURCE_TYPE_HDMI,
	VIP_SOURCE_TYPE_HDMI2,
	VIP_SOURCE_TYPE_HDMI3,
	VIP_SOURCE_TYPE_VGA,
	VIP_SOURCE_TYPE_IDTV,
	VIP_SOURCE_TYPE_PLAYBACK,
	VIP_SOURCE_TYPE_MAX_NUM,
} VIP_SOURCE_OPTION_TYPE;


typedef struct _SOURCE_TIMING_INFO {
	/*VIP_SOURCE_OPTION_TYPE 		source;*/
	int 		source;
	VIP_TABLE_TIMIMG_ENUM		timing;
	VIP_TABLE_COLORSTD_ENUM		color;
} SOURCE_TIMING_INFO;


typedef enum _VIP_TABLE_SAVE_ENUM {
	VIP_TABLE_SAVE_PICMODE = 0x1,
	VIP_TABLE_SAVE_COLORTEMP = 0x2,
	VIP_TABLE_SAVE_COLORFAC = 0x4,
	VIP_TABLE_SAVE_ALL = 0x7,
} VIP_TABLE_SAVE_ENUM;

typedef enum _VIP_TABLE_INDEX_TYPE {
	VIP_TABLE_INDEX_BY_SOURCE_TYPE = 0,
	VIP_TABLE_INDEX_BY_SOURCE,
} VIP_TABLE_INDEX_TYPE;


typedef enum _VIP_TABLE_TYPE {
	VIP_TABLE_PICMODE = 0,
	VIP_TABLE_COLORDATA,
	VIP_TABLE_COLORTEMP,
	VIP_TABLE_COLORFAC,
	VIP_TABLE_TYPE_NUM,
} VIP_TABLE_TYPE;

void VipTableInit(void);
void VipTableUnInit(void);

bool Init(void);
bool Deinit(void);

bool LoadDefault(void);
void LoadDefaultGainOffsetTable(void);
bool Save(int saveOption/* = VIP_TABLE_SAVE_ALL*/);

/*----------------------------------------------------------------------*/
/*  get table function							*/
/*----------------------------------------------------------------------*/
/* Following APIs are used by AP*/
/* get current source's tables (by getting current timing)*/
StructColorDataType *GetCurColorData(void);
StructColorDataFacModeType *GetCurColorFacMode(void);
unsigned char *GetCurColorTempLevel(UINT32 picMode/* = 0xff*/);
SLR_COLORTEMP_DATA *GetCurColorTempData(void);
SLR_COLORTEMP_DATA *GetCurColorTempDataByLevel(SLR_COLORTEMP_LEVEL level);
SLR_PICTURE_MODE_DATA *GetCurPictureModeData(UINT32 picMode/* = 0xff*/);
SLR_PICTURE_MODE_DATA *GetDefaultPictureModeTable(PICTURE_MODE picMode);
void SetValueToAllPictureModeTable(unsigned char which, unsigned char val);
SLR_PICTURE_MODE_DATA *GetPictureModeDataByIndex(PICTURE_MODE curPictureMode);
unsigned char GetCurDnrMode(void);
SLR_PICTURE_MODE_DATA *GetDefaultPictureModeTable_byCurPictureMode(PICTURE_MODE picMode);

/* get/set picture mode*/
PICTURE_MODE GetPictureMode(SourceOption source);
void SetPictureMode(SourceOption source, PICTURE_MODE picMode);

VIP_TABLE_COLORSTD_ENUM GetVipPictureMode(PICTURE_MODE CurPictureMode);
PICTURE_MODE GetCurPictureMode(void);
void SetCurPictureMode(PICTURE_MODE picMode);


/* Following APIs are called by scaler callback functions*/
/* source type is ENUM_TVD_INPUT_FORMAT*/
void *GetColorData(UINT32 source, UINT32 timing, UINT32 param);
void *GetColorFacMode(UINT32 source, UINT32 timing, UINT32 param);
void *GetColorTempLevel(UINT32 source, UINT32 timing, UINT32 param);

/*void* GetColorTempData_TSB(UINT32 source, UINT32 timing, UINT32 colortmp);*/
void *GetColorTempData(UINT32 source, UINT32 timing, UINT32 param);
void *GetPictureModeData(UINT32 source, UINT32 timing, UINT32 param);
void *GetDnrMode(UINT32 source, UINT32 timing, UINT32 param);

void *GetQualityCoef(VIP_SOURCE_TIMING source_timing);
void *GetQualityCoefExtend(VIP_SOURCE_TIMING source_timing);
void *GetQualityCoefExtend2(VIP_SOURCE_TIMING source_timing);
void *GetQualityCoefExtend3(VIP_SOURCE_TIMING source_timing);
void *GetQualityCoefExtend4(VIP_SOURCE_TIMING source_timing);
void *GetQualityCoef3Dmaode(VIP_3DSOURCE_TIMING source_timing);
UINT8 GetIcmBySrcPicmode(UINT8 picMode);

/*
void SyncValueToAllMode();
void SyncValueToAllTimings();
void SyncValueToAllIdex();
void SavePicModeTableToEeprom();
void SaveCurPicModeTableToEeprom();
void SaveGainOffsetTableToEeprom();
void SkyworthFacReset();
*/
void SaveGainOffsetTable(void);

bool WriteAdcSetting(unsigned char nSrcType, ADCGainOffset *adcGainOffset, unsigned char mode/*=0*/);
bool ReadAdcSetting(unsigned char nSrcType, ADCGainOffset *adcGainOffset, unsigned char mode/*=0*/);
bool WriteColorTempSetting(COLOR_TEMP_DATA *colortempData, unsigned char srcIdx);
bool ReadColorTempSetting(COLOR_TEMP_DATA *colortempData, unsigned char srcIdx);


/*static bool GetPanelFileName(char *sFileName);*/

void Sync(void);
void SetDirty(int id);
bool xConstructVipTablePointLink(void);
bool xLoadFromDisk(void);
bool xLoadDefaultTable(void);

/* load default table*/
void xLoadDefaultPicModeTable(void);
void xLoadDefaultColorDataTable(void);
void xLoadDefaultColorTempTable(void);
void xLoadDefaultColorFacModeTable(void);

/* save each table*/
bool xSavePicModeTable(void);
bool xSaveColorDataTable(void);
bool xSaveColorTempTable(void);
bool xSaveColorFacModeTable(void);

/* load each table from saved content*/
void xLoadPicModeTable(void);
void xLoadColorDataTable(void);
void xLoadColorTempTable(void);
void xLoadColorFacModeTable(void);

void xLoadDefaultGainOffsetTable(void);
void xLoadGainOffsetTable(void);

void *xGetIndexTableItem(VIP_TABLE_TYPE tableType, int index);
void *xGetVipTableDataItem(VIP_TABLE_TYPE tableType, int index);

int xGetIndexTableLength(VIP_TABLE_TYPE tableType);


bool xRegisterCallback(void);
bool xRegisterTable(void);

bool xGetVipTableData(VIP_TABLE_TYPE tableType, int tableIdx,
	VIP_TABLE_TIMIMG_ENUM timing, VIP_TABLE_COLORSTD_ENUM color, void **pRetTableData, int *piRetTableDataLen);


int xGetTableIdx(VIP_TABLE_TYPE tableType, SOURCE_TIMING_INFO *indexTable, int tableSize, SourceOption source, VIP_TABLE_TIMIMG_ENUM timing, VIP_TABLE_COLORSTD_ENUM color);

int xGetTableAllocLengthOnlyByType(VIP_TABLE_TYPE tableType);
int xGetTableAllocLength(VIP_TABLE_TYPE tableType, VIP_TABLE_DATA_STRUCT *pTable, int tableSize);
int xGetTableAllocLengthEx(VIP_TABLE_TYPE tableType, VIP_TABLE_DATA_STRUCT_EX *pTable, int tableSize);

VIP_TABLE_SRC_ENUM 	xGetVipSourceByOptionType(VIP_SOURCE_OPTION_TYPE source);
VIP_TABLE_SRC_ENUM 	xGetVipSourceByOption(SourceOption source);

VIP_TABLE_TIMIMG_ENUM xGetCurVipTiming(void);
VIP_TABLE_TIMIMG_ENUM xGetInputVipTiming(VIP_SOURCE_TIMING srcTiming);
VIP_SOURCE_TIMING xGetInputVipCheckTiming(void);


VIP_SOURCE_OPTION_TYPE 	xGetSourceType(SourceOption source);
SourceOption xGetSourceOption(UINT32 sourceFmt); /* input is ENUM_TVD_INPUT_FORMAT*/

VIP_SOURCE_OPTION_TYPE xGetSourceTypeFromVipSource(VIP_TABLE_SRC_ENUM vipSrc);
void xInitSourceCount(SourceOption *sourceList, int count);
SourceOption xGetCurSource(void);
int xGetSourceCount(void);
bool xGetSourceIndex(SourceOption source, int *iSourceIdx);
bool xGetSourceByIndex(SourceOption *source, int iSourceIdx);

#if 0
static void xGetMD5Value(void *pBuffer, int iBufLen, UINT8 *pMD5Value);
#endif

#ifdef ENABLE_OVERDRIVE
static void xAllocateODMem(void);
static void xReleaseODMem(void);
#endif
void *Vip_GetQualityCoef(VIP_SOURCE_TIMING source_timing);
void *Vip_GetQualityCoefExtend(VIP_SOURCE_TIMING source_timing);
void *Vip_GetQualityCoefExtend2(VIP_SOURCE_TIMING source_timing);
void *Vip_GetQualityCoefExtend3(VIP_SOURCE_TIMING source_timing);
void *Vip_GetQualityCoefExtend4(VIP_SOURCE_TIMING source_timing);
void *Vip_GetQualityCoef3Dmaode(VIP_3DSOURCE_TIMING source_timing);
void *Vip_GetColorData(UINT32 pcbSourceIndex, UINT32 timing, UINT32 param);
void *Vip_GetColorFacMode(UINT32 pcbSourceIndex, UINT32 timing, UINT32 param);
void *Vip_GetColorTempLevel(UINT32 pcbSourceIndex, UINT32 timing, UINT32 param);
void *Vip_GetColorTempData(UINT32 pcbSourceIndex, UINT32 timing, UINT32 param);
void *Vip_GetColorTempData_TSB(UINT32 source, UINT32 timing, UINT32 colortmp);
void *Vip_GetPictureModeData(UINT32 pcbSourceIndex, UINT32 timing, UINT32 param);
void *Vip_GetDnrMode(UINT32 pcbSourceIndex, UINT32 timing, UINT32 param);
UINT8 Vip_GetIcmBySrcPicmode(UINT8 picMode);
int Vip_GetCurPicMode(void);
int VipPanel_GetColorDataTableSize(void);
int VipPanel_GetColorFacTableSize(void);
int VipPanel_GetColorTempTableSize(void);
int VipPanel_GetPictureModeTableSize(void);
int VipPanel_GetPictureModeSetSize(void);
void VipPanel_InitBackLightRange(unsigned int uiMax, unsigned int uiMin);
int VipPanel_GetCustomVipTableSize(void);
void *VipPanel_GetCustomVipTableStruct(void);


#endif

