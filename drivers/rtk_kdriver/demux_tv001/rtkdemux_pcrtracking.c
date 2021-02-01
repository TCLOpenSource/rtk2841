#include <linux/math64.h>
#include <linux/delay.h>
#include "rtkdemux_export.h"
#include "rtkdemux_pcrtracking.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_debug.h"
#include <rbus/pll_reg_reg.h>
#include <linux/freezer.h>
#include "rtkdemux_pcrsync.h"


/*pcr tracking manager*/
#define BEGIN_SLEEP_LOOP_COUNT          200
#define RUNNING_SLEEP_LOOP_COUNT        100
#define FINETUNE_SLEEP_LOOP_COUNT       1000
#define TUNING_SLEEP_WAIT_DURATION      10 // 1ms is too short to sleep precisely






/* 0.97*DEFAULT_FREQUENCY to 1.03*DEFAULT_FREQUENCY */
/*	PLL Frequency = 27*(NCODE +3 + FCODE/2048)
*	Frequency set to 432 and the PCR local clock will become 90k.
*	Input : (NCODE=13, FCODE=0, PLLDDS_N=0(input divider is 1)), Output value: 432 , 432/1=432
*	Input : (NCODE=61, FCODE=0, PLLDDS_N=3(input divider is 4)), Output value : 1728 , 1728/4=432
*/
/*	The max adjustment of PCR clock :
*
*	max clock rate     (61+3+ (160*16)/2048) - (61 + 3 + 0/2048)      160 * 16
*	--------------- = ------------------------------------------- =  ------------ = 0.01953125
*		90K                   (61 + 3 + 0/2048)                      2048 * 64
*/


/*
   For the projects which use VO overscan
   The value of FULL_SPAN depends on VO which will close VO gatting when the clock(PCRA or PCRB) is too quick
   We adjust the limit of FULL_SPAN as : 192
   The max adjustment range of PCR clock is 192*16/2048/64 = 0.0234375
   160*16/2048/64 = 0.01953125
   128*16/2048/64 = 0.015625
   //This is experimental data.//
*/

#define PCRTRACK_PREDEFINED_DEFAULT_NCODE              61
#define PCRTRACK_PREDEFINED_DEFAULT_FCODE              0

#define PCRTRACK_PREDEFINED_DEFAULT_IDX                0
#define PCRTRACK_PREDEFINED_FULL_SPAN                  50//192 // 320 // 256

#define PCRTRACK_PREDEFINED_TOP_IDX                    (PCRTRACK_PREDEFINED_DEFAULT_IDX+PCRTRACK_PREDEFINED_FULL_SPAN)
#define PCRTRACK_PREDEFINED_BOTTOM_IDX                 (PCRTRACK_PREDEFINED_DEFAULT_IDX-PCRTRACK_PREDEFINED_FULL_SPAN)

#define PCRTRACK_PREDEFINED_FCODE_STEP_SPAN            16 /* if input divider is 1, FCODE_STEP_SPAN is 4 */
#define PCRTRACK_PREDEFINED_FINETUNE_FCODE_STEP_SPAN   1

#define PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX           ((PCRTRACK_PREDEFINED_DEFAULT_IDX+PCRTRACK_PREDEFINED_FULL_SPAN)*PCRTRACK_PREDEFINED_FCODE_STEP_SPAN)
#define PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX        ((PCRTRACK_PREDEFINED_DEFAULT_IDX-PCRTRACK_PREDEFINED_FULL_SPAN)*PCRTRACK_PREDEFINED_FCODE_STEP_SPAN)

#define PCRTRACK_PREDEFINED_FINETUNE_MULTIPLE          PCRTRACK_PREDEFINED_FCODE_STEP_SPAN

#define PCRTRACK_PREDEFINED_ADJUST_FACTOR              0x20000
#define PCRTRACK_PLLBUS_FCODE_DIVISOR                  0x800

#define PCRTRACK_PREDEFINED_EDGE_SPAN                  10 // 30

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

/**************************************************************/
/* State                                                      */
/**************************************************************/
void PCRTRACK_SuspendStateExecute(PCRTRK_MANAGER_T *pManager)
{
	/*msleep(THREAD_SLEEP_TIME_SUSPENDED);*/
	wait_event_freezable_timeout(pManager->resumeWQ,  ((pManager->bIsSuspending==false) ||(pManager->bIsTerminating == true)), msecs_to_jiffies(TUNING_SLEEP_WAIT_DURATION));
	mutex_lock(&pManager->mutex);
	if (pManager->bIsSuspending == false) {
		pManager->state = PCRTRK_READY;
		dmx_mask_print(DEMUX_PCRTRACK_DEBUG|DEMUX_NOTICE_PRINT, "PCRTRACKING   start RUNNING!!!!!\n")
	}
	mutex_unlock(&pManager->mutex);
}

void PCRTRACK_ReadyStateExecute(PCRTRK_MANAGER_T *pManager)
{
	int ii = 0;

	mutex_lock(&pManager->mutex);
	if (pManager->bIsSuspending == true) {
		pManager->state = PCRTRK_SUSPEND;
		PCRTRACK_SMP_Reset(&pManager->sampling);
		pManager->switchStepSpan = false;
		pManager->tuningMode = PCRTRK_TM_INIT;
		pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
		pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
		PCRTRACK_REG_ResetClock(&pManager->registers);
		pManager->extremeStep = 0;
		pManager->extremeStepCountDown = 0;
		pManager->trendCountDown = TRACKING_TREND_NUM;
		for(ii=0; ii<TRACKING_TREND_NUM; ii++)
		{
			pManager->lastTrackingTrend[ii] = 0;
		}
		dmx_mask_print(DEMUX_PCRTRACK_DEBUG|DEMUX_NOTICE_PRINT, "PCRTRACKING  be SUSPEND!!!!!.\n")
	} else {
		pManager->state = PCRTRK_SAMPLING;
	}
	mutex_unlock(&pManager->mutex);
}

void PCRTRACK_SMP_Reset(PCRTRK_SAMPLING_T *pSampling)
{
	pSampling->pcr = -1;
	pSampling->stc = -1;
	pSampling->lastPcr = -1;
	pSampling->lastStc = -1;
	pSampling->prevRCD = 0;
	pSampling->speed_advice = 0;

	pSampling->baseRCD = 0;
	pSampling->rcdIdx = 0;
	memset(pSampling->sampleRCD, 0, sizeof(pSampling->sampleRCD));
}

int PCRTRACK_SMP_UpdateSpeedAdvice(PCRTRK_SAMPLING_T *pSampling, int trkMode, int64_t aDiff, int64_t vDiff)
{
	#define lower              81000   // 900ms
	#define seriousD_lower     72000   // 800ms
	#define seriousC_lower     63000   // 700ms
	#define seriousB_lower     54000   // 600ms
	#define seriousA_lower     45000   // 500ms
	#define dangerousD_lower   36000   // 400ms
	#define dangerousC_lower   27000   // 300ms
	#define dangerousB_lower   18000   // 200ms
	#define dangerousA_lower    9000   // 100ms
	
	#define upper              99000   // 1100ms
	#define seriousD_upper    108000   // 1200ms
	#define seriousC_upper    117000   // 1300ms
	#define seriousB_upper    126000   // 1400ms
	#define seriousA_upper    135000   // 1500ms
	#define dangerousD_upper  144000   // 1600ms
	#define dangerousC_upper  153000   // 1700ms
	#define dangerousB_upper  162000   // 1800ms
	#define dangerousA_upper  171000   // 1900ms

	int speed_advice = 0;
	int64_t masterDiff = 0, slaveDiff = 0;
	int64_t masterLastDiff = 0, slaveLastDiff = 0;
	if (trkMode == ABUFFER_TRACKING) {
		masterDiff = aDiff;
		slaveDiff = vDiff;
		masterLastDiff = pSampling->audioDiff;
		slaveLastDiff = pSampling->videoDiff;
	} else if (trkMode == VBUFFER_TRACKING) {
		masterDiff = vDiff;
		slaveDiff = aDiff;
		masterLastDiff = pSampling->videoDiff;
		slaveLastDiff = pSampling->audioDiff;
	}
	else return speed_advice;

	if (masterDiff < lower && masterDiff >= 0) {
		// speed down
		speed_advice -= 1;
		if (masterDiff < masterLastDiff) {
			speed_advice -= 1;
			if (masterDiff < seriousD_lower)
				speed_advice -= 1;
			if (masterDiff < seriousC_lower)
				speed_advice -= 1;
			if (masterDiff < seriousB_lower)
				speed_advice -= 1;
			if (masterDiff < seriousA_lower)
				speed_advice -= 1;
			if (masterDiff < dangerousD_lower)
				speed_advice -= 2;
			if (masterDiff < dangerousC_lower)
				speed_advice -= 2;
			if (masterDiff < dangerousB_lower)
				speed_advice -= 2;
			if (masterDiff < dangerousA_lower)
				speed_advice -= 2;
		} else {
			if (masterDiff > seriousA_lower)
				speed_advice += 1;
		}
	} else if(masterDiff > upper) {
		// speed up
		speed_advice += 1;
		if (masterDiff > masterLastDiff) {
			speed_advice += 1;
			if (masterDiff > seriousD_upper)
				speed_advice += 1;
			if (masterDiff > seriousC_upper)
				speed_advice += 1;
			if (masterDiff > seriousB_upper)
				speed_advice += 1;
			if (masterDiff > seriousA_upper)
				speed_advice += 1;
			if (masterDiff > dangerousD_upper)
				speed_advice += 2;
			if (masterDiff > dangerousC_upper)
				speed_advice += 2;
			if (masterDiff > dangerousB_upper)
				speed_advice += 2;
			if (masterDiff > dangerousA_upper)
				speed_advice += 2;
		} else {
			if (masterDiff < seriousA_upper)
				speed_advice -= 1;
		}
	}

	return speed_advice;
}

void PCRTRACK_SamplingStateExecute(PCRTRK_MANAGER_T *pManager)
{
	int ii=0;
	bool bUpdated = false;
	int speedAdjust = 0;

	mutex_lock(&pManager->mutex);
	if ((pManager->isTrackingMode != pManager->trackingMode) || ((pManager->sampling.prevRCD == -1) ^ (pManager->RCD == -1)))
	{
		pManager->trackingMode = pManager->isTrackingMode;
		if(pManager->trackingMode == PCR_TRACKING || pManager->trackingMode == NO_TRACKING)
		{
			PCRTRACK_SMP_Reset(&pManager->sampling);
			pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
			pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
			PCRTRACK_REG_ResetClock(&pManager->registers);
			pManager->switchStepSpan = false;
			pManager->tuningMode = PCRTRK_TM_INIT;
			pManager->extremeStep = 0;
			pManager->extremeStepCountDown = 0;
			pManager->trendCountDown = TRACKING_TREND_NUM;
			for(ii=0; ii<TRACKING_TREND_NUM; ii++)
			{
				pManager->lastTrackingTrend[ii] = 0;
			}
		}
		else
		{
			if(pManager->tuningMode != PCRTRK_TM_NORMAL)
			{
				pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
				pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
				pManager->tuningMode = PCRTRK_TM_NORMAL;
			}
		}
	}
	else if (pManager->trackingMode == ABUFFER_TRACKING)
	{
		if(pManager->RCD != -1 && pManager->infoUpdated)
		{
			int64_t adiff = -1, vdiff = -1;
			if(pManager->videoSysPTS != -1 && pManager->videoPTS != -1)
				vdiff = pManager->videoPTS - pManager->videoSysPTS;
			
			if(pManager->audioSysPTS != -1 && pManager->audioPTS != -1)
			{
				adiff = pManager->audioPTS - pManager->audioSysPTS;
			
				speedAdjust = PCRTRACK_SMP_UpdateSpeedAdvice(&pManager->sampling, pManager->trackingMode, adiff, vdiff);
			
				if((speedAdjust < 0 && pManager->currentStepIdx > PCRTRACK_PREDEFINED_DEFAULT_IDX)
				  || (speedAdjust > 0 && pManager->currentStepIdx < PCRTRACK_PREDEFINED_DEFAULT_IDX))
					speedAdjust *= 2;
			
				bUpdated = true;
				pManager->sampling.audioDiff = adiff;
			}
			pManager->sampling.videoDiff = vdiff;
			pManager->infoUpdated = false;
		}
	}
	else if (pManager->trackingMode == VBUFFER_TRACKING)
	{
		if(pManager->RCD != -1 && pManager->infoUpdated)
		{
			int64_t adiff = -1, vdiff = -1;
			if(pManager->audioSysPTS != -1 && pManager->audioPTS != -1)
				adiff = pManager->audioPTS - pManager->audioSysPTS;
			
			if (pManager->videoSysPTS != -1 && pManager->videoPTS != -1)
			{
				vdiff = pManager->videoPTS - pManager->videoSysPTS;
			
				speedAdjust = PCRTRACK_SMP_UpdateSpeedAdvice(&pManager->sampling, pManager->trackingMode, adiff, vdiff);
			
				if((speedAdjust < 0 && pManager->currentStepIdx > PCRTRACK_PREDEFINED_DEFAULT_IDX)
				  || (speedAdjust > 0 && pManager->currentStepIdx < PCRTRACK_PREDEFINED_DEFAULT_IDX))
					speedAdjust *= 2;
			
				bUpdated = true;
				pManager->sampling.videoDiff = vdiff;
			}
			pManager->sampling.audioDiff = adiff;
			pManager->infoUpdated = false;
		}
	}
	else
	{
		if(pManager->infoUpdated)
		{
			if(pManager->nextSTC> 0 && pManager->nextPCR > 0 && pManager->nextSTC != pManager->sampling.stc && pManager->nextPCR != pManager->sampling.pcr)
			{
				if (pManager->RCD != -1 && pManager->sampling.pcr != -1 && pManager->sampling.stc != -1)
				{
					int64_t pcr_diff = pManager->nextPCR - pManager->sampling.pcr;
					int64_t stc_diff = pManager->nextSTC - pManager->sampling.stc;
					int64_t pcr_diff1 = pManager->sampling.pcr - pManager->sampling.lastPcr;
					int64_t stc_diff1 = pManager->sampling.stc - pManager->sampling.lastStc;

					int64_t rcd = pManager->nextPCR - pManager->nextSTC;
					int64_t rcd1 = pManager->sampling.pcr - pManager->sampling.stc;
					int64_t rcd2 = pManager->sampling.lastPcr - pManager->sampling.lastStc;

					if (pcr_diff > 0 && pcr_diff1 > 0  && stc_diff > 0 && stc_diff1 > 0 && abs(rcd - rcd1) < DEMUX_CLOCKS_PER_SEC && abs(rcd1 - rcd2) < DEMUX_CLOCKS_PER_SEC)
					{
						int64_t preAdjust = div_s64((PCRTRACK_PREDEFINED_ADJUST_FACTOR * (pcr_diff - stc_diff)), (stc_diff * PCRTRACK_PREDEFINED_FCODE_STEP_SPAN));

						//dmx_notice("\033[1;32m[ADJUST] (mode=%d, cur_step=%d, ti=%lld), (pcr_diff=%lld, stc_diff=%lld, preAdjust=%lld)\033[m\n", pManager->tuningMode, pManager->currentStepIdx, interval, pcr_diff, stc_diff, preAdjust);
						if(pManager->tuningMode == PCRTRK_TM_INIT)
						{
							speedAdjust = (int)preAdjust;
							pManager->tuningMode = PCRTRK_TM_START;
							pManager->sampling.rcdIdx = 0;
							pManager->sampling.baseRCD = 0;
						}
						else
						{
							int64_t rcd_diff = 0;
							if(abs(preAdjust) < 4)
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

								rcd_diff = rcd - rcd1;
								if(pManager->sampling.rcdIdx < RCD_SAMPLE_NUM)
								{
									pManager->sampling.sampleRCD[pManager->sampling.rcdIdx] = rcd;
									pManager->sampling.rcdIdx++;

									if(pManager->sampling.rcdIdx == RCD_SAMPLE_NUM)
									{
										pManager->sampling.baseRCD = 0;
										for(ii=1; ii<RCD_SAMPLE_NUM; ii++)
											pManager->sampling.baseRCD += pManager->sampling.sampleRCD[ii] - pManager->sampling.sampleRCD[0];

										pManager->sampling.baseRCD = div_s64(pManager->sampling.baseRCD, RCD_SAMPLE_NUM) + pManager->sampling.sampleRCD[0];
									}

									if (rcd_diff > 0)
									{
										speedAdjust++;
									}
									else if (rcd_diff < 0)
									{
										speedAdjust--;
									}
								}
								else
								{
									if(rcd_diff > 0 && rcd > pManager->sampling.baseRCD)
									{
										speedAdjust++;
									}
									else if(rcd_diff < 0 && rcd < pManager->sampling.baseRCD)
									{
										speedAdjust--;
									}
								}
							}
							else
							{
								if(pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
									pManager->switchStepSpan = true;
								pManager->tuningMode = PCRTRK_TM_NORMAL;

								rcd_diff = rcd - rcd1;
								if (rcd_diff > 0)
								{
									speedAdjust++;
								}
								else if (rcd_diff < 0)
								{
									speedAdjust--;
								}
							}
						}
						bUpdated = true;
					}
				}
				pManager->sampling.lastPcr = pManager->sampling.pcr;
				pManager->sampling.lastStc = pManager->sampling.stc;
				pManager->sampling.pcr = pManager->nextPCR;
				pManager->sampling.stc = pManager->nextSTC;
			}
			pManager->infoUpdated = false;
		}
	}
	PCRTRACK_UpdateSpeedAdjust(pManager, speedAdjust, bUpdated);
	pManager->sampling.prevRCD = pManager->RCD;
	pManager->state = PCRTRK_DETERMINE;
	mutex_unlock(&pManager->mutex);
}
/*	Only use this function in States to prevent from race condition.

*	step=1 means get the index of higher speed with 1 step.
*	step=-2 means get the index of lower speed with 2 step.
*/
static int PCRTRACK_GetNextSpeedPredefinedArrayIdx(PCRTRK_MANAGER_T *pManager, int step)
{
	int nextIdx = pManager->currentStepIdx + step;

	if (pManager->trackingMode == PCR_TRACKING) {
		//dmx_notice("[Trans mode: %d] tuningMode(%d), nextIdx(%d), currentStepIdx(%d)\n", __LINE__, pManager->tuningMode, nextIdx, pManager->currentStepIdx);
		if( pManager->switchStepSpan == true) {
			if (pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
				pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX + (pManager->currentStepIdx - PCRTRACK_PREDEFINED_DEFAULT_IDX) * PCRTRACK_PREDEFINED_FCODE_STEP_SPAN;
			else
				pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX + (pManager->currentStepIdx - PCRTRACK_PREDEFINED_DEFAULT_IDX) / PCRTRACK_PREDEFINED_FCODE_STEP_SPAN;

			nextIdx = pManager->currentStepIdx + step;
			pManager->switchStepSpan = false;
		}
	}
	/* tracking range is limited.
	 * Otherwise VODMA will have problem (K3LG-223) at least.
	 */
	if (pManager->tuningMode == PCRTRK_TM_FINE_TUNE) {
		if (nextIdx > PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX)
			nextIdx = PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX;
		else if (nextIdx < PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX)
			nextIdx = PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX;
	} else {
		if (nextIdx > PCRTRACK_PREDEFINED_TOP_IDX)
			nextIdx = PCRTRACK_PREDEFINED_TOP_IDX;
		else if (nextIdx < PCRTRACK_PREDEFINED_BOTTOM_IDX)
			nextIdx = PCRTRACK_PREDEFINED_BOTTOM_IDX;
	}
	return nextIdx;
}

void PCRTRACK_DetermineStateExecute(PCRTRK_MANAGER_T *pManager)
{
	if (pManager->bIsSuspending)
		pManager->state = PCRTRK_READY;
	else {
		int next = PCRTRACK_GetSpeedAdjust(pManager);
		if(next == 0)
			pManager->state = PCRTRK_WAITING;
		else {
			pManager->nextStepIdx = PCRTRACK_GetNextSpeedPredefinedArrayIdx(pManager, next);
			pManager->state = PCRTRK_SET_CLOCK;
		}

		if (pManager->adjustUpdated) {
			int ii = 0;
			for (ii=0; ii<(TRACKING_TREND_NUM-1); ii++)
				pManager->lastTrackingTrend[ii] = pManager->lastTrackingTrend[ii+1];

			pManager->lastTrackingTrend[TRACKING_TREND_NUM-1] = next;
			if (pManager->trendCountDown > 0) pManager->trendCountDown--;
	
			if (pManager->nextStepIdx < PCRTRACK_PREDEFINED_DEFAULT_IDX) {
				if((pManager->tuningMode == PCRTRK_TM_NORMAL && pManager->nextStepIdx == PCRTRACK_PREDEFINED_BOTTOM_IDX)
					|| (pManager->tuningMode == PCRTRK_TM_FINE_TUNE && pManager->nextStepIdx == PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX)) {
					pManager->extremeStep = 2;
					pManager->extremeStepCountDown = 30;
				} else {
					if(pManager->extremeStepCountDown > 0)
						pManager->extremeStepCountDown--;
					else
						pManager->extremeStep = 0;
				}
			}

			if (pManager->nextStepIdx > PCRTRACK_PREDEFINED_DEFAULT_IDX) {
				if ((pManager->tuningMode == PCRTRK_TM_NORMAL && pManager->nextStepIdx == PCRTRACK_PREDEFINED_TOP_IDX)
					|| (pManager->tuningMode == PCRTRK_TM_FINE_TUNE && pManager->nextStepIdx == PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX)) {
					pManager->extremeStep = 3;
					pManager->extremeStepCountDown = 30;
				} else {
					if(pManager->extremeStepCountDown > 0)
						pManager->extremeStepCountDown--;
					else
						pManager->extremeStep = 0;
				}
			}
			pManager->adjustUpdated = false;
		}
	}
}



/* pcr tracking manager*/
int PCRTRACK_ThreadProcEntry(void *pParam);
void PCRTRACK_ManagerVariableReset(PCRTRK_MANAGER_T *pManager)
{
	pManager->cc = 0;
	pManager->state = PCRTRK_SUSPEND;
	pManager->bIsSuspending = true;
	pManager->bIsTerminating = false;
	pManager->currentStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
	pManager->nextStepIdx = PCRTRACK_PREDEFINED_DEFAULT_IDX;
	pManager->trackingMode = NO_TRACKING;
	pManager->isTrackingMode = PCR_TRACKING;
	pManager->switchStepSpan = false;
	pManager->tuningMode = PCRTRK_TM_INIT;
	pManager->infoUpdated = false;
	pManager->nextPCR = -1;
	pManager->nextSTC = -1;
	pManager->RCD = -1 ;
	pManager->videoPTS = -1;
	pManager->audioPTS = -1;
	pManager->videoSysPTS = -1;
	pManager->audioSysPTS = -1;
}

void PCRTRACK_Initialize(PCRTRK_MANAGER_T *pManager, unsigned char tunerHandle)
{
	if (pManager->bInitialized)
		return;

	dmx_notice("[PT] PCR Tracking Manager Initializing...\n");

	PCRTRACK_REG_Initialize(&pManager->registers, PCRTRACK_ChoosePCRClock(tunerHandle));
	PCRTRACK_SMP_Reset(&pManager->sampling);
	PCRTRACK_REG_ResetClock(&pManager->registers);
	PCRTRACK_ManagerVariableReset(pManager);
	pManager->tunerHandle = tunerHandle;
	pManager->bInitialized = true;
	init_waitqueue_head(&pManager->resumeWQ);
	mutex_init(&pManager->mutex);
	pManager->pThread = kthread_create(PCRTRACK_ThreadProcEntry, (void *)pManager, "PCRTRACK");

	wake_up_process(pManager->pThread);
}

void PCRTRACK_Release(PCRTRK_MANAGER_T *pManager)
{
	/*PCR tracking manager isn't initialized yet.*/
	if (!pManager->bInitialized)
		return;

	pManager->bIsTerminating = true;
	if (pManager->pThread){
		wake_up(&pManager->resumeWQ);
		kthread_stop(pManager->pThread);
		pManager->pThread = NULL;
	}
	PCRTRACK_REG_ResetClock(&pManager->registers);
	PCRTRACK_ManagerVariableReset(pManager);

	pManager->tunerHandle = 0;
	pManager->bInitialized = false;
	mutex_destroy(&pManager->mutex);

	dmx_notice("[PT] PCR Tracking Manager UnInitialized...\n");
}

bool PCRTRACK_Start(PCRTRK_MANAGER_T *pManager, unsigned char tunerHandle)
{
	bool result = false;

	if (pManager->bIsSuspending) {
		mutex_lock(&pManager->mutex);
		if (pManager->state == PCRTRK_SUSPEND) {
			pManager->bIsSuspending = false;
			result = true;
			wake_up(&pManager->resumeWQ);
		}
		mutex_unlock(&pManager->mutex);
	} else {
		dmx_mask_print(DEMUX_PCRTRACK_DEBUG, "start pctrakcing....status not change\n")
		result = true;
	}
	return result;
}

void PCRTRACK_Stop(PCRTRK_MANAGER_T *pManager)
{
	mutex_lock(&pManager->mutex);
	pManager->bIsSuspending = true;
	wake_up(&pManager->resumeWQ);
	mutex_unlock(&pManager->mutex);
}

void PCRTRACK_UpdateSpeedAdjust(PCRTRK_MANAGER_T *pManager, int adjust, bool updated)
{
	pManager->speedAdjust = adjust;
	pManager->adjustUpdated = updated;
}

int PCRTRACK_GetSpeedAdjust(PCRTRK_MANAGER_T *pManager)
{
	int ret = 0;
	if (pManager->adjustUpdated) {
		ret = pManager->speedAdjust;
		pManager->speedAdjust = 0;
	}
	return ret;
}

void PCRTRACK_CheckTrackingSteady(PCRTRK_MANAGER_T *pManager, DEMUX_PCRSYNC_T *pPcrProcesser)
{
	int isUpward = 0, isDownward = 0, theTrend = 0;
	int ii = 0;

	if (pManager->trackingMode != PCR_TRACKING) {
		pPcrProcesser->isTrackingSteady = 1;
		return;
	}

	if (pManager->extremeStep == 2
	  || (pManager->tuningMode == PCRTRK_TM_NORMAL && pManager->currentStepIdx <= (PCRTRACK_PREDEFINED_BOTTOM_IDX+PCRTRACK_PREDEFINED_EDGE_SPAN))
	  || (pManager->tuningMode == PCRTRK_TM_FINE_TUNE && pManager->currentStepIdx <= (PCRTRACK_PREDEFINED_FINETUNE_BOTTOM_IDX+PCRTRACK_PREDEFINED_EDGE_SPAN*PCRTRACK_PREDEFINED_FINETUNE_MULTIPLE))) {
		pPcrProcesser->isTrackingSteady = 2;
		return;
	}

	if (pManager->extremeStep == 3
	  || (pManager->tuningMode == PCRTRK_TM_NORMAL && pManager->currentStepIdx >= (PCRTRACK_PREDEFINED_TOP_IDX-PCRTRACK_PREDEFINED_EDGE_SPAN))
	  || (pManager->tuningMode == PCRTRK_TM_FINE_TUNE && pManager->currentStepIdx >= (PCRTRACK_PREDEFINED_FINETUNE_TOP_IDX-PCRTRACK_PREDEFINED_EDGE_SPAN*PCRTRACK_PREDEFINED_FINETUNE_MULTIPLE))) {
		pPcrProcesser->isTrackingSteady = 3;
		return;
	}

	if (pManager->tuningMode < PCRTRK_TM_NORMAL || pManager->trendCountDown > (TRACKING_TREND_NUM/3)) {
		pPcrProcesser->isTrackingSteady = 0;
		return;
	}

	for (ii=0; ii<TRACKING_TREND_NUM; ii++) {
		theTrend += pManager->lastTrackingTrend[ii];
		if (pManager->lastTrackingTrend[ii] < 0)
			isDownward++;

		if (pManager->lastTrackingTrend[ii] > 0)
			isUpward++;
	}

	if ((theTrend < 0 && (isDownward - theTrend) > (3*TRACKING_TREND_NUM/2)) || (theTrend > 0 && (isUpward + theTrend) > (3*TRACKING_TREND_NUM/2))) {
		pPcrProcesser->isTrackingSteady = 0;
		return;
	}

	if (pManager->tuningMode > PCRTRK_TM_NORMAL) {
		pPcrProcesser->isTrackingSteady = 1;
		return;
	}

	pPcrProcesser->isTrackingSteady = 1;
}
void PCRTRACK_SetClockExecute(PCRTRK_MANAGER_T *pManager)
{
	if (pManager->nextStepIdx != pManager->currentStepIdx) {
		unsigned long defaultN = 0, defaultF = 0, fcode = 0, ncode = 0, tmp_fcode = 0;
		unsigned long quotient = 0, remainder = 0;
		int fcode_step = 0;

		defaultN = PCRTRACK_PREDEFINED_DEFAULT_NCODE;
		defaultF = PCRTRACK_PREDEFINED_DEFAULT_FCODE;
		if (pManager->tuningMode == PCRTRK_TM_FINE_TUNE)
			fcode_step = PCRTRACK_PREDEFINED_FINETUNE_FCODE_STEP_SPAN;
		else
			fcode_step = PCRTRACK_PREDEFINED_FCODE_STEP_SPAN;

		if (pManager->nextStepIdx < PCRTRACK_PREDEFINED_DEFAULT_IDX) {
			tmp_fcode = fcode_step*(PCRTRACK_PREDEFINED_DEFAULT_IDX - pManager->nextStepIdx);
			quotient = tmp_fcode / PCRTRACK_PLLBUS_FCODE_DIVISOR;
			remainder = tmp_fcode % PCRTRACK_PLLBUS_FCODE_DIVISOR;

			ncode = defaultN - quotient - 1;
			fcode = PCRTRACK_PLLBUS_FCODE_DIVISOR - remainder;
		} else if (pManager->nextStepIdx > PCRTRACK_PREDEFINED_DEFAULT_IDX) {
			tmp_fcode = fcode_step*(pManager->nextStepIdx - PCRTRACK_PREDEFINED_DEFAULT_IDX);
			quotient = tmp_fcode / PCRTRACK_PLLBUS_FCODE_DIVISOR;
			remainder = tmp_fcode % PCRTRACK_PLLBUS_FCODE_DIVISOR;

			ncode = defaultN + quotient;
			fcode = remainder;
		} else {
			ncode = defaultN;
			fcode = defaultF;
		}
		PCRTRACK_REG_Set_PLLDDS_OC(&pManager->registers, 0);
		PCRTRACK_REG_Set_FCODE(&pManager->registers, fcode);
		PCRTRACK_REG_Set_NCODE(&pManager->registers, ncode);
		PCRTRACK_REG_Set_PLLDDS_OC(&pManager->registers, 1);
	}

	pManager->currentStepIdx = pManager->nextStepIdx;
	pManager->state = PCRTRK_WAITING;
}
void PCRTRACK_WaitingStateExecute(PCRTRK_MANAGER_T *pManager)
{
	int waitCounter = 0;
	/* To prevent entering the TrackState with the same frequency ratio. It will cause frequency became larger or smaller continuously.*/
	/* context->m_isSuspending is because when suspending, Sampling module might be unable to update ratio counter, and cause stucking in wait state.*/
	if (pManager->tuningMode == PCRTRK_TM_FINE_TUNE) {
		for (waitCounter = 0 ; waitCounter < FINETUNE_SLEEP_LOOP_COUNT ; waitCounter++) {
			wait_event_freezable_timeout(pManager->resumeWQ,  (pManager->bIsSuspending ||(pManager->bIsTerminating == true)), msecs_to_jiffies(TUNING_SLEEP_WAIT_DURATION));

			if (pManager->bIsSuspending ||(pManager->bIsTerminating == true)|| (pManager->isTrackingMode != pManager->trackingMode) || pManager->RCD == -1)
				break;
		}
	} else if (pManager->tuningMode == PCRTRK_TM_START || pManager->tuningMode == PCRTRK_TM_INIT) {
		for (waitCounter = 0 ; waitCounter < BEGIN_SLEEP_LOOP_COUNT ; waitCounter++) {
			wait_event_freezable_timeout(pManager->resumeWQ,  (pManager->bIsSuspending ||(pManager->bIsTerminating == true)), msecs_to_jiffies(TUNING_SLEEP_WAIT_DURATION));

			if (pManager->bIsSuspending ||(pManager->bIsTerminating == true)|| (pManager->isTrackingMode != pManager->trackingMode) || pManager->RCD == -1)
				break;
		}
	} else {
		for (waitCounter = 0 ; waitCounter < RUNNING_SLEEP_LOOP_COUNT ; waitCounter++) {
			wait_event_freezable_timeout(pManager->resumeWQ,  (pManager->bIsSuspending ||(pManager->bIsTerminating == true)), msecs_to_jiffies(TUNING_SLEEP_WAIT_DURATION));

			if (pManager->bIsSuspending ||(pManager->bIsTerminating == true)|| (pManager->isTrackingMode != pManager->trackingMode) || pManager->RCD == -1)
				break;
		}
	}

	if (pManager->bIsSuspending)
		pManager->state = PCRTRK_READY;
	else
		pManager->state = PCRTRK_SAMPLING;
}

int PCRTRACK_ThreadProcEntry(void *pParam)
{
	int64_t lastPTS = -1;
	int64_t currentPTS = -1;
	PCRTRK_MANAGER_T *pManager = (PCRTRK_MANAGER_T *)pParam;

	while (pManager->bIsTerminating == false ||(!kthread_should_stop())) {
		set_freezable();
		pManager->cc++;

		currentPTS = CLOCK_GetPTS();
		if (!pManager->bIsSuspending && pManager->state != PCRTRK_SUSPEND && currentPTS-lastPTS > 3*DEMUX_CLOCKS_PER_SEC) {
			dmx_mask_print(DEMUX_PCRTRACK_DEBUG,DGB_COLOR_GREEN"[PT]CH%d: cc=%lld, cur_step=%d, sus=%d, mode=(%d, %d, %d, %d) (adiff %lld, vdiff %lld)"DGB_COLOR_NONE_N,
					pManager->tunerHandle, pManager->cc, pManager->currentStepIdx,
					pManager->bIsSuspending,
					pManager->isTrackingMode,
					pManager->trackingMode,
					(int)(pManager->tuningMode),
					pManager->extremeStep,
					pManager->audioPTS - pManager->audioSysPTS,
					pManager->videoPTS - pManager->videoSysPTS);
			lastPTS = currentPTS;
		} else if (currentPTS < lastPTS)
			lastPTS = currentPTS;

		switch (pManager->state) {
		case PCRTRK_SUSPEND:
			PCRTRACK_SuspendStateExecute(pManager);
			break;
		case PCRTRK_READY:
			PCRTRACK_ReadyStateExecute(pManager);
			break;
		case PCRTRK_WAITING:
			PCRTRACK_WaitingStateExecute(pManager);
			break;
		case PCRTRK_SAMPLING:
			PCRTRACK_SamplingStateExecute(pManager);
			break;
		case PCRTRK_DETERMINE:
			PCRTRACK_DetermineStateExecute(pManager);
			break;
		case PCRTRK_SET_CLOCK:
			PCRTRACK_SetClockExecute(pManager);
			break;
		}
	}
	return 1;
}
void PCRTRACK_UpdatePosition(PCRTRK_MANAGER_T *pManager, DEMUX_PCRSYNC_T *pPcrProcesser)
{
	/*check if A/V display the last frame and we have to continue to update RCD*/
	if (pManager != NULL && pPcrProcesser != NULL && pManager->pThread != NULL) {
		mutex_lock(&pManager->mutex);
		pManager->isTrackingMode = pPcrProcesser->trackingMode;
		pManager->nextPCR        = pPcrProcesser->pcr;
	  	pManager->nextSTC        = pPcrProcesser->stc;
		pManager->RCD            = pPcrProcesser->rcd;
		pManager->videoPTS       = pPcrProcesser->lastDemuxVideoPTS;
		pManager->audioPTS       = pPcrProcesser->lastDemuxAudioPTS;
		pManager->videoSysPTS    = pPcrProcesser->lastVideoSystemPTS;
		pManager->audioSysPTS    = pPcrProcesser->lastAudioSystemPTS;
		pManager->infoUpdated    = true;
		mutex_unlock(&pManager->mutex);
	}
}
long PCRTRACK_ChoosePCRClock(unsigned char tunerHandle)
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

