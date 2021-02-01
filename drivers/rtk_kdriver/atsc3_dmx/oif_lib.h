#ifndef __OIF_LIB_H__
#define __OIF_LIB_H__

#include "alp_def.h"

#ifdef __cplusplus
extern "C" {
#endif 


#define OIF_STARTER_VAL     0x5A5A5A5A


typedef struct {
    unsigned int   starter;    
    
#if 1
    unsigned int   plp_id:6;    
    unsigned int   err:1;
    unsigned int   err_en:1;        
    unsigned int   length : 16;
    unsigned int   cc : 8;
#else
    unsigned int   cc : 8;
    unsigned int   length : 16;
    unsigned int   plp_id:6;        
    unsigned int   err:1;
    unsigned int   err_en:1;        
#endif        
}OIF_HDR;

extern int oif_encapsulate_bbf( unsigned char*      bbf, 
                                unsigned short      bbf_sz, 
                                unsigned char*      out, 
                                unsigned long       out_len, 
                                unsigned char       plp,
                                unsigned char*      p_cc,
                                unsigned char       err);   

unsigned char* oif_find_starter(unsigned char*      oif, 
                                unsigned long       oif_len);   

#define OIF_STARTER(oif)    (*(unsigned int*)oif)
#define OIF_PLP(oif)        (oif[4] & 0x3F)                                                                
#define OIF_ERROR(oif)      ((oif[4]>>6) & 0x3)                                                                
#define OIF_LENGTH(oif)     ((oif[5]<<8) + oif[6])                                
#define OIF_CC(oif)         (oif[7])                                                                
    
//////////////////////////////////////////////
#define OIF_WARNING(fmt, args...)       printf("[OIF] Warn, " fmt, ## args)
#define OIF_INFO(fmt, args...)          printf("[OIF] Info, " fmt, ## args)
#define OIF_DBG(fmt, args...)           printf("[OIF] Dbg, " fmt, ## args)


#ifdef __cplusplus
}
#endif     

#endif
