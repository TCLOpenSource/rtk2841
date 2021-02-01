

#ifndef _specan_H_
#define _specan_H_

/* SPECAN Major and Minor version numbers */
//#define SPECAN_VERSION_MAJOR 0x01
//#define SPECAN_VERSION_MINOR 0x00

/* Indicates which version of the Spectrum Analyser API is implemented */
#define SA_API_VERSION 0

/* Indicates the identity and version of the Spectrum Analyser application */
#define SA_DEMOD_ID 1

/* Indicates the build number of the Spectrum Analyser application */
#define SA_BUILD_ID 2

/* The control register is the primary operating control for the Spectrum Analyser IP. Command values written to this register control the major operating modes of the demodulator. This register is a command register as described in [1]. */
#define SA_CONTROL 3

/* The state register indicates the current operating state of the TV demodulator. */
#define SA_STATE 4

/* In the INITIALISED state, this register is used to set the starting RF tuner frequency for a scan. For a host-controlled tuner, it is also used for confirmation that a requested frequency has been set, as described in section 2.3.2.  It is a command register as described in [1]. */
#define SA_TUNER_FREQ 5

/* In the INITIALISED state, this register is used to set the RF tuner bandwidth to use during a scan. For a host-controlled tuner, it is also used for confirmation that a requested bandwidth has been set, as described in section 2.3.2.   Its operation is linked to SA_TUNER_FREQ in two ways: Updates to the tuner bandwidth will not become effective until SA_TUNER_FREQ is written also; i.e. bandwidth changes and centre frequency changes are always made together.   Completion of combined frequency and bandwidth update operations is indicated in SA_TUNER_FREQ. You should check that SA_TUNER_FREQ is ready for an update before writing to SA_TUNER_BW. A bandwidth update may be missed if a frequency update (which implies a bandwidth update also) is still in progress. */
#define SA_TUNER_BW 6

/* This register is used (in conjunction with SA_TUNER_GRID_INCR) to describe a RF frequency grid to the demodulator.  When a demodulator requests that the host makes a RF frequency change, it will limit such requests to frequencies satisfying: F=SA_TUNER_GRID_BASE +\- N*SA_TUNER_GRID_INC, where N is an integer. This has two benefits:  Frequency selections can be limited to those that the tuner is able to provide.   Frequency selections are effectively filtered, limiting traffic across the register API.  Frequency gridding/filtering can be disabled by setting SA_TUNER_GRID_INCR to 0 or 1.  */
#define SA_TUNER_GRID_BASE 7

/* This register is used (in conjunction with SA_TUNER_GRID_BASE) to describe a RF frequency grid to the demodulator.  When a demodulator requests that the host makes a RF frequency change, it will limit such requests to frequencies satisfying: F=SA_TUNER_GRID_BASE +\- N*SA_TUNER_GRID_INC, where N is an integer. This has two benefits:   Frequency selections can be limited to those that the tuner is able to provide.   Frequency selections are effectively filtered, limiting traffic across the register API.  Frequency gridding/filtering can be disabled by setting SA_TUNER_GRID_INCR to 0 or 1.   */
#define SA_TUNER_GRID_INCR 8

/* For a host-controlled tuner this register is used to request changes of tuner frequency.  In the case where the tuner is controlled directly by the spectrum analyser system, this register may be ignored. */
#define SA_ACTIVE_TUNER_FREQ 11

/* For a host-controlled tuner this register is used to request changes of tuner bandwidth.  In the case where the tuner is controlled directly by the spectrum analyser system, this register may be ignored. */
#define SA_ACTIVE_TUNER_BW 12

/* This register specifies the desired scan range. The output range is (SA_TUNER_FREQ : SA_TUNER_FREQ+SA_SCAN_RANGE) in Hz. If set to 0, this register specifies a single frequency tune at SA_TUNER_FREQ, the output range is (SA_TUNER_FREQ-SA_TUNING_STEP/2 : SA_TUNER_FREQ+SA_TUNING_STEP/2) in Hz. */
#define SA_SCAN_RANGE 0x8000

/*  */
#define SA_SCAN_RESOLUTION 0x8001

/*  */
#define SA_TUNING_STEP 0x8002

/*  */
#define SA_MEASUREMENT_CONTROL 0x8003

/*  */
#define SA_AVERAGING_PERIOD 0x8004

/*  */
#define SA_IF_GAIN_OVERRIDE 0x8005

/*  */
#define SA_TUNER_3DB_POINT  0x8006

/*  */
#define SA_TUNER_6DB_POINT 0x8007

/*  */
#define SA_TUNER_9DB_POINT 0x8008

/*  */
#define SA_TUNER_12DB_POINT 0x8009

/*  */
#define SA_REG_OUT_SPECTRUM_PTR 0x800A

/*  */
#define SA_OUT_SPECTRUM_LEN  0x800B

/*  */
#define SA_MAX_RSSI_REG 0x800C

/*  */
#define SA_REF_IF_GAIN_REG 0x800D

/* These registers record the 8 largest independent values of spectral power found in the scan.  To ensure that each peak is independent, peaks which are adjacent to another higher peak are excluded.  The 'adjacent' region is defined by the SA_MAX_PEAK_WIDTH register.  SA_MAX_POWER_REG_0 records the highest spectral power found, whereas SA_MAX_POWER_REG_7 records the 8th highest power found. */
#define SA_MAX_POWER_REG_00 0x800E
#define SA_MAX_POWER_REG_01 0x800F
#define SA_MAX_POWER_REG_02 0x8010
#define SA_MAX_POWER_REG_03 0x8011
#define SA_MAX_POWER_REG_04 0x8012
#define SA_MAX_POWER_REG_05 0x8013
#define SA_MAX_POWER_REG_06 0x8014
#define SA_MAX_POWER_REG_07 0x8015

/* The failure code register should be read on commencing a scan to ensure settings are valid. Zero indicates no failure. */
#define SA_FAILURE_CODE 0x8016

/* This register can be polled during a scan to obtain a rough estimate of progress through the scan. */
#define SA_COMPLETION_PERCENT 0x8017

/* A write to this register initiates a transfer of debug data into a holding buffer. */
#define SA_DEBUG_VECTOR_OP_SEL  19

/* In the case where an output debug vector is larger than the buffer available for transferring it, this register allows the user to specify what part of the vector will be transferred. */
#define SA_DEBUG_VECTOR_OP_PARAMS 20

/* Length to use when transferring a vector of data selected with SA_DEBUG_VECTOR_OP_SEL */
#define  SA_DEBUG_VECTOR_TRANSFER_LEN 21

/* Total number of specan specific registers */
#define SPECAN_NUM_REGS (24)

/* Total number of registers for specan */
#define SPECAN_REG_TOTALREG (SPECAN_NUM_REGS + TV_REG_NUM_COMMON_REG)


#endif /* _specan_H_ */

