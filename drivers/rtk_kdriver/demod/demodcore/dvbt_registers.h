/**** THIS FILE IS AUTO GENRATED BY THE xml2reg TOOL ****/

#ifndef _dvbt_H_
#define _dvbt_H_

/* Select modes to detect */
#define DVBT_REG_DETECT_MASK 0x8000

/* Set/read FFT size */
#define DVBT_REG_TUN_FFT 0x8001

/* Set/read guard interval */
#define DVBT_REG_TUN_GUARD 0x8002

/* Set/read modulation */
#define DVBT_REG_TUN_MOD 0x8003

/* Set/read code rate */
#define DVBT_REG_TUN_CODE_RATE 0x8004

/* Set/read hierarchical alpha */
#define DVBT_REG_TUN_ALPHA 0x8005

/* Set/read interleaver mode */
#define DVBT_REG_TUN_INTERLEAVER 0x8006

/* Select stream of hierarchical multiplex */
#define DVBT_REG_TUN_HIERARCHICAL 0x8007

/* Set/read spectrum inversion */
#define DVBT_REG_TUN_SPECT_INV 0x8008

/* Update or apply calibration values */
#define DVBT_REG_CALIB_CTRL 0x8009

/* Estimate of crystal frequency offset */
#define DVBT_REG_CALIB_XTAL_OFFSET 0x800A

/* Update or reset status */
#define DVBT_REG_STAT_CTRL 0x800B

/* Count of status updates */
#define DVBT_REG_STAT_UPDATE 0x800C

/* Signal strength indicator */
#define DVBT_REG_STAT_SSI 0x800D

/* Signal to Noise ratio (dB) */
#define DVBT_REG_STAT_SNR 0x800E

/* Carrier offset (Hz) */
#define DVBT_REG_STAT_CARRIER_OFFSET 0x800F

/* Number of TS packets counted */
#define DVBT_REG_STAT_TS_PKT_COUNT 0x8010

/* Number of un-correctable TS packets detected */
#define DVBT_REG_STAT_TS_BAD_PKT_COUNT 0x8011

/* Number of byte errors detected in transport stream packets */
#define DVBT_REG_STAT_TS_BYTE_ERRS 0x8012

/* Number of bit errors detected in transport stream packets */
#define DVBT_REG_STAT_TS_BIT_ERRS 0x8013

/* Viterbi bit-error-rate */
#define DVBT_REG_STAT_VITERBI_BER 0x8014

/* Transport stream sync indicator */
#define DVBT_REG_STAT_TS_SYNC 0x8015

/* TPS sync indicator */
#define DVBT_REG_STAT_TPS_SYNC 0x8016

/* IF AGC control level */
#define DVBT_REG_STAT_IF_AGC_LEVEL 0x8017

/* Number of OFDM symbols received */
#define DVBT_REG_STAT_NUM_SYMBOLS 0x8018

/* Number of time the PHY has re-acquired due to loss of signal */
#define DVBT_REG_STAT_NUM_REACQ 0x8019

/* Indication of ACI detection */
#define DVBT_REG_STAT_ACI_DETECTED 0x801A

/* Cell ID */
#define DVBT_REG_STAT_CELL_ID 0x8022

/* Integration period for error-rate counters */
#define DVBT_REG_BER_PERIOD 0x801B

/* Counter of error rate updates */
#define DVBT_REG_BER_UPDATE 0x801C

/* Reed-Solomon bit error rate */
#define DVBT_REG_BER_RS_BER 0x801D

/* Transport stream packet-error rate */
#define DVBT_REG_BER_TS_PER 0x801E

/* Signal quality indicator */
#define DVBT_REG_BER_SQI 0x801F

/* Viterbi iterative mode elimination coefficients for pass 2. */
#define DVBT_REG_ELIM_COEFF_VITERBI_ITER_MODE_PASS2 0x8020

/* Viterbi iterative mode elimination coefficients for pass 3. */
#define DVBT_REG_ELIM_COEFF_VITERBI_ITER_MODE_PASS3 0x8021

/* Total number of registers for dvbt */
#define DVBT_REG_TOTALREG ((35) + TV_REG_NUM_COMMON_REG)

/* DVBT Major and Minor version numbers */
//#define DVBT_VERSION_MAJOR 0x01
//#define DVBT_VERSION_MINOR 0x00

#endif /* _dvbt_H_ */

