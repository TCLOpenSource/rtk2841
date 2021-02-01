#include <linux/types.h>
#include <mach/io.h>
#include "rtkdemux_register.h"

#define DEMUX_REGISTER_SIZE (32u)

// The memory layout of execution counters(equal size) for each channel:
// (n = DEMUX_MAX_SUPPORT_CHANNEL_COUNT - 1)
//
// |<------------------ 32 bits ------------------>|
// [Channel #0][Channel #1]    ......   [Channel #n]
#define DEMUX_MAX_SUPPORT_CHANNEL_COUNT (2u)
#define DEMUX_MIN_EXECUTION_COUNTER_SIZE (8u)
#define DEMUX_EXECUTION_COUNTER_SIZE (DEMUX_REGISTER_SIZE / DEMUX_MAX_SUPPORT_CHANNEL_COUNT)

#if (DEMUX_EXECUTION_COUNTER_SIZE < DEMUX_MIN_EXECUTION_COUNTER_SIZE)
    #error "execution counters are not big enough"
#else
    #if (DEMUX_REGISTER_SIZE % DEMUX_MAX_SUPPORT_CHANNEL_COUNT != 0)
        #error "the max support channel count does not divides register size"
    #elif (DEMUX_REGISTER_SIZE % DEMUX_MIN_EXECUTION_COUNTER_SIZE != 0)
        #error "the min execution counter size does not divides register size"
    #endif
#endif

typedef uint32_t register_t;

#if (DEMUX_EXECUTION_COUNTER_SIZE == DEMUX_REGISTER_SIZE)
    typedef register_t execution_counter_t;
    #define DEMUX_EXECUTION_COUNTER_FILTER_MASK (0xFFFFFFFF)
#elif (DEMUX_EXECUTION_COUNTER_SIZE == 16u)
    typedef uint16_t execution_counter_t;
    #define DEMUX_EXECUTION_COUNTER_FILTER_MASK (0x0000FFFF)
#elif (DEMUX_EXECUTION_COUNTER_SIZE == 8u)
    typedef uint8_t execution_counter_t;
    #define DEMUX_EXECUTION_COUNTER_FILTER_MASK (0x000000FF)
#endif

#define DEMUX_EXECUTION_COUNTER_RECOVERY_OFFSET(channel) \
    ((DEMUX_MAX_SUPPORT_CHANNEL_COUNT - 1 - channel) * DEMUX_EXECUTION_COUNTER_SIZE)

static register_t DEMUX_RegisterRead(uint32_t address)
{
    return rtd_inl(address);
}

static void DEMUX_RegisterWrite(uint32_t address, register_t value)
{
    return rtd_outl(address, value);
}

static execution_counter_t DEMUX_RegisterReadExecutionCounter(unsigned channel)
{
    if (!DEMUX_RegisterIsSupportedChannel(channel))
        return (execution_counter_t)-1;
	else {
    const register_t value = DEMUX_RegisterRead(DEMUX_THREAD_EXECUTION_COUNTER);
    return (execution_counter_t)(value >> DEMUX_EXECUTION_COUNTER_RECOVERY_OFFSET(channel) & DEMUX_EXECUTION_COUNTER_FILTER_MASK);
}
}

static void DEMUX_RegisterWriteExecutionCounter(unsigned channel, execution_counter_t value)
{
#if 0
    if (!DEMUX_RegisterIsSupportedChannel(channel))
        return;
	else {

    const unsigned recoveryOffset = DEMUX_EXECUTION_COUNTER_RECOVERY_OFFSET(channel);

    const register_t extended = value;
    const register_t shifted  = (extended << recoveryOffset);

    const register_t mask = ~(DEMUX_EXECUTION_COUNTER_FILTER_MASK << recoveryOffset);

    const register_t oldValue = DEMUX_RegisterRead(DEMUX_THREAD_EXECUTION_COUNTER);
    const register_t newValue = (oldValue & mask) | shifted;

    DEMUX_RegisterWrite(DEMUX_THREAD_EXECUTION_COUNTER, newValue);
}
#endif
}

bool DEMUX_RegisterIsSupportedChannel(unsigned channel)
{
    return channel < DEMUX_MAX_SUPPORT_CHANNEL_COUNT;
}

void DEMUX_RegisterResetExecutionCounters()
{
    DEMUX_RegisterWrite(DEMUX_THREAD_EXECUTION_COUNTER, 0u);
}

void DEMUX_RegisterIncreaseExecutionCounter(unsigned channel)
{
    if (!DEMUX_RegisterIsSupportedChannel(channel))
        return;

    DEMUX_RegisterWriteExecutionCounter(
        channel,
        DEMUX_RegisterReadExecutionCounter(channel) + 1
    );
}
