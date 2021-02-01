#ifndef __RING_BUFF_H__
#define __RING_BUFF_H__

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
    unsigned char*  base;
    unsigned char*  limit;
    unsigned char*  rp;
    unsigned char*  wp;
}ring_buffer;

extern ring_buffer* ring_alloc(unsigned int size);
extern void ring_destroy(ring_buffer* ring);

extern int ring_get_free_space(ring_buffer* ring, unsigned char** pp_wp, unsigned int* p_size);
extern int ring_put_data(ring_buffer* ring, unsigned char* pp_rp, unsigned int len);
extern int ring_get_data(ring_buffer* ring, unsigned char** pp_rp, unsigned int* p_len);
extern int ring_release_data(ring_buffer* ring, unsigned char* p_rp, unsigned int len);


#ifdef __cplusplus
}
#endif     

#endif
