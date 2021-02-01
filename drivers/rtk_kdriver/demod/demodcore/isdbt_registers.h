/**** THIS FILE IS AUTO GENRATED BY THE xml2reg TOOL ****/

#ifndef _isdbt_H_
#define _isdbt_H_


/* System control bits */
#define ISDBT_REG_CTRL 0x8000

/* Set SubChannel Number */
#define ISDBT_REG_TUN_SUBCHANNEL 0x8001

/* Partial Reception Flag */
#define ISDBT_REG_TUN_PARTIAL_RECEPTION 0x8002

/* Set tune ISDBT Mode */
#define ISDBT_REG_TUN_MODE 0x8003

/* Set tune Guard fraction denominator interval */
#define ISDBT_REG_TUN_GUARD 0x8004

/* Modulation  */
#define ISDBT_REG_TUN_MOD_A 0x8005

/* Code rate  */
#define ISDBT_REG_TUN_CODE_RATE_A 0x8006

/* Interleaving Length Identities */
#define ISDBT_REG_TUN_INTERLEAVER_A 0x8007

/* Number of segments */
#define ISDBT_REG_TUN_SEGS_A 0x8008

/* Modulation  */
#define ISDBT_REG_TUN_MOD_B 0x8009

/* Code rate  */
#define ISDBT_REG_TUN_CODE_RATE_B 0x800A

/* Interleaving Length Identities */
#define ISDBT_REG_TUN_INTERLEAVER_B 0x800B

/* Number of segments */
#define ISDBT_REG_TUN_SEGS_B 0x800C

/* Modulation  */
#define ISDBT_REG_TUN_MOD_C 0x800D

/* Code rate  */
#define ISDBT_REG_TUN_CODE_RATE_C 0x800E

/* Interleaving Length Identities */
#define ISDBT_REG_TUN_INTERLEAVER_C 0x800F

/* Number of segments */
#define ISDBT_REG_TUN_SEGS_C 0x8010

/* Start Flag Emergency Alarm */
#define ISDBT_REG_EAF 0x8011

/* Number of TS RS packet counted - state demodulating */
#define ISDBT_REG_STAT_TS_PKT_COUNT_A 0x8012

/* Number of RS un-correctable packets (TEI ) - state demodulating */
#define ISDBT_REG_STAT_TS_BAD_PKT_COUNT_A 0x8013

/* Number of RS corrected error (bytes) - state demodulating */
#define ISDBT_REG_STAT_TS_BYTE_ERRS_A 0x8014

/* Number of RS corrected bit errors - state demodulating */
#define ISDBT_REG_STAT_TS_BIT_ERRS_A 0x8015

/* Number of TS RS packet counted - state demodulating */
#define ISDBT_REG_STAT_TS_PKT_COUNT_B 0x8016

/* Number of RS un-correctable packets (TEI ) - state demodulating */
#define ISDBT_REG_STAT_TS_BAD_PKT_COUNT_B 0x8017

/* Number of RS corrected error (bytes) - state demodulating */
#define ISDBT_REG_STAT_TS_BYTE_ERRS_B 0x8018

/* Number of RS corrected bit errors - state demodulating */
#define ISDBT_REG_STAT_TS_BIT_ERRS_B 0x8019

/* Number of TS RS packet counted - state demodulating */
#define ISDBT_REG_STAT_TS_PKT_COUNT_C 0x801A

/* Number of RS un-correctable packets (TEI ) - state demodulating */
#define ISDBT_REG_STAT_TS_BAD_PKT_COUNT_C 0x801B

/* Number of RS corrected error (bytes) - state demodulating */
#define ISDBT_REG_STAT_TS_BYTE_ERRS_C 0x801C

/* Number of RS corrected bit errors - state demodulating */
#define ISDBT_REG_STAT_TS_BIT_ERRS_C 0x801D

/* Number of time the PHY has re-acquired due to loss of signal */
#define ISDBT_REG_STAT_NUM_REACQ 0x801E

/* Signal to Noise ratio (dB) */
#define ISDBT_REG_STAT_SNR 0x801F

/* Carrier acquisition offset */
#define ISDBT_REG_STAT_CARRIER_ACQUISITION_OFFSET 0x8020

/* Carrier tracking offset */
#define ISDBT_REG_STAT_CARRIER_TRACKING_OFFSET 0x8021

/* AGC control level  */
#define ISDBT_REG_STAT_IF_AGC_LEVEL 0x8022

/* Integration period for error-rate */
#define ISDBT_REG_NUM_SECONDS_BER_AVERAGING 0x8023

/* Viterbi error rate - state demodulating */
#define ISDBT_REG_VITERBI_BER_A 0x8024

/* Long term pre-RS bit error rate */
#define ISDBT_REG_RS_BER_A 0x8025

/* Long term transport stream packet-error rate */
#define ISDBT_REG_TS_PER_A 0x8026

/* Viterbi error rate - state demodulating */
#define ISDBT_REG_VITERBI_BER_B 0x8027

/* Long term pre-RS bit error rate */
#define ISDBT_REG_RS_BER_B 0x8028

/* Long term transport stream packet-error rate */
#define ISDBT_REG_TS_PER_B 0x8029

/* Viterbi error rate - state demodulating */
#define ISDBT_REG_VITERBI_BER_C 0x802A

/* Long term pre-RS bit error rate */
#define ISDBT_REG_RS_BER_C 0x802B

/* Long term transport stream packet-error rate */
#define ISDBT_REG_TS_PER_C 0x802C

/* Failure code */
#define ISDBT_REG_FAILURE_CODE 0x802D

/* Demodulation failure PER timeout count */
#define ISDBT_REG_DEMOD_FAILURE_COUNT_PER_TIMEOUT 0x802E

/* Count of failures that are not caused by PER timeouts. */
#define ISDBT_REG_FAILURE_COUNT_OTHER 0x802F

/* Count of number of received TMCCs. */
#define ISDBT_REG_TMCC_COUNT 0x8030

/* Count of number of good TMCC decodes. */
#define ISDBT_REG_TMCC_GOOD_DECODE_COUNT 0x8031

/* Write to this command register to reset the TMCC counts registers */
#define ISDBT_REG_TMCC_COUNTS_RESET 0x8032

/* Channel offset in Hz of known CCI. */
#define ISDBT_REG_CHANNEL_INTERFERER_OFFSET_HZ 0x8033

/* Total number of registers for isdbt */
#define ISDBT_REG_TOTALREG ((52) + TV_REG_NUM_COMMON_REG)


#endif /* _isdbt_H_ */

