#include <linux/kernel.h>
#include "rtkdemux_clock.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_pcrdebugger.h"


void PCRDEBUG_Reset(PCR_DEBUGGER_T *pDebugger)
{
	pDebugger->tail = pDebugger->head = 0;
	pDebugger->meetPcrBackTrack = false;
	pDebugger->lastEntry.pcr = pDebugger->lastEntry.stc = -1;
	pDebugger->lastEntry.audioDemuxPTS = pDebugger->lastEntry.videoDemuxPTS = -1;
}

int PCRDEBUG_Insert(PCR_DEBUGGER_T *pDebugger, long long pcr, long long stc, long long audioPTS, long long videoPTS)
{
	if (pDebugger->lastEntry.pcr != -1 && pDebugger->lastEntry.pcr == pcr && pDebugger->lastEntry.stc == stc && pDebugger->lastEntry.audioDemuxPTS == audioPTS && pDebugger->lastEntry.videoDemuxPTS == videoPTS)
		return 0;

	/*stc back trace will cause video jitter (video complains RCD jump)*/
	if (pDebugger->lastEntry.stc != -1 && pDebugger->lastEntry.stc > stc) {
		static unsigned long pts;
		unsigned long curpts = CLOCK_GetPTS();
		if (curpts-pts > DEMUX_CLOCKS_PER_SEC) {
			dmx_err("[%s %d] drop pcr (%lld), prev_stc (%lld), stc (%lld)\n", __FILE__, __LINE__, pcr, pDebugger->lastEntry.stc, stc);
			pts = curpts;
		}
		/*return 0;*/
	}

	if (pcr < pDebugger->lastEntry.pcr) {
		pDebugger->meetPcrBackTrack = true;
	}

	pDebugger->pcrTable[pDebugger->head].pcr = pcr;
	pDebugger->pcrTable[pDebugger->head].stc = stc;
	pDebugger->pcrTable[pDebugger->head].audioDemuxPTS = audioPTS;
	pDebugger->pcrTable[pDebugger->head].videoDemuxPTS = videoPTS;

	pDebugger->lastEntry = pDebugger->pcrTable[pDebugger->head];
	pDebugger->head = (pDebugger->head == (PCR_TABLE_SIZE-1)) ? 0 : (pDebugger->head+1);
	if (pDebugger->tail == pDebugger->head)
		pDebugger->tail = (pDebugger->tail == (PCR_TABLE_SIZE-1)) ? 0 : (pDebugger->tail+1);

#ifdef SHOW_PCR_HISTORY
	dmx_warn("pcr = %lld, stc = %lld, audioDemuxPTS = %lld, videoDemuxPTS = %lld\n", pcr, stc, audioPTS, videoPTS);
#endif
	return 1;
}

void PCRDEBUG_Dump(const PCR_DEBUGGER_T *pDebugger)
{
	int i = pDebugger->tail;
	while (i != pDebugger->head) {
		dmx_mask_print(DEMUX_PCRSYC_DEBUG,"pcr = %lld, stc = %lld, audioDemuxPTS = %lld, videoDemuxPTS = %lld\n", pDebugger->pcrTable[i].pcr, pDebugger->pcrTable[i].stc, pDebugger->pcrTable[i].audioDemuxPTS, pDebugger->pcrTable[i].videoDemuxPTS);
		i = (i == (PCR_TABLE_SIZE-1)) ? 0 : (i+1);
	}
}

bool PCRDEBUG_MeetPcrBackTrack(const PCR_DEBUGGER_T *pDebugger)
{
	return pDebugger->meetPcrBackTrack;
}

void PCRDEBUG_ClearPcrBackTrack(PCR_DEBUGGER_T *pDebugger)
{
	pDebugger->meetPcrBackTrack = false;
}
