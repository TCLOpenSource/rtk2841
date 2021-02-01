/**
 * @file kw_common.h
 * @brief This header file defines Real-Image common stdio/memory/string library function.
 * @date August.24.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par KW Debug trace V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifndef _REAL_COMMON_HEADER_
#define _REAL_COMMON_HEADER_

#include "memc_isr/include/kw_type.h"

#define REAL_CHIP

#ifdef DLL_IMPLEMENT
#ifdef __cplusplus
#define DLL_API extern "C" __declspec(dllexport)
#else /* else of __cplusplus*/
#define DLL_API __declspec(dllexport)
#endif /* End of #ifdef __cplusplus */
#else /* else of DLL_IMPLEMENT*/
#ifdef __cplusplus
#define DLL_API extern "C" __declspec(dllimport)
#else /* else of __cplusplus */
#ifdef WIN32
#define DLL_API __declspec(dllimport)
#else /* else of WIN32 */
#define DLL_API
#endif/* End of #ifdef WIN32 */
#endif/* End of #ifdef __cplusplus */
#endif/* End of #ifdef DLL_IMPLEMENT */

/*! define error no macro */
#define SUCCESS				0			///< success is 0
#define ERR_PARA			1			///< parameter error
#define ERR_INSUFF_BUF		2			///< insufficient buffer space

/*! define MAX/MIN macro to get max value of two input data, input must be same type */
#define MAX(x, y)  (((x) > (y)) ? (x) : (y))
#define MIN(x, y)  (((x) < (y)) ? (x) : (y))

/*! define va_list */
#ifndef	_VA_LIST
#define _VA_LIST
typedef SCHAR* va_list;
#endif /* End of #ifndef    _VA_LIST */

/*! undefine some macro to avoid redefinition in WIN32 platform */
#undef __va_size
#undef va_start
#undef va_arg
#undef va_end

/*! deinfe va_size from GCC */
#define __va_size(type) \
        (((sizeof(type) + sizeof(SINT32) - 1) / sizeof(SINT32)) * sizeof(SINT32))

/*! deinfe va_start from GCC */
#define va_start(ap, last) \
        ((ap) = (va_list)&(last) + __va_size(last))

/*! deinfe va_arg from GCC */
#define va_arg(ap, type) \
        (*(type *)((ap) += __va_size(type), (ap) - __va_size(type)))

/*! deinfe va_end from GCC */
#define va_end(ap)

/*! exported API */
/**
 * @brief This exported function convert input number string to a signed SINT32 value.
 * @param [in] pcString			String to convert to signed number
 * @return Value converted from input string. If input string is wrong, guiErrorNO is set.
*/

DLL_API SINT32 kw_atoi(SCHAR *pcString);

/**
 * @brief This exported function convert input number string to a unsigned value.
 * @param [in] pcString			String to convert to unsigned number
 * @return Value converted from input string. If input string is wrong, guiErrorNO is set.
*/
DLL_API UINT32 kw_atoui(SCHAR *pcString);

/**
 * @brief This exported function concat the source string into dest string and return the dest string.
 * @param [in] pcDest		Dest string need to concat. The pcDest must have enough space to save source string, otherwise pcSource truncated.
 * @param [in] iDestBufLen	Dest buffer total length including pcDest original string length
 * @param [in] pcSource		Source string
 * @return String merged. If dest string has no enough buffer, source string is truncated.
*/
DLL_API SCHAR *kw_strcat(SCHAR *pcDest, SINT32 iDestBufLen, SCHAR *pcSource);

/**
 * @brief This exported function get input string length. Does not support unicode.
 * @param [in] pcSource string pointer want to get length.
 * @return String length, if the input pointer is NULL, return 0
*/
DLL_API SINT32 kw_strlen(SCHAR *pcSource);

/**
 * @brief This exported function get common function error NO. It is better to get this value after each call.
 * @return ErrorNO of last operation
*/
DLL_API UINT32 kw_GetErrorNO(VOID);

/**
 * @brief This exported function is almost same with C runtime standard printf function
 * @param [in] pcFormat		format string of this printf. The input parameter is variable.
 * @return Character number print out from pcFormat.
*/
DLL_API SINT32 kw_printf(SCHAR *pcFormat, ...);

/**
 * @brief This exported function covnver input signed number into input buffer based on base and return the buffer.
 * @param [in] iVal			signed number want to convert to string
 * @param [in] pcBuf		buffer contains the convert string
 * @param [in] iBufLen		buffer length
 * @param [in] iBase			base is 16 for hex, 10 for dec, 2 for binary, not support others currently
 * @return Character number show out
*/
DLL_API SCHAR *kw_itoa(SINT32 iVal, SCHAR *pcBuf, SINT32 iBufLen, SINT32 iBase);

/**
 * @brief This exported function covnver input signed number into input buffer based on base and return the buffer.
 * @param [in] iVal			signed number want to convert to string
 * @param [in] pcBuf		buffer contains the convert string
 * @param [in] iBufLen		buffer length
 * @param [in] iBase		base is 16 for hex, 10 for dec, 2 for binary, not support others currently
 * @return Character number show out
*/
DLL_API SCHAR *kw_uitoa(SINT32 iVal, SCHAR *pcBuf, SINT32 iBufLen, SINT32 iBase);

/**
 * @brief This exported function copy specified length of character from source string start position into dest string.
 *		  The invoker should guarantee sufficient dest string buffer.
 * @param [in] pcDest			Dest string buffer want to copy
 * @param [in] pcSource			Source string
 * @param [in] iCpyLen			Copy length, it is the invoker responsable to guarrant buffer length
 * @param [in] iStarIndex		Source string start index
 * @return Character number show out
*/
DLL_API SCHAR *kw_strcpy(SCHAR *pcDest, SCHAR *pcSource, SINT32 iCpyLen, SINT32 iStartIndex);

// for debug purpose to get printf output
#ifdef WIN32
typedef VOID (*pPrintChar)(char ch);
DLL_API VOID kw_SetPrintfCallback(pPrintChar p);
#endif

#endif /* End of #ifndef _REAL_COMMON_HEADER_ */


