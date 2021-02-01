#ifndef RTKDEMUX_REGISTER_H
#define RTKDEMUX_REGISTER_H

#include <linux/types.h>

static const uint32_t DEMUX_THREAD_EXECUTION_COUNTER = 0xb8014188;

bool DEMUX_RegisterIsSupportedChannel(unsigned channel);
void DEMUX_RegisterResetExecutionCounters(void);
void DEMUX_RegisterIncreaseExecutionCounter(unsigned channel);

#endif
