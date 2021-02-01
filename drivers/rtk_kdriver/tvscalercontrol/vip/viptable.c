
#include <linux/delay.h>
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
//#include <mach/RPCDriver.h>
#include <linux/pageremap.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/vip/viptable.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"

//-----------------------------------------------------------------------------
//	define
//-----------------------------------------------------------------------------
#define VIPTABLE_SAVE_DIR					"/usr/local/etc/dvdplayer/vipTable/"
//#define VIPTABLE_SAVE_DIR					"/tmp/test/darwin/system/src/Unit_test/Tinkerbell/" // test
#define VIPTABLE_SAVE_PICMODE				VIPTABLE_SAVE_DIR"picMode"
#define VIPTABLE_SAVE_COLORDATA				VIPTABLE_SAVE_DIR"colorData"
#define VIPTABLE_SAVE_COLORTEMP				VIPTABLE_SAVE_DIR"colorTemp"
#define VIPTABLE_SAVE_COLORFACMODE			VIPTABLE_SAVE_DIR"colorFacMode"

#define VIPTABLE_SAVE_YPPGAINOFFSET			VIPTABLE_SAVE_DIR"yppGainOffset"
#define VIPTABLE_SAVE_VGAGAINOFFSET			VIPTABLE_SAVE_DIR"vgaGainOffset"

#define VIPTABLE_SAVE_PICMODE_2				VIPTABLE_SAVE_DIR"picMode2"//picture mode data backup file
typedef struct _VIPTABLE_SAVE_HEADER {
	UINT16	iFileSize;
	UINT16	iArrayLen;	// for keeping arraylen in header
	UINT8	md5check[16];
} VIPTABLE_SAVE_HEADER;

#define	vip_malloc(x)	kmalloc(x, GFP_KERNEL)
#define	vip_free(x)	kfree(x)

//-----------------------------------------------------------------------------
//	extern tables and callbacks
//-----------------------------------------------------------------------------

extern ADCGainOffset 				m_defaultYPbPrGainOffsetData[SR_MAX_YPBPR_GAINOFFSET_MODE];
extern ADCGainOffset				m_defaultVgaGainOffset;
extern VIP_TABLE_DATA_STRUCT 		m_defaultColorDataTable[];
extern VIP_TABLE_DATA_STRUCT 		m_defaultColorFacTable[];
extern VIP_TABLE_DATA_STRUCT 		m_defaultColorTempTable[];
extern VIP_TABLE_DATA_STRUCT_EX		m_defaultPictureModeTable[];
extern SLR_VIP_TABLE 				m_defaultVipTable;

extern SLR_PICTURE_MODE_DATA m_defaultPictureModeSet[];



////VIP_TABLE_INDEX_TYPE	m_indexType;
VIP_TABLE_INDEX_TYPE	m_indexType[VIP_TABLE_TYPE_NUM];
int 					m_iIndexSourceCnt[VIP_TABLE_TYPE_NUM]; // VIP_SOURCE_TYPE_MAX_NUM or PcbSource count

// table array
// SOURCE_TIMING_INFO index array is for future extention
// currently only index by source type
PIC_MODE_DATA*				m_picModeTable;
UINT16						m_picModeTableSize;
SOURCE_TIMING_INFO* 		m_picModeTableIdx;	// length = m_picModeTable's length

StructColorDataType*		m_colorDataTable;
UINT16						m_colorDataTableSize;
SOURCE_TIMING_INFO* 		m_colorDataTableIdx;

COLOR_TEMP_DATA*			m_colorTempData;
UINT16						m_colorTempDataSize;
SOURCE_TIMING_INFO* 		m_colorTempDataIdx;

StructColorDataFacModeType* m_colorFacModeTable;
UINT16						m_colorFacModeTableSize;
SOURCE_TIMING_INFO* 		m_colorFacModeTableIdx;

ADCGainOffset				m_vgaGainOffset;
ADCGainOffset				m_yPbPrGainOffsetData[SR_MAX_YPBPR_GAINOFFSET_MODE];

SLR_VIP_TABLE*				m_pVipTable;
void*						m_pVipTableCustom;
bool						m_bCopyVipTable;

// vip table related setting (not put in SetupClass)
PICTURE_MODE*				m_pictureMode;
bool						m_isLoaded;
SourceOption				m_picModeSource;

SourceOption sourceList[9] = {
	SOURCE_IDTV1,
	SOURCE_ATV1,
	SOURCE_DTV1,
	SOURCE_AV1,
	SOURCE_AV2,
	SOURCE_YPP1,
	SOURCE_HDMI1,
	SOURCE_HDMI2,
	SOURCE_HDMI3,
};

static SourceOption m_sourceList[SOURCE_MAX_NUM] = {0};
static int m_count = 0;
//-----------------------------------------------------------------------------
//
//	PUBLIC FUNCTIONS
//
//-----------------------------------------------------------------------------
void VipTableInit()
{
	int iCnt = 0;

	m_picModeTable = NULL;
	m_picModeTableSize = 0;
	m_picModeTableIdx = NULL;

	m_colorDataTable = NULL;
	m_colorDataTableSize = 0;
	m_colorDataTableIdx = NULL;

	m_colorTempData = NULL;
	m_colorTempDataSize = 0;
	m_colorTempDataIdx = NULL;

	m_colorFacModeTable = NULL;
	m_colorFacModeTableSize = 0;
	m_colorFacModeTableIdx = NULL;

	memset(&m_vgaGainOffset, 0, sizeof(ADCGainOffset));
	memset(m_yPbPrGainOffsetData, 0, sizeof(ADCGainOffset) * SR_MAX_YPBPR_GAINOFFSET_MODE);

	// todo: need copy SLR_VIP_TABLE?
	m_pVipTable = NULL;
	m_pVipTableCustom = NULL;
	m_bCopyVipTable = FALSE;

	for (iCnt = 0; iCnt < VIP_TABLE_TYPE_NUM; iCnt ++) {
		//m_indexType[iCnt] = VIP_TABLE_INDEX_BY_SOURCE_TYPE;
		m_indexType[iCnt] = VIP_TABLE_INDEX_BY_SOURCE;
		m_iIndexSourceCnt[iCnt] = 0;	// will set when Init
	}

	//cloud add@20120628 ColorFacMode table is separated  by timming.
	m_indexType[VIP_TABLE_COLORFAC] =VIP_TABLE_INDEX_BY_SOURCE_TYPE;

	m_pictureMode = NULL;

	m_isLoaded = FALSE;

	m_picModeSource = SOURCE_NULL;

	xInitSourceCount(sourceList, sizeof(sourceList)/sizeof(sourceList[0]));

	Init();
}

void VipTableUnInit()
{
	Deinit();
}

bool Init()
{
	int iCnt = 0;

	for (iCnt = 0; iCnt < VIP_TABLE_TYPE_NUM; iCnt ++) {
		if (m_indexType[iCnt] == VIP_TABLE_INDEX_BY_SOURCE) {
			m_iIndexSourceCnt[iCnt] = xGetSourceCount() + 1;	// for browser
		} else {
			m_iIndexSourceCnt[iCnt] = VIP_SOURCE_TYPE_MAX_NUM;
		}
	}

	if (NULL == m_pictureMode) {
		m_pictureMode = (PICTURE_MODE*)vip_malloc(m_iIndexSourceCnt[VIP_TABLE_PICMODE] * sizeof(PICTURE_MODE));
		if(m_pictureMode == NULL)
			{
				rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
				return false;
			}
		for (iCnt = 0; iCnt < m_iIndexSourceCnt[VIP_TABLE_PICMODE]; iCnt ++) {
			m_pictureMode[iCnt] = PICTURE_MODE_STANDARD;
		}
	}

	xLoadFromDisk();

	xRegisterCallback();
	xRegisterTable();

#ifdef ENABLE_OVERDRIVE
	xAllocateODMem();
#endif

	return TRUE;
}

bool Deinit()
{
	// free tables
	// pic mode
	if (m_picModeTable) {
		vip_free(m_picModeTable);
		m_picModeTable = NULL;
	}

	if (m_picModeTableIdx) {
		vip_free(m_picModeTableIdx);
		m_picModeTableIdx = NULL;
	}

	// color data
	if (m_colorDataTable) {
		vip_free(m_colorDataTable);
		m_colorDataTable = NULL;
	}

	if (m_colorDataTableIdx) {
		vip_free(m_colorDataTableIdx);
		m_colorDataTableIdx = NULL;
	}

	// color temp
	if (m_colorTempData) {
		vip_free(m_colorTempData);
		m_colorTempData = NULL;
	}

	if (m_colorTempDataIdx) {
		vip_free(m_colorTempDataIdx);
		m_colorTempDataIdx = NULL;
	}

	// color fac mode
	if (m_colorFacModeTable) {
		vip_free(m_colorFacModeTable);
		m_colorFacModeTable = NULL;
	}

	if (m_colorFacModeTableIdx) {
		vip_free(m_colorFacModeTableIdx);
		m_colorFacModeTableIdx = NULL;
	}

	if (m_bCopyVipTable && m_pVipTable) {
		vip_free(m_pVipTable);
		m_pVipTable = NULL;
	}

	if (m_bCopyVipTable && m_pVipTableCustom) {
		vip_free(m_pVipTableCustom);
		m_pVipTableCustom = NULL;
	}

	if (m_pictureMode) {
		vip_free(m_pictureMode);
		m_pictureMode = NULL;
	}

#ifdef ENABLE_OVERDRIVE
	xReleaseODMem();
#endif

	return TRUE;
}

bool LoadDefault()
{
	return xLoadDefaultTable();
}

void LoadDefaultGainOffsetTable()
{
    xLoadDefaultGainOffsetTable();
}

bool Save(int saveOption)
{
#if 0
	DIR *dir = NULL;
	if ((dir = opendir(VIPTABLE_SAVE_DIR)) == NULL)
		mkdir(VIPTABLE_SAVE_DIR, 0777);
	else
		closedir(dir);

	///xSaveColorDataTable();//color data, not necessary to save
	if ((saveOption & VIP_TABLE_SAVE_PICMODE) == VIP_TABLE_SAVE_PICMODE)
		xSavePicModeTable();
	if ((saveOption & VIP_TABLE_SAVE_COLORTEMP) == VIP_TABLE_SAVE_COLORTEMP)
		xSaveColorTempTable();
	if ((saveOption & VIP_TABLE_SAVE_COLORFAC) == VIP_TABLE_SAVE_COLORFAC)
		xSaveColorFacModeTable();
#endif
	return TRUE;
}



void* GetColorData(UINT32 source, UINT32 timing, UINT32 color)
{
	int iIdx;
	if (NULL == m_colorDataTable || NULL == m_colorDataTableIdx)
		return NULL;

	iIdx = xGetTableIdx(VIP_TABLE_COLORDATA, m_colorDataTableIdx, m_colorDataTableSize, xGetSourceOption(source), (VIP_TABLE_TIMIMG_ENUM)timing, (VIP_TABLE_COLORSTD_ENUM)color);
	return (void*)&m_colorDataTable[iIdx];
}

void* GetColorFacMode(UINT32 source, UINT32 timing, UINT32 color)
{
	int iIdx;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	PICTURE_MODE curPictureMode;
	VIP_TABLE_COLORSTD_ENUM vipPictureMode;
	if (NULL == m_colorFacModeTable || NULL == m_colorFacModeTableIdx)
		return NULL;

	curTiming = xGetCurVipTiming();
	curPictureMode = GetCurPictureMode();
	vipPictureMode = (VIP_TABLE_COLORSTD_ENUM)curPictureMode;

	if((color == 0)||(color == 0xFF)||(color >= VIP_PICTURE_MODE_MAX)){
		iIdx = xGetTableIdx(VIP_TABLE_COLORFAC, m_colorFacModeTableIdx, m_colorFacModeTableSize, xGetSourceOption(source), curTiming, vipPictureMode);
	}
	else{
		//iIdx = xGetTableIdx(VIP_TABLE_COLORFAC, m_colorFacModeTableIdx, m_colorFacModeTableSize, xGetSourceOption(source), (VIP_TABLE_TIMIMG_ENUM)timing, (VIP_TABLE_COLORSTD_ENUM)color);
		iIdx = xGetTableIdx(VIP_TABLE_COLORFAC, m_colorFacModeTableIdx, m_colorFacModeTableSize, xGetSourceOption(source), curTiming, (VIP_TABLE_COLORSTD_ENUM)color);
	}
	return (void*)&m_colorFacModeTable[iIdx];
}

void* GetColorTempLevel(UINT32 source, UINT32 timing, UINT32 color)
{
	PICTURE_MODE mode;
	int iIdx;
	if (NULL == m_picModeTable || NULL == m_picModeTableIdx)
		return NULL;

	mode = GetPictureMode(xGetSourceOption(source));
	iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, xGetSourceOption(source), (VIP_TABLE_TIMIMG_ENUM)timing, (VIP_TABLE_COLORSTD_ENUM)color);

	return (void *)&m_picModeTable[iIdx].picMode[mode].ColorTemp;
}

void* GetColorTempData(UINT32 source, UINT32 timing, UINT32 color)
{
	UINT8 *pValue = NULL;
	SLR_COLORTEMP_LEVEL level = SLR_COLORTEMP_USER;
	int iIdx = 0;
	if (NULL == m_colorTempData || NULL == m_colorTempDataIdx)
		return NULL;

	pValue = (UINT8 *)GetColorTempLevel(source, timing, color);
	if (pValue != NULL) {
		level = (SLR_COLORTEMP_LEVEL)(*pValue);
		iIdx = xGetTableIdx(VIP_TABLE_COLORTEMP, m_colorTempDataIdx, m_colorTempDataSize, xGetSourceOption(source), (VIP_TABLE_TIMIMG_ENUM)timing, (VIP_TABLE_COLORSTD_ENUM)color);
	}
	return &m_colorTempData[iIdx].colorTempData[level];
}

// param is for passing picture mode
// todo: need add param for color
void* GetPictureModeData(UINT32 source, UINT32 timing, UINT32 param)
{
	UINT32 color;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	PICTURE_MODE curPictureMode;
	VIP_TABLE_COLORSTD_ENUM vipPictureMode;
	int iIdx;

	if(param == 0xDF)
	{
		return GetDefaultPictureModeTable_byCurPictureMode(GetCurPictureMode());
	}

	if ((param != 0xFF) && (param >= PICTURE_MODE_MAX))
		return NULL;

	if (NULL == m_picModeTable || NULL == m_picModeTableIdx)
		return NULL;

	color = param;
	source = TVD_INFMT_VODMA0;// fixed source for driver base to avoid src incorrect (driver base no more use real picmode data)
	if (param == 0xFF) {
		param = GetPictureMode(xGetSourceOption(source));

		//20110711 peggy: keep scaler callback source for set picture mode
		m_picModeSource = xGetSourceOption(source);
	}

//	SourceOption sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();
	curPictureMode = GetCurPictureMode();
	vipPictureMode = (VIP_TABLE_COLORSTD_ENUM)curPictureMode;

	//int iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, xGetSourceOption(source), (VIP_TABLE_TIMIMG_ENUM)timing, VIP_COLORSTD_DEFAULT);
	iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, xGetSourceOption(source),curTiming, VIP_COLORSTD_DEFAULT);
	return (void *)&m_picModeTable[iIdx].picMode[curPictureMode];
}

void* GetDnrMode(UINT32 source, UINT32 timing, UINT32 color)
{
	int iIdx;
	PICTURE_MODE mode;
	if (NULL == m_picModeTable || NULL == m_picModeTableIdx)
		return NULL;

	iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, xGetSourceOption(source), (VIP_TABLE_TIMIMG_ENUM)timing, (VIP_TABLE_COLORSTD_ENUM)color);
	mode = GetPictureMode(xGetSourceOption(source));

	return (void *)&m_picModeTable[iIdx].picMode[mode].DNR;
}

void* GetQualityCoef(VIP_SOURCE_TIMING source_timing)
{
	if (NULL == m_pVipTable)
		return NULL;

	return (void *)(((UINT8 *)m_pVipTable->VIP_QUALITY_Coef) + source_timing * VIP_QUALITY_Coef_MAX);
}

void* GetQualityCoefExtend(VIP_SOURCE_TIMING source_timing)
{
	if (NULL == m_pVipTable)
		return NULL;

	return (void *)(((UINT8 *)m_pVipTable->VIP_QUALITY_Extend_Coef) + source_timing * VIP_QUALITY_Extend_Coef_MAX);
}

void* GetQualityCoefExtend2(VIP_SOURCE_TIMING source_timing)
{
	if (NULL == m_pVipTable)
		return NULL;

	return (void *)(((UINT8 *)m_pVipTable->VIP_QUALITY_Extend2_Coef) + source_timing * VIP_QUALITY_Extend2_Coef_MAX);
}

void* GetQualityCoefExtend3(VIP_SOURCE_TIMING source_timing)
{
	if (NULL == m_pVipTable)
		return NULL;

	return (void *)(((UINT8 *)m_pVipTable->VIP_QUALITY_Extend3_Coef) + source_timing * VIP_QUALITY_Extend3_Coef_MAX);
}

void* GetQualityCoefExtend4(VIP_SOURCE_TIMING source_timing)
{
	if (NULL == m_pVipTable)
		return NULL;

	return (void *)(((UINT8 *)m_pVipTable->VIP_QUALITY_Extend4_Coef) + source_timing * VIP_QUALITY_Extend4_Coef_MAX);
}


//young 3Dtable
void* GetQualityCoef3Dmaode(VIP_3DSOURCE_TIMING source_timing)
{
	if (NULL == m_pVipTable)
		return NULL;

	return (void *)(((UINT8 *)m_pVipTable->VIP_QUALITY_3Dmode_Coef) + source_timing * VIP_QUALITY_3Dmode_Coef_MAX);
}

// following APIs are for AP use
// get current table (get current source and current timing, colorstd use default)

StructColorDataType* GetCurColorData()
{
	int iIdx;
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	if (NULL == m_colorDataTable || NULL == m_colorDataTableIdx)
		return NULL;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();

	iIdx = xGetTableIdx(VIP_TABLE_COLORDATA, m_colorDataTableIdx, m_colorDataTableSize, sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	return &m_colorDataTable[iIdx];
}

StructColorDataFacModeType* GetCurColorFacMode()
{
	int iIdx;
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	PICTURE_MODE curPictureMode;
	VIP_TABLE_COLORSTD_ENUM vipPictureMode;

	if (NULL == m_colorFacModeTable || NULL == m_colorFacModeTableIdx)
		return NULL;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();
	curPictureMode = GetCurPictureMode();
	vipPictureMode = (VIP_TABLE_COLORSTD_ENUM)curPictureMode;

	iIdx = xGetTableIdx(VIP_TABLE_COLORFAC, m_colorFacModeTableIdx, m_colorFacModeTableSize, sourceOption, curTiming, vipPictureMode);

	return &m_colorFacModeTable[iIdx];
}

unsigned char* GetCurColorTempLevel(UINT32 picMode)
{
	int iIdx;
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	PICTURE_MODE mode;
	if ((picMode != 0xFF) && (picMode >= PICTURE_MODE_MAX))
		return NULL;

	if (NULL == m_picModeTable || NULL == m_picModeTableIdx)
		return NULL;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();

	mode = (PICTURE_MODE)picMode;
	if (picMode == 0xFF)
		mode = GetPictureMode(sourceOption);

	//Malone 20120620:Fix that change colortemp invalid at HDMI mode @ YCbCr 444/442
	#if defined(BUILD_TV033_1_ISDB) || defined(BUILD_TV015_5_ISDB)
	curTiming = VIP_TIMIMG_DEFAULT;
	#endif

	iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	return &(m_picModeTable[iIdx].picMode[mode].ColorTemp);

}

SLR_COLORTEMP_DATA* GetCurColorTempData()
{
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	UINT8 *pValue = NULL;
	SLR_COLORTEMP_LEVEL level = SLR_COLORTEMP_USER;
	int iIdx = 0;

	if (NULL == m_colorTempData || NULL == m_colorTempDataIdx)
		return NULL;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();
	//rtd_printk(KERN_DEBUG, TAG_NAME, "\033[1;40;31m ************bug sourceOption not send to GetColorTempLevel which need input fmt*******\033[m\n");
	pValue = (UINT8 *)GetColorTempLevel(sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	if (pValue != NULL) {
		level = (SLR_COLORTEMP_LEVEL)(*pValue);
		iIdx = xGetTableIdx(VIP_TABLE_COLORTEMP, m_colorTempDataIdx, m_colorTempDataSize, sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	}

	return &m_colorTempData[iIdx].colorTempData[level];
}

SLR_COLORTEMP_DATA*	GetCurColorTempDataByLevel(SLR_COLORTEMP_LEVEL level)
{
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	int iIdx;

	if (NULL == m_colorTempData || NULL == m_colorTempDataIdx)
		return NULL;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();

	iIdx = xGetTableIdx(VIP_TABLE_COLORTEMP, m_colorTempDataIdx, m_colorTempDataSize, sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	return &m_colorTempData[iIdx].colorTempData[level];
}

VIP_TABLE_COLORSTD_ENUM GetVipPictureMode(PICTURE_MODE CurPictureMode)
{
    return (VIP_TABLE_COLORSTD_ENUM)CurPictureMode;
}

// if input = 0xff, get current picture mode
SLR_PICTURE_MODE_DATA* GetCurPictureModeData(UINT32 picMode)
{
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	PICTURE_MODE curPictureMode;
	VIP_TABLE_COLORSTD_ENUM vipPictureMode;
	int iIdx;
	if ((picMode != 0xFF) && (picMode >= PICTURE_MODE_MAX))
		return NULL;

	if (NULL == m_picModeTable || NULL == m_picModeTableIdx)
		return NULL;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();

	curPictureMode = GetCurPictureMode();
	vipPictureMode = (VIP_TABLE_COLORSTD_ENUM)curPictureMode;

	if (picMode == 0xFF){
		picMode = GetPictureMode(sourceOption);
	}

	iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	return &m_picModeTable[iIdx].picMode[vipPictureMode];
}

SLR_PICTURE_MODE_DATA* GetPictureModeDataByIndex(PICTURE_MODE curPictureMode)
{
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	SourceOption curSource;
	int iIdx;
	VIP_TABLE_COLORSTD_ENUM vipPictureMode = GetVipPictureMode(curPictureMode);
	if (vipPictureMode >= VIP_PICTURE_MODE_MAX)
		return NULL;

	if (NULL == m_picModeTable || NULL == m_picModeTableIdx)
		return NULL;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();


//	PICTURE_MODE curPictureMode = GetCurPictureMode();


// USER:roni_lai	DATE:20120508 add,change to media , sourceOption value always is last source .
// we need to change sourceOption value .
	curSource = xGetCurSource();
	if(curSource == SOURCE_PLAYBACK)
		sourceOption = SOURCE_PLAYBACK;

	//rtd_printk(KERN_DEBUG, TAG_NAME, "planck:::GetCurPictureModeData:::sourceOption=%d\n", sourceOption);
	//rtd_printk(KERN_DEBUG, TAG_NAME, "planck:::GetCurPictureModeData:::curTiming=%d\n", curTiming);
	//rtd_printk(KERN_DEBUG, TAG_NAME, "planck:::GetCurPictureModeData:::curPictureMode=%d\n", curPictureMode);
	//rtd_printk(KERN_DEBUG, TAG_NAME, "planck:::GetCurPictureModeData:::vipPictureMode=%d\n", vipPictureMode);


	iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	return &m_picModeTable[iIdx].picMode[vipPictureMode];
}

SLR_PICTURE_MODE_DATA* GetDefaultPictureModeTable(PICTURE_MODE picMode)
{
	if (((picMode != 0xFF) && (picMode >= PICTURE_MODE_MAX)) || picMode >= VipPanel_GetPictureModeSetSize())
		return NULL;

	return &m_defaultPictureModeSet[picMode];
}

void SetValueToAllPictureModeTable(unsigned char which ,unsigned char val)
{
	int tidx,midx;

	rtd_printk(KERN_DEBUG, TAG_NAME, "m_iIndexSourceCnt[VIP_TABLE_PICMODE];:%d\n",m_iIndexSourceCnt[VIP_TABLE_PICMODE]);

	for(tidx=0;tidx<m_iIndexSourceCnt[VIP_TABLE_PICMODE];tidx++)
	{
		for(midx=PICTURE_MODE_USER;midx<PICTURE_MODE_MAX;midx++)
			if(which==0)
				m_picModeTable[tidx].picMode[midx].DNR = val;
			else if(which==1)
				m_picModeTable[tidx].picMode[midx].MPEG= val;
			else if(which==2)
				m_picModeTable[tidx].picMode[midx].DCRMode= val;
	}
}

SLR_PICTURE_MODE_DATA* GetDefaultPictureModeTable_byCurPictureMode(PICTURE_MODE picMode)
{
	SLR_PICTURE_MODE_DATA* pTableData = NULL;
	int iTableDataLen = 0;

	if ((picMode != 0xFF) && (picMode >= PICTURE_MODE_MAX))
		return NULL;

	//only atv
	xGetVipTableData(VIP_TABLE_PICMODE, 0, VIP_TIMIMG_DEFAULT, VIP_COLORSTD_DEFAULT, (void**)(&pTableData), &iTableDataLen);
	if (pTableData)
		return &pTableData[picMode];
	return NULL;
}

unsigned char GetCurDnrMode()
{
	SourceOption sourceOption;
	VIP_TABLE_TIMIMG_ENUM curTiming;
	int iIdx;
	PICTURE_MODE mode;

	if (NULL == m_picModeTable || NULL == m_picModeTableIdx)
		return 0;

	sourceOption = xGetCurSource();
	curTiming = xGetCurVipTiming();

	iIdx = xGetTableIdx(VIP_TABLE_PICMODE, m_picModeTableIdx, m_picModeTableSize, sourceOption, curTiming, VIP_COLORSTD_DEFAULT);
	mode = GetPictureMode(sourceOption);

	return m_picModeTable[iIdx].picMode[mode].DNR;
}


PICTURE_MODE GetPictureMode(SourceOption source)
{
	int iSourceIdx = 0;
	if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_PICMODE]) {
 		if (false == xGetSourceIndex(source, &iSourceIdx)) {
			if (source == SOURCE_PLAYBACK)
				iSourceIdx = m_iIndexSourceCnt[VIP_TABLE_PICMODE] - 1; //last is for browser
			else
				iSourceIdx = 0;
		}
	} else {
		iSourceIdx = xGetSourceType(source);
	}

	return m_pictureMode[iSourceIdx];
}

void SetPictureMode(SourceOption source, PICTURE_MODE picMode)
{
	int iSourceIdx = 0;
	if (m_picModeSource != SOURCE_NULL)
		source = m_picModeSource;

	if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_PICMODE]) {
		if (false == xGetSourceIndex(source, &iSourceIdx)) {
			if (source == SOURCE_PLAYBACK)
				iSourceIdx = m_iIndexSourceCnt[VIP_TABLE_PICMODE] - 1; //last is for browser
			else
				iSourceIdx = 0;
		}
	} else {
		iSourceIdx = xGetSourceType(source);
	}

	m_pictureMode[iSourceIdx] = picMode;
}

PICTURE_MODE GetCurPictureMode()
{
	int iSourceIdx = 0;
	if (m_picModeSource == SOURCE_NULL)
		return m_pictureMode[0];

	if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_PICMODE]) {
		if (false == xGetSourceIndex(m_picModeSource, &iSourceIdx)) {
			if (m_picModeSource == SOURCE_PLAYBACK)
				iSourceIdx = m_iIndexSourceCnt[VIP_TABLE_PICMODE] - 1; //last is for browser
			else
				iSourceIdx = 0;
		}
	} else {
		iSourceIdx = xGetSourceType(m_picModeSource);
	}

	return m_pictureMode[iSourceIdx];
}

void SetCurPictureMode(PICTURE_MODE picMode)
{
	int iSourceIdx = 0;
	if (m_picModeSource == SOURCE_NULL)
		return;

	if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_PICMODE]) {
		if (false == xGetSourceIndex(m_picModeSource, &iSourceIdx)) {
			if (m_picModeSource == SOURCE_PLAYBACK)
				iSourceIdx = m_iIndexSourceCnt[VIP_TABLE_PICMODE] - 1; //last is for browser
			else
				iSourceIdx = 0;
		}
	} else {
		iSourceIdx = xGetSourceType(m_picModeSource);
	}

	m_pictureMode[iSourceIdx] = picMode;
}

void SaveGainOffsetTable()
{
#if 0
	DIR *dir = NULL;
	if ((dir = opendir(VIPTABLE_SAVE_DIR)) == NULL)
		mkdir(VIPTABLE_SAVE_DIR, 0777);
	else
		closedir(dir);

	VIPTABLE_SAVE_HEADER header;

	FILE *pFile = fopen(VIPTABLE_SAVE_YPPGAINOFFSET, "w+");
	if (pFile) {
		UINT16 iFileSize = sizeof(ADCGainOffset) * SR_MAX_YPBPR_GAINOFFSET_MODE;

		void* buffer = vip_malloc(iFileSize);
		if(buffer == NULL)
			{
				printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
				return ;
			}
		UINT8* bufferIdx = (UINT8*)buffer;
		memcpy(bufferIdx, &m_yPbPrGainOffsetData, sizeof(ADCGainOffset) * SR_MAX_YPBPR_GAINOFFSET_MODE);

		// count md5 key
		xGetMD5Value(buffer, iFileSize, (UINT8*)header.md5check);

		header.iFileSize = iFileSize;
		header.iArrayLen = SR_MAX_YPBPR_GAINOFFSET_MODE;

		fwrite(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
		fwrite(buffer, 1, iFileSize, pFile);

		vip_free(buffer);
		fclose(pFile);
	}

	pFile = fopen(VIPTABLE_SAVE_VGAGAINOFFSET, "w+");
	if (pFile) {
		UINT16 iFileSize = sizeof(ADCGainOffset);

		void* buffer = vip_malloc(iFileSize);
		if(buffer == NULL)
			{
				fclose(pFile);
				printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
				return ;
			}
		UINT8* bufferIdx = (UINT8*)buffer;
		memcpy(bufferIdx, &m_vgaGainOffset, sizeof(ADCGainOffset));

		// count md5 key
		xGetMD5Value(buffer, iFileSize, (UINT8*)header.md5check);

		header.iFileSize = iFileSize;
		header.iArrayLen = 1;

		fwrite(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
		fwrite(buffer, 1, iFileSize, pFile);

		vip_free(buffer);
		fclose(pFile);
	}
#endif
}

UINT8 GetIcmBySrcPicmode(UINT8 picMode)
{
	VIP_TABLE_TIMIMG_ENUM srcTiming;
	if (NULL == m_pVipTable)
		return 0;

	srcTiming = xGetCurVipTiming();

	return *(((UINT8 *)m_pVipTable->ICM_by_timing_picmode) + picMode * VIP_PICTURE_MODE_MAX + srcTiming);
}

//-----------------------------------------------------------------------------
//
//	LOCAL FUNCTIONS
//
//-----------------------------------------------------------------------------
bool xConstructVipTablePointLink()
{
	if (m_bCopyVipTable) {
		m_pVipTable = (SLR_VIP_TABLE*) vip_malloc(sizeof(SLR_VIP_TABLE));
		m_pVipTableCustom = vip_malloc(VipPanel_GetCustomVipTableSize());
		if(m_pVipTable == NULL || m_pVipTableCustom == NULL)
		{
			rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
			return false;
		}

		memcpy(m_pVipTable, &m_defaultVipTable, sizeof(SLR_VIP_TABLE));
		memcpy(m_pVipTableCustom, (void*)VipPanel_GetCustomVipTableStruct(), VipPanel_GetCustomVipTableSize());
	} else {
		m_pVipTable = &m_defaultVipTable;
		m_pVipTableCustom = (void*)VipPanel_GetCustomVipTableStruct();
	}
	return true;
}

bool xLoadFromDisk()
{
	//todo, binary and sql lite version
	if (m_isLoaded == FALSE) {
#if 0
			char sfactoypath[128];
			memset(sfactoypath,0,128);
			sprintf(sfactoypath, "/tmp/factory/");
			FILE *fd = fopen(sfactoypath, "r");
			if (fd == NULL)
				system("factory load");
#endif
		xLoadPicModeTable();
		xLoadColorDataTable();
		xLoadColorTempTable();
		xLoadColorFacModeTable();

		xLoadGainOffsetTable();
		//todo: following table

		if (!xConstructVipTablePointLink()) return false;
		m_isLoaded = TRUE;

	}

	return TRUE;
}

// virtual
// might be customized, currently copy to each SOURCE_TYPE (ex. AV1 and AV2 will use the same table)
bool xLoadDefaultTable()
{
	xLoadDefaultPicModeTable();
	xLoadDefaultColorDataTable();

	xLoadDefaultColorTempTable();

	xLoadDefaultColorFacModeTable();

	xLoadDefaultGainOffsetTable();

	if (!xConstructVipTablePointLink()) return false;

	return TRUE;
}

bool xRegisterCallback()
{
	// register callback
	fwif_color_reg_callback1(COLOR_CALLBACK_GET_QUALITY_COEF, Vip_GetQualityCoef);
	fwif_color_reg_callback1(COLOR_CALLBACK_GET_QUALITY_EXTEND, Vip_GetQualityCoefExtend);
	fwif_color_reg_callback1(COLOR_CALLBACK_GET_QUALITY_EXTEND2, Vip_GetQualityCoefExtend2);
	fwif_color_reg_callback1(COLOR_CALLBACK_GET_QUALITY_EXTEND3, Vip_GetQualityCoefExtend3);
	fwif_color_reg_callback1(COLOR_CALLBACK_GET_QUALITY_EXTEND4, Vip_GetQualityCoefExtend4);

	fwif_color_reg_callback2(COLOR_CALLBACK_GET_COLOR_DATA, Vip_GetColorData);
	fwif_color_reg_callback2(COLOR_CALLBACK_GET_COLOR_FAC_MODE, Vip_GetColorFacMode);
	fwif_color_reg_callback2(COLOR_CALLBACK_GET_COLOR_TEMP_DATA, Vip_GetColorTempData);
//	fwif_color_reg_callback2(COLOR_CALLBACK_GET_COLOR_TEMP_DATA_TSB, Vip_GetColorTempData_TSB);
	fwif_color_reg_callback2(COLOR_CALLBACK_GET_COLOR_TEMP_LEVEL, Vip_GetColorTempLevel);
	fwif_color_reg_callback2(COLOR_CALLBACK_GET_PICTURE_MODE_DATA, Vip_GetPictureModeData);
	fwif_color_reg_callback2(COLOR_CALLBACK_GET_DNR_MODE, Vip_GetDnrMode);

	fwif_color_reg_callback3(COLOR_CALLBACK_GET_CURPICMODE, Vip_GetCurPicMode);
	fwif_color_reg_callback4(COLOR_CALLBACK_GET_ICM_BY_TIMING_PICMODE, Vip_GetIcmBySrcPicmode);
	fwif_color_reg_callback5(COLOR_CALLBACK_GET_QUALITY_3Dmode, Vip_GetQualityCoef3Dmaode);
	return TRUE;
}

bool xRegisterTable()
{
#if 0
	Scaler_RegTable(SCALER_REG_TABLE_VGA_GAINOFFSET, (void *)&m_vgaGainOffset);
	Scaler_RegTable(SCALER_REG_TABLE_YPBPR_GAINOFFSET, m_yPbPrGainOffsetData);
	Scaler_RegTable(SCALER_REG_TABLE_VIP_TABLE,(void *)m_pVipTable);
	Scaler_RegTable(SCALER_REG_TABLE_VIP_TABLE_CUSTOM,(void *)m_pVipTableCustom);
	Scaler_RegTable(SCALER_REG_TABLE_Ddomain_SHP,(void *)&m_pVipTable->Ddomain_SHPTable[0]);

	Scaler_RegTable(SCALER_REG_TABLE_SR_INIT_TABLE, (void *)&m_pVipTable->SR_init_table[0][0]);
	//Scaler_RegTable(SCALER_REG_TABLE_SD_H_Table, (void *)&m_pVipTable->SD_H_table[0][0]);
	//Scaler_RegTable(SCALER_REG_TABLE_SD_V_Table, (void *)&m_pVipTable->SD_V_table[0][0]);
	//Scaler_RegTable(SCALER_REG_TABLE_DCC_CONTROL_STRUCTURE, (void *)&m_pVipTable->DCC_Control_Structure);
//	Scaler_RegTable(SCALER_REG_TABLE_DCC_LEVEL_TABLE, (void *)&m_pVipTable->DCC_LEVEL_TABLE[0][0]);	//20120827 added by CSFC
	//Scaler_RegTable(SCALER_REG_TABLE_DCC_skin_tone_TABLE, (void *)&m_pVipTable->DCC_skin_tone_TABLE[0]);	//20130520 added by CSFC
//	Scaler_RegTable(SCALER_REG_TABLE_RTNR_Y_C_COEFF, (void *)&m_pVipTable->RTNR_Y_C_Coeff[0][0]);	//20100817 added by Leo Chen
	Scaler_RegTable(SCALER_REG_TABLE_ODtable_COEFF, (void *)&m_pVipTable->ODtable_Coeff[0][0]);	//young vippanel
	Scaler_RegTable(SCALER_REG_TABLE_NR_TABLE, (void *)&m_pVipTable->Manual_NR_Table[0][0]);
	Scaler_RegTable(SCALER_REG_TABLE_PQA_INPUT_TABLE, (void *)&m_pVipTable->PQA_Input_Table[0][0][0]);
	Scaler_RegTable(SCALER_REG_TABLE_PQA_TABLE, (void *)&m_pVipTable->PQA_Table[0][0][0][0]);
	Scaler_RegTable(SCALER_REG_TABLE_DCR_TABLE, (void *)&m_pVipTable->DCR_TABLE[0][0]);				//20101111 added by Leo Chen

//	Scaler_RegTable(SCALER_REG_TABLE_dbDCCHisto, (void *)&m_pVipTable->database_histogram[0][0]);
//	Scaler_RegTable(SCALER_REG_TABLE_dbDCCCurve, (void *)&m_pVipTable->database_curve[0][0]);


//	Scaler_RegTable(SCALER_REG_TABLE_EGSM_PostSHP_Coef, (void *)&m_pVipTable->EGSM_PostSHP_Coef [0][0]);//20101013 csfanchiang
	Scaler_RegTable(SCALER_REG_TABLE_EGSM_PostSHP_Coef, (void *)&m_pVipTable->D_EDGE_Smooth_Coef[0]);
//	Scaler_RegTable(SCALER_REG_TABLE_I_EDGE_Smooth_Coef, (void *)&m_pVipTable->I_EDGE_Smooth_Coef [0][0]);//20120301 march
	Scaler_RegTable(SCALER_REG_TABLE_I_EDGE_Smooth_Coef, (void *)&m_pVipTable->I_EDGE_Smooth_Coef[0]);

	Scaler_RegTable(SCALER_REG_TABLE_Auto_Function_Array1, (void *)&m_pVipTable->Auto_Function_Array1[0]);
	Scaler_RegTable(SCALER_REG_TABLE_Auto_Function_Array2, (void *)&m_pVipTable->Auto_Function_Array2[0]);
	Scaler_RegTable(SCALER_REG_TABLE_UV_Gains_1, (void *)((UINT16 (*)[9]) m_pVipTable->UV_Gains_1[0]));
	Scaler_RegTable(SCALER_REG_TABLE_UV_Gains_2, (void *)((UINT16 (*)[9]) m_pVipTable->UV_Gains_2[0]));
#endif
	fwif_colo_load_vip_table(m_pVipTable);
	Scaler_Load_VipTable_Custom(m_pVipTableCustom);
	//drvif_ODTable(m_pVipTable->ODtable_Coeff);
	fwif_color_regNRTable((DRV_NR_Item *)m_pVipTable->Manual_NR_Table);
	//drvif_color_DCRTable(m_pVipTable->DCR_TABLE);
	fwif_color_regDEdgeSmooth_Coef(m_pVipTable->D_EDGE_Smooth_Coef);
	fwif_color_regIEdgeSmooth_Coef(m_pVipTable->I_EDGE_Smooth_Coef);
	//drvif_color_reg_UV_Gains_Table((void *)((UINT16 (*)[0][9]) m_pVipTable->UV_Gains[0]));

	return TRUE;
}

bool xGetVipTableData(VIP_TABLE_TYPE tableType, int tableIdx,
		VIP_TABLE_TIMIMG_ENUM timing, VIP_TABLE_COLORSTD_ENUM color, void** pRetTableData, int *piRetTableDataLen)
{
	VIP_TABLE_SRC_ENUM vipSource;
	VIP_TABLE_DATA_STRUCT *pIndexTable = NULL;
	VIP_TABLE_DATA_STRUCT_EX *pIndexTableEx = NULL;
	int iIndexTableLen = 0;
	VIP_TABLE_DATA_STRUCT *pItem = NULL;
	VIP_TABLE_DATA_STRUCT_EX *pItemEx = NULL;
	void *pDefaultSrc = NULL, *pDefaultTiming = NULL, *pDefaultColorStd = NULL, *pMatch = NULL;
	int iDefaultSrc = 0, iDefaultTiming = 0, iDefaultColorStd = 0, iMatch = 0;
	int i;

	switch (tableType) {
		case VIP_TABLE_COLORDATA:
			pIndexTable = m_defaultColorDataTable;
			iIndexTableLen = VipPanel_GetColorDataTableSize();
			break;
		case VIP_TABLE_COLORFAC:
			pIndexTable = m_defaultColorFacTable;
			iIndexTableLen = VipPanel_GetColorFacTableSize();
			break;
		case VIP_TABLE_COLORTEMP:
			pIndexTable = m_defaultColorTempTable;
			iIndexTableLen = VipPanel_GetColorTempTableSize();
			break;
		case VIP_TABLE_PICMODE:
			pIndexTableEx = m_defaultPictureModeTable;
			iIndexTableLen = VipPanel_GetPictureModeTableSize();
			break;
		default:
			return false;
	}


	if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[tableType]) {
		SourceOption src;
		if (xGetSourceByIndex(&src, tableIdx) == true)
			vipSource = xGetVipSourceByOption(src);
		else // browser
			vipSource = VIP_SRC_VO_USB;
	} else
		vipSource = xGetVipSourceByOptionType((VIP_SOURCE_OPTION_TYPE)tableIdx);

	for (i = 0; i < iIndexTableLen; i++) {
		if (pIndexTable != NULL)
			pItem = &pIndexTable[i];
		else
			pItemEx = &pIndexTableEx[i];

		if (pItem != NULL) {
			if (pItem->source == VIP_SRC_DEFAULT)
				pDefaultSrc = pItem->tableData;

			if (pItem->source == vipSource) {
				if (pItem->timing == timing && pItem->color == color)
					pMatch = pItem->tableData;
				else if (pItem->timing == VIP_TIMIMG_DEFAULT && pItem->color == color)
					pDefaultTiming = pItem->tableData;
        			else if (pItem->timing == timing && pItem->color == VIP_COLORSTD_DEFAULT)
					pDefaultColorStd = pItem->tableData;
				else
					pDefaultSrc = pItem->tableData;
			}
		} else if (pItemEx != NULL) {
			if (pItemEx->source == VIP_SRC_DEFAULT) {
				pDefaultSrc = pItemEx->tableData;
        			iDefaultSrc = pItemEx->tableDataLen;
			}

			if (pItemEx->source == vipSource) {
				if (pItemEx->timing == timing && pItemEx->color == color) {
					pMatch = pItemEx->tableData;
					iMatch = pItemEx->tableDataLen;
        			} else if (pItemEx->timing == VIP_TIMIMG_DEFAULT && pItemEx->color == color) {
					pDefaultTiming = pItemEx->tableData;
					iDefaultTiming = pItemEx->tableDataLen;
        			} else if (pItemEx->timing == timing && pItemEx->color == VIP_COLORSTD_DEFAULT) {
					pDefaultColorStd = pItemEx->tableData;
					iDefaultColorStd = pItemEx->tableDataLen;
				} else {
					// replace default
					pDefaultSrc = pItemEx->tableData;
        				iDefaultSrc = pItemEx->tableDataLen;
				}
			}
		}
	}

	if (pMatch != NULL) {
		*pRetTableData = pMatch;
		if (piRetTableDataLen)
			*piRetTableDataLen = iMatch;
		return true;
	}

	if (pDefaultColorStd != NULL) {
		*pRetTableData = pDefaultColorStd;
		if (piRetTableDataLen)
			*piRetTableDataLen = iDefaultColorStd;
		return true;
	}

	if (pDefaultTiming != NULL) {
		*pRetTableData = pDefaultTiming;
		if (piRetTableDataLen)
			*piRetTableDataLen = iDefaultTiming;
		return true;
	}

	// if no default table is defined, use first table
	if (pDefaultSrc == NULL) {
		*pRetTableData = pDefaultSrc;
		if (piRetTableDataLen)
			*piRetTableDataLen = iDefaultSrc;
		return true;
	}

	*pRetTableData = pDefaultSrc;
	if (piRetTableDataLen)
		*piRetTableDataLen = iDefaultSrc;
	return true;
}

//int xGetTableIdx(SOURCE_TIMING_INFO *indexTable, int tableSize, VIP_SOURCE_OPTION_TYPE sourceType, VIP_TABLE_TIMIMG_ENUM timing, VIP_TABLE_COLORSTD_ENUM color)
// for search corresponding timing/colorstd table index in indextable
int xGetTableIdx(VIP_TABLE_TYPE tableType, SOURCE_TIMING_INFO *indexTable, int tableSize, SourceOption source, VIP_TABLE_TIMIMG_ENUM timing, VIP_TABLE_COLORSTD_ENUM color)
{
	int iSourceIdx = 0;
	int iCnt = 0, iTimimgDefaultIdx = -1, iColorDefaultIdx = -1;

	if (NULL == indexTable)
		return 0; // default

	if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[tableType]) {
		if (false == xGetSourceIndex(source, &iSourceIdx)) {
			if (source == SOURCE_PLAYBACK)
				iSourceIdx = m_iIndexSourceCnt[tableType] - 1; //last is for browser
			else
				iSourceIdx = 0;
		}
	} else {
		iSourceIdx = xGetSourceType(source);
	}

	// check other than source
	if (tableSize > m_iIndexSourceCnt[tableType]) {
		// check timing first
		for (iCnt = m_iIndexSourceCnt[tableType]; iCnt < tableSize; iCnt ++) {
			if (indexTable[iCnt].source == iSourceIdx) {
				if (indexTable[iCnt].timing == timing && indexTable[iCnt].color == color)
					return iCnt;

				// color match
				if (indexTable[iCnt].timing == VIP_TIMIMG_DEFAULT && indexTable[iCnt].color == color)
					iTimimgDefaultIdx = iCnt;

				// timing match
				if (indexTable[iCnt].timing == timing && indexTable[iCnt].color == VIP_COLORSTD_DEFAULT)
					iColorDefaultIdx = iCnt;
			}
		}
	}

	if (iTimimgDefaultIdx != -1)
		return iTimimgDefaultIdx;

	if (iColorDefaultIdx != -1)
		return iColorDefaultIdx;

	return (int)iSourceIdx; // default table index
}

int xGetTableAllocLength(VIP_TABLE_TYPE tableType, VIP_TABLE_DATA_STRUCT *pTable, int tableSize)
{
	// each source type + specific source + timing table
	int iCnt = 0, iAllocLen = m_iIndexSourceCnt[tableType];

	if (VIP_TABLE_INDEX_BY_SOURCE != m_indexType[tableType]) { // only source type will support different timing/colorstd
		for (iCnt = 0; iCnt < tableSize; iCnt ++) {
			if (pTable[iCnt].timing != VIP_TIMIMG_DEFAULT || pTable[iCnt].color != VIP_COLORSTD_DEFAULT)
				iAllocLen ++;
		}
	}
	return iAllocLen;
}

int xGetTableAllocLengthEx(VIP_TABLE_TYPE tableType, VIP_TABLE_DATA_STRUCT_EX *pTable, int tableSize)
{
	// each source type + specific source + timing table
	int iCnt = 0, iAllocLen = m_iIndexSourceCnt[tableType];

	if (VIP_TABLE_INDEX_BY_SOURCE != m_indexType[tableType]) { // only source type will support different timing/colorstd
		for (iCnt = 0; iCnt < tableSize; iCnt ++) {
			if (pTable[iCnt].timing != VIP_TIMIMG_DEFAULT || pTable[iCnt].color != VIP_COLORSTD_DEFAULT)
				iAllocLen ++;
		}
	}
	return iAllocLen;
}

int xGetTableAllocLengthOnlyByType(VIP_TABLE_TYPE tableType)
{
	VIP_TABLE_DATA_STRUCT *pTable = NULL;
	VIP_TABLE_DATA_STRUCT_EX *pTableEx = NULL;
	int iTableLen = 0, iAllocLen = VIP_SOURCE_TYPE_MAX_NUM;

	switch (tableType) {
		case VIP_TABLE_COLORDATA:
			pTable = m_defaultColorDataTable;
			iTableLen = VipPanel_GetColorDataTableSize();
			return xGetTableAllocLength(tableType, pTable, iTableLen);
		case VIP_TABLE_COLORFAC:
			pTable = m_defaultColorFacTable;
			iTableLen = VipPanel_GetColorFacTableSize();
			return xGetTableAllocLength(tableType, pTable, iTableLen);
		case VIP_TABLE_PICMODE:
			pTableEx = m_defaultPictureModeTable;
			iTableLen =  VipPanel_GetPictureModeTableSize();
			return xGetTableAllocLengthEx(tableType, pTableEx, iTableLen);
		case VIP_TABLE_COLORTEMP:
			pTable = m_defaultColorTempTable;
			iTableLen = VipPanel_GetColorTempTableSize();
			return xGetTableAllocLength(tableType, pTable, iTableLen);
		default:
			break;
	}

	return iAllocLen;
}


VIP_TABLE_SRC_ENUM xGetVipSourceByOptionType(VIP_SOURCE_OPTION_TYPE srcType)
{
	switch (srcType)
	{
	case VIP_SOURCE_TYPE_ATV:
		return VIP_SRC_ATV;
	case VIP_SOURCE_TYPE_AV:
		return VIP_SRC_AV;
	case VIP_SOURCE_TYPE_SV:
		return VIP_SRC_SV;
	case VIP_SOURCE_TYPE_YPP:
		return VIP_SRC_YPBPR;
	case VIP_SOURCE_TYPE_VGA:
		return VIP_SRC_VGA;
	case VIP_SOURCE_TYPE_HDMI:
	case VIP_SOURCE_TYPE_HDMI2:
	case VIP_SOURCE_TYPE_HDMI3:
		return VIP_SRC_HDMI;
	case VIP_SOURCE_TYPE_DTV:
		return VIP_SRC_VO;
	case VIP_SOURCE_TYPE_PLAYBACK:
		return VIP_SRC_VO_USB;

	default:
		break;
	}

	return VIP_SRC_DEFAULT;
}


VIP_TABLE_SRC_ENUM xGetVipSourceByOption(SourceOption source)
{
	switch (source)
	{
	case SOURCE_ATV1:
	case SOURCE_ATV2:
		return VIP_SRC_ATV;

	case SOURCE_AV1:
	case SOURCE_AV2:
	case SOURCE_AV3:
		return VIP_SRC_AV;

	case SOURCE_SV1:
	case SOURCE_SV2:
		return VIP_SRC_SV;

	case SOURCE_YPP1:
	case SOURCE_YPP2:
	case SOURCE_YPP3:
	case SOURCE_YPP4:
		return VIP_SRC_YPBPR;

	case SOURCE_VGA1:
	case SOURCE_VGA2:
		return VIP_SRC_VGA;

	case SOURCE_HDMI1:
	case SOURCE_HDMI2:
	case SOURCE_HDMI3:
	case SOURCE_HDMI4:
		return VIP_SRC_HDMI;

	case SOURCE_IDTV1:
	case SOURCE_DTV1:
	case SOURCE_DTV2:
		return VIP_SRC_VO;

	case SOURCE_PLAYBACK:
		return VIP_SRC_VO_USB;

	default:
		break;
	}

	return VIP_SRC_DEFAULT;
}

VIP_SOURCE_OPTION_TYPE xGetSourceType(SourceOption source)
{
	switch (source)
	{
	case SOURCE_ATV1:
	case SOURCE_ATV2:
		return VIP_SOURCE_TYPE_ATV;
	case SOURCE_AV1:
	case SOURCE_AV2:
	case SOURCE_AV3:
		return VIP_SOURCE_TYPE_AV;
	case SOURCE_SV1:
	case SOURCE_SV2:
		return VIP_SOURCE_TYPE_SV;
	case SOURCE_YPP1:
	case SOURCE_YPP2:
	case SOURCE_YPP3:
	case SOURCE_YPP4:
		return VIP_SOURCE_TYPE_YPP;
	case SOURCE_SCART1:
	case SOURCE_SCART2:
		return VIP_SOURCE_TYPE_SCART;
	case SOURCE_DTV1:
	case SOURCE_DTV2:
		return VIP_SOURCE_TYPE_DTV;
	case SOURCE_HDMI1:
		return VIP_SOURCE_TYPE_HDMI;
	case SOURCE_HDMI2:
		return VIP_SOURCE_TYPE_HDMI2;
	case SOURCE_HDMI3:
		return VIP_SOURCE_TYPE_HDMI3;
	case SOURCE_HDMI4:
		return VIP_SOURCE_TYPE_HDMI;
	case SOURCE_VGA1:
	case SOURCE_VGA2:
		return VIP_SOURCE_TYPE_VGA;
	case SOURCE_IDTV1:
		return VIP_SOURCE_TYPE_ATV;
	case SOURCE_PLAYBACK:
		return VIP_SOURCE_TYPE_PLAYBACK;
	default:
		break;
	}
	return VIP_SOURCE_TYPE_ATV; //default
}

SourceOption xGetSourceOption(UINT32 sourceFmt)
{
	switch (sourceFmt)
	{
	case TVD_INFMT_CVBS0_TUNER:
		return SOURCE_ATV1;

	case TVD_INFMT_CVBS1:
		return SOURCE_AV1;
	case TVD_INFMT_CVBS2:
		return SOURCE_AV2;

	case TVD_INFMT_SVIDEO0:
		return SOURCE_SV1;
	case TVD_INFMT_SVIDEO1:
		return SOURCE_SV2;

	case TVD_INFMT_YPbPr0:
		return SOURCE_YPP1;
	case TVD_INFMT_YPbPr1:
		return SOURCE_YPP2;
	case TVD_INFMT_YPbPr2:
		return SOURCE_YPP3;
	case TVD_INFMT_YPbPr3:
		return SOURCE_YPP4;

	case TVD_INFMT_SCART:
	case TVD_INFMT_SCART_CVBS:
	case TVD_INFMT_SCART_RGB:
		return SOURCE_SCART1;

	case TVD_INFMT_HDMI0:
		return SOURCE_HDMI1;
	case TVD_INFMT_HDMI1:
		return SOURCE_HDMI2;
	case TVD_INFMT_HDMI2:
		return SOURCE_HDMI3;
	case TVD_INFMT_HDMI3:
		return SOURCE_HDMI4;

	case TVD_INFMT_VGA0:
		return SOURCE_VGA1;
	case TVD_INFMT_VGA1:
		return SOURCE_VGA2;

	case TVD_INFMT_VODMA0:
		return SOURCE_DTV1;
	case TVD_INFMT_VODMA1:
		return SOURCE_PLAYBACK;
	default:
		break;
	}
	return SOURCE_ATV1; //default
}


VIP_SOURCE_OPTION_TYPE xGetSourceTypeFromVipSource(VIP_TABLE_SRC_ENUM vipSrc)
{
	switch (vipSrc)
	{
	case VIP_SRC_ATV:
		return VIP_SOURCE_TYPE_ATV;
	case VIP_SRC_VO:
		return VIP_SOURCE_TYPE_DTV;
	case VIP_SRC_AV:
		return VIP_SOURCE_TYPE_AV;
	case VIP_SRC_SV:
		return VIP_SOURCE_TYPE_SV;
	case VIP_SRC_HDMI:
		return VIP_SOURCE_TYPE_HDMI;
	case VIP_SRC_HDMI2:
		return VIP_SOURCE_TYPE_HDMI2;
	case VIP_SRC_HDMI3:
		return VIP_SOURCE_TYPE_HDMI3;
	case VIP_SRC_VGA:
		return VIP_SOURCE_TYPE_VGA;
	case VIP_SRC_YPBPR:
		return VIP_SOURCE_TYPE_YPP;
	case VIP_SRC_USB:
		return VIP_SOURCE_TYPE_PLAYBACK;

	default:
		break;
	}

	return VIP_SOURCE_TYPE_ATV; //default
}

bool xSourceControl_GetIndex(SourceOption source, int* retIndex)
{
	int i;
	for (i = 0; i < (sizeof(m_sourceList)/sizeof(m_sourceList[0])); i++) {
		if (m_sourceList[i] == source) {
			*retIndex = i;
			return TRUE;
		}
	}
	return FALSE;
}

bool xSourceControl_GetSourceByIdx(SourceOption *pRetSource, int index)
{
	if (index >= 0 && index < m_count) {
		*pRetSource = m_sourceList[index];
		return true;
	}
	//rtd_printk(KERN_DEBUG, TAG_NAME, "VipTable::SourceControl_GetSourceByIdx error! index = %d\n", index);
	*pRetSource = m_sourceList[0];
	return false;
}

SourceOption xGetCurSource()
{
	return SOURCE_HDMI1;//SetupClass::GetInstance()->GetSource();
}

void xInitSourceCount(SourceOption* sourceList, int count)
{
	int i;
	for (i = 0; i < count && i < SOURCE_MAX_NUM; i++)
		m_sourceList[i] = sourceList[i];
	m_count = count;
}

int xGetSourceCount()
{
	return m_count;
}

bool xGetSourceIndex(SourceOption source, int *iSourceIdx)
{
	return xSourceControl_GetIndex(source, iSourceIdx);
}

bool xGetSourceByIndex(SourceOption *source, int iSourceIdx)
{
	return xSourceControl_GetSourceByIdx(source, iSourceIdx);
}

VIP_TABLE_TIMIMG_ENUM xGetInputVipTiming(VIP_SOURCE_TIMING srcTiming)
{
	switch (srcTiming)
	{
	//CVBS
	case VIP_QUALITY_CVBS_NTSC:
	case VIP_QUALITY_CVBS_S_NTSC:
		return VIP_TIMIMG_VD_NTSC;
		break;
	case VIP_QUALITY_CVBS_PAL:
	case VIP_QUALITY_CVBS_S_PAL:
	case VIP_QUALITY_CVBS_PAL_M:
	case VIP_QUALITY_CVBS_S_PAL_M:
		return VIP_TIMIMG_VD_PAL;
		break;
	case VIP_QUALITY_CVBS_SECAN:
	case VIP_QUALITY_CVBS_S_SECAN:
		return VIP_TIMIMG_VD_SECAM;
		break;
	//TV
	case VIP_QUALITY_TV_NTSC:
		return VIP_TIMIMG_VD_NTSC;
		break;
	case VIP_QUALITY_TV_PAL:
	case VIP_QUALITY_TV_PAL_M:
		return VIP_TIMIMG_VD_PAL;
		break;
	case VIP_QUALITY_TV_SECAN:
		return VIP_TIMIMG_VD_SECAM;
		break;
      // YPbPr
	case VIP_QUALITY_YPbPr_480I:
	case VIP_QUALITY_YPbPr_576I:
	case VIP_QUALITY_YPbPr_480P:
	case VIP_QUALITY_YPbPr_576P:
		return VIP_TIMIMG_SD;
		break;
	case VIP_QUALITY_YPbPr_720P:
	case VIP_QUALITY_YPbPr_1080I:
	case VIP_QUALITY_YPbPr_1080P:
		return VIP_TIMIMG_HD;
		break;
	// HDMI
	case VIP_QUALITY_HDMI_480I:
	case VIP_QUALITY_HDMI_576I:
	case VIP_QUALITY_HDMI_480P:
	case VIP_QUALITY_HDMI_576P:
		return VIP_TIMIMG_SD;
		break;
	case VIP_QUALITY_HDMI_720P:
	case VIP_QUALITY_HDMI_1080I:
	case VIP_QUALITY_HDMI_1080P:
		return VIP_TIMIMG_HD;
		break;
	case VIP_QUALITY_HDMI_4k2kI_30:
	case VIP_QUALITY_HDMI_4k2kP_30:
	case VIP_QUALITY_HDMI_4k2kP_60:
		return VIP_TIMIMG_4K2K;
		break;
	// DTV
	case VIP_QUALITY_DTV_480I:
	case VIP_QUALITY_DTV_576I:
	case VIP_QUALITY_DTV_480P:
	case VIP_QUALITY_DTV_576P:
		return VIP_TIMIMG_SD;
		break;
	case VIP_QUALITY_DTV_720P:
	case VIP_QUALITY_DTV_1080I:
	case VIP_QUALITY_DTV_1080P:
		return VIP_TIMIMG_HD;
		break;
	case VIP_QUALITY_DTV_4k2kI_30:
	case VIP_QUALITY_DTV_4k2kP_30:
	case VIP_QUALITY_DTV_4k2kP_60:
		return VIP_TIMIMG_4K2K;
		break;
	// PVR
	case VIP_QUALITY_PVR_480I:
	case VIP_QUALITY_PVR_576I:
	case VIP_QUALITY_PVR_480P:
	case VIP_QUALITY_PVR_576P:
		return VIP_TIMIMG_SD;
		break;
	case VIP_QUALITY_PVR_720P:
	case VIP_QUALITY_PVR_1080I:
	case VIP_QUALITY_PVR_1080P:
		return VIP_TIMIMG_HD;
		break;
	case VIP_QUALITY_PVR_4k2kI_30:
	case VIP_QUALITY_PVR_4k2kP_30:
	case VIP_QUALITY_PVR_4k2kP_60:
		return VIP_TIMIMG_4K2K;
		break;
	case VIP_QUALITY_DolbyHDR_HDMI_4k2kP:
	case VIP_QUALITY_DolbyHDR_DTV_4k2kP:
	case VIP_QUALITY_DolbyHDR_PVR_4k2kP:
		return VIP_TIMIMG_DolbyHDR_4K2K;
		break;
	default:
		break;
	}

	return VIP_TIMIMG_DEFAULT;

}

VIP_TABLE_TIMIMG_ENUM xGetCurVipTiming()
{
	UINT16 input_src_timing;
	VIP_SOURCE_TIMING srcTiming;

	input_src_timing = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);

	srcTiming = fwif_vip_source_check(3, 0);

	return xGetInputVipTiming(srcTiming);
}

void* xGetIndexTableItem(VIP_TABLE_TYPE tableType, int iIdx)
{
	switch (tableType) {
		case VIP_TABLE_COLORDATA:
			return (void*)&(m_defaultColorDataTable[iIdx]);
		case VIP_TABLE_COLORFAC:
			return (void*)&(m_defaultColorFacTable[iIdx]);
		case VIP_TABLE_PICMODE:
			return (void*)&(m_defaultPictureModeTable[iIdx]);
		case VIP_TABLE_COLORTEMP:
			return (void*)&(m_defaultColorTempTable[iIdx]);
		default:
			break;
	}
	return NULL;
}


void* xGetVipTableDataItem(VIP_TABLE_TYPE tableType, int iIdx)
{
	switch (tableType) {
		case VIP_TABLE_COLORDATA:
			return (void*)m_defaultColorDataTable[iIdx].tableData;
		case VIP_TABLE_COLORFAC:
			return (void*)m_defaultColorFacTable[iIdx].tableData;
		case VIP_TABLE_PICMODE:
			return (void*)m_defaultPictureModeTable[iIdx].tableData;
		case VIP_TABLE_COLORTEMP:
			return (void*)m_defaultColorTempTable[iIdx].tableData;
		default:
			break;
	}

	return NULL;
}

int	xGetIndexTableLength(VIP_TABLE_TYPE tableType)
{
	switch (tableType) {
		case VIP_TABLE_COLORDATA:
			return VipPanel_GetColorDataTableSize();
		case VIP_TABLE_COLORFAC:
			return VipPanel_GetColorFacTableSize();
		case VIP_TABLE_PICMODE:
			return VipPanel_GetPictureModeTableSize();
		case VIP_TABLE_COLORTEMP:
			return VipPanel_GetColorTempTableSize();
		default:
			break;
	}

	return 0;
}

//-----------------------------------------------------------------------------
//	Save functions: should be overloaded
//
//
//-----------------------------------------------------------------------------
//LewisLee modify picture index error, double check later
bool xSavePicModeTable()
{
#if 0
	VIPTABLE_SAVE_HEADER header;

	FILE *pFile = fopen(VIPTABLE_SAVE_PICMODE, "w+");
	if (pFile) {
		UINT16 iFileSize = sizeof(PIC_MODE_DATA) * m_picModeTableSize
				+ sizeof(SOURCE_TIMING_INFO) * m_picModeTableSize + sizeof(m_pictureMode) * m_picModeTableSize;

		void* buffer = vip_malloc(iFileSize);
		if(buffer == NULL)
			{
				printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
				return false;
			}
		UINT8* bufferIdx = (UINT8*)buffer;
		memcpy(bufferIdx, m_picModeTable, sizeof(PIC_MODE_DATA) * m_picModeTableSize);
		bufferIdx += sizeof(PIC_MODE_DATA) * m_picModeTableSize;
		memcpy(bufferIdx, m_picModeTableIdx, sizeof(SOURCE_TIMING_INFO) * m_picModeTableSize);
		bufferIdx += sizeof(SOURCE_TIMING_INFO) * m_picModeTableSize;
		memcpy(bufferIdx, m_pictureMode, sizeof(m_pictureMode) * m_picModeTableSize);

		// count md5 key
		xGetMD5Value(buffer, iFileSize, (UINT8*)header.md5check);

		header.iFileSize = iFileSize;
		header.iArrayLen = m_picModeTableSize;

		fwrite(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
		fwrite(buffer, 1, iFileSize, pFile);

		vip_free(buffer);
		fclose(pFile);
		pFile = NULL;

		// mark it because system will hang-up when swtiching AV mode continuously
		//system("cp -f /usr/local/etc/dvdplayer/vipTable/picMode /usr/local/etc/dvdplayer/vipTable/picMode2");//for backup picure mode files mechanism
		return TRUE;
	}
#endif
	return FALSE;
}

bool xSaveColorDataTable()
{
#if 0
	VIPTABLE_SAVE_HEADER header;

	FILE *pFile = fopen(VIPTABLE_SAVE_COLORDATA, "w+");
	if (pFile) {
		UINT16 iFileSize = sizeof(StructColorDataType) * m_colorDataTableSize
				+ sizeof(SOURCE_TIMING_INFO) * m_colorDataTableSize;

		void* buffer = vip_malloc(iFileSize);
		if(buffer == NULL)
			{
				fclose(pFile);
				printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
				return false;
			}
		UINT8* bufferIdx = (UINT8*)buffer;
		memcpy(bufferIdx, m_colorDataTable, sizeof(StructColorDataType) * m_colorDataTableSize);
		bufferIdx += sizeof(StructColorDataType) * m_colorDataTableSize;
		memcpy(bufferIdx, m_colorDataTableIdx, sizeof(SOURCE_TIMING_INFO) * m_colorDataTableSize);

		// count md5 key
		xGetMD5Value(buffer, iFileSize, (UINT8*)header.md5check);

		header.iFileSize = iFileSize;
		header.iArrayLen = m_colorDataTableSize;

		fwrite(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
		fwrite(buffer, 1, iFileSize, pFile);

		vip_free(buffer);
		fclose(pFile);
		pFile = NULL;
		return TRUE;
	}
#endif
	return FALSE;
}

bool xSaveColorTempTable()
{
#if 0
	VIPTABLE_SAVE_HEADER header;

	FILE *pFile = fopen(VIPTABLE_SAVE_COLORTEMP, "w+");
	if (pFile) {
		UINT16 iFileSize = sizeof(COLOR_TEMP_DATA) * m_colorTempDataSize
				+ sizeof(SOURCE_TIMING_INFO) * m_colorTempDataSize;

		void* buffer = vip_malloc(iFileSize);
		if(buffer == NULL)
			{
			fclose(pFile);
			printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
				return false;
			}
		UINT8* bufferIdx = (UINT8*)buffer;
		memcpy(bufferIdx, m_colorTempData, sizeof(COLOR_TEMP_DATA) * m_colorTempDataSize);
		bufferIdx += sizeof(COLOR_TEMP_DATA) * m_colorTempDataSize;
		memcpy(bufferIdx, m_colorDataTableIdx, sizeof(SOURCE_TIMING_INFO) * m_colorTempDataSize);

		// count md5 key
		xGetMD5Value(buffer, iFileSize, (UINT8*)header.md5check);

		header.iFileSize = iFileSize;
		header.iArrayLen = m_colorTempDataSize;

		fwrite(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
		fwrite(buffer, 1, iFileSize, pFile);

		vip_free(buffer);
		fclose(pFile);
		pFile = NULL;
		return TRUE;
	}
#endif
	return FALSE;
}

bool xSaveColorFacModeTable()
{
#if 0
	VIPTABLE_SAVE_HEADER header;

	FILE *pFile = fopen(VIPTABLE_SAVE_COLORFACMODE, "w+");
	if (pFile) {
		UINT16 iFileSize = sizeof(StructColorDataFacModeType) * m_colorFacModeTableSize
				+ sizeof(SOURCE_TIMING_INFO) * m_colorFacModeTableSize;

		void* buffer = vip_malloc(iFileSize);
		if(buffer == NULL)
			{
				fclose(pFile);
				rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
				return false;
			}
		UINT8* bufferIdx = (UINT8*)buffer;
		memcpy(bufferIdx, m_colorFacModeTable, sizeof(StructColorDataFacModeType) * m_colorFacModeTableSize);
		bufferIdx += sizeof(StructColorDataFacModeType) * m_colorFacModeTableSize;
		memcpy(bufferIdx, m_colorFacModeTableIdx, sizeof(SOURCE_TIMING_INFO) * m_colorFacModeTableSize);

		// count md5 key
		xGetMD5Value(buffer, iFileSize, (UINT8*)header.md5check);

		header.iFileSize = iFileSize;
		header.iArrayLen = m_colorFacModeTableSize;

		fwrite(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
		fwrite(buffer, 1, iFileSize, pFile);

		vip_free(buffer);
		fclose(pFile);
		pFile = NULL;
		return TRUE;
	}
#endif
	return FALSE;
}


//-----------------------------------------------------------------------------
//	Load functions: should be overloaded
//
//
//-----------------------------------------------------------------------------
void xLoadDefaultPicModeTable()
{
	SLR_PICTURE_MODE_DATA* pTableData = NULL;
	int iCnt = 0, iTableIdx = 0, iTableDataLen = 0;

	m_picModeTableSize = xGetTableAllocLengthOnlyByType(VIP_TABLE_PICMODE);

	if (m_picModeTable != NULL)
		vip_free(m_picModeTable);
	m_picModeTable = (PIC_MODE_DATA*)vip_malloc(sizeof(PIC_MODE_DATA) * m_picModeTableSize);
	if (m_picModeTable == NULL) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}

	if (m_picModeTableIdx != NULL)
		vip_free(m_picModeTableIdx);
	m_picModeTableIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_picModeTableSize);
	if (m_picModeTableIdx == NULL) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}

	// default table

	for (iCnt = 0; iCnt < m_iIndexSourceCnt[VIP_TABLE_PICMODE]; iCnt ++) {	//iCnt = source type

		xGetVipTableData(VIP_TABLE_PICMODE, iCnt, VIP_TIMIMG_DEFAULT, VIP_COLORSTD_DEFAULT, (void**)(&pTableData), &iTableDataLen);

		// copy by picture mode, if some mode is not defined in panel file, use it as default, or copy first mode
		if (pTableData) {
			//memcpy(&m_picModeTable[iCnt], pTable, sizeof(PIC_MODE_DATA));
			int iCntPicMode = 0, iCntTableIdx = 0;
			for (iCntPicMode = 0; iCntPicMode < PICTURE_MODE_MAX; iCntPicMode ++) {	//iCntPicMode = picture mode
				bool bFound = FALSE;
				for (iCntTableIdx = 0; iCntTableIdx < iTableDataLen; iCntTableIdx ++) {	//iTableDataLen = number of column in m_defaultPictureModeSet,...etc.
					if (iCntPicMode == pTableData[iCntTableIdx].mode) {
						memcpy(&(m_picModeTable[iCnt].picMode[iCntPicMode]), &(pTableData[iCntTableIdx]), sizeof(SLR_PICTURE_MODE_DATA));
						bFound = TRUE;
						break;
					}
				}

				if (bFound == FALSE) {	// copy first pic mode data (should be user mode)
					memcpy(&(m_picModeTable[iCnt].picMode[iCntPicMode]), &(pTableData[0]), sizeof(SLR_PICTURE_MODE_DATA));
				}
			}
		} else
			memset(&m_picModeTable[iCnt], 0, sizeof(PIC_MODE_DATA));

		//m_picModeTableIdx[iCnt].source = iCnt;//source type or SourceOption
		if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_PICMODE]) {
			SourceOption src;
			if (xGetSourceByIndex(&src, iCnt) == true)
				m_picModeTableIdx[iCnt].source = src;
			else // browser
				m_picModeTableIdx[iCnt].source = SOURCE_PLAYBACK;
		} else
			m_picModeTableIdx[iCnt].source = (VIP_SOURCE_OPTION_TYPE)iCnt;

		//m_picModeTableIdx[iCnt].timing = VIP_TIMIMG_DEFAULT;
		m_picModeTableIdx[iCnt].color = VIP_COLORSTD_DEFAULT;
	}

	iTableIdx = m_iIndexSourceCnt[VIP_TABLE_PICMODE];

	// other timing table
	if (VIP_TABLE_INDEX_BY_SOURCE != m_indexType[VIP_TABLE_PICMODE])  {
		for (iCnt = 0; iCnt < xGetIndexTableLength(VIP_TABLE_PICMODE); iCnt ++) {
			VIP_TABLE_DATA_STRUCT_EX *pIndexTableItem = (VIP_TABLE_DATA_STRUCT_EX*) xGetIndexTableItem(VIP_TABLE_PICMODE, iCnt);
			if (pIndexTableItem != NULL) {
				if (pIndexTableItem->timing != VIP_TIMIMG_DEFAULT || pIndexTableItem->color != VIP_COLORSTD_DEFAULT) {

					SLR_PICTURE_MODE_DATA* pTableData = (SLR_PICTURE_MODE_DATA*) xGetVipTableDataItem(VIP_TABLE_PICMODE, iCnt);
					if (pTableData != NULL) {
						int iCntPicMode = 0, iCntTableIdx = 0;
						for (iCntPicMode = 0; iCntPicMode < PICTURE_MODE_MAX; iCntPicMode ++) {
							bool bFound = FALSE;
							for (iCntTableIdx = 0; iCntTableIdx < iTableDataLen; iCntTableIdx ++) {
								if (iCntPicMode == pTableData[iCntTableIdx].mode) {
									memcpy(&(m_picModeTable[iTableIdx].picMode[iCntPicMode]), &(pTableData[iCntTableIdx]), sizeof(SLR_PICTURE_MODE_DATA));
									bFound = TRUE;
									break;
								}
							}

							if (bFound == FALSE) {	// copy first pic mode data (should be user mode)
								memcpy(&(m_picModeTable[iTableIdx].picMode[iCntPicMode]), &(pTableData[0]), sizeof(SLR_PICTURE_MODE_DATA));
							}
						}

						m_picModeTableIdx[iTableIdx].source = xGetSourceTypeFromVipSource((VIP_TABLE_SRC_ENUM)pIndexTableItem->source);


						m_picModeTableIdx[iTableIdx].timing = (VIP_TABLE_TIMIMG_ENUM)pIndexTableItem->timing;
						m_picModeTableIdx[iTableIdx].color = (VIP_TABLE_COLORSTD_ENUM)pIndexTableItem->color;
						iTableIdx ++;
					}
				}
			}
		}
	}
}


void xLoadDefaultColorDataTable()
{
	void* pTable = NULL;
	int iCnt = 0, iTableIdx = 0;

	m_colorDataTableSize = xGetTableAllocLengthOnlyByType(VIP_TABLE_COLORDATA);

	if (NULL != m_colorDataTable)
		vip_free(m_colorDataTable);
	m_colorDataTable = (StructColorDataType*)vip_malloc(sizeof(StructColorDataType) * m_colorDataTableSize);
	if (m_colorDataTable == NULL) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}
	if (NULL != m_colorDataTableIdx)
		vip_free(m_colorDataTableIdx);
	m_colorDataTableIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_colorDataTableSize);
	if (m_colorDataTableIdx == NULL) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}

	for (iCnt = 0; iCnt < m_iIndexSourceCnt[VIP_TABLE_COLORDATA]; iCnt ++) {

		xGetVipTableData(VIP_TABLE_COLORDATA, iCnt, VIP_TIMIMG_DEFAULT, VIP_COLORSTD_DEFAULT, &pTable, NULL);

		if (pTable)
			memcpy(&m_colorDataTable[iCnt], pTable, sizeof(StructColorDataType));
		else
			memset(&m_colorDataTable[iCnt], 0, sizeof(StructColorDataType));

		//m_colorDataTableIdx[iCnt].source = (VIP_SOURCE_OPTION_TYPE)iCnt;
		if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_COLORDATA]) {
			SourceOption src;
			if (xGetSourceByIndex(&src, iCnt) == true)
				m_colorDataTableIdx[iCnt].source = src;
			else // browser
				m_colorDataTableIdx[iCnt].source = SOURCE_PLAYBACK;
		} else
			m_colorDataTableIdx[iCnt].source = (VIP_SOURCE_OPTION_TYPE)iCnt;

		m_colorDataTableIdx[iCnt].timing = VIP_TIMIMG_DEFAULT;
		m_colorDataTableIdx[iCnt].color = VIP_COLORSTD_DEFAULT;
	}

	iTableIdx = m_iIndexSourceCnt[VIP_TABLE_COLORDATA];

	// other timing/colorstd table
	if (VIP_TABLE_INDEX_BY_SOURCE != m_indexType[VIP_TABLE_COLORDATA])  {
		for (iCnt = 0; iCnt < xGetIndexTableLength(VIP_TABLE_COLORDATA); iCnt ++) {
			VIP_TABLE_DATA_STRUCT *pIndexTableItem = (VIP_TABLE_DATA_STRUCT*) xGetIndexTableItem(VIP_TABLE_COLORDATA, iCnt);
			if (pIndexTableItem != NULL) {
				if (pIndexTableItem->timing != VIP_TIMIMG_DEFAULT || pIndexTableItem->color != VIP_COLORSTD_DEFAULT) {

					StructColorDataType* pTableData = (StructColorDataType*) xGetVipTableDataItem(VIP_TABLE_COLORDATA, iCnt);
					if (pTableData != NULL) {
						memcpy(&m_colorDataTable[iTableIdx], pTableData, sizeof(StructColorDataType));
						m_colorDataTableIdx[iTableIdx].source = xGetSourceTypeFromVipSource((VIP_TABLE_SRC_ENUM)pIndexTableItem->source);
						m_colorDataTableIdx[iTableIdx].timing = (VIP_TABLE_TIMIMG_ENUM)pIndexTableItem->timing;
						m_colorDataTableIdx[iTableIdx].color = (VIP_TABLE_COLORSTD_ENUM)pIndexTableItem->color;

						iTableIdx ++;
					}
				}
			}
		}
	}
}

void xLoadDefaultColorTempTable()
{
	void* pTable = NULL;
	int iCnt = 0, iTableIdx = 0;

	m_colorTempDataSize = xGetTableAllocLengthOnlyByType(VIP_TABLE_COLORTEMP);

	if (NULL != m_colorTempData)
		vip_free(m_colorTempData);
	m_colorTempData = (COLOR_TEMP_DATA*)vip_malloc(sizeof(COLOR_TEMP_DATA) * m_colorTempDataSize);

	// need to check if malloc successful, added by ghyu
	if (NULL == m_colorTempData) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}

	if (NULL != m_colorTempDataIdx)
		vip_free(m_colorTempDataIdx);
	m_colorTempDataIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_colorTempDataSize);

	// need to check if malloc successful, added by ghyu
	if (NULL == m_colorTempDataIdx) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}

	for (iCnt = 0; iCnt < m_iIndexSourceCnt[VIP_TABLE_COLORTEMP]; iCnt ++) {
		xGetVipTableData(VIP_TABLE_COLORTEMP, iCnt, VIP_TIMIMG_DEFAULT, VIP_COLORSTD_DEFAULT, &pTable, NULL);

		if (pTable)
			memcpy(&m_colorTempData[iCnt], pTable, sizeof(COLOR_TEMP_DATA));
		else
			memset(&m_colorTempData[iCnt], 0, sizeof(COLOR_TEMP_DATA));

		if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_COLORTEMP]) {
			SourceOption src;
			if (xGetSourceByIndex(&src, iCnt) == true)
				m_colorTempDataIdx[iCnt].source = src;
			else // browser
				m_colorTempDataIdx[iCnt].source = SOURCE_PLAYBACK;
		} else
			m_colorTempDataIdx[iCnt].source = (VIP_SOURCE_OPTION_TYPE)iCnt;

		m_colorTempDataIdx[iCnt].timing = VIP_TIMIMG_DEFAULT;
		m_colorTempDataIdx[iCnt].color = VIP_COLORSTD_DEFAULT;
	}

	iTableIdx = m_iIndexSourceCnt[VIP_TABLE_COLORTEMP];

	// other timing table
	if (VIP_TABLE_INDEX_BY_SOURCE != m_indexType[VIP_TABLE_COLORTEMP]) {

		for (iCnt = 0; iCnt < xGetIndexTableLength(VIP_TABLE_COLORTEMP); iCnt ++) {
			VIP_TABLE_DATA_STRUCT *pIndexTableItem = (VIP_TABLE_DATA_STRUCT*) xGetIndexTableItem(VIP_TABLE_COLORTEMP, iCnt);
			if (pIndexTableItem != NULL) {
				if (pIndexTableItem->timing != VIP_TIMIMG_DEFAULT || pIndexTableItem->color != VIP_COLORSTD_DEFAULT) {

					COLOR_TEMP_DATA* pTableData = (COLOR_TEMP_DATA*) xGetVipTableDataItem(VIP_TABLE_COLORTEMP, iCnt);
					if (pTableData != NULL) {
						memcpy(&m_colorTempData[iTableIdx], pTableData, sizeof(COLOR_TEMP_DATA));

						m_colorTempDataIdx[iTableIdx].source = xGetSourceTypeFromVipSource((VIP_TABLE_SRC_ENUM)pIndexTableItem->source);
						m_colorTempDataIdx[iTableIdx].timing = (VIP_TABLE_TIMIMG_ENUM)pIndexTableItem->timing;
						m_colorTempDataIdx[iTableIdx].color = (VIP_TABLE_COLORSTD_ENUM)pIndexTableItem->color;

						iTableIdx ++;
					}
				}
			}
		}
	}
}

void xLoadDefaultColorFacModeTable()
{
	void* pTable = NULL;
	int iCnt = 0, iTableIdx = 0;

	m_colorFacModeTableSize = xGetTableAllocLengthOnlyByType(VIP_TABLE_COLORFAC);
	if (NULL != m_colorFacModeTable)
		vip_free(m_colorFacModeTable);

	m_colorFacModeTable = (StructColorDataFacModeType*)vip_malloc(sizeof(StructColorDataFacModeType) * m_colorFacModeTableSize);
	if (m_colorFacModeTable == NULL) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}

	if (NULL != m_colorFacModeTableIdx)
		vip_free(m_colorFacModeTableIdx);

	m_colorFacModeTableIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_colorFacModeTableSize);
	if (m_colorFacModeTableIdx == NULL) {
		rtd_printk(KERN_ERR, TAG_NAME, "[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
		return;
	}

	for (iCnt = 0; iCnt < m_iIndexSourceCnt[VIP_TABLE_COLORFAC]; iCnt ++) {

		xGetVipTableData(VIP_TABLE_COLORFAC, iCnt, VIP_TIMIMG_DEFAULT, VIP_COLORSTD_DEFAULT, &pTable, NULL);

		if (pTable)
			memcpy(&m_colorFacModeTable[iCnt], pTable, sizeof(StructColorDataFacModeType));
		else
			memset(&m_colorFacModeTable[iCnt], 0, sizeof(StructColorDataFacModeType));

		if (VIP_TABLE_INDEX_BY_SOURCE == m_indexType[VIP_TABLE_COLORFAC]) {
			SourceOption src;
			if (xGetSourceByIndex(&src, iCnt) == true)
				m_colorFacModeTableIdx[iCnt].source = src;
			else // browser
				m_colorFacModeTableIdx[iCnt].source = SOURCE_PLAYBACK;
		} else
			m_colorFacModeTableIdx[iCnt].source = (VIP_SOURCE_OPTION_TYPE)iCnt;

		m_colorFacModeTableIdx[iCnt].timing = VIP_TIMIMG_DEFAULT;
		m_colorFacModeTableIdx[iCnt].color = VIP_COLORSTD_DEFAULT;
	}

	iTableIdx = m_iIndexSourceCnt[VIP_TABLE_COLORFAC];

	// other timing table
	if (VIP_TABLE_INDEX_BY_SOURCE != m_indexType[VIP_TABLE_COLORFAC]) {
		for (iCnt = 0; iCnt < xGetIndexTableLength(VIP_TABLE_COLORFAC); iCnt ++) {
			VIP_TABLE_DATA_STRUCT *pIndexTableItem = (VIP_TABLE_DATA_STRUCT*) xGetIndexTableItem(VIP_TABLE_COLORFAC, iCnt);
			if (pIndexTableItem != NULL) {
				if (pIndexTableItem->timing != VIP_TIMIMG_DEFAULT || pIndexTableItem->color != VIP_COLORSTD_DEFAULT) {
					StructColorDataFacModeType* pTableData = (StructColorDataFacModeType*) xGetVipTableDataItem(VIP_TABLE_COLORFAC, iCnt);
					if (pTableData != NULL) {
						memcpy(&m_colorFacModeTable[iTableIdx], pTableData, sizeof(StructColorDataFacModeType));
						m_colorFacModeTableIdx[iTableIdx].source = xGetSourceTypeFromVipSource((VIP_TABLE_SRC_ENUM)pIndexTableItem->source);
						m_colorFacModeTableIdx[iTableIdx].timing = (VIP_TABLE_TIMIMG_ENUM)pIndexTableItem->timing;
						m_colorFacModeTableIdx[iTableIdx].color = (VIP_TABLE_COLORSTD_ENUM)pIndexTableItem->color;

						iTableIdx ++;
					}
				}
			}
		}
	}
}

//LewisLee modify picture index error, double check later
void xLoadPicModeTable()
{
#if 0
	void* buffer = NULL;
	char* pBufIdx = NULL;
	int iReadBytes = 0;

	FILE *pFile = NULL;

	pFile = fopen(VIPTABLE_SAVE_PICMODE, "r");
	if (NULL == pFile) {
		goto restore;
	}

	VIPTABLE_SAVE_HEADER header;
	fread(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
	if (header.iFileSize <= 0 || header.iArrayLen <= 0) {
		goto restore;
	}

	buffer = vip_malloc(header.iFileSize);
	if(buffer == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
			return ;
		}
	iReadBytes = fread(buffer, 1, header.iFileSize, pFile);
	if (iReadBytes != (int)header.iFileSize)
		goto restore;

	UINT8 md5[16];
	xGetMD5Value(buffer, iReadBytes, (UINT8*)md5);

	if (memcmp(md5, header.md5check, 16) != 0) {
		printk("md5 check error\n");
		goto restore;
	}
		goto pass;
restore:
	pFile = fopen(VIPTABLE_SAVE_PICMODE_2, "r");
	if (NULL == pFile) {
		goto load_fail;
	}

	if (buffer != NULL) {
		vip_free(buffer);
		buffer = NULL;
	}

	fread(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
	if (header.iFileSize <= 0 || header.iArrayLen <= 0) {
		goto load_fail;
	}

	buffer = vip_malloc(header.iFileSize);
	if(buffer == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
			return ;
		}
	iReadBytes = fread(buffer, 1, header.iFileSize, pFile);
	if (iReadBytes != (int)header.iFileSize){
		goto load_fail;
	}

	xGetMD5Value(buffer, iReadBytes, (UINT8*)md5);

	if (memcmp(md5, header.md5check, 16) != 0) {
		printk("md5 check error\n");
		goto load_fail;
	}

pass:

	pBufIdx = (char*)buffer;
	m_picModeTableSize = header.iArrayLen;

	m_picModeTable = (PIC_MODE_DATA*)vip_malloc(sizeof(PIC_MODE_DATA) * m_picModeTableSize);
	if(m_picModeTable == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
			return ;
		}
	m_picModeTableIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_picModeTableSize);
	if(m_picModeTableIdx == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
			return ;
		}
	memcpy(m_picModeTable, pBufIdx, sizeof(PIC_MODE_DATA) * m_picModeTableSize);
	pBufIdx += sizeof(PIC_MODE_DATA) * m_picModeTableSize;

	memcpy(m_picModeTableIdx, pBufIdx, sizeof(SOURCE_TIMING_INFO) * m_picModeTableSize);
	pBufIdx += sizeof(SOURCE_TIMING_INFO) * m_picModeTableSize;

	if (m_pictureMode!=NULL){
		vip_free(m_pictureMode);
	}
	m_pictureMode = (PICTURE_MODE*)vip_malloc(sizeof(m_pictureMode) * m_picModeTableSize);
	if(m_pictureMode == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] can't alloc memory\n", __FILE__, __LINE__);
			return ;
		}
	memcpy(m_pictureMode, pBufIdx, sizeof(m_pictureMode) * m_picModeTableSize);
	fclose(pFile);

	vip_free(buffer);
	return;

load_fail:
	if (pFile != NULL)
		fclose(pFile);

	if (buffer != NULL) {
		vip_free(buffer);
		buffer = NULL;
	}
#endif
	xLoadDefaultPicModeTable();
}

void xLoadColorDataTable()
{
#if 0
	void* buffer = NULL;
	char* pBufIdx = NULL;
	int iReadBytes = 0;
	FILE *pFile = NULL;

	pFile = fopen(VIPTABLE_SAVE_COLORDATA, "r");
	if (NULL == pFile) {
		goto load_fail;
	}

	VIPTABLE_SAVE_HEADER header;
	fread(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
	if (header.iFileSize <= 0 || header.iArrayLen <= 0) {
		goto load_fail;
	}

	buffer = vip_malloc(header.iFileSize);
	if(buffer == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
			return ;
		}
	iReadBytes = fread(buffer, 1, header.iFileSize, pFile);
	if (iReadBytes != (int)header.iFileSize)
		goto load_fail;

	UINT8 md5[16];
	xGetMD5Value(buffer, iReadBytes, (UINT8*)md5);

	if (memcmp(md5, header.md5check, 16) != 0) {
		printk("md5 check error\n");
		goto load_fail;
	}

	pBufIdx = (char*)buffer;
	m_colorDataTableSize = header.iArrayLen;
	if (m_colorDataTableSize <= 0)
		goto load_fail;

	m_colorDataTable = (StructColorDataType*)vip_malloc(sizeof(StructColorDataType) * m_colorDataTableSize);
	if(m_colorDataTable == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
			return ;
		}
	m_colorDataTableIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_colorDataTableSize);
		if(m_colorDataTableIdx == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
			return ;
		}
	memcpy(m_colorDataTable, pBufIdx, sizeof(StructColorDataType) * m_colorDataTableSize);
	pBufIdx += sizeof(StructColorDataType) * m_colorDataTableSize;

	memcpy(m_colorDataTableIdx, pBufIdx, sizeof(SOURCE_TIMING_INFO) * m_colorDataTableSize);
	pBufIdx += sizeof(SOURCE_TIMING_INFO) * m_colorDataTableSize;

	fclose(pFile);
	vip_free(buffer);

	return;

load_fail:
	if (pFile != NULL)
		fclose(pFile);

	if (buffer != NULL) {
		vip_free(buffer);
		buffer = NULL;
	}
#endif
	xLoadDefaultColorDataTable();
}

void xLoadColorTempTable()
{
#if 0
	void* buffer = NULL;
	char* pBufIdx = NULL;
	int iReadBytes = 0;

	FILE *pFile = NULL;

	pFile = fopen(VIPTABLE_SAVE_COLORTEMP, "r");

	if (NULL == pFile) {
		goto load_fail;
	}

	VIPTABLE_SAVE_HEADER header;
	fread(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
	if (header.iFileSize <= 0 || header.iArrayLen <= 0) {
		goto load_fail;
	}

	buffer = vip_malloc(header.iFileSize);
		if(buffer == NULL)
		{
			fclose(pFile);
			printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
			return ;
		}

	iReadBytes = fread(buffer, 1, header.iFileSize, pFile);
	if (iReadBytes != (int)header.iFileSize)
		goto load_fail;

	UINT8 md5[16];
	xGetMD5Value(buffer, iReadBytes, (UINT8*)md5);

	if (memcmp(md5, header.md5check, 16) != 0) {
		printk("md5 check error\n");
		goto load_fail;
	}

	pBufIdx = (char*)buffer;
	m_colorTempDataSize = header.iArrayLen;

	m_colorTempData = (COLOR_TEMP_DATA*)vip_malloc(sizeof(COLOR_TEMP_DATA) * m_colorTempDataSize);
	if(m_colorTempData == NULL)
	{
		fclose(pFile);
		vip_free(buffer); //klocwork-1017, 111
		printk("[%s:%d] alloc memory failed\n", __FILE__, __LINE__);
		return ;
	}
	m_colorTempDataIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_colorTempDataSize);
	if(m_colorTempDataIdx == NULL)
	{
		fclose(pFile);
		vip_free(buffer); //klocwork-1017, 111
		printk("[%s:%d] alloc memory failed\n", __FILE__, __LINE__);
		return ;
	}
	memcpy(m_colorTempData, pBufIdx, sizeof(COLOR_TEMP_DATA) * m_colorTempDataSize);
	pBufIdx += sizeof(COLOR_TEMP_DATA) * m_colorTempDataSize;

	memcpy(m_colorTempDataIdx, pBufIdx, sizeof(SOURCE_TIMING_INFO) * m_colorTempDataSize);
	pBufIdx += sizeof(SOURCE_TIMING_INFO) * m_colorTempDataSize;

	fclose(pFile);
	vip_free(buffer);

	return;

load_fail:
	if (pFile != NULL)
		fclose(pFile);

	if (buffer != NULL) {
		vip_free(buffer);
		buffer = NULL;
	}
#endif
	xLoadDefaultColorTempTable();
}

void xLoadColorFacModeTable()
{
#if 0
	void* buffer = NULL;
	char* pBufIdx = NULL;
	int iReadBytes = 0;
	FILE *pFile = NULL;

	pFile = fopen(VIPTABLE_SAVE_COLORFACMODE, "r");
	if (NULL == pFile) {
		goto load_fail;
	}

	VIPTABLE_SAVE_HEADER header;
	fread(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
	if (header.iFileSize <= 0 || header.iArrayLen <= 0) {
		goto load_fail;
	}

	buffer = vip_malloc(header.iFileSize);
	if(buffer == NULL)
	{
		fclose(pFile);
		printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
		return ;
	}
	iReadBytes = fread(buffer, 1, header.iFileSize, pFile);
	if (iReadBytes != (int)header.iFileSize)
		goto load_fail;

	UINT8 md5[16];
	xGetMD5Value(buffer, iReadBytes, (UINT8*)md5);

	if (memcmp(md5, header.md5check, 16) != 0) {
		printk("md5 check error\n");
		goto load_fail;
	}

	pBufIdx = (char*)buffer;
	m_colorFacModeTableSize = header.iArrayLen;

	m_colorFacModeTable = (StructColorDataFacModeType*)vip_malloc(sizeof(StructColorDataFacModeType) * m_colorFacModeTableSize);
	if(m_colorFacModeTable == NULL)
	{
		fclose(pFile);
		printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
		return ;
	}
	m_colorFacModeTableIdx = (SOURCE_TIMING_INFO*) vip_malloc(sizeof(SOURCE_TIMING_INFO) * m_colorFacModeTableSize);
	if(m_colorFacModeTableIdx == NULL)
	{
		fclose(pFile);
		printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
		return ;
	}
	memcpy(m_colorFacModeTable, pBufIdx, sizeof(StructColorDataFacModeType) * m_colorFacModeTableSize);
	pBufIdx += sizeof(StructColorDataFacModeType) * m_colorFacModeTableSize;

	memcpy(m_colorFacModeTableIdx, pBufIdx, sizeof(SOURCE_TIMING_INFO) * m_colorFacModeTableSize);
	pBufIdx += sizeof(SOURCE_TIMING_INFO) * m_colorFacModeTableSize;

	fclose(pFile);
	vip_free(buffer);

	return;

load_fail:
	if (pFile != NULL)
		fclose(pFile);

	if (buffer != NULL) {
		vip_free(buffer);
		buffer = NULL;
	}
#endif
	xLoadDefaultColorFacModeTable();
}

void xLoadDefaultGainOffsetTable()
{
	memcpy(&m_vgaGainOffset, &m_defaultVgaGainOffset, sizeof(ADCGainOffset));
	memcpy(&m_yPbPrGainOffsetData, m_defaultYPbPrGainOffsetData, sizeof(ADCGainOffset) * SR_MAX_YPBPR_GAINOFFSET_MODE);
}

void xLoadGainOffsetTable()
{
#if 0
	void* buffer = NULL;
	char* pBufIdx = NULL;
	int iReadBytes = 0;
	FILE *pFile = NULL;

	pFile = fopen(VIPTABLE_SAVE_YPPGAINOFFSET, "r");
	if (NULL == pFile) {
		goto load_fail;
	}

	VIPTABLE_SAVE_HEADER header;
	fread(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
	if (header.iFileSize <= 0 || header.iArrayLen <= 0) {
		goto load_fail;
	}

	buffer = vip_malloc(header.iFileSize);
	if(buffer == NULL)
	{
		fclose(pFile);
		printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
		return ;
	}
	iReadBytes = fread(buffer, 1, header.iFileSize, pFile);
	if (iReadBytes != (int)header.iFileSize)
		goto load_fail;

	UINT8 md5[16];
	xGetMD5Value(buffer, iReadBytes, (UINT8*)md5);

	if (memcmp(md5, header.md5check, 16) != 0) {
		printk("md5 check error\n");
		goto load_fail;
	}

	pBufIdx = (char*)buffer;

	//m_yPbPrGainOffsetData = (ADCGainOffset*)vip_malloc(sizeof(ADCGainOffset) * header.iArrayLen);
	memcpy(&m_yPbPrGainOffsetData, pBufIdx, sizeof(ADCGainOffset) * header.iArrayLen);

	fclose(pFile);
	vip_free(buffer);

	pFile = fopen(VIPTABLE_SAVE_VGAGAINOFFSET, "r");
	if (NULL == pFile) {
		goto load_fail;
	}

	fread(&header, 1, sizeof(VIPTABLE_SAVE_HEADER), pFile);
	if (header.iFileSize <= 0 || header.iArrayLen <= 0) {
		goto load_fail;
	}

	buffer = vip_malloc(header.iFileSize);
	if(buffer == NULL)
	{
		fclose(pFile);
		printk("[%s:%d] alloc memory success\n", __FILE__, __LINE__);
		return ;
	}
	iReadBytes = fread(buffer, 1, header.iFileSize, pFile);
	if (iReadBytes != (int)header.iFileSize)
		goto load_fail;

	xGetMD5Value(buffer, iReadBytes, (UINT8*)md5);

	if (memcmp(md5, header.md5check, 16) != 0) {
		printk("md5 check error\n");
		goto load_fail;
	}

	pBufIdx = (char*)buffer;

	//m_vgaGainOffset = (ADCGainOffset*)vip_malloc(sizeof(ADCGainOffset) * header.iArrayLen);
	memcpy(&m_vgaGainOffset, pBufIdx, sizeof(ADCGainOffset) * header.iArrayLen);

	fclose(pFile);
	vip_free(buffer);

	return;

load_fail:
	if (pFile != NULL)
		fclose(pFile);

	if (buffer != NULL) {
		vip_free(buffer);
		buffer = NULL;
	}
#endif
	xLoadDefaultGainOffsetTable();
}
#if 0
void xGetMD5Value(void *pBuffer, int iBufLen, UINT8 *pMD5Value)
{
	//MD5Context ctx;
	unsigned char md5[16];
	//md5_init_ctx(&ctx);
	//md5_process_bytes(pBuffer, iBufLen, &ctx);
	//md5_finish_ctx(&md5, &ctx);

	if (NULL == pBuffer || NULL == pMD5Value)
		return;

	memset(md5, 0x6d, 16);
	memcpy(pMD5Value, md5, 16);
}
#endif
bool WriteAdcSetting(unsigned char nSrcType, ADCGainOffset* adcGainOffset, unsigned char mode)
{
	switch (nSrcType) {
		case  _SRC_VGA:
			memcpy(&m_vgaGainOffset, adcGainOffset, sizeof(ADCGainOffset));
			break;
		case _SRC_YPBPR:
			memcpy(&m_yPbPrGainOffsetData[mode], adcGainOffset, sizeof(ADCGainOffset));
			break;
		default:
			break;
	}
	return true;
}

bool ReadAdcSetting(unsigned char nSrcType, ADCGainOffset* adcGainOffset, unsigned char mode)
{
	switch (nSrcType){
		case  _SRC_VGA:
			memcpy(adcGainOffset, &m_vgaGainOffset, sizeof(ADCGainOffset));
			break;
		case _SRC_YPBPR:
			memcpy(adcGainOffset, &m_yPbPrGainOffsetData[mode], sizeof(ADCGainOffset));
			break;
		default:
			break;
	}
	return true;
}

bool WriteColorTempSetting(COLOR_TEMP_DATA* colortempData, unsigned char srcIdx)
{
	memcpy(&m_colorTempData[srcIdx], colortempData, sizeof(COLOR_TEMP_DATA));
	return true;
}

bool ReadColorTempSetting(COLOR_TEMP_DATA* colortempData, unsigned char srcIdx)
{
	memcpy(colortempData, &m_colorTempData[srcIdx], sizeof(COLOR_TEMP_DATA));
	return true;
}

#ifdef ENABLE_OVERDRIVE
void xAllocateODMem(void)
{
	Scaler_AllocateODMem();
}

void xReleaseODMem(void)
{
	Scaler_ReleaseODMem();
}
#endif

void *Vip_GetQualityCoef(VIP_SOURCE_TIMING source_timing)
{
	return GetQualityCoef(source_timing);
}


void *Vip_GetQualityCoefExtend(VIP_SOURCE_TIMING source_timing)
{
	return GetQualityCoefExtend(source_timing);
}


void *Vip_GetQualityCoefExtend2(VIP_SOURCE_TIMING source_timing)
{
	return GetQualityCoefExtend2(source_timing);
}

void *Vip_GetQualityCoefExtend3(VIP_SOURCE_TIMING source_timing)
{
	return GetQualityCoefExtend3(source_timing);
}

void *Vip_GetQualityCoefExtend4(VIP_SOURCE_TIMING source_timing)
{
	return GetQualityCoefExtend4(source_timing);
}


//young 3Dtable
void *Vip_GetQualityCoef3Dmaode(VIP_3DSOURCE_TIMING source_timing)
{
	return GetQualityCoef3Dmaode(source_timing);
}

void *Vip_GetColorData(UINT32 source, UINT32 timing, UINT32 param)
{
	return GetColorData(source, timing, param);
}

void *Vip_GetColorFacMode(UINT32 source, UINT32 timing, UINT32 param)
{
	return GetColorFacMode(source, timing, param);
}

void *Vip_GetColorTempLevel(UINT32 source, UINT32 timing, UINT32 param)
{
	return GetColorTempLevel(source, timing, param);
}

void *Vip_GetColorTempData(UINT32 source, UINT32 timing, UINT32 param)
{
	return GetColorTempData(source, timing, param);
}

void *Vip_GetPictureModeData(UINT32 source, UINT32 timing, UINT32 param)
{
	return GetPictureModeData(source, timing, param);
}

void *Vip_GetDnrMode(UINT32 source, UINT32 timing, UINT32 param)
{
	return GetDnrMode(source, timing, param);
}

int Vip_GetCurPicMode()
{
	return GetPictureMode(xGetCurSource());
}

UINT8 Vip_GetIcmBySrcPicmode(UINT8 picMode)
{
	return GetIcmBySrcPicmode(picMode);
}

