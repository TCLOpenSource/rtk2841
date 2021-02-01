#include "rtkdemux.h"
#include "rtkdemux_pcrtracking.h"
#include "rtkdemux_refclk.h"
#include "rtkdemux_debug.h"
#include <tp/tp_drv_global.h>

int Demux_MW_enablePCRTracking(demux_channel *pCh)
{
	TPK_PCR_CLK_SRC_T clk_src;
	INT32 iClkRet;
	if (pCh== NULL)
		return -1;

	/* Don't start pcr recovery while in MTP status */
	if (pCh->tp_src == MTP) return 0;


	if (pCh->pPcrRecoveryManager) {
		if( 1 == pCh->bPcrTrackEnable) {

			/* Change clock mode */
			clk_src = PCRTRACK_ChoosePCRClock(pCh->tunerHandle);
			dmx_mask_print(DEMUX_PCRTRACK_DEBUG,"\033[1;36m [%s %d] (dtv%d)Set tp&ref clk=%d\033[m\n", __func__ , __LINE__ , pCh->tunerHandle,clk_src );
			iClkRet = RHAL_PCRTrackingEnable(pCh->tunerHandle, true, pCh->PCRPID, clk_src);
			if( TPK_SUCCESS == iClkRet ) {
				REFCLK_SetClockMode(DEMUX_GetReferenceClock(pCh), clk_src);

				/* Reset AV Sync variables */
				//PCRSYNC_Reset(&pCh->pcrProcesser, DEMUX_GetReferenceClock(pCh), pCh->tunerHandle, pCh->pPcrRecoveryManager);

				/* Start PcrTracking State Machine */

				if (PCRTRACK_Start(pCh->pPcrRecoveryManager, pCh->tunerHandle) ==false ){
					dmx_mask_print(DEMUX_PCRTRACK_DEBUG,"\033[1;36m [%s %d] ch:%d, fail to start PcrTracking \033[m\n", __func__ , __LINE__ ,pCh->tunerHandle );
					return -1;
				}
			}
			else{
				dmx_notice("\033[1;31m [%s %d](dtv%d)Set tp clk=%d Failed,ret=%d,PID=0x%x\033[m\n", __func__ , __LINE__ , pCh->tunerHandle , clk_src , iClkRet , pCh->PCRPID);
				return -1;
			}

		} else {
			clk_src = MISC_90KHz;
			dmx_mask_print(DEMUX_PCRTRACK_DEBUG,"\033[1;36m [%s %d] (dtv%d)Set tp&ref clk=%d\033[m\n", __func__ , __LINE__ , pCh->tunerHandle,clk_src );
			iClkRet = RHAL_PCRTrackingEnable(pCh->tunerHandle, true, pCh->PCRPID, clk_src);
			if( TPK_SUCCESS == iClkRet ) {
				REFCLK_SetClockMode(DEMUX_GetReferenceClock(pCh), clk_src);
			} else {
				dmx_notice("\033[1;31m [%s %d](dtv%d)Set tp clk=%d Failed,ret=%d,PID=0x%x\033[m\n", __func__ , __LINE__ , pCh->tunerHandle , clk_src , iClkRet , pCh->PCRPID);
			}
		}

	}
	else{
		dmx_err("[%s,%d] fail to enable pcrtracking  , no support pcrtracking in ch: %d \n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}

	return 0;
}

int Demux_MW_disablePCRTracking(demux_channel *pCh)
{
	TPK_PCR_CLK_SRC_T clk_src;
	INT32 iClkRet;
	if (pCh== NULL)
		return -1;
	
	if (pCh->pPcrRecoveryManager) {
		/* Stop PcrTracking State Machine */
		PCRTRACK_Stop(pCh->pPcrRecoveryManager);
	}

	/* change clock mode */
	clk_src = MISC_90KHz;
	dmx_mask_print(DEMUX_PCRTRACK_DEBUG,"\033[1;36m [%s %d] Ch =%d\033[m\n", __func__ , __LINE__ , pCh->tunerHandle );
	if(0 < pCh->PCRPID && pCh->PCRPID < 0x1FFF)
		iClkRet = RHAL_PCRTrackingEnable(pCh->tunerHandle, true , pCh->PCRPID, clk_src);
	else
		iClkRet = RHAL_PCRTrackingEnable(pCh->tunerHandle, false , pCh->PCRPID, clk_src);

	if( TPK_SUCCESS == iClkRet ) {

		REFCLK_SetClockMode(DEMUX_GetReferenceClock(pCh), clk_src);

		/* Reset AV Sync variables */
		PCRSYNC_Reset(&pCh->pcrProcesser, DEMUX_GetReferenceClock(pCh), pCh->tunerHandle, pCh->pPcrRecoveryManager);
	} else {
		dmx_notice("\033[1;31m [%s %d](dtv%d)Set tp clk=%d Failed,ret=%d,PID=0x%x\033[m\n", __func__ , __LINE__ , pCh->tunerHandle , clk_src , iClkRet , pCh->PCRPID);
	}
	return 0;
}
