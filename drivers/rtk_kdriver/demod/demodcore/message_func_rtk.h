#ifndef __MESSAGE_FUNC_MERLIN2_H
#define __MESSAGE_FUNC_MERLIN2_H




//#define rtd_outl(addr, value)           pli_writeReg32(addr, value)
//#define rtd_inl(addr)                   pli_readReg32(addr)
//#define rtd_maskl(addr, mask, value)    rtd_outl(addr, ((rtd_inl(addr) & mask) | value))

/* Shift value for message type field. */
#define HP_MESSAGE_TYPE_SHIFT                   24
/* Mask for message type field. */
#define HP_MESSAGE_TYPE_MASK                    0x7F000000
/* Shift value for message payload field. */
#define HP_PAYLOAD_BITS_SHIFT                   0
/* Mask for message payload field. */
#define HP_PAYLOAD_BITS_MASK                    0x00FFFFFF

#define MSG_LENGTH_SELF_SIZE                    4
#define MSG_BUF_SIZE_WORD                       32
#define MSG_SOURCE_ID                           0
#define MSG_TARGET_ID                           1
#define MSG_MSG_ID                              0x2A

#define MSG_CMD_REG_DONE_AND_SUCCESS            0xFFFFFFFF
#define MSG_CMD_REG_DONE_AND_FAIL               0xEFFFFFFF

/* RPUctrl_msgBufferBaseAddr. */
#define MSG_BUFER_BASE_ADDR 		0x37000000
/* RPUctrl_msgBuffWordSize. */
#define MSG_BUFER_GRAM_WORD_SIZE	3
#define MSG_BUFER_MSG_SIZE			8

typedef enum
{
    /*! START message type ID. (1)*/
    HP_START_MESSAGE = 1,
    /*! DATA message type ID. (2)*/
    HP_DATA_MESSAGE,
    /*! READY message type ID. (3)*/
    HP_READY_MESSAGE,
    /*! Host buffer base address message type ID. (4) */
    HP_BUFBASEH_MESSAGE,
    /*! UCC buffer base address message type ID. (5) */
    HP_BUFBASEU_MESSAGE,
    /*! Buffer ready message type id. (6) */
    HP_BUFREADY_MESSAGE,
    /*! POKE_USER message type ID (7) */
    HP_POKE_USER_MESSAGE
} HP_MESSAGE_TYPE_T;


/*! * Enumerate types of messages functions */
typedef enum{
    /*!Test messaging system. This request does nothing except solicit a status response.*/
    HPMP_PING = 0x00,
    /*!Ready status message. Provided in response to a ping request and automatically at system startup.
     *  Also signals lost message count*/
    HPMP_READY,
    /*!Activate an instance of a TV demodulator.*/
    HPMP_ACTIVATE,
    /*!TV demodulator activation status.*/
    HPMP_ACTIVATED,
    /*!Deactivate an instance of a TV demodulator.*/
    HPMP_DEACTIVATE,
    /*!TV demodulator deactivation status.*/
    HPMP_DEACTIVATED,
    /*!Set a virtual register in the interface of a TV demodulator instance.*/
    HPMP_SETREG,
    /*!Register value.*/
    HPMP_REGVALUE,
    /*!Request the value of a virtual register in the interface of a TV demodulator instance.*/
    HPMP_GETREG,
    /*!Memory block*/
    HPMP_MEM,
    /*!Activate automatic transmission of updates to a virtual register in the interface of a
     *  TV demodulator instance.*/
    HPMP_AUTO_ON,
    /*!Deactivate automatic transmission of updates to a virtual register in the interface of
     * a TV demodulator instance.*/
    HPMP_AUTO_OFF=0x0C,
    /*!Read a block of data from RPU memory*/
    HPMP_READMEM=0X0E,
    /*!Reset or re-boot the entire RPU systeml*/
    HPMP_SHUTDOWN,
    /*!Error status message. This is transmitted in response to an invalid request.*/
    HPMP_ERROR=0xFFFFFFFF
}RPUMSG_MSG_FUNCTIONS;

typedef enum
{
    /*! Normal successful completion */
    HP_RESULT_SUCCESS,
    /*! Bad parameter value or parameter combination */
    HP_RESULT_ILLEGAL_PARAM,
    /*! Read operation cancelled */
    HP_RESULT_READ_CANCEL,
    /*! Read operation timed out */
    HP_RESULT_READ_TIMEOUT,
    /*! Write operation timed out */
    HP_RESULT_WRITE_TIMEOUT,
    /*! Module not correctly initialised */
    HP_RESULT_INIT_ERROR
} HP_STATUS_T;

#define REG_HOST_TO_MTX_CMD     0x02000430
#define REG_MTX_TO_HOST_CMD     0x02000434
#define REG_HOST_TO_MTX_ACK     0x02000438
#define REG_MTX_TO_HOST_ACK     0x0200043C


unsigned int
ImgRegAddrConvert(
    unsigned int AddressIn
);

int
CheckHostToMetaIntClear(void);

int
CheckMetaToHostIntRised(void);

void
WriteHostToMetaAck(void);

void
WriteHostToMetaCmdReg(
    unsigned int *MsgWord
);

void
ReadMetaToHostCmdReg(
    unsigned int *MsgWord
);

int
CheckRpuReadyToReceive(
    unsigned int TimeOutMs
);

int
SendMsgFunc(
    unsigned char *Message,
    unsigned int MsgLength
);

int
MsgSetCmdReg(
    unsigned int PrimaryRegIdx,
    unsigned int SecondaryRegIdx,
    unsigned int WriteValue
);

int
MsgSetReg(
    unsigned int PrimaryRegIdx,
    unsigned int SecondaryRegIdx,
    unsigned int WriteValue
);

int
MsgGetReg(
    unsigned int PrimaryRegIdx,
    unsigned int SecondaryRegIdx,
    unsigned int *ReadValue
);

int
MsgPingRpu(
    unsigned int *IsLive
);

int
MsgShutDown(
    void
);

int
MsgActivateCore(
    unsigned int DemodId,
    unsigned int ChannelId
);


int
MsgDeactivateCore(
    unsigned int DemodId,
    unsigned int ChannelId
);

int
MsgReadMemory(
    unsigned int BufferAddress,
    unsigned int ByteCount
);

int
MsgCheckRpuReady(
    unsigned int *IsRpuReady
);

int
MsgSwitchToBuffered
(
   void
);

int
GetHwRegValue(
    unsigned int HwRegAddr,
    unsigned int *HwRegValue
);

int
SetHwRegValue(
    unsigned int HwRegAddr,
    unsigned int HwRegValue
);

extern unsigned int RPUTimeOutPeriodCnt;
extern unsigned long RPUTimeOutTotalCnt;



#define RTK_MSG_PRINT_LVL_DBG      0
#define RTK_MSG_PRINT_LVL_INFO     1
#define RTK_MSG_PRINT_LVL_WARNING  2


#ifndef RTK_MSG_PRINT_LVL
#define RTK_MSG_PRINT_LVL          RTK_MSG_PRINT_LVL_INFO
#endif

#define RTK_MSG_DBG(fmt, args...)        rtd_printk_demod(KERN_DEBUG, "DEMO", "RTK_MSG_DEBUG, " fmt, ##args);
#define RTK_MSG_INFO(fmt, args...)       rtd_printk_demod(KERN_INFO, "DEMO", "RTK_MSG_INFO, " fmt, ##args);
#define RTK_MSG_WARNING(fmt, args...)    rtd_printk_demod(KERN_WARNING, "DEMO", "RTK_MSG_WARNING, " fmt, ##args);


#endif
