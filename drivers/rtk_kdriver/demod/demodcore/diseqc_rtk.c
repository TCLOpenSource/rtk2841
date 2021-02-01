//#include <stdio.h>
//#include <string.h>
//#include "OSAL.h"
#include <mach/io.h>
#include "tv_osal.h"
#include "foundation.h"
#include "diseqc_rtk.h"
#include <rtk_kdriver/rtk_crt.h>

unsigned int DvbS2_Keep_22k_on_off = 0;

int
realtek_i_Diseqc_SetDiseqcContinue22kOnOff(
    unsigned int Diseqc22kOnOff
)
{
    REALTEK_I_DISEQC_INFO("\033[1;32;31m" "realtek_i_Diseqc_SetDiseqcContinue22kOnOff (%u)\n" "\033[m", Diseqc22kOnOff);
    DvbS2_Keep_22k_on_off = Diseqc22kOnOff;
    
    if((rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask) != SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_img_demod_mask) != SYS_REG_SYS_CLKEN0_clken_img_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD_IMG_EN\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD_IMG_EN, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_diseqc_mask) != SYS_REG_SYS_CLKEN0_clken_diseqc_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DISEQC\n" "\033[m");
        CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);
    }
    
    rtd_maskl(0xb8000828, ~(0xF0000000), 0x60000000);//Sel pinmux to dsc_22
   
    rtd_maskl(0xb8070004, ~(0x00000400), 0x00000000);//Tx Off
    
    rtd_maskl(0xb8070004, ~(0x80000000), 0x80000000);//En loop back mode

    #ifdef CONFIG_CUSTOMER_TV006
    rtd_maskl(0xb8070000, ~(0x40000000), 0x40000000);//Tx envelop mode
    #else
    rtd_maskl(0xb8070000, ~(0x40000000), 0x00000000);//Tx pulse mode
    #endif

    rtd_maskl(0xb8070004, ~(0x0000c000), 0x0000c000);//Continue Tone Mode
    
    rtd_maskl(0xb8070004, ~(0x000003ff), 0x0000027f);//22k freq divider

    tv_osal_msleep(1);

    if(Diseqc22kOnOff == 1)
    {
        rtd_maskl(0xb8070004, ~(0x00000400), 0x00000400);//Tx Go
    }
    else
    {
        rtd_maskl(0xb8070004, ~(0x00000400), 0x00000400);//Tx Go
        rtd_maskl(0xb8070004, ~(0x00000400), 0x00000000);//Tx Off
    }
    
    return FUNCTION_SUCCESS;
}

int
realtek_i_Diseqc_SetDiseqcCmd(
    unsigned int DataLength,
    unsigned char *Data
)
{
    int DataCount;

    REALTEK_I_DISEQC_INFO("\033[1;32;31m" "realtek_i_Diseqc_SetDiseqcCmd\n" "\033[m");
    
    if((rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask) != SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_img_demod_mask) != SYS_REG_SYS_CLKEN0_clken_img_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD_IMG_EN\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD_IMG_EN, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_diseqc_mask) != SYS_REG_SYS_CLKEN0_clken_diseqc_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DISEQC\n" "\033[m");
        CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);
    }
    
    rtd_maskl(0xb8000828, ~(0xF0000000), 0x60000000);//Sel pinmux to dsc_22
    
    rtd_maskl(0xb8070004, ~(0x00000400), 0x00000000);//Tx Off
    
    rtd_maskl(0xb8070004, ~(0x80000000), 0x80000000);//En loop back mode
    
    #ifdef CONFIG_CUSTOMER_TV006
    rtd_maskl(0xb8070000, ~(0x40000000), 0x40000000);//Tx envelop mode
    #else
    rtd_maskl(0xb8070000, ~(0x40000000), 0x00000000);//Tx pulse mode
    #endif
    
    rtd_maskl(0xb8070004, ~(0x0000c000), 0x00008000);//Diseqc Cmd Mode
    
    rtd_maskl(0xb8070004, ~(0x000003ff), 0x0000027f);//22k freq divider
    
    rtd_maskl(0xb8070004, ~(0x00010000), 0x00010000);//Odd parity

    rtd_maskl(0xb8070004, ~(0x00003800), ((DataLength-1)<<11));//Set Data Length(0:1Byte, 1:2Byte, ...)

    for(DataCount=0; DataCount<DataLength; DataCount++)
    {
        rtd_outl((0xb807001c+(4*DataCount)), *(Data+DataCount));
    }
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 0 = %x\n" "\033[m", rtd_inl(0xb807001c));
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 1 = %x\n" "\033[m", rtd_inl(0xb8070020));
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 2 = %x\n" "\033[m", rtd_inl(0xb8070024));
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 3 = %x\n" "\033[m", rtd_inl(0xb8070028));
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 4 = %x\n" "\033[m", rtd_inl(0xb807002c));
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 5 = %x\n" "\033[m", rtd_inl(0xb8070030));
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 6 = %x\n" "\033[m", rtd_inl(0xb8070034));
    //REALTEK_I_DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 7 = %x\n" "\033[m", rtd_inl(0xb8070038));
    
    REALTEK_I_DISEQC_INFO("Diseqc cmd data %x %x %x %x %x %x %x %x\n", rtd_inl(0xb807001c), rtd_inl(0xb8070020), rtd_inl(0xb8070024), rtd_inl(0xb8070028), rtd_inl(0xb807002c), rtd_inl(0xb8070030), rtd_inl(0xb8070034), rtd_inl(0xb8070038));

    tv_osal_msleep(70);

    rtd_maskl(0xb8070004, ~(0x00000400), 0x00000400);//Tx Go
    
    #ifndef CONFIG_CUSTOMER_TV006
    tv_osal_msleep(100);
    #endif
    
    return FUNCTION_SUCCESS;
}

int
realtek_i_Diseqc_SetDiseqcUnModToneBurst(
)
{
    REALTEK_I_DISEQC_INFO("\033[1;32;31m" "realtek_i_Diseqc_SetDiseqcUnModToneBurst\n" "\033[m");
    
    if((rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask) != SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_img_demod_mask) != SYS_REG_SYS_CLKEN0_clken_img_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD_IMG_EN\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD_IMG_EN, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_diseqc_mask) != SYS_REG_SYS_CLKEN0_clken_diseqc_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DISEQC\n" "\033[m");
        CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);
    }
    
    rtd_maskl(0xb8000828, ~(0xF0000000), 0x60000000);//Sel pinmux to dsc_22

    rtd_maskl(0xb8070004, ~(0x00000400), 0x00000000);//Tx Off
    
    rtd_maskl(0xb8070004, ~(0x80000000), 0x80000000);//En loop back mode
    
    #ifdef CONFIG_CUSTOMER_TV006
    rtd_maskl(0xb8070000, ~(0x40000000), 0x40000000);//Tx envelop mode
    #else
    rtd_maskl(0xb8070000, ~(0x40000000), 0x00000000);//Tx pulse mode
    #endif
    
    rtd_maskl(0xb8070004, ~(0x0000C000), 0x00004000);//Un-Modulated Tone Burst Mode
    
    rtd_maskl(0xb8070004, ~(0x000003ff), 0x0000027f);//22k freq divider

    tv_osal_msleep(1); 
    
    rtd_maskl(0xb8070004, ~(0x00000400), 0x00000400);//Tx Go
    
    #ifndef CONFIG_CUSTOMER_TV006
    tv_osal_msleep(15);
    #endif

    return FUNCTION_SUCCESS;
}

int
realtek_i_Diseqc_SetDiseqcModToneBurst(
)
{
    REALTEK_I_DISEQC_INFO("\033[1;32;31m" "realtek_i_Diseqc_SetDiseqcModToneBurst\n" "\033[m");
    
    if((rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask) != SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_img_demod_mask) != SYS_REG_SYS_CLKEN0_clken_img_demod_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DIGDEMOD_IMG_EN\n" "\033[m");
        CRT_CLK_OnOff(DIGDEMOD_IMG_EN, CLK_ON, NULL);
    }

    if((rtd_inl(SYS_REG_SYS_CLKEN0_reg) & SYS_REG_SYS_CLKEN0_clken_diseqc_mask) != SYS_REG_SYS_CLKEN0_clken_diseqc_mask)
    {
        REALTEK_I_DISEQC_INFO("\033[1;32;31m" "Diseqc First Control, Enable DISEQC\n" "\033[m");
        CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);
    }
    
    rtd_maskl(0xb8000828, ~(0xF0000000), 0x60000000);//Sel pinmux to dsc_22
    
    rtd_maskl(0xb8070004, ~(0x00000400), 0x00000000);//Tx Off
    
    rtd_maskl(0xb8070004, ~(0x80000000), 0x80000000);//En loop back mode
    
    #ifdef CONFIG_CUSTOMER_TV006
    rtd_maskl(0xb8070000, ~(0x40000000), 0x40000000);//Tx envelop mode
    #else
    rtd_maskl(0xb8070000, ~(0x40000000), 0x00000000);//Tx pulse mode
    #endif
    
    rtd_maskl(0xb8070004, ~(0x0000C000), 0x00000000);//Modulated Tone Burst Mode
    
    rtd_maskl(0xb8070004, ~(0x000003ff), 0x0000027f);//22k freq divider

    tv_osal_msleep(1); 

    rtd_maskl(0xb8070004, ~(0x00000400), 0x00000400);//Tx Go
    
    #ifndef CONFIG_CUSTOMER_TV006
    tv_osal_msleep(15);
    #endif
    
    return FUNCTION_SUCCESS;
}


int
realtek_i_Diseqc_SetDiseqcToneBurst(DISEQC_TONE_MODE mode)
{
    REALTEK_I_DISEQC_INFO("\033[1;32;31m" "realtek_i_Diseqc_SetDiseqcToneBurst (%u)\n" "\033[m", (unsigned int)mode);
    
    if(mode == DISEQC_TONE_MODE_A)
        realtek_i_Diseqc_SetDiseqcUnModToneBurst();
    else
        realtek_i_Diseqc_SetDiseqcModToneBurst();
 
    return FUNCTION_SUCCESS;
}

