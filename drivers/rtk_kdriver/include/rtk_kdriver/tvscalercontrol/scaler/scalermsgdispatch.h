#ifndef __SCALER_MSG_DISPATCH_H__
#define __SCALER_MSG_DISPATCH_H__


#include <Platform_Lib/Utils/RtMsgQueue.h>



typedef enum _SCALER_PATH {
	
	SCALER_PATH_MAIN = 0,
	SCALER_PATH_SUB,
	SCLAER_PATH_MAX
	
} SCALER_PATH;



void ScalerMsgDispatch_Init();
void ScalerMsgDispatch_DeInit();
bool ScalerMsgDispatch_Reset(SCALER_PATH path);
bool ScalerMsgDispatch_Send(SCALER_PATH path, unsigned int message, unsigned int data);
bool ScalerMsgDispatch_Get(SCALER_PATH path, RT_MESSAGE_BUF *pMsgBuf);
bool ScalerMsgDispatch_Get(SCALER_PATH path, RT_MESSAGE_BUF *pMsgBuf, unsigned int msTimeout);

#if defined (IS_MACARTHUR3)
bool ScalerMsgDispatch_Remove(SCALER_PATH path, RT_MESSAGE_BUF *pMsgBuf);
bool ScalerMsgDispatch_Remove(SCALER_PATH path, int message, int data=-1);
#endif


#endif // __SCALER_MSG_DISPATCH_H__

