/* ----------------------------------------------------------------------------
 File Name: HdicType.h

 Description:

 Version 1.0 : Created   2012.03.21  Sharp Wang
 				 2.0 ：Modified  2013.03.05  Sharp Wang	 

 ---------------------------------------------------------------------------- */ 
#ifndef __DTMB_DEMOD_REALTEK_H_TYPE_H__
#define __DTMB_DEMOD_REALTEK_H_TYPE_H__
//#ifndef __DTMBTYPE_H__
//#define __DTMBTYPE_H__

typedef int						BOOL;
typedef signed char		INT8;	/**< 8 bits, bit 7 is the signed bit */
typedef signed short	INT16;	/**< 16 bits, bit 15 is the signed bit */
typedef signed int		INT32;	/**< 32 bits, bit 31 is the signed bit */
typedef unsigned char	UINT8;	/**< 8 bits */
typedef unsigned short	UINT16;	/**< 16 bits */
typedef unsigned int	UINT32;	/**< 32 bits */

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

enum
{
	DTMB_NO_ERROR = 0,				/* no error */
	DTMB_OTHER_ERROR					/* other error*/
};

enum
{
	DTMB_TUNER_NORMAL,				/*TunerType, Normal IF*/
	DTMB_TUNER_ZERO_IF				/*TunerType, Zero IF*/
};

enum
{
	DTMB_DTMB_4QAM_NR,				    /*DTMB Mode, 4QAM NR*/
	DTMB_DTMB_4QAM,						/*DTMB Mode, 4QAM*/
	DTMB_DTMB_16QAM,					/*DTMB Mode, 16QAM*/	
	DTMB_DTMB_32QAM,					/*DTMB Mode, 32QAM*/
	DTMB_DTMB_64QAM						/*DTMB Mode, 64QAM*/
};

enum
{
	DTMB_PN_VARIABLE,				    /*变相位*/
	DTMB_PN_FIXED						/*定相位*/
};

enum
{
	DTMB_RATE_04,					/*0.4*/
	DTMB_RATE_06,					/*0.6*/
	DTMB_RATE_08					/*0.8*/
};

enum
{
	DTMB_CARRIER_SINGLE,			/* Single Carrier */
	DTMB_CARRIER_MULTI				/* Multi Carrier */
};

enum{
	DTMB_PN_945,					/*PN945*/
	DTMB_PN_595,					/*PN595*/
	DTMB_PN_420						/*PN420*/
};

enum
{
	DTMB_INTERLEAVER_720,			/* Interleaver 720*/
	DTMB_INTERLEAVER_240			/* Interleaver 240*/
};

enum
{
	DTMB_TS_OUTPUT_PARALLEL,			/* TS parallel output */
	DTMB_TS_OUTPUT_SERIAL				/* TS serial output */
};

enum
{
	DTMB_TS_DATA_SAMPLE_RISING,			/* TS Data should be sampled at the rising edge of TS_CLK */
	DTMB_TS_DATA_SAMPLE_FALLING			/* TS Data should be sampled at the falling edge of TS_CLK */
};

enum
{
	DTMB_TS_CLK_ALWAYS,					/* TS TS_CLK is always on */
	DTMB_TS_CLK_WITH_TSVLD				/* TS TS_CLK is set to 0 when TS_VLD is low */
};

enum
{
	DTMB_TS_NULLPACKET_ENABLED,			/* TS Null packets are enabled.*/
	DTMB_TS_NULLPACKET_DELETED			/* TS Null packets are deleted.*/
};

enum
{
	DTMB_TS_SERIAL_OUTPUT_D7,			/* When TS is serial,TS_D7 is valid.*/
	DTMB_TS_SERIAL_OUTPUT_D0		    /* When TS is serial,TS_D0 is valid*/
};

enum
{
	DTMB_SPECTRUM_NEGATIVE,		        /*Default Spectrum Mode*/
	DTMB_SPECTRUM_POSITIVE
};

enum
{
	DTMB_TS_SERIAL_MSB_TO_LSB,		    /* When TS is serial,MSB to LSB.*/
	DTMB_TS_SERIAL_LSB_TO_MSB		    /* When TS is serial,LSB to MSB*/
};

enum
{
	DTMB_TS_SERIAL_SYNC_BYTE,			/* When TS is serial,SYNC is masked with the first byte.*/
	DTMB_TS_SERIAL_SYNC_BIT		        /* When TS is serial,SYNC is masked with the first Bit*/
};


#endif