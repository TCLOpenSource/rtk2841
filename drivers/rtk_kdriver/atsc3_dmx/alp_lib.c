#include <linux/kernel.h>
#include <linux/slab.h>
#include "alp_lib.h"
#include "alp_mpeg2_ts.h"



const char* alp_packet_type_str(unsigned char type)
{
    switch(type)
    {
    case ALP_PACKET_TYPE_ID_IPV4:
        return "IPV4 Packet";

    case ALP_PACKET_TYPE_ID_COMPRESSED_IP_PACK:
        return "Compressed IP Packet";

    case ALP_PACKET_TYPE_ID_LINK_LAYER_SIGINALING_PACKET:
        return "Link Layer Signaling Packet";

    case ALP_PACKET_TYPE_ID_PACKET_TYPE_EXTENSION:
        return "Extnesion Packet";

    case ALP_PACKET_TYPE_ID_MPEG_2_TS:
        return "MPEG2 Transport Packet";

    default:
        return "Unknown";
    }
}



int alp_get_alp_size(
    unsigned char*  alp,
    unsigned int    alp_len
    )
{
    int ret = 0;

    if (alp==NULL || alp_len<2)
    {
        ALP_WARNING("Parse ALP failed - invalid parameters\n");
        return -1;
    }            

    if (ALP_PACKET_TYPE(alp)==ALP_PACKET_TYPE_ID_MPEG_2_TS)
    {                
        return alp_get_mpeg2_ts_alp_size(alp, alp_len);    
    }
    else
    {
        int payload_size = ALP_LENGTH(alp);                

        ALP_DBG("alp_get_alp_size, alp {%02x %02x}\n", alp[0], alp[1]);
        
        switch ((alp[0]>>3)&0x3)
        {
        case 0x0:   // single packet, without aditional header
            ret = 2 + payload_size;
            break;

        case 0x1:   // single packet, with aditional header
            if (alp_len<3)  // at least 3 bytes
                return -1;
                
            ret = 3 + payload_size + (alp[2] >>3);
            break;

        case 0x2:   // segmented packet,
            if (alp_len<3)  // at least 3 bytes
                return -1;
            ret = 3 + payload_size + (alp[2] >>3);
            break;

        case 0x3:   // conscate packets (multiple packet)
            if (alp_len<3)  // at least 3 bytes
                return -1;                
            ret = 3 + payload_size + (alp[2] >>3);
        }
        // generic packet format
        ALP_DBG("alp_get_alp_size, Type=(Generic), payload_size=%d, length=%d\n", ret, payload_size, ret);        
    }

    return -1;
}


/*============================================
 * Func  : alp_parse_alp
 *
 * Desc  : parse ALP info
 *
 * Param : alp : pointer of alp packet
 *         alp_data_len : size of alp packet
 *         p_info : alp info output
 *
 * Retn  : <0 : fail
 *          others : successed
 *============================================*/
int alp_parse_alp(
    unsigned char*  alp,
    unsigned int    alp_data_len,
    alp_info*       p_info
    )
{
    int ret = 0;
    unsigned char packet_type;

    if (p_info==NULL || alp==NULL || alp_data_len==0)
    {
        ALP_WARNING("Parse ALP failed - invalid parameters\n");
        return -1;
    }

    packet_type = ALP_PACKET_TYPE(alp);

    switch(packet_type)
    {
    default:
    case ALP_PACKET_TYPE_ID_IPV4:
    case ALP_PACKET_TYPE_ID_COMPRESSED_IP_PACK:
    case ALP_PACKET_TYPE_ID_LINK_LAYER_SIGINALING_PACKET:
    case ALP_PACKET_TYPE_ID_PACKET_TYPE_EXTENSION:
        ALP_WARNING("Parse ALP failed - unsupported packet type - %d (%s)\n",
            packet_type, alp_packet_type_str(packet_type));
        return -1;

    case ALP_PACKET_TYPE_ID_MPEG_2_TS:
        ret = alp_parse_mpeg2_ts_alp(alp, alp_data_len, p_info);
        break;
    }

    return ret;
}

