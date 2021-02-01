#include <linux/kernel.h>
#include <linux/slab.h>
#include "alp_lib.h"
#include "bbp_lib.h"



#if 1

/*======================================================
 * Func  : bbp_parse_bbp
 *
 * Desc  : parse BBP info
 *
 * Param : bbp : pointer of bbp packet
 *         bbp_len : size of bbp packet
 *         p_info : bbp info output
 *
 * Retn  : <0 : fail
 *          others : successed
 *======================================================*/
int bbp_parse_bbp(
    unsigned char*  bbp,
    unsigned int    bbp_len,
    bbp_info*       p_info
    )
{    
    memset(p_info, 0, sizeof(bbp_info));

    if (bbp[0] & 0x80)
    {
        p_info->pointer = ((bbp[1]>>2)<<7)+(bbp[0] & 0x7F);
        p_info->ofi = bbp[1] & 0x3;

        switch (p_info->ofi)
        {
        case 0: // no optional no padding
            p_info->payload_start = bbp + 2;
            break;

        case 1:
            p_info->ext.type = bbp[2]>>5;
            p_info->ext.len  = bbp[2] & 0x1F;
            p_info->ext.data = bbp + 3;
            p_info->payload_start  = p_info->ext.data + p_info->ext.len;
            break;

        case 2:
        case 3:
            p_info->ext.type = bbp[2]>>5;
            p_info->ext.len  = (bbp[3]<<8)+(bbp[2]&0x1F);
            p_info->ext.data = bbp + 4;
            p_info->payload_start  = p_info->ext.data + p_info->ext.len;
            break;
        }
    }
    else
    {
        // Mode = 0: 1 byte header
        p_info->pointer = bbp[0] & 0x7F;
        p_info->payload_start = bbp + 1;
    }

    if (p_info->payload_start > bbp + bbp_len)      // out of bound
    {                
        BBP_WARNING("bbp_parse_bbp failed, payload out of bound\n");
        return -1;
    }

    p_info->payload_size = bbp + bbp_len - p_info->payload_start;

    BBP_DBG("bbp_parse_bbp, pointer=%u, payload_size =%u\n", 
            p_info->pointer,p_info->payload_size );        
        
    // parse payload ..............
    if (p_info->pointer != 8191)        // has ALPs
    {
        unsigned char* alp = p_info->payload_start;
        unsigned short payload_size = p_info->payload_size;
        int alp_cnt = 0;

        if (p_info->pointer!=0) // has ALP tail
        {
            p_info->alps[0].flags = ALP_TAIL;
            p_info->alps[0].data  = alp;
            p_info->alps[0].size  = p_info->pointer;
            alp += p_info->pointer;
            payload_size -= p_info->pointer;
            alp_cnt++;
        }

        // parse ALP info
        while(payload_size)
        {
            int alp_size = alp_get_alp_size(alp, payload_size);  // get size of alp

            if (payload_size >= alp_size)
            {
                // complete alps
                p_info->alps[alp_cnt].flags = ALP_HDR | ALP_TAIL;
                p_info->alps[alp_cnt].data  = alp;
                p_info->alps[alp_cnt].size  = alp_size;
                alp += alp_size;
                payload_size -= alp_size;
            }
            else
            {
                // header only...
                p_info->alps[alp_cnt].flags = ALP_HDR;
                p_info->alps[alp_cnt].data  = alp;
                p_info->alps[alp_cnt].size  = payload_size;
                alp += payload_size;
                payload_size = 0;
            }
            
            BBP_DBG("ALP[%d] data=%p, size=%u, flags=%x\n", 
                    alp_cnt,
                    p_info->alps[alp_cnt].data,
                    p_info->alps[alp_cnt].size,
                    p_info->alps[alp_cnt].flags);
            
            alp_cnt++;
        }
        
        p_info->n_alps = alp_cnt;
    }

    return 0;
}

#endif



/*======================================================
 * Func  : bbp_get_header_size
 *
 * Desc  : get size of BBP header
 *
 * Param : bbp : pointer of bbp packet
 *         bbp_len : size of bbp packet 
 *
 * Retn  : <0 : fail
 *          others : bbp header size
 *======================================================*/
int bbp_get_header_size(
    unsigned char*  bbp,
    unsigned int    bbp_len
    )
{
    int ret = -1;

    if ((bbp[0] & 0x80)==0)
    {
        ret = 1;
    }
    else
    {
        if (bbp_len < 2)
            goto end_proc;

        switch (bbp[1] & 0x3)
        {
        case 0: // no optional no padding
            ret = 2;
            break;
        case 1:
            if (bbp_len < 3)
                goto end_proc;

            ret = 3 + (bbp[3] & 0x1F);
            break;

        case 2:
        case 3:
            if (bbp_len < 4)
                goto end_proc;

            ret = 4 + (bbp[3]<<5)+(bbp[2]&0x1F);
            break;
        }
    }

end_proc:
    BBP_DBG("bbp_get_header_size HDR = {%02x %02x %02x %02x } size=%d\n",
            bbp[0], bbp[1], bbp[2], bbp[3], ret);

    return ret;
}



/*======================================================
 * Func  : bbp_generate_bbp_hdr
 *
 * Desc  : generate bbp hdr
 *
 * Param : p_buff  : header buffer
 *         buff_sz : size of bbp header
 *         p_ext   : extenstion field
 *         n_ext   : bytes of extension field
 *         pointer : pointer field
 *
 * Retn  : <0 : fail
 *          others : successed
 *======================================================*/
int bbp_generate_bbp_hdr(
    unsigned char*      p_buff,
    unsigned int        buff_sz,
    unsigned char*      p_ext,
    unsigned short      n_ext,
    unsigned char       ext_type,
    unsigned short      pointer
    )
{
    if (pointer < 0x80 && p_ext==NULL)
    {
        // mode 0:
        *p_buff = pointer & 0x7F;
        return 1;
    }
    else
    {
        p_buff[0] = 0x80 | (pointer & 0x7F);    // pointer LSB (7b)
        p_buff[1] = ((pointer>>7) & 0x3F)<<2;        // pointer MSB (6b)

        if (p_ext==NULL)
        {
            // OFI = no extension
            return 2;
        }
        else if (n_ext < 0x20)
        {
            // OFI = short extension
            p_buff[1] |= 0x1;
            p_buff[2] = ((ext_type & 0x7) <<5) | n_ext;
            memcpy(&p_buff[3], p_ext, n_ext);
            return 3 + n_ext;
        }
        else if (n_ext < 8192)
        {
            // OFI = long extension
            p_buff[1] |= 0x2;
            p_buff[2] = ((ext_type & 0x7) <<5) | (n_ext & 0x1F);    // EXT_LEN (LSB)
            p_buff[3] = (n_ext >> 5) & 0xFF;
            memcpy(&p_buff[4], p_ext, n_ext);
            return 4 + n_ext;
        }
    }

    return -1;
}




/*======================================================
 * Func  : bbp_dump_bbp_info
 *
 * Desc  : dump bbp info
 *
 * Param : p_info  : bbp info
 *
 * Retn  : N/A
 *======================================================*/
void bbp_dump_bbp_info(bbp_info* p_info)
{
    int i;

    if (p_info==NULL)
        return;

    BBP_INFO("BBP CTX, pointer=%d, ext={%p, %u}, payload={%p, %u}, n_alp=%u\n",
             p_info->pointer,
             p_info->ext.data,
             p_info->ext.len,
             p_info->payload_start,
             p_info->payload_size,             
             p_info->n_alps);

    for (i = 0; i<p_info->n_alps; i++)
    {
        BBP_INFO("BBP ALP[%d]={%p, %u, %x}\n",
            i,
             p_info->alps[i].data,
             p_info->alps[i].size,
             p_info->alps[i].flags);
    }
}