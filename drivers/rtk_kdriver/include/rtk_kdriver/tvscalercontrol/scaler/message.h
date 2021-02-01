#ifndef __SCALER_MESSAGE_H__
#define __SCALER_MESSAGE_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>
//#include <global.h>

/*===================================  Types ================================*/

/*================================== Variables ==============================*/
/*================================ Definitions ==============================*/

#if defined(CONFIG_REMOTE_CONTROL_XOCECO)
#define CONFIG_MESSAGE_QUEUE_SIZE 	 10         //  2	// Define the size of message queue
#else
#define CONFIG_MESSAGE_QUEUE_SIZE 	10	// Define the size of message queue
#endif

#define MESSAGE_SIG			0x01
#define TIME_EVENT_SIG		0x02

#define MessageForm(ucType, MsgNo) ((((unsigned int)(ucType & 0x00ff)) << 16) | (MsgNo & 0xffff))
#define MessageType(msg) ((unsigned short)((msg & 0x00ff0000) >> 16))
#define MessageNo(msg) ((unsigned short)(msg & 0x0000ffff))


#if !defined(_MESSAGE_C)
extern unsigned char ucUiReady;
#endif

#define IS_UI_READY()		(ucUiReady == 0x5a)
#define CLR_UI_READY()		(ucUiReady = 0x00)
#define SET_UI_READY()		(ucUiReady = 0x5a)

/*================================== Function ===============================*/
/*===========================================================================*/
/**
 * Message_Initial
 * Initial message System
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void Message_Initial(void);

/*============================================================================*/
/**
 * ui_message_push
 * Push message into message queues
 *
 * @param <message>	{ message to be placed in messasge queues }
 * @return 			{ void }
 *
 */
void ui_message_push(unsigned int message);

/*============================================================================*/
/**
 * ui_message_pop
 * Get message in message queue
 *
 * @param <void>		{ void }
 * @return 			{ Get a message in message queues }
 *
 */
unsigned int ui_message_pop(void);

/*============================================================================*/
/**
 * ui_message_clear
 * Clear all message in message queue
 *
 * @param <void>		{ void }
 * @return			{ void }
 *
 */
void ui_message_clear(void);

/*============================================================================*/
/**
 * ui_message_clear
 * Clear all message in message queue
 *
 * @param <void>		{ void }
 * @return			{ void }
 *
 */
void ui_message_clear(void);

#if defined(CONFIG_REMOTE_CONTROL_XOCECO)
void IRKeyClean(void);
#endif

/*============================================================================*/
/**
 * ui_message_clearMessage
 * Clear a  message in message queue
 *
 * @param <void>		{ void }
 * @return			{ void }
 *
 */
//void ui_message_clearMessage(unsigned int message);

#ifdef __cplusplus
}
#endif

#endif // __SCALER_MESSAGE_H__


