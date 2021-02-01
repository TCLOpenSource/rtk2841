#ifndef __DEFINES_FOR_BIONIC__
  #define __DEFINES_FOR_BIONIC__
  #define __THROW
#ifndef FALSE
  #define FALSE (0)
#endif
#ifndef TRUE
  #define TRUE (1)
#endif
  #define __FLOAT_WORD_ORDER __BYTE_ORDER
  typedef int bool_t;
  typedef int enum_t;
  /* Convenience types.  */
  typedef unsigned char __u_char;
  typedef unsigned short int __u_short;
  typedef unsigned int __u_int;
  typedef unsigned long int __u_long;
  
  // by guessing
  typedef int __daddr_t;
  typedef int __caddr_t;
  typedef long int __quad_t;
  typedef unsigned long int __u_quad_t;
  typedef __quad_t quad_t;
  typedef __u_quad_t u_quad_t;
#endif //__DEFINES_FOR_BIONIC__

