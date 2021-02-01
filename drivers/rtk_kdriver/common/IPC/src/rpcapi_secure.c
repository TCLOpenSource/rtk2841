#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <stdlib.h>

#include <rpcapi.h>


#define		SIGRPC		SIGUSR2

int			rfdp_a, rfdi_a;
int			rfdp_v, rfdi_v;
int			rfdp_v2, rfdi_v2;
int			rfdp_s, rfdi_s;
//#ifdef KERNEL_2_6_34
const char *read_poll_dev_a = "/dev/rpc2";
const char *read_intr_dev_a = "/dev/rpc3";
const char *read_poll_dev_v = "/dev/rpc6";
const char *read_intr_dev_v = "/dev/rpc7";
const char *read_poll_dev_v2 = "/dev/rpc10";
const char *read_intr_dev_v2 = "/dev/rpc11";
const char *read_poll_dev_s = "/dev/rpc12";
const char *read_intr_dev_s = "/dev/rpc13";
//#else
//const char *read_poll_dev_a = "/dev/rpc/2";
//const char *read_intr_dev_a = "/dev/rpc/3";
//const char *read_poll_dev_v = "/dev/rpc/6";
//const char *read_intr_dev_v = "/dev/rpc/7";
//const char *read_poll_dev_s = "/dev/rpc/8";
//const char *read_intr_dev_s = "/dev/rpc/9";
//#endif

/****************************************************************************
//	Initialize RPC
//
//	return value:	=0	open successfully
//					<0	some error condition happen
****************************************************************************/
int			openRPC()
{
	if ((rfdp_a = open(read_poll_dev_a, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_a);
		perror("rpcapi::openRPC");
		exit(-1);
	}
	
	if ((rfdi_a = open(read_intr_dev_a, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_a);
		perror("rpcapi::openRPC");
		exit(-1);
	}
	
	if ((rfdp_v = open(read_poll_dev_v, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_v);
		perror("rpcapi::openRPC");
		exit(-1);
	}
	
	if ((rfdi_v = open(read_intr_dev_v, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_v);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	if ((rfdp_v2 = open(read_poll_dev_v2, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_v2);
		perror("rpcapi::openRPC");
		exit(-1);
	}
	
	if ((rfdi_v2 = open(read_intr_dev_v2, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_v2);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	if ((rfdp_s = open(read_poll_dev_s, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdp_s);
		perror("rpcapi::openRPC");
		exit(-1);
	}
	
	if ((rfdi_s = open(read_intr_dev_s, O_RDONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", rfdi_s);
		perror("rpcapi::openRPC");
		exit(-1);
	}

	return 0;
}

/****************************************************************************
//	Close RPC
****************************************************************************/
int			closeRPC()
{
	close(rfdp_a);
	close(rfdi_a);
	close(rfdp_v);
	close(rfdi_v);
	close(rfdp_v2);
	close(rfdi_v2);
	close(rfdp_s);
	close(rfdi_s);

	return 0;
}

/****************************************************************************
//      Register RPC
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
	ret = ioctl(rfdi_s, RPC_IOCTHANDLER, programID);
	if(ret == -1) goto err;
	ret = ioctl(rfdp_a, RPC_IOCTHANDLER, programID);
	if(ret == -1) goto err;
	ret = ioctl(rfdp_v, RPC_IOCTHANDLER, programID);
	if(ret == -1) goto err;
	ret = ioctl(rfdp_v2, RPC_IOCTHANDLER, programID);
	if(ret == -1) goto err;
	ret = ioctl(rfdp_s, RPC_IOCTHANDLER, programID);
	if(ret == -1) goto err;

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

	if (opt & SEND_SYSTEM_CPU) {
		rfdp = rfdp_s;
		rfdi = rfdi_s;
	} else if (opt & SEND_AUDIO_CPU) {
		rfdp = rfdp_a;
		rfdi = rfdi_a;
	} else if (opt & SEND_VIDEO_CPU2) {
		rfdp = rfdp_v2;
		rfdi = rfdi_v2;
	} else {
		rfdp = rfdp_v;
		rfdi = rfdi_v;
	}
		
	if (opt & USE_INTR_BUF) {
		// interrupt mode
		if (opt & BLOCK_MODE)
			fcntl(rfdi, F_SETFL, fcntl(rfdi, F_GETFL) & ~O_NONBLOCK);
		else
			fcntl(rfdi, F_SETFL, fcntl(rfdi, F_GETFL) | O_NONBLOCK);

		cnt = read(rfdi, buf, size);
	} else {
		// polling mode
		cnt = read(rfdp, buf, size);
	}
	
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
//	printf("Killing %d..\n", taskid);
	kill(taskid, SIGRPC);
}

