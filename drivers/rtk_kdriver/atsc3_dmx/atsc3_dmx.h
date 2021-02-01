#ifndef __ATSC3_DMX_H__
#define __ATSC3_DMX_H__

//#include <pthread.h>


#ifdef __cplusplus
extern "C" {
#endif



struct dmx_callback
{
    void* p_ctx;
    void (*callback)(void* p_ctx, unsigned char plp, unsigned char* p_data, unsigned int len);
};

#define RING_FLAG_REACH_LIMIT       0x1

struct atsc3_ring
{
    void* p_priv;

    struct {
        // for read
        int (*read_data)(struct atsc3_ring* ring, unsigned char** pp_rp, unsigned long* p_len, unsigned long* p_flags);
        int (*release_data)(struct atsc3_ring* ring, unsigned char* p_rp, unsigned long len);

        // for write
        int (*get_free_space)(struct atsc3_ring* ring, unsigned char* p_wp, unsigned long* p_len, unsigned long* p_flags);
        int (*put_data)(struct atsc3_ring* ring, unsigned char* p_wp, unsigned long len);
    }ops;
};

struct atsc3_dmx
{
    unsigned long   plp_mask[256/32];       // plp mask bit
    unsigned char   bbp_buffer[8192];       // tmep buffer for multi segment buffer
    unsigned long   bbp_buff_zize;
    unsigned long   bbp_excepted_zize;
    unsigned char   bbp_plp;
    unsigned char   bbp_cc;

    //pthread_t       thread_id;
    unsigned long   flags;

    #define DMX_FLAG_THREAD_START    0x2
    #define DMX_FLAG_THREAD_STOP     0x1

    struct atsc3_ring*  p_in;          // input ring buffer
    struct dmx_callback cb;            // dmx callback

    struct {
        //int (*start)(struct atsc3_dmx* dmx);
        //int (*stop)(struct atsc3_dmx* dmx);
        int (*run)(struct atsc3_dmx* dmx);
    }ops;
};




///////////////////////////////////////////////////////
extern struct atsc3_dmx* create_atsc3_dmx(struct dmx_callback* cb, struct atsc3_ring* p_dmx_in);
extern void destroy_atsc3_dmx(struct atsc3_dmx* dmx);

///////////////////////////////////////////////////////
#ifdef ATSC3_DMX_TRACE_EN
#define ATSC3_DMX_TRACE()                printk(KERN_INFO "[ATSC3_DMX][TRACE] %s:%d:%s\n", __FILE__, __LINE__, __FUNCTION__)
#else
#define ATSC3_DMX_TRACE()
#endif

#define ATSC3_DMX_DBG_EN
#ifdef ATSC3_DMX_DBG_EN
#define ATSC3_DMX_DBG(fmt, args...)      printk(KERN_DEBUG "[ATSC3_DMX][DBG] " fmt, ## args )
#else
#define ATSC3_DMX_DBG(fmt, args...)
#endif
#define ATSC3_DMX_INFO(fmt, args...)     printk(KERN_INFO "[ATSC3_DMX][INFO] " fmt, ## args )
#define ATSC3_DMX_WARN(fmt, args...)     printk(KERN_WARNING "[ATSC3_DMX][WARN] " fmt, ## args )

#ifdef __cplusplus
}
#endif

#endif
