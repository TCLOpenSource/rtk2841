#ifndef __CRT_API__
#define __CRT_API__
#include <linux/spinlock.h>
#include <linux/hardirq.h>

/* support module list */
enum CRT_MODULE {
	USB    = 0x00000001,
	IrDA   = 0x00000002,
	I2C    = 0x00000004,
	UART   = 0x00000008,
	SE     = 0x00000010,
	NAND   = 0x00000020,
	MD     = 0x00000040,
	PWM    = 0x00000080,
	PCMCIA = 0x00000100,
	GPIO   = 0x00000200,
	EMMC   = 0x00000400,
	SDIO   = 0x00000800,
	SMC    = 0x00001000,
	CP     = 0x00002000,
	TP     = 0x00004000,
	TPOUT  = 0x00004001,
	MHL    = 0x00008000,
	HDMI   = 0x00010000,
	GDMA   = 0x00020000,
	VBI    = 0x00040000,
	GPU    = 0x00400000,
	DOLBY_HDR    = 0x00800000,
	DISEQC = 0x02000000,
	LSADC    = 0x40000000,
	CEC    = 0x80000000,
	ETH    = 0x01000000,
	
	ANADEMOD   		= 0x00080000,
	DIGDEMOD    		= 0x00100001,
	DIGDEMOD_ADC_EN  	= 0x00100002,
	DIGDEMOD_IMG_EN   = 0x00100003,
	DIGDEMOD_HDIC_EN	= 0x00100004,
	DIGDEMOD_RTK_EN	= 0x00100005,

	SCALER_ADC_CLK_1 = 0x00080001,
	SCALER_AUTO_CLK_1 = 0x00080002,
	SCALER_AUTO_CLK_2 = 0x00080003,
	SCALER_VFEDEV_1 = 0x00080004,
	SCALER_TVE_1 = 0x00080010,
	SCALER_TVE_2 = 0x00080011,
	SCALER_TVE_3 = 0x00080012,
	SCALER_TVE_4 = 0x00080013,
	SCALER_TVE_5 = 0x00080014,

	SCALER_VDC_1 = 0x00080020,
	SCALER_VDC_2 = 0x00080021,
	SCALER_VDC_3 = 0x00080022,
	SCALER_VDC_4 = 0x00080023,
	SCALER_VDC_5 = 0x00080024,
	SCALER_VDC_6 = 0x00080025,
	SCALER_VDC_7 = 0x00080026,
	SCALER_VDC_8 = 0x00080027,
	SCALER_VDC_9 = 0x00080028,
	SCALER_VDC_10 = 0x00080029,

	SCALER_VDC_INPUT_1 = 0x00080031,
	SCALER_VDC_INPUT_2 = 0x00080032,
	SCALER_VDC_INPUT_3 = 0x00080033,

	SCALER_VO_1 = 0x00080044,
	THERMAL_SENSOR = 0x00080055,
    
    
};


enum CRT_CLK {
	CLK_ON = 0,
	CLK_OFF = 1,
};

enum CRT_RET {
	CRT_SUCCESS = 0,
	CRT_FAIL = 1,
};

/* support nand clock info*/
enum NF_CLK_CTRL {
	NF_CLK_SET = 0,
	NF_CLK_GET = 1,
};

struct NF_CLK_INFO {
	unsigned int nf_clksel;		/*nf_clksel value*/
	unsigned char clk_is_on;	/*0-> clk off; 1-> clk on */
	enum NF_CLK_CTRL clk_set_or_get;	/*0-> set clk; 1-> get clk info*/
};


/* hardware semaphore API*/
void hw_semaphore_try_lock(void);
void hw_semaphore_unlock(void);

/* module crt register access API */
int APLL_ADC_clock(enum CRT_CLK clken);
int USB_CriticalRegister(enum CRT_CLK clken, void *private_data);
int IrDA_CriticalRegister(enum CRT_CLK clken, void *private_data);
int I2C_CriticalRegister(enum CRT_CLK clken, void *private_data);
int UART_CriticalRegister(enum CRT_CLK clken, void *private_data);
int SE_CriticalRegister(enum CRT_CLK clken);
int NAND_CriticalRegister(enum CRT_CLK clken, void *private_data);
int MD_CriticalRegister(enum CRT_CLK clken);
int DDEMOD_CriticalRegister(enum CRT_CLK clken);
int DiseqC_CriticalRegister(enum CRT_CLK clken);
int PWM_CriticalRegister(enum CRT_CLK clken, void *private_data);
int PCMCIA_CriticalRegister(enum CRT_CLK clken);
int EMMC_CriticalRegister(enum CRT_CLK clken, void *private_data);
int SDIO_CriticalRegister(enum CRT_CLK clken, void *private_data);
int SMC_CriticalRegister(enum CRT_CLK clken);
int CP_CriticalRegister(enum CRT_CLK clken);
int TP_CriticalRegister(enum CRT_CLK clken);
int MHL_CriticalRegister(enum CRT_CLK clken);
int HDMI_CriticalRegister(enum CRT_CLK clken);
int GDMA_CriticalRegister(enum CRT_CLK clken, void *private_data);
int DOLBY_HDR_CriticalRegister(enum CRT_CLK clken, void *private_data);
int VBI_CriticalRegister(enum CRT_CLK clken);
int ETH_CriticalRegister(enum CRT_CLK clken, void *private_data);
int ADC_CriticalRegister(enum CRT_CLK clken);
int Auto_CriticalRegister(enum CRT_CLK clken);
int Auto2_CriticalRegister(enum CRT_CLK clken);
int VO_CriticalRegister(enum CRT_CLK clken);
int VFEDEV_CriticalRegister(enum CRT_CLK clken);
int TVE1_CriticalRegister(enum CRT_CLK clken);
int TVE2_CriticalRegister(enum CRT_CLK clken);
int TVE3_CriticalRegister(enum CRT_CLK clken);
int TVE4_CriticalRegister(enum CRT_CLK clken);
int TVE5_CriticalRegister(enum CRT_CLK clken);
int VDC1_CriticalRegister(enum CRT_CLK clken);
int VDC2_CriticalRegister(enum CRT_CLK clken);
//int VDC3_CriticalRegister(enum CRT_CLK clken);
int VDC3_CriticalRegister(enum CRT_CLK clken, void *private_data);
int VDC4_CriticalRegister(enum CRT_CLK clken, void *private_data);
int VDC5_CriticalRegister(enum CRT_CLK clken, void *private_data);
int VDC6_CriticalRegister(enum CRT_CLK clken, void *private_data);
int VDC7_CriticalRegister(enum CRT_CLK clken);
int VDC8_CriticalRegister(enum CRT_CLK clken);
int VDC9_CriticalRegister(enum CRT_CLK clken, void *private_data);
int VDCInput2_CriticalRegister(enum CRT_CLK clken);
int VDCInput3_CriticalRegister(enum CRT_CLK clken);




/** RTD SW SEMAPHOR **/

#define PLL_27X3_LOCKBIT      BIT(0)
#define AVDIN_IFD_LOCKBIT     BIT(4)
extern void rtd_crt_swsem_unlock(int bit);
extern void rtd_crt_swsem_lock(int bit);
extern int rtd_crt_swsem_trylock(int bit);

extern spinlock_t pll27x3_lock;
extern spinlock_t avdin_lock; 
#define RTD_SWSEM_27x3_LOCK(flag)				\
	do {							\
		if (!in_interrupt())				\
			spin_lock_irqsave(&pll27x3_lock, flag); \
		rtd_crt_swsem_lock(PLL_27X3_LOCKBIT);		\
	} while(0)

#define RTD_SWSEM_27x3_UNLOCK(flag)					\
	do {								\
		rtd_crt_swsem_unlock(PLL_27X3_LOCKBIT);			\
		if (!in_interrupt())					\
			spin_unlock_irqrestore(&pll27x3_lock, flag);	\
	} while(0)

#define RTD_SWSEM_AVDIN_LOCK(flag)				\
	do {							\
		if (!in_interrupt())				\
			spin_lock_irqsave(&avdin_lock, flag);	\
		rtd_crt_swsem_lock(AVDIN_IFD_LOCKBIT);		\
	} while(0);

#define RTD_SWSEM_AVDIN_UNLOCK(flag)				\
	do {							\
		rtd_crt_swsem_unlock(AVDIN_IFD_LOCKBIT);		\
		if (!in_interrupt())				\
			spin_unlock_irqrestore(&avdin_lock, flag);	\
	} while(0)


 
void CRT_CLK_OnOff(enum CRT_MODULE module_ip, enum CRT_CLK clken, void *private_data);
char * CRT_CLK_ModuleName(enum CRT_MODULE module_ip);

/* rtk_crt char device data struct and macro  */
#ifndef CRT_MAJOR
#define CRT_MAJOR 0   /* dynamic major by default */
#endif

#ifndef CRT_NR_DEVS
#define CRT_NR_DEVS 1
#endif

#define CRT_NAME		"crt device"

/* ioctl cmd package struct  */
typedef struct crt_clk_onoff {
	enum CRT_MODULE module_ip;
	enum CRT_CLK clken;
	void *private_data;
} crt_clk_onoff_cmd;

/*
 * Ioctl definitions
 */
#define CRT_IOC_MAGIC  'x'
#define CRT_IOC_CLK_ONOFF 		_IOW(CRT_IOC_MAGIC,  0, crt_clk_onoff_cmd)

#ifdef CONFIG_USB
enum {
	CRT_USB2_VER = 2,
	CRT_USB3_VER = 3,
};
#endif

#endif // __CRT_API__
