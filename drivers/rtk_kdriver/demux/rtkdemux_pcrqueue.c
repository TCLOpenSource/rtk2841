#include <linux/kernel.h>
#include "rtkdemux_common.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_pcrqueue.h"

void PCRQ_Reset(PCR_QUEUE *pQueue)
{
	pQueue->tailIdx = 0;
	pQueue->headIdx = 0;
}

bool PCRQ_IsEmpty(PCR_QUEUE *pQueue)
{
	return (pQueue->tailIdx == pQueue->headIdx);
}

bool PCRQ_IsFull(const PCR_QUEUE *pQueue)
{
	int distance = pQueue->headIdx - pQueue->tailIdx;
	if (distance < 0)
		distance += PCR_QUEUE_SIZE;

	return (distance + 1 == PCR_QUEUE_SIZE);
}

bool PCRQ_EnQueue(PCR_QUEUE *pQueue, PCR_INFO pcrInfo)
{
	int fullness = pQueue->headIdx - pQueue->tailIdx;
	if (fullness < 0)
		fullness +=  PCR_QUEUE_SIZE;

	if ((fullness+1) == PCR_QUEUE_SIZE) {
		dmx_crit("[%s %d] pcr queue full\n", __FILE__, __LINE__);
		return false;
	}

	pQueue->table[pQueue->headIdx] = pcrInfo;
	pQueue->headIdx++;
	if (pQueue->headIdx >= PCR_QUEUE_SIZE)
		pQueue->headIdx -= PCR_QUEUE_SIZE;

	return true;
}

bool PCRQ_GetHead(PCR_QUEUE *pQueue, PCR_INFO *pPcrInfo)
{
	if (PCRQ_IsEmpty(pQueue))
		return false;

	*pPcrInfo = pQueue->table[pQueue->tailIdx];
	return true;
}

bool PCRQ_DeQueue(PCR_QUEUE *pQueue, PCR_INFO *pPcrInfo)
{
	if (!PCRQ_GetHead(pQueue, pPcrInfo))
		return false;

	pQueue->tailIdx++;
	if (pQueue->tailIdx >= PCR_QUEUE_SIZE)
		pQueue->tailIdx -= PCR_QUEUE_SIZE;

	return true;
}
