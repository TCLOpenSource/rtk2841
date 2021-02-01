
typedef enum
{
    IFD_AUDIO_BP_SEL_BYPASS = 0            ,
    IFD_AUDIO_BP_SEL_4P300M_4P700M =   1,
    IFD_AUDIO_BP_SEL_3P960M_5P040M =   2,
    IFD_AUDIO_BP_SEL_4P100M_4P900M =   3,
    IFD_AUDIO_BP_SEL_5P300M_6P700M =   4,
    IFD_AUDIO_BP_SEL_5P250M_6P750M =   5,
    IFD_AUDIO_BP_SEL_5P200M_6P800M =   6,
    IFD_AUDIO_BP_SEL_6P300M_6P700M =   7,
    IFD_AUDIO_BP_SEL_6P200M_6P800M =   8,
    IFD_AUDIO_BP_SEL_6P100M_6P900M =   9,
    IFD_AUDIO_BP_SEL_4P090M_4P780M =  10,
    IFD_AUDIO_BP_SEL_4P180M_4P780M =  11,
    IFD_AUDIO_BP_SEL_4P210M_4P750M =  12,
    IFD_AUDIO_BP_SEL_5P115M_7P136M =  16,	//0x10
    IFD_AUDIO_BP_SEL_5P120M_7P132M =  17,	//0x11
    IFD_AUDIO_BP_SEL_5P124M_7P127M =  18,	//0x12
    IFD_AUDIO_BP_SEL_5P132M_7P119M =  19,	//0x13
    IFD_AUDIO_BP_SEL_5P170M_7P032M =  20,	//0x14
    IFD_AUDIO_BP_SEL_5P174M_7P027M =  21,	//0x15
    IFD_AUDIO_BP_SEL_5P182M_7P020M =  22,	//0x16
    IFD_AUDIO_BP_SEL_4P000M_5P000M =  23,	//0x17
    IFD_AUDIO_BP_SEL_3P800M_5P200M =  24,	//0x18
    IFD_AUDIO_BP_SEL_4P300M_5P300M =  25,
    IFD_AUDIO_BP_SEL_5P300M_7P300M =  26,
    IFD_AUDIO_BP_SEL_HPF_4P300M       =  27,
    IFD_AUDIO_BP_SEL_HPF_5P300M       =  28,
} IFD_AUDIO_BP_SEL;

typedef enum
{
    IFD_AUDIO_UPSAMPLE_LP_SEL_BYPASS = 0  ,
    IFD_AUDIO_UPSAMPLE_LP_SEL_PAL = 2,
} IFD_AUDIO_UPSAMPLE_LP_SEL;

void drv_ifd_set_audio_bp (IFD_AUDIO_BP_SEL audio_bp_sel);
UINT8 drv_ifd_get_audio_bp_info (void);
void drv_ifd_audio_gain_en(bool enable);
bool drv_ifd_audio_gain_en_get_info(void);
void drv_ifd_audio_gain_manual(UINT16 gain);
UINT16 drv_ifd_audio_gain_manual_get_info(void);
UINT16 drv_ifd_audio_gain_status(void);
void drv_ifd_audio_output_div2(bool enable);


