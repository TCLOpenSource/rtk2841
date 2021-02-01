// TV Frontend OSAL Driver
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>
#include "tv_osal.h"
#include "tv_fe_aux.h"


const char* tv_sys_name(TV_SYSTEM sys)
{    
    switch(sys)
    {
    case TV_SYS_BG_PAL:         return "BG_PAL";
    case TV_SYS_I_PAL:          return "I_PAL";
    case TV_SYS_DK_PAL:         return "DK_PAL";
    case TV_SYS_BG_SECAM:       return "BG_SECAM";
    case TV_SYS_DK_SECAM:       return "DK_SECAM";                 
    case TV_SYS_L_SECAM:        return "L_SECAM";
    case TV_SYS_LL_SECAM:       return "LL_SECAM";
    case TV_SYS_M_NTSC:         return "M_NTSC";
    case TV_SYS_M_PAL:          return "M_PAL";
    case TV_SYS_N_PAL:          return "N_PAL";  
    case TV_SYS_DVBT_6M:        return "DVBT 6M";
    case TV_SYS_DVBT_7M:        return "DVBT 7M";
    case TV_SYS_DVBT_8M:        return "DVBT 8M";
    case TV_SYS_DVBC_6M:        return "DVBC 6M";
    case TV_SYS_DVBC_7M:        return "DVBC 7M";
    case TV_SYS_DVBC_8M:        return "DVBC 8M";
    case TV_SYS_DVBT2_1D7M:     return "DVBT2 1.7M";
    case TV_SYS_DVBT2_6M:       return "DVBT2 6M";
    case TV_SYS_DVBT2_7M:       return "DVBT2 7M";
    case TV_SYS_DVBT2_8M:       return "DVBT2 8M";
    case TV_SYS_DVBT2_1D7M_PLP: return "DVBT2 1.7M PLP";
    case TV_SYS_DVBT2_6M_PLP:   return "DVBT2 6M PLP";
    case TV_SYS_DVBT2_7M_PLP:   return "DVBT2 7M PLP";
    case TV_SYS_DVBT2_8M_PLP:   return "DVBT2 8M PLP";
    case TV_SYS_AUTOSCAN_6M:    return "AUTOSCAN 6M";
    case TV_SYS_AUTOSCAN_7M:    return "AUTOSCAN 7M";
    case TV_SYS_AUTOSCAN_8M:    return "AUTOSCAN 8M";
    case TV_SYS_DVBS:           return "DVBS";
    case TV_SYS_DVBS2:          return "DVBS2";
    case TV_SYS_ABS_S:          return "ABS-S";
    case TV_SYS_ATSC:           return "ATSC";
    case TV_SYS_OPENCABLE_64:   return "OPENCABLE 64";
    case TV_SYS_OPENCABLE_256:  return "OPENCABLE 256";
    case TV_SYS_DTMB:           return "DTMB";
    case TV_SYS_DTMB_6M:           return "DTMB_6M";
    case TV_SYS_DTMB_8M:           return "DTMB_8M";
    case TV_SYS_ISDBT_6M:       return "ISDB-T 6M";
    case TV_SYS_ISDBT_7M:       return "ISDB-T 7M";
    case TV_SYS_ISDBT_8M:       return "ISDB-T 8M";            
    case TV_SYS_ISDBS_6M:       return "ISDB-S 6M";
    case TV_SYS_MMTS:           return "TS From Memory";
    case TV_SYS_FILE:           return "TS From FILE";    
    case TV_SYS_RTSP:           return "TS From RTSP protocol";  
    case TV_SYS_CURRENT:        return "Current TV SYS";
    default:                    return "UNKNOWN";
    }    
}




const char* lnb_mode_str(LNB_MODE mode)
{    
    switch(mode)
    {                    
    case LNB_MODE_OFF:                  return "LNB OFF";
    case LNB_MODE_13V:                  return "LNB with 13V DC";
    case LNB_MODE_18V:                  return "LNB with 18V DC";
    case LNB_MODE_13V_WITH_22K_BURST:   return "LNB with 13V DC and 22k burst";
    case LNB_MODE_18V_WITH_22K_BURST:   return "LNB with 18V DC and 22k burst";                         
    default:                            return "Unknown LNB mode";
    }    
}


const char* tuner_mode_str(TV_OP_MODE mode)
{       
    switch(mode)
    {                    
    case TV_OP_MODE_NORMAL:             return "Normal Mode";
    case TV_OP_MODE_SCANING:            return "Scan Mode";
    case TV_OP_MODE_STANDBY:            return "Standby Mode";                  
    case TV_OP_MODE_TP_ONLY:            return "TP Only Mode";               
    default:                            return "Unknown tuner mode";
    }    
}


unsigned char Snr2Str(unsigned long Snr)
{        
    unsigned char str_map[] = 
    { 
      //------- Lv 1 : Ultra Low signal, Step = 1 
      0,    // 0dB
      0,    // 1dB
      0,    // 2dB 
      0,    // 3dB 
      0,    // 4dB 
      0,    // 5dB 
      5,    // 6dB 
      5,    // 7dB
      5,    // 8dB
      5,    // 9dB               
      10,   // 10dB                  
      11,   // 11dB
      12,   // 12dB       
      13,   // 13dB 
      14,   // 14dB 
      //------- Lv 2 : Low signal            
      18,   // 15dB       
      24,   // 16dB       
      30,   // 17dB
      35,   // 18dB
      40,   // 19dB            
      46,   // 20dB
      52,   // 21dB
      58,   // 22dB 
      64,   // 23dB 
      70,   // 24dB       
      //------- Lv 3 : Good signal
      72,   // 25dB       
      76,   // 26dB 
      80,   // 27dB
      84,   // 28dB
      88,   // 29dB            
      //------- Lv 4 : Great signal
      90,   // 30dB 
      92,   // 31dB      
      94,   // 32dB      
      96,   // 33dB      
      98,   // 34dB      
      100,  // 35dB                        
    };
    
    if (Snr < 0)
        return 0;
    else if (Snr >= sizeof(str_map))
        return 100;
    else
        return str_map[(int) Snr];
}



unsigned char Ber2Quality(unsigned long ber)
{                      
    if (ber <=30)
    {
        // Good singal : from 100 - 70
        return 100 - ber;
    }
    else if (ber <= 80)         
    {
        // Normal Signal : from 70 - 20
        return 70 - (ber-30);
    }
    else if (ber <= 100)
    {
        // poor Signal : from 20 - 5
        return 20 - (ber-80);
    }
    else
    {
        return 0;
    } 
	return 100;
}


#ifndef DTV_CTRL_ATTRIBUTE_PATH
#define DTV_CTRL_ATTRIBUTE_PATH    "/var/dtv_ctrl/"
#endif


int check_tv_ctrl_attribute(const char* name)
{
#if 0
	char path[256];
    
    snprintf(path, sizeof(path), "%s/%s", DTV_CTRL_ATTRIBUTE_PATH, name);
    
    return access(path, R_OK);    
#else
	return 0;
#endif

}


int read_tv_ctrl_attribute(const char* name, char* command, int len)
{
#if 0
	char buff[256];
    int ret;
    FILE* fd;
    
    snprintf(buff, sizeof(buff), "%s/%s", DTV_CTRL_ATTRIBUTE_PATH, name);
        
    fd = fopen(buff, "r");
    
    command[0] = 0;
    
    if (fd==NULL)
        return 0;
        
    ret = fread(command, 1, len, fd);
    
    fclose(fd);
        
    return ret;             
#else
	return 0;
#endif
}

void clear_tv_ctrl_attribute(const char* name)
{
#if 0
    char cmd[256];
    
    snprintf(cmd, sizeof(cmd), "rm -f %s/%s ", DTV_CTRL_ATTRIBUTE_PATH, name);
    
    system(cmd);
#endif
}


/////////////////////////////////////// DISEQC Command ////////////////////////////////////////////
#ifdef DISEQC_SUPPORT_EN

const char* diseqc_tone_mode_str(DISEQC_TONE_MODE mode)
{    
    switch(mode)
    {                 
    case DISEQC_TONE_MODE_A:    return "0 Tone Bust for Sattlite A";
    case DISEQC_TONE_MODE_B:    return "1 Tone Bust for Sattlite B";           
    default:                    return "Unknown Tone mode";
    }    
}

#endif

