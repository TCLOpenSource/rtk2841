#include <linux/i2c.h>
#include "tv_osal.h"
#include "rtk_tv_fe_types.h"
#include "comm.h"

#define MAX_TX_SIZE         (255)
#define MAX_RX_SIZE         (255)

#define S_OK 1
 
#define DECODE_RET(x)       ((x==S_OK) ? TUNER_CTRL_OK : TUNER_CTRL_FAIL )

void Comm_Constructors(COMM* pCOMMKernel,unsigned char Id)
{
	pCOMMKernel->m_max_tx_size = 0;
	pCOMMKernel->m_max_rx_size = 0;

    pCOMMKernel->m_Id            = Id;    
    pCOMMKernel->m_max_tx_size   = MAX_TX_SIZE;
    pCOMMKernel->m_max_rx_size   = MAX_RX_SIZE;  

    pCOMMKernel->Init = Comm_Init;
    pCOMMKernel->SendReadCommand = Comm_SendReadCommand;
    pCOMMKernel->SendWriteCommand =  Comm_SendWriteCommand;
    pCOMMKernel->SetTargetName =  Comm_SetTargetName;
	pCOMMKernel->Destory = Comm_Destructors;
}

void Comm_Destructors(COMM* pCOMMKernel)
{
}

int Comm_Init(COMM* pCOMMKernel){

// ^^^^^^^^^^^^^^^^^^^  
    return TUNER_CTRL_OK; 
#if 0
    I2C_Init();
    
    I2C_SetSpeed(pCOMMKernel->m_Id, 100);
    return TUNER_CTRL_OK; 
#endif
}

int Comm_SendReadCommand(
	COMM*            pCOMMKernel,
	unsigned char           DeviceAddr, 
	unsigned char*          pRegisterAddr,
	unsigned char           RegisterAddrSize,
	unsigned char*          pReadingBytes,
	unsigned char           ByteNum,
	unsigned long           Flags)
{

#if 0
// ^^^^^^^^^^^^^^^^^^^  
	return TUNER_CTRL_OK;
#else
	int ret;
	//COMM_DBG("i2c read\n");
	ret = i2c_master_recv_ex_flag(pCOMMKernel->m_Id, DeviceAddr>>1,\
		pRegisterAddr,\
		RegisterAddrSize,\
		pReadingBytes, ByteNum, I2C_M_NO_GUARD_TIME | I2C_M_HIGH_SPEED);

#ifdef SHOW_RW_MSG
    int j;
    COMM_WARNING("RD[%02x] ",DeviceAddr);
    
    for(j=0; j<RegisterAddrSize; j++) {        
        COMM_WARNING("<%02x> ",pRegisterAddr[j]);        
    }            
    
    for(j=0; j<ByteNum; j++) {
        COMM_WARNING("%02x ",pReadingBytes[j]);
    }
            
    COMM_WARNING("\n");         
#endif            

#ifdef SHOW_ERR_MSG                     
    
    if (ret!=S_OK)
    {
        int i;
        
        COMM_WARNING("\n\n#################################################\n");
        COMM_WARNING("%s : i2c %d : FETAL : send random read command to target(%02x) fail\n",__FUNCTION__, pCOMMKernel->m_Id, DeviceAddr);
        COMM_WARNING("RR [%02x] ",DeviceAddr);
        
        for(i=0; i<RegisterAddrSize; i++) {        
            COMM_WARNING("<%02x> ",pRegisterAddr[i]);        
        }            
        
        for(i=0; i<ByteNum; i++) {
            COMM_WARNING("%02x ",pReadingBytes[i]);
        }
            
        COMM_WARNING("\n\n#################################################\n"); 
    }        
    
#endif                      
    return TUNER_CTRL_OK;
#endif
    
}

int Comm_SendWriteCommand(
	COMM*            pCOMMKernel,
    unsigned char           DeviceAddr,        
    unsigned char*          pWritingBytes,
    unsigned char           ByteNum,
    unsigned long           Flags)
{
#if 0
// ^^^^^^^^^^^^^^^^^^^  
	return TUNER_CTRL_OK;
#else
	//COMM_DBG("rtk_demod i2c write m_Id=0x%x DeviceAddr=0x%x ByteNum=%d\n", pCOMMKernel->m_Id, DeviceAddr,ByteNum);
	int ret;
	ret = i2c_master_send_ex_flag(pCOMMKernel->m_Id, \
				DeviceAddr>>1,\
				pWritingBytes, \
				ByteNum, I2C_M_NO_GUARD_TIME | I2C_M_HIGH_SPEED);

#ifdef SHOW_RW_MSG    
    COMM_WARNING("WR[%02x] ",DeviceAddr);
    
    for( j=0; j<ByteNum; j++) 
    { 
        COMM_WARNING("%02x ",pWritingBytes[j]);        
    }               
    COMM_WARNING("\n");         
#endif            
    
    if (ret!= S_OK)    
    {
        
#ifdef SHOW_ERR_MSG                  
        COMM_WARNING("\n\n#################################################\n");
        COMM_WARNING("%s : i2c %d : FETAL : send write command to target(%02x) fail\n",__FUNCTION__, pCOMMKernel->m_Id, DeviceAddr);
        COMM_WARNING("Write[%02x] ",DeviceAddr);
        for(int i=0;i<ByteNum; i++)                    
            COMM_WARNING("%02x ",pWritingBytes[i]);                             
        COMM_WARNING("\n#################################################\n\n");                
#endif        
        return TUNER_CTRL_FAIL;
    }          

    return TUNER_CTRL_OK;
#endif
}          
    
   
int Comm_SetTargetName(
	COMM*            pCOMMKernel,
	unsigned char           DeviceAddr,        
	const char*             Name)
{
// ^^^^^^^^^^^^^^^^^^^  
	return TUNER_CTRL_OK;
#if 0
    if (I2C_Set_Target_Name_EX(pCOMMKernel->m_Id, DeviceAddr>>1,Name)==S_OK)
        return TUNER_CTRL_OK;
    else
        return TUNER_CTRL_FAIL;
#endif
}

