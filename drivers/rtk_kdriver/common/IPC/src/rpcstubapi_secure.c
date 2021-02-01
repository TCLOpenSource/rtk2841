#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

#include <unistd.h>
#include <stdlib.h>

#include <rpcstubapi.h>

#define		SIGRPC		SIGUSR2

pthread_key_t   	tlsKey = 0;
struct sigaction	newact, oldact;

typedef struct
{
	sigset_t			newmask, oldmask, suspmask;
//	struct sigaction	newact, oldact;
	unsigned char		isAck; // indicate whether the reply arrive
} sync_struct;


int			wfdp_a, wfdi_a;
int			wfdp_v, wfdi_v;
int			wfdp_v2, wfdi_v2;
int			wfdp_s, wfdi_s;
//#ifdef KERNEL_2_6_34
const char *write_poll_dev_a = "/dev/rpc0";
const char *write_intr_dev_a = "/dev/rpc1";
const char *write_poll_dev_v = "/dev/rpc4";
const char *write_intr_dev_v = "/dev/rpc5";
const char *write_poll_dev_v2 = "/dev/rpc8";
const char *write_intr_dev_v2 = "/dev/rpc9";
const char *write_poll_dev_s = "/dev/rpc14";
const char *write_intr_dev_s = "/dev/rpc15";
//#else
//const char *write_poll_dev_a = "/dev/rpc/0";
//const char *write_intr_dev_a = "/dev/rpc/1";
//const char *write_poll_dev_v = "/dev/rpc/4";
//const char *write_intr_dev_v = "/dev/rpc/5";
//const char *write_poll_dev_s = "/dev/rpc/10";
//const char *write_intr_dev_s = "/dev/rpc/11";
//#endif

static void
sig_none(void)
{
	sync_struct *ptr;
	ptr = (sync_struct *)pthread_getspecific(tlsKey);
	if (ptr == NULL)
	{
		printf("**********Error in sig_none**********\n");
		return;
	}

	// *** add some code in this funciton to indicate that some signal is received.
	ptr->isAck = 1;
//	printf("Get the ack signal...\n");
	return; /* nothing to do, just returning wakes up sigsuspend() */
}

static void
globalDestructor(void *value)
{
	// This function will be called when a thread is terminated.
//	printf("In the data destructor...\n");
	free(value);
	pthread_setspecific(tlsKey, NULL);
}

/****************************************************************************
//	Initialize RPC
//
//	return value:	=0	open successfully
//					<0	some error condition happen
****************************************************************************/
int			openStubRPC()
{
	static int done = 0;
	int rc = 0;
	
	if (done)
		return 0;
	
	if ((wfdp_a = open(write_poll_dev_a, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_a);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}
	
	if ((wfdi_a = open(write_intr_dev_a, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_a);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdp_v = open(write_poll_dev_v, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_v);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}
	
	if ((wfdi_v = open(write_intr_dev_v, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_v);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdp_v2 = open(write_poll_dev_v2, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_v2);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}
	
	if ((wfdi_v2 = open(write_intr_dev_v2, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_v2);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdp_s = open(write_poll_dev_s, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_s);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}
	
	if ((wfdi_s = open(write_intr_dev_s, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_s);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((rc = pthread_key_create(&tlsKey, globalDestructor)) != 0) {
		printf("ERROR; return code from pthread_key_create() is %d\n", rc);
		closeStubRPC();
		exit(-1);
	}
	
	newact.sa_handler = (__sighandler_t)sig_none;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGRPC, &newact, &oldact);

	done = 1;
	return 0;
}

/****************************************************************************
//	Close RPC
****************************************************************************/
int			closeStubRPC()
{
	close(wfdp_a);
	close(wfdi_a);
	close(wfdp_v);
	close(wfdi_v);
	close(wfdp_v2);
	close(wfdi_v2);
	close(wfdp_s);
	close(wfdi_s);

	return 0;
}

/****************************************************************************
//	Get the current task's ID
****************************************************************************/
long		getTaskID()
{
	return (int)getpid();
}

/****************************************************************************
//	Write data into specified ring buffer
//
//	opt		:
//	buf		:
//	size	:
//
//	note: BLOCK_MODE can be used with both polling buffer and interrupt buffer.
****************************************************************************/
int			writeRingBuf(int opt, char *buf, int size)
{
	sync_struct *ptr;
	int cnt;
	int	wfdp, wfdi;

	if (opt & SEND_SYSTEM_CPU) {
		wfdp = wfdp_s;
		wfdi = wfdi_s;
	} else if (opt & SEND_AUDIO_CPU) {
		wfdp = wfdp_a;
		wfdi = wfdi_a;
	} else if (opt & SEND_VIDEO_CPU2) {
		wfdp = wfdp_v2;
		wfdi = wfdi_v2;
	} else {
		wfdp = wfdp_v;
		wfdi = wfdi_v;
	}

	ptr = (sync_struct *)pthread_getspecific(tlsKey);
	if (ptr == NULL) {
//		printf("Allocate TLS...\n");
		ptr = (sync_struct *)malloc(sizeof(sync_struct));
		pthread_setspecific(tlsKey, ptr);
	}

	if (opt & BLOCK_MODE) {
		// set new signal mask for the block mode
		sigemptyset(&ptr->newmask);
		sigaddset(&ptr->newmask, SIGRPC);
		// set new mask (ensure the mask will block SIGRPC)
		sigprocmask(SIG_BLOCK, &ptr->newmask, &ptr->oldmask);
		
		ptr->isAck = 0;
	}
	
	if (opt & USE_INTR_BUF)
		cnt = write(wfdi, buf, size);
	else
		cnt = write(wfdp, buf, size);
		
	return cnt;
}

/****************************************************************************
//	Wait for the reply from other processor
//
//	opt		:
//	buf		:
//	size	:
//
//	note: This function is used in blocking mode.
****************************************************************************/
void		waitReply()
{
	sync_struct *ptr;
	ptr = (sync_struct *)pthread_getspecific(tlsKey);
	if (ptr == NULL)
	{
		printf("**********Error in waitReply**********\n");
		return;
	}
	
	// register new handler for SIGRPC
//	ptr->newact.sa_handler = sig_none;
//	sigemptyset(&ptr->newact.sa_mask);
//	ptr->newact.sa_flags = 0;
//	sigaction(SIGRPC, &ptr->newact, &ptr->oldact);

	// prepare the mask used in sigsuspend()...
	// ensure the mask won't block SIGRPC
	ptr->suspmask = ptr->oldmask;
	sigdelset(&ptr->suspmask, SIGRPC);
	
	while (!ptr->isAck) {
		sigsuspend(&ptr->suspmask);
	}

	// restore the original handler
//	sigaction(SIGRPC, &ptr->oldact, NULL);

	// restore the original mask
	sigprocmask(SIG_SETMASK, &ptr->oldmask, NULL);
}
