/**
 * @file kw_uart.h
 * @brief This header file defines Real-Image uart printf/receive function.
 * @date August.24.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par KW Debug trace V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifndef _REAL_UART_HEADER_
#define _REAL_UART_HEADER_

#include "memc_isr/include/kw_type.h"

/**
 * @brief This exported function output one character through uart. Please provide this function for debug.
 * @param [in] ch		Character want to output
*/
VOID Uart_Printf(SCHAR ch);

/**
 * @brief This exported function receive strings through uart. This function does not block, it gratch data from buffer then return. Please provide this function for debug.
 * @param [in] pcBuf		String buffer for received string
 * @param [in] iBufSize		Buf size including string termiante 0 byte.
 * @return Real string length received
*/
SINT32 Uart_Receive(SCHAR *pcBuf, SINT32 iBufSize);

#endif /* End of #ifndef _REAL_COMMON_HEADER_ */


