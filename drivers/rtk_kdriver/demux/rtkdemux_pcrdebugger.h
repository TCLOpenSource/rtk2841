#ifndef RTKDEMUX_PCRDEBUGGER_H
#define RTKDEMUX_PCRDEBUGGER_H

#define PCR_TABLE_SIZE 10

typedef struct {
    long long pcr;
    long long stc;
    long long audioDemuxPTS;
    long long videoDemuxPTS;
} PCR_ENTRY_T;

typedef struct {
    PCR_ENTRY_T pcrTable[PCR_TABLE_SIZE];
    int tail;   /*point to the first element which is going to be read*/
    int head;   /*point to the first element which is going to be written*/
    bool meetPcrBackTrack;
    PCR_ENTRY_T lastEntry;

} PCR_DEBUGGER_T;

void PCRDEBUG_Reset(PCR_DEBUGGER_T *pDebugger);
int PCRDEBUG_Insert(PCR_DEBUGGER_T *pDebugger, long long pcr, long long stc, long long audioPTS, long long videoPTS);
void PCRDEBUG_Dump(const PCR_DEBUGGER_T *pDebugger);
bool PCRDEBUG_MeetPcrBackTrack(const PCR_DEBUGGER_T *pDebugger);
void PCRDEBUG_ClearPcrBackTrack(PCR_DEBUGGER_T *pDebugger);


#endif /*RTKDEMUX_PCRDEBUGGER_H*/
