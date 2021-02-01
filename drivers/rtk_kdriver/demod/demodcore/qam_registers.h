/**** THIS FILE IS AUTO GENRATED BY THE xml2reg TOOL ****/

#ifndef _j83b_H_
#define _j83b_H_

/* System State */
#define CABLE_REG_SYSTEM_STATE 0x8000

/* Coarse Carrier Synchronization Sub-state */
#define CABLE_REG_CCS_STATE 0x8001

/* Equaliser Adaptation Sub-state */
#define CABLE_REG_EQADAPT_STATE 0x8002

/* Signal Not Found */
#define CABLE_REG_SIGNAL_NOT_FOUND 0x8003

/* Symbol Rate Monitor */
#define CABLE_REG_SYM_RATE_MON 0x8004

/* Carrier Frequency Monitor */
#define CABLE_REG_CARR_FREQ_MON 0x8005

/* QAM Size Monitor */
#define CABLE_REG_QAM_MON 0x8006

/* Spectrum Inversion Monitor */
#define CABLE_REG_SPEC_INV_MON 0x8007

/* J83B Interleaver Mode */
#define CABLE_REG_INTL_MODE 0x8008

/* Acquisition Timer */
#define CABLE_REG_AQUISITION_TIME 0x8009

/* Acquisition Time Reset */
#define CABLE_REG_AQUISITION_TIME_RESET 0x800A

/* Equaliser Output SNR */
#define CABLE_REG_EQ_SNR_DB 0x800B

/* Number of MPEG TS Packets */
#define CABLE_REG_NUM_PKTS 0x800C

/* Number of Bad Packets */
#define CABLE_REG_NUM_BADPKTS 0x800D

/* Number of Byte Errors */
#define CABLE_REG_NUM_BYTE_ERRS 0x800E

/* Number of Bit Errors */
#define CABLE_REG_NUM_BIT_ERRS 0x800F

/* Length BER averaging */
#define CABLE_REG_NUM_SECS_BER_AVERAGE 0x8010

/* Average BER at Reed Solomon */
#define CABLE_REG_RS_AVERAGE_BER 0x8011

/* Average PER at Reed Solomon */
#define CABLE_REG_RS_AVERAGE_PER 0x8012

/* Average SNR at Equaliser */
#define CABLE_REG_EQ_AVERAGE_SNR 0x8013

/* Failure Counters Reset */
#define CABLE_REG_FAILURE_COUNTERS_RESET 0x8014

/* Number Coarse Symbol Timing Failures */
#define CABLE_REG_NUM_COARSE_SYMTIM_FAILURE 0x8015

/* Number Fine Symbol Timing Failures */
#define CABLE_REG_NUM_FINE_SYMTIM_FAILURE 0x8016

/* Number Carrier Sync Failures */
#define CABLE_REG_NUM_CARRSYNC_FAILURE 0x8017

/* Number Failures from unsupported CDI mode */
#define CABLE_REG_NUM_CDI_MODE_FAILURE 0x8018

/* Number Spectrum Inversion Search Failures */
#define CABLE_REG_NUM_SPECINV_SEARCH_FAILURE 0x8019

/* Number Failures from unsupported TS rate */
#define CABLE_REG_NUM_TS_RATE_FAILURE 0x801A

/* Number Failures from PER */
#define CABLE_REG_NUM_PER_FAILURE 0x801B

/* Number Failures from signal dropout */
#define CABLE_REG_NUM_SIGNAL_DROPOUT_FAILURE 0x801C

/* Last Failure Case */
#define CABLE_REG_LAST_FAILURE 0x801D

/* Core Clock Rate */
#define CABLE_REG_CORE_CLK 0x801E

/* QAM Search Enable */
#define CABLE_REG_QAM_SEARCH_ENABLE 0x801F

/* Fixed QAM Size */
#define CABLE_REG_QAM_FIXED 0x8020

/* Spectrum Inversion Search Enable */
#define CABLE_REG_SPECINV_SEARCH_ENABLE 0x8021

/* Spectrum Inversion */
#define CABLE_REG_SPECTRUM_INVERSION 0x8022

/* Number of Byte Errors in Bad Packets */
#define CABLE_REG_BYTE_ERR_BADPKTS 0x8023

/* Number of Bit Errors in Bad Packets */
#define CABLE_REG_BIT_ERR_BADPKTS 0x8024

/* Percentage of Bad Packets in Bad Set */
#define CABLE_REG_PERCENT_BADPKTS_BADSET 0x8025

/* Set Error Rate for Failure */
#define CABLE_REG_SER_FAILURE 0x8026

/* J83B Interleaver Level */
#define CABLE_REG_INTL_LEVEL 0x8027

/* Phase Tracker Loop Gain 64QAM */
#define CABLE_REG_PTGAIN_64QAM 0x8028

/* No comments */
#define CABLE_REG_PTGAIN_256QAM 0x8029

/* Performance tuning DAGC Power */
#define CABLE_REG_TUNE_DAGC_POWER  0x802A

/* Performance tuning Equalizer update rate */
#define CABLE_REG_TUNE_EQ_UPDATE_STEPSIZE  0x802B

/* Coarse symbol timing mean to peak FFT power ratio threshold */
#define CABLE_REG_CST_PEAK_TO_MEAN_THRESHOLD  0x802C

/* Total number of registers for cable */
#define CABLE_REG_TOTALREG ((45) + TV_REG_NUM_COMMON_REG)


#endif /* _j83b_H_ */

