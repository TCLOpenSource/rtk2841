#ifndef __RTK_RCP_DEFINES_H__
#define __RTK_RCP_DEFINES_H__

#define MAX_CW_ENTRY       128
#define RCP_B4TL(b1, b2, b3, b4)        (((b1) << 24) + ((b2) << 16) + ((b3) << 8) + (b4))

/*#define RCP_BS4TL(array)                ((*(array) << 24) + (*(array + 1) << 16) +  \
                                            (*(array + 2) << 8) + *(array + 3))*/
                                            
#define RCP_BS4TL(array)        (htonl(*(unsigned int *)(array)))                                           

#define RCP_LTB4(b1, b2, b3, b4, L)     { b1 = ((L>>24)); b2 = ((L>>16)); \
                                            b3 = ((L>> 8)); b4 = ( L); }
                                            
/*#define RCP_LTBS4(array, L)             { *(array)  = ((L>>24)); *(array + 1) = ((L>>16)); \
                                            *(array + 2) = ((L>> 8)); *(array + 3) = ( L); }*/
                                            
#define RCP_LTBS4(array, L)   {(*(unsigned int *)(array)) = htonl(L);} 

typedef enum _RCP_REG_TYPE{
    RCP_REG_TYPE_KEY,
    RCP_REG_TYPE_KEY1,
    RCP_REG_TYPE_DATAIN,
    RCP_REG_TYPE_DATAOUT,
    RCP_REG_TYPE_IV,
}RCP_REG_TYPE;

typedef enum _RCP_MODE_TYPE{
    KEY_MODE,
    IV_MODE,
    INPUT_MODE,
    OUTPUT_MODE,
    INPUT_ENTRY,
    OUTPUT_ENTRY,
}RCP_MODE_TYPE;

typedef enum _RCP_CW_LOGIC_MODE_TYPE{
    CW_LOGIC_MODE_AND,
    CW_LOGIC_MODE_OR,
    CW_LOGIC_MODE_XOR,
}RCP_CW_LOGIC_MODE_TYPE;

#endif