#include <linux/kernel.h>
#include <linux/slab.h>
#include "atsc3_dmx.h"
#include "oif_lib.h"

#define malloc(size)        kmalloc(size, GFP_KERNEL)
#define free(addr)          kfree(addr)

#if 0

/*======================================================
 * Func  : _dmx_thread_func
 *
 * Desc  : demux thread
 *
 * Param :
 *
 * Retn  :
 *======================================================*/
static void* _dmx_thread_func(void * const data)
{
    struct atsc3_dmx* p_this = (struct atsc3_dmx*) data;

    while((p_this->flags & DMX_FLAG_THREAD_STOP)==0)
    {
        p_this->ops.run(p_this);
        usleep(10000);
    }

    p_this->flags &= ~(DMX_FLAG_THREAD_STOP | DMX_FLAG_THREAD_START);
}




/*======================================================
 * Func  : atsc3_dmx_start
 *
 * Desc  : start atsc3 demux
 *
 * Param : handle of atsc3 dmx
 *
 * Retn  : 0 : successed, oethers failed
 *======================================================*/
int atsc3_dmx_start(struct atsc3_dmx* p_this)
{
    ATSC3_DMX_TRACE();

    if (p_this==NULL /*|| p_this->p_in==NULL*/)
    {
        ATSC3_DMX_WARN("Enable ATSC 3.0 demux failed, invalid parameters\n");
        return -1;
    }

    // start thread here
    if (p_this->flags & DMX_FLAG_THREAD_START)
        return 0;

    p_this->flags &= ~DMX_FLAG_THREAD_STOP;
    p_this->flags |=  DMX_FLAG_THREAD_START;

    if (pthread_create(&p_this->thread_id, NULL, _dmx_thread_func, p_this))
    {
        p_this->flags &= ~DMX_FLAG_THREAD_START;
        return -1;
    }

    return 0;
}



/*======================================================
 * Func  : atsc3_dmx_stop
 *
 * Desc  : stop atsc3 demux
 *
 * Param : handle of atsc3 dmx
 *
 * Retn  : 0 : successed, oethers failed
 *======================================================*/
int atsc3_dmx_stop(struct atsc3_dmx* p_this)
{
    ATSC3_DMX_TRACE();

    if (p_this==NULL)
    {
        ATSC3_DMX_WARN("Enable ATSC 3.0 demux failed, invalid parameters\n");
        return -1;
    }

    // stop thread here
    p_this->flags |= DMX_FLAG_THREAD_STOP;
    
    pthread_cancel(p_this->thread_id);
    
    return 0;
}

#endif


/*======================================================
 * Func  : atsc3_dmx_run
 *
 * Desc  : stop atsc3 demux
 *
 * Param : handle of atsc3 dmx
 *
 * Retn  : 0 : successed, oethers failed
 *======================================================*/
int atsc3_dmx_run(struct atsc3_dmx* p_this)
{
    struct atsc3_ring* p_in = p_this->p_in;
    unsigned char* p_rp, p_oif;
    unsigned long len;
    unsigned long flags;
    ATSC3_DMX_TRACE();

    while (p_in->ops.read_data(p_in, &p_rp, &len, &flags)==0 && len)
    {                
        ATSC3_DMX_DBG("read data from ring (%p) = { %02x.%02x.%02x.%02x....%02x.%02x.%02x.%02x }\n",
                    p_rp,
                    p_rp[0], p_rp[1], p_rp[2], p_rp[3], 
                    p_rp[len-4], p_rp[len-3], p_rp[len-2], p_rp[len-1]);
                    
        if (p_this->bbp_excepted_zize==0)
        {
            // fid header header....
            unsigned char* p_oif = oif_find_starter(p_rp, len);
            unsigned int   data_len;

            if (p_oif==NULL)
            {
                p_in->ops.release_data(p_in, p_rp, len);
                return 0;
            }            

            if (p_oif > p_rp)
            {
                // release spare data...
                data_len = (unsigned int)(p_oif - p_rp);
                p_in->ops.release_data(p_in, p_rp, data_len);
                len  -= data_len;
                p_rp  = p_oif;
            }                        

            ATSC3_DMX_DBG("Got OIF hdr(%p) = { %02x.%02x.%02x.%02x_%02x.%02x.%02x.%02x }\n",
                    p_rp,
                    p_rp[0], p_rp[1], p_rp[2], p_rp[3], 
                    p_rp[4], p_rp[5], p_rp[6], p_rp[7]);
                    
            if (len<8)   // data less than 8 bytes
            {
                p_this->bbp_excepted_zize = 8;
                p_this->bbp_buff_zize     = len;            // minimum size...
                memcpy(p_this->bbp_buffer, p_rp, len);      // store temp buffer                
                p_in->ops.release_data(p_in, p_rp, len);    // release data
                continue;
            }
            else
            {                                                                                                                
                // a complete packet header
                p_this->bbp_plp = p_rp[4] & 0x1F;
                p_this->bbp_excepted_zize = 8 + (p_rp[5]<<8) + (p_rp[6]);
                p_this->bbp_cc  = p_rp[7];
                                                
                if (len >= p_this->bbp_excepted_zize)
                {
                    ATSC3_DMX_DBG("complete data block, just deliver it\n");
                    
                    // a complete data block : dispatch data directly
#ifdef ATSC3_DMX_DELIVER_OIF_HEADER
                    p_this->cb.callback(p_this->cb.p_ctx, p_this->bbp_plp, p_rp, p_this->bbp_excepted_zize);
#else
                    p_this->cb.callback(p_this->cb.p_ctx, p_this->bbp_plp + 8, p_rp, p_this->bbp_excepted_zize -8);
#endif                    
                    p_in->ops.release_data(p_in, p_rp, p_this->bbp_excepted_zize);
                    p_this->bbp_excepted_zize = 0;
                    p_this->bbp_buff_zize = 0;                    
                    continue;
                }
                else
                {
                    // part of block... : store it in the internal buffer
                    memcpy(p_this->bbp_buffer, p_rp, len);
                    p_this->bbp_buff_zize = len;                    
                    p_in->ops.release_data(p_in, p_rp, len);
                    
                    ATSC3_DMX_DBG("part of data block, collect it, buff_size=%u, excepted size=%u\n", 
                        p_this->bbp_buff_zize, p_this->bbp_excepted_zize);
                    continue;
                }
            }
        }
        else if (p_this->bbp_excepted_zize==8)
        {                    
            // collecting header....            
            ATSC3_DMX_DBG("collect data header, len = %u, buff_size=%u, excepted size=%u\n", 
                    len, p_this->bbp_buff_zize, p_this->bbp_excepted_zize);
                  
            int data_len = 8 - p_this->bbp_buff_zize;
            
            if (data_len > len)
                data_len = len;
            
            memcpy(p_this->bbp_buffer, p_rp, data_len);                  
            p_this->bbp_buff_zize += data_len;                  
            p_in->ops.release_data(p_in, p_rp, data_len);  
                
            if (p_this->bbp_buff_zize == p_this->bbp_excepted_zize)
            {                                                                              
                // parse header
                p_this->bbp_plp = p_this->bbp_buffer[4] & 0x1F;
                p_this->bbp_excepted_zize += (p_this->bbp_buffer[5]<<8) + (p_this->bbp_buffer[6]);                  
                p_this->bbp_cc  = p_this->bbp_buffer[7];                                                                      
                continue;                
            }
        }
        else
        {
            ATSC3_DMX_DBG("collect data block, len = %u, buff_size=%u, excepted size=%u\n", 
                    len, p_this->bbp_buff_zize, p_this->bbp_excepted_zize);
                    
            // collecting data
            int data_len = p_this->bbp_excepted_zize - p_this->bbp_buff_zize;   // remain size    
            
            if (data_len > len)            
                data_len = len;
                
            memcpy(p_this->bbp_buffer + p_this->bbp_buff_zize, p_rp, data_len);                
            p_in->ops.release_data(p_in, p_rp, data_len);
            
            p_this->bbp_buff_zize += data_len;
            
            if (p_this->bbp_buff_zize >= p_this->bbp_excepted_zize)
            {
                // complete block
#ifdef ATSC3_DMX_DELIVER_OIF_HEADER                
                p_this->cb.callback(p_this->cb.p_ctx, p_this->bbp_plp, p_this->bbp_buffer, p_this->bbp_excepted_zize);
#else
                p_this->cb.callback(p_this->cb.p_ctx, p_this->bbp_plp, p_this->bbp_buffer + 8, p_this->bbp_excepted_zize - 8);
#endif                
                p_this->bbp_excepted_zize = 0;
                p_this->bbp_buff_zize = 0;
            }                
        }        
    }        

    return 0;
}



/*======================================================
 * Func  : create_atsc3_dmx
 *
 * Desc  : create a atsc3 demux
 *
 * Param : p_dmx_in : input buffer
 *
 * Retn  : handle of atsc3 dmx
 *======================================================*/
struct atsc3_dmx* create_atsc3_dmx(
    struct dmx_callback*        p_cb,
    struct atsc3_ring*          p_dmx_in
    )
{
    struct atsc3_dmx* p_this;

    ATSC3_DMX_TRACE();

    p_this = (struct atsc3_dmx*) malloc(sizeof(struct atsc3_dmx));

    if (p_this)
    {
        memset(p_this, 0, sizeof(struct atsc3_dmx));
        p_this->p_in = p_dmx_in;
        p_this->cb = *p_cb;
        //p_this->ops.start = atsc3_dmx_start;
        //p_this->ops.stop  = atsc3_dmx_stop;
        p_this->ops.run   = atsc3_dmx_run;
//        p_this->ops.deliver_data = atsc3_dmx_deliver_data;
    }

    return p_this;
}



/*======================================================
 * Func  : create_atsc3_dmx
 *
 * Desc  : create a atsc3 demux
 *
 * Param : handle of atsc3 dmx
 *
 * Retn  : N/A
 *======================================================*/
void destroy_atsc3_dmx(struct atsc3_dmx* p_this)
{
    ATSC3_DMX_TRACE();
    if (p_this)
        free(p_this);
}
