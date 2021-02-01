/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		MHL_cbus.c
 *
 * author: 	Black Widow, Natasha Romanoff
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"
#include "mhl_driver.h"


#if MHL_SUPPORT


/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/






/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/
const unsigned int D614[HDMI_PHY_TOTAL_NUM] = {
		MHL_P0_PORT0_MHL_DEMUX_CTRL_reg,
		MHL_P1_PORT1_MHL_DEMUX_CTRL_reg,
		MHL_P2_PORT2_MHL_DEMUX_CTRL_reg,
#if HDMI_PHY_TOTAL_NUM==4
		MHL_P3_PORT2_MHL_DEMUX_CTRL_reg
#endif
		};
#if MHL3_ENABLE
const unsigned int D700[HDMI_PHY_TOTAL_NUM] = {
		MHL_P0_PORT0_MHL3_CTRL_reg,
		MHL_P1_PORT1_MHL3_CTRL_reg,
		MHL_P2_PORT2_MHL3_CTRL_reg,
		MHL_P3_PORT2_MHL3_CTRL_reg};
#endif





/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
MHL_PARAM_T MHL_CTRL;
// cloud add global variable for cbus use
//CBUS_CHANNEL_T *cbus;
u_int8_t _bMhl_clk_mode;
//u_int8_t _bMhl_phy_clk_mode;
u_int8_t _bMhl_No_clock_cnt;
u_int8_t _bMhl_FW_PP_24_mode;
u_int8_t _bMhl_FW_PP_24_mode_cnt;
u_int8_t _bMhl_FW_PP_24_LOCK;
int     MHL_wClock_value;
u_int8_t mhl_link_mode_updated;


// For RCP in out fifo pointer & rcp buffer
#define buffer_length   10
#define RCP_NULL 0x69

u_int8_t RCP_Buffer[buffer_length];
u_int8_t in_point =0 ,out_point = 0;





/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/

void mhl3_isr(void);








/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/

void MHL_setPPMode(unsigned char pp)
{
	_bMhl_clk_mode = pp;
}

unsigned char MHL_IsPPMode(void)
{
	return _bMhl_clk_mode;
}

u_int8_t bGet_MHL_CLK_TYPE(void)
{
	return CBUS_MSC_REG_31_get_clk_mode(hdmi_in(CBUS_MSC_REG_31_reg));
}
/***************************************************************************************/
//Function :  void CBUS_MSC_CMD1(u_int8_t  bcase,u_int8_t bCmd)
//Description: SET MSC command CMD1 1 BYTE only
//Parameter:  bcase reference FW Request case
//return: no need return
/**************************************************************************************/
void CBUS_MSC_CMD1(u_int8_t bCmd,u_int8_t breturnType)
{
	FW0Requester_set_tx_case(MHL_TX_CASE_COMMAND);
	FW0Requester_set_head(MHL_HEADER_MSC_CMD);
	FW0Requester_set_cmd1(bCmd);
	FW0Requester_set_wait_case(breturnType);
	FW0Requester_set_req_en(1);

}

/***************************************************************************************/
//Function :  CBUS_MSC_CMD1_SET_HOT_PLUG(void)
//Description: SET HPD
//Parameter:  bcase reference FW Request case
//return: fail or sucess
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD1_SET_HOT_PLUG(void)
{
	u_int8_t btimeout = 250;

	CBUS_MSC_CMD1(MHL_MSC_CMD_CODE_SET_HPD,MHL_TX_WAIT_CASE_CMD_ONLY);
	do {
		btimeout--;
	} while((!FW0Requester_get_cmd_flag())&(btimeout != 0));

	HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD1_SET_HOT_PLUG wait counter = %d \n", btimeout);  //measure timeout counter
	FW0Requester_set_cmd_flag(1);//write 1 clear
	if(FW0Requester_get_cmd() == MHL_MSC_CMD_CODE_ACK) {
		HDMI_PRINTF("[CBUS_LOG] SET HPD SUCESS\n");
		return TRUE;
	} else {
		HDMI_PRINTF("[CBUS_LOG] SET HPD FAIL\n");
		return  FALSE;
	}

}

/***************************************************************************************/
//Function :  CBUS_MSC_CMD1_CLR_HOT_PLUG(void)
//Description: CLR HPD
//Parameter:  bcase reference FW Request case
//return:  fail or sucess
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD1_CLR_HOT_PLUG(void)
{

	CBUS_MSC_CMD1(MHL_MSC_CMD_CODE_CLR_HPD,MHL_TX_WAIT_CASE_CMD_ONLY);
	while(!FW0Requester_get_cmd_flag());
	FW0Requester_set_cmd_flag(1);//write 1 clear
	if(FW0Requester_get_cmd() == MHL_MSC_CMD_CODE_ACK) {
		HDMI_PRINTF("[CBUS_LOG] CLR HPD SUCESS\n");
		return TRUE;
	} else {
		HDMI_PRINTF("[CBUS_LOG] CLR  HPD FAIL\n");
		return  FALSE;
	}
}

/***************************************************************************************/
//Function :  CBUS_MSC_CMD1_GET_STATE(void)
//Description: SMC GET STATE
//Parameter:  bcase reference FW Request case
//return: STATE
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD1_GET_STATE(void)
{
	u_int8_t bReturnData;
	CBUS_MSC_CMD1(MHL_MSC_CMD_CODE_GET_STATE,MHL_TX_WAIT_CASE_DATA_ONLY);
	while(!FW0Requester_get_data_flag());
	FW0Requester_set_data_flag(1);//write 1 clear
	bReturnData =  FW0Requester_get_data() ;
	HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD1_GET_STATE = %x \n" ,bReturnData);
	return bReturnData ;

}
/***************************************************************************************/
//Function :  bCBUS_MSC_CMD1_GET_VENDOR_ID(void)
//Description: MHL_MSC_CMD_CODE_GET_VENDOR_ID
//Parameter:  bcase reference FW Request case
//return: VENDOR_ID
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD1_GET_VENDOR_ID(void)
{
	u_int8_t bReturnData;
	CBUS_MSC_CMD1(MHL_MSC_CMD_CODE_GET_VENDOR_ID,MHL_TX_WAIT_CASE_DATA_ONLY);
	while(!FW0Requester_get_data_flag());
	FW0Requester_set_data_flag(1);//write 1 clear
	bReturnData =  FW0Requester_get_data() ;
	HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD1_GET_VENDOR_ID = %x \n" ,bReturnData);
	return bReturnData ;

}

/***************************************************************************************/
//Function :  bCBUS_MSC_CMD1_GET_DDC_ERR(void)
//Description: MHL_MSC_CMD_CODE_GET_DDC_ERR
//Parameter:  bcase reference FW Request case
//return: DDC_ERR code
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD1_GET_DDC_ERR(void)
{
	u_int8_t bReturnData;
	CBUS_MSC_CMD1(MHL_MSC_CMD_CODE_GET_DDC_ERR,MHL_TX_WAIT_CASE_DATA_ONLY);
	while(!FW0Requester_get_data_flag());
	FW0Requester_set_data_flag(1);//write 1 clear
	bReturnData =  FW0Requester_get_data() ;
	HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD1_GET_DDC_ERR = %x \n" ,bReturnData);
	return bReturnData ;

}

/***************************************************************************************/
//Function :  bCBUS_MSC_CMD1_GET_MSC_ERR(void)
//Description: MHL_MSC_CMD_CODE_GET_MSC_ERR
//Parameter:  bcase reference FW Request case
//return: DDC_ERR code
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD1_GET_MSC_ERR(void)
{
	u_int8_t bReturnData;
	CBUS_MSC_CMD1(MHL_MSC_CMD_CODE_GET_MSC_ERR,MHL_TX_WAIT_CASE_DATA_ONLY);
	while(!FW0Requester_get_data_flag());
	FW0Requester_set_data_flag(1);//write 1 clear
	bReturnData =  FW0Requester_get_data() ;
	HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD1_GET_MSC_ERR = %x \n" ,bReturnData);
	return bReturnData ;

}

/***************************************************************************************/
//Function :  void CBUS_MSC_CMD2(u_int8_t bCmd,u_int8_t boffset,u_int8_t breturnType)
//Description: SET MSC command CMD1 +OFFSET
//Parameter:  bcase reference FW Request case
//return: no need return
/**************************************************************************************/
void CBUS_MSC_CMD2(u_int8_t bCmd,u_int8_t boffset,u_int8_t breturnType)
{
	FW0Requester_set_tx_case(MHL_TX_CASE_COM_OFF);
	FW0Requester_set_head(MHL_HEADER_MSC_CMD);
	FW0Requester_set_cmd1(bCmd);
	FW0Requester_set_offset(boffset);
	FW0Requester_set_wait_case(breturnType);
	FW0Requester_set_req_en(1);
}

/***************************************************************************************/
//Function :  bCBUS_MSC_CMD2_READ_DEVCAP(void)
//Description: MHL_MSC_CMD_CODE_READ_DEVCAP
//Parameter:  bcase reference FW Request case
//return: DDC_ERR code
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD2_READ_DEVCAP(u_int8_t bOffset)
{
	u_int8_t bReturnData;
	CBUS_MSC_CMD2(MHL_MSC_CMD_CODE_READ_DEVCAP,bOffset,MHL_TX_WAIT_CASE_CMD_DATA);

	while(!FW0Requester_get_cmd_flag());
	FW0Requester_set_cmd_flag(1);//write 1 clear
	if(FW0Requester_get_cmd() == MHL_MSC_CMD_CODE_ACK) {
		HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD2_READ_DEVCAP ACK\n");
	} else {
		HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD2_READ_DEVCAP NACK\n");
		return FALSE ;
	}

	while(!FW0Requester_get_data_flag());
	FW0Requester_set_data_flag(1);//write 1 clear
	bReturnData =  FW0Requester_get_data() ;
	HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD2_READ_DEVCAP Offset  = %x , data = %x \n" ,bOffset,bReturnData);
	return bReturnData ;

}

/***************************************************************************************/
//Function :  void CBUS_MSC_CMD3(u_int8_t  bcase,u_int8_t bCmd)
//Description: SET MSC command CMD1 +OFFSET +DATA
//Parameter:  bcase reference FW Request case
//return: no need return
/**************************************************************************************/
void CBUS_MSC_CMD3(u_int8_t bCmd,u_int8_t boffset,u_int8_t bvalue,u_int8_t breturnType)
{
	FW0Requester_set_tx_case(MHL_TX_CASE_COM_OFF_DAT);
	FW0Requester_set_head(MHL_HEADER_MSC_CMD);
	FW0Requester_set_cmd1(bCmd);
	FW0Requester_set_offset(boffset);
	FW0Requester_set_data(bvalue);
	FW0Requester_set_wait_case(breturnType);
	FW0Requester_set_req_en(1);
}


/***************************************************************************************/
//Function :  bCBUS_MSC_CMD3_WRITE_STAT(void)
//Description: MHL_MSC_CMD_CODE_WRT_STAT
//Parameter:  bcase reference FW Request case
//return: ACK or NACK
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD3_WRITE_STAT(u_int8_t bOffset ,u_int8_t bvalue)
{

	CBUS_MSC_CMD3(MHL_MSC_CMD_CODE_WRT_STAT,bOffset ,bvalue,MHL_TX_WAIT_CASE_CMD_ONLY);

	while(!FW0Requester_get_cmd_flag());
	FW0Requester_set_cmd_flag(1);//write 1 clear
	if(FW0Requester_get_cmd() == MHL_MSC_CMD_CODE_ACK) {
		HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD3_WRITE_STAT SUCESS\n");
		return TRUE;
	} else {
		HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD3_WRITE_STAT FAIL\n");
		return  FALSE;
	}

}


/***************************************************************************************/
//Function :  bCBUS_MSC_CMD3_SET_INT(void)
//Description: MHL_MSC_CMD_CODE_SET_INT
//Parameter:  bcase reference FW Request case
//return: ACK or NACK
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD3_SET_INT(u_int8_t bOffset ,u_int8_t bvalue)
{

	CBUS_MSC_CMD3(MHL_MSC_CMD_CODE_SET_INT,bOffset ,bvalue,MHL_TX_WAIT_CASE_CMD_ONLY);

	while(!FW0Requester_get_cmd_flag());
	FW0Requester_set_cmd_flag(1);//write 1 clear
	if(FW0Requester_get_cmd() == MHL_MSC_CMD_CODE_ACK) {
		HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD3_SET_INT SUCESS\n");
		return TRUE;
	} else {
		HDMI_PRINTF("[CBUS_LOG]bCBUS_MSC_CMD3_SET_INT FAIL\n");
		return  FALSE;
	}

}

/***************************************************************************************/
//Function :  bCBUS_MSC_CMD3_MSG_RAP_SUB_CMD(u_int8_t bOffset ,u_int8_t bvalue)
//Description: MHL_MSC_CMD_CODE_MSC_MSG
//Parameter:  bcase reference FW Request case
//return: ACK or NACK
/**************************************************************************************/
u_int8_t bCBUS_MSC_CMD3_MSG_SUB_CMD(u_int8_t bOffset ,u_int8_t bvalue)
{

	CBUS_MSC_CMD3(MHL_MSC_CMD_CODE_MSC_MSG,bOffset ,bvalue,MHL_TX_WAIT_CASE_CMD_ONLY);

	while(!FW0Requester_get_cmd_flag());
	FW0Requester_set_cmd_flag(1);//write 1 clear
	if(FW0Requester_get_cmd() == MHL_MSC_CMD_CODE_ACK) {
		HDMI_PRINTF("[CBUS_LOG] bCBUS_MSC_CMD3_MSG_RAP_SUB_CMD SUCESS\n");
		return TRUE;
	} else {
		HDMI_PRINTF("[CBUS_LOG]bCBUS_MSC_CMD3_MSG_RAP_SUB_CMD FAIL\n");
		return  FALSE;
	}

}
/***************************************************************************************/
//Function :  CBUS_RAP(u_int8_t bopcode)
//Description: MHL_MSG_RAP
//Parameter:   bopcode :
//                  0x00 poll ,
//                  0x10 change to content_on state ,
//                  0x11 change to content_off state
//return: ACK or NACK
/**************************************************************************************/
void CBUS_MSG_RAP(u_int8_t bopcode)
{
	bCBUS_MSC_CMD3_MSG_SUB_CMD(MHL_MSG_RAP,bopcode);
	HDMI_PRINTF("[CBUS_LOG]CBUS_MSG_RAP  OPcode = %x \n",bopcode);
}

/***************************************************************************************/
//Function :  CBUS_RAPK(u_int8_t berrorcode)
//Description: MHL_MSC_CMD_CODE_MSC_MSG
//                  0x00 No error ,
//                  0x01 Unrecognized Action code  ,
//                  0x02 Unsupported Action code
//                  0x03 Responder Busy
//return: ACK or NACK
/**************************************************************************************/
void CBUS_MSG_RAPK(u_int8_t berrorcode)
{
	bCBUS_MSC_CMD3_MSG_SUB_CMD(MHL_MSG_RAPK,berrorcode);
	HDMI_PRINTF("[CBUS_LOG]CBUS_MSG_RAPK  berrorcode = %x \n",berrorcode);
}


/***************************************************************************************/
//Function :  CBUS_MSG_RCPE(u_int8_t bstatuscode)
//Description: MHL_MSG_RCPE
//                  0x00  : No error
//                  0x01  : ineffective key code
//                  0x02  : Responder busy
//return: This is ACK code to host means you get right key
/**************************************************************************************/
void CBUS_MSG_RCPE(u_int8_t bstatuscode)
{
	bCBUS_MSC_CMD3_MSG_SUB_CMD(MHL_MSG_RCPE,bstatuscode);
	HDMI_PRINTF("[CBUS_LOG]CBUS_MSG_RCPE  bstatuscode = %x \n",bstatuscode);
}

/***************************************************************************************/
//Function :  CBUS_MSG_UCP(u_int8_t bkeycode)
//Description: MHL_MSG_UCP
//                  UTF-8 Character Protocol (UCP)
//return: SEND MSG RCP key To follower
/**************************************************************************************/
void CBUS_MSG_UCP(u_int8_t bkeycode)
{
	bCBUS_MSC_CMD3_MSG_SUB_CMD(MHL_MSG_UCP,bkeycode);
	HDMI_PRINTF("[CBUS_LOG]CBUS_MSG_UCP  bkeycode = %x \n",bkeycode);
}

/***************************************************************************************/
//Function :  CBUS_MSG_UCP(u_int8_t bkeycode)
//Description: MHL_MSG_UCPK
//                  UTF-8 Character Protocol (UCP)
//return: SEND MSG RCP key To follower
/**************************************************************************************/
void CBUS_MSG_UCPK(u_int8_t bkeycode)
{
	bCBUS_MSC_CMD3_MSG_SUB_CMD(MHL_MSG_UCPK,bkeycode);
	HDMI_PRINTF("[CBUS_LOG]CBUS_MSG_UCPK  bkeycode = %x \n",bkeycode);
}

/***************************************************************************************/
//Function :  CBUS_MSG_UCPE(u_int8_t bkeycode)
//Description: MHL_MSG_UCPE
//                  UTF-8 Character Protocol (UCP)
//return: SEND MSG RCP key To follower
/**************************************************************************************/
void CBUS_MSG_UCPE(u_int8_t bkeycode)
{
	bCBUS_MSC_CMD3_MSG_SUB_CMD(MHL_MSG_UCPE,bkeycode);
	HDMI_PRINTF("[CBUS_LOG]CBUS_MSG_UCPE  bkeycode = %x \n",bkeycode);
}

//--------------------------------------------------
// Description  : Send MSC HPD Operation
// Input Value  : ucInputPort --> D0 or D1
//                enumMSCType --> MSC Command
//                enumMSCOffset --> MSC Device Register
//                enumMSCValue --> MSC Device Register Field
// Output Value : Success or Different Fail Situations
//--------------------------------------------------
u_int8_t MHLMscFIFOSendCommand( u_int8_t enumMSCCommand, u_int8_t enumMSCOffset, u_int8_t enumMSCValue, u_int8_t ucDataLength, u_int8_t *pucData)
{
	u_int8_t ucTimeOut = 100;
	u_int8_t ucSendType = 0;
	u_int8_t ucWaitType = 0;
	u_int8_t ucI = 0;
	u_int8_t Receive_DATA = 0;
	//  HDMI_PRINTF("[CBUS_LOG] cloud MHLMscFIFOSendCommand = %x ,  offset = %x ,  enumMSCValue = %x \n" ,enumMSCCommand,enumMSCOffset,enumMSCValue);
	switch(enumMSCCommand) {
		case MHL_MSC_CMD_CODE_SET_INT:   //MHL_MSC_CMD_CODE_WRT_STAT
		case MHL_MSC_CMD_CODE_MSC_MSG:

			ucSendType = MHL_TX_CASE_COM_OFF_DAT;
			ucWaitType = MHL_TX_WAIT_CASE_CMD_ONLY;
			break;

		case MHL_MSC_CMD_CODE_SET_HPD:
		case MHL_MSC_CMD_CODE_CLR_HPD:

			ucSendType = MHL_TX_CASE_COMMAND;
			ucWaitType = MHL_TX_WAIT_CASE_CMD_ONLY;
			break;


		case MHL_MSC_CMD_CODE_GET_STATE:
		case MHL_MSC_CMD_CODE_GET_VENDOR_ID:
		case MHL_MSC_CMD_CODE_GET_MSC_ERR:

			ucSendType = MHL_TX_CASE_COMMAND;
			ucWaitType = MHL_TX_WAIT_CASE_DATA_ONLY;
			break;

		case MHL_MSC_CMD_CODE_ABORT:

			ucSendType = MHL_TX_CASE_COMMAND;
			ucWaitType = MHL_TX_WAIT_CASE_CMD_NO_WAIT;
			break;

		case MHL_MSC_CMD_CODE_WRT_BURST:

			ucSendType = MHL_TX_CASE_COM_OFF_DAT_COM;
			ucWaitType = MHL_TX_WAIT_CASE_CMD_ONLY;
			break;

		case  MHL_MSC_CMD_CODE_READ_DEVCAP:
			ucSendType = MHL_TX_CASE_COM_OFF;
			ucWaitType = MHL_TX_WAIT_CASE_CMD_DATA;
			break;

		default:

			break;
	}


	// Check If Source Has Sent An ABORT Packet
	if(CBUS_CBUS_MSC_06_get_abort_req_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		//clear Abort flag
		//hdmiport_mask(CBUS_MSC_06_reg,~(CBUS_MSC_06_abort_req_irq_mask),CBUS_MSC_06_abort_req_irq_mask);
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_abort_req_irq_mask);
		/*
		SET_MHL_READY_TO_TRANSMIT(0);  // can't transmit

		// delay 2.5 sec then set ready to transmit
		SET_MHL_TIMER_SEC(2.5);
		 HDMI_PRINTF("[CBUS_LOG]MHLMscFIFOSendCommand  GET ABORT \n");
		 */

		return _MHL_ABORT_FAIL;
	}
	//  HDMI_PRINTF("[CBUS_LOG] cloud MHLMscFIFOSendCommand REQUEST !!! \n" );
	// Clear FIFO and Send Command Only
	FW0Requester_set_tx_case(ucSendType);
	hdmiport_mask(CBUS_FW0_REQ_00_reg,~(CBUS_FW0_REQ_00_fw0_fifo_clr_mask), CBUS_FW0_REQ_00_fw0_fifo_clr_mask);
	// Set MSC Command
	FW0Requester_set_cmd1(enumMSCCommand);
	// Set MSC Offset
	FW0Requester_set_offset(enumMSCOffset);
	if(enumMSCCommand == MHL_MSC_CMD_CODE_WRT_BURST) {
		HDMI_PRINTF("[CBUS_LOG] SENDING WRT_BURST CMD\n");
		// Set MSC Last Command
		FW0Requester_set_cmd2(MHL_MSC_CMD_CODE_EOF);
		// Set MSC Data
		for(ucI = 0; ucI < ucDataLength; ucI++) {
			FW0Requester_set_data(pucData[ucI]);
		}
	} else {
		// Set MSC Value
		FW0Requester_set_data(enumMSCValue);
	}

	// MSC Packet and Wait Type
	FW0Requester_set_head(MHL_HEADER_MSC_CMD);
	FW0Requester_set_wait_case(ucWaitType);
	// Send Request
	FW0Requester_set_req_en(1);

	// Check if Process is finished
	while(--ucTimeOut != 0) {

		//  HDMI_PRINTF("[CBUS_LOG]HW REQ finish  = %d  , Error flag = %d  \n",FW0Requester_get_finish_flag() ,FW0Requester_get_error_flag());
		if(CBUS_CBUS_MSC_06_get_abort_req_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) { //abort occur
			//clear Abort flag
			//hdmiport_mask(CBUS_MSC_06_reg,~(CBUS_MSC_06_abort_req_irq_mask),CBUS_MSC_06_abort_req_irq_mask);
			hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_abort_req_irq_mask);
			HDMI_PRINTF("[CBUS_LOG]SEND CMD return Abort \n");
			return _MHL_ABORT_FAIL;
		} else if((FW0Requester_get_finish_flag() == TRUE) && (FW0Requester_get_error_flag() == 0x00)) {
			// Transmit success
			// Clear Flag

			FW0Requester_set_finish_flag(1);

			if(ucWaitType == MHL_TX_WAIT_CASE_CMD_NO_WAIT) {
				//   HDMI_PRINTF("[CBUS_LOG]Transmit finish !!_MHL_SUCCESS!!!!!!\n");
				return _MHL_SUCCESS;
			} else {
				// Check ACK Packet
				// HDMI_PRINTF("[CBUS_LOG]Transmit finish !!!!!!\n");
				if(FW0Requester_get_cmd()== MHL_MSC_CMD_CODE_ACK) {
					if(ucWaitType == MHL_TX_WAIT_CASE_CMD_DATA) {
						Receive_DATA = FW0Requester_get_data();
						HDMI_PRINTF("[CBUS_LOG]read data from Tx %x \n",Receive_DATA);
					}
					//    HDMI_PRINTF("[CBUS_LOG]SEND CMD return _MHL_SUCCESS \n");
					return _MHL_SUCCESS;
				} else {
					HDMI_PRINTF("[CBUS_LOG]SEND CMD return _MHL_FAIL \n");
					return _MHL_FAIL;
				}
			}
		} else if((FW0Requester_get_error_flag() == TRUE)  && (FW0Requester_get_error_code() == _MHL_ERR_CODE_PRO_ER)) {
			// Clear Flags
			FW0Requester_set_finish_flag(1);
			FW0Requester_set_error_flag(1);
			FW0Requester_CLR_error_code() ;
			HDMI_PRINTF("[CBUS_LOG]SEND CMD return _MHL_ABORT_REPLY \n");
			return _MHL_ABORT_REPLY;
		}
		msleep(10);
		//  ScalerTimerDelayXms(1);
	}

	// Clear Flags
	FW0Requester_set_finish_flag(1);
	FW0Requester_set_error_flag(1);
	FW0Requester_CLR_error_code() ;
	HDMI_PRINTF("[CBUS_LOG]not finish ucTimeOut = %d !! _MHL_FAIL !!!!!! \n",ucTimeOut);
	return _MHL_FAIL;
}

//--------------------------------------------------
// Description  : Send MSC HPD Operation
// Input Value  : ucInputPort --> D0 or D1
//                enumMSCType --> MSC Command
//                enumMSCOffset --> MSC Device Register
//                enumMSCValue --> MSC Device Register Field
// Output Value : Success or Fail
//--------------------------------------------------
u_int8_t MHLMscSendCommand( u_int8_t enumMSCCommand, u_int8_t enumMSCOffset, u_int8_t enumMSCValue)
{
	u_int8_t ucResultPacket = 0;

	if(GET_MHL_READY_TO_TRANSMIT() == 1) {
		ucResultPacket = MHLMscFIFOSendCommand( enumMSCCommand, enumMSCOffset, enumMSCValue, 0, _NULL_POINTER);
		//if (MHL_MSC_CMD_CODE_MSC_MSG == enumMSCCommand && MHL_MSG_RAPK==enumMSCOffset)
		//HDMI_PRINTF("[CBUS_LOG] SEND Command = %x,%x,%x Result = %x\n" , enumMSCCommand, enumMSCOffset, enumMSCValue, ucResultPacket);
		switch(ucResultPacket) {
			case _MHL_SUCCESS: // Source reply ACK Packet

				SET_MHL_READY_TO_TRANSMIT(1);

				return _MHL_OK;

				break;

			case  _MHL_FAIL:
			case _MHL_ABORT_FAIL: // Source reply ABORT Packet

				SET_MHL_READY_TO_TRANSMIT(0);  // can't transmit

				// delay 2.5 sec then set ready to transmit
				SET_MHL_TIMER1_SEC(250);  // 10 msec * 250 = 2.5sec
				HDMI_PRINTF("[CBUS_LOG][ERR]  SEND command fail will wait 2.5 sec can send command\n");
				return _MHL_NG;

				break;

			case _MHL_ABORT_REPLY: // Source Reply Data Packet Instead of Control Packet

				MHLMscFIFOSendCommand( MHL_MSC_CMD_CODE_ABORT, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL, 0, _NULL_POINTER);
				HDMI_PRINTF("[CBUS_LOG][ERR] MHLMscSendCommand _MHL_ABORT_REPLY\n");
				return _MHL_NG;

				break;

			default: // Source Reply No Packet(Timeout) or NACK

				return _MHL_NG;

				break;
		}
	} else {
		HDMI_PRINTF("[CBUS_LOG] MHLMscSendCommand: cannot transmit!!!\n");
		return _MHL_NG;
	}
}

void OCbus_Power(char enable)
{
unsigned char nport = MHL_CHANNEL;

	if (enable) {
		hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg,
			~(CBUS_PMM_CBUS_PHY_4_en_cbus_rx_mask|CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx_mask|CBUS_PMM_CBUS_PHY_4_en_cmp_rx_mask|CBUS_PMM_CBUS_PHY_4_en_driver_rx_mask),
			(CBUS_PMM_CBUS_PHY_4_en_cbus_rx_mask|CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx_mask|CBUS_PMM_CBUS_PHY_4_en_cmp_rx_mask|CBUS_PMM_CBUS_PHY_4_en_driver_rx_mask));
		hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg, ~CBUS_PMM_CBUS_PHY_4_sel_cbusb_gpio_rx_mask, 0);
		hdmiport_mask(HDMI_HDMI_VCR_reg, ~(HDMI_HDMI_VCR_cbus_ddc_chsel_mask), HDMI_HDMI_VCR_cbus_ddc_chsel_mask);
	} else {
		hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg,
			~(CBUS_PMM_CBUS_PHY_4_en_cbus_rx_mask|CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx_mask|CBUS_PMM_CBUS_PHY_4_en_cmp_rx_mask|CBUS_PMM_CBUS_PHY_4_en_driver_rx_mask),
			0);
		hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg, ~CBUS_PMM_CBUS_PHY_4_sel_cbusb_gpio_rx_mask, CBUS_PMM_CBUS_PHY_4_sel_cbusb_gpio_rx_mask);
		hdmiport_mask(HDMI_HDMI_VCR_reg, ~(HDMI_HDMI_VCR_cbus_ddc_chsel_mask), 0);
	}
}

//--------------------------------------------------
// Description  : Power Process for CBUS Phy
// Input Value  : bEn --> _ON/_OFF
// Output Value : None
//--------------------------------------------------
void CBUSSwitch(u_int8_t benable)
{

	if (benable) {
		lib_hdmi_mhl_z300_sel(MHL_CHANNEL, 1, 0);
		OCbus_Power(1);

		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_dis_irq_en_mask|CBUS_PMM_CBUS_STANDBY_00_wake_irq_en_mask), 0);
		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_08_reg, ~(CBUS_PMM_CBUS_STANDBY_08_cable_det_mask), CBUS_PMM_CBUS_STANDBY_08_cable_det_mask);
	} else {
		OCbus_Power(0);

		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_dis_irq_en_mask|CBUS_PMM_CBUS_STANDBY_00_wake_irq_en_mask), 0);
		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_08_reg, ~(CBUS_PMM_CBUS_STANDBY_08_cable_det_mask), 0);
	}

	MHL_Z100k_Switch(MHL_CHANNEL, 0);
}

#if 0
//--------------------------------------------------
// Description  :Cbus power on or poer off setting
// Input Value  : none
// Output Value : no
//
//--------------------------------------------------
void Cbus_Power(char enable)
{
	if (enable) {
		OCbus_Power(1);
	} else {
		if (MHLMscSendCommand(MHL_MSC_CMD_CODE_CLR_HPD, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL) == _MHL_OK) {
			HDMI_PRINTF("[CBUS_LOG] _MHL_CLR_HPD!!!!!\n");
		} else {
			HDMI_PRINTF("[CBUS_LOG]  _MHL_CLR_HPD FAIL!!!!\n");
		}
		if (DETECT_MHL2_IN) {
			hdmiport_mask(CBUS_PMM_CBUS_PHY_3_reg, ~(CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask), 0);
		}

		OCbus_Power(0);
		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_08_reg, ~(CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask), (CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask));
		SET_MHL_PROCESS_STATE(_MHL_STATE_INITIAL);
		SET_SETTINGMHL(0);
		//HDMI_PRINTF("[CBUS_LOG] Cbus_Power OFF  !!!\n");
	}
}
#endif

void mhl_release(void)
{
	if (MHLMscSendCommand(MHL_MSC_CMD_CODE_CLR_HPD, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL) == _MHL_OK) {
		HDMI_PRINTF("[CBUS_LOG] _MHL_CLR_HPD!!!!!\n");
	} else {
		HDMI_PRINTF("[CBUS_LOG]  _MHL_CLR_HPD FAIL!!!!\n");
	}
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_08_reg, ~(CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask), (CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask));

	newbase_hdmi_set_is_mhl(MHL_CHANNEL, 0);
	newbase_hdmi_set_is_mhl_ppmode(MHL_CHANNEL, MHL_IsPPMode());
	SET_ISMHL(0);
	SET_MHL_PROCESS_STATE(_MHL_STATE_INITIAL);
	if (GET_SETTINGMHL()) {
		lib_hdmi_z0_set(MHL_CHANNEL, LN_ALL, 1);
		mhl_clk_switch(MHL_CHANNEL, 0);
		MHLSwitch(MHL_CHANNEL,0);
		CBUSSwitch(0);

		PINMUX_SEL_HDMI_OUT();
		SET_SETTINGMHL(0);
	}
}

//--------------------------------------------------
// Description  : Power Process for CBUS Phy
// Input Value  : bEn --> _ON/_OFF
// Output Value : None
//--------------------------------------------------
void MHLSwitch(u_int8_t nport, u_int8_t benable)
{
	if (benable) {
		if (_bMhl_clk_mode) {

			hdmiport_mask(D614[nport], ~(MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_dvi_ch_sync_mask), MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en_mask);
			hdmiport_mask(HDMI_MHL_HDMI_MAC_CTRL_reg, ~(HDMI_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_mask|HDMI_MHL_HDMI_MAC_CTRL_pp_mode_output_mask|HDMI_MHL_HDMI_MAC_CTRL_packet_mhl_en_mask), (HDMI_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_mask|HDMI_MHL_HDMI_MAC_CTRL_pp_mode_output_mask|HDMI_MHL_HDMI_MAC_CTRL_packet_mhl_en_mask));
			hdmiport_mask(HDMI_MHL_HDMI_MAC_CTRL_reg, ~(HDMI_MHL_HDMI_MAC_CTRL_xor_pixel_sel_mask), HDMI_MHL_HDMI_MAC_CTRL_xor_pixel_sel(3));

			HDMI_PRINTF("[MHL_LOG] MHLswitch ppmode=1\n");
		} else {

			hdmiport_mask(D614[nport], ~(MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_dvi_ch_sync_mask), MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_dvi_ch_sync_mask);
			hdmiport_mask(HDMI_MHL_HDMI_MAC_CTRL_reg, ~(HDMI_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_mask|HDMI_MHL_HDMI_MAC_CTRL_pp_mode_output_mask|HDMI_MHL_HDMI_MAC_CTRL_packet_mhl_en_mask), 0);
			hdmiport_mask(HDMI_MHL_HDMI_MAC_CTRL_reg, ~(HDMI_MHL_HDMI_MAC_CTRL_xor_pixel_sel_mask), HDMI_MHL_HDMI_MAC_CTRL_xor_pixel_sel(0));

			HDMI_PRINTF("[MHL_LOG] MHLswitch ppmode=0\n");
		}

#if MHL3_ENABLE
		if (mhl_is_ver3x()) {
			hdmiport_mask (HDMI_TMDS_ERRC_reg, ~HDMI_TMDS_ERRC_nl_mask, HDMI_TMDS_ERRC_nl(0));
		} else {
			hdmiport_mask (HDMI_TMDS_ERRC_reg, ~HDMI_TMDS_ERRC_nl_mask, HDMI_TMDS_ERRC_nl(3));
		}

		hdmiport_mask(D700[nport], ~MHL_P0_PORT0_MHL3_CTRL_mhl_ver3_en_mask, MHL_P0_PORT0_MHL3_CTRL_mhl_ver3_en(mhl_is_ver3x()));
#endif
	} else {                          // MHL plug out  HDMI MODE

		hdmiport_mask(D614[nport], ~(MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_dvi_ch_sync_mask), 0);

		hdmiport_mask(HDMI_MHL_HDMI_MAC_CTRL_reg, ~(HDMI_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_mask|HDMI_MHL_HDMI_MAC_CTRL_pp_mode_output_mask|HDMI_MHL_HDMI_MAC_CTRL_packet_mhl_en_mask), 0);
		hdmiport_mask(HDMI_MHL_HDMI_MAC_CTRL_reg, ~(HDMI_MHL_HDMI_MAC_CTRL_xor_pixel_sel_mask), HDMI_MHL_HDMI_MAC_CTRL_xor_pixel_sel(0));

		hdmiport_mask (HDMI_TMDS_ERRC_reg, ~HDMI_TMDS_ERRC_nl_mask, HDMI_TMDS_ERRC_nl(3));
#if MHL3_ENABLE
		hdmiport_mask(D700[nport], ~MHL_P0_PORT0_MHL3_CTRL_mhl_ver3_en_mask, 0);
#endif
	}

	lib_hdmi_mhl_z300_sel(nport, benable, mhl_is_ver3x());

}


//--------------------------------------------------
// Description  : TMDS Set PHY Function (EXINT0 Only)
// Input Value  : Measured Clk Count for PHY Setting
// Output Value : None
//--------------------------------------------------
void MHLTmdsSetPhy(void)
{
	u_int8_t bTemp;

	// Check if Packed Pixel Mode
	bTemp = CBUS_MSC_REG_31_get_clk_mode(hdmi_in(CBUS_MSC_REG_31_reg));
	//ScalerSetByte_EXINT0(P28_AC_CBUS0_CTRL_0C, _MSC_LINK_MODE);
	if(bTemp == LINK_MODE_CLK_PP_MODE) {
		//Set CDR counter
		/*
		ScalerSetBit_EXINT0(PB_C8_FLD_CONT_0, ~(_BIT7 | _BIT6), _BIT7);
		ScalerSetByte_EXINT0(PB_C9_FLD_CONT_1, 0x3F);
		ScalerSetByte_EXINT0(PB_CA_FLD_CONT_2, 0x4F);
		*/
	} else if(bTemp == LINK_MODE_CLK_24BIT_MODE) { // Otherwise --> 24 Bit Mode
		//Set CDR counter
		/*
		ScalerSetBit_EXINT0(PB_C8_FLD_CONT_0, ~(_BIT7 | _BIT6), _BIT7);
		ScalerSetByte_EXINT0(PB_C9_FLD_CONT_1, 0x3F);
		ScalerSetByte_EXINT0(PB_CA_FLD_CONT_2, 0x6A);
		*/
	}


}
/***************************************************************************************/
//Function :  MHL_SBUS_TIMER_ISR(u_int8_t bkeycode)
//Description: MHL cbus 10msec modify flag & event
//
//return: SEND MSG RCP key To follower
/**************************************************************************************/
void CBUS_TIMER_Handle_ISR(void)
{
	if(GET_MHL_TIMER1_SEC() !=0 ) {  // set CBUS can transmit command
		SET_MHL_TIMER1_SEC((GET_MHL_TIMER1_SEC()-1));      //count down
	} else {
		SET_MHL_READY_TO_TRANSMIT(1);
		//  HDMI_PRINTF("[CBUS_LOG]Ready to send command \n");

	}

	if(GET_MHL_TIMER2_SEC() !=0 ) {
		SET_MHL_TIMER2_SEC((GET_MHL_TIMER2_SEC()-1));      //count down
		//   HDMI_PRINTF("[CBUS_LOG]SET_MHL_RECONNECT_OK Count down   = %d \n",GET_MHL_TIMER2_SEC());
	} else {
		SET_MHL_RECONNECT_OK(1); // set FSM can re connect
		// HDMI_PRINTF("[CBUS_LOG]SET_MHL_RECONNECT_OK  = %d \n",GET_MHL_RECONNECT_OK());
	}

	if(GET_MHL_TIMER3_SEC() !=0 ) {
		SET_MHL_TIMER3_SEC((GET_MHL_TIMER3_SEC()-1));      //count down
	} else {
		SET_MHL_READY_TO_RESEND( 1);
		//   HDMI_PRINTF("[CBUS_LOG]SET_MHL_READY_TO_RESEND\n");

	}

}


/***************************************************************************************/
//Function :   void CBUS_InitialPHYSettings(void)
//Description:  Calibration for 1K/100K and LDO Level Adjust
//
//return: S
/**************************************************************************************/
void CBUS_InitialPHYSettings(void)
{
	hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg,
		~(CBUS_PMM_CBUS_PHY_4_sel_input_high_rx_mask|CBUS_PMM_CBUS_PHY_4_sel_input_low_rx_mask|CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx_mask|CBUS_PMM_CBUS_PHY_4_cbus_strc_rx_mask),
		(CBUS_PMM_CBUS_PHY_4_sel_input_high_rx(0)|CBUS_PMM_CBUS_PHY_4_sel_input_low_rx(1)|CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx_mask|CBUS_PMM_CBUS_PHY_4_cbus_strc_rx(4)));

	hdmiport_mask(CBUS_PMM_CBUS_PHY_7_reg, ~(CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx_mask|CBUS_PMM_CBUS_PHY_7_en_ldo_rx_mask|CBUS_PMM_CBUS_PHY_7_en_bias_rx_mask),
  	CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx(0)|CBUS_PMM_CBUS_PHY_7_en_ldo_rx(1)|CBUS_PMM_CBUS_PHY_7_en_bias_rx(1));

	hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg,~(CBUS_PMM_CBUS_PHY_4_mhl_r1k_rx_mask),CBUS_PMM_CBUS_PHY_4_mhl_r1k_rx(6));

	//hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg, ~(CBUS_PMM_CBUS_PHY_4_adjr_100k_rx_mask), CBUS_PMM_CBUS_PHY_4_adjr_100k_rx(0xa));
	hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg, ~(CBUS_PMM_CBUS_PHY_4_en_res_cal_cbus_rx_mask|CBUS_PMM_CBUS_PHY_4_auto_k_100k_rx_mask), 0);
	hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg, ~(CBUS_PMM_CBUS_PHY_4_auto_k_100k_rx_mask), (CBUS_PMM_CBUS_PHY_4_auto_k_100k_rx_mask));
	hdmiport_mask(CBUS_PMM_CBUS_PHY_4_reg, ~CBUS_PMM_CBUS_PHY_4_en_res_cal_cbus_rx_mask, CBUS_PMM_CBUS_PHY_4_en_res_cal_cbus_rx_mask);

	MHL_Z100k_Switch(MHL_CHANNEL, 0);
}

/***************************************************************************************/
//Function :   void MHLInitialMACSettings(void)
//Description:  Cbus setting
//
//return: S
/**************************************************************************************/
void MHLInitialMACSettings(void)
{

#if 0
	if (!hdmi_in(PLL27X_REG_SYS_PLL_AUD3_reg) & _BIT0) {
		rtd_hwsem_lock(SEMA_HW_SEM_5_SCPU_2);  //use hardware semiphore to protect from audio cpu access
		hdmi_out(PLL27X_REG_SYS_PLL_AUD3_reg,0x00000000);//disable pllaud
		hdmi_out(PLL27X_REG_SYS_PLL_512FS_2_reg,0x00000004);//Disable PLL512Fs output
		hdmi_out(PLL27X_REG_SYS_PLL_27X2,0x88085501);//Enable Audio PLL related LDO, PLL_POW_LDO11V & PLL_POW_LDO
		msleep(15);//at least > 10us
		hdmi_out(PLL27X_REG_SYS_PLL_PSAUD1,0x00000000);//Disable PSAUD phase shifter & PSAUD all function
		msleep(15);//at least > 10us
		hdmi_out(PLL27X_REG_SYS_PLL_PSAUD1,0x00000004);//PSAUD_EN 0 --> 1
		msleep(15);//at least > 10us
		hdmi_out(PLL27X_REG_SYS_PLL_PSAUD1,0x0000000C);//PSAUD_PSEN 0 --> 1
		msleep(15);//at least > 10us
		hdmi_out(PLL27X_REG_SYS_PLL_512FS_2_reg,0x00000005);//PW ON PLL512Fs
		msleep(15);//at least > 10us
		hdmi_out(PLL27X_REG_SYS_PLL_512FS_2_reg,0x00000007);//PLL512Fs from 0 --> 1 (normal mode)
		msleep(15);//at least > 10us
		hdmi_out(PLL27X_REG_SYS_PLL_AUD3_reg,0x00000019);//Enable PLLAUD_CK196M/CK295M output
		hdmi_out(PLL27X_REG_SYS_PLL_512FS_2_reg,0x00000003);//Enable PLL512Fs output
		rtd_hwsem_unlock(SEMA_HW_SEM_5_SCPU_2);
	        msleep(50);//wait audio clock output stable
	}
#endif
	// Write clear wake pulse & discovery pulse
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask),(CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask));

	// Set MHL 1MHz Clk Divider  27M clock
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_01_reg, ~(CBUS_PMM_CBUS_STANDBY_01_clk_1m_div_mask), CBUS_PMM_CBUS_STANDBY_01_clk_1m_div(13));

	//cloud fix for HTC issue
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_01_reg, ~(CBUS_PMM_CBUS_STANDBY_01_clk_1k_div_mask), CBUS_PMM_CBUS_STANDBY_01_clk_1k_div(519));  //519* 1.25
	//initial wake up pulse width
	//2013 0621 for HTC wake up timing  16.25msec ~33.75msec
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_04_reg,~(CBUS_PMM_CBUS_STANDBY_04_wake_offset_low_mask|CBUS_PMM_CBUS_STANDBY_04_wake_offset_low2_mask|CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask|CBUS_PMM_CBUS_STANDBY_04_wake_cnt_mask),(CBUS_PMM_CBUS_STANDBY_04_wake_offset(7)|CBUS_PMM_CBUS_STANDBY_04_wake_offset_low(7)|CBUS_PMM_CBUS_STANDBY_04_wake_offset_low2(7)));//20msec +-7msec

	//Set Cbus discuss  Low Time to 150us
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_02_reg, ~(CBUS_PMM_CBUS_STANDBY_02_disconn_mask), CBUS_PMM_CBUS_STANDBY_02_disconn(1)); //cloud test for 4.3.20

	// Set Discovery Upper/Lower Bound  60 micro second ~ 140 micro sec
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_05_reg, ~(CBUS_PMM_CBUS_STANDBY_05_dis_upper_mask|CBUS_PMM_CBUS_STANDBY_05_dis_lower_mask), (CBUS_PMM_CBUS_STANDBY_05_dis_upper(5)|CBUS_PMM_CBUS_STANDBY_05_dis_lower(5)));
	hdmiport_mask(CBUS_CBUS_DUMMY0_reg, ~(CBUS_CBUS_DUMMY0_ddc_idle_no_tx_abort_gated_mask), CBUS_CBUS_DUMMY0_ddc_idle_no_tx_abort_gated_mask); /* 4.3.17.2 */
}

void CDF_Cability_Setting(void)
{
	hdmiport_mask(CBUS_MSC_REG_01_reg, ~CBUS_MSC_REG_01_mhl_ver_mask, (CDF_CR_MHL_VER_MAJOR<<4)|CDF_CR_MHL_VER_MINOR);  //MHL 2.0
	hdmiport_mask(CBUS_MSC_REG_02_reg, ~(CBUS_MSC_REG_02_plim_mask|CBUS_MSC_REG_02_pow_mask|CBUS_MSC_REG_02_dev_type_mask), CBUS_MSC_REG_02_plim(CDF_CR_POW_PLIM)|CBUS_MSC_REG_02_pow(CDF_CR_POW)|CBUS_MSC_REG_02_dev_type(CDF_CR_DEV_TYPE));  //MHL 2.0
	//adopter_H
	hdmi_out (CBUS_MSC_REG_03_reg,CDF_CR_ADOPTER_ID_H);
	// adopter_L
	hdmi_out (CBUS_MSC_REG_04_reg,CDF_CR_ADOPTER_ID_L);


	hdmiport_mask(CBUS_MSC_REG_05_reg, ~(CBUS_MSC_REG_05_vid_link_md_mask|CBUS_MSC_REG_05_supp_vga_mask|CBUS_MSC_REG_05_supp_islands_mask|CBUS_MSC_REG_05_supp_ppixel_mask|CBUS_MSC_REG_05_supp_yuv422_mask|CBUS_MSC_REG_05_supp_yuv444_mask|CBUS_MSC_REG_05_supp_rgb444_mask),
		(CBUS_MSC_REG_05_vid_link_md(CDF_CR_SUPP_16BPP)|CBUS_MSC_REG_05_supp_vga(CDF_CR_SUPP_VGA))|CBUS_MSC_REG_05_supp_islands(CDF_CR_SUPP_ISLANDS)|CBUS_MSC_REG_05_supp_ppixel(CDF_CR_SUPP_PPIXEL)|CBUS_MSC_REG_05_supp_yuv422(CDF_CR_SUPP_YCBCR422)|CBUS_MSC_REG_05_supp_yuv444(CDF_CR_SUPP_YCBCR444)|CBUS_MSC_REG_05_supp_rgb444(CDF_CR_SUPP_YCBCR444));// not support PP mode

	hdmiport_mask(CBUS_MSC_REG_06_reg, ~(CBUS_MSC_REG_06_aud_hbr_mask|CBUS_MSC_REG_06_aud_8ch_mask|CBUS_MSC_REG_06_aud_2ch_mask), CBUS_MSC_REG_06_aud_hbr(CDF_CR_HBR)|CBUS_MSC_REG_06_aud_8ch(CDF_CR_AUD_8CH)|CBUS_MSC_REG_06_aud_2ch(CDF_CR_AUD_2CH));// not support PP mode

	hdmiport_mask(CBUS_MSC_REG_07_reg, ~(CBUS_MSC_REG_07_video_type_mask|CBUS_MSC_REG_07_vt_game_mask|CBUS_MSC_REG_07_vt_cinema_mask|CBUS_MSC_REG_07_vt_photo_mask|CBUS_MSC_REG_07_vt_graphics_mask),CBUS_MSC_REG_07_vt_game(CDF_CR_VT_GAME)|CBUS_MSC_REG_07_vt_cinema(CDF_CR_VT_CINEMA)|CBUS_MSC_REG_07_vt_photo(CDF_CR_VT_PHOTO)|CBUS_MSC_REG_07_vt_graphics(CDF_CR_VT_GRAPHICS));

	hdmiport_mask(CBUS_MSC_REG_08_reg, ~(CBUS_MSC_REG_08_ld_gui_mask|CBUS_MSC_REG_08_ld_speaker_mask|CBUS_MSC_REG_08_ld_record_mask|CBUS_MSC_REG_08_ld_tuner_mask|CBUS_MSC_REG_08_ld_media_mask|CBUS_MSC_REG_08_ld_audio_mask|CBUS_MSC_REG_08_ld_video_mask|CBUS_MSC_REG_08_ld_display_mask),CBUS_MSC_REG_08_ld_gui(CDF_CR_LD_GUI)|CBUS_MSC_REG_08_ld_speaker(CDF_CR_LD_SPEAKER)|CBUS_MSC_REG_08_ld_record(CDF_CR_LD_RECORD)|CBUS_MSC_REG_08_ld_tuner(CDF_CR_LD_TUNER)|CBUS_MSC_REG_08_ld_media(CDF_CR_LD_MEDIA)|CBUS_MSC_REG_08_ld_audio(CDF_CR_LD_AUDIO)|CBUS_MSC_REG_08_ld_video(CDF_CR_LD_VIDEO)|CBUS_MSC_REG_08_ld_display(CDF_CR_LD_DISPLAY));//

	hdmiport_mask(CBUS_MSC_REG_09_reg, ~CBUS_MSC_REG_09_bandwid_mask,CBUS_MSC_REG_09_bandwid(CDF_CR_BANDWIDTH));// not support PP mode

	hdmiport_mask(CBUS_MSC_REG_0A_reg, ~(CBUS_MSC_REG_0A_rbp_support_mask|CBUS_MSC_REG_0A_ucp_recv_supp_mask|CBUS_MSC_REG_0A_ucp_send_supp_mask|CBUS_MSC_REG_0A_sp_supp_mask|CBUS_MSC_REG_0A_rap_supp_mask|CBUS_MSC_REG_0A_rcp_supp_mask), CBUS_MSC_REG_0A_rbp_support(CDF_CR_RBP_SUPPORT)|CBUS_MSC_REG_0A_ucp_recv_supp(CDF_CR_UCP_RECV_SUPPORT)|CBUS_MSC_REG_0A_ucp_send_supp(CDF_CR_UCP_SEND_SUPPORT)|CBUS_MSC_REG_0A_sp_supp(CDF_CR_SP_SUPPORT)|CBUS_MSC_REG_0A_rap_supp(CDF_CR_RAP_SUPPORT)|CBUS_MSC_REG_0A_rcp_supp(CDF_CR_RCP_SUPPORT));// not support RAP   RCP  UCP send

	hdmiport_mask(CBUS_MSC_REG_0B_reg, ~CBUS_MSC_REG_0B_device_id_h_mask,CDF_CR_DEVICE_ID_H);// not support PP mode

	hdmiport_mask(CBUS_MSC_REG_0C_reg, ~CBUS_MSC_REG_0C_device_id_l_mask,CDF_CR_DEVICE_ID_L);// not support PP mode

	hdmiport_mask(CBUS_MSC_REG_0D_reg, ~CBUS_MSC_REG_0D_scr_size_mask,CBUS_MSC_REG_0D_scr_size(CDF_CR_SCRATCHPAD_SIZE));// not support PP mode

	hdmiport_mask(CBUS_MSC_REG_0E_reg, ~(CBUS_MSC_REG_0E_stat_size_mask|CBUS_MSC_REG_0E_int_size_mask),CBUS_MSC_REG_0E_stat_size(CDF_CR_INT_SIZE)|CBUS_MSC_REG_0E_int_size(CDF_CR_STAT_SIZE));// not support PP mode


#if MHL3_ENABLE
	hdmi_out(CBUS_MSC_REG_80_reg,
		CBUS_MSC_REG_80_ecbus_s_075(CDF_ECBUS_S_75)|
		CBUS_MSC_REG_80_ecbus_s_8b(CDF_ECBUS_S_8BIT)|
		CBUS_MSC_REG_80_ecbus_s_12b(CDF_ECBUS_S_12BIT)|
		CBUS_MSC_REG_80_ecbus_d_150(CDF_ECBUS_D_150)|
		CBUS_MSC_REG_80_ecbus_d_8b(CDF_ECBUS_D_8BIT));		// eCBUS-S 8-bit Mode support only
	hdmi_out(CBUS_MSC_REG_81_reg,
		CBUS_MSC_REG_81_tmds_150(CDF_TMDS_150)|
		CBUS_MSC_REG_81_tmds_300(CDF_TMDS_300)|
		CBUS_MSC_REG_81_tmds_600(CDF_TMDS_600));		// TMDS Support 6Gbps
	hdmi_out(CBUS_MSC_REG_82_reg,
		CBUS_MSC_REG_82_dev_host(CDF_DEV_HOST)|
		CBUS_MSC_REG_82_dev_device(CDF_DEV_DEVICE)|
		CBUS_MSC_REG_82_dev_charger(CDF_DEV_CHARGER)|
		CBUS_MSC_REG_82_hid_host(CDF_HID_HOST)|
		CBUS_MSC_REG_82_hid_dev(CDF_HID_DEVICE));		// HID Device, Charger, USB Device
	hdmi_out(CBUS_MSC_REG_83_reg,
		CBUS_MSC_REG_83_ld_phone(CDF_LD_PHONE));		// Not Support Phone function
	hdmi_out(CBUS_MSC_REG_84_reg,
		(CDF_ACRFS_DIV_8)|
		(CDF_ACRFS_DIV_16<<1)|
		(CDF_ACRFS_DIV_32<<2));		// ACRFD_DIV_SUPPORT
#endif

}

/***************************************************************************************/
//Function :  MHLTmdsInitial(void)
//Description: MHL Tmds Setting
//
//return: SEND MSG RCP key To follower
/**************************************************************************************/
void MHLTmdsInitial(void)
{

	hdmiport_mask(MHL_P0_PORT0_MHL_CH_CR_reg,
		~(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask),
		(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask)); // follow script, Mac3 default=1
	hdmiport_mask(MHL_P1_PORT1_MHL_CH_CR_reg,
		~(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask),
		(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask)); // follow script, Mac3 default=1
	hdmiport_mask(MHL_P2_PORT2_MHL_CH_CR_reg,
		~(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask),
		(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask)); // follow script, Mac3 default=1
#if HDMI_PHY_TOTAL_NUM==4
	hdmiport_mask(MHL_P3_PORT2_MHL_CH_CR_reg,
		~(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask),
		(MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask|MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask)); // follow script, Mac3 default=1
#endif

#if MHL3_ENABLE
	mhl3_init_phy_mac();
#endif
	CDF_Cability_Setting();

}

/***************************************************************************************/
//Function :  MHL_LinkerSetting(u_int8_t bkeycode)
//Description: MHL_MSG_UCPE
//                  UTF-8 Character Protocol (UCP)
//return: SEND MSG RCP key To follower
/**************************************************************************************/
void CBUS_LinkerSetting(float fSystemClk)
{
#if 0
	hdmi_out(CBUS_LINK_00_reg, 0x00018471);
	hdmi_out(CBUS_LINK_01_reg, 0x00004820);
	hdmi_out(CBUS_LINK_02_reg, 0x00000000);
	hdmi_out(CBUS_LINK_03_reg, 0x0000004c);
	hdmi_out(CBUS_LINK_04_reg, 0x00000065);
	hdmi_out(CBUS_LINK_05_reg, 0x0000000f);
	hdmi_out(CBUS_LINK_06_reg, 0x0000000c);
	hdmi_out(CBUS_LINK_07_reg, 0x00000032);
	hdmi_out(CBUS_LINK_08_reg, 0x00000065);
	//hdmi_out(CBUS_LINK_09_reg, 0x00000074);
	hdmi_out(CBUS_LINK_0A_reg, 0x00000059);
	hdmi_out(CBUS_LINK_0B_reg, 0x00000049);
	hdmi_out(CBUS_LINK_0C_reg, 0x00000020);
	//hdmi_out(CBUS_LINK_0D_reg, 0x00000050);
	hdmi_out(CBUS_LINK_0E_reg, 0x00000059);
	//hdmi_out(CBUS_LINK_0F_reg, 0x00000030);
	hdmi_out(CBUS_LINK_10_reg, 0x00000065);
	hdmi_out(CBUS_LINK_11_reg, 0x00000032);
	//hdmi_out(CBUS_LINK_12_reg, 0x00000084);
	hdmi_out(CBUS_LINK_13_reg, 0x00000056);
#else
	 //ONLY FOR RBUS 250M
        hdmiport_mask(CBUS_CBUS_LINK_00_reg, ~(CBUS_CBUS_LINK_00_sync0_hb_8_0_mask|CBUS_CBUS_LINK_00_sync0_lb_8_0_mask), (CBUS_CBUS_LINK_00_sync0_hb_8_0(0xF0)|CBUS_CBUS_LINK_00_sync0_lb_8_0(0x8C)));
        hdmiport_mask(CBUS_CBUS_LINK_01_reg, ~(CBUS_CBUS_LINK_01_sync1_hb_7_0_mask|CBUS_CBUS_LINK_01_sync1_lb_7_0_mask), (CBUS_CBUS_LINK_01_sync1_hb_7_0(0x5A)|CBUS_CBUS_LINK_01_sync1_lb_7_0(0x28)));
        hdmiport_mask(CBUS_CBUS_LINK_03_reg, ~(CBUS_CBUS_LINK_03_abs_threshold_mask), (CBUS_CBUS_LINK_03_abs_threshold(0x5F)));
        hdmiport_mask(CBUS_CBUS_LINK_04_reg, ~(CBUS_CBUS_LINK_04_parity_time_mask), (CBUS_CBUS_LINK_04_parity_time(0x7D)));
        hdmiport_mask(CBUS_CBUS_LINK_06_reg, ~(CBUS_CBUS_LINK_06_ack_fall_mask), (CBUS_CBUS_LINK_06_ack_fall(0x10)));
        hdmiport_mask(CBUS_CBUS_LINK_07_reg, ~(CBUS_CBUS_LINK_07_ack_0_mask), (CBUS_CBUS_LINK_07_ack_0(0x3E)));
        hdmiport_mask(CBUS_CBUS_LINK_08_reg, ~(CBUS_CBUS_LINK_08_tx_bit_time_mask), (CBUS_CBUS_LINK_08_tx_bit_time(0x7D)));
        hdmiport_mask(CBUS_CBUS_LINK_0A_reg, ~(CBUS_CBUS_LINK_0A_tx_ack_fal_mask), (CBUS_CBUS_LINK_0A_tx_ack_fal(0x6E)));
        hdmiport_mask(CBUS_CBUS_LINK_0B_reg, ~(CBUS_CBUS_LINK_0B_tx_ack_low_hb_mask), (CBUS_CBUS_LINK_0B_tx_ack_low_hb(0x5A)));
        hdmiport_mask(CBUS_CBUS_LINK_0C_reg, ~(CBUS_CBUS_LINK_0C_tx_ack_low_lb_mask), (CBUS_CBUS_LINK_0C_tx_ack_low_lb(0x28)));
        hdmiport_mask(CBUS_CBUS_LINK_0E_reg, ~(CBUS_CBUS_LINK_0E_drv_hi_cbus_mask), (CBUS_CBUS_LINK_0E_drv_hi_cbus(0x1F)));
        hdmiport_mask(CBUS_CBUS_LINK_10_reg, ~(CBUS_CBUS_LINK_10_req_opp_flt_mask), (CBUS_CBUS_LINK_10_req_opp_flt(0x7D)));
        hdmiport_mask(CBUS_CBUS_LINK_11_reg, ~(CBUS_CBUS_LINK_11_req_cont_mask), (CBUS_CBUS_LINK_11_req_cont(0x3E)));
        hdmiport_mask(CBUS_CBUS_LINK_13_reg, ~(CBUS_CBUS_LINK_13_link_time_mask), (CBUS_CBUS_LINK_13_link_time(0xF)));
#endif
}

void CBUSLINKClk(u_int8_t  bmode)
{
	if(bmode == _M2PLL_CLK) {   //standyby mode
		CBUS_LinkerSetting(bmode);
	} else if(bmode == _ACTIVE_CLK) { // ACTIVE mode
		CBUS_LinkerSetting(250);
	}
}

void mhl_disconnect(void)
{
#if MHL3_ENABLE
	mhl3_disconnect();
	mhl3_reset();
#endif
	lib_hdmi_z0_set(MHL_CHANNEL, LN_B, 0);
	MHL_Z100k_Switch(MHL_CHANNEL, 0);
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_04_reg, ~(CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_mask|CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask), (CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask));
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_02_reg, ~(CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv_mask), CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv(4));
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_08_reg, ~(CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask), (CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask));
	hdmiport_mask(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask), (CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask));
	//SET_SETTINGMHL(0);
	SET_MHL_TIMER1_SEC(0);
	_bMhl_No_clock_cnt = 0 ;
	HDMI_PRINTF("[CBUS] %s!!\n", __func__);
}

//--------------------------------------------------
// Description  : detect discovery pulse & wake up pulse by interrupt
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void MHLCBUS_ISR(void)
{
	/* check disconnected state*/
	if ((hdmi_in(CBUS_PMM_CBUS_STANDBY_04_reg)&(CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask)) == (CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask)) {
		mhl_disconnect();
		SET_MHL_PROCESS_STATE(_MHL_STATE_INITIAL);
		HDMI_PRINTF("[CBUS] Disconnected!!\n");
	}


	/* discovery occurs*/
	if ((hdmi_in(CBUS_PMM_CBUS_STANDBY_00_reg)&(CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask)) == (CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask)) {
		/*hdmiport_mask(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask), (CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask));*/
		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask), (CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask));
		HDMI_PRINTF("[CBUS] Wake up occurred!!\n");
	}

	if ((hdmi_in(CBUS_PMM_CBUS_STANDBY_00_reg)&(CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask)) == (CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask)) {
		lib_hdmi_z0_set(MHL_CHANNEL, LN_B, 1);
		MHL_Z100k_Switch(MHL_CHANNEL, 1);
		SET_MHL_READY_TO_TRANSMIT(1); /* 6.3.6.5, if mhl3_ocbus_send_cmd fail, cannot response within 2s*/
#if MHL3_ENABLE
		mhl3_init_state();
		if (mhl3_ocbus_send_cmd()) {
			mhl3_ecbus_discovery();
		}
#endif

		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_00_reg, ~(CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask), (CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask|CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask));
		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_04_reg, ~(CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_mask|CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask), (CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_mask|CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask));

		hdmiport_mask(CBUS_PMM_CBUS_STANDBY_02_reg, ~(CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv_mask), 0);
		SET_MHL_PROCESS_STATE(_MHL_STATE_DISCOVERY_DONE);

		/*printk("[CBUS_LOG]MHLCBUS_ISR !! DETECT Discovery occurs!! \n");*/
	}

#if MHL3_ENABLE
	mhl3_isr();
#endif

}

void mhl_fill_burst_chksum(unsigned char *buf) /*buf[2]=chksum for across all 16 bytes*/
{
	unsigned char i, cksum;
	cksum = 0;
	for (i = 0; i < 16; i++) {
		cksum += buf[i];
	}
	buf[2] = 0xff-cksum+1;
}

//--------------------------------------------------
// Description  : Send Write Burst Operation
// Input Value  : ucInputPort --> D0 or D1
//                ucDataLength --> Data Length
//                pucData --> Data
//                ucMode --> Write Burst Mode
// Output Value : Success or Different Fail Situations
//--------------------------------------------------

u_int8_t MHLMscSendWriteBurst( u_int8_t ucOffset, u_int8_t ucDataLength, u_int8_t *pucData, EnumMHLWriteBurstMode enumMode)
{
	u_int8_t ucResultPacket = 0 , bTimecnt =100;

	if(enumMode == _MHL_WRITE_BURST_WITH_REQ) {

		// Clear Grant To Write Flag
		hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_grt_wrt_mask);
		// Send Request to Write
		MHLMscSendCommand( MHL_MSC_CMD_CODE_SET_INT, _MHL_REG_RCHANGE_INT, REQ_WRT);

		//  this area is different with monitor
		// Disable Access Port Auto Increase
		//    ScalerSetBit(P28_AB_CBUS0_CTRL_0B, ~_BIT0, 0x00);
		// Polling Grant to Write
		//    ScalerSetByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT);
		//    ScalerTimerPollingFlagProc(100, P28_AD_CBUS0_CTRL_0D, _MSC_GRT_WRT, _TRUE);
		// Enable Access Port Auto Increase
		//    ScalerSetBit(P28_AB_CBUS0_CTRL_0B, ~_BIT0, _BIT0);

		do {
			msleep(10);
			bTimecnt --;
			//if(CBUS_MSC_REG_20_get_grt_wrt(hdmi_in(CBUS_MSC_REG_20_reg)))   break ;
		} while ((!CBUS_MSC_REG_20_get_grt_wrt(hdmi_in(CBUS_MSC_REG_20_reg)))&&(bTimecnt) );

		if(bTimecnt ==0)    HDMI_PRINTF("[CBUS_LOG]  MHLMscSendWriteBurst  wait Timeout!!! \n" );

	}

	if(GET_MHL_READY_TO_TRANSMIT() == TRUE) {
		ucResultPacket = MHLMscFIFOSendCommand(MHL_MSC_CMD_CODE_WRT_BURST, ucOffset, 0x00, ucDataLength, pucData);

		switch(ucResultPacket) {
			case _MHL_SUCCESS: // Source reply ACK Packet

				// Send Device Scratchpad Change
				MHLMscSendCommand( MHL_MSC_CMD_CODE_SET_INT, _MHL_REG_RCHANGE_INT, DSCR_CHG);

				return _MHL_OK;

				break;

			case _MHL_ABORT_FAIL: // Source reply ABORT Packet

				SET_MHL_READY_TO_TRANSMIT(0);
				SET_MHL_TIMER1_SEC(250); // 250 * 10 msec  =2.5 sec



				return _MHL_NG;

				break;

			case _MHL_ABORT_REPLY: // Source Reply Data Packet Instead of Control Packet

				MHLMscFIFOSendCommand( MHL_MSC_CMD_CODE_ABORT, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL, 0, _NULL_POINTER);

				return _MHL_NG;

				break;

			default: // Source Reply No Packet(Timeout) or NACK

				return _MHL_NG;

				break;
		}
	} else {
		return _MHL_NG;
	}
}

unsigned char MHL_GetScratchpad(unsigned char len, unsigned char *scr)
{
	unsigned char i;
	/*if ( CBUS_MSC_REG_20_get_dscr_chg(hdmi_in(CBUS_MSC_REG_20_reg)) ) {*/
		for (i=0; i<len; i++) {
			if ( i > 31 ) {
				HDMI_PRINTF("[MHL] The max length of Get Scratchpad is 32.\n");
				return FALSE;
			}
			scr[i] = CBUS_MSC_REG_40_get_scratch_40(hdmi_in(CBUS_MSC_REG_40_reg+(i*4)));
		}
		/*hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_dscr_chg_mask);*/
		return TRUE;
	/*}
	return FALSE;*/
}


unsigned char mhl_get_msc_write_burst(void)
{
	if (CBUS_CBUS_MSC_06_get_wr_burst_irq(hdmi_in(CBUS_CBUS_MSC_06_reg))) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_wr_burst_irq_mask);
		/*hdmi_out(CBUS_MSC_06_reg, CBUS_MSC_06_wr_stat_irq_mask);*/
		hdmi_out(CBUS_oCBUS_CTRL_10_reg, CBUS_oCBUS_CTRL_10_wr_xstat_irq_mask);
		return TRUE;
	}
	return FALSE;
}

void mhl_write_burst_handler(void)
{
unsigned char wburst_buff[16];

	if (!mhl_get_msc_write_burst()) {
		return;
	}

	MHL_GetScratchpad(16, wburst_buff);

#if MHL3_ENABLE
	if ((wburst_buff[0] == BIST_SETUP_H) && (wburst_buff[1] == BIST_SETUP_L)) {
		MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_READY, (BIST_ECBUS_READY|BIST_AVLINK_READY|BIST_TERM_READY));
		mhl3_bist_ecbus_set(wburst_buff[3], wburst_buff[4], (wburst_buff[5]<<8)|wburst_buff[6]);
		mhl3_bist_avlink_set(wburst_buff[0x0b], wburst_buff[0x09], (wburst_buff[0x0c]<<8)|wburst_buff[0x0d], wburst_buff[0x0e]);
	} else if ((wburst_buff[0] == VC_ASSIGN_H) && (wburst_buff[1] == VC_ASSIGN_L)) {
		mhl3_virtual_channel_handler(wburst_buff);
	} else if ((wburst_buff[0] == BIST_RETURN_STAT_H) && (wburst_buff[1] == BIST_RETURN_STAT_L)) {
		HDMI_PRINTF("[MHL3] GET BIST, NEED TO DO SOMETHING?\n");
	} else if ((wburst_buff[0] == BIST_DISCARD_H) && (wburst_buff[1] == BIST_DISCARD_L)) {
		HDMI_PRINTF("[MHL3] GET BIST, NEED TO DO SOMETHING?\n");
	} else if ((wburst_buff[0] == BIST_ECHO_REQUEST_H) && (wburst_buff[1] == BIST_ECHO_REQUEST_L)) {
		HDMI_PRINTF("[MHL3] GET BIST, NEED TO DO SOMETHING?\n");
	} else if ((wburst_buff[0] == BIST_ECHO_RESPONSE_H) && (wburst_buff[1] == BIST_ECHO_RESPONSE_L)) {
		HDMI_PRINTF("[MHL3] GET BIST, NEED TO DO SOMETHING?\n");
	} else if ((wburst_buff[0] == EMSC_SUPPORT_H) && (wburst_buff[1] == EMSC_SUPPORT_L)) {
		HDMI_PRINTF("[MHL3] Receive WB-EMSC_SUPPORT (tot=%d,num=%d,%02x,%02x)\n", wburst_buff[3], wburst_buff[5], wburst_buff[6], wburst_buff[7]);
	} else if ((wburst_buff[0] == BITS_PER_PIXEL_FMT_H) && (wburst_buff[1] == BITS_PER_PIXEL_FMT_L)) {
		HDMI_PRINTF("[MHL3] GET BITS_PER_PIXEL_FMT=%d %d %d\n", wburst_buff[6], wburst_buff[7], wburst_buff[8]);
	} else {
		HDMI_PRINTF("[MHL3] GET MSC_WRITE_BURST(0x%02x%02x), NEED TO DO SOMETHING?\n", wburst_buff[0], wburst_buff[1]);
	}
#else
	HDMI_PRINTF("[MHL] GET MSC_WRITE_BURST(0x%02x%02x), NEED TO DO SOMETHING?\n", wburst_buff[0], wburst_buff[1]);
#endif
}

unsigned char mhl_get_bist_trigger(void)
{
	if (CBUS_oCBUS_CTRL_13_get_btrig_irq(hdmi_in(CBUS_oCBUS_CTRL_13_reg))) {
		hdmi_out(CBUS_oCBUS_CTRL_13_reg, CBUS_oCBUS_CTRL_13_btrig_irq_mask);
		return TRUE;
	}
	return FALSE;
}

unsigned char mhl_get_bist_request_stat(void)
{
	if (CBUS_oCBUS_CTRL_13_get_breq_irq(hdmi_in(CBUS_oCBUS_CTRL_13_reg))) {
		hdmi_out(CBUS_oCBUS_CTRL_13_reg, CBUS_oCBUS_CTRL_13_breq_irq_mask);
		return TRUE;
	}
	return FALSE;
}

unsigned char mhl_get_bist_ready(void)
{
	if (CBUS_oCBUS_CTRL_13_get_brdy_irq(hdmi_in(CBUS_oCBUS_CTRL_13_reg))) {
		hdmi_out(CBUS_oCBUS_CTRL_13_reg, CBUS_oCBUS_CTRL_13_brdy_irq_mask);
		return TRUE;
	}
	return FALSE;
}

unsigned char mhl_get_bist_stop(void)
{
	if (CBUS_oCBUS_CTRL_13_get_bstop_irq(hdmi_in(CBUS_oCBUS_CTRL_13_reg))) {
		hdmi_out(CBUS_oCBUS_CTRL_13_reg, CBUS_oCBUS_CTRL_13_bstop_irq_mask);
		return TRUE;
	}
	return FALSE;
}


/***************************************************************************************/
//Function :  MHLMscCheckDeviceINT(void)
//Description: MHL cbus RX check TX request INT
//
//return: SEND MSG RCP key To follower
/**************************************************************************************/

unsigned char MHLMscCheckDeviceINT(void)
{
unsigned char got_cmd = 0;
#if MHL3_ENABLE
unsigned int i;
#endif

	if (CBUS_CBUS_MSC_06_get_wr_stat_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_wr_stat_irq_mask);
		HDMI_PRINTF("[CBUS_LOG]Receive MSC_WR_ST cmd=%x offset=%x data=%x len =%x\n", hdmi_in(CBUS_CBUS_MSC_01_reg), hdmi_in(CBUS_CBUS_MSC_02_reg), hdmi_in(CBUS_CBUS_MSC_04_reg), CBUS_CBUS_MSC_03_get_na_rx_len(hdmi_in(CBUS_CBUS_MSC_03_reg)));
		if (hdmi_in(CBUS_CBUS_MSC_02_reg) == _MHL_REG_LINK_MODE) {
			mhl_link_mode_updated = 1;
			HDMI_PRINTF("[CBUS] clk_mode=%d\n", CBUS_MSC_REG_31_get_clk_mode(hdmi_in(CBUS_MSC_REG_31_reg)));
		}

		if (CBUS_MSC_REG_20_get_req_wrt(hdmi_in(CBUS_MSC_REG_20_reg)) == TRUE) {
			hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_req_wrt_mask);
			HDMI_PRINTF("[CBUS_LOG] READ TX REQUEST WRT, SRC WILL SEND WRITE_BURST(6C)\n");
			if (MHLMscSendCommand(MHL_MSC_CMD_CODE_SET_INT, _MHL_REG_RCHANGE_INT, GRT_WRT) == _MHL_OK) {

			}
		}

#if MHL3_ENABLE
		if (CBUS_MSC_REG_20_get_feat_complete(hdmi_in(CBUS_MSC_REG_20_reg)) == TRUE) { /*FEAT_COMPLETE*/
			hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_feat_complete_mask);
			HDMI_PRINTF("[CBUS_LOG] FEAT_COMPLETE\n");
		}
		if (CBUS_MSC_REG_20_get_feat_req(hdmi_in(CBUS_MSC_REG_20_reg)) == TRUE) { /*FEAT_REQ*/
			hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_feat_req_mask);
			mhl3_send_hev_vic();
			mhl3_send_emsc_support();
			if (MHLMscSendCommand(MHL_MSC_CMD_CODE_SET_INT, _MHL_REG_RCHANGE_INT, FEAT_COMPLETE) == _MHL_OK) {
				HDMI_PRINTF("[CBUS_LOG] FEAT_REQ & FEAT_COMPLETE\n");
			}
		}

		if (CBUS_MSC_REG_20_get_dcap_chg(hdmi_in(CBUS_MSC_REG_20_reg))) {
			hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_dcap_chg_mask);
			if (mhl3_get_src_ver() >= 0x30) {
				for (i = 0x80; i < 0x81; i++) {
					if (!mhl3_read_xdevcap(i)) { /*CTS6.4.3.4, 6.4.16.2*/
						break;
					}
				}
				WRITE_XSTAT(0x90, 0x04); /*6.4.3.4, follow MNT*/
			}
			/*if (MHLMscSendCommand(MHL_MSC_CMD_CODE_SET_INT, _MHL_REG_RCHANGE_INT, FEAT_REQ) == _MHL_OK) {
				HDMI_PRINTF("[CBUS_LOG] FEAT_REQ OK\n");
			} else {
				HDMI_PRINTF("[CBUS_LOG] FEAT_REQ FAIL\n");
			}*/
		}
#endif

		if (CBUS_MSC_REG_20_get_dscr_chg(hdmi_in(CBUS_MSC_REG_20_reg))) {
			hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_dscr_chg_mask);
			HDMI_PRINTF("[CBUS_LOG] SCRATCHPAD CHG\n");
		}

		// Check 3D Request and Reply No Support For All Timings
		if (CBUS_MSC_REG_20_get_cbus_3d_req(hdmi_in(CBUS_MSC_REG_20_reg)) == TRUE) {
			// 3D_VIC Header
#if 0
			MHL_CTRL.bBuf[0] = _MHL_3D_VIC_HB;   //ADOPTER ID HIGH
			MHL_CTRL.bBuf[1] = _MHL_3D_VIC_LB;   //ADOPTER ID LOW

			// Total Entries -> 0
			MHL_CTRL.bBuf[3] = 0x00;

			// Checksum -> pData[0] ^ pData[1] ^ pData[3]
			MHL_CTRL.bBuf[2] = 0x10;

			// 3D_DTD Header
			MHL_CTRL.bBuf[4] = _MHL_3D_DTD_HB;
			MHL_CTRL.bBuf[5] = _MHL_3D_DTD_LB;

			// Total Entries -> 0
			MHL_CTRL.bBuf[7] = 0x00;

			// Checksum -> pData[0] ^ pData[1] ^ pData[3]
			MHL_CTRL.bBuf[6] = 0x11;

			if((MHLMscSendWriteBurst( _MHL_REG_SCRATCH_START, 4, MHL_CTRL.bBuf, _MHL_WRITE_BURST_WITH_REQ) == _MHL_OK) &&
			    (MHLMscSendWriteBurst(_MHL_REG_SCRATCH_START, 4, &MHL_CTRL.bBuf[4], _MHL_WRITE_BURST_WITH_REQ)) == _MHL_OK) {
				//ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _BIT4);
				hdmi_out(MSC_REG_20_reg, MSC_REG_20_cbus_3d_req_mask);
				HDMI_PRINTF("[CBUS_LOG] 3D REQ DONE\n");
            }
#else
			MHL_CTRL.bBuf[0] = _MHL_3D_VIC_HB;   //ADOPTER ID HIGH
			MHL_CTRL.bBuf[1] = _MHL_3D_VIC_LB;   //ADOPTER ID LOW
			MHL_CTRL.bBuf[2] = 0xef; //Checksum
			MHL_CTRL.bBuf[3] = 0x00; //tot_ent
			MHL_CTRL.bBuf[4] = 0x01; //seq
			MHL_CTRL.bBuf[5] = 0x00; //num_ent

			MHL_CTRL.bBuf[6] = _MHL_3D_DTD_HB;
			MHL_CTRL.bBuf[7] = _MHL_3D_DTD_LB;
			MHL_CTRL.bBuf[8] = 0xee; //Checksum
			MHL_CTRL.bBuf[9] = 0x00; //tot_ent
			MHL_CTRL.bBuf[10] = 0x01; //seq
			MHL_CTRL.bBuf[11] = 0x00; //num_ent

			if((MHLMscSendWriteBurst( _MHL_REG_SCRATCH_START, 6, MHL_CTRL.bBuf, _MHL_WRITE_BURST_WITH_REQ) == _MHL_OK) &&
				    (MHLMscSendWriteBurst(_MHL_REG_SCRATCH_START, 6, &MHL_CTRL.bBuf[6], _MHL_WRITE_BURST_WITH_REQ)) == _MHL_OK) {
				hdmi_out(CBUS_MSC_REG_20_reg, CBUS_MSC_REG_20_cbus_3d_req_mask);
				HDMI_PRINTF("[CBUS_LOG] 3D REQ DONE\n");
			}
#endif
		}

		got_cmd = 1;
	}

	/* msc_msg handler */
#if MHL3_ENABLE
	if (mhl3_get_src_ver() >= 0x30) {
		if (CBUS_CBUS_MSC_06_get_msg_sub_irq(hdmi_in(CBUS_CBUS_MSC_06_reg))) { /*6.3.11.22, 6.3.11.23*/
			hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_msg_sub_irq_mask);

			if (hdmi_in(CBUS_CBUS_MSC_0A_reg) != 2) // 2=Protocol Error
			MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_MSGE, _MSC_INEFFECTIVE_CODE);
		}
	}

	mhl3_xstat_handler();
	mhl3_bist_handler();
	mhl3_block_handler();
#endif

	mhl_write_burst_handler();

	return got_cmd;
}

//--------------------------------------------------
// Description  : RAP Process
// Input Value  : None
// Output Value : True or False (False if Content Off  need return serch mode)
//--------------------------------------------------
void  MHLMscRAPHandler(void)
{
	u_int8_t bRap_code;

	// Check RAP Command ,check rap_irq flag

	if (CBUS_CBUS_MSC_06_get_rap_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		/*HDMI_PRINTF("[CBUS_LOG] GET RAP IRQ!!!!! \n");*/
		bRap_code = CBUS_CBUS_MSC_12_rap_rcv(hdmi_in(CBUS_CBUS_MSC_12_reg)) ;
		if(((bRap_code) == _MSC_RAP_POLL) || ((bRap_code) == _MSC_RAP_CONTENT_ON) ||((bRap_code) == _MSC_RAP_CONTENT_OFF)) {
			MHLMscSendCommand( MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RAPK, _MSC_NO_ERROR);
			HDMI_PRINTF("[CBUS_LOG] GET RAP IRQ(0x%02x)\n", bRap_code);
		}
#if MHL3_ENABLE
		else if (bRap_code == _MSC_RAP_MODE_UP) {
			return;
		} else if (bRap_code == _MSC_RAP_MODE_DOWN) {
			hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rap_irq_mask);
			if (mhl_is_ver3x()) {
				if (_MHL_OK == MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RAPK, _MSC_NO_ERROR)) {
					HDMI_PRINTF("[MHL3] RAP MODE DOWN\n");
				} else {
					HDMI_PRINTF("[MHL3] RAP MODE DOWN, REPLY FAIL\n");
				}
//				mhl3_rap_mode_down(); //6.4.16.3 need time to disconnect
			}
			return;
		}
#endif
		else {
			MHLMscSendCommand( MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RAPK, _MSC_INEFFECTIVE_CODE);
			HDMI_PRINTF("[CBUS_LOG] GET UNKNOWN RAP IRQ(0x%02x)\n", bRap_code);
		}

		// Clear  RAP Flag
		// hdmiport_mask(CBUS_MSC_06_reg,~CBUS_MSC_06_rap_irq_mask,CBUS_MSC_06_rap_irq_mask);
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rap_irq_mask);
		if(CBUS_CBUS_MSC_12_rap_rcv(hdmi_in(CBUS_CBUS_MSC_12_reg)) == _MSC_RAP_CONTENT_OFF) {

			if(MHLMscSendCommand( MHL_MSC_CMD_CODE_WRT_STAT, _MHL_REG_LINK_MODE, 0x00) == _MHL_OK) {
				HDMI_PRINTF("[CBUS_LOG]  _MSC_RAP_CONTENT_OFF!!!!! CMD ok  \n");
			} else {
				HDMI_PRINTF("[CBUS_LOG]  _MSC_RAP_CONTENT_OFF!!!!! CMD fail  \n");
			}
			// FALSE make system reserch
		} else if(CBUS_CBUS_MSC_12_rap_rcv(hdmi_in(CBUS_CBUS_MSC_12_reg)) == _MSC_RAP_CONTENT_ON) {
			if(MHLMscSendCommand( MHL_MSC_CMD_CODE_WRT_STAT, _MHL_REG_LINK_MODE, LINK_MODE_PATH_EN) == _MHL_OK) {
				HDMI_PRINTF("[CBUS_LOG]  _MSC_RAP_CONTENT_ON!!!!! CMD ok  \n");
			} else {
				HDMI_PRINTF("[CBUS_LOG]  _MSC_RAP_CONTENT_ON!!!!! CMD fail  \n");
			}

		}


	}


}

u_int8_t MHLMscRAPGetCommand(u_int8_t *pucKeyCode)
{
	if (CBUS_CBUS_MSC_06_get_rap_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rap_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_12_get_rap_rcv(hdmi_in(CBUS_CBUS_MSC_12_reg));

		return TRUE;
	}
	return FALSE;
}

u_int8_t MHLMscRAPKGetCommand(u_int8_t *pucKeyCode)
{
	if (CBUS_CBUS_MSC_06_get_rapk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rapk_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_13_get_rapk_rcv(hdmi_in(CBUS_CBUS_MSC_13_reg));

		return TRUE;
	}
	return FALSE;
}

//--------------------------------------------------
// Description  : Get RCP Key Code
// Input Value  : None
// Output Value : _D0_INPUT_PORT/_D1_INPUT_PORT/_MSC_NONE
//--------------------------------------------------
u_int8_t MHLMscRCPGetCommand(u_int8_t *pucKeyCode)
{
	if (CBUS_CBUS_MSC_06_get_rcp_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rcp_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_0F_get_rcp_rcv(hdmi_in(CBUS_CBUS_MSC_0F_reg));

		return TRUE;
	}
	return FALSE;
}

u_int8_t MHLMscRCPKGetCommand(u_int8_t *pucKeyCode)
{
	if (CBUS_CBUS_MSC_06_get_rcpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rcpk_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_10_get_rcpk_rcv(hdmi_in(CBUS_CBUS_MSC_10_reg));

		return TRUE;
	}
	return FALSE;
}

u_int8_t MHLMscRCPEGetCommand(u_int8_t *pucKeyCode)
{
	if (CBUS_CBUS_MSC_06_get_rcpe_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rcpe_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_11_get_rcpe_rcv(hdmi_in(CBUS_CBUS_MSC_11_reg));

		return TRUE;
	}
	return FALSE;
}

//--------------------------------------------------
// Description  : Get UCP Key Code
// Input Value  : None
// Output Value : _D0_INPUT_PORT/_D1_INPUT_PORT/_MSC_NONE
//--------------------------------------------------
u_int8_t MHLMscUCPGetCommand(u_int8_t *pucKeyCode)
{
	if ((CBUS_CBUS_MSC_06_get_ucp_irq(hdmi_in(CBUS_CBUS_MSC_06_reg))== TRUE)) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_ucp_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_0C_get_msg_cmd(hdmi_in(CBUS_CBUS_MSC_20_reg));

		return TRUE;
	}
	return FALSE;
}

u_int8_t MHLMscUCPKGetCommand(u_int8_t *pucKeyCode)
{
	if ((CBUS_CBUS_MSC_06_get_ucpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg))== TRUE)) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_ucpk_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_21_get_ucpk_rcv(hdmi_in(CBUS_CBUS_MSC_21_reg));

		return TRUE;
	}
	return FALSE;
}

u_int8_t MHLMscUCPEGetCommand(u_int8_t *pucKeyCode)
{
	if ((CBUS_CBUS_MSC_06_get_ucpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg))== TRUE)) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_ucpe_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_22_get_ucpe_rcv(hdmi_in(CBUS_CBUS_MSC_22_reg));

		return TRUE;
	}
	return FALSE;
}
HDMI_bool Cbus_SEND_UCP_SUB_Command(unsigned char bKeyCode)
{

	u_int8_t bCode;
	u_int16_t bTimeout = 0;
	HDMI_bool bStatus =_MHL_SUCCESS ;
	bCode = bKeyCode &0x7f;
	hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_ucpk_irq_mask);
	if(MHLMscSendCommand( MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_UCP, bKeyCode) == _MHL_OK) {
		HDMI_PRINTF("[CBUS_LOG]  UCP CMD %x  \n",bKeyCode );

		while (1) {
			if (CBUS_CBUS_MSC_06_get_ucpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {

				// Clear Flag
				//hdmiport_mask(CBUS_MSC_06_reg,~CBUS_MSC_06_rcpk_irq_mask,CBUS_MSC_06_rcpk_irq_mask);
				hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_ucpk_irq_mask);
				bCode = CBUS_CBUS_MSC_20_get_ucp_rcv(hdmi_in(CBUS_CBUS_MSC_20_reg));
				HDMI_PRINTF("[CBUS_LOG]  UCPK  Key code %x  , time = %d !!!!!  \n",bCode ,bTimeout );
									return bStatus;

				break;
			} else {
				msleep(10);
				bTimeout++;
				if(bTimeout >=20) {

					HDMI_PRINTF("[CBUS_LOG]  UCPK wait   Key code TIME OUT !!! !!!!!  \n" );
					bStatus = _MHL_FAIL;
					return bStatus;
				}

			}
		}
	/*
	bTimeout=0;
		msleep(50);
		bTemp = bKeyCode|0x80;
		if(MHLMscSendCommand( MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_UCP, bTemp) == _MHL_OK) {
			while (1) {
				if (CBUS_CBUS_MSC_06_get_ucpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {

					// Clear Flag
					//hdmiport_mask(CBUS_MSC_06_reg,~CBUS_MSC_06_rcpk_irq_mask,CBUS_MSC_06_rcpk_irq_mask);
					hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_ucpk_irq_mask);
					bCode = CBUS_CBUS_MSC_20_get_ucp_rcv(hdmi_in(CBUS_CBUS_MSC_20_reg));
					HDMI_PRINTF("[CBUS_LOG]  UCPK  Key code %x  , time = %d !!!!!  \n",bCode ,bTimeout );
					break;
				} else {
					msleep(10);
					bTimeout++;
					if(bTimeout >=10) {

						HDMI_PRINTF("[CBUS_LOG]  UCPK wait   Key code TIME OUT !!! !!!!!  \n" );
						bStatus = _MHL_FAIL;
						return bStatus;
					}

				}
			}
			return bStatus;
		} else {
			HDMI_PRINTF("[CBUS_LOG]  UCP CMD send fail!!!!!  \n" );
			bStatus = _MHL_FAIL;
			return bStatus;
		}
*/
	}
	else{
		HDMI_PRINTF("[CBUS_LOG]  UCP CMD send fail!!!!!  \n" );
		bStatus = _MHL_FAIL;
		return bStatus;
	}

}


u_int8_t MHLMscMSGEGetCommand(u_int8_t *pucKeyCode)
{
	if ((CBUS_CBUS_MSC_06_get_msge_irq(hdmi_in(CBUS_CBUS_MSC_06_reg))== TRUE)) {
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_msge_irq_mask);
		pucKeyCode[0] = CBUS_CBUS_MSC_0E_get_msge_rcv(hdmi_in(CBUS_CBUS_MSC_0E_reg));

		return TRUE;
	}
	return FALSE;
}

u_int8_t MHLMscRBPGetCommand(u_int8_t *pucKeyCode)
{
	if (CBUS_oCBUS_CTRL_12_get_rbp_irq(hdmi_in(CBUS_oCBUS_CTRL_12_reg))) {
		hdmi_out(CBUS_oCBUS_CTRL_12_reg, CBUS_oCBUS_CTRL_12_rbp_irq_mask);
		pucKeyCode[0] = CBUS_oCBUS_CTRL_16_get_rbp_rcv(hdmi_in(CBUS_oCBUS_CTRL_16_reg));

		return TRUE;
	}
	return FALSE;
}

unsigned char mhl_check_rbp_valid(const unsigned char rbp_code)
{
	if (rbp_code) {
		return TRUE;
	}
	return FALSE;
}

void  MHLMscRBPHandler(void)
{
	unsigned char rbp_code;
	if (MHLMscRBPGetCommand(&rbp_code)) {
		HDMI_PRINTF("[MHL] GOT RBP=%x\n", rbp_code);
		if (mhl_check_rbp_valid(rbp_code)) {
			MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RBPK, rbp_code);
		} else {
			MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RBPE, _MSC_INEFFECTIVE_CODE);
			MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RBPK, rbp_code);
		}
	}
}

//--------------------------------------------------
// Description  : MHLMSCRE_SEND_DCAD_RDY
// Input Value  : none
// Output Value : none
//              :none
//--------------------------------------------------
void MHLMSCRE_SEND_DCAD_RDY(void)
{

	if((GET_MHL_READY_TO_TRANSMIT() == TRUE) && (GET_MHL_READY_TO_RESEND() == TRUE)) {
		MHLMscSendCommand( MHL_MSC_CMD_CODE_WRT_STAT, _MHL_REG_CONNECTED_RDY, CONNECT_DCAP_RDY);

		SET_MHL_READY_TO_RESEND( 0);
		SET_MHL_TIMER3_SEC(100);  //10 msec * 100 = 1 sec

		HDMI_PRINTF("[CBUS_LOG]  MHL MHLMSCRE_SEND_DCAD_RDY \n");

	}
}
//--------------------------------------------------
// Description  : void  WRITE_RCP_FIFO(u_int8_t* data)
// Input Value  : none
// Output Value : RCP command
//
//--------------------------------------------------
void  WRITE_RCP_FIFO(u_int8_t *data)
{

	RCP_Buffer[(in_point%buffer_length)]= *data;
	HDMI_PRINTF("[CBUS_LOG]  WRITE_RCP_FIFO = %x  in data =%x  , in_point =%x  \n",RCP_Buffer[(in_point%buffer_length)] , *data ,in_point);
	in_point ++;

}

//--------------------------------------------------
// Description  : u_int8_t  READ_RCP_FIFO(void)
// Input Value  : none
// Output Value : RCP command
//
//--------------------------------------------------
u_int8_t  READ_RCP_FIFO(void)
{
	u_int8_t returndata;
	if (((in_point%buffer_length) !=(out_point%buffer_length))) {
		returndata = RCP_Buffer[(out_point%buffer_length)] ;
		out_point ++;

	} else {
		returndata = RCP_NULL;
	}
	HDMI_PRINTF("[CBUS_LOG]  READ_RCP_FIFO = %x  in data =%x  , in_point =%x  \n",returndata, out_point ,in_point);
	return  returndata ;
}

// Description  : UserMHLMscCHECK_MODE
// Input Value  : none
// Output Value : none
//              :none
//--------------------------------------------------

void UserMHLMscCHECK_MODE(void)
{
	u_int8_t ucActivePort = 0;


	//re send ready command for test
	//MHLMSCRE_SEND_DCAD_RDY();
	// Check Source If SET_INT
	//cloud test 0403
	MHLMscCheckDeviceINT();

	// RAP Handler
	MHLMscRAPHandler();

	/*
	if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
	{
	    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
	}
	*/



	// RCP Handler
	ucActivePort = MHLMscRCPGetCommand(MHL_CTRL.bBuf);

	if(ucActivePort == TRUE) {
		WRITE_RCP_FIFO(&MHL_CTRL.bBuf[0]);
		// Check RCP Key Code
		MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RCPK, MHL_CTRL.bBuf[0]);


	}

	// UCP Handler
	ucActivePort = MHLMscUCPGetCommand(MHL_CTRL.bBuf);

	if(ucActivePort == TRUE) {
		MHL_CTRL.bBuf[1] = 0;
		//DebugMessageOsd(pData, pData[0]);
		HDMI_PRINTF("[CBUS_LOG]  UCP Handler  Get UCP data = %x  \n" , MHL_CTRL.bBuf[0]);
		MHLMscSendCommand(MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_UCPK, MHL_CTRL.bBuf[0]);
	}

	MHLMscRBPHandler();

}

//--------------------------------------------------
// Description  : CBUS_CTS_CMD_TEST(Power Normal)
// Input Value  : none
// Output Value : none
//              : False : No Signal
//--------------------------------------------------
void  CBUS_CTS_CMD_TEST(void)
{

	if(MHLMscSendCommand(MHL_MSC_CMD_CODE_GET_STATE, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL) == _MHL_OK) {
		HDMI_PRINTF("[CBUS_LOG]  MHL GET_STATE CMD \n");
	} else {
		HDMI_PRINTF("[CBUS_LOG]  MHL GET_STATE CMD fail !!!\n");
	}
	msleep(150);
	if(MHLMscSendCommand(MHL_MSC_CMD_CODE_GET_VENDOR_ID, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL) == _MHL_OK) {
		HDMI_PRINTF("[CBUS_LOG]  MHL GET_VENDOR_ID \n");
	} else {
		HDMI_PRINTF("[CBUS_LOG]  MHL GET_VENDOR_ID fail !!!\n");
	}
	msleep(150);
	if(MHLMscSendCommand(MHL_MSC_CMD_CODE_GET_MSC_ERR, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL) == _MHL_OK) {
		HDMI_PRINTF("[CBUS_LOG]  MHL GET_MSC_ERR CMD \n");
	} else {
		HDMI_PRINTF("[CBUS_LOG]  MHL GET_MSC_ERR CMD fail !!!\n");
	}
	msleep(150);

}


//--------------------------------------------------
//
//
//
//--------------------------------------------------
HDMI_bool Cbus_SEND_RCP_SUB_Command(unsigned char bKeyCode)
{
	u_int8_t bCode,bTemp;
	u_int16_t bTimeout = 0;
	HDMI_bool bStatus =_MHL_SUCCESS ;

	bCode = bKeyCode &0x7f;
	// 	if ((bCode == 0x00)||(bCode == 0x01)||(bCode == 0x02)||(bCode == 0x03)||(bCode == 0x04)||(bCode == 0x0d)||(bCode == 0x2B))
	//  {
	if(MHLMscSendCommand( MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RCP, bKeyCode) == _MHL_OK) {
		HDMI_PRINTF("[CBUS_LOG]  RCP CMD %x  \n",bKeyCode );

		while (1) {
			if (CBUS_CBUS_MSC_06_get_rcpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {

				// Clear Flag
				//hdmiport_mask(CBUS_MSC_06_reg,~CBUS_MSC_06_rcpk_irq_mask,CBUS_MSC_06_rcpk_irq_mask);
				hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rcpk_irq_mask);
				bCode = CBUS_CBUS_MSC_0F_get_rcp_rcv(hdmi_in(CBUS_CBUS_MSC_10_reg));
				HDMI_PRINTF("[CBUS_LOG]  RCPK  Key code %x  , time = %d !!!!!  \n",bCode ,bTimeout );
				break;
			} else {
				msleep(10);
				bTimeout++;
				if(bTimeout >=10) {

					HDMI_PRINTF("[CBUS_LOG]  RCPK wait   Key code TIME OUT !!! !!!!!  \n" );
					bStatus = _MHL_FAIL;
					return bStatus;
				}

			}
		}

		msleep(50);
		bTemp = bKeyCode|0x80;
		if(MHLMscSendCommand( MHL_MSC_CMD_CODE_MSC_MSG, MHL_MSG_RCP, bTemp) == _MHL_OK) {
			while (1) {
				if (CBUS_CBUS_MSC_06_get_rcpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {

					// Clear Flag
					//hdmiport_mask(CBUS_MSC_06_reg,~CBUS_MSC_06_rcpk_irq_mask,CBUS_MSC_06_rcpk_irq_mask);
					hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rcpk_irq_mask);
					bCode = CBUS_CBUS_MSC_0F_get_rcp_rcv(hdmi_in(CBUS_CBUS_MSC_10_reg));
					HDMI_PRINTF("[CBUS_LOG]  RCPK  Key code %x  , time = %d !!!!!  \n",bCode ,bTimeout );
					break;
				} else {
					msleep(10);
					bTimeout++;
					if(bTimeout >=10) {

						HDMI_PRINTF("[CBUS_LOG]  RCPK wait   Key code TIME OUT !!! !!!!!  \n" );
						bStatus = _MHL_FAIL;
						return bStatus;
					}

				}
			}
			return bStatus;
		} else {
			HDMI_PRINTF("[CBUS_LOG]  RCP CMD send fail!!!!!  \n" );
			bStatus = _MHL_FAIL;
			return bStatus;
		}

	} else {
		HDMI_PRINTF("[CBUS_LOG]  RCP CMD send fail!!!!!  \n" );
		bStatus = _MHL_FAIL;
		return bStatus;
	}
	// }
	// else
	// {
	//    HDMI_PRINTF("[CBUS_LOG]  RCP CMD send OUT of RANGE  !!!!!  \n" );
	// }
}

void Cbus_GET_RCPK_SUB_Command(void)
{
	u_int8_t bCode;
	if (CBUS_CBUS_MSC_06_get_rcpk_irq(hdmi_in(CBUS_CBUS_MSC_06_reg)) == TRUE) {

		// Clear Flag
		//hdmiport_mask(CBUS_MSC_06_reg,~CBUS_MSC_06_rcpk_irq_mask,CBUS_MSC_06_rcpk_irq_mask);
		hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_rcpk_irq_mask);
		bCode = CBUS_CBUS_MSC_0F_get_rcp_rcv(hdmi_in(CBUS_CBUS_MSC_10_reg));
		HDMI_PRINTF("[CBUS_LOG]  RCPK  Key code %x !!!!!  \n",bCode );
	}
}
//--------------------------------------------------
// Description  : Signal PreDetection for TMDS(Power Normal)
// Input Value  : Input Port(D0 or D1, HDMI or DVI)
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
u_int8_t MHLNormalPreDetect(void)
{
	if (CBUS_CBUS_MSC_12_get_rap_rcv(hdmi_in(CBUS_CBUS_MSC_12_reg)) == _MSC_RAP_CONTENT_OFF) {
		HDMI_PRINTF("[CBUS_LOG]  MHLNormalPreDetect  _MSC_RAP_CONTENT_OFF \n" );
		return FALSE;
	}


#if 0//MHL3_ENABLE
	if (mhl_is_ver3x() && (mhl3_get_state() == MHL3_RE_DISCOVERY)) {
		SET_MHL_PROCESS_STATE(_MHL_STATE_INITIAL);
		/*return FALSE;*/
	}
#endif

	switch (GET_MHL_PROCESS_STATE()) {
		case _MHL_STATE_INITIAL:  /*wait interrupt to change state to  _MHL_STATE_DISCOVERY_DONE*/
			if (GET_MHL_RECONNECT_OK()) {
				HDMI_PRINTF("[CBUS_LOG] Cable in wait signal _MHL_STATE_INITIAL  \n");
				SET_MHL_RECONNECT_OK(0);
				SET_MHL_TIMER2_SEC(500);
				CBUSSwitch(TRUE);
			}
#if 0//MHL3_ENABLE
			hdmi_clear_b_struct();
#endif
			MHL_wClock_value = 0;
			mhl_link_mode_updated = 0;
			_bMhl_clk_mode = 0;
			return FALSE;
			break;
		case _MHL_STATE_DISCOVERY_DONE:
			SET_MHL_TIMER2_SEC(0);
			//hdmi_ioctl_struct.b_mhl_debounce = 0;

#if MHL3_ENABLE
			if (mhl3_get_src_ver()>=0x30) {
				if (mhl3_get_state() == MHL3_READY) {
					SET_MHL_PROCESS_STATE(_MHL_STATE_DEV_CAP_RDY);
					return TRUE;
				} else if (mhl3_get_state() == MHL3_SKIP) {
					/* go mhl2.0*/
 				} else {
					return FALSE;
				}
			}
#else
			msleep(300);   /* FOR cts 4.3.23.2*/
#endif

			if (MHLMscSendCommand(MHL_MSC_CMD_CODE_SET_HPD, MHL_MSC_CMD_CODE_NULL, MHL_MSC_CMD_CODE_NULL) == _MHL_OK) {
				SET_MHL_PROCESS_STATE( _MHL_STATE_HPD_DONE);
			} else {
				HDMI_PRINTF("[CBUS_LOG]  _MHL_SET_HPD FAIL!!!!!  \n" );
				/*SET_MHL_PROCESS_STATE(_MHL_STATE_DISCOVERY_DONE);*/
				return FALSE;
			}
			break;
		case _MHL_STATE_HPD_DONE:
			HDMI_PRINTF("[CBUS_LOG] _MHL_STATE_HPD_DONE  \n" );
			if(MHLMscSendCommand(MHL_MSC_CMD_CODE_WRT_STAT, _MHL_REG_LINK_MODE, LINK_MODE_PATH_EN) == _MHL_OK) {
				HDMI_PRINTF("[CBUS_LOG]   _MHL_STATE_PATH_EN_DONE \n");
				SET_MHL_PROCESS_STATE(_MHL_STATE_PATH_EN_DONE);

			} else {
				return FALSE;
			}
			break;
		case _MHL_STATE_PATH_EN_DONE:
			if (MHLMscSendCommand(MHL_MSC_CMD_CODE_WRT_STAT, _MHL_REG_CONNECTED_RDY, CONNECT_DCAP_RDY) == _MHL_OK) {
				MHL_Z100k_Switch(MHL_CHANNEL, 0);
				HDMI_PRINTF("[CBUS_LOG]  MHL Dev Cap RDY\n");
				SET_MHL_PROCESS_STATE(_MHL_STATE_DEV_CAP_RDY);
				SET_MHL_READY_TO_RESEND( 1);
			} else {
				return FALSE;
			}

			break;
		case _MHL_STATE_DEV_CAP_RDY:


			//FIX CTS bug 4.3.20.1
			if((GET_MHL_READY_TO_TRANSMIT() == TRUE) && (GET_MHL_READY_TO_RESEND() == TRUE)) {
				MHLMscCheckDeviceINT();
				SET_MHL_READY_TO_RESEND( 0);
				SET_MHL_TIMER3_SEC(10);
					//wClock_value = mhl_get_b_value();
					//MHL_wClock_value =  wClock_value;
					//HDMI_PRINTF("[CBUS_LOG]  MHL CBUS Done MHL clock =%d  \n", wClock_value);

					//if (wClock_value == 0)   _bMhl_No_clock_cnt ++;
					//else                           _bMhl_No_clock_cnt = 0;

#if 0
				if (_bMhl_No_clock_cnt  > 20) {
					SET_MHL_PROCESS_STATE(_MHL_STATE_INITIAL);
					_bMhl_No_clock_cnt =0 ;
					CBUSSwitch(0);
#if Mag2_FIX
					if((GET_HDMI_CHANNEL() ==0)) {
						hdmiport_mask(HDMIPHY_REG_BANDGAP_Z0_CTRL_reg,~(HDMIPHY_REG_BANDGAP_Z0_CTRL_z0pow_0_mask),(0));
					} else if((GET_HDMI_CHANNEL() ==1)) {
						hdmiport_mask(HDMIPHY_REG_BANDGAP_Z0_CTRL_reg,~(HDMIPHY_REG_BANDGAP_Z0_CTRL_z0pow_1_mask),(0));
					} else if((GET_HDMI_CHANNEL() ==2)) {
						hdmiport_mask(HDMIPHY_REG_BANDGAP_Z0_CTRL_reg,~(HDMIPHY_REG_BANDGAP_Z0_CTRL_z0pow_2_mask),(0));
					}
#endif

					//hdmiport_mask(HDMIPHY_REG_BANDGAP_Z0_CTRL_reg,~(HDMIPHY_REG_BANDGAP_Z0_CTRL_z0pow_2_mask),(0));
					HDMI_PRINTF("[CBUS_LOG]  MHL CBUS RESET !!!!!!!!!!!!!!!!!! \n");
				}
#endif
				return TRUE;
			}

			return FALSE;

			break;

		default:

			break;
	}

	return FALSE;
}

void MHL_CheckPPMode(void)
{
	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_31_BYPASS_CBUS) {
		_bMhl_clk_mode = (hdmi_in(DEBUG_REG_ADDR)&DEBUG_30_FORCE_MHL_PP)>>30;
		return;
	}

	if (CBUS_MSC_REG_05_get_supp_ppixel(hdmi_in(CBUS_MSC_REG_05_reg)) &&
	    (CBUS_MSC_REG_31_get_clk_mode(hdmi_in(CBUS_MSC_REG_31_reg)) == MHL_CLK_TYPE_packedpixel_mode) &&
	    mhl_link_mode_updated) {
		_bMhl_clk_mode = 1;
	} else {
		_bMhl_clk_mode = 0;
	}
	/*HDMI_PRINTF("clk_mode=%d(flag=%d)\n", CBUS_MSC_REG_31_get_clk_mode(hdmi_in(CBUS_MSC_REG_31_reg)), CBUS_MSC_06_get_clk_mode_chg(hdmi_in(CBUS_MSC_06_reg)));*/
	hdmi_out(CBUS_CBUS_MSC_06_reg, CBUS_CBUS_MSC_06_clk_mode_chg_mask);
}



void lib_mhl_mac_init(unsigned char nport)
{
	hdmiport_mask(D614[nport], ~(MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en_mask|MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_mask), 0);
#if MHL3_ENABLE
	hdmiport_mask(D700[nport], ~MHL_P0_PORT0_MHL3_CTRL_errc_sel_mask, MHL_P0_PORT0_MHL3_CTRL_errc_sel(4));
#endif
}

unsigned char lib_mhl_port_is_ppmode(unsigned char nport)
{
	if (nport != MHL_CHANNEL)
		return 0;

	return MHL_P0_PORT0_MHL_DEMUX_CTRL_get_mhl_pp_en(hdmi_in(D614[nport]));
}

unsigned char lib_mhl_port_is_turn_on(unsigned char nport)
{
	if (nport != MHL_CHANNEL)
		return 0;

	return CBUS_PMM_CBUS_PHY_4_get_en_driver_rx(hdmi_in(CBUS_PMM_CBUS_PHY_4_reg));
}

#if MHL3_ENABLE
unsigned char lib_mhl_port_is_mhl3(unsigned char nport)
{
	if (nport != MHL_CHANNEL)
		return 0;

	return CBUS_PMM_CBUS_PHY_6_get_pll_pow_ecbusrx(hdmi_in(CBUS_PMM_CBUS_PHY_6_reg));
}
#endif


#if MHL3_ENABLE
void lib_mhl3_set_24_16bit(unsigned char nport, unsigned char bpp_16)
{
	HDMI_PRINTF("[MHL] MHL3 - 16bit=%d\n", bpp_16);
	hdmiport_mask(D700[nport], ~MHL_P0_PORT0_MHL3_CTRL_mhl_ver3_24_16_bit_sel_mask, MHL_P0_PORT0_MHL3_CTRL_mhl_ver3_24_16_bit_sel(bpp_16));
}

void mhl3_isr(void)
{
	if ((GET_MHL_PROCESS_STATE()>_MHL_STATE_WAKE_UP_DONE) && (mhl3_get_src_ver()>=0x30)) {
		if (!mhl3_ecbus_discovery()) {
			SET_MHL_PROCESS_STATE(_MHL_STATE_INITIAL);
		}
    }
}
#endif



unsigned char mhl_is_ver3x(void)
{
#if MHL3_ENABLE
	return (mhl3_get_version() >= 0x30);
#else
	return 0;
#endif
}


#endif  //end of MHL_SUPPORT





void MHL_Z100k_Switch(unsigned char nport, unsigned char benable)
{
	if (nport == 0) {
		hdmiport_mask(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg,
			~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en(1<<nport)),
			benable?DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en(1<<nport):0);
	} else if (nport == 1) {
		hdmiport_mask(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg,
			~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en(1<<nport)),
			benable?DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en(1<<nport):0);
	} else if (nport == 2) {
		hdmiport_mask(DFE_HDMI_RX_PHY_P2_Z0POW_reg,
			~(DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z100_en_mask),
			benable?DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z100_en(1):0);
	}
}

void mhl_clk_switch(unsigned char nport, unsigned char is_mhl)
{
	unsigned int mhl_pow_addr[3] = {
		DFE_HDMI_RX_PHY_P0P1_MHL_reg,
		DFE_HDMI_RX_PHY_P1_MHL_reg,
		DFE_HDMI_RX_PHY_P2_MHL_reg
	};
	unsigned int mhl_pow_bit[3] = {	DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_pow_mask,
	                                DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_pow_mask,
	                                DFE_HDMI_RX_PHY_P2_MHL_reg_p2_mhl_pow_mask
	                              };
	unsigned int datasel_bit[3] = {	DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_datasel_mask,
	                                DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_datasel_mask,
	                                DFE_HDMI_RX_PHY_P2_MHL_reg_p2_mhl_hdmi_datasel_mask
	                              };
	unsigned int cksel_bit[3] = {	DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_cksel_mask,
	                                DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_cksel_mask,
	                                DFE_HDMI_RX_PHY_P2_MHL_reg_p2_mhl_hdmi_cksel_mask
	                            };

	hdmiport_mask(mhl_pow_addr[nport],
		~(cksel_bit[nport]|datasel_bit[nport]|mhl_pow_bit[nport]),
		(is_mhl)?mhl_pow_bit[nport]:(cksel_bit[nport]|datasel_bit[nport]));

#if MHL3_ENABLE
	lib_hdmi_ck_md_ref_sel(nport, mhl_is_ver3x());
#endif
	lib_hdmi_mhl_z300_sel(nport, is_mhl, mhl_is_ver3x()); /* remove it? */

}

