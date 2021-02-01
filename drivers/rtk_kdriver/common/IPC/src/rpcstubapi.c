//#define LOG_NDEBUG 0
#define LOG_TAG "rpcstubapi"

#include <sys/types.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <errno.h>
#include <rpcstubapi.h>
#include <stdbool.h>
//#include <Logger/rtd_log.h>

//#include <utils/Log.h>


#if __BIONIC__ == 0

#include <sys/syscall.h>

pid_t gettid(void)
{
  return syscall(SYS_gettid);
}

pid_t tkill(int tid, int sig)
{
	int ret = 0;
	ret = syscall(SYS_tkill, tid, sig);
	if(ret != 0)
		printf("rpc debug tkill tid: %d, err: %d, errno: %d, %s \n", tid, ret, errno, strerror(errno));
  return ret;
}

#endif

#if (__BIONIC__ == 1) && !defined(__LP64__)
// Don't support realtime signal because there is a 32-bit ABI bugs on bionic for arm.
#define                SIGRPC          SIGUSR2
#else
#define                SIGRPC          (SIGRTMIN+19)//51//SIGUSR2
#endif

#if __BIONIC__ == 0
//pthread_key_t   	tlsKey = 0;
#else
pthread_key_t   	tlsKey = 0;
#endif

struct sigaction	newact, oldact;

typedef struct
{
	sigset_t			newmask, oldmask, suspmask;
//	struct sigaction	newact, oldact;
	unsigned char		isAck; // indicate whether the reply arrive
} sync_struct;

static __thread sync_struct sync__;

static int		done_open = 0;
int			wfdp_a, wfdi_a;
int			wfdp_v, wfdi_v;
int			wfdp_v2, wfdi_v2;
#ifdef ENABLE_KCPU_COMMON
int			wfdp_k, wfdi_k;
#endif

#define START_WAIT_SIGNAL()    //RTD_LOG_NOTICE(RTD_LOG_MODULE_ALL,"++%s:%s,pid = %d\n", func_name, __FUNCTION__,gettid())
#define END_WAIT_SIGNAL()      //RTD_LOG_NOTICE(RTD_LOG_MODULE_ALL,"--%s:%s,pid = %d\n", func_name, __FUNCTION__,gettid())

//#ifdef KERNEL_2_6_34
const char *write_poll_dev_a = "/dev/rpc0";
const char *write_intr_dev_a = "/dev/rpc1";
const char *write_poll_dev_v = "/dev/rpc4";
const char *write_intr_dev_v = "/dev/rpc5";
const char *write_poll_dev_v2 = "/dev/rpc8";
const char *write_intr_dev_v2 = "/dev/rpc9";

#ifdef ENABLE_KCPU_COMMON
const char *write_poll_dev_k = "/dev/rpc12";
const char *write_intr_dev_k = "/dev/rpc13";
#endif

//#else
//const char *write_poll_dev_a = "/dev/rpc/0";
//const char *write_intr_dev_a = "/dev/rpc/1";
//const char *write_poll_dev_v = "/dev/rpc/4";
//const char *write_intr_dev_v = "/dev/rpc/5";
//const char *write_poll_dev_v2 = "/dev/rpc/8";
//const char *write_intr_dev_v2 = "/dev/rpc/9";
//#endif

void logger_kmsg(char * fmt, ...)
{
       FILE * fd;
       va_list _ap;

       fd = fopen("/dev/kmsg", "w");

       if (fd == NULL)
               return;

       va_start(_ap, fmt);
       vfprintf(fd, fmt, _ap);
       va_end(_ap );
       fclose(fd);

}

static void
#if __BIONIC__ == 0
sig_none(void)
#else
sig_none(int sig)
#endif
{
	sync_struct *ptr;
#if __BIONIC__ == 0
	ptr = &sync__;
#else
	ptr = (sync_struct *)pthread_getspecific(tlsKey);
	if (ptr == NULL)
		printf("**********Error in sig_none**********\n");
#endif

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
#if __BIONIC__ == 1
	pthread_setspecific(tlsKey, NULL);
#endif
}

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

int			openStubRPC()
{
	int rc = 0;

  #ifdef RESOLVEFD
  done_open = 0;
  #endif

	if (done_open)
		return 0;

	if ((wfdp_a = xopen(write_poll_dev_a, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_a);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdi_a = xopen(write_intr_dev_a, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_a);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdp_v = xopen(write_poll_dev_v, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_v);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdi_v = xopen(write_intr_dev_v, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_v);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdp_v2 = xopen(write_poll_dev_v2, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_v2);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdi_v2 = xopen(write_intr_dev_v2, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_v2);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

#ifdef ENABLE_KCPU_COMMON
	if ((wfdp_k = xopen(write_poll_dev_k, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdp_k);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}

	if ((wfdi_k = xopen(write_intr_dev_k, O_WRONLY)) < 0) {
		printf("ERROR; return code from open() is %d\n", wfdi_k);
		perror("rpcstubapi::openRPC");
		exit(-1);
	}
#endif

#if __BIONIC__ == 1
	if ((rc = pthread_key_create(&tlsKey, globalDestructor)) != 0) {
		printf("ERROR; return code from pthread_key_create() is %d\n", rc);
		closeStubRPC();
		exit(-1);
	}
#endif

	newact.sa_handler = (__sighandler_t)sig_none;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGRPC, &newact, &oldact);

	done_open = 1;
	return 0;
}

/****************************************************************************
//	Close RPC
****************************************************************************/
int			closeStubRPC()
{

#if __BIONIC__ == 1
	if(pthread_key_delete(tlsKey) != 0)
		printf("pthread_key_delete fail\n");
#endif

	if (done_open == 0)
		return 0;

	close(wfdp_a);
	close(wfdi_a);
	close(wfdp_v);
	close(wfdi_v);
	close(wfdp_v2);
	close(wfdi_v2);
#ifdef ENABLE_KCPU_COMMON
	close(wfdp_k);
	close(wfdi_k);
#endif
	done_open = 0;

	return 0;
}

/****************************************************************************
//	Get the current task's ID
****************************************************************************/
long		getTaskID()
{
    //int i = (int)gettid();
	//int j = (int)getpid();
	//int k = syscall(SYS_gettid);
	//printf ("DEBUG TRACE: %s:%d getTaskID() -- gettid():%d getpid():%d SYS_gettid:%d\n", __FILE__, __LINE__, i, j, k);
	return (int)gettid();
	//return (int)getpid();
	//return syscall(SYS_gettid);
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

	if (opt & SEND_AUDIO_CPU) {
		wfdp = wfdp_a;
		wfdi = wfdi_a;
	}
	else if(opt & SEND_VIDEO_CPU2) {
		wfdp = wfdp_v2;
		wfdi = wfdi_v2;
	}
#ifdef ENABLE_KCPU_COMMON
	else if(opt & SEND_SECURE_CPU) {
		wfdp = wfdp_k;
		wfdi = wfdi_k;
	}
#endif
	else {
		wfdp = wfdp_v;
		wfdi = wfdi_v;
	}

#if __BIONIC__ == 0
	ptr = &sync__;
#else
	ptr = (sync_struct *)pthread_getspecific(tlsKey);
	if (ptr == NULL) {
		printf("Allocate TLS...\n");
		ptr = (sync_struct *)malloc(sizeof(sync_struct));
		pthread_setspecific(tlsKey, ptr);
	}
#endif

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
#if !defined(USE_TIMED_WAITREPLY)
void	waitReply()
{
	sync_struct *ptr;
#if __BIONIC__ == 0
	ptr = &sync__;
#else
	ptr = (sync_struct *)pthread_getspecific(tlsKey);
	if (ptr == NULL)
		printf("**********Error in waitReply**********\n");
#endif

	// register new handler for SIGRPC
//	ptr->newact.sa_handler = sig_none;
//	sigemptyset(&ptr->newact.sa_mask);
//	ptr->newact.sa_flags = 0;
//	sigaction(SIGRPC, &ptr->newact, &ptr->oldact);

	// prepare the mask used in sigsuspend()...
	// ensure the mask won't block SIGRPC
	ptr->suspmask = ptr->oldmask;
	sigdelset(&ptr->suspmask, SIGRPC);
	START_WAIT_SIGNAL();
	while (!ptr->isAck) {
		sigsuspend(&ptr->suspmask);
	}
	END_WAIT_SIGNAL();

	// restore the original handler
//	sigaction(SIGRPC, &ptr->oldact, NULL);

	// restore the original mask
	sigprocmask(SIG_SETMASK, &ptr->oldmask, NULL);
}

#else

#define TIMEOUT_SEC             (100) // make it longer for VIDEO_RPC_TRANSITION_ToAgent_Start_0()
#define WAKEUP_TIMEOUT_MS       (30)
#define MAX_TIMEOUT_COUNT       (TIMEOUT_SEC*1000/WAKEUP_TIMEOUT_MS)

void		__timedwaitReply(const char *func_name)
{
	sync_struct *ptr;
#if __BIONIC__ == 0
	ptr = &sync__;
#else
	ptr = (sync_struct *)pthread_getspecific(tlsKey);
#endif
    int my_errno;
	int my_count = 0;
    struct timespec timeout;

	timeout.tv_sec = 0;
	timeout.tv_nsec = WAKEUP_TIMEOUT_MS * 1000 * 1000;

	if (ptr == NULL)
		RPC_EMERG("**********Error in waitReply**********\n");

	START_WAIT_SIGNAL();
	while(!ptr->isAck){
        int sig_no = sigtimedwait(&ptr->newmask, NULL, &timeout);
		if (sig_no < 0) {
            my_errno = errno;
			if (my_errno == EINTR) {
				/* Interrupted by a signal other than SIGRPC. */
				//printf("waitReply2,pid = %d,other signal\n", gettid());
				continue;
			}
			else if (my_errno == EAGAIN) {
				if (my_count ++ > MAX_TIMEOUT_COUNT ) {
					RPC_EMERG("%s:%s,pid = %d, time out\n", func_name,__FUNCTION__,gettid());
					break;
				}
				continue;
			}
			else {
				RPC_EMERG("%s:%s,pid = %d, error = %d\n", func_name, __FUNCTION__,gettid(),my_errno);
			}
		}
        break;
	};
	END_WAIT_SIGNAL();

	sigprocmask(SIG_SETMASK, &ptr->oldmask, NULL);
}
#endif
