#ifndef __RTK_AMP_H__
#define __RTK_AMP_H__

#include <mach/rtk_log.h>

#define AMP_INFO(fmt, args...)  rtd_printk(KERN_DEBUG, "AMP" , fmt, ## args)
#define AMP_WARN(fmt, args...)  rtd_printk(KERN_WARNING, "AMP" , fmt, ## args)
#define AMP_ERR(fmt, args...)   rtd_printk(KERN_ERR  , "AMP" , fmt, ## args)

//Register
#define	ALC_1310_MX00_RESET 	         0x00
#define ALC_1310_MX01_THERMAL_FB         0x01
#define ALC_1310_MX02_SEQ_CTRL           0x02
#define ALC_1310_MX04_BQ_SETUP           0x04
#define ALC_1310_MX05_PLL_SETTING        0x05
#define ALC_1310_MX09_DRC_SETTING_1      0x09
#define ALC_1310_MX0A_DRC_SETTING_2      0x0A
#define ALC_1310_MX0B_DRC_SETTING_3      0x0B
#define ALC_1310_MX0C_DRC_SETTING_4      0x0C
#define ALC_1310_MX0E_DRC_SETTING_5      0x0E
#define ALC_1310_PR9A_DRC_SETTING_6      0x9A
#define ALC_1310_PR9C_DRC_SETTING_7      0x9C
#define ALC_1310_PR9D_DRC_SETTING_8      0x9D
#define ALC_1310_PR9E_DRC_SETTING_9      0x9E
#define ALC_1310_MX12_VOLUME_SETTING_1   0x12
#define ALC_1310_MX13_VOLUME_SETTING_2   0x13
#define ALC_1310_MX16_DPWM_1             0x16
#define ALC_1310_MX17_DPWM_2             0x17
#define ALC_1310_MX18_DPWM_3             0x18
#define ALC_1310_MX1D_I2C_SETTING        0x1D
#define ALC_1310_PR6A_REG_INDEX          0x6A
#define ALC_1310_PR6C_REG_DATA           0x6C
#define ALC_1310_MX7C_VENDER_ID          0x7C
#define ALC_1310_MX7E_DEVICE_ID          0x7E

#define ALC_1310_MX13_VOLUME_MUTE        0xC0
#define ALC_1310_MUTE_ON(data)           (ALC_1310_MX13_VOLUME_MUTE | (data))
#define ALC_1310_MUTE_OFF(data)          (~ALC_1310_MX13_VOLUME_MUTE & (data))
  
#define AMP_DEVICE_ADDR (0x1A)
#define END_FLAG        (0xFF)
#define AMP_DEBUG       (0)
#define AMP_ADDR_SIZE   (1)
#define AMP_DATA_SIZE	(2)
#define AMP_MUTE_ON	(1)
#define AMP_MUTE_OFF	(0)

#define AMP_MX_REG_SIZE   (0x7F)
#define AMP_PR_REG1_END   (0x1F)
#define AMP_PR_REG2_START (0x90)
#define AMP_PR_REG2_END   (0xFF)

typedef struct
{
    unsigned char bAddr;
    unsigned char bArray[2];
}ALC1310_REG;//markchen add for 1310

static ALC1310_REG Alc1310_DefautTbl[] =
{
    //init
    {ALC_1310_MX05_PLL_SETTING,{0x40,0x3e}},
    {ALC_1310_MX02_SEQ_CTRL,{0x80,0x00}},
    {ALC_1310_MX09_DRC_SETTING_1,{0x80,0x00}},
    //DC
    {ALC_1310_PR6A_REG_INDEX,{0x00,0xdc}},
    {ALC_1310_PR6C_REG_DATA,{0x00,0x24}},
    //D9
    {0x14,{0x00,0xd9}},
    {0x50,{0xa4,0x10}},

    //DRC
    {ALC_1310_MX09_DRC_SETTING_1,{0xC8,0x00}},//DRC Enable
    {ALC_1310_MX0A_DRC_SETTING_2,{0x05,0x00}},
    {ALC_1310_MX0C_DRC_SETTING_4,{0x04,0x02}},
    {ALC_1310_MX0E_DRC_SETTING_5,{0x06,0x00}},

    /* down layer register and value */
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x9d}},
    {ALC_1310_PR6C_REG_DATA,{0x46,0x00}},

    {ALC_1310_PR6A_REG_INDEX,{0x00,0x9e}},
    {ALC_1310_PR6C_REG_DATA,{0x26,0x26}},

    //b0
    {ALC_1310_PR6A_REG_INDEX,{0x00,0xb0}},					
    {ALC_1310_PR6C_REG_DATA,{0x88,0x03}},					//Silence detection:level is -80dB

    {ALC_1310_MX13_VOLUME_SETTING_2,{0x00,0x0c}},					//unmute
    {ALC_1310_MX13_VOLUME_SETTING_2,{0x00,0x0c}},					//unmute

    //{0x12,0x02,{0xff,0xff}},					//L/R Volume
    //{0x12,0x02,{0x00,0x00}},					//L/R Volume	

    //BQ1 BQ1Ty= 4 BQ1Fs=44100 BQ1Fc=100BQ1Ga=1 BQ1Fb=120
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x00}}, 
    {ALC_1310_PR6C_REG_DATA,{0x02,0x00}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x01}},
    {ALC_1310_PR6C_REG_DATA,{0x87,0x8E}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x02}},
    {ALC_1310_PR6C_REG_DATA,{0x1C,0x09}},

    {ALC_1310_PR6A_REG_INDEX,{0x00,0x03}},
    {ALC_1310_PR6C_REG_DATA,{0xD4,0xC5}},
		                        
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x04}},
    {ALC_1310_PR6C_REG_DATA,{0x01,0xF6}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x05}},
    {ALC_1310_PR6C_REG_DATA,{0x45,0x96}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x06}},
    {ALC_1310_PR6C_REG_DATA,{0x03,0xF7}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x07}},
    {ALC_1310_PR6C_REG_DATA,{0x37,0xBD}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x08}},
    {ALC_1310_PR6C_REG_DATA,{0x1E,0x08}},
		                        
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x09}},
    {ALC_1310_PR6C_REG_DATA,{0xAD,0xE1}},


    //BQ2 BQ2Ty= 4 BQ2Fs=44100 BQ2Fc=6000 BQ2Ga=0.5 BQ2Fb=1500
    {ALC_1310_PR6A_REG_INDEX,{0x00,0xa}}, 
    {ALC_1310_PR6C_REG_DATA,{0x02,0x02}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x0b}},
    {ALC_1310_PR6C_REG_DATA,{0x9D,0x55}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x0c}},
    {ALC_1310_PR6C_REG_DATA,{0x1D,0x9C}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x0d}},
    {ALC_1310_PR6C_REG_DATA,{0xF6,0x0A}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x0e}},
    {ALC_1310_PR6C_REG_DATA,{0x01,0xA2}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x0f}},
    {ALC_1310_PR6C_REG_DATA,{0xFE,0xEA}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x10}},
    {ALC_1310_PR6C_REG_DATA,{0x02,0x66}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x11}},
    {ALC_1310_PR6C_REG_DATA,{0x28,0xC3}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x12}},
    {ALC_1310_PR6C_REG_DATA,{0x1E,0x58}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x13}},
    {ALC_1310_PR6C_REG_DATA,{0x40,0x03}},


    //BQ3 BQ3Ty= 4 BQ3Fs=44100 BQ3Fc=11000 BQ3Ga=1.5 BQ3Fb=14000
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x14}},
    {ALC_1310_PR6C_REG_DATA,{0x02,0x25}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x15}},
    {ALC_1310_PR6C_REG_DATA,{0x88,0x62}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x16}},
    {ALC_1310_PR6C_REG_DATA,{0x1F,0xFD}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x17}},
    {ALC_1310_PR6C_REG_DATA,{0xEC,0x29}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x18}},
    {ALC_1310_PR6C_REG_DATA,{0x00,0x47}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x19}},
    {ALC_1310_PR6C_REG_DATA,{0x09,0xFB}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x1a}},
    {ALC_1310_PR6C_REG_DATA,{0x00,0x02}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x1b}},
    {ALC_1310_PR6C_REG_DATA,{0x3A,0xD3}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x1c}},
    {ALC_1310_PR6C_REG_DATA,{0x1F,0x8E}},
                            
    {ALC_1310_PR6A_REG_INDEX,{0x00,0x1d}},
    {ALC_1310_PR6C_REG_DATA,{0x38,0x7E}},

    {ALC_1310_MX04_BQ_SETUP,{0xc7,0x00}},


    {END_FLAG ,0x01,{0x00}},
#if 0
    //init
    {ALC_1310_MX05_PLL_SETTING,{0x40,0x3E}},
    {ALC_1310_MX02_SEQ_CTRL,{0x80,0x00}},
    {ALC_1310_MX13_VOLUME_SETTING_2,{0x00,0x0C}},
    {ALC_1310_MX09_DRC_SETTING_1,{0x84,0x00}},
    {ALC_1310_PR6A_REG_INDEX,{0x00,0xDC}},
    {ALC_1310_PR6C_REG_DATA,{0x00,0x24}},
    {ALC_1310_PR6A_REG_INDEX,{0x00,0xD9}},
    {ALC_1310_PR6C_REG_DATA,{0xA4,0x10}},
    {END_FLAG ,0x01,{0x00}},
#endif
};

static unsigned char ALC1310_Dump_Reg[] =
{
    ALC_1310_MX00_RESET,
    ALC_1310_MX01_THERMAL_FB,
    ALC_1310_MX02_SEQ_CTRL,
    ALC_1310_MX04_BQ_SETUP,
    ALC_1310_MX05_PLL_SETTING,
    ALC_1310_MX09_DRC_SETTING_1,
    ALC_1310_MX0A_DRC_SETTING_2,
    ALC_1310_MX0B_DRC_SETTING_3,
    ALC_1310_MX0C_DRC_SETTING_4,
    ALC_1310_MX0E_DRC_SETTING_5,
    ALC_1310_PR9A_DRC_SETTING_6,
    ALC_1310_PR9C_DRC_SETTING_7,
    ALC_1310_PR9D_DRC_SETTING_8,
    ALC_1310_PR9E_DRC_SETTING_9,
    ALC_1310_MX12_VOLUME_SETTING_1,
    ALC_1310_MX13_VOLUME_SETTING_2,
    ALC_1310_MX16_DPWM_1,
    ALC_1310_MX17_DPWM_2,
    ALC_1310_MX18_DPWM_3,
    ALC_1310_MX1D_I2C_SETTING,
    ALC_1310_PR6A_REG_INDEX,
    ALC_1310_PR6C_REG_DATA,
    ALC_1310_MX7C_VENDER_ID,
    ALC_1310_MX7E_DEVICE_ID,
};

#define ALC1310_REG_SIZE (sizeof(ALC1310_Dump_Reg)/sizeof(unsigned char))

#endif
