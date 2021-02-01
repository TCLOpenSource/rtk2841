#ifndef __SCALER_ADC_H__
#define __SCALER_ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/*==================== Definitions ================= */

typedef enum _ADC_TABLE_TYPE{
	ADC_TABLE_VGA_MODE,
	ADC_TABLE_VGA_OFFSET,
	ADC_TABLE_YPBPR_OFFSET,
	ADC_TABLE_SCREEN_MODE_INFO
} ADC_TABLE_TYPE;

/*==================== Variables ================= */
//leochen add SelfAWB timing mode
#define SELFAWB_YPP_MODE	0
#define SELFAWB_VGA_MODE	1

/*==================== Functions ================== */
unsigned char fwif_adc_configposition(unsigned char display);
unsigned char fwif_adc_autobalance(unsigned char display);
unsigned char fwif_adc_regTable(ADC_TABLE_TYPE index, void *ptr);

void dump_adc_dma_data(UINT16 Height,UINT16 Width);
void dump_adc_rawdata_start(void);
void dump_adc_rawdata_release(void);

bool fwif_ADC_LoadSelfAWBResult(char a_ucSrc);
void fwif_ADC_SaveSelfAWBResult(void);
void fwif_ADC_SelfAWB_backup_offsetgain(void);
void fwif_ADC_SelfAWB_restore_offsetgain(int srcindex);

#ifdef __cplusplus
}
#endif

#endif // __SCALER_ADC_H__
