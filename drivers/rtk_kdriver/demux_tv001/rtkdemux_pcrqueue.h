#ifndef RTKDEMUX_PCRQUEUE_H
#define RTKDEMUX_PCRQUEUE_H

typedef struct {
    int64_t pcr;
    int64_t stc;
    int64_t prevPcr;
    int64_t prevStc;
    int64_t videoPTS;
    int64_t audioPTS;
    int64_t prevVideoPTS;
    int64_t prevAudioPTS;
} PCR_INFO;

#define PCR_QUEUE_SIZE 20
typedef struct {
    int tailIdx;    /*point to the first element which is going to be read*/
    int headIdx;    /*point to the first element which is going to be written*/

    PCR_INFO table[PCR_QUEUE_SIZE];
} PCR_QUEUE;

void PCRQ_Reset(PCR_QUEUE *pQueue);
bool PCRQ_IsFull(const PCR_QUEUE *pQueue);
bool PCRQ_IsEmpty(PCR_QUEUE *pQueue);
bool PCRQ_EnQueue(PCR_QUEUE *pQueue, PCR_INFO pcrInfo);
bool PCRQ_GetHead(PCR_QUEUE *pQueue, PCR_INFO *pPcrInfo);
bool PCRQ_DeQueue(PCR_QUEUE *pQueue, PCR_INFO *pPcrInfo);

#endif /*RTKDEMUX_PCRQUEUE_H*/
