#ifndef __RSA_UTIL_H__
#define __RSA_UTIL_H__
#include "rsa_lib.h"
extern void change_byte_array_endian(UINT8 *buffer, UINT32 len);
extern int rsa_verify_signature(RSA_T *rsa, MPI sig,
                UINT32 sig_size, UINT8 *digest, UINT8 *digest_len);
extern MPI get_mpi_from_char_array(unsigned char *buffer,
                        unsigned int len, UINT8 convert);
extern void dump_mem_buffer(char *name, unsigned char *octet_str,
        unsigned int len);
extern void dump_mpi_value(char *name, MPI x, unsigned int len);
extern unsigned char hex_to_dec(unsigned char hex);
#endif
