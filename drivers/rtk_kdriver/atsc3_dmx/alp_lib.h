#ifndef __ALP_LIB_H__
#define __ALP_LIB_H__

#include "alp_def.h"

#ifdef __cplusplus
extern "C" {
#endif 


typedef struct 
{
    unsigned char  data_len;         // 187 : TSP header is included in data field, 184 : tsp header is stored in tsp_hdr field
    unsigned char  tsp_hdr[3];       // only valid when data len is 184 bytes
    unsigned char* data;
}alp_tsp_info;


typedef struct 
{
    unsigned char packet_type;
    unsigned int  packet_size;
    union 
    {
        // packet type == ALP_PACKET_TYPE_ID_MPEG_2_TS
        struct 
        {
            unsigned char hdm;
            unsigned char dpm;
            unsigned char dpn;
            unsigned char n_tsp;         // number of tsp : up to 16
            alp_tsp_info  tsp_list[16];   // tsp info list
        }mepg2_ts;
    };
}alp_info;


//////////////////////////////////////////////
extern int alp_parse_alp(unsigned char* alp, unsigned int alp_data_len, alp_info* p_info);
extern const char* alp_packet_type_str(unsigned char type);
extern int alp_get_alp_size(unsigned char* alp, unsigned int alp_len);

//////////////////////////////////////////////
#include "alp_mpeg2_ts.h"
    
//////////////////////////////////////////////
#define ALP_WARNING(fmt, args...)       printk(KERN_WARNING "[ALP] Warn, " fmt, ## args)
#define ALP_INFO(fmt, args...)          printk(KERN_INFO "[ALP] Info, " fmt, ## args)
#define ALP_DBG(fmt, args...)           printk(KERN_DEBUG "[ALP] Dbg, " fmt, ## args)


#ifdef __cplusplus
}
#endif     

#endif
