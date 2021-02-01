#ifndef _ADEMOD_MGR_H_
#define _ADEMOD_MGR_H_

#include "ademod_cmd.h"

typedef struct
{
   unsigned char m_addr;
   unsigned char m_output_mode;
   unsigned char m_output_freq;
}RTK_ADEMOD_CONSTRUCTORS;

typedef struct
{
   unsigned char sys;
   TV_SIG_INFO sig_info;
}RTK_ADEMOD_SETTVSYSEX;

typedef struct
{
   unsigned long   freq;               // frequency (Hz)
   unsigned char   inversion;          // inversion
   unsigned char   agc_pola;       // postive agc gain, 1: postive, 0:negative
}RTK_ADEMOD_SETIF;

typedef struct
{
   unsigned long   mode;               // frequency (Hz)
}RTK_ADEMOD_SETMODE;

typedef struct
{
   unsigned char mode;
   unsigned char data_order : 1;   // 0 : bit 7 is MSB, 1 : bit 7 is LSB (Parallel)
   unsigned char datapin  : 1;     // 0 : MSB First,   1 : LSB First (Serial)
   unsigned char err_pol  : 1;     // 0 : Active High, 1 : Active Low
   unsigned char sync_pol : 1;     // 0 : Active High, 1 : Active Low
   unsigned char val_pol  : 1;     // 0 : Active High, 1 : Active Low
   unsigned char clk_pol  : 1;     // 0 : Latch On Rising Edge, 1 : Latch On Falling Edge
   unsigned char internal_demod_input : 1;  // used to enable internal demod input
   unsigned char strength_mode;
}RTK_ADEMOD_SET_TS_MODE;

typedef struct
{
   unsigned char lock;
}RTK_ADEMOD_GET_LOCK;

typedef struct
{
   unsigned char WaitSignalLock;
   unsigned char lock;
}RTK_ADEMOD_SET_ACQ_SIG;

typedef struct
{
   unsigned long   mode;               // frequency (Hz)
}RTK_ADEMOD_SET_TVMODE;

typedef struct
{
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
}RTK_ADEMOD_SET_TVPARA;

typedef struct
{
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
}TV_SIG_QUAL_KERNEL;

typedef struct
{
	int            id;
	TV_SIG_QUAL_KERNEL            pQuality;
}RTK_ADEMOD_GET_QUALITY;

typedef struct
{
	long            pOffset;
}RTK_ADEMOD_GET_CARRIEROFFSET;

typedef struct _RTK_ADEMOD_DATA
{
   struct semaphore sem ;          /* mutual exclusion semaphore     */
   struct cdev      cdev ;         /* Char device structure          */
   unsigned char    filter_flag ;	/* set to 1 if received section/pes packet*/
   struct file      *fpInit ;       /* which fp to init sdec module can un-init sdec while init-process is killed*/
   ADEMOD*           m_pADemod;
   TUNER*           m_pTuner;

   RTK_ADEMOD_CONSTRUCTORS ademod_init_data;
   RTK_ADEMOD_SETTVSYSEX set_tv_sys_ex_data;
   RTK_ADEMOD_SETIF set_if_data;
   RTK_ADEMOD_SETMODE set_mode_data;
   RTK_ADEMOD_SET_TS_MODE set_ts_mode_data;
   RTK_ADEMOD_SET_TVMODE set_tv_mode_data;
   RTK_ADEMOD_SET_ACQ_SIG set_acq_sig_data;
   RTK_ADEMOD_GET_LOCK get_lock_data;
   RTK_ADEMOD_SET_TVPARA set_tv_para;
   RTK_ADEMOD_GET_QUALITY get_quality;
   
}SRTK_ADEMOD_DATA,*PS_RTK_ADEMOD_DATA;



#define ADEMOD_MGR_CALLER(fmt, args...)         rtd_printk(KERN_DEBUG, "DEMO", "ATV_MGR_CALLER, " fmt, ##args);
#define ADEMOD_MGR_DBG(fmt, args...)         rtd_printk(KERN_DEBUG, "DEMO", "ATV_MGR_DEBUG, " fmt, ##args);
#define ADEMOD_MGR_INFO(fmt, args...)               rtd_printk(KERN_INFO, "DEMO", "ATV_MGR_INFO, " fmt, ##args);
#define ADEMOD_MGR_WARNING(fmt, args...)        rtd_printk(KERN_WARNING, "DEMO", "ATV_MGR_WARNING, " fmt, ##args);

#endif

