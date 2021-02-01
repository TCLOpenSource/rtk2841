#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <stdlib.h>

#include <rpcapi.h>
#if __BIONIC__ == 1
#include <pthread.h>
#endif

#if (__BIONIC__ == 1) && !defined(__LP64__)
// Don't support realtime signal because there is a 32-bit ABI bugs on bionic for arm.
#define                SIGRPC          SIGUSR2
#else
#define                SIGRPC          (SIGRTMIN+19)//51//SIGUSR2
#endif

static int		done_open = 0;
int			rfdp_a, rfdi_a;
int			rfdp_v, rfdi_v;
int			rfdp_v2, rfdi_v2;
#ifdef ENABLE_KCPU_COMMON
int			rfdp_k, rfdi_k;
#endif

//#ifdef KERNEL_2_6_34
const char *read_poll_dev_a = "/dev/rpc2";
const char *read_intr_dev_a = "/dev/rpc3";
const char *read_poll_dev_v = "/dev/rpc6";
const char *read_intr_dev_v = "/dev/rpc7";
const char *read_poll_dev_v2 = "/dev/rpc10";
const char *read_intr_dev_v2 = "/dev/rpc11";
#ifdef ENABLE_KCPU_COMMON
const char *read_poll_dev_k = "/dev/rpc14";
const char *read_intr_dev_k = "/dev/rpc15";
#endif

//#else
//const char *read_poll_dev_a = "/dev/rpc/2";
//const char *read_intr_dev_a = "/dev/rpc/3";
//const char *read_poll_dev_v = "/dev/rpc/6";
//const char *read_intr_dev_v = "/dev/rpc/7";
//const char *read_poll_dev_v2 = "/dev/rpc/10";
//const char *read_intr_dev_v2 = "/dev/rpc/11";
//#endif

/****************************************************************************
//	Initialize RPC
//
//	return value:	=0	open successfully
//					<0	some error condition happen
****************************************************************************/

#ifdef RESOLVEFD
  #include "resolvefd.h"
  #define xopen(a, b) resolvefd(a, b)
#else
  #define xopen(a, b) open(a, b)
#endif

int			openRPC()
{
#ifdef RESOLVEFD
	done_open = 0;
#endif

	if (done_open)
		return 0;

	if ((rfdp_a = xopen(read_poll_dev_a, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_a);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	if ((rfdi_a = xopen(read_intr_dev_a, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_a);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	if ((rfdp_v = xopen(read_poll_dev_v, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_v);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	if ((rfdi_v = xopen(read_intr_dev_v, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_v);
		perror("rpcapi::openRPC");
		exit(-1);
	}
	if ((rfdp_v2 = xopen(read_poll_dev_v2, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_v2);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	if ((rfdi_v2 = xopen(read_intr_dev_v2, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_v2);
		perror("rpcapi::openRPC");
		exit(-1);
	}
#ifdef ENABLE_KCPU_COMMON
	if ((rfdp_k = xopen(read_poll_dev_k, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_k);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	if ((rfdi_k = xopen(read_intr_dev_k, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_k);
		perror("rpcapi::openRPC");
		exit(-1);
	}
#endif

	done_open = 1;
	return 0;
}

/****************************************************************************
//	Close RPC
****************************************************************************/
int			closeRPC()
{
	if (done_open == 0)
		return 0;

	close(rfdp_a);
	close(rfdi_a);
	close(rfdp_v);
	close(rfdi_v);
	close(rfdp_v2);
	close(rfdi_v2);
#ifdef ENABLE_KCPU_COMMON
	close(rfdp_k);
	close(rfdi_k);
#endif
	done_open = 0;

	return 0;
}

/****************************************************************************
//	Register RPC
****************************************************************************/
#ifdef RPC_PROGRAM_REGISTER
int registerRPC(unsigned long programID)
{
	int ret = 0;

    ret = ioctl(rfdi_a, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
    ret = ioctl(rfdi_v, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
    ret = ioctl(rfdi_v2, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
#ifdef ENABLE_KCPU_COMMON
    ret = ioctl(rfdi_k, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
#endif
    ret = ioctl(rfdp_a, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
    ret = ioctl(rfdp_v, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
    ret = ioctl(rfdp_v2, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
#ifdef ENABLE_KCPU_COMMON
    ret = ioctl(rfdp_k, RPC_IOCTHANDLER, programID);
    if(ret == -1) goto err;
#endif

    return 0;

err:
    printf("%s: failed to register program handler: %s\n", __func__, strerror(errno));
	return 1;
}
#endif

/****************************************************************************
//	Set the timeout for the blocking mode
//
//	msec	: timeout interval
//
//	note: If msec == -1, it represents that wait forever.
****************************************************************************/
void		setTimeout(int msec)
{
	// +++ todo...
}

/****************************************************************************
//	Read data from specified ring buffer
//
//	opt		:
//	buf		:
//	size	:
//
//	note: Using BLOCK_MODE with polling buffer has no effect. (Accessing polling
//	      buffer doesn't support blocking IO)
****************************************************************************/
int			readRingBuf(int opt, char *buf, int size)
{
	int cnt;
	int	rfdp, rfdi;

	if (opt & SEND_AUDIO_CPU) {
		rfdp = rfdp_a;
		rfdi = rfdi_a;
	}
	else if(opt & SEND_VIDEO_CPU2) {
		rfdp = rfdp_v2;
		rfdi = rfdi_v2;
	}
#ifdef ENABLE_KCPU_COMMON
	else if(opt & SEND_SECURE_CPU) {
		rfdp = rfdp_k;
		rfdi = rfdi_k;
	}
#endif
	else {
		rfdp = rfdp_v;
		rfdi = rfdi_v;
	}

	if (opt & USE_INTR_BUF) {
		// interrupt mode
		if (opt & BLOCK_MODE){
			if(fcntl(rfdi, F_SETFL, fcntl(rfdi, F_GETFL) & ~O_NONBLOCK) ==-1){
				printf("fcntl F_SETFL fail...\n");
				return -1;
			}
		}
		else{
			if(fcntl(rfdi, F_SETFL, fcntl(rfdi, F_GETFL) | O_NONBLOCK) == -1){
				printf("fcntl F_SETFL O_NONBLOCK fail...\n");
				return -1;
			}
		}

		cnt = read(rfdi, buf, size);
	} else {
		// polling mode
		cnt = read(rfdp, buf, size);
	}
	//if(cnt > 0) printf("%s %d bytes from %s %s device with %s mode\n", __func__, cnt, (opt & SEND_AUDIO_CPU) ? "audio" : "video", (opt & USE_INTR_BUF) ? "intr" : "poll", (opt & BLOCK_MODE) ? "blocking" : "nonblocking");

	return cnt;
}

/****************************************************************************
//	Notify a specified task that its reply is available
//
//	opt		:
//	buf		:
//	size	:
//
//	note: This function should be used with waitReply in pair.
****************************************************************************/
void		ackTask(int taskid)
{
    int err;
	err = tkill(taskid, SIGRPC);
}

int stopRPC()
{
	int ret = 0;

	// notify fw to stop send rpc command

    ret = ioctl(rfdp_a, RPC_IOSTOP, NULL);
    return ret;
}

