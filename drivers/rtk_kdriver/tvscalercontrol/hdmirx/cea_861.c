#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/string.h>
#include "hdmi_edid.h"
#include "hdmi_debug.h"
#include "cea_861.h"

const VIC_TIMING_INFO vic_timing[] =
{   // vic, , field_rate
    {  1,    640,  480 },
    {  2,    720,  480 },
    {  3,    720,  480 },
    {  4,   1280,  720 },
    {  5,   1920, 1080 },
    {  6,   1440,  480 },
    {  7,   1440,  480 },
    {  8,   1440,  240 },
    {  9,   1440,  240 },
    { 10,   2880,  480 },
    { 11,   2880,  480 },
    { 12,   2880,  240 },
    { 13,   2880,  240 },
    { 14,   1440,  480 },
    { 15,   1440,  480 },
    { 16,   1920, 1080 },
    { 17,    720,  576 },
    { 18,    720,  576 },
    { 19,   1280,  720 },
    { 20,   1920, 1080 },
    { 21,   1440,  576 },
    { 22,   1440,  576 },
    { 23,   1440,  288 },
    { 24,   1440,  288 },
    { 25,   2880,  576 },
    { 26,   2880,  576 },
    { 27,   2880,  288 },
    { 28,   2880,  288 },
    { 29,   1440,  576 },
    { 30,   1440,  576 },
    { 31,   1920, 1080 },
    { 32,   1920, 1080 },
    { 33,   1920, 1080 },
    { 34,   1920, 1080 },
    { 35,   2880,  480 },
    { 36,   2880,  480 },
    { 37,   2880,  576 },
    { 38,   2880,  576 },
    { 39,   1920, 1080 },
    { 40,   1920, 1080 },
    { 41,   1280,  720 },
    { 42,    720,  576 },
    { 43,    720,  576 },
    { 44,   1440,  576 },
    { 45,   1440,  576 },
    { 46,   1920, 1080 },
    { 47,   1280,  720 },
    { 48,    720,  480 },
    { 49,    720,  480 },
    { 50,   1440,  480 },
    { 51,   1440,  480 },
    { 52,    720,  576 },
    { 53,    720,  576 },
    { 54,   1440,  576 },
    { 55,   1440,  576 },
    { 56,    720,  480 },
    { 57,    720,  480 },
    { 58,   1440,  480 },
    { 59,   1440,  480 },
    { 60,   1280,  720 },
    { 61,   1280,  720 },
    { 62,   1280,  720 },
    { 63,   1920, 1080 },
    { 64,   1920, 1080 },
    { 65,   1280,  720 },
    { 66,   1280,  720 },
    { 67,   1280,  720 },
    { 68,   1280,  720 },
    { 69,   1280,  720 },
    { 70,   1280,  720 },
    { 71,   1280,  720 },
    { 72,   1920, 1080 },
    { 73,   1920, 1080 },
    { 74,   1920, 1080 },
    { 75,   1920, 1080 },
    { 76,   1920, 1080 },
    { 77,   1920, 1080 },
    { 78,   1920, 1080 },
    { 79,   1680,  720 },
    { 80,   1680,  720 },
    { 81,   1680,  720 },
    { 82,   1680,  720 },
    { 83,   1680,  720 },
    { 84,   1680,  720 },
    { 85,   1680,  720 },
    { 86,   2560, 1080 },
    { 87,   2560, 1080 },
    { 88,   2560, 1080 },
    { 89,   2560, 1080 },
    { 90,   2560, 1080 },
    { 91,   2560, 1080 },
    { 92,   2560, 1080 },
    { 93,   3840, 2160 },
    { 94,   3840, 2160 },
    { 95,   3840, 2160 },
    { 96,   3840, 2160 },
    { 97,   3840, 2160 },
    { 98,   4096, 2160 },
    { 99,   4096, 2160 },
    {100,   4096, 2160 },
    {101,   4096, 2160 },
    {102,   4096, 2160 },
    {103,   3840, 2160 },
    {104,   3840, 2160 },
    {105,   3840, 2160 },
    {106,   3840, 2160 },
    {107,   3840, 2160 },
    {108,   1280,  720 },
    {109,   1280,  720 },
    {110,   1680,  720 },
    {111,   1920, 1080 },
    {112,   1920, 1080 },
    {113,   2560, 1080 },
    {114,   3840, 2160 },
    {115,   4096, 2160 },
    {116,   3840, 2160 },
    {117,   3840, 2160 },
    {118,   3840, 2160 },
    {119,   3840, 2160 },
    {120,   3840, 2160 },
    {121,   5120, 2160 },
    {122,   5120, 2160 },
    {123,   5120, 2160 },
    {124,   5120, 2160 },
    {125,   5120, 2160 },
    {126,   5120, 2160 },
    {127,   5120, 2160 },
    {193,   5120, 2160 },
    {194,   7680, 4320 },
    {195,   7680, 4320 },
    {196,   7680, 4320 },
    {197,   7680, 4320 },
    {198,   7680, 4320 },
    {199,   7680, 4320 },
    {200,   7680, 4320 },
    {201,   7680, 4320 },
    {202,   7680, 4320 },
    {203,   7680, 4320 },
    {204,   7680, 4320 },
    {205,   7680, 4320 },
    {206,   7680, 4320 },
    {207,   7680, 4320 },
    {208,   7680, 4320 },
    {209,   7680, 4320 },
    {210,  10240, 4320 },
    {211,  10240, 4320 },
    {212,  10240, 4320 },
    {213,  10240, 4320 },
    {214,  10240, 4320 },
    {215,  10240, 4320 },
    {216,  10240, 4320 },
    {217,  10240, 4320 },
    {218,   4096, 2160 },
    {219,   4096, 2160 },
};



/*--------------------------------------------
 * Func : _get_vic_timing
 *
 * Desc : get timing information of a given VIC
 *
 * Para : vic : (I) VIC  
 *
 * Retn : NULL : no Video timing of the given VIC
 *        others : handle of the VIC timing info
 *-------------------------------------------*/
const VIC_TIMING_INFO* _get_vic_timing(unsigned char vic)
{
    int i;
    for (i=0; i<sizeof(vic_timing)/sizeof(VIC_TIMING_INFO); i++)
    {
        if (vic_timing[i].vic == vic)
            return &vic_timing[i];
    }
    return NULL;
}


/*--------------------------------------------
 * Func : _hdmi_vic_to_vic
 *
 * Desc : convert hdmi vic to vic.
 *        hdmi vic is a VIC that defined by HDMI 
 *        forum for 4Kx2K resolution extension. 
 *        For detail information, please check HDMI spec 1.4b 
 *        section 8.2.3.1
 *
 * Para : hdmi_vic : (I) hdmi_vic  
 *
 * Retn : 0 : unknow hdmi_vic
 *        others : associated vic value
 *-------------------------------------------*/
unsigned char _hdmi_vic_to_vic(unsigned char hdmi_vic)
{
    // mapping hdmi vic to CTA-861-G VIC
    // The mapping is specified on HDMI 2.0a table 10-2
    
    switch(hdmi_vic)
    {
    case 1:  return 95;
    case 2:  return 94;
    case 3:  return 93;
    case 4:  return 98;
    default: return 0;
    }
}


/*--------------------------------------------
 * Func : _svd_to_vic
 *
 * Desc : convert svd (short Video) to vic.  
 *
 * Para : svd : (I) SVD  
 *
 * Retn : vic : vic number 
 *-------------------------------------------*/
unsigned char _svd_to_vic(unsigned char svd)
{
    // CEA-861-F section 7-5.1 - Video Data block
    if ((svd >= 65 && svd <= 127) ||
        (svd >= 193 && svd <= 255))
        return svd;

    return (svd & (~0x80));
}


/*--------------------------------------------
 * Func : _parse_cea_ext_blk_info
 *
 * Desc : extrat cea ext block information of the 
 *        given EDID. the cea ext block info will
 *        find out each field of the given CEA 
 *        ext block. to ease data analysis and 
 *        modification      
 *
 * Para : edid : (I) EDID
 *        p_info : (O) CEA_EXT_BLOCK info output
 *
 * Retn : 0 : successed, -1 : failed
 *-------------------------------------------*/
int _parse_cea_ext_blk_info(unsigned char edid[128], CEA_EXT_BLK_INFO* p_info)
{
    if (edid==NULL || p_info==NULL)
    {
        HDMI_EDID_DBG("Parse hdmi edid failed, invalid parameters\n");
        return -1;
    }

    memset(p_info, 0, sizeof(CEA_EXT_BLK_INFO));

    p_info->hdr = *((CEA_EXT_HDR*) edid);

    HDMI_EDID_DBG("_parse_cea_ext_blk_info : EDID (%p) = %02x %02x %02x %02x ...\n", edid, edid[0], edid[1], edid[2], edid[3]);
    HDMI_EDID_DBG("_parse_cea_ext_blk_info : Tag : %d, Rev=%d, dtd_ofst=%d", p_info->hdr.tag, p_info->hdr.revision, p_info->hdr.dtd_ofst);
    HDMI_EDID_DBG("_parse_cea_ext_blk_info : undescan : %d, audio=%d, YCbCr444=%d, YCbCr422=%d, n_dtd=%d\n",
                p_info->hdr.undescan, p_info->hdr.audio, p_info->hdr.YCbCr444, p_info->hdr.YCbCr422,
                p_info->hdr.n_dtd);

    if (p_info->hdr.tag != 0x2 || p_info->hdr.revision != 0x3)
    {
        HDMI_EDID_DBG("Parse hdmi edid failed, invalid parameters\n");
        return -1;
    }

    if (p_info->hdr.dtd_ofst >=4)
    {
        unsigned char cdb_size = p_info->hdr.dtd_ofst - 4;
        int i;
        CEA_DATA_BLOCK* p_cdb;

        if ((p_info->hdr.dtd_ofst + (sizeof(CEA_DTD_BLK) * p_info->hdr.n_dtd)) > 127 )
        {
            HDMI_EDID_DBG("Parse hdmi edid failed, check dtd size failed (dtd_ofst=%d, p_info->hdr.n_dtd=%d (%d))\n",
                    p_info->hdr.dtd_ofst, p_info->hdr.n_dtd, sizeof(CEA_DTD_BLK));
            return -1;
        }

        // cea data block collection
        p_cdb = (CEA_DATA_BLOCK*) &edid[4];

        while (cdb_size)
        {
            unsigned char cdb_len = CEA_DATA_BLOCK_SIZE(p_cdb);

            if (cdb_len > cdb_size)
            {
                HDMI_EDID_DBG("Parse hdmi edid failed, parse cea data block failed, incomplete cea data block\n");
                break;
            }

            HDMI_EDID_DBG("_parse_cea_ext_blk_info : CDB[%d] = %p\n", p_info->n_cdb, p_cdb);
            p_info->p_cdb[p_info->n_cdb++] = p_cdb;
            p_cdb = (CEA_DATA_BLOCK*)((unsigned char*) p_cdb + cdb_len);
            cdb_size -= cdb_len;
        }

        // record address of dtd blocks
        for (i=0; i< p_info->hdr.n_dtd; i++) {
            p_info->p_dtd[i] = (CEA_DTD_BLK*) &edid[p_info->hdr.dtd_ofst + (i * sizeof(CEA_DTD_BLK))];
            HDMI_EDID_DBG("_parse_cea_ext_blk_info : DTD[%d] = %p\n", i, p_info->p_dtd[i]);
        }
    }
    else if (p_info->hdr.dtd_ofst==0)
    {
        if (p_info->hdr.n_dtd !=0)
        {
            HDMI_EDID_DBG("Parse hdmi edid failed, invalid parameters, n_dtd shoulbe be 0 when dtd_ofst is 0\n");
            return -1;
        }
        // no CEC data block collections, no nothing
    }
    else if (p_info->hdr.dtd_ofst > 0)
    {
        HDMI_EDID_DBG("Parse hdmi edid failed, invalid parameters, n_dtd shoulbe be 0 when dtd_ofst is 0\n");
        return -1;
    }

    p_info->checksum = edid[127];
    return 0;
}



/*--------------------------------------------
 * Func : _dump_cea_ext_blk_info
 *
 * Desc : dump information of a given cea ext block  
 *
 * Para : p_info : (I) CEA_EXT_BLOCK info
 *
 * Retn : N/A
 *-------------------------------------------*/
void _dump_cea_ext_blk_info(CEA_EXT_BLK_INFO* p_info)
{
    int i;

    HDMI_EDID_DBG("_dump_cea_ext_blk_info : Tag=%d, Rev=%d, dtd_ofst=%d", p_info->hdr.tag, p_info->hdr.revision, p_info->hdr.dtd_ofst);

    HDMI_EDID_DBG("_dump_cea_ext_blk_info : undescan : %d, audio=%d, YCbCr444=%d, YCbCr422=%d, n_dtd=%d\n",
                p_info->hdr.undescan, p_info->hdr.audio, p_info->hdr.YCbCr444, p_info->hdr.YCbCr422,
                p_info->hdr.n_dtd);

    HDMI_EDID_DBG("_dump_cea_ext_blk_info : n_cdb=%d,\n", p_info->n_cdb);

    for (i=0; i<p_info->n_cdb; i++)
    {
        CEA_DATA_BLOCK* p_cdb = p_info->p_cdb[i];

        if (p_cdb)
            HDMI_EDID_DBG("_dump_cea_ext_blk_info : CDB[%d] : tag=%d, length=%d\n", i, p_cdb->tag, p_cdb->length);
    }

    for (i=0; i<p_info->hdr.n_dtd; i++)
    {
        CEA_DTD_BLK* p_dtd = p_info->p_dtd[i];

        if (p_dtd)
        {
            HDMI_EDID_DBG("_dump_cea_ext_blk_info : DTD[%d] : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n",
                i, p_dtd->data[0], p_dtd->data[1], p_dtd->data[2], p_dtd->data[3], p_dtd->data[4], p_dtd->data[5], p_dtd->data[6],
                p_dtd->data[7], p_dtd->data[8], p_dtd->data[9], p_dtd->data[10], p_dtd->data[11], p_dtd->data[12], p_dtd->data[13],
                p_dtd->data[14], p_dtd->data[15], p_dtd->data[16], p_dtd->data[17]);
        }
    }

    HDMI_EDID_DBG("_dump_cea_ext_blk_info : CheckSum : %02x\n", p_info->checksum);
}


/*--------------------------------------------
 * Func : _compute_checksum
 *
 * Desc : compute checksum value a given data  
 *
 * Para : p_data : (I) p_data
 *        len    : (I) len
 *
 * Retn : 8 bits sum of the input data
 *-------------------------------------------*/
unsigned char _compute_checksum(unsigned char* p_data, unsigned char len)
{
    unsigned char cs = 0;

    while(len--)
        cs += *p_data++;

    return cs;
}


/*--------------------------------------------
 * Func : _parse_vsdb_info
 *
 * Desc : extrat information of a given VSDB
 *
 * Para : edid : (I) EDID
 *        p_info : (O) CEA_EXT_BLOCK info output
 *
 * Retn : 0 : successed, -1 : failed
 *-------------------------------------------*/
int _parse_vsdb_info(CEA_DATA_BLOCK *p_vsdb, CEA_HDMI_VSDB_INFO* p_info)
{
    unsigned char* p_data = &p_vsdb->data[8];

    memset(p_info, 0, sizeof(CEA_HDMI_VSDB_INFO));

    p_info->p_hdr = (CEA_HDMI_VSDB_HEAD*) p_vsdb;

    if (p_info->p_hdr->tag !=0x3 ||
        p_vsdb->length < 5 ||
        p_info->p_hdr->oui[0]!=0x03 ||
        p_info->p_hdr->oui[1]!=0x0C ||
        p_info->p_hdr->oui[2]!=0x00)
    {
        HDMI_EDID_DBG("_parse_vsdb_info failed, check tag & oui failed\n");
        return -1;
    }

    if (p_vsdb->length < 8)
        return 0;

    if (p_info->p_hdr->latency_present)
    {
        p_info->p_latency= (CEA_HDMI_VSDB_LATENCY*) p_data;
        p_data += sizeof(CEA_HDMI_VSDB_LATENCY);
    }

    if (p_info->p_hdr->i_latency_present)
    {
        p_info->p_i_latency= (CEA_HDMI_VSDB_LATENCY*) p_data;
        p_data += sizeof(CEA_HDMI_VSDB_LATENCY);
    }

    if (p_info->p_hdr->hdmi_video_present)
    {
        p_info->p_video= (CEA_HDMI_VSDB_VIDEO_HDR*) p_data;
        p_data += sizeof(CEA_HDMI_VSDB_VIDEO_HDR);

        if (p_info->p_video->hdmi_vic_len)
        {
            p_info->p_hdmi_vic = p_data;
            p_data += p_info->p_video->hdmi_vic_len;
        }

        if (p_info->p_video->hdmi_3d_len)
        {
            p_info->p_hdmi_3d_data = p_data;
            p_data += p_info->p_video->hdmi_3d_len;
        }
    }

    if (p_data > p_vsdb->data + p_vsdb->length)
    {
        HDMI_EDID_DBG("_parse_vsdb_info failed, incomplete vsdb\n");
        return -1;
    }

    return 0;
}


/*--------------------------------------------
 * Func : _dump_vsdb_info
 *
 * Desc : dump inforamtion of a Vendor Specific 
 *        Data Block
 *
 * Para : p_info : (I) VSDB information
 *
 * Retn : N/A
 *-------------------------------------------*/
void _dump_vsdb_info(CEA_HDMI_VSDB_INFO* p_info)
{
    CEA_HDMI_VSDB_HEAD* p_hdr = p_info->p_hdr;
    HDMI_EDID_DBG("_dump_vsdb_info : tag=%02x, len=%d, oui=%02x%02x%02x, PA=%d.%d.%d.%d\n",
        p_hdr->tag, p_hdr->length,
        p_hdr->oui[0], p_hdr->oui[1], p_hdr->oui[2],
        p_hdr->A, p_hdr->B, p_hdr->C, p_hdr->D);

    if (p_info->p_hdmi_vic)
        HDMI_EDID_DBG("_dump_vsdb_info : hdmi_vic_len=%d\n", 
            p_info->p_video->hdmi_vic_len);

    if (p_info->p_hdmi_3d_data)
        HDMI_EDID_DBG("_dump_vsdb_info : hdmi_3d_len=%d\n", 
            p_info->p_video->hdmi_3d_len);
}


/*--------------------------------------------
 * Func : _parse_dtd_info
 *
 * Desc : extraction information of a given DTD
 *
 * Para : p_dtd  : (I) DTD data block
 *        p_info : (O) DTD information output
 *
 * Retn : 0 : success
 *-------------------------------------------*/
int _parse_dtd_info(CEA_DTD_BLK* p_dtd, CEA_DTD_INFO* p_info)
{
    unsigned char* data = p_dtd->data;

    p_info->pixel_clock = (data[1]<<8) + data[0];
    p_info->h_active = (DTD_H_ACT_H(data[4])<<8) + data[2];
    p_info->h_blank  = (DTD_H_BLANKING_H(data[4])<<8) + data[3];
    p_info->v_active = (DTD_V_ACT_H(data[7])<<8) + data[5];
    p_info->v_blank  = (DTD_V_BLANKING_H(data[7])<<8) + data[6];
    return 0;
}


/*--------------------------------------------
 * Func : _gen_hdmi_edid
 *
 * Desc : generate hdmi edid via cea ext block info
 *
 * Para : p_info : (I) CEC ext block information
 *        edid_out : (O) EDID output 
 *
 * Retn : 0 : success
 *-------------------------------------------*/
int _gen_hdmi_edid(CEA_EXT_BLK_INFO* p_info, unsigned char edid_out[128])
{
    unsigned char   tmp[128];
    CEA_EXT_HDR*    p_hdr = (CEA_EXT_HDR*) tmp;
    CEA_DATA_BLOCK* p_cdb = (CEA_DATA_BLOCK*)(tmp + sizeof(CEA_EXT_HDR));
    CEA_DTD_BLK*    p_dtd;
    int i;

    memset(tmp, 0, sizeof(tmp));

    //-------------------------------------
    // copy header
    //-------------------------------------
    *p_hdr = p_info->hdr;
    p_hdr->dtd_ofst = sizeof(CEA_EXT_HDR); // init dtd ofset
    p_hdr->n_dtd = 0;

    //-------------------------------------
    // copy cdb collections
    //-------------------------------------
    if (p_info->n_cdb)
    {
        for (i=0; i<p_info->n_cdb; i++)
        {
            HDMI_EDID_DBG("copy CDB[%d/%d]=%p, tag=%d, len=%d, dtd_ofst=%d\n",
                    i, p_info->n_cdb, p_info->p_cdb[i], p_info->p_cdb[i]->tag,
                    CEA_DATA_BLOCK_SIZE(p_info->p_cdb[i]), p_hdr->dtd_ofst );

            if (p_info->p_cdb[i])
            {
                unsigned char cdb_len = CEA_DATA_BLOCK_SIZE(p_info->p_cdb[i]);
                memcpy(p_cdb, p_info->p_cdb[i], cdb_len);
                p_hdr->dtd_ofst += cdb_len;     // update dtd offset
                p_cdb = (CEA_DATA_BLOCK*) (tmp + p_hdr->dtd_ofst);
            }
        }
    }

    //-------------------------------------
    // copy dtds
    //-------------------------------------
    p_dtd = (CEA_DTD_BLK*) (tmp + p_hdr->dtd_ofst);

    for (i=0; i<6; i++)
    {
        if (p_info->p_dtd[i])
        {
            *p_dtd++ = *p_info->p_dtd[i];  // copy dtd
            p_hdr->n_dtd++;
        }
    }

    if (p_hdr->n_dtd==0)
        p_hdr->dtd_ofst = 0;   // if no dtd exists

    //-------------------------------------
    // compute checksum
    //-------------------------------------
    tmp[127] = (0x100 - _compute_checksum(tmp, 127)) & 0xFF;

    memcpy(edid_out, tmp, 128);
    return 0;
}

