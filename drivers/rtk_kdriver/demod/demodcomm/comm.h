#ifndef __COMM_H__
#define __COMM_H__

#include "tv_osal.h"
#include "rtk_tv_fe_types.h"

#ifdef __cplusplus
extern "C" {
#endif 

#define COMM_FLAG_NORMAL_SPEED      0x0000
#define COMM_FLAG_FAST_SPEED        0x0002
#define COMM_FLAG_HIGH_SPEED        0x0004
#define COMM_FLAG_LOW_SPEED         0x0006
#define COMM_FLAG_EXPAND_SDA_HOLD_TIME 0x0080
#define COMM_FLAG_NO_GUARD_INTERVAL 0x0008

typedef struct sCOMM
{            
    unsigned char   m_max_tx_size;
    unsigned char   m_max_rx_size;
    unsigned char m_Id;
    
    int (* Init)(struct sCOMM *comm);
    int (* SendReadCommand)(struct sCOMM *comm, unsigned char DeviceAddr, unsigned char* pRegisterAddr, unsigned char RegisterAddrSize, unsigned char* pReadingBytes, unsigned char ByteNum,unsigned long Flags);
    int (* SendWriteCommand)(struct sCOMM *comm, unsigned char DeviceAddr, unsigned char* pWritingBytes, unsigned char ByteNum,unsigned long Flags);
    int (* SetTargetName)(struct sCOMM *comm, unsigned char DeviceAddr, const char* Name);
    void (*Destory)(struct sCOMM *comm);
}COMM;


void Comm_Constructors(COMM* pCOMMKernel,unsigned char Id);
void Comm_Destructors(COMM* pCOMMKernel);
int Comm_Init(COMM* pCOMMKernel);
int Comm_SendReadCommand(COMM* pCOMMKernel, unsigned char DeviceAddr, unsigned char* pRegisterAddr, unsigned char RegisterAddrSize, unsigned char* pReadingBytes,	unsigned char ByteNum, unsigned long Flags);
int Comm_SendWriteCommand(COMM* pCOMMKernel, unsigned char DeviceAddr, unsigned char* pWritingBytes, unsigned char ByteNum, unsigned long Flags);
int Comm_SetTargetName( COMM* pCOMMKernel, unsigned char DeviceAddr, const char* Name);

//=============================================================

#define COMM_DBG(fmt, args...)          rtd_printk_demod(KERN_DEBUG, "DEMO", "DTV_COMM_DEBUG, " fmt, ##args);
#define COMM_WARNING(fmt, args...)         rtd_printk_demod(KERN_WARNING, "DEMO", "DTV_COMM_WARNING, " fmt, ##args);


#ifdef __cplusplus
    }
#endif 


#endif  //__COMM_H__
