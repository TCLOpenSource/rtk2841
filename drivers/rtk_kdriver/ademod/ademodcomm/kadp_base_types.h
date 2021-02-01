
#ifndef __BASE_TYPES_H__
#define __BASE_TYPES_H__
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#ifdef __cplusplus
extern "C" {
#endif


//------------------------------------------
// Definitions of Bits
//------------------------------------------
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


typedef unsigned int                UINT32;	//!< for unsigned integer (32 bits)
typedef int                         INT32;  //!< for signed integer (32 bits)
typedef unsigned short              UINT16; //!< for unsigned short (16 bits)
typedef short                       INT16;  //!< for signed short (16 bits)
typedef unsigned char               UINT8;  //!< for unsigned character (8 bits)
typedef char                        INT8;   //!< for character (8 bits)
typedef float                       FLOAT32;//!< for float point (32 bits)
typedef double                      FLOAT64;//!< for float point (64 bits)


#ifndef BOOL
#define BOOL                        bool
#endif

#ifndef NULL
  #define NULL                      (void *)0
#endif

#define CLEARBITS(a,b)              ((a) &= ~(b))
#define SETBITS(a,b)                ((a) |= (b))
#define ISSET(a,b)                  (((a) & (b))!=0)
#define ISCLEARED(a,b)              (((a) & (b))==0)

#ifdef __cplusplus
}
#endif

#endif  //__BASE_TYPES_H__
