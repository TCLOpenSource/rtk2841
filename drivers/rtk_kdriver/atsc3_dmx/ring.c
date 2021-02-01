#include <linux/kernel.h>
#include <linux/slab.h>
#include "ring.h"

#define malloc(size)        kmalloc(size, GFP_KERNEL)
#define free(addr)          kfree(addr)

ring_buffer* ring_alloc(unsigned int size)
{
    ring_buffer* ring = (ring_buffer*) malloc(size + sizeof(ring_buffer));
    ring->base = ((unsigned char*) ring) + sizeof(ring_buffer);
    ring->rp = ring->base;
    ring->wp = ring->base;
    ring->limit = ring->base + size;        
    return ring;    
}


void ring_destroy(ring_buffer* ring)
{
    if (ring)
        free(ring);
}

void ring_dump_status(ring_buffer* ring)
{
    printk("ring[%p] = %p/%p/%p/%p\n", 
            ring, 
            ring->base,
            ring->rp,
            ring->wp,
            ring->limit);
}

int ring_get_free_space(
    ring_buffer*        ring, 
    unsigned char**     pp_wp, 
    unsigned int*       p_size
    )
{
    if (ring==NULL || pp_wp==NULL || p_size==NULL) {
        printk("ring_release_data failed, invalid arguments\n");
        return -1;
    }
    
    ring_dump_status(ring);           

    *pp_wp = ring->wp;
    
    if (ring->wp >= ring->rp)
        *p_size = (unsigned int) (ring->limit - ring->wp);
    else        
        *p_size = (unsigned int) (ring->wp - ring->rp);
            
    return 0;        
}




int ring_put_data(
    ring_buffer*        ring, 
    unsigned char*      p_wp, 
    unsigned int        len
    )
{
    if (ring==NULL) {
        printk("ring_release_data failed, invalid arguments\n");
        return -1;
    }
        
    if (p_wp != ring->wp)
    {
        // humm ... should not happen
        printk("ring_release_data failed, wp out off sync\n");
        return -1;
    }
    
    if (p_wp > ring->limit || p_wp < ring->base)
        return -1;

    ring->wp = p_wp + len;
    
    if (ring->wp >= ring->limit)
        ring->wp = ring->base;
                    
    return 0;  
}




int ring_get_data(
    ring_buffer*        ring, 
    unsigned char**     pp_rp, 
    unsigned int*       p_len
    )
{
     if (ring==NULL || pp_rp==NULL || p_len==NULL) {
        printk("ring_release_data failed, rp out off sync\n");
        return -1;        
    }
            
    *pp_rp = ring->rp;    
    
    if (ring->wp >= ring->rp)
        *p_len = (unsigned int) (ring->wp - ring->rp);
    else        
        *p_len = (unsigned int) (ring->limit - ring->rp);
                    
    return 0;  
}



int ring_release_data(
    ring_buffer*        ring, 
    unsigned char*      p_rp, 
    unsigned int        len
    )
{
    if (ring==NULL) {
        printk("ring_release_data failed, invalid arguments\n");
        return -1;
    }
        
    if (p_rp != ring->rp)
    {
        // humm ... should not happen
        printk("ring_release_data failed, rp out off sync\n");
        return -1;
    }
    
    if (p_rp > ring->limit || p_rp < ring->base)
        return -1;

    ring->rp = p_rp + len;
    
    if (ring->rp >= ring->limit)
        ring->rp = ring->base;
                    
    return 0;
}
