#ifndef __DISEQC_REALTEK_I_H
#define __DISEQC_REALTEK_I_H


#ifdef __cplusplus
extern "C"{
#endif

//#define rtd_outl(addr, value)           pli_writeReg32(addr, value)
//#define rtd_inl(addr)                   pli_readReg32(addr)
//#define rtd_maskl(addr, mask, value)    rtd_outl(addr, ((rtd_inl(addr) & mask) | value))


int 
realtek_i_Diseqc_SetDiseqcContinue22kOnOff(
    unsigned int Diseqc22kOnOff
);

int 
realtek_i_Diseqc_SetDiseqcCmd(
    unsigned int DataLength,
    unsigned char *Data
);

int
realtek_i_Diseqc_SetDiseqcUnModToneBurst(void);

int
realtek_i_Diseqc_SetDiseqcModToneBurst(void);

int
realtek_i_Diseqc_SetDiseqcToneBurst(DISEQC_TONE_MODE mode);


#define REALTEK_I_DISEQC_PRINT_LVL_DBG      0
#define REALTEK_I_DISEQC_PRINT_LVL_INFO     1
#define REALTEK_I_DISEQC_PRINT_LVL_WARNING  2


#ifndef REALTEK_I_DISEQC_PRINT_LVL
#define REALTEK_I_DISEQC_PRINT_LVL          REALTEK_I_DISEQC_PRINT_LVL_DBG
#endif

#define REALTEK_I_DISEQC_DBG(fmt, args...)         rtd_printk_demod(KERN_DEBUG, "DEMO", "DISEQC_DEBUG, " fmt, ##args);
#define REALTEK_I_DISEQC_INFO(fmt, args...)       rtd_printk_demod(KERN_INFO, "DEMO", "DISEQC_INFO, " fmt, ##args);
#define REALTEK_I_DISEQC_WARNING(fmt, args...)    rtd_printk_demod(KERN_WARNING, "DEMO", "DISEQC_WARNING, " fmt, ##args);


#ifdef __cplusplus
}
#endif
#endif
