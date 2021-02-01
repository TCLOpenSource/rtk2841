#include <linux/kernel.h>
#include <linux/slab.h>
#include "alp_lib.h"
#include "alp_mpeg2_ts.h"



/*======================================================
 * Func  : alp_parse_mpeg2_ts_alp
 *
 * Desc  : parse ALP info
 *
 * Param : alp : pointer of alp packet
 *         alp_data_len : size of alp packet
 *         p_info : alp info output
 *
 * Retn  : <0  : fail
 *         >=0 : size of alp data
 *======================================================*/
int alp_get_mpeg2_ts_alp_size(
    unsigned char*      alp,
    unsigned int        alp_len
    )
{
    int ret = 0;
    int num_ts;

    if (alp==NULL || alp_len<2)
    {
        ALP_WARNING("get mpeg2 ts alp size failed - invalid parameters\n");
        return -1;
    }        
    
    if (ALP_PACKET_TYPE(alp)!=ALP_PACKET_TYPE_ID_MPEG_2_TS)
    {        
        ALP_WARNING("get mpeg2 ts alp size failed - type is not correct\n");        
        return -1;
    }

    ALP_DBG("alp_get_alp_size, alp {%02x %02x}\n", alp[0], alp[1]);
    
    num_ts = ALP_NUM_TS(alp);
                    
    if (num_ts==0)
        num_ts = 16;
        
    if (ALP_AHF(alp)==0)
    {
        // 1 bytes header (no HDM) : each TSP take 187 bytes
        ret = 1 + (187 * num_ts);
    }
    else
    {
        // 2 bytes header
        if (ALP_HDM(alp))       // with HDM : the 1st TSP is 187 bytes, and the reset is 184 bytes
            ret = 2 + 3 + (184 * num_ts);
        else                    // without HDM : all the TSP is 187 bytes
            ret = 2 + (187 * num_ts);
    }
    
    ALP_DBG("alp_get_alp_size, Type=(MPEG TS), NumTS=%d, length=%d\n", num_ts, ret);
    return ret;
}


/*======================================================
 * Func  : alp_parse_mpeg2_ts_alp
 *
 * Desc  : parse ALP info
 *
 * Param : alp : pointer of alp packet
 *         alp_data_len : size of alp packet
 *         p_info : alp info output
 *
 * Retn  : <0  : fail
 *         >=0 : size of alp data
 *======================================================*/
int alp_parse_mpeg2_ts_alp(
    unsigned char*      alp,
    unsigned int        alp_len,
    alp_info*           p_info
    )
{
    int i;
    unsigned char hdm_tsp_hdr[3];
    unsigned char next_cc = 0;
    unsigned char tsp_size = 187;

    if (alp==NULL || alp_len < 1|| p_info==NULL ||
        ALP_PACKET_TYPE(alp)!=ALP_PACKET_TYPE_ID_MPEG_2_TS) {
        ALP_WARNING("alp_parse_mpeg2_ts_alp failed, invalid parameters\n");
        return -1;
    }

    memset(p_info, 0, sizeof(alp_info));

    // parse packet header
    p_info->packet_type = ALP_PACKET_TYPE_ID_MPEG_2_TS;
    p_info->packet_size = 1;
    p_info->mepg2_ts.n_tsp = (alp[0] >> 1) & 0xF;

    if (p_info->mepg2_ts.n_tsp==0)
        p_info->mepg2_ts.n_tsp = 16;

    if ((alp[0] & 0x1))
    {
        if (alp_len<2) {
            ALP_WARNING("alp_parse_mpeg2_ts_alp failed, alp_len %d < 2\n", alp_len);
            return -1;
        }

        p_info->mepg2_ts.hdm = alp[1] & 0x80;
        p_info->mepg2_ts.dpm = alp[1] & 0x7F;
        p_info->mepg2_ts.dpn = alp[1] & 0x7F;
        p_info->packet_size++;
    }

    alp += p_info->packet_size;

    ALP_DBG("p_info->mepg2_ts.hdm=%x\n", p_info->mepg2_ts.hdm);    
    
    if (p_info->mepg2_ts.hdm)
        p_info->packet_size += (184*p_info->mepg2_ts.n_tsp) + 3;
    else
        p_info->packet_size += 187 * p_info->mepg2_ts.n_tsp;

    if (alp_len < p_info->packet_size) {     // no enough data size
        ALP_WARNING("alp_parse_mpeg2_ts_alp failed, alp_len %d < %d\n", alp_len, p_info->packet_size);
        return p_info->packet_size;
    }        

    for (i=0; i<p_info->mepg2_ts.n_tsp; i++)
    {
        if (p_info->mepg2_ts.hdm)
        {
            // With Header Deletion
            if (i==0)
            {
                memcpy(hdm_tsp_hdr, alp, 3);    // store current hdm tsp header
                next_cc = NEXT_CC((hdm_tsp_hdr[2] & 0xF));     // next CC
                tsp_size = 187;
            }
            else
            {
                p_info->mepg2_ts.tsp_list[i].tsp_hdr[0] = hdm_tsp_hdr[0];
                p_info->mepg2_ts.tsp_list[i].tsp_hdr[1] = hdm_tsp_hdr[1];
                p_info->mepg2_ts.tsp_list[i].tsp_hdr[2] = (hdm_tsp_hdr[2] & 0xF0) | (next_cc & 0xF);  // update CC
                next_cc = NEXT_CC(next_cc); 
                tsp_size = 184;
            }
        }

        p_info->mepg2_ts.tsp_list[i].data = alp;
        p_info->mepg2_ts.tsp_list[i].data_len = tsp_size;
        alp += tsp_size;
    }

    return 0;
}




/*======================================================
 * Func  : alp_encapsulate_mepg_ts
 *
 * Desc  : Enapsulate MPEG2 TSPs into ALP packet
 *
 * Param : alp : pointer of alp packet
 *         alp_data_len : size of alp packet
 *         p_info : alp info output
 *         flags  :
 *            ALP_ENCAP_WITH_NULL_PACK_DELETEION
 *            ALP_ENCAP_WITH_PACKET_HEADER_DELETION
 *
 * Retn  : <0 : fail
 *          others : number of TSP encapulated
 *======================================================*/
int alp_encapsulate_mepg_ts(
    unsigned char*  tsp,
    unsigned int    ntsp,
    alp_info*       p_info,
    unsigned int    flags
    )
{
    int i = 0;
    int proc_tsp_cnt = 0;
    unsigned char* ref_hdr = NULL;
    unsigned char  next_cc = 0;
    unsigned char  procced_tsp = 0;    

    if (tsp==NULL || p_info==NULL || ntsp==0)
        return -1;

    memset(p_info, 0, sizeof(alp_info));

    // parse packet header
    p_info->packet_type = ALP_PACKET_TYPE_ID_MPEG_2_TS;
    p_info->packet_size = 1;

    if ((flags & ALP_ENCAP_WITH_NULL_PACK_DELETEION))
    {
        p_info->mepg2_ts.dpm = 1;
        p_info->packet_size = 2;
    }

    if ((flags & ALP_ENCAP_WITH_PACKET_HEADER_DELETION))
    {
        p_info->mepg2_ts.hdm = 1;
        p_info->packet_size = 2;
    }

    for (i=0; i<ntsp; i++)
    {           
        unsigned char* data = tsp + 1;
        unsigned char  data_len = 187;
        
        ALP_DBG("TSP[%d]={%02x %02x %02x %02x }...\n", i, tsp[0], tsp[1], tsp[2],tsp[3]);
                    
        if (TSP_PID(tsp)==0x1FFF && p_info->mepg2_ts.dpm)
        {
            // NULL packet deletion
            if (p_info->mepg2_ts.n_tsp)     // if already has some TSPs, End of TSPs {
                break;

            proc_tsp_cnt++;
            // conscade null TSP
            if (p_info->mepg2_ts.dpn==0x7F)  // reach the maximum null packet count
            {
                // put it as a useful TSP                
                p_info->mepg2_ts.tsp_list[0].data = data;
                p_info->mepg2_ts.tsp_list[0].data_len = data_len;
                p_info->mepg2_ts.n_tsp = 1;
                p_info->packet_size += data_len;                
                break;
            }
            
            p_info->mepg2_ts.dpn++;    // increase dpn
        }
        else
        {        
            ALP_DBG("p_info->mepg2_ts.hdm=%02x\n", p_info->mepg2_ts.hdm);
            
            if (p_info->mepg2_ts.hdm)
            {
                if (p_info->mepg2_ts.n_tsp==0)
                {
                    ref_hdr = data;
                    next_cc = NEXT_CC(ref_hdr[2]);
                }
                else
                {
                    ALP_DBG("HDR Check : Curr=%02x%02x%02x, Ref=%02x%02x%02x\n",
                            data[0],data[1],data[2],
                            ref_hdr[0],ref_hdr[1],ref_hdr[2]);
                                                
                    if ((data[0] != ref_hdr[0]) ||
                        (data[1] != ref_hdr[1]) ||
                        ((data[2] & 0xF0)!=(ref_hdr[2]& 0xF0))||
                        (TSP_CC(tsp) != next_cc))
                    {
                        // header changed, end of chaining                             
                        ALP_DBG("header changed, end of chaining\n");
                        break;
                    }

                    data += 3;      // remove header
                    data_len -= 3;
                    next_cc = NEXT_CC(next_cc); // increase cc
                    ALP_DBG("header detected, remove header : next cc = %d, chained count=%d\n", 
                            next_cc, p_info->mepg2_ts.n_tsp);
                }
            }            
                    
            p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data = data;
            p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data_len = data_len;
            p_info->packet_size += data_len;
            
            ALP_DBG("tsp_list[%d]= data=%p, len=%d { %02x %02x %02x %02x}\n", 
                    p_info->mepg2_ts.n_tsp, 
                    p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data,
                    p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data_len,
                    p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data[0],
                    p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data[1],
                    p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data[2],
                    p_info->mepg2_ts.tsp_list[p_info->mepg2_ts.n_tsp].data[3]);
                                
            p_info->mepg2_ts.n_tsp++;

            proc_tsp_cnt++;
            
            if (p_info->mepg2_ts.n_tsp>=16)
                break;
        }

        // Next TSP
        tsp += 188;
    }
    
    ALP_DBG("proc_tsp_cnt=%d\n", proc_tsp_cnt);

    return proc_tsp_cnt;
}




/*======================================================
 * Func  : alp_encapsulate_mepg_ts
 *
 * Desc  : Enapsulate MPEG2 TSPs into ALP packet
 *
 * Param : alp : pointer of alp packet
 *         alp_data_len : size of alp packet
 *         p_info : alp info output
 *         flags  :
 *            ALP_ENCAP_WITH_NULL_PACK_DELETEION
 *            ALP_ENCAP_WITH_PACKET_HEADER_DELETION
 *
 * Retn  : <0 : fail
 *          others : number of bytes 
 *======================================================*/
int alp_decapsulate_mepg_ts(    
    unsigned char*  alp,
    unsigned int    alp_len,    
    unsigned char*  p_buff,
    unsigned int    buff_sz
    )
{
    unsigned char tsp_hdr[3];
    unsigned char tsp_cc;
    unsigned char hdm = 0;
    int num_ts = ALP_NUM_TS(alp);    
    int outlen;    
    int i;
            
    if (ALP_AHF(alp))
    {                
        hdm = ALP_HDM(alp);
        alp += 2;
    }
    else
        alp++;        
        
    if (num_ts==0)
        num_ts = 16;
        
    outlen = 188 * num_ts;
          
    if (outlen > buff_sz)
        return -1;       
    
    for (i=0; i<num_ts; i++)
    {
        *p_buff++ = 0x47;
        
        if (hdm)
        {
            if (i==0) 
            {                
                memcpy(p_buff, alp, 187);       // 
                memcpy(tsp_hdr, alp, 3);        // save hdr        
                tsp_cc = tsp_hdr[2] & 0xF;      // save CC
                tsp_hdr[2] &= ~0xF;             // clear cc
                tsp_cc++;
                alp += 187;
                
                ALP_DBG("111 TSP[%d] %02x %02x %02x\n", i, p_buff[0], p_buff[1], p_buff[2], p_buff[3]);
            }
            else                
            {                   
                memcpy(p_buff, tsp_hdr, 3);     // restore hdr        
                p_buff[2] |= (tsp_cc++) & 0xF;  // update cc                
                memcpy(p_buff + 3, alp, 184);   // copy payload
                ALP_DBG("222 TSP[%d] %02x %02x %02x\n", i, p_buff[0], p_buff[1], p_buff[2], p_buff[3]);
                alp += 184;
            }    
            p_buff+= 187;
        }            
        else
        {
            // generate TSP            
            memcpy(p_buff, alp, 187);
            ALP_DBG("000 TSP[%d] %02x %02x %02x\n", i, p_buff[0], p_buff[1], p_buff[2], p_buff[3]);
            
            p_buff+= 187;
            alp += 187;
            
        }                        
    }
            
    return outlen;
}
