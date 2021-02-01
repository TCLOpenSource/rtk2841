#ifndef __SCALER_FLOW_MGR_H__
#define __SCALER_FLOW_MGR_H__

#include <StreamClass/CFlowManager.h>



typedef enum _SCALER_PATH {
	
	SCALER_PATH_MAIN = 0,
	SCALER_PATH_SUB,
	SCLAER_PATH_MAX
	
} SCALER_PATH;



void Scaler_InitFlowMgr();
void Scaler_ResetFlowMgr(SCALER_PATH path);
void Scaler_SetFlowMgr(SCALER_PATH path, CFlowManager *pFlow);
bool Scaler_SendMessage(SCALER_PATH path, unsigned int message);


#endif // __SCALER_FLOW_MGR_H__

