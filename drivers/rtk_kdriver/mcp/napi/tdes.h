#ifndef __TDES_H__
#define __TDES_H__

typedef struct {    
    unsigned char       mode;
    unsigned char       enc;
    unsigned char*      key;
    unsigned char*      iv;
    unsigned char       buff[2][21];
}TDES_CTX;


#endif
