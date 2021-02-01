#ifndef __ALP_DEF_H__
#define __ALP_DEF_H__

typedef enum {
    ALP_PACKET_TYPE_ID_IPV4 = 0x0,
    ALP_PACKET_TYPE_ID_COMPRESSED_IP_PACK = 0x2,
    ALP_PACKET_TYPE_ID_LINK_LAYER_SIGINALING_PACKET = 0x4,
    ALP_PACKET_TYPE_ID_PACKET_TYPE_EXTENSION = 0x6,
    ALP_PACKET_TYPE_ID_MPEG_2_TS = 0x7
}ALP_PACKET_TYPE_ID;

#define ALP_PACKET_TYPE(alp)    ((alp[0] >>5) & 0x7)
#define ALP_HDR_PACKET_TYPE(x)    ((x & 0x7)<<5)

////////////////////////////////////

// Generic ALP
#define ALP_LENGTH(alp)     (((alp[0] & 0x7)<<8) + alp[1])

// for MEPG TS
#define ALP_MPEG_TS_AHR_HDM     0x80
#define ALP_MPEG_TS_HDR_AHF     0x01
#define ALP_MPEG_TS_HDR_NUMTS(x)    ((x & 0xF)<<1)

#define ALP_NUM_TS(alp)         ((alp[0]>>1) & 0xF)
#define ALP_AHF(alp)            (alp[0] & ALP_MPEG_TS_HDR_AHF)
#define ALP_HDM(alp)            (alp[1] & ALP_MPEG_TS_AHR_HDM)

#endif
