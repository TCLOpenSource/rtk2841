#ifndef __TUNER_H__
#define __TUNER_H__

/* #include <Application/AppClass/channeldef.h> */
#include "rtk_tv_fe_types.h"
#include "tv_fe_aux.h"
#include "comm.h"

#define TV_SYSTEM_TYPE_NONE   0x00
#define TV_SYSTEM_TYPE_MN     0x01
#define TV_SYSTEM_TYPE_BGDKIL 0x02
#define TV_SYSTEM_TYPE_ATSC   0x04
#define TV_SYSTEM_TYPE_DVB    0x08
#define TV_SYSTEM_TYPE_ISDBT  0x10


#define MAX_TUNER_ADDR_COUNT   4

enum {
	TV_TUNER_NO_TUNER = 0,
	TV_TUNER_NXP_TDA18275A,
	TV_TUNER_SILICONLABS_SI2178B,
	TV_TUNER_SILICONLABS_SI2151,
	TV_TUNER_RAFAEL_R840,
	TV_TUNER_MAXLINEAR_MXL661,
	TV_TUNER_SONY_SUTRC234,
	TV_TUNER_SONY_SUTZE221,
	TV_TUNER_AV2018,
	DTV_TUNER_NUMBER_MAX,
};


typedef struct sTUNER {
	unsigned short        m_id;                 // tuner id
	unsigned char         m_addr;               // i2c address of this tuner
	unsigned long         m_capability;         // capability of this tuner
	TV_OP_MODE            m_op_mode;
	TV_SYSTEM             m_tv_sys;
	unsigned long         m_freq;


	TUNER_PARAM TunerParam;
	unsigned char DemodParamEn;
	COMM                 *m_pComm;

	int (* Init)(struct sTUNER *tuner);
	int (* Reset)(struct sTUNER *tuner);
	int (* SetTuner)(struct sTUNER *tuner, unsigned long freq, TV_SYSTEM sys);
	int (* SetTunerEx)(struct sTUNER *tuner, unsigned long freq, TV_SYSTEM sys, const TV_SIG_INFO *pSigInfo);

	/*------------------------------------------------------------------
	 * Func : CheckTuner
	 *
	 * Desc : Check if tuner's configuration is exactly the same with specified
	 *        configuration.
	 *
	 * Parm : freq   : Target frequency
	 *        sys    : Target TV System
	 *        pParam : Target Parameters
	 *
	 * Retn : TUNER_CTRL_OK : this configuration is current tuner configuration
	 *        TUNER_CTRL_FAIL : not current tuner configuration
	 *------------------------------------------------------------------*/
	int (* GetParam)(struct sTUNER *tuner, TV_SYSTEM sys, TUNER_PARAM *pParam);
	void (*Destory)(struct sTUNER *tuner);
} TUNER;


void Tuner_Constructors(TUNER* pTunerKernel);
void Tuner_Destructors(TUNER* pDemodKernel);
int Tuner_GetParam(TUNER* pTunerKernel, TV_SYSTEM sys, TUNER_PARAM *pParam);
int Tuner_Init(TUNER* pTunerKernel);
int Tuner_Reset(TUNER* pTunerKernel);
int Tuner_SetTuner(TUNER* pTunerKernel, unsigned long freq, TV_SYSTEM sys);
//int Tuner_SetTunerEx(TUNER* pTunerKernel, unsigned long freq, TV_SYSTEM sys, const TV_SIG_INFO *pSigInfo = NULL);
int Tuner_SetTunerEx(TUNER* pTunerKernel, unsigned long freq, TV_SYSTEM sys, const TV_SIG_INFO *pSigInfo);


//=============================================================
#define TUNER_DBG(fmt, args)             rtd_printk_demod(KERN_DEBUG, "DEMO", "TUNER_DEBUG, " fmt, ##args);
#define TUNER_INFO(fmt, args)            rtd_printk_demod(KERN_INFO, "DEMO", "TUNER_INFO, " fmt, ##args);
#define TUNER_WARNING(fmt, args)            rtd_printk_demod(KERN_WARNING, "DEMO", "TUNER_WARNING, " fmt, ##args);


#endif  //__TUNER_H__
