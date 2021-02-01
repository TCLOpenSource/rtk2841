#ifndef __ALP_MPEG2_TS_H__
#define __ALP_MPEG2_TS_H__

#include "alp_def.h"

#ifdef __cplusplus
extern "C" {
#endif 


//////////////////////////////////////////////
#define TSP_PID(tsp)      (((tsp[1] & 0x1F)<<8) + tsp[2])
#define TSP_CC(tsp)       (tsp[3] & 0xF)
#define NEXT_CC(cc)       ((cc+1) & 0xF)

//////////////////////////////////////////////
extern int alp_get_mpeg2_ts_alp_size(unsigned char* alp, unsigned int alp_len);
extern int alp_parse_mpeg2_ts_alp(unsigned char* alp, unsigned int alp_len, alp_info* p_info);
extern int alp_encapsulate_mepg_ts(unsigned char* tsp, unsigned int ntsp, alp_info* p_info, unsigned int flags);
extern int alp_decapsulate_mepg_ts(unsigned char*  alp, unsigned int alp_len, unsigned char* p_buff, unsigned int buff_sz);

#define ALP_ENCAP_WITH_NULL_PACK_DELETEION          (0x1<<0)
#define ALP_ENCAP_WITH_PACKET_HEADER_DELETION       (0x1<<1)

#ifdef __cplusplus
}
#endif     

#endif
