#ifndef __CUSTOM_PCBSOURCE_H__
#define __CUSTOM_PCBSOURCE_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <Platform_Lib/TVScalerControl/scaler/scalerStruct.h>


//allen add for Display Range 20071001
#define _DisplayRange_FULL              0
#define _DisplayRange_ZOOM              1



void PcbSource_Init(void);
StructSourceInput *PcbSource_GetTable(void);
int PcbSource_GetTableSize(void);


#ifdef __cplusplus
}
#endif

#endif	
