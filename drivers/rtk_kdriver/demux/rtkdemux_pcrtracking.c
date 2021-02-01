#include <linux/math64.h>
#include <linux/delay.h>
/*#include <asm/io.h>*/
#include "rtkdemux_export.h"
#include "rtkdemux_pcrtracking.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_debug.h"
#include <rbus/pll_reg_reg.h>
//#include <tp/tp_drv_global.h>
//#include <tp/rbusTPReg.h>
#include <linux/freezer.h>
#include "rtkdemux_pcrsync.h"
//#include "../rtkademod/ademodcore/rbusCRTReg.h"

//#define FREERUN_NO_TRACKING

/*pcr tracking sampling*/
static const int SAMPLE_COUNT = 256;
static const long MAX_IGNORE_PCR_COUNT = 32;

/*pcr tracking manager*/
const static int     THREAD_SLEEP_TIME_RUNNING    = 100;
const static int     THREAD_SLEEP_TIME_SUSPENDED = 1000;
const static int     THREAD_SLEEP_TIME_SETTING   = 200;
const static int     UPDATE_PCR_SAMPLING_INTERVAL  = 200*DEMUX_CLOCKS_PER_MS; /* 100ms in 90k */
const static int     UPDATE_PCR_SAMPLING_INITIAL   = 1000*DEMUX_CLOCKS_PER_MS; /* 100ms in 90k */
const static int     UPDATE_PCR_SAMPLING_FINETUNE  = 10000*DEMUX_CLOCKS_PER_MS; /* 100ms in 90k */

/* 0.97*DEFAULT_FREQUENCY to 1.03*DEFAULT_FREQUENCY */
/*
	PLL Frequency = 27*(NCODE +3 + FCODE/2048)
	Frequency set to 432 and the PCR local clock will become 90k. (NCODE=61, FCODE=0, PLLDDS_N=3(input divider is 4))
*/
/*
	The max adjustment of PCR clock :

	max clock rate     (61+3+ (160*16)/2048) - (61 + 3 + 0/2048)      160 * 16
	--------------- = ------------------------------------------- =  ------------ = 0.01953125
	     90K                   (61 + 3 + 0/2048)                      2048 * 64
*/

#define PCRTRACK_PREDEFINED_DEFAULT_NCODE              61
#define PCRTRACK_PREDEFINED_DEFAULT_FCODE 0

#define PCRTRACK_PREDEFINED_DEFAULT_IDX                0
#define PCRTRACK_PREDEFINED_FULL_SPAN                  160

#define PCRTRACK_PREDEFINED_TOP_IDX                    (PCRTRACK_PREDEFINED_DEFAULT_IDX+PCRTRACK_PREDEFINED_FULL_SPAN)
#define PCRTRACK_PREDEFINED_BOTTOM_IDX                 (PCRTRACK_PREDEFINED_DEFAULT_IDX-PCRTRACK_PREDEFINED_FULL_SPAN)

#define PCRTRACK_PREDEFINED_FCODE_STEP_SPAN            16 // if input divider is 1, FCODE_STEP_SPAN is 4
#define PCRTRACK_PREDEFINED_FINETUNE_FCODE_STEP_SPAN   1

#define PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX           ((PCRTRACK_PREDEFINED_DEFAULT_IDX+PCRTRACK_PREDEFINED_FULL_SPAN)*PCRTRACK_PREDEFINED_FCODE_STEP_SPAN)
#define PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX        ((PCRTRACK_PREDEFINED_DEFAULT_IDX-PCRTRACK_PREDEFINED_FULL_SPAN)*PCRTRACK_PREDEFINED_FCODE_STEP_SPAN)

#define PCRTRACK_PREDEFINED_ADJUST_FACTOR              0x20000


/*
	Only use this function in States to prevent from race condition.

	step=1 means get the index of higher speed with 1 step.
	step=-2 means get the index of lower speed with 2 step.
*/
static int PCRTRACK_GetNextSpeedPredefinedArrayIdx(PCRTRK_MANAGER_T *pManager, int step)
{
	int nextIdx = pManager->currentStepIdx + step;
	if(pManager->bIsPreventDistortion == true)
	{
		if (nextIdx >= PCRTRACK_PREDEFINED_DEFAULT_IDX+40)
			nextIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX+40;
		else if (nextIdx < PCRTRACK_PREDEFINED_DEFAULT_IDX-40)
			nextIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX-40;
	}
	else
	{
		if(pManager->audioMaster == false)
		{
			//dmx_notice("[Trans mode: %d] tuningMode(%d), nextIdx(%d), currentStepIdx(%d)\n", __LINE__, pManager->tuningMode, nextIdx, pManager->currentStepIdx);
			if(pManager->switchStepSpan == true)
			{
				if(pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
				{
					/* PCRTRK_TM_NORMAL -> PCRTRK_TM_FINE_TUNE
					 * step is increased 1 in normal mode is equal to step is increased 1*PCRTRACK_PREDEFINED_FCODE_STEP_SPAN in fine tune mode.
					 * we should scale up currentStepIdx.
					 */
					pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX + (pManager->currentStepIdx - PCRTRACK_PREDEFINED_DEFAULT_IDX) * PCRTRACK_PREDEFINED_FCODE_STEP_SPAN;
				}
				else
				{
					/* PCRTRK_TM_FINE_TUNE -> PCRTRK_TM_NORMAL
					 * we should scale down currentStepIdx.
					 */
					pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX + (pManager->currentStepIdx - PCRTRACK_PREDEFINED_DEFAULT_IDX) / PCRTRACK_PREDEFINED_FCODE_STEP_SPAN;
				}
				nextIdx = pManager->currentStepIdx + step;
				pManager->switchStepSpan = false;
			}
		}

		/* tracking range is limited.
		 * Otherwise VODMA will have problem (K3LG-223) at least.
		 */
		if(pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
		{
			if (nextIdx > PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX)
				nextIdx = PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX;
			else if (nextIdx < PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX)
				nextIdx = PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX;
		}
		else
		{
			if (nextIdx > PCRTRACK_PREDEFINED_TOP_IDX)
				nextIdx = PCRTRACK_PREDEFINED_TOP_IDX;
			else if (nextIdx < PCRTRACK_PREDEFINED_BOTTOM_IDX)
				nextIdx = PCRTRACK_PREDEFINED_BOTTOM_IDX;
		}
	}
	return nextIdx;
}

/* pcr tracking sampleing*/
/* This function is in the same thread with StateExecute functions, so it doesn't need MUTEX. */
void PCRTRACK_SMP_Update(PCRTRK_MANAGER_T *pManager)
{
	int64_t interval = 0;
	int i=0;
	if(pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
		interval = UPDATE_PCR_SAMPLING_FINETUNE;
	else if(pManager->tuningMode == PCRTRK_TM_START|| pManager->tuningMode == PCRTRK_TM_INIT)
		interval = UPDATE_PCR_SAMPLING_INITIAL;
	else
		interval = UPDATE_PCR_SAMPLING_INTERVAL;

	if ((CLOCK_GetPTS()-pManager->sampling.updateIntervalTick > interval) || (pManager->sampling.prevRCD != -1 && pManager->RCD == -1))
	{
		pManager->sampling.speed_advice = 0;
		mutex_lock(&pManager->mutex);
		if ((pManager->isAudioMaster != pManager->audioMaster) || (pManager->sampling.prevRCD != -1 && pManager->RCD == -1))
		{
			pManager->audioMaster = pManager->isAudioMaster;
#ifdef FREERUN_NO_TRACKING
			PCRTRACK_SMP_Reset(&pManager->sampling);
			pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
			pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
			PCRTRACK_REG_ResetClock(&pManager->registers);
			pManager->switchStepSpan = false;
			pManager->tuningMode = PCRTRK_TM_INIT;
#else
			if(pManager->audioMaster == false)
			{
				/* free run -> pcr master
				 * we want the transition of tuningMode is INIT -> START -> NORMAL or FINE_TUNE
				*/
				PCRTRACK_SMP_Reset(&pManager->sampling);
				pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
				pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
				PCRTRACK_REG_ResetClock(&pManager->registers);
				pManager->switchStepSpan = false;
				pManager->tuningMode = PCRTRK_TM_INIT;
			}
			else
			{
				/* pcr master -> free run
				 * At free run, we will track audio fullness and the variation is sometimes big relatively.
				 * So track at NORMAL mode.
				 */
				if(pManager->tuningMode != PCRTRK_TM_NORMAL)
				{
					pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
					pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
				}
				pManager->tuningMode = PCRTRK_TM_NORMAL;
			}
#endif
		}
		else if (pManager->audioMaster)
		{
#ifndef FREERUN_NO_TRACKING
			if(pManager->RCD != -1 && pManager->update)
			{
				if (pManager->audioSysPTS != -1 && pManager->audioPTS != -1)
				{
					const int64_t dangerous_lower =  600*DEMUX_CLOCKS_PER_MS;
					const int64_t serious_lower   =  800*DEMUX_CLOCKS_PER_MS;
					const int64_t lower           = 1000*DEMUX_CLOCKS_PER_MS;
					const int64_t upper           = 1200*DEMUX_CLOCKS_PER_MS;
					const int64_t serious_upper   = 1500*DEMUX_CLOCKS_PER_MS;
					const int64_t wraparound = -(5*DEMUX_CLOCKS_PER_SEC);

					int64_t adiff = pManager->audioPTS - pManager->audioSysPTS;
					if (adiff < lower && adiff > wraparound)
					{
						// speed down
						pManager->sampling.speed_advice--;
						if(adiff < serious_lower)
							pManager->sampling.speed_advice--;
						if(adiff < dangerous_lower)
							pManager->sampling.speed_advice -= 2;
					}
					else if(adiff > upper)
					{
						// speed up
						pManager->sampling.speed_advice++;
						if(adiff > serious_upper)
							pManager->sampling.speed_advice++;
					}
				}
				pManager->update = false;
				pManager->sampling.updated = true;
			}
			else
			{
				pManager->sampling.speed_advice = 0;
			}
#endif
		}
		else
		{
			if(pManager->update)
			{
				int64_t pcr = pManager->pcr;
				int64_t stc= pManager->stc;

				/* start to track when
				 * 1. pcr/stc are available ==> pcr > 0
				 * 2. new pcr is available
				 */
				if (stc > 0 && pcr > 0 && stc != pManager->sampling.stc && pcr != pManager->sampling.pcr)
				{
					if (pManager->RCD != -1)
					{
						int64_t pcr_diff = pcr - pManager->sampling.pcr;
						int64_t stc_diff = stc - pManager->sampling.stc;
						int64_t pcr_diff1 = pManager->sampling.pcr - pManager->sampling.lastPcr;
						int64_t stc_diff1 = pManager->sampling.stc - pManager->sampling.lastStc;

						int64_t rcd = pcr - stc;
						int64_t rcd1 = pManager->sampling.pcr - pManager->sampling.stc;
						int64_t rcd2 = pManager->sampling.lastPcr - pManager->sampling.lastStc;

						/* 1. pcr should not decrease ==> pcr diff > 0
						 * 2. system clock should be increase ==> stc diff > 0
						 * 3. don't track at the moment when wrap-around or PMT change ==> rcd diff < 2 second
						 */
						if (pcr_diff > 0 && pcr_diff1 > 0  && stc_diff > 0 && stc_diff1 > 0 && abs(rcd - rcd1) < 2*DEMUX_CLOCKS_PER_SEC && abs(rcd1 - rcd2) < 2*DEMUX_CLOCKS_PER_SEC)
						{
							/* Assume pcr clock is or close to 90K at the beginning.
							 * pcr_diff - stc_diff    New_clk_rate - 90K    (61+3+(F*16)/2048) - (61+3+0/2048)
							 * -------------------- = ------------------- = -----------------------------------
							 *      stc_diff                 90K                      (61+3+0/2048)
							*/
							int64_t preAdjust = div_s64((PCRTRACK_PREDEFINED_ADJUST_FACTOR * (pcr_diff - stc_diff)), (stc_diff * PCRTRACK_PREDEFINED_FCODE_STEP_SPAN));

							//dmx_notice("\033[1;32m[ADJUST] (mode=%d, cur_step=%d, ti=%lld), (pcr_diff=%lld, stc_diff=%lld, preAdjust=%lld)\033[m\n", pManager->tuningMode, pManager->currentStepIdx, interval, pcr_diff, stc_diff, preAdjust);
							if(pManager->tuningMode == PCRTRK_TM_INIT)
							{
								pManager->sampling.speed_advice = (int)preAdjust;
								pManager->tuningMode = PCRTRK_TM_START;
								pManager->sampling.rcdIdx = 0;
								pManager->sampling.baseRCD = 0;
							}
							else
							{
								if(preAdjust > -2 && preAdjust < 2)
								{
									if(pManager->tuningMode != PCRTRK_TM_FINE_TUNE)
									{
										pManager->switchStepSpan = true;
										pManager->tuningMode = PCRTRK_TM_FINE_TUNE;
									}
									if((pManager->sampling.rcdIdx > 0) && (abs(rcd - pManager->sampling.sampleRCD[pManager->sampling.rcdIdx-1]) > 900))
									{
										pManager->sampling.rcdIdx = 0;
										pManager->sampling.baseRCD = 0;
									}
								}
								else
								{
									if(pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
										pManager->switchStepSpan = true;
									pManager->tuningMode = PCRTRK_TM_NORMAL;
								}

								if(pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
								{
									int64_t rcd_diff = rcd - rcd1;
									if(pManager->sampling.rcdIdx < RCD_SAMPLE_NUM)
									{
										pManager->sampling.sampleRCD[pManager->sampling.rcdIdx] = rcd;
										pManager->sampling.rcdIdx++;

										if(pManager->sampling.rcdIdx == RCD_SAMPLE_NUM)
										{
											pManager->sampling.baseRCD = 0;
											for(i=1; i<RCD_SAMPLE_NUM; i++)
												pManager->sampling.baseRCD += pManager->sampling.sampleRCD[i] - pManager->sampling.sampleRCD[0];

											pManager->sampling.baseRCD = div_s64(pManager->sampling.baseRCD, RCD_SAMPLE_NUM) + pManager->sampling.sampleRCD[0];
										}

										if (rcd_diff > 0)
										{
											/* rcd_diff > 0 means pcr increasement is larger than stc increasement,
											 * then speed up clock.
											 */
											pManager->sampling.speed_advice++;
										}
										else if (rcd_diff < 0)
										{
											pManager->sampling.speed_advice--;
										}
									}
									else
									{
										if(rcd_diff > 0 && rcd > pManager->sampling.baseRCD)
										{
											pManager->sampling.speed_advice++;
										}
										else if(rcd_diff < 0 && rcd < pManager->sampling.baseRCD)
										{
											pManager->sampling.speed_advice--;
										}
									}

								}
								else if(pManager->tuningMode == PCRTRK_TM_NORMAL)
								{
									int64_t rcd_diff = rcd - rcd2 + rcd1 - rcd2;
									if (rcd_diff > 0)
									{
										pManager->sampling.speed_advice++;
									}
									else if (rcd_diff < 0)
									{
										pManager->sampling.speed_advice--;
									}
								}
							}
							pManager->update = false;
							pManager->sampling.updated = true;
						}
					}
					if(pManager->sampling.pcr == -1 && pManager->sampling.stc == -1)
					{
						pManager->sampling.lastPcr = pcr;
						pManager->sampling.lastStc = stc;
						pManager->sampling.pcr = pcr;
						pManager->sampling.stc = stc;
					}
					else
					{
						pManager->sampling.lastPcr = pManager->sampling.pcr;
						pManager->sampling.lastStc = pManager->sampling.stc;
						pManager->sampling.pcr = pcr;
						pManager->sampling.stc = stc;
					}
				}
			}
		}
		pManager->sampling.prevRCD = pManager->RCD;
		mutex_unlock(&pManager->mutex);
		pManager->sampling.updateIntervalTick = CLOCK_GetPTS();
	}
	else if (CLOCK_GetPTS() < pManager->sampling.updateIntervalTick)
		pManager->sampling.updateIntervalTick = CLOCK_GetPTS();
}
void PCRTRACK_SMP_Reset(PCRTRK_SAMPLING_T *pSampling)
{
	pSampling->pcr = -1;
	pSampling->stc = -1;
	pSampling->lastPcr = -1;
	pSampling->lastStc = -1;
	pSampling->prevRCD = 0;
	pSampling->speed_advice = 0;
	pSampling->updated = false;

	pSampling->baseRCD = 0;
	pSampling->rcdIdx = 0;
	memset( pSampling->sampleRCD , 0 , sizeof( pSampling->sampleRCD ));
}
/* This function is in the same thread with StateExecute functions, so it doesn't need MUTEX. */
int PCRTRACK_SMP_GetSpeedAdvice(PCRTRK_SAMPLING_T *pSampling, PCRTRK_MANAGER_T *pManager)
{
	int ret = 0;
	if (pSampling->updated)
	{
		if(pManager->bIsPreventDistortion == true)
		{
			if (pSampling->speed_advice > 0)
				ret = 1;
			else if (pSampling->speed_advice < 0)
				ret = -1;
		}
		else
		{
			ret = pSampling->speed_advice;
		}
		pSampling->updated = false;
		pSampling->speed_advice = 0;
	}
	return ret;
}

unsigned int PCRTRACK_REG_GetValue(const unsigned int value, const int startBit, const unsigned int mask)
{
	return (value >> startBit) & mask;
}
void PCRTRACK_REG_SetValue(const unsigned long value, volatile unsigned int *reg, const int startBit, const unsigned int mask)
{
	*reg &= ~(mask << startBit);
	*reg |= ((value & mask) << startBit);
}

bool PCRTRACK_REG_Initialize(PCRTRK_REGISTER_T *pRegister, TPK_PCR_CLK_SRC_T clock_mode)
{
	pRegister->sys_pll_dispa_sd1 = (volatile unsigned int*)GET_MAPPED_RBUS_ADDR(PLL_REG_SYS_PLL_DISPA_SD1_reg);
	pRegister->sys_pll_dispa_sd2 = (volatile unsigned int*)GET_MAPPED_RBUS_ADDR(PLL_REG_SYS_PLL_DISPA_SD2_reg);
	pRegister->sys_dvfs_ddsa     = (volatile unsigned int*)GET_MAPPED_RBUS_ADDR(PLL_REG_SYS_DVFS_DDSA_reg);
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	pRegister->sys_pll_dispb_sd1 = (volatile unsigned int*)GET_MAPPED_RBUS_ADDR(PLL_REG_SYS_PLL_DISPB_SD1_reg);
	pRegister->sys_pll_dispb_sd2 = (volatile unsigned int*)GET_MAPPED_RBUS_ADDR(PLL_REG_SYS_PLL_DISPB_SD2_reg);
	pRegister->sys_dvfs_ddsb     = (volatile unsigned int*)GET_MAPPED_RBUS_ADDR(PLL_REG_SYS_DVFS_DDSB_reg);
#endif

	switch (clock_mode) {
	case TP_PCRA_LOCAL_90KHz:
		pRegister->sys_pll_disp_sd1 = pRegister->sys_pll_dispa_sd1;
		pRegister->sys_pll_disp_sd2 = pRegister->sys_pll_dispa_sd2;
		pRegister->sys_dvfs_dds = pRegister->sys_dvfs_ddsa;
		break;
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	case TP_PCRB_LOCAL_90KHz:
		pRegister->sys_pll_disp_sd1 = pRegister->sys_pll_dispb_sd1;
		pRegister->sys_pll_disp_sd2 = pRegister->sys_pll_dispb_sd2;
		pRegister->sys_dvfs_dds = pRegister->sys_dvfs_ddsb;
		break;
#endif
	default:
		return false;
	}

	return true;
}

/**************************************************************/
/* Register operate                                           */
/**************************************************************/
void PCRTRACK_REG_Set_PLLDDS_N(PCRTRK_REGISTER_T *pRegister, unsigned long value)
{
	PCRTRACK_REG_SetValue(value, pRegister->sys_pll_disp_sd1, 30, 0x3);
}
unsigned long PCRTRACK_REG_Get_PLLDDS_N(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_pll_disp_sd1, 30, 0x3);
}
void PCRTRACK_REG_Set_FCODE(PCRTRK_REGISTER_T *pRegister, unsigned long value)
{
	PCRTRACK_REG_SetValue(value, pRegister->sys_pll_disp_sd2, 16, 0x7FF);
}
unsigned long PCRTRACK_REG_Get_FCODE(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_pll_disp_sd2, 16, 0x7FF);
}
void PCRTRACK_REG_Set_NCODE(PCRTRK_REGISTER_T *pRegister, unsigned long value)
{
	PCRTRACK_REG_SetValue(value, pRegister->sys_pll_disp_sd2, 8, 0xFF);
}
unsigned long PCRTRACK_REG_Get_NCODE(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_pll_disp_sd2, 8, 0xFF);
}

unsigned char PCRTRACK_REG_Get_PLLDDS_OEB(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_pll_disp_sd2, 2, 0x1);
}
void PCRTRACK_REG_Set_PLLDDS_RSTB(PCRTRK_REGISTER_T *pRegister, unsigned char value)
{
	PCRTRACK_REG_SetValue(value, pRegister->sys_pll_disp_sd2, 1, 0x1);
}
unsigned char PCRTRACK_REG_Get_PLLDDS_RSTB(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_pll_disp_sd2, 1, 0x1);
}

unsigned char PCRTRACK_REG_Get_PLLDDS_POW(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_pll_disp_sd2, 0, 0x1);
}
void PCRTRACK_REG_Set_PLLDDS_OC(PCRTRK_REGISTER_T *pRegister, unsigned char value)
{
	PCRTRACK_REG_SetValue(value, pRegister->sys_dvfs_dds, 0, 0x1);
}
bool PCRTRACK_REG_Get_PLLDDS_OC(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_dvfs_dds, 0, 0x1);
}
bool PCRTRACK_REG_Get_PLLDDS_OC_DONE(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_dvfs_dds, 1, 0x1);
}

bool PCRTRACK_REG_Get_PLLDDS_SDM_ORDER(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_dvfs_ddsa, 2, 0x1);
}

bool PCRTRACK_REG_Get_PLLDDS_OC_STEP(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_dvfs_dds, 4, 0x3FF);
}

bool PCRTRACK_REG_Get_PLLDDS_OC_MODE(PCRTRK_REGISTER_T *pRegister)
{
	return PCRTRACK_REG_GetValue(*pRegister->sys_dvfs_dds, 24, 0x3);
}

void PCRTRACK_REG_ResetClock(PCRTRK_REGISTER_T *pRegister)
{
	PCRTRACK_REG_Set_PLLDDS_OC(pRegister, 0);
	PCRTRACK_REG_Set_FCODE(pRegister, PCRTRACK_PREDEFINED_DEFAULT_FCODE);
	PCRTRACK_REG_Set_NCODE(pRegister, PCRTRACK_PREDEFINED_DEFAULT_NCODE);
	PCRTRACK_REG_Set_PLLDDS_OC(pRegister, 1);
}
/* pcr tracking manager*/
int PCRTRACK_ThreadProcEntry(void *pParam);
void PCRTRACK_Initialize(PCRTRK_MANAGER_T *pManager, unsigned char tunerHandle)
{
	dmx_notice("[PT] PCR Tracking Manager Initializing...\n");

	PCRTRACK_REG_Initialize(&pManager->registers, PCRTRACK_ChoosePCRClock(tunerHandle));
	PCRTRACK_SMP_Reset(&pManager->sampling);
	PCRTRACK_REG_ResetClock(&pManager->registers);

	pManager->cc = 0;
	pManager->state = PCRTRK_SUSPEND;
	pManager->prevRatioCounter = 0;
	pManager->tunerHandle = tunerHandle;
	pManager->nextTunerHandle = tunerHandle;
	pManager->bIsSuspending = true;
	pManager->bIsTerminating = false;
	pManager->bInitialized = true;
	pManager->bIsPreventDistortion = false;
	pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
	pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
	pManager->isFreeRunMode = 0;
	pManager->audioMaster = false;
	pManager->isAudioMaster = false;
	pManager->switchStepSpan = false;
	pManager->tuningMode = PCRTRK_TM_INIT;
	pManager->update = false;
	pManager->pcr = -1;
	pManager->stc = -1;
	pManager->RCD = -1 ;
	pManager->videoPTS = -1 ;
	pManager->audioPTS = -1 ;
	pManager->videoSysPTS = -1;
	pManager->audioSysPTS = -1;
	init_waitqueue_head(&pManager->resumeWQ);
	mutex_init(&pManager->mutex);
	pManager->pThread = kthread_create(PCRTRACK_ThreadProcEntry, (void *)pManager, "PCRTRACK") ;

	wake_up_process(pManager->pThread);
}
void PCRTRACK_Release(PCRTRK_MANAGER_T *pManager)
{
	/*PCR tracking manager isn't initialized yet.*/
	if (!pManager->bInitialized)
		return;

	pManager->bIsTerminating = true;
	if (pManager->pThread)
		kthread_stop(pManager->pThread);
	PCRTRACK_REG_ResetClock(&pManager->registers);

	pManager->cc = 0;
	pManager->state = PCRTRK_SUSPEND;
	pManager->prevRatioCounter = 0;
	pManager->tunerHandle = 0;
	pManager->nextTunerHandle = 0;
	pManager->bIsSuspending = true;
	pManager->bIsTerminating = false;
	pManager->bInitialized = false;
	pManager->bIsPreventDistortion = false;
	pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
	pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
	pManager->isFreeRunMode = 0;
	pManager->audioMaster = false;
	pManager->isAudioMaster = false;
	pManager->switchStepSpan = false;
	pManager->tuningMode = PCRTRK_TM_INIT;
	pManager->update = false;
	pManager->RCD = -1 ;
	pManager->pcr = -1;
	pManager->stc = -1;
	pManager->videoPTS = -1 ;
	pManager->audioPTS = -1 ;
	pManager->videoSysPTS = -1;
	pManager->audioSysPTS = -1;
	mutex_destroy(&pManager->mutex);

	dmx_notice("[PT] PCR Tracking Manager UnInitialized...\n");
}
bool PCRTRACK_Start(PCRTRK_MANAGER_T *pManager, unsigned char tunerHandle)
{
	bool result = false;
	if (pManager->bIsSuspending) {
		mutex_lock(&pManager->mutex);
		if (pManager->bIsSuspending && pManager->state == PCRTRK_SUSPEND) {
			pManager->bIsSuspending = false;
			result = true;
			pManager->nextTunerHandle = tunerHandle;
			wake_up(&pManager->resumeWQ);
		}
		mutex_unlock(&pManager->mutex);
	}
	else{
		dmx_mask_print(DEMUX_PCRTRACK_DEBUG, "start pctrakcing....status not change\n")
		result = true;
	}
	return result;
}
void PCRTRACK_Stop(PCRTRK_MANAGER_T *pManager)
{
	mutex_lock(&pManager->mutex);
	pManager->bIsSuspending = true;
	mutex_unlock(&pManager->mutex);
}
void PCRTRACK_Smooth(PCRTRK_MANAGER_T *pManager)
{
	//mutex_lock(&pManager->mutex);
	//pManager->bIsPreventDistortion = true;
	//mutex_unlock(&pManager->mutex);
}

/**************************************************************/
/* State                                                      */
/**************************************************************/
void PCRTRACK_SuspendStateExecute(PCRTRK_MANAGER_T *pManager)
{
	//msleep(THREAD_SLEEP_TIME_SUSPENDED);
	wait_event_timeout(pManager->resumeWQ, (pManager->bIsSuspending == false), msecs_to_jiffies(THREAD_SLEEP_TIME_SUSPENDED));
	if (pManager->bIsSuspending == false) {
		mutex_lock(&pManager->mutex);
		if (pManager->bIsSuspending == false) {
			pManager->tunerHandle = pManager->nextTunerHandle;
			pManager->state = PCRTRK_READY;
			dmx_mask_print(DEMUX_PCRTRACK_DEBUG|DEMUX_NOTICE_PRINT, "PCRTRACKING   start RUNNING!!!!!\n")
		}
		mutex_unlock(&pManager->mutex);
	}
}
void PCRTRACK_ReadyStateExecute(PCRTRK_MANAGER_T *pManager)
{
	mutex_lock(&pManager->mutex);
	if (pManager->bIsSuspending == true) {
			pManager->state = PCRTRK_SUSPEND;
		PCRTRACK_SMP_Reset(&pManager->sampling);

		pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
		pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
		pManager->switchStepSpan = false;
		pManager->tuningMode = PCRTRK_TM_INIT;
		PCRTRACK_REG_ResetClock(&pManager->registers);
		dmx_mask_print(DEMUX_PCRTRACK_DEBUG|DEMUX_NOTICE_PRINT, "PCRTRACKING  be SUSPEND!!!!!.\n")
	} else {
		pManager->state = PCRTRK_DETERMINE;
	}
	mutex_unlock(&pManager->mutex);
}
void PCRTRACK_DetermineStateExecute(PCRTRK_MANAGER_T *pManager)
{
	PCRTRK_SAMPLING_T *pSampling = &(pManager->sampling);
	int next = PCRTRACK_SMP_GetSpeedAdvice(pSampling, pManager);

	if (pManager->bIsSuspending) {
		pManager->state = PCRTRK_READY;
	} else {
		pManager->nextStepIdx = PCRTRACK_GetNextSpeedPredefinedArrayIdx(pManager, next);
		pManager->state = PCRTRK_SET_CLOCK;
	}
}
void PCRTRACK_SetClockExecute(PCRTRK_MANAGER_T *pManager)
{
	if (pManager->nextStepIdx != pManager->currentStepIdx) {
		unsigned long defaultN = 0, defaultF = 0, fcode = 0, ncode = 0, tmp_fcode = 0;
		unsigned long quotient = 0, remainder = 0;
		int fcode_step = 0;

		defaultN = PCRTRACK_PREDEFINED_DEFAULT_NCODE;
		defaultF = PCRTRACK_PREDEFINED_DEFAULT_FCODE;
		if(pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
		{
			fcode_step = PCRTRACK_PREDEFINED_FINETUNE_FCODE_STEP_SPAN;
}
		else
		{
			fcode_step = PCRTRACK_PREDEFINED_FCODE_STEP_SPAN;
		}

		if (pManager->nextStepIdx < PCRTRACK_PREDEFINED_DEFAULT_IDX)
		{
			tmp_fcode = fcode_step*(PCRTRACK_PREDEFINED_DEFAULT_IDX - pManager->nextStepIdx);
			quotient = tmp_fcode / 0x800;
			remainder = tmp_fcode % 0x800;

			ncode = defaultN - quotient -1;
			fcode = 0x800 - remainder;
		}
		else if (pManager->nextStepIdx > PCRTRACK_PREDEFINED_DEFAULT_IDX)
		{
			tmp_fcode = fcode_step*(pManager->nextStepIdx - PCRTRACK_PREDEFINED_DEFAULT_IDX);
			quotient = tmp_fcode / 0x800;
			remainder = tmp_fcode % 0x800;

			ncode = defaultN + quotient;
			fcode = remainder;
		}
		else
		{
			ncode = defaultN;
			fcode = defaultF;
		}
		PCRTRACK_REG_Set_PLLDDS_OC(&pManager->registers, 0);
		PCRTRACK_REG_Set_FCODE(&pManager->registers, fcode);
		PCRTRACK_REG_Set_NCODE(&pManager->registers, ncode);
		PCRTRACK_REG_Set_PLLDDS_OC(&pManager->registers, 1);
	}

	pManager->currentStepIdx = pManager->nextStepIdx;
	pManager->state = PCRTRK_WAIT_SAMPLE;
}
void PCRTRACK_WaitForSampleUpdatedStateExecute(PCRTRK_MANAGER_T *pManager)
{
	/* To prevent entering the TrackState with the same frequency ratio. It will cause frequency became larger or smaller continuously.*/
	/* context->m_isSuspending is because when suspending, Sampling module might be unable to update ratio counter, and cause stucking in wait state.*/
	if (pManager->sampling.updated || pManager->bIsSuspending) {
		pManager->state = PCRTRK_READY;
	} else {
		msleep(THREAD_SLEEP_TIME_RUNNING);
	}
}

int PCRTRACK_ThreadProcEntry(void *pParam)
{
	int64_t lastPTS = -1;
	int64_t currentPTS = -1;
	PCRTRK_MANAGER_T *pManager = (PCRTRK_MANAGER_T *)pParam;
	while (pManager->bIsTerminating == false) {
		set_freezable();
		pManager->cc++;

		if (!pManager->bIsSuspending)
			PCRTRACK_SMP_Update(pManager);
		currentPTS = CLOCK_GetPTS();
		if (!pManager->bIsSuspending && pManager->state != PCRTRK_SUSPEND && currentPTS-lastPTS > 3*DEMUX_CLOCKS_PER_SEC) {
			dmx_mask_print(DEMUX_PCRTRACK_DEBUG,"\033[1;32m[PT]CH%d: cc=%lld,cur_step=%d,sus=%d,mode=(%d, %d, %d) (adiff %lld, vdiff %lld)\033[m\n",
					pManager->tunerHandle, pManager->cc, pManager->currentStepIdx,
					pManager->bIsSuspending,
					pManager->isFreeRunMode,
					pManager->audioMaster,
					(int)(pManager->tuningMode),
					pManager->audioPTS - pManager->audioSysPTS,
					pManager->videoPTS - pManager->videoSysPTS);
			lastPTS = currentPTS;
		}
		else if (currentPTS < lastPTS) lastPTS = currentPTS;

		switch (pManager->state) {
		case PCRTRK_SUSPEND:
			PCRTRACK_SuspendStateExecute(pManager);
			break;
		case PCRTRK_READY:
			PCRTRACK_ReadyStateExecute(pManager);
			break;
		case PCRTRK_DETERMINE:
			PCRTRACK_DetermineStateExecute(pManager);
			break;
		case PCRTRK_WAIT_SAMPLE:
			PCRTRACK_WaitForSampleUpdatedStateExecute(pManager);
			break;
		case PCRTRK_SET_CLOCK:
			PCRTRACK_SetClockExecute(pManager);
			break;
		}
	}
	return 1;
}
void PCRTRACK_UpdatePosition(PCRTRK_MANAGER_T *pManager, DEMUX_PCRSYNC_T *pPcrProcesser, AV_SYNC_MODE avSyncMode)
{
	/*check if A/V display the last frame and we have to continue to update RCD*/
	if( pManager != NULL && pPcrProcesser != NULL && pManager->pThread != NULL)
	{
		PRESENTATION_POSITIONS position;
		REFCLK_GetPresentationPositions(pPcrProcesser->pRefClock, &position);

		pPcrProcesser->lastAudioSystemPTS = position.audioSystemPTS;
		pPcrProcesser->lastVideoSystemPTS = position.videoSystemPTS;

		mutex_lock(&pManager->mutex);
		pManager->isFreeRunMode = PCRSYNC_IsUnderFreeRunMode(pPcrProcesser);
		pManager->isAudioMaster = (avSyncMode != NAV_AVSYNC_PCR_MASTER);
		pManager->pcr = pPcrProcesser->pcr;
	  	pManager->stc = pPcrProcesser->stc;
		pManager->RCD         = pPcrProcesser->rcd;
		pManager->videoPTS    = pPcrProcesser->lastDemuxVideoPTS;
		pManager->audioPTS    = pPcrProcesser->lastDemuxAudioPTS;
		pManager->videoSysPTS = pPcrProcesser->lastVideoSystemPTS;
		pManager->audioSysPTS = pPcrProcesser->lastAudioSystemPTS;
		pManager->update = true ;
		mutex_unlock(&pManager->mutex);
	}
}
long PCRTRACK_ChoosePCRClock (unsigned char tunerHandle)
{
	switch (tunerHandle) {
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	case 0:
		return TP_PCRA_LOCAL_90KHz;
	case 1:
		return TP_PCRB_LOCAL_90KHz;
#endif
	default:
		return TP_PCR_LOCAL_90KHz;
	}
}

