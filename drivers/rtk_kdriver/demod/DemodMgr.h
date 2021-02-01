#ifndef _DEMOD_MGR_H_
#define _DEMOD_MGR_H_

#include "demod_cmd.h"
#include <mach/rtk_log.h>

typedef struct {
	unsigned char m_addr;
	unsigned char m_output_mode;
	unsigned char m_output_freq;
} RTK_DEMOD_CONSTRUCTORS;

typedef struct {
	unsigned char sys;
	TV_SIG_INFO pSigInfo;
} RTK_DEMOD_SETTVSYSEX;

typedef struct {
	unsigned long   freq;               // frequency (Hz)
	unsigned char   inversion;          // inversion
	unsigned char   agc_pola;       // postive agc gain, 1: postive, 0:negative
} RTK_DEMOD_SETIF;

typedef struct {
	unsigned long   mode;               // frequency (Hz)
} RTK_DEMOD_SETMODE;

typedef struct {
	unsigned char mode;
	unsigned char data_order : 1;   // 0 : bit 7 is MSB, 1 : bit 7 is LSB (Parallel)
	unsigned char datapin  : 1;     // 0 : MSB First,   1 : LSB First (Serial)
	unsigned char err_pol  : 1;     // 0 : Active High, 1 : Active Low
	unsigned char sync_pol : 1;     // 0 : Active High, 1 : Active Low
	unsigned char val_pol  : 1;     // 0 : Active High, 1 : Active Low
	unsigned char clk_pol  : 1;     // 0 : Latch On Rising Edge, 1 : Latch On Falling Edge
	unsigned char internal_demod_input : 1;  // used to enable internal demod input
	unsigned char strength_mode;
	unsigned char tsOutEn : 1;
} RTK_DEMOD_SET_TS_MODE;

typedef struct {
	unsigned char lock;
} RTK_DEMOD_GET_LOCK;

typedef struct {
	unsigned char WaitSignalLock;
	int           return_value;
} RTK_DEMOD_SET_ACQ_SIG;

typedef struct {
	unsigned long   mode;               // frequency (Hz)
} RTK_DEMOD_SET_TVMODE;

typedef struct {
	unsigned char debug_mode;
} RTK_DEMOD_GET_DEBUG_INFO;

typedef struct {
	unsigned short  id;
	TV_SYSTEM       std;
	unsigned long   step_freq;
	unsigned long   if_freq;
	unsigned char   if_inversion;
	unsigned char   if_agc_pola;       // postive agc gain, 1: postive, 0:negative
	unsigned long   min_freq;
	unsigned long   max_freq;
	unsigned long   lowband_midband_limit_freq;  // The limit frequency (in Hz) between low-band and mid-band.
	unsigned long   midband_highband_limit_freq; // The limit frequency (in Hz) between mid-band and high-band.
} RTK_DEMOD_SET_TVPARA;

typedef struct {
	unsigned long   snr;
	unsigned long           ber;
	unsigned long           per;
	unsigned char	iter;
	unsigned long   	ucblocks;
	unsigned char   	strength;
	unsigned char   	quality;
	signed long 	rflevel;
	unsigned long	     dbuvPower;
	unsigned long   	agc;
	unsigned char       nosig;
	unsigned char       trlock;
	unsigned char       inner;

	struct {
		unsigned long ber_num;
		unsigned long ber_den;
	} layer_ber;

	struct {
		unsigned long per_num;
		unsigned long per_den;
	} layer_per;

	unsigned int DemodFwVersion;
	unsigned char   emergency_flag;
} TV_SIG_QUAL_KERNEL;

typedef struct {
	int            id;
	TV_SIG_QUAL_KERNEL            pQuality;
} RTK_DEMOD_GET_QUALITY;

typedef struct {
	long                   Offset;
} RTK_DEMOD_GET_CROFFSET;

typedef struct {
	unsigned char Standard;
	unsigned char Modulation;
	unsigned char CodeRate;
	unsigned char PilotOnOff;
	unsigned char Inverse;
} RTK_DEMOD_GET_CHANNELINFO;

typedef struct {
	unsigned int   IcName;
	unsigned int   IcVersion;
	unsigned int   PGAMode;
	unsigned int   PGAGain;
	unsigned int   IfPathType;
} RTK_DEMOD_GET_DEMOD_INFO;

typedef struct {
	unsigned int onoff;
} RTK_DEMOD_SET_DISEQC_22K;

typedef struct {
	unsigned int length;
	unsigned char data[10];
} RTK_DEMOD_SET_DISEQC_CMD;


typedef struct {
	DISEQC_TONE_MODE mode;
} RTK_DEMOD_SET_DISEQC_TONEBURST;

typedef struct {
	unsigned int StartFreqMhz;
    unsigned int EndFreqMhz;
} RTK_DEMOD_BLINDSCAN_INIT;

typedef struct {
	unsigned int bBlindScanEnd;
} RTK_DEMOD_BLINDSCAN_NEXTFREQ;

typedef struct {
	unsigned int TunerCenterFreqMhz;
    unsigned int TunerCutOffFreqKhz;
} RTK_DEMOD_BLINDSCAN_GET_TUNERFREQ;

typedef struct {
	unsigned int FreqMhz;
    unsigned int SymbolRateKhz;
} RTK_DEMOD_BLINDSCAN_GET_FOUNDTP;

typedef struct {
	unsigned char Status;
    unsigned int bBlindScanLock;
} RTK_DEMOD_BLINDSCAN_GET_STATUS;

typedef struct {
	unsigned int SymbolRate;
    int Fcfo;
    unsigned char bTpLock;
} RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL;

typedef struct {
	unsigned int RegAddr;
	unsigned int RegValue;
} RTK_DEMOD_GET_REG_DATA;

typedef struct {
	unsigned int RegAddr;
	unsigned int RegValue;
} RTK_DEMOD_SET_REG_DATA;

typedef struct {
	unsigned char Mode;
} RTK_DEMOD_SET_TUNER_INPUT;

typedef union {
	TV_MODULATION       mod;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned char   level;      // it should be 8 or 16
	} vsb;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned short  constellation;
	} psk;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned int   bandwidth;
		unsigned char   hierarchy;
		unsigned short  constellation;
		unsigned char   alpha;
		unsigned char   code_rate_hp;
		unsigned char   code_rate_lp;
		unsigned char   guard_interval;
		unsigned char   fft_mode;
		unsigned int  cell_ID;
		unsigned char  bSpectrumInv;
		unsigned char  bProfileHP;

	} ofdm;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned short   constellation;
		unsigned char    spectrum_inverse;
	} qam;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned short   constellation;
		unsigned long    symbol_rate;
		unsigned char    alpha;
		unsigned char    spectrum_inverse;
	} dvbc_qam;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		DTMB_OFDM_TIME_INTERLEAVER_MODE_E      tim;
		DTMB_OFDM_CARRIER_MODE                 carrier_mode;
		unsigned int guard_interval;

		struct {
			DTMB_OFDM_PSEUDO_NOISE_E           mode;
			DTMB_OFDM_PSEUDO_NOISE_SEQUENCE_E  seq;
		} pn;

		struct {
			DTMB_OFDM_FEC_RATE_E               rate;
			DTMB_OFDM_CONSTELLATION_E          constellation;
		} fec;

		unsigned int usrData;  // used to store device specific or user-defined data
	} dtmb_ofdm;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned long    symbol_rate;
		unsigned char    zapping_mode;
		unsigned char    modulation;
		unsigned char    code_rate;
		unsigned char    pilot_onoff;
		unsigned char    spec_invert;
		LNB_MODE         lnb_mode;
		unsigned char 	 DiseqcCmdCnt;
		unsigned char 	 DiseqcCmd[64];
		unsigned char 	 IsBlindsearch;
	} dvbs;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned long    symbol_rate;
		unsigned char    spectrum_inv: 1;
		LNB_MODE         lnb_mode;
	} abss;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned int   bandwidth;
		unsigned char   hierarchy;
		unsigned short  constellation;
		unsigned char   alpha;
		unsigned char   code_rate_hp;
		unsigned char   code_rate_lp;
		unsigned char   guard_interval;
		unsigned char   fft_mode;
		unsigned char    plp_cnt;
		unsigned char    plp[256];
		int plp_type[256];
		int plp_select;
		unsigned char profile;
		unsigned char fec_type;
		unsigned int cell_ID;
		unsigned char  bSpectrumInv;
	       unsigned char  bProfileHP;	 
		
	} dvbt2_ofdm;

	struct {
		unsigned char bwExt;
		unsigned char s1;
		unsigned char s2;
		unsigned char fftMode;
		unsigned char gi;
		unsigned char papr;
		unsigned char mod;
		unsigned char code_rate;
		unsigned char pp;
		unsigned char version;
		int cell_ID;
	} dvbt2_L1pre;

	struct {
		unsigned long fefLength;
	} dvbt2_L1post;

	struct {
		unsigned char   tx_id_availability;
		unsigned int    cell_id;
		unsigned int    network_id;
		unsigned int    t2_system_id;
	} dvbt2_TXID;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned long    segment_num;
		unsigned long    subchannel_num;
		unsigned int trans_mode;
		unsigned int guard_interval;
		unsigned char  bSpectrumInv;

		struct isdbt_layer_kernal {
			unsigned int    segment_num;
			unsigned short constellation;
			unsigned char 	code_rate;
			unsigned int    time_intlv;

		} layer[3];
	} isdbt;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
	
		unsigned long       symbol_rate;
		LNB_MODE            lnb_mode;
		unsigned short      ts_id;
	} isdbs;

	struct {
		TV_MODULATION       mod;
		unsigned int scan_mode;      /* 0:normal mode, 1:scan mode, 10:DEMOD mode changed only, 20:Frontend mode changed*/
			
	} analog;

       struct {
		TV_MODULATION       mod;
		char*            fname;
	} ts_file;

	struct {
		TV_MODULATION       mod;
	
		char*            pVirtualAddr;
		char*            PhyAddr;
		unsigned long    Size;
	} m2m;

	struct {
		TV_MODULATION       mod;
	
		int              port;
		char             addr[16];	//IPV4
	} rtsp;

} RTK_DEMOD_GET_SIGNAL_INFO;

typedef struct _RTK_DEMOD_DATA {
	struct semaphore sem ;          /* mutual exclusion semaphore     */
	struct cdev      cdev ;         /* Char device structure          */
	unsigned char    filter_flag ;	/* set to 1 if received section/pes packet*/
	struct file      *fpInit ;       /* which fp to init sdec module can un-init sdec while init-process is killed*/
	DEMOD*           m_pDemod;
	COMM*            m_comm;
	TUNER*           m_pTuner;

	RTK_DEMOD_CONSTRUCTORS demod_init_data;
	RTK_DEMOD_SETTVSYSEX set_tv_sys_ex_data;
	RTK_DEMOD_SETIF set_if_data;
	RTK_DEMOD_SETMODE set_mode_data;
	RTK_DEMOD_SET_TS_MODE set_ts_mode_data;
	RTK_DEMOD_SET_TVMODE set_tv_mode_data;
	RTK_DEMOD_SET_ACQ_SIG set_acq_sig_data;
	RTK_DEMOD_GET_LOCK get_lock_data;
	RTK_DEMOD_SET_TVPARA set_tv_para;
	RTK_DEMOD_GET_QUALITY get_quality;
	RTK_DEMOD_GET_DEBUG_INFO get_debug_info_data;
	RTK_DEMOD_GET_DEMOD_INFO   get_demod_info_data;
	RTK_DEMOD_GET_REG_DATA   get_reg_data;
	RTK_DEMOD_SET_REG_DATA   set_reg_data;
	RTK_DEMOD_SET_DISEQC_22K   set_diseqc_22k_data;
	RTK_DEMOD_SET_DISEQC_CMD   set_diseqc_cmd_data;
	RTK_DEMOD_SET_DISEQC_TONEBURST   set_diseqc_toneburst_data;
	RTK_DEMOD_SET_TUNER_INPUT   set_tuner_input;
	RTK_DEMOD_GET_SIGNAL_INFO get_signal_info_data;
	RTK_DEMOD_GET_CROFFSET   get_croffset_data;
	RTK_DEMOD_GET_CHANNELINFO    get_channelinfo_data;
	RTK_DEMOD_BLINDSCAN_INIT   blindscan_init_data;
	RTK_DEMOD_BLINDSCAN_NEXTFREQ   blindscan_nextfreq_data;
	RTK_DEMOD_BLINDSCAN_GET_TUNERFREQ   blindscan_get_tunerfreq_data;
	RTK_DEMOD_BLINDSCAN_GET_FOUNDTP   blindscan_get_foundtp_data;
	RTK_DEMOD_BLINDSCAN_GET_STATUS   blindscan_get_status_data;
	RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL   blindscan_acquire_signal_data;
} SRTK_DEMOD_DATA, *PS_RTK_DEMOD_DATA;



#define DEMOD_MGR_CALLER(fmt, args...)         rtd_printk_demod(KERN_DEBUG, "DEMO", "DTV_MGR_CALLER, " fmt, ##args);
#define DEMOD_MGR_DBG(fmt, args...)            rtd_printk_demod(KERN_DEBUG, "DEMO", "DTV_MGR_DEBUG, " fmt, ##args);
#define DEMOD_MGR_INFO(fmt, args...)           rtd_printk_demod(KERN_INFO, "DEMO", "DTV_MGR_INFO, " fmt, ##args);
#define DEMOD_MGR_WARNING(fmt, args...)        rtd_printk_demod(KERN_WARNING, "DEMO", "DTV_MGR_WARNING, " fmt, ##args);
#define DEMOD_MGR_EMERG_FORCE(fmt, args...)  rtd_printk_demod_force(KERN_EMERG, "DEMO", "DTV_MGR_WARNING, " fmt, ##args);


#endif

