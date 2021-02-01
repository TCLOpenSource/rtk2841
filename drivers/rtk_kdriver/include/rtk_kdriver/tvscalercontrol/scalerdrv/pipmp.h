#ifndef __PIPMP_H__
#define __PIPMP_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
//#include <tvscalercontrol/scaler/scalerStruct.h>

/*======================== CONSTANTS =========================================*/


/*======================== MACROS ============================================*/

/*======================== TYPES =============================================*/

/*======================== VARIABLES =========================================*/

/*======================== FUNCTIONS =========================================*/
void Pipmp_SetPipCtrl(void);
void Pipmp_SetMpCtrl(void);
void PipMp_GetPipSize(eSubType Type, unsigned short* Width, unsigned short* Length);
unsigned short PipMp_GetMpFlag(eSubType Type);
void PipMp_GetPipPos(ePipPos Pos, eSubType Type, unsigned short* HStart, unsigned short* VStart);
unsigned char PipMp_RotateMp(unsigned int timerId, void* msg);
void PipMp_SetSubInfo(unsigned char SubType);
void PipMp_DisableSubChannel(void);
void PipmpSetSubDisplayWindow(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta,
	unsigned short DispVEnd, unsigned char Border);
void PipmpSetSubActiveWindow(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta,
	unsigned short DispVEnd);
void PipmpSetSubDisplayBorder(unsigned short DispHSta, unsigned short DispHEnd, unsigned short DispVSta,
	unsigned short DispVEnd, unsigned char Border,unsigned char BorderType);
void PipMpSetMpEnable(unsigned short MpEnable);
//unsigned short pipmp_get_mem_cap_width(void);
void PipMp_SetSubBorderWidth(unsigned char width);
void Pipmp_SetPipCustomWin(StructSrcRect m_dispwin);
StructSrcRect Pipmp_GetPipCustomWin(void);

#ifdef __cplusplus
}
#endif

#endif // __PIPMP_H__

