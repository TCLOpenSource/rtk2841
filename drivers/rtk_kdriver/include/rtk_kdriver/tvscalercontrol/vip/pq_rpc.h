#ifndef __PQ_RPC_H__
#define __PQ_RPC_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SINT8
typedef	signed char				__SINT8;
#define SINT8 __SINT8
#endif

#ifndef UINT8
typedef	unsigned char				__UINT8;
#define UINT8 __UINT8
#endif


#ifndef SINT16
typedef	signed short			__SINT16;
#define SINT16 __SINT16
#endif

#ifndef UINT16
typedef	unsigned short			__UINT16;
#define UINT16 __UINT16
#endif


#ifndef SINT32
typedef	signed int			__SINT32;
#define SINT32 __SINT32
#endif

#ifndef UINT32
typedef	unsigned int			__UINT32;
#define UINT32 __UINT32
#endif


#if CONFIG_FIRMWARE_IN_KERNEL
#else
#ifndef BOOLEAN
typedef	unsigned int			__BOOLEAN;
#define BOOLEAN __BOOLEAN
#endif
#endif

typedef struct _FILM_FWMode
{
	UINT8 fw_StatusFilmSequence;
	UINT8 fw_Status32Detected1;
	UINT8 fw_Status32Detected2;
	UINT8 fw_Status22Detected;
	UINT8 Fw_StatusFilmWeaveMode;
	UINT8 Fw_MixedFilmConfuse;
	UINT8 Fw_StatusMixedFilmDetected;
	UINT8 Fw_StatusFilmDetected;
	UINT32 Fw_TopLine1;
	UINT32 Fw_BotLine1;
	UINT32 Fw_TopLine2;
	UINT32 Fw_BotLine2;
	UINT32 Fw_TopLine3;
	UINT32 Fw_BotLine3;

}FILM_FWMode;

#define FILM22 1
#define FILM32 2
#define FILM3223 4
#define FILM64 8
#define FILM55 16
#define FILM2224 32
#define FILM32322 64
#define FILM87 128

void scalerVIP_film_FWmode(void);
FILM_FWMode DETECTION_scalerVIP_film_FWmode(void);
void APPLY_scalerVIP_film_FWmode(FILM_FWMode DetInformation);
void	scalerVIP_film_FWmode_detection1(unsigned int FrameStaticPattern,unsigned int FramePairPattern,
		unsigned int PrevStaticPattern, unsigned int NextStaticPattern, unsigned char Strict,
		unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,unsigned int *count_still,
		unsigned char *p32Detected1, unsigned int *p32Sequence1,unsigned char film_Pair_en_auto,
		unsigned char film_Pair1_en,unsigned char film_HiFreq_flag,unsigned char film_Violate_strict_en);

void scalerVIP_film_FWmode_detection2(unsigned int NextStaticPattern, unsigned char Strict,
								unsigned int FrameStaticPattern,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index,
								unsigned char *p32Detected2, unsigned int *p32Sequence2,unsigned char film_Violate_strict_en);

void	scalerVIP_film_FWmode_detection22(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence,unsigned char film_Violate_strict_en);

void	scalerVIP_film_FWmode_detection22new(	unsigned int NextStaticPattern, unsigned char Strict,
								unsigned char PrevFieldMotion, unsigned char NextFieldMotion,
							    unsigned char *ExactMatch, unsigned char *Violate, unsigned int *film_index, unsigned int *count_still22,
								unsigned char *p22Detected, unsigned int *p22Sequence);

void scalerVIP_film_FWmode_film32_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum);
void scalerVIP_film_FWmode_film22_debounce(unsigned char *Detected_flag, unsigned int *Detected_cnt,unsigned char FieldNum);


#ifdef __cplusplus
}
#endif

#endif /* __PQ_RPC_H__*/


