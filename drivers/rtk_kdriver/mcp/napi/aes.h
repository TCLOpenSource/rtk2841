#ifndef __AES_H__
#define __AES_H__

typedef struct {    
    unsigned char       mode;
    unsigned char       enc;
    unsigned char*      key;
    unsigned char*      iv;
    unsigned char       buff[2][16];
    
    // for CTR mode only    
    unsigned char       ecnt_ofst;          // encrypyed count ofst
    unsigned char       ecnt[16];           // tmp data, used to store encrypted counter
    
}AES_CTX;


#endif
