#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct {
	unsigned long		addr;
	unsigned long		prot;
} watch_struct;

#define WATCH_IOC_MAGIC				'j'
#define WATCH_IOQGETASID			_IO(WATCH_IOC_MAGIC, 1)
#define WATCH_IOSSETWATCH			_IOW(WATCH_IOC_MAGIC, 2, watch_struct)
#define WATCH_IOTCLRWATCH			_IO(WATCH_IOC_MAGIC, 3)

#define WATCH_R		0x1
#define WATCH_W 	0x2
#define WATCH_X		0x4

int main(int argc, char* argv[])
{
	int a = 0;
	int fd;
	watch_struct ws;
	int i = 0;
	int arg = 0;

	if (argc <= 1) {
		printf("please set arguments, 1:get, 2:set, 3:clear\n");
		return 0;
	}

	arg = atoi(argv[1]);

	fd = open("/dev/watch", O_RDONLY);
	if (fd < 0) {
		printf("error open /dev/watch \n");
		return 0;
	}

	if (arg == 1) {
		printf("getwatch\n");
		ioctl(fd, WATCH_IOQGETASID);
	}

	if (arg == 2) {
		ws.addr = &a;
		ws.prot = WATCH_R | WATCH_W;
		printf("setwatch, ws=%x, addr=%x, prot=%x\n", &ws, ws.addr, ws.prot);
		ioctl(fd, WATCH_IOSSETWATCH, &ws);
	}

	if (arg == 3) {
		printf("clrwatch\n");
		ioctl(fd, WATCH_IOTCLRWATCH);
	}

	a = 3;
	a = 4;
	a = 5;

	if (a == 5) 
		printf("hello\n");

	ioctl(fd, WATCH_IOTCLRWATCH);

    close(fd);

	return 0;
}
