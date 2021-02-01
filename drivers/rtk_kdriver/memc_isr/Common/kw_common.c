/**
 * @file common.c
 * @brief This file implements common stdio/memory/string library function. These function only support MEMC library.
 * @date August.24.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par MEMC Library V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifdef WIN32
#define DLL_IMPLEMENT
#endif

#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Common/kw_uart.h"

#ifdef WIN32
#include <stdio.h>
#endif

/*! Global variable */
static UINT32		guiErrorNO;			///< error number

/*! Internal function for use in this file. */
/**
 * @brief This internal function convert string to Hex
 * @param pcString		String to convert to hex
 * @return Hex data returned. If input string is wrong, guiErrorNO is set.
*/
static SINT32 ConverStrToHex(SCHAR *pcString)
{
	SINT32		i;
	SINT32		iLen = kw_strlen(pcString);
	SINT32		iVal = 0;

	/* Loop to convert */
	for (i = iLen - 1; i < iLen; i--)
	{
		if (pcString[i] >= '0' && pcString[i] <= '9')
		{
			iVal |= (pcString[i] - 0x30) << (i * 4);
		}
		else if (pcString[i] >= 'A' && pcString[i] <= 'F')
		{
			iVal |= (pcString[i] - 55) << (i * 4);
		}
		else if (pcString[i] >= 'a' && pcString[i] <= 'f')
		{
			iVal |= (pcString[i] - 87) << (i * 4);
		}
		else
		{
			guiErrorNO = ERR_PARA;
			break;
		}
	}

	return iVal;
}

/**
 * @brief This internal function convert input string to a signed decimal number.
 * @param pcString		String to convert to decimal number, no signed byte. 
 * @return Deciaml number converted. If input string is wrong, guiErrorNO is set.
*/
static SINT32 ConvertStrToSINT(SCHAR *pcString)
{
	SINT32		i;
	SINT32		iLen = kw_strlen(pcString);
	SINT32		iVal = 0;

	/* Loop to convert */
	for (i = iLen - 1; i < iLen; i--)
	{
		if (pcString[i] >= '0' && pcString[i] <= '9')
		{
			iVal |= (pcString[i] - 0x30) << (i * 4);
		}
		else
		{
			guiErrorNO = ERR_PARA;
			break;
		}
	}

	return iVal;
}

#ifdef WIN32
static pPrintChar gp = NULL;

VOID kw_SetPrintfCallback(pPrintChar p)
{
	gp = p;
}

#endif

static VOID printch(SCHAR ch)
{
//	Uart_Printf(ch);
#ifdef WIN32
	printf("%c", ch);
	if (gp != NULL)
		gp(ch);
#else
	Uart_Printf(ch);
#endif
}

static VOID printdec(SINT32 dec)
{
	if(dec == 0)
	{
		return;
	}
	else if (dec < 0)
	{
		printch('-');
		dec *= -1;
	}
	
	printdec(dec / 10);
	printch((SCHAR)(dec % 10 + '0'));
}

#ifdef SUPPORT_FLOAT
static VOID printflt(double flt)
{
	SINT32 icnt = 0;
	SINT32 tmpint = 0;
    
	tmpint = (SINT32)flt;
	printdec(tmpint);
	printch('.');
	flt = flt - tmpint;
	tmpint = (SINT32)(flt * 1000000);
	printdec(tmpint);
}
#endif

static VOID printstr(const SCHAR* str)
{
	while(*str)
	{
		printch(*str++);
	}
}

static VOID printbin(UINT32 bin)
{
	if(bin == 0)
	{
		printstr("0");
		return;
	}
	printbin(bin / 2);
	printch((SCHAR)(bin % 2 + '0'));
}

static VOID printhex(UINT32 hex)
{
	if (hex == 0)
		return;

	printhex(hex / 16);

	if((hex % 16) < 10)
	{
		printch((SCHAR)(hex % 16 + '0'));
	}
	else
	{
		printch((SCHAR)(hex % 16 - 10 + 'a' ));
	}
}

/*! Exported API */

/**
 * @brief This exported function convert input number string to a signed SINT32 value.
 * @param [in] pcString			String to convert to signed number
 * @return Value converted from input string. If input string is wrong, guiErrorNO is set.
*/

SINT32 kw_atoi(SCHAR *pcString)
{
	SCHAR *pcTemp = pcString;
	BOOL bHex = FALSE;
	BOOL bNeg = FALSE;
	SINT32 iVal = 0;

	/* check input parameter */
	if (pcTemp == NULL)
	{
		guiErrorNO = ERR_PARA;
		return iVal;
	}

	/* check whether is Hex */
	if (pcTemp[0] == '0' && ((pcTemp[1] == 'x') || (pcTemp[1] == 'X')))
	{
		bHex = TRUE;
	}

	/* check negative number */
	if (pcTemp[0] == '-')
	{
		bNeg = TRUE;
	}

	/* Convert string*/
	if (bHex)
	{
		/* it is hex string like 0x12abcdef */
		pcTemp += 2;
		iVal = ConverStrToHex(pcTemp);
	}
	else if (bNeg)
	{
		/* it is negative number string like -1234 */
		pcTemp++;
		iVal = ConvertStrToSINT(pcTemp);

		iVal *= -1;
	}
	else
	{
		/* it is positive number string */
		iVal = ConvertStrToSINT(pcTemp);
	}

	/* clear errorNO */
	guiErrorNO = SUCCESS;

	return iVal;
}

/**
 * @brief This exported function convert input number string to a unsigned value.
 * @param [in] pcString			String to convert to unsigned number
 * @return Value converted from input string. If input string is wrong, guiErrorNO is set.
*/
UINT32 kw_atoui(SCHAR *pcString)
{
	SCHAR *pcTemp = pcString;
//	BOOL bHex = FALSE;
//	BOOL bNeg = FALSE;
	UINT32 uiVal = 0;

	/* check input parameter */
	if ((pcTemp == NULL) || (pcTemp[0] == '-'))
	{
		guiErrorNO = ERR_PARA;
		return uiVal;
	}

	/* check string validate */
	if (pcTemp[0] == '0' && ((pcTemp[1] == 'x') || (pcTemp[1] == 'X')))
	{
		/* hex number string */
		pcTemp += 2;
		uiVal = (UINT32)ConverStrToHex(pcTemp);
	}
	else
	{
		uiVal = (UINT32)ConvertStrToSINT(pcTemp);
	}

	/* clear errorNO */
	guiErrorNO = SUCCESS;

	return uiVal;
}

/**
 * @brief This exported function concat the source string into dest string and return the dest string.
 * @param [in] pcDest		Dest string need to concat. The pcDest must have enough space to save source string, otherwise pcSource truncated.
 * @param [in] iDestBufLen	Dest buffer total length including pcDest original string length
 * @param [in] pcSource		Source string
 * @return String merged. If dest string has no enough buffer, source string is truncated.
*/
SCHAR *kw_strcat(SCHAR *pcDest, SINT32 iDestBufLen, SCHAR *pcSource)
{
	SINT32	iBufSpaceLen;
	SCHAR	*pcDestTmp;
	SINT32	i;

	/* check input parameter if Dest string is NULL or Destbuflen is samller than Dest string Length fail strcat */
	if (pcDest == NULL || (kw_strlen(pcDest) >= iDestBufLen))
		return NULL;

	/* if source string is NULL, just return Dest string */
	if (pcSource == NULL)
		return pcDest;

	/* get buf space */
	iBufSpaceLen = iDestBufLen - kw_strlen(pcDest);

	/* minus string can fill in */
	iBufSpaceLen = iBufSpaceLen > kw_strlen(pcSource) ? kw_strlen(pcSource) : (iBufSpaceLen - 1);

	pcDestTmp = (SCHAR *)(&pcDest[kw_strlen(pcDest)]);

	for (i = 0; i < iBufSpaceLen; i++)
	{
		pcDestTmp[i] = pcSource[i];
	}

	/* set string end */
	pcDestTmp[i] = 0;

	/* clear errorNO */
	guiErrorNO = SUCCESS;
	
	return pcDest;
}

/**
 * @brief This exported function get input string length. Does not support unicode.
 * @param [in] pcSource string pointer want to get length.
 * @return String length, if the input pointer is NULL, return 0
*/
SINT32 kw_strlen(SCHAR *pcSource)
{
	SINT32	iLen = 0;
	SCHAR	*pcTemp = pcSource;

	/* check input parameter */
	if (pcTemp == NULL)
	{
		return iLen;
	}

	/* loop to scan pcSource for length */
	do
	{
		iLen++;
		pcTemp++;
	}while (*pcTemp != 0);

	/* clear errorNO */
	guiErrorNO = SUCCESS;

	return iLen;
}

/**
 * @brief This exported function get common function error NO. It is better to get this value after each call.
 * @return ErrorNO of last operation
*/
UINT32 kw_GetErrorNO(VOID)
{
	return guiErrorNO;
}

/**
 * @brief This exported function is almost same with C runtime standard printf function
 * @param [in] pcFormat		format string of this printf. The input parameter is variable.
 * @return Character number print out from pcFormat.
*/
SINT32 kw_printf(SCHAR *pcFormat, ...)
{
	SINT32		ret = 0;
	va_list		vp;
	SCHAR		*pfmt;
//	double		vargflt = 0;
	SINT32		vargint = 0;
	UINT32		varguint32 = 0;
	SCHAR		*vargpch = NULL;
	SCHAR		vargch = 0;

	va_start(vp, pcFormat);
	pfmt = pcFormat;

	while (*pfmt)
	{
		if(*pfmt == '%')
		{
			switch(*(++pfmt))
			{
				case 'c':
						vargch = (SCHAR)va_arg(vp, SINT32); 
						/*    va_arg(ap, type), if type is narrow type (SCHAR, short, float) an error is given in strict ANSI
						mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */
						printch(vargch);
						break;

				case 'd':
				case 'i':
						vargint = va_arg(vp, SINT32);
						if(vargint == 0)
							printch((SCHAR)(0 + '0'));
						else
							printdec(vargint);
						break;

#if SUPPORT_FLOAT	// do not support float value
				case 'f':
						vargflt = va_arg(vp, double);
						/*    va_arg(ap, type), if type is narrow type (SCHAR, short, float) an error is given in strict ANSI
						mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */
						printflt(vargflt);
						break;
#endif

				case 's':
						vargpch = va_arg(vp, SCHAR*);
						printstr(vargpch);
						break;

				case 'b':
				case 'B':
						varguint32 = va_arg(vp, UINT32);
						printbin(varguint32);
						break;

				case 'x':
				case 'X':
						varguint32 = va_arg(vp, UINT32);
						
						if (varguint32 == 0)
							printstr("0");
						else
							printhex(varguint32);
						break;

				case '%':
						printch('%');
						break;
				
				default:
						break;
			}

			pfmt++;
		}
		else
		{
			printch(*pfmt++);
		}
	}

	va_end(vp);

	return ret;
}

/**
 * @brief This exported function covnver input signed number into input buffer based on base and return the buffer.
 * @param [in] iVal			signed number want to convert to string
 * @param [in] *pcBuf		buffer contains the convert string
 * @param [in] iBufLen		buffer length
 * @param [in] iBase			base is 16 for hex, 10 for dec, 2 for binary, not support others currently
 * @return Character number show out
*/
SCHAR *kw_itoa(SINT32 iVal, SCHAR *pcBuf, SINT32 iBufLen, SINT32 iBase)
{
	SCHAR *pcTmp = pcBuf;

	/*! if it is negative number, convert to positive number. Negative number only support decimal string */
	if (((iVal < 0) && (iBase != 10)) || (pcTmp == NULL) || (iBufLen <= 0))
	{
		return NULL;
	}

	if (iVal < 0)
	{
		pcTmp[0] = '-';
		iVal *= -1;			// convert to positive number
		iBufLen--;
	}

	pcTmp = kw_uitoa(iVal, (SCHAR *)&pcTmp[1], iBufLen, iBase);

	return pcTmp;
}

/**
 * @brief This exported function covnver input signed number into input buffer based on base and return the buffer.
 * @param [in] iVal			signed number want to convert to string
 * @param [in] *pcBuf		buffer contains the convert string
 * @param [in] iBufLen		buffer length
 * @param [in] iBase			base is 16 for hex, 10 for dec, 2 for binary, not support others currently
 * @return Character number show out
*/
SCHAR *kw_uitoa(SINT32 iVal, SCHAR *pcBuf, SINT32 iBufLen, SINT32 iBase)
{
	return NULL;
}

/**
 * @brief This exported function copy specified length of character from source string start position into dest string.
 *		  The invoker should guarantee sufficient dest string buffer.
 * @param [in] pcDest			Dest string buffer want to copy
 * @param [in] pcSource			Source string
 * @param [in] iCpyLen			Copy length, it is the invoker responsable to guarrant buffer length
 * @param [in] iStarIndex		Source string start index
 * @return Character number show out
*/
SCHAR *kw_strcpy(SCHAR *pcDest, SCHAR *pcSource, SINT32 iCpyLen, SINT32 iStartIndex)
{
	/* check input parameter */
	if (pcDest != NULL && pcSource != NULL && iCpyLen > 0 && iStartIndex >= 0 && iStartIndex < kw_strlen(pcSource))
	{
//		SCHAR	*pcTemp = (SCHAR *)(&pcSource[iStartIndex]);

		while (iCpyLen && *pcDest)
		{
			*pcDest = *pcSource;
			pcDest++;
			pcSource++;
			iCpyLen--;
		}

		*pcDest = 0;
	}

	return pcDest;
}



