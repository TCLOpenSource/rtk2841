#include <linux/kernel.h>
#include <linux/slab.h>
#include "oif_lib.h"

#define OIF_HDR_SIZE        8
#define OIF_HDR_ERR_EN      (1<<7)
#define OIF_HDR_ERR         (1<<6)

int oif_encapsulate_bbf(
    unsigned char*      bbf, 
    unsigned short      bbf_sz, 
    unsigned char*      out, 
    unsigned long       out_len, 
    unsigned char       plp,
    unsigned char*      p_cc,
    unsigned char       err
    )
{
    if (out_len < bbf_sz + OIF_HDR_SIZE)
        return -1;
                      
    memset(out, 0x5A, 4);
    out[4]= plp & 0x3F;
    
    if (err)    
        out[4] |= OIF_HDR_ERR_EN | OIF_HDR_ERR;     // err & err_en

    out[5] = (bbf_sz>>8) & 0xFF;
    out[6] = (bbf_sz) & 0xFF;
    out[7] = *p_cc;            
    *p_cc = out[7]+1;               
    
    printk("cc=%d\n", out[7]);  
    
    memcpy(out + OIF_HDR_SIZE, bbf, bbf_sz);
    
    return bbf_sz + OIF_HDR_SIZE;
}



unsigned char* oif_find_starter(
    unsigned char*      oif, 
    unsigned long       oif_len
    )
{    
    while(oif_len >= 4)
    {        
        if (*((unsigned int*)oif) == OIF_STARTER_VAL) {
            //printk("find stater = %p\n", oif);        
            return oif;
        }
        oif++;   
        oif_len--;                     
    }
    
    printk("find stater failed\n", oif);        
    
    return NULL;    
}

