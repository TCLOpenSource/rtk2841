//#include <stdio.h>
//#include <string.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <mach/io.h>

#include "tv_osal.h"
#include "foundation.h"
#include "message_func_rtk.h"

//#define MSG_REG_DBG
//#define MSG_BUFFER_DBG
//[todd]need modified mutex protection 

#define DELAY_TIME 50
unsigned int Msg[MSG_BUF_SIZE_WORD];
//osal_mutex_t msg_lock;
//osal_mutex_t cmd_lock;

unsigned int HostToRPUAddr;
unsigned int RPUToHostAddr;
unsigned char useBufferedProtocol=0;

#define RPU_TIMEOUT_REPORT_MAX_CNT 10
unsigned int RPUTimeOutPeriodCnt = 0;
unsigned long RPUTimeOutTotalCnt = 0;


unsigned int
ImgRegAddrConvert(
    unsigned int AddressIn
)
{
    //static unsigned int gAddressPre;
    unsigned int AddressOut, MsbAddress;

    //if((gAddressPre&0xFFFC0000) != (AddressIn&0xFFFC0000))     
    //{
        MsbAddress = (AddressIn&0xFFFC0000);
        rtd_outl(0xB8072020, MsbAddress);
    //}

    //udelay(DELAY_TIME);
    
    //gAddressPre = AddressIn; // Store Previous Access Address  
    AddressOut = ((AddressIn&0x0003FFFF)|0xB80C0000);

    //udelay(DELAY_TIME);

    return AddressOut;
}


int
CheckHostToMetaIntClear(
)
{
    unsigned int LsbAddress;

    LsbAddress = ImgRegAddrConvert(REG_HOST_TO_MTX_CMD);//0x02000030//0x04800430//0x048000030

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    RTK_MSG_DBG("\033[1;32;32m" "Read %x = %x\n" "\033[m", REG_HOST_TO_MTX_CMD, rtd_inl(LsbAddress));
    #endif

    if((rtd_inl(LsbAddress)&0x80000000) == 0x80000000) //Check HOST_INT is Cleared
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int
CheckMetaToHostIntRised(
)
{
    unsigned int LsbAddress;

    LsbAddress = ImgRegAddrConvert(REG_MTX_TO_HOST_CMD);//0x02000034//0x04800434//0x048000034

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    RTK_MSG_DBG("\033[1;32;32m" "Read %x = %x\n" "\033[m", REG_MTX_TO_HOST_CMD, rtd_inl(LsbAddress));
    #endif

    if((rtd_inl(LsbAddress)&0x80000000) == 0x80000000) //Check META_INT is Rised
    {
        return 1;
    }
    else
    {
        return 0;     
    }
}


void
WriteHostToMetaAck( //Clear MTX_INT_CLR
)
{
    unsigned int LsbAddress;

    LsbAddress = ImgRegAddrConvert(REG_HOST_TO_MTX_ACK);//0x02000038//0x04800438//0x048000038

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    RTK_MSG_DBG("\033[1;32;32m" "Write %x = %x\n" "\033[m", REG_HOST_TO_MTX_ACK, 0x80000000);
    #endif

    rtd_outl(LsbAddress, 0x80000000); //Clear MTX_INT_CLR
}


void
WriteHostToMetaCmdReg(
    unsigned int *MsgWord
)
{
    unsigned int LsbAddress;

    LsbAddress = ImgRegAddrConvert(REG_HOST_TO_MTX_CMD);//0x02000030//0x04800430//0x048000030

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    RTK_MSG_DBG("\033[1;32;32m" "Write %x = %x\n" "\033[m", REG_HOST_TO_MTX_CMD, (*MsgWord & 0x7FFFFFFF));
    #endif

    rtd_outl(LsbAddress, (*MsgWord & 0x7FFFFFFF)); //Write host_to_mtx_cmd register
}


void
ReadMetaToHostCmdReg(
    unsigned int *MsgWord
)
{
    unsigned int LsbAddress;

    LsbAddress = ImgRegAddrConvert(REG_MTX_TO_HOST_CMD);//0x02000034//0x04800434//0x048000034

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    RTK_MSG_DBG("\033[1;32;32m" "Read %x = %x\n" "\033[m", REG_MTX_TO_HOST_CMD, (rtd_inl(LsbAddress)&0x7FFFFFFF));
    #endif

    *MsgWord = (rtd_inl(LsbAddress)&0x7FFFFFFF); //Read mtx_to_host_cmd register
}


int
CheckRpuReadyToReceive(
    unsigned int TimeOutMs
)
{
    unsigned long stime = tv_osal_time();
    unsigned long temptime = 0;

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    #endif

    while((tv_osal_time()-stime) < (unsigned long)TimeOutMs)
    {
// REMOVE THIS        udelay(DELAY_TIME);

        
        
        //Read Register host_to_meta_cmd bit31(HOST_INT)
        if(CheckHostToMetaIntClear()) //Check HOST_INT is Cleared
        {
            #ifdef MSG_REG_DBG
            temptime = tv_osal_time()-stime;
            RTK_MSG_DBG("\033[1;32;32m" "HostToMetaIntClear in %d ms\n" "\033[m", temptime);
            #endif
            RPUTimeOutPeriodCnt = 0;//clear
            RPUTimeOutTotalCnt = 0;//clear
            
            return 1;
        }

        udelay(DELAY_TIME);//tv_osal_msleep(1);

        if(TimeOutMs == -1) //-1 always wait
            stime = tv_osal_time();
    }

    RPUTimeOutPeriodCnt++;
    RPUTimeOutTotalCnt++;
    if(RPUTimeOutPeriodCnt==RPU_TIMEOUT_REPORT_MAX_CNT){
        RPUTimeOutPeriodCnt=0;
        RTK_MSG_WARNING("\033[1;32;32m" "*CheckRpuReadyToReceive Time Out !!!!(error_cnt=%ld)\n" "\033[m", RPUTimeOutTotalCnt);
    }
    if(RPUTimeOutTotalCnt==0xffffffff) RPUTimeOutTotalCnt=0xffffffff;
    
    return 0;
}


int
CheckRpuReplyMessage(
    unsigned int TimeOutMs
)
{
    unsigned long stime = tv_osal_time();
    unsigned long temptime = 0;

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    #endif

    while((tv_osal_time()-stime) < (unsigned long)TimeOutMs)
    {
// REMOVE THIS                udelay(DELAY_TIME);

        //temptime = tv_osal_time()-stime;

        //if(temptime > 950)
        //{
            //RPUTimeOutPeriodCnt++;
            //RPUTimeOutTotalCnt++;
            //if(RPUTimeOutPeriodCnt==RPU_TIMEOUT_REPORT_MAX_CNT){
            //    RPUTimeOutPeriodCnt=0;
            //    RTK_MSG_WARNING("\033[1;32;32m" "*CheckRpuReplyMessage > 950 ms !!!! (%d ms)\n" "\033[m", temptime);
            //}
            //if(RPUTimeOutTotalCnt==0xffffffff) RPUTimeOutTotalCnt=0xffffffff;
            //RTK_MSG_WARNING("\033[1;32;32m" "CheckRpuReplyMessage > 950 ms !!!! (%d ms)\n" "\033[m", temptime);
        //}
        
        //Read Register host_to_meta_cmd bit31(HOST_INT)
        if(CheckMetaToHostIntRised()) //Check META_INT is Rised
        {
            #ifdef MSG_REG_DBG
            temptime = tv_osal_time()-stime;
            RTK_MSG_DBG("\033[1;32;32m" "MetaToHostIntRised in %d ms\n" "\033[m", temptime);
            #endif
            RPUTimeOutPeriodCnt = 0;//clear
            RPUTimeOutTotalCnt = 0;//clear
            
            return 1;
        }

        udelay(DELAY_TIME);//tv_osal_msleep(1);

        if(TimeOutMs == -1) //-1 always wait
            stime = tv_osal_time();
    }
    RPUTimeOutPeriodCnt++;
    RPUTimeOutTotalCnt++;
    if(RPUTimeOutPeriodCnt==RPU_TIMEOUT_REPORT_MAX_CNT){
        RPUTimeOutPeriodCnt=0;
        RTK_MSG_WARNING("\033[1;32;32m" "*CheckRpuReplyMessage  Time Out !!!!(error_cnt=%ld)\n" "\033[m", RPUTimeOutTotalCnt);
    }
    if(RPUTimeOutTotalCnt==0xffffffff) RPUTimeOutTotalCnt=0xffffffff;

    return 0;
}

HP_STATUS_T SendMsgWord
(
   HP_MESSAGE_TYPE_T messageType, 
   unsigned payload,
   int timeout_ms
)
{
    unsigned msgWord = ((messageType << HP_MESSAGE_TYPE_SHIFT) & HP_MESSAGE_TYPE_MASK)
    		| (payload & HP_PAYLOAD_BITS_MASK);
    int done;
    /* Obtain lock for writing, this ensures that 2 processes don't try to write to the host at the same time,
    which would result in corrupted messages.  Wait indefinitely for this lock */
    //osal_MutexLock(&msg_lock);

    /* Poll for RPU to be ready, as indicated by interrupt bit */
    done = CheckRpuReadyToReceive(timeout_ms);
    if (!done) 
    	return HP_RESULT_WRITE_TIMEOUT;

    /* Write message to RPU */
    WriteHostToMetaCmdReg(&msgWord);

    /* Release the lock */
    //osal_MutexUnlock(&msg_lock);

    return HP_RESULT_SUCCESS;
}

int
SendMsgFunc(
    unsigned char *Message,
    unsigned int MsgLength
)
{
    unsigned int RpuReady, TimeOutMs, i, j;
    unsigned int msgWord;
    unsigned int LsbAddress;
    unsigned int BufferAddress;
    HP_STATUS_T ret = HP_RESULT_SUCCESS;

// REMOVE THIS            udelay(DELAY_TIME);

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    #endif

    if (useBufferedProtocol)
    {
    	/* 1. Copy Message into the GRAM HostToRPU buffer */
    	for (j=0;j<(MsgLength>>2);j++)
        {
            BufferAddress=ImgRegAddrConvert(HostToRPUAddr+(4*j));
            msgWord = 0;
            i = 4;
            while(i> 0)
            {
            	msgWord |= ((*Message) << (8*(4-i)) );
            	Message++;
            	i--;
            }
            //Write msgWord to HostToRPUAddr through RBUS
            rtd_outl(BufferAddress,(msgWord&0xFFFFFFFF));
            //printk("rtd_inl(0x%x)=0x%x\n", BufferAddress,(rtd_inl(BufferAddress)&0xFFFFFFFF));
        }

    	/* 2. Send BUFREADY message to RPU */
    	ret =SendMsgWord(HP_BUFREADY_MESSAGE, MsgLength, 1000);
    	if(ret !=HP_RESULT_SUCCESS)
    		goto error_status_send_demod_message;
        
    	return FUNCTION_SUCCESS;
    }
    else
    {
        /* Poll for RPU to be ready, as indicated by interrupt bit */
        TimeOutMs = 1000;
        RpuReady = CheckRpuReadyToReceive(TimeOutMs);

        if (!RpuReady)
        {
        	goto error_status_send_demod_message;
        }
        else
        {
        	/* Send HP_START_MESSAGE */
        	msgWord = ((HP_START_MESSAGE << HP_MESSAGE_TYPE_SHIFT) & HP_MESSAGE_TYPE_MASK)
        	    | (MsgLength & HP_PAYLOAD_BITS_MASK);

            //Write msgWord to host_to_metx_cmd register
            WriteHostToMetaCmdReg(&msgWord);
        }

        /* Repeatedly send HP_DATA_MESSAGE to transfer the message 3 bytes at a time */
        while(MsgLength > 0)
        {
// REMOVE THIS                    udelay(DELAY_TIME);
            
            if(CheckRpuReadyToReceive(TimeOutMs))
            {
                /* serialise 3 bytes of data. If there are less than 3 bytes left, NULL stuff. */
                msgWord = (HP_DATA_MESSAGE << HP_MESSAGE_TYPE_SHIFT);
                i = 3;
                while(i-- > 0)
                {
                    if(MsgLength)
                    {
                        msgWord |= ((*Message) << (8 * i) );
                        Message++;
                        MsgLength--;
                    }
                    /* else we have reached the end of data */
                }
                //Write msgWord to host_to_metx_cmd register
                WriteHostToMetaCmdReg(&msgWord);
            }
            else
            {
                goto error_status_send_demod_message;
            }
        }
        
        return FUNCTION_SUCCESS;
    }

error_status_send_demod_message:
    return FUNCTION_ERROR;
}


int
ReceiveMsgFunc(
    unsigned char *Message
)
{
    unsigned int RxNotDone = 0, RxMessageWord = 0, bytesToRead = 0, bytesRead = 0, RpuReplyDone = 0, messagePayload = 0;
    unsigned int BufferAddress = 0, i = 0, j = 0;
    HP_MESSAGE_TYPE_T messageType;

// REMOVE THIS                        udelay(DELAY_TIME);

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s\n" "\033[m", __func__);
    #endif

    RxNotDone = 1;
    while(RxNotDone)
    {
// REMOVE THIS                            udelay(DELAY_TIME);
        
        RpuReplyDone = CheckRpuReplyMessage(1000);

    	if(!RpuReplyDone)
    	{
    		goto error_status_receive_demod_message;
    	}
        else
        {
            //Read Meta_to_host_cmd register value
            ReadMetaToHostCmdReg(&RxMessageWord);
        }

        messageType = (HP_MESSAGE_TYPE_T)((RxMessageWord & HP_MESSAGE_TYPE_MASK)
                    >> HP_MESSAGE_TYPE_SHIFT);
        messagePayload = RxMessageWord & HP_PAYLOAD_BITS_MASK;

        switch(messageType)
        {
            case HP_START_MESSAGE:
                RTK_MSG_DBG("[Message Receive] HP_START_MESSAGE\n");
                /* Obtain an Rx buffer from queue */
                /* Record how many bytes we need to read, and reset our buffer pointer */
                bytesToRead = messagePayload;
                bytesRead = 0;
            	break;
                
            case HP_DATA_MESSAGE:
                RTK_MSG_DBG("[Message Receive] HP_DATA_MESSAGE\n");
            	/* We should previously have received START, which should have given us a buffer pointer and length */
            	if (bytesToRead == 0)
            	{
            	    goto error_status_receive_demod_message;
            	}
            	else
            	{
                    /* Unpack 3 (or less) bytes of data */
                    j = 3;
                    while(j != 0)
                    {
                        j--;
                        if(bytesRead < bytesToRead)
                        {
                            /* we have some data so add data byte to buffer if there is space*/
                            if(bytesRead < (MSG_BUF_SIZE_WORD*4))
                            {
                            	*(Message+bytesRead) = (messagePayload >> (8 * j)) & 0xFF;
                                bytesRead++;
                            }
                        }
                    }
                    if(bytesRead == bytesToRead)
                    {
        				bytesRead = 0;
                        bytesToRead = 0;
                        RxNotDone = 0;
                    }
            	}
            	break;
                
            case HP_READY_MESSAGE:
                *(Message+16) = HPMP_READY;
                RxNotDone = 0;
                break;
                
            case HP_BUFBASEH_MESSAGE:
                RTK_MSG_DBG("[Message Receive] HP_BUFBASEH_MESSAGE\n");
                /* Payload is the host buffer offset */
                HostToRPUAddr = MSG_BUFER_BASE_ADDR+(messagePayload*MSG_BUFER_GRAM_WORD_SIZE);
                RxNotDone = 0;
                break;

            case HP_BUFBASEU_MESSAGE:
                RTK_MSG_DBG("[Message Receive] HP_BUFBASEU_MESSAGE\n");
                /* Payload is the host buffer offset */
                RPUToHostAddr = MSG_BUFER_BASE_ADDR+(messagePayload*MSG_BUFER_GRAM_WORD_SIZE);
                RxNotDone = 0;
                break;

            case HP_BUFREADY_MESSAGE:
                RTK_MSG_DBG("[Message Receive] HP_BUFREADY_MESSAGE\n");
                /* Payload is the message length */
                /* Copy message into receive buffer */
                for (j=0;j<(messagePayload>>2);j++)
                {
                    BufferAddress=ImgRegAddrConvert(RPUToHostAddr+(4*j));
                    //printk("[RPUToHost] rtd_inl(0x%x)=0x%x\n", BufferAddress,(rtd_inl(BufferAddress)&0xFFFFFFFF));
                    i=4;
                    while(i-->0)
                    {
                    	*Message = ((rtd_inl(BufferAddress)<<(8*i))&0xFF000000)>>24;
                    	Message++;
                    }
                } 
                RxNotDone = 0;
                break;
                
            default:
                RTK_MSG_INFO("[Message Receive] ERROR!!!\n");
                RxNotDone = 0;
        	goto error_status_receive_demod_message;
            	break;
        }
        /* Send an ACK to acknowledge the message and clear the interrupt (note this happens even in
        failure conditions, so things don't lock up) */
        //Write META_INT to host_to_metx_ack register
        WriteHostToMetaAck();
    }

    return FUNCTION_SUCCESS;

error_status_receive_demod_message:
    return FUNCTION_ERROR;
}

int
MsgCheckRpuReady(
    unsigned int *IsRpuReady
)
{
    //osal_MutexLock(&msg_lock);
    
    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    if(*(Msg+4) == HPMP_READY)
    {
        *IsRpuReady = 1;
    }
    else
    {
        *IsRpuReady = 0;
    }
    
    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;

error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}


int
MsgSetCmdReg(
    unsigned int PrimaryRegIdx,
    unsigned int SecondaryRegIdx,
    unsigned int WriteValue
)
{
    unsigned int CheckRegVal;
    unsigned long stime = tv_osal_time();
    unsigned long TimeOutMs = 2000;
    //unsigned int time1, time2;

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s START!!!!\n" "\033[m", __func__);
    #endif

    //osal_MutexLock(&cmd_lock);
    
    //time1 = tv_osal_time();
    MsgSetReg(PrimaryRegIdx, SecondaryRegIdx, WriteValue);
// REMOVE THIS                                tv_osal_msleep(2);
    while((tv_osal_time()-stime) < TimeOutMs)
    {
// REMOVE THIS                            udelay(DELAY_TIME);
        
        MsgGetReg(PrimaryRegIdx, SecondaryRegIdx, &CheckRegVal);
        
        if(CheckRegVal == MSG_CMD_REG_DONE_AND_SUCCESS || CheckRegVal == MSG_CMD_REG_DONE_AND_FAIL)
        {
            //RTK_MSG_INFO("\033[1;32;32m" "MsgSetCmdReg Rst=%x\n" "\033[m", CheckRegVal);
            //time2 = tv_osal_time();
            //RTK_MSG_INFO("\033[1;32;32m" "MsgSetCmdReg=%d\n" "\033[m", time2-time1);
            //osal_MutexUnlock(&cmd_lock);

            #ifdef MSG_REG_DBG
            RTK_MSG_DBG("\033[1;32;31m" "%s END!!!!\n" "\033[m", __func__);
            #endif
            
            return FUNCTION_SUCCESS;
        }

        udelay(DELAY_TIME);//tv_osal_msleep(1);
    }
    
    RTK_MSG_WARNING("\033[1;32;32m" "MsgSetCmdReg Rst=FUNCTION_ERROR\n" "\033[m");
    
    //osal_MutexUnlock(&cmd_lock);
    
    return FUNCTION_ERROR;
}


int
MsgSetReg(
    unsigned int PrimaryRegIdx,
    unsigned int SecondaryRegIdx,
    unsigned int WriteValue
)
{
    //osal_MutexLock(&msg_lock);

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s START!!!!\n" "\033[m", __func__);
    RTK_MSG_DBG("\033[1;32;32m" "PrimaryRegIdx = %x, SecondaryRegIdx = %x, WriteValue = %x\n" "\033[m", PrimaryRegIdx, SecondaryRegIdx, WriteValue);
    #endif
    
    memset(Msg, 0, sizeof(Msg));
    Msg[0] = 28;            //Message Length
    Msg[1] = MSG_SOURCE_ID; //Source ID
    Msg[2] = MSG_TARGET_ID; //Target ID
    Msg[3] = MSG_MSG_ID;    //Message ID
    Msg[4] = HPMP_SETREG;   //Message Func
    Msg[5] = 8;             //Data Length
    Msg[6] = (SecondaryRegIdx<<16) | PrimaryRegIdx; //[SecondaryRegIdx|PrimaryRegIdx]
    Msg[7] = WriteValue;    //Register Value

    #ifdef MSG_BUFFER_DBG
    int j=0;
    printk("------- MsgSetReg -------\n");
    for (j=0;j<MSG_BUFER_MSG_SIZE;j++) printf(" S_Msg[%d]=%2x\n", j, *(Msg+j));
    #endif
    
    if(SendMsgFunc((unsigned char*)Msg, (Msg[0]+MSG_LENGTH_SELF_SIZE)) != FUNCTION_SUCCESS)
		goto error_status_send_demod_message;

    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    #ifdef MSG_BUFFER_DBG
    for (j=0;j<MSG_BUFER_MSG_SIZE;j++) printf(" R_Msg[%d]=%2x\n", j, *(Msg+j));
    printk("--------------------\n");
    #endif

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s END!!!!\n" "\033[m", __func__);
    #endif

    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_SUCCESS;

error_status_send_demod_message:
error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}


int
MsgGetReg(
    unsigned int PrimaryRegIdx,
    unsigned int SecondaryRegIdx,
    unsigned int *ReadValue
)
{
    //osal_MutexLock(&msg_lock);

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;31m" "%s START!!!!\n" "\033[m", __func__);
    RTK_MSG_DBG("\033[1;32;32m" "PrimaryRegIdx = %x, SecondaryRegIdx = %x\n" "\033[m", PrimaryRegIdx, SecondaryRegIdx);
    #endif
    
    memset(Msg, 0, sizeof(Msg));
    Msg[0] = 24;            //Message Length
    Msg[1] = MSG_SOURCE_ID; //Source ID
    Msg[2] = MSG_TARGET_ID; //Target ID
    Msg[3] = MSG_MSG_ID;    //Message ID
    Msg[4] = HPMP_GETREG;   //Message Func
    Msg[5] = 4;             //Data Length
    Msg[6] = (SecondaryRegIdx<<16) | PrimaryRegIdx; //[SecondaryRegIdx|PrimaryRegIdx]

    #ifdef MSG_BUFFER_DBG
    int j=0;
    printk("------- MsgGetReg -------\n");
    for (j=0;j<MSG_BUFER_MSG_SIZE;j++) printk(" S_Msg[%d]=%2x\n", j, *(Msg+j));
    #endif
    
    if(SendMsgFunc((unsigned char*)Msg, (Msg[0]+MSG_LENGTH_SELF_SIZE)) != FUNCTION_SUCCESS)
		goto error_status_send_demod_message;

    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    #ifdef MSG_BUFFER_DBG	
    for (j=0;j<MSG_BUFER_MSG_SIZE;j++) printk(" R_Msg[%d]=%2x\n", j, *(Msg+j));
    printk("--------------------\n");
    #endif

    *ReadValue = *(Msg+7);

    #ifdef MSG_REG_DBG
    RTK_MSG_DBG("\033[1;32;32m" "PrimaryRegIdx = %x, SecondaryRegIdx = %x, ReadValue = %x\n" "\033[m", PrimaryRegIdx, SecondaryRegIdx, *ReadValue);
    RTK_MSG_DBG("\033[1;32;31m" "%s END!!!!\n" "\033[m", __func__);
    #endif
    
    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;

error_status_send_demod_message:
error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}

int
MsgPingRpu(
    unsigned int *IsLive
)
{
    //osal_MutexLock(&msg_lock);
    
    memset(Msg, 0, sizeof(Msg));
    Msg[0] = 20;            //Message Length
    Msg[1] = MSG_SOURCE_ID; //Source ID
    Msg[2] = MSG_TARGET_ID; //Target ID
    Msg[3] = MSG_MSG_ID;    //Message ID
    Msg[4] = HPMP_PING;     //Message Func
    Msg[5] = 0;             //Data Length

    if(SendMsgFunc((unsigned char*)Msg, (unsigned int)(Msg[0]+MSG_LENGTH_SELF_SIZE)) != FUNCTION_SUCCESS)
		goto error_status_send_demod_message;

    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    if(*(Msg+4) == HPMP_READY)
        *IsLive = 1;
    else
        goto error_status_receive_demod_message;

    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_SUCCESS;

error_status_send_demod_message:
error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}

int
MsgShutDown(
    void
)
{
    //osal_MutexLock(&msg_lock);
    
    memset(Msg, 0, sizeof(Msg));
    Msg[0] = 20;            //Message Length
    Msg[1] = MSG_SOURCE_ID; //Source ID
    Msg[2] = MSG_TARGET_ID; //Target ID
    Msg[3] = MSG_MSG_ID;    //Message ID
    Msg[4] = HPMP_SHUTDOWN; //Message Func
    Msg[5] = 0;             //Data Length

    if(SendMsgFunc((unsigned char*)Msg, (unsigned int)(Msg[0]+MSG_LENGTH_SELF_SIZE)) != FUNCTION_SUCCESS)
		goto error_status_send_demod_message;

    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    if(*(Msg+4) != HPMP_READY)
        goto error_status_receive_demod_message;

    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;

error_status_send_demod_message:
error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}

int
MsgActivateCore(
    unsigned int DemodId,
    unsigned int ChannelId
)
{
    //osal_MutexLock(&msg_lock);
    
    memset(Msg, 0, sizeof(Msg));
    Msg[0] = 28;            //Message Length
    Msg[1] = MSG_SOURCE_ID; //Source ID
    Msg[2] = 0; //Target ID
    Msg[3] = MSG_MSG_ID;    //Message ID
    Msg[4] = HPMP_ACTIVATE; //Message Func
    Msg[5] = 8;             //Data Length
    Msg[6] = DemodId;
    Msg[7] = ChannelId;

    if(SendMsgFunc((unsigned char*)Msg, (unsigned int)(Msg[0]+MSG_LENGTH_SELF_SIZE)) != FUNCTION_SUCCESS)
		goto error_status_send_demod_message;

    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    if(*(Msg+4) != HPMP_ACTIVATED)
        goto error_status_receive_demod_message;

    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;

error_status_send_demod_message:
error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}

int
MsgDeactivateCore(
    unsigned int DemodId,
    unsigned int ChannelId
)
{
    //osal_MutexLock(&msg_lock);
    
    memset(Msg, 0, sizeof(Msg));
    Msg[0] = 20;                //Message Length
    Msg[1] = MSG_SOURCE_ID;     //Source ID
    Msg[2] = MSG_TARGET_ID;     //Target ID
    Msg[3] = MSG_MSG_ID;        //Message ID
    Msg[4] = HPMP_DEACTIVATE;   //Message Func
    Msg[5] = 0;                 //Data Length

    if(SendMsgFunc((unsigned char*)Msg, (unsigned int)(Msg[0]+MSG_LENGTH_SELF_SIZE)) != FUNCTION_SUCCESS)
		goto error_status_send_demod_message;

    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    if(*(Msg+4) != HPMP_DEACTIVATED)
        goto error_status_receive_demod_message;

    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;

error_status_send_demod_message:
error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}

int
MsgReadMemory(
    unsigned int BufferAddress,
    unsigned int ByteCount
)
{
    //osal_MutexLock(&msg_lock);
    
    memset(Msg, 0, sizeof(Msg));
    Msg[0] = 28;                //Message Length
    Msg[1] = MSG_SOURCE_ID;     //Source ID
    Msg[2] = MSG_TARGET_ID;     //Target ID
    Msg[3] = MSG_MSG_ID;        //Message ID
    Msg[4] = HPMP_DEACTIVATE;   //Message Func
    Msg[5] = 8;                 //Data Length
    Msg[6] = BufferAddress;
    Msg[7] = ByteCount;

    if(SendMsgFunc((unsigned char*)Msg, (unsigned int)(Msg[0]+MSG_LENGTH_SELF_SIZE)) != FUNCTION_SUCCESS)
		goto error_status_send_demod_message;

    memset(Msg, 0, sizeof(Msg));
    if(ReceiveMsgFunc((unsigned char*)Msg) != FUNCTION_SUCCESS)
		goto error_status_receive_demod_message;

    //Get Memory Data
    //Coding Here!!!!
    //unsigned int Data[32] = {0};
    //Data[0] = *(Msg+6)...

    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;

error_status_send_demod_message:
error_status_receive_demod_message:
    //osal_MutexUnlock(&msg_lock);
    
    return FUNCTION_ERROR;
}

int
MsgSwitchToBuffered(
	void
)
{
	HP_STATUS_T HPstatus=HP_RESULT_SUCCESS;
	
	/*1. Discover BUFBASEH addresses */
	HPstatus = SendMsgWord(HP_BUFBASEH_MESSAGE, 0, 1000);
	if (HPstatus!=HP_RESULT_SUCCESS)
		goto error_status_switch_to_buffer;
	ReceiveMsgFunc(Msg);

	/* 2. Discover BUFBASEU addresses */
	HPstatus = SendMsgWord(HP_BUFBASEU_MESSAGE, 0, 1000);
	if (HPstatus!=HP_RESULT_SUCCESS)
		goto error_status_switch_to_buffer;
	ReceiveMsgFunc(Msg);

	switch(HPstatus)
	{
		case HP_RESULT_SUCCESS:
			useBufferedProtocol=1;
			break;
		default:
			useBufferedProtocol=0;
			goto error_status_switch_to_buffer;
			break;
	}
	return FUNCTION_SUCCESS;

error_status_switch_to_buffer:
	return FUNCTION_ERROR;
}

int
GetHwRegValue(
    unsigned int HwRegAddr,
    unsigned int *HwRegValue
)
{
    unsigned int LsbAddress;

    //osal_MutexLock(&msg_lock);

    LsbAddress = ImgRegAddrConvert(HwRegAddr);
    *HwRegValue = rtd_inl(LsbAddress);

    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;
}

int
SetHwRegValue(
    unsigned int HwRegAddr,
    unsigned int HwRegValue
)
{
    unsigned int LsbAddress;

    //osal_MutexLock(&msg_lock);

    LsbAddress = ImgRegAddrConvert(HwRegAddr);
    rtd_outl(LsbAddress, HwRegValue);

    //osal_MutexUnlock(&msg_lock);

    return FUNCTION_SUCCESS;
}
