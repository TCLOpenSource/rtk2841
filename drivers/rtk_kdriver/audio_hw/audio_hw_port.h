#ifndef AUDIO_HW_PORT_H
#define AUDIO_HW_PORT_H

#include <linux/kernel.h>
#include <linux/delay.h>
#include <mach/io.h>

/* for enable debug log */
#define  __ALOG_ENABLE

#include "audio_hw_log.h"

/* true/false */
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* io */
#ifndef IoReg_Read32
#define IoReg_Read32(addr)		rtd_inl((addr))
#endif

#ifndef IoReg_Write32
#define IoReg_Write32(addr, value)	rtd_outl((addr), (value))
#endif

/*
 * a proper sleep fucntion 
 *  
 * 10us > 		using udelay()
 * 10us - 20ms		using usleep_range() 
 * 10ms <		msleep() or msleep_interruptible()
 *  
 * refer https://www.kernel.org/doc/Documentation/timers/timers-howto.txt 
 */
#define audio_hw_usleep(usecs) \
(void)({ \
	unsigned long us___ = (unsigned long)(usecs); \
	if (us___ < 10) \
		udelay(us___); \
	else if (us___ >= 10 && us___ <= 20000) \
		usleep_range(us___, us___); \
	else \
		msleep_interruptible(DIV_ROUND_UP(us___, 1000)); \
	(void)us___; \
})


/************************* Audio HW Config *************************/ 
/* IC Version */
#define	RTD284X												/* Support AIO1, HP */
#undef	RTD289X											/* Support AIO1, AIO2, HP */
#undef	RTD287X											/* Support AIO1, AIO2, HP */

/* Audio Function */
#undef	SUPPORT_HP_OUT_SWAP					/* only support on Merlin series IC */
#undef	SUPPORT_ADC_DVC							/* For controling analog_in independently */
#undef	SUPPORT_2_SET_ADC						/* For 2 pairs AMIC in */
#undef	SUPPORT_TWO_BAND_DRC						/* For 2band DRC */
#undef	SUPPORT_6_CHANNEL_PRESCALE	/* only support on Merlin series IC */
#undef	SUPPORT_6_CHANNEL_LOUDNESS	/* only support on Merlin series IC */
#undef	SUPPORT_8_CHANNEL_I2S_OUT		/* only support on Merlin series IC) */

/* AQ relevant */
#define	NO_USE_HW_AQ								/* HW AQ switch */
#define	USE_ATV_SW_MUTE							/* ATV SW/HW Mute */
#undef	USE_SW_SOUND_SURROUND				/* SW sound surround*/
#define	MAX_EQ_BAND_NUM 9						/* 1LPF + 7BPF + 1HPF */

/* Custom Config */
#undef  TV001_BOARD

#undef	ENABLE_AUDIO_BACKTRACE_DUMP	/* dump stack */

#define	AUDIO_USER_CONFIG_TV001 0x0
#define	AUDIO_USER_CONFIG_TV002 0x1
#define	AUDIO_USER_CONFIG_TV003 0x2
#define	AUDIO_USER_CONFIG_UNKNOWN 0xF

extern int32_t g_user_config;

#endif
