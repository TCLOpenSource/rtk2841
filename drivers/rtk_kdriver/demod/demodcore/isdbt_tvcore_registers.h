/**** THIS FILE IS AUTO GENRATED BY THE xml2reg TOOL ****/

#ifndef _tvcore_registers_H_
#define _tvcore_registers_H_

/* TVCORE Major and Minor version numbers */
#define TVCORE_VERSION_MAJOR 0x07
#define TVCORE_VERSION_MINOR 0x08

/* Indicates which version of the common TV API is implemented. */
#define TV_REG_API_ID 0

/* Indicates the identity and version of the TV demodulator */
#define TV_REG_DEMOD_ID 1

/* Indicates the build number of the TV demodulator */
#define TV_REG_BUILD_ID 2

/* The TV control register. Writing to this register controls the main operating functions of the TV demodulator */
#define TV_REG_CONTROL 3

/* The TV state register. The value in this register indicates the current operating state of the TV demodulator. */
#define TV_REG_STATE 4

/* Tuner frequency control register. Sets the nominal tuner RF frequency in Hz. */
#define TV_REG_TUNER_FREQ 5

/* Tuner frequency control register. Sets the nominal tuner RF bandwidth in Hz. */
#define TV_REG_TUNER_BW 6

/* External tuner grid base frequency in Hz. */
#define TV_REG_TUNER_GRID_BASE 7

/* External tuner grid frequency increment in Hz. */
#define TV_REG_TUNER_GRID_INCR 8

/* Notch filter frequency and request. */
#define TV_REG_NOTCH_FREQ 9

/* Notch filter bandwidth. */
#define TV_REG_NOTCH_BW 10

/* Active tuner frequency (Hz). */
#define TV_REG_ACTIVE_TUNER_FREQ 11

/* Active tuner bandwidth (Hz). */
#define TV_REG_ACTIVE_TUNER_BW 12

/* Active tuner IF gain value. */
#define TV_REG_ACTIVE_TUNER_GAIN 13

/* Active tuner received signal strength indicator (RSSI) value. */
#define TV_REG_ACTIVE_TUNER_RSSI 14

/* Multi-valued AGC parameter override */
#define TV_REG_AGC_PARAMS 15

/* Configuration of Transport Stream Output */
#define TV_REG_TSO_CONFIG 16

/* Margin by which the TSO byte clock frequency exceeds that required (ppm) */
#define TV_REG_TSO_CLK_RATE_MARGIN 17

/* Maximum TSO byte clock frequency */
#define TV_REG_TSO_CLK_RATE_MAX 18

/* Selection of debug data vector to be transferred. */
#define TV_REG_DEBUG_VECTOR_OP_SEL 19

/* Specify what part of the vector will be transferred */
#define TV_REG_DEBUG_VECTOR_OP_PARAMS 20

/* Length to use when transferring a vector of data selected with TV_REG_DEBUG_VECTOR_OP_SEL */
#define TV_REG_DEBUG_VECTOR_TRANSFER_LEN 21

/* Specify the location of the DBV transfer buffer */
#define TV_REG_DEBUG_VECTOR_BUFF_PTR 22

/* Specify the size of the DBV transfer buffer */
#define TV_REG_DEBUG_VECTOR_BUFF_SIZE 23

/* Flags to enable logging of various items for debug purposes */
#define TV_REG_ENSIGMA_SDK_LOGGING 24

/* Specify the location of the Ensigma SDK logging buffer */
#define TV_REG_ENSIGMA_SDK_BUFF_PTR 25

/* Specify the size of the Ensigma SDK logging buffer */
#define TV_REG_ENSIGMA_SDK_BUFF_SIZE 26

/* Time from DETECT/RUN command to ACQUIRED/NOTHING_THERE event */
#define TV_REG_LOCK_TIME 27

/* If the host is controlling the tuner, override tunerConfig */
#define TV_REG_TUNER_CFG_OVERRIDE 28

/* Control params for setIFgain. */
#define TV_REG_PFM_SET_IF_GAIN_CTRL 29

/* Provide the values of PFM_COMPLEX_IF_FLAG, PFM_TUNER_SAMPLE_FORMAT and PFM_TUNER_INTERNAL_AGC_ENABLE. */
#define TV_REG_PFM_FLAGS 30

/* The final IF frequency */
#define TV_REG_PFM_IF_FREQ 31

/* Select platform support override registers */
#define TV_REG_PFM_OVERRIDE 32

/* IF sampling clock frequency */
#define TV_REG_PFM_IF_CLK_FREQUENCY 33

/* LDPC decoder clock frequency */
#define TV_REG_PFM_LDPC_CLK_FREQUENCY 34

/* UCC clock frequency */
#define TV_REG_PFM_UCC_CLK_FREQUENCY 35

/* MCU clock frequency */
#define TV_REG_PFM_MCU_CLK_FREQUENCY 36

/* Error count threshold, above which we will not declare DEMODULATING if entering from acquisition. */
#define TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY 37

/* Data length for the error rate measurement prior to entering DEMODULATING */
#define TV_REG_DEMOD_ENTRY_MEASURE_LEN 38

/* Maximum time, in ms, for the error rate measurement prior to entering DEMODULATING */
#define TV_REG_DEMOD_LOCK_TIMEOUT 39

/* Threshold error count above which we will declare loss of lock and drop out of DEMODULATING (after a timeout). */
#define TV_REG_ERR_THRESH_FOR_DEMOD_EXIT 40

/* Data length for the error rate measurement that governs exit from DEMODULATING */
#define TV_REG_DEMOD_EXIT_MEASURE_LEN 41

/* Timeout in ms during which we will observe bad conditions before dropping out of the DEMODULATING state */
#define TV_REG_LOST_LOCK_TIMEOUT 42

/* Total number of registers for tvcore */
#define TV_REG_NUM_COMMON_REG (43)


#endif /* _tvcore_registers_H_ */

