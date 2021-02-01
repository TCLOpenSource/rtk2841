
#ifndef  __PCB_MGR_H__
#define  __PCB_MGR_H__

typedef enum {
    PCB_PIN_TYPE_UNUSED = 0,
	PCB_PIN_TYPE_LSADC = 1,
	PCB_PIN_TYPE_EMCU_GPIO = 2,
	PCB_PIN_TYPE_GPIO = 3,
	PCB_PIN_TYPE_ISO_GPIO = 4,
	PCB_PIN_TYPE_UNIPWM = 5,
	PCB_PIN_TYPE_ISO_UNIPWM = 6,
	PCB_PIN_TYPE_PWM = 7,
	PCB_PIN_TYPE_ISO_PWM = 8,
	PCB_PIN_TYPE_AUDIO = 9,
	PCB_PIN_TYPE_ISO2_GPIO = 10,
	PCB_PIN_TYPE_GPI = 11,
	PCB_PIN_TYPE_GPO = 12,
	PCB_PIN_TYPE_ISO_GPI = 13,
	PCB_PIN_TYPE_ISO_GPO = 14,
	PCB_PIN_TYPE_UNDEF = 0xFF,
} PCB_PIN_TYPE_T;

typedef enum {
	PCB_GPIO_TYPE_INPUT,
	PCB_GPIO_TYPE_OUPUT,
	PCB_GPIO_TYPE_TRI_IO,
	PCB_GPIO_TYPE_UNDEF,
} PCB_GPIO_TYPE_T;

typedef enum {
	PCB_LSADC_TYPE_VOLTAGE,
	PCB_LSADC_TYPE_CURRENT,
	PCB_LSADC_TYPE_UNDEF,
} PCB_LSADC_TYPE_T;


typedef enum {
	PCB_DDC_0 = 0,
	PCB_DDC_1,
	PCB_DDC_2,
	PCB_DDC_3,
	PCB_DDC_UNUSED,
} PCB_DDC_ENUM_T;

typedef enum {
	PCB_I2C_0 = 0,
	PCB_I2C_1,
	PCB_I2C_2,
	PCB_I2C_3,
	PCB_I2C_4,
	PCB_I2C_5,
	PCB_I2C_6,
	PCB_I2C_7,
	PCB_I2C_UNUSED,
} PCB_I2C_ENUM_T;

typedef enum {
	PCB_I2C_TYPE_HW_I2C,
	PCB_I2C_TYPE_GPIO_I2C,
	PCB_I2C_TYPE_UNDEF,
} PCB_I2C_TYPE_T;

typedef enum {
	PCB_I2C_PHY_0 = 0,
	PCB_I2C_PHY_1,
	PCB_I2C_PHY_2,
	PCB_I2C_PHY_3,
	PCB_I2C_PHY_UNUSED,
} PCB_I2C_PHY_T;

typedef enum {
	PCB_I2C_SUB_SRC_0 = 0,
	PCB_I2C_SUB_SRC_1,
	PCB_I2C_SUB_SRC_2,
	PCB_I2C_SUB_SRC_3,
	PCB_I2C_SUB_SRC_4,
	PCB_I2C_SUB_SRC_5,
	PCB_I2C_SUB_SRC_6,
	PCB_I2C_SUB_SRC_7,
	PCB_I2C_SUB_SRC_8,
	PCB_I2C_SUB_SRC_9,
	PCB_I2C_SUB_SRC_10,
	PCB_I2C_SUB_SRC_11,
	PCB_I2C_SUB_SRC_12,
	PCB_I2C_SUB_SRC_13,
	PCB_I2C_SUB_SRC_14,
	PCB_I2C_SUB_SRC_ANY,
} PCB_I2C_SUB_SRC_ENUM_T;

/****************************************************************************/
/*
//TP_SRC
 INTERNAL_DEMOD:[0..3]
 EXTERNAL_TUNER0_SRC:[4..7]
 EXTERNAL_TUNER1_SRC:[8..11]
 EXTERNAL_CAM0_SRC:[12..15]
 EXTERNAL_CAM1_SRC:[16..20]
*/
/****************************************************************************/
#define TP_SRC_INTERNAL_DEMOD_SET(x)               (x&0xf)
#define TP_SRC_EXTERNAL_TUNER0_SET(x)             ((x&0xf)<<4)
#define TP_SRC_EXTERNAL_TUNER1_SET(x)             ((x&0xf)<<8)
#define TP_SRC_EXTERNAL_CAM0_SET(x)                 ((x&0xf)<<12)
#define TP_SRC_EXTERNAL_CAM1_SET(x)                 ((x&0xf)<<16)

typedef enum {
	TP_SRC_0 	= 0,
	TP_SRC_1	= 1,
	TP_SRC_2	= 2,
	TP_SRC_3	= 3,
	TP_SRC_INTERNAL=7,
	TP_SRC_UNUSED
} TP_SRC_TYPE_T;

#define PCB_HW_I2C(phy, src)    (((unsigned long long) (PCB_I2C_TYPE_HW_I2C & 1)<<32) | \
                                 ((unsigned long long) (phy & 0x7) << 4) | \
                                  (unsigned long long) (src & 0xF))

#define PCB_GPIO_I2C(sda, scl)  (((unsigned long long) (PCB_I2C_TYPE_GPIO_I2C & 1)<<32) | \
                                 ((unsigned long long) (sda & 0xFFFF) << 16) | \
                                  (unsigned long long) (scl & 0xFFFF))

#define GET_I2C_TYPE(cfg)       ((cfg >> 32) & 0x1)
#define GET_HW_I2C_PHY(cfg)     ((cfg >> 4)  & 0x7)
#define GET_HW_I2C_SRC(cfg)     (cfg & 0xF)

#define GET_GPIO_I2C_SDA(cfg)   ((cfg >> 16)  & 0xFFFF)
#define GET_GPIO_I2C_SCL(cfg)   (cfg & 0xFFFF)

#ifndef _HDMI_FUN_H

// HDMI enumeration please sync with Platform_Lib/TVScalerControl/hdmiRx/hdmiFun.h
typedef enum {
	HDMI_PHY_PORT0 = 0,
	HDMI_PHY_PORT1,
	HDMI_PHY_PORT2,
	HDMI_PHY_PORT3,
	HDMI_PHY_PORT_NOTUSED
} HDMI_PHY_PORT_T;


typedef enum {
	HDMI_MUX_PORT0 = 0,
	HDMI_MUX_PORT1,
	HDMI_MUX_PORT2,
	HDMI_MUX_PORT3,
	HDMI_MUX_PORT4,
	HDMI_MUX_PORT5,
	HDMI_MUX_PORT6,
	HDMI_MUX_PORT_NOTUSED
} HDMI_MUX_PORT_T;


typedef enum {
	HDMI_EDID_ONCHIP = 0,
	HDMI_EDID_EEPROM,
	HDMI_EDID_I2CMUX,
	HDMI_EDID_DISABLE
} HDMI_EDID_TYPE_T;

typedef enum {
	HDMI_HPD_ONCHIP = 0,
	HDMI_HPD_I2CMUX,
	HDMI_HPD_DISABLE,
} HDMI_HPD_TYPE_T;

typedef enum {
	HDMI_MUX_PS331 = 0,
	HDMI_SWITCH_SiI9199,
	HDMI_MUX_NOUSED,
} HDMI_MUX_IC_T;
#endif  //_HDMI_FUN_H


#define __PIN(type, index, param1, param2, param3, param4, param5, param6)		\
			(((unsigned long long) (type) & 0xFF) | (((unsigned long long) (index) & 0xFF) << 8) | (((unsigned long long) (param1) & 0xFF) << 16) | (((unsigned long long) (param2) & 0xFF) << 24)  |    \
			(((unsigned long long) (param3) & 0xFF) << 32) | (((unsigned long long) (param4) & 0xFF) << 40)  | (((unsigned long long) (param5) & 0xFF) << 48)  | (((unsigned long long) (param6) & 0xFF) << 56))

#define GET_PIN_TYPE(x)		((PCB_PIN_TYPE_T) (x & 0xFF))
#define GET_PIN_INDEX(x)	((unsigned char) ((x >> 8) & 0xFF))
#define GET_PIN_PARAM1(x)	((unsigned char) ((x >> 16) & 0xFF))
#define GET_PIN_PARAM2(x)	((unsigned char) ((x >> 24) & 0xFF))
#define GET_PIN_PARAM3(x)	((unsigned char) ((x >> 32) & 0xFF))
#define GET_PIN_PARAM4(x)	((unsigned char) ((x >> 40) & 0xFF))
#define GET_PIN_PARAM5(x)	((unsigned char) ((x >> 48) & 0xFF))
#define GET_PIN_PARAM6(x)	((unsigned char) ((x >> 56) & 0xFF))

#define GET_LSADC_TYPE(x)			 ((PCB_LSADC_TYPE_T) GET_PIN_PARAM1(x))
#define GET_LSADC_HITVALUE(x)		GET_PIN_PARAM2(x)
#define GET_LSADC_TOLERANCE(x)	 	GET_PIN_PARAM3(x)

#define GET_GPIO_TYPE(x)	 		((PCB_GPIO_TYPE_T) GET_PIN_PARAM1(x))
#define GET_GPIO_INVERT(x)	 		GET_PIN_PARAM2(x)
#define GET_GPIO_INIT_VALUE(x) 		GET_PIN_PARAM3(x)

#define GET_PWM_INVERT(x)	 		((GET_PIN_PARAM1(x) >> 7) & 0x01)
#define GET_PWM_FREQ(x)			((((unsigned int) (GET_PIN_PARAM1(x) & 0x7F)) << 16) | (((unsigned int) GET_PIN_PARAM2(x)) << 8) | (GET_PIN_PARAM3(x)))
#define GET_PWM_DUTY_MAX(x)		GET_PIN_PARAM4(x)
#define GET_PWM_INIT_DUTY(x)		GET_PIN_PARAM5(x)

#define GET_UNIPWM_INVERT(x)	 	((GET_PIN_PARAM1(x) >> 7) & 0x01)
#define GET_UNIPWM_FREQ(x)			((((unsigned int) (GET_PIN_PARAM1(x) & 0x7F)) << 16) | (((unsigned int) GET_PIN_PARAM2(x)) << 8) | (GET_PIN_PARAM3(x)))
#define GET_UNIPWM_DUTY_MAX(x)		GET_PIN_PARAM4(x)
#define GET_UNIPWM_INIT_DUTY(x)		GET_PIN_PARAM5(x)
#define GET_UNIPWM_PWM_NUM(x)	 	GET_PIN_PARAM6(x)
typedef struct {
	unsigned long long info;
	char *name;
} PCB_ENUM_T;

extern void PinMuxInit(void);

/*
  * Function: pcb_mgr_show_pin_enum_info
  *
  *	Description:
  *			if pcb enum is "PIN" enum
  *  			then this function can interpret PIN's value  into PIN's information such that PIN_TYPE....
  *
  *
  *	return :   -1 : means unkwon pin type ...
  *			0: success
  *
*/
extern int pcb_mgr_show_pin_enum_info(unsigned long long pin);

/*
	Function: pcb_mgr_show_all_enum_info

	Description:
			list  all pcb enum in text

	return :
*/
extern void pcb_mgr_show_all_enum_info(void);

/*
  * Function: pcb_mgr_init
  *
  *	Description:
  *			init pcb_mgr
  *
  *	return :   -1 : means error
  *			0: success
  *
*/
extern int pcb_mgr_init(void);
/*
	Function: pcb_mgr_get_enum_info_byname

	Description:
	  		pcb enum is a key-value pair structure,
	  		enum_name is the key and is a string
	  		the value is a unsigned long long variable
	  		pcb_mgr_get_enum_info_byname is given enum_name as the key to find corresponding value

	return :   -1 : means there is no pcb enum found
			0: success

*/
extern int pcb_mgr_get_enum_info_byname(char *enum_name, unsigned long long *value);
/*
  * Function: pcb_enumeration
  *
  *	Description:
  *			enumerate pcb staff from /sys/realtek_boards/pcb
  *
  *   param:
  *		   pppin_enum : search result pointer
  *
  *	return :   -1 : means fail
  *			0: success
  *
*/
extern int pcb_enumeration(PCB_ENUM_T **pppin_enum);
extern int pcb_mgr_get_enum_info_num(int num, unsigned long long *value) ;

extern void pcb_gen_kernel_cmd_line(char *buffer, PCB_ENUM_T *ppcb_enum);
/*
  * Function: IO_PWM_SetDuty
  *
  *	Description:
  *			given some "PIN_XX"'s value then setup pwm duty
  *
  *   param:
  *		   pin : the value corresponding to some "PIN_XXX"
  *			    pin include duty_max function
  *		   duty: PWM duty
  *	return :   -1 : means unkwon pin type ...
  *			0: success
  *
*/
extern int IO_PWM_SetDuty(unsigned long long pin, int duty);
/*
  * Function: IO_PWM_SetFreq
  *
  *	Description:
  *			given some "PIN_XX"'s value then setup pwm frequency
  *
  *   param:
  *		   pin : the value corresponding to some "PIN_XXX"
  *		   freq_hz: PWM frequency
  *	return :   -1 : means unkwon pin type ...
  *			0: success
  *
*/
extern int IO_PWM_SetFreq(unsigned long long pin, int freq_hz);
/*
  * Function: IO_Config
  *
  *	Description:
  *			given some "PIN_XX"'s value then initialze IO
  *                  if IO is lsadc then turn on LSADC and set to current mode / voltage mode
  *                  if IO is GPIO, then setup correct initial state
  *                  if IO is pwm, then setup freq and duty
  *
  *   param:
  *		   pin : the corresponding value  of some "PIN_XXX"
  *
  *	return :   -1 : means unkwon pin type ...
  *			0: success
  *
*/

extern int IO_Config(unsigned long long pin);
/*
  * Function: IO_Set
  *
  *	Description:
  *			given some "PIN_XX"'s value then setup IO value
  *                  if IO is pwm, then setup pwm duty
  *                  if IO is GPO, then setup high low
  *
  *
  *   param:
  *		   pin : the value corresponding to some "PIN_XXX"
  *
  *	return :   -1 : means unkwon pin type ...
  *			0: success
  *
*/
extern int IO_Set(unsigned long long pin, int value);

/*
  * Function: IO_Get
  *
  *	Description:
  *			given some "PIN_XX"'s value then setup IO value
  *                  if IO is lsadc then check if the ADC value hit the presetting ADC value
  *                  "PIN_XX"'s value include presetting ADC value
  *                  if IO is GPI, then get GPI high low
  *
  *
  *   param:
  *		   pin : the corresponding value  of some "PIN_XXX"
  *
  *	return :   -1 : means unkwon pin type ...
  *			0: success
  *
*/
extern int IO_Get(unsigned long long pin);

extern int IO_Direct_Set(char *enum_name, int value);
extern int IO_Direct_Get(char *enum_name);
extern int IO_Direct_SetPWMFreq(char *enum_name, int freq_hz);

#ifdef __PCB_ENUM__
#define PCB_ENUM_START()     PCB_ENUM_T	pcb_enum[] = {
#define PCB_ENUM(x)					{ x, #x },
#define PCB_ENUM_END()		{0, 0}, };
#else
extern PCB_ENUM_T pcb_enum[];
#define PCB_ENUM_START()    //
#define PCB_ENUM(x)			//
#define PCB_ENUM_END()		//
#endif // __PCB_ENUM__

#endif


#ifndef __PCB_MGR_EXTENSION__
#define __PCB_MGR_EXTENSION__

extern int rtk_SetIOPinDirection(unsigned long long pininfo, unsigned int value);
extern int rtk_GetIOPinDirection(unsigned long long pininfo);
extern int rtk_SetIOPin(unsigned long long pininfo, unsigned int value);
extern int rtk_GetIOPin(unsigned long long pininfo);

#undef RTK_IO_DEBUG
/* #define RTK_IO_DEBUG */
#ifdef RTK_IO_DEBUG
#define RTK_IO_P(fmt, args...)          rtd_printk(fmt, ## args)
#else
#define RTK_IO_P(fmt, args...)
#endif

#endif //__PCB_MGR_EXTENSION__
