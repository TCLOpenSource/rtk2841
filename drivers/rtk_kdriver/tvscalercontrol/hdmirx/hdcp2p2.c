/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdcp_2p2.c
 *
 * author: 	Scarlet Witch, Wanda Maximoff
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"
#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_session.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_interface.h>



/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/
#define HDCP2_SEND_PAIRINGINFO_BY_IRQ_RD	0
#define DEFAULT_KEY_TEST 0
#define HDCP_2P2_PRINTF(fmt, args...) 		HDMI_EMG(fmt, ## args)


/*
#define _ZERO                       0x00
#define _BIT0                       0x01
#define _BIT1                       0x02
#define _BIT2                       0x04
#define _BIT3                       0x08
#define _BIT4                       0x10
#define _BIT5                       0x20
#define _BIT6                       0x40
#define _BIT7                       0x80
#define _BIT8                       0x0100
#define _BIT9                       0x0200
#define _BIT10                      0x0400
#define _BIT11                      0x0800
#define _BIT12                      0x1000
#define _BIT13                      0x2000
#define _BIT14                      0x4000
#define _BIT15                      0x8000
#define _BIT16                      0x10000
#define _BIT17                      0x20000
#define _BIT18                      0x40000
#define _BIT19                      0x80000
#define _BIT20                      0x100000
#define _BIT21                      0x200000
#define _BIT22                      0x400000
#define _BIT23                      0x800000
#define _BIT24                      0x1000000
#define _BIT25                      0x2000000
#define _BIT26                      0x4000000
#define _BIT27                      0x8000000
#define _BIT28                      0x10000000
#define _BIT29                      0x20000000
#define _BIT30                      0x40000000
#define _BIT31                      0x80000000
*/
//For HDCP2_2  TEST 20140815 cloud wu
#define HDCP_RXstatus_addr    0x70
#define IDEL  					0   //TX=>RX
#define AKE_INIT 					2   //TX=>RX
#define AKE_Send_Cert 			3   //RX=>TX
#define AKE_NO_Stored_Km  		4   //TX=>RX
#define AKE_Stored_Km  			5   //TX=>RX
#define AKE_Send_H_prime  		7   //RX=>TX
#define AKE_Send_Pariring_Info  	8   //RX=>TX
#define LC_Init               			9   //TX=>RX
#define LC_Send_L_prime              10  //RX=>TX
#define SKE_Send_Eks              	11  //TX=>RX



//RX send FSM
#define  RX_FSM_SEND_START                     1
#define  RX_FSM_WAIT                  		2
#define  RX_FSM_FINISH                             3


//=============================HDCP 2.2 OFFSET =========================================//
#define Write_Message_offset           0x60
#define Rxstatus_offset                     0x70
#define Read_Message_offset            0x80





/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/





#if DEFAULT_KEY_TEST
const unsigned char Hdcp2_2_Certrx[522] ={

0x8b , 0xa4 , 0x47 , 0x42 , 0xfb , 0xe4 , 0x68 , 0x63 , 0x8a , 0xda , 0x97 , 0x2d , 0xde , 0x9a , 0x8d ,
0x1c , 0xb1 , 0x65 , 0x4b , 0x85 , 0x8d , 0xe5 , 0x46 , 0xd6 , 0xdb , 0x95 , 0xa5 , 0xf6 , 0x66 , 0x74 ,
0xea , 0x81 , 0x0b , 0x9a , 0x58 , 0x58 , 0x66 , 0x26 , 0x86 , 0xa6 , 0xb4 , 0x56 , 0x2b , 0x29 , 0x43 ,
0xe5 , 0xbb , 0x81 , 0x74 , 0x86 , 0xa7 , 0xb7 , 0x16 , 0x2f , 0x07 , 0xec , 0xd1 , 0xb5 , 0xf9 , 0xae ,
0x4f , 0x98 , 0x89 , 0xa9 , 0x91 , 0x7d , 0x58 , 0x5b , 0x8d , 0x20 , 0xd5 , 0xc5 , 0x08 , 0x40 , 0x3b ,
0x86 , 0xaf , 0xf4 , 0xd6 , 0xb9 , 0x20 , 0x95 , 0xe8 , 0x90 , 0x3b , 0x8f , 0x9f , 0x36 , 0x5b , 0x46 ,
0xb6 , 0xd4 , 0x1e , 0xf5 , 0x05 , 0x88 , 0x80 , 0x14 , 0xe7 , 0x2c , 0x77 , 0x5d , 0x6e , 0x54 , 0xe9 ,
0x65 , 0x81 , 0x5a , 0x68 , 0x92 , 0xa5 , 0xd6 , 0x40 , 0x78 , 0x11 , 0x97 , 0x65 , 0xd7 , 0x64 , 0x36 ,
0x5e , 0x8d , 0x2a , 0x87 , 0xa8 , 0xeb , 0x7d , 0x06 , 0x2c , 0x10 , 0xf8 , 0x0a , 0x7d , 0x01 , 0x00 ,
0x01 , 0x10 , 0x00 , 0x06 , 0x40 , 0x99 , 0x8f , 0x5a , 0x54 , 0x71 , 0x23 , 0xa7 , 0x6a , 0x64 , 0x3f ,
0xbd , 0xdd , 0x52 , 0xb2 , 0x79 , 0x6f , 0x88 , 0x26 , 0x94 , 0x9e , 0xaf , 0xa4 , 0xde , 0x7d , 0x8d ,
0x88 , 0x10 , 0xc8 , 0xf6 , 0x56 , 0xf0 , 0x8f , 0x46 , 0x28 , 0x48 , 0x55 , 0x51 , 0xc5 , 0xaf , 0xa1 ,
0xa9 , 0x9d , 0xac , 0x9f , 0xb1 , 0x26 , 0x4b , 0xeb , 0x39 , 0xad , 0x88 , 0x46 , 0xaf , 0xbc , 0x61 ,
0xa8 , 0x7b , 0xf9 , 0x7b , 0x3e , 0xe4 , 0x95 , 0xd9 , 0xa8 , 0x79 , 0x48 , 0x51 , 0x00 , 0xbe , 0xa4 ,
0xb6 , 0x96 , 0x7f , 0x3d , 0xfd , 0x76 , 0xa6 , 0xb7 , 0xbb , 0xb9 , 0x77 , 0xdc , 0x54 , 0xfb , 0x52 ,
0x9c , 0x79 , 0x8f , 0xed , 0xd4 , 0xb1 , 0xbc , 0x0f , 0x7e , 0xb1 , 0x7e , 0x70 , 0x6d , 0xfc , 0xb9 ,
0x7e , 0x66 , 0x9a , 0x86 , 0x23 , 0x3a , 0x98 , 0x5e , 0x32 , 0x8d , 0x75 , 0x18 , 0x54 , 0x64 , 0x36 ,
0xdd , 0x92 , 0x01 , 0x39 , 0x90 , 0xb9 , 0xe3 , 0xaf , 0x6f , 0x98 , 0xa5 , 0xc0 , 0x80 , 0xc6 , 0x2f ,
0xa1 , 0x02 , 0xad , 0x8d , 0xf4 , 0xd6 , 0x66 , 0x7b , 0x45 , 0xe5 , 0x74 , 0x18 , 0xb1 , 0x27 , 0x24 ,
0x01 , 0x1e , 0xea , 0xd8 , 0xf3 , 0x79 , 0x92 , 0xe9 , 0x03 , 0xf5 , 0x57 , 0x8d , 0x65 , 0x2a , 0x8d ,
0x1b , 0xf0 , 0xda , 0x58 , 0x3f , 0x58 , 0xa0 , 0xf4 , 0xb4 , 0xbe , 0xcb , 0x21 , 0x66 , 0xe9 , 0x21 ,
0x7c , 0x76 , 0xf3 , 0xc1 , 0x7e , 0x2e , 0x7c , 0x3d , 0x61 , 0x20 , 0x1d , 0xc5 , 0xc0 , 0x71 , 0x28 ,
0x2e , 0xb7 , 0x0f , 0x1f , 0x7a , 0xc1 , 0xd3 , 0x6a , 0x1e , 0xa3 , 0x54 , 0x34 , 0x8e , 0x0d , 0xd7 ,
0x96 , 0x93 , 0x78 , 0x50 , 0xc1 , 0xee , 0x27 , 0x72 , 0x3a , 0xbd , 0x57 , 0x22 , 0xf0 , 0xd7 , 0x6d ,
0x9d , 0x65 , 0xc4 , 0x07 , 0x9c , 0x82 , 0xa6 , 0xd4 , 0xf7 , 0x6b , 0x9a , 0xe9 , 0xc0 , 0x6c , 0x4a ,
0x4f , 0x6f , 0xbe , 0x8e , 0x01 , 0x37 , 0x50 , 0x3a , 0x66 , 0xd9 , 0xe9 , 0xd9 , 0xf9 , 0x06 , 0x9e ,
0x00 , 0xa9 , 0x84 , 0xa0 , 0x18 , 0xb3 , 0x44 , 0x21 , 0x24 , 0xa3 , 0x6c , 0xcd , 0xb7 , 0x0f , 0x31 ,
0x2a , 0xe8 , 0x15 , 0xb6 , 0x93 , 0x6f , 0xb9 , 0x86 , 0xe5 , 0x28 , 0x01 , 0x1a , 0x5e , 0x10 , 0x3f ,
0x1f , 0x4d , 0x35 , 0xa2 , 0x8d , 0xb8 , 0x54 , 0x26 , 0x68 , 0x3a , 0xcd , 0xcb , 0x5f , 0xfa , 0x37 ,
0x4a , 0x60 , 0x10 , 0xb1 , 0x0a , 0xfe , 0xba , 0x9b , 0x96 , 0x5d , 0x7e , 0x99 , 0xcf , 0x01 , 0x98 ,
0x65 , 0x87 , 0xad , 0x40 , 0xd5 , 0x82 , 0x1d , 0x61 , 0x54 , 0xa2 , 0xd3 , 0x16 , 0x3e , 0xf7 , 0xe3 ,
0x05 , 0x89 , 0x8d , 0x8a , 0x50 , 0x87 , 0x47 , 0xbe , 0x29 , 0x18 , 0x01 , 0xb7 , 0xc3 , 0xdd , 0x43 ,
0x23 , 0x7a , 0xcd , 0x85 , 0x1d , 0x4e , 0xa9 , 0xc0 , 0x1a , 0xa4 , 0x77 , 0xab , 0xe7 , 0x31 , 0x9a ,
0x33 , 0x1b , 0x7a , 0x86 , 0xe1 , 0xe5 , 0xca , 0x0c , 0x43 , 0x1a , 0xfa , 0xec , 0x4c , 0x05 , 0xc6 ,
0xd1 , 0x43 , 0x12 , 0xf9 , 0x4d , 0x3e , 0xf7 , 0xd6 , 0x05 , 0x9c , 0x1c , 0xdd ,
};


const unsigned char H_prime[32]=
{
	0x4f , 0xf1 , 0xa2 , 0xa5 , 0x61 , 0x67,
	0xc8 , 0xe0 , 0xad , 0x16 , 0xc8 , 0x95,
	0x99 , 0x1b , 0x1a , 0x21 , 0xa8 , 0x80,
	0xc6 , 0x27 , 0x39 , 0x3f , 0xc7 , 0xbb,
	0x83 , 0xed , 0xa7 , 0xe5 , 0x69 , 0x07,
	0xa5 , 0xdc
};


const unsigned char Ekh_km[16] = {
	0xe6 ,0x57 ,0x8e ,0xbc ,0xc7 ,0x68,
	0x44 ,0x87 ,0x88 ,0x8a ,0x9b ,0xd7,
	0xd6 ,0xae ,0x38 ,0xbe
};


const unsigned char L_prime[32] = {
	0xf2 ,0x0f, 0x13 ,0x6e ,0x85 ,0x53,
	0xc1 ,0x0c, 0xd3 ,0xdd ,0xb2 ,0xf9,
	0x6d ,0x33, 0x31 ,0xf9 ,0xcb ,0x6e,
	0x97 ,0x8c, 0xcd ,0x5e ,0xda ,0x13,
	0xdd ,0xea, 0x41 ,0x44 ,0x10 ,0x9b,
	0x51 ,0xb0
};

const unsigned char Rrx[8]={0xe1 , 0x7a  , 0xb0 , 0xfd , 0x0f , 0x54 ,  0x40,  0x52};
const unsigned char RxCaps[3]={0x02 , 0x0  , 0x0 };

/*
unsigned char ks[16]={
0xf3 ,0xdf ,0x1d ,0xd9 ,0x57 ,0x96,
0x12 ,0x3f ,0x98 ,0x97 ,0x89 ,0xb4,
0x21 ,0xe1 ,0x2d ,0xe1 };
*/

#if 0

const unsigned char lc128[16] = {
	//0x93,0xce,0x5a ,0x56 ,0xa0 ,0xa1 ,0xf4 ,0xf7 ,0x3c,
	//0x65,0x8a,0x1b ,0xd2 ,0xae ,0xf0 ,0xf7
	 0xB5, 0xD8, 0xE9, 0xAB, 0x5F, 0x8A ,0xFE, 0xCA ,0x38, 0x55, 0xB1, 0xA5, 0x1E, 0xC9 ,0xBC, 0x0F ,
};

const unsigned char Riv[8]={
	0x9a , 0x6d , 0x11 , 0x00 , 0xa9 ,0xb7,
	0x6f ,0x64
};
#endif



const unsigned char Hdcp2_2_lc128[16] = {
	0x93 , 0xCE , 0x5a , 0x56 , 0xa0 , 0xa1 , 0xf4 , 0xf7 , 0x3c , 0x65 , 0x8a , 0x1b , 0xd2 , 0xae , 0xf0 ,0xf7
};


unsigned char Rxcap[3]={2,0,0};
unsigned char Km[16]={
0xca, 0x9f , 0x83 , 0x95 , 0x70 , 0xd0,
0xd0, 0xf9 , 0xcf , 0xe4 , 0xeb , 0x54,
0x7e, 0x09 , 0xfa , 0x3b

};
#endif



/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
unsigned char g_bmsg_id[HDMI_RX_PORT_MAX_NUM] ,g_RX_state[HDMI_RX_PORT_MAX_NUM] , g_Rx_Send_State[HDMI_RX_PORT_MAX_NUM];
unsigned char TX_msg_id[HDMI_RX_PORT_MAX_NUM][540] ;
unsigned int b_Tx_Len[HDMI_RX_PORT_MAX_NUM];





/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/












/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/


void lib_enable_reauth(unsigned char nport)
{
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~(HDMI_HDCP_2p2_CR_enable_reauth_mask), HDMI_HDCP_2p2_CR_enable_reauth_mask);
}


void lib_disable_reauth(unsigned char nport)
{
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~(HDMI_HDCP_2p2_CR_fw_mode_riv_mask), 0);
}



void lib_hdcp_debug(unsigned char nport)
{
	hdmi_mask(0xb800d028,~(_BIT4|_BIT5|_BIT6|_BIT7|_BIT8|_BIT9), (0x2d)<<4);		 // sel  hdmi rx debug
	hdmi_mask(0xb800d1ac,~(_BIT4|_BIT5|_BIT6|_BIT7), (0x1)<<4); 	 // sel  hdmi_MHL top debug sel mhl hdmi dfe cbus debug
	hdmi_mask(0xb80008c0,~(_BIT0|_BIT1|_BIT2|_BIT3|_BIT4|_BIT5|_BIT6|_BIT7), (0x6));	  // test pin mux
	hdmi_mask(0xb80008c0,~(_BIT0|_BIT1|_BIT2|_BIT3|_BIT4|_BIT5|_BIT6|_BIT7), (0x6));	  // test pin mux

	//pin mux
	hdmi_mask(0xb8000800,~(_BIT28|_BIT29|_BIT30|_BIT31), (0xe)<<28);
	hdmi_mask(0xb800081c,~(_BIT28|_BIT29|_BIT30|_BIT31), (0xe)<<28);
	hdmi_mask(0xb800081c,~(_BIT12|_BIT13|_BIT14|_BIT15), (0xe)<<12);
#ifndef ENABLE_FUNCTIONAL_TEST
	//0xb8060208 used by MT board GPIO, do not touch it
	hdmi_mask(0xb8060208,~(_BIT20|_BIT21|_BIT22|_BIT23), (0xe)<<20);
#endif
	hdmi_mask(0xb8000814,~(_BIT7|_BIT6|_BIT5|_BIT4), (0xe)<<4);
	hdmi_mask(0xb8000818,~(_BIT15|_BIT14|_BIT13|_BIT12), (0xe)<<12);
}

char lib_get_hdmi_hdcp22_write_msg(unsigned char nport)
{
	if (HDMI_HDCP_2p2_SR0_get_irq_wr_msg_done(hdmi_in(HDMI_HDCP_2p2_SR0_reg)))	return 1;
	else		return 0;															return 0;
}

char lib_get_hdmi_hdcp22_read_msg(unsigned char nport)
{
	if (HDMI_HDCP_2p2_SR0_get_irq_rd_msg_done(hdmi_in(HDMI_HDCP_2p2_SR0_reg)))	return 1;
	else		return 0;																	return 0;
}

void lib_hdmi_hdcp22_set_rd_msg_done_irq(unsigned char nport, unsigned char enable)
{
	hdmi_mask(HDMI_HDCP_2p2_SR1_reg,~(HDMI_HDCP_2p2_SR1_irq_rd_msg_done_en_mask), HDMI_HDCP_2p2_SR1_irq_rd_msg_done_en(enable));
}

void lib_clear_hdmi_hdcp22_read_status(unsigned char nport)
{
	hdmi_out(HDMI_HDCP_2p2_SR0_reg,HDMI_HDCP_2p2_SR0_irq_rd_msg_done_mask);
}

#if 1
void lib_hw_cipher_setting(unsigned char nport, unsigned char *lc128)
{
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~(HDMI_HDCP_2p2_CR_fw_mode_riv_mask), HDMI_HDCP_2p2_CR_fw_mode_riv_mask);
	//initial ks value
	/*
	hdmi_mask(HDCP_2p2_ks0_reg,~HDCP_2p2_ks0_ks_mask, (ks[15]|(ks[14]<<8)|(ks[13]<<16)|(ks[12]<<24)));
	hdmi_mask(HDCP_2p2_ks1_reg,~HDCP_2p2_ks1_ks_mask, (ks[11]|(ks[10]<<8)|(ks[9]<<16)|(ks[8]<<24)));
	hdmi_mask(HDCP_2p2_ks2_reg,~HDCP_2p2_ks2_ks_mask, (ks[7]|(ks[6]<<8)|(ks[5]<<16)|(ks[4]<<24)));
	hdmi_mask(HDCP_2p2_ks3_reg,~HDCP_2p2_ks3_ks_mask, (ks[3]|(ks[2]<<8)|(ks[1]<<16)|(ks[0]<<24)));
	*/
	//lc 128
	hdmi_mask(HDMI_HDCP_2p2_lc0_reg,~HDMI_HDCP_2p2_lc0_lc_mask, (lc128[15]|(lc128[14]<<8)|(lc128[13]<<16)|(lc128[12]<<24)));
	hdmi_mask(HDMI_HDCP_2p2_lc1_reg,~HDMI_HDCP_2p2_lc1_lc_mask, (lc128[11]|(lc128[10]<<8)|(lc128[9]<<16)|(lc128[8]<<24)));
	hdmi_mask(HDMI_HDCP_2p2_lc2_reg,~HDMI_HDCP_2p2_lc2_lc_mask, (lc128[7]|(lc128[6]<<8)|(lc128[5]<<16)|(lc128[4]<<24)));
	hdmi_mask(HDMI_HDCP_2p2_lc3_reg,~HDMI_HDCP_2p2_lc3_lc_mask, (lc128[3]|(lc128[2]<<8)|(lc128[1]<<16)|(lc128[0]<<24)));

	//Riv
	/*
	hdmi_mask(HDCP_2p2_riv0_reg,~HDCP_2p2_riv0_riv_mask, (Riv[7]|(Riv[6]<<8)|(Riv[5]<<16)|(Riv[4]<<24)));
	hdmi_mask(HDCP_2p2_riv1_reg,~HDCP_2p2_riv1_riv_mask, (Riv[3]|(Riv[2]<<8)|(Riv[1]<<16)|(Riv[0]<<24)));
	*/

}

#else
void lib_hw_cipher_setting(unsigned char nport)
{
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~(HDMI_HDCP_2p2_CR_fw_mode_riv_mask), HDMI_HDCP_2p2_CR_fw_mode_riv_mask);
	//initial ks value
	/*
	hdmi_mask(HDCP_2p2_ks0_reg,~HDCP_2p2_ks0_ks_mask, (ks[15]|(ks[14]<<8)|(ks[13]<<16)|(ks[12]<<24)));
	hdmi_mask(HDCP_2p2_ks1_reg,~HDCP_2p2_ks1_ks_mask, (ks[11]|(ks[10]<<8)|(ks[9]<<16)|(ks[8]<<24)));
	hdmi_mask(HDCP_2p2_ks2_reg,~HDCP_2p2_ks2_ks_mask, (ks[7]|(ks[6]<<8)|(ks[5]<<16)|(ks[4]<<24)));
	hdmi_mask(HDCP_2p2_ks3_reg,~HDCP_2p2_ks3_ks_mask, (ks[3]|(ks[2]<<8)|(ks[1]<<16)|(ks[0]<<24)));
	*/
	//lc 128
	hdmi_mask(HDMI_HDCP_2p2_lc0_reg,~HDMI_HDCP_2p2_lc0_lc_mask, (lc128[15]|(lc128[14]<<8)|(lc128[13]<<16)|(lc128[12]<<24)));
	hdmi_mask(HDMI_HDCP_2p2_lc1_reg,~HDMI_HDCP_2p2_lc1_lc_mask, (lc128[11]|(lc128[10]<<8)|(lc128[9]<<16)|(lc128[8]<<24)));
	hdmi_mask(HDMI_HDCP_2p2_lc2_reg,~HDMI_HDCP_2p2_lc2_lc_mask, (lc128[7]|(lc128[6]<<8)|(lc128[5]<<16)|(lc128[4]<<24)));
	hdmi_mask(HDMI_HDCP_2p2_lc3_reg,~HDMI_HDCP_2p2_lc3_lc_mask, (lc128[3]|(lc128[2]<<8)|(lc128[1]<<16)|(lc128[0]<<24)));

	//Riv
	/*
	hdmi_mask(HDCP_2p2_riv0_reg,~HDCP_2p2_riv0_riv_mask, (Riv[7]|(Riv[6]<<8)|(Riv[5]<<16)|(Riv[4]<<24)));
	hdmi_mask(HDCP_2p2_riv1_reg,~HDCP_2p2_riv1_riv_mask, (Riv[3]|(Riv[2]<<8)|(Riv[1]<<16)|(Riv[0]<<24)));
	*/

}
#endif

void lib_ks_setting(unsigned char nport, unsigned char* bKs)
{
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~(HDMI_HDCP_2p2_CR_fw_mode_riv_mask), HDMI_HDCP_2p2_CR_fw_mode_riv_mask);
	//initial ks value
	hdmi_mask(HDMI_HDCP_2p2_ks0_reg,~HDMI_HDCP_2p2_ks0_ks_mask, ((*(bKs+15))|((*(bKs+14))<<8)|((*(bKs+13))<<16)|((*(bKs+12))<<24)));
	hdmi_mask(HDMI_HDCP_2p2_ks1_reg,~HDMI_HDCP_2p2_ks1_ks_mask, ((*(bKs+11))|((*(bKs+10))<<8)|((*(bKs+9))<<16)|((*(bKs+8))<<24)));
	hdmi_mask(HDMI_HDCP_2p2_ks2_reg,~HDMI_HDCP_2p2_ks2_ks_mask, ((*(bKs+7))|((*(bKs+6))<<8)|((*(bKs+5))<<16)|((*(bKs+4))<<24)));
	hdmi_mask(HDMI_HDCP_2p2_ks3_reg,~HDMI_HDCP_2p2_ks3_ks_mask, ((*(bKs+3))|((*(bKs+2))<<8)|((*(bKs+1))<<16)|((*bKs)<<24)));

	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_ks_done_mask, HDMI_HDCP_2p2_CR_ks_done_mask);
	HDCP_2P2_PRINTF("[HDCP2.2]KS_Setting bKs  = 0x%x , 0x%x ,0x%x ,0x%x ,0x%x ,0x%x ,0x%x ,0x%x ,\n",(*bKs),*(bKs+1),*(bKs+2),*(bKs+3),*(bKs+4),*(bKs+5),*(bKs+6),*(bKs+7));

}

void lib_riv_setting(unsigned char nport, unsigned char* bRiv)
{
	hdmi_mask(HDMI_HDCP_2p2_riv0_reg,~HDMI_HDCP_2p2_riv0_riv_mask, (*(bRiv+7)|(*(bRiv+6)<<8)|(*(bRiv+5)<<16)|(*(bRiv+4)<<24)));
	hdmi_mask(HDMI_HDCP_2p2_riv1_reg,~HDMI_HDCP_2p2_riv1_riv_mask, (*(bRiv+3)|(*(bRiv+2)<<8)|(*(bRiv+1)<<16)|((*bRiv)<<24)));

	HDCP_2P2_PRINTF("[HDCP2.2]Riv_Setting bRiv = 0x%x , 0x%x ,0x%x ,0x%x ,0x%x ,0x%x ,0x%x ,0x%x , \n",(*bRiv),*(bRiv+1),*(bRiv+2),*(bRiv+3),*(bRiv+4),*(bRiv+5),*(bRiv+6),*(bRiv+7));

}

void lib_hdmi_hdcp22_init(unsigned char nport)
{
	unsigned char uc_lc128[16];

	HDCP_2P2_PRINTF("[HDCP2.2] lib_hdcp22_init\n");
	// enable hdcp 2.2 HW
	//hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask, 0);
	hdmi_mask(HDMI_HDCP_2p2_SR1_reg,~HDMI_HDCP_2p2_SR1_irq_wr_msg_done_en_mask, HDMI_HDCP_2p2_SR1_irq_wr_msg_done_en_mask);
	// open write & read msg irq for flag
	//hdmi_mask(HDCP_2p2_SR1_reg,~(HDCP_2p2_SR1_irq_rd_msg_done_en_mask|HDCP_2p2_SR1_irq_wr_msg_done_en_mask), (0));
	if(newbase_hdmi_get_customer_hdcp2p2())
	{
		HDCP_2P2_PRINTF("[HDCP2.2] hdcp2_load_from_AP\n");
		hdcp2_load_from_ap(newbase_hdmi_get_customer_hdcp2p2_table());
	}
	else
	hdcp2_load_from_flash();
	// SET Lc
	hdcp2_get_lc128(uc_lc128);
	lib_hw_cipher_setting(nport, uc_lc128);
	//hdmi_mask(INTERRUPT_INT_CTRL_VCPU_VADDR, ~(_BIT2), 0);  // stop disp I interrupt

	//HDCP_Debug();

	//2106.08.08 willychou add HDCP2p2
	//STD flow : hdcp2_init_module =>vfe_suspend_std  =>vfe_resume_std =>vfe_hdmi_drv_init => vfe_hdmi_drv_open => vfe_hdmi_drv_connect
              hdmi_out(SYS_REG_INT_CTRL_MEMC_reg, (SYS_REG_INT_CTRL_MEMC_hdmi_irq_scpu_routing_en_mask|SYS_REG_INT_CTRL_MEMC_write_data_mask));
}

void lib_hdmi_hdcp22_write_data_to_tx(unsigned char nport, unsigned char* bSendData, unsigned short wLen)
{
	unsigned short i ;//,wCnt;
	//if(bSendData ==NULL)     return FALSE;
	/*
	if (wLen > 0x3F)
	{
		HDCP_2P2_PRINTF("[HDCP2.2] illegal Addr !!!! ERROR  \n");
		return FALSE;
	}
	*/
	for(i=0;i<wLen;i++)
	{
		hdmi_out(HDMI_HDCP_MSAP_reg,i);
		hdmi_out(HDMI_HDCP_MSDP_reg,*(bSendData+i));
	}
#if 1   // wlen bug for TX polling
#if 0
	hdmi_mask(0xb800d204,~_BIT0, _BIT0);
	//drvif_Hdmi_HPD(1,0);	 //high
	while((!(hdmi_in(HDMI_HDCP_FLAG1_reg)&_BIT3))&&(wCnt<5000))
	{
		wCnt++;
	}
	hdmi_out(0xb800d210,_BIT3);

	//drvif_Hdmi_HPD(1,1);	   //LOW
#endif

	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr);
	hdmi_out(HDMI_HDCP_DP_reg,(wLen&0xFF));
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr+1);
	hdmi_out(HDMI_HDCP_DP_reg,((wLen&0x3FF)>>8));

	//hdmi_mask(0xb800d204,~_BIT0, 0);
#else
	hdmi_out(0xb800d24c,_BIT16);
	while (!(hdmi_in(0xb800d24c)&_BIT16));
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr);
	hdmi_out(HDMI_HDCP_DP_reg,(wLen&0xFF));
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr+1);
	hdmi_out(HDMI_HDCP_DP_reg,((wLen&0x3FF)>>8));

#endif

	HDCP_2P2_PRINTF("[HDCP2.2] Hdmi_HDCP2_2_Write_Data_to_TX!!!! wlen =%d   date 0 =0x%x ,date1 = 0x%x , date2 =0x%x \n",wLen,*(bSendData),*(bSendData+1),*(bSendData+2));
	//	return TRUE;
}


#if DEFAULT_KEY_TEST
void lib_AKE_send_cert(unsigned char nport)
{
	unsigned short wLen , i;
	wLen = 534;
	//msg_id
	hdmi_out(HDMI_HDCP_MSAP_reg,0);
	hdmi_out(HDMI_HDCP_MSDP_reg,AKE_Send_Cert);
	//certrx
	for(i=0;i<522;i++)
	{
		hdmi_out(HDMI_HDCP_MSAP_reg,i+1);
		hdmi_out(HDMI_HDCP_MSDP_reg,Hdcp2_2_Certrx[(i)]);
	}
	//rrx
	for(i=0;i<8;i++)
	{
		hdmi_out(HDMI_HDCP_MSAP_reg,i+523);
		hdmi_out(HDMI_HDCP_MSDP_reg,Rrx[(i)]);
	}
	//rxcaps
	for(i=0;i<8;i++)
	{
		hdmi_out(HDMI_HDCP_MSAP_reg,i+531);
		hdmi_out(HDMI_HDCP_MSDP_reg,RxCaps[(i)]);
	}
	// fill length
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr);
	hdmi_out(HDMI_HDCP_DP_reg,(wLen&0xFF));
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr+1);
	hdmi_out(HDMI_HDCP_DP_reg,((wLen&0x3FF)>>8));

	HDCP_2P2_PRINTF("[HDCP2.2] driv_AKE_Send_Cert !!!!!     \n" );

}

void lib_AKE_send_h_prime(unsigned char nport)
{
	unsigned short wLen , i;
	wLen = 33;
	//msg_id
	hdmi_out(HDMI_HDCP_MSAP_reg,0);
	hdmi_out(HDMI_HDCP_MSDP_reg,AKE_Send_H_prime);
	//H_parameter
	for(i=0;i<32;i++)
	{
		hdmi_out(HDMI_HDCP_MSAP_reg,i+1);
		hdmi_out(HDMI_HDCP_MSDP_reg,H_prime[(i)]);
	}

	// fill length
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr);
	hdmi_out(HDMI_HDCP_DP_reg,(wLen&0xFF));
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr+1);
	hdmi_out(HDMI_HDCP_DP_reg,((wLen&0x3FF)>>8));

	HDCP_2P2_PRINTF("[HDCP2.2] driv_AKE_Send_H_prime !!!!!     \n" );
}

void lib_AKE_send_pariring_info(unsigned char nport)
{
	unsigned short wLen , i;
	wLen = 17;
	//msg_id
	hdmi_out(HDMI_HDCP_MSAP_reg,0);
	hdmi_out(HDMI_HDCP_MSDP_reg,AKE_Send_Pariring_Info);
	//H_parameter
	for(i=0;i<16;i++)
	{
		hdmi_out(HDMI_HDCP_MSAP_reg,i+1);
		hdmi_out(HDMI_HDCP_MSDP_reg,Ekh_km[(i)]);
	}

	// fill length
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr);
	hdmi_out(HDMI_HDCP_DP_reg,(wLen&0xFF));
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr+1);
	hdmi_out(HDMI_HDCP_DP_reg,((wLen&0x3FF)>>8));

	HDCP_2P2_PRINTF("[HDCP2.2]driv_AKE_Send_Pariring_Info !!!!!     \n" );
}

void lib_LC_send_l_prime(unsigned char nport)
{
	UINT16 wLen , i;
	wLen = 33;
	//msg_id
	hdmi_out(HDMI_HDCP_MSAP_reg,0);
	hdmi_out(HDMI_HDCP_MSDP_reg,LC_Send_L_prime);
	//H_parameter
	for(i=0;i<32;i++)
	{
		hdmi_out(HDMI_HDCP_MSAP_reg,i+1);
		hdmi_out(HDMI_HDCP_MSDP_reg,L_prime[(i)]);
	}

	// fill length
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr);
	hdmi_out(HDMI_HDCP_DP_reg,(wLen&0xFF));
	hdmi_out(HDMI_HDCP_AP_reg,HDCP_RXstatus_addr+1);
	hdmi_out(HDMI_HDCP_DP_reg,((wLen&0x3FF)>>8));
	HDCP_2P2_PRINTF("[HDCP2.2]driv_LC_Send_L_prime !!!!!     \n" );

}
#endif

void lib_wait_TX_read_finish(unsigned char nport)
{
    while(!lib_get_hdmi_hdcp22_read_msg(nport));

    hdmi_out(HDMI_HDCP_2p2_SR0_reg,HDMI_HDCP_2p2_SR0_irq_rd_msg_done_mask);
    HDCP_2P2_PRINTF("[HDCP2.2] TX read finish !!!!!     \n" );

}

void lib_hdmi_hdcp22_force_cipher(unsigned char nport)
{
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~(HDMI_HDCP_2p2_CR_switch_state_mask), HDMI_HDCP_2p2_CR_switch_state(0x10));	 //set authenticated
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~(HDMI_HDCP_2p2_CR_apply_state_mask|HDMI_HDCP_2p2_CR_fw_mode_riv_mask), (HDMI_HDCP_2p2_CR_apply_state_mask|HDMI_HDCP_2p2_CR_fw_mode_riv_mask));
}

void lib_get_msg_command(unsigned char nport)
{
#if HDCP2_2
	unsigned char bLen,i ;
	if (lib_get_hdmi_hdcp22_write_msg(nport))  //GET TX mesage
	{
		//for test gpo
		//hdmi_mask(0xb8061108,~_BIT4,_BIT4);  // must close hdcp1.4
		//hdmi_mask(INTERRUPT_INT_CTRL_VCPU_VADDR, ~(_BIT2), 0);  // stop disp I interrupt
		//hdmi_mask(0xb8061108,~_BIT24,_BIT24);

		hdmi_out(HDMI_HDCP_2p2_SR0_reg,HDMI_HDCP_2p2_SR0_irq_wr_msg_done_mask);
#if 0
	hdmi_mask(HDMI_HDCP_CR_reg,~HDMI_HDCP_CR_hdcp_en_mask,0);  // must close hdcp1.4
	hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask, HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask);	//open hdcp2p2
#endif

		hdmi_out(HDMI_HDCP_MSAP_reg,0);
		g_bmsg_id[nport] = hdmi_in(HDMI_HDCP_MSDP_reg);
		TX_msg_id[nport][0]= g_bmsg_id[nport];
		HDCP_2P2_PRINTF("[HDCP2.2] bmsg_id[%d]  =%x     \n", nport, g_bmsg_id[nport]);

		g_Rx_Send_State[nport] =  RX_FSM_SEND_START;
		switch (g_bmsg_id[nport]) {
			case AKE_INIT:
				g_RX_state[nport] =  AKE_Send_Cert ;//AKE_Send_Cert ;
				bLen = 11;
				lib_hdmi_hdcp22_enable(nport, 1);
				lib_hdmi_hdcp14_enable(nport, 0);
				newbase_hdcp_init_timer(nport);
#if (HDCP2_SEND_PAIRINGINFO_BY_IRQ_RD)
				lib_hdmi_hdcp22_set_rd_msg_done_irq(nport, 0);
#endif
				break;
			case AKE_NO_Stored_Km:
				g_RX_state[nport] =  AKE_Send_H_prime;//AKE_Send_H_prime ;
				bLen =128;
				break;
			case AKE_Stored_Km:
				g_RX_state[nport] =  AKE_Send_H_prime;//AKE_Send_H_prime ;
				bLen =32;
				break;
			case LC_Init:
				//hdmi_mask(0xb8061108,~_BIT24,_BIT24);
				g_RX_state[nport] =  LC_Send_L_prime;//LC_Send_L_prime ;
				bLen =8;
				break;
			case SKE_Send_Eks:
				//hdmi_mask(HDCP_2p2_CR_reg,~HDCP_2p2_CR_ks_done_mask, HDCP_2p2_CR_ks_done_mask);
#if 0 //HDCP_BUG
				hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_switch_state_mask, HDMI_HDCP_2p2_CR_switch_state(0x01));
				hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_apply_state_mask, HDMI_HDCP_2p2_CR_apply_state_mask);
#endif
				//open ISR
				//hdmi_mask(INTERRUPT_INT_CTRL_VCPU_VADDR, ~(_BIT2), _BIT2);  // stop disp I interrupt
				bLen =24;
				break;
			default:
				HDCP_2P2_PRINTF("[HDCP2.2] illegal msg\n");
				return;
		}

		for (i = 1; i <= bLen; i++) {
			TX_msg_id[nport][i] = hdmi_in(HDMI_HDCP_MSDP_reg);
			//This log take too much time will out of timing spec
			//	HDCP_2P2_PRINTF("[HDCP2.2] Tx write data%x  =%x     \n",i,TX_msg_id[i] );
		}

		// for HW Cipher setting
		if (g_bmsg_id[nport] == SKE_Send_Eks)	lib_riv_setting(nport, (&(TX_msg_id[nport][17])));  // set Riv address

		//hdmi_out(HDCP_2p2_SR0_reg,HDCP_2p2_SR0_irq_wr_msg_done_mask);
		//HDCP_2P2_PRINTF("[HDCP2.2] HW Receiver Status = %x      \n", HDCP_2p2_SR0_get_state(hdmi_in(HDCP_2p2_SR0_reg)));

		//hdcp2.2 sw parse the message
		//for test gpo

		h2MessageParse(TX_msg_id[nport], bLen);
		//hdmi_mask(0xb8061108,~_BIT24,0);

		//hdmi_mask(0xb8061108,~_BIT4,0);  // must close hdcp1.4

#if 0 //HDCP_BUG
		if (g_bmsg_id ==SKE_Send_Eks)
		{
			//HDCP_2P2_PRINTF("[HDCP2.2] Second Times AKINIT RESET start %x !!!!!!!!\n",hdmi_in(HDMI_HDCP_2p2_CR_reg));
			//HDCP_2P2_PRINTF("[HDCP2.2] Second Times AKINIT RESET!!!!!!!!     \n");
			hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_switch_state_mask, HDMI_HDCP_2p2_CR_switch_state(0x10));
			hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_apply_state_mask, HDMI_HDCP_2p2_CR_apply_state_mask);
			//HDCP_2P2_PRINTF("[HDCP2.2] Second Times AKINIT RESET!!!!!!!!     \n");
			// hdmi_mask(0xb8061108,~_BIT24,0);
		}
#endif
	}
#endif
}

void lib_send_msg_command(unsigned char nport)
{
	if (g_Rx_Send_State[nport] ==  RX_FSM_SEND_START )
	{
#if DEFAULT_KEY_TEST
		switch(g_RX_state[nport])
		{
			case  AKE_Send_Cert :	lib_AKE_send_cert(nport);  break;
			case  AKE_Send_H_prime :  lib_AKE_send_h_prime(nport); break;
			case  AKE_Send_Pariring_Info :  lib_AKE_send_pariring_info(nport);  break;
			case  LC_Send_L_prime :   lib_LC_send_l_prime(nport);  break;
		}
#endif
		g_Rx_Send_State[nport] = RX_FSM_WAIT ;
	}

#if (HDCP2_SEND_PAIRINGINFO_BY_IRQ_RD)
	g_Rx_Send_State[nport] = RX_FSM_FINISH ;

	if (lib_get_hdmi_hdcp22_read_msg(nport))
#endif
	{
		if ((g_RX_state[nport] == AKE_Send_H_prime)&&(g_bmsg_id[nport] ==  AKE_NO_Stored_Km ))
		{
			h2MessagePoll(NULL, 0);
			g_Rx_Send_State[nport] = RX_FSM_SEND_START;
			g_RX_state[nport] = AKE_Send_Pariring_Info;
		}
		else
		{
			g_Rx_Send_State[nport] = RX_FSM_FINISH ;
		}
		lib_clear_hdmi_hdcp22_read_status(nport);
		HDCP_2P2_PRINTF("[HDCP2.2] Tx Read finish !!!!!     \n" );
	}
	/*
	else
	{
		g_Rx_Send_State =  RX_FSM_WAIT ;
	}
	*/

}

/*********************************************************************************
*
*	hdcp_newbase
*
*********************************************************************************/
void newbase_msg_hander(unsigned char nport)
{
	// printk("[HDCP2.2] test  msg_hander   ");
	lib_get_msg_command(nport);
	lib_send_msg_command(nport);
}

void newbase_hdmi_hdcp22_write_data_to_tx(unsigned char nport, unsigned char* bSendData, unsigned short wLen)
{
	lib_hdmi_hdcp22_write_data_to_tx(nport, bSendData, wLen);
}


void newbase_ks_setting(unsigned char nport, unsigned char* bKs)
{
	return (lib_ks_setting(nport, bKs));
}

/* //removed by jerry. This function could be removed instead of clearing read_flag. Need to more testings.
void newbase_hdmi_hdcp2_clear_status(unsigned char port)
{
	g_bmsg_id[port] = NULL_MSG;

#if (HDCP2_SEND_PAIRINGINFO_BY_IRQ_RD)
	lib_hdmi_hdcp22_set_rd_msg_done_irq(port, 0);
	lib_clear_hdmi_hdcp22_read_status(port);
#endif
}
*/


