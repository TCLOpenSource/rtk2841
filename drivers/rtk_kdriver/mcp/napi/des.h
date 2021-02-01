#ifndef __DES_H__
#define __DES_H__

typedef struct {    
    unsigned char       mode;
    unsigned char       enc;
    unsigned char*      key;
    unsigned char*      iv;
    unsigned char       buff[2][8];
}DES_CTX;


#endif
