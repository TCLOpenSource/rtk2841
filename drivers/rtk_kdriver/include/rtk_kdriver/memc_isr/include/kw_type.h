/**
 * @file kw_type.h
 * @brief This header file defines Real-Image data type and common used macro.
 * @date August.24.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par KW type trace V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifndef _REAL_TYPE_HEADER_
#define _REAL_TYPE_HEADER_


/*! Define data type */
typedef char				SCHAR;				///< signed SCHAR, 8 bits
typedef short				SINT16;				///< define short as SINT16
typedef int					SINT32;				///< define long as SINT32

typedef unsigned char		UBYTE;				///< 8 bits unsigned data
#ifndef UINT16
typedef unsigned short		UINT16;				///< 16 bits unsigned data
#endif
#ifndef UINT32
typedef unsigned int		UINT32;				///< define int as UINT32
#endif
#ifndef BOOL
#ifdef WIN32
typedef int					BOOL;
#else
typedef unsigned char		BOOL;				///< define BOOL as unsigned char 8 bits
#endif
#endif

#ifndef VOID
typedef void				VOID;				///< define VOID
#endif

/*! define null pointer */
/*! c++ NULL define is different with c */
#ifndef NULL
#ifndef __cplusplus
#define NULL				((VOID *)0)
#else
#define NULL				0
#endif /* End of #ifndef __cplusplus */
#endif /* End of #ifndef NULL */

/*! define TRUE */
#ifndef TRUE
#define TRUE				1
#endif/* End of #ifndef TRUE */

/*! define FALSE */
#ifndef FALSE
#define FALSE				0
#endif/* End of #ifndef FALSE */

/*! define BIT0~BIT31 */
#define BIT_0		0x00000001	///< define BIT_0
#define BIT_1 		0x00000002	///< define BIT_1
#define BIT_2 		0x00000004	///< define BIT_2
#define BIT_3 		0x00000008	///< define BIT_3
#define BIT_4 		0x00000010	///< define BIT_4
#define BIT_5 		0x00000020	///< define BIT_5
#define BIT_6 		0x00000040	///< define BIT_6
#define BIT_7 		0x00000080	///< define BIT_7
#define BIT_8 		0x00000100	///< define BIT_8
#define BIT_9 		0x00000200	///< define BIT_9
#define BIT_10 		0x00000400	///< define BIT_10
#define BIT_11 		0x00000800	///< define BIT_11
#define BIT_12 		0x00001000	///< define BIT_12
#define BIT_13 		0x00002000	///< define BIT_13
#define BIT_14 		0x00004000	///< define BIT_14
#define BIT_15 		0x00008000	///< define BIT_15
#define BIT_16 		0x00010000	///< define BIT_16
#define BIT_17 		0x00020000	///< define BIT_17
#define BIT_18 		0x00040000	///< define BIT_18
#define BIT_19 		0x00080000	///< define BIT_19
#define BIT_20 		0x00100000	///< define BIT_20
#define BIT_21 		0x00200000	///< define BIT_21
#define BIT_22 		0x00400000	///< define BIT_22
#define BIT_23 		0x00800000	///< define BIT_23
#define BIT_24 		0x01000000	///< define BIT_24
#define BIT_25 		0x02000000	///< define BIT_25
#define BIT_26 		0x04000000	///< define BIT_26
#define BIT_27 		0x08000000	///< define BIT_27
#define BIT_28 		0x10000000	///< define BIT_28
#define BIT_29 		0x20000000	///< define BIT_29
#define BIT_30 		0x40000000	///< define BIT_30
#define BIT_31 		0x80000000	///< define BIT_31

#endif /* End of #ifndef _REAL_TYPE_HEADER_ */

