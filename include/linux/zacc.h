#ifndef _LINUX_ZACC_H_
#define _LINUX_ZACC_H_

extern int zacc_ready(void);
extern ssize_t zacc_encode(void *dst, void const *src);
extern ssize_t zacc_decode(void *dst, void const *src, size_t size);

#endif	/* _LINUX_ZACC_H_ */
