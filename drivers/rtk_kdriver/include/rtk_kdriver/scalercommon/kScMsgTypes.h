/***************************************************************************
               kScMsgTypes.h  -  Kernel/SC Message Type
                             -------------------
    begin                : Fri Oct 21 2005
    copyright            : (C) 2005 by Johnson
    email                : ljshuenn@realtek.com.tw
 ***************************************************************************/

/**
        @file kScMsgTypes.h
        @author Johnson ljshuenn@realtek.com.tw
        @ingroup
*/
/*==========================================================================
        $Header: /cvsroot/dtv/include/system/sysControl/kScMsgTypes.h,v 1.1 2005/10/21 02:43:10 ljshuenn Exp $
        $Log: kScMsgTypes.h,v $
        Revision 1.1  2005/10/21 02:43:10  ljshuenn
        *: Move message types to kScMsgTypes.h


*==========================================================================*/
#ifndef _COMMON_KSCMSGTYPES_H__
#define _COMMON_KSCMSGTYPES_H__

	#define		SC_MAX_UDP_DATA			64				///< Define the max message size
	#define		RT_MAX_UDP_DATA			SC_MAX_UDP_DATA

	// Define the message type
	typedef enum	{
		SC_ALL_MSG					=	0x00000000,			///< If the msg type is 0, it means all msg.

		SC_UI_MSG					=	0x00010000,			///< UI Message. The key event uses this msg type. The subType is the key code.

		SC_UI_TERMINATE				=	0x0001FFFF,			///< Terminate the UI Thread

		SC_SIDB_MSG					=	0x00020000,			///< SiDB Message

		SC_SUBTITLE_MSG				=	0x00030000,			///< Subtitle message
		SC_RC_MSG					=	0x00040000,			///< Remote control message
		SC_DTV_MODULE_MSG			=	0x00040001,			///< DTV Module message
		SC_IO_MSG					=	0x00040002,			///< I/O message
		SC_CI_MSG					=	0x00040003,			///<Common interface message

		SC_AVP_MSG					=	0x00050000,			///< AVP message
		SC_RMP_MSG					=	0x00050001,			///< rmp file play flow message
		SC_AUDIO_MSG				=	0x00050002,			///< Audio message

#if 1 //#ifdef CONFIG_NL_VO_INFO // Notify vo_info to scaler via netlink. USER: hsliao DATE: 2010/4/20
		SC_SCALER_MSG				=	0x00055000,			///< Scaler message
#endif

		SC_2620_MSG					=	0x00060000,
		SC_2547D_MSG				=	0x00070000,
		/* cyhuang (2008/3/12) : Add USB hotplug netlink message type. */
		// SC_NO_USED3					=	0x00080000,
		SC_USB_HOTPLUG				=	0x00080000,
		SC_ETH_HOTPLUG				=	0x00085000,
		SC_IFD_MSG					=	0x00090000,
		SC_NO_USED5					=	0x000A0000,
		SC_NO_USED6					=	0x000B0000,
		SC_NO_USED7					=	0x000C0000,
		SC_NO_USED8					=	0x000D0000,
		SC_TIMER					=	0x000E0000,

		SC_EMERGENCY				=	0x000F0000,			///< Emergency Message
		SC_EMERGENCY_DRIVER			=	0x000F0001,			///< The emergency msg from driver
		SC_EMERGENCY_RESERVED1		=	0x000F0010,			///< The emergency msg is reserved
		SC_EMERGENCY_RESERVED2		=	0x000F0020,			///< The emergency msg is reserved
		SC_EMERGENCY_RESERVED3		=	0x000F0040,			///< The emergency msg is reserved
		SC_EMERGENCY_RESERVED4		=	0x000F0080,			///< The emergency msg is reserved
		SC_EMERGENCY_RESERVED5		=	0x000F0100,			///< The emergency msg is reserved
		SC_EMERGENCY_TERMINATE		=	0x000FFFFF,			///< Terminate Emergency thread

		SC_TERMINATE					=	0xFFFFFFFF			///< Terminate all of the SW threads
	} SC_MSG_TYPE, RT_MSG_TYPE ;

	typedef struct _RT_MSGBUF
	{
		unsigned int								msgType;			///< msgType is dispatched by system controller
		unsigned int								msgSubType ;		///< msgSubType is dispatched by others include emergency thread
		unsigned int								msgIntData ;		///< Integer data part
		unsigned int								msgBodyByteSize ;	///< record the data size in followed data pointer
		void *								        msgDataPtr ;		///< The variable length data
		unsigned int								isValidate ;		///< Record the status of message.
	} SC_MSGBUF, RT_MSGBUF, RT_MESSAGE;

	// This is only for out-host message because it occupies actual data buffer
	typedef struct _SC_UDPMSGBUF
	{
		unsigned int								msgType;			///< msgType is dispatched by system controller
		unsigned int								msgSubType ;		///< msgSubType is dispatched by others include emergency thread
		unsigned int								msgIntData ;		///< Integer data part

		unsigned int								msgDataBuf[SC_MAX_UDP_DATA] ;
	} SC_UDPMSGBUF, RT_UDPMSGBUF ;

#endif


