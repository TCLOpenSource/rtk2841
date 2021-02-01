
#include <linux/cdev.h>
#include "rtkdemux.h"
#include "rtkdemux_common.h"
#include "rtkdemux_clock.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_specialhandling.h"

void BufferFullDroppingReset(demux_channel *pCh, int pinIndex, int isAllPin)
{
    int i;

    if(isAllPin)
    {
    	for(i = 0; i < NUMBER_OF_PINS; i ++)
    	{
        	pCh->bDropflag[i] = false;
        	pCh->ringFullCheckTimer[i] = 0;
    	}
    	demux_device->totalDroppingPin = 0;
    }
    else
    {
    		pCh->bDropflag[pinIndex] = false;
		pCh->ringFullCheckTimer[pinIndex] = 0;
		demux_device->totalDroppingPin --;
		if(demux_device->totalDroppingPin < 0)
			demux_device->totalDroppingPin = 0;
    }
}

void CheckStartCondition(demux_channel *pCh, int pinIndex)
{
    if(!pCh->bDropflag[pinIndex] && (pCh->ringFullCheckTimer[pinIndex] == 0))
    {                                       
        pCh->ringFullCheckTimer[pinIndex] = CLOCK_GetPTS();
    }
    else if (!pCh->bDropflag[pinIndex] && (CLOCK_GetPTS() - pCh->ringFullCheckTimer[pinIndex]) > 50*DEMUX_CLOCKS_PER_MS)
    {                        
        //dmx_must_print("[%s %d] ring buffer full, dropping mode. Ch = %d, pinIndex = %d\n", __func__, __LINE__, pCh->tunerHandle, pinIndex);                        
        pCh->bDropflag[pinIndex] = true;
	  demux_device->totalDroppingPin++;
    }
}

void CheckStopCondition(demux_channel *pCh, int pinIndex, long writableSize, long ringBufferSize)
{
    pCh->ringFullCheckTimer[pinIndex] = 0;
		
    if(IsDropping(pCh, pinIndex) && (writableSize > 25 * (ringBufferSize - writableSize) * writableSize))		
    {
        dmx_crit("[%s %d] dropping mode stop. Ch = %d, pinIndex =%d\n", __func__, __LINE__, pCh->tunerHandle, pinIndex);
        pCh->bDropflag[pinIndex] = false;
	  demux_device->totalDroppingPin--;
    }
}

bool IsDropping(demux_channel *pCh, int pinIndex) 
{ 
	return pCh->bDropflag[pinIndex]; 
}

bool GetTotalDroppingPin(void)
{
	return demux_device->totalDroppingPin > 0;
}

